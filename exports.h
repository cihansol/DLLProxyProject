//  exports.h
//
//	Simple header to instruct the linker to forward function exports to another library.
//

//Below is an example of a forward the Windows Image loader can use to look for the required function 
#pragma comment(linker,"/export:FunctionNameA=TARGETMODULE.FunctionNameA,@1")

