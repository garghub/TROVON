static int T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
V_2 = true ;
return 0 ;
}
static int F_3 ( void )
{
return V_3 ;
}
void F_4 ( void )
{
V_3 = 1 ;
}
bool F_5 ( void )
{
return V_4 -> F_5 ;
}
struct V_5 * F_6 ( struct V_6 * V_7 )
{
if ( F_5 () )
return & V_7 -> V_8 ;
else
return V_9 ;
}
static inline T_2 F_7 ( unsigned int V_10 , T_2 * V_11 )
{
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
V_13 = F_8 ( F_9 () ) ;
V_14 = F_10 ( V_10 ) . V_15 [ V_16 ] ;
V_14 += F_10 ( V_10 ) . V_15 [ V_17 ] ;
V_14 += F_10 ( V_10 ) . V_15 [ V_18 ] ;
V_14 += F_10 ( V_10 ) . V_15 [ V_19 ] ;
V_14 += F_10 ( V_10 ) . V_15 [ V_20 ] ;
V_14 += F_10 ( V_10 ) . V_15 [ V_21 ] ;
V_12 = V_13 - V_14 ;
if ( V_11 )
* V_11 = F_11 ( V_13 ) ;
return F_11 ( V_12 ) ;
}
T_2 F_12 ( unsigned int V_10 , T_2 * V_11 , int V_22 )
{
T_2 V_12 = F_13 ( V_10 , V_22 ? V_11 : NULL ) ;
if ( V_12 == - 1ULL )
return F_7 ( V_10 , V_11 ) ;
else if ( ! V_22 )
V_12 += F_14 ( V_10 , V_11 ) ;
return V_12 ;
}
static struct V_6 * F_15 ( unsigned int V_10 , bool V_23 )
{
struct V_6 * V_24 ;
unsigned long V_25 ;
if ( V_10 >= V_26 )
goto V_27;
F_16 ( & V_28 , V_25 ) ;
if ( ! V_4 )
goto V_29;
if ( ! F_17 ( V_4 -> V_30 ) )
goto V_29;
V_24 = F_18 ( V_31 , V_10 ) ;
if ( ! V_24 )
goto V_32;
if ( ! V_23 && ! F_19 ( & V_24 -> V_8 ) )
goto V_32;
F_20 ( & V_28 , V_25 ) ;
return V_24 ;
V_32:
F_21 ( V_4 -> V_30 ) ;
V_29:
F_20 ( & V_28 , V_25 ) ;
V_27:
return NULL ;
}
struct V_6 * F_22 ( unsigned int V_10 )
{
if ( F_3 () )
return NULL ;
return F_15 ( V_10 , false ) ;
}
static struct V_6 * F_23 ( unsigned int V_10 )
{
return F_15 ( V_10 , true ) ;
}
static void F_24 ( struct V_6 * V_24 , bool V_23 )
{
if ( ! V_23 )
F_25 ( & V_24 -> V_8 ) ;
F_21 ( V_4 -> V_30 ) ;
}
void F_26 ( struct V_6 * V_24 )
{
if ( F_3 () )
return;
F_24 ( V_24 , false ) ;
}
static void F_27 ( struct V_6 * V_24 )
{
F_24 ( V_24 , true ) ;
}
static void F_28 ( unsigned long V_33 , struct V_34 * V_35 )
{
if ( V_35 -> V_25 & V_36 )
return;
if ( ! V_37 ) {
V_38 = V_39 ;
V_37 = V_35 -> V_40 ;
F_29 ( L_1
L_2 , V_38 , V_37 ) ;
}
if ( ( V_33 == V_41 && V_35 -> V_40 != V_35 -> V_42 ) ||
( V_33 == V_43 || V_33 == V_44 ) ) {
V_39 = F_30 ( V_38 , V_37 ,
V_35 -> V_42 ) ;
F_29 ( L_3
L_4 , V_39 , V_35 -> V_42 ) ;
}
}
static inline void F_28 ( unsigned long V_33 , struct V_34 * V_35 )
{
return;
}
static void F_31 ( struct V_6 * V_7 ,
struct V_34 * V_45 , unsigned int V_46 )
{
F_32 ( F_33 () ) ;
if ( F_3 () )
return;
V_45 -> V_25 = V_4 -> V_25 ;
F_29 ( L_5 ,
V_46 , V_45 -> V_42 ) ;
switch ( V_46 ) {
case V_47 :
if ( F_34 ( V_7 -> V_48 ==
F_35 ( V_7 -> V_49 ) ,
L_6 ) )
return;
V_7 -> V_48 ++ ;
if ( ! ( V_4 -> V_25 & V_36 ) ) {
if ( ( V_7 ) && ( V_7 -> V_10 == V_45 -> V_10 ) &&
( V_7 -> V_50 ) && ( V_7 -> V_50 != V_45 -> V_40 ) ) {
F_29 ( L_7
L_8 ,
V_45 -> V_40 , V_7 -> V_50 ) ;
V_45 -> V_40 = V_7 -> V_50 ;
}
}
F_36 ( & V_1 ,
V_47 , V_45 ) ;
F_28 ( V_47 , V_45 ) ;
break;
case V_41 :
if ( F_34 ( ! V_7 -> V_48 ,
L_9 ) )
return;
V_7 -> V_48 -- ;
F_28 ( V_41 , V_45 ) ;
F_29 ( L_10 , ( unsigned long ) V_45 -> V_42 ,
( unsigned long ) V_45 -> V_10 ) ;
F_37 ( V_45 -> V_42 , V_45 -> V_10 ) ;
F_36 ( & V_1 ,
V_41 , V_45 ) ;
if ( F_38 ( V_7 ) && F_38 ( V_7 -> V_10 == V_45 -> V_10 ) )
V_7 -> V_50 = V_45 -> V_42 ;
break;
}
}
void F_39 ( struct V_6 * V_7 ,
struct V_34 * V_45 , unsigned int V_46 )
{
F_40 (freqs->cpu, policy->cpus)
F_31 ( V_7 , V_45 , V_46 ) ;
}
static struct V_51 * F_41 ( const char * V_52 )
{
struct V_51 * V_53 ;
F_42 (t, &cpufreq_governor_list, governor_list)
if ( ! F_43 ( V_52 , V_53 -> V_54 , V_55 ) )
return V_53 ;
return NULL ;
}
static int F_44 ( char * V_52 , unsigned int * V_7 ,
struct V_51 * * V_56 )
{
int V_57 = - V_58 ;
if ( ! V_4 )
goto V_59;
if ( V_4 -> V_60 ) {
if ( ! F_43 ( V_52 , L_11 , V_55 ) ) {
* V_7 = V_61 ;
V_57 = 0 ;
} else if ( ! F_43 ( V_52 , L_12 ,
V_55 ) ) {
* V_7 = V_62 ;
V_57 = 0 ;
}
} else if ( V_4 -> V_63 ) {
struct V_51 * V_53 ;
F_45 ( & V_64 ) ;
V_53 = F_41 ( V_52 ) ;
if ( V_53 == NULL ) {
int V_65 ;
F_46 ( & V_64 ) ;
V_65 = F_47 ( L_13 , V_52 ) ;
F_45 ( & V_64 ) ;
if ( V_65 == 0 )
V_53 = F_41 ( V_52 ) ;
}
if ( V_53 != NULL ) {
* V_56 = V_53 ;
V_57 = 0 ;
}
F_46 ( & V_64 ) ;
}
V_59:
return V_57 ;
}
static T_3 F_48 ( struct V_6 * V_7 ,
char * V_66 )
{
unsigned int V_67 = F_49 ( V_7 -> V_10 ) ;
if ( ! V_67 )
return sprintf ( V_66 , L_14 ) ;
return sprintf ( V_66 , L_15 , V_67 ) ;
}
static T_3 F_50 ( struct V_6 * V_7 , char * V_66 )
{
if ( V_7 -> V_7 == V_62 )
return sprintf ( V_66 , L_16 ) ;
else if ( V_7 -> V_7 == V_61 )
return sprintf ( V_66 , L_17 ) ;
else if ( V_7 -> V_56 )
return F_51 ( V_66 , V_68 , L_18 ,
V_7 -> V_56 -> V_54 ) ;
return - V_58 ;
}
static T_3 F_52 ( struct V_6 * V_7 ,
const char * V_66 , T_4 V_69 )
{
unsigned int V_65 ;
char V_52 [ 16 ] ;
struct V_6 V_70 ;
V_65 = F_53 ( & V_70 , V_7 -> V_10 ) ;
if ( V_65 )
return V_65 ;
V_65 = sscanf ( V_66 , L_19 , V_52 ) ;
if ( V_65 != 1 )
return - V_58 ;
if ( F_44 ( V_52 , & V_70 . V_7 ,
& V_70 . V_56 ) )
return - V_58 ;
V_65 = F_54 ( V_7 , & V_70 ) ;
V_7 -> V_71 . V_7 = V_7 -> V_7 ;
V_7 -> V_71 . V_56 = V_7 -> V_56 ;
if ( V_65 )
return V_65 ;
else
return V_69 ;
}
static T_3 F_55 ( struct V_6 * V_7 , char * V_66 )
{
return F_51 ( V_66 , V_68 , L_18 , V_4 -> V_54 ) ;
}
static T_3 F_56 ( struct V_6 * V_7 ,
char * V_66 )
{
T_3 V_72 = 0 ;
struct V_51 * V_53 ;
if ( ! V_4 -> V_63 ) {
V_72 += sprintf ( V_66 , L_20 ) ;
goto V_59;
}
F_42 (t, &cpufreq_governor_list, governor_list) {
if ( V_72 >= ( T_3 ) ( ( V_73 / sizeof( char ) )
- ( V_55 + 2 ) ) )
goto V_59;
V_72 += F_51 ( & V_66 [ V_72 ] , V_68 , L_21 , V_53 -> V_54 ) ;
}
V_59:
V_72 += sprintf ( & V_66 [ V_72 ] , L_22 ) ;
return V_72 ;
}
T_3 F_57 ( const struct V_74 * V_75 , char * V_66 )
{
T_3 V_72 = 0 ;
unsigned int V_10 ;
F_40 (cpu, mask) {
if ( V_72 )
V_72 += F_51 ( & V_66 [ V_72 ] , ( V_73 - V_72 - 2 ) , L_23 ) ;
V_72 += F_51 ( & V_66 [ V_72 ] , ( V_73 - V_72 - 2 ) , L_24 , V_10 ) ;
if ( V_72 >= ( V_73 - 5 ) )
break;
}
V_72 += sprintf ( & V_66 [ V_72 ] , L_22 ) ;
return V_72 ;
}
static T_3 F_58 ( struct V_6 * V_7 , char * V_66 )
{
return F_57 ( V_7 -> V_76 , V_66 ) ;
}
static T_3 F_59 ( struct V_6 * V_7 , char * V_66 )
{
return F_57 ( V_7 -> V_49 , V_66 ) ;
}
static T_3 F_60 ( struct V_6 * V_7 ,
const char * V_66 , T_4 V_69 )
{
unsigned int V_77 = 0 ;
unsigned int V_65 ;
if ( ! V_7 -> V_56 || ! V_7 -> V_56 -> V_78 )
return - V_58 ;
V_65 = sscanf ( V_66 , L_24 , & V_77 ) ;
if ( V_65 != 1 )
return - V_58 ;
V_7 -> V_56 -> V_78 ( V_7 , V_77 ) ;
return V_69 ;
}
static T_3 F_61 ( struct V_6 * V_7 , char * V_66 )
{
if ( ! V_7 -> V_56 || ! V_7 -> V_56 -> V_79 )
return sprintf ( V_66 , L_25 ) ;
return V_7 -> V_56 -> V_79 ( V_7 , V_66 ) ;
}
static T_3 F_62 ( struct V_6 * V_7 , char * V_66 )
{
unsigned int V_80 ;
int V_65 ;
if ( V_4 -> V_81 ) {
V_65 = V_4 -> V_81 ( V_7 -> V_10 , & V_80 ) ;
if ( ! V_65 )
return sprintf ( V_66 , L_15 , V_80 ) ;
}
return sprintf ( V_66 , L_15 , V_7 -> V_82 . V_83 ) ;
}
static T_3 F_63 ( struct V_5 * V_8 , struct V_84 * V_85 , char * V_66 )
{
struct V_6 * V_7 = F_64 ( V_8 ) ;
struct V_86 * V_87 = F_65 ( V_85 ) ;
T_3 V_65 = - V_58 ;
V_7 = F_23 ( V_7 -> V_10 ) ;
if ( ! V_7 )
goto V_88;
if ( F_66 ( V_7 -> V_10 ) < 0 )
goto V_89;
if ( V_87 -> F_63 )
V_65 = V_87 -> F_63 ( V_7 , V_66 ) ;
else
V_65 = - V_90 ;
F_67 ( V_7 -> V_10 ) ;
V_89:
F_27 ( V_7 ) ;
V_88:
return V_65 ;
}
static T_3 F_68 ( struct V_5 * V_8 , struct V_84 * V_85 ,
const char * V_66 , T_4 V_69 )
{
struct V_6 * V_7 = F_64 ( V_8 ) ;
struct V_86 * V_87 = F_65 ( V_85 ) ;
T_3 V_65 = - V_58 ;
V_7 = F_23 ( V_7 -> V_10 ) ;
if ( ! V_7 )
goto V_88;
if ( F_69 ( V_7 -> V_10 ) < 0 )
goto V_89;
if ( V_87 -> F_68 )
V_65 = V_87 -> F_68 ( V_7 , V_66 , V_69 ) ;
else
V_65 = - V_90 ;
F_70 ( V_7 -> V_10 ) ;
V_89:
F_27 ( V_7 ) ;
V_88:
return V_65 ;
}
static void F_71 ( struct V_5 * V_8 )
{
struct V_6 * V_7 = F_64 ( V_8 ) ;
F_29 ( L_26 ) ;
F_72 ( & V_7 -> V_91 ) ;
}
int F_73 ( void )
{
if ( ! V_92 ++ )
return F_74 ( V_9 ,
& V_93 . V_94 -> V_8 , L_27 , L_28 ) ;
return 0 ;
}
void F_75 ( void )
{
if ( ! -- V_92 )
F_76 ( V_9 ) ;
}
int F_77 ( const struct V_84 * V_85 )
{
int V_65 = F_73 () ;
if ( ! V_65 ) {
V_65 = F_78 ( V_9 , V_85 ) ;
if ( V_65 )
F_75 () ;
}
return V_65 ;
}
void F_79 ( const struct V_84 * V_85 )
{
F_80 ( V_9 , V_85 ) ;
F_75 () ;
}
static int F_81 ( unsigned int V_10 ,
struct V_6 * V_7 )
{
unsigned int V_95 ;
int V_65 = 0 ;
F_40 (j, policy->cpus) {
struct V_6 * V_96 ;
struct V_97 * V_98 ;
if ( V_95 == V_10 )
continue;
F_29 ( L_29 , V_95 ) ;
V_96 = F_22 ( V_10 ) ;
V_98 = F_82 ( V_95 ) ;
V_65 = F_83 ( & V_98 -> V_8 , & V_7 -> V_8 ,
L_28 ) ;
if ( V_65 ) {
F_26 ( V_96 ) ;
return V_65 ;
}
}
return V_65 ;
}
static int F_84 ( unsigned int V_10 ,
struct V_6 * V_7 ,
struct V_97 * V_99 )
{
struct V_6 V_70 ;
struct V_86 * * V_100 ;
unsigned long V_25 ;
int V_65 = 0 ;
unsigned int V_95 ;
V_65 = F_85 ( & V_7 -> V_8 , & V_101 ,
& V_99 -> V_8 , L_28 ) ;
if ( V_65 )
return V_65 ;
V_100 = V_4 -> V_85 ;
while ( ( V_100 ) && ( * V_100 ) ) {
V_65 = F_78 ( & V_7 -> V_8 , & ( ( * V_100 ) -> V_85 ) ) ;
if ( V_65 )
goto V_102;
V_100 ++ ;
}
if ( V_4 -> V_103 ) {
V_65 = F_78 ( & V_7 -> V_8 , & V_104 . V_85 ) ;
if ( V_65 )
goto V_102;
}
if ( V_4 -> V_63 ) {
V_65 = F_78 ( & V_7 -> V_8 , & V_105 . V_85 ) ;
if ( V_65 )
goto V_102;
}
if ( V_4 -> V_81 ) {
V_65 = F_78 ( & V_7 -> V_8 , & V_81 . V_85 ) ;
if ( V_65 )
goto V_102;
}
F_86 ( & V_28 , V_25 ) ;
F_40 (j, policy->cpus) {
F_18 ( V_31 , V_95 ) = V_7 ;
F_18 ( V_106 , V_95 ) = V_7 -> V_10 ;
}
F_87 ( & V_28 , V_25 ) ;
V_65 = F_81 ( V_10 , V_7 ) ;
if ( V_65 )
goto V_102;
memcpy ( & V_70 , V_7 , sizeof( struct V_6 ) ) ;
V_7 -> V_56 = NULL ;
V_65 = F_54 ( V_7 , & V_70 ) ;
V_7 -> V_71 . V_7 = V_7 -> V_7 ;
V_7 -> V_71 . V_56 = V_7 -> V_56 ;
if ( V_65 ) {
F_29 ( L_30 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_7 ) ;
}
return V_65 ;
V_102:
F_25 ( & V_7 -> V_8 ) ;
F_88 ( & V_7 -> V_91 ) ;
return V_65 ;
}
static int F_89 ( unsigned int V_10 , unsigned int V_107 ,
struct V_97 * V_99 )
{
struct V_6 * V_7 ;
int V_65 = 0 , V_108 = ! ! V_4 -> V_63 ;
unsigned long V_25 ;
V_7 = F_22 ( V_107 ) ;
F_90 ( ! V_7 ) ;
if ( V_108 )
F_91 ( V_7 , V_109 ) ;
F_69 ( V_107 ) ;
F_86 ( & V_28 , V_25 ) ;
F_92 ( V_10 , V_7 -> V_49 ) ;
F_18 ( V_106 , V_10 ) = V_7 -> V_10 ;
F_18 ( V_31 , V_10 ) = V_7 ;
F_87 ( & V_28 , V_25 ) ;
F_70 ( V_107 ) ;
if ( V_108 ) {
F_91 ( V_7 , V_110 ) ;
F_91 ( V_7 , V_111 ) ;
}
V_65 = F_83 ( & V_99 -> V_8 , & V_7 -> V_8 , L_28 ) ;
if ( V_65 ) {
F_26 ( V_7 ) ;
return V_65 ;
}
return 0 ;
}
static int F_93 ( struct V_97 * V_99 , struct V_112 * V_113 )
{
unsigned int V_95 , V_10 = V_99 -> V_114 ;
int V_65 = - V_115 ;
struct V_6 * V_7 ;
unsigned long V_25 ;
#ifdef F_94
struct V_51 * V_116 ;
int V_107 ;
#endif
if ( F_95 ( V_10 ) )
return 0 ;
F_29 ( L_31 , V_10 ) ;
#ifdef F_96
V_7 = F_22 ( V_10 ) ;
if ( F_97 ( V_7 ) ) {
F_26 ( V_7 ) ;
return 0 ;
}
#ifdef F_94
F_16 ( & V_28 , V_25 ) ;
F_98 (sibling) {
struct V_6 * V_117 = F_18 ( V_31 , V_107 ) ;
if ( V_117 && F_99 ( V_10 , V_117 -> V_76 ) ) {
F_20 ( & V_28 , V_25 ) ;
return F_89 ( V_10 , V_107 , V_99 ) ;
}
}
F_20 ( & V_28 , V_25 ) ;
#endif
#endif
if ( ! F_17 ( V_4 -> V_30 ) ) {
V_65 = - V_58 ;
goto V_118;
}
V_7 = F_100 ( sizeof( struct V_6 ) , V_119 ) ;
if ( ! V_7 )
goto V_120;
if ( ! F_101 ( & V_7 -> V_49 , V_119 ) )
goto V_121;
if ( ! F_102 ( & V_7 -> V_76 , V_119 ) )
goto V_122;
V_7 -> V_10 = V_10 ;
V_7 -> V_56 = V_123 ;
F_103 ( V_7 -> V_49 , F_104 ( V_10 ) ) ;
F_18 ( V_106 , V_10 ) = V_10 ;
F_105 ( & V_7 -> V_91 ) ;
F_106 ( & V_7 -> V_124 , V_125 ) ;
V_65 = V_4 -> V_126 ( V_7 ) ;
if ( V_65 ) {
F_29 ( L_32 ) ;
goto V_127;
}
F_107 ( V_7 -> V_76 , V_7 -> V_76 , V_7 -> V_49 ) ;
F_108 ( V_7 -> V_49 , V_7 -> V_49 , V_128 ) ;
V_7 -> V_71 . V_129 = V_7 -> V_129 ;
V_7 -> V_71 . V_130 = V_7 -> V_130 ;
F_109 ( & V_131 ,
V_132 , V_7 ) ;
#ifdef F_94
V_116 = F_41 ( F_18 ( V_133 , V_10 ) ) ;
if ( V_116 ) {
V_7 -> V_56 = V_116 ;
F_29 ( L_33 ,
V_7 -> V_56 -> V_54 , V_10 ) ;
}
#endif
V_65 = F_84 ( V_10 , V_7 , V_99 ) ;
if ( V_65 )
goto V_134;
F_110 ( & V_7 -> V_8 , V_135 ) ;
F_21 ( V_4 -> V_30 ) ;
F_29 ( L_34 ) ;
return 0 ;
V_134:
F_86 ( & V_28 , V_25 ) ;
F_40 (j, policy->cpus)
F_18 ( V_31 , V_95 ) = NULL ;
F_87 ( & V_28 , V_25 ) ;
F_25 ( & V_7 -> V_8 ) ;
F_88 ( & V_7 -> V_91 ) ;
V_127:
F_18 ( V_106 , V_10 ) = - 1 ;
F_111 ( V_7 -> V_76 ) ;
V_122:
F_111 ( V_7 -> V_49 ) ;
V_121:
F_112 ( V_7 ) ;
V_120:
F_21 ( V_4 -> V_30 ) ;
V_118:
return V_65 ;
}
static void F_113 ( struct V_6 * V_7 , unsigned int V_10 )
{
int V_95 ;
V_7 -> V_136 = V_7 -> V_10 ;
V_7 -> V_10 = V_10 ;
F_40 (j, policy->cpus)
F_18 ( V_106 , V_95 ) = V_10 ;
#ifdef F_114
F_115 ( V_7 ) ;
#endif
F_109 ( & V_131 ,
V_137 , V_7 ) ;
}
static int F_116 ( struct V_97 * V_99 ,
struct V_112 * V_113 )
{
unsigned int V_10 = V_99 -> V_114 , V_65 , V_49 ;
unsigned long V_25 ;
struct V_6 * V_24 ;
struct V_5 * V_8 ;
struct V_138 * V_139 ;
struct V_97 * V_98 ;
F_29 ( L_35 , V_140 , V_10 ) ;
F_86 ( & V_28 , V_25 ) ;
V_24 = F_18 ( V_31 , V_10 ) ;
F_18 ( V_31 , V_10 ) = NULL ;
F_87 ( & V_28 , V_25 ) ;
if ( ! V_24 ) {
F_29 ( L_36 , V_140 ) ;
return - V_58 ;
}
if ( V_4 -> V_63 )
F_91 ( V_24 , V_109 ) ;
#ifdef F_94
if ( ! V_4 -> V_60 )
strncpy ( F_18 ( V_133 , V_10 ) ,
V_24 -> V_56 -> V_54 , V_55 ) ;
#endif
F_90 ( F_69 ( V_10 ) ) ;
V_49 = F_35 ( V_24 -> V_49 ) ;
if ( V_49 > 1 )
F_117 ( V_10 , V_24 -> V_49 ) ;
F_70 ( V_10 ) ;
if ( V_10 != V_24 -> V_10 ) {
F_118 ( & V_99 -> V_8 , L_28 ) ;
} else if ( V_49 > 1 ) {
V_98 = F_82 ( F_119 ( V_24 -> V_49 ) ) ;
F_118 ( & V_98 -> V_8 , L_28 ) ;
V_65 = F_120 ( & V_24 -> V_8 , & V_98 -> V_8 ) ;
if ( V_65 ) {
F_121 ( L_37 , V_140 , V_65 ) ;
F_90 ( F_69 ( V_10 ) ) ;
F_92 ( V_10 , V_24 -> V_49 ) ;
F_86 ( & V_28 , V_25 ) ;
F_18 ( V_31 , V_10 ) = V_24 ;
F_87 ( & V_28 , V_25 ) ;
F_70 ( V_10 ) ;
V_65 = F_83 ( & V_98 -> V_8 , & V_24 -> V_8 ,
L_28 ) ;
return - V_58 ;
}
F_90 ( F_69 ( V_10 ) ) ;
F_113 ( V_24 , V_98 -> V_114 ) ;
F_70 ( V_10 ) ;
F_29 ( L_38 ,
V_140 , V_98 -> V_114 , V_10 ) ;
}
if ( V_49 == 1 ) {
if ( V_4 -> V_63 )
F_91 ( V_24 , V_141 ) ;
F_66 ( V_10 ) ;
V_8 = & V_24 -> V_8 ;
V_139 = & V_24 -> V_91 ;
F_67 ( V_10 ) ;
F_25 ( V_8 ) ;
F_29 ( L_39 ) ;
F_88 ( V_139 ) ;
F_29 ( L_40 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_24 ) ;
F_111 ( V_24 -> V_76 ) ;
F_111 ( V_24 -> V_49 ) ;
F_112 ( V_24 ) ;
} else {
F_29 ( L_41 , V_140 , V_10 ) ;
F_26 ( V_24 ) ;
if ( V_4 -> V_63 ) {
F_91 ( V_24 , V_110 ) ;
F_91 ( V_24 , V_111 ) ;
}
}
F_18 ( V_106 , V_10 ) = - 1 ;
return 0 ;
}
static int F_122 ( struct V_97 * V_99 , struct V_112 * V_113 )
{
unsigned int V_10 = V_99 -> V_114 ;
int V_142 ;
if ( F_95 ( V_10 ) )
return 0 ;
V_142 = F_116 ( V_99 , V_113 ) ;
return V_142 ;
}
static void V_125 ( struct V_143 * V_144 )
{
struct V_6 * V_7 =
F_123 ( V_144 , struct V_6 , V_124 ) ;
unsigned int V_10 = V_7 -> V_10 ;
F_29 ( L_42 , V_10 ) ;
F_124 ( V_10 ) ;
}
static void F_125 ( unsigned int V_10 , unsigned int V_145 ,
unsigned int V_146 )
{
struct V_6 * V_7 ;
struct V_34 V_45 ;
unsigned long V_25 ;
F_29 ( L_43
L_44 , V_145 , V_146 ) ;
V_45 . V_40 = V_145 ;
V_45 . V_42 = V_146 ;
F_16 ( & V_28 , V_25 ) ;
V_7 = F_18 ( V_31 , V_10 ) ;
F_20 ( & V_28 , V_25 ) ;
F_39 ( V_7 , & V_45 , V_47 ) ;
F_39 ( V_7 , & V_45 , V_41 ) ;
}
unsigned int F_126 ( unsigned int V_10 )
{
struct V_6 * V_7 ;
unsigned int V_147 = 0 ;
if ( V_4 && V_4 -> V_60 && V_4 -> V_103 )
return V_4 -> V_103 ( V_10 ) ;
V_7 = F_22 ( V_10 ) ;
if ( V_7 ) {
V_147 = V_7 -> V_50 ;
F_26 ( V_7 ) ;
}
return V_147 ;
}
unsigned int F_127 ( unsigned int V_10 )
{
struct V_6 * V_7 = F_22 ( V_10 ) ;
unsigned int V_147 = 0 ;
if ( V_7 ) {
V_147 = V_7 -> V_130 ;
F_26 ( V_7 ) ;
}
return V_147 ;
}
static unsigned int F_49 ( unsigned int V_10 )
{
struct V_6 * V_7 = F_18 ( V_31 , V_10 ) ;
unsigned int V_147 = 0 ;
if ( ! V_4 -> V_103 )
return V_147 ;
V_147 = V_4 -> V_103 ( V_10 ) ;
if ( V_147 && V_7 -> V_50 &&
! ( V_4 -> V_25 & V_36 ) ) {
if ( F_97 ( V_147 != V_7 -> V_50 ) ) {
F_125 ( V_10 , V_7 -> V_50 , V_147 ) ;
F_128 ( & V_7 -> V_124 ) ;
}
}
return V_147 ;
}
unsigned int F_129 ( unsigned int V_10 )
{
unsigned int V_147 = 0 ;
struct V_6 * V_7 = F_22 ( V_10 ) ;
if ( ! V_7 )
goto V_59;
if ( F_97 ( F_66 ( V_10 ) ) )
goto V_148;
V_147 = F_49 ( V_10 ) ;
F_67 ( V_10 ) ;
V_148:
F_26 ( V_7 ) ;
V_59:
return V_147 ;
}
static int F_130 ( void )
{
int V_65 = 0 ;
int V_10 = F_131 () ;
struct V_6 * V_149 ;
F_29 ( L_45 , V_10 ) ;
V_149 = F_22 ( V_10 ) ;
if ( ! V_149 )
return 0 ;
if ( V_4 -> V_150 ) {
V_65 = V_4 -> V_150 ( V_149 ) ;
if ( V_65 )
F_132 ( V_151 L_46
L_47 , V_149 -> V_10 ) ;
}
F_26 ( V_149 ) ;
return V_65 ;
}
static void F_133 ( void )
{
int V_65 = 0 ;
int V_10 = F_131 () ;
struct V_6 * V_149 ;
F_29 ( L_48 , V_10 ) ;
V_149 = F_22 ( V_10 ) ;
if ( ! V_149 )
return;
if ( V_4 -> V_152 ) {
V_65 = V_4 -> V_152 ( V_149 ) ;
if ( V_65 ) {
F_132 ( V_151 L_49
L_47 , V_149 -> V_10 ) ;
goto V_89;
}
}
F_128 ( & V_149 -> V_124 ) ;
V_89:
F_26 ( V_149 ) ;
}
const char * F_134 ( void )
{
if ( V_4 )
return V_4 -> V_54 ;
return NULL ;
}
int F_135 ( struct V_153 * V_154 , unsigned int V_155 )
{
int V_65 ;
if ( F_3 () )
return - V_58 ;
F_90 ( ! V_2 ) ;
switch ( V_155 ) {
case V_156 :
V_65 = F_136 (
& V_1 , V_154 ) ;
break;
case V_157 :
V_65 = F_137 (
& V_131 , V_154 ) ;
break;
default:
V_65 = - V_58 ;
}
return V_65 ;
}
int F_138 ( struct V_153 * V_154 , unsigned int V_155 )
{
int V_65 ;
if ( F_3 () )
return - V_58 ;
switch ( V_155 ) {
case V_156 :
V_65 = F_139 (
& V_1 , V_154 ) ;
break;
case V_157 :
V_65 = F_140 (
& V_131 , V_154 ) ;
break;
default:
V_65 = - V_58 ;
}
return V_65 ;
}
int F_141 ( struct V_6 * V_7 ,
unsigned int V_158 ,
unsigned int V_159 )
{
int V_142 = - V_58 ;
unsigned int V_160 = V_158 ;
if ( F_3 () )
return - V_161 ;
if ( V_7 -> V_48 )
return - V_162 ;
if ( V_158 > V_7 -> V_130 )
V_158 = V_7 -> V_130 ;
if ( V_158 < V_7 -> V_129 )
V_158 = V_7 -> V_129 ;
F_29 ( L_50 ,
V_7 -> V_10 , V_158 , V_159 , V_160 ) ;
if ( V_158 == V_7 -> V_50 )
return 0 ;
if ( V_4 -> V_63 )
V_142 = V_4 -> V_63 ( V_7 , V_158 , V_159 ) ;
return V_142 ;
}
int F_142 ( struct V_6 * V_7 ,
unsigned int V_158 ,
unsigned int V_159 )
{
int V_65 = - V_58 ;
if ( F_97 ( F_69 ( V_7 -> V_10 ) ) )
goto V_89;
V_65 = F_141 ( V_7 , V_158 , V_159 ) ;
F_70 ( V_7 -> V_10 ) ;
V_89:
return V_65 ;
}
int F_143 ( struct V_6 * V_7 , unsigned int V_10 )
{
if ( F_3 () )
return 0 ;
if ( ! V_4 -> V_163 )
return 0 ;
return V_4 -> V_163 ( V_7 , V_10 ) ;
}
static int F_91 ( struct V_6 * V_7 ,
unsigned int V_164 )
{
int V_65 ;
#ifdef F_144
struct V_51 * V_116 = & V_165 ;
#else
struct V_51 * V_116 = NULL ;
#endif
if ( V_7 -> V_56 -> V_166 &&
V_7 -> V_82 . V_167 >
V_7 -> V_56 -> V_166 ) {
if ( ! V_116 )
return - V_58 ;
else {
F_132 ( V_168 L_51
L_52
L_53 ,
V_7 -> V_56 -> V_54 ,
V_116 -> V_54 ) ;
V_7 -> V_56 = V_116 ;
}
}
if ( ! F_17 ( V_7 -> V_56 -> V_30 ) )
return - V_58 ;
F_29 ( L_54 ,
V_7 -> V_10 , V_164 ) ;
F_45 ( & V_169 ) ;
if ( ( ! V_7 -> V_170 && ( V_164 == V_109 ) ) ||
( V_7 -> V_170 && ( V_164 == V_110 ) ) ) {
F_46 ( & V_169 ) ;
return - V_162 ;
}
if ( V_164 == V_109 )
V_7 -> V_170 = false ;
else if ( V_164 == V_110 )
V_7 -> V_170 = true ;
F_46 ( & V_169 ) ;
V_65 = V_7 -> V_56 -> V_56 ( V_7 , V_164 ) ;
if ( ! V_65 ) {
if ( V_164 == V_171 )
V_7 -> V_56 -> V_172 ++ ;
else if ( V_164 == V_141 )
V_7 -> V_56 -> V_172 -- ;
} else {
F_45 ( & V_169 ) ;
if ( V_164 == V_109 )
V_7 -> V_170 = true ;
else if ( V_164 == V_110 )
V_7 -> V_170 = false ;
F_46 ( & V_169 ) ;
}
if ( ( V_164 != V_110 ) || V_65 )
F_21 ( V_7 -> V_56 -> V_30 ) ;
if ( ( V_164 == V_109 ) && ! V_65 )
F_21 ( V_7 -> V_56 -> V_30 ) ;
return V_65 ;
}
int F_145 ( struct V_51 * V_56 )
{
int V_57 ;
if ( ! V_56 )
return - V_58 ;
if ( F_3 () )
return - V_161 ;
F_45 ( & V_64 ) ;
V_56 -> V_172 = 0 ;
V_57 = - V_162 ;
if ( F_41 ( V_56 -> V_54 ) == NULL ) {
V_57 = 0 ;
F_146 ( & V_56 -> V_173 , & V_174 ) ;
}
F_46 ( & V_64 ) ;
return V_57 ;
}
void F_147 ( struct V_51 * V_56 )
{
#ifdef F_94
int V_10 ;
#endif
if ( ! V_56 )
return;
if ( F_3 () )
return;
#ifdef F_94
F_148 (cpu) {
if ( F_149 ( V_10 ) )
continue;
if ( ! strcmp ( F_18 ( V_133 , V_10 ) , V_56 -> V_54 ) )
strcpy ( F_18 ( V_133 , V_10 ) , L_55 ) ;
}
#endif
F_45 ( & V_64 ) ;
F_150 ( & V_56 -> V_173 ) ;
F_46 ( & V_64 ) ;
return;
}
int F_53 ( struct V_6 * V_7 , unsigned int V_10 )
{
struct V_6 * V_149 ;
if ( ! V_7 )
return - V_58 ;
V_149 = F_22 ( V_10 ) ;
if ( ! V_149 )
return - V_58 ;
memcpy ( V_7 , V_149 , sizeof( struct V_6 ) ) ;
F_26 ( V_149 ) ;
return 0 ;
}
static int F_54 ( struct V_6 * V_24 ,
struct V_6 * V_7 )
{
int V_65 = 0 , V_175 = 1 ;
F_29 ( L_56 , V_7 -> V_10 ,
V_7 -> V_129 , V_7 -> V_130 ) ;
memcpy ( & V_7 -> V_82 , & V_24 -> V_82 ,
sizeof( struct V_176 ) ) ;
if ( V_7 -> V_129 > V_24 -> V_130 || V_7 -> V_130 < V_24 -> V_129 ) {
V_65 = - V_58 ;
goto V_177;
}
V_65 = V_4 -> V_178 ( V_7 ) ;
if ( V_65 )
goto V_177;
F_109 ( & V_131 ,
V_179 , V_7 ) ;
F_109 ( & V_131 ,
V_180 , V_7 ) ;
V_65 = V_4 -> V_178 ( V_7 ) ;
if ( V_65 )
goto V_177;
F_109 ( & V_131 ,
V_181 , V_7 ) ;
V_24 -> V_129 = V_7 -> V_129 ;
V_24 -> V_130 = V_7 -> V_130 ;
F_29 ( L_57 ,
V_24 -> V_129 , V_24 -> V_130 ) ;
if ( V_4 -> V_60 ) {
V_24 -> V_7 = V_7 -> V_7 ;
F_29 ( L_58 ) ;
V_65 = V_4 -> V_60 ( V_7 ) ;
} else {
if ( V_7 -> V_56 != V_24 -> V_56 ) {
struct V_51 * V_182 = V_24 -> V_56 ;
F_29 ( L_59 ) ;
if ( V_24 -> V_56 ) {
F_91 ( V_24 , V_109 ) ;
F_70 ( V_7 -> V_10 ) ;
F_91 ( V_24 ,
V_141 ) ;
F_69 ( V_7 -> V_10 ) ;
}
V_24 -> V_56 = V_7 -> V_56 ;
if ( ! F_91 ( V_24 , V_171 ) ) {
if ( ! F_91 ( V_24 , V_110 ) ) {
V_175 = 0 ;
} else {
F_70 ( V_7 -> V_10 ) ;
F_91 ( V_24 ,
V_141 ) ;
F_69 ( V_7 -> V_10 ) ;
}
}
if ( V_175 ) {
F_29 ( L_60 ,
V_24 -> V_56 -> V_54 ) ;
if ( V_182 ) {
V_24 -> V_56 = V_182 ;
F_91 ( V_24 ,
V_171 ) ;
F_91 ( V_24 ,
V_110 ) ;
}
V_65 = - V_58 ;
goto V_177;
}
}
F_29 ( L_61 ) ;
F_91 ( V_24 , V_111 ) ;
}
V_177:
return V_65 ;
}
int F_124 ( unsigned int V_10 )
{
struct V_6 * V_24 = F_22 ( V_10 ) ;
struct V_6 V_7 ;
int V_65 ;
if ( ! V_24 ) {
V_65 = - V_161 ;
goto V_88;
}
if ( F_97 ( F_69 ( V_10 ) ) ) {
V_65 = - V_58 ;
goto V_89;
}
F_29 ( L_62 , V_10 ) ;
memcpy ( & V_7 , V_24 , sizeof( struct V_6 ) ) ;
V_7 . V_129 = V_24 -> V_71 . V_129 ;
V_7 . V_130 = V_24 -> V_71 . V_130 ;
V_7 . V_7 = V_24 -> V_71 . V_7 ;
V_7 . V_56 = V_24 -> V_71 . V_56 ;
if ( V_4 -> V_103 ) {
V_7 . V_50 = V_4 -> V_103 ( V_10 ) ;
if ( ! V_24 -> V_50 ) {
F_29 ( L_63 ) ;
V_24 -> V_50 = V_7 . V_50 ;
} else {
if ( V_24 -> V_50 != V_7 . V_50 && V_4 -> V_63 )
F_125 ( V_10 , V_24 -> V_50 ,
V_7 . V_50 ) ;
}
}
V_65 = F_54 ( V_24 , & V_7 ) ;
F_70 ( V_10 ) ;
V_89:
F_26 ( V_24 ) ;
V_88:
return V_65 ;
}
static int F_151 ( struct V_153 * V_183 ,
unsigned long V_184 , void * V_185 )
{
unsigned int V_10 = ( unsigned long ) V_185 ;
struct V_97 * V_99 ;
V_99 = F_82 ( V_10 ) ;
if ( V_99 ) {
switch ( V_184 ) {
case V_186 :
case V_187 :
F_93 ( V_99 , NULL ) ;
break;
case V_188 :
case V_189 :
F_116 ( V_99 , NULL ) ;
break;
case V_190 :
case V_191 :
F_93 ( V_99 , NULL ) ;
break;
}
}
return V_192 ;
}
int F_152 ( struct V_4 * V_193 )
{
unsigned long V_25 ;
int V_65 ;
if ( F_3 () )
return - V_161 ;
if ( ! V_193 || ! V_193 -> V_178 || ! V_193 -> V_126 ||
( ( ! V_193 -> V_60 ) && ( ! V_193 -> V_63 ) ) )
return - V_58 ;
F_29 ( L_64 , V_193 -> V_54 ) ;
if ( V_193 -> V_60 )
V_193 -> V_25 |= V_36 ;
F_86 ( & V_28 , V_25 ) ;
if ( V_4 ) {
F_87 ( & V_28 , V_25 ) ;
return - V_162 ;
}
V_4 = V_193 ;
F_87 ( & V_28 , V_25 ) ;
V_65 = F_153 ( & V_194 ) ;
if ( V_65 )
goto V_195;
if ( ! ( V_4 -> V_25 & V_196 ) ) {
int V_72 ;
V_65 = - V_161 ;
for ( V_72 = 0 ; V_72 < V_26 ; V_72 ++ )
if ( F_154 ( V_72 ) && F_18 ( V_31 , V_72 ) ) {
V_65 = 0 ;
break;
}
if ( V_65 ) {
F_29 ( L_65 ,
V_193 -> V_54 ) ;
goto V_197;
}
}
F_155 ( & V_198 ) ;
F_29 ( L_66 , V_193 -> V_54 ) ;
return 0 ;
V_197:
F_156 ( & V_194 ) ;
V_195:
F_86 ( & V_28 , V_25 ) ;
V_4 = NULL ;
F_87 ( & V_28 , V_25 ) ;
return V_65 ;
}
int F_157 ( struct V_4 * V_199 )
{
unsigned long V_25 ;
if ( ! V_4 || ( V_199 != V_4 ) )
return - V_58 ;
F_29 ( L_67 , V_199 -> V_54 ) ;
F_156 ( & V_194 ) ;
F_158 ( & V_198 ) ;
F_86 ( & V_28 , V_25 ) ;
V_4 = NULL ;
F_87 ( & V_28 , V_25 ) ;
return 0 ;
}
static int T_1 F_159 ( void )
{
int V_10 ;
if ( F_3 () )
return - V_161 ;
F_160 (cpu) {
F_18 ( V_106 , V_10 ) = - 1 ;
F_161 ( & F_18 ( V_200 , V_10 ) ) ;
}
V_9 = F_162 () ;
F_32 ( ! V_9 ) ;
F_163 ( & V_201 ) ;
return 0 ;
}
