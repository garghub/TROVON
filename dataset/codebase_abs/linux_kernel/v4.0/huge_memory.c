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
static inline bool F_17 ( T_1 V_15 )
{
return F_18 ( F_19 ( V_15 ) ) ;
}
static struct V_16 * F_20 ( void )
{
struct V_16 * V_17 ;
V_18:
if ( F_21 ( F_22 ( & V_19 ) ) )
return F_23 ( V_20 ) ;
V_17 = F_24 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_17 ) {
F_25 ( V_25 ) ;
return NULL ;
}
F_25 ( V_26 ) ;
F_26 () ;
if ( F_27 ( & V_20 , NULL , V_17 ) ) {
F_28 () ;
F_29 ( V_17 , F_30 ( V_17 ) ) ;
goto V_18;
}
F_31 ( & V_19 , 2 ) ;
F_28 () ;
return F_23 ( V_20 ) ;
}
static void F_32 ( void )
{
F_33 ( F_34 ( & V_19 ) ) ;
}
static unsigned long F_35 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_36 ( & V_19 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_37 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_38 ( & V_19 , 1 , 0 ) == 1 ) {
struct V_16 * V_17 = F_39 ( & V_20 , NULL ) ;
F_33 ( V_17 == NULL ) ;
F_29 ( V_17 , F_30 ( V_17 ) ) ;
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
T_1 F_83 ( T_1 V_15 , struct V_75 * V_76 )
{
if ( F_21 ( V_76 -> V_77 & V_78 ) )
V_15 = F_84 ( V_15 ) ;
return V_15 ;
}
static inline T_1 F_85 ( struct V_16 * V_16 , T_5 V_79 )
{
T_1 V_80 ;
V_80 = F_86 ( V_16 , V_79 ) ;
V_80 = F_87 ( V_80 ) ;
return V_80 ;
}
static int F_88 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_15 ,
struct V_16 * V_16 )
{
struct V_84 * V_85 ;
T_6 V_86 ;
T_7 * V_87 ;
F_89 ( ! F_90 ( V_16 ) , V_16 ) ;
if ( F_91 ( V_16 , V_82 , V_21 , & V_85 ) )
return V_88 ;
V_86 = F_92 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) ) {
F_93 ( V_16 , V_85 ) ;
return V_88 ;
}
F_94 ( V_16 , V_83 , V_31 ) ;
F_95 ( V_16 ) ;
V_87 = F_96 ( V_82 , V_15 ) ;
if ( F_10 ( ! F_97 ( * V_15 ) ) ) {
F_98 ( V_87 ) ;
F_93 ( V_16 , V_85 ) ;
F_99 ( V_16 ) ;
F_100 ( V_82 , V_86 ) ;
} else {
T_1 V_80 ;
V_80 = F_85 ( V_16 , V_76 -> V_89 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
F_102 ( V_16 , V_76 , V_83 ) ;
F_103 ( V_16 , V_85 , false ) ;
F_104 ( V_16 , V_76 ) ;
F_105 ( V_82 , V_15 , V_86 ) ;
F_106 ( V_82 , V_83 , V_15 , V_80 ) ;
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
static bool F_110 ( T_6 V_86 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_83 , T_1 * V_15 ,
struct V_16 * V_17 )
{
T_1 V_80 ;
if ( ! F_97 ( * V_15 ) )
return false ;
V_80 = F_86 ( V_17 , V_76 -> V_89 ) ;
V_80 = F_87 ( V_80 ) ;
F_105 ( V_82 , V_15 , V_86 ) ;
F_106 ( V_82 , V_83 , V_15 , V_80 ) ;
F_108 ( & V_82 -> V_91 ) ;
return true ;
}
int F_111 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_95 , T_1 * V_15 ,
unsigned int V_96 )
{
T_8 V_97 ;
struct V_16 * V_16 ;
unsigned long V_83 = V_95 & V_98 ;
if ( V_83 < V_76 -> V_99 || V_83 + V_100 > V_76 -> V_101 )
return V_102 ;
if ( F_10 ( F_112 ( V_76 ) ) )
return V_88 ;
if ( F_10 ( F_113 ( V_76 , V_76 -> V_77 ) ) )
return V_88 ;
if ( ! ( V_96 & V_103 ) && ! F_114 ( V_82 ) &&
F_115 () ) {
T_7 * V_87 ;
T_6 V_86 ;
struct V_16 * V_17 ;
bool V_104 ;
V_86 = F_92 ( V_82 , V_83 ) ;
if ( F_10 ( ! V_86 ) )
return V_88 ;
V_17 = F_20 () ;
if ( F_10 ( ! V_17 ) ) {
F_100 ( V_82 , V_86 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
V_87 = F_96 ( V_82 , V_15 ) ;
V_104 = F_110 ( V_86 , V_82 , V_76 , V_83 , V_15 ,
V_17 ) ;
F_98 ( V_87 ) ;
if ( ! V_104 ) {
F_100 ( V_82 , V_86 ) ;
F_32 () ;
}
return 0 ;
}
V_97 = F_109 ( F_116 ( V_76 ) , 0 ) ;
V_16 = F_117 ( V_97 , V_76 , V_83 , V_24 ) ;
if ( F_10 ( ! V_16 ) ) {
F_25 ( V_105 ) ;
return V_102 ;
}
if ( F_10 ( F_88 ( V_82 , V_76 , V_83 , V_15 , V_16 ) ) ) {
F_99 ( V_16 ) ;
F_25 ( V_105 ) ;
return V_102 ;
}
F_25 ( V_106 ) ;
return 0 ;
}
int F_118 ( struct V_81 * V_107 , struct V_81 * V_108 ,
T_1 * V_109 , T_1 * V_110 , unsigned long V_111 ,
struct V_75 * V_76 )
{
T_7 * V_112 , * V_113 ;
struct V_16 * V_114 ;
T_1 V_15 ;
T_6 V_86 ;
int V_45 ;
V_45 = - V_66 ;
V_86 = F_92 ( V_107 , V_111 ) ;
if ( F_10 ( ! V_86 ) )
goto V_71;
V_112 = F_96 ( V_107 , V_109 ) ;
V_113 = F_119 ( V_108 , V_110 ) ;
F_120 ( V_113 , V_115 ) ;
V_45 = - V_116 ;
V_15 = * V_110 ;
if ( F_10 ( ! F_121 ( V_15 ) ) ) {
F_100 ( V_107 , V_86 ) ;
goto V_117;
}
if ( F_17 ( V_15 ) ) {
struct V_16 * V_17 ;
bool V_104 ;
V_17 = F_20 () ;
V_104 = F_110 ( V_86 , V_107 , V_76 , V_111 , V_109 ,
V_17 ) ;
F_33 ( ! V_104 ) ;
V_45 = 0 ;
goto V_117;
}
if ( F_10 ( F_122 ( V_15 ) ) ) {
F_98 ( V_113 ) ;
F_98 ( V_112 ) ;
F_100 ( V_107 , V_86 ) ;
F_123 ( V_76 -> V_118 , V_110 ) ;
goto V_71;
}
V_114 = F_19 ( V_15 ) ;
F_89 ( ! F_124 ( V_114 ) , V_114 ) ;
F_125 ( V_114 ) ;
F_126 ( V_114 ) ;
F_107 ( V_107 , V_90 , V_31 ) ;
F_127 ( V_108 , V_111 , V_110 ) ;
V_15 = F_128 ( F_129 ( V_15 ) ) ;
F_105 ( V_107 , V_109 , V_86 ) ;
F_106 ( V_107 , V_111 , V_109 , V_15 ) ;
F_108 ( & V_107 -> V_91 ) ;
V_45 = 0 ;
V_117:
F_98 ( V_113 ) ;
F_98 ( V_112 ) ;
V_71:
return V_45 ;
}
void F_130 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_95 ,
T_1 * V_15 , T_1 V_119 ,
int V_120 )
{
T_7 * V_87 ;
T_1 V_80 ;
unsigned long V_83 ;
V_87 = F_96 ( V_82 , V_15 ) ;
if ( F_10 ( ! F_131 ( * V_15 , V_119 ) ) )
goto V_121;
V_80 = F_132 ( V_119 ) ;
V_83 = V_95 & V_98 ;
if ( F_133 ( V_76 , V_83 , V_15 , V_80 , V_120 ) )
F_134 ( V_76 , V_95 , V_15 ) ;
V_121:
F_98 ( V_87 ) ;
}
static void F_135 ( struct V_16 * V_16 )
{
if ( F_136 ( V_122 ) ) {
struct V_16 * V_123 = V_16 + V_31 ;
F_137 ( V_31 , & V_16 -> V_124 ) ;
while ( ++ V_16 < V_123 )
F_138 ( V_16 ) ;
} else {
F_125 ( V_16 ) ;
}
}
static void F_139 ( struct V_16 * V_16 )
{
if ( F_136 ( V_122 ) ) {
struct V_16 * V_123 = V_16 + V_31 ;
while ( V_16 < V_123 )
F_99 ( V_16 ++ ) ;
} else {
F_99 ( V_16 ) ;
}
}
static int F_140 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_95 ,
T_1 * V_15 , T_1 V_119 ,
struct V_16 * V_16 ,
unsigned long V_83 )
{
struct V_84 * V_85 ;
T_7 * V_87 ;
T_6 V_86 ;
T_1 V_125 ;
int V_45 = 0 , V_126 ;
struct V_16 * * V_58 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_58 = F_141 ( sizeof( struct V_16 * ) * V_31 ,
V_129 ) ;
if ( F_10 ( ! V_58 ) ) {
V_45 |= V_88 ;
goto V_71;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_58 [ V_126 ] = F_142 ( V_130 |
V_131 ,
V_76 , V_95 , F_143 ( V_16 ) ) ;
if ( F_10 ( ! V_58 [ V_126 ] ||
F_91 ( V_58 [ V_126 ] , V_82 , V_129 ,
& V_85 ) ) ) {
if ( V_58 [ V_126 ] )
F_99 ( V_58 [ V_126 ] ) ;
while ( -- V_126 >= 0 ) {
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_93 ( V_58 [ V_126 ] , V_85 ) ;
F_99 ( V_58 [ V_126 ] ) ;
}
F_146 ( V_58 ) ;
V_45 |= V_88 ;
goto V_71;
}
F_145 ( V_58 [ V_126 ] , ( unsigned long ) V_85 ) ;
}
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
F_147 ( V_58 [ V_126 ] , V_16 + V_126 ,
V_83 + V_132 * V_126 , V_76 ) ;
F_95 ( V_58 [ V_126 ] ) ;
F_148 () ;
}
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_87 = F_96 ( V_82 , V_15 ) ;
if ( F_10 ( ! F_131 ( * V_15 , V_119 ) ) )
goto V_133;
F_89 ( ! F_124 ( V_16 ) , V_16 ) ;
F_150 ( V_76 , V_83 , V_15 ) ;
V_86 = F_151 ( V_82 , V_15 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_153 ( V_58 [ V_126 ] , V_76 -> V_89 ) ;
V_80 = F_154 ( F_155 ( V_80 ) , V_76 ) ;
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_102 ( V_58 [ V_126 ] , V_76 , V_83 ) ;
F_103 ( V_58 [ V_126 ] , V_85 , false ) ;
F_104 ( V_58 [ V_126 ] , V_76 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_42 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_146 ( V_58 ) ;
F_160 () ;
F_152 ( V_82 , V_15 , V_86 ) ;
F_161 ( V_16 ) ;
F_98 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
V_45 |= V_135 ;
F_99 ( V_16 ) ;
V_71:
return V_45 ;
V_133:
F_98 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ ) {
V_85 = ( void * ) F_144 ( V_58 [ V_126 ] ) ;
F_145 ( V_58 [ V_126 ] , 0 ) ;
F_93 ( V_58 [ V_126 ] , V_85 ) ;
F_99 ( V_58 [ V_126 ] ) ;
}
F_146 ( V_58 ) ;
goto V_71;
}
int F_163 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_95 , T_1 * V_15 , T_1 V_119 )
{
T_7 * V_87 ;
int V_45 = 0 ;
struct V_16 * V_16 = NULL , * V_136 ;
struct V_84 * V_85 ;
unsigned long V_83 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_87 = F_119 ( V_82 , V_15 ) ;
F_164 ( ! V_76 -> V_118 , V_76 ) ;
V_83 = V_95 & V_98 ;
if ( F_17 ( V_119 ) )
goto V_137;
F_165 ( V_87 ) ;
if ( F_10 ( ! F_131 ( * V_15 , V_119 ) ) )
goto V_117;
V_16 = F_19 ( V_119 ) ;
F_89 ( ! F_90 ( V_16 ) || ! F_124 ( V_16 ) , V_16 ) ;
if ( F_166 ( V_16 ) == 1 ) {
T_1 V_80 ;
V_80 = F_132 ( V_119 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
if ( F_133 ( V_76 , V_83 , V_15 , V_80 , 1 ) )
F_134 ( V_76 , V_95 , V_15 ) ;
V_45 |= V_135 ;
goto V_117;
}
F_135 ( V_16 ) ;
F_98 ( V_87 ) ;
V_137:
if ( F_167 ( V_76 ) &&
! F_168 () ) {
T_8 V_97 ;
V_97 = F_109 ( F_116 ( V_76 ) , 0 ) ;
V_136 = F_117 ( V_97 , V_76 , V_83 , V_24 ) ;
} else
V_136 = NULL ;
if ( F_10 ( ! V_136 ) ) {
if ( ! V_16 ) {
F_169 ( V_76 , V_95 , V_15 ) ;
V_45 |= V_102 ;
} else {
V_45 = F_140 ( V_82 , V_76 , V_95 ,
V_15 , V_119 , V_16 , V_83 ) ;
if ( V_45 & V_88 ) {
F_170 ( V_16 ) ;
V_45 |= V_102 ;
}
F_139 ( V_16 ) ;
}
F_25 ( V_105 ) ;
goto V_71;
}
if ( F_10 ( F_91 ( V_136 , V_82 ,
V_21 , & V_85 ) ) ) {
F_99 ( V_136 ) ;
if ( V_16 ) {
F_170 ( V_16 ) ;
F_139 ( V_16 ) ;
} else
F_169 ( V_76 , V_95 , V_15 ) ;
V_45 |= V_102 ;
F_25 ( V_105 ) ;
goto V_71;
}
F_25 ( V_106 ) ;
if ( ! V_16 )
F_94 ( V_136 , V_83 , V_31 ) ;
else
F_171 ( V_136 , V_16 , V_83 , V_76 , V_31 ) ;
F_95 ( V_136 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
F_165 ( V_87 ) ;
if ( V_16 )
F_139 ( V_16 ) ;
if ( F_10 ( ! F_131 ( * V_15 , V_119 ) ) ) {
F_98 ( V_87 ) ;
F_93 ( V_136 , V_85 ) ;
F_99 ( V_136 ) ;
goto V_138;
} else {
T_1 V_80 ;
V_80 = F_85 ( V_136 , V_76 -> V_89 ) ;
V_80 = F_83 ( F_101 ( V_80 ) , V_76 ) ;
F_150 ( V_76 , V_83 , V_15 ) ;
F_102 ( V_136 , V_76 , V_83 ) ;
F_103 ( V_136 , V_85 , false ) ;
F_104 ( V_136 , V_76 ) ;
F_106 ( V_82 , V_83 , V_15 , V_80 ) ;
F_134 ( V_76 , V_95 , V_15 ) ;
if ( ! V_16 ) {
F_107 ( V_82 , V_90 , V_31 ) ;
F_32 () ;
} else {
F_89 ( ! F_124 ( V_16 ) , V_16 ) ;
F_161 ( V_16 ) ;
F_99 ( V_16 ) ;
}
V_45 |= V_135 ;
}
F_98 ( V_87 ) ;
V_138:
F_162 ( V_82 , V_127 , V_128 ) ;
V_71:
return V_45 ;
V_117:
F_98 ( V_87 ) ;
return V_45 ;
}
struct V_16 * F_172 ( struct V_75 * V_76 ,
unsigned long V_111 ,
T_1 * V_15 ,
unsigned int V_96 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
struct V_16 * V_16 = NULL ;
F_173 ( F_119 ( V_82 , V_15 ) ) ;
if ( V_96 & V_140 && ! F_174 ( * V_15 ) )
goto V_71;
if ( ( V_96 & V_141 ) && F_17 ( * V_15 ) )
return F_175 ( - V_142 ) ;
if ( ( V_96 & V_143 ) && F_176 ( * V_15 ) )
goto V_71;
V_16 = F_19 ( * V_15 ) ;
F_89 ( ! F_124 ( V_16 ) , V_16 ) ;
if ( V_96 & V_144 ) {
T_1 V_125 ;
V_125 = F_132 ( F_101 ( * V_15 ) ) ;
if ( F_133 ( V_76 , V_111 & V_98 ,
V_15 , V_125 , 1 ) )
F_134 ( V_76 , V_111 , V_15 ) ;
}
if ( ( V_96 & V_145 ) && ( V_76 -> V_77 & V_146 ) ) {
if ( V_16 -> V_147 && F_177 ( V_16 ) ) {
F_178 () ;
if ( V_16 -> V_147 )
F_179 ( V_16 ) ;
F_180 ( V_16 ) ;
}
}
V_16 += ( V_111 & ~ V_98 ) >> V_6 ;
F_89 ( ! F_90 ( V_16 ) , V_16 ) ;
if ( V_96 & V_148 )
F_181 ( V_16 ) ;
V_71:
return V_16 ;
}
int F_182 ( struct V_81 * V_82 , struct V_75 * V_76 ,
unsigned long V_111 , T_1 V_15 , T_1 * V_149 )
{
T_7 * V_87 ;
struct V_118 * V_118 = NULL ;
struct V_16 * V_16 ;
unsigned long V_83 = V_111 & V_98 ;
int V_150 = - 1 , V_151 = F_183 () ;
int V_152 , V_153 = - 1 ;
bool V_154 ;
bool V_155 = false ;
bool V_156 ;
int V_96 = 0 ;
F_33 ( ! ( V_76 -> V_77 & ( V_157 | V_158 | V_78 ) ) ) ;
V_87 = F_96 ( V_82 , V_149 ) ;
if ( F_10 ( ! F_131 ( V_15 , * V_149 ) ) )
goto V_117;
if ( F_10 ( F_184 ( * V_149 ) ) ) {
V_16 = F_19 ( * V_149 ) ;
F_98 ( V_87 ) ;
F_185 ( V_16 ) ;
goto V_71;
}
V_16 = F_19 ( V_15 ) ;
F_33 ( F_18 ( V_16 ) ) ;
V_150 = F_143 ( V_16 ) ;
V_153 = F_186 ( V_16 ) ;
F_187 ( V_159 ) ;
if ( V_150 == V_151 ) {
F_187 ( V_160 ) ;
V_96 |= V_161 ;
}
if ( ! ( V_76 -> V_77 & V_78 ) )
V_96 |= V_162 ;
V_154 = F_177 ( V_16 ) ;
V_152 = F_188 ( V_16 , V_76 , V_83 ) ;
if ( V_152 == - 1 ) {
if ( V_154 )
goto V_163;
}
if ( ! V_154 ) {
F_98 ( V_87 ) ;
F_185 ( V_16 ) ;
V_150 = - 1 ;
goto V_71;
}
F_125 ( V_16 ) ;
F_98 ( V_87 ) ;
V_118 = F_189 ( V_16 ) ;
F_165 ( V_87 ) ;
if ( F_10 ( ! F_131 ( V_15 , * V_149 ) ) ) {
F_180 ( V_16 ) ;
F_99 ( V_16 ) ;
V_150 = - 1 ;
goto V_117;
}
if ( F_10 ( ! V_118 ) ) {
F_99 ( V_16 ) ;
V_150 = - 1 ;
goto V_163;
}
F_98 ( V_87 ) ;
V_155 = F_190 ( V_82 , V_76 ,
V_149 , V_15 , V_111 , V_16 , V_152 ) ;
if ( V_155 ) {
V_96 |= V_164 ;
V_150 = V_152 ;
} else
V_96 |= V_165 ;
goto V_71;
V_163:
F_33 ( ! F_191 ( V_16 ) ) ;
V_156 = F_174 ( V_15 ) ;
V_15 = F_192 ( V_15 , V_76 -> V_89 ) ;
V_15 = F_132 ( V_15 ) ;
if ( V_156 )
V_15 = F_84 ( V_15 ) ;
F_106 ( V_82 , V_83 , V_149 , V_15 ) ;
F_134 ( V_76 , V_111 , V_149 ) ;
F_180 ( V_16 ) ;
V_117:
F_98 ( V_87 ) ;
V_71:
if ( V_118 )
F_193 ( V_118 ) ;
if ( V_150 != - 1 )
F_194 ( V_153 , V_150 , V_31 , V_96 ) ;
return 0 ;
}
int F_195 ( struct V_166 * V_167 , struct V_75 * V_76 ,
T_1 * V_15 , unsigned long V_111 )
{
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_196 ( V_15 , V_76 , & V_87 ) == 1 ) {
struct V_16 * V_16 ;
T_6 V_86 ;
T_1 V_119 ;
V_119 = F_197 ( V_167 -> V_82 , V_111 , V_15 ,
V_167 -> V_168 ) ;
F_198 ( V_167 , V_15 , V_111 ) ;
V_86 = F_151 ( V_167 -> V_82 , V_15 ) ;
if ( F_17 ( V_119 ) ) {
F_199 ( & V_167 -> V_82 -> V_91 ) ;
F_98 ( V_87 ) ;
F_32 () ;
} else {
V_16 = F_19 ( V_119 ) ;
F_161 ( V_16 ) ;
F_89 ( F_166 ( V_16 ) < 0 , V_16 ) ;
F_107 ( V_167 -> V_82 , V_90 , - V_31 ) ;
F_89 ( ! F_124 ( V_16 ) , V_16 ) ;
F_199 ( & V_167 -> V_82 -> V_91 ) ;
F_98 ( V_87 ) ;
F_200 ( V_167 , V_16 ) ;
}
F_100 ( V_167 -> V_82 , V_86 ) ;
V_45 = 1 ;
}
return V_45 ;
}
int F_201 ( struct V_75 * V_76 , struct V_75 * V_169 ,
unsigned long V_170 ,
unsigned long V_171 , unsigned long V_172 ,
T_1 * V_173 , T_1 * V_174 )
{
T_7 * V_175 , * V_176 ;
int V_45 = 0 ;
T_1 V_15 ;
struct V_81 * V_82 = V_76 -> V_139 ;
if ( ( V_170 & ~ V_98 ) ||
( V_171 & ~ V_98 ) ||
V_172 - V_170 < V_100 ||
( V_169 -> V_77 & V_177 ) )
goto V_71;
if ( F_202 ( ! F_97 ( * V_174 ) ) ) {
F_42 ( F_121 ( * V_174 ) ) ;
goto V_71;
}
V_45 = F_196 ( V_173 , V_76 , & V_175 ) ;
if ( V_45 == 1 ) {
V_176 = F_119 ( V_82 , V_174 ) ;
if ( V_176 != V_175 )
F_120 ( V_176 , V_115 ) ;
V_15 = F_203 ( V_82 , V_170 , V_173 ) ;
F_42 ( ! F_97 ( * V_174 ) ) ;
if ( F_204 ( V_176 , V_175 ) ) {
T_6 V_86 ;
V_86 = F_151 ( V_82 , V_173 ) ;
F_105 ( V_82 , V_174 , V_86 ) ;
}
F_106 ( V_82 , V_171 , V_174 , F_205 ( V_15 ) ) ;
if ( V_176 != V_175 )
F_98 ( V_176 ) ;
F_98 ( V_175 ) ;
}
V_71:
return V_45 ;
}
int F_206 ( struct V_75 * V_76 , T_1 * V_15 ,
unsigned long V_111 , T_5 V_178 , int V_179 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
int V_45 = 0 ;
if ( F_196 ( V_15 , V_76 , & V_87 ) == 1 ) {
T_1 V_80 ;
bool V_180 = V_179 && F_174 ( * V_15 ) ;
V_45 = 1 ;
if ( V_179 && F_17 ( * V_15 ) ) {
F_98 ( V_87 ) ;
return V_45 ;
}
if ( ! V_179 || ! F_176 ( * V_15 ) ) {
V_80 = F_207 ( V_82 , V_111 , V_15 ) ;
V_80 = F_192 ( V_80 , V_178 ) ;
if ( V_180 )
V_80 = F_84 ( V_80 ) ;
V_45 = V_31 ;
F_106 ( V_82 , V_111 , V_15 , V_80 ) ;
F_33 ( ! V_180 && F_174 ( V_80 ) ) ;
}
F_98 ( V_87 ) ;
}
return V_45 ;
}
int F_196 ( T_1 * V_15 , struct V_75 * V_76 ,
T_7 * * V_87 )
{
* V_87 = F_96 ( V_76 -> V_139 , V_15 ) ;
if ( F_21 ( F_121 ( * V_15 ) ) ) {
if ( F_10 ( F_122 ( * V_15 ) ) ) {
F_98 ( * V_87 ) ;
F_123 ( V_76 -> V_118 , V_15 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_98 ( * V_87 ) ;
return 0 ;
}
T_1 * F_208 ( struct V_16 * V_16 ,
struct V_81 * V_82 ,
unsigned long V_95 ,
enum V_181 V_47 ,
T_7 * * V_87 )
{
T_10 * V_182 ;
T_11 * V_183 ;
T_1 * V_15 ;
if ( V_95 & ~ V_98 )
return NULL ;
V_182 = F_209 ( V_82 , V_95 ) ;
if ( ! F_210 ( * V_182 ) )
return NULL ;
V_183 = F_211 ( V_182 , V_95 ) ;
if ( ! F_212 ( * V_183 ) )
return NULL ;
V_15 = F_213 ( V_183 , V_95 ) ;
* V_87 = F_96 ( V_82 , V_15 ) ;
if ( ! F_214 ( * V_15 ) )
goto V_121;
if ( F_19 ( * V_15 ) != V_16 )
goto V_121;
if ( V_47 == V_184 &&
F_122 ( * V_15 ) )
goto V_121;
if ( F_121 ( * V_15 ) ) {
F_42 ( V_47 == V_185 &&
! F_122 ( * V_15 ) ) ;
return V_15 ;
}
V_121:
F_98 ( * V_87 ) ;
return NULL ;
}
static int F_215 ( struct V_16 * V_16 ,
struct V_75 * V_76 ,
unsigned long V_95 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_15 ;
int V_45 = 0 ;
const unsigned long V_127 = V_95 ;
const unsigned long V_128 = V_95 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_15 = F_208 ( V_16 , V_82 , V_95 ,
V_184 , & V_87 ) ;
if ( V_15 ) {
F_216 ( V_76 , V_95 , V_15 ) ;
V_45 = 1 ;
F_98 ( V_87 ) ;
}
F_162 ( V_82 , V_127 , V_128 ) ;
return V_45 ;
}
static void F_217 ( struct V_16 * V_16 ,
struct V_186 * V_187 )
{
int V_126 ;
struct V_1 * V_1 = F_218 ( V_16 ) ;
struct V_188 * V_188 ;
int V_189 = 0 ;
F_219 ( & V_1 -> V_190 ) ;
V_188 = F_220 ( V_16 , V_1 ) ;
F_221 ( V_16 ) ;
F_222 ( V_16 ) ;
for ( V_126 = V_31 - 1 ; V_126 >= 1 ; V_126 -- ) {
struct V_16 * V_191 = V_16 + V_126 ;
F_33 ( F_166 ( V_191 ) < 0 ) ;
V_189 += F_166 ( V_191 ) ;
F_33 ( V_189 < 0 ) ;
F_33 ( F_36 ( & V_191 -> V_124 ) != 0 ) ;
F_137 ( F_166 ( V_16 ) + F_166 ( V_191 ) + 1 ,
& V_191 -> V_124 ) ;
F_223 () ;
V_191 -> V_96 &= ~ V_192 | V_193 ;
V_191 -> V_96 |= ( V_16 -> V_96 &
( ( 1L << V_194 ) |
( 1L << V_195 ) |
( 1L << V_196 ) |
( 1L << V_197 ) |
( 1L << V_198 ) |
( 1L << V_199 ) ) ) ;
V_191 -> V_96 |= ( 1L << V_200 ) ;
F_160 () ;
V_191 -> V_201 = V_16 -> V_201 ;
F_33 ( V_191 -> V_147 ) ;
V_191 -> V_147 = V_16 -> V_147 ;
V_191 -> V_202 = V_16 -> V_202 + V_126 ;
F_224 ( V_191 , F_186 ( V_16 ) ) ;
F_33 ( ! F_225 ( V_191 ) ) ;
F_33 ( ! F_226 ( V_191 ) ) ;
F_33 ( ! F_227 ( V_191 ) ) ;
F_33 ( ! F_228 ( V_191 ) ) ;
F_229 ( V_16 , V_191 , V_188 , V_187 ) ;
}
F_230 ( V_189 , & V_16 -> V_124 ) ;
F_33 ( F_36 ( & V_16 -> V_124 ) <= 0 ) ;
F_231 ( V_1 , V_203 , - 1 ) ;
F_232 ( V_16 ) ;
F_233 ( V_16 ) ;
F_234 ( & V_1 -> V_190 ) ;
for ( V_126 = 1 ; V_126 < V_31 ; V_126 ++ ) {
struct V_16 * V_191 = V_16 + V_126 ;
F_33 ( F_235 ( V_191 ) <= 0 ) ;
F_99 ( V_191 ) ;
}
F_33 ( F_235 ( V_16 ) <= 0 ) ;
}
static int F_236 ( struct V_16 * V_16 ,
struct V_75 * V_76 ,
unsigned long V_95 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_7 * V_87 ;
T_1 * V_15 , V_125 ;
int V_45 = 0 , V_126 ;
T_6 V_86 ;
unsigned long V_83 ;
V_15 = F_208 ( V_16 , V_82 , V_95 ,
V_185 , & V_87 ) ;
if ( V_15 ) {
V_86 = F_151 ( V_82 , V_15 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
if ( F_174 ( * V_15 ) )
F_33 ( F_166 ( V_16 ) != 1 ) ;
V_83 = V_95 ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
F_33 ( F_90 ( V_16 + V_126 ) ) ;
V_80 = F_153 ( V_16 + V_126 , V_76 -> V_89 ) ;
V_80 = F_154 ( F_155 ( V_80 ) , V_76 ) ;
if ( ! F_174 ( * V_15 ) )
V_80 = F_237 ( V_80 ) ;
if ( ! F_238 ( * V_15 ) )
V_80 = F_239 ( V_80 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_33 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_160 () ;
F_240 ( V_76 , V_95 , V_15 ) ;
F_152 ( V_82 , V_15 , V_86 ) ;
V_45 = 1 ;
F_98 ( V_87 ) ;
}
return V_45 ;
}
static void F_241 ( struct V_16 * V_16 ,
struct V_118 * V_118 ,
struct V_186 * V_187 )
{
int V_204 , V_205 ;
T_12 V_206 = V_16 -> V_202 << ( V_207 - V_6 ) ;
struct V_208 * V_209 ;
F_33 ( ! F_124 ( V_16 ) ) ;
F_33 ( F_242 ( V_16 ) ) ;
V_204 = 0 ;
F_243 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_209 -> V_76 ;
unsigned long V_111 = F_244 ( V_16 , V_76 ) ;
F_33 ( F_245 ( V_76 ) ) ;
V_204 += F_215 ( V_16 , V_76 , V_111 ) ;
}
if ( V_204 != F_166 ( V_16 ) ) {
F_12 ( L_17 ,
V_204 , F_166 ( V_16 ) ) ;
F_246 () ;
}
F_217 ( V_16 , V_187 ) ;
V_205 = 0 ;
F_243 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_75 * V_76 = V_209 -> V_76 ;
unsigned long V_111 = F_244 ( V_16 , V_76 ) ;
F_33 ( F_245 ( V_76 ) ) ;
V_205 += F_236 ( V_16 , V_76 , V_111 ) ;
}
if ( V_204 != V_205 ) {
F_12 ( L_18 ,
V_204 , V_205 , F_166 ( V_16 ) ) ;
F_246 () ;
}
}
int F_247 ( struct V_16 * V_16 , struct V_186 * V_187 )
{
struct V_118 * V_118 ;
int V_45 = 1 ;
F_33 ( F_18 ( V_16 ) ) ;
F_33 ( ! F_225 ( V_16 ) ) ;
V_118 = F_248 ( V_16 ) ;
if ( ! V_118 )
goto V_71;
F_249 ( V_118 ) ;
V_45 = 0 ;
if ( ! F_90 ( V_16 ) )
goto V_117;
F_33 ( ! F_228 ( V_16 ) ) ;
F_241 ( V_16 , V_118 , V_187 ) ;
F_25 ( V_210 ) ;
F_33 ( F_90 ( V_16 ) ) ;
V_117:
F_250 ( V_118 ) ;
F_251 ( V_118 ) ;
V_71:
return V_45 ;
}
int F_252 ( struct V_75 * V_76 ,
unsigned long * V_77 , int V_211 )
{
switch ( V_211 ) {
case V_212 :
#ifdef F_253
if ( F_254 ( V_76 -> V_139 ) )
return 0 ;
#endif
if ( * V_77 & ( V_213 | V_214 ) )
return - V_42 ;
* V_77 &= ~ V_177 ;
* V_77 |= V_213 ;
if ( F_10 ( F_255 ( V_76 , * V_77 ) ) )
return - V_66 ;
break;
case V_215 :
if ( * V_77 & ( V_177 | V_214 ) )
return - V_42 ;
* V_77 &= ~ V_213 ;
* V_77 |= V_177 ;
break;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
V_216 = F_256 ( L_19 ,
sizeof( struct V_217 ) ,
F_257 ( struct V_217 ) , 0 , NULL ) ;
if ( ! V_216 )
return - V_66 ;
return 0 ;
}
static inline struct V_217 * F_258 ( void )
{
if ( ! V_216 )
return NULL ;
return F_259 ( V_216 , V_129 ) ;
}
static inline void F_260 ( struct V_217 * V_217 )
{
F_261 ( V_216 , V_217 ) ;
}
static struct V_217 * F_262 ( struct V_81 * V_82 )
{
struct V_217 * V_217 ;
F_263 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_82 == V_217 -> V_82 )
return V_217 ;
return NULL ;
}
static void F_264 ( struct V_81 * V_82 ,
struct V_217 * V_217 )
{
V_217 -> V_82 = V_82 ;
F_265 ( V_218 , & V_217 -> V_219 , ( long ) V_82 ) ;
}
static inline int F_266 ( struct V_81 * V_82 )
{
return F_36 ( & V_82 -> V_220 ) == 0 ;
}
int F_267 ( struct V_81 * V_82 )
{
struct V_217 * V_217 ;
int V_221 ;
V_217 = F_258 () ;
if ( ! V_217 )
return - V_66 ;
F_268 ( F_266 ( V_82 ) , V_82 ) ;
if ( F_10 ( F_269 ( V_222 , & V_82 -> V_96 ) ) ) {
F_260 ( V_217 ) ;
return 0 ;
}
F_165 ( & V_223 ) ;
F_264 ( V_82 , V_217 ) ;
V_221 = F_14 ( & V_12 . V_13 ) ;
F_270 ( & V_217 -> V_224 , & V_12 . V_13 ) ;
F_98 ( & V_223 ) ;
F_271 ( & V_82 -> V_225 ) ;
if ( V_221 )
F_15 ( & V_14 ) ;
return 0 ;
}
int F_255 ( struct V_75 * V_76 ,
unsigned long V_77 )
{
unsigned long V_226 , V_227 ;
if ( ! V_76 -> V_118 )
return 0 ;
if ( V_76 -> V_228 )
return 0 ;
F_164 ( V_77 & V_214 , V_76 ) ;
V_226 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_227 = V_76 -> V_101 & V_98 ;
if ( V_226 < V_227 )
return F_113 ( V_76 , V_77 ) ;
return 0 ;
}
void F_272 ( struct V_81 * V_82 )
{
struct V_217 * V_217 ;
int free = 0 ;
F_165 ( & V_223 ) ;
V_217 = F_262 ( V_82 ) ;
if ( V_217 && V_12 . V_217 != V_217 ) {
F_273 ( & V_217 -> V_219 ) ;
F_274 ( & V_217 -> V_224 ) ;
free = 1 ;
}
F_98 ( & V_223 ) ;
if ( free ) {
F_45 ( V_222 , & V_82 -> V_96 ) ;
F_260 ( V_217 ) ;
F_275 ( V_82 ) ;
} else if ( V_217 ) {
F_276 ( & V_82 -> V_229 ) ;
F_277 ( & V_82 -> V_229 ) ;
}
}
static void F_278 ( struct V_16 * V_16 )
{
F_279 ( V_16 , V_230 + 0 ) ;
F_180 ( V_16 ) ;
F_280 ( V_16 ) ;
}
static void F_281 ( T_9 * V_134 , T_9 * V_231 )
{
while ( -- V_231 >= V_134 ) {
T_9 V_232 = * V_231 ;
if ( ! F_157 ( V_232 ) )
F_278 ( F_282 ( V_232 ) ) ;
}
}
static int F_283 ( struct V_75 * V_76 ,
unsigned long V_95 ,
T_9 * V_134 )
{
struct V_16 * V_16 ;
T_9 * V_231 ;
int V_233 = 0 ;
bool V_234 = false , V_235 = false ;
for ( V_231 = V_134 ; V_231 < V_134 + V_31 ;
V_231 ++ , V_95 += V_132 ) {
T_9 V_232 = * V_231 ;
if ( F_157 ( V_232 ) ) {
if ( ++ V_233 <= V_62 )
continue;
else
goto V_71;
}
if ( ! F_284 ( V_232 ) )
goto V_71;
V_16 = F_285 ( V_76 , V_95 , V_232 ) ;
if ( F_10 ( ! V_16 ) )
goto V_71;
F_89 ( F_90 ( V_16 ) , V_16 ) ;
F_89 ( ! F_225 ( V_16 ) , V_16 ) ;
F_89 ( ! F_228 ( V_16 ) , V_16 ) ;
if ( ! F_177 ( V_16 ) )
goto V_71;
if ( F_235 ( V_16 ) != 1 + ! ! F_286 ( V_16 ) ) {
F_180 ( V_16 ) ;
goto V_71;
}
if ( F_287 ( V_232 ) ) {
V_235 = true ;
} else {
if ( F_286 ( V_16 ) && ! F_288 ( V_16 ) ) {
F_180 ( V_16 ) ;
goto V_71;
}
}
if ( F_289 ( V_16 ) ) {
F_180 ( V_16 ) ;
goto V_71;
}
F_290 ( V_16 , V_230 + 0 ) ;
F_89 ( ! F_191 ( V_16 ) , V_16 ) ;
F_89 ( F_291 ( V_16 ) , V_16 ) ;
if ( F_292 ( V_232 ) || F_293 ( V_16 ) ||
F_294 ( V_76 -> V_139 , V_95 ) )
V_234 = true ;
}
if ( F_21 ( V_234 && V_235 ) )
return 1 ;
V_71:
F_281 ( V_134 , V_231 ) ;
return 0 ;
}
static void F_295 ( T_9 * V_134 , struct V_16 * V_16 ,
struct V_75 * V_76 ,
unsigned long V_95 ,
T_7 * V_87 )
{
T_9 * V_231 ;
for ( V_231 = V_134 ; V_231 < V_134 + V_31 ; V_231 ++ ) {
T_9 V_232 = * V_231 ;
struct V_16 * V_114 ;
if ( F_157 ( V_232 ) ) {
F_296 ( V_16 , V_95 ) ;
F_107 ( V_76 -> V_139 , V_90 , 1 ) ;
} else {
V_114 = F_282 ( V_232 ) ;
F_147 ( V_16 , V_114 , V_95 , V_76 ) ;
F_89 ( F_166 ( V_114 ) != 1 , V_114 ) ;
F_278 ( V_114 ) ;
F_165 ( V_87 ) ;
F_297 ( V_76 -> V_139 , V_95 , V_231 ) ;
F_161 ( V_114 ) ;
F_98 ( V_87 ) ;
F_298 ( V_114 ) ;
}
V_95 += V_132 ;
V_16 ++ ;
}
}
static void F_299 ( void )
{
F_300 ( V_14 , false ,
F_301 ( V_56 ) ) ;
}
static bool F_302 ( int V_236 )
{
int V_126 ;
if ( ! V_237 )
return false ;
if ( V_238 [ V_236 ] )
return false ;
for ( V_126 = 0 ; V_126 < V_239 ; V_126 ++ ) {
if ( ! V_238 [ V_126 ] )
continue;
if ( F_303 ( V_236 , V_126 ) > V_240 )
return true ;
}
return false ;
}
static int F_304 ( void )
{
static int V_241 = V_242 ;
int V_236 , V_243 = 0 , V_244 = 0 ;
for ( V_236 = 0 ; V_236 < V_239 ; V_236 ++ )
if ( V_238 [ V_236 ] > V_244 ) {
V_244 = V_238 [ V_236 ] ;
V_243 = V_236 ;
}
if ( V_243 <= V_241 )
for ( V_236 = V_241 + 1 ; V_236 < V_239 ;
V_236 ++ )
if ( V_244 == V_238 [ V_236 ] ) {
V_243 = V_236 ;
break;
}
V_241 = V_243 ;
return V_243 ;
}
static bool F_305 ( struct V_16 * * V_245 , bool * V_246 )
{
if ( F_11 ( * V_245 ) ) {
if ( ! * V_246 )
return false ;
* V_246 = false ;
* V_245 = NULL ;
F_299 () ;
} else if ( * V_245 ) {
F_99 ( * V_245 ) ;
* V_245 = NULL ;
}
return true ;
}
static struct V_16
* F_306 ( struct V_16 * * V_245 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_95 ,
int V_247 )
{
F_89 ( * V_245 , * V_245 ) ;
F_307 ( & V_82 -> V_229 ) ;
* V_245 = F_308 ( V_247 , F_109 (
F_309 () , V_131 ) , V_24 ) ;
if ( F_10 ( ! * V_245 ) ) {
F_25 ( V_248 ) ;
* V_245 = F_175 ( - V_66 ) ;
return NULL ;
}
F_25 ( V_249 ) ;
return * V_245 ;
}
static int F_304 ( void )
{
return 0 ;
}
static inline struct V_16 * F_310 ( int V_92 )
{
return F_24 ( F_109 ( V_92 , 0 ) ,
V_24 ) ;
}
static struct V_16 * F_311 ( bool * V_246 )
{
struct V_16 * V_245 ;
do {
V_245 = F_310 ( F_309 () ) ;
if ( ! V_245 ) {
F_25 ( V_248 ) ;
if ( ! * V_246 )
return NULL ;
* V_246 = false ;
F_299 () ;
} else
F_25 ( V_249 ) ;
} while ( F_10 ( ! V_245 ) && F_21 ( F_2 () ) );
return V_245 ;
}
static bool F_305 ( struct V_16 * * V_245 , bool * V_246 )
{
if ( ! * V_245 )
* V_245 = F_311 ( V_246 ) ;
if ( F_10 ( ! * V_245 ) )
return false ;
return true ;
}
static struct V_16
* F_306 ( struct V_16 * * V_245 , struct V_81 * V_82 ,
struct V_75 * V_76 , unsigned long V_95 ,
int V_247 )
{
F_307 ( & V_82 -> V_229 ) ;
F_42 ( ! * V_245 ) ;
return * V_245 ;
}
static bool F_312 ( struct V_75 * V_76 )
{
if ( ( ! ( V_76 -> V_77 & V_213 ) && ! F_313 () ) ||
( V_76 -> V_77 & V_177 ) )
return false ;
if ( ! V_76 -> V_118 || V_76 -> V_228 )
return false ;
if ( F_245 ( V_76 ) )
return false ;
F_164 ( V_76 -> V_77 & V_214 , V_76 ) ;
return true ;
}
static void F_314 ( struct V_81 * V_82 ,
unsigned long V_95 ,
struct V_16 * * V_245 ,
struct V_75 * V_76 ,
int V_247 )
{
T_1 * V_15 , V_125 ;
T_9 * V_134 ;
T_6 V_86 ;
struct V_16 * V_136 ;
T_7 * V_250 , * V_251 ;
int V_252 ;
unsigned long V_226 , V_227 ;
struct V_84 * V_85 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_42 ( V_95 & ~ V_98 ) ;
V_136 = F_306 ( V_245 , V_82 , V_76 , V_95 , V_247 ) ;
if ( ! V_136 )
return;
if ( F_10 ( F_91 ( V_136 , V_82 ,
V_21 , & V_85 ) ) )
return;
F_276 ( & V_82 -> V_229 ) ;
if ( F_10 ( F_266 ( V_82 ) ) )
goto V_71;
V_76 = F_315 ( V_82 , V_95 ) ;
if ( ! V_76 )
goto V_71;
V_226 = ( V_76 -> V_99 + ~ V_98 ) & V_98 ;
V_227 = V_76 -> V_101 & V_98 ;
if ( V_95 < V_226 || V_95 + V_100 > V_227 )
goto V_71;
if ( ! F_312 ( V_76 ) )
goto V_71;
V_15 = F_316 ( V_82 , V_95 ) ;
if ( ! V_15 )
goto V_71;
F_249 ( V_76 -> V_118 ) ;
V_134 = F_156 ( V_15 , V_95 ) ;
V_251 = F_317 ( V_82 , V_15 ) ;
V_127 = V_95 ;
V_128 = V_95 + V_100 ;
F_149 ( V_82 , V_127 , V_128 ) ;
V_250 = F_96 ( V_82 , V_15 ) ;
V_125 = F_318 ( V_76 , V_95 , V_15 ) ;
F_98 ( V_250 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
F_165 ( V_251 ) ;
V_252 = F_283 ( V_76 , V_95 , V_134 ) ;
F_98 ( V_251 ) ;
if ( F_10 ( ! V_252 ) ) {
F_159 ( V_134 ) ;
F_165 ( V_250 ) ;
F_33 ( ! F_97 ( * V_15 ) ) ;
F_152 ( V_82 , V_15 , F_319 ( V_125 ) ) ;
F_98 ( V_250 ) ;
F_250 ( V_76 -> V_118 ) ;
goto V_71;
}
F_250 ( V_76 -> V_118 ) ;
F_295 ( V_134 , V_136 , V_76 , V_95 , V_251 ) ;
F_159 ( V_134 ) ;
F_95 ( V_136 ) ;
V_86 = F_319 ( V_125 ) ;
V_125 = F_85 ( V_136 , V_76 -> V_89 ) ;
V_125 = F_83 ( F_101 ( V_125 ) , V_76 ) ;
F_160 () ;
F_165 ( V_250 ) ;
F_33 ( ! F_97 ( * V_15 ) ) ;
F_102 ( V_136 , V_76 , V_95 ) ;
F_103 ( V_136 , V_85 , false ) ;
F_104 ( V_136 , V_76 ) ;
F_105 ( V_82 , V_15 , V_86 ) ;
F_106 ( V_82 , V_95 , V_15 , V_125 ) ;
F_134 ( V_76 , V_95 , V_15 ) ;
F_98 ( V_250 ) ;
* V_245 = NULL ;
V_59 ++ ;
V_253:
F_277 ( & V_82 -> V_229 ) ;
return;
V_71:
F_93 ( V_136 , V_85 ) ;
goto V_253;
}
static int F_320 ( struct V_81 * V_82 ,
struct V_75 * V_76 ,
unsigned long V_95 ,
struct V_16 * * V_245 )
{
T_1 * V_15 ;
T_9 * V_134 , * V_231 ;
int V_45 = 0 , V_233 = 0 ;
struct V_16 * V_16 ;
unsigned long V_254 ;
T_7 * V_87 ;
int V_247 = V_242 ;
bool V_235 = false , V_234 = false ;
F_42 ( V_95 & ~ V_98 ) ;
V_15 = F_316 ( V_82 , V_95 ) ;
if ( ! V_15 )
goto V_71;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
V_134 = F_321 ( V_82 , V_15 , V_95 , & V_87 ) ;
for ( V_254 = V_95 , V_231 = V_134 ; V_231 < V_134 + V_31 ;
V_231 ++ , V_254 += V_132 ) {
T_9 V_232 = * V_231 ;
if ( F_157 ( V_232 ) ) {
if ( ++ V_233 <= V_62 )
continue;
else
goto V_255;
}
if ( ! F_284 ( V_232 ) )
goto V_255;
if ( F_287 ( V_232 ) )
V_235 = true ;
V_16 = F_285 ( V_76 , V_254 , V_232 ) ;
if ( F_10 ( ! V_16 ) )
goto V_255;
V_247 = F_143 ( V_16 ) ;
if ( F_302 ( V_247 ) )
goto V_255;
V_238 [ V_247 ] ++ ;
F_89 ( F_90 ( V_16 ) , V_16 ) ;
if ( ! F_291 ( V_16 ) || F_191 ( V_16 ) || ! F_225 ( V_16 ) )
goto V_255;
if ( F_235 ( V_16 ) != 1 + ! ! F_286 ( V_16 ) )
goto V_255;
if ( F_292 ( V_232 ) || F_293 ( V_16 ) ||
F_294 ( V_76 -> V_139 , V_95 ) )
V_234 = true ;
}
if ( V_234 && V_235 )
V_45 = 1 ;
V_255:
F_322 ( V_134 , V_87 ) ;
if ( V_45 ) {
V_247 = F_304 () ;
F_314 ( V_82 , V_95 , V_245 , V_76 , V_247 ) ;
}
V_71:
return V_45 ;
}
static void F_323 ( struct V_217 * V_217 )
{
struct V_81 * V_82 = V_217 -> V_82 ;
F_42 ( V_256 != 1 && ! F_324 ( & V_223 ) ) ;
if ( F_266 ( V_82 ) ) {
F_273 ( & V_217 -> V_219 ) ;
F_274 ( & V_217 -> V_224 ) ;
F_260 ( V_217 ) ;
F_275 ( V_82 ) ;
}
}
static unsigned int F_325 ( unsigned int V_58 ,
struct V_16 * * V_245 )
__releases( &khugepaged_mm_lock
static int F_326 ( void )
{
return ! F_14 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_327 ( void )
{
return ! F_14 ( & V_12 . V_13 ) ||
F_328 () ;
}
static void F_329 ( void )
{
struct V_16 * V_245 = NULL ;
unsigned int V_257 = 0 , V_258 = 0 ;
unsigned int V_58 = V_57 ;
bool V_246 = true ;
F_330 () ;
while ( V_257 < V_58 ) {
if ( ! F_305 ( & V_245 , & V_246 ) )
break;
F_148 () ;
if ( F_10 ( F_328 () || F_331 ( V_259 ) ) )
break;
F_165 ( & V_223 ) ;
if ( ! V_12 . V_217 )
V_258 ++ ;
if ( F_326 () &&
V_258 < 2 )
V_257 += F_325 ( V_58 - V_257 ,
& V_245 ) ;
else
V_257 = V_58 ;
F_98 ( & V_223 ) ;
}
if ( ! F_332 ( V_245 ) )
F_99 ( V_245 ) ;
}
static void F_333 ( void )
{
F_334 () ;
if ( F_326 () ) {
if ( ! V_53 )
return;
F_300 ( V_14 ,
F_328 () ,
F_301 ( V_53 ) ) ;
return;
}
if ( F_2 () )
F_335 ( V_14 , F_327 () ) ;
}
static int V_11 ( void * V_233 )
{
struct V_217 * V_217 ;
F_336 () ;
F_337 ( V_259 , V_260 ) ;
while ( ! F_328 () ) {
F_329 () ;
F_333 () ;
}
F_165 ( & V_223 ) ;
V_217 = V_12 . V_217 ;
V_12 . V_217 = NULL ;
if ( V_217 )
F_323 ( V_217 ) ;
F_98 ( & V_223 ) ;
return 0 ;
}
static void F_338 ( struct V_75 * V_76 ,
unsigned long V_83 , T_1 * V_15 )
{
struct V_81 * V_82 = V_76 -> V_139 ;
T_6 V_86 ;
T_1 V_125 ;
int V_126 ;
F_150 ( V_76 , V_83 , V_15 ) ;
V_86 = F_151 ( V_82 , V_15 ) ;
F_152 ( V_82 , & V_125 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_31 ; V_126 ++ , V_83 += V_132 ) {
T_9 * V_134 , V_80 ;
V_80 = F_339 ( F_340 ( V_83 ) , V_76 -> V_89 ) ;
V_80 = F_341 ( V_80 ) ;
V_134 = F_156 ( & V_125 , V_83 ) ;
F_42 ( ! F_157 ( * V_134 ) ) ;
F_158 ( V_82 , V_83 , V_134 , V_80 ) ;
F_159 ( V_134 ) ;
}
F_160 () ;
F_152 ( V_82 , V_15 , V_86 ) ;
F_32 () ;
}
void F_342 ( struct V_75 * V_76 , unsigned long V_95 ,
T_1 * V_15 )
{
T_7 * V_87 ;
struct V_16 * V_16 ;
struct V_81 * V_82 = V_76 -> V_139 ;
unsigned long V_83 = V_95 & V_98 ;
unsigned long V_127 ;
unsigned long V_128 ;
F_33 ( V_76 -> V_99 > V_83 || V_76 -> V_101 < V_83 + V_100 ) ;
V_127 = V_83 ;
V_128 = V_83 + V_100 ;
V_261:
F_149 ( V_82 , V_127 , V_128 ) ;
V_87 = F_96 ( V_82 , V_15 ) ;
if ( F_10 ( ! F_121 ( * V_15 ) ) ) {
F_98 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
return;
}
if ( F_17 ( * V_15 ) ) {
F_338 ( V_76 , V_83 , V_15 ) ;
F_98 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
return;
}
V_16 = F_19 ( * V_15 ) ;
F_89 ( ! F_235 ( V_16 ) , V_16 ) ;
F_125 ( V_16 ) ;
F_98 ( V_87 ) ;
F_162 ( V_82 , V_127 , V_128 ) ;
F_170 ( V_16 ) ;
F_99 ( V_16 ) ;
if ( F_10 ( F_121 ( * V_15 ) ) )
goto V_261;
}
void F_343 ( struct V_81 * V_82 , unsigned long V_95 ,
T_1 * V_15 )
{
struct V_75 * V_76 ;
V_76 = F_315 ( V_82 , V_95 ) ;
F_33 ( V_76 == NULL ) ;
F_169 ( V_76 , V_95 , V_15 ) ;
}
static void F_344 ( struct V_81 * V_82 ,
unsigned long V_95 )
{
T_10 * V_182 ;
T_11 * V_183 ;
T_1 * V_15 ;
F_42 ( ! ( V_95 & ~ V_98 ) ) ;
V_182 = F_209 ( V_82 , V_95 ) ;
if ( ! F_210 ( * V_182 ) )
return;
V_183 = F_211 ( V_182 , V_95 ) ;
if ( ! F_212 ( * V_183 ) )
return;
V_15 = F_213 ( V_183 , V_95 ) ;
if ( ! F_214 ( * V_15 ) )
return;
F_343 ( V_82 , V_95 , V_15 ) ;
}
void F_345 ( struct V_75 * V_76 ,
unsigned long V_262 ,
unsigned long V_263 ,
long V_264 )
{
if ( V_262 & ~ V_98 &&
( V_262 & V_98 ) >= V_76 -> V_99 &&
( V_262 & V_98 ) + V_100 <= V_76 -> V_101 )
F_344 ( V_76 -> V_139 , V_262 ) ;
if ( V_263 & ~ V_98 &&
( V_263 & V_98 ) >= V_76 -> V_99 &&
( V_263 & V_98 ) + V_100 <= V_76 -> V_101 )
F_344 ( V_76 -> V_139 , V_263 ) ;
if ( V_264 > 0 ) {
struct V_75 * V_265 = V_76 -> V_266 ;
unsigned long V_267 = V_265 -> V_99 ;
V_267 += V_264 << V_6 ;
if ( V_267 & ~ V_98 &&
( V_267 & V_98 ) >= V_265 -> V_99 &&
( V_267 & V_98 ) + V_100 <= V_265 -> V_101 )
F_344 ( V_265 -> V_139 , V_267 ) ;
}
}
