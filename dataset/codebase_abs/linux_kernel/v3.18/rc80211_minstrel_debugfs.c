int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
char * V_12 ;
V_7 = F_2 ( 2048 , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_2 -> V_15 = V_7 ;
V_12 = V_7 -> V_16 ;
V_12 += sprintf ( V_12 , L_1
L_2 ) ;
for ( V_8 = 0 ; V_8 < V_4 -> V_17 ; V_8 ++ ) {
struct V_18 * V_19 = & V_4 -> V_20 [ V_8 ] ;
struct V_21 * V_22 = & V_4 -> V_20 [ V_8 ] . V_23 ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_24 [ 0 ] ) ? 'A' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_24 [ 1 ] ) ? 'B' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_24 [ 2 ] ) ? 'C' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_24 [ 3 ] ) ? 'D' : ' ' ;
* ( V_12 ++ ) = ( V_8 == V_4 -> V_25 ) ? 'P' : ' ' ;
V_12 += sprintf ( V_12 , L_3 , V_19 -> V_26 / 2 ,
( V_19 -> V_26 & 1 ? L_4 : L_5 ) ) ;
V_9 = F_3 ( V_22 -> V_27 / 10 ) ;
V_10 = F_3 ( V_22 -> V_28 * 1000 ) ;
V_11 = F_3 ( V_22 -> V_29 * 1000 ) ;
V_12 += sprintf ( V_12 , L_6
L_7 ,
V_9 / 10 , V_9 % 10 ,
V_11 / 10 , V_11 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_22 -> V_30 ,
V_22 -> V_31 ,
( unsigned long long ) V_22 -> V_32 ,
( unsigned long long ) V_22 -> V_33 ) ;
}
V_12 += sprintf ( V_12 , L_8
L_9 ,
V_4 -> V_34 - V_4 -> V_35 ,
V_4 -> V_35 ) ;
V_7 -> V_36 = V_12 - V_7 -> V_16 ;
F_4 ( V_7 -> V_36 + sizeof( * V_7 ) > 2048 ) ;
return 0 ;
}
T_1
F_5 ( struct V_2 * V_2 , char T_2 * V_16 , T_3 V_36 , T_4 * V_37 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_15 ;
return F_6 ( V_16 , V_36 , V_37 , V_7 -> V_16 , V_7 -> V_36 ) ;
}
int
F_7 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_8 ( V_2 -> V_15 ) ;
return 0 ;
}
void
F_9 ( void * V_38 , void * V_39 , struct V_40 * V_41 )
{
struct V_3 * V_4 = V_39 ;
V_4 -> V_42 = F_10 ( L_10 , V_43 , V_41 , V_4 ,
& V_44 ) ;
}
void
F_11 ( void * V_38 , void * V_39 )
{
struct V_3 * V_4 = V_39 ;
F_12 ( V_4 -> V_42 ) ;
}
