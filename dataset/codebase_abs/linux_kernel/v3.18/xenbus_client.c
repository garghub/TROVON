const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
[ V_10 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
} ;
return ( V_2 < F_2 ( V_3 ) ) ? V_3 [ V_2 ] : L_10 ;
}
int F_3 ( struct V_13 * V_14 , const char * V_15 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * * , unsigned int ) )
{
int V_18 ;
V_17 -> V_19 = V_15 ;
V_17 -> F_4 = F_4 ;
V_18 = F_5 ( V_17 ) ;
if ( V_18 ) {
V_17 -> V_19 = NULL ;
V_17 -> F_4 = NULL ;
F_6 ( V_14 , V_18 , L_11 , V_15 ) ;
}
return V_18 ;
}
int F_7 ( struct V_13 * V_14 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * * , unsigned int ) ,
const char * V_20 , ... )
{
int V_18 ;
T_1 V_21 ;
char * V_15 ;
va_start ( V_21 , V_20 ) ;
V_15 = F_8 ( V_22 | V_23 , V_20 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_15 ) {
F_6 ( V_14 , - V_24 , L_12 ) ;
return - V_24 ;
}
V_18 = F_3 ( V_14 , V_15 , V_17 , F_4 ) ;
if ( V_18 )
F_9 ( V_15 ) ;
return V_18 ;
}
static int
F_10 ( struct V_13 * V_14 ,
enum V_1 V_2 , int V_25 )
{
struct V_26 V_27 ;
int V_28 ;
int V_18 , abort ;
if ( V_2 == V_14 -> V_2 )
return 0 ;
V_29:
abort = 1 ;
V_18 = F_11 ( & V_27 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_13 ) ;
return 0 ;
}
V_18 = F_13 ( V_27 , V_14 -> V_30 , L_14 , L_15 , & V_28 ) ;
if ( V_18 != 1 )
goto abort;
V_18 = F_14 ( V_27 , V_14 -> V_30 , L_14 , L_15 , V_2 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_16 ) ;
goto abort;
}
abort = 0 ;
abort:
V_18 = F_15 ( V_27 , abort ) ;
if ( V_18 ) {
if ( V_18 == - V_31 && ! abort )
goto V_29;
F_12 ( V_14 , V_25 , V_18 , L_17 ) ;
} else
V_14 -> V_2 = V_2 ;
return 0 ;
}
int F_16 ( struct V_13 * V_14 , enum V_1 V_2 )
{
return F_10 ( V_14 , V_2 , 0 ) ;
}
int F_17 ( struct V_13 * V_14 )
{
F_16 ( V_14 , V_10 ) ;
F_18 ( & V_14 -> V_32 ) ;
return 0 ;
}
static char * F_19 ( struct V_13 * V_14 )
{
return F_20 ( V_33 , L_18 , V_14 -> V_30 ) ;
}
static void F_21 ( struct V_13 * V_14 , int V_18 ,
const char * V_34 , T_1 V_21 )
{
unsigned int V_35 ;
char * V_36 = NULL ;
char * V_37 = NULL ;
#define F_22 4096
V_36 = F_23 ( F_22 , V_33 ) ;
if ( V_36 == NULL )
goto V_38;
V_35 = sprintf ( V_36 , L_19 , - V_18 ) ;
vsnprintf ( V_36 + V_35 , F_22 - V_35 , V_34 , V_21 ) ;
F_24 ( & V_14 -> V_14 , L_20 , V_36 ) ;
V_37 = F_19 ( V_14 ) ;
if ( V_37 == NULL ) {
F_24 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_36 ) ;
goto V_38;
}
if ( F_25 ( V_39 , V_37 , L_22 , V_36 ) != 0 ) {
F_24 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_36 ) ;
goto V_38;
}
V_38:
F_9 ( V_36 ) ;
F_9 ( V_37 ) ;
}
void F_26 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
}
void F_6 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
F_16 ( V_14 , V_9 ) ;
}
static void F_12 ( struct V_13 * V_14 , int V_25 , int V_18 ,
const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_25 )
F_10 ( V_14 , V_9 , 1 ) ;
}
int F_27 ( struct V_13 * V_14 , unsigned long V_40 )
{
int V_18 = F_28 ( V_14 -> V_41 , V_40 , 0 ) ;
if ( V_18 < 0 )
F_6 ( V_14 , V_18 , L_23 ) ;
return V_18 ;
}
int F_29 ( struct V_13 * V_14 , int * V_42 )
{
struct V_43 V_44 ;
int V_18 ;
V_44 . V_45 = V_46 ;
V_44 . V_47 = V_14 -> V_41 ;
V_18 = F_30 ( V_48 ,
& V_44 ) ;
if ( V_18 )
F_6 ( V_14 , V_18 , L_24 ) ;
else
* V_42 = V_44 . V_42 ;
return V_18 ;
}
int F_31 ( struct V_13 * V_14 , int V_42 )
{
struct V_49 V_50 ;
int V_18 ;
V_50 . V_42 = V_42 ;
V_18 = F_30 ( V_51 , & V_50 ) ;
if ( V_18 )
F_26 ( V_14 , V_18 , L_25 , V_42 ) ;
return V_18 ;
}
int F_32 ( struct V_13 * V_14 , int V_52 , void * * V_53 )
{
return V_54 -> V_55 ( V_14 , V_52 , V_53 ) ;
}
static int F_33 ( struct V_13 * V_14 ,
int V_52 , void * * V_53 )
{
struct V_56 V_57 = {
. V_58 = V_59 | V_60 ,
. V_61 = V_52 ,
. V_45 = V_14 -> V_41 ,
} ;
struct V_62 * V_19 ;
struct V_63 * V_64 ;
T_2 * V_65 ;
* V_53 = NULL ;
V_19 = F_34 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 )
return - V_24 ;
V_64 = F_35 ( V_66 , & V_65 ) ;
if ( ! V_64 ) {
F_9 ( V_19 ) ;
return - V_24 ;
}
V_57 . V_67 = F_36 ( V_65 ) . V_68 ;
F_37 ( & V_57 , 1 ) ;
if ( V_57 . V_69 != V_70 ) {
F_38 ( V_64 ) ;
F_9 ( V_19 ) ;
F_6 ( V_14 , V_57 . V_69 ,
L_26 ,
V_52 , V_14 -> V_41 ) ;
return V_57 . V_69 ;
}
V_19 -> V_71 = V_57 . V_71 ;
V_19 -> V_64 = V_64 ;
F_39 ( & V_72 ) ;
F_40 ( & V_19 -> V_73 , & V_74 ) ;
F_41 ( & V_72 ) ;
* V_53 = V_64 -> V_75 ;
return 0 ;
}
static int F_42 ( struct V_13 * V_14 ,
int V_52 , void * * V_53 )
{
struct V_62 * V_19 ;
int V_18 ;
void * V_75 ;
* V_53 = NULL ;
V_19 = F_34 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 )
return - V_24 ;
V_18 = F_43 ( 1 , & V_19 -> V_76 , false ) ;
if ( V_18 )
goto V_77;
V_75 = F_44 ( F_45 ( V_19 -> V_76 ) ) ;
V_18 = F_46 ( V_14 , V_52 , & V_19 -> V_71 , V_75 ) ;
if ( V_18 )
goto V_78;
F_39 ( & V_72 ) ;
F_40 ( & V_19 -> V_73 , & V_74 ) ;
F_41 ( & V_72 ) ;
* V_53 = V_75 ;
return 0 ;
V_78:
F_47 ( 1 , & V_19 -> V_76 ) ;
V_77:
F_9 ( V_19 ) ;
return V_18 ;
}
int F_46 ( struct V_13 * V_14 , int V_52 ,
T_3 * V_71 , void * V_53 )
{
struct V_56 V_57 ;
F_48 ( & V_57 , ( unsigned long ) V_53 , V_59 , V_52 ,
V_14 -> V_41 ) ;
F_37 ( & V_57 , 1 ) ;
if ( V_57 . V_69 != V_70 ) {
F_6 ( V_14 , V_57 . V_69 ,
L_26 ,
V_52 , V_14 -> V_41 ) ;
} else
* V_71 = V_57 . V_71 ;
return V_57 . V_69 ;
}
int F_49 ( struct V_13 * V_14 , void * V_53 )
{
return V_54 -> V_79 ( V_14 , V_53 ) ;
}
static int F_50 ( struct V_13 * V_14 , void * V_53 )
{
struct V_62 * V_19 ;
struct V_80 V_57 = {
. V_67 = ( unsigned long ) V_53 ,
} ;
unsigned int V_81 ;
F_39 ( & V_72 ) ;
F_51 (node, &xenbus_valloc_pages, next) {
if ( V_19 -> V_64 -> V_75 == V_53 ) {
F_52 ( & V_19 -> V_73 ) ;
goto V_82;
}
}
V_19 = NULL ;
V_82:
F_41 ( & V_72 ) ;
if ( ! V_19 ) {
F_26 ( V_14 , - V_83 ,
L_27 , V_53 ) ;
return V_84 ;
}
V_57 . V_71 = V_19 -> V_71 ;
V_57 . V_67 = F_36 (
F_53 ( ( unsigned long ) V_53 , & V_81 ) ) . V_68 ;
if ( F_54 ( V_85 , & V_57 , 1 ) )
F_55 () ;
if ( V_57 . V_69 == V_70 )
F_38 ( V_19 -> V_64 ) ;
else
F_26 ( V_14 , V_57 . V_69 ,
L_28 ,
V_19 -> V_71 , V_57 . V_69 ) ;
F_9 ( V_19 ) ;
return V_57 . V_69 ;
}
static int F_56 ( struct V_13 * V_14 , void * V_53 )
{
int V_86 ;
struct V_62 * V_19 ;
void * V_75 ;
F_39 ( & V_72 ) ;
F_51 (node, &xenbus_valloc_pages, next) {
V_75 = F_44 ( F_45 ( V_19 -> V_76 ) ) ;
if ( V_75 == V_53 ) {
F_52 ( & V_19 -> V_73 ) ;
goto V_82;
}
}
V_19 = V_75 = NULL ;
V_82:
F_41 ( & V_72 ) ;
if ( ! V_19 ) {
F_26 ( V_14 , - V_83 ,
L_27 , V_53 ) ;
return V_84 ;
}
V_86 = F_57 ( V_14 , V_19 -> V_71 , V_75 ) ;
if ( ! V_86 )
F_47 ( 1 , & V_19 -> V_76 ) ;
else
F_58 ( 1 , L_29 , V_53 ) ;
F_9 ( V_19 ) ;
return V_86 ;
}
int F_57 ( struct V_13 * V_14 ,
T_3 V_71 , void * V_53 )
{
struct V_80 V_57 ;
F_59 ( & V_57 , ( unsigned long ) V_53 , V_59 , V_71 ) ;
if ( F_54 ( V_85 , & V_57 , 1 ) )
F_55 () ;
if ( V_57 . V_69 != V_70 )
F_26 ( V_14 , V_57 . V_69 ,
L_28 ,
V_71 , V_57 . V_69 ) ;
return V_57 . V_69 ;
}
enum V_1 F_60 ( const char * V_15 )
{
enum V_1 V_87 ;
int V_18 = F_61 ( V_39 , V_15 , L_14 , L_15 , & V_87 , NULL ) ;
if ( V_18 )
V_87 = V_4 ;
return V_87 ;
}
void T_4 F_62 ( void )
{
if ( ! F_63 ( V_88 ) )
V_54 = & V_89 ;
else
V_54 = & V_90 ;
}
