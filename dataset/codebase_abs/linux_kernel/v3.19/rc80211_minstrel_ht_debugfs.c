static char *
F_1 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 ;
char V_11 = '2' ;
char V_12 = 'L' ;
T_1 V_13 ;
if ( ! V_2 -> V_14 [ V_3 ] . V_15 )
return V_4 ;
V_6 = & V_16 [ V_3 ] ;
V_13 = V_6 -> V_17 ;
if ( V_13 & V_18 )
V_11 = '4' ;
else if ( V_13 & V_19 )
V_11 = '8' ;
if ( V_13 & V_20 )
V_12 = 'S' ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
struct V_22 * V_23 = & V_2 -> V_14 [ V_3 ] . V_24 [ V_7 ] ;
static const int V_25 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_26 = V_3 * V_21 + V_7 ;
if ( ! ( V_2 -> V_14 [ V_3 ] . V_15 & F_2 ( V_7 ) ) )
continue;
if ( V_13 & V_27 )
V_4 += sprintf ( V_4 , L_1 , V_11 , V_12 ) ;
else if ( V_13 & V_28 )
V_4 += sprintf ( V_4 , L_2 , V_11 , V_12 ) ;
else
V_4 += sprintf ( V_4 , L_3 , V_7 < 4 ? 'L' : 'S' ) ;
* ( V_4 ++ ) = ( V_26 == V_2 -> V_29 [ 0 ] ) ? 'A' : ' ' ;
* ( V_4 ++ ) = ( V_26 == V_2 -> V_29 [ 1 ] ) ? 'B' : ' ' ;
* ( V_4 ++ ) = ( V_26 == V_2 -> V_29 [ 2 ] ) ? 'C' : ' ' ;
* ( V_4 ++ ) = ( V_26 == V_2 -> V_29 [ 3 ] ) ? 'D' : ' ' ;
* ( V_4 ++ ) = ( V_26 == V_2 -> V_30 ) ? 'P' : ' ' ;
if ( V_13 & V_27 ) {
V_4 += sprintf ( V_4 , L_4 , ( V_6 -> V_31 - 1 ) * 8 + V_7 ) ;
} else if ( V_13 & V_28 ) {
V_4 += sprintf ( V_4 , L_5 , V_7 , V_6 -> V_31 ) ;
} else {
int V_32 = V_25 [ V_7 % 4 ] ;
V_4 += sprintf ( V_4 , L_6 , V_32 / 10 , V_32 % 10 ) ;
}
V_8 = V_23 -> V_33 / 10 ;
V_9 = F_3 ( V_23 -> V_34 * 1000 ) ;
V_10 = F_3 ( V_23 -> V_35 * 1000 ) ;
V_4 += sprintf ( V_4 , L_7
L_8 ,
V_8 / 10 , V_8 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_9 / 10 , V_9 % 10 ,
V_23 -> V_36 ,
V_23 -> V_37 ,
V_23 -> V_38 ,
( unsigned long long ) V_23 -> V_39 ,
( unsigned long long ) V_23 -> V_40 ) ;
}
return V_4 ;
}
static int
F_4 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
struct V_1 * V_2 = & V_44 -> V_46 ;
struct V_47 * V_48 ;
unsigned int V_3 ;
char * V_4 ;
int V_49 ;
if ( ! V_44 -> V_50 ) {
V_41 -> V_45 = & V_44 -> V_51 ;
V_49 = F_5 ( V_41 , V_42 ) ;
V_41 -> V_45 = V_44 ;
return V_49 ;
}
V_48 = F_6 ( 32768 , V_52 ) ;
if ( ! V_48 )
return - V_53 ;
V_42 -> V_54 = V_48 ;
V_4 = V_48 -> V_55 ;
V_4 += sprintf ( V_4 , L_9
L_10 ) ;
V_4 = F_1 ( V_2 , V_56 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_56 ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_3 ++ ; V_3 < F_7 ( V_2 -> V_14 ) ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += sprintf ( V_4 , L_11
L_12 ,
F_8 ( 0 , ( int ) V_2 -> V_57 - ( int ) V_2 -> V_58 ) ,
V_2 -> V_58 ) ;
V_4 += sprintf ( V_4 , L_13 ,
F_3 ( V_2 -> V_59 ) ,
F_3 ( V_2 -> V_59 * 10 ) % 10 ) ;
V_48 -> V_60 = V_4 - V_48 -> V_55 ;
F_9 ( V_48 -> V_60 + sizeof( * V_48 ) > 32768 ) ;
return F_10 ( V_41 , V_42 ) ;
}
void
F_11 ( void * V_61 , void * V_62 , struct V_63 * V_64 )
{
struct V_43 * V_44 = V_62 ;
V_44 -> V_65 = F_12 ( L_14 , V_66 , V_64 , V_44 ,
& V_67 ) ;
}
void
F_13 ( void * V_61 , void * V_62 )
{
struct V_43 * V_44 = V_62 ;
F_14 ( V_44 -> V_65 ) ;
}
