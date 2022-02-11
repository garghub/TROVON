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
F_47 ( ! ( V_1 -> V_7 & V_54 )
&& V_55 == V_11 -> V_56 ) ;
V_57:
F_48 ( V_11 -> V_58 , ! V_11 -> V_59 ) ;
F_49 ( & V_11 -> V_60 ) ;
if ( F_50 ( V_11 -> V_59 ) ) {
F_51 ( & V_11 -> V_60 ) ;
goto V_57;
}
V_11 -> V_59 = true ;
V_11 -> V_56 = V_55 ;
F_51 ( & V_11 -> V_60 ) ;
F_42 ( V_11 , V_49 , V_51 ) ;
}
void F_52 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_53 )
{
if ( F_50 ( F_47 ( ! V_11 -> V_59 ) ) )
return;
F_44 ( V_11 , V_49 , V_53 ) ;
V_11 -> V_59 = false ;
V_11 -> V_56 = NULL ;
F_53 ( & V_11 -> V_58 ) ;
}
static T_3 F_54 ( struct V_9 * V_12 ,
struct V_61 * V_62 , char * V_63 )
{
return sprintf ( V_63 , L_10 , V_1 -> V_64 ) ;
}
static T_3 F_55 ( struct V_9 * V_12 , struct V_61 * V_62 ,
const char * V_63 , T_4 V_65 )
{
int V_30 , V_66 ;
V_30 = sscanf ( V_63 , L_11 , & V_66 ) ;
if ( V_30 != 1 || V_66 < 0 || V_66 > 1 )
return - V_67 ;
if ( F_56 ( V_66 ) ) {
F_18 ( L_12 ,
V_31 , V_66 ? L_13 : L_14 ) ;
return - V_67 ;
}
F_34 ( L_15 ,
V_31 , V_66 ? L_16 : L_17 ) ;
return V_65 ;
}
static struct V_68 * F_57 ( const char * V_69 )
{
struct V_68 * V_70 ;
F_58 (t, &cpufreq_governor_list, governor_list)
if ( ! strncasecmp ( V_69 , V_70 -> V_71 , V_72 ) )
return V_70 ;
return NULL ;
}
static int F_59 ( char * V_69 , unsigned int * V_11 ,
struct V_68 * * V_73 )
{
int V_74 = - V_67 ;
if ( ! V_1 )
goto V_75;
if ( V_1 -> V_76 ) {
if ( ! strncasecmp ( V_69 , L_18 , V_72 ) ) {
* V_11 = V_77 ;
V_74 = 0 ;
} else if ( ! strncasecmp ( V_69 , L_19 ,
V_72 ) ) {
* V_11 = V_78 ;
V_74 = 0 ;
}
} else if ( F_1 () ) {
struct V_68 * V_70 ;
F_60 ( & V_79 ) ;
V_70 = F_57 ( V_69 ) ;
if ( V_70 == NULL ) {
int V_30 ;
F_61 ( & V_79 ) ;
V_30 = F_62 ( L_20 , V_69 ) ;
F_60 ( & V_79 ) ;
if ( V_30 == 0 )
V_70 = F_57 ( V_69 ) ;
}
if ( V_70 != NULL ) {
* V_73 = V_70 ;
V_74 = 0 ;
}
F_61 ( & V_79 ) ;
}
V_75:
return V_74 ;
}
static T_3 F_63 (
struct V_10 * V_11 , char * V_63 )
{
T_3 V_30 ;
if ( V_1 && V_1 -> V_76 && V_1 -> V_80 )
V_30 = sprintf ( V_63 , L_21 , V_1 -> V_80 ( V_11 -> V_14 ) ) ;
else
V_30 = sprintf ( V_63 , L_21 , V_11 -> V_52 ) ;
return V_30 ;
}
static T_3 F_64 ( struct V_10 * V_11 ,
char * V_63 )
{
unsigned int V_81 = F_65 ( V_11 -> V_14 ) ;
if ( ! V_81 )
return sprintf ( V_63 , L_22 ) ;
return sprintf ( V_63 , L_21 , V_81 ) ;
}
static T_3 F_66 ( struct V_10 * V_11 , char * V_63 )
{
if ( V_11 -> V_11 == V_78 )
return sprintf ( V_63 , L_23 ) ;
else if ( V_11 -> V_11 == V_77 )
return sprintf ( V_63 , L_24 ) ;
else if ( V_11 -> V_73 )
return F_67 ( V_63 , V_82 , L_25 ,
V_11 -> V_73 -> V_71 ) ;
return - V_67 ;
}
static T_3 F_68 ( struct V_10 * V_11 ,
const char * V_63 , T_4 V_65 )
{
int V_30 ;
char V_69 [ 16 ] ;
struct V_10 V_83 ;
V_30 = F_69 ( & V_83 , V_11 -> V_14 ) ;
if ( V_30 )
return V_30 ;
V_30 = sscanf ( V_63 , L_26 , V_69 ) ;
if ( V_30 != 1 )
return - V_67 ;
if ( F_59 ( V_69 , & V_83 . V_11 ,
& V_83 . V_73 ) )
return - V_67 ;
V_30 = F_70 ( V_11 , & V_83 ) ;
V_11 -> V_84 . V_11 = V_11 -> V_11 ;
V_11 -> V_84 . V_73 = V_11 -> V_73 ;
if ( V_30 )
return V_30 ;
else
return V_65 ;
}
static T_3 F_71 ( struct V_10 * V_11 , char * V_63 )
{
return F_67 ( V_63 , V_82 , L_25 , V_1 -> V_71 ) ;
}
static T_3 F_72 ( struct V_10 * V_11 ,
char * V_63 )
{
T_3 V_85 = 0 ;
struct V_68 * V_70 ;
if ( ! F_1 () ) {
V_85 += sprintf ( V_63 , L_27 ) ;
goto V_75;
}
F_58 (t, &cpufreq_governor_list, governor_list) {
if ( V_85 >= ( T_3 ) ( ( V_86 / sizeof( char ) )
- ( V_72 + 2 ) ) )
goto V_75;
V_85 += F_67 ( & V_63 [ V_85 ] , V_82 , L_28 , V_70 -> V_71 ) ;
}
V_75:
V_85 += sprintf ( & V_63 [ V_85 ] , L_29 ) ;
return V_85 ;
}
T_3 F_73 ( const struct V_87 * V_88 , char * V_63 )
{
T_3 V_85 = 0 ;
unsigned int V_14 ;
F_43 (cpu, mask) {
if ( V_85 )
V_85 += F_67 ( & V_63 [ V_85 ] , ( V_86 - V_85 - 2 ) , L_30 ) ;
V_85 += F_67 ( & V_63 [ V_85 ] , ( V_86 - V_85 - 2 ) , L_31 , V_14 ) ;
if ( V_85 >= ( V_86 - 5 ) )
break;
}
V_85 += sprintf ( & V_63 [ V_85 ] , L_29 ) ;
return V_85 ;
}
static T_3 F_74 ( struct V_10 * V_11 , char * V_63 )
{
return F_73 ( V_11 -> V_89 , V_63 ) ;
}
static T_3 F_75 ( struct V_10 * V_11 , char * V_63 )
{
return F_73 ( V_11 -> V_33 , V_63 ) ;
}
static T_3 F_76 ( struct V_10 * V_11 ,
const char * V_63 , T_4 V_65 )
{
unsigned int V_90 = 0 ;
unsigned int V_30 ;
if ( ! V_11 -> V_73 || ! V_11 -> V_73 -> V_91 )
return - V_67 ;
V_30 = sscanf ( V_63 , L_31 , & V_90 ) ;
if ( V_30 != 1 )
return - V_67 ;
V_11 -> V_73 -> V_91 ( V_11 , V_90 ) ;
return V_65 ;
}
static T_3 F_77 ( struct V_10 * V_11 , char * V_63 )
{
if ( ! V_11 -> V_73 || ! V_11 -> V_73 -> V_92 )
return sprintf ( V_63 , L_32 ) ;
return V_11 -> V_73 -> V_92 ( V_11 , V_63 ) ;
}
static T_3 F_78 ( struct V_10 * V_11 , char * V_63 )
{
unsigned int V_93 ;
int V_30 ;
if ( V_1 -> V_94 ) {
V_30 = V_1 -> V_94 ( V_11 -> V_14 , & V_93 ) ;
if ( ! V_30 )
return sprintf ( V_63 , L_21 , V_93 ) ;
}
return sprintf ( V_63 , L_21 , V_11 -> V_32 . V_95 ) ;
}
static T_3 F_79 ( struct V_9 * V_12 , struct V_61 * V_62 , char * V_63 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
struct V_96 * V_97 = F_81 ( V_62 ) ;
T_3 V_30 ;
if ( ! F_26 ( & V_37 ) )
return - V_67 ;
F_82 ( & V_11 -> V_98 ) ;
if ( V_97 -> F_79 )
V_30 = V_97 -> F_79 ( V_11 , V_63 ) ;
else
V_30 = - V_99 ;
F_30 ( & V_11 -> V_98 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
static T_3 F_83 ( struct V_9 * V_12 , struct V_61 * V_62 ,
const char * V_63 , T_4 V_65 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
struct V_96 * V_97 = F_81 ( V_62 ) ;
T_3 V_30 = - V_67 ;
F_84 () ;
if ( ! F_85 ( V_11 -> V_14 ) )
goto V_100;
if ( ! F_26 ( & V_37 ) )
goto V_100;
F_86 ( & V_11 -> V_98 ) ;
if ( V_97 -> F_83 )
V_30 = V_97 -> F_83 ( V_11 , V_63 , V_65 ) ;
else
V_30 = - V_99 ;
F_87 ( & V_11 -> V_98 ) ;
F_30 ( & V_37 ) ;
V_100:
F_88 () ;
return V_30 ;
}
static void F_89 ( struct V_9 * V_12 )
{
struct V_10 * V_11 = F_80 ( V_12 ) ;
F_34 ( L_33 ) ;
F_90 ( & V_11 -> V_101 ) ;
}
int F_91 ( void )
{
if ( ! V_102 ++ )
return F_92 ( V_13 ,
& V_103 . V_104 -> V_12 , L_34 , L_35 ) ;
return 0 ;
}
void F_93 ( void )
{
if ( ! -- V_102 )
F_94 ( V_13 ) ;
}
int F_95 ( const struct V_61 * V_62 )
{
int V_30 = F_91 () ;
if ( ! V_30 ) {
V_30 = F_96 ( V_13 , V_62 ) ;
if ( V_30 )
F_93 () ;
}
return V_30 ;
}
void F_97 ( const struct V_61 * V_62 )
{
F_98 ( V_13 , V_62 ) ;
F_93 () ;
}
static int F_99 ( struct V_10 * V_11 )
{
unsigned int V_105 ;
int V_30 = 0 ;
F_43 (j, policy->cpus) {
struct V_106 * V_107 ;
if ( V_105 == V_11 -> V_14 )
continue;
F_34 ( L_36 , V_105 ) ;
V_107 = F_100 ( V_105 ) ;
V_30 = F_101 ( & V_107 -> V_12 , & V_11 -> V_12 ,
L_35 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
static int F_102 ( struct V_10 * V_11 ,
struct V_106 * V_108 )
{
struct V_96 * * V_109 ;
int V_30 = 0 ;
V_30 = F_103 ( & V_11 -> V_12 , & V_110 ,
& V_108 -> V_12 , L_35 ) ;
if ( V_30 )
return V_30 ;
V_109 = V_1 -> V_62 ;
while ( ( V_109 ) && ( * V_109 ) ) {
V_30 = F_96 ( & V_11 -> V_12 , & ( ( * V_109 ) -> V_62 ) ) ;
if ( V_30 )
goto V_111;
V_109 ++ ;
}
if ( V_1 -> V_80 ) {
V_30 = F_96 ( & V_11 -> V_12 , & V_112 . V_62 ) ;
if ( V_30 )
goto V_111;
}
V_30 = F_96 ( & V_11 -> V_12 , & V_113 . V_62 ) ;
if ( V_30 )
goto V_111;
if ( V_1 -> V_94 ) {
V_30 = F_96 ( & V_11 -> V_12 , & V_94 . V_62 ) ;
if ( V_30 )
goto V_111;
}
V_30 = F_99 ( V_11 ) ;
if ( V_30 )
goto V_111;
return V_30 ;
V_111:
F_32 ( & V_11 -> V_12 ) ;
F_104 ( & V_11 -> V_101 ) ;
return V_30 ;
}
static void F_105 ( struct V_10 * V_11 )
{
struct V_68 * V_114 = NULL ;
struct V_10 V_83 ;
int V_30 = 0 ;
memcpy ( & V_83 , V_11 , sizeof( * V_11 ) ) ;
V_114 = F_57 ( F_21 ( V_115 , V_11 -> V_14 ) ) ;
if ( V_114 )
F_34 ( L_37 ,
V_11 -> V_73 -> V_71 , V_11 -> V_14 ) ;
else
V_114 = V_116 ;
V_83 . V_73 = V_114 ;
if ( V_1 -> V_76 )
F_59 ( V_114 -> V_71 , & V_83 . V_11 , NULL ) ;
V_30 = F_70 ( V_11 , & V_83 ) ;
if ( V_30 ) {
F_34 ( L_38 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
}
}
static int F_106 ( struct V_10 * V_11 ,
unsigned int V_14 , struct V_106 * V_108 )
{
int V_30 = 0 ;
unsigned long V_7 ;
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_117 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
}
F_86 ( & V_11 -> V_98 ) ;
F_108 ( & V_38 , V_7 ) ;
F_109 ( V_14 , V_11 -> V_33 ) ;
F_21 ( V_34 , V_14 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
F_87 ( & V_11 -> V_98 ) ;
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_118 ) ;
if ( ! V_30 )
V_30 = F_107 ( V_11 , V_119 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
return F_101 ( & V_108 -> V_12 , & V_11 -> V_12 , L_35 ) ;
}
static struct V_10 * F_111 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_7 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_120 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
if ( V_11 )
V_11 -> V_73 = NULL ;
return V_11 ;
}
static struct V_10 * F_112 ( void )
{
struct V_10 * V_11 ;
V_11 = F_113 ( sizeof( * V_11 ) , V_121 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_114 ( & V_11 -> V_33 , V_121 ) )
goto V_122;
if ( ! F_115 ( & V_11 -> V_89 , V_121 ) )
goto V_123;
F_116 ( & V_11 -> V_124 ) ;
F_117 ( & V_11 -> V_98 ) ;
F_118 ( & V_11 -> V_60 ) ;
F_119 ( & V_11 -> V_58 ) ;
return V_11 ;
V_123:
F_120 ( V_11 -> V_33 ) ;
V_122:
F_121 ( V_11 ) ;
return NULL ;
}
static void F_122 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
struct V_125 * V_126 ;
F_123 ( & V_127 ,
V_128 , V_11 ) ;
F_82 ( & V_11 -> V_98 ) ;
V_12 = & V_11 -> V_12 ;
V_126 = & V_11 -> V_101 ;
F_30 ( & V_11 -> V_98 ) ;
F_32 ( V_12 ) ;
F_34 ( L_41 ) ;
F_104 ( V_126 ) ;
F_34 ( L_42 ) ;
}
static void F_124 ( struct V_10 * V_11 )
{
F_120 ( V_11 -> V_89 ) ;
F_120 ( V_11 -> V_33 ) ;
F_121 ( V_11 ) ;
}
static int F_125 ( struct V_10 * V_11 , unsigned int V_14 ,
struct V_106 * V_107 )
{
int V_30 ;
if ( F_47 ( V_14 == V_11 -> V_14 ) )
return 0 ;
V_30 = F_126 ( & V_11 -> V_12 , & V_107 -> V_12 ) ;
if ( V_30 ) {
F_18 ( L_43 , V_31 , V_30 ) ;
return V_30 ;
}
F_86 ( & V_11 -> V_98 ) ;
V_11 -> V_129 = V_11 -> V_14 ;
V_11 -> V_14 = V_14 ;
F_87 ( & V_11 -> V_98 ) ;
F_123 ( & V_127 ,
V_130 , V_11 ) ;
return 0 ;
}
static int F_127 ( struct V_106 * V_108 , struct V_131 * V_132 )
{
unsigned int V_105 , V_14 = V_108 -> V_133 ;
int V_30 = - V_134 ;
struct V_10 * V_11 ;
unsigned long V_7 ;
bool V_135 = V_136 ;
#ifdef F_128
struct V_10 * V_137 ;
#endif
if ( F_129 ( V_14 ) )
return 0 ;
F_34 ( L_44 , V_14 ) ;
#ifdef F_130
V_11 = F_25 ( V_14 ) ;
if ( F_50 ( V_11 ) ) {
F_31 ( V_11 ) ;
return 0 ;
}
#endif
if ( ! F_26 ( & V_37 ) )
return 0 ;
#ifdef F_128
F_27 ( & V_38 , V_7 ) ;
F_58 (tpolicy, &cpufreq_policy_list, policy_list) {
if ( F_131 ( V_14 , V_137 -> V_89 ) ) {
F_29 ( & V_38 , V_7 ) ;
V_30 = F_106 ( V_137 , V_14 , V_108 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
}
F_29 ( & V_38 , V_7 ) ;
#endif
V_11 = V_135 ? F_111 ( V_14 ) : NULL ;
if ( ! V_11 ) {
V_135 = false ;
V_11 = F_112 () ;
if ( ! V_11 )
goto V_138;
}
if ( V_135 && V_14 != V_11 -> V_14 )
F_47 ( F_125 ( V_11 , V_14 , V_108 ) ) ;
else
V_11 -> V_14 = V_14 ;
F_132 ( V_11 -> V_33 , F_133 ( V_14 ) ) ;
F_134 ( & V_11 -> V_101 ) ;
F_135 ( & V_11 -> V_139 , V_140 ) ;
V_30 = V_1 -> V_141 ( V_11 ) ;
if ( V_30 ) {
F_34 ( L_45 ) ;
goto V_142;
}
F_136 ( V_11 -> V_89 , V_11 -> V_89 , V_11 -> V_33 ) ;
F_137 ( V_11 -> V_33 , V_11 -> V_33 , V_143 ) ;
if ( ! V_135 ) {
V_11 -> V_84 . V_144 = V_11 -> V_144 ;
V_11 -> V_84 . V_145 = V_11 -> V_145 ;
}
F_86 ( & V_11 -> V_98 ) ;
F_108 ( & V_38 , V_7 ) ;
F_43 (j, policy->cpus)
F_21 ( V_34 , V_105 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
if ( V_1 -> V_80 && ! V_1 -> V_76 ) {
V_11 -> V_52 = V_1 -> V_80 ( V_11 -> V_14 ) ;
if ( ! V_11 -> V_52 ) {
F_18 ( L_46 , V_31 ) ;
goto V_146;
}
}
if ( ( V_1 -> V_7 & V_147 )
&& F_1 () ) {
V_30 = F_138 ( V_11 , V_11 -> V_52 ) ;
if ( V_30 == - V_67 ) {
F_139 ( L_47 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
V_30 = F_140 ( V_11 , V_11 -> V_52 - 1 ,
V_148 ) ;
F_37 ( V_30 ) ;
F_139 ( L_48 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
}
}
F_123 ( & V_127 ,
V_149 , V_11 ) ;
if ( ! V_135 ) {
V_30 = F_102 ( V_11 , V_108 ) ;
if ( V_30 )
goto V_150;
F_123 ( & V_127 ,
V_151 , V_11 ) ;
}
F_108 ( & V_38 , V_7 ) ;
F_141 ( & V_11 -> V_124 , & V_152 ) ;
F_110 ( & V_38 , V_7 ) ;
F_105 ( V_11 ) ;
if ( ! V_135 ) {
V_11 -> V_84 . V_11 = V_11 -> V_11 ;
V_11 -> V_84 . V_73 = V_11 -> V_73 ;
}
F_87 ( & V_11 -> V_98 ) ;
F_142 ( & V_11 -> V_12 , V_153 ) ;
F_30 ( & V_37 ) ;
F_34 ( L_49 ) ;
return 0 ;
V_150:
V_146:
F_108 ( & V_38 , V_7 ) ;
F_43 (j, policy->cpus)
F_21 ( V_34 , V_105 ) = NULL ;
F_110 ( & V_38 , V_7 ) ;
F_87 ( & V_11 -> V_98 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
V_142:
if ( V_135 ) {
F_21 ( V_120 , V_14 ) = NULL ;
F_122 ( V_11 ) ;
}
F_124 ( V_11 ) ;
V_138:
F_30 ( & V_37 ) ;
return V_30 ;
}
static int F_143 ( struct V_106 * V_108 , struct V_131 * V_132 )
{
return F_127 ( V_108 , V_132 ) ;
}
static int F_144 ( struct V_106 * V_108 ,
struct V_131 * V_132 )
{
unsigned int V_14 = V_108 -> V_133 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_34 ( L_50 , V_31 , V_14 ) ;
F_108 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_136 )
F_21 ( V_120 , V_14 ) = V_11 ;
F_110 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_34 ( L_51 , V_31 ) ;
return - V_67 ;
}
if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_117 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
}
if ( ! V_1 -> V_76 )
strncpy ( F_21 ( V_115 , V_14 ) ,
V_11 -> V_73 -> V_71 , V_72 ) ;
F_82 ( & V_11 -> V_98 ) ;
V_33 = F_145 ( V_11 -> V_33 ) ;
F_30 ( & V_11 -> V_98 ) ;
if ( V_14 != V_11 -> V_14 ) {
F_146 ( & V_108 -> V_12 , L_35 ) ;
} else if ( V_33 > 1 ) {
int V_154 = F_147 ( V_11 -> V_33 , V_14 ) ;
struct V_106 * V_107 = F_100 ( V_154 ) ;
F_146 ( & V_107 -> V_12 , L_35 ) ;
V_30 = F_125 ( V_11 , V_154 , V_107 ) ;
if ( V_30 ) {
if ( F_101 ( & V_107 -> V_12 , & V_11 -> V_12 ,
L_35 ) )
F_18 ( L_52 ,
V_31 , V_107 -> V_133 ) ;
return V_30 ;
}
if ( ! V_136 )
F_34 ( L_53 ,
V_31 , V_154 , V_14 ) ;
} else if ( V_1 -> V_155 ) {
V_1 -> V_155 ( V_11 ) ;
}
return 0 ;
}
static int F_148 ( struct V_106 * V_108 ,
struct V_131 * V_132 )
{
unsigned int V_14 = V_108 -> V_133 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_34 ( L_51 , V_31 ) ;
return - V_67 ;
}
F_86 ( & V_11 -> V_98 ) ;
V_33 = F_145 ( V_11 -> V_33 ) ;
if ( V_33 > 1 )
F_149 ( V_14 , V_11 -> V_33 ) ;
F_87 ( & V_11 -> V_98 ) ;
if ( V_33 == 1 ) {
if ( F_1 () ) {
V_30 = F_107 ( V_11 ,
V_156 ) ;
if ( V_30 ) {
F_18 ( L_54 ,
V_31 ) ;
return V_30 ;
}
}
if ( ! V_136 )
F_122 ( V_11 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
F_108 ( & V_38 , V_7 ) ;
F_150 ( & V_11 -> V_124 ) ;
F_110 ( & V_38 , V_7 ) ;
if ( ! V_136 )
F_124 ( V_11 ) ;
} else if ( F_1 () ) {
V_30 = F_107 ( V_11 , V_118 ) ;
if ( ! V_30 )
V_30 = F_107 ( V_11 , V_119 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
F_21 ( V_34 , V_14 ) = NULL ;
return 0 ;
}
static int F_151 ( struct V_106 * V_108 , struct V_131 * V_132 )
{
unsigned int V_14 = V_108 -> V_133 ;
int V_30 ;
if ( F_129 ( V_14 ) )
return 0 ;
V_30 = F_144 ( V_108 , V_132 ) ;
if ( ! V_30 )
V_30 = F_148 ( V_108 , V_132 ) ;
return V_30 ;
}
static void V_140 ( struct V_157 * V_158 )
{
struct V_10 * V_11 =
F_152 ( V_158 , struct V_10 , V_139 ) ;
unsigned int V_14 = V_11 -> V_14 ;
F_34 ( L_55 , V_14 ) ;
F_153 ( V_14 ) ;
}
static void F_154 ( unsigned int V_14 , unsigned int V_159 ,
unsigned int V_160 )
{
struct V_10 * V_11 ;
struct V_40 V_49 ;
unsigned long V_7 ;
F_34 ( L_56 ,
V_159 , V_160 ) ;
V_49 . V_46 = V_159 ;
V_49 . V_48 = V_160 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
F_46 ( V_11 , & V_49 ) ;
F_52 ( V_11 , & V_49 , 0 ) ;
}
unsigned int F_155 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned int V_161 = 0 ;
if ( V_1 && V_1 -> V_76 && V_1 -> V_80 )
return V_1 -> V_80 ( V_14 ) ;
V_11 = F_25 ( V_14 ) ;
if ( V_11 ) {
V_161 = V_11 -> V_52 ;
F_31 ( V_11 ) ;
}
return V_161 ;
}
unsigned int F_156 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_161 = 0 ;
if ( V_11 ) {
V_161 = V_11 -> V_145 ;
F_31 ( V_11 ) ;
}
return V_161 ;
}
static unsigned int F_65 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_21 ( V_34 , V_14 ) ;
unsigned int V_161 = 0 ;
if ( ! V_1 -> V_80 )
return V_161 ;
V_161 = V_1 -> V_80 ( V_14 ) ;
if ( V_161 && V_11 -> V_52 &&
! ( V_1 -> V_7 & V_42 ) ) {
if ( F_50 ( V_161 != V_11 -> V_52 ) ) {
F_154 ( V_14 , V_11 -> V_52 , V_161 ) ;
F_157 ( & V_11 -> V_139 ) ;
}
}
return V_161 ;
}
unsigned int F_158 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_161 = 0 ;
if ( V_11 ) {
F_82 ( & V_11 -> V_98 ) ;
V_161 = F_65 ( V_14 ) ;
F_30 ( & V_11 -> V_98 ) ;
F_31 ( V_11 ) ;
}
return V_161 ;
}
int F_159 ( struct V_10 * V_11 )
{
int V_30 ;
if ( ! V_11 -> V_162 ) {
F_18 ( L_57 , V_31 ) ;
return - V_67 ;
}
F_34 ( L_58 , V_31 ,
V_11 -> V_162 ) ;
V_30 = F_140 ( V_11 , V_11 -> V_162 ,
V_163 ) ;
if ( V_30 )
F_18 ( L_59 ,
V_31 , V_11 -> V_162 , V_30 ) ;
return V_30 ;
}
void F_160 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
if ( ! F_1 () )
goto V_164;
F_34 ( L_60 , V_31 ) ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
if ( F_107 ( V_11 , V_117 ) )
F_18 ( L_61 ,
V_31 , V_11 ) ;
else if ( V_1 -> V_164
&& V_1 -> V_164 ( V_11 ) )
F_18 ( L_62 , V_31 ,
V_11 ) ;
}
V_164:
V_136 = true ;
}
void F_161 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
V_136 = false ;
if ( ! F_1 () )
return;
F_34 ( L_63 , V_31 ) ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
if ( V_1 -> V_165 && V_1 -> V_165 ( V_11 ) )
F_18 ( L_64 , V_31 ,
V_11 ) ;
else if ( F_107 ( V_11 , V_118 )
|| F_107 ( V_11 , V_119 ) )
F_18 ( L_65 ,
V_31 , V_11 ) ;
if ( F_162 ( & V_11 -> V_124 , & V_152 ) )
F_157 ( & V_11 -> V_139 ) ;
}
}
const char * F_163 ( void )
{
if ( V_1 )
return V_1 -> V_71 ;
return NULL ;
}
void * F_164 ( void )
{
if ( V_1 )
return V_1 -> V_166 ;
return NULL ;
}
int F_165 ( struct V_167 * V_168 , unsigned int V_169 )
{
int V_30 ;
if ( F_4 () )
return - V_67 ;
F_47 ( ! V_5 ) ;
switch ( V_169 ) {
case V_170 :
V_30 = F_166 (
& V_4 , V_168 ) ;
break;
case V_171 :
V_30 = F_167 (
& V_127 , V_168 ) ;
break;
default:
V_30 = - V_67 ;
}
return V_30 ;
}
int F_168 ( struct V_167 * V_168 , unsigned int V_169 )
{
int V_30 ;
if ( F_4 () )
return - V_67 ;
switch ( V_169 ) {
case V_170 :
V_30 = F_169 (
& V_4 , V_168 ) ;
break;
case V_171 :
V_30 = F_170 (
& V_127 , V_168 ) ;
break;
default:
V_30 = - V_67 ;
}
return V_30 ;
}
static int F_171 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_172 )
{
int V_30 ;
V_49 -> V_48 = V_1 -> V_173 ( V_11 , V_172 ) ;
if ( ! V_49 -> V_48 )
return 0 ;
F_34 ( L_66 ,
V_31 , V_11 -> V_14 , V_49 -> V_46 , V_49 -> V_48 ) ;
F_46 ( V_11 , V_49 ) ;
V_30 = V_1 -> V_174 ( V_11 , V_172 ) ;
F_52 ( V_11 , V_49 , V_30 ) ;
if ( V_30 )
F_18 ( L_67 ,
V_31 , V_30 ) ;
return V_30 ;
}
static int F_172 ( struct V_10 * V_11 ,
struct V_27 * V_175 , int V_172 )
{
struct V_40 V_49 = { . V_46 = V_11 -> V_52 , . V_7 = 0 } ;
unsigned int V_176 = 0 ;
int V_177 = - V_67 ;
bool V_178 ;
V_178 = ! ( V_1 -> V_7 & V_54 ) ;
if ( V_178 ) {
if ( V_1 -> V_173 ) {
V_177 = F_171 ( V_11 , & V_49 , V_172 ) ;
if ( V_177 )
return V_177 ;
V_176 = V_49 . V_48 ;
if ( V_176 )
V_49 . V_46 = V_49 . V_48 ;
}
V_49 . V_48 = V_175 [ V_172 ] . V_179 ;
F_34 ( L_68 ,
V_31 , V_11 -> V_14 , V_49 . V_46 , V_49 . V_48 ) ;
F_46 ( V_11 , & V_49 ) ;
}
V_177 = V_1 -> V_2 ( V_11 , V_172 ) ;
if ( V_177 )
F_18 ( L_69 , V_31 ,
V_177 ) ;
if ( V_178 ) {
F_52 ( V_11 , & V_49 , V_177 ) ;
if ( F_50 ( V_177 && V_176 ) ) {
V_49 . V_46 = V_176 ;
V_49 . V_48 = V_11 -> V_180 ;
F_46 ( V_11 , & V_49 ) ;
F_52 ( V_11 , & V_49 , 0 ) ;
}
}
return V_177 ;
}
int F_140 ( struct V_10 * V_11 ,
unsigned int V_181 ,
unsigned int V_182 )
{
unsigned int V_183 = V_181 ;
int V_177 = - V_67 ;
if ( F_4 () )
return - V_184 ;
if ( V_181 > V_11 -> V_145 )
V_181 = V_11 -> V_145 ;
if ( V_181 < V_11 -> V_144 )
V_181 = V_11 -> V_144 ;
F_34 ( L_70 ,
V_11 -> V_14 , V_181 , V_182 , V_183 ) ;
if ( V_181 == V_11 -> V_52 )
return 0 ;
V_11 -> V_180 = V_11 -> V_52 ;
if ( V_1 -> V_3 )
V_177 = V_1 -> V_3 ( V_11 , V_181 , V_182 ) ;
else if ( V_1 -> V_2 ) {
struct V_27 * V_175 ;
int V_172 ;
V_175 = F_173 ( V_11 -> V_14 ) ;
if ( F_50 ( ! V_175 ) ) {
F_18 ( L_71 , V_31 ) ;
goto V_75;
}
V_177 = F_174 ( V_11 , V_175 ,
V_181 , V_182 , & V_172 ) ;
if ( F_50 ( V_177 ) ) {
F_18 ( L_72 , V_31 ) ;
goto V_75;
}
if ( V_175 [ V_172 ] . V_179 == V_11 -> V_52 ) {
V_177 = 0 ;
goto V_75;
}
V_177 = F_172 ( V_11 , V_175 , V_172 ) ;
}
V_75:
return V_177 ;
}
int F_175 ( struct V_10 * V_11 ,
unsigned int V_181 ,
unsigned int V_182 )
{
int V_30 = - V_67 ;
F_86 ( & V_11 -> V_98 ) ;
V_30 = F_140 ( V_11 , V_181 , V_182 ) ;
F_87 ( & V_11 -> V_98 ) ;
return V_30 ;
}
static int F_107 ( struct V_10 * V_11 ,
unsigned int V_185 )
{
int V_30 ;
#ifdef F_176
struct V_68 * V_114 = & V_186 ;
#else
struct V_68 * V_114 = NULL ;
#endif
if ( V_136 )
return 0 ;
if ( V_11 -> V_73 -> V_187 &&
V_11 -> V_32 . V_29 >
V_11 -> V_73 -> V_187 ) {
if ( ! V_114 )
return - V_67 ;
else {
F_139 ( L_73 ,
V_11 -> V_73 -> V_71 , V_114 -> V_71 ) ;
V_11 -> V_73 = V_114 ;
}
}
if ( V_185 == V_188 )
if ( ! F_177 ( V_11 -> V_73 -> V_189 ) )
return - V_67 ;
F_34 ( L_74 ,
V_11 -> V_14 , V_185 ) ;
F_60 ( & V_190 ) ;
if ( ( V_11 -> V_191 && V_185 == V_118 )
|| ( ! V_11 -> V_191
&& ( V_185 == V_119 || V_185 == V_117 ) ) ) {
F_61 ( & V_190 ) ;
return - V_192 ;
}
if ( V_185 == V_117 )
V_11 -> V_191 = false ;
else if ( V_185 == V_118 )
V_11 -> V_191 = true ;
F_61 ( & V_190 ) ;
V_30 = V_11 -> V_73 -> V_73 ( V_11 , V_185 ) ;
if ( ! V_30 ) {
if ( V_185 == V_188 )
V_11 -> V_73 -> V_193 ++ ;
else if ( V_185 == V_156 )
V_11 -> V_73 -> V_193 -- ;
} else {
F_60 ( & V_190 ) ;
if ( V_185 == V_117 )
V_11 -> V_191 = true ;
else if ( V_185 == V_118 )
V_11 -> V_191 = false ;
F_61 ( & V_190 ) ;
}
if ( ( ( V_185 == V_188 ) && V_30 ) ||
( ( V_185 == V_156 ) && ! V_30 ) )
F_178 ( V_11 -> V_73 -> V_189 ) ;
return V_30 ;
}
int F_179 ( struct V_68 * V_73 )
{
int V_74 ;
if ( ! V_73 )
return - V_67 ;
if ( F_4 () )
return - V_184 ;
F_60 ( & V_79 ) ;
V_73 -> V_193 = 0 ;
V_74 = - V_192 ;
if ( F_57 ( V_73 -> V_71 ) == NULL ) {
V_74 = 0 ;
F_141 ( & V_73 -> V_194 , & V_195 ) ;
}
F_61 ( & V_79 ) ;
return V_74 ;
}
void F_180 ( struct V_68 * V_73 )
{
int V_14 ;
if ( ! V_73 )
return;
if ( F_4 () )
return;
F_181 (cpu) {
if ( F_85 ( V_14 ) )
continue;
if ( ! strcmp ( F_21 ( V_115 , V_14 ) , V_73 -> V_71 ) )
strcpy ( F_21 ( V_115 , V_14 ) , L_75 ) ;
}
F_60 ( & V_79 ) ;
F_150 ( & V_73 -> V_194 ) ;
F_61 ( & V_79 ) ;
return;
}
int F_69 ( struct V_10 * V_11 , unsigned int V_14 )
{
struct V_10 * V_196 ;
if ( ! V_11 )
return - V_67 ;
V_196 = F_25 ( V_14 ) ;
if ( ! V_196 )
return - V_67 ;
memcpy ( V_11 , V_196 , sizeof( * V_11 ) ) ;
F_31 ( V_196 ) ;
return 0 ;
}
static int F_70 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
struct V_68 * V_197 ;
int V_30 ;
F_34 ( L_76 ,
V_83 -> V_14 , V_83 -> V_144 , V_83 -> V_145 ) ;
memcpy ( & V_83 -> V_32 , & V_11 -> V_32 , sizeof( V_11 -> V_32 ) ) ;
if ( V_83 -> V_144 > V_11 -> V_145 || V_83 -> V_145 < V_11 -> V_144 )
return - V_67 ;
V_30 = V_1 -> V_198 ( V_83 ) ;
if ( V_30 )
return V_30 ;
F_123 ( & V_127 ,
V_199 , V_83 ) ;
F_123 ( & V_127 ,
V_200 , V_83 ) ;
V_30 = V_1 -> V_198 ( V_83 ) ;
if ( V_30 )
return V_30 ;
F_123 ( & V_127 ,
V_201 , V_83 ) ;
V_11 -> V_144 = V_83 -> V_144 ;
V_11 -> V_145 = V_83 -> V_145 ;
F_34 ( L_77 ,
V_11 -> V_144 , V_11 -> V_145 ) ;
if ( V_1 -> V_76 ) {
V_11 -> V_11 = V_83 -> V_11 ;
F_34 ( L_78 ) ;
return V_1 -> V_76 ( V_83 ) ;
}
if ( V_83 -> V_73 == V_11 -> V_73 )
goto V_75;
F_34 ( L_79 ) ;
V_197 = V_11 -> V_73 ;
if ( V_197 ) {
F_107 ( V_11 , V_117 ) ;
F_87 ( & V_11 -> V_98 ) ;
F_107 ( V_11 , V_156 ) ;
F_86 ( & V_11 -> V_98 ) ;
}
V_11 -> V_73 = V_83 -> V_73 ;
if ( ! F_107 ( V_11 , V_188 ) ) {
if ( ! F_107 ( V_11 , V_118 ) )
goto V_75;
F_87 ( & V_11 -> V_98 ) ;
F_107 ( V_11 , V_156 ) ;
F_86 ( & V_11 -> V_98 ) ;
}
F_34 ( L_80 , V_11 -> V_73 -> V_71 ) ;
if ( V_197 ) {
V_11 -> V_73 = V_197 ;
F_107 ( V_11 , V_188 ) ;
F_107 ( V_11 , V_118 ) ;
}
return - V_67 ;
V_75:
F_34 ( L_81 ) ;
return F_107 ( V_11 , V_119 ) ;
}
int F_153 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
struct V_10 V_83 ;
int V_30 ;
if ( ! V_11 )
return - V_184 ;
F_86 ( & V_11 -> V_98 ) ;
F_34 ( L_82 , V_14 ) ;
memcpy ( & V_83 , V_11 , sizeof( * V_11 ) ) ;
V_83 . V_144 = V_11 -> V_84 . V_144 ;
V_83 . V_145 = V_11 -> V_84 . V_145 ;
V_83 . V_11 = V_11 -> V_84 . V_11 ;
V_83 . V_73 = V_11 -> V_84 . V_73 ;
if ( V_1 -> V_80 && ! V_1 -> V_76 ) {
V_83 . V_52 = V_1 -> V_80 ( V_14 ) ;
if ( F_47 ( ! V_83 . V_52 ) ) {
V_30 = - V_99 ;
goto V_100;
}
if ( ! V_11 -> V_52 ) {
F_34 ( L_83 ) ;
V_11 -> V_52 = V_83 . V_52 ;
} else {
if ( V_11 -> V_52 != V_83 . V_52 && F_1 () )
F_154 ( V_14 , V_11 -> V_52 ,
V_83 . V_52 ) ;
}
}
V_30 = F_70 ( V_11 , & V_83 ) ;
V_100:
F_87 ( & V_11 -> V_98 ) ;
F_31 ( V_11 ) ;
return V_30 ;
}
static int F_182 ( struct V_167 * V_202 ,
unsigned long V_203 , void * V_204 )
{
unsigned int V_14 = ( unsigned long ) V_204 ;
struct V_106 * V_108 ;
V_108 = F_100 ( V_14 ) ;
if ( V_108 ) {
switch ( V_203 & ~ V_205 ) {
case V_206 :
F_127 ( V_108 , NULL ) ;
break;
case V_207 :
F_144 ( V_108 , NULL ) ;
break;
case V_208 :
F_148 ( V_108 , NULL ) ;
break;
case V_209 :
F_127 ( V_108 , NULL ) ;
break;
}
}
return V_210 ;
}
static int F_183 ( int V_50 )
{
struct V_27 * V_175 ;
struct V_10 * V_11 ;
int V_30 = - V_67 ;
F_58 (policy, &cpufreq_policy_list, policy_list) {
V_175 = F_173 ( V_11 -> V_14 ) ;
if ( V_175 ) {
V_30 = F_184 ( V_11 ,
V_175 ) ;
if ( V_30 ) {
F_18 ( L_84 ,
V_31 ) ;
break;
}
V_11 -> V_84 . V_145 = V_11 -> V_145 ;
F_107 ( V_11 , V_119 ) ;
}
}
return V_30 ;
}
int F_56 ( int V_50 )
{
unsigned long V_7 ;
int V_30 = 0 ;
if ( V_1 -> V_64 == V_50 )
return 0 ;
F_108 ( & V_38 , V_7 ) ;
V_1 -> V_64 = V_50 ;
F_110 ( & V_38 , V_7 ) ;
V_30 = V_1 -> V_211 ( V_50 ) ;
if ( V_30 ) {
F_108 ( & V_38 , V_7 ) ;
V_1 -> V_64 = ! V_50 ;
F_110 ( & V_38 , V_7 ) ;
F_18 ( L_85 ,
V_31 , V_50 ? L_13 : L_14 ) ;
}
return V_30 ;
}
int F_185 ( void )
{
if ( F_41 ( V_1 ) )
return V_1 -> V_212 ;
return 0 ;
}
int F_186 ( void )
{
return V_1 -> V_64 ;
}
int F_187 ( struct V_1 * V_166 )
{
unsigned long V_7 ;
int V_30 ;
if ( F_4 () )
return - V_184 ;
if ( ! V_166 || ! V_166 -> V_198 || ! V_166 -> V_141 ||
! ( V_166 -> V_76 || V_166 -> V_2 ||
V_166 -> V_3 ) ||
( V_166 -> V_76 && ( V_166 -> V_2 ||
V_166 -> V_3 ) ) ||
( ! ! V_166 -> V_173 != ! ! V_166 -> V_174 ) )
return - V_67 ;
F_34 ( L_86 , V_166 -> V_71 ) ;
if ( V_166 -> V_76 )
V_166 -> V_7 |= V_42 ;
F_108 ( & V_38 , V_7 ) ;
if ( V_1 ) {
F_110 ( & V_38 , V_7 ) ;
return - V_213 ;
}
V_1 = V_166 ;
F_110 ( & V_38 , V_7 ) ;
if ( F_185 () ) {
if ( ! V_1 -> V_211 )
V_1 -> V_211 = F_183 ;
V_30 = F_95 ( & V_214 . V_62 ) ;
if ( V_30 ) {
F_18 ( L_87 ,
V_31 ) ;
goto V_215;
}
}
V_30 = F_188 ( & V_216 ) ;
if ( V_30 )
goto V_217;
if ( ! ( V_1 -> V_7 & V_218 ) ) {
int V_85 ;
V_30 = - V_184 ;
for ( V_85 = 0 ; V_85 < V_36 ; V_85 ++ )
if ( F_189 ( V_85 ) && F_21 ( V_34 , V_85 ) ) {
V_30 = 0 ;
break;
}
if ( V_30 ) {
F_34 ( L_88 ,
V_166 -> V_71 ) ;
goto V_219;
}
}
F_190 ( & V_220 ) ;
F_34 ( L_89 , V_166 -> V_71 ) ;
return 0 ;
V_219:
F_191 ( & V_216 ) ;
V_217:
if ( F_185 () )
F_97 ( & V_214 . V_62 ) ;
V_215:
F_108 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_110 ( & V_38 , V_7 ) ;
return V_30 ;
}
int F_192 ( struct V_1 * V_221 )
{
unsigned long V_7 ;
if ( ! V_1 || ( V_221 != V_1 ) )
return - V_67 ;
F_34 ( L_90 , V_221 -> V_71 ) ;
F_191 ( & V_216 ) ;
if ( F_185 () )
F_97 ( & V_214 . V_62 ) ;
F_193 ( & V_220 ) ;
F_86 ( & V_37 ) ;
F_108 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_110 ( & V_38 , V_7 ) ;
F_87 ( & V_37 ) ;
return 0 ;
}
static int T_1 F_194 ( void )
{
if ( F_4 () )
return - V_184 ;
V_13 = F_195 () ;
F_37 ( ! V_13 ) ;
return 0 ;
}
