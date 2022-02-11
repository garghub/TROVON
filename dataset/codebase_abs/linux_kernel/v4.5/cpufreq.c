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
if ( F_5 ( & V_2 -> V_5 , & V_6 ) )
return NULL ;
V_2 = F_6 ( V_2 , V_5 ) ;
} while ( ! F_3 ( V_2 , V_4 ) );
return V_2 ;
}
static struct V_1 * F_7 ( bool V_4 )
{
struct V_1 * V_2 ;
if ( F_8 ( & V_6 ) )
return NULL ;
V_2 = F_9 ( & V_6 , F_10 ( * V_2 ) ,
V_5 ) ;
if ( ! F_3 ( V_2 , V_4 ) )
V_2 = F_4 ( V_2 , V_4 ) ;
return V_2 ;
}
static inline bool F_11 ( void )
{
return V_7 -> V_8 || V_7 -> V_9 ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_10 ) ;
V_11 = true ;
return 0 ;
}
static int F_14 ( void )
{
return V_12 ;
}
void F_15 ( void )
{
V_12 = 1 ;
}
bool F_16 ( void )
{
return ! ! ( V_7 -> V_13 & V_14 ) ;
}
struct V_15 * F_17 ( struct V_1 * V_2 )
{
if ( F_16 () )
return & V_2 -> V_16 ;
else
return V_17 ;
}
struct V_18 * F_18 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_19 ( V_20 , V_19 ) ;
return V_2 && ! F_1 ( V_2 ) ?
V_2 -> V_21 : NULL ;
}
static inline T_2 F_20 ( unsigned int V_19 , T_2 * V_22 )
{
T_2 V_23 ;
T_2 V_24 ;
T_2 V_25 ;
V_24 = F_21 ( F_22 () ) ;
V_25 = F_23 ( V_19 ) . V_26 [ V_27 ] ;
V_25 += F_23 ( V_19 ) . V_26 [ V_28 ] ;
V_25 += F_23 ( V_19 ) . V_26 [ V_29 ] ;
V_25 += F_23 ( V_19 ) . V_26 [ V_30 ] ;
V_25 += F_23 ( V_19 ) . V_26 [ V_31 ] ;
V_25 += F_23 ( V_19 ) . V_26 [ V_32 ] ;
V_23 = V_24 - V_25 ;
if ( V_22 )
* V_22 = F_24 ( V_24 ) ;
return F_24 ( V_23 ) ;
}
T_2 F_25 ( unsigned int V_19 , T_2 * V_22 , int V_33 )
{
T_2 V_23 = F_26 ( V_19 , V_33 ? V_22 : NULL ) ;
if ( V_23 == - 1ULL )
return F_20 ( V_19 , V_22 ) ;
else if ( ! V_33 )
V_23 += F_27 ( V_19 , V_22 ) ;
return V_23 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_18 * V_34 ,
unsigned int V_35 )
{
int V_36 ;
V_36 = F_29 ( V_2 , V_34 ) ;
if ( V_36 ) {
F_30 ( L_1 , V_37 , V_36 ) ;
return V_36 ;
}
V_2 -> V_38 . V_35 = V_35 ;
F_31 ( V_2 -> V_3 ) ;
return 0 ;
}
struct V_1 * F_32 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_19 ( V_20 , V_19 ) ;
return V_2 && F_33 ( V_19 , V_2 -> V_3 ) ? V_2 : NULL ;
}
unsigned int F_34 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_32 ( V_19 ) ;
if ( ! V_2 || F_35 ( V_2 -> V_39 ) ) {
F_30 ( L_2 ,
V_37 , V_2 ? L_3 : L_4 , V_19 ) ;
return 0 ;
}
return F_36 ( V_2 -> V_39 ) / 1000 ;
}
struct V_1 * F_37 ( unsigned int V_19 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_13 ;
if ( F_38 ( V_19 >= V_40 ) )
return NULL ;
F_39 ( & V_41 , V_13 ) ;
if ( V_7 ) {
V_2 = F_32 ( V_19 ) ;
if ( V_2 )
F_40 ( & V_2 -> V_16 ) ;
}
F_41 ( & V_41 , V_13 ) ;
return V_2 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_16 ) ;
}
static void F_44 ( unsigned long V_42 , struct V_43 * V_44 )
{
#ifndef F_45
static unsigned long V_45 ;
static unsigned int V_46 ;
if ( V_44 -> V_13 & V_47 )
return;
if ( ! V_46 ) {
V_45 = V_48 ;
V_46 = V_44 -> V_49 ;
F_46 ( L_5 ,
V_45 , V_46 ) ;
}
if ( V_42 == V_50 && V_44 -> V_49 != V_44 -> V_51 ) {
V_48 = F_47 ( V_45 , V_46 ,
V_44 -> V_51 ) ;
F_46 ( L_6 ,
V_48 , V_44 -> V_51 ) ;
}
#endif
}
static void F_48 ( struct V_1 * V_2 ,
struct V_43 * V_52 , unsigned int V_53 )
{
F_49 ( F_50 () ) ;
if ( F_14 () )
return;
V_52 -> V_13 = V_7 -> V_13 ;
F_46 ( L_7 ,
V_53 , V_52 -> V_51 ) ;
switch ( V_53 ) {
case V_54 :
if ( ! ( V_7 -> V_13 & V_47 ) ) {
if ( ( V_2 ) && ( V_2 -> V_19 == V_52 -> V_19 ) &&
( V_2 -> V_55 ) && ( V_2 -> V_55 != V_52 -> V_49 ) ) {
F_46 ( L_8 ,
V_52 -> V_49 , V_2 -> V_55 ) ;
V_52 -> V_49 = V_2 -> V_55 ;
}
}
F_51 ( & V_10 ,
V_54 , V_52 ) ;
F_44 ( V_54 , V_52 ) ;
break;
case V_50 :
F_44 ( V_50 , V_52 ) ;
F_46 ( L_9 ,
( unsigned long ) V_52 -> V_51 , ( unsigned long ) V_52 -> V_19 ) ;
F_52 ( V_52 -> V_51 , V_52 -> V_19 ) ;
F_51 ( & V_10 ,
V_50 , V_52 ) ;
if ( F_53 ( V_2 ) && F_53 ( V_2 -> V_19 == V_52 -> V_19 ) )
V_2 -> V_55 = V_52 -> V_51 ;
break;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_43 * V_52 , unsigned int V_53 )
{
F_55 (freqs->cpu, policy->cpus)
F_48 ( V_2 , V_52 , V_53 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_56 )
{
F_54 ( V_2 , V_52 , V_50 ) ;
if ( ! V_56 )
return;
F_57 ( V_52 -> V_49 , V_52 -> V_51 ) ;
F_54 ( V_2 , V_52 , V_54 ) ;
F_54 ( V_2 , V_52 , V_50 ) ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_43 * V_52 )
{
F_38 ( ! ( V_7 -> V_13 & V_57 )
&& V_58 == V_2 -> V_59 ) ;
V_60:
F_59 ( V_2 -> V_61 , ! V_2 -> V_62 ) ;
F_60 ( & V_2 -> V_63 ) ;
if ( F_61 ( V_2 -> V_62 ) ) {
F_62 ( & V_2 -> V_63 ) ;
goto V_60;
}
V_2 -> V_62 = true ;
V_2 -> V_59 = V_58 ;
F_62 ( & V_2 -> V_63 ) ;
F_54 ( V_2 , V_52 , V_54 ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_56 )
{
if ( F_61 ( F_38 ( ! V_2 -> V_62 ) ) )
return;
F_56 ( V_2 , V_52 , V_56 ) ;
V_2 -> V_62 = false ;
V_2 -> V_59 = NULL ;
F_64 ( & V_2 -> V_61 ) ;
}
static T_3 F_65 ( struct V_15 * V_16 ,
struct V_64 * V_65 , char * V_66 )
{
return sprintf ( V_66 , L_10 , V_7 -> V_67 ) ;
}
static T_3 F_66 ( struct V_15 * V_16 , struct V_64 * V_65 ,
const char * V_66 , T_4 V_68 )
{
int V_36 , V_69 ;
V_36 = sscanf ( V_66 , L_11 , & V_69 ) ;
if ( V_36 != 1 || V_69 < 0 || V_69 > 1 )
return - V_70 ;
if ( F_67 ( V_69 ) ) {
F_30 ( L_12 ,
V_37 , V_69 ? L_13 : L_14 ) ;
return - V_70 ;
}
F_46 ( L_15 ,
V_37 , V_69 ? L_16 : L_17 ) ;
return V_68 ;
}
static struct V_71 * F_68 ( const char * V_72 )
{
struct V_71 * V_73 ;
F_69 (t)
if ( ! strncasecmp ( V_72 , V_73 -> V_74 , V_75 ) )
return V_73 ;
return NULL ;
}
static int F_70 ( char * V_72 , unsigned int * V_2 ,
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
F_71 ( & V_81 ) ;
V_73 = F_68 ( V_72 ) ;
if ( V_73 == NULL ) {
int V_36 ;
F_72 ( & V_81 ) ;
V_36 = F_73 ( L_20 , V_72 ) ;
F_71 ( & V_81 ) ;
if ( V_36 == 0 )
V_73 = F_68 ( V_72 ) ;
}
if ( V_73 != NULL ) {
* V_76 = V_73 ;
V_77 = 0 ;
}
F_72 ( & V_81 ) ;
}
return V_77 ;
}
static T_3 F_74 ( struct V_1 * V_2 , char * V_66 )
{
T_3 V_36 ;
if ( V_7 && V_7 -> V_78 && V_7 -> V_82 )
V_36 = sprintf ( V_66 , L_21 , V_7 -> V_82 ( V_2 -> V_19 ) ) ;
else
V_36 = sprintf ( V_66 , L_21 , V_2 -> V_55 ) ;
return V_36 ;
}
static T_3 F_75 ( struct V_1 * V_2 ,
char * V_66 )
{
unsigned int V_83 = F_76 ( V_2 ) ;
if ( ! V_83 )
return sprintf ( V_66 , L_22 ) ;
return sprintf ( V_66 , L_21 , V_83 ) ;
}
static T_3 F_77 ( struct V_1 * V_2 , char * V_66 )
{
if ( V_2 -> V_2 == V_80 )
return sprintf ( V_66 , L_23 ) ;
else if ( V_2 -> V_2 == V_79 )
return sprintf ( V_66 , L_24 ) ;
else if ( V_2 -> V_76 )
return F_78 ( V_66 , V_84 , L_25 ,
V_2 -> V_76 -> V_74 ) ;
return - V_70 ;
}
static T_3 F_79 ( struct V_1 * V_2 ,
const char * V_66 , T_4 V_68 )
{
int V_36 ;
char V_72 [ 16 ] ;
struct V_1 V_85 ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_36 = sscanf ( V_66 , L_26 , V_72 ) ;
if ( V_36 != 1 )
return - V_70 ;
if ( F_70 ( V_72 , & V_85 . V_2 ,
& V_85 . V_76 ) )
return - V_70 ;
V_36 = F_80 ( V_2 , & V_85 ) ;
return V_36 ? V_36 : V_68 ;
}
static T_3 F_81 ( struct V_1 * V_2 , char * V_66 )
{
return F_78 ( V_66 , V_84 , L_25 , V_7 -> V_74 ) ;
}
static T_3 F_82 ( struct V_1 * V_2 ,
char * V_66 )
{
T_3 V_86 = 0 ;
struct V_71 * V_73 ;
if ( ! F_11 () ) {
V_86 += sprintf ( V_66 , L_27 ) ;
goto V_87;
}
F_69 (t) {
if ( V_86 >= ( T_3 ) ( ( V_88 / sizeof( char ) )
- ( V_75 + 2 ) ) )
goto V_87;
V_86 += F_78 ( & V_66 [ V_86 ] , V_84 , L_28 , V_73 -> V_74 ) ;
}
V_87:
V_86 += sprintf ( & V_66 [ V_86 ] , L_29 ) ;
return V_86 ;
}
T_3 F_83 ( const struct V_89 * V_90 , char * V_66 )
{
T_3 V_86 = 0 ;
unsigned int V_19 ;
F_55 (cpu, mask) {
if ( V_86 )
V_86 += F_78 ( & V_66 [ V_86 ] , ( V_88 - V_86 - 2 ) , L_30 ) ;
V_86 += F_78 ( & V_66 [ V_86 ] , ( V_88 - V_86 - 2 ) , L_31 , V_19 ) ;
if ( V_86 >= ( V_88 - 5 ) )
break;
}
V_86 += sprintf ( & V_66 [ V_86 ] , L_29 ) ;
return V_86 ;
}
static T_3 F_84 ( struct V_1 * V_2 , char * V_66 )
{
return F_83 ( V_2 -> V_91 , V_66 ) ;
}
static T_3 F_85 ( struct V_1 * V_2 , char * V_66 )
{
return F_83 ( V_2 -> V_3 , V_66 ) ;
}
static T_3 F_86 ( struct V_1 * V_2 ,
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
static T_3 F_87 ( struct V_1 * V_2 , char * V_66 )
{
if ( ! V_2 -> V_76 || ! V_2 -> V_76 -> V_94 )
return sprintf ( V_66 , L_32 ) ;
return V_2 -> V_76 -> V_94 ( V_2 , V_66 ) ;
}
static T_3 F_88 ( struct V_1 * V_2 , char * V_66 )
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
static T_3 F_89 ( struct V_15 * V_16 , struct V_64 * V_65 , char * V_66 )
{
struct V_1 * V_2 = F_90 ( V_16 ) ;
struct V_98 * V_99 = F_91 ( V_65 ) ;
T_3 V_36 ;
F_92 ( & V_2 -> V_100 ) ;
if ( V_99 -> F_89 )
V_36 = V_99 -> F_89 ( V_2 , V_66 ) ;
else
V_36 = - V_101 ;
F_93 ( & V_2 -> V_100 ) ;
return V_36 ;
}
static T_3 F_94 ( struct V_15 * V_16 , struct V_64 * V_65 ,
const char * V_66 , T_4 V_68 )
{
struct V_1 * V_2 = F_90 ( V_16 ) ;
struct V_98 * V_99 = F_91 ( V_65 ) ;
T_3 V_36 = - V_70 ;
F_95 () ;
if ( ! F_96 ( V_2 -> V_19 ) )
goto V_102;
F_97 ( & V_2 -> V_100 ) ;
if ( V_99 -> F_94 )
V_36 = V_99 -> F_94 ( V_2 , V_66 , V_68 ) ;
else
V_36 = - V_101 ;
F_98 ( & V_2 -> V_100 ) ;
V_102:
F_99 () ;
return V_36 ;
}
static void F_100 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_90 ( V_16 ) ;
F_46 ( L_33 ) ;
F_101 ( & V_2 -> V_103 ) ;
}
static int F_102 ( struct V_1 * V_2 , int V_19 )
{
struct V_104 * V_105 ;
F_46 ( L_34 , V_37 , V_19 ) ;
if ( ! V_2 )
return 0 ;
V_105 = F_103 ( V_19 ) ;
if ( F_38 ( ! V_105 ) )
return 0 ;
return F_104 ( & V_105 -> V_16 , & V_2 -> V_16 , L_35 ) ;
}
static void F_105 ( struct V_1 * V_2 , int V_19 )
{
struct V_104 * V_105 ;
F_46 ( L_36 , V_37 , V_19 ) ;
V_105 = F_103 ( V_19 ) ;
if ( F_38 ( ! V_105 ) )
return;
F_106 ( & V_105 -> V_16 , L_35 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
unsigned int V_106 ;
int V_36 = 0 ;
F_55 (j, policy->real_cpus) {
V_36 = F_102 ( V_2 , V_106 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
static void F_108 ( struct V_1 * V_2 )
{
unsigned int V_106 ;
F_55 (j, policy->real_cpus)
F_105 ( V_2 , V_106 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_98 * * V_107 ;
int V_36 = 0 ;
V_107 = V_7 -> V_65 ;
while ( V_107 && * V_107 ) {
V_36 = F_110 ( & V_2 -> V_16 , & ( ( * V_107 ) -> V_65 ) ) ;
if ( V_36 )
return V_36 ;
V_107 ++ ;
}
if ( V_7 -> V_82 ) {
V_36 = F_110 ( & V_2 -> V_16 , & V_108 . V_65 ) ;
if ( V_36 )
return V_36 ;
}
V_36 = F_110 ( & V_2 -> V_16 , & V_109 . V_65 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_96 ) {
V_36 = F_110 ( & V_2 -> V_16 , & V_96 . V_65 ) ;
if ( V_36 )
return V_36 ;
}
return F_107 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_71 * V_110 = NULL ;
struct V_1 V_85 ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_110 = F_68 ( V_2 -> V_111 ) ;
if ( V_110 )
F_46 ( L_37 ,
V_2 -> V_76 -> V_74 , V_2 -> V_19 ) ;
else
V_110 = V_112 ;
V_85 . V_76 = V_110 ;
if ( V_7 -> V_78 ) {
if ( V_2 -> V_113 )
V_85 . V_2 = V_2 -> V_113 ;
else
F_70 ( V_110 -> V_74 , & V_85 . V_2 ,
NULL ) ;
}
return F_80 ( V_2 , & V_85 ) ;
}
static int F_112 ( struct V_1 * V_2 , unsigned int V_19 )
{
int V_36 = 0 ;
if ( F_33 ( V_19 , V_2 -> V_3 ) )
return 0 ;
if ( F_11 () ) {
V_36 = F_113 ( V_2 , V_114 ) ;
if ( V_36 ) {
F_30 ( L_38 , V_37 ) ;
return V_36 ;
}
}
F_97 ( & V_2 -> V_100 ) ;
F_114 ( V_19 , V_2 -> V_3 ) ;
F_98 ( & V_2 -> V_100 ) ;
if ( F_11 () ) {
V_36 = F_113 ( V_2 , V_115 ) ;
if ( ! V_36 )
V_36 = F_113 ( V_2 , V_116 ) ;
if ( V_36 ) {
F_30 ( L_39 , V_37 ) ;
return V_36 ;
}
}
return 0 ;
}
static struct V_1 * F_115 ( unsigned int V_19 )
{
struct V_104 * V_117 = F_103 ( V_19 ) ;
struct V_1 * V_2 ;
if ( F_38 ( ! V_117 ) )
return NULL ;
V_2 = F_116 ( sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return NULL ;
if ( ! F_117 ( & V_2 -> V_3 , V_118 ) )
goto V_119;
if ( ! F_118 ( & V_2 -> V_91 , V_118 ) )
goto V_120;
if ( ! F_118 ( & V_2 -> V_121 , V_118 ) )
goto V_122;
F_119 ( & V_2 -> V_16 , & V_123 ) ;
F_120 ( & V_2 -> V_5 ) ;
F_121 ( & V_2 -> V_100 ) ;
F_122 ( & V_2 -> V_63 ) ;
F_123 ( & V_2 -> V_61 ) ;
F_124 ( & V_2 -> V_103 ) ;
F_125 ( & V_2 -> V_124 , V_125 ) ;
V_2 -> V_19 = V_19 ;
return V_2 ;
V_122:
F_126 ( V_2 -> V_91 ) ;
V_120:
F_126 ( V_2 -> V_3 ) ;
V_119:
F_127 ( V_2 ) ;
return NULL ;
}
static void F_128 ( struct V_1 * V_2 , bool V_126 )
{
struct V_15 * V_16 ;
struct V_127 * V_128 ;
if ( V_126 )
F_129 ( & V_129 ,
V_130 , V_2 ) ;
F_97 ( & V_2 -> V_100 ) ;
F_108 ( V_2 ) ;
V_16 = & V_2 -> V_16 ;
V_128 = & V_2 -> V_103 ;
F_98 ( & V_2 -> V_100 ) ;
F_43 ( V_16 ) ;
F_46 ( L_40 ) ;
F_130 ( V_128 ) ;
F_46 ( L_41 ) ;
}
static void F_131 ( struct V_1 * V_2 , bool V_126 )
{
unsigned long V_13 ;
int V_19 ;
F_132 ( & V_41 , V_13 ) ;
F_133 ( & V_2 -> V_5 ) ;
F_55 (cpu, policy->related_cpus)
F_19 ( V_20 , V_19 ) = NULL ;
F_134 ( & V_41 , V_13 ) ;
F_128 ( V_2 , V_126 ) ;
F_126 ( V_2 -> V_121 ) ;
F_126 ( V_2 -> V_91 ) ;
F_126 ( V_2 -> V_3 ) ;
F_127 ( V_2 ) ;
}
static int F_135 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
bool V_85 ;
unsigned long V_13 ;
unsigned int V_106 ;
int V_36 ;
F_46 ( L_42 , V_37 , V_19 ) ;
V_2 = F_19 ( V_20 , V_19 ) ;
if ( V_2 ) {
F_38 ( ! F_33 ( V_19 , V_2 -> V_91 ) ) ;
if ( ! F_1 ( V_2 ) )
return F_112 ( V_2 , V_19 ) ;
V_85 = false ;
F_97 ( & V_2 -> V_100 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_76 = NULL ;
F_98 ( & V_2 -> V_100 ) ;
} else {
V_85 = true ;
V_2 = F_115 ( V_19 ) ;
if ( ! V_2 )
return - V_131 ;
}
F_136 ( V_2 -> V_3 , F_137 ( V_19 ) ) ;
V_36 = V_7 -> V_132 ( V_2 ) ;
if ( V_36 ) {
F_46 ( L_43 ) ;
goto V_133;
}
F_97 ( & V_2 -> V_100 ) ;
if ( V_85 ) {
F_136 ( V_2 -> V_91 , V_2 -> V_3 ) ;
F_138 ( V_2 -> V_121 , V_2 -> V_3 , V_134 ) ;
V_36 = F_139 ( & V_2 -> V_16 , V_17 ,
L_44 ,
F_140 ( V_2 -> V_91 ) ) ;
if ( V_36 ) {
F_30 ( L_45 , V_37 ,
V_36 ) ;
goto V_135;
}
}
F_138 ( V_2 -> V_3 , V_2 -> V_3 , V_136 ) ;
if ( V_85 ) {
V_2 -> V_137 . V_138 = V_2 -> V_138 ;
V_2 -> V_137 . V_139 = V_2 -> V_139 ;
F_132 ( & V_41 , V_13 ) ;
F_55 (j, policy->related_cpus)
F_19 ( V_20 , V_106 ) = V_2 ;
F_134 ( & V_41 , V_13 ) ;
}
if ( V_7 -> V_82 && ! V_7 -> V_78 ) {
V_2 -> V_55 = V_7 -> V_82 ( V_2 -> V_19 ) ;
if ( ! V_2 -> V_55 ) {
F_30 ( L_46 , V_37 ) ;
goto V_135;
}
}
if ( ( V_7 -> V_13 & V_140 )
&& F_11 () ) {
V_36 = F_141 ( V_2 , V_2 -> V_55 ) ;
if ( V_36 == - V_70 ) {
F_142 ( L_47 ,
V_37 , V_2 -> V_19 , V_2 -> V_55 ) ;
V_36 = F_143 ( V_2 , V_2 -> V_55 - 1 ,
V_141 ) ;
F_49 ( V_36 ) ;
F_142 ( L_48 ,
V_37 , V_2 -> V_19 , V_2 -> V_55 ) ;
}
}
F_129 ( & V_129 ,
V_142 , V_2 ) ;
if ( V_85 ) {
V_36 = F_109 ( V_2 ) ;
if ( V_36 )
goto V_135;
F_129 ( & V_129 ,
V_143 , V_2 ) ;
F_132 ( & V_41 , V_13 ) ;
F_144 ( & V_2 -> V_5 , & V_6 ) ;
F_134 ( & V_41 , V_13 ) ;
}
V_36 = F_111 ( V_2 ) ;
if ( V_36 ) {
F_30 ( L_49 ,
V_37 , V_19 , V_36 ) ;
V_85 = false ;
goto V_135;
}
F_98 ( & V_2 -> V_100 ) ;
F_145 ( & V_2 -> V_16 , V_144 ) ;
if ( V_7 -> V_145 )
V_7 -> V_145 ( V_2 ) ;
F_46 ( L_50 ) ;
return 0 ;
V_135:
F_98 ( & V_2 -> V_100 ) ;
if ( V_7 -> exit )
V_7 -> exit ( V_2 ) ;
V_133:
F_131 ( V_2 , ! V_85 ) ;
return V_36 ;
}
static int F_146 ( struct V_104 * V_117 , struct V_146 * V_147 )
{
unsigned V_19 = V_117 -> V_148 ;
int V_36 ;
F_147 ( V_117 , L_51 , V_37 , V_19 ) ;
if ( F_96 ( V_19 ) ) {
V_36 = F_135 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_19 ( V_20 , V_19 ) ;
V_36 = V_2 && ! F_148 ( V_19 , V_2 -> V_121 )
? F_102 ( V_2 , V_19 ) : 0 ;
}
return V_36 ;
}
static void F_149 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
F_46 ( L_52 , V_37 , V_19 ) ;
V_2 = F_32 ( V_19 ) ;
if ( ! V_2 ) {
F_46 ( L_53 , V_37 ) ;
return;
}
if ( F_11 () ) {
int V_36 = F_113 ( V_2 , V_114 ) ;
if ( V_36 )
F_30 ( L_38 , V_37 ) ;
}
F_97 ( & V_2 -> V_100 ) ;
F_150 ( V_19 , V_2 -> V_3 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_11 () )
strncpy ( V_2 -> V_111 , V_2 -> V_76 -> V_74 ,
V_75 ) ;
else
V_2 -> V_113 = V_2 -> V_2 ;
} else if ( V_19 == V_2 -> V_19 ) {
V_2 -> V_19 = F_151 ( V_2 -> V_3 ) ;
}
F_98 ( & V_2 -> V_100 ) ;
if ( ! F_1 ( V_2 ) ) {
if ( F_11 () ) {
int V_36 = F_113 ( V_2 , V_115 ) ;
if ( ! V_36 )
V_36 = F_113 ( V_2 , V_116 ) ;
if ( V_36 )
F_30 ( L_39 , V_37 ) ;
}
} else if ( V_7 -> V_149 ) {
V_7 -> V_149 ( V_2 ) ;
}
}
static void F_152 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_19 ( V_20 , V_19 ) ;
if ( ! V_2 ) {
F_46 ( L_53 , V_37 ) ;
return;
}
if ( ! F_1 ( V_2 ) )
return;
if ( F_11 () ) {
int V_36 = F_113 ( V_2 , V_150 ) ;
if ( V_36 )
F_30 ( L_54 , V_37 ) ;
}
if ( V_7 -> exit ) {
V_7 -> exit ( V_2 ) ;
V_2 -> V_21 = NULL ;
}
}
static void F_153 ( struct V_104 * V_117 , struct V_146 * V_147 )
{
unsigned int V_19 = V_117 -> V_148 ;
struct V_1 * V_2 = F_19 ( V_20 , V_19 ) ;
if ( ! V_2 )
return;
if ( F_96 ( V_19 ) ) {
F_149 ( V_19 ) ;
F_152 ( V_19 ) ;
}
F_150 ( V_19 , V_2 -> V_121 ) ;
F_105 ( V_2 , V_19 ) ;
if ( F_2 ( V_2 -> V_121 ) )
F_131 ( V_2 , true ) ;
}
static void V_125 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_154 ( V_152 , struct V_1 , V_124 ) ;
unsigned int V_19 = V_2 -> V_19 ;
F_46 ( L_55 , V_19 ) ;
F_155 ( V_19 ) ;
}
static void F_156 ( struct V_1 * V_2 ,
unsigned int V_153 )
{
struct V_43 V_52 ;
F_46 ( L_56 ,
V_2 -> V_55 , V_153 ) ;
V_52 . V_49 = V_2 -> V_55 ;
V_52 . V_51 = V_153 ;
F_58 ( V_2 , & V_52 ) ;
F_63 ( V_2 , & V_52 , 0 ) ;
}
unsigned int F_157 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
unsigned int V_154 = 0 ;
if ( V_7 && V_7 -> V_78 && V_7 -> V_82 )
return V_7 -> V_82 ( V_19 ) ;
V_2 = F_37 ( V_19 ) ;
if ( V_2 ) {
V_154 = V_2 -> V_55 ;
F_42 ( V_2 ) ;
}
return V_154 ;
}
unsigned int F_158 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_37 ( V_19 ) ;
unsigned int V_154 = 0 ;
if ( V_2 ) {
V_154 = V_2 -> V_139 ;
F_42 ( V_2 ) ;
}
return V_154 ;
}
static unsigned int F_76 ( struct V_1 * V_2 )
{
unsigned int V_154 = 0 ;
if ( ! V_7 -> V_82 )
return V_154 ;
V_154 = V_7 -> V_82 ( V_2 -> V_19 ) ;
if ( F_61 ( F_1 ( V_2 ) ) )
return V_154 ;
if ( V_154 && V_2 -> V_55 &&
! ( V_7 -> V_13 & V_47 ) ) {
if ( F_61 ( V_154 != V_2 -> V_55 ) ) {
F_156 ( V_2 , V_154 ) ;
F_159 ( & V_2 -> V_124 ) ;
}
}
return V_154 ;
}
unsigned int F_160 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_37 ( V_19 ) ;
unsigned int V_154 = 0 ;
if ( V_2 ) {
F_92 ( & V_2 -> V_100 ) ;
V_154 = F_76 ( V_2 ) ;
F_93 ( & V_2 -> V_100 ) ;
F_42 ( V_2 ) ;
}
return V_154 ;
}
int F_161 ( struct V_1 * V_2 )
{
int V_36 ;
if ( ! V_2 -> V_155 ) {
F_46 ( L_57 , V_37 ) ;
return 0 ;
}
F_46 ( L_58 , V_37 ,
V_2 -> V_155 ) ;
V_36 = F_143 ( V_2 , V_2 -> V_155 ,
V_156 ) ;
if ( V_36 )
F_30 ( L_59 ,
V_37 , V_2 -> V_155 , V_36 ) ;
return V_36 ;
}
void F_162 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
if ( ! F_11 () )
goto V_157;
F_46 ( L_60 , V_37 ) ;
F_163 (policy) {
if ( F_113 ( V_2 , V_114 ) )
F_30 ( L_61 ,
V_37 , V_2 ) ;
else if ( V_7 -> V_157
&& V_7 -> V_157 ( V_2 ) )
F_30 ( L_62 , V_37 ,
V_2 ) ;
}
V_157:
V_158 = true ;
}
void F_164 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_158 = false ;
if ( ! F_11 () )
return;
F_46 ( L_63 , V_37 ) ;
F_163 (policy) {
if ( V_7 -> V_159 && V_7 -> V_159 ( V_2 ) )
F_30 ( L_64 , V_37 ,
V_2 ) ;
else if ( F_113 ( V_2 , V_115 )
|| F_113 ( V_2 , V_116 ) )
F_30 ( L_65 ,
V_37 , V_2 ) ;
}
V_2 = F_32 ( F_140 ( V_136 ) ) ;
if ( F_38 ( ! V_2 ) )
return;
F_159 ( & V_2 -> V_124 ) ;
}
const char * F_165 ( void )
{
if ( V_7 )
return V_7 -> V_74 ;
return NULL ;
}
void * F_166 ( void )
{
if ( V_7 )
return V_7 -> V_160 ;
return NULL ;
}
int F_167 ( struct V_161 * V_162 , unsigned int V_163 )
{
int V_36 ;
if ( F_14 () )
return - V_70 ;
F_38 ( ! V_11 ) ;
switch ( V_163 ) {
case V_164 :
V_36 = F_168 (
& V_10 , V_162 ) ;
break;
case V_165 :
V_36 = F_169 (
& V_129 , V_162 ) ;
break;
default:
V_36 = - V_70 ;
}
return V_36 ;
}
int F_170 ( struct V_161 * V_162 , unsigned int V_163 )
{
int V_36 ;
if ( F_14 () )
return - V_70 ;
switch ( V_163 ) {
case V_164 :
V_36 = F_171 (
& V_10 , V_162 ) ;
break;
case V_165 :
V_36 = F_172 (
& V_129 , V_162 ) ;
break;
default:
V_36 = - V_70 ;
}
return V_36 ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_43 * V_52 , int V_166 )
{
int V_36 ;
V_52 -> V_51 = V_7 -> V_167 ( V_2 , V_166 ) ;
if ( ! V_52 -> V_51 )
return 0 ;
F_46 ( L_66 ,
V_37 , V_2 -> V_19 , V_52 -> V_49 , V_52 -> V_51 ) ;
F_58 ( V_2 , V_52 ) ;
V_36 = V_7 -> V_168 ( V_2 , V_166 ) ;
F_63 ( V_2 , V_52 , V_36 ) ;
if ( V_36 )
F_30 ( L_67 ,
V_37 , V_36 ) ;
return V_36 ;
}
static int F_174 ( struct V_1 * V_2 ,
struct V_18 * V_21 , int V_166 )
{
struct V_43 V_52 = { . V_49 = V_2 -> V_55 , . V_13 = 0 } ;
unsigned int V_169 = 0 ;
int V_170 = - V_70 ;
bool V_126 ;
V_126 = ! ( V_7 -> V_13 & V_57 ) ;
if ( V_126 ) {
if ( V_7 -> V_167 ) {
V_170 = F_173 ( V_2 , & V_52 , V_166 ) ;
if ( V_170 )
return V_170 ;
V_169 = V_52 . V_51 ;
if ( V_169 )
V_52 . V_49 = V_52 . V_51 ;
}
V_52 . V_51 = V_21 [ V_166 ] . V_171 ;
F_46 ( L_68 ,
V_37 , V_2 -> V_19 , V_52 . V_49 , V_52 . V_51 ) ;
F_58 ( V_2 , & V_52 ) ;
}
V_170 = V_7 -> V_8 ( V_2 , V_166 ) ;
if ( V_170 )
F_30 ( L_69 , V_37 ,
V_170 ) ;
if ( V_126 ) {
F_63 ( V_2 , & V_52 , V_170 ) ;
if ( F_61 ( V_170 && V_169 ) ) {
V_52 . V_49 = V_169 ;
V_52 . V_51 = V_2 -> V_172 ;
F_58 ( V_2 , & V_52 ) ;
F_63 ( V_2 , & V_52 , 0 ) ;
}
}
return V_170 ;
}
int F_143 ( struct V_1 * V_2 ,
unsigned int V_173 ,
unsigned int V_174 )
{
unsigned int V_175 = V_173 ;
int V_170 = - V_70 ;
if ( F_14 () )
return - V_176 ;
if ( V_173 > V_2 -> V_139 )
V_173 = V_2 -> V_139 ;
if ( V_173 < V_2 -> V_138 )
V_173 = V_2 -> V_138 ;
F_46 ( L_70 ,
V_2 -> V_19 , V_173 , V_174 , V_175 ) ;
if ( V_173 == V_2 -> V_55 )
return 0 ;
V_2 -> V_172 = V_2 -> V_55 ;
if ( V_7 -> V_9 )
V_170 = V_7 -> V_9 ( V_2 , V_173 , V_174 ) ;
else if ( V_7 -> V_8 ) {
struct V_18 * V_21 ;
int V_166 ;
V_21 = F_18 ( V_2 -> V_19 ) ;
if ( F_61 ( ! V_21 ) ) {
F_30 ( L_71 , V_37 ) ;
goto V_87;
}
V_170 = F_175 ( V_2 , V_21 ,
V_173 , V_174 , & V_166 ) ;
if ( F_61 ( V_170 ) ) {
F_30 ( L_72 , V_37 ) ;
goto V_87;
}
if ( V_21 [ V_166 ] . V_171 == V_2 -> V_55 ) {
V_170 = 0 ;
goto V_87;
}
V_170 = F_174 ( V_2 , V_21 , V_166 ) ;
}
V_87:
return V_170 ;
}
int F_176 ( struct V_1 * V_2 ,
unsigned int V_173 ,
unsigned int V_174 )
{
int V_36 = - V_70 ;
F_97 ( & V_2 -> V_100 ) ;
V_36 = F_143 ( V_2 , V_173 , V_174 ) ;
F_98 ( & V_2 -> V_100 ) ;
return V_36 ;
}
static int F_113 ( struct V_1 * V_2 ,
unsigned int V_177 )
{
int V_36 ;
#ifdef F_177
struct V_71 * V_110 = & V_178 ;
#else
struct V_71 * V_110 = NULL ;
#endif
if ( V_158 )
return 0 ;
if ( ! V_2 -> V_76 )
return - V_70 ;
if ( V_2 -> V_76 -> V_179 &&
V_2 -> V_38 . V_35 >
V_2 -> V_76 -> V_179 ) {
if ( ! V_110 )
return - V_70 ;
else {
F_142 ( L_73 ,
V_2 -> V_76 -> V_74 , V_110 -> V_74 ) ;
V_2 -> V_76 = V_110 ;
}
}
if ( V_177 == V_180 )
if ( ! F_178 ( V_2 -> V_76 -> V_181 ) )
return - V_70 ;
F_46 ( L_74 , V_37 , V_2 -> V_19 , V_177 ) ;
F_71 ( & V_182 ) ;
if ( ( V_2 -> V_183 && V_177 == V_115 )
|| ( ! V_2 -> V_183
&& ( V_177 == V_116 || V_177 == V_114 ) ) ) {
F_72 ( & V_182 ) ;
return - V_184 ;
}
if ( V_177 == V_114 )
V_2 -> V_183 = false ;
else if ( V_177 == V_115 )
V_2 -> V_183 = true ;
F_72 ( & V_182 ) ;
V_36 = V_2 -> V_76 -> V_76 ( V_2 , V_177 ) ;
if ( ! V_36 ) {
if ( V_177 == V_180 )
V_2 -> V_76 -> V_185 ++ ;
else if ( V_177 == V_150 )
V_2 -> V_76 -> V_185 -- ;
} else {
F_71 ( & V_182 ) ;
if ( V_177 == V_114 )
V_2 -> V_183 = true ;
else if ( V_177 == V_115 )
V_2 -> V_183 = false ;
F_72 ( & V_182 ) ;
}
if ( ( ( V_177 == V_180 ) && V_36 ) ||
( ( V_177 == V_150 ) && ! V_36 ) )
F_179 ( V_2 -> V_76 -> V_181 ) ;
return V_36 ;
}
int F_180 ( struct V_71 * V_76 )
{
int V_77 ;
if ( ! V_76 )
return - V_70 ;
if ( F_14 () )
return - V_176 ;
F_71 ( & V_81 ) ;
V_76 -> V_185 = 0 ;
V_77 = - V_184 ;
if ( ! F_68 ( V_76 -> V_74 ) ) {
V_77 = 0 ;
F_144 ( & V_76 -> V_186 , & V_187 ) ;
}
F_72 ( & V_81 ) ;
return V_77 ;
}
void F_181 ( struct V_71 * V_76 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
if ( ! V_76 )
return;
if ( F_14 () )
return;
F_39 ( & V_41 , V_13 ) ;
F_182 (policy) {
if ( ! strcmp ( V_2 -> V_111 , V_76 -> V_74 ) ) {
V_2 -> V_76 = NULL ;
strcpy ( V_2 -> V_111 , L_75 ) ;
}
}
F_41 ( & V_41 , V_13 ) ;
F_71 ( & V_81 ) ;
F_133 ( & V_76 -> V_186 ) ;
F_72 ( & V_81 ) ;
return;
}
int F_183 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_1 * V_188 ;
if ( ! V_2 )
return - V_70 ;
V_188 = F_37 ( V_19 ) ;
if ( ! V_188 )
return - V_70 ;
memcpy ( V_2 , V_188 , sizeof( * V_2 ) ) ;
F_42 ( V_188 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_1 * V_85 )
{
struct V_71 * V_189 ;
int V_36 ;
F_46 ( L_76 ,
V_85 -> V_19 , V_85 -> V_138 , V_85 -> V_139 ) ;
memcpy ( & V_85 -> V_38 , & V_2 -> V_38 , sizeof( V_2 -> V_38 ) ) ;
if ( V_85 -> V_138 > V_85 -> V_139 )
return - V_70 ;
V_36 = V_7 -> V_190 ( V_85 ) ;
if ( V_36 )
return V_36 ;
F_129 ( & V_129 ,
V_191 , V_85 ) ;
V_36 = V_7 -> V_190 ( V_85 ) ;
if ( V_36 )
return V_36 ;
F_129 ( & V_129 ,
V_192 , V_85 ) ;
V_2 -> V_138 = V_85 -> V_138 ;
V_2 -> V_139 = V_85 -> V_139 ;
F_46 ( L_77 ,
V_2 -> V_138 , V_2 -> V_139 ) ;
if ( V_7 -> V_78 ) {
V_2 -> V_2 = V_85 -> V_2 ;
F_46 ( L_78 ) ;
return V_7 -> V_78 ( V_85 ) ;
}
if ( V_85 -> V_76 == V_2 -> V_76 )
goto V_87;
F_46 ( L_79 ) ;
V_189 = V_2 -> V_76 ;
if ( V_189 ) {
V_36 = F_113 ( V_2 , V_114 ) ;
if ( V_36 ) {
F_46 ( L_80 ,
V_37 , V_189 -> V_74 , V_36 ) ;
return V_36 ;
}
F_98 ( & V_2 -> V_100 ) ;
V_36 = F_113 ( V_2 , V_150 ) ;
F_97 ( & V_2 -> V_100 ) ;
if ( V_36 ) {
F_30 ( L_81 ,
V_37 , V_189 -> V_74 , V_36 ) ;
return V_36 ;
}
}
V_2 -> V_76 = V_85 -> V_76 ;
V_36 = F_113 ( V_2 , V_180 ) ;
if ( ! V_36 ) {
V_36 = F_113 ( V_2 , V_115 ) ;
if ( ! V_36 )
goto V_87;
F_98 ( & V_2 -> V_100 ) ;
F_113 ( V_2 , V_150 ) ;
F_97 ( & V_2 -> V_100 ) ;
}
F_46 ( L_82 , V_2 -> V_76 -> V_74 ) ;
if ( V_189 ) {
V_2 -> V_76 = V_189 ;
if ( F_113 ( V_2 , V_180 ) )
V_2 -> V_76 = NULL ;
else
F_113 ( V_2 , V_115 ) ;
}
return V_36 ;
V_87:
F_46 ( L_83 ) ;
return F_113 ( V_2 , V_116 ) ;
}
int F_155 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_37 ( V_19 ) ;
struct V_1 V_85 ;
int V_36 ;
if ( ! V_2 )
return - V_176 ;
F_97 ( & V_2 -> V_100 ) ;
F_46 ( L_84 , V_19 ) ;
memcpy ( & V_85 , V_2 , sizeof( * V_2 ) ) ;
V_85 . V_138 = V_2 -> V_137 . V_138 ;
V_85 . V_139 = V_2 -> V_137 . V_139 ;
if ( V_7 -> V_82 && ! V_7 -> V_78 ) {
V_85 . V_55 = V_7 -> V_82 ( V_19 ) ;
if ( F_38 ( ! V_85 . V_55 ) ) {
V_36 = - V_101 ;
goto V_102;
}
if ( ! V_2 -> V_55 ) {
F_46 ( L_85 ) ;
V_2 -> V_55 = V_85 . V_55 ;
} else {
if ( V_2 -> V_55 != V_85 . V_55 && F_11 () )
F_156 ( V_2 , V_85 . V_55 ) ;
}
}
V_36 = F_80 ( V_2 , & V_85 ) ;
V_102:
F_98 ( & V_2 -> V_100 ) ;
F_42 ( V_2 ) ;
return V_36 ;
}
static int F_184 ( struct V_161 * V_193 ,
unsigned long V_194 , void * V_195 )
{
unsigned int V_19 = ( unsigned long ) V_195 ;
switch ( V_194 & ~ V_196 ) {
case V_197 :
F_135 ( V_19 ) ;
break;
case V_198 :
F_149 ( V_19 ) ;
break;
case V_199 :
F_152 ( V_19 ) ;
break;
case V_200 :
F_135 ( V_19 ) ;
break;
}
return V_201 ;
}
static int F_185 ( int V_53 )
{
struct V_18 * V_21 ;
struct V_1 * V_2 ;
int V_36 = - V_70 ;
F_163 (policy) {
V_21 = F_18 ( V_2 -> V_19 ) ;
if ( V_21 ) {
V_36 = F_186 ( V_2 ,
V_21 ) ;
if ( V_36 ) {
F_30 ( L_86 ,
V_37 ) ;
break;
}
V_2 -> V_137 . V_139 = V_2 -> V_139 ;
F_113 ( V_2 , V_116 ) ;
}
}
return V_36 ;
}
int F_67 ( int V_53 )
{
unsigned long V_13 ;
int V_36 = 0 ;
if ( V_7 -> V_67 == V_53 )
return 0 ;
F_132 ( & V_41 , V_13 ) ;
V_7 -> V_67 = V_53 ;
F_134 ( & V_41 , V_13 ) ;
V_36 = V_7 -> V_202 ( V_53 ) ;
if ( V_36 ) {
F_132 ( & V_41 , V_13 ) ;
V_7 -> V_67 = ! V_53 ;
F_134 ( & V_41 , V_13 ) ;
F_30 ( L_87 ,
V_37 , V_53 ? L_13 : L_14 ) ;
}
return V_36 ;
}
static bool F_187 ( void )
{
return F_53 ( V_7 ) && V_7 -> V_202 ;
}
static int F_188 ( void )
{
int V_36 ;
V_36 = F_110 ( V_17 , & V_203 . V_65 ) ;
if ( V_36 )
F_30 ( L_88 ,
V_37 ) ;
return V_36 ;
}
static void F_189 ( void )
{
if ( F_187 () )
F_190 ( V_17 , & V_203 . V_65 ) ;
}
int F_191 ( void )
{
if ( ! V_7 )
return - V_70 ;
if ( F_187 () )
return 0 ;
V_7 -> V_202 = F_185 ;
return F_188 () ;
}
int F_192 ( void )
{
return V_7 -> V_67 ;
}
int F_193 ( struct V_7 * V_160 )
{
unsigned long V_13 ;
int V_36 ;
if ( F_14 () )
return - V_176 ;
if ( ! V_160 || ! V_160 -> V_190 || ! V_160 -> V_132 ||
! ( V_160 -> V_78 || V_160 -> V_8 ||
V_160 -> V_9 ) ||
( V_160 -> V_78 && ( V_160 -> V_8 ||
V_160 -> V_9 ) ) ||
( ! ! V_160 -> V_167 != ! ! V_160 -> V_168 ) )
return - V_70 ;
F_46 ( L_89 , V_160 -> V_74 ) ;
F_95 () ;
F_132 ( & V_41 , V_13 ) ;
if ( V_7 ) {
F_134 ( & V_41 , V_13 ) ;
V_36 = - V_204 ;
goto V_87;
}
V_7 = V_160 ;
F_134 ( & V_41 , V_13 ) ;
if ( V_160 -> V_78 )
V_160 -> V_13 |= V_47 ;
if ( F_187 () ) {
V_36 = F_188 () ;
if ( V_36 )
goto V_205;
}
V_36 = F_194 ( & V_206 ) ;
if ( V_36 )
goto V_207;
if ( ! ( V_7 -> V_13 & V_208 ) &&
F_8 ( & V_6 ) ) {
F_46 ( L_90 , V_37 ,
V_160 -> V_74 ) ;
goto V_209;
}
F_195 ( & V_210 ) ;
F_46 ( L_91 , V_160 -> V_74 ) ;
V_87:
F_99 () ;
return V_36 ;
V_209:
F_196 ( & V_206 ) ;
V_207:
F_189 () ;
V_205:
F_132 ( & V_41 , V_13 ) ;
V_7 = NULL ;
F_134 ( & V_41 , V_13 ) ;
goto V_87;
}
int F_197 ( struct V_7 * V_211 )
{
unsigned long V_13 ;
if ( ! V_7 || ( V_211 != V_7 ) )
return - V_70 ;
F_46 ( L_92 , V_211 -> V_74 ) ;
F_95 () ;
F_196 ( & V_206 ) ;
F_189 () ;
F_198 ( & V_210 ) ;
F_132 ( & V_41 , V_13 ) ;
V_7 = NULL ;
F_134 ( & V_41 , V_13 ) ;
F_99 () ;
return 0 ;
}
static int T_1 F_199 ( void )
{
if ( F_14 () )
return - V_176 ;
V_17 = F_200 ( L_35 , & V_212 . V_213 -> V_16 ) ;
F_49 ( ! V_17 ) ;
F_201 ( & V_214 ) ;
return 0 ;
}
