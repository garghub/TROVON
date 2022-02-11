void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
const T_1 V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
int V_9 ;
if ( V_4 % 3 )
return;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 3 ) {
V_6 = V_3 [ V_9 + 0 ] ;
V_7 = V_3 [ V_9 + 1 ] ;
V_8 = V_3 [ V_9 + 2 ] ;
if ( V_7 == 0xffffffff ) {
V_5 = V_8 ;
} else {
V_5 = F_2 ( V_6 ) ;
V_5 &= ~ V_7 ;
V_5 |= V_8 ;
}
F_3 ( V_6 , V_5 ) ;
}
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 < V_11 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( V_2 -> V_13 [ V_9 ] . V_14 )
F_5 ( V_2 -> V_13 [ V_9 ] . V_14 ) ;
else
F_6 ( V_2 , V_9 ) ;
}
F_3 ( V_15 , 0 ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_10 < V_16 ) {
V_2 -> V_17 . V_18 = 5 ;
} else {
V_2 -> V_17 . V_18 = 7 ;
}
V_2 -> V_17 . V_19 = V_20 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
V_2 -> V_17 . free [ V_9 ] = true ;
V_2 -> V_17 . V_6 [ V_9 ] = V_2 -> V_17 . V_19 + ( V_9 * 4 ) ;
}
}
int F_8 ( struct V_1 * V_2 , T_2 * V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
if ( V_2 -> V_17 . free [ V_9 ] ) {
V_2 -> V_17 . free [ V_9 ] = false ;
* V_6 = V_2 -> V_17 . V_6 [ V_9 ] ;
return 0 ;
}
}
return - V_21 ;
}
void F_9 ( struct V_1 * V_2 , T_2 V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
if ( V_2 -> V_17 . V_6 [ V_9 ] == V_6 ) {
V_2 -> V_17 . free [ V_9 ] = true ;
return;
}
}
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = false ;
}
void F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
if ( V_2 -> V_22 . V_24 ) {
if ( ! F_12 ( V_2 -> V_22 . V_24 , false ) ) {
F_13 ( V_2 -> V_22 . V_24 ) ;
F_14 ( V_2 -> V_22 . V_24 ) ;
F_15 ( V_2 -> V_22 . V_24 ) ;
}
F_16 ( & V_2 -> V_22 . V_24 ) ;
V_2 -> V_22 . V_22 = NULL ;
V_2 -> V_22 . V_24 = NULL ;
}
}
int F_17 ( struct V_1 * V_2 )
{
int V_25 ;
if ( V_2 -> V_22 . V_24 == NULL ) {
V_25 = F_18 ( V_2 , V_26 , V_27 , true ,
V_28 , NULL , & V_2 -> V_22 . V_24 ) ;
if ( V_25 ) {
F_19 ( V_2 -> V_29 , L_1 , V_25 ) ;
return V_25 ;
}
V_25 = F_12 ( V_2 -> V_22 . V_24 , false ) ;
if ( F_20 ( V_25 != 0 ) ) {
F_11 ( V_2 ) ;
return V_25 ;
}
V_25 = F_21 ( V_2 -> V_22 . V_24 , V_28 ,
& V_2 -> V_22 . V_30 ) ;
if ( V_25 ) {
F_15 ( V_2 -> V_22 . V_24 ) ;
F_19 ( V_2 -> V_29 , L_2 , V_25 ) ;
F_11 ( V_2 ) ;
return V_25 ;
}
V_25 = F_22 ( V_2 -> V_22 . V_24 , ( void * * ) & V_2 -> V_22 . V_22 ) ;
F_15 ( V_2 -> V_22 . V_24 ) ;
if ( V_25 ) {
F_19 ( V_2 -> V_29 , L_3 , V_25 ) ;
F_11 ( V_2 ) ;
return V_25 ;
}
}
memset ( ( char * ) V_2 -> V_22 . V_22 , 0 , V_26 ) ;
V_2 -> V_22 . V_31 = false ;
if ( V_32 == 1 ) {
V_2 -> V_22 . V_23 = false ;
} else {
if ( V_2 -> V_33 & V_34 ) {
V_2 -> V_22 . V_23 = false ;
} else if ( V_2 -> V_10 < V_16 ) {
V_2 -> V_22 . V_23 = false ;
} else {
V_2 -> V_22 . V_23 = true ;
if ( V_2 -> V_10 >= V_11 ) {
V_2 -> V_22 . V_31 = true ;
}
}
}
if ( V_2 -> V_10 >= V_35 ) {
V_2 -> V_22 . V_23 = true ;
V_2 -> V_22 . V_31 = true ;
}
F_23 ( V_2 -> V_29 , L_4 , V_2 -> V_22 . V_23 ? L_5 : L_6 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 , struct V_36 * V_37 , T_3 V_38 )
{
T_4 V_39 = ( T_4 ) V_40 << 20 ;
V_37 -> V_41 = V_38 ;
if ( V_37 -> V_42 > ( V_2 -> V_37 . V_43 - V_38 + 1 ) ) {
F_19 ( V_2 -> V_29 , L_7 ) ;
V_37 -> V_44 = V_37 -> V_45 ;
V_37 -> V_42 = V_37 -> V_45 ;
}
V_37 -> V_46 = V_37 -> V_41 + V_37 -> V_42 - 1 ;
if ( V_2 -> V_33 & V_34 && V_37 -> V_46 > V_37 -> V_47 && V_37 -> V_41 <= V_37 -> V_48 ) {
F_19 ( V_2 -> V_29 , L_7 ) ;
V_37 -> V_44 = V_37 -> V_45 ;
V_37 -> V_42 = V_37 -> V_45 ;
}
V_37 -> V_46 = V_37 -> V_41 + V_37 -> V_42 - 1 ;
if ( V_39 && V_39 < V_37 -> V_44 )
V_37 -> V_44 = V_39 ;
F_23 ( V_2 -> V_29 , L_8 ,
V_37 -> V_42 >> 20 , V_37 -> V_41 ,
V_37 -> V_46 , V_37 -> V_44 >> 20 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
T_3 V_49 , V_50 ;
V_49 = ( ( V_2 -> V_37 . V_43 - V_37 -> V_46 ) + V_37 -> V_51 ) & ~ V_37 -> V_51 ;
V_50 = V_37 -> V_41 & ~ V_37 -> V_51 ;
if ( V_50 > V_49 ) {
if ( V_37 -> V_52 > V_50 ) {
F_19 ( V_2 -> V_29 , L_9 ) ;
V_37 -> V_52 = V_50 ;
}
V_37 -> V_47 = ( V_37 -> V_41 & ~ V_37 -> V_51 ) - V_37 -> V_52 ;
} else {
if ( V_37 -> V_52 > V_49 ) {
F_19 ( V_2 -> V_29 , L_9 ) ;
V_37 -> V_52 = V_49 ;
}
V_37 -> V_47 = ( V_37 -> V_46 + 1 + V_37 -> V_51 ) & ~ V_37 -> V_51 ;
}
V_37 -> V_48 = V_37 -> V_47 + V_37 -> V_52 - 1 ;
F_23 ( V_2 -> V_29 , L_10 ,
V_37 -> V_52 >> 20 , V_37 -> V_47 , V_37 -> V_48 ) ;
}
bool F_26 ( struct V_1 * V_2 )
{
T_2 V_6 ;
if ( F_27 ( V_53 ) &&
( V_2 -> V_54 -> V_55 == V_56 ) &&
( V_2 -> V_10 < V_11 ) )
return false ;
if ( F_28 ( V_2 ) )
goto V_57;
if ( F_29 ( V_2 ) ) {
V_6 = F_2 ( V_58 + V_59 ) |
F_2 ( V_58 + V_60 ) ;
if ( V_2 -> V_61 >= 4 ) {
V_6 |= F_2 ( V_58 + V_62 ) |
F_2 ( V_58 + V_63 ) ;
}
if ( V_2 -> V_61 >= 6 ) {
V_6 |= F_2 ( V_58 + V_64 ) |
F_2 ( V_58 + V_65 ) ;
}
if ( V_6 & V_66 )
return true ;
} else if ( F_30 ( V_2 ) ) {
V_6 = F_2 ( V_67 ) |
F_2 ( V_68 ) ;
if ( V_6 & V_69 ) {
return true ;
}
} else {
V_6 = F_2 ( V_70 ) |
F_2 ( V_71 ) ;
if ( V_6 & V_72 ) {
return true ;
}
}
V_57:
if ( V_2 -> V_10 >= V_11 )
V_6 = F_2 ( V_73 ) ;
else
V_6 = F_2 ( V_74 ) ;
if ( V_6 )
return true ;
return false ;
}
void F_31 ( struct V_1 * V_2 )
{
T_5 V_75 ;
T_1 V_76 = V_2 -> V_77 . V_78 ;
T_1 V_79 = V_2 -> V_77 . V_80 ;
V_75 . V_81 = F_32 ( 100 ) ;
V_2 -> V_77 . V_76 . V_81 = F_32 ( V_76 ) ;
V_2 -> V_77 . V_76 . V_81 = F_33 ( V_2 -> V_77 . V_76 , V_75 ) ;
V_2 -> V_77 . V_79 . V_81 = F_32 ( V_79 ) ;
V_2 -> V_77 . V_79 . V_81 = F_33 ( V_2 -> V_77 . V_79 , V_75 ) ;
if ( V_2 -> V_33 & V_82 ) {
V_75 . V_81 = F_32 ( 16 ) ;
V_2 -> V_77 . V_83 . V_81 = F_33 ( V_2 -> V_77 . V_76 , V_75 ) ;
}
}
bool F_34 ( struct V_1 * V_2 )
{
if ( F_26 ( V_2 ) )
return true ;
if ( V_2 -> V_84 ) {
F_35 ( L_11 ) ;
if ( V_2 -> V_85 )
F_36 ( V_2 -> V_86 . V_87 ) ;
else
F_37 ( V_2 -> V_88 ) ;
return true ;
} else {
F_38 ( V_2 -> V_29 , L_12 ) ;
return false ;
}
}
int F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 . V_90 )
return 0 ;
V_2 -> V_89 . V_90 = F_40 ( V_91 | V_92 | V_93 ) ;
if ( V_2 -> V_89 . V_90 == NULL )
return - V_94 ;
V_2 -> V_89 . V_95 = F_41 ( V_2 -> V_54 , V_2 -> V_89 . V_90 ,
0 , V_27 , V_96 ) ;
if ( F_42 ( V_2 -> V_54 , V_2 -> V_89 . V_95 ) ) {
F_38 ( & V_2 -> V_54 -> V_29 , L_13 ) ;
F_43 ( V_2 -> V_89 . V_90 ) ;
V_2 -> V_89 . V_90 = NULL ;
return - V_94 ;
}
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 . V_90 == NULL )
return;
F_45 ( V_2 -> V_54 , V_2 -> V_89 . V_95 ,
V_27 , V_96 ) ;
F_43 ( V_2 -> V_89 . V_90 ) ;
V_2 -> V_89 . V_90 = NULL ;
}
static T_2 F_46 ( struct V_97 * V_98 , T_2 V_6 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
T_2 V_25 ;
V_25 = V_2 -> V_100 ( V_2 , V_6 ) ;
return V_25 ;
}
static void F_47 ( struct V_97 * V_98 , T_2 V_6 , T_2 V_101 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
V_2 -> V_102 ( V_2 , V_6 , V_101 ) ;
}
static T_2 F_48 ( struct V_97 * V_98 , T_2 V_6 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
T_2 V_25 ;
V_25 = V_2 -> V_103 ( V_2 , V_6 ) ;
return V_25 ;
}
static void F_49 ( struct V_97 * V_98 , T_2 V_6 , T_2 V_101 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
V_2 -> V_104 ( V_2 , V_6 , V_101 ) ;
}
static void F_50 ( struct V_97 * V_98 , T_2 V_6 , T_2 V_101 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
F_3 ( V_6 * 4 , V_101 ) ;
}
static T_2 F_51 ( struct V_97 * V_98 , T_2 V_6 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
T_2 V_25 ;
V_25 = F_2 ( V_6 * 4 ) ;
return V_25 ;
}
static void F_52 ( struct V_97 * V_98 , T_2 V_6 , T_2 V_101 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
F_53 ( V_6 * 4 , V_101 ) ;
}
static T_2 F_54 ( struct V_97 * V_98 , T_2 V_6 )
{
struct V_1 * V_2 = V_98 -> V_29 -> V_99 ;
T_2 V_25 ;
V_25 = F_55 ( V_6 * 4 ) ;
return V_25 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_97 * V_105 =
F_57 ( sizeof( struct V_97 ) , V_92 ) ;
if ( ! V_105 )
return - V_94 ;
V_2 -> V_86 . V_105 = V_105 ;
V_105 -> V_29 = V_2 -> V_88 ;
V_105 -> V_106 = F_51 ;
V_105 -> V_107 = F_50 ;
if ( V_2 -> V_108 ) {
V_105 -> V_109 = F_54 ;
V_105 -> V_110 = F_52 ;
} else {
F_58 ( L_14 ) ;
V_105 -> V_109 = F_51 ;
V_105 -> V_110 = F_50 ;
}
V_105 -> V_111 = F_48 ;
V_105 -> V_112 = F_49 ;
V_105 -> V_113 = F_46 ;
V_105 -> V_114 = F_47 ;
V_2 -> V_86 . V_87 = F_59 ( V_105 , V_2 -> V_84 ) ;
if ( ! V_2 -> V_86 . V_87 ) {
F_60 ( V_2 ) ;
return - V_94 ;
}
F_61 ( & V_2 -> V_86 . V_87 -> V_115 ) ;
F_62 ( V_2 -> V_88 ) ;
F_63 ( V_2 -> V_86 . V_87 ) ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 . V_87 ) {
F_64 ( V_2 -> V_86 . V_87 -> V_17 ) ;
}
F_64 ( V_2 -> V_86 . V_87 ) ;
V_2 -> V_86 . V_87 = NULL ;
F_64 ( V_2 -> V_86 . V_105 ) ;
V_2 -> V_86 . V_105 = NULL ;
}
int F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_88 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 )
{
}
static unsigned int F_68 ( void * V_116 , bool V_117 )
{
struct V_1 * V_2 = V_116 ;
F_69 ( V_2 , V_117 ) ;
if ( V_117 )
return V_118 | V_119 |
V_120 | V_121 ;
else
return V_120 | V_121 ;
}
static bool F_70 ( int V_122 )
{
return ( V_122 & ( V_122 - 1 ) ) == 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( ! F_70 ( V_40 ) ) {
F_19 ( V_2 -> V_29 , L_15 ,
V_40 ) ;
V_40 = 0 ;
}
if ( V_123 < 32 ) {
F_19 ( V_2 -> V_29 , L_16 ,
V_123 ) ;
V_123 = 512 ;
} else if ( ! F_70 ( V_123 ) ) {
F_19 ( V_2 -> V_29 , L_17 ,
V_123 ) ;
V_123 = 512 ;
}
V_2 -> V_37 . V_52 = ( T_4 ) V_123 << 20 ;
switch ( V_124 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_19 ( V_2 -> V_29 , L_18
L_19 , V_124 ) ;
V_124 = 0 ;
break;
}
}
static bool F_72 ( struct V_125 * V_54 )
{
if ( V_54 -> V_55 == V_56 &&
V_54 -> V_126 == 0x00e2 ) {
F_73 ( V_127 L_20 ) ;
return true ;
}
return false ;
}
static void F_74 ( struct V_125 * V_54 , enum V_128 V_117 )
{
struct V_129 * V_29 = F_75 ( V_54 ) ;
T_6 V_130 = { . V_131 = V_132 } ;
if ( V_117 == V_133 ) {
unsigned V_134 = V_29 -> V_54 -> V_134 ;
F_73 ( V_127 L_21 ) ;
V_29 -> V_135 = V_136 ;
if ( V_134 < 20 && F_72 ( V_54 ) )
V_29 -> V_54 -> V_134 = 20 ;
F_76 ( V_29 ) ;
V_29 -> V_54 -> V_134 = V_134 ;
V_29 -> V_135 = V_137 ;
F_77 ( V_29 ) ;
} else {
F_73 ( V_127 L_22 ) ;
F_78 ( V_29 ) ;
V_29 -> V_135 = V_136 ;
F_79 ( V_29 , V_130 ) ;
V_29 -> V_135 = V_138 ;
}
}
static bool F_80 ( struct V_125 * V_54 )
{
struct V_129 * V_29 = F_75 ( V_54 ) ;
bool V_139 ;
F_81 ( & V_29 -> V_140 ) ;
V_139 = ( V_29 -> V_141 == 0 ) ;
F_82 ( & V_29 -> V_140 ) ;
return V_139 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_129 * V_88 ,
struct V_125 * V_54 ,
T_2 V_33 )
{
int V_25 , V_9 ;
int V_142 ;
V_2 -> V_143 = false ;
V_2 -> V_29 = & V_54 -> V_29 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_10 = V_33 & V_144 ;
V_2 -> V_85 = false ;
V_2 -> V_145 = V_146 ;
V_2 -> V_37 . V_52 = V_123 * 1024 * 1024 ;
V_2 -> V_147 = false ;
for ( V_9 = 0 ; V_9 < V_148 ; V_9 ++ ) {
V_2 -> V_149 [ V_9 ] . V_150 = V_9 ;
}
F_35 ( L_23 ,
V_151 [ V_2 -> V_10 ] , V_54 -> V_152 , V_54 -> V_153 ,
V_54 -> V_55 , V_54 -> V_126 ) ;
F_61 ( & V_2 -> V_154 ) ;
F_61 ( & V_2 -> V_155 ) ;
F_84 ( & V_2 -> V_156 . V_157 , 0 ) ;
F_61 ( & V_2 -> V_158 . V_115 ) ;
F_61 ( & V_2 -> V_77 . V_115 ) ;
F_61 ( & V_2 -> V_159 ) ;
F_85 ( & V_2 -> V_77 . V_160 ) ;
F_85 ( & V_2 -> V_161 ) ;
F_86 ( & V_2 -> V_162 . V_163 ) ;
V_25 = F_87 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_61 ( & V_2 -> V_164 . V_157 ) ;
V_2 -> V_164 . V_165 = 1 << 20 ;
F_88 ( & V_2 -> V_164 . V_166 ) ;
V_25 = F_89 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_71 ( V_2 ) ;
if ( ( V_2 -> V_10 >= V_167 ) &&
( V_2 -> V_33 & V_82 ) ) {
V_2 -> V_33 &= ~ V_34 ;
}
if ( V_2 -> V_33 & V_34 && V_124 == - 1 ) {
F_90 ( V_2 ) ;
}
if ( V_2 -> V_10 >= V_168 )
V_2 -> V_37 . V_43 = 0xffffffffffULL ;
else if ( V_2 -> V_10 >= V_169 )
V_2 -> V_37 . V_43 = 0xfffffffffULL ;
else
V_2 -> V_37 . V_43 = 0xffffffffULL ;
V_2 -> V_170 = false ;
if ( V_2 -> V_33 & V_34 )
V_2 -> V_170 = true ;
if ( ( V_2 -> V_33 & V_171 ) &&
( V_2 -> V_10 <= V_172 ) )
V_2 -> V_170 = true ;
V_142 = V_2 -> V_170 ? 32 : 40 ;
V_25 = F_91 ( V_2 -> V_54 , F_92 ( V_142 ) ) ;
if ( V_25 ) {
V_2 -> V_170 = true ;
V_142 = 32 ;
F_73 ( V_173 L_24 ) ;
}
V_25 = F_93 ( V_2 -> V_54 , F_92 ( V_142 ) ) ;
if ( V_25 ) {
F_93 ( V_2 -> V_54 , F_92 ( 32 ) ) ;
F_73 ( V_173 L_25 ) ;
}
F_94 ( & V_2 -> V_174 ) ;
V_2 -> V_175 = F_95 ( V_2 -> V_54 , 2 ) ;
V_2 -> V_176 = F_96 ( V_2 -> V_54 , 2 ) ;
V_2 -> V_177 = F_97 ( V_2 -> V_175 , V_2 -> V_176 ) ;
if ( V_2 -> V_177 == NULL ) {
return - V_94 ;
}
F_35 ( L_26 , ( T_2 ) V_2 -> V_175 ) ;
F_35 ( L_27 , ( unsigned ) V_2 -> V_176 ) ;
for ( V_9 = 0 ; V_9 < V_178 ; V_9 ++ ) {
if ( F_98 ( V_2 -> V_54 , V_9 ) & V_179 ) {
V_2 -> V_180 = F_96 ( V_2 -> V_54 , V_9 ) ;
V_2 -> V_108 = F_99 ( V_2 -> V_54 , V_9 , V_2 -> V_180 ) ;
break;
}
}
if ( V_2 -> V_108 == NULL )
F_58 ( L_28 ) ;
F_100 ( V_2 -> V_54 , V_2 , NULL , F_68 ) ;
F_101 ( V_2 -> V_54 , & V_181 ) ;
V_25 = F_102 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_103 ( V_2 ) ;
if ( V_25 )
F_58 ( L_29 , V_25 ) ;
V_25 = F_104 ( V_2 ) ;
if ( V_25 ) {
F_58 ( L_30 , V_25 ) ;
}
if ( V_2 -> V_33 & V_34 && ! V_2 -> V_147 ) {
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_90 ( V_2 ) ;
V_25 = F_102 ( V_2 ) ;
if ( V_25 )
return V_25 ;
}
if ( ( V_182 & 1 ) ) {
F_107 ( V_2 ) ;
}
if ( ( V_182 & 2 ) ) {
F_108 ( V_2 ) ;
}
if ( V_183 ) {
F_109 ( V_2 , V_183 ) ;
}
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
F_35 ( L_31 ) ;
V_2 -> V_143 = true ;
F_111 ( V_2 ) ;
F_106 ( V_2 ) ;
F_112 ( V_2 -> V_54 ) ;
F_100 ( V_2 -> V_54 , NULL , NULL , NULL ) ;
if ( V_2 -> V_108 )
F_113 ( V_2 -> V_54 , V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
F_114 ( V_2 -> V_177 ) ;
V_2 -> V_177 = NULL ;
F_115 ( V_2 ) ;
}
int F_79 ( struct V_129 * V_29 , T_6 V_117 )
{
struct V_1 * V_2 ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
int V_9 , V_25 ;
bool V_188 = false ;
if ( V_29 == NULL || V_29 -> V_99 == NULL ) {
return - V_189 ;
}
if ( V_117 . V_131 == V_190 ) {
return 0 ;
}
V_2 = V_29 -> V_99 ;
if ( V_29 -> V_135 == V_138 )
return 0 ;
F_78 ( V_29 ) ;
F_116 (connector, &dev->mode_config.connector_list, head) {
F_117 ( V_187 , V_191 ) ;
}
F_116 (crtc, &dev->mode_config.crtc_list, head) {
struct V_192 * V_193 = F_118 ( V_185 -> V_194 ) ;
struct V_195 * V_196 ;
if ( V_193 == NULL || V_193 -> V_197 == NULL ) {
continue;
}
V_196 = F_119 ( V_193 -> V_197 ) ;
if ( ! F_120 ( V_2 , V_196 ) ) {
V_25 = F_12 ( V_196 , false ) ;
if ( V_25 == 0 ) {
F_14 ( V_196 ) ;
F_15 ( V_196 ) ;
}
}
}
F_111 ( V_2 ) ;
F_121 ( & V_2 -> V_154 ) ;
for ( V_9 = 0 ; V_9 < V_148 ; V_9 ++ ) {
V_25 = F_122 ( V_2 , V_9 ) ;
if ( V_25 ) {
V_188 = true ;
}
}
if ( V_188 ) {
F_123 ( V_2 ) ;
}
F_124 ( & V_2 -> V_154 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_111 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_29 -> V_54 ) ;
if ( V_117 . V_131 == V_132 ) {
F_131 ( V_29 -> V_54 ) ;
F_132 ( V_29 -> V_54 , V_198 ) ;
}
F_133 () ;
F_134 ( V_2 , 1 ) ;
F_135 () ;
return 0 ;
}
int F_76 ( struct V_129 * V_29 )
{
struct V_186 * V_187 ;
struct V_1 * V_2 = V_29 -> V_99 ;
int V_25 ;
if ( V_29 -> V_135 == V_138 )
return 0 ;
F_133 () ;
F_132 ( V_29 -> V_54 , V_199 ) ;
F_136 ( V_29 -> V_54 ) ;
if ( F_137 ( V_29 -> V_54 ) ) {
F_135 () ;
return - 1 ;
}
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
V_25 = F_103 ( V_2 ) ;
if ( V_25 )
F_58 ( L_29 , V_25 ) ;
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
F_134 ( V_2 , 0 ) ;
F_135 () ;
if ( V_2 -> V_85 ) {
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
if ( V_2 -> V_86 . V_200 ) {
T_7 V_201 = F_144 ( V_2 ,
V_2 -> V_86 . V_200 ) ;
F_145 ( V_2 , V_2 -> V_86 . V_200 ,
V_201 ) ;
}
}
F_146 ( V_2 ) ;
F_147 ( V_29 ) ;
F_116 (connector, &dev->mode_config.connector_list, head) {
F_117 ( V_187 , V_202 ) ;
}
F_77 ( V_29 ) ;
return 0 ;
}
int F_148 ( struct V_1 * V_2 )
{
unsigned V_203 [ V_148 ] ;
T_2 * V_204 [ V_148 ] ;
bool V_205 = false ;
int V_9 , V_25 ;
int V_206 ;
F_149 ( & V_2 -> V_161 ) ;
F_125 ( V_2 ) ;
V_206 = F_150 ( & V_2 -> V_207 . V_208 ) ;
F_127 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_148 ; ++ V_9 ) {
V_203 [ V_9 ] = F_151 ( V_2 , & V_2 -> V_149 [ V_9 ] ,
& V_204 [ V_9 ] ) ;
if ( V_203 [ V_9 ] ) {
V_205 = true ;
F_23 ( V_2 -> V_29 , L_32
L_33 , V_203 [ V_9 ] , V_9 ) ;
}
}
V_209:
V_25 = F_105 ( V_2 ) ;
if ( ! V_25 ) {
F_23 ( V_2 -> V_29 , L_34 ) ;
F_139 ( V_2 ) ;
}
F_141 ( V_2 ) ;
if ( ! V_25 ) {
for ( V_9 = 0 ; V_9 < V_148 ; ++ V_9 ) {
F_152 ( V_2 , & V_2 -> V_149 [ V_9 ] ,
V_203 [ V_9 ] , V_204 [ V_9 ] ) ;
V_203 [ V_9 ] = 0 ;
V_204 [ V_9 ] = NULL ;
}
V_25 = F_103 ( V_2 ) ;
if ( V_25 ) {
F_38 ( V_2 -> V_29 , L_29 , V_25 ) ;
if ( V_205 ) {
V_205 = false ;
F_127 ( V_2 ) ;
goto V_209;
}
}
} else {
F_123 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_148 ; ++ V_9 ) {
F_64 ( V_204 [ V_9 ] ) ;
}
}
F_147 ( V_2 -> V_88 ) ;
F_153 ( & V_2 -> V_207 . V_208 , V_206 ) ;
if ( V_25 ) {
F_23 ( V_2 -> V_29 , L_35 ) ;
}
F_154 ( & V_2 -> V_161 ) ;
return V_25 ;
}
int F_155 ( struct V_1 * V_2 ,
struct V_210 * V_211 ,
unsigned V_212 )
{
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_213 ; V_9 ++ ) {
if ( V_2 -> V_214 [ V_9 ] . V_211 == V_211 ) {
return 0 ;
}
}
V_9 = V_2 -> V_213 + 1 ;
if ( V_9 > V_215 ) {
F_58 ( L_36 ) ;
F_58 ( L_37
L_38 ) ;
return - V_21 ;
}
V_2 -> V_214 [ V_2 -> V_213 ] . V_211 = V_211 ;
V_2 -> V_214 [ V_2 -> V_213 ] . V_216 = V_212 ;
V_2 -> V_213 = V_9 ;
#if F_156 ( V_217 )
F_157 ( V_211 , V_212 ,
V_2 -> V_88 -> V_218 -> V_219 ,
V_2 -> V_88 -> V_218 ) ;
F_157 ( V_211 , V_212 ,
V_2 -> V_88 -> V_220 -> V_219 ,
V_2 -> V_88 -> V_220 ) ;
#endif
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
#if F_156 ( V_217 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_213 ; V_9 ++ ) {
F_158 ( V_2 -> V_214 [ V_9 ] . V_211 ,
V_2 -> V_214 [ V_9 ] . V_216 ,
V_2 -> V_88 -> V_218 ) ;
F_158 ( V_2 -> V_214 [ V_9 ] . V_211 ,
V_2 -> V_214 [ V_9 ] . V_216 ,
V_2 -> V_88 -> V_220 ) ;
}
#endif
}
int F_159 ( struct V_221 * V_222 )
{
return 0 ;
}
void F_160 ( struct V_221 * V_222 )
{
}
