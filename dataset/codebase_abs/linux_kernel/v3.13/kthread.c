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
return F_31 () ;
}
static void F_32 ( struct V_21 * V_22 )
{
int V_32 ;
#ifdef F_30
V_8 -> V_31 = V_22 -> V_33 ;
#endif
V_32 = F_33 ( V_1 , V_22 , V_34 | V_35 | V_36 ) ;
if ( V_32 < 0 ) {
struct V_5 * V_23 = F_26 ( & V_22 -> V_23 , NULL ) ;
if ( ! V_23 ) {
F_27 ( V_22 ) ;
return;
}
V_22 -> V_28 = F_34 ( V_32 ) ;
F_20 ( V_23 ) ;
}
}
struct V_2 * F_35 ( int (* F_24)( void * V_14 ) ,
void * V_14 , int V_33 ,
const char V_37 [] ,
... )
{
F_36 ( V_23 ) ;
struct V_2 * V_13 ;
struct V_21 * V_22 = F_37 ( sizeof( * V_22 ) ,
V_38 ) ;
if ( ! V_22 )
return F_34 ( - V_39 ) ;
V_22 -> F_24 = F_24 ;
V_22 -> V_14 = V_14 ;
V_22 -> V_33 = V_33 ;
V_22 -> V_23 = & V_23 ;
F_38 ( & V_40 ) ;
F_39 ( & V_22 -> V_41 , & V_42 ) ;
F_40 ( & V_40 ) ;
F_41 ( V_30 ) ;
if ( F_11 ( F_42 ( & V_23 ) ) ) {
if ( F_26 ( & V_22 -> V_23 , NULL ) )
return F_34 ( - V_39 ) ;
F_43 ( & V_23 ) ;
}
V_13 = V_22 -> V_28 ;
if ( ! F_44 ( V_13 ) ) {
static const struct V_43 V_44 = { . V_45 = 0 } ;
T_1 args ;
va_start ( args , V_37 ) ;
vsnprintf ( V_13 -> V_46 , sizeof( V_13 -> V_46 ) , V_37 , args ) ;
va_end ( args ) ;
F_45 ( V_13 , V_47 , & V_44 ) ;
F_46 ( V_13 , V_48 ) ;
}
F_27 ( V_22 ) ;
return V_13 ;
}
static void F_47 ( struct V_2 * V_49 , unsigned int V_50 , long V_51 )
{
if ( ! F_48 ( V_49 , V_51 ) ) {
F_49 ( 1 ) ;
return;
}
F_50 ( V_49 , F_51 ( V_50 ) ) ;
V_49 -> V_9 |= V_52 ;
}
void F_52 ( struct V_2 * V_49 , unsigned int V_50 )
{
F_47 ( V_49 , V_50 , V_27 ) ;
}
struct V_2 * F_53 ( int (* F_24)( void * V_14 ) ,
void * V_14 , unsigned int V_50 ,
const char * V_37 )
{
struct V_2 * V_49 ;
V_49 = F_35 ( F_24 , V_14 , F_54 ( V_50 ) , V_37 ,
V_50 ) ;
if ( F_44 ( V_49 ) )
return V_49 ;
F_55 ( V_53 , & F_1 ( V_49 ) -> V_9 ) ;
F_1 ( V_49 ) -> V_50 = V_50 ;
F_56 ( V_49 ) ;
return V_49 ;
}
static void F_57 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_22 ( V_10 , & V_1 -> V_9 ) ;
if ( F_58 ( V_17 , & V_1 -> V_9 ) ) {
if ( F_7 ( V_53 , & V_1 -> V_9 ) )
F_47 ( V_3 , V_1 -> V_50 , V_16 ) ;
F_59 ( V_3 , V_16 ) ;
}
}
void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
if ( V_1 )
F_57 ( V_3 , V_1 ) ;
}
int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
int V_24 = - V_54 ;
if ( V_1 ) {
if ( ! F_7 ( V_17 , & V_1 -> V_9 ) ) {
F_55 ( V_10 , & V_1 -> V_9 ) ;
if ( V_3 != V_8 ) {
F_41 ( V_3 ) ;
F_43 ( & V_1 -> V_18 ) ;
}
}
V_24 = 0 ;
}
return V_24 ;
}
int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_24 ;
F_62 ( V_3 ) ;
F_63 ( V_3 ) ;
V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_55 ( V_7 , & V_1 -> V_9 ) ;
F_57 ( V_3 , V_1 ) ;
F_41 ( V_3 ) ;
F_43 ( & V_1 -> V_25 ) ;
}
V_24 = V_3 -> V_55 ;
F_64 ( V_3 ) ;
F_65 ( V_24 ) ;
return V_24 ;
}
int F_66 ( void * V_56 )
{
struct V_2 * V_29 = V_8 ;
F_67 ( V_29 , L_1 ) ;
F_68 ( V_29 ) ;
F_46 ( V_29 , V_48 ) ;
F_69 ( V_57 [ V_58 ] ) ;
V_8 -> V_9 |= V_59 ;
for (; ; ) {
F_70 ( V_60 ) ;
if ( F_71 ( & V_42 ) )
F_21 () ;
F_18 ( V_19 ) ;
F_38 ( & V_40 ) ;
while ( ! F_71 ( & V_42 ) ) {
struct V_21 * V_22 ;
V_22 = F_72 ( V_42 . V_61 ,
struct V_21 , V_41 ) ;
F_73 ( & V_22 -> V_41 ) ;
F_40 ( & V_40 ) ;
F_32 ( V_22 ) ;
F_38 ( & V_40 ) ;
}
F_40 ( & V_40 ) ;
}
return 0 ;
}
void F_74 ( struct V_62 * V_63 ,
const char * V_64 ,
struct V_65 * V_66 )
{
F_75 ( & V_63 -> V_67 ) ;
F_76 ( & V_63 -> V_67 , V_66 , V_64 ) ;
F_77 ( & V_63 -> V_68 ) ;
V_63 -> V_13 = NULL ;
}
int F_78 ( void * V_69 )
{
struct V_62 * V_63 = V_69 ;
struct V_70 * V_71 ;
F_49 ( V_63 -> V_13 ) ;
V_63 -> V_13 = V_8 ;
V_72:
F_70 ( V_60 ) ;
if ( F_6 () ) {
F_18 ( V_19 ) ;
F_79 ( & V_63 -> V_67 ) ;
V_63 -> V_13 = NULL ;
F_80 ( & V_63 -> V_67 ) ;
return 0 ;
}
V_71 = NULL ;
F_79 ( & V_63 -> V_67 ) ;
if ( ! F_71 ( & V_63 -> V_68 ) ) {
V_71 = F_81 ( & V_63 -> V_68 ,
struct V_70 , V_33 ) ;
F_73 ( & V_71 -> V_33 ) ;
}
V_63 -> V_73 = V_71 ;
F_80 ( & V_63 -> V_67 ) ;
if ( V_71 ) {
F_18 ( V_19 ) ;
V_71 -> V_74 ( V_71 ) ;
} else if ( ! F_12 ( V_8 ) )
F_21 () ;
F_82 () ;
goto V_72;
}
static void F_83 ( struct V_62 * V_63 ,
struct V_70 * V_71 ,
struct V_75 * V_76 )
{
F_84 ( & V_63 -> V_67 ) ;
F_39 ( & V_71 -> V_33 , V_76 ) ;
V_71 -> V_63 = V_63 ;
if ( F_5 ( V_63 -> V_13 ) )
F_41 ( V_63 -> V_13 ) ;
}
bool F_85 ( struct V_62 * V_63 ,
struct V_70 * V_71 )
{
bool V_24 = false ;
unsigned long V_9 ;
F_86 ( & V_63 -> V_67 , V_9 ) ;
if ( F_71 ( & V_71 -> V_33 ) ) {
F_83 ( V_63 , V_71 , & V_63 -> V_68 ) ;
V_24 = true ;
}
F_87 ( & V_63 -> V_67 , V_9 ) ;
return V_24 ;
}
static void F_88 ( struct V_70 * V_71 )
{
struct V_77 * V_78 =
F_89 ( V_71 , struct V_77 , V_71 ) ;
F_20 ( & V_78 -> V_23 ) ;
}
void F_90 ( struct V_70 * V_71 )
{
struct V_77 V_78 = {
F_91 ( V_78 . V_71 , F_88 ) ,
F_92 ( V_78 . V_23 ) ,
} ;
struct V_62 * V_63 ;
bool V_79 = false ;
V_80:
V_63 = V_71 -> V_63 ;
if ( ! V_63 )
return;
F_79 ( & V_63 -> V_67 ) ;
if ( V_71 -> V_63 != V_63 ) {
F_80 ( & V_63 -> V_67 ) ;
goto V_80;
}
if ( ! F_71 ( & V_71 -> V_33 ) )
F_83 ( V_63 , & V_78 . V_71 , V_71 -> V_33 . V_61 ) ;
else if ( V_63 -> V_73 == V_71 )
F_83 ( V_63 , & V_78 . V_71 , V_63 -> V_68 . V_61 ) ;
else
V_79 = true ;
F_80 ( & V_63 -> V_67 ) ;
if ( ! V_79 )
F_43 ( & V_78 . V_23 ) ;
}
void F_93 ( struct V_62 * V_63 )
{
struct V_77 V_78 = {
F_91 ( V_78 . V_71 , F_88 ) ,
F_92 ( V_78 . V_23 ) ,
} ;
F_85 ( V_63 , & V_78 . V_71 ) ;
F_43 ( & V_78 . V_23 ) ;
}
