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
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_2 -> V_17 & V_24 )
return sprintf ( V_21 , L_7 ) ;
else
return sprintf ( V_21 , L_8 ) ;
}
static T_3 F_13 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_24 ) ;
if ( strcmp ( V_21 , L_9 ) )
V_17 |= V_24 ;
V_7 = F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_7 )
return - V_27 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_14 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
return sprintf ( V_21 , L_10 ) ;
}
static T_3 F_15 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 | V_28 ;
V_7 = F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_7 )
return - V_27 ;
return V_7 ;
}
static T_3 F_16 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
return sprintf ( V_21 , L_11 , ! ! ( V_2 -> V_17 & V_29 ) ) ;
}
static T_3 F_17 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_29 ) ;
if ( strcmp ( V_21 , L_12 ) )
V_17 |= V_29 ;
V_7 = F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_7 )
return - V_27 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_18 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
return sprintf ( V_21 , L_11 , ! ! ( V_2 -> V_17 & V_30 ) ) ;
}
static T_3 F_19 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_17 ;
int V_7 ;
V_17 = V_2 -> V_17 & ( ~ V_30 ) ;
if ( strcmp ( V_21 , L_12 ) )
V_17 |= V_30 ;
V_7 = F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_7 )
return - V_27 ;
V_2 -> V_17 = V_17 ;
return V_7 ;
}
static T_3 F_20 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_4 ;
char V_31 = ' ' ;
int V_7 ;
V_7 = F_7 ( V_2 , V_12 , & V_4 ) ;
if ( V_7 )
return - V_27 ;
if ( V_4 & V_32 ) {
V_4 = ( V_32 << 1 ) - V_4 ;
V_31 = '-' ;
}
return sprintf ( V_21 , L_13 , V_31 ,
( V_4 >> V_33 ) ,
( V_4 & V_34 ) * 25 ) ;
}
static T_3 F_21 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_4 ;
char V_31 = ' ' ;
int V_7 ;
V_7 = F_7 ( V_2 , V_13 , & V_4 ) ;
if ( V_7 )
return - V_27 ;
if ( V_4 & V_32 ) {
V_4 = ( V_32 << 1 ) - V_4 ;
V_31 = '-' ;
}
return sprintf ( V_21 , L_13 , V_31 ,
( V_4 >> V_33 ) ,
( V_4 & V_34 ) * 25 ) ;
}
static T_3 F_22 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_4 [ V_35 ] ;
int V_10 , V_36 , V_7 ;
V_7 = F_7 ( V_2 , V_14 , V_4 ) ;
if ( V_7 )
return - V_27 ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ ) {
if ( V_2 -> V_17 & ( V_37 << V_10 ) ) {
V_7 = sprintf ( V_21 , L_14 , V_10 ,
V_4 [ V_10 ] & V_38 ) ;
if ( V_7 < 0 )
break;
V_21 += V_7 ;
V_36 += V_7 ;
}
}
return V_36 ;
}
static T_3 F_23 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
return sprintf ( V_21 , L_15 , ( V_2 -> V_17 & V_39 ) >>
V_40 ) ;
}
static T_3 F_24 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_17 ;
unsigned long V_4 ;
int V_10 , V_7 ;
V_7 = F_25 ( V_21 , 16 , & V_4 ) ;
if ( V_7 || V_4 > 0xff )
return - V_16 ;
V_17 = V_2 -> V_17 & ( ~ V_39 ) ;
V_17 |= V_4 << V_40 ;
V_7 = F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_7 )
return - V_27 ;
V_2 -> V_17 = V_17 ;
for ( V_10 = 0 , V_2 -> V_15 = 0 ; V_10 < V_35 ; V_10 ++ ) {
if ( V_2 -> V_17 & ( V_37 << V_10 ) )
V_2 -> V_15 ++ ;
}
return V_7 ;
}
static T_5 F_26 ( int V_41 , void * V_42 )
{
struct V_22 * V_43 = V_42 ;
struct V_1 * V_2 = F_12 ( V_42 ) ;
T_2 V_44 , V_45 ;
T_2 V_17 ;
int V_10 ;
T_6 V_46 = F_27 () ;
if ( F_1 ( V_2 , V_47 , & V_44 ) )
return V_48 ;
if ( F_1 ( V_2 , V_49 , & V_45 ) )
return V_48 ;
if ( ! ( V_44 || V_45 ) )
return V_48 ;
V_17 = V_2 -> V_17 | V_50 ;
F_5 ( V_2 , V_26 , V_17 ) ;
V_17 = V_2 -> V_17 & ~ V_50 ;
F_5 ( V_2 , V_26 , V_17 ) ;
if ( V_44 & ( 1 << 0 ) )
F_28 ( V_43 , 0 ,
F_29 ( V_51 ,
0 ,
V_52 ,
V_53 ) ,
V_46 ) ;
if ( V_44 & ( 1 << 1 ) )
F_28 ( V_43 , 0 ,
F_29 ( V_51 ,
0 ,
V_52 ,
V_54 ) ,
V_46 ) ;
if ( V_44 & ( 1 << 2 ) )
F_28 ( V_43 , 0 ,
F_29 ( V_51 ,
0 ,
V_52 ,
V_53 ) ,
V_46 ) ;
if ( V_44 & ( 1 << 3 ) )
F_28 ( V_43 , 0 ,
F_29 ( V_51 ,
0 ,
V_52 ,
V_54 ) ,
V_46 ) ;
for ( V_10 = 0 ; V_10 < V_35 * 2 ; V_10 += 2 ) {
if ( V_45 & ( 1 << V_10 ) )
F_28 ( V_43 , 0 ,
F_29 ( V_55 ,
V_10 / 2 ,
V_52 ,
V_53 ) ,
V_46 ) ;
if ( V_45 & ( 1 << ( V_10 + 1 ) ) )
F_28 ( V_43 , 0 ,
F_29 ( V_55 ,
V_10 / 2 ,
V_52 ,
V_54 ) ,
V_46 ) ;
}
return V_48 ;
}
static inline T_3 F_30 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_56 * V_57 = F_31 ( V_20 ) ;
T_2 V_4 ;
char V_31 = ' ' ;
int V_7 ;
V_7 = F_1 ( V_2 , V_57 -> V_58 , & V_4 ) ;
if ( V_7 )
return - V_27 ;
V_4 &= V_38 ;
if ( V_4 & V_32 ) {
V_4 = ( V_32 << 1 ) - V_4 ;
V_31 = '-' ;
}
return sprintf ( V_21 , L_13 , V_31 ,
V_4 >> V_33 ,
( V_4 & V_34 ) * 25 ) ;
}
static inline T_3 F_32 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_56 * V_57 = F_31 ( V_20 ) ;
long V_59 , V_60 ;
T_2 V_4 ;
char * V_61 ;
int V_7 ;
V_61 = strchr ( V_21 , '.' ) ;
V_7 = F_33 ( V_21 , 10 , & V_59 ) ;
if ( V_7 || V_59 > 127 || V_59 < - 128 )
return - V_16 ;
if ( V_61 ) {
V_25 = strlen ( V_61 ) ;
if ( V_25 > V_33 )
V_25 = V_33 ;
V_61 [ V_25 ] = 0 ;
V_7 = F_33 ( V_61 , 10 , & V_60 ) ;
if ( ! V_7 )
V_60 = ( V_60 / 25 ) * 25 ;
}
if ( V_59 < 0 )
V_4 = ( T_2 ) ( - V_59 ) ;
else
V_4 = ( T_2 ) V_59 ;
V_4 = ( V_4 << V_33 ) |
( V_60 & V_34 ) ;
if ( V_59 < 0 )
V_4 = ( V_32 << 1 ) - V_4 ;
V_7 = F_5 ( V_2 , V_57 -> V_58 , V_4 ) ;
if ( V_7 )
return - V_27 ;
return V_7 ;
}
static inline T_3 F_34 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
T_1 V_62 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_2 V_4 ;
int V_7 ;
if ( V_62 < V_63 ||
V_62 >= V_63 +
V_35 )
return - V_16 ;
V_7 = F_1 ( V_2 , V_62 , & V_4 ) ;
if ( V_7 )
return - V_27 ;
V_4 &= V_38 ;
return sprintf ( V_21 , L_11 , V_4 ) ;
}
static inline T_3 F_35 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
T_1 V_62 ,
const char * V_21 ,
T_4 V_25 )
{
struct V_22 * V_23 = F_11 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
unsigned long V_64 ;
T_2 V_4 ;
int V_7 ;
if ( V_62 < V_63 ||
V_62 >= V_63 +
V_35 )
return - V_16 ;
V_7 = F_25 ( V_21 , 10 , & V_64 ) ;
if ( V_7 || V_64 >= 4096 )
return - V_16 ;
V_4 = ( T_2 ) V_64 ;
V_7 = F_5 ( V_2 , V_62 , V_4 ) ;
if ( V_7 )
return - V_27 ;
return V_7 ;
}
static int T_7 F_36 ( struct V_5 * V_6 ,
const struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_22 * V_43 ;
int V_7 = 0 ;
V_43 = F_37 ( sizeof( * V_2 ) ) ;
if ( V_43 == NULL ) {
V_7 = - V_67 ;
goto V_68;
}
V_2 = F_12 ( V_43 ) ;
F_38 ( V_6 , V_43 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_30 | V_37 ;
V_43 -> V_69 = V_66 -> V_69 ;
V_43 -> V_8 . V_70 = & V_6 -> V_8 ;
V_43 -> V_71 = & V_72 ;
V_43 -> V_73 = V_74 ;
V_7 = F_39 ( V_43 ) ;
if ( V_7 )
goto V_75;
if ( V_6 -> V_41 > 0 ) {
V_7 = F_40 ( V_6 -> V_41 ,
NULL ,
& F_26 ,
V_76 | V_77 ,
V_66 -> V_69 ,
V_43 ) ;
if ( V_7 )
goto V_78;
V_2 -> V_17 |= V_79 ;
}
V_7 = F_5 ( V_2 , V_26 , V_2 -> V_17 ) ;
if ( V_7 ) {
V_7 = - V_27 ;
goto V_80;
}
V_23 ( & V_6 -> V_8 , L_16 ,
V_66 -> V_69 ) ;
return 0 ;
V_80:
F_41 ( V_6 -> V_41 , V_43 ) ;
V_78:
F_42 ( V_43 ) ;
V_75:
F_43 ( V_43 ) ;
V_68:
return V_7 ;
}
static int T_8 F_44 ( struct V_5 * V_6 )
{
struct V_22 * V_43 = F_45 ( V_6 ) ;
if ( V_6 -> V_41 )
F_41 ( V_6 -> V_41 , V_43 ) ;
F_42 ( V_43 ) ;
F_43 ( V_43 ) ;
return 0 ;
}
static T_9 int F_46 ( void )
{
return F_47 ( & V_81 ) ;
}
static T_10 void F_48 ( void )
{
F_49 ( & V_81 ) ;
}
