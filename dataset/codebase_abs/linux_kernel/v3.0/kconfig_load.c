void F_1 ( void )
{
void * V_1 ;
char * error ;
V_1 = F_2 ( L_1 , V_2 ) ;
if ( ! V_1 ) {
V_1 = F_2 ( L_2 , V_2 ) ;
if ( ! V_1 ) {
fprintf ( V_3 , L_3 , F_3 () ) ;
exit ( 1 ) ;
}
}
#define F_4 ( T_1 , type , T_2 ) \
{ \
name ## _p = dlsym(handle, #name); \
if ((error = dlerror())) { \
fprintf(stderr, "%s\n", error); \
exit(1); \
} \
}
#include "lkc_proto.h"
#undef F_4
}
