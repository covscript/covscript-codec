import codec.base64.standard as base64
var ifs = iostream.fstream("./powered-by.png", iostream.openmode.bin_in)
var ofs = iostream.fstream("./out.png", iostream.openmode.bin_out)
var str = base64.encode_stream(ifs)
system.out.println(str)
base64.decode_stream(str, ofs)