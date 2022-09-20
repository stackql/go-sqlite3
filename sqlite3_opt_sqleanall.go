//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

//go:build sqlite_sqleanall || sqleanall
// +build sqlite_sqleanall sqleanall

package sqlite3

/*
#cgo CFLAGS: -DSQLITE_ENABLE_SQLEANALL -DSQLITE_ENABLE_UNICODE
*/
import "C"
