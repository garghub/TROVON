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
* ( V_12 ++ ) = ( V_8 == V_4 -> V_21 [ 0 ] ) ? 'A' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_21 [ 1 ] ) ? 'B' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_21 [ 2 ] ) ? 'C' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_21 [ 3 ] ) ? 'D' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_22 ) ? 'P' : ' ' ;
V_12 += sprintf ( V_12 , L_3 , V_19 -> V_23 / 2 ,
( V_19 -> V_23 & 1 ? L_4 : L_5 ) ) ;
V_9 = F_3 ( V_19 -> V_24 / 10 ) ;
V_10 = F_3 ( V_19 -> V_25 * 1000 ) ;
V_11 = F_3 ( V_19 -> V_26 * 1000 ) ;
V_12 += sprintf ( V_12 , L_6
L_7 ,
V_9 / 10 , V_9 % 10 ,
V_11 / 10 , V_11 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_19 -> V_27 ,
V_19 -> V_28 ,
( unsigned long long ) V_19 -> V_29 ,
( unsigned long long ) V_19 -> V_30 ) ;
}
V_12 += sprintf ( V_12 , L_8
L_9 ,
V_4 -> V_31 - V_4 -> V_32 ,
V_4 -> V_32 ) ;
V_7 -> V_33 = V_12 - V_7 -> V_16 ;
return 0 ;
}
T_1
F_4 ( struct V_2 * V_2 , char T_2 * V_16 , T_3 V_33 , T_4 * V_34 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_15 ;
return F_5 ( V_16 , V_33 , V_34 , V_7 -> V_16 , V_7 -> V_33 ) ;
}
int
F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
return 0 ;
}
void
F_8 ( void * V_35 , void * V_36 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_36 ;
V_4 -> V_39 = F_9 ( L_10 , V_40 , V_38 , V_4 ,
& V_41 ) ;
}
void
F_10 ( void * V_35 , void * V_36 )
{
struct V_3 * V_4 = V_36 ;
F_11 ( V_4 -> V_39 ) ;
}
