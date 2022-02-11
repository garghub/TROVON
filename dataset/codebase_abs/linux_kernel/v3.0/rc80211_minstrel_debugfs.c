int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
char * V_12 ;
V_7 = F_2 ( sizeof( * V_7 ) + 4096 , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_2 -> V_15 = V_7 ;
V_12 = V_7 -> V_16 ;
V_12 += sprintf ( V_12 , L_1
L_2 ) ;
for ( V_8 = 0 ; V_8 < V_4 -> V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_4 -> V_20 [ V_8 ] ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_21 ) ? 'T' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_22 ) ? 't' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_23 ) ? 'P' : ' ' ;
V_12 += sprintf ( V_12 , L_3 , V_19 -> V_24 / 2 ,
( V_19 -> V_24 & 1 ? L_4 : L_5 ) ) ;
V_9 = V_19 -> V_25 / ( ( 18000 << 10 ) / 96 ) ;
V_10 = V_19 -> V_26 / 18 ;
V_11 = V_19 -> V_27 / 18 ;
V_12 += sprintf ( V_12 , L_6
L_7 ,
V_9 / 10 , V_9 % 10 ,
V_11 / 10 , V_11 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_19 -> V_28 ,
V_19 -> V_29 ,
( unsigned long long ) V_19 -> V_30 ,
( unsigned long long ) V_19 -> V_31 ) ;
}
V_12 += sprintf ( V_12 , L_8
L_9 ,
V_4 -> V_32 - V_4 -> V_33 ,
V_4 -> V_33 ) ;
V_7 -> V_34 = V_12 - V_7 -> V_16 ;
return 0 ;
}
T_1
F_3 ( struct V_2 * V_2 , char T_2 * V_16 , T_3 V_34 , T_4 * V_35 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_15 ;
return F_4 ( V_16 , V_34 , V_35 , V_7 -> V_16 , V_7 -> V_34 ) ;
}
int
F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_6 ( V_2 -> V_15 ) ;
return 0 ;
}
void
F_7 ( void * V_36 , void * V_37 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_37 ;
V_4 -> V_40 = F_8 ( L_10 , V_41 , V_39 , V_4 ,
& V_42 ) ;
}
void
F_9 ( void * V_36 , void * V_37 )
{
struct V_3 * V_4 = V_37 ;
F_10 ( V_4 -> V_40 ) ;
}
