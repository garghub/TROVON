static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_2 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_7 = 1 ;
F_9 ( & V_2 -> V_5 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_8 * V_6 ,
T_1 V_9 , T_1 V_10 )
{
F_11 ( & V_2 -> V_4 ) ;
F_6 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
F_12 ( & V_2 -> V_4 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_4 ) ;
V_2 -> V_10 = V_11 ;
F_12 ( & V_2 -> V_4 ) ;
F_8 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_4 ) ;
V_2 -> V_12 = 1 ;
V_2 -> V_10 = V_11 ;
F_12 ( & V_2 -> V_4 ) ;
F_8 ( V_2 ) ;
}
static struct V_8 * F_15 ( struct V_1 * V_2 ,
int V_13 , T_1 V_9 , T_1 V_10 )
{
int V_14 ;
struct V_8 * V_6 ;
V_14 = F_16 ( V_2 -> V_5 ,
V_2 -> V_7 ,
F_17 ( V_13 ) ) ;
F_11 ( & V_2 -> V_4 ) ;
V_6 = V_2 -> V_6 ;
V_2 -> V_6 = NULL ;
if ( ! V_14 ) {
V_14 = - V_15 ;
goto V_16;
}
if ( ! V_6 || V_2 -> V_9 != V_9 || V_2 -> V_10 == V_10 ) {
V_14 = - V_17 ;
goto V_16;
}
if ( V_2 -> V_12 ) {
V_14 = - V_18 ;
goto V_16;
}
V_16:
F_12 ( & V_2 -> V_4 ) ;
if ( V_14 < 0 ) {
F_6 ( V_6 ) ;
V_6 = F_18 ( V_14 ) ;
}
V_2 -> V_7 = 0 ;
return V_6 ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_20 ( V_20 , struct V_21 , V_23 . V_20 ) ;
F_8 ( V_22 -> V_24 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_20 ( V_20 , struct V_21 , V_25 ) ;
struct V_8 * V_6 ;
V_6 = F_15 ( V_22 -> V_26 , V_22 -> V_27 ,
V_22 -> V_9 , V_22 -> V_10 ) ;
if ( ! V_22 -> V_28 ) {
F_22 ( V_22 , L_1 ) ;
if ( ! F_23 ( V_6 ) )
F_6 ( V_6 ) ;
V_6 = F_18 ( - V_18 ) ;
}
V_22 -> V_29 ( V_22 -> V_30 , V_22 -> V_31 , V_6 ) ;
}
static int F_24 ( struct V_30 * V_32 , struct V_8 * V_6 ,
T_2 V_13 , T_3 V_29 , void * V_31 )
{
struct V_21 * V_22 = F_25 ( V_32 ) ;
T_1 V_33 ;
if ( ! V_22 -> V_28 ) {
F_22 ( V_22 , L_1 ) ;
return - V_18 ;
}
V_22 -> V_27 = V_13 ;
V_22 -> V_29 = V_29 ;
V_22 -> V_31 = V_31 ;
F_26 ( & V_22 -> V_25 ) ;
if ( V_22 -> V_34 ) {
F_27 ( V_22 , L_2 , V_22 -> V_34 ) ;
F_6 ( V_6 ) ;
V_22 -> V_34 -- ;
return 0 ;
}
if ( V_6 ) {
F_10 ( V_22 -> V_24 , V_6 , V_22 -> V_9 ,
V_22 -> V_10 ) ;
F_28 ( & V_33 , 1 ) ;
V_33 = 3 + ( V_33 & 0x07 ) ;
F_29 ( & V_22 -> V_23 , F_17 ( V_33 ) ) ;
}
return 0 ;
}
static void F_30 ( struct V_30 * V_32 )
{
struct V_21 * V_22 = F_25 ( V_32 ) ;
F_13 ( V_22 -> V_26 ) ;
}
static int F_31 ( struct V_30 * V_32 , bool V_35 )
{
struct V_21 * V_22 = F_25 ( V_32 ) ;
V_22 -> V_28 = V_35 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_32 ,
int type , int V_36 )
{
struct V_21 * V_22 = F_25 ( V_32 ) ;
switch ( type ) {
case V_37 :
V_22 -> V_28 = true ;
V_22 -> V_10 = V_38 ;
V_22 -> V_9 = V_36 ;
break;
case V_39 :
break;
default:
F_22 ( V_22 , L_3 , type ) ;
return - V_17 ;
}
return 0 ;
}
static int F_33 ( struct V_30 * V_32 ,
struct V_8 * V_6 , T_2 V_13 ,
T_3 V_29 , void * V_31 )
{
return F_24 ( V_32 , V_6 , V_13 , V_29 , V_31 ) ;
}
static int F_34 ( struct V_30 * V_32 ,
int type , int V_36 )
{
struct V_21 * V_22 = F_25 ( V_32 ) ;
switch ( type ) {
case V_37 :
V_22 -> V_28 = true ;
V_22 -> V_10 = V_40 ;
V_22 -> V_9 = V_36 ;
break;
case V_39 :
break;
default:
F_22 ( V_22 , L_3 , type ) ;
return - V_17 ;
}
return 0 ;
}
static int F_35 ( struct V_30 * V_32 ,
struct V_8 * V_6 , T_2 V_13 ,
T_3 V_29 , void * V_31 )
{
return F_24 ( V_32 , V_6 , V_13 , V_29 , V_31 ) ;
}
static int F_36 ( struct V_30 * V_32 , T_2 V_13 ,
T_3 V_29 , void * V_31 )
{
return F_24 ( V_32 , NULL , V_13 , V_29 , V_31 ) ;
}
static void F_37 ( void )
{
V_41 = F_38 ( L_4 , NULL ) ;
if ( ! V_41 )
F_39 ( L_5 ) ;
}
static void F_40 ( void )
{
F_41 ( V_41 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_42 * V_43 ;
char V_44 [ 5 ] ;
T_4 V_45 ;
int V_46 ;
if ( ! V_41 ) {
F_22 ( V_22 , L_6 ) ;
return;
}
V_45 = V_22 -> V_30 -> V_47 -> V_45 ;
V_46 = snprintf ( V_44 , sizeof( V_44 ) , L_7 , V_45 ) ;
if ( V_46 >= sizeof( V_44 ) ) {
F_22 ( V_22 , L_8 , V_45 ) ;
return;
}
V_43 = F_38 ( V_44 , V_41 ) ;
if ( ! V_43 ) {
F_22 ( V_22 , L_9 ,
V_45 ) ;
return;
}
F_43 ( L_10 , 0664 , V_43 , & V_22 -> V_34 ) ;
}
static struct V_21 * F_44 ( struct V_1 * V_26 ,
struct V_1 * V_24 )
{
struct V_21 * V_22 ;
int V_14 ;
V_22 = F_2 ( sizeof( struct V_21 ) , V_3 ) ;
if ( ! V_22 )
return F_18 ( - V_48 ) ;
F_45 ( & V_22 -> V_23 , F_19 ) ;
F_46 ( & V_22 -> V_25 , F_21 ) ;
V_22 -> V_30 =
F_47 ( & V_49 ,
V_50 ,
V_51 ,
0 , 0 ) ;
if ( ! V_22 -> V_30 ) {
F_7 ( V_22 ) ;
return F_18 ( - V_48 ) ;
}
F_48 ( V_22 -> V_30 , V_22 ) ;
V_22 -> V_26 = V_26 ;
V_22 -> V_24 = V_24 ;
V_14 = F_49 ( V_22 -> V_30 ) ;
if ( V_14 ) {
F_39 ( L_11 , V_14 ) ;
F_50 ( V_22 -> V_30 ) ;
F_7 ( V_22 ) ;
return F_18 ( V_14 ) ;
}
F_42 ( V_22 ) ;
return V_22 ;
}
static void F_51 ( struct V_21 * V_22 )
{
F_52 ( V_22 -> V_30 ) ;
V_22 -> V_28 = false ;
F_14 ( V_22 -> V_26 ) ;
F_53 ( & V_22 -> V_23 ) ;
F_54 ( & V_22 -> V_25 ) ;
F_50 ( V_22 -> V_30 ) ;
F_7 ( V_22 ) ;
}
static int T_5 F_55 ( void )
{
struct V_1 * V_52 , * V_53 ;
int V_14 ;
V_52 = F_1 () ;
V_53 = F_1 () ;
if ( ! V_52 || ! V_53 ) {
V_14 = - V_48 ;
goto V_54;
}
F_37 () ;
V_55 = F_44 ( V_52 , V_53 ) ;
if ( F_23 ( V_55 ) ) {
V_14 = F_56 ( V_55 ) ;
goto V_54;
}
V_56 = F_44 ( V_53 , V_52 ) ;
if ( F_23 ( V_56 ) ) {
F_51 ( V_55 ) ;
V_14 = F_56 ( V_56 ) ;
goto V_54;
}
F_57 ( L_12 V_57 L_13 ) ;
return 0 ;
V_54:
F_39 ( L_14 , V_14 ) ;
F_5 ( V_52 ) ;
F_5 ( V_53 ) ;
return V_14 ;
}
static void T_6 F_58 ( void )
{
struct V_1 * V_52 , * V_53 ;
V_52 = V_55 -> V_26 ;
V_53 = V_55 -> V_24 ;
F_51 ( V_55 ) ;
F_51 ( V_56 ) ;
F_5 ( V_52 ) ;
F_5 ( V_53 ) ;
F_40 () ;
}
