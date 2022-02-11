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
static inline T_1 F_6 ( int V_7 )
{
return F_2 ( V_7 , 100 ) ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_8 ;
}
static inline T_3 F_8 ( T_3 V_1 , T_3 V_2 )
{
return F_9 ( V_1 << V_8 , V_2 ) ;
}
static inline T_1 F_10 ( int V_7 )
{
return F_8 ( V_7 , 100 ) ;
}
static bool F_11 ( void )
{
if ( V_9 . V_10 == V_11 ||
V_9 . V_10 == V_12 )
return true ;
return V_13 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 () ;
}
static void F_14 ( int V_16 )
{
struct V_17 V_18 ;
static T_4 V_19 = 0 , V_20 = V_21 ;
int V_6 ;
V_6 = F_15 ( V_16 , & V_18 ) ;
if ( V_6 )
return;
F_16 ( V_18 . V_22 , V_16 ) ;
if ( V_19 <= V_20 ) {
if ( V_18 . V_22 > V_19 )
V_19 = V_18 . V_22 ;
if ( V_18 . V_22 < V_20 )
V_20 = V_18 . V_22 ;
if ( V_19 > V_20 ) {
F_17 ( & V_23 ) ;
}
}
}
static void F_14 ( int V_16 )
{
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_6 ;
int V_27 ;
if ( V_28 ) {
F_14 ( V_25 -> V_16 ) ;
return;
}
if ( ! F_11 () )
return;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_6 = F_19 ( & V_16 -> V_30 ,
V_25 -> V_16 ) ;
if ( V_6 )
return;
if ( V_16 -> V_30 . V_31 . V_32 !=
V_33 )
goto V_34;
if ( V_16 -> V_30 . V_35 < 2 )
goto V_34;
F_20 ( L_1 , V_25 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_16 -> V_30 . V_35 ; V_27 ++ ) {
F_20 ( L_2 ,
( V_27 == V_16 -> V_30 . V_36 ? '*' : ' ' ) , V_27 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_38 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_39 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_40 ) ;
}
if ( ! V_41 . V_42 )
V_16 -> V_30 . V_37 [ 0 ] . V_38 =
V_25 -> V_43 . V_44 / 1000 ;
V_16 -> V_45 = true ;
F_20 ( L_3 ) ;
return;
V_34:
V_16 -> V_45 = false ;
F_21 ( V_25 -> V_16 ) ;
}
static void F_22 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_16 -> V_45 )
return;
F_21 ( V_25 -> V_16 ) ;
}
static inline void F_18 ( struct V_24 * V_25 )
{
}
static inline void F_22 ( struct V_24 * V_25 )
{
}
static signed int F_23 ( struct V_46 * V_47 , T_1 V_48 )
{
signed int V_49 ;
T_1 V_50 , V_51 , V_52 ;
T_1 V_53 ;
V_52 = V_47 -> V_54 - V_48 ;
if ( abs ( V_52 ) <= V_47 -> V_55 )
return 0 ;
V_50 = F_1 ( V_47 -> V_56 , V_52 ) ;
V_47 -> V_57 += V_52 ;
V_53 = F_24 ( 30 ) ;
if ( V_47 -> V_57 > V_53 )
V_47 -> V_57 = V_53 ;
if ( V_47 -> V_57 < - V_53 )
V_47 -> V_57 = - V_53 ;
V_51 = F_1 ( V_47 -> V_58 , V_52 - V_47 -> V_59 ) ;
V_47 -> V_59 = V_52 ;
V_49 = V_50 + F_1 ( V_47 -> V_57 , V_47 -> V_60 ) + V_51 ;
V_49 = V_49 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_49 ) ;
}
static inline void F_25 ( struct V_26 * V_16 )
{
struct V_46 * V_47 = & V_16 -> V_47 ;
V_47 -> V_56 = F_6 ( V_61 . V_62 ) ;
V_47 -> V_58 = F_6 ( V_61 . V_63 ) ;
V_47 -> V_60 = F_6 ( V_61 . V_64 ) ;
V_47 -> V_54 = F_24 ( V_61 . V_54 ) ;
V_47 -> V_59 = V_47 -> V_54 - F_24 ( 100 ) ;
V_47 -> V_55 = F_24 ( V_61 . V_55 ) ;
V_47 -> V_57 = 0 ;
}
static inline void F_26 ( void )
{
T_3 V_65 ;
struct V_26 * V_16 ;
V_16 = V_29 [ 0 ] ;
F_27 ( V_66 , V_65 ) ;
V_41 . V_42 =
( V_65 & V_67 ||
V_16 -> V_68 . V_69 == V_16 -> V_68 . V_70 ) ;
}
static int F_28 ( void )
{
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_70 = V_16 -> V_68 . V_70 ;
return V_70 ?
F_29 ( V_16 -> V_68 . V_71 * 100 , V_70 ) : 0 ;
}
static T_5 F_30 ( struct V_26 * V_72 )
{
T_3 V_73 ;
int V_6 ;
if ( ! F_31 ( V_74 ) )
return - V_75 ;
V_6 = F_32 ( V_72 -> V_16 , V_76 , & V_73 ) ;
if ( V_6 )
return ( T_5 ) V_6 ;
return ( T_5 ) ( V_73 & 0x0f ) ;
}
static T_5 F_33 ( struct V_26 * V_72 , T_3 V_77 )
{
T_5 V_78 ;
if ( F_31 ( V_79 ) ) {
if ( ! V_77 ) {
V_78 = F_32 ( V_72 -> V_16 , V_80 ,
& V_77 ) ;
if ( V_78 )
return V_78 ;
}
V_78 = ( V_77 >> 24 ) & 0xff ;
} else {
V_78 = F_30 ( V_72 ) ;
}
return V_78 ;
}
static int F_34 ( int V_16 , T_5 V_81 )
{
T_3 V_73 ;
int V_6 ;
if ( ! F_31 ( V_74 ) )
return - V_75 ;
V_6 = F_32 ( V_16 , V_76 , & V_73 ) ;
if ( V_6 )
return V_6 ;
V_73 = ( V_73 & ~ 0x0f ) | V_81 ;
F_35 ( V_16 , V_76 , V_73 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_72 )
{
T_5 V_78 ;
int V_82 = - V_83 ;
V_78 = F_33 ( V_72 , 0 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( F_31 ( V_79 ) ) {
V_82 = ( V_78 >> 6 ) + 1 ;
} else if ( F_31 ( V_74 ) ) {
V_82 = ( V_78 >> 2 ) + 1 ;
}
return V_82 ;
}
static int F_37 ( struct V_26 * V_72 ,
int V_84 )
{
int V_78 = - V_83 ;
int V_6 ;
if ( ! V_84 )
V_78 = V_72 -> V_85 ;
F_38 ( & V_86 ) ;
if ( F_31 ( V_79 ) ) {
T_3 V_87 ;
V_6 = F_32 ( V_72 -> V_16 , V_80 , & V_87 ) ;
if ( V_6 )
goto V_88;
V_87 &= ~ F_39 ( 31 , 24 ) ;
if ( V_78 == - V_83 )
V_78 = ( V_84 - 1 ) << 6 ;
V_87 |= ( T_3 ) V_78 << 24 ;
V_6 = F_35 ( V_72 -> V_16 , V_80 , V_87 ) ;
} else {
if ( V_78 == - V_83 )
V_78 = ( V_84 - 1 ) << 2 ;
V_6 = F_34 ( V_72 -> V_16 , V_78 ) ;
}
V_88:
F_40 ( & V_86 ) ;
return V_6 ;
}
static T_6 F_41 (
struct V_24 * V_25 , char * V_89 )
{
int V_27 = 0 ;
int V_6 = 0 ;
while ( V_90 [ V_27 ] != NULL )
V_6 += sprintf ( & V_89 [ V_6 ] , L_4 , V_90 [ V_27 ++ ] ) ;
V_6 += sprintf ( & V_89 [ V_6 ] , L_5 ) ;
return V_6 ;
}
static T_6 F_42 (
struct V_24 * V_25 , const char * V_89 , T_7 V_91 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
char V_92 [ 21 ] ;
int V_6 , V_27 = 0 ;
V_6 = sscanf ( V_89 , L_6 , V_92 ) ;
if ( V_6 != 1 )
return - V_83 ;
while ( V_90 [ V_27 ] != NULL ) {
if ( ! strcmp ( V_92 , V_90 [ V_27 ] ) ) {
F_37 ( V_72 , V_27 ) ;
return V_91 ;
}
++ V_27 ;
}
return - V_83 ;
}
static T_6 F_43 (
struct V_24 * V_25 , char * V_89 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
int V_93 ;
V_93 = F_36 ( V_72 ) ;
if ( V_93 < 0 )
return V_93 ;
return sprintf ( V_89 , L_7 , V_90 [ V_93 ] ) ;
}
static void F_44 ( unsigned int V_16 )
{
struct V_26 * V_72 = V_29 [ V_16 ] ;
int V_94 , V_95 , V_96 , V_97 ;
T_3 V_87 , V_98 ;
T_5 V_78 ;
F_32 ( V_16 , V_99 , & V_98 ) ;
V_95 = F_45 ( V_98 ) ;
if ( V_41 . V_100 )
V_97 = F_46 ( V_98 ) ;
else
V_97 = F_47 ( V_98 ) ;
V_96 = F_48 ( V_97 * V_72 -> V_101 ) ;
if ( V_72 -> V_25 == V_102 )
V_94 = V_96 ;
else
V_94 = F_48 ( V_97 * V_72 -> V_103 ) ;
F_32 ( V_16 , V_80 , & V_87 ) ;
V_87 &= ~ F_49 ( ~ 0L ) ;
V_87 |= F_49 ( V_94 ) ;
V_87 &= ~ F_50 ( ~ 0L ) ;
V_87 |= F_50 ( V_96 ) ;
if ( V_72 -> V_104 == V_72 -> V_25 )
goto V_105;
V_72 -> V_104 = V_72 -> V_25 ;
if ( V_72 -> V_106 >= 0 ) {
V_78 = V_72 -> V_106 ;
V_72 -> V_106 = - V_83 ;
goto V_107;
}
if ( V_72 -> V_25 == V_102 ) {
V_78 = F_33 ( V_72 , V_87 ) ;
V_72 -> V_108 = V_78 ;
if ( V_78 < 0 )
goto V_105;
V_78 = 0 ;
} else {
if ( V_72 -> V_108 < 0 )
goto V_105;
V_78 = F_33 ( V_72 , V_87 ) ;
if ( V_78 )
goto V_105;
V_78 = V_72 -> V_108 ;
}
V_107:
if ( F_31 ( V_79 ) ) {
V_87 &= ~ F_39 ( 31 , 24 ) ;
V_87 |= ( T_3 ) V_78 << 24 ;
} else {
F_34 ( V_16 , V_78 ) ;
}
V_105:
F_35 ( V_16 , V_80 , V_87 ) ;
}
static int F_51 ( struct V_24 * V_25 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_28 )
return 0 ;
V_72 -> V_106 = F_33 ( V_72 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 )
{
if ( ! V_28 )
return 0 ;
F_38 ( & V_86 ) ;
V_29 [ V_25 -> V_16 ] -> V_104 = 0 ;
F_44 ( V_25 -> V_16 ) ;
F_40 ( & V_86 ) ;
return 0 ;
}
static void F_53 ( void )
{
int V_16 ;
F_54 (cpu)
F_55 ( V_16 ) ;
}
static int F_56 ( void * V_109 , T_3 V_110 )
{
unsigned int V_16 ;
* ( T_4 * ) V_109 = V_110 ;
V_61 . V_111 = V_61 . V_112 * V_113 ;
F_54 (cpu)
if ( V_29 [ V_16 ] )
F_25 ( V_29 [ V_16 ] ) ;
return 0 ;
}
static int F_57 ( void * V_109 , T_3 * V_110 )
{
* V_110 = * ( T_4 * ) V_109 ;
return 0 ;
}
static void F_58 ( void )
{
int V_27 ;
V_114 = F_59 ( L_8 , NULL ) ;
if ( F_60 ( V_114 ) )
return;
for ( V_27 = 0 ; V_115 [ V_27 ] . V_116 ; V_27 ++ ) {
struct V_117 * V_117 ;
V_117 = F_61 ( V_115 [ V_27 ] . V_116 , 0660 ,
V_114 , V_115 [ V_27 ] . V_87 ,
& V_118 ) ;
if ( ! F_62 ( V_117 ) )
V_115 [ V_27 ] . V_117 = V_117 ;
}
}
static void F_63 ( void )
{
int V_27 ;
if ( F_60 ( V_114 ) )
return;
for ( V_27 = 0 ; V_115 [ V_27 ] . V_116 ; V_27 ++ ) {
F_64 ( V_115 [ V_27 ] . V_117 ) ;
V_115 [ V_27 ] . V_117 = NULL ;
}
F_64 ( V_114 ) ;
V_114 = NULL ;
}
static T_6 F_65 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_89 )
{
T_6 V_6 ;
F_38 ( & V_123 ) ;
V_6 = F_66 ( V_89 ) ;
F_40 ( & V_123 ) ;
return V_6 ;
}
static T_6 F_67 ( struct V_119 * V_124 , struct V_121 * V_125 ,
const char * V_89 , T_7 V_91 )
{
char * V_126 = memchr ( V_89 , '\n' , V_91 ) ;
int V_6 ;
F_38 ( & V_123 ) ;
V_6 = F_68 ( V_89 , V_126 ? V_126 - V_89 : V_91 ) ;
F_40 ( & V_123 ) ;
return V_6 < 0 ? V_6 : V_91 ;
}
static T_6 F_69 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_89 )
{
struct V_26 * V_16 ;
int V_127 , V_100 , V_128 ;
T_8 V_129 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
V_16 = V_29 [ 0 ] ;
V_127 = V_16 -> V_68 . V_70 - V_16 -> V_68 . V_71 + 1 ;
V_100 = V_16 -> V_68 . V_69 - V_16 -> V_68 . V_71 + 1 ;
V_129 = F_2 ( V_100 , V_127 ) ;
V_128 = 100 - F_5 ( F_1 ( V_129 , F_24 ( 100 ) ) ) ;
F_40 ( & V_123 ) ;
return sprintf ( V_89 , L_9 , V_128 ) ;
}
static T_6 F_70 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_89 )
{
struct V_26 * V_16 ;
int V_127 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
V_16 = V_29 [ 0 ] ;
V_127 = V_16 -> V_68 . V_70 - V_16 -> V_68 . V_71 + 1 ;
F_40 ( & V_123 ) ;
return sprintf ( V_89 , L_9 , V_127 ) ;
}
static T_6 F_71 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_89 )
{
T_6 V_6 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
F_26 () ;
if ( V_41 . V_42 )
V_6 = sprintf ( V_89 , L_9 , V_41 . V_42 ) ;
else
V_6 = sprintf ( V_89 , L_9 , V_41 . V_100 ) ;
F_40 ( & V_123 ) ;
return V_6 ;
}
static T_6 F_72 ( struct V_119 * V_124 , struct V_121 * V_125 ,
const char * V_89 , T_7 V_91 )
{
unsigned int V_132 ;
int V_6 ;
V_6 = sscanf ( V_89 , L_10 , & V_132 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
F_38 ( & V_86 ) ;
F_26 () ;
if ( V_41 . V_42 ) {
F_73 ( L_11 ) ;
F_40 ( & V_86 ) ;
F_40 ( & V_123 ) ;
return - V_133 ;
}
V_41 . V_100 = F_74 ( int , V_132 , 0 , 1 ) ;
if ( V_41 . V_100 ) {
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_134 = V_16 -> V_68 . V_69 * 100 / V_16 -> V_68 . V_70 ;
if ( V_41 . V_135 > V_134 )
V_41 . V_135 = V_134 ;
}
F_40 ( & V_86 ) ;
F_53 () ;
F_40 ( & V_123 ) ;
return V_91 ;
}
static T_6 F_75 ( struct V_119 * V_124 , struct V_121 * V_125 ,
const char * V_89 , T_7 V_91 )
{
unsigned int V_132 ;
int V_6 ;
V_6 = sscanf ( V_89 , L_10 , & V_132 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
F_38 ( & V_86 ) ;
V_41 . V_136 = F_74 ( int , V_132 , V_41 . V_135 , 100 ) ;
F_40 ( & V_86 ) ;
F_53 () ;
F_40 ( & V_123 ) ;
return V_91 ;
}
static T_6 F_76 ( struct V_119 * V_124 , struct V_121 * V_125 ,
const char * V_89 , T_7 V_91 )
{
unsigned int V_132 ;
int V_6 ;
V_6 = sscanf ( V_89 , L_10 , & V_132 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_38 ( & V_123 ) ;
if ( ! V_130 ) {
F_40 ( & V_123 ) ;
return - V_131 ;
}
F_38 ( & V_86 ) ;
V_41 . V_135 = F_74 ( int , V_132 ,
F_28 () , V_41 . V_136 ) ;
F_40 ( & V_86 ) ;
F_53 () ;
F_40 ( & V_123 ) ;
return V_91 ;
}
static void T_9 F_77 ( void )
{
struct V_119 * V_137 ;
int V_138 ;
V_137 = F_78 ( L_12 ,
& V_139 . V_140 -> V_120 ) ;
if ( F_79 ( ! V_137 ) )
return;
V_138 = F_80 ( V_137 , & V_141 ) ;
if ( F_79 ( V_138 ) )
return;
if ( V_142 )
return;
V_138 = F_81 ( V_137 , & V_136 . V_122 ) ;
F_79 ( V_138 ) ;
V_138 = F_81 ( V_137 , & V_135 . V_122 ) ;
F_79 ( V_138 ) ;
}
static void F_82 ( struct V_26 * V_26 )
{
if ( F_31 ( V_143 ) )
F_35 ( V_26 -> V_16 , V_144 , 0x00 ) ;
F_35 ( V_26 -> V_16 , V_145 , 0x1 ) ;
V_26 -> V_104 = 0 ;
if ( V_26 -> V_85 == - V_83 )
V_26 -> V_85 = F_33 ( V_26 , 0 ) ;
}
static void F_83 ( int V_16 )
{
T_3 V_146 ;
int V_6 ;
V_6 = F_32 ( V_16 , V_147 , & V_146 ) ;
if ( V_6 )
return;
if ( ! ( V_146 & F_84 ( V_148 ) ) ) {
F_85 ( L_13 ) ;
V_146 |= F_84 ( V_148 ) ;
F_35 ( V_16 , V_147 , V_146 ) ;
}
}
static int F_86 ( void )
{
T_3 V_87 ;
F_27 ( V_149 , V_87 ) ;
return ( V_87 >> 8 ) & 0x7F ;
}
static int F_87 ( void )
{
T_3 V_87 ;
F_27 ( V_149 , V_87 ) ;
return ( V_87 >> 16 ) & 0x7F ;
}
static int F_88 ( void )
{
T_3 V_87 ;
F_27 ( V_150 , V_87 ) ;
return V_87 & 0x7F ;
}
static T_3 F_89 ( struct V_26 * V_26 , int V_68 )
{
T_3 V_110 ;
T_1 V_151 ;
T_4 V_152 ;
V_110 = ( T_3 ) V_68 << 8 ;
if ( V_41 . V_100 && ! V_41 . V_42 )
V_110 |= ( T_3 ) 1 << 32 ;
V_151 = V_26 -> V_152 . V_94 + F_1 (
F_24 ( V_68 - V_26 -> V_68 . V_71 ) ,
V_26 -> V_152 . V_153 ) ;
V_151 = F_74 ( T_1 , V_151 , V_26 -> V_152 . V_94 , V_26 -> V_152 . V_96 ) ;
V_152 = F_4 ( V_151 ) ;
if ( V_68 > V_26 -> V_68 . V_69 )
V_152 = V_26 -> V_152 . V_154 ;
return V_110 | V_152 ;
}
static int F_90 ( void )
{
T_3 V_87 ;
int V_27 ;
static int V_155 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_27 ( V_156 , V_87 ) ;
V_27 = V_87 & 0x7 ;
F_79 ( V_27 > 4 ) ;
return V_155 [ V_27 ] ;
}
static int F_91 ( void )
{
T_3 V_87 ;
int V_27 ;
static int V_157 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_27 ( V_156 , V_87 ) ;
V_27 = V_87 & 0xF ;
F_79 ( V_27 > 8 ) ;
return V_157 [ V_27 ] ;
}
static void F_92 ( struct V_26 * V_26 )
{
T_3 V_87 ;
F_27 ( V_158 , V_87 ) ;
V_26 -> V_152 . V_94 = F_24 ( ( V_87 >> 8 ) & 0x7f ) ;
V_26 -> V_152 . V_96 = F_24 ( ( V_87 >> 16 ) & 0x7f ) ;
V_26 -> V_152 . V_153 = F_2 (
V_26 -> V_152 . V_96 - V_26 -> V_152 . V_94 ,
F_24 ( V_26 -> V_68 . V_69 -
V_26 -> V_68 . V_71 ) ) ;
F_27 ( V_159 , V_87 ) ;
V_26 -> V_152 . V_154 = V_87 & 0x7f ;
}
static int F_93 ( void )
{
T_3 V_87 ;
F_27 ( V_160 , V_87 ) ;
return ( V_87 >> 40 ) & 0xFF ;
}
static int F_94 ( void )
{
T_3 V_87 ;
F_27 ( V_160 , V_87 ) ;
return ( V_87 >> 8 ) & 0xFF ;
}
static int F_95 ( T_3 V_161 )
{
if ( V_161 & 0x600000000 ) {
T_3 V_162 ;
T_3 V_163 ;
int V_164 ;
int V_34 ;
V_34 = F_96 ( V_165 , & V_162 ) ;
if ( V_34 )
return V_34 ;
V_164 = V_166 + ( V_162 & 0x03 ) ;
V_34 = F_96 ( V_164 , & V_163 ) ;
if ( V_34 )
return V_34 ;
if ( V_162 & 0x03 )
V_163 >>= 16 ;
V_163 &= 0xff ;
F_20 ( L_14 , ( int ) V_163 ) ;
return ( int ) V_163 ;
}
return - V_75 ;
}
static int F_97 ( void )
{
T_3 V_167 ;
T_3 V_161 ;
int V_69 ;
int V_163 ;
int V_34 ;
F_27 ( V_160 , V_161 ) ;
V_69 = ( V_161 >> 8 ) & 0xFF ;
V_163 = F_95 ( V_161 ) ;
if ( V_163 <= 0 )
return V_69 ;
if ( V_28 ) {
return V_163 ;
}
V_34 = F_96 ( V_168 , & V_167 ) ;
if ( ! V_34 ) {
int V_169 ;
V_169 = V_167 & 0xff ;
if ( V_163 - 1 == V_169 ) {
V_69 = V_169 ;
F_20 ( L_15 , V_69 ) ;
}
}
return V_69 ;
}
static int F_98 ( void )
{
T_3 V_87 ;
int V_170 , V_6 ;
F_27 ( V_171 , V_87 ) ;
V_170 = F_97 () ;
V_6 = ( V_87 ) & 255 ;
if ( V_6 <= V_170 )
V_6 = V_170 ;
return V_6 ;
}
static inline int F_99 ( void )
{
return 100000 ;
}
static T_3 F_100 ( struct V_26 * V_26 , int V_68 )
{
T_3 V_110 ;
V_110 = ( T_3 ) V_68 << 8 ;
if ( V_41 . V_100 && ! V_41 . V_42 )
V_110 |= ( T_3 ) 1 << 32 ;
return V_110 ;
}
static int F_101 ( void )
{
T_3 V_87 ;
int V_170 , V_6 ;
F_27 ( V_171 , V_87 ) ;
V_170 = F_97 () ;
V_6 = ( ( ( V_87 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_170 )
V_6 = V_170 ;
return V_6 ;
}
static int F_102 ( struct V_26 * V_16 )
{
return V_41 . V_100 || V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
}
static void F_103 ( struct V_26 * V_16 , int V_68 )
{
F_104 ( V_68 * V_16 -> V_68 . V_172 , V_16 -> V_16 ) ;
V_16 -> V_68 . V_173 = V_68 ;
F_35 ( V_16 -> V_16 , V_174 ,
V_175 . V_176 ( V_16 , V_68 ) ) ;
}
static void F_105 ( struct V_26 * V_16 )
{
F_103 ( V_16 , V_16 -> V_68 . V_71 ) ;
}
static void F_106 ( struct V_26 * V_16 )
{
int V_68 ;
F_26 () ;
V_68 = F_102 ( V_16 ) ;
V_68 = V_96 ( V_16 -> V_68 . V_71 ,
F_48 ( V_68 * V_16 -> V_101 ) ) ;
F_103 ( V_16 , V_68 ) ;
}
static void F_107 ( struct V_26 * V_16 )
{
V_16 -> V_68 . V_71 = V_175 . V_177 () ;
V_16 -> V_68 . V_69 = V_175 . V_178 () ;
V_16 -> V_68 . V_179 = V_175 . V_180 () ;
V_16 -> V_68 . V_70 = V_175 . V_181 () ;
V_16 -> V_68 . V_172 = V_175 . V_182 () ;
V_16 -> V_68 . V_44 = V_16 -> V_68 . V_69 * V_16 -> V_68 . V_172 ;
V_16 -> V_68 . V_183 = V_16 -> V_68 . V_70 * V_16 -> V_68 . V_172 ;
if ( V_175 . V_184 )
V_175 . V_184 ( V_16 ) ;
F_105 ( V_16 ) ;
}
static inline void F_108 ( struct V_26 * V_16 )
{
struct V_185 * V_185 = & V_16 -> V_185 ;
V_185 -> V_186 = F_8 ( V_185 -> V_187 , V_185 -> V_188 ) ;
}
static inline bool F_109 ( struct V_26 * V_16 , T_3 time )
{
T_3 V_187 , V_188 ;
unsigned long V_189 ;
T_3 V_190 ;
F_110 ( V_189 ) ;
F_27 ( V_191 , V_187 ) ;
F_27 ( V_192 , V_188 ) ;
V_190 = F_111 () ;
if ( V_16 -> V_193 == V_188 || V_16 -> V_194 == V_190 ) {
F_112 ( V_189 ) ;
return false ;
}
F_112 ( V_189 ) ;
V_16 -> V_195 = V_16 -> V_185 . time ;
V_16 -> V_185 . time = time ;
V_16 -> V_185 . V_187 = V_187 ;
V_16 -> V_185 . V_188 = V_188 ;
V_16 -> V_185 . V_190 = V_190 ;
V_16 -> V_185 . V_187 -= V_16 -> V_196 ;
V_16 -> V_185 . V_188 -= V_16 -> V_193 ;
V_16 -> V_185 . V_190 -= V_16 -> V_194 ;
V_16 -> V_196 = V_187 ;
V_16 -> V_193 = V_188 ;
V_16 -> V_194 = V_190 ;
if ( V_16 -> V_195 ) {
F_108 ( V_16 ) ;
return true ;
}
return false ;
}
static inline T_1 F_113 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_185 . V_186 ,
V_16 -> V_68 . V_179 * V_16 -> V_68 . V_172 ) ;
}
static inline T_1 F_114 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_68 . V_179 ,
V_16 -> V_185 . V_186 ) ;
}
static inline T_1 F_115 ( struct V_26 * V_16 )
{
struct V_185 * V_185 = & V_16 -> V_185 ;
T_1 V_197 , V_198 ;
int V_199 , V_200 ;
if ( V_16 -> V_25 == V_102 )
return V_16 -> V_68 . V_70 ;
V_197 = F_2 ( V_185 -> V_188 , V_185 -> V_190 ) ;
V_198 = V_16 -> V_201 ;
V_16 -> V_201 >>= 1 ;
if ( V_197 < V_198 )
V_197 = V_198 ;
V_185 -> V_202 = V_197 * 100 ;
V_199 = V_41 . V_100 || V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
V_199 += V_199 >> 2 ;
V_199 = F_1 ( V_199 , V_197 ) ;
if ( V_199 < V_16 -> V_68 . V_71 )
V_199 = V_16 -> V_68 . V_71 ;
V_200 = F_114 ( V_16 ) ;
if ( V_200 > V_199 )
V_199 += ( V_200 - V_199 ) >> 1 ;
return V_199 ;
}
static inline T_1 F_116 ( struct V_26 * V_16 )
{
T_1 V_203 , V_69 , V_173 , V_204 ;
T_3 V_205 ;
if ( V_16 -> V_25 == V_102 )
return V_16 -> V_68 . V_70 ;
V_69 = V_16 -> V_68 . V_179 ;
V_173 = V_16 -> V_68 . V_173 ;
V_203 = F_7 ( V_16 -> V_185 . V_186 ,
F_2 ( 100 * V_69 , V_173 ) ) ;
V_205 = V_16 -> V_185 . time - V_16 -> V_195 ;
if ( ( T_2 ) V_205 > V_61 . V_111 * 3 ) {
V_204 = F_2 ( V_61 . V_111 , V_205 ) ;
V_203 = F_1 ( V_203 , V_204 ) ;
} else {
V_204 = F_2 ( 100 * V_16 -> V_185 . V_188 , V_16 -> V_185 . V_190 ) ;
if ( V_204 < F_24 ( 1 ) )
V_203 = 0 ;
}
V_16 -> V_185 . V_202 = V_203 ;
return V_16 -> V_68 . V_173 - F_23 ( & V_16 -> V_47 , V_203 ) ;
}
static int F_117 ( struct V_26 * V_16 , int V_68 )
{
int V_69 = F_102 ( V_16 ) ;
int V_71 ;
V_71 = V_96 ( V_16 -> V_68 . V_71 ,
F_48 ( V_69 * V_16 -> V_103 ) ) ;
V_69 = V_96 ( V_71 , F_48 ( V_69 * V_16 -> V_101 ) ) ;
return F_74 ( int , V_68 , V_71 , V_69 ) ;
}
static void F_118 ( struct V_26 * V_16 , int V_68 )
{
if ( V_68 == V_16 -> V_68 . V_173 )
return;
V_16 -> V_68 . V_173 = V_68 ;
F_119 ( V_174 , V_175 . V_176 ( V_16 , V_68 ) ) ;
}
static void F_120 ( struct V_26 * V_16 , int V_206 )
{
int V_207 = V_16 -> V_68 . V_173 ;
struct V_185 * V_185 ;
F_26 () ;
V_206 = F_117 ( V_16 , V_206 ) ;
F_104 ( V_206 * V_16 -> V_68 . V_172 , V_16 -> V_16 ) ;
F_118 ( V_16 , V_206 ) ;
V_185 = & V_16 -> V_185 ;
F_121 ( F_7 ( 100 , V_185 -> V_186 ) ,
F_5 ( V_185 -> V_202 ) ,
V_207 ,
V_16 -> V_68 . V_173 ,
V_185 -> V_188 ,
V_185 -> V_187 ,
V_185 -> V_190 ,
F_113 ( V_16 ) ,
F_5 ( V_16 -> V_201 * 100 ) ) ;
}
static void F_122 ( struct V_208 * V_109 ,
T_3 time , unsigned int V_189 )
{
struct V_26 * V_16 = F_123 ( V_109 , struct V_26 , V_209 ) ;
T_3 V_210 = time - V_16 -> V_185 . time ;
if ( ( T_2 ) V_210 >= V_211 )
F_109 ( V_16 , time ) ;
}
static void F_124 ( struct V_208 * V_109 ,
T_3 time , unsigned int V_189 )
{
struct V_26 * V_16 = F_123 ( V_109 , struct V_26 , V_209 ) ;
T_3 V_210 = time - V_16 -> V_185 . time ;
if ( ( T_2 ) V_210 < V_61 . V_111 )
return;
if ( F_109 ( V_16 , time ) ) {
int V_206 ;
V_206 = F_116 ( V_16 ) ;
F_120 ( V_16 , V_206 ) ;
}
}
static void F_125 ( struct V_208 * V_109 , T_3 time ,
unsigned int V_189 )
{
struct V_26 * V_16 = F_123 ( V_109 , struct V_26 , V_209 ) ;
T_3 V_210 ;
if ( V_189 & V_212 ) {
V_16 -> V_201 = F_24 ( 1 ) ;
} else if ( V_16 -> V_201 ) {
V_210 = time - V_16 -> V_213 ;
if ( V_210 > V_214 )
V_16 -> V_201 = 0 ;
}
V_16 -> V_213 = time ;
V_210 = time - V_16 -> V_185 . time ;
if ( ( T_2 ) V_210 < V_215 )
return;
if ( F_109 ( V_16 , time ) ) {
int V_206 ;
V_206 = F_115 ( V_16 ) ;
F_120 ( V_16 , V_206 ) ;
}
}
static int F_126 ( unsigned int V_216 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_216 ] ;
if ( ! V_16 ) {
V_16 = F_127 ( sizeof( * V_16 ) , V_217 ) ;
if ( ! V_16 )
return - V_218 ;
V_29 [ V_216 ] = V_16 ;
V_16 -> V_85 = - V_83 ;
V_16 -> V_108 = - V_83 ;
V_16 -> V_106 = - V_83 ;
}
V_16 = V_29 [ V_216 ] ;
V_16 -> V_16 = V_216 ;
if ( V_28 ) {
const struct V_219 * V_220 ;
V_220 = F_128 ( V_221 ) ;
if ( V_220 )
F_83 ( V_216 ) ;
F_82 ( V_16 ) ;
} else if ( F_129 () ) {
F_25 ( V_16 ) ;
}
F_107 ( V_16 ) ;
F_20 ( L_16 , V_216 ) ;
return 0 ;
}
static unsigned int F_130 ( unsigned int V_222 )
{
struct V_26 * V_16 = V_29 [ V_222 ] ;
return V_16 ? F_113 ( V_16 ) : 0 ;
}
static void F_131 ( unsigned int V_222 )
{
struct V_26 * V_16 = V_29 [ V_222 ] ;
if ( V_16 -> V_223 )
return;
V_16 -> V_185 . time = 0 ;
F_132 ( V_222 , & V_16 -> V_209 ,
V_175 . V_209 ) ;
V_16 -> V_223 = true ;
}
static void F_133 ( unsigned int V_16 )
{
struct V_26 * V_72 = V_29 [ V_16 ] ;
if ( ! V_72 -> V_223 )
return;
F_134 ( V_16 ) ;
V_72 -> V_223 = false ;
F_135 () ;
}
static int F_136 ( struct V_26 * V_16 )
{
return V_41 . V_42 || V_41 . V_100 ?
V_16 -> V_68 . V_44 : V_16 -> V_68 . V_183 ;
}
static void F_137 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
int V_44 = F_136 ( V_16 ) ;
T_1 V_224 , V_225 ;
V_224 = F_8 ( V_25 -> V_96 , V_44 ) ;
V_224 = F_74 ( T_1 , V_224 , 0 , F_138 ( 1 ) ) ;
if ( V_25 -> V_96 == V_25 -> V_94 ) {
V_225 = V_224 ;
} else {
V_225 = F_8 ( V_25 -> V_94 , V_44 ) ;
V_225 = F_74 ( T_1 , V_225 ,
0 , V_224 ) ;
}
if ( V_142 ) {
V_16 -> V_103 = V_225 ;
V_16 -> V_101 = V_224 ;
} else {
T_1 V_226 , V_227 ;
V_227 = F_10 ( V_41 . V_136 ) ;
V_226 = F_10 ( V_41 . V_135 ) ;
if ( V_44 != V_16 -> V_68 . V_183 ) {
T_1 V_228 ;
V_228 = F_8 ( V_16 -> V_68 . V_70 ,
V_16 -> V_68 . V_69 ) ;
V_226 = F_7 ( V_226 , V_228 ) ;
V_227 = F_7 ( V_227 , V_228 ) ;
}
V_226 = F_74 ( T_1 , V_226 , 0 , V_227 ) ;
V_16 -> V_103 = V_96 ( V_225 , V_226 ) ;
V_16 -> V_103 = V_94 ( V_16 -> V_103 , V_224 ) ;
V_16 -> V_101 = V_94 ( V_224 , V_227 ) ;
V_16 -> V_101 = V_96 ( V_225 , V_16 -> V_101 ) ;
V_16 -> V_103 = V_94 ( V_16 -> V_103 , V_16 -> V_101 ) ;
}
V_16 -> V_101 = F_139 ( V_16 -> V_101 , V_8 ) ;
V_16 -> V_103 = F_139 ( V_16 -> V_103 , V_8 ) ;
F_20 ( L_17 , V_25 -> V_16 ,
F_48 ( V_16 -> V_101 * 100 ) ,
F_48 ( V_16 -> V_103 * 100 ) ) ;
}
static int F_140 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
if ( ! V_25 -> V_43 . V_44 )
return - V_229 ;
F_20 ( L_18 ,
V_25 -> V_43 . V_44 , V_25 -> V_96 ) ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_25 = V_25 -> V_25 ;
F_38 ( & V_86 ) ;
F_137 ( V_25 , V_16 ) ;
if ( V_16 -> V_25 == V_102 ) {
F_133 ( V_25 -> V_16 ) ;
F_106 ( V_16 ) ;
}
F_131 ( V_25 -> V_16 ) ;
if ( V_28 )
F_44 ( V_25 -> V_16 ) ;
F_40 ( & V_86 ) ;
return 0 ;
}
static void F_141 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
if ( V_16 -> V_68 . V_179 > V_16 -> V_68 . V_69 &&
V_25 -> V_96 < V_25 -> V_43 . V_44 &&
V_25 -> V_96 > V_16 -> V_68 . V_44 ) {
F_20 ( L_19 ) ;
V_25 -> V_96 = V_25 -> V_43 . V_44 ;
}
}
static int F_142 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_26 () ;
F_143 ( V_25 , V_25 -> V_43 . V_230 ,
F_136 ( V_16 ) ) ;
if ( V_25 -> V_25 != V_231 &&
V_25 -> V_25 != V_102 )
return - V_83 ;
F_141 ( V_25 , V_16 ) ;
return 0 ;
}
static void F_144 ( struct V_24 * V_25 )
{
F_105 ( V_29 [ V_25 -> V_16 ] ) ;
}
static void F_145 ( struct V_24 * V_25 )
{
F_20 ( L_20 , V_25 -> V_16 ) ;
F_133 ( V_25 -> V_16 ) ;
if ( V_28 )
F_51 ( V_25 ) ;
else
F_144 ( V_25 ) ;
}
static int F_146 ( struct V_24 * V_25 )
{
F_22 ( V_25 ) ;
V_25 -> V_232 = false ;
return 0 ;
}
static int F_147 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_138 ;
V_138 = F_126 ( V_25 -> V_16 ) ;
if ( V_138 )
return V_138 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_101 = F_138 ( 1 ) ;
V_16 -> V_103 = 0 ;
V_25 -> V_94 = V_16 -> V_68 . V_71 * V_16 -> V_68 . V_172 ;
V_25 -> V_96 = V_16 -> V_68 . V_70 * V_16 -> V_68 . V_172 ;
V_25 -> V_43 . V_230 = V_16 -> V_68 . V_71 * V_16 -> V_68 . V_172 ;
F_26 () ;
V_25 -> V_43 . V_44 = V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
V_25 -> V_43 . V_44 *= V_16 -> V_68 . V_172 ;
F_18 ( V_25 ) ;
F_148 ( V_25 -> V_16 , V_25 -> V_233 ) ;
V_25 -> V_232 = true ;
return 0 ;
}
static int F_149 ( struct V_24 * V_25 )
{
int V_6 = F_147 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_43 . V_234 = V_235 ;
if ( F_150 ( V_236 ) )
V_25 -> V_25 = V_102 ;
else
V_25 -> V_25 = V_231 ;
return 0 ;
}
static int F_151 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_26 () ;
F_143 ( V_25 , V_25 -> V_43 . V_230 ,
F_136 ( V_16 ) ) ;
F_141 ( V_25 , V_16 ) ;
F_137 ( V_25 , V_16 ) ;
return 0 ;
}
static int F_152 ( struct V_24 * V_25 ,
unsigned int V_237 ,
unsigned int V_238 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
struct V_239 V_240 ;
int V_206 ;
F_26 () ;
V_240 . V_241 = V_25 -> V_242 ;
V_240 . V_243 = V_237 ;
F_153 ( V_25 , & V_240 ) ;
switch ( V_238 ) {
case V_244 :
V_206 = F_29 ( V_240 . V_243 , V_16 -> V_68 . V_172 ) ;
break;
case V_245 :
V_206 = V_240 . V_243 / V_16 -> V_68 . V_172 ;
break;
default:
V_206 = F_154 ( V_240 . V_243 , V_16 -> V_68 . V_172 ) ;
break;
}
V_206 = F_117 ( V_16 , V_206 ) ;
if ( V_206 != V_16 -> V_68 . V_173 ) {
V_16 -> V_68 . V_173 = V_206 ;
F_35 ( V_25 -> V_16 , V_174 ,
V_175 . V_176 ( V_16 , V_206 ) ) ;
}
V_240 . V_243 = V_206 * V_16 -> V_68 . V_172 ;
F_155 ( V_25 , & V_240 , false ) ;
return 0 ;
}
static unsigned int F_156 ( struct V_24 * V_25 ,
unsigned int V_237 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
int V_206 ;
F_26 () ;
V_206 = F_29 ( V_237 , V_16 -> V_68 . V_172 ) ;
V_206 = F_117 ( V_16 , V_206 ) ;
F_118 ( V_16 , V_206 ) ;
return V_206 * V_16 -> V_68 . V_172 ;
}
static int F_157 ( struct V_24 * V_25 )
{
int V_6 = F_147 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_43 . V_234 = V_246 ;
V_25 -> V_247 = V_248 ;
V_25 -> V_242 = V_25 -> V_43 . V_230 ;
return 0 ;
}
static bool F_129 ( void )
{
return V_130 == & V_249 &&
V_175 . V_209 == F_124 ;
}
static void F_158 ( void )
{
unsigned int V_16 ;
F_159 () ;
F_160 (cpu) {
if ( V_29 [ V_16 ] ) {
if ( V_130 == & V_249 )
F_133 ( V_16 ) ;
F_161 ( V_29 [ V_16 ] ) ;
V_29 [ V_16 ] = NULL ;
}
}
F_162 () ;
V_130 = NULL ;
}
static int F_163 ( struct V_250 * V_251 )
{
int V_6 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_136 = 100 ;
V_130 = V_251 ;
V_6 = F_164 ( V_130 ) ;
if ( V_6 ) {
F_158 () ;
return V_6 ;
}
V_41 . V_135 = F_28 () ;
if ( F_129 () )
F_58 () ;
return 0 ;
}
static int F_165 ( void )
{
if ( V_28 )
return - V_252 ;
if ( F_129 () )
F_63 () ;
F_166 ( V_130 ) ;
F_158 () ;
return 0 ;
}
static T_6 F_66 ( char * V_89 )
{
if ( ! V_130 )
return sprintf ( V_89 , L_21 ) ;
return sprintf ( V_89 , L_7 , V_130 == & V_249 ?
L_22 : L_23 ) ;
}
static int F_68 ( const char * V_89 , T_7 V_253 )
{
int V_6 ;
if ( V_253 == 3 && ! strncmp ( V_89 , L_24 , V_253 ) )
return V_130 ?
F_165 () : - V_83 ;
if ( V_253 == 6 && ! strncmp ( V_89 , L_22 , V_253 ) ) {
if ( V_130 ) {
if ( V_130 == & V_249 )
return 0 ;
V_6 = F_165 () ;
if ( V_6 )
return V_6 ;
}
return F_163 ( & V_249 ) ;
}
if ( V_253 == 7 && ! strncmp ( V_89 , L_23 , V_253 ) ) {
if ( V_130 ) {
if ( V_130 == & V_254 )
return 0 ;
V_6 = F_165 () ;
if ( V_6 )
return V_6 ;
}
return F_163 ( & V_254 ) ;
}
return - V_83 ;
}
static int T_9 F_167 ( void )
{
if ( ! V_175 . V_178 () ||
! V_175 . V_177 () ||
! V_175 . V_181 () )
return - V_229 ;
return 0 ;
}
static void F_168 ( void )
{
switch ( V_9 . V_10 ) {
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_175 . V_209 = F_125 ;
}
}
static void F_168 ( void )
{
}
static void T_9 F_169 ( struct V_175 * V_260 )
{
V_175 . V_178 = V_260 -> V_178 ;
V_175 . V_180 = V_260 -> V_180 ;
V_175 . V_177 = V_260 -> V_177 ;
V_175 . V_181 = V_260 -> V_181 ;
V_175 . V_182 = V_260 -> V_182 ;
V_175 . V_176 = V_260 -> V_176 ;
V_175 . V_184 = V_260 -> V_184 ;
V_175 . V_209 = V_260 -> V_209 ;
F_168 () ;
}
static bool T_9 F_170 ( void )
{
int V_27 ;
F_54 (i) {
T_10 V_261 ;
union V_262 * V_263 ;
struct V_264 V_265 = { V_266 , NULL } ;
struct V_267 * V_268 = F_171 ( V_269 , V_27 ) ;
if ( ! V_268 )
continue;
V_261 = F_172 ( V_268 -> V_270 , L_25 , NULL , & V_265 ) ;
if ( F_173 ( V_261 ) )
continue;
V_263 = V_265 . V_271 ;
if ( V_263 && V_263 -> type == V_272 ) {
F_161 ( V_263 ) ;
return false ;
}
F_161 ( V_263 ) ;
}
return true ;
}
static bool T_9 F_174 ( void )
{
int V_27 ;
F_54 (i) {
struct V_267 * V_268 = F_171 ( V_269 , V_27 ) ;
if ( ! V_268 )
continue;
if ( F_175 ( V_268 -> V_270 , L_26 ) )
return true ;
}
return false ;
}
static bool T_9 F_176 ( void )
{
struct V_273 V_274 ;
struct V_275 * V_276 ;
const struct V_219 * V_220 ;
T_3 V_277 ;
V_220 = F_128 ( V_278 ) ;
if ( V_220 ) {
F_27 ( V_279 , V_277 ) ;
if ( V_277 & ( 1 << 8 ) )
return true ;
}
if ( V_280 ||
F_173 ( F_177 ( V_281 , 0 , & V_274 ) ) )
return false ;
for ( V_276 = V_282 ; V_276 -> V_283 ; V_276 ++ ) {
if ( ! strncmp ( V_274 . V_284 , V_276 -> V_284 , V_285 ) &&
! strncmp ( V_274 . V_286 , V_276 -> V_286 ,
V_287 ) )
switch ( V_276 -> V_288 ) {
case V_289 :
return F_170 () ;
case V_290 :
return F_174 () &&
( ! V_291 ) ;
}
}
return false ;
}
static void F_178 ( void )
{
if ( V_13 )
F_179 () ;
}
static inline bool F_176 ( void ) { return false ; }
static inline bool F_174 ( void ) { return false ; }
static inline void F_178 ( void ) {}
static int T_9 F_180 ( void )
{
int V_138 ;
if ( V_292 )
return - V_229 ;
if ( F_128 ( V_293 ) ) {
F_169 ( & V_294 ) ;
if ( V_295 ) {
V_175 . V_209 = F_125 ;
} else {
V_28 ++ ;
V_249 . V_122 = V_296 ;
V_175 . V_209 = F_122 ;
goto V_297;
}
} else {
const struct V_219 * V_220 ;
V_220 = F_128 ( V_298 ) ;
if ( ! V_220 )
return - V_229 ;
F_169 ( (struct V_175 * ) V_220 -> V_299 ) ;
}
if ( F_167 () )
return - V_229 ;
V_297:
if ( F_176 () )
return - V_229 ;
if ( ! V_28 && V_300 )
return - V_301 ;
F_85 ( L_27 ) ;
V_29 = F_181 ( sizeof( void * ) * F_182 () ) ;
if ( ! V_29 )
return - V_218 ;
F_178 () ;
F_77 () ;
F_38 ( & V_123 ) ;
V_138 = F_163 ( V_302 ) ;
F_40 ( & V_123 ) ;
if ( V_138 )
return V_138 ;
if ( V_28 )
F_85 ( L_28 ) ;
return 0 ;
}
static int T_9 F_183 ( char * V_303 )
{
if ( ! V_303 )
return - V_83 ;
if ( ! strcmp ( V_303 , L_29 ) ) {
V_292 = 1 ;
} else if ( ! strcmp ( V_303 , L_23 ) ) {
F_85 ( L_30 ) ;
V_302 = & V_254 ;
V_295 = 1 ;
}
if ( ! strcmp ( V_303 , L_31 ) ) {
F_85 ( L_32 ) ;
V_295 = 1 ;
}
if ( ! strcmp ( V_303 , L_33 ) )
V_291 = 1 ;
if ( ! strcmp ( V_303 , L_34 ) )
V_300 = 1 ;
if ( ! strcmp ( V_303 , L_35 ) )
V_142 = true ;
#ifdef F_184
if ( ! strcmp ( V_303 , L_36 ) )
V_13 = true ;
#endif
return 0 ;
}
