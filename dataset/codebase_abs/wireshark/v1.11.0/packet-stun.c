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
F_3 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , T_5 T_7 V_1 , T_1 T_8 V_1 )
{
T_4 * V_8 ;
F_4 ( T_3 -> V_9 , V_10 , L_1 ) ;
F_4 ( T_3 -> V_9 , V_11 , L_2 ) ;
if ( V_7 ) {
T_9 * V_12 ;
T_6 * V_13 ;
V_12 = F_5 (
V_7 , V_14 , V_2 , 0 ,
V_5 ,
V_15 ) ;
F_6 ( V_12 , L_3 ) ;
V_13 = F_7 ( V_12 , V_16 ) ;
F_5 ( V_13 , V_17 , V_2 , 0 , 2 , V_18 ) ;
F_5 ( V_13 , V_19 , V_2 , 2 , 2 , V_18 ) ;
}
V_8 = F_8 ( V_2 , V_5 ) ;
if ( ! F_9 ( V_20 , V_8 , T_3 , V_7 , NULL ) ) {
F_10 ( V_21 , V_8 , T_3 , V_7 , NULL ) ;
}
return F_11 ( V_2 ) ;
}
static int
F_12 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , T_10 V_22 )
{
T_1 V_23 ;
T_5 T_7 ;
T_1 T_8 ;
T_9 * V_12 ;
T_6 * V_13 ;
T_6 * V_24 ;
T_6 * V_25 ;
T_6 * V_26 ;
T_6 * V_27 = NULL ;
T_5 V_28 ;
T_5 V_29 ;
const char * V_30 ;
const char * V_31 ;
T_5 V_32 ;
T_5 V_33 ;
T_1 V_34 ;
T_1 V_35 ;
T_11 * V_36 = NULL ;
T_12 * V_37 ;
T_13 * V_38 ;
T_14 V_39 [ 2 ] ;
T_15 V_40 [ 3 ] ;
V_23 = F_13 ( V_2 ) ;
if ( V_23 < V_41 )
return 0 ;
T_7 = F_2 ( V_2 , 0 ) ;
T_8 = F_2 ( V_2 , 2 ) ;
if ( T_7 & 0xC000 ) {
T_1 V_42 = F_11 ( V_2 ) ;
if ( T_7 == 0xFFFF )
return 0 ;
if ( T_3 -> V_43 == V_44 ) {
if ( V_42 != ( T_8 + V_5 ) )
return 0 ;
} else {
if ( V_42 != ( ( T_8 + V_5 + 3 ) & ~ 0x3 ) )
return 0 ;
}
if ( V_22 ) {
if ( F_14 ( T_3 -> V_45 -> V_46 , & T_3 -> V_47 , & T_3 -> V_48 ,
T_3 -> V_49 , T_3 -> V_50 ,
T_3 -> V_51 , 0 ) == NULL )
return 0 ;
}
return F_3 ( V_2 , T_3 , V_7 , T_7 , T_8 ) ;
}
if ( V_23 < V_6 )
return 0 ;
if ( F_15 ( V_2 , 4 ) != 0x2112a442 )
return 0 ;
if ( F_11 ( V_2 ) != ( T_8 + V_6 ) )
return 0 ;
F_4 ( T_3 -> V_9 , V_10 , L_1 ) ;
V_40 [ 0 ] = F_15 ( V_2 , 8 ) ;
V_40 [ 1 ] = F_15 ( V_2 , 12 ) ;
V_40 [ 2 ] = F_15 ( V_2 , 16 ) ;
V_39 [ 0 ] . V_4 = 3 ;
V_39 [ 0 ] . V_52 = V_40 ;
V_39 [ 1 ] . V_4 = 0 ;
V_39 [ 1 ] . V_52 = NULL ;
V_29 = ( ( T_7 & 0x0010 ) >> 4 ) | ( ( T_7 & 0x0100 ) >> 7 ) ;
V_28 = ( T_7 & 0x000F ) | ( ( T_7 & 0x00E0 ) >> 1 ) | ( ( T_7 & 0x3E00 ) >> 2 ) ;
V_36 = F_16 ( T_3 ) ;
V_37 = ( T_12 * ) F_17 ( V_36 , V_14 ) ;
if ( ! V_37 ) {
V_37 = F_18 ( F_19 () , T_12 ) ;
V_37 -> V_53 = F_20 ( F_19 () ) ;
F_21 ( V_36 , V_14 , V_37 ) ;
}
if ( ! T_3 -> V_45 -> V_54 . V_55 ) {
if ( ( V_38 = ( T_13 * )
F_22 ( V_37 -> V_53 ,
V_39 ) ) == NULL ) {
V_39 [ 0 ] . V_4 = 3 ;
V_39 [ 0 ] . V_52 = V_40 ;
V_39 [ 1 ] . V_4 = 0 ;
V_39 [ 1 ] . V_52 = NULL ;
V_38 = F_18 ( F_19 () , T_13 ) ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_58 = T_3 -> V_45 -> V_59 ;
F_23 ( V_37 -> V_53 ,
V_39 ,
( void * ) V_38 ) ;
}
if ( V_29 == V_60 ) {
if ( V_38 -> V_56 == 0 ) {
V_38 -> V_56 = T_3 -> V_45 -> V_46 ;
}
} else {
if ( V_38 -> V_57 == 0 ) {
V_38 -> V_57 = T_3 -> V_45 -> V_46 ;
}
}
} else {
V_38 = ( T_13 * ) F_22 ( V_37 -> V_53 ,
V_39 ) ;
}
if ( ! V_38 ) {
V_38 = F_18 ( F_24 () , T_13 ) ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_58 = T_3 -> V_45 -> V_59 ;
}
V_30 = F_25 ( V_29 , V_61 , L_4 ) ;
V_31 = F_25 ( V_28 , V_62 , L_4 ) ;
F_26 ( T_3 -> V_9 , V_11 , L_5 ,
V_31 , V_30 ) ;
V_12 = F_5 ( V_7 , V_14 , V_2 , 0 , - 1 , V_15 ) ;
V_13 = F_7 ( V_12 , V_16 ) ;
if( V_7 ) {
if ( V_29 == V_60 ) {
if ( V_38 -> V_56 != T_3 -> V_45 -> V_46 ) {
T_9 * V_63 ;
V_63 = F_27 ( V_13 , V_64 ,
V_2 , 0 , 0 ,
V_38 -> V_56 ) ;
F_28 ( V_63 ) ;
}
if ( V_38 -> V_57 ) {
T_9 * V_63 ;
V_63 = F_27 ( V_13 , V_65 ,
V_2 , 0 , 0 ,
V_38 -> V_57 ) ;
F_28 ( V_63 ) ;
}
}
else {
if ( V_38 -> V_57 != T_3 -> V_45 -> V_46 ) {
T_9 * V_63 ;
V_63 = F_27 ( V_13 , V_64 ,
V_2 , 0 , 0 ,
V_38 -> V_57 ) ;
F_28 ( V_63 ) ;
}
if ( V_29 == V_66 || V_29 == V_67 ) {
if ( V_38 -> V_56 ) {
T_9 * V_63 ;
T_16 V_68 ;
V_63 = F_27 ( V_13 , V_69 , V_2 , 0 , 0 ,
V_38 -> V_56 ) ;
F_28 ( V_63 ) ;
F_29 ( & V_68 , & T_3 -> V_45 -> V_59 , & V_38 -> V_58 ) ;
V_63 = F_30 ( V_13 , V_70 , V_2 , 0 , 0 , & V_68 ) ;
F_28 ( V_63 ) ;
}
}
}
V_12 = F_31 ( V_13 , V_71 , V_2 , 0 , 2 ,
T_7 , L_6 , T_7 , V_31 , V_30 ) ;
V_24 = F_7 ( V_12 , V_72 ) ;
F_27 ( V_24 , V_73 , V_2 , 0 , 2 , T_7 ) ;
V_12 = F_32 ( V_24 , V_2 , 0 , 2 , L_7 , V_30 , V_29 ) ;
F_28 ( V_12 ) ;
F_27 ( V_24 , V_74 , V_2 , 0 , 2 , T_7 ) ;
V_12 = F_32 ( V_24 , V_2 , 0 , 2 , L_8 , V_31 , V_28 ) ;
F_28 ( V_12 ) ;
F_27 ( V_24 , V_75 , V_2 , 0 , 2 , T_7 ) ;
V_12 = F_32 ( V_24 , V_2 , 0 , 2 ,
L_7 ,
F_33 ( ( T_7 & 0x2000 ) >> 13 , V_76 , L_9 ) ,
( T_7 & 0x2000 ) >> 13 ) ;
F_28 ( V_12 ) ;
F_5 ( V_13 , V_19 , V_2 , 2 , 2 , V_18 ) ;
F_5 ( V_13 , V_77 , V_2 , 4 , 4 , V_15 ) ;
F_5 ( V_13 , V_78 , V_2 , 8 , 12 , V_15 ) ;
}
V_35 = F_15 ( V_2 , 4 ) ;
if ( T_8 != 0 ) {
T_1 V_3 ;
V_12 = F_5 ( V_13 , V_79 , V_2 , V_6 , T_8 , V_15 ) ;
V_25 = F_7 ( V_12 , V_80 ) ;
V_3 = V_6 ;
while ( V_3 < ( V_6 + T_8 ) ) {
V_32 = F_2 ( V_2 , V_3 ) ;
V_33 = F_2 ( V_2 , V_3 + 2 ) ;
if( V_25 ) {
V_12 = F_34 ( V_25 , V_81 ,
V_2 , V_3 , V_82 + V_33 ,
V_32 , L_10 , F_25 ( V_32 , V_83 , L_4 ) ) ;
V_27 = F_7 ( V_12 , V_84 ) ;
V_12 = F_27 ( V_27 , V_85 , V_2 ,
V_3 , 2 , V_32 ) ;
V_26 = F_7 ( V_12 , V_86 ) ;
F_27 ( V_26 , V_87 , V_2 , V_3 , 2 , V_32 ) ;
V_12 = F_32 ( V_26 , V_2 , V_3 , 2 ,
L_7 ,
F_33 ( ( V_32 & 0x8000 ) >> 15 , V_88 , L_11 ) ,
( V_32 & 0x8000 ) >> 15 ) ;
F_28 ( V_12 ) ;
F_27 ( V_26 , V_89 , V_2 , V_3 , 2 , V_32 ) ;
V_12 = F_32 ( V_26 , V_2 , V_3 , 2 ,
L_7 ,
F_33 ( ( V_32 & 0x4000 ) >> 14 , V_76 , L_11 ) ,
( V_32 & 0x4000 ) >> 14 ) ;
F_28 ( V_12 ) ;
if ( ( V_3 + V_82 + V_33 ) > ( V_6 + T_8 ) ) {
F_31 ( V_27 ,
V_90 , V_2 , V_3 + 2 , 2 ,
V_33 ,
L_12 ,
V_33 ) ;
break;
}
}
V_3 += 2 ;
F_27 ( V_27 , V_90 , V_2 ,
V_3 , 2 , V_33 ) ;
V_3 += 2 ;
switch ( V_32 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_95 , V_2 , V_3 , 1 , V_18 ) ;
if ( V_33 < 2 )
break;
F_5 ( V_27 , V_96 , V_2 , V_3 + 1 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_97 , V_2 , V_3 + 2 , 2 , V_18 ) ;
switch ( F_35 ( V_2 , V_3 + 1 ) )
{
case 1 :
if ( V_33 < 8 )
break;
F_5 ( V_27 , V_98 , V_2 , V_3 + 4 , 4 , V_18 ) ;
F_6 ( V_27 , L_13 , F_36 ( V_2 , V_3 + 4 ) , F_2 ( V_2 , V_3 + 2 ) ) ;
break;
case 2 :
if ( V_33 < 20 )
break;
F_5 ( V_27 , V_99 , V_2 , V_3 + 4 , 16 , V_15 ) ;
break;
}
break;
case V_100 :
F_5 ( V_27 , V_101 , V_2 , V_3 , V_33 , V_102 | V_15 ) ;
F_6 ( V_27 , L_14 , F_37 ( F_24 () , V_2 , V_3 , V_33 ) ) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 ,
V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_95 , V_2 , V_3 , 1 , V_18 ) ;
if ( V_33 < 2 )
break;
F_5 ( V_27 , V_96 , V_2 , V_3 + 1 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_97 , V_2 , V_3 + 2 , 2 , V_18 ) ;
switch ( F_35 ( V_2 , V_3 + 1 ) ) {
case 1 :
if ( V_33 < 8 )
break;
F_5 ( V_27 , V_98 , V_2 , V_3 + 4 , 4 , V_18 ) ;
F_6 ( V_27 , L_15 , F_36 ( V_2 , V_3 + 4 ) , F_2 ( V_2 , V_3 + 2 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_16 ,
F_25 ( V_32 , V_83 , L_4 ) ,
F_36 ( V_2 , V_3 + 4 ) ,
F_2 ( V_2 , V_3 + 2 )
) ;
break;
case 2 :
if ( V_33 < 20 )
break;
F_5 ( V_27 , V_99 , V_2 , V_3 + 4 , 16 , V_15 ) ;
break;
}
break;
case V_108 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_109 , V_2 , V_3 , 4 , V_18 ) ;
F_5 ( V_27 , V_110 , V_2 , V_3 , 4 , V_18 ) ;
break;
case V_111 :
F_5 ( V_27 , V_112 , V_2 , V_3 , V_33 , V_102 | V_15 ) ;
F_6 ( V_27 , L_17 , F_37 ( F_24 () , V_2 , V_3 , V_33 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_18 ,
F_37 ( F_24 () , V_2 , V_3 , V_33 )
) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 ,
V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_113 :
if ( V_33 < 20 )
break;
F_5 ( V_27 , V_114 , V_2 , V_3 , V_33 , V_15 ) ;
break;
case V_115 :
if ( V_33 < 2 )
break;
F_5 ( V_27 , V_95 , V_2 , V_3 , 2 , V_18 ) ;
if ( V_33 < 3 )
break;
F_5 ( V_27 , V_116 , V_2 , V_3 + 2 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_117 , V_2 , V_3 + 3 , 1 , V_18 ) ;
{
int V_118 = F_35 ( V_2 , V_3 + 2 ) * 100 + F_35 ( V_2 , V_3 + 3 ) ;
F_6 (
V_27 ,
L_19 ,
V_118 ,
F_25 ( V_118 , V_119 , L_20 )
) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_21 ,
V_118 ,
F_25 ( V_118 , V_119 , L_20 )
) ;
}
if ( V_33 < 5 )
break;
F_5 ( V_27 , V_120 , V_2 , V_3 + 4 , V_33 - 4 , V_102 | V_15 ) ;
F_6 ( V_27 , L_17 , F_37 ( F_24 () , V_2 , V_3 + 4 , V_33 - 4 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_22 ,
F_37 ( F_24 () , V_2 , V_3 + 4 , V_33 - 4 )
) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_121 :
for ( V_34 = 0 ; V_34 < V_33 ; V_34 += 2 )
F_5 ( V_27 , V_122 , V_2 , V_3 + V_34 , 2 , V_18 ) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_123 :
F_5 ( V_27 , V_124 , V_2 , V_3 , V_33 , V_102 | V_15 ) ;
F_6 ( V_27 , L_17 , F_37 ( F_24 () , V_2 , V_3 , V_33 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_23 ,
F_37 ( F_24 () , V_2 , V_3 , V_33 )
) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_125 :
F_5 ( V_27 , V_126 , V_2 , V_3 , V_33 , V_102 | V_15 ) ;
F_6 ( V_27 , L_17 , F_37 ( F_24 () , V_2 , V_3 , V_33 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_24
) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_95 , V_2 , V_3 , 1 , V_18 ) ;
if ( V_33 < 2 )
break;
F_5 ( V_27 , V_96 , V_2 , V_3 + 1 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_132 , V_2 , V_3 + 2 , 2 , V_15 ) ;
V_12 = F_27 ( V_27 , V_97 , V_2 , V_3 + 2 , 2 ,
F_2 ( V_2 , V_3 + 2 ) ^ ( V_35 >> 16 ) ) ;
F_28 ( V_12 ) ;
if ( V_33 < 8 )
break;
switch ( F_35 ( V_2 , V_3 + 1 ) ) {
case 1 :
F_5 ( V_27 , V_133 , V_2 , V_3 + 4 , 4 , V_15 ) ;
V_12 = F_39 ( V_27 , V_98 , V_2 , V_3 + 4 , 4 ,
F_40 ( V_2 , V_3 + 4 ) ^ F_41 ( V_35 ) ) ;
F_28 ( V_12 ) ;
{
const T_17 * V_134 ;
T_15 V_135 ;
T_5 V_136 ;
V_135 = F_40 ( V_2 , V_3 + 4 ) ^ F_41 ( V_35 ) ;
V_134 = F_42 ( ( V_137 * ) & V_135 ) ;
V_136 = F_2 ( V_2 , V_3 + 2 ) ^ ( V_35 >> 16 ) ;
F_6 ( V_27 , L_15 , V_134 , V_136 ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_16 ,
F_25 ( V_32 , V_83 , L_4 ) ,
V_134 ,
V_136
) ;
}
break;
case 2 :
if ( V_33 < 20 )
break;
F_5 ( V_27 , V_138 , V_2 , V_3 + 4 , 16 , V_15 ) ;
{
T_15 V_139 [ 4 ] ;
F_43 ( V_2 , V_3 + 4 , (struct V_140 * ) V_139 ) ;
V_139 [ 0 ] = V_139 [ 0 ] ^ F_41 ( V_35 ) ;
V_139 [ 1 ] = V_139 [ 1 ] ^ F_41 ( V_40 [ 0 ] ) ;
V_139 [ 2 ] = V_139 [ 2 ] ^ F_41 ( V_40 [ 1 ] ) ;
V_139 [ 3 ] = V_139 [ 3 ] ^ F_41 ( V_40 [ 2 ] ) ;
V_12 = F_44 ( V_27 , V_99 , V_2 , V_3 + 4 , 16 ,
( const V_137 * ) V_139 ) ;
F_28 ( V_12 ) ;
}
break;
}
break;
case V_141 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_96 , V_2 , V_3 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_95 , V_2 , V_3 + 1 , 3 , V_18 ) ;
break;
case V_142 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_143 , V_2 , V_3 , 1 , V_18 ) ;
break;
case V_144 :
if ( V_33 < 8 )
break;
F_5 ( V_27 , V_145 , V_2 , V_3 , 8 , V_15 ) ;
break;
case V_146 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_147 , V_2 , V_3 , 4 , V_18 ) ;
break;
case V_148 :
F_27 ( V_27 , V_103 , V_2 , V_3 , V_33 , V_33 ) ;
break;
case V_149 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_150 , V_2 , V_3 , 1 , V_18 ) ;
F_5 ( V_27 , V_151 , V_2 , V_3 + 1 , 1 , V_18 ) ;
break;
case V_152 :
F_5 ( V_27 , V_153 , V_2 , V_3 , V_33 , V_102 | V_15 ) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
case V_154 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_155 , V_2 , V_3 , 4 , V_18 ) ;
break;
case V_156 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_157 , V_2 , V_3 , V_33 , V_18 ) ;
break;
case V_158 :
case V_159 :
if ( V_33 < 8 )
break;
F_5 ( V_27 , V_160 , V_2 , V_3 , 8 , V_15 ) ;
break;
case V_161 :
if ( V_33 > 0 ) {
T_4 * V_8 ;
F_5 ( V_27 , V_162 , V_2 , V_3 , V_33 , V_15 ) ;
if ( V_33 % 4 != 0 ) {
T_1 V_163 ;
V_163 = 4 - ( V_33 % 4 ) ;
F_27 ( V_27 , V_103 , V_2 , V_3 + V_33 , V_163 , V_163 ) ;
}
V_8 = F_45 ( V_2 , V_3 , V_33 , V_33 ) ;
if ( ! F_9 ( V_20 , V_8 , T_3 , V_27 , NULL ) ) {
F_10 ( V_21 , V_8 , T_3 , V_27 , NULL ) ;
}
}
break;
case V_164 :
if ( V_33 < 1 )
break;
F_5 ( V_27 , V_165 , V_2 , V_3 , 1 , V_18 ) ;
if ( V_33 < 4 )
break;
{
V_137 V_166 = F_35 ( V_2 , V_3 ) ;
F_6 ( V_27 , L_17 , F_33 ( V_166 , V_167 , L_25 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_22 ,
F_33 ( V_166 , V_167 , L_25 )
) ;
}
F_5 ( V_27 , V_95 , V_2 , V_3 + 1 , 3 , V_18 ) ;
break;
case V_168 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_169 , V_2 , V_3 , 2 , V_18 ) ;
{
T_5 V_170 = F_2 ( V_2 , V_3 ) ;
F_6 ( V_27 , L_26 , V_170 ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_27 ,
V_170
) ;
}
F_5 ( V_27 , V_95 , V_2 , V_3 + 2 , 2 , V_18 ) ;
break;
case V_171 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_172 , V_2 , V_3 , 4 , V_18 ) ;
F_6 ( V_27 , L_28 , F_15 ( V_2 , V_3 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_29 ,
F_15 ( V_2 , V_3 )
) ;
break;
case V_173 :
if ( V_33 < 4 )
break;
F_5 ( V_27 , V_174 , V_2 , V_3 , 4 , V_18 ) ;
F_6 ( V_27 , L_28 , F_15 ( V_2 , V_3 ) ) ;
F_38 (
T_3 -> V_9 , V_11 ,
L_30 ,
F_15 ( V_2 , V_3 )
) ;
break;
default:
if ( V_33 > 0 )
F_5 ( V_27 , V_162 , V_2 , V_3 , V_33 , V_15 ) ;
if ( V_33 % 4 != 0 )
F_27 ( V_27 , V_103 , V_2 ,
V_3 + V_33 , 4 - ( V_33 % 4 ) , 4 - ( V_33 % 4 ) ) ;
break;
}
V_3 += ( V_33 + 3 ) & ~ 0x3 ;
}
}
return F_11 ( V_2 ) ;
}
static int
F_46 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , void * T_18 V_1 )
{
return F_12 ( V_2 , T_3 , V_7 , FALSE ) ;
}
static void
F_47 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 )
{
F_12 ( V_2 , T_3 , V_7 , FALSE ) ;
}
static void
F_48 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 )
{
F_49 ( V_2 , T_3 , V_7 , TRUE , V_41 ,
F_1 , F_47 ) ;
}
static T_10
F_50 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_7 , void * T_18 V_1 )
{
if ( F_12 ( V_2 , T_3 , V_7 , TRUE ) == 0 ) {
return FALSE ;
}
return TRUE ;
}
void
F_51 ( void )
{
static T_19 V_175 [] = {
{ & V_17 ,
{ L_31 , L_32 , V_176 ,
V_177 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_71 ,
{ L_33 , L_34 , V_176 ,
V_177 , NULL , 0 , NULL , V_178 }
} ,
{ & V_73 ,
{ L_35 , L_36 , V_176 ,
V_177 , NULL , 0x0110 , NULL , V_178 }
} ,
{ & V_74 ,
{ L_37 , L_38 , V_176 ,
V_177 , NULL , 0x3EEF , NULL , V_178 }
} ,
{ & V_75 ,
{ L_39 , L_40 , V_176 ,
V_177 , NULL , 0x2000 , NULL , V_178 }
} ,
{ & V_19 ,
{ L_41 , L_42 , V_176 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_77 ,
{ L_43 , L_44 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_78 ,
{ L_45 , L_46 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_79 ,
{ L_47 , L_48 , V_182 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_81 ,
{ L_49 , L_50 , V_176 ,
V_177 , NULL , 0 , NULL , V_178 }
} ,
{ & V_65 ,
{ L_51 , L_52 , V_183 ,
V_181 , NULL , 0x0 , L_53 , V_178 }
} ,
{ & V_69 ,
{ L_54 , L_55 , V_183 ,
V_181 , NULL , 0x0 , L_56 , V_178 }
} ,
{ & V_70 ,
{ L_57 , L_58 , V_184 ,
V_181 , NULL , 0x0 , L_59 , V_178 }
} ,
{ & V_64 ,
{ L_60 , L_61 , V_183 ,
V_181 , NULL , 0x0 , L_62 , V_178 }
} ,
{ & V_85 ,
{ L_49 , L_63 , V_176 ,
V_177 , F_52 ( V_83 ) , 0x0 , NULL , V_178 }
} ,
{ & V_87 ,
{ L_64 , L_65 , V_176 ,
V_177 , NULL , 0x8000 , NULL , V_178 }
} ,
{ & V_89 ,
{ L_66 , L_67 , V_176 ,
V_177 , NULL , 0x4000 , NULL , V_178 }
} ,
{ & V_90 ,
{ L_68 , L_69 , V_176 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_96 ,
{ L_70 , L_71 , V_185 ,
V_177 , F_52 ( V_186 ) , 0x0 , NULL , V_178 }
} ,
{ & V_98 ,
{ L_72 , L_73 , V_187 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_99 ,
{ L_72 , L_74 , V_188 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_97 ,
{ L_75 , L_76 , V_176 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_112 ,
{ L_77 , L_78 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_101 ,
{ L_79 , L_80 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_103 ,
{ L_81 , L_82 , V_176 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_114 ,
{ L_83 , L_84 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_157 ,
{ L_85 , L_86 , V_190 ,
V_177 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_116 ,
{ L_87 , L_88 , V_185 ,
V_179 , NULL , 0x07 , NULL , V_178 }
} ,
{ & V_117 ,
{ L_89 , L_90 , V_185 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_120 ,
{ L_91 , L_92 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_124 ,
{ L_93 , L_94 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_126 ,
{ L_95 , L_96 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_122 ,
{ L_97 , L_98 , V_176 ,
V_177 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_133 ,
{ L_99 , L_100 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_138 ,
{ L_99 , L_101 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_132 ,
{ L_102 , L_103 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_150 ,
{ L_104 , L_105 , V_185 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_151 ,
{ L_106 , L_107 , V_185 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_153 ,
{ L_108 , L_109 , V_189 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_147 ,
{ L_110 , L_111 , V_190 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_160 ,
{ L_112 , L_113 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_174 ,
{ L_114 , L_115 , V_190 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_109 ,
{ L_116 , L_117 , V_191 ,
16 , F_53 ( & V_192 ) , 0x0004 , NULL , V_178 }
} ,
{ & V_110 ,
{ L_118 , L_119 , V_191 ,
16 , F_53 ( & V_192 ) , 0x0002 , NULL , V_178 }
} ,
{ & V_143 ,
{ L_120 , L_121 , V_185 ,
V_179 , F_52 ( V_193 ) , 0x80 , NULL , V_178 }
} ,
{ & V_155 ,
{ L_122 , L_123 , V_190 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_145 ,
{ L_124 , L_125 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_162 ,
{ L_126 , L_127 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_95 ,
{ L_128 , L_129 , V_180 ,
V_181 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_165 ,
{ L_130 , L_131 , V_185 ,
V_177 , F_52 ( V_167 ) , 0x0 , NULL , V_178 }
} ,
{ & V_169 ,
{ L_132 , L_133 , V_176 ,
V_177 , NULL , 0x0 , NULL , V_178 }
} ,
{ & V_172 ,
{ L_134 , L_135 , V_190 ,
V_179 , NULL , 0x0 , NULL , V_178 }
} ,
} ;
static T_20 * V_194 [] = {
& V_16 ,
& V_72 ,
& V_80 ,
& V_84 ,
& V_86 ,
} ;
V_14 = F_54 ( L_136 , L_1 , L_137 ) ;
F_55 ( V_14 , V_175 , F_56 ( V_175 ) ) ;
F_57 ( V_194 , F_56 ( V_194 ) ) ;
F_58 ( L_137 , & V_20 ) ;
F_59 ( L_138 , F_46 , V_14 ) ;
F_59 ( L_139 , F_50 , V_14 ) ;
}
void
F_60 ( void )
{
T_21 V_195 ;
T_21 V_196 ;
V_195 = F_61 ( F_48 , V_14 ) ;
V_196 = F_62 ( F_46 , V_14 ) ;
F_63 ( L_140 , V_197 , V_195 ) ;
F_63 ( L_141 , V_198 , V_196 ) ;
F_64 ( L_140 , V_195 ) ;
F_64 ( L_141 , V_196 ) ;
F_65 ( L_142 , F_50 , V_14 ) ;
V_21 = F_66 ( L_143 ) ;
}
