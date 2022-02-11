int
F_1 ( T_1 )
{
union {
struct V_1 V_2 ;
} * args = V_3 ;
const T_2 V_4 = V_5 -> V_6 * 0x030 ;
int V_7 , V_8 ;
F_2 ( V_9 , L_1 , V_10 ) ;
if ( F_3 ( args -> V_2 , 0 , 0 , true ) ) {
F_2 ( V_9 , L_2 , args -> V_2 . V_11 ) ;
if ( V_10 > 0x60 )
return - V_12 ;
} else
return V_7 ;
if ( V_10 && args -> V_2 . V_3 [ 0 ] ) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_4 ( V_13 , 0x10ec00 + V_4 , ( V_8 << 8 ) | args -> V_2 . V_3 [ V_8 ] ) ;
for (; V_8 < 0x60 ; V_8 ++ )
F_4 ( V_13 , 0x10ec00 + V_4 , ( V_8 << 8 ) ) ;
F_5 ( V_13 , 0x10ec10 + V_4 , 0x80000003 , 0x80000003 ) ;
} else
if ( V_10 ) {
F_5 ( V_13 , 0x10ec10 + V_4 , 0x80000003 , 0x80000001 ) ;
} else {
F_5 ( V_13 , 0x10ec10 + V_4 , 0x80000003 , 0x80000000 ) ;
}
return 0 ;
}
