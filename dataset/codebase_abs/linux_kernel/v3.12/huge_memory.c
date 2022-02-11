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
F_40 ( ! F_86 ( V_15 ) ) ;
V_85 = F_87 ( V_83 , V_84 ) ;
if ( F_9 ( ! V_85 ) )
return V_86 ;
F_88 ( V_15 , V_84 , V_31 ) ;
F_89 ( V_15 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_91 ( * V_17 ) ) ) {
F_92 ( & V_83 -> V_87 ) ;
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
V_83 -> V_90 ++ ;
F_92 ( & V_83 -> V_87 ) ;
}
return 0 ;
}
static inline T_7 F_101 ( int V_91 , T_7 V_92 )
{
return ( V_21 & ~ ( V_91 ? 0 : V_93 ) ) | V_92 ;
}
static inline struct V_15 * F_102 ( int V_91 ,
struct V_76 * V_77 ,
unsigned long V_84 , int V_94 ,
T_7 V_92 )
{
return F_103 ( F_101 ( V_91 , V_92 ) ,
V_24 , V_77 , V_84 , V_94 ) ;
}
static inline struct V_15 * F_104 ( int V_91 )
{
return F_23 ( F_101 ( V_91 , 0 ) ,
V_24 ) ;
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
V_83 -> V_90 ++ ;
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
return V_86 ;
if ( F_9 ( F_109 ( V_77 ) ) )
return V_86 ;
if ( ! ( V_96 & V_102 ) &&
F_110 () ) {
T_6 V_85 ;
struct V_15 * V_18 ;
bool V_103 ;
V_85 = F_87 ( V_83 , V_84 ) ;
if ( F_9 ( ! V_85 ) )
return V_86 ;
V_18 = F_20 () ;
if ( F_9 ( ! V_18 ) ) {
F_95 ( V_83 , V_85 ) ;
F_24 ( V_104 ) ;
return V_101 ;
}
F_90 ( & V_83 -> V_87 ) ;
V_103 = F_105 ( V_85 , V_83 , V_77 , V_84 , V_17 ,
V_18 ) ;
F_92 ( & V_83 -> V_87 ) ;
if ( ! V_103 ) {
F_95 ( V_83 , V_85 ) ;
F_30 () ;
}
return 0 ;
}
V_15 = F_102 ( F_111 ( V_77 ) ,
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
struct V_15 * V_112 ;
T_1 V_17 ;
T_6 V_85 ;
int V_45 ;
V_45 = - V_66 ;
V_85 = F_87 ( V_107 , V_111 ) ;
if ( F_9 ( ! V_85 ) )
goto V_71;
F_90 ( & V_107 -> V_87 ) ;
F_115 ( & V_108 -> V_87 , V_113 ) ;
V_45 = - V_114 ;
V_17 = * V_110 ;
if ( F_9 ( ! F_116 ( V_17 ) ) ) {
F_95 ( V_107 , V_85 ) ;
goto V_115;
}
if ( F_18 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_103 ;
V_18 = F_20 () ;
V_103 = F_105 ( V_85 , V_107 , V_77 , V_111 , V_109 ,
V_18 ) ;
F_31 ( ! V_103 ) ;
V_45 = 0 ;
goto V_115;
}
if ( F_9 ( F_117 ( V_17 ) ) ) {
F_92 ( & V_108 -> V_87 ) ;
F_92 ( & V_107 -> V_87 ) ;
F_95 ( V_107 , V_85 ) ;
F_118 ( V_77 -> V_116 , V_110 ) ;
goto V_71;
}
V_112 = F_19 ( V_17 ) ;
F_40 ( ! F_119 ( V_112 ) ) ;
F_120 ( V_112 ) ;
F_121 ( V_112 ) ;
F_100 ( V_107 , V_89 , V_31 ) ;
F_122 ( V_108 , V_111 , V_110 ) ;
V_17 = F_123 ( F_106 ( V_17 ) ) ;
F_98 ( V_107 , V_109 , V_85 ) ;
F_99 ( V_107 , V_111 , V_109 , V_17 ) ;
V_107 -> V_90 ++ ;
V_45 = 0 ;
V_115:
F_92 ( & V_108 -> V_87 ) ;
F_92 ( & V_107 -> V_87 ) ;
V_71:
return V_45 ;
}
void F_124 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 ,
int V_118 )
{
T_1 V_81 ;
unsigned long V_84 ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( * V_17 , V_117 ) ) )
goto V_119;
V_81 = F_126 ( V_117 ) ;
V_84 = V_95 & V_97 ;
if ( F_127 ( V_77 , V_84 , V_17 , V_81 , V_118 ) )
F_128 ( V_77 , V_95 , V_17 ) ;
V_119:
F_92 ( & V_83 -> V_87 ) ;
}
static int F_129 ( struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 , unsigned long V_84 )
{
T_6 V_85 ;
T_1 V_120 ;
struct V_15 * V_15 ;
int V_121 , V_45 = 0 ;
unsigned long V_122 ;
unsigned long V_123 ;
V_15 = F_130 ( V_124 , V_77 , V_95 ) ;
if ( ! V_15 ) {
V_45 |= V_86 ;
goto V_71;
}
if ( F_113 ( V_15 , V_83 , V_105 ) ) {
F_94 ( V_15 ) ;
V_45 |= V_86 ;
goto V_71;
}
F_131 ( V_15 , V_95 ) ;
F_89 ( V_15 ) ;
V_122 = V_84 ;
V_123 = V_84 + V_99 ;
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( * V_17 , V_117 ) ) )
goto V_125;
F_133 ( V_77 , V_84 , V_17 ) ;
V_85 = F_134 ( V_83 , V_17 ) ;
F_135 ( V_83 , & V_120 , V_85 ) ;
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ , V_84 += V_126 ) {
T_8 * V_127 , V_81 ;
if ( V_84 == ( V_95 & V_128 ) ) {
V_81 = F_136 ( V_15 , V_77 -> V_88 ) ;
V_81 = F_137 ( F_138 ( V_81 ) , V_77 ) ;
F_97 ( V_15 , V_77 , V_84 ) ;
} else {
V_81 = F_139 ( F_140 ( V_84 ) , V_77 -> V_88 ) ;
V_81 = F_141 ( V_81 ) ;
}
V_127 = F_142 ( & V_120 , V_84 ) ;
F_40 ( ! F_143 ( * V_127 ) ) ;
F_144 ( V_83 , V_84 , V_127 , V_81 ) ;
F_145 ( V_127 ) ;
}
F_146 () ;
F_135 ( V_83 , V_17 , V_85 ) ;
F_92 ( & V_83 -> V_87 ) ;
F_30 () ;
F_147 ( V_83 , V_89 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
V_45 |= V_129 ;
V_71:
return V_45 ;
V_125:
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
F_93 ( V_15 ) ;
F_94 ( V_15 ) ;
goto V_71;
}
static int F_149 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 ,
struct V_15 * V_15 ,
unsigned long V_84 )
{
T_6 V_85 ;
T_1 V_120 ;
int V_45 = 0 , V_121 ;
struct V_15 * * V_58 ;
unsigned long V_122 ;
unsigned long V_123 ;
V_58 = F_150 ( sizeof( struct V_15 * ) * V_31 ,
V_105 ) ;
if ( F_9 ( ! V_58 ) ) {
V_45 |= V_86 ;
goto V_71;
}
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ ) {
V_58 [ V_121 ] = F_151 ( V_124 |
V_130 ,
V_77 , V_95 , F_152 ( V_15 ) ) ;
if ( F_9 ( ! V_58 [ V_121 ] ||
F_113 ( V_58 [ V_121 ] , V_83 ,
V_105 ) ) ) {
if ( V_58 [ V_121 ] )
F_94 ( V_58 [ V_121 ] ) ;
F_153 () ;
while ( -- V_121 >= 0 ) {
F_93 ( V_58 [ V_121 ] ) ;
F_94 ( V_58 [ V_121 ] ) ;
}
F_154 () ;
F_155 ( V_58 ) ;
V_45 |= V_86 ;
goto V_71;
}
}
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ ) {
F_156 ( V_58 [ V_121 ] , V_15 + V_121 ,
V_84 + V_126 * V_121 , V_77 ) ;
F_89 ( V_58 [ V_121 ] ) ;
F_157 () ;
}
V_122 = V_84 ;
V_123 = V_84 + V_99 ;
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( * V_17 , V_117 ) ) )
goto V_131;
F_40 ( ! F_119 ( V_15 ) ) ;
F_133 ( V_77 , V_84 , V_17 ) ;
V_85 = F_134 ( V_83 , V_17 ) ;
F_135 ( V_83 , & V_120 , V_85 ) ;
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ , V_84 += V_126 ) {
T_8 * V_127 , V_81 ;
V_81 = F_136 ( V_58 [ V_121 ] , V_77 -> V_88 ) ;
V_81 = F_137 ( F_138 ( V_81 ) , V_77 ) ;
F_97 ( V_58 [ V_121 ] , V_77 , V_84 ) ;
V_127 = F_142 ( & V_120 , V_84 ) ;
F_40 ( ! F_143 ( * V_127 ) ) ;
F_144 ( V_83 , V_84 , V_127 , V_81 ) ;
F_145 ( V_127 ) ;
}
F_155 ( V_58 ) ;
F_146 () ;
F_135 ( V_83 , V_17 , V_85 ) ;
F_158 ( V_15 ) ;
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
V_45 |= V_129 ;
F_94 ( V_15 ) ;
V_71:
return V_45 ;
V_131:
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
F_153 () ;
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ ) {
F_93 ( V_58 [ V_121 ] ) ;
F_94 ( V_58 [ V_121 ] ) ;
}
F_154 () ;
F_155 ( V_58 ) ;
goto V_71;
}
int F_159 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_95 , T_1 * V_17 , T_1 V_117 )
{
int V_45 = 0 ;
struct V_15 * V_15 = NULL , * V_132 ;
unsigned long V_84 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_40 ( ! V_77 -> V_116 ) ;
V_84 = V_95 & V_97 ;
if ( F_18 ( V_117 ) )
goto V_133;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( * V_17 , V_117 ) ) )
goto V_115;
V_15 = F_19 ( V_117 ) ;
F_40 ( ! F_86 ( V_15 ) || ! F_119 ( V_15 ) ) ;
if ( F_160 ( V_15 ) == 1 ) {
T_1 V_81 ;
V_81 = F_126 ( V_117 ) ;
V_81 = F_80 ( F_96 ( V_81 ) , V_77 ) ;
if ( F_127 ( V_77 , V_84 , V_17 , V_81 , 1 ) )
F_128 ( V_77 , V_95 , V_17 ) ;
V_45 |= V_129 ;
goto V_115;
}
F_120 ( V_15 ) ;
F_92 ( & V_83 -> V_87 ) ;
V_133:
if ( F_161 ( V_77 ) &&
! F_162 () )
V_132 = F_102 ( F_111 ( V_77 ) ,
V_77 , V_84 , F_112 () , 0 ) ;
else
V_132 = NULL ;
if ( F_9 ( ! V_132 ) ) {
if ( F_18 ( V_117 ) ) {
V_45 = F_129 ( V_83 , V_77 ,
V_95 , V_17 , V_117 , V_84 ) ;
} else {
V_45 = F_149 ( V_83 , V_77 , V_95 ,
V_17 , V_117 , V_15 , V_84 ) ;
if ( V_45 & V_86 )
F_163 ( V_15 ) ;
F_94 ( V_15 ) ;
}
F_24 ( V_104 ) ;
goto V_71;
}
if ( F_9 ( F_113 ( V_132 , V_83 , V_105 ) ) ) {
F_94 ( V_132 ) ;
if ( V_15 ) {
F_163 ( V_15 ) ;
F_94 ( V_15 ) ;
}
F_24 ( V_104 ) ;
V_45 |= V_86 ;
goto V_71;
}
F_24 ( V_106 ) ;
if ( F_18 ( V_117 ) )
F_88 ( V_132 , V_84 , V_31 ) ;
else
F_164 ( V_132 , V_15 , V_84 , V_77 , V_31 ) ;
F_89 ( V_132 ) ;
V_122 = V_84 ;
V_123 = V_84 + V_99 ;
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( V_15 )
F_94 ( V_15 ) ;
if ( F_9 ( ! F_125 ( * V_17 , V_117 ) ) ) {
F_92 ( & V_83 -> V_87 ) ;
F_93 ( V_132 ) ;
F_94 ( V_132 ) ;
goto V_134;
} else {
T_1 V_81 ;
V_81 = F_82 ( V_132 , V_77 -> V_88 ) ;
V_81 = F_80 ( F_96 ( V_81 ) , V_77 ) ;
F_133 ( V_77 , V_84 , V_17 ) ;
F_97 ( V_132 , V_77 , V_84 ) ;
F_99 ( V_83 , V_84 , V_17 , V_81 ) ;
F_128 ( V_77 , V_95 , V_17 ) ;
if ( F_18 ( V_117 ) ) {
F_100 ( V_83 , V_89 , V_31 ) ;
F_30 () ;
} else {
F_40 ( ! F_119 ( V_15 ) ) ;
F_158 ( V_15 ) ;
F_94 ( V_15 ) ;
}
V_45 |= V_129 ;
}
F_92 ( & V_83 -> V_87 ) ;
V_134:
F_148 ( V_83 , V_122 , V_123 ) ;
V_71:
return V_45 ;
V_115:
F_92 ( & V_83 -> V_87 ) ;
return V_45 ;
}
struct V_15 * F_165 ( struct V_76 * V_77 ,
unsigned long V_111 ,
T_1 * V_17 ,
unsigned int V_96 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
struct V_15 * V_15 = NULL ;
F_166 ( & V_83 -> V_87 ) ;
if ( V_96 & V_136 && ! F_167 ( * V_17 ) )
goto V_71;
if ( ( V_96 & V_137 ) && F_18 ( * V_17 ) )
return F_168 ( - V_138 ) ;
V_15 = F_19 ( * V_17 ) ;
F_40 ( ! F_119 ( V_15 ) ) ;
if ( V_96 & V_139 ) {
T_1 V_120 ;
V_120 = F_126 ( F_96 ( * V_17 ) ) ;
if ( F_127 ( V_77 , V_111 & V_97 ,
V_17 , V_120 , 1 ) )
F_128 ( V_77 , V_111 , V_17 ) ;
}
if ( ( V_96 & V_140 ) && ( V_77 -> V_78 & V_141 ) ) {
if ( V_15 -> V_142 && F_169 ( V_15 ) ) {
F_170 () ;
if ( V_15 -> V_142 )
F_171 ( V_15 ) ;
F_172 ( V_15 ) ;
}
}
V_15 += ( V_111 & ~ V_97 ) >> V_6 ;
F_40 ( ! F_86 ( V_15 ) ) ;
if ( V_96 & V_143 )
F_173 ( V_15 ) ;
V_71:
return V_15 ;
}
int F_174 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_111 , T_1 V_17 , T_1 * V_144 )
{
struct V_116 * V_116 = NULL ;
struct V_15 * V_15 ;
unsigned long V_84 = V_111 & V_97 ;
int V_145 = - 1 , V_146 = F_112 () ;
int V_147 ;
bool V_148 ;
bool V_149 = false ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( V_17 , * V_144 ) ) )
goto V_115;
V_15 = F_19 ( V_17 ) ;
V_145 = F_152 ( V_15 ) ;
F_175 ( V_150 ) ;
if ( V_145 == V_146 )
F_175 ( V_151 ) ;
V_148 = F_169 ( V_15 ) ;
V_147 = F_176 ( V_15 , V_77 , V_84 ) ;
if ( V_147 == - 1 ) {
if ( V_148 )
goto V_152;
F_92 ( & V_83 -> V_87 ) ;
F_177 ( V_15 ) ;
V_145 = - 1 ;
goto V_71;
}
F_120 ( V_15 ) ;
F_92 ( & V_83 -> V_87 ) ;
if ( ! V_148 )
F_178 ( V_15 ) ;
V_116 = F_179 ( V_15 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_125 ( V_17 , * V_144 ) ) ) {
F_172 ( V_15 ) ;
F_94 ( V_15 ) ;
V_145 = - 1 ;
goto V_115;
}
F_92 ( & V_83 -> V_87 ) ;
V_149 = F_180 ( V_83 , V_77 ,
V_144 , V_17 , V_111 , V_15 , V_147 ) ;
if ( V_149 )
V_145 = V_147 ;
goto V_71;
V_152:
F_31 ( ! F_181 ( V_15 ) ) ;
V_17 = F_182 ( V_17 ) ;
F_99 ( V_83 , V_84 , V_144 , V_17 ) ;
F_40 ( F_183 ( * V_144 ) ) ;
F_128 ( V_77 , V_111 , V_144 ) ;
F_172 ( V_15 ) ;
V_115:
F_92 ( & V_83 -> V_87 ) ;
V_71:
if ( V_116 )
F_184 ( V_116 ) ;
if ( V_145 != - 1 )
F_185 ( V_145 , V_31 , V_149 ) ;
return 0 ;
}
int F_186 ( struct V_153 * V_154 , struct V_76 * V_77 ,
T_1 * V_17 , unsigned long V_111 )
{
int V_45 = 0 ;
if ( F_187 ( V_17 , V_77 ) == 1 ) {
struct V_15 * V_15 ;
T_6 V_85 ;
T_1 V_117 ;
V_117 = F_188 ( V_154 -> V_83 , V_111 , V_17 ) ;
F_189 ( V_154 , V_17 , V_111 ) ;
V_85 = F_134 ( V_154 -> V_83 , V_17 ) ;
if ( F_18 ( V_117 ) ) {
V_154 -> V_83 -> V_90 -- ;
F_92 ( & V_154 -> V_83 -> V_87 ) ;
F_30 () ;
} else {
V_15 = F_19 ( V_117 ) ;
F_158 ( V_15 ) ;
F_40 ( F_160 ( V_15 ) < 0 ) ;
F_100 ( V_154 -> V_83 , V_89 , - V_31 ) ;
F_40 ( ! F_119 ( V_15 ) ) ;
V_154 -> V_83 -> V_90 -- ;
F_92 ( & V_154 -> V_83 -> V_87 ) ;
F_190 ( V_154 , V_15 ) ;
}
F_95 ( V_154 -> V_83 , V_85 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_191 ( struct V_76 * V_77 , T_1 * V_17 ,
unsigned long V_111 , unsigned long V_155 ,
unsigned char * V_156 )
{
int V_45 = 0 ;
if ( F_187 ( V_17 , V_77 ) == 1 ) {
F_92 ( & V_77 -> V_135 -> V_87 ) ;
memset ( V_156 , 1 , ( V_155 - V_111 ) >> V_6 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_192 ( struct V_76 * V_77 , struct V_76 * V_157 ,
unsigned long V_158 ,
unsigned long V_159 , unsigned long V_160 ,
T_1 * V_161 , T_1 * V_162 )
{
int V_45 = 0 ;
T_1 V_17 ;
struct V_82 * V_83 = V_77 -> V_135 ;
if ( ( V_158 & ~ V_97 ) ||
( V_159 & ~ V_97 ) ||
V_160 - V_158 < V_99 ||
( V_157 -> V_78 & V_163 ) )
goto V_71;
if ( F_193 ( ! F_91 ( * V_162 ) ) ) {
F_40 ( F_116 ( * V_162 ) ) ;
goto V_71;
}
V_45 = F_187 ( V_161 , V_77 ) ;
if ( V_45 == 1 ) {
V_17 = F_188 ( V_83 , V_158 , V_161 ) ;
F_40 ( ! F_91 ( * V_162 ) ) ;
F_99 ( V_83 , V_159 , V_162 , F_194 ( V_17 ) ) ;
F_92 ( & V_83 -> V_87 ) ;
}
V_71:
return V_45 ;
}
int F_195 ( struct V_76 * V_77 , T_1 * V_17 ,
unsigned long V_111 , T_5 V_164 , int V_165 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
int V_45 = 0 ;
if ( F_187 ( V_17 , V_77 ) == 1 ) {
T_1 V_81 ;
V_81 = F_188 ( V_83 , V_111 , V_17 ) ;
if ( ! V_165 ) {
V_81 = F_196 ( V_81 , V_164 ) ;
F_31 ( F_167 ( V_81 ) ) ;
} else {
struct V_15 * V_15 = F_19 ( * V_17 ) ;
if ( F_160 ( V_15 ) == 1 &&
! F_183 ( * V_17 ) ) {
V_81 = F_197 ( V_81 ) ;
}
}
F_99 ( V_83 , V_111 , V_17 , V_81 ) ;
F_92 ( & V_77 -> V_135 -> V_87 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_187 ( T_1 * V_17 , struct V_76 * V_77 )
{
F_90 ( & V_77 -> V_135 -> V_87 ) ;
if ( F_21 ( F_116 ( * V_17 ) ) ) {
if ( F_9 ( F_117 ( * V_17 ) ) ) {
F_92 ( & V_77 -> V_135 -> V_87 ) ;
F_118 ( V_77 -> V_116 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_92 ( & V_77 -> V_135 -> V_87 ) ;
return 0 ;
}
T_1 * F_198 ( struct V_15 * V_15 ,
struct V_82 * V_83 ,
unsigned long V_95 ,
enum V_166 V_47 )
{
T_1 * V_17 , * V_45 = NULL ;
if ( V_95 & ~ V_97 )
goto V_71;
V_17 = F_199 ( V_83 , V_95 ) ;
if ( ! V_17 )
goto V_71;
if ( F_91 ( * V_17 ) )
goto V_71;
if ( F_19 ( * V_17 ) != V_15 )
goto V_71;
if ( V_47 == V_167 &&
F_117 ( * V_17 ) )
goto V_71;
if ( F_116 ( * V_17 ) ) {
F_40 ( V_47 == V_168 &&
! F_117 ( * V_17 ) ) ;
V_45 = V_17 ;
}
V_71:
return V_45 ;
}
static int F_200 ( struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
T_1 * V_17 ;
int V_45 = 0 ;
const unsigned long V_122 = V_95 ;
const unsigned long V_123 = V_95 + V_99 ;
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
V_17 = F_198 ( V_15 , V_83 , V_95 ,
V_167 ) ;
if ( V_17 ) {
F_201 ( V_77 , V_95 , V_17 ) ;
V_45 = 1 ;
}
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
return V_45 ;
}
static void F_202 ( struct V_15 * V_15 ,
struct V_169 * V_170 )
{
int V_121 ;
struct V_1 * V_1 = F_203 ( V_15 ) ;
struct V_171 * V_171 ;
int V_172 = 0 ;
F_204 ( & V_1 -> V_173 ) ;
V_171 = F_205 ( V_15 , V_1 ) ;
F_206 ( V_15 ) ;
F_207 ( V_15 ) ;
for ( V_121 = V_31 - 1 ; V_121 >= 1 ; V_121 -- ) {
struct V_15 * V_174 = V_15 + V_121 ;
F_31 ( F_160 ( V_174 ) < 0 ) ;
V_172 += F_160 ( V_174 ) ;
F_31 ( V_172 < 0 ) ;
F_31 ( F_34 ( & V_174 -> V_175 ) != 0 ) ;
F_208 ( F_160 ( V_15 ) + F_160 ( V_174 ) + 1 ,
& V_174 -> V_175 ) ;
F_209 () ;
V_174 -> V_96 &= ~ V_176 | V_177 ;
V_174 -> V_96 |= ( V_15 -> V_96 &
( ( 1L << V_178 ) |
( 1L << V_179 ) |
( 1L << V_180 ) |
( 1L << V_181 ) |
( 1L << V_182 ) |
( 1L << V_183 ) ) ) ;
V_174 -> V_96 |= ( 1L << V_184 ) ;
F_146 () ;
V_174 -> V_185 = V_15 -> V_185 ;
F_31 ( V_174 -> V_142 ) ;
V_174 -> V_142 = V_15 -> V_142 ;
V_174 -> V_186 = V_15 -> V_186 + V_121 ;
F_210 ( V_174 , F_211 ( V_15 ) ) ;
F_31 ( ! F_212 ( V_174 ) ) ;
F_31 ( ! F_213 ( V_174 ) ) ;
F_31 ( ! F_214 ( V_174 ) ) ;
F_31 ( ! F_215 ( V_174 ) ) ;
F_216 ( V_15 , V_174 , V_171 , V_170 ) ;
}
F_217 ( V_172 , & V_15 -> V_175 ) ;
F_31 ( F_34 ( & V_15 -> V_175 ) <= 0 ) ;
F_218 ( V_1 , V_187 , - 1 ) ;
F_219 ( V_15 ) ;
F_220 ( V_15 ) ;
F_221 ( & V_1 -> V_173 ) ;
for ( V_121 = 1 ; V_121 < V_31 ; V_121 ++ ) {
struct V_15 * V_174 = V_15 + V_121 ;
F_31 ( F_222 ( V_174 ) <= 0 ) ;
F_94 ( V_174 ) ;
}
F_31 ( F_222 ( V_15 ) <= 0 ) ;
}
static int F_223 ( struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
T_1 * V_17 , V_120 ;
int V_45 = 0 , V_121 ;
T_6 V_85 ;
unsigned long V_84 ;
F_90 ( & V_83 -> V_87 ) ;
V_17 = F_198 ( V_15 , V_83 , V_95 ,
V_168 ) ;
if ( V_17 ) {
V_85 = F_134 ( V_83 , V_17 ) ;
F_135 ( V_83 , & V_120 , V_85 ) ;
V_84 = V_95 ;
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ , V_84 += V_126 ) {
T_8 * V_127 , V_81 ;
F_31 ( F_86 ( V_15 + V_121 ) ) ;
V_81 = F_136 ( V_15 + V_121 , V_77 -> V_88 ) ;
V_81 = F_137 ( F_138 ( V_81 ) , V_77 ) ;
if ( ! F_167 ( * V_17 ) )
V_81 = F_224 ( V_81 ) ;
else
F_31 ( F_160 ( V_15 ) != 1 ) ;
if ( ! F_225 ( * V_17 ) )
V_81 = F_226 ( V_81 ) ;
if ( F_183 ( * V_17 ) )
V_81 = F_227 ( V_81 ) ;
V_127 = F_142 ( & V_120 , V_84 ) ;
F_31 ( ! F_143 ( * V_127 ) ) ;
F_144 ( V_83 , V_84 , V_127 , V_81 ) ;
F_145 ( V_127 ) ;
}
F_146 () ;
F_228 ( V_77 , V_95 , V_17 ) ;
F_135 ( V_83 , V_17 , V_85 ) ;
V_45 = 1 ;
}
F_92 ( & V_83 -> V_87 ) ;
return V_45 ;
}
static void F_229 ( struct V_15 * V_15 ,
struct V_116 * V_116 ,
struct V_169 * V_170 )
{
int V_188 , V_189 ;
T_9 V_190 = V_15 -> V_186 << ( V_191 - V_6 ) ;
struct V_192 * V_193 ;
F_31 ( ! F_119 ( V_15 ) ) ;
F_31 ( F_230 ( V_15 ) ) ;
V_188 = 0 ;
F_231 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_76 * V_77 = V_193 -> V_77 ;
unsigned long V_111 = F_232 ( V_15 , V_77 ) ;
F_31 ( F_233 ( V_77 ) ) ;
V_188 += F_200 ( V_15 , V_77 , V_111 ) ;
}
if ( V_188 != F_160 ( V_15 ) )
F_11 ( V_11 L_15 ,
V_188 , F_160 ( V_15 ) ) ;
F_31 ( V_188 != F_160 ( V_15 ) ) ;
F_202 ( V_15 , V_170 ) ;
V_189 = 0 ;
F_231 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_76 * V_77 = V_193 -> V_77 ;
unsigned long V_111 = F_232 ( V_15 , V_77 ) ;
F_31 ( F_233 ( V_77 ) ) ;
V_189 += F_223 ( V_15 , V_77 , V_111 ) ;
}
if ( V_188 != V_189 )
F_11 ( V_11 L_16 ,
V_188 , V_189 , F_160 ( V_15 ) ) ;
F_31 ( V_188 != V_189 ) ;
}
int F_234 ( struct V_15 * V_15 , struct V_169 * V_170 )
{
struct V_116 * V_116 ;
int V_45 = 1 ;
F_31 ( F_16 ( V_15 ) ) ;
F_31 ( ! F_212 ( V_15 ) ) ;
V_116 = F_235 ( V_15 ) ;
if ( ! V_116 )
goto V_71;
F_236 ( V_116 ) ;
V_45 = 0 ;
if ( ! F_86 ( V_15 ) )
goto V_115;
F_31 ( ! F_215 ( V_15 ) ) ;
F_229 ( V_15 , V_116 , V_170 ) ;
F_24 ( V_194 ) ;
F_31 ( F_86 ( V_15 ) ) ;
V_115:
F_237 ( V_116 ) ;
F_238 ( V_116 ) ;
V_71:
return V_45 ;
}
int F_239 ( struct V_76 * V_77 ,
unsigned long * V_78 , int V_195 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
switch ( V_195 ) {
case V_196 :
if ( * V_78 & ( V_197 | V_198 ) )
return - V_42 ;
if ( V_83 -> V_199 & V_163 )
return - V_42 ;
* V_78 &= ~ V_163 ;
* V_78 |= V_197 ;
if ( F_9 ( F_240 ( V_77 ) ) )
return - V_66 ;
break;
case V_200 :
if ( * V_78 & ( V_163 | V_198 ) )
return - V_42 ;
* V_78 &= ~ V_197 ;
* V_78 |= V_163 ;
break;
}
return 0 ;
}
static int T_4 F_77 ( void )
{
V_201 = F_241 ( L_17 ,
sizeof( struct V_202 ) ,
F_242 ( struct V_202 ) , 0 , NULL ) ;
if ( ! V_201 )
return - V_66 ;
return 0 ;
}
static inline struct V_202 * F_243 ( void )
{
if ( ! V_201 )
return NULL ;
return F_244 ( V_201 , V_105 ) ;
}
static inline void F_245 ( struct V_202 * V_202 )
{
F_246 ( V_201 , V_202 ) ;
}
static struct V_202 * F_247 ( struct V_82 * V_83 )
{
struct V_202 * V_202 ;
F_248 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_83 == V_202 -> V_83 )
return V_202 ;
return NULL ;
}
static void F_249 ( struct V_82 * V_83 ,
struct V_202 * V_202 )
{
V_202 -> V_83 = V_83 ;
F_250 ( V_203 , & V_202 -> V_204 , ( long ) V_83 ) ;
}
static inline int F_251 ( struct V_82 * V_83 )
{
return F_34 ( & V_83 -> V_205 ) == 0 ;
}
int F_252 ( struct V_82 * V_83 )
{
struct V_202 * V_202 ;
int V_206 ;
V_202 = F_243 () ;
if ( ! V_202 )
return - V_66 ;
F_40 ( F_251 ( V_83 ) ) ;
if ( F_9 ( F_253 ( V_207 , & V_83 -> V_96 ) ) ) {
F_245 ( V_202 ) ;
return 0 ;
}
F_90 ( & V_208 ) ;
F_249 ( V_83 , V_202 ) ;
V_206 = F_13 ( & V_12 . V_13 ) ;
F_254 ( & V_202 -> V_209 , & V_12 . V_13 ) ;
F_92 ( & V_208 ) ;
F_255 ( & V_83 -> V_210 ) ;
if ( V_206 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_240 ( struct V_76 * V_77 )
{
unsigned long V_211 , V_212 ;
if ( ! V_77 -> V_116 )
return 0 ;
if ( V_77 -> V_213 )
return 0 ;
F_40 ( V_77 -> V_78 & V_198 ) ;
V_211 = ( V_77 -> V_98 + ~ V_97 ) & V_97 ;
V_212 = V_77 -> V_100 & V_97 ;
if ( V_211 < V_212 )
return F_109 ( V_77 ) ;
return 0 ;
}
void F_256 ( struct V_82 * V_83 )
{
struct V_202 * V_202 ;
int free = 0 ;
F_90 ( & V_208 ) ;
V_202 = F_247 ( V_83 ) ;
if ( V_202 && V_12 . V_202 != V_202 ) {
F_257 ( & V_202 -> V_204 ) ;
F_258 ( & V_202 -> V_209 ) ;
free = 1 ;
}
F_92 ( & V_208 ) ;
if ( free ) {
F_43 ( V_207 , & V_83 -> V_96 ) ;
F_245 ( V_202 ) ;
F_259 ( V_83 ) ;
} else if ( V_202 ) {
F_260 ( & V_83 -> V_214 ) ;
F_261 ( & V_83 -> V_214 ) ;
}
}
static void F_262 ( struct V_15 * V_15 )
{
F_263 ( V_15 , V_215 + 0 ) ;
F_172 ( V_15 ) ;
F_264 ( V_15 ) ;
}
static void F_265 ( T_8 * V_127 , T_8 * V_216 )
{
while ( -- V_216 >= V_127 ) {
T_8 V_217 = * V_216 ;
if ( ! F_143 ( V_217 ) )
F_262 ( F_266 ( V_217 ) ) ;
}
}
static int F_267 ( struct V_76 * V_77 ,
unsigned long V_95 ,
T_8 * V_127 )
{
struct V_15 * V_15 ;
T_8 * V_216 ;
int V_218 = 0 , V_219 = 0 ;
for ( V_216 = V_127 ; V_216 < V_127 + V_31 ;
V_216 ++ , V_95 += V_126 ) {
T_8 V_217 = * V_216 ;
if ( F_143 ( V_217 ) ) {
if ( ++ V_219 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_268 ( V_217 ) || ! F_269 ( V_217 ) )
goto V_71;
V_15 = F_270 ( V_77 , V_95 , V_217 ) ;
if ( F_9 ( ! V_15 ) )
goto V_71;
F_40 ( F_86 ( V_15 ) ) ;
F_31 ( ! F_212 ( V_15 ) ) ;
F_40 ( ! F_215 ( V_15 ) ) ;
if ( F_222 ( V_15 ) != 1 )
goto V_71;
if ( ! F_169 ( V_15 ) )
goto V_71;
if ( F_271 ( V_15 ) ) {
F_172 ( V_15 ) ;
goto V_71;
}
F_272 ( V_15 , V_215 + 0 ) ;
F_40 ( ! F_181 ( V_15 ) ) ;
F_40 ( F_273 ( V_15 ) ) ;
if ( F_274 ( V_217 ) || F_275 ( V_15 ) ||
F_276 ( V_77 -> V_135 , V_95 ) )
V_218 = 1 ;
}
if ( F_21 ( V_218 ) )
return 1 ;
V_71:
F_265 ( V_127 , V_216 ) ;
return 0 ;
}
static void F_277 ( T_8 * V_127 , struct V_15 * V_15 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
T_10 * V_220 )
{
T_8 * V_216 ;
for ( V_216 = V_127 ; V_216 < V_127 + V_31 ; V_216 ++ ) {
T_8 V_217 = * V_216 ;
struct V_15 * V_112 ;
if ( F_143 ( V_217 ) ) {
F_131 ( V_15 , V_95 ) ;
F_100 ( V_77 -> V_135 , V_89 , 1 ) ;
} else {
V_112 = F_266 ( V_217 ) ;
F_156 ( V_15 , V_112 , V_95 , V_77 ) ;
F_40 ( F_160 ( V_112 ) != 1 ) ;
F_262 ( V_112 ) ;
F_90 ( V_220 ) ;
F_278 ( V_77 -> V_135 , V_95 , V_216 ) ;
F_158 ( V_112 ) ;
F_92 ( V_220 ) ;
F_279 ( V_112 ) ;
}
V_95 += V_126 ;
V_15 ++ ;
}
}
static void F_280 ( void )
{
F_281 ( V_14 , false ,
F_282 ( V_56 ) ) ;
}
static bool F_283 ( struct V_15 * * V_221 , bool * V_222 )
{
if ( F_10 ( * V_221 ) ) {
if ( ! * V_222 )
return false ;
* V_222 = false ;
* V_221 = NULL ;
F_280 () ;
} else if ( * V_221 ) {
F_94 ( * V_221 ) ;
* V_221 = NULL ;
}
return true ;
}
static struct V_15
* F_284 ( struct V_15 * * V_221 , struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
int V_223 )
{
F_40 ( * V_221 ) ;
* V_221 = F_102 ( F_285 () , V_77 , V_95 ,
V_223 , V_130 ) ;
F_286 ( & V_83 -> V_214 ) ;
if ( F_9 ( ! * V_221 ) ) {
F_24 ( V_224 ) ;
* V_221 = F_168 ( - V_66 ) ;
return NULL ;
}
F_24 ( V_225 ) ;
return * V_221 ;
}
static struct V_15 * F_287 ( bool * V_222 )
{
struct V_15 * V_221 ;
do {
V_221 = F_104 ( F_285 () ) ;
if ( ! V_221 ) {
F_24 ( V_224 ) ;
if ( ! * V_222 )
return NULL ;
* V_222 = false ;
F_280 () ;
} else
F_24 ( V_225 ) ;
} while ( F_9 ( ! V_221 ) && F_21 ( F_2 () ) );
return V_221 ;
}
static bool F_283 ( struct V_15 * * V_221 , bool * V_222 )
{
if ( ! * V_221 )
* V_221 = F_287 ( V_222 ) ;
if ( F_9 ( ! * V_221 ) )
return false ;
return true ;
}
static struct V_15
* F_284 ( struct V_15 * * V_221 , struct V_82 * V_83 ,
struct V_76 * V_77 , unsigned long V_95 ,
int V_223 )
{
F_286 ( & V_83 -> V_214 ) ;
F_40 ( ! * V_221 ) ;
return * V_221 ;
}
static bool F_288 ( struct V_76 * V_77 )
{
if ( ( ! ( V_77 -> V_78 & V_197 ) && ! F_289 () ) ||
( V_77 -> V_78 & V_163 ) )
return false ;
if ( ! V_77 -> V_116 || V_77 -> V_213 )
return false ;
if ( F_233 ( V_77 ) )
return false ;
F_40 ( V_77 -> V_78 & V_198 ) ;
return true ;
}
static void F_290 ( struct V_82 * V_83 ,
unsigned long V_95 ,
struct V_15 * * V_221 ,
struct V_76 * V_77 ,
int V_223 )
{
T_1 * V_17 , V_120 ;
T_8 * V_127 ;
T_6 V_85 ;
struct V_15 * V_132 ;
T_10 * V_220 ;
int V_226 ;
unsigned long V_211 , V_212 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_40 ( V_95 & ~ V_97 ) ;
V_132 = F_284 ( V_221 , V_83 , V_77 , V_95 , V_223 ) ;
if ( ! V_132 )
return;
if ( F_9 ( F_113 ( V_132 , V_83 , V_105 ) ) )
return;
F_260 ( & V_83 -> V_214 ) ;
if ( F_9 ( F_251 ( V_83 ) ) )
goto V_71;
V_77 = F_291 ( V_83 , V_95 ) ;
if ( ! V_77 )
goto V_71;
V_211 = ( V_77 -> V_98 + ~ V_97 ) & V_97 ;
V_212 = V_77 -> V_100 & V_97 ;
if ( V_95 < V_211 || V_95 + V_99 > V_212 )
goto V_71;
if ( ! F_288 ( V_77 ) )
goto V_71;
V_17 = F_199 ( V_83 , V_95 ) ;
if ( ! V_17 )
goto V_71;
if ( F_116 ( * V_17 ) )
goto V_71;
F_236 ( V_77 -> V_116 ) ;
V_127 = F_142 ( V_17 , V_95 ) ;
V_220 = F_292 ( V_83 , V_17 ) ;
V_122 = V_95 ;
V_123 = V_95 + V_99 ;
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
V_120 = F_133 ( V_77 , V_95 , V_17 ) ;
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
F_90 ( V_220 ) ;
V_226 = F_267 ( V_77 , V_95 , V_127 ) ;
F_92 ( V_220 ) ;
if ( F_9 ( ! V_226 ) ) {
F_145 ( V_127 ) ;
F_90 ( & V_83 -> V_87 ) ;
F_31 ( ! F_91 ( * V_17 ) ) ;
F_135 ( V_83 , V_17 , F_293 ( V_120 ) ) ;
F_92 ( & V_83 -> V_87 ) ;
F_237 ( V_77 -> V_116 ) ;
goto V_71;
}
F_237 ( V_77 -> V_116 ) ;
F_277 ( V_127 , V_132 , V_77 , V_95 , V_220 ) ;
F_145 ( V_127 ) ;
F_89 ( V_132 ) ;
V_85 = F_293 ( V_120 ) ;
V_120 = F_82 ( V_132 , V_77 -> V_88 ) ;
V_120 = F_80 ( F_96 ( V_120 ) , V_77 ) ;
F_146 () ;
F_90 ( & V_83 -> V_87 ) ;
F_31 ( ! F_91 ( * V_17 ) ) ;
F_97 ( V_132 , V_77 , V_95 ) ;
F_98 ( V_83 , V_17 , V_85 ) ;
F_99 ( V_83 , V_95 , V_17 , V_120 ) ;
F_128 ( V_77 , V_95 , V_17 ) ;
F_92 ( & V_83 -> V_87 ) ;
* V_221 = NULL ;
V_59 ++ ;
V_227:
F_261 ( & V_83 -> V_214 ) ;
return;
V_71:
F_93 ( V_132 ) ;
goto V_227;
}
static int F_294 ( struct V_82 * V_83 ,
struct V_76 * V_77 ,
unsigned long V_95 ,
struct V_15 * * V_221 )
{
T_1 * V_17 ;
T_8 * V_127 , * V_216 ;
int V_45 = 0 , V_218 = 0 , V_219 = 0 ;
struct V_15 * V_15 ;
unsigned long V_228 ;
T_10 * V_220 ;
int V_223 = V_229 ;
F_40 ( V_95 & ~ V_97 ) ;
V_17 = F_199 ( V_83 , V_95 ) ;
if ( ! V_17 )
goto V_71;
if ( F_116 ( * V_17 ) )
goto V_71;
V_127 = F_295 ( V_83 , V_17 , V_95 , & V_220 ) ;
for ( V_228 = V_95 , V_216 = V_127 ; V_216 < V_127 + V_31 ;
V_216 ++ , V_228 += V_126 ) {
T_8 V_217 = * V_216 ;
if ( F_143 ( V_217 ) ) {
if ( ++ V_219 <= V_62 )
continue;
else
goto V_230;
}
if ( ! F_268 ( V_217 ) || ! F_269 ( V_217 ) )
goto V_230;
V_15 = F_270 ( V_77 , V_228 , V_217 ) ;
if ( F_9 ( ! V_15 ) )
goto V_230;
if ( V_223 == V_229 )
V_223 = F_152 ( V_15 ) ;
F_40 ( F_86 ( V_15 ) ) ;
if ( ! F_273 ( V_15 ) || F_181 ( V_15 ) || ! F_212 ( V_15 ) )
goto V_230;
if ( F_222 ( V_15 ) != 1 )
goto V_230;
if ( F_274 ( V_217 ) || F_275 ( V_15 ) ||
F_276 ( V_77 -> V_135 , V_95 ) )
V_218 = 1 ;
}
if ( V_218 )
V_45 = 1 ;
V_230:
F_296 ( V_127 , V_220 ) ;
if ( V_45 )
F_290 ( V_83 , V_95 , V_221 , V_77 , V_223 ) ;
V_71:
return V_45 ;
}
static void F_297 ( struct V_202 * V_202 )
{
struct V_82 * V_83 = V_202 -> V_83 ;
F_40 ( V_231 != 1 && ! F_298 ( & V_208 ) ) ;
if ( F_251 ( V_83 ) ) {
F_257 ( & V_202 -> V_204 ) ;
F_258 ( & V_202 -> V_209 ) ;
F_245 ( V_202 ) ;
F_259 ( V_83 ) ;
}
}
static unsigned int F_299 ( unsigned int V_58 ,
struct V_15 * * V_221 )
__releases( &khugepaged_mm_lock
static int F_300 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_301 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_302 () ;
}
static void F_303 ( void )
{
struct V_15 * V_221 = NULL ;
unsigned int V_232 = 0 , V_233 = 0 ;
unsigned int V_58 = V_57 ;
bool V_222 = true ;
F_304 () ;
while ( V_232 < V_58 ) {
if ( ! F_283 ( & V_221 , & V_222 ) )
break;
F_157 () ;
if ( F_9 ( F_302 () || F_305 ( V_234 ) ) )
break;
F_90 ( & V_208 ) ;
if ( ! V_12 . V_202 )
V_233 ++ ;
if ( F_300 () &&
V_233 < 2 )
V_232 += F_299 ( V_58 - V_232 ,
& V_221 ) ;
else
V_232 = V_58 ;
F_92 ( & V_208 ) ;
}
if ( ! F_306 ( V_221 ) )
F_94 ( V_221 ) ;
}
static void F_307 ( void )
{
F_308 () ;
if ( F_300 () ) {
if ( ! V_53 )
return;
F_281 ( V_14 ,
F_302 () ,
F_282 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_309 ( V_14 , F_301 () ) ;
}
static int V_10 ( void * V_219 )
{
struct V_202 * V_202 ;
F_310 () ;
F_311 ( V_234 , 19 ) ;
while ( ! F_302 () ) {
F_303 () ;
F_307 () ;
}
F_90 ( & V_208 ) ;
V_202 = V_12 . V_202 ;
V_12 . V_202 = NULL ;
if ( V_202 )
F_297 ( V_202 ) ;
F_92 ( & V_208 ) ;
return 0 ;
}
static void F_312 ( struct V_76 * V_77 ,
unsigned long V_84 , T_1 * V_17 )
{
struct V_82 * V_83 = V_77 -> V_135 ;
T_6 V_85 ;
T_1 V_120 ;
int V_121 ;
F_133 ( V_77 , V_84 , V_17 ) ;
V_85 = F_134 ( V_83 , V_17 ) ;
F_135 ( V_83 , & V_120 , V_85 ) ;
for ( V_121 = 0 ; V_121 < V_31 ; V_121 ++ , V_84 += V_126 ) {
T_8 * V_127 , V_81 ;
V_81 = F_139 ( F_140 ( V_84 ) , V_77 -> V_88 ) ;
V_81 = F_141 ( V_81 ) ;
V_127 = F_142 ( & V_120 , V_84 ) ;
F_40 ( ! F_143 ( * V_127 ) ) ;
F_144 ( V_83 , V_84 , V_127 , V_81 ) ;
F_145 ( V_127 ) ;
}
F_146 () ;
F_135 ( V_83 , V_17 , V_85 ) ;
F_30 () ;
}
void F_313 ( struct V_76 * V_77 , unsigned long V_95 ,
T_1 * V_17 )
{
struct V_15 * V_15 ;
struct V_82 * V_83 = V_77 -> V_135 ;
unsigned long V_84 = V_95 & V_97 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_31 ( V_77 -> V_98 > V_84 || V_77 -> V_100 < V_84 + V_99 ) ;
V_122 = V_84 ;
V_123 = V_84 + V_99 ;
V_235:
F_132 ( V_83 , V_122 , V_123 ) ;
F_90 ( & V_83 -> V_87 ) ;
if ( F_9 ( ! F_116 ( * V_17 ) ) ) {
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
return;
}
if ( F_18 ( * V_17 ) ) {
F_312 ( V_77 , V_84 , V_17 ) ;
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
return;
}
V_15 = F_19 ( * V_17 ) ;
F_40 ( ! F_222 ( V_15 ) ) ;
F_120 ( V_15 ) ;
F_92 ( & V_83 -> V_87 ) ;
F_148 ( V_83 , V_122 , V_123 ) ;
F_163 ( V_15 ) ;
F_94 ( V_15 ) ;
if ( F_9 ( F_116 ( * V_17 ) ) )
goto V_235;
}
void F_314 ( struct V_82 * V_83 , unsigned long V_95 ,
T_1 * V_17 )
{
struct V_76 * V_77 ;
V_77 = F_291 ( V_83 , V_95 ) ;
F_31 ( V_77 == NULL ) ;
F_315 ( V_77 , V_95 , V_17 ) ;
}
static void F_316 ( struct V_82 * V_83 ,
unsigned long V_95 )
{
T_1 * V_17 ;
F_40 ( ! ( V_95 & ~ V_97 ) ) ;
V_17 = F_199 ( V_83 , V_95 ) ;
if ( ! V_17 )
return;
F_314 ( V_83 , V_95 , V_17 ) ;
}
void F_317 ( struct V_76 * V_77 ,
unsigned long V_236 ,
unsigned long V_155 ,
long V_237 )
{
if ( V_236 & ~ V_97 &&
( V_236 & V_97 ) >= V_77 -> V_98 &&
( V_236 & V_97 ) + V_99 <= V_77 -> V_100 )
F_316 ( V_77 -> V_135 , V_236 ) ;
if ( V_155 & ~ V_97 &&
( V_155 & V_97 ) >= V_77 -> V_98 &&
( V_155 & V_97 ) + V_99 <= V_77 -> V_100 )
F_316 ( V_77 -> V_135 , V_155 ) ;
if ( V_237 > 0 ) {
struct V_76 * V_238 = V_77 -> V_239 ;
unsigned long V_240 = V_238 -> V_98 ;
V_240 += V_237 << V_6 ;
if ( V_240 & ~ V_97 &&
( V_240 & V_97 ) >= V_238 -> V_98 &&
( V_240 & V_97 ) + V_99 <= V_238 -> V_100 )
F_316 ( V_238 -> V_135 , V_240 ) ;
}
}
