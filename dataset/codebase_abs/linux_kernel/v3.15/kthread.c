static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 -> V_4 ) ;
if ( F_5 ( V_6 ) )
return F_2 ( V_6 ) ;
return NULL ;
}
bool F_6 ( void )
{
return F_7 ( V_7 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_8 ( void )
{
return F_7 ( V_10 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_9 ( bool * V_11 )
{
bool V_12 = false ;
F_10 () ;
if ( F_11 ( F_12 ( V_8 ) ) )
V_12 = F_13 ( true ) ;
if ( V_11 )
* V_11 = V_12 ;
return F_6 () ;
}
void * F_14 ( struct V_2 * V_13 )
{
return F_1 ( V_13 ) -> V_14 ;
}
void * F_15 ( struct V_2 * V_13 )
{
struct V_1 * V_1 = F_1 ( V_13 ) ;
void * V_14 = NULL ;
F_16 ( & V_14 , & V_1 -> V_14 , sizeof( V_14 ) ) ;
return V_14 ;
}
static void F_17 ( struct V_1 * V_15 )
{
F_18 ( V_16 ) ;
while ( F_7 ( V_10 , & V_15 -> V_9 ) ) {
if ( ! F_19 ( V_17 , & V_15 -> V_9 ) )
F_20 ( & V_15 -> V_18 ) ;
F_21 () ;
F_18 ( V_16 ) ;
}
F_22 ( V_17 , & V_15 -> V_9 ) ;
F_18 ( V_19 ) ;
}
void F_23 ( void )
{
F_17 ( F_1 ( V_8 ) ) ;
}
static int V_1 ( void * V_20 )
{
struct V_21 * V_22 = V_20 ;
int (* F_24)( void * V_14 ) = V_22 -> F_24 ;
void * V_14 = V_22 -> V_14 ;
struct V_5 * V_23 ;
struct V_1 V_15 ;
int V_24 ;
V_15 . V_9 = 0 ;
V_15 . V_14 = V_14 ;
F_25 ( & V_15 . V_25 ) ;
F_25 ( & V_15 . V_18 ) ;
V_8 -> V_4 = & V_15 . V_25 ;
V_23 = F_26 ( & V_22 -> V_23 , NULL ) ;
if ( ! V_23 ) {
F_27 ( V_22 ) ;
F_28 ( - V_26 ) ;
}
F_18 ( V_27 ) ;
V_22 -> V_28 = V_8 ;
F_20 ( V_23 ) ;
F_21 () ;
V_24 = - V_26 ;
if ( ! F_7 ( V_7 , & V_15 . V_9 ) ) {
F_17 ( & V_15 ) ;
V_24 = F_24 ( V_14 ) ;
}
F_28 ( V_24 ) ;
}
int F_29 ( struct V_2 * V_29 )
{
#ifdef F_30
if ( V_29 == V_30 )
return V_29 -> V_31 ;
#endif
return V_32 ;
}
static void F_31 ( struct V_21 * V_22 )
{
int V_33 ;
#ifdef F_30
V_8 -> V_31 = V_22 -> V_34 ;
#endif
V_33 = F_32 ( V_1 , V_22 , V_35 | V_36 | V_37 ) ;
if ( V_33 < 0 ) {
struct V_5 * V_23 = F_26 ( & V_22 -> V_23 , NULL ) ;
if ( ! V_23 ) {
F_27 ( V_22 ) ;
return;
}
V_22 -> V_28 = F_33 ( V_33 ) ;
F_20 ( V_23 ) ;
}
}
struct V_2 * F_34 ( int (* F_24)( void * V_14 ) ,
void * V_14 , int V_34 ,
const char V_38 [] ,
... )
{
F_35 ( V_23 ) ;
struct V_2 * V_13 ;
struct V_21 * V_22 = F_36 ( sizeof( * V_22 ) ,
V_39 ) ;
if ( ! V_22 )
return F_33 ( - V_40 ) ;
V_22 -> F_24 = F_24 ;
V_22 -> V_14 = V_14 ;
V_22 -> V_34 = V_34 ;
V_22 -> V_23 = & V_23 ;
F_37 ( & V_41 ) ;
F_38 ( & V_22 -> V_42 , & V_43 ) ;
F_39 ( & V_41 ) ;
F_40 ( V_30 ) ;
if ( F_11 ( F_41 ( & V_23 ) ) ) {
if ( F_26 ( & V_22 -> V_23 , NULL ) )
return F_33 ( - V_40 ) ;
F_42 ( & V_23 ) ;
}
V_13 = V_22 -> V_28 ;
if ( ! F_43 ( V_13 ) ) {
static const struct V_44 V_45 = { . V_46 = 0 } ;
T_1 args ;
va_start ( args , V_38 ) ;
vsnprintf ( V_13 -> V_47 , sizeof( V_13 -> V_47 ) , V_38 , args ) ;
va_end ( args ) ;
F_44 ( V_13 , V_48 , & V_45 ) ;
F_45 ( V_13 , V_49 ) ;
}
F_27 ( V_22 ) ;
return V_13 ;
}
static void F_46 ( struct V_2 * V_50 , unsigned int V_51 , long V_52 )
{
if ( ! F_47 ( V_50 , V_52 ) ) {
F_48 ( 1 ) ;
return;
}
F_49 ( V_50 , F_50 ( V_51 ) ) ;
V_50 -> V_9 |= V_53 ;
}
void F_51 ( struct V_2 * V_50 , unsigned int V_51 )
{
F_46 ( V_50 , V_51 , V_27 ) ;
}
struct V_2 * F_52 ( int (* F_24)( void * V_14 ) ,
void * V_14 , unsigned int V_51 ,
const char * V_38 )
{
struct V_2 * V_50 ;
V_50 = F_34 ( F_24 , V_14 , F_53 ( V_51 ) , V_38 ,
V_51 ) ;
if ( F_43 ( V_50 ) )
return V_50 ;
F_54 ( V_54 , & F_1 ( V_50 ) -> V_9 ) ;
F_1 ( V_50 ) -> V_51 = V_51 ;
F_55 ( V_50 ) ;
return V_50 ;
}
static void F_56 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_22 ( V_10 , & V_1 -> V_9 ) ;
if ( F_57 ( V_17 , & V_1 -> V_9 ) ) {
if ( F_7 ( V_54 , & V_1 -> V_9 ) )
F_46 ( V_3 , V_1 -> V_51 , V_16 ) ;
F_58 ( V_3 , V_16 ) ;
}
}
void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
if ( V_1 )
F_56 ( V_3 , V_1 ) ;
}
int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
int V_24 = - V_55 ;
if ( V_1 ) {
if ( ! F_7 ( V_17 , & V_1 -> V_9 ) ) {
F_54 ( V_10 , & V_1 -> V_9 ) ;
if ( V_3 != V_8 ) {
F_40 ( V_3 ) ;
F_42 ( & V_1 -> V_18 ) ;
}
}
V_24 = 0 ;
}
return V_24 ;
}
int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_24 ;
F_61 ( V_3 ) ;
F_62 ( V_3 ) ;
V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_54 ( V_7 , & V_1 -> V_9 ) ;
F_56 ( V_3 , V_1 ) ;
F_40 ( V_3 ) ;
F_42 ( & V_1 -> V_25 ) ;
}
V_24 = V_3 -> V_56 ;
F_63 ( V_3 ) ;
F_64 ( V_24 ) ;
return V_24 ;
}
int F_65 ( void * V_57 )
{
struct V_2 * V_29 = V_8 ;
F_66 ( V_29 , L_1 ) ;
F_67 ( V_29 ) ;
F_45 ( V_29 , V_49 ) ;
F_68 ( V_58 [ V_59 ] ) ;
V_8 -> V_9 |= V_60 ;
for (; ; ) {
F_69 ( V_61 ) ;
if ( F_70 ( & V_43 ) )
F_21 () ;
F_18 ( V_19 ) ;
F_37 ( & V_41 ) ;
while ( ! F_70 ( & V_43 ) ) {
struct V_21 * V_22 ;
V_22 = F_71 ( V_43 . V_62 ,
struct V_21 , V_42 ) ;
F_72 ( & V_22 -> V_42 ) ;
F_39 ( & V_41 ) ;
F_31 ( V_22 ) ;
F_37 ( & V_41 ) ;
}
F_39 ( & V_41 ) ;
}
return 0 ;
}
void F_73 ( struct V_63 * V_64 ,
const char * V_65 ,
struct V_66 * V_67 )
{
F_74 ( & V_64 -> V_68 ) ;
F_75 ( & V_64 -> V_68 , V_67 , V_65 ) ;
F_76 ( & V_64 -> V_69 ) ;
V_64 -> V_13 = NULL ;
}
int F_77 ( void * V_70 )
{
struct V_63 * V_64 = V_70 ;
struct V_71 * V_72 ;
F_48 ( V_64 -> V_13 ) ;
V_64 -> V_13 = V_8 ;
V_73:
F_69 ( V_61 ) ;
if ( F_6 () ) {
F_18 ( V_19 ) ;
F_78 ( & V_64 -> V_68 ) ;
V_64 -> V_13 = NULL ;
F_79 ( & V_64 -> V_68 ) ;
return 0 ;
}
V_72 = NULL ;
F_78 ( & V_64 -> V_68 ) ;
if ( ! F_70 ( & V_64 -> V_69 ) ) {
V_72 = F_80 ( & V_64 -> V_69 ,
struct V_71 , V_34 ) ;
F_72 ( & V_72 -> V_34 ) ;
}
V_64 -> V_74 = V_72 ;
F_79 ( & V_64 -> V_68 ) ;
if ( V_72 ) {
F_18 ( V_19 ) ;
V_72 -> V_75 ( V_72 ) ;
} else if ( ! F_12 ( V_8 ) )
F_21 () ;
F_81 () ;
goto V_73;
}
static void F_82 ( struct V_63 * V_64 ,
struct V_71 * V_72 ,
struct V_76 * V_77 )
{
F_83 ( & V_64 -> V_68 ) ;
F_38 ( & V_72 -> V_34 , V_77 ) ;
V_72 -> V_64 = V_64 ;
if ( F_5 ( V_64 -> V_13 ) )
F_40 ( V_64 -> V_13 ) ;
}
bool F_84 ( struct V_63 * V_64 ,
struct V_71 * V_72 )
{
bool V_24 = false ;
unsigned long V_9 ;
F_85 ( & V_64 -> V_68 , V_9 ) ;
if ( F_70 ( & V_72 -> V_34 ) ) {
F_82 ( V_64 , V_72 , & V_64 -> V_69 ) ;
V_24 = true ;
}
F_86 ( & V_64 -> V_68 , V_9 ) ;
return V_24 ;
}
static void F_87 ( struct V_71 * V_72 )
{
struct V_78 * V_79 =
F_88 ( V_72 , struct V_78 , V_72 ) ;
F_20 ( & V_79 -> V_23 ) ;
}
void F_89 ( struct V_71 * V_72 )
{
struct V_78 V_79 = {
F_90 ( V_79 . V_72 , F_87 ) ,
F_91 ( V_79 . V_23 ) ,
} ;
struct V_63 * V_64 ;
bool V_80 = false ;
V_81:
V_64 = V_72 -> V_64 ;
if ( ! V_64 )
return;
F_78 ( & V_64 -> V_68 ) ;
if ( V_72 -> V_64 != V_64 ) {
F_79 ( & V_64 -> V_68 ) ;
goto V_81;
}
if ( ! F_70 ( & V_72 -> V_34 ) )
F_82 ( V_64 , & V_79 . V_72 , V_72 -> V_34 . V_62 ) ;
else if ( V_64 -> V_74 == V_72 )
F_82 ( V_64 , & V_79 . V_72 , V_64 -> V_69 . V_62 ) ;
else
V_80 = true ;
F_79 ( & V_64 -> V_68 ) ;
if ( ! V_80 )
F_42 ( & V_79 . V_23 ) ;
}
void F_92 ( struct V_63 * V_64 )
{
struct V_78 V_79 = {
F_90 ( V_79 . V_72 , F_87 ) ,
F_91 ( V_79 . V_23 ) ,
} ;
F_84 ( V_64 , & V_79 . V_72 ) ;
F_42 ( & V_79 . V_23 ) ;
}
