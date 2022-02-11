static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
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
int V_8 ;
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
V_5 += sprintf ( V_14 + V_5 , L_4 ) ;
return V_5 ;
}
static T_2 F_7 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_5 , V_2 -> V_22 ) ;
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
F_3 ( V_9 , L_6 ) ;
return - V_26 ;
}
static T_2 F_10 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_27 * V_28 = F_11 ( V_13 ) ;
T_1 V_4 ;
F_1 ( V_2 , V_28 -> V_29 , & V_4 , 1 ) ;
return sprintf ( V_14 , L_7 , V_4 & 0x7F ) ;
}
static T_2 F_12 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_27 * V_28 = F_11 ( V_13 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ! V_8 ) {
F_5 ( V_2 , V_28 -> V_29 ,
( V_4 ? V_30 : 0 ) | ( V_4 & 0x7F ) ) ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_14 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_8 , V_2 -> V_31 ) ;
}
static T_2 F_15 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_32 , V_4 ) ;
V_2 -> V_31 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_2 F_16 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_8 , V_2 -> V_33 ) ;
}
static T_2 F_17 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_34 , V_4 ) ;
V_2 -> V_33 = V_4 ;
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
return sprintf ( V_14 , L_8 , V_2 -> V_35 ) ;
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
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_36 , V_4 ) ;
V_2 -> V_35 = V_4 ;
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
return sprintf ( V_14 , L_9 , V_2 -> V_37 ) ;
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
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_38 , V_4 >> 8 ) ;
F_5 ( V_2 , V_39 , V_4 ) ;
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
unsigned long V_4 ;
char V_40 [ 3 ] ;
F_1 ( V_2 , V_41 , V_40 , 3 ) ;
V_4 = ( ( int ) V_40 [ 0 ] << 16 ) | ( ( int ) V_40 [ 1 ] << 8 ) | ( int ) V_40 [ 2 ] ;
return sprintf ( V_14 , L_10 , V_4 ) ;
}
static T_2 F_23 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_4 ;
char V_40 [ 3 ] ;
F_1 ( V_2 , V_42 , V_40 , 3 ) ;
V_4 = ( ( int ) V_40 [ 0 ] << 16 ) | ( ( int ) V_40 [ 1 ] << 8 ) | ( int ) V_40 [ 2 ] ;
return sprintf ( V_14 , L_10 , V_4 ) ;
}
static T_2 F_24 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_14 , L_9 , V_2 -> V_43 ) ;
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
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_44 , V_4 >> 8 ) ;
F_5 ( V_2 , V_45 , V_4 ) ;
V_2 -> V_43 = V_4 ;
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
return sprintf ( V_14 , L_9 , V_2 -> V_46 ) ;
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
V_8 = F_13 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_47 , V_4 >> 8 ) ;
F_5 ( V_2 , V_48 , V_4 ) ;
V_2 -> V_46 = V_4 ;
return V_5 ;
}
return - V_26 ;
}
static T_4 F_28 ( int V_49 , void * V_50 )
{
struct V_19 * V_51 = V_50 ;
struct V_1 * V_2 = F_29 ( V_51 ) ;
T_1 V_52 ;
F_1 ( V_2 , V_53 , & V_52 , 1 ) ;
if ( V_52 & V_54 )
F_30 ( V_51 , 0 ,
V_55 ,
F_31 () ) ;
if ( V_52 & V_56 )
F_30 ( V_51 , 0 ,
V_57 ,
F_31 () ) ;
return V_58 ;
}
static int T_5 F_32 ( struct V_6 * V_7 ,
const struct V_59 * V_60 )
{
int V_8 = 0 , V_61 = 0 ;
struct V_1 * V_2 = F_33 ( sizeof( * V_2 ) , V_62 ) ;
if ( V_2 == NULL ) {
V_8 = - V_63 ;
goto V_64;
}
F_34 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_51 = F_35 ( 0 ) ;
if ( V_2 -> V_51 == NULL ) {
V_8 = - V_63 ;
goto V_65;
}
V_2 -> V_51 -> V_18 = V_60 -> V_18 ;
V_2 -> V_51 -> V_9 . V_66 = & V_7 -> V_9 ;
V_2 -> V_51 -> V_67 = & V_68 ;
V_2 -> V_51 -> V_21 = ( void * ) ( V_2 ) ;
V_2 -> V_51 -> V_69 = V_70 ;
V_8 = F_36 ( V_2 -> V_51 ) ;
if ( V_8 )
goto V_71;
V_61 = 1 ;
if ( V_7 -> V_49 ) {
V_8 = F_37 ( V_7 -> V_49 ,
NULL ,
& F_28 ,
V_72 ,
L_11 ,
V_2 -> V_51 ) ;
if ( V_8 )
goto V_71;
}
F_3 ( & V_7 -> V_9 , L_12 , V_60 -> V_18 , V_7 -> V_49 ) ;
return 0 ;
V_71:
if ( V_61 )
F_38 ( V_7 -> V_49 , V_2 -> V_51 ) ;
else
F_39 ( V_2 -> V_51 ) ;
V_65:
F_40 ( V_2 ) ;
V_64:
return V_8 ;
}
static int T_6 F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
struct V_19 * V_51 = V_2 -> V_51 ;
if ( V_7 -> V_49 )
F_38 ( V_7 -> V_49 , V_51 ) ;
F_43 ( V_51 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static T_7 int F_44 ( void )
{
return F_45 ( & V_73 ) ;
}
static T_8 void F_46 ( void )
{
F_47 ( & V_73 ) ;
}
