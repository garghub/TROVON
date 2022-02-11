static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline int F_4 ( T_1 V_1 )
{
int V_5 , V_6 ;
V_6 = F_5 ( V_1 ) ;
V_5 = ( 1 << V_4 ) - 1 ;
if ( V_1 & V_5 )
V_6 += 1 ;
return V_6 ;
}
static inline T_3 F_6 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_7 ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return F_8 ( V_1 << V_7 , V_2 ) ;
}
static inline T_1 F_9 ( int V_8 )
{
return F_7 ( V_8 , 100 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_11 = 100 ;
V_10 -> V_12 = F_11 ( 1 ) ;
V_10 -> V_13 = 100 ;
V_10 -> V_14 = 100 ;
}
static bool F_12 ( void )
{
if ( V_15 . V_16 == V_17 ||
V_15 . V_16 == V_18 )
return true ;
return V_19 ;
}
static void F_13 ( struct V_20 * V_21 )
{
F_14 () ;
}
static void F_15 ( int V_22 )
{
struct V_23 V_24 ;
static T_4 V_25 = 0 , V_26 = V_27 ;
int V_6 ;
V_6 = F_16 ( V_22 , & V_24 ) ;
if ( V_6 )
return;
F_17 ( V_24 . V_28 , V_22 ) ;
if ( V_25 <= V_26 ) {
if ( V_24 . V_28 > V_25 )
V_25 = V_24 . V_28 ;
if ( V_24 . V_28 < V_26 )
V_26 = V_24 . V_28 ;
if ( V_25 > V_26 ) {
F_18 ( & V_29 ) ;
}
}
}
static void F_15 ( int V_22 )
{
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_32 * V_22 ;
int V_6 ;
int V_33 ;
if ( V_34 ) {
F_15 ( V_31 -> V_22 ) ;
return;
}
if ( ! F_12 () )
return;
V_22 = V_35 [ V_31 -> V_22 ] ;
V_6 = F_20 ( & V_22 -> V_36 ,
V_31 -> V_22 ) ;
if ( V_6 )
return;
if ( V_22 -> V_36 . V_37 . V_38 !=
V_39 )
goto V_40;
if ( V_22 -> V_36 . V_41 < 2 )
goto V_40;
F_21 ( L_1 , V_31 -> V_22 ) ;
for ( V_33 = 0 ; V_33 < V_22 -> V_36 . V_41 ; V_33 ++ ) {
F_21 ( L_2 ,
( V_33 == V_22 -> V_36 . V_42 ? '*' : ' ' ) , V_33 ,
( T_4 ) V_22 -> V_36 . V_43 [ V_33 ] . V_44 ,
( T_4 ) V_22 -> V_36 . V_43 [ V_33 ] . V_45 ,
( T_4 ) V_22 -> V_36 . V_43 [ V_33 ] . V_46 ) ;
}
if ( ! V_47 . V_48 )
V_22 -> V_36 . V_43 [ 0 ] . V_44 =
V_31 -> V_49 . V_50 / 1000 ;
V_22 -> V_51 = true ;
F_21 ( L_3 ) ;
return;
V_40:
V_22 -> V_51 = false ;
F_22 ( V_31 -> V_22 ) ;
}
static void F_23 ( struct V_30 * V_31 )
{
struct V_32 * V_22 ;
V_22 = V_35 [ V_31 -> V_22 ] ;
if ( ! V_22 -> V_51 )
return;
F_22 ( V_31 -> V_22 ) ;
}
static inline void F_19 ( struct V_30 * V_31 )
{
}
static inline void F_23 ( struct V_30 * V_31 )
{
}
static inline void F_24 ( struct V_52 * V_53 , int V_54 , int V_55 ,
int V_56 , int V_57 ) {
V_53 -> V_54 = F_25 ( V_54 ) ;
V_53 -> V_56 = F_25 ( V_56 ) ;
V_53 -> V_57 = F_25 ( V_57 ) ;
V_53 -> V_58 = F_25 ( V_54 ) - F_25 ( V_55 ) ;
}
static inline void F_26 ( struct V_52 * V_53 , int V_8 )
{
V_53 -> V_59 = F_2 ( V_8 , 100 ) ;
}
static inline void F_27 ( struct V_52 * V_53 , int V_8 )
{
V_53 -> V_60 = F_2 ( V_8 , 100 ) ;
}
static inline void F_28 ( struct V_52 * V_53 , int V_8 )
{
V_53 -> V_61 = F_2 ( V_8 , 100 ) ;
}
static signed int F_29 ( struct V_52 * V_53 , T_1 V_55 )
{
signed int V_62 ;
T_1 V_63 , V_64 , V_65 ;
T_1 V_66 ;
V_65 = V_53 -> V_54 - V_55 ;
if ( abs ( V_65 ) <= V_53 -> V_56 )
return 0 ;
V_63 = F_1 ( V_53 -> V_59 , V_65 ) ;
V_53 -> V_57 += V_65 ;
V_66 = F_25 ( 30 ) ;
if ( V_53 -> V_57 > V_66 )
V_53 -> V_57 = V_66 ;
if ( V_53 -> V_57 < - V_66 )
V_53 -> V_57 = - V_66 ;
V_64 = F_1 ( V_53 -> V_61 , V_65 - V_53 -> V_58 ) ;
V_53 -> V_58 = V_65 ;
V_62 = V_63 + F_1 ( V_53 -> V_57 , V_53 -> V_60 ) + V_64 ;
V_62 = V_62 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_62 ) ;
}
static inline void F_30 ( struct V_32 * V_22 )
{
F_26 ( & V_22 -> V_53 , V_67 . V_68 ) ;
F_28 ( & V_22 -> V_53 , V_67 . V_69 ) ;
F_27 ( & V_22 -> V_53 , V_67 . V_70 ) ;
F_24 ( & V_22 -> V_53 , V_67 . V_54 , 100 , V_67 . V_56 , 0 ) ;
}
static inline void F_31 ( void )
{
unsigned int V_22 ;
F_32 (cpu) {
if ( V_35 [ V_22 ] )
F_30 ( V_35 [ V_22 ] ) ;
}
}
static inline void F_33 ( void )
{
T_3 V_71 ;
struct V_32 * V_22 ;
V_22 = V_35 [ 0 ] ;
F_34 ( V_72 , V_71 ) ;
V_47 . V_48 =
( V_71 & V_73 ||
V_22 -> V_74 . V_75 == V_22 -> V_74 . V_76 ) ;
}
static T_5 F_35 ( struct V_32 * V_77 )
{
T_3 V_78 ;
int V_6 ;
if ( ! F_36 ( V_79 ) )
return - V_80 ;
V_6 = F_37 ( V_77 -> V_22 , V_81 , & V_78 ) ;
if ( V_6 )
return ( T_5 ) V_6 ;
return ( T_5 ) ( V_78 & 0x0f ) ;
}
static T_5 F_38 ( struct V_32 * V_77 , T_3 V_82 )
{
T_5 V_83 ;
if ( F_36 ( V_84 ) ) {
if ( ! V_82 ) {
V_83 = F_37 ( V_77 -> V_22 , V_85 ,
& V_82 ) ;
if ( V_83 )
return V_83 ;
}
V_83 = ( V_82 >> 24 ) & 0xff ;
} else {
V_83 = F_35 ( V_77 ) ;
}
return V_83 ;
}
static int F_39 ( int V_22 , T_5 V_86 )
{
T_3 V_78 ;
int V_6 ;
if ( ! F_36 ( V_79 ) )
return - V_80 ;
V_6 = F_37 ( V_22 , V_81 , & V_78 ) ;
if ( V_6 )
return V_6 ;
V_78 = ( V_78 & ~ 0x0f ) | V_86 ;
F_40 ( V_22 , V_81 , V_78 ) ;
return 0 ;
}
static int F_41 ( struct V_32 * V_77 )
{
T_5 V_83 ;
int V_87 = - V_88 ;
V_83 = F_38 ( V_77 , 0 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( F_36 ( V_84 ) ) {
V_87 = ( V_83 >> 6 ) + 1 ;
} else if ( F_36 ( V_79 ) ) {
V_87 = ( V_83 >> 2 ) + 1 ;
}
return V_87 ;
}
static int F_42 ( struct V_32 * V_77 ,
int V_89 )
{
int V_83 = - V_88 ;
int V_6 ;
if ( ! V_89 )
V_83 = V_77 -> V_90 ;
F_43 ( & V_91 ) ;
if ( F_36 ( V_84 ) ) {
T_3 V_92 ;
V_6 = F_37 ( V_77 -> V_22 , V_85 , & V_92 ) ;
if ( V_6 )
goto V_93;
V_92 &= ~ F_44 ( 31 , 24 ) ;
if ( V_83 == - V_88 )
V_83 = ( V_89 - 1 ) << 6 ;
V_92 |= ( T_3 ) V_83 << 24 ;
V_6 = F_40 ( V_77 -> V_22 , V_85 , V_92 ) ;
} else {
if ( V_83 == - V_88 )
V_83 = ( V_89 - 1 ) << 2 ;
V_6 = F_39 ( V_77 -> V_22 , V_83 ) ;
}
V_93:
F_45 ( & V_91 ) ;
return V_6 ;
}
static T_6 F_46 (
struct V_30 * V_31 , char * V_94 )
{
int V_33 = 0 ;
int V_6 = 0 ;
while ( V_95 [ V_33 ] != NULL )
V_6 += sprintf ( & V_94 [ V_6 ] , L_4 , V_95 [ V_33 ++ ] ) ;
V_6 += sprintf ( & V_94 [ V_6 ] , L_5 ) ;
return V_6 ;
}
static T_6 F_47 (
struct V_30 * V_31 , const char * V_94 , T_7 V_96 )
{
struct V_32 * V_77 = V_35 [ V_31 -> V_22 ] ;
char V_97 [ 21 ] ;
int V_6 , V_33 = 0 ;
V_6 = sscanf ( V_94 , L_6 , V_97 ) ;
if ( V_6 != 1 )
return - V_88 ;
while ( V_95 [ V_33 ] != NULL ) {
if ( ! strcmp ( V_97 , V_95 [ V_33 ] ) ) {
F_42 ( V_77 , V_33 ) ;
return V_96 ;
}
++ V_33 ;
}
return - V_88 ;
}
static T_6 F_48 (
struct V_30 * V_31 , char * V_94 )
{
struct V_32 * V_77 = V_35 [ V_31 -> V_22 ] ;
int V_98 ;
V_98 = F_41 ( V_77 ) ;
if ( V_98 < 0 )
return V_98 ;
return sprintf ( V_94 , L_7 , V_95 [ V_98 ] ) ;
}
static void F_49 ( struct V_30 * V_31 )
{
int V_99 , V_100 , V_101 , V_102 , V_22 ;
struct V_9 * V_9 = & V_47 ;
T_3 V_92 , V_103 ;
F_50 (cpu, policy->cpus) {
struct V_32 * V_77 = V_35 [ V_22 ] ;
T_5 V_83 ;
if ( V_104 )
V_9 = V_35 [ V_22 ] -> V_9 ;
F_37 ( V_22 , V_105 , & V_103 ) ;
V_100 = F_51 ( V_103 ) ;
if ( V_47 . V_106 )
V_102 = F_52 ( V_103 ) ;
else
V_102 = F_53 ( V_103 ) ;
V_101 = F_54 ( V_102 * V_9 -> V_12 ) ;
if ( V_77 -> V_31 == V_107 )
V_99 = V_101 ;
else
V_99 = F_54 ( V_102 * V_9 -> V_108 ) ;
F_37 ( V_22 , V_85 , & V_92 ) ;
V_92 &= ~ F_55 ( ~ 0L ) ;
V_92 |= F_55 ( V_99 ) ;
V_92 &= ~ F_56 ( ~ 0L ) ;
V_92 |= F_56 ( V_101 ) ;
if ( V_77 -> V_109 == V_77 -> V_31 )
goto V_110;
V_77 -> V_109 = V_77 -> V_31 ;
if ( V_77 -> V_111 >= 0 ) {
V_83 = V_77 -> V_111 ;
V_77 -> V_111 = - V_88 ;
goto V_112;
}
if ( V_77 -> V_31 == V_107 ) {
V_83 = F_38 ( V_77 , V_92 ) ;
V_77 -> V_113 = V_83 ;
if ( V_83 < 0 )
goto V_110;
V_83 = 0 ;
} else {
if ( V_77 -> V_113 < 0 )
goto V_110;
V_83 = F_38 ( V_77 , V_92 ) ;
if ( V_83 )
goto V_110;
V_83 = V_77 -> V_113 ;
}
V_112:
if ( F_36 ( V_84 ) ) {
V_92 &= ~ F_44 ( 31 , 24 ) ;
V_92 |= ( T_3 ) V_83 << 24 ;
} else {
F_39 ( V_22 , V_83 ) ;
}
V_110:
F_40 ( V_22 , V_85 , V_92 ) ;
}
}
static int F_57 ( struct V_30 * V_31 )
{
if ( V_34 )
F_49 ( V_31 ) ;
return 0 ;
}
static int F_58 ( struct V_30 * V_31 )
{
struct V_32 * V_77 = V_35 [ V_31 -> V_22 ] ;
if ( ! V_34 )
return 0 ;
V_77 -> V_111 = F_38 ( V_77 , 0 ) ;
return 0 ;
}
static int F_59 ( struct V_30 * V_31 )
{
int V_6 ;
if ( ! V_34 )
return 0 ;
F_43 ( & V_91 ) ;
V_35 [ V_31 -> V_22 ] -> V_109 = 0 ;
V_6 = F_57 ( V_31 ) ;
F_45 ( & V_91 ) ;
return V_6 ;
}
static void F_60 ( void )
{
int V_22 ;
F_61 (cpu)
F_62 ( V_22 ) ;
}
static int F_63 ( void * V_114 , T_3 V_115 )
{
* ( T_4 * ) V_114 = V_115 ;
V_67 . V_116 = V_67 . V_117 * V_118 ;
F_31 () ;
return 0 ;
}
static int F_64 ( void * V_114 , T_3 * V_115 )
{
* V_115 = * ( T_4 * ) V_114 ;
return 0 ;
}
static void F_65 ( void )
{
int V_33 ;
V_119 = F_66 ( L_8 , NULL ) ;
if ( F_67 ( V_119 ) )
return;
for ( V_33 = 0 ; V_120 [ V_33 ] . V_121 ; V_33 ++ ) {
struct V_122 * V_122 ;
V_122 = F_68 ( V_120 [ V_33 ] . V_121 , 0660 ,
V_119 , V_120 [ V_33 ] . V_92 ,
& V_123 ) ;
if ( ! F_69 ( V_122 ) )
V_120 [ V_33 ] . V_122 = V_122 ;
}
}
static void F_70 ( void )
{
int V_33 ;
if ( F_67 ( V_119 ) )
return;
for ( V_33 = 0 ; V_120 [ V_33 ] . V_121 ; V_33 ++ ) {
F_71 ( V_120 [ V_33 ] . V_122 ) ;
V_120 [ V_33 ] . V_122 = NULL ;
}
F_71 ( V_119 ) ;
V_119 = NULL ;
}
static T_6 F_72 ( struct V_124 * V_125 ,
struct V_126 * V_127 , char * V_94 )
{
T_6 V_6 ;
F_43 ( & V_128 ) ;
V_6 = F_73 ( V_94 ) ;
F_45 ( & V_128 ) ;
return V_6 ;
}
static T_6 F_74 ( struct V_124 * V_129 , struct V_126 * V_130 ,
const char * V_94 , T_7 V_96 )
{
char * V_131 = memchr ( V_94 , '\n' , V_96 ) ;
int V_6 ;
F_43 ( & V_128 ) ;
V_6 = F_75 ( V_94 , V_131 ? V_131 - V_94 : V_96 ) ;
F_45 ( & V_128 ) ;
return V_6 < 0 ? V_6 : V_96 ;
}
static T_6 F_76 ( struct V_124 * V_125 ,
struct V_126 * V_127 , char * V_94 )
{
struct V_32 * V_22 ;
int V_132 , V_106 , V_133 ;
T_8 V_134 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
V_22 = V_35 [ 0 ] ;
V_132 = V_22 -> V_74 . V_76 - V_22 -> V_74 . V_137 + 1 ;
V_106 = V_22 -> V_74 . V_75 - V_22 -> V_74 . V_137 + 1 ;
V_134 = F_2 ( V_106 , V_132 ) ;
V_133 = 100 - F_5 ( F_1 ( V_134 , F_25 ( 100 ) ) ) ;
F_45 ( & V_128 ) ;
return sprintf ( V_94 , L_9 , V_133 ) ;
}
static T_6 F_77 ( struct V_124 * V_125 ,
struct V_126 * V_127 , char * V_94 )
{
struct V_32 * V_22 ;
int V_132 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
V_22 = V_35 [ 0 ] ;
V_132 = V_22 -> V_74 . V_76 - V_22 -> V_74 . V_137 + 1 ;
F_45 ( & V_128 ) ;
return sprintf ( V_94 , L_9 , V_132 ) ;
}
static T_6 F_78 ( struct V_124 * V_125 ,
struct V_126 * V_127 , char * V_94 )
{
T_6 V_6 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
F_33 () ;
if ( V_47 . V_48 )
V_6 = sprintf ( V_94 , L_9 , V_47 . V_48 ) ;
else
V_6 = sprintf ( V_94 , L_9 , V_47 . V_106 ) ;
F_45 ( & V_128 ) ;
return V_6 ;
}
static T_6 F_79 ( struct V_124 * V_129 , struct V_126 * V_130 ,
const char * V_94 , T_7 V_96 )
{
unsigned int V_138 ;
int V_6 ;
V_6 = sscanf ( V_94 , L_10 , & V_138 ) ;
if ( V_6 != 1 )
return - V_88 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
F_43 ( & V_91 ) ;
F_33 () ;
if ( V_47 . V_48 ) {
F_80 ( L_11 ) ;
F_45 ( & V_91 ) ;
F_45 ( & V_128 ) ;
return - V_139 ;
}
V_47 . V_106 = F_81 ( int , V_138 , 0 , 1 ) ;
F_45 ( & V_91 ) ;
F_60 () ;
F_45 ( & V_128 ) ;
return V_96 ;
}
static T_6 F_82 ( struct V_124 * V_129 , struct V_126 * V_130 ,
const char * V_94 , T_7 V_96 )
{
unsigned int V_138 ;
int V_6 ;
V_6 = sscanf ( V_94 , L_10 , & V_138 ) ;
if ( V_6 != 1 )
return - V_88 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
F_43 ( & V_91 ) ;
V_47 . V_14 = F_81 ( int , V_138 , 0 , 100 ) ;
V_47 . V_11 = V_99 ( V_47 . V_13 , V_47 . V_14 ) ;
V_47 . V_11 = V_101 ( V_47 . V_140 , V_47 . V_11 ) ;
V_47 . V_11 = V_101 ( V_47 . V_141 , V_47 . V_11 ) ;
V_47 . V_12 = F_9 ( V_47 . V_11 ) ;
F_45 ( & V_91 ) ;
F_60 () ;
F_45 ( & V_128 ) ;
return V_96 ;
}
static T_6 F_83 ( struct V_124 * V_129 , struct V_126 * V_130 ,
const char * V_94 , T_7 V_96 )
{
unsigned int V_138 ;
int V_6 ;
V_6 = sscanf ( V_94 , L_10 , & V_138 ) ;
if ( V_6 != 1 )
return - V_88 ;
F_43 ( & V_128 ) ;
if ( ! V_135 ) {
F_45 ( & V_128 ) ;
return - V_136 ;
}
F_43 ( & V_91 ) ;
V_47 . V_142 = F_81 ( int , V_138 , 0 , 100 ) ;
V_47 . V_141 = V_101 ( V_47 . V_140 , V_47 . V_142 ) ;
V_47 . V_141 = V_99 ( V_47 . V_13 , V_47 . V_141 ) ;
V_47 . V_141 = V_99 ( V_47 . V_11 , V_47 . V_141 ) ;
V_47 . V_108 = F_9 ( V_47 . V_141 ) ;
F_45 ( & V_91 ) ;
F_60 () ;
F_45 ( & V_128 ) ;
return V_96 ;
}
static void T_9 F_84 ( void )
{
struct V_124 * V_143 ;
int V_144 ;
V_143 = F_85 ( L_12 ,
& V_145 . V_146 -> V_125 ) ;
if ( F_86 ( ! V_143 ) )
return;
V_144 = F_87 ( V_143 , & V_147 ) ;
if ( F_86 ( V_144 ) )
return;
if ( V_104 )
return;
V_144 = F_88 ( V_143 , & V_11 . V_127 ) ;
F_86 ( V_144 ) ;
V_144 = F_88 ( V_143 , & V_141 . V_127 ) ;
F_86 ( V_144 ) ;
}
static void F_89 ( struct V_32 * V_32 )
{
if ( F_36 ( V_148 ) )
F_40 ( V_32 -> V_22 , V_149 , 0x00 ) ;
F_40 ( V_32 -> V_22 , V_150 , 0x1 ) ;
V_32 -> V_109 = 0 ;
if ( V_32 -> V_90 == - V_88 )
V_32 -> V_90 = F_38 ( V_32 , 0 ) ;
}
static void F_90 ( int V_22 )
{
T_3 V_151 ;
int V_6 ;
V_6 = F_37 ( V_22 , V_152 , & V_151 ) ;
if ( V_6 )
return;
if ( ! ( V_151 & F_91 ( V_153 ) ) ) {
F_92 ( L_13 ) ;
V_151 |= F_91 ( V_153 ) ;
F_40 ( V_22 , V_152 , V_151 ) ;
}
}
static int F_93 ( void )
{
T_3 V_92 ;
F_34 ( V_154 , V_92 ) ;
return ( V_92 >> 8 ) & 0x7F ;
}
static int F_94 ( void )
{
T_3 V_92 ;
F_34 ( V_154 , V_92 ) ;
return ( V_92 >> 16 ) & 0x7F ;
}
static int F_95 ( void )
{
T_3 V_92 ;
F_34 ( V_155 , V_92 ) ;
return V_92 & 0x7F ;
}
static T_3 F_96 ( struct V_32 * V_32 , int V_74 )
{
T_3 V_115 ;
T_1 V_156 ;
T_4 V_157 ;
V_115 = ( T_3 ) V_74 << 8 ;
if ( V_47 . V_106 && ! V_47 . V_48 )
V_115 |= ( T_3 ) 1 << 32 ;
V_156 = V_32 -> V_157 . V_99 + F_1 (
F_25 ( V_74 - V_32 -> V_74 . V_137 ) ,
V_32 -> V_157 . V_158 ) ;
V_156 = F_81 ( T_1 , V_156 , V_32 -> V_157 . V_99 , V_32 -> V_157 . V_101 ) ;
V_157 = F_4 ( V_156 ) ;
if ( V_74 > V_32 -> V_74 . V_75 )
V_157 = V_32 -> V_157 . V_159 ;
return V_115 | V_157 ;
}
static int F_97 ( void )
{
T_3 V_92 ;
int V_33 ;
static int V_160 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_34 ( V_161 , V_92 ) ;
V_33 = V_92 & 0x7 ;
F_86 ( V_33 > 4 ) ;
return V_160 [ V_33 ] ;
}
static int F_98 ( void )
{
T_3 V_92 ;
int V_33 ;
static int V_162 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_34 ( V_161 , V_92 ) ;
V_33 = V_92 & 0xF ;
F_86 ( V_33 > 8 ) ;
return V_162 [ V_33 ] ;
}
static void F_99 ( struct V_32 * V_32 )
{
T_3 V_92 ;
F_34 ( V_163 , V_92 ) ;
V_32 -> V_157 . V_99 = F_25 ( ( V_92 >> 8 ) & 0x7f ) ;
V_32 -> V_157 . V_101 = F_25 ( ( V_92 >> 16 ) & 0x7f ) ;
V_32 -> V_157 . V_158 = F_2 (
V_32 -> V_157 . V_101 - V_32 -> V_157 . V_99 ,
F_25 ( V_32 -> V_74 . V_75 -
V_32 -> V_74 . V_137 ) ) ;
F_34 ( V_164 , V_92 ) ;
V_32 -> V_157 . V_159 = V_92 & 0x7f ;
}
static int F_100 ( void )
{
T_3 V_92 ;
F_34 ( V_165 , V_92 ) ;
return ( V_92 >> 40 ) & 0xFF ;
}
static int F_101 ( void )
{
T_3 V_92 ;
F_34 ( V_165 , V_92 ) ;
return ( V_92 >> 8 ) & 0xFF ;
}
static int F_102 ( T_3 V_166 )
{
if ( V_166 & 0x600000000 ) {
T_3 V_167 ;
T_3 V_168 ;
int V_169 ;
int V_40 ;
V_40 = F_103 ( V_170 , & V_167 ) ;
if ( V_40 )
return V_40 ;
V_169 = V_171 + ( V_167 & 0x03 ) ;
V_40 = F_103 ( V_169 , & V_168 ) ;
if ( V_40 )
return V_40 ;
if ( V_167 & 0x03 )
V_168 >>= 16 ;
V_168 &= 0xff ;
F_21 ( L_14 , ( int ) V_168 ) ;
return ( int ) V_168 ;
}
return - V_80 ;
}
static int F_104 ( void )
{
T_3 V_172 ;
T_3 V_166 ;
int V_75 ;
int V_168 ;
int V_40 ;
F_34 ( V_165 , V_166 ) ;
V_75 = ( V_166 >> 8 ) & 0xFF ;
V_168 = F_102 ( V_166 ) ;
if ( V_168 <= 0 )
return V_75 ;
if ( V_34 ) {
return V_168 ;
}
V_40 = F_103 ( V_173 , & V_172 ) ;
if ( ! V_40 ) {
int V_174 ;
V_174 = V_172 & 0xff ;
if ( V_168 - 1 == V_174 ) {
V_75 = V_174 ;
F_21 ( L_15 , V_75 ) ;
}
}
return V_75 ;
}
static int F_105 ( void )
{
T_3 V_92 ;
int V_175 , V_6 ;
F_34 ( V_176 , V_92 ) ;
V_175 = F_104 () ;
V_6 = ( V_92 ) & 255 ;
if ( V_6 <= V_175 )
V_6 = V_175 ;
return V_6 ;
}
static inline int F_106 ( void )
{
return 100000 ;
}
static T_3 F_107 ( struct V_32 * V_32 , int V_74 )
{
T_3 V_115 ;
V_115 = ( T_3 ) V_74 << 8 ;
if ( V_47 . V_106 && ! V_47 . V_48 )
V_115 |= ( T_3 ) 1 << 32 ;
return V_115 ;
}
static int F_108 ( void )
{
T_3 V_92 ;
int V_175 , V_6 ;
F_34 ( V_176 , V_92 ) ;
V_175 = F_104 () ;
V_6 = ( ( ( V_92 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_175 )
V_6 = V_175 ;
return V_6 ;
}
static void F_109 ( struct V_32 * V_22 , int * V_99 , int * V_101 )
{
int V_12 = V_22 -> V_74 . V_76 ;
int V_177 ;
int V_108 ;
struct V_9 * V_9 = & V_47 ;
if ( V_47 . V_106 || V_47 . V_48 )
V_12 = V_22 -> V_74 . V_75 ;
if ( V_104 )
V_9 = V_22 -> V_9 ;
V_177 = F_54 ( V_12 * V_9 -> V_12 ) ;
* V_101 = F_81 ( int , V_177 ,
V_22 -> V_74 . V_137 , V_22 -> V_74 . V_76 ) ;
V_108 = F_54 ( V_12 * V_9 -> V_108 ) ;
* V_99 = F_81 ( int , V_108 , V_22 -> V_74 . V_137 , V_12 ) ;
}
static void F_110 ( struct V_32 * V_22 , int V_74 )
{
F_111 ( V_74 * V_22 -> V_74 . V_178 , V_22 -> V_22 ) ;
V_22 -> V_74 . V_179 = V_74 ;
F_40 ( V_22 -> V_22 , V_180 ,
V_181 . V_182 ( V_22 , V_74 ) ) ;
}
static void F_112 ( struct V_32 * V_22 )
{
F_110 ( V_22 , V_22 -> V_74 . V_137 ) ;
}
static void F_113 ( struct V_32 * V_22 )
{
int V_137 , V_75 ;
F_33 () ;
F_109 ( V_22 , & V_137 , & V_75 ) ;
F_110 ( V_22 , V_75 ) ;
}
static void F_114 ( struct V_32 * V_22 )
{
V_22 -> V_74 . V_137 = V_181 . V_183 () ;
V_22 -> V_74 . V_75 = V_181 . V_184 () ;
V_22 -> V_74 . V_185 = V_181 . V_186 () ;
V_22 -> V_74 . V_76 = V_181 . V_187 () ;
V_22 -> V_74 . V_178 = V_181 . V_188 () ;
V_22 -> V_74 . V_50 = V_22 -> V_74 . V_75 * V_22 -> V_74 . V_178 ;
V_22 -> V_74 . V_189 = V_22 -> V_74 . V_76 * V_22 -> V_74 . V_178 ;
if ( V_181 . V_190 )
V_181 . V_190 ( V_22 ) ;
F_112 ( V_22 ) ;
}
static inline void F_115 ( struct V_32 * V_22 )
{
struct V_191 * V_191 = & V_22 -> V_191 ;
V_191 -> V_192 = F_7 ( V_191 -> V_193 , V_191 -> V_194 ) ;
}
static inline bool F_116 ( struct V_32 * V_22 , T_3 time )
{
T_3 V_193 , V_194 ;
unsigned long V_195 ;
T_3 V_196 ;
F_117 ( V_195 ) ;
F_34 ( V_197 , V_193 ) ;
F_34 ( V_198 , V_194 ) ;
V_196 = F_118 () ;
if ( V_22 -> V_199 == V_194 || V_22 -> V_200 == V_196 ) {
F_119 ( V_195 ) ;
return false ;
}
F_119 ( V_195 ) ;
V_22 -> V_201 = V_22 -> V_191 . time ;
V_22 -> V_191 . time = time ;
V_22 -> V_191 . V_193 = V_193 ;
V_22 -> V_191 . V_194 = V_194 ;
V_22 -> V_191 . V_196 = V_196 ;
V_22 -> V_191 . V_193 -= V_22 -> V_202 ;
V_22 -> V_191 . V_194 -= V_22 -> V_199 ;
V_22 -> V_191 . V_196 -= V_22 -> V_200 ;
V_22 -> V_202 = V_193 ;
V_22 -> V_199 = V_194 ;
V_22 -> V_200 = V_196 ;
return ! ! V_22 -> V_201 ;
}
static inline T_1 F_120 ( struct V_32 * V_22 )
{
return F_6 ( V_22 -> V_191 . V_192 ,
V_22 -> V_74 . V_185 * V_22 -> V_74 . V_178 ) ;
}
static inline T_1 F_121 ( struct V_32 * V_22 )
{
return F_6 ( V_22 -> V_74 . V_185 ,
V_22 -> V_191 . V_192 ) ;
}
static inline T_1 F_122 ( struct V_32 * V_22 )
{
struct V_191 * V_191 = & V_22 -> V_191 ;
T_1 V_203 , V_204 ;
int V_205 , V_206 ;
V_203 = F_2 ( V_191 -> V_194 , V_191 -> V_196 ) ;
V_204 = V_22 -> V_207 ;
V_22 -> V_207 >>= 1 ;
if ( V_203 < V_204 )
V_203 = V_204 ;
V_191 -> V_208 = V_203 * 100 ;
V_205 = V_47 . V_106 || V_47 . V_48 ?
V_22 -> V_74 . V_75 : V_22 -> V_74 . V_76 ;
V_205 += V_205 >> 2 ;
V_205 = F_1 ( V_205 , V_203 ) ;
if ( V_205 < V_22 -> V_74 . V_137 )
V_205 = V_22 -> V_74 . V_137 ;
V_206 = F_121 ( V_22 ) ;
if ( V_206 > V_205 )
V_205 += ( V_206 - V_205 ) >> 1 ;
return V_205 ;
}
static inline T_1 F_123 ( struct V_32 * V_22 )
{
T_1 V_209 , V_75 , V_179 , V_210 ;
T_3 V_211 ;
V_75 = V_22 -> V_74 . V_185 ;
V_179 = V_22 -> V_74 . V_179 ;
V_209 = F_6 ( V_22 -> V_191 . V_192 ,
F_2 ( 100 * V_75 , V_179 ) ) ;
V_211 = V_22 -> V_191 . time - V_22 -> V_201 ;
if ( ( T_2 ) V_211 > V_67 . V_116 * 3 ) {
V_210 = F_2 ( V_67 . V_116 , V_211 ) ;
V_209 = F_1 ( V_209 , V_210 ) ;
} else {
V_210 = F_2 ( 100 * V_22 -> V_191 . V_194 , V_22 -> V_191 . V_196 ) ;
if ( V_210 < F_25 ( 1 ) )
V_209 = 0 ;
}
V_22 -> V_191 . V_208 = V_209 ;
return V_22 -> V_74 . V_179 - F_29 ( & V_22 -> V_53 , V_209 ) ;
}
static int F_124 ( struct V_32 * V_22 , int V_74 )
{
int V_12 , V_108 ;
F_109 ( V_22 , & V_108 , & V_12 ) ;
V_74 = F_81 ( int , V_74 , V_108 , V_12 ) ;
return V_74 ;
}
static void F_125 ( struct V_32 * V_22 , int V_74 )
{
if ( V_74 == V_22 -> V_74 . V_179 )
return;
V_22 -> V_74 . V_179 = V_74 ;
F_126 ( V_180 , V_181 . V_182 ( V_22 , V_74 ) ) ;
}
static inline void F_127 ( struct V_32 * V_22 )
{
int V_212 , V_213 ;
struct V_191 * V_191 ;
V_212 = V_22 -> V_74 . V_179 ;
V_213 = V_22 -> V_31 == V_107 ?
V_22 -> V_74 . V_76 : V_181 . V_214 ( V_22 ) ;
F_33 () ;
V_213 = F_124 ( V_22 , V_213 ) ;
F_111 ( V_213 * V_22 -> V_74 . V_178 , V_22 -> V_22 ) ;
F_125 ( V_22 , V_213 ) ;
V_191 = & V_22 -> V_191 ;
F_128 ( F_6 ( 100 , V_191 -> V_192 ) ,
F_5 ( V_191 -> V_208 ) ,
V_212 ,
V_22 -> V_74 . V_179 ,
V_191 -> V_194 ,
V_191 -> V_193 ,
V_191 -> V_196 ,
F_120 ( V_22 ) ,
F_5 ( V_22 -> V_207 * 100 ) ) ;
}
static void F_129 ( struct V_215 * V_114 , T_3 time ,
unsigned int V_195 )
{
struct V_32 * V_22 = F_130 ( V_114 , struct V_32 , V_216 ) ;
T_3 V_217 ;
if ( V_181 . V_214 == F_122 ) {
if ( V_195 & V_218 ) {
V_22 -> V_207 = F_25 ( 1 ) ;
} else if ( V_22 -> V_207 ) {
V_217 = time - V_22 -> V_219 ;
if ( V_217 > V_220 )
V_22 -> V_207 = 0 ;
}
V_22 -> V_219 = time ;
}
V_217 = time - V_22 -> V_191 . time ;
if ( ( T_2 ) V_217 >= V_67 . V_116 ) {
bool V_221 = F_116 ( V_22 , time ) ;
if ( V_221 ) {
F_115 ( V_22 ) ;
if ( ! V_34 )
F_127 ( V_22 ) ;
}
}
}
static int F_131 ( unsigned int V_222 )
{
struct V_32 * V_22 ;
V_22 = V_35 [ V_222 ] ;
if ( ! V_22 ) {
unsigned int V_223 = sizeof( struct V_32 ) ;
if ( V_104 )
V_223 += sizeof( struct V_9 ) ;
V_22 = F_132 ( V_223 , V_224 ) ;
if ( ! V_22 )
return - V_225 ;
V_35 [ V_222 ] = V_22 ;
if ( V_104 )
V_22 -> V_9 = (struct V_9 * ) ( V_22 + 1 ) ;
V_22 -> V_90 = - V_88 ;
V_22 -> V_113 = - V_88 ;
V_22 -> V_111 = - V_88 ;
}
V_22 = V_35 [ V_222 ] ;
V_22 -> V_22 = V_222 ;
if ( V_34 ) {
const struct V_226 * V_227 ;
V_227 = F_133 ( V_228 ) ;
if ( V_227 )
F_90 ( V_222 ) ;
F_89 ( V_22 ) ;
V_67 . V_117 = 50 ;
V_67 . V_116 = 50 * V_118 ;
}
F_114 ( V_22 ) ;
F_30 ( V_22 ) ;
F_21 ( L_16 , V_222 ) ;
return 0 ;
}
static unsigned int F_134 ( unsigned int V_229 )
{
struct V_32 * V_22 = V_35 [ V_229 ] ;
return V_22 ? F_120 ( V_22 ) : 0 ;
}
static void F_135 ( unsigned int V_229 )
{
struct V_32 * V_22 = V_35 [ V_229 ] ;
if ( V_22 -> V_230 )
return;
V_22 -> V_191 . time = 0 ;
F_136 ( V_229 , & V_22 -> V_216 ,
F_129 ) ;
V_22 -> V_230 = true ;
}
static void F_137 ( unsigned int V_22 )
{
struct V_32 * V_77 = V_35 [ V_22 ] ;
if ( ! V_77 -> V_230 )
return;
F_138 ( V_22 ) ;
V_77 -> V_230 = false ;
F_139 () ;
}
static void F_140 ( struct V_30 * V_31 ,
struct V_9 * V_10 )
{
T_1 V_231 , V_232 ;
V_231 = F_7 ( V_31 -> V_101 , V_31 -> V_49 . V_50 ) ;
V_231 = F_81 ( T_1 , V_231 , 0 , F_11 ( 1 ) ) ;
if ( V_31 -> V_101 == V_31 -> V_99 ) {
V_232 = V_231 ;
} else {
V_232 = F_7 ( V_31 -> V_99 ,
V_31 -> V_49 . V_50 ) ;
V_232 = F_81 ( T_1 , V_232 ,
0 , V_231 ) ;
}
V_10 -> V_108 = V_101 ( V_232 ,
F_9 ( V_10 -> V_142 ) ) ;
V_10 -> V_108 = V_99 ( V_10 -> V_108 , V_231 ) ;
V_10 -> V_12 = V_99 ( V_231 ,
F_9 ( V_10 -> V_14 ) ) ;
V_10 -> V_12 = V_101 ( V_232 , V_10 -> V_12 ) ;
V_10 -> V_108 = V_99 ( V_10 -> V_108 , V_10 -> V_12 ) ;
V_10 -> V_12 = F_141 ( V_10 -> V_12 , V_7 ) ;
V_10 -> V_108 = F_141 ( V_10 -> V_108 , V_7 ) ;
V_10 -> V_11 = F_54 ( V_10 -> V_12 * 100 ) ;
V_10 -> V_141 = F_54 ( V_10 -> V_108 * 100 ) ;
F_21 ( L_17 , V_31 -> V_22 ,
V_10 -> V_11 , V_10 -> V_141 ) ;
}
static int F_142 ( struct V_30 * V_31 )
{
struct V_32 * V_22 ;
struct V_9 * V_9 = & V_47 ;
if ( ! V_31 -> V_49 . V_50 )
return - V_233 ;
F_21 ( L_18 ,
V_31 -> V_49 . V_50 , V_31 -> V_101 ) ;
V_22 = V_35 [ V_31 -> V_22 ] ;
V_22 -> V_31 = V_31 -> V_31 ;
if ( V_22 -> V_74 . V_185 > V_22 -> V_74 . V_75 &&
V_31 -> V_101 < V_31 -> V_49 . V_50 &&
V_31 -> V_101 > V_22 -> V_74 . V_75 * V_22 -> V_74 . V_178 ) {
F_21 ( L_19 ) ;
V_31 -> V_101 = V_31 -> V_49 . V_50 ;
}
if ( V_104 )
V_9 = V_22 -> V_9 ;
F_43 ( & V_91 ) ;
F_140 ( V_31 , V_9 ) ;
if ( V_22 -> V_31 == V_107 ) {
F_137 ( V_31 -> V_22 ) ;
F_113 ( V_22 ) ;
}
F_135 ( V_31 -> V_22 ) ;
F_57 ( V_31 ) ;
F_45 ( & V_91 ) ;
return 0 ;
}
static int F_143 ( struct V_30 * V_31 )
{
struct V_32 * V_22 = V_35 [ V_31 -> V_22 ] ;
F_33 () ;
V_31 -> V_49 . V_50 = V_47 . V_48 || V_47 . V_106 ?
V_22 -> V_74 . V_50 :
V_22 -> V_74 . V_189 ;
F_144 ( V_31 ) ;
if ( V_31 -> V_31 != V_234 &&
V_31 -> V_31 != V_107 )
return - V_88 ;
if ( ! V_104 ) {
unsigned int V_50 , V_235 ;
V_50 = V_31 -> V_49 . V_50 *
V_47 . V_14 / 100 ;
V_235 = V_31 -> V_49 . V_50 *
V_47 . V_142 / 100 ;
F_145 ( V_31 , V_235 , V_50 ) ;
}
return 0 ;
}
static void F_146 ( struct V_30 * V_31 )
{
F_112 ( V_35 [ V_31 -> V_22 ] ) ;
}
static void F_147 ( struct V_30 * V_31 )
{
F_21 ( L_20 , V_31 -> V_22 ) ;
F_137 ( V_31 -> V_22 ) ;
if ( V_34 )
F_58 ( V_31 ) ;
else
F_146 ( V_31 ) ;
}
static int F_148 ( struct V_30 * V_31 )
{
F_23 ( V_31 ) ;
V_31 -> V_236 = false ;
return 0 ;
}
static int F_149 ( struct V_30 * V_31 )
{
struct V_32 * V_22 ;
int V_144 ;
V_144 = F_131 ( V_31 -> V_22 ) ;
if ( V_144 )
return V_144 ;
V_22 = V_35 [ V_31 -> V_22 ] ;
if ( V_104 )
F_10 ( V_22 -> V_9 ) ;
V_31 -> V_99 = V_22 -> V_74 . V_137 * V_22 -> V_74 . V_178 ;
V_31 -> V_101 = V_22 -> V_74 . V_76 * V_22 -> V_74 . V_178 ;
V_31 -> V_49 . V_235 = V_22 -> V_74 . V_137 * V_22 -> V_74 . V_178 ;
F_33 () ;
V_31 -> V_49 . V_50 = V_47 . V_48 ?
V_22 -> V_74 . V_75 : V_22 -> V_74 . V_76 ;
V_31 -> V_49 . V_50 *= V_22 -> V_74 . V_178 ;
F_19 ( V_31 ) ;
F_150 ( V_31 -> V_22 , V_31 -> V_237 ) ;
V_31 -> V_236 = true ;
return 0 ;
}
static int F_151 ( struct V_30 * V_31 )
{
int V_6 = F_149 ( V_31 ) ;
if ( V_6 )
return V_6 ;
V_31 -> V_49 . V_238 = V_239 ;
if ( F_152 ( V_240 ) )
V_31 -> V_31 = V_107 ;
else
V_31 -> V_31 = V_234 ;
return 0 ;
}
static int F_153 ( struct V_30 * V_31 )
{
struct V_32 * V_22 = V_35 [ V_31 -> V_22 ] ;
F_33 () ;
V_31 -> V_49 . V_50 = V_47 . V_106 || V_47 . V_48 ?
V_22 -> V_74 . V_50 : V_22 -> V_74 . V_189 ;
F_144 ( V_31 ) ;
return 0 ;
}
static int F_154 ( struct V_30 * V_31 ,
unsigned int V_241 ,
unsigned int V_242 )
{
struct V_32 * V_22 = V_35 [ V_31 -> V_22 ] ;
struct V_243 V_244 ;
int V_213 ;
F_33 () ;
V_244 . V_245 = V_31 -> V_246 ;
V_244 . V_247 = V_241 ;
F_155 ( V_31 , & V_244 ) ;
switch ( V_242 ) {
case V_248 :
V_213 = F_156 ( V_244 . V_247 , V_22 -> V_74 . V_178 ) ;
break;
case V_249 :
V_213 = V_244 . V_247 / V_22 -> V_74 . V_178 ;
break;
default:
V_213 = F_157 ( V_244 . V_247 , V_22 -> V_74 . V_178 ) ;
break;
}
V_213 = F_124 ( V_22 , V_213 ) ;
if ( V_213 != V_22 -> V_74 . V_179 ) {
V_22 -> V_74 . V_179 = V_213 ;
F_40 ( V_31 -> V_22 , V_180 ,
V_181 . V_182 ( V_22 , V_213 ) ) ;
}
V_244 . V_247 = V_213 * V_22 -> V_74 . V_178 ;
F_158 ( V_31 , & V_244 , false ) ;
return 0 ;
}
static unsigned int F_159 ( struct V_30 * V_31 ,
unsigned int V_241 )
{
struct V_32 * V_22 = V_35 [ V_31 -> V_22 ] ;
int V_213 ;
F_33 () ;
V_213 = F_156 ( V_241 , V_22 -> V_74 . V_178 ) ;
V_213 = F_124 ( V_22 , V_213 ) ;
F_125 ( V_22 , V_213 ) ;
return V_213 * V_22 -> V_74 . V_178 ;
}
static int F_160 ( struct V_30 * V_31 )
{
int V_6 = F_149 ( V_31 ) ;
if ( V_6 )
return V_6 ;
V_31 -> V_49 . V_238 = V_250 ;
V_31 -> V_246 = V_31 -> V_49 . V_235 ;
return 0 ;
}
static void F_161 ( void )
{
unsigned int V_22 ;
F_162 () ;
F_32 (cpu) {
if ( V_35 [ V_22 ] ) {
if ( V_251 == & V_252 )
F_137 ( V_22 ) ;
F_163 ( V_35 [ V_22 ] ) ;
V_35 [ V_22 ] = NULL ;
}
}
F_164 () ;
}
static int F_165 ( void )
{
int V_6 ;
F_10 ( & V_47 ) ;
V_6 = F_166 ( V_251 ) ;
if ( V_6 ) {
F_161 () ;
return V_6 ;
}
F_43 ( & V_91 ) ;
V_135 = true ;
F_45 ( & V_91 ) ;
if ( V_251 == & V_252 && ! V_34 &&
V_181 . V_214 != F_122 )
F_65 () ;
return 0 ;
}
static int F_167 ( void )
{
if ( V_34 )
return - V_253 ;
if ( V_251 == & V_252 && ! V_34 &&
V_181 . V_214 != F_122 )
F_70 () ;
F_43 ( & V_91 ) ;
V_135 = false ;
F_45 ( & V_91 ) ;
F_168 ( V_251 ) ;
F_161 () ;
return 0 ;
}
static T_6 F_73 ( char * V_94 )
{
if ( ! V_135 )
return sprintf ( V_94 , L_21 ) ;
return sprintf ( V_94 , L_7 , V_251 == & V_252 ?
L_22 : L_23 ) ;
}
static int F_75 ( const char * V_94 , T_7 V_223 )
{
int V_6 ;
if ( V_223 == 3 && ! strncmp ( V_94 , L_24 , V_223 ) )
return V_135 ?
F_167 () : - V_88 ;
if ( V_223 == 6 && ! strncmp ( V_94 , L_22 , V_223 ) ) {
if ( V_135 ) {
if ( V_251 == & V_252 )
return 0 ;
V_6 = F_167 () ;
if ( V_6 )
return V_6 ;
}
V_251 = & V_252 ;
return F_165 () ;
}
if ( V_223 == 7 && ! strncmp ( V_94 , L_23 , V_223 ) ) {
if ( V_135 ) {
if ( V_251 != & V_252 )
return 0 ;
V_6 = F_167 () ;
if ( V_6 )
return V_6 ;
}
V_251 = & V_254 ;
return F_165 () ;
}
return - V_88 ;
}
static int T_9 F_169 ( void )
{
if ( ! V_181 . V_184 () ||
! V_181 . V_183 () ||
! V_181 . V_187 () )
return - V_233 ;
return 0 ;
}
static void T_9 F_170 ( struct V_255 * V_31 )
{
V_67 . V_117 = V_31 -> V_117 ;
V_67 . V_116 = V_67 . V_117 * V_118 ;
V_67 . V_68 = V_31 -> V_68 ;
V_67 . V_70 = V_31 -> V_70 ;
V_67 . V_69 = V_31 -> V_69 ;
V_67 . V_56 = V_31 -> V_56 ;
V_67 . V_54 = V_31 -> V_54 ;
}
static void F_171 ( void )
{
if ( V_15 . V_16 == V_256 )
V_181 . V_214 =
F_122 ;
}
static void F_171 ( void )
{
}
static void T_9 F_172 ( struct V_181 * V_257 )
{
V_181 . V_184 = V_257 -> V_184 ;
V_181 . V_186 = V_257 -> V_186 ;
V_181 . V_183 = V_257 -> V_183 ;
V_181 . V_187 = V_257 -> V_187 ;
V_181 . V_188 = V_257 -> V_188 ;
V_181 . V_182 = V_257 -> V_182 ;
V_181 . V_190 = V_257 -> V_190 ;
V_181 . V_214 = V_257 -> V_214 ;
F_171 () ;
}
static bool T_9 F_173 ( void )
{
int V_33 ;
F_61 (i) {
T_10 V_258 ;
union V_259 * V_260 ;
struct V_261 V_262 = { V_263 , NULL } ;
struct V_264 * V_265 = F_174 ( V_266 , V_33 ) ;
if ( ! V_265 )
continue;
V_258 = F_175 ( V_265 -> V_267 , L_25 , NULL , & V_262 ) ;
if ( F_176 ( V_258 ) )
continue;
V_260 = V_262 . V_268 ;
if ( V_260 && V_260 -> type == V_269 ) {
F_163 ( V_260 ) ;
return false ;
}
F_163 ( V_260 ) ;
}
return true ;
}
static bool T_9 F_177 ( void )
{
int V_33 ;
F_61 (i) {
struct V_264 * V_265 = F_174 ( V_266 , V_33 ) ;
if ( ! V_265 )
continue;
if ( F_178 ( V_265 -> V_267 , L_26 ) )
return true ;
}
return false ;
}
static bool T_9 F_179 ( void )
{
struct V_270 V_271 ;
struct V_272 * V_273 ;
const struct V_226 * V_227 ;
T_3 V_274 ;
V_227 = F_133 ( V_275 ) ;
if ( V_227 ) {
F_34 ( V_276 , V_274 ) ;
if ( V_274 & ( 1 << 8 ) )
return true ;
}
if ( V_277 ||
F_176 ( F_180 ( V_278 , 0 , & V_271 ) ) )
return false ;
for ( V_273 = V_279 ; V_273 -> V_280 ; V_273 ++ ) {
if ( ! strncmp ( V_271 . V_281 , V_273 -> V_281 , V_282 ) &&
! strncmp ( V_271 . V_283 , V_273 -> V_283 ,
V_284 ) )
switch ( V_273 -> V_285 ) {
case V_286 :
return F_173 () ;
case V_287 :
return F_177 () &&
( ! V_288 ) ;
}
}
return false ;
}
static void F_181 ( void )
{
if ( V_19 )
F_182 () ;
}
static inline bool F_179 ( void ) { return false ; }
static inline bool F_177 ( void ) { return false ; }
static inline void F_181 ( void ) {}
static int T_9 F_183 ( void )
{
const struct V_226 * V_227 ;
struct V_289 * V_290 ;
int V_144 = 0 ;
if ( V_291 )
return - V_233 ;
if ( F_133 ( V_292 ) && ! V_293 ) {
F_172 ( & V_294 . V_257 ) ;
V_34 ++ ;
V_252 . V_127 = V_295 ;
goto V_296;
}
V_227 = F_133 ( V_297 ) ;
if ( ! V_227 )
return - V_233 ;
V_290 = (struct V_289 * ) V_227 -> V_298 ;
F_170 ( & V_290 -> V_299 ) ;
F_172 ( & V_290 -> V_257 ) ;
if ( F_169 () )
return - V_233 ;
V_296:
if ( F_179 () )
return - V_233 ;
if ( ! V_34 && V_300 )
return - V_301 ;
F_92 ( L_27 ) ;
V_35 = F_184 ( sizeof( void * ) * F_185 () ) ;
if ( ! V_35 )
return - V_225 ;
F_181 () ;
F_84 () ;
F_43 ( & V_128 ) ;
V_144 = F_165 () ;
F_45 ( & V_128 ) ;
if ( V_144 )
return V_144 ;
if ( V_34 )
F_92 ( L_28 ) ;
return 0 ;
}
static int T_9 F_186 ( char * V_302 )
{
if ( ! V_302 )
return - V_88 ;
if ( ! strcmp ( V_302 , L_29 ) ) {
V_291 = 1 ;
} else if ( ! strcmp ( V_302 , L_23 ) ) {
F_92 ( L_30 ) ;
V_251 = & V_254 ;
V_293 = 1 ;
}
if ( ! strcmp ( V_302 , L_31 ) ) {
F_92 ( L_32 ) ;
V_293 = 1 ;
}
if ( ! strcmp ( V_302 , L_33 ) )
V_288 = 1 ;
if ( ! strcmp ( V_302 , L_34 ) )
V_300 = 1 ;
if ( ! strcmp ( V_302 , L_35 ) )
V_104 = true ;
#ifdef F_187
if ( ! strcmp ( V_302 , L_36 ) )
V_19 = true ;
#endif
return 0 ;
}
