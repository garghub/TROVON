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
return F_33 ( - V_26 ) ;
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
static void F_46 ( struct V_2 * V_50 , const struct V_51 * V_52 , long V_53 )
{
unsigned long V_9 ;
if ( ! F_47 ( V_50 , V_53 ) ) {
F_48 ( 1 ) ;
return;
}
F_49 ( & V_50 -> V_54 , V_9 ) ;
F_50 ( V_50 , V_52 ) ;
V_50 -> V_9 |= V_55 ;
F_51 ( & V_50 -> V_54 , V_9 ) ;
}
static void F_52 ( struct V_2 * V_50 , unsigned int V_56 , long V_53 )
{
F_46 ( V_50 , F_53 ( V_56 ) , V_53 ) ;
}
void F_54 ( struct V_2 * V_50 , const struct V_51 * V_52 )
{
F_46 ( V_50 , V_52 , V_27 ) ;
}
void F_55 ( struct V_2 * V_50 , unsigned int V_56 )
{
F_52 ( V_50 , V_56 , V_27 ) ;
}
struct V_2 * F_56 ( int (* F_24)( void * V_14 ) ,
void * V_14 , unsigned int V_56 ,
const char * V_38 )
{
struct V_2 * V_50 ;
V_50 = F_34 ( F_24 , V_14 , F_57 ( V_56 ) , V_38 ,
V_56 ) ;
if ( F_43 ( V_50 ) )
return V_50 ;
F_58 ( V_57 , & F_1 ( V_50 ) -> V_9 ) ;
F_1 ( V_50 ) -> V_56 = V_56 ;
F_59 ( V_50 ) ;
return V_50 ;
}
static void F_60 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_22 ( V_10 , & V_1 -> V_9 ) ;
if ( F_61 ( V_17 , & V_1 -> V_9 ) ) {
if ( F_7 ( V_57 , & V_1 -> V_9 ) )
F_52 ( V_3 , V_1 -> V_56 , V_16 ) ;
F_62 ( V_3 , V_16 ) ;
}
}
void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
if ( V_1 )
F_60 ( V_3 , V_1 ) ;
}
int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
int V_24 = - V_58 ;
if ( V_1 ) {
if ( ! F_7 ( V_17 , & V_1 -> V_9 ) ) {
F_58 ( V_10 , & V_1 -> V_9 ) ;
if ( V_3 != V_8 ) {
F_40 ( V_3 ) ;
F_42 ( & V_1 -> V_18 ) ;
}
}
V_24 = 0 ;
}
return V_24 ;
}
int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_24 ;
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_58 ( V_7 , & V_1 -> V_9 ) ;
F_60 ( V_3 , V_1 ) ;
F_40 ( V_3 ) ;
F_42 ( & V_1 -> V_25 ) ;
}
V_24 = V_3 -> V_59 ;
F_67 ( V_3 ) ;
F_68 ( V_24 ) ;
return V_24 ;
}
int F_69 ( void * V_60 )
{
struct V_2 * V_29 = V_8 ;
F_70 ( V_29 , L_1 ) ;
F_71 ( V_29 ) ;
F_45 ( V_29 , V_49 ) ;
F_72 ( V_61 [ V_62 ] ) ;
V_8 -> V_9 |= V_63 ;
for (; ; ) {
F_73 ( V_64 ) ;
if ( F_74 ( & V_43 ) )
F_21 () ;
F_18 ( V_19 ) ;
F_37 ( & V_41 ) ;
while ( ! F_74 ( & V_43 ) ) {
struct V_21 * V_22 ;
V_22 = F_75 ( V_43 . V_65 ,
struct V_21 , V_42 ) ;
F_76 ( & V_22 -> V_42 ) ;
F_39 ( & V_41 ) ;
F_31 ( V_22 ) ;
F_37 ( & V_41 ) ;
}
F_39 ( & V_41 ) ;
}
return 0 ;
}
void F_77 ( struct V_66 * V_67 ,
const char * V_68 ,
struct V_69 * V_70 )
{
F_78 ( & V_67 -> V_71 ) ;
F_79 ( & V_67 -> V_71 , V_70 , V_68 ) ;
F_80 ( & V_67 -> V_72 ) ;
V_67 -> V_13 = NULL ;
}
int F_81 ( void * V_73 )
{
struct V_66 * V_67 = V_73 ;
struct V_74 * V_75 ;
F_48 ( V_67 -> V_13 ) ;
V_67 -> V_13 = V_8 ;
V_76:
F_73 ( V_64 ) ;
if ( F_6 () ) {
F_18 ( V_19 ) ;
F_82 ( & V_67 -> V_71 ) ;
V_67 -> V_13 = NULL ;
F_83 ( & V_67 -> V_71 ) ;
return 0 ;
}
V_75 = NULL ;
F_82 ( & V_67 -> V_71 ) ;
if ( ! F_74 ( & V_67 -> V_72 ) ) {
V_75 = F_84 ( & V_67 -> V_72 ,
struct V_74 , V_34 ) ;
F_76 ( & V_75 -> V_34 ) ;
}
V_67 -> V_77 = V_75 ;
F_83 ( & V_67 -> V_71 ) ;
if ( V_75 ) {
F_18 ( V_19 ) ;
V_75 -> V_78 ( V_75 ) ;
} else if ( ! F_12 ( V_8 ) )
F_21 () ;
F_85 () ;
goto V_76;
}
static void F_86 ( struct V_66 * V_67 ,
struct V_74 * V_75 ,
struct V_79 * V_80 )
{
F_87 ( & V_67 -> V_71 ) ;
F_38 ( & V_75 -> V_34 , V_80 ) ;
V_75 -> V_67 = V_67 ;
if ( ! V_67 -> V_77 && F_5 ( V_67 -> V_13 ) )
F_40 ( V_67 -> V_13 ) ;
}
bool F_88 ( struct V_66 * V_67 ,
struct V_74 * V_75 )
{
bool V_24 = false ;
unsigned long V_9 ;
F_89 ( & V_67 -> V_71 , V_9 ) ;
if ( F_74 ( & V_75 -> V_34 ) ) {
F_86 ( V_67 , V_75 , & V_67 -> V_72 ) ;
V_24 = true ;
}
F_90 ( & V_67 -> V_71 , V_9 ) ;
return V_24 ;
}
static void F_91 ( struct V_74 * V_75 )
{
struct V_81 * V_82 =
F_92 ( V_75 , struct V_81 , V_75 ) ;
F_20 ( & V_82 -> V_23 ) ;
}
void F_93 ( struct V_74 * V_75 )
{
struct V_81 V_82 = {
F_94 ( V_82 . V_75 , F_91 ) ,
F_95 ( V_82 . V_23 ) ,
} ;
struct V_66 * V_67 ;
bool V_83 = false ;
V_84:
V_67 = V_75 -> V_67 ;
if ( ! V_67 )
return;
F_82 ( & V_67 -> V_71 ) ;
if ( V_75 -> V_67 != V_67 ) {
F_83 ( & V_67 -> V_71 ) ;
goto V_84;
}
if ( ! F_74 ( & V_75 -> V_34 ) )
F_86 ( V_67 , & V_82 . V_75 , V_75 -> V_34 . V_65 ) ;
else if ( V_67 -> V_77 == V_75 )
F_86 ( V_67 , & V_82 . V_75 , V_67 -> V_72 . V_65 ) ;
else
V_83 = true ;
F_83 ( & V_67 -> V_71 ) ;
if ( ! V_83 )
F_42 ( & V_82 . V_23 ) ;
}
void F_96 ( struct V_66 * V_67 )
{
struct V_81 V_82 = {
F_94 ( V_82 . V_75 , F_91 ) ,
F_95 ( V_82 . V_23 ) ,
} ;
F_88 ( V_67 , & V_82 . V_75 ) ;
F_42 ( & V_82 . V_23 ) ;
}
