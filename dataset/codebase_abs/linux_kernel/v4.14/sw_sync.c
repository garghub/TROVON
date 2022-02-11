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
V_9 -> V_13 = V_14 ;
F_8 ( & V_9 -> V_15 ) ;
F_9 ( & V_9 -> V_16 ) ;
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
static const char * F_18 ( struct V_2 * V_3 )
{
return L_1 ;
}
static const char * F_19 ( struct V_2 * V_3 )
{
struct V_7 * V_17 = F_20 ( V_3 ) ;
return V_17 -> V_8 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_7 * V_17 = F_20 ( V_3 ) ;
if ( ! F_22 ( & V_18 -> V_19 ) ) {
unsigned long V_20 ;
F_23 ( V_3 -> V_16 , V_20 ) ;
if ( ! F_22 ( & V_18 -> V_19 ) ) {
F_24 ( & V_18 -> V_19 ) ;
F_25 ( & V_18 -> V_21 , & V_17 -> V_13 ) ;
}
F_26 ( V_3 -> V_16 , V_20 ) ;
}
F_16 ( V_17 ) ;
F_27 ( V_3 ) ;
}
static bool F_28 ( struct V_2 * V_3 )
{
struct V_7 * V_17 = F_20 ( V_3 ) ;
return ! F_29 ( V_3 -> V_22 , V_17 -> V_23 ) ;
}
static bool F_30 ( struct V_2 * V_3 )
{
return true ;
}
static void F_31 ( struct V_2 * V_3 ,
char * V_24 , int V_25 )
{
snprintf ( V_24 , V_25 , L_2 , V_3 -> V_22 ) ;
}
static void F_32 ( struct V_2 * V_3 ,
char * V_24 , int V_25 )
{
struct V_7 * V_17 = F_20 ( V_3 ) ;
snprintf ( V_24 , V_25 , L_2 , V_17 -> V_23 ) ;
}
static void F_33 ( struct V_7 * V_9 , unsigned int V_26 )
{
struct V_1 * V_18 , * V_27 ;
F_34 ( V_9 ) ;
F_35 ( & V_9 -> V_16 ) ;
V_9 -> V_23 += V_26 ;
F_36 (pt, next, &obj->pt_list, link) {
if ( ! F_28 ( & V_18 -> V_6 ) )
break;
F_37 ( & V_18 -> V_19 ) ;
F_25 ( & V_18 -> V_21 , & V_9 -> V_13 ) ;
F_38 ( & V_18 -> V_6 ) ;
}
F_39 ( & V_9 -> V_16 ) ;
}
static struct V_1 * F_40 ( struct V_7 * V_9 ,
unsigned int V_23 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( sizeof( * V_18 ) , V_10 ) ;
if ( ! V_18 )
return NULL ;
F_14 ( V_9 ) ;
F_41 ( & V_18 -> V_6 , & V_5 , & V_9 -> V_16 ,
V_9 -> V_12 , V_23 ) ;
F_8 ( & V_18 -> V_19 ) ;
F_35 ( & V_9 -> V_16 ) ;
if ( ! F_42 ( & V_18 -> V_6 ) ) {
struct V_28 * * V_29 = & V_9 -> V_13 . V_28 ;
struct V_28 * V_17 = NULL ;
while ( * V_29 ) {
struct V_1 * V_30 ;
int V_31 ;
V_17 = * V_29 ;
V_30 = F_43 ( V_17 , F_44 ( * V_18 ) , V_21 ) ;
V_31 = V_23 - V_30 -> V_6 . V_22 ;
if ( V_31 > 0 ) {
V_29 = & V_17 -> V_32 ;
} else if ( V_31 < 0 ) {
V_29 = & V_17 -> V_33 ;
} else {
if ( F_45 ( & V_30 -> V_6 ) ) {
F_46 ( & V_18 -> V_6 ) ;
V_18 = V_30 ;
goto V_34;
}
V_29 = & V_17 -> V_33 ;
}
}
F_47 ( & V_18 -> V_21 , V_17 , V_29 ) ;
F_48 ( & V_18 -> V_21 , & V_9 -> V_13 ) ;
V_17 = F_49 ( & V_18 -> V_21 ) ;
F_50 ( & V_18 -> V_19 ,
V_17 ? & F_43 ( V_17 , F_44 ( * V_18 ) , V_21 ) -> V_19 : & V_9 -> V_15 ) ;
}
V_34:
F_39 ( & V_9 -> V_16 ) ;
return V_18 ;
}
static int F_51 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_7 * V_9 ;
char V_37 [ V_38 ] ;
F_52 ( V_37 , V_39 ) ;
V_9 = F_3 ( V_37 ) ;
if ( ! V_9 )
return - V_40 ;
V_36 -> V_41 = V_9 ;
return 0 ;
}
static int F_53 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_7 * V_9 = V_36 -> V_41 ;
F_54 () ;
F_16 ( V_9 ) ;
return 0 ;
}
static long F_55 ( struct V_7 * V_9 ,
unsigned long V_42 )
{
int V_43 = F_56 ( V_44 ) ;
int V_45 ;
struct V_1 * V_18 ;
struct V_46 * V_46 ;
struct V_47 V_48 ;
if ( V_43 < 0 )
return V_43 ;
if ( F_57 ( & V_48 , ( void V_49 * ) V_42 , sizeof( V_48 ) ) ) {
V_45 = - V_50 ;
goto V_45;
}
V_18 = F_40 ( V_9 , V_48 . V_23 ) ;
if ( ! V_18 ) {
V_45 = - V_40 ;
goto V_45;
}
V_46 = F_58 ( & V_18 -> V_6 ) ;
F_46 ( & V_18 -> V_6 ) ;
if ( ! V_46 ) {
V_45 = - V_40 ;
goto V_45;
}
V_48 . V_3 = V_43 ;
if ( F_59 ( ( void V_49 * ) V_42 , & V_48 , sizeof( V_48 ) ) ) {
F_60 ( V_46 -> V_36 ) ;
V_45 = - V_50 ;
goto V_45;
}
F_61 ( V_43 , V_46 -> V_36 ) ;
return 0 ;
V_45:
F_62 ( V_43 ) ;
return V_45 ;
}
static long F_63 ( struct V_7 * V_9 , unsigned long V_42 )
{
T_1 V_23 ;
if ( F_57 ( & V_23 , ( void V_49 * ) V_42 , sizeof( V_23 ) ) )
return - V_50 ;
while ( V_23 > V_51 ) {
F_33 ( V_9 , V_51 ) ;
V_23 -= V_51 ;
}
F_33 ( V_9 , V_23 ) ;
return 0 ;
}
static long F_64 ( struct V_36 * V_36 , unsigned int V_52 ,
unsigned long V_42 )
{
struct V_7 * V_9 = V_36 -> V_41 ;
switch ( V_52 ) {
case V_53 :
return F_55 ( V_9 , V_42 ) ;
case V_54 :
return F_63 ( V_9 , V_42 ) ;
default:
return - V_55 ;
}
}
