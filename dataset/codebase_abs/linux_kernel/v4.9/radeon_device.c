static inline bool F_1 ( void ) { return false ; }
static inline bool F_2 ( void ) { return false ; }
bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & V_7 )
return true ;
return false ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_10 ;
while ( V_9 && V_9 -> V_11 != 0 ) {
if ( V_4 -> V_12 -> V_13 == V_9 -> V_14 &&
V_4 -> V_12 -> V_15 == V_9 -> V_11 &&
V_4 -> V_12 -> V_16 == V_9 -> V_17 &&
V_4 -> V_12 -> V_18 == V_9 -> V_19 ) {
V_4 -> V_20 = V_9 -> V_20 ;
break;
}
++ V_9 ;
}
if ( V_4 -> V_20 & V_21 )
V_4 -> V_6 &= ~ V_7 ;
if ( ! F_2 () &&
! F_1 () )
V_4 -> V_6 &= ~ V_7 ;
}
void F_5 ( struct V_3 * V_4 ,
const T_1 * V_22 ,
const T_1 V_23 )
{
T_1 V_24 , V_25 , V_26 , V_27 ;
int V_28 ;
if ( V_23 % 3 )
return;
for ( V_28 = 0 ; V_28 < V_23 ; V_28 += 3 ) {
V_25 = V_22 [ V_28 + 0 ] ;
V_26 = V_22 [ V_28 + 1 ] ;
V_27 = V_22 [ V_28 + 2 ] ;
if ( V_26 == 0xffffffff ) {
V_24 = V_27 ;
} else {
V_24 = F_6 ( V_25 ) ;
V_24 &= ~ V_26 ;
V_24 |= V_27 ;
}
F_7 ( V_25 , V_24 ) ;
}
}
void F_8 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_12 , 0x7c , V_29 ) ;
}
void F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_30 < V_31 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
if ( V_4 -> V_33 [ V_28 ] . V_34 )
F_11 ( V_4 -> V_33 [ V_28 ] . V_34 ) ;
else
F_12 ( V_4 , V_28 ) ;
}
F_7 ( V_35 , 0 ) ;
}
}
void F_13 ( struct V_3 * V_4 )
{
int V_28 ;
if ( V_4 -> V_30 < V_36 ) {
V_4 -> V_37 . V_38 = 5 ;
} else {
V_4 -> V_37 . V_38 = 7 ;
}
V_4 -> V_37 . V_39 = V_40 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_37 . V_38 ; V_28 ++ ) {
V_4 -> V_37 . free [ V_28 ] = true ;
V_4 -> V_37 . V_25 [ V_28 ] = V_4 -> V_37 . V_39 + ( V_28 * 4 ) ;
}
}
int F_14 ( struct V_3 * V_4 , T_2 * V_25 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_37 . V_38 ; V_28 ++ ) {
if ( V_4 -> V_37 . free [ V_28 ] ) {
V_4 -> V_37 . free [ V_28 ] = false ;
* V_25 = V_4 -> V_37 . V_25 [ V_28 ] ;
return 0 ;
}
}
return - V_41 ;
}
void F_15 ( struct V_3 * V_4 , T_2 V_25 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_37 . V_38 ; V_28 ++ ) {
if ( V_4 -> V_37 . V_25 [ V_28 ] == V_25 ) {
V_4 -> V_37 . free [ V_28 ] = true ;
return;
}
}
}
static int F_16 ( struct V_3 * V_4 )
{
V_4 -> V_42 . V_43 = F_17 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_42 . V_44 = F_18 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_42 . V_45 = F_19 ( T_1 , V_4 -> V_42 . V_44 / sizeof( T_1 ) , V_46 ) ;
if ( V_4 -> V_42 . V_45 == 0 )
return - V_41 ;
V_4 -> V_42 . V_47 = F_20 ( V_4 -> V_42 . V_43 , V_4 -> V_42 . V_45 * sizeof( T_1 ) ) ;
if ( V_4 -> V_42 . V_47 == NULL ) {
return - V_48 ;
}
F_21 ( L_1 , ( T_2 ) V_4 -> V_42 . V_43 ) ;
F_21 ( L_2 , ( unsigned ) V_4 -> V_42 . V_44 ) ;
memset ( & V_4 -> V_42 . V_49 , 0 , sizeof( V_4 -> V_42 . V_49 ) ) ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
F_23 ( V_4 -> V_42 . V_47 ) ;
V_4 -> V_42 . V_47 = NULL ;
}
int F_24 ( struct V_3 * V_4 , T_1 * V_42 )
{
unsigned long V_50 = F_25 ( V_4 -> V_42 . V_49 , V_4 -> V_42 . V_45 ) ;
if ( V_50 < V_4 -> V_42 . V_45 ) {
F_26 ( V_50 , V_4 -> V_42 . V_49 ) ;
* V_42 = V_50 ;
return 0 ;
} else {
return - V_41 ;
}
}
void F_27 ( struct V_3 * V_4 , T_1 V_42 )
{
if ( V_42 < V_4 -> V_42 . V_45 )
F_28 ( V_42 , V_4 -> V_42 . V_49 ) ;
}
void F_29 ( struct V_3 * V_4 ,
T_3 * V_51 ,
T_4 * V_52 ,
T_4 * V_53 )
{
if ( V_4 -> V_42 . V_44 > V_4 -> V_42 . V_45 * sizeof( T_1 ) ) {
* V_51 = V_4 -> V_42 . V_43 ;
* V_52 = V_4 -> V_42 . V_44 ;
* V_53 = V_4 -> V_42 . V_45 * sizeof( T_1 ) ;
} else {
* V_51 = 0 ;
* V_52 = 0 ;
* V_53 = 0 ;
}
}
void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_54 . V_55 = false ;
}
void F_31 ( struct V_3 * V_4 )
{
F_30 ( V_4 ) ;
if ( V_4 -> V_54 . V_56 ) {
if ( ! F_32 ( V_4 -> V_54 . V_56 , false ) ) {
F_33 ( V_4 -> V_54 . V_56 ) ;
F_34 ( V_4 -> V_54 . V_56 ) ;
F_35 ( V_4 -> V_54 . V_56 ) ;
}
F_36 ( & V_4 -> V_54 . V_56 ) ;
V_4 -> V_54 . V_54 = NULL ;
V_4 -> V_54 . V_56 = NULL ;
}
}
int F_37 ( struct V_3 * V_4 )
{
int V_57 ;
if ( V_4 -> V_54 . V_56 == NULL ) {
V_57 = F_38 ( V_4 , V_58 , V_59 , true ,
V_60 , 0 , NULL , NULL ,
& V_4 -> V_54 . V_56 ) ;
if ( V_57 ) {
F_39 ( V_4 -> V_2 , L_3 , V_57 ) ;
return V_57 ;
}
V_57 = F_32 ( V_4 -> V_54 . V_56 , false ) ;
if ( F_40 ( V_57 != 0 ) ) {
F_31 ( V_4 ) ;
return V_57 ;
}
V_57 = F_41 ( V_4 -> V_54 . V_56 , V_60 ,
& V_4 -> V_54 . V_61 ) ;
if ( V_57 ) {
F_35 ( V_4 -> V_54 . V_56 ) ;
F_39 ( V_4 -> V_2 , L_4 , V_57 ) ;
F_31 ( V_4 ) ;
return V_57 ;
}
V_57 = F_42 ( V_4 -> V_54 . V_56 , ( void * * ) & V_4 -> V_54 . V_54 ) ;
F_35 ( V_4 -> V_54 . V_56 ) ;
if ( V_57 ) {
F_39 ( V_4 -> V_2 , L_5 , V_57 ) ;
F_31 ( V_4 ) ;
return V_57 ;
}
}
memset ( ( char * ) V_4 -> V_54 . V_54 , 0 , V_58 ) ;
V_4 -> V_54 . V_62 = false ;
if ( V_63 == 1 ) {
V_4 -> V_54 . V_55 = false ;
} else {
if ( V_4 -> V_6 & V_64 ) {
V_4 -> V_54 . V_55 = false ;
} else if ( V_4 -> V_30 < V_36 ) {
V_4 -> V_54 . V_55 = false ;
} else {
V_4 -> V_54 . V_55 = true ;
if ( V_4 -> V_30 >= V_31 ) {
V_4 -> V_54 . V_62 = true ;
}
}
}
if ( V_4 -> V_30 >= V_65 ) {
V_4 -> V_54 . V_55 = true ;
V_4 -> V_54 . V_62 = true ;
}
F_43 ( V_4 -> V_2 , L_6 , V_4 -> V_54 . V_55 ? L_7 : L_8 ) ;
return 0 ;
}
void F_44 ( struct V_3 * V_4 , struct V_66 * V_67 , T_5 V_43 )
{
T_6 V_68 = ( T_6 ) V_69 << 20 ;
V_67 -> V_70 = V_43 ;
if ( V_67 -> V_71 > ( V_4 -> V_67 . V_72 - V_43 + 1 ) ) {
F_39 ( V_4 -> V_2 , L_9 ) ;
V_67 -> V_73 = V_67 -> V_74 ;
V_67 -> V_71 = V_67 -> V_74 ;
}
V_67 -> V_75 = V_67 -> V_70 + V_67 -> V_71 - 1 ;
if ( V_4 -> V_6 & V_64 && V_67 -> V_75 > V_67 -> V_76 && V_67 -> V_70 <= V_67 -> V_77 ) {
F_39 ( V_4 -> V_2 , L_9 ) ;
V_67 -> V_73 = V_67 -> V_74 ;
V_67 -> V_71 = V_67 -> V_74 ;
}
V_67 -> V_75 = V_67 -> V_70 + V_67 -> V_71 - 1 ;
if ( V_68 && V_68 < V_67 -> V_73 )
V_67 -> V_73 = V_68 ;
F_43 ( V_4 -> V_2 , L_10 ,
V_67 -> V_71 >> 20 , V_67 -> V_70 ,
V_67 -> V_75 , V_67 -> V_73 >> 20 ) ;
}
void F_45 ( struct V_3 * V_4 , struct V_66 * V_67 )
{
T_5 V_78 , V_79 ;
V_78 = ( ( V_4 -> V_67 . V_72 - V_67 -> V_75 ) + V_67 -> V_80 ) & ~ V_67 -> V_80 ;
V_79 = V_67 -> V_70 & ~ V_67 -> V_80 ;
if ( V_79 > V_78 ) {
if ( V_67 -> V_81 > V_79 ) {
F_39 ( V_4 -> V_2 , L_11 ) ;
V_67 -> V_81 = V_79 ;
}
V_67 -> V_76 = ( V_67 -> V_70 & ~ V_67 -> V_80 ) - V_67 -> V_81 ;
} else {
if ( V_67 -> V_81 > V_78 ) {
F_39 ( V_4 -> V_2 , L_11 ) ;
V_67 -> V_81 = V_78 ;
}
V_67 -> V_76 = ( V_67 -> V_75 + 1 + V_67 -> V_80 ) & ~ V_67 -> V_80 ;
}
V_67 -> V_77 = V_67 -> V_76 + V_67 -> V_81 - 1 ;
F_43 ( V_4 -> V_2 , L_12 ,
V_67 -> V_81 >> 20 , V_67 -> V_76 , V_67 -> V_77 ) ;
}
bool F_46 ( void )
{
#ifdef F_47
return F_48 ( V_82 ) ;
#else
return false ;
#endif
}
bool F_49 ( struct V_3 * V_4 )
{
T_2 V_25 ;
if ( V_4 -> V_30 >= V_83 &&
F_46 () )
return false ;
if ( F_50 ( V_84 ) &&
( V_4 -> V_12 -> V_16 == V_85 ) &&
( V_4 -> V_30 < V_31 ) )
return false ;
if ( F_51 ( V_4 ) )
goto V_86;
if ( F_52 ( V_4 ) ) {
V_25 = F_6 ( V_87 + V_88 ) |
F_6 ( V_87 + V_89 ) ;
if ( V_4 -> V_90 >= 4 ) {
V_25 |= F_6 ( V_87 + V_91 ) |
F_6 ( V_87 + V_92 ) ;
}
if ( V_4 -> V_90 >= 6 ) {
V_25 |= F_6 ( V_87 + V_93 ) |
F_6 ( V_87 + V_94 ) ;
}
if ( V_25 & V_95 )
return true ;
} else if ( F_53 ( V_4 ) ) {
V_25 = F_6 ( V_96 ) |
F_6 ( V_97 ) ;
if ( V_25 & V_98 ) {
return true ;
}
} else {
V_25 = F_6 ( V_99 ) |
F_6 ( V_100 ) ;
if ( V_25 & V_101 ) {
return true ;
}
}
V_86:
if ( V_4 -> V_30 >= V_31 )
V_25 = F_6 ( V_102 ) ;
else
V_25 = F_6 ( V_103 ) ;
if ( V_25 )
return true ;
return false ;
}
void F_54 ( struct V_3 * V_4 )
{
T_7 V_104 ;
T_1 V_105 = V_4 -> V_106 . V_107 ;
T_1 V_108 = V_4 -> V_106 . V_109 ;
V_104 . V_110 = F_55 ( 100 ) ;
V_4 -> V_106 . V_105 . V_110 = F_55 ( V_105 ) ;
V_4 -> V_106 . V_105 . V_110 = F_56 ( V_4 -> V_106 . V_105 , V_104 ) ;
V_4 -> V_106 . V_108 . V_110 = F_55 ( V_108 ) ;
V_4 -> V_106 . V_108 . V_110 = F_56 ( V_4 -> V_106 . V_108 , V_104 ) ;
if ( V_4 -> V_6 & V_111 ) {
V_104 . V_110 = F_55 ( 16 ) ;
V_4 -> V_106 . V_112 . V_110 = F_56 ( V_4 -> V_106 . V_105 , V_104 ) ;
}
}
bool F_57 ( struct V_3 * V_4 )
{
if ( F_49 ( V_4 ) )
return true ;
if ( V_4 -> V_113 ) {
F_21 ( L_13 ) ;
if ( V_4 -> V_114 )
F_58 ( V_4 -> V_115 . V_116 ) ;
else
F_59 ( V_4 -> V_117 ) ;
return true ;
} else {
F_60 ( V_4 -> V_2 , L_14 ) ;
return false ;
}
}
int F_61 ( struct V_3 * V_4 )
{
if ( V_4 -> V_118 . V_119 )
return 0 ;
V_4 -> V_118 . V_119 = F_62 ( V_120 | V_121 | V_122 ) ;
if ( V_4 -> V_118 . V_119 == NULL )
return - V_48 ;
V_4 -> V_118 . V_123 = F_63 ( V_4 -> V_12 , V_4 -> V_118 . V_119 ,
0 , V_59 , V_124 ) ;
if ( F_64 ( V_4 -> V_12 , V_4 -> V_118 . V_123 ) ) {
F_60 ( & V_4 -> V_12 -> V_2 , L_15 ) ;
F_65 ( V_4 -> V_118 . V_119 ) ;
V_4 -> V_118 . V_119 = NULL ;
return - V_48 ;
}
V_4 -> V_118 . V_125 = F_66 ( V_4 -> V_118 . V_123 ,
V_126 ) ;
return 0 ;
}
void F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_118 . V_119 == NULL )
return;
F_68 ( V_4 -> V_12 , V_4 -> V_118 . V_123 ,
V_59 , V_124 ) ;
F_65 ( V_4 -> V_118 . V_119 ) ;
V_4 -> V_118 . V_119 = NULL ;
}
static T_2 F_69 ( struct V_127 * V_128 , T_2 V_25 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = V_4 -> V_129 ( V_4 , V_25 ) ;
return V_57 ;
}
static void F_70 ( struct V_127 * V_128 , T_2 V_25 , T_2 V_130 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
V_4 -> V_131 ( V_4 , V_25 , V_130 ) ;
}
static T_2 F_71 ( struct V_127 * V_128 , T_2 V_25 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = V_4 -> V_132 ( V_4 , V_25 ) ;
return V_57 ;
}
static void F_72 ( struct V_127 * V_128 , T_2 V_25 , T_2 V_130 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
V_4 -> V_133 ( V_4 , V_25 , V_130 ) ;
}
static void F_73 ( struct V_127 * V_128 , T_2 V_25 , T_2 V_130 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
F_7 ( V_25 * 4 , V_130 ) ;
}
static T_2 F_74 ( struct V_127 * V_128 , T_2 V_25 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = F_6 ( V_25 * 4 ) ;
return V_57 ;
}
static void F_75 ( struct V_127 * V_128 , T_2 V_25 , T_2 V_130 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
F_76 ( V_25 * 4 , V_130 ) ;
}
static T_2 F_77 ( struct V_127 * V_128 , T_2 V_25 )
{
struct V_3 * V_4 = V_128 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = F_78 ( V_25 * 4 ) ;
return V_57 ;
}
int F_79 ( struct V_3 * V_4 )
{
struct V_127 * V_134 =
F_80 ( sizeof( struct V_127 ) , V_121 ) ;
if ( ! V_134 )
return - V_48 ;
V_4 -> V_115 . V_134 = V_134 ;
V_134 -> V_2 = V_4 -> V_117 ;
V_134 -> V_135 = F_74 ;
V_134 -> V_136 = F_73 ;
if ( V_4 -> V_137 ) {
V_134 -> V_138 = F_77 ;
V_134 -> V_139 = F_75 ;
} else {
F_81 ( L_16 ) ;
V_134 -> V_138 = F_74 ;
V_134 -> V_139 = F_73 ;
}
V_134 -> V_140 = F_71 ;
V_134 -> V_141 = F_72 ;
V_134 -> V_142 = F_69 ;
V_134 -> V_143 = F_70 ;
V_4 -> V_115 . V_116 = F_82 ( V_134 , V_4 -> V_113 ) ;
if ( ! V_4 -> V_115 . V_116 ) {
F_83 ( V_4 ) ;
return - V_48 ;
}
F_84 ( & V_4 -> V_115 . V_116 -> V_144 ) ;
F_84 ( & V_4 -> V_115 . V_116 -> V_145 ) ;
F_85 ( V_4 -> V_117 ) ;
F_86 ( V_4 -> V_115 . V_116 ) ;
return 0 ;
}
void F_83 ( struct V_3 * V_4 )
{
if ( V_4 -> V_115 . V_116 ) {
F_87 ( V_4 -> V_115 . V_116 -> V_37 ) ;
}
F_87 ( V_4 -> V_115 . V_116 ) ;
V_4 -> V_115 . V_116 = NULL ;
F_87 ( V_4 -> V_115 . V_134 ) ;
V_4 -> V_115 . V_134 = NULL ;
}
int F_88 ( struct V_3 * V_4 )
{
F_89 ( V_4 -> V_117 ) ;
return 0 ;
}
void F_90 ( struct V_3 * V_4 )
{
}
static unsigned int F_91 ( void * V_146 , bool V_147 )
{
struct V_3 * V_4 = V_146 ;
F_92 ( V_4 , V_147 ) ;
if ( V_147 )
return V_148 | V_149 |
V_150 | V_151 ;
else
return V_150 | V_151 ;
}
static bool F_93 ( int V_152 )
{
return ( V_152 & ( V_152 - 1 ) ) == 0 ;
}
static int F_94 ( enum V_153 V_30 )
{
if ( V_30 >= V_154 )
return 2048 ;
else if ( V_30 >= V_155 )
return 1024 ;
else
return 512 ;
}
static void F_95 ( struct V_3 * V_4 )
{
if ( ! F_93 ( V_69 ) ) {
F_39 ( V_4 -> V_2 , L_17 ,
V_69 ) ;
V_69 = 0 ;
}
if ( V_156 == - 1 ) {
V_156 = F_94 ( V_4 -> V_30 ) ;
}
if ( V_156 < 32 ) {
F_39 ( V_4 -> V_2 , L_18 ,
V_156 ) ;
V_156 = F_94 ( V_4 -> V_30 ) ;
} else if ( ! F_93 ( V_156 ) ) {
F_39 ( V_4 -> V_2 , L_19 ,
V_156 ) ;
V_156 = F_94 ( V_4 -> V_30 ) ;
}
V_4 -> V_67 . V_81 = ( T_6 ) V_156 << 20 ;
switch ( V_157 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_39 ( V_4 -> V_2 , L_20
L_21 , V_157 ) ;
V_157 = 0 ;
break;
}
if ( ! F_93 ( V_158 ) ) {
F_39 ( V_4 -> V_2 , L_22 ,
V_158 ) ;
V_158 = 4 ;
}
if ( V_158 < 1 ) {
F_39 ( V_4 -> V_2 , L_23 ,
V_158 ) ;
V_158 = 4 ;
}
if ( V_158 > 1024 ) {
F_39 ( V_4 -> V_2 , L_24 ,
V_158 ) ;
V_158 = 4 ;
}
if ( V_159 == - 1 ) {
unsigned V_160 = F_96 ( V_158 ) + 18 ;
if ( V_158 <= 8 )
V_159 = V_160 - 9 ;
else
V_159 = ( V_160 + 3 ) / 2 ;
} else if ( V_159 < 9 ) {
F_39 ( V_4 -> V_2 , L_25 ,
V_159 ) ;
V_159 = 9 ;
}
if ( V_159 > 24 ||
( V_158 * 1024 ) < ( 1ull << V_159 ) ) {
F_39 ( V_4 -> V_2 , L_26 ,
V_159 ) ;
V_159 = 9 ;
}
}
static void F_97 ( struct V_161 * V_12 , enum V_162 V_147 )
{
struct V_1 * V_2 = F_98 ( V_12 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) && V_147 == V_163 )
return;
if ( V_147 == V_164 ) {
unsigned V_165 = V_2 -> V_12 -> V_165 ;
F_99 ( V_166 L_27 ) ;
V_2 -> V_167 = V_168 ;
if ( V_165 < 20 && ( V_4 -> V_20 & V_169 ) )
V_2 -> V_12 -> V_165 = 20 ;
F_100 ( V_2 , true , true ) ;
V_2 -> V_12 -> V_165 = V_165 ;
V_2 -> V_167 = V_170 ;
F_101 ( V_2 ) ;
} else {
F_99 ( V_166 L_28 ) ;
F_102 ( V_2 ) ;
V_2 -> V_167 = V_168 ;
F_103 ( V_2 , true , true , false ) ;
V_2 -> V_167 = V_171 ;
}
}
static bool F_104 ( struct V_161 * V_12 )
{
struct V_1 * V_2 = F_98 ( V_12 ) ;
return V_2 -> V_172 == 0 ;
}
int F_105 ( struct V_3 * V_4 ,
struct V_1 * V_117 ,
struct V_161 * V_12 ,
T_2 V_6 )
{
int V_57 , V_28 ;
int V_173 ;
bool V_174 = false ;
V_4 -> V_175 = false ;
V_4 -> V_2 = & V_12 -> V_2 ;
V_4 -> V_117 = V_117 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_30 = V_6 & V_176 ;
V_4 -> V_114 = false ;
V_4 -> V_177 = V_178 ;
V_4 -> V_67 . V_81 = 512 * 1024 * 1024 ;
V_4 -> V_179 = false ;
for ( V_28 = 0 ; V_28 < V_180 ; V_28 ++ ) {
V_4 -> V_181 [ V_28 ] . V_182 = V_28 ;
}
V_4 -> V_183 = F_106 ( V_180 ) ;
F_21 ( L_29 ,
V_184 [ V_4 -> V_30 ] , V_12 -> V_13 , V_12 -> V_15 ,
V_12 -> V_16 , V_12 -> V_18 , V_12 -> V_185 ) ;
F_84 ( & V_4 -> V_186 ) ;
F_84 ( & V_4 -> V_187 ) ;
F_107 ( & V_4 -> V_188 . V_189 , 0 ) ;
F_84 ( & V_4 -> V_190 . V_144 ) ;
F_84 ( & V_4 -> V_106 . V_144 ) ;
F_84 ( & V_4 -> V_191 ) ;
F_84 ( & V_4 -> V_192 ) ;
F_84 ( & V_4 -> V_193 ) ;
F_108 ( & V_4 -> V_106 . V_194 ) ;
F_108 ( & V_4 -> V_195 ) ;
F_109 ( & V_4 -> V_196 . V_197 ) ;
F_84 ( & V_4 -> V_198 ) ;
F_110 ( V_4 -> V_199 ) ;
V_57 = F_111 ( V_4 ) ;
if ( V_57 )
return V_57 ;
F_95 ( V_4 ) ;
V_4 -> V_200 . V_201 = V_158 << 18 ;
V_57 = F_112 ( V_4 ) ;
if ( V_57 )
return V_57 ;
if ( ( V_4 -> V_30 >= V_202 ) &&
( V_4 -> V_6 & V_111 ) ) {
V_4 -> V_6 &= ~ V_64 ;
}
if ( V_4 -> V_6 & V_64 && V_157 == - 1 ) {
F_113 ( V_4 ) ;
}
if ( V_4 -> V_30 >= V_203 )
V_4 -> V_67 . V_72 = 0xffffffffffULL ;
else if ( V_4 -> V_30 >= V_204 )
V_4 -> V_67 . V_72 = 0xfffffffffULL ;
else
V_4 -> V_67 . V_72 = 0xffffffffULL ;
V_4 -> V_205 = false ;
if ( V_4 -> V_6 & V_64 )
V_4 -> V_205 = true ;
if ( ( V_4 -> V_6 & V_206 ) &&
( V_4 -> V_30 <= V_207 ) )
V_4 -> V_205 = true ;
V_173 = V_4 -> V_205 ? 32 : 40 ;
V_57 = F_114 ( V_4 -> V_12 , F_115 ( V_173 ) ) ;
if ( V_57 ) {
V_4 -> V_205 = true ;
V_173 = 32 ;
F_99 ( V_208 L_30 ) ;
}
V_57 = F_116 ( V_4 -> V_12 , F_115 ( V_173 ) ) ;
if ( V_57 ) {
F_116 ( V_4 -> V_12 , F_115 ( 32 ) ) ;
F_99 ( V_208 L_31 ) ;
}
F_117 ( & V_4 -> V_209 ) ;
F_117 ( & V_4 -> V_210 ) ;
F_117 ( & V_4 -> V_211 ) ;
F_117 ( & V_4 -> V_212 ) ;
F_117 ( & V_4 -> V_213 ) ;
F_117 ( & V_4 -> V_214 ) ;
F_117 ( & V_4 -> V_215 ) ;
F_117 ( & V_4 -> V_216 ) ;
F_117 ( & V_4 -> V_217 ) ;
F_117 ( & V_4 -> V_218 ) ;
F_117 ( & V_4 -> V_219 ) ;
F_117 ( & V_4 -> V_220 ) ;
if ( V_4 -> V_30 >= V_83 ) {
V_4 -> V_221 = F_17 ( V_4 -> V_12 , 5 ) ;
V_4 -> V_222 = F_18 ( V_4 -> V_12 , 5 ) ;
} else {
V_4 -> V_221 = F_17 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_222 = F_18 ( V_4 -> V_12 , 2 ) ;
}
V_4 -> V_223 = F_20 ( V_4 -> V_221 , V_4 -> V_222 ) ;
if ( V_4 -> V_223 == NULL ) {
return - V_48 ;
}
F_21 ( L_32 , ( T_2 ) V_4 -> V_221 ) ;
F_21 ( L_33 , ( unsigned ) V_4 -> V_222 ) ;
if ( V_4 -> V_30 >= V_83 )
F_16 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_224 ; V_28 ++ ) {
if ( F_118 ( V_4 -> V_12 , V_28 ) & V_225 ) {
V_4 -> V_226 = F_18 ( V_4 -> V_12 , V_28 ) ;
V_4 -> V_137 = F_119 ( V_4 -> V_12 , V_28 , V_4 -> V_226 ) ;
break;
}
}
if ( V_4 -> V_137 == NULL )
F_81 ( L_34 ) ;
if ( V_4 -> V_6 & V_7 )
F_4 ( V_4 ) ;
F_120 ( V_4 -> V_12 , V_4 , NULL , F_91 ) ;
if ( V_4 -> V_6 & V_7 )
V_174 = true ;
F_121 ( V_4 -> V_12 , & V_227 , V_174 ) ;
if ( V_174 )
F_122 ( V_4 -> V_2 , & V_4 -> V_228 ) ;
V_57 = F_123 ( V_4 ) ;
if ( V_57 )
goto V_229;
V_57 = F_124 ( V_4 ) ;
if ( V_57 ) {
F_81 ( L_35 , V_57 ) ;
}
V_57 = F_125 ( V_4 ) ;
if ( V_57 ) {
F_81 ( L_36 , V_57 ) ;
}
if ( V_4 -> V_6 & V_64 && ! V_4 -> V_179 ) {
F_126 ( V_4 ) ;
F_127 ( V_4 ) ;
F_113 ( V_4 ) ;
V_57 = F_123 ( V_4 ) ;
if ( V_57 )
goto V_229;
}
V_57 = F_128 ( V_4 ) ;
if ( V_57 )
F_81 ( L_37 , V_57 ) ;
if ( V_4 -> V_106 . V_230 &&
( V_4 -> V_106 . V_231 == V_232 ) &&
( V_4 -> V_30 == V_233 ) &&
( V_4 -> V_6 & V_234 ) ) {
F_129 ( & V_4 -> V_106 . V_144 ) ;
F_130 ( V_4 ) ;
F_131 ( V_4 ) ;
F_132 ( & V_4 -> V_106 . V_144 ) ;
}
if ( ( V_235 & 1 ) ) {
if ( V_4 -> V_179 )
F_133 ( V_4 ) ;
else
F_21 ( L_38 ) ;
}
if ( ( V_235 & 2 ) ) {
if ( V_4 -> V_179 )
F_134 ( V_4 ) ;
else
F_21 ( L_39 ) ;
}
if ( V_236 ) {
if ( V_4 -> V_179 )
F_135 ( V_4 , V_236 ) ;
else
F_21 ( L_40 ) ;
}
return 0 ;
V_229:
if ( F_3 ( V_117 ) )
F_136 ( V_117 -> V_2 ) ;
if ( V_174 )
F_137 ( V_4 -> V_2 ) ;
return V_57 ;
}
void F_138 ( struct V_3 * V_4 )
{
F_21 ( L_41 ) ;
V_4 -> V_175 = true ;
F_139 ( V_4 ) ;
F_127 ( V_4 ) ;
F_140 ( V_4 -> V_12 ) ;
if ( V_4 -> V_6 & V_7 )
F_137 ( V_4 -> V_2 ) ;
F_120 ( V_4 -> V_12 , NULL , NULL , NULL ) ;
if ( V_4 -> V_137 )
F_141 ( V_4 -> V_12 , V_4 -> V_137 ) ;
V_4 -> V_137 = NULL ;
F_23 ( V_4 -> V_223 ) ;
V_4 -> V_223 = NULL ;
if ( V_4 -> V_30 >= V_83 )
F_22 ( V_4 ) ;
F_142 ( V_4 ) ;
}
int F_103 ( struct V_1 * V_2 , bool V_237 ,
bool V_238 , bool V_239 )
{
struct V_3 * V_4 ;
struct V_240 * V_241 ;
struct V_242 * V_243 ;
int V_28 , V_57 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_244 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_167 == V_171 )
return 0 ;
F_102 ( V_2 ) ;
F_143 ( V_2 ) ;
F_144 (connector, &dev->mode_config.connector_list, head) {
F_145 ( V_243 , V_245 ) ;
}
F_146 ( V_2 ) ;
F_144 (crtc, &dev->mode_config.crtc_list, head) {
struct V_246 * V_246 = F_147 ( V_241 ) ;
struct V_247 * V_248 = F_148 ( V_241 -> V_249 -> V_250 ) ;
struct V_251 * V_252 ;
if ( V_246 -> V_253 ) {
struct V_251 * V_252 = F_149 ( V_246 -> V_253 ) ;
V_57 = F_32 ( V_252 , false ) ;
if ( V_57 == 0 ) {
F_34 ( V_252 ) ;
F_35 ( V_252 ) ;
}
}
if ( V_248 == NULL || V_248 -> V_254 == NULL ) {
continue;
}
V_252 = F_149 ( V_248 -> V_254 ) ;
if ( ! F_150 ( V_4 , V_252 ) ) {
V_57 = F_32 ( V_252 , false ) ;
if ( V_57 == 0 ) {
F_34 ( V_252 ) ;
F_35 ( V_252 ) ;
}
}
}
F_139 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_180 ; V_28 ++ ) {
V_57 = F_151 ( V_4 , V_28 ) ;
if ( V_57 ) {
F_152 ( V_4 , V_28 ) ;
}
}
F_153 ( V_4 ) ;
F_154 ( V_4 ) ;
F_155 ( V_4 ) ;
F_139 ( V_4 ) ;
F_156 ( V_4 ) ;
F_157 ( V_2 -> V_12 ) ;
if ( V_239 && V_4 -> V_30 >= V_204 ) {
V_4 -> V_255 -> V_256 ( V_4 , true ) ;
F_158 ( V_2 -> V_12 ) ;
} else if ( V_237 ) {
F_159 ( V_2 -> V_12 ) ;
F_160 ( V_2 -> V_12 , V_257 ) ;
}
if ( V_238 ) {
F_161 () ;
F_162 ( V_4 , 1 ) ;
F_163 () ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 , bool V_258 , bool V_238 )
{
struct V_242 * V_243 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_240 * V_241 ;
int V_57 ;
if ( V_2 -> V_167 == V_171 )
return 0 ;
if ( V_238 ) {
F_161 () ;
}
if ( V_258 ) {
F_160 ( V_2 -> V_12 , V_259 ) ;
F_158 ( V_2 -> V_12 ) ;
if ( F_164 ( V_2 -> V_12 ) ) {
if ( V_238 )
F_163 () ;
return - 1 ;
}
}
F_165 ( V_4 ) ;
F_166 ( V_4 ) ;
V_57 = F_128 ( V_4 ) ;
if ( V_57 )
F_81 ( L_37 , V_57 ) ;
if ( ( V_4 -> V_106 . V_231 == V_232 ) && V_4 -> V_106 . V_230 ) {
V_57 = F_167 ( V_4 ) ;
if ( V_57 ) {
V_4 -> V_106 . V_230 = false ;
F_81 ( L_42 ) ;
}
} else {
F_168 ( V_4 ) ;
}
F_169 ( V_4 ) ;
F_144 (crtc, &dev->mode_config.crtc_list, head) {
struct V_246 * V_246 = F_147 ( V_241 ) ;
if ( V_246 -> V_253 ) {
struct V_251 * V_252 = F_149 ( V_246 -> V_253 ) ;
V_57 = F_32 ( V_252 , false ) ;
if ( V_57 == 0 ) {
V_57 = F_170 ( V_252 ,
V_260 ,
F_53 ( V_4 ) ?
0 : 1 << 27 ,
& V_246 -> V_261 ) ;
if ( V_57 != 0 )
F_81 ( L_43 , V_57 ) ;
F_35 ( V_252 ) ;
}
}
}
if ( V_4 -> V_114 ) {
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
if ( V_4 -> V_115 . V_262 ) {
T_8 V_263 = F_173 ( V_4 ,
V_4 -> V_115 . V_262 ) ;
F_174 ( V_4 , V_4 -> V_115 . V_262 ,
V_263 ) ;
}
}
F_175 ( V_4 ) ;
if ( V_238 ) {
F_176 ( V_2 ) ;
F_143 ( V_2 ) ;
F_144 (connector, &dev->mode_config.connector_list, head) {
F_145 ( V_243 , V_264 ) ;
}
F_146 ( V_2 ) ;
}
F_101 ( V_2 ) ;
if ( ( V_4 -> V_106 . V_231 == V_232 ) && V_4 -> V_106 . V_230 )
F_177 ( V_4 ) ;
if ( V_238 ) {
F_162 ( V_4 , 0 ) ;
F_163 () ;
}
return 0 ;
}
int F_178 ( struct V_3 * V_4 )
{
unsigned V_265 [ V_180 ] ;
T_2 * V_266 [ V_180 ] ;
bool V_267 = false ;
int V_28 , V_57 ;
int V_268 ;
F_179 ( & V_4 -> V_195 ) ;
if ( ! V_4 -> V_269 ) {
F_180 ( & V_4 -> V_195 ) ;
return 0 ;
}
F_181 ( & V_4 -> V_270 ) ;
F_153 ( V_4 ) ;
V_268 = F_182 ( & V_4 -> V_271 . V_272 ) ;
F_154 ( V_4 ) ;
F_155 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_180 ; ++ V_28 ) {
V_265 [ V_28 ] = F_183 ( V_4 , & V_4 -> V_181 [ V_28 ] ,
& V_266 [ V_28 ] ) ;
if ( V_265 [ V_28 ] ) {
V_267 = true ;
F_43 ( V_4 -> V_2 , L_44
L_45 , V_265 [ V_28 ] , V_28 ) ;
}
}
V_57 = F_126 ( V_4 ) ;
if ( ! V_57 ) {
F_43 ( V_4 -> V_2 , L_46 ) ;
F_166 ( V_4 ) ;
}
F_169 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_180 ; ++ V_28 ) {
if ( ! V_57 && V_266 [ V_28 ] ) {
F_184 ( V_4 , & V_4 -> V_181 [ V_28 ] ,
V_265 [ V_28 ] , V_266 [ V_28 ] ) ;
} else {
F_152 ( V_4 , V_28 ) ;
F_87 ( V_266 [ V_28 ] ) ;
}
}
if ( ( V_4 -> V_106 . V_231 == V_232 ) && V_4 -> V_106 . V_230 ) {
V_57 = F_167 ( V_4 ) ;
if ( V_57 ) {
V_4 -> V_106 . V_230 = false ;
F_81 ( L_42 ) ;
}
} else {
F_168 ( V_4 ) ;
}
if ( V_4 -> V_114 ) {
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
if ( V_4 -> V_115 . V_262 ) {
T_8 V_263 = F_173 ( V_4 ,
V_4 -> V_115 . V_262 ) ;
F_174 ( V_4 , V_4 -> V_115 . V_262 ,
V_263 ) ;
}
}
F_175 ( V_4 ) ;
F_185 ( & V_4 -> V_271 . V_272 , V_268 ) ;
V_4 -> V_273 = true ;
V_4 -> V_269 = false ;
F_186 ( & V_4 -> V_195 ) ;
F_176 ( V_4 -> V_117 ) ;
if ( ( V_4 -> V_106 . V_231 == V_232 ) && V_4 -> V_106 . V_230 )
F_177 ( V_4 ) ;
if ( ! V_57 ) {
V_57 = F_128 ( V_4 ) ;
if ( V_57 && V_267 )
V_57 = - V_274 ;
} else {
F_43 ( V_4 -> V_2 , L_47 ) ;
}
V_4 -> V_269 = V_57 == - V_274 ;
V_4 -> V_273 = false ;
F_187 ( & V_4 -> V_195 ) ;
return V_57 ;
}
int F_188 ( struct V_3 * V_4 ,
struct V_275 * V_276 ,
unsigned V_277 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_278 ; V_28 ++ ) {
if ( V_4 -> V_279 [ V_28 ] . V_276 == V_276 ) {
return 0 ;
}
}
V_28 = V_4 -> V_278 + 1 ;
if ( V_28 > V_280 ) {
F_81 ( L_48 ) ;
F_81 ( L_49
L_50 ) ;
return - V_41 ;
}
V_4 -> V_279 [ V_4 -> V_278 ] . V_276 = V_276 ;
V_4 -> V_279 [ V_4 -> V_278 ] . V_281 = V_277 ;
V_4 -> V_278 = V_28 ;
#if F_189 ( V_282 )
F_190 ( V_276 , V_277 ,
V_4 -> V_117 -> V_283 -> V_284 ,
V_4 -> V_117 -> V_283 ) ;
F_190 ( V_276 , V_277 ,
V_4 -> V_117 -> V_249 -> V_284 ,
V_4 -> V_117 -> V_249 ) ;
#endif
return 0 ;
}
static void F_142 ( struct V_3 * V_4 )
{
#if F_189 ( V_282 )
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_278 ; V_28 ++ ) {
F_191 ( V_4 -> V_279 [ V_28 ] . V_276 ,
V_4 -> V_279 [ V_28 ] . V_281 ,
V_4 -> V_117 -> V_283 ) ;
F_191 ( V_4 -> V_279 [ V_28 ] . V_276 ,
V_4 -> V_279 [ V_28 ] . V_281 ,
V_4 -> V_117 -> V_249 ) ;
}
#endif
}
