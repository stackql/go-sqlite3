// Copyright (C) 2019 Yasuhiro Matsumoto <mattn.jp@gmail.com>.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

// +build sqlite_sqleanall sqleanall

package sqlite3

/*
#cgo CFLAGS: -DSQLITE_ENABLE_SQLEANALL
*/
import "C"
