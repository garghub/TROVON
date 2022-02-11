static inline bool F_1 ( void )
{
return V_1 -> V_2 || V_1 -> V_3 ;
}
static int T_1 F_2 ( void )
{
F_3 ( & V_4 ) ;
V_5 = true ;
return 0 ;
}
static int F_4 ( void )
{
return V_6 ;
}
void F_5 ( void )
{
V_6 = 1 ;
}
bool F_6 ( void )
{
return ! ! ( V_1 -> V_7 & V_8 ) ;
}
struct V_9 * F_7 ( struct V_10 * V_11 )
{
if ( F_6 () )
return & V_11 -> V_12 ;
else
return V_13 ;
}
static inline T_2 F_8 ( unsigned int V_14 , T_2 * V_15 )
{
T_2 V_16 ;
T_2 V_17 ;
T_2 V_18 ;
V_17 = F_9 ( F_10 () ) ;
V_18 = F_11 ( V_14 ) . V_19 [ V_20 ] ;
V_18 += F_11 ( V_14 ) . V_19 [ V_21 ] ;
V_18 += F_11 ( V_14 ) . V_19 [ V_22 ] ;
V_18 += F_11 ( V_14 ) . V_19 [ V_23 ] ;
V_18 += F_11 ( V_14 ) . V_19 [ V_24 ] ;
V_18 += F_11 ( V_14 ) . V_19 [ V_25 ] ;
V_16 = V_17 - V_18 ;
if ( V_15 )
* V_15 = F_12 ( V_17 ) ;
return F_12 ( V_16 ) ;
}
T_2 F_13 ( unsigned int V_14 , T_2 * V_15 , int V_26 )
{
T_2 V_16 = F_14 ( V_14 , V_26 ? V_15 : NULL ) ;
if ( V_16 == - 1ULL )
return F_8 ( V_14 , V_15 ) ;
else if ( ! V_26 )
V_16 += F_15 ( V_14 , V_15 ) ;
return V_16 ;
}
int F_16 ( struct V_10 * V_11 ,
struct V_27 * V_28 ,
unsigned int V_29 )
{
int V_30 ;
V_30 = F_17 ( V_11 , V_28 ) ;
if ( V_30 ) {
F_18 ( L_1 , V_31 , V_30 ) ;
return V_30 ;
}
V_11 -> V_32 . V_29 = V_29 ;
F_19 ( V_11 -> V_33 ) ;
return 0 ;
}
struct V_10 * F_20 ( unsigned int V_14 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_7 ;
if ( F_4 () || ( V_14 >= V_34 ) )
return NULL ;
if ( ! F_21 ( & V_35 ) )
return NULL ;
F_22 ( & V_36 , V_7 ) ;
if ( V_1 ) {
V_11 = F_23 ( V_37 , V_14 ) ;
if ( V_11 )
F_24 ( & V_11 -> V_12 ) ;
}
F_25 ( & V_36 , V_7 ) ;
if ( ! V_11 )
F_26 ( & V_35 ) ;
return V_11 ;
}
void F_27 ( struct V_10 * V_11 )
{
if ( F_4 () )
return;
F_28 ( & V_11 -> V_12 ) ;
F_26 ( & V_35 ) ;
}
static void F_29 ( unsigned long V_38 , struct V_39 * V_40 )
{
if ( V_40 -> V_7 & V_41 )
return;
if ( ! V_42 ) {
V_43 = V_44 ;
V_42 = V_40 -> V_45 ;
F_30 ( L_2
L_3 , V_43 , V_42 ) ;
}
if ( ( V_38 == V_46 && V_40 -> V_45 != V_40 -> V_47 ) ||
( V_38 == V_48 || V_38 == V_49 ) ) {
V_44 = F_31 ( V_43 , V_42 ,
V_40 -> V_47 ) ;
F_30 ( L_4
L_5 , V_44 , V_40 -> V_47 ) ;
}
}
static inline void F_29 ( unsigned long V_38 , struct V_39 * V_40 )
{
return;
}
static void F_32 ( struct V_10 * V_11 ,
struct V_39 * V_50 , unsigned int V_51 )
{
F_33 ( F_34 () ) ;
if ( F_4 () )
return;
V_50 -> V_7 = V_1 -> V_7 ;
F_30 ( L_6 ,
V_51 , V_50 -> V_47 ) ;
switch ( V_51 ) {
case V_52 :
if ( ! ( V_1 -> V_7 & V_41 ) ) {
if ( ( V_11 ) && ( V_11 -> V_14 == V_50 -> V_14 ) &&
( V_11 -> V_53 ) && ( V_11 -> V_53 != V_50 -> V_45 ) ) {
F_30 ( L_7
L_8 ,
V_50 -> V_45 , V_11 -> V_53 ) ;
V_50 -> V_45 = V_11 -> V_53 ;
}
}
F_35 ( & V_4 ,
V_52 , V_50 ) ;
F_29 ( V_52 , V_50 ) ;
break;
case V_46 :
F_29 ( V_46 , V_50 ) ;
F_30 ( L_9 , ( unsigned long ) V_50 -> V_47 ,
( unsigned long ) V_50 -> V_14 ) ;
F_36 ( V_50 -> V_47 , V_50 -> V_14 ) ;
F_35 ( & V_4 ,
V_46 , V_50 ) ;
if ( F_37 ( V_11 ) && F_37 ( V_11 -> V_14 == V_50 -> V_14 ) )
V_11 -> V_53 = V_50 -> V_47 ;
break;
}
}
void F_38 ( struct V_10 * V_11 ,
struct V_39 * V_50 , unsigned int V_51 )
{
F_39 (freqs->cpu, policy->cpus)
F_32 ( V_11 , V_50 , V_51 ) ;
}
static struct V_54 * F_40 ( const char * V_55 )
{
struct V_54 * V_56 ;
F_41 (t, &cpufreq_governor_list, governor_list)
if ( ! F_42 ( V_55 , V_56 -> V_57 , V_58 ) )
return V_56 ;
return NULL ;
}
static int F_43 ( char * V_55 , unsigned int * V_11 ,
struct V_54 * * V_59 )
{
int V_60 = - V_61 ;
if ( ! V_1 )
goto V_62;
if ( V_1 -> V_63 ) {
if ( ! F_42 ( V_55 , L_10 , V_58 ) ) {
* V_11 = V_64 ;
V_60 = 0 ;
} else if ( ! F_42 ( V_55 , L_11 ,
V_58 ) ) {
* V_11 = V_65 ;
V_60 = 0 ;
}
} else if ( F_1 () ) {
struct V_54 * V_56 ;
F_44 ( & V_66 ) ;
V_56 = F_40 ( V_55 ) ;
if ( V_56 == NULL ) {
int V_30 ;
F_45 ( & V_66 ) ;
V_30 = F_46 ( L_12 , V_55 ) ;
F_44 ( & V_66 ) ;
if ( V_30 == 0 )
V_56 = F_40 ( V_55 ) ;
}
if ( V_56 != NULL ) {
* V_59 = V_56 ;
V_60 = 0 ;
}
F_45 ( & V_66 ) ;
}
V_62:
return V_60 ;
}
static T_3 F_47 ( struct V_10 * V_11 ,
char * V_67 )
{
unsigned int V_68 = F_48 ( V_11 -> V_14 ) ;
if ( ! V_68 )
return sprintf ( V_67 , L_13 ) ;
return sprintf ( V_67 , L_14 , V_68 ) ;
}
static T_3 F_49 ( struct V_10 * V_11 , char * V_67 )
{
if ( V_11 -> V_11 == V_65 )
return sprintf ( V_67 , L_15 ) ;
else if ( V_11 -> V_11 == V_64 )
return sprintf ( V_67 , L_16 ) ;
else if ( V_11 -> V_59 )
return F_50 ( V_67 , V_69 , L_17 ,
V_11 -> V_59 -> V_57 ) ;
return - V_61 ;
}
static T_3 F_51 ( struct V_10 * V_11 ,
const char * V_67 , T_4 V_70 )
{
int V_30 ;
char V_55 [ 16 ] ;
struct V_10 V_71 ;
V_30 = F_52 ( & V_71 , V_11 -> V_14 ) ;
if ( V_30 )
return V_30 ;
V_30 = sscanf ( V_67 , L_18 , V_55 ) ;
if ( V_30 != 1 )
return - V_61 ;
if ( F_43 ( V_55 , & V_71 . V_11 ,
& V_71 . V_59 ) )
return - V_61 ;
V_30 = F_53 ( V_11 , & V_71 ) ;
V_11 -> V_72 . V_11 = V_11 -> V_11 ;
V_11 -> V_72 . V_59 = V_11 -> V_59 ;
if ( V_30 )
return V_30 ;
else
return V_70 ;
}
static T_3 F_54 ( struct V_10 * V_11 , char * V_67 )
{
return F_50 ( V_67 , V_69 , L_17 , V_1 -> V_57 ) ;
}
static T_3 F_55 ( struct V_10 * V_11 ,
char * V_67 )
{
T_3 V_73 = 0 ;
struct V_54 * V_56 ;
if ( ! F_1 () ) {
V_73 += sprintf ( V_67 , L_19 ) ;
goto V_62;
}
F_41 (t, &cpufreq_governor_list, governor_list) {
if ( V_73 >= ( T_3 ) ( ( V_74 / sizeof( char ) )
- ( V_58 + 2 ) ) )
goto V_62;
V_73 += F_50 ( & V_67 [ V_73 ] , V_69 , L_20 , V_56 -> V_57 ) ;
}
V_62:
V_73 += sprintf ( & V_67 [ V_73 ] , L_21 ) ;
return V_73 ;
}
T_3 F_56 ( const struct V_75 * V_76 , char * V_67 )
{
T_3 V_73 = 0 ;
unsigned int V_14 ;
F_39 (cpu, mask) {
if ( V_73 )
V_73 += F_50 ( & V_67 [ V_73 ] , ( V_74 - V_73 - 2 ) , L_22 ) ;
V_73 += F_50 ( & V_67 [ V_73 ] , ( V_74 - V_73 - 2 ) , L_23 , V_14 ) ;
if ( V_73 >= ( V_74 - 5 ) )
break;
}
V_73 += sprintf ( & V_67 [ V_73 ] , L_21 ) ;
return V_73 ;
}
static T_3 F_57 ( struct V_10 * V_11 , char * V_67 )
{
return F_56 ( V_11 -> V_77 , V_67 ) ;
}
static T_3 F_58 ( struct V_10 * V_11 , char * V_67 )
{
return F_56 ( V_11 -> V_33 , V_67 ) ;
}
static T_3 F_59 ( struct V_10 * V_11 ,
const char * V_67 , T_4 V_70 )
{
unsigned int V_78 = 0 ;
unsigned int V_30 ;
if ( ! V_11 -> V_59 || ! V_11 -> V_59 -> V_79 )
return - V_61 ;
V_30 = sscanf ( V_67 , L_23 , & V_78 ) ;
if ( V_30 != 1 )
return - V_61 ;
V_11 -> V_59 -> V_79 ( V_11 , V_78 ) ;
return V_70 ;
}
static T_3 F_60 ( struct V_10 * V_11 , char * V_67 )
{
if ( ! V_11 -> V_59 || ! V_11 -> V_59 -> V_80 )
return sprintf ( V_67 , L_24 ) ;
return V_11 -> V_59 -> V_80 ( V_11 , V_67 ) ;
}
static T_3 F_61 ( struct V_10 * V_11 , char * V_67 )
{
unsigned int V_81 ;
int V_30 ;
if ( V_1 -> V_82 ) {
V_30 = V_1 -> V_82 ( V_11 -> V_14 , & V_81 ) ;
if ( ! V_30 )
return sprintf ( V_67 , L_14 , V_81 ) ;
}
return sprintf ( V_67 , L_14 , V_11 -> V_32 . V_83 ) ;
}
static T_3 F_62 ( struct V_9 * V_12 , struct V_84 * V_85 , char * V_67 )
{
struct V_10 * V_11 = F_63 ( V_12 ) ;
struct V_86 * V_87 = F_64 ( V_85 ) ;
T_3 V_30 ;
if ( ! F_21 ( & V_35 ) )
return - V_61 ;
F_65 ( & V_11 -> V_88 ) ;
if ( V_87 -> F_62 )
V_30 = V_87 -> F_62 ( V_11 , V_67 ) ;
else
V_30 = - V_89 ;
F_26 ( & V_11 -> V_88 ) ;
F_26 ( & V_35 ) ;
return V_30 ;
}
static T_3 F_66 ( struct V_9 * V_12 , struct V_84 * V_85 ,
const char * V_67 , T_4 V_70 )
{
struct V_10 * V_11 = F_63 ( V_12 ) ;
struct V_86 * V_87 = F_64 ( V_85 ) ;
T_3 V_30 = - V_61 ;
F_67 () ;
if ( ! F_68 ( V_11 -> V_14 ) )
goto V_90;
if ( ! F_21 ( & V_35 ) )
goto V_90;
F_69 ( & V_11 -> V_88 ) ;
if ( V_87 -> F_66 )
V_30 = V_87 -> F_66 ( V_11 , V_67 , V_70 ) ;
else
V_30 = - V_89 ;
F_70 ( & V_11 -> V_88 ) ;
F_26 ( & V_35 ) ;
V_90:
F_71 () ;
return V_30 ;
}
static void F_72 ( struct V_9 * V_12 )
{
struct V_10 * V_11 = F_63 ( V_12 ) ;
F_30 ( L_25 ) ;
F_73 ( & V_11 -> V_91 ) ;
}
int F_74 ( void )
{
if ( ! V_92 ++ )
return F_75 ( V_13 ,
& V_93 . V_94 -> V_12 , L_26 , L_27 ) ;
return 0 ;
}
void F_76 ( void )
{
if ( ! -- V_92 )
F_77 ( V_13 ) ;
}
int F_78 ( const struct V_84 * V_85 )
{
int V_30 = F_74 () ;
if ( ! V_30 ) {
V_30 = F_79 ( V_13 , V_85 ) ;
if ( V_30 )
F_76 () ;
}
return V_30 ;
}
void F_80 ( const struct V_84 * V_85 )
{
F_81 ( V_13 , V_85 ) ;
F_76 () ;
}
static int F_82 ( struct V_10 * V_11 )
{
unsigned int V_95 ;
int V_30 = 0 ;
F_39 (j, policy->cpus) {
struct V_96 * V_97 ;
if ( V_95 == V_11 -> V_14 )
continue;
F_30 ( L_28 , V_95 ) ;
V_97 = F_83 ( V_95 ) ;
V_30 = F_84 ( & V_97 -> V_12 , & V_11 -> V_12 ,
L_27 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
static int F_85 ( struct V_10 * V_11 ,
struct V_96 * V_98 )
{
struct V_86 * * V_99 ;
int V_30 = 0 ;
V_30 = F_86 ( & V_11 -> V_12 , & V_100 ,
& V_98 -> V_12 , L_27 ) ;
if ( V_30 )
return V_30 ;
V_99 = V_1 -> V_85 ;
while ( ( V_99 ) && ( * V_99 ) ) {
V_30 = F_79 ( & V_11 -> V_12 , & ( ( * V_99 ) -> V_85 ) ) ;
if ( V_30 )
goto V_101;
V_99 ++ ;
}
if ( V_1 -> V_102 ) {
V_30 = F_79 ( & V_11 -> V_12 , & V_103 . V_85 ) ;
if ( V_30 )
goto V_101;
}
if ( F_1 () ) {
V_30 = F_79 ( & V_11 -> V_12 , & V_104 . V_85 ) ;
if ( V_30 )
goto V_101;
}
if ( V_1 -> V_82 ) {
V_30 = F_79 ( & V_11 -> V_12 , & V_82 . V_85 ) ;
if ( V_30 )
goto V_101;
}
V_30 = F_82 ( V_11 ) ;
if ( V_30 )
goto V_101;
return V_30 ;
V_101:
F_28 ( & V_11 -> V_12 ) ;
F_87 ( & V_11 -> V_91 ) ;
return V_30 ;
}
static void F_88 ( struct V_10 * V_11 )
{
struct V_10 V_71 ;
int V_30 = 0 ;
memcpy ( & V_71 , V_11 , sizeof( * V_11 ) ) ;
if ( V_1 -> V_63 )
F_43 ( V_11 -> V_59 -> V_57 ,
& V_71 . V_11 , NULL ) ;
V_11 -> V_59 = NULL ;
V_30 = F_53 ( V_11 , & V_71 ) ;
if ( V_30 ) {
F_30 ( L_29 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
}
}
static int F_89 ( struct V_10 * V_11 ,
unsigned int V_14 , struct V_96 * V_98 )
{
int V_30 = 0 ;
unsigned long V_7 ;
if ( F_1 () ) {
V_30 = F_90 ( V_11 , V_105 ) ;
if ( V_30 ) {
F_18 ( L_30 , V_31 ) ;
return V_30 ;
}
}
F_69 ( & V_11 -> V_88 ) ;
F_91 ( & V_36 , V_7 ) ;
F_92 ( V_14 , V_11 -> V_33 ) ;
F_23 ( V_37 , V_14 ) = V_11 ;
F_93 ( & V_36 , V_7 ) ;
F_70 ( & V_11 -> V_88 ) ;
if ( F_1 () ) {
if ( ( V_30 = F_90 ( V_11 , V_106 ) ) ||
( V_30 = F_90 ( V_11 , V_107 ) ) ) {
F_18 ( L_31 , V_31 ) ;
return V_30 ;
}
}
return F_84 ( & V_98 -> V_12 , & V_11 -> V_12 , L_27 ) ;
}
static struct V_10 * F_94 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_7 ;
F_22 ( & V_36 , V_7 ) ;
V_11 = F_23 ( V_108 , V_14 ) ;
F_25 ( & V_36 , V_7 ) ;
return V_11 ;
}
static struct V_10 * F_95 ( void )
{
struct V_10 * V_11 ;
V_11 = F_96 ( sizeof( * V_11 ) , V_109 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_97 ( & V_11 -> V_33 , V_109 ) )
goto V_110;
if ( ! F_98 ( & V_11 -> V_77 , V_109 ) )
goto V_111;
F_99 ( & V_11 -> V_112 ) ;
F_100 ( & V_11 -> V_88 ) ;
return V_11 ;
V_111:
F_101 ( V_11 -> V_33 ) ;
V_110:
F_102 ( V_11 ) ;
return NULL ;
}
static void F_103 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
struct V_113 * V_114 ;
F_65 ( & V_11 -> V_88 ) ;
V_12 = & V_11 -> V_12 ;
V_114 = & V_11 -> V_91 ;
F_26 ( & V_11 -> V_88 ) ;
F_28 ( V_12 ) ;
F_30 ( L_32 ) ;
F_87 ( V_114 ) ;
F_30 ( L_33 ) ;
}
static void F_104 ( struct V_10 * V_11 )
{
F_101 ( V_11 -> V_77 ) ;
F_101 ( V_11 -> V_33 ) ;
F_102 ( V_11 ) ;
}
static void F_105 ( struct V_10 * V_11 , unsigned int V_14 )
{
if ( F_106 ( V_14 == V_11 -> V_14 ) )
return;
F_69 ( & V_11 -> V_88 ) ;
V_11 -> V_115 = V_11 -> V_14 ;
V_11 -> V_14 = V_14 ;
F_70 ( & V_11 -> V_88 ) ;
F_107 ( V_11 ) ;
F_108 ( & V_116 ,
V_117 , V_11 ) ;
}
static int F_109 ( struct V_96 * V_98 , struct V_118 * V_119 ,
bool V_120 )
{
unsigned int V_95 , V_14 = V_98 -> V_121 ;
int V_30 = - V_122 ;
struct V_10 * V_11 ;
unsigned long V_7 ;
#ifdef F_110
struct V_10 * V_123 ;
struct V_54 * V_124 ;
#endif
if ( F_111 ( V_14 ) )
return 0 ;
F_30 ( L_34 , V_14 ) ;
#ifdef F_112
V_11 = F_20 ( V_14 ) ;
if ( F_113 ( V_11 ) ) {
F_27 ( V_11 ) ;
return 0 ;
}
#endif
if ( ! F_21 ( & V_35 ) )
return 0 ;
#ifdef F_110
F_22 ( & V_36 , V_7 ) ;
F_41 (tpolicy, &cpufreq_policy_list, policy_list) {
if ( F_114 ( V_14 , V_123 -> V_77 ) ) {
F_25 ( & V_36 , V_7 ) ;
V_30 = F_89 ( V_123 , V_14 , V_98 ) ;
F_26 ( & V_35 ) ;
return V_30 ;
}
}
F_25 ( & V_36 , V_7 ) ;
#endif
V_11 = V_120 ? F_94 ( V_14 ) : NULL ;
if ( ! V_11 ) {
V_120 = false ;
V_11 = F_95 () ;
if ( ! V_11 )
goto V_125;
}
if ( V_120 && V_14 != V_11 -> V_14 )
F_105 ( V_11 , V_14 ) ;
else
V_11 -> V_14 = V_14 ;
V_11 -> V_59 = V_126 ;
F_115 ( V_11 -> V_33 , F_116 ( V_14 ) ) ;
F_117 ( & V_11 -> V_91 ) ;
F_118 ( & V_11 -> V_127 , V_128 ) ;
V_30 = V_1 -> V_129 ( V_11 ) ;
if ( V_30 ) {
F_30 ( L_35 ) ;
goto V_130;
}
if ( V_1 -> V_102 ) {
V_11 -> V_53 = V_1 -> V_102 ( V_11 -> V_14 ) ;
if ( ! V_11 -> V_53 ) {
F_18 ( L_36 , V_31 ) ;
goto V_131;
}
}
F_119 ( V_11 -> V_77 , V_11 -> V_77 , V_11 -> V_33 ) ;
F_120 ( V_11 -> V_33 , V_11 -> V_33 , V_132 ) ;
if ( ! V_120 ) {
V_11 -> V_72 . V_133 = V_11 -> V_133 ;
V_11 -> V_72 . V_134 = V_11 -> V_134 ;
}
F_108 ( & V_116 ,
V_135 , V_11 ) ;
#ifdef F_110
V_124 = F_40 ( F_23 ( V_136 , V_14 ) ) ;
if ( V_124 ) {
V_11 -> V_59 = V_124 ;
F_30 ( L_37 ,
V_11 -> V_59 -> V_57 , V_14 ) ;
}
#endif
F_91 ( & V_36 , V_7 ) ;
F_39 (j, policy->cpus)
F_23 ( V_37 , V_95 ) = V_11 ;
F_93 ( & V_36 , V_7 ) ;
if ( ! V_120 ) {
V_30 = F_85 ( V_11 , V_98 ) ;
if ( V_30 )
goto V_137;
}
F_91 ( & V_36 , V_7 ) ;
F_121 ( & V_11 -> V_112 , & V_138 ) ;
F_93 ( & V_36 , V_7 ) ;
F_88 ( V_11 ) ;
if ( ! V_120 ) {
V_11 -> V_72 . V_11 = V_11 -> V_11 ;
V_11 -> V_72 . V_59 = V_11 -> V_59 ;
}
F_122 ( & V_11 -> V_12 , V_139 ) ;
F_26 ( & V_35 ) ;
F_30 ( L_38 ) ;
return 0 ;
V_137:
F_91 ( & V_36 , V_7 ) ;
F_39 (j, policy->cpus)
F_23 ( V_37 , V_95 ) = NULL ;
F_93 ( & V_36 , V_7 ) ;
V_131:
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
V_130:
if ( V_120 ) {
F_23 ( V_108 , V_14 ) = NULL ;
F_103 ( V_11 ) ;
}
F_104 ( V_11 ) ;
V_125:
F_26 ( & V_35 ) ;
return V_30 ;
}
static int F_123 ( struct V_96 * V_98 , struct V_118 * V_119 )
{
return F_109 ( V_98 , V_119 , false ) ;
}
static int F_124 ( struct V_10 * V_11 ,
unsigned int V_140 )
{
struct V_96 * V_97 ;
int V_30 ;
V_97 = F_83 ( F_125 ( V_11 -> V_33 , V_140 ) ) ;
F_126 ( & V_97 -> V_12 , L_27 ) ;
V_30 = F_127 ( & V_11 -> V_12 , & V_97 -> V_12 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 , V_30 ) ;
F_69 ( & V_11 -> V_88 ) ;
F_92 ( V_140 , V_11 -> V_33 ) ;
F_70 ( & V_11 -> V_88 ) ;
V_30 = F_84 ( & V_97 -> V_12 , & V_11 -> V_12 ,
L_27 ) ;
return - V_61 ;
}
return V_97 -> V_121 ;
}
static int F_128 ( struct V_96 * V_98 ,
struct V_118 * V_119 ,
bool V_120 )
{
unsigned int V_14 = V_98 -> V_121 , V_33 ;
int V_141 , V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_30 ( L_40 , V_31 , V_14 ) ;
F_91 ( & V_36 , V_7 ) ;
V_11 = F_23 ( V_37 , V_14 ) ;
if ( V_120 )
F_23 ( V_108 , V_14 ) = V_11 ;
F_93 ( & V_36 , V_7 ) ;
if ( ! V_11 ) {
F_30 ( L_41 , V_31 ) ;
return - V_61 ;
}
if ( F_1 () ) {
V_30 = F_90 ( V_11 , V_105 ) ;
if ( V_30 ) {
F_18 ( L_30 , V_31 ) ;
return V_30 ;
}
}
#ifdef F_110
if ( ! V_1 -> V_63 )
strncpy ( F_23 ( V_136 , V_14 ) ,
V_11 -> V_59 -> V_57 , V_58 ) ;
#endif
F_65 ( & V_11 -> V_88 ) ;
V_33 = F_129 ( V_11 -> V_33 ) ;
F_26 ( & V_11 -> V_88 ) ;
if ( V_14 != V_11 -> V_14 ) {
if ( ! V_120 )
F_126 ( & V_98 -> V_12 , L_27 ) ;
} else if ( V_33 > 1 ) {
V_141 = F_124 ( V_11 , V_14 ) ;
if ( V_141 >= 0 ) {
F_105 ( V_11 , V_141 ) ;
if ( ! V_120 ) {
F_30 ( L_42 ,
V_31 , V_141 , V_14 ) ;
}
}
}
return 0 ;
}
static int F_130 ( struct V_96 * V_98 ,
struct V_118 * V_119 ,
bool V_120 )
{
unsigned int V_14 = V_98 -> V_121 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_22 ( & V_36 , V_7 ) ;
V_11 = F_23 ( V_37 , V_14 ) ;
F_25 ( & V_36 , V_7 ) ;
if ( ! V_11 ) {
F_30 ( L_41 , V_31 ) ;
return - V_61 ;
}
F_69 ( & V_11 -> V_88 ) ;
V_33 = F_129 ( V_11 -> V_33 ) ;
if ( V_33 > 1 )
F_131 ( V_14 , V_11 -> V_33 ) ;
F_70 ( & V_11 -> V_88 ) ;
if ( V_33 == 1 ) {
if ( F_1 () ) {
V_30 = F_90 ( V_11 ,
V_142 ) ;
if ( V_30 ) {
F_18 ( L_43 ,
V_31 ) ;
return V_30 ;
}
}
if ( ! V_120 )
F_103 ( V_11 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
F_91 ( & V_36 , V_7 ) ;
F_132 ( & V_11 -> V_112 ) ;
F_93 ( & V_36 , V_7 ) ;
if ( ! V_120 )
F_104 ( V_11 ) ;
} else {
if ( F_1 () ) {
if ( ( V_30 = F_90 ( V_11 , V_106 ) ) ||
( V_30 = F_90 ( V_11 , V_107 ) ) ) {
F_18 ( L_31 ,
V_31 ) ;
return V_30 ;
}
}
}
F_23 ( V_37 , V_14 ) = NULL ;
return 0 ;
}
static int F_133 ( struct V_96 * V_98 , struct V_118 * V_119 )
{
unsigned int V_14 = V_98 -> V_121 ;
int V_30 ;
if ( F_111 ( V_14 ) )
return 0 ;
V_30 = F_128 ( V_98 , V_119 , false ) ;
if ( ! V_30 )
V_30 = F_130 ( V_98 , V_119 , false ) ;
return V_30 ;
}
static void V_128 ( struct V_143 * V_144 )
{
struct V_10 * V_11 =
F_134 ( V_144 , struct V_10 , V_127 ) ;
unsigned int V_14 = V_11 -> V_14 ;
F_30 ( L_44 , V_14 ) ;
F_135 ( V_14 ) ;
}
static void F_136 ( unsigned int V_14 , unsigned int V_145 ,
unsigned int V_146 )
{
struct V_10 * V_11 ;
struct V_39 V_50 ;
unsigned long V_7 ;
F_30 ( L_45
L_46 , V_145 , V_146 ) ;
V_50 . V_45 = V_145 ;
V_50 . V_47 = V_146 ;
F_22 ( & V_36 , V_7 ) ;
V_11 = F_23 ( V_37 , V_14 ) ;
F_25 ( & V_36 , V_7 ) ;
F_38 ( V_11 , & V_50 , V_52 ) ;
F_38 ( V_11 , & V_50 , V_46 ) ;
}
unsigned int F_137 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned int V_147 = 0 ;
if ( V_1 && V_1 -> V_63 && V_1 -> V_102 )
return V_1 -> V_102 ( V_14 ) ;
V_11 = F_20 ( V_14 ) ;
if ( V_11 ) {
V_147 = V_11 -> V_53 ;
F_27 ( V_11 ) ;
}
return V_147 ;
}
unsigned int F_138 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_20 ( V_14 ) ;
unsigned int V_147 = 0 ;
if ( V_11 ) {
V_147 = V_11 -> V_134 ;
F_27 ( V_11 ) ;
}
return V_147 ;
}
static unsigned int F_48 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_23 ( V_37 , V_14 ) ;
unsigned int V_147 = 0 ;
if ( ! V_1 -> V_102 )
return V_147 ;
V_147 = V_1 -> V_102 ( V_14 ) ;
if ( V_147 && V_11 -> V_53 &&
! ( V_1 -> V_7 & V_41 ) ) {
if ( F_113 ( V_147 != V_11 -> V_53 ) ) {
F_136 ( V_14 , V_11 -> V_53 , V_147 ) ;
F_139 ( & V_11 -> V_127 ) ;
}
}
return V_147 ;
}
unsigned int F_140 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_23 ( V_37 , V_14 ) ;
unsigned int V_147 = 0 ;
if ( F_4 () || ! V_1 )
return - V_148 ;
F_33 ( ! V_11 ) ;
if ( ! F_21 ( & V_35 ) )
return 0 ;
F_65 ( & V_11 -> V_88 ) ;
V_147 = F_48 ( V_14 ) ;
F_26 ( & V_11 -> V_88 ) ;
F_26 ( & V_35 ) ;
return V_147 ;
}
static int F_141 ( void )
{
int V_30 = 0 ;
int V_14 = F_142 () ;
struct V_10 * V_11 ;
F_30 ( L_47 , V_14 ) ;
V_11 = F_20 ( V_14 ) ;
if ( ! V_11 )
return 0 ;
if ( V_1 -> V_149 ) {
V_30 = V_1 -> V_149 ( V_11 ) ;
if ( V_30 )
F_143 ( V_150 L_48
L_49 , V_11 -> V_14 ) ;
}
F_27 ( V_11 ) ;
return V_30 ;
}
static void F_144 ( void )
{
int V_30 = 0 ;
int V_14 = F_142 () ;
struct V_10 * V_11 ;
F_30 ( L_50 , V_14 ) ;
V_11 = F_20 ( V_14 ) ;
if ( ! V_11 )
return;
if ( V_1 -> V_151 ) {
V_30 = V_1 -> V_151 ( V_11 ) ;
if ( V_30 ) {
F_143 ( V_150 L_51
L_49 , V_11 -> V_14 ) ;
goto V_152;
}
}
F_139 ( & V_11 -> V_127 ) ;
V_152:
F_27 ( V_11 ) ;
}
const char * F_145 ( void )
{
if ( V_1 )
return V_1 -> V_57 ;
return NULL ;
}
int F_146 ( struct V_153 * V_154 , unsigned int V_155 )
{
int V_30 ;
if ( F_4 () )
return - V_61 ;
F_106 ( ! V_5 ) ;
switch ( V_155 ) {
case V_156 :
V_30 = F_147 (
& V_4 , V_154 ) ;
break;
case V_157 :
V_30 = F_148 (
& V_116 , V_154 ) ;
break;
default:
V_30 = - V_61 ;
}
return V_30 ;
}
int F_149 ( struct V_153 * V_154 , unsigned int V_155 )
{
int V_30 ;
if ( F_4 () )
return - V_61 ;
switch ( V_155 ) {
case V_156 :
V_30 = F_150 (
& V_4 , V_154 ) ;
break;
case V_157 :
V_30 = F_151 (
& V_116 , V_154 ) ;
break;
default:
V_30 = - V_61 ;
}
return V_30 ;
}
int F_152 ( struct V_10 * V_11 ,
unsigned int V_158 ,
unsigned int V_159 )
{
int V_160 = - V_61 ;
unsigned int V_161 = V_158 ;
if ( F_4 () )
return - V_162 ;
if ( V_158 > V_11 -> V_134 )
V_158 = V_11 -> V_134 ;
if ( V_158 < V_11 -> V_133 )
V_158 = V_11 -> V_133 ;
F_30 ( L_52 ,
V_11 -> V_14 , V_158 , V_159 , V_161 ) ;
if ( V_158 == V_11 -> V_53 )
return 0 ;
if ( V_1 -> V_3 )
V_160 = V_1 -> V_3 ( V_11 , V_158 , V_159 ) ;
else if ( V_1 -> V_2 ) {
struct V_27 * V_163 ;
struct V_39 V_50 ;
bool V_164 ;
int V_165 ;
V_163 = F_153 ( V_11 -> V_14 ) ;
if ( F_113 ( ! V_163 ) ) {
F_18 ( L_53 , V_31 ) ;
goto V_62;
}
V_160 = F_154 ( V_11 , V_163 ,
V_158 , V_159 , & V_165 ) ;
if ( F_113 ( V_160 ) ) {
F_18 ( L_54 , V_31 ) ;
goto V_62;
}
if ( V_163 [ V_165 ] . V_166 == V_11 -> V_53 ) {
V_160 = 0 ;
goto V_62;
}
V_164 = ! ( V_1 -> V_7 & V_167 ) ;
if ( V_164 ) {
V_50 . V_45 = V_11 -> V_53 ;
V_50 . V_47 = V_163 [ V_165 ] . V_166 ;
V_50 . V_7 = 0 ;
F_30 ( L_55 ,
V_31 , V_11 -> V_14 , V_50 . V_45 ,
V_50 . V_47 ) ;
F_38 ( V_11 , & V_50 ,
V_52 ) ;
}
V_160 = V_1 -> V_2 ( V_11 , V_165 ) ;
if ( V_160 )
F_18 ( L_56 ,
V_31 , V_160 ) ;
if ( V_164 ) {
if ( V_160 )
V_50 . V_47 = V_50 . V_45 ;
F_38 ( V_11 , & V_50 ,
V_46 ) ;
}
}
V_62:
return V_160 ;
}
int F_155 ( struct V_10 * V_11 ,
unsigned int V_158 ,
unsigned int V_159 )
{
int V_30 = - V_61 ;
F_69 ( & V_11 -> V_88 ) ;
V_30 = F_152 ( V_11 , V_158 , V_159 ) ;
F_70 ( & V_11 -> V_88 ) ;
return V_30 ;
}
static int F_90 ( struct V_10 * V_11 ,
unsigned int V_168 )
{
int V_30 ;
#ifdef F_156
struct V_54 * V_124 = & V_169 ;
#else
struct V_54 * V_124 = NULL ;
#endif
if ( V_11 -> V_59 -> V_170 &&
V_11 -> V_32 . V_29 >
V_11 -> V_59 -> V_170 ) {
if ( ! V_124 )
return - V_61 ;
else {
F_143 ( V_171 L_57
L_58
L_59 ,
V_11 -> V_59 -> V_57 ,
V_124 -> V_57 ) ;
V_11 -> V_59 = V_124 ;
}
}
if ( V_168 == V_172 )
if ( ! F_157 ( V_11 -> V_59 -> V_173 ) )
return - V_61 ;
F_30 ( L_60 ,
V_11 -> V_14 , V_168 ) ;
F_44 ( & V_174 ) ;
if ( ( V_11 -> V_175 && V_168 == V_106 )
|| ( ! V_11 -> V_175
&& ( V_168 == V_107 || V_168 == V_105 ) ) ) {
F_45 ( & V_174 ) ;
return - V_176 ;
}
if ( V_168 == V_105 )
V_11 -> V_175 = false ;
else if ( V_168 == V_106 )
V_11 -> V_175 = true ;
F_45 ( & V_174 ) ;
V_30 = V_11 -> V_59 -> V_59 ( V_11 , V_168 ) ;
if ( ! V_30 ) {
if ( V_168 == V_172 )
V_11 -> V_59 -> V_177 ++ ;
else if ( V_168 == V_142 )
V_11 -> V_59 -> V_177 -- ;
} else {
F_44 ( & V_174 ) ;
if ( V_168 == V_105 )
V_11 -> V_175 = true ;
else if ( V_168 == V_106 )
V_11 -> V_175 = false ;
F_45 ( & V_174 ) ;
}
if ( ( ( V_168 == V_172 ) && V_30 ) ||
( ( V_168 == V_142 ) && ! V_30 ) )
F_158 ( V_11 -> V_59 -> V_173 ) ;
return V_30 ;
}
int F_159 ( struct V_54 * V_59 )
{
int V_60 ;
if ( ! V_59 )
return - V_61 ;
if ( F_4 () )
return - V_162 ;
F_44 ( & V_66 ) ;
V_59 -> V_177 = 0 ;
V_60 = - V_176 ;
if ( F_40 ( V_59 -> V_57 ) == NULL ) {
V_60 = 0 ;
F_121 ( & V_59 -> V_178 , & V_179 ) ;
}
F_45 ( & V_66 ) ;
return V_60 ;
}
void F_160 ( struct V_54 * V_59 )
{
#ifdef F_110
int V_14 ;
#endif
if ( ! V_59 )
return;
if ( F_4 () )
return;
#ifdef F_110
F_161 (cpu) {
if ( F_68 ( V_14 ) )
continue;
if ( ! strcmp ( F_23 ( V_136 , V_14 ) , V_59 -> V_57 ) )
strcpy ( F_23 ( V_136 , V_14 ) , L_61 ) ;
}
#endif
F_44 ( & V_66 ) ;
F_132 ( & V_59 -> V_178 ) ;
F_45 ( & V_66 ) ;
return;
}
int F_52 ( struct V_10 * V_11 , unsigned int V_14 )
{
struct V_10 * V_180 ;
if ( ! V_11 )
return - V_61 ;
V_180 = F_20 ( V_14 ) ;
if ( ! V_180 )
return - V_61 ;
memcpy ( V_11 , V_180 , sizeof( * V_11 ) ) ;
F_27 ( V_180 ) ;
return 0 ;
}
static int F_53 ( struct V_10 * V_11 ,
struct V_10 * V_71 )
{
int V_30 = 0 , V_181 = 1 ;
F_30 ( L_62 , V_71 -> V_14 ,
V_71 -> V_133 , V_71 -> V_134 ) ;
memcpy ( & V_71 -> V_32 , & V_11 -> V_32 , sizeof( V_11 -> V_32 ) ) ;
if ( V_71 -> V_133 > V_11 -> V_134 || V_71 -> V_134 < V_11 -> V_133 ) {
V_30 = - V_61 ;
goto V_182;
}
V_30 = V_1 -> V_183 ( V_71 ) ;
if ( V_30 )
goto V_182;
F_108 ( & V_116 ,
V_184 , V_71 ) ;
F_108 ( & V_116 ,
V_185 , V_71 ) ;
V_30 = V_1 -> V_183 ( V_71 ) ;
if ( V_30 )
goto V_182;
F_108 ( & V_116 ,
V_186 , V_71 ) ;
V_11 -> V_133 = V_71 -> V_133 ;
V_11 -> V_134 = V_71 -> V_134 ;
F_30 ( L_63 ,
V_11 -> V_133 , V_11 -> V_134 ) ;
if ( V_1 -> V_63 ) {
V_11 -> V_11 = V_71 -> V_11 ;
F_30 ( L_64 ) ;
V_30 = V_1 -> V_63 ( V_71 ) ;
} else {
if ( V_71 -> V_59 != V_11 -> V_59 ) {
struct V_54 * V_187 = V_11 -> V_59 ;
F_30 ( L_65 ) ;
if ( V_11 -> V_59 ) {
F_90 ( V_11 , V_105 ) ;
F_70 ( & V_11 -> V_88 ) ;
F_90 ( V_11 ,
V_142 ) ;
F_69 ( & V_11 -> V_88 ) ;
}
V_11 -> V_59 = V_71 -> V_59 ;
if ( ! F_90 ( V_11 , V_172 ) ) {
if ( ! F_90 ( V_11 , V_106 ) ) {
V_181 = 0 ;
} else {
F_70 ( & V_11 -> V_88 ) ;
F_90 ( V_11 ,
V_142 ) ;
F_69 ( & V_11 -> V_88 ) ;
}
}
if ( V_181 ) {
F_30 ( L_66 ,
V_11 -> V_59 -> V_57 ) ;
if ( V_187 ) {
V_11 -> V_59 = V_187 ;
F_90 ( V_11 ,
V_172 ) ;
F_90 ( V_11 ,
V_106 ) ;
}
V_30 = - V_61 ;
goto V_182;
}
}
F_30 ( L_67 ) ;
V_30 = F_90 ( V_11 , V_107 ) ;
}
V_182:
return V_30 ;
}
int F_135 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_20 ( V_14 ) ;
struct V_10 V_71 ;
int V_30 ;
if ( ! V_11 ) {
V_30 = - V_162 ;
goto V_188;
}
F_69 ( & V_11 -> V_88 ) ;
F_30 ( L_68 , V_14 ) ;
memcpy ( & V_71 , V_11 , sizeof( * V_11 ) ) ;
V_71 . V_133 = V_11 -> V_72 . V_133 ;
V_71 . V_134 = V_11 -> V_72 . V_134 ;
V_71 . V_11 = V_11 -> V_72 . V_11 ;
V_71 . V_59 = V_11 -> V_72 . V_59 ;
if ( V_1 -> V_102 ) {
V_71 . V_53 = V_1 -> V_102 ( V_14 ) ;
if ( ! V_11 -> V_53 ) {
F_30 ( L_69 ) ;
V_11 -> V_53 = V_71 . V_53 ;
} else {
if ( V_11 -> V_53 != V_71 . V_53 && F_1 () )
F_136 ( V_14 , V_11 -> V_53 ,
V_71 . V_53 ) ;
}
}
V_30 = F_53 ( V_11 , & V_71 ) ;
F_70 ( & V_11 -> V_88 ) ;
F_27 ( V_11 ) ;
V_188:
return V_30 ;
}
static int F_162 ( struct V_153 * V_189 ,
unsigned long V_190 , void * V_191 )
{
unsigned int V_14 = ( unsigned long ) V_191 ;
struct V_96 * V_98 ;
bool V_120 = false ;
V_98 = F_83 ( V_14 ) ;
if ( V_98 ) {
if ( V_190 & V_192 )
V_120 = true ;
switch ( V_190 & ~ V_192 ) {
case V_193 :
F_109 ( V_98 , NULL , V_120 ) ;
F_135 ( V_14 ) ;
break;
case V_194 :
F_128 ( V_98 , NULL , V_120 ) ;
break;
case V_195 :
F_130 ( V_98 , NULL , V_120 ) ;
break;
case V_196 :
F_109 ( V_98 , NULL , V_120 ) ;
break;
}
}
return V_197 ;
}
int F_163 ( struct V_1 * V_198 )
{
unsigned long V_7 ;
int V_30 ;
if ( F_4 () )
return - V_162 ;
if ( ! V_198 || ! V_198 -> V_183 || ! V_198 -> V_129 ||
! ( V_198 -> V_63 || V_198 -> V_2 ||
V_198 -> V_3 ) )
return - V_61 ;
F_30 ( L_70 , V_198 -> V_57 ) ;
if ( V_198 -> V_63 )
V_198 -> V_7 |= V_41 ;
F_91 ( & V_36 , V_7 ) ;
if ( V_1 ) {
F_93 ( & V_36 , V_7 ) ;
return - V_199 ;
}
V_1 = V_198 ;
F_93 ( & V_36 , V_7 ) ;
V_30 = F_164 ( & V_200 ) ;
if ( V_30 )
goto V_201;
if ( ! ( V_1 -> V_7 & V_202 ) ) {
int V_73 ;
V_30 = - V_162 ;
for ( V_73 = 0 ; V_73 < V_34 ; V_73 ++ )
if ( F_165 ( V_73 ) && F_23 ( V_37 , V_73 ) ) {
V_30 = 0 ;
break;
}
if ( V_30 ) {
F_30 ( L_71 ,
V_198 -> V_57 ) ;
goto V_203;
}
}
F_166 ( & V_204 ) ;
F_30 ( L_72 , V_198 -> V_57 ) ;
return 0 ;
V_203:
F_167 ( & V_200 ) ;
V_201:
F_91 ( & V_36 , V_7 ) ;
V_1 = NULL ;
F_93 ( & V_36 , V_7 ) ;
return V_30 ;
}
int F_168 ( struct V_1 * V_205 )
{
unsigned long V_7 ;
if ( ! V_1 || ( V_205 != V_1 ) )
return - V_61 ;
F_30 ( L_73 , V_205 -> V_57 ) ;
F_167 ( & V_200 ) ;
F_169 ( & V_204 ) ;
F_69 ( & V_35 ) ;
F_91 ( & V_36 , V_7 ) ;
V_1 = NULL ;
F_93 ( & V_36 , V_7 ) ;
F_70 ( & V_35 ) ;
return 0 ;
}
static int T_1 F_170 ( void )
{
if ( F_4 () )
return - V_162 ;
V_13 = F_171 () ;
F_33 ( ! V_13 ) ;
F_172 ( & V_206 ) ;
return 0 ;
}
