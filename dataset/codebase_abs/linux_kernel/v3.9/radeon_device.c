void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < V_4 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_8 )
F_2 ( V_2 -> V_7 [ V_5 ] . V_8 ) ;
else
F_3 ( V_2 , V_5 ) ;
}
F_4 ( V_9 , 0 ) ;
}
}
void F_5 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_3 < V_10 ) {
V_2 -> V_11 . V_12 = 5 ;
} else {
V_2 -> V_11 . V_12 = 7 ;
}
V_2 -> V_11 . V_13 = V_14 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_11 . V_12 ; V_5 ++ ) {
V_2 -> V_11 . free [ V_5 ] = true ;
V_2 -> V_11 . V_15 [ V_5 ] = V_2 -> V_11 . V_13 + ( V_5 * 4 ) ;
}
}
int F_6 ( struct V_1 * V_2 , T_1 * V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_11 . V_12 ; V_5 ++ ) {
if ( V_2 -> V_11 . free [ V_5 ] ) {
V_2 -> V_11 . free [ V_5 ] = false ;
* V_15 = V_2 -> V_11 . V_15 [ V_5 ] ;
return 0 ;
}
}
return - V_16 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_11 . V_12 ; V_5 ++ ) {
if ( V_2 -> V_11 . V_15 [ V_5 ] == V_15 ) {
V_2 -> V_11 . free [ V_5 ] = true ;
return;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_18 . V_19 ) {
V_17 = F_9 ( V_2 -> V_18 . V_19 , false ) ;
if ( F_10 ( V_17 != 0 ) )
return;
F_11 ( V_2 -> V_18 . V_19 ) ;
F_12 ( V_2 -> V_18 . V_19 ) ;
F_13 ( V_2 -> V_18 . V_19 ) ;
}
V_2 -> V_18 . V_20 = false ;
}
void F_14 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_18 . V_19 ) {
F_15 ( & V_2 -> V_18 . V_19 ) ;
V_2 -> V_18 . V_18 = NULL ;
V_2 -> V_18 . V_19 = NULL ;
}
}
int F_16 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_18 . V_19 == NULL ) {
V_17 = F_17 ( V_2 , V_21 , V_22 , true ,
V_23 , NULL , & V_2 -> V_18 . V_19 ) ;
if ( V_17 ) {
F_18 ( V_2 -> V_24 , L_1 , V_17 ) ;
return V_17 ;
}
}
V_17 = F_9 ( V_2 -> V_18 . V_19 , false ) ;
if ( F_10 ( V_17 != 0 ) ) {
F_14 ( V_2 ) ;
return V_17 ;
}
V_17 = F_19 ( V_2 -> V_18 . V_19 , V_23 ,
& V_2 -> V_18 . V_25 ) ;
if ( V_17 ) {
F_13 ( V_2 -> V_18 . V_19 ) ;
F_18 ( V_2 -> V_24 , L_2 , V_17 ) ;
F_14 ( V_2 ) ;
return V_17 ;
}
V_17 = F_20 ( V_2 -> V_18 . V_19 , ( void * * ) & V_2 -> V_18 . V_18 ) ;
F_13 ( V_2 -> V_18 . V_19 ) ;
if ( V_17 ) {
F_18 ( V_2 -> V_24 , L_3 , V_17 ) ;
F_14 ( V_2 ) ;
return V_17 ;
}
memset ( ( char * ) V_2 -> V_18 . V_18 , 0 , V_21 ) ;
V_2 -> V_18 . V_26 = false ;
if ( V_27 == 1 ) {
V_2 -> V_18 . V_20 = false ;
} else {
if ( V_2 -> V_28 & V_29 ) {
V_2 -> V_18 . V_20 = false ;
} else if ( V_2 -> V_3 < V_10 ) {
V_2 -> V_18 . V_20 = false ;
} else {
V_2 -> V_18 . V_20 = true ;
if ( V_2 -> V_3 >= V_4 ) {
V_2 -> V_18 . V_26 = true ;
}
}
}
if ( V_2 -> V_3 >= V_30 ) {
V_2 -> V_18 . V_20 = true ;
V_2 -> V_18 . V_26 = true ;
}
F_21 ( V_2 -> V_24 , L_4 , V_2 -> V_18 . V_20 ? L_5 : L_6 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 , struct V_31 * V_32 , T_2 V_33 )
{
T_3 V_34 = ( T_3 ) V_35 << 20 ;
V_32 -> V_36 = V_33 ;
if ( V_32 -> V_37 > ( 0xFFFFFFFF - V_33 + 1 ) ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_32 -> V_38 = V_32 -> V_39 ;
V_32 -> V_37 = V_32 -> V_39 ;
}
V_32 -> V_40 = V_32 -> V_36 + V_32 -> V_37 - 1 ;
if ( V_2 -> V_28 & V_29 && V_32 -> V_40 > V_32 -> V_41 && V_32 -> V_36 <= V_32 -> V_42 ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_32 -> V_38 = V_32 -> V_39 ;
V_32 -> V_37 = V_32 -> V_39 ;
}
V_32 -> V_40 = V_32 -> V_36 + V_32 -> V_37 - 1 ;
if ( V_34 && V_34 < V_32 -> V_38 )
V_32 -> V_38 = V_34 ;
F_21 ( V_2 -> V_24 , L_8 ,
V_32 -> V_37 >> 20 , V_32 -> V_36 ,
V_32 -> V_40 , V_32 -> V_38 >> 20 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_2 V_43 , V_44 ;
V_43 = ( ( 0xFFFFFFFF - V_32 -> V_40 ) + V_32 -> V_45 ) & ~ V_32 -> V_45 ;
V_44 = V_32 -> V_36 & ~ V_32 -> V_45 ;
if ( V_44 > V_43 ) {
if ( V_32 -> V_46 > V_44 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_32 -> V_46 = V_44 ;
}
V_32 -> V_41 = ( V_32 -> V_36 & ~ V_32 -> V_45 ) - V_32 -> V_46 ;
} else {
if ( V_32 -> V_46 > V_43 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_32 -> V_46 = V_43 ;
}
V_32 -> V_41 = ( V_32 -> V_40 + 1 + V_32 -> V_45 ) & ~ V_32 -> V_45 ;
}
V_32 -> V_42 = V_32 -> V_41 + V_32 -> V_46 - 1 ;
F_21 ( V_2 -> V_24 , L_10 ,
V_32 -> V_46 >> 20 , V_32 -> V_41 , V_32 -> V_42 ) ;
}
bool F_24 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( F_25 ( V_47 ) &&
V_2 -> V_48 -> V_49 == V_50 )
return false ;
if ( F_26 ( V_2 ) ) {
V_15 = F_27 ( V_51 + V_52 ) |
F_27 ( V_51 + V_53 ) ;
if ( V_15 & V_54 )
return true ;
} else if ( F_28 ( V_2 ) ) {
V_15 = F_27 ( V_51 + V_52 ) |
F_27 ( V_51 + V_53 ) |
F_27 ( V_51 + V_55 ) |
F_27 ( V_51 + V_56 ) |
F_27 ( V_51 + V_57 ) |
F_27 ( V_51 + V_58 ) ;
if ( V_15 & V_54 )
return true ;
} else if ( F_29 ( V_2 ) ) {
V_15 = F_27 ( V_59 ) |
F_27 ( V_60 ) ;
if ( V_15 & V_61 ) {
return true ;
}
} else {
V_15 = F_27 ( V_62 ) |
F_27 ( V_63 ) ;
if ( V_15 & V_64 ) {
return true ;
}
}
if ( V_2 -> V_3 >= V_4 )
V_15 = F_27 ( V_65 ) ;
else
V_15 = F_27 ( V_66 ) ;
if ( V_15 )
return true ;
return false ;
}
void F_30 ( struct V_1 * V_2 )
{
T_4 V_67 ;
T_5 V_68 = V_2 -> V_69 . V_70 ;
T_5 V_71 = V_2 -> V_69 . V_72 ;
V_67 . V_73 = F_31 ( 100 ) ;
V_2 -> V_69 . V_68 . V_73 = F_31 ( V_68 ) ;
V_2 -> V_69 . V_68 . V_73 = F_32 ( V_2 -> V_69 . V_68 , V_67 ) ;
V_2 -> V_69 . V_71 . V_73 = F_31 ( V_71 ) ;
V_2 -> V_69 . V_71 . V_73 = F_32 ( V_2 -> V_69 . V_71 , V_67 ) ;
if ( V_2 -> V_28 & V_74 ) {
V_67 . V_73 = F_31 ( 16 ) ;
V_2 -> V_69 . V_75 . V_73 = F_32 ( V_2 -> V_69 . V_68 , V_67 ) ;
}
}
bool F_33 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return true ;
if ( V_2 -> V_76 ) {
F_34 ( L_11 ) ;
if ( V_2 -> V_77 )
F_35 ( V_2 -> V_78 . V_79 ) ;
else
F_36 ( V_2 -> V_80 ) ;
return true ;
} else {
F_37 ( V_2 -> V_24 , L_12 ) ;
return false ;
}
}
int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 . V_82 )
return 0 ;
V_2 -> V_81 . V_82 = F_39 ( V_83 | V_84 | V_85 ) ;
if ( V_2 -> V_81 . V_82 == NULL )
return - V_86 ;
V_2 -> V_81 . V_87 = F_40 ( V_2 -> V_48 , V_2 -> V_81 . V_82 ,
0 , V_22 , V_88 ) ;
if ( F_41 ( V_2 -> V_48 , V_2 -> V_81 . V_87 ) ) {
F_37 ( & V_2 -> V_48 -> V_24 , L_13 ) ;
F_42 ( V_2 -> V_81 . V_82 ) ;
V_2 -> V_81 . V_82 = NULL ;
return - V_86 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 . V_82 == NULL )
return;
F_44 ( V_2 -> V_48 , V_2 -> V_81 . V_87 ,
V_22 , V_88 ) ;
F_42 ( V_2 -> V_81 . V_82 ) ;
V_2 -> V_81 . V_82 = NULL ;
}
static T_1 F_45 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = V_2 -> V_92 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_46 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
V_2 -> V_94 ( V_2 , V_15 , V_93 ) ;
}
static T_1 F_47 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = V_2 -> V_95 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_48 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
V_2 -> V_96 ( V_2 , V_15 , V_93 ) ;
}
static void F_49 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
F_4 ( V_15 * 4 , V_93 ) ;
}
static T_1 F_50 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = F_27 ( V_15 * 4 ) ;
return V_17 ;
}
static void F_51 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
F_52 ( V_15 * 4 , V_93 ) ;
}
static T_1 F_53 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = F_54 ( V_15 * 4 ) ;
return V_17 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_89 * V_97 =
F_56 ( sizeof( struct V_89 ) , V_84 ) ;
if ( ! V_97 )
return - V_86 ;
V_2 -> V_78 . V_97 = V_97 ;
V_97 -> V_24 = V_2 -> V_80 ;
V_97 -> V_98 = F_50 ;
V_97 -> V_99 = F_49 ;
if ( V_2 -> V_100 ) {
V_97 -> V_101 = F_53 ;
V_97 -> V_102 = F_51 ;
} else {
F_57 ( L_14 ) ;
V_97 -> V_101 = F_50 ;
V_97 -> V_102 = F_49 ;
}
V_97 -> V_103 = F_47 ;
V_97 -> V_104 = F_48 ;
V_97 -> V_105 = F_45 ;
V_97 -> V_106 = F_46 ;
V_2 -> V_78 . V_79 = F_58 ( V_97 , V_2 -> V_76 ) ;
if ( ! V_2 -> V_78 . V_79 ) {
F_59 ( V_2 ) ;
return - V_86 ;
}
F_60 ( & V_2 -> V_78 . V_79 -> V_107 ) ;
F_61 ( V_2 -> V_80 ) ;
F_62 ( V_2 -> V_78 . V_79 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 . V_79 ) {
F_63 ( V_2 -> V_78 . V_79 -> V_11 ) ;
}
F_63 ( V_2 -> V_78 . V_79 ) ;
V_2 -> V_78 . V_79 = NULL ;
F_63 ( V_2 -> V_78 . V_97 ) ;
V_2 -> V_78 . V_97 = NULL ;
}
int F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_80 ) ;
return 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
}
static unsigned int F_67 ( void * V_108 , bool V_109 )
{
struct V_1 * V_2 = V_108 ;
F_68 ( V_2 , V_109 ) ;
if ( V_109 )
return V_110 | V_111 |
V_112 | V_113 ;
else
return V_112 | V_113 ;
}
static bool F_69 ( int V_114 )
{
return ( V_114 & ( V_114 - 1 ) ) == 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
if ( ! F_69 ( V_35 ) ) {
F_18 ( V_2 -> V_24 , L_15 ,
V_35 ) ;
V_35 = 0 ;
}
if ( V_115 < 32 ) {
F_18 ( V_2 -> V_24 , L_16 ,
V_115 ) ;
V_115 = 512 ;
} else if ( ! F_69 ( V_115 ) ) {
F_18 ( V_2 -> V_24 , L_17 ,
V_115 ) ;
V_115 = 512 ;
}
V_2 -> V_32 . V_46 = ( T_3 ) V_115 << 20 ;
switch ( V_116 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_18 ( V_2 -> V_24 , L_18
L_19 , V_116 ) ;
V_116 = 0 ;
break;
}
}
static bool F_71 ( struct V_117 * V_48 )
{
if ( V_48 -> V_49 == V_50 &&
V_48 -> V_118 == 0x00e2 ) {
F_72 ( V_119 L_20 ) ;
return true ;
}
return false ;
}
static void F_73 ( struct V_117 * V_48 , enum V_120 V_109 )
{
struct V_121 * V_24 = F_74 ( V_48 ) ;
T_6 V_122 = { . V_123 = V_124 } ;
if ( V_109 == V_125 ) {
unsigned V_126 = V_24 -> V_48 -> V_126 ;
F_72 ( V_119 L_21 ) ;
V_24 -> V_127 = V_128 ;
if ( V_126 < 20 && F_71 ( V_48 ) )
V_24 -> V_48 -> V_126 = 20 ;
F_75 ( V_24 ) ;
V_24 -> V_48 -> V_126 = V_126 ;
V_24 -> V_127 = V_129 ;
F_76 ( V_24 ) ;
} else {
F_72 ( V_119 L_22 ) ;
F_77 ( V_24 ) ;
V_24 -> V_127 = V_128 ;
F_78 ( V_24 , V_122 ) ;
V_24 -> V_127 = V_130 ;
}
}
static bool F_79 ( struct V_117 * V_48 )
{
struct V_121 * V_24 = F_74 ( V_48 ) ;
bool V_131 ;
F_80 ( & V_24 -> V_132 ) ;
V_131 = ( V_24 -> V_133 == 0 ) ;
F_81 ( & V_24 -> V_132 ) ;
return V_131 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_121 * V_80 ,
struct V_117 * V_48 ,
T_1 V_28 )
{
int V_17 , V_5 ;
int V_134 ;
V_2 -> V_135 = false ;
V_2 -> V_24 = & V_48 -> V_24 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_3 = V_28 & V_136 ;
V_2 -> V_77 = false ;
V_2 -> V_137 = V_138 ;
V_2 -> V_32 . V_46 = V_115 * 1024 * 1024 ;
V_2 -> V_139 = false ;
for ( V_5 = 0 ; V_5 < V_140 ; V_5 ++ ) {
V_2 -> V_141 [ V_5 ] . V_142 = V_5 ;
}
F_34 ( L_23 ,
V_143 [ V_2 -> V_3 ] , V_48 -> V_144 , V_48 -> V_145 ,
V_48 -> V_49 , V_48 -> V_118 ) ;
F_60 ( & V_2 -> V_146 ) ;
F_60 ( & V_2 -> V_147 ) ;
F_83 ( & V_2 -> V_148 . V_149 , 0 ) ;
F_60 ( & V_2 -> V_150 . V_107 ) ;
F_60 ( & V_2 -> V_69 . V_107 ) ;
F_60 ( & V_2 -> V_151 ) ;
F_84 ( & V_2 -> V_69 . V_152 ) ;
F_84 ( & V_2 -> V_153 ) ;
F_85 ( & V_2 -> V_154 . V_155 ) ;
V_17 = F_86 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_60 ( & V_2 -> V_156 . V_149 ) ;
V_2 -> V_156 . V_157 = 1 << 20 ;
F_87 ( & V_2 -> V_156 . V_158 ) ;
V_17 = F_88 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_70 ( V_2 ) ;
if ( ( V_2 -> V_3 >= V_159 ) &&
( V_2 -> V_28 & V_74 ) ) {
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_28 & V_29 && V_116 == - 1 ) {
F_89 ( V_2 ) ;
}
V_2 -> V_160 = false ;
if ( V_2 -> V_28 & V_29 )
V_2 -> V_160 = true ;
if ( ( V_2 -> V_28 & V_161 ) &&
( V_2 -> V_3 <= V_162 ) )
V_2 -> V_160 = true ;
V_134 = V_2 -> V_160 ? 32 : 40 ;
V_17 = F_90 ( V_2 -> V_48 , F_91 ( V_134 ) ) ;
if ( V_17 ) {
V_2 -> V_160 = true ;
V_134 = 32 ;
F_72 ( V_163 L_24 ) ;
}
V_17 = F_92 ( V_2 -> V_48 , F_91 ( V_134 ) ) ;
if ( V_17 ) {
F_92 ( V_2 -> V_48 , F_91 ( 32 ) ) ;
F_72 ( V_163 L_25 ) ;
}
F_93 ( & V_2 -> V_164 ) ;
V_2 -> V_165 = F_94 ( V_2 -> V_48 , 2 ) ;
V_2 -> V_166 = F_95 ( V_2 -> V_48 , 2 ) ;
V_2 -> V_167 = F_96 ( V_2 -> V_165 , V_2 -> V_166 ) ;
if ( V_2 -> V_167 == NULL ) {
return - V_86 ;
}
F_34 ( L_26 , ( T_1 ) V_2 -> V_165 ) ;
F_34 ( L_27 , ( unsigned ) V_2 -> V_166 ) ;
for ( V_5 = 0 ; V_5 < V_168 ; V_5 ++ ) {
if ( F_97 ( V_2 -> V_48 , V_5 ) & V_169 ) {
V_2 -> V_170 = F_95 ( V_2 -> V_48 , V_5 ) ;
V_2 -> V_100 = F_98 ( V_2 -> V_48 , V_5 , V_2 -> V_170 ) ;
break;
}
}
if ( V_2 -> V_100 == NULL )
F_57 ( L_28 ) ;
F_99 ( V_2 -> V_48 , V_2 , NULL , F_67 ) ;
F_100 ( V_2 -> V_48 , & V_171 ) ;
V_17 = F_101 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_102 ( V_2 ) ;
if ( V_17 )
F_57 ( L_29 , V_17 ) ;
if ( V_2 -> V_28 & V_29 && ! V_2 -> V_139 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
F_89 ( V_2 ) ;
V_17 = F_101 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( ( V_172 & 1 ) ) {
F_105 ( V_2 ) ;
}
if ( ( V_172 & 2 ) ) {
F_106 ( V_2 ) ;
}
if ( V_173 ) {
F_107 ( V_2 , V_173 ) ;
}
return 0 ;
}
void F_108 ( struct V_1 * V_2 )
{
F_34 ( L_30 ) ;
V_2 -> V_135 = true ;
F_109 ( V_2 ) ;
F_104 ( V_2 ) ;
F_110 ( V_2 -> V_48 ) ;
F_99 ( V_2 -> V_48 , NULL , NULL , NULL ) ;
if ( V_2 -> V_100 )
F_111 ( V_2 -> V_48 , V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
F_112 ( V_2 -> V_167 ) ;
V_2 -> V_167 = NULL ;
F_113 ( V_2 ) ;
}
int F_78 ( struct V_121 * V_24 , T_6 V_109 )
{
struct V_1 * V_2 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
int V_5 , V_17 ;
bool V_178 = false ;
if ( V_24 == NULL || V_24 -> V_91 == NULL ) {
return - V_179 ;
}
if ( V_109 . V_123 == V_180 ) {
return 0 ;
}
V_2 = V_24 -> V_91 ;
if ( V_24 -> V_127 == V_130 )
return 0 ;
F_77 ( V_24 ) ;
F_114 (connector, &dev->mode_config.connector_list, head) {
F_115 ( V_177 , V_181 ) ;
}
F_114 (crtc, &dev->mode_config.crtc_list, head) {
struct V_182 * V_183 = F_116 ( V_175 -> V_184 ) ;
struct V_185 * V_186 ;
if ( V_183 == NULL || V_183 -> V_187 == NULL ) {
continue;
}
V_186 = F_117 ( V_183 -> V_187 ) ;
if ( ! F_118 ( V_2 , V_186 ) ) {
V_17 = F_9 ( V_186 , false ) ;
if ( V_17 == 0 ) {
F_12 ( V_186 ) ;
F_13 ( V_186 ) ;
}
}
}
F_109 ( V_2 ) ;
F_119 ( & V_2 -> V_146 ) ;
for ( V_5 = 0 ; V_5 < V_140 ; V_5 ++ ) {
V_17 = F_120 ( V_2 , V_5 ) ;
if ( V_17 ) {
V_178 = true ;
}
}
if ( V_178 ) {
F_121 ( V_2 ) ;
}
F_122 ( & V_2 -> V_146 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_109 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_24 -> V_48 ) ;
if ( V_109 . V_123 == V_124 ) {
F_129 ( V_24 -> V_48 ) ;
F_130 ( V_24 -> V_48 , V_188 ) ;
}
F_131 () ;
F_132 ( V_2 , 1 ) ;
F_133 () ;
return 0 ;
}
int F_75 ( struct V_121 * V_24 )
{
struct V_176 * V_177 ;
struct V_1 * V_2 = V_24 -> V_91 ;
int V_17 ;
if ( V_24 -> V_127 == V_130 )
return 0 ;
F_131 () ;
F_130 ( V_24 -> V_48 , V_189 ) ;
F_134 ( V_24 -> V_48 ) ;
if ( F_135 ( V_24 -> V_48 ) ) {
F_133 () ;
return - 1 ;
}
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
V_17 = F_102 ( V_2 ) ;
if ( V_17 )
F_57 ( L_29 , V_17 ) ;
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
F_132 ( V_2 , 0 ) ;
F_133 () ;
if ( V_2 -> V_77 ) {
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
if ( V_2 -> V_78 . V_190 ) {
T_7 V_191 = F_142 ( V_2 ,
V_2 -> V_78 . V_190 ) ;
F_143 ( V_2 , V_2 -> V_78 . V_190 ,
V_191 ) ;
}
}
F_144 ( V_2 ) ;
F_145 ( V_24 ) ;
F_114 (connector, &dev->mode_config.connector_list, head) {
F_115 ( V_177 , V_192 ) ;
}
F_76 ( V_24 ) ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 )
{
unsigned V_193 [ V_140 ] ;
T_1 * V_194 [ V_140 ] ;
bool V_195 = false ;
int V_5 , V_17 ;
int V_196 ;
F_147 ( & V_2 -> V_153 ) ;
F_123 ( V_2 ) ;
V_196 = F_148 ( & V_2 -> V_197 . V_198 ) ;
F_125 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_140 ; ++ V_5 ) {
V_193 [ V_5 ] = F_149 ( V_2 , & V_2 -> V_141 [ V_5 ] ,
& V_194 [ V_5 ] ) ;
if ( V_193 [ V_5 ] ) {
V_195 = true ;
F_21 ( V_2 -> V_24 , L_31
L_32 , V_193 [ V_5 ] , V_5 ) ;
}
}
V_199:
V_17 = F_103 ( V_2 ) ;
if ( ! V_17 ) {
F_21 ( V_2 -> V_24 , L_33 ) ;
F_137 ( V_2 ) ;
}
F_139 ( V_2 ) ;
if ( ! V_17 ) {
for ( V_5 = 0 ; V_5 < V_140 ; ++ V_5 ) {
F_150 ( V_2 , & V_2 -> V_141 [ V_5 ] ,
V_193 [ V_5 ] , V_194 [ V_5 ] ) ;
V_193 [ V_5 ] = 0 ;
V_194 [ V_5 ] = NULL ;
}
V_17 = F_102 ( V_2 ) ;
if ( V_17 ) {
F_37 ( V_2 -> V_24 , L_29 , V_17 ) ;
if ( V_195 ) {
V_195 = false ;
F_125 ( V_2 ) ;
goto V_199;
}
}
} else {
F_121 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_140 ; ++ V_5 ) {
F_63 ( V_194 [ V_5 ] ) ;
}
}
F_145 ( V_2 -> V_80 ) ;
F_151 ( & V_2 -> V_197 . V_198 , V_196 ) ;
if ( V_17 ) {
F_21 ( V_2 -> V_24 , L_34 ) ;
}
F_152 ( & V_2 -> V_153 ) ;
return V_17 ;
}
int F_153 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
unsigned V_202 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_203 ; V_5 ++ ) {
if ( V_2 -> V_204 [ V_5 ] . V_201 == V_201 ) {
return 0 ;
}
}
V_5 = V_2 -> V_203 + 1 ;
if ( V_5 > V_205 ) {
F_57 ( L_35 ) ;
F_57 ( L_36
L_37 ) ;
return - V_16 ;
}
V_2 -> V_204 [ V_2 -> V_203 ] . V_201 = V_201 ;
V_2 -> V_204 [ V_2 -> V_203 ] . V_206 = V_202 ;
V_2 -> V_203 = V_5 ;
#if F_154 ( V_207 )
F_155 ( V_201 , V_202 ,
V_2 -> V_80 -> V_208 -> V_209 ,
V_2 -> V_80 -> V_208 ) ;
F_155 ( V_201 , V_202 ,
V_2 -> V_80 -> V_210 -> V_209 ,
V_2 -> V_80 -> V_210 ) ;
#endif
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
#if F_154 ( V_207 )
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_203 ; V_5 ++ ) {
F_156 ( V_2 -> V_204 [ V_5 ] . V_201 ,
V_2 -> V_204 [ V_5 ] . V_206 ,
V_2 -> V_80 -> V_208 ) ;
F_156 ( V_2 -> V_204 [ V_5 ] . V_201 ,
V_2 -> V_204 [ V_5 ] . V_206 ,
V_2 -> V_80 -> V_210 ) ;
}
#endif
}
int F_157 ( struct V_211 * V_212 )
{
return 0 ;
}
void F_158 ( struct V_211 * V_212 )
{
}
