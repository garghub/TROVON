static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( V_2 -> V_3 != & V_4 )
return NULL ;
return F_2 ( V_2 , struct V_1 , V_5 ) ;
}
struct V_6 * F_3 ( const char * V_7 )
{
struct V_6 * V_8 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_5 ( & V_8 -> V_10 ) ;
V_8 -> V_11 = F_6 ( 1 ) ;
F_7 ( V_8 -> V_7 , V_7 , sizeof( V_8 -> V_7 ) ) ;
F_8 ( & V_8 -> V_12 ) ;
F_8 ( & V_8 -> V_13 ) ;
F_9 ( & V_8 -> V_14 ) ;
F_10 ( V_8 ) ;
return V_8 ;
}
static void F_11 ( struct V_10 * V_10 )
{
struct V_6 * V_8 =
F_2 ( V_10 , struct V_6 , V_10 ) ;
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_6 * V_8 )
{
F_15 ( & V_8 -> V_10 ) ;
}
static void F_16 ( struct V_6 * V_8 )
{
F_17 ( & V_8 -> V_10 , F_11 ) ;
}
static void F_18 ( struct V_6 * V_8 , unsigned int V_15 )
{
unsigned long V_16 ;
struct V_1 * V_17 , * V_18 ;
F_19 ( V_8 ) ;
F_20 ( & V_8 -> V_14 , V_16 ) ;
V_8 -> V_19 += V_15 ;
F_21 (pt, next, &obj->active_list_head,
active_list) {
if ( F_22 ( & V_17 -> V_5 ) )
F_23 ( & V_17 -> V_20 ) ;
}
F_24 ( & V_8 -> V_14 , V_16 ) ;
}
static struct V_1 * F_25 ( struct V_6 * V_8 , int V_21 ,
unsigned int V_19 )
{
unsigned long V_16 ;
struct V_1 * V_17 ;
if ( V_21 < sizeof( * V_17 ) )
return NULL ;
V_17 = F_4 ( V_21 , V_9 ) ;
if ( ! V_17 )
return NULL ;
F_20 ( & V_8 -> V_14 , V_16 ) ;
F_14 ( V_8 ) ;
F_26 ( & V_17 -> V_5 , & V_4 , & V_8 -> V_14 ,
V_8 -> V_11 , V_19 ) ;
F_27 ( & V_17 -> V_22 , & V_8 -> V_12 ) ;
F_8 ( & V_17 -> V_20 ) ;
F_24 ( & V_8 -> V_14 , V_16 ) ;
return V_17 ;
}
static const char * F_28 ( struct V_2 * V_2 )
{
return L_1 ;
}
static const char * F_29 ( struct V_2 * V_2 )
{
struct V_6 * V_23 = F_30 ( V_2 ) ;
return V_23 -> V_7 ;
}
static void F_31 ( struct V_2 * V_2 )
{
struct V_1 * V_17 = F_1 ( V_2 ) ;
struct V_6 * V_23 = F_30 ( V_2 ) ;
unsigned long V_16 ;
F_20 ( V_2 -> V_24 , V_16 ) ;
F_32 ( & V_17 -> V_22 ) ;
if ( F_33 ( ! F_34 ( & V_17 -> V_20 ) ) )
F_32 ( & V_17 -> V_20 ) ;
F_24 ( V_2 -> V_24 , V_16 ) ;
F_16 ( V_23 ) ;
F_35 ( V_2 ) ;
}
static bool F_36 ( struct V_2 * V_2 )
{
struct V_6 * V_23 = F_30 ( V_2 ) ;
return ( V_2 -> V_25 > V_23 -> V_19 ) ? false : true ;
}
static bool F_37 ( struct V_2 * V_2 )
{
struct V_1 * V_17 = F_1 ( V_2 ) ;
struct V_6 * V_23 = F_30 ( V_2 ) ;
if ( F_36 ( V_2 ) )
return false ;
F_27 ( & V_17 -> V_20 , & V_23 -> V_13 ) ;
return true ;
}
static void F_38 ( struct V_2 * V_2 ,
char * V_26 , int V_21 )
{
snprintf ( V_26 , V_21 , L_2 , V_2 -> V_25 ) ;
}
static void F_39 ( struct V_2 * V_2 ,
char * V_26 , int V_21 )
{
struct V_6 * V_23 = F_30 ( V_2 ) ;
snprintf ( V_26 , V_21 , L_2 , V_23 -> V_19 ) ;
}
static int F_40 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
struct V_6 * V_8 ;
char V_29 [ V_30 ] ;
F_41 ( V_29 , V_31 ) ;
V_8 = F_3 ( V_29 ) ;
if ( ! V_8 )
return - V_32 ;
V_28 -> V_33 = V_8 ;
return 0 ;
}
static int F_42 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
struct V_6 * V_8 = V_28 -> V_33 ;
F_43 () ;
F_16 ( V_8 ) ;
return 0 ;
}
static long F_44 ( struct V_6 * V_8 ,
unsigned long V_34 )
{
int V_35 = F_45 ( V_36 ) ;
int V_37 ;
struct V_1 * V_17 ;
struct V_38 * V_38 ;
struct V_39 V_40 ;
if ( V_35 < 0 )
return V_35 ;
if ( F_46 ( & V_40 , ( void V_41 * ) V_34 , sizeof( V_40 ) ) ) {
V_37 = - V_42 ;
goto V_37;
}
V_17 = F_25 ( V_8 , sizeof( * V_17 ) , V_40 . V_19 ) ;
if ( ! V_17 ) {
V_37 = - V_32 ;
goto V_37;
}
V_38 = F_47 ( & V_17 -> V_5 ) ;
if ( ! V_38 ) {
F_48 ( & V_17 -> V_5 ) ;
V_37 = - V_32 ;
goto V_37;
}
V_40 . V_2 = V_35 ;
if ( F_49 ( ( void V_41 * ) V_34 , & V_40 , sizeof( V_40 ) ) ) {
F_50 ( V_38 -> V_28 ) ;
V_37 = - V_42 ;
goto V_37;
}
F_51 ( V_35 , V_38 -> V_28 ) ;
return 0 ;
V_37:
F_52 ( V_35 ) ;
return V_37 ;
}
static long F_53 ( struct V_6 * V_8 , unsigned long V_34 )
{
T_1 V_19 ;
if ( F_46 ( & V_19 , ( void V_41 * ) V_34 , sizeof( V_19 ) ) )
return - V_42 ;
F_18 ( V_8 , V_19 ) ;
return 0 ;
}
static long F_54 ( struct V_28 * V_28 , unsigned int V_43 ,
unsigned long V_34 )
{
struct V_6 * V_8 = V_28 -> V_33 ;
switch ( V_43 ) {
case V_44 :
return F_44 ( V_8 , V_34 ) ;
case V_45 :
return F_53 ( V_8 , V_34 ) ;
default:
return - V_46 ;
}
}
