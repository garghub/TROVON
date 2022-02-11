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
F_22 ( V_2 -> V_24 , L_8 ,
V_31 -> V_34 >> 20 , V_31 -> V_33 ,
V_31 -> V_37 , V_31 -> V_35 >> 20 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
T_2 V_40 , V_41 ;
V_40 = ( ( 0xFFFFFFFF - V_31 -> V_37 ) + V_31 -> V_42 ) & ~ V_31 -> V_42 ;
V_41 = V_31 -> V_33 & ~ V_31 -> V_42 ;
if ( V_41 > V_40 ) {
if ( V_31 -> V_43 > V_41 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_31 -> V_43 = V_41 ;
}
V_31 -> V_38 = ( V_31 -> V_33 & ~ V_31 -> V_42 ) - V_31 -> V_43 ;
} else {
if ( V_31 -> V_43 > V_40 ) {
F_18 ( V_2 -> V_24 , L_9 ) ;
V_31 -> V_43 = V_40 ;
}
V_31 -> V_38 = ( V_31 -> V_37 + 1 + V_31 -> V_42 ) & ~ V_31 -> V_42 ;
}
V_31 -> V_39 = V_31 -> V_38 + V_31 -> V_43 - 1 ;
F_22 ( V_2 -> V_24 , L_10 ,
V_31 -> V_43 >> 20 , V_31 -> V_38 , V_31 -> V_39 ) ;
}
bool F_25 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( F_26 ( V_2 ) ) {
V_15 = F_27 ( V_44 + V_45 ) |
F_27 ( V_44 + V_46 ) ;
if ( V_15 & V_47 )
return true ;
} else if ( F_28 ( V_2 ) ) {
V_15 = F_27 ( V_44 + V_45 ) |
F_27 ( V_44 + V_46 ) |
F_27 ( V_44 + V_48 ) |
F_27 ( V_44 + V_49 ) |
F_27 ( V_44 + V_50 ) |
F_27 ( V_44 + V_51 ) ;
if ( V_15 & V_47 )
return true ;
} else if ( F_29 ( V_2 ) ) {
V_15 = F_27 ( V_52 ) |
F_27 ( V_53 ) ;
if ( V_15 & V_54 ) {
return true ;
}
} else {
V_15 = F_27 ( V_55 ) |
F_27 ( V_56 ) ;
if ( V_15 & V_57 ) {
return true ;
}
}
if ( V_2 -> V_3 >= V_4 )
V_15 = F_27 ( V_58 ) ;
else
V_15 = F_27 ( V_59 ) ;
if ( V_15 )
return true ;
return false ;
}
void F_30 ( struct V_1 * V_2 )
{
T_3 V_60 ;
T_4 V_61 = V_2 -> V_62 . V_63 ;
T_4 V_64 = V_2 -> V_62 . V_65 ;
V_60 . V_66 = F_31 ( 100 ) ;
V_2 -> V_62 . V_61 . V_66 = F_31 ( V_61 ) ;
V_2 -> V_62 . V_61 . V_66 = F_32 ( V_2 -> V_62 . V_61 , V_60 ) ;
V_2 -> V_62 . V_64 . V_66 = F_31 ( V_64 ) ;
V_2 -> V_62 . V_64 . V_66 = F_32 ( V_2 -> V_62 . V_64 , V_60 ) ;
if ( V_2 -> V_28 & V_67 ) {
V_60 . V_66 = F_31 ( 16 ) ;
V_2 -> V_62 . V_68 . V_66 = F_32 ( V_2 -> V_62 . V_61 , V_60 ) ;
}
}
bool F_33 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return true ;
if ( V_2 -> V_69 ) {
F_34 ( L_11 ) ;
if ( V_2 -> V_70 )
F_35 ( V_2 -> V_71 . V_72 ) ;
else
F_36 ( V_2 -> V_73 ) ;
return true ;
} else {
F_37 ( V_2 -> V_24 , L_12 ) ;
return false ;
}
}
int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 . V_75 )
return 0 ;
V_2 -> V_74 . V_75 = F_39 ( V_76 | V_77 | V_78 ) ;
if ( V_2 -> V_74 . V_75 == NULL )
return - V_79 ;
V_2 -> V_74 . V_80 = F_40 ( V_2 -> V_81 , V_2 -> V_74 . V_75 ,
0 , V_22 , V_82 ) ;
if ( F_41 ( V_2 -> V_81 , V_2 -> V_74 . V_80 ) ) {
F_37 ( & V_2 -> V_81 -> V_24 , L_13 ) ;
F_42 ( V_2 -> V_74 . V_75 ) ;
V_2 -> V_74 . V_75 = NULL ;
return - V_79 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 . V_75 == NULL )
return;
F_44 ( V_2 -> V_81 , V_2 -> V_74 . V_80 ,
V_22 , V_82 ) ;
F_42 ( V_2 -> V_74 . V_75 ) ;
V_2 -> V_74 . V_75 = NULL ;
}
static T_1 F_45 ( struct V_83 * V_84 , T_1 V_15 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
T_1 V_17 ;
V_17 = V_2 -> V_86 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_46 ( struct V_83 * V_84 , T_1 V_15 , T_1 V_87 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
V_2 -> V_88 ( V_2 , V_15 , V_87 ) ;
}
static T_1 F_47 ( struct V_83 * V_84 , T_1 V_15 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
T_1 V_17 ;
V_17 = V_2 -> V_89 ( V_2 , V_15 ) ;
return V_17 ;
}
static void F_48 ( struct V_83 * V_84 , T_1 V_15 , T_1 V_87 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
V_2 -> V_90 ( V_2 , V_15 , V_87 ) ;
}
static void F_49 ( struct V_83 * V_84 , T_1 V_15 , T_1 V_87 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
F_4 ( V_15 * 4 , V_87 ) ;
}
static T_1 F_50 ( struct V_83 * V_84 , T_1 V_15 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
T_1 V_17 ;
V_17 = F_27 ( V_15 * 4 ) ;
return V_17 ;
}
static void F_51 ( struct V_83 * V_84 , T_1 V_15 , T_1 V_87 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
F_52 ( V_15 * 4 , V_87 ) ;
}
static T_1 F_53 ( struct V_83 * V_84 , T_1 V_15 )
{
struct V_1 * V_2 = V_84 -> V_24 -> V_85 ;
T_1 V_17 ;
V_17 = F_54 ( V_15 * 4 ) ;
return V_17 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_83 * V_91 =
F_56 ( sizeof( struct V_83 ) , V_77 ) ;
if ( ! V_91 )
return - V_79 ;
V_2 -> V_71 . V_91 = V_91 ;
V_91 -> V_24 = V_2 -> V_73 ;
V_91 -> V_92 = F_50 ;
V_91 -> V_93 = F_49 ;
if ( V_2 -> V_94 ) {
V_91 -> V_95 = F_53 ;
V_91 -> V_96 = F_51 ;
} else {
F_57 ( L_14 ) ;
V_91 -> V_95 = F_50 ;
V_91 -> V_96 = F_49 ;
}
V_91 -> V_97 = F_47 ;
V_91 -> V_98 = F_48 ;
V_91 -> V_99 = F_45 ;
V_91 -> V_100 = F_46 ;
V_2 -> V_71 . V_72 = F_58 ( V_91 , V_2 -> V_69 ) ;
F_59 ( & V_2 -> V_71 . V_72 -> V_101 ) ;
F_60 ( V_2 -> V_73 ) ;
F_61 ( V_2 -> V_71 . V_72 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 . V_72 ) {
F_63 ( V_2 -> V_71 . V_72 -> V_11 ) ;
F_63 ( V_2 -> V_71 . V_72 ) ;
}
F_63 ( V_2 -> V_71 . V_91 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_73 ) ;
return 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
}
static unsigned int F_67 ( void * V_102 , bool V_103 )
{
struct V_1 * V_2 = V_102 ;
F_68 ( V_2 , V_103 ) ;
if ( V_103 )
return V_104 | V_105 |
V_106 | V_107 ;
else
return V_106 | V_107 ;
}
void F_69 ( struct V_1 * V_2 )
{
switch ( V_108 ) {
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
V_108 ) ;
V_108 = 0 ;
break;
}
V_108 = V_108 << 20 ;
switch ( V_109 ) {
case 4 :
case 8 :
case 16 :
F_18 ( V_2 -> V_24 , L_16 ,
V_109 ) ;
V_109 = 512 ;
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
V_109 ) ;
V_109 = 512 ;
break;
}
V_2 -> V_31 . V_43 = V_109 * 1024 * 1024 ;
switch ( V_110 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_18 ( V_2 -> V_24 , L_18
L_19 , V_110 ) ;
V_110 = 0 ;
break;
}
}
static void F_70 ( struct V_111 * V_81 , enum V_112 V_103 )
{
struct V_113 * V_24 = F_71 ( V_81 ) ;
T_5 V_114 = { . V_115 = V_116 } ;
if ( V_103 == V_117 ) {
F_72 ( V_118 L_20 ) ;
V_24 -> V_119 = V_120 ;
F_73 ( V_24 ) ;
V_24 -> V_119 = V_121 ;
F_74 ( V_24 ) ;
} else {
F_72 ( V_118 L_21 ) ;
F_75 ( V_24 ) ;
V_24 -> V_119 = V_120 ;
F_76 ( V_24 , V_114 ) ;
V_24 -> V_119 = V_122 ;
}
}
static bool F_77 ( struct V_111 * V_81 )
{
struct V_113 * V_24 = F_71 ( V_81 ) ;
bool V_123 ;
F_78 ( & V_24 -> V_124 ) ;
V_123 = ( V_24 -> V_125 == 0 ) ;
F_79 ( & V_24 -> V_124 ) ;
return V_123 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_113 * V_73 ,
struct V_111 * V_81 ,
T_1 V_28 )
{
int V_17 , V_5 ;
int V_126 ;
V_2 -> V_127 = false ;
V_2 -> V_24 = & V_81 -> V_24 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_3 = V_28 & V_128 ;
V_2 -> V_70 = false ;
V_2 -> V_129 = V_130 ;
V_2 -> V_31 . V_43 = V_109 * 1024 * 1024 ;
V_2 -> V_131 = false ;
V_2 -> V_132 = false ;
F_34 ( L_22 ,
V_133 [ V_2 -> V_3 ] , V_81 -> V_134 , V_81 -> V_135 ) ;
F_59 ( & V_2 -> V_136 ) ;
F_59 ( & V_2 -> V_137 . V_101 ) ;
F_59 ( & V_2 -> V_138 . V_101 ) ;
F_59 ( & V_2 -> V_139 ) ;
if ( V_2 -> V_3 >= V_4 )
F_81 ( & V_2 -> V_140 . V_141 ) ;
F_59 ( & V_2 -> V_142 . V_101 ) ;
F_59 ( & V_2 -> V_62 . V_101 ) ;
F_59 ( & V_2 -> V_143 ) ;
F_82 ( & V_2 -> V_144 . V_141 ) ;
F_83 ( & V_2 -> V_142 . V_145 ) ;
F_84 ( & V_2 -> V_146 . V_147 ) ;
F_84 ( & V_2 -> V_146 . V_148 ) ;
V_17 = F_85 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_69 ( V_2 ) ;
if ( ( V_2 -> V_3 >= V_149 ) &&
( V_2 -> V_28 & V_67 ) ) {
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_28 & V_29 && V_110 == - 1 ) {
F_86 ( V_2 ) ;
}
V_2 -> V_150 = false ;
if ( V_2 -> V_28 & V_29 )
V_2 -> V_150 = true ;
if ( V_2 -> V_28 & V_151 )
V_2 -> V_150 = true ;
V_126 = V_2 -> V_150 ? 32 : 40 ;
V_17 = F_87 ( V_2 -> V_81 , F_88 ( V_126 ) ) ;
if ( V_17 ) {
V_2 -> V_150 = true ;
F_72 ( V_152 L_23 ) ;
}
V_2 -> V_153 = F_89 ( V_2 -> V_81 , 2 ) ;
V_2 -> V_154 = F_90 ( V_2 -> V_81 , 2 ) ;
V_2 -> V_155 = F_91 ( V_2 -> V_153 , V_2 -> V_154 ) ;
if ( V_2 -> V_155 == NULL ) {
return - V_79 ;
}
F_34 ( L_24 , ( T_1 ) V_2 -> V_153 ) ;
F_34 ( L_25 , ( unsigned ) V_2 -> V_154 ) ;
for ( V_5 = 0 ; V_5 < V_156 ; V_5 ++ ) {
if ( F_92 ( V_2 -> V_81 , V_5 ) & V_157 ) {
V_2 -> V_158 = F_90 ( V_2 -> V_81 , V_5 ) ;
V_2 -> V_94 = F_93 ( V_2 -> V_81 , V_5 , V_2 -> V_158 ) ;
break;
}
}
if ( V_2 -> V_94 == NULL )
F_57 ( L_26 ) ;
F_94 ( V_2 -> V_81 , V_2 , NULL , F_67 ) ;
F_95 ( V_2 -> V_81 ,
F_70 ,
NULL ,
F_77 ) ;
V_17 = F_96 ( V_2 ) ;
if ( V_17 )
return V_17 ;
if ( V_2 -> V_28 & V_29 && ! V_2 -> V_132 ) {
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_86 ( V_2 ) ;
V_17 = F_96 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_159 ) {
F_99 ( V_2 ) ;
}
if ( V_160 ) {
F_100 ( V_2 ) ;
}
return 0 ;
}
void F_101 ( struct V_1 * V_2 )
{
F_34 ( L_27 ) ;
V_2 -> V_127 = true ;
F_102 ( V_2 ) ;
F_98 ( V_2 ) ;
F_103 ( V_2 -> V_81 ) ;
F_94 ( V_2 -> V_81 , NULL , NULL , NULL ) ;
if ( V_2 -> V_94 )
F_104 ( V_2 -> V_81 , V_2 -> V_94 ) ;
V_2 -> V_94 = NULL ;
F_105 ( V_2 -> V_155 ) ;
V_2 -> V_155 = NULL ;
}
int F_76 ( struct V_113 * V_24 , T_5 V_103 )
{
struct V_1 * V_2 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
int V_17 ;
if ( V_24 == NULL || V_24 -> V_85 == NULL ) {
return - V_165 ;
}
if ( V_103 . V_115 == V_166 ) {
return 0 ;
}
V_2 = V_24 -> V_85 ;
if ( V_24 -> V_119 == V_122 )
return 0 ;
F_106 (connector, &dev->mode_config.connector_list, head) {
F_107 ( V_164 , V_167 ) ;
}
F_106 (crtc, &dev->mode_config.crtc_list, head) {
struct V_168 * V_169 = F_108 ( V_162 -> V_170 ) ;
struct V_171 * V_172 ;
if ( V_169 == NULL || V_169 -> V_173 == NULL ) {
continue;
}
V_172 = F_109 ( V_169 -> V_173 ) ;
if ( ! F_110 ( V_2 , V_172 ) ) {
V_17 = F_9 ( V_172 , false ) ;
if ( V_17 == 0 ) {
F_12 ( V_172 ) ;
F_13 ( V_172 ) ;
}
}
}
F_102 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
F_102 ( V_2 ) ;
F_116 ( V_2 ) ;
F_117 ( V_24 -> V_81 ) ;
if ( V_103 . V_115 == V_116 ) {
F_118 ( V_24 -> V_81 ) ;
F_119 ( V_24 -> V_81 , V_174 ) ;
}
F_120 () ;
F_121 ( V_2 , 1 ) ;
F_122 () ;
return 0 ;
}
int F_73 ( struct V_113 * V_24 )
{
struct V_163 * V_164 ;
struct V_1 * V_2 = V_24 -> V_85 ;
if ( V_24 -> V_119 == V_122 )
return 0 ;
F_120 () ;
F_119 ( V_24 -> V_81 , V_175 ) ;
F_123 ( V_24 -> V_81 ) ;
if ( F_124 ( V_24 -> V_81 ) ) {
F_122 () ;
return - 1 ;
}
F_125 ( V_24 -> V_81 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_121 ( V_2 , 0 ) ;
F_122 () ;
if ( V_2 -> V_70 )
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_24 ) ;
F_106 (connector, &dev->mode_config.connector_list, head) {
F_107 ( V_164 , V_176 ) ;
}
return 0 ;
}
int F_133 ( struct V_1 * V_2 )
{
int V_17 ;
int V_177 ;
F_112 ( V_2 ) ;
V_177 = F_134 ( & V_2 -> V_178 . V_179 ) ;
F_114 ( V_2 ) ;
V_17 = F_97 ( V_2 ) ;
if ( ! V_17 ) {
F_22 ( V_2 -> V_24 , L_28 ) ;
F_127 ( V_2 ) ;
F_129 ( V_2 ) ;
F_132 ( V_2 -> V_73 ) ;
F_135 ( & V_2 -> V_178 . V_179 , V_177 ) ;
return 0 ;
}
F_22 ( V_2 -> V_24 , L_29 ) ;
return V_17 ;
}
int F_136 ( struct V_1 * V_2 ,
struct V_180 * V_181 ,
unsigned V_182 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_183 ; V_5 ++ ) {
if ( V_184 [ V_5 ] . V_181 == V_181 ) {
return 0 ;
}
}
if ( ( V_183 + V_182 ) > V_185 ) {
F_57 ( L_30 ) ;
F_57 ( L_31 ) ;
return - V_16 ;
}
V_184 [ V_183 ] . V_181 = V_181 ;
V_184 [ V_183 ] . V_186 = V_182 ;
V_183 ++ ;
#if F_137 ( V_187 )
F_138 ( V_181 , V_182 ,
V_2 -> V_73 -> V_188 -> V_189 ,
V_2 -> V_73 -> V_188 ) ;
F_138 ( V_181 , V_182 ,
V_2 -> V_73 -> V_190 -> V_189 ,
V_2 -> V_73 -> V_190 ) ;
#endif
return 0 ;
}
int F_139 ( struct V_191 * V_192 )
{
return 0 ;
}
void F_140 ( struct V_191 * V_192 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_183 ; V_5 ++ ) {
F_141 ( V_184 [ V_5 ] . V_181 ,
V_184 [ V_5 ] . V_186 , V_192 ) ;
}
}
