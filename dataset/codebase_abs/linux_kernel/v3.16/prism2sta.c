static int F_1 ( T_1 * V_1 )
{
return 0 ;
}
static int F_2 ( T_1 * V_1 )
{
return 0 ;
}
static void F_3 ( T_1 * V_1 )
{
}
static int F_4 ( T_1 * V_1 , struct V_2 * V_3 ,
union V_4 * V_4 ,
struct V_5 * V_6 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
int V_9 ;
if ( ( V_1 -> V_10 & ( V_11 | V_12 ) ) ==
V_11 ) {
V_4 -> V_13 . V_14 |= F_5 ( F_6 ( 1 ) ) ;
}
V_9 = F_7 ( V_7 , V_3 , V_4 , V_6 ) ;
return V_9 ;
}
static int F_8 ( T_1 * V_1 , struct V_15 * V_16 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
int V_9 = 0 ;
switch ( V_16 -> V_17 ) {
case V_18 :
F_9 ( L_1 ) ;
V_9 = F_10 ( V_1 , V_16 ) ;
break;
case V_19 :
F_9 ( L_2 ) ;
V_9 = F_10 ( V_1 , V_16 ) ;
break;
case V_20 :
F_9 ( L_3 ) ;
V_9 = F_11 ( V_1 , V_16 ) ;
break;
case V_21 :
F_9 ( L_4 ) ;
V_9 = F_12 ( V_1 , V_16 ) ;
break;
case V_22 :
F_9 ( L_5 ) ;
V_9 = F_13 ( V_1 , V_16 ) ;
break;
case V_23 :
F_9 ( L_6 ) ;
V_9 = F_14 ( V_1 , V_16 ) ;
break;
case V_24 :
F_9 ( L_7 ) ;
V_9 = F_15 ( V_1 , V_16 ) ;
break;
case V_25 :
F_9 ( L_8 ) ;
V_9 = F_16 ( V_1 , V_16 ) ;
break;
case V_26 :
F_9 ( L_9 ) ;
V_9 = F_17 ( V_1 , V_16 ) ;
break;
case V_27 :
F_9 ( L_10 ) ;
V_9 = F_18 ( V_1 , V_16 ) ;
break;
case V_28 :
break;
case V_29 :
{
struct V_30 * V_31 ;
F_9 ( L_11 ) ;
V_31 = (struct V_30 * ) V_16 ;
V_9 =
F_19 ( V_1 ,
V_31 -> V_32 . V_33 ) ;
V_31 -> V_34 . V_35 =
V_36 ;
V_31 -> V_34 . V_33 = V_9 ;
V_9 = 0 ;
}
break;
case V_37 :
F_9 ( L_12 ) ;
V_9 = F_20 ( V_1 , V_16 ) ;
break;
case V_38 :
F_9 ( L_13 ) ;
V_9 = F_21 ( V_1 , V_16 ) ;
break;
case V_39 : {
struct V_40 * V_41 ;
F_9 ( L_14 ) ;
V_41 = (struct V_40 * ) V_16 ;
V_41 -> V_42 . V_35 =
V_36 ;
V_41 -> V_43 . V_35 =
V_36 ;
V_41 -> V_44 . V_35 =
V_36 ;
V_41 -> V_42 . V_33 = F_22 ( V_7 -> V_45 . V_46 ) ;
V_41 -> V_43 . V_33 = F_22 ( V_7 -> V_45 . V_47 ) ;
V_41 -> V_44 . V_33 = F_22 ( V_7 -> V_45 . V_48 ) ;
V_41 -> V_49 . V_33 = V_7 -> V_49 ;
break;
}
default:
F_23 ( V_1 -> V_50 ,
L_15 ,
V_16 -> V_17 ) ;
break;
}
return V_9 ;
}
T_3 F_19 ( T_1 * V_1 , T_3 V_32 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_3 V_9 ;
V_9 = V_51 ;
F_9 ( L_16 ,
V_1 -> V_52 , V_32 ) ;
switch ( V_32 ) {
case V_53 :
switch ( V_1 -> V_52 ) {
case V_54 :
V_1 -> V_52 = V_55 ;
V_9 = F_24 ( V_7 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 ,
L_17 , ( int ) V_9 ) ;
V_9 =
V_51 ;
V_1 -> V_52 = V_54 ;
break;
}
V_1 -> V_52 = V_56 ;
V_9 = V_57 ;
break;
case V_56 :
F_26 ( V_7 ) ;
V_9 = V_57 ;
break;
case V_58 :
F_23 ( V_1 -> V_50 ,
L_18
L_19 ) ;
V_9 = V_59 ;
break;
case V_60 :
default:
V_9 = V_51 ;
break;
}
break;
case V_61 :
switch ( V_1 -> V_52 ) {
case V_54 :
case V_56 :
V_1 -> V_52 = V_62 ;
V_9 = F_24 ( V_7 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 ,
L_17 , ( int ) V_9 ) ;
V_9 =
V_51 ;
V_1 -> V_52 = V_54 ;
break;
}
V_9 = F_27 ( V_1 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 ,
L_20 , ( int ) V_9 ) ;
V_9 =
V_51 ;
F_28 ( V_7 ) ;
V_1 -> V_52 = V_54 ;
break;
}
V_9 = F_29 ( V_1 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 ,
L_21 , ( int ) V_9 ) ;
V_9 =
V_51 ;
F_28 ( V_7 ) ;
V_1 -> V_52 = V_54 ;
break;
}
V_1 -> V_52 = V_58 ;
V_7 -> V_63 = 0 ;
V_7 -> V_64 = 60 ;
V_9 = V_57 ;
break;
case V_58 :
V_9 = V_57 ;
break;
case V_60 :
default:
V_9 = V_51 ;
break;
}
break;
case V_65 :
switch ( V_1 -> V_52 ) {
case V_54 :
V_9 = V_57 ;
break;
case V_56 :
case V_58 :
V_1 -> V_52 = V_66 ;
if ( ! V_1 -> V_67 )
F_30 ( V_1 -> V_50 ) ;
F_28 ( V_7 ) ;
V_1 -> V_68 = V_69 ;
V_1 -> V_52 = V_54 ;
V_9 = V_57 ;
break;
case V_60 :
default:
V_9 = V_51 ;
break;
}
break;
default:
V_9 = V_59 ;
break;
}
return V_9 ;
}
static int F_27 ( T_1 * V_1 )
{
int V_9 = 0 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_4 V_70 ;
T_5 V_71 [ V_72 ] ;
char V_73 [ ( V_72 * 4 ) + 1 ] ;
V_9 = F_31 ( V_7 , V_74 ,
& V_7 -> V_75 ,
sizeof( V_76 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_22 ) ;
goto V_77;
}
V_7 -> V_75 . V_78 = F_22 ( V_7 -> V_75 . V_78 ) ;
V_7 -> V_75 . V_79 = F_22 ( V_7 -> V_75 . V_79 ) ;
V_7 -> V_75 . V_80 = F_22 ( V_7 -> V_75 . V_80 ) ;
V_7 -> V_75 . V_81 = F_22 ( V_7 -> V_75 . V_81 ) ;
F_32 ( V_1 -> V_50 , L_23 ,
V_7 -> V_75 . V_78 , V_7 -> V_75 . V_80 ,
V_7 -> V_75 . V_81 , V_7 -> V_75 . V_79 ) ;
V_9 = F_31 ( V_7 , V_82 ,
& V_7 -> V_83 ,
sizeof( V_76 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_24 ) ;
goto V_77;
}
V_7 -> V_83 . V_78 = F_22 ( V_7 -> V_83 . V_78 ) ;
V_7 -> V_83 . V_79 = F_22 ( V_7 -> V_83 . V_79 ) ;
V_7 -> V_83 . V_80 = F_22 ( V_7 -> V_83 . V_80 ) ;
V_7 -> V_83 . V_81 = F_22 ( V_7 -> V_83 . V_81 ) ;
F_32 ( V_1 -> V_50 , L_25 ,
V_7 -> V_83 . V_78 , V_7 -> V_83 . V_80 ,
V_7 -> V_83 . V_81 , V_7 -> V_83 . V_79 ) ;
V_9 = F_31 ( V_7 , V_84 ,
& V_7 -> V_85 ,
sizeof( V_76 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_26 ) ;
goto V_77;
}
if ( V_7 -> V_75 . V_78 < 0x8000 ) {
F_25 ( V_1 -> V_50 ,
L_27 ) ;
V_9 = - 1 ;
goto V_77;
}
V_7 -> V_85 . V_78 = F_22 ( V_7 -> V_85 . V_78 ) ;
V_7 -> V_85 . V_79 = F_22 ( V_7 -> V_85 . V_79 ) ;
V_7 -> V_85 . V_80 = F_22 ( V_7 -> V_85 . V_80 ) ;
V_7 -> V_85 . V_81 = F_22 ( V_7 -> V_85 . V_81 ) ;
V_7 -> V_86 = V_7 -> V_85 . V_79 & ( F_33 ( 14 ) | F_33 ( 15 ) ) ;
V_7 -> V_85 . V_79 &= ~ ( ( T_4 ) ( F_33 ( 14 ) | F_33 ( 15 ) ) ) ;
if ( V_7 -> V_85 . V_78 == 0x1f ) {
F_32 ( V_1 -> V_50 ,
L_28 ,
V_7 -> V_85 . V_78 , V_7 -> V_85 . V_80 ,
V_7 -> V_85 . V_81 , V_7 -> V_85 . V_79 ) ;
} else {
F_32 ( V_1 -> V_50 ,
L_29 ,
V_7 -> V_85 . V_78 , V_7 -> V_85 . V_80 ,
V_7 -> V_85 . V_81 , V_7 -> V_85 . V_79 ) ;
F_25 ( V_1 -> V_50 , L_30 ) ;
goto V_77;
}
V_9 = F_31 ( V_7 , V_87 ,
& V_7 -> V_88 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_31 ) ;
goto V_77;
}
V_7 -> V_88 . V_90 = F_22 ( V_7 -> V_88 . V_90 ) ;
V_7 -> V_88 . V_78 = F_22 ( V_7 -> V_88 . V_78 ) ;
V_7 -> V_88 . V_79 = F_22 ( V_7 -> V_88 . V_79 ) ;
V_7 -> V_88 . V_91 = F_22 ( V_7 -> V_88 . V_91 ) ;
V_7 -> V_88 . V_92 = F_22 ( V_7 -> V_88 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_32 ,
V_7 -> V_88 . V_90 , V_7 -> V_88 . V_78 ,
V_7 -> V_88 . V_79 , V_7 -> V_88 . V_91 ,
V_7 -> V_88 . V_92 ) ;
V_9 = F_31 ( V_7 , V_93 ,
& V_7 -> V_94 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_33 ) ;
goto V_77;
}
V_7 -> V_94 . V_90 = F_22 ( V_7 -> V_94 . V_90 ) ;
V_7 -> V_94 . V_78 = F_22 ( V_7 -> V_94 . V_78 ) ;
V_7 -> V_94 . V_79 = F_22 ( V_7 -> V_94 . V_79 ) ;
V_7 -> V_94 . V_91 = F_22 ( V_7 -> V_94 . V_91 ) ;
V_7 -> V_94 . V_92 = F_22 ( V_7 -> V_94 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_34 ,
V_7 -> V_94 . V_90 , V_7 -> V_94 . V_78 ,
V_7 -> V_94 . V_79 , V_7 -> V_94 . V_91 ,
V_7 -> V_94 . V_92 ) ;
V_9 = F_31 ( V_7 , V_95 ,
& V_7 -> V_96 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_35 ) ;
goto V_77;
}
V_7 -> V_96 . V_90 = F_22 ( V_7 -> V_96 . V_90 ) ;
V_7 -> V_96 . V_78 = F_22 ( V_7 -> V_96 . V_78 ) ;
V_7 -> V_96 . V_79 = F_22 ( V_7 -> V_96 . V_79 ) ;
V_7 -> V_96 . V_91 = F_22 ( V_7 -> V_96 . V_91 ) ;
V_7 -> V_96 . V_92 = F_22 ( V_7 -> V_96 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_36 ,
V_7 -> V_96 . V_90 , V_7 -> V_96 . V_78 ,
V_7 -> V_96 . V_79 , V_7 -> V_96 . V_91 ,
V_7 -> V_96 . V_92 ) ;
V_9 = F_31 ( V_7 , V_97 ,
& V_7 -> V_98 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_37 ) ;
goto V_77;
}
V_7 -> V_98 . V_90 = F_22 ( V_7 -> V_98 . V_90 ) ;
V_7 -> V_98 . V_78 = F_22 ( V_7 -> V_98 . V_78 ) ;
V_7 -> V_98 . V_79 = F_22 ( V_7 -> V_98 . V_79 ) ;
V_7 -> V_98 . V_91 = F_22 ( V_7 -> V_98 . V_91 ) ;
V_7 -> V_98 . V_92 = F_22 ( V_7 -> V_98 . V_92 ) ;
if ( V_7 -> V_98 . V_78 == 0x04 ) {
F_32 ( V_1 -> V_50 ,
L_38 ,
V_7 -> V_98 . V_90 , V_7 -> V_98 . V_78 ,
V_7 -> V_98 . V_79 , V_7 -> V_98 . V_91 ,
V_7 -> V_98 . V_92 ) ;
} else {
F_32 ( V_1 -> V_50 ,
L_39 ,
V_7 -> V_98 . V_90 , V_7 -> V_98 . V_78 ,
V_7 -> V_98 . V_79 , V_7 -> V_98 . V_91 ,
V_7 -> V_98 . V_92 ) ;
}
V_9 = F_31 ( V_7 , V_99 ,
& V_7 -> V_100 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_40 ) ;
goto V_77;
}
V_7 -> V_100 . V_90 = F_22 ( V_7 -> V_100 . V_90 ) ;
V_7 -> V_100 . V_78 = F_22 ( V_7 -> V_100 . V_78 ) ;
V_7 -> V_100 . V_79 = F_22 ( V_7 -> V_100 . V_79 ) ;
V_7 -> V_100 . V_91 = F_22 ( V_7 -> V_100 . V_91 ) ;
V_7 -> V_100 . V_92 = F_22 ( V_7 -> V_100 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_41 ,
V_7 -> V_100 . V_90 , V_7 -> V_100 . V_78 ,
V_7 -> V_100 . V_79 , V_7 -> V_100 . V_91 ,
V_7 -> V_100 . V_92 ) ;
V_9 = F_31 ( V_7 , V_101 ,
& V_7 -> V_102 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_42 ) ;
goto V_77;
}
V_7 -> V_102 . V_90 = F_22 ( V_7 -> V_102 . V_90 ) ;
V_7 -> V_102 . V_78 = F_22 ( V_7 -> V_102 . V_78 ) ;
V_7 -> V_102 . V_79 = F_22 ( V_7 -> V_102 . V_79 ) ;
V_7 -> V_102 . V_91 = F_22 ( V_7 -> V_102 . V_91 ) ;
V_7 -> V_102 . V_92 = F_22 ( V_7 -> V_102 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_43 ,
V_7 -> V_102 . V_90 , V_7 -> V_102 . V_78 ,
V_7 -> V_102 . V_79 , V_7 -> V_102 . V_91 ,
V_7 -> V_102 . V_92 ) ;
V_9 = F_31 ( V_7 , V_103 ,
& V_7 -> V_104 ,
sizeof( V_89 ) ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_44 ) ;
goto V_77;
}
V_7 -> V_104 . V_90 = F_22 ( V_7 -> V_104 . V_90 ) ;
V_7 -> V_104 . V_78 = F_22 ( V_7 -> V_104 . V_78 ) ;
V_7 -> V_104 . V_79 = F_22 ( V_7 -> V_104 . V_79 ) ;
V_7 -> V_104 . V_91 = F_22 ( V_7 -> V_104 . V_91 ) ;
V_7 -> V_104 . V_92 = F_22 ( V_7 -> V_104 . V_92 ) ;
F_32 ( V_1 -> V_50 ,
L_45 ,
V_7 -> V_104 . V_90 , V_7 -> V_104 . V_78 ,
V_7 -> V_104 . V_79 , V_7 -> V_104 . V_91 ,
V_7 -> V_104 . V_92 ) ;
V_9 = F_31 ( V_7 , V_105 ,
V_71 , V_72 ) ;
if ( ! V_9 ) {
F_34 ( V_71 , V_72 ,
V_73 , sizeof( V_73 ) ) ;
F_32 ( V_1 -> V_50 , L_46 , V_73 ) ;
} else {
F_25 ( V_1 -> V_50 , L_47 ) ;
goto V_77;
}
V_9 = F_31 ( V_7 , V_106 ,
V_1 -> V_50 -> V_107 , V_108 ) ;
if ( V_9 != 0 ) {
F_25 ( V_1 -> V_50 , L_48 ) ;
goto V_77;
}
V_1 -> V_109 |= V_110 ;
F_35 ( V_7 , V_111 , & V_70 ) ;
if ( V_70 )
V_1 -> V_109 |= V_112 ;
F_35 ( V_7 , V_113 , & V_70 ) ;
V_7 -> V_114 = V_70 ;
if ( F_36 ( V_7 -> V_85 . V_80 ,
V_7 -> V_85 . V_81 ,
V_7 -> V_85 . V_79 ) <
F_36 ( 1 , 5 , 5 ) ) {
V_1 -> V_109 |= V_115 ;
}
goto V_116;
V_77:
F_25 ( V_1 -> V_50 , L_49 , V_9 ) ;
V_116:
return V_9 ;
}
static int F_29 ( T_1 * V_1 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
return F_37 ( V_7 , V_117 ,
V_118 ) ;
}
static int F_38 ( T_1 * V_1 , T_6 * V_119 )
{
int V_9 = 0 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_4 V_120 ;
if ( V_7 -> V_121 != V_122 )
goto exit;
if ( ( V_119 -> V_123 & ( V_124 | V_125 ) ) != 0 )
V_120 = V_126 ;
else
V_120 = V_127 ;
V_9 =
F_39 ( V_7 , V_128 ,
V_120 ) ;
exit:
return V_9 ;
}
static void F_40 ( T_1 * V_1 ,
T_7 * V_129 )
{
F_9 ( L_50 ) ;
}
static void F_41 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_4 * V_130 ;
T_3 * V_131 ;
T_3 * V_132 ;
int V_133 ;
int V_134 ;
V_134 = sizeof( V_135 ) / sizeof( T_3 ) ;
if ( V_129 -> V_136 > 22 ) {
V_131 = ( T_3 * ) & V_7 -> V_137 ;
V_132 = ( T_3 * ) & V_129 -> V_138 . V_139 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ , V_131 ++ , V_132 ++ )
* V_131 += F_42 ( * V_132 ) ;
} else {
V_131 = ( T_3 * ) & V_7 -> V_137 ;
V_130 = ( T_4 * ) & V_129 -> V_138 . V_140 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ , V_131 ++ , V_130 ++ )
* V_131 += F_22 ( * V_130 ) ;
}
}
static void F_43 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
int V_141 ;
T_8 * V_142 = & ( V_129 -> V_138 . V_143 ) ;
int V_133 ;
T_9 V_144 ;
int V_9 ;
V_141 = ( V_129 -> V_136 * sizeof( T_4 ) ) -
sizeof( V_129 -> V_145 ) - sizeof( V_129 -> V_138 . V_143 . V_146 ) ;
V_141 /= sizeof( V_147 ) ;
F_9 ( L_51 ,
V_129 -> V_138 . V_143 . V_146 , V_141 ) ;
for ( V_133 = 0 ; V_133 < V_141 ; V_133 ++ ) {
F_9 ( L_52 ,
V_142 -> V_9 [ V_133 ] . V_148 ,
V_142 -> V_9 [ V_133 ] . V_149 ,
V_142 -> V_9 [ V_133 ] . V_150 , V_142 -> V_9 [ V_133 ] . V_151 ) ;
F_9 ( L_53 ,
V_142 -> V_9 [ V_133 ] . V_152 , V_142 -> V_9 [ V_133 ] . V_153 ) ;
}
V_144 . V_154 = V_142 -> V_9 [ 0 ] . V_148 ;
memcpy ( V_144 . V_155 , V_142 -> V_9 [ 0 ] . V_155 , V_156 ) ;
V_9 = F_44 ( V_7 ,
V_157 ,
& V_144 , V_158 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_54 ,
V_9 ) ;
}
}
static void F_45 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
int V_141 ;
V_141 = ( V_129 -> V_136 - 3 ) / 32 ;
F_9 ( L_55 , V_141 ) ;
if ( V_141 > 32 )
V_141 = 32 ;
F_46 ( V_7 -> V_159 ) ;
V_7 -> V_159 = F_47 ( V_129 , sizeof( T_7 ) , V_160 ) ;
if ( V_141 == 0 )
V_141 = - 1 ;
V_7 -> V_161 = V_141 ;
F_48 ( & V_7 -> V_162 ) ;
}
static void F_49 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
unsigned int V_133 , V_163 ;
V_7 -> V_164 . V_165 . V_166 =
F_22 ( V_129 -> V_138 . V_167 . V_166 ) ;
for ( V_133 = 0 , V_163 = 0 ; V_133 < V_168 ; V_133 ++ ) {
T_10 * V_9 ;
T_10 * V_167 ;
int V_169 ;
if ( ! ( V_7 -> V_164 . V_165 . V_166 & ( 1 << V_133 ) ) )
continue;
V_9 = & V_129 -> V_138 . V_167 . V_9 [ V_163 ] ;
V_169 = F_22 ( V_9 -> V_148 ) - 1 ;
if ( V_169 < 0 || V_169 >= V_168 )
continue;
V_167 = & V_7 -> V_164 . V_165 . V_9 [ V_169 ] ;
V_167 -> V_148 = V_169 ;
V_167 -> V_149 = F_22 ( V_9 -> V_149 ) ;
V_167 -> V_170 = F_22 ( V_9 -> V_170 ) ;
V_167 -> V_171 = F_22 ( V_9 -> V_171 ) ;
F_9 ( L_56 ,
V_169 + 1 ,
( V_167 -> V_171 & V_172 )
? L_57 : L_58 ,
V_167 -> V_149 , V_167 -> V_170 ,
( V_167 -> V_171 & V_173 )
? 1 : 0 ) ;
V_163 ++ ;
}
F_50 ( & V_7 -> V_164 . V_116 , 2 ) ;
V_7 -> V_164 . V_174 = V_163 ;
}
void F_51 ( struct V_175 * V_33 )
{
T_2 * V_7 = F_52 ( V_33 , struct V_176 , V_177 ) ;
T_1 * V_1 = V_7 -> V_1 ;
T_11 V_178 ;
int V_9 ;
{
struct V_2 * V_3 ;
T_7 * V_129 ;
while ( ( V_3 = F_53 ( & V_7 -> V_179 ) ) ) {
V_129 = ( T_7 * ) V_3 -> V_33 ;
F_54 ( V_1 , V_129 ) ;
}
}
if ( V_7 -> V_180 == V_7 -> V_181 )
return;
V_7 -> V_180 = V_7 -> V_181 ;
switch ( V_7 -> V_180 ) {
case V_182 :
F_30 ( V_1 -> V_50 ) ;
F_32 ( V_1 -> V_50 , L_59 ) ;
break;
case V_183 :
F_55 ( V_1 -> V_50 ) ;
if ( V_7 -> V_63 == 1 )
V_7 -> V_63 = 2 ;
V_7 -> V_64 = 60 ;
if ( V_1 -> V_50 -> type == V_184 ) {
T_4 V_185 ;
F_32 ( V_1 -> V_50 , L_60 ) ;
V_9 = F_31 ( V_7 ,
V_186 ,
V_1 -> V_155 ,
V_156 ) ;
if ( V_9 ) {
F_9
( L_61 ,
V_186 , V_9 ) ;
return;
}
V_9 = F_31 ( V_7 ,
V_187 ,
& V_178 , sizeof( V_178 ) ) ;
if ( V_9 ) {
F_9
( L_61 ,
V_187 , V_9 ) ;
return;
}
F_56 ( (struct V_188 * ) & V_178 ,
( V_189 * ) &
V_1 -> V_178 ) ;
V_9 = F_35 ( V_7 ,
V_190 ,
& V_185 ) ;
if ( V_9 ) {
F_9
( L_61 ,
V_190 , V_9 ) ;
return;
}
V_1 -> V_68 =
( V_185 == V_191 ) ?
V_192 : V_193 ;
F_57 ( V_1 , V_127 ) ;
F_58 ( & V_7 -> V_194 ) ;
}
break;
case V_195 :
if ( V_1 -> V_50 -> type == V_184 )
F_32 ( V_1 -> V_50 ,
L_62 ) ;
V_1 -> V_68 = V_69 ;
F_30 ( V_1 -> V_50 ) ;
F_59 ( V_1 ) ;
break;
case V_196 :
F_32 ( V_1 -> V_50 , L_63 ) ;
V_9 = F_31 ( V_7 ,
V_186 ,
V_1 -> V_155 , V_156 ) ;
if ( V_9 ) {
F_9 ( L_61 ,
V_186 , V_9 ) ;
return;
}
V_9 = F_31 ( V_7 ,
V_187 ,
& V_178 , sizeof( V_178 ) ) ;
if ( V_9 ) {
F_9 ( L_61 ,
V_187 , V_9 ) ;
return;
}
F_56 ( (struct V_188 * ) & V_178 ,
( V_189 * ) & V_1 -> V_178 ) ;
V_7 -> V_180 = V_183 ;
F_55 ( V_1 -> V_50 ) ;
F_60 ( V_1 ) ;
break;
case V_197 :
F_32 ( V_1 -> V_50 , L_64 ) ;
F_30 ( V_1 -> V_50 ) ;
break;
case V_198 :
F_32 ( V_1 -> V_50 , L_65 ) ;
V_7 -> V_180 = V_183 ;
F_55 ( V_1 -> V_50 ) ;
break;
case V_199 :
if ( V_7 -> V_63 && -- V_7 -> V_64 > 0 ) {
T_9 V_144 ;
V_144 = V_7 -> V_144 ;
F_44 ( V_7 ,
V_157 ,
& V_144 ,
V_158 ) ;
F_32 ( V_1 -> V_50 ,
L_66 ) ;
} else {
F_32 ( V_1 -> V_50 , L_67 ) ;
}
F_30 ( V_1 -> V_50 ) ;
F_57 ( V_1 , V_126 ) ;
break;
default:
F_23 ( V_1 -> V_50 ,
L_68 , V_7 -> V_180 ) ;
return;
}
V_1 -> V_200 = ( V_7 -> V_180 == V_183 ) ;
}
static void F_61 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_7 -> V_181 = F_22 ( V_129 -> V_138 . V_200 . V_200 ) ;
F_62 ( & V_7 -> V_177 ) ;
}
static void F_63 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_12 V_201 ;
int V_133 ;
memcpy ( & V_201 , & V_129 -> V_138 . V_202 , sizeof( V_201 ) ) ;
V_201 . V_202 = F_22 ( V_201 . V_202 ) ;
V_201 . V_203 = F_22 ( V_201 . V_203 ) ;
for ( V_133 = 0 ; V_133 < V_7 -> V_204 . V_134 ; V_133 ++ )
if ( memcmp ( V_201 . V_205 , V_7 -> V_204 . V_206 [ V_133 ] , V_108 ) == 0 )
break;
if ( V_133 >= V_7 -> V_204 . V_134 ) {
if ( V_201 . V_202 != V_207 )
F_23 ( V_1 -> V_50 ,
L_69 ) ;
} else {
V_7 -> V_204 . V_208 [ V_133 ] =
( V_201 . V_202 == V_209 ||
V_201 . V_202 == V_210 ) ;
if ( V_201 . V_202 == V_207 )
F_23 ( V_1 -> V_50 ,
L_70 ) ;
}
}
static void F_64 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
struct V_2 * V_3 ;
V_3 = F_65 ( sizeof( * V_129 ) ) ;
if ( V_3 ) {
F_66 ( V_3 , sizeof( * V_129 ) ) ;
memcpy ( V_3 -> V_33 , V_129 , sizeof( * V_129 ) ) ;
F_67 ( & V_7 -> V_179 , V_3 ) ;
F_62 ( & V_7 -> V_177 ) ;
}
}
static void F_54 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
T_13 V_201 ;
int V_133 , V_211 , V_9 , V_134 ;
T_5 * V_206 ;
memcpy ( V_201 . V_212 , V_129 -> V_138 . V_213 . V_205 , V_108 ) ;
V_201 . V_35 = V_214 ;
switch ( V_7 -> V_215 ) {
case V_216 :
for ( V_133 = 0 ; V_133 < V_7 -> V_204 . V_134 ; V_133 ++ )
if ( memcmp ( V_201 . V_212 , V_7 -> V_204 . V_206 [ V_133 ] ,
V_108 ) == 0 ) {
V_201 . V_35 = V_217 ;
break;
}
break;
case V_218 :
V_201 . V_35 = V_217 ;
break;
case V_219 :
if ( V_7 -> V_220 . V_221 == 0 ) {
V_134 = V_7 -> V_220 . V_134 ;
V_206 = V_7 -> V_220 . V_206 [ 0 ] ;
} else {
V_134 = V_7 -> V_220 . V_222 ;
V_206 = V_7 -> V_220 . V_223 [ 0 ] ;
}
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ , V_206 += V_108 )
if ( memcmp ( V_201 . V_212 , V_206 , V_108 ) == 0 ) {
V_201 . V_35 = V_217 ;
break;
}
break;
case V_224 :
if ( V_7 -> V_225 . V_221 == 0 ) {
V_134 = V_7 -> V_225 . V_134 ;
V_206 = V_7 -> V_225 . V_206 [ 0 ] ;
} else {
V_134 = V_7 -> V_225 . V_222 ;
V_206 = V_7 -> V_225 . V_223 [ 0 ] ;
}
V_201 . V_35 = V_217 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ , V_206 += V_108 )
if ( memcmp ( V_201 . V_212 , V_206 , V_108 ) == 0 ) {
V_201 . V_35 = V_214 ;
break;
}
break;
}
V_211 = 0 ;
if ( V_201 . V_35 == V_217 ) {
for ( V_133 = 0 ; V_133 < V_7 -> V_204 . V_134 ; V_133 ++ )
if ( memcmp ( V_201 . V_212 , V_7 -> V_204 . V_206 [ V_133 ] , V_108 )
== 0 )
break;
if ( V_133 >= V_7 -> V_204 . V_134 ) {
if ( V_7 -> V_204 . V_134 >= V_226 ) {
V_201 . V_35 = V_227 ;
} else {
memcpy ( V_7 -> V_204 . V_206 [ V_7 -> V_204 . V_134 ] ,
V_201 . V_212 , V_108 ) ;
V_7 -> V_204 . V_134 ++ ;
V_211 = 1 ;
}
}
}
V_201 . V_35 = F_5 ( V_201 . V_35 ) ;
V_201 . V_228 = V_129 -> V_138 . V_213 . V_228 ;
V_9 = F_44 ( V_7 , V_229 ,
& V_201 , sizeof( V_201 ) ) ;
if ( V_9 ) {
if ( V_211 )
V_7 -> V_204 . V_134 -- ;
F_25 ( V_1 -> V_50 ,
L_71 ,
V_9 ) ;
}
}
static void F_68 ( T_1 * V_1 ,
T_7 * V_129 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_7 -> V_230 = F_22 ( V_129 -> V_138 . V_231 . V_232 ) ;
}
void F_69 ( T_1 * V_1 , T_7 * V_129 )
{
V_129 -> V_145 = F_22 ( V_129 -> V_145 ) ;
switch ( V_129 -> V_145 ) {
case V_233 :
F_40 ( V_1 , V_129 ) ;
break;
case V_234 :
F_41 ( V_1 , V_129 ) ;
break;
case V_235 :
F_45 ( V_1 , V_129 ) ;
break;
case V_236 :
F_43 ( V_1 , V_129 ) ;
break;
case V_237 :
F_49 ( V_1 , V_129 ) ;
break;
case V_238 :
F_61 ( V_1 , V_129 ) ;
break;
case V_239 :
F_63 ( V_1 , V_129 ) ;
break;
case V_240 :
F_64 ( V_1 , V_129 ) ;
break;
case V_241 :
F_68 ( V_1 , V_129 ) ;
break;
case V_242 :
F_23 ( V_1 -> V_50 , L_72 ) ;
break;
case V_243 :
F_23 ( V_1 -> V_50 , L_73 ) ;
break;
case V_244 :
F_23 ( V_1 -> V_50 , L_74 ) ;
break;
default:
F_23 ( V_1 -> V_50 ,
L_75 , V_129 -> V_145 ) ;
break;
}
}
void F_70 ( T_1 * V_1 , T_4 V_35 )
{
F_9 ( L_76 , V_35 ) ;
}
void F_71 ( T_1 * V_1 , T_4 V_35 )
{
F_9 ( L_77 , V_35 ) ;
V_1 -> V_245 . V_246 ++ ;
}
void F_72 ( T_1 * V_1 , struct V_2 * V_3 )
{
F_73 ( V_1 , V_3 ) ;
}
void F_74 ( T_1 * V_1 )
{
F_75 ( V_1 -> V_50 ) ;
}
static T_1 * F_76 ( void )
{
T_1 * V_1 = NULL ;
T_2 * V_7 = NULL ;
V_1 = F_77 ( sizeof( T_1 ) , V_247 ) ;
V_7 = F_77 ( sizeof( T_2 ) , V_247 ) ;
if ( ! V_1 || ! V_7 ) {
F_78 ( L_78 , V_248 ) ;
F_46 ( V_1 ) ;
F_46 ( V_7 ) ;
return NULL ;
}
V_1 -> V_249 = V_248 ;
V_1 -> V_52 = V_66 ;
V_1 -> V_8 = V_7 ;
V_1 -> V_250 = F_1 ;
V_1 -> V_251 = F_2 ;
V_1 -> V_252 = F_3 ;
V_1 -> V_253 = F_4 ;
V_1 -> V_254 = F_8 ;
V_1 -> V_255 = F_38 ;
V_1 -> V_256 = V_257 ;
V_1 -> V_109 = V_258 | V_259 ;
V_7 -> V_260 = 1 ;
return V_1 ;
}
void F_58 ( struct V_175 * V_33 )
{
T_2 * V_7 = F_52 ( V_33 , struct V_176 , V_194 ) ;
T_1 * V_1 = V_7 -> V_1 ;
T_11 V_178 ;
struct V_261 V_16 ;
T_14 * V_262 = ( T_14 * )
& V_16 . V_263 . V_33 ;
int V_9 = 0 ;
if ( V_7 -> V_1 -> V_67 )
return;
if ( ( V_1 -> V_68 == V_69 ) ||
( V_1 -> V_68 == V_264 ) ) {
return;
}
if ( V_1 -> V_68 != V_192 ) {
V_9 = F_31 (
V_7 , V_265 ,
& V_7 -> V_45 , V_266 ) ;
if ( V_9 ) {
F_25 ( V_1 -> V_50 , L_79 ) ;
return;
}
F_9 ( L_80 ,
F_22 ( V_7 -> V_45 . V_46 ) ,
F_22 ( V_7 -> V_45 . V_47 ) ,
F_22 ( V_7 -> V_45 . V_48 ) ) ;
}
V_16 . V_17 = V_18 ;
V_262 -> V_267 = V_268 ;
V_9 = F_79 ( V_1 , ( T_5 * ) & V_16 ) ;
if ( V_9 ) {
F_9 ( L_81 ,
V_9 ) ;
return;
}
switch ( V_262 -> V_33 ) {
case V_269 :
V_7 -> V_49 = 10 ;
break;
case V_270 :
V_7 -> V_49 = 20 ;
break;
case V_271 :
V_7 -> V_49 = 55 ;
break;
case V_272 :
V_7 -> V_49 = 110 ;
break;
default:
F_9 ( L_82 , V_262 -> V_33 ) ;
}
V_9 = F_31 ( V_7 ,
V_186 ,
V_1 -> V_155 , V_156 ) ;
if ( V_9 ) {
F_9 ( L_61 ,
V_186 , V_9 ) ;
return;
}
V_9 = F_31 ( V_7 ,
V_187 ,
& V_178 , sizeof( V_178 ) ) ;
if ( V_9 ) {
F_9 ( L_61 ,
V_187 , V_9 ) ;
return;
}
F_56 ( (struct V_188 * ) & V_178 ,
( V_189 * ) & V_1 -> V_178 ) ;
F_80 ( & V_7 -> V_273 , V_274 + V_275 ) ;
}
void F_81 ( unsigned long V_33 )
{
T_2 * V_7 = ( T_2 * ) V_33 ;
F_62 ( & V_7 -> V_194 ) ;
}
