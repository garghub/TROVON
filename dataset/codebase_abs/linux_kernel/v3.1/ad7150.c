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
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_3 , V_2 -> V_21 ) ;
}
static T_2 F_10 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_22 ;
int V_15 ;
F_1 ( V_2 , V_23 , & V_22 , 1 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( strncmp ( V_14 , V_17 [ V_15 ] . V_18 ,
strlen ( V_17 [ V_15 ] . V_18 ) - 1 ) == 0 ) {
V_2 -> V_21 = V_17 [ V_15 ] . V_18 ;
V_22 |= 0x18 | V_17 [ V_15 ] . V_24 ;
F_5 ( V_2 , V_23 , V_22 ) ;
return V_5 ;
}
}
F_3 ( V_9 , L_4 ) ;
return - V_25 ;
}
static T_2 F_11 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
return sprintf ( V_14 , L_5 ) ;
}
static T_2 F_12 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_26 , V_4 , 2 ) ;
return sprintf ( V_14 , L_6 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_13 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_27 , V_4 , 2 ) ;
return sprintf ( V_14 , L_6 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_14 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_3 , V_2 -> V_28 ) ;
}
static T_2 F_15 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_22 ;
F_1 ( V_2 , V_23 , & V_22 , 1 ) ;
if ( strncmp ( V_14 , L_7 , 5 ) == 0 ) {
strcpy ( V_2 -> V_28 , L_7 ) ;
V_22 |= V_29 ;
F_5 ( V_2 , V_23 , V_22 ) ;
return V_5 ;
} else if ( strncmp ( V_14 , L_8 , 8 ) == 0 ) {
strcpy ( V_2 -> V_28 , L_8 ) ;
V_22 &= ~ V_29 ;
F_5 ( V_2 , V_23 , V_22 ) ;
return V_5 ;
}
F_3 ( V_9 , L_9 ) ;
return - V_25 ;
}
static T_2 F_16 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_30 ) ;
}
static T_2 F_17 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_31 , V_4 >> 8 ) ;
F_5 ( V_2 , V_32 , V_4 ) ;
V_2 -> V_30 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_19 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_33 ) ;
}
static T_2 F_20 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_34 , V_4 >> 8 ) ;
F_5 ( V_2 , V_35 , V_4 ) ;
V_2 -> V_33 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_21 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_36 ) ;
}
static T_2 F_22 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_37 , V_4 ) ;
V_2 -> V_36 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_23 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_38 ) ;
}
static T_2 F_24 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_39 , V_4 ) ;
V_2 -> V_38 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_25 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_40 ) ;
}
static T_2 F_26 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_41 , V_4 ) ;
V_2 -> V_40 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_27 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_42 ) ;
}
static T_2 F_28 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_43 , V_4 ) ;
V_2 -> V_42 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_29 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_10 , V_2 -> V_44 ) ;
}
static T_2 F_30 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_45 , V_4 ) ;
V_2 -> V_44 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_31 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_10 , V_2 -> V_46 ) ;
}
static T_2 F_32 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_47 , V_4 ) ;
V_2 -> V_46 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_2 F_33 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_10 , V_2 -> V_48 ) ;
}
static T_2 F_34 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_18 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x40 ) ) {
V_2 -> V_48 = V_4 ;
return V_5 ;
}
return - V_25 ;
}
static T_4 F_35 ( int V_49 , void * V_50 )
{
struct V_19 * V_51 = V_50 ;
struct V_1 * V_2 = F_9 ( V_51 ) ;
T_1 V_52 ;
T_5 V_53 = F_36 () ;
F_1 ( V_2 , V_54 , & V_52 , 1 ) ;
if ( ( V_52 & V_55 ) && ! ( V_2 -> V_56 & V_55 ) )
F_37 ( V_51 , 0 ,
F_38 ( V_57 ,
0 ,
V_58 ,
V_59 ) ,
V_53 ) ;
else if ( ( ! ( V_52 & V_55 ) ) && ( V_2 -> V_56 & V_55 ) )
F_37 ( V_51 , 0 ,
F_38 ( V_57 ,
0 ,
V_58 ,
V_60 ) ,
V_53 ) ;
if ( ( V_52 & V_61 ) && ! ( V_2 -> V_56 & V_61 ) )
F_37 ( V_51 , 0 ,
F_38 ( V_57 ,
1 ,
V_58 ,
V_59 ) ,
V_53 ) ;
else if ( ( ! ( V_52 & V_61 ) ) && ( V_2 -> V_56 & V_61 ) )
F_37 ( V_51 , 0 ,
F_38 ( V_57 ,
1 ,
V_58 ,
V_60 ) ,
V_53 ) ;
return V_62 ;
}
static int T_6 F_39 ( struct V_6 * V_7 ,
const struct V_63 * V_64 )
{
int V_8 = 0 , V_65 = 0 ;
struct V_1 * V_2 ;
struct V_19 * V_51 ;
V_51 = F_40 ( sizeof( * V_2 ) ) ;
if ( V_51 == NULL ) {
V_8 = - V_66 ;
goto V_67;
}
V_2 = F_9 ( V_51 ) ;
F_41 ( V_7 , V_51 ) ;
V_2 -> V_7 = V_7 ;
V_51 -> V_18 = V_64 -> V_18 ;
V_51 -> V_9 . V_68 = & V_7 -> V_9 ;
V_51 -> V_69 = & V_70 ;
V_51 -> V_71 = V_72 ;
V_8 = F_42 ( V_51 ) ;
if ( V_8 )
goto V_73;
V_65 = 1 ;
if ( V_7 -> V_49 ) {
V_8 = F_43 ( V_7 -> V_49 ,
NULL ,
& F_35 ,
V_74 |
V_75 ,
L_11 ,
V_51 ) ;
if ( V_8 )
goto V_73;
}
F_3 ( & V_7 -> V_9 , L_12 , V_64 -> V_18 , V_7 -> V_49 ) ;
return 0 ;
V_73:
if ( V_65 )
F_44 ( V_51 ) ;
else
F_45 ( V_51 ) ;
V_67:
return V_8 ;
}
static int T_7 F_46 ( struct V_6 * V_7 )
{
struct V_19 * V_51 = F_47 ( V_7 ) ;
if ( V_7 -> V_49 )
F_48 ( V_7 -> V_49 , V_51 ) ;
F_44 ( V_51 ) ;
return 0 ;
}
static T_8 int F_49 ( void )
{
return F_50 ( & V_76 ) ;
}
static T_9 void F_51 ( void )
{
F_52 ( & V_76 ) ;
}
