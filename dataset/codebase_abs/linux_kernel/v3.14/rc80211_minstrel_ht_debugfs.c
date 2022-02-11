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
* ( V_4 ++ ) = ( V_27 == V_2 -> V_28 ) ? 'T' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_29 ) ? 't' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_30 ) ? 'P' : ' ' ;
if ( V_3 == V_5 ) {
int V_31 = V_26 [ V_10 % 4 ] ;
V_4 += sprintf ( V_4 , L_3 , V_31 / 10 , V_31 % 10 ) ;
} else {
V_4 += sprintf ( V_4 , L_4 , ( V_9 -> V_32 - 1 ) * 8 + V_10 ) ;
}
V_11 = V_24 -> V_33 / 10 ;
V_12 = F_3 ( V_24 -> V_34 * 1000 ) ;
V_13 = F_3 ( V_24 -> V_35 * 1000 ) ;
V_4 += sprintf ( V_4 , L_5
L_6 ,
V_11 / 10 , V_11 % 10 ,
V_13 / 10 , V_13 % 10 ,
V_12 / 10 , V_12 % 10 ,
V_24 -> V_36 ,
V_24 -> V_37 ,
V_24 -> V_38 ,
( unsigned long long ) V_24 -> V_39 ,
( unsigned long long ) V_24 -> V_40 ) ;
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
unsigned int V_5 = V_6 * V_7 ;
char * V_4 ;
int V_49 ;
if ( ! V_44 -> V_50 ) {
V_41 -> V_45 = & V_44 -> V_51 ;
V_49 = F_5 ( V_41 , V_42 ) ;
V_41 -> V_45 = V_44 ;
return V_49 ;
}
V_48 = F_6 ( sizeof( * V_48 ) + 8192 , V_52 ) ;
if ( ! V_48 )
return - V_53 ;
V_42 -> V_54 = V_48 ;
V_4 = V_48 -> V_55 ;
V_4 += sprintf ( V_4 , L_7
L_8 ) ;
V_4 = F_1 ( V_2 , V_5 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += sprintf ( V_4 , L_9
L_10 ,
F_7 ( 0 , ( int ) V_2 -> V_56 - ( int ) V_2 -> V_57 ) ,
V_2 -> V_57 ) ;
V_4 += sprintf ( V_4 , L_11 ,
F_3 ( V_2 -> V_58 ) ,
F_3 ( V_2 -> V_58 * 10 ) % 10 ) ;
V_48 -> V_59 = V_4 - V_48 -> V_55 ;
return F_8 ( V_41 , V_42 ) ;
}
void
F_9 ( void * V_60 , void * V_61 , struct V_62 * V_63 )
{
struct V_43 * V_44 = V_61 ;
V_44 -> V_64 = F_10 ( L_12 , V_65 , V_63 , V_44 ,
& V_66 ) ;
}
void
F_11 ( void * V_60 , void * V_61 )
{
struct V_43 * V_44 = V_61 ;
F_12 ( V_44 -> V_64 ) ;
}
