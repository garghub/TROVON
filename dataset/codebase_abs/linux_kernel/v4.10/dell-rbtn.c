static enum V_1 F_1 ( struct V_2 * V_3 )
{
unsigned long long V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_3 -> V_6 , L_1 , NULL , & V_4 ) ;
if ( F_3 ( V_5 ) )
return V_7 ;
switch ( V_4 ) {
case 0 :
case 1 :
return V_8 ;
case 2 :
case 3 :
return V_9 ;
default:
return V_7 ;
}
}
static int F_4 ( struct V_2 * V_3 )
{
unsigned long long V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_3 -> V_6 , L_2 , NULL , & V_4 ) ;
if ( F_3 ( V_5 ) )
return - V_10 ;
return ! V_4 ;
}
static int F_5 ( struct V_2 * V_3 , bool V_11 )
{
struct V_12 V_13 ;
union V_14 V_15 ;
T_1 V_5 ;
V_15 . type = V_16 ;
V_15 . integer . V_17 = V_11 ;
V_13 . V_18 = 1 ;
V_13 . V_19 = & V_15 ;
V_5 = F_6 ( V_3 -> V_6 , L_3 , & V_13 , NULL ) ;
if ( F_3 ( V_5 ) )
return - V_10 ;
return 0 ;
}
static void F_7 ( struct V_20 * V_20 , void * V_21 )
{
struct V_2 * V_3 = V_21 ;
int V_22 ;
V_22 = F_4 ( V_3 ) ;
if ( V_22 < 0 )
return;
F_8 ( V_20 , V_22 , V_22 ) ;
}
static int F_9 ( void * V_21 , bool V_23 )
{
return - V_10 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_24 * V_24 = V_3 -> V_25 ;
int V_26 ;
if ( V_24 -> V_20 )
return 0 ;
V_24 -> V_20 = F_11 ( L_4 , & V_3 -> V_27 ,
V_28 , & V_29 , V_3 ) ;
if ( ! V_24 -> V_20 )
return - V_30 ;
V_26 = F_12 ( V_24 -> V_20 ) ;
if ( V_26 ) {
F_13 ( V_24 -> V_20 ) ;
V_24 -> V_20 = NULL ;
return V_26 ;
}
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_24 * V_24 = V_3 -> V_25 ;
if ( ! V_24 -> V_20 )
return;
F_15 ( V_24 -> V_20 ) ;
F_13 ( V_24 -> V_20 ) ;
V_24 -> V_20 = NULL ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_24 * V_24 = V_3 -> V_25 ;
if ( V_24 -> V_20 )
F_7 ( V_24 -> V_20 , V_3 ) ;
}
static int F_17 ( struct V_24 * V_24 )
{
int V_26 ;
V_24 -> V_31 = F_18 () ;
if ( ! V_24 -> V_31 )
return - V_30 ;
V_24 -> V_31 -> V_32 = L_5 ;
V_24 -> V_31 -> V_33 = L_6 ;
V_24 -> V_31 -> V_34 . V_35 = V_36 ;
V_24 -> V_31 -> V_37 [ 0 ] = F_19 ( V_38 ) ;
F_20 ( V_39 , V_24 -> V_31 -> V_40 ) ;
V_26 = F_21 ( V_24 -> V_31 ) ;
if ( V_26 ) {
F_22 ( V_24 -> V_31 ) ;
V_24 -> V_31 = NULL ;
return V_26 ;
}
return 0 ;
}
static void F_23 ( struct V_24 * V_24 )
{
F_24 ( V_24 -> V_31 ) ;
V_24 -> V_31 = NULL ;
}
static void F_25 ( struct V_24 * V_24 )
{
F_26 ( V_24 -> V_31 , V_39 , 1 ) ;
F_27 ( V_24 -> V_31 ) ;
F_26 ( V_24 -> V_31 , V_39 , 0 ) ;
F_27 ( V_24 -> V_31 ) ;
}
static void T_2 F_28 ( void * V_41 )
{
struct V_24 * V_24 = V_41 ;
V_24 -> V_42 = false ;
}
static int F_29 ( struct V_3 * V_27 )
{
struct V_2 * V_3 = F_30 ( V_27 ) ;
struct V_24 * V_24 = F_31 ( V_3 ) ;
V_24 -> V_42 = true ;
return 0 ;
}
static int F_32 ( struct V_3 * V_27 )
{
struct V_2 * V_3 = F_30 ( V_27 ) ;
struct V_24 * V_24 = F_31 ( V_3 ) ;
T_1 V_5 ;
V_5 = F_33 ( V_43 ,
F_28 , V_24 ) ;
if ( F_3 ( V_5 ) )
F_28 ( V_24 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_27 , void * V_21 )
{
struct V_2 * V_3 = F_30 ( V_27 ) ;
struct V_24 * V_24 = V_3 -> V_25 ;
int * V_18 = V_21 ;
if ( V_24 -> type == V_9 )
( * V_18 ) ++ ;
return 0 ;
}
static int F_35 ( struct V_3 * V_27 , void * V_21 )
{
struct V_2 * V_3 = F_30 ( V_27 ) ;
struct V_24 * V_24 = V_3 -> V_25 ;
bool V_11 = V_21 ;
if ( V_24 -> type != V_9 )
return 0 ;
if ( V_11 )
F_10 ( V_3 ) ;
else
F_14 ( V_3 ) ;
return 0 ;
}
int F_36 ( struct V_44 * V_45 )
{
bool V_46 ;
int V_18 ;
int V_26 ;
V_18 = 0 ;
V_26 = F_37 ( & V_47 . V_48 , NULL , & V_18 ,
F_34 ) ;
if ( V_26 || V_18 == 0 )
return - V_49 ;
V_46 = ! V_50 . V_51 ;
V_26 = F_38 ( & V_50 , V_45 ) ;
if ( V_26 != 0 )
return V_26 ;
if ( V_52 && V_46 )
V_26 = F_37 ( & V_47 . V_48 , NULL ,
( void * ) false , F_35 ) ;
return V_26 ;
}
int F_39 ( struct V_44 * V_45 )
{
int V_26 ;
V_26 = F_40 ( & V_50 , V_45 ) ;
if ( V_26 != 0 )
return V_26 ;
if ( V_52 && ! V_50 . V_51 )
V_26 = F_37 ( & V_47 . V_48 , NULL ,
( void * ) true , F_35 ) ;
return V_26 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_24 * V_24 ;
enum V_1 type ;
int V_26 = 0 ;
type = F_1 ( V_3 ) ;
if ( type == V_7 ) {
F_42 ( & V_3 -> V_27 , L_7 ) ;
return - V_10 ;
}
V_26 = F_5 ( V_3 , true ) ;
if ( V_26 < 0 ) {
F_43 ( & V_3 -> V_27 , L_8 ) ;
return V_26 ;
}
V_24 = F_44 ( & V_3 -> V_27 , sizeof( * V_24 ) , V_53 ) ;
if ( ! V_24 )
return - V_30 ;
V_24 -> type = type ;
V_3 -> V_25 = V_24 ;
switch ( V_24 -> type ) {
case V_8 :
V_26 = F_17 ( V_24 ) ;
break;
case V_9 :
if ( V_52 && V_50 . V_51 )
V_26 = 0 ;
else
V_26 = F_10 ( V_3 ) ;
break;
default:
V_26 = - V_10 ;
}
return V_26 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_24 * V_24 = V_3 -> V_25 ;
switch ( V_24 -> type ) {
case V_8 :
F_23 ( V_24 ) ;
break;
case V_9 :
F_14 ( V_3 ) ;
break;
default:
break;
}
F_5 ( V_3 , false ) ;
V_3 -> V_25 = NULL ;
return 0 ;
}
static void F_46 ( struct V_2 * V_3 , T_3 V_54 )
{
struct V_24 * V_24 = V_3 -> V_25 ;
if ( V_24 -> V_42 ) {
F_47 ( & V_3 -> V_27 , L_9 ) ;
return;
}
if ( V_54 != 0x80 ) {
F_42 ( & V_3 -> V_27 , L_10 ,
V_54 ) ;
return;
}
switch ( V_24 -> type ) {
case V_8 :
F_25 ( V_24 ) ;
break;
case V_9 :
F_16 ( V_3 ) ;
F_48 ( & V_50 , V_54 , V_3 ) ;
break;
default:
break;
}
}
