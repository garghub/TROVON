int
F_1 ( T_1 )
{
union {
struct V_1 V_2 ;
} * args = V_3 ;
const T_2 V_4 = V_5 -> V_6 * 0x800 ;
T_2 V_7 ;
int V_8 ;
F_2 ( V_9 , L_1 , V_10 ) ;
if ( F_3 ( args -> V_2 , 0 , 0 , false ) ) {
F_2 ( V_9 , L_2 ,
args -> V_2 . V_11 , args -> V_2 . V_12 ) ;
V_7 = ! ! args -> V_2 . V_12 ;
} else
return V_8 ;
F_4 ( V_13 , 0x61c004 + V_4 , 0x80000000 , 0x00000000 ) ;
F_5 ( V_13 , 0x61c004 + V_4 , 0x80000001 , 0x80000000 | V_7 ) ;
F_4 ( V_13 , 0x61c004 + V_4 , 0x80000000 , 0x00000000 ) ;
F_4 ( V_13 , 0x61c030 + V_4 , 0x10000000 , 0x00000000 ) ;
return 0 ;
}
