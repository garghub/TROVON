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
struct V_6 * F_15 ( unsigned int V_10 )
{
struct V_6 * V_7 = NULL ;
unsigned long V_23 ;
if ( F_3 () || ( V_10 >= V_24 ) )
return NULL ;
if ( ! F_16 ( & V_25 ) )
return NULL ;
F_17 ( & V_26 , V_23 ) ;
if ( V_4 ) {
V_7 = F_18 ( V_27 , V_10 ) ;
if ( V_7 )
F_19 ( & V_7 -> V_8 ) ;
}
F_20 ( & V_26 , V_23 ) ;
if ( ! V_7 )
F_21 ( & V_25 ) ;
return V_7 ;
}
void F_22 ( struct V_6 * V_7 )
{
if ( F_3 () )
return;
F_23 ( & V_7 -> V_8 ) ;
F_21 ( & V_25 ) ;
}
static void F_24 ( unsigned long V_28 , struct V_29 * V_30 )
{
if ( V_30 -> V_23 & V_31 )
return;
if ( ! V_32 ) {
V_33 = V_34 ;
V_32 = V_30 -> V_35 ;
F_25 ( L_1
L_2 , V_33 , V_32 ) ;
}
if ( ( V_28 == V_36 && V_30 -> V_35 != V_30 -> V_37 ) ||
( V_28 == V_38 || V_28 == V_39 ) ) {
V_34 = F_26 ( V_33 , V_32 ,
V_30 -> V_37 ) ;
F_25 ( L_3
L_4 , V_34 , V_30 -> V_37 ) ;
}
}
static inline void F_24 ( unsigned long V_28 , struct V_29 * V_30 )
{
return;
}
static void F_27 ( struct V_6 * V_7 ,
struct V_29 * V_40 , unsigned int V_41 )
{
F_28 ( F_29 () ) ;
if ( F_3 () )
return;
V_40 -> V_23 = V_4 -> V_23 ;
F_25 ( L_5 ,
V_41 , V_40 -> V_37 ) ;
switch ( V_41 ) {
case V_42 :
if ( ! ( V_4 -> V_23 & V_31 ) ) {
if ( ( V_7 ) && ( V_7 -> V_10 == V_40 -> V_10 ) &&
( V_7 -> V_43 ) && ( V_7 -> V_43 != V_40 -> V_35 ) ) {
F_25 ( L_6
L_7 ,
V_40 -> V_35 , V_7 -> V_43 ) ;
V_40 -> V_35 = V_7 -> V_43 ;
}
}
F_30 ( & V_1 ,
V_42 , V_40 ) ;
F_24 ( V_42 , V_40 ) ;
break;
case V_36 :
F_24 ( V_36 , V_40 ) ;
F_25 ( L_8 , ( unsigned long ) V_40 -> V_37 ,
( unsigned long ) V_40 -> V_10 ) ;
F_31 ( V_40 -> V_37 , V_40 -> V_10 ) ;
F_30 ( & V_1 ,
V_36 , V_40 ) ;
if ( F_32 ( V_7 ) && F_32 ( V_7 -> V_10 == V_40 -> V_10 ) )
V_7 -> V_43 = V_40 -> V_37 ;
break;
}
}
void F_33 ( struct V_6 * V_7 ,
struct V_29 * V_40 , unsigned int V_41 )
{
F_34 (freqs->cpu, policy->cpus)
F_27 ( V_7 , V_40 , V_41 ) ;
}
static struct V_44 * F_35 ( const char * V_45 )
{
struct V_44 * V_46 ;
F_36 (t, &cpufreq_governor_list, governor_list)
if ( ! F_37 ( V_45 , V_46 -> V_47 , V_48 ) )
return V_46 ;
return NULL ;
}
static int F_38 ( char * V_45 , unsigned int * V_7 ,
struct V_44 * * V_49 )
{
int V_50 = - V_51 ;
if ( ! V_4 )
goto V_52;
if ( V_4 -> V_53 ) {
if ( ! F_37 ( V_45 , L_9 , V_48 ) ) {
* V_7 = V_54 ;
V_50 = 0 ;
} else if ( ! F_37 ( V_45 , L_10 ,
V_48 ) ) {
* V_7 = V_55 ;
V_50 = 0 ;
}
} else if ( V_4 -> V_56 ) {
struct V_44 * V_46 ;
F_39 ( & V_57 ) ;
V_46 = F_35 ( V_45 ) ;
if ( V_46 == NULL ) {
int V_58 ;
F_40 ( & V_57 ) ;
V_58 = F_41 ( L_11 , V_45 ) ;
F_39 ( & V_57 ) ;
if ( V_58 == 0 )
V_46 = F_35 ( V_45 ) ;
}
if ( V_46 != NULL ) {
* V_49 = V_46 ;
V_50 = 0 ;
}
F_40 ( & V_57 ) ;
}
V_52:
return V_50 ;
}
static T_3 F_42 ( struct V_6 * V_7 ,
char * V_59 )
{
unsigned int V_60 = F_43 ( V_7 -> V_10 ) ;
if ( ! V_60 )
return sprintf ( V_59 , L_12 ) ;
return sprintf ( V_59 , L_13 , V_60 ) ;
}
static T_3 F_44 ( struct V_6 * V_7 , char * V_59 )
{
if ( V_7 -> V_7 == V_55 )
return sprintf ( V_59 , L_14 ) ;
else if ( V_7 -> V_7 == V_54 )
return sprintf ( V_59 , L_15 ) ;
else if ( V_7 -> V_49 )
return F_45 ( V_59 , V_61 , L_16 ,
V_7 -> V_49 -> V_47 ) ;
return - V_51 ;
}
static T_3 F_46 ( struct V_6 * V_7 ,
const char * V_59 , T_4 V_62 )
{
int V_58 ;
char V_45 [ 16 ] ;
struct V_6 V_63 ;
V_58 = F_47 ( & V_63 , V_7 -> V_10 ) ;
if ( V_58 )
return V_58 ;
V_58 = sscanf ( V_59 , L_17 , V_45 ) ;
if ( V_58 != 1 )
return - V_51 ;
if ( F_38 ( V_45 , & V_63 . V_7 ,
& V_63 . V_49 ) )
return - V_51 ;
V_58 = F_48 ( V_7 , & V_63 ) ;
V_7 -> V_64 . V_7 = V_7 -> V_7 ;
V_7 -> V_64 . V_49 = V_7 -> V_49 ;
if ( V_58 )
return V_58 ;
else
return V_62 ;
}
static T_3 F_49 ( struct V_6 * V_7 , char * V_59 )
{
return F_45 ( V_59 , V_61 , L_16 , V_4 -> V_47 ) ;
}
static T_3 F_50 ( struct V_6 * V_7 ,
char * V_59 )
{
T_3 V_65 = 0 ;
struct V_44 * V_46 ;
if ( ! V_4 -> V_56 ) {
V_65 += sprintf ( V_59 , L_18 ) ;
goto V_52;
}
F_36 (t, &cpufreq_governor_list, governor_list) {
if ( V_65 >= ( T_3 ) ( ( V_66 / sizeof( char ) )
- ( V_48 + 2 ) ) )
goto V_52;
V_65 += F_45 ( & V_59 [ V_65 ] , V_61 , L_19 , V_46 -> V_47 ) ;
}
V_52:
V_65 += sprintf ( & V_59 [ V_65 ] , L_20 ) ;
return V_65 ;
}
T_3 F_51 ( const struct V_67 * V_68 , char * V_59 )
{
T_3 V_65 = 0 ;
unsigned int V_10 ;
F_34 (cpu, mask) {
if ( V_65 )
V_65 += F_45 ( & V_59 [ V_65 ] , ( V_66 - V_65 - 2 ) , L_21 ) ;
V_65 += F_45 ( & V_59 [ V_65 ] , ( V_66 - V_65 - 2 ) , L_22 , V_10 ) ;
if ( V_65 >= ( V_66 - 5 ) )
break;
}
V_65 += sprintf ( & V_59 [ V_65 ] , L_20 ) ;
return V_65 ;
}
static T_3 F_52 ( struct V_6 * V_7 , char * V_59 )
{
return F_51 ( V_7 -> V_69 , V_59 ) ;
}
static T_3 F_53 ( struct V_6 * V_7 , char * V_59 )
{
return F_51 ( V_7 -> V_70 , V_59 ) ;
}
static T_3 F_54 ( struct V_6 * V_7 ,
const char * V_59 , T_4 V_62 )
{
unsigned int V_71 = 0 ;
unsigned int V_58 ;
if ( ! V_7 -> V_49 || ! V_7 -> V_49 -> V_72 )
return - V_51 ;
V_58 = sscanf ( V_59 , L_22 , & V_71 ) ;
if ( V_58 != 1 )
return - V_51 ;
V_7 -> V_49 -> V_72 ( V_7 , V_71 ) ;
return V_62 ;
}
static T_3 F_55 ( struct V_6 * V_7 , char * V_59 )
{
if ( ! V_7 -> V_49 || ! V_7 -> V_49 -> V_73 )
return sprintf ( V_59 , L_23 ) ;
return V_7 -> V_49 -> V_73 ( V_7 , V_59 ) ;
}
static T_3 F_56 ( struct V_6 * V_7 , char * V_59 )
{
unsigned int V_74 ;
int V_58 ;
if ( V_4 -> V_75 ) {
V_58 = V_4 -> V_75 ( V_7 -> V_10 , & V_74 ) ;
if ( ! V_58 )
return sprintf ( V_59 , L_13 , V_74 ) ;
}
return sprintf ( V_59 , L_13 , V_7 -> V_76 . V_77 ) ;
}
static T_3 F_57 ( struct V_5 * V_8 , struct V_78 * V_79 , char * V_59 )
{
struct V_6 * V_7 = F_58 ( V_8 ) ;
struct V_80 * V_81 = F_59 ( V_79 ) ;
T_3 V_58 = - V_51 ;
if ( ! F_16 ( & V_25 ) )
goto exit;
if ( F_60 ( V_7 -> V_10 ) < 0 )
goto F_21;
if ( V_81 -> F_57 )
V_58 = V_81 -> F_57 ( V_7 , V_59 ) ;
else
V_58 = - V_82 ;
F_61 ( V_7 -> V_10 ) ;
F_21:
F_21 ( & V_25 ) ;
exit:
return V_58 ;
}
static T_3 F_62 ( struct V_5 * V_8 , struct V_78 * V_79 ,
const char * V_59 , T_4 V_62 )
{
struct V_6 * V_7 = F_58 ( V_8 ) ;
struct V_80 * V_81 = F_59 ( V_79 ) ;
T_3 V_58 = - V_51 ;
F_63 () ;
if ( ! F_64 ( V_7 -> V_10 ) )
goto V_83;
if ( ! F_16 ( & V_25 ) )
goto V_83;
if ( F_65 ( V_7 -> V_10 ) < 0 )
goto F_21;
if ( V_81 -> F_62 )
V_58 = V_81 -> F_62 ( V_7 , V_59 , V_62 ) ;
else
V_58 = - V_82 ;
F_66 ( V_7 -> V_10 ) ;
F_21:
F_21 ( & V_25 ) ;
V_83:
F_67 () ;
return V_58 ;
}
static void F_68 ( struct V_5 * V_8 )
{
struct V_6 * V_7 = F_58 ( V_8 ) ;
F_25 ( L_24 ) ;
F_69 ( & V_7 -> V_84 ) ;
}
int F_70 ( void )
{
if ( ! V_85 ++ )
return F_71 ( V_9 ,
& V_86 . V_87 -> V_8 , L_25 , L_26 ) ;
return 0 ;
}
void F_72 ( void )
{
if ( ! -- V_85 )
F_73 ( V_9 ) ;
}
int F_74 ( const struct V_78 * V_79 )
{
int V_58 = F_70 () ;
if ( ! V_58 ) {
V_58 = F_75 ( V_9 , V_79 ) ;
if ( V_58 )
F_72 () ;
}
return V_58 ;
}
void F_76 ( const struct V_78 * V_79 )
{
F_77 ( V_9 , V_79 ) ;
F_72 () ;
}
static int F_78 ( struct V_6 * V_7 )
{
unsigned int V_88 ;
int V_58 = 0 ;
F_34 (j, policy->cpus) {
struct V_89 * V_90 ;
if ( V_88 == V_7 -> V_10 )
continue;
F_25 ( L_27 , V_88 ) ;
V_90 = F_79 ( V_88 ) ;
V_58 = F_80 ( & V_90 -> V_8 , & V_7 -> V_8 ,
L_26 ) ;
if ( V_58 )
break;
}
return V_58 ;
}
static int F_81 ( struct V_6 * V_7 ,
struct V_89 * V_91 )
{
struct V_80 * * V_92 ;
int V_58 = 0 ;
V_58 = F_82 ( & V_7 -> V_8 , & V_93 ,
& V_91 -> V_8 , L_26 ) ;
if ( V_58 )
return V_58 ;
V_92 = V_4 -> V_79 ;
while ( ( V_92 ) && ( * V_92 ) ) {
V_58 = F_75 ( & V_7 -> V_8 , & ( ( * V_92 ) -> V_79 ) ) ;
if ( V_58 )
goto V_94;
V_92 ++ ;
}
if ( V_4 -> V_95 ) {
V_58 = F_75 ( & V_7 -> V_8 , & V_96 . V_79 ) ;
if ( V_58 )
goto V_94;
}
if ( V_4 -> V_56 ) {
V_58 = F_75 ( & V_7 -> V_8 , & V_97 . V_79 ) ;
if ( V_58 )
goto V_94;
}
if ( V_4 -> V_75 ) {
V_58 = F_75 ( & V_7 -> V_8 , & V_75 . V_79 ) ;
if ( V_58 )
goto V_94;
}
V_58 = F_78 ( V_7 ) ;
if ( V_58 )
goto V_94;
return V_58 ;
V_94:
F_23 ( & V_7 -> V_8 ) ;
F_83 ( & V_7 -> V_84 ) ;
return V_58 ;
}
static void F_84 ( struct V_6 * V_7 )
{
struct V_6 V_63 ;
int V_58 = 0 ;
memcpy ( & V_63 , V_7 , sizeof( * V_7 ) ) ;
V_7 -> V_49 = NULL ;
V_58 = F_48 ( V_7 , & V_63 ) ;
V_7 -> V_64 . V_7 = V_7 -> V_7 ;
V_7 -> V_64 . V_49 = V_7 -> V_49 ;
if ( V_58 ) {
F_25 ( L_28 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_7 ) ;
}
}
static int F_85 ( struct V_6 * V_7 ,
unsigned int V_10 , struct V_89 * V_91 ,
bool V_98 )
{
int V_58 = 0 , V_99 = ! ! V_4 -> V_56 ;
unsigned long V_23 ;
if ( V_99 ) {
V_58 = F_86 ( V_7 , V_100 ) ;
if ( V_58 ) {
F_87 ( L_29 , V_101 ) ;
return V_58 ;
}
}
F_65 ( V_7 -> V_10 ) ;
F_88 ( & V_26 , V_23 ) ;
F_89 ( V_10 , V_7 -> V_70 ) ;
F_18 ( V_27 , V_10 ) = V_7 ;
F_90 ( & V_26 , V_23 ) ;
F_66 ( V_7 -> V_10 ) ;
if ( V_99 ) {
if ( ( V_58 = F_86 ( V_7 , V_102 ) ) ||
( V_58 = F_86 ( V_7 , V_103 ) ) ) {
F_87 ( L_30 , V_101 ) ;
return V_58 ;
}
}
if ( ! V_98 )
V_58 = F_80 ( & V_91 -> V_8 , & V_7 -> V_8 , L_26 ) ;
return V_58 ;
}
static struct V_6 * F_91 ( unsigned int V_10 )
{
struct V_6 * V_7 ;
unsigned long V_23 ;
F_17 ( & V_26 , V_23 ) ;
V_7 = F_18 ( V_104 , V_10 ) ;
F_20 ( & V_26 , V_23 ) ;
return V_7 ;
}
static struct V_6 * F_92 ( void )
{
struct V_6 * V_7 ;
V_7 = F_93 ( sizeof( * V_7 ) , V_105 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_94 ( & V_7 -> V_70 , V_105 ) )
goto V_106;
if ( ! F_95 ( & V_7 -> V_69 , V_105 ) )
goto V_107;
F_96 ( & V_7 -> V_108 ) ;
return V_7 ;
V_107:
F_97 ( V_7 -> V_70 ) ;
V_106:
F_98 ( V_7 ) ;
return NULL ;
}
static void F_99 ( struct V_6 * V_7 )
{
F_97 ( V_7 -> V_69 ) ;
F_97 ( V_7 -> V_70 ) ;
F_98 ( V_7 ) ;
}
static void F_100 ( struct V_6 * V_7 , unsigned int V_10 )
{
if ( V_10 == V_7 -> V_10 )
return;
F_101 ( & F_18 ( V_109 , V_7 -> V_10 ) ) ;
V_7 -> V_110 = V_7 -> V_10 ;
V_7 -> V_10 = V_10 ;
F_102 ( & F_18 ( V_109 , V_7 -> V_110 ) ) ;
#ifdef F_103
F_104 ( V_7 ) ;
#endif
F_105 ( & V_111 ,
V_112 , V_7 ) ;
}
static int F_106 ( struct V_89 * V_91 , struct V_113 * V_114 ,
bool V_98 )
{
unsigned int V_88 , V_10 = V_91 -> V_115 ;
int V_58 = - V_116 ;
struct V_6 * V_7 ;
unsigned long V_23 ;
#ifdef F_107
struct V_6 * V_117 ;
struct V_44 * V_118 ;
#endif
if ( F_108 ( V_10 ) )
return 0 ;
F_25 ( L_31 , V_10 ) ;
#ifdef F_109
V_7 = F_15 ( V_10 ) ;
if ( F_110 ( V_7 ) ) {
F_22 ( V_7 ) ;
return 0 ;
}
#endif
if ( ! F_16 ( & V_25 ) )
return 0 ;
#ifdef F_107
F_17 ( & V_26 , V_23 ) ;
F_36 (tpolicy, &cpufreq_policy_list, policy_list) {
if ( F_111 ( V_10 , V_117 -> V_69 ) ) {
F_20 ( & V_26 , V_23 ) ;
V_58 = F_85 ( V_117 , V_10 , V_91 , V_98 ) ;
F_21 ( & V_25 ) ;
return V_58 ;
}
}
F_20 ( & V_26 , V_23 ) ;
#endif
if ( V_98 )
V_7 = F_91 ( V_10 ) ;
else
V_7 = F_92 () ;
if ( ! V_7 )
goto V_119;
if ( V_98 && V_10 != V_7 -> V_10 )
F_100 ( V_7 , V_10 ) ;
else
V_7 -> V_10 = V_10 ;
V_7 -> V_49 = V_120 ;
F_112 ( V_7 -> V_70 , F_113 ( V_10 ) ) ;
F_114 ( & V_7 -> V_84 ) ;
F_115 ( & V_7 -> V_121 , V_122 ) ;
V_58 = V_4 -> V_123 ( V_7 ) ;
if ( V_58 ) {
F_25 ( L_32 ) ;
goto V_124;
}
F_116 ( V_7 -> V_69 , V_7 -> V_69 , V_7 -> V_70 ) ;
F_117 ( V_7 -> V_70 , V_7 -> V_70 , V_125 ) ;
V_7 -> V_64 . V_126 = V_7 -> V_126 ;
V_7 -> V_64 . V_127 = V_7 -> V_127 ;
F_105 ( & V_111 ,
V_128 , V_7 ) ;
#ifdef F_107
V_118 = F_35 ( F_18 ( V_129 , V_10 ) ) ;
if ( V_118 ) {
V_7 -> V_49 = V_118 ;
F_25 ( L_33 ,
V_7 -> V_49 -> V_47 , V_10 ) ;
}
#endif
F_88 ( & V_26 , V_23 ) ;
F_34 (j, policy->cpus)
F_18 ( V_27 , V_88 ) = V_7 ;
F_90 ( & V_26 , V_23 ) ;
if ( ! V_98 ) {
V_58 = F_81 ( V_7 , V_91 ) ;
if ( V_58 )
goto V_130;
}
F_88 ( & V_26 , V_23 ) ;
F_118 ( & V_7 -> V_108 , & V_131 ) ;
F_90 ( & V_26 , V_23 ) ;
F_84 ( V_7 ) ;
F_119 ( & V_7 -> V_8 , V_132 ) ;
F_21 ( & V_25 ) ;
F_25 ( L_34 ) ;
return 0 ;
V_130:
F_88 ( & V_26 , V_23 ) ;
F_34 (j, policy->cpus)
F_18 ( V_27 , V_88 ) = NULL ;
F_90 ( & V_26 , V_23 ) ;
V_124:
F_99 ( V_7 ) ;
V_119:
F_21 ( & V_25 ) ;
return V_58 ;
}
static int F_120 ( struct V_89 * V_91 , struct V_113 * V_114 )
{
return F_106 ( V_91 , V_114 , false ) ;
}
static int F_121 ( struct V_6 * V_7 ,
unsigned int V_133 , bool V_98 )
{
struct V_89 * V_90 ;
int V_58 ;
V_90 = F_79 ( F_122 ( V_7 -> V_70 , V_133 ) ) ;
if ( V_98 )
return V_90 -> V_115 ;
F_123 ( & V_90 -> V_8 , L_26 ) ;
V_58 = F_124 ( & V_7 -> V_8 , & V_90 -> V_8 ) ;
if ( V_58 ) {
F_87 ( L_35 , V_101 , V_58 ) ;
F_125 ( F_65 ( V_133 ) ) ;
F_89 ( V_133 , V_7 -> V_70 ) ;
F_66 ( V_133 ) ;
V_58 = F_80 ( & V_90 -> V_8 , & V_7 -> V_8 ,
L_26 ) ;
return - V_51 ;
}
return V_90 -> V_115 ;
}
static int F_126 ( struct V_89 * V_91 ,
struct V_113 * V_114 ,
bool V_98 )
{
unsigned int V_10 = V_91 -> V_115 , V_70 ;
int V_134 , V_58 ;
unsigned long V_23 ;
struct V_6 * V_7 ;
F_25 ( L_36 , V_101 , V_10 ) ;
F_88 ( & V_26 , V_23 ) ;
V_7 = F_18 ( V_27 , V_10 ) ;
if ( V_98 )
F_18 ( V_104 , V_10 ) = V_7 ;
F_90 ( & V_26 , V_23 ) ;
if ( ! V_7 ) {
F_25 ( L_37 , V_101 ) ;
return - V_51 ;
}
if ( V_4 -> V_56 ) {
V_58 = F_86 ( V_7 , V_100 ) ;
if ( V_58 ) {
F_87 ( L_29 , V_101 ) ;
return V_58 ;
}
}
#ifdef F_107
if ( ! V_4 -> V_53 )
strncpy ( F_18 ( V_129 , V_10 ) ,
V_7 -> V_49 -> V_47 , V_48 ) ;
#endif
F_60 ( V_10 ) ;
V_70 = F_127 ( V_7 -> V_70 ) ;
F_61 ( V_10 ) ;
if ( V_10 != V_7 -> V_10 ) {
if ( ! V_98 )
F_123 ( & V_91 -> V_8 , L_26 ) ;
} else if ( V_70 > 1 ) {
V_134 = F_121 ( V_7 , V_10 , V_98 ) ;
if ( V_134 >= 0 ) {
F_100 ( V_7 , V_134 ) ;
if ( ! V_98 ) {
F_25 ( L_38
L_39 , V_101 , V_134 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_128 ( struct V_89 * V_91 ,
struct V_113 * V_114 ,
bool V_98 )
{
unsigned int V_10 = V_91 -> V_115 , V_70 ;
int V_58 ;
unsigned long V_23 ;
struct V_6 * V_7 ;
struct V_5 * V_8 ;
struct V_135 * V_136 ;
F_17 ( & V_26 , V_23 ) ;
V_7 = F_18 ( V_27 , V_10 ) ;
F_20 ( & V_26 , V_23 ) ;
if ( ! V_7 ) {
F_25 ( L_37 , V_101 ) ;
return - V_51 ;
}
F_125 ( F_65 ( V_10 ) ) ;
V_70 = F_127 ( V_7 -> V_70 ) ;
if ( V_70 > 1 )
F_129 ( V_10 , V_7 -> V_70 ) ;
F_66 ( V_10 ) ;
if ( V_70 == 1 ) {
if ( V_4 -> V_56 ) {
V_58 = F_86 ( V_7 ,
V_137 ) ;
if ( V_58 ) {
F_87 ( L_40 ,
V_101 ) ;
return V_58 ;
}
}
if ( ! V_98 ) {
F_60 ( V_10 ) ;
V_8 = & V_7 -> V_8 ;
V_136 = & V_7 -> V_84 ;
F_61 ( V_10 ) ;
F_23 ( V_8 ) ;
F_25 ( L_41 ) ;
F_83 ( V_136 ) ;
F_25 ( L_42 ) ;
}
if ( V_4 -> exit )
V_4 -> exit ( V_7 ) ;
F_88 ( & V_26 , V_23 ) ;
F_130 ( & V_7 -> V_108 ) ;
F_90 ( & V_26 , V_23 ) ;
if ( ! V_98 )
F_99 ( V_7 ) ;
} else {
if ( V_4 -> V_56 ) {
if ( ( V_58 = F_86 ( V_7 , V_102 ) ) ||
( V_58 = F_86 ( V_7 , V_103 ) ) ) {
F_87 ( L_30 ,
V_101 ) ;
return V_58 ;
}
}
}
F_18 ( V_27 , V_10 ) = NULL ;
return 0 ;
}
static inline int F_131 ( struct V_89 * V_91 ,
struct V_113 * V_114 ,
bool V_98 )
{
int V_58 ;
V_58 = F_126 ( V_91 , V_114 , V_98 ) ;
if ( ! V_58 )
V_58 = F_128 ( V_91 , V_114 , V_98 ) ;
return V_58 ;
}
static int F_132 ( struct V_89 * V_91 , struct V_113 * V_114 )
{
unsigned int V_10 = V_91 -> V_115 ;
int V_138 ;
if ( F_108 ( V_10 ) )
return 0 ;
V_138 = F_131 ( V_91 , V_114 , false ) ;
return V_138 ;
}
static void V_122 ( struct V_139 * V_140 )
{
struct V_6 * V_7 =
F_133 ( V_140 , struct V_6 , V_121 ) ;
unsigned int V_10 = V_7 -> V_10 ;
F_25 ( L_43 , V_10 ) ;
F_134 ( V_10 ) ;
}
static void F_135 ( unsigned int V_10 , unsigned int V_141 ,
unsigned int V_142 )
{
struct V_6 * V_7 ;
struct V_29 V_40 ;
unsigned long V_23 ;
F_25 ( L_44
L_45 , V_141 , V_142 ) ;
V_40 . V_35 = V_141 ;
V_40 . V_37 = V_142 ;
F_17 ( & V_26 , V_23 ) ;
V_7 = F_18 ( V_27 , V_10 ) ;
F_20 ( & V_26 , V_23 ) ;
F_33 ( V_7 , & V_40 , V_42 ) ;
F_33 ( V_7 , & V_40 , V_36 ) ;
}
unsigned int F_136 ( unsigned int V_10 )
{
struct V_6 * V_7 ;
unsigned int V_143 = 0 ;
if ( V_4 && V_4 -> V_53 && V_4 -> V_95 )
return V_4 -> V_95 ( V_10 ) ;
V_7 = F_15 ( V_10 ) ;
if ( V_7 ) {
V_143 = V_7 -> V_43 ;
F_22 ( V_7 ) ;
}
return V_143 ;
}
unsigned int F_137 ( unsigned int V_10 )
{
struct V_6 * V_7 = F_15 ( V_10 ) ;
unsigned int V_143 = 0 ;
if ( V_7 ) {
V_143 = V_7 -> V_127 ;
F_22 ( V_7 ) ;
}
return V_143 ;
}
static unsigned int F_43 ( unsigned int V_10 )
{
struct V_6 * V_7 = F_18 ( V_27 , V_10 ) ;
unsigned int V_143 = 0 ;
if ( ! V_4 -> V_95 )
return V_143 ;
V_143 = V_4 -> V_95 ( V_10 ) ;
if ( V_143 && V_7 -> V_43 &&
! ( V_4 -> V_23 & V_31 ) ) {
if ( F_110 ( V_143 != V_7 -> V_43 ) ) {
F_135 ( V_10 , V_7 -> V_43 , V_143 ) ;
F_138 ( & V_7 -> V_121 ) ;
}
}
return V_143 ;
}
unsigned int F_139 ( unsigned int V_10 )
{
unsigned int V_143 = 0 ;
if ( F_3 () || ! V_4 )
return - V_144 ;
if ( ! F_16 ( & V_25 ) )
return 0 ;
if ( F_110 ( F_60 ( V_10 ) ) )
goto V_145;
V_143 = F_43 ( V_10 ) ;
F_61 ( V_10 ) ;
V_145:
F_21 ( & V_25 ) ;
return V_143 ;
}
static int F_140 ( void )
{
int V_58 = 0 ;
int V_10 = F_141 () ;
struct V_6 * V_7 ;
F_25 ( L_46 , V_10 ) ;
V_7 = F_15 ( V_10 ) ;
if ( ! V_7 )
return 0 ;
if ( V_4 -> V_146 ) {
V_58 = V_4 -> V_146 ( V_7 ) ;
if ( V_58 )
F_142 ( V_147 L_47
L_48 , V_7 -> V_10 ) ;
}
F_22 ( V_7 ) ;
return V_58 ;
}
static void F_143 ( void )
{
int V_58 = 0 ;
int V_10 = F_141 () ;
struct V_6 * V_7 ;
F_25 ( L_49 , V_10 ) ;
V_7 = F_15 ( V_10 ) ;
if ( ! V_7 )
return;
if ( V_4 -> V_148 ) {
V_58 = V_4 -> V_148 ( V_7 ) ;
if ( V_58 ) {
F_142 ( V_147 L_50
L_48 , V_7 -> V_10 ) ;
goto V_149;
}
}
F_138 ( & V_7 -> V_121 ) ;
V_149:
F_22 ( V_7 ) ;
}
const char * F_144 ( void )
{
if ( V_4 )
return V_4 -> V_47 ;
return NULL ;
}
int F_145 ( struct V_150 * V_151 , unsigned int V_152 )
{
int V_58 ;
if ( F_3 () )
return - V_51 ;
F_125 ( ! V_2 ) ;
switch ( V_152 ) {
case V_153 :
V_58 = F_146 (
& V_1 , V_151 ) ;
break;
case V_154 :
V_58 = F_147 (
& V_111 , V_151 ) ;
break;
default:
V_58 = - V_51 ;
}
return V_58 ;
}
int F_148 ( struct V_150 * V_151 , unsigned int V_152 )
{
int V_58 ;
if ( F_3 () )
return - V_51 ;
switch ( V_152 ) {
case V_153 :
V_58 = F_149 (
& V_1 , V_151 ) ;
break;
case V_154 :
V_58 = F_150 (
& V_111 , V_151 ) ;
break;
default:
V_58 = - V_51 ;
}
return V_58 ;
}
int F_151 ( struct V_6 * V_7 ,
unsigned int V_155 ,
unsigned int V_156 )
{
int V_138 = - V_51 ;
unsigned int V_157 = V_155 ;
if ( F_3 () )
return - V_158 ;
if ( V_155 > V_7 -> V_127 )
V_155 = V_7 -> V_127 ;
if ( V_155 < V_7 -> V_126 )
V_155 = V_7 -> V_126 ;
F_25 ( L_51 ,
V_7 -> V_10 , V_155 , V_156 , V_157 ) ;
if ( V_155 == V_7 -> V_43 )
return 0 ;
if ( V_4 -> V_56 )
V_138 = V_4 -> V_56 ( V_7 , V_155 , V_156 ) ;
return V_138 ;
}
int F_152 ( struct V_6 * V_7 ,
unsigned int V_155 ,
unsigned int V_156 )
{
int V_58 = - V_51 ;
if ( F_110 ( F_65 ( V_7 -> V_10 ) ) )
goto V_149;
V_58 = F_151 ( V_7 , V_155 , V_156 ) ;
F_66 ( V_7 -> V_10 ) ;
V_149:
return V_58 ;
}
static int F_86 ( struct V_6 * V_7 ,
unsigned int V_159 )
{
int V_58 ;
#ifdef F_153
struct V_44 * V_118 = & V_160 ;
#else
struct V_44 * V_118 = NULL ;
#endif
if ( V_7 -> V_49 -> V_161 &&
V_7 -> V_76 . V_162 >
V_7 -> V_49 -> V_161 ) {
if ( ! V_118 )
return - V_51 ;
else {
F_142 ( V_163 L_52
L_53
L_54 ,
V_7 -> V_49 -> V_47 ,
V_118 -> V_47 ) ;
V_7 -> V_49 = V_118 ;
}
}
if ( V_159 == V_164 )
if ( ! F_154 ( V_7 -> V_49 -> V_165 ) )
return - V_51 ;
F_25 ( L_55 ,
V_7 -> V_10 , V_159 ) ;
F_39 ( & V_166 ) ;
if ( ( V_7 -> V_167 && V_159 == V_102 )
|| ( ! V_7 -> V_167
&& ( V_159 == V_103 || V_159 == V_100 ) ) ) {
F_40 ( & V_166 ) ;
return - V_168 ;
}
if ( V_159 == V_100 )
V_7 -> V_167 = false ;
else if ( V_159 == V_102 )
V_7 -> V_167 = true ;
F_40 ( & V_166 ) ;
V_58 = V_7 -> V_49 -> V_49 ( V_7 , V_159 ) ;
if ( ! V_58 ) {
if ( V_159 == V_164 )
V_7 -> V_49 -> V_169 ++ ;
else if ( V_159 == V_137 )
V_7 -> V_49 -> V_169 -- ;
} else {
F_39 ( & V_166 ) ;
if ( V_159 == V_100 )
V_7 -> V_167 = true ;
else if ( V_159 == V_102 )
V_7 -> V_167 = false ;
F_40 ( & V_166 ) ;
}
if ( ( ( V_159 == V_164 ) && V_58 ) ||
( ( V_159 == V_137 ) && ! V_58 ) )
F_155 ( V_7 -> V_49 -> V_165 ) ;
return V_58 ;
}
int F_156 ( struct V_44 * V_49 )
{
int V_50 ;
if ( ! V_49 )
return - V_51 ;
if ( F_3 () )
return - V_158 ;
F_39 ( & V_57 ) ;
V_49 -> V_169 = 0 ;
V_50 = - V_168 ;
if ( F_35 ( V_49 -> V_47 ) == NULL ) {
V_50 = 0 ;
F_118 ( & V_49 -> V_170 , & V_171 ) ;
}
F_40 ( & V_57 ) ;
return V_50 ;
}
void F_157 ( struct V_44 * V_49 )
{
#ifdef F_107
int V_10 ;
#endif
if ( ! V_49 )
return;
if ( F_3 () )
return;
#ifdef F_107
F_158 (cpu) {
if ( F_64 ( V_10 ) )
continue;
if ( ! strcmp ( F_18 ( V_129 , V_10 ) , V_49 -> V_47 ) )
strcpy ( F_18 ( V_129 , V_10 ) , L_56 ) ;
}
#endif
F_39 ( & V_57 ) ;
F_130 ( & V_49 -> V_170 ) ;
F_40 ( & V_57 ) ;
return;
}
int F_47 ( struct V_6 * V_7 , unsigned int V_10 )
{
struct V_6 * V_172 ;
if ( ! V_7 )
return - V_51 ;
V_172 = F_15 ( V_10 ) ;
if ( ! V_172 )
return - V_51 ;
memcpy ( V_7 , V_172 , sizeof( * V_7 ) ) ;
F_22 ( V_172 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_6 * V_63 )
{
int V_58 = 0 , V_173 = 1 ;
F_25 ( L_57 , V_63 -> V_10 ,
V_63 -> V_126 , V_63 -> V_127 ) ;
memcpy ( & V_63 -> V_76 , & V_7 -> V_76 , sizeof( V_7 -> V_76 ) ) ;
if ( V_63 -> V_126 > V_7 -> V_127 || V_63 -> V_127 < V_7 -> V_126 ) {
V_58 = - V_51 ;
goto V_174;
}
V_58 = V_4 -> V_175 ( V_63 ) ;
if ( V_58 )
goto V_174;
F_105 ( & V_111 ,
V_176 , V_63 ) ;
F_105 ( & V_111 ,
V_177 , V_63 ) ;
V_58 = V_4 -> V_175 ( V_63 ) ;
if ( V_58 )
goto V_174;
F_105 ( & V_111 ,
V_178 , V_63 ) ;
V_7 -> V_126 = V_63 -> V_126 ;
V_7 -> V_127 = V_63 -> V_127 ;
F_25 ( L_58 ,
V_7 -> V_126 , V_7 -> V_127 ) ;
if ( V_4 -> V_53 ) {
V_7 -> V_7 = V_63 -> V_7 ;
F_25 ( L_59 ) ;
V_58 = V_4 -> V_53 ( V_63 ) ;
} else {
if ( V_63 -> V_49 != V_7 -> V_49 ) {
struct V_44 * V_179 = V_7 -> V_49 ;
F_25 ( L_60 ) ;
if ( V_7 -> V_49 ) {
F_86 ( V_7 , V_100 ) ;
F_66 ( V_63 -> V_10 ) ;
F_86 ( V_7 ,
V_137 ) ;
F_65 ( V_63 -> V_10 ) ;
}
V_7 -> V_49 = V_63 -> V_49 ;
if ( ! F_86 ( V_7 , V_164 ) ) {
if ( ! F_86 ( V_7 , V_102 ) ) {
V_173 = 0 ;
} else {
F_66 ( V_63 -> V_10 ) ;
F_86 ( V_7 ,
V_137 ) ;
F_65 ( V_63 -> V_10 ) ;
}
}
if ( V_173 ) {
F_25 ( L_61 ,
V_7 -> V_49 -> V_47 ) ;
if ( V_179 ) {
V_7 -> V_49 = V_179 ;
F_86 ( V_7 ,
V_164 ) ;
F_86 ( V_7 ,
V_102 ) ;
}
V_58 = - V_51 ;
goto V_174;
}
}
F_25 ( L_62 ) ;
V_58 = F_86 ( V_7 , V_103 ) ;
}
V_174:
return V_58 ;
}
int F_134 ( unsigned int V_10 )
{
struct V_6 * V_7 = F_15 ( V_10 ) ;
struct V_6 V_63 ;
int V_58 ;
if ( ! V_7 ) {
V_58 = - V_158 ;
goto V_180;
}
if ( F_110 ( F_65 ( V_10 ) ) ) {
V_58 = - V_51 ;
goto V_149;
}
F_25 ( L_63 , V_10 ) ;
memcpy ( & V_63 , V_7 , sizeof( * V_7 ) ) ;
V_63 . V_126 = V_7 -> V_64 . V_126 ;
V_63 . V_127 = V_7 -> V_64 . V_127 ;
V_63 . V_7 = V_7 -> V_64 . V_7 ;
V_63 . V_49 = V_7 -> V_64 . V_49 ;
if ( V_4 -> V_95 ) {
V_63 . V_43 = V_4 -> V_95 ( V_10 ) ;
if ( ! V_7 -> V_43 ) {
F_25 ( L_64 ) ;
V_7 -> V_43 = V_63 . V_43 ;
} else {
if ( V_7 -> V_43 != V_63 . V_43 && V_4 -> V_56 )
F_135 ( V_10 , V_7 -> V_43 ,
V_63 . V_43 ) ;
}
}
V_58 = F_48 ( V_7 , & V_63 ) ;
F_66 ( V_10 ) ;
V_149:
F_22 ( V_7 ) ;
V_180:
return V_58 ;
}
static int F_159 ( struct V_150 * V_181 ,
unsigned long V_182 , void * V_183 )
{
unsigned int V_10 = ( unsigned long ) V_183 ;
struct V_89 * V_91 ;
bool V_98 = false ;
V_91 = F_79 ( V_10 ) ;
if ( V_91 ) {
if ( V_182 & V_184 )
V_98 = true ;
switch ( V_182 & ~ V_184 ) {
case V_185 :
F_106 ( V_91 , NULL , V_98 ) ;
F_134 ( V_10 ) ;
break;
case V_186 :
F_126 ( V_91 , NULL , V_98 ) ;
break;
case V_187 :
F_128 ( V_91 , NULL , V_98 ) ;
break;
case V_188 :
F_106 ( V_91 , NULL , V_98 ) ;
break;
}
}
return V_189 ;
}
int F_160 ( struct V_4 * V_190 )
{
unsigned long V_23 ;
int V_58 ;
if ( F_3 () )
return - V_158 ;
if ( ! V_190 || ! V_190 -> V_175 || ! V_190 -> V_123 ||
( ( ! V_190 -> V_53 ) && ( ! V_190 -> V_56 ) ) )
return - V_51 ;
F_25 ( L_65 , V_190 -> V_47 ) ;
if ( V_190 -> V_53 )
V_190 -> V_23 |= V_31 ;
F_88 ( & V_26 , V_23 ) ;
if ( V_4 ) {
F_90 ( & V_26 , V_23 ) ;
return - V_191 ;
}
V_4 = V_190 ;
F_90 ( & V_26 , V_23 ) ;
V_58 = F_161 ( & V_192 ) ;
if ( V_58 )
goto V_193;
if ( ! ( V_4 -> V_23 & V_194 ) ) {
int V_65 ;
V_58 = - V_158 ;
for ( V_65 = 0 ; V_65 < V_24 ; V_65 ++ )
if ( F_162 ( V_65 ) && F_18 ( V_27 , V_65 ) ) {
V_58 = 0 ;
break;
}
if ( V_58 ) {
F_25 ( L_66 ,
V_190 -> V_47 ) ;
goto V_195;
}
}
F_163 ( & V_196 ) ;
F_25 ( L_67 , V_190 -> V_47 ) ;
return 0 ;
V_195:
F_164 ( & V_192 ) ;
V_193:
F_88 ( & V_26 , V_23 ) ;
V_4 = NULL ;
F_90 ( & V_26 , V_23 ) ;
return V_58 ;
}
int F_165 ( struct V_4 * V_197 )
{
unsigned long V_23 ;
if ( ! V_4 || ( V_197 != V_4 ) )
return - V_51 ;
F_25 ( L_68 , V_197 -> V_47 ) ;
F_164 ( & V_192 ) ;
F_166 ( & V_196 ) ;
F_101 ( & V_25 ) ;
F_88 ( & V_26 , V_23 ) ;
V_4 = NULL ;
F_90 ( & V_26 , V_23 ) ;
F_102 ( & V_25 ) ;
return 0 ;
}
static int T_1 F_167 ( void )
{
int V_10 ;
if ( F_3 () )
return - V_158 ;
F_168 (cpu)
F_169 ( & F_18 ( V_109 , V_10 ) ) ;
V_9 = F_170 () ;
F_28 ( ! V_9 ) ;
F_171 ( & V_198 ) ;
return 0 ;
}
