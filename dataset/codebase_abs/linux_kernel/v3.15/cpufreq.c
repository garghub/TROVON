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
F_18 ( L_2 ,
V_31 , V_11 ? L_3 : L_4 , V_14 ) ;
return 0 ;
}
return F_23 ( V_11 -> V_35 ) / 1000 ;
}
struct V_10 * F_24 ( unsigned int V_14 )
{
return F_21 ( V_34 , V_14 ) ;
}
struct V_10 * F_25 ( unsigned int V_14 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_7 ;
if ( F_4 () || ( V_14 >= V_36 ) )
return NULL ;
if ( ! F_26 ( & V_37 ) )
return NULL ;
F_27 ( & V_38 , V_7 ) ;
if ( V_1 ) {
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_11 )
F_28 ( & V_11 -> V_12 ) ;
}
F_29 ( & V_38 , V_7 ) ;
if ( ! V_11 )
F_30 ( & V_37 ) ;
return V_11 ;
}
void F_31 ( struct V_10 * V_11 )
{
if ( F_4 () )
return;
F_32 ( & V_11 -> V_12 ) ;
F_30 ( & V_37 ) ;
}
static void F_33 ( unsigned long V_39 , struct V_40 * V_41 )
{
if ( V_41 -> V_7 & V_42 )
return;
if ( ! V_43 ) {
V_44 = V_45 ;
V_43 = V_41 -> V_46 ;
F_34 ( L_5 ,
V_44 , V_43 ) ;
}
if ( V_39 == V_47 && V_41 -> V_46 != V_41 -> V_48 ) {
V_45 = F_35 ( V_44 , V_43 ,
V_41 -> V_48 ) ;
F_34 ( L_6 ,
V_45 , V_41 -> V_48 ) ;
}
}
static inline void F_33 ( unsigned long V_39 , struct V_40 * V_41 )
{
return;
}
static void F_36 ( struct V_10 * V_11 ,
struct V_40 * V_49 , unsigned int V_50 )
{
F_37 ( F_38 () ) ;
if ( F_4 () )
return;
V_49 -> V_7 = V_1 -> V_7 ;
F_34 ( L_7 ,
V_50 , V_49 -> V_48 ) ;
switch ( V_50 ) {
case V_51 :
if ( ! ( V_1 -> V_7 & V_42 ) ) {
if ( ( V_11 ) && ( V_11 -> V_14 == V_49 -> V_14 ) &&
( V_11 -> V_52 ) && ( V_11 -> V_52 != V_49 -> V_46 ) ) {
F_34 ( L_8 ,
V_49 -> V_46 , V_11 -> V_52 ) ;
V_49 -> V_46 = V_11 -> V_52 ;
}
}
F_39 ( & V_4 ,
V_51 , V_49 ) ;
F_33 ( V_51 , V_49 ) ;
break;
case V_47 :
F_33 ( V_47 , V_49 ) ;
F_34 ( L_9 ,
( unsigned long ) V_49 -> V_48 , ( unsigned long ) V_49 -> V_14 ) ;
F_40 ( V_49 -> V_48 , V_49 -> V_14 ) ;
F_39 ( & V_4 ,
V_47 , V_49 ) ;
if ( F_41 ( V_11 ) && F_41 ( V_11 -> V_14 == V_49 -> V_14 ) )
V_11 -> V_52 = V_49 -> V_48 ;
break;
}
}
static void F_42 ( struct V_10 * V_11 ,
struct V_40 * V_49 , unsigned int V_50 )
{
F_43 (freqs->cpu, policy->cpus)
F_36 ( V_11 , V_49 , V_50 ) ;
}
static void F_44 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_53 )
{
F_42 ( V_11 , V_49 , V_47 ) ;
if ( ! V_53 )
return;
F_45 ( V_49 -> V_46 , V_49 -> V_48 ) ;
F_42 ( V_11 , V_49 , V_51 ) ;
F_42 ( V_11 , V_49 , V_47 ) ;
}
void F_46 ( struct V_10 * V_11 ,
struct V_40 * V_49 )
{
V_54:
F_47 ( V_11 -> V_55 , ! V_11 -> V_56 ) ;
F_48 ( & V_11 -> V_57 ) ;
if ( F_49 ( V_11 -> V_56 ) ) {
F_50 ( & V_11 -> V_57 ) ;
goto V_54;
}
V_11 -> V_56 = true ;
F_50 ( & V_11 -> V_57 ) ;
F_42 ( V_11 , V_49 , V_51 ) ;
}
void F_51 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_53 )
{
if ( F_49 ( F_52 ( ! V_11 -> V_56 ) ) )
return;
F_44 ( V_11 , V_49 , V_53 ) ;
V_11 -> V_56 = false ;
F_53 ( & V_11 -> V_55 ) ;
}
static T_3 F_54 ( struct V_9 * V_12 ,
struct V_58 * V_59 , char * V_60 )
{
return sprintf ( V_60 , L_10 , V_1 -> V_61 ) ;
}
static T_3 F_55 ( struct V_9 * V_12 , struct V_58 * V_59 ,
const char * V_60 , T_4 V_62 )
{
int V_30 , V_63 ;
V_30 = sscanf ( V_60 , L_11 , & V_63 ) ;
if ( V_30 != 1 || V_63 < 0 || V_63 > 1 )
return - V_64 ;
if ( F_56 ( V_63 ) ) {
F_18 ( L_12 ,
V_31 , V_63 ? L_13 : L_14 ) ;
return - V_64 ;
}
F_34 ( L_15 ,
V_31 , V_63 ? L_16 : L_17 ) ;
return V_62 ;
}
static struct V_65 * F_57 ( const char * V_66 )
{
struct V_65 * V_67 ;
F_58 (t, &cpufreq_governor_list, governor_list)
if ( ! F_59 ( V_66 , V_67 -> V_68 , V_69 ) )
return V_67 ;
return NULL ;
}
static int F_60 ( char * V_66 , unsigned int * V_11 ,
struct V_65 * * V_70 )
{
int V_71 = - V_64 ;
if ( ! V_1 )
goto V_72;
if ( V_1 -> V_73 ) {
if ( ! F_59 ( V_66 , L_18 , V_69 ) ) {
* V_11 = V_74 ;
V_71 = 0 ;
} else if ( ! F_59 ( V_66 , L_19 ,
V_69 ) ) {
* V_11 = V_75 ;
V_71 = 0 ;
}
} else if ( F_1 () ) {
struct V_65 * V_67 ;
F_61 ( & V_76 ) ;
V_67 = F_57 ( V_66 ) ;
if ( V_67 == NULL ) {
int V_30 ;
F_62 ( & V_76 ) ;
V_30 = F_63 ( L_20 , V_66 ) ;
F_61 ( & V_76 ) ;
if ( V_30 == 0 )
V_67 = F_57 ( V_66 ) ;
}
if ( V_67 != NULL ) {
* V_70 = V_67 ;
V_71 = 0 ;
}
F_62 ( & V_76 ) ;
}
V_72:
return V_71 ;
}
static T_3 F_64 ( struct V_10 * V_11 ,
char * V_60 )
{
unsigned int V_77 = F_65 ( V_11 -> V_14 ) ;
if ( ! V_77 )
return sprintf ( V_60 , L_21 ) ;
return sprintf ( V_60 , L_22 , V_77 ) ;
}
static T_3 F_66 ( struct V_10 * V_11 , char * V_60 )
{
if ( V_11 -> V_11 == V_75 )
return sprintf ( V_60 , L_23 ) ;
else if ( V_11 -> V_11 == V_74 )
return sprintf ( V_60 , L_24 ) ;
else if ( V_11 -> V_70 )
return F_67 ( V_60 , V_78 , L_25 ,
V_11 -> V_70 -> V_68 ) ;
return - V_64 ;
}
static T_3 F_68 ( struct V_10 * V_11 ,
const char * V_60 , T_4 V_62 )
{
int V_30 ;
char V_66 [ 16 ] ;
struct V_10 V_79 ;
V_30 = F_69 ( & V_79 , V_11 -> V_14 ) ;
if ( V_30 )
return V_30 ;
V_30 = sscanf ( V_60 , L_26 , V_66 ) ;
if ( V_30 != 1 )
return - V_64 ;
if ( F_60 ( V_66 , & V_79 . V_11 ,
& V_79 . V_70 ) )
return - V_64 ;
V_30 = F_70 ( V_11 , & V_79 ) ;
V_11 -> V_80 . V_11 = V_11 -> V_11 ;
V_11 -> V_80 . V_70 = V_11 -> V_70 ;
if ( V_30 )
return V_30 ;
else
return V_62 ;
}
static T_3 F_71 ( struct V_10 * V_11 , char * V_60 )
{
return F_67 ( V_60 , V_78 , L_25 , V_1 -> V_68 ) ;
}
static T_3 F_72 ( struct V_10 * V_11 ,
char * V_60 )
{
T_3 V_81 = 0 ;
struct V_65 * V_67 ;
if ( ! F_1 () ) {
V_81 += sprintf ( V_60 , L_27 ) ;
goto V_72;
}
F_58 (t, &cpufreq_governor_list, governor_list) {
if ( V_81 >= ( T_3 ) ( ( V_82 / sizeof( char ) )
- ( V_69 + 2 ) ) )
goto V_72;
V_81 += F_67 ( & V_60 [ V_81 ] , V_78 , L_28 , V_67 -> V_68 ) ;
}
V_72:
V_81 += sprintf ( & V_60 [ V_81 ] , L_29 ) ;
return V_81 ;
}
T_3 F_73 ( const struct V_83 * V_84 , char * V_60 )
{
T_3 V_81 = 0 ;
unsigned int V_14 ;
F_43 (cpu, mask) {
if ( V_81 )
V_81 += F_67 ( & V_60 [ V_81 ] , ( V_82 - V_81 - 2 ) , L_30 ) ;
V_81 += F_67 ( & V_60 [ V_81 ] , ( V_82 - V_81 - 2 ) , L_31 , V_14 ) ;
if ( V_81 >= ( V_82 - 5 ) )
break;
}
V_81 += sprintf ( & V_60 [ V_81 ] , L_29 ) ;
return V_81 ;
}
static T_3 F_74 ( struct V_10 * V_11 , char * V_60 )
{
return F_73 ( V_11 -> V_85 , V_60 ) ;
}
static T_3 F_75 ( struct V_10 * V_11 , char * V_60 )
{
return F_73 ( V_11 -> V_33 , V_60 ) ;
}
static T_3 F_76 ( struct V_10 * V_11 ,
const char * V_60 , T_4 V_62 )
{
unsigned int V_86 = 0 ;
unsigned int V_30 ;
if ( ! V_11 -> V_70 || ! V_11 -> V_70 -> V_87 )
return - V_64 ;
V_30 = sscanf ( V_60 , L_31 , & V_86 ) ;
if ( V_30 != 1 )
return - V_64 ;
V_11 -> V_70 -> V_87 ( V_11 , V_86 ) ;
return V_62 ;
}
static T_3 F_77 ( struct V_10 * V_11 , char * V_60 )
{
if ( ! V_11 -> V_70 || ! V_11 -> V_70 -> V_88 )
return sprintf ( V_60 , L_32 ) ;
return V_11 -> V_70 -> V_88 ( V_11 , V_60 ) ;
}
static T_3 F_78 ( struct V_10 * V_11 , char * V_60 )
{
unsigned int V_89 ;
int V_30 ;
if ( V_1 -> V_90 ) {
V_30 = V_1 -> V_90 ( V_11 -> V_14 , & V_89 ) ;
if ( ! V_30 )
return sprintf ( V_60 , L_22 , V_89 ) ;
}
return sprintf ( V_60 , L_22 , V_11 -> V_32 . V_91 ) ;
}
static T_3 F_79 ( struct V_9 * V_12 , struct V_58 * V_59 , char * V_60 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
struct V_92 * V_93 = F_81 ( V_59 ) ;
T_3 V_30 ;
if ( ! F_26 ( & V_37 ) )
return - V_64 ;
F_82 ( & V_11 -> V_94 ) ;
if ( V_93 -> F_79 )
V_30 = V_93 -> F_79 ( V_11 , V_60 ) ;
else
V_30 = - V_95 ;
F_30 ( & V_11 -> V_94 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
static T_3 F_83 ( struct V_9 * V_12 , struct V_58 * V_59 ,
const char * V_60 , T_4 V_62 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
struct V_92 * V_93 = F_81 ( V_59 ) ;
T_3 V_30 = - V_64 ;
F_84 () ;
if ( ! F_85 ( V_11 -> V_14 ) )
goto V_96;
if ( ! F_26 ( & V_37 ) )
goto V_96;
F_86 ( & V_11 -> V_94 ) ;
if ( V_93 -> F_83 )
V_30 = V_93 -> F_83 ( V_11 , V_60 , V_62 ) ;
else
V_30 = - V_95 ;
F_87 ( & V_11 -> V_94 ) ;
F_30 ( & V_37 ) ;
V_96:
F_88 () ;
return V_30 ;
}
static void F_89 ( struct V_9 * V_12 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
F_34 ( L_33 ) ;
F_90 ( & V_11 -> V_97 ) ;
}
int F_91 ( void )
{
if ( ! V_98 ++ )
return F_92 ( V_13 ,
& V_99 . V_100 -> V_12 , L_34 , L_35 ) ;
return 0 ;
}
void F_93 ( void )
{
if ( ! -- V_98 )
F_94 ( V_13 ) ;
}
int F_95 ( const struct V_58 * V_59 )
{
int V_30 = F_91 () ;
if ( ! V_30 ) {
V_30 = F_96 ( V_13 , V_59 ) ;
if ( V_30 )
F_93 () ;
}
return V_30 ;
}
void F_97 ( const struct V_58 * V_59 )
{
F_98 ( V_13 , V_59 ) ;
F_93 () ;
}
static int F_99 ( struct V_10 * V_11 )
{
unsigned int V_101 ;
int V_30 = 0 ;
F_43 (j, policy->cpus) {
struct V_102 * V_103 ;
if ( V_101 == V_11 -> V_14 )
continue;
F_34 ( L_36 , V_101 ) ;
V_103 = F_100 ( V_101 ) ;
V_30 = F_101 ( & V_103 -> V_12 , & V_11 -> V_12 ,
L_35 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
static int F_102 ( struct V_10 * V_11 ,
struct V_102 * V_104 )
{
struct V_92 * * V_105 ;
int V_30 = 0 ;
V_30 = F_103 ( & V_11 -> V_12 , & V_106 ,
& V_104 -> V_12 , L_35 ) ;
if ( V_30 )
return V_30 ;
V_105 = V_1 -> V_59 ;
while ( ( V_105 ) && ( * V_105 ) ) {
V_30 = F_96 ( & V_11 -> V_12 , & ( ( * V_105 ) -> V_59 ) ) ;
if ( V_30 )
goto V_107;
V_105 ++ ;
}
if ( V_1 -> V_108 ) {
V_30 = F_96 ( & V_11 -> V_12 , & V_109 . V_59 ) ;
if ( V_30 )
goto V_107;
}
if ( F_1 () ) {
V_30 = F_96 ( & V_11 -> V_12 , & V_110 . V_59 ) ;
if ( V_30 )
goto V_107;
}
if ( V_1 -> V_90 ) {
V_30 = F_96 ( & V_11 -> V_12 , & V_90 . V_59 ) ;
if ( V_30 )
goto V_107;
}
V_30 = F_99 ( V_11 ) ;
if ( V_30 )
goto V_107;
return V_30 ;
V_107:
F_32 ( & V_11 -> V_12 ) ;
F_104 ( & V_11 -> V_97 ) ;
return V_30 ;
}
static void F_105 ( struct V_10 * V_11 )
{
struct V_65 * V_111 = NULL ;
struct V_10 V_79 ;
int V_30 = 0 ;
memcpy ( & V_79 , V_11 , sizeof( * V_11 ) ) ;
V_111 = F_57 ( F_21 ( V_112 , V_11 -> V_14 ) ) ;
if ( V_111 )
F_34 ( L_37 ,
V_11 -> V_70 -> V_68 , V_11 -> V_14 ) ;
else
V_111 = V_113 ;
V_79 . V_70 = V_111 ;
if ( V_1 -> V_73 )
F_60 ( V_111 -> V_68 , & V_79 . V_11 , NULL ) ;
V_30 = F_70 ( V_11 , & V_79 ) ;
if ( V_30 ) {
F_34 ( L_38 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
}
}
static int F_106 ( struct V_10 * V_11 ,
unsigned int V_14 , struct V_102 * V_104 )
{
int V_30 = 0 ;
unsigned long V_7 ;
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_114 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
}
F_86 ( & V_11 -> V_94 ) ;
F_108 ( & V_38 , V_7 ) ;
F_109 ( V_14 , V_11 -> V_33 ) ;
F_21 ( V_34 , V_14 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
F_87 ( & V_11 -> V_94 ) ;
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_115 ) ;
if ( ! V_30 )
V_30 = F_107 ( V_11 , V_116 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
return F_101 ( & V_104 -> V_12 , & V_11 -> V_12 , L_35 ) ;
}
static struct V_10 * F_111 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_7 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_117 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
V_11 -> V_70 = NULL ;
return V_11 ;
}
static struct V_10 * F_112 ( void )
{
struct V_10 * V_11 ;
V_11 = F_113 ( sizeof( * V_11 ) , V_118 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_114 ( & V_11 -> V_33 , V_118 ) )
goto V_119;
if ( ! F_115 ( & V_11 -> V_85 , V_118 ) )
goto V_120;
F_116 ( & V_11 -> V_121 ) ;
F_117 ( & V_11 -> V_94 ) ;
F_118 ( & V_11 -> V_57 ) ;
F_119 ( & V_11 -> V_55 ) ;
return V_11 ;
V_120:
F_120 ( V_11 -> V_33 ) ;
V_119:
F_121 ( V_11 ) ;
return NULL ;
}
static void F_122 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
struct V_122 * V_123 ;
F_123 ( & V_124 ,
V_125 , V_11 ) ;
F_82 ( & V_11 -> V_94 ) ;
V_12 = & V_11 -> V_12 ;
V_123 = & V_11 -> V_97 ;
F_30 ( & V_11 -> V_94 ) ;
F_32 ( V_12 ) ;
F_34 ( L_41 ) ;
F_104 ( V_123 ) ;
F_34 ( L_42 ) ;
}
static void F_124 ( struct V_10 * V_11 )
{
F_120 ( V_11 -> V_85 ) ;
F_120 ( V_11 -> V_33 ) ;
F_121 ( V_11 ) ;
}
static void F_125 ( struct V_10 * V_11 , unsigned int V_14 )
{
if ( F_52 ( V_14 == V_11 -> V_14 ) )
return;
F_86 ( & V_11 -> V_94 ) ;
V_11 -> V_126 = V_11 -> V_14 ;
V_11 -> V_14 = V_14 ;
F_87 ( & V_11 -> V_94 ) ;
F_123 ( & V_124 ,
V_127 , V_11 ) ;
}
static int F_126 ( struct V_102 * V_104 , struct V_128 * V_129 )
{
unsigned int V_101 , V_14 = V_104 -> V_130 ;
int V_30 = - V_131 ;
struct V_10 * V_11 ;
unsigned long V_7 ;
bool V_132 = V_133 ;
#ifdef F_127
struct V_10 * V_134 ;
#endif
if ( F_128 ( V_14 ) )
return 0 ;
F_34 ( L_43 , V_14 ) ;
#ifdef F_129
V_11 = F_25 ( V_14 ) ;
if ( F_49 ( V_11 ) ) {
F_31 ( V_11 ) ;
return 0 ;
}
#endif
if ( ! F_26 ( & V_37 ) )
return 0 ;
#ifdef F_127
F_27 ( & V_38 , V_7 ) ;
F_58 (tpolicy, &cpufreq_policy_list, policy_list) {
if ( F_130 ( V_14 , V_134 -> V_85 ) ) {
F_29 ( & V_38 , V_7 ) ;
V_30 = F_106 ( V_134 , V_14 , V_104 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
}
F_29 ( & V_38 , V_7 ) ;
#endif
V_11 = V_132 ? F_111 ( V_14 ) : NULL ;
if ( ! V_11 ) {
V_132 = false ;
V_11 = F_112 () ;
if ( ! V_11 )
goto V_135;
}
if ( V_132 && V_14 != V_11 -> V_14 )
F_125 ( V_11 , V_14 ) ;
else
V_11 -> V_14 = V_14 ;
F_131 ( V_11 -> V_33 , F_132 ( V_14 ) ) ;
F_133 ( & V_11 -> V_97 ) ;
F_134 ( & V_11 -> V_136 , V_137 ) ;
V_30 = V_1 -> V_138 ( V_11 ) ;
if ( V_30 ) {
F_34 ( L_44 ) ;
goto V_139;
}
F_135 ( V_11 -> V_85 , V_11 -> V_85 , V_11 -> V_33 ) ;
F_136 ( V_11 -> V_33 , V_11 -> V_33 , V_140 ) ;
if ( ! V_132 ) {
V_11 -> V_80 . V_141 = V_11 -> V_141 ;
V_11 -> V_80 . V_142 = V_11 -> V_142 ;
}
F_86 ( & V_11 -> V_94 ) ;
F_108 ( & V_38 , V_7 ) ;
F_43 (j, policy->cpus)
F_21 ( V_34 , V_101 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
if ( V_1 -> V_108 && ! V_1 -> V_73 ) {
V_11 -> V_52 = V_1 -> V_108 ( V_11 -> V_14 ) ;
if ( ! V_11 -> V_52 ) {
F_18 ( L_45 , V_31 ) ;
goto V_143;
}
}
if ( ( V_1 -> V_7 & V_144 )
&& F_1 () ) {
V_30 = F_137 ( V_11 , V_11 -> V_52 ) ;
if ( V_30 == - V_64 ) {
F_138 ( L_46 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
V_30 = F_139 ( V_11 , V_11 -> V_52 - 1 ,
V_145 ) ;
F_37 ( V_30 ) ;
F_138 ( L_47 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
}
}
F_123 ( & V_124 ,
V_146 , V_11 ) ;
if ( ! V_132 ) {
V_30 = F_102 ( V_11 , V_104 ) ;
if ( V_30 )
goto V_147;
F_123 ( & V_124 ,
V_148 , V_11 ) ;
}
F_108 ( & V_38 , V_7 ) ;
F_140 ( & V_11 -> V_121 , & V_149 ) ;
F_110 ( & V_38 , V_7 ) ;
F_105 ( V_11 ) ;
if ( ! V_132 ) {
V_11 -> V_80 . V_11 = V_11 -> V_11 ;
V_11 -> V_80 . V_70 = V_11 -> V_70 ;
}
F_87 ( & V_11 -> V_94 ) ;
F_141 ( & V_11 -> V_12 , V_150 ) ;
F_30 ( & V_37 ) ;
F_34 ( L_48 ) ;
return 0 ;
V_147:
V_143:
F_108 ( & V_38 , V_7 ) ;
F_43 (j, policy->cpus)
F_21 ( V_34 , V_101 ) = NULL ;
F_110 ( & V_38 , V_7 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
V_139:
if ( V_132 ) {
F_21 ( V_117 , V_14 ) = NULL ;
F_122 ( V_11 ) ;
}
F_124 ( V_11 ) ;
V_135:
F_30 ( & V_37 ) ;
return V_30 ;
}
static int F_142 ( struct V_102 * V_104 , struct V_128 * V_129 )
{
return F_126 ( V_104 , V_129 ) ;
}
static int F_143 ( struct V_10 * V_11 ,
unsigned int V_151 )
{
struct V_102 * V_103 ;
int V_30 ;
V_103 = F_100 ( F_144 ( V_11 -> V_33 , V_151 ) ) ;
F_145 ( & V_103 -> V_12 , L_35 ) ;
V_30 = F_146 ( & V_11 -> V_12 , & V_103 -> V_12 ) ;
if ( V_30 ) {
F_18 ( L_49 , V_31 , V_30 ) ;
F_86 ( & V_11 -> V_94 ) ;
F_109 ( V_151 , V_11 -> V_33 ) ;
F_87 ( & V_11 -> V_94 ) ;
V_30 = F_101 ( & V_103 -> V_12 , & V_11 -> V_12 ,
L_35 ) ;
return - V_64 ;
}
return V_103 -> V_130 ;
}
static int F_147 ( struct V_102 * V_104 ,
struct V_128 * V_129 )
{
unsigned int V_14 = V_104 -> V_130 , V_33 ;
int V_152 , V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_34 ( L_50 , V_31 , V_14 ) ;
F_108 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_133 )
F_21 ( V_117 , V_14 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_34 ( L_51 , V_31 ) ;
return - V_64 ;
}
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_114 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
}
if ( ! V_1 -> V_73 )
strncpy ( F_21 ( V_112 , V_14 ) ,
V_11 -> V_70 -> V_68 , V_69 ) ;
F_82 ( & V_11 -> V_94 ) ;
V_33 = F_148 ( V_11 -> V_33 ) ;
F_30 ( & V_11 -> V_94 ) ;
if ( V_14 != V_11 -> V_14 ) {
F_145 ( & V_104 -> V_12 , L_35 ) ;
} else if ( V_33 > 1 ) {
V_152 = F_143 ( V_11 , V_14 ) ;
if ( V_152 >= 0 ) {
F_125 ( V_11 , V_152 ) ;
if ( ! V_133 )
F_34 ( L_52 ,
V_31 , V_152 , V_14 ) ;
}
} else if ( V_1 -> V_153 && V_1 -> V_73 ) {
V_1 -> V_153 ( V_11 ) ;
}
return 0 ;
}
static int F_149 ( struct V_102 * V_104 ,
struct V_128 * V_129 )
{
unsigned int V_14 = V_104 -> V_130 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_34 ( L_51 , V_31 ) ;
return - V_64 ;
}
F_86 ( & V_11 -> V_94 ) ;
V_33 = F_148 ( V_11 -> V_33 ) ;
if ( V_33 > 1 )
F_150 ( V_14 , V_11 -> V_33 ) ;
F_87 ( & V_11 -> V_94 ) ;
if ( V_33 == 1 ) {
if ( F_1 () ) {
V_30 = F_107 ( V_11 ,
V_154 ) ;
if ( V_30 ) {
F_18 ( L_53 ,
V_31 ) ;
return V_30 ;
}
}
if ( ! V_133 )
F_122 ( V_11 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
F_108 ( & V_38 , V_7 ) ;
F_151 ( & V_11 -> V_121 ) ;
F_110 ( & V_38 , V_7 ) ;
if ( ! V_133 )
F_124 ( V_11 ) ;
} else if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_115 ) ;
if ( ! V_30 )
V_30 = F_107 ( V_11 , V_116 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
F_21 ( V_34 , V_14 ) = NULL ;
return 0 ;
}
static int F_152 ( struct V_102 * V_104 , struct V_128 * V_129 )
{
unsigned int V_14 = V_104 -> V_130 ;
int V_30 ;
if ( F_128 ( V_14 ) )
return 0 ;
V_30 = F_147 ( V_104 , V_129 ) ;
if ( ! V_30 )
V_30 = F_149 ( V_104 , V_129 ) ;
return V_30 ;
}
static void V_137 ( struct V_155 * V_156 )
{
struct V_10 * V_11 =
F_153 ( V_156 , struct V_10 , V_136 ) ;
unsigned int V_14 = V_11 -> V_14 ;
F_34 ( L_54 , V_14 ) ;
F_154 ( V_14 ) ;
}
static void F_155 ( unsigned int V_14 , unsigned int V_157 ,
unsigned int V_158 )
{
struct V_10 * V_11 ;
struct V_40 V_49 ;
unsigned long V_7 ;
F_34 ( L_55 ,
V_157 , V_158 ) ;
V_49 . V_46 = V_157 ;
V_49 . V_48 = V_158 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
F_46 ( V_11 , & V_49 ) ;
F_51 ( V_11 , & V_49 , 0 ) ;
}
unsigned int F_156 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned int V_159 = 0 ;
if ( V_1 && V_1 -> V_73 && V_1 -> V_108 )
return V_1 -> V_108 ( V_14 ) ;
V_11 = F_25 ( V_14 ) ;
if ( V_11 ) {
V_159 = V_11 -> V_52 ;
F_31 ( V_11 ) ;
}
return V_159 ;
}
unsigned int F_157 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_159 = 0 ;
if ( V_11 ) {
V_159 = V_11 -> V_142 ;
F_31 ( V_11 ) ;
}
return V_159 ;
}
static unsigned int F_65 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_21 ( V_34 , V_14 ) ;
unsigned int V_159 = 0 ;
if ( ! V_1 -> V_108 )
return V_159 ;
V_159 = V_1 -> V_108 ( V_14 ) ;
if ( V_159 && V_11 -> V_52 &&
! ( V_1 -> V_7 & V_42 ) ) {
if ( F_49 ( V_159 != V_11 -> V_52 ) ) {
F_155 ( V_14 , V_11 -> V_52 , V_159 ) ;
F_158 ( & V_11 -> V_136 ) ;
}
}
return V_159 ;
}
unsigned int F_159 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_159 = 0 ;
if ( V_11 ) {
F_82 ( & V_11 -> V_94 ) ;
V_159 = F_65 ( V_14 ) ;
F_30 ( & V_11 -> V_94 ) ;
F_31 ( V_11 ) ;
}
return V_159 ;
}
int F_160 ( struct V_10 * V_11 )
{
int V_30 ;
if ( ! V_11 -> V_160 ) {
F_18 ( L_56 , V_31 ) ;
return - V_64 ;
}
F_34 ( L_57 , V_31 ,
V_11 -> V_160 ) ;
V_30 = F_139 ( V_11 , V_11 -> V_160 ,
V_161 ) ;
if ( V_30 )
F_18 ( L_58 ,
V_31 , V_11 -> V_160 , V_30 ) ;
return V_30 ;
}
void F_161 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
if ( ! F_1 () )
return;
F_34 ( L_59 , V_31 ) ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
if ( F_107 ( V_11 , V_114 ) )
F_18 ( L_60 ,
V_31 , V_11 ) ;
else if ( V_1 -> V_162
&& V_1 -> V_162 ( V_11 ) )
F_18 ( L_61 , V_31 ,
V_11 ) ;
}
V_133 = true ;
}
void F_162 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
if ( ! F_1 () )
return;
F_34 ( L_62 , V_31 ) ;
V_133 = false ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
if ( V_1 -> V_163 && V_1 -> V_163 ( V_11 ) )
F_18 ( L_63 , V_31 ,
V_11 ) ;
else if ( F_107 ( V_11 , V_115 )
|| F_107 ( V_11 , V_116 ) )
F_18 ( L_64 ,
V_31 , V_11 ) ;
if ( F_163 ( & V_11 -> V_121 , & V_149 ) )
F_158 ( & V_11 -> V_136 ) ;
}
}
const char * F_164 ( void )
{
if ( V_1 )
return V_1 -> V_68 ;
return NULL ;
}
int F_165 ( struct V_164 * V_165 , unsigned int V_166 )
{
int V_30 ;
if ( F_4 () )
return - V_64 ;
F_52 ( ! V_5 ) ;
switch ( V_166 ) {
case V_167 :
V_30 = F_166 (
& V_4 , V_165 ) ;
break;
case V_168 :
V_30 = F_167 (
& V_124 , V_165 ) ;
break;
default:
V_30 = - V_64 ;
}
return V_30 ;
}
int F_168 ( struct V_164 * V_165 , unsigned int V_166 )
{
int V_30 ;
if ( F_4 () )
return - V_64 ;
switch ( V_166 ) {
case V_167 :
V_30 = F_169 (
& V_4 , V_165 ) ;
break;
case V_168 :
V_30 = F_170 (
& V_124 , V_165 ) ;
break;
default:
V_30 = - V_64 ;
}
return V_30 ;
}
int F_139 ( struct V_10 * V_11 ,
unsigned int V_169 ,
unsigned int V_170 )
{
int V_171 = - V_64 ;
unsigned int V_172 = V_169 ;
if ( F_4 () )
return - V_173 ;
if ( V_169 > V_11 -> V_142 )
V_169 = V_11 -> V_142 ;
if ( V_169 < V_11 -> V_141 )
V_169 = V_11 -> V_141 ;
F_34 ( L_65 ,
V_11 -> V_14 , V_169 , V_170 , V_172 ) ;
if ( V_169 == V_11 -> V_52 )
return 0 ;
if ( V_1 -> V_3 )
V_171 = V_1 -> V_3 ( V_11 , V_169 , V_170 ) ;
else if ( V_1 -> V_2 ) {
struct V_27 * V_174 ;
struct V_40 V_49 ;
bool V_175 ;
int V_176 ;
V_174 = F_171 ( V_11 -> V_14 ) ;
if ( F_49 ( ! V_174 ) ) {
F_18 ( L_66 , V_31 ) ;
goto V_72;
}
V_171 = F_172 ( V_11 , V_174 ,
V_169 , V_170 , & V_176 ) ;
if ( F_49 ( V_171 ) ) {
F_18 ( L_67 , V_31 ) ;
goto V_72;
}
if ( V_174 [ V_176 ] . V_177 == V_11 -> V_52 ) {
V_171 = 0 ;
goto V_72;
}
V_175 = ! ( V_1 -> V_7 & V_178 ) ;
if ( V_175 ) {
V_49 . V_46 = V_11 -> V_52 ;
V_49 . V_48 = V_174 [ V_176 ] . V_177 ;
V_49 . V_7 = 0 ;
F_34 ( L_68 ,
V_31 , V_11 -> V_14 , V_49 . V_46 , V_49 . V_48 ) ;
F_46 ( V_11 , & V_49 ) ;
}
V_171 = V_1 -> V_2 ( V_11 , V_176 ) ;
if ( V_171 )
F_18 ( L_69 ,
V_31 , V_171 ) ;
if ( V_175 )
F_51 ( V_11 , & V_49 , V_171 ) ;
}
V_72:
return V_171 ;
}
int F_173 ( struct V_10 * V_11 ,
unsigned int V_169 ,
unsigned int V_170 )
{
int V_30 = - V_64 ;
F_86 ( & V_11 -> V_94 ) ;
V_30 = F_139 ( V_11 , V_169 , V_170 ) ;
F_87 ( & V_11 -> V_94 ) ;
return V_30 ;
}
static int F_107 ( struct V_10 * V_11 ,
unsigned int V_179 )
{
int V_30 ;
#ifdef F_174
struct V_65 * V_111 = & V_180 ;
#else
struct V_65 * V_111 = NULL ;
#endif
if ( V_133 )
return 0 ;
if ( V_11 -> V_70 -> V_181 &&
V_11 -> V_32 . V_29 >
V_11 -> V_70 -> V_181 ) {
if ( ! V_111 )
return - V_64 ;
else {
F_138 ( L_70 ,
V_11 -> V_70 -> V_68 , V_111 -> V_68 ) ;
V_11 -> V_70 = V_111 ;
}
}
if ( V_179 == V_182 )
if ( ! F_175 ( V_11 -> V_70 -> V_183 ) )
return - V_64 ;
F_34 ( L_71 ,
V_11 -> V_14 , V_179 ) ;
F_61 ( & V_184 ) ;
if ( ( V_11 -> V_185 && V_179 == V_115 )
|| ( ! V_11 -> V_185
&& ( V_179 == V_116 || V_179 == V_114 ) ) ) {
F_62 ( & V_184 ) ;
return - V_186 ;
}
if ( V_179 == V_114 )
V_11 -> V_185 = false ;
else if ( V_179 == V_115 )
V_11 -> V_185 = true ;
F_62 ( & V_184 ) ;
V_30 = V_11 -> V_70 -> V_70 ( V_11 , V_179 ) ;
if ( ! V_30 ) {
if ( V_179 == V_182 )
V_11 -> V_70 -> V_187 ++ ;
else if ( V_179 == V_154 )
V_11 -> V_70 -> V_187 -- ;
} else {
F_61 ( & V_184 ) ;
if ( V_179 == V_114 )
V_11 -> V_185 = true ;
else if ( V_179 == V_115 )
V_11 -> V_185 = false ;
F_62 ( & V_184 ) ;
}
if ( ( ( V_179 == V_182 ) && V_30 ) ||
( ( V_179 == V_154 ) && ! V_30 ) )
F_176 ( V_11 -> V_70 -> V_183 ) ;
return V_30 ;
}
int F_177 ( struct V_65 * V_70 )
{
int V_71 ;
if ( ! V_70 )
return - V_64 ;
if ( F_4 () )
return - V_173 ;
F_61 ( & V_76 ) ;
V_70 -> V_187 = 0 ;
V_71 = - V_186 ;
if ( F_57 ( V_70 -> V_68 ) == NULL ) {
V_71 = 0 ;
F_140 ( & V_70 -> V_188 , & V_189 ) ;
}
F_62 ( & V_76 ) ;
return V_71 ;
}
void F_178 ( struct V_65 * V_70 )
{
int V_14 ;
if ( ! V_70 )
return;
if ( F_4 () )
return;
F_179 (cpu) {
if ( F_85 ( V_14 ) )
continue;
if ( ! strcmp ( F_21 ( V_112 , V_14 ) , V_70 -> V_68 ) )
strcpy ( F_21 ( V_112 , V_14 ) , L_72 ) ;
}
F_61 ( & V_76 ) ;
F_151 ( & V_70 -> V_188 ) ;
F_62 ( & V_76 ) ;
return;
}
int F_69 ( struct V_10 * V_11 , unsigned int V_14 )
{
struct V_10 * V_190 ;
if ( ! V_11 )
return - V_64 ;
V_190 = F_25 ( V_14 ) ;
if ( ! V_190 )
return - V_64 ;
memcpy ( V_11 , V_190 , sizeof( * V_11 ) ) ;
F_31 ( V_190 ) ;
return 0 ;
}
static int F_70 ( struct V_10 * V_11 ,
struct V_10 * V_79 )
{
struct V_65 * V_191 ;
int V_30 ;
F_34 ( L_73 ,
V_79 -> V_14 , V_79 -> V_141 , V_79 -> V_142 ) ;
memcpy ( & V_79 -> V_32 , & V_11 -> V_32 , sizeof( V_11 -> V_32 ) ) ;
if ( V_79 -> V_141 > V_11 -> V_142 || V_79 -> V_142 < V_11 -> V_141 )
return - V_64 ;
V_30 = V_1 -> V_192 ( V_79 ) ;
if ( V_30 )
return V_30 ;
F_123 ( & V_124 ,
V_193 , V_79 ) ;
F_123 ( & V_124 ,
V_194 , V_79 ) ;
V_30 = V_1 -> V_192 ( V_79 ) ;
if ( V_30 )
return V_30 ;
F_123 ( & V_124 ,
V_195 , V_79 ) ;
V_11 -> V_141 = V_79 -> V_141 ;
V_11 -> V_142 = V_79 -> V_142 ;
F_34 ( L_74 ,
V_11 -> V_141 , V_11 -> V_142 ) ;
if ( V_1 -> V_73 ) {
V_11 -> V_11 = V_79 -> V_11 ;
F_34 ( L_75 ) ;
return V_1 -> V_73 ( V_79 ) ;
}
if ( V_79 -> V_70 == V_11 -> V_70 )
goto V_72;
F_34 ( L_76 ) ;
V_191 = V_11 -> V_70 ;
if ( V_191 ) {
F_107 ( V_11 , V_114 ) ;
F_87 ( & V_11 -> V_94 ) ;
F_107 ( V_11 , V_154 ) ;
F_86 ( & V_11 -> V_94 ) ;
}
V_11 -> V_70 = V_79 -> V_70 ;
if ( ! F_107 ( V_11 , V_182 ) ) {
if ( ! F_107 ( V_11 , V_115 ) )
goto V_72;
F_87 ( & V_11 -> V_94 ) ;
F_107 ( V_11 , V_154 ) ;
F_86 ( & V_11 -> V_94 ) ;
}
F_34 ( L_77 , V_11 -> V_70 -> V_68 ) ;
if ( V_191 ) {
V_11 -> V_70 = V_191 ;
F_107 ( V_11 , V_182 ) ;
F_107 ( V_11 , V_115 ) ;
}
return - V_64 ;
V_72:
F_34 ( L_78 ) ;
return F_107 ( V_11 , V_116 ) ;
}
int F_154 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
struct V_10 V_79 ;
int V_30 ;
if ( ! V_11 ) {
V_30 = - V_173 ;
goto V_196;
}
F_86 ( & V_11 -> V_94 ) ;
F_34 ( L_79 , V_14 ) ;
memcpy ( & V_79 , V_11 , sizeof( * V_11 ) ) ;
V_79 . V_141 = V_11 -> V_80 . V_141 ;
V_79 . V_142 = V_11 -> V_80 . V_142 ;
V_79 . V_11 = V_11 -> V_80 . V_11 ;
V_79 . V_70 = V_11 -> V_80 . V_70 ;
if ( V_1 -> V_108 && ! V_1 -> V_73 ) {
V_79 . V_52 = V_1 -> V_108 ( V_14 ) ;
if ( F_52 ( ! V_79 . V_52 ) ) {
V_30 = - V_95 ;
goto V_196;
}
if ( ! V_11 -> V_52 ) {
F_34 ( L_80 ) ;
V_11 -> V_52 = V_79 . V_52 ;
} else {
if ( V_11 -> V_52 != V_79 . V_52 && F_1 () )
F_155 ( V_14 , V_11 -> V_52 ,
V_79 . V_52 ) ;
}
}
V_30 = F_70 ( V_11 , & V_79 ) ;
F_87 ( & V_11 -> V_94 ) ;
F_31 ( V_11 ) ;
V_196:
return V_30 ;
}
static int F_180 ( struct V_164 * V_197 ,
unsigned long V_198 , void * V_199 )
{
unsigned int V_14 = ( unsigned long ) V_199 ;
struct V_102 * V_104 ;
V_104 = F_100 ( V_14 ) ;
if ( V_104 ) {
switch ( V_198 & ~ V_200 ) {
case V_201 :
F_126 ( V_104 , NULL ) ;
break;
case V_202 :
F_147 ( V_104 , NULL ) ;
break;
case V_203 :
F_149 ( V_104 , NULL ) ;
break;
case V_204 :
F_126 ( V_104 , NULL ) ;
break;
}
}
return V_205 ;
}
static int F_181 ( int V_50 )
{
struct V_27 * V_174 ;
struct V_10 * V_11 ;
int V_30 = - V_64 ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
V_174 = F_171 ( V_11 -> V_14 ) ;
if ( V_174 ) {
V_30 = F_182 ( V_11 ,
V_174 ) ;
if ( V_30 ) {
F_18 ( L_81 ,
V_31 ) ;
break;
}
V_11 -> V_80 . V_142 = V_11 -> V_142 ;
F_107 ( V_11 , V_116 ) ;
}
}
return V_30 ;
}
int F_56 ( int V_50 )
{
unsigned long V_7 ;
int V_30 = 0 ;
if ( V_1 -> V_61 == V_50 )
return 0 ;
F_108 ( & V_38 , V_7 ) ;
V_1 -> V_61 = V_50 ;
F_110 ( & V_38 , V_7 ) ;
V_30 = V_1 -> V_206 ( V_50 ) ;
if ( V_30 ) {
F_108 ( & V_38 , V_7 ) ;
V_1 -> V_61 = ! V_50 ;
F_110 ( & V_38 , V_7 ) ;
F_18 ( L_82 ,
V_31 , V_50 ? L_13 : L_14 ) ;
}
return V_30 ;
}
int F_183 ( void )
{
if ( F_41 ( V_1 ) )
return V_1 -> V_207 ;
return 0 ;
}
int F_184 ( void )
{
return V_1 -> V_61 ;
}
int F_185 ( struct V_1 * V_208 )
{
unsigned long V_7 ;
int V_30 ;
if ( F_4 () )
return - V_173 ;
if ( ! V_208 || ! V_208 -> V_192 || ! V_208 -> V_138 ||
! ( V_208 -> V_73 || V_208 -> V_2 ||
V_208 -> V_3 ) ||
( V_208 -> V_73 && ( V_208 -> V_2 ||
V_208 -> V_3 ) ) )
return - V_64 ;
F_34 ( L_83 , V_208 -> V_68 ) ;
if ( V_208 -> V_73 )
V_208 -> V_7 |= V_42 ;
F_108 ( & V_38 , V_7 ) ;
if ( V_1 ) {
F_110 ( & V_38 , V_7 ) ;
return - V_209 ;
}
V_1 = V_208 ;
F_110 ( & V_38 , V_7 ) ;
if ( F_183 () ) {
if ( ! V_1 -> V_206 )
V_1 -> V_206 = F_181 ;
V_30 = F_95 ( & V_210 . V_59 ) ;
if ( V_30 ) {
F_18 ( L_84 ,
V_31 ) ;
goto V_211;
}
}
V_30 = F_186 ( & V_212 ) ;
if ( V_30 )
goto V_213;
if ( ! ( V_1 -> V_7 & V_214 ) ) {
int V_81 ;
V_30 = - V_173 ;
for ( V_81 = 0 ; V_81 < V_36 ; V_81 ++ )
if ( F_187 ( V_81 ) && F_21 ( V_34 , V_81 ) ) {
V_30 = 0 ;
break;
}
if ( V_30 ) {
F_34 ( L_85 ,
V_208 -> V_68 ) ;
goto V_215;
}
}
F_188 ( & V_216 ) ;
F_34 ( L_86 , V_208 -> V_68 ) ;
return 0 ;
V_215:
F_189 ( & V_212 ) ;
V_213:
if ( F_183 () )
F_97 ( & V_210 . V_59 ) ;
V_211:
F_108 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_110 ( & V_38 , V_7 ) ;
return V_30 ;
}
int F_190 ( struct V_1 * V_217 )
{
unsigned long V_7 ;
if ( ! V_1 || ( V_217 != V_1 ) )
return - V_64 ;
F_34 ( L_87 , V_217 -> V_68 ) ;
F_189 ( & V_212 ) ;
if ( F_183 () )
F_97 ( & V_210 . V_59 ) ;
F_191 ( & V_216 ) ;
F_86 ( & V_37 ) ;
F_108 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_110 ( & V_38 , V_7 ) ;
F_87 ( & V_37 ) ;
return 0 ;
}
static int T_1 F_192 ( void )
{
if ( F_4 () )
return - V_173 ;
V_13 = F_193 () ;
F_37 ( ! V_13 ) ;
return 0 ;
}
