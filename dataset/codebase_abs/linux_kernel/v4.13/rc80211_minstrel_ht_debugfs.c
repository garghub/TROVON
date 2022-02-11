static char *
F_1 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 ;
char V_12 = '2' ;
char V_13 = 'L' ;
T_1 V_14 ;
if ( ! V_2 -> V_15 [ V_3 ] )
return V_4 ;
V_6 = & V_16 [ V_3 ] ;
V_14 = V_6 -> V_17 ;
if ( V_14 & V_18 )
V_12 = '4' ;
else if ( V_14 & V_19 )
V_12 = '8' ;
if ( V_14 & V_20 )
V_13 = 'S' ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] . V_25 [ V_7 ] ;
static const int V_26 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_27 = V_3 * V_21 + V_7 ;
unsigned int V_28 ;
if ( ! ( V_2 -> V_15 [ V_3 ] & F_2 ( V_7 ) ) )
continue;
if ( V_14 & V_29 ) {
V_4 += sprintf ( V_4 , L_1 , V_12 ) ;
V_4 += sprintf ( V_4 , L_2 , V_13 ) ;
V_4 += sprintf ( V_4 , L_3 , V_6 -> V_30 ) ;
} else if ( V_14 & V_31 ) {
V_4 += sprintf ( V_4 , L_4 , V_12 ) ;
V_4 += sprintf ( V_4 , L_5 , V_13 ) ;
V_4 += sprintf ( V_4 , L_3 , V_6 -> V_30 ) ;
} else {
V_4 += sprintf ( V_4 , L_6 ) ;
V_4 += sprintf ( V_4 , L_7 , V_7 < 4 ? 'L' : 'S' ) ;
V_4 += sprintf ( V_4 , L_8 ) ;
}
* ( V_4 ++ ) = ( V_27 == V_2 -> V_32 [ 0 ] ) ? 'A' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_32 [ 1 ] ) ? 'B' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_32 [ 2 ] ) ? 'C' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_32 [ 3 ] ) ? 'D' : ' ' ;
* ( V_4 ++ ) = ( V_27 == V_2 -> V_33 ) ? 'P' : ' ' ;
if ( V_14 & V_29 ) {
V_4 += sprintf ( V_4 , L_9 , ( V_6 -> V_30 - 1 ) * 8 + V_7 ) ;
} else if ( V_14 & V_31 ) {
V_4 += sprintf ( V_4 , L_10 , V_7 , V_6 -> V_30 ) ;
} else {
int V_34 = V_26 [ V_7 % 4 ] ;
V_4 += sprintf ( V_4 , L_11 , V_34 / 10 , V_34 % 10 ) ;
}
V_4 += sprintf ( V_4 , L_12 , V_27 ) ;
V_11 = F_3 ( V_6 -> V_35 [ V_7 ] , 1000 ) ;
V_4 += sprintf ( V_4 , L_13 , V_11 ) ;
V_8 = F_4 ( V_2 , V_3 , V_7 , F_5 ( 100 , 100 ) ) ;
V_9 = F_4 ( V_2 , V_3 , V_7 , V_23 -> V_36 ) ;
V_10 = F_6 ( V_23 -> V_36 * 1000 ) ;
V_28 = F_7 ( V_23 ) ;
V_4 += sprintf ( V_4 , L_14
L_15
L_16 ,
V_8 / 10 , V_8 % 10 ,
V_9 / 10 , V_9 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_28 / 10 , V_28 % 10 ,
V_23 -> V_37 ,
V_23 -> V_38 ,
V_23 -> V_39 ,
( unsigned long long ) V_23 -> V_40 ,
( unsigned long long ) V_23 -> V_41 ) ;
}
return V_4 ;
}
static int
F_8 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_47 ;
struct V_48 * V_49 ;
unsigned int V_3 ;
int V_50 ;
char * V_4 ;
if ( ! V_45 -> V_51 ) {
V_42 -> V_46 = & V_45 -> V_52 ;
V_50 = F_9 ( V_42 , V_43 ) ;
V_42 -> V_46 = V_45 ;
return V_50 ;
}
V_49 = F_10 ( 32768 , V_53 ) ;
if ( ! V_49 )
return - V_54 ;
V_43 -> V_55 = V_49 ;
V_4 = V_49 -> V_56 ;
V_4 += sprintf ( V_4 , L_17 ) ;
V_4 += sprintf ( V_4 ,
L_18 ) ;
V_4 += sprintf ( V_4 ,
L_19 ) ;
V_4 = F_1 ( V_2 , V_57 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_3 ++ ; V_3 < F_11 ( V_2 -> V_24 ) ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += sprintf ( V_4 , L_20
L_21 ,
F_12 ( 0 , ( int ) V_2 -> V_58 - ( int ) V_2 -> V_59 ) ,
V_2 -> V_59 ) ;
V_4 += sprintf ( V_4 , L_22 ,
F_6 ( V_2 -> V_60 ) ,
F_6 ( V_2 -> V_60 * 10 ) % 10 ) ;
V_49 -> V_61 = V_4 - V_49 -> V_56 ;
F_13 ( V_49 -> V_61 + sizeof( * V_49 ) > 32768 ) ;
return F_14 ( V_42 , V_43 ) ;
}
static char *
F_15 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 ;
char V_12 = '2' ;
char V_13 = 'L' ;
T_1 V_14 ;
if ( ! V_2 -> V_15 [ V_3 ] )
return V_4 ;
V_6 = & V_16 [ V_3 ] ;
V_14 = V_6 -> V_17 ;
if ( V_14 & V_18 )
V_12 = '4' ;
else if ( V_14 & V_19 )
V_12 = '8' ;
if ( V_14 & V_20 )
V_13 = 'S' ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] . V_25 [ V_7 ] ;
static const int V_26 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_27 = V_3 * V_21 + V_7 ;
unsigned int V_28 ;
if ( ! ( V_2 -> V_15 [ V_3 ] & F_2 ( V_7 ) ) )
continue;
if ( V_14 & V_29 ) {
V_4 += sprintf ( V_4 , L_23 , V_12 ) ;
V_4 += sprintf ( V_4 , L_24 , V_13 ) ;
V_4 += sprintf ( V_4 , L_25 , V_6 -> V_30 ) ;
} else if ( V_14 & V_31 ) {
V_4 += sprintf ( V_4 , L_26 , V_12 ) ;
V_4 += sprintf ( V_4 , L_24 , V_13 ) ;
V_4 += sprintf ( V_4 , L_25 , V_6 -> V_30 ) ;
} else {
V_4 += sprintf ( V_4 , L_27 ) ;
V_4 += sprintf ( V_4 , L_28 , V_7 < 4 ? 'L' : 'S' ) ;
V_4 += sprintf ( V_4 , L_29 ) ;
}
V_4 += sprintf ( V_4 , L_30 , ( ( V_27 == V_2 -> V_32 [ 0 ] ) ? L_31 : L_32 ) ) ;
V_4 += sprintf ( V_4 , L_30 , ( ( V_27 == V_2 -> V_32 [ 1 ] ) ? L_33 : L_32 ) ) ;
V_4 += sprintf ( V_4 , L_30 , ( ( V_27 == V_2 -> V_32 [ 2 ] ) ? L_34 : L_32 ) ) ;
V_4 += sprintf ( V_4 , L_30 , ( ( V_27 == V_2 -> V_32 [ 3 ] ) ? L_35 : L_32 ) ) ;
V_4 += sprintf ( V_4 , L_30 , ( ( V_27 == V_2 -> V_33 ) ? L_36 : L_32 ) ) ;
if ( V_14 & V_29 ) {
V_4 += sprintf ( V_4 , L_37 , ( V_6 -> V_30 - 1 ) * 8 + V_7 ) ;
} else if ( V_14 & V_31 ) {
V_4 += sprintf ( V_4 , L_38 , V_7 , V_6 -> V_30 ) ;
} else {
int V_34 = V_26 [ V_7 % 4 ] ;
V_4 += sprintf ( V_4 , L_39 , V_34 / 10 , V_34 % 10 ) ;
}
V_4 += sprintf ( V_4 , L_40 , V_27 ) ;
V_11 = F_3 ( V_6 -> V_35 [ V_7 ] , 1000 ) ;
V_4 += sprintf ( V_4 , L_40 , V_11 ) ;
V_8 = F_4 ( V_2 , V_3 , V_7 , F_5 ( 100 , 100 ) ) ;
V_9 = F_4 ( V_2 , V_3 , V_7 , V_23 -> V_36 ) ;
V_10 = F_6 ( V_23 -> V_36 * 1000 ) ;
V_28 = F_7 ( V_23 ) ;
V_4 += sprintf ( V_4 , L_41
L_42 ,
V_8 / 10 , V_8 % 10 ,
V_9 / 10 , V_9 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_28 / 10 , V_28 % 10 ,
V_23 -> V_37 ,
V_23 -> V_38 ,
V_23 -> V_39 ,
( unsigned long long ) V_23 -> V_40 ,
( unsigned long long ) V_23 -> V_41 ) ;
V_4 += sprintf ( V_4 , L_43 ,
F_12 ( 0 , ( int ) V_2 -> V_58 -
( int ) V_2 -> V_59 ) ,
V_2 -> V_59 ,
F_6 ( V_2 -> V_60 ) ,
F_6 ( V_2 -> V_60 * 10 ) % 10 ) ;
}
return V_4 ;
}
static int
F_16 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_47 ;
struct V_48 * V_49 ;
unsigned int V_3 ;
int V_50 ;
char * V_4 ;
if ( ! V_45 -> V_51 ) {
V_42 -> V_46 = & V_45 -> V_52 ;
V_50 = F_17 ( V_42 , V_43 ) ;
V_42 -> V_46 = V_45 ;
return V_50 ;
}
V_49 = F_10 ( 32768 , V_53 ) ;
if ( ! V_49 )
return - V_54 ;
V_43 -> V_55 = V_49 ;
V_4 = V_49 -> V_56 ;
V_4 = F_15 ( V_2 , V_57 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
V_4 = F_15 ( V_2 , V_3 , V_4 ) ;
for ( V_3 ++ ; V_3 < F_11 ( V_2 -> V_24 ) ; V_3 ++ )
V_4 = F_15 ( V_2 , V_3 , V_4 ) ;
V_49 -> V_61 = V_4 - V_49 -> V_56 ;
F_13 ( V_49 -> V_61 + sizeof( * V_49 ) > 32768 ) ;
return F_14 ( V_42 , V_43 ) ;
}
void
F_18 ( void * V_62 , void * V_63 , struct V_64 * V_65 )
{
struct V_44 * V_45 = V_63 ;
V_45 -> V_66 = F_19 ( L_44 , V_67 , V_65 , V_45 ,
& V_68 ) ;
V_45 -> V_69 = F_19 ( L_45 , V_67 ,
V_65 , V_45 , & V_70 ) ;
}
void
F_20 ( void * V_62 , void * V_63 )
{
struct V_44 * V_45 = V_63 ;
F_21 ( V_45 -> V_66 ) ;
F_21 ( V_45 -> V_69 ) ;
}
