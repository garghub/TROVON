static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
V_8 = F_2 ( V_7 , & V_3 , 1 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_7 -> V_9 , L_1 ) ;
return V_8 ;
}
V_8 = F_4 ( V_7 , V_4 , V_5 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_7 -> V_9 , L_2 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
T_1 V_10 [ 2 ] = {
V_3 ,
V_4 ,
} ;
V_8 = F_2 ( V_7 , V_10 , 2 ) ;
if ( V_8 < 0 )
F_3 ( & V_7 -> V_9 , L_1 ) ;
return V_8 ;
}
static T_2 F_6 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
int V_15 ;
int V_5 = 0 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
V_5 += sprintf ( V_14 + V_5 , L_3 , V_17 [ V_15 ] . V_18 ) ;
return V_5 ;
}
static T_2 F_7 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_3 , V_2 -> V_22 ) ;
}
static T_2 F_9 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_23 ;
int V_15 ;
F_1 ( V_2 , V_24 , & V_23 , 1 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( strncmp ( V_14 , V_17 [ V_15 ] . V_18 ,
strlen ( V_17 [ V_15 ] . V_18 ) - 1 ) == 0 ) {
V_2 -> V_22 = V_17 [ V_15 ] . V_18 ;
V_23 |= 0x18 | V_17 [ V_15 ] . V_25 ;
F_5 ( V_2 , V_24 , V_23 ) ;
return V_5 ;
}
}
F_3 ( V_9 , L_4 ) ;
return - V_26 ;
}
static T_2 F_10 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
return sprintf ( V_14 , L_5 ) ;
}
static T_2 F_11 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_27 , V_4 , 2 ) ;
return sprintf ( V_14 , L_6 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_12 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_28 , V_4 , 2 ) ;
return sprintf ( V_14 , L_6 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_13 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_3 , V_2 -> V_29 ) ;
}
static T_2 F_14 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_23 ;
F_1 ( V_2 , V_24 , & V_23 , 1 ) ;
if ( strncmp ( V_14 , L_7 , 5 ) == 0 ) {
strcpy ( V_2 -> V_29 , L_7 ) ;
V_23 |= V_30 ;
F_5 ( V_2 , V_24 , V_23 ) ;
return V_5 ;
} else if ( strncmp ( V_14 , L_8 , 8 ) == 0 ) {
strcpy ( V_2 -> V_29 , L_8 ) ;
V_23 &= ~ V_30 ;
F_5 ( V_2 , V_24 , V_23 ) ;
return V_5 ;
}
F_3 ( V_9 , L_9 ) ;
return - V_26 ;
}
static T_2 F_15 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_31 ) ;
}
static T_2 F_16 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_32 , V_4 >> 8 ) ;
F_5 ( V_2 , V_33 , V_4 ) ;
V_2 -> V_31 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_18 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_34 ) ;
}
static T_2 F_19 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_35 , V_4 >> 8 ) ;
F_5 ( V_2 , V_36 , V_4 ) ;
V_2 -> V_34 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_20 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_37 ) ;
}
static T_2 F_21 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_38 , V_4 ) ;
V_2 -> V_37 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_22 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_39 ) ;
}
static T_2 F_23 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_40 , V_4 ) ;
V_2 -> V_39 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_24 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_41 ) ;
}
static T_2 F_25 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_42 , V_4 ) ;
V_2 -> V_41 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_26 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_6 , V_2 -> V_43 ) ;
}
static T_2 F_27 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_44 , V_4 ) ;
V_2 -> V_43 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_28 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_10 , V_2 -> V_45 ) ;
}
static T_2 F_29 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_46 , V_4 ) ;
V_2 -> V_45 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_30 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_10 , V_2 -> V_47 ) ;
}
static T_2 F_31 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_48 , V_4 ) ;
V_2 -> V_47 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_32 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_10 , V_2 -> V_49 ) ;
}
static T_2 F_33 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_17 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x40 ) ) {
V_2 -> V_49 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_4 F_34 ( int V_50 , void * V_51 )
{
struct V_19 * V_52 = V_51 ;
struct V_1 * V_2 = F_35 ( V_52 ) ;
T_1 V_53 ;
T_5 V_54 = F_36 () ;
F_1 ( V_2 , V_55 , & V_53 , 1 ) ;
if ( ( V_53 & V_56 ) && ! ( V_2 -> V_57 & V_56 ) )
F_37 ( V_52 , 0 ,
F_38 ( V_58 ,
0 ,
V_59 ,
V_60 ) ,
V_54 ) ;
else if ( ( ! ( V_53 & V_56 ) ) && ( V_2 -> V_57 & V_56 ) )
F_37 ( V_52 , 0 ,
F_38 ( V_58 ,
0 ,
V_59 ,
V_61 ) ,
V_54 ) ;
if ( ( V_53 & V_62 ) && ! ( V_2 -> V_57 & V_62 ) )
F_37 ( V_52 , 0 ,
F_38 ( V_58 ,
1 ,
V_59 ,
V_60 ) ,
V_54 ) ;
else if ( ( ! ( V_53 & V_62 ) ) && ( V_2 -> V_57 & V_62 ) )
F_37 ( V_52 , 0 ,
F_38 ( V_58 ,
1 ,
V_59 ,
V_61 ) ,
V_54 ) ;
return V_63 ;
}
static int T_6 F_39 ( struct V_6 * V_7 ,
const struct V_64 * V_65 )
{
int V_8 = 0 , V_66 = 0 ;
struct V_1 * V_2 = F_40 ( sizeof( * V_2 ) , V_67 ) ;
if ( V_2 == NULL ) {
V_8 = - V_68 ;
goto V_69;
}
F_41 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_52 = F_42 ( 0 ) ;
if ( V_2 -> V_52 == NULL ) {
V_8 = - V_68 ;
goto V_70;
}
V_2 -> V_52 -> V_18 = V_65 -> V_18 ;
V_2 -> V_52 -> V_9 . V_71 = & V_7 -> V_9 ;
V_2 -> V_52 -> V_72 = & V_73 ;
V_2 -> V_52 -> V_21 = ( void * ) ( V_2 ) ;
V_2 -> V_52 -> V_74 = V_75 ;
V_8 = F_43 ( V_2 -> V_52 ) ;
if ( V_8 )
goto V_76;
V_66 = 1 ;
if ( V_7 -> V_50 ) {
V_8 = F_44 ( V_7 -> V_50 ,
NULL ,
& F_34 ,
V_77 |
V_78 ,
L_11 ,
V_2 -> V_52 ) ;
if ( V_8 )
goto V_76;
}
F_3 ( & V_7 -> V_9 , L_12 , V_65 -> V_18 , V_7 -> V_50 ) ;
return 0 ;
V_76:
if ( V_66 )
F_45 ( V_2 -> V_52 ) ;
else
F_46 ( V_2 -> V_52 ) ;
V_70:
F_47 ( V_2 ) ;
V_69:
return V_8 ;
}
static int T_7 F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_49 ( V_7 ) ;
struct V_19 * V_52 = V_2 -> V_52 ;
if ( V_7 -> V_50 )
F_50 ( V_7 -> V_50 , V_52 ) ;
F_45 ( V_52 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static T_8 int F_51 ( void )
{
return F_52 ( & V_79 ) ;
}
static T_9 void F_53 ( void )
{
F_54 ( & V_79 ) ;
}
