int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
unsigned char * V_5 ;
struct V_6 {
T_2 V_7 ;
T_2 V_8 ;
struct V_9 {
T_2 V_10 ;
T_3 V_11 ;
} V_12 [ 8 ] ;
} * V_13 ;
#define F_2 0x032957
#define F_3 1
V_5 = F_4 ( V_2 , ( 16384 - sizeof( * V_13 ) ) / 512 , & V_4 ) ;
if ( ! V_5 )
return - 1 ;
V_13 = (struct V_6 * ) ( V_5 + 512 - sizeof( * V_13 ) ) ;
if ( V_13 -> V_7 == F_2 && V_13 -> V_8 == F_3 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( V_13 -> V_12 [ V_3 ] . V_10 )
F_5 ( V_2 , V_3 + 1 ,
V_13 -> V_12 [ V_3 ] . V_11 ,
V_13 -> V_12 [ V_3 ] . V_10 ) ;
F_6 ( V_4 ) ;
F_7 ( V_2 -> V_14 , L_1 , V_15 ) ;
return 1 ;
} else {
F_6 ( V_4 ) ;
return 0 ;
}
}
