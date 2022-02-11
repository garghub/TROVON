static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = F_4 ( ( T_2 ) V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_6 ( V_6 , V_3 , F_4 ( V_4 ) ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_9 [ 4 ] ;
int V_7 = 0 ;
int V_10 , V_11 ;
if ( V_3 == V_12 || V_3 == V_13 )
V_11 = 2 ;
else if ( V_3 == V_14 ) {
if ( ! V_2 -> V_15 ) {
F_3 ( & V_6 -> V_8 , L_3 ) ;
return - V_16 ;
}
V_11 = 2 + V_2 -> V_15 * 2 ;
} else {
F_3 ( & V_6 -> V_8 , L_4 ) ;
return - V_16 ;
}
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = ( V_2 -> V_17 >> 8 ) & 0xff ;
V_9 [ 2 ] = V_2 -> V_17 & 0xff ;
V_9 [ 3 ] = V_3 ;
V_7 = F_8 ( V_6 , V_9 , 4 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_5 ) ;
return V_7 ;
}
V_7 = F_9 ( V_6 , ( T_1 * ) V_4 , V_11 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_6 ) ;
return V_7 ;
}
V_7 >>= 2 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
V_4 [ V_10 ] = F_4 ( V_4 [ V_10 ] ) ;
return V_7 ;
}
static T_3 F_10 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
if ( V_2 -> V_17 & V_25 )
return sprintf ( V_21 , L_7 ) ;
else
return sprintf ( V_21 , L_8 ) ;
}
static T_3 F_12 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_25 ) ;
if ( strcmp ( V_21 , L_9 ) )
V_17 |= V_25 ;
V_7 = F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_7 )
return - V_28 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_13 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
return sprintf ( V_21 , L_10 ) ;
}
static T_3 F_14 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 | V_29 ;
V_7 = F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_7 )
return - V_28 ;
return V_7 ;
}
static T_3 F_15 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
return sprintf ( V_21 , L_11 , ! ! ( V_2 -> V_17 & V_30 ) ) ;
}
static T_3 F_16 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_30 ) ;
if ( strcmp ( V_21 , L_12 ) )
V_17 |= V_30 ;
V_7 = F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_7 )
return - V_28 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_17 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
return sprintf ( V_21 , L_11 , ! ! ( V_2 -> V_17 & V_31 ) ) ;
}
static T_3 F_18 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_31 ) ;
if ( strcmp ( V_21 , L_12 ) )
V_17 |= V_31 ;
V_7 = F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_7 )
return - V_28 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_19 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_4 ;
char V_32 = ' ' ;
int V_7 ;
V_7 = F_7 ( V_2 , V_12 , & V_4 ) ;
if ( V_7 )
return - V_28 ;
if ( V_4 & V_33 ) {
V_4 = ( V_33 << 1 ) - V_4 ;
V_32 = '-' ;
}
return sprintf ( V_21 , L_13 , V_32 ,
( V_4 >> V_34 ) ,
( V_4 & V_35 ) * 25 ) ;
}
static T_3 F_20 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_4 ;
char V_32 = ' ' ;
int V_7 ;
V_7 = F_7 ( V_2 , V_13 , & V_4 ) ;
if ( V_7 )
return - V_28 ;
if ( V_4 & V_33 ) {
V_4 = ( V_33 << 1 ) - V_4 ;
V_32 = '-' ;
}
return sprintf ( V_21 , L_13 , V_32 ,
( V_4 >> V_34 ) ,
( V_4 & V_35 ) * 25 ) ;
}
static T_3 F_21 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_4 [ V_36 ] ;
int V_10 , V_37 , V_7 ;
V_7 = F_7 ( V_2 , V_14 , V_4 ) ;
if ( V_7 )
return - V_28 ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
if ( V_2 -> V_17 & ( V_38 << V_10 ) ) {
V_7 = sprintf ( V_21 , L_14 , V_10 ,
V_4 [ V_10 ] & V_39 ) ;
if ( V_7 < 0 )
break;
V_21 += V_7 ;
V_37 += V_7 ;
}
}
return V_37 ;
}
static T_3 F_22 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
return sprintf ( V_21 , L_15 , ( V_2 -> V_17 & V_40 ) >>
V_41 ) ;
}
static T_3 F_23 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_17 ;
unsigned long V_4 ;
int V_10 , V_7 ;
V_7 = F_24 ( V_21 , 16 , & V_4 ) ;
if ( V_7 || V_4 > 0xff )
return - V_16 ;
V_17 = V_2 -> V_17 & ( ~ V_40 ) ;
V_17 |= V_4 << V_41 ;
V_7 = F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_7 )
return - V_28 ;
V_2 -> V_17 = V_17 ;
for ( V_10 = 0 , V_2 -> V_15 = 0 ; V_10 < V_36 ; V_10 ++ ) {
if ( V_2 -> V_17 & ( V_38 << V_10 ) )
V_2 -> V_15 ++ ;
}
return V_7 ;
}
static T_5 F_25 ( int V_42 , void * V_43 )
{
struct V_22 * V_44 = V_43 ;
struct V_1 * V_2 = F_26 ( V_43 ) ;
T_2 V_45 , V_46 ;
T_2 V_17 ;
int V_10 ;
T_6 V_47 = F_27 () ;
if ( F_1 ( V_2 , V_48 , & V_45 ) )
return V_49 ;
if ( F_1 ( V_2 , V_50 , & V_46 ) )
return V_49 ;
if ( ! ( V_45 || V_46 ) )
return V_49 ;
V_17 = V_2 -> V_17 | V_51 ;
F_5 ( V_2 , V_27 , V_17 ) ;
V_17 = V_2 -> V_17 & ~ V_51 ;
F_5 ( V_2 , V_27 , V_17 ) ;
if ( V_45 & ( 1 << 0 ) )
F_28 ( V_44 , 0 ,
F_29 ( V_52 ,
0 ,
V_53 ,
V_54 ) ,
V_47 ) ;
if ( V_45 & ( 1 << 1 ) )
F_28 ( V_44 , 0 ,
F_29 ( V_52 ,
0 ,
V_53 ,
V_55 ) ,
V_47 ) ;
if ( V_45 & ( 1 << 2 ) )
F_28 ( V_44 , 0 ,
F_29 ( V_52 ,
0 ,
V_53 ,
V_54 ) ,
V_47 ) ;
if ( V_45 & ( 1 << 3 ) )
F_28 ( V_44 , 0 ,
F_29 ( V_52 ,
0 ,
V_53 ,
V_55 ) ,
V_47 ) ;
for ( V_10 = 0 ; V_10 < V_36 * 2 ; V_10 += 2 ) {
if ( V_46 & ( 1 << V_10 ) )
F_28 ( V_44 , 0 ,
F_29 ( V_56 ,
V_10 / 2 ,
V_53 ,
V_54 ) ,
V_47 ) ;
if ( V_46 & ( 1 << ( V_10 + 1 ) ) )
F_28 ( V_44 , 0 ,
F_29 ( V_56 ,
V_10 / 2 ,
V_53 ,
V_55 ) ,
V_47 ) ;
}
return V_49 ;
}
static inline T_3 F_30 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_57 * V_58 = F_31 ( V_20 ) ;
T_2 V_4 ;
char V_32 = ' ' ;
int V_7 ;
V_7 = F_1 ( V_2 , V_58 -> V_59 , & V_4 ) ;
if ( V_7 )
return - V_28 ;
V_4 &= V_39 ;
if ( V_4 & V_33 ) {
V_4 = ( V_33 << 1 ) - V_4 ;
V_32 = '-' ;
}
return sprintf ( V_21 , L_13 , V_32 ,
V_4 >> V_34 ,
( V_4 & V_35 ) * 25 ) ;
}
static inline T_3 F_32 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_57 * V_58 = F_31 ( V_20 ) ;
long V_60 , V_61 ;
T_2 V_4 ;
char * V_62 ;
int V_7 ;
V_62 = strchr ( V_21 , '.' ) ;
V_7 = F_33 ( V_21 , 10 , & V_60 ) ;
if ( V_7 || V_60 > 127 || V_60 < - 128 )
return - V_16 ;
if ( V_62 ) {
V_26 = strlen ( V_62 ) ;
if ( V_26 > V_34 )
V_26 = V_34 ;
V_62 [ V_26 ] = 0 ;
V_7 = F_33 ( V_62 , 10 , & V_61 ) ;
if ( ! V_7 )
V_61 = ( V_61 / 25 ) * 25 ;
}
if ( V_60 < 0 )
V_4 = ( T_2 ) ( - V_60 ) ;
else
V_4 = ( T_2 ) V_60 ;
V_4 = ( V_4 << V_34 ) |
( V_61 & V_35 ) ;
if ( V_60 < 0 )
V_4 = ( V_33 << 1 ) - V_4 ;
V_7 = F_5 ( V_2 , V_58 -> V_59 , V_4 ) ;
if ( V_7 )
return - V_28 ;
return V_7 ;
}
static inline T_3 F_34 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
T_1 V_63 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_4 ;
int V_7 ;
if ( V_63 < V_64 ||
V_63 >= V_64 +
V_36 )
return - V_16 ;
V_7 = F_1 ( V_2 , V_63 , & V_4 ) ;
if ( V_7 )
return - V_28 ;
V_4 &= V_39 ;
return sprintf ( V_21 , L_11 , V_4 ) ;
}
static inline T_3 F_35 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
T_1 V_63 ,
const char * V_21 ,
T_4 V_26 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_65 ;
T_2 V_4 ;
int V_7 ;
if ( V_63 < V_64 ||
V_63 >= V_64 +
V_36 )
return - V_16 ;
V_7 = F_24 ( V_21 , 10 , & V_65 ) ;
if ( V_7 || V_65 >= 4096 )
return - V_16 ;
V_4 = ( T_2 ) V_65 ;
V_7 = F_5 ( V_2 , V_63 , V_4 ) ;
if ( V_7 )
return - V_28 ;
return V_7 ;
}
static int T_7 F_36 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_68 ) ;
if ( V_2 == NULL )
return - V_69 ;
F_38 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_31 | V_38 ;
V_2 -> V_44 = F_39 ( 0 ) ;
if ( V_2 -> V_44 == NULL ) {
V_7 = - V_69 ;
goto V_70;
}
V_2 -> V_44 -> V_71 = V_67 -> V_71 ;
V_2 -> V_44 -> V_8 . V_72 = & V_6 -> V_8 ;
V_2 -> V_44 -> V_73 = & V_74 ;
V_2 -> V_44 -> V_24 = ( void * ) V_2 ;
V_2 -> V_44 -> V_75 = V_76 ;
V_7 = F_40 ( V_2 -> V_44 ) ;
if ( V_7 )
goto V_77;
if ( V_6 -> V_42 > 0 ) {
V_7 = F_41 ( V_6 -> V_42 ,
NULL ,
& F_25 ,
V_78 | V_79 ,
V_67 -> V_71 ,
V_2 -> V_44 ) ;
if ( V_7 )
goto V_80;
V_2 -> V_17 |= V_81 ;
}
V_7 = F_5 ( V_2 , V_27 , V_2 -> V_17 ) ;
if ( V_7 ) {
V_7 = - V_28 ;
goto V_82;
}
V_23 ( & V_6 -> V_8 , L_16 ,
V_67 -> V_71 ) ;
return 0 ;
V_82:
F_42 ( V_6 -> V_42 , V_2 -> V_44 ) ;
V_80:
F_43 ( V_2 -> V_44 ) ;
V_77:
F_44 ( V_2 -> V_44 ) ;
V_70:
F_45 ( V_2 ) ;
return V_7 ;
}
static int T_8 F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_47 ( V_6 ) ;
struct V_22 * V_44 = V_2 -> V_44 ;
if ( V_6 -> V_42 )
F_42 ( V_6 -> V_42 , V_2 -> V_44 ) ;
F_43 ( V_44 ) ;
F_44 ( V_2 -> V_44 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static T_9 int F_48 ( void )
{
return F_49 ( & V_83 ) ;
}
static T_10 void F_50 ( void )
{
F_51 ( & V_83 ) ;
}
