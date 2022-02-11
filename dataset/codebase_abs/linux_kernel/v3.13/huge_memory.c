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
static inline bool F_16 ( struct V_15 * V_15 )
{
return F_17 ( V_16 ) == V_15 ;
}
static inline bool F_18 ( T_1 V_17 )
{
return F_16 ( F_19 ( V_17 ) ) ;
}
static struct V_15 * F_20 ( void )
{
struct V_15 * V_18 ;
V_19:
if ( F_21 ( F_22 ( & V_20 ) ) )
return F_17 ( V_16 ) ;
V_18 = F_23 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_18 ) {
F_24 ( V_25 ) ;
return NULL ;
}
F_24 ( V_26 ) ;
F_25 () ;
if ( F_26 ( & V_16 , NULL , V_18 ) ) {
F_27 () ;
F_28 ( V_18 ) ;
goto V_19;
}
F_29 ( & V_20 , 2 ) ;
F_27 () ;
return F_17 ( V_16 ) ;
}
static void F_30 ( void )
{
F_31 ( F_32 ( & V_20 ) ) ;
}
static unsigned long F_33 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_34 ( & V_20 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_35 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_36 ( & V_20 , 1 , 0 ) == 1 ) {
struct V_15 * V_18 = F_37 ( & V_16 , NULL ) ;
F_31 ( V_18 == NULL ) ;
F_28 ( V_18 ) ;
return V_31 ;
}
return 0 ;
}
static T_2 F_38 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( F_39 ( V_38 , & V_40 ) ) {
F_40 ( F_39 ( V_39 , & V_40 ) ) ;
return sprintf ( V_36 , L_3 ) ;
} else if ( F_39 ( V_39 , & V_40 ) )
return sprintf ( V_36 , L_4 ) ;
else
return sprintf ( V_36 , L_5 ) ;
}
static T_2 F_41 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( ! memcmp ( L_6 , V_36 ,
F_4 ( sizeof( L_6 ) - 1 , V_41 ) ) ) {
F_42 ( V_38 , & V_40 ) ;
F_43 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_7 , V_36 ,
F_4 ( sizeof( L_7 ) - 1 , V_41 ) ) ) {
F_43 ( V_38 , & V_40 ) ;
F_42 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_8 , V_36 ,
F_4 ( sizeof( L_8 ) - 1 , V_41 ) ) ) {
F_43 ( V_38 , & V_40 ) ;
F_43 ( V_39 , & V_40 ) ;
} else
return - V_42 ;
return V_41 ;
}
static T_2 F_44 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_38 ( V_33 , V_35 , V_36 ,
V_43 ,
V_44 ) ;
}
static T_2 F_45 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
T_2 V_45 ;
V_45 = F_41 ( V_33 , V_35 , V_36 , V_41 ,
V_43 ,
V_44 ) ;
if ( V_45 > 0 ) {
int V_8 ;
F_46 ( & V_46 ) ;
V_8 = F_7 () ;
F_47 ( & V_46 ) ;
if ( V_8 )
V_45 = V_8 ;
}
return V_45 ;
}
static T_2 F_48 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_47 )
{
return sprintf ( V_36 , L_9 ,
! ! F_39 ( V_47 , & V_40 ) ) ;
}
static T_2 F_49 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_47 )
{
unsigned long V_48 ;
int V_45 ;
V_45 = F_50 ( V_36 , 10 , & V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_48 > 1 )
return - V_42 ;
if ( V_48 )
F_42 ( V_47 , & V_40 ) ;
else
F_43 ( V_47 , & V_40 ) ;
return V_41 ;
}
static T_2 F_51 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_38 ( V_33 , V_35 , V_36 ,
V_49 ,
V_50 ) ;
}
static T_2 F_52 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_41 ( V_33 , V_35 , V_36 , V_41 ,
V_49 ,
V_50 ) ;
}
static T_2 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_48 ( V_33 , V_35 , V_36 ,
V_51 ) ;
}
static T_2 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_41 )
{
return F_49 ( V_33 , V_35 , V_36 , V_41 ,
V_51 ) ;
}
static T_2 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_48 ( V_33 , V_35 , V_36 ,
V_52 ) ;
}
static T_2 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_49 ( V_33 , V_35 , V_36 , V_41 ,
V_52 ) ;
}
static T_2 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_53 ) ;
}
static T_2 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_8 ;
V_8 = F_50 ( V_36 , 10 , & V_54 ) ;
if ( V_8 || V_54 > V_55 )
return - V_42 ;
V_53 = V_54 ;
F_14 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_56 ) ;
}
static T_2 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_8 ;
V_8 = F_50 ( V_36 , 10 , & V_54 ) ;
if ( V_8 || V_54 > V_55 )
return - V_42 ;
V_56 = V_54 ;
F_14 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_57 ) ;
}
static T_2 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_8 ;
unsigned long V_58 ;
V_8 = F_50 ( V_36 , 10 , & V_58 ) ;
if ( V_8 || ! V_58 || V_58 > V_55 )
return - V_42 ;
V_57 = V_58 ;
return V_41 ;
}
static T_2 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_59 ) ;
}
static T_2 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_60 ) ;
}
static T_2 F_65 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_48 ( V_33 , V_35 , V_36 ,
V_61 ) ;
}
static T_2 F_66 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_49 ( V_33 , V_35 , V_36 , V_41 ,
V_61 ) ;
}
static T_2 F_67 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_10 , V_62 ) ;
}
static T_2 F_68 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_8 ;
unsigned long V_63 ;
V_8 = F_50 ( V_36 , 10 , & V_63 ) ;
if ( V_8 || V_63 > V_31 - 1 )
return - V_42 ;
V_62 = V_63 ;
return V_41 ;
}
static int T_4 F_69 ( struct V_32 * * V_64 )
{
int V_8 ;
* V_64 = F_70 ( L_11 , V_65 ) ;
if ( F_9 ( ! * V_64 ) ) {
F_11 ( V_11 L_12 ) ;
return - V_66 ;
}
V_8 = F_71 ( * V_64 , & V_67 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_68;
}
V_8 = F_71 ( * V_64 , & V_69 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_70;
}
return 0 ;
V_70:
F_72 ( * V_64 , & V_67 ) ;
V_68:
F_73 ( * V_64 ) ;
return V_8 ;
}
static void T_4 F_74 ( struct V_32 * V_64 )
{
F_72 ( V_64 , & V_69 ) ;
F_72 ( V_64 , & V_67 ) ;
F_73 ( V_64 ) ;
}
static inline int F_69 ( struct V_32 * * V_64 )
{
return 0 ;
}
static inline void F_74 ( struct V_32 * V_64 )
{
}
static int T_4 F_75 ( void )
{
int V_8 ;
struct V_32 * V_64 ;
if ( ! F_76 () ) {
V_40 = 0 ;
return - V_42 ;
}
V_8 = F_69 ( & V_64 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 () ;
if ( V_8 )
goto V_71;
F_78 ( & V_72 ) ;
if ( V_73 < ( 512 << ( 20 - V_6 ) ) )
V_40 = 0 ;
F_7 () ;
return 0 ;
V_71:
F_74 ( V_64 ) ;
return V_8 ;
}
static int T_4 F_79 ( char * V_74 )
{
int V_45 = 0 ;
if ( ! V_74 )
goto V_71;
if ( ! strcmp ( V_74 , L_6 ) ) {
F_42 ( V_43 ,
& V_40 ) ;
F_43 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_7 ) ) {
F_43 ( V_43 ,
& V_40 ) ;
F_42 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_8 ) ) {
F_43 ( V_43 ,
& V_40 ) ;
F_43 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
}
V_71:
if ( ! V_45 )
F_11 ( V_75
L_14 ) ;
return V_45 ;
}
T_1 F_80 ( T_1 V_17 , struct V_76 * V_77 )
{
if ( F_21 ( V_77 -> V_78 & V_79 ) )
V_17 = F_81 ( V_17 ) ;
return V_17 ;
}
static inline T_1 F_82 ( struct V_15 * V_15 , T_5 V_80 )
{
T_1 V_81 ;
V_81 = F_83 ( V_15 , V_80 ) ;
V_81 = F_84 ( V_81 ) ;
return V_81 ;
}
static int F_85 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_84 , T_1 * V_17 ,
struct V_15 * V_15 )
{
T_6 V_85 ;
T_7 * V_86 ;
F_40 ( ! F_86 ( V_15 ) ) ;
V_85 = F_87 ( V_83 , V_84 ) ;
if ( F_9 ( ! V_85 ) )
return V_87 ;
F_88 ( V_15 , V_84 , V_31 ) ;
F_89 ( V_15 ) ;
V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_9 ( ! F_91 ( * V_17 ) ) ) {
F_92 ( V_86 ) ;
F_93 ( V_15 ) ;
F_94 ( V_15 ) ;
F_95 ( V_83 , V_85 ) ;
} else {
T_1 V_81 ;
V_81 = F_82 ( V_15 , V_77 -> V_88 ) ;
V_81 = F_80 ( F_96 ( V_81 ) , V_77 ) ;
F_97 ( V_15 , V_77 , V_84 ) ;
F_98 ( V_83 , V_17 , V_85 ) ;
F_99 ( V_83 , V_84 , V_17 , V_81 ) ;
F_100 ( V_83 , V_89 , V_31 ) ;
F_101 ( & V_83 -> V_90 ) ;
F_92 ( V_86 ) ;
}
return 0 ;
}
static inline T_8 F_102 ( int V_91 , T_8 V_92 )
{
return ( V_21 & ~ ( V_91 ? 0 : V_93 ) ) | V_92 ;
}
static inline struct V_15 * F_103 ( int V_91 ,
struct V_76 * V_77 ,
unsigned long V_84 , int V_94 ,
T_8 V_92 )
{
return F_104 ( F_102 ( V_91 , V_92 ) ,
V_24 , V_77 , V_84 , V_94 ) ;
}
static bool F_105 ( T_6 V_85 , struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_84 , T_1 * V_17 ,
struct V_15 * V_18 )
{
T_1 V_81 ;
if ( ! F_91 ( * V_17 ) )
return false ;
V_81 = F_83 ( V_18 , V_77 -> V_88 ) ;
V_81 = F_106 ( V_81 ) ;
V_81 = F_84 ( V_81 ) ;
F_98 ( V_83 , V_17 , V_85 ) ;
F_99 ( V_83 , V_84 , V_17 , V_81 ) ;
F_101 ( & V_83 -> V_90 ) ;
return true ;
}
int F_107 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_95 , T_1 * V_17 ,
unsigned int V_96 )
{
struct V_15 * V_15 ;
unsigned long V_84 = V_95 & V_97 ;
if ( V_84 < V_77 -> V_98 || V_84 + V_99 > V_77 -> V_100 )
return V_101 ;
if ( F_9 ( F_108 ( V_77 ) ) )
return V_87 ;
if ( F_9 ( F_109 ( V_77 ) ) )
return V_87 ;
if ( ! ( V_96 & V_102 ) &&
F_110 () ) {
T_7 * V_86 ;
T_6 V_85 ;
struct V_15 * V_18 ;
bool V_103 ;
V_85 = F_87 ( V_83 , V_84 ) ;
if ( F_9 ( ! V_85 ) )
return V_87 ;
V_18 = F_20 () ;
if ( F_9 ( ! V_18 ) ) {
F_95 ( V_83 , V_85 ) ;
F_24 ( V_104 ) ;
return V_101 ;
}
V_86 = F_90 ( V_83 , V_17 ) ;
V_103 = F_105 ( V_85 , V_83 , V_77 , V_84 , V_17 ,
V_18 ) ;
F_92 ( V_86 ) ;
if ( ! V_103 ) {
F_95 ( V_83 , V_85 ) ;
F_30 () ;
}
return 0 ;
}
V_15 = F_103 ( F_111 ( V_77 ) ,
V_77 , V_84 , F_112 () , 0 ) ;
if ( F_9 ( ! V_15 ) ) {
F_24 ( V_104 ) ;
return V_101 ;
}
if ( F_9 ( F_113 ( V_15 , V_83 , V_105 ) ) ) {
F_94 ( V_15 ) ;
F_24 ( V_104 ) ;
return V_101 ;
}
if ( F_9 ( F_85 ( V_83 , V_77 , V_84 , V_17 , V_15 ) ) ) {
F_93 ( V_15 ) ;
F_94 ( V_15 ) ;
F_24 ( V_104 ) ;
return V_101 ;
}
F_24 ( V_106 ) ;
return 0 ;
}
int F_114 ( struct V_82 * V_107 , struct V_82 * V_108 ,
T_1 * V_109 , T_1 * V_110 , unsigned long V_111 ,
struct V_76 * V_77 )
{
T_7 * V_112 , * V_113 ;
struct V_15 * V_114 ;
T_1 V_17 ;
T_6 V_85 ;
int V_45 ;
V_45 = - V_66 ;
V_85 = F_87 ( V_107 , V_111 ) ;
if ( F_9 ( ! V_85 ) )
goto V_71;
V_112 = F_90 ( V_107 , V_109 ) ;
V_113 = F_115 ( V_108 , V_110 ) ;
F_116 ( V_113 , V_115 ) ;
V_45 = - V_116 ;
V_17 = * V_110 ;
if ( F_9 ( ! F_117 ( V_17 ) ) ) {
F_95 ( V_107 , V_85 ) ;
goto V_117;
}
if ( F_18 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_103 ;
V_18 = F_20 () ;
V_103 = F_105 ( V_85 , V_107 , V_77 , V_111 , V_109 ,
V_18 ) ;
F_31 ( ! V_103 ) ;
V_45 = 0 ;
goto V_117;
}
if ( F_9 ( F_118 ( V_17 ) ) ) {
F_92 ( V_113 ) ;
F_92 ( V_112 ) ;
F_95 ( V_107 , V_85 ) ;
F_119 ( V_77 -> V_118 , V_110 ) ;
goto V_71;
}
V_114 = F_19 ( V_17 ) ;
F_40 ( ! F_120 ( V_114 ) ) ;
F_121 ( V_114 ) ;
F_122 ( V_114 ) ;
F_100 ( V_107 , V_89 , V_31 ) ;
F_123 ( V_108 , V_111 , V_110 ) ;
V_17 = F_124 ( F_106 ( V_17 ) ) ;
F_98 ( V_107 , V_109 , V_85 ) ;
F_99 ( V_107 , V_111 , V_109 , V_17 ) ;
F_101 ( & V_107 -> V_90 ) ;
V_45 = 0 ;
V_117:
F_92 ( V_113 ) ;
F_92 ( V_112 ) ;
V_71:
return V_45 ;
}
void F_125 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_119 ,
int V_120 )
{
T_7 * V_86 ;
T_1 V_81 ;
unsigned long V_84 ;
V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_9 ( ! F_126 ( * V_17 , V_119 ) ) )
goto V_121;
V_81 = F_127 ( V_119 ) ;
V_84 = V_95 & V_97 ;
if ( F_128 ( V_77 , V_84 , V_17 , V_81 , V_120 ) )
F_129 ( V_77 , V_95 , V_17 ) ;
V_121:
F_92 ( V_86 ) ;
}
static int F_130 ( struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
T_1 * V_17 , T_1 V_119 , unsigned long V_84 )
{
T_7 * V_86 ;
T_6 V_85 ;
T_1 V_122 ;
struct V_15 * V_15 ;
int V_123 , V_45 = 0 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_15 = F_131 ( V_126 , V_77 , V_95 ) ;
if ( ! V_15 ) {
V_45 |= V_87 ;
goto V_71;
}
if ( F_113 ( V_15 , V_83 , V_105 ) ) {
F_94 ( V_15 ) ;
V_45 |= V_87 ;
goto V_71;
}
F_132 ( V_15 , V_95 ) ;
F_89 ( V_15 ) ;
V_124 = V_84 ;
V_125 = V_84 + V_99 ;
F_133 ( V_83 , V_124 , V_125 ) ;
V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_9 ( ! F_126 ( * V_17 , V_119 ) ) )
goto V_127;
F_134 ( V_77 , V_84 , V_17 ) ;
V_85 = F_135 ( V_83 , V_17 ) ;
F_136 ( V_83 , & V_122 , V_85 ) ;
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ , V_84 += V_128 ) {
T_9 * V_129 , V_81 ;
if ( V_84 == ( V_95 & V_130 ) ) {
V_81 = F_137 ( V_15 , V_77 -> V_88 ) ;
V_81 = F_138 ( F_139 ( V_81 ) , V_77 ) ;
F_97 ( V_15 , V_77 , V_84 ) ;
} else {
V_81 = F_140 ( F_141 ( V_84 ) , V_77 -> V_88 ) ;
V_81 = F_142 ( V_81 ) ;
}
V_129 = F_143 ( & V_122 , V_84 ) ;
F_40 ( ! F_144 ( * V_129 ) ) ;
F_145 ( V_83 , V_84 , V_129 , V_81 ) ;
F_146 ( V_129 ) ;
}
F_147 () ;
F_136 ( V_83 , V_17 , V_85 ) ;
F_92 ( V_86 ) ;
F_30 () ;
F_148 ( V_83 , V_89 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
V_45 |= V_131 ;
V_71:
return V_45 ;
V_127:
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
F_93 ( V_15 ) ;
F_94 ( V_15 ) ;
goto V_71;
}
static int F_150 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_119 ,
struct V_15 * V_15 ,
unsigned long V_84 )
{
T_7 * V_86 ;
T_6 V_85 ;
T_1 V_122 ;
int V_45 = 0 , V_123 ;
struct V_15 * * V_58 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_58 = F_151 ( sizeof( struct V_15 * ) * V_31 ,
V_105 ) ;
if ( F_9 ( ! V_58 ) ) {
V_45 |= V_87 ;
goto V_71;
}
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ ) {
V_58 [ V_123 ] = F_152 ( V_126 |
V_132 ,
V_77 , V_95 , F_153 ( V_15 ) ) ;
if ( F_9 ( ! V_58 [ V_123 ] ||
F_113 ( V_58 [ V_123 ] , V_83 ,
V_105 ) ) ) {
if ( V_58 [ V_123 ] )
F_94 ( V_58 [ V_123 ] ) ;
F_154 () ;
while ( -- V_123 >= 0 ) {
F_93 ( V_58 [ V_123 ] ) ;
F_94 ( V_58 [ V_123 ] ) ;
}
F_155 () ;
F_156 ( V_58 ) ;
V_45 |= V_87 ;
goto V_71;
}
}
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ ) {
F_157 ( V_58 [ V_123 ] , V_15 + V_123 ,
V_84 + V_128 * V_123 , V_77 ) ;
F_89 ( V_58 [ V_123 ] ) ;
F_158 () ;
}
V_124 = V_84 ;
V_125 = V_84 + V_99 ;
F_133 ( V_83 , V_124 , V_125 ) ;
V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_9 ( ! F_126 ( * V_17 , V_119 ) ) )
goto V_133;
F_40 ( ! F_120 ( V_15 ) ) ;
F_134 ( V_77 , V_84 , V_17 ) ;
V_85 = F_135 ( V_83 , V_17 ) ;
F_136 ( V_83 , & V_122 , V_85 ) ;
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ , V_84 += V_128 ) {
T_9 * V_129 , V_81 ;
V_81 = F_137 ( V_58 [ V_123 ] , V_77 -> V_88 ) ;
V_81 = F_138 ( F_139 ( V_81 ) , V_77 ) ;
F_97 ( V_58 [ V_123 ] , V_77 , V_84 ) ;
V_129 = F_143 ( & V_122 , V_84 ) ;
F_40 ( ! F_144 ( * V_129 ) ) ;
F_145 ( V_83 , V_84 , V_129 , V_81 ) ;
F_146 ( V_129 ) ;
}
F_156 ( V_58 ) ;
F_147 () ;
F_136 ( V_83 , V_17 , V_85 ) ;
F_159 ( V_15 ) ;
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
V_45 |= V_131 ;
F_94 ( V_15 ) ;
V_71:
return V_45 ;
V_133:
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
F_154 () ;
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ ) {
F_93 ( V_58 [ V_123 ] ) ;
F_94 ( V_58 [ V_123 ] ) ;
}
F_155 () ;
F_156 ( V_58 ) ;
goto V_71;
}
int F_160 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_95 , T_1 * V_17 , T_1 V_119 )
{
T_7 * V_86 ;
int V_45 = 0 ;
struct V_15 * V_15 = NULL , * V_134 ;
unsigned long V_84 ;
unsigned long V_124 ;
unsigned long V_125 ;
V_86 = F_115 ( V_83 , V_17 ) ;
F_40 ( ! V_77 -> V_118 ) ;
V_84 = V_95 & V_97 ;
if ( F_18 ( V_119 ) )
goto V_135;
F_161 ( V_86 ) ;
if ( F_9 ( ! F_126 ( * V_17 , V_119 ) ) )
goto V_117;
V_15 = F_19 ( V_119 ) ;
F_40 ( ! F_86 ( V_15 ) || ! F_120 ( V_15 ) ) ;
if ( F_162 ( V_15 ) == 1 ) {
T_1 V_81 ;
V_81 = F_127 ( V_119 ) ;
V_81 = F_80 ( F_96 ( V_81 ) , V_77 ) ;
if ( F_128 ( V_77 , V_84 , V_17 , V_81 , 1 ) )
F_129 ( V_77 , V_95 , V_17 ) ;
V_45 |= V_131 ;
goto V_117;
}
F_121 ( V_15 ) ;
F_92 ( V_86 ) ;
V_135:
if ( F_163 ( V_77 ) &&
! F_164 () )
V_134 = F_103 ( F_111 ( V_77 ) ,
V_77 , V_84 , F_112 () , 0 ) ;
else
V_134 = NULL ;
if ( F_9 ( ! V_134 ) ) {
if ( ! V_15 ) {
V_45 = F_130 ( V_83 , V_77 ,
V_95 , V_17 , V_119 , V_84 ) ;
} else {
V_45 = F_150 ( V_83 , V_77 , V_95 ,
V_17 , V_119 , V_15 , V_84 ) ;
if ( V_45 & V_87 )
F_165 ( V_15 ) ;
F_94 ( V_15 ) ;
}
F_24 ( V_104 ) ;
goto V_71;
}
if ( F_9 ( F_113 ( V_134 , V_83 , V_105 ) ) ) {
F_94 ( V_134 ) ;
if ( V_15 ) {
F_165 ( V_15 ) ;
F_94 ( V_15 ) ;
}
F_24 ( V_104 ) ;
V_45 |= V_87 ;
goto V_71;
}
F_24 ( V_106 ) ;
if ( ! V_15 )
F_88 ( V_134 , V_84 , V_31 ) ;
else
F_166 ( V_134 , V_15 , V_84 , V_77 , V_31 ) ;
F_89 ( V_134 ) ;
V_124 = V_84 ;
V_125 = V_84 + V_99 ;
F_133 ( V_83 , V_124 , V_125 ) ;
F_161 ( V_86 ) ;
if ( V_15 )
F_94 ( V_15 ) ;
if ( F_9 ( ! F_126 ( * V_17 , V_119 ) ) ) {
F_92 ( V_86 ) ;
F_93 ( V_134 ) ;
F_94 ( V_134 ) ;
goto V_136;
} else {
T_1 V_81 ;
V_81 = F_82 ( V_134 , V_77 -> V_88 ) ;
V_81 = F_80 ( F_96 ( V_81 ) , V_77 ) ;
F_134 ( V_77 , V_84 , V_17 ) ;
F_97 ( V_134 , V_77 , V_84 ) ;
F_99 ( V_83 , V_84 , V_17 , V_81 ) ;
F_129 ( V_77 , V_95 , V_17 ) ;
if ( ! V_15 ) {
F_100 ( V_83 , V_89 , V_31 ) ;
F_30 () ;
} else {
F_40 ( ! F_120 ( V_15 ) ) ;
F_159 ( V_15 ) ;
F_94 ( V_15 ) ;
}
V_45 |= V_131 ;
}
F_92 ( V_86 ) ;
V_136:
F_149 ( V_83 , V_124 , V_125 ) ;
V_71:
return V_45 ;
V_117:
F_92 ( V_86 ) ;
return V_45 ;
}
struct V_15 * F_167 ( struct V_76 * V_77 ,
unsigned long V_111 ,
T_1 * V_17 ,
unsigned int V_96 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
struct V_15 * V_15 = NULL ;
F_168 ( F_115 ( V_83 , V_17 ) ) ;
if ( V_96 & V_138 && ! F_169 ( * V_17 ) )
goto V_71;
if ( ( V_96 & V_139 ) && F_18 ( * V_17 ) )
return F_170 ( - V_140 ) ;
if ( ( V_96 & V_141 ) && F_171 ( * V_17 ) )
goto V_71;
V_15 = F_19 ( * V_17 ) ;
F_40 ( ! F_120 ( V_15 ) ) ;
if ( V_96 & V_142 ) {
T_1 V_122 ;
V_122 = F_127 ( F_96 ( * V_17 ) ) ;
if ( F_128 ( V_77 , V_111 & V_97 ,
V_17 , V_122 , 1 ) )
F_129 ( V_77 , V_111 , V_17 ) ;
}
if ( ( V_96 & V_143 ) && ( V_77 -> V_78 & V_144 ) ) {
if ( V_15 -> V_145 && F_172 ( V_15 ) ) {
F_173 () ;
if ( V_15 -> V_145 )
F_174 ( V_15 ) ;
F_175 ( V_15 ) ;
}
}
V_15 += ( V_111 & ~ V_97 ) >> V_6 ;
F_40 ( ! F_86 ( V_15 ) ) ;
if ( V_96 & V_146 )
F_176 ( V_15 ) ;
V_71:
return V_15 ;
}
int F_177 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_111 , T_1 V_17 , T_1 * V_147 )
{
T_7 * V_86 ;
struct V_118 * V_118 = NULL ;
struct V_15 * V_15 ;
unsigned long V_84 = V_111 & V_97 ;
int V_148 = - 1 , V_149 = F_112 () ;
int V_150 , V_151 = - 1 ;
bool V_152 ;
bool V_153 = false ;
int V_96 = 0 ;
V_86 = F_90 ( V_83 , V_147 ) ;
if ( F_9 ( ! F_126 ( V_17 , * V_147 ) ) )
goto V_117;
if ( F_9 ( F_178 ( * V_147 ) ) ) {
F_92 ( V_86 ) ;
F_179 ( V_77 -> V_118 , V_147 ) ;
goto V_71;
}
V_15 = F_19 ( V_17 ) ;
F_31 ( F_16 ( V_15 ) ) ;
V_148 = F_153 ( V_15 ) ;
V_151 = F_180 ( V_15 ) ;
F_181 ( V_154 ) ;
if ( V_148 == V_149 ) {
F_181 ( V_155 ) ;
V_96 |= V_156 ;
}
if ( ! F_169 ( V_17 ) )
V_96 |= V_157 ;
V_152 = F_172 ( V_15 ) ;
V_150 = F_182 ( V_15 , V_77 , V_84 ) ;
if ( V_150 == - 1 ) {
if ( V_152 )
goto V_158;
}
if ( ! V_152 ) {
F_92 ( V_86 ) ;
F_183 ( V_15 ) ;
V_148 = - 1 ;
goto V_71;
}
F_121 ( V_15 ) ;
F_92 ( V_86 ) ;
V_118 = F_184 ( V_15 ) ;
F_161 ( V_86 ) ;
if ( F_9 ( ! F_126 ( V_17 , * V_147 ) ) ) {
F_175 ( V_15 ) ;
F_94 ( V_15 ) ;
V_148 = - 1 ;
goto V_117;
}
if ( F_9 ( ! V_118 ) ) {
F_94 ( V_15 ) ;
V_148 = - 1 ;
goto V_158;
}
F_92 ( V_86 ) ;
V_153 = F_185 ( V_83 , V_77 ,
V_147 , V_17 , V_111 , V_15 , V_150 ) ;
if ( V_153 ) {
V_96 |= V_159 ;
V_148 = V_150 ;
}
goto V_71;
V_158:
F_31 ( ! F_186 ( V_15 ) ) ;
V_17 = F_187 ( V_17 ) ;
F_99 ( V_83 , V_84 , V_147 , V_17 ) ;
F_40 ( F_171 ( * V_147 ) ) ;
F_129 ( V_77 , V_111 , V_147 ) ;
F_175 ( V_15 ) ;
V_117:
F_92 ( V_86 ) ;
V_71:
if ( V_118 )
F_188 ( V_118 ) ;
if ( V_148 != - 1 )
F_189 ( V_151 , V_148 , V_31 , V_96 ) ;
return 0 ;
}
int F_190 ( struct V_160 * V_161 , struct V_76 * V_77 ,
T_1 * V_17 , unsigned long V_111 )
{
T_7 * V_86 ;
int V_45 = 0 ;
if ( F_191 ( V_17 , V_77 , & V_86 ) == 1 ) {
struct V_15 * V_15 ;
T_6 V_85 ;
T_1 V_119 ;
V_119 = F_192 ( V_161 -> V_83 , V_111 , V_17 ) ;
F_193 ( V_161 , V_17 , V_111 ) ;
V_85 = F_135 ( V_161 -> V_83 , V_17 ) ;
if ( F_18 ( V_119 ) ) {
F_194 ( & V_161 -> V_83 -> V_90 ) ;
F_92 ( V_86 ) ;
F_30 () ;
} else {
V_15 = F_19 ( V_119 ) ;
F_159 ( V_15 ) ;
F_40 ( F_162 ( V_15 ) < 0 ) ;
F_100 ( V_161 -> V_83 , V_89 , - V_31 ) ;
F_40 ( ! F_120 ( V_15 ) ) ;
F_194 ( & V_161 -> V_83 -> V_90 ) ;
F_92 ( V_86 ) ;
F_195 ( V_161 , V_15 ) ;
}
F_95 ( V_161 -> V_83 , V_85 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_196 ( struct V_76 * V_77 , T_1 * V_17 ,
unsigned long V_111 , unsigned long V_162 ,
unsigned char * V_163 )
{
T_7 * V_86 ;
int V_45 = 0 ;
if ( F_191 ( V_17 , V_77 , & V_86 ) == 1 ) {
F_92 ( V_86 ) ;
memset ( V_163 , 1 , ( V_162 - V_111 ) >> V_6 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_197 ( struct V_76 * V_77 , struct V_76 * V_164 ,
unsigned long V_165 ,
unsigned long V_166 , unsigned long V_167 ,
T_1 * V_168 , T_1 * V_169 )
{
T_7 * V_170 , * V_171 ;
int V_45 = 0 ;
T_1 V_17 ;
struct V_82 * V_83 = V_77 -> V_137 ;
if ( ( V_165 & ~ V_97 ) ||
( V_166 & ~ V_97 ) ||
V_167 - V_165 < V_99 ||
( V_164 -> V_78 & V_172 ) )
goto V_71;
if ( F_198 ( ! F_91 ( * V_169 ) ) ) {
F_40 ( F_117 ( * V_169 ) ) ;
goto V_71;
}
V_45 = F_191 ( V_168 , V_77 , & V_170 ) ;
if ( V_45 == 1 ) {
V_171 = F_115 ( V_83 , V_169 ) ;
if ( V_171 != V_170 )
F_116 ( V_171 , V_115 ) ;
V_17 = F_192 ( V_83 , V_165 , V_168 ) ;
F_40 ( ! F_91 ( * V_169 ) ) ;
F_99 ( V_83 , V_166 , V_169 , F_199 ( V_17 ) ) ;
if ( V_171 != V_170 ) {
T_6 V_85 ;
V_85 = F_135 ( V_83 , V_168 ) ;
F_98 ( V_83 , V_169 , V_85 ) ;
F_92 ( V_171 ) ;
}
F_92 ( V_170 ) ;
}
V_71:
return V_45 ;
}
int F_200 ( struct V_76 * V_77 , T_1 * V_17 ,
unsigned long V_111 , T_5 V_173 , int V_174 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
T_7 * V_86 ;
int V_45 = 0 ;
if ( F_191 ( V_17 , V_77 , & V_86 ) == 1 ) {
T_1 V_81 ;
V_45 = 1 ;
if ( ! V_174 ) {
V_81 = F_192 ( V_83 , V_111 , V_17 ) ;
if ( F_171 ( V_81 ) )
V_81 = F_187 ( V_81 ) ;
V_81 = F_201 ( V_81 , V_173 ) ;
V_45 = V_31 ;
F_31 ( F_169 ( V_81 ) ) ;
} else {
struct V_15 * V_15 = F_19 ( * V_17 ) ;
if ( ! F_16 ( V_15 ) &&
! F_171 ( * V_17 ) ) {
V_81 = * V_17 ;
V_81 = F_202 ( V_81 ) ;
V_45 = V_31 ;
}
}
if ( V_45 == V_31 )
F_99 ( V_83 , V_111 , V_17 , V_81 ) ;
F_92 ( V_86 ) ;
}
return V_45 ;
}
int F_191 ( T_1 * V_17 , struct V_76 * V_77 ,
T_7 * * V_86 )
{
* V_86 = F_90 ( V_77 -> V_137 , V_17 ) ;
if ( F_21 ( F_117 ( * V_17 ) ) ) {
if ( F_9 ( F_118 ( * V_17 ) ) ) {
F_92 ( * V_86 ) ;
F_119 ( V_77 -> V_118 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_92 ( * V_86 ) ;
return 0 ;
}
T_1 * F_203 ( struct V_15 * V_15 ,
struct V_82 * V_83 ,
unsigned long V_95 ,
enum V_175 V_47 ,
T_7 * * V_86 )
{
T_1 * V_17 ;
if ( V_95 & ~ V_97 )
return NULL ;
V_17 = F_204 ( V_83 , V_95 ) ;
if ( ! V_17 )
return NULL ;
* V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_91 ( * V_17 ) )
goto V_121;
if ( F_19 ( * V_17 ) != V_15 )
goto V_121;
if ( V_47 == V_176 &&
F_118 ( * V_17 ) )
goto V_121;
if ( F_117 ( * V_17 ) ) {
F_40 ( V_47 == V_177 &&
! F_118 ( * V_17 ) ) ;
return V_17 ;
}
V_121:
F_92 ( * V_86 ) ;
return NULL ;
}
static int F_205 ( struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
T_7 * V_86 ;
T_1 * V_17 ;
int V_45 = 0 ;
const unsigned long V_124 = V_95 ;
const unsigned long V_125 = V_95 + V_99 ;
F_133 ( V_83 , V_124 , V_125 ) ;
V_17 = F_203 ( V_15 , V_83 , V_95 ,
V_176 , & V_86 ) ;
if ( V_17 ) {
F_206 ( V_77 , V_95 , V_17 ) ;
V_45 = 1 ;
F_92 ( V_86 ) ;
}
F_149 ( V_83 , V_124 , V_125 ) ;
return V_45 ;
}
static void F_207 ( struct V_15 * V_15 ,
struct V_178 * V_179 )
{
int V_123 ;
struct V_1 * V_1 = F_208 ( V_15 ) ;
struct V_180 * V_180 ;
int V_181 = 0 ;
F_209 ( & V_1 -> V_182 ) ;
V_180 = F_210 ( V_15 , V_1 ) ;
F_211 ( V_15 ) ;
F_212 ( V_15 ) ;
for ( V_123 = V_31 - 1 ; V_123 >= 1 ; V_123 -- ) {
struct V_15 * V_183 = V_15 + V_123 ;
F_31 ( F_162 ( V_183 ) < 0 ) ;
V_181 += F_162 ( V_183 ) ;
F_31 ( V_181 < 0 ) ;
F_31 ( F_34 ( & V_183 -> V_184 ) != 0 ) ;
F_213 ( F_162 ( V_15 ) + F_162 ( V_183 ) + 1 ,
& V_183 -> V_184 ) ;
F_214 () ;
V_183 -> V_96 &= ~ V_185 | V_186 ;
V_183 -> V_96 |= ( V_15 -> V_96 &
( ( 1L << V_187 ) |
( 1L << V_188 ) |
( 1L << V_189 ) |
( 1L << V_190 ) |
( 1L << V_191 ) |
( 1L << V_192 ) ) ) ;
V_183 -> V_96 |= ( 1L << V_193 ) ;
F_147 () ;
V_183 -> V_194 = V_15 -> V_194 ;
F_31 ( V_183 -> V_145 ) ;
V_183 -> V_145 = V_15 -> V_145 ;
V_183 -> V_195 = V_15 -> V_195 + V_123 ;
F_215 ( V_183 , F_180 ( V_15 ) ) ;
F_31 ( ! F_216 ( V_183 ) ) ;
F_31 ( ! F_217 ( V_183 ) ) ;
F_31 ( ! F_218 ( V_183 ) ) ;
F_31 ( ! F_219 ( V_183 ) ) ;
F_220 ( V_15 , V_183 , V_180 , V_179 ) ;
}
F_221 ( V_181 , & V_15 -> V_184 ) ;
F_31 ( F_34 ( & V_15 -> V_184 ) <= 0 ) ;
F_222 ( V_1 , V_196 , - 1 ) ;
F_223 ( V_15 ) ;
F_224 ( V_15 ) ;
F_225 ( & V_1 -> V_182 ) ;
for ( V_123 = 1 ; V_123 < V_31 ; V_123 ++ ) {
struct V_15 * V_183 = V_15 + V_123 ;
F_31 ( F_226 ( V_183 ) <= 0 ) ;
F_94 ( V_183 ) ;
}
F_31 ( F_226 ( V_15 ) <= 0 ) ;
}
static int F_227 ( struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
T_7 * V_86 ;
T_1 * V_17 , V_122 ;
int V_45 = 0 , V_123 ;
T_6 V_85 ;
unsigned long V_84 ;
V_17 = F_203 ( V_15 , V_83 , V_95 ,
V_177 , & V_86 ) ;
if ( V_17 ) {
V_85 = F_135 ( V_83 , V_17 ) ;
F_136 ( V_83 , & V_122 , V_85 ) ;
V_84 = V_95 ;
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ , V_84 += V_128 ) {
T_9 * V_129 , V_81 ;
F_31 ( F_86 ( V_15 + V_123 ) ) ;
V_81 = F_137 ( V_15 + V_123 , V_77 -> V_88 ) ;
V_81 = F_138 ( F_139 ( V_81 ) , V_77 ) ;
if ( ! F_169 ( * V_17 ) )
V_81 = F_228 ( V_81 ) ;
else
F_31 ( F_162 ( V_15 ) != 1 ) ;
if ( ! F_229 ( * V_17 ) )
V_81 = F_230 ( V_81 ) ;
if ( F_171 ( * V_17 ) )
V_81 = F_231 ( V_81 ) ;
V_129 = F_143 ( & V_122 , V_84 ) ;
F_31 ( ! F_144 ( * V_129 ) ) ;
F_145 ( V_83 , V_84 , V_129 , V_81 ) ;
F_146 ( V_129 ) ;
}
F_147 () ;
F_232 ( V_77 , V_95 , V_17 ) ;
F_136 ( V_83 , V_17 , V_85 ) ;
V_45 = 1 ;
F_92 ( V_86 ) ;
}
return V_45 ;
}
static void F_233 ( struct V_15 * V_15 ,
struct V_118 * V_118 ,
struct V_178 * V_179 )
{
int V_197 , V_198 ;
T_10 V_199 = V_15 -> V_195 << ( V_200 - V_6 ) ;
struct V_201 * V_202 ;
F_31 ( ! F_120 ( V_15 ) ) ;
F_31 ( F_234 ( V_15 ) ) ;
V_197 = 0 ;
F_235 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_76 * V_77 = V_202 -> V_77 ;
unsigned long V_111 = F_236 ( V_15 , V_77 ) ;
F_31 ( F_237 ( V_77 ) ) ;
V_197 += F_205 ( V_15 , V_77 , V_111 ) ;
}
if ( V_197 != F_162 ( V_15 ) )
F_11 ( V_11 L_15 ,
V_197 , F_162 ( V_15 ) ) ;
F_31 ( V_197 != F_162 ( V_15 ) ) ;
F_207 ( V_15 , V_179 ) ;
V_198 = 0 ;
F_235 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_76 * V_77 = V_202 -> V_77 ;
unsigned long V_111 = F_236 ( V_15 , V_77 ) ;
F_31 ( F_237 ( V_77 ) ) ;
V_198 += F_227 ( V_15 , V_77 , V_111 ) ;
}
if ( V_197 != V_198 )
F_11 ( V_11 L_16 ,
V_197 , V_198 , F_162 ( V_15 ) ) ;
F_31 ( V_197 != V_198 ) ;
}
int F_238 ( struct V_15 * V_15 , struct V_178 * V_179 )
{
struct V_118 * V_118 ;
int V_45 = 1 ;
F_31 ( F_16 ( V_15 ) ) ;
F_31 ( ! F_216 ( V_15 ) ) ;
V_118 = F_239 ( V_15 ) ;
if ( ! V_118 )
goto V_71;
F_240 ( V_118 ) ;
V_45 = 0 ;
if ( ! F_86 ( V_15 ) )
goto V_117;
F_31 ( ! F_219 ( V_15 ) ) ;
F_233 ( V_15 , V_118 , V_179 ) ;
F_24 ( V_203 ) ;
F_31 ( F_86 ( V_15 ) ) ;
V_117:
F_241 ( V_118 ) ;
F_242 ( V_118 ) ;
V_71:
return V_45 ;
}
int F_243 ( struct V_76 * V_77 ,
unsigned long * V_78 , int V_204 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
switch ( V_204 ) {
case V_205 :
if ( * V_78 & ( V_206 | V_207 ) )
return - V_42 ;
if ( V_83 -> V_208 & V_172 )
return - V_42 ;
* V_78 &= ~ V_172 ;
* V_78 |= V_206 ;
if ( F_9 ( F_244 ( V_77 ) ) )
return - V_66 ;
break;
case V_209 :
if ( * V_78 & ( V_172 | V_207 ) )
return - V_42 ;
* V_78 &= ~ V_206 ;
* V_78 |= V_172 ;
break;
}
return 0 ;
}
static int T_4 F_77 ( void )
{
V_210 = F_245 ( L_17 ,
sizeof( struct V_211 ) ,
F_246 ( struct V_211 ) , 0 , NULL ) ;
if ( ! V_210 )
return - V_66 ;
return 0 ;
}
static inline struct V_211 * F_247 ( void )
{
if ( ! V_210 )
return NULL ;
return F_248 ( V_210 , V_105 ) ;
}
static inline void F_249 ( struct V_211 * V_211 )
{
F_250 ( V_210 , V_211 ) ;
}
static struct V_211 * F_251 ( struct V_82 * V_83 )
{
struct V_211 * V_211 ;
F_252 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_83 == V_211 -> V_83 )
return V_211 ;
return NULL ;
}
static void F_253 ( struct V_82 * V_83 ,
struct V_211 * V_211 )
{
V_211 -> V_83 = V_83 ;
F_254 ( V_212 , & V_211 -> V_213 , ( long ) V_83 ) ;
}
static inline int F_255 ( struct V_82 * V_83 )
{
return F_34 ( & V_83 -> V_214 ) == 0 ;
}
int F_256 ( struct V_82 * V_83 )
{
struct V_211 * V_211 ;
int V_215 ;
V_211 = F_247 () ;
if ( ! V_211 )
return - V_66 ;
F_40 ( F_255 ( V_83 ) ) ;
if ( F_9 ( F_257 ( V_216 , & V_83 -> V_96 ) ) ) {
F_249 ( V_211 ) ;
return 0 ;
}
F_161 ( & V_217 ) ;
F_253 ( V_83 , V_211 ) ;
V_215 = F_13 ( & V_12 . V_13 ) ;
F_258 ( & V_211 -> V_218 , & V_12 . V_13 ) ;
F_92 ( & V_217 ) ;
F_259 ( & V_83 -> V_219 ) ;
if ( V_215 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_244 ( struct V_76 * V_77 )
{
unsigned long V_220 , V_221 ;
if ( ! V_77 -> V_118 )
return 0 ;
if ( V_77 -> V_222 )
return 0 ;
F_40 ( V_77 -> V_78 & V_207 ) ;
V_220 = ( V_77 -> V_98 + ~ V_97 ) & V_97 ;
V_221 = V_77 -> V_100 & V_97 ;
if ( V_220 < V_221 )
return F_109 ( V_77 ) ;
return 0 ;
}
void F_260 ( struct V_82 * V_83 )
{
struct V_211 * V_211 ;
int free = 0 ;
F_161 ( & V_217 ) ;
V_211 = F_251 ( V_83 ) ;
if ( V_211 && V_12 . V_211 != V_211 ) {
F_261 ( & V_211 -> V_213 ) ;
F_262 ( & V_211 -> V_218 ) ;
free = 1 ;
}
F_92 ( & V_217 ) ;
if ( free ) {
F_43 ( V_216 , & V_83 -> V_96 ) ;
F_249 ( V_211 ) ;
F_263 ( V_83 ) ;
} else if ( V_211 ) {
F_264 ( & V_83 -> V_223 ) ;
F_265 ( & V_83 -> V_223 ) ;
}
}
static void F_266 ( struct V_15 * V_15 )
{
F_267 ( V_15 , V_224 + 0 ) ;
F_175 ( V_15 ) ;
F_268 ( V_15 ) ;
}
static void F_269 ( T_9 * V_129 , T_9 * V_225 )
{
while ( -- V_225 >= V_129 ) {
T_9 V_226 = * V_225 ;
if ( ! F_144 ( V_226 ) )
F_266 ( F_270 ( V_226 ) ) ;
}
}
static int F_271 ( struct V_76 * V_77 ,
unsigned long V_95 ,
T_9 * V_129 )
{
struct V_15 * V_15 ;
T_9 * V_225 ;
int V_227 = 0 , V_228 = 0 ;
for ( V_225 = V_129 ; V_225 < V_129 + V_31 ;
V_225 ++ , V_95 += V_128 ) {
T_9 V_226 = * V_225 ;
if ( F_144 ( V_226 ) ) {
if ( ++ V_228 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_272 ( V_226 ) || ! F_273 ( V_226 ) )
goto V_71;
V_15 = F_274 ( V_77 , V_95 , V_226 ) ;
if ( F_9 ( ! V_15 ) )
goto V_71;
F_40 ( F_86 ( V_15 ) ) ;
F_31 ( ! F_216 ( V_15 ) ) ;
F_40 ( ! F_219 ( V_15 ) ) ;
if ( F_226 ( V_15 ) != 1 )
goto V_71;
if ( ! F_172 ( V_15 ) )
goto V_71;
if ( F_275 ( V_15 ) ) {
F_175 ( V_15 ) ;
goto V_71;
}
F_276 ( V_15 , V_224 + 0 ) ;
F_40 ( ! F_186 ( V_15 ) ) ;
F_40 ( F_277 ( V_15 ) ) ;
if ( F_278 ( V_226 ) || F_279 ( V_15 ) ||
F_280 ( V_77 -> V_137 , V_95 ) )
V_227 = 1 ;
}
if ( F_21 ( V_227 ) )
return 1 ;
V_71:
F_269 ( V_129 , V_225 ) ;
return 0 ;
}
static void F_281 ( T_9 * V_129 , struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_7 * V_86 )
{
T_9 * V_225 ;
for ( V_225 = V_129 ; V_225 < V_129 + V_31 ; V_225 ++ ) {
T_9 V_226 = * V_225 ;
struct V_15 * V_114 ;
if ( F_144 ( V_226 ) ) {
F_132 ( V_15 , V_95 ) ;
F_100 ( V_77 -> V_137 , V_89 , 1 ) ;
} else {
V_114 = F_270 ( V_226 ) ;
F_157 ( V_15 , V_114 , V_95 , V_77 ) ;
F_40 ( F_162 ( V_114 ) != 1 ) ;
F_266 ( V_114 ) ;
F_161 ( V_86 ) ;
F_282 ( V_77 -> V_137 , V_95 , V_225 ) ;
F_159 ( V_114 ) ;
F_92 ( V_86 ) ;
F_283 ( V_114 ) ;
}
V_95 += V_128 ;
V_15 ++ ;
}
}
static void F_284 ( void )
{
F_285 ( V_14 , false ,
F_286 ( V_56 ) ) ;
}
static int F_287 ( void )
{
static int V_229 = V_230 ;
int V_231 , V_232 = 0 , V_233 = 0 ;
for ( V_231 = 0 ; V_231 < V_234 ; V_231 ++ )
if ( V_235 [ V_231 ] > V_233 ) {
V_233 = V_235 [ V_231 ] ;
V_232 = V_231 ;
}
if ( V_232 <= V_229 )
for ( V_231 = V_229 + 1 ; V_231 < V_234 ;
V_231 ++ )
if ( V_233 == V_235 [ V_231 ] ) {
V_232 = V_231 ;
break;
}
V_229 = V_232 ;
return V_232 ;
}
static bool F_288 ( struct V_15 * * V_236 , bool * V_237 )
{
if ( F_10 ( * V_236 ) ) {
if ( ! * V_237 )
return false ;
* V_237 = false ;
* V_236 = NULL ;
F_284 () ;
} else if ( * V_236 ) {
F_94 ( * V_236 ) ;
* V_236 = NULL ;
}
return true ;
}
static struct V_15
* F_289 ( struct V_15 * * V_236 , struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
int V_238 )
{
F_40 ( * V_236 ) ;
* V_236 = F_290 ( V_238 , F_102 (
F_291 () , V_132 ) , V_24 ) ;
F_292 ( & V_83 -> V_223 ) ;
if ( F_9 ( ! * V_236 ) ) {
F_24 ( V_239 ) ;
* V_236 = F_170 ( - V_66 ) ;
return NULL ;
}
F_24 ( V_240 ) ;
return * V_236 ;
}
static int F_287 ( void )
{
return 0 ;
}
static inline struct V_15 * F_293 ( int V_91 )
{
return F_23 ( F_102 ( V_91 , 0 ) ,
V_24 ) ;
}
static struct V_15 * F_294 ( bool * V_237 )
{
struct V_15 * V_236 ;
do {
V_236 = F_293 ( F_291 () ) ;
if ( ! V_236 ) {
F_24 ( V_239 ) ;
if ( ! * V_237 )
return NULL ;
* V_237 = false ;
F_284 () ;
} else
F_24 ( V_240 ) ;
} while ( F_9 ( ! V_236 ) && F_21 ( F_2 () ) );
return V_236 ;
}
static bool F_288 ( struct V_15 * * V_236 , bool * V_237 )
{
if ( ! * V_236 )
* V_236 = F_294 ( V_237 ) ;
if ( F_9 ( ! * V_236 ) )
return false ;
return true ;
}
static struct V_15
* F_289 ( struct V_15 * * V_236 , struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
int V_238 )
{
F_292 ( & V_83 -> V_223 ) ;
F_40 ( ! * V_236 ) ;
return * V_236 ;
}
static bool F_295 ( struct V_76 * V_77 )
{
if ( ( ! ( V_77 -> V_78 & V_206 ) && ! F_296 () ) ||
( V_77 -> V_78 & V_172 ) )
return false ;
if ( ! V_77 -> V_118 || V_77 -> V_222 )
return false ;
if ( F_237 ( V_77 ) )
return false ;
F_40 ( V_77 -> V_78 & V_207 ) ;
return true ;
}
static void F_297 ( struct V_82 * V_83 ,
unsigned long V_95 ,
struct V_15 * * V_236 ,
struct V_76 * V_77 ,
int V_238 )
{
T_1 * V_17 , V_122 ;
T_9 * V_129 ;
T_6 V_85 ;
struct V_15 * V_134 ;
T_7 * V_241 , * V_242 ;
int V_243 ;
unsigned long V_220 , V_221 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_40 ( V_95 & ~ V_97 ) ;
V_134 = F_289 ( V_236 , V_83 , V_77 , V_95 , V_238 ) ;
if ( ! V_134 )
return;
if ( F_9 ( F_113 ( V_134 , V_83 , V_105 ) ) )
return;
F_264 ( & V_83 -> V_223 ) ;
if ( F_9 ( F_255 ( V_83 ) ) )
goto V_71;
V_77 = F_298 ( V_83 , V_95 ) ;
if ( ! V_77 )
goto V_71;
V_220 = ( V_77 -> V_98 + ~ V_97 ) & V_97 ;
V_221 = V_77 -> V_100 & V_97 ;
if ( V_95 < V_220 || V_95 + V_99 > V_221 )
goto V_71;
if ( ! F_295 ( V_77 ) )
goto V_71;
V_17 = F_204 ( V_83 , V_95 ) ;
if ( ! V_17 )
goto V_71;
if ( F_117 ( * V_17 ) )
goto V_71;
F_240 ( V_77 -> V_118 ) ;
V_129 = F_143 ( V_17 , V_95 ) ;
V_242 = F_299 ( V_83 , V_17 ) ;
V_124 = V_95 ;
V_125 = V_95 + V_99 ;
F_133 ( V_83 , V_124 , V_125 ) ;
V_241 = F_90 ( V_83 , V_17 ) ;
V_122 = F_134 ( V_77 , V_95 , V_17 ) ;
F_92 ( V_241 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
F_161 ( V_242 ) ;
V_243 = F_271 ( V_77 , V_95 , V_129 ) ;
F_92 ( V_242 ) ;
if ( F_9 ( ! V_243 ) ) {
F_146 ( V_129 ) ;
F_161 ( V_241 ) ;
F_31 ( ! F_91 ( * V_17 ) ) ;
F_136 ( V_83 , V_17 , F_300 ( V_122 ) ) ;
F_92 ( V_241 ) ;
F_241 ( V_77 -> V_118 ) ;
goto V_71;
}
F_241 ( V_77 -> V_118 ) ;
F_281 ( V_129 , V_134 , V_77 , V_95 , V_242 ) ;
F_146 ( V_129 ) ;
F_89 ( V_134 ) ;
V_85 = F_300 ( V_122 ) ;
V_122 = F_82 ( V_134 , V_77 -> V_88 ) ;
V_122 = F_80 ( F_96 ( V_122 ) , V_77 ) ;
F_147 () ;
F_161 ( V_241 ) ;
F_31 ( ! F_91 ( * V_17 ) ) ;
F_97 ( V_134 , V_77 , V_95 ) ;
F_98 ( V_83 , V_17 , V_85 ) ;
F_99 ( V_83 , V_95 , V_17 , V_122 ) ;
F_129 ( V_77 , V_95 , V_17 ) ;
F_92 ( V_241 ) ;
* V_236 = NULL ;
V_59 ++ ;
V_244:
F_265 ( & V_83 -> V_223 ) ;
return;
V_71:
F_93 ( V_134 ) ;
goto V_244;
}
static int F_301 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
struct V_15 * * V_236 )
{
T_1 * V_17 ;
T_9 * V_129 , * V_225 ;
int V_45 = 0 , V_227 = 0 , V_228 = 0 ;
struct V_15 * V_15 ;
unsigned long V_245 ;
T_7 * V_86 ;
int V_238 = V_230 ;
F_40 ( V_95 & ~ V_97 ) ;
V_17 = F_204 ( V_83 , V_95 ) ;
if ( ! V_17 )
goto V_71;
if ( F_117 ( * V_17 ) )
goto V_71;
memset ( V_235 , 0 , sizeof( V_235 ) ) ;
V_129 = F_302 ( V_83 , V_17 , V_95 , & V_86 ) ;
for ( V_245 = V_95 , V_225 = V_129 ; V_225 < V_129 + V_31 ;
V_225 ++ , V_245 += V_128 ) {
T_9 V_226 = * V_225 ;
if ( F_144 ( V_226 ) ) {
if ( ++ V_228 <= V_62 )
continue;
else
goto V_246;
}
if ( ! F_272 ( V_226 ) || ! F_273 ( V_226 ) )
goto V_246;
V_15 = F_274 ( V_77 , V_245 , V_226 ) ;
if ( F_9 ( ! V_15 ) )
goto V_246;
V_238 = F_153 ( V_15 ) ;
V_235 [ V_238 ] ++ ;
F_40 ( F_86 ( V_15 ) ) ;
if ( ! F_277 ( V_15 ) || F_186 ( V_15 ) || ! F_216 ( V_15 ) )
goto V_246;
if ( F_226 ( V_15 ) != 1 )
goto V_246;
if ( F_278 ( V_226 ) || F_279 ( V_15 ) ||
F_280 ( V_77 -> V_137 , V_95 ) )
V_227 = 1 ;
}
if ( V_227 )
V_45 = 1 ;
V_246:
F_303 ( V_129 , V_86 ) ;
if ( V_45 ) {
V_238 = F_287 () ;
F_297 ( V_83 , V_95 , V_236 , V_77 , V_238 ) ;
}
V_71:
return V_45 ;
}
static void F_304 ( struct V_211 * V_211 )
{
struct V_82 * V_83 = V_211 -> V_83 ;
F_40 ( V_247 != 1 && ! F_305 ( & V_217 ) ) ;
if ( F_255 ( V_83 ) ) {
F_261 ( & V_211 -> V_213 ) ;
F_262 ( & V_211 -> V_218 ) ;
F_249 ( V_211 ) ;
F_263 ( V_83 ) ;
}
}
static unsigned int F_306 ( unsigned int V_58 ,
struct V_15 * * V_236 )
__releases( &khugepaged_mm_lock
static int F_307 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_308 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_309 () ;
}
static void F_310 ( void )
{
struct V_15 * V_236 = NULL ;
unsigned int V_248 = 0 , V_249 = 0 ;
unsigned int V_58 = V_57 ;
bool V_237 = true ;
F_311 () ;
while ( V_248 < V_58 ) {
if ( ! F_288 ( & V_236 , & V_237 ) )
break;
F_158 () ;
if ( F_9 ( F_309 () || F_312 ( V_250 ) ) )
break;
F_161 ( & V_217 ) ;
if ( ! V_12 . V_211 )
V_249 ++ ;
if ( F_307 () &&
V_249 < 2 )
V_248 += F_306 ( V_58 - V_248 ,
& V_236 ) ;
else
V_248 = V_58 ;
F_92 ( & V_217 ) ;
}
if ( ! F_313 ( V_236 ) )
F_94 ( V_236 ) ;
}
static void F_314 ( void )
{
F_315 () ;
if ( F_307 () ) {
if ( ! V_53 )
return;
F_285 ( V_14 ,
F_309 () ,
F_286 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_316 ( V_14 , F_308 () ) ;
}
static int V_10 ( void * V_228 )
{
struct V_211 * V_211 ;
F_317 () ;
F_318 ( V_250 , 19 ) ;
while ( ! F_309 () ) {
F_310 () ;
F_314 () ;
}
F_161 ( & V_217 ) ;
V_211 = V_12 . V_211 ;
V_12 . V_211 = NULL ;
if ( V_211 )
F_304 ( V_211 ) ;
F_92 ( & V_217 ) ;
return 0 ;
}
static void F_319 ( struct V_76 * V_77 ,
unsigned long V_84 , T_1 * V_17 )
{
struct V_82 * V_83 = V_77 -> V_137 ;
T_6 V_85 ;
T_1 V_122 ;
int V_123 ;
F_134 ( V_77 , V_84 , V_17 ) ;
V_85 = F_135 ( V_83 , V_17 ) ;
F_136 ( V_83 , & V_122 , V_85 ) ;
for ( V_123 = 0 ; V_123 < V_31 ; V_123 ++ , V_84 += V_128 ) {
T_9 * V_129 , V_81 ;
V_81 = F_140 ( F_141 ( V_84 ) , V_77 -> V_88 ) ;
V_81 = F_142 ( V_81 ) ;
V_129 = F_143 ( & V_122 , V_84 ) ;
F_40 ( ! F_144 ( * V_129 ) ) ;
F_145 ( V_83 , V_84 , V_129 , V_81 ) ;
F_146 ( V_129 ) ;
}
F_147 () ;
F_136 ( V_83 , V_17 , V_85 ) ;
F_30 () ;
}
void F_320 ( struct V_76 * V_77 , unsigned long V_95 ,
T_1 * V_17 )
{
T_7 * V_86 ;
struct V_15 * V_15 ;
struct V_82 * V_83 = V_77 -> V_137 ;
unsigned long V_84 = V_95 & V_97 ;
unsigned long V_124 ;
unsigned long V_125 ;
F_31 ( V_77 -> V_98 > V_84 || V_77 -> V_100 < V_84 + V_99 ) ;
V_124 = V_84 ;
V_125 = V_84 + V_99 ;
V_251:
F_133 ( V_83 , V_124 , V_125 ) ;
V_86 = F_90 ( V_83 , V_17 ) ;
if ( F_9 ( ! F_117 ( * V_17 ) ) ) {
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
return;
}
if ( F_18 ( * V_17 ) ) {
F_319 ( V_77 , V_84 , V_17 ) ;
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
return;
}
V_15 = F_19 ( * V_17 ) ;
F_40 ( ! F_226 ( V_15 ) ) ;
F_121 ( V_15 ) ;
F_92 ( V_86 ) ;
F_149 ( V_83 , V_124 , V_125 ) ;
F_165 ( V_15 ) ;
F_94 ( V_15 ) ;
if ( F_9 ( F_117 ( * V_17 ) ) )
goto V_251;
}
void F_321 ( struct V_82 * V_83 , unsigned long V_95 ,
T_1 * V_17 )
{
struct V_76 * V_77 ;
V_77 = F_298 ( V_83 , V_95 ) ;
F_31 ( V_77 == NULL ) ;
F_322 ( V_77 , V_95 , V_17 ) ;
}
static void F_323 ( struct V_82 * V_83 ,
unsigned long V_95 )
{
T_1 * V_17 ;
F_40 ( ! ( V_95 & ~ V_97 ) ) ;
V_17 = F_204 ( V_83 , V_95 ) ;
if ( ! V_17 )
return;
F_321 ( V_83 , V_95 , V_17 ) ;
}
void F_324 ( struct V_76 * V_77 ,
unsigned long V_252 ,
unsigned long V_162 ,
long V_253 )
{
if ( V_252 & ~ V_97 &&
( V_252 & V_97 ) >= V_77 -> V_98 &&
( V_252 & V_97 ) + V_99 <= V_77 -> V_100 )
F_323 ( V_77 -> V_137 , V_252 ) ;
if ( V_162 & ~ V_97 &&
( V_162 & V_97 ) >= V_77 -> V_98 &&
( V_162 & V_97 ) + V_99 <= V_77 -> V_100 )
F_323 ( V_77 -> V_137 , V_162 ) ;
if ( V_253 > 0 ) {
struct V_76 * V_254 = V_77 -> V_255 ;
unsigned long V_256 = V_254 -> V_98 ;
V_256 += V_253 << V_6 ;
if ( V_256 & ~ V_97 &&
( V_256 & V_97 ) >= V_254 -> V_98 &&
( V_256 & V_97 ) + V_99 <= V_254 -> V_100 )
F_323 ( V_254 -> V_137 , V_256 ) ;
}
}
