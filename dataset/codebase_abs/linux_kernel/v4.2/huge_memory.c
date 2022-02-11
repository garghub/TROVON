static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
F_2 (zone)
V_2 ++ ;
V_3 = V_4 * V_2 * 2 ;
V_3 += V_4 * V_2 *
V_5 * V_5 ;
V_3 = F_3 ( V_3 ,
( unsigned long ) F_4 () / 20 ) ;
V_3 <<= ( V_6 - 10 ) ;
if ( V_3 > V_7 ) {
if ( V_8 >= 0 )
F_5 ( L_1
L_2 ,
V_7 , V_3 ) ;
V_7 = V_3 ;
}
F_6 () ;
return 0 ;
}
static int F_7 ( void )
{
int V_9 = 0 ;
if ( F_8 () ) {
if ( ! V_10 )
V_10 = F_9 ( V_11 , NULL ,
L_3 ) ;
if ( F_10 ( F_11 ( V_10 ) ) ) {
F_12 ( L_4 ) ;
V_9 = F_13 ( V_10 ) ;
V_10 = NULL ;
goto V_12;
}
if ( ! F_14 ( & V_13 . V_14 ) )
F_15 ( & V_15 ) ;
F_1 () ;
} else if ( V_10 ) {
F_16 ( V_10 ) ;
V_10 = NULL ;
}
V_12:
return V_9 ;
}
static inline bool F_17 ( T_1 V_16 )
{
return F_18 ( F_19 ( V_16 ) ) ;
}
static struct V_17 * F_20 ( void )
{
struct V_17 * V_18 ;
V_19:
if ( F_21 ( F_22 ( & V_20 ) ) )
return F_23 ( V_21 ) ;
V_18 = F_24 ( ( V_22 | V_23 ) & ~ V_24 ,
V_25 ) ;
if ( ! V_18 ) {
F_25 ( V_26 ) ;
return NULL ;
}
F_25 ( V_27 ) ;
F_26 () ;
if ( F_27 ( & V_21 , NULL , V_18 ) ) {
F_28 () ;
F_29 ( V_18 , F_30 ( V_18 ) ) ;
goto V_19;
}
F_31 ( & V_20 , 2 ) ;
F_28 () ;
return F_23 ( V_21 ) ;
}
static void F_32 ( void )
{
F_33 ( F_34 ( & V_20 ) ) ;
}
static unsigned long F_35 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
return F_36 ( & V_20 ) == 1 ? V_32 : 0 ;
}
static unsigned long F_37 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
if ( F_38 ( & V_20 , 1 , 0 ) == 1 ) {
struct V_17 * V_18 = F_39 ( & V_21 , NULL ) ;
F_33 ( V_18 == NULL ) ;
F_29 ( V_18 , F_30 ( V_18 ) ) ;
return V_32 ;
}
return 0 ;
}
static T_2 F_40 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( F_41 ( V_39 , & V_41 ) ) {
F_42 ( F_41 ( V_40 , & V_41 ) ) ;
return sprintf ( V_37 , L_5 ) ;
} else if ( F_41 ( V_40 , & V_41 ) )
return sprintf ( V_37 , L_6 ) ;
else
return sprintf ( V_37 , L_7 ) ;
}
static T_2 F_43 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( ! memcmp ( L_8 , V_37 ,
F_3 ( sizeof( L_8 ) - 1 , V_42 ) ) ) {
F_44 ( V_39 , & V_41 ) ;
F_45 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_9 , V_37 ,
F_3 ( sizeof( L_9 ) - 1 , V_42 ) ) ) {
F_45 ( V_39 , & V_41 ) ;
F_44 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_10 , V_37 ,
F_3 ( sizeof( L_10 ) - 1 , V_42 ) ) ) {
F_45 ( V_39 , & V_41 ) ;
F_45 ( V_40 , & V_41 ) ;
} else
return - V_43 ;
return V_42 ;
}
static T_2 F_46 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_40 ( V_34 , V_36 , V_37 ,
V_44 ,
V_45 ) ;
}
static T_2 F_47 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
T_2 V_46 ;
V_46 = F_43 ( V_34 , V_36 , V_37 , V_42 ,
V_44 ,
V_45 ) ;
if ( V_46 > 0 ) {
int V_9 ;
F_48 ( & V_47 ) ;
V_9 = F_7 () ;
F_49 ( & V_47 ) ;
if ( V_9 )
V_46 = V_9 ;
}
return V_46 ;
}
static T_2 F_50 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_48 )
{
return sprintf ( V_37 , L_11 ,
! ! F_41 ( V_48 , & V_41 ) ) ;
}
static T_2 F_51 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_48 )
{
unsigned long V_49 ;
int V_46 ;
V_46 = F_52 ( V_37 , 10 , & V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_49 > 1 )
return - V_43 ;
if ( V_49 )
F_44 ( V_48 , & V_41 ) ;
else
F_45 ( V_48 , & V_41 ) ;
return V_42 ;
}
static T_2 F_53 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_40 ( V_34 , V_36 , V_37 ,
V_50 ,
V_51 ) ;
}
static T_2 F_54 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_43 ( V_34 , V_36 , V_37 , V_42 ,
V_50 ,
V_51 ) ;
}
static T_2 F_55 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_50 ( V_34 , V_36 , V_37 ,
V_52 ) ;
}
static T_2 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_42 )
{
return F_51 ( V_34 , V_36 , V_37 , V_42 ,
V_52 ) ;
}
static T_2 F_57 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_50 ( V_34 , V_36 , V_37 ,
V_53 ) ;
}
static T_2 F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_51 ( V_34 , V_36 , V_37 , V_42 ,
V_53 ) ;
}
static T_2 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_54 ) ;
}
static T_2 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_9 ;
V_9 = F_52 ( V_37 , 10 , & V_55 ) ;
if ( V_9 || V_55 > V_56 )
return - V_43 ;
V_54 = V_55 ;
F_15 ( & V_15 ) ;
return V_42 ;
}
static T_2 F_61 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_57 ) ;
}
static T_2 F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_9 ;
V_9 = F_52 ( V_37 , 10 , & V_55 ) ;
if ( V_9 || V_55 > V_56 )
return - V_43 ;
V_57 = V_55 ;
F_15 ( & V_15 ) ;
return V_42 ;
}
static T_2 F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_58 ) ;
}
static T_2 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_9 ;
unsigned long V_59 ;
V_9 = F_52 ( V_37 , 10 , & V_59 ) ;
if ( V_9 || ! V_59 || V_59 > V_56 )
return - V_43 ;
V_58 = V_59 ;
return V_42 ;
}
static T_2 F_65 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_60 ) ;
}
static T_2 F_66 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_61 ) ;
}
static T_2 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_50 ( V_34 , V_36 , V_37 ,
V_62 ) ;
}
static T_2 F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_51 ( V_34 , V_36 , V_37 , V_42 ,
V_62 ) ;
}
static T_2 F_69 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_12 , V_63 ) ;
}
static T_2 F_70 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_9 ;
unsigned long V_64 ;
V_9 = F_52 ( V_37 , 10 , & V_64 ) ;
if ( V_9 || V_64 > V_32 - 1 )
return - V_43 ;
V_63 = V_64 ;
return V_42 ;
}
static int T_4 F_71 ( struct V_33 * * V_65 )
{
int V_9 ;
* V_65 = F_72 ( L_13 , V_66 ) ;
if ( F_10 ( ! * V_65 ) ) {
F_12 ( L_14 ) ;
return - V_67 ;
}
V_9 = F_73 ( * V_65 , & V_68 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_69;
}
V_9 = F_73 ( * V_65 , & V_70 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_71;
}
return 0 ;
V_71:
F_74 ( * V_65 , & V_68 ) ;
V_69:
F_75 ( * V_65 ) ;
return V_9 ;
}
static void T_4 F_76 ( struct V_33 * V_65 )
{
F_74 ( V_65 , & V_70 ) ;
F_74 ( V_65 , & V_68 ) ;
F_75 ( V_65 ) ;
}
static inline int F_71 ( struct V_33 * * V_65 )
{
return 0 ;
}
static inline void F_76 ( struct V_33 * V_65 )
{
}
static int T_4 F_77 ( void )
{
int V_9 ;
struct V_33 * V_65 ;
if ( ! F_78 () ) {
V_41 = 0 ;
return - V_43 ;
}
V_9 = F_71 ( & V_65 ) ;
if ( V_9 )
goto V_72;
V_9 = F_79 () ;
if ( V_9 )
goto V_73;
V_9 = F_80 ( & V_74 ) ;
if ( V_9 )
goto V_75;
if ( V_76 < ( 512 << ( 20 - V_6 ) ) ) {
V_41 = 0 ;
return 0 ;
}
V_9 = F_7 () ;
if ( V_9 )
goto V_77;
return 0 ;
V_77:
F_81 ( & V_74 ) ;
V_75:
F_82 () ;
V_73:
F_76 ( V_65 ) ;
V_72:
return V_9 ;
}
static int T_4 F_83 ( char * V_78 )
{
int V_46 = 0 ;
if ( ! V_78 )
goto V_79;
if ( ! strcmp ( V_78 , L_8 ) ) {
F_44 ( V_44 ,
& V_41 ) ;
F_45 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_78 , L_9 ) ) {
F_45 ( V_44 ,
& V_41 ) ;
F_44 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_78 , L_10 ) ) {
F_45 ( V_44 ,
& V_41 ) ;
F_45 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
}
V_79:
if ( ! V_46 )
F_84 ( L_16 ) ;
return V_46 ;
}
T_1 F_85 ( T_1 V_16 , struct V_80 * V_81 )
{
if ( F_21 ( V_81 -> V_82 & V_83 ) )
V_16 = F_86 ( V_16 ) ;
return V_16 ;
}
static inline T_1 F_87 ( struct V_17 * V_17 , T_5 V_84 )
{
T_1 V_85 ;
V_85 = F_88 ( V_17 , V_84 ) ;
V_85 = F_89 ( V_85 ) ;
return V_85 ;
}
static int F_90 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_88 , T_1 * V_16 ,
struct V_17 * V_17 , T_6 V_89 )
{
struct V_90 * V_91 ;
T_7 V_92 ;
T_8 * V_93 ;
F_91 ( ! F_92 ( V_17 ) , V_17 ) ;
if ( F_93 ( V_17 , V_87 , V_89 , & V_91 ) )
return V_94 ;
V_92 = F_94 ( V_87 , V_88 ) ;
if ( F_10 ( ! V_92 ) ) {
F_95 ( V_17 , V_91 ) ;
return V_94 ;
}
F_96 ( V_17 , V_88 , V_32 ) ;
F_97 ( V_17 ) ;
V_93 = F_98 ( V_87 , V_16 ) ;
if ( F_10 ( ! F_99 ( * V_16 ) ) ) {
F_100 ( V_93 ) ;
F_95 ( V_17 , V_91 ) ;
F_101 ( V_17 ) ;
F_102 ( V_87 , V_92 ) ;
} else {
T_1 V_85 ;
V_85 = F_87 ( V_17 , V_81 -> V_95 ) ;
V_85 = F_85 ( F_103 ( V_85 ) , V_81 ) ;
F_104 ( V_17 , V_81 , V_88 ) ;
F_105 ( V_17 , V_91 , false ) ;
F_106 ( V_17 , V_81 ) ;
F_107 ( V_87 , V_16 , V_92 ) ;
F_108 ( V_87 , V_88 , V_16 , V_85 ) ;
F_109 ( V_87 , V_96 , V_32 ) ;
F_110 ( & V_87 -> V_97 ) ;
F_100 ( V_93 ) ;
}
return 0 ;
}
static inline T_6 F_111 ( int V_98 , T_6 V_99 )
{
return ( V_22 & ~ ( V_98 ? 0 : V_100 ) ) | V_99 ;
}
static bool F_112 ( T_7 V_92 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_88 , T_1 * V_16 ,
struct V_17 * V_18 )
{
T_1 V_85 ;
if ( ! F_99 ( * V_16 ) )
return false ;
V_85 = F_88 ( V_18 , V_81 -> V_95 ) ;
V_85 = F_89 ( V_85 ) ;
F_107 ( V_87 , V_16 , V_92 ) ;
F_108 ( V_87 , V_88 , V_16 , V_85 ) ;
F_110 ( & V_87 -> V_97 ) ;
return true ;
}
int F_113 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_101 , T_1 * V_16 ,
unsigned int V_102 )
{
T_6 V_89 ;
struct V_17 * V_17 ;
unsigned long V_88 = V_101 & V_103 ;
if ( V_88 < V_81 -> V_104 || V_88 + V_105 > V_81 -> V_106 )
return V_107 ;
if ( F_10 ( F_114 ( V_81 ) ) )
return V_94 ;
if ( F_10 ( F_115 ( V_81 , V_81 -> V_82 ) ) )
return V_94 ;
if ( ! ( V_102 & V_108 ) && ! F_116 ( V_87 ) &&
F_117 () ) {
T_8 * V_93 ;
T_7 V_92 ;
struct V_17 * V_18 ;
bool V_109 ;
V_92 = F_94 ( V_87 , V_88 ) ;
if ( F_10 ( ! V_92 ) )
return V_94 ;
V_18 = F_20 () ;
if ( F_10 ( ! V_18 ) ) {
F_102 ( V_87 , V_92 ) ;
F_25 ( V_110 ) ;
return V_107 ;
}
V_93 = F_98 ( V_87 , V_16 ) ;
V_109 = F_112 ( V_92 , V_87 , V_81 , V_88 , V_16 ,
V_18 ) ;
F_100 ( V_93 ) ;
if ( ! V_109 ) {
F_102 ( V_87 , V_92 ) ;
F_32 () ;
}
return 0 ;
}
V_89 = F_111 ( F_118 ( V_81 ) , 0 ) ;
V_17 = F_119 ( V_89 , V_81 , V_88 , V_25 ) ;
if ( F_10 ( ! V_17 ) ) {
F_25 ( V_110 ) ;
return V_107 ;
}
if ( F_10 ( F_90 ( V_87 , V_81 , V_88 , V_16 , V_17 , V_89 ) ) ) {
F_101 ( V_17 ) ;
F_25 ( V_110 ) ;
return V_107 ;
}
F_25 ( V_111 ) ;
return 0 ;
}
int F_120 ( struct V_86 * V_112 , struct V_86 * V_113 ,
T_1 * V_114 , T_1 * V_115 , unsigned long V_116 ,
struct V_80 * V_81 )
{
T_8 * V_117 , * V_118 ;
struct V_17 * V_119 ;
T_1 V_16 ;
T_7 V_92 ;
int V_46 ;
V_46 = - V_67 ;
V_92 = F_94 ( V_112 , V_116 ) ;
if ( F_10 ( ! V_92 ) )
goto V_79;
V_117 = F_98 ( V_112 , V_114 ) ;
V_118 = F_121 ( V_113 , V_115 ) ;
F_122 ( V_118 , V_120 ) ;
V_46 = - V_121 ;
V_16 = * V_115 ;
if ( F_10 ( ! F_123 ( V_16 ) ) ) {
F_102 ( V_112 , V_92 ) ;
goto V_122;
}
if ( F_17 ( V_16 ) ) {
struct V_17 * V_18 ;
bool V_109 ;
V_18 = F_20 () ;
V_109 = F_112 ( V_92 , V_112 , V_81 , V_116 , V_114 ,
V_18 ) ;
F_33 ( ! V_109 ) ;
V_46 = 0 ;
goto V_122;
}
if ( F_10 ( F_124 ( V_16 ) ) ) {
F_100 ( V_118 ) ;
F_100 ( V_117 ) ;
F_102 ( V_112 , V_92 ) ;
F_125 ( V_81 -> V_123 , V_115 ) ;
goto V_79;
}
V_119 = F_19 ( V_16 ) ;
F_91 ( ! F_126 ( V_119 ) , V_119 ) ;
F_127 ( V_119 ) ;
F_128 ( V_119 ) ;
F_109 ( V_112 , V_96 , V_32 ) ;
F_129 ( V_113 , V_116 , V_115 ) ;
V_16 = F_130 ( F_131 ( V_16 ) ) ;
F_107 ( V_112 , V_114 , V_92 ) ;
F_108 ( V_112 , V_116 , V_114 , V_16 ) ;
F_110 ( & V_112 -> V_97 ) ;
V_46 = 0 ;
V_122:
F_100 ( V_118 ) ;
F_100 ( V_117 ) ;
V_79:
return V_46 ;
}
void F_132 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_101 ,
T_1 * V_16 , T_1 V_124 ,
int V_125 )
{
T_8 * V_93 ;
T_1 V_85 ;
unsigned long V_88 ;
V_93 = F_98 ( V_87 , V_16 ) ;
if ( F_10 ( ! F_133 ( * V_16 , V_124 ) ) )
goto V_126;
V_85 = F_134 ( V_124 ) ;
V_88 = V_101 & V_103 ;
if ( F_135 ( V_81 , V_88 , V_16 , V_85 , V_125 ) )
F_136 ( V_81 , V_101 , V_16 ) ;
V_126:
F_100 ( V_93 ) ;
}
static void F_137 ( struct V_17 * V_17 )
{
if ( F_138 ( V_127 ) ) {
struct V_17 * V_128 = V_17 + V_32 ;
F_139 ( V_32 , & V_17 -> V_129 ) ;
while ( ++ V_17 < V_128 )
F_140 ( V_17 ) ;
} else {
F_127 ( V_17 ) ;
}
}
static void F_141 ( struct V_17 * V_17 )
{
if ( F_138 ( V_127 ) ) {
struct V_17 * V_128 = V_17 + V_32 ;
while ( V_17 < V_128 )
F_101 ( V_17 ++ ) ;
} else {
F_101 ( V_17 ) ;
}
}
static int F_142 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_101 ,
T_1 * V_16 , T_1 V_124 ,
struct V_17 * V_17 ,
unsigned long V_88 )
{
struct V_90 * V_91 ;
T_8 * V_93 ;
T_7 V_92 ;
T_1 V_130 ;
int V_46 = 0 , V_131 ;
struct V_17 * * V_59 ;
unsigned long V_132 ;
unsigned long V_133 ;
V_59 = F_143 ( sizeof( struct V_17 * ) * V_32 ,
V_134 ) ;
if ( F_10 ( ! V_59 ) ) {
V_46 |= V_94 ;
goto V_79;
}
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ ) {
V_59 [ V_131 ] = F_144 ( V_135 |
V_136 ,
V_81 , V_101 , F_145 ( V_17 ) ) ;
if ( F_10 ( ! V_59 [ V_131 ] ||
F_93 ( V_59 [ V_131 ] , V_87 , V_134 ,
& V_91 ) ) ) {
if ( V_59 [ V_131 ] )
F_101 ( V_59 [ V_131 ] ) ;
while ( -- V_131 >= 0 ) {
V_91 = ( void * ) F_146 ( V_59 [ V_131 ] ) ;
F_147 ( V_59 [ V_131 ] , 0 ) ;
F_95 ( V_59 [ V_131 ] , V_91 ) ;
F_101 ( V_59 [ V_131 ] ) ;
}
F_148 ( V_59 ) ;
V_46 |= V_94 ;
goto V_79;
}
F_147 ( V_59 [ V_131 ] , ( unsigned long ) V_91 ) ;
}
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ ) {
F_149 ( V_59 [ V_131 ] , V_17 + V_131 ,
V_88 + V_137 * V_131 , V_81 ) ;
F_97 ( V_59 [ V_131 ] ) ;
F_150 () ;
}
V_132 = V_88 ;
V_133 = V_88 + V_105 ;
F_151 ( V_87 , V_132 , V_133 ) ;
V_93 = F_98 ( V_87 , V_16 ) ;
if ( F_10 ( ! F_133 ( * V_16 , V_124 ) ) )
goto V_138;
F_91 ( ! F_126 ( V_17 ) , V_17 ) ;
F_152 ( V_81 , V_88 , V_16 ) ;
V_92 = F_153 ( V_87 , V_16 ) ;
F_154 ( V_87 , & V_130 , V_92 ) ;
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ , V_88 += V_137 ) {
T_9 * V_139 , V_85 ;
V_85 = F_155 ( V_59 [ V_131 ] , V_81 -> V_95 ) ;
V_85 = F_156 ( F_157 ( V_85 ) , V_81 ) ;
V_91 = ( void * ) F_146 ( V_59 [ V_131 ] ) ;
F_147 ( V_59 [ V_131 ] , 0 ) ;
F_104 ( V_59 [ V_131 ] , V_81 , V_88 ) ;
F_105 ( V_59 [ V_131 ] , V_91 , false ) ;
F_106 ( V_59 [ V_131 ] , V_81 ) ;
V_139 = F_158 ( & V_130 , V_88 ) ;
F_42 ( ! F_159 ( * V_139 ) ) ;
F_160 ( V_87 , V_88 , V_139 , V_85 ) ;
F_161 ( V_139 ) ;
}
F_148 ( V_59 ) ;
F_162 () ;
F_154 ( V_87 , V_16 , V_92 ) ;
F_163 ( V_17 ) ;
F_100 ( V_93 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
V_46 |= V_140 ;
F_101 ( V_17 ) ;
V_79:
return V_46 ;
V_138:
F_100 ( V_93 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ ) {
V_91 = ( void * ) F_146 ( V_59 [ V_131 ] ) ;
F_147 ( V_59 [ V_131 ] , 0 ) ;
F_95 ( V_59 [ V_131 ] , V_91 ) ;
F_101 ( V_59 [ V_131 ] ) ;
}
F_148 ( V_59 ) ;
goto V_79;
}
int F_165 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_101 , T_1 * V_16 , T_1 V_124 )
{
T_8 * V_93 ;
int V_46 = 0 ;
struct V_17 * V_17 = NULL , * V_141 ;
struct V_90 * V_91 ;
unsigned long V_88 ;
unsigned long V_132 ;
unsigned long V_133 ;
T_6 V_142 ;
V_93 = F_121 ( V_87 , V_16 ) ;
F_166 ( ! V_81 -> V_123 , V_81 ) ;
V_88 = V_101 & V_103 ;
if ( F_17 ( V_124 ) )
goto V_143;
F_167 ( V_93 ) ;
if ( F_10 ( ! F_133 ( * V_16 , V_124 ) ) )
goto V_122;
V_17 = F_19 ( V_124 ) ;
F_91 ( ! F_92 ( V_17 ) || ! F_126 ( V_17 ) , V_17 ) ;
if ( F_168 ( V_17 ) == 1 ) {
T_1 V_85 ;
V_85 = F_134 ( V_124 ) ;
V_85 = F_85 ( F_103 ( V_85 ) , V_81 ) ;
if ( F_135 ( V_81 , V_88 , V_16 , V_85 , 1 ) )
F_136 ( V_81 , V_101 , V_16 ) ;
V_46 |= V_140 ;
goto V_122;
}
F_137 ( V_17 ) ;
F_100 ( V_93 ) ;
V_143:
if ( F_169 ( V_81 ) &&
! F_170 () ) {
V_142 = F_111 ( F_118 ( V_81 ) , 0 ) ;
V_141 = F_119 ( V_142 , V_81 , V_88 , V_25 ) ;
} else
V_141 = NULL ;
if ( F_10 ( ! V_141 ) ) {
if ( ! V_17 ) {
F_171 ( V_81 , V_101 , V_16 ) ;
V_46 |= V_107 ;
} else {
V_46 = F_142 ( V_87 , V_81 , V_101 ,
V_16 , V_124 , V_17 , V_88 ) ;
if ( V_46 & V_94 ) {
F_172 ( V_17 ) ;
V_46 |= V_107 ;
}
F_141 ( V_17 ) ;
}
F_25 ( V_110 ) ;
goto V_79;
}
if ( F_10 ( F_93 ( V_141 , V_87 , V_142 , & V_91 ) ) ) {
F_101 ( V_141 ) ;
if ( V_17 ) {
F_172 ( V_17 ) ;
F_141 ( V_17 ) ;
} else
F_171 ( V_81 , V_101 , V_16 ) ;
V_46 |= V_107 ;
F_25 ( V_110 ) ;
goto V_79;
}
F_25 ( V_111 ) ;
if ( ! V_17 )
F_96 ( V_141 , V_88 , V_32 ) ;
else
F_173 ( V_141 , V_17 , V_88 , V_81 , V_32 ) ;
F_97 ( V_141 ) ;
V_132 = V_88 ;
V_133 = V_88 + V_105 ;
F_151 ( V_87 , V_132 , V_133 ) ;
F_167 ( V_93 ) ;
if ( V_17 )
F_141 ( V_17 ) ;
if ( F_10 ( ! F_133 ( * V_16 , V_124 ) ) ) {
F_100 ( V_93 ) ;
F_95 ( V_141 , V_91 ) ;
F_101 ( V_141 ) ;
goto V_144;
} else {
T_1 V_85 ;
V_85 = F_87 ( V_141 , V_81 -> V_95 ) ;
V_85 = F_85 ( F_103 ( V_85 ) , V_81 ) ;
F_152 ( V_81 , V_88 , V_16 ) ;
F_104 ( V_141 , V_81 , V_88 ) ;
F_105 ( V_141 , V_91 , false ) ;
F_106 ( V_141 , V_81 ) ;
F_108 ( V_87 , V_88 , V_16 , V_85 ) ;
F_136 ( V_81 , V_101 , V_16 ) ;
if ( ! V_17 ) {
F_109 ( V_87 , V_96 , V_32 ) ;
F_32 () ;
} else {
F_91 ( ! F_126 ( V_17 ) , V_17 ) ;
F_163 ( V_17 ) ;
F_101 ( V_17 ) ;
}
V_46 |= V_140 ;
}
F_100 ( V_93 ) ;
V_144:
F_164 ( V_87 , V_132 , V_133 ) ;
V_79:
return V_46 ;
V_122:
F_100 ( V_93 ) ;
return V_46 ;
}
struct V_17 * F_174 ( struct V_80 * V_81 ,
unsigned long V_116 ,
T_1 * V_16 ,
unsigned int V_102 )
{
struct V_86 * V_87 = V_81 -> V_145 ;
struct V_17 * V_17 = NULL ;
F_175 ( F_121 ( V_87 , V_16 ) ) ;
if ( V_102 & V_146 && ! F_176 ( * V_16 ) )
goto V_79;
if ( ( V_102 & V_147 ) && F_17 ( * V_16 ) )
return F_177 ( - V_148 ) ;
if ( ( V_102 & V_149 ) && F_178 ( * V_16 ) )
goto V_79;
V_17 = F_19 ( * V_16 ) ;
F_91 ( ! F_126 ( V_17 ) , V_17 ) ;
if ( V_102 & V_150 ) {
T_1 V_130 ;
V_130 = F_134 ( F_103 ( * V_16 ) ) ;
if ( F_135 ( V_81 , V_116 & V_103 ,
V_16 , V_130 , 1 ) )
F_136 ( V_81 , V_116 , V_16 ) ;
}
if ( ( V_102 & V_151 ) && ( V_81 -> V_82 & V_152 ) ) {
if ( V_17 -> V_153 && F_179 ( V_17 ) ) {
F_180 () ;
if ( V_17 -> V_153 )
F_181 ( V_17 ) ;
F_182 ( V_17 ) ;
}
}
V_17 += ( V_116 & ~ V_103 ) >> V_6 ;
F_91 ( ! F_92 ( V_17 ) , V_17 ) ;
if ( V_102 & V_154 )
F_183 ( V_17 ) ;
V_79:
return V_17 ;
}
int F_184 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_116 , T_1 V_16 , T_1 * V_155 )
{
T_8 * V_93 ;
struct V_123 * V_123 = NULL ;
struct V_17 * V_17 ;
unsigned long V_88 = V_116 & V_103 ;
int V_156 = - 1 , V_157 = F_185 () ;
int V_158 , V_159 = - 1 ;
bool V_160 ;
bool V_161 = false ;
bool V_162 ;
int V_102 = 0 ;
F_33 ( ! ( V_81 -> V_82 & ( V_163 | V_164 | V_83 ) ) ) ;
V_93 = F_98 ( V_87 , V_155 ) ;
if ( F_10 ( ! F_133 ( V_16 , * V_155 ) ) )
goto V_122;
if ( F_10 ( F_186 ( * V_155 ) ) ) {
V_17 = F_19 ( * V_155 ) ;
F_100 ( V_93 ) ;
F_187 ( V_17 ) ;
goto V_79;
}
V_17 = F_19 ( V_16 ) ;
F_33 ( F_18 ( V_17 ) ) ;
V_156 = F_145 ( V_17 ) ;
V_159 = F_188 ( V_17 ) ;
F_189 ( V_165 ) ;
if ( V_156 == V_157 ) {
F_189 ( V_166 ) ;
V_102 |= V_167 ;
}
if ( ! ( V_81 -> V_82 & V_83 ) )
V_102 |= V_168 ;
V_160 = F_179 ( V_17 ) ;
V_158 = F_190 ( V_17 , V_81 , V_88 ) ;
if ( V_158 == - 1 ) {
if ( V_160 )
goto V_169;
}
if ( ! V_160 ) {
F_100 ( V_93 ) ;
F_187 ( V_17 ) ;
V_156 = - 1 ;
goto V_79;
}
F_127 ( V_17 ) ;
F_100 ( V_93 ) ;
V_123 = F_191 ( V_17 ) ;
F_167 ( V_93 ) ;
if ( F_10 ( ! F_133 ( V_16 , * V_155 ) ) ) {
F_182 ( V_17 ) ;
F_101 ( V_17 ) ;
V_156 = - 1 ;
goto V_122;
}
if ( F_10 ( ! V_123 ) ) {
F_101 ( V_17 ) ;
V_156 = - 1 ;
goto V_169;
}
F_100 ( V_93 ) ;
V_161 = F_192 ( V_87 , V_81 ,
V_155 , V_16 , V_116 , V_17 , V_158 ) ;
if ( V_161 ) {
V_102 |= V_170 ;
V_156 = V_158 ;
} else
V_102 |= V_171 ;
goto V_79;
V_169:
F_33 ( ! F_193 ( V_17 ) ) ;
V_162 = F_176 ( V_16 ) ;
V_16 = F_194 ( V_16 , V_81 -> V_95 ) ;
V_16 = F_134 ( V_16 ) ;
if ( V_162 )
V_16 = F_86 ( V_16 ) ;
F_108 ( V_87 , V_88 , V_155 , V_16 ) ;
F_136 ( V_81 , V_116 , V_155 ) ;
F_182 ( V_17 ) ;
V_122:
F_100 ( V_93 ) ;
V_79:
if ( V_123 )
F_195 ( V_123 ) ;
if ( V_156 != - 1 )
F_196 ( V_159 , V_156 , V_32 , V_102 ) ;
return 0 ;
}
int F_197 ( struct V_172 * V_173 , struct V_80 * V_81 ,
T_1 * V_16 , unsigned long V_116 )
{
T_8 * V_93 ;
int V_46 = 0 ;
if ( F_198 ( V_16 , V_81 , & V_93 ) == 1 ) {
struct V_17 * V_17 ;
T_7 V_92 ;
T_1 V_124 ;
V_124 = F_199 ( V_173 -> V_87 , V_116 , V_16 ,
V_173 -> V_174 ) ;
F_200 ( V_173 , V_16 , V_116 ) ;
V_92 = F_153 ( V_173 -> V_87 , V_16 ) ;
if ( F_17 ( V_124 ) ) {
F_201 ( & V_173 -> V_87 -> V_97 ) ;
F_100 ( V_93 ) ;
F_32 () ;
} else {
V_17 = F_19 ( V_124 ) ;
F_163 ( V_17 ) ;
F_91 ( F_168 ( V_17 ) < 0 , V_17 ) ;
F_109 ( V_173 -> V_87 , V_96 , - V_32 ) ;
F_91 ( ! F_126 ( V_17 ) , V_17 ) ;
F_201 ( & V_173 -> V_87 -> V_97 ) ;
F_100 ( V_93 ) ;
F_202 ( V_173 , V_17 ) ;
}
F_102 ( V_173 -> V_87 , V_92 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_203 ( struct V_80 * V_81 , struct V_80 * V_175 ,
unsigned long V_176 ,
unsigned long V_177 , unsigned long V_178 ,
T_1 * V_179 , T_1 * V_180 )
{
T_8 * V_181 , * V_182 ;
int V_46 = 0 ;
T_1 V_16 ;
struct V_86 * V_87 = V_81 -> V_145 ;
if ( ( V_176 & ~ V_103 ) ||
( V_177 & ~ V_103 ) ||
V_178 - V_176 < V_105 ||
( V_175 -> V_82 & V_183 ) )
goto V_79;
if ( F_204 ( ! F_99 ( * V_180 ) ) ) {
F_42 ( F_123 ( * V_180 ) ) ;
goto V_79;
}
V_46 = F_198 ( V_179 , V_81 , & V_181 ) ;
if ( V_46 == 1 ) {
V_182 = F_121 ( V_87 , V_180 ) ;
if ( V_182 != V_181 )
F_122 ( V_182 , V_120 ) ;
V_16 = F_205 ( V_87 , V_176 , V_179 ) ;
F_42 ( ! F_99 ( * V_180 ) ) ;
if ( F_206 ( V_182 , V_181 ) ) {
T_7 V_92 ;
V_92 = F_153 ( V_87 , V_179 ) ;
F_107 ( V_87 , V_180 , V_92 ) ;
}
F_108 ( V_87 , V_177 , V_180 , F_207 ( V_16 ) ) ;
if ( V_182 != V_181 )
F_100 ( V_182 ) ;
F_100 ( V_181 ) ;
}
V_79:
return V_46 ;
}
int F_208 ( struct V_80 * V_81 , T_1 * V_16 ,
unsigned long V_116 , T_5 V_184 , int V_185 )
{
struct V_86 * V_87 = V_81 -> V_145 ;
T_8 * V_93 ;
int V_46 = 0 ;
if ( F_198 ( V_16 , V_81 , & V_93 ) == 1 ) {
T_1 V_85 ;
bool V_186 = V_185 && F_176 ( * V_16 ) ;
V_46 = 1 ;
if ( V_185 && F_17 ( * V_16 ) ) {
F_100 ( V_93 ) ;
return V_46 ;
}
if ( ! V_185 || ! F_178 ( * V_16 ) ) {
V_85 = F_209 ( V_87 , V_116 , V_16 ) ;
V_85 = F_194 ( V_85 , V_184 ) ;
if ( V_186 )
V_85 = F_86 ( V_85 ) ;
V_46 = V_32 ;
F_108 ( V_87 , V_116 , V_16 , V_85 ) ;
F_33 ( ! V_186 && F_176 ( V_85 ) ) ;
}
F_100 ( V_93 ) ;
}
return V_46 ;
}
int F_198 ( T_1 * V_16 , struct V_80 * V_81 ,
T_8 * * V_93 )
{
* V_93 = F_98 ( V_81 -> V_145 , V_16 ) ;
if ( F_21 ( F_123 ( * V_16 ) ) ) {
if ( F_10 ( F_124 ( * V_16 ) ) ) {
F_100 ( * V_93 ) ;
F_125 ( V_81 -> V_123 , V_16 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_100 ( * V_93 ) ;
return 0 ;
}
T_1 * F_210 ( struct V_17 * V_17 ,
struct V_86 * V_87 ,
unsigned long V_101 ,
enum V_187 V_48 ,
T_8 * * V_93 )
{
T_10 * V_188 ;
T_11 * V_189 ;
T_1 * V_16 ;
if ( V_101 & ~ V_103 )
return NULL ;
V_188 = F_211 ( V_87 , V_101 ) ;
if ( ! F_212 ( * V_188 ) )
return NULL ;
V_189 = F_213 ( V_188 , V_101 ) ;
if ( ! F_214 ( * V_189 ) )
return NULL ;
V_16 = F_215 ( V_189 , V_101 ) ;
* V_93 = F_98 ( V_87 , V_16 ) ;
if ( ! F_216 ( * V_16 ) )
goto V_126;
if ( F_19 ( * V_16 ) != V_17 )
goto V_126;
if ( V_48 == V_190 &&
F_124 ( * V_16 ) )
goto V_126;
if ( F_123 ( * V_16 ) ) {
F_42 ( V_48 == V_191 &&
! F_124 ( * V_16 ) ) ;
return V_16 ;
}
V_126:
F_100 ( * V_93 ) ;
return NULL ;
}
static int F_217 ( struct V_17 * V_17 ,
struct V_80 * V_81 ,
unsigned long V_101 )
{
struct V_86 * V_87 = V_81 -> V_145 ;
T_8 * V_93 ;
T_1 * V_16 ;
int V_46 = 0 ;
const unsigned long V_132 = V_101 ;
const unsigned long V_133 = V_101 + V_105 ;
F_151 ( V_87 , V_132 , V_133 ) ;
V_16 = F_210 ( V_17 , V_87 , V_101 ,
V_190 , & V_93 ) ;
if ( V_16 ) {
F_218 ( V_81 , V_101 , V_16 ) ;
V_46 = 1 ;
F_100 ( V_93 ) ;
}
F_164 ( V_87 , V_132 , V_133 ) ;
return V_46 ;
}
static void F_219 ( struct V_17 * V_17 ,
struct V_192 * V_193 )
{
int V_131 ;
struct V_1 * V_1 = F_220 ( V_17 ) ;
struct V_194 * V_194 ;
int V_195 = 0 ;
F_221 ( & V_1 -> V_196 ) ;
V_194 = F_222 ( V_17 , V_1 ) ;
F_223 ( V_17 ) ;
F_224 ( V_17 ) ;
for ( V_131 = V_32 - 1 ; V_131 >= 1 ; V_131 -- ) {
struct V_17 * V_197 = V_17 + V_131 ;
F_33 ( F_168 ( V_197 ) < 0 ) ;
V_195 += F_168 ( V_197 ) ;
F_33 ( V_195 < 0 ) ;
F_33 ( F_36 ( & V_197 -> V_129 ) != 0 ) ;
F_139 ( F_168 ( V_17 ) + F_168 ( V_197 ) + 1 ,
& V_197 -> V_129 ) ;
F_225 () ;
V_197 -> V_102 &= ~ V_198 ;
V_197 -> V_102 |= ( V_17 -> V_102 &
( ( 1L << V_199 ) |
( 1L << V_200 ) |
( 1L << V_201 ) |
( 1L << V_202 ) |
( 1L << V_203 ) |
( 1L << V_204 ) ) ) ;
V_197 -> V_102 |= ( 1L << V_205 ) ;
F_162 () ;
V_197 -> V_206 = V_17 -> V_206 ;
F_33 ( V_197 -> V_153 ) ;
V_197 -> V_153 = V_17 -> V_153 ;
V_197 -> V_207 = V_17 -> V_207 + V_131 ;
F_226 ( V_197 , F_188 ( V_17 ) ) ;
F_33 ( ! F_227 ( V_197 ) ) ;
F_33 ( ! F_228 ( V_197 ) ) ;
F_33 ( ! F_229 ( V_197 ) ) ;
F_33 ( ! F_230 ( V_197 ) ) ;
F_231 ( V_17 , V_197 , V_194 , V_193 ) ;
}
F_232 ( V_195 , & V_17 -> V_129 ) ;
F_33 ( F_36 ( & V_17 -> V_129 ) <= 0 ) ;
F_233 ( V_1 , V_208 , - 1 ) ;
F_234 ( V_17 ) ;
F_235 ( V_17 ) ;
F_236 ( & V_1 -> V_196 ) ;
for ( V_131 = 1 ; V_131 < V_32 ; V_131 ++ ) {
struct V_17 * V_197 = V_17 + V_131 ;
F_33 ( F_237 ( V_197 ) <= 0 ) ;
F_101 ( V_197 ) ;
}
F_33 ( F_237 ( V_17 ) <= 0 ) ;
}
static int F_238 ( struct V_17 * V_17 ,
struct V_80 * V_81 ,
unsigned long V_101 )
{
struct V_86 * V_87 = V_81 -> V_145 ;
T_8 * V_93 ;
T_1 * V_16 , V_130 ;
int V_46 = 0 , V_131 ;
T_7 V_92 ;
unsigned long V_88 ;
V_16 = F_210 ( V_17 , V_87 , V_101 ,
V_191 , & V_93 ) ;
if ( V_16 ) {
V_92 = F_153 ( V_87 , V_16 ) ;
F_154 ( V_87 , & V_130 , V_92 ) ;
if ( F_176 ( * V_16 ) )
F_33 ( F_168 ( V_17 ) != 1 ) ;
V_88 = V_101 ;
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ , V_88 += V_137 ) {
T_9 * V_139 , V_85 ;
F_33 ( F_92 ( V_17 + V_131 ) ) ;
V_85 = F_155 ( V_17 + V_131 , V_81 -> V_95 ) ;
V_85 = F_156 ( F_157 ( V_85 ) , V_81 ) ;
if ( ! F_176 ( * V_16 ) )
V_85 = F_239 ( V_85 ) ;
if ( ! F_240 ( * V_16 ) )
V_85 = F_241 ( V_85 ) ;
V_139 = F_158 ( & V_130 , V_88 ) ;
F_33 ( ! F_159 ( * V_139 ) ) ;
F_160 ( V_87 , V_88 , V_139 , V_85 ) ;
F_161 ( V_139 ) ;
}
F_162 () ;
F_242 ( V_81 , V_101 , V_16 ) ;
F_154 ( V_87 , V_16 , V_92 ) ;
V_46 = 1 ;
F_100 ( V_93 ) ;
}
return V_46 ;
}
static void F_243 ( struct V_17 * V_17 ,
struct V_123 * V_123 ,
struct V_192 * V_193 )
{
int V_209 , V_210 ;
T_12 V_211 = V_17 -> V_207 << ( V_212 - V_6 ) ;
struct V_213 * V_214 ;
F_33 ( ! F_126 ( V_17 ) ) ;
F_33 ( F_244 ( V_17 ) ) ;
V_209 = 0 ;
F_245 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_80 * V_81 = V_214 -> V_81 ;
unsigned long V_116 = F_246 ( V_17 , V_81 ) ;
F_33 ( F_247 ( V_81 ) ) ;
V_209 += F_217 ( V_17 , V_81 , V_116 ) ;
}
if ( V_209 != F_168 ( V_17 ) ) {
F_12 ( L_17 ,
V_209 , F_168 ( V_17 ) ) ;
F_248 () ;
}
F_219 ( V_17 , V_193 ) ;
V_210 = 0 ;
F_245 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_80 * V_81 = V_214 -> V_81 ;
unsigned long V_116 = F_246 ( V_17 , V_81 ) ;
F_33 ( F_247 ( V_81 ) ) ;
V_210 += F_238 ( V_17 , V_81 , V_116 ) ;
}
if ( V_209 != V_210 ) {
F_12 ( L_18 ,
V_209 , V_210 , F_168 ( V_17 ) ) ;
F_248 () ;
}
}
int F_249 ( struct V_17 * V_17 , struct V_192 * V_193 )
{
struct V_123 * V_123 ;
int V_46 = 1 ;
F_33 ( F_18 ( V_17 ) ) ;
F_33 ( ! F_227 ( V_17 ) ) ;
V_123 = F_250 ( V_17 ) ;
if ( ! V_123 )
goto V_79;
F_251 ( V_123 ) ;
V_46 = 0 ;
if ( ! F_92 ( V_17 ) )
goto V_122;
F_33 ( ! F_230 ( V_17 ) ) ;
F_243 ( V_17 , V_123 , V_193 ) ;
F_25 ( V_215 ) ;
F_33 ( F_92 ( V_17 ) ) ;
V_122:
F_252 ( V_123 ) ;
F_253 ( V_123 ) ;
V_79:
return V_46 ;
}
int F_254 ( struct V_80 * V_81 ,
unsigned long * V_82 , int V_216 )
{
switch ( V_216 ) {
case V_217 :
#ifdef F_255
if ( F_256 ( V_81 -> V_145 ) )
return 0 ;
#endif
if ( * V_82 & ( V_218 | V_219 ) )
return - V_43 ;
* V_82 &= ~ V_183 ;
* V_82 |= V_218 ;
if ( F_10 ( F_257 ( V_81 , * V_82 ) ) )
return - V_67 ;
break;
case V_220 :
if ( * V_82 & ( V_183 | V_219 ) )
return - V_43 ;
* V_82 &= ~ V_218 ;
* V_82 |= V_183 ;
break;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
V_221 = F_258 ( L_19 ,
sizeof( struct V_222 ) ,
F_259 ( struct V_222 ) , 0 , NULL ) ;
if ( ! V_221 )
return - V_67 ;
return 0 ;
}
static void T_4 F_82 ( void )
{
F_260 ( V_221 ) ;
}
static inline struct V_222 * F_261 ( void )
{
if ( ! V_221 )
return NULL ;
return F_262 ( V_221 , V_134 ) ;
}
static inline void F_263 ( struct V_222 * V_222 )
{
F_264 ( V_221 , V_222 ) ;
}
static struct V_222 * F_265 ( struct V_86 * V_87 )
{
struct V_222 * V_222 ;
F_266 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_87 == V_222 -> V_87 )
return V_222 ;
return NULL ;
}
static void F_267 ( struct V_86 * V_87 ,
struct V_222 * V_222 )
{
V_222 -> V_87 = V_87 ;
F_268 ( V_223 , & V_222 -> V_224 , ( long ) V_87 ) ;
}
static inline int F_269 ( struct V_86 * V_87 )
{
return F_36 ( & V_87 -> V_225 ) == 0 ;
}
int F_270 ( struct V_86 * V_87 )
{
struct V_222 * V_222 ;
int V_226 ;
V_222 = F_261 () ;
if ( ! V_222 )
return - V_67 ;
F_271 ( F_269 ( V_87 ) , V_87 ) ;
if ( F_10 ( F_272 ( V_227 , & V_87 -> V_102 ) ) ) {
F_263 ( V_222 ) ;
return 0 ;
}
F_167 ( & V_228 ) ;
F_267 ( V_87 , V_222 ) ;
V_226 = F_14 ( & V_13 . V_14 ) ;
F_273 ( & V_222 -> V_229 , & V_13 . V_14 ) ;
F_100 ( & V_228 ) ;
F_274 ( & V_87 -> V_230 ) ;
if ( V_226 )
F_15 ( & V_15 ) ;
return 0 ;
}
int F_257 ( struct V_80 * V_81 ,
unsigned long V_82 )
{
unsigned long V_231 , V_232 ;
if ( ! V_81 -> V_123 )
return 0 ;
if ( V_81 -> V_233 )
return 0 ;
F_166 ( V_82 & V_219 , V_81 ) ;
V_231 = ( V_81 -> V_104 + ~ V_103 ) & V_103 ;
V_232 = V_81 -> V_106 & V_103 ;
if ( V_231 < V_232 )
return F_115 ( V_81 , V_82 ) ;
return 0 ;
}
void F_275 ( struct V_86 * V_87 )
{
struct V_222 * V_222 ;
int free = 0 ;
F_167 ( & V_228 ) ;
V_222 = F_265 ( V_87 ) ;
if ( V_222 && V_13 . V_222 != V_222 ) {
F_276 ( & V_222 -> V_224 ) ;
F_277 ( & V_222 -> V_229 ) ;
free = 1 ;
}
F_100 ( & V_228 ) ;
if ( free ) {
F_45 ( V_227 , & V_87 -> V_102 ) ;
F_263 ( V_222 ) ;
F_278 ( V_87 ) ;
} else if ( V_222 ) {
F_279 ( & V_87 -> V_234 ) ;
F_280 ( & V_87 -> V_234 ) ;
}
}
static void F_281 ( struct V_17 * V_17 )
{
F_282 ( V_17 , V_235 + 0 ) ;
F_182 ( V_17 ) ;
F_283 ( V_17 ) ;
}
static void F_284 ( T_9 * V_139 , T_9 * V_236 )
{
while ( -- V_236 >= V_139 ) {
T_9 V_237 = * V_236 ;
if ( ! F_159 ( V_237 ) && ! F_285 ( F_286 ( V_237 ) ) )
F_281 ( F_287 ( V_237 ) ) ;
}
}
static int F_288 ( struct V_80 * V_81 ,
unsigned long V_101 ,
T_9 * V_139 )
{
struct V_17 * V_17 ;
T_9 * V_236 ;
int V_238 = 0 ;
bool V_239 = false , V_240 = false ;
for ( V_236 = V_139 ; V_236 < V_139 + V_32 ;
V_236 ++ , V_101 += V_137 ) {
T_9 V_237 = * V_236 ;
if ( F_159 ( V_237 ) || F_285 ( F_286 ( V_237 ) ) ) {
if ( ++ V_238 <= V_63 )
continue;
else
goto V_79;
}
if ( ! F_289 ( V_237 ) )
goto V_79;
V_17 = F_290 ( V_81 , V_101 , V_237 ) ;
if ( F_10 ( ! V_17 ) )
goto V_79;
F_91 ( F_92 ( V_17 ) , V_17 ) ;
F_91 ( ! F_227 ( V_17 ) , V_17 ) ;
F_91 ( ! F_230 ( V_17 ) , V_17 ) ;
if ( ! F_179 ( V_17 ) )
goto V_79;
if ( F_237 ( V_17 ) != 1 + ! ! F_291 ( V_17 ) ) {
F_182 ( V_17 ) ;
goto V_79;
}
if ( F_292 ( V_237 ) ) {
V_240 = true ;
} else {
if ( F_291 ( V_17 ) && ! F_293 ( V_17 ) ) {
F_182 ( V_17 ) ;
goto V_79;
}
}
if ( F_294 ( V_17 ) ) {
F_182 ( V_17 ) ;
goto V_79;
}
F_295 ( V_17 , V_235 + 0 ) ;
F_91 ( ! F_193 ( V_17 ) , V_17 ) ;
F_91 ( F_296 ( V_17 ) , V_17 ) ;
if ( F_297 ( V_237 ) || F_298 ( V_17 ) ||
F_299 ( V_81 -> V_145 , V_101 ) )
V_239 = true ;
}
if ( F_21 ( V_239 && V_240 ) )
return 1 ;
V_79:
F_284 ( V_139 , V_236 ) ;
return 0 ;
}
static void F_300 ( T_9 * V_139 , struct V_17 * V_17 ,
struct V_80 * V_81 ,
unsigned long V_101 ,
T_8 * V_93 )
{
T_9 * V_236 ;
for ( V_236 = V_139 ; V_236 < V_139 + V_32 ; V_236 ++ ) {
T_9 V_237 = * V_236 ;
struct V_17 * V_119 ;
if ( F_159 ( V_237 ) || F_285 ( F_286 ( V_237 ) ) ) {
F_301 ( V_17 , V_101 ) ;
F_109 ( V_81 -> V_145 , V_96 , 1 ) ;
if ( F_285 ( F_286 ( V_237 ) ) ) {
F_167 ( V_93 ) ;
F_302 ( V_81 -> V_145 , V_101 , V_236 ) ;
F_100 ( V_93 ) ;
}
} else {
V_119 = F_287 ( V_237 ) ;
F_149 ( V_17 , V_119 , V_101 , V_81 ) ;
F_91 ( F_168 ( V_119 ) != 1 , V_119 ) ;
F_281 ( V_119 ) ;
F_167 ( V_93 ) ;
F_302 ( V_81 -> V_145 , V_101 , V_236 ) ;
F_163 ( V_119 ) ;
F_100 ( V_93 ) ;
F_303 ( V_119 ) ;
}
V_101 += V_137 ;
V_17 ++ ;
}
}
static void F_304 ( void )
{
F_305 ( V_15 , false ,
F_306 ( V_57 ) ) ;
}
static bool F_307 ( int V_241 )
{
int V_131 ;
if ( ! V_242 )
return false ;
if ( V_243 [ V_241 ] )
return false ;
for ( V_131 = 0 ; V_131 < V_244 ; V_131 ++ ) {
if ( ! V_243 [ V_131 ] )
continue;
if ( F_308 ( V_241 , V_131 ) > V_245 )
return true ;
}
return false ;
}
static int F_309 ( void )
{
static int V_246 = V_247 ;
int V_241 , V_248 = 0 , V_249 = 0 ;
for ( V_241 = 0 ; V_241 < V_244 ; V_241 ++ )
if ( V_243 [ V_241 ] > V_249 ) {
V_249 = V_243 [ V_241 ] ;
V_248 = V_241 ;
}
if ( V_248 <= V_246 )
for ( V_241 = V_246 + 1 ; V_241 < V_244 ;
V_241 ++ )
if ( V_249 == V_243 [ V_241 ] ) {
V_248 = V_241 ;
break;
}
V_246 = V_248 ;
return V_248 ;
}
static bool F_310 ( struct V_17 * * V_250 , bool * V_251 )
{
if ( F_11 ( * V_250 ) ) {
if ( ! * V_251 )
return false ;
* V_251 = false ;
* V_250 = NULL ;
F_304 () ;
} else if ( * V_250 ) {
F_101 ( * V_250 ) ;
* V_250 = NULL ;
}
return true ;
}
static struct V_17 *
F_311 ( struct V_17 * * V_250 , T_6 V_89 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_101 ,
int V_252 )
{
F_91 ( * V_250 , * V_250 ) ;
F_312 ( & V_87 -> V_234 ) ;
* V_250 = F_313 ( V_252 , V_89 , V_25 ) ;
if ( F_10 ( ! * V_250 ) ) {
F_25 ( V_253 ) ;
* V_250 = F_177 ( - V_67 ) ;
return NULL ;
}
F_25 ( V_254 ) ;
return * V_250 ;
}
static int F_309 ( void )
{
return 0 ;
}
static inline struct V_17 * F_314 ( int V_98 )
{
return F_24 ( F_111 ( V_98 , 0 ) ,
V_25 ) ;
}
static struct V_17 * F_315 ( bool * V_251 )
{
struct V_17 * V_250 ;
do {
V_250 = F_314 ( F_316 () ) ;
if ( ! V_250 ) {
F_25 ( V_253 ) ;
if ( ! * V_251 )
return NULL ;
* V_251 = false ;
F_304 () ;
} else
F_25 ( V_254 ) ;
} while ( F_10 ( ! V_250 ) && F_21 ( F_8 () ) );
return V_250 ;
}
static bool F_310 ( struct V_17 * * V_250 , bool * V_251 )
{
if ( ! * V_250 )
* V_250 = F_315 ( V_251 ) ;
if ( F_10 ( ! * V_250 ) )
return false ;
return true ;
}
static struct V_17 *
F_311 ( struct V_17 * * V_250 , T_6 V_89 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_101 ,
int V_252 )
{
F_312 ( & V_87 -> V_234 ) ;
F_42 ( ! * V_250 ) ;
return * V_250 ;
}
static bool F_317 ( struct V_80 * V_81 )
{
if ( ( ! ( V_81 -> V_82 & V_218 ) && ! F_318 () ) ||
( V_81 -> V_82 & V_183 ) )
return false ;
if ( ! V_81 -> V_123 || V_81 -> V_233 )
return false ;
if ( F_247 ( V_81 ) )
return false ;
F_166 ( V_81 -> V_82 & V_219 , V_81 ) ;
return true ;
}
static void F_319 ( struct V_86 * V_87 ,
unsigned long V_101 ,
struct V_17 * * V_250 ,
struct V_80 * V_81 ,
int V_252 )
{
T_1 * V_16 , V_130 ;
T_9 * V_139 ;
T_7 V_92 ;
struct V_17 * V_141 ;
T_8 * V_255 , * V_256 ;
int V_257 ;
unsigned long V_231 , V_232 ;
struct V_90 * V_91 ;
unsigned long V_132 ;
unsigned long V_133 ;
T_6 V_89 ;
F_42 ( V_101 & ~ V_103 ) ;
V_89 = F_111 ( F_316 () , V_136 ) |
V_258 ;
V_141 = F_311 ( V_250 , V_89 , V_87 , V_81 , V_101 , V_252 ) ;
if ( ! V_141 )
return;
if ( F_10 ( F_93 ( V_141 , V_87 ,
V_89 , & V_91 ) ) )
return;
F_279 ( & V_87 -> V_234 ) ;
if ( F_10 ( F_269 ( V_87 ) ) )
goto V_79;
V_81 = F_320 ( V_87 , V_101 ) ;
if ( ! V_81 )
goto V_79;
V_231 = ( V_81 -> V_104 + ~ V_103 ) & V_103 ;
V_232 = V_81 -> V_106 & V_103 ;
if ( V_101 < V_231 || V_101 + V_105 > V_232 )
goto V_79;
if ( ! F_317 ( V_81 ) )
goto V_79;
V_16 = F_321 ( V_87 , V_101 ) ;
if ( ! V_16 )
goto V_79;
F_251 ( V_81 -> V_123 ) ;
V_139 = F_158 ( V_16 , V_101 ) ;
V_256 = F_322 ( V_87 , V_16 ) ;
V_132 = V_101 ;
V_133 = V_101 + V_105 ;
F_151 ( V_87 , V_132 , V_133 ) ;
V_255 = F_98 ( V_87 , V_16 ) ;
V_130 = F_323 ( V_81 , V_101 , V_16 ) ;
F_100 ( V_255 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
F_167 ( V_256 ) ;
V_257 = F_288 ( V_81 , V_101 , V_139 ) ;
F_100 ( V_256 ) ;
if ( F_10 ( ! V_257 ) ) {
F_161 ( V_139 ) ;
F_167 ( V_255 ) ;
F_33 ( ! F_99 ( * V_16 ) ) ;
F_154 ( V_87 , V_16 , F_324 ( V_130 ) ) ;
F_100 ( V_255 ) ;
F_252 ( V_81 -> V_123 ) ;
goto V_79;
}
F_252 ( V_81 -> V_123 ) ;
F_300 ( V_139 , V_141 , V_81 , V_101 , V_256 ) ;
F_161 ( V_139 ) ;
F_97 ( V_141 ) ;
V_92 = F_324 ( V_130 ) ;
V_130 = F_87 ( V_141 , V_81 -> V_95 ) ;
V_130 = F_85 ( F_103 ( V_130 ) , V_81 ) ;
F_162 () ;
F_167 ( V_255 ) ;
F_33 ( ! F_99 ( * V_16 ) ) ;
F_104 ( V_141 , V_81 , V_101 ) ;
F_105 ( V_141 , V_91 , false ) ;
F_106 ( V_141 , V_81 ) ;
F_107 ( V_87 , V_16 , V_92 ) ;
F_108 ( V_87 , V_101 , V_16 , V_130 ) ;
F_136 ( V_81 , V_101 , V_16 ) ;
F_100 ( V_255 ) ;
* V_250 = NULL ;
V_60 ++ ;
V_259:
F_280 ( & V_87 -> V_234 ) ;
return;
V_79:
F_95 ( V_141 , V_91 ) ;
goto V_259;
}
static int F_325 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_101 ,
struct V_17 * * V_250 )
{
T_1 * V_16 ;
T_9 * V_139 , * V_236 ;
int V_46 = 0 , V_238 = 0 ;
struct V_17 * V_17 ;
unsigned long V_260 ;
T_8 * V_93 ;
int V_252 = V_247 ;
bool V_240 = false , V_239 = false ;
F_42 ( V_101 & ~ V_103 ) ;
V_16 = F_321 ( V_87 , V_101 ) ;
if ( ! V_16 )
goto V_79;
memset ( V_243 , 0 , sizeof( V_243 ) ) ;
V_139 = F_326 ( V_87 , V_16 , V_101 , & V_93 ) ;
for ( V_260 = V_101 , V_236 = V_139 ; V_236 < V_139 + V_32 ;
V_236 ++ , V_260 += V_137 ) {
T_9 V_237 = * V_236 ;
if ( F_159 ( V_237 ) || F_285 ( F_286 ( V_237 ) ) ) {
if ( ++ V_238 <= V_63 )
continue;
else
goto V_261;
}
if ( ! F_289 ( V_237 ) )
goto V_261;
if ( F_292 ( V_237 ) )
V_240 = true ;
V_17 = F_290 ( V_81 , V_260 , V_237 ) ;
if ( F_10 ( ! V_17 ) )
goto V_261;
V_252 = F_145 ( V_17 ) ;
if ( F_307 ( V_252 ) )
goto V_261;
V_243 [ V_252 ] ++ ;
F_91 ( F_92 ( V_17 ) , V_17 ) ;
if ( ! F_296 ( V_17 ) || F_193 ( V_17 ) || ! F_227 ( V_17 ) )
goto V_261;
if ( F_237 ( V_17 ) != 1 + ! ! F_291 ( V_17 ) )
goto V_261;
if ( F_297 ( V_237 ) || F_298 ( V_17 ) ||
F_299 ( V_81 -> V_145 , V_101 ) )
V_239 = true ;
}
if ( V_239 && V_240 )
V_46 = 1 ;
V_261:
F_327 ( V_139 , V_93 ) ;
if ( V_46 ) {
V_252 = F_309 () ;
F_319 ( V_87 , V_101 , V_250 , V_81 , V_252 ) ;
}
V_79:
return V_46 ;
}
static void F_328 ( struct V_222 * V_222 )
{
struct V_86 * V_87 = V_222 -> V_87 ;
F_42 ( V_262 != 1 && ! F_329 ( & V_228 ) ) ;
if ( F_269 ( V_87 ) ) {
F_276 ( & V_222 -> V_224 ) ;
F_277 ( & V_222 -> V_229 ) ;
F_263 ( V_222 ) ;
F_278 ( V_87 ) ;
}
}
static unsigned int F_330 ( unsigned int V_59 ,
struct V_17 * * V_250 )
__releases( &khugepaged_mm_lock
static int F_331 ( void )
{
return ! F_14 ( & V_13 . V_14 ) &&
F_8 () ;
}
static int F_332 ( void )
{
return ! F_14 ( & V_13 . V_14 ) ||
F_333 () ;
}
static void F_334 ( void )
{
struct V_17 * V_250 = NULL ;
unsigned int V_263 = 0 , V_264 = 0 ;
unsigned int V_59 = V_58 ;
bool V_251 = true ;
F_335 () ;
while ( V_263 < V_59 ) {
if ( ! F_310 ( & V_250 , & V_251 ) )
break;
F_150 () ;
if ( F_10 ( F_333 () || F_336 () ) )
break;
F_167 ( & V_228 ) ;
if ( ! V_13 . V_222 )
V_264 ++ ;
if ( F_331 () &&
V_264 < 2 )
V_263 += F_330 ( V_59 - V_263 ,
& V_250 ) ;
else
V_263 = V_59 ;
F_100 ( & V_228 ) ;
}
if ( ! F_337 ( V_250 ) )
F_101 ( V_250 ) ;
}
static void F_338 ( void )
{
if ( F_331 () ) {
if ( ! V_54 )
return;
F_305 ( V_15 ,
F_333 () ,
F_306 ( V_54 ) ) ;
return;
}
if ( F_8 () )
F_339 ( V_15 , F_332 () ) ;
}
static int V_11 ( void * V_265 )
{
struct V_222 * V_222 ;
F_340 () ;
F_341 ( V_266 , V_267 ) ;
while ( ! F_333 () ) {
F_334 () ;
F_338 () ;
}
F_167 ( & V_228 ) ;
V_222 = V_13 . V_222 ;
V_13 . V_222 = NULL ;
if ( V_222 )
F_328 ( V_222 ) ;
F_100 ( & V_228 ) ;
return 0 ;
}
static void F_342 ( struct V_80 * V_81 ,
unsigned long V_88 , T_1 * V_16 )
{
struct V_86 * V_87 = V_81 -> V_145 ;
T_7 V_92 ;
T_1 V_130 ;
int V_131 ;
F_152 ( V_81 , V_88 , V_16 ) ;
V_92 = F_153 ( V_87 , V_16 ) ;
F_154 ( V_87 , & V_130 , V_92 ) ;
for ( V_131 = 0 ; V_131 < V_32 ; V_131 ++ , V_88 += V_137 ) {
T_9 * V_139 , V_85 ;
V_85 = F_343 ( F_344 ( V_88 ) , V_81 -> V_95 ) ;
V_85 = F_345 ( V_85 ) ;
V_139 = F_158 ( & V_130 , V_88 ) ;
F_42 ( ! F_159 ( * V_139 ) ) ;
F_160 ( V_87 , V_88 , V_139 , V_85 ) ;
F_161 ( V_139 ) ;
}
F_162 () ;
F_154 ( V_87 , V_16 , V_92 ) ;
F_32 () ;
}
void F_346 ( struct V_80 * V_81 , unsigned long V_101 ,
T_1 * V_16 )
{
T_8 * V_93 ;
struct V_17 * V_17 ;
struct V_86 * V_87 = V_81 -> V_145 ;
unsigned long V_88 = V_101 & V_103 ;
unsigned long V_132 ;
unsigned long V_133 ;
F_33 ( V_81 -> V_104 > V_88 || V_81 -> V_106 < V_88 + V_105 ) ;
V_132 = V_88 ;
V_133 = V_88 + V_105 ;
V_268:
F_151 ( V_87 , V_132 , V_133 ) ;
V_93 = F_98 ( V_87 , V_16 ) ;
if ( F_10 ( ! F_123 ( * V_16 ) ) ) {
F_100 ( V_93 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
return;
}
if ( F_17 ( * V_16 ) ) {
F_342 ( V_81 , V_88 , V_16 ) ;
F_100 ( V_93 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
return;
}
V_17 = F_19 ( * V_16 ) ;
F_91 ( ! F_237 ( V_17 ) , V_17 ) ;
F_127 ( V_17 ) ;
F_100 ( V_93 ) ;
F_164 ( V_87 , V_132 , V_133 ) ;
F_172 ( V_17 ) ;
F_101 ( V_17 ) ;
if ( F_10 ( F_123 ( * V_16 ) ) )
goto V_268;
}
void F_347 ( struct V_86 * V_87 , unsigned long V_101 ,
T_1 * V_16 )
{
struct V_80 * V_81 ;
V_81 = F_320 ( V_87 , V_101 ) ;
F_33 ( V_81 == NULL ) ;
F_171 ( V_81 , V_101 , V_16 ) ;
}
static void F_348 ( struct V_86 * V_87 ,
unsigned long V_101 )
{
T_10 * V_188 ;
T_11 * V_189 ;
T_1 * V_16 ;
F_42 ( ! ( V_101 & ~ V_103 ) ) ;
V_188 = F_211 ( V_87 , V_101 ) ;
if ( ! F_212 ( * V_188 ) )
return;
V_189 = F_213 ( V_188 , V_101 ) ;
if ( ! F_214 ( * V_189 ) )
return;
V_16 = F_215 ( V_189 , V_101 ) ;
if ( ! F_216 ( * V_16 ) )
return;
F_347 ( V_87 , V_101 , V_16 ) ;
}
void F_349 ( struct V_80 * V_81 ,
unsigned long V_269 ,
unsigned long V_270 ,
long V_271 )
{
if ( V_269 & ~ V_103 &&
( V_269 & V_103 ) >= V_81 -> V_104 &&
( V_269 & V_103 ) + V_105 <= V_81 -> V_106 )
F_348 ( V_81 -> V_145 , V_269 ) ;
if ( V_270 & ~ V_103 &&
( V_270 & V_103 ) >= V_81 -> V_104 &&
( V_270 & V_103 ) + V_105 <= V_81 -> V_106 )
F_348 ( V_81 -> V_145 , V_270 ) ;
if ( V_271 > 0 ) {
struct V_80 * V_272 = V_81 -> V_273 ;
unsigned long V_274 = V_272 -> V_104 ;
V_274 += V_271 << V_6 ;
if ( V_274 & ~ V_103 &&
( V_274 & V_103 ) >= V_272 -> V_104 &&
( V_274 & V_103 ) + V_105 <= V_272 -> V_106 )
F_348 ( V_272 -> V_145 , V_274 ) ;
}
}
