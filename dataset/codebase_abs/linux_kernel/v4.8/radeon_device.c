bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & V_7 )
return true ;
return false ;
}
static void F_2 ( struct V_3 * V_4 )
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
}
void F_3 ( struct V_3 * V_4 ,
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
V_24 = F_4 ( V_25 ) ;
V_24 &= ~ V_26 ;
V_24 |= V_27 ;
}
F_5 ( V_25 , V_24 ) ;
}
}
void F_6 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_12 , 0x7c , V_29 ) ;
}
void F_8 ( struct V_3 * V_4 )
{
if ( V_4 -> V_30 < V_31 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
if ( V_4 -> V_33 [ V_28 ] . V_34 )
F_9 ( V_4 -> V_33 [ V_28 ] . V_34 ) ;
else
F_10 ( V_4 , V_28 ) ;
}
F_5 ( V_35 , 0 ) ;
}
}
void F_11 ( struct V_3 * V_4 )
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
int F_12 ( struct V_3 * V_4 , T_2 * V_25 )
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
void F_13 ( struct V_3 * V_4 , T_2 V_25 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_37 . V_38 ; V_28 ++ ) {
if ( V_4 -> V_37 . V_25 [ V_28 ] == V_25 ) {
V_4 -> V_37 . free [ V_28 ] = true ;
return;
}
}
}
static int F_14 ( struct V_3 * V_4 )
{
V_4 -> V_42 . V_43 = F_15 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_42 . V_44 = F_16 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_42 . V_45 = F_17 ( T_1 , V_4 -> V_42 . V_44 / sizeof( T_1 ) , V_46 ) ;
if ( V_4 -> V_42 . V_45 == 0 )
return - V_41 ;
V_4 -> V_42 . V_47 = F_18 ( V_4 -> V_42 . V_43 , V_4 -> V_42 . V_45 * sizeof( T_1 ) ) ;
if ( V_4 -> V_42 . V_47 == NULL ) {
return - V_48 ;
}
F_19 ( L_1 , ( T_2 ) V_4 -> V_42 . V_43 ) ;
F_19 ( L_2 , ( unsigned ) V_4 -> V_42 . V_44 ) ;
memset ( & V_4 -> V_42 . V_49 , 0 , sizeof( V_4 -> V_42 . V_49 ) ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 -> V_42 . V_47 ) ;
V_4 -> V_42 . V_47 = NULL ;
}
int F_22 ( struct V_3 * V_4 , T_1 * V_42 )
{
unsigned long V_50 = F_23 ( V_4 -> V_42 . V_49 , V_4 -> V_42 . V_45 ) ;
if ( V_50 < V_4 -> V_42 . V_45 ) {
F_24 ( V_50 , V_4 -> V_42 . V_49 ) ;
* V_42 = V_50 ;
return 0 ;
} else {
return - V_41 ;
}
}
void F_25 ( struct V_3 * V_4 , T_1 V_42 )
{
if ( V_42 < V_4 -> V_42 . V_45 )
F_26 ( V_42 , V_4 -> V_42 . V_49 ) ;
}
void F_27 ( struct V_3 * V_4 ,
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
void F_28 ( struct V_3 * V_4 )
{
V_4 -> V_54 . V_55 = false ;
}
void F_29 ( struct V_3 * V_4 )
{
F_28 ( V_4 ) ;
if ( V_4 -> V_54 . V_56 ) {
if ( ! F_30 ( V_4 -> V_54 . V_56 , false ) ) {
F_31 ( V_4 -> V_54 . V_56 ) ;
F_32 ( V_4 -> V_54 . V_56 ) ;
F_33 ( V_4 -> V_54 . V_56 ) ;
}
F_34 ( & V_4 -> V_54 . V_56 ) ;
V_4 -> V_54 . V_54 = NULL ;
V_4 -> V_54 . V_56 = NULL ;
}
}
int F_35 ( struct V_3 * V_4 )
{
int V_57 ;
if ( V_4 -> V_54 . V_56 == NULL ) {
V_57 = F_36 ( V_4 , V_58 , V_59 , true ,
V_60 , 0 , NULL , NULL ,
& V_4 -> V_54 . V_56 ) ;
if ( V_57 ) {
F_37 ( V_4 -> V_2 , L_3 , V_57 ) ;
return V_57 ;
}
V_57 = F_30 ( V_4 -> V_54 . V_56 , false ) ;
if ( F_38 ( V_57 != 0 ) ) {
F_29 ( V_4 ) ;
return V_57 ;
}
V_57 = F_39 ( V_4 -> V_54 . V_56 , V_60 ,
& V_4 -> V_54 . V_61 ) ;
if ( V_57 ) {
F_33 ( V_4 -> V_54 . V_56 ) ;
F_37 ( V_4 -> V_2 , L_4 , V_57 ) ;
F_29 ( V_4 ) ;
return V_57 ;
}
V_57 = F_40 ( V_4 -> V_54 . V_56 , ( void * * ) & V_4 -> V_54 . V_54 ) ;
F_33 ( V_4 -> V_54 . V_56 ) ;
if ( V_57 ) {
F_37 ( V_4 -> V_2 , L_5 , V_57 ) ;
F_29 ( V_4 ) ;
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
F_41 ( V_4 -> V_2 , L_6 , V_4 -> V_54 . V_55 ? L_7 : L_8 ) ;
return 0 ;
}
void F_42 ( struct V_3 * V_4 , struct V_66 * V_67 , T_5 V_43 )
{
T_6 V_68 = ( T_6 ) V_69 << 20 ;
V_67 -> V_70 = V_43 ;
if ( V_67 -> V_71 > ( V_4 -> V_67 . V_72 - V_43 + 1 ) ) {
F_37 ( V_4 -> V_2 , L_9 ) ;
V_67 -> V_73 = V_67 -> V_74 ;
V_67 -> V_71 = V_67 -> V_74 ;
}
V_67 -> V_75 = V_67 -> V_70 + V_67 -> V_71 - 1 ;
if ( V_4 -> V_6 & V_64 && V_67 -> V_75 > V_67 -> V_76 && V_67 -> V_70 <= V_67 -> V_77 ) {
F_37 ( V_4 -> V_2 , L_9 ) ;
V_67 -> V_73 = V_67 -> V_74 ;
V_67 -> V_71 = V_67 -> V_74 ;
}
V_67 -> V_75 = V_67 -> V_70 + V_67 -> V_71 - 1 ;
if ( V_68 && V_68 < V_67 -> V_73 )
V_67 -> V_73 = V_68 ;
F_41 ( V_4 -> V_2 , L_10 ,
V_67 -> V_71 >> 20 , V_67 -> V_70 ,
V_67 -> V_75 , V_67 -> V_73 >> 20 ) ;
}
void F_43 ( struct V_3 * V_4 , struct V_66 * V_67 )
{
T_5 V_78 , V_79 ;
V_78 = ( ( V_4 -> V_67 . V_72 - V_67 -> V_75 ) + V_67 -> V_80 ) & ~ V_67 -> V_80 ;
V_79 = V_67 -> V_70 & ~ V_67 -> V_80 ;
if ( V_79 > V_78 ) {
if ( V_67 -> V_81 > V_79 ) {
F_37 ( V_4 -> V_2 , L_11 ) ;
V_67 -> V_81 = V_79 ;
}
V_67 -> V_76 = ( V_67 -> V_70 & ~ V_67 -> V_80 ) - V_67 -> V_81 ;
} else {
if ( V_67 -> V_81 > V_78 ) {
F_37 ( V_4 -> V_2 , L_11 ) ;
V_67 -> V_81 = V_78 ;
}
V_67 -> V_76 = ( V_67 -> V_75 + 1 + V_67 -> V_80 ) & ~ V_67 -> V_80 ;
}
V_67 -> V_77 = V_67 -> V_76 + V_67 -> V_81 - 1 ;
F_41 ( V_4 -> V_2 , L_12 ,
V_67 -> V_81 >> 20 , V_67 -> V_76 , V_67 -> V_77 ) ;
}
static bool F_44 ( void )
{
#ifdef F_45
return F_46 ( V_82 ) ;
#else
return false ;
#endif
}
bool F_47 ( struct V_3 * V_4 )
{
T_2 V_25 ;
if ( F_44 () )
return false ;
if ( F_48 ( V_83 ) &&
( V_4 -> V_12 -> V_16 == V_84 ) &&
( V_4 -> V_30 < V_31 ) )
return false ;
if ( F_49 ( V_4 ) )
goto V_85;
if ( F_50 ( V_4 ) ) {
V_25 = F_4 ( V_86 + V_87 ) |
F_4 ( V_86 + V_88 ) ;
if ( V_4 -> V_89 >= 4 ) {
V_25 |= F_4 ( V_86 + V_90 ) |
F_4 ( V_86 + V_91 ) ;
}
if ( V_4 -> V_89 >= 6 ) {
V_25 |= F_4 ( V_86 + V_92 ) |
F_4 ( V_86 + V_93 ) ;
}
if ( V_25 & V_94 )
return true ;
} else if ( F_51 ( V_4 ) ) {
V_25 = F_4 ( V_95 ) |
F_4 ( V_96 ) ;
if ( V_25 & V_97 ) {
return true ;
}
} else {
V_25 = F_4 ( V_98 ) |
F_4 ( V_99 ) ;
if ( V_25 & V_100 ) {
return true ;
}
}
V_85:
if ( V_4 -> V_30 >= V_31 )
V_25 = F_4 ( V_101 ) ;
else
V_25 = F_4 ( V_102 ) ;
if ( V_25 )
return true ;
return false ;
}
void F_52 ( struct V_3 * V_4 )
{
T_7 V_103 ;
T_1 V_104 = V_4 -> V_105 . V_106 ;
T_1 V_107 = V_4 -> V_105 . V_108 ;
V_103 . V_109 = F_53 ( 100 ) ;
V_4 -> V_105 . V_104 . V_109 = F_53 ( V_104 ) ;
V_4 -> V_105 . V_104 . V_109 = F_54 ( V_4 -> V_105 . V_104 , V_103 ) ;
V_4 -> V_105 . V_107 . V_109 = F_53 ( V_107 ) ;
V_4 -> V_105 . V_107 . V_109 = F_54 ( V_4 -> V_105 . V_107 , V_103 ) ;
if ( V_4 -> V_6 & V_110 ) {
V_103 . V_109 = F_53 ( 16 ) ;
V_4 -> V_105 . V_111 . V_109 = F_54 ( V_4 -> V_105 . V_104 , V_103 ) ;
}
}
bool F_55 ( struct V_3 * V_4 )
{
if ( F_47 ( V_4 ) )
return true ;
if ( V_4 -> V_112 ) {
F_19 ( L_13 ) ;
if ( V_4 -> V_113 )
F_56 ( V_4 -> V_114 . V_115 ) ;
else
F_57 ( V_4 -> V_116 ) ;
return true ;
} else {
F_58 ( V_4 -> V_2 , L_14 ) ;
return false ;
}
}
int F_59 ( struct V_3 * V_4 )
{
if ( V_4 -> V_117 . V_118 )
return 0 ;
V_4 -> V_117 . V_118 = F_60 ( V_119 | V_120 | V_121 ) ;
if ( V_4 -> V_117 . V_118 == NULL )
return - V_48 ;
V_4 -> V_117 . V_122 = F_61 ( V_4 -> V_12 , V_4 -> V_117 . V_118 ,
0 , V_59 , V_123 ) ;
if ( F_62 ( V_4 -> V_12 , V_4 -> V_117 . V_122 ) ) {
F_58 ( & V_4 -> V_12 -> V_2 , L_15 ) ;
F_63 ( V_4 -> V_117 . V_118 ) ;
V_4 -> V_117 . V_118 = NULL ;
return - V_48 ;
}
V_4 -> V_117 . V_124 = F_64 ( V_4 -> V_117 . V_122 ,
V_125 ) ;
return 0 ;
}
void F_65 ( struct V_3 * V_4 )
{
if ( V_4 -> V_117 . V_118 == NULL )
return;
F_66 ( V_4 -> V_12 , V_4 -> V_117 . V_122 ,
V_59 , V_123 ) ;
F_63 ( V_4 -> V_117 . V_118 ) ;
V_4 -> V_117 . V_118 = NULL ;
}
static T_2 F_67 ( struct V_126 * V_127 , T_2 V_25 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = V_4 -> V_128 ( V_4 , V_25 ) ;
return V_57 ;
}
static void F_68 ( struct V_126 * V_127 , T_2 V_25 , T_2 V_129 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
V_4 -> V_130 ( V_4 , V_25 , V_129 ) ;
}
static T_2 F_69 ( struct V_126 * V_127 , T_2 V_25 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = V_4 -> V_131 ( V_4 , V_25 ) ;
return V_57 ;
}
static void F_70 ( struct V_126 * V_127 , T_2 V_25 , T_2 V_129 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
V_4 -> V_132 ( V_4 , V_25 , V_129 ) ;
}
static void F_71 ( struct V_126 * V_127 , T_2 V_25 , T_2 V_129 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
F_5 ( V_25 * 4 , V_129 ) ;
}
static T_2 F_72 ( struct V_126 * V_127 , T_2 V_25 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = F_4 ( V_25 * 4 ) ;
return V_57 ;
}
static void F_73 ( struct V_126 * V_127 , T_2 V_25 , T_2 V_129 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
F_74 ( V_25 * 4 , V_129 ) ;
}
static T_2 F_75 ( struct V_126 * V_127 , T_2 V_25 )
{
struct V_3 * V_4 = V_127 -> V_2 -> V_5 ;
T_2 V_57 ;
V_57 = F_76 ( V_25 * 4 ) ;
return V_57 ;
}
int F_77 ( struct V_3 * V_4 )
{
struct V_126 * V_133 =
F_78 ( sizeof( struct V_126 ) , V_120 ) ;
if ( ! V_133 )
return - V_48 ;
V_4 -> V_114 . V_133 = V_133 ;
V_133 -> V_2 = V_4 -> V_116 ;
V_133 -> V_134 = F_72 ;
V_133 -> V_135 = F_71 ;
if ( V_4 -> V_136 ) {
V_133 -> V_137 = F_75 ;
V_133 -> V_138 = F_73 ;
} else {
F_79 ( L_16 ) ;
V_133 -> V_137 = F_72 ;
V_133 -> V_138 = F_71 ;
}
V_133 -> V_139 = F_69 ;
V_133 -> V_140 = F_70 ;
V_133 -> V_141 = F_67 ;
V_133 -> V_142 = F_68 ;
V_4 -> V_114 . V_115 = F_80 ( V_133 , V_4 -> V_112 ) ;
if ( ! V_4 -> V_114 . V_115 ) {
F_81 ( V_4 ) ;
return - V_48 ;
}
F_82 ( & V_4 -> V_114 . V_115 -> V_143 ) ;
F_82 ( & V_4 -> V_114 . V_115 -> V_144 ) ;
F_83 ( V_4 -> V_116 ) ;
F_84 ( V_4 -> V_114 . V_115 ) ;
return 0 ;
}
void F_81 ( struct V_3 * V_4 )
{
if ( V_4 -> V_114 . V_115 ) {
F_85 ( V_4 -> V_114 . V_115 -> V_37 ) ;
}
F_85 ( V_4 -> V_114 . V_115 ) ;
V_4 -> V_114 . V_115 = NULL ;
F_85 ( V_4 -> V_114 . V_133 ) ;
V_4 -> V_114 . V_133 = NULL ;
}
int F_86 ( struct V_3 * V_4 )
{
F_87 ( V_4 -> V_116 ) ;
return 0 ;
}
void F_88 ( struct V_3 * V_4 )
{
}
static unsigned int F_89 ( void * V_145 , bool V_146 )
{
struct V_3 * V_4 = V_145 ;
F_90 ( V_4 , V_146 ) ;
if ( V_146 )
return V_147 | V_148 |
V_149 | V_150 ;
else
return V_149 | V_150 ;
}
static bool F_91 ( int V_151 )
{
return ( V_151 & ( V_151 - 1 ) ) == 0 ;
}
static int F_92 ( enum V_152 V_30 )
{
if ( V_30 >= V_153 )
return 2048 ;
else if ( V_30 >= V_154 )
return 1024 ;
else
return 512 ;
}
static void F_93 ( struct V_3 * V_4 )
{
if ( ! F_91 ( V_69 ) ) {
F_37 ( V_4 -> V_2 , L_17 ,
V_69 ) ;
V_69 = 0 ;
}
if ( V_155 == - 1 ) {
V_155 = F_92 ( V_4 -> V_30 ) ;
}
if ( V_155 < 32 ) {
F_37 ( V_4 -> V_2 , L_18 ,
V_155 ) ;
V_155 = F_92 ( V_4 -> V_30 ) ;
} else if ( ! F_91 ( V_155 ) ) {
F_37 ( V_4 -> V_2 , L_19 ,
V_155 ) ;
V_155 = F_92 ( V_4 -> V_30 ) ;
}
V_4 -> V_67 . V_81 = ( T_6 ) V_155 << 20 ;
switch ( V_156 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_37 ( V_4 -> V_2 , L_20
L_21 , V_156 ) ;
V_156 = 0 ;
break;
}
if ( ! F_91 ( V_157 ) ) {
F_37 ( V_4 -> V_2 , L_22 ,
V_157 ) ;
V_157 = 4 ;
}
if ( V_157 < 1 ) {
F_37 ( V_4 -> V_2 , L_23 ,
V_157 ) ;
V_157 = 4 ;
}
if ( V_157 > 1024 ) {
F_37 ( V_4 -> V_2 , L_24 ,
V_157 ) ;
V_157 = 4 ;
}
if ( V_158 == - 1 ) {
unsigned V_159 = F_94 ( V_157 ) + 18 ;
if ( V_157 <= 8 )
V_158 = V_159 - 9 ;
else
V_158 = ( V_159 + 3 ) / 2 ;
} else if ( V_158 < 9 ) {
F_37 ( V_4 -> V_2 , L_25 ,
V_158 ) ;
V_158 = 9 ;
}
if ( V_158 > 24 ||
( V_157 * 1024 ) < ( 1ull << V_158 ) ) {
F_37 ( V_4 -> V_2 , L_26 ,
V_158 ) ;
V_158 = 9 ;
}
}
static void F_95 ( struct V_160 * V_12 , enum V_161 V_146 )
{
struct V_1 * V_2 = F_96 ( V_12 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_1 ( V_2 ) && V_146 == V_162 )
return;
if ( V_146 == V_163 ) {
unsigned V_164 = V_2 -> V_12 -> V_164 ;
F_97 ( V_165 L_27 ) ;
V_2 -> V_166 = V_167 ;
if ( V_164 < 20 && ( V_4 -> V_20 & V_168 ) )
V_2 -> V_12 -> V_164 = 20 ;
F_98 ( V_2 , true , true ) ;
V_2 -> V_12 -> V_164 = V_164 ;
V_2 -> V_166 = V_169 ;
F_99 ( V_2 ) ;
} else {
F_97 ( V_165 L_28 ) ;
F_100 ( V_2 ) ;
V_2 -> V_166 = V_167 ;
F_101 ( V_2 , true , true , false ) ;
V_2 -> V_166 = V_170 ;
}
}
static bool F_102 ( struct V_160 * V_12 )
{
struct V_1 * V_2 = F_96 ( V_12 ) ;
return V_2 -> V_171 == 0 ;
}
int F_103 ( struct V_3 * V_4 ,
struct V_1 * V_116 ,
struct V_160 * V_12 ,
T_2 V_6 )
{
int V_57 , V_28 ;
int V_172 ;
bool V_173 = false ;
V_4 -> V_174 = false ;
V_4 -> V_2 = & V_12 -> V_2 ;
V_4 -> V_116 = V_116 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_30 = V_6 & V_175 ;
V_4 -> V_113 = false ;
V_4 -> V_176 = V_177 ;
V_4 -> V_67 . V_81 = 512 * 1024 * 1024 ;
V_4 -> V_178 = false ;
for ( V_28 = 0 ; V_28 < V_179 ; V_28 ++ ) {
V_4 -> V_180 [ V_28 ] . V_181 = V_28 ;
}
V_4 -> V_182 = F_104 ( V_179 ) ;
F_19 ( L_29 ,
V_183 [ V_4 -> V_30 ] , V_12 -> V_13 , V_12 -> V_15 ,
V_12 -> V_16 , V_12 -> V_18 , V_12 -> V_184 ) ;
F_82 ( & V_4 -> V_185 ) ;
F_82 ( & V_4 -> V_186 ) ;
F_105 ( & V_4 -> V_187 . V_188 , 0 ) ;
F_82 ( & V_4 -> V_189 . V_143 ) ;
F_82 ( & V_4 -> V_105 . V_143 ) ;
F_82 ( & V_4 -> V_190 ) ;
F_82 ( & V_4 -> V_191 ) ;
F_82 ( & V_4 -> V_192 ) ;
F_106 ( & V_4 -> V_105 . V_193 ) ;
F_106 ( & V_4 -> V_194 ) ;
F_107 ( & V_4 -> V_195 . V_196 ) ;
F_82 ( & V_4 -> V_197 ) ;
F_108 ( V_4 -> V_198 ) ;
V_57 = F_109 ( V_4 ) ;
if ( V_57 )
return V_57 ;
F_93 ( V_4 ) ;
V_4 -> V_199 . V_200 = V_157 << 18 ;
V_57 = F_110 ( V_4 ) ;
if ( V_57 )
return V_57 ;
if ( ( V_4 -> V_30 >= V_201 ) &&
( V_4 -> V_6 & V_110 ) ) {
V_4 -> V_6 &= ~ V_64 ;
}
if ( V_4 -> V_6 & V_64 && V_156 == - 1 ) {
F_111 ( V_4 ) ;
}
if ( V_4 -> V_30 >= V_202 )
V_4 -> V_67 . V_72 = 0xffffffffffULL ;
else if ( V_4 -> V_30 >= V_203 )
V_4 -> V_67 . V_72 = 0xfffffffffULL ;
else
V_4 -> V_67 . V_72 = 0xffffffffULL ;
V_4 -> V_204 = false ;
if ( V_4 -> V_6 & V_64 )
V_4 -> V_204 = true ;
if ( ( V_4 -> V_6 & V_205 ) &&
( V_4 -> V_30 <= V_206 ) )
V_4 -> V_204 = true ;
V_172 = V_4 -> V_204 ? 32 : 40 ;
V_57 = F_112 ( V_4 -> V_12 , F_113 ( V_172 ) ) ;
if ( V_57 ) {
V_4 -> V_204 = true ;
V_172 = 32 ;
F_97 ( V_207 L_30 ) ;
}
V_57 = F_114 ( V_4 -> V_12 , F_113 ( V_172 ) ) ;
if ( V_57 ) {
F_114 ( V_4 -> V_12 , F_113 ( 32 ) ) ;
F_97 ( V_207 L_31 ) ;
}
F_115 ( & V_4 -> V_208 ) ;
F_115 ( & V_4 -> V_209 ) ;
F_115 ( & V_4 -> V_210 ) ;
F_115 ( & V_4 -> V_211 ) ;
F_115 ( & V_4 -> V_212 ) ;
F_115 ( & V_4 -> V_213 ) ;
F_115 ( & V_4 -> V_214 ) ;
F_115 ( & V_4 -> V_215 ) ;
F_115 ( & V_4 -> V_216 ) ;
F_115 ( & V_4 -> V_217 ) ;
F_115 ( & V_4 -> V_218 ) ;
F_115 ( & V_4 -> V_219 ) ;
if ( V_4 -> V_30 >= V_220 ) {
V_4 -> V_221 = F_15 ( V_4 -> V_12 , 5 ) ;
V_4 -> V_222 = F_16 ( V_4 -> V_12 , 5 ) ;
} else {
V_4 -> V_221 = F_15 ( V_4 -> V_12 , 2 ) ;
V_4 -> V_222 = F_16 ( V_4 -> V_12 , 2 ) ;
}
V_4 -> V_223 = F_18 ( V_4 -> V_221 , V_4 -> V_222 ) ;
if ( V_4 -> V_223 == NULL ) {
return - V_48 ;
}
F_19 ( L_32 , ( T_2 ) V_4 -> V_221 ) ;
F_19 ( L_33 , ( unsigned ) V_4 -> V_222 ) ;
if ( V_4 -> V_30 >= V_220 )
F_14 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_224 ; V_28 ++ ) {
if ( F_116 ( V_4 -> V_12 , V_28 ) & V_225 ) {
V_4 -> V_226 = F_16 ( V_4 -> V_12 , V_28 ) ;
V_4 -> V_136 = F_117 ( V_4 -> V_12 , V_28 , V_4 -> V_226 ) ;
break;
}
}
if ( V_4 -> V_136 == NULL )
F_79 ( L_34 ) ;
if ( V_4 -> V_6 & V_7 )
F_2 ( V_4 ) ;
F_118 ( V_4 -> V_12 , V_4 , NULL , F_89 ) ;
if ( V_4 -> V_6 & V_7 )
V_173 = true ;
F_119 ( V_4 -> V_12 , & V_227 , V_173 ) ;
if ( V_173 )
F_120 ( V_4 -> V_2 , & V_4 -> V_228 ) ;
V_57 = F_121 ( V_4 ) ;
if ( V_57 )
goto V_229;
V_57 = F_122 ( V_4 ) ;
if ( V_57 ) {
F_79 ( L_35 , V_57 ) ;
}
V_57 = F_123 ( V_4 ) ;
if ( V_57 ) {
F_79 ( L_36 , V_57 ) ;
}
if ( V_4 -> V_6 & V_64 && ! V_4 -> V_178 ) {
F_124 ( V_4 ) ;
F_125 ( V_4 ) ;
F_111 ( V_4 ) ;
V_57 = F_121 ( V_4 ) ;
if ( V_57 )
goto V_229;
}
V_57 = F_126 ( V_4 ) ;
if ( V_57 )
F_79 ( L_37 , V_57 ) ;
if ( V_4 -> V_105 . V_230 &&
( V_4 -> V_105 . V_231 == V_232 ) &&
( V_4 -> V_30 == V_233 ) &&
( V_4 -> V_6 & V_234 ) ) {
F_127 ( & V_4 -> V_105 . V_143 ) ;
F_128 ( V_4 ) ;
F_129 ( V_4 ) ;
F_130 ( & V_4 -> V_105 . V_143 ) ;
}
if ( ( V_235 & 1 ) ) {
if ( V_4 -> V_178 )
F_131 ( V_4 ) ;
else
F_19 ( L_38 ) ;
}
if ( ( V_235 & 2 ) ) {
if ( V_4 -> V_178 )
F_132 ( V_4 ) ;
else
F_19 ( L_39 ) ;
}
if ( V_236 ) {
if ( V_4 -> V_178 )
F_133 ( V_4 , V_236 ) ;
else
F_19 ( L_40 ) ;
}
return 0 ;
V_229:
if ( F_1 ( V_116 ) )
F_134 ( V_116 -> V_2 ) ;
if ( V_173 )
F_135 ( V_4 -> V_2 ) ;
return V_57 ;
}
void F_136 ( struct V_3 * V_4 )
{
F_19 ( L_41 ) ;
V_4 -> V_174 = true ;
F_137 ( V_4 ) ;
F_125 ( V_4 ) ;
F_138 ( V_4 -> V_12 ) ;
if ( V_4 -> V_6 & V_7 )
F_135 ( V_4 -> V_2 ) ;
F_118 ( V_4 -> V_12 , NULL , NULL , NULL ) ;
if ( V_4 -> V_136 )
F_139 ( V_4 -> V_12 , V_4 -> V_136 ) ;
V_4 -> V_136 = NULL ;
F_21 ( V_4 -> V_223 ) ;
V_4 -> V_223 = NULL ;
if ( V_4 -> V_30 >= V_220 )
F_20 ( V_4 ) ;
F_140 ( V_4 ) ;
}
int F_101 ( struct V_1 * V_2 , bool V_237 ,
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
if ( V_2 -> V_166 == V_170 )
return 0 ;
F_100 ( V_2 ) ;
F_141 ( V_2 ) ;
F_142 (connector, &dev->mode_config.connector_list, head) {
F_143 ( V_243 , V_245 ) ;
}
F_144 ( V_2 ) ;
F_142 (crtc, &dev->mode_config.crtc_list, head) {
struct V_246 * V_246 = F_145 ( V_241 ) ;
struct V_247 * V_248 = F_146 ( V_241 -> V_249 -> V_250 ) ;
struct V_251 * V_252 ;
if ( V_246 -> V_253 ) {
struct V_251 * V_252 = F_147 ( V_246 -> V_253 ) ;
V_57 = F_30 ( V_252 , false ) ;
if ( V_57 == 0 ) {
F_32 ( V_252 ) ;
F_33 ( V_252 ) ;
}
}
if ( V_248 == NULL || V_248 -> V_254 == NULL ) {
continue;
}
V_252 = F_147 ( V_248 -> V_254 ) ;
if ( ! F_148 ( V_4 , V_252 ) ) {
V_57 = F_30 ( V_252 , false ) ;
if ( V_57 == 0 ) {
F_32 ( V_252 ) ;
F_33 ( V_252 ) ;
}
}
}
F_137 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_179 ; V_28 ++ ) {
V_57 = F_149 ( V_4 , V_28 ) ;
if ( V_57 ) {
F_150 ( V_4 , V_28 ) ;
}
}
F_151 ( V_4 ) ;
F_152 ( V_4 ) ;
F_153 ( V_4 ) ;
F_137 ( V_4 ) ;
F_154 ( V_4 ) ;
F_155 ( V_2 -> V_12 ) ;
if ( V_239 && V_4 -> V_30 >= V_203 ) {
V_4 -> V_255 -> V_256 ( V_4 , true ) ;
F_156 ( V_2 -> V_12 ) ;
} else if ( V_237 ) {
F_157 ( V_2 -> V_12 ) ;
F_158 ( V_2 -> V_12 , V_257 ) ;
}
if ( V_238 ) {
F_159 () ;
F_160 ( V_4 , 1 ) ;
F_161 () ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 , bool V_258 , bool V_238 )
{
struct V_242 * V_243 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_240 * V_241 ;
int V_57 ;
if ( V_2 -> V_166 == V_170 )
return 0 ;
if ( V_238 ) {
F_159 () ;
}
if ( V_258 ) {
F_158 ( V_2 -> V_12 , V_259 ) ;
F_156 ( V_2 -> V_12 ) ;
if ( F_162 ( V_2 -> V_12 ) ) {
if ( V_238 )
F_161 () ;
return - 1 ;
}
}
F_163 ( V_4 ) ;
F_164 ( V_4 ) ;
V_57 = F_126 ( V_4 ) ;
if ( V_57 )
F_79 ( L_37 , V_57 ) ;
if ( ( V_4 -> V_105 . V_231 == V_232 ) && V_4 -> V_105 . V_230 ) {
V_57 = F_165 ( V_4 ) ;
if ( V_57 ) {
V_4 -> V_105 . V_230 = false ;
F_79 ( L_42 ) ;
}
} else {
F_166 ( V_4 ) ;
}
F_167 ( V_4 ) ;
F_142 (crtc, &dev->mode_config.crtc_list, head) {
struct V_246 * V_246 = F_145 ( V_241 ) ;
if ( V_246 -> V_253 ) {
struct V_251 * V_252 = F_147 ( V_246 -> V_253 ) ;
V_57 = F_30 ( V_252 , false ) ;
if ( V_57 == 0 ) {
V_57 = F_168 ( V_252 ,
V_260 ,
F_51 ( V_4 ) ?
0 : 1 << 27 ,
& V_246 -> V_261 ) ;
if ( V_57 != 0 )
F_79 ( L_43 , V_57 ) ;
F_33 ( V_252 ) ;
}
}
}
if ( V_4 -> V_113 ) {
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
if ( V_4 -> V_114 . V_262 ) {
T_8 V_263 = F_171 ( V_4 ,
V_4 -> V_114 . V_262 ) ;
F_172 ( V_4 , V_4 -> V_114 . V_262 ,
V_263 ) ;
}
}
F_173 ( V_4 ) ;
if ( V_238 ) {
F_174 ( V_2 ) ;
F_141 ( V_2 ) ;
F_142 (connector, &dev->mode_config.connector_list, head) {
F_143 ( V_243 , V_264 ) ;
}
F_144 ( V_2 ) ;
}
F_99 ( V_2 ) ;
if ( ( V_4 -> V_105 . V_231 == V_232 ) && V_4 -> V_105 . V_230 )
F_175 ( V_4 ) ;
if ( V_238 ) {
F_160 ( V_4 , 0 ) ;
F_161 () ;
}
return 0 ;
}
int F_176 ( struct V_3 * V_4 )
{
unsigned V_265 [ V_179 ] ;
T_2 * V_266 [ V_179 ] ;
bool V_267 = false ;
int V_28 , V_57 ;
int V_268 ;
F_177 ( & V_4 -> V_194 ) ;
if ( ! V_4 -> V_269 ) {
F_178 ( & V_4 -> V_194 ) ;
return 0 ;
}
F_179 ( & V_4 -> V_270 ) ;
F_151 ( V_4 ) ;
V_268 = F_180 ( & V_4 -> V_271 . V_272 ) ;
F_152 ( V_4 ) ;
F_153 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_179 ; ++ V_28 ) {
V_265 [ V_28 ] = F_181 ( V_4 , & V_4 -> V_180 [ V_28 ] ,
& V_266 [ V_28 ] ) ;
if ( V_265 [ V_28 ] ) {
V_267 = true ;
F_41 ( V_4 -> V_2 , L_44
L_45 , V_265 [ V_28 ] , V_28 ) ;
}
}
V_57 = F_124 ( V_4 ) ;
if ( ! V_57 ) {
F_41 ( V_4 -> V_2 , L_46 ) ;
F_164 ( V_4 ) ;
}
F_167 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_179 ; ++ V_28 ) {
if ( ! V_57 && V_266 [ V_28 ] ) {
F_182 ( V_4 , & V_4 -> V_180 [ V_28 ] ,
V_265 [ V_28 ] , V_266 [ V_28 ] ) ;
} else {
F_150 ( V_4 , V_28 ) ;
F_85 ( V_266 [ V_28 ] ) ;
}
}
if ( ( V_4 -> V_105 . V_231 == V_232 ) && V_4 -> V_105 . V_230 ) {
V_57 = F_165 ( V_4 ) ;
if ( V_57 ) {
V_4 -> V_105 . V_230 = false ;
F_79 ( L_42 ) ;
}
} else {
F_166 ( V_4 ) ;
}
if ( V_4 -> V_113 ) {
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
if ( V_4 -> V_114 . V_262 ) {
T_8 V_263 = F_171 ( V_4 ,
V_4 -> V_114 . V_262 ) ;
F_172 ( V_4 , V_4 -> V_114 . V_262 ,
V_263 ) ;
}
}
F_173 ( V_4 ) ;
F_183 ( & V_4 -> V_271 . V_272 , V_268 ) ;
V_4 -> V_273 = true ;
V_4 -> V_269 = false ;
F_184 ( & V_4 -> V_194 ) ;
F_174 ( V_4 -> V_116 ) ;
if ( ( V_4 -> V_105 . V_231 == V_232 ) && V_4 -> V_105 . V_230 )
F_175 ( V_4 ) ;
if ( ! V_57 ) {
V_57 = F_126 ( V_4 ) ;
if ( V_57 && V_267 )
V_57 = - V_274 ;
} else {
F_41 ( V_4 -> V_2 , L_47 ) ;
}
V_4 -> V_269 = V_57 == - V_274 ;
V_4 -> V_273 = false ;
F_185 ( & V_4 -> V_194 ) ;
return V_57 ;
}
int F_186 ( struct V_3 * V_4 ,
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
F_79 ( L_48 ) ;
F_79 ( L_49
L_50 ) ;
return - V_41 ;
}
V_4 -> V_279 [ V_4 -> V_278 ] . V_276 = V_276 ;
V_4 -> V_279 [ V_4 -> V_278 ] . V_281 = V_277 ;
V_4 -> V_278 = V_28 ;
#if F_187 ( V_282 )
F_188 ( V_276 , V_277 ,
V_4 -> V_116 -> V_283 -> V_284 ,
V_4 -> V_116 -> V_283 ) ;
F_188 ( V_276 , V_277 ,
V_4 -> V_116 -> V_249 -> V_284 ,
V_4 -> V_116 -> V_249 ) ;
#endif
return 0 ;
}
static void F_140 ( struct V_3 * V_4 )
{
#if F_187 ( V_282 )
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_278 ; V_28 ++ ) {
F_189 ( V_4 -> V_279 [ V_28 ] . V_276 ,
V_4 -> V_279 [ V_28 ] . V_281 ,
V_4 -> V_116 -> V_283 ) ;
F_189 ( V_4 -> V_279 [ V_28 ] . V_276 ,
V_4 -> V_279 [ V_28 ] . V_281 ,
V_4 -> V_116 -> V_249 ) ;
}
#endif
}
int F_190 ( struct V_285 * V_286 )
{
return 0 ;
}
void F_191 ( struct V_285 * V_286 )
{
}
