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
if ( V_47 && V_2 -> V_48 -> V_49 == V_50 )
return false ;
if ( F_25 ( V_2 ) ) {
V_15 = F_26 ( V_51 + V_52 ) |
F_26 ( V_51 + V_53 ) ;
if ( V_15 & V_54 )
return true ;
} else if ( F_27 ( V_2 ) ) {
V_15 = F_26 ( V_51 + V_52 ) |
F_26 ( V_51 + V_53 ) |
F_26 ( V_51 + V_55 ) |
F_26 ( V_51 + V_56 ) |
F_26 ( V_51 + V_57 ) |
F_26 ( V_51 + V_58 ) ;
if ( V_15 & V_54 )
return true ;
} else if ( F_28 ( V_2 ) ) {
V_15 = F_26 ( V_59 ) |
F_26 ( V_60 ) ;
if ( V_15 & V_61 ) {
return true ;
}
} else {
V_15 = F_26 ( V_62 ) |
F_26 ( V_63 ) ;
if ( V_15 & V_64 ) {
return true ;
}
}
if ( V_2 -> V_3 >= V_4 )
V_15 = F_26 ( V_65 ) ;
else
V_15 = F_26 ( V_66 ) ;
if ( V_15 )
return true ;
return false ;
}
void F_29 ( struct V_1 * V_2 )
{
T_4 V_67 ;
T_5 V_68 = V_2 -> V_69 . V_70 ;
T_5 V_71 = V_2 -> V_69 . V_72 ;
V_67 . V_73 = F_30 ( 100 ) ;
V_2 -> V_69 . V_68 . V_73 = F_30 ( V_68 ) ;
V_2 -> V_69 . V_68 . V_73 = F_31 ( V_2 -> V_69 . V_68 , V_67 ) ;
V_2 -> V_69 . V_71 . V_73 = F_30 ( V_71 ) ;
V_2 -> V_69 . V_71 . V_73 = F_31 ( V_2 -> V_69 . V_71 , V_67 ) ;
if ( V_2 -> V_28 & V_74 ) {
V_67 . V_73 = F_30 ( 16 ) ;
V_2 -> V_69 . V_75 . V_73 = F_31 ( V_2 -> V_69 . V_68 , V_67 ) ;
}
}
bool F_32 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return true ;
if ( V_2 -> V_76 ) {
F_33 ( L_11 ) ;
if ( V_2 -> V_77 )
F_34 ( V_2 -> V_78 . V_79 ) ;
else
F_35 ( V_2 -> V_80 ) ;
return true ;
} else {
F_36 ( V_2 -> V_24 , L_12 ) ;
return false ;
}
}
int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 . V_82 )
return 0 ;
V_2 -> V_81 . V_82 = F_38 ( V_83 | V_84 | V_85 ) ;
if ( V_2 -> V_81 . V_82 == NULL )
return - V_86 ;
V_2 -> V_81 . V_87 = F_39 ( V_2 -> V_48 , V_2 -> V_81 . V_82 ,
0 , V_22 , V_88 ) ;
if ( F_40 ( V_2 -> V_48 , V_2 -> V_81 . V_87 ) ) {
F_36 ( & V_2 -> V_48 -> V_24 , L_13 ) ;
F_41 ( V_2 -> V_81 . V_82 ) ;
V_2 -> V_81 . V_82 = NULL ;
return - V_86 ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 . V_82 == NULL )
return;
F_43 ( V_2 -> V_48 , V_2 -> V_81 . V_87 ,
V_22 , V_88 ) ;
F_41 ( V_2 -> V_81 . V_82 ) ;
V_2 -> V_81 . V_82 = NULL ;
}
static T_1 F_44 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = V_2 -> V_92 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_45 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
V_2 -> V_94 ( V_2 , V_15 , V_93 ) ;
}
static T_1 F_46 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = V_2 -> V_95 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_47 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
V_2 -> V_96 ( V_2 , V_15 , V_93 ) ;
}
static void F_48 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
F_4 ( V_15 * 4 , V_93 ) ;
}
static T_1 F_49 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = F_26 ( V_15 * 4 ) ;
return V_17 ;
}
static void F_50 ( struct V_89 * V_90 , T_1 V_15 , T_1 V_93 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
F_51 ( V_15 * 4 , V_93 ) ;
}
static T_1 F_52 ( struct V_89 * V_90 , T_1 V_15 )
{
struct V_1 * V_2 = V_90 -> V_24 -> V_91 ;
T_1 V_17 ;
V_17 = F_53 ( V_15 * 4 ) ;
return V_17 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_89 * V_97 =
F_55 ( sizeof( struct V_89 ) , V_84 ) ;
if ( ! V_97 )
return - V_86 ;
V_2 -> V_78 . V_97 = V_97 ;
V_97 -> V_24 = V_2 -> V_80 ;
V_97 -> V_98 = F_49 ;
V_97 -> V_99 = F_48 ;
if ( V_2 -> V_100 ) {
V_97 -> V_101 = F_52 ;
V_97 -> V_102 = F_50 ;
} else {
F_56 ( L_14 ) ;
V_97 -> V_101 = F_49 ;
V_97 -> V_102 = F_48 ;
}
V_97 -> V_103 = F_46 ;
V_97 -> V_104 = F_47 ;
V_97 -> V_105 = F_44 ;
V_97 -> V_106 = F_45 ;
V_2 -> V_78 . V_79 = F_57 ( V_97 , V_2 -> V_76 ) ;
F_58 ( & V_2 -> V_78 . V_79 -> V_107 ) ;
F_59 ( V_2 -> V_80 ) ;
F_60 ( V_2 -> V_78 . V_79 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 . V_79 ) {
F_62 ( V_2 -> V_78 . V_79 -> V_11 ) ;
F_62 ( V_2 -> V_78 . V_79 ) ;
}
F_62 ( V_2 -> V_78 . V_97 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_80 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 )
{
}
static unsigned int F_66 ( void * V_108 , bool V_109 )
{
struct V_1 * V_2 = V_108 ;
F_67 ( V_2 , V_109 ) ;
if ( V_109 )
return V_110 | V_111 |
V_112 | V_113 ;
else
return V_112 | V_113 ;
}
static bool F_68 ( int V_114 )
{
return ( V_114 & ( V_114 - 1 ) ) == 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_35 ) ) {
F_18 ( V_2 -> V_24 , L_15 ,
V_35 ) ;
V_35 = 0 ;
}
if ( V_115 < 32 ) {
F_18 ( V_2 -> V_24 , L_16 ,
V_115 ) ;
V_115 = 512 ;
} else if ( ! F_68 ( V_115 ) ) {
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
static void F_70 ( struct V_117 * V_48 , enum V_118 V_109 )
{
struct V_119 * V_24 = F_71 ( V_48 ) ;
T_6 V_120 = { . V_121 = V_122 } ;
if ( V_109 == V_123 ) {
F_72 ( V_124 L_20 ) ;
V_24 -> V_125 = V_126 ;
F_73 ( V_24 ) ;
V_24 -> V_125 = V_127 ;
F_74 ( V_24 ) ;
} else {
F_72 ( V_124 L_21 ) ;
F_75 ( V_24 ) ;
V_24 -> V_125 = V_126 ;
F_76 ( V_24 , V_120 ) ;
V_24 -> V_125 = V_128 ;
}
}
static bool F_77 ( struct V_117 * V_48 )
{
struct V_119 * V_24 = F_71 ( V_48 ) ;
bool V_129 ;
F_78 ( & V_24 -> V_130 ) ;
V_129 = ( V_24 -> V_131 == 0 ) ;
F_79 ( & V_24 -> V_130 ) ;
return V_129 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_119 * V_80 ,
struct V_117 * V_48 ,
T_1 V_28 )
{
int V_17 , V_5 ;
int V_132 ;
V_2 -> V_133 = false ;
V_2 -> V_24 = & V_48 -> V_24 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_3 = V_28 & V_134 ;
V_2 -> V_77 = false ;
V_2 -> V_135 = V_136 ;
V_2 -> V_32 . V_46 = V_115 * 1024 * 1024 ;
V_2 -> V_137 = false ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ ) {
V_2 -> V_139 [ V_5 ] . V_140 = V_5 ;
}
F_33 ( L_22 ,
V_141 [ V_2 -> V_3 ] , V_48 -> V_142 , V_48 -> V_143 ,
V_48 -> V_49 , V_48 -> V_144 ) ;
F_58 ( & V_2 -> V_145 ) ;
F_58 ( & V_2 -> V_146 ) ;
F_81 ( & V_2 -> V_147 . V_148 , 0 ) ;
F_58 ( & V_2 -> V_149 . V_107 ) ;
F_58 ( & V_2 -> V_69 . V_107 ) ;
F_58 ( & V_2 -> V_150 ) ;
F_82 ( & V_2 -> V_69 . V_151 ) ;
F_82 ( & V_2 -> V_152 ) ;
F_83 ( & V_2 -> V_153 . V_154 ) ;
V_17 = F_84 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_58 ( & V_2 -> V_155 . V_148 ) ;
V_2 -> V_155 . V_156 = 1 << 20 ;
F_85 ( & V_2 -> V_155 . V_157 ) ;
V_17 = F_86 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_69 ( V_2 ) ;
if ( ( V_2 -> V_3 >= V_158 ) &&
( V_2 -> V_28 & V_74 ) ) {
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_28 & V_29 && V_116 == - 1 ) {
F_87 ( V_2 ) ;
}
V_2 -> V_159 = false ;
if ( V_2 -> V_28 & V_29 )
V_2 -> V_159 = true ;
if ( ( V_2 -> V_28 & V_160 ) &&
( V_2 -> V_3 <= V_161 ) )
V_2 -> V_159 = true ;
V_132 = V_2 -> V_159 ? 32 : 40 ;
V_17 = F_88 ( V_2 -> V_48 , F_89 ( V_132 ) ) ;
if ( V_17 ) {
V_2 -> V_159 = true ;
V_132 = 32 ;
F_72 ( V_162 L_23 ) ;
}
V_17 = F_90 ( V_2 -> V_48 , F_89 ( V_132 ) ) ;
if ( V_17 ) {
F_90 ( V_2 -> V_48 , F_89 ( 32 ) ) ;
F_72 ( V_162 L_24 ) ;
}
V_2 -> V_163 = F_91 ( V_2 -> V_48 , 2 ) ;
V_2 -> V_164 = F_92 ( V_2 -> V_48 , 2 ) ;
V_2 -> V_165 = F_93 ( V_2 -> V_163 , V_2 -> V_164 ) ;
if ( V_2 -> V_165 == NULL ) {
return - V_86 ;
}
F_33 ( L_25 , ( T_1 ) V_2 -> V_163 ) ;
F_33 ( L_26 , ( unsigned ) V_2 -> V_164 ) ;
for ( V_5 = 0 ; V_5 < V_166 ; V_5 ++ ) {
if ( F_94 ( V_2 -> V_48 , V_5 ) & V_167 ) {
V_2 -> V_168 = F_92 ( V_2 -> V_48 , V_5 ) ;
V_2 -> V_100 = F_95 ( V_2 -> V_48 , V_5 , V_2 -> V_168 ) ;
break;
}
}
if ( V_2 -> V_100 == NULL )
F_56 ( L_27 ) ;
F_96 ( V_2 -> V_48 , V_2 , NULL , F_66 ) ;
F_97 ( V_2 -> V_48 , & V_169 ) ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_99 ( V_2 ) ;
if ( V_17 )
F_56 ( L_28 , V_17 ) ;
if ( V_2 -> V_28 & V_29 && ! V_2 -> V_137 ) {
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_87 ( V_2 ) ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( ( V_170 & 1 ) ) {
F_102 ( V_2 ) ;
}
if ( ( V_170 & 2 ) ) {
F_103 ( V_2 ) ;
}
if ( V_171 ) {
F_104 ( V_2 , V_171 ) ;
}
return 0 ;
}
void F_105 ( struct V_1 * V_2 )
{
F_33 ( L_29 ) ;
V_2 -> V_133 = true ;
F_106 ( V_2 ) ;
F_101 ( V_2 ) ;
F_107 ( V_2 -> V_48 ) ;
F_96 ( V_2 -> V_48 , NULL , NULL , NULL ) ;
if ( V_2 -> V_100 )
F_108 ( V_2 -> V_48 , V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
F_109 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
F_110 ( V_2 ) ;
}
int F_76 ( struct V_119 * V_24 , T_6 V_109 )
{
struct V_1 * V_2 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_5 , V_17 ;
if ( V_24 == NULL || V_24 -> V_91 == NULL ) {
return - V_176 ;
}
if ( V_109 . V_121 == V_177 ) {
return 0 ;
}
V_2 = V_24 -> V_91 ;
if ( V_24 -> V_125 == V_128 )
return 0 ;
F_75 ( V_24 ) ;
F_111 (connector, &dev->mode_config.connector_list, head) {
F_112 ( V_175 , V_178 ) ;
}
F_111 (crtc, &dev->mode_config.crtc_list, head) {
struct V_179 * V_180 = F_113 ( V_173 -> V_181 ) ;
struct V_182 * V_183 ;
if ( V_180 == NULL || V_180 -> V_184 == NULL ) {
continue;
}
V_183 = F_114 ( V_180 -> V_184 ) ;
if ( ! F_115 ( V_2 , V_183 ) ) {
V_17 = F_9 ( V_183 , false ) ;
if ( V_17 == 0 ) {
F_12 ( V_183 ) ;
F_13 ( V_183 ) ;
}
}
}
F_106 ( V_2 ) ;
F_116 ( & V_2 -> V_145 ) ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ )
F_117 ( V_2 , V_5 ) ;
F_118 ( & V_2 -> V_145 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_106 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_24 -> V_48 ) ;
if ( V_109 . V_121 == V_122 ) {
F_125 ( V_24 -> V_48 ) ;
F_126 ( V_24 -> V_48 , V_185 ) ;
}
F_127 () ;
F_128 ( V_2 , 1 ) ;
F_129 () ;
return 0 ;
}
int F_73 ( struct V_119 * V_24 )
{
struct V_174 * V_175 ;
struct V_1 * V_2 = V_24 -> V_91 ;
int V_17 ;
if ( V_24 -> V_125 == V_128 )
return 0 ;
F_127 () ;
F_126 ( V_24 -> V_48 , V_186 ) ;
F_130 ( V_24 -> V_48 ) ;
if ( F_131 ( V_24 -> V_48 ) ) {
F_129 () ;
return - 1 ;
}
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
V_17 = F_99 ( V_2 ) ;
if ( V_17 )
F_56 ( L_28 , V_17 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_128 ( V_2 , 0 ) ;
F_129 () ;
if ( V_2 -> V_77 ) {
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
if ( V_2 -> V_78 . V_187 ) {
T_7 V_188 = F_138 ( V_2 ,
V_2 -> V_78 . V_187 ) ;
F_139 ( V_2 , V_2 -> V_78 . V_187 ,
V_188 ) ;
}
}
F_140 ( V_2 ) ;
F_141 ( V_24 ) ;
F_111 (connector, &dev->mode_config.connector_list, head) {
F_112 ( V_175 , V_189 ) ;
}
F_74 ( V_24 ) ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 )
{
unsigned V_190 [ V_138 ] ;
T_1 * V_191 [ V_138 ] ;
bool V_192 = false ;
int V_5 , V_17 ;
int V_193 ;
F_143 ( & V_2 -> V_152 ) ;
F_119 ( V_2 ) ;
V_193 = F_144 ( & V_2 -> V_194 . V_195 ) ;
F_121 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_138 ; ++ V_5 ) {
V_190 [ V_5 ] = F_145 ( V_2 , & V_2 -> V_139 [ V_5 ] ,
& V_191 [ V_5 ] ) ;
if ( V_190 [ V_5 ] ) {
V_192 = true ;
F_21 ( V_2 -> V_24 , L_30
L_31 , V_190 [ V_5 ] , V_5 ) ;
}
}
V_196:
V_17 = F_100 ( V_2 ) ;
if ( ! V_17 ) {
F_21 ( V_2 -> V_24 , L_32 ) ;
F_133 ( V_2 ) ;
}
F_135 ( V_2 ) ;
F_141 ( V_2 -> V_80 ) ;
if ( ! V_17 ) {
for ( V_5 = 0 ; V_5 < V_138 ; ++ V_5 ) {
F_146 ( V_2 , & V_2 -> V_139 [ V_5 ] ,
V_190 [ V_5 ] , V_191 [ V_5 ] ) ;
V_190 [ V_5 ] = 0 ;
V_191 [ V_5 ] = NULL ;
}
V_17 = F_99 ( V_2 ) ;
if ( V_17 ) {
F_36 ( V_2 -> V_24 , L_28 , V_17 ) ;
if ( V_192 ) {
V_192 = false ;
F_121 ( V_2 ) ;
goto V_196;
}
}
} else {
for ( V_5 = 0 ; V_5 < V_138 ; ++ V_5 ) {
F_62 ( V_191 [ V_5 ] ) ;
}
}
F_147 ( & V_2 -> V_194 . V_195 , V_193 ) ;
if ( V_17 ) {
F_21 ( V_2 -> V_24 , L_33 ) ;
}
F_148 ( & V_2 -> V_152 ) ;
return V_17 ;
}
int F_149 ( struct V_1 * V_2 ,
struct V_197 * V_198 ,
unsigned V_199 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_200 ; V_5 ++ ) {
if ( V_2 -> V_201 [ V_5 ] . V_198 == V_198 ) {
return 0 ;
}
}
V_5 = V_2 -> V_200 + 1 ;
if ( V_5 > V_202 ) {
F_56 ( L_34 ) ;
F_56 ( L_35
L_36 ) ;
return - V_16 ;
}
V_2 -> V_201 [ V_2 -> V_200 ] . V_198 = V_198 ;
V_2 -> V_201 [ V_2 -> V_200 ] . V_203 = V_199 ;
V_2 -> V_200 = V_5 ;
#if F_150 ( V_204 )
F_151 ( V_198 , V_199 ,
V_2 -> V_80 -> V_205 -> V_206 ,
V_2 -> V_80 -> V_205 ) ;
F_151 ( V_198 , V_199 ,
V_2 -> V_80 -> V_207 -> V_206 ,
V_2 -> V_80 -> V_207 ) ;
#endif
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
#if F_150 ( V_204 )
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_200 ; V_5 ++ ) {
F_152 ( V_2 -> V_201 [ V_5 ] . V_198 ,
V_2 -> V_201 [ V_5 ] . V_203 ,
V_2 -> V_80 -> V_205 ) ;
F_152 ( V_2 -> V_201 [ V_5 ] . V_198 ,
V_2 -> V_201 [ V_5 ] . V_203 ,
V_2 -> V_80 -> V_207 ) ;
}
#endif
}
int F_153 ( struct V_208 * V_209 )
{
return 0 ;
}
void F_154 ( struct V_208 * V_209 )
{
}
