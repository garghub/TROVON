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
struct V_84 * V_85 ;
T_6 V_86 ;
T_7 * V_87 ;
F_88 ( ! F_89 ( V_15 ) , V_15 ) ;
if ( F_90 ( V_15 , V_82 , V_21 , & V_85 ) )
return V_88 ;
V_86 = F_91 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) ) {
F_92 ( V_15 , V_85 ) ;
return V_88 ;
}
F_93 ( V_15 , V_83 , V_31 ) ;
F_94 ( V_15 ) ;
V_87 = F_95 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_96 ( * V_17 ) ) ) {
F_97 ( V_87 ) ;
F_92 ( V_15 , V_85 ) ;
F_98 ( V_15 ) ;
F_99 ( V_82 , V_86 ) ;
} else {
T_1 V_80 ;
V_80 = F_84 ( V_15 , V_76 -> V_89 ) ;
V_80 = F_82 ( F_100 ( V_80 ) , V_76 ) ;
F_101 ( V_15 , V_76 , V_83 ) ;
F_102 ( V_15 , V_85 , false ) ;
F_103 ( V_15 , V_76 ) ;
F_104 ( V_82 , V_17 , V_86 ) ;
F_105 ( V_82 , V_83 , V_17 , V_80 ) ;
F_106 ( V_82 , V_90 , V_31 ) ;
F_107 ( & V_82 -> V_91 ) ;
F_97 ( V_87 ) ;
}
return 0 ;
}
static inline T_8 F_108 ( int V_92 , T_8 V_93 )
{
return ( V_21 & ~ ( V_92 ? 0 : V_94 ) ) | V_93 ;
}
static inline struct V_15 * F_109 ( int V_92 ,
struct V_75 * V_76 ,
unsigned long V_83 , int V_95 ,
T_8 V_93 )
{
return F_110 ( F_108 ( V_92 , V_93 ) ,
V_24 , V_76 , V_83 , V_95 ) ;
}
static bool F_111 ( T_6 V_86 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_83 , T_1 * V_17 ,
struct V_15 * V_18 )
{
T_1 V_80 ;
if ( ! F_96 ( * V_17 ) )
return false ;
V_80 = F_85 ( V_18 , V_76 -> V_89 ) ;
V_80 = F_112 ( V_80 ) ;
V_80 = F_86 ( V_80 ) ;
F_104 ( V_82 , V_17 , V_86 ) ;
F_105 ( V_82 , V_83 , V_17 , V_80 ) ;
F_107 ( & V_82 -> V_91 ) ;
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
if ( F_10 ( F_115 ( V_76 ) ) )
return V_88 ;
if ( ! ( V_97 & V_103 ) &&
F_116 () ) {
T_7 * V_87 ;
T_6 V_86 ;
struct V_15 * V_18 ;
bool V_104 ;
V_86 = F_91 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) )
return V_88 ;
V_18 = F_21 () ;
if ( F_10 ( ! V_18 ) ) {
F_99 ( V_82 , V_86 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
V_87 = F_95 ( V_82 , V_17 ) ;
V_104 = F_111 ( V_86 , V_82 , V_76 , V_83 , V_17 ,
V_18 ) ;
F_97 ( V_87 ) ;
if ( ! V_104 ) {
F_99 ( V_82 , V_86 ) ;
F_31 () ;
}
return 0 ;
}
V_15 = F_109 ( F_117 ( V_76 ) ,
V_76 , V_83 , F_118 () , 0 ) ;
if ( F_10 ( ! V_15 ) ) {
F_25 ( V_105 ) ;
return V_102 ;
}
if ( F_10 ( F_87 ( V_82 , V_76 , V_83 , V_17 , V_15 ) ) ) {
F_98 ( V_15 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
F_25 ( V_106 ) ;
return 0 ;
}
int F_119 ( struct V_81 * V_107 , struct V_81 * V_108 ,
T_1 * V_109 , T_1 * V_110 , unsigned long V_111 ,
struct V_75 * V_76 )
{
T_7 * V_112 , * V_113 ;
struct V_15 * V_114 ;
T_1 V_17 ;
T_6 V_86 ;
int V_45 ;
V_45 = - V_66 ;
V_86 = F_91 ( V_107 , V_111 ) ;
if ( F_10 ( ! V_86 ) )
goto V_71;
V_112 = F_95 ( V_107 , V_109 ) ;
V_113 = F_120 ( V_108 , V_110 ) ;
F_121 ( V_113 , V_115 ) ;
V_45 = - V_116 ;
V_17 = * V_110 ;
if ( F_10 ( ! F_122 ( V_17 ) ) ) {
F_99 ( V_107 , V_86 ) ;
goto V_117;
}
if ( F_19 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_104 ;
V_18 = F_21 () ;
V_104 = F_111 ( V_86 , V_107 , V_76 , V_111 , V_109 ,
V_18 ) ;
F_32 ( ! V_104 ) ;
V_45 = 0 ;
goto V_117;
}
if ( F_10 ( F_123 ( V_17 ) ) ) {
F_97 ( V_113 ) ;
F_97 ( V_112 ) ;
F_99 ( V_107 , V_86 ) ;
F_124 ( V_76 -> V_118 , V_110 ) ;
goto V_71;
}
V_114 = F_20 ( V_17 ) ;
F_88 ( ! F_125 ( V_114 ) , V_114 ) ;
F_126 ( V_114 ) ;
F_127 ( V_114 ) ;
F_106 ( V_107 , V_90 , V_31 ) ;
F_128 ( V_108 , V_111 , V_110 ) ;
V_17 = F_129 ( F_112 ( V_17 ) ) ;
F_104 ( V_107 , V_109 , V_86 ) ;
F_105 ( V_107 , V_111 , V_109 , V_17 ) ;
F_107 ( & V_107 -> V_91 ) ;
V_45 = 0 ;
V_117:
F_97 ( V_113 ) ;
F_97 ( V_112 ) ;
V_71:
return V_45 ;
}
void F_130 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
T_1 * V_17 , T_1 V_119 ,
int V_120 )
{
T_7 * V_87 ;
T_1 V_80 ;
unsigned long V_83 ;
V_87 = F_95 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_131 ( * V_17 , V_119 ) ) )
goto V_121;
V_80 = F_132 ( V_119 ) ;
V_83 = V_96 & V_98 ;
if ( F_133 ( V_76 , V_83 , V_17 , V_80 , V_120 ) )
F_134 ( V_76 , V_96 , V_17 ) ;
V_121:
F_97 ( V_87 ) ;
}
static void F_135 ( struct V_15 * V_15 )
{
if ( F_136 ( V_122 ) ) {
struct V_15 * V_123 = V_15 + V_31 ;
F_137 ( V_31 , & V_15 -> V_124 ) ;
while ( ++ V_15 < V_123 )
F_138 ( V_15 ) ;
} else {
F_126 ( V_15 ) ;
}
}
static void F_139 ( struct V_15 * V_15 )
{
if ( F_136 ( V_122 ) ) {
struct V_15 * V_123 = V_15 + V_31 ;
while ( V_15 < V_123 )
F_98 ( V_15 ++ ) ;
} else {
F_98 ( V_15 ) ;
}
}
static int F_140 ( struct V_81 * V_82 ,
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
V_58 = F_141 ( sizeof( struct V_15 * ) * V_31 ,
V_129 ) ;
if ( F_10 ( ! V_58 ) ) {
V_45 |= V_88 ;
goto V_71;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_58 [ V_126 ] = F_142 ( V_130 |
V_131 ,
V_76 , V_96 , F_143 ( V_15 ) ) ;
if ( F_10 ( ! V_58 [ V_126 ] ||
F_90 ( V_58 [ V_126 ] , V_82 , V_129 ,
& V_85 ) ) ) {
if ( V_58 [ V_126 ] )
F_98 ( V_58 [ V_126 ] ) ;
while ( -- V_126 >= 0 ) {
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_92 ( V_58 [ V_126 ] , V_85 ) ;
F_98 ( V_58 [ V_126 ] ) ;
}
F_146 ( V_58 ) ;
V_45 |= V_88 ;
goto V_71;
}
F_145 ( V_58 [ V_126 ] , ( unsigned long ) V_85 ) ;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
F_147 ( V_58 [ V_126 ] , V_15 + V_126 ,
V_83 + V_132 * V_126 , V_76 ) ;
F_94 ( V_58 [ V_126 ] ) ;
F_148 () ;
}
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_87 = F_95 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_131 ( * V_17 , V_119 ) ) )
goto V_133;
F_88 ( ! F_125 ( V_15 ) , V_15 ) ;
F_150 ( V_76 , V_83 , V_17 ) ;
V_86 = F_151 ( V_82 , V_17 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_153 ( V_58 [ V_126 ] , V_76 -> V_89 ) ;
V_80 = F_154 ( F_155 ( V_80 ) , V_76 ) ;
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_101 ( V_58 [ V_126 ] , V_76 , V_83 ) ;
F_102 ( V_58 [ V_126 ] , V_85 , false ) ;
F_103 ( V_58 [ V_126 ] , V_76 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_41 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_146 ( V_58 ) ;
F_160 () ;
F_152 ( V_82 , V_17 , V_86 ) ;
F_161 ( V_15 ) ;
F_97 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
V_45 |= V_135 ;
F_98 ( V_15 ) ;
V_71:
return V_45 ;
V_133:
F_97 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_92 ( V_58 [ V_126 ] , V_85 ) ;
F_98 ( V_58 [ V_126 ] ) ;
}
F_146 ( V_58 ) ;
goto V_71;
}
int F_163 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_96 , T_1 * V_17 , T_1 V_119 )
{
T_7 * V_87 ;
int V_45 = 0 ;
struct V_15 * V_15 = NULL , * V_136 ;
struct V_84 * V_85 ;
unsigned long V_83 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_87 = F_120 ( V_82 , V_17 ) ;
F_41 ( ! V_76 -> V_118 ) ;
V_83 = V_96 & V_98 ;
if ( F_19 ( V_119 ) )
goto V_137;
F_164 ( V_87 ) ;
if ( F_10 ( ! F_131 ( * V_17 , V_119 ) ) )
goto V_117;
V_15 = F_20 ( V_119 ) ;
F_88 ( ! F_89 ( V_15 ) || ! F_125 ( V_15 ) , V_15 ) ;
if ( F_165 ( V_15 ) == 1 ) {
T_1 V_80 ;
V_80 = F_132 ( V_119 ) ;
V_80 = F_82 ( F_100 ( V_80 ) , V_76 ) ;
if ( F_133 ( V_76 , V_83 , V_17 , V_80 , 1 ) )
F_134 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_135 ;
goto V_117;
}
F_135 ( V_15 ) ;
F_97 ( V_87 ) ;
V_137:
if ( F_166 ( V_76 ) &&
! F_167 () )
V_136 = F_109 ( F_117 ( V_76 ) ,
V_76 , V_83 , F_118 () , 0 ) ;
else
V_136 = NULL ;
if ( F_10 ( ! V_136 ) ) {
if ( ! V_15 ) {
F_168 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_102 ;
} else {
V_45 = F_140 ( V_82 , V_76 , V_96 ,
V_17 , V_119 , V_15 , V_83 ) ;
if ( V_45 & V_88 ) {
F_169 ( V_15 ) ;
V_45 |= V_102 ;
}
F_139 ( V_15 ) ;
}
F_25 ( V_105 ) ;
goto V_71;
}
if ( F_10 ( F_90 ( V_136 , V_82 ,
V_21 , & V_85 ) ) ) {
F_98 ( V_136 ) ;
if ( V_15 ) {
F_169 ( V_15 ) ;
F_139 ( V_15 ) ;
} else
F_168 ( V_76 , V_96 , V_17 ) ;
V_45 |= V_102 ;
F_25 ( V_105 ) ;
goto V_71;
}
F_25 ( V_106 ) ;
if ( ! V_15 )
F_93 ( V_136 , V_83 , V_31 ) ;
else
F_170 ( V_136 , V_15 , V_83 , V_76 , V_31 ) ;
F_94 ( V_136 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
F_164 ( V_87 ) ;
if ( V_15 )
F_139 ( V_15 ) ;
if ( F_10 ( ! F_131 ( * V_17 , V_119 ) ) ) {
F_97 ( V_87 ) ;
F_92 ( V_136 , V_85 ) ;
F_98 ( V_136 ) ;
goto V_138;
} else {
T_1 V_80 ;
V_80 = F_84 ( V_136 , V_76 -> V_89 ) ;
V_80 = F_82 ( F_100 ( V_80 ) , V_76 ) ;
F_150 ( V_76 , V_83 , V_17 ) ;
F_101 ( V_136 , V_76 , V_83 ) ;
F_102 ( V_136 , V_85 , false ) ;
F_103 ( V_136 , V_76 ) ;
F_105 ( V_82 , V_83 , V_17 , V_80 ) ;
F_134 ( V_76 , V_96 , V_17 ) ;
if ( ! V_15 ) {
F_106 ( V_82 , V_90 , V_31 ) ;
F_31 () ;
} else {
F_88 ( ! F_125 ( V_15 ) , V_15 ) ;
F_161 ( V_15 ) ;
F_98 ( V_15 ) ;
}
V_45 |= V_135 ;
}
F_97 ( V_87 ) ;
V_138:
F_162 ( V_82 , V_127 , V_128 ) ;
V_71:
return V_45 ;
V_117:
F_97 ( V_87 ) ;
return V_45 ;
}
struct V_15 * F_171 ( struct V_75 * V_76 ,
unsigned long V_111 ,
T_1 * V_17 ,
unsigned int V_97 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
struct V_15 * V_15 = NULL ;
F_172 ( F_120 ( V_82 , V_17 ) ) ;
if ( V_97 & V_140 && ! F_173 ( * V_17 ) )
goto V_71;
if ( ( V_97 & V_141 ) && F_19 ( * V_17 ) )
return F_174 ( - V_142 ) ;
if ( ( V_97 & V_143 ) && F_175 ( * V_17 ) )
goto V_71;
V_15 = F_20 ( * V_17 ) ;
F_88 ( ! F_125 ( V_15 ) , V_15 ) ;
if ( V_97 & V_144 ) {
T_1 V_125 ;
V_125 = F_132 ( F_100 ( * V_17 ) ) ;
if ( F_133 ( V_76 , V_111 & V_98 ,
V_17 , V_125 , 1 ) )
F_134 ( V_76 , V_111 , V_17 ) ;
}
if ( ( V_97 & V_145 ) && ( V_76 -> V_77 & V_146 ) ) {
if ( V_15 -> V_147 && F_176 ( V_15 ) ) {
F_177 () ;
if ( V_15 -> V_147 )
F_178 ( V_15 ) ;
F_179 ( V_15 ) ;
}
}
V_15 += ( V_111 & ~ V_98 ) >> V_6 ;
F_88 ( ! F_89 ( V_15 ) , V_15 ) ;
if ( V_97 & V_148 )
F_180 ( V_15 ) ;
V_71:
return V_15 ;
}
int F_181 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_111 , T_1 V_17 , T_1 * V_149 )
{
T_7 * V_87 ;
struct V_118 * V_118 = NULL ;
struct V_15 * V_15 ;
unsigned long V_83 = V_111 & V_98 ;
int V_150 = - 1 , V_151 = F_118 () ;
int V_152 , V_153 = - 1 ;
bool V_154 ;
bool V_155 = false ;
int V_97 = 0 ;
V_87 = F_95 ( V_82 , V_149 ) ;
if ( F_10 ( ! F_131 ( V_17 , * V_149 ) ) )
goto V_117;
if ( F_10 ( F_182 ( * V_149 ) ) ) {
F_97 ( V_87 ) ;
F_183 ( V_76 -> V_118 , V_149 ) ;
goto V_71;
}
V_15 = F_20 ( V_17 ) ;
F_32 ( F_17 ( V_15 ) ) ;
V_150 = F_143 ( V_15 ) ;
V_153 = F_184 ( V_15 ) ;
F_185 ( V_156 ) ;
if ( V_150 == V_151 ) {
F_185 ( V_157 ) ;
V_97 |= V_158 ;
}
if ( ! F_173 ( V_17 ) )
V_97 |= V_159 ;
V_154 = F_176 ( V_15 ) ;
V_152 = F_186 ( V_15 , V_76 , V_83 ) ;
if ( V_152 == - 1 ) {
if ( V_154 )
goto V_160;
}
if ( ! V_154 ) {
F_97 ( V_87 ) ;
F_187 ( V_15 ) ;
V_150 = - 1 ;
goto V_71;
}
F_126 ( V_15 ) ;
F_97 ( V_87 ) ;
V_118 = F_188 ( V_15 ) ;
F_164 ( V_87 ) ;
if ( F_10 ( ! F_131 ( V_17 , * V_149 ) ) ) {
F_179 ( V_15 ) ;
F_98 ( V_15 ) ;
V_150 = - 1 ;
goto V_117;
}
if ( F_10 ( ! V_118 ) ) {
F_98 ( V_15 ) ;
V_150 = - 1 ;
goto V_160;
}
F_97 ( V_87 ) ;
V_155 = F_189 ( V_82 , V_76 ,
V_149 , V_17 , V_111 , V_15 , V_152 ) ;
if ( V_155 ) {
V_97 |= V_161 ;
V_150 = V_152 ;
}
goto V_71;
V_160:
F_32 ( ! F_190 ( V_15 ) ) ;
V_17 = F_191 ( V_17 ) ;
F_105 ( V_82 , V_83 , V_149 , V_17 ) ;
F_41 ( F_175 ( * V_149 ) ) ;
F_134 ( V_76 , V_111 , V_149 ) ;
F_179 ( V_15 ) ;
V_117:
F_97 ( V_87 ) ;
V_71:
if ( V_118 )
F_192 ( V_118 ) ;
if ( V_150 != - 1 )
F_193 ( V_153 , V_150 , V_31 , V_97 ) ;
return 0 ;
}
int F_194 ( struct V_162 * V_163 , struct V_75 * V_76 ,
T_1 * V_17 , unsigned long V_111 )
{
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_195 ( V_17 , V_76 , & V_87 ) == 1 ) {
struct V_15 * V_15 ;
T_6 V_86 ;
T_1 V_119 ;
V_119 = F_196 ( V_163 -> V_82 , V_111 , V_17 ) ;
F_197 ( V_163 , V_17 , V_111 ) ;
V_86 = F_151 ( V_163 -> V_82 , V_17 ) ;
if ( F_19 ( V_119 ) ) {
F_198 ( & V_163 -> V_82 -> V_91 ) ;
F_97 ( V_87 ) ;
F_31 () ;
} else {
V_15 = F_20 ( V_119 ) ;
F_161 ( V_15 ) ;
F_88 ( F_165 ( V_15 ) < 0 , V_15 ) ;
F_106 ( V_163 -> V_82 , V_90 , - V_31 ) ;
F_88 ( ! F_125 ( V_15 ) , V_15 ) ;
F_198 ( & V_163 -> V_82 -> V_91 ) ;
F_97 ( V_87 ) ;
F_199 ( V_163 , V_15 ) ;
}
F_99 ( V_163 -> V_82 , V_86 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_200 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_111 , unsigned long V_164 ,
unsigned char * V_165 )
{
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_195 ( V_17 , V_76 , & V_87 ) == 1 ) {
F_97 ( V_87 ) ;
memset ( V_165 , 1 , ( V_164 - V_111 ) >> V_6 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_201 ( struct V_75 * V_76 , struct V_75 * V_166 ,
unsigned long V_167 ,
unsigned long V_168 , unsigned long V_169 ,
T_1 * V_170 , T_1 * V_171 )
{
T_7 * V_172 , * V_173 ;
int V_45 = 0 ;
T_1 V_17 ;
struct V_81 * V_82 = V_76 -> V_139 ;
if ( ( V_167 & ~ V_98 ) ||
( V_168 & ~ V_98 ) ||
V_169 - V_167 < V_100 ||
( V_166 -> V_77 & V_174 ) )
goto V_71;
if ( F_202 ( ! F_96 ( * V_171 ) ) ) {
F_41 ( F_122 ( * V_171 ) ) ;
goto V_71;
}
V_45 = F_195 ( V_170 , V_76 , & V_172 ) ;
if ( V_45 == 1 ) {
V_173 = F_120 ( V_82 , V_171 ) ;
if ( V_173 != V_172 )
F_121 ( V_173 , V_115 ) ;
V_17 = F_196 ( V_82 , V_167 , V_170 ) ;
F_41 ( ! F_96 ( * V_171 ) ) ;
if ( F_203 ( V_173 , V_172 ) ) {
T_6 V_86 ;
V_86 = F_151 ( V_82 , V_170 ) ;
F_104 ( V_82 , V_171 , V_86 ) ;
}
F_105 ( V_82 , V_168 , V_171 , F_204 ( V_17 ) ) ;
if ( V_173 != V_172 )
F_97 ( V_173 ) ;
F_97 ( V_172 ) ;
}
V_71:
return V_45 ;
}
int F_205 ( struct V_75 * V_76 , T_1 * V_17 ,
unsigned long V_111 , T_5 V_175 , int V_176 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_195 ( V_17 , V_76 , & V_87 ) == 1 ) {
T_1 V_80 ;
V_45 = 1 ;
if ( ! V_176 ) {
V_80 = F_196 ( V_82 , V_111 , V_17 ) ;
if ( F_175 ( V_80 ) )
V_80 = F_191 ( V_80 ) ;
V_80 = F_206 ( V_80 , V_175 ) ;
V_45 = V_31 ;
F_105 ( V_82 , V_111 , V_17 , V_80 ) ;
F_32 ( F_173 ( V_80 ) ) ;
} else {
struct V_15 * V_15 = F_20 ( * V_17 ) ;
if ( ! F_17 ( V_15 ) &&
! F_175 ( * V_17 ) ) {
F_207 ( V_82 , V_111 , V_17 ) ;
V_45 = V_31 ;
}
}
F_97 ( V_87 ) ;
}
return V_45 ;
}
int F_195 ( T_1 * V_17 , struct V_75 * V_76 ,
T_7 * * V_87 )
{
* V_87 = F_95 ( V_76 -> V_139 , V_17 ) ;
if ( F_22 ( F_122 ( * V_17 ) ) ) {
if ( F_10 ( F_123 ( * V_17 ) ) ) {
F_97 ( * V_87 ) ;
F_124 ( V_76 -> V_118 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_97 ( * V_87 ) ;
return 0 ;
}
T_1 * F_208 ( struct V_15 * V_15 ,
struct V_81 * V_82 ,
unsigned long V_96 ,
enum V_177 V_47 ,
T_7 * * V_87 )
{
T_10 * V_178 ;
T_11 * V_179 ;
T_1 * V_17 ;
if ( V_96 & ~ V_98 )
return NULL ;
V_178 = F_209 ( V_82 , V_96 ) ;
if ( ! F_210 ( * V_178 ) )
return NULL ;
V_179 = F_211 ( V_178 , V_96 ) ;
if ( ! F_212 ( * V_179 ) )
return NULL ;
V_17 = F_213 ( V_179 , V_96 ) ;
* V_87 = F_95 ( V_82 , V_17 ) ;
if ( ! F_214 ( * V_17 ) )
goto V_121;
if ( F_20 ( * V_17 ) != V_15 )
goto V_121;
if ( V_47 == V_180 &&
F_123 ( * V_17 ) )
goto V_121;
if ( F_122 ( * V_17 ) ) {
F_41 ( V_47 == V_181 &&
! F_123 ( * V_17 ) ) ;
return V_17 ;
}
V_121:
F_97 ( * V_87 ) ;
return NULL ;
}
static int F_215 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_17 ;
int V_45 = 0 ;
const unsigned long V_127 = V_96 ;
const unsigned long V_128 = V_96 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_17 = F_208 ( V_15 , V_82 , V_96 ,
V_180 , & V_87 ) ;
if ( V_17 ) {
F_216 ( V_76 , V_96 , V_17 ) ;
V_45 = 1 ;
F_97 ( V_87 ) ;
}
F_162 ( V_82 , V_127 , V_128 ) ;
return V_45 ;
}
static void F_217 ( struct V_15 * V_15 ,
struct V_182 * V_183 )
{
int V_126 ;
struct V_1 * V_1 = F_218 ( V_15 ) ;
struct V_184 * V_184 ;
int V_185 = 0 ;
F_219 ( & V_1 -> V_186 ) ;
V_184 = F_220 ( V_15 , V_1 ) ;
F_221 ( V_15 ) ;
F_222 ( V_15 ) ;
for ( V_126 = V_31 - 1 ; V_126 >= 1 ; V_126 -- ) {
struct V_15 * V_187 = V_15 + V_126 ;
F_32 ( F_165 ( V_187 ) < 0 ) ;
V_185 += F_165 ( V_187 ) ;
F_32 ( V_185 < 0 ) ;
F_32 ( F_35 ( & V_187 -> V_124 ) != 0 ) ;
F_137 ( F_165 ( V_15 ) + F_165 ( V_187 ) + 1 ,
& V_187 -> V_124 ) ;
F_223 () ;
V_187 -> V_97 &= ~ V_188 | V_189 ;
V_187 -> V_97 |= ( V_15 -> V_97 &
( ( 1L << V_190 ) |
( 1L << V_191 ) |
( 1L << V_192 ) |
( 1L << V_193 ) |
( 1L << V_194 ) |
( 1L << V_195 ) ) ) ;
V_187 -> V_97 |= ( 1L << V_196 ) ;
F_160 () ;
V_187 -> V_197 = V_15 -> V_197 ;
F_32 ( V_187 -> V_147 ) ;
V_187 -> V_147 = V_15 -> V_147 ;
V_187 -> V_198 = V_15 -> V_198 + V_126 ;
F_224 ( V_187 , F_184 ( V_15 ) ) ;
F_32 ( ! F_225 ( V_187 ) ) ;
F_32 ( ! F_226 ( V_187 ) ) ;
F_32 ( ! F_227 ( V_187 ) ) ;
F_32 ( ! F_228 ( V_187 ) ) ;
F_229 ( V_15 , V_187 , V_184 , V_183 ) ;
}
F_230 ( V_185 , & V_15 -> V_124 ) ;
F_32 ( F_35 ( & V_15 -> V_124 ) <= 0 ) ;
F_231 ( V_1 , V_199 , - 1 ) ;
F_232 ( V_15 ) ;
F_233 ( V_15 ) ;
F_234 ( & V_1 -> V_186 ) ;
for ( V_126 = 1 ; V_126 < V_31 ; V_126 ++ ) {
struct V_15 * V_187 = V_15 + V_126 ;
F_32 ( F_235 ( V_187 ) <= 0 ) ;
F_98 ( V_187 ) ;
}
F_32 ( F_235 ( V_15 ) <= 0 ) ;
}
static int F_236 ( struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_17 , V_125 ;
int V_45 = 0 , V_126 ;
T_6 V_86 ;
unsigned long V_83 ;
V_17 = F_208 ( V_15 , V_82 , V_96 ,
V_181 , & V_87 ) ;
if ( V_17 ) {
V_86 = F_151 ( V_82 , V_17 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
if ( F_173 ( * V_17 ) )
F_32 ( F_165 ( V_15 ) != 1 ) ;
V_83 = V_96 ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
F_32 ( F_89 ( V_15 + V_126 ) ) ;
V_80 = F_153 ( V_15 + V_126 , V_76 -> V_89 ) ;
V_80 = F_154 ( F_155 ( V_80 ) , V_76 ) ;
if ( ! F_173 ( * V_17 ) )
V_80 = F_237 ( V_80 ) ;
if ( ! F_238 ( * V_17 ) )
V_80 = F_239 ( V_80 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_32 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_160 () ;
F_240 ( V_76 , V_96 , V_17 ) ;
F_152 ( V_82 , V_17 , V_86 ) ;
V_45 = 1 ;
F_97 ( V_87 ) ;
}
return V_45 ;
}
static void F_241 ( struct V_15 * V_15 ,
struct V_118 * V_118 ,
struct V_182 * V_183 )
{
int V_200 , V_201 ;
T_12 V_202 = V_15 -> V_198 << ( V_203 - V_6 ) ;
struct V_204 * V_205 ;
F_32 ( ! F_125 ( V_15 ) ) ;
F_32 ( F_242 ( V_15 ) ) ;
V_200 = 0 ;
F_243 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_205 -> V_76 ;
unsigned long V_111 = F_244 ( V_15 , V_76 ) ;
F_32 ( F_245 ( V_76 ) ) ;
V_200 += F_215 ( V_15 , V_76 , V_111 ) ;
}
if ( V_200 != F_165 ( V_15 ) ) {
F_12 ( L_17 ,
V_200 , F_165 ( V_15 ) ) ;
F_246 () ;
}
F_217 ( V_15 , V_183 ) ;
V_201 = 0 ;
F_243 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_205 -> V_76 ;
unsigned long V_111 = F_244 ( V_15 , V_76 ) ;
F_32 ( F_245 ( V_76 ) ) ;
V_201 += F_236 ( V_15 , V_76 , V_111 ) ;
}
if ( V_200 != V_201 ) {
F_12 ( L_18 ,
V_200 , V_201 , F_165 ( V_15 ) ) ;
F_246 () ;
}
}
int F_247 ( struct V_15 * V_15 , struct V_182 * V_183 )
{
struct V_118 * V_118 ;
int V_45 = 1 ;
F_32 ( F_17 ( V_15 ) ) ;
F_32 ( ! F_225 ( V_15 ) ) ;
V_118 = F_248 ( V_15 ) ;
if ( ! V_118 )
goto V_71;
F_249 ( V_118 ) ;
V_45 = 0 ;
if ( ! F_89 ( V_15 ) )
goto V_117;
F_32 ( ! F_228 ( V_15 ) ) ;
F_241 ( V_15 , V_118 , V_183 ) ;
F_25 ( V_206 ) ;
F_32 ( F_89 ( V_15 ) ) ;
V_117:
F_250 ( V_118 ) ;
F_251 ( V_118 ) ;
V_71:
return V_45 ;
}
int F_252 ( struct V_75 * V_76 ,
unsigned long * V_77 , int V_207 )
{
switch ( V_207 ) {
case V_208 :
#ifdef F_253
if ( F_254 ( V_76 -> V_139 ) )
return 0 ;
#endif
if ( * V_77 & ( V_209 | V_210 ) )
return - V_42 ;
* V_77 &= ~ V_174 ;
* V_77 |= V_209 ;
if ( F_10 ( F_255 ( V_76 ) ) )
return - V_66 ;
break;
case V_211 :
if ( * V_77 & ( V_174 | V_210 ) )
return - V_42 ;
* V_77 &= ~ V_209 ;
* V_77 |= V_174 ;
break;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
V_212 = F_256 ( L_19 ,
sizeof( struct V_213 ) ,
F_257 ( struct V_213 ) , 0 , NULL ) ;
if ( ! V_212 )
return - V_66 ;
return 0 ;
}
static inline struct V_213 * F_258 ( void )
{
if ( ! V_212 )
return NULL ;
return F_259 ( V_212 , V_129 ) ;
}
static inline void F_260 ( struct V_213 * V_213 )
{
F_261 ( V_212 , V_213 ) ;
}
static struct V_213 * F_262 ( struct V_81 * V_82 )
{
struct V_213 * V_213 ;
F_263 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_82 == V_213 -> V_82 )
return V_213 ;
return NULL ;
}
static void F_264 ( struct V_81 * V_82 ,
struct V_213 * V_213 )
{
V_213 -> V_82 = V_82 ;
F_265 ( V_214 , & V_213 -> V_215 , ( long ) V_82 ) ;
}
static inline int F_266 ( struct V_81 * V_82 )
{
return F_35 ( & V_82 -> V_216 ) == 0 ;
}
int F_267 ( struct V_81 * V_82 )
{
struct V_213 * V_213 ;
int V_217 ;
V_213 = F_258 () ;
if ( ! V_213 )
return - V_66 ;
F_41 ( F_266 ( V_82 ) ) ;
if ( F_10 ( F_268 ( V_218 , & V_82 -> V_97 ) ) ) {
F_260 ( V_213 ) ;
return 0 ;
}
F_164 ( & V_219 ) ;
F_264 ( V_82 , V_213 ) ;
V_217 = F_14 ( & V_12 . V_13 ) ;
F_269 ( & V_213 -> V_220 , & V_12 . V_13 ) ;
F_97 ( & V_219 ) ;
F_270 ( & V_82 -> V_221 ) ;
if ( V_217 )
F_15 ( & V_14 ) ;
return 0 ;
}
int F_255 ( struct V_75 * V_76 )
{
unsigned long V_222 , V_223 ;
if ( ! V_76 -> V_118 )
return 0 ;
if ( V_76 -> V_224 )
return 0 ;
F_41 ( V_76 -> V_77 & V_210 ) ;
V_222 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_223 = V_76 -> V_101 & V_98 ;
if ( V_222 < V_223 )
return F_115 ( V_76 ) ;
return 0 ;
}
void F_271 ( struct V_81 * V_82 )
{
struct V_213 * V_213 ;
int free = 0 ;
F_164 ( & V_219 ) ;
V_213 = F_262 ( V_82 ) ;
if ( V_213 && V_12 . V_213 != V_213 ) {
F_272 ( & V_213 -> V_215 ) ;
F_273 ( & V_213 -> V_220 ) ;
free = 1 ;
}
F_97 ( & V_219 ) ;
if ( free ) {
F_44 ( V_218 , & V_82 -> V_97 ) ;
F_260 ( V_213 ) ;
F_274 ( V_82 ) ;
} else if ( V_213 ) {
F_275 ( & V_82 -> V_225 ) ;
F_276 ( & V_82 -> V_225 ) ;
}
}
static void F_277 ( struct V_15 * V_15 )
{
F_278 ( V_15 , V_226 + 0 ) ;
F_179 ( V_15 ) ;
F_279 ( V_15 ) ;
}
static void F_280 ( T_9 * V_134 , T_9 * V_227 )
{
while ( -- V_227 >= V_134 ) {
T_9 V_228 = * V_227 ;
if ( ! F_157 ( V_228 ) )
F_277 ( F_281 ( V_228 ) ) ;
}
}
static int F_282 ( struct V_75 * V_76 ,
unsigned long V_96 ,
T_9 * V_134 )
{
struct V_15 * V_15 ;
T_9 * V_227 ;
int V_229 = 0 , V_230 = 0 ;
for ( V_227 = V_134 ; V_227 < V_134 + V_31 ;
V_227 ++ , V_96 += V_132 ) {
T_9 V_228 = * V_227 ;
if ( F_157 ( V_228 ) ) {
if ( ++ V_230 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_283 ( V_228 ) || ! F_284 ( V_228 ) )
goto V_71;
V_15 = F_285 ( V_76 , V_96 , V_228 ) ;
if ( F_10 ( ! V_15 ) )
goto V_71;
F_88 ( F_89 ( V_15 ) , V_15 ) ;
F_88 ( ! F_225 ( V_15 ) , V_15 ) ;
F_88 ( ! F_228 ( V_15 ) , V_15 ) ;
if ( F_235 ( V_15 ) != 1 )
goto V_71;
if ( ! F_176 ( V_15 ) )
goto V_71;
if ( F_286 ( V_15 ) ) {
F_179 ( V_15 ) ;
goto V_71;
}
F_287 ( V_15 , V_226 + 0 ) ;
F_88 ( ! F_190 ( V_15 ) , V_15 ) ;
F_88 ( F_288 ( V_15 ) , V_15 ) ;
if ( F_289 ( V_228 ) || F_290 ( V_15 ) ||
F_291 ( V_76 -> V_139 , V_96 ) )
V_229 = 1 ;
}
if ( F_22 ( V_229 ) )
return 1 ;
V_71:
F_280 ( V_134 , V_227 ) ;
return 0 ;
}
static void F_292 ( T_9 * V_134 , struct V_15 * V_15 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
T_7 * V_87 )
{
T_9 * V_227 ;
for ( V_227 = V_134 ; V_227 < V_134 + V_31 ; V_227 ++ ) {
T_9 V_228 = * V_227 ;
struct V_15 * V_114 ;
if ( F_157 ( V_228 ) ) {
F_293 ( V_15 , V_96 ) ;
F_106 ( V_76 -> V_139 , V_90 , 1 ) ;
} else {
V_114 = F_281 ( V_228 ) ;
F_147 ( V_15 , V_114 , V_96 , V_76 ) ;
F_88 ( F_165 ( V_114 ) != 1 , V_114 ) ;
F_277 ( V_114 ) ;
F_164 ( V_87 ) ;
F_294 ( V_76 -> V_139 , V_96 , V_227 ) ;
F_161 ( V_114 ) ;
F_97 ( V_87 ) ;
F_295 ( V_114 ) ;
}
V_96 += V_132 ;
V_15 ++ ;
}
}
static void F_296 ( void )
{
F_297 ( V_14 , false ,
F_298 ( V_56 ) ) ;
}
static bool F_299 ( int V_231 )
{
int V_126 ;
if ( ! V_232 )
return false ;
if ( V_233 [ V_231 ] )
return false ;
for ( V_126 = 0 ; V_126 < V_234 ; V_126 ++ ) {
if ( ! V_233 [ V_126 ] )
continue;
if ( F_300 ( V_231 , V_126 ) > V_235 )
return true ;
}
return false ;
}
static int F_301 ( void )
{
static int V_236 = V_237 ;
int V_231 , V_238 = 0 , V_239 = 0 ;
for ( V_231 = 0 ; V_231 < V_234 ; V_231 ++ )
if ( V_233 [ V_231 ] > V_239 ) {
V_239 = V_233 [ V_231 ] ;
V_238 = V_231 ;
}
if ( V_238 <= V_236 )
for ( V_231 = V_236 + 1 ; V_231 < V_234 ;
V_231 ++ )
if ( V_239 == V_233 [ V_231 ] ) {
V_238 = V_231 ;
break;
}
V_236 = V_238 ;
return V_238 ;
}
static bool F_302 ( struct V_15 * * V_240 , bool * V_241 )
{
if ( F_11 ( * V_240 ) ) {
if ( ! * V_241 )
return false ;
* V_241 = false ;
* V_240 = NULL ;
F_296 () ;
} else if ( * V_240 ) {
F_98 ( * V_240 ) ;
* V_240 = NULL ;
}
return true ;
}
static struct V_15
* F_303 ( struct V_15 * * V_240 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_96 ,
int V_242 )
{
F_88 ( * V_240 , * V_240 ) ;
* V_240 = F_304 ( V_242 , F_108 (
F_305 () , V_131 ) , V_24 ) ;
F_306 ( & V_82 -> V_225 ) ;
if ( F_10 ( ! * V_240 ) ) {
F_25 ( V_243 ) ;
* V_240 = F_174 ( - V_66 ) ;
return NULL ;
}
F_25 ( V_244 ) ;
return * V_240 ;
}
static int F_301 ( void )
{
return 0 ;
}
static inline struct V_15 * F_307 ( int V_92 )
{
return F_24 ( F_108 ( V_92 , 0 ) ,
V_24 ) ;
}
static struct V_15 * F_308 ( bool * V_241 )
{
struct V_15 * V_240 ;
do {
V_240 = F_307 ( F_305 () ) ;
if ( ! V_240 ) {
F_25 ( V_243 ) ;
if ( ! * V_241 )
return NULL ;
* V_241 = false ;
F_296 () ;
} else
F_25 ( V_244 ) ;
} while ( F_10 ( ! V_240 ) && F_22 ( F_2 () ) );
return V_240 ;
}
static bool F_302 ( struct V_15 * * V_240 , bool * V_241 )
{
if ( ! * V_240 )
* V_240 = F_308 ( V_241 ) ;
if ( F_10 ( ! * V_240 ) )
return false ;
return true ;
}
static struct V_15
* F_303 ( struct V_15 * * V_240 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_96 ,
int V_242 )
{
F_306 ( & V_82 -> V_225 ) ;
F_41 ( ! * V_240 ) ;
return * V_240 ;
}
static bool F_309 ( struct V_75 * V_76 )
{
if ( ( ! ( V_76 -> V_77 & V_209 ) && ! F_310 () ) ||
( V_76 -> V_77 & V_174 ) )
return false ;
if ( ! V_76 -> V_118 || V_76 -> V_224 )
return false ;
if ( F_245 ( V_76 ) )
return false ;
F_41 ( V_76 -> V_77 & V_210 ) ;
return true ;
}
static void F_311 ( struct V_81 * V_82 ,
unsigned long V_96 ,
struct V_15 * * V_240 ,
struct V_75 * V_76 ,
int V_242 )
{
T_1 * V_17 , V_125 ;
T_9 * V_134 ;
T_6 V_86 ;
struct V_15 * V_136 ;
T_7 * V_245 , * V_246 ;
int V_247 ;
unsigned long V_222 , V_223 ;
struct V_84 * V_85 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_41 ( V_96 & ~ V_98 ) ;
V_136 = F_303 ( V_240 , V_82 , V_76 , V_96 , V_242 ) ;
if ( ! V_136 )
return;
if ( F_10 ( F_90 ( V_136 , V_82 ,
V_21 , & V_85 ) ) )
return;
F_275 ( & V_82 -> V_225 ) ;
if ( F_10 ( F_266 ( V_82 ) ) )
goto V_71;
V_76 = F_312 ( V_82 , V_96 ) ;
if ( ! V_76 )
goto V_71;
V_222 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_223 = V_76 -> V_101 & V_98 ;
if ( V_96 < V_222 || V_96 + V_100 > V_223 )
goto V_71;
if ( ! F_309 ( V_76 ) )
goto V_71;
V_17 = F_313 ( V_82 , V_96 ) ;
if ( ! V_17 )
goto V_71;
F_249 ( V_76 -> V_118 ) ;
V_134 = F_156 ( V_17 , V_96 ) ;
V_246 = F_314 ( V_82 , V_17 ) ;
V_127 = V_96 ;
V_128 = V_96 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_245 = F_95 ( V_82 , V_17 ) ;
V_125 = F_150 ( V_76 , V_96 , V_17 ) ;
F_97 ( V_245 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
F_164 ( V_246 ) ;
V_247 = F_282 ( V_76 , V_96 , V_134 ) ;
F_97 ( V_246 ) ;
if ( F_10 ( ! V_247 ) ) {
F_159 ( V_134 ) ;
F_164 ( V_245 ) ;
F_32 ( ! F_96 ( * V_17 ) ) ;
F_152 ( V_82 , V_17 , F_315 ( V_125 ) ) ;
F_97 ( V_245 ) ;
F_250 ( V_76 -> V_118 ) ;
goto V_71;
}
F_250 ( V_76 -> V_118 ) ;
F_292 ( V_134 , V_136 , V_76 , V_96 , V_246 ) ;
F_159 ( V_134 ) ;
F_94 ( V_136 ) ;
V_86 = F_315 ( V_125 ) ;
V_125 = F_84 ( V_136 , V_76 -> V_89 ) ;
V_125 = F_82 ( F_100 ( V_125 ) , V_76 ) ;
F_160 () ;
F_164 ( V_245 ) ;
F_32 ( ! F_96 ( * V_17 ) ) ;
F_101 ( V_136 , V_76 , V_96 ) ;
F_102 ( V_136 , V_85 , false ) ;
F_103 ( V_136 , V_76 ) ;
F_104 ( V_82 , V_17 , V_86 ) ;
F_105 ( V_82 , V_96 , V_17 , V_125 ) ;
F_134 ( V_76 , V_96 , V_17 ) ;
F_97 ( V_245 ) ;
* V_240 = NULL ;
V_59 ++ ;
V_248:
F_276 ( & V_82 -> V_225 ) ;
return;
V_71:
F_92 ( V_136 , V_85 ) ;
goto V_248;
}
static int F_316 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_96 ,
struct V_15 * * V_240 )
{
T_1 * V_17 ;
T_9 * V_134 , * V_227 ;
int V_45 = 0 , V_229 = 0 , V_230 = 0 ;
struct V_15 * V_15 ;
unsigned long V_249 ;
T_7 * V_87 ;
int V_242 = V_237 ;
F_41 ( V_96 & ~ V_98 ) ;
V_17 = F_313 ( V_82 , V_96 ) ;
if ( ! V_17 )
goto V_71;
memset ( V_233 , 0 , sizeof( V_233 ) ) ;
V_134 = F_317 ( V_82 , V_17 , V_96 , & V_87 ) ;
for ( V_249 = V_96 , V_227 = V_134 ; V_227 < V_134 + V_31 ;
V_227 ++ , V_249 += V_132 ) {
T_9 V_228 = * V_227 ;
if ( F_157 ( V_228 ) ) {
if ( ++ V_230 <= V_62 )
continue;
else
goto V_250;
}
if ( ! F_283 ( V_228 ) || ! F_284 ( V_228 ) )
goto V_250;
V_15 = F_285 ( V_76 , V_249 , V_228 ) ;
if ( F_10 ( ! V_15 ) )
goto V_250;
V_242 = F_143 ( V_15 ) ;
if ( F_299 ( V_242 ) )
goto V_250;
V_233 [ V_242 ] ++ ;
F_88 ( F_89 ( V_15 ) , V_15 ) ;
if ( ! F_288 ( V_15 ) || F_190 ( V_15 ) || ! F_225 ( V_15 ) )
goto V_250;
if ( F_235 ( V_15 ) != 1 )
goto V_250;
if ( F_289 ( V_228 ) || F_290 ( V_15 ) ||
F_291 ( V_76 -> V_139 , V_96 ) )
V_229 = 1 ;
}
if ( V_229 )
V_45 = 1 ;
V_250:
F_318 ( V_134 , V_87 ) ;
if ( V_45 ) {
V_242 = F_301 () ;
F_311 ( V_82 , V_96 , V_240 , V_76 , V_242 ) ;
}
V_71:
return V_45 ;
}
static void F_319 ( struct V_213 * V_213 )
{
struct V_81 * V_82 = V_213 -> V_82 ;
F_41 ( V_251 != 1 && ! F_320 ( & V_219 ) ) ;
if ( F_266 ( V_82 ) ) {
F_272 ( & V_213 -> V_215 ) ;
F_273 ( & V_213 -> V_220 ) ;
F_260 ( V_213 ) ;
F_274 ( V_82 ) ;
}
}
static unsigned int F_321 ( unsigned int V_58 ,
struct V_15 * * V_240 )
__releases( &khugepaged_mm_lock
static int F_322 ( void )
{
return ! F_14 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_323 ( void )
{
return ! F_14 ( & V_12 . V_13 ) ||
F_324 () ;
}
static void F_325 ( void )
{
struct V_15 * V_240 = NULL ;
unsigned int V_252 = 0 , V_253 = 0 ;
unsigned int V_58 = V_57 ;
bool V_241 = true ;
F_326 () ;
while ( V_252 < V_58 ) {
if ( ! F_302 ( & V_240 , & V_241 ) )
break;
F_148 () ;
if ( F_10 ( F_324 () || F_327 ( V_254 ) ) )
break;
F_164 ( & V_219 ) ;
if ( ! V_12 . V_213 )
V_253 ++ ;
if ( F_322 () &&
V_253 < 2 )
V_252 += F_321 ( V_58 - V_252 ,
& V_240 ) ;
else
V_252 = V_58 ;
F_97 ( & V_219 ) ;
}
if ( ! F_328 ( V_240 ) )
F_98 ( V_240 ) ;
}
static void F_329 ( void )
{
F_330 () ;
if ( F_322 () ) {
if ( ! V_53 )
return;
F_297 ( V_14 ,
F_324 () ,
F_298 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_331 ( V_14 , F_323 () ) ;
}
static int V_11 ( void * V_230 )
{
struct V_213 * V_213 ;
F_332 () ;
F_333 ( V_254 , V_255 ) ;
while ( ! F_324 () ) {
F_325 () ;
F_329 () ;
}
F_164 ( & V_219 ) ;
V_213 = V_12 . V_213 ;
V_12 . V_213 = NULL ;
if ( V_213 )
F_319 ( V_213 ) ;
F_97 ( & V_219 ) ;
return 0 ;
}
static void F_334 ( struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_17 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_6 V_86 ;
T_1 V_125 ;
int V_126 ;
F_150 ( V_76 , V_83 , V_17 ) ;
V_86 = F_151 ( V_82 , V_17 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_335 ( F_336 ( V_83 ) , V_76 -> V_89 ) ;
V_80 = F_337 ( V_80 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_41 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_160 () ;
F_152 ( V_82 , V_17 , V_86 ) ;
F_31 () ;
}
void F_338 ( struct V_75 * V_76 , unsigned long V_96 ,
T_1 * V_17 )
{
T_7 * V_87 ;
struct V_15 * V_15 ;
struct V_81 * V_82 = V_76 -> V_139 ;
unsigned long V_83 = V_96 & V_98 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_32 ( V_76 -> V_99 > V_83 || V_76 -> V_101 < V_83 + V_100 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
V_256:
F_149 ( V_82 , V_127 , V_128 ) ;
V_87 = F_95 ( V_82 , V_17 ) ;
if ( F_10 ( ! F_122 ( * V_17 ) ) ) {
F_97 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
return;
}
if ( F_19 ( * V_17 ) ) {
F_334 ( V_76 , V_83 , V_17 ) ;
F_97 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
return;
}
V_15 = F_20 ( * V_17 ) ;
F_88 ( ! F_235 ( V_15 ) , V_15 ) ;
F_126 ( V_15 ) ;
F_97 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
F_169 ( V_15 ) ;
F_98 ( V_15 ) ;
if ( F_10 ( F_122 ( * V_17 ) ) )
goto V_256;
}
void F_339 ( struct V_81 * V_82 , unsigned long V_96 ,
T_1 * V_17 )
{
struct V_75 * V_76 ;
V_76 = F_312 ( V_82 , V_96 ) ;
F_32 ( V_76 == NULL ) ;
F_168 ( V_76 , V_96 , V_17 ) ;
}
static void F_340 ( struct V_81 * V_82 ,
unsigned long V_96 )
{
T_10 * V_178 ;
T_11 * V_179 ;
T_1 * V_17 ;
F_41 ( ! ( V_96 & ~ V_98 ) ) ;
V_178 = F_209 ( V_82 , V_96 ) ;
if ( ! F_210 ( * V_178 ) )
return;
V_179 = F_211 ( V_178 , V_96 ) ;
if ( ! F_212 ( * V_179 ) )
return;
V_17 = F_213 ( V_179 , V_96 ) ;
if ( ! F_214 ( * V_17 ) )
return;
F_339 ( V_82 , V_96 , V_17 ) ;
}
void F_341 ( struct V_75 * V_76 ,
unsigned long V_257 ,
unsigned long V_164 ,
long V_258 )
{
if ( V_257 & ~ V_98 &&
( V_257 & V_98 ) >= V_76 -> V_99 &&
( V_257 & V_98 ) + V_100 <= V_76 -> V_101 )
F_340 ( V_76 -> V_139 , V_257 ) ;
if ( V_164 & ~ V_98 &&
( V_164 & V_98 ) >= V_76 -> V_99 &&
( V_164 & V_98 ) + V_100 <= V_76 -> V_101 )
F_340 ( V_76 -> V_139 , V_164 ) ;
if ( V_258 > 0 ) {
struct V_75 * V_259 = V_76 -> V_260 ;
unsigned long V_261 = V_259 -> V_99 ;
V_261 += V_258 << V_6 ;
if ( V_261 & ~ V_98 &&
( V_261 & V_98 ) >= V_259 -> V_99 &&
( V_261 & V_98 ) + V_100 <= V_259 -> V_101 )
F_340 ( V_259 -> V_139 , V_261 ) ;
}
}
