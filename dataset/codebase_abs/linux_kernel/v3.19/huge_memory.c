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
F_29 ( V_18 , F_30 ( V_18 ) ) ;
goto V_19;
}
F_31 ( & V_20 , 2 ) ;
F_28 () ;
return F_18 ( V_16 ) ;
}
static void F_32 ( void )
{
F_33 ( F_34 ( & V_20 ) ) ;
}
static unsigned long F_35 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_36 ( & V_20 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_37 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_38 ( & V_20 , 1 , 0 ) == 1 ) {
struct V_15 * V_18 = F_39 ( & V_16 , NULL ) ;
F_33 ( V_18 == NULL ) ;
F_29 ( V_18 , F_30 ( V_18 ) ) ;
return V_31 ;
}
return 0 ;
}
static T_2 F_40 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( F_41 ( V_38 , & V_40 ) ) {
F_42 ( F_41 ( V_39 , & V_40 ) ) ;
return sprintf ( V_36 , L_5 ) ;
} else if ( F_41 ( V_39 , & V_40 ) )
return sprintf ( V_36 , L_6 ) ;
else
return sprintf ( V_36 , L_7 ) ;
}
static T_2 F_43 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( ! memcmp ( L_8 , V_36 ,
F_4 ( sizeof( L_8 ) - 1 , V_41 ) ) ) {
F_44 ( V_38 , & V_40 ) ;
F_45 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_9 , V_36 ,
F_4 ( sizeof( L_9 ) - 1 , V_41 ) ) ) {
F_45 ( V_38 , & V_40 ) ;
F_44 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_10 , V_36 ,
F_4 ( sizeof( L_10 ) - 1 , V_41 ) ) ) {
F_45 ( V_38 , & V_40 ) ;
F_45 ( V_39 , & V_40 ) ;
} else
return - V_42 ;
return V_41 ;
}
static T_2 F_46 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_40 ( V_33 , V_35 , V_36 ,
V_43 ,
V_44 ) ;
}
static T_2 F_47 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
T_2 V_45 ;
V_45 = F_43 ( V_33 , V_35 , V_36 , V_41 ,
V_43 ,
V_44 ) ;
if ( V_45 > 0 ) {
int V_9 ;
F_48 ( & V_46 ) ;
V_9 = F_8 () ;
F_49 ( & V_46 ) ;
if ( V_9 )
V_45 = V_9 ;
}
return V_45 ;
}
static T_2 F_50 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_47 )
{
return sprintf ( V_36 , L_11 ,
! ! F_41 ( V_47 , & V_40 ) ) ;
}
static T_2 F_51 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 ,
enum V_37 V_47 )
{
unsigned long V_48 ;
int V_45 ;
V_45 = F_52 ( V_36 , 10 , & V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_48 > 1 )
return - V_42 ;
if ( V_48 )
F_44 ( V_47 , & V_40 ) ;
else
F_45 ( V_47 , & V_40 ) ;
return V_41 ;
}
static T_2 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_40 ( V_33 , V_35 , V_36 ,
V_49 ,
V_50 ) ;
}
static T_2 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_43 ( V_33 , V_35 , V_36 , V_41 ,
V_49 ,
V_50 ) ;
}
static T_2 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_50 ( V_33 , V_35 , V_36 ,
V_51 ) ;
}
static T_2 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_41 )
{
return F_51 ( V_33 , V_35 , V_36 , V_41 ,
V_51 ) ;
}
static T_2 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_50 ( V_33 , V_35 , V_36 ,
V_52 ) ;
}
static T_2 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_51 ( V_33 , V_35 , V_36 , V_41 ,
V_52 ) ;
}
static T_2 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_53 ) ;
}
static T_2 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_52 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_53 = V_54 ;
F_15 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_56 ) ;
}
static T_2 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_52 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_56 = V_54 ;
F_15 ( & V_14 ) ;
return V_41 ;
}
static T_2 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_57 ) ;
}
static T_2 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_9 ;
unsigned long V_58 ;
V_9 = F_52 ( V_36 , 10 , & V_58 ) ;
if ( V_9 || ! V_58 || V_58 > V_55 )
return - V_42 ;
V_57 = V_58 ;
return V_41 ;
}
static T_2 F_65 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_59 ) ;
}
static T_2 F_66 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_60 ) ;
}
static T_2 F_67 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_50 ( V_33 , V_35 , V_36 ,
V_61 ) ;
}
static T_2 F_68 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
return F_51 ( V_33 , V_35 , V_36 , V_41 ,
V_61 ) ;
}
static T_2 F_69 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_62 ) ;
}
static T_2 F_70 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_41 )
{
int V_9 ;
unsigned long V_63 ;
V_9 = F_52 ( V_36 , 10 , & V_63 ) ;
if ( V_9 || V_63 > V_31 - 1 )
return - V_42 ;
V_62 = V_63 ;
return V_41 ;
}
static int T_4 F_71 ( struct V_32 * * V_64 )
{
int V_9 ;
* V_64 = F_72 ( L_13 , V_65 ) ;
if ( F_10 ( ! * V_64 ) ) {
F_12 ( L_14 ) ;
return - V_66 ;
}
V_9 = F_73 ( * V_64 , & V_67 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_68;
}
V_9 = F_73 ( * V_64 , & V_69 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_70;
}
return 0 ;
V_70:
F_74 ( * V_64 , & V_67 ) ;
V_68:
F_75 ( * V_64 ) ;
return V_9 ;
}
static void T_4 F_76 ( struct V_32 * V_64 )
{
F_74 ( V_64 , & V_69 ) ;
F_74 ( V_64 , & V_67 ) ;
F_75 ( V_64 ) ;
}
static inline int F_71 ( struct V_32 * * V_64 )
{
return 0 ;
}
static inline void F_76 ( struct V_32 * V_64 )
{
}
static int T_4 F_77 ( void )
{
int V_9 ;
struct V_32 * V_64 ;
if ( ! F_78 () ) {
V_40 = 0 ;
return - V_42 ;
}
V_9 = F_71 ( & V_64 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_79 () ;
if ( V_9 )
goto V_71;
F_80 ( & V_72 ) ;
if ( V_73 < ( 512 << ( 20 - V_6 ) ) )
V_40 = 0 ;
F_8 () ;
return 0 ;
V_71:
F_76 ( V_64 ) ;
return V_9 ;
}
static int T_4 F_81 ( char * V_74 )
{
int V_45 = 0 ;
if ( ! V_74 )
goto V_71;
if ( ! strcmp ( V_74 , L_8 ) ) {
F_44 ( V_43 ,
& V_40 ) ;
F_45 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_9 ) ) {
F_45 ( V_43 ,
& V_40 ) ;
F_44 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_74 , L_10 ) ) {
F_45 ( V_43 ,
& V_40 ) ;
F_45 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
}
V_71:
if ( ! V_45 )
F_82 ( L_16 ) ;
return V_45 ;
}
T_1 F_83 ( T_1 V_17 , struct V_75 * V_76 )
{
if ( F_22 ( V_76 -> V_77 & V_78 ) )
V_17 = F_84 ( V_17 ) ;
return V_17 ;
}
static inline T_1 F_85 ( struct V_15 * V_15 , T_5 V_79 )
{
T_1 V_80 ;
V_80 = F_86 ( V_15 , V_79 ) ;
V_80 = F_87 ( V_80 ) ;
return V_80 ;
}
static int F_88 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_17 ,
struct V_15 * V_15 )
{
struct V_84 * V_85 ;
T_6 V_86 ;
T_7 * V_87 ;
F_89 ( ! F_90 ( V_15 ) , V_15 ) ;
if ( F_91 ( V_15 , V_82 , V_21 , & V_85 ) )
return V_88 ;
V_86 = F_92 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) ) {
F_93 ( V_15 , V_85 ) ;
return V_88 ;
}
F_94 ( V_15 , V_83 , V_31 ) ;
F_95 ( V_15 ) ;
V_87 = F_96 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_97 ( * V_17 ) ) ) {
F_98 ( V_87 ) ;
F_93 ( V_15 , V_85 ) ;
F_99 ( V_15 ) ;
F_100 ( V_82 , V_86 ) ;
} else {
T_1 V_80 ;
V_80 = F_85 ( V_15 , V_76 -> V_89 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
F_102 ( V_15 , V_76 , V_83 ) ;
F_103 ( V_15 , V_85 , false ) ;
F_104 ( V_15 , V_76 ) ;
F_105 ( V_82 , V_17 , V_86 ) ;
F_106 ( V_82 , V_83 , V_17 , V_80 ) ;
F_107 ( V_82 , V_90 , V_31 ) ;
F_108 ( & V_82 -> V_91 ) ;
F_98 ( V_87 ) ;
}
return 0 ;
}
static inline T_8 F_109 ( int V_92 , T_8 V_93 )
{
return ( V_21 & ~ ( V_92 ? 0 : V_94 ) ) | V_93 ;
}
static inline struct V_15 * F_110 ( int V_92 ,
struct V_75 * V_76 ,
unsigned long V_83 , int V_95 ,
T_8 V_93 )
{
return F_111 ( F_109 ( V_92 , V_93 ) ,
V_24 , V_76 , V_83 , V_95 ) ;
}
static bool F_112 ( T_6 V_86 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_83 , T_1 * V_17 ,
struct V_15 * V_18 )
{
T_1 V_80 ;
if ( ! F_97 ( * V_17 ) )
return false ;
V_80 = F_86 ( V_18 , V_76 -> V_89 ) ;
V_80 = F_87 ( V_80 ) ;
F_105 ( V_82 , V_17 , V_86 ) ;
F_106 ( V_82 , V_83 , V_17 , V_80 ) ;
F_108 ( & V_82 -> V_91 ) ;
return true ;
}
int F_113 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_96 , T_1 * V_17 ,
unsigned int V_97 )
{
struct V_15 * V_15 ;
unsigned long V_83 = V_96 & V_98 ;
if ( V_83 < V_76 -> V_99 || V_83 + V_100 > V_76 -> V_101 )
return V_102 ;
if ( F_10 ( F_114 ( V_76 ) ) )
return V_88 ;
if ( F_10 ( F_115 ( V_76 , V_76 -> V_77 ) ) )
return V_88 ;
if ( ! ( V_97 & V_103 ) && ! F_116 ( V_82 ) &&
F_117 () ) {
T_7 * V_87 ;
T_6 V_86 ;
struct V_15 * V_18 ;
bool V_104 ;
V_86 = F_92 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) )
return V_88 ;
V_18 = F_21 () ;
if ( F_10 ( ! V_18 ) ) {
F_100 ( V_82 , V_86 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
V_87 = F_96 ( V_82 , V_17 ) ;
V_104 = F_112 ( V_86 , V_82 , V_76 , V_83 , V_17 ,
V_18 ) ;
F_98 ( V_87 ) ;
if ( ! V_104 ) {
F_100 ( V_82 , V_86 ) ;
F_32 () ;
}
return 0 ;
}
V_15 = F_110 ( F_118 ( V_76 ) ,
V_76 , V_83 , F_119 () , 0 ) ;
if ( F_10 ( ! V_15 ) ) {
F_25 ( V_105 ) ;
return V_102 ;
}
if ( F_10 ( F_88 ( V_82 , V_76 , V_83 , V_17 , V_15 ) ) ) {
F_99 ( V_15 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
F_25 ( V_106 ) ;
return 0 ;
}
int F_120 ( struct V_81 * V_107 , struct V_81 * V_108 ,
T_1 * V_109 , T_1 * V_110 , unsigned long V_111 ,
struct V_75 * V_76 )
{
T_7 * V_112 , * V_113 ;
struct V_15 * V_114 ;
T_1 V_17 ;
T_6 V_86 ;
int V_45 ;
V_45 = - V_66 ;
V_86 = F_92 ( V_107 , V_111 ) ;
if ( F_10 ( ! V_86 ) )
goto V_71;
V_112 = F_96 ( V_107 , V_109 ) ;
V_113 = F_121 ( V_108 , V_110 ) ;
F_122 ( V_113 , V_115 ) ;
V_45 = - V_116 ;
V_17 = * V_110 ;
if ( F_10 ( ! F_123 ( V_17 ) ) ) {
F_100 ( V_107 , V_86 ) ;
goto V_117;
}
if ( F_19 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_104 ;
V_18 = F_21 () ;
V_104 = F_112 ( V_86 , V_107 , V_76 , V_111 , V_109 ,
V_18 ) ;
F_33 ( ! V_104 ) ;
V_45 = 0 ;
goto V_117;
}
if ( F_10 ( F_124 ( V_17 ) ) ) {
F_98 ( V_113 ) ;
F_98 ( V_112 ) ;
F_100 ( V_107 , V_86 ) ;
F_125 ( V_76 -> V_118 , V_110 ) ;
goto V_71;
}
V_114 = F_20 ( V_17 ) ;
F_89 ( ! F_126 ( V_114 ) , V_114 ) ;
F_127 ( V_114 ) ;
F_128 ( V_114 ) ;
F_107 ( V_107 , V_90 , V_31 ) ;
F_129 ( V_108 , V_111 , V_110 ) ;
V_17 = F_130 ( F_131 ( V_17 ) ) ;
F_105 ( V_107 , V_109 , V_86 ) ;
F_106 ( V_107 , V_111 , V_109 , V_17 ) ;
F_108 ( & V_107 -> V_91 ) ;
V_45 = 0 ;
V_117:
F_98 ( V_113 ) ;
F_98 ( V_112 ) ;
V_71:
return V_45 ;
}
void F_132 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
T_1 * V_17 , T_1 V_119 ,
int V_120 )
{
T_7 * V_87 ;
T_1 V_80 ;
unsigned long V_83 ;
V_87 = F_96 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_133 ( * V_17 , V_119 ) ) )
goto V_121;
V_80 = F_134 ( V_119 ) ;
V_83 = V_96 & V_98 ;
if ( F_135 ( V_76 , V_83 , V_17 , V_80 , V_120 ) )
F_136 ( V_76 , V_96 , V_17 ) ;
V_121:
F_98 ( V_87 ) ;
}
static void F_137 ( struct V_15 * V_15 )
{
if ( F_138 ( V_122 ) ) {
struct V_15 * V_123 = V_15 + V_31 ;
F_139 ( V_31 , & V_15 -> V_124 ) ;
while ( ++ V_15 < V_123 )
F_140 ( V_15 ) ;
} else {
F_127 ( V_15 ) ;
}
}
static void F_141 ( struct V_15 * V_15 )
{
if ( F_138 ( V_122 ) ) {
struct V_15 * V_123 = V_15 + V_31 ;
while ( V_15 < V_123 )
F_99 ( V_15 ++ ) ;
} else {
F_99 ( V_15 ) ;
}
}
static int F_142 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
T_1 * V_17 , T_1 V_119 ,
struct V_15 * V_15 ,
unsigned long V_83 )
{
struct V_84 * V_85 ;
T_7 * V_87 ;
T_6 V_86 ;
T_1 V_125 ;
int V_45 = 0 , V_126 ;
struct V_15 * * V_58 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_58 = F_143 ( sizeof( struct V_15 * ) * V_31 ,
V_129 ) ;
if ( F_10 ( ! V_58 ) ) {
V_45 |= V_88 ;
goto V_71;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_58 [ V_126 ] = F_144 ( V_130 |
V_131 ,
V_76 , V_96 , F_145 ( V_15 ) ) ;
if ( F_10 ( ! V_58 [ V_126 ] ||
F_91 ( V_58 [ V_126 ] , V_82 , V_129 ,
& V_85 ) ) ) {
if ( V_58 [ V_126 ] )
F_99 ( V_58 [ V_126 ] ) ;
while ( -- V_126 >= 0 ) {
V_85 = ( void * ) F_146 ( V_58 [ V_126 ] ) ;
F_147 ( V_58 [ V_126 ] , 0 ) ;
F_93 ( V_58 [ V_126 ] , V_85 ) ;
F_99 ( V_58 [ V_126 ] ) ;
}
F_148 ( V_58 ) ;
V_45 |= V_88 ;
goto V_71;
}
F_147 ( V_58 [ V_126 ] , ( unsigned long ) V_85 ) ;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
F_149 ( V_58 [ V_126 ] , V_15 + V_126 ,
V_83 + V_132 * V_126 , V_76 ) ;
F_95 ( V_58 [ V_126 ] ) ;
F_150 () ;
}
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_151 ( V_82 , V_127 , V_128 ) ;
V_87 = F_96 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_133 ( * V_17 , V_119 ) ) )
goto V_133;
F_89 ( ! F_126 ( V_15 ) , V_15 ) ;
F_152 ( V_76 , V_83 , V_17 ) ;
V_86 = F_153 ( V_82 , V_17 ) ;
F_154 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_155 ( V_58 [ V_126 ] , V_76 -> V_89 ) ;
V_80 = F_156 ( F_157 ( V_80 ) , V_76 ) ;
V_85 = ( void * ) F_146 ( V_58 [ V_126 ] ) ;
F_147 ( V_58 [ V_126 ] , 0 ) ;
F_102 ( V_58 [ V_126 ] , V_76 , V_83 ) ;
F_103 ( V_58 [ V_126 ] , V_85 , false ) ;
F_104 ( V_58 [ V_126 ] , V_76 ) ;
V_134 = F_158 ( & V_125 , V_83 ) ;
F_42 ( ! F_159 ( * V_134 ) ) ;
F_160 ( V_82 , V_83 , V_134 , V_80 ) ;
F_161 ( V_134 ) ;
}
F_148 ( V_58 ) ;
F_162 () ;
F_154 ( V_82 , V_17 , V_86 ) ;
F_163 ( V_15 ) ;
F_98 ( V_87 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
V_45 |= V_135 ;
F_99 ( V_15 ) ;
V_71:
return V_45 ;
V_133:
F_98 ( V_87 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_85 = ( void * ) F_146 ( V_58 [ V_126 ] ) ;
F_147 ( V_58 [ V_126 ] , 0 ) ;
F_93 ( V_58 [ V_126 ] , V_85 ) ;
F_99 ( V_58 [ V_126 ] ) ;
}
F_148 ( V_58 ) ;
goto V_71;
}
int F_165 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_96 , T_1 * V_17 , T_1 V_119 )
{
T_7 * V_87 ;
int V_45 = 0 ;
struct V_15 * V_15 = NULL , * V_136 ;
struct V_84 * V_85 ;
unsigned long V_83 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_87 = F_121 ( V_82 , V_17 ) ;
F_166 ( ! V_76 -> V_118 , V_76 ) ;
V_83 = V_96 & V_98 ;
if ( F_19 ( V_119 ) )
goto V_137;
F_167 ( V_87 ) ;
if ( F_10 ( ! F_133 ( * V_17 , V_119 ) ) )
goto V_117;
V_15 = F_20 ( V_119 ) ;
F_89 ( ! F_90 ( V_15 ) || ! F_126 ( V_15 ) , V_15 ) ;
if ( F_168 ( V_15 ) == 1 ) {
T_1 V_80 ;
V_80 = F_134 ( V_119 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
if ( F_135 ( V_76 , V_83 , V_17 , V_80 , 1 ) )
F_136 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_135 ;
goto V_117;
}
F_137 ( V_15 ) ;
F_98 ( V_87 ) ;
V_137:
if ( F_169 ( V_76 ) &&
! F_170 () )
V_136 = F_110 ( F_118 ( V_76 ) ,
V_76 , V_83 , F_119 () , 0 ) ;
else
V_136 = NULL ;
if ( F_10 ( ! V_136 ) ) {
if ( ! V_15 ) {
F_171 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_102 ;
} else {
V_45 = F_142 ( V_82 , V_76 , V_96 ,
V_17 , V_119 , V_15 , V_83 ) ;
if ( V_45 & V_88 ) {
F_172 ( V_15 ) ;
V_45 |= V_102 ;
}
F_141 ( V_15 ) ;
}
F_25 ( V_105 ) ;
goto V_71;
}
if ( F_10 ( F_91 ( V_136 , V_82 ,
V_21 , & V_85 ) ) ) {
F_99 ( V_136 ) ;
if ( V_15 ) {
F_172 ( V_15 ) ;
F_141 ( V_15 ) ;
} else
F_171 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_102 ;
F_25 ( V_105 ) ;
goto V_71;
}
F_25 ( V_106 ) ;
if ( ! V_15 )
F_94 ( V_136 , V_83 , V_31 ) ;
else
F_173 ( V_136 , V_15 , V_83 , V_76 , V_31 ) ;
F_95 ( V_136 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_151 ( V_82 , V_127 , V_128 ) ;
F_167 ( V_87 ) ;
if ( V_15 )
F_141 ( V_15 ) ;
if ( F_10 ( ! F_133 ( * V_17 , V_119 ) ) ) {
F_98 ( V_87 ) ;
F_93 ( V_136 , V_85 ) ;
F_99 ( V_136 ) ;
goto V_138;
} else {
T_1 V_80 ;
V_80 = F_85 ( V_136 , V_76 -> V_89 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
F_152 ( V_76 , V_83 , V_17 ) ;
F_102 ( V_136 , V_76 , V_83 ) ;
F_103 ( V_136 , V_85 , false ) ;
F_104 ( V_136 , V_76 ) ;
F_106 ( V_82 , V_83 , V_17 , V_80 ) ;
F_136 ( V_76 , V_96 , V_17 ) ;
if ( ! V_15 ) {
F_107 ( V_82 , V_90 , V_31 ) ;
F_32 () ;
} else {
F_89 ( ! F_126 ( V_15 ) , V_15 ) ;
F_163 ( V_15 ) ;
F_99 ( V_15 ) ;
}
V_45 |= V_135 ;
}
F_98 ( V_87 ) ;
V_138:
F_164 ( V_82 , V_127 , V_128 ) ;
V_71:
return V_45 ;
V_117:
F_98 ( V_87 ) ;
return V_45 ;
}
struct V_15 * F_174 ( struct V_75 * V_76 ,
unsigned long V_111 ,
T_1 * V_17 ,
unsigned int V_97 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
struct V_15 * V_15 = NULL ;
F_175 ( F_121 ( V_82 , V_17 ) ) ;
if ( V_97 & V_140 && ! F_176 ( * V_17 ) )
goto V_71;
if ( ( V_97 & V_141 ) && F_19 ( * V_17 ) )
return F_177 ( - V_142 ) ;
if ( ( V_97 & V_143 ) && F_178 ( * V_17 ) )
goto V_71;
V_15 = F_20 ( * V_17 ) ;
F_89 ( ! F_126 ( V_15 ) , V_15 ) ;
if ( V_97 & V_144 ) {
T_1 V_125 ;
V_125 = F_134 ( F_101 ( * V_17 ) ) ;
if ( F_135 ( V_76 , V_111 & V_98 ,
V_17 , V_125 , 1 ) )
F_136 ( V_76 , V_111 , V_17 ) ;
}
if ( ( V_97 & V_145 ) && ( V_76 -> V_77 & V_146 ) ) {
if ( V_15 -> V_147 && F_179 ( V_15 ) ) {
F_180 () ;
if ( V_15 -> V_147 )
F_181 ( V_15 ) ;
F_182 ( V_15 ) ;
}
}
V_15 += ( V_111 & ~ V_98 ) >> V_6 ;
F_89 ( ! F_90 ( V_15 ) , V_15 ) ;
if ( V_97 & V_148 )
F_183 ( V_15 ) ;
V_71:
return V_15 ;
}
int F_184 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_111 , T_1 V_17 , T_1 * V_149 )
{
T_7 * V_87 ;
struct V_118 * V_118 = NULL ;
struct V_15 * V_15 ;
unsigned long V_83 = V_111 & V_98 ;
int V_150 = - 1 , V_151 = F_119 () ;
int V_152 , V_153 = - 1 ;
bool V_154 ;
bool V_155 = false ;
int V_97 = 0 ;
V_87 = F_96 ( V_82 , V_149 ) ;
if ( F_10 ( ! F_133 ( V_17 , * V_149 ) ) )
goto V_117;
if ( F_10 ( F_185 ( * V_149 ) ) ) {
F_98 ( V_87 ) ;
F_186 ( V_76 -> V_118 , V_149 ) ;
goto V_71;
}
V_15 = F_20 ( V_17 ) ;
F_33 ( F_17 ( V_15 ) ) ;
V_150 = F_145 ( V_15 ) ;
V_153 = F_187 ( V_15 ) ;
F_188 ( V_156 ) ;
if ( V_150 == V_151 ) {
F_188 ( V_157 ) ;
V_97 |= V_158 ;
}
if ( ! F_176 ( V_17 ) )
V_97 |= V_159 ;
V_154 = F_179 ( V_15 ) ;
V_152 = F_189 ( V_15 , V_76 , V_83 ) ;
if ( V_152 == - 1 ) {
if ( V_154 )
goto V_160;
}
if ( ! V_154 ) {
F_98 ( V_87 ) ;
F_190 ( V_15 ) ;
V_150 = - 1 ;
goto V_71;
}
F_127 ( V_15 ) ;
F_98 ( V_87 ) ;
V_118 = F_191 ( V_15 ) ;
F_167 ( V_87 ) ;
if ( F_10 ( ! F_133 ( V_17 , * V_149 ) ) ) {
F_182 ( V_15 ) ;
F_99 ( V_15 ) ;
V_150 = - 1 ;
goto V_117;
}
if ( F_10 ( ! V_118 ) ) {
F_99 ( V_15 ) ;
V_150 = - 1 ;
goto V_160;
}
F_98 ( V_87 ) ;
V_155 = F_192 ( V_82 , V_76 ,
V_149 , V_17 , V_111 , V_15 , V_152 ) ;
if ( V_155 ) {
V_97 |= V_161 ;
V_150 = V_152 ;
}
goto V_71;
V_160:
F_33 ( ! F_193 ( V_15 ) ) ;
V_17 = F_194 ( V_17 ) ;
F_106 ( V_82 , V_83 , V_149 , V_17 ) ;
F_42 ( F_178 ( * V_149 ) ) ;
F_136 ( V_76 , V_111 , V_149 ) ;
F_182 ( V_15 ) ;
V_117:
F_98 ( V_87 ) ;
V_71:
if ( V_118 )
F_195 ( V_118 ) ;
if ( V_150 != - 1 )
F_196 ( V_153 , V_150 , V_31 , V_97 ) ;
return 0 ;
}
int F_197 ( struct V_162 * V_163 , struct V_75 * V_76 ,
T_1 * V_17 , unsigned long V_111 )
{
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_198 ( V_17 , V_76 , & V_87 ) == 1 ) {
struct V_15 * V_15 ;
T_6 V_86 ;
T_1 V_119 ;
V_119 = F_199 ( V_163 -> V_82 , V_111 , V_17 ,
V_163 -> V_164 ) ;
F_200 ( V_163 , V_17 , V_111 ) ;
V_86 = F_153 ( V_163 -> V_82 , V_17 ) ;
if ( F_19 ( V_119 ) ) {
F_201 ( & V_163 -> V_82 -> V_91 ) ;
F_98 ( V_87 ) ;
F_32 () ;
} else {
V_15 = F_20 ( V_119 ) ;
F_163 ( V_15 ) ;
F_89 ( F_168 ( V_15 ) < 0 , V_15 ) ;
F_107 ( V_163 -> V_82 , V_90 , - V_31 ) ;
F_89 ( ! F_126 ( V_15 ) , V_15 ) ;
F_201 ( & V_163 -> V_82 -> V_91 ) ;
F_98 ( V_87 ) ;
F_202 ( V_163 , V_15 ) ;
}
F_100 ( V_163 -> V_82 , V_86 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_203 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_111 , unsigned long V_165 ,
unsigned char * V_166 )
{
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_198 ( V_17 , V_76 , & V_87 ) == 1 ) {
F_98 ( V_87 ) ;
memset ( V_166 , 1 , ( V_165 - V_111 ) >> V_6 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_204 ( struct V_75 * V_76 , struct V_75 * V_167 ,
unsigned long V_168 ,
unsigned long V_169 , unsigned long V_170 ,
T_1 * V_171 , T_1 * V_172 )
{
T_7 * V_173 , * V_174 ;
int V_45 = 0 ;
T_1 V_17 ;
struct V_81 * V_82 = V_76 -> V_139 ;
if ( ( V_168 & ~ V_98 ) ||
( V_169 & ~ V_98 ) ||
V_170 - V_168 < V_100 ||
( V_167 -> V_77 & V_175 ) )
goto V_71;
if ( F_205 ( ! F_97 ( * V_172 ) ) ) {
F_42 ( F_123 ( * V_172 ) ) ;
goto V_71;
}
V_45 = F_198 ( V_171 , V_76 , & V_173 ) ;
if ( V_45 == 1 ) {
V_174 = F_121 ( V_82 , V_172 ) ;
if ( V_174 != V_173 )
F_122 ( V_174 , V_115 ) ;
V_17 = F_206 ( V_82 , V_168 , V_171 ) ;
F_42 ( ! F_97 ( * V_172 ) ) ;
if ( F_207 ( V_174 , V_173 ) ) {
T_6 V_86 ;
V_86 = F_153 ( V_82 , V_171 ) ;
F_105 ( V_82 , V_172 , V_86 ) ;
}
F_106 ( V_82 , V_169 , V_172 , F_208 ( V_17 ) ) ;
if ( V_174 != V_173 )
F_98 ( V_174 ) ;
F_98 ( V_173 ) ;
}
V_71:
return V_45 ;
}
int F_209 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_111 , T_5 V_176 , int V_177 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_198 ( V_17 , V_76 , & V_87 ) == 1 ) {
T_1 V_80 ;
V_45 = 1 ;
if ( ! V_177 ) {
V_80 = F_210 ( V_82 , V_111 , V_17 ) ;
if ( F_178 ( V_80 ) )
V_80 = F_194 ( V_80 ) ;
V_80 = F_211 ( V_80 , V_176 ) ;
V_45 = V_31 ;
F_106 ( V_82 , V_111 , V_17 , V_80 ) ;
F_33 ( F_176 ( V_80 ) ) ;
} else {
struct V_15 * V_15 = F_20 ( * V_17 ) ;
if ( ! F_17 ( V_15 ) &&
! F_178 ( * V_17 ) ) {
F_212 ( V_82 , V_111 , V_17 ) ;
V_45 = V_31 ;
}
}
F_98 ( V_87 ) ;
}
return V_45 ;
}
int F_198 ( T_1 * V_17 , struct V_75 * V_76 ,
T_7 * * V_87 )
{
* V_87 = F_96 ( V_76 -> V_139 , V_17 ) ;
if ( F_22 ( F_123 ( * V_17 ) ) ) {
if ( F_10 ( F_124 ( * V_17 ) ) ) {
F_98 ( * V_87 ) ;
F_125 ( V_76 -> V_118 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_98 ( * V_87 ) ;
return 0 ;
}
T_1 * F_213 ( struct V_15 * V_15 ,
struct V_81 * V_82 ,
unsigned long V_96 ,
enum V_178 V_47 ,
T_7 * * V_87 )
{
T_10 * V_179 ;
T_11 * V_180 ;
T_1 * V_17 ;
if ( V_96 & ~ V_98 )
return NULL ;
V_179 = F_214 ( V_82 , V_96 ) ;
if ( ! F_215 ( * V_179 ) )
return NULL ;
V_180 = F_216 ( V_179 , V_96 ) ;
if ( ! F_217 ( * V_180 ) )
return NULL ;
V_17 = F_218 ( V_180 , V_96 ) ;
* V_87 = F_96 ( V_82 , V_17 ) ;
if ( ! F_219 ( * V_17 ) )
goto V_121;
if ( F_20 ( * V_17 ) != V_15 )
goto V_121;
if ( V_47 == V_181 &&
F_124 ( * V_17 ) )
goto V_121;
if ( F_123 ( * V_17 ) ) {
F_42 ( V_47 == V_182 &&
! F_124 ( * V_17 ) ) ;
return V_17 ;
}
V_121:
F_98 ( * V_87 ) ;
return NULL ;
}
static int F_220 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_17 ;
int V_45 = 0 ;
const unsigned long V_127 = V_96 ;
const unsigned long V_128 = V_96 + V_100 ;
F_151 ( V_82 , V_127 , V_128 ) ;
V_17 = F_213 ( V_15 , V_82 , V_96 ,
V_181 , & V_87 ) ;
if ( V_17 ) {
F_221 ( V_76 , V_96 , V_17 ) ;
V_45 = 1 ;
F_98 ( V_87 ) ;
}
F_164 ( V_82 , V_127 , V_128 ) ;
return V_45 ;
}
static void F_222 ( struct V_15 * V_15 ,
struct V_183 * V_184 )
{
int V_126 ;
struct V_1 * V_1 = F_223 ( V_15 ) ;
struct V_185 * V_185 ;
int V_186 = 0 ;
F_224 ( & V_1 -> V_187 ) ;
V_185 = F_225 ( V_15 , V_1 ) ;
F_226 ( V_15 ) ;
F_227 ( V_15 ) ;
for ( V_126 = V_31 - 1 ; V_126 >= 1 ; V_126 -- ) {
struct V_15 * V_188 = V_15 + V_126 ;
F_33 ( F_168 ( V_188 ) < 0 ) ;
V_186 += F_168 ( V_188 ) ;
F_33 ( V_186 < 0 ) ;
F_33 ( F_36 ( & V_188 -> V_124 ) != 0 ) ;
F_139 ( F_168 ( V_15 ) + F_168 ( V_188 ) + 1 ,
& V_188 -> V_124 ) ;
F_228 () ;
V_188 -> V_97 &= ~ V_189 | V_190 ;
V_188 -> V_97 |= ( V_15 -> V_97 &
( ( 1L << V_191 ) |
( 1L << V_192 ) |
( 1L << V_193 ) |
( 1L << V_194 ) |
( 1L << V_195 ) |
( 1L << V_196 ) ) ) ;
V_188 -> V_97 |= ( 1L << V_197 ) ;
F_162 () ;
V_188 -> V_198 = V_15 -> V_198 ;
F_33 ( V_188 -> V_147 ) ;
V_188 -> V_147 = V_15 -> V_147 ;
V_188 -> V_199 = V_15 -> V_199 + V_126 ;
F_229 ( V_188 , F_187 ( V_15 ) ) ;
F_33 ( ! F_230 ( V_188 ) ) ;
F_33 ( ! F_231 ( V_188 ) ) ;
F_33 ( ! F_232 ( V_188 ) ) ;
F_33 ( ! F_233 ( V_188 ) ) ;
F_234 ( V_15 , V_188 , V_185 , V_184 ) ;
}
F_235 ( V_186 , & V_15 -> V_124 ) ;
F_33 ( F_36 ( & V_15 -> V_124 ) <= 0 ) ;
F_236 ( V_1 , V_200 , - 1 ) ;
F_237 ( V_15 ) ;
F_238 ( V_15 ) ;
F_239 ( & V_1 -> V_187 ) ;
for ( V_126 = 1 ; V_126 < V_31 ; V_126 ++ ) {
struct V_15 * V_188 = V_15 + V_126 ;
F_33 ( F_240 ( V_188 ) <= 0 ) ;
F_99 ( V_188 ) ;
}
F_33 ( F_240 ( V_15 ) <= 0 ) ;
}
static int F_241 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_17 , V_125 ;
int V_45 = 0 , V_126 ;
T_6 V_86 ;
unsigned long V_83 ;
V_17 = F_213 ( V_15 , V_82 , V_96 ,
V_182 , & V_87 ) ;
if ( V_17 ) {
V_86 = F_153 ( V_82 , V_17 ) ;
F_154 ( V_82 , & V_125 , V_86 ) ;
if ( F_176 ( * V_17 ) )
F_33 ( F_168 ( V_15 ) != 1 ) ;
V_83 = V_96 ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
F_33 ( F_90 ( V_15 + V_126 ) ) ;
V_80 = F_155 ( V_15 + V_126 , V_76 -> V_89 ) ;
V_80 = F_156 ( F_157 ( V_80 ) , V_76 ) ;
if ( ! F_176 ( * V_17 ) )
V_80 = F_242 ( V_80 ) ;
if ( ! F_243 ( * V_17 ) )
V_80 = F_244 ( V_80 ) ;
V_134 = F_158 ( & V_125 , V_83 ) ;
F_33 ( ! F_159 ( * V_134 ) ) ;
F_160 ( V_82 , V_83 , V_134 , V_80 ) ;
F_161 ( V_134 ) ;
}
F_162 () ;
F_245 ( V_76 , V_96 , V_17 ) ;
F_154 ( V_82 , V_17 , V_86 ) ;
V_45 = 1 ;
F_98 ( V_87 ) ;
}
return V_45 ;
}
static void F_246 ( struct V_15 * V_15 ,
struct V_118 * V_118 ,
struct V_183 * V_184 )
{
int V_201 , V_202 ;
T_12 V_203 = V_15 -> V_199 << ( V_204 - V_6 ) ;
struct V_205 * V_206 ;
F_33 ( ! F_126 ( V_15 ) ) ;
F_33 ( F_247 ( V_15 ) ) ;
V_201 = 0 ;
F_248 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_206 -> V_76 ;
unsigned long V_111 = F_249 ( V_15 , V_76 ) ;
F_33 ( F_250 ( V_76 ) ) ;
V_201 += F_220 ( V_15 , V_76 , V_111 ) ;
}
if ( V_201 != F_168 ( V_15 ) ) {
F_12 ( L_17 ,
V_201 , F_168 ( V_15 ) ) ;
F_251 () ;
}
F_222 ( V_15 , V_184 ) ;
V_202 = 0 ;
F_248 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_206 -> V_76 ;
unsigned long V_111 = F_249 ( V_15 , V_76 ) ;
F_33 ( F_250 ( V_76 ) ) ;
V_202 += F_241 ( V_15 , V_76 , V_111 ) ;
}
if ( V_201 != V_202 ) {
F_12 ( L_18 ,
V_201 , V_202 , F_168 ( V_15 ) ) ;
F_251 () ;
}
}
int F_252 ( struct V_15 * V_15 , struct V_183 * V_184 )
{
struct V_118 * V_118 ;
int V_45 = 1 ;
F_33 ( F_17 ( V_15 ) ) ;
F_33 ( ! F_230 ( V_15 ) ) ;
V_118 = F_253 ( V_15 ) ;
if ( ! V_118 )
goto V_71;
F_254 ( V_118 ) ;
V_45 = 0 ;
if ( ! F_90 ( V_15 ) )
goto V_117;
F_33 ( ! F_233 ( V_15 ) ) ;
F_246 ( V_15 , V_118 , V_184 ) ;
F_25 ( V_207 ) ;
F_33 ( F_90 ( V_15 ) ) ;
V_117:
F_255 ( V_118 ) ;
F_256 ( V_118 ) ;
V_71:
return V_45 ;
}
int F_257 ( struct V_75 * V_76 ,
unsigned long * V_77 , int V_208 )
{
switch ( V_208 ) {
case V_209 :
#ifdef F_258
if ( F_259 ( V_76 -> V_139 ) )
return 0 ;
#endif
if ( * V_77 & ( V_210 | V_211 ) )
return - V_42 ;
* V_77 &= ~ V_175 ;
* V_77 |= V_210 ;
if ( F_10 ( F_260 ( V_76 , * V_77 ) ) )
return - V_66 ;
break;
case V_212 :
if ( * V_77 & ( V_175 | V_211 ) )
return - V_42 ;
* V_77 &= ~ V_210 ;
* V_77 |= V_175 ;
break;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
V_213 = F_261 ( L_19 ,
sizeof( struct V_214 ) ,
F_262 ( struct V_214 ) , 0 , NULL ) ;
if ( ! V_213 )
return - V_66 ;
return 0 ;
}
static inline struct V_214 * F_263 ( void )
{
if ( ! V_213 )
return NULL ;
return F_264 ( V_213 , V_129 ) ;
}
static inline void F_265 ( struct V_214 * V_214 )
{
F_266 ( V_213 , V_214 ) ;
}
static struct V_214 * F_267 ( struct V_81 * V_82 )
{
struct V_214 * V_214 ;
F_268 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_82 == V_214 -> V_82 )
return V_214 ;
return NULL ;
}
static void F_269 ( struct V_81 * V_82 ,
struct V_214 * V_214 )
{
V_214 -> V_82 = V_82 ;
F_270 ( V_215 , & V_214 -> V_216 , ( long ) V_82 ) ;
}
static inline int F_271 ( struct V_81 * V_82 )
{
return F_36 ( & V_82 -> V_217 ) == 0 ;
}
int F_272 ( struct V_81 * V_82 )
{
struct V_214 * V_214 ;
int V_218 ;
V_214 = F_263 () ;
if ( ! V_214 )
return - V_66 ;
F_273 ( F_271 ( V_82 ) , V_82 ) ;
if ( F_10 ( F_274 ( V_219 , & V_82 -> V_97 ) ) ) {
F_265 ( V_214 ) ;
return 0 ;
}
F_167 ( & V_220 ) ;
F_269 ( V_82 , V_214 ) ;
V_218 = F_14 ( & V_12 . V_13 ) ;
F_275 ( & V_214 -> V_221 , & V_12 . V_13 ) ;
F_98 ( & V_220 ) ;
F_276 ( & V_82 -> V_222 ) ;
if ( V_218 )
F_15 ( & V_14 ) ;
return 0 ;
}
int F_260 ( struct V_75 * V_76 ,
unsigned long V_77 )
{
unsigned long V_223 , V_224 ;
if ( ! V_76 -> V_118 )
return 0 ;
if ( V_76 -> V_225 )
return 0 ;
F_166 ( V_77 & V_211 , V_76 ) ;
V_223 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_224 = V_76 -> V_101 & V_98 ;
if ( V_223 < V_224 )
return F_115 ( V_76 , V_77 ) ;
return 0 ;
}
void F_277 ( struct V_81 * V_82 )
{
struct V_214 * V_214 ;
int free = 0 ;
F_167 ( & V_220 ) ;
V_214 = F_267 ( V_82 ) ;
if ( V_214 && V_12 . V_214 != V_214 ) {
F_278 ( & V_214 -> V_216 ) ;
F_279 ( & V_214 -> V_221 ) ;
free = 1 ;
}
F_98 ( & V_220 ) ;
if ( free ) {
F_45 ( V_219 , & V_82 -> V_97 ) ;
F_265 ( V_214 ) ;
F_280 ( V_82 ) ;
} else if ( V_214 ) {
F_281 ( & V_82 -> V_226 ) ;
F_282 ( & V_82 -> V_226 ) ;
}
}
static void F_283 ( struct V_15 * V_15 )
{
F_284 ( V_15 , V_227 + 0 ) ;
F_182 ( V_15 ) ;
F_285 ( V_15 ) ;
}
static void F_286 ( T_9 * V_134 , T_9 * V_228 )
{
while ( -- V_228 >= V_134 ) {
T_9 V_229 = * V_228 ;
if ( ! F_159 ( V_229 ) )
F_283 ( F_287 ( V_229 ) ) ;
}
}
static int F_288 ( struct V_75 * V_76 ,
unsigned long V_96 ,
T_9 * V_134 )
{
struct V_15 * V_15 ;
T_9 * V_228 ;
int V_230 = 0 , V_231 = 0 ;
for ( V_228 = V_134 ; V_228 < V_134 + V_31 ;
V_228 ++ , V_96 += V_132 ) {
T_9 V_229 = * V_228 ;
if ( F_159 ( V_229 ) ) {
if ( ++ V_231 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_289 ( V_229 ) || ! F_290 ( V_229 ) )
goto V_71;
V_15 = F_291 ( V_76 , V_96 , V_229 ) ;
if ( F_10 ( ! V_15 ) )
goto V_71;
F_89 ( F_90 ( V_15 ) , V_15 ) ;
F_89 ( ! F_230 ( V_15 ) , V_15 ) ;
F_89 ( ! F_233 ( V_15 ) , V_15 ) ;
if ( F_240 ( V_15 ) != 1 )
goto V_71;
if ( ! F_179 ( V_15 ) )
goto V_71;
if ( F_292 ( V_15 ) ) {
F_182 ( V_15 ) ;
goto V_71;
}
F_293 ( V_15 , V_227 + 0 ) ;
F_89 ( ! F_193 ( V_15 ) , V_15 ) ;
F_89 ( F_294 ( V_15 ) , V_15 ) ;
if ( F_295 ( V_229 ) || F_296 ( V_15 ) ||
F_297 ( V_76 -> V_139 , V_96 ) )
V_230 = 1 ;
}
if ( F_22 ( V_230 ) )
return 1 ;
V_71:
F_286 ( V_134 , V_228 ) ;
return 0 ;
}
static void F_298 ( T_9 * V_134 , struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
T_7 * V_87 )
{
T_9 * V_228 ;
for ( V_228 = V_134 ; V_228 < V_134 + V_31 ; V_228 ++ ) {
T_9 V_229 = * V_228 ;
struct V_15 * V_114 ;
if ( F_159 ( V_229 ) ) {
F_299 ( V_15 , V_96 ) ;
F_107 ( V_76 -> V_139 , V_90 , 1 ) ;
} else {
V_114 = F_287 ( V_229 ) ;
F_149 ( V_15 , V_114 , V_96 , V_76 ) ;
F_89 ( F_168 ( V_114 ) != 1 , V_114 ) ;
F_283 ( V_114 ) ;
F_167 ( V_87 ) ;
F_300 ( V_76 -> V_139 , V_96 , V_228 ) ;
F_163 ( V_114 ) ;
F_98 ( V_87 ) ;
F_301 ( V_114 ) ;
}
V_96 += V_132 ;
V_15 ++ ;
}
}
static void F_302 ( void )
{
F_303 ( V_14 , false ,
F_304 ( V_56 ) ) ;
}
static bool F_305 ( int V_232 )
{
int V_126 ;
if ( ! V_233 )
return false ;
if ( V_234 [ V_232 ] )
return false ;
for ( V_126 = 0 ; V_126 < V_235 ; V_126 ++ ) {
if ( ! V_234 [ V_126 ] )
continue;
if ( F_306 ( V_232 , V_126 ) > V_236 )
return true ;
}
return false ;
}
static int F_307 ( void )
{
static int V_237 = V_238 ;
int V_232 , V_239 = 0 , V_240 = 0 ;
for ( V_232 = 0 ; V_232 < V_235 ; V_232 ++ )
if ( V_234 [ V_232 ] > V_240 ) {
V_240 = V_234 [ V_232 ] ;
V_239 = V_232 ;
}
if ( V_239 <= V_237 )
for ( V_232 = V_237 + 1 ; V_232 < V_235 ;
V_232 ++ )
if ( V_240 == V_234 [ V_232 ] ) {
V_239 = V_232 ;
break;
}
V_237 = V_239 ;
return V_239 ;
}
static bool F_308 ( struct V_15 * * V_241 , bool * V_242 )
{
if ( F_11 ( * V_241 ) ) {
if ( ! * V_242 )
return false ;
* V_242 = false ;
* V_241 = NULL ;
F_302 () ;
} else if ( * V_241 ) {
F_99 ( * V_241 ) ;
* V_241 = NULL ;
}
return true ;
}
static struct V_15
* F_309 ( struct V_15 * * V_241 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_96 ,
int V_243 )
{
F_89 ( * V_241 , * V_241 ) ;
F_310 ( & V_82 -> V_226 ) ;
* V_241 = F_311 ( V_243 , F_109 (
F_312 () , V_131 ) , V_24 ) ;
if ( F_10 ( ! * V_241 ) ) {
F_25 ( V_244 ) ;
* V_241 = F_177 ( - V_66 ) ;
return NULL ;
}
F_25 ( V_245 ) ;
return * V_241 ;
}
static int F_307 ( void )
{
return 0 ;
}
static inline struct V_15 * F_313 ( int V_92 )
{
return F_24 ( F_109 ( V_92 , 0 ) ,
V_24 ) ;
}
static struct V_15 * F_314 ( bool * V_242 )
{
struct V_15 * V_241 ;
do {
V_241 = F_313 ( F_312 () ) ;
if ( ! V_241 ) {
F_25 ( V_244 ) ;
if ( ! * V_242 )
return NULL ;
* V_242 = false ;
F_302 () ;
} else
F_25 ( V_245 ) ;
} while ( F_10 ( ! V_241 ) && F_22 ( F_2 () ) );
return V_241 ;
}
static bool F_308 ( struct V_15 * * V_241 , bool * V_242 )
{
if ( ! * V_241 )
* V_241 = F_314 ( V_242 ) ;
if ( F_10 ( ! * V_241 ) )
return false ;
return true ;
}
static struct V_15
* F_309 ( struct V_15 * * V_241 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_96 ,
int V_243 )
{
F_310 ( & V_82 -> V_226 ) ;
F_42 ( ! * V_241 ) ;
return * V_241 ;
}
static bool F_315 ( struct V_75 * V_76 )
{
if ( ( ! ( V_76 -> V_77 & V_210 ) && ! F_316 () ) ||
( V_76 -> V_77 & V_175 ) )
return false ;
if ( ! V_76 -> V_118 || V_76 -> V_225 )
return false ;
if ( F_250 ( V_76 ) )
return false ;
F_166 ( V_76 -> V_77 & V_211 , V_76 ) ;
return true ;
}
static void F_317 ( struct V_81 * V_82 ,
unsigned long V_96 ,
struct V_15 * * V_241 ,
struct V_75 * V_76 ,
int V_243 )
{
T_1 * V_17 , V_125 ;
T_9 * V_134 ;
T_6 V_86 ;
struct V_15 * V_136 ;
T_7 * V_246 , * V_247 ;
int V_248 ;
unsigned long V_223 , V_224 ;
struct V_84 * V_85 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_42 ( V_96 & ~ V_98 ) ;
V_136 = F_309 ( V_241 , V_82 , V_76 , V_96 , V_243 ) ;
if ( ! V_136 )
return;
if ( F_10 ( F_91 ( V_136 , V_82 ,
V_21 , & V_85 ) ) )
return;
F_281 ( & V_82 -> V_226 ) ;
if ( F_10 ( F_271 ( V_82 ) ) )
goto V_71;
V_76 = F_318 ( V_82 , V_96 ) ;
if ( ! V_76 )
goto V_71;
V_223 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_224 = V_76 -> V_101 & V_98 ;
if ( V_96 < V_223 || V_96 + V_100 > V_224 )
goto V_71;
if ( ! F_315 ( V_76 ) )
goto V_71;
V_17 = F_319 ( V_82 , V_96 ) ;
if ( ! V_17 )
goto V_71;
F_254 ( V_76 -> V_118 ) ;
V_134 = F_158 ( V_17 , V_96 ) ;
V_247 = F_320 ( V_82 , V_17 ) ;
V_127 = V_96 ;
V_128 = V_96 + V_100 ;
F_151 ( V_82 , V_127 , V_128 ) ;
V_246 = F_96 ( V_82 , V_17 ) ;
V_125 = F_321 ( V_76 , V_96 , V_17 ) ;
F_98 ( V_246 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
F_167 ( V_247 ) ;
V_248 = F_288 ( V_76 , V_96 , V_134 ) ;
F_98 ( V_247 ) ;
if ( F_10 ( ! V_248 ) ) {
F_161 ( V_134 ) ;
F_167 ( V_246 ) ;
F_33 ( ! F_97 ( * V_17 ) ) ;
F_154 ( V_82 , V_17 , F_322 ( V_125 ) ) ;
F_98 ( V_246 ) ;
F_255 ( V_76 -> V_118 ) ;
goto V_71;
}
F_255 ( V_76 -> V_118 ) ;
F_298 ( V_134 , V_136 , V_76 , V_96 , V_247 ) ;
F_161 ( V_134 ) ;
F_95 ( V_136 ) ;
V_86 = F_322 ( V_125 ) ;
V_125 = F_85 ( V_136 , V_76 -> V_89 ) ;
V_125 = F_83 ( F_101 ( V_125 ) , V_76 ) ;
F_162 () ;
F_167 ( V_246 ) ;
F_33 ( ! F_97 ( * V_17 ) ) ;
F_102 ( V_136 , V_76 , V_96 ) ;
F_103 ( V_136 , V_85 , false ) ;
F_104 ( V_136 , V_76 ) ;
F_105 ( V_82 , V_17 , V_86 ) ;
F_106 ( V_82 , V_96 , V_17 , V_125 ) ;
F_136 ( V_76 , V_96 , V_17 ) ;
F_98 ( V_246 ) ;
* V_241 = NULL ;
V_59 ++ ;
V_249:
F_282 ( & V_82 -> V_226 ) ;
return;
V_71:
F_93 ( V_136 , V_85 ) ;
goto V_249;
}
static int F_323 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
struct V_15 * * V_241 )
{
T_1 * V_17 ;
T_9 * V_134 , * V_228 ;
int V_45 = 0 , V_230 = 0 , V_231 = 0 ;
struct V_15 * V_15 ;
unsigned long V_250 ;
T_7 * V_87 ;
int V_243 = V_238 ;
F_42 ( V_96 & ~ V_98 ) ;
V_17 = F_319 ( V_82 , V_96 ) ;
if ( ! V_17 )
goto V_71;
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
V_134 = F_324 ( V_82 , V_17 , V_96 , & V_87 ) ;
for ( V_250 = V_96 , V_228 = V_134 ; V_228 < V_134 + V_31 ;
V_228 ++ , V_250 += V_132 ) {
T_9 V_229 = * V_228 ;
if ( F_159 ( V_229 ) ) {
if ( ++ V_231 <= V_62 )
continue;
else
goto V_251;
}
if ( ! F_289 ( V_229 ) || ! F_290 ( V_229 ) )
goto V_251;
V_15 = F_291 ( V_76 , V_250 , V_229 ) ;
if ( F_10 ( ! V_15 ) )
goto V_251;
V_243 = F_145 ( V_15 ) ;
if ( F_305 ( V_243 ) )
goto V_251;
V_234 [ V_243 ] ++ ;
F_89 ( F_90 ( V_15 ) , V_15 ) ;
if ( ! F_294 ( V_15 ) || F_193 ( V_15 ) || ! F_230 ( V_15 ) )
goto V_251;
if ( F_240 ( V_15 ) != 1 )
goto V_251;
if ( F_295 ( V_229 ) || F_296 ( V_15 ) ||
F_297 ( V_76 -> V_139 , V_96 ) )
V_230 = 1 ;
}
if ( V_230 )
V_45 = 1 ;
V_251:
F_325 ( V_134 , V_87 ) ;
if ( V_45 ) {
V_243 = F_307 () ;
F_317 ( V_82 , V_96 , V_241 , V_76 , V_243 ) ;
}
V_71:
return V_45 ;
}
static void F_326 ( struct V_214 * V_214 )
{
struct V_81 * V_82 = V_214 -> V_82 ;
F_42 ( V_252 != 1 && ! F_327 ( & V_220 ) ) ;
if ( F_271 ( V_82 ) ) {
F_278 ( & V_214 -> V_216 ) ;
F_279 ( & V_214 -> V_221 ) ;
F_265 ( V_214 ) ;
F_280 ( V_82 ) ;
}
}
static unsigned int F_328 ( unsigned int V_58 ,
struct V_15 * * V_241 )
__releases( &khugepaged_mm_lock
static int F_329 ( void )
{
return ! F_14 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_330 ( void )
{
return ! F_14 ( & V_12 . V_13 ) ||
F_331 () ;
}
static void F_332 ( void )
{
struct V_15 * V_241 = NULL ;
unsigned int V_253 = 0 , V_254 = 0 ;
unsigned int V_58 = V_57 ;
bool V_242 = true ;
F_333 () ;
while ( V_253 < V_58 ) {
if ( ! F_308 ( & V_241 , & V_242 ) )
break;
F_150 () ;
if ( F_10 ( F_331 () || F_334 ( V_255 ) ) )
break;
F_167 ( & V_220 ) ;
if ( ! V_12 . V_214 )
V_254 ++ ;
if ( F_329 () &&
V_254 < 2 )
V_253 += F_328 ( V_58 - V_253 ,
& V_241 ) ;
else
V_253 = V_58 ;
F_98 ( & V_220 ) ;
}
if ( ! F_335 ( V_241 ) )
F_99 ( V_241 ) ;
}
static void F_336 ( void )
{
F_337 () ;
if ( F_329 () ) {
if ( ! V_53 )
return;
F_303 ( V_14 ,
F_331 () ,
F_304 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_338 ( V_14 , F_330 () ) ;
}
static int V_11 ( void * V_231 )
{
struct V_214 * V_214 ;
F_339 () ;
F_340 ( V_255 , V_256 ) ;
while ( ! F_331 () ) {
F_332 () ;
F_336 () ;
}
F_167 ( & V_220 ) ;
V_214 = V_12 . V_214 ;
V_12 . V_214 = NULL ;
if ( V_214 )
F_326 ( V_214 ) ;
F_98 ( & V_220 ) ;
return 0 ;
}
static void F_341 ( struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_17 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_6 V_86 ;
T_1 V_125 ;
int V_126 ;
F_152 ( V_76 , V_83 , V_17 ) ;
V_86 = F_153 ( V_82 , V_17 ) ;
F_154 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_342 ( F_343 ( V_83 ) , V_76 -> V_89 ) ;
V_80 = F_344 ( V_80 ) ;
V_134 = F_158 ( & V_125 , V_83 ) ;
F_42 ( ! F_159 ( * V_134 ) ) ;
F_160 ( V_82 , V_83 , V_134 , V_80 ) ;
F_161 ( V_134 ) ;
}
F_162 () ;
F_154 ( V_82 , V_17 , V_86 ) ;
F_32 () ;
}
void F_345 ( struct V_75 * V_76 , unsigned long V_96 ,
T_1 * V_17 )
{
T_7 * V_87 ;
struct V_15 * V_15 ;
struct V_81 * V_82 = V_76 -> V_139 ;
unsigned long V_83 = V_96 & V_98 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_33 ( V_76 -> V_99 > V_83 || V_76 -> V_101 < V_83 + V_100 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
V_257:
F_151 ( V_82 , V_127 , V_128 ) ;
V_87 = F_96 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_123 ( * V_17 ) ) ) {
F_98 ( V_87 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
return;
}
if ( F_19 ( * V_17 ) ) {
F_341 ( V_76 , V_83 , V_17 ) ;
F_98 ( V_87 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
return;
}
V_15 = F_20 ( * V_17 ) ;
F_89 ( ! F_240 ( V_15 ) , V_15 ) ;
F_127 ( V_15 ) ;
F_98 ( V_87 ) ;
F_164 ( V_82 , V_127 , V_128 ) ;
F_172 ( V_15 ) ;
F_99 ( V_15 ) ;
if ( F_10 ( F_123 ( * V_17 ) ) )
goto V_257;
}
void F_346 ( struct V_81 * V_82 , unsigned long V_96 ,
T_1 * V_17 )
{
struct V_75 * V_76 ;
V_76 = F_318 ( V_82 , V_96 ) ;
F_33 ( V_76 == NULL ) ;
F_171 ( V_76 , V_96 , V_17 ) ;
}
static void F_347 ( struct V_81 * V_82 ,
unsigned long V_96 )
{
T_10 * V_179 ;
T_11 * V_180 ;
T_1 * V_17 ;
F_42 ( ! ( V_96 & ~ V_98 ) ) ;
V_179 = F_214 ( V_82 , V_96 ) ;
if ( ! F_215 ( * V_179 ) )
return;
V_180 = F_216 ( V_179 , V_96 ) ;
if ( ! F_217 ( * V_180 ) )
return;
V_17 = F_218 ( V_180 , V_96 ) ;
if ( ! F_219 ( * V_17 ) )
return;
F_346 ( V_82 , V_96 , V_17 ) ;
}
void F_348 ( struct V_75 * V_76 ,
unsigned long V_258 ,
unsigned long V_165 ,
long V_259 )
{
if ( V_258 & ~ V_98 &&
( V_258 & V_98 ) >= V_76 -> V_99 &&
( V_258 & V_98 ) + V_100 <= V_76 -> V_101 )
F_347 ( V_76 -> V_139 , V_258 ) ;
if ( V_165 & ~ V_98 &&
( V_165 & V_98 ) >= V_76 -> V_99 &&
( V_165 & V_98 ) + V_100 <= V_76 -> V_101 )
F_347 ( V_76 -> V_139 , V_165 ) ;
if ( V_259 > 0 ) {
struct V_75 * V_260 = V_76 -> V_261 ;
unsigned long V_262 = V_260 -> V_99 ;
V_262 += V_259 << V_6 ;
if ( V_262 & ~ V_98 &&
( V_262 & V_98 ) >= V_260 -> V_99 &&
( V_262 & V_98 ) + V_100 <= V_260 -> V_101 )
F_347 ( V_260 -> V_139 , V_262 ) ;
}
}
