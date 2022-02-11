static char *
F_1 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
unsigned int V_5 = V_6 * V_7 ;
const struct V_8 * V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
char V_14 = '2' ;
char V_15 = 'L' ;
if ( ! V_2 -> V_16 [ V_3 ] . V_17 )
return V_4 ;
V_9 = & V_18 [ V_3 ] ;
if ( V_9 -> V_19 & V_20 )
V_14 = '4' ;
if ( V_9 -> V_19 & V_21 )
V_15 = 'S' ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
struct V_23 * V_24 = & V_2 -> V_16 [ V_3 ] . V_25 [ V_10 ] ;
static const int V_26 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_27 = V_3 * V_22 + V_10 ;
if ( ! ( V_2 -> V_16 [ V_3 ] . V_17 & F_2 ( V_10 ) ) )
continue;
if ( V_3 == V_5 )
V_4 += sprintf ( V_4 , L_1 , V_10 < 4 ? 'L' : 'S' ) ;
else
V_4 += sprintf ( V_4 , L_2 , V_14 , V_15 ) ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_28 [ 0 ] ) ? 'A' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_28 [ 1 ] ) ? 'B' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_28 [ 2 ] ) ? 'C' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_28 [ 3 ] ) ? 'D' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_29 ) ? 'P' : ' ' ;
if ( V_3 == V_5 ) {
int V_30 = V_26 [ V_10 % 4 ] ;
V_4 += sprintf ( V_4 , L_3 , V_30 / 10 , V_30 % 10 ) ;
} else {
V_4 += sprintf ( V_4 , L_4 , ( V_9 -> V_31 - 1 ) * 8 + V_10 ) ;
}
V_11 = V_24 -> V_32 / 10 ;
V_12 = F_3 ( V_24 -> V_33 * 1000 ) ;
V_13 = F_3 ( V_24 -> V_34 * 1000 ) ;
V_4 += sprintf ( V_4 , L_5
L_6 ,
V_11 / 10 , V_11 % 10 ,
V_13 / 10 , V_13 % 10 ,
V_12 / 10 , V_12 % 10 ,
V_24 -> V_35 ,
V_24 -> V_36 ,
V_24 -> V_37 ,
( unsigned long long ) V_24 -> V_38 ,
( unsigned long long ) V_24 -> V_39 ) ;
}
return V_4 ;
}
static int
F_4 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_45 ;
struct V_46 * V_47 ;
unsigned int V_3 ;
unsigned int V_5 = V_6 * V_7 ;
char * V_4 ;
int V_48 ;
if ( ! V_43 -> V_49 ) {
V_40 -> V_44 = & V_43 -> V_50 ;
V_48 = F_5 ( V_40 , V_41 ) ;
V_40 -> V_44 = V_43 ;
return V_48 ;
}
V_47 = F_6 ( 8192 , V_51 ) ;
if ( ! V_47 )
return - V_52 ;
V_41 -> V_53 = V_47 ;
V_4 = V_47 -> V_54 ;
V_4 += sprintf ( V_4 , L_7
L_8 ) ;
V_4 = F_1 ( V_2 , V_5 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += sprintf ( V_4 , L_9
L_10 ,
F_7 ( 0 , ( int ) V_2 -> V_55 - ( int ) V_2 -> V_56 ) ,
V_2 -> V_56 ) ;
V_4 += sprintf ( V_4 , L_11 ,
F_3 ( V_2 -> V_57 ) ,
F_3 ( V_2 -> V_57 * 10 ) % 10 ) ;
V_47 -> V_58 = V_4 - V_47 -> V_54 ;
F_8 ( V_47 -> V_58 + sizeof( * V_47 ) > 8192 ) ;
return F_9 ( V_40 , V_41 ) ;
}
void
F_10 ( void * V_59 , void * V_60 , struct V_61 * V_62 )
{
struct V_42 * V_43 = V_60 ;
V_43 -> V_63 = F_11 ( L_12 , V_64 , V_62 , V_43 ,
& V_65 ) ;
}
void
F_12 ( void * V_59 , void * V_60 )
{
struct V_42 * V_43 = V_60 ;
F_13 ( V_43 -> V_63 ) ;
}
