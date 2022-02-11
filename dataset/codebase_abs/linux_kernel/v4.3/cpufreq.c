static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static bool F_3 ( struct V_1 * V_2 , bool V_4 )
{
return V_4 == ! F_1 ( V_2 ) ;
}
static struct V_1 * F_4 ( struct V_1 * V_2 ,
bool V_4 )
{
do {
V_2 = F_5 ( V_2 , V_5 ) ;
if ( & V_2 -> V_5 == & V_6 )
return NULL ;
} while ( ! F_3 ( V_2 , V_4 ) );
return V_2 ;
}
static struct V_1 * F_6 ( bool V_4 )
{
struct V_1 * V_2 ;
if ( F_7 ( & V_6 ) )
return NULL ;
V_2 = F_8 ( & V_6 , F_9 ( * V_2 ) ,
V_5 ) ;
if ( ! F_3 ( V_2 , V_4 ) )
V_2 = F_4 ( V_2 , V_4 ) ;
return V_2 ;
}
static inline bool F_10 ( void )
{
return V_7 -> V_8 || V_7 -> V_9 ;
}
static int T_1 F_11 ( void )
{
F_12 ( & V_10 ) ;
V_11 = true ;
return 0 ;
}
static int F_13 ( void )
{
return V_12 ;
}
void F_14 ( void )
{
V_12 = 1 ;
}
bool F_15 ( void )
{
return ! ! ( V_7 -> V_13 & V_14 ) ;
}
struct V_15 * F_16 ( struct V_1 * V_2 )
{
if ( F_15 () )
return & V_2 -> V_16 ;
else
return V_17 ;
}
struct V_18 * F_17 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
return V_2 && ! F_1 ( V_2 ) ?
V_2 -> V_21 : NULL ;
}
static inline T_2 F_19 ( unsigned int V_19 , T_2 * V_22 )
{
T_2 V_23 ;
T_2 V_24 ;
T_2 V_25 ;
V_24 = F_20 ( F_21 () ) ;
V_25 = F_22 ( V_19 ) . V_26 [ V_27 ] ;
V_25 += F_22 ( V_19 ) . V_26 [ V_28 ] ;
V_25 += F_22 ( V_19 ) . V_26 [ V_29 ] ;
V_25 += F_22 ( V_19 ) . V_26 [ V_30 ] ;
V_25 += F_22 ( V_19 ) . V_26 [ V_31 ] ;
V_25 += F_22 ( V_19 ) . V_26 [ V_32 ] ;
V_23 = V_24 - V_25 ;
if ( V_22 )
* V_22 = F_23 ( V_24 ) ;
return F_23 ( V_23 ) ;
}
T_2 F_24 ( unsigned int V_19 , T_2 * V_22 , int V_33 )
{
T_2 V_23 = F_25 ( V_19 , V_33 ? V_22 : NULL ) ;
if ( V_23 == - 1ULL )
return F_19 ( V_19 , V_22 ) ;
else if ( ! V_33 )
V_23 += F_26 ( V_19 , V_22 ) ;
return V_23 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_18 * V_34 ,
unsigned int V_35 )
{
int V_36 ;
V_36 = F_28 ( V_2 , V_34 ) ;
if ( V_36 ) {
F_29 ( L_1 , V_37 , V_36 ) ;
return V_36 ;
}
V_2 -> V_38 . V_35 = V_35 ;
F_30 ( V_2 -> V_3 ) ;
return 0 ;
}
struct V_1 * F_31 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
return V_2 && F_32 ( V_19 , V_2 -> V_3 ) ? V_2 : NULL ;
}
unsigned int F_33 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_31 ( V_19 ) ;
if ( ! V_2 || F_34 ( V_2 -> V_39 ) ) {
F_29 ( L_2 ,
V_37 , V_2 ? L_3 : L_4 , V_19 ) ;
return 0 ;
}
return F_35 ( V_2 -> V_39 ) / 1000 ;
}
struct V_1 * F_36 ( unsigned int V_19 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_13 ;
if ( F_37 ( V_19 >= V_40 ) )
return NULL ;
F_38 ( & V_41 , V_13 ) ;
if ( V_7 ) {
V_2 = F_31 ( V_19 ) ;
if ( V_2 )
F_39 ( & V_2 -> V_16 ) ;
}
F_40 ( & V_41 , V_13 ) ;
return V_2 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_16 ) ;
}
static void F_43 ( unsigned long V_42 , struct V_43 * V_44 )
{
#ifndef F_44
static unsigned long V_45 ;
static unsigned int V_46 ;
if ( V_44 -> V_13 & V_47 )
return;
if ( ! V_46 ) {
V_45 = V_48 ;
V_46 = V_44 -> V_49 ;
F_45 ( L_5 ,
V_45 , V_46 ) ;
}
if ( V_42 == V_50 && V_44 -> V_49 != V_44 -> V_51 ) {
V_48 = F_46 ( V_45 , V_46 ,
V_44 -> V_51 ) ;
F_45 ( L_6 ,
V_48 , V_44 -> V_51 ) ;
}
#endif
}
static void F_47 ( struct V_1 * V_2 ,
struct V_43 * V_52 , unsigned int V_53 )
{
F_48 ( F_49 () ) ;
if ( F_13 () )
return;
V_52 -> V_13 = V_7 -> V_13 ;
F_45 ( L_7 ,
V_53 , V_52 -> V_51 ) ;
switch ( V_53 ) {
case V_54 :
if ( ! ( V_7 -> V_13 & V_47 ) ) {
if ( ( V_2 ) && ( V_2 -> V_19 == V_52 -> V_19 ) &&
( V_2 -> V_55 ) && ( V_2 -> V_55 != V_52 -> V_49 ) ) {
F_45 ( L_8 ,
V_52 -> V_49 , V_2 -> V_55 ) ;
V_52 -> V_49 = V_2 -> V_55 ;
}
}
F_50 ( & V_10 ,
V_54 , V_52 ) ;
F_43 ( V_54 , V_52 ) ;
break;
case V_50 :
F_43 ( V_50 , V_52 ) ;
F_45 ( L_9 ,
( unsigned long ) V_52 -> V_51 , ( unsigned long ) V_52 -> V_19 ) ;
F_51 ( V_52 -> V_51 , V_52 -> V_19 ) ;
F_50 ( & V_10 ,
V_50 , V_52 ) ;
if ( F_52 ( V_2 ) && F_52 ( V_2 -> V_19 == V_52 -> V_19 ) )
V_2 -> V_55 = V_52 -> V_51 ;
break;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_43 * V_52 , unsigned int V_53 )
{
F_54 (freqs->cpu, policy->cpus)
F_47 ( V_2 , V_52 , V_53 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_56 )
{
F_53 ( V_2 , V_52 , V_50 ) ;
if ( ! V_56 )
return;
F_56 ( V_52 -> V_49 , V_52 -> V_51 ) ;
F_53 ( V_2 , V_52 , V_54 ) ;
F_53 ( V_2 , V_52 , V_50 ) ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_43 * V_52 )
{
F_37 ( ! ( V_7 -> V_13 & V_57 )
&& V_58 == V_2 -> V_59 ) ;
V_60:
F_58 ( V_2 -> V_61 , ! V_2 -> V_62 ) ;
F_59 ( & V_2 -> V_63 ) ;
if ( F_60 ( V_2 -> V_62 ) ) {
F_61 ( & V_2 -> V_63 ) ;
goto V_60;
}
V_2 -> V_62 = true ;
V_2 -> V_59 = V_58 ;
F_61 ( & V_2 -> V_63 ) ;
F_53 ( V_2 , V_52 , V_54 ) ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_56 )
{
if ( F_60 ( F_37 ( ! V_2 -> V_62 ) ) )
return;
F_55 ( V_2 , V_52 , V_56 ) ;
V_2 -> V_62 = false ;
V_2 -> V_59 = NULL ;
F_63 ( & V_2 -> V_61 ) ;
}
static T_3 F_64 ( struct V_15 * V_16 ,
struct V_64 * V_65 , char * V_66 )
{
return sprintf ( V_66 , L_10 , V_7 -> V_67 ) ;
}
static T_3 F_65 ( struct V_15 * V_16 , struct V_64 * V_65 ,
const char * V_66 , T_4 V_68 )
{
int V_36 , V_69 ;
V_36 = sscanf ( V_66 , L_11 , & V_69 ) ;
if ( V_36 != 1 || V_69 < 0 || V_69 > 1 )
return - V_70 ;
if ( F_66 ( V_69 ) ) {
F_29 ( L_12 ,
V_37 , V_69 ? L_13 : L_14 ) ;
return - V_70 ;
}
F_45 ( L_15 ,
V_37 , V_69 ? L_16 : L_17 ) ;
return V_68 ;
}
static struct V_71 * F_67 ( const char * V_72 )
{
struct V_71 * V_73 ;
F_68 (t)
if ( ! strncasecmp ( V_72 , V_73 -> V_74 , V_75 ) )
return V_73 ;
return NULL ;
}
static int F_69 ( char * V_72 , unsigned int * V_2 ,
struct V_71 * * V_76 )
{
int V_77 = - V_70 ;
if ( V_7 -> V_78 ) {
if ( ! strncasecmp ( V_72 , L_18 , V_75 ) ) {
* V_2 = V_79 ;
V_77 = 0 ;
} else if ( ! strncasecmp ( V_72 , L_19 ,
V_75 ) ) {
* V_2 = V_80 ;
V_77 = 0 ;
}
} else {
struct V_71 * V_73 ;
F_70 ( & V_81 ) ;
V_73 = F_67 ( V_72 ) ;
if ( V_73 == NULL ) {
int V_36 ;
F_71 ( & V_81 ) ;
V_36 = F_72 ( L_20 , V_72 ) ;
F_70 ( & V_81 ) ;
if ( V_36 == 0 )
V_73 = F_67 ( V_72 ) ;
}
if ( V_73 != NULL ) {
* V_76 = V_73 ;
V_77 = 0 ;
}
F_71 ( & V_81 ) ;
}
return V_77 ;
}
static T_3 F_73 ( struct V_1 * V_2 , char * V_66 )
{
T_3 V_36 ;
if ( V_7 && V_7 -> V_78 && V_7 -> V_82 )
V_36 = sprintf ( V_66 , L_21 , V_7 -> V_82 ( V_2 -> V_19 ) ) ;
else
V_36 = sprintf ( V_66 , L_21 , V_2 -> V_55 ) ;
return V_36 ;
}
static T_3 F_74 ( struct V_1 * V_2 ,
char * V_66 )
{
unsigned int V_83 = F_75 ( V_2 ) ;
if ( ! V_83 )
return sprintf ( V_66 , L_22 ) ;
return sprintf ( V_66 , L_21 , V_83 ) ;
}
static T_3 F_76 ( struct V_1 * V_2 , char * V_66 )
{
if ( V_2 -> V_2 == V_80 )
return sprintf ( V_66 , L_23 ) ;
else if ( V_2 -> V_2 == V_79 )
return sprintf ( V_66 , L_24 ) ;
else if ( V_2 -> V_76 )
return F_77 ( V_66 , V_84 , L_25 ,
V_2 -> V_76 -> V_74 ) ;
return - V_70 ;
}
static T_3 F_78 ( struct V_1 * V_2 ,
const char * V_66 , T_4 V_68 )
{
int V_36 ;
char V_72 [ 16 ] ;
struct V_1 V_85 ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_36 = sscanf ( V_66 , L_26 , V_72 ) ;
if ( V_36 != 1 )
return - V_70 ;
if ( F_69 ( V_72 , & V_85 . V_2 ,
& V_85 . V_76 ) )
return - V_70 ;
V_36 = F_79 ( V_2 , & V_85 ) ;
return V_36 ? V_36 : V_68 ;
}
static T_3 F_80 ( struct V_1 * V_2 , char * V_66 )
{
return F_77 ( V_66 , V_84 , L_25 , V_7 -> V_74 ) ;
}
static T_3 F_81 ( struct V_1 * V_2 ,
char * V_66 )
{
T_3 V_86 = 0 ;
struct V_71 * V_73 ;
if ( ! F_10 () ) {
V_86 += sprintf ( V_66 , L_27 ) ;
goto V_87;
}
F_68 (t) {
if ( V_86 >= ( T_3 ) ( ( V_88 / sizeof( char ) )
- ( V_75 + 2 ) ) )
goto V_87;
V_86 += F_77 ( & V_66 [ V_86 ] , V_84 , L_28 , V_73 -> V_74 ) ;
}
V_87:
V_86 += sprintf ( & V_66 [ V_86 ] , L_29 ) ;
return V_86 ;
}
T_3 F_82 ( const struct V_89 * V_90 , char * V_66 )
{
T_3 V_86 = 0 ;
unsigned int V_19 ;
F_54 (cpu, mask) {
if ( V_86 )
V_86 += F_77 ( & V_66 [ V_86 ] , ( V_88 - V_86 - 2 ) , L_30 ) ;
V_86 += F_77 ( & V_66 [ V_86 ] , ( V_88 - V_86 - 2 ) , L_31 , V_19 ) ;
if ( V_86 >= ( V_88 - 5 ) )
break;
}
V_86 += sprintf ( & V_66 [ V_86 ] , L_29 ) ;
return V_86 ;
}
static T_3 F_83 ( struct V_1 * V_2 , char * V_66 )
{
return F_82 ( V_2 -> V_91 , V_66 ) ;
}
static T_3 F_84 ( struct V_1 * V_2 , char * V_66 )
{
return F_82 ( V_2 -> V_3 , V_66 ) ;
}
static T_3 F_85 ( struct V_1 * V_2 ,
const char * V_66 , T_4 V_68 )
{
unsigned int V_92 = 0 ;
unsigned int V_36 ;
if ( ! V_2 -> V_76 || ! V_2 -> V_76 -> V_93 )
return - V_70 ;
V_36 = sscanf ( V_66 , L_31 , & V_92 ) ;
if ( V_36 != 1 )
return - V_70 ;
V_2 -> V_76 -> V_93 ( V_2 , V_92 ) ;
return V_68 ;
}
static T_3 F_86 ( struct V_1 * V_2 , char * V_66 )
{
if ( ! V_2 -> V_76 || ! V_2 -> V_76 -> V_94 )
return sprintf ( V_66 , L_32 ) ;
return V_2 -> V_76 -> V_94 ( V_2 , V_66 ) ;
}
static T_3 F_87 ( struct V_1 * V_2 , char * V_66 )
{
unsigned int V_95 ;
int V_36 ;
if ( V_7 -> V_96 ) {
V_36 = V_7 -> V_96 ( V_2 -> V_19 , & V_95 ) ;
if ( ! V_36 )
return sprintf ( V_66 , L_21 , V_95 ) ;
}
return sprintf ( V_66 , L_21 , V_2 -> V_38 . V_97 ) ;
}
static T_3 F_88 ( struct V_15 * V_16 , struct V_64 * V_65 , char * V_66 )
{
struct V_1 * V_2 = F_89 ( V_16 ) ;
struct V_98 * V_99 = F_90 ( V_65 ) ;
T_3 V_36 ;
F_91 ( & V_2 -> V_100 ) ;
if ( V_99 -> F_88 )
V_36 = V_99 -> F_88 ( V_2 , V_66 ) ;
else
V_36 = - V_101 ;
F_92 ( & V_2 -> V_100 ) ;
return V_36 ;
}
static T_3 F_93 ( struct V_15 * V_16 , struct V_64 * V_65 ,
const char * V_66 , T_4 V_68 )
{
struct V_1 * V_2 = F_89 ( V_16 ) ;
struct V_98 * V_99 = F_90 ( V_65 ) ;
T_3 V_36 = - V_70 ;
F_94 () ;
if ( ! F_95 ( V_2 -> V_19 ) )
goto V_102;
F_96 ( & V_2 -> V_100 ) ;
if ( F_60 ( F_1 ( V_2 ) ) ) {
V_36 = - V_103 ;
goto V_104;
}
if ( V_99 -> F_93 )
V_36 = V_99 -> F_93 ( V_2 , V_66 , V_68 ) ;
else
V_36 = - V_101 ;
V_104:
F_97 ( & V_2 -> V_100 ) ;
V_102:
F_98 () ;
return V_36 ;
}
static void F_99 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_89 ( V_16 ) ;
F_45 ( L_33 ) ;
F_100 ( & V_2 -> V_105 ) ;
}
int F_101 ( void )
{
if ( ! V_106 ++ )
return F_102 ( V_17 ,
& V_107 . V_108 -> V_16 , L_34 , L_35 ) ;
return 0 ;
}
void F_103 ( void )
{
if ( ! -- V_106 )
F_104 ( V_17 ) ;
}
int F_105 ( const struct V_64 * V_65 )
{
int V_36 = F_101 () ;
if ( ! V_36 ) {
V_36 = F_106 ( V_17 , V_65 ) ;
if ( V_36 )
F_103 () ;
}
return V_36 ;
}
void F_107 ( const struct V_64 * V_65 )
{
F_108 ( V_17 , V_65 ) ;
F_103 () ;
}
static int F_109 ( struct V_1 * V_2 , int V_19 )
{
struct V_109 * V_110 ;
F_45 ( L_36 , V_37 , V_19 ) ;
if ( ! V_2 )
return 0 ;
V_110 = F_110 ( V_19 ) ;
if ( F_37 ( ! V_110 ) )
return 0 ;
return F_111 ( & V_110 -> V_16 , & V_2 -> V_16 , L_35 ) ;
}
static void F_112 ( struct V_1 * V_2 , int V_19 )
{
struct V_109 * V_110 ;
F_45 ( L_37 , V_37 , V_19 ) ;
V_110 = F_110 ( V_19 ) ;
if ( F_37 ( ! V_110 ) )
return;
F_113 ( & V_110 -> V_16 , L_35 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
unsigned int V_111 ;
int V_36 = 0 ;
F_54 (j, policy->real_cpus) {
if ( V_111 == V_2 -> V_112 )
continue;
V_36 = F_109 ( V_2 , V_111 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
static void F_115 ( struct V_1 * V_2 )
{
unsigned int V_111 ;
F_54 (j, policy->real_cpus) {
if ( V_111 == V_2 -> V_112 )
continue;
F_112 ( V_2 , V_111 ) ;
}
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_98 * * V_113 ;
int V_36 = 0 ;
V_113 = V_7 -> V_65 ;
while ( V_113 && * V_113 ) {
V_36 = F_106 ( & V_2 -> V_16 , & ( ( * V_113 ) -> V_65 ) ) ;
if ( V_36 )
return V_36 ;
V_113 ++ ;
}
if ( V_7 -> V_82 ) {
V_36 = F_106 ( & V_2 -> V_16 , & V_114 . V_65 ) ;
if ( V_36 )
return V_36 ;
}
V_36 = F_106 ( & V_2 -> V_16 , & V_115 . V_65 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_96 ) {
V_36 = F_106 ( & V_2 -> V_16 , & V_96 . V_65 ) ;
if ( V_36 )
return V_36 ;
}
return F_114 ( V_2 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_71 * V_116 = NULL ;
struct V_1 V_85 ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_116 = F_67 ( V_2 -> V_117 ) ;
if ( V_116 )
F_45 ( L_38 ,
V_2 -> V_76 -> V_74 , V_2 -> V_19 ) ;
else
V_116 = V_118 ;
V_85 . V_76 = V_116 ;
if ( V_7 -> V_78 )
F_69 ( V_116 -> V_74 , & V_85 . V_2 , NULL ) ;
return F_79 ( V_2 , & V_85 ) ;
}
static int F_118 ( struct V_1 * V_2 , unsigned int V_19 )
{
int V_36 = 0 ;
if ( F_32 ( V_19 , V_2 -> V_3 ) )
return 0 ;
if ( F_10 () ) {
V_36 = F_119 ( V_2 , V_119 ) ;
if ( V_36 ) {
F_29 ( L_39 , V_37 ) ;
return V_36 ;
}
}
F_96 ( & V_2 -> V_100 ) ;
F_120 ( V_19 , V_2 -> V_3 ) ;
F_97 ( & V_2 -> V_100 ) ;
if ( F_10 () ) {
V_36 = F_119 ( V_2 , V_120 ) ;
if ( ! V_36 )
V_36 = F_119 ( V_2 , V_121 ) ;
if ( V_36 ) {
F_29 ( L_40 , V_37 ) ;
return V_36 ;
}
}
return 0 ;
}
static struct V_1 * F_121 ( unsigned int V_19 )
{
struct V_109 * V_122 = F_110 ( V_19 ) ;
struct V_1 * V_2 ;
int V_36 ;
if ( F_37 ( ! V_122 ) )
return NULL ;
V_2 = F_122 ( sizeof( * V_2 ) , V_123 ) ;
if ( ! V_2 )
return NULL ;
if ( ! F_123 ( & V_2 -> V_3 , V_123 ) )
goto V_124;
if ( ! F_124 ( & V_2 -> V_91 , V_123 ) )
goto V_125;
if ( ! F_124 ( & V_2 -> V_126 , V_123 ) )
goto V_127;
V_36 = F_125 ( & V_2 -> V_16 , & V_128 , & V_122 -> V_16 ,
L_35 ) ;
if ( V_36 ) {
F_29 ( L_41 , V_37 , V_36 ) ;
goto V_129;
}
F_126 ( & V_2 -> V_5 ) ;
F_127 ( & V_2 -> V_100 ) ;
F_128 ( & V_2 -> V_63 ) ;
F_129 ( & V_2 -> V_61 ) ;
F_130 ( & V_2 -> V_105 ) ;
F_131 ( & V_2 -> V_130 , V_131 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_112 = V_19 ;
return V_2 ;
V_129:
F_132 ( V_2 -> V_126 ) ;
V_127:
F_132 ( V_2 -> V_91 ) ;
V_125:
F_132 ( V_2 -> V_3 ) ;
V_124:
F_133 ( V_2 ) ;
return NULL ;
}
static void F_134 ( struct V_1 * V_2 , bool V_132 )
{
struct V_15 * V_16 ;
struct V_133 * V_134 ;
if ( V_132 )
F_135 ( & V_135 ,
V_136 , V_2 ) ;
F_96 ( & V_2 -> V_100 ) ;
F_115 ( V_2 ) ;
V_16 = & V_2 -> V_16 ;
V_134 = & V_2 -> V_105 ;
F_97 ( & V_2 -> V_100 ) ;
F_42 ( V_16 ) ;
F_45 ( L_42 ) ;
F_136 ( V_134 ) ;
F_45 ( L_43 ) ;
}
static void F_137 ( struct V_1 * V_2 , bool V_132 )
{
unsigned long V_13 ;
int V_19 ;
F_138 ( & V_41 , V_13 ) ;
F_139 ( & V_2 -> V_5 ) ;
F_54 (cpu, policy->related_cpus)
F_18 ( V_20 , V_19 ) = NULL ;
F_140 ( & V_41 , V_13 ) ;
F_134 ( V_2 , V_132 ) ;
F_132 ( V_2 -> V_126 ) ;
F_132 ( V_2 -> V_91 ) ;
F_132 ( V_2 -> V_3 ) ;
F_133 ( V_2 ) ;
}
static int F_141 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
bool V_85 ;
unsigned long V_13 ;
unsigned int V_111 ;
int V_36 ;
F_45 ( L_44 , V_37 , V_19 ) ;
V_2 = F_18 ( V_20 , V_19 ) ;
if ( V_2 ) {
F_37 ( ! F_32 ( V_19 , V_2 -> V_91 ) ) ;
if ( ! F_1 ( V_2 ) )
return F_118 ( V_2 , V_19 ) ;
V_85 = false ;
F_96 ( & V_2 -> V_100 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_76 = NULL ;
F_97 ( & V_2 -> V_100 ) ;
} else {
V_85 = true ;
V_2 = F_121 ( V_19 ) ;
if ( ! V_2 )
return - V_137 ;
}
F_142 ( V_2 -> V_3 , F_143 ( V_19 ) ) ;
V_36 = V_7 -> V_138 ( V_2 ) ;
if ( V_36 ) {
F_45 ( L_45 ) ;
goto V_139;
}
F_96 ( & V_2 -> V_100 ) ;
if ( V_85 ) {
F_144 ( V_2 -> V_91 , V_2 -> V_91 , V_2 -> V_3 ) ;
F_145 ( V_2 -> V_126 , V_2 -> V_3 , V_140 ) ;
}
F_145 ( V_2 -> V_3 , V_2 -> V_3 , V_141 ) ;
if ( V_85 ) {
V_2 -> V_142 . V_143 = V_2 -> V_143 ;
V_2 -> V_142 . V_144 = V_2 -> V_144 ;
F_138 ( & V_41 , V_13 ) ;
F_54 (j, policy->related_cpus)
F_18 ( V_20 , V_111 ) = V_2 ;
F_140 ( & V_41 , V_13 ) ;
}
if ( V_7 -> V_82 && ! V_7 -> V_78 ) {
V_2 -> V_55 = V_7 -> V_82 ( V_2 -> V_19 ) ;
if ( ! V_2 -> V_55 ) {
F_29 ( L_46 , V_37 ) ;
goto V_145;
}
}
if ( ( V_7 -> V_13 & V_146 )
&& F_10 () ) {
V_36 = F_146 ( V_2 , V_2 -> V_55 ) ;
if ( V_36 == - V_70 ) {
F_147 ( L_47 ,
V_37 , V_2 -> V_19 , V_2 -> V_55 ) ;
V_36 = F_148 ( V_2 , V_2 -> V_55 - 1 ,
V_147 ) ;
F_48 ( V_36 ) ;
F_147 ( L_48 ,
V_37 , V_2 -> V_19 , V_2 -> V_55 ) ;
}
}
F_135 ( & V_135 ,
V_148 , V_2 ) ;
if ( V_85 ) {
V_36 = F_116 ( V_2 ) ;
if ( V_36 )
goto V_145;
F_135 ( & V_135 ,
V_149 , V_2 ) ;
F_138 ( & V_41 , V_13 ) ;
F_149 ( & V_2 -> V_5 , & V_6 ) ;
F_140 ( & V_41 , V_13 ) ;
}
V_36 = F_117 ( V_2 ) ;
if ( V_36 ) {
F_29 ( L_49 ,
V_37 , V_19 , V_36 ) ;
V_85 = false ;
goto V_145;
}
F_97 ( & V_2 -> V_100 ) ;
F_150 ( & V_2 -> V_16 , V_150 ) ;
if ( V_7 -> V_151 )
V_7 -> V_151 ( V_2 ) ;
F_45 ( L_50 ) ;
return 0 ;
V_145:
F_97 ( & V_2 -> V_100 ) ;
if ( V_7 -> exit )
V_7 -> exit ( V_2 ) ;
V_139:
F_137 ( V_2 , ! V_85 ) ;
return V_36 ;
}
static int F_151 ( struct V_109 * V_122 , struct V_152 * V_153 )
{
unsigned V_19 = V_122 -> V_154 ;
int V_36 ;
F_152 ( V_122 , L_51 , V_37 , V_19 ) ;
if ( F_95 ( V_19 ) ) {
V_36 = F_141 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
V_36 = V_2 && ! F_153 ( V_19 , V_2 -> V_126 )
? F_109 ( V_2 , V_19 ) : 0 ;
}
return V_36 ;
}
static void F_154 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
F_45 ( L_52 , V_37 , V_19 ) ;
V_2 = F_31 ( V_19 ) ;
if ( ! V_2 ) {
F_45 ( L_53 , V_37 ) ;
return;
}
if ( F_10 () ) {
int V_36 = F_119 ( V_2 , V_119 ) ;
if ( V_36 )
F_29 ( L_39 , V_37 ) ;
}
F_96 ( & V_2 -> V_100 ) ;
F_155 ( V_19 , V_2 -> V_3 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_10 () )
strncpy ( V_2 -> V_117 , V_2 -> V_76 -> V_74 ,
V_75 ) ;
} else if ( V_19 == V_2 -> V_19 ) {
V_2 -> V_19 = F_156 ( V_2 -> V_3 ) ;
}
F_97 ( & V_2 -> V_100 ) ;
if ( ! F_1 ( V_2 ) ) {
if ( F_10 () ) {
int V_36 = F_119 ( V_2 , V_120 ) ;
if ( ! V_36 )
V_36 = F_119 ( V_2 , V_121 ) ;
if ( V_36 )
F_29 ( L_40 , V_37 ) ;
}
} else if ( V_7 -> V_155 ) {
V_7 -> V_155 ( V_2 ) ;
}
}
static void F_157 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
if ( ! V_2 ) {
F_45 ( L_53 , V_37 ) ;
return;
}
if ( ! F_1 ( V_2 ) )
return;
if ( F_10 () ) {
int V_36 = F_119 ( V_2 , V_156 ) ;
if ( V_36 )
F_29 ( L_54 , V_37 ) ;
}
if ( V_7 -> exit ) {
V_7 -> exit ( V_2 ) ;
V_2 -> V_21 = NULL ;
}
}
static void F_158 ( struct V_109 * V_122 , struct V_152 * V_153 )
{
unsigned int V_19 = V_122 -> V_154 ;
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
if ( ! V_2 )
return;
if ( F_95 ( V_19 ) ) {
F_154 ( V_19 ) ;
F_157 ( V_19 ) ;
}
F_155 ( V_19 , V_2 -> V_126 ) ;
if ( F_2 ( V_2 -> V_126 ) ) {
F_137 ( V_2 , true ) ;
return;
}
if ( V_19 != V_2 -> V_112 ) {
F_112 ( V_2 , V_19 ) ;
} else {
unsigned int V_157 = F_159 ( V_2 -> V_126 ) ;
struct V_109 * V_158 = F_110 ( V_157 ) ;
F_152 ( V_122 , L_55 , V_37 , V_157 ) ;
F_113 ( & V_158 -> V_16 , L_35 ) ;
V_2 -> V_112 = V_157 ;
F_37 ( F_160 ( & V_2 -> V_16 , & V_158 -> V_16 ) ) ;
}
}
static void V_131 ( struct V_159 * V_160 )
{
struct V_1 * V_2 =
F_161 ( V_160 , struct V_1 , V_130 ) ;
unsigned int V_19 = V_2 -> V_19 ;
F_45 ( L_56 , V_19 ) ;
F_162 ( V_19 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
unsigned int V_161 )
{
struct V_43 V_52 ;
F_45 ( L_57 ,
V_2 -> V_55 , V_161 ) ;
V_52 . V_49 = V_2 -> V_55 ;
V_52 . V_51 = V_161 ;
F_57 ( V_2 , & V_52 ) ;
F_62 ( V_2 , & V_52 , 0 ) ;
}
unsigned int F_164 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
unsigned int V_162 = 0 ;
if ( V_7 && V_7 -> V_78 && V_7 -> V_82 )
return V_7 -> V_82 ( V_19 ) ;
V_2 = F_36 ( V_19 ) ;
if ( V_2 ) {
V_162 = V_2 -> V_55 ;
F_41 ( V_2 ) ;
}
return V_162 ;
}
unsigned int F_165 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
unsigned int V_162 = 0 ;
if ( V_2 ) {
V_162 = V_2 -> V_144 ;
F_41 ( V_2 ) ;
}
return V_162 ;
}
static unsigned int F_75 ( struct V_1 * V_2 )
{
unsigned int V_162 = 0 ;
if ( ! V_7 -> V_82 )
return V_162 ;
V_162 = V_7 -> V_82 ( V_2 -> V_19 ) ;
if ( F_60 ( F_1 ( V_2 ) ) )
return V_162 ;
if ( V_162 && V_2 -> V_55 &&
! ( V_7 -> V_13 & V_47 ) ) {
if ( F_60 ( V_162 != V_2 -> V_55 ) ) {
F_163 ( V_2 , V_162 ) ;
F_166 ( & V_2 -> V_130 ) ;
}
}
return V_162 ;
}
unsigned int F_167 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
unsigned int V_162 = 0 ;
if ( V_2 ) {
F_91 ( & V_2 -> V_100 ) ;
V_162 = F_75 ( V_2 ) ;
F_92 ( & V_2 -> V_100 ) ;
F_41 ( V_2 ) ;
}
return V_162 ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_36 ;
if ( ! V_2 -> V_163 ) {
F_45 ( L_58 , V_37 ) ;
return 0 ;
}
F_45 ( L_59 , V_37 ,
V_2 -> V_163 ) ;
V_36 = F_148 ( V_2 , V_2 -> V_163 ,
V_164 ) ;
if ( V_36 )
F_29 ( L_60 ,
V_37 , V_2 -> V_163 , V_36 ) ;
return V_36 ;
}
void F_169 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
if ( ! F_10 () )
goto V_165;
F_45 ( L_61 , V_37 ) ;
F_170 (policy) {
if ( F_119 ( V_2 , V_119 ) )
F_29 ( L_62 ,
V_37 , V_2 ) ;
else if ( V_7 -> V_165
&& V_7 -> V_165 ( V_2 ) )
F_29 ( L_63 , V_37 ,
V_2 ) ;
}
V_165:
V_166 = true ;
}
void F_171 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_166 = false ;
if ( ! F_10 () )
return;
F_45 ( L_64 , V_37 ) ;
F_170 (policy) {
if ( V_7 -> V_167 && V_7 -> V_167 ( V_2 ) )
F_29 ( L_65 , V_37 ,
V_2 ) ;
else if ( F_119 ( V_2 , V_120 )
|| F_119 ( V_2 , V_121 ) )
F_29 ( L_66 ,
V_37 , V_2 ) ;
}
V_2 = F_31 ( F_159 ( V_141 ) ) ;
if ( F_37 ( ! V_2 ) )
return;
F_166 ( & V_2 -> V_130 ) ;
}
const char * F_172 ( void )
{
if ( V_7 )
return V_7 -> V_74 ;
return NULL ;
}
void * F_173 ( void )
{
if ( V_7 )
return V_7 -> V_168 ;
return NULL ;
}
int F_174 ( struct V_169 * V_170 , unsigned int V_171 )
{
int V_36 ;
if ( F_13 () )
return - V_70 ;
F_37 ( ! V_11 ) ;
switch ( V_171 ) {
case V_172 :
V_36 = F_175 (
& V_10 , V_170 ) ;
break;
case V_173 :
V_36 = F_176 (
& V_135 , V_170 ) ;
break;
default:
V_36 = - V_70 ;
}
return V_36 ;
}
int F_177 ( struct V_169 * V_170 , unsigned int V_171 )
{
int V_36 ;
if ( F_13 () )
return - V_70 ;
switch ( V_171 ) {
case V_172 :
V_36 = F_178 (
& V_10 , V_170 ) ;
break;
case V_173 :
V_36 = F_179 (
& V_135 , V_170 ) ;
break;
default:
V_36 = - V_70 ;
}
return V_36 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_174 )
{
int V_36 ;
V_52 -> V_51 = V_7 -> V_175 ( V_2 , V_174 ) ;
if ( ! V_52 -> V_51 )
return 0 ;
F_45 ( L_67 ,
V_37 , V_2 -> V_19 , V_52 -> V_49 , V_52 -> V_51 ) ;
F_57 ( V_2 , V_52 ) ;
V_36 = V_7 -> V_176 ( V_2 , V_174 ) ;
F_62 ( V_2 , V_52 , V_36 ) ;
if ( V_36 )
F_29 ( L_68 ,
V_37 , V_36 ) ;
return V_36 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_18 * V_21 , int V_174 )
{
struct V_43 V_52 = { . V_49 = V_2 -> V_55 , . V_13 = 0 } ;
unsigned int V_177 = 0 ;
int V_178 = - V_70 ;
bool V_132 ;
V_132 = ! ( V_7 -> V_13 & V_57 ) ;
if ( V_132 ) {
if ( V_7 -> V_175 ) {
V_178 = F_180 ( V_2 , & V_52 , V_174 ) ;
if ( V_178 )
return V_178 ;
V_177 = V_52 . V_51 ;
if ( V_177 )
V_52 . V_49 = V_52 . V_51 ;
}
V_52 . V_51 = V_21 [ V_174 ] . V_179 ;
F_45 ( L_69 ,
V_37 , V_2 -> V_19 , V_52 . V_49 , V_52 . V_51 ) ;
F_57 ( V_2 , & V_52 ) ;
}
V_178 = V_7 -> V_8 ( V_2 , V_174 ) ;
if ( V_178 )
F_29 ( L_70 , V_37 ,
V_178 ) ;
if ( V_132 ) {
F_62 ( V_2 , & V_52 , V_178 ) ;
if ( F_60 ( V_178 && V_177 ) ) {
V_52 . V_49 = V_177 ;
V_52 . V_51 = V_2 -> V_180 ;
F_57 ( V_2 , & V_52 ) ;
F_62 ( V_2 , & V_52 , 0 ) ;
}
}
return V_178 ;
}
int F_148 ( struct V_1 * V_2 ,
unsigned int V_181 ,
unsigned int V_182 )
{
unsigned int V_183 = V_181 ;
int V_178 = - V_70 ;
if ( F_13 () )
return - V_184 ;
if ( V_181 > V_2 -> V_144 )
V_181 = V_2 -> V_144 ;
if ( V_181 < V_2 -> V_143 )
V_181 = V_2 -> V_143 ;
F_45 ( L_71 ,
V_2 -> V_19 , V_181 , V_182 , V_183 ) ;
if ( V_181 == V_2 -> V_55 )
return 0 ;
V_2 -> V_180 = V_2 -> V_55 ;
if ( V_7 -> V_9 )
V_178 = V_7 -> V_9 ( V_2 , V_181 , V_182 ) ;
else if ( V_7 -> V_8 ) {
struct V_18 * V_21 ;
int V_174 ;
V_21 = F_17 ( V_2 -> V_19 ) ;
if ( F_60 ( ! V_21 ) ) {
F_29 ( L_72 , V_37 ) ;
goto V_87;
}
V_178 = F_182 ( V_2 , V_21 ,
V_181 , V_182 , & V_174 ) ;
if ( F_60 ( V_178 ) ) {
F_29 ( L_73 , V_37 ) ;
goto V_87;
}
if ( V_21 [ V_174 ] . V_179 == V_2 -> V_55 ) {
V_178 = 0 ;
goto V_87;
}
V_178 = F_181 ( V_2 , V_21 , V_174 ) ;
}
V_87:
return V_178 ;
}
int F_183 ( struct V_1 * V_2 ,
unsigned int V_181 ,
unsigned int V_182 )
{
int V_36 = - V_70 ;
F_96 ( & V_2 -> V_100 ) ;
V_36 = F_148 ( V_2 , V_181 , V_182 ) ;
F_97 ( & V_2 -> V_100 ) ;
return V_36 ;
}
static int F_119 ( struct V_1 * V_2 ,
unsigned int V_185 )
{
int V_36 ;
#ifdef F_184
struct V_71 * V_116 = & V_186 ;
#else
struct V_71 * V_116 = NULL ;
#endif
if ( V_166 )
return 0 ;
if ( ! V_2 -> V_76 )
return - V_70 ;
if ( V_2 -> V_76 -> V_187 &&
V_2 -> V_38 . V_35 >
V_2 -> V_76 -> V_187 ) {
if ( ! V_116 )
return - V_70 ;
else {
F_147 ( L_74 ,
V_2 -> V_76 -> V_74 , V_116 -> V_74 ) ;
V_2 -> V_76 = V_116 ;
}
}
if ( V_185 == V_188 )
if ( ! F_185 ( V_2 -> V_76 -> V_189 ) )
return - V_70 ;
F_45 ( L_75 , V_37 , V_2 -> V_19 , V_185 ) ;
F_70 ( & V_190 ) ;
if ( ( V_2 -> V_191 && V_185 == V_120 )
|| ( ! V_2 -> V_191
&& ( V_185 == V_121 || V_185 == V_119 ) ) ) {
F_71 ( & V_190 ) ;
return - V_103 ;
}
if ( V_185 == V_119 )
V_2 -> V_191 = false ;
else if ( V_185 == V_120 )
V_2 -> V_191 = true ;
F_71 ( & V_190 ) ;
V_36 = V_2 -> V_76 -> V_76 ( V_2 , V_185 ) ;
if ( ! V_36 ) {
if ( V_185 == V_188 )
V_2 -> V_76 -> V_192 ++ ;
else if ( V_185 == V_156 )
V_2 -> V_76 -> V_192 -- ;
} else {
F_70 ( & V_190 ) ;
if ( V_185 == V_119 )
V_2 -> V_191 = true ;
else if ( V_185 == V_120 )
V_2 -> V_191 = false ;
F_71 ( & V_190 ) ;
}
if ( ( ( V_185 == V_188 ) && V_36 ) ||
( ( V_185 == V_156 ) && ! V_36 ) )
F_186 ( V_2 -> V_76 -> V_189 ) ;
return V_36 ;
}
int F_187 ( struct V_71 * V_76 )
{
int V_77 ;
if ( ! V_76 )
return - V_70 ;
if ( F_13 () )
return - V_184 ;
F_70 ( & V_81 ) ;
V_76 -> V_192 = 0 ;
V_77 = - V_103 ;
if ( ! F_67 ( V_76 -> V_74 ) ) {
V_77 = 0 ;
F_149 ( & V_76 -> V_193 , & V_194 ) ;
}
F_71 ( & V_81 ) ;
return V_77 ;
}
void F_188 ( struct V_71 * V_76 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
if ( ! V_76 )
return;
if ( F_13 () )
return;
F_38 ( & V_41 , V_13 ) ;
F_189 (policy) {
if ( ! strcmp ( V_2 -> V_117 , V_76 -> V_74 ) ) {
V_2 -> V_76 = NULL ;
strcpy ( V_2 -> V_117 , L_76 ) ;
}
}
F_40 ( & V_41 , V_13 ) ;
F_70 ( & V_81 ) ;
F_139 ( & V_76 -> V_193 ) ;
F_71 ( & V_81 ) ;
return;
}
int F_190 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_1 * V_195 ;
if ( ! V_2 )
return - V_70 ;
V_195 = F_36 ( V_19 ) ;
if ( ! V_195 )
return - V_70 ;
memcpy ( V_2 , V_195 , sizeof( * V_2 ) ) ;
F_41 ( V_195 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_1 * V_85 )
{
struct V_71 * V_196 ;
int V_36 ;
F_45 ( L_77 ,
V_85 -> V_19 , V_85 -> V_143 , V_85 -> V_144 ) ;
memcpy ( & V_85 -> V_38 , & V_2 -> V_38 , sizeof( V_2 -> V_38 ) ) ;
if ( V_85 -> V_143 > V_85 -> V_144 )
return - V_70 ;
V_36 = V_7 -> V_197 ( V_85 ) ;
if ( V_36 )
return V_36 ;
F_135 ( & V_135 ,
V_198 , V_85 ) ;
V_36 = V_7 -> V_197 ( V_85 ) ;
if ( V_36 )
return V_36 ;
F_135 ( & V_135 ,
V_199 , V_85 ) ;
V_2 -> V_143 = V_85 -> V_143 ;
V_2 -> V_144 = V_85 -> V_144 ;
F_45 ( L_78 ,
V_2 -> V_143 , V_2 -> V_144 ) ;
if ( V_7 -> V_78 ) {
V_2 -> V_2 = V_85 -> V_2 ;
F_45 ( L_79 ) ;
return V_7 -> V_78 ( V_85 ) ;
}
if ( V_85 -> V_76 == V_2 -> V_76 )
goto V_87;
F_45 ( L_80 ) ;
V_196 = V_2 -> V_76 ;
if ( V_196 ) {
V_36 = F_119 ( V_2 , V_119 ) ;
if ( V_36 ) {
F_45 ( L_81 ,
V_37 , V_196 -> V_74 , V_36 ) ;
return V_36 ;
}
F_97 ( & V_2 -> V_100 ) ;
V_36 = F_119 ( V_2 , V_156 ) ;
F_96 ( & V_2 -> V_100 ) ;
if ( V_36 ) {
F_29 ( L_82 ,
V_37 , V_196 -> V_74 , V_36 ) ;
return V_36 ;
}
}
V_2 -> V_76 = V_85 -> V_76 ;
V_36 = F_119 ( V_2 , V_188 ) ;
if ( ! V_36 ) {
V_36 = F_119 ( V_2 , V_120 ) ;
if ( ! V_36 )
goto V_87;
F_97 ( & V_2 -> V_100 ) ;
F_119 ( V_2 , V_156 ) ;
F_96 ( & V_2 -> V_100 ) ;
}
F_45 ( L_83 , V_2 -> V_76 -> V_74 ) ;
if ( V_196 ) {
V_2 -> V_76 = V_196 ;
if ( F_119 ( V_2 , V_188 ) )
V_2 -> V_76 = NULL ;
else
F_119 ( V_2 , V_120 ) ;
}
return V_36 ;
V_87:
F_45 ( L_84 ) ;
return F_119 ( V_2 , V_121 ) ;
}
int F_162 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
struct V_1 V_85 ;
int V_36 ;
if ( ! V_2 )
return - V_184 ;
F_96 ( & V_2 -> V_100 ) ;
F_45 ( L_85 , V_19 ) ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_85 . V_143 = V_2 -> V_142 . V_143 ;
V_85 . V_144 = V_2 -> V_142 . V_144 ;
if ( V_7 -> V_82 && ! V_7 -> V_78 ) {
V_85 . V_55 = V_7 -> V_82 ( V_19 ) ;
if ( F_37 ( ! V_85 . V_55 ) ) {
V_36 = - V_101 ;
goto V_102;
}
if ( ! V_2 -> V_55 ) {
F_45 ( L_86 ) ;
V_2 -> V_55 = V_85 . V_55 ;
} else {
if ( V_2 -> V_55 != V_85 . V_55 && F_10 () )
F_163 ( V_2 , V_85 . V_55 ) ;
}
}
V_36 = F_79 ( V_2 , & V_85 ) ;
V_102:
F_97 ( & V_2 -> V_100 ) ;
F_41 ( V_2 ) ;
return V_36 ;
}
static int F_191 ( struct V_169 * V_200 ,
unsigned long V_201 , void * V_202 )
{
unsigned int V_19 = ( unsigned long ) V_202 ;
switch ( V_201 & ~ V_203 ) {
case V_204 :
F_141 ( V_19 ) ;
break;
case V_205 :
F_154 ( V_19 ) ;
break;
case V_206 :
F_157 ( V_19 ) ;
break;
case V_207 :
F_141 ( V_19 ) ;
break;
}
return V_208 ;
}
static int F_192 ( int V_53 )
{
struct V_18 * V_21 ;
struct V_1 * V_2 ;
int V_36 = - V_70 ;
F_170 (policy) {
V_21 = F_17 ( V_2 -> V_19 ) ;
if ( V_21 ) {
V_36 = F_193 ( V_2 ,
V_21 ) ;
if ( V_36 ) {
F_29 ( L_87 ,
V_37 ) ;
break;
}
V_2 -> V_142 . V_144 = V_2 -> V_144 ;
F_119 ( V_2 , V_121 ) ;
}
}
return V_36 ;
}
int F_66 ( int V_53 )
{
unsigned long V_13 ;
int V_36 = 0 ;
if ( V_7 -> V_67 == V_53 )
return 0 ;
F_138 ( & V_41 , V_13 ) ;
V_7 -> V_67 = V_53 ;
F_140 ( & V_41 , V_13 ) ;
V_36 = V_7 -> V_209 ( V_53 ) ;
if ( V_36 ) {
F_138 ( & V_41 , V_13 ) ;
V_7 -> V_67 = ! V_53 ;
F_140 ( & V_41 , V_13 ) ;
F_29 ( L_88 ,
V_37 , V_53 ? L_13 : L_14 ) ;
}
return V_36 ;
}
int F_194 ( void )
{
if ( F_52 ( V_7 ) )
return V_7 -> V_210 ;
return 0 ;
}
static int F_195 ( void )
{
int V_36 ;
if ( ! F_194 () )
return 0 ;
if ( ! V_7 -> V_209 )
V_7 -> V_209 = F_192 ;
V_36 = F_105 ( & V_211 . V_65 ) ;
if ( V_36 )
F_29 ( L_89 ,
V_37 ) ;
return V_36 ;
}
static void F_196 ( void )
{
if ( F_194 () )
F_107 ( & V_211 . V_65 ) ;
}
int F_197 ( void )
{
if ( ! V_7 )
return - V_70 ;
if ( F_194 () )
return 0 ;
V_7 -> V_210 = true ;
return F_195 () ;
}
int F_198 ( void )
{
return V_7 -> V_67 ;
}
int F_199 ( struct V_7 * V_168 )
{
unsigned long V_13 ;
int V_36 ;
if ( F_13 () )
return - V_184 ;
if ( ! V_168 || ! V_168 -> V_197 || ! V_168 -> V_138 ||
! ( V_168 -> V_78 || V_168 -> V_8 ||
V_168 -> V_9 ) ||
( V_168 -> V_78 && ( V_168 -> V_8 ||
V_168 -> V_9 ) ) ||
( ! ! V_168 -> V_175 != ! ! V_168 -> V_176 ) )
return - V_70 ;
F_45 ( L_90 , V_168 -> V_74 ) ;
F_94 () ;
F_138 ( & V_41 , V_13 ) ;
if ( V_7 ) {
F_140 ( & V_41 , V_13 ) ;
V_36 = - V_212 ;
goto V_87;
}
V_7 = V_168 ;
F_140 ( & V_41 , V_13 ) ;
if ( V_168 -> V_78 )
V_168 -> V_13 |= V_47 ;
V_36 = F_195 () ;
if ( V_36 )
goto V_213;
V_36 = F_200 ( & V_214 ) ;
if ( V_36 )
goto V_215;
if ( ! ( V_7 -> V_13 & V_216 ) &&
F_7 ( & V_6 ) ) {
F_45 ( L_91 , V_37 ,
V_168 -> V_74 ) ;
goto V_217;
}
F_201 ( & V_218 ) ;
F_45 ( L_92 , V_168 -> V_74 ) ;
V_87:
F_98 () ;
return V_36 ;
V_217:
F_202 ( & V_214 ) ;
V_215:
F_196 () ;
V_213:
F_138 ( & V_41 , V_13 ) ;
V_7 = NULL ;
F_140 ( & V_41 , V_13 ) ;
goto V_87;
}
int F_203 ( struct V_7 * V_219 )
{
unsigned long V_13 ;
if ( ! V_7 || ( V_219 != V_7 ) )
return - V_70 ;
F_45 ( L_93 , V_219 -> V_74 ) ;
F_94 () ;
F_202 ( & V_214 ) ;
F_196 () ;
F_204 ( & V_218 ) ;
F_138 ( & V_41 , V_13 ) ;
V_7 = NULL ;
F_140 ( & V_41 , V_13 ) ;
F_98 () ;
return 0 ;
}
static int T_1 F_205 ( void )
{
if ( F_13 () )
return - V_184 ;
V_17 = F_206 () ;
F_48 ( ! V_17 ) ;
F_207 ( & V_220 ) ;
return 0 ;
}
