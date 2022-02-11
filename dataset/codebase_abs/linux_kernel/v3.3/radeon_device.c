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
V_23 , & V_2 -> V_18 . V_19 ) ;
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
if ( V_27 == 1 )
V_2 -> V_18 . V_20 = false ;
else {
if ( V_2 -> V_28 & V_29 ) {
V_2 -> V_18 . V_20 = false ;
} else if ( V_2 -> V_3 < V_10 ) {
V_2 -> V_18 . V_20 = false ;
} else {
V_2 -> V_18 . V_20 = true ;
if ( V_2 -> V_3 >= V_4 )
V_2 -> V_18 . V_26 = true ;
}
}
if ( F_21 ( V_2 ) ) {
V_2 -> V_18 . V_20 = true ;
V_2 -> V_18 . V_26 = true ;
}
F_22 ( V_2 -> V_24 , L_4 , V_2 -> V_18 . V_20 ? L_5 : L_6 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 , struct V_30 * V_31 , T_2 V_32 )
{
V_31 -> V_33 = V_32 ;
if ( V_31 -> V_34 > ( 0xFFFFFFFF - V_32 + 1 ) ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_31 -> V_35 = V_31 -> V_36 ;
V_31 -> V_34 = V_31 -> V_36 ;
}
V_31 -> V_37 = V_31 -> V_33 + V_31 -> V_34 - 1 ;
if ( V_2 -> V_28 & V_29 && V_31 -> V_37 > V_31 -> V_38 && V_31 -> V_33 <= V_31 -> V_39 ) {
F_18 ( V_2 -> V_24 , L_7 ) ;
V_31 -> V_35 = V_31 -> V_36 ;
V_31 -> V_34 = V_31 -> V_36 ;
}
V_31 -> V_37 = V_31 -> V_33 + V_31 -> V_34 - 1 ;
if ( V_40 && V_40 < V_31 -> V_35 )
V_31 -> V_35 = V_40 ;
F_22 ( V_2 -> V_24 , L_8 ,
V_31 -> V_34 >> 20 , V_31 -> V_33 ,
V_31 -> V_37 , V_31 -> V_35 >> 20 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
T_2 V_41 , V_42 ;
V_41 = ( ( 0xFFFFFFFF - V_31 -> V_37 ) + V_31 -> V_43 ) & ~ V_31 -> V_43 ;
V_42 = V_31 -> V_33 & ~ V_31 -> V_43 ;
if ( V_42 > V_41 ) {
if ( V_31 -> V_44 > V_42 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_31 -> V_44 = V_42 ;
}
V_31 -> V_38 = ( V_31 -> V_33 & ~ V_31 -> V_43 ) - V_31 -> V_44 ;
} else {
if ( V_31 -> V_44 > V_41 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_31 -> V_44 = V_41 ;
}
V_31 -> V_38 = ( V_31 -> V_37 + 1 + V_31 -> V_43 ) & ~ V_31 -> V_43 ;
}
V_31 -> V_39 = V_31 -> V_38 + V_31 -> V_44 - 1 ;
F_22 ( V_2 -> V_24 , L_10 ,
V_31 -> V_44 >> 20 , V_31 -> V_38 , V_31 -> V_39 ) ;
}
bool F_25 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( V_45 && V_2 -> V_46 -> V_47 == V_48 )
return false ;
if ( F_26 ( V_2 ) ) {
V_15 = F_27 ( V_49 + V_50 ) |
F_27 ( V_49 + V_51 ) ;
if ( V_15 & V_52 )
return true ;
} else if ( F_28 ( V_2 ) ) {
V_15 = F_27 ( V_49 + V_50 ) |
F_27 ( V_49 + V_51 ) |
F_27 ( V_49 + V_53 ) |
F_27 ( V_49 + V_54 ) |
F_27 ( V_49 + V_55 ) |
F_27 ( V_49 + V_56 ) ;
if ( V_15 & V_52 )
return true ;
} else if ( F_29 ( V_2 ) ) {
V_15 = F_27 ( V_57 ) |
F_27 ( V_58 ) ;
if ( V_15 & V_59 ) {
return true ;
}
} else {
V_15 = F_27 ( V_60 ) |
F_27 ( V_61 ) ;
if ( V_15 & V_62 ) {
return true ;
}
}
if ( V_2 -> V_3 >= V_4 )
V_15 = F_27 ( V_63 ) ;
else
V_15 = F_27 ( V_64 ) ;
if ( V_15 )
return true ;
return false ;
}
void F_30 ( struct V_1 * V_2 )
{
T_3 V_65 ;
T_4 V_66 = V_2 -> V_67 . V_68 ;
T_4 V_69 = V_2 -> V_67 . V_70 ;
V_65 . V_71 = F_31 ( 100 ) ;
V_2 -> V_67 . V_66 . V_71 = F_31 ( V_66 ) ;
V_2 -> V_67 . V_66 . V_71 = F_32 ( V_2 -> V_67 . V_66 , V_65 ) ;
V_2 -> V_67 . V_69 . V_71 = F_31 ( V_69 ) ;
V_2 -> V_67 . V_69 . V_71 = F_32 ( V_2 -> V_67 . V_69 , V_65 ) ;
if ( V_2 -> V_28 & V_72 ) {
V_65 . V_71 = F_31 ( 16 ) ;
V_2 -> V_67 . V_73 . V_71 = F_32 ( V_2 -> V_67 . V_66 , V_65 ) ;
}
}
bool F_33 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return true ;
if ( V_2 -> V_74 ) {
F_34 ( L_11 ) ;
if ( V_2 -> V_75 )
F_35 ( V_2 -> V_76 . V_77 ) ;
else
F_36 ( V_2 -> V_78 ) ;
return true ;
} else {
F_37 ( V_2 -> V_24 , L_12 ) ;
return false ;
}
}
int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 . V_80 )
return 0 ;
V_2 -> V_79 . V_80 = F_39 ( V_81 | V_82 | V_83 ) ;
if ( V_2 -> V_79 . V_80 == NULL )
return - V_84 ;
V_2 -> V_79 . V_85 = F_40 ( V_2 -> V_46 , V_2 -> V_79 . V_80 ,
0 , V_22 , V_86 ) ;
if ( F_41 ( V_2 -> V_46 , V_2 -> V_79 . V_85 ) ) {
F_37 ( & V_2 -> V_46 -> V_24 , L_13 ) ;
F_42 ( V_2 -> V_79 . V_80 ) ;
V_2 -> V_79 . V_80 = NULL ;
return - V_84 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 . V_80 == NULL )
return;
F_44 ( V_2 -> V_46 , V_2 -> V_79 . V_85 ,
V_22 , V_86 ) ;
F_42 ( V_2 -> V_79 . V_80 ) ;
V_2 -> V_79 . V_80 = NULL ;
}
static T_1 F_45 ( struct V_87 * V_88 , T_1 V_15 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
T_1 V_17 ;
V_17 = V_2 -> V_90 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_46 ( struct V_87 * V_88 , T_1 V_15 , T_1 V_91 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
V_2 -> V_92 ( V_2 , V_15 , V_91 ) ;
}
static T_1 F_47 ( struct V_87 * V_88 , T_1 V_15 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
T_1 V_17 ;
V_17 = V_2 -> V_93 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_48 ( struct V_87 * V_88 , T_1 V_15 , T_1 V_91 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
V_2 -> V_94 ( V_2 , V_15 , V_91 ) ;
}
static void F_49 ( struct V_87 * V_88 , T_1 V_15 , T_1 V_91 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
F_4 ( V_15 * 4 , V_91 ) ;
}
static T_1 F_50 ( struct V_87 * V_88 , T_1 V_15 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
T_1 V_17 ;
V_17 = F_27 ( V_15 * 4 ) ;
return V_17 ;
}
static void F_51 ( struct V_87 * V_88 , T_1 V_15 , T_1 V_91 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
F_52 ( V_15 * 4 , V_91 ) ;
}
static T_1 F_53 ( struct V_87 * V_88 , T_1 V_15 )
{
struct V_1 * V_2 = V_88 -> V_24 -> V_89 ;
T_1 V_17 ;
V_17 = F_54 ( V_15 * 4 ) ;
return V_17 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_87 * V_95 =
F_56 ( sizeof( struct V_87 ) , V_82 ) ;
if ( ! V_95 )
return - V_84 ;
V_2 -> V_76 . V_95 = V_95 ;
V_95 -> V_24 = V_2 -> V_78 ;
V_95 -> V_96 = F_50 ;
V_95 -> V_97 = F_49 ;
if ( V_2 -> V_98 ) {
V_95 -> V_99 = F_53 ;
V_95 -> V_100 = F_51 ;
} else {
F_57 ( L_14 ) ;
V_95 -> V_99 = F_50 ;
V_95 -> V_100 = F_49 ;
}
V_95 -> V_101 = F_47 ;
V_95 -> V_102 = F_48 ;
V_95 -> V_103 = F_45 ;
V_95 -> V_104 = F_46 ;
V_2 -> V_76 . V_77 = F_58 ( V_95 , V_2 -> V_74 ) ;
F_59 ( & V_2 -> V_76 . V_77 -> V_105 ) ;
F_60 ( V_2 -> V_78 ) ;
F_61 ( V_2 -> V_76 . V_77 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_76 . V_77 ) {
F_63 ( V_2 -> V_76 . V_77 -> V_11 ) ;
F_63 ( V_2 -> V_76 . V_77 ) ;
}
F_63 ( V_2 -> V_76 . V_95 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_78 ) ;
return 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
}
static unsigned int F_67 ( void * V_106 , bool V_107 )
{
struct V_1 * V_2 = V_106 ;
F_68 ( V_2 , V_107 ) ;
if ( V_107 )
return V_108 | V_109 |
V_110 | V_111 ;
else
return V_110 | V_111 ;
}
void F_69 ( struct V_1 * V_2 )
{
switch ( V_40 ) {
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
V_40 ) ;
V_40 = 0 ;
break;
}
V_40 = V_40 << 20 ;
switch ( V_112 ) {
case 4 :
case 8 :
case 16 :
F_18 ( V_2 -> V_24 , L_16 ,
V_112 ) ;
V_112 = 512 ;
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
V_112 ) ;
V_112 = 512 ;
break;
}
V_2 -> V_31 . V_44 = V_112 * 1024 * 1024 ;
switch ( V_113 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_18 ( V_2 -> V_24 , L_18
L_19 , V_113 ) ;
V_113 = 0 ;
break;
}
}
static void F_70 ( struct V_114 * V_46 , enum V_115 V_107 )
{
struct V_116 * V_24 = F_71 ( V_46 ) ;
T_5 V_117 = { . V_118 = V_119 } ;
if ( V_107 == V_120 ) {
F_72 ( V_121 L_20 ) ;
V_24 -> V_122 = V_123 ;
F_73 ( V_24 ) ;
V_24 -> V_122 = V_124 ;
F_74 ( V_24 ) ;
} else {
F_72 ( V_121 L_21 ) ;
F_75 ( V_24 ) ;
V_24 -> V_122 = V_123 ;
F_76 ( V_24 , V_117 ) ;
V_24 -> V_122 = V_125 ;
}
}
static bool F_77 ( struct V_114 * V_46 )
{
struct V_116 * V_24 = F_71 ( V_46 ) ;
bool V_126 ;
F_78 ( & V_24 -> V_127 ) ;
V_126 = ( V_24 -> V_128 == 0 ) ;
F_79 ( & V_24 -> V_127 ) ;
return V_126 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_116 * V_78 ,
struct V_114 * V_46 ,
T_1 V_28 )
{
int V_17 , V_5 ;
int V_129 ;
V_2 -> V_130 = false ;
V_2 -> V_24 = & V_46 -> V_24 ;
V_2 -> V_78 = V_78 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_3 = V_28 & V_131 ;
V_2 -> V_75 = false ;
V_2 -> V_132 = V_133 ;
V_2 -> V_31 . V_44 = V_112 * 1024 * 1024 ;
V_2 -> V_134 = false ;
V_2 -> V_135 = false ;
F_34 ( L_22 ,
V_136 [ V_2 -> V_3 ] , V_46 -> V_137 , V_46 -> V_138 ,
V_46 -> V_47 , V_46 -> V_139 ) ;
F_81 ( & V_2 -> V_140 ) ;
F_81 ( & V_2 -> V_141 . V_105 ) ;
for ( V_5 = 0 ; V_5 < V_142 ; ++ V_5 )
F_59 ( & V_2 -> V_143 [ V_5 ] . V_105 ) ;
F_59 ( & V_2 -> V_144 ) ;
if ( V_2 -> V_3 >= V_4 )
F_82 ( & V_2 -> V_145 . V_146 ) ;
F_59 ( & V_2 -> V_147 . V_105 ) ;
F_59 ( & V_2 -> V_67 . V_105 ) ;
F_59 ( & V_2 -> V_148 ) ;
F_83 ( & V_2 -> V_149 ) ;
F_83 ( & V_2 -> V_150 . V_146 ) ;
F_84 ( & V_2 -> V_147 . V_151 ) ;
F_85 ( & V_2 -> V_152 . V_153 ) ;
F_85 ( & V_2 -> V_152 . V_154 ) ;
F_84 ( & V_2 -> V_150 . V_8 ) ;
V_2 -> V_155 . V_156 = 1 ;
V_2 -> V_155 . V_157 = 1 << 20 ;
F_84 ( & V_2 -> V_155 . V_158 ) ;
V_17 = F_86 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_69 ( V_2 ) ;
if ( ( V_2 -> V_3 >= V_159 ) &&
( V_2 -> V_28 & V_72 ) ) {
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_28 & V_29 && V_113 == - 1 ) {
F_87 ( V_2 ) ;
}
V_2 -> V_160 = false ;
if ( V_2 -> V_28 & V_29 )
V_2 -> V_160 = true ;
if ( ( V_2 -> V_28 & V_161 ) &&
( V_2 -> V_3 < V_159 ) )
V_2 -> V_160 = true ;
V_129 = V_2 -> V_160 ? 32 : 40 ;
V_17 = F_88 ( V_2 -> V_46 , F_89 ( V_129 ) ) ;
if ( V_17 ) {
V_2 -> V_160 = true ;
V_129 = 32 ;
F_72 ( V_162 L_23 ) ;
}
V_17 = F_90 ( V_2 -> V_46 , F_89 ( V_129 ) ) ;
if ( V_17 ) {
F_90 ( V_2 -> V_46 , F_89 ( 32 ) ) ;
F_72 ( V_162 L_24 ) ;
}
V_2 -> V_163 = F_91 ( V_2 -> V_46 , 2 ) ;
V_2 -> V_164 = F_92 ( V_2 -> V_46 , 2 ) ;
V_2 -> V_165 = F_93 ( V_2 -> V_163 , V_2 -> V_164 ) ;
if ( V_2 -> V_165 == NULL ) {
return - V_84 ;
}
F_34 ( L_25 , ( T_1 ) V_2 -> V_163 ) ;
F_34 ( L_26 , ( unsigned ) V_2 -> V_164 ) ;
for ( V_5 = 0 ; V_5 < V_166 ; V_5 ++ ) {
if ( F_94 ( V_2 -> V_46 , V_5 ) & V_167 ) {
V_2 -> V_168 = F_92 ( V_2 -> V_46 , V_5 ) ;
V_2 -> V_98 = F_95 ( V_2 -> V_46 , V_5 , V_2 -> V_168 ) ;
break;
}
}
if ( V_2 -> V_98 == NULL )
F_57 ( L_27 ) ;
F_96 ( V_2 -> V_46 , V_2 , NULL , F_67 ) ;
F_97 ( V_2 -> V_46 ,
F_70 ,
NULL ,
F_77 ) ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
return V_17 ;
if ( V_2 -> V_28 & V_29 && ! V_2 -> V_135 ) {
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
F_87 ( V_2 ) ;
V_17 = F_98 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( ( V_169 & 1 ) ) {
F_101 ( V_2 ) ;
}
if ( ( V_169 & 2 ) ) {
F_102 ( V_2 ) ;
}
if ( V_170 ) {
F_103 ( V_2 , V_170 ) ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_34 ( L_28 ) ;
V_2 -> V_130 = true ;
F_105 ( V_2 ) ;
F_100 ( V_2 ) ;
F_106 ( V_2 -> V_46 ) ;
F_96 ( V_2 -> V_46 , NULL , NULL , NULL ) ;
if ( V_2 -> V_98 )
F_107 ( V_2 -> V_46 , V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
F_108 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
F_109 ( V_2 ) ;
}
int F_76 ( struct V_116 * V_24 , T_5 V_107 )
{
struct V_1 * V_2 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
int V_5 , V_17 ;
if ( V_24 == NULL || V_24 -> V_89 == NULL ) {
return - V_175 ;
}
if ( V_107 . V_118 == V_176 ) {
return 0 ;
}
V_2 = V_24 -> V_89 ;
if ( V_24 -> V_122 == V_125 )
return 0 ;
F_75 ( V_24 ) ;
F_110 (connector, &dev->mode_config.connector_list, head) {
F_111 ( V_174 , V_177 ) ;
}
F_110 (crtc, &dev->mode_config.crtc_list, head) {
struct V_178 * V_179 = F_112 ( V_172 -> V_180 ) ;
struct V_181 * V_182 ;
if ( V_179 == NULL || V_179 -> V_183 == NULL ) {
continue;
}
V_182 = F_113 ( V_179 -> V_183 ) ;
if ( ! F_114 ( V_2 , V_182 ) ) {
V_17 = F_9 ( V_182 , false ) ;
if ( V_17 == 0 ) {
F_12 ( V_182 ) ;
F_13 ( V_182 ) ;
}
}
}
F_105 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_142 ; V_5 ++ )
F_115 ( V_2 , V_5 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_105 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_24 -> V_46 ) ;
if ( V_107 . V_118 == V_119 ) {
F_122 ( V_24 -> V_46 ) ;
F_123 ( V_24 -> V_46 , V_184 ) ;
}
F_124 () ;
F_125 ( V_2 , 1 ) ;
F_126 () ;
return 0 ;
}
int F_73 ( struct V_116 * V_24 )
{
struct V_173 * V_174 ;
struct V_1 * V_2 = V_24 -> V_89 ;
if ( V_24 -> V_122 == V_125 )
return 0 ;
F_124 () ;
F_123 ( V_24 -> V_46 , V_185 ) ;
F_127 ( V_24 -> V_46 ) ;
if ( F_128 ( V_24 -> V_46 ) ) {
F_126 () ;
return - 1 ;
}
F_129 ( V_24 -> V_46 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_125 ( V_2 , 0 ) ;
F_126 () ;
if ( V_2 -> V_75 ) {
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
}
F_136 ( V_2 ) ;
F_137 ( V_24 ) ;
F_110 (connector, &dev->mode_config.connector_list, head) {
F_111 ( V_174 , V_186 ) ;
}
F_74 ( V_24 ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 )
{
int V_17 ;
int V_187 ;
F_139 ( & V_2 -> V_140 ) ;
F_116 ( V_2 ) ;
V_187 = F_140 ( & V_2 -> V_188 . V_189 ) ;
F_118 ( V_2 ) ;
V_17 = F_99 ( V_2 ) ;
if ( ! V_17 ) {
F_22 ( V_2 -> V_24 , L_29 ) ;
F_131 ( V_2 ) ;
F_133 ( V_2 ) ;
F_137 ( V_2 -> V_78 ) ;
F_141 ( & V_2 -> V_188 . V_189 , V_187 ) ;
}
F_142 ( & V_2 -> V_140 ) ;
if ( V_17 ) {
F_22 ( V_2 -> V_24 , L_30 ) ;
}
return V_17 ;
}
int F_143 ( struct V_1 * V_2 ,
struct V_190 * V_191 ,
unsigned V_192 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_193 ; V_5 ++ ) {
if ( V_2 -> V_194 [ V_5 ] . V_191 == V_191 ) {
return 0 ;
}
}
V_5 = V_2 -> V_193 + 1 ;
if ( V_5 > V_195 ) {
F_57 ( L_31 ) ;
F_57 ( L_32
L_33 ) ;
return - V_16 ;
}
V_2 -> V_194 [ V_2 -> V_193 ] . V_191 = V_191 ;
V_2 -> V_194 [ V_2 -> V_193 ] . V_196 = V_192 ;
V_2 -> V_193 = V_5 ;
#if F_144 ( V_197 )
F_145 ( V_191 , V_192 ,
V_2 -> V_78 -> V_198 -> V_199 ,
V_2 -> V_78 -> V_198 ) ;
F_145 ( V_191 , V_192 ,
V_2 -> V_78 -> V_200 -> V_199 ,
V_2 -> V_78 -> V_200 ) ;
#endif
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
#if F_144 ( V_197 )
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_193 ; V_5 ++ ) {
F_146 ( V_2 -> V_194 [ V_5 ] . V_191 ,
V_2 -> V_194 [ V_5 ] . V_196 ,
V_2 -> V_78 -> V_198 ) ;
F_146 ( V_2 -> V_194 [ V_5 ] . V_191 ,
V_2 -> V_194 [ V_5 ] . V_196 ,
V_2 -> V_78 -> V_200 ) ;
}
#endif
}
int F_147 ( struct V_201 * V_202 )
{
return 0 ;
}
void F_148 ( struct V_201 * V_202 )
{
}
