static inline void F_1 ( void * V_1 )
{
V_2 -> V_3 = ( V_4 void V_5 * ) V_1 ;
}
static inline struct V_1 * F_2 ( struct V_6 * V_7 )
{
F_3 ( ! ( V_7 -> V_8 & V_9 ) ) ;
return ( V_4 void * ) V_7 -> V_3 ;
}
void F_4 ( struct V_6 * V_7 )
{
F_5 ( F_2 ( V_7 ) ) ;
}
bool F_6 ( void )
{
return F_7 ( V_10 , & F_2 ( V_2 ) -> V_8 ) ;
}
bool F_8 ( void )
{
return F_7 ( V_11 , & F_2 ( V_2 ) -> V_8 ) ;
}
bool F_9 ( bool * V_12 )
{
bool V_13 = false ;
F_10 () ;
if ( F_11 ( F_12 ( V_2 ) ) )
V_13 = F_13 ( true ) ;
if ( V_12 )
* V_12 = V_13 ;
return F_6 () ;
}
void * F_14 ( struct V_6 * V_14 )
{
return F_2 ( V_14 ) -> V_15 ;
}
void * F_15 ( struct V_6 * V_14 )
{
struct V_1 * V_1 = F_2 ( V_14 ) ;
void * V_15 = NULL ;
F_16 ( & V_15 , & V_1 -> V_15 , sizeof( V_15 ) ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_16 )
{
F_18 ( V_17 ) ;
while ( F_7 ( V_11 , & V_16 -> V_8 ) ) {
if ( ! F_19 ( V_18 , & V_16 -> V_8 ) )
F_20 ( & V_16 -> V_19 ) ;
F_21 () ;
F_18 ( V_17 ) ;
}
F_22 ( V_18 , & V_16 -> V_8 ) ;
F_18 ( V_20 ) ;
}
void F_23 ( void )
{
F_17 ( F_2 ( V_2 ) ) ;
}
static int V_1 ( void * V_21 )
{
struct V_22 * V_23 = V_21 ;
int (* F_24)( void * V_15 ) = V_23 -> F_24 ;
void * V_15 = V_23 -> V_15 ;
struct V_24 * V_25 ;
struct V_1 * V_16 ;
int V_26 ;
V_16 = F_25 ( sizeof( * V_16 ) , V_27 ) ;
F_1 ( V_16 ) ;
V_25 = F_26 ( & V_23 -> V_25 , NULL ) ;
if ( ! V_25 ) {
F_5 ( V_23 ) ;
F_27 ( - V_28 ) ;
}
if ( ! V_16 ) {
V_23 -> V_29 = F_28 ( - V_30 ) ;
F_20 ( V_25 ) ;
F_27 ( - V_30 ) ;
}
V_16 -> V_8 = 0 ;
V_16 -> V_15 = V_15 ;
F_29 ( & V_16 -> V_31 ) ;
F_29 ( & V_16 -> V_19 ) ;
V_2 -> V_32 = & V_16 -> V_31 ;
F_18 ( V_33 ) ;
V_23 -> V_29 = V_2 ;
F_20 ( V_25 ) ;
F_21 () ;
V_26 = - V_28 ;
if ( ! F_7 ( V_10 , & V_16 -> V_8 ) ) {
F_30 () ;
F_17 ( V_16 ) ;
V_26 = F_24 ( V_15 ) ;
}
F_27 ( V_26 ) ;
}
int F_31 ( struct V_6 * V_34 )
{
#ifdef F_32
if ( V_34 == V_35 )
return V_34 -> V_36 ;
#endif
return V_37 ;
}
static void F_33 ( struct V_22 * V_23 )
{
int V_38 ;
#ifdef F_32
V_2 -> V_36 = V_23 -> V_39 ;
#endif
V_38 = F_34 ( V_1 , V_23 , V_40 | V_41 | V_42 ) ;
if ( V_38 < 0 ) {
struct V_24 * V_25 = F_26 ( & V_23 -> V_25 , NULL ) ;
if ( ! V_25 ) {
F_5 ( V_23 ) ;
return;
}
V_23 -> V_29 = F_28 ( V_38 ) ;
F_20 ( V_25 ) ;
}
}
V_6 * F_35 ( int (* F_24)( void * V_15 ) ,
void * V_15 , int V_39 ,
const char V_43 [] ,
... )
{
struct V_6 * V_14 ;
T_1 args ;
va_start ( args , V_43 ) ;
V_14 = F_36 ( F_24 , V_15 , V_39 , V_43 , args ) ;
va_end ( args ) ;
return V_14 ;
}
static void F_37 ( struct V_6 * V_44 , const struct V_45 * V_46 , long V_47 )
{
unsigned long V_8 ;
if ( ! F_38 ( V_44 , V_47 ) ) {
F_3 ( 1 ) ;
return;
}
F_39 ( & V_44 -> V_48 , V_8 ) ;
F_40 ( V_44 , V_46 ) ;
V_44 -> V_8 |= V_49 ;
F_41 ( & V_44 -> V_48 , V_8 ) ;
}
static void F_42 ( struct V_6 * V_44 , unsigned int V_50 , long V_47 )
{
F_37 ( V_44 , F_43 ( V_50 ) , V_47 ) ;
}
void F_44 ( struct V_6 * V_44 , const struct V_45 * V_46 )
{
F_37 ( V_44 , V_46 , V_33 ) ;
}
void F_45 ( struct V_6 * V_44 , unsigned int V_50 )
{
F_42 ( V_44 , V_50 , V_33 ) ;
}
struct V_6 * F_46 ( int (* F_24)( void * V_15 ) ,
void * V_15 , unsigned int V_50 ,
const char * V_43 )
{
struct V_6 * V_44 ;
V_44 = F_35 ( F_24 , V_15 , F_47 ( V_50 ) , V_43 ,
V_50 ) ;
if ( F_48 ( V_44 ) )
return V_44 ;
F_45 ( V_44 , V_50 ) ;
F_49 ( V_51 , & F_2 ( V_44 ) -> V_8 ) ;
F_2 ( V_44 ) -> V_50 = V_50 ;
return V_44 ;
}
void F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_2 ( V_7 ) ;
F_22 ( V_11 , & V_1 -> V_8 ) ;
if ( F_51 ( V_18 , & V_1 -> V_8 ) ) {
if ( F_7 ( V_51 , & V_1 -> V_8 ) )
F_42 ( V_7 , V_1 -> V_50 , V_17 ) ;
F_52 ( V_7 , V_17 ) ;
}
}
int F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_2 ( V_7 ) ;
if ( F_3 ( V_7 -> V_8 & V_52 ) )
return - V_53 ;
if ( ! F_7 ( V_18 , & V_1 -> V_8 ) ) {
F_49 ( V_11 , & V_1 -> V_8 ) ;
if ( V_7 != V_2 ) {
F_54 ( V_7 ) ;
F_55 ( & V_1 -> V_19 ) ;
}
}
return 0 ;
}
int F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_1 ;
int V_26 ;
F_57 ( V_7 ) ;
F_58 ( V_7 ) ;
V_1 = F_2 ( V_7 ) ;
F_49 ( V_10 , & V_1 -> V_8 ) ;
F_50 ( V_7 ) ;
F_54 ( V_7 ) ;
F_55 ( & V_1 -> V_31 ) ;
V_26 = V_7 -> V_54 ;
F_59 ( V_7 ) ;
F_60 ( V_26 ) ;
return V_26 ;
}
int F_61 ( void * V_55 )
{
struct V_6 * V_34 = V_2 ;
F_62 ( V_34 , L_1 ) ;
F_63 ( V_34 ) ;
F_64 ( V_34 , V_56 ) ;
F_65 ( V_57 [ V_58 ] ) ;
V_2 -> V_8 |= V_59 ;
F_66 () ;
for (; ; ) {
F_67 ( V_60 ) ;
if ( F_68 ( & V_61 ) )
F_21 () ;
F_18 ( V_20 ) ;
F_69 ( & V_62 ) ;
while ( ! F_68 ( & V_61 ) ) {
struct V_22 * V_23 ;
V_23 = F_70 ( V_61 . V_63 ,
struct V_22 , V_64 ) ;
F_71 ( & V_23 -> V_64 ) ;
F_72 ( & V_62 ) ;
F_33 ( V_23 ) ;
F_69 ( & V_62 ) ;
}
F_72 ( & V_62 ) ;
}
return 0 ;
}
void F_73 ( struct V_65 * V_66 ,
const char * V_67 ,
struct V_68 * V_69 )
{
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
F_74 ( & V_66 -> V_70 ) ;
F_75 ( & V_66 -> V_70 , V_69 , V_67 ) ;
F_76 ( & V_66 -> V_71 ) ;
F_76 ( & V_66 -> V_72 ) ;
}
int F_77 ( void * V_73 )
{
struct V_65 * V_66 = V_73 ;
struct V_74 * V_75 ;
F_3 ( V_66 -> V_14 && V_66 -> V_14 != V_2 ) ;
V_66 -> V_14 = V_2 ;
if ( V_66 -> V_8 & V_76 )
F_78 () ;
V_77:
F_67 ( V_60 ) ;
if ( F_6 () ) {
F_18 ( V_20 ) ;
F_79 ( & V_66 -> V_70 ) ;
V_66 -> V_14 = NULL ;
F_80 ( & V_66 -> V_70 ) ;
return 0 ;
}
V_75 = NULL ;
F_79 ( & V_66 -> V_70 ) ;
if ( ! F_68 ( & V_66 -> V_71 ) ) {
V_75 = F_81 ( & V_66 -> V_71 ,
struct V_74 , V_39 ) ;
F_71 ( & V_75 -> V_39 ) ;
}
V_66 -> V_78 = V_75 ;
F_80 ( & V_66 -> V_70 ) ;
if ( V_75 ) {
F_18 ( V_20 ) ;
V_75 -> V_79 ( V_75 ) ;
} else if ( ! F_12 ( V_2 ) )
F_21 () ;
F_82 () ;
F_83 () ;
goto V_77;
}
V_65 *
F_84 ( unsigned int V_8 , const char V_43 [] , ... )
{
struct V_65 * V_66 ;
T_1 args ;
va_start ( args , V_43 ) ;
V_66 = F_85 ( - 1 , V_8 , V_43 , args ) ;
va_end ( args ) ;
return V_66 ;
}
struct V_65 *
F_86 ( int V_50 , unsigned int V_8 ,
const char V_43 [] , ... )
{
struct V_65 * V_66 ;
T_1 args ;
va_start ( args , V_43 ) ;
V_66 = F_85 ( V_50 , V_8 , V_43 , args ) ;
va_end ( args ) ;
return V_66 ;
}
static inline bool F_87 ( struct V_65 * V_66 ,
struct V_74 * V_75 )
{
F_88 ( & V_66 -> V_70 ) ;
return ! F_68 ( & V_75 -> V_39 ) || V_75 -> V_80 ;
}
static void F_89 ( struct V_65 * V_66 ,
struct V_74 * V_75 )
{
F_88 ( & V_66 -> V_70 ) ;
F_90 ( ! F_68 ( & V_75 -> V_39 ) ) ;
F_90 ( V_75 -> V_66 && V_75 -> V_66 != V_66 ) ;
}
static void F_91 ( struct V_65 * V_66 ,
struct V_74 * V_75 ,
struct V_81 * V_82 )
{
F_89 ( V_66 , V_75 ) ;
F_92 ( & V_75 -> V_39 , V_82 ) ;
V_75 -> V_66 = V_66 ;
if ( ! V_66 -> V_78 && F_93 ( V_66 -> V_14 ) )
F_54 ( V_66 -> V_14 ) ;
}
bool F_94 ( struct V_65 * V_66 ,
struct V_74 * V_75 )
{
bool V_26 = false ;
unsigned long V_8 ;
F_95 ( & V_66 -> V_70 , V_8 ) ;
if ( ! F_87 ( V_66 , V_75 ) ) {
F_91 ( V_66 , V_75 , & V_66 -> V_71 ) ;
V_26 = true ;
}
F_96 ( & V_66 -> V_70 , V_8 ) ;
return V_26 ;
}
void F_97 ( unsigned long V_83 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_83 ;
struct V_74 * V_75 = & V_85 -> V_75 ;
struct V_65 * V_66 = V_75 -> V_66 ;
if ( F_90 ( ! V_66 ) )
return;
F_69 ( & V_66 -> V_70 ) ;
F_90 ( V_75 -> V_66 != V_66 ) ;
F_90 ( F_68 ( & V_75 -> V_39 ) ) ;
F_71 ( & V_75 -> V_39 ) ;
F_91 ( V_66 , V_75 , & V_66 -> V_71 ) ;
F_72 ( & V_66 -> V_70 ) ;
}
void F_98 ( struct V_65 * V_66 ,
struct V_84 * V_85 ,
unsigned long V_86 )
{
struct V_87 * V_88 = & V_85 -> V_88 ;
struct V_74 * V_75 = & V_85 -> V_75 ;
F_90 ( V_88 -> V_89 != F_97 ||
V_88 -> V_15 != ( unsigned long ) V_85 ) ;
if ( ! V_86 ) {
F_91 ( V_66 , V_75 , & V_66 -> V_71 ) ;
return;
}
F_89 ( V_66 , V_75 ) ;
F_99 ( & V_75 -> V_39 , & V_66 -> V_72 ) ;
V_75 -> V_66 = V_66 ;
V_88 -> V_90 = V_91 + V_86 ;
F_100 ( V_88 ) ;
}
bool F_101 ( struct V_65 * V_66 ,
struct V_84 * V_85 ,
unsigned long V_86 )
{
struct V_74 * V_75 = & V_85 -> V_75 ;
unsigned long V_8 ;
bool V_26 = false ;
F_95 ( & V_66 -> V_70 , V_8 ) ;
if ( ! F_87 ( V_66 , V_75 ) ) {
F_98 ( V_66 , V_85 , V_86 ) ;
V_26 = true ;
}
F_96 ( & V_66 -> V_70 , V_8 ) ;
return V_26 ;
}
static void F_102 ( struct V_74 * V_75 )
{
struct V_92 * V_93 =
F_103 ( V_75 , struct V_92 , V_75 ) ;
F_20 ( & V_93 -> V_25 ) ;
}
void V_92 ( struct V_74 * V_75 )
{
struct V_92 V_93 = {
F_104 ( V_93 . V_75 , F_102 ) ,
F_105 ( V_93 . V_25 ) ,
} ;
struct V_65 * V_66 ;
bool V_94 = false ;
V_66 = V_75 -> V_66 ;
if ( ! V_66 )
return;
F_79 ( & V_66 -> V_70 ) ;
F_90 ( V_75 -> V_66 != V_66 ) ;
if ( ! F_68 ( & V_75 -> V_39 ) )
F_91 ( V_66 , & V_93 . V_75 , V_75 -> V_39 . V_63 ) ;
else if ( V_66 -> V_78 == V_75 )
F_91 ( V_66 , & V_93 . V_75 ,
V_66 -> V_71 . V_63 ) ;
else
V_94 = true ;
F_80 ( & V_66 -> V_70 ) ;
if ( ! V_94 )
F_55 ( & V_93 . V_25 ) ;
}
static bool F_106 ( struct V_74 * V_75 , bool V_95 ,
unsigned long * V_8 )
{
if ( V_95 ) {
struct V_84 * V_85 =
F_103 ( V_75 , struct V_84 , V_75 ) ;
struct V_65 * V_66 = V_75 -> V_66 ;
V_75 -> V_80 ++ ;
F_96 ( & V_66 -> V_70 , * V_8 ) ;
F_107 ( & V_85 -> V_88 ) ;
F_95 ( & V_66 -> V_70 , * V_8 ) ;
V_75 -> V_80 -- ;
}
if ( ! F_68 ( & V_75 -> V_39 ) ) {
F_71 ( & V_75 -> V_39 ) ;
return true ;
}
return false ;
}
bool F_108 ( struct V_65 * V_66 ,
struct V_84 * V_85 ,
unsigned long V_86 )
{
struct V_74 * V_75 = & V_85 -> V_75 ;
unsigned long V_8 ;
int V_26 = false ;
F_95 ( & V_66 -> V_70 , V_8 ) ;
if ( ! V_75 -> V_66 )
goto V_96;
F_90 ( V_75 -> V_66 != V_66 ) ;
if ( V_75 -> V_80 )
goto V_97;
V_26 = F_106 ( V_75 , true , & V_8 ) ;
V_96:
F_98 ( V_66 , V_85 , V_86 ) ;
V_97:
F_96 ( & V_66 -> V_70 , V_8 ) ;
return V_26 ;
}
static bool F_109 ( struct V_74 * V_75 , bool V_95 )
{
struct V_65 * V_66 = V_75 -> V_66 ;
unsigned long V_8 ;
int V_26 = false ;
if ( ! V_66 )
goto V_97;
F_95 ( & V_66 -> V_70 , V_8 ) ;
F_90 ( V_75 -> V_66 != V_66 ) ;
V_26 = F_106 ( V_75 , V_95 , & V_8 ) ;
if ( V_66 -> V_78 != V_75 )
goto V_98;
V_75 -> V_80 ++ ;
F_96 ( & V_66 -> V_70 , V_8 ) ;
V_92 ( V_75 ) ;
F_95 ( & V_66 -> V_70 , V_8 ) ;
V_75 -> V_80 -- ;
V_98:
F_96 ( & V_66 -> V_70 , V_8 ) ;
V_97:
return V_26 ;
}
bool F_110 ( struct V_74 * V_75 )
{
return F_109 ( V_75 , false ) ;
}
bool F_111 ( struct V_84 * V_85 )
{
return F_109 ( & V_85 -> V_75 , true ) ;
}
void F_112 ( struct V_65 * V_66 )
{
struct V_92 V_93 = {
F_104 ( V_93 . V_75 , F_102 ) ,
F_105 ( V_93 . V_25 ) ,
} ;
F_94 ( V_66 , & V_93 . V_75 ) ;
F_55 ( & V_93 . V_25 ) ;
}
void F_113 ( struct V_65 * V_66 )
{
struct V_6 * V_14 ;
V_14 = V_66 -> V_14 ;
if ( F_3 ( ! V_14 ) )
return;
F_112 ( V_66 ) ;
F_56 ( V_14 ) ;
F_3 ( ! F_68 ( & V_66 -> V_71 ) ) ;
F_5 ( V_66 ) ;
}
