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
if ( V_3 > V_7 ) {
if ( V_8 >= 0 )
F_6 ( L_1
L_2 ,
V_7 , V_3 ) ;
V_7 = V_3 ;
}
F_7 () ;
return 0 ;
}
static int F_8 ( void )
{
int V_9 = 0 ;
if ( F_2 () ) {
if ( ! V_10 )
V_10 = F_9 ( V_11 , NULL ,
L_3 ) ;
if ( F_10 ( F_11 ( V_10 ) ) ) {
F_12 ( V_12
L_4 ) ;
V_9 = F_13 ( V_10 ) ;
V_10 = NULL ;
}
if ( ! F_14 ( & V_13 . V_14 ) )
F_15 ( & V_15 ) ;
F_1 () ;
} else if ( V_10 ) {
F_16 ( V_10 ) ;
V_10 = NULL ;
}
return V_9 ;
}
static inline bool F_17 ( struct V_16 * V_16 )
{
return F_18 ( V_17 ) == V_16 ;
}
static inline bool F_19 ( T_1 V_18 )
{
return F_17 ( F_20 ( V_18 ) ) ;
}
static struct V_16 * F_21 ( void )
{
struct V_16 * V_19 ;
V_20:
if ( F_22 ( F_23 ( & V_21 ) ) )
return F_18 ( V_17 ) ;
V_19 = F_24 ( ( V_22 | V_23 ) & ~ V_24 ,
V_25 ) ;
if ( ! V_19 ) {
F_25 ( V_26 ) ;
return NULL ;
}
F_25 ( V_27 ) ;
F_26 () ;
if ( F_27 ( & V_17 , NULL , V_19 ) ) {
F_28 () ;
F_29 ( V_19 ) ;
goto V_20;
}
F_30 ( & V_21 , 2 ) ;
F_28 () ;
return F_18 ( V_17 ) ;
}
static void F_31 ( void )
{
F_32 ( F_33 ( & V_21 ) ) ;
}
static unsigned long F_34 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
return F_35 ( & V_21 ) == 1 ? V_32 : 0 ;
}
static unsigned long F_36 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
if ( F_37 ( & V_21 , 1 , 0 ) == 1 ) {
struct V_16 * V_19 = F_38 ( & V_17 , NULL ) ;
F_32 ( V_19 == NULL ) ;
F_29 ( V_19 ) ;
return V_32 ;
}
return 0 ;
}
static T_2 F_39 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( F_40 ( V_39 , & V_41 ) ) {
F_41 ( F_40 ( V_40 , & V_41 ) ) ;
return sprintf ( V_37 , L_5 ) ;
} else if ( F_40 ( V_40 , & V_41 ) )
return sprintf ( V_37 , L_6 ) ;
else
return sprintf ( V_37 , L_7 ) ;
}
static T_2 F_42 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( ! memcmp ( L_8 , V_37 ,
F_4 ( sizeof( L_8 ) - 1 , V_42 ) ) ) {
F_43 ( V_39 , & V_41 ) ;
F_44 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_9 , V_37 ,
F_4 ( sizeof( L_9 ) - 1 , V_42 ) ) ) {
F_44 ( V_39 , & V_41 ) ;
F_43 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_10 , V_37 ,
F_4 ( sizeof( L_10 ) - 1 , V_42 ) ) ) {
F_44 ( V_39 , & V_41 ) ;
F_44 ( V_40 , & V_41 ) ;
} else
return - V_43 ;
return V_42 ;
}
static T_2 F_45 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_39 ( V_34 , V_36 , V_37 ,
V_44 ,
V_45 ) ;
}
static T_2 F_46 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
T_2 V_46 ;
V_46 = F_42 ( V_34 , V_36 , V_37 , V_42 ,
V_44 ,
V_45 ) ;
if ( V_46 > 0 ) {
int V_9 ;
F_47 ( & V_47 ) ;
V_9 = F_8 () ;
F_48 ( & V_47 ) ;
if ( V_9 )
V_46 = V_9 ;
}
return V_46 ;
}
static T_2 F_49 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_48 )
{
return sprintf ( V_37 , L_11 ,
! ! F_40 ( V_48 , & V_41 ) ) ;
}
static T_2 F_50 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_48 )
{
unsigned long V_49 ;
int V_46 ;
V_46 = F_51 ( V_37 , 10 , & V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_49 > 1 )
return - V_43 ;
if ( V_49 )
F_43 ( V_48 , & V_41 ) ;
else
F_44 ( V_48 , & V_41 ) ;
return V_42 ;
}
static T_2 F_52 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_39 ( V_34 , V_36 , V_37 ,
V_50 ,
V_51 ) ;
}
static T_2 F_53 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_42 ( V_34 , V_36 , V_37 , V_42 ,
V_50 ,
V_51 ) ;
}
static T_2 F_54 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_49 ( V_34 , V_36 , V_37 ,
V_52 ) ;
}
static T_2 F_55 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_42 )
{
return F_50 ( V_34 , V_36 , V_37 , V_42 ,
V_52 ) ;
}
static T_2 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_49 ( V_34 , V_36 , V_37 ,
V_53 ) ;
}
static T_2 F_57 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_50 ( V_34 , V_36 , V_37 , V_42 ,
V_53 ) ;
}
static T_2 F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_54 ) ;
}
static T_2 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_9 ;
V_9 = F_51 ( V_37 , 10 , & V_55 ) ;
if ( V_9 || V_55 > V_56 )
return - V_43 ;
V_54 = V_55 ;
F_15 ( & V_15 ) ;
return V_42 ;
}
static T_2 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_57 ) ;
}
static T_2 F_61 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_9 ;
V_9 = F_51 ( V_37 , 10 , & V_55 ) ;
if ( V_9 || V_55 > V_56 )
return - V_43 ;
V_57 = V_55 ;
F_15 ( & V_15 ) ;
return V_42 ;
}
static T_2 F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_58 ) ;
}
static T_2 F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_9 ;
unsigned long V_59 ;
V_9 = F_51 ( V_37 , 10 , & V_59 ) ;
if ( V_9 || ! V_59 || V_59 > V_56 )
return - V_43 ;
V_58 = V_59 ;
return V_42 ;
}
static T_2 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_60 ) ;
}
static T_2 F_65 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_61 ) ;
}
static T_2 F_66 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_49 ( V_34 , V_36 , V_37 ,
V_62 ) ;
}
static T_2 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_50 ( V_34 , V_36 , V_37 , V_42 ,
V_62 ) ;
}
static T_2 F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_63 ) ;
}
static T_2 F_69 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_9 ;
unsigned long V_64 ;
V_9 = F_51 ( V_37 , 10 , & V_64 ) ;
if ( V_9 || V_64 > V_32 - 1 )
return - V_43 ;
V_63 = V_64 ;
return V_42 ;
}
static int T_4 F_70 ( struct V_33 * * V_65 )
{
int V_9 ;
* V_65 = F_71 ( L_13 , V_66 ) ;
if ( F_10 ( ! * V_65 ) ) {
F_12 ( V_12 L_14 ) ;
return - V_67 ;
}
V_9 = F_72 ( * V_65 , & V_68 ) ;
if ( V_9 ) {
F_12 ( V_12 L_15 ) ;
goto V_69;
}
V_9 = F_72 ( * V_65 , & V_70 ) ;
if ( V_9 ) {
F_12 ( V_12 L_15 ) ;
goto V_71;
}
return 0 ;
V_71:
F_73 ( * V_65 , & V_68 ) ;
V_69:
F_74 ( * V_65 ) ;
return V_9 ;
}
static void T_4 F_75 ( struct V_33 * V_65 )
{
F_73 ( V_65 , & V_70 ) ;
F_73 ( V_65 , & V_68 ) ;
F_74 ( V_65 ) ;
}
static inline int F_70 ( struct V_33 * * V_65 )
{
return 0 ;
}
static inline void F_75 ( struct V_33 * V_65 )
{
}
static int T_4 F_76 ( void )
{
int V_9 ;
struct V_33 * V_65 ;
if ( ! F_77 () ) {
V_41 = 0 ;
return - V_43 ;
}
V_9 = F_70 ( & V_65 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_78 () ;
if ( V_9 )
goto V_72;
F_79 ( & V_73 ) ;
if ( V_74 < ( 512 << ( 20 - V_6 ) ) )
V_41 = 0 ;
F_8 () ;
return 0 ;
V_72:
F_75 ( V_65 ) ;
return V_9 ;
}
static int T_4 F_80 ( char * V_75 )
{
int V_46 = 0 ;
if ( ! V_75 )
goto V_72;
if ( ! strcmp ( V_75 , L_8 ) ) {
F_43 ( V_44 ,
& V_41 ) ;
F_44 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_75 , L_9 ) ) {
F_44 ( V_44 ,
& V_41 ) ;
F_43 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_75 , L_10 ) ) {
F_44 ( V_44 ,
& V_41 ) ;
F_44 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
}
V_72:
if ( ! V_46 )
F_12 ( V_76
L_16 ) ;
return V_46 ;
}
T_1 F_81 ( T_1 V_18 , struct V_77 * V_78 )
{
if ( F_22 ( V_78 -> V_79 & V_80 ) )
V_18 = F_82 ( V_18 ) ;
return V_18 ;
}
static inline T_1 F_83 ( struct V_16 * V_16 , T_5 V_81 )
{
T_1 V_82 ;
V_82 = F_84 ( V_16 , V_81 ) ;
V_82 = F_85 ( V_82 ) ;
return V_82 ;
}
static int F_86 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_85 , T_1 * V_18 ,
struct V_16 * V_16 )
{
T_6 V_86 ;
T_7 * V_87 ;
F_87 ( ! F_88 ( V_16 ) , V_16 ) ;
V_86 = F_89 ( V_84 , V_85 ) ;
if ( F_10 ( ! V_86 ) )
return V_88 ;
F_90 ( V_16 , V_85 , V_32 ) ;
F_91 ( V_16 ) ;
V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_10 ( ! F_93 ( * V_18 ) ) ) {
F_94 ( V_87 ) ;
F_95 ( V_16 ) ;
F_96 ( V_16 ) ;
F_97 ( V_84 , V_86 ) ;
} else {
T_1 V_82 ;
V_82 = F_83 ( V_16 , V_78 -> V_89 ) ;
V_82 = F_81 ( F_98 ( V_82 ) , V_78 ) ;
F_99 ( V_16 , V_78 , V_85 ) ;
F_100 ( V_84 , V_18 , V_86 ) ;
F_101 ( V_84 , V_85 , V_18 , V_82 ) ;
F_102 ( V_84 , V_90 , V_32 ) ;
F_103 ( & V_84 -> V_91 ) ;
F_94 ( V_87 ) ;
}
return 0 ;
}
static inline T_8 F_104 ( int V_92 , T_8 V_93 )
{
return ( V_22 & ~ ( V_92 ? 0 : V_94 ) ) | V_93 ;
}
static inline struct V_16 * F_105 ( int V_92 ,
struct V_77 * V_78 ,
unsigned long V_85 , int V_95 ,
T_8 V_93 )
{
return F_106 ( F_104 ( V_92 , V_93 ) ,
V_25 , V_78 , V_85 , V_95 ) ;
}
static bool F_107 ( T_6 V_86 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_85 , T_1 * V_18 ,
struct V_16 * V_19 )
{
T_1 V_82 ;
if ( ! F_93 ( * V_18 ) )
return false ;
V_82 = F_84 ( V_19 , V_78 -> V_89 ) ;
V_82 = F_108 ( V_82 ) ;
V_82 = F_85 ( V_82 ) ;
F_100 ( V_84 , V_18 , V_86 ) ;
F_101 ( V_84 , V_85 , V_18 , V_82 ) ;
F_103 ( & V_84 -> V_91 ) ;
return true ;
}
int F_109 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_96 , T_1 * V_18 ,
unsigned int V_97 )
{
struct V_16 * V_16 ;
unsigned long V_85 = V_96 & V_98 ;
if ( V_85 < V_78 -> V_99 || V_85 + V_100 > V_78 -> V_101 )
return V_102 ;
if ( F_10 ( F_110 ( V_78 ) ) )
return V_88 ;
if ( F_10 ( F_111 ( V_78 ) ) )
return V_88 ;
if ( ! ( V_97 & V_103 ) &&
F_112 () ) {
T_7 * V_87 ;
T_6 V_86 ;
struct V_16 * V_19 ;
bool V_104 ;
V_86 = F_89 ( V_84 , V_85 ) ;
if ( F_10 ( ! V_86 ) )
return V_88 ;
V_19 = F_21 () ;
if ( F_10 ( ! V_19 ) ) {
F_97 ( V_84 , V_86 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
V_87 = F_92 ( V_84 , V_18 ) ;
V_104 = F_107 ( V_86 , V_84 , V_78 , V_85 , V_18 ,
V_19 ) ;
F_94 ( V_87 ) ;
if ( ! V_104 ) {
F_97 ( V_84 , V_86 ) ;
F_31 () ;
}
return 0 ;
}
V_16 = F_105 ( F_113 ( V_78 ) ,
V_78 , V_85 , F_114 () , 0 ) ;
if ( F_10 ( ! V_16 ) ) {
F_25 ( V_105 ) ;
return V_102 ;
}
if ( F_10 ( F_115 ( V_16 , V_84 , V_106 ) ) ) {
F_96 ( V_16 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
if ( F_10 ( F_86 ( V_84 , V_78 , V_85 , V_18 , V_16 ) ) ) {
F_95 ( V_16 ) ;
F_96 ( V_16 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
F_25 ( V_107 ) ;
return 0 ;
}
int F_116 ( struct V_83 * V_108 , struct V_83 * V_109 ,
T_1 * V_110 , T_1 * V_111 , unsigned long V_112 ,
struct V_77 * V_78 )
{
T_7 * V_113 , * V_114 ;
struct V_16 * V_115 ;
T_1 V_18 ;
T_6 V_86 ;
int V_46 ;
V_46 = - V_67 ;
V_86 = F_89 ( V_108 , V_112 ) ;
if ( F_10 ( ! V_86 ) )
goto V_72;
V_113 = F_92 ( V_108 , V_110 ) ;
V_114 = F_117 ( V_109 , V_111 ) ;
F_118 ( V_114 , V_116 ) ;
V_46 = - V_117 ;
V_18 = * V_111 ;
if ( F_10 ( ! F_119 ( V_18 ) ) ) {
F_97 ( V_108 , V_86 ) ;
goto V_118;
}
if ( F_19 ( V_18 ) ) {
struct V_16 * V_19 ;
bool V_104 ;
V_19 = F_21 () ;
V_104 = F_107 ( V_86 , V_108 , V_78 , V_112 , V_110 ,
V_19 ) ;
F_32 ( ! V_104 ) ;
V_46 = 0 ;
goto V_118;
}
if ( F_10 ( F_120 ( V_18 ) ) ) {
F_94 ( V_114 ) ;
F_94 ( V_113 ) ;
F_97 ( V_108 , V_86 ) ;
F_121 ( V_78 -> V_119 , V_111 ) ;
goto V_72;
}
V_115 = F_20 ( V_18 ) ;
F_87 ( ! F_122 ( V_115 ) , V_115 ) ;
F_123 ( V_115 ) ;
F_124 ( V_115 ) ;
F_102 ( V_108 , V_90 , V_32 ) ;
F_125 ( V_109 , V_112 , V_111 ) ;
V_18 = F_126 ( F_108 ( V_18 ) ) ;
F_100 ( V_108 , V_110 , V_86 ) ;
F_101 ( V_108 , V_112 , V_110 , V_18 ) ;
F_103 ( & V_108 -> V_91 ) ;
V_46 = 0 ;
V_118:
F_94 ( V_114 ) ;
F_94 ( V_113 ) ;
V_72:
return V_46 ;
}
void F_127 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_96 ,
T_1 * V_18 , T_1 V_120 ,
int V_121 )
{
T_7 * V_87 ;
T_1 V_82 ;
unsigned long V_85 ;
V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_10 ( ! F_128 ( * V_18 , V_120 ) ) )
goto V_122;
V_82 = F_129 ( V_120 ) ;
V_85 = V_96 & V_98 ;
if ( F_130 ( V_78 , V_85 , V_18 , V_82 , V_121 ) )
F_131 ( V_78 , V_96 , V_18 ) ;
V_122:
F_94 ( V_87 ) ;
}
static int F_132 ( struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_96 ,
T_1 * V_18 , T_1 V_120 , unsigned long V_85 )
{
T_7 * V_87 ;
T_6 V_86 ;
T_1 V_123 ;
struct V_16 * V_16 ;
int V_124 , V_46 = 0 ;
unsigned long V_125 ;
unsigned long V_126 ;
V_16 = F_133 ( V_127 , V_78 , V_96 ) ;
if ( ! V_16 ) {
V_46 |= V_88 ;
goto V_72;
}
if ( F_115 ( V_16 , V_84 , V_106 ) ) {
F_96 ( V_16 ) ;
V_46 |= V_88 ;
goto V_72;
}
F_134 ( V_16 , V_96 ) ;
F_91 ( V_16 ) ;
V_125 = V_85 ;
V_126 = V_85 + V_100 ;
F_135 ( V_84 , V_125 , V_126 ) ;
V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_10 ( ! F_128 ( * V_18 , V_120 ) ) )
goto V_128;
F_136 ( V_78 , V_85 , V_18 ) ;
V_86 = F_137 ( V_84 , V_18 ) ;
F_138 ( V_84 , & V_123 , V_86 ) ;
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ , V_85 += V_129 ) {
T_9 * V_130 , V_82 ;
if ( V_85 == ( V_96 & V_131 ) ) {
V_82 = F_139 ( V_16 , V_78 -> V_89 ) ;
V_82 = F_140 ( F_141 ( V_82 ) , V_78 ) ;
F_99 ( V_16 , V_78 , V_85 ) ;
} else {
V_82 = F_142 ( F_143 ( V_85 ) , V_78 -> V_89 ) ;
V_82 = F_144 ( V_82 ) ;
}
V_130 = F_145 ( & V_123 , V_85 ) ;
F_41 ( ! F_146 ( * V_130 ) ) ;
F_147 ( V_84 , V_85 , V_130 , V_82 ) ;
F_148 ( V_130 ) ;
}
F_149 () ;
F_138 ( V_84 , V_18 , V_86 ) ;
F_94 ( V_87 ) ;
F_31 () ;
F_150 ( V_84 , V_90 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
V_46 |= V_132 ;
V_72:
return V_46 ;
V_128:
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
F_95 ( V_16 ) ;
F_96 ( V_16 ) ;
goto V_72;
}
static int F_152 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_96 ,
T_1 * V_18 , T_1 V_120 ,
struct V_16 * V_16 ,
unsigned long V_85 )
{
T_7 * V_87 ;
T_6 V_86 ;
T_1 V_123 ;
int V_46 = 0 , V_124 ;
struct V_16 * * V_59 ;
unsigned long V_125 ;
unsigned long V_126 ;
V_59 = F_153 ( sizeof( struct V_16 * ) * V_32 ,
V_106 ) ;
if ( F_10 ( ! V_59 ) ) {
V_46 |= V_88 ;
goto V_72;
}
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ ) {
V_59 [ V_124 ] = F_154 ( V_127 |
V_133 ,
V_78 , V_96 , F_155 ( V_16 ) ) ;
if ( F_10 ( ! V_59 [ V_124 ] ||
F_115 ( V_59 [ V_124 ] , V_84 ,
V_106 ) ) ) {
if ( V_59 [ V_124 ] )
F_96 ( V_59 [ V_124 ] ) ;
F_156 () ;
while ( -- V_124 >= 0 ) {
F_95 ( V_59 [ V_124 ] ) ;
F_96 ( V_59 [ V_124 ] ) ;
}
F_157 () ;
F_158 ( V_59 ) ;
V_46 |= V_88 ;
goto V_72;
}
}
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ ) {
F_159 ( V_59 [ V_124 ] , V_16 + V_124 ,
V_85 + V_129 * V_124 , V_78 ) ;
F_91 ( V_59 [ V_124 ] ) ;
F_160 () ;
}
V_125 = V_85 ;
V_126 = V_85 + V_100 ;
F_135 ( V_84 , V_125 , V_126 ) ;
V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_10 ( ! F_128 ( * V_18 , V_120 ) ) )
goto V_134;
F_87 ( ! F_122 ( V_16 ) , V_16 ) ;
F_136 ( V_78 , V_85 , V_18 ) ;
V_86 = F_137 ( V_84 , V_18 ) ;
F_138 ( V_84 , & V_123 , V_86 ) ;
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ , V_85 += V_129 ) {
T_9 * V_130 , V_82 ;
V_82 = F_139 ( V_59 [ V_124 ] , V_78 -> V_89 ) ;
V_82 = F_140 ( F_141 ( V_82 ) , V_78 ) ;
F_99 ( V_59 [ V_124 ] , V_78 , V_85 ) ;
V_130 = F_145 ( & V_123 , V_85 ) ;
F_41 ( ! F_146 ( * V_130 ) ) ;
F_147 ( V_84 , V_85 , V_130 , V_82 ) ;
F_148 ( V_130 ) ;
}
F_158 ( V_59 ) ;
F_149 () ;
F_138 ( V_84 , V_18 , V_86 ) ;
F_161 ( V_16 ) ;
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
V_46 |= V_132 ;
F_96 ( V_16 ) ;
V_72:
return V_46 ;
V_134:
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
F_156 () ;
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ ) {
F_95 ( V_59 [ V_124 ] ) ;
F_96 ( V_59 [ V_124 ] ) ;
}
F_157 () ;
F_158 ( V_59 ) ;
goto V_72;
}
int F_162 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_96 , T_1 * V_18 , T_1 V_120 )
{
T_7 * V_87 ;
int V_46 = 0 ;
struct V_16 * V_16 = NULL , * V_135 ;
unsigned long V_85 ;
unsigned long V_125 ;
unsigned long V_126 ;
V_87 = F_117 ( V_84 , V_18 ) ;
F_41 ( ! V_78 -> V_119 ) ;
V_85 = V_96 & V_98 ;
if ( F_19 ( V_120 ) )
goto V_136;
F_163 ( V_87 ) ;
if ( F_10 ( ! F_128 ( * V_18 , V_120 ) ) )
goto V_118;
V_16 = F_20 ( V_120 ) ;
F_87 ( ! F_88 ( V_16 ) || ! F_122 ( V_16 ) , V_16 ) ;
if ( F_164 ( V_16 ) == 1 ) {
T_1 V_82 ;
V_82 = F_129 ( V_120 ) ;
V_82 = F_81 ( F_98 ( V_82 ) , V_78 ) ;
if ( F_130 ( V_78 , V_85 , V_18 , V_82 , 1 ) )
F_131 ( V_78 , V_96 , V_18 ) ;
V_46 |= V_132 ;
goto V_118;
}
F_123 ( V_16 ) ;
F_94 ( V_87 ) ;
V_136:
if ( F_165 ( V_78 ) &&
! F_166 () )
V_135 = F_105 ( F_113 ( V_78 ) ,
V_78 , V_85 , F_114 () , 0 ) ;
else
V_135 = NULL ;
if ( F_10 ( ! V_135 ) ) {
if ( ! V_16 ) {
V_46 = F_132 ( V_84 , V_78 ,
V_96 , V_18 , V_120 , V_85 ) ;
} else {
V_46 = F_152 ( V_84 , V_78 , V_96 ,
V_18 , V_120 , V_16 , V_85 ) ;
if ( V_46 & V_88 ) {
F_167 ( V_16 ) ;
V_46 |= V_102 ;
}
F_96 ( V_16 ) ;
}
F_25 ( V_105 ) ;
goto V_72;
}
if ( F_10 ( F_115 ( V_135 , V_84 , V_106 ) ) ) {
F_96 ( V_135 ) ;
if ( V_16 ) {
F_167 ( V_16 ) ;
F_96 ( V_16 ) ;
} else
F_168 ( V_78 , V_96 , V_18 ) ;
V_46 |= V_102 ;
F_25 ( V_105 ) ;
goto V_72;
}
F_25 ( V_107 ) ;
if ( ! V_16 )
F_90 ( V_135 , V_85 , V_32 ) ;
else
F_169 ( V_135 , V_16 , V_85 , V_78 , V_32 ) ;
F_91 ( V_135 ) ;
V_125 = V_85 ;
V_126 = V_85 + V_100 ;
F_135 ( V_84 , V_125 , V_126 ) ;
F_163 ( V_87 ) ;
if ( V_16 )
F_96 ( V_16 ) ;
if ( F_10 ( ! F_128 ( * V_18 , V_120 ) ) ) {
F_94 ( V_87 ) ;
F_95 ( V_135 ) ;
F_96 ( V_135 ) ;
goto V_137;
} else {
T_1 V_82 ;
V_82 = F_83 ( V_135 , V_78 -> V_89 ) ;
V_82 = F_81 ( F_98 ( V_82 ) , V_78 ) ;
F_136 ( V_78 , V_85 , V_18 ) ;
F_99 ( V_135 , V_78 , V_85 ) ;
F_101 ( V_84 , V_85 , V_18 , V_82 ) ;
F_131 ( V_78 , V_96 , V_18 ) ;
if ( ! V_16 ) {
F_102 ( V_84 , V_90 , V_32 ) ;
F_31 () ;
} else {
F_87 ( ! F_122 ( V_16 ) , V_16 ) ;
F_161 ( V_16 ) ;
F_96 ( V_16 ) ;
}
V_46 |= V_132 ;
}
F_94 ( V_87 ) ;
V_137:
F_151 ( V_84 , V_125 , V_126 ) ;
V_72:
return V_46 ;
V_118:
F_94 ( V_87 ) ;
return V_46 ;
}
struct V_16 * F_170 ( struct V_77 * V_78 ,
unsigned long V_112 ,
T_1 * V_18 ,
unsigned int V_97 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
struct V_16 * V_16 = NULL ;
F_171 ( F_117 ( V_84 , V_18 ) ) ;
if ( V_97 & V_139 && ! F_172 ( * V_18 ) )
goto V_72;
if ( ( V_97 & V_140 ) && F_19 ( * V_18 ) )
return F_173 ( - V_141 ) ;
if ( ( V_97 & V_142 ) && F_174 ( * V_18 ) )
goto V_72;
V_16 = F_20 ( * V_18 ) ;
F_87 ( ! F_122 ( V_16 ) , V_16 ) ;
if ( V_97 & V_143 ) {
T_1 V_123 ;
V_123 = F_129 ( F_98 ( * V_18 ) ) ;
if ( F_130 ( V_78 , V_112 & V_98 ,
V_18 , V_123 , 1 ) )
F_131 ( V_78 , V_112 , V_18 ) ;
}
if ( ( V_97 & V_144 ) && ( V_78 -> V_79 & V_145 ) ) {
if ( V_16 -> V_146 && F_175 ( V_16 ) ) {
F_176 () ;
if ( V_16 -> V_146 )
F_177 ( V_16 ) ;
F_178 ( V_16 ) ;
}
}
V_16 += ( V_112 & ~ V_98 ) >> V_6 ;
F_87 ( ! F_88 ( V_16 ) , V_16 ) ;
if ( V_97 & V_147 )
F_179 ( V_16 ) ;
V_72:
return V_16 ;
}
int F_180 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_112 , T_1 V_18 , T_1 * V_148 )
{
T_7 * V_87 ;
struct V_119 * V_119 = NULL ;
struct V_16 * V_16 ;
unsigned long V_85 = V_112 & V_98 ;
int V_149 = - 1 , V_150 = F_114 () ;
int V_151 , V_152 = - 1 ;
bool V_153 ;
bool V_154 = false ;
int V_97 = 0 ;
V_87 = F_92 ( V_84 , V_148 ) ;
if ( F_10 ( ! F_128 ( V_18 , * V_148 ) ) )
goto V_118;
if ( F_10 ( F_181 ( * V_148 ) ) ) {
F_94 ( V_87 ) ;
F_182 ( V_78 -> V_119 , V_148 ) ;
goto V_72;
}
V_16 = F_20 ( V_18 ) ;
F_32 ( F_17 ( V_16 ) ) ;
V_149 = F_155 ( V_16 ) ;
V_152 = F_183 ( V_16 ) ;
F_184 ( V_155 ) ;
if ( V_149 == V_150 ) {
F_184 ( V_156 ) ;
V_97 |= V_157 ;
}
if ( ! F_172 ( V_18 ) )
V_97 |= V_158 ;
V_153 = F_175 ( V_16 ) ;
V_151 = F_185 ( V_16 , V_78 , V_85 ) ;
if ( V_151 == - 1 ) {
if ( V_153 )
goto V_159;
}
if ( ! V_153 ) {
F_94 ( V_87 ) ;
F_186 ( V_16 ) ;
V_149 = - 1 ;
goto V_72;
}
F_123 ( V_16 ) ;
F_94 ( V_87 ) ;
V_119 = F_187 ( V_16 ) ;
F_163 ( V_87 ) ;
if ( F_10 ( ! F_128 ( V_18 , * V_148 ) ) ) {
F_178 ( V_16 ) ;
F_96 ( V_16 ) ;
V_149 = - 1 ;
goto V_118;
}
if ( F_10 ( ! V_119 ) ) {
F_96 ( V_16 ) ;
V_149 = - 1 ;
goto V_159;
}
F_94 ( V_87 ) ;
V_154 = F_188 ( V_84 , V_78 ,
V_148 , V_18 , V_112 , V_16 , V_151 ) ;
if ( V_154 ) {
V_97 |= V_160 ;
V_149 = V_151 ;
}
goto V_72;
V_159:
F_32 ( ! F_189 ( V_16 ) ) ;
V_18 = F_190 ( V_18 ) ;
F_101 ( V_84 , V_85 , V_148 , V_18 ) ;
F_41 ( F_174 ( * V_148 ) ) ;
F_131 ( V_78 , V_112 , V_148 ) ;
F_178 ( V_16 ) ;
V_118:
F_94 ( V_87 ) ;
V_72:
if ( V_119 )
F_191 ( V_119 ) ;
if ( V_149 != - 1 )
F_192 ( V_152 , V_149 , V_32 , V_97 ) ;
return 0 ;
}
int F_193 ( struct V_161 * V_162 , struct V_77 * V_78 ,
T_1 * V_18 , unsigned long V_112 )
{
T_7 * V_87 ;
int V_46 = 0 ;
if ( F_194 ( V_18 , V_78 , & V_87 ) == 1 ) {
struct V_16 * V_16 ;
T_6 V_86 ;
T_1 V_120 ;
V_120 = F_195 ( V_162 -> V_84 , V_112 , V_18 ) ;
F_196 ( V_162 , V_18 , V_112 ) ;
V_86 = F_137 ( V_162 -> V_84 , V_18 ) ;
if ( F_19 ( V_120 ) ) {
F_197 ( & V_162 -> V_84 -> V_91 ) ;
F_94 ( V_87 ) ;
F_31 () ;
} else {
V_16 = F_20 ( V_120 ) ;
F_161 ( V_16 ) ;
F_87 ( F_164 ( V_16 ) < 0 , V_16 ) ;
F_102 ( V_162 -> V_84 , V_90 , - V_32 ) ;
F_87 ( ! F_122 ( V_16 ) , V_16 ) ;
F_197 ( & V_162 -> V_84 -> V_91 ) ;
F_94 ( V_87 ) ;
F_198 ( V_162 , V_16 ) ;
}
F_97 ( V_162 -> V_84 , V_86 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_199 ( struct V_77 * V_78 , T_1 * V_18 ,
unsigned long V_112 , unsigned long V_163 ,
unsigned char * V_164 )
{
T_7 * V_87 ;
int V_46 = 0 ;
if ( F_194 ( V_18 , V_78 , & V_87 ) == 1 ) {
F_94 ( V_87 ) ;
memset ( V_164 , 1 , ( V_163 - V_112 ) >> V_6 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_200 ( struct V_77 * V_78 , struct V_77 * V_165 ,
unsigned long V_166 ,
unsigned long V_167 , unsigned long V_168 ,
T_1 * V_169 , T_1 * V_170 )
{
T_7 * V_171 , * V_172 ;
int V_46 = 0 ;
T_1 V_18 ;
struct V_83 * V_84 = V_78 -> V_138 ;
if ( ( V_166 & ~ V_98 ) ||
( V_167 & ~ V_98 ) ||
V_168 - V_166 < V_100 ||
( V_165 -> V_79 & V_173 ) )
goto V_72;
if ( F_201 ( ! F_93 ( * V_170 ) ) ) {
F_41 ( F_119 ( * V_170 ) ) ;
goto V_72;
}
V_46 = F_194 ( V_169 , V_78 , & V_171 ) ;
if ( V_46 == 1 ) {
V_172 = F_117 ( V_84 , V_170 ) ;
if ( V_172 != V_171 )
F_118 ( V_172 , V_116 ) ;
V_18 = F_195 ( V_84 , V_166 , V_169 ) ;
F_41 ( ! F_93 ( * V_170 ) ) ;
if ( F_202 ( V_172 , V_171 ) ) {
T_6 V_86 ;
V_86 = F_137 ( V_84 , V_169 ) ;
F_100 ( V_84 , V_170 , V_86 ) ;
}
F_101 ( V_84 , V_167 , V_170 , F_203 ( V_18 ) ) ;
if ( V_172 != V_171 )
F_94 ( V_172 ) ;
F_94 ( V_171 ) ;
}
V_72:
return V_46 ;
}
int F_204 ( struct V_77 * V_78 , T_1 * V_18 ,
unsigned long V_112 , T_5 V_174 , int V_175 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
T_7 * V_87 ;
int V_46 = 0 ;
if ( F_194 ( V_18 , V_78 , & V_87 ) == 1 ) {
T_1 V_82 ;
V_46 = 1 ;
if ( ! V_175 ) {
V_82 = F_195 ( V_84 , V_112 , V_18 ) ;
if ( F_174 ( V_82 ) )
V_82 = F_190 ( V_82 ) ;
V_82 = F_205 ( V_82 , V_174 ) ;
V_46 = V_32 ;
F_101 ( V_84 , V_112 , V_18 , V_82 ) ;
F_32 ( F_172 ( V_82 ) ) ;
} else {
struct V_16 * V_16 = F_20 ( * V_18 ) ;
if ( ! F_17 ( V_16 ) &&
! F_174 ( * V_18 ) ) {
F_206 ( V_84 , V_112 , V_18 ) ;
V_46 = V_32 ;
}
}
F_94 ( V_87 ) ;
}
return V_46 ;
}
int F_194 ( T_1 * V_18 , struct V_77 * V_78 ,
T_7 * * V_87 )
{
* V_87 = F_92 ( V_78 -> V_138 , V_18 ) ;
if ( F_22 ( F_119 ( * V_18 ) ) ) {
if ( F_10 ( F_120 ( * V_18 ) ) ) {
F_94 ( * V_87 ) ;
F_121 ( V_78 -> V_119 , V_18 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_94 ( * V_87 ) ;
return 0 ;
}
T_1 * F_207 ( struct V_16 * V_16 ,
struct V_83 * V_84 ,
unsigned long V_96 ,
enum V_176 V_48 ,
T_7 * * V_87 )
{
T_1 * V_18 ;
if ( V_96 & ~ V_98 )
return NULL ;
V_18 = F_208 ( V_84 , V_96 ) ;
if ( ! V_18 )
return NULL ;
* V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_93 ( * V_18 ) )
goto V_122;
if ( F_20 ( * V_18 ) != V_16 )
goto V_122;
if ( V_48 == V_177 &&
F_120 ( * V_18 ) )
goto V_122;
if ( F_119 ( * V_18 ) ) {
F_41 ( V_48 == V_178 &&
! F_120 ( * V_18 ) ) ;
return V_18 ;
}
V_122:
F_94 ( * V_87 ) ;
return NULL ;
}
static int F_209 ( struct V_16 * V_16 ,
struct V_77 * V_78 ,
unsigned long V_96 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
T_7 * V_87 ;
T_1 * V_18 ;
int V_46 = 0 ;
const unsigned long V_125 = V_96 ;
const unsigned long V_126 = V_96 + V_100 ;
F_135 ( V_84 , V_125 , V_126 ) ;
V_18 = F_207 ( V_16 , V_84 , V_96 ,
V_177 , & V_87 ) ;
if ( V_18 ) {
F_210 ( V_78 , V_96 , V_18 ) ;
V_46 = 1 ;
F_94 ( V_87 ) ;
}
F_151 ( V_84 , V_125 , V_126 ) ;
return V_46 ;
}
static void F_211 ( struct V_16 * V_16 ,
struct V_179 * V_180 )
{
int V_124 ;
struct V_1 * V_1 = F_212 ( V_16 ) ;
struct V_181 * V_181 ;
int V_182 = 0 ;
F_213 ( & V_1 -> V_183 ) ;
V_181 = F_214 ( V_16 , V_1 ) ;
F_215 ( V_16 ) ;
F_216 ( V_16 ) ;
for ( V_124 = V_32 - 1 ; V_124 >= 1 ; V_124 -- ) {
struct V_16 * V_184 = V_16 + V_124 ;
F_32 ( F_164 ( V_184 ) < 0 ) ;
V_182 += F_164 ( V_184 ) ;
F_32 ( V_182 < 0 ) ;
F_32 ( F_35 ( & V_184 -> V_185 ) != 0 ) ;
F_217 ( F_164 ( V_16 ) + F_164 ( V_184 ) + 1 ,
& V_184 -> V_185 ) ;
F_218 () ;
V_184 -> V_97 &= ~ V_186 | V_187 ;
V_184 -> V_97 |= ( V_16 -> V_97 &
( ( 1L << V_188 ) |
( 1L << V_189 ) |
( 1L << V_190 ) |
( 1L << V_191 ) |
( 1L << V_192 ) |
( 1L << V_193 ) ) ) ;
V_184 -> V_97 |= ( 1L << V_194 ) ;
F_149 () ;
V_184 -> V_195 = V_16 -> V_195 ;
F_32 ( V_184 -> V_146 ) ;
V_184 -> V_146 = V_16 -> V_146 ;
V_184 -> V_196 = V_16 -> V_196 + V_124 ;
F_219 ( V_184 , F_183 ( V_16 ) ) ;
F_32 ( ! F_220 ( V_184 ) ) ;
F_32 ( ! F_221 ( V_184 ) ) ;
F_32 ( ! F_222 ( V_184 ) ) ;
F_32 ( ! F_223 ( V_184 ) ) ;
F_224 ( V_16 , V_184 , V_181 , V_180 ) ;
}
F_225 ( V_182 , & V_16 -> V_185 ) ;
F_32 ( F_35 ( & V_16 -> V_185 ) <= 0 ) ;
F_226 ( V_1 , V_197 , - 1 ) ;
F_227 ( V_16 ) ;
F_228 ( V_16 ) ;
F_229 ( & V_1 -> V_183 ) ;
for ( V_124 = 1 ; V_124 < V_32 ; V_124 ++ ) {
struct V_16 * V_184 = V_16 + V_124 ;
F_32 ( F_230 ( V_184 ) <= 0 ) ;
F_96 ( V_184 ) ;
}
F_32 ( F_230 ( V_16 ) <= 0 ) ;
}
static int F_231 ( struct V_16 * V_16 ,
struct V_77 * V_78 ,
unsigned long V_96 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
T_7 * V_87 ;
T_1 * V_18 , V_123 ;
int V_46 = 0 , V_124 ;
T_6 V_86 ;
unsigned long V_85 ;
V_18 = F_207 ( V_16 , V_84 , V_96 ,
V_178 , & V_87 ) ;
if ( V_18 ) {
V_86 = F_137 ( V_84 , V_18 ) ;
F_138 ( V_84 , & V_123 , V_86 ) ;
V_85 = V_96 ;
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ , V_85 += V_129 ) {
T_9 * V_130 , V_82 ;
F_32 ( F_88 ( V_16 + V_124 ) ) ;
V_82 = F_139 ( V_16 + V_124 , V_78 -> V_89 ) ;
V_82 = F_140 ( F_141 ( V_82 ) , V_78 ) ;
if ( ! F_172 ( * V_18 ) )
V_82 = F_232 ( V_82 ) ;
else
F_32 ( F_164 ( V_16 ) != 1 ) ;
if ( ! F_233 ( * V_18 ) )
V_82 = F_234 ( V_82 ) ;
if ( F_174 ( * V_18 ) )
V_82 = F_235 ( V_82 ) ;
V_130 = F_145 ( & V_123 , V_85 ) ;
F_32 ( ! F_146 ( * V_130 ) ) ;
F_147 ( V_84 , V_85 , V_130 , V_82 ) ;
F_148 ( V_130 ) ;
}
F_149 () ;
F_236 ( V_78 , V_96 , V_18 ) ;
F_138 ( V_84 , V_18 , V_86 ) ;
V_46 = 1 ;
F_94 ( V_87 ) ;
}
return V_46 ;
}
static void F_237 ( struct V_16 * V_16 ,
struct V_119 * V_119 ,
struct V_179 * V_180 )
{
int V_198 , V_199 ;
T_10 V_200 = V_16 -> V_196 << ( V_201 - V_6 ) ;
struct V_202 * V_203 ;
F_32 ( ! F_122 ( V_16 ) ) ;
F_32 ( F_238 ( V_16 ) ) ;
V_198 = 0 ;
F_239 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_77 * V_78 = V_203 -> V_78 ;
unsigned long V_112 = F_240 ( V_16 , V_78 ) ;
F_32 ( F_241 ( V_78 ) ) ;
V_198 += F_209 ( V_16 , V_78 , V_112 ) ;
}
if ( V_198 != F_164 ( V_16 ) )
F_12 ( V_12 L_17 ,
V_198 , F_164 ( V_16 ) ) ;
F_32 ( V_198 != F_164 ( V_16 ) ) ;
F_211 ( V_16 , V_180 ) ;
V_199 = 0 ;
F_239 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_77 * V_78 = V_203 -> V_78 ;
unsigned long V_112 = F_240 ( V_16 , V_78 ) ;
F_32 ( F_241 ( V_78 ) ) ;
V_199 += F_231 ( V_16 , V_78 , V_112 ) ;
}
if ( V_198 != V_199 )
F_12 ( V_12 L_18 ,
V_198 , V_199 , F_164 ( V_16 ) ) ;
F_32 ( V_198 != V_199 ) ;
}
int F_242 ( struct V_16 * V_16 , struct V_179 * V_180 )
{
struct V_119 * V_119 ;
int V_46 = 1 ;
F_32 ( F_17 ( V_16 ) ) ;
F_32 ( ! F_220 ( V_16 ) ) ;
V_119 = F_243 ( V_16 ) ;
if ( ! V_119 )
goto V_72;
F_244 ( V_119 ) ;
V_46 = 0 ;
if ( ! F_88 ( V_16 ) )
goto V_118;
F_32 ( ! F_223 ( V_16 ) ) ;
F_237 ( V_16 , V_119 , V_180 ) ;
F_25 ( V_204 ) ;
F_32 ( F_88 ( V_16 ) ) ;
V_118:
F_245 ( V_119 ) ;
F_246 ( V_119 ) ;
V_72:
return V_46 ;
}
int F_247 ( struct V_77 * V_78 ,
unsigned long * V_79 , int V_205 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
switch ( V_205 ) {
case V_206 :
if ( * V_79 & ( V_207 | V_208 ) )
return - V_43 ;
if ( V_84 -> V_209 & V_173 )
return - V_43 ;
* V_79 &= ~ V_173 ;
* V_79 |= V_207 ;
if ( F_10 ( F_248 ( V_78 ) ) )
return - V_67 ;
break;
case V_210 :
if ( * V_79 & ( V_173 | V_208 ) )
return - V_43 ;
* V_79 &= ~ V_207 ;
* V_79 |= V_173 ;
break;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
V_211 = F_249 ( L_19 ,
sizeof( struct V_212 ) ,
F_250 ( struct V_212 ) , 0 , NULL ) ;
if ( ! V_211 )
return - V_67 ;
return 0 ;
}
static inline struct V_212 * F_251 ( void )
{
if ( ! V_211 )
return NULL ;
return F_252 ( V_211 , V_106 ) ;
}
static inline void F_253 ( struct V_212 * V_212 )
{
F_254 ( V_211 , V_212 ) ;
}
static struct V_212 * F_255 ( struct V_83 * V_84 )
{
struct V_212 * V_212 ;
F_256 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_84 == V_212 -> V_84 )
return V_212 ;
return NULL ;
}
static void F_257 ( struct V_83 * V_84 ,
struct V_212 * V_212 )
{
V_212 -> V_84 = V_84 ;
F_258 ( V_213 , & V_212 -> V_214 , ( long ) V_84 ) ;
}
static inline int F_259 ( struct V_83 * V_84 )
{
return F_35 ( & V_84 -> V_215 ) == 0 ;
}
int F_260 ( struct V_83 * V_84 )
{
struct V_212 * V_212 ;
int V_216 ;
V_212 = F_251 () ;
if ( ! V_212 )
return - V_67 ;
F_41 ( F_259 ( V_84 ) ) ;
if ( F_10 ( F_261 ( V_217 , & V_84 -> V_97 ) ) ) {
F_253 ( V_212 ) ;
return 0 ;
}
F_163 ( & V_218 ) ;
F_257 ( V_84 , V_212 ) ;
V_216 = F_14 ( & V_13 . V_14 ) ;
F_262 ( & V_212 -> V_219 , & V_13 . V_14 ) ;
F_94 ( & V_218 ) ;
F_263 ( & V_84 -> V_220 ) ;
if ( V_216 )
F_15 ( & V_15 ) ;
return 0 ;
}
int F_248 ( struct V_77 * V_78 )
{
unsigned long V_221 , V_222 ;
if ( ! V_78 -> V_119 )
return 0 ;
if ( V_78 -> V_223 )
return 0 ;
F_41 ( V_78 -> V_79 & V_208 ) ;
V_221 = ( V_78 -> V_99 + ~ V_98 ) & V_98 ;
V_222 = V_78 -> V_101 & V_98 ;
if ( V_221 < V_222 )
return F_111 ( V_78 ) ;
return 0 ;
}
void F_264 ( struct V_83 * V_84 )
{
struct V_212 * V_212 ;
int free = 0 ;
F_163 ( & V_218 ) ;
V_212 = F_255 ( V_84 ) ;
if ( V_212 && V_13 . V_212 != V_212 ) {
F_265 ( & V_212 -> V_214 ) ;
F_266 ( & V_212 -> V_219 ) ;
free = 1 ;
}
F_94 ( & V_218 ) ;
if ( free ) {
F_44 ( V_217 , & V_84 -> V_97 ) ;
F_253 ( V_212 ) ;
F_267 ( V_84 ) ;
} else if ( V_212 ) {
F_268 ( & V_84 -> V_224 ) ;
F_269 ( & V_84 -> V_224 ) ;
}
}
static void F_270 ( struct V_16 * V_16 )
{
F_271 ( V_16 , V_225 + 0 ) ;
F_178 ( V_16 ) ;
F_272 ( V_16 ) ;
}
static void F_273 ( T_9 * V_130 , T_9 * V_226 )
{
while ( -- V_226 >= V_130 ) {
T_9 V_227 = * V_226 ;
if ( ! F_146 ( V_227 ) )
F_270 ( F_274 ( V_227 ) ) ;
}
}
static int F_275 ( struct V_77 * V_78 ,
unsigned long V_96 ,
T_9 * V_130 )
{
struct V_16 * V_16 ;
T_9 * V_226 ;
int V_228 = 0 , V_229 = 0 ;
for ( V_226 = V_130 ; V_226 < V_130 + V_32 ;
V_226 ++ , V_96 += V_129 ) {
T_9 V_227 = * V_226 ;
if ( F_146 ( V_227 ) ) {
if ( ++ V_229 <= V_63 )
continue;
else
goto V_72;
}
if ( ! F_276 ( V_227 ) || ! F_277 ( V_227 ) )
goto V_72;
V_16 = F_278 ( V_78 , V_96 , V_227 ) ;
if ( F_10 ( ! V_16 ) )
goto V_72;
F_87 ( F_88 ( V_16 ) , V_16 ) ;
F_87 ( ! F_220 ( V_16 ) , V_16 ) ;
F_87 ( ! F_223 ( V_16 ) , V_16 ) ;
if ( F_230 ( V_16 ) != 1 )
goto V_72;
if ( ! F_175 ( V_16 ) )
goto V_72;
if ( F_279 ( V_16 ) ) {
F_178 ( V_16 ) ;
goto V_72;
}
F_280 ( V_16 , V_225 + 0 ) ;
F_87 ( ! F_189 ( V_16 ) , V_16 ) ;
F_87 ( F_281 ( V_16 ) , V_16 ) ;
if ( F_282 ( V_227 ) || F_283 ( V_16 ) ||
F_284 ( V_78 -> V_138 , V_96 ) )
V_228 = 1 ;
}
if ( F_22 ( V_228 ) )
return 1 ;
V_72:
F_273 ( V_130 , V_226 ) ;
return 0 ;
}
static void F_285 ( T_9 * V_130 , struct V_16 * V_16 ,
struct V_77 * V_78 ,
unsigned long V_96 ,
T_7 * V_87 )
{
T_9 * V_226 ;
for ( V_226 = V_130 ; V_226 < V_130 + V_32 ; V_226 ++ ) {
T_9 V_227 = * V_226 ;
struct V_16 * V_115 ;
if ( F_146 ( V_227 ) ) {
F_134 ( V_16 , V_96 ) ;
F_102 ( V_78 -> V_138 , V_90 , 1 ) ;
} else {
V_115 = F_274 ( V_227 ) ;
F_159 ( V_16 , V_115 , V_96 , V_78 ) ;
F_87 ( F_164 ( V_115 ) != 1 , V_115 ) ;
F_270 ( V_115 ) ;
F_163 ( V_87 ) ;
F_286 ( V_78 -> V_138 , V_96 , V_226 ) ;
F_161 ( V_115 ) ;
F_94 ( V_87 ) ;
F_287 ( V_115 ) ;
}
V_96 += V_129 ;
V_16 ++ ;
}
}
static void F_288 ( void )
{
F_289 ( V_15 , false ,
F_290 ( V_57 ) ) ;
}
static int F_291 ( void )
{
static int V_230 = V_231 ;
int V_232 , V_233 = 0 , V_234 = 0 ;
for ( V_232 = 0 ; V_232 < V_235 ; V_232 ++ )
if ( V_236 [ V_232 ] > V_234 ) {
V_234 = V_236 [ V_232 ] ;
V_233 = V_232 ;
}
if ( V_233 <= V_230 )
for ( V_232 = V_230 + 1 ; V_232 < V_235 ;
V_232 ++ )
if ( V_234 == V_236 [ V_232 ] ) {
V_233 = V_232 ;
break;
}
V_230 = V_233 ;
return V_233 ;
}
static bool F_292 ( struct V_16 * * V_237 , bool * V_238 )
{
if ( F_11 ( * V_237 ) ) {
if ( ! * V_238 )
return false ;
* V_238 = false ;
* V_237 = NULL ;
F_288 () ;
} else if ( * V_237 ) {
F_96 ( * V_237 ) ;
* V_237 = NULL ;
}
return true ;
}
static struct V_16
* F_293 ( struct V_16 * * V_237 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_96 ,
int V_239 )
{
F_87 ( * V_237 , * V_237 ) ;
* V_237 = F_294 ( V_239 , F_104 (
F_295 () , V_133 ) , V_25 ) ;
F_296 ( & V_84 -> V_224 ) ;
if ( F_10 ( ! * V_237 ) ) {
F_25 ( V_240 ) ;
* V_237 = F_173 ( - V_67 ) ;
return NULL ;
}
F_25 ( V_241 ) ;
return * V_237 ;
}
static int F_291 ( void )
{
return 0 ;
}
static inline struct V_16 * F_297 ( int V_92 )
{
return F_24 ( F_104 ( V_92 , 0 ) ,
V_25 ) ;
}
static struct V_16 * F_298 ( bool * V_238 )
{
struct V_16 * V_237 ;
do {
V_237 = F_297 ( F_295 () ) ;
if ( ! V_237 ) {
F_25 ( V_240 ) ;
if ( ! * V_238 )
return NULL ;
* V_238 = false ;
F_288 () ;
} else
F_25 ( V_241 ) ;
} while ( F_10 ( ! V_237 ) && F_22 ( F_2 () ) );
return V_237 ;
}
static bool F_292 ( struct V_16 * * V_237 , bool * V_238 )
{
if ( ! * V_237 )
* V_237 = F_298 ( V_238 ) ;
if ( F_10 ( ! * V_237 ) )
return false ;
return true ;
}
static struct V_16
* F_293 ( struct V_16 * * V_237 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_96 ,
int V_239 )
{
F_296 ( & V_84 -> V_224 ) ;
F_41 ( ! * V_237 ) ;
return * V_237 ;
}
static bool F_299 ( struct V_77 * V_78 )
{
if ( ( ! ( V_78 -> V_79 & V_207 ) && ! F_300 () ) ||
( V_78 -> V_79 & V_173 ) )
return false ;
if ( ! V_78 -> V_119 || V_78 -> V_223 )
return false ;
if ( F_241 ( V_78 ) )
return false ;
F_41 ( V_78 -> V_79 & V_208 ) ;
return true ;
}
static void F_301 ( struct V_83 * V_84 ,
unsigned long V_96 ,
struct V_16 * * V_237 ,
struct V_77 * V_78 ,
int V_239 )
{
T_1 * V_18 , V_123 ;
T_9 * V_130 ;
T_6 V_86 ;
struct V_16 * V_135 ;
T_7 * V_242 , * V_243 ;
int V_244 ;
unsigned long V_221 , V_222 ;
unsigned long V_125 ;
unsigned long V_126 ;
F_41 ( V_96 & ~ V_98 ) ;
V_135 = F_293 ( V_237 , V_84 , V_78 , V_96 , V_239 ) ;
if ( ! V_135 )
return;
if ( F_10 ( F_115 ( V_135 , V_84 , V_106 ) ) )
return;
F_268 ( & V_84 -> V_224 ) ;
if ( F_10 ( F_259 ( V_84 ) ) )
goto V_72;
V_78 = F_302 ( V_84 , V_96 ) ;
if ( ! V_78 )
goto V_72;
V_221 = ( V_78 -> V_99 + ~ V_98 ) & V_98 ;
V_222 = V_78 -> V_101 & V_98 ;
if ( V_96 < V_221 || V_96 + V_100 > V_222 )
goto V_72;
if ( ! F_299 ( V_78 ) )
goto V_72;
V_18 = F_208 ( V_84 , V_96 ) ;
if ( ! V_18 )
goto V_72;
if ( F_119 ( * V_18 ) )
goto V_72;
F_244 ( V_78 -> V_119 ) ;
V_130 = F_145 ( V_18 , V_96 ) ;
V_243 = F_303 ( V_84 , V_18 ) ;
V_125 = V_96 ;
V_126 = V_96 + V_100 ;
F_135 ( V_84 , V_125 , V_126 ) ;
V_242 = F_92 ( V_84 , V_18 ) ;
V_123 = F_136 ( V_78 , V_96 , V_18 ) ;
F_94 ( V_242 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
F_163 ( V_243 ) ;
V_244 = F_275 ( V_78 , V_96 , V_130 ) ;
F_94 ( V_243 ) ;
if ( F_10 ( ! V_244 ) ) {
F_148 ( V_130 ) ;
F_163 ( V_242 ) ;
F_32 ( ! F_93 ( * V_18 ) ) ;
F_138 ( V_84 , V_18 , F_304 ( V_123 ) ) ;
F_94 ( V_242 ) ;
F_245 ( V_78 -> V_119 ) ;
goto V_72;
}
F_245 ( V_78 -> V_119 ) ;
F_285 ( V_130 , V_135 , V_78 , V_96 , V_243 ) ;
F_148 ( V_130 ) ;
F_91 ( V_135 ) ;
V_86 = F_304 ( V_123 ) ;
V_123 = F_83 ( V_135 , V_78 -> V_89 ) ;
V_123 = F_81 ( F_98 ( V_123 ) , V_78 ) ;
F_149 () ;
F_163 ( V_242 ) ;
F_32 ( ! F_93 ( * V_18 ) ) ;
F_99 ( V_135 , V_78 , V_96 ) ;
F_100 ( V_84 , V_18 , V_86 ) ;
F_101 ( V_84 , V_96 , V_18 , V_123 ) ;
F_131 ( V_78 , V_96 , V_18 ) ;
F_94 ( V_242 ) ;
* V_237 = NULL ;
V_60 ++ ;
V_245:
F_269 ( & V_84 -> V_224 ) ;
return;
V_72:
F_95 ( V_135 ) ;
goto V_245;
}
static int F_305 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_96 ,
struct V_16 * * V_237 )
{
T_1 * V_18 ;
T_9 * V_130 , * V_226 ;
int V_46 = 0 , V_228 = 0 , V_229 = 0 ;
struct V_16 * V_16 ;
unsigned long V_246 ;
T_7 * V_87 ;
int V_239 = V_231 ;
F_41 ( V_96 & ~ V_98 ) ;
V_18 = F_208 ( V_84 , V_96 ) ;
if ( ! V_18 )
goto V_72;
if ( F_119 ( * V_18 ) )
goto V_72;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
V_130 = F_306 ( V_84 , V_18 , V_96 , & V_87 ) ;
for ( V_246 = V_96 , V_226 = V_130 ; V_226 < V_130 + V_32 ;
V_226 ++ , V_246 += V_129 ) {
T_9 V_227 = * V_226 ;
if ( F_146 ( V_227 ) ) {
if ( ++ V_229 <= V_63 )
continue;
else
goto V_247;
}
if ( ! F_276 ( V_227 ) || ! F_277 ( V_227 ) )
goto V_247;
V_16 = F_278 ( V_78 , V_246 , V_227 ) ;
if ( F_10 ( ! V_16 ) )
goto V_247;
V_239 = F_155 ( V_16 ) ;
V_236 [ V_239 ] ++ ;
F_87 ( F_88 ( V_16 ) , V_16 ) ;
if ( ! F_281 ( V_16 ) || F_189 ( V_16 ) || ! F_220 ( V_16 ) )
goto V_247;
if ( F_230 ( V_16 ) != 1 )
goto V_247;
if ( F_282 ( V_227 ) || F_283 ( V_16 ) ||
F_284 ( V_78 -> V_138 , V_96 ) )
V_228 = 1 ;
}
if ( V_228 )
V_46 = 1 ;
V_247:
F_307 ( V_130 , V_87 ) ;
if ( V_46 ) {
V_239 = F_291 () ;
F_301 ( V_84 , V_96 , V_237 , V_78 , V_239 ) ;
}
V_72:
return V_46 ;
}
static void F_308 ( struct V_212 * V_212 )
{
struct V_83 * V_84 = V_212 -> V_84 ;
F_41 ( V_248 != 1 && ! F_309 ( & V_218 ) ) ;
if ( F_259 ( V_84 ) ) {
F_265 ( & V_212 -> V_214 ) ;
F_266 ( & V_212 -> V_219 ) ;
F_253 ( V_212 ) ;
F_267 ( V_84 ) ;
}
}
static unsigned int F_310 ( unsigned int V_59 ,
struct V_16 * * V_237 )
__releases( &khugepaged_mm_lock
static int F_311 ( void )
{
return ! F_14 ( & V_13 . V_14 ) &&
F_2 () ;
}
static int F_312 ( void )
{
return ! F_14 ( & V_13 . V_14 ) ||
F_313 () ;
}
static void F_314 ( void )
{
struct V_16 * V_237 = NULL ;
unsigned int V_249 = 0 , V_250 = 0 ;
unsigned int V_59 = V_58 ;
bool V_238 = true ;
F_315 () ;
while ( V_249 < V_59 ) {
if ( ! F_292 ( & V_237 , & V_238 ) )
break;
F_160 () ;
if ( F_10 ( F_313 () || F_316 ( V_251 ) ) )
break;
F_163 ( & V_218 ) ;
if ( ! V_13 . V_212 )
V_250 ++ ;
if ( F_311 () &&
V_250 < 2 )
V_249 += F_310 ( V_59 - V_249 ,
& V_237 ) ;
else
V_249 = V_59 ;
F_94 ( & V_218 ) ;
}
if ( ! F_317 ( V_237 ) )
F_96 ( V_237 ) ;
}
static void F_318 ( void )
{
F_319 () ;
if ( F_311 () ) {
if ( ! V_54 )
return;
F_289 ( V_15 ,
F_313 () ,
F_290 ( V_54 ) ) ;
return;
}
if ( F_2 () )
F_320 ( V_15 , F_312 () ) ;
}
static int V_11 ( void * V_229 )
{
struct V_212 * V_212 ;
F_321 () ;
F_322 ( V_251 , 19 ) ;
while ( ! F_313 () ) {
F_314 () ;
F_318 () ;
}
F_163 ( & V_218 ) ;
V_212 = V_13 . V_212 ;
V_13 . V_212 = NULL ;
if ( V_212 )
F_308 ( V_212 ) ;
F_94 ( & V_218 ) ;
return 0 ;
}
static void F_323 ( struct V_77 * V_78 ,
unsigned long V_85 , T_1 * V_18 )
{
struct V_83 * V_84 = V_78 -> V_138 ;
T_6 V_86 ;
T_1 V_123 ;
int V_124 ;
F_136 ( V_78 , V_85 , V_18 ) ;
V_86 = F_137 ( V_84 , V_18 ) ;
F_138 ( V_84 , & V_123 , V_86 ) ;
for ( V_124 = 0 ; V_124 < V_32 ; V_124 ++ , V_85 += V_129 ) {
T_9 * V_130 , V_82 ;
V_82 = F_142 ( F_143 ( V_85 ) , V_78 -> V_89 ) ;
V_82 = F_144 ( V_82 ) ;
V_130 = F_145 ( & V_123 , V_85 ) ;
F_41 ( ! F_146 ( * V_130 ) ) ;
F_147 ( V_84 , V_85 , V_130 , V_82 ) ;
F_148 ( V_130 ) ;
}
F_149 () ;
F_138 ( V_84 , V_18 , V_86 ) ;
F_31 () ;
}
void F_324 ( struct V_77 * V_78 , unsigned long V_96 ,
T_1 * V_18 )
{
T_7 * V_87 ;
struct V_16 * V_16 ;
struct V_83 * V_84 = V_78 -> V_138 ;
unsigned long V_85 = V_96 & V_98 ;
unsigned long V_125 ;
unsigned long V_126 ;
F_32 ( V_78 -> V_99 > V_85 || V_78 -> V_101 < V_85 + V_100 ) ;
V_125 = V_85 ;
V_126 = V_85 + V_100 ;
V_252:
F_135 ( V_84 , V_125 , V_126 ) ;
V_87 = F_92 ( V_84 , V_18 ) ;
if ( F_10 ( ! F_119 ( * V_18 ) ) ) {
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
return;
}
if ( F_19 ( * V_18 ) ) {
F_323 ( V_78 , V_85 , V_18 ) ;
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
return;
}
V_16 = F_20 ( * V_18 ) ;
F_87 ( ! F_230 ( V_16 ) , V_16 ) ;
F_123 ( V_16 ) ;
F_94 ( V_87 ) ;
F_151 ( V_84 , V_125 , V_126 ) ;
F_167 ( V_16 ) ;
F_96 ( V_16 ) ;
if ( F_10 ( F_119 ( * V_18 ) ) )
goto V_252;
}
void F_325 ( struct V_83 * V_84 , unsigned long V_96 ,
T_1 * V_18 )
{
struct V_77 * V_78 ;
V_78 = F_302 ( V_84 , V_96 ) ;
F_32 ( V_78 == NULL ) ;
F_168 ( V_78 , V_96 , V_18 ) ;
}
static void F_326 ( struct V_83 * V_84 ,
unsigned long V_96 )
{
T_1 * V_18 ;
F_41 ( ! ( V_96 & ~ V_98 ) ) ;
V_18 = F_208 ( V_84 , V_96 ) ;
if ( ! V_18 )
return;
F_325 ( V_84 , V_96 , V_18 ) ;
}
void F_327 ( struct V_77 * V_78 ,
unsigned long V_253 ,
unsigned long V_163 ,
long V_254 )
{
if ( V_253 & ~ V_98 &&
( V_253 & V_98 ) >= V_78 -> V_99 &&
( V_253 & V_98 ) + V_100 <= V_78 -> V_101 )
F_326 ( V_78 -> V_138 , V_253 ) ;
if ( V_163 & ~ V_98 &&
( V_163 & V_98 ) >= V_78 -> V_99 &&
( V_163 & V_98 ) + V_100 <= V_78 -> V_101 )
F_326 ( V_78 -> V_138 , V_163 ) ;
if ( V_254 > 0 ) {
struct V_77 * V_255 = V_78 -> V_256 ;
unsigned long V_257 = V_255 -> V_99 ;
V_257 += V_254 << V_6 ;
if ( V_257 & ~ V_98 &&
( V_257 & V_98 ) >= V_255 -> V_99 &&
( V_257 & V_98 ) + V_100 <= V_255 -> V_101 )
F_326 ( V_255 -> V_138 , V_257 ) ;
}
}
