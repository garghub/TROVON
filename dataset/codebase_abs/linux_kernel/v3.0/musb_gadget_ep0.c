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
V_15 [ 0 ] = V_9 -> V_21 << V_22 ;
V_15 [ 0 ] |= V_9 -> V_23 << V_24 ;
#ifdef F_3
if ( V_9 -> V_25 . V_26 ) {
V_15 [ 0 ] |= V_9 -> V_25 . V_27
<< V_28 ;
V_15 [ 0 ] |= V_9 -> V_25 . V_29
<< V_30 ;
V_15 [ 0 ] |= V_9 -> V_25 . V_31
<< V_32 ;
}
#endif
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
F_4 ( V_12 , V_16 ) ;
if ( V_35 )
V_38 = F_5 ( V_39 , V_48 )
& V_49 ;
else
V_38 = F_5 ( V_39 , V_50 )
& V_51 ;
F_4 ( V_12 , 0 ) ;
V_15 [ 0 ] = V_38 ? 1 : 0 ;
} break;
default:
V_14 = 0 ;
break;
}
if ( V_14 > 0 ) {
T_3 V_52 = F_6 ( V_11 -> V_53 ) ;
if ( V_52 > 2 )
V_52 = 2 ;
F_7 ( & V_9 -> V_42 [ 0 ] , V_52 , V_15 ) ;
}
return V_14 ;
}
static int
F_8 ( struct V_9 * V_9 , const struct V_10 * V_11 )
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
static void F_9 ( struct V_9 * V_9 , struct V_58 * V_59 )
{
F_10 ( & V_9 -> V_42 [ 0 ] . V_43 , V_59 , 0 ) ;
}
static inline void F_11 ( struct V_9 * V_9 )
{
void T_2 * V_12 = V_9 -> V_13 ;
T_1 V_60 ;
F_12 ( V_9 -> V_61 , L_9 ) ;
V_60 = F_13 ( V_12 , V_62 ) ;
F_14 ( V_12 , V_62 , V_60 | V_63 ) ;
}
static int
F_15 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
__releases( V_9 -> V_64 )
__acquires( V_9 -> V_64 )
{
int V_14 = - V_47 ;
void T_2 * V_12 = V_9 -> V_13 ;
const T_1 V_17 = V_11 -> V_18 & V_19 ;
if ( ( V_11 -> V_18 & V_54 )
== V_55 ) {
switch ( V_11 -> V_56 ) {
case V_65 :
V_9 -> V_66 = true ;
V_9 -> V_67 = ( T_1 ) ( V_11 -> V_68 & 0x7f ) ;
V_14 = 1 ;
break;
case V_69 :
switch ( V_17 ) {
case V_20 :
if ( V_11 -> V_68
!= V_24 )
break;
V_9 -> V_23 = 0 ;
V_14 = 1 ;
break;
case V_33 :
break;
case V_34 : {
const T_1 V_16 =
V_11 -> V_40 & 0x0f ;
struct V_36 * V_36 ;
struct V_70 * V_37 ;
struct V_71 * V_72 ;
void T_2 * V_39 ;
int V_35 ;
T_3 V_73 ;
if ( V_16 == 0 || V_16 >= V_45 ||
V_11 -> V_68 != V_74 )
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
if ( V_36 -> V_75 )
break;
F_4 ( V_12 , V_16 ) ;
if ( V_35 ) {
V_73 = F_5 ( V_39 , V_48 ) ;
V_73 |= V_76 |
V_77 ;
V_73 &= ~ ( V_49 |
V_78 |
V_79 ) ;
F_16 ( V_39 , V_48 , V_73 ) ;
} else {
V_73 = F_5 ( V_39 , V_50 ) ;
V_73 |= V_80 |
V_81 ;
V_73 &= ~ ( V_51 |
V_82 ) ;
F_16 ( V_39 , V_50 , V_73 ) ;
}
V_72 = F_17 ( V_36 ) ;
if ( ! V_36 -> V_83 && V_72 ) {
F_12 ( V_9 -> V_61 , L_10 ) ;
F_18 ( V_9 , V_72 ) ;
}
F_4 ( V_12 , 0 ) ;
} break;
default:
V_14 = 0 ;
break;
}
break;
case V_84 :
switch ( V_17 ) {
case V_20 :
V_14 = 1 ;
switch ( V_11 -> V_68 ) {
case V_24 :
V_9 -> V_23 = 1 ;
break;
case V_85 :
if ( V_9 -> V_25 . V_86 != V_87 )
goto V_88;
if ( V_11 -> V_40 & 0xff )
goto V_88;
switch ( V_11 -> V_40 >> 8 ) {
case 1 :
F_19 ( L_11 ) ;
V_9 -> V_89 =
V_90 ;
break;
case 2 :
F_19 ( L_12 ) ;
V_9 -> V_89 =
V_91 ;
break;
case 3 :
F_19 ( L_13 ) ;
V_9 -> V_89 =
V_92 ;
break;
case 4 :
F_19 ( L_14 ) ;
V_9 -> V_89 =
V_93 ;
break;
case 0xc0 :
F_19 ( L_15 ) ;
V_9 -> V_89 =
V_94 ;
break;
case 0xc1 :
F_19 ( L_16 ) ;
V_9 -> V_89 =
V_95 ;
break;
case 0xc2 :
F_19 ( L_17 ) ;
V_9 -> V_89 =
V_96 ;
break;
case 0xc3 :
F_19 ( L_18 ) ;
V_9 -> V_89 =
V_97 ;
break;
default:
goto V_88;
}
if ( V_14 > 0 )
V_9 -> V_98 = true ;
break;
#ifdef F_3
case V_28 :
if ( ! V_9 -> V_25 . V_26 )
goto V_88;
V_9 -> V_25 . V_27 = 1 ;
F_11 ( V_9 ) ;
break;
case V_32 :
if ( ! V_9 -> V_25 . V_26 )
goto V_88;
V_9 -> V_25 . V_31 = 1 ;
break;
case V_30 :
if ( ! V_9 -> V_25 . V_26 )
goto V_88;
V_9 -> V_25 . V_29 = 1 ;
break;
#endif
case V_99 :
V_14 = 0 ;
break;
V_88:
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
struct V_70 * V_37 ;
void T_2 * V_39 ;
int V_35 ;
T_3 V_73 ;
if ( V_16 == 0 || V_16 >= V_45 ||
V_11 -> V_68 != V_74 )
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
F_4 ( V_12 , V_16 ) ;
if ( V_35 ) {
V_73 = F_5 ( V_39 , V_48 ) ;
if ( V_73 & V_100 )
V_73 |= V_101 ;
V_73 |= V_49
| V_76
| V_77 ;
F_16 ( V_39 , V_48 , V_73 ) ;
} else {
V_73 = F_5 ( V_39 , V_50 ) ;
V_73 |= V_51
| V_102
| V_80
| V_81 ;
F_16 ( V_39 , V_50 , V_73 ) ;
}
F_4 ( V_12 , 0 ) ;
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
static void F_20 ( struct V_9 * V_9 )
{
void T_2 * V_39 = V_9 -> V_103 -> V_39 ;
struct V_71 * V_72 ;
struct V_58 * V_59 ;
T_3 V_104 , V_73 ;
V_72 = F_21 ( V_9 ) ;
V_59 = & V_72 -> V_72 ;
if ( V_59 ) {
void * V_105 = V_59 -> V_105 + V_59 -> V_106 ;
unsigned V_52 = V_59 -> V_107 - V_59 -> V_106 ;
V_104 = F_13 ( V_39 , V_108 ) ;
if ( V_104 > V_52 ) {
V_59 -> V_109 = - V_110 ;
V_104 = V_52 ;
}
F_22 ( & V_9 -> V_42 [ 0 ] , V_104 , V_105 ) ;
V_59 -> V_106 += V_104 ;
V_73 = V_111 ;
if ( V_104 < 64 || V_59 -> V_106 == V_59 -> V_107 ) {
V_9 -> V_112 = V_7 ;
V_73 |= V_113 ;
} else
V_59 = NULL ;
} else
V_73 = V_111 | V_114 ;
if ( V_59 ) {
V_9 -> V_115 = V_73 ;
F_9 ( V_9 , V_59 ) ;
if ( ! V_9 -> V_115 )
return;
V_9 -> V_115 = 0 ;
}
F_4 ( V_9 -> V_13 , 0 ) ;
F_16 ( V_39 , V_116 , V_73 ) ;
}
static void F_23 ( struct V_9 * V_9 )
{
void T_2 * V_39 = V_9 -> V_103 -> V_39 ;
struct V_71 * V_59 = F_21 ( V_9 ) ;
struct V_58 * V_72 ;
T_3 V_73 = V_117 ;
T_1 * V_118 ;
T_1 V_119 ;
if ( ! V_59 ) {
F_12 ( V_9 -> V_61 , L_19 , F_5 ( V_39 , V_116 ) ) ;
return;
}
V_72 = & V_59 -> V_72 ;
V_118 = ( T_1 * ) V_72 -> V_105 + V_72 -> V_106 ;
V_119 = F_24 ( ( unsigned ) V_120 ,
V_72 -> V_107 - V_72 -> V_106 ) ;
F_7 ( & V_9 -> V_42 [ 0 ] , V_119 , V_118 ) ;
V_72 -> V_106 += V_119 ;
if ( V_119 < V_121
|| ( V_72 -> V_106 == V_72 -> V_107
&& ! V_72 -> V_122 ) ) {
V_9 -> V_112 = V_8 ;
V_73 |= V_113 ;
} else
V_72 = NULL ;
if ( V_72 ) {
V_9 -> V_115 = V_73 ;
F_9 ( V_9 , V_72 ) ;
if ( ! V_9 -> V_115 )
return;
V_9 -> V_115 = 0 ;
}
F_4 ( V_9 -> V_13 , 0 ) ;
F_16 ( V_39 , V_116 , V_73 ) ;
}
static void
F_25 ( struct V_9 * V_9 , struct V_10 * V_59 )
{
struct V_71 * V_123 ;
void T_2 * V_39 = V_9 -> V_103 -> V_39 ;
F_22 ( & V_9 -> V_42 [ 0 ] , sizeof *V_59 , ( T_1 * ) V_59 ) ;
F_12 ( V_9 -> V_61 , L_20 ,
V_59 -> V_18 ,
V_59 -> V_56 ,
F_6 ( V_59 -> V_68 ) ,
F_6 ( V_59 -> V_40 ) ,
F_6 ( V_59 -> V_53 ) ) ;
V_123 = F_21 ( V_9 ) ;
if ( V_123 )
F_9 ( V_9 , & V_123 -> V_72 ) ;
V_9 -> V_66 = false ;
V_9 -> V_115 = V_111 ;
if ( V_59 -> V_53 == 0 ) {
if ( V_59 -> V_18 & V_41 )
V_9 -> V_115 |= V_117 ;
V_9 -> V_112 = V_6 ;
} else if ( V_59 -> V_18 & V_41 ) {
V_9 -> V_112 = V_4 ;
F_16 ( V_39 , V_116 , V_111 ) ;
while ( ( F_5 ( V_39 , V_116 )
& V_124 ) != 0 )
F_26 () ;
V_9 -> V_115 = 0 ;
} else
V_9 -> V_112 = V_5 ;
}
static int
F_27 ( struct V_9 * V_9 , const struct V_10 * V_11 )
__releases( V_9 -> V_64 )
__acquires( V_9 -> V_64 )
{
int V_125 ;
if ( ! V_9 -> V_126 )
return - V_127 ;
F_28 ( & V_9 -> V_64 ) ;
V_125 = V_9 -> V_126 -> V_128 ( & V_9 -> V_25 , V_11 ) ;
F_29 ( & V_9 -> V_64 ) ;
return V_125 ;
}
T_4 F_30 ( struct V_9 * V_9 )
{
T_3 V_73 ;
T_3 V_52 ;
void T_2 * V_12 = V_9 -> V_13 ;
void T_2 * V_39 = V_9 -> V_42 [ 0 ] . V_39 ;
T_4 V_125 = V_129 ;
F_4 ( V_12 , 0 ) ;
V_73 = F_5 ( V_39 , V_116 ) ;
V_52 = F_13 ( V_39 , V_108 ) ;
F_12 ( V_9 -> V_61 , L_21 ,
V_73 , V_52 ,
F_13 ( V_12 , V_130 ) ,
F_1 ( V_9 -> V_112 ) ) ;
if ( V_73 & V_131 ) {
F_16 ( V_39 , V_116 ,
V_73 & ~ V_131 ) ;
V_125 = V_132 ;
V_9 -> V_112 = V_2 ;
V_73 = F_5 ( V_39 , V_116 ) ;
}
if ( V_73 & V_133 ) {
F_16 ( V_39 , V_116 , V_134 ) ;
V_125 = V_132 ;
switch ( V_9 -> V_112 ) {
case V_4 :
V_9 -> V_112 = V_8 ;
break;
case V_5 :
V_9 -> V_112 = V_7 ;
break;
default:
F_31 ( L_22 ,
F_1 ( V_9 -> V_112 ) ) ;
}
V_73 = F_5 ( V_39 , V_116 ) ;
}
switch ( V_9 -> V_112 ) {
case V_4 :
if ( ( V_73 & V_117 ) == 0 ) {
F_23 ( V_9 ) ;
V_125 = V_132 ;
}
break;
case V_5 :
if ( V_73 & V_124 ) {
F_20 ( V_9 ) ;
V_125 = V_132 ;
}
break;
case V_7 :
if ( V_9 -> V_66 ) {
V_9 -> V_66 = false ;
F_14 ( V_12 , V_130 , V_9 -> V_67 ) ;
}
else if ( V_9 -> V_98 ) {
F_12 ( V_9 -> V_61 , L_23 ) ;
if ( V_93 == V_9 -> V_89 )
F_32 ( V_9 ) ;
F_14 ( V_12 , V_135 ,
V_9 -> V_89 ) ;
}
case V_8 :
{
struct V_71 * V_59 ;
V_59 = F_21 ( V_9 ) ;
if ( V_59 )
F_9 ( V_9 , & V_59 -> V_72 ) ;
}
if ( V_73 & V_124 )
goto V_128;
V_125 = V_132 ;
V_9 -> V_112 = V_2 ;
break;
case V_2 :
V_125 = V_132 ;
V_9 -> V_112 = V_3 ;
case V_3 :
V_128:
if ( V_73 & V_124 ) {
struct V_10 V_128 ;
int V_14 = 0 ;
if ( V_52 != 8 ) {
F_31 ( L_24 , V_52 ) ;
break;
}
F_25 ( V_9 , & V_128 ) ;
V_125 = V_132 ;
if ( F_33 ( V_9 -> V_25 . V_86 == V_136 ) ) {
T_1 V_137 ;
F_34 ( V_138 L_25
L_26 ,
V_139 ) ;
V_137 = F_13 ( V_12 , V_140 ) ;
V_9 -> V_25 . V_86 = ( V_137 & V_141 )
? V_87 : V_142 ;
}
switch ( V_9 -> V_112 ) {
case V_6 :
V_14 = F_15 (
V_9 , & V_128 ) ;
V_9 -> V_115 |= V_113 ;
if ( V_14 > 0 )
V_9 -> V_112 =
V_7 ;
break;
case V_4 :
V_14 = F_8 ( V_9 , & V_128 ) ;
if ( V_14 > 0 ) {
V_9 -> V_115 = V_117
| V_113 ;
V_9 -> V_112 =
V_8 ;
}
break;
default:
break;
}
F_12 ( V_9 -> V_61 , L_27 ,
V_14 , V_73 ,
F_1 ( V_9 -> V_112 ) ) ;
if ( V_14 < 0 )
goto V_88;
else if ( V_14 > 0 )
goto V_143;
V_14 = F_27 ( V_9 , & V_128 ) ;
if ( V_14 < 0 ) {
F_4 ( V_12 , 0 ) ;
V_88:
F_12 ( V_9 -> V_61 , L_28 , V_14 ) ;
V_9 -> V_115 |= V_114 ;
V_9 -> V_112 = V_2 ;
V_143:
F_16 ( V_39 , V_116 ,
V_9 -> V_115 ) ;
V_9 -> V_115 = 0 ;
}
}
break;
case V_6 :
V_125 = V_132 ;
break;
default:
F_35 ( 1 ) ;
F_16 ( V_39 , V_116 , V_114 ) ;
V_9 -> V_112 = V_2 ;
break;
}
return V_125 ;
}
static int
F_36 ( struct V_144 * V_37 , const struct V_145 * V_46 )
{
return - V_47 ;
}
static int F_37 ( struct V_144 * V_146 )
{
return - V_47 ;
}
static int
F_38 ( struct V_144 * V_146 , struct V_58 * V_123 , T_5 V_147 )
{
struct V_36 * V_37 ;
struct V_71 * V_59 ;
struct V_9 * V_9 ;
int V_109 ;
unsigned long V_148 ;
void T_2 * V_39 ;
if ( ! V_146 || ! V_123 )
return - V_47 ;
V_37 = F_39 ( V_146 ) ;
V_9 = V_37 -> V_9 ;
V_39 = V_9 -> V_103 -> V_39 ;
V_59 = F_40 ( V_123 ) ;
V_59 -> V_9 = V_9 ;
V_59 -> V_72 . V_106 = 0 ;
V_59 -> V_72 . V_109 = - V_149 ;
V_59 -> V_150 = V_37 -> V_35 ;
F_41 ( & V_9 -> V_64 , V_148 ) ;
if ( ! F_42 ( & V_37 -> V_151 ) ) {
V_109 = - V_152 ;
goto V_153;
}
switch ( V_9 -> V_112 ) {
case V_5 :
case V_4 :
case V_6 :
V_109 = 0 ;
break;
default:
F_12 ( V_9 -> V_61 , L_29 ,
V_9 -> V_112 ) ;
V_109 = - V_47 ;
goto V_153;
}
F_43 ( & V_59 -> V_154 , & V_37 -> V_151 ) ;
F_12 ( V_9 -> V_61 , L_30 ,
V_37 -> V_155 , V_37 -> V_35 ? L_31 : L_32 ,
V_59 -> V_72 . V_107 ) ;
F_4 ( V_9 -> V_13 , 0 ) ;
if ( V_9 -> V_112 == V_4 )
F_23 ( V_9 ) ;
else if ( V_9 -> V_112 == V_6 ) {
if ( V_59 -> V_72 . V_107 )
V_109 = - V_47 ;
else {
V_9 -> V_112 = V_7 ;
F_16 ( V_39 , V_116 ,
V_9 -> V_115 | V_113 ) ;
V_9 -> V_115 = 0 ;
F_9 ( V_37 -> V_9 , V_123 ) ;
}
} else if ( V_9 -> V_115 ) {
F_16 ( V_39 , V_116 , V_9 -> V_115 ) ;
V_9 -> V_115 = 0 ;
}
V_153:
F_44 ( & V_9 -> V_64 , V_148 ) ;
return V_109 ;
}
static int F_45 ( struct V_144 * V_37 , struct V_58 * V_59 )
{
return - V_47 ;
}
static int F_46 ( struct V_144 * V_146 , int V_156 )
{
struct V_36 * V_37 ;
struct V_9 * V_9 ;
void T_2 * V_157 , * V_39 ;
unsigned long V_158 ;
int V_109 ;
T_3 V_73 ;
if ( ! V_146 || ! V_156 )
return - V_47 ;
V_37 = F_39 ( V_146 ) ;
V_9 = V_37 -> V_9 ;
V_157 = V_9 -> V_13 ;
V_39 = V_9 -> V_103 -> V_39 ;
V_109 = 0 ;
F_41 ( & V_9 -> V_64 , V_158 ) ;
if ( ! F_42 ( & V_37 -> V_151 ) ) {
V_109 = - V_152 ;
goto V_153;
}
F_4 ( V_157 , 0 ) ;
V_73 = V_9 -> V_115 ;
switch ( V_9 -> V_112 ) {
case V_4 :
case V_6 :
case V_5 :
V_73 = F_5 ( V_39 , V_116 ) ;
case V_7 :
case V_8 :
V_73 |= V_114 ;
F_16 ( V_39 , V_116 , V_73 ) ;
V_9 -> V_112 = V_2 ;
V_9 -> V_115 = 0 ;
break;
default:
F_12 ( V_9 -> V_61 , L_33 , V_9 -> V_112 ) ;
V_109 = - V_47 ;
}
V_153:
F_44 ( & V_9 -> V_64 , V_158 ) ;
return V_109 ;
}
