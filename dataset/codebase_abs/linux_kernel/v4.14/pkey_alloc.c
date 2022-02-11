static T_1 F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
int V_4 , V_5 = 0 ;
#include "trace/beauty/generated/pkey_alloc_access_rights_array.c"
static F_2 ( V_6 ) ;
if ( V_1 == 0 ) {
const char * V_7 = V_8 . V_9 [ 0 ] ;
if ( V_7 )
return F_3 ( V_2 , V_3 , L_1 , V_7 ) ;
return F_3 ( V_2 , V_3 , L_2 , 0 ) ;
}
for ( V_4 = 1 ; V_4 < V_8 . V_10 ; ++ V_4 ) {
int V_11 = 1 << ( V_4 - 1 ) ;
if ( ! ( V_1 & V_11 ) )
continue;
if ( V_5 != 0 )
V_5 += F_3 ( V_2 + V_5 , V_3 - V_5 , L_3 ) ;
if ( V_8 . V_9 [ V_4 ] != NULL )
V_5 += F_3 ( V_2 + V_5 , V_3 - V_5 , L_1 , V_8 . V_9 [ V_4 ] ) ;
else
V_5 += F_3 ( V_2 + V_5 , V_3 - V_5 , L_4 , V_11 ) ;
}
return V_5 ;
}
T_1 F_4 ( char * V_2 , T_1 V_3 , struct V_12 * V_13 )
{
unsigned long V_14 = V_13 -> V_15 ;
return F_1 ( V_14 , V_2 , V_3 ) ;
}
