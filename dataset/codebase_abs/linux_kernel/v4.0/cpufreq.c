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
if ( V_14 >= V_36 )
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
F_32 ( & V_11 -> V_12 ) ;
F_30 ( & V_37 ) ;
}
static void F_33 ( unsigned long V_39 , struct V_40 * V_41 )
{
#ifndef F_34
static unsigned long V_42 ;
static unsigned int V_43 ;
if ( V_41 -> V_7 & V_44 )
return;
if ( ! V_43 ) {
V_42 = V_45 ;
V_43 = V_41 -> V_46 ;
F_35 ( L_5 ,
V_42 , V_43 ) ;
}
if ( V_39 == V_47 && V_41 -> V_46 != V_41 -> V_48 ) {
V_45 = F_36 ( V_42 , V_43 ,
V_41 -> V_48 ) ;
F_35 ( L_6 ,
V_45 , V_41 -> V_48 ) ;
}
#endif
}
static void F_37 ( struct V_10 * V_11 ,
struct V_40 * V_49 , unsigned int V_50 )
{
F_38 ( F_39 () ) ;
if ( F_4 () )
return;
V_49 -> V_7 = V_1 -> V_7 ;
F_35 ( L_7 ,
V_50 , V_49 -> V_48 ) ;
switch ( V_50 ) {
case V_51 :
if ( ! ( V_1 -> V_7 & V_44 ) ) {
if ( ( V_11 ) && ( V_11 -> V_14 == V_49 -> V_14 ) &&
( V_11 -> V_52 ) && ( V_11 -> V_52 != V_49 -> V_46 ) ) {
F_35 ( L_8 ,
V_49 -> V_46 , V_11 -> V_52 ) ;
V_49 -> V_46 = V_11 -> V_52 ;
}
}
F_40 ( & V_4 ,
V_51 , V_49 ) ;
F_33 ( V_51 , V_49 ) ;
break;
case V_47 :
F_33 ( V_47 , V_49 ) ;
F_35 ( L_9 ,
( unsigned long ) V_49 -> V_48 , ( unsigned long ) V_49 -> V_14 ) ;
F_41 ( V_49 -> V_48 , V_49 -> V_14 ) ;
F_40 ( & V_4 ,
V_47 , V_49 ) ;
if ( F_42 ( V_11 ) && F_42 ( V_11 -> V_14 == V_49 -> V_14 ) )
V_11 -> V_52 = V_49 -> V_48 ;
break;
}
}
static void F_43 ( struct V_10 * V_11 ,
struct V_40 * V_49 , unsigned int V_50 )
{
F_44 (freqs->cpu, policy->cpus)
F_37 ( V_11 , V_49 , V_50 ) ;
}
static void F_45 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_53 )
{
F_43 ( V_11 , V_49 , V_47 ) ;
if ( ! V_53 )
return;
F_46 ( V_49 -> V_46 , V_49 -> V_48 ) ;
F_43 ( V_11 , V_49 , V_51 ) ;
F_43 ( V_11 , V_49 , V_47 ) ;
}
void F_47 ( struct V_10 * V_11 ,
struct V_40 * V_49 )
{
F_48 ( ! ( V_1 -> V_7 & V_54 )
&& V_55 == V_11 -> V_56 ) ;
V_57:
F_49 ( V_11 -> V_58 , ! V_11 -> V_59 ) ;
F_50 ( & V_11 -> V_60 ) ;
if ( F_51 ( V_11 -> V_59 ) ) {
F_52 ( & V_11 -> V_60 ) ;
goto V_57;
}
V_11 -> V_59 = true ;
V_11 -> V_56 = V_55 ;
F_52 ( & V_11 -> V_60 ) ;
F_43 ( V_11 , V_49 , V_51 ) ;
}
void F_53 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_53 )
{
if ( F_51 ( F_48 ( ! V_11 -> V_59 ) ) )
return;
F_45 ( V_11 , V_49 , V_53 ) ;
V_11 -> V_59 = false ;
V_11 -> V_56 = NULL ;
F_54 ( & V_11 -> V_58 ) ;
}
static T_3 F_55 ( struct V_9 * V_12 ,
struct V_61 * V_62 , char * V_63 )
{
return sprintf ( V_63 , L_10 , V_1 -> V_64 ) ;
}
static T_3 F_56 ( struct V_9 * V_12 , struct V_61 * V_62 ,
const char * V_63 , T_4 V_65 )
{
int V_30 , V_66 ;
V_30 = sscanf ( V_63 , L_11 , & V_66 ) ;
if ( V_30 != 1 || V_66 < 0 || V_66 > 1 )
return - V_67 ;
if ( F_57 ( V_66 ) ) {
F_18 ( L_12 ,
V_31 , V_66 ? L_13 : L_14 ) ;
return - V_67 ;
}
F_35 ( L_15 ,
V_31 , V_66 ? L_16 : L_17 ) ;
return V_65 ;
}
static struct V_68 * F_58 ( const char * V_69 )
{
struct V_68 * V_70 ;
F_59 (t)
if ( ! strncasecmp ( V_69 , V_70 -> V_71 , V_72 ) )
return V_70 ;
return NULL ;
}
static int F_60 ( char * V_69 , unsigned int * V_11 ,
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
} else {
struct V_68 * V_70 ;
F_61 ( & V_79 ) ;
V_70 = F_58 ( V_69 ) ;
if ( V_70 == NULL ) {
int V_30 ;
F_62 ( & V_79 ) ;
V_30 = F_63 ( L_20 , V_69 ) ;
F_61 ( & V_79 ) ;
if ( V_30 == 0 )
V_70 = F_58 ( V_69 ) ;
}
if ( V_70 != NULL ) {
* V_73 = V_70 ;
V_74 = 0 ;
}
F_62 ( & V_79 ) ;
}
V_75:
return V_74 ;
}
static T_3 F_64 ( struct V_10 * V_11 , char * V_63 )
{
T_3 V_30 ;
if ( V_1 && V_1 -> V_76 && V_1 -> V_80 )
V_30 = sprintf ( V_63 , L_21 , V_1 -> V_80 ( V_11 -> V_14 ) ) ;
else
V_30 = sprintf ( V_63 , L_21 , V_11 -> V_52 ) ;
return V_30 ;
}
static T_3 F_65 ( struct V_10 * V_11 ,
char * V_63 )
{
unsigned int V_81 = F_66 ( V_11 ) ;
if ( ! V_81 )
return sprintf ( V_63 , L_22 ) ;
return sprintf ( V_63 , L_21 , V_81 ) ;
}
static T_3 F_67 ( struct V_10 * V_11 , char * V_63 )
{
if ( V_11 -> V_11 == V_78 )
return sprintf ( V_63 , L_23 ) ;
else if ( V_11 -> V_11 == V_77 )
return sprintf ( V_63 , L_24 ) ;
else if ( V_11 -> V_73 )
return F_68 ( V_63 , V_82 , L_25 ,
V_11 -> V_73 -> V_71 ) ;
return - V_67 ;
}
static T_3 F_69 ( struct V_10 * V_11 ,
const char * V_63 , T_4 V_65 )
{
int V_30 ;
char V_69 [ 16 ] ;
struct V_10 V_83 ;
V_30 = F_70 ( & V_83 , V_11 -> V_14 ) ;
if ( V_30 )
return V_30 ;
V_30 = sscanf ( V_63 , L_26 , V_69 ) ;
if ( V_30 != 1 )
return - V_67 ;
if ( F_60 ( V_69 , & V_83 . V_11 ,
& V_83 . V_73 ) )
return - V_67 ;
V_30 = F_71 ( V_11 , & V_83 ) ;
V_11 -> V_84 . V_11 = V_11 -> V_11 ;
V_11 -> V_84 . V_73 = V_11 -> V_73 ;
if ( V_30 )
return V_30 ;
else
return V_65 ;
}
static T_3 F_72 ( struct V_10 * V_11 , char * V_63 )
{
return F_68 ( V_63 , V_82 , L_25 , V_1 -> V_71 ) ;
}
static T_3 F_73 ( struct V_10 * V_11 ,
char * V_63 )
{
T_3 V_85 = 0 ;
struct V_68 * V_70 ;
if ( ! F_1 () ) {
V_85 += sprintf ( V_63 , L_27 ) ;
goto V_75;
}
F_59 (t) {
if ( V_85 >= ( T_3 ) ( ( V_86 / sizeof( char ) )
- ( V_72 + 2 ) ) )
goto V_75;
V_85 += F_68 ( & V_63 [ V_85 ] , V_82 , L_28 , V_70 -> V_71 ) ;
}
V_75:
V_85 += sprintf ( & V_63 [ V_85 ] , L_29 ) ;
return V_85 ;
}
T_3 F_74 ( const struct V_87 * V_88 , char * V_63 )
{
T_3 V_85 = 0 ;
unsigned int V_14 ;
F_44 (cpu, mask) {
if ( V_85 )
V_85 += F_68 ( & V_63 [ V_85 ] , ( V_86 - V_85 - 2 ) , L_30 ) ;
V_85 += F_68 ( & V_63 [ V_85 ] , ( V_86 - V_85 - 2 ) , L_31 , V_14 ) ;
if ( V_85 >= ( V_86 - 5 ) )
break;
}
V_85 += sprintf ( & V_63 [ V_85 ] , L_29 ) ;
return V_85 ;
}
static T_3 F_75 ( struct V_10 * V_11 , char * V_63 )
{
return F_74 ( V_11 -> V_89 , V_63 ) ;
}
static T_3 F_76 ( struct V_10 * V_11 , char * V_63 )
{
return F_74 ( V_11 -> V_33 , V_63 ) ;
}
static T_3 F_77 ( struct V_10 * V_11 ,
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
static T_3 F_78 ( struct V_10 * V_11 , char * V_63 )
{
if ( ! V_11 -> V_73 || ! V_11 -> V_73 -> V_92 )
return sprintf ( V_63 , L_32 ) ;
return V_11 -> V_73 -> V_92 ( V_11 , V_63 ) ;
}
static T_3 F_79 ( struct V_10 * V_11 , char * V_63 )
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
static T_3 F_80 ( struct V_9 * V_12 , struct V_61 * V_62 , char * V_63 )
{
struct V_10 * V_11 = F_81 ( V_12 ) ;
struct V_96 * V_97 = F_82 ( V_62 ) ;
T_3 V_30 ;
if ( ! F_26 ( & V_37 ) )
return - V_67 ;
F_83 ( & V_11 -> V_98 ) ;
if ( V_97 -> F_80 )
V_30 = V_97 -> F_80 ( V_11 , V_63 ) ;
else
V_30 = - V_99 ;
F_30 ( & V_11 -> V_98 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
static T_3 F_84 ( struct V_9 * V_12 , struct V_61 * V_62 ,
const char * V_63 , T_4 V_65 )
{
struct V_10 * V_11 = F_81 ( V_12 ) ;
struct V_96 * V_97 = F_82 ( V_62 ) ;
T_3 V_30 = - V_67 ;
F_85 () ;
if ( ! F_86 ( V_11 -> V_14 ) )
goto V_100;
if ( ! F_26 ( & V_37 ) )
goto V_100;
F_87 ( & V_11 -> V_98 ) ;
if ( V_97 -> F_84 )
V_30 = V_97 -> F_84 ( V_11 , V_63 , V_65 ) ;
else
V_30 = - V_99 ;
F_88 ( & V_11 -> V_98 ) ;
F_30 ( & V_37 ) ;
V_100:
F_89 () ;
return V_30 ;
}
static void F_90 ( struct V_9 * V_12 )
{
struct V_10 * V_11 = F_81 ( V_12 ) ;
F_35 ( L_33 ) ;
F_91 ( & V_11 -> V_101 ) ;
}
int F_92 ( void )
{
if ( ! V_102 ++ )
return F_93 ( V_13 ,
& V_103 . V_104 -> V_12 , L_34 , L_35 ) ;
return 0 ;
}
void F_94 ( void )
{
if ( ! -- V_102 )
F_95 ( V_13 ) ;
}
int F_96 ( const struct V_61 * V_62 )
{
int V_30 = F_92 () ;
if ( ! V_30 ) {
V_30 = F_97 ( V_13 , V_62 ) ;
if ( V_30 )
F_94 () ;
}
return V_30 ;
}
void F_98 ( const struct V_61 * V_62 )
{
F_99 ( V_13 , V_62 ) ;
F_94 () ;
}
static int F_100 ( struct V_10 * V_11 )
{
unsigned int V_105 ;
int V_30 = 0 ;
F_44 (j, policy->cpus) {
struct V_106 * V_107 ;
if ( V_105 == V_11 -> V_14 )
continue;
F_35 ( L_36 , V_105 ) ;
V_107 = F_101 ( V_105 ) ;
V_30 = F_102 ( & V_107 -> V_12 , & V_11 -> V_12 ,
L_35 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
static int F_103 ( struct V_10 * V_11 ,
struct V_106 * V_108 )
{
struct V_96 * * V_109 ;
int V_30 = 0 ;
V_109 = V_1 -> V_62 ;
while ( V_109 && * V_109 ) {
V_30 = F_97 ( & V_11 -> V_12 , & ( ( * V_109 ) -> V_62 ) ) ;
if ( V_30 )
return V_30 ;
V_109 ++ ;
}
if ( V_1 -> V_80 ) {
V_30 = F_97 ( & V_11 -> V_12 , & V_110 . V_62 ) ;
if ( V_30 )
return V_30 ;
}
V_30 = F_97 ( & V_11 -> V_12 , & V_111 . V_62 ) ;
if ( V_30 )
return V_30 ;
if ( V_1 -> V_94 ) {
V_30 = F_97 ( & V_11 -> V_12 , & V_94 . V_62 ) ;
if ( V_30 )
return V_30 ;
}
return F_100 ( V_11 ) ;
}
static void F_104 ( struct V_10 * V_11 )
{
struct V_68 * V_112 = NULL ;
struct V_10 V_83 ;
int V_30 = 0 ;
memcpy ( & V_83 , V_11 , sizeof( * V_11 ) ) ;
V_112 = F_58 ( F_21 ( V_113 , V_11 -> V_14 ) ) ;
if ( V_112 )
F_35 ( L_37 ,
V_11 -> V_73 -> V_71 , V_11 -> V_14 ) ;
else
V_112 = V_114 ;
V_83 . V_73 = V_112 ;
if ( V_1 -> V_76 )
F_60 ( V_112 -> V_71 , & V_83 . V_11 , NULL ) ;
V_30 = F_71 ( V_11 , & V_83 ) ;
if ( V_30 ) {
F_35 ( L_38 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
}
}
static int F_105 ( struct V_10 * V_11 ,
unsigned int V_14 , struct V_106 * V_108 )
{
int V_30 = 0 ;
unsigned long V_7 ;
if ( F_1 () ) {
V_30 = F_106 ( V_11 , V_115 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
}
F_87 ( & V_11 -> V_98 ) ;
F_107 ( & V_38 , V_7 ) ;
F_108 ( V_14 , V_11 -> V_33 ) ;
F_21 ( V_34 , V_14 ) = V_11 ;
F_109 ( & V_38 , V_7 ) ;
F_88 ( & V_11 -> V_98 ) ;
if ( F_1 () ) {
V_30 = F_106 ( V_11 , V_116 ) ;
if ( ! V_30 )
V_30 = F_106 ( V_11 , V_117 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
return F_102 ( & V_108 -> V_12 , & V_11 -> V_12 , L_35 ) ;
}
static struct V_10 * F_110 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_7 ;
F_27 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_118 , V_14 ) ;
F_29 ( & V_38 , V_7 ) ;
if ( V_11 )
V_11 -> V_73 = NULL ;
return V_11 ;
}
static struct V_10 * F_111 ( void )
{
struct V_10 * V_11 ;
V_11 = F_112 ( sizeof( * V_11 ) , V_119 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_113 ( & V_11 -> V_33 , V_119 ) )
goto V_120;
if ( ! F_114 ( & V_11 -> V_89 , V_119 ) )
goto V_121;
F_115 ( & V_11 -> V_122 ) ;
F_116 ( & V_11 -> V_98 ) ;
F_117 ( & V_11 -> V_60 ) ;
F_118 ( & V_11 -> V_58 ) ;
F_119 ( & V_11 -> V_101 ) ;
F_120 ( & V_11 -> V_123 , V_124 ) ;
return V_11 ;
V_121:
F_121 ( V_11 -> V_33 ) ;
V_120:
F_122 ( V_11 ) ;
return NULL ;
}
static void F_123 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
struct V_125 * V_126 ;
F_124 ( & V_127 ,
V_128 , V_11 ) ;
F_83 ( & V_11 -> V_98 ) ;
V_12 = & V_11 -> V_12 ;
V_126 = & V_11 -> V_101 ;
F_30 ( & V_11 -> V_98 ) ;
F_32 ( V_12 ) ;
F_35 ( L_41 ) ;
F_125 ( V_126 ) ;
F_35 ( L_42 ) ;
}
static void F_126 ( struct V_10 * V_11 )
{
F_121 ( V_11 -> V_89 ) ;
F_121 ( V_11 -> V_33 ) ;
F_122 ( V_11 ) ;
}
static int F_127 ( struct V_10 * V_11 , unsigned int V_14 ,
struct V_106 * V_107 )
{
int V_30 ;
if ( F_48 ( V_14 == V_11 -> V_14 ) )
return 0 ;
V_30 = F_128 ( & V_11 -> V_12 , & V_107 -> V_12 ) ;
if ( V_30 ) {
F_18 ( L_43 , V_31 , V_30 ) ;
return V_30 ;
}
F_87 ( & V_11 -> V_98 ) ;
V_11 -> V_14 = V_14 ;
F_88 ( & V_11 -> V_98 ) ;
return 0 ;
}
static int F_129 ( struct V_106 * V_108 , struct V_129 * V_130 )
{
unsigned int V_105 , V_14 = V_108 -> V_131 ;
int V_30 = - V_132 ;
struct V_10 * V_11 ;
unsigned long V_7 ;
bool V_133 = V_134 ;
if ( F_130 ( V_14 ) )
return 0 ;
F_35 ( L_44 , V_14 ) ;
V_11 = F_24 ( V_14 ) ;
if ( F_51 ( V_11 ) )
return 0 ;
if ( ! F_26 ( & V_37 ) )
return 0 ;
F_27 ( & V_38 , V_7 ) ;
F_131 (policy) {
if ( F_132 ( V_14 , V_11 -> V_89 ) ) {
F_29 ( & V_38 , V_7 ) ;
V_30 = F_105 ( V_11 , V_14 , V_108 ) ;
F_30 ( & V_37 ) ;
return V_30 ;
}
}
F_29 ( & V_38 , V_7 ) ;
V_11 = V_133 ? F_110 ( V_14 ) : NULL ;
if ( ! V_11 ) {
V_133 = false ;
V_11 = F_111 () ;
if ( ! V_11 )
goto V_135;
}
if ( V_133 && V_14 != V_11 -> V_14 )
F_48 ( F_127 ( V_11 , V_14 , V_108 ) ) ;
else
V_11 -> V_14 = V_14 ;
F_133 ( V_11 -> V_33 , F_134 ( V_14 ) ) ;
V_30 = V_1 -> V_136 ( V_11 ) ;
if ( V_30 ) {
F_35 ( L_45 ) ;
goto V_137;
}
F_87 ( & V_11 -> V_98 ) ;
F_135 ( V_11 -> V_89 , V_11 -> V_89 , V_11 -> V_33 ) ;
F_136 ( V_11 -> V_33 , V_11 -> V_33 , V_138 ) ;
if ( ! V_133 ) {
V_11 -> V_84 . V_139 = V_11 -> V_139 ;
V_11 -> V_84 . V_140 = V_11 -> V_140 ;
V_30 = F_137 ( & V_11 -> V_12 , & V_141 ,
& V_108 -> V_12 , L_35 ) ;
if ( V_30 ) {
F_18 ( L_46 ,
V_31 , V_30 ) ;
goto V_142;
}
}
F_107 ( & V_38 , V_7 ) ;
F_44 (j, policy->cpus)
F_21 ( V_34 , V_105 ) = V_11 ;
F_109 ( & V_38 , V_7 ) ;
if ( V_1 -> V_80 && ! V_1 -> V_76 ) {
V_11 -> V_52 = V_1 -> V_80 ( V_11 -> V_14 ) ;
if ( ! V_11 -> V_52 ) {
F_18 ( L_47 , V_31 ) ;
goto V_143;
}
}
if ( ( V_1 -> V_7 & V_144 )
&& F_1 () ) {
V_30 = F_138 ( V_11 , V_11 -> V_52 ) ;
if ( V_30 == - V_67 ) {
F_139 ( L_48 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
V_30 = F_140 ( V_11 , V_11 -> V_52 - 1 ,
V_145 ) ;
F_38 ( V_30 ) ;
F_139 ( L_49 ,
V_31 , V_11 -> V_14 , V_11 -> V_52 ) ;
}
}
F_124 ( & V_127 ,
V_146 , V_11 ) ;
if ( ! V_133 ) {
V_30 = F_103 ( V_11 , V_108 ) ;
if ( V_30 )
goto V_147;
F_124 ( & V_127 ,
V_148 , V_11 ) ;
}
F_107 ( & V_38 , V_7 ) ;
F_141 ( & V_11 -> V_122 , & V_149 ) ;
F_109 ( & V_38 , V_7 ) ;
F_104 ( V_11 ) ;
if ( ! V_133 ) {
V_11 -> V_84 . V_11 = V_11 -> V_11 ;
V_11 -> V_84 . V_73 = V_11 -> V_73 ;
}
F_88 ( & V_11 -> V_98 ) ;
F_142 ( & V_11 -> V_12 , V_150 ) ;
F_30 ( & V_37 ) ;
if ( V_1 -> V_151 )
V_1 -> V_151 ( V_11 ) ;
F_35 ( L_50 ) ;
return 0 ;
V_147:
V_143:
F_107 ( & V_38 , V_7 ) ;
F_44 (j, policy->cpus)
F_21 ( V_34 , V_105 ) = NULL ;
F_109 ( & V_38 , V_7 ) ;
if ( ! V_133 ) {
F_32 ( & V_11 -> V_12 ) ;
F_125 ( & V_11 -> V_101 ) ;
}
V_142:
F_88 ( & V_11 -> V_98 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
V_137:
if ( V_133 ) {
F_21 ( V_118 , V_14 ) = NULL ;
F_123 ( V_11 ) ;
}
F_126 ( V_11 ) ;
V_135:
F_30 ( & V_37 ) ;
return V_30 ;
}
static int F_143 ( struct V_106 * V_108 , struct V_129 * V_130 )
{
return F_129 ( V_108 , V_130 ) ;
}
static int F_144 ( struct V_106 * V_108 ,
struct V_129 * V_130 )
{
unsigned int V_14 = V_108 -> V_131 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_35 ( L_51 , V_31 , V_14 ) ;
F_107 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
if ( V_134 )
F_21 ( V_118 , V_14 ) = V_11 ;
F_109 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_35 ( L_52 , V_31 ) ;
return - V_67 ;
}
if ( F_1 () ) {
V_30 = F_106 ( V_11 , V_115 ) ;
if ( V_30 ) {
F_18 ( L_39 , V_31 ) ;
return V_30 ;
}
strncpy ( F_21 ( V_113 , V_14 ) ,
V_11 -> V_73 -> V_71 , V_72 ) ;
}
F_83 ( & V_11 -> V_98 ) ;
V_33 = F_145 ( V_11 -> V_33 ) ;
F_30 ( & V_11 -> V_98 ) ;
if ( V_14 != V_11 -> V_14 ) {
F_146 ( & V_108 -> V_12 , L_35 ) ;
} else if ( V_33 > 1 ) {
int V_152 = F_147 ( V_11 -> V_33 , V_14 ) ;
struct V_106 * V_107 = F_101 ( V_152 ) ;
F_146 ( & V_107 -> V_12 , L_35 ) ;
V_30 = F_127 ( V_11 , V_152 , V_107 ) ;
if ( V_30 ) {
if ( F_102 ( & V_107 -> V_12 , & V_11 -> V_12 ,
L_35 ) )
F_18 ( L_53 ,
V_31 , V_107 -> V_131 ) ;
return V_30 ;
}
if ( ! V_134 )
F_35 ( L_54 ,
V_31 , V_152 , V_14 ) ;
} else if ( V_1 -> V_153 ) {
V_1 -> V_153 ( V_11 ) ;
}
return 0 ;
}
static int F_148 ( struct V_106 * V_108 ,
struct V_129 * V_130 )
{
unsigned int V_14 = V_108 -> V_131 , V_33 ;
int V_30 ;
unsigned long V_7 ;
struct V_10 * V_11 ;
F_107 ( & V_38 , V_7 ) ;
V_11 = F_21 ( V_34 , V_14 ) ;
F_21 ( V_34 , V_14 ) = NULL ;
F_109 ( & V_38 , V_7 ) ;
if ( ! V_11 ) {
F_35 ( L_52 , V_31 ) ;
return - V_67 ;
}
F_87 ( & V_11 -> V_98 ) ;
V_33 = F_145 ( V_11 -> V_33 ) ;
if ( V_33 > 1 )
F_149 ( V_14 , V_11 -> V_33 ) ;
F_88 ( & V_11 -> V_98 ) ;
if ( V_33 == 1 ) {
if ( F_1 () ) {
V_30 = F_106 ( V_11 ,
V_154 ) ;
if ( V_30 ) {
F_18 ( L_55 ,
V_31 ) ;
return V_30 ;
}
}
if ( ! V_134 )
F_123 ( V_11 ) ;
if ( V_1 -> exit )
V_1 -> exit ( V_11 ) ;
F_107 ( & V_38 , V_7 ) ;
F_150 ( & V_11 -> V_122 ) ;
F_109 ( & V_38 , V_7 ) ;
if ( ! V_134 )
F_126 ( V_11 ) ;
} else if ( F_1 () ) {
V_30 = F_106 ( V_11 , V_116 ) ;
if ( ! V_30 )
V_30 = F_106 ( V_11 , V_117 ) ;
if ( V_30 ) {
F_18 ( L_40 , V_31 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_151 ( struct V_106 * V_108 , struct V_129 * V_130 )
{
unsigned int V_14 = V_108 -> V_131 ;
int V_30 ;
if ( F_130 ( V_14 ) )
return 0 ;
V_30 = F_144 ( V_108 , V_130 ) ;
if ( ! V_30 )
V_30 = F_148 ( V_108 , V_130 ) ;
return V_30 ;
}
static void V_124 ( struct V_155 * V_156 )
{
struct V_10 * V_11 =
F_152 ( V_156 , struct V_10 , V_123 ) ;
unsigned int V_14 = V_11 -> V_14 ;
F_35 ( L_56 , V_14 ) ;
F_153 ( V_14 ) ;
}
static void F_154 ( struct V_10 * V_11 ,
unsigned int V_157 )
{
struct V_40 V_49 ;
F_35 ( L_57 ,
V_11 -> V_52 , V_157 ) ;
V_49 . V_46 = V_11 -> V_52 ;
V_49 . V_48 = V_157 ;
F_47 ( V_11 , & V_49 ) ;
F_53 ( V_11 , & V_49 , 0 ) ;
}
unsigned int F_155 ( unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned int V_158 = 0 ;
if ( V_1 && V_1 -> V_76 && V_1 -> V_80 )
return V_1 -> V_80 ( V_14 ) ;
V_11 = F_25 ( V_14 ) ;
if ( V_11 ) {
V_158 = V_11 -> V_52 ;
F_31 ( V_11 ) ;
}
return V_158 ;
}
unsigned int F_156 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_158 = 0 ;
if ( V_11 ) {
V_158 = V_11 -> V_140 ;
F_31 ( V_11 ) ;
}
return V_158 ;
}
static unsigned int F_66 ( struct V_10 * V_11 )
{
unsigned int V_158 = 0 ;
if ( ! V_1 -> V_80 )
return V_158 ;
V_158 = V_1 -> V_80 ( V_11 -> V_14 ) ;
if ( V_158 && V_11 -> V_52 &&
! ( V_1 -> V_7 & V_44 ) ) {
if ( F_51 ( V_158 != V_11 -> V_52 ) ) {
F_154 ( V_11 , V_158 ) ;
F_157 ( & V_11 -> V_123 ) ;
}
}
return V_158 ;
}
unsigned int F_158 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
unsigned int V_158 = 0 ;
if ( V_11 ) {
F_83 ( & V_11 -> V_98 ) ;
V_158 = F_66 ( V_11 ) ;
F_30 ( & V_11 -> V_98 ) ;
F_31 ( V_11 ) ;
}
return V_158 ;
}
int F_159 ( struct V_10 * V_11 )
{
int V_30 ;
if ( ! V_11 -> V_159 ) {
F_18 ( L_58 , V_31 ) ;
return - V_67 ;
}
F_35 ( L_59 , V_31 ,
V_11 -> V_159 ) ;
V_30 = F_140 ( V_11 , V_11 -> V_159 ,
V_160 ) ;
if ( V_30 )
F_18 ( L_60 ,
V_31 , V_11 -> V_159 , V_30 ) ;
return V_30 ;
}
void F_160 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
if ( ! F_1 () )
goto V_161;
F_35 ( L_61 , V_31 ) ;
F_131 (policy) {
if ( F_106 ( V_11 , V_115 ) )
F_18 ( L_62 ,
V_31 , V_11 ) ;
else if ( V_1 -> V_161
&& V_1 -> V_161 ( V_11 ) )
F_18 ( L_63 , V_31 ,
V_11 ) ;
}
V_161:
V_134 = true ;
}
void F_161 ( void )
{
struct V_10 * V_11 ;
if ( ! V_1 )
return;
V_134 = false ;
if ( ! F_1 () )
return;
F_35 ( L_64 , V_31 ) ;
F_131 (policy) {
if ( V_1 -> V_162 && V_1 -> V_162 ( V_11 ) )
F_18 ( L_65 , V_31 ,
V_11 ) ;
else if ( F_106 ( V_11 , V_116 )
|| F_106 ( V_11 , V_117 ) )
F_18 ( L_66 ,
V_31 , V_11 ) ;
}
V_11 = F_24 ( F_162 ( V_138 ) ) ;
if ( F_48 ( ! V_11 ) )
return;
F_157 ( & V_11 -> V_123 ) ;
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
return V_1 -> V_163 ;
return NULL ;
}
int F_165 ( struct V_164 * V_165 , unsigned int V_166 )
{
int V_30 ;
if ( F_4 () )
return - V_67 ;
F_48 ( ! V_5 ) ;
switch ( V_166 ) {
case V_167 :
V_30 = F_166 (
& V_4 , V_165 ) ;
break;
case V_168 :
V_30 = F_167 (
& V_127 , V_165 ) ;
break;
default:
V_30 = - V_67 ;
}
return V_30 ;
}
int F_168 ( struct V_164 * V_165 , unsigned int V_166 )
{
int V_30 ;
if ( F_4 () )
return - V_67 ;
switch ( V_166 ) {
case V_167 :
V_30 = F_169 (
& V_4 , V_165 ) ;
break;
case V_168 :
V_30 = F_170 (
& V_127 , V_165 ) ;
break;
default:
V_30 = - V_67 ;
}
return V_30 ;
}
static int F_171 ( struct V_10 * V_11 ,
struct V_40 * V_49 , int V_169 )
{
int V_30 ;
V_49 -> V_48 = V_1 -> V_170 ( V_11 , V_169 ) ;
if ( ! V_49 -> V_48 )
return 0 ;
F_35 ( L_67 ,
V_31 , V_11 -> V_14 , V_49 -> V_46 , V_49 -> V_48 ) ;
F_47 ( V_11 , V_49 ) ;
V_30 = V_1 -> V_171 ( V_11 , V_169 ) ;
F_53 ( V_11 , V_49 , V_30 ) ;
if ( V_30 )
F_18 ( L_68 ,
V_31 , V_30 ) ;
return V_30 ;
}
static int F_172 ( struct V_10 * V_11 ,
struct V_27 * V_172 , int V_169 )
{
struct V_40 V_49 = { . V_46 = V_11 -> V_52 , . V_7 = 0 } ;
unsigned int V_173 = 0 ;
int V_174 = - V_67 ;
bool V_175 ;
V_175 = ! ( V_1 -> V_7 & V_54 ) ;
if ( V_175 ) {
if ( V_1 -> V_170 ) {
V_174 = F_171 ( V_11 , & V_49 , V_169 ) ;
if ( V_174 )
return V_174 ;
V_173 = V_49 . V_48 ;
if ( V_173 )
V_49 . V_46 = V_49 . V_48 ;
}
V_49 . V_48 = V_172 [ V_169 ] . V_176 ;
F_35 ( L_69 ,
V_31 , V_11 -> V_14 , V_49 . V_46 , V_49 . V_48 ) ;
F_47 ( V_11 , & V_49 ) ;
}
V_174 = V_1 -> V_2 ( V_11 , V_169 ) ;
if ( V_174 )
F_18 ( L_70 , V_31 ,
V_174 ) ;
if ( V_175 ) {
F_53 ( V_11 , & V_49 , V_174 ) ;
if ( F_51 ( V_174 && V_173 ) ) {
V_49 . V_46 = V_173 ;
V_49 . V_48 = V_11 -> V_177 ;
F_47 ( V_11 , & V_49 ) ;
F_53 ( V_11 , & V_49 , 0 ) ;
}
}
return V_174 ;
}
int F_140 ( struct V_10 * V_11 ,
unsigned int V_178 ,
unsigned int V_179 )
{
unsigned int V_180 = V_178 ;
int V_174 = - V_67 ;
if ( F_4 () )
return - V_181 ;
if ( V_178 > V_11 -> V_140 )
V_178 = V_11 -> V_140 ;
if ( V_178 < V_11 -> V_139 )
V_178 = V_11 -> V_139 ;
F_35 ( L_71 ,
V_11 -> V_14 , V_178 , V_179 , V_180 ) ;
if ( V_178 == V_11 -> V_52 )
return 0 ;
V_11 -> V_177 = V_11 -> V_52 ;
if ( V_1 -> V_3 )
V_174 = V_1 -> V_3 ( V_11 , V_178 , V_179 ) ;
else if ( V_1 -> V_2 ) {
struct V_27 * V_172 ;
int V_169 ;
V_172 = F_173 ( V_11 -> V_14 ) ;
if ( F_51 ( ! V_172 ) ) {
F_18 ( L_72 , V_31 ) ;
goto V_75;
}
V_174 = F_174 ( V_11 , V_172 ,
V_178 , V_179 , & V_169 ) ;
if ( F_51 ( V_174 ) ) {
F_18 ( L_73 , V_31 ) ;
goto V_75;
}
if ( V_172 [ V_169 ] . V_176 == V_11 -> V_52 ) {
V_174 = 0 ;
goto V_75;
}
V_174 = F_172 ( V_11 , V_172 , V_169 ) ;
}
V_75:
return V_174 ;
}
int F_175 ( struct V_10 * V_11 ,
unsigned int V_178 ,
unsigned int V_179 )
{
int V_30 = - V_67 ;
F_87 ( & V_11 -> V_98 ) ;
V_30 = F_140 ( V_11 , V_178 , V_179 ) ;
F_88 ( & V_11 -> V_98 ) ;
return V_30 ;
}
static int F_106 ( struct V_10 * V_11 ,
unsigned int V_182 )
{
int V_30 ;
#ifdef F_176
struct V_68 * V_112 = & V_183 ;
#else
struct V_68 * V_112 = NULL ;
#endif
if ( V_134 )
return 0 ;
if ( ! V_11 -> V_73 )
return - V_67 ;
if ( V_11 -> V_73 -> V_184 &&
V_11 -> V_32 . V_29 >
V_11 -> V_73 -> V_184 ) {
if ( ! V_112 )
return - V_67 ;
else {
F_139 ( L_74 ,
V_11 -> V_73 -> V_71 , V_112 -> V_71 ) ;
V_11 -> V_73 = V_112 ;
}
}
if ( V_182 == V_185 )
if ( ! F_177 ( V_11 -> V_73 -> V_186 ) )
return - V_67 ;
F_35 ( L_75 ,
V_11 -> V_14 , V_182 ) ;
F_61 ( & V_187 ) ;
if ( ( V_11 -> V_188 && V_182 == V_116 )
|| ( ! V_11 -> V_188
&& ( V_182 == V_117 || V_182 == V_115 ) ) ) {
F_62 ( & V_187 ) ;
return - V_189 ;
}
if ( V_182 == V_115 )
V_11 -> V_188 = false ;
else if ( V_182 == V_116 )
V_11 -> V_188 = true ;
F_62 ( & V_187 ) ;
V_30 = V_11 -> V_73 -> V_73 ( V_11 , V_182 ) ;
if ( ! V_30 ) {
if ( V_182 == V_185 )
V_11 -> V_73 -> V_190 ++ ;
else if ( V_182 == V_154 )
V_11 -> V_73 -> V_190 -- ;
} else {
F_61 ( & V_187 ) ;
if ( V_182 == V_115 )
V_11 -> V_188 = true ;
else if ( V_182 == V_116 )
V_11 -> V_188 = false ;
F_62 ( & V_187 ) ;
}
if ( ( ( V_182 == V_185 ) && V_30 ) ||
( ( V_182 == V_154 ) && ! V_30 ) )
F_178 ( V_11 -> V_73 -> V_186 ) ;
return V_30 ;
}
int F_179 ( struct V_68 * V_73 )
{
int V_74 ;
if ( ! V_73 )
return - V_67 ;
if ( F_4 () )
return - V_181 ;
F_61 ( & V_79 ) ;
V_73 -> V_190 = 0 ;
V_74 = - V_189 ;
if ( ! F_58 ( V_73 -> V_71 ) ) {
V_74 = 0 ;
F_141 ( & V_73 -> V_191 , & V_192 ) ;
}
F_62 ( & V_79 ) ;
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
if ( F_86 ( V_14 ) )
continue;
if ( ! strcmp ( F_21 ( V_113 , V_14 ) , V_73 -> V_71 ) )
strcpy ( F_21 ( V_113 , V_14 ) , L_76 ) ;
}
F_61 ( & V_79 ) ;
F_150 ( & V_73 -> V_191 ) ;
F_62 ( & V_79 ) ;
return;
}
int F_70 ( struct V_10 * V_11 , unsigned int V_14 )
{
struct V_10 * V_193 ;
if ( ! V_11 )
return - V_67 ;
V_193 = F_25 ( V_14 ) ;
if ( ! V_193 )
return - V_67 ;
memcpy ( V_11 , V_193 , sizeof( * V_11 ) ) ;
F_31 ( V_193 ) ;
return 0 ;
}
static int F_71 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
struct V_68 * V_194 ;
int V_30 ;
F_35 ( L_77 ,
V_83 -> V_14 , V_83 -> V_139 , V_83 -> V_140 ) ;
memcpy ( & V_83 -> V_32 , & V_11 -> V_32 , sizeof( V_11 -> V_32 ) ) ;
if ( V_83 -> V_139 > V_11 -> V_140 || V_83 -> V_140 < V_11 -> V_139 )
return - V_67 ;
V_30 = V_1 -> V_195 ( V_83 ) ;
if ( V_30 )
return V_30 ;
F_124 ( & V_127 ,
V_196 , V_83 ) ;
F_124 ( & V_127 ,
V_197 , V_83 ) ;
V_30 = V_1 -> V_195 ( V_83 ) ;
if ( V_30 )
return V_30 ;
F_124 ( & V_127 ,
V_198 , V_83 ) ;
V_11 -> V_139 = V_83 -> V_139 ;
V_11 -> V_140 = V_83 -> V_140 ;
F_35 ( L_78 ,
V_11 -> V_139 , V_11 -> V_140 ) ;
if ( V_1 -> V_76 ) {
V_11 -> V_11 = V_83 -> V_11 ;
F_35 ( L_79 ) ;
return V_1 -> V_76 ( V_83 ) ;
}
if ( V_83 -> V_73 == V_11 -> V_73 )
goto V_75;
F_35 ( L_80 ) ;
V_194 = V_11 -> V_73 ;
if ( V_194 ) {
F_106 ( V_11 , V_115 ) ;
F_88 ( & V_11 -> V_98 ) ;
F_106 ( V_11 , V_154 ) ;
F_87 ( & V_11 -> V_98 ) ;
}
V_11 -> V_73 = V_83 -> V_73 ;
if ( ! F_106 ( V_11 , V_185 ) ) {
if ( ! F_106 ( V_11 , V_116 ) )
goto V_75;
F_88 ( & V_11 -> V_98 ) ;
F_106 ( V_11 , V_154 ) ;
F_87 ( & V_11 -> V_98 ) ;
}
F_35 ( L_81 , V_11 -> V_73 -> V_71 ) ;
if ( V_194 ) {
V_11 -> V_73 = V_194 ;
F_106 ( V_11 , V_185 ) ;
F_106 ( V_11 , V_116 ) ;
}
return - V_67 ;
V_75:
F_35 ( L_82 ) ;
return F_106 ( V_11 , V_117 ) ;
}
int F_153 ( unsigned int V_14 )
{
struct V_10 * V_11 = F_25 ( V_14 ) ;
struct V_10 V_83 ;
int V_30 ;
if ( ! V_11 )
return - V_181 ;
F_87 ( & V_11 -> V_98 ) ;
F_35 ( L_83 , V_14 ) ;
memcpy ( & V_83 , V_11 , sizeof( * V_11 ) ) ;
V_83 . V_139 = V_11 -> V_84 . V_139 ;
V_83 . V_140 = V_11 -> V_84 . V_140 ;
V_83 . V_11 = V_11 -> V_84 . V_11 ;
V_83 . V_73 = V_11 -> V_84 . V_73 ;
if ( V_1 -> V_80 && ! V_1 -> V_76 ) {
V_83 . V_52 = V_1 -> V_80 ( V_14 ) ;
if ( F_48 ( ! V_83 . V_52 ) ) {
V_30 = - V_99 ;
goto V_100;
}
if ( ! V_11 -> V_52 ) {
F_35 ( L_84 ) ;
V_11 -> V_52 = V_83 . V_52 ;
} else {
if ( V_11 -> V_52 != V_83 . V_52 && F_1 () )
F_154 ( V_11 , V_83 . V_52 ) ;
}
}
V_30 = F_71 ( V_11 , & V_83 ) ;
V_100:
F_88 ( & V_11 -> V_98 ) ;
F_31 ( V_11 ) ;
return V_30 ;
}
static int F_182 ( struct V_164 * V_199 ,
unsigned long V_200 , void * V_201 )
{
unsigned int V_14 = ( unsigned long ) V_201 ;
struct V_106 * V_108 ;
V_108 = F_101 ( V_14 ) ;
if ( V_108 ) {
switch ( V_200 & ~ V_202 ) {
case V_203 :
F_129 ( V_108 , NULL ) ;
break;
case V_204 :
F_144 ( V_108 , NULL ) ;
break;
case V_205 :
F_148 ( V_108 , NULL ) ;
break;
case V_206 :
F_129 ( V_108 , NULL ) ;
break;
}
}
return V_207 ;
}
static int F_183 ( int V_50 )
{
struct V_27 * V_172 ;
struct V_10 * V_11 ;
int V_30 = - V_67 ;
F_131 (policy) {
V_172 = F_173 ( V_11 -> V_14 ) ;
if ( V_172 ) {
V_30 = F_184 ( V_11 ,
V_172 ) ;
if ( V_30 ) {
F_18 ( L_85 ,
V_31 ) ;
break;
}
V_11 -> V_84 . V_140 = V_11 -> V_140 ;
F_106 ( V_11 , V_117 ) ;
}
}
return V_30 ;
}
int F_57 ( int V_50 )
{
unsigned long V_7 ;
int V_30 = 0 ;
if ( V_1 -> V_64 == V_50 )
return 0 ;
F_107 ( & V_38 , V_7 ) ;
V_1 -> V_64 = V_50 ;
F_109 ( & V_38 , V_7 ) ;
V_30 = V_1 -> V_208 ( V_50 ) ;
if ( V_30 ) {
F_107 ( & V_38 , V_7 ) ;
V_1 -> V_64 = ! V_50 ;
F_109 ( & V_38 , V_7 ) ;
F_18 ( L_86 ,
V_31 , V_50 ? L_13 : L_14 ) ;
}
return V_30 ;
}
int F_185 ( void )
{
if ( F_42 ( V_1 ) )
return V_1 -> V_209 ;
return 0 ;
}
int F_186 ( void )
{
return V_1 -> V_64 ;
}
int F_187 ( struct V_1 * V_163 )
{
unsigned long V_7 ;
int V_30 ;
if ( F_4 () )
return - V_181 ;
if ( ! V_163 || ! V_163 -> V_195 || ! V_163 -> V_136 ||
! ( V_163 -> V_76 || V_163 -> V_2 ||
V_163 -> V_3 ) ||
( V_163 -> V_76 && ( V_163 -> V_2 ||
V_163 -> V_3 ) ) ||
( ! ! V_163 -> V_170 != ! ! V_163 -> V_171 ) )
return - V_67 ;
F_35 ( L_87 , V_163 -> V_71 ) ;
F_107 ( & V_38 , V_7 ) ;
if ( V_1 ) {
F_109 ( & V_38 , V_7 ) ;
return - V_210 ;
}
V_1 = V_163 ;
F_109 ( & V_38 , V_7 ) ;
if ( V_163 -> V_76 )
V_163 -> V_7 |= V_44 ;
if ( F_185 () ) {
if ( ! V_1 -> V_208 )
V_1 -> V_208 = F_183 ;
V_30 = F_96 ( & V_211 . V_62 ) ;
if ( V_30 ) {
F_18 ( L_88 ,
V_31 ) ;
goto V_212;
}
}
V_30 = F_188 ( & V_213 ) ;
if ( V_30 )
goto V_214;
if ( ! ( V_1 -> V_7 & V_215 ) &&
F_189 ( & V_149 ) ) {
F_35 ( L_89 , V_31 ,
V_163 -> V_71 ) ;
goto V_216;
}
F_190 ( & V_217 ) ;
F_35 ( L_90 , V_163 -> V_71 ) ;
return 0 ;
V_216:
F_191 ( & V_213 ) ;
V_214:
if ( F_185 () )
F_98 ( & V_211 . V_62 ) ;
V_212:
F_107 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_109 ( & V_38 , V_7 ) ;
return V_30 ;
}
int F_192 ( struct V_1 * V_218 )
{
unsigned long V_7 ;
if ( ! V_1 || ( V_218 != V_1 ) )
return - V_67 ;
F_35 ( L_91 , V_218 -> V_71 ) ;
F_191 ( & V_213 ) ;
if ( F_185 () )
F_98 ( & V_211 . V_62 ) ;
F_193 ( & V_217 ) ;
F_87 ( & V_37 ) ;
F_107 ( & V_38 , V_7 ) ;
V_1 = NULL ;
F_109 ( & V_38 , V_7 ) ;
F_88 ( & V_37 ) ;
return 0 ;
}
static int T_1 F_194 ( void )
{
if ( F_4 () )
return - V_181 ;
V_13 = F_195 () ;
F_38 ( ! V_13 ) ;
F_196 ( & V_219 ) ;
return 0 ;
}
