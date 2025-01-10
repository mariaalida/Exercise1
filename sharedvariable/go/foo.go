// Use `go run foo.go` to run your program

package main

import (
    . "fmt"
    "runtime"
)

var i = 0

type Request struct{
    op string
    finished chan bool 
}

func server(requests chan Request) {
	for req := range requests {
		switch req.op {
		case "increment":
			i++
		case "decrement":
			i--
		case "read":
			req.finished<-true
		}
	}
}

func incrementing(ch_a chan Request, finished chan bool) {
    for j:=0; j<1000000; j++{
        ch_a <- Request{op:"increment"}
    }
    ch_a <- Request{op: "read", finished: finished}
}

func decrementing(ch_a chan Request, finished chan bool) {
    for j:=0; j<1000000; j++{
        ch_a <- Request{op:"decrement"}
    }
    ch_a <- Request{op: "read", finished: finished}
}

func main() {
    runtime.GOMAXPROCS(2)    
	
    ch_a := make(chan Request)
    finished := make(chan bool)

    go server(ch_a)
	go incrementing(ch_a, finished)
    go decrementing(ch_a, finished)

    <-finished
    <-finished

    Println("The magic number is:", i)
}
