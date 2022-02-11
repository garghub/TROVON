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
unsigned int F_20 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_21 ( V_34 , V_14 ) ;
if ( ! V_11 || F_22 ( V_11 -> V_35 ) ) {
F_18 ( L_2 , V_31 ,
V_11 ? L_3 : L_4 , V_14 ) ;
return 0 ;
}
return F_23 ( V_11 -> V_35 ) / 1000 ;
}
struct V_10 * F_24 ( unsigned int V_14 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_7 ;
if ( F_4 () || ( V_14 >= V_36 ) )
return NULL ;
if ( ! F_25 ( & V_37 ) )
return NULL ;
F_26 ( & V_38 , V_7 ) ;
if ( V_1 ) {
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_11 )
F_27 ( & V_11 -> V_12 ) ;
}
F_28 ( & V_38 , V_7 ) ;
if ( ! V_11 )
F_29 ( & V_37 ) ;
return V_11 ;
}
void F_30 ( struct V_10 * V_11 )
{
if ( F_4 () )
return;
F_31 ( & V_11 -> V_12 ) ;
F_29 ( & V_37 ) ;
}
static void F_32 ( unsigned long V_39 , struct V_40 * V_41 )
{
if ( V_41 -> V_7 & V_42 )
return;
if ( ! V_43 ) {
V_44 = V_45 ;
V_43 = V_41 -> V_46 ;
F_33 ( L_5
L_6 , V_44 , V_43 ) ;
}
if ( ( V_39 == V_47 && V_41 -> V_46 != V_41 -> V_48 ) ||
( V_39 == V_49 || V_39 == V_50 ) ) {
V_45 = F_34 ( V_44 , V_43 ,
V_41 -> V_48 ) ;
F_33 ( L_7
L_8 , V_45 , V_41 -> V_48 ) ;
}
}
static inline void F_32 ( unsigned long V_39 , struct V_40 * V_41 )
{
return;
}
static void F_35 ( struct V_10 * V_11 ,
struct V_40 * V_51 , unsigned int V_52 )
{
F_36 ( F_37 () ) ;
if ( F_4 () )
return;
V_51 -> V_7 = V_1 -> V_7 ;
F_33 ( L_9 ,
V_52 , V_51 -> V_48 ) ;
switch ( V_52 ) {
case V_53 :
if ( ! ( V_1 -> V_7 & V_42 ) ) {
if ( ( V_11 ) && ( V_11 -> V_14 == V_51 -> V_14 ) &&
( V_11 -> V_54 ) && ( V_11 -> V_54 != V_51 -> V_46 ) ) {
F_33 ( L_10
L_11 ,
V_51 -> V_46 , V_11 -> V_54 ) ;
V_51 -> V_46 = V_11 -> V_54 ;
}
}
F_38 ( & V_4 ,
V_53 , V_51 ) ;
F_32 ( V_53 , V_51 ) ;
break;
case V_47 :
F_32 ( V_47 , V_51 ) ;
F_33 ( L_12 , ( unsigned long ) V_51 -> V_48 ,
( unsigned long ) V_51 -> V_14 ) ;
F_39 ( V_51 -> V_48 , V_51 -> V_14 ) ;
F_38 ( & V_4 ,
V_47 , V_51 ) ;
if ( F_40 ( V_11 ) && F_40 ( V_11 -> V_14 == V_51 -> V_14 ) )
V_11 -> V_54 = V_51 -> V_48 ;
break;
}
}
void F_41 ( struct V_10 * V_11 ,
struct V_40 * V_51 , unsigned int V_52 )
{
F_42 (freqs->cpu, policy->cpus)
F_35 ( V_11 , V_51 , V_52 ) ;
}
void F_43 ( struct V_10 * V_11 ,
struct V_40 * V_51 , int V_55 )
{
F_41 ( V_11 , V_51 , V_47 ) ;
if ( ! V_55 )
return;
F_44 ( V_51 -> V_46 , V_51 -> V_48 ) ;
F_41 ( V_11 , V_51 , V_53 ) ;
F_41 ( V_11 , V_51 , V_47 ) ;
}
T_3 F_45 ( struct V_9 * V_12 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_13 , V_1 -> V_59 ) ;
}
static T_3 F_46 ( struct V_9 * V_12 , struct V_56 * V_57 ,
const char * V_58 , T_4 V_60 )
{
int V_30 , V_61 ;
V_30 = sscanf ( V_58 , L_14 , & V_61 ) ;
if ( V_30 != 1 || V_61 < 0 || V_61 > 1 )
return - V_62 ;
if ( F_47 ( V_61 ) ) {
F_18 ( L_15 , V_31 ,
V_61 ? L_16 : L_17 ) ;
return - V_62 ;
}
F_33 ( L_18 , V_31 ,
V_61 ? L_19 : L_20 ) ;
return V_60 ;
}
static struct V_63 * F_48 ( const char * V_64 )
{
struct V_63 * V_65 ;
F_49 (t, &cpufreq_governor_list, governor_list)
if ( ! F_50 ( V_64 , V_65 -> V_66 , V_67 ) )
return V_65 ;
return NULL ;
}
static int F_51 ( char * V_64 , unsigned int * V_11 ,
struct V_63 * * V_68 )
{
int V_69 = - V_62 ;
if ( ! V_1 )
goto V_70;
if ( V_1 -> V_71 ) {
if ( ! F_50 ( V_64 , L_21 , V_67 ) ) {
* V_11 = V_72 ;
V_69 = 0 ;
} else if ( ! F_50 ( V_64 , L_22 ,
V_67 ) ) {
* V_11 = V_73 ;
V_69 = 0 ;
}
} else if ( F_1 () ) {
struct V_63 * V_65 ;
F_52 ( & V_74 ) ;
V_65 = F_48 ( V_64 ) ;
if ( V_65 == NULL ) {
int V_30 ;
F_53 ( & V_74 ) ;
V_30 = F_54 ( L_23 , V_64 ) ;
F_52 ( & V_74 ) ;
if ( V_30 == 0 )
V_65 = F_48 ( V_64 ) ;
}
if ( V_65 != NULL ) {
* V_68 = V_65 ;
V_69 = 0 ;
}
F_53 ( & V_74 ) ;
}
V_70:
return V_69 ;
}
static T_3 F_55 ( struct V_10 * V_11 ,
char * V_58 )
{
unsigned int V_75 = F_56 ( V_11 -> V_14 ) ;
if ( ! V_75 )
return sprintf ( V_58 , L_24 ) ;
return sprintf ( V_58 , L_25 , V_75 ) ;
}
static T_3 F_57 ( struct V_10 * V_11 , char * V_58 )
{
if ( V_11 -> V_11 == V_73 )
return sprintf ( V_58 , L_26 ) ;
else if ( V_11 -> V_11 == V_72 )
return sprintf ( V_58 , L_27 ) ;
else if ( V_11 -> V_68 )
return F_58 ( V_58 , V_76 , L_28 ,
V_11 -> V_68 -> V_66 ) ;
return - V_62 ;
}
static T_3 F_59 ( struct V_10 * V_11 ,
const char * V_58 , T_4 V_60 )
{
int V_30 ;
char V_64 [ 16 ] ;
struct V_10 V_77 ;
V_30 = F_60 ( & V_77 , V_11 -> V_14 ) ;
if ( V_30 )
return V_30 ;
V_30 = sscanf ( V_58 , L_29 , V_64 ) ;
if ( V_30 != 1 )
return - V_62 ;
if ( F_51 ( V_64 , & V_77 . V_11 ,
& V_77 . V_68 ) )
return - V_62 ;
V_30 = F_61 ( V_11 , & V_77 ) ;
V_11 -> V_78 . V_11 = V_11 -> V_11 ;
V_11 -> V_78 . V_68 = V_11 -> V_68 ;
if ( V_30 )
return V_30 ;
else
return V_60 ;
}
static T_3 F_62 ( struct V_10 * V_11 , char * V_58 )
{
return F_58 ( V_58 , V_76 , L_28 , V_1 -> V_66 ) ;
}
static T_3 F_63 ( struct V_10 * V_11 ,
char * V_58 )
{
T_3 V_79 = 0 ;
struct V_63 * V_65 ;
if ( ! F_1 () ) {
V_79 += sprintf ( V_58 , L_30 ) ;
goto V_70;
}
F_49 (t, &cpufreq_governor_list, governor_list) {
if ( V_79 >= ( T_3 ) ( ( V_80 / sizeof( char ) )
- ( V_67 + 2 ) ) )
goto V_70;
V_79 += F_58 ( & V_58 [ V_79 ] , V_76 , L_31 , V_65 -> V_66 ) ;
}
V_70:
V_79 += sprintf ( & V_58 [ V_79 ] , L_32 ) ;
return V_79 ;
}
T_3 F_64 ( const struct V_81 * V_82 , char * V_58 )
{
T_3 V_79 = 0 ;
unsigned int V_14 ;
F_42 (cpu, mask) {
if ( V_79 )
V_79 += F_58 ( & V_58 [ V_79 ] , ( V_80 - V_79 - 2 ) , L_33 ) ;
V_79 += F_58 ( & V_58 [ V_79 ] , ( V_80 - V_79 - 2 ) , L_34 , V_14 ) ;
if ( V_79 >= ( V_80 - 5 ) )
break;
}
V_79 += sprintf ( & V_58 [ V_79 ] , L_32 ) ;
return V_79 ;
}
static T_3 F_65 ( struct V_10 * V_11 , char * V_58 )
{
return F_64 ( V_11 -> V_83 , V_58 ) ;
}
static T_3 F_66 ( struct V_10 * V_11 , char * V_58 )
{
return F_64 ( V_11 -> V_33 , V_58 ) ;
}
static T_3 F_67 ( struct V_10 * V_11 ,
const char * V_58 , T_4 V_60 )
{
unsigned int V_84 = 0 ;
unsigned int V_30 ;
if ( ! V_11 -> V_68 || ! V_11 -> V_68 -> V_85 )
return - V_62 ;
V_30 = sscanf ( V_58 , L_34 , & V_84 ) ;
if ( V_30 != 1 )
return - V_62 ;
V_11 -> V_68 -> V_85 ( V_11 , V_84 ) ;
return V_60 ;
}
static T_3 F_68 ( struct V_10 * V_11 , char * V_58 )
{
if ( ! V_11 -> V_68 || ! V_11 -> V_68 -> V_86 )
return sprintf ( V_58 , L_35 ) ;
return V_11 -> V_68 -> V_86 ( V_11 , V_58 ) ;
}
static T_3 F_69 ( struct V_10 * V_11 , char * V_58 )
{
unsigned int V_87 ;
int V_30 ;
if ( V_1 -> V_88 ) {
V_30 = V_1 -> V_88 ( V_11 -> V_14 , & V_87 ) ;
if ( ! V_30 )
return sprintf ( V_58 , L_25 , V_87 ) ;
}
return sprintf ( V_58 , L_25 , V_11 -> V_32 . V_89 ) ;
}
static T_3 F_70 ( struct V_9 * V_12 , struct V_56 * V_57 , char * V_58 )
{
struct V_10 * V_11 = F_71 ( V_12 ) ;
struct V_90 * V_91 = F_72 ( V_57 ) ;
T_3 V_30 ;
if ( ! F_25 ( & V_37 ) )
return - V_62 ;
F_73 ( & V_11 -> V_92 ) ;
if ( V_91 -> F_70 )
V_30 = V_91 -> F_70 ( V_11 , V_58 ) ;
else
V_30 = - V_93 ;
F_29 ( & V_11 -> V_92 ) ;
F_29 ( & V_37 ) ;
return V_30 ;
}
static T_3 F_74 ( struct V_9 * V_12 , struct V_56 * V_57 ,
const char * V_58 , T_4 V_60 )
{
struct V_10 * V_11 = F_71 ( V_12 ) ;
struct V_90 * V_91 = F_72 ( V_57 ) ;
T_3 V_30 = - V_62 ;
F_75 () ;
if ( ! F_76 ( V_11 -> V_14 ) )
goto V_94;
if ( ! F_25 ( & V_37 ) )
goto V_94;
F_77 ( & V_11 -> V_92 ) ;
if ( V_91 -> F_74 )
V_30 = V_91 -> F_74 ( V_11 , V_58 , V_60 ) ;
else
V_30 = - V_93 ;
F_78 ( & V_11 -> V_92 ) ;
F_29 ( & V_37 ) ;
V_94:
F_79 () ;
return V_30 ;
}
static void F_80 ( struct V_9 * V_12 )
{
struct V_10 * V_11 = F_71 ( V_12 ) ;
F_33 ( L_36 ) ;
F_81 ( & V_11 -> V_95 ) ;
}
int F_82 ( void )
{
if ( ! V_96 ++ )
return F_83 ( V_13 ,
& V_97 . V_98 -> V_12 , L_37 , L_38 ) ;
return 0 ;
}
void F_84 ( void )
{
if ( ! -- V_96 )
F_85 ( V_13 ) ;
}
int F_86 ( const struct V_56 * V_57 )
{
int V_30 = F_82 () ;
if ( ! V_30 ) {
V_30 = F_87 ( V_13 , V_57 ) ;
if ( V_30 )
F_84 () ;
}
return V_30 ;
}
void F_88 ( const struct V_56 * V_57 )
{
F_89 ( V_13 , V_57 ) ;
F_84 () ;
}
static int F_90 ( struct V_10 * V_11 )
{
unsigned int V_99 ;
int V_30 = 0 ;
F_42 (j, policy->cpus) {
struct V_100 * V_101 ;
if ( V_99 == V_11 -> V_14 )
continue;
F_33 ( L_39 , V_99 ) ;
V_101 = F_91 ( V_99 ) ;
V_30 = F_92 ( & V_101 -> V_12 , & V_11 -> V_12 ,
L_38 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
static int F_93 ( struct V_10 * V_11 ,
struct V_100 * V_102 )
{
struct V_90 * * V_103 ;
int V_30 = 0 ;
V_30 = F_94 ( & V_11 -> V_12 , & V_104 ,
& V_102 -> V_12 , L_38 ) ;
if ( V_30 )
return V_30 ;
V_103 = V_1 -> V_57 ;
while ( ( V_103 ) && ( * V_103 ) ) {
V_30 = F_87 ( & V_11 -> V_12 , & ( ( * V_103 ) -> V_57 ) ) ;
if ( V_30 )
goto V_105;
V_103 ++ ;
}
if ( V_1 -> V_106 ) {
V_30 = F_87 ( & V_11 -> V_12 , & V_107 . V_57 ) ;
if ( V_30 )
goto V_105;
}
if ( F_1 () ) {
V_30 = F_87 ( & V_11 -> V_12 , & V_108 . V_57 ) ;
if ( V_30 )
goto V_105;
}
if ( V_1 -> V_88 ) {
V_30 = F_87 ( & V_11 -> V_12 , & V_88 . V_57 ) ;
if ( V_30 )
goto V_105;
}
V_30 = F_90 ( V_11 ) ;
if ( V_30 )
goto V_105;
return V_30 ;
V_105:
F_31 ( & V_11 -> V_12 ) ;
F_95 ( & V_11 -> V_95 ) ;
return V_30 ;
}
static void F_96 ( struct V_10 * V_11 )
{
struct V_10 V_77 ;
int V_30 = 0 ;
memcpy ( & V_77 , V_11 , sizeof( * V_11 ) ) ;
if ( V_1 -> V_71 )
F_51 ( V_11 -> V_68 -> V_66 ,
& V_77 . V_11 , NULL ) ;
V_11 -> V_68 = NULL ;
V_30 = F_61 ( V_11 , & V_77 ) ;
if ( V_30 ) {
F_33 ( L_40 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
}
}
static int F_97 ( struct V_10 * V_11 ,
unsigned int V_14 , struct V_100 * V_102 )
{
int V_30 = 0 ;
unsigned long V_7 ;
if ( F_1 () ) {
V_30 = F_98 ( V_11 , V_109 ) ;
if ( V_30 ) {
F_18 ( L_41 , V_31 ) ;
return V_30 ;
}
}
F_77 ( & V_11 -> V_92 ) ;
F_99 ( & V_38 , V_7 ) ;
F_100 ( V_14 , V_11 -> V_33 ) ;
F_21 ( V_34 , V_14 ) = V_11 ;
F_101 ( & V_38 , V_7 ) ;
F_78 ( & V_11 -> V_92 ) ;
if ( F_1 () ) {
if ( ( V_30 = F_98 ( V_11 , V_110 ) ) ||
( V_30 = F_98 ( V_11 , V_111 ) ) ) {
F_18 ( L_42 , V_31 ) ;
return V_30 ;
}
}
return F_92 ( & V_102 -> V_12 , & V_11 -> V_12 , L_38 ) ;
}
static struct V_10 * F_102 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_7 ;
F_26 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_112 , V_14 ) ;
F_28 ( & V_38 , V_7 ) ;
return V_11 ;
}
static struct V_10 * F_103 ( void )
{
struct V_10 * V_11 ;
V_11 = F_104 ( sizeof( * V_11 ) , V_113 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_105 ( & V_11 -> V_33 , V_113 ) )
goto V_114;
if ( ! F_106 ( & V_11 -> V_83 , V_113 ) )
goto V_115;
F_107 ( & V_11 -> V_116 ) ;
F_108 ( & V_11 -> V_92 ) ;
return V_11 ;
V_115:
F_109 ( V_11 -> V_33 ) ;
V_114:
F_110 ( V_11 ) ;
return NULL ;
}
static void F_111 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
struct V_117 * V_118 ;
F_112 ( & V_119 ,
V_120 , V_11 ) ;
F_73 ( & V_11 -> V_92 ) ;
V_12 = & V_11 -> V_12 ;
V_118 = & V_11 -> V_95 ;
F_29 ( & V_11 -> V_92 ) ;
F_31 ( V_12 ) ;
F_33 ( L_43 ) ;
F_95 ( V_118 ) ;
F_33 ( L_44 ) ;
}
static void F_113 ( struct V_10 * V_11 )
{
F_109 ( V_11 -> V_83 ) ;
F_109 ( V_11 -> V_33 ) ;
F_110 ( V_11 ) ;
}
static void F_114 ( struct V_10 * V_11 , unsigned int V_14 )
{
if ( F_115 ( V_14 == V_11 -> V_14 ) )
return;
F_77 ( & V_11 -> V_92 ) ;
V_11 -> V_121 = V_11 -> V_14 ;
V_11 -> V_14 = V_14 ;
F_78 ( & V_11 -> V_92 ) ;
F_116 ( V_11 ) ;
F_112 ( & V_119 ,
V_122 , V_11 ) ;
}
static int F_117 ( struct V_100 * V_102 , struct V_123 * V_124 ,
bool V_125 )
{
unsigned int V_99 , V_14 = V_102 -> V_126 ;
int V_30 = - V_127 ;
struct V_10 * V_11 ;
unsigned long V_7 ;
#ifdef F_118
struct V_10 * V_128 ;
struct V_63 * V_129 ;
#endif
if ( F_119 ( V_14 ) )
return 0 ;
F_33 ( L_45 , V_14 ) ;
#ifdef F_120
V_11 = F_24 ( V_14 ) ;
if ( F_121 ( V_11 ) ) {
F_30 ( V_11 ) ;
return 0 ;
}
#endif
if ( ! F_25 ( & V_37 ) )
return 0 ;
#ifdef F_118
F_26 ( & V_38 , V_7 ) ;
F_49 (tpolicy, &cpufreq_policy_list, policy_list) {
if ( F_122 ( V_14 , V_128 -> V_83 ) ) {
F_28 ( & V_38 , V_7 ) ;
V_30 = F_97 ( V_128 , V_14 , V_102 ) ;
F_29 ( & V_37 ) ;
return V_30 ;
}
}
F_28 ( & V_38 , V_7 ) ;
#endif
V_11 = V_125 ? F_102 ( V_14 ) : NULL ;
if ( ! V_11 ) {
V_125 = false ;
V_11 = F_103 () ;
if ( ! V_11 )
goto V_130;
}
if ( V_125 && V_14 != V_11 -> V_14 )
F_114 ( V_11 , V_14 ) ;
else
V_11 -> V_14 = V_14 ;
V_11 -> V_68 = V_131 ;
F_123 ( V_11 -> V_33 , F_124 ( V_14 ) ) ;
F_125 ( & V_11 -> V_95 ) ;
F_126 ( & V_11 -> V_132 , V_133 ) ;
V_30 = V_1 -> V_134 ( V_11 ) ;
if ( V_30 ) {
F_33 ( L_46 ) ;
goto V_135;
}
F_127 ( V_11 -> V_83 , V_11 -> V_83 , V_11 -> V_33 ) ;
F_128 ( V_11 -> V_33 , V_11 -> V_33 , V_136 ) ;
if ( ! V_125 ) {
V_11 -> V_78 . V_137 = V_11 -> V_137 ;
V_11 -> V_78 . V_138 = V_11 -> V_138 ;
}
F_77 ( & V_11 -> V_92 ) ;
F_99 ( & V_38 , V_7 ) ;
F_42 (j, policy->cpus)
F_21 ( V_34 , V_99 ) = V_11 ;
F_101 ( & V_38 , V_7 ) ;
if ( V_1 -> V_106 && ! V_1 -> V_71 ) {
V_11 -> V_54 = V_1 -> V_106 ( V_11 -> V_14 ) ;
if ( ! V_11 -> V_54 ) {
F_18 ( L_47 , V_31 ) ;
goto V_139;
}
}
if ( ( V_1 -> V_7 & V_140 )
&& F_1 () ) {
V_30 = F_129 ( V_11 , V_11 -> V_54 ) ;
if ( V_30 == - V_62 ) {
F_130 ( L_48 ,
V_31 , V_11 -> V_14 , V_11 -> V_54 ) ;
V_30 = F_131 ( V_11 , V_11 -> V_54 - 1 ,
V_141 ) ;
F_36 ( V_30 ) ;
F_130 ( L_49 ,
V_31 , V_11 -> V_14 , V_11 -> V_54 ) ;
}
}
F_112 ( & V_119 ,
V_142 , V_11 ) ;
#ifdef F_118
V_129 = F_48 ( F_21 ( V_143 , V_14 ) ) ;
if ( V_129 ) {
V_11 -> V_68 = V_129 ;
F_33 ( L_50 ,
V_11 -> V_68 -> V_66 , V_14 ) ;
}
#endif
if ( ! V_125 ) {
V_30 = F_93 ( V_11 , V_102 ) ;
if ( V_30 )
goto V_144;
F_112 ( & V_119 ,
V_145 , V_11 ) ;
}
F_99 ( & V_38 , V_7 ) ;
F_132 ( & V_11 -> V_116 , & V_146 ) ;
F_101 ( & V_38 , V_7 ) ;
F_96 ( V_11 ) ;
if ( ! V_125 ) {
V_11 -> V_78 . V_11 = V_11 -> V_11 ;
V_11 -> V_78 . V_68 = V_11 -> V_68 ;
}
F_78 ( & V_11 -> V_92 ) ;
F_133 ( & V_11 -> V_12 , V_147 ) ;
F_29 ( & V_37 ) ;
F_33 ( L_51 ) ;
return 0 ;
V_144:
V_139:
F_99 ( & V_38 , V_7 ) ;
F_42 (j, policy->cpus)
F_21 ( V_34 , V_99 ) = NULL ;
F_101 ( & V_38 , V_7 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
V_135:
if ( V_125 ) {
F_21 ( V_112 , V_14 ) = NULL ;
F_111 ( V_11 ) ;
}
F_113 ( V_11 ) ;
V_130:
F_29 ( & V_37 ) ;
return V_30 ;
}
static int F_134 ( struct V_100 * V_102 , struct V_123 * V_124 )
{
return F_117 ( V_102 , V_124 , false ) ;
}
static int F_135 ( struct V_10 * V_11 ,
unsigned int V_148 )
{
struct V_100 * V_101 ;
int V_30 ;
V_101 = F_91 ( F_136 ( V_11 -> V_33 , V_148 ) ) ;
F_137 ( & V_101 -> V_12 , L_38 ) ;
V_30 = F_138 ( & V_11 -> V_12 , & V_101 -> V_12 ) ;
if ( V_30 ) {
F_18 ( L_52 , V_31 , V_30 ) ;
F_77 ( & V_11 -> V_92 ) ;
F_100 ( V_148 , V_11 -> V_33 ) ;
F_78 ( & V_11 -> V_92 ) ;
V_30 = F_92 ( & V_101 -> V_12 , & V_11 -> V_12 ,
L_38 ) ;
return - V_62 ;
}
return V_101 -> V_126 ;
}
static int F_139 ( struct V_100 * V_102 ,
struct V_123 * V_124 ,
bool V_125 )
{
unsigned int V_14 = V_102 -> V_126 , V_33 ;
int V_149 , V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_33 ( L_53 , V_31 , V_14 ) ;
F_99 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_125 )
F_21 ( V_112 , V_14 ) = V_11 ;
F_101 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_33 ( L_54 , V_31 ) ;
return - V_62 ;
}
if ( F_1 () ) {
V_30 = F_98 ( V_11 , V_109 ) ;
if ( V_30 ) {
F_18 ( L_41 , V_31 ) ;
return V_30 ;
}
}
#ifdef F_118
if ( ! V_1 -> V_71 )
strncpy ( F_21 ( V_143 , V_14 ) ,
V_11 -> V_68 -> V_66 , V_67 ) ;
#endif
F_73 ( & V_11 -> V_92 ) ;
V_33 = F_140 ( V_11 -> V_33 ) ;
F_29 ( & V_11 -> V_92 ) ;
if ( V_14 != V_11 -> V_14 ) {
F_137 ( & V_102 -> V_12 , L_38 ) ;
} else if ( V_33 > 1 ) {
V_149 = F_135 ( V_11 , V_14 ) ;
if ( V_149 >= 0 ) {
F_114 ( V_11 , V_149 ) ;
if ( ! V_125 ) {
F_33 ( L_55 ,
V_31 , V_149 , V_14 ) ;
}
}
}
return 0 ;
}
static int F_141 ( struct V_100 * V_102 ,
struct V_123 * V_124 ,
bool V_125 )
{
unsigned int V_14 = V_102 -> V_126 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_26 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_28 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_33 ( L_54 , V_31 ) ;
return - V_62 ;
}
F_77 ( & V_11 -> V_92 ) ;
V_33 = F_140 ( V_11 -> V_33 ) ;
if ( V_33 > 1 )
F_142 ( V_14 , V_11 -> V_33 ) ;
F_78 ( & V_11 -> V_92 ) ;
if ( V_33 == 1 ) {
if ( F_1 () ) {
V_30 = F_98 ( V_11 ,
V_150 ) ;
if ( V_30 ) {
F_18 ( L_56 ,
V_31 ) ;
return V_30 ;
}
}
if ( ! V_125 )
F_111 ( V_11 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
F_99 ( & V_38 , V_7 ) ;
F_143 ( & V_11 -> V_116 ) ;
F_101 ( & V_38 , V_7 ) ;
if ( ! V_125 )
F_113 ( V_11 ) ;
} else {
if ( F_1 () ) {
if ( ( V_30 = F_98 ( V_11 , V_110 ) ) ||
( V_30 = F_98 ( V_11 , V_111 ) ) ) {
F_18 ( L_42 ,
V_31 ) ;
return V_30 ;
}
}
}
F_21 ( V_34 , V_14 ) = NULL ;
return 0 ;
}
static int F_144 ( struct V_100 * V_102 , struct V_123 * V_124 )
{
unsigned int V_14 = V_102 -> V_126 ;
int V_30 ;
if ( F_119 ( V_14 ) )
return 0 ;
V_30 = F_139 ( V_102 , V_124 , false ) ;
if ( ! V_30 )
V_30 = F_141 ( V_102 , V_124 , false ) ;
return V_30 ;
}
static void V_133 ( struct V_151 * V_152 )
{
struct V_10 * V_11 =
F_145 ( V_152 , struct V_10 , V_132 ) ;
unsigned int V_14 = V_11 -> V_14 ;
F_33 ( L_57 , V_14 ) ;
F_146 ( V_14 ) ;
}
static void F_147 ( unsigned int V_14 , unsigned int V_153 ,
unsigned int V_154 )
{
struct V_10 * V_11 ;
struct V_40 V_51 ;
unsigned long V_7 ;
F_33 ( L_58
L_59 , V_153 , V_154 ) ;
V_51 . V_46 = V_153 ;
V_51 . V_48 = V_154 ;
F_26 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_28 ( & V_38 , V_7 ) ;
F_41 ( V_11 , & V_51 , V_53 ) ;
F_41 ( V_11 , & V_51 , V_47 ) ;
}
unsigned int F_148 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned int V_155 = 0 ;
if ( V_1 && V_1 -> V_71 && V_1 -> V_106 )
return V_1 -> V_106 ( V_14 ) ;
V_11 = F_24 ( V_14 ) ;
if ( V_11 ) {
V_155 = V_11 -> V_54 ;
F_30 ( V_11 ) ;
}
return V_155 ;
}
unsigned int F_149 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_24 ( V_14 ) ;
unsigned int V_155 = 0 ;
if ( V_11 ) {
V_155 = V_11 -> V_138 ;
F_30 ( V_11 ) ;
}
return V_155 ;
}
static unsigned int F_56 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_21 ( V_34 , V_14 ) ;
unsigned int V_155 = 0 ;
if ( ! V_1 -> V_106 )
return V_155 ;
V_155 = V_1 -> V_106 ( V_14 ) ;
if ( V_155 && V_11 -> V_54 &&
! ( V_1 -> V_7 & V_42 ) ) {
if ( F_121 ( V_155 != V_11 -> V_54 ) ) {
F_147 ( V_14 , V_11 -> V_54 , V_155 ) ;
F_150 ( & V_11 -> V_132 ) ;
}
}
return V_155 ;
}
unsigned int F_151 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_24 ( V_14 ) ;
unsigned int V_155 = 0 ;
if ( V_11 ) {
F_73 ( & V_11 -> V_92 ) ;
V_155 = F_56 ( V_14 ) ;
F_29 ( & V_11 -> V_92 ) ;
F_30 ( V_11 ) ;
}
return V_155 ;
}
static int F_152 ( void )
{
int V_30 = 0 ;
int V_14 = F_153 () ;
struct V_10 * V_11 ;
F_33 ( L_60 , V_14 ) ;
V_11 = F_24 ( V_14 ) ;
if ( ! V_11 )
return 0 ;
if ( V_1 -> V_156 ) {
V_30 = V_1 -> V_156 ( V_11 ) ;
if ( V_30 )
F_154 ( V_157 L_61
L_62 , V_11 -> V_14 ) ;
}
F_30 ( V_11 ) ;
return V_30 ;
}
static void F_155 ( void )
{
int V_30 = 0 ;
int V_14 = F_153 () ;
struct V_10 * V_11 ;
F_33 ( L_63 , V_14 ) ;
V_11 = F_24 ( V_14 ) ;
if ( ! V_11 )
return;
if ( V_1 -> V_158 ) {
V_30 = V_1 -> V_158 ( V_11 ) ;
if ( V_30 ) {
F_154 ( V_157 L_64
L_62 , V_11 -> V_14 ) ;
goto V_159;
}
}
F_150 ( & V_11 -> V_132 ) ;
V_159:
F_30 ( V_11 ) ;
}
const char * F_156 ( void )
{
if ( V_1 )
return V_1 -> V_66 ;
return NULL ;
}
int F_157 ( struct V_160 * V_161 , unsigned int V_162 )
{
int V_30 ;
if ( F_4 () )
return - V_62 ;
F_115 ( ! V_5 ) ;
switch ( V_162 ) {
case V_163 :
V_30 = F_158 (
& V_4 , V_161 ) ;
break;
case V_164 :
V_30 = F_159 (
& V_119 , V_161 ) ;
break;
default:
V_30 = - V_62 ;
}
return V_30 ;
}
int F_160 ( struct V_160 * V_161 , unsigned int V_162 )
{
int V_30 ;
if ( F_4 () )
return - V_62 ;
switch ( V_162 ) {
case V_163 :
V_30 = F_161 (
& V_4 , V_161 ) ;
break;
case V_164 :
V_30 = F_162 (
& V_119 , V_161 ) ;
break;
default:
V_30 = - V_62 ;
}
return V_30 ;
}
int F_131 ( struct V_10 * V_11 ,
unsigned int V_165 ,
unsigned int V_166 )
{
int V_167 = - V_62 ;
unsigned int V_168 = V_165 ;
if ( F_4 () )
return - V_169 ;
if ( V_165 > V_11 -> V_138 )
V_165 = V_11 -> V_138 ;
if ( V_165 < V_11 -> V_137 )
V_165 = V_11 -> V_137 ;
F_33 ( L_65 ,
V_11 -> V_14 , V_165 , V_166 , V_168 ) ;
if ( V_165 == V_11 -> V_54 )
return 0 ;
if ( V_1 -> V_3 )
V_167 = V_1 -> V_3 ( V_11 , V_165 , V_166 ) ;
else if ( V_1 -> V_2 ) {
struct V_27 * V_170 ;
struct V_40 V_51 ;
bool V_171 ;
int V_172 ;
V_170 = F_163 ( V_11 -> V_14 ) ;
if ( F_121 ( ! V_170 ) ) {
F_18 ( L_66 , V_31 ) ;
goto V_70;
}
V_167 = F_164 ( V_11 , V_170 ,
V_165 , V_166 , & V_172 ) ;
if ( F_121 ( V_167 ) ) {
F_18 ( L_67 , V_31 ) ;
goto V_70;
}
if ( V_170 [ V_172 ] . V_173 == V_11 -> V_54 ) {
V_167 = 0 ;
goto V_70;
}
V_171 = ! ( V_1 -> V_7 & V_174 ) ;
if ( V_171 ) {
V_51 . V_46 = V_11 -> V_54 ;
V_51 . V_48 = V_170 [ V_172 ] . V_173 ;
V_51 . V_7 = 0 ;
F_33 ( L_68 ,
V_31 , V_11 -> V_14 , V_51 . V_46 ,
V_51 . V_48 ) ;
F_41 ( V_11 , & V_51 ,
V_53 ) ;
}
V_167 = V_1 -> V_2 ( V_11 , V_172 ) ;
if ( V_167 )
F_18 ( L_69 ,
V_31 , V_167 ) ;
if ( V_171 )
F_43 ( V_11 , & V_51 , V_167 ) ;
}
V_70:
return V_167 ;
}
int F_165 ( struct V_10 * V_11 ,
unsigned int V_165 ,
unsigned int V_166 )
{
int V_30 = - V_62 ;
F_77 ( & V_11 -> V_92 ) ;
V_30 = F_131 ( V_11 , V_165 , V_166 ) ;
F_78 ( & V_11 -> V_92 ) ;
return V_30 ;
}
static int F_98 ( struct V_10 * V_11 ,
unsigned int V_175 )
{
int V_30 ;
#ifdef F_166
struct V_63 * V_129 = & V_176 ;
#else
struct V_63 * V_129 = NULL ;
#endif
if ( V_11 -> V_68 -> V_177 &&
V_11 -> V_32 . V_29 >
V_11 -> V_68 -> V_177 ) {
if ( ! V_129 )
return - V_62 ;
else {
F_154 ( V_178 L_70
L_71
L_72 ,
V_11 -> V_68 -> V_66 ,
V_129 -> V_66 ) ;
V_11 -> V_68 = V_129 ;
}
}
if ( V_175 == V_179 )
if ( ! F_167 ( V_11 -> V_68 -> V_180 ) )
return - V_62 ;
F_33 ( L_73 ,
V_11 -> V_14 , V_175 ) ;
F_52 ( & V_181 ) ;
if ( ( V_11 -> V_182 && V_175 == V_110 )
|| ( ! V_11 -> V_182
&& ( V_175 == V_111 || V_175 == V_109 ) ) ) {
F_53 ( & V_181 ) ;
return - V_183 ;
}
if ( V_175 == V_109 )
V_11 -> V_182 = false ;
else if ( V_175 == V_110 )
V_11 -> V_182 = true ;
F_53 ( & V_181 ) ;
V_30 = V_11 -> V_68 -> V_68 ( V_11 , V_175 ) ;
if ( ! V_30 ) {
if ( V_175 == V_179 )
V_11 -> V_68 -> V_184 ++ ;
else if ( V_175 == V_150 )
V_11 -> V_68 -> V_184 -- ;
} else {
F_52 ( & V_181 ) ;
if ( V_175 == V_109 )
V_11 -> V_182 = true ;
else if ( V_175 == V_110 )
V_11 -> V_182 = false ;
F_53 ( & V_181 ) ;
}
if ( ( ( V_175 == V_179 ) && V_30 ) ||
( ( V_175 == V_150 ) && ! V_30 ) )
F_168 ( V_11 -> V_68 -> V_180 ) ;
return V_30 ;
}
int F_169 ( struct V_63 * V_68 )
{
int V_69 ;
if ( ! V_68 )
return - V_62 ;
if ( F_4 () )
return - V_169 ;
F_52 ( & V_74 ) ;
V_68 -> V_184 = 0 ;
V_69 = - V_183 ;
if ( F_48 ( V_68 -> V_66 ) == NULL ) {
V_69 = 0 ;
F_132 ( & V_68 -> V_185 , & V_186 ) ;
}
F_53 ( & V_74 ) ;
return V_69 ;
}
void F_170 ( struct V_63 * V_68 )
{
#ifdef F_118
int V_14 ;
#endif
if ( ! V_68 )
return;
if ( F_4 () )
return;
#ifdef F_118
F_171 (cpu) {
if ( F_76 ( V_14 ) )
continue;
if ( ! strcmp ( F_21 ( V_143 , V_14 ) , V_68 -> V_66 ) )
strcpy ( F_21 ( V_143 , V_14 ) , L_74 ) ;
}
#endif
F_52 ( & V_74 ) ;
F_143 ( & V_68 -> V_185 ) ;
F_53 ( & V_74 ) ;
return;
}
int F_60 ( struct V_10 * V_11 , unsigned int V_14 )
{
struct V_10 * V_187 ;
if ( ! V_11 )
return - V_62 ;
V_187 = F_24 ( V_14 ) ;
if ( ! V_187 )
return - V_62 ;
memcpy ( V_11 , V_187 , sizeof( * V_11 ) ) ;
F_30 ( V_187 ) ;
return 0 ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_10 * V_77 )
{
int V_30 = 0 , V_188 = 1 ;
F_33 ( L_75 , V_77 -> V_14 ,
V_77 -> V_137 , V_77 -> V_138 ) ;
memcpy ( & V_77 -> V_32 , & V_11 -> V_32 , sizeof( V_11 -> V_32 ) ) ;
if ( V_77 -> V_137 > V_11 -> V_138 || V_77 -> V_138 < V_11 -> V_137 ) {
V_30 = - V_62 ;
goto V_189;
}
V_30 = V_1 -> V_190 ( V_77 ) ;
if ( V_30 )
goto V_189;
F_112 ( & V_119 ,
V_191 , V_77 ) ;
F_112 ( & V_119 ,
V_192 , V_77 ) ;
V_30 = V_1 -> V_190 ( V_77 ) ;
if ( V_30 )
goto V_189;
F_112 ( & V_119 ,
V_193 , V_77 ) ;
V_11 -> V_137 = V_77 -> V_137 ;
V_11 -> V_138 = V_77 -> V_138 ;
F_33 ( L_76 ,
V_11 -> V_137 , V_11 -> V_138 ) ;
if ( V_1 -> V_71 ) {
V_11 -> V_11 = V_77 -> V_11 ;
F_33 ( L_77 ) ;
V_30 = V_1 -> V_71 ( V_77 ) ;
} else {
if ( V_77 -> V_68 != V_11 -> V_68 ) {
struct V_63 * V_194 = V_11 -> V_68 ;
F_33 ( L_78 ) ;
if ( V_11 -> V_68 ) {
F_98 ( V_11 , V_109 ) ;
F_78 ( & V_11 -> V_92 ) ;
F_98 ( V_11 ,
V_150 ) ;
F_77 ( & V_11 -> V_92 ) ;
}
V_11 -> V_68 = V_77 -> V_68 ;
if ( ! F_98 ( V_11 , V_179 ) ) {
if ( ! F_98 ( V_11 , V_110 ) ) {
V_188 = 0 ;
} else {
F_78 ( & V_11 -> V_92 ) ;
F_98 ( V_11 ,
V_150 ) ;
F_77 ( & V_11 -> V_92 ) ;
}
}
if ( V_188 ) {
F_33 ( L_79 ,
V_11 -> V_68 -> V_66 ) ;
if ( V_194 ) {
V_11 -> V_68 = V_194 ;
F_98 ( V_11 ,
V_179 ) ;
F_98 ( V_11 ,
V_110 ) ;
}
V_30 = - V_62 ;
goto V_189;
}
}
F_33 ( L_80 ) ;
V_30 = F_98 ( V_11 , V_111 ) ;
}
V_189:
return V_30 ;
}
int F_146 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_24 ( V_14 ) ;
struct V_10 V_77 ;
int V_30 ;
if ( ! V_11 ) {
V_30 = - V_169 ;
goto V_195;
}
F_77 ( & V_11 -> V_92 ) ;
F_33 ( L_81 , V_14 ) ;
memcpy ( & V_77 , V_11 , sizeof( * V_11 ) ) ;
V_77 . V_137 = V_11 -> V_78 . V_137 ;
V_77 . V_138 = V_11 -> V_78 . V_138 ;
V_77 . V_11 = V_11 -> V_78 . V_11 ;
V_77 . V_68 = V_11 -> V_78 . V_68 ;
if ( V_1 -> V_106 && ! V_1 -> V_71 ) {
V_77 . V_54 = V_1 -> V_106 ( V_14 ) ;
if ( ! V_11 -> V_54 ) {
F_33 ( L_82 ) ;
V_11 -> V_54 = V_77 . V_54 ;
} else {
if ( V_11 -> V_54 != V_77 . V_54 && F_1 () )
F_147 ( V_14 , V_11 -> V_54 ,
V_77 . V_54 ) ;
}
}
V_30 = F_61 ( V_11 , & V_77 ) ;
F_78 ( & V_11 -> V_92 ) ;
F_30 ( V_11 ) ;
V_195:
return V_30 ;
}
static int F_172 ( struct V_160 * V_196 ,
unsigned long V_197 , void * V_198 )
{
unsigned int V_14 = ( unsigned long ) V_198 ;
struct V_100 * V_102 ;
bool V_125 = false ;
V_102 = F_91 ( V_14 ) ;
if ( V_102 ) {
if ( V_197 & V_199 )
V_125 = true ;
switch ( V_197 & ~ V_199 ) {
case V_200 :
F_117 ( V_102 , NULL , V_125 ) ;
F_146 ( V_14 ) ;
break;
case V_201 :
F_139 ( V_102 , NULL , V_125 ) ;
break;
case V_202 :
F_141 ( V_102 , NULL , V_125 ) ;
break;
case V_203 :
F_117 ( V_102 , NULL , V_125 ) ;
break;
}
}
return V_204 ;
}
static int F_173 ( int V_52 )
{
struct V_27 * V_170 ;
struct V_10 * V_11 ;
int V_30 = - V_62 ;
F_49 (policy, &cpufreq_policy_list, policy_list) {
V_170 = F_163 ( V_11 -> V_14 ) ;
if ( V_170 ) {
V_30 = F_174 ( V_11 ,
V_170 ) ;
if ( V_30 ) {
F_18 ( L_83 ,
V_31 ) ;
break;
}
V_11 -> V_78 . V_138 = V_11 -> V_138 ;
F_98 ( V_11 , V_111 ) ;
}
}
return V_30 ;
}
int F_47 ( int V_52 )
{
unsigned long V_7 ;
int V_30 = 0 ;
if ( V_1 -> V_59 == V_52 )
return 0 ;
F_99 ( & V_38 , V_7 ) ;
V_1 -> V_59 = V_52 ;
F_101 ( & V_38 , V_7 ) ;
V_30 = V_1 -> V_205 ( V_52 ) ;
if ( V_30 ) {
F_99 ( & V_38 , V_7 ) ;
V_1 -> V_59 = ! V_52 ;
F_101 ( & V_38 , V_7 ) ;
F_18 ( L_84 , V_31 ,
V_52 ? L_16 : L_17 ) ;
}
return V_30 ;
}
int F_175 ( void )
{
if ( F_40 ( V_1 ) )
return V_1 -> V_206 ;
return 0 ;
}
int F_176 ( void )
{
return V_1 -> V_59 ;
}
int F_177 ( struct V_1 * V_207 )
{
unsigned long V_7 ;
int V_30 ;
if ( F_4 () )
return - V_169 ;
if ( ! V_207 || ! V_207 -> V_190 || ! V_207 -> V_134 ||
! ( V_207 -> V_71 || V_207 -> V_2 ||
V_207 -> V_3 ) )
return - V_62 ;
F_33 ( L_85 , V_207 -> V_66 ) ;
if ( V_207 -> V_71 )
V_207 -> V_7 |= V_42 ;
F_99 ( & V_38 , V_7 ) ;
if ( V_1 ) {
F_101 ( & V_38 , V_7 ) ;
return - V_208 ;
}
V_1 = V_207 ;
F_101 ( & V_38 , V_7 ) ;
if ( F_175 () ) {
if ( ! V_1 -> V_205 )
V_1 -> V_205 = F_173 ;
V_30 = F_86 ( & V_209 . V_57 ) ;
if ( V_30 ) {
F_18 ( L_86 ,
V_31 ) ;
goto V_210;
}
}
V_30 = F_178 ( & V_211 ) ;
if ( V_30 )
goto V_212;
if ( ! ( V_1 -> V_7 & V_213 ) ) {
int V_79 ;
V_30 = - V_169 ;
for ( V_79 = 0 ; V_79 < V_36 ; V_79 ++ )
if ( F_179 ( V_79 ) && F_21 ( V_34 , V_79 ) ) {
V_30 = 0 ;
break;
}
if ( V_30 ) {
F_33 ( L_87 ,
V_207 -> V_66 ) ;
goto V_214;
}
}
F_180 ( & V_215 ) ;
F_33 ( L_88 , V_207 -> V_66 ) ;
return 0 ;
V_214:
F_181 ( & V_211 ) ;
V_212:
if ( F_175 () )
F_88 ( & V_209 . V_57 ) ;
V_210:
F_99 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_101 ( & V_38 , V_7 ) ;
return V_30 ;
}
int F_182 ( struct V_1 * V_216 )
{
unsigned long V_7 ;
if ( ! V_1 || ( V_216 != V_1 ) )
return - V_62 ;
F_33 ( L_89 , V_216 -> V_66 ) ;
F_181 ( & V_211 ) ;
if ( F_175 () )
F_88 ( & V_209 . V_57 ) ;
F_183 ( & V_215 ) ;
F_77 ( & V_37 ) ;
F_99 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_101 ( & V_38 , V_7 ) ;
F_78 ( & V_37 ) ;
return 0 ;
}
static int T_1 F_184 ( void )
{
if ( F_4 () )
return - V_169 ;
V_13 = F_185 () ;
F_36 ( ! V_13 ) ;
F_186 ( & V_217 ) ;
return 0 ;
}
