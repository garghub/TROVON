static char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
case V_6 : return L_5 ;
case V_7 : return L_6 ;
case V_8 : return L_7 ;
default: return L_8 ;
}
}
static int F_2 (
struct V_9 * V_9 ,
const struct V_10 * V_11 )
{
void T_2 * V_12 = V_9 -> V_13 ;
int V_14 = 1 ;
T_1 V_15 [ 2 ] , V_16 = 0 ;
const T_1 V_17 = V_11 -> V_18 & V_19 ;
V_15 [ 1 ] = 0 ;
switch ( V_17 ) {
case V_20 :
V_15 [ 0 ] = V_9 -> V_21 . V_22 << V_23 ;
V_15 [ 0 ] |= V_9 -> V_24 << V_25 ;
if ( V_9 -> V_21 . V_26 ) {
V_15 [ 0 ] |= V_9 -> V_21 . V_27
<< V_28 ;
V_15 [ 0 ] |= V_9 -> V_21 . V_29
<< V_30 ;
V_15 [ 0 ] |= V_9 -> V_21 . V_31
<< V_32 ;
}
break;
case V_33 :
V_15 [ 0 ] = 0 ;
break;
case V_34 : {
int V_35 ;
struct V_36 * V_37 ;
T_3 V_38 ;
void T_2 * V_39 ;
V_16 = ( T_1 ) V_11 -> V_40 ;
if ( ! V_16 ) {
V_15 [ 0 ] = 0 ;
break;
}
V_35 = V_16 & V_41 ;
if ( V_35 ) {
V_16 &= 0x0f ;
V_37 = & V_9 -> V_42 [ V_16 ] . V_43 ;
} else {
V_37 = & V_9 -> V_42 [ V_16 ] . V_44 ;
}
V_39 = V_9 -> V_42 [ V_16 ] . V_39 ;
if ( V_16 >= V_45 || ! V_37 -> V_46 ) {
V_14 = - V_47 ;
break;
}
F_3 ( V_12 , V_16 ) ;
if ( V_35 )
V_38 = F_4 ( V_39 , V_48 )
& V_49 ;
else
V_38 = F_4 ( V_39 , V_50 )
& V_51 ;
F_3 ( V_12 , 0 ) ;
V_15 [ 0 ] = V_38 ? 1 : 0 ;
} break;
default:
V_14 = 0 ;
break;
}
if ( V_14 > 0 ) {
T_3 V_52 = F_5 ( V_11 -> V_53 ) ;
if ( V_52 > 2 )
V_52 = 2 ;
F_6 ( & V_9 -> V_42 [ 0 ] , V_52 , V_15 ) ;
}
return V_14 ;
}
static int
F_7 ( struct V_9 * V_9 , const struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( ( V_11 -> V_18 & V_54 )
== V_55 ) {
switch ( V_11 -> V_56 ) {
case V_57 :
V_14 = F_2 ( V_9 ,
V_11 ) ;
break;
default:
break;
}
}
return V_14 ;
}
static void F_8 ( struct V_9 * V_9 , struct V_58 * V_59 )
{
F_9 ( & V_9 -> V_42 [ 0 ] . V_43 , V_59 , 0 ) ;
}
static inline void F_10 ( struct V_9 * V_9 )
{
void T_2 * V_12 = V_9 -> V_13 ;
T_1 V_60 ;
F_11 ( V_9 , L_9 ) ;
V_60 = F_12 ( V_12 , V_61 ) ;
F_13 ( V_12 , V_61 , V_60 | V_62 ) ;
}
static int
F_14 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
__releases( V_9 -> V_63 )
__acquires( V_9 -> V_63 )
{
int V_14 = - V_47 ;
void T_2 * V_12 = V_9 -> V_13 ;
const T_1 V_17 = V_11 -> V_18 & V_19 ;
if ( ( V_11 -> V_18 & V_54 )
== V_55 ) {
switch ( V_11 -> V_56 ) {
case V_64 :
V_9 -> V_65 = true ;
V_9 -> V_66 = ( T_1 ) ( V_11 -> V_67 & 0x7f ) ;
V_14 = 1 ;
break;
case V_68 :
switch ( V_17 ) {
case V_20 :
if ( V_11 -> V_67
!= V_25 )
break;
V_9 -> V_24 = 0 ;
V_14 = 1 ;
break;
case V_33 :
break;
case V_34 : {
const T_1 V_16 =
V_11 -> V_40 & 0x0f ;
struct V_36 * V_36 ;
struct V_69 * V_37 ;
struct V_70 * V_71 ;
void T_2 * V_39 ;
int V_35 ;
T_3 V_72 ;
if ( V_16 == 0 || V_16 >= V_45 ||
V_11 -> V_67 != V_73 )
break;
V_37 = V_9 -> V_42 + V_16 ;
V_39 = V_37 -> V_39 ;
V_35 = V_11 -> V_40 & V_41 ;
if ( V_35 )
V_36 = & V_37 -> V_43 ;
else
V_36 = & V_37 -> V_44 ;
if ( ! V_36 -> V_46 )
break;
V_14 = 1 ;
if ( V_36 -> V_74 )
break;
F_3 ( V_12 , V_16 ) ;
if ( V_35 ) {
V_72 = F_4 ( V_39 , V_48 ) ;
V_72 |= V_75 |
V_76 ;
V_72 &= ~ ( V_49 |
V_77 |
V_78 ) ;
F_15 ( V_39 , V_48 , V_72 ) ;
} else {
V_72 = F_4 ( V_39 , V_50 ) ;
V_72 |= V_79 |
V_80 ;
V_72 &= ~ ( V_51 |
V_81 ) ;
F_15 ( V_39 , V_50 , V_72 ) ;
}
V_71 = F_16 ( V_36 ) ;
if ( ! V_36 -> V_82 && V_71 ) {
F_11 ( V_9 , L_10 ) ;
F_17 ( V_9 , V_71 ) ;
}
F_3 ( V_12 , 0 ) ;
} break;
default:
V_14 = 0 ;
break;
}
break;
case V_83 :
switch ( V_17 ) {
case V_20 :
V_14 = 1 ;
switch ( V_11 -> V_67 ) {
case V_25 :
V_9 -> V_24 = 1 ;
break;
case V_84 :
if ( V_9 -> V_21 . V_85 != V_86 )
goto V_87;
if ( V_11 -> V_40 & 0xff )
goto V_87;
switch ( V_11 -> V_40 >> 8 ) {
case 1 :
F_18 ( L_11 ) ;
V_9 -> V_88 =
V_89 ;
break;
case 2 :
F_18 ( L_12 ) ;
V_9 -> V_88 =
V_90 ;
break;
case 3 :
F_18 ( L_13 ) ;
V_9 -> V_88 =
V_91 ;
break;
case 4 :
F_18 ( L_14 ) ;
V_9 -> V_88 =
V_92 ;
break;
case 0xc0 :
F_18 ( L_15 ) ;
V_9 -> V_88 =
V_93 ;
break;
case 0xc1 :
F_18 ( L_16 ) ;
V_9 -> V_88 =
V_94 ;
break;
case 0xc2 :
F_18 ( L_17 ) ;
V_9 -> V_88 =
V_95 ;
break;
case 0xc3 :
F_18 ( L_18 ) ;
V_9 -> V_88 =
V_96 ;
break;
default:
goto V_87;
}
if ( V_14 > 0 )
V_9 -> V_97 = true ;
break;
case V_28 :
if ( ! V_9 -> V_21 . V_26 )
goto V_87;
V_9 -> V_21 . V_27 = 1 ;
F_10 ( V_9 ) ;
break;
case V_32 :
if ( ! V_9 -> V_21 . V_26 )
goto V_87;
V_9 -> V_21 . V_31 = 1 ;
break;
case V_30 :
if ( ! V_9 -> V_21 . V_26 )
goto V_87;
V_9 -> V_21 . V_29 = 1 ;
break;
case V_98 :
V_14 = 0 ;
break;
V_87:
default:
V_14 = - V_47 ;
break;
}
break;
case V_33 :
break;
case V_34 : {
const T_1 V_16 =
V_11 -> V_40 & 0x0f ;
struct V_36 * V_36 ;
struct V_69 * V_37 ;
void T_2 * V_39 ;
int V_35 ;
T_3 V_72 ;
if ( V_16 == 0 || V_16 >= V_45 ||
V_11 -> V_67 != V_73 )
break;
V_37 = V_9 -> V_42 + V_16 ;
V_39 = V_37 -> V_39 ;
V_35 = V_11 -> V_40 & V_41 ;
if ( V_35 )
V_36 = & V_37 -> V_43 ;
else
V_36 = & V_37 -> V_44 ;
if ( ! V_36 -> V_46 )
break;
F_3 ( V_12 , V_16 ) ;
if ( V_35 ) {
V_72 = F_4 ( V_39 , V_48 ) ;
if ( V_72 & V_99 )
V_72 |= V_100 ;
V_72 |= V_49
| V_75
| V_76 ;
F_15 ( V_39 , V_48 , V_72 ) ;
} else {
V_72 = F_4 ( V_39 , V_50 ) ;
V_72 |= V_51
| V_101
| V_79
| V_80 ;
F_15 ( V_39 , V_50 , V_72 ) ;
}
F_3 ( V_12 , 0 ) ;
V_14 = 1 ;
} break;
default:
V_14 = 0 ;
break;
}
break;
default:
V_14 = 0 ;
}
} else
V_14 = 0 ;
return V_14 ;
}
static void F_19 ( struct V_9 * V_9 )
{
void T_2 * V_39 = V_9 -> V_102 -> V_39 ;
struct V_70 * V_71 ;
struct V_58 * V_59 ;
T_3 V_103 , V_72 ;
V_71 = F_20 ( V_9 ) ;
V_59 = & V_71 -> V_71 ;
if ( V_59 ) {
void * V_104 = V_59 -> V_104 + V_59 -> V_105 ;
unsigned V_52 = V_59 -> V_106 - V_59 -> V_105 ;
V_103 = F_12 ( V_39 , V_107 ) ;
if ( V_103 > V_52 ) {
V_59 -> V_108 = - V_109 ;
V_103 = V_52 ;
}
if ( V_103 > 0 ) {
F_21 ( & V_9 -> V_42 [ 0 ] , V_103 , V_104 ) ;
V_59 -> V_105 += V_103 ;
}
V_72 = V_110 ;
if ( V_103 < 64 || V_59 -> V_105 == V_59 -> V_106 ) {
V_9 -> V_111 = V_7 ;
V_72 |= V_112 ;
} else
V_59 = NULL ;
} else
V_72 = V_110 | V_113 ;
if ( V_59 ) {
V_9 -> V_114 = V_72 ;
F_8 ( V_9 , V_59 ) ;
if ( ! V_9 -> V_114 )
return;
V_9 -> V_114 = 0 ;
}
F_3 ( V_9 -> V_13 , 0 ) ;
F_15 ( V_39 , V_115 , V_72 ) ;
}
static void F_22 ( struct V_9 * V_9 )
{
void T_2 * V_39 = V_9 -> V_102 -> V_39 ;
struct V_70 * V_59 = F_20 ( V_9 ) ;
struct V_58 * V_71 ;
T_3 V_72 = V_116 ;
T_1 * V_117 ;
T_1 V_118 ;
if ( ! V_59 ) {
F_11 ( V_9 , L_19 , F_4 ( V_39 , V_115 ) ) ;
return;
}
V_71 = & V_59 -> V_71 ;
V_117 = ( T_1 * ) V_71 -> V_104 + V_71 -> V_105 ;
V_118 = F_23 ( ( unsigned ) V_119 ,
V_71 -> V_106 - V_71 -> V_105 ) ;
F_6 ( & V_9 -> V_42 [ 0 ] , V_118 , V_117 ) ;
V_71 -> V_105 += V_118 ;
if ( V_118 < V_120
|| ( V_71 -> V_105 == V_71 -> V_106
&& ! V_71 -> V_121 ) ) {
V_9 -> V_111 = V_8 ;
V_72 |= V_112 ;
} else
V_71 = NULL ;
if ( V_71 ) {
V_9 -> V_114 = V_72 ;
F_8 ( V_9 , V_71 ) ;
if ( ! V_9 -> V_114 )
return;
V_9 -> V_114 = 0 ;
}
F_3 ( V_9 -> V_13 , 0 ) ;
F_15 ( V_39 , V_115 , V_72 ) ;
}
static void
F_24 ( struct V_9 * V_9 , struct V_10 * V_59 )
{
struct V_70 * V_122 ;
void T_2 * V_39 = V_9 -> V_102 -> V_39 ;
F_21 ( & V_9 -> V_42 [ 0 ] , sizeof *V_59 , ( T_1 * ) V_59 ) ;
F_11 ( V_9 , L_20 ,
V_59 -> V_18 ,
V_59 -> V_56 ,
F_5 ( V_59 -> V_67 ) ,
F_5 ( V_59 -> V_40 ) ,
F_5 ( V_59 -> V_53 ) ) ;
V_122 = F_20 ( V_9 ) ;
if ( V_122 )
F_8 ( V_9 , & V_122 -> V_71 ) ;
V_9 -> V_65 = false ;
V_9 -> V_114 = V_110 ;
if ( V_59 -> V_53 == 0 ) {
if ( V_59 -> V_18 & V_41 )
V_9 -> V_114 |= V_116 ;
V_9 -> V_111 = V_6 ;
} else if ( V_59 -> V_18 & V_41 ) {
V_9 -> V_111 = V_4 ;
F_15 ( V_39 , V_115 , V_110 ) ;
while ( ( F_4 ( V_39 , V_115 )
& V_123 ) != 0 )
F_25 () ;
V_9 -> V_114 = 0 ;
} else
V_9 -> V_111 = V_5 ;
}
static int
F_26 ( struct V_9 * V_9 , const struct V_10 * V_11 )
__releases( V_9 -> V_63 )
__acquires( V_9 -> V_63 )
{
int V_124 ;
if ( ! V_9 -> V_125 )
return - V_126 ;
F_27 ( & V_9 -> V_63 ) ;
V_124 = V_9 -> V_125 -> V_127 ( & V_9 -> V_21 , V_11 ) ;
F_28 ( & V_9 -> V_63 ) ;
return V_124 ;
}
T_4 F_29 ( struct V_9 * V_9 )
{
T_3 V_72 ;
T_3 V_52 ;
void T_2 * V_12 = V_9 -> V_13 ;
void T_2 * V_39 = V_9 -> V_42 [ 0 ] . V_39 ;
T_4 V_124 = V_128 ;
F_3 ( V_12 , 0 ) ;
V_72 = F_4 ( V_39 , V_115 ) ;
V_52 = F_12 ( V_39 , V_107 ) ;
F_11 ( V_9 , L_21 ,
V_72 , V_52 , F_1 ( V_9 -> V_111 ) ) ;
if ( V_72 & V_112 ) {
return V_129 ;
}
if ( V_72 & V_130 ) {
F_15 ( V_39 , V_115 ,
V_72 & ~ V_130 ) ;
V_124 = V_129 ;
V_9 -> V_111 = V_2 ;
V_72 = F_4 ( V_39 , V_115 ) ;
}
if ( V_72 & V_131 ) {
F_15 ( V_39 , V_115 , V_132 ) ;
V_124 = V_129 ;
switch ( V_9 -> V_111 ) {
case V_4 :
V_9 -> V_111 = V_8 ;
break;
case V_5 :
V_9 -> V_111 = V_7 ;
break;
default:
F_30 ( L_22 ,
F_1 ( V_9 -> V_111 ) ) ;
}
V_72 = F_4 ( V_39 , V_115 ) ;
}
switch ( V_9 -> V_111 ) {
case V_4 :
if ( ( V_72 & V_116 ) == 0 ) {
F_22 ( V_9 ) ;
V_124 = V_129 ;
}
break;
case V_5 :
if ( V_72 & V_123 ) {
F_19 ( V_9 ) ;
V_124 = V_129 ;
}
break;
case V_7 :
if ( V_9 -> V_65 ) {
V_9 -> V_65 = false ;
F_13 ( V_12 , V_133 , V_9 -> V_66 ) ;
}
else if ( V_9 -> V_97 ) {
F_11 ( V_9 , L_23 ) ;
if ( V_92 == V_9 -> V_88 )
F_31 ( V_9 ) ;
F_13 ( V_12 , V_134 ,
V_9 -> V_88 ) ;
}
case V_8 :
{
struct V_70 * V_59 ;
V_59 = F_20 ( V_9 ) ;
if ( V_59 )
F_8 ( V_9 , & V_59 -> V_71 ) ;
}
if ( V_72 & V_123 )
goto V_127;
V_124 = V_129 ;
V_9 -> V_111 = V_2 ;
break;
case V_2 :
V_124 = V_129 ;
V_9 -> V_111 = V_3 ;
case V_3 :
V_127:
if ( V_72 & V_123 ) {
struct V_10 V_127 ;
int V_14 = 0 ;
if ( V_52 != 8 ) {
F_30 ( L_24 , V_52 ) ;
break;
}
F_24 ( V_9 , & V_127 ) ;
V_124 = V_129 ;
if ( F_32 ( V_9 -> V_21 . V_85 == V_135 ) ) {
T_1 V_136 ;
F_33 ( V_137 L_25
L_26 ,
V_138 ) ;
V_136 = F_12 ( V_12 , V_139 ) ;
V_9 -> V_21 . V_85 = ( V_136 & V_140 )
? V_86 : V_141 ;
}
switch ( V_9 -> V_111 ) {
case V_6 :
V_14 = F_14 (
V_9 , & V_127 ) ;
V_9 -> V_114 |= V_112 ;
if ( V_14 > 0 )
V_9 -> V_111 =
V_7 ;
break;
case V_4 :
V_14 = F_7 ( V_9 , & V_127 ) ;
if ( V_14 > 0 ) {
V_9 -> V_114 = V_116
| V_112 ;
V_9 -> V_111 =
V_8 ;
}
break;
default:
break;
}
F_11 ( V_9 , L_27 ,
V_14 , V_72 ,
F_1 ( V_9 -> V_111 ) ) ;
if ( V_14 < 0 )
goto V_87;
else if ( V_14 > 0 )
goto V_142;
V_14 = F_26 ( V_9 , & V_127 ) ;
if ( V_14 < 0 ) {
F_3 ( V_12 , 0 ) ;
V_87:
F_11 ( V_9 , L_28 , V_14 ) ;
V_9 -> V_114 |= V_113 ;
V_9 -> V_111 = V_2 ;
V_142:
F_15 ( V_39 , V_115 ,
V_9 -> V_114 ) ;
V_9 -> V_114 = 0 ;
}
}
break;
case V_6 :
V_124 = V_129 ;
break;
default:
F_34 ( 1 ) ;
F_15 ( V_39 , V_115 , V_113 ) ;
V_9 -> V_111 = V_2 ;
break;
}
return V_124 ;
}
static int
F_35 ( struct V_143 * V_37 , const struct V_144 * V_46 )
{
return - V_47 ;
}
static int F_36 ( struct V_143 * V_145 )
{
return - V_47 ;
}
static int
F_37 ( struct V_143 * V_145 , struct V_58 * V_122 , T_5 V_146 )
{
struct V_36 * V_37 ;
struct V_70 * V_59 ;
struct V_9 * V_9 ;
int V_108 ;
unsigned long V_147 ;
void T_2 * V_39 ;
if ( ! V_145 || ! V_122 )
return - V_47 ;
V_37 = F_38 ( V_145 ) ;
V_9 = V_37 -> V_9 ;
V_39 = V_9 -> V_102 -> V_39 ;
V_59 = F_39 ( V_122 ) ;
V_59 -> V_9 = V_9 ;
V_59 -> V_71 . V_105 = 0 ;
V_59 -> V_71 . V_108 = - V_148 ;
V_59 -> V_149 = V_37 -> V_35 ;
F_40 ( & V_9 -> V_63 , V_147 ) ;
if ( ! F_41 ( & V_37 -> V_150 ) ) {
V_108 = - V_151 ;
goto V_152;
}
switch ( V_9 -> V_111 ) {
case V_5 :
case V_4 :
case V_6 :
V_108 = 0 ;
break;
default:
F_11 ( V_9 , L_29 ,
V_9 -> V_111 ) ;
V_108 = - V_47 ;
goto V_152;
}
F_42 ( & V_59 -> V_153 , & V_37 -> V_150 ) ;
F_11 ( V_9 , L_30 ,
V_37 -> V_154 , V_37 -> V_35 ? L_31 : L_32 ,
V_59 -> V_71 . V_106 ) ;
F_3 ( V_9 -> V_13 , 0 ) ;
if ( V_9 -> V_111 == V_4 )
F_22 ( V_9 ) ;
else if ( V_9 -> V_111 == V_6 ) {
if ( V_59 -> V_71 . V_106 )
V_108 = - V_47 ;
else {
V_9 -> V_111 = V_7 ;
F_15 ( V_39 , V_115 ,
V_9 -> V_114 | V_112 ) ;
V_9 -> V_114 = 0 ;
F_8 ( V_37 -> V_9 , V_122 ) ;
}
} else if ( V_9 -> V_114 ) {
F_15 ( V_39 , V_115 , V_9 -> V_114 ) ;
V_9 -> V_114 = 0 ;
}
V_152:
F_43 ( & V_9 -> V_63 , V_147 ) ;
return V_108 ;
}
static int F_44 ( struct V_143 * V_37 , struct V_58 * V_59 )
{
return - V_47 ;
}
static int F_45 ( struct V_143 * V_145 , int V_155 )
{
struct V_36 * V_37 ;
struct V_9 * V_9 ;
void T_2 * V_156 , * V_39 ;
unsigned long V_157 ;
int V_108 ;
T_3 V_72 ;
if ( ! V_145 || ! V_155 )
return - V_47 ;
V_37 = F_38 ( V_145 ) ;
V_9 = V_37 -> V_9 ;
V_156 = V_9 -> V_13 ;
V_39 = V_9 -> V_102 -> V_39 ;
V_108 = 0 ;
F_40 ( & V_9 -> V_63 , V_157 ) ;
if ( ! F_41 ( & V_37 -> V_150 ) ) {
V_108 = - V_151 ;
goto V_152;
}
F_3 ( V_156 , 0 ) ;
V_72 = V_9 -> V_114 ;
switch ( V_9 -> V_111 ) {
case V_4 :
case V_6 :
case V_5 :
V_72 = F_4 ( V_39 , V_115 ) ;
case V_7 :
case V_8 :
V_72 |= V_113 ;
F_15 ( V_39 , V_115 , V_72 ) ;
V_9 -> V_111 = V_2 ;
V_9 -> V_114 = 0 ;
break;
default:
F_11 ( V_9 , L_33 , V_9 -> V_111 ) ;
V_108 = - V_47 ;
}
V_152:
F_43 ( & V_9 -> V_63 , V_157 ) ;
return V_108 ;
}
