static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 , V_12 , V_13 , V_14 , V_15 ;
char * V_16 ;
int V_17 ;
if ( ! V_4 -> V_18 ) {
V_1 -> V_5 = & V_4 -> V_19 ;
V_17 = F_2 ( V_1 , V_2 ) ;
V_1 -> V_5 = V_4 ;
return V_17 ;
}
V_10 = F_3 ( sizeof( * V_10 ) + 8192 , V_20 ) ;
if ( ! V_10 )
return - V_21 ;
V_2 -> V_22 = V_10 ;
V_16 = V_10 -> V_23 ;
V_16 += sprintf ( V_16 , L_1
L_2 ) ;
for ( V_11 = 0 ; V_11 < V_24 * V_25 ; V_11 ++ ) {
char V_26 = '2' ;
char V_27 = 'L' ;
if ( ! V_7 -> V_28 [ V_11 ] . V_29 )
continue;
if ( V_30 [ V_11 ] . V_31 & V_32 )
V_26 = '4' ;
if ( V_30 [ V_11 ] . V_31 & V_33 )
V_27 = 'S' ;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
struct V_35 * V_36 = & V_7 -> V_28 [ V_11 ] . V_37 [ V_12 ] ;
int V_38 = V_11 * V_34 + V_12 ;
if ( ! ( V_7 -> V_28 [ V_11 ] . V_29 & F_4 ( V_12 ) ) )
continue;
V_16 += sprintf ( V_16 , L_3 , V_26 , V_27 ) ;
* ( V_16 ++ ) = ( V_38 == V_7 -> V_39 ) ? 'T' : ' ' ;
* ( V_16 ++ ) = ( V_38 == V_7 -> V_40 ) ? 't' : ' ' ;
* ( V_16 ++ ) = ( V_38 == V_7 -> V_41 ) ? 'P' : ' ' ;
V_16 += sprintf ( V_16 , L_4 , ( V_30 [ V_11 ] . V_42 - 1 ) *
V_34 + V_12 ) ;
V_13 = V_36 -> V_43 / 10 ;
V_14 = F_5 ( V_36 -> V_44 * 1000 ) ;
V_15 = F_5 ( V_36 -> V_45 * 1000 ) ;
V_16 += sprintf ( V_16 , L_5
L_6 ,
V_13 / 10 , V_13 % 10 ,
V_15 / 10 , V_15 % 10 ,
V_14 / 10 , V_14 % 10 ,
V_36 -> V_46 ,
V_36 -> V_47 ,
( unsigned long long ) V_36 -> V_48 ,
( unsigned long long ) V_36 -> V_49 ) ;
}
}
V_16 += sprintf ( V_16 , L_7
L_8 ,
F_6 ( 0 , ( int ) V_7 -> V_50 - ( int ) V_7 -> V_51 ) ,
V_7 -> V_51 ) ;
V_16 += sprintf ( V_16 , L_9 ,
F_5 ( V_7 -> V_52 ) ,
F_5 ( V_7 -> V_52 * 10 ) % 10 ) ;
V_10 -> V_53 = V_16 - V_10 -> V_23 ;
return F_7 ( V_1 , V_2 ) ;
}
void
F_8 ( void * V_54 , void * V_55 , struct V_56 * V_57 )
{
struct V_3 * V_4 = V_55 ;
V_4 -> V_58 = F_9 ( L_10 , V_59 , V_57 , V_4 ,
& V_60 ) ;
}
void
F_10 ( void * V_54 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
F_11 ( V_4 -> V_58 ) ;
}
