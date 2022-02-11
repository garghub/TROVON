static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_1 , V_1 -> V_5 ) ;
}
static const char * F_2 ( T_2 type )
{
switch ( type ) {
case 0 : return L_2 ;
default: return L_3 ;
}
}
static T_1 F_3 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_4 ,
V_1 -> type ,
F_2 ( V_1 -> type ) ) ;
}
static T_1 F_4 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
return sprintf ( V_4 , L_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_3 V_6 )
{
F_6 ( V_1 -> V_5 ) ;
F_7 ( & V_1 -> V_7 , & V_3 -> V_3 ) ;
F_8 ( & V_1 -> V_7 ) ;
return V_6 ;
}
static T_1 F_9 ( struct V_8 * V_7 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_2 * V_9 ;
struct V_1 * V_10 ;
V_9 = F_10 ( V_3 ) ;
V_10 = F_11 ( V_7 ) ;
if ( ! V_9 -> V_11 )
return - V_12 ;
return V_9 -> V_11 ( V_10 , V_9 , V_4 ) ;
}
static T_1 F_12 ( struct V_8 * V_7 ,
struct V_9 * V_3 ,
const char * V_4 , T_3 V_13 )
{
struct V_2 * V_9 ;
struct V_1 * V_10 ;
V_9 = F_10 ( V_3 ) ;
V_10 = F_11 ( V_7 ) ;
if ( ! V_9 -> V_14 )
return - V_12 ;
return V_9 -> V_14 ( V_10 , V_9 , V_4 , V_13 ) ;
}
static void F_13 ( struct V_8 * V_7 )
{
struct V_1 * V_10 ;
V_10 = F_11 ( V_7 ) ;
F_14 ( V_10 -> V_15 ) ;
F_14 ( V_10 ) ;
}
static T_1 F_15 ( struct V_16 * V_17 , struct V_8 * V_7 ,
struct V_18 * V_19 ,
char * V_15 , T_4 V_20 , T_3 V_6 )
{
int V_21 ;
struct V_1 * V_10 = F_11 ( V_7 ) ;
if ( ! V_10 -> V_15 ) {
V_10 -> V_15 = F_16 ( V_10 -> V_22 , V_23 ) ;
if ( ! V_10 -> V_15 )
return - V_12 ;
V_21 = F_17 ( F_18 ( V_10 -> V_15 ) ,
V_10 -> V_22 , V_10 -> V_5 ) ;
if ( V_21 != V_24 ) {
F_19 ( L_6 ,
V_10 -> V_5 ) ;
F_14 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
return - V_12 ;
}
}
memcpy ( V_15 , V_10 -> V_15 + V_20 , V_6 ) ;
return V_6 ;
}
static struct V_1 * F_20 ( T_2 V_5 , T_3 V_22 , T_2 type )
{
struct V_1 * V_10 ;
int V_25 ;
V_10 = F_16 ( sizeof( * V_10 ) , V_23 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_7 . V_26 = V_27 ;
F_21 ( & V_10 -> V_7 , & V_28 ) ;
F_22 ( & V_10 -> V_29 ) ;
V_10 -> V_29 . V_3 . V_30 = L_7 ;
V_10 -> V_29 . V_3 . V_31 = 0400 ;
V_10 -> V_29 . V_22 = V_22 ;
V_10 -> V_29 . V_32 = F_15 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_22 = V_22 ;
V_10 -> type = type ;
V_10 -> V_15 = F_16 ( V_10 -> V_22 , V_23 ) ;
if ( V_10 -> V_15 ) {
V_25 = F_17 ( F_18 ( V_10 -> V_15 ) ,
V_10 -> V_22 , V_10 -> V_5 ) ;
if ( V_25 != V_24 ) {
F_19 ( L_6 ,
V_10 -> V_5 ) ;
F_14 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
V_25 = F_23 ( & V_10 -> V_7 , NULL , L_8 , V_5 ) ;
if ( V_25 ) {
F_8 ( & V_10 -> V_7 ) ;
return NULL ;
}
V_25 = F_24 ( & V_10 -> V_7 , & V_10 -> V_29 ) ;
if ( V_25 ) {
F_8 ( & V_10 -> V_7 ) ;
return NULL ;
}
F_25 ( & V_10 -> V_7 , V_33 ) ;
return V_10 ;
}
static void F_26 ( struct V_34 * V_35 )
{
T_5 V_22 ;
T_5 V_5 ;
T_5 type ;
T_2 V_36 ;
T_2 V_37 ;
T_2 V_38 ;
int V_25 ;
char V_30 [ 2 + 16 + 1 ] ;
V_25 = F_27 ( & V_5 , & V_22 , & type ) ;
if ( V_25 != V_24 ) {
F_19 ( L_9 ) ;
return;
}
V_36 = F_28 ( V_22 ) ;
V_37 = F_28 ( V_5 ) ;
V_38 = F_28 ( type ) ;
F_29 ( V_36 > V_39 ) ;
if ( V_36 >= V_39 )
V_36 = V_39 ;
sprintf ( V_30 , L_8 , V_37 ) ;
if ( F_30 ( V_27 , V_30 ) )
return;
F_20 ( V_37 , V_36 , V_38 ) ;
}
static int F_31 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_43 )
{
if ( V_42 & V_44 )
F_32 ( & V_45 ) ;
return 0 ;
}
int T_6 F_33 ( void )
{
int V_25 = 0 ;
if ( ! F_34 ( V_46 ) )
return - 1 ;
V_27 = F_35 ( L_10 , NULL , V_47 ) ;
if ( ! V_27 ) {
F_36 ( L_11 , V_48 ) ;
return - 1 ;
}
V_25 = F_37 ( & V_49 ) ;
if ( V_25 ) {
F_19 ( L_12 ,
V_48 , V_25 ) ;
return V_25 ;
}
F_38 () ;
return 0 ;
}
