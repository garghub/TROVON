static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 -> V_4 ) ;
if ( F_5 ( V_6 ) && F_6 ( V_3 ) )
return F_2 ( V_6 ) ;
return NULL ;
}
bool F_7 ( void )
{
return F_8 ( V_7 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_9 ( void )
{
return F_8 ( V_10 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_10 ( bool * V_11 )
{
bool V_12 = false ;
F_11 () ;
if ( F_12 ( F_13 ( V_8 ) ) )
V_12 = F_14 ( true ) ;
if ( V_11 )
* V_11 = V_12 ;
return F_7 () ;
}
void * F_15 ( struct V_2 * V_13 )
{
return F_1 ( V_13 ) -> V_14 ;
}
void * F_16 ( struct V_2 * V_13 )
{
struct V_1 * V_1 = F_1 ( V_13 ) ;
void * V_14 = NULL ;
F_17 ( & V_14 , & V_1 -> V_14 , sizeof( V_14 ) ) ;
return V_14 ;
}
static void F_18 ( struct V_1 * V_15 )
{
F_19 ( V_16 ) ;
while ( F_8 ( V_10 , & V_15 -> V_9 ) ) {
if ( ! F_20 ( V_17 , & V_15 -> V_9 ) )
F_21 ( & V_15 -> V_18 ) ;
F_22 () ;
F_19 ( V_16 ) ;
}
F_23 ( V_17 , & V_15 -> V_9 ) ;
F_19 ( V_19 ) ;
}
void F_24 ( void )
{
F_18 ( F_1 ( V_8 ) ) ;
}
static int V_1 ( void * V_20 )
{
struct V_21 * V_22 = V_20 ;
int (* F_25)( void * V_14 ) = V_22 -> F_25 ;
void * V_14 = V_22 -> V_14 ;
struct V_5 * V_23 ;
struct V_1 V_15 ;
int V_24 ;
V_15 . V_9 = 0 ;
V_15 . V_14 = V_14 ;
F_26 ( & V_15 . V_25 ) ;
F_26 ( & V_15 . V_18 ) ;
V_8 -> V_4 = & V_15 . V_25 ;
V_23 = F_27 ( & V_22 -> V_23 , NULL ) ;
if ( ! V_23 ) {
F_28 ( V_22 ) ;
F_29 ( - V_26 ) ;
}
F_19 ( V_27 ) ;
V_22 -> V_28 = V_8 ;
F_21 ( V_23 ) ;
F_22 () ;
V_24 = - V_26 ;
if ( ! F_8 ( V_7 , & V_15 . V_9 ) ) {
F_18 ( & V_15 ) ;
V_24 = F_25 ( V_14 ) ;
}
F_29 ( V_24 ) ;
}
int F_30 ( struct V_2 * V_29 )
{
#ifdef F_31
if ( V_29 == V_30 )
return V_29 -> V_31 ;
#endif
return V_32 ;
}
static void F_32 ( struct V_21 * V_22 )
{
int V_33 ;
#ifdef F_31
V_8 -> V_31 = V_22 -> V_34 ;
#endif
V_33 = F_33 ( V_1 , V_22 , V_35 | V_36 | V_37 ) ;
if ( V_33 < 0 ) {
struct V_5 * V_23 = F_27 ( & V_22 -> V_23 , NULL ) ;
if ( ! V_23 ) {
F_28 ( V_22 ) ;
return;
}
V_22 -> V_28 = F_34 ( V_33 ) ;
F_21 ( V_23 ) ;
}
}
static struct V_2 * F_35 ( int (* F_25)( void * V_14 ) ,
void * V_14 , int V_34 ,
const char V_38 [] ,
T_1 args )
{
F_36 ( V_23 ) ;
struct V_2 * V_13 ;
struct V_21 * V_22 = F_37 ( sizeof( * V_22 ) ,
V_39 ) ;
if ( ! V_22 )
return F_34 ( - V_40 ) ;
V_22 -> F_25 = F_25 ;
V_22 -> V_14 = V_14 ;
V_22 -> V_34 = V_34 ;
V_22 -> V_23 = & V_23 ;
F_38 ( & V_41 ) ;
F_39 ( & V_22 -> V_42 , & V_43 ) ;
F_40 ( & V_41 ) ;
F_41 ( V_30 ) ;
if ( F_12 ( F_42 ( & V_23 ) ) ) {
if ( F_27 ( & V_22 -> V_23 , NULL ) )
return F_34 ( - V_26 ) ;
F_43 ( & V_23 ) ;
}
V_13 = V_22 -> V_28 ;
if ( ! F_44 ( V_13 ) ) {
static const struct V_44 V_45 = { . V_46 = 0 } ;
vsnprintf ( V_13 -> V_47 , sizeof( V_13 -> V_47 ) , V_38 , args ) ;
F_45 ( V_13 , V_48 , & V_45 ) ;
F_46 ( V_13 , V_49 ) ;
}
F_28 ( V_22 ) ;
return V_13 ;
}
struct V_2 * F_47 ( int (* F_25)( void * V_14 ) ,
void * V_14 , int V_34 ,
const char V_38 [] ,
... )
{
struct V_2 * V_13 ;
T_1 args ;
va_start ( args , V_38 ) ;
V_13 = F_35 ( F_25 , V_14 , V_34 , V_38 , args ) ;
va_end ( args ) ;
return V_13 ;
}
static void F_48 ( struct V_2 * V_50 , const struct V_51 * V_52 , long V_53 )
{
unsigned long V_9 ;
if ( ! F_49 ( V_50 , V_53 ) ) {
F_50 ( 1 ) ;
return;
}
F_51 ( & V_50 -> V_54 , V_9 ) ;
F_52 ( V_50 , V_52 ) ;
V_50 -> V_9 |= V_55 ;
F_53 ( & V_50 -> V_54 , V_9 ) ;
}
static void F_54 ( struct V_2 * V_50 , unsigned int V_56 , long V_53 )
{
F_48 ( V_50 , F_55 ( V_56 ) , V_53 ) ;
}
void F_56 ( struct V_2 * V_50 , const struct V_51 * V_52 )
{
F_48 ( V_50 , V_52 , V_27 ) ;
}
void F_57 ( struct V_2 * V_50 , unsigned int V_56 )
{
F_54 ( V_50 , V_56 , V_27 ) ;
}
struct V_2 * F_58 ( int (* F_25)( void * V_14 ) ,
void * V_14 , unsigned int V_56 ,
const char * V_38 )
{
struct V_2 * V_50 ;
V_50 = F_47 ( F_25 , V_14 , F_59 ( V_56 ) , V_38 ,
V_56 ) ;
if ( F_44 ( V_50 ) )
return V_50 ;
F_57 ( V_50 , V_56 ) ;
F_60 ( V_57 , & F_1 ( V_50 ) -> V_9 ) ;
F_1 ( V_50 ) -> V_56 = V_56 ;
return V_50 ;
}
static void F_61 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_23 ( V_10 , & V_1 -> V_9 ) ;
if ( F_62 ( V_17 , & V_1 -> V_9 ) ) {
if ( F_8 ( V_57 , & V_1 -> V_9 ) )
F_54 ( V_3 , V_1 -> V_56 , V_16 ) ;
F_63 ( V_3 , V_16 ) ;
}
}
void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_61 ( V_3 , V_1 ) ;
F_65 ( V_3 ) ;
}
}
int F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
int V_24 = - V_58 ;
if ( V_1 ) {
if ( ! F_8 ( V_17 , & V_1 -> V_9 ) ) {
F_60 ( V_10 , & V_1 -> V_9 ) ;
if ( V_3 != V_8 ) {
F_41 ( V_3 ) ;
F_43 ( & V_1 -> V_18 ) ;
}
}
F_65 ( V_3 ) ;
V_24 = 0 ;
}
return V_24 ;
}
int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_24 ;
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_60 ( V_7 , & V_1 -> V_9 ) ;
F_61 ( V_3 , V_1 ) ;
F_41 ( V_3 ) ;
F_43 ( & V_1 -> V_25 ) ;
F_65 ( V_3 ) ;
}
V_24 = V_3 -> V_59 ;
F_70 ( V_3 ) ;
F_71 ( V_24 ) ;
return V_24 ;
}
int F_72 ( void * V_60 )
{
struct V_2 * V_29 = V_8 ;
F_73 ( V_29 , L_1 ) ;
F_74 ( V_29 ) ;
F_46 ( V_29 , V_49 ) ;
F_75 ( V_61 [ V_62 ] ) ;
V_8 -> V_9 |= V_63 ;
for (; ; ) {
F_76 ( V_64 ) ;
if ( F_77 ( & V_43 ) )
F_22 () ;
F_19 ( V_19 ) ;
F_38 ( & V_41 ) ;
while ( ! F_77 ( & V_43 ) ) {
struct V_21 * V_22 ;
V_22 = F_78 ( V_43 . V_65 ,
struct V_21 , V_42 ) ;
F_79 ( & V_22 -> V_42 ) ;
F_40 ( & V_41 ) ;
F_32 ( V_22 ) ;
F_38 ( & V_41 ) ;
}
F_40 ( & V_41 ) ;
}
return 0 ;
}
void F_80 ( struct V_66 * V_67 ,
const char * V_68 ,
struct V_69 * V_70 )
{
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
F_81 ( & V_67 -> V_71 ) ;
F_82 ( & V_67 -> V_71 , V_70 , V_68 ) ;
F_83 ( & V_67 -> V_72 ) ;
F_83 ( & V_67 -> V_73 ) ;
}
int F_84 ( void * V_74 )
{
struct V_66 * V_67 = V_74 ;
struct V_75 * V_76 ;
F_50 ( V_67 -> V_13 && V_67 -> V_13 != V_8 ) ;
V_67 -> V_13 = V_8 ;
if ( V_67 -> V_9 & V_77 )
F_85 () ;
V_78:
F_76 ( V_64 ) ;
if ( F_7 () ) {
F_19 ( V_19 ) ;
F_86 ( & V_67 -> V_71 ) ;
V_67 -> V_13 = NULL ;
F_87 ( & V_67 -> V_71 ) ;
return 0 ;
}
V_76 = NULL ;
F_86 ( & V_67 -> V_71 ) ;
if ( ! F_77 ( & V_67 -> V_72 ) ) {
V_76 = F_88 ( & V_67 -> V_72 ,
struct V_75 , V_34 ) ;
F_79 ( & V_76 -> V_34 ) ;
}
V_67 -> V_79 = V_76 ;
F_87 ( & V_67 -> V_71 ) ;
if ( V_76 ) {
F_19 ( V_19 ) ;
V_76 -> V_80 ( V_76 ) ;
} else if ( ! F_13 ( V_8 ) )
F_22 () ;
F_89 () ;
goto V_78;
}
static struct V_66 *
F_90 ( int V_56 , unsigned int V_9 ,
const char V_38 [] , T_1 args )
{
struct V_66 * V_67 ;
struct V_2 * V_13 ;
V_67 = F_91 ( sizeof( * V_67 ) , V_39 ) ;
if ( ! V_67 )
return F_34 ( - V_40 ) ;
F_92 ( V_67 ) ;
if ( V_56 >= 0 ) {
char V_68 [ V_81 ] ;
vsnprintf ( V_68 , sizeof( V_68 ) , V_38 , args ) ;
V_13 = F_58 ( F_84 , V_67 ,
V_56 , V_68 ) ;
} else {
V_13 = F_35 ( F_84 , V_67 ,
- 1 , V_38 , args ) ;
}
if ( F_44 ( V_13 ) )
goto V_82;
V_67 -> V_9 = V_9 ;
V_67 -> V_13 = V_13 ;
F_41 ( V_13 ) ;
return V_67 ;
V_82:
F_28 ( V_67 ) ;
return F_93 ( V_13 ) ;
}
struct V_66 *
F_94 ( unsigned int V_9 , const char V_38 [] , ... )
{
struct V_66 * V_67 ;
T_1 args ;
va_start ( args , V_38 ) ;
V_67 = F_90 ( - 1 , V_9 , V_38 , args ) ;
va_end ( args ) ;
return V_67 ;
}
struct V_66 *
F_95 ( int V_56 , unsigned int V_9 ,
const char V_38 [] , ... )
{
struct V_66 * V_67 ;
T_1 args ;
va_start ( args , V_38 ) ;
V_67 = F_90 ( V_56 , V_9 , V_38 , args ) ;
va_end ( args ) ;
return V_67 ;
}
static inline bool F_96 ( struct V_66 * V_67 ,
struct V_75 * V_76 )
{
F_97 ( & V_67 -> V_71 ) ;
return ! F_77 ( & V_76 -> V_34 ) || V_76 -> V_83 ;
}
static void F_98 ( struct V_66 * V_67 ,
struct V_75 * V_76 )
{
F_97 ( & V_67 -> V_71 ) ;
F_99 ( ! F_77 ( & V_76 -> V_34 ) ) ;
F_99 ( V_76 -> V_67 && V_76 -> V_67 != V_67 ) ;
}
static void F_100 ( struct V_66 * V_67 ,
struct V_75 * V_76 ,
struct V_84 * V_85 )
{
F_98 ( V_67 , V_76 ) ;
F_39 ( & V_76 -> V_34 , V_85 ) ;
V_76 -> V_67 = V_67 ;
if ( ! V_67 -> V_79 && F_5 ( V_67 -> V_13 ) )
F_41 ( V_67 -> V_13 ) ;
}
bool F_101 ( struct V_66 * V_67 ,
struct V_75 * V_76 )
{
bool V_24 = false ;
unsigned long V_9 ;
F_102 ( & V_67 -> V_71 , V_9 ) ;
if ( ! F_96 ( V_67 , V_76 ) ) {
F_100 ( V_67 , V_76 , & V_67 -> V_72 ) ;
V_24 = true ;
}
F_103 ( & V_67 -> V_71 , V_9 ) ;
return V_24 ;
}
void F_104 ( unsigned long V_86 )
{
struct V_87 * V_88 =
(struct V_87 * ) V_86 ;
struct V_75 * V_76 = & V_88 -> V_76 ;
struct V_66 * V_67 = V_76 -> V_67 ;
if ( F_99 ( ! V_67 ) )
return;
F_38 ( & V_67 -> V_71 ) ;
F_99 ( V_76 -> V_67 != V_67 ) ;
F_99 ( F_77 ( & V_76 -> V_34 ) ) ;
F_79 ( & V_76 -> V_34 ) ;
F_100 ( V_67 , V_76 , & V_67 -> V_72 ) ;
F_40 ( & V_67 -> V_71 ) ;
}
void F_105 ( struct V_66 * V_67 ,
struct V_87 * V_88 ,
unsigned long V_89 )
{
struct V_90 * V_91 = & V_88 -> V_91 ;
struct V_75 * V_76 = & V_88 -> V_76 ;
F_99 ( V_91 -> V_92 != F_104 ||
V_91 -> V_14 != ( unsigned long ) V_88 ) ;
if ( ! V_89 ) {
F_100 ( V_67 , V_76 , & V_67 -> V_72 ) ;
return;
}
F_98 ( V_67 , V_76 ) ;
F_106 ( & V_76 -> V_34 , & V_67 -> V_73 ) ;
V_76 -> V_67 = V_67 ;
F_107 ( & V_88 -> V_91 ) ;
V_91 -> V_93 = V_94 + V_89 ;
F_108 ( V_91 ) ;
}
bool F_109 ( struct V_66 * V_67 ,
struct V_87 * V_88 ,
unsigned long V_89 )
{
struct V_75 * V_76 = & V_88 -> V_76 ;
unsigned long V_9 ;
bool V_24 = false ;
F_102 ( & V_67 -> V_71 , V_9 ) ;
if ( ! F_96 ( V_67 , V_76 ) ) {
F_105 ( V_67 , V_88 , V_89 ) ;
V_24 = true ;
}
F_103 ( & V_67 -> V_71 , V_9 ) ;
return V_24 ;
}
static void F_110 ( struct V_75 * V_76 )
{
struct V_95 * V_96 =
F_111 ( V_76 , struct V_95 , V_76 ) ;
F_21 ( & V_96 -> V_23 ) ;
}
void V_95 ( struct V_75 * V_76 )
{
struct V_95 V_96 = {
F_112 ( V_96 . V_76 , F_110 ) ,
F_113 ( V_96 . V_23 ) ,
} ;
struct V_66 * V_67 ;
bool V_97 = false ;
V_67 = V_76 -> V_67 ;
if ( ! V_67 )
return;
F_86 ( & V_67 -> V_71 ) ;
F_99 ( V_76 -> V_67 != V_67 ) ;
if ( ! F_77 ( & V_76 -> V_34 ) )
F_100 ( V_67 , & V_96 . V_76 , V_76 -> V_34 . V_65 ) ;
else if ( V_67 -> V_79 == V_76 )
F_100 ( V_67 , & V_96 . V_76 ,
V_67 -> V_72 . V_65 ) ;
else
V_97 = true ;
F_87 ( & V_67 -> V_71 ) ;
if ( ! V_97 )
F_43 ( & V_96 . V_23 ) ;
}
static bool F_114 ( struct V_75 * V_76 , bool V_98 ,
unsigned long * V_9 )
{
if ( V_98 ) {
struct V_87 * V_88 =
F_111 ( V_76 , struct V_87 , V_76 ) ;
struct V_66 * V_67 = V_76 -> V_67 ;
V_76 -> V_83 ++ ;
F_103 ( & V_67 -> V_71 , * V_9 ) ;
F_115 ( & V_88 -> V_91 ) ;
F_102 ( & V_67 -> V_71 , * V_9 ) ;
V_76 -> V_83 -- ;
}
if ( ! F_77 ( & V_76 -> V_34 ) ) {
F_79 ( & V_76 -> V_34 ) ;
return true ;
}
return false ;
}
bool F_116 ( struct V_66 * V_67 ,
struct V_87 * V_88 ,
unsigned long V_89 )
{
struct V_75 * V_76 = & V_88 -> V_76 ;
unsigned long V_9 ;
int V_24 = false ;
F_102 ( & V_67 -> V_71 , V_9 ) ;
if ( ! V_76 -> V_67 )
goto V_99;
F_99 ( V_76 -> V_67 != V_67 ) ;
if ( V_76 -> V_83 )
goto V_100;
V_24 = F_114 ( V_76 , true , & V_9 ) ;
V_99:
F_105 ( V_67 , V_88 , V_89 ) ;
V_100:
F_103 ( & V_67 -> V_71 , V_9 ) ;
return V_24 ;
}
static bool F_117 ( struct V_75 * V_76 , bool V_98 )
{
struct V_66 * V_67 = V_76 -> V_67 ;
unsigned long V_9 ;
int V_24 = false ;
if ( ! V_67 )
goto V_100;
F_102 ( & V_67 -> V_71 , V_9 ) ;
F_99 ( V_76 -> V_67 != V_67 ) ;
V_24 = F_114 ( V_76 , V_98 , & V_9 ) ;
if ( V_67 -> V_79 != V_76 )
goto V_101;
V_76 -> V_83 ++ ;
F_103 ( & V_67 -> V_71 , V_9 ) ;
V_95 ( V_76 ) ;
F_102 ( & V_67 -> V_71 , V_9 ) ;
V_76 -> V_83 -- ;
V_101:
F_103 ( & V_67 -> V_71 , V_9 ) ;
V_100:
return V_24 ;
}
bool F_118 ( struct V_75 * V_76 )
{
return F_117 ( V_76 , false ) ;
}
bool F_119 ( struct V_87 * V_88 )
{
return F_117 ( & V_88 -> V_76 , true ) ;
}
void F_120 ( struct V_66 * V_67 )
{
struct V_95 V_96 = {
F_112 ( V_96 . V_76 , F_110 ) ,
F_113 ( V_96 . V_23 ) ,
} ;
F_101 ( V_67 , & V_96 . V_76 ) ;
F_43 ( & V_96 . V_23 ) ;
}
void F_121 ( struct V_66 * V_67 )
{
struct V_2 * V_13 ;
V_13 = V_67 -> V_13 ;
if ( F_50 ( ! V_13 ) )
return;
F_120 ( V_67 ) ;
F_67 ( V_13 ) ;
F_50 ( ! F_77 ( & V_67 -> V_72 ) ) ;
F_28 ( V_67 ) ;
}
