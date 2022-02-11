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
if ( ! F_38 ( & V_41 ) )
return NULL ;
F_39 ( & V_42 , V_13 ) ;
if ( V_7 ) {
V_2 = F_31 ( V_19 ) ;
if ( V_2 )
F_40 ( & V_2 -> V_16 ) ;
}
F_41 ( & V_42 , V_13 ) ;
if ( ! V_2 )
F_42 ( & V_41 ) ;
return V_2 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_16 ) ;
F_42 ( & V_41 ) ;
}
static void F_45 ( unsigned long V_43 , struct V_44 * V_45 )
{
#ifndef F_46
static unsigned long V_46 ;
static unsigned int V_47 ;
if ( V_45 -> V_13 & V_48 )
return;
if ( ! V_47 ) {
V_46 = V_49 ;
V_47 = V_45 -> V_50 ;
F_47 ( L_5 ,
V_46 , V_47 ) ;
}
if ( V_43 == V_51 && V_45 -> V_50 != V_45 -> V_52 ) {
V_49 = F_48 ( V_46 , V_47 ,
V_45 -> V_52 ) ;
F_47 ( L_6 ,
V_49 , V_45 -> V_52 ) ;
}
#endif
}
static void F_49 ( struct V_1 * V_2 ,
struct V_44 * V_53 , unsigned int V_54 )
{
F_50 ( F_51 () ) ;
if ( F_13 () )
return;
V_53 -> V_13 = V_7 -> V_13 ;
F_47 ( L_7 ,
V_54 , V_53 -> V_52 ) ;
switch ( V_54 ) {
case V_55 :
if ( ! ( V_7 -> V_13 & V_48 ) ) {
if ( ( V_2 ) && ( V_2 -> V_19 == V_53 -> V_19 ) &&
( V_2 -> V_56 ) && ( V_2 -> V_56 != V_53 -> V_50 ) ) {
F_47 ( L_8 ,
V_53 -> V_50 , V_2 -> V_56 ) ;
V_53 -> V_50 = V_2 -> V_56 ;
}
}
F_52 ( & V_10 ,
V_55 , V_53 ) ;
F_45 ( V_55 , V_53 ) ;
break;
case V_51 :
F_45 ( V_51 , V_53 ) ;
F_47 ( L_9 ,
( unsigned long ) V_53 -> V_52 , ( unsigned long ) V_53 -> V_19 ) ;
F_53 ( V_53 -> V_52 , V_53 -> V_19 ) ;
F_52 ( & V_10 ,
V_51 , V_53 ) ;
if ( F_54 ( V_2 ) && F_54 ( V_2 -> V_19 == V_53 -> V_19 ) )
V_2 -> V_56 = V_53 -> V_52 ;
break;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_44 * V_53 , unsigned int V_54 )
{
F_56 (freqs->cpu, policy->cpus)
F_49 ( V_2 , V_53 , V_54 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_44 * V_53 , int V_57 )
{
F_55 ( V_2 , V_53 , V_51 ) ;
if ( ! V_57 )
return;
F_58 ( V_53 -> V_50 , V_53 -> V_52 ) ;
F_55 ( V_2 , V_53 , V_55 ) ;
F_55 ( V_2 , V_53 , V_51 ) ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_44 * V_53 )
{
F_37 ( ! ( V_7 -> V_13 & V_58 )
&& V_59 == V_2 -> V_60 ) ;
V_61:
F_60 ( V_2 -> V_62 , ! V_2 -> V_63 ) ;
F_61 ( & V_2 -> V_64 ) ;
if ( F_62 ( V_2 -> V_63 ) ) {
F_63 ( & V_2 -> V_64 ) ;
goto V_61;
}
V_2 -> V_63 = true ;
V_2 -> V_60 = V_59 ;
F_63 ( & V_2 -> V_64 ) ;
F_55 ( V_2 , V_53 , V_55 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_44 * V_53 , int V_57 )
{
if ( F_62 ( F_37 ( ! V_2 -> V_63 ) ) )
return;
F_57 ( V_2 , V_53 , V_57 ) ;
V_2 -> V_63 = false ;
V_2 -> V_60 = NULL ;
F_65 ( & V_2 -> V_62 ) ;
}
static T_3 F_66 ( struct V_15 * V_16 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_10 , V_7 -> V_68 ) ;
}
static T_3 F_67 ( struct V_15 * V_16 , struct V_65 * V_66 ,
const char * V_67 , T_4 V_69 )
{
int V_36 , V_70 ;
V_36 = sscanf ( V_67 , L_11 , & V_70 ) ;
if ( V_36 != 1 || V_70 < 0 || V_70 > 1 )
return - V_71 ;
if ( F_68 ( V_70 ) ) {
F_29 ( L_12 ,
V_37 , V_70 ? L_13 : L_14 ) ;
return - V_71 ;
}
F_47 ( L_15 ,
V_37 , V_70 ? L_16 : L_17 ) ;
return V_69 ;
}
static struct V_72 * F_69 ( const char * V_73 )
{
struct V_72 * V_74 ;
F_70 (t)
if ( ! strncasecmp ( V_73 , V_74 -> V_75 , V_76 ) )
return V_74 ;
return NULL ;
}
static int F_71 ( char * V_73 , unsigned int * V_2 ,
struct V_72 * * V_77 )
{
int V_78 = - V_71 ;
if ( ! V_7 )
goto V_79;
if ( V_7 -> V_80 ) {
if ( ! strncasecmp ( V_73 , L_18 , V_76 ) ) {
* V_2 = V_81 ;
V_78 = 0 ;
} else if ( ! strncasecmp ( V_73 , L_19 ,
V_76 ) ) {
* V_2 = V_82 ;
V_78 = 0 ;
}
} else {
struct V_72 * V_74 ;
F_72 ( & V_83 ) ;
V_74 = F_69 ( V_73 ) ;
if ( V_74 == NULL ) {
int V_36 ;
F_73 ( & V_83 ) ;
V_36 = F_74 ( L_20 , V_73 ) ;
F_72 ( & V_83 ) ;
if ( V_36 == 0 )
V_74 = F_69 ( V_73 ) ;
}
if ( V_74 != NULL ) {
* V_77 = V_74 ;
V_78 = 0 ;
}
F_73 ( & V_83 ) ;
}
V_79:
return V_78 ;
}
static T_3 F_75 ( struct V_1 * V_2 , char * V_67 )
{
T_3 V_36 ;
if ( V_7 && V_7 -> V_80 && V_7 -> V_84 )
V_36 = sprintf ( V_67 , L_21 , V_7 -> V_84 ( V_2 -> V_19 ) ) ;
else
V_36 = sprintf ( V_67 , L_21 , V_2 -> V_56 ) ;
return V_36 ;
}
static T_3 F_76 ( struct V_1 * V_2 ,
char * V_67 )
{
unsigned int V_85 = F_77 ( V_2 ) ;
if ( ! V_85 )
return sprintf ( V_67 , L_22 ) ;
return sprintf ( V_67 , L_21 , V_85 ) ;
}
static T_3 F_78 ( struct V_1 * V_2 , char * V_67 )
{
if ( V_2 -> V_2 == V_82 )
return sprintf ( V_67 , L_23 ) ;
else if ( V_2 -> V_2 == V_81 )
return sprintf ( V_67 , L_24 ) ;
else if ( V_2 -> V_77 )
return F_79 ( V_67 , V_86 , L_25 ,
V_2 -> V_77 -> V_75 ) ;
return - V_71 ;
}
static T_3 F_80 ( struct V_1 * V_2 ,
const char * V_67 , T_4 V_69 )
{
int V_36 ;
char V_73 [ 16 ] ;
struct V_1 V_87 ;
V_36 = F_81 ( & V_87 , V_2 -> V_19 ) ;
if ( V_36 )
return V_36 ;
V_36 = sscanf ( V_67 , L_26 , V_73 ) ;
if ( V_36 != 1 )
return - V_71 ;
if ( F_71 ( V_73 , & V_87 . V_2 ,
& V_87 . V_77 ) )
return - V_71 ;
V_36 = F_82 ( V_2 , & V_87 ) ;
V_2 -> V_88 . V_2 = V_2 -> V_2 ;
V_2 -> V_88 . V_77 = V_2 -> V_77 ;
if ( V_36 )
return V_36 ;
else
return V_69 ;
}
static T_3 F_83 ( struct V_1 * V_2 , char * V_67 )
{
return F_79 ( V_67 , V_86 , L_25 , V_7 -> V_75 ) ;
}
static T_3 F_84 ( struct V_1 * V_2 ,
char * V_67 )
{
T_3 V_89 = 0 ;
struct V_72 * V_74 ;
if ( ! F_10 () ) {
V_89 += sprintf ( V_67 , L_27 ) ;
goto V_79;
}
F_70 (t) {
if ( V_89 >= ( T_3 ) ( ( V_90 / sizeof( char ) )
- ( V_76 + 2 ) ) )
goto V_79;
V_89 += F_79 ( & V_67 [ V_89 ] , V_86 , L_28 , V_74 -> V_75 ) ;
}
V_79:
V_89 += sprintf ( & V_67 [ V_89 ] , L_29 ) ;
return V_89 ;
}
T_3 F_85 ( const struct V_91 * V_92 , char * V_67 )
{
T_3 V_89 = 0 ;
unsigned int V_19 ;
F_56 (cpu, mask) {
if ( V_89 )
V_89 += F_79 ( & V_67 [ V_89 ] , ( V_90 - V_89 - 2 ) , L_30 ) ;
V_89 += F_79 ( & V_67 [ V_89 ] , ( V_90 - V_89 - 2 ) , L_31 , V_19 ) ;
if ( V_89 >= ( V_90 - 5 ) )
break;
}
V_89 += sprintf ( & V_67 [ V_89 ] , L_29 ) ;
return V_89 ;
}
static T_3 F_86 ( struct V_1 * V_2 , char * V_67 )
{
return F_85 ( V_2 -> V_93 , V_67 ) ;
}
static T_3 F_87 ( struct V_1 * V_2 , char * V_67 )
{
return F_85 ( V_2 -> V_3 , V_67 ) ;
}
static T_3 F_88 ( struct V_1 * V_2 ,
const char * V_67 , T_4 V_69 )
{
unsigned int V_94 = 0 ;
unsigned int V_36 ;
if ( ! V_2 -> V_77 || ! V_2 -> V_77 -> V_95 )
return - V_71 ;
V_36 = sscanf ( V_67 , L_31 , & V_94 ) ;
if ( V_36 != 1 )
return - V_71 ;
V_2 -> V_77 -> V_95 ( V_2 , V_94 ) ;
return V_69 ;
}
static T_3 F_89 ( struct V_1 * V_2 , char * V_67 )
{
if ( ! V_2 -> V_77 || ! V_2 -> V_77 -> V_96 )
return sprintf ( V_67 , L_32 ) ;
return V_2 -> V_77 -> V_96 ( V_2 , V_67 ) ;
}
static T_3 F_90 ( struct V_1 * V_2 , char * V_67 )
{
unsigned int V_97 ;
int V_36 ;
if ( V_7 -> V_98 ) {
V_36 = V_7 -> V_98 ( V_2 -> V_19 , & V_97 ) ;
if ( ! V_36 )
return sprintf ( V_67 , L_21 , V_97 ) ;
}
return sprintf ( V_67 , L_21 , V_2 -> V_38 . V_99 ) ;
}
static T_3 F_91 ( struct V_15 * V_16 , struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_92 ( V_16 ) ;
struct V_100 * V_101 = F_93 ( V_66 ) ;
T_3 V_36 ;
if ( ! F_38 ( & V_41 ) )
return - V_71 ;
F_94 ( & V_2 -> V_102 ) ;
if ( V_101 -> F_91 )
V_36 = V_101 -> F_91 ( V_2 , V_67 ) ;
else
V_36 = - V_103 ;
F_42 ( & V_2 -> V_102 ) ;
F_42 ( & V_41 ) ;
return V_36 ;
}
static T_3 F_95 ( struct V_15 * V_16 , struct V_65 * V_66 ,
const char * V_67 , T_4 V_69 )
{
struct V_1 * V_2 = F_92 ( V_16 ) ;
struct V_100 * V_101 = F_93 ( V_66 ) ;
T_3 V_36 = - V_71 ;
F_96 () ;
if ( ! F_97 ( V_2 -> V_19 ) )
goto V_104;
if ( ! F_38 ( & V_41 ) )
goto V_104;
F_98 ( & V_2 -> V_102 ) ;
if ( F_62 ( F_1 ( V_2 ) ) ) {
V_36 = - V_105 ;
goto V_106;
}
if ( V_101 -> F_95 )
V_36 = V_101 -> F_95 ( V_2 , V_67 , V_69 ) ;
else
V_36 = - V_103 ;
V_106:
F_99 ( & V_2 -> V_102 ) ;
F_42 ( & V_41 ) ;
V_104:
F_100 () ;
return V_36 ;
}
static void F_101 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_92 ( V_16 ) ;
F_47 ( L_33 ) ;
F_102 ( & V_2 -> V_107 ) ;
}
int F_103 ( void )
{
if ( ! V_108 ++ )
return F_104 ( V_17 ,
& V_109 . V_110 -> V_16 , L_34 , L_35 ) ;
return 0 ;
}
void F_105 ( void )
{
if ( ! -- V_108 )
F_106 ( V_17 ) ;
}
int F_107 ( const struct V_65 * V_66 )
{
int V_36 = F_103 () ;
if ( ! V_36 ) {
V_36 = F_108 ( V_17 , V_66 ) ;
if ( V_36 )
F_105 () ;
}
return V_36 ;
}
void F_109 ( const struct V_65 * V_66 )
{
F_110 ( V_17 , V_66 ) ;
F_105 () ;
}
static int F_111 ( struct V_1 * V_2 , int V_19 )
{
struct V_111 * V_112 ;
F_47 ( L_36 , V_37 , V_19 ) ;
if ( ! V_2 )
return 0 ;
V_112 = F_112 ( V_19 ) ;
if ( F_37 ( ! V_112 ) )
return 0 ;
return F_113 ( & V_112 -> V_16 , & V_2 -> V_16 , L_35 ) ;
}
static void F_114 ( struct V_1 * V_2 , int V_19 )
{
struct V_111 * V_112 ;
F_47 ( L_37 , V_37 , V_19 ) ;
V_112 = F_112 ( V_19 ) ;
if ( F_37 ( ! V_112 ) )
return;
F_115 ( & V_112 -> V_16 , L_35 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
unsigned int V_113 ;
int V_36 = 0 ;
F_56 (j, policy->real_cpus) {
if ( V_113 == V_2 -> V_114 )
continue;
V_36 = F_111 ( V_2 , V_113 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
static void F_117 ( struct V_1 * V_2 )
{
unsigned int V_113 ;
F_56 (j, policy->real_cpus) {
if ( V_113 == V_2 -> V_114 )
continue;
F_114 ( V_2 , V_113 ) ;
}
}
static int F_118 ( struct V_1 * V_2 ,
struct V_111 * V_115 )
{
struct V_100 * * V_116 ;
int V_36 = 0 ;
V_116 = V_7 -> V_66 ;
while ( V_116 && * V_116 ) {
V_36 = F_108 ( & V_2 -> V_16 , & ( ( * V_116 ) -> V_66 ) ) ;
if ( V_36 )
return V_36 ;
V_116 ++ ;
}
if ( V_7 -> V_84 ) {
V_36 = F_108 ( & V_2 -> V_16 , & V_117 . V_66 ) ;
if ( V_36 )
return V_36 ;
}
V_36 = F_108 ( & V_2 -> V_16 , & V_118 . V_66 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_98 ) {
V_36 = F_108 ( & V_2 -> V_16 , & V_98 . V_66 ) ;
if ( V_36 )
return V_36 ;
}
return F_116 ( V_2 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_72 * V_119 = NULL ;
struct V_1 V_87 ;
int V_36 = 0 ;
memcpy ( & V_87 , V_2 , sizeof( * V_2 ) ) ;
V_119 = F_69 ( V_2 -> V_120 ) ;
if ( V_119 )
F_47 ( L_38 ,
V_2 -> V_77 -> V_75 , V_2 -> V_19 ) ;
else
V_119 = V_121 ;
V_87 . V_77 = V_119 ;
if ( V_7 -> V_80 )
F_71 ( V_119 -> V_75 , & V_87 . V_2 , NULL ) ;
V_36 = F_82 ( V_2 , & V_87 ) ;
if ( V_36 ) {
F_47 ( L_39 ) ;
if ( V_7 -> exit )
V_7 -> exit ( V_2 ) ;
}
}
static int F_120 ( struct V_1 * V_2 ,
unsigned int V_19 , struct V_111 * V_115 )
{
int V_36 = 0 ;
if ( F_32 ( V_19 , V_2 -> V_3 ) )
return 0 ;
if ( F_10 () ) {
V_36 = F_121 ( V_2 , V_122 ) ;
if ( V_36 ) {
F_29 ( L_40 , V_37 ) ;
return V_36 ;
}
}
F_98 ( & V_2 -> V_102 ) ;
F_122 ( V_19 , V_2 -> V_3 ) ;
F_99 ( & V_2 -> V_102 ) ;
if ( F_10 () ) {
V_36 = F_121 ( V_2 , V_123 ) ;
if ( ! V_36 )
V_36 = F_121 ( V_2 , V_124 ) ;
if ( V_36 ) {
F_29 ( L_41 , V_37 ) ;
return V_36 ;
}
}
return 0 ;
}
static struct V_1 * F_123 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
F_39 ( & V_42 , V_13 ) ;
V_2 = F_18 ( V_20 , V_19 ) ;
F_41 ( & V_42 , V_13 ) ;
if ( F_54 ( V_2 ) ) {
F_37 ( ! F_1 ( V_2 ) ) ;
F_98 ( & V_2 -> V_102 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_77 = NULL ;
F_99 ( & V_2 -> V_102 ) ;
}
return V_2 ;
}
static struct V_1 * F_124 ( struct V_111 * V_115 )
{
struct V_1 * V_2 ;
int V_36 ;
V_2 = F_125 ( sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return NULL ;
if ( ! F_126 ( & V_2 -> V_3 , V_125 ) )
goto V_126;
if ( ! F_127 ( & V_2 -> V_93 , V_125 ) )
goto V_127;
if ( ! F_127 ( & V_2 -> V_128 , V_125 ) )
goto V_129;
V_36 = F_128 ( & V_2 -> V_16 , & V_130 , & V_115 -> V_16 ,
L_35 ) ;
if ( V_36 ) {
F_29 ( L_42 , V_37 , V_36 ) ;
goto V_131;
}
F_129 ( & V_2 -> V_5 ) ;
F_130 ( & V_2 -> V_102 ) ;
F_131 ( & V_2 -> V_64 ) ;
F_132 ( & V_2 -> V_62 ) ;
F_133 ( & V_2 -> V_107 ) ;
F_134 ( & V_2 -> V_132 , V_133 ) ;
V_2 -> V_19 = V_115 -> V_134 ;
V_2 -> V_114 = V_115 -> V_134 ;
return V_2 ;
V_131:
F_135 ( V_2 -> V_128 ) ;
V_129:
F_135 ( V_2 -> V_93 ) ;
V_127:
F_135 ( V_2 -> V_3 ) ;
V_126:
F_136 ( V_2 ) ;
return NULL ;
}
static void F_137 ( struct V_1 * V_2 , bool V_135 )
{
struct V_15 * V_16 ;
struct V_136 * V_137 ;
if ( V_135 )
F_138 ( & V_138 ,
V_139 , V_2 ) ;
F_98 ( & V_2 -> V_102 ) ;
F_117 ( V_2 ) ;
V_16 = & V_2 -> V_16 ;
V_137 = & V_2 -> V_107 ;
F_99 ( & V_2 -> V_102 ) ;
F_44 ( V_16 ) ;
F_47 ( L_43 ) ;
F_139 ( V_137 ) ;
F_47 ( L_44 ) ;
}
static void F_140 ( struct V_1 * V_2 , bool V_135 )
{
unsigned long V_13 ;
int V_19 ;
F_141 ( & V_42 , V_13 ) ;
F_142 ( & V_2 -> V_5 ) ;
F_56 (cpu, policy->related_cpus)
F_18 ( V_20 , V_19 ) = NULL ;
F_143 ( & V_42 , V_13 ) ;
F_137 ( V_2 , V_135 ) ;
F_135 ( V_2 -> V_128 ) ;
F_135 ( V_2 -> V_93 ) ;
F_135 ( V_2 -> V_3 ) ;
F_136 ( V_2 ) ;
}
static int F_144 ( struct V_111 * V_115 , struct V_140 * V_141 )
{
unsigned int V_113 , V_19 = V_115 -> V_134 ;
int V_36 = - V_142 ;
struct V_1 * V_2 ;
unsigned long V_13 ;
bool V_143 = ! V_141 ;
F_47 ( L_45 , V_19 ) ;
if ( F_145 ( V_19 ) ) {
V_2 = F_18 ( V_20 , V_19 ) ;
return V_2 && ! F_146 ( V_19 , V_2 -> V_128 )
? F_111 ( V_2 , V_19 ) : 0 ;
}
if ( ! F_38 ( & V_41 ) )
return 0 ;
V_2 = F_18 ( V_20 , V_19 ) ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_37 ( ! F_32 ( V_19 , V_2 -> V_93 ) ) ;
V_36 = F_120 ( V_2 , V_19 , V_115 ) ;
F_42 ( & V_41 ) ;
return V_36 ;
}
V_2 = V_143 ? F_123 ( V_19 ) : NULL ;
if ( ! V_2 ) {
V_143 = false ;
V_2 = F_124 ( V_115 ) ;
if ( ! V_2 )
goto V_144;
}
F_147 ( V_2 -> V_3 , F_148 ( V_19 ) ) ;
V_36 = V_7 -> V_145 ( V_2 ) ;
if ( V_36 ) {
F_47 ( L_46 ) ;
goto V_146;
}
F_98 ( & V_2 -> V_102 ) ;
F_149 ( V_2 -> V_93 , V_2 -> V_93 , V_2 -> V_3 ) ;
if ( ! V_143 )
F_150 ( V_2 -> V_128 , V_2 -> V_3 , V_147 ) ;
F_150 ( V_2 -> V_3 , V_2 -> V_3 , V_148 ) ;
if ( ! V_143 ) {
V_2 -> V_88 . V_149 = V_2 -> V_149 ;
V_2 -> V_88 . V_150 = V_2 -> V_150 ;
F_141 ( & V_42 , V_13 ) ;
F_56 (j, policy->related_cpus)
F_18 ( V_20 , V_113 ) = V_2 ;
F_143 ( & V_42 , V_13 ) ;
}
if ( V_7 -> V_84 && ! V_7 -> V_80 ) {
V_2 -> V_56 = V_7 -> V_84 ( V_2 -> V_19 ) ;
if ( ! V_2 -> V_56 ) {
F_29 ( L_47 , V_37 ) ;
goto V_151;
}
}
if ( ( V_7 -> V_13 & V_152 )
&& F_10 () ) {
V_36 = F_151 ( V_2 , V_2 -> V_56 ) ;
if ( V_36 == - V_71 ) {
F_152 ( L_48 ,
V_37 , V_2 -> V_19 , V_2 -> V_56 ) ;
V_36 = F_153 ( V_2 , V_2 -> V_56 - 1 ,
V_153 ) ;
F_50 ( V_36 ) ;
F_152 ( L_49 ,
V_37 , V_2 -> V_19 , V_2 -> V_56 ) ;
}
}
F_138 ( & V_138 ,
V_154 , V_2 ) ;
if ( ! V_143 ) {
V_36 = F_118 ( V_2 , V_115 ) ;
if ( V_36 )
goto V_155;
F_138 ( & V_138 ,
V_156 , V_2 ) ;
F_141 ( & V_42 , V_13 ) ;
F_154 ( & V_2 -> V_5 , & V_6 ) ;
F_143 ( & V_42 , V_13 ) ;
}
F_119 ( V_2 ) ;
if ( ! V_143 ) {
V_2 -> V_88 . V_2 = V_2 -> V_2 ;
V_2 -> V_88 . V_77 = V_2 -> V_77 ;
}
F_99 ( & V_2 -> V_102 ) ;
F_155 ( & V_2 -> V_16 , V_157 ) ;
F_42 ( & V_41 ) ;
if ( V_7 -> V_158 )
V_7 -> V_158 ( V_2 ) ;
F_47 ( L_50 ) ;
return 0 ;
V_155:
V_151:
F_99 ( & V_2 -> V_102 ) ;
if ( V_7 -> exit )
V_7 -> exit ( V_2 ) ;
V_146:
F_140 ( V_2 , V_143 ) ;
V_144:
F_42 ( & V_41 ) ;
return V_36 ;
}
static int F_156 ( struct V_111 * V_115 )
{
unsigned int V_19 = V_115 -> V_134 ;
int V_36 = 0 ;
struct V_1 * V_2 ;
F_47 ( L_51 , V_37 , V_19 ) ;
V_2 = F_31 ( V_19 ) ;
if ( ! V_2 ) {
F_47 ( L_52 , V_37 ) ;
return - V_71 ;
}
if ( F_10 () ) {
V_36 = F_121 ( V_2 , V_122 ) ;
if ( V_36 )
F_29 ( L_40 , V_37 ) ;
}
F_98 ( & V_2 -> V_102 ) ;
F_157 ( V_19 , V_2 -> V_3 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_10 () )
strncpy ( V_2 -> V_120 , V_2 -> V_77 -> V_75 ,
V_76 ) ;
} else if ( V_19 == V_2 -> V_19 ) {
V_2 -> V_19 = F_158 ( V_2 -> V_3 ) ;
}
F_99 ( & V_2 -> V_102 ) ;
if ( ! F_1 ( V_2 ) ) {
if ( F_10 () ) {
V_36 = F_121 ( V_2 , V_123 ) ;
if ( ! V_36 )
V_36 = F_121 ( V_2 , V_124 ) ;
if ( V_36 )
F_29 ( L_41 , V_37 ) ;
}
} else if ( V_7 -> V_159 ) {
V_7 -> V_159 ( V_2 ) ;
}
return V_36 ;
}
static int F_159 ( struct V_111 * V_115 )
{
unsigned int V_19 = V_115 -> V_134 ;
int V_36 ;
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
if ( ! V_2 ) {
F_47 ( L_52 , V_37 ) ;
return - V_71 ;
}
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( F_10 () ) {
V_36 = F_121 ( V_2 , V_160 ) ;
if ( V_36 )
F_29 ( L_53 , V_37 ) ;
}
if ( V_7 -> exit )
V_7 -> exit ( V_2 ) ;
return 0 ;
}
static int F_160 ( struct V_111 * V_115 , struct V_140 * V_141 )
{
unsigned int V_19 = V_115 -> V_134 ;
struct V_1 * V_2 = F_18 ( V_20 , V_19 ) ;
if ( ! V_2 )
return 0 ;
if ( F_97 ( V_19 ) ) {
F_156 ( V_115 ) ;
F_159 ( V_115 ) ;
}
F_157 ( V_19 , V_2 -> V_128 ) ;
if ( F_2 ( V_2 -> V_128 ) ) {
F_140 ( V_2 , true ) ;
return 0 ;
}
if ( V_19 != V_2 -> V_114 ) {
F_114 ( V_2 , V_19 ) ;
} else {
unsigned int V_161 = F_161 ( V_2 -> V_128 ) ;
struct V_111 * V_162 = F_112 ( V_161 ) ;
F_162 ( V_115 , L_54 , V_37 , V_161 ) ;
F_115 ( & V_162 -> V_16 , L_35 ) ;
V_2 -> V_114 = V_161 ;
F_37 ( F_163 ( & V_2 -> V_16 , & V_162 -> V_16 ) ) ;
}
return 0 ;
}
static void V_133 ( struct V_163 * V_164 )
{
struct V_1 * V_2 =
F_164 ( V_164 , struct V_1 , V_132 ) ;
unsigned int V_19 = V_2 -> V_19 ;
F_47 ( L_55 , V_19 ) ;
F_165 ( V_19 ) ;
}
static void F_166 ( struct V_1 * V_2 ,
unsigned int V_165 )
{
struct V_44 V_53 ;
F_47 ( L_56 ,
V_2 -> V_56 , V_165 ) ;
V_53 . V_50 = V_2 -> V_56 ;
V_53 . V_52 = V_165 ;
F_59 ( V_2 , & V_53 ) ;
F_64 ( V_2 , & V_53 , 0 ) ;
}
unsigned int F_167 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
unsigned int V_166 = 0 ;
if ( V_7 && V_7 -> V_80 && V_7 -> V_84 )
return V_7 -> V_84 ( V_19 ) ;
V_2 = F_36 ( V_19 ) ;
if ( V_2 ) {
V_166 = V_2 -> V_56 ;
F_43 ( V_2 ) ;
}
return V_166 ;
}
unsigned int F_168 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
unsigned int V_166 = 0 ;
if ( V_2 ) {
V_166 = V_2 -> V_150 ;
F_43 ( V_2 ) ;
}
return V_166 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
unsigned int V_166 = 0 ;
if ( ! V_7 -> V_84 )
return V_166 ;
V_166 = V_7 -> V_84 ( V_2 -> V_19 ) ;
if ( F_62 ( F_1 ( V_2 ) ) )
return V_166 ;
if ( V_166 && V_2 -> V_56 &&
! ( V_7 -> V_13 & V_48 ) ) {
if ( F_62 ( V_166 != V_2 -> V_56 ) ) {
F_166 ( V_2 , V_166 ) ;
F_169 ( & V_2 -> V_132 ) ;
}
}
return V_166 ;
}
unsigned int F_170 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
unsigned int V_166 = 0 ;
if ( V_2 ) {
F_94 ( & V_2 -> V_102 ) ;
V_166 = F_77 ( V_2 ) ;
F_42 ( & V_2 -> V_102 ) ;
F_43 ( V_2 ) ;
}
return V_166 ;
}
int F_171 ( struct V_1 * V_2 )
{
int V_36 ;
if ( ! V_2 -> V_167 ) {
F_29 ( L_57 , V_37 ) ;
return - V_71 ;
}
F_47 ( L_58 , V_37 ,
V_2 -> V_167 ) ;
V_36 = F_153 ( V_2 , V_2 -> V_167 ,
V_168 ) ;
if ( V_36 )
F_29 ( L_59 ,
V_37 , V_2 -> V_167 , V_36 ) ;
return V_36 ;
}
void F_172 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
if ( ! F_10 () )
goto V_169;
F_47 ( L_60 , V_37 ) ;
F_173 (policy) {
if ( F_121 ( V_2 , V_122 ) )
F_29 ( L_61 ,
V_37 , V_2 ) ;
else if ( V_7 -> V_169
&& V_7 -> V_169 ( V_2 ) )
F_29 ( L_62 , V_37 ,
V_2 ) ;
}
V_169:
V_170 = true ;
}
void F_174 ( void )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_170 = false ;
if ( ! F_10 () )
return;
F_47 ( L_63 , V_37 ) ;
F_173 (policy) {
if ( V_7 -> V_171 && V_7 -> V_171 ( V_2 ) )
F_29 ( L_64 , V_37 ,
V_2 ) ;
else if ( F_121 ( V_2 , V_123 )
|| F_121 ( V_2 , V_124 ) )
F_29 ( L_65 ,
V_37 , V_2 ) ;
}
V_2 = F_31 ( F_161 ( V_148 ) ) ;
if ( F_37 ( ! V_2 ) )
return;
F_169 ( & V_2 -> V_132 ) ;
}
const char * F_175 ( void )
{
if ( V_7 )
return V_7 -> V_75 ;
return NULL ;
}
void * F_176 ( void )
{
if ( V_7 )
return V_7 -> V_172 ;
return NULL ;
}
int F_177 ( struct V_173 * V_174 , unsigned int V_175 )
{
int V_36 ;
if ( F_13 () )
return - V_71 ;
F_37 ( ! V_11 ) ;
switch ( V_175 ) {
case V_176 :
V_36 = F_178 (
& V_10 , V_174 ) ;
break;
case V_177 :
V_36 = F_179 (
& V_138 , V_174 ) ;
break;
default:
V_36 = - V_71 ;
}
return V_36 ;
}
int F_180 ( struct V_173 * V_174 , unsigned int V_175 )
{
int V_36 ;
if ( F_13 () )
return - V_71 ;
switch ( V_175 ) {
case V_176 :
V_36 = F_181 (
& V_10 , V_174 ) ;
break;
case V_177 :
V_36 = F_182 (
& V_138 , V_174 ) ;
break;
default:
V_36 = - V_71 ;
}
return V_36 ;
}
static int F_183 ( struct V_1 * V_2 ,
struct V_44 * V_53 , int V_178 )
{
int V_36 ;
V_53 -> V_52 = V_7 -> V_179 ( V_2 , V_178 ) ;
if ( ! V_53 -> V_52 )
return 0 ;
F_47 ( L_66 ,
V_37 , V_2 -> V_19 , V_53 -> V_50 , V_53 -> V_52 ) ;
F_59 ( V_2 , V_53 ) ;
V_36 = V_7 -> V_180 ( V_2 , V_178 ) ;
F_64 ( V_2 , V_53 , V_36 ) ;
if ( V_36 )
F_29 ( L_67 ,
V_37 , V_36 ) ;
return V_36 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_18 * V_21 , int V_178 )
{
struct V_44 V_53 = { . V_50 = V_2 -> V_56 , . V_13 = 0 } ;
unsigned int V_181 = 0 ;
int V_182 = - V_71 ;
bool V_135 ;
V_135 = ! ( V_7 -> V_13 & V_58 ) ;
if ( V_135 ) {
if ( V_7 -> V_179 ) {
V_182 = F_183 ( V_2 , & V_53 , V_178 ) ;
if ( V_182 )
return V_182 ;
V_181 = V_53 . V_52 ;
if ( V_181 )
V_53 . V_50 = V_53 . V_52 ;
}
V_53 . V_52 = V_21 [ V_178 ] . V_183 ;
F_47 ( L_68 ,
V_37 , V_2 -> V_19 , V_53 . V_50 , V_53 . V_52 ) ;
F_59 ( V_2 , & V_53 ) ;
}
V_182 = V_7 -> V_8 ( V_2 , V_178 ) ;
if ( V_182 )
F_29 ( L_69 , V_37 ,
V_182 ) ;
if ( V_135 ) {
F_64 ( V_2 , & V_53 , V_182 ) ;
if ( F_62 ( V_182 && V_181 ) ) {
V_53 . V_50 = V_181 ;
V_53 . V_52 = V_2 -> V_184 ;
F_59 ( V_2 , & V_53 ) ;
F_64 ( V_2 , & V_53 , 0 ) ;
}
}
return V_182 ;
}
int F_153 ( struct V_1 * V_2 ,
unsigned int V_185 ,
unsigned int V_186 )
{
unsigned int V_187 = V_185 ;
int V_182 = - V_71 ;
if ( F_13 () )
return - V_188 ;
if ( V_185 > V_2 -> V_150 )
V_185 = V_2 -> V_150 ;
if ( V_185 < V_2 -> V_149 )
V_185 = V_2 -> V_149 ;
F_47 ( L_70 ,
V_2 -> V_19 , V_185 , V_186 , V_187 ) ;
if ( V_185 == V_2 -> V_56 )
return 0 ;
V_2 -> V_184 = V_2 -> V_56 ;
if ( V_7 -> V_9 )
V_182 = V_7 -> V_9 ( V_2 , V_185 , V_186 ) ;
else if ( V_7 -> V_8 ) {
struct V_18 * V_21 ;
int V_178 ;
V_21 = F_17 ( V_2 -> V_19 ) ;
if ( F_62 ( ! V_21 ) ) {
F_29 ( L_71 , V_37 ) ;
goto V_79;
}
V_182 = F_185 ( V_2 , V_21 ,
V_185 , V_186 , & V_178 ) ;
if ( F_62 ( V_182 ) ) {
F_29 ( L_72 , V_37 ) ;
goto V_79;
}
if ( V_21 [ V_178 ] . V_183 == V_2 -> V_56 ) {
V_182 = 0 ;
goto V_79;
}
V_182 = F_184 ( V_2 , V_21 , V_178 ) ;
}
V_79:
return V_182 ;
}
int F_186 ( struct V_1 * V_2 ,
unsigned int V_185 ,
unsigned int V_186 )
{
int V_36 = - V_71 ;
F_98 ( & V_2 -> V_102 ) ;
V_36 = F_153 ( V_2 , V_185 , V_186 ) ;
F_99 ( & V_2 -> V_102 ) ;
return V_36 ;
}
static int F_121 ( struct V_1 * V_2 ,
unsigned int V_189 )
{
int V_36 ;
#ifdef F_187
struct V_72 * V_119 = & V_190 ;
#else
struct V_72 * V_119 = NULL ;
#endif
if ( V_170 )
return 0 ;
if ( ! V_2 -> V_77 )
return - V_71 ;
if ( V_2 -> V_77 -> V_191 &&
V_2 -> V_38 . V_35 >
V_2 -> V_77 -> V_191 ) {
if ( ! V_119 )
return - V_71 ;
else {
F_152 ( L_73 ,
V_2 -> V_77 -> V_75 , V_119 -> V_75 ) ;
V_2 -> V_77 = V_119 ;
}
}
if ( V_189 == V_192 )
if ( ! F_188 ( V_2 -> V_77 -> V_193 ) )
return - V_71 ;
F_47 ( L_74 ,
V_2 -> V_19 , V_189 ) ;
F_72 ( & V_194 ) ;
if ( ( V_2 -> V_195 && V_189 == V_123 )
|| ( ! V_2 -> V_195
&& ( V_189 == V_124 || V_189 == V_122 ) ) ) {
F_73 ( & V_194 ) ;
return - V_105 ;
}
if ( V_189 == V_122 )
V_2 -> V_195 = false ;
else if ( V_189 == V_123 )
V_2 -> V_195 = true ;
F_73 ( & V_194 ) ;
V_36 = V_2 -> V_77 -> V_77 ( V_2 , V_189 ) ;
if ( ! V_36 ) {
if ( V_189 == V_192 )
V_2 -> V_77 -> V_196 ++ ;
else if ( V_189 == V_160 )
V_2 -> V_77 -> V_196 -- ;
} else {
F_72 ( & V_194 ) ;
if ( V_189 == V_122 )
V_2 -> V_195 = true ;
else if ( V_189 == V_123 )
V_2 -> V_195 = false ;
F_73 ( & V_194 ) ;
}
if ( ( ( V_189 == V_192 ) && V_36 ) ||
( ( V_189 == V_160 ) && ! V_36 ) )
F_189 ( V_2 -> V_77 -> V_193 ) ;
return V_36 ;
}
int F_190 ( struct V_72 * V_77 )
{
int V_78 ;
if ( ! V_77 )
return - V_71 ;
if ( F_13 () )
return - V_188 ;
F_72 ( & V_83 ) ;
V_77 -> V_196 = 0 ;
V_78 = - V_105 ;
if ( ! F_69 ( V_77 -> V_75 ) ) {
V_78 = 0 ;
F_154 ( & V_77 -> V_197 , & V_198 ) ;
}
F_73 ( & V_83 ) ;
return V_78 ;
}
void F_191 ( struct V_72 * V_77 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
if ( ! V_77 )
return;
if ( F_13 () )
return;
F_39 ( & V_42 , V_13 ) ;
F_192 (policy) {
if ( ! strcmp ( V_2 -> V_120 , V_77 -> V_75 ) ) {
V_2 -> V_77 = NULL ;
strcpy ( V_2 -> V_120 , L_75 ) ;
}
}
F_41 ( & V_42 , V_13 ) ;
F_72 ( & V_83 ) ;
F_142 ( & V_77 -> V_197 ) ;
F_73 ( & V_83 ) ;
return;
}
int F_81 ( struct V_1 * V_2 , unsigned int V_19 )
{
struct V_1 * V_199 ;
if ( ! V_2 )
return - V_71 ;
V_199 = F_36 ( V_19 ) ;
if ( ! V_199 )
return - V_71 ;
memcpy ( V_2 , V_199 , sizeof( * V_2 ) ) ;
F_43 ( V_199 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_1 * V_87 )
{
struct V_72 * V_200 ;
int V_36 ;
F_47 ( L_76 ,
V_87 -> V_19 , V_87 -> V_149 , V_87 -> V_150 ) ;
memcpy ( & V_87 -> V_38 , & V_2 -> V_38 , sizeof( V_2 -> V_38 ) ) ;
if ( V_87 -> V_149 > V_2 -> V_150 || V_87 -> V_150 < V_2 -> V_149 )
return - V_71 ;
V_36 = V_7 -> V_201 ( V_87 ) ;
if ( V_36 )
return V_36 ;
F_138 ( & V_138 ,
V_202 , V_87 ) ;
F_138 ( & V_138 ,
V_203 , V_87 ) ;
V_36 = V_7 -> V_201 ( V_87 ) ;
if ( V_36 )
return V_36 ;
F_138 ( & V_138 ,
V_204 , V_87 ) ;
V_2 -> V_149 = V_87 -> V_149 ;
V_2 -> V_150 = V_87 -> V_150 ;
F_47 ( L_77 ,
V_2 -> V_149 , V_2 -> V_150 ) ;
if ( V_7 -> V_80 ) {
V_2 -> V_2 = V_87 -> V_2 ;
F_47 ( L_78 ) ;
return V_7 -> V_80 ( V_87 ) ;
}
if ( V_87 -> V_77 == V_2 -> V_77 )
goto V_79;
F_47 ( L_79 ) ;
V_200 = V_2 -> V_77 ;
if ( V_200 ) {
F_121 ( V_2 , V_122 ) ;
F_99 ( & V_2 -> V_102 ) ;
F_121 ( V_2 , V_160 ) ;
F_98 ( & V_2 -> V_102 ) ;
}
V_2 -> V_77 = V_87 -> V_77 ;
if ( ! F_121 ( V_2 , V_192 ) ) {
if ( ! F_121 ( V_2 , V_123 ) )
goto V_79;
F_99 ( & V_2 -> V_102 ) ;
F_121 ( V_2 , V_160 ) ;
F_98 ( & V_2 -> V_102 ) ;
}
F_47 ( L_80 , V_2 -> V_77 -> V_75 ) ;
if ( V_200 ) {
V_2 -> V_77 = V_200 ;
F_121 ( V_2 , V_192 ) ;
F_121 ( V_2 , V_123 ) ;
}
return - V_71 ;
V_79:
F_47 ( L_81 ) ;
return F_121 ( V_2 , V_124 ) ;
}
int F_165 ( unsigned int V_19 )
{
struct V_1 * V_2 = F_36 ( V_19 ) ;
struct V_1 V_87 ;
int V_36 ;
if ( ! V_2 )
return - V_188 ;
F_98 ( & V_2 -> V_102 ) ;
F_47 ( L_82 , V_19 ) ;
memcpy ( & V_87 , V_2 , sizeof( * V_2 ) ) ;
V_87 . V_149 = V_2 -> V_88 . V_149 ;
V_87 . V_150 = V_2 -> V_88 . V_150 ;
V_87 . V_2 = V_2 -> V_88 . V_2 ;
V_87 . V_77 = V_2 -> V_88 . V_77 ;
if ( V_7 -> V_84 && ! V_7 -> V_80 ) {
V_87 . V_56 = V_7 -> V_84 ( V_19 ) ;
if ( F_37 ( ! V_87 . V_56 ) ) {
V_36 = - V_103 ;
goto V_104;
}
if ( ! V_2 -> V_56 ) {
F_47 ( L_83 ) ;
V_2 -> V_56 = V_87 . V_56 ;
} else {
if ( V_2 -> V_56 != V_87 . V_56 && F_10 () )
F_166 ( V_2 , V_87 . V_56 ) ;
}
}
V_36 = F_82 ( V_2 , & V_87 ) ;
V_104:
F_99 ( & V_2 -> V_102 ) ;
F_43 ( V_2 ) ;
return V_36 ;
}
static int F_193 ( struct V_173 * V_205 ,
unsigned long V_206 , void * V_207 )
{
unsigned int V_19 = ( unsigned long ) V_207 ;
struct V_111 * V_115 ;
V_115 = F_112 ( V_19 ) ;
if ( V_115 ) {
switch ( V_206 & ~ V_208 ) {
case V_209 :
F_144 ( V_115 , NULL ) ;
break;
case V_210 :
F_156 ( V_115 ) ;
break;
case V_211 :
F_159 ( V_115 ) ;
break;
case V_212 :
F_144 ( V_115 , NULL ) ;
break;
}
}
return V_213 ;
}
static int F_194 ( int V_54 )
{
struct V_18 * V_21 ;
struct V_1 * V_2 ;
int V_36 = - V_71 ;
F_173 (policy) {
V_21 = F_17 ( V_2 -> V_19 ) ;
if ( V_21 ) {
V_36 = F_195 ( V_2 ,
V_21 ) ;
if ( V_36 ) {
F_29 ( L_84 ,
V_37 ) ;
break;
}
V_2 -> V_88 . V_150 = V_2 -> V_150 ;
F_121 ( V_2 , V_124 ) ;
}
}
return V_36 ;
}
int F_68 ( int V_54 )
{
unsigned long V_13 ;
int V_36 = 0 ;
if ( V_7 -> V_68 == V_54 )
return 0 ;
F_141 ( & V_42 , V_13 ) ;
V_7 -> V_68 = V_54 ;
F_143 ( & V_42 , V_13 ) ;
V_36 = V_7 -> V_214 ( V_54 ) ;
if ( V_36 ) {
F_141 ( & V_42 , V_13 ) ;
V_7 -> V_68 = ! V_54 ;
F_143 ( & V_42 , V_13 ) ;
F_29 ( L_85 ,
V_37 , V_54 ? L_13 : L_14 ) ;
}
return V_36 ;
}
int F_196 ( void )
{
if ( F_54 ( V_7 ) )
return V_7 -> V_215 ;
return 0 ;
}
int F_197 ( void )
{
return V_7 -> V_68 ;
}
int F_198 ( struct V_7 * V_172 )
{
unsigned long V_13 ;
int V_36 ;
if ( F_13 () )
return - V_188 ;
if ( ! V_172 || ! V_172 -> V_201 || ! V_172 -> V_145 ||
! ( V_172 -> V_80 || V_172 -> V_8 ||
V_172 -> V_9 ) ||
( V_172 -> V_80 && ( V_172 -> V_8 ||
V_172 -> V_9 ) ) ||
( ! ! V_172 -> V_179 != ! ! V_172 -> V_180 ) )
return - V_71 ;
F_47 ( L_86 , V_172 -> V_75 ) ;
F_141 ( & V_42 , V_13 ) ;
if ( V_7 ) {
F_143 ( & V_42 , V_13 ) ;
return - V_216 ;
}
V_7 = V_172 ;
F_143 ( & V_42 , V_13 ) ;
if ( V_172 -> V_80 )
V_172 -> V_13 |= V_48 ;
if ( F_196 () ) {
if ( ! V_7 -> V_214 )
V_7 -> V_214 = F_194 ;
V_36 = F_107 ( & V_217 . V_66 ) ;
if ( V_36 ) {
F_29 ( L_87 ,
V_37 ) ;
goto V_218;
}
}
V_36 = F_199 ( & V_219 ) ;
if ( V_36 )
goto V_220;
if ( ! ( V_7 -> V_13 & V_221 ) &&
F_7 ( & V_6 ) ) {
F_47 ( L_88 , V_37 ,
V_172 -> V_75 ) ;
goto V_222;
}
F_200 ( & V_223 ) ;
F_47 ( L_89 , V_172 -> V_75 ) ;
return 0 ;
V_222:
F_201 ( & V_219 ) ;
V_220:
if ( F_196 () )
F_109 ( & V_217 . V_66 ) ;
V_218:
F_141 ( & V_42 , V_13 ) ;
V_7 = NULL ;
F_143 ( & V_42 , V_13 ) ;
return V_36 ;
}
int F_202 ( struct V_7 * V_224 )
{
unsigned long V_13 ;
if ( ! V_7 || ( V_224 != V_7 ) )
return - V_71 ;
F_47 ( L_90 , V_224 -> V_75 ) ;
F_201 ( & V_219 ) ;
if ( F_196 () )
F_109 ( & V_217 . V_66 ) ;
F_203 ( & V_223 ) ;
F_98 ( & V_41 ) ;
F_141 ( & V_42 , V_13 ) ;
V_7 = NULL ;
F_143 ( & V_42 , V_13 ) ;
F_99 ( & V_41 ) ;
return 0 ;
}
static int T_1 F_204 ( void )
{
if ( F_13 () )
return - V_188 ;
V_17 = F_205 () ;
F_50 ( ! V_17 ) ;
F_206 ( & V_225 ) ;
return 0 ;
}
