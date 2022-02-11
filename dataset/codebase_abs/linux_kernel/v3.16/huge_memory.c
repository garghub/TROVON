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
F_12 ( L_4 ) ;
V_9 = F_13 ( V_10 ) ;
V_10 = NULL ;
}
if ( ! F_14 ( & V_12 . V_13 ) )
F_15 ( & V_14 ) ;
F_1 () ;
} else if ( V_10 ) {
F_16 ( V_10 ) ;
V_10 = NULL ;
}
return V_9 ;
}
static inline bool F_17 ( struct V_15 * V_15 )
{
return F_18 ( V_16 ) == V_15 ;
}
static inline bool F_19 ( T_1 V_17 )
{
return F_17 ( F_20 ( V_17 ) ) ;
}
static struct V_15 * F_21 ( void )
{
struct V_15 * V_18 ;
V_19:
if ( F_22 ( F_23 ( & V_20 ) ) )
return F_18 ( V_16 ) ;
V_18 = F_24 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_18 ) {
F_25 ( V_25 ) ;
return NULL ;
}
F_25 ( V_26 ) ;
F_26 () ;
if ( F_27 ( & V_16 , NULL , V_18 ) ) {
F_28 () ;
F_29 ( V_18 ) ;
goto V_19;
}
F_30 ( & V_20 , 2 ) ;
F_28 () ;
return F_18 ( V_16 ) ;
}
static void F_31 ( void )
{
F_32 ( F_33 ( & V_20 ) ) ;
}
static unsigned long F_34 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_35 ( & V_20 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_36 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_37 ( & V_20 , 1 , 0 ) == 1 ) {
struct V_15 * V_18 = F_38 ( & V_16 , NULL ) ;
F_32 ( V_18 == NULL ) ;
F_29 ( V_18 ) ;
return V_31 ;
}
return 0 ;
}
static T_2 F_39 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( F_40 ( V_38 , & V_40 ) ) {
F_41 ( F_40 ( V_39 , & V_40 ) ) ;
return sprintf ( V_36 , L_5 ) ;
} else if ( F_40 ( V_39 , & V_40 ) )
return sprintf ( V_36 , L_6 ) ;
else
return sprintf ( V_36 , L_7 ) ;
}
static T_2 F_42 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( ! memcmp ( L_8 , V_36 ,
F_4 ( sizeof( L_8 ) - 1 , V_41 ) ) ) {
F_43 ( V_38 , & V_40 ) ;
F_44 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_9 , V_36 ,
F_4 ( sizeof( L_9 ) - 1 , V_41 ) ) ) {
F_44 ( V_38 , & V_40 ) ;
F_43 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_10 , V_36 ,
F_4 ( sizeof( L_10 ) - 1 , V_41 ) ) ) {
F_44 ( V_38 , & V_40 ) ;
F_44 ( V_39 , & V_40 ) ;
} else
return - V_42 ;
return V_41 ;
}
static T_2 F_45 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_39 ( V_33 , V_35 , V_36 ,
V_43 ,
V_44 ) ;
}
static T_2 F_46 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
T_2 V_45 ;
V_45 = F_42 ( V_33 , V_35 , V_36 , V_41 ,
V_43 ,
V_44 ) ;
if ( V_45 > 0 ) {
int V_9 ;
F_47 ( & V_46 ) ;
V_9 = F_8 () ;
F_48 ( & V_46 ) ;
if ( V_9 )
V_45 = V_9 ;
}
return V_45 ;
}
static T_2 F_49 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_47 )
{
return sprintf ( V_36 , L_11 ,
! ! F_40 ( V_47 , & V_40 ) ) ;
}
static T_2 F_50 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_47 )
{
unsigned long V_48 ;
int V_45 ;
V_45 = F_51 ( V_36 , 10 , & V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_48 > 1 )
return - V_42 ;
if ( V_48 )
F_43 ( V_47 , & V_40 ) ;
else
F_44 ( V_47 , & V_40 ) ;
return V_41 ;
}
static T_2 F_52 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_39 ( V_33 , V_35 , V_36 ,
V_49 ,
V_50 ) ;
}
static T_2 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_42 ( V_33 , V_35 , V_36 , V_41 ,
V_49 ,
V_50 ) ;
}
static T_2 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_49 ( V_33 , V_35 , V_36 ,
V_51 ) ;
}
static T_2 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_41 )
{
return F_50 ( V_33 , V_35 , V_36 , V_41 ,
V_51 ) ;
}
static T_2 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_49 ( V_33 , V_35 , V_36 ,
V_52 ) ;
}
static T_2 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_50 ( V_33 , V_35 , V_36 , V_41 ,
V_52 ) ;
}
static T_2 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_53 ) ;
}
static T_2 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_51 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_53 = V_54 ;
F_15 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_56 ) ;
}
static T_2 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_51 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_56 = V_54 ;
F_15 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_57 ) ;
}
static T_2 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_9 ;
unsigned long V_58 ;
V_9 = F_51 ( V_36 , 10 , & V_58 ) ;
if ( V_9 || ! V_58 || V_58 > V_55 )
return - V_42 ;
V_57 = V_58 ;
return V_41 ;
}
static T_2 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_59 ) ;
}
static T_2 F_65 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_60 ) ;
}
static T_2 F_66 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_49 ( V_33 , V_35 , V_36 ,
V_61 ) ;
}
static T_2 F_67 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_50 ( V_33 , V_35 , V_36 , V_41 ,
V_61 ) ;
}
static T_2 F_68 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_62 ) ;
}
static T_2 F_69 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_9 ;
unsigned long V_63 ;
V_9 = F_51 ( V_36 , 10 , & V_63 ) ;
if ( V_9 || V_63 > V_31 - 1 )
return - V_42 ;
V_62 = V_63 ;
return V_41 ;
}
static int T_4 F_70 ( struct V_32 * * V_64 )
{
int V_9 ;
* V_64 = F_71 ( L_13 , V_65 ) ;
if ( F_10 ( ! * V_64 ) ) {
F_12 ( L_14 ) ;
return - V_66 ;
}
V_9 = F_72 ( * V_64 , & V_67 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_68;
}
V_9 = F_72 ( * V_64 , & V_69 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_70;
}
return 0 ;
V_70:
F_73 ( * V_64 , & V_67 ) ;
V_68:
F_74 ( * V_64 ) ;
return V_9 ;
}
static void T_4 F_75 ( struct V_32 * V_64 )
{
F_73 ( V_64 , & V_69 ) ;
F_73 ( V_64 , & V_67 ) ;
F_74 ( V_64 ) ;
}
static inline int F_70 ( struct V_32 * * V_64 )
{
return 0 ;
}
static inline void F_75 ( struct V_32 * V_64 )
{
}
static int T_4 F_76 ( void )
{
int V_9 ;
struct V_32 * V_64 ;
if ( ! F_77 () ) {
V_40 = 0 ;
return - V_42 ;
}
V_9 = F_70 ( & V_64 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_78 () ;
if ( V_9 )
goto V_71;
F_79 ( & V_72 ) ;
if ( V_73 < ( 512 << ( 20 - V_6 ) ) )
V_40 = 0 ;
F_8 () ;
return 0 ;
V_71:
F_75 ( V_64 ) ;
return V_9 ;
}
static int T_4 F_80 ( char * V_74 )
{
int V_45 = 0 ;
if ( ! V_74 )
goto V_71;
if ( ! strcmp ( V_74 , L_8 ) ) {
F_43 ( V_43 ,
& V_40 ) ;
F_44 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_9 ) ) {
F_44 ( V_43 ,
& V_40 ) ;
F_43 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_10 ) ) {
F_44 ( V_43 ,
& V_40 ) ;
F_44 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
}
V_71:
if ( ! V_45 )
F_81 ( L_16 ) ;
return V_45 ;
}
T_1 F_82 ( T_1 V_17 , struct V_75 * V_76 )
{
if ( F_22 ( V_76 -> V_77 & V_78 ) )
V_17 = F_83 ( V_17 ) ;
return V_17 ;
}
static inline T_1 F_84 ( struct V_15 * V_15 , T_5 V_79 )
{
T_1 V_80 ;
V_80 = F_85 ( V_15 , V_79 ) ;
V_80 = F_86 ( V_80 ) ;
return V_80 ;
}
static int F_87 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_17 ,
struct V_15 * V_15 )
{
T_6 V_84 ;
T_7 * V_85 ;
F_88 ( ! F_89 ( V_15 ) , V_15 ) ;
V_84 = F_90 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_84 ) )
return V_86 ;
F_91 ( V_15 , V_83 , V_31 ) ;
F_92 ( V_15 ) ;
V_85 = F_93 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_94 ( * V_17 ) ) ) {
F_95 ( V_85 ) ;
F_96 ( V_15 ) ;
F_97 ( V_15 ) ;
F_98 ( V_82 , V_84 ) ;
} else {
T_1 V_80 ;
V_80 = F_84 ( V_15 , V_76 -> V_87 ) ;
V_80 = F_82 ( F_99 ( V_80 ) , V_76 ) ;
F_100 ( V_15 , V_76 , V_83 ) ;
F_101 ( V_82 , V_17 , V_84 ) ;
F_102 ( V_82 , V_83 , V_17 , V_80 ) ;
F_103 ( V_82 , V_88 , V_31 ) ;
F_104 ( & V_82 -> V_89 ) ;
F_95 ( V_85 ) ;
}
return 0 ;
}
static inline T_8 F_105 ( int V_90 , T_8 V_91 )
{
return ( V_21 & ~ ( V_90 ? 0 : V_92 ) ) | V_91 ;
}
static inline struct V_15 * F_106 ( int V_90 ,
struct V_75 * V_76 ,
unsigned long V_83 , int V_93 ,
T_8 V_91 )
{
return F_107 ( F_105 ( V_90 , V_91 ) ,
V_24 , V_76 , V_83 , V_93 ) ;
}
static bool F_108 ( T_6 V_84 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_83 , T_1 * V_17 ,
struct V_15 * V_18 )
{
T_1 V_80 ;
if ( ! F_94 ( * V_17 ) )
return false ;
V_80 = F_85 ( V_18 , V_76 -> V_87 ) ;
V_80 = F_109 ( V_80 ) ;
V_80 = F_86 ( V_80 ) ;
F_101 ( V_82 , V_17 , V_84 ) ;
F_102 ( V_82 , V_83 , V_17 , V_80 ) ;
F_104 ( & V_82 -> V_89 ) ;
return true ;
}
int F_110 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_94 , T_1 * V_17 ,
unsigned int V_95 )
{
struct V_15 * V_15 ;
unsigned long V_83 = V_94 & V_96 ;
if ( V_83 < V_76 -> V_97 || V_83 + V_98 > V_76 -> V_99 )
return V_100 ;
if ( F_10 ( F_111 ( V_76 ) ) )
return V_86 ;
if ( F_10 ( F_112 ( V_76 ) ) )
return V_86 ;
if ( ! ( V_95 & V_101 ) &&
F_113 () ) {
T_7 * V_85 ;
T_6 V_84 ;
struct V_15 * V_18 ;
bool V_102 ;
V_84 = F_90 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_84 ) )
return V_86 ;
V_18 = F_21 () ;
if ( F_10 ( ! V_18 ) ) {
F_98 ( V_82 , V_84 ) ;
F_25 ( V_103 ) ;
return V_100 ;
}
V_85 = F_93 ( V_82 , V_17 ) ;
V_102 = F_108 ( V_84 , V_82 , V_76 , V_83 , V_17 ,
V_18 ) ;
F_95 ( V_85 ) ;
if ( ! V_102 ) {
F_98 ( V_82 , V_84 ) ;
F_31 () ;
}
return 0 ;
}
V_15 = F_106 ( F_114 ( V_76 ) ,
V_76 , V_83 , F_115 () , 0 ) ;
if ( F_10 ( ! V_15 ) ) {
F_25 ( V_103 ) ;
return V_100 ;
}
if ( F_10 ( F_116 ( V_15 , V_82 , V_104 ) ) ) {
F_97 ( V_15 ) ;
F_25 ( V_103 ) ;
return V_100 ;
}
if ( F_10 ( F_87 ( V_82 , V_76 , V_83 , V_17 , V_15 ) ) ) {
F_96 ( V_15 ) ;
F_97 ( V_15 ) ;
F_25 ( V_103 ) ;
return V_100 ;
}
F_25 ( V_105 ) ;
return 0 ;
}
int F_117 ( struct V_81 * V_106 , struct V_81 * V_107 ,
T_1 * V_108 , T_1 * V_109 , unsigned long V_110 ,
struct V_75 * V_76 )
{
T_7 * V_111 , * V_112 ;
struct V_15 * V_113 ;
T_1 V_17 ;
T_6 V_84 ;
int V_45 ;
V_45 = - V_66 ;
V_84 = F_90 ( V_106 , V_110 ) ;
if ( F_10 ( ! V_84 ) )
goto V_71;
V_111 = F_93 ( V_106 , V_108 ) ;
V_112 = F_118 ( V_107 , V_109 ) ;
F_119 ( V_112 , V_114 ) ;
V_45 = - V_115 ;
V_17 = * V_109 ;
if ( F_10 ( ! F_120 ( V_17 ) ) ) {
F_98 ( V_106 , V_84 ) ;
goto V_116;
}
if ( F_19 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_102 ;
V_18 = F_21 () ;
V_102 = F_108 ( V_84 , V_106 , V_76 , V_110 , V_108 ,
V_18 ) ;
F_32 ( ! V_102 ) ;
V_45 = 0 ;
goto V_116;
}
if ( F_10 ( F_121 ( V_17 ) ) ) {
F_95 ( V_112 ) ;
F_95 ( V_111 ) ;
F_98 ( V_106 , V_84 ) ;
F_122 ( V_76 -> V_117 , V_109 ) ;
goto V_71;
}
V_113 = F_20 ( V_17 ) ;
F_88 ( ! F_123 ( V_113 ) , V_113 ) ;
F_124 ( V_113 ) ;
F_125 ( V_113 ) ;
F_103 ( V_106 , V_88 , V_31 ) ;
F_126 ( V_107 , V_110 , V_109 ) ;
V_17 = F_127 ( F_109 ( V_17 ) ) ;
F_101 ( V_106 , V_108 , V_84 ) ;
F_102 ( V_106 , V_110 , V_108 , V_17 ) ;
F_104 ( & V_106 -> V_89 ) ;
V_45 = 0 ;
V_116:
F_95 ( V_112 ) ;
F_95 ( V_111 ) ;
V_71:
return V_45 ;
}
void F_128 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_94 ,
T_1 * V_17 , T_1 V_118 ,
int V_119 )
{
T_7 * V_85 ;
T_1 V_80 ;
unsigned long V_83 ;
V_85 = F_93 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_129 ( * V_17 , V_118 ) ) )
goto V_120;
V_80 = F_130 ( V_118 ) ;
V_83 = V_94 & V_96 ;
if ( F_131 ( V_76 , V_83 , V_17 , V_80 , V_119 ) )
F_132 ( V_76 , V_94 , V_17 ) ;
V_120:
F_95 ( V_85 ) ;
}
static void F_133 ( struct V_15 * V_15 )
{
if ( F_134 ( V_121 ) ) {
struct V_15 * V_122 = V_15 + V_31 ;
F_135 ( V_31 , & V_15 -> V_123 ) ;
while ( ++ V_15 < V_122 )
F_136 ( V_15 ) ;
} else {
F_124 ( V_15 ) ;
}
}
static void F_137 ( struct V_15 * V_15 )
{
if ( F_134 ( V_121 ) ) {
struct V_15 * V_122 = V_15 + V_31 ;
while ( V_15 < V_122 )
F_97 ( V_15 ++ ) ;
} else {
F_97 ( V_15 ) ;
}
}
static int F_138 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_94 ,
T_1 * V_17 , T_1 V_118 ,
struct V_15 * V_15 ,
unsigned long V_83 )
{
T_7 * V_85 ;
T_6 V_84 ;
T_1 V_124 ;
int V_45 = 0 , V_125 ;
struct V_15 * * V_58 ;
unsigned long V_126 ;
unsigned long V_127 ;
V_58 = F_139 ( sizeof( struct V_15 * ) * V_31 ,
V_104 ) ;
if ( F_10 ( ! V_58 ) ) {
V_45 |= V_86 ;
goto V_71;
}
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ ) {
V_58 [ V_125 ] = F_140 ( V_128 |
V_129 ,
V_76 , V_94 , F_141 ( V_15 ) ) ;
if ( F_10 ( ! V_58 [ V_125 ] ||
F_116 ( V_58 [ V_125 ] , V_82 ,
V_104 ) ) ) {
if ( V_58 [ V_125 ] )
F_97 ( V_58 [ V_125 ] ) ;
F_142 () ;
while ( -- V_125 >= 0 ) {
F_96 ( V_58 [ V_125 ] ) ;
F_97 ( V_58 [ V_125 ] ) ;
}
F_143 () ;
F_144 ( V_58 ) ;
V_45 |= V_86 ;
goto V_71;
}
}
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ ) {
F_145 ( V_58 [ V_125 ] , V_15 + V_125 ,
V_83 + V_130 * V_125 , V_76 ) ;
F_92 ( V_58 [ V_125 ] ) ;
F_146 () ;
}
V_126 = V_83 ;
V_127 = V_83 + V_98 ;
F_147 ( V_82 , V_126 , V_127 ) ;
V_85 = F_93 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_129 ( * V_17 , V_118 ) ) )
goto V_131;
F_88 ( ! F_123 ( V_15 ) , V_15 ) ;
F_148 ( V_76 , V_83 , V_17 ) ;
V_84 = F_149 ( V_82 , V_17 ) ;
F_150 ( V_82 , & V_124 , V_84 ) ;
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ , V_83 += V_130 ) {
T_9 * V_132 , V_80 ;
V_80 = F_151 ( V_58 [ V_125 ] , V_76 -> V_87 ) ;
V_80 = F_152 ( F_153 ( V_80 ) , V_76 ) ;
F_100 ( V_58 [ V_125 ] , V_76 , V_83 ) ;
V_132 = F_154 ( & V_124 , V_83 ) ;
F_41 ( ! F_155 ( * V_132 ) ) ;
F_156 ( V_82 , V_83 , V_132 , V_80 ) ;
F_157 ( V_132 ) ;
}
F_144 ( V_58 ) ;
F_158 () ;
F_150 ( V_82 , V_17 , V_84 ) ;
F_159 ( V_15 ) ;
F_95 ( V_85 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
V_45 |= V_133 ;
F_97 ( V_15 ) ;
V_71:
return V_45 ;
V_131:
F_95 ( V_85 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
F_142 () ;
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ ) {
F_96 ( V_58 [ V_125 ] ) ;
F_97 ( V_58 [ V_125 ] ) ;
}
F_143 () ;
F_144 ( V_58 ) ;
goto V_71;
}
int F_161 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_94 , T_1 * V_17 , T_1 V_118 )
{
T_7 * V_85 ;
int V_45 = 0 ;
struct V_15 * V_15 = NULL , * V_134 ;
unsigned long V_83 ;
unsigned long V_126 ;
unsigned long V_127 ;
V_85 = F_118 ( V_82 , V_17 ) ;
F_41 ( ! V_76 -> V_117 ) ;
V_83 = V_94 & V_96 ;
if ( F_19 ( V_118 ) )
goto V_135;
F_162 ( V_85 ) ;
if ( F_10 ( ! F_129 ( * V_17 , V_118 ) ) )
goto V_116;
V_15 = F_20 ( V_118 ) ;
F_88 ( ! F_89 ( V_15 ) || ! F_123 ( V_15 ) , V_15 ) ;
if ( F_163 ( V_15 ) == 1 ) {
T_1 V_80 ;
V_80 = F_130 ( V_118 ) ;
V_80 = F_82 ( F_99 ( V_80 ) , V_76 ) ;
if ( F_131 ( V_76 , V_83 , V_17 , V_80 , 1 ) )
F_132 ( V_76 , V_94 , V_17 ) ;
V_45 |= V_133 ;
goto V_116;
}
F_133 ( V_15 ) ;
F_95 ( V_85 ) ;
V_135:
if ( F_164 ( V_76 ) &&
! F_165 () )
V_134 = F_106 ( F_114 ( V_76 ) ,
V_76 , V_83 , F_115 () , 0 ) ;
else
V_134 = NULL ;
if ( F_10 ( ! V_134 ) ) {
if ( ! V_15 ) {
F_166 ( V_76 , V_94 , V_17 ) ;
V_45 |= V_100 ;
} else {
V_45 = F_138 ( V_82 , V_76 , V_94 ,
V_17 , V_118 , V_15 , V_83 ) ;
if ( V_45 & V_86 ) {
F_167 ( V_15 ) ;
V_45 |= V_100 ;
}
F_137 ( V_15 ) ;
}
F_25 ( V_103 ) ;
goto V_71;
}
if ( F_10 ( F_116 ( V_134 , V_82 , V_104 ) ) ) {
F_97 ( V_134 ) ;
if ( V_15 ) {
F_167 ( V_15 ) ;
F_137 ( V_15 ) ;
} else
F_166 ( V_76 , V_94 , V_17 ) ;
V_45 |= V_100 ;
F_25 ( V_103 ) ;
goto V_71;
}
F_25 ( V_105 ) ;
if ( ! V_15 )
F_91 ( V_134 , V_83 , V_31 ) ;
else
F_168 ( V_134 , V_15 , V_83 , V_76 , V_31 ) ;
F_92 ( V_134 ) ;
V_126 = V_83 ;
V_127 = V_83 + V_98 ;
F_147 ( V_82 , V_126 , V_127 ) ;
F_162 ( V_85 ) ;
if ( V_15 )
F_137 ( V_15 ) ;
if ( F_10 ( ! F_129 ( * V_17 , V_118 ) ) ) {
F_95 ( V_85 ) ;
F_96 ( V_134 ) ;
F_97 ( V_134 ) ;
goto V_136;
} else {
T_1 V_80 ;
V_80 = F_84 ( V_134 , V_76 -> V_87 ) ;
V_80 = F_82 ( F_99 ( V_80 ) , V_76 ) ;
F_148 ( V_76 , V_83 , V_17 ) ;
F_100 ( V_134 , V_76 , V_83 ) ;
F_102 ( V_82 , V_83 , V_17 , V_80 ) ;
F_132 ( V_76 , V_94 , V_17 ) ;
if ( ! V_15 ) {
F_103 ( V_82 , V_88 , V_31 ) ;
F_31 () ;
} else {
F_88 ( ! F_123 ( V_15 ) , V_15 ) ;
F_159 ( V_15 ) ;
F_97 ( V_15 ) ;
}
V_45 |= V_133 ;
}
F_95 ( V_85 ) ;
V_136:
F_160 ( V_82 , V_126 , V_127 ) ;
V_71:
return V_45 ;
V_116:
F_95 ( V_85 ) ;
return V_45 ;
}
struct V_15 * F_169 ( struct V_75 * V_76 ,
unsigned long V_110 ,
T_1 * V_17 ,
unsigned int V_95 )
{
struct V_81 * V_82 = V_76 -> V_137 ;
struct V_15 * V_15 = NULL ;
F_170 ( F_118 ( V_82 , V_17 ) ) ;
if ( V_95 & V_138 && ! F_171 ( * V_17 ) )
goto V_71;
if ( ( V_95 & V_139 ) && F_19 ( * V_17 ) )
return F_172 ( - V_140 ) ;
if ( ( V_95 & V_141 ) && F_173 ( * V_17 ) )
goto V_71;
V_15 = F_20 ( * V_17 ) ;
F_88 ( ! F_123 ( V_15 ) , V_15 ) ;
if ( V_95 & V_142 ) {
T_1 V_124 ;
V_124 = F_130 ( F_99 ( * V_17 ) ) ;
if ( F_131 ( V_76 , V_110 & V_96 ,
V_17 , V_124 , 1 ) )
F_132 ( V_76 , V_110 , V_17 ) ;
}
if ( ( V_95 & V_143 ) && ( V_76 -> V_77 & V_144 ) ) {
if ( V_15 -> V_145 && F_174 ( V_15 ) ) {
F_175 () ;
if ( V_15 -> V_145 )
F_176 ( V_15 ) ;
F_177 ( V_15 ) ;
}
}
V_15 += ( V_110 & ~ V_96 ) >> V_6 ;
F_88 ( ! F_89 ( V_15 ) , V_15 ) ;
if ( V_95 & V_146 )
F_178 ( V_15 ) ;
V_71:
return V_15 ;
}
int F_179 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_110 , T_1 V_17 , T_1 * V_147 )
{
T_7 * V_85 ;
struct V_117 * V_117 = NULL ;
struct V_15 * V_15 ;
unsigned long V_83 = V_110 & V_96 ;
int V_148 = - 1 , V_149 = F_115 () ;
int V_150 , V_151 = - 1 ;
bool V_152 ;
bool V_153 = false ;
int V_95 = 0 ;
V_85 = F_93 ( V_82 , V_147 ) ;
if ( F_10 ( ! F_129 ( V_17 , * V_147 ) ) )
goto V_116;
if ( F_10 ( F_180 ( * V_147 ) ) ) {
F_95 ( V_85 ) ;
F_181 ( V_76 -> V_117 , V_147 ) ;
goto V_71;
}
V_15 = F_20 ( V_17 ) ;
F_32 ( F_17 ( V_15 ) ) ;
V_148 = F_141 ( V_15 ) ;
V_151 = F_182 ( V_15 ) ;
F_183 ( V_154 ) ;
if ( V_148 == V_149 ) {
F_183 ( V_155 ) ;
V_95 |= V_156 ;
}
if ( ! F_171 ( V_17 ) )
V_95 |= V_157 ;
V_152 = F_174 ( V_15 ) ;
V_150 = F_184 ( V_15 , V_76 , V_83 ) ;
if ( V_150 == - 1 ) {
if ( V_152 )
goto V_158;
}
if ( ! V_152 ) {
F_95 ( V_85 ) ;
F_185 ( V_15 ) ;
V_148 = - 1 ;
goto V_71;
}
F_124 ( V_15 ) ;
F_95 ( V_85 ) ;
V_117 = F_186 ( V_15 ) ;
F_162 ( V_85 ) ;
if ( F_10 ( ! F_129 ( V_17 , * V_147 ) ) ) {
F_177 ( V_15 ) ;
F_97 ( V_15 ) ;
V_148 = - 1 ;
goto V_116;
}
if ( F_10 ( ! V_117 ) ) {
F_97 ( V_15 ) ;
V_148 = - 1 ;
goto V_158;
}
F_95 ( V_85 ) ;
V_153 = F_187 ( V_82 , V_76 ,
V_147 , V_17 , V_110 , V_15 , V_150 ) ;
if ( V_153 ) {
V_95 |= V_159 ;
V_148 = V_150 ;
}
goto V_71;
V_158:
F_32 ( ! F_188 ( V_15 ) ) ;
V_17 = F_189 ( V_17 ) ;
F_102 ( V_82 , V_83 , V_147 , V_17 ) ;
F_41 ( F_173 ( * V_147 ) ) ;
F_132 ( V_76 , V_110 , V_147 ) ;
F_177 ( V_15 ) ;
V_116:
F_95 ( V_85 ) ;
V_71:
if ( V_117 )
F_190 ( V_117 ) ;
if ( V_148 != - 1 )
F_191 ( V_151 , V_148 , V_31 , V_95 ) ;
return 0 ;
}
int F_192 ( struct V_160 * V_161 , struct V_75 * V_76 ,
T_1 * V_17 , unsigned long V_110 )
{
T_7 * V_85 ;
int V_45 = 0 ;
if ( F_193 ( V_17 , V_76 , & V_85 ) == 1 ) {
struct V_15 * V_15 ;
T_6 V_84 ;
T_1 V_118 ;
V_118 = F_194 ( V_161 -> V_82 , V_110 , V_17 ) ;
F_195 ( V_161 , V_17 , V_110 ) ;
V_84 = F_149 ( V_161 -> V_82 , V_17 ) ;
if ( F_19 ( V_118 ) ) {
F_196 ( & V_161 -> V_82 -> V_89 ) ;
F_95 ( V_85 ) ;
F_31 () ;
} else {
V_15 = F_20 ( V_118 ) ;
F_159 ( V_15 ) ;
F_88 ( F_163 ( V_15 ) < 0 , V_15 ) ;
F_103 ( V_161 -> V_82 , V_88 , - V_31 ) ;
F_88 ( ! F_123 ( V_15 ) , V_15 ) ;
F_196 ( & V_161 -> V_82 -> V_89 ) ;
F_95 ( V_85 ) ;
F_197 ( V_161 , V_15 ) ;
}
F_98 ( V_161 -> V_82 , V_84 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_198 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_110 , unsigned long V_162 ,
unsigned char * V_163 )
{
T_7 * V_85 ;
int V_45 = 0 ;
if ( F_193 ( V_17 , V_76 , & V_85 ) == 1 ) {
F_95 ( V_85 ) ;
memset ( V_163 , 1 , ( V_162 - V_110 ) >> V_6 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_199 ( struct V_75 * V_76 , struct V_75 * V_164 ,
unsigned long V_165 ,
unsigned long V_166 , unsigned long V_167 ,
T_1 * V_168 , T_1 * V_169 )
{
T_7 * V_170 , * V_171 ;
int V_45 = 0 ;
T_1 V_17 ;
struct V_81 * V_82 = V_76 -> V_137 ;
if ( ( V_165 & ~ V_96 ) ||
( V_166 & ~ V_96 ) ||
V_167 - V_165 < V_98 ||
( V_164 -> V_77 & V_172 ) )
goto V_71;
if ( F_200 ( ! F_94 ( * V_169 ) ) ) {
F_41 ( F_120 ( * V_169 ) ) ;
goto V_71;
}
V_45 = F_193 ( V_168 , V_76 , & V_170 ) ;
if ( V_45 == 1 ) {
V_171 = F_118 ( V_82 , V_169 ) ;
if ( V_171 != V_170 )
F_119 ( V_171 , V_114 ) ;
V_17 = F_194 ( V_82 , V_165 , V_168 ) ;
F_41 ( ! F_94 ( * V_169 ) ) ;
if ( F_201 ( V_171 , V_170 ) ) {
T_6 V_84 ;
V_84 = F_149 ( V_82 , V_168 ) ;
F_101 ( V_82 , V_169 , V_84 ) ;
}
F_102 ( V_82 , V_166 , V_169 , F_202 ( V_17 ) ) ;
if ( V_171 != V_170 )
F_95 ( V_171 ) ;
F_95 ( V_170 ) ;
}
V_71:
return V_45 ;
}
int F_203 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_110 , T_5 V_173 , int V_174 )
{
struct V_81 * V_82 = V_76 -> V_137 ;
T_7 * V_85 ;
int V_45 = 0 ;
if ( F_193 ( V_17 , V_76 , & V_85 ) == 1 ) {
T_1 V_80 ;
V_45 = 1 ;
if ( ! V_174 ) {
V_80 = F_194 ( V_82 , V_110 , V_17 ) ;
if ( F_173 ( V_80 ) )
V_80 = F_189 ( V_80 ) ;
V_80 = F_204 ( V_80 , V_173 ) ;
V_45 = V_31 ;
F_102 ( V_82 , V_110 , V_17 , V_80 ) ;
F_32 ( F_171 ( V_80 ) ) ;
} else {
struct V_15 * V_15 = F_20 ( * V_17 ) ;
if ( ! F_17 ( V_15 ) &&
! F_173 ( * V_17 ) ) {
F_205 ( V_82 , V_110 , V_17 ) ;
V_45 = V_31 ;
}
}
F_95 ( V_85 ) ;
}
return V_45 ;
}
int F_193 ( T_1 * V_17 , struct V_75 * V_76 ,
T_7 * * V_85 )
{
* V_85 = F_93 ( V_76 -> V_137 , V_17 ) ;
if ( F_22 ( F_120 ( * V_17 ) ) ) {
if ( F_10 ( F_121 ( * V_17 ) ) ) {
F_95 ( * V_85 ) ;
F_122 ( V_76 -> V_117 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_95 ( * V_85 ) ;
return 0 ;
}
T_1 * F_206 ( struct V_15 * V_15 ,
struct V_81 * V_82 ,
unsigned long V_94 ,
enum V_175 V_47 ,
T_7 * * V_85 )
{
T_10 * V_176 ;
T_11 * V_177 ;
T_1 * V_17 ;
if ( V_94 & ~ V_96 )
return NULL ;
V_176 = F_207 ( V_82 , V_94 ) ;
if ( ! F_208 ( * V_176 ) )
return NULL ;
V_177 = F_209 ( V_176 , V_94 ) ;
if ( ! F_210 ( * V_177 ) )
return NULL ;
V_17 = F_211 ( V_177 , V_94 ) ;
* V_85 = F_93 ( V_82 , V_17 ) ;
if ( ! F_212 ( * V_17 ) )
goto V_120;
if ( F_20 ( * V_17 ) != V_15 )
goto V_120;
if ( V_47 == V_178 &&
F_121 ( * V_17 ) )
goto V_120;
if ( F_120 ( * V_17 ) ) {
F_41 ( V_47 == V_179 &&
! F_121 ( * V_17 ) ) ;
return V_17 ;
}
V_120:
F_95 ( * V_85 ) ;
return NULL ;
}
static int F_213 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_94 )
{
struct V_81 * V_82 = V_76 -> V_137 ;
T_7 * V_85 ;
T_1 * V_17 ;
int V_45 = 0 ;
const unsigned long V_126 = V_94 ;
const unsigned long V_127 = V_94 + V_98 ;
F_147 ( V_82 , V_126 , V_127 ) ;
V_17 = F_206 ( V_15 , V_82 , V_94 ,
V_178 , & V_85 ) ;
if ( V_17 ) {
F_214 ( V_76 , V_94 , V_17 ) ;
V_45 = 1 ;
F_95 ( V_85 ) ;
}
F_160 ( V_82 , V_126 , V_127 ) ;
return V_45 ;
}
static void F_215 ( struct V_15 * V_15 ,
struct V_180 * V_181 )
{
int V_125 ;
struct V_1 * V_1 = F_216 ( V_15 ) ;
struct V_182 * V_182 ;
int V_183 = 0 ;
F_217 ( & V_1 -> V_184 ) ;
V_182 = F_218 ( V_15 , V_1 ) ;
F_219 ( V_15 ) ;
F_220 ( V_15 ) ;
for ( V_125 = V_31 - 1 ; V_125 >= 1 ; V_125 -- ) {
struct V_15 * V_185 = V_15 + V_125 ;
F_32 ( F_163 ( V_185 ) < 0 ) ;
V_183 += F_163 ( V_185 ) ;
F_32 ( V_183 < 0 ) ;
F_32 ( F_35 ( & V_185 -> V_123 ) != 0 ) ;
F_135 ( F_163 ( V_15 ) + F_163 ( V_185 ) + 1 ,
& V_185 -> V_123 ) ;
F_221 () ;
V_185 -> V_95 &= ~ V_186 | V_187 ;
V_185 -> V_95 |= ( V_15 -> V_95 &
( ( 1L << V_188 ) |
( 1L << V_189 ) |
( 1L << V_190 ) |
( 1L << V_191 ) |
( 1L << V_192 ) |
( 1L << V_193 ) ) ) ;
V_185 -> V_95 |= ( 1L << V_194 ) ;
F_158 () ;
V_185 -> V_195 = V_15 -> V_195 ;
F_32 ( V_185 -> V_145 ) ;
V_185 -> V_145 = V_15 -> V_145 ;
V_185 -> V_196 = V_15 -> V_196 + V_125 ;
F_222 ( V_185 , F_182 ( V_15 ) ) ;
F_32 ( ! F_223 ( V_185 ) ) ;
F_32 ( ! F_224 ( V_185 ) ) ;
F_32 ( ! F_225 ( V_185 ) ) ;
F_32 ( ! F_226 ( V_185 ) ) ;
F_227 ( V_15 , V_185 , V_182 , V_181 ) ;
}
F_228 ( V_183 , & V_15 -> V_123 ) ;
F_32 ( F_35 ( & V_15 -> V_123 ) <= 0 ) ;
F_229 ( V_1 , V_197 , - 1 ) ;
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_232 ( & V_1 -> V_184 ) ;
for ( V_125 = 1 ; V_125 < V_31 ; V_125 ++ ) {
struct V_15 * V_185 = V_15 + V_125 ;
F_32 ( F_233 ( V_185 ) <= 0 ) ;
F_97 ( V_185 ) ;
}
F_32 ( F_233 ( V_15 ) <= 0 ) ;
}
static int F_234 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_94 )
{
struct V_81 * V_82 = V_76 -> V_137 ;
T_7 * V_85 ;
T_1 * V_17 , V_124 ;
int V_45 = 0 , V_125 ;
T_6 V_84 ;
unsigned long V_83 ;
V_17 = F_206 ( V_15 , V_82 , V_94 ,
V_179 , & V_85 ) ;
if ( V_17 ) {
V_84 = F_149 ( V_82 , V_17 ) ;
F_150 ( V_82 , & V_124 , V_84 ) ;
V_83 = V_94 ;
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ , V_83 += V_130 ) {
T_9 * V_132 , V_80 ;
F_32 ( F_89 ( V_15 + V_125 ) ) ;
V_80 = F_151 ( V_15 + V_125 , V_76 -> V_87 ) ;
V_80 = F_152 ( F_153 ( V_80 ) , V_76 ) ;
if ( ! F_171 ( * V_17 ) )
V_80 = F_235 ( V_80 ) ;
else
F_32 ( F_163 ( V_15 ) != 1 ) ;
if ( ! F_236 ( * V_17 ) )
V_80 = F_237 ( V_80 ) ;
if ( F_173 ( * V_17 ) )
V_80 = F_238 ( V_80 ) ;
V_132 = F_154 ( & V_124 , V_83 ) ;
F_32 ( ! F_155 ( * V_132 ) ) ;
F_156 ( V_82 , V_83 , V_132 , V_80 ) ;
F_157 ( V_132 ) ;
}
F_158 () ;
F_239 ( V_76 , V_94 , V_17 ) ;
F_150 ( V_82 , V_17 , V_84 ) ;
V_45 = 1 ;
F_95 ( V_85 ) ;
}
return V_45 ;
}
static void F_240 ( struct V_15 * V_15 ,
struct V_117 * V_117 ,
struct V_180 * V_181 )
{
int V_198 , V_199 ;
T_12 V_200 = V_15 -> V_196 << ( V_201 - V_6 ) ;
struct V_202 * V_203 ;
F_32 ( ! F_123 ( V_15 ) ) ;
F_32 ( F_241 ( V_15 ) ) ;
V_198 = 0 ;
F_242 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_203 -> V_76 ;
unsigned long V_110 = F_243 ( V_15 , V_76 ) ;
F_32 ( F_244 ( V_76 ) ) ;
V_198 += F_213 ( V_15 , V_76 , V_110 ) ;
}
if ( V_198 != F_163 ( V_15 ) ) {
F_12 ( L_17 ,
V_198 , F_163 ( V_15 ) ) ;
F_245 () ;
}
F_215 ( V_15 , V_181 ) ;
V_199 = 0 ;
F_242 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_203 -> V_76 ;
unsigned long V_110 = F_243 ( V_15 , V_76 ) ;
F_32 ( F_244 ( V_76 ) ) ;
V_199 += F_234 ( V_15 , V_76 , V_110 ) ;
}
if ( V_198 != V_199 ) {
F_12 ( L_18 ,
V_198 , V_199 , F_163 ( V_15 ) ) ;
F_245 () ;
}
}
int F_246 ( struct V_15 * V_15 , struct V_180 * V_181 )
{
struct V_117 * V_117 ;
int V_45 = 1 ;
F_32 ( F_17 ( V_15 ) ) ;
F_32 ( ! F_223 ( V_15 ) ) ;
V_117 = F_247 ( V_15 ) ;
if ( ! V_117 )
goto V_71;
F_248 ( V_117 ) ;
V_45 = 0 ;
if ( ! F_89 ( V_15 ) )
goto V_116;
F_32 ( ! F_226 ( V_15 ) ) ;
F_240 ( V_15 , V_117 , V_181 ) ;
F_25 ( V_204 ) ;
F_32 ( F_89 ( V_15 ) ) ;
V_116:
F_249 ( V_117 ) ;
F_250 ( V_117 ) ;
V_71:
return V_45 ;
}
int F_251 ( struct V_75 * V_76 ,
unsigned long * V_77 , int V_205 )
{
switch ( V_205 ) {
case V_206 :
#ifdef F_252
if ( F_253 ( V_76 -> V_137 ) )
return 0 ;
#endif
if ( * V_77 & ( V_207 | V_208 ) )
return - V_42 ;
* V_77 &= ~ V_172 ;
* V_77 |= V_207 ;
if ( F_10 ( F_254 ( V_76 ) ) )
return - V_66 ;
break;
case V_209 :
if ( * V_77 & ( V_172 | V_208 ) )
return - V_42 ;
* V_77 &= ~ V_207 ;
* V_77 |= V_172 ;
break;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
V_210 = F_255 ( L_19 ,
sizeof( struct V_211 ) ,
F_256 ( struct V_211 ) , 0 , NULL ) ;
if ( ! V_210 )
return - V_66 ;
return 0 ;
}
static inline struct V_211 * F_257 ( void )
{
if ( ! V_210 )
return NULL ;
return F_258 ( V_210 , V_104 ) ;
}
static inline void F_259 ( struct V_211 * V_211 )
{
F_260 ( V_210 , V_211 ) ;
}
static struct V_211 * F_261 ( struct V_81 * V_82 )
{
struct V_211 * V_211 ;
F_262 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_82 == V_211 -> V_82 )
return V_211 ;
return NULL ;
}
static void F_263 ( struct V_81 * V_82 ,
struct V_211 * V_211 )
{
V_211 -> V_82 = V_82 ;
F_264 ( V_212 , & V_211 -> V_213 , ( long ) V_82 ) ;
}
static inline int F_265 ( struct V_81 * V_82 )
{
return F_35 ( & V_82 -> V_214 ) == 0 ;
}
int F_266 ( struct V_81 * V_82 )
{
struct V_211 * V_211 ;
int V_215 ;
V_211 = F_257 () ;
if ( ! V_211 )
return - V_66 ;
F_41 ( F_265 ( V_82 ) ) ;
if ( F_10 ( F_267 ( V_216 , & V_82 -> V_95 ) ) ) {
F_259 ( V_211 ) ;
return 0 ;
}
F_162 ( & V_217 ) ;
F_263 ( V_82 , V_211 ) ;
V_215 = F_14 ( & V_12 . V_13 ) ;
F_268 ( & V_211 -> V_218 , & V_12 . V_13 ) ;
F_95 ( & V_217 ) ;
F_269 ( & V_82 -> V_219 ) ;
if ( V_215 )
F_15 ( & V_14 ) ;
return 0 ;
}
int F_254 ( struct V_75 * V_76 )
{
unsigned long V_220 , V_221 ;
if ( ! V_76 -> V_117 )
return 0 ;
if ( V_76 -> V_222 )
return 0 ;
F_41 ( V_76 -> V_77 & V_208 ) ;
V_220 = ( V_76 -> V_97 + ~ V_96 ) & V_96 ;
V_221 = V_76 -> V_99 & V_96 ;
if ( V_220 < V_221 )
return F_112 ( V_76 ) ;
return 0 ;
}
void F_270 ( struct V_81 * V_82 )
{
struct V_211 * V_211 ;
int free = 0 ;
F_162 ( & V_217 ) ;
V_211 = F_261 ( V_82 ) ;
if ( V_211 && V_12 . V_211 != V_211 ) {
F_271 ( & V_211 -> V_213 ) ;
F_272 ( & V_211 -> V_218 ) ;
free = 1 ;
}
F_95 ( & V_217 ) ;
if ( free ) {
F_44 ( V_216 , & V_82 -> V_95 ) ;
F_259 ( V_211 ) ;
F_273 ( V_82 ) ;
} else if ( V_211 ) {
F_274 ( & V_82 -> V_223 ) ;
F_275 ( & V_82 -> V_223 ) ;
}
}
static void F_276 ( struct V_15 * V_15 )
{
F_277 ( V_15 , V_224 + 0 ) ;
F_177 ( V_15 ) ;
F_278 ( V_15 ) ;
}
static void F_279 ( T_9 * V_132 , T_9 * V_225 )
{
while ( -- V_225 >= V_132 ) {
T_9 V_226 = * V_225 ;
if ( ! F_155 ( V_226 ) )
F_276 ( F_280 ( V_226 ) ) ;
}
}
static int F_281 ( struct V_75 * V_76 ,
unsigned long V_94 ,
T_9 * V_132 )
{
struct V_15 * V_15 ;
T_9 * V_225 ;
int V_227 = 0 , V_228 = 0 ;
for ( V_225 = V_132 ; V_225 < V_132 + V_31 ;
V_225 ++ , V_94 += V_130 ) {
T_9 V_226 = * V_225 ;
if ( F_155 ( V_226 ) ) {
if ( ++ V_228 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_282 ( V_226 ) || ! F_283 ( V_226 ) )
goto V_71;
V_15 = F_284 ( V_76 , V_94 , V_226 ) ;
if ( F_10 ( ! V_15 ) )
goto V_71;
F_88 ( F_89 ( V_15 ) , V_15 ) ;
F_88 ( ! F_223 ( V_15 ) , V_15 ) ;
F_88 ( ! F_226 ( V_15 ) , V_15 ) ;
if ( F_233 ( V_15 ) != 1 )
goto V_71;
if ( ! F_174 ( V_15 ) )
goto V_71;
if ( F_285 ( V_15 ) ) {
F_177 ( V_15 ) ;
goto V_71;
}
F_286 ( V_15 , V_224 + 0 ) ;
F_88 ( ! F_188 ( V_15 ) , V_15 ) ;
F_88 ( F_287 ( V_15 ) , V_15 ) ;
if ( F_288 ( V_226 ) || F_289 ( V_15 ) ||
F_290 ( V_76 -> V_137 , V_94 ) )
V_227 = 1 ;
}
if ( F_22 ( V_227 ) )
return 1 ;
V_71:
F_279 ( V_132 , V_225 ) ;
return 0 ;
}
static void F_291 ( T_9 * V_132 , struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_94 ,
T_7 * V_85 )
{
T_9 * V_225 ;
for ( V_225 = V_132 ; V_225 < V_132 + V_31 ; V_225 ++ ) {
T_9 V_226 = * V_225 ;
struct V_15 * V_113 ;
if ( F_155 ( V_226 ) ) {
F_292 ( V_15 , V_94 ) ;
F_103 ( V_76 -> V_137 , V_88 , 1 ) ;
} else {
V_113 = F_280 ( V_226 ) ;
F_145 ( V_15 , V_113 , V_94 , V_76 ) ;
F_88 ( F_163 ( V_113 ) != 1 , V_113 ) ;
F_276 ( V_113 ) ;
F_162 ( V_85 ) ;
F_293 ( V_76 -> V_137 , V_94 , V_225 ) ;
F_159 ( V_113 ) ;
F_95 ( V_85 ) ;
F_294 ( V_113 ) ;
}
V_94 += V_130 ;
V_15 ++ ;
}
}
static void F_295 ( void )
{
F_296 ( V_14 , false ,
F_297 ( V_56 ) ) ;
}
static int F_298 ( void )
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
static bool F_299 ( struct V_15 * * V_236 , bool * V_237 )
{
if ( F_11 ( * V_236 ) ) {
if ( ! * V_237 )
return false ;
* V_237 = false ;
* V_236 = NULL ;
F_295 () ;
} else if ( * V_236 ) {
F_97 ( * V_236 ) ;
* V_236 = NULL ;
}
return true ;
}
static struct V_15
* F_300 ( struct V_15 * * V_236 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_94 ,
int V_238 )
{
F_88 ( * V_236 , * V_236 ) ;
* V_236 = F_301 ( V_238 , F_105 (
F_302 () , V_129 ) , V_24 ) ;
F_303 ( & V_82 -> V_223 ) ;
if ( F_10 ( ! * V_236 ) ) {
F_25 ( V_239 ) ;
* V_236 = F_172 ( - V_66 ) ;
return NULL ;
}
F_25 ( V_240 ) ;
return * V_236 ;
}
static int F_298 ( void )
{
return 0 ;
}
static inline struct V_15 * F_304 ( int V_90 )
{
return F_24 ( F_105 ( V_90 , 0 ) ,
V_24 ) ;
}
static struct V_15 * F_305 ( bool * V_237 )
{
struct V_15 * V_236 ;
do {
V_236 = F_304 ( F_302 () ) ;
if ( ! V_236 ) {
F_25 ( V_239 ) ;
if ( ! * V_237 )
return NULL ;
* V_237 = false ;
F_295 () ;
} else
F_25 ( V_240 ) ;
} while ( F_10 ( ! V_236 ) && F_22 ( F_2 () ) );
return V_236 ;
}
static bool F_299 ( struct V_15 * * V_236 , bool * V_237 )
{
if ( ! * V_236 )
* V_236 = F_305 ( V_237 ) ;
if ( F_10 ( ! * V_236 ) )
return false ;
return true ;
}
static struct V_15
* F_300 ( struct V_15 * * V_236 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_94 ,
int V_238 )
{
F_303 ( & V_82 -> V_223 ) ;
F_41 ( ! * V_236 ) ;
return * V_236 ;
}
static bool F_306 ( struct V_75 * V_76 )
{
if ( ( ! ( V_76 -> V_77 & V_207 ) && ! F_307 () ) ||
( V_76 -> V_77 & V_172 ) )
return false ;
if ( ! V_76 -> V_117 || V_76 -> V_222 )
return false ;
if ( F_244 ( V_76 ) )
return false ;
F_41 ( V_76 -> V_77 & V_208 ) ;
return true ;
}
static void F_308 ( struct V_81 * V_82 ,
unsigned long V_94 ,
struct V_15 * * V_236 ,
struct V_75 * V_76 ,
int V_238 )
{
T_1 * V_17 , V_124 ;
T_9 * V_132 ;
T_6 V_84 ;
struct V_15 * V_134 ;
T_7 * V_241 , * V_242 ;
int V_243 ;
unsigned long V_220 , V_221 ;
unsigned long V_126 ;
unsigned long V_127 ;
F_41 ( V_94 & ~ V_96 ) ;
V_134 = F_300 ( V_236 , V_82 , V_76 , V_94 , V_238 ) ;
if ( ! V_134 )
return;
if ( F_10 ( F_116 ( V_134 , V_82 , V_104 ) ) )
return;
F_274 ( & V_82 -> V_223 ) ;
if ( F_10 ( F_265 ( V_82 ) ) )
goto V_71;
V_76 = F_309 ( V_82 , V_94 ) ;
if ( ! V_76 )
goto V_71;
V_220 = ( V_76 -> V_97 + ~ V_96 ) & V_96 ;
V_221 = V_76 -> V_99 & V_96 ;
if ( V_94 < V_220 || V_94 + V_98 > V_221 )
goto V_71;
if ( ! F_306 ( V_76 ) )
goto V_71;
V_17 = F_310 ( V_82 , V_94 ) ;
if ( ! V_17 )
goto V_71;
F_248 ( V_76 -> V_117 ) ;
V_132 = F_154 ( V_17 , V_94 ) ;
V_242 = F_311 ( V_82 , V_17 ) ;
V_126 = V_94 ;
V_127 = V_94 + V_98 ;
F_147 ( V_82 , V_126 , V_127 ) ;
V_241 = F_93 ( V_82 , V_17 ) ;
V_124 = F_148 ( V_76 , V_94 , V_17 ) ;
F_95 ( V_241 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
F_162 ( V_242 ) ;
V_243 = F_281 ( V_76 , V_94 , V_132 ) ;
F_95 ( V_242 ) ;
if ( F_10 ( ! V_243 ) ) {
F_157 ( V_132 ) ;
F_162 ( V_241 ) ;
F_32 ( ! F_94 ( * V_17 ) ) ;
F_150 ( V_82 , V_17 , F_312 ( V_124 ) ) ;
F_95 ( V_241 ) ;
F_249 ( V_76 -> V_117 ) ;
goto V_71;
}
F_249 ( V_76 -> V_117 ) ;
F_291 ( V_132 , V_134 , V_76 , V_94 , V_242 ) ;
F_157 ( V_132 ) ;
F_92 ( V_134 ) ;
V_84 = F_312 ( V_124 ) ;
V_124 = F_84 ( V_134 , V_76 -> V_87 ) ;
V_124 = F_82 ( F_99 ( V_124 ) , V_76 ) ;
F_158 () ;
F_162 ( V_241 ) ;
F_32 ( ! F_94 ( * V_17 ) ) ;
F_100 ( V_134 , V_76 , V_94 ) ;
F_101 ( V_82 , V_17 , V_84 ) ;
F_102 ( V_82 , V_94 , V_17 , V_124 ) ;
F_132 ( V_76 , V_94 , V_17 ) ;
F_95 ( V_241 ) ;
* V_236 = NULL ;
V_59 ++ ;
V_244:
F_275 ( & V_82 -> V_223 ) ;
return;
V_71:
F_96 ( V_134 ) ;
goto V_244;
}
static int F_313 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_94 ,
struct V_15 * * V_236 )
{
T_1 * V_17 ;
T_9 * V_132 , * V_225 ;
int V_45 = 0 , V_227 = 0 , V_228 = 0 ;
struct V_15 * V_15 ;
unsigned long V_245 ;
T_7 * V_85 ;
int V_238 = V_230 ;
F_41 ( V_94 & ~ V_96 ) ;
V_17 = F_310 ( V_82 , V_94 ) ;
if ( ! V_17 )
goto V_71;
memset ( V_235 , 0 , sizeof( V_235 ) ) ;
V_132 = F_314 ( V_82 , V_17 , V_94 , & V_85 ) ;
for ( V_245 = V_94 , V_225 = V_132 ; V_225 < V_132 + V_31 ;
V_225 ++ , V_245 += V_130 ) {
T_9 V_226 = * V_225 ;
if ( F_155 ( V_226 ) ) {
if ( ++ V_228 <= V_62 )
continue;
else
goto V_246;
}
if ( ! F_282 ( V_226 ) || ! F_283 ( V_226 ) )
goto V_246;
V_15 = F_284 ( V_76 , V_245 , V_226 ) ;
if ( F_10 ( ! V_15 ) )
goto V_246;
V_238 = F_141 ( V_15 ) ;
V_235 [ V_238 ] ++ ;
F_88 ( F_89 ( V_15 ) , V_15 ) ;
if ( ! F_287 ( V_15 ) || F_188 ( V_15 ) || ! F_223 ( V_15 ) )
goto V_246;
if ( F_233 ( V_15 ) != 1 )
goto V_246;
if ( F_288 ( V_226 ) || F_289 ( V_15 ) ||
F_290 ( V_76 -> V_137 , V_94 ) )
V_227 = 1 ;
}
if ( V_227 )
V_45 = 1 ;
V_246:
F_315 ( V_132 , V_85 ) ;
if ( V_45 ) {
V_238 = F_298 () ;
F_308 ( V_82 , V_94 , V_236 , V_76 , V_238 ) ;
}
V_71:
return V_45 ;
}
static void F_316 ( struct V_211 * V_211 )
{
struct V_81 * V_82 = V_211 -> V_82 ;
F_41 ( V_247 != 1 && ! F_317 ( & V_217 ) ) ;
if ( F_265 ( V_82 ) ) {
F_271 ( & V_211 -> V_213 ) ;
F_272 ( & V_211 -> V_218 ) ;
F_259 ( V_211 ) ;
F_273 ( V_82 ) ;
}
}
static unsigned int F_318 ( unsigned int V_58 ,
struct V_15 * * V_236 )
__releases( &khugepaged_mm_lock
static int F_319 ( void )
{
return ! F_14 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_320 ( void )
{
return ! F_14 ( & V_12 . V_13 ) ||
F_321 () ;
}
static void F_322 ( void )
{
struct V_15 * V_236 = NULL ;
unsigned int V_248 = 0 , V_249 = 0 ;
unsigned int V_58 = V_57 ;
bool V_237 = true ;
F_323 () ;
while ( V_248 < V_58 ) {
if ( ! F_299 ( & V_236 , & V_237 ) )
break;
F_146 () ;
if ( F_10 ( F_321 () || F_324 ( V_250 ) ) )
break;
F_162 ( & V_217 ) ;
if ( ! V_12 . V_211 )
V_249 ++ ;
if ( F_319 () &&
V_249 < 2 )
V_248 += F_318 ( V_58 - V_248 ,
& V_236 ) ;
else
V_248 = V_58 ;
F_95 ( & V_217 ) ;
}
if ( ! F_325 ( V_236 ) )
F_97 ( V_236 ) ;
}
static void F_326 ( void )
{
F_327 () ;
if ( F_319 () ) {
if ( ! V_53 )
return;
F_296 ( V_14 ,
F_321 () ,
F_297 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_328 ( V_14 , F_320 () ) ;
}
static int V_11 ( void * V_228 )
{
struct V_211 * V_211 ;
F_329 () ;
F_330 ( V_250 , V_251 ) ;
while ( ! F_321 () ) {
F_322 () ;
F_326 () ;
}
F_162 ( & V_217 ) ;
V_211 = V_12 . V_211 ;
V_12 . V_211 = NULL ;
if ( V_211 )
F_316 ( V_211 ) ;
F_95 ( & V_217 ) ;
return 0 ;
}
static void F_331 ( struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_17 )
{
struct V_81 * V_82 = V_76 -> V_137 ;
T_6 V_84 ;
T_1 V_124 ;
int V_125 ;
F_148 ( V_76 , V_83 , V_17 ) ;
V_84 = F_149 ( V_82 , V_17 ) ;
F_150 ( V_82 , & V_124 , V_84 ) ;
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ , V_83 += V_130 ) {
T_9 * V_132 , V_80 ;
V_80 = F_332 ( F_333 ( V_83 ) , V_76 -> V_87 ) ;
V_80 = F_334 ( V_80 ) ;
V_132 = F_154 ( & V_124 , V_83 ) ;
F_41 ( ! F_155 ( * V_132 ) ) ;
F_156 ( V_82 , V_83 , V_132 , V_80 ) ;
F_157 ( V_132 ) ;
}
F_158 () ;
F_150 ( V_82 , V_17 , V_84 ) ;
F_31 () ;
}
void F_335 ( struct V_75 * V_76 , unsigned long V_94 ,
T_1 * V_17 )
{
T_7 * V_85 ;
struct V_15 * V_15 ;
struct V_81 * V_82 = V_76 -> V_137 ;
unsigned long V_83 = V_94 & V_96 ;
unsigned long V_126 ;
unsigned long V_127 ;
F_32 ( V_76 -> V_97 > V_83 || V_76 -> V_99 < V_83 + V_98 ) ;
V_126 = V_83 ;
V_127 = V_83 + V_98 ;
V_252:
F_147 ( V_82 , V_126 , V_127 ) ;
V_85 = F_93 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_120 ( * V_17 ) ) ) {
F_95 ( V_85 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
return;
}
if ( F_19 ( * V_17 ) ) {
F_331 ( V_76 , V_83 , V_17 ) ;
F_95 ( V_85 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
return;
}
V_15 = F_20 ( * V_17 ) ;
F_88 ( ! F_233 ( V_15 ) , V_15 ) ;
F_124 ( V_15 ) ;
F_95 ( V_85 ) ;
F_160 ( V_82 , V_126 , V_127 ) ;
F_167 ( V_15 ) ;
F_97 ( V_15 ) ;
if ( F_10 ( F_120 ( * V_17 ) ) )
goto V_252;
}
void F_336 ( struct V_81 * V_82 , unsigned long V_94 ,
T_1 * V_17 )
{
struct V_75 * V_76 ;
V_76 = F_309 ( V_82 , V_94 ) ;
F_32 ( V_76 == NULL ) ;
F_166 ( V_76 , V_94 , V_17 ) ;
}
static void F_337 ( struct V_81 * V_82 ,
unsigned long V_94 )
{
T_10 * V_176 ;
T_11 * V_177 ;
T_1 * V_17 ;
F_41 ( ! ( V_94 & ~ V_96 ) ) ;
V_176 = F_207 ( V_82 , V_94 ) ;
if ( ! F_208 ( * V_176 ) )
return;
V_177 = F_209 ( V_176 , V_94 ) ;
if ( ! F_210 ( * V_177 ) )
return;
V_17 = F_211 ( V_177 , V_94 ) ;
if ( ! F_212 ( * V_17 ) )
return;
F_336 ( V_82 , V_94 , V_17 ) ;
}
void F_338 ( struct V_75 * V_76 ,
unsigned long V_253 ,
unsigned long V_162 ,
long V_254 )
{
if ( V_253 & ~ V_96 &&
( V_253 & V_96 ) >= V_76 -> V_97 &&
( V_253 & V_96 ) + V_98 <= V_76 -> V_99 )
F_337 ( V_76 -> V_137 , V_253 ) ;
if ( V_162 & ~ V_96 &&
( V_162 & V_96 ) >= V_76 -> V_97 &&
( V_162 & V_96 ) + V_98 <= V_76 -> V_99 )
F_337 ( V_76 -> V_137 , V_162 ) ;
if ( V_254 > 0 ) {
struct V_75 * V_255 = V_76 -> V_256 ;
unsigned long V_257 = V_255 -> V_97 ;
V_257 += V_254 << V_6 ;
if ( V_257 & ~ V_96 &&
( V_257 & V_96 ) >= V_255 -> V_97 &&
( V_257 & V_96 ) + V_98 <= V_255 -> V_99 )
F_337 ( V_255 -> V_137 , V_257 ) ;
}
}
