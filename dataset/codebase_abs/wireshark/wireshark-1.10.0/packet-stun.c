static T_1
F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
T_5 type = F_2 ( V_2 , V_3 ) ;
T_1 V_4 = F_2 ( V_2 , V_3 + 2 ) ;
if ( type & 0xC000 )
{
return ( V_4 + V_5 + 3 ) & ~ 0x3 ;
}
else
{
return V_4 + V_6 ;
}
}
static int
F_3 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , T_5 V_8 , T_1 V_9 )
{
T_1 V_10 ;
T_4 * V_11 ;
V_10 = F_4 ( V_2 ) ;
if ( V_8 == 0xFFFF )
return 0 ;
if ( T_3 -> V_12 == V_13 ) {
if ( V_10 != ( V_9 + V_5 ) )
return 0 ;
} else {
if ( V_10 != ( ( V_9 + V_5 + 3 ) & ~ 0x3 ) )
return 0 ;
}
F_5 ( T_3 -> V_14 , V_15 , L_1 ) ;
F_5 ( T_3 -> V_14 , V_16 , L_2 ) ;
if ( V_7 ) {
T_7 * V_17 ;
T_6 * V_18 ;
V_17 = F_6 (
V_7 , V_19 , V_2 , 0 ,
V_5 ,
V_20 ) ;
F_7 ( V_17 , L_3 ) ;
V_18 = F_8 ( V_17 , V_21 ) ;
F_6 ( V_18 , V_22 , V_2 , 0 , 2 , V_23 ) ;
F_6 ( V_18 , V_24 , V_2 , 2 , 2 , V_23 ) ;
}
V_11 = F_9 ( V_2 , V_5 ) ;
if ( ! F_10 ( V_25 , V_11 , T_3 , V_7 , NULL ) ) {
F_11 ( V_26 , V_11 , T_3 , V_7 , NULL ) ;
}
return V_10 ;
}
static int
F_12 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , T_8 V_27 )
{
T_1 V_28 ;
T_5 V_8 ;
T_1 V_9 ;
T_7 * V_17 ;
T_6 * V_18 ;
T_6 * V_29 ;
T_6 * V_30 ;
T_6 * V_31 ;
T_6 * V_32 ;
T_5 V_33 ;
T_5 V_34 ;
const char * V_35 ;
const char * V_36 ;
T_5 V_37 ;
T_5 V_38 ;
T_1 V_39 ;
T_1 V_40 ;
T_9 * V_41 = NULL ;
T_10 * V_42 ;
T_11 * V_43 ;
T_12 V_44 [ 2 ] ;
T_13 V_45 [ 3 ] ;
V_28 = F_13 ( V_2 ) ;
if ( V_28 < V_46 )
return 0 ;
V_8 = F_2 ( V_2 , 0 ) ;
V_9 = F_2 ( V_2 , 2 ) ;
if ( V_8 & 0xC000 ) {
if ( V_27 ) {
if ( F_14 ( T_3 -> V_47 -> V_48 , & T_3 -> V_49 , & T_3 -> V_50 ,
T_3 -> V_51 , T_3 -> V_52 ,
T_3 -> V_53 , 0 ) == NULL )
return 0 ;
}
return F_3 ( V_2 , T_3 , V_7 , V_8 , V_9 ) ;
}
if ( V_28 < V_6 )
return 0 ;
if ( F_15 ( V_2 , 4 ) != 0x2112a442 )
return 0 ;
if ( F_4 ( V_2 ) != ( V_9 + V_6 ) )
return 0 ;
F_5 ( T_3 -> V_14 , V_15 , L_1 ) ;
V_45 [ 0 ] = F_15 ( V_2 , 8 ) ;
V_45 [ 1 ] = F_15 ( V_2 , 12 ) ;
V_45 [ 2 ] = F_15 ( V_2 , 16 ) ;
V_44 [ 0 ] . V_4 = 3 ;
V_44 [ 0 ] . V_54 = V_45 ;
V_44 [ 1 ] . V_4 = 0 ;
V_44 [ 1 ] . V_54 = NULL ;
V_34 = ( ( V_8 & 0x0010 ) >> 4 ) | ( ( V_8 & 0x0100 ) >> 7 ) ;
V_33 = ( V_8 & 0x000F ) | ( ( V_8 & 0x00E0 ) >> 1 ) | ( ( V_8 & 0x3E00 ) >> 2 ) ;
V_41 = F_16 ( T_3 ) ;
V_42 = ( T_10 * ) F_17 ( V_41 , V_19 ) ;
if ( ! V_42 ) {
V_42 = F_18 ( T_10 ) ;
V_42 -> V_55 = F_19 ( V_56 , L_4 ) ;
F_20 ( V_41 , V_19 , V_42 ) ;
}
if ( ! T_3 -> V_47 -> V_57 . V_58 ) {
if ( ( V_43 = ( T_11 * )
F_21 ( V_42 -> V_55 ,
V_44 ) ) == NULL ) {
V_44 [ 0 ] . V_4 = 3 ;
V_44 [ 0 ] . V_54 = V_45 ;
V_44 [ 1 ] . V_4 = 0 ;
V_44 [ 1 ] . V_54 = NULL ;
V_43 = F_18 ( T_11 ) ;
V_43 -> V_59 = 0 ;
V_43 -> V_60 = 0 ;
V_43 -> V_61 = T_3 -> V_47 -> V_62 ;
F_22 ( V_42 -> V_55 ,
V_44 ,
( void * ) V_43 ) ;
}
if ( V_34 == V_63 ) {
if ( V_43 -> V_59 == 0 ) {
V_43 -> V_59 = T_3 -> V_47 -> V_48 ;
}
} else {
if ( V_43 -> V_60 == 0 ) {
V_43 -> V_60 = T_3 -> V_47 -> V_48 ;
}
}
} else {
V_43 = ( T_11 * ) F_21 ( V_42 -> V_55 ,
V_44 ) ;
}
if ( ! V_43 ) {
V_43 = F_23 ( T_11 ) ;
V_43 -> V_59 = 0 ;
V_43 -> V_60 = 0 ;
V_43 -> V_61 = T_3 -> V_47 -> V_62 ;
}
V_35 = F_24 ( V_34 , V_64 , L_5 ) ;
V_36 = F_24 ( V_33 , V_65 , L_5 ) ;
F_25 ( T_3 -> V_14 , V_16 , L_6 ,
V_36 , V_35 ) ;
V_17 = F_6 ( V_7 , V_19 , V_2 , 0 , - 1 , V_20 ) ;
V_18 = F_8 ( V_17 , V_21 ) ;
if ( V_34 == V_63 ) {
if ( V_43 -> V_59 != T_3 -> V_47 -> V_48 ) {
T_7 * V_66 ;
V_66 = F_26 ( V_18 , V_67 ,
V_2 , 0 , 0 ,
V_43 -> V_59 ) ;
F_27 ( V_66 ) ;
}
if ( V_43 -> V_60 ) {
T_7 * V_66 ;
V_66 = F_26 ( V_18 , V_68 ,
V_2 , 0 , 0 ,
V_43 -> V_60 ) ;
F_27 ( V_66 ) ;
}
}
else {
if ( V_43 -> V_60 != T_3 -> V_47 -> V_48 ) {
T_7 * V_66 ;
V_66 = F_26 ( V_18 , V_67 ,
V_2 , 0 , 0 ,
V_43 -> V_60 ) ;
F_27 ( V_66 ) ;
}
if ( V_34 == V_69 || V_34 == V_70 ) {
if ( V_43 -> V_59 ) {
T_7 * V_66 ;
T_14 V_71 ;
V_66 = F_26 ( V_18 , V_72 , V_2 , 0 , 0 ,
V_43 -> V_59 ) ;
F_27 ( V_66 ) ;
F_28 ( & V_71 , & T_3 -> V_47 -> V_62 , & V_43 -> V_61 ) ;
V_66 = F_29 ( V_18 , V_73 , V_2 , 0 , 0 , & V_71 ) ;
F_27 ( V_66 ) ;
}
}
}
V_17 = F_30 ( V_18 , V_74 , V_2 , 0 , 2 ,
V_8 , L_7 , V_8 , V_36 , V_35 ) ;
V_29 = F_8 ( V_17 , V_75 ) ;
F_26 ( V_29 , V_76 , V_2 , 0 , 2 , V_8 ) ;
V_17 = F_31 ( V_29 , V_2 , 0 , 2 , L_8 , V_35 , V_34 ) ;
F_27 ( V_17 ) ;
F_26 ( V_29 , V_77 , V_2 , 0 , 2 , V_8 ) ;
V_17 = F_31 ( V_29 , V_2 , 0 , 2 , L_9 , V_36 , V_33 ) ;
F_27 ( V_17 ) ;
F_26 ( V_29 , V_78 , V_2 , 0 , 2 , V_8 ) ;
V_17 = F_31 ( V_29 , V_2 , 0 , 2 ,
L_8 ,
F_32 ( ( V_8 & 0x2000 ) >> 13 , V_79 , L_10 ) ,
( V_8 & 0x2000 ) >> 13 ) ;
F_27 ( V_17 ) ;
F_6 ( V_18 , V_24 , V_2 , 2 , 2 , V_23 ) ;
F_6 ( V_18 , V_80 , V_2 , 4 , 4 , V_20 ) ;
F_6 ( V_18 , V_81 , V_2 , 8 , 12 , V_20 ) ;
V_40 = F_15 ( V_2 , 4 ) ;
if ( V_9 != 0 ) {
T_1 V_3 ;
V_17 = F_6 ( V_18 , V_82 , V_2 , V_6 , V_9 , V_20 ) ;
V_30 = F_8 ( V_17 , V_83 ) ;
V_3 = V_6 ;
while ( V_3 < ( V_6 + V_9 ) ) {
V_37 = F_2 ( V_2 , V_3 ) ;
V_38 = F_2 ( V_2 , V_3 + 2 ) ;
V_17 = F_30 ( V_30 , V_84 ,
V_2 , V_3 , V_85 + V_38 ,
V_37 , L_11 , F_24 ( V_37 , V_86 , L_5 ) ) ;
V_32 = F_8 ( V_17 , V_87 ) ;
V_17 = F_26 ( V_32 , V_88 , V_2 ,
V_3 , 2 , V_37 ) ;
V_31 = F_8 ( V_17 , V_89 ) ;
F_26 ( V_31 , V_90 , V_2 , V_3 , 2 , V_37 ) ;
V_17 = F_31 ( V_31 , V_2 , V_3 , 2 ,
L_8 ,
F_32 ( ( V_37 & 0x8000 ) >> 15 , V_91 , L_12 ) ,
( V_37 & 0x8000 ) >> 15 ) ;
F_27 ( V_17 ) ;
F_26 ( V_31 , V_92 , V_2 , V_3 , 2 , V_37 ) ;
V_17 = F_31 ( V_31 , V_2 , V_3 , 2 ,
L_8 ,
F_32 ( ( V_37 & 0x4000 ) >> 14 , V_79 , L_12 ) ,
( V_37 & 0x4000 ) >> 14 ) ;
F_27 ( V_17 ) ;
if ( ( V_3 + V_85 + V_38 ) > ( V_6 + V_9 ) ) {
F_30 ( V_32 ,
V_93 , V_2 , V_3 + 2 , 2 ,
V_38 ,
L_13 ,
V_38 ) ;
break;
}
V_3 += 2 ;
F_26 ( V_32 , V_93 , V_2 ,
V_3 , 2 , V_38 ) ;
V_3 += 2 ;
switch ( V_37 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_98 , V_2 , V_3 , 1 , V_23 ) ;
if ( V_38 < 2 )
break;
F_6 ( V_32 , V_99 , V_2 , V_3 + 1 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_100 , V_2 , V_3 + 2 , 2 , V_23 ) ;
switch ( F_33 ( V_2 , V_3 + 1 ) )
{
case 1 :
if ( V_38 < 8 )
break;
F_6 ( V_32 , V_101 , V_2 , V_3 + 4 , 4 , V_23 ) ;
F_7 ( V_32 , L_14 , F_34 ( V_2 , V_3 + 4 ) , F_2 ( V_2 , V_3 + 2 ) ) ;
break;
case 2 :
if ( V_38 < 20 )
break;
F_6 ( V_32 , V_102 , V_2 , V_3 + 4 , 16 , V_20 ) ;
break;
}
break;
case V_103 :
F_6 ( V_32 , V_104 , V_2 , V_3 , V_38 , V_105 | V_20 ) ;
F_7 ( V_32 , L_15 , F_35 ( V_2 , V_3 , V_38 ) ) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 ,
V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_98 , V_2 , V_3 , 1 , V_23 ) ;
if ( V_38 < 2 )
break;
F_6 ( V_32 , V_99 , V_2 , V_3 + 1 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_100 , V_2 , V_3 + 2 , 2 , V_23 ) ;
switch ( F_33 ( V_2 , V_3 + 1 ) ) {
case 1 :
if ( V_38 < 8 )
break;
F_6 ( V_32 , V_101 , V_2 , V_3 + 4 , 4 , V_23 ) ;
F_7 ( V_32 , L_16 , F_34 ( V_2 , V_3 + 4 ) , F_2 ( V_2 , V_3 + 2 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_17 ,
F_24 ( V_37 , V_86 , L_5 ) ,
F_34 ( V_2 , V_3 + 4 ) ,
F_2 ( V_2 , V_3 + 2 )
) ;
break;
case 2 :
if ( V_38 < 20 )
break;
F_6 ( V_32 , V_102 , V_2 , V_3 + 4 , 16 , V_20 ) ;
break;
}
break;
case V_111 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_112 , V_2 , V_3 , 4 , V_23 ) ;
F_6 ( V_32 , V_113 , V_2 , V_3 , 4 , V_23 ) ;
break;
case V_114 :
F_6 ( V_32 , V_115 , V_2 , V_3 , V_38 , V_105 | V_20 ) ;
F_7 ( V_32 , L_18 , F_35 ( V_2 , V_3 , V_38 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_19 ,
F_35 ( V_2 , V_3 , V_38 )
) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 ,
V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_116 :
if ( V_38 < 20 )
break;
F_6 ( V_32 , V_117 , V_2 , V_3 , V_38 , V_20 ) ;
break;
case V_118 :
if ( V_38 < 2 )
break;
F_6 ( V_32 , V_98 , V_2 , V_3 , 2 , V_23 ) ;
if ( V_38 < 3 )
break;
F_6 ( V_32 , V_119 , V_2 , V_3 + 2 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_120 , V_2 , V_3 + 3 , 1 , V_23 ) ;
{
int V_121 = F_33 ( V_2 , V_3 + 2 ) * 100 + F_33 ( V_2 , V_3 + 3 ) ;
F_7 (
V_32 ,
L_20 ,
V_121 ,
F_24 ( V_121 , V_122 , L_21 )
) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_22 ,
V_121 ,
F_24 ( V_121 , V_122 , L_21 )
) ;
}
if ( V_38 < 5 )
break;
F_6 ( V_32 , V_123 , V_2 , V_3 + 4 , V_38 - 4 , V_105 | V_20 ) ;
F_7 ( V_32 , L_18 , F_35 ( V_2 , V_3 + 4 , V_38 - 4 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_23 ,
F_35 ( V_2 , V_3 + 4 , V_38 - 4 )
) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_124 :
for ( V_39 = 0 ; V_39 < V_38 ; V_39 += 2 )
F_6 ( V_32 , V_125 , V_2 , V_3 + V_39 , 2 , V_23 ) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_126 :
F_6 ( V_32 , V_127 , V_2 , V_3 , V_38 , V_105 | V_20 ) ;
F_7 ( V_32 , L_18 , F_35 ( V_2 , V_3 , V_38 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_24 ,
F_35 ( V_2 , V_3 , V_38 )
) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_128 :
F_6 ( V_32 , V_129 , V_2 , V_3 , V_38 , V_105 | V_20 ) ;
F_7 ( V_32 , L_18 , F_35 ( V_2 , V_3 , V_38 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_25
) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_98 , V_2 , V_3 , 1 , V_23 ) ;
if ( V_38 < 2 )
break;
F_6 ( V_32 , V_99 , V_2 , V_3 + 1 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_135 , V_2 , V_3 + 2 , 2 , V_20 ) ;
V_17 = F_26 ( V_32 , V_100 , V_2 , V_3 + 2 , 2 ,
F_2 ( V_2 , V_3 + 2 ) ^ ( V_40 >> 16 ) ) ;
F_27 ( V_17 ) ;
if ( V_38 < 8 )
break;
switch ( F_33 ( V_2 , V_3 + 1 ) ) {
case 1 :
F_6 ( V_32 , V_136 , V_2 , V_3 + 4 , 4 , V_20 ) ;
V_17 = F_37 ( V_32 , V_101 , V_2 , V_3 + 4 , 4 ,
F_38 ( V_2 , V_3 + 4 ) ^ F_39 ( V_40 ) ) ;
F_27 ( V_17 ) ;
{
const T_15 * V_137 ;
T_13 V_138 ;
T_5 V_139 ;
V_138 = F_38 ( V_2 , V_3 + 4 ) ^ F_39 ( V_40 ) ;
V_137 = F_40 ( ( V_140 * ) & V_138 ) ;
V_139 = F_2 ( V_2 , V_3 + 2 ) ^ ( V_40 >> 16 ) ;
F_7 ( V_32 , L_16 , V_137 , V_139 ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_17 ,
F_24 ( V_37 , V_86 , L_5 ) ,
V_137 ,
V_139
) ;
}
break;
case 2 :
if ( V_38 < 20 )
break;
F_6 ( V_32 , V_141 , V_2 , V_3 + 4 , 16 , V_20 ) ;
{
T_13 V_142 [ 4 ] ;
F_41 ( V_2 , V_3 + 4 , (struct V_143 * ) V_142 ) ;
V_142 [ 0 ] = V_142 [ 0 ] ^ F_39 ( V_40 ) ;
V_142 [ 1 ] = V_142 [ 1 ] ^ F_39 ( V_45 [ 0 ] ) ;
V_142 [ 2 ] = V_142 [ 2 ] ^ F_39 ( V_45 [ 1 ] ) ;
V_142 [ 3 ] = V_142 [ 3 ] ^ F_39 ( V_45 [ 2 ] ) ;
V_17 = F_42 ( V_32 , V_102 , V_2 , V_3 + 4 , 16 ,
( const V_140 * ) V_142 ) ;
F_27 ( V_17 ) ;
}
break;
}
break;
case V_144 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_99 , V_2 , V_3 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_98 , V_2 , V_3 + 1 , 3 , V_23 ) ;
break;
case V_145 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_146 , V_2 , V_3 , 1 , V_23 ) ;
break;
case V_147 :
if ( V_38 < 8 )
break;
F_6 ( V_32 , V_148 , V_2 , V_3 , 8 , V_20 ) ;
break;
case V_149 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_150 , V_2 , V_3 , 4 , V_23 ) ;
break;
case V_151 :
F_26 ( V_32 , V_106 , V_2 , V_3 , V_38 , V_38 ) ;
break;
case V_152 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_153 , V_2 , V_3 , 1 , V_23 ) ;
F_6 ( V_32 , V_154 , V_2 , V_3 + 1 , 1 , V_23 ) ;
break;
case V_155 :
F_6 ( V_32 , V_156 , V_2 , V_3 , V_38 , V_105 | V_20 ) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
case V_157 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_158 , V_2 , V_3 , 4 , V_23 ) ;
break;
case V_159 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_160 , V_2 , V_3 , V_38 , V_23 ) ;
break;
case V_161 :
case V_162 :
if ( V_38 < 8 )
break;
F_6 ( V_32 , V_163 , V_2 , V_3 , 8 , V_20 ) ;
break;
case V_164 :
if ( V_38 > 0 ) {
T_4 * V_11 ;
F_6 ( V_32 , V_165 , V_2 , V_3 , V_38 , V_20 ) ;
if ( V_38 % 4 != 0 ) {
T_1 V_166 ;
V_166 = 4 - ( V_38 % 4 ) ;
F_26 ( V_32 , V_106 , V_2 , V_3 + V_38 , V_166 , V_166 ) ;
}
V_11 = F_43 ( V_2 , V_3 , V_38 , V_38 ) ;
if ( ! F_10 ( V_25 , V_11 , T_3 , V_32 , NULL ) ) {
F_11 ( V_26 , V_11 , T_3 , V_32 , NULL ) ;
}
}
break;
case V_167 :
if ( V_38 < 1 )
break;
F_6 ( V_32 , V_168 , V_2 , V_3 , 1 , V_23 ) ;
if ( V_38 < 4 )
break;
{
V_140 V_169 = F_33 ( V_2 , V_3 ) ;
F_7 ( V_32 , L_18 , F_32 ( V_169 , V_170 , L_26 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_23 ,
F_32 ( V_169 , V_170 , L_26 )
) ;
}
F_6 ( V_32 , V_98 , V_2 , V_3 + 1 , 3 , V_23 ) ;
break;
case V_171 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_172 , V_2 , V_3 , 2 , V_23 ) ;
{
T_5 V_173 = F_2 ( V_2 , V_3 ) ;
F_7 ( V_32 , L_27 , V_173 ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_28 ,
V_173
) ;
}
F_6 ( V_32 , V_98 , V_2 , V_3 + 2 , 2 , V_23 ) ;
break;
case V_174 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_175 , V_2 , V_3 , 4 , V_23 ) ;
F_7 ( V_32 , L_29 , F_15 ( V_2 , V_3 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_30 ,
F_15 ( V_2 , V_3 )
) ;
break;
case V_176 :
if ( V_38 < 4 )
break;
F_6 ( V_32 , V_177 , V_2 , V_3 , 4 , V_23 ) ;
F_7 ( V_32 , L_29 , F_15 ( V_2 , V_3 ) ) ;
F_36 (
T_3 -> V_14 , V_16 ,
L_31 ,
F_15 ( V_2 , V_3 )
) ;
break;
default:
if ( V_38 > 0 )
F_6 ( V_32 , V_165 , V_2 , V_3 , V_38 , V_20 ) ;
if ( V_38 % 4 != 0 )
F_26 ( V_32 , V_106 , V_2 ,
V_3 + V_38 , 4 - ( V_38 % 4 ) , 4 - ( V_38 % 4 ) ) ;
break;
}
V_3 += ( V_38 + 3 ) & ~ 0x3 ;
}
}
return F_4 ( V_2 ) ;
}
static int
F_44 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , void * T_16 V_1 )
{
return F_12 ( V_2 , T_3 , V_7 , FALSE ) ;
}
static void
F_45 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 )
{
F_12 ( V_2 , T_3 , V_7 , FALSE ) ;
}
static void
F_46 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 )
{
F_47 ( V_2 , T_3 , V_7 , TRUE , V_46 ,
F_1 , F_45 ) ;
}
static T_8
F_48 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , void * T_16 V_1 )
{
if ( F_12 ( V_2 , T_3 , V_7 , TRUE ) == 0 ) {
return FALSE ;
}
return TRUE ;
}
void
F_49 ( void )
{
static T_17 V_178 [] = {
{ & V_22 ,
{ L_32 , L_33 , V_179 ,
V_180 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_74 ,
{ L_34 , L_35 , V_179 ,
V_180 , NULL , 0 , NULL , V_181 }
} ,
{ & V_76 ,
{ L_36 , L_37 , V_179 ,
V_180 , NULL , 0x0110 , NULL , V_181 }
} ,
{ & V_77 ,
{ L_38 , L_39 , V_179 ,
V_180 , NULL , 0x3EEF , NULL , V_181 }
} ,
{ & V_78 ,
{ L_40 , L_41 , V_179 ,
V_180 , NULL , 0x2000 , NULL , V_181 }
} ,
{ & V_24 ,
{ L_42 , L_43 , V_179 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_80 ,
{ L_44 , L_45 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_81 ,
{ L_46 , L_47 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_82 ,
{ L_48 , L_49 , V_185 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_84 ,
{ L_50 , L_51 , V_179 ,
V_180 , NULL , 0 , NULL , V_181 }
} ,
{ & V_68 ,
{ L_52 , L_53 , V_186 ,
V_184 , NULL , 0x0 , L_54 , V_181 }
} ,
{ & V_72 ,
{ L_55 , L_56 , V_186 ,
V_184 , NULL , 0x0 , L_57 , V_181 }
} ,
{ & V_73 ,
{ L_58 , L_59 , V_187 ,
V_184 , NULL , 0x0 , L_60 , V_181 }
} ,
{ & V_67 ,
{ L_61 , L_62 , V_186 ,
V_184 , NULL , 0x0 , L_63 , V_181 }
} ,
{ & V_88 ,
{ L_50 , L_64 , V_179 ,
V_180 , F_50 ( V_86 ) , 0x0 , NULL , V_181 }
} ,
{ & V_90 ,
{ L_65 , L_66 , V_179 ,
V_180 , NULL , 0x8000 , NULL , V_181 }
} ,
{ & V_92 ,
{ L_67 , L_68 , V_179 ,
V_180 , NULL , 0x4000 , NULL , V_181 }
} ,
{ & V_93 ,
{ L_69 , L_70 , V_179 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_99 ,
{ L_71 , L_72 , V_188 ,
V_180 , F_50 ( V_189 ) , 0x0 , NULL , V_181 }
} ,
{ & V_101 ,
{ L_73 , L_74 , V_190 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_102 ,
{ L_73 , L_75 , V_191 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_100 ,
{ L_76 , L_77 , V_179 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_115 ,
{ L_78 , L_79 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_104 ,
{ L_80 , L_81 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_106 ,
{ L_82 , L_83 , V_179 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_117 ,
{ L_84 , L_85 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_160 ,
{ L_86 , L_87 , V_193 ,
V_180 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_119 ,
{ L_88 , L_89 , V_188 ,
V_182 , NULL , 0x07 , NULL , V_181 }
} ,
{ & V_120 ,
{ L_90 , L_91 , V_188 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_123 ,
{ L_92 , L_93 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_127 ,
{ L_94 , L_95 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_129 ,
{ L_96 , L_97 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_125 ,
{ L_98 , L_99 , V_179 ,
V_180 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_136 ,
{ L_100 , L_101 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_141 ,
{ L_100 , L_102 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_135 ,
{ L_103 , L_104 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_153 ,
{ L_105 , L_106 , V_188 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_154 ,
{ L_107 , L_108 , V_188 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_156 ,
{ L_109 , L_110 , V_192 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_150 ,
{ L_111 , L_112 , V_193 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_163 ,
{ L_113 , L_114 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_177 ,
{ L_115 , L_116 , V_193 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_112 ,
{ L_117 , L_118 , V_194 ,
16 , F_51 ( & V_195 ) , 0x0004 , NULL , V_181 }
} ,
{ & V_113 ,
{ L_119 , L_120 , V_194 ,
16 , F_51 ( & V_195 ) , 0x0002 , NULL , V_181 }
} ,
{ & V_146 ,
{ L_121 , L_122 , V_188 ,
V_182 , F_50 ( V_196 ) , 0x80 , NULL , V_181 }
} ,
{ & V_158 ,
{ L_123 , L_124 , V_193 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_148 ,
{ L_125 , L_126 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_165 ,
{ L_127 , L_128 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_98 ,
{ L_129 , L_130 , V_183 ,
V_184 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_168 ,
{ L_131 , L_132 , V_188 ,
V_180 , F_50 ( V_170 ) , 0x0 , NULL , V_181 }
} ,
{ & V_172 ,
{ L_133 , L_134 , V_179 ,
V_180 , NULL , 0x0 , NULL , V_181 }
} ,
{ & V_175 ,
{ L_135 , L_136 , V_193 ,
V_182 , NULL , 0x0 , NULL , V_181 }
} ,
} ;
static T_18 * V_197 [] = {
& V_21 ,
& V_75 ,
& V_83 ,
& V_87 ,
& V_89 ,
} ;
V_19 = F_52 ( L_137 , L_1 , L_138 ) ;
F_53 ( V_19 , V_178 , F_54 ( V_178 ) ) ;
F_55 ( V_197 , F_54 ( V_197 ) ) ;
F_56 ( L_138 , & V_25 ) ;
F_57 ( L_139 , F_44 , V_19 ) ;
F_57 ( L_140 , F_48 , V_19 ) ;
}
void
F_58 ( void )
{
T_19 V_198 ;
T_19 V_199 ;
V_198 = F_59 ( F_46 , V_19 ) ;
V_199 = F_60 ( F_44 , V_19 ) ;
F_61 ( L_141 , V_200 , V_198 ) ;
F_61 ( L_142 , V_201 , V_199 ) ;
F_62 ( L_141 , V_198 ) ;
F_62 ( L_142 , V_199 ) ;
F_63 ( L_143 , F_48 , V_19 ) ;
V_26 = F_64 ( L_144 ) ;
}
