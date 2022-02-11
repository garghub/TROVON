static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
if ( ! F_2 () )
return 0 ;
F_3 (zone)
V_2 ++ ;
V_3 = V_4 * V_2 * 2 ;
V_3 += V_4 * V_2 *
V_5 * V_5 ;
V_3 = F_4 ( V_3 ,
( unsigned long ) F_5 () / 20 ) ;
V_3 <<= ( V_6 - 10 ) ;
if ( V_3 > V_7 )
V_7 = V_3 ;
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
F_80 ( & V_75 ) ;
if ( V_76 < ( 512 << ( 20 - V_6 ) ) )
V_43 = 0 ;
F_7 () ;
return 0 ;
V_74:
F_76 ( V_67 ) ;
return V_8 ;
}
static int T_4 F_81 ( char * V_77 )
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
T_1 F_82 ( T_1 V_18 , struct V_79 * V_80 )
{
if ( F_21 ( V_80 -> V_81 & V_82 ) )
V_18 = F_83 ( V_18 ) ;
return V_18 ;
}
static inline T_1 F_84 ( struct V_19 * V_19 , struct V_79 * V_80 )
{
T_1 V_83 ;
V_83 = F_85 ( V_19 , V_80 -> V_84 ) ;
V_83 = F_82 ( F_86 ( V_83 ) , V_80 ) ;
V_83 = F_87 ( V_83 ) ;
return V_83 ;
}
static int F_88 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_87 , T_1 * V_18 ,
struct V_19 * V_19 )
{
T_5 V_88 ;
F_41 ( ! F_89 ( V_19 ) ) ;
V_88 = F_90 ( V_86 , V_87 ) ;
if ( F_9 ( ! V_88 ) )
return V_89 ;
F_91 ( V_19 , V_87 , V_34 ) ;
F_92 ( V_19 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_94 ( * V_18 ) ) ) {
F_95 ( & V_86 -> V_90 ) ;
F_96 ( V_19 ) ;
F_97 ( V_19 ) ;
F_98 ( V_86 , V_88 ) ;
} else {
T_1 V_83 ;
V_83 = F_84 ( V_19 , V_80 ) ;
F_99 ( V_19 , V_80 , V_87 ) ;
F_100 ( V_86 , V_87 , V_18 , V_83 ) ;
F_101 ( V_86 , V_88 ) ;
F_102 ( V_86 , V_91 , V_34 ) ;
V_86 -> V_92 ++ ;
F_95 ( & V_86 -> V_90 ) ;
}
return 0 ;
}
static inline T_6 F_103 ( int V_93 , T_6 V_94 )
{
return ( V_23 & ~ ( V_93 ? 0 : V_95 ) ) | V_94 ;
}
static inline struct V_19 * F_104 ( int V_93 ,
struct V_79 * V_80 ,
unsigned long V_87 , int V_96 ,
T_6 V_94 )
{
return F_105 ( F_103 ( V_93 , V_94 ) ,
V_26 , V_80 , V_87 , V_96 ) ;
}
static inline struct V_19 * F_106 ( int V_93 )
{
return F_23 ( F_103 ( V_93 , 0 ) ,
V_26 ) ;
}
static bool F_107 ( T_5 V_88 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_87 , T_1 * V_18 ,
unsigned long V_16 )
{
T_1 V_83 ;
if ( ! F_94 ( * V_18 ) )
return false ;
V_83 = F_108 ( V_16 , V_80 -> V_84 ) ;
V_83 = F_109 ( V_83 ) ;
V_83 = F_87 ( V_83 ) ;
F_100 ( V_86 , V_87 , V_18 , V_83 ) ;
F_101 ( V_86 , V_88 ) ;
V_86 -> V_92 ++ ;
return true ;
}
int F_110 ( struct V_85 * V_86 , struct V_79 * V_80 ,
unsigned long V_97 , T_1 * V_18 ,
unsigned int V_98 )
{
struct V_19 * V_19 ;
unsigned long V_87 = V_97 & V_99 ;
T_7 * V_100 ;
if ( V_87 >= V_80 -> V_101 && V_87 + V_102 <= V_80 -> V_103 ) {
if ( F_9 ( F_111 ( V_80 ) ) )
return V_89 ;
if ( F_9 ( F_112 ( V_80 ) ) )
return V_89 ;
if ( ! ( V_98 & V_104 ) &&
F_113 () ) {
T_5 V_88 ;
unsigned long V_16 ;
bool V_105 ;
V_88 = F_90 ( V_86 , V_87 ) ;
if ( F_9 ( ! V_88 ) )
return V_89 ;
V_16 = F_20 () ;
if ( F_9 ( ! V_16 ) ) {
F_98 ( V_86 , V_88 ) ;
F_24 ( V_106 ) ;
goto V_74;
}
F_93 ( & V_86 -> V_90 ) ;
V_105 = F_107 ( V_88 , V_86 , V_80 , V_87 , V_18 ,
V_16 ) ;
F_95 ( & V_86 -> V_90 ) ;
if ( ! V_105 ) {
F_98 ( V_86 , V_88 ) ;
F_31 () ;
}
return 0 ;
}
V_19 = F_104 ( F_114 ( V_80 ) ,
V_80 , V_87 , F_115 () , 0 ) ;
if ( F_9 ( ! V_19 ) ) {
F_24 ( V_106 ) ;
goto V_74;
}
F_24 ( V_107 ) ;
if ( F_9 ( F_116 ( V_19 , V_86 , V_108 ) ) ) {
F_97 ( V_19 ) ;
goto V_74;
}
if ( F_9 ( F_88 ( V_86 , V_80 , V_87 , V_18 ,
V_19 ) ) ) {
F_96 ( V_19 ) ;
F_97 ( V_19 ) ;
goto V_74;
}
return 0 ;
}
V_74:
if ( F_9 ( F_94 ( * V_18 ) ) &&
F_9 ( F_117 ( V_86 , V_80 , V_18 , V_97 ) ) )
return V_89 ;
if ( F_9 ( F_118 ( * V_18 ) ) )
return 0 ;
V_100 = F_119 ( V_18 , V_97 ) ;
return F_120 ( V_86 , V_80 , V_97 , V_100 , V_18 , V_98 ) ;
}
int F_121 ( struct V_85 * V_109 , struct V_85 * V_110 ,
T_1 * V_111 , T_1 * V_112 , unsigned long V_113 ,
struct V_79 * V_80 )
{
struct V_19 * V_114 ;
T_1 V_18 ;
T_5 V_88 ;
int V_48 ;
V_48 = - V_69 ;
V_88 = F_90 ( V_109 , V_113 ) ;
if ( F_9 ( ! V_88 ) )
goto V_74;
F_93 ( & V_109 -> V_90 ) ;
F_122 ( & V_110 -> V_90 , V_115 ) ;
V_48 = - V_116 ;
V_18 = * V_112 ;
if ( F_9 ( ! F_118 ( V_18 ) ) ) {
F_98 ( V_109 , V_88 ) ;
goto V_117;
}
if ( F_18 ( V_18 ) ) {
unsigned long V_16 ;
bool V_105 ;
V_16 = F_20 () ;
V_105 = F_107 ( V_88 , V_109 , V_80 , V_113 , V_111 ,
V_16 ) ;
F_32 ( ! V_105 ) ;
V_48 = 0 ;
goto V_117;
}
if ( F_9 ( F_123 ( V_18 ) ) ) {
F_95 ( & V_110 -> V_90 ) ;
F_95 ( & V_109 -> V_90 ) ;
F_98 ( V_109 , V_88 ) ;
F_124 ( V_80 -> V_118 , V_112 ) ;
goto V_74;
}
V_114 = F_125 ( V_18 ) ;
F_41 ( ! F_126 ( V_114 ) ) ;
F_127 ( V_114 ) ;
F_128 ( V_114 ) ;
F_102 ( V_109 , V_91 , V_34 ) ;
F_129 ( V_110 , V_113 , V_112 ) ;
V_18 = F_130 ( F_109 ( V_18 ) ) ;
F_100 ( V_109 , V_113 , V_111 , V_18 ) ;
F_101 ( V_109 , V_88 ) ;
V_109 -> V_92 ++ ;
V_48 = 0 ;
V_117:
F_95 ( & V_110 -> V_90 ) ;
F_95 ( & V_109 -> V_90 ) ;
V_74:
return V_48 ;
}
void F_131 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
T_1 * V_18 , T_1 V_119 ,
int V_120 )
{
T_1 V_83 ;
unsigned long V_87 ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( * V_18 , V_119 ) ) )
goto V_121;
V_83 = F_133 ( V_119 ) ;
V_87 = V_97 & V_99 ;
if ( F_134 ( V_80 , V_87 , V_18 , V_83 , V_120 ) )
F_135 ( V_80 , V_97 , V_18 ) ;
V_121:
F_95 ( & V_86 -> V_90 ) ;
}
static int F_136 ( struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
T_1 * V_18 , T_1 V_119 , unsigned long V_87 )
{
T_5 V_88 ;
T_1 V_122 ;
struct V_19 * V_19 ;
int V_123 , V_48 = 0 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_19 = F_137 ( V_126 , V_80 , V_97 ) ;
if ( ! V_19 ) {
V_48 |= V_89 ;
goto V_74;
}
if ( F_116 ( V_19 , V_86 , V_108 ) ) {
F_97 ( V_19 ) ;
V_48 |= V_89 ;
goto V_74;
}
F_138 ( V_19 , V_97 ) ;
F_92 ( V_19 ) ;
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( * V_18 , V_119 ) ) )
goto V_127;
F_140 ( V_80 , V_87 , V_18 ) ;
V_88 = F_141 ( V_86 ) ;
F_142 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
if ( V_87 == ( V_97 & V_129 ) ) {
V_83 = F_143 ( V_19 , V_80 -> V_84 ) ;
V_83 = F_144 ( F_145 ( V_83 ) , V_80 ) ;
F_99 ( V_19 , V_80 , V_87 ) ;
} else {
V_83 = F_146 ( F_147 ( V_87 ) , V_80 -> V_84 ) ;
V_83 = F_148 ( V_83 ) ;
}
V_100 = F_119 ( & V_122 , V_87 ) ;
F_41 ( ! F_149 ( * V_100 ) ) ;
F_150 ( V_86 , V_87 , V_100 , V_83 ) ;
F_151 ( V_100 ) ;
}
F_152 () ;
F_142 ( V_86 , V_18 , V_88 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_31 () ;
F_153 ( V_86 , V_91 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
V_48 |= V_130 ;
V_74:
return V_48 ;
V_127:
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
F_96 ( V_19 ) ;
F_97 ( V_19 ) ;
goto V_74;
}
static int F_155 ( struct V_85 * V_86 ,
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
V_61 = F_156 ( sizeof( struct V_19 * ) * V_34 ,
V_108 ) ;
if ( F_9 ( ! V_61 ) ) {
V_48 |= V_89 ;
goto V_74;
}
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
V_61 [ V_123 ] = F_157 ( V_126 |
V_131 ,
V_80 , V_97 , F_158 ( V_19 ) ) ;
if ( F_9 ( ! V_61 [ V_123 ] ||
F_116 ( V_61 [ V_123 ] , V_86 ,
V_108 ) ) ) {
if ( V_61 [ V_123 ] )
F_97 ( V_61 [ V_123 ] ) ;
F_159 () ;
while ( -- V_123 >= 0 ) {
F_96 ( V_61 [ V_123 ] ) ;
F_97 ( V_61 [ V_123 ] ) ;
}
F_160 () ;
F_161 ( V_61 ) ;
V_48 |= V_89 ;
goto V_74;
}
}
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
F_162 ( V_61 [ V_123 ] , V_19 + V_123 ,
V_87 + V_128 * V_123 , V_80 ) ;
F_92 ( V_61 [ V_123 ] ) ;
F_163 () ;
}
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( * V_18 , V_119 ) ) )
goto V_132;
F_41 ( ! F_126 ( V_19 ) ) ;
F_140 ( V_80 , V_87 , V_18 ) ;
V_88 = F_141 ( V_86 ) ;
F_142 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
V_83 = F_143 ( V_61 [ V_123 ] , V_80 -> V_84 ) ;
V_83 = F_144 ( F_145 ( V_83 ) , V_80 ) ;
F_99 ( V_61 [ V_123 ] , V_80 , V_87 ) ;
V_100 = F_119 ( & V_122 , V_87 ) ;
F_41 ( ! F_149 ( * V_100 ) ) ;
F_150 ( V_86 , V_87 , V_100 , V_83 ) ;
F_151 ( V_100 ) ;
}
F_161 ( V_61 ) ;
F_152 () ;
F_142 ( V_86 , V_18 , V_88 ) ;
F_164 ( V_19 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
V_48 |= V_130 ;
F_97 ( V_19 ) ;
V_74:
return V_48 ;
V_132:
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
F_159 () ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
F_96 ( V_61 [ V_123 ] ) ;
F_97 ( V_61 [ V_123 ] ) ;
}
F_160 () ;
F_161 ( V_61 ) ;
goto V_74;
}
int F_165 ( struct V_85 * V_86 , struct V_79 * V_80 ,
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
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( * V_18 , V_119 ) ) )
goto V_117;
V_19 = F_125 ( V_119 ) ;
F_41 ( ! F_89 ( V_19 ) || ! F_126 ( V_19 ) ) ;
if ( F_166 ( V_19 ) == 1 ) {
T_1 V_83 ;
V_83 = F_133 ( V_119 ) ;
V_83 = F_82 ( F_86 ( V_83 ) , V_80 ) ;
if ( F_134 ( V_80 , V_87 , V_18 , V_83 , 1 ) )
F_135 ( V_80 , V_97 , V_18 ) ;
V_48 |= V_130 ;
goto V_117;
}
F_127 ( V_19 ) ;
F_95 ( & V_86 -> V_90 ) ;
V_134:
if ( F_167 ( V_80 ) &&
! F_168 () )
V_133 = F_104 ( F_114 ( V_80 ) ,
V_80 , V_87 , F_115 () , 0 ) ;
else
V_133 = NULL ;
if ( F_9 ( ! V_133 ) ) {
F_24 ( V_106 ) ;
if ( F_18 ( V_119 ) ) {
V_48 = F_136 ( V_86 , V_80 ,
V_97 , V_18 , V_119 , V_87 ) ;
} else {
V_48 = F_155 ( V_86 , V_80 , V_97 ,
V_18 , V_119 , V_19 , V_87 ) ;
if ( V_48 & V_89 )
F_169 ( V_19 ) ;
F_97 ( V_19 ) ;
}
goto V_74;
}
F_24 ( V_107 ) ;
if ( F_9 ( F_116 ( V_133 , V_86 , V_108 ) ) ) {
F_97 ( V_133 ) ;
if ( V_19 ) {
F_169 ( V_19 ) ;
F_97 ( V_19 ) ;
}
V_48 |= V_89 ;
goto V_74;
}
if ( F_18 ( V_119 ) )
F_91 ( V_133 , V_87 , V_34 ) ;
else
F_170 ( V_133 , V_19 , V_87 , V_80 , V_34 ) ;
F_92 ( V_133 ) ;
V_124 = V_87 ;
V_125 = V_87 + V_102 ;
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( V_19 )
F_97 ( V_19 ) ;
if ( F_9 ( ! F_132 ( * V_18 , V_119 ) ) ) {
F_95 ( & V_86 -> V_90 ) ;
F_96 ( V_133 ) ;
F_97 ( V_133 ) ;
goto V_135;
} else {
T_1 V_83 ;
V_83 = F_84 ( V_133 , V_80 ) ;
F_140 ( V_80 , V_87 , V_18 ) ;
F_99 ( V_133 , V_80 , V_87 ) ;
F_100 ( V_86 , V_87 , V_18 , V_83 ) ;
F_135 ( V_80 , V_97 , V_18 ) ;
if ( F_18 ( V_119 ) ) {
F_102 ( V_86 , V_91 , V_34 ) ;
F_31 () ;
} else {
F_41 ( ! F_126 ( V_19 ) ) ;
F_164 ( V_19 ) ;
F_97 ( V_19 ) ;
}
V_48 |= V_130 ;
}
F_95 ( & V_86 -> V_90 ) ;
V_135:
F_154 ( V_86 , V_124 , V_125 ) ;
V_74:
return V_48 ;
V_117:
F_95 ( & V_86 -> V_90 ) ;
return V_48 ;
}
struct V_19 * F_171 ( struct V_79 * V_80 ,
unsigned long V_113 ,
T_1 * V_18 ,
unsigned int V_98 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
struct V_19 * V_19 = NULL ;
F_172 ( & V_86 -> V_90 ) ;
if ( V_98 & V_137 && ! F_173 ( * V_18 ) )
goto V_74;
if ( ( V_98 & V_138 ) && F_18 ( * V_18 ) )
return F_174 ( - V_139 ) ;
V_19 = F_125 ( * V_18 ) ;
F_41 ( ! F_126 ( V_19 ) ) ;
if ( V_98 & V_140 ) {
T_1 V_122 ;
V_122 = F_133 ( F_86 ( * V_18 ) ) ;
F_100 ( V_86 , V_113 & V_99 , V_18 , V_122 ) ;
}
if ( ( V_98 & V_141 ) && ( V_80 -> V_81 & V_142 ) ) {
if ( V_19 -> V_143 && F_175 ( V_19 ) ) {
F_176 () ;
if ( V_19 -> V_143 )
F_177 ( V_19 ) ;
F_178 ( V_19 ) ;
}
}
V_19 += ( V_113 & ~ V_99 ) >> V_6 ;
F_41 ( ! F_89 ( V_19 ) ) ;
if ( V_98 & V_144 )
F_179 ( V_19 ) ;
V_74:
return V_19 ;
}
int F_180 ( struct V_85 * V_86 , struct V_79 * V_80 ,
unsigned long V_113 , T_1 V_18 , T_1 * V_145 )
{
struct V_19 * V_19 ;
unsigned long V_87 = V_113 & V_99 ;
int V_146 ;
int V_147 = - 1 ;
bool V_148 ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( V_18 , * V_145 ) ) )
goto V_117;
V_19 = F_125 ( V_18 ) ;
F_127 ( V_19 ) ;
V_147 = F_158 ( V_19 ) ;
F_181 ( V_149 ) ;
if ( V_147 == F_115 () )
F_181 ( V_150 ) ;
V_146 = F_182 ( V_19 , V_80 , V_87 ) ;
if ( V_146 == - 1 ) {
F_97 ( V_19 ) ;
goto V_151;
}
F_95 ( & V_86 -> V_90 ) ;
F_183 ( V_19 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( V_18 , * V_145 ) ) ) {
F_178 ( V_19 ) ;
F_97 ( V_19 ) ;
goto V_117;
}
F_95 ( & V_86 -> V_90 ) ;
V_148 = F_184 ( V_86 , V_80 ,
V_145 , V_18 , V_113 , V_19 , V_146 ) ;
if ( ! V_148 )
goto V_152;
F_185 ( V_146 , V_34 , true ) ;
return 0 ;
V_152:
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_132 ( V_18 , * V_145 ) ) )
goto V_117;
V_151:
V_18 = F_186 ( V_18 ) ;
F_100 ( V_86 , V_87 , V_145 , V_18 ) ;
F_41 ( F_187 ( * V_145 ) ) ;
F_135 ( V_80 , V_113 , V_145 ) ;
V_117:
F_95 ( & V_86 -> V_90 ) ;
if ( V_147 != - 1 )
F_185 ( V_147 , V_34 , false ) ;
return 0 ;
}
int F_188 ( struct V_153 * V_154 , struct V_79 * V_80 ,
T_1 * V_18 , unsigned long V_113 )
{
int V_48 = 0 ;
if ( F_189 ( V_18 , V_80 ) == 1 ) {
struct V_19 * V_19 ;
T_5 V_88 ;
T_1 V_119 ;
V_88 = F_141 ( V_154 -> V_86 ) ;
V_119 = F_190 ( V_154 -> V_86 , V_113 , V_18 ) ;
F_191 ( V_154 , V_18 , V_113 ) ;
if ( F_18 ( V_119 ) ) {
V_154 -> V_86 -> V_92 -- ;
F_95 ( & V_154 -> V_86 -> V_90 ) ;
F_31 () ;
} else {
V_19 = F_125 ( V_119 ) ;
F_164 ( V_19 ) ;
F_41 ( F_166 ( V_19 ) < 0 ) ;
F_102 ( V_154 -> V_86 , V_91 , - V_34 ) ;
F_41 ( ! F_126 ( V_19 ) ) ;
V_154 -> V_86 -> V_92 -- ;
F_95 ( & V_154 -> V_86 -> V_90 ) ;
F_192 ( V_154 , V_19 ) ;
}
F_98 ( V_154 -> V_86 , V_88 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_193 ( struct V_79 * V_80 , T_1 * V_18 ,
unsigned long V_113 , unsigned long V_155 ,
unsigned char * V_156 )
{
int V_48 = 0 ;
if ( F_189 ( V_18 , V_80 ) == 1 ) {
F_95 ( & V_80 -> V_136 -> V_90 ) ;
memset ( V_156 , 1 , ( V_155 - V_113 ) >> V_6 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_194 ( struct V_79 * V_80 , struct V_79 * V_157 ,
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
if ( F_195 ( ! F_94 ( * V_162 ) ) ) {
F_41 ( F_118 ( * V_162 ) ) ;
goto V_74;
}
V_48 = F_189 ( V_161 , V_80 ) ;
if ( V_48 == 1 ) {
V_18 = F_190 ( V_86 , V_158 , V_161 ) ;
F_41 ( ! F_94 ( * V_162 ) ) ;
F_100 ( V_86 , V_159 , V_162 , V_18 ) ;
F_95 ( & V_86 -> V_90 ) ;
}
V_74:
return V_48 ;
}
int F_196 ( struct V_79 * V_80 , T_1 * V_18 ,
unsigned long V_113 , T_8 V_164 , int V_165 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
int V_48 = 0 ;
if ( F_189 ( V_18 , V_80 ) == 1 ) {
T_1 V_83 ;
V_83 = F_190 ( V_86 , V_113 , V_18 ) ;
if ( ! V_165 ) {
V_83 = F_197 ( V_83 , V_164 ) ;
F_32 ( F_173 ( V_83 ) ) ;
} else {
struct V_19 * V_19 = F_125 ( * V_18 ) ;
if ( F_166 ( V_19 ) == 1 &&
! F_187 ( * V_18 ) ) {
V_83 = F_198 ( V_83 ) ;
}
}
F_100 ( V_86 , V_113 , V_18 , V_83 ) ;
F_95 ( & V_80 -> V_136 -> V_90 ) ;
V_48 = 1 ;
}
return V_48 ;
}
int F_189 ( T_1 * V_18 , struct V_79 * V_80 )
{
F_93 ( & V_80 -> V_136 -> V_90 ) ;
if ( F_21 ( F_118 ( * V_18 ) ) ) {
if ( F_9 ( F_123 ( * V_18 ) ) ) {
F_95 ( & V_80 -> V_136 -> V_90 ) ;
F_124 ( V_80 -> V_118 , V_18 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_95 ( & V_80 -> V_136 -> V_90 ) ;
return 0 ;
}
T_1 * F_199 ( struct V_19 * V_19 ,
struct V_85 * V_86 ,
unsigned long V_97 ,
enum V_166 V_50 )
{
T_1 * V_18 , * V_48 = NULL ;
if ( V_97 & ~ V_99 )
goto V_74;
V_18 = F_200 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_94 ( * V_18 ) )
goto V_74;
if ( F_125 ( * V_18 ) != V_19 )
goto V_74;
if ( V_50 == V_167 &&
F_123 ( * V_18 ) )
goto V_74;
if ( F_118 ( * V_18 ) ) {
F_41 ( V_50 == V_168 &&
! F_123 ( * V_18 ) ) ;
V_48 = V_18 ;
}
V_74:
return V_48 ;
}
static int F_201 ( struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_1 * V_18 ;
int V_48 = 0 ;
const unsigned long V_124 = V_97 ;
const unsigned long V_125 = V_97 + V_102 ;
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
V_18 = F_199 ( V_19 , V_86 , V_97 ,
V_167 ) ;
if ( V_18 ) {
F_202 ( V_80 , V_97 , V_18 ) ;
V_48 = 1 ;
}
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
return V_48 ;
}
static void F_203 ( struct V_19 * V_19 )
{
int V_123 ;
struct V_1 * V_1 = F_204 ( V_19 ) ;
struct V_169 * V_169 ;
int V_170 = 0 ;
F_205 ( & V_1 -> V_171 ) ;
V_169 = F_206 ( V_19 , V_1 ) ;
F_207 ( V_19 ) ;
F_208 ( V_19 ) ;
for ( V_123 = V_34 - 1 ; V_123 >= 1 ; V_123 -- ) {
struct V_19 * V_172 = V_19 + V_123 ;
F_32 ( F_166 ( V_172 ) < 0 ) ;
V_170 += F_166 ( V_172 ) ;
F_32 ( V_170 < 0 ) ;
F_32 ( F_35 ( & V_172 -> V_173 ) != 0 ) ;
F_209 ( F_166 ( V_19 ) + F_166 ( V_172 ) + 1 ,
& V_172 -> V_173 ) ;
F_210 () ;
V_172 -> V_98 &= ~ V_174 | V_175 ;
V_172 -> V_98 |= ( V_19 -> V_98 &
( ( 1L << V_176 ) |
( 1L << V_177 ) |
( 1L << V_178 ) |
( 1L << V_179 ) ) ) ;
V_172 -> V_98 |= ( 1L << V_180 ) ;
F_152 () ;
V_172 -> V_181 = V_19 -> V_181 ;
F_32 ( V_172 -> V_143 ) ;
V_172 -> V_143 = V_19 -> V_143 ;
V_172 -> V_182 = V_19 -> V_182 + V_123 ;
F_211 ( V_172 , F_212 ( V_19 ) ) ;
F_32 ( ! F_213 ( V_172 ) ) ;
F_32 ( ! F_214 ( V_172 ) ) ;
F_32 ( ! F_215 ( V_172 ) ) ;
F_32 ( ! F_216 ( V_172 ) ) ;
F_217 ( V_19 , V_172 , V_169 ) ;
}
F_218 ( V_170 , & V_19 -> V_173 ) ;
F_32 ( F_35 ( & V_19 -> V_173 ) <= 0 ) ;
F_219 ( V_1 , V_183 , - 1 ) ;
F_219 ( V_1 , V_184 , V_34 ) ;
F_220 ( V_19 ) ;
F_221 ( V_19 ) ;
F_222 ( & V_1 -> V_171 ) ;
for ( V_123 = 1 ; V_123 < V_34 ; V_123 ++ ) {
struct V_19 * V_172 = V_19 + V_123 ;
F_32 ( F_223 ( V_172 ) <= 0 ) ;
F_97 ( V_172 ) ;
}
F_32 ( F_223 ( V_19 ) <= 0 ) ;
}
static int F_224 ( struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_1 * V_18 , V_122 ;
int V_48 = 0 , V_123 ;
T_5 V_88 ;
unsigned long V_87 ;
F_93 ( & V_86 -> V_90 ) ;
V_18 = F_199 ( V_19 , V_86 , V_97 ,
V_168 ) ;
if ( V_18 ) {
V_88 = F_141 ( V_86 ) ;
F_142 ( V_86 , & V_122 , V_88 ) ;
V_87 = V_97 ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
F_32 ( F_89 ( V_19 + V_123 ) ) ;
V_83 = F_143 ( V_19 + V_123 , V_80 -> V_84 ) ;
V_83 = F_144 ( F_145 ( V_83 ) , V_80 ) ;
if ( ! F_173 ( * V_18 ) )
V_83 = F_225 ( V_83 ) ;
else
F_32 ( F_166 ( V_19 ) != 1 ) ;
if ( ! F_226 ( * V_18 ) )
V_83 = F_227 ( V_83 ) ;
if ( F_187 ( * V_18 ) )
V_83 = F_228 ( V_83 ) ;
V_100 = F_119 ( & V_122 , V_87 ) ;
F_32 ( ! F_149 ( * V_100 ) ) ;
F_150 ( V_86 , V_87 , V_100 , V_83 ) ;
F_151 ( V_100 ) ;
}
F_152 () ;
F_229 ( V_80 , V_97 , V_18 ) ;
F_142 ( V_86 , V_18 , V_88 ) ;
V_48 = 1 ;
}
F_95 ( & V_86 -> V_90 ) ;
return V_48 ;
}
static void F_230 ( struct V_19 * V_19 ,
struct V_118 * V_118 )
{
int V_185 , V_186 ;
T_9 V_187 = V_19 -> V_182 << ( V_188 - V_6 ) ;
struct V_189 * V_190 ;
F_32 ( ! F_126 ( V_19 ) ) ;
F_32 ( F_231 ( V_19 ) ) ;
V_185 = 0 ;
F_232 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_79 * V_80 = V_190 -> V_80 ;
unsigned long V_113 = F_233 ( V_19 , V_80 ) ;
F_32 ( F_234 ( V_80 ) ) ;
V_185 += F_201 ( V_19 , V_80 , V_113 ) ;
}
if ( V_185 != F_166 ( V_19 ) )
F_11 ( V_11 L_15 ,
V_185 , F_166 ( V_19 ) ) ;
F_32 ( V_185 != F_166 ( V_19 ) ) ;
F_203 ( V_19 ) ;
V_186 = 0 ;
F_232 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_79 * V_80 = V_190 -> V_80 ;
unsigned long V_113 = F_233 ( V_19 , V_80 ) ;
F_32 ( F_234 ( V_80 ) ) ;
V_186 += F_224 ( V_19 , V_80 , V_113 ) ;
}
if ( V_185 != V_186 )
F_11 ( V_11 L_16 ,
V_185 , V_186 , F_166 ( V_19 ) ) ;
F_32 ( V_185 != V_186 ) ;
}
int F_169 ( struct V_19 * V_19 )
{
struct V_118 * V_118 ;
int V_48 = 1 ;
F_32 ( F_16 ( F_27 ( V_19 ) ) ) ;
F_32 ( ! F_213 ( V_19 ) ) ;
V_118 = F_235 ( V_19 ) ;
if ( ! V_118 )
goto V_74;
F_236 ( V_118 ) ;
V_48 = 0 ;
if ( ! F_89 ( V_19 ) )
goto V_117;
F_32 ( ! F_216 ( V_19 ) ) ;
F_230 ( V_19 , V_118 ) ;
F_24 ( V_191 ) ;
F_32 ( F_89 ( V_19 ) ) ;
V_117:
F_237 ( V_118 ) ;
F_238 ( V_118 ) ;
V_74:
return V_48 ;
}
int F_239 ( struct V_79 * V_80 ,
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
if ( F_9 ( F_240 ( V_80 ) ) )
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
V_198 = F_241 ( L_17 ,
sizeof( struct V_199 ) ,
F_242 ( struct V_199 ) , 0 , NULL ) ;
if ( ! V_198 )
return - V_69 ;
return 0 ;
}
static inline struct V_199 * F_243 ( void )
{
if ( ! V_198 )
return NULL ;
return F_244 ( V_198 , V_108 ) ;
}
static inline void F_245 ( struct V_199 * V_199 )
{
F_246 ( V_198 , V_199 ) ;
}
static struct V_199 * F_247 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
F_248 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_86 == V_199 -> V_86 )
return V_199 ;
return NULL ;
}
static void F_249 ( struct V_85 * V_86 ,
struct V_199 * V_199 )
{
V_199 -> V_86 = V_86 ;
F_250 ( V_200 , & V_199 -> V_201 , ( long ) V_86 ) ;
}
static inline int F_251 ( struct V_85 * V_86 )
{
return F_35 ( & V_86 -> V_202 ) == 0 ;
}
int F_252 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
int V_203 ;
V_199 = F_243 () ;
if ( ! V_199 )
return - V_69 ;
F_41 ( F_251 ( V_86 ) ) ;
if ( F_9 ( F_253 ( V_204 , & V_86 -> V_98 ) ) ) {
F_245 ( V_199 ) ;
return 0 ;
}
F_93 ( & V_205 ) ;
F_249 ( V_86 , V_199 ) ;
V_203 = F_13 ( & V_12 . V_13 ) ;
F_254 ( & V_199 -> V_206 , & V_12 . V_13 ) ;
F_95 ( & V_205 ) ;
F_255 ( & V_86 -> V_207 ) ;
if ( V_203 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_240 ( struct V_79 * V_80 )
{
unsigned long V_208 , V_209 ;
if ( ! V_80 -> V_118 )
return 0 ;
if ( V_80 -> V_210 )
return 0 ;
F_41 ( V_80 -> V_81 & V_195 ) ;
V_208 = ( V_80 -> V_101 + ~ V_99 ) & V_99 ;
V_209 = V_80 -> V_103 & V_99 ;
if ( V_208 < V_209 )
return F_112 ( V_80 ) ;
return 0 ;
}
void F_256 ( struct V_85 * V_86 )
{
struct V_199 * V_199 ;
int free = 0 ;
F_93 ( & V_205 ) ;
V_199 = F_247 ( V_86 ) ;
if ( V_199 && V_12 . V_199 != V_199 ) {
F_257 ( & V_199 -> V_201 ) ;
F_258 ( & V_199 -> V_206 ) ;
free = 1 ;
}
F_95 ( & V_205 ) ;
if ( free ) {
F_44 ( V_204 , & V_86 -> V_98 ) ;
F_245 ( V_199 ) ;
F_259 ( V_86 ) ;
} else if ( V_199 ) {
F_260 ( & V_86 -> V_211 ) ;
F_261 ( & V_86 -> V_211 ) ;
}
}
static void F_262 ( struct V_19 * V_19 )
{
F_263 ( V_19 , V_212 + 0 ) ;
F_178 ( V_19 ) ;
F_264 ( V_19 ) ;
}
static void F_265 ( T_7 * V_100 , T_7 * V_213 )
{
while ( -- V_213 >= V_100 ) {
T_7 V_214 = * V_213 ;
if ( ! F_149 ( V_214 ) )
F_262 ( F_266 ( V_214 ) ) ;
}
}
static int F_267 ( struct V_79 * V_80 ,
unsigned long V_97 ,
T_7 * V_100 )
{
struct V_19 * V_19 ;
T_7 * V_213 ;
int V_215 = 0 , V_216 = 0 ;
for ( V_213 = V_100 ; V_213 < V_100 + V_34 ;
V_213 ++ , V_97 += V_128 ) {
T_7 V_214 = * V_213 ;
if ( F_149 ( V_214 ) ) {
if ( ++ V_216 <= V_65 )
continue;
else
goto V_74;
}
if ( ! F_268 ( V_214 ) || ! F_269 ( V_214 ) )
goto V_74;
V_19 = F_270 ( V_80 , V_97 , V_214 ) ;
if ( F_9 ( ! V_19 ) )
goto V_74;
F_41 ( F_89 ( V_19 ) ) ;
F_32 ( ! F_213 ( V_19 ) ) ;
F_41 ( ! F_216 ( V_19 ) ) ;
if ( F_223 ( V_19 ) != 1 )
goto V_74;
if ( ! F_175 ( V_19 ) )
goto V_74;
if ( F_271 ( V_19 ) ) {
F_178 ( V_19 ) ;
goto V_74;
}
F_272 ( V_19 , V_212 + 0 ) ;
F_41 ( ! F_273 ( V_19 ) ) ;
F_41 ( F_274 ( V_19 ) ) ;
if ( F_275 ( V_214 ) || F_276 ( V_19 ) ||
F_277 ( V_80 -> V_136 , V_97 ) )
V_215 = 1 ;
}
if ( F_21 ( V_215 ) )
return 1 ;
V_74:
F_265 ( V_100 , V_213 ) ;
return 0 ;
}
static void F_278 ( T_7 * V_100 , struct V_19 * V_19 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
T_10 * V_217 )
{
T_7 * V_213 ;
for ( V_213 = V_100 ; V_213 < V_100 + V_34 ; V_213 ++ ) {
T_7 V_214 = * V_213 ;
struct V_19 * V_114 ;
if ( F_149 ( V_214 ) ) {
F_138 ( V_19 , V_97 ) ;
F_102 ( V_80 -> V_136 , V_91 , 1 ) ;
} else {
V_114 = F_266 ( V_214 ) ;
F_162 ( V_19 , V_114 , V_97 , V_80 ) ;
F_41 ( F_166 ( V_114 ) != 1 ) ;
F_262 ( V_114 ) ;
F_93 ( V_217 ) ;
F_279 ( V_80 -> V_136 , V_97 , V_213 ) ;
F_164 ( V_114 ) ;
F_95 ( V_217 ) ;
F_280 ( V_114 ) ;
}
V_97 += V_128 ;
V_19 ++ ;
}
}
static void F_281 ( void )
{
F_282 ( V_14 , false ,
F_283 ( V_59 ) ) ;
}
static bool F_284 ( struct V_19 * * V_218 , bool * V_219 )
{
if ( F_10 ( * V_218 ) ) {
if ( ! * V_219 )
return false ;
* V_219 = false ;
* V_218 = NULL ;
F_281 () ;
} else if ( * V_218 ) {
F_97 ( * V_218 ) ;
* V_218 = NULL ;
}
return true ;
}
static struct V_19
* F_285 ( struct V_19 * * V_218 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
int V_220 )
{
F_41 ( * V_218 ) ;
* V_218 = F_104 ( F_286 () , V_80 , V_97 ,
V_220 , V_131 ) ;
F_287 ( & V_86 -> V_211 ) ;
if ( F_9 ( ! * V_218 ) ) {
F_24 ( V_221 ) ;
* V_218 = F_174 ( - V_69 ) ;
return NULL ;
}
F_24 ( V_222 ) ;
return * V_218 ;
}
static struct V_19 * F_288 ( bool * V_219 )
{
struct V_19 * V_218 ;
do {
V_218 = F_106 ( F_286 () ) ;
if ( ! V_218 ) {
F_24 ( V_221 ) ;
if ( ! * V_219 )
return NULL ;
* V_219 = false ;
F_281 () ;
} else
F_24 ( V_222 ) ;
} while ( F_9 ( ! V_218 ) && F_21 ( F_2 () ) );
return V_218 ;
}
static bool F_284 ( struct V_19 * * V_218 , bool * V_219 )
{
if ( ! * V_218 )
* V_218 = F_288 ( V_219 ) ;
if ( F_9 ( ! * V_218 ) )
return false ;
return true ;
}
static struct V_19
* F_285 ( struct V_19 * * V_218 , struct V_85 * V_86 ,
struct V_79 * V_80 , unsigned long V_97 ,
int V_220 )
{
F_287 ( & V_86 -> V_211 ) ;
F_41 ( ! * V_218 ) ;
return * V_218 ;
}
static bool F_289 ( struct V_79 * V_80 )
{
if ( ( ! ( V_80 -> V_81 & V_194 ) && ! F_290 () ) ||
( V_80 -> V_81 & V_163 ) )
return false ;
if ( ! V_80 -> V_118 || V_80 -> V_210 )
return false ;
if ( F_234 ( V_80 ) )
return false ;
F_41 ( V_80 -> V_81 & V_195 ) ;
return true ;
}
static void F_291 ( struct V_85 * V_86 ,
unsigned long V_97 ,
struct V_19 * * V_218 ,
struct V_79 * V_80 ,
int V_220 )
{
T_1 * V_18 , V_122 ;
T_7 * V_100 ;
T_5 V_88 ;
struct V_19 * V_133 ;
T_10 * V_217 ;
int V_223 ;
unsigned long V_208 , V_209 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_41 ( V_97 & ~ V_99 ) ;
V_133 = F_285 ( V_218 , V_86 , V_80 , V_97 , V_220 ) ;
if ( ! V_133 )
return;
if ( F_9 ( F_116 ( V_133 , V_86 , V_108 ) ) )
return;
F_260 ( & V_86 -> V_211 ) ;
if ( F_9 ( F_251 ( V_86 ) ) )
goto V_74;
V_80 = F_292 ( V_86 , V_97 ) ;
V_208 = ( V_80 -> V_101 + ~ V_99 ) & V_99 ;
V_209 = V_80 -> V_103 & V_99 ;
if ( V_97 < V_208 || V_97 + V_102 > V_209 )
goto V_74;
if ( ! F_289 ( V_80 ) )
goto V_74;
V_18 = F_200 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_118 ( * V_18 ) )
goto V_74;
F_236 ( V_80 -> V_118 ) ;
V_100 = F_119 ( V_18 , V_97 ) ;
V_217 = F_293 ( V_86 , V_18 ) ;
V_124 = V_97 ;
V_125 = V_97 + V_102 ;
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
V_122 = F_140 ( V_80 , V_97 , V_18 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
F_93 ( V_217 ) ;
V_223 = F_267 ( V_80 , V_97 , V_100 ) ;
F_95 ( V_217 ) ;
if ( F_9 ( ! V_223 ) ) {
F_151 ( V_100 ) ;
F_93 ( & V_86 -> V_90 ) ;
F_32 ( ! F_94 ( * V_18 ) ) ;
F_100 ( V_86 , V_97 , V_18 , V_122 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_237 ( V_80 -> V_118 ) ;
goto V_74;
}
F_237 ( V_80 -> V_118 ) ;
F_278 ( V_100 , V_133 , V_80 , V_97 , V_217 ) ;
F_151 ( V_100 ) ;
F_92 ( V_133 ) ;
V_88 = F_294 ( V_122 ) ;
V_122 = F_84 ( V_133 , V_80 ) ;
F_152 () ;
F_93 ( & V_86 -> V_90 ) ;
F_32 ( ! F_94 ( * V_18 ) ) ;
F_99 ( V_133 , V_80 , V_97 ) ;
F_100 ( V_86 , V_97 , V_18 , V_122 ) ;
F_135 ( V_80 , V_97 , V_18 ) ;
F_101 ( V_86 , V_88 ) ;
F_95 ( & V_86 -> V_90 ) ;
* V_218 = NULL ;
V_62 ++ ;
V_224:
F_261 ( & V_86 -> V_211 ) ;
return;
V_74:
F_96 ( V_133 ) ;
goto V_224;
}
static int F_295 ( struct V_85 * V_86 ,
struct V_79 * V_80 ,
unsigned long V_97 ,
struct V_19 * * V_218 )
{
T_1 * V_18 ;
T_7 * V_100 , * V_213 ;
int V_48 = 0 , V_215 = 0 , V_216 = 0 ;
struct V_19 * V_19 ;
unsigned long V_225 ;
T_10 * V_217 ;
int V_220 = V_226 ;
F_41 ( V_97 & ~ V_99 ) ;
V_18 = F_200 ( V_86 , V_97 ) ;
if ( ! V_18 )
goto V_74;
if ( F_118 ( * V_18 ) )
goto V_74;
V_100 = F_296 ( V_86 , V_18 , V_97 , & V_217 ) ;
for ( V_225 = V_97 , V_213 = V_100 ; V_213 < V_100 + V_34 ;
V_213 ++ , V_225 += V_128 ) {
T_7 V_214 = * V_213 ;
if ( F_149 ( V_214 ) ) {
if ( ++ V_216 <= V_65 )
continue;
else
goto V_227;
}
if ( ! F_268 ( V_214 ) || ! F_269 ( V_214 ) )
goto V_227;
V_19 = F_270 ( V_80 , V_225 , V_214 ) ;
if ( F_9 ( ! V_19 ) )
goto V_227;
if ( V_220 == V_226 )
V_220 = F_158 ( V_19 ) ;
F_41 ( F_89 ( V_19 ) ) ;
if ( ! F_274 ( V_19 ) || F_273 ( V_19 ) || ! F_213 ( V_19 ) )
goto V_227;
if ( F_223 ( V_19 ) != 1 )
goto V_227;
if ( F_275 ( V_214 ) || F_276 ( V_19 ) ||
F_277 ( V_80 -> V_136 , V_97 ) )
V_215 = 1 ;
}
if ( V_215 )
V_48 = 1 ;
V_227:
F_297 ( V_100 , V_217 ) ;
if ( V_48 )
F_291 ( V_86 , V_97 , V_218 , V_80 , V_220 ) ;
V_74:
return V_48 ;
}
static void F_298 ( struct V_199 * V_199 )
{
struct V_85 * V_86 = V_199 -> V_86 ;
F_41 ( V_228 != 1 && ! F_299 ( & V_205 ) ) ;
if ( F_251 ( V_86 ) ) {
F_257 ( & V_199 -> V_201 ) ;
F_258 ( & V_199 -> V_206 ) ;
F_245 ( V_199 ) ;
F_259 ( V_86 ) ;
}
}
static unsigned int F_300 ( unsigned int V_61 ,
struct V_19 * * V_218 )
__releases( &khugepaged_mm_lock
static int F_301 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_302 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_303 () ;
}
static void F_304 ( void )
{
struct V_19 * V_218 = NULL ;
unsigned int V_229 = 0 , V_230 = 0 ;
unsigned int V_61 = V_60 ;
bool V_219 = true ;
F_305 () ;
while ( V_229 < V_61 ) {
if ( ! F_284 ( & V_218 , & V_219 ) )
break;
F_163 () ;
if ( F_9 ( F_303 () || F_306 ( V_231 ) ) )
break;
F_93 ( & V_205 ) ;
if ( ! V_12 . V_199 )
V_230 ++ ;
if ( F_301 () &&
V_230 < 2 )
V_229 += F_300 ( V_61 - V_229 ,
& V_218 ) ;
else
V_229 = V_61 ;
F_95 ( & V_205 ) ;
}
if ( ! F_307 ( V_218 ) )
F_97 ( V_218 ) ;
}
static void F_308 ( void )
{
F_309 () ;
if ( F_301 () ) {
if ( ! V_56 )
return;
F_282 ( V_14 ,
F_303 () ,
F_283 ( V_56 ) ) ;
return;
}
if ( F_2 () )
F_310 ( V_14 , F_302 () ) ;
}
static int V_10 ( void * V_216 )
{
struct V_199 * V_199 ;
F_311 () ;
F_312 ( V_231 , 19 ) ;
while ( ! F_303 () ) {
F_304 () ;
F_308 () ;
}
F_93 ( & V_205 ) ;
V_199 = V_12 . V_199 ;
V_12 . V_199 = NULL ;
if ( V_199 )
F_298 ( V_199 ) ;
F_95 ( & V_205 ) ;
return 0 ;
}
static void F_313 ( struct V_79 * V_80 ,
unsigned long V_87 , T_1 * V_18 )
{
struct V_85 * V_86 = V_80 -> V_136 ;
T_5 V_88 ;
T_1 V_122 ;
int V_123 ;
F_140 ( V_80 , V_87 , V_18 ) ;
V_88 = F_141 ( V_86 ) ;
F_142 ( V_86 , & V_122 , V_88 ) ;
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ , V_87 += V_128 ) {
T_7 * V_100 , V_83 ;
V_83 = F_146 ( F_147 ( V_87 ) , V_80 -> V_84 ) ;
V_83 = F_148 ( V_83 ) ;
V_100 = F_119 ( & V_122 , V_87 ) ;
F_41 ( ! F_149 ( * V_100 ) ) ;
F_150 ( V_86 , V_87 , V_100 , V_83 ) ;
F_151 ( V_100 ) ;
}
F_152 () ;
F_142 ( V_86 , V_18 , V_88 ) ;
F_31 () ;
}
void F_314 ( struct V_79 * V_80 , unsigned long V_97 ,
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
F_139 ( V_86 , V_124 , V_125 ) ;
F_93 ( & V_86 -> V_90 ) ;
if ( F_9 ( ! F_118 ( * V_18 ) ) ) {
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
return;
}
if ( F_18 ( * V_18 ) ) {
F_313 ( V_80 , V_87 , V_18 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
return;
}
V_19 = F_125 ( * V_18 ) ;
F_41 ( ! F_223 ( V_19 ) ) ;
F_127 ( V_19 ) ;
F_95 ( & V_86 -> V_90 ) ;
F_154 ( V_86 , V_124 , V_125 ) ;
F_169 ( V_19 ) ;
F_97 ( V_19 ) ;
F_32 ( F_118 ( * V_18 ) ) ;
}
void F_315 ( struct V_85 * V_86 , unsigned long V_97 ,
T_1 * V_18 )
{
struct V_79 * V_80 ;
V_80 = F_292 ( V_86 , V_97 ) ;
F_32 ( V_80 == NULL ) ;
F_316 ( V_80 , V_97 , V_18 ) ;
}
static void F_317 ( struct V_85 * V_86 ,
unsigned long V_97 )
{
T_1 * V_18 ;
F_41 ( ! ( V_97 & ~ V_99 ) ) ;
V_18 = F_200 ( V_86 , V_97 ) ;
if ( ! V_18 )
return;
F_315 ( V_86 , V_97 , V_18 ) ;
}
void F_318 ( struct V_79 * V_80 ,
unsigned long V_232 ,
unsigned long V_155 ,
long V_233 )
{
if ( V_232 & ~ V_99 &&
( V_232 & V_99 ) >= V_80 -> V_101 &&
( V_232 & V_99 ) + V_102 <= V_80 -> V_103 )
F_317 ( V_80 -> V_136 , V_232 ) ;
if ( V_155 & ~ V_99 &&
( V_155 & V_99 ) >= V_80 -> V_101 &&
( V_155 & V_99 ) + V_102 <= V_80 -> V_103 )
F_317 ( V_80 -> V_136 , V_155 ) ;
if ( V_233 > 0 ) {
struct V_79 * V_234 = V_80 -> V_235 ;
unsigned long V_236 = V_234 -> V_101 ;
V_236 += V_233 << V_6 ;
if ( V_236 & ~ V_99 &&
( V_236 & V_99 ) >= V_234 -> V_101 &&
( V_236 & V_99 ) + V_102 <= V_234 -> V_103 )
F_317 ( V_234 -> V_136 , V_236 ) ;
}
}
