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
int F_10 ( struct V_1 * V_2 )
{
int V_9 ;
V_2 -> V_22 . V_23 = F_11 ( V_2 -> V_24 , 2 ) ;
V_2 -> V_22 . V_25 = F_12 ( V_2 -> V_24 , 2 ) ;
if ( V_2 -> V_22 . V_25 > ( 4 * 1024 * 1024 ) )
V_2 -> V_22 . V_25 = 4 * 1024 * 1024 ;
V_2 -> V_22 . V_26 = F_13 ( V_2 -> V_22 . V_23 , V_2 -> V_22 . V_25 ) ;
if ( V_2 -> V_22 . V_26 == NULL ) {
return - V_27 ;
}
F_14 ( L_1 , ( T_2 ) V_2 -> V_22 . V_23 ) ;
F_14 ( L_2 , ( unsigned ) V_2 -> V_22 . V_25 ) ;
V_2 -> V_22 . V_28 = V_2 -> V_22 . V_25 / V_29 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_22 . V_28 ; V_9 ++ ) {
V_2 -> V_22 . free [ V_9 ] = true ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_22 . V_26 ) ;
V_2 -> V_22 . V_26 = NULL ;
}
int F_17 ( struct V_1 * V_2 , T_1 * V_22 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_22 . V_28 ; V_9 ++ ) {
if ( V_2 -> V_22 . free [ V_9 ] ) {
V_2 -> V_22 . free [ V_9 ] = false ;
* V_22 = V_9 ;
return 0 ;
}
}
return - V_21 ;
}
void F_18 ( struct V_1 * V_2 , T_1 V_22 )
{
if ( V_22 < V_2 -> V_22 . V_28 )
V_2 -> V_22 . free [ V_22 ] = true ;
}
void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_30 . V_31 = false ;
}
void F_20 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
if ( V_2 -> V_30 . V_32 ) {
if ( ! F_21 ( V_2 -> V_30 . V_32 , false ) ) {
F_22 ( V_2 -> V_30 . V_32 ) ;
F_23 ( V_2 -> V_30 . V_32 ) ;
F_24 ( V_2 -> V_30 . V_32 ) ;
}
F_25 ( & V_2 -> V_30 . V_32 ) ;
V_2 -> V_30 . V_30 = NULL ;
V_2 -> V_30 . V_32 = NULL ;
}
}
int F_26 ( struct V_1 * V_2 )
{
int V_33 ;
if ( V_2 -> V_30 . V_32 == NULL ) {
V_33 = F_27 ( V_2 , V_34 , V_29 , true ,
V_35 , NULL , & V_2 -> V_30 . V_32 ) ;
if ( V_33 ) {
F_28 ( V_2 -> V_36 , L_3 , V_33 ) ;
return V_33 ;
}
V_33 = F_21 ( V_2 -> V_30 . V_32 , false ) ;
if ( F_29 ( V_33 != 0 ) ) {
F_20 ( V_2 ) ;
return V_33 ;
}
V_33 = F_30 ( V_2 -> V_30 . V_32 , V_35 ,
& V_2 -> V_30 . V_37 ) ;
if ( V_33 ) {
F_24 ( V_2 -> V_30 . V_32 ) ;
F_28 ( V_2 -> V_36 , L_4 , V_33 ) ;
F_20 ( V_2 ) ;
return V_33 ;
}
V_33 = F_31 ( V_2 -> V_30 . V_32 , ( void * * ) & V_2 -> V_30 . V_30 ) ;
F_24 ( V_2 -> V_30 . V_32 ) ;
if ( V_33 ) {
F_28 ( V_2 -> V_36 , L_5 , V_33 ) ;
F_20 ( V_2 ) ;
return V_33 ;
}
}
memset ( ( char * ) V_2 -> V_30 . V_30 , 0 , V_34 ) ;
V_2 -> V_30 . V_38 = false ;
if ( V_39 == 1 ) {
V_2 -> V_30 . V_31 = false ;
} else {
if ( V_2 -> V_40 & V_41 ) {
V_2 -> V_30 . V_31 = false ;
} else if ( V_2 -> V_10 < V_16 ) {
V_2 -> V_30 . V_31 = false ;
} else {
V_2 -> V_30 . V_31 = true ;
if ( V_2 -> V_10 >= V_11 ) {
V_2 -> V_30 . V_38 = true ;
}
}
}
if ( V_2 -> V_10 >= V_42 ) {
V_2 -> V_30 . V_31 = true ;
V_2 -> V_30 . V_38 = true ;
}
F_32 ( V_2 -> V_36 , L_6 , V_2 -> V_30 . V_31 ? L_7 : L_8 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 , struct V_43 * V_44 , T_3 V_23 )
{
T_4 V_45 = ( T_4 ) V_46 << 20 ;
V_44 -> V_47 = V_23 ;
if ( V_44 -> V_48 > ( V_2 -> V_44 . V_49 - V_23 + 1 ) ) {
F_28 ( V_2 -> V_36 , L_9 ) ;
V_44 -> V_50 = V_44 -> V_51 ;
V_44 -> V_48 = V_44 -> V_51 ;
}
V_44 -> V_52 = V_44 -> V_47 + V_44 -> V_48 - 1 ;
if ( V_2 -> V_40 & V_41 && V_44 -> V_52 > V_44 -> V_53 && V_44 -> V_47 <= V_44 -> V_54 ) {
F_28 ( V_2 -> V_36 , L_9 ) ;
V_44 -> V_50 = V_44 -> V_51 ;
V_44 -> V_48 = V_44 -> V_51 ;
}
V_44 -> V_52 = V_44 -> V_47 + V_44 -> V_48 - 1 ;
if ( V_45 && V_45 < V_44 -> V_50 )
V_44 -> V_50 = V_45 ;
F_32 ( V_2 -> V_36 , L_10 ,
V_44 -> V_48 >> 20 , V_44 -> V_47 ,
V_44 -> V_52 , V_44 -> V_50 >> 20 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
T_3 V_55 , V_56 ;
V_55 = ( ( V_2 -> V_44 . V_49 - V_44 -> V_52 ) + V_44 -> V_57 ) & ~ V_44 -> V_57 ;
V_56 = V_44 -> V_47 & ~ V_44 -> V_57 ;
if ( V_56 > V_55 ) {
if ( V_44 -> V_58 > V_56 ) {
F_28 ( V_2 -> V_36 , L_11 ) ;
V_44 -> V_58 = V_56 ;
}
V_44 -> V_53 = ( V_44 -> V_47 & ~ V_44 -> V_57 ) - V_44 -> V_58 ;
} else {
if ( V_44 -> V_58 > V_55 ) {
F_28 ( V_2 -> V_36 , L_11 ) ;
V_44 -> V_58 = V_55 ;
}
V_44 -> V_53 = ( V_44 -> V_52 + 1 + V_44 -> V_57 ) & ~ V_44 -> V_57 ;
}
V_44 -> V_54 = V_44 -> V_53 + V_44 -> V_58 - 1 ;
F_32 ( V_2 -> V_36 , L_12 ,
V_44 -> V_58 >> 20 , V_44 -> V_53 , V_44 -> V_54 ) ;
}
bool F_35 ( struct V_1 * V_2 )
{
T_2 V_6 ;
if ( F_36 ( V_59 ) &&
( V_2 -> V_24 -> V_60 == V_61 ) &&
( V_2 -> V_10 < V_11 ) )
return false ;
if ( F_37 ( V_2 ) )
goto V_62;
if ( F_38 ( V_2 ) ) {
V_6 = F_2 ( V_63 + V_64 ) |
F_2 ( V_63 + V_65 ) ;
if ( V_2 -> V_66 >= 4 ) {
V_6 |= F_2 ( V_63 + V_67 ) |
F_2 ( V_63 + V_68 ) ;
}
if ( V_2 -> V_66 >= 6 ) {
V_6 |= F_2 ( V_63 + V_69 ) |
F_2 ( V_63 + V_70 ) ;
}
if ( V_6 & V_71 )
return true ;
} else if ( F_39 ( V_2 ) ) {
V_6 = F_2 ( V_72 ) |
F_2 ( V_73 ) ;
if ( V_6 & V_74 ) {
return true ;
}
} else {
V_6 = F_2 ( V_75 ) |
F_2 ( V_76 ) ;
if ( V_6 & V_77 ) {
return true ;
}
}
V_62:
if ( V_2 -> V_10 >= V_11 )
V_6 = F_2 ( V_78 ) ;
else
V_6 = F_2 ( V_79 ) ;
if ( V_6 )
return true ;
return false ;
}
void F_40 ( struct V_1 * V_2 )
{
T_5 V_80 ;
T_1 V_81 = V_2 -> V_82 . V_83 ;
T_1 V_84 = V_2 -> V_82 . V_85 ;
V_80 . V_86 = F_41 ( 100 ) ;
V_2 -> V_82 . V_81 . V_86 = F_41 ( V_81 ) ;
V_2 -> V_82 . V_81 . V_86 = F_42 ( V_2 -> V_82 . V_81 , V_80 ) ;
V_2 -> V_82 . V_84 . V_86 = F_41 ( V_84 ) ;
V_2 -> V_82 . V_84 . V_86 = F_42 ( V_2 -> V_82 . V_84 , V_80 ) ;
if ( V_2 -> V_40 & V_87 ) {
V_80 . V_86 = F_41 ( 16 ) ;
V_2 -> V_82 . V_88 . V_86 = F_42 ( V_2 -> V_82 . V_81 , V_80 ) ;
}
}
bool F_43 ( struct V_1 * V_2 )
{
if ( F_35 ( V_2 ) )
return true ;
if ( V_2 -> V_89 ) {
F_14 ( L_13 ) ;
if ( V_2 -> V_90 )
F_44 ( V_2 -> V_91 . V_92 ) ;
else
F_45 ( V_2 -> V_93 ) ;
return true ;
} else {
F_46 ( V_2 -> V_36 , L_14 ) ;
return false ;
}
}
int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 . V_95 )
return 0 ;
V_2 -> V_94 . V_95 = F_48 ( V_96 | V_97 | V_98 ) ;
if ( V_2 -> V_94 . V_95 == NULL )
return - V_27 ;
V_2 -> V_94 . V_99 = F_49 ( V_2 -> V_24 , V_2 -> V_94 . V_95 ,
0 , V_29 , V_100 ) ;
if ( F_50 ( V_2 -> V_24 , V_2 -> V_94 . V_99 ) ) {
F_46 ( & V_2 -> V_24 -> V_36 , L_15 ) ;
F_51 ( V_2 -> V_94 . V_95 ) ;
V_2 -> V_94 . V_95 = NULL ;
return - V_27 ;
}
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 . V_95 == NULL )
return;
F_53 ( V_2 -> V_24 , V_2 -> V_94 . V_99 ,
V_29 , V_100 ) ;
F_51 ( V_2 -> V_94 . V_95 ) ;
V_2 -> V_94 . V_95 = NULL ;
}
static T_2 F_54 ( struct V_101 * V_102 , T_2 V_6 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
T_2 V_33 ;
V_33 = V_2 -> V_104 ( V_2 , V_6 ) ;
return V_33 ;
}
static void F_55 ( struct V_101 * V_102 , T_2 V_6 , T_2 V_105 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
V_2 -> V_106 ( V_2 , V_6 , V_105 ) ;
}
static T_2 F_56 ( struct V_101 * V_102 , T_2 V_6 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
T_2 V_33 ;
V_33 = V_2 -> V_107 ( V_2 , V_6 ) ;
return V_33 ;
}
static void F_57 ( struct V_101 * V_102 , T_2 V_6 , T_2 V_105 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
V_2 -> V_108 ( V_2 , V_6 , V_105 ) ;
}
static void F_58 ( struct V_101 * V_102 , T_2 V_6 , T_2 V_105 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
F_3 ( V_6 * 4 , V_105 ) ;
}
static T_2 F_59 ( struct V_101 * V_102 , T_2 V_6 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
T_2 V_33 ;
V_33 = F_2 ( V_6 * 4 ) ;
return V_33 ;
}
static void F_60 ( struct V_101 * V_102 , T_2 V_6 , T_2 V_105 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
F_61 ( V_6 * 4 , V_105 ) ;
}
static T_2 F_62 ( struct V_101 * V_102 , T_2 V_6 )
{
struct V_1 * V_2 = V_102 -> V_36 -> V_103 ;
T_2 V_33 ;
V_33 = F_63 ( V_6 * 4 ) ;
return V_33 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_101 * V_109 =
F_65 ( sizeof( struct V_101 ) , V_97 ) ;
if ( ! V_109 )
return - V_27 ;
V_2 -> V_91 . V_109 = V_109 ;
V_109 -> V_36 = V_2 -> V_93 ;
V_109 -> V_110 = F_59 ;
V_109 -> V_111 = F_58 ;
if ( V_2 -> V_112 ) {
V_109 -> V_113 = F_62 ;
V_109 -> V_114 = F_60 ;
} else {
F_66 ( L_16 ) ;
V_109 -> V_113 = F_59 ;
V_109 -> V_114 = F_58 ;
}
V_109 -> V_115 = F_56 ;
V_109 -> V_116 = F_57 ;
V_109 -> V_117 = F_54 ;
V_109 -> V_118 = F_55 ;
V_2 -> V_91 . V_92 = F_67 ( V_109 , V_2 -> V_89 ) ;
if ( ! V_2 -> V_91 . V_92 ) {
F_68 ( V_2 ) ;
return - V_27 ;
}
F_69 ( & V_2 -> V_91 . V_92 -> V_119 ) ;
F_70 ( V_2 -> V_93 ) ;
F_71 ( V_2 -> V_91 . V_92 ) ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 . V_92 ) {
F_72 ( V_2 -> V_91 . V_92 -> V_17 ) ;
}
F_72 ( V_2 -> V_91 . V_92 ) ;
V_2 -> V_91 . V_92 = NULL ;
F_72 ( V_2 -> V_91 . V_109 ) ;
V_2 -> V_91 . V_109 = NULL ;
}
int F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_93 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
}
static unsigned int F_76 ( void * V_120 , bool V_121 )
{
struct V_1 * V_2 = V_120 ;
F_77 ( V_2 , V_121 ) ;
if ( V_121 )
return V_122 | V_123 |
V_124 | V_125 ;
else
return V_124 | V_125 ;
}
static bool F_78 ( int V_126 )
{
return ( V_126 & ( V_126 - 1 ) ) == 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( ! F_78 ( V_46 ) ) {
F_28 ( V_2 -> V_36 , L_17 ,
V_46 ) ;
V_46 = 0 ;
}
if ( V_127 < 32 ) {
F_28 ( V_2 -> V_36 , L_18 ,
V_127 ) ;
V_127 = 512 ;
} else if ( ! F_78 ( V_127 ) ) {
F_28 ( V_2 -> V_36 , L_19 ,
V_127 ) ;
V_127 = 512 ;
}
V_2 -> V_44 . V_58 = ( T_4 ) V_127 << 20 ;
switch ( V_128 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_28 ( V_2 -> V_36 , L_20
L_21 , V_128 ) ;
V_128 = 0 ;
break;
}
}
static bool F_80 ( struct V_129 * V_24 )
{
if ( V_24 -> V_60 == V_61 &&
V_24 -> V_130 == 0x00e2 ) {
F_81 ( V_131 L_22 ) ;
return true ;
}
return false ;
}
static void F_82 ( struct V_129 * V_24 , enum V_132 V_121 )
{
struct V_133 * V_36 = F_83 ( V_24 ) ;
T_6 V_134 = { . V_135 = V_136 } ;
if ( V_121 == V_137 ) {
unsigned V_138 = V_36 -> V_24 -> V_138 ;
F_81 ( V_131 L_23 ) ;
V_36 -> V_139 = V_140 ;
if ( V_138 < 20 && F_80 ( V_24 ) )
V_36 -> V_24 -> V_138 = 20 ;
F_84 ( V_36 ) ;
V_36 -> V_24 -> V_138 = V_138 ;
V_36 -> V_139 = V_141 ;
F_85 ( V_36 ) ;
} else {
F_81 ( V_131 L_24 ) ;
F_86 ( V_36 ) ;
V_36 -> V_139 = V_140 ;
F_87 ( V_36 , V_134 ) ;
V_36 -> V_139 = V_142 ;
}
}
static bool F_88 ( struct V_129 * V_24 )
{
struct V_133 * V_36 = F_83 ( V_24 ) ;
bool V_143 ;
F_89 ( & V_36 -> V_144 ) ;
V_143 = ( V_36 -> V_145 == 0 ) ;
F_90 ( & V_36 -> V_144 ) ;
return V_143 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_133 * V_93 ,
struct V_129 * V_24 ,
T_2 V_40 )
{
int V_33 , V_9 ;
int V_146 ;
V_2 -> V_147 = false ;
V_2 -> V_36 = & V_24 -> V_36 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_10 = V_40 & V_148 ;
V_2 -> V_90 = false ;
V_2 -> V_149 = V_150 ;
V_2 -> V_44 . V_58 = V_127 * 1024 * 1024 ;
V_2 -> V_151 = false ;
for ( V_9 = 0 ; V_9 < V_152 ; V_9 ++ ) {
V_2 -> V_153 [ V_9 ] . V_154 = V_9 ;
}
F_14 ( L_25 ,
V_155 [ V_2 -> V_10 ] , V_24 -> V_156 , V_24 -> V_157 ,
V_24 -> V_60 , V_24 -> V_130 ) ;
F_69 ( & V_2 -> V_158 ) ;
F_69 ( & V_2 -> V_159 ) ;
F_92 ( & V_2 -> V_160 . V_161 , 0 ) ;
F_69 ( & V_2 -> V_162 . V_119 ) ;
F_69 ( & V_2 -> V_82 . V_119 ) ;
F_69 ( & V_2 -> V_163 ) ;
F_69 ( & V_2 -> V_164 ) ;
F_93 ( & V_2 -> V_82 . V_165 ) ;
F_93 ( & V_2 -> V_166 ) ;
F_94 ( & V_2 -> V_167 . V_168 ) ;
V_33 = F_95 ( V_2 ) ;
if ( V_33 )
return V_33 ;
F_69 ( & V_2 -> V_169 . V_161 ) ;
V_2 -> V_169 . V_170 = 1 << 20 ;
F_96 ( & V_2 -> V_169 . V_171 ) ;
V_33 = F_97 ( V_2 ) ;
if ( V_33 )
return V_33 ;
F_79 ( V_2 ) ;
if ( ( V_2 -> V_10 >= V_172 ) &&
( V_2 -> V_40 & V_87 ) ) {
V_2 -> V_40 &= ~ V_41 ;
}
if ( V_2 -> V_40 & V_41 && V_128 == - 1 ) {
F_98 ( V_2 ) ;
}
if ( V_2 -> V_10 >= V_173 )
V_2 -> V_44 . V_49 = 0xffffffffffULL ;
else if ( V_2 -> V_10 >= V_174 )
V_2 -> V_44 . V_49 = 0xfffffffffULL ;
else
V_2 -> V_44 . V_49 = 0xffffffffULL ;
V_2 -> V_175 = false ;
if ( V_2 -> V_40 & V_41 )
V_2 -> V_175 = true ;
if ( ( V_2 -> V_40 & V_176 ) &&
( V_2 -> V_10 <= V_177 ) )
V_2 -> V_175 = true ;
V_146 = V_2 -> V_175 ? 32 : 40 ;
V_33 = F_99 ( V_2 -> V_24 , F_100 ( V_146 ) ) ;
if ( V_33 ) {
V_2 -> V_175 = true ;
V_146 = 32 ;
F_81 ( V_178 L_26 ) ;
}
V_33 = F_101 ( V_2 -> V_24 , F_100 ( V_146 ) ) ;
if ( V_33 ) {
F_101 ( V_2 -> V_24 , F_100 ( 32 ) ) ;
F_81 ( V_178 L_27 ) ;
}
F_102 ( & V_2 -> V_179 ) ;
if ( V_2 -> V_10 >= V_180 ) {
V_2 -> V_181 = F_11 ( V_2 -> V_24 , 5 ) ;
V_2 -> V_182 = F_12 ( V_2 -> V_24 , 5 ) ;
} else {
V_2 -> V_181 = F_11 ( V_2 -> V_24 , 2 ) ;
V_2 -> V_182 = F_12 ( V_2 -> V_24 , 2 ) ;
}
V_2 -> V_183 = F_13 ( V_2 -> V_181 , V_2 -> V_182 ) ;
if ( V_2 -> V_183 == NULL ) {
return - V_27 ;
}
F_14 ( L_28 , ( T_2 ) V_2 -> V_181 ) ;
F_14 ( L_29 , ( unsigned ) V_2 -> V_182 ) ;
if ( V_2 -> V_10 >= V_180 )
F_10 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_184 ; V_9 ++ ) {
if ( F_103 ( V_2 -> V_24 , V_9 ) & V_185 ) {
V_2 -> V_186 = F_12 ( V_2 -> V_24 , V_9 ) ;
V_2 -> V_112 = F_104 ( V_2 -> V_24 , V_9 , V_2 -> V_186 ) ;
break;
}
}
if ( V_2 -> V_112 == NULL )
F_66 ( L_30 ) ;
F_105 ( V_2 -> V_24 , V_2 , NULL , F_76 ) ;
F_106 ( V_2 -> V_24 , & V_187 ) ;
V_33 = F_107 ( V_2 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_108 ( V_2 ) ;
if ( V_33 )
F_66 ( L_31 , V_33 ) ;
V_33 = F_109 ( V_2 ) ;
if ( V_33 ) {
F_66 ( L_32 , V_33 ) ;
}
if ( V_2 -> V_40 & V_41 && ! V_2 -> V_151 ) {
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_98 ( V_2 ) ;
V_33 = F_107 ( V_2 ) ;
if ( V_33 )
return V_33 ;
}
if ( ( V_188 & 1 ) ) {
F_112 ( V_2 ) ;
}
if ( ( V_188 & 2 ) ) {
F_113 ( V_2 ) ;
}
if ( V_189 ) {
F_114 ( V_2 , V_189 ) ;
}
return 0 ;
}
void F_115 ( struct V_1 * V_2 )
{
F_14 ( L_33 ) ;
V_2 -> V_147 = true ;
F_116 ( V_2 ) ;
F_111 ( V_2 ) ;
F_117 ( V_2 -> V_24 ) ;
F_105 ( V_2 -> V_24 , NULL , NULL , NULL ) ;
if ( V_2 -> V_112 )
F_118 ( V_2 -> V_24 , V_2 -> V_112 ) ;
V_2 -> V_112 = NULL ;
F_16 ( V_2 -> V_183 ) ;
V_2 -> V_183 = NULL ;
if ( V_2 -> V_10 >= V_180 )
F_15 ( V_2 ) ;
F_119 ( V_2 ) ;
}
int F_87 ( struct V_133 * V_36 , T_6 V_121 )
{
struct V_1 * V_2 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
int V_9 , V_33 ;
bool V_194 = false ;
if ( V_36 == NULL || V_36 -> V_103 == NULL ) {
return - V_195 ;
}
if ( V_121 . V_135 == V_196 ) {
return 0 ;
}
V_2 = V_36 -> V_103 ;
if ( V_36 -> V_139 == V_142 )
return 0 ;
F_86 ( V_36 ) ;
F_120 (connector, &dev->mode_config.connector_list, head) {
F_121 ( V_193 , V_197 ) ;
}
F_120 (crtc, &dev->mode_config.crtc_list, head) {
struct V_198 * V_199 = F_122 ( V_191 -> V_200 ) ;
struct V_201 * V_202 ;
if ( V_199 == NULL || V_199 -> V_203 == NULL ) {
continue;
}
V_202 = F_123 ( V_199 -> V_203 ) ;
if ( ! F_124 ( V_2 , V_202 ) ) {
V_33 = F_21 ( V_202 , false ) ;
if ( V_33 == 0 ) {
F_23 ( V_202 ) ;
F_24 ( V_202 ) ;
}
}
}
F_116 ( V_2 ) ;
F_125 ( & V_2 -> V_158 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; V_9 ++ ) {
V_33 = F_126 ( V_2 , V_9 ) ;
if ( V_33 ) {
V_194 = true ;
}
}
if ( V_194 ) {
F_127 ( V_2 ) ;
}
F_128 ( & V_2 -> V_158 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_116 ( V_2 ) ;
F_133 ( V_2 ) ;
F_134 ( V_36 -> V_24 ) ;
if ( V_121 . V_135 == V_136 ) {
F_135 ( V_36 -> V_24 ) ;
F_136 ( V_36 -> V_24 , V_204 ) ;
}
F_137 () ;
F_138 ( V_2 , 1 ) ;
F_139 () ;
return 0 ;
}
int F_84 ( struct V_133 * V_36 )
{
struct V_192 * V_193 ;
struct V_1 * V_2 = V_36 -> V_103 ;
int V_33 ;
if ( V_36 -> V_139 == V_142 )
return 0 ;
F_137 () ;
F_136 ( V_36 -> V_24 , V_205 ) ;
F_140 ( V_36 -> V_24 ) ;
if ( F_141 ( V_36 -> V_24 ) ) {
F_139 () ;
return - 1 ;
}
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
V_33 = F_108 ( V_2 ) ;
if ( V_33 )
F_66 ( L_31 , V_33 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_138 ( V_2 , 0 ) ;
F_139 () ;
if ( V_2 -> V_90 ) {
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
if ( V_2 -> V_91 . V_206 ) {
T_7 V_207 = F_148 ( V_2 ,
V_2 -> V_91 . V_206 ) ;
F_149 ( V_2 , V_2 -> V_91 . V_206 ,
V_207 ) ;
}
}
F_150 ( V_2 ) ;
F_151 ( V_36 ) ;
F_120 (connector, &dev->mode_config.connector_list, head) {
F_121 ( V_193 , V_208 ) ;
}
F_85 ( V_36 ) ;
return 0 ;
}
int F_152 ( struct V_1 * V_2 )
{
unsigned V_209 [ V_152 ] ;
T_2 * V_210 [ V_152 ] ;
bool V_211 = false ;
int V_9 , V_33 ;
int V_212 ;
F_153 ( & V_2 -> V_166 ) ;
F_129 ( V_2 ) ;
V_212 = F_154 ( & V_2 -> V_213 . V_214 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; ++ V_9 ) {
V_209 [ V_9 ] = F_155 ( V_2 , & V_2 -> V_153 [ V_9 ] ,
& V_210 [ V_9 ] ) ;
if ( V_209 [ V_9 ] ) {
V_211 = true ;
F_32 ( V_2 -> V_36 , L_34
L_35 , V_209 [ V_9 ] , V_9 ) ;
}
}
V_215:
V_33 = F_110 ( V_2 ) ;
if ( ! V_33 ) {
F_32 ( V_2 -> V_36 , L_36 ) ;
F_143 ( V_2 ) ;
}
F_145 ( V_2 ) ;
if ( ! V_33 ) {
for ( V_9 = 0 ; V_9 < V_152 ; ++ V_9 ) {
F_156 ( V_2 , & V_2 -> V_153 [ V_9 ] ,
V_209 [ V_9 ] , V_210 [ V_9 ] ) ;
V_209 [ V_9 ] = 0 ;
V_210 [ V_9 ] = NULL ;
}
V_33 = F_108 ( V_2 ) ;
if ( V_33 ) {
F_46 ( V_2 -> V_36 , L_31 , V_33 ) ;
if ( V_211 ) {
V_211 = false ;
F_131 ( V_2 ) ;
goto V_215;
}
}
} else {
F_127 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; ++ V_9 ) {
F_72 ( V_210 [ V_9 ] ) ;
}
}
F_144 ( V_2 ) ;
F_151 ( V_2 -> V_93 ) ;
F_157 ( & V_2 -> V_213 . V_214 , V_212 ) ;
if ( V_33 ) {
F_32 ( V_2 -> V_36 , L_37 ) ;
}
F_158 ( & V_2 -> V_166 ) ;
return V_33 ;
}
int F_159 ( struct V_1 * V_2 ,
struct V_216 * V_217 ,
unsigned V_218 )
{
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_219 ; V_9 ++ ) {
if ( V_2 -> V_220 [ V_9 ] . V_217 == V_217 ) {
return 0 ;
}
}
V_9 = V_2 -> V_219 + 1 ;
if ( V_9 > V_221 ) {
F_66 ( L_38 ) ;
F_66 ( L_39
L_40 ) ;
return - V_21 ;
}
V_2 -> V_220 [ V_2 -> V_219 ] . V_217 = V_217 ;
V_2 -> V_220 [ V_2 -> V_219 ] . V_222 = V_218 ;
V_2 -> V_219 = V_9 ;
#if F_160 ( V_223 )
F_161 ( V_217 , V_218 ,
V_2 -> V_93 -> V_224 -> V_225 ,
V_2 -> V_93 -> V_224 ) ;
F_161 ( V_217 , V_218 ,
V_2 -> V_93 -> V_226 -> V_225 ,
V_2 -> V_93 -> V_226 ) ;
#endif
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
#if F_160 ( V_223 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_219 ; V_9 ++ ) {
F_162 ( V_2 -> V_220 [ V_9 ] . V_217 ,
V_2 -> V_220 [ V_9 ] . V_222 ,
V_2 -> V_93 -> V_224 ) ;
F_162 ( V_2 -> V_220 [ V_9 ] . V_217 ,
V_2 -> V_220 [ V_9 ] . V_222 ,
V_2 -> V_93 -> V_226 ) ;
}
#endif
}
int F_163 ( struct V_227 * V_228 )
{
return 0 ;
}
void F_164 ( struct V_227 * V_228 )
{
}
