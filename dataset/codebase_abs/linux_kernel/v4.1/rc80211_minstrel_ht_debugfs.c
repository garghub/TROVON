static char *
F_1 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
char V_13 = '2' ;
char V_14 = 'L' ;
T_1 V_15 ;
if ( ! V_2 -> V_16 [ V_3 ] . V_17 )
return V_4 ;
V_6 = & V_18 [ V_3 ] ;
V_15 = V_6 -> V_19 ;
if ( V_15 & V_20 )
V_13 = '4' ;
else if ( V_15 & V_21 )
V_13 = '8' ;
if ( V_15 & V_22 )
V_14 = 'S' ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
struct V_24 * V_25 = & V_2 -> V_16 [ V_3 ] . V_26 [ V_7 ] ;
static const int V_27 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_28 = V_3 * V_23 + V_7 ;
if ( ! ( V_2 -> V_16 [ V_3 ] . V_17 & F_2 ( V_7 ) ) )
continue;
if ( V_15 & V_29 ) {
V_4 += sprintf ( V_4 , L_1 , V_13 ) ;
V_4 += sprintf ( V_4 , L_2 , V_14 ) ;
V_4 += sprintf ( V_4 , L_3 , V_6 -> V_30 ) ;
} else if ( V_15 & V_31 ) {
V_4 += sprintf ( V_4 , L_4 , V_13 ) ;
V_4 += sprintf ( V_4 , L_5 , V_14 ) ;
V_4 += sprintf ( V_4 , L_3 , V_6 -> V_30 ) ;
} else {
V_4 += sprintf ( V_4 , L_6 ) ;
V_4 += sprintf ( V_4 , L_7 , V_7 < 4 ? 'L' : 'S' ) ;
V_4 += sprintf ( V_4 , L_8 ) ;
}
* ( V_4 ++ ) = ( V_28 == V_2 -> V_32 [ 0 ] ) ? 'A' : ' ' ;
* ( V_4 ++ ) = ( V_28 == V_2 -> V_32 [ 1 ] ) ? 'B' : ' ' ;
* ( V_4 ++ ) = ( V_28 == V_2 -> V_32 [ 2 ] ) ? 'C' : ' ' ;
* ( V_4 ++ ) = ( V_28 == V_2 -> V_32 [ 3 ] ) ? 'D' : ' ' ;
* ( V_4 ++ ) = ( V_28 == V_2 -> V_33 ) ? 'P' : ' ' ;
if ( V_15 & V_29 ) {
V_4 += sprintf ( V_4 , L_9 , ( V_6 -> V_30 - 1 ) * 8 + V_7 ) ;
} else if ( V_15 & V_31 ) {
V_4 += sprintf ( V_4 , L_10 , V_7 , V_6 -> V_30 ) ;
} else {
int V_34 = V_27 [ V_7 % 4 ] ;
V_4 += sprintf ( V_4 , L_11 , V_34 / 10 , V_34 % 10 ) ;
}
V_4 += sprintf ( V_4 , L_12 , V_28 ) ;
V_12 = F_3 ( V_6 -> V_35 [ V_7 ] , 1000 ) ;
V_4 += sprintf ( V_4 , L_13 , V_12 ) ;
V_8 = F_4 ( V_2 , V_3 , V_7 , F_5 ( 100 , 100 ) ) ;
V_9 = F_4 ( V_2 , V_3 , V_7 , V_25 -> V_36 ) ;
V_10 = F_6 ( V_25 -> V_37 * 1000 ) ;
V_11 = F_6 ( V_25 -> V_36 * 1000 ) ;
V_4 += sprintf ( V_4 , L_14
L_15
L_16 ,
V_8 / 10 , V_8 % 10 ,
V_9 / 10 , V_9 % 10 ,
V_11 / 10 , V_11 % 10 ,
V_25 -> V_38 / 10 , V_25 -> V_38 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_25 -> V_39 ,
V_25 -> V_40 ,
V_25 -> V_41 ,
( unsigned long long ) V_25 -> V_42 ,
( unsigned long long ) V_25 -> V_43 ) ;
}
return V_4 ;
}
static int
F_7 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_1 * V_2 = & V_47 -> V_49 ;
struct V_50 * V_51 ;
unsigned int V_3 ;
int V_52 ;
char * V_4 ;
if ( ! V_47 -> V_53 ) {
V_44 -> V_48 = & V_47 -> V_54 ;
V_52 = F_8 ( V_44 , V_45 ) ;
V_44 -> V_48 = V_47 ;
return V_52 ;
}
V_51 = F_9 ( 32768 , V_55 ) ;
if ( ! V_51 )
return - V_56 ;
V_45 -> V_57 = V_51 ;
V_4 = V_51 -> V_58 ;
V_4 += sprintf ( V_4 , L_17 ) ;
V_4 += sprintf ( V_4 , L_18
L_19
L_20 ) ;
V_4 += sprintf ( V_4 , L_21
L_22
L_23 ) ;
V_4 = F_1 ( V_2 , V_59 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_3 ++ ; V_3 < F_10 ( V_2 -> V_16 ) ; V_3 ++ )
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_4 += sprintf ( V_4 , L_24
L_25 ,
F_11 ( 0 , ( int ) V_2 -> V_60 - ( int ) V_2 -> V_61 ) ,
V_2 -> V_61 ) ;
V_4 += sprintf ( V_4 , L_26 ,
F_6 ( V_2 -> V_62 ) ,
F_6 ( V_2 -> V_62 * 10 ) % 10 ) ;
V_51 -> V_63 = V_4 - V_51 -> V_58 ;
F_12 ( V_51 -> V_63 + sizeof( * V_51 ) > 32768 ) ;
return F_13 ( V_44 , V_45 ) ;
}
static char *
F_14 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
char V_13 = '2' ;
char V_14 = 'L' ;
T_1 V_15 ;
if ( ! V_2 -> V_16 [ V_3 ] . V_17 )
return V_4 ;
V_6 = & V_18 [ V_3 ] ;
V_15 = V_6 -> V_19 ;
if ( V_15 & V_20 )
V_13 = '4' ;
else if ( V_15 & V_21 )
V_13 = '8' ;
if ( V_15 & V_22 )
V_14 = 'S' ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
struct V_24 * V_25 = & V_2 -> V_16 [ V_3 ] . V_26 [ V_7 ] ;
static const int V_27 [ 4 ] = { 10 , 20 , 55 , 110 } ;
int V_28 = V_3 * V_23 + V_7 ;
if ( ! ( V_2 -> V_16 [ V_3 ] . V_17 & F_2 ( V_7 ) ) )
continue;
if ( V_15 & V_29 ) {
V_4 += sprintf ( V_4 , L_27 , V_13 ) ;
V_4 += sprintf ( V_4 , L_28 , V_14 ) ;
V_4 += sprintf ( V_4 , L_29 , V_6 -> V_30 ) ;
} else if ( V_15 & V_31 ) {
V_4 += sprintf ( V_4 , L_30 , V_13 ) ;
V_4 += sprintf ( V_4 , L_28 , V_14 ) ;
V_4 += sprintf ( V_4 , L_29 , V_6 -> V_30 ) ;
} else {
V_4 += sprintf ( V_4 , L_31 ) ;
V_4 += sprintf ( V_4 , L_32 , V_7 < 4 ? 'L' : 'S' ) ;
V_4 += sprintf ( V_4 , L_33 ) ;
}
V_4 += sprintf ( V_4 , L_34 , ( ( V_28 == V_2 -> V_32 [ 0 ] ) ? L_35 : L_36 ) ) ;
V_4 += sprintf ( V_4 , L_34 , ( ( V_28 == V_2 -> V_32 [ 1 ] ) ? L_37 : L_36 ) ) ;
V_4 += sprintf ( V_4 , L_34 , ( ( V_28 == V_2 -> V_32 [ 2 ] ) ? L_38 : L_36 ) ) ;
V_4 += sprintf ( V_4 , L_34 , ( ( V_28 == V_2 -> V_32 [ 3 ] ) ? L_39 : L_36 ) ) ;
V_4 += sprintf ( V_4 , L_34 , ( ( V_28 == V_2 -> V_33 ) ? L_40 : L_36 ) ) ;
if ( V_15 & V_29 ) {
V_4 += sprintf ( V_4 , L_41 , ( V_6 -> V_30 - 1 ) * 8 + V_7 ) ;
} else if ( V_15 & V_31 ) {
V_4 += sprintf ( V_4 , L_42 , V_7 , V_6 -> V_30 ) ;
} else {
int V_34 = V_27 [ V_7 % 4 ] ;
V_4 += sprintf ( V_4 , L_43 , V_34 / 10 , V_34 % 10 ) ;
}
V_4 += sprintf ( V_4 , L_44 , V_28 ) ;
V_12 = F_3 ( V_6 -> V_35 [ V_7 ] , 1000 ) ;
V_4 += sprintf ( V_4 , L_44 , V_12 ) ;
V_8 = F_4 ( V_2 , V_3 , V_7 , F_5 ( 100 , 100 ) ) ;
V_9 = F_4 ( V_2 , V_3 , V_7 , V_25 -> V_36 ) ;
V_10 = F_6 ( V_25 -> V_37 * 1000 ) ;
V_11 = F_6 ( V_25 -> V_36 * 1000 ) ;
V_4 += sprintf ( V_4 , L_45
L_46 ,
V_8 / 10 , V_8 % 10 ,
V_9 / 10 , V_9 % 10 ,
V_11 / 10 , V_11 % 10 ,
V_25 -> V_38 / 10 , V_25 -> V_38 % 10 ,
V_10 / 10 , V_10 % 10 ,
V_25 -> V_39 ,
V_25 -> V_40 ,
V_25 -> V_41 ,
( unsigned long long ) V_25 -> V_42 ,
( unsigned long long ) V_25 -> V_43 ) ;
V_4 += sprintf ( V_4 , L_47 ,
F_11 ( 0 , ( int ) V_2 -> V_60 -
( int ) V_2 -> V_61 ) ,
V_2 -> V_61 ,
F_6 ( V_2 -> V_62 ) ,
F_6 ( V_2 -> V_62 * 10 ) % 10 ) ;
}
return V_4 ;
}
static int
F_15 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_1 * V_2 = & V_47 -> V_49 ;
struct V_50 * V_51 ;
unsigned int V_3 ;
int V_52 ;
char * V_4 ;
if ( ! V_47 -> V_53 ) {
V_44 -> V_48 = & V_47 -> V_54 ;
V_52 = F_16 ( V_44 , V_45 ) ;
V_44 -> V_48 = V_47 ;
return V_52 ;
}
V_51 = F_9 ( 32768 , V_55 ) ;
if ( ! V_51 )
return - V_56 ;
V_45 -> V_57 = V_51 ;
V_4 = V_51 -> V_58 ;
V_4 = F_14 ( V_2 , V_59 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ )
V_4 = F_14 ( V_2 , V_3 , V_4 ) ;
for ( V_3 ++ ; V_3 < F_10 ( V_2 -> V_16 ) ; V_3 ++ )
V_4 = F_14 ( V_2 , V_3 , V_4 ) ;
V_51 -> V_63 = V_4 - V_51 -> V_58 ;
F_12 ( V_51 -> V_63 + sizeof( * V_51 ) > 32768 ) ;
return F_13 ( V_44 , V_45 ) ;
}
void
F_17 ( void * V_64 , void * V_65 , struct V_66 * V_67 )
{
struct V_46 * V_47 = V_65 ;
V_47 -> V_68 = F_18 ( L_48 , V_69 , V_67 , V_47 ,
& V_70 ) ;
V_47 -> V_71 = F_18 ( L_49 , V_69 ,
V_67 , V_47 , & V_72 ) ;
}
void
F_19 ( void * V_64 , void * V_65 )
{
struct V_46 * V_47 = V_65 ;
F_20 ( V_47 -> V_68 ) ;
F_20 ( V_47 -> V_71 ) ;
}
