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
static int F_10 ( struct V_4 * V_5 , int V_6 )
{
if ( ! F_11 ( & V_5 -> V_7 . V_8 ,
V_9 , V_6 ) )
return - V_10 ;
#ifdef F_12
if ( ! F_11 ( & V_5 -> V_7 . V_11 ,
V_9 , V_6 ) ) {
F_13 ( V_5 -> V_7 . V_8 ) ;
return - V_10 ;
}
#endif
#ifdef F_14
if ( ! F_11 ( & V_5 -> V_12 , V_9 , V_6 ) ) {
#ifdef F_12
F_13 ( V_5 -> V_7 . V_11 ) ;
#endif
F_13 ( V_5 -> V_7 . V_8 ) ;
return - V_10 ;
}
#endif
return 0 ;
}
static void F_15 ( struct V_4 * V_5 , int V_6 ,
const struct V_13 * V_8 )
{
if ( ! V_8 )
V_8 = V_2 ;
F_16 ( V_5 -> V_7 . V_8 , V_8 ) ;
#ifdef F_14
F_17 ( V_5 -> V_12 ) ;
#endif
#ifdef F_18
V_5 -> V_7 . V_6 = V_6 ;
#endif
}
static inline int
F_10 ( struct V_4 * V_5 , int V_6 ) { return 0 ; }
static inline void
F_15 ( struct V_4 * V_5 , int V_6 , const struct V_13 * V_8 ) { }
static void F_19 ( unsigned int V_14 , struct V_4 * V_5 , int V_6 ,
const struct V_13 * V_8 , struct V_15 * V_16 )
{
int V_17 ;
V_5 -> V_7 . V_18 = NULL ;
V_5 -> V_7 . V_19 = NULL ;
V_5 -> V_20 . V_21 = & V_5 -> V_7 ;
V_5 -> V_20 . V_14 = V_14 ;
V_5 -> V_20 . V_22 = & V_23 ;
V_5 -> V_20 . V_24 = NULL ;
F_20 ( V_5 , ~ 0 , V_25 ) ;
F_21 ( & V_5 -> V_20 , V_26 ) ;
F_21 ( & V_5 -> V_20 , V_27 ) ;
V_5 -> V_28 = V_29 ;
V_5 -> V_30 = 1 ;
V_5 -> V_31 = 0 ;
V_5 -> V_32 = 0 ;
V_5 -> V_33 = NULL ;
V_5 -> V_16 = V_16 ;
F_22 ( V_17 )
* F_23 ( V_5 -> V_34 , V_17 ) = 0 ;
F_15 ( V_5 , V_6 , V_8 ) ;
}
static T_2 F_24 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
int V_17 , V_14 = V_5 -> V_20 . V_14 ;
T_2 V_40 = 0 ;
char * V_41 = L_1 ;
F_22 (cpu) {
unsigned int V_42 = F_26 ( V_14 , V_17 ) ;
V_40 += F_27 ( V_39 + V_40 , V_43 - V_40 , L_2 , V_41 , V_42 ) ;
V_41 = L_3 ;
}
V_40 += F_27 ( V_39 + V_40 , V_43 - V_40 , L_4 ) ;
return V_40 ;
}
static T_2 F_28 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
T_2 V_40 = 0 ;
F_29 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_20 . V_22 && V_5 -> V_20 . V_22 -> V_33 ) {
V_40 = F_27 ( V_39 , V_43 , L_5 ,
V_5 -> V_20 . V_22 -> V_33 ) ;
}
F_30 ( & V_5 -> V_44 ) ;
return V_40 ;
}
static T_2 F_31 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
T_2 V_40 = 0 ;
F_29 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_20 . V_45 )
V_40 = sprintf ( V_39 , L_6 , ( int ) V_5 -> V_20 . V_46 ) ;
F_30 ( & V_5 -> V_44 ) ;
return V_40 ;
}
static T_2 F_32 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
T_2 V_40 = 0 ;
F_29 ( & V_5 -> V_44 ) ;
V_40 = sprintf ( V_39 , L_5 ,
F_33 ( & V_5 -> V_20 ) ? L_7 : L_8 ) ;
F_30 ( & V_5 -> V_44 ) ;
return V_40 ;
}
static T_2 F_34 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
T_2 V_40 = 0 ;
F_29 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_33 )
V_40 = F_27 ( V_39 , V_43 , L_5 , V_5 -> V_33 ) ;
F_30 ( & V_5 -> V_44 ) ;
return V_40 ;
}
static T_2 F_35 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
struct V_47 * V_48 ;
T_2 V_40 = 0 ;
char * V_41 = L_1 ;
F_29 ( & V_5 -> V_44 ) ;
for ( V_48 = V_5 -> V_48 ; V_48 != NULL ; V_48 = V_48 -> V_49 ) {
V_40 += F_27 ( V_39 + V_40 , V_43 - V_40 , L_9 ,
V_41 , V_48 -> V_33 ) ;
V_41 = L_3 ;
}
F_30 ( & V_5 -> V_44 ) ;
if ( V_40 )
V_40 += F_27 ( V_39 + V_40 , V_43 - V_40 , L_4 ) ;
return V_40 ;
}
static void F_36 ( int V_14 , struct V_4 * V_5 )
{
if ( V_50 ) {
if ( F_37 ( & V_5 -> V_36 , V_50 , L_10 , V_14 ) )
F_38 ( L_11 , V_14 ) ;
}
}
static int T_1 F_39 ( void )
{
struct V_4 * V_5 ;
int V_14 ;
F_40 () ;
V_50 = F_41 ( L_12 , V_51 ) ;
if ( ! V_50 ) {
F_42 () ;
return - V_10 ;
}
F_43 (irq, desc)
F_36 ( V_14 , V_5 ) ;
F_42 () ;
return 0 ;
}
static void F_36 ( int V_14 , struct V_4 * V_5 ) {}
static void F_44 ( unsigned int V_14 , struct V_4 * V_5 )
{
F_45 ( & V_52 , V_14 , V_5 ) ;
}
struct V_4 * F_46 ( unsigned int V_14 )
{
return F_47 ( & V_52 , V_14 ) ;
}
static void F_48 ( unsigned int V_14 )
{
F_49 ( & V_52 , V_14 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
#ifdef F_14
F_13 ( V_5 -> V_12 ) ;
#endif
F_13 ( V_5 -> V_7 . V_8 ) ;
#ifdef F_12
F_13 ( V_5 -> V_7 . V_11 ) ;
#endif
}
static inline void F_50 ( struct V_4 * V_5 ) { }
void F_40 ( void )
{
F_51 ( & V_53 ) ;
}
void F_42 ( void )
{
F_52 ( & V_53 ) ;
}
static struct V_4 * F_53 ( int V_14 , int V_6 , unsigned int V_54 ,
const struct V_13 * V_8 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 ;
V_5 = F_54 ( sizeof( * V_5 ) , V_9 , V_6 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_34 = F_55 (unsigned int) ;
if ( ! V_5 -> V_34 )
goto V_55;
if ( F_10 ( V_5 , V_6 ) )
goto V_56;
F_56 ( & V_5 -> V_44 ) ;
F_57 ( & V_5 -> V_44 , & V_57 ) ;
F_58 ( & V_5 -> V_58 ) ;
F_59 ( & V_5 -> V_59 ) ;
F_19 ( V_14 , V_5 , V_6 , V_8 , V_16 ) ;
F_21 ( & V_5 -> V_20 , V_54 ) ;
F_60 ( & V_5 -> V_36 , & V_60 ) ;
return V_5 ;
V_56:
F_61 ( V_5 -> V_34 ) ;
V_55:
F_62 ( V_5 ) ;
return NULL ;
}
static void F_63 ( struct V_35 * V_36 )
{
struct V_4 * V_5 = F_25 ( V_36 , struct V_4 , V_36 ) ;
F_50 ( V_5 ) ;
F_61 ( V_5 -> V_34 ) ;
F_62 ( V_5 ) ;
}
static void F_64 ( struct V_61 * V_62 )
{
struct V_4 * V_5 = F_25 ( V_62 , struct V_4 , V_59 ) ;
F_65 ( & V_5 -> V_36 ) ;
}
static void F_66 ( unsigned int V_14 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
F_67 ( V_5 ) ;
F_68 ( V_14 , V_5 ) ;
F_51 ( & V_53 ) ;
F_69 ( & V_5 -> V_36 ) ;
F_48 ( V_14 ) ;
F_52 ( & V_53 ) ;
F_70 ( & V_5 -> V_59 , F_64 ) ;
}
static int F_71 ( unsigned int V_63 , unsigned int V_64 , int V_6 ,
const struct V_13 * V_8 , struct V_15 * V_16 )
{
const struct V_13 * V_65 = NULL ;
struct V_4 * V_5 ;
unsigned int V_54 ;
int V_66 ;
if ( V_8 ) {
for ( V_66 = 0 , V_65 = V_8 ; V_66 < V_64 ; V_66 ++ , V_65 ++ ) {
if ( F_8 ( V_65 ) )
return - V_67 ;
}
}
V_54 = V_8 ? V_68 : 0 ;
V_65 = NULL ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ ) {
if ( V_8 ) {
V_6 = F_72 ( F_73 ( V_8 ) ) ;
V_65 = V_8 ;
V_8 ++ ;
}
V_5 = F_53 ( V_63 + V_66 , V_6 , V_54 , V_65 , V_16 ) ;
if ( ! V_5 )
goto V_69;
F_51 ( & V_53 ) ;
F_44 ( V_63 + V_66 , V_5 ) ;
F_36 ( V_63 + V_66 , V_5 ) ;
F_52 ( & V_53 ) ;
}
return V_63 ;
V_69:
for ( V_66 -- ; V_66 >= 0 ; V_66 -- )
F_66 ( V_63 + V_66 ) ;
F_51 ( & V_53 ) ;
F_74 ( V_70 , V_63 , V_64 ) ;
F_52 ( & V_53 ) ;
return - V_10 ;
}
static int F_75 ( unsigned int V_71 )
{
if ( V_71 > V_72 )
return - V_10 ;
V_73 = V_71 ;
return 0 ;
}
int T_1 F_76 ( void )
{
int V_66 , V_74 , V_6 = V_75 ;
struct V_4 * V_5 ;
F_6 () ;
V_74 = F_77 () ;
F_78 ( V_76 L_13 ,
V_77 , V_73 , V_74 ) ;
if ( F_79 ( V_73 > V_72 ) )
V_73 = V_72 ;
if ( F_79 ( V_74 > V_72 ) )
V_74 = V_72 ;
if ( V_74 > V_73 )
V_73 = V_74 ;
for ( V_66 = 0 ; V_66 < V_74 ; V_66 ++ ) {
V_5 = F_53 ( V_66 , V_6 , 0 , NULL , NULL ) ;
F_80 ( V_66 , V_70 ) ;
F_44 ( V_66 , V_5 ) ;
}
return F_81 () ;
}
int T_1 F_76 ( void )
{
int V_78 , V_66 , V_6 = V_75 ;
struct V_4 * V_5 ;
F_6 () ;
F_78 ( V_76 L_14 , V_77 ) ;
V_5 = V_4 ;
V_78 = F_82 ( V_4 ) ;
for ( V_66 = 0 ; V_66 < V_78 ; V_66 ++ ) {
V_5 [ V_66 ] . V_34 = F_55 (unsigned int) ;
F_10 ( & V_5 [ V_66 ] , V_6 ) ;
F_56 ( & V_5 [ V_66 ] . V_44 ) ;
F_57 ( & V_5 [ V_66 ] . V_44 , & V_57 ) ;
F_19 ( V_66 , & V_5 [ V_66 ] , V_6 , NULL , NULL ) ;
}
return F_81 () ;
}
struct V_4 * F_46 ( unsigned int V_14 )
{
return ( V_14 < V_77 ) ? V_4 + V_14 : NULL ;
}
static void F_66 ( unsigned int V_14 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
unsigned long V_54 ;
F_83 ( & V_5 -> V_44 , V_54 ) ;
F_19 ( V_14 , V_5 , F_84 ( V_5 ) , NULL , NULL ) ;
F_85 ( & V_5 -> V_44 , V_54 ) ;
}
static inline int F_71 ( unsigned int V_63 , unsigned int V_64 , int V_6 ,
const struct V_13 * V_8 ,
struct V_15 * V_16 )
{
T_3 V_66 ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ ) {
struct V_4 * V_5 = F_46 ( V_63 + V_66 ) ;
V_5 -> V_16 = V_16 ;
}
return V_63 ;
}
static int F_75 ( unsigned int V_71 )
{
return - V_10 ;
}
void F_86 ( unsigned int V_14 )
{
F_51 ( & V_53 ) ;
F_87 ( V_70 , V_14 , 1 ) ;
F_52 ( & V_53 ) ;
}
void F_88 ( unsigned int V_14 )
{
F_66 ( V_14 ) ;
}
int F_89 ( unsigned int V_14 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
if ( ! V_5 )
return - V_67 ;
F_90 ( V_5 ) ;
return 0 ;
}
int F_91 ( struct V_79 * V_45 , unsigned int V_46 ,
bool V_80 , struct V_81 * V_82 )
{
struct V_81 * V_83 = F_92 ( V_82 ) ;
unsigned int V_14 = V_46 ;
int V_40 = 0 ;
F_93 () ;
#ifdef F_94
if ( V_80 )
V_14 = F_95 ( V_45 , V_46 ) ;
#endif
if ( F_96 ( ! V_14 || V_14 >= V_73 ) ) {
F_97 ( V_14 ) ;
V_40 = - V_67 ;
} else {
F_89 ( V_14 ) ;
}
F_98 () ;
F_92 ( V_83 ) ;
return V_40 ;
}
void F_99 ( unsigned int V_84 , unsigned int V_64 )
{
int V_66 ;
if ( V_84 >= V_73 || ( V_84 + V_64 ) > V_73 )
return;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ )
F_66 ( V_84 + V_66 ) ;
F_51 ( & V_53 ) ;
F_74 ( V_70 , V_84 , V_64 ) ;
F_52 ( & V_53 ) ;
}
int T_4
F_100 ( int V_14 , unsigned int V_84 , unsigned int V_64 , int V_6 ,
struct V_15 * V_16 , const struct V_13 * V_8 )
{
int V_63 , V_40 ;
if ( ! V_64 )
return - V_67 ;
if ( V_14 >= 0 ) {
if ( V_84 > V_14 )
return - V_67 ;
V_84 = V_14 ;
} else {
V_84 = F_101 ( V_84 ) ;
}
F_51 ( & V_53 ) ;
V_63 = F_102 ( V_70 , V_72 ,
V_84 , V_64 , 0 ) ;
V_40 = - V_85 ;
if ( V_14 >= 0 && V_63 != V_14 )
goto V_69;
if ( V_63 + V_64 > V_73 ) {
V_40 = F_75 ( V_63 + V_64 ) ;
if ( V_40 )
goto V_69;
}
F_87 ( V_70 , V_63 , V_64 ) ;
F_52 ( & V_53 ) ;
return F_71 ( V_63 , V_64 , V_6 , V_8 , V_16 ) ;
V_69:
F_52 ( & V_53 ) ;
return V_40 ;
}
unsigned int F_103 ( int V_64 , int V_6 )
{
int V_66 , V_14 = F_100 ( - 1 , 0 , V_64 , V_6 , NULL , NULL ) ;
if ( V_14 < 0 )
return 0 ;
for ( V_66 = V_14 ; V_64 > 0 ; V_66 ++ , V_64 -- ) {
if ( F_104 ( V_66 , V_6 ) )
goto V_69;
F_105 ( V_66 , V_86 ) ;
}
return V_14 ;
V_69:
for ( V_66 -- ; V_66 >= V_14 ; V_66 -- ) {
F_106 ( V_66 , V_86 | V_87 ) ;
F_107 ( V_66 ) ;
}
F_99 ( V_14 , V_64 ) ;
return 0 ;
}
void F_108 ( unsigned int V_84 , int V_64 )
{
int V_66 , V_88 ;
for ( V_66 = V_84 , V_88 = V_64 ; V_88 > 0 ; V_66 ++ , V_88 -- ) {
F_106 ( V_66 , V_86 | V_87 ) ;
F_107 ( V_66 ) ;
}
F_99 ( V_84 , V_64 ) ;
}
unsigned int F_109 ( unsigned int V_89 )
{
return F_110 ( V_70 , V_73 , V_89 ) ;
}
struct V_4 *
F_111 ( unsigned int V_14 , unsigned long * V_54 , bool V_90 ,
unsigned int V_91 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
if ( V_5 ) {
if ( V_91 & V_92 ) {
if ( ( V_91 & V_93 ) &&
! F_112 ( V_5 ) )
return NULL ;
if ( ! ( V_91 & V_93 ) &&
F_112 ( V_5 ) )
return NULL ;
}
if ( V_90 )
F_113 ( V_5 ) ;
F_83 ( & V_5 -> V_44 , * V_54 ) ;
}
return V_5 ;
}
void F_114 ( struct V_4 * V_5 , unsigned long V_54 , bool V_90 )
{
F_85 ( & V_5 -> V_44 , V_54 ) ;
if ( V_90 )
F_115 ( V_5 ) ;
}
int F_116 ( unsigned int V_14 ,
const struct V_13 * V_8 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
if ( ! V_5 )
return - V_67 ;
if ( V_5 -> V_94 )
return - V_67 ;
V_5 -> V_94 = F_117 ( sizeof( * V_5 -> V_94 ) , V_9 ) ;
if ( ! V_5 -> V_94 )
return - V_10 ;
if ( V_8 )
V_5 -> V_95 = V_8 ;
else
V_5 -> V_95 = V_96 ;
F_118 ( V_14 ) ;
return 0 ;
}
int F_119 ( unsigned int V_14 )
{
return F_116 ( V_14 , NULL ) ;
}
int F_120 ( unsigned int V_14 , struct V_13 * V_8 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
if ( ! V_5 || ! V_5 -> V_94 )
return - V_67 ;
if ( V_8 )
F_16 ( V_8 , V_5 -> V_95 ) ;
return 0 ;
}
void F_121 ( unsigned int V_14 )
{
F_122 ( F_46 ( V_14 ) ) ;
}
unsigned int F_26 ( unsigned int V_14 , int V_17 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
return V_5 && V_5 -> V_34 ?
* F_23 ( V_5 -> V_34 , V_17 ) : 0 ;
}
unsigned int V_34 ( unsigned int V_14 )
{
struct V_4 * V_5 = F_46 ( V_14 ) ;
int V_17 ;
unsigned int V_97 = 0 ;
if ( ! V_5 || ! V_5 -> V_34 )
return 0 ;
F_22 (cpu)
V_97 += * F_23 ( V_5 -> V_34 , V_17 ) ;
return V_97 ;
}
unsigned int F_123 ( unsigned int V_14 )
{
unsigned int V_97 ;
F_40 () ;
V_97 = V_34 ( V_14 ) ;
F_42 () ;
return V_97 ;
}
