static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 != & V_5 )
return NULL ;
return F_2 ( V_3 , struct V_1 , V_6 ) ;
}
static struct V_7 * F_3 ( const char * V_8 )
{
struct V_7 * V_9 ;
V_9 = F_4 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
F_5 ( & V_9 -> V_11 ) ;
V_9 -> V_12 = F_6 ( 1 ) ;
F_7 ( V_9 -> V_8 , V_8 , sizeof( V_9 -> V_8 ) ) ;
F_8 ( & V_9 -> V_13 ) ;
F_8 ( & V_9 -> V_14 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_10 ( V_9 ) ;
return V_9 ;
}
static void F_11 ( struct V_11 * V_11 )
{
struct V_7 * V_9 =
F_2 ( V_11 , struct V_7 , V_11 ) ;
F_12 ( V_9 ) ;
F_13 ( V_9 ) ;
}
static void F_14 ( struct V_7 * V_9 )
{
F_15 ( & V_9 -> V_11 ) ;
}
static void F_16 ( struct V_7 * V_9 )
{
F_17 ( & V_9 -> V_11 , F_11 ) ;
}
static void F_18 ( struct V_7 * V_9 , unsigned int V_16 )
{
unsigned long V_17 ;
struct V_1 * V_18 , * V_19 ;
F_19 ( V_9 ) ;
F_20 ( & V_9 -> V_15 , V_17 ) ;
V_9 -> V_20 += V_16 ;
F_21 (pt, next, &obj->active_list_head,
active_list) {
if ( F_22 ( & V_18 -> V_6 ) )
F_23 ( & V_18 -> V_21 ) ;
}
F_24 ( & V_9 -> V_15 , V_17 ) ;
}
static struct V_1 * F_25 ( struct V_7 * V_9 , int V_22 ,
unsigned int V_20 )
{
unsigned long V_17 ;
struct V_1 * V_18 ;
if ( V_22 < sizeof( * V_18 ) )
return NULL ;
V_18 = F_4 ( V_22 , V_10 ) ;
if ( ! V_18 )
return NULL ;
F_20 ( & V_9 -> V_15 , V_17 ) ;
F_14 ( V_9 ) ;
F_26 ( & V_18 -> V_6 , & V_5 , & V_9 -> V_15 ,
V_9 -> V_12 , V_20 ) ;
F_27 ( & V_18 -> V_23 , & V_9 -> V_13 ) ;
F_8 ( & V_18 -> V_21 ) ;
F_24 ( & V_9 -> V_15 , V_17 ) ;
return V_18 ;
}
static const char * F_28 ( struct V_2 * V_3 )
{
return L_1 ;
}
static const char * F_29 ( struct V_2 * V_3 )
{
struct V_7 * V_24 = F_30 ( V_3 ) ;
return V_24 -> V_8 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_7 * V_24 = F_30 ( V_3 ) ;
unsigned long V_17 ;
F_20 ( V_3 -> V_25 , V_17 ) ;
F_32 ( & V_18 -> V_23 ) ;
if ( ! F_33 ( & V_18 -> V_21 ) )
F_32 ( & V_18 -> V_21 ) ;
F_24 ( V_3 -> V_25 , V_17 ) ;
F_16 ( V_24 ) ;
F_34 ( V_3 ) ;
}
static bool F_35 ( struct V_2 * V_3 )
{
struct V_7 * V_24 = F_30 ( V_3 ) ;
return ( V_3 -> V_26 > V_24 -> V_20 ) ? false : true ;
}
static bool F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_7 * V_24 = F_30 ( V_3 ) ;
if ( F_35 ( V_3 ) )
return false ;
F_27 ( & V_18 -> V_21 , & V_24 -> V_14 ) ;
return true ;
}
static void F_37 ( struct V_2 * V_3 ,
char * V_27 , int V_22 )
{
snprintf ( V_27 , V_22 , L_2 , V_3 -> V_26 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
char * V_27 , int V_22 )
{
struct V_7 * V_24 = F_30 ( V_3 ) ;
snprintf ( V_27 , V_22 , L_2 , V_24 -> V_20 ) ;
}
static int F_39 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
struct V_7 * V_9 ;
char V_30 [ V_31 ] ;
F_40 ( V_30 , V_32 ) ;
V_9 = F_3 ( V_30 ) ;
if ( ! V_9 )
return - V_33 ;
V_29 -> V_34 = V_9 ;
return 0 ;
}
static int F_41 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
struct V_7 * V_9 = V_29 -> V_34 ;
F_42 () ;
F_16 ( V_9 ) ;
return 0 ;
}
static long F_43 ( struct V_7 * V_9 ,
unsigned long V_35 )
{
int V_36 = F_44 ( V_37 ) ;
int V_38 ;
struct V_1 * V_18 ;
struct V_39 * V_39 ;
struct V_40 V_41 ;
if ( V_36 < 0 )
return V_36 ;
if ( F_45 ( & V_41 , ( void V_42 * ) V_35 , sizeof( V_41 ) ) ) {
V_38 = - V_43 ;
goto V_38;
}
V_18 = F_25 ( V_9 , sizeof( * V_18 ) , V_41 . V_20 ) ;
if ( ! V_18 ) {
V_38 = - V_33 ;
goto V_38;
}
V_39 = F_46 ( & V_18 -> V_6 ) ;
F_47 ( & V_18 -> V_6 ) ;
if ( ! V_39 ) {
V_38 = - V_33 ;
goto V_38;
}
V_41 . V_3 = V_36 ;
if ( F_48 ( ( void V_42 * ) V_35 , & V_41 , sizeof( V_41 ) ) ) {
F_49 ( V_39 -> V_29 ) ;
V_38 = - V_43 ;
goto V_38;
}
F_50 ( V_36 , V_39 -> V_29 ) ;
return 0 ;
V_38:
F_51 ( V_36 ) ;
return V_38 ;
}
static long F_52 ( struct V_7 * V_9 , unsigned long V_35 )
{
T_1 V_20 ;
if ( F_45 ( & V_20 , ( void V_42 * ) V_35 , sizeof( V_20 ) ) )
return - V_43 ;
F_18 ( V_9 , V_20 ) ;
return 0 ;
}
static long F_53 ( struct V_29 * V_29 , unsigned int V_44 ,
unsigned long V_35 )
{
struct V_7 * V_9 = V_29 -> V_34 ;
switch ( V_44 ) {
case V_45 :
return F_43 ( V_9 , V_35 ) ;
case V_46 :
return F_52 ( V_9 , V_35 ) ;
default:
return - V_47 ;
}
}
