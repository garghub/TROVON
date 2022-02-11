T_1
F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 ;
V_6 = V_1 -> V_7 ;
return F_2 ( V_2 , V_3 , V_4 , V_6 -> V_2 , V_6 -> V_3 ) ;
}
int
F_3 ( struct V_8 * V_8 , struct V_1 * V_1 )
{
F_4 ( V_1 -> V_7 ) ;
return 0 ;
}
int
F_5 ( struct V_8 * V_8 , struct V_1 * V_1 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_5 * V_6 ;
unsigned int V_12 , V_13 , V_14 , V_15 ;
char * V_16 ;
V_6 = F_6 ( 2048 , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_1 -> V_7 = V_6 ;
V_16 = V_6 -> V_2 ;
V_16 += sprintf ( V_16 , L_1 ) ;
V_16 += sprintf ( V_16 ,
L_2 ) ;
V_16 += sprintf ( V_16 ,
L_3 ) ;
for ( V_12 = 0 ; V_12 < V_10 -> V_19 ; V_12 ++ ) {
struct V_20 * V_21 = & V_10 -> V_22 [ V_12 ] ;
struct V_23 * V_24 = & V_10 -> V_22 [ V_12 ] . V_25 ;
unsigned int V_26 ;
* ( V_16 ++ ) = ( V_12 == V_10 -> V_27 [ 0 ] ) ? 'A' : ' ' ;
* ( V_16 ++ ) = ( V_12 == V_10 -> V_27 [ 1 ] ) ? 'B' : ' ' ;
* ( V_16 ++ ) = ( V_12 == V_10 -> V_27 [ 2 ] ) ? 'C' : ' ' ;
* ( V_16 ++ ) = ( V_12 == V_10 -> V_27 [ 3 ] ) ? 'D' : ' ' ;
* ( V_16 ++ ) = ( V_12 == V_10 -> V_28 ) ? 'P' : ' ' ;
V_16 += sprintf ( V_16 , L_4 , V_21 -> V_29 / 2 ,
( V_21 -> V_29 & 1 ? L_5 : L_6 ) ) ;
V_16 += sprintf ( V_16 , L_7 , V_12 ) ;
V_16 += sprintf ( V_16 , L_8 , V_21 -> V_30 ) ;
V_13 = F_7 ( V_21 , F_8 ( 100 , 100 ) ) ;
V_14 = F_7 ( V_21 , V_24 -> V_31 ) ;
V_15 = F_9 ( V_24 -> V_31 * 1000 ) ;
V_26 = F_10 ( V_24 ) ;
V_16 += sprintf ( V_16 , L_9
L_10
L_11 ,
V_13 / 10 , V_13 % 10 ,
V_14 / 10 , V_14 % 10 ,
V_15 / 10 , V_15 % 10 ,
V_26 / 10 , V_26 % 10 ,
V_24 -> V_32 ,
V_24 -> V_33 ,
V_24 -> V_34 ,
( unsigned long long ) V_24 -> V_35 ,
( unsigned long long ) V_24 -> V_36 ) ;
}
V_16 += sprintf ( V_16 , L_12
L_13 ,
V_10 -> V_37 - V_10 -> V_38 ,
V_10 -> V_38 ) ;
V_6 -> V_3 = V_16 - V_6 -> V_2 ;
F_11 ( V_6 -> V_3 + sizeof( * V_6 ) > 2048 ) ;
return 0 ;
}
int
F_12 ( struct V_8 * V_8 , struct V_1 * V_1 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_5 * V_6 ;
unsigned int V_12 , V_13 , V_14 , V_15 ;
char * V_16 ;
V_6 = F_6 ( 2048 , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_1 -> V_7 = V_6 ;
V_16 = V_6 -> V_2 ;
for ( V_12 = 0 ; V_12 < V_10 -> V_19 ; V_12 ++ ) {
struct V_20 * V_21 = & V_10 -> V_22 [ V_12 ] ;
struct V_23 * V_24 = & V_10 -> V_22 [ V_12 ] . V_25 ;
unsigned int V_26 ;
V_16 += sprintf ( V_16 , L_14 , ( ( V_12 == V_10 -> V_27 [ 0 ] ) ? L_15 : L_16 ) ) ;
V_16 += sprintf ( V_16 , L_14 , ( ( V_12 == V_10 -> V_27 [ 1 ] ) ? L_17 : L_16 ) ) ;
V_16 += sprintf ( V_16 , L_14 , ( ( V_12 == V_10 -> V_27 [ 2 ] ) ? L_18 : L_16 ) ) ;
V_16 += sprintf ( V_16 , L_14 , ( ( V_12 == V_10 -> V_27 [ 3 ] ) ? L_19 : L_16 ) ) ;
V_16 += sprintf ( V_16 , L_14 , ( ( V_12 == V_10 -> V_28 ) ? L_20 : L_16 ) ) ;
V_16 += sprintf ( V_16 , L_21 , V_21 -> V_29 / 2 ,
( V_21 -> V_29 & 1 ? L_22 : L_23 ) ) ;
V_16 += sprintf ( V_16 , L_24 , V_12 ) ;
V_16 += sprintf ( V_16 , L_24 , V_21 -> V_30 ) ;
V_13 = F_7 ( V_21 , F_8 ( 100 , 100 ) ) ;
V_14 = F_7 ( V_21 , V_24 -> V_31 ) ;
V_15 = F_9 ( V_24 -> V_31 * 1000 ) ;
V_26 = F_10 ( V_24 ) ;
V_16 += sprintf ( V_16 , L_25
L_26 ,
V_13 / 10 , V_13 % 10 ,
V_14 / 10 , V_14 % 10 ,
V_15 / 10 , V_15 % 10 ,
V_26 / 10 , V_26 % 10 ,
V_24 -> V_32 ,
V_24 -> V_33 ,
V_24 -> V_34 ,
( unsigned long long ) V_24 -> V_35 ,
( unsigned long long ) V_24 -> V_36 ,
V_10 -> V_37 - V_10 -> V_38 ,
V_10 -> V_38 ) ;
}
V_6 -> V_3 = V_16 - V_6 -> V_2 ;
F_11 ( V_6 -> V_3 + sizeof( * V_6 ) > 2048 ) ;
return 0 ;
}
void
F_13 ( void * V_39 , void * V_40 , struct V_41 * V_42 )
{
struct V_9 * V_10 = V_40 ;
V_10 -> V_43 = F_14 ( L_27 , V_44 , V_42 , V_10 ,
& V_45 ) ;
V_10 -> V_46 = F_14 ( L_28 , V_44 , V_42 ,
V_10 , & V_47 ) ;
}
void
F_15 ( void * V_39 , void * V_40 )
{
struct V_9 * V_10 = V_40 ;
F_16 ( V_10 -> V_43 ) ;
F_16 ( V_10 -> V_46 ) ;
}
