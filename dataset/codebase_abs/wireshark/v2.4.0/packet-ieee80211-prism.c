static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_1 , V_2 / 2 , V_2 & 1 ? 5 : 0 ) ;
}
static T_1 *
F_3 ( T_2 V_2 )
{
T_1 * V_1 = NULL ;
V_1 = ( T_1 * ) F_4 ( F_5 () , V_4 ) ;
V_1 [ 0 ] = '\0' ;
F_1 ( V_1 , V_2 ) ;
return V_1 ;
}
static T_1 *
F_6 ( T_2 V_5 , T_2 V_6 , struct V_7 * V_8 )
{
T_1 * V_1 = NULL ;
unsigned int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
T_3 V_19 = FALSE ;
unsigned int V_20 , V_21 , V_22 , V_23 , V_24 ;
unsigned int V_25 , V_26 , V_27 = 1 , V_28 , V_29 ;
unsigned int V_30 [] = { 22 , 11 , 4 , 2 } ;
static const unsigned int V_31 [] = { 0 , 1 , 4 , 11 } ;
V_11 = V_5 & 0xF ;
switch ( V_11 ) {
case 0 :
V_8 -> V_32 = V_33 ;
V_9 = ( V_5 >> 4 ) & 0xF ;
V_10 = ( V_9 & 0x4 ) ? 9 : 6 ;
V_9 &= ~ 0x4 ;
V_9 = V_10 << ( 11 - V_9 ) ;
V_9 = ( V_9 > 54 ) ? 54 : V_9 ;
V_8 -> V_34 = 1 ;
V_8 -> V_35 = V_9 * 2 ;
V_29 = V_5 & ( 1 << 12 ) ;
V_13 = 20 << ( ( V_5 >> 13 ) & 0x3 ) ;
V_1 = F_7 ( F_5 () ,
L_2 ,
V_9 , 0 , V_29 ? L_3 : L_4 , V_13
) ;
break;
case 1 :
V_8 -> V_32 = V_36 ;
V_9 = ( V_5 >> 4 ) & 0xF ;
V_10 = ( V_9 & 0x4 ) ? 1 : 0 ;
V_8 -> V_37 . V_38 . V_39 = 1 ;
V_8 -> V_37 . V_38 . V_40 = V_10 ;
V_9 &= ~ 0x4 ;
V_9 = ( V_9 - 8 ) & 0x3 ;
V_12 = V_30 [ V_9 ] ;
V_8 -> V_34 = 1 ;
V_8 -> V_35 = V_12 ;
V_1 = F_7 ( F_5 () , L_5 ,
V_12 / 2 ,
( V_12 & 1 ) ? 5 : 0 ,
V_10 ? L_6 : L_7 ) ;
break;
case 2 :
V_8 -> V_32 = V_41 ;
V_25 = ( V_5 >> 4 ) & 0xFFFF ;
V_26 = ( V_6 ) & 0xFFF ;
V_9 = V_25 & 0x7f ;
V_8 -> V_37 . V_42 . V_43 = 1 ;
V_8 -> V_37 . V_42 . V_44 = V_9 ;
V_13 = 20 << ( ( V_25 >> 7 ) & 1 ) ;
V_8 -> V_37 . V_42 . V_45 = 1 ;
V_8 -> V_37 . V_42 . V_46 = ( ( V_25 >> 7 ) & 1 ) ;
V_14 = ( V_26 >> 7 ) & 1 ;
V_8 -> V_37 . V_42 . V_47 = 1 ;
V_8 -> V_37 . V_42 . V_48 = V_14 ;
V_15 = ( V_26 >> 6 ) & 1 ;
V_8 -> V_37 . V_42 . V_49 = 1 ;
V_8 -> V_37 . V_42 . V_50 = V_15 ;
V_16 = ( ( V_26 >> 4 ) & 3 ) ? 1 : 0 ;
V_8 -> V_37 . V_42 . V_51 = 1 ;
V_8 -> V_37 . V_42 . V_52 = V_16 ;
V_8 -> V_37 . V_42 . V_53 = 1 ;
V_8 -> V_37 . V_42 . V_54 = ( V_26 >> 8 ) & 3 ;
V_27 = ( V_9 >> 3 ) + 1 ;
V_12 = 0 ;
if ( ( V_27 <= 4 ) && ( V_9 <= 31 ) && ( ( V_13 == 20 ) || ( V_13 == 40 ) ) ) {
switch ( V_13 ) {
case 20 :
if ( V_14 ) {
V_12 = V_55 [ V_9 ] [ 1 ] ;
} else {
V_12 = V_55 [ V_9 ] [ 0 ] ;
}
break;
case 40 :
if ( V_14 ) {
V_12 = V_56 [ V_9 ] [ 1 ] ;
} else {
V_12 = V_56 [ V_9 ] [ 0 ] ;
}
break;
}
}
V_1 = F_7 ( F_5 () ,
L_8 ,
V_12 / 10 , V_12 % 10 , V_9 , V_27 , V_13 ,
V_14 ? L_9 : L_10 ,
V_15 ? L_11 : L_10 ,
V_16 ? L_12 : L_10 ) ;
break;
case 3 :
V_8 -> V_32 = V_57 ;
V_25 = ( V_5 >> 4 ) & 0xFFFFFF ;
V_26 = ( V_6 ) & 0xFFFFFF ;
V_16 = ( V_25 >> 3 ) & 1 ;
V_8 -> V_37 . V_58 . V_59 = 1 ;
V_8 -> V_37 . V_58 . V_16 = V_16 ;
V_14 = V_26 & 1 ;
V_8 -> V_37 . V_58 . V_47 = 1 ;
V_8 -> V_37 . V_58 . V_48 = V_14 ;
V_13 = 20 << ( V_25 & 3 ) ;
V_8 -> V_37 . V_58 . V_45 = 1 ;
V_8 -> V_37 . V_58 . V_46 = V_31 [ ( V_25 & 3 ) ] ;
V_15 = ( V_26 >> 2 ) & 1 ;
V_8 -> V_37 . V_58 . V_49 = 1 ;
V_8 -> V_37 . V_58 . V_50 = V_15 ;
V_17 = ( V_25 >> 4 ) & 0x3F ;
V_8 -> V_37 . V_58 . V_60 = 1 ;
V_8 -> V_37 . V_58 . V_61 = V_17 ;
if ( V_17 == 0 || V_17 == 63 )
V_19 = TRUE ;
V_12 = 0 ;
if ( V_19 ) {
V_28 = ( V_25 >> 10 ) & 0x7 ;
if ( V_16 )
V_27 = V_28 >> 2 ;
else
V_27 = V_28 ;
++ V_27 ;
V_9 = ( V_26 >> 4 ) & 0xF ;
V_8 -> V_37 . V_58 . V_9 [ 0 ] = V_9 ;
V_8 -> V_37 . V_58 . V_27 [ 0 ] = V_27 ;
V_18 = ( V_26 >> 8 ) & 1 ;
V_8 -> V_37 . V_58 . V_62 = 1 ;
V_8 -> V_37 . V_58 . V_63 = V_18 ;
V_20 = ( V_25 >> 13 ) & 0x1FF ;
V_8 -> V_37 . V_58 . V_64 = 1 ;
V_8 -> V_37 . V_58 . V_20 = V_20 ;
if ( ( V_27 <= 4 ) && ( V_9 <= 9 ) && ( ( V_13 == 20 ) || ( V_13 == 40 ) || ( V_13 == 80 ) || V_13 == 160 ) ) {
switch ( V_13 ) {
case 20 :
if ( V_14 ) {
V_12 = V_65 [ V_9 ] [ ( V_27 * 2 ) - 1 ] ;
} else {
V_12 = V_65 [ V_9 ] [ ( V_27 - 1 ) * 2 ] ;
}
break;
case 40 :
if ( V_14 ) {
V_12 = V_66 [ V_9 ] [ ( V_27 * 2 ) - 1 ] ;
} else {
V_12 = V_66 [ V_9 ] [ ( V_27 - 1 ) * 2 ] ;
}
break;
case 80 :
if ( V_14 ) {
V_12 = V_67 [ V_9 ] [ ( V_27 * 2 ) - 1 ] ;
} else {
V_12 = V_67 [ V_9 ] [ ( V_27 - 1 ) * 2 ] ;
}
break;
case 160 :
if ( V_14 ) {
V_12 = V_68 [ V_9 ] [ ( V_27 * 2 ) - 1 ] ;
} else {
V_12 = V_68 [ V_9 ] [ ( V_27 - 1 ) * 2 ] ;
}
break;
}
}
V_1 = F_7 ( F_5 () ,
L_13 ,
V_12 / 10 , V_12 % 10 ,
V_9 , V_27 , V_20 , V_13 ,
V_14 ? L_9 : L_10 ,
V_15 ? L_11 : L_10 ,
V_16 ? L_12 : L_10 ,
V_17 ,
L_14 ,
V_18 ? L_15 : L_10 ) ;
} else {
V_21 = ( V_25 >> 10 ) & 0x7 ;
V_22 = ( V_25 >> 13 ) & 0x7 ;
V_23 = ( V_25 >> 16 ) & 0x7 ;
V_24 = ( V_25 >> 19 ) & 0x7 ;
V_1 = F_7 ( F_5 () ,
L_16 ,
V_21 , V_22 , V_23 , V_24 , V_13 ,
V_14 ? L_9 : L_10 ,
V_15 ? L_11 : L_10 ,
V_16 ? L_12 : L_10 ,
V_17 ,
L_17 ) ;
}
break;
}
return V_1 ;
}
static T_3
F_8 ( const T_4 * V_69 , int V_70 , int V_71 , T_5 * V_72 , const union V_73 * T_6 V_74 )
{
T_2 V_75 ;
if ( ! F_9 ( V_70 , V_71 , 4 ) )
return FALSE ;
V_75 = F_10 ( V_69 ) ;
if ( ( V_75 == V_76 ) ||
( V_75 == V_77 ) ) {
return F_11 ( V_78 , V_69 , V_70 , V_71 , V_72 , T_6 ) ;
}
if ( ! F_9 ( V_70 , V_71 , V_79 ) )
return FALSE ;
V_70 += V_79 ;
return F_11 ( V_80 , V_69 , V_70 , V_71 , V_72 , T_6 ) ;
}
static int
F_12 ( T_7 * V_81 , T_8 * V_82 , T_9 * V_83 , void * T_10 V_74 )
{
T_9 * V_84 , * V_85 = NULL ;
T_11 * V_86 = NULL , * V_87 = NULL ;
T_7 * V_88 ;
int V_70 ;
T_2 V_89 , V_90 , V_91 , V_5 = 0 , V_6 = 0 ;
T_12 V_92 ;
T_13 V_93 ;
const T_14 * V_94 ;
T_2 V_95 ;
T_2 V_96 ;
T_2 V_97 ;
T_2 V_2 ;
struct V_7 V_8 ;
V_70 = 0 ;
V_91 = 0 ;
V_89 = F_13 ( V_81 , V_70 ) ;
if ( ( V_89 == V_76 ) ||
( V_89 == V_77 ) ) {
F_14 ( V_98 , V_81 , V_82 , V_83 ) ;
return F_15 ( V_81 ) ;
}
if ( ( V_89 == V_99 ) || ( V_89 == V_100 ) ) {
V_92 = V_101 ;
} else if ( ( ( V_89 = F_16 ( V_81 , V_70 ) ) == V_99 ) ||
( V_89 == V_100 ) ) {
V_92 = V_102 ;
} else {
F_14 ( V_103 , V_81 , V_82 , V_83 ) ;
return F_15 ( V_81 ) ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_104 = - 1 ;
V_8 . V_105 = FALSE ;
V_8 . V_106 = FALSE ;
V_8 . V_32 = V_107 ;
F_17 ( V_82 -> V_108 , V_109 , L_18 ) ;
F_18 ( V_82 -> V_108 , V_110 ) ;
V_86 = F_19 ( V_83 , V_111 , V_81 , 0 , 144 , V_112 ) ;
V_84 = F_20 ( V_86 , V_113 ) ;
F_21 ( V_84 , V_114 , V_81 , V_70 , 4 , V_92 , & V_89 ) ;
V_70 += 4 ;
F_21 ( V_84 , V_115 , V_81 , V_70 , 4 , V_92 , & V_90 ) ;
V_70 += 4 ;
F_22 ( V_84 , V_116 , V_81 , V_70 , 16 , V_117 | V_112 , F_5 () , & V_94 ) ;
V_70 += 16 ;
F_23 ( V_82 -> V_108 , V_110 , L_19 , V_94 , V_89 , V_90 ) ;
while ( V_70 < V_79 )
{
if ( V_83 ) {
V_87 = F_19 ( V_84 , V_118 , V_81 , V_70 , 12 , V_112 ) ;
V_85 = F_20 ( V_87 , V_119 ) ;
F_19 ( V_85 , V_120 , V_81 , V_70 , 4 , V_92 ) ;
V_91 = F_24 ( V_81 , V_70 , V_92 ) ;
F_25 ( V_87 , L_20 , F_26 ( V_91 , V_121 , L_21 ) ) ;
}
V_70 += 4 ;
V_93 = F_27 ( V_81 , V_70 , V_92 ) ;
F_19 ( V_85 , V_122 , V_81 , V_70 , 2 , V_92 ) ;
V_70 += 2 ;
F_19 ( V_85 , V_123 , V_81 , V_70 , 2 , V_92 ) ;
V_70 += 2 ;
if ( V_93 == 0 ) {
switch ( V_91 ) {
case V_124 :
case V_125 :
if ( V_83 ) {
F_19 ( V_85 , V_126 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_22 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
case V_127 :
case V_128 :
V_95 = F_24 ( V_81 , V_70 , V_92 ) ;
V_8 . V_129 = 1 ;
V_8 . V_130 = V_95 ;
if ( V_83 ) {
F_19 ( V_85 , V_131 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_22 , V_95 ) ;
}
break;
case V_132 :
case V_133 :
V_96 = F_24 ( V_81 , V_70 , V_92 ) ;
V_8 . V_134 = TRUE ;
V_8 . V_96 = V_96 ;
if ( V_83 ) {
F_19 ( V_85 , V_135 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_23 , V_96 ) ;
}
F_23 ( V_82 -> V_108 , V_136 , L_24 , V_96 ) ;
break;
case V_137 :
case V_138 :
V_97 = F_24 ( V_81 , V_70 , V_92 ) ;
V_8 . V_139 = 1 ;
V_8 . V_97 = V_97 ;
if ( V_83 ) {
F_19 ( V_85 , V_140 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_22 , V_97 ) ;
}
F_23 ( V_82 -> V_108 , V_141 , L_25 , V_97 ) ;
break;
case V_142 :
case V_143 :
if ( V_83 ) {
F_19 ( V_85 , V_144 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
case V_145 :
case V_146 :
if ( V_83 ) {
F_19 ( V_85 , V_147 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
case V_148 :
case V_149 :
if ( V_83 ) {
F_19 ( V_85 , V_150 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
case V_151 :
case V_152 :
V_2 = F_24 ( V_81 , V_70 , V_92 ) ;
V_8 . V_34 = TRUE ;
V_8 . V_35 = V_2 ;
if ( V_83 ) {
F_19 ( V_85 , V_153 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_27 , F_3 ( V_2 ) ) ;
}
F_23 ( V_82 -> V_108 , V_154 , L_28 , F_3 ( V_2 ) ) ;
break;
case V_155 :
case V_156 :
V_5 = F_16 ( V_81 , V_70 ) ;
if ( V_83 ) {
F_19 ( V_85 , V_157 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_16 ( V_81 , V_70 ) ) ;
}
break;
case V_158 :
case V_159 :
V_6 = F_16 ( V_81 , V_70 ) ;
if ( V_83 ) {
F_19 ( V_85 , V_160 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_16 ( V_81 , V_70 ) ) ;
}
break;
case V_161 :
case V_162 :
if ( V_83 && V_5 && V_6 ) {
T_11 * V_163 ;
F_19 ( V_85 , V_164 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_16 ( V_81 , V_70 ) ) ;
V_163 = F_19 ( V_84 , V_165 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_163 , L_20 , F_6 ( V_5 , V_6 , & V_8 ) ) ;
}
break;
case V_166 :
case V_167 :
if ( V_83 ) {
F_19 ( V_85 , V_168 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_26 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
case V_169 :
case V_170 :
if ( V_83 ) {
F_19 ( V_85 , V_171 , V_81 , V_70 , 4 , V_92 ) ;
F_25 ( V_87 , L_22 , F_24 ( V_81 , V_70 , V_92 ) ) ;
}
break;
default:
F_19 ( V_85 , V_172 , V_81 , V_70 , 4 , V_92 ) ;
break;
}
}
V_70 += 4 ;
}
V_88 = F_28 ( V_81 , V_70 ) ;
F_29 ( V_173 , V_88 , V_82 , V_83 , ( void * ) & V_8 ) ;
return F_15 ( V_81 ) ;
}
void F_30 ( void )
{
V_111 = F_31 ( L_29 , L_18 ,
L_30 ) ;
F_32 ( V_111 , V_174 , F_33 ( V_174 ) ) ;
F_34 ( V_175 , F_33 ( V_175 ) ) ;
V_176 = F_35 ( L_30 , F_12 , V_111 ) ;
}
void F_36 ( void )
{
T_15 V_177 ;
F_37 ( L_31 , V_178 , V_176 ) ;
V_103 = F_38 ( L_32 , V_111 ) ;
V_173 = F_38 ( L_33 , V_111 ) ;
V_98 = F_38 ( L_34 , V_111 ) ;
V_177 = F_39 ( F_8 , V_111 ) ;
F_40 ( L_31 , V_178 , V_177 ) ;
V_80 = F_41 ( L_35 ) ;
V_78 = F_41 ( L_34 ) ;
}
