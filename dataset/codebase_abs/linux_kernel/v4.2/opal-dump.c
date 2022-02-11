static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_1 , V_1 -> V_5 ) ;
}
static const char * F_2 ( T_2 type )
{
switch ( type ) {
case 0x01 : return L_2 ;
case 0x02 : return L_3 ;
case 0x03 : return L_4 ;
default: return L_5 ;
}
}
static T_1 F_3 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_6 , V_1 -> type ,
F_2 ( V_1 -> type ) ) ;
}
static T_1 F_4 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_7 ) ;
}
static T_3 F_5 ( T_2 V_6 )
{
int V_7 ;
V_7 = F_6 ( V_6 ) ;
if ( V_7 )
F_7 ( L_8 ,
V_8 , V_6 , V_7 ) ;
return V_7 ;
}
static T_1 F_8 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_4 V_9 )
{
F_5 ( V_1 -> V_5 ) ;
F_9 ( & V_1 -> V_10 , & V_3 -> V_3 ) ;
F_10 ( & V_1 -> V_10 ) ;
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_9 ) ;
}
static T_3 F_12 ( T_5 type )
{
int V_7 ;
V_7 = F_13 ( type ) ;
if ( V_7 )
F_7 ( L_10 ,
V_8 , V_7 ) ;
return V_7 ;
}
static T_1 F_14 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_4 V_9 )
{
int V_7 ;
V_7 = F_12 ( V_11 ) ;
if ( V_7 == V_12 )
F_15 ( L_11 , V_8 ) ;
return V_9 ;
}
static T_1 F_16 ( struct V_13 * V_10 ,
struct V_14 * V_3 ,
char * V_4 )
{
struct V_2 * V_14 ;
struct V_1 * V_15 ;
V_14 = F_17 ( V_3 ) ;
V_15 = F_18 ( V_10 ) ;
if ( ! V_14 -> V_16 )
return - V_17 ;
return V_14 -> V_16 ( V_15 , V_14 , V_4 ) ;
}
static T_1 F_19 ( struct V_13 * V_10 ,
struct V_14 * V_3 ,
const char * V_4 , T_4 V_18 )
{
struct V_2 * V_14 ;
struct V_1 * V_15 ;
V_14 = F_17 ( V_3 ) ;
V_15 = F_18 ( V_10 ) ;
if ( ! V_14 -> V_19 )
return - V_17 ;
return V_14 -> V_19 ( V_15 , V_14 , V_4 , V_18 ) ;
}
static void F_20 ( struct V_13 * V_10 )
{
struct V_1 * V_15 ;
V_15 = F_18 ( V_10 ) ;
F_21 ( V_15 -> V_20 ) ;
F_22 ( V_15 ) ;
}
static T_3 F_23 ( T_2 * V_6 , T_2 * V_21 , T_2 * V_22 )
{
T_6 V_5 , V_23 , type ;
int V_7 ;
type = F_24 ( 0xffffffff ) ;
V_7 = F_25 ( & V_5 , & V_23 , & type ) ;
if ( V_7 == V_24 )
V_7 = F_26 ( & V_5 , & V_23 ) ;
* V_6 = F_27 ( V_5 ) ;
* V_21 = F_27 ( V_23 ) ;
* V_22 = F_27 ( type ) ;
if ( V_7 )
F_7 ( L_12 ,
V_8 , V_7 ) ;
return V_7 ;
}
static T_3 F_28 ( struct V_1 * V_15 )
{
struct V_25 * V_26 ;
T_7 V_27 ;
T_3 V_7 ;
V_15 -> V_20 = F_29 ( F_30 ( V_15 -> V_23 ) ) ;
if ( ! V_15 -> V_20 ) {
F_31 ( L_13 , V_8 ) ;
V_7 = - V_28 ;
goto V_29;
}
V_26 = F_32 ( V_15 -> V_20 , V_15 -> V_23 ) ;
if ( ! V_26 ) {
V_7 = - V_28 ;
goto V_29;
}
V_27 = F_33 ( V_26 ) ;
V_7 = V_30 ;
while ( V_7 == V_31 || V_7 == V_30 ) {
V_7 = F_34 ( V_15 -> V_5 , V_27 ) ;
if ( V_7 == V_30 ) {
F_35 ( NULL ) ;
F_36 ( 20 ) ;
}
}
if ( V_7 != V_12 && V_7 != V_32 )
F_7 ( L_14 ,
V_8 , V_15 -> V_5 ) ;
F_37 ( V_26 ) ;
V_29:
return V_7 ;
}
static T_1 F_38 ( struct V_33 * V_34 , struct V_13 * V_10 ,
struct V_35 * V_36 ,
char * V_20 , T_8 V_37 , T_4 V_9 )
{
T_1 V_7 ;
struct V_1 * V_15 = F_18 ( V_10 ) ;
if ( ! V_15 -> V_20 ) {
V_7 = F_28 ( V_15 ) ;
if ( V_7 != V_12 && V_7 != V_32 ) {
F_21 ( V_15 -> V_20 ) ;
V_15 -> V_20 = NULL ;
return - V_17 ;
}
if ( V_7 == V_32 ) {
F_15 ( L_15 ,
V_8 , V_15 -> V_5 ) ;
return - V_17 ;
}
}
memcpy ( V_20 , V_15 -> V_20 + V_37 , V_9 ) ;
return V_9 ;
}
static struct V_1 * F_39 ( T_2 V_5 , T_4 V_23 ,
T_2 type )
{
struct V_1 * V_15 ;
int V_7 ;
V_15 = F_40 ( sizeof( * V_15 ) , V_38 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_10 . V_39 = V_40 ;
F_41 ( & V_15 -> V_10 , & V_41 ) ;
F_42 ( & V_15 -> V_42 ) ;
V_15 -> V_42 . V_3 . V_43 = L_16 ;
V_15 -> V_42 . V_3 . V_44 = 0400 ;
V_15 -> V_42 . V_23 = V_23 ;
V_15 -> V_42 . V_45 = F_38 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_23 = V_23 ;
V_15 -> type = type ;
V_7 = F_43 ( & V_15 -> V_10 , NULL , L_17 , type , V_5 ) ;
if ( V_7 ) {
F_10 ( & V_15 -> V_10 ) ;
return NULL ;
}
V_7 = F_44 ( & V_15 -> V_10 , & V_15 -> V_42 ) ;
if ( V_7 ) {
F_10 ( & V_15 -> V_10 ) ;
return NULL ;
}
F_15 ( L_18 ,
V_8 , V_15 -> V_5 , V_15 -> V_23 ) ;
F_45 ( & V_15 -> V_10 , V_46 ) ;
return V_15 ;
}
static T_9 F_46 ( int V_47 , void * V_48 )
{
int V_7 ;
T_2 V_6 , V_21 , V_22 ;
struct V_1 * V_15 ;
char V_43 [ 22 ] ;
V_7 = F_23 ( & V_6 , & V_21 , & V_22 ) ;
if ( V_7 != V_12 )
return V_7 ;
sprintf ( V_43 , L_17 , V_22 , V_6 ) ;
if ( F_47 ( V_40 , V_43 ) )
return 0 ;
V_15 = F_39 ( V_6 , V_21 , V_22 ) ;
if ( ! V_15 )
return - 1 ;
return V_49 ;
}
void T_10 F_48 ( void )
{
int V_7 ;
int V_50 ;
if ( ! F_49 ( V_51 ) )
return;
V_40 = F_50 ( L_16 , NULL , V_52 ) ;
if ( ! V_40 ) {
F_7 ( L_19 , V_8 ) ;
return;
}
V_7 = F_51 ( & V_40 -> V_10 , & V_53 ) ;
if ( V_7 ) {
F_7 ( L_20 ,
V_8 ) ;
F_10 ( & V_40 -> V_10 ) ;
return;
}
V_50 = F_52 ( F_53 ( V_54 ) ) ;
if ( ! V_50 ) {
F_31 ( L_21 ,
V_8 , V_50 ) ;
return;
}
V_7 = F_54 ( V_50 , NULL , F_46 ,
V_55 | V_56 ,
L_22 , NULL ) ;
if ( V_7 ) {
F_31 ( L_23 ,
V_8 , V_7 ) ;
return;
}
if ( F_49 ( V_57 ) )
F_55 () ;
}
