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
V_32 -> V_34 = V_33 ;
if ( V_32 -> V_35 > ( 0xFFFFFFFF - V_33 + 1 ) ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_32 -> V_36 = V_32 -> V_37 ;
V_32 -> V_35 = V_32 -> V_37 ;
}
V_32 -> V_38 = V_32 -> V_34 + V_32 -> V_35 - 1 ;
if ( V_2 -> V_28 & V_29 && V_32 -> V_38 > V_32 -> V_39 && V_32 -> V_34 <= V_32 -> V_40 ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_32 -> V_36 = V_32 -> V_37 ;
V_32 -> V_35 = V_32 -> V_37 ;
}
V_32 -> V_38 = V_32 -> V_34 + V_32 -> V_35 - 1 ;
if ( V_41 && V_41 < V_32 -> V_36 )
V_32 -> V_36 = V_41 ;
F_21 ( V_2 -> V_24 , L_8 ,
V_32 -> V_35 >> 20 , V_32 -> V_34 ,
V_32 -> V_38 , V_32 -> V_36 >> 20 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_2 V_42 , V_43 ;
V_42 = ( ( 0xFFFFFFFF - V_32 -> V_38 ) + V_32 -> V_44 ) & ~ V_32 -> V_44 ;
V_43 = V_32 -> V_34 & ~ V_32 -> V_44 ;
if ( V_43 > V_42 ) {
if ( V_32 -> V_45 > V_43 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_32 -> V_45 = V_43 ;
}
V_32 -> V_39 = ( V_32 -> V_34 & ~ V_32 -> V_44 ) - V_32 -> V_45 ;
} else {
if ( V_32 -> V_45 > V_42 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_32 -> V_45 = V_42 ;
}
V_32 -> V_39 = ( V_32 -> V_38 + 1 + V_32 -> V_44 ) & ~ V_32 -> V_44 ;
}
V_32 -> V_40 = V_32 -> V_39 + V_32 -> V_45 - 1 ;
F_21 ( V_2 -> V_24 , L_10 ,
V_32 -> V_45 >> 20 , V_32 -> V_39 , V_32 -> V_40 ) ;
}
bool F_24 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( V_46 && V_2 -> V_47 -> V_48 == V_49 )
return false ;
if ( F_25 ( V_2 ) ) {
V_15 = F_26 ( V_50 + V_51 ) |
F_26 ( V_50 + V_52 ) ;
if ( V_15 & V_53 )
return true ;
} else if ( F_27 ( V_2 ) ) {
V_15 = F_26 ( V_50 + V_51 ) |
F_26 ( V_50 + V_52 ) |
F_26 ( V_50 + V_54 ) |
F_26 ( V_50 + V_55 ) |
F_26 ( V_50 + V_56 ) |
F_26 ( V_50 + V_57 ) ;
if ( V_15 & V_53 )
return true ;
} else if ( F_28 ( V_2 ) ) {
V_15 = F_26 ( V_58 ) |
F_26 ( V_59 ) ;
if ( V_15 & V_60 ) {
return true ;
}
} else {
V_15 = F_26 ( V_61 ) |
F_26 ( V_62 ) ;
if ( V_15 & V_63 ) {
return true ;
}
}
if ( V_2 -> V_3 >= V_4 )
V_15 = F_26 ( V_64 ) ;
else
V_15 = F_26 ( V_65 ) ;
if ( V_15 )
return true ;
return false ;
}
void F_29 ( struct V_1 * V_2 )
{
T_3 V_66 ;
T_4 V_67 = V_2 -> V_68 . V_69 ;
T_4 V_70 = V_2 -> V_68 . V_71 ;
V_66 . V_72 = F_30 ( 100 ) ;
V_2 -> V_68 . V_67 . V_72 = F_30 ( V_67 ) ;
V_2 -> V_68 . V_67 . V_72 = F_31 ( V_2 -> V_68 . V_67 , V_66 ) ;
V_2 -> V_68 . V_70 . V_72 = F_30 ( V_70 ) ;
V_2 -> V_68 . V_70 . V_72 = F_31 ( V_2 -> V_68 . V_70 , V_66 ) ;
if ( V_2 -> V_28 & V_73 ) {
V_66 . V_72 = F_30 ( 16 ) ;
V_2 -> V_68 . V_74 . V_72 = F_31 ( V_2 -> V_68 . V_67 , V_66 ) ;
}
}
bool F_32 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return true ;
if ( V_2 -> V_75 ) {
F_33 ( L_11 ) ;
if ( V_2 -> V_76 )
F_34 ( V_2 -> V_77 . V_78 ) ;
else
F_35 ( V_2 -> V_79 ) ;
return true ;
} else {
F_36 ( V_2 -> V_24 , L_12 ) ;
return false ;
}
}
int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_80 . V_81 )
return 0 ;
V_2 -> V_80 . V_81 = F_38 ( V_82 | V_83 | V_84 ) ;
if ( V_2 -> V_80 . V_81 == NULL )
return - V_85 ;
V_2 -> V_80 . V_86 = F_39 ( V_2 -> V_47 , V_2 -> V_80 . V_81 ,
0 , V_22 , V_87 ) ;
if ( F_40 ( V_2 -> V_47 , V_2 -> V_80 . V_86 ) ) {
F_36 ( & V_2 -> V_47 -> V_24 , L_13 ) ;
F_41 ( V_2 -> V_80 . V_81 ) ;
V_2 -> V_80 . V_81 = NULL ;
return - V_85 ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_80 . V_81 == NULL )
return;
F_43 ( V_2 -> V_47 , V_2 -> V_80 . V_86 ,
V_22 , V_87 ) ;
F_41 ( V_2 -> V_80 . V_81 ) ;
V_2 -> V_80 . V_81 = NULL ;
}
static T_1 F_44 ( struct V_88 * V_89 , T_1 V_15 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
T_1 V_17 ;
V_17 = V_2 -> V_91 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_45 ( struct V_88 * V_89 , T_1 V_15 , T_1 V_92 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
V_2 -> V_93 ( V_2 , V_15 , V_92 ) ;
}
static T_1 F_46 ( struct V_88 * V_89 , T_1 V_15 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
T_1 V_17 ;
V_17 = V_2 -> V_94 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_47 ( struct V_88 * V_89 , T_1 V_15 , T_1 V_92 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
V_2 -> V_95 ( V_2 , V_15 , V_92 ) ;
}
static void F_48 ( struct V_88 * V_89 , T_1 V_15 , T_1 V_92 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
F_4 ( V_15 * 4 , V_92 ) ;
}
static T_1 F_49 ( struct V_88 * V_89 , T_1 V_15 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
T_1 V_17 ;
V_17 = F_26 ( V_15 * 4 ) ;
return V_17 ;
}
static void F_50 ( struct V_88 * V_89 , T_1 V_15 , T_1 V_92 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
F_51 ( V_15 * 4 , V_92 ) ;
}
static T_1 F_52 ( struct V_88 * V_89 , T_1 V_15 )
{
struct V_1 * V_2 = V_89 -> V_24 -> V_90 ;
T_1 V_17 ;
V_17 = F_53 ( V_15 * 4 ) ;
return V_17 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_88 * V_96 =
F_55 ( sizeof( struct V_88 ) , V_83 ) ;
if ( ! V_96 )
return - V_85 ;
V_2 -> V_77 . V_96 = V_96 ;
V_96 -> V_24 = V_2 -> V_79 ;
V_96 -> V_97 = F_49 ;
V_96 -> V_98 = F_48 ;
if ( V_2 -> V_99 ) {
V_96 -> V_100 = F_52 ;
V_96 -> V_101 = F_50 ;
} else {
F_56 ( L_14 ) ;
V_96 -> V_100 = F_49 ;
V_96 -> V_101 = F_48 ;
}
V_96 -> V_102 = F_46 ;
V_96 -> V_103 = F_47 ;
V_96 -> V_104 = F_44 ;
V_96 -> V_105 = F_45 ;
V_2 -> V_77 . V_78 = F_57 ( V_96 , V_2 -> V_75 ) ;
F_58 ( & V_2 -> V_77 . V_78 -> V_106 ) ;
F_59 ( V_2 -> V_79 ) ;
F_60 ( V_2 -> V_77 . V_78 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_77 . V_78 ) {
F_62 ( V_2 -> V_77 . V_78 -> V_11 ) ;
F_62 ( V_2 -> V_77 . V_78 ) ;
}
F_62 ( V_2 -> V_77 . V_96 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_79 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 )
{
}
static unsigned int F_66 ( void * V_107 , bool V_108 )
{
struct V_1 * V_2 = V_107 ;
F_67 ( V_2 , V_108 ) ;
if ( V_108 )
return V_109 | V_110 |
V_111 | V_112 ;
else
return V_111 | V_112 ;
}
void F_68 ( struct V_1 * V_2 )
{
switch ( V_41 ) {
case 0 :
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
case 128 :
case 256 :
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_18 ( V_2 -> V_24 , L_15 ,
V_41 ) ;
V_41 = 0 ;
break;
}
V_41 = V_41 << 20 ;
switch ( V_113 ) {
case 4 :
case 8 :
case 16 :
F_18 ( V_2 -> V_24 , L_16 ,
V_113 ) ;
V_113 = 512 ;
break;
case 32 :
case 64 :
case 128 :
case 256 :
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_18 ( V_2 -> V_24 , L_17 ,
V_113 ) ;
V_113 = 512 ;
break;
}
V_2 -> V_32 . V_45 = V_113 * 1024 * 1024 ;
switch ( V_114 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_18 ( V_2 -> V_24 , L_18
L_19 , V_114 ) ;
V_114 = 0 ;
break;
}
}
static void F_69 ( struct V_115 * V_47 , enum V_116 V_108 )
{
struct V_117 * V_24 = F_70 ( V_47 ) ;
T_5 V_118 = { . V_119 = V_120 } ;
if ( V_108 == V_121 ) {
F_71 ( V_122 L_20 ) ;
V_24 -> V_123 = V_124 ;
F_72 ( V_24 ) ;
V_24 -> V_123 = V_125 ;
F_73 ( V_24 ) ;
} else {
F_71 ( V_122 L_21 ) ;
F_74 ( V_24 ) ;
V_24 -> V_123 = V_124 ;
F_75 ( V_24 , V_118 ) ;
V_24 -> V_123 = V_126 ;
}
}
static bool F_76 ( struct V_115 * V_47 )
{
struct V_117 * V_24 = F_70 ( V_47 ) ;
bool V_127 ;
F_77 ( & V_24 -> V_128 ) ;
V_127 = ( V_24 -> V_129 == 0 ) ;
F_78 ( & V_24 -> V_128 ) ;
return V_127 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_117 * V_79 ,
struct V_115 * V_47 ,
T_1 V_28 )
{
int V_17 , V_5 ;
int V_130 ;
V_2 -> V_131 = false ;
V_2 -> V_24 = & V_47 -> V_24 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_3 = V_28 & V_132 ;
V_2 -> V_76 = false ;
V_2 -> V_133 = V_134 ;
V_2 -> V_32 . V_45 = V_113 * 1024 * 1024 ;
V_2 -> V_135 = false ;
for ( V_5 = 0 ; V_5 < V_136 ; V_5 ++ ) {
V_2 -> V_137 [ V_5 ] . V_138 = V_5 ;
}
F_33 ( L_22 ,
V_139 [ V_2 -> V_3 ] , V_47 -> V_140 , V_47 -> V_141 ,
V_47 -> V_48 , V_47 -> V_142 ) ;
F_58 ( & V_2 -> V_143 ) ;
F_58 ( & V_2 -> V_144 ) ;
F_80 ( & V_2 -> V_145 . V_146 , 0 ) ;
F_58 ( & V_2 -> V_147 . V_106 ) ;
F_58 ( & V_2 -> V_68 . V_106 ) ;
F_58 ( & V_2 -> V_148 ) ;
F_81 ( & V_2 -> V_68 . V_149 ) ;
F_81 ( & V_2 -> V_150 ) ;
F_82 ( & V_2 -> V_151 . V_152 ) ;
F_82 ( & V_2 -> V_151 . V_153 ) ;
V_17 = F_83 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_58 ( & V_2 -> V_154 . V_146 ) ;
V_2 -> V_154 . V_155 = 1 ;
V_2 -> V_154 . V_156 = 1 << 20 ;
F_84 ( & V_2 -> V_154 . V_157 ) ;
V_17 = F_85 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_68 ( V_2 ) ;
if ( ( V_2 -> V_3 >= V_158 ) &&
( V_2 -> V_28 & V_73 ) ) {
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_28 & V_29 && V_114 == - 1 ) {
F_86 ( V_2 ) ;
}
V_2 -> V_159 = false ;
if ( V_2 -> V_28 & V_29 )
V_2 -> V_159 = true ;
if ( ( V_2 -> V_28 & V_160 ) &&
( V_2 -> V_3 <= V_161 ) )
V_2 -> V_159 = true ;
V_130 = V_2 -> V_159 ? 32 : 40 ;
V_17 = F_87 ( V_2 -> V_47 , F_88 ( V_130 ) ) ;
if ( V_17 ) {
V_2 -> V_159 = true ;
V_130 = 32 ;
F_71 ( V_162 L_23 ) ;
}
V_17 = F_89 ( V_2 -> V_47 , F_88 ( V_130 ) ) ;
if ( V_17 ) {
F_89 ( V_2 -> V_47 , F_88 ( 32 ) ) ;
F_71 ( V_162 L_24 ) ;
}
V_2 -> V_163 = F_90 ( V_2 -> V_47 , 2 ) ;
V_2 -> V_164 = F_91 ( V_2 -> V_47 , 2 ) ;
V_2 -> V_165 = F_92 ( V_2 -> V_163 , V_2 -> V_164 ) ;
if ( V_2 -> V_165 == NULL ) {
return - V_85 ;
}
F_33 ( L_25 , ( T_1 ) V_2 -> V_163 ) ;
F_33 ( L_26 , ( unsigned ) V_2 -> V_164 ) ;
for ( V_5 = 0 ; V_5 < V_166 ; V_5 ++ ) {
if ( F_93 ( V_2 -> V_47 , V_5 ) & V_167 ) {
V_2 -> V_168 = F_91 ( V_2 -> V_47 , V_5 ) ;
V_2 -> V_99 = F_94 ( V_2 -> V_47 , V_5 , V_2 -> V_168 ) ;
break;
}
}
if ( V_2 -> V_99 == NULL )
F_56 ( L_27 ) ;
F_95 ( V_2 -> V_47 , V_2 , NULL , F_66 ) ;
F_96 ( V_2 -> V_47 , & V_169 ) ;
V_17 = F_97 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
F_56 ( L_28 , V_17 ) ;
if ( V_2 -> V_28 & V_29 && ! V_2 -> V_135 ) {
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
F_86 ( V_2 ) ;
V_17 = F_97 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( ( V_170 & 1 ) ) {
F_101 ( V_2 ) ;
}
if ( ( V_170 & 2 ) ) {
F_102 ( V_2 ) ;
}
if ( V_171 ) {
F_103 ( V_2 , V_171 ) ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_33 ( L_29 ) ;
V_2 -> V_131 = true ;
F_105 ( V_2 ) ;
F_100 ( V_2 ) ;
F_106 ( V_2 -> V_47 ) ;
F_95 ( V_2 -> V_47 , NULL , NULL , NULL ) ;
if ( V_2 -> V_99 )
F_107 ( V_2 -> V_47 , V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
F_108 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
F_109 ( V_2 ) ;
}
int F_75 ( struct V_117 * V_24 , T_5 V_108 )
{
struct V_1 * V_2 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_5 , V_17 ;
if ( V_24 == NULL || V_24 -> V_90 == NULL ) {
return - V_176 ;
}
if ( V_108 . V_119 == V_177 ) {
return 0 ;
}
V_2 = V_24 -> V_90 ;
if ( V_24 -> V_123 == V_126 )
return 0 ;
F_74 ( V_24 ) ;
F_110 (connector, &dev->mode_config.connector_list, head) {
F_111 ( V_175 , V_178 ) ;
}
F_110 (crtc, &dev->mode_config.crtc_list, head) {
struct V_179 * V_180 = F_112 ( V_173 -> V_181 ) ;
struct V_182 * V_183 ;
if ( V_180 == NULL || V_180 -> V_184 == NULL ) {
continue;
}
V_183 = F_113 ( V_180 -> V_184 ) ;
if ( ! F_114 ( V_2 , V_183 ) ) {
V_17 = F_9 ( V_183 , false ) ;
if ( V_17 == 0 ) {
F_12 ( V_183 ) ;
F_13 ( V_183 ) ;
}
}
}
F_105 ( V_2 ) ;
F_115 ( & V_2 -> V_143 ) ;
for ( V_5 = 0 ; V_5 < V_136 ; V_5 ++ )
F_116 ( V_2 , V_5 ) ;
F_117 ( & V_2 -> V_143 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_105 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_24 -> V_47 ) ;
if ( V_108 . V_119 == V_120 ) {
F_124 ( V_24 -> V_47 ) ;
F_125 ( V_24 -> V_47 , V_185 ) ;
}
F_126 () ;
F_127 ( V_2 , 1 ) ;
F_128 () ;
return 0 ;
}
int F_72 ( struct V_117 * V_24 )
{
struct V_174 * V_175 ;
struct V_1 * V_2 = V_24 -> V_90 ;
int V_17 ;
if ( V_24 -> V_123 == V_126 )
return 0 ;
F_126 () ;
F_125 ( V_24 -> V_47 , V_186 ) ;
F_129 ( V_24 -> V_47 ) ;
if ( F_130 ( V_24 -> V_47 ) ) {
F_128 () ;
return - 1 ;
}
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
F_56 ( L_28 , V_17 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_127 ( V_2 , 0 ) ;
F_128 () ;
if ( V_2 -> V_76 ) {
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
}
F_137 ( V_2 ) ;
F_138 ( V_24 ) ;
F_110 (connector, &dev->mode_config.connector_list, head) {
F_111 ( V_175 , V_187 ) ;
}
F_73 ( V_24 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 )
{
unsigned V_188 [ V_136 ] ;
T_1 * V_189 [ V_136 ] ;
bool V_190 = false ;
int V_5 , V_17 ;
int V_191 ;
F_140 ( & V_2 -> V_150 ) ;
F_118 ( V_2 ) ;
V_191 = F_141 ( & V_2 -> V_192 . V_193 ) ;
F_120 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_136 ; ++ V_5 ) {
V_188 [ V_5 ] = F_142 ( V_2 , & V_2 -> V_137 [ V_5 ] ,
& V_189 [ V_5 ] ) ;
if ( V_188 [ V_5 ] ) {
V_190 = true ;
F_21 ( V_2 -> V_24 , L_30
L_31 , V_188 [ V_5 ] , V_5 ) ;
}
}
V_194:
V_17 = F_99 ( V_2 ) ;
if ( ! V_17 ) {
F_21 ( V_2 -> V_24 , L_32 ) ;
F_132 ( V_2 ) ;
}
F_134 ( V_2 ) ;
F_138 ( V_2 -> V_79 ) ;
if ( ! V_17 ) {
for ( V_5 = 0 ; V_5 < V_136 ; ++ V_5 ) {
F_143 ( V_2 , & V_2 -> V_137 [ V_5 ] ,
V_188 [ V_5 ] , V_189 [ V_5 ] ) ;
V_188 [ V_5 ] = 0 ;
V_189 [ V_5 ] = NULL ;
}
V_17 = F_98 ( V_2 ) ;
if ( V_17 ) {
F_36 ( V_2 -> V_24 , L_28 , V_17 ) ;
if ( V_190 ) {
V_190 = false ;
F_120 ( V_2 ) ;
goto V_194;
}
}
} else {
for ( V_5 = 0 ; V_5 < V_136 ; ++ V_5 ) {
F_62 ( V_189 [ V_5 ] ) ;
}
}
F_144 ( & V_2 -> V_192 . V_193 , V_191 ) ;
if ( V_17 ) {
F_21 ( V_2 -> V_24 , L_33 ) ;
}
F_145 ( & V_2 -> V_150 ) ;
return V_17 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_195 * V_196 ,
unsigned V_197 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_198 ; V_5 ++ ) {
if ( V_2 -> V_199 [ V_5 ] . V_196 == V_196 ) {
return 0 ;
}
}
V_5 = V_2 -> V_198 + 1 ;
if ( V_5 > V_200 ) {
F_56 ( L_34 ) ;
F_56 ( L_35
L_36 ) ;
return - V_16 ;
}
V_2 -> V_199 [ V_2 -> V_198 ] . V_196 = V_196 ;
V_2 -> V_199 [ V_2 -> V_198 ] . V_201 = V_197 ;
V_2 -> V_198 = V_5 ;
#if F_147 ( V_202 )
F_148 ( V_196 , V_197 ,
V_2 -> V_79 -> V_203 -> V_204 ,
V_2 -> V_79 -> V_203 ) ;
F_148 ( V_196 , V_197 ,
V_2 -> V_79 -> V_205 -> V_204 ,
V_2 -> V_79 -> V_205 ) ;
#endif
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
#if F_147 ( V_202 )
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_198 ; V_5 ++ ) {
F_149 ( V_2 -> V_199 [ V_5 ] . V_196 ,
V_2 -> V_199 [ V_5 ] . V_201 ,
V_2 -> V_79 -> V_203 ) ;
F_149 ( V_2 -> V_199 [ V_5 ] . V_196 ,
V_2 -> V_199 [ V_5 ] . V_201 ,
V_2 -> V_79 -> V_205 ) ;
}
#endif
}
int F_150 ( struct V_206 * V_207 )
{
return 0 ;
}
void F_151 ( struct V_206 * V_207 )
{
}
