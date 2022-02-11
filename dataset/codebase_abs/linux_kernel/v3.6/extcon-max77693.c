static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 = 0 ;
T_1 V_5 ;
switch ( time ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
V_4 = F_2 ( V_2 -> V_10 -> V_11 ,
V_12 , & V_5 ) ;
V_5 &= ~ V_13 ;
V_5 |= ( time << V_14 ) ;
V_4 = F_3 ( V_2 -> V_10 -> V_11 ,
V_12 , V_5 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_15 , L_1 ) ;
V_4 = - V_16 ;
}
break;
default:
F_4 ( V_2 -> V_15 , L_2 ) ;
V_4 = - V_16 ;
break;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_17 , bool V_18 )
{
int V_4 = 0 ;
T_1 V_19 , V_20 = 0 ;
if ( V_18 )
V_19 = V_17 ;
else
V_19 = V_21 ;
V_4 = F_6 ( V_2 -> V_10 -> V_11 ,
V_22 , V_19 , V_23 ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 -> V_15 , L_3 ) ;
goto V_24;
}
if ( V_18 )
V_20 |= V_25 ;
else
V_20 |= V_26 ;
V_4 = F_6 ( V_2 -> V_10 -> V_11 ,
V_27 , V_20 ,
V_26 | V_25 ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 -> V_15 , L_3 ) ;
goto V_24;
}
F_7 ( V_2 -> V_15 ,
L_4 ,
V_19 , V_20 , V_18 ? L_5 : L_6 ) ;
V_24:
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
bool V_18 )
{
int V_4 = 0 ;
int type ;
int V_28 , V_29 , V_30 ;
if ( V_18 ) {
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_30 = V_2 -> V_31 [ 0 ] & V_33 ;
V_30 >>= V_34 ;
V_29 = V_2 -> V_31 [ 0 ] & V_35 ;
V_29 >>= V_36 ;
type = ( ( 0x1 << 8 ) | ( V_30 << 1 ) | V_29 ) ;
V_2 -> V_37 = V_28 ;
V_2 -> V_38 = type ;
} else
type = V_2 -> V_38 ;
switch ( type ) {
case V_39 :
V_4 = F_5 ( V_2 , V_40 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 , L_7 , V_18 ) ;
break;
case V_42 :
V_4 = F_5 ( V_2 , V_43 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 ,
L_8 , V_18 ) ;
break;
case V_44 :
F_9 ( V_2 -> V_41 , L_9 , V_18 ) ;
break;
default:
F_4 ( V_2 -> V_15 , L_10 ,
V_18 ? L_5 : L_6 ) ;
F_4 ( V_2 -> V_15 , L_11 ,
V_28 , V_30 , V_29 ) ;
V_4 = - V_16 ;
break;
}
V_24:
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_45 , bool V_18 )
{
int V_4 = 0 ;
int V_28 ;
if ( V_18 ) {
V_2 -> V_37 = V_45 ;
V_28 = V_45 ;
} else
V_28 = V_2 -> V_37 ;
F_7 ( V_2 -> V_15 ,
L_12 ,
V_18 ? L_5 : L_6 , V_45 , V_2 -> V_37 ) ;
switch ( V_28 ) {
case V_46 :
F_8 ( V_2 , V_18 ) ;
break;
case V_47 :
case V_48 :
V_4 = F_5 ( V_2 , V_40 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 , L_13 , V_18 ) ;
break;
case V_49 :
case V_50 :
V_4 = F_5 ( V_2 , V_51 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 , L_14 , V_18 ) ;
break;
case V_52 :
V_4 = F_5 ( V_2 , V_43 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 ,
L_15 , V_18 ) ;
break;
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
case V_77 :
F_7 ( V_2 -> V_15 ,
L_16 ,
V_18 ? L_5 : L_6 , V_28 ) ;
goto V_24;
default:
F_4 ( V_2 -> V_15 ,
L_17 ,
V_18 ? L_5 : L_6 , V_28 ) ;
V_4 = - V_16 ;
goto V_24;
}
V_24:
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_78 , bool V_18 )
{
int V_4 = 0 ;
int V_79 ;
if ( V_18 ) {
V_2 -> V_80 = V_78 ;
V_79 = V_78 ;
} else
V_79 = V_2 -> V_80 ;
F_7 ( V_2 -> V_15 ,
L_18 ,
V_18 ? L_5 : L_6 ,
V_78 , V_2 -> V_80 ) ;
switch ( V_79 ) {
case V_81 :
V_4 = F_5 ( V_2 , V_40 , V_18 ) ;
if ( V_4 < 0 )
goto V_24;
F_9 ( V_2 -> V_41 , L_13 , V_18 ) ;
break;
case V_82 :
F_9 ( V_2 -> V_41 ,
L_19 , V_18 ) ;
break;
case V_83 :
F_9 ( V_2 -> V_41 , L_20 , V_18 ) ;
break;
case V_84 :
F_9 ( V_2 -> V_41 , L_21 , V_18 ) ;
break;
case V_85 :
F_9 ( V_2 -> V_41 , L_22 , V_18 ) ;
break;
case V_86 :
break;
default:
F_4 ( V_2 -> V_15 ,
L_23 ,
V_18 ? L_5 : L_6 , V_79 ) ;
V_4 = - V_16 ;
goto V_24;
}
V_24:
return V_4 ;
}
static void F_12 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_13 ( V_88 ,
struct V_1 , V_89 ) ;
int V_45 , V_78 ;
int V_90 = - 1 ;
int V_91 , V_4 = 0 ;
bool V_18 = true ;
if ( ! V_2 -> V_41 )
return;
F_14 ( & V_2 -> V_92 ) ;
for ( V_91 = 0 ; V_91 < F_15 ( V_93 ) ; V_91 ++ )
if ( V_2 -> V_94 == V_93 [ V_91 ] . V_95 )
V_90 = V_93 [ V_91 ] . V_94 ;
V_4 = F_16 ( V_2 -> V_10 -> V_11 ,
V_96 , 2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_15 , L_24 ) ;
F_17 ( & V_2 -> V_92 ) ;
return;
}
switch ( V_90 ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_45 = V_2 -> V_31 [ 0 ] & V_32 ;
V_45 >>= V_101 ;
if ( V_45 == V_102 )
V_18 = false ;
V_4 = F_10 ( V_2 , V_45 , V_18 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_78 = V_2 -> V_31 [ 1 ] & V_109 ;
V_78 >>= V_110 ;
if ( V_78 == V_111 )
V_18 = false ;
V_4 = F_11 ( V_2 , V_78 , V_18 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
break;
default:
F_4 ( V_2 -> V_15 , L_25 ,
V_90 ) ;
break;
}
if ( V_4 < 0 )
F_4 ( V_2 -> V_15 , L_26 ) ;
F_17 ( & V_2 -> V_92 ) ;
return;
}
static T_2 F_18 ( int V_94 , void * V_118 )
{
struct V_1 * V_2 = V_118 ;
V_2 -> V_94 = V_94 ;
F_19 ( & V_2 -> V_89 ) ;
return V_119 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_28 , V_79 ;
F_14 ( & V_2 -> V_92 ) ;
V_4 = F_16 ( V_2 -> V_10 -> V_11 ,
V_96 , 2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_15 , L_24 ) ;
F_17 ( & V_2 -> V_92 ) ;
return - V_16 ;
}
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_28 >>= V_101 ;
if ( V_28 != V_102 ) {
F_7 ( V_2 -> V_15 ,
L_27 , V_28 ) ;
V_4 = F_10 ( V_2 , V_28 , true ) ;
if ( V_4 < 0 )
F_4 ( V_2 -> V_15 , L_28 ) ;
goto V_24;
}
V_79 = V_2 -> V_31 [ 1 ] & V_109 ;
V_79 >>= V_110 ;
if ( V_79 != V_111 ) {
F_7 ( V_2 -> V_15 ,
L_29 ,
V_79 ) ;
F_11 ( V_2 , V_79 , true ) ;
if ( V_4 < 0 )
F_4 ( V_2 -> V_15 , L_30 ) ;
}
V_24:
F_17 ( & V_2 -> V_92 ) ;
return V_4 ;
}
static int T_3 F_21 ( struct V_120 * V_121 )
{
struct V_122 * V_10 = F_22 ( V_121 -> V_15 . V_123 ) ;
struct V_1 * V_2 ;
int V_4 , V_91 ;
T_1 V_124 ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_125 ) ;
if ( ! V_2 ) {
F_4 ( & V_121 -> V_15 , L_31 ) ;
V_4 = - V_126 ;
goto V_127;
}
V_2 -> V_15 = & V_121 -> V_15 ;
V_2 -> V_10 = V_10 ;
if ( V_2 -> V_10 -> V_11 )
F_24 ( & V_121 -> V_15 , L_32 ) ;
else {
V_2 -> V_10 -> V_11 = F_25 (
V_2 -> V_10 -> V_128 ,
& V_129 ) ;
if ( F_26 ( V_2 -> V_10 -> V_11 ) ) {
V_4 = F_27 ( V_2 -> V_10 -> V_11 ) ;
F_4 ( V_10 -> V_15 ,
L_33 , V_4 ) ;
goto V_130;
}
}
F_28 ( V_121 , V_2 ) ;
F_29 ( & V_2 -> V_92 ) ;
F_30 ( & V_2 -> V_89 , F_12 ) ;
for ( V_91 = 0 ; V_91 < F_15 ( V_93 ) ; V_91 ++ ) {
struct V_131 * V_132 = & V_93 [ V_91 ] ;
int V_95 = 0 ;
V_95 = F_31 ( V_10 -> V_133 , V_132 -> V_94 ) ;
if ( ! V_95 )
goto V_134;
V_132 -> V_95 = V_95 ;
V_4 = F_32 ( V_95 , NULL ,
F_18 ,
0 , V_132 -> V_135 , V_2 ) ;
if ( V_4 ) {
F_4 ( & V_121 -> V_15 ,
L_34
L_35 ,
V_132 -> V_94 , V_4 ) ;
for ( V_91 = V_91 - 1 ; V_91 >= 0 ; V_91 -- )
F_33 ( V_132 -> V_95 , V_2 ) ;
goto V_134;
}
}
V_2 -> V_41 = F_23 ( sizeof( struct V_136 ) , V_125 ) ;
if ( ! V_2 -> V_41 ) {
F_4 ( & V_121 -> V_15 , L_36 ) ;
V_4 = - V_126 ;
goto V_134;
}
V_2 -> V_41 -> V_135 = V_137 ;
V_2 -> V_41 -> V_138 = V_139 ;
V_4 = F_34 ( V_2 -> V_41 , NULL ) ;
if ( V_4 ) {
F_4 ( & V_121 -> V_15 , L_37 ) ;
goto V_140;
}
V_4 = F_2 ( V_2 -> V_10 -> V_11 ,
V_141 , & V_124 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_121 -> V_15 , L_38 ) ;
goto V_140;
}
F_7 ( V_2 -> V_15 , L_39 , V_124 ) ;
F_1 ( V_2 , V_8 ) ;
F_20 ( V_2 ) ;
return V_4 ;
V_140:
F_35 ( V_2 -> V_41 ) ;
V_134:
V_130:
F_35 ( V_2 ) ;
V_127:
return V_4 ;
}
static int T_4 F_36 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_37 ( V_121 ) ;
int V_91 ;
for ( V_91 = 0 ; V_91 < F_15 ( V_93 ) ; V_91 ++ )
F_33 ( V_93 [ V_91 ] . V_95 , V_2 ) ;
F_38 ( & V_2 -> V_89 ) ;
F_39 ( V_2 -> V_41 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
