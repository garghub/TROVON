static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
extern int V_4 ;
if ( ! F_2 () )
return 0 ;
F_3 (zone)
V_2 ++ ;
V_3 = V_5 * V_2 * 2 ;
V_3 += V_5 * V_2 *
V_6 * V_6 ;
V_3 = F_4 ( V_3 ,
( unsigned long ) F_5 () / 20 ) ;
V_3 <<= ( V_7 - 10 ) ;
if ( V_3 > V_4 )
V_4 = V_3 ;
F_6 () ;
return 0 ;
}
static int F_7 ( void )
{
int V_8 = 0 ;
if ( F_2 () ) {
if ( ! V_9 )
V_9 = F_8 ( V_10 , NULL ,
L_1 ) ;
if ( F_9 ( F_10 ( V_9 ) ) ) {
F_11 ( V_11
L_2 ) ;
V_8 = F_12 ( V_9 ) ;
V_9 = NULL ;
}
if ( ! F_13 ( & V_12 . V_13 ) )
F_14 ( & V_14 ) ;
F_1 () ;
} else if ( V_9 ) {
F_15 ( V_9 ) ;
V_9 = NULL ;
}
return V_8 ;
}
static inline bool F_16 ( unsigned long V_15 )
{
unsigned long V_16 = F_17 ( V_17 ) ;
return V_16 && V_15 == V_16 ;
}
static inline bool F_18 ( T_1 V_18 )
{
return F_16 ( F_19 ( V_18 ) ) ;
}
static unsigned long F_20 ( void )
{
struct V_19 * V_20 ;
V_21:
if ( F_21 ( F_22 ( & V_22 ) ) )
return F_17 ( V_17 ) ;
V_20 = F_23 ( ( V_23 | V_24 ) & ~ V_25 ,
V_26 ) ;
if ( ! V_20 ) {
F_24 ( V_27 ) ;
return 0 ;
}
F_24 ( V_28 ) ;
F_25 () ;
if ( F_26 ( & V_17 , 0 , F_27 ( V_20 ) ) ) {
F_28 () ;
F_29 ( V_20 ) ;
goto V_21;
}
F_30 ( & V_22 , 2 ) ;
F_28 () ;
return F_17 ( V_17 ) ;
}
static void F_31 ( void )
{
F_32 ( F_33 ( & V_22 ) ) ;
}
static int F_34 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
if ( ! V_32 -> V_33 )
return F_35 ( & V_22 ) == 1 ? V_34 : 0 ;
if ( F_36 ( & V_22 , 1 , 0 ) == 1 ) {
unsigned long V_16 = F_37 ( & V_17 , 0 ) ;
F_32 ( V_16 == 0 ) ;
F_29 ( F_38 ( V_16 ) ) ;
}
return 0 ;
}
static T_2 F_39 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 ,
enum V_40 V_41 ,
enum V_40 V_42 )
{
if ( F_40 ( V_41 , & V_43 ) ) {
F_41 ( F_40 ( V_42 , & V_43 ) ) ;
return sprintf ( V_39 , L_3 ) ;
} else if ( F_40 ( V_42 , & V_43 ) )
return sprintf ( V_39 , L_4 ) ;
else
return sprintf ( V_39 , L_5 ) ;
}
static T_2 F_42 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 ,
enum V_40 V_41 ,
enum V_40 V_42 )
{
if ( ! memcmp ( L_6 , V_39 ,
F_4 ( sizeof( L_6 ) - 1 , V_44 ) ) ) {
F_43 ( V_41 , & V_43 ) ;
F_44 ( V_42 , & V_43 ) ;
} else if ( ! memcmp ( L_7 , V_39 ,
F_4 ( sizeof( L_7 ) - 1 , V_44 ) ) ) {
F_44 ( V_41 , & V_43 ) ;
F_43 ( V_42 , & V_43 ) ;
} else if ( ! memcmp ( L_8 , V_39 ,
F_4 ( sizeof( L_8 ) - 1 , V_44 ) ) ) {
F_44 ( V_41 , & V_43 ) ;
F_44 ( V_42 , & V_43 ) ;
} else
return - V_45 ;
return V_44 ;
}
static T_2 F_45 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return F_39 ( V_36 , V_38 , V_39 ,
V_46 ,
V_47 ) ;
}
static T_2 F_46 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
T_2 V_48 ;
V_48 = F_42 ( V_36 , V_38 , V_39 , V_44 ,
V_46 ,
V_47 ) ;
if ( V_48 > 0 ) {
int V_8 ;
F_47 ( & V_49 ) ;
V_8 = F_7 () ;
F_48 ( & V_49 ) ;
if ( V_8 )
V_48 = V_8 ;
}
return V_48 ;
}
static T_2 F_49 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 ,
enum V_40 V_50 )
{
return sprintf ( V_39 , L_9 ,
! ! F_40 ( V_50 , & V_43 ) ) ;
}
static T_2 F_50 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 ,
enum V_40 V_50 )
{
unsigned long V_51 ;
int V_48 ;
V_48 = F_51 ( V_39 , 10 , & V_51 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_51 > 1 )
return - V_45 ;
if ( V_51 )
F_43 ( V_50 , & V_43 ) ;
else
F_44 ( V_50 , & V_43 ) ;
return V_44 ;
}
static T_2 F_52 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return F_39 ( V_36 , V_38 , V_39 ,
V_52 ,
V_53 ) ;
}
static T_2 F_53 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
return F_42 ( V_36 , V_38 , V_39 , V_44 ,
V_52 ,
V_53 ) ;
}
static T_2 F_54 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return F_49 ( V_36 , V_38 , V_39 ,
V_54 ) ;
}
static T_2 F_55 ( struct V_35 * V_36 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_44 )
{
return F_50 ( V_36 , V_38 , V_39 , V_44 ,
V_54 ) ;
}
static T_2 F_56 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return F_49 ( V_36 , V_38 , V_39 ,
V_55 ) ;
}
static T_2 F_57 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
return F_50 ( V_36 , V_38 , V_39 , V_44 ,
V_55 ) ;
}
static T_2 F_58 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_56 ) ;
}
static T_2 F_59 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
unsigned long V_57 ;
int V_8 ;
V_8 = F_60 ( V_39 , 10 , & V_57 ) ;
if ( V_8 || V_57 > V_58 )
return - V_45 ;
V_56 = V_57 ;
F_14 ( & V_14 ) ;
return V_44 ;
}
static T_2 F_61 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_59 ) ;
}
static T_2 F_62 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
unsigned long V_57 ;
int V_8 ;
V_8 = F_60 ( V_39 , 10 , & V_57 ) ;
if ( V_8 || V_57 > V_58 )
return - V_45 ;
V_59 = V_57 ;
F_14 ( & V_14 ) ;
return V_44 ;
}
static T_2 F_63 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_60 ) ;
}
static T_2 F_64 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
int V_8 ;
unsigned long V_61 ;
V_8 = F_60 ( V_39 , 10 , & V_61 ) ;
if ( V_8 || ! V_61 || V_61 > V_58 )
return - V_45 ;
V_60 = V_61 ;
return V_44 ;
}
static T_2 F_65 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_62 ) ;
}
static T_2 F_66 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_63 ) ;
}
static T_2 F_67 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return F_49 ( V_36 , V_38 , V_39 ,
V_64 ) ;
}
static T_2 F_68 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
return F_50 ( V_36 , V_38 , V_39 , V_44 ,
V_64 ) ;
}
static T_2 F_69 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
return sprintf ( V_39 , L_10 , V_65 ) ;
}
static T_2 F_70 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_44 )
{
int V_8 ;
unsigned long V_66 ;
V_8 = F_60 ( V_39 , 10 , & V_66 ) ;
if ( V_8 || V_66 > V_34 - 1 )
return - V_45 ;
V_65 = V_66 ;
return V_44 ;
}
static int T_4 F_71 ( struct V_35 * * V_67 )
{
int V_8 ;
* V_67 = F_72 ( L_11 , V_68 ) ;
if ( F_9 ( ! * V_67 ) ) {
F_11 ( V_11 L_12 ) ;
return - V_69 ;
}
V_8 = F_73 ( * V_67 , & V_70 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_71;
}
V_8 = F_73 ( * V_67 , & V_72 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_73;
}
return 0 ;
V_73:
F_74 ( * V_67 , & V_70 ) ;
V_71:
F_75 ( * V_67 ) ;
return V_8 ;
}
static void T_4 F_76 ( struct V_35 * V_67 )
{
F_74 ( V_67 , & V_72 ) ;
F_74 ( V_67 , & V_70 ) ;
F_75 ( V_67 ) ;
}
static inline int F_71 ( struct V_35 * * V_67 )
{
return 0 ;
}
static inline void F_76 ( struct V_35 * V_67 )
{
}
static int T_4 F_77 ( void )
{
int V_8 ;
struct V_35 * V_67 ;
if ( ! F_78 () ) {
V_43 = 0 ;
return - V_45 ;
}
V_8 = F_71 ( & V_67 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_79 () ;
if ( V_8 )
goto V_74;
V_8 = F_80 () ;
if ( V_8 ) {
F_81 () ;
goto V_74;
}
F_82 ( & V_75 ) ;
if ( V_76 < ( 512 << ( 20 - V_7 ) ) )
V_43 = 0 ;
F_7 () ;
return 0 ;
V_74:
F_76 ( V_67 ) ;
return V_8 ;
}
static int T_4 F_83 ( char * V_77 )
{
int V_48 = 0 ;
if ( ! V_77 )
goto V_74;
if ( ! strcmp ( V_77 , L_6 ) ) {
F_43 ( V_46 ,
& V_43 ) ;
F_44 ( V_47 ,
& V_43 ) ;
V_48 = 1 ;
} else if ( ! strcmp ( V_77 , L_7 ) ) {
F_44 ( V_46 ,
& V_43 ) ;
F_43 ( V_47 ,
& V_43 ) ;
V_48 = 1 ;
} else if ( ! strcmp ( V_77 , L_8 ) ) {
F_44 ( V_46 ,
& V_43 ) ;
F_44 ( V_47 ,
& V_43 ) ;
V_48 = 1 ;
}
V_74:
if ( ! V_48 )
F_11 ( V_78
L_14 ) ;
return V_48 ;
}
T_1 F_84 ( T_1 V_18 , struct V_79 * V_80 )
{
if ( F_21 ( V_80 -> V_81 & V_82 ) )
V_18 = F_85 ( V_18 ) ;
return V_18 ;
}
static inline T_1 F_86 ( struct V_19 * V_19 , struct V_79 * V_80 )
{
T_1 V_83 ;
V_83 = F_87 ( V_19 , V_80 -> V_84 ) ;
V_83 = F_84 ( F_88 ( V_83 ) , V_80 ) ;
V_83 = F_89 ( V_83 ) ;
return V_83 ;
}
static int F_90 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_87 , T_1 * V_18 ,
struct V_19 * V_19 )
{
T_5 V_88 ;
F_41 ( ! F_91 ( V_19 ) ) ;
V_88 = F_92 ( V_86 , V_87 ) ;
if ( F_9 ( ! V_88 ) )
return V_89 ;
F_93 ( V_19 , V_87 , V_34 ) ;
F_94 ( V_19 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_96 ( * V_18 ) ) ) {
F_97 ( & V_86 -> V_90 ) ;
F_98 ( V_19 ) ;
F_99 ( V_19 ) ;
F_100 ( V_86 , V_88 ) ;
} else {
T_1 V_83 ;
V_83 = F_86 ( V_19 , V_80 ) ;
F_101 ( V_19 , V_80 , V_87 ) ;
F_102 ( V_86 , V_87 , V_18 , V_83 ) ;
F_103 ( V_86 , V_88 ) ;
F_104 ( V_86 , V_91 , V_34 ) ;
V_86 -> V_92 ++ ;
F_97 ( & V_86 -> V_90 ) ;
}
return 0 ;
}
static inline T_6 F_105 ( int V_93 , T_6 V_94 )
{
return ( V_23 & ~ ( V_93 ? 0 : V_95 ) ) | V_94 ;
}
static inline struct V_19 * F_106 ( int V_93 ,
struct V_79 * V_80 ,
unsigned long V_87 , int V_96 ,
T_6 V_94 )
{
return F_107 ( F_105 ( V_93 , V_94 ) ,
V_26 , V_80 , V_87 , V_96 ) ;
}
static inline struct V_19 * F_108 ( int V_93 )
{
return F_23 ( F_105 ( V_93 , 0 ) ,
V_26 ) ;
}
static bool F_109 ( T_5 V_88 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_87 , T_1 * V_18 ,
unsigned long V_16 )
{
T_1 V_83 ;
if ( ! F_96 ( * V_18 ) )
return false ;
V_83 = F_110 ( V_16 , V_80 -> V_84 ) ;
V_83 = F_111 ( V_83 ) ;
V_83 = F_89 ( V_83 ) ;
F_102 ( V_86 , V_87 , V_18 , V_83 ) ;
F_103 ( V_86 , V_88 ) ;
V_86 -> V_92 ++ ;
return true ;
}
int F_112 ( struct V_85 * V_86 , struct V_79 * V_80 ,
unsigned long V_97 , T_1 * V_18 ,
unsigned int V_98 )
{
struct V_19 * V_19 ;
unsigned long V_87 = V_97 & V_99 ;
T_7 * V_100 ;
if ( V_87 >= V_80 -> V_101 && V_87 + V_102 <= V_80 -> V_103 ) {
if ( F_9 ( F_113 ( V_80 ) ) )
return V_89 ;
if ( F_9 ( F_114 ( V_80 ) ) )
return V_89 ;
if ( ! ( V_98 & V_104 ) &&
F_115 () ) {
T_5 V_88 ;
unsigned long V_16 ;
bool V_105 ;
V_88 = F_92 ( V_86 , V_87 ) ;
if ( F_9 ( ! V_88 ) )
return V_89 ;
V_16 = F_20 () ;
if ( F_9 ( ! V_16 ) ) {
F_100 ( V_86 , V_88 ) ;
F_24 ( V_106 ) ;
goto V_74;
}
F_95 ( & V_86 -> V_90 ) ;
V_105 = F_109 ( V_88 , V_86 , V_80 , V_87 , V_18 ,
V_16 ) ;
F_97 ( & V_86 -> V_90 ) ;
if ( ! V_105 ) {
F_100 ( V_86 , V_88 ) ;
F_31 () ;
}
return 0 ;
}
V_19 = F_106 ( F_116 ( V_80 ) ,
V_80 , V_87 , F_117 () , 0 ) ;
if ( F_9 ( ! V_19 ) ) {
F_24 ( V_106 ) ;
goto V_74;
}
F_24 ( V_107 ) ;
if ( F_9 ( F_118 ( V_19 , V_86 , V_108 ) ) ) {
F_99 ( V_19 ) ;
goto V_74;
}
if ( F_9 ( F_90 ( V_86 , V_80 , V_87 , V_18 ,
V_19 ) ) ) {
F_98 ( V_19 ) ;
F_99 ( V_19 ) ;
goto V_74;
}
return 0 ;
}
V_74:
if ( F_9 ( F_96 ( * V_18 ) ) &&
F_9 ( F_119 ( V_86 , V_80 , V_18 , V_97 ) ) )
return V_89 ;
if ( F_9 ( F_120 ( * V_18 ) ) )
return 0 ;
V_100 = F_121 ( V_18 , V_97 ) ;
return F_122 ( V_86 , V_80 , V_97 , V_100 , V_18 , V_98 ) ;
}
int F_123 ( struct V_85 * V_109 , struct V_85 * V_110 ,
T_1 * V_111 , T_1 * V_112 , unsigned long V_113 ,
struct V_79 * V_80 )
{
struct V_19 * V_114 ;
T_1 V_18 ;
T_5 V_88 ;
int V_48 ;
V_48 = - V_69 ;
V_88 = F_92 ( V_109 , V_113 ) ;
if ( F_9 ( ! V_88 ) )
goto V_74;
F_95 ( & V_109 -> V_90 ) ;
F_124 ( & V_110 -> V_90 , V_115 ) ;
V_48 = - V_116 ;
V_18 = * V_112 ;
if ( F_9 ( ! F_120 ( V_18 ) ) ) {
F_100 ( V_109 , V_88 ) ;
goto V_117;
}
if ( F_18 ( V_18 ) ) {
unsigned long V_16 ;
bool V_105 ;
V_16 = F_20 () ;
V_105 = F_109 ( V_88 , V_109 , V_80 , V_113 , V_111 ,
V_16 ) ;
F_32 ( ! V_105 ) ;
V_48 = 0 ;
goto V_117;
}
if ( F_9 ( F_125 ( V_18 ) ) ) {
F_97 ( & V_110 -> V_90 ) ;
F_97 ( & V_109 -> V_90 ) ;
F_100 ( V_109 , V_88 ) ;
F_126 ( V_80 -> V_118 , V_112 ) ;
goto V_74;
}
V_114 = F_127 ( V_18 ) ;
F_41 ( ! F_128 ( V_114 ) ) ;
F_129 ( V_114 ) ;
F_130 ( V_114 ) ;
F_104 ( V_109 , V_91 , V_34 ) ;
F_131 ( V_110 , V_113 , V_112 ) ;
V_18 = F_132 ( F_111 ( V_18 ) ) ;
F_102 ( V_109 , V_113 , V_111 , V_18 ) ;
F_103 ( V_109 , V_88 ) ;
V_109 -> V_92 ++ ;
V_48 = 0 ;
V_117:
F_97 ( & V_110 -> V_90 ) ;
F_97 ( & V_109 -> V_90 ) ;
V_74:
return V_48 ;
}
void F_133 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
T_1 * V_18 , T_1 V_119 ,
int V_120 )
{
T_1 V_83 ;
unsigned long V_87 ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( * V_18 , V_119 ) ) )
goto V_121;
V_83 = F_135 ( V_119 ) ;
V_87 = V_97 & V_99 ;
if ( F_136 ( V_80 , V_87 , V_18 , V_83 , V_120 ) )
F_137 ( V_80 , V_97 , V_18 ) ;
V_121:
F_97 ( & V_86 -> V_90 ) ;
}
static int F_138 ( struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
T_1 * V_18 , T_1 V_119 , unsigned long V_87 )
{
T_5 V_88 ;
T_1 V_122 ;
struct V_19 * V_19 ;
int V_123 , V_48 = 0 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_19 = F_139 ( V_126 , V_80 , V_97 ) ;
if ( ! V_19 ) {
V_48 |= V_89 ;
goto V_74;
}
if ( F_118 ( V_19 , V_86 , V_108 ) ) {
F_99 ( V_19 ) ;
V_48 |= V_89 ;
goto V_74;
}
F_140 ( V_19 , V_97 ) ;
F_94 ( V_19 ) ;
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( * V_18 , V_119 ) ) )
goto V_127;
F_142 ( V_80 , V_87 , V_18 ) ;
V_88 = F_143 ( V_86 ) ;
F_144 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
if ( V_87 == ( V_97 & V_129 ) ) {
V_83 = F_145 ( V_19 , V_80 -> V_84 ) ;
V_83 = F_146 ( F_147 ( V_83 ) , V_80 ) ;
F_101 ( V_19 , V_80 , V_87 ) ;
} else {
V_83 = F_148 ( F_149 ( V_87 ) , V_80 -> V_84 ) ;
V_83 = F_150 ( V_83 ) ;
}
V_100 = F_121 ( & V_122 , V_87 ) ;
F_41 ( ! F_151 ( * V_100 ) ) ;
F_152 ( V_86 , V_87 , V_100 , V_83 ) ;
F_153 ( V_100 ) ;
}
F_154 () ;
F_144 ( V_86 , V_18 , V_88 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_31 () ;
F_155 ( V_86 , V_91 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
V_48 |= V_130 ;
V_74:
return V_48 ;
V_127:
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
F_98 ( V_19 ) ;
F_99 ( V_19 ) ;
goto V_74;
}
static int F_157 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
T_1 * V_18 , T_1 V_119 ,
struct V_19 * V_19 ,
unsigned long V_87 )
{
T_5 V_88 ;
T_1 V_122 ;
int V_48 = 0 , V_123 ;
struct V_19 * * V_61 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_61 = F_158 ( sizeof( struct V_19 * ) * V_34 ,
V_108 ) ;
if ( F_9 ( ! V_61 ) ) {
V_48 |= V_89 ;
goto V_74;
}
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
V_61 [ V_123 ] = F_159 ( V_126 |
V_131 ,
V_80 , V_97 , F_160 ( V_19 ) ) ;
if ( F_9 ( ! V_61 [ V_123 ] ||
F_118 ( V_61 [ V_123 ] , V_86 ,
V_108 ) ) ) {
if ( V_61 [ V_123 ] )
F_99 ( V_61 [ V_123 ] ) ;
F_161 () ;
while ( -- V_123 >= 0 ) {
F_98 ( V_61 [ V_123 ] ) ;
F_99 ( V_61 [ V_123 ] ) ;
}
F_162 () ;
F_163 ( V_61 ) ;
V_48 |= V_89 ;
goto V_74;
}
}
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
F_164 ( V_61 [ V_123 ] , V_19 + V_123 ,
V_87 + V_128 * V_123 , V_80 ) ;
F_94 ( V_61 [ V_123 ] ) ;
F_165 () ;
}
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( * V_18 , V_119 ) ) )
goto V_132;
F_41 ( ! F_128 ( V_19 ) ) ;
F_142 ( V_80 , V_87 , V_18 ) ;
V_88 = F_143 ( V_86 ) ;
F_144 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
V_83 = F_145 ( V_61 [ V_123 ] , V_80 -> V_84 ) ;
V_83 = F_146 ( F_147 ( V_83 ) , V_80 ) ;
F_101 ( V_61 [ V_123 ] , V_80 , V_87 ) ;
V_100 = F_121 ( & V_122 , V_87 ) ;
F_41 ( ! F_151 ( * V_100 ) ) ;
F_152 ( V_86 , V_87 , V_100 , V_83 ) ;
F_153 ( V_100 ) ;
}
F_163 ( V_61 ) ;
F_154 () ;
F_144 ( V_86 , V_18 , V_88 ) ;
F_166 ( V_19 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
V_48 |= V_130 ;
F_99 ( V_19 ) ;
V_74:
return V_48 ;
V_132:
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
F_161 () ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
F_98 ( V_61 [ V_123 ] ) ;
F_99 ( V_61 [ V_123 ] ) ;
}
F_162 () ;
F_163 ( V_61 ) ;
goto V_74;
}
int F_167 ( struct V_85 * V_86 , struct V_79 * V_80 ,
unsigned long V_97 , T_1 * V_18 , T_1 V_119 )
{
int V_48 = 0 ;
struct V_19 * V_19 = NULL , * V_133 ;
unsigned long V_87 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_41 ( ! V_80 -> V_118 ) ;
V_87 = V_97 & V_99 ;
if ( F_18 ( V_119 ) )
goto V_134;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( * V_18 , V_119 ) ) )
goto V_117;
V_19 = F_127 ( V_119 ) ;
F_41 ( ! F_91 ( V_19 ) || ! F_128 ( V_19 ) ) ;
if ( F_168 ( V_19 ) == 1 ) {
T_1 V_83 ;
V_83 = F_135 ( V_119 ) ;
V_83 = F_84 ( F_88 ( V_83 ) , V_80 ) ;
if ( F_136 ( V_80 , V_87 , V_18 , V_83 , 1 ) )
F_137 ( V_80 , V_97 , V_18 ) ;
V_48 |= V_130 ;
goto V_117;
}
F_129 ( V_19 ) ;
F_97 ( & V_86 -> V_90 ) ;
V_134:
if ( F_169 ( V_80 ) &&
! F_170 () )
V_133 = F_106 ( F_116 ( V_80 ) ,
V_80 , V_87 , F_117 () , 0 ) ;
else
V_133 = NULL ;
if ( F_9 ( ! V_133 ) ) {
F_24 ( V_106 ) ;
if ( F_18 ( V_119 ) ) {
V_48 = F_138 ( V_86 , V_80 ,
V_97 , V_18 , V_119 , V_87 ) ;
} else {
V_48 = F_157 ( V_86 , V_80 , V_97 ,
V_18 , V_119 , V_19 , V_87 ) ;
if ( V_48 & V_89 )
F_171 ( V_19 ) ;
F_99 ( V_19 ) ;
}
goto V_74;
}
F_24 ( V_107 ) ;
if ( F_9 ( F_118 ( V_133 , V_86 , V_108 ) ) ) {
F_99 ( V_133 ) ;
if ( V_19 ) {
F_171 ( V_19 ) ;
F_99 ( V_19 ) ;
}
V_48 |= V_89 ;
goto V_74;
}
if ( F_18 ( V_119 ) )
F_93 ( V_133 , V_87 , V_34 ) ;
else
F_172 ( V_133 , V_19 , V_87 , V_80 , V_34 ) ;
F_94 ( V_133 ) ;
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( V_19 )
F_99 ( V_19 ) ;
if ( F_9 ( ! F_134 ( * V_18 , V_119 ) ) ) {
F_97 ( & V_86 -> V_90 ) ;
F_98 ( V_133 ) ;
F_99 ( V_133 ) ;
goto V_135;
} else {
T_1 V_83 ;
V_83 = F_86 ( V_133 , V_80 ) ;
F_142 ( V_80 , V_87 , V_18 ) ;
F_101 ( V_133 , V_80 , V_87 ) ;
F_102 ( V_86 , V_87 , V_18 , V_83 ) ;
F_137 ( V_80 , V_97 , V_18 ) ;
if ( F_18 ( V_119 ) ) {
F_104 ( V_86 , V_91 , V_34 ) ;
F_31 () ;
} else {
F_41 ( ! F_128 ( V_19 ) ) ;
F_166 ( V_19 ) ;
F_99 ( V_19 ) ;
}
V_48 |= V_130 ;
}
F_97 ( & V_86 -> V_90 ) ;
V_135:
F_156 ( V_86 , V_124 , V_125 ) ;
V_74:
return V_48 ;
V_117:
F_97 ( & V_86 -> V_90 ) ;
return V_48 ;
}
struct V_19 * F_173 ( struct V_79 * V_80 ,
unsigned long V_113 ,
T_1 * V_18 ,
unsigned int V_98 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
struct V_19 * V_19 = NULL ;
F_174 ( & V_86 -> V_90 ) ;
if ( V_98 & V_137 && ! F_175 ( * V_18 ) )
goto V_74;
if ( ( V_98 & V_138 ) && F_18 ( * V_18 ) )
return F_176 ( - V_139 ) ;
V_19 = F_127 ( * V_18 ) ;
F_41 ( ! F_128 ( V_19 ) ) ;
if ( V_98 & V_140 ) {
T_1 V_122 ;
V_122 = F_135 ( F_88 ( * V_18 ) ) ;
F_102 ( V_86 , V_113 & V_99 , V_18 , V_122 ) ;
}
if ( ( V_98 & V_141 ) && ( V_80 -> V_81 & V_142 ) ) {
if ( V_19 -> V_143 && F_177 ( V_19 ) ) {
F_178 () ;
if ( V_19 -> V_143 )
F_179 ( V_19 ) ;
F_180 ( V_19 ) ;
}
}
V_19 += ( V_113 & ~ V_99 ) >> V_7 ;
F_41 ( ! F_91 ( V_19 ) ) ;
if ( V_98 & V_144 )
F_181 ( V_19 ) ;
V_74:
return V_19 ;
}
int F_182 ( struct V_85 * V_86 , struct V_79 * V_80 ,
unsigned long V_113 , T_1 V_18 , T_1 * V_145 )
{
struct V_19 * V_19 ;
unsigned long V_87 = V_113 & V_99 ;
int V_146 ;
int V_147 = - 1 ;
bool V_148 ;
bool V_149 = false ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( V_18 , * V_145 ) ) )
goto V_117;
V_19 = F_127 ( V_18 ) ;
F_129 ( V_19 ) ;
V_147 = F_160 ( V_19 ) ;
F_183 ( V_150 ) ;
if ( V_147 == F_117 () )
F_183 ( V_151 ) ;
V_146 = F_184 ( V_19 , V_80 , V_87 ) ;
if ( V_146 == - 1 ) {
F_99 ( V_19 ) ;
goto V_152;
}
F_97 ( & V_86 -> V_90 ) ;
F_185 ( V_19 ) ;
V_149 = true ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( V_18 , * V_145 ) ) ) {
F_180 ( V_19 ) ;
F_99 ( V_19 ) ;
goto V_117;
}
F_97 ( & V_86 -> V_90 ) ;
V_148 = F_186 ( V_86 , V_80 ,
V_145 , V_18 , V_113 ,
V_19 , V_146 ) ;
if ( V_148 )
V_147 = V_146 ;
else {
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_134 ( V_18 , * V_145 ) ) ) {
F_180 ( V_19 ) ;
goto V_117;
}
goto V_152;
}
F_187 ( V_147 , V_34 , V_148 ) ;
return 0 ;
V_152:
V_18 = F_188 ( V_18 ) ;
F_102 ( V_86 , V_87 , V_145 , V_18 ) ;
F_41 ( F_189 ( * V_145 ) ) ;
F_137 ( V_80 , V_113 , V_145 ) ;
if ( V_149 )
F_180 ( V_19 ) ;
V_117:
F_97 ( & V_86 -> V_90 ) ;
if ( V_147 != - 1 )
F_187 ( V_147 , V_34 , V_148 ) ;
return 0 ;
}
int F_190 ( struct V_153 * V_154 , struct V_79 * V_80 ,
T_1 * V_18 , unsigned long V_113 )
{
int V_48 = 0 ;
if ( F_191 ( V_18 , V_80 ) == 1 ) {
struct V_19 * V_19 ;
T_5 V_88 ;
T_1 V_119 ;
V_88 = F_143 ( V_154 -> V_86 ) ;
V_119 = F_192 ( V_154 -> V_86 , V_113 , V_18 ) ;
F_193 ( V_154 , V_18 , V_113 ) ;
if ( F_18 ( V_119 ) ) {
V_154 -> V_86 -> V_92 -- ;
F_97 ( & V_154 -> V_86 -> V_90 ) ;
F_31 () ;
} else {
V_19 = F_127 ( V_119 ) ;
F_166 ( V_19 ) ;
F_41 ( F_168 ( V_19 ) < 0 ) ;
F_104 ( V_154 -> V_86 , V_91 , - V_34 ) ;
F_41 ( ! F_128 ( V_19 ) ) ;
V_154 -> V_86 -> V_92 -- ;
F_97 ( & V_154 -> V_86 -> V_90 ) ;
F_194 ( V_154 , V_19 ) ;
}
F_100 ( V_154 -> V_86 , V_88 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_195 ( struct V_79 * V_80 , T_1 * V_18 ,
unsigned long V_113 , unsigned long V_155 ,
unsigned char * V_156 )
{
int V_48 = 0 ;
if ( F_191 ( V_18 , V_80 ) == 1 ) {
F_97 ( & V_80 -> V_136 -> V_90 ) ;
memset ( V_156 , 1 , ( V_155 - V_113 ) >> V_7 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_196 ( struct V_79 * V_80 , struct V_79 * V_157 ,
unsigned long V_158 ,
unsigned long V_159 , unsigned long V_160 ,
T_1 * V_161 , T_1 * V_162 )
{
int V_48 = 0 ;
T_1 V_18 ;
struct V_85 * V_86 = V_80 -> V_136 ;
if ( ( V_158 & ~ V_99 ) ||
( V_159 & ~ V_99 ) ||
V_160 - V_158 < V_102 ||
( V_157 -> V_81 & V_163 ) )
goto V_74;
if ( F_197 ( ! F_96 ( * V_162 ) ) ) {
F_41 ( F_120 ( * V_162 ) ) ;
goto V_74;
}
V_48 = F_191 ( V_161 , V_80 ) ;
if ( V_48 == 1 ) {
V_18 = F_192 ( V_86 , V_158 , V_161 ) ;
F_41 ( ! F_96 ( * V_162 ) ) ;
F_102 ( V_86 , V_159 , V_162 , V_18 ) ;
F_97 ( & V_86 -> V_90 ) ;
}
V_74:
return V_48 ;
}
int F_198 ( struct V_79 * V_80 , T_1 * V_18 ,
unsigned long V_113 , T_8 V_164 , int V_165 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
int V_48 = 0 ;
if ( F_191 ( V_18 , V_80 ) == 1 ) {
T_1 V_83 ;
V_83 = F_192 ( V_86 , V_113 , V_18 ) ;
if ( ! V_165 ) {
V_83 = F_199 ( V_83 , V_164 ) ;
F_32 ( F_175 ( V_83 ) ) ;
} else {
struct V_19 * V_19 = F_127 ( * V_18 ) ;
if ( F_168 ( V_19 ) == 1 &&
! F_189 ( * V_18 ) ) {
V_83 = F_200 ( V_83 ) ;
}
}
F_102 ( V_86 , V_113 , V_18 , V_83 ) ;
F_97 ( & V_80 -> V_136 -> V_90 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_191 ( T_1 * V_18 , struct V_79 * V_80 )
{
F_95 ( & V_80 -> V_136 -> V_90 ) ;
if ( F_21 ( F_120 ( * V_18 ) ) ) {
if ( F_9 ( F_125 ( * V_18 ) ) ) {
F_97 ( & V_80 -> V_136 -> V_90 ) ;
F_126 ( V_80 -> V_118 , V_18 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_97 ( & V_80 -> V_136 -> V_90 ) ;
return 0 ;
}
T_1 * F_201 ( struct V_19 * V_19 ,
struct V_85 * V_86 ,
unsigned long V_97 ,
enum V_166 V_50 )
{
T_1 * V_18 , * V_48 = NULL ;
if ( V_97 & ~ V_99 )
goto V_74;
V_18 = F_202 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_96 ( * V_18 ) )
goto V_74;
if ( F_127 ( * V_18 ) != V_19 )
goto V_74;
if ( V_50 == V_167 &&
F_125 ( * V_18 ) )
goto V_74;
if ( F_120 ( * V_18 ) ) {
F_41 ( V_50 == V_168 &&
! F_125 ( * V_18 ) ) ;
V_48 = V_18 ;
}
V_74:
return V_48 ;
}
static int F_203 ( struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_1 * V_18 ;
int V_48 = 0 ;
const unsigned long V_124 = V_97 ;
const unsigned long V_125 = V_97 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
V_18 = F_201 ( V_19 , V_86 , V_97 ,
V_167 ) ;
if ( V_18 ) {
F_204 ( V_80 , V_97 , V_18 ) ;
V_48 = 1 ;
}
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
return V_48 ;
}
static void F_205 ( struct V_19 * V_19 )
{
int V_123 ;
struct V_1 * V_1 = F_206 ( V_19 ) ;
struct V_169 * V_169 ;
int V_170 = 0 ;
F_207 ( & V_1 -> V_171 ) ;
V_169 = F_208 ( V_19 , V_1 ) ;
F_209 ( V_19 ) ;
F_210 ( V_19 ) ;
for ( V_123 = V_34 - 1 ; V_123 >= 1 ; V_123 -- ) {
struct V_19 * V_172 = V_19 + V_123 ;
F_32 ( F_168 ( V_172 ) < 0 ) ;
V_170 += F_168 ( V_172 ) ;
F_32 ( V_170 < 0 ) ;
F_32 ( F_35 ( & V_172 -> V_173 ) != 0 ) ;
F_211 ( F_168 ( V_19 ) + F_168 ( V_172 ) + 1 ,
& V_172 -> V_173 ) ;
F_212 () ;
V_172 -> V_98 &= ~ V_174 | V_175 ;
V_172 -> V_98 |= ( V_19 -> V_98 &
( ( 1L << V_176 ) |
( 1L << V_177 ) |
( 1L << V_178 ) |
( 1L << V_179 ) ) ) ;
V_172 -> V_98 |= ( 1L << V_180 ) ;
F_154 () ;
V_172 -> V_181 = V_19 -> V_181 ;
F_32 ( V_172 -> V_143 ) ;
V_172 -> V_143 = V_19 -> V_143 ;
V_172 -> V_182 = V_19 -> V_182 + V_123 ;
F_213 ( V_172 , F_214 ( V_19 ) ) ;
F_32 ( ! F_215 ( V_172 ) ) ;
F_32 ( ! F_216 ( V_172 ) ) ;
F_32 ( ! F_217 ( V_172 ) ) ;
F_32 ( ! F_218 ( V_172 ) ) ;
F_219 ( V_19 , V_172 , V_169 ) ;
}
F_220 ( V_170 , & V_19 -> V_173 ) ;
F_32 ( F_35 ( & V_19 -> V_173 ) <= 0 ) ;
F_221 ( V_1 , V_183 , - 1 ) ;
F_221 ( V_1 , V_184 , V_34 ) ;
F_222 ( V_19 ) ;
F_223 ( V_19 ) ;
F_224 ( & V_1 -> V_171 ) ;
for ( V_123 = 1 ; V_123 < V_34 ; V_123 ++ ) {
struct V_19 * V_172 = V_19 + V_123 ;
F_32 ( F_225 ( V_172 ) <= 0 ) ;
F_99 ( V_172 ) ;
}
F_32 ( F_225 ( V_19 ) <= 0 ) ;
}
static int F_226 ( struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_1 * V_18 , V_122 ;
int V_48 = 0 , V_123 ;
T_5 V_88 ;
unsigned long V_87 ;
F_95 ( & V_86 -> V_90 ) ;
V_18 = F_201 ( V_19 , V_86 , V_97 ,
V_168 ) ;
if ( V_18 ) {
V_88 = F_143 ( V_86 ) ;
F_144 ( V_86 , & V_122 , V_88 ) ;
V_87 = V_97 ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
F_32 ( F_91 ( V_19 + V_123 ) ) ;
V_83 = F_145 ( V_19 + V_123 , V_80 -> V_84 ) ;
V_83 = F_146 ( F_147 ( V_83 ) , V_80 ) ;
if ( ! F_175 ( * V_18 ) )
V_83 = F_227 ( V_83 ) ;
else
F_32 ( F_168 ( V_19 ) != 1 ) ;
if ( ! F_228 ( * V_18 ) )
V_83 = F_229 ( V_83 ) ;
if ( F_189 ( * V_18 ) )
V_83 = F_230 ( V_83 ) ;
V_100 = F_121 ( & V_122 , V_87 ) ;
F_32 ( ! F_151 ( * V_100 ) ) ;
F_152 ( V_86 , V_87 , V_100 , V_83 ) ;
F_153 ( V_100 ) ;
}
F_154 () ;
F_231 ( V_80 , V_97 , V_18 ) ;
F_144 ( V_86 , V_18 , V_88 ) ;
V_48 = 1 ;
}
F_97 ( & V_86 -> V_90 ) ;
return V_48 ;
}
static void F_232 ( struct V_19 * V_19 ,
struct V_118 * V_118 )
{
int V_185 , V_186 ;
T_9 V_187 = V_19 -> V_182 << ( V_188 - V_7 ) ;
struct V_189 * V_190 ;
F_32 ( ! F_128 ( V_19 ) ) ;
F_32 ( F_233 ( V_19 ) ) ;
V_185 = 0 ;
F_234 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_79 * V_80 = V_190 -> V_80 ;
unsigned long V_113 = F_235 ( V_19 , V_80 ) ;
F_32 ( F_236 ( V_80 ) ) ;
V_185 += F_203 ( V_19 , V_80 , V_113 ) ;
}
if ( V_185 != F_168 ( V_19 ) )
F_11 ( V_11 L_15 ,
V_185 , F_168 ( V_19 ) ) ;
F_32 ( V_185 != F_168 ( V_19 ) ) ;
F_205 ( V_19 ) ;
V_186 = 0 ;
F_234 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_79 * V_80 = V_190 -> V_80 ;
unsigned long V_113 = F_235 ( V_19 , V_80 ) ;
F_32 ( F_236 ( V_80 ) ) ;
V_186 += F_226 ( V_19 , V_80 , V_113 ) ;
}
if ( V_185 != V_186 )
F_11 ( V_11 L_16 ,
V_185 , V_186 , F_168 ( V_19 ) ) ;
F_32 ( V_185 != V_186 ) ;
}
int F_171 ( struct V_19 * V_19 )
{
struct V_118 * V_118 ;
int V_48 = 1 ;
F_32 ( F_16 ( F_27 ( V_19 ) ) ) ;
F_32 ( ! F_215 ( V_19 ) ) ;
V_118 = F_237 ( V_19 ) ;
if ( ! V_118 )
goto V_74;
F_238 ( V_118 ) ;
V_48 = 0 ;
if ( ! F_91 ( V_19 ) )
goto V_117;
F_32 ( ! F_218 ( V_19 ) ) ;
F_232 ( V_19 , V_118 ) ;
F_24 ( V_191 ) ;
F_32 ( F_91 ( V_19 ) ) ;
V_117:
F_239 ( V_118 ) ;
F_240 ( V_118 ) ;
V_74:
return V_48 ;
}
int F_241 ( struct V_79 * V_80 ,
unsigned long * V_81 , int V_192 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
switch ( V_192 ) {
case V_193 :
if ( * V_81 & ( V_194 | V_195 ) )
return - V_45 ;
if ( V_86 -> V_196 & V_163 )
return - V_45 ;
* V_81 &= ~ V_163 ;
* V_81 |= V_194 ;
if ( F_9 ( F_242 ( V_80 ) ) )
return - V_69 ;
break;
case V_197 :
if ( * V_81 & ( V_163 | V_195 ) )
return - V_45 ;
* V_81 &= ~ V_194 ;
* V_81 |= V_163 ;
break;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
V_198 = F_243 ( L_17 ,
sizeof( struct V_199 ) ,
F_244 ( struct V_199 ) , 0 , NULL ) ;
if ( ! V_198 )
return - V_69 ;
return 0 ;
}
static void T_4 F_81 ( void )
{
F_245 ( V_198 ) ;
V_198 = NULL ;
}
static inline struct V_199 * F_246 ( void )
{
if ( ! V_198 )
return NULL ;
return F_247 ( V_198 , V_108 ) ;
}
static inline void F_248 ( struct V_199 * V_199 )
{
F_249 ( V_198 , V_199 ) ;
}
static int T_4 F_80 ( void )
{
V_200 = F_250 ( V_201 * sizeof( struct V_202 ) ,
V_108 ) ;
if ( ! V_200 )
return - V_69 ;
return 0 ;
}
static struct V_199 * F_251 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
V_203 = & V_200 [ ( ( unsigned long ) V_86 / sizeof( struct V_85 ) )
% V_201 ] ;
F_252 (mm_slot, node, bucket, hash) {
if ( V_86 == V_199 -> V_86 )
return V_199 ;
}
return NULL ;
}
static void F_253 ( struct V_85 * V_86 ,
struct V_199 * V_199 )
{
struct V_202 * V_203 ;
V_203 = & V_200 [ ( ( unsigned long ) V_86 / sizeof( struct V_85 ) )
% V_201 ] ;
V_199 -> V_86 = V_86 ;
F_254 ( & V_199 -> V_206 , V_203 ) ;
}
static inline int F_255 ( struct V_85 * V_86 )
{
return F_35 ( & V_86 -> V_207 ) == 0 ;
}
int F_256 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
int V_208 ;
V_199 = F_246 () ;
if ( ! V_199 )
return - V_69 ;
F_41 ( F_255 ( V_86 ) ) ;
if ( F_9 ( F_257 ( V_209 , & V_86 -> V_98 ) ) ) {
F_248 ( V_199 ) ;
return 0 ;
}
F_95 ( & V_210 ) ;
F_253 ( V_86 , V_199 ) ;
V_208 = F_13 ( & V_12 . V_13 ) ;
F_258 ( & V_199 -> V_211 , & V_12 . V_13 ) ;
F_97 ( & V_210 ) ;
F_259 ( & V_86 -> V_212 ) ;
if ( V_208 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_242 ( struct V_79 * V_80 )
{
unsigned long V_213 , V_214 ;
if ( ! V_80 -> V_118 )
return 0 ;
if ( V_80 -> V_215 )
return 0 ;
F_41 ( V_80 -> V_81 & V_195 ) ;
V_213 = ( V_80 -> V_101 + ~ V_99 ) & V_99 ;
V_214 = V_80 -> V_103 & V_99 ;
if ( V_213 < V_214 )
return F_114 ( V_80 ) ;
return 0 ;
}
void F_260 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
int free = 0 ;
F_95 ( & V_210 ) ;
V_199 = F_251 ( V_86 ) ;
if ( V_199 && V_12 . V_199 != V_199 ) {
F_261 ( & V_199 -> V_206 ) ;
F_262 ( & V_199 -> V_211 ) ;
free = 1 ;
}
F_97 ( & V_210 ) ;
if ( free ) {
F_44 ( V_209 , & V_86 -> V_98 ) ;
F_248 ( V_199 ) ;
F_263 ( V_86 ) ;
} else if ( V_199 ) {
F_264 ( & V_86 -> V_216 ) ;
F_265 ( & V_86 -> V_216 ) ;
}
}
static void F_266 ( struct V_19 * V_19 )
{
F_267 ( V_19 , V_217 + 0 ) ;
F_180 ( V_19 ) ;
F_268 ( V_19 ) ;
}
static void F_269 ( T_7 * V_100 , T_7 * V_218 )
{
while ( -- V_218 >= V_100 ) {
T_7 V_219 = * V_218 ;
if ( ! F_151 ( V_219 ) )
F_266 ( F_270 ( V_219 ) ) ;
}
}
static int F_271 ( struct V_79 * V_80 ,
unsigned long V_97 ,
T_7 * V_100 )
{
struct V_19 * V_19 ;
T_7 * V_218 ;
int V_220 = 0 , V_221 = 0 ;
for ( V_218 = V_100 ; V_218 < V_100 + V_34 ;
V_218 ++ , V_97 += V_128 ) {
T_7 V_219 = * V_218 ;
if ( F_151 ( V_219 ) ) {
if ( ++ V_221 <= V_65 )
continue;
else
goto V_74;
}
if ( ! F_272 ( V_219 ) || ! F_273 ( V_219 ) )
goto V_74;
V_19 = F_274 ( V_80 , V_97 , V_219 ) ;
if ( F_9 ( ! V_19 ) )
goto V_74;
F_41 ( F_91 ( V_19 ) ) ;
F_32 ( ! F_215 ( V_19 ) ) ;
F_41 ( ! F_218 ( V_19 ) ) ;
if ( F_225 ( V_19 ) != 1 )
goto V_74;
if ( ! F_177 ( V_19 ) )
goto V_74;
if ( F_275 ( V_19 ) ) {
F_180 ( V_19 ) ;
goto V_74;
}
F_276 ( V_19 , V_217 + 0 ) ;
F_41 ( ! F_277 ( V_19 ) ) ;
F_41 ( F_278 ( V_19 ) ) ;
if ( F_279 ( V_219 ) || F_280 ( V_19 ) ||
F_281 ( V_80 -> V_136 , V_97 ) )
V_220 = 1 ;
}
if ( F_21 ( V_220 ) )
return 1 ;
V_74:
F_269 ( V_100 , V_218 ) ;
return 0 ;
}
static void F_282 ( T_7 * V_100 , struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
T_10 * V_222 )
{
T_7 * V_218 ;
for ( V_218 = V_100 ; V_218 < V_100 + V_34 ; V_218 ++ ) {
T_7 V_219 = * V_218 ;
struct V_19 * V_114 ;
if ( F_151 ( V_219 ) ) {
F_140 ( V_19 , V_97 ) ;
F_104 ( V_80 -> V_136 , V_91 , 1 ) ;
} else {
V_114 = F_270 ( V_219 ) ;
F_164 ( V_19 , V_114 , V_97 , V_80 ) ;
F_41 ( F_168 ( V_114 ) != 1 ) ;
F_266 ( V_114 ) ;
F_95 ( V_222 ) ;
F_283 ( V_80 -> V_136 , V_97 , V_218 ) ;
F_166 ( V_114 ) ;
F_97 ( V_222 ) ;
F_284 ( V_114 ) ;
}
V_97 += V_128 ;
V_19 ++ ;
}
}
static void F_285 ( void )
{
F_286 ( V_14 , false ,
F_287 ( V_59 ) ) ;
}
static bool F_288 ( struct V_19 * * V_223 , bool * V_224 )
{
if ( F_10 ( * V_223 ) ) {
if ( ! * V_224 )
return false ;
* V_224 = false ;
* V_223 = NULL ;
F_285 () ;
} else if ( * V_223 ) {
F_99 ( * V_223 ) ;
* V_223 = NULL ;
}
return true ;
}
static struct V_19
* F_289 ( struct V_19 * * V_223 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
int V_205 )
{
F_41 ( * V_223 ) ;
* V_223 = F_106 ( F_290 () , V_80 , V_97 ,
V_205 , V_131 ) ;
F_291 ( & V_86 -> V_216 ) ;
if ( F_9 ( ! * V_223 ) ) {
F_24 ( V_225 ) ;
* V_223 = F_176 ( - V_69 ) ;
return NULL ;
}
F_24 ( V_226 ) ;
return * V_223 ;
}
static struct V_19 * F_292 ( bool * V_224 )
{
struct V_19 * V_223 ;
do {
V_223 = F_108 ( F_290 () ) ;
if ( ! V_223 ) {
F_24 ( V_225 ) ;
if ( ! * V_224 )
return NULL ;
* V_224 = false ;
F_285 () ;
} else
F_24 ( V_226 ) ;
} while ( F_9 ( ! V_223 ) && F_21 ( F_2 () ) );
return V_223 ;
}
static bool F_288 ( struct V_19 * * V_223 , bool * V_224 )
{
if ( ! * V_223 )
* V_223 = F_292 ( V_224 ) ;
if ( F_9 ( ! * V_223 ) )
return false ;
return true ;
}
static struct V_19
* F_289 ( struct V_19 * * V_223 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
int V_205 )
{
F_291 ( & V_86 -> V_216 ) ;
F_41 ( ! * V_223 ) ;
return * V_223 ;
}
static bool F_293 ( struct V_79 * V_80 )
{
if ( ( ! ( V_80 -> V_81 & V_194 ) && ! F_294 () ) ||
( V_80 -> V_81 & V_163 ) )
return false ;
if ( ! V_80 -> V_118 || V_80 -> V_215 )
return false ;
if ( F_236 ( V_80 ) )
return false ;
F_41 ( V_80 -> V_81 & V_195 ) ;
return true ;
}
static void F_295 ( struct V_85 * V_86 ,
unsigned long V_97 ,
struct V_19 * * V_223 ,
struct V_79 * V_80 ,
int V_205 )
{
T_1 * V_18 , V_122 ;
T_7 * V_100 ;
T_5 V_88 ;
struct V_19 * V_133 ;
T_10 * V_222 ;
int V_227 ;
unsigned long V_213 , V_214 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_41 ( V_97 & ~ V_99 ) ;
V_133 = F_289 ( V_223 , V_86 , V_80 , V_97 , V_205 ) ;
if ( ! V_133 )
return;
if ( F_9 ( F_118 ( V_133 , V_86 , V_108 ) ) )
return;
F_264 ( & V_86 -> V_216 ) ;
if ( F_9 ( F_255 ( V_86 ) ) )
goto V_74;
V_80 = F_296 ( V_86 , V_97 ) ;
V_213 = ( V_80 -> V_101 + ~ V_99 ) & V_99 ;
V_214 = V_80 -> V_103 & V_99 ;
if ( V_97 < V_213 || V_97 + V_102 > V_214 )
goto V_74;
if ( ! F_293 ( V_80 ) )
goto V_74;
V_18 = F_202 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_120 ( * V_18 ) )
goto V_74;
F_238 ( V_80 -> V_118 ) ;
V_100 = F_121 ( V_18 , V_97 ) ;
V_222 = F_297 ( V_86 , V_18 ) ;
V_124 = V_97 ;
V_125 = V_97 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
V_122 = F_142 ( V_80 , V_97 , V_18 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
F_95 ( V_222 ) ;
V_227 = F_271 ( V_80 , V_97 , V_100 ) ;
F_97 ( V_222 ) ;
if ( F_9 ( ! V_227 ) ) {
F_153 ( V_100 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_32 ( ! F_96 ( * V_18 ) ) ;
F_102 ( V_86 , V_97 , V_18 , V_122 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_239 ( V_80 -> V_118 ) ;
goto V_74;
}
F_239 ( V_80 -> V_118 ) ;
F_282 ( V_100 , V_133 , V_80 , V_97 , V_222 ) ;
F_153 ( V_100 ) ;
F_94 ( V_133 ) ;
V_88 = F_298 ( V_122 ) ;
V_122 = F_86 ( V_133 , V_80 ) ;
F_154 () ;
F_95 ( & V_86 -> V_90 ) ;
F_32 ( ! F_96 ( * V_18 ) ) ;
F_101 ( V_133 , V_80 , V_97 ) ;
F_102 ( V_86 , V_97 , V_18 , V_122 ) ;
F_137 ( V_80 , V_97 , V_18 ) ;
F_103 ( V_86 , V_88 ) ;
F_97 ( & V_86 -> V_90 ) ;
* V_223 = NULL ;
V_62 ++ ;
V_228:
F_265 ( & V_86 -> V_216 ) ;
return;
V_74:
F_98 ( V_133 ) ;
goto V_228;
}
static int F_299 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
struct V_19 * * V_223 )
{
T_1 * V_18 ;
T_7 * V_100 , * V_218 ;
int V_48 = 0 , V_220 = 0 , V_221 = 0 ;
struct V_19 * V_19 ;
unsigned long V_229 ;
T_10 * V_222 ;
int V_205 = - 1 ;
F_41 ( V_97 & ~ V_99 ) ;
V_18 = F_202 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_120 ( * V_18 ) )
goto V_74;
V_100 = F_300 ( V_86 , V_18 , V_97 , & V_222 ) ;
for ( V_229 = V_97 , V_218 = V_100 ; V_218 < V_100 + V_34 ;
V_218 ++ , V_229 += V_128 ) {
T_7 V_219 = * V_218 ;
if ( F_151 ( V_219 ) ) {
if ( ++ V_221 <= V_65 )
continue;
else
goto V_230;
}
if ( ! F_272 ( V_219 ) || ! F_273 ( V_219 ) )
goto V_230;
V_19 = F_274 ( V_80 , V_229 , V_219 ) ;
if ( F_9 ( ! V_19 ) )
goto V_230;
if ( V_205 == - 1 )
V_205 = F_160 ( V_19 ) ;
F_41 ( F_91 ( V_19 ) ) ;
if ( ! F_278 ( V_19 ) || F_277 ( V_19 ) || ! F_215 ( V_19 ) )
goto V_230;
if ( F_225 ( V_19 ) != 1 )
goto V_230;
if ( F_279 ( V_219 ) || F_280 ( V_19 ) ||
F_281 ( V_80 -> V_136 , V_97 ) )
V_220 = 1 ;
}
if ( V_220 )
V_48 = 1 ;
V_230:
F_301 ( V_100 , V_222 ) ;
if ( V_48 )
F_295 ( V_86 , V_97 , V_223 , V_80 , V_205 ) ;
V_74:
return V_48 ;
}
static void F_302 ( struct V_199 * V_199 )
{
struct V_85 * V_86 = V_199 -> V_86 ;
F_41 ( V_231 != 1 && ! F_303 ( & V_210 ) ) ;
if ( F_255 ( V_86 ) ) {
F_261 ( & V_199 -> V_206 ) ;
F_262 ( & V_199 -> V_211 ) ;
F_248 ( V_199 ) ;
F_263 ( V_86 ) ;
}
}
static unsigned int F_304 ( unsigned int V_61 ,
struct V_19 * * V_223 )
__releases( &khugepaged_mm_lock
static int F_305 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_306 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_307 () ;
}
static void F_308 ( void )
{
struct V_19 * V_223 = NULL ;
unsigned int V_232 = 0 , V_233 = 0 ;
unsigned int V_61 = V_60 ;
bool V_224 = true ;
F_309 () ;
while ( V_232 < V_61 ) {
if ( ! F_288 ( & V_223 , & V_224 ) )
break;
F_165 () ;
if ( F_9 ( F_307 () || F_310 ( V_234 ) ) )
break;
F_95 ( & V_210 ) ;
if ( ! V_12 . V_199 )
V_233 ++ ;
if ( F_305 () &&
V_233 < 2 )
V_232 += F_304 ( V_61 - V_232 ,
& V_223 ) ;
else
V_232 = V_61 ;
F_97 ( & V_210 ) ;
}
if ( ! F_311 ( V_223 ) )
F_99 ( V_223 ) ;
}
static void F_312 ( void )
{
F_313 () ;
if ( F_305 () ) {
if ( ! V_56 )
return;
F_286 ( V_14 ,
F_307 () ,
F_287 ( V_56 ) ) ;
return;
}
if ( F_2 () )
F_314 ( V_14 , F_306 () ) ;
}
static int V_10 ( void * V_221 )
{
struct V_199 * V_199 ;
F_315 () ;
F_316 ( V_234 , 19 ) ;
while ( ! F_307 () ) {
F_308 () ;
F_312 () ;
}
F_95 ( & V_210 ) ;
V_199 = V_12 . V_199 ;
V_12 . V_199 = NULL ;
if ( V_199 )
F_302 ( V_199 ) ;
F_97 ( & V_210 ) ;
return 0 ;
}
static void F_317 ( struct V_79 * V_80 ,
unsigned long V_87 , T_1 * V_18 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_5 V_88 ;
T_1 V_122 ;
int V_123 ;
F_142 ( V_80 , V_87 , V_18 ) ;
V_88 = F_143 ( V_86 ) ;
F_144 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
V_83 = F_148 ( F_149 ( V_87 ) , V_80 -> V_84 ) ;
V_83 = F_150 ( V_83 ) ;
V_100 = F_121 ( & V_122 , V_87 ) ;
F_41 ( ! F_151 ( * V_100 ) ) ;
F_152 ( V_86 , V_87 , V_100 , V_83 ) ;
F_153 ( V_100 ) ;
}
F_154 () ;
F_144 ( V_86 , V_18 , V_88 ) ;
F_31 () ;
}
void F_318 ( struct V_79 * V_80 , unsigned long V_97 ,
T_1 * V_18 )
{
struct V_19 * V_19 ;
struct V_85 * V_86 = V_80 -> V_136 ;
unsigned long V_87 = V_97 & V_99 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_32 ( V_80 -> V_101 > V_87 || V_80 -> V_103 < V_87 + V_102 ) ;
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_141 ( V_86 , V_124 , V_125 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_120 ( * V_18 ) ) ) {
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
return;
}
if ( F_18 ( * V_18 ) ) {
F_317 ( V_80 , V_87 , V_18 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
return;
}
V_19 = F_127 ( * V_18 ) ;
F_41 ( ! F_225 ( V_19 ) ) ;
F_129 ( V_19 ) ;
F_97 ( & V_86 -> V_90 ) ;
F_156 ( V_86 , V_124 , V_125 ) ;
F_171 ( V_19 ) ;
F_99 ( V_19 ) ;
F_32 ( F_120 ( * V_18 ) ) ;
}
void F_319 ( struct V_85 * V_86 , unsigned long V_97 ,
T_1 * V_18 )
{
struct V_79 * V_80 ;
V_80 = F_296 ( V_86 , V_97 ) ;
F_32 ( V_80 == NULL ) ;
F_320 ( V_80 , V_97 , V_18 ) ;
}
static void F_321 ( struct V_85 * V_86 ,
unsigned long V_97 )
{
T_1 * V_18 ;
F_41 ( ! ( V_97 & ~ V_99 ) ) ;
V_18 = F_202 ( V_86 , V_97 ) ;
if ( ! V_18 )
return;
F_319 ( V_86 , V_97 , V_18 ) ;
}
void F_322 ( struct V_79 * V_80 ,
unsigned long V_235 ,
unsigned long V_155 ,
long V_236 )
{
if ( V_235 & ~ V_99 &&
( V_235 & V_99 ) >= V_80 -> V_101 &&
( V_235 & V_99 ) + V_102 <= V_80 -> V_103 )
F_321 ( V_80 -> V_136 , V_235 ) ;
if ( V_155 & ~ V_99 &&
( V_155 & V_99 ) >= V_80 -> V_101 &&
( V_155 & V_99 ) + V_102 <= V_80 -> V_103 )
F_321 ( V_80 -> V_136 , V_155 ) ;
if ( V_236 > 0 ) {
struct V_79 * V_237 = V_80 -> V_238 ;
unsigned long V_239 = V_237 -> V_101 ;
V_239 += V_236 << V_7 ;
if ( V_239 & ~ V_99 &&
( V_239 & V_99 ) >= V_237 -> V_101 &&
( V_239 & V_99 ) + V_102 <= V_237 -> V_103 )
F_321 ( V_237 -> V_136 , V_239 ) ;
}
}
