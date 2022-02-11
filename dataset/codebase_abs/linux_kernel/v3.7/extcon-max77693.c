static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_11 ,
time << V_12 ,
V_13 ) ;
if ( V_4 )
F_3 ( V_2 -> V_14 , L_1 ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_2 ) ;
V_4 = - V_15 ;
break;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_16 , bool V_17 )
{
int V_4 = 0 ;
T_1 V_18 , V_19 = 0 ;
if ( V_17 )
V_18 = V_16 ;
else
V_18 = V_20 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_21 , V_18 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
goto V_23;
}
if ( V_17 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_26 , V_19 ,
V_25 | V_24 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
goto V_23;
}
F_5 ( V_2 -> V_14 ,
L_4 ,
V_18 , V_19 , V_17 ? L_5 : L_6 ) ;
V_23:
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_17 )
{
int V_4 = 0 ;
int type ;
int V_27 , V_28 , V_29 ;
if ( V_17 ) {
V_27 = V_2 -> V_30 [ 0 ] & V_31 ;
V_29 = V_2 -> V_30 [ 0 ] & V_32 ;
V_29 >>= V_33 ;
V_28 = V_2 -> V_30 [ 0 ] & V_34 ;
V_28 >>= V_35 ;
type = ( ( 0x1 << 8 ) | ( V_29 << 1 ) | V_28 ) ;
V_2 -> V_36 = V_27 ;
V_2 -> V_37 = type ;
} else
type = V_2 -> V_37 ;
switch ( type ) {
case V_38 :
V_4 = F_4 ( V_2 , V_39 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 , L_7 , V_17 ) ;
break;
case V_41 :
V_4 = F_4 ( V_2 , V_42 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 ,
L_8 , V_17 ) ;
break;
case V_43 :
F_7 ( V_2 -> V_40 , L_9 , V_17 ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_10 ,
V_17 ? L_5 : L_6 ) ;
F_3 ( V_2 -> V_14 , L_11 ,
V_27 , V_29 , V_28 ) ;
V_4 = - V_15 ;
break;
}
V_23:
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_44 , bool V_17 )
{
int V_4 = 0 ;
int V_27 ;
if ( V_17 ) {
V_2 -> V_36 = V_44 ;
V_27 = V_44 ;
} else
V_27 = V_2 -> V_36 ;
F_5 ( V_2 -> V_14 ,
L_12 ,
V_17 ? L_5 : L_6 , V_44 , V_2 -> V_36 ) ;
switch ( V_27 ) {
case V_45 :
F_6 ( V_2 , V_17 ) ;
break;
case V_46 :
case V_47 :
V_4 = F_4 ( V_2 , V_39 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 , L_13 , V_17 ) ;
break;
case V_48 :
case V_49 :
V_4 = F_4 ( V_2 , V_50 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 , L_14 , V_17 ) ;
break;
case V_51 :
V_4 = F_4 ( V_2 , V_42 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 ,
L_15 , V_17 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
F_5 ( V_2 -> V_14 ,
L_16 ,
V_17 ? L_5 : L_6 , V_27 ) ;
goto V_23;
default:
F_3 ( V_2 -> V_14 ,
L_17 ,
V_17 ? L_5 : L_6 , V_27 ) ;
V_4 = - V_15 ;
goto V_23;
}
V_23:
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_77 , bool V_17 )
{
int V_4 = 0 ;
int V_78 ;
if ( V_17 ) {
V_2 -> V_79 = V_77 ;
V_78 = V_77 ;
} else
V_78 = V_2 -> V_79 ;
F_5 ( V_2 -> V_14 ,
L_18 ,
V_17 ? L_5 : L_6 ,
V_77 , V_2 -> V_79 ) ;
switch ( V_78 ) {
case V_80 :
V_4 = F_4 ( V_2 , V_39 , V_17 ) ;
if ( V_4 < 0 )
goto V_23;
F_7 ( V_2 -> V_40 , L_13 , V_17 ) ;
break;
case V_81 :
F_7 ( V_2 -> V_40 ,
L_19 , V_17 ) ;
break;
case V_82 :
F_7 ( V_2 -> V_40 , L_20 , V_17 ) ;
break;
case V_83 :
F_7 ( V_2 -> V_40 , L_21 , V_17 ) ;
break;
case V_84 :
F_7 ( V_2 -> V_40 , L_22 , V_17 ) ;
break;
case V_85 :
break;
default:
F_3 ( V_2 -> V_14 ,
L_23 ,
V_17 ? L_5 : L_6 , V_78 ) ;
V_4 = - V_15 ;
goto V_23;
}
V_23:
return V_4 ;
}
static void F_10 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_11 ( V_87 ,
struct V_1 , V_88 ) ;
int V_44 , V_77 ;
int V_89 = - 1 ;
int V_90 , V_4 = 0 ;
bool V_17 = true ;
if ( ! V_2 -> V_40 )
return;
F_12 ( & V_2 -> V_91 ) ;
for ( V_90 = 0 ; V_90 < F_13 ( V_92 ) ; V_90 ++ )
if ( V_2 -> V_93 == V_92 [ V_90 ] . V_94 )
V_89 = V_92 [ V_90 ] . V_93 ;
V_4 = F_14 ( V_2 -> V_9 -> V_10 ,
V_95 , 2 , V_2 -> V_30 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_24 ) ;
F_15 ( & V_2 -> V_91 ) ;
return;
}
switch ( V_89 ) {
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_44 = V_2 -> V_30 [ 0 ] & V_31 ;
V_44 >>= V_100 ;
if ( V_44 == V_101 )
V_17 = false ;
V_4 = F_8 ( V_2 , V_44 , V_17 ) ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_77 = V_2 -> V_30 [ 1 ] & V_108 ;
V_77 >>= V_109 ;
if ( V_77 == V_110 )
V_17 = false ;
V_4 = F_9 ( V_2 , V_77 , V_17 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
break;
default:
F_3 ( V_2 -> V_14 , L_25 ,
V_89 ) ;
break;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_14 , L_26 ) ;
F_15 ( & V_2 -> V_91 ) ;
return;
}
static T_2 F_16 ( int V_93 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
V_2 -> V_93 = V_93 ;
F_17 ( & V_2 -> V_88 ) ;
return V_118 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_27 , V_78 ;
F_12 ( & V_2 -> V_91 ) ;
V_4 = F_14 ( V_2 -> V_9 -> V_10 ,
V_95 , 2 , V_2 -> V_30 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_24 ) ;
F_15 ( & V_2 -> V_91 ) ;
return - V_15 ;
}
V_27 = V_2 -> V_30 [ 0 ] & V_31 ;
V_27 >>= V_100 ;
if ( V_27 != V_101 ) {
F_5 ( V_2 -> V_14 ,
L_27 , V_27 ) ;
V_4 = F_8 ( V_2 , V_27 , true ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_14 , L_28 ) ;
goto V_23;
}
V_78 = V_2 -> V_30 [ 1 ] & V_108 ;
V_78 >>= V_109 ;
if ( V_78 != V_110 ) {
F_5 ( V_2 -> V_14 ,
L_29 ,
V_78 ) ;
F_9 ( V_2 , V_78 , true ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_14 , L_30 ) ;
}
V_23:
F_15 ( & V_2 -> V_91 ) ;
return V_4 ;
}
static int T_3 F_19 ( struct V_119 * V_120 )
{
struct V_121 * V_9 = F_20 ( V_120 -> V_14 . V_122 ) ;
struct V_123 * V_124 = F_21 ( V_9 -> V_14 ) ;
struct V_125 * V_126 = V_124 -> V_127 ;
struct V_1 * V_2 ;
int V_4 , V_90 ;
T_1 V_128 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_2 ) {
F_3 ( & V_120 -> V_14 , L_31 ) ;
V_4 = - V_130 ;
goto V_131;
}
V_2 -> V_14 = & V_120 -> V_14 ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_9 -> V_10 )
F_23 ( & V_120 -> V_14 , L_32 ) ;
else {
V_2 -> V_9 -> V_10 = F_24 (
V_2 -> V_9 -> V_132 ,
& V_133 ) ;
if ( F_25 ( V_2 -> V_9 -> V_10 ) ) {
V_4 = F_26 ( V_2 -> V_9 -> V_10 ) ;
F_3 ( V_9 -> V_14 ,
L_33 , V_4 ) ;
goto V_134;
}
}
F_27 ( V_120 , V_2 ) ;
F_28 ( & V_2 -> V_91 ) ;
F_29 ( & V_2 -> V_88 , F_10 ) ;
for ( V_90 = 0 ; V_90 < F_13 ( V_92 ) ; V_90 ++ ) {
struct V_135 * V_136 = & V_92 [ V_90 ] ;
int V_94 = 0 ;
V_94 = F_30 ( V_9 -> V_137 , V_136 -> V_93 ) ;
if ( ! V_94 )
goto V_138;
V_136 -> V_94 = V_94 ;
V_4 = F_31 ( V_94 , NULL ,
F_16 ,
V_139 , V_136 -> V_140 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_120 -> V_14 ,
L_34
L_35 ,
V_136 -> V_93 , V_4 ) ;
for ( V_90 = V_90 - 1 ; V_90 >= 0 ; V_90 -- )
F_32 ( V_136 -> V_94 , V_2 ) ;
goto V_138;
}
}
V_2 -> V_40 = F_22 ( sizeof( struct V_141 ) , V_129 ) ;
if ( ! V_2 -> V_40 ) {
F_3 ( & V_120 -> V_14 , L_36 ) ;
V_4 = - V_130 ;
goto V_138;
}
V_2 -> V_40 -> V_140 = V_142 ;
V_2 -> V_40 -> V_143 = V_144 ;
V_4 = F_33 ( V_2 -> V_40 , NULL ) ;
if ( V_4 ) {
F_3 ( & V_120 -> V_14 , L_37 ) ;
goto V_145;
}
for ( V_90 = 0 ; V_90 < V_126 -> V_146 ; V_90 ++ ) {
enum V_147 V_148 = V_149 ;
F_34 ( V_2 -> V_9 -> V_10 ,
V_126 -> V_150 [ V_90 ] . V_151 ,
V_126 -> V_150 [ V_90 ] . V_117 ) ;
switch ( V_126 -> V_150 [ V_90 ] . V_151 ) {
case V_152 :
V_148 = V_153 ;
break;
case V_154 :
V_148 = V_155 ;
break;
case V_156 :
V_148 = V_157 ;
break;
}
if ( V_148 < V_149 )
V_2 -> V_9 -> V_158 [ V_148 ]
= V_126 -> V_150 [ V_90 ] . V_117 ;
}
V_4 = F_35 ( V_2 -> V_9 -> V_10 ,
V_159 , & V_128 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_120 -> V_14 , L_38 ) ;
goto V_145;
}
F_5 ( V_2 -> V_14 , L_39 , V_128 ) ;
F_1 ( V_2 , V_7 ) ;
F_18 ( V_2 ) ;
return V_4 ;
V_145:
F_36 ( V_2 -> V_40 ) ;
V_138:
V_134:
F_36 ( V_2 ) ;
V_131:
return V_4 ;
}
static int T_4 F_37 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_38 ( V_120 ) ;
int V_90 ;
for ( V_90 = 0 ; V_90 < F_13 ( V_92 ) ; V_90 ++ )
F_32 ( V_92 [ V_90 ] . V_94 , V_2 ) ;
F_39 ( & V_2 -> V_88 ) ;
F_40 ( V_2 -> V_40 ) ;
F_36 ( V_2 -> V_40 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
