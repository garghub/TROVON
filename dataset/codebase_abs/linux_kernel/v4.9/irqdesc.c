static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_2 , V_3 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( F_5 () , V_2 ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
#ifdef F_7
if ( ! V_2 )
F_2 ( & V_2 , V_3 ) ;
#endif
if ( F_8 ( V_2 ) )
F_9 ( V_2 ) ;
}
static void T_1 F_6 ( void )
{
}
static int F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( ! F_11 ( & V_5 -> V_8 . V_9 ,
V_6 , V_7 ) )
return - V_10 ;
#ifdef F_12
if ( ! F_11 ( & V_5 -> V_11 , V_6 , V_7 ) ) {
F_13 ( V_5 -> V_8 . V_9 ) ;
return - V_10 ;
}
#endif
return 0 ;
}
static void F_14 ( struct V_4 * V_5 , int V_7 ,
const struct V_12 * V_9 )
{
if ( ! V_9 )
V_9 = V_2 ;
F_15 ( V_5 -> V_8 . V_9 , V_9 ) ;
#ifdef F_12
F_16 ( V_5 -> V_11 ) ;
#endif
#ifdef F_17
V_5 -> V_8 . V_7 = V_7 ;
#endif
}
static inline int
F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 ) { return 0 ; }
static inline void
F_14 ( struct V_4 * V_5 , int V_7 , const struct V_12 * V_9 ) { }
static void F_18 ( unsigned int V_13 , struct V_4 * V_5 , int V_7 ,
const struct V_12 * V_9 , struct V_14 * V_15 )
{
int V_16 ;
V_5 -> V_8 . V_17 = NULL ;
V_5 -> V_8 . V_18 = NULL ;
V_5 -> V_19 . V_20 = & V_5 -> V_8 ;
V_5 -> V_19 . V_13 = V_13 ;
V_5 -> V_19 . V_21 = & V_22 ;
V_5 -> V_19 . V_23 = NULL ;
F_19 ( V_5 , ~ 0 , V_24 ) ;
F_20 ( & V_5 -> V_19 , V_25 ) ;
V_5 -> V_26 = V_27 ;
V_5 -> V_28 = 1 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 0 ;
V_5 -> V_31 = NULL ;
V_5 -> V_15 = V_15 ;
F_21 ( V_16 )
* F_22 ( V_5 -> V_32 , V_16 ) = 0 ;
F_14 ( V_5 , V_7 , V_9 ) ;
}
static T_3 F_23 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
int V_16 , V_13 = V_5 -> V_19 . V_13 ;
T_3 V_38 = 0 ;
char * V_39 = L_1 ;
F_21 (cpu) {
unsigned int V_40 = F_25 ( V_13 , V_16 ) ;
V_38 += F_26 ( V_37 + V_38 , V_41 - V_38 , L_2 , V_39 , V_40 ) ;
V_39 = L_3 ;
}
V_38 += F_26 ( V_37 + V_38 , V_41 - V_38 , L_4 ) ;
return V_38 ;
}
static T_3 F_27 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
T_3 V_38 = 0 ;
F_28 ( & V_5 -> V_42 ) ;
if ( V_5 -> V_19 . V_21 && V_5 -> V_19 . V_21 -> V_31 ) {
V_38 = F_26 ( V_37 , V_41 , L_5 ,
V_5 -> V_19 . V_21 -> V_31 ) ;
}
F_29 ( & V_5 -> V_42 ) ;
return V_38 ;
}
static T_3 F_30 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
T_3 V_38 = 0 ;
F_28 ( & V_5 -> V_42 ) ;
if ( V_5 -> V_19 . V_43 )
V_38 = sprintf ( V_37 , L_6 , ( int ) V_5 -> V_19 . V_44 ) ;
F_29 ( & V_5 -> V_42 ) ;
return V_38 ;
}
static T_3 F_31 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
T_3 V_38 = 0 ;
F_28 ( & V_5 -> V_42 ) ;
V_38 = sprintf ( V_37 , L_5 ,
F_32 ( & V_5 -> V_19 ) ? L_7 : L_8 ) ;
F_29 ( & V_5 -> V_42 ) ;
return V_38 ;
}
static T_3 F_33 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
T_3 V_38 = 0 ;
F_28 ( & V_5 -> V_42 ) ;
if ( V_5 -> V_31 )
V_38 = F_26 ( V_37 , V_41 , L_5 , V_5 -> V_31 ) ;
F_29 ( & V_5 -> V_42 ) ;
return V_38 ;
}
static T_3 F_34 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
struct V_45 * V_46 ;
T_3 V_38 = 0 ;
char * V_39 = L_1 ;
F_28 ( & V_5 -> V_42 ) ;
for ( V_46 = V_5 -> V_46 ; V_46 != NULL ; V_46 = V_46 -> V_47 ) {
V_38 += F_26 ( V_37 + V_38 , V_41 - V_38 , L_9 ,
V_39 , V_46 -> V_31 ) ;
V_39 = L_3 ;
}
F_29 ( & V_5 -> V_42 ) ;
if ( V_38 )
V_38 += F_26 ( V_37 + V_38 , V_41 - V_38 , L_4 ) ;
return V_38 ;
}
static void F_35 ( int V_13 , struct V_4 * V_5 )
{
if ( V_48 ) {
if ( F_36 ( & V_5 -> V_34 , V_48 , L_10 , V_13 ) )
F_37 ( L_11 , V_13 ) ;
}
}
static int T_1 F_38 ( void )
{
struct V_4 * V_5 ;
int V_13 ;
F_39 () ;
V_48 = F_40 ( L_12 , V_49 ) ;
if ( ! V_48 ) {
F_41 () ;
return - V_10 ;
}
F_42 (irq, desc)
F_35 ( V_13 , V_5 ) ;
F_41 () ;
return 0 ;
}
static void F_35 ( int V_13 , struct V_4 * V_5 ) {}
static void F_43 ( unsigned int V_13 , struct V_4 * V_5 )
{
F_44 ( & V_50 , V_13 , V_5 ) ;
}
struct V_4 * F_45 ( unsigned int V_13 )
{
return F_46 ( & V_50 , V_13 ) ;
}
static void F_47 ( unsigned int V_13 )
{
F_48 ( & V_50 , V_13 ) ;
}
static void F_49 ( struct V_4 * V_5 )
{
#ifdef F_12
F_13 ( V_5 -> V_11 ) ;
#endif
F_13 ( V_5 -> V_8 . V_9 ) ;
}
static inline void F_49 ( struct V_4 * V_5 ) { }
void F_39 ( void )
{
F_50 ( & V_51 ) ;
}
void F_41 ( void )
{
F_51 ( & V_51 ) ;
}
static struct V_4 * F_52 ( int V_13 , int V_7 , unsigned int V_52 ,
const struct V_12 * V_9 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 ;
T_2 V_6 = V_53 ;
V_5 = F_53 ( sizeof( * V_5 ) , V_6 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_32 = F_54 (unsigned int) ;
if ( ! V_5 -> V_32 )
goto V_54;
if ( F_10 ( V_5 , V_6 , V_7 ) )
goto V_55;
F_55 ( & V_5 -> V_42 ) ;
F_56 ( & V_5 -> V_42 , & V_56 ) ;
F_57 ( & V_5 -> V_57 ) ;
F_18 ( V_13 , V_5 , V_7 , V_9 , V_15 ) ;
F_20 ( & V_5 -> V_19 , V_52 ) ;
F_58 ( & V_5 -> V_34 , & V_58 ) ;
return V_5 ;
V_55:
F_59 ( V_5 -> V_32 ) ;
V_54:
F_60 ( V_5 ) ;
return NULL ;
}
static void F_61 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = F_24 ( V_34 , struct V_4 , V_34 ) ;
F_49 ( V_5 ) ;
F_59 ( V_5 -> V_32 ) ;
F_60 ( V_5 ) ;
}
static void F_62 ( struct V_59 * V_60 )
{
struct V_4 * V_5 = F_24 ( V_60 , struct V_4 , V_57 ) ;
F_63 ( & V_5 -> V_34 ) ;
}
static void F_64 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
F_65 ( V_13 , V_5 ) ;
F_50 ( & V_51 ) ;
F_66 ( & V_5 -> V_34 ) ;
F_47 ( V_13 ) ;
F_51 ( & V_51 ) ;
F_67 ( & V_5 -> V_57 , F_62 ) ;
}
static int F_68 ( unsigned int V_61 , unsigned int V_62 , int V_7 ,
const struct V_12 * V_9 , struct V_14 * V_15 )
{
const struct V_12 * V_63 = NULL ;
struct V_4 * V_5 ;
unsigned int V_52 ;
int V_64 ;
if ( V_9 ) {
for ( V_64 = 0 , V_63 = V_9 ; V_64 < V_62 ; V_64 ++ , V_63 ++ ) {
if ( F_8 ( V_63 ) )
return - V_65 ;
}
}
V_52 = V_9 ? V_66 : 0 ;
V_63 = NULL ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
if ( V_9 ) {
V_7 = F_69 ( F_70 ( V_9 ) ) ;
V_63 = V_9 ;
V_9 ++ ;
}
V_5 = F_52 ( V_61 + V_64 , V_7 , V_52 , V_63 , V_15 ) ;
if ( ! V_5 )
goto V_67;
F_50 ( & V_51 ) ;
F_43 ( V_61 + V_64 , V_5 ) ;
F_35 ( V_61 + V_64 , V_5 ) ;
F_51 ( & V_51 ) ;
}
return V_61 ;
V_67:
for ( V_64 -- ; V_64 >= 0 ; V_64 -- )
F_64 ( V_61 + V_64 ) ;
F_50 ( & V_51 ) ;
F_71 ( V_68 , V_61 , V_62 ) ;
F_51 ( & V_51 ) ;
return - V_10 ;
}
static int F_72 ( unsigned int V_69 )
{
if ( V_69 > V_70 )
return - V_10 ;
V_71 = V_69 ;
return 0 ;
}
int T_1 F_73 ( void )
{
int V_64 , V_72 , V_7 = V_73 ;
struct V_4 * V_5 ;
F_6 () ;
V_72 = F_74 () ;
F_75 ( V_74 L_13 , V_75 , V_71 , V_72 ) ;
if ( F_76 ( V_71 > V_70 ) )
V_71 = V_70 ;
if ( F_76 ( V_72 > V_70 ) )
V_72 = V_70 ;
if ( V_72 > V_71 )
V_71 = V_72 ;
for ( V_64 = 0 ; V_64 < V_72 ; V_64 ++ ) {
V_5 = F_52 ( V_64 , V_7 , 0 , NULL , NULL ) ;
F_77 ( V_64 , V_68 ) ;
F_43 ( V_64 , V_5 ) ;
}
return F_78 () ;
}
int T_1 F_73 ( void )
{
int V_76 , V_64 , V_7 = V_73 ;
struct V_4 * V_5 ;
F_6 () ;
F_75 ( V_74 L_14 , V_75 ) ;
V_5 = V_4 ;
V_76 = F_79 ( V_4 ) ;
for ( V_64 = 0 ; V_64 < V_76 ; V_64 ++ ) {
V_5 [ V_64 ] . V_32 = F_54 (unsigned int) ;
F_10 ( & V_5 [ V_64 ] , V_53 , V_7 ) ;
F_55 ( & V_5 [ V_64 ] . V_42 ) ;
F_56 ( & V_5 [ V_64 ] . V_42 , & V_56 ) ;
F_18 ( V_64 , & V_5 [ V_64 ] , V_7 , NULL , NULL ) ;
}
return F_78 () ;
}
struct V_4 * F_45 ( unsigned int V_13 )
{
return ( V_13 < V_75 ) ? V_4 + V_13 : NULL ;
}
static void F_64 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
unsigned long V_52 ;
F_80 ( & V_5 -> V_42 , V_52 ) ;
F_18 ( V_13 , V_5 , F_81 ( V_5 ) , NULL , NULL ) ;
F_82 ( & V_5 -> V_42 , V_52 ) ;
}
static inline int F_68 ( unsigned int V_61 , unsigned int V_62 , int V_7 ,
const struct V_12 * V_9 ,
struct V_14 * V_15 )
{
T_4 V_64 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_4 * V_5 = F_45 ( V_61 + V_64 ) ;
V_5 -> V_15 = V_15 ;
}
return V_61 ;
}
static int F_72 ( unsigned int V_69 )
{
return - V_10 ;
}
void F_83 ( unsigned int V_13 )
{
F_50 ( & V_51 ) ;
F_84 ( V_68 , V_13 , 1 ) ;
F_51 ( & V_51 ) ;
}
void F_85 ( unsigned int V_13 )
{
F_64 ( V_13 ) ;
}
int F_86 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
if ( ! V_5 )
return - V_65 ;
F_87 ( V_5 ) ;
return 0 ;
}
int F_88 ( struct V_77 * V_43 , unsigned int V_44 ,
bool V_78 , struct V_79 * V_80 )
{
struct V_79 * V_81 = F_89 ( V_80 ) ;
unsigned int V_13 = V_44 ;
int V_38 = 0 ;
F_90 () ;
#ifdef F_91
if ( V_78 )
V_13 = F_92 ( V_43 , V_44 ) ;
#endif
if ( F_93 ( ! V_13 || V_13 >= V_71 ) ) {
F_94 ( V_13 ) ;
V_38 = - V_65 ;
} else {
F_86 ( V_13 ) ;
}
F_95 () ;
F_89 ( V_81 ) ;
return V_38 ;
}
void F_96 ( unsigned int V_82 , unsigned int V_62 )
{
int V_64 ;
if ( V_82 >= V_71 || ( V_82 + V_62 ) > V_71 )
return;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ )
F_64 ( V_82 + V_64 ) ;
F_50 ( & V_51 ) ;
F_71 ( V_68 , V_82 , V_62 ) ;
F_51 ( & V_51 ) ;
}
int T_5
F_97 ( int V_13 , unsigned int V_82 , unsigned int V_62 , int V_7 ,
struct V_14 * V_15 , const struct V_12 * V_9 )
{
int V_61 , V_38 ;
if ( ! V_62 )
return - V_65 ;
if ( V_13 >= 0 ) {
if ( V_82 > V_13 )
return - V_65 ;
V_82 = V_13 ;
} else {
V_82 = F_98 ( V_82 ) ;
}
F_50 ( & V_51 ) ;
V_61 = F_99 ( V_68 , V_70 ,
V_82 , V_62 , 0 ) ;
V_38 = - V_83 ;
if ( V_13 >= 0 && V_61 != V_13 )
goto V_67;
if ( V_61 + V_62 > V_71 ) {
V_38 = F_72 ( V_61 + V_62 ) ;
if ( V_38 )
goto V_67;
}
F_84 ( V_68 , V_61 , V_62 ) ;
F_51 ( & V_51 ) ;
return F_68 ( V_61 , V_62 , V_7 , V_9 , V_15 ) ;
V_67:
F_51 ( & V_51 ) ;
return V_38 ;
}
unsigned int F_100 ( int V_62 , int V_7 )
{
int V_64 , V_13 = F_97 ( - 1 , 0 , V_62 , V_7 , NULL , NULL ) ;
if ( V_13 < 0 )
return 0 ;
for ( V_64 = V_13 ; V_62 > 0 ; V_64 ++ , V_62 -- ) {
if ( F_101 ( V_64 , V_7 ) )
goto V_67;
F_102 ( V_64 , V_84 ) ;
}
return V_13 ;
V_67:
for ( V_64 -- ; V_64 >= V_13 ; V_64 -- ) {
F_103 ( V_64 , V_84 | V_85 ) ;
F_104 ( V_64 ) ;
}
F_96 ( V_13 , V_62 ) ;
return 0 ;
}
void F_105 ( unsigned int V_82 , int V_62 )
{
int V_64 , V_86 ;
for ( V_64 = V_82 , V_86 = V_62 ; V_86 > 0 ; V_64 ++ , V_86 -- ) {
F_103 ( V_64 , V_84 | V_85 ) ;
F_104 ( V_64 ) ;
}
F_96 ( V_82 , V_62 ) ;
}
unsigned int F_106 ( unsigned int V_87 )
{
return F_107 ( V_68 , V_71 , V_87 ) ;
}
struct V_4 *
F_108 ( unsigned int V_13 , unsigned long * V_52 , bool V_88 ,
unsigned int V_89 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
if ( V_5 ) {
if ( V_89 & V_90 ) {
if ( ( V_89 & V_91 ) &&
! F_109 ( V_5 ) )
return NULL ;
if ( ! ( V_89 & V_91 ) &&
F_109 ( V_5 ) )
return NULL ;
}
if ( V_88 )
F_110 ( V_5 ) ;
F_80 ( & V_5 -> V_42 , * V_52 ) ;
}
return V_5 ;
}
void F_111 ( struct V_4 * V_5 , unsigned long V_52 , bool V_88 )
{
F_82 ( & V_5 -> V_42 , V_52 ) ;
if ( V_88 )
F_112 ( V_5 ) ;
}
int F_113 ( unsigned int V_13 ,
const struct V_12 * V_9 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
if ( ! V_5 )
return - V_65 ;
if ( V_5 -> V_92 )
return - V_65 ;
V_5 -> V_92 = F_114 ( sizeof( * V_5 -> V_92 ) , V_53 ) ;
if ( ! V_5 -> V_92 )
return - V_10 ;
if ( V_9 )
V_5 -> V_93 = V_9 ;
else
V_5 -> V_93 = V_94 ;
F_115 ( V_13 ) ;
return 0 ;
}
int F_116 ( unsigned int V_13 )
{
return F_113 ( V_13 , NULL ) ;
}
int F_117 ( unsigned int V_13 , struct V_12 * V_9 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
if ( ! V_5 || ! V_5 -> V_92 )
return - V_65 ;
if ( V_9 )
F_15 ( V_9 , V_5 -> V_93 ) ;
return 0 ;
}
void F_118 ( unsigned int V_13 )
{
F_119 ( F_45 ( V_13 ) ) ;
}
unsigned int F_25 ( unsigned int V_13 , int V_16 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
return V_5 && V_5 -> V_32 ?
* F_22 ( V_5 -> V_32 , V_16 ) : 0 ;
}
unsigned int V_32 ( unsigned int V_13 )
{
struct V_4 * V_5 = F_45 ( V_13 ) ;
int V_16 ;
unsigned int V_95 = 0 ;
if ( ! V_5 || ! V_5 -> V_32 )
return 0 ;
F_21 (cpu)
V_95 += * F_22 ( V_5 -> V_32 , V_16 ) ;
return V_95 ;
}
unsigned int F_120 ( unsigned int V_13 )
{
unsigned int V_95 ;
F_39 () ;
V_95 = V_32 ( V_13 ) ;
F_41 () ;
return V_95 ;
}
