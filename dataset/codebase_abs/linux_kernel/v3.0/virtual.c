static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 && V_4 -> V_7
&& V_4 -> V_6 <= V_4 -> V_7 ) {
F_2 ( V_2 , L_1 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_5 = F_3 ( V_4 -> V_8 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
if ( V_5 != 0 ) {
F_4 ( V_2 ,
L_2 , V_5 ) ;
return;
}
}
if ( V_4 -> V_6 && V_4 -> V_7 && ! V_4 -> V_9 ) {
F_2 ( V_2 , L_3 ) ;
V_5 = F_5 ( V_4 -> V_8 ) ;
if ( V_5 == 0 )
V_4 -> V_9 = true ;
else
F_4 ( V_2 , L_4 ,
V_5 ) ;
}
if ( ! ( V_4 -> V_6 && V_4 -> V_7 ) && V_4 -> V_9 ) {
F_2 ( V_2 , L_5 ) ;
V_5 = F_6 ( V_4 -> V_8 ) ;
if ( V_5 == 0 )
V_4 -> V_9 = false ;
else
F_4 ( V_2 , L_6 ,
V_5 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_10
&& V_4 -> V_11 <= V_4 -> V_10 ) {
F_2 ( V_2 , L_7 ,
V_4 -> V_11 , V_4 -> V_10 ) ;
V_5 = F_8 ( V_4 -> V_8 ,
V_4 -> V_11 , V_4 -> V_10 ) ;
if ( V_5 != 0 ) {
F_4 ( V_2 ,
L_8 ,
V_5 ) ;
return;
}
}
if ( V_4 -> V_10 && ! V_4 -> V_9 ) {
F_2 ( V_2 , L_3 ) ;
V_5 = F_5 ( V_4 -> V_8 ) ;
if ( V_5 == 0 )
V_4 -> V_9 = true ;
else
F_4 ( V_2 , L_4 ,
V_5 ) ;
}
if ( ! ( V_4 -> V_11 && V_4 -> V_10 ) && V_4 -> V_9 ) {
F_2 ( V_2 , L_5 ) ;
V_5 = F_6 ( V_4 -> V_8 ) ;
if ( V_5 == 0 )
V_4 -> V_9 = false ;
else
F_4 ( V_2 , L_6 ,
V_5 ) ;
}
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
return sprintf ( V_14 , L_9 , V_4 -> V_6 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
long V_16 ;
if ( F_12 ( V_14 , 10 , & V_16 ) != 0 )
return V_15 ;
F_13 ( & V_4 -> V_17 ) ;
V_4 -> V_6 = V_16 ;
F_1 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
return sprintf ( V_14 , L_9 , V_4 -> V_7 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
long V_16 ;
if ( F_12 ( V_14 , 10 , & V_16 ) != 0 )
return V_15 ;
F_13 ( & V_4 -> V_17 ) ;
V_4 -> V_7 = V_16 ;
F_1 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
return sprintf ( V_14 , L_9 , V_4 -> V_11 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
long V_16 ;
if ( F_12 ( V_14 , 10 , & V_16 ) != 0 )
return V_15 ;
F_13 ( & V_4 -> V_17 ) ;
V_4 -> V_11 = V_16 ;
F_7 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
return sprintf ( V_14 , L_9 , V_4 -> V_10 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
long V_16 ;
if ( F_12 ( V_14 , 10 , & V_16 ) != 0 )
return V_15 ;
F_13 ( & V_4 -> V_17 ) ;
V_4 -> V_10 = V_16 ;
F_7 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
return sprintf ( V_14 , L_10 ) ;
case V_20 :
return sprintf ( V_14 , L_11 ) ;
case V_21 :
return sprintf ( V_14 , L_12 ) ;
case V_22 :
return sprintf ( V_14 , L_13 ) ;
default:
return sprintf ( V_14 , L_14 ) ;
}
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_3 * V_4 = F_10 ( V_2 ) ;
unsigned int V_18 ;
int V_5 ;
if ( F_23 ( V_14 , L_10 ) )
V_18 = V_19 ;
else if ( F_23 ( V_14 , L_11 ) )
V_18 = V_20 ;
else if ( F_23 ( V_14 , L_12 ) )
V_18 = V_21 ;
else if ( F_23 ( V_14 , L_13 ) )
V_18 = V_22 ;
else {
F_4 ( V_2 , L_15 ) ;
return V_15 ;
}
F_13 ( & V_4 -> V_17 ) ;
V_5 = F_24 ( V_4 -> V_8 , V_18 ) ;
if ( V_5 == 0 )
V_4 -> V_18 = V_18 ;
else
F_4 ( V_2 , L_16 , V_5 ) ;
F_14 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static int T_3 F_25 ( struct V_23 * V_24 )
{
char * V_25 = V_24 -> V_2 . V_26 ;
struct V_3 * V_27 ;
int V_5 ;
V_27 = F_26 ( sizeof( struct V_3 ) , V_28 ) ;
if ( V_27 == NULL )
return - V_29 ;
F_27 ( & V_27 -> V_17 ) ;
V_27 -> V_8 = F_28 ( & V_24 -> V_2 , V_25 ) ;
if ( F_29 ( V_27 -> V_8 ) ) {
V_5 = F_30 ( V_27 -> V_8 ) ;
F_4 ( & V_24 -> V_2 , L_17 ,
V_25 , V_5 ) ;
goto V_30;
}
V_5 = F_31 ( & V_24 -> V_2 . V_31 ,
& V_32 ) ;
if ( V_5 != 0 ) {
F_4 ( & V_24 -> V_2 ,
L_18 , V_5 ) ;
goto V_33;
}
V_27 -> V_18 = F_32 ( V_27 -> V_8 ) ;
F_33 ( V_24 , V_27 ) ;
return 0 ;
V_33:
F_34 ( V_27 -> V_8 ) ;
V_30:
F_35 ( V_27 ) ;
return V_5 ;
}
static int T_4 F_36 ( struct V_23 * V_24 )
{
struct V_3 * V_27 = F_37 ( V_24 ) ;
F_38 ( & V_24 -> V_2 . V_31 , & V_32 ) ;
if ( V_27 -> V_9 )
F_6 ( V_27 -> V_8 ) ;
F_34 ( V_27 -> V_8 ) ;
F_35 ( V_27 ) ;
F_33 ( V_24 , NULL ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_34 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_34 ) ;
}
