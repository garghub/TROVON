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
unsigned int V_12 , V_13 , V_14 , V_15 , V_16 ;
char * V_17 ;
V_6 = F_6 ( 2048 , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
V_1 -> V_7 = V_6 ;
V_17 = V_6 -> V_2 ;
V_17 += sprintf ( V_17 , L_1 ) ;
V_17 += sprintf ( V_17 , L_2
L_3
L_4 ) ;
V_17 += sprintf ( V_17 , L_5
L_6
L_7 ) ;
for ( V_12 = 0 ; V_12 < V_10 -> V_20 ; V_12 ++ ) {
struct V_21 * V_22 = & V_10 -> V_23 [ V_12 ] ;
struct V_24 * V_25 = & V_10 -> V_23 [ V_12 ] . V_26 ;
* ( V_17 ++ ) = ( V_12 == V_10 -> V_27 [ 0 ] ) ? 'A' : ' ' ;
* ( V_17 ++ ) = ( V_12 == V_10 -> V_27 [ 1 ] ) ? 'B' : ' ' ;
* ( V_17 ++ ) = ( V_12 == V_10 -> V_27 [ 2 ] ) ? 'C' : ' ' ;
* ( V_17 ++ ) = ( V_12 == V_10 -> V_27 [ 3 ] ) ? 'D' : ' ' ;
* ( V_17 ++ ) = ( V_12 == V_10 -> V_28 ) ? 'P' : ' ' ;
V_17 += sprintf ( V_17 , L_8 , V_22 -> V_29 / 2 ,
( V_22 -> V_29 & 1 ? L_9 : L_10 ) ) ;
V_17 += sprintf ( V_17 , L_11 , V_12 ) ;
V_17 += sprintf ( V_17 , L_12 , V_22 -> V_30 ) ;
V_13 = F_7 ( V_22 , F_8 ( 100 , 100 ) ) ;
V_14 = F_7 ( V_22 , V_25 -> V_31 ) ;
V_15 = F_9 ( V_25 -> V_32 * 1000 ) ;
V_16 = F_9 ( V_25 -> V_31 * 1000 ) ;
V_17 += sprintf ( V_17 , L_13
L_14
L_15 ,
V_13 / 10 , V_13 % 10 ,
V_14 / 10 , V_14 % 10 ,
V_16 / 10 , V_16 % 10 ,
V_25 -> V_33 / 10 , V_25 -> V_33 % 10 ,
V_15 / 10 , V_15 % 10 ,
V_25 -> V_34 ,
V_25 -> V_35 ,
V_25 -> V_36 ,
( unsigned long long ) V_25 -> V_37 ,
( unsigned long long ) V_25 -> V_38 ) ;
}
V_17 += sprintf ( V_17 , L_16
L_17 ,
V_10 -> V_39 - V_10 -> V_40 ,
V_10 -> V_40 ) ;
V_6 -> V_3 = V_17 - V_6 -> V_2 ;
F_10 ( V_6 -> V_3 + sizeof( * V_6 ) > 2048 ) ;
return 0 ;
}
int
F_11 ( struct V_8 * V_8 , struct V_1 * V_1 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_5 * V_6 ;
unsigned int V_12 , V_13 , V_14 , V_15 , V_16 ;
char * V_17 ;
V_6 = F_6 ( 2048 , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
V_1 -> V_7 = V_6 ;
V_17 = V_6 -> V_2 ;
for ( V_12 = 0 ; V_12 < V_10 -> V_20 ; V_12 ++ ) {
struct V_21 * V_22 = & V_10 -> V_23 [ V_12 ] ;
struct V_24 * V_25 = & V_10 -> V_23 [ V_12 ] . V_26 ;
V_17 += sprintf ( V_17 , L_18 , ( ( V_12 == V_10 -> V_27 [ 0 ] ) ? L_19 : L_20 ) ) ;
V_17 += sprintf ( V_17 , L_18 , ( ( V_12 == V_10 -> V_27 [ 1 ] ) ? L_21 : L_20 ) ) ;
V_17 += sprintf ( V_17 , L_18 , ( ( V_12 == V_10 -> V_27 [ 2 ] ) ? L_22 : L_20 ) ) ;
V_17 += sprintf ( V_17 , L_18 , ( ( V_12 == V_10 -> V_27 [ 3 ] ) ? L_23 : L_20 ) ) ;
V_17 += sprintf ( V_17 , L_18 , ( ( V_12 == V_10 -> V_28 ) ? L_24 : L_20 ) ) ;
V_17 += sprintf ( V_17 , L_25 , V_22 -> V_29 / 2 ,
( V_22 -> V_29 & 1 ? L_26 : L_27 ) ) ;
V_17 += sprintf ( V_17 , L_28 , V_12 ) ;
V_17 += sprintf ( V_17 , L_28 , V_22 -> V_30 ) ;
V_13 = F_7 ( V_22 , F_8 ( 100 , 100 ) ) ;
V_14 = F_7 ( V_22 , V_25 -> V_31 ) ;
V_15 = F_9 ( V_25 -> V_32 * 1000 ) ;
V_16 = F_9 ( V_25 -> V_31 * 1000 ) ;
V_17 += sprintf ( V_17 , L_29
L_30 ,
V_13 / 10 , V_13 % 10 ,
V_14 / 10 , V_14 % 10 ,
V_16 / 10 , V_16 % 10 ,
V_25 -> V_33 / 10 , V_25 -> V_33 % 10 ,
V_15 / 10 , V_15 % 10 ,
V_25 -> V_34 ,
V_25 -> V_35 ,
V_25 -> V_36 ,
( unsigned long long ) V_25 -> V_37 ,
( unsigned long long ) V_25 -> V_38 ,
V_10 -> V_39 - V_10 -> V_40 ,
V_10 -> V_40 ) ;
}
V_6 -> V_3 = V_17 - V_6 -> V_2 ;
F_10 ( V_6 -> V_3 + sizeof( * V_6 ) > 2048 ) ;
return 0 ;
}
void
F_12 ( void * V_41 , void * V_42 , struct V_43 * V_44 )
{
struct V_9 * V_10 = V_42 ;
V_10 -> V_45 = F_13 ( L_31 , V_46 , V_44 , V_10 ,
& V_47 ) ;
V_10 -> V_48 = F_13 ( L_32 , V_46 , V_44 ,
V_10 , & V_49 ) ;
}
void
F_14 ( void * V_41 , void * V_42 )
{
struct V_9 * V_10 = V_42 ;
F_15 ( V_10 -> V_45 ) ;
F_15 ( V_10 -> V_48 ) ;
}
