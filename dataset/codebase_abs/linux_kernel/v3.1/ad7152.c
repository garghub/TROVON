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
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_21 , V_4 , 2 ) ;
return sprintf ( V_14 , L_5 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_10 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_4 [ 2 ] ;
F_1 ( V_2 , V_22 , V_4 , 2 ) ;
return sprintf ( V_14 , L_5 , ( ( int ) V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ) ;
}
static T_2 F_11 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_6 , V_2 -> V_23 ) ;
}
static T_2 F_12 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_1 V_24 ;
int V_15 ;
F_1 ( V_2 , V_25 , & V_24 , 1 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( strncmp ( V_14 , V_17 [ V_15 ] . V_18 ,
strlen ( V_17 [ V_15 ] . V_18 ) - 1 ) == 0 ) {
V_2 -> V_23 = V_17 [ V_15 ] . V_18 ;
V_24 |= 0x18 | V_17 [ V_15 ] . V_26 ;
F_5 ( V_2 , V_25 , V_24 ) ;
return V_5 ;
}
F_3 ( V_9 , L_7 ) ;
return - V_27 ;
}
static T_2 F_13 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_5 , V_2 -> V_28 ) ;
}
static T_2 F_14 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_29 , V_4 >> 8 ) ;
F_5 ( V_2 , V_30 , V_4 ) ;
V_2 -> V_28 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_16 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_5 , V_2 -> V_31 ) ;
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
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_32 , V_4 >> 8 ) ;
F_5 ( V_2 , V_33 , V_4 ) ;
V_2 -> V_31 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_18 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_5 , V_2 -> V_34 ) ;
}
static T_2 F_19 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_35 , V_4 >> 8 ) ;
F_5 ( V_2 , V_36 , V_4 ) ;
V_2 -> V_34 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_20 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_5 , V_2 -> V_37 ) ;
}
static T_2 F_21 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x10000 ) ) {
F_5 ( V_2 , V_38 , V_4 >> 8 ) ;
F_5 ( V_2 , V_39 , V_4 ) ;
V_2 -> V_37 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_22 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_8 , V_2 -> V_40 ) ;
}
static T_2 F_23 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_41 , V_4 ) ;
V_2 -> V_40 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_24 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_8 , V_2 -> V_42 ) ;
}
static T_2 F_25 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_43 , V_4 ) ;
V_2 -> V_42 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static T_2 F_26 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
return sprintf ( V_14 , L_8 , V_2 -> V_44 ) ;
}
static T_2 F_27 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_3 V_5 )
{
struct V_19 * V_20 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
unsigned long V_4 ;
int V_8 ;
V_8 = F_15 ( V_14 , 10 , & V_4 ) ;
if ( ( ! V_8 ) && ( V_4 < 0x100 ) ) {
F_5 ( V_2 , V_45 , V_4 ) ;
V_2 -> V_44 = V_4 ;
return V_5 ;
}
return - V_27 ;
}
static int T_4 F_28 ( struct V_6 * V_7 ,
const struct V_46 * V_47 )
{
int V_8 = 0 ;
struct V_1 * V_2 ;
struct V_19 * V_48 ;
V_48 = F_29 ( sizeof( * V_2 ) ) ;
if ( V_48 == NULL ) {
V_8 = - V_49 ;
goto V_50;
}
V_2 = F_9 ( V_48 ) ;
F_30 ( V_7 , V_48 ) ;
V_2 -> V_7 = V_7 ;
V_48 -> V_18 = V_47 -> V_18 ;
V_48 -> V_9 . V_51 = & V_7 -> V_9 ;
V_48 -> V_52 = & V_53 ;
V_48 -> V_54 = V_55 ;
V_8 = F_31 ( V_48 ) ;
if ( V_8 )
goto V_56;
F_3 ( & V_7 -> V_9 , L_9 , V_47 -> V_18 ) ;
return 0 ;
V_56:
F_32 ( V_48 ) ;
V_50:
return V_8 ;
}
static int T_5 F_33 ( struct V_6 * V_7 )
{
struct V_19 * V_48 = F_34 ( V_7 ) ;
F_35 ( V_48 ) ;
return 0 ;
}
static T_6 int F_36 ( void )
{
return F_37 ( & V_57 ) ;
}
static T_7 void F_38 ( void )
{
F_39 ( & V_57 ) ;
}
