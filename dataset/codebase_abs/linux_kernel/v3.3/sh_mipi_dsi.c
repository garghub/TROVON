static struct V_1 * F_1 ( int V_2 )
{
if ( V_2 >= F_2 ( V_3 ) || V_2 < 0 )
return NULL ;
return V_3 [ V_2 ] ;
}
static int F_3 ( struct V_1 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_2 V_8 = ( V_5 << 24 ) | ( V_6 << 16 ) | ( V_7 << 8 ) ;
int V_9 = 100 ;
F_4 ( 1 | V_8 , V_4 -> V_10 + V_11 ) ;
F_4 ( 1 , V_4 -> V_10 + V_12 ) ;
while ( ( F_5 ( V_4 -> V_10 + V_12 ) & 1 ) && -- V_9 )
F_6 ( 1 ) ;
return V_9 ? 0 : - V_13 ;
}
static int F_7 ( int V_2 , T_1 V_6 )
{
struct V_1 * V_4 = F_1 ( F_8 ( V_2 ) ) ;
if ( ! V_4 )
return - V_14 ;
return F_3 ( V_4 , V_15 , V_6 , 0 ) ;
}
static int F_9 ( int V_2 , T_1 V_6 , T_1 V_7 )
{
struct V_1 * V_4 = F_1 ( F_8 ( V_2 ) ) ;
if ( ! V_4 )
return - V_14 ;
return F_3 ( V_4 , V_16 , V_6 ,
V_7 ) ;
}
static void F_10 ( struct V_1 * V_4 , bool V_17 )
{
F_4 ( 0x00000002 | V_17 , V_4 -> V_10 + V_18 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_12 ( V_20 ) ;
F_10 ( V_4 , false ) ;
}
static int T_3 F_13 ( struct V_1 * V_4 ,
struct V_21 * V_22 )
{
void T_4 * V_23 = V_4 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
T_2 V_27 , V_28 , V_29 , V_30 , V_31 ;
T_2 V_32 , V_33 , V_34 , V_35 , div ;
bool V_36 ;
int V_37 ;
switch ( V_22 -> V_38 ) {
case V_39 :
V_27 = 0 ;
V_28 = V_40 ;
V_29 = V_41 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 3 ;
V_36 = false ;
break;
case V_44 :
V_27 = 1 ;
V_28 = V_45 ;
V_29 = V_46 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 2 ;
V_36 = false ;
break;
case V_47 :
V_27 = 2 ;
V_28 = V_48 ;
V_29 = V_41 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 3 ;
V_36 = false ;
break;
case V_49 :
V_27 = 3 ;
V_28 = V_50 ;
V_29 = V_51 ;
V_30 = ( V_25 -> V_42 [ 0 ] . V_43 * 18 + 7 ) / 8 ;
V_36 = false ;
break;
case V_52 :
V_27 = 8 ;
V_28 = V_40 ;
V_29 = V_41 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 3 ;
V_36 = false ;
break;
case V_53 :
V_27 = 9 ;
V_28 = V_45 ;
V_29 = V_46 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 2 ;
V_36 = false ;
break;
case V_54 :
V_27 = 0xa ;
V_28 = V_48 ;
V_29 = V_41 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 3 ;
V_36 = false ;
break;
case V_55 :
V_27 = 0xb ;
V_28 = V_50 ;
V_29 = V_51 ;
V_30 = ( V_25 -> V_42 [ 0 ] . V_43 * 18 + 7 ) / 8 ;
V_36 = false ;
break;
case V_56 :
V_27 = 4 ;
V_28 = V_57 ;
V_29 = V_46 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 2 ;
V_36 = true ;
break;
case V_58 :
V_27 = 5 ;
V_28 = V_57 ;
V_29 = V_46 ;
V_30 = V_25 -> V_42 [ 0 ] . V_43 * 2 ;
V_36 = true ;
break;
case V_59 :
V_27 = 6 ;
V_28 = V_60 ;
V_29 = V_61 ;
V_30 = ( V_25 -> V_42 [ 0 ] . V_43 * 12 + 7 ) / 8 ;
V_36 = true ;
break;
case V_62 :
V_27 = 7 ;
V_28 = V_60 ;
V_29 = V_61 ;
V_30 = ( V_25 -> V_42 [ 0 ] . V_43 + 1 ) / 2 ;
V_36 = true ;
break;
default:
return - V_63 ;
}
if ( ( V_36 && V_25 -> V_64 != V_65 ) ||
( ! V_36 && V_25 -> V_64 != V_66 ) )
return - V_63 ;
if ( ! V_22 -> V_67 )
return - V_63 ;
F_4 ( 0x00000001 , V_23 + V_68 ) ;
F_6 ( 50 ) ;
F_4 ( 0x00000000 , V_23 + V_68 ) ;
F_4 ( 0x70003332 , V_23 + V_69 ) ;
F_4 ( 0x00000000 , V_23 + V_70 ) ;
F_4 ( 0x00000100 , V_23 + V_71 ) ;
F_4 ( 0x0fffffff , V_23 + V_72 ) ;
F_4 ( 0x0fffffff , V_23 + V_73 ) ;
F_4 ( 0x0fffffff , V_23 + V_74 ) ;
F_4 ( 0x0fffffff , V_23 + V_75 ) ;
F_4 ( 0 , V_23 + V_76 ) ;
F_4 ( 0x00000001 , V_23 + V_77 ) ;
F_6 ( 200 ) ;
F_4 ( 0x03070001 , V_23 + V_77 ) ;
F_14 ( ( unsigned long * ) & V_32 , V_22 -> V_67 ) ;
V_32 |= 0x00003700 ;
F_4 ( V_32 , V_23 + V_78 ) ;
F_4 ( 0x00000006 , V_4 -> V_10 + V_18 ) ;
F_4 ( ( V_25 -> V_42 [ 0 ] . V_79 << V_22 -> V_80 ) |
( V_22 -> V_81 << 16 ) | ( V_27 << 12 ) | V_28 ,
V_4 -> V_10 + V_82 ) ;
V_31 = 0 ;
if ( V_22 -> V_83 & V_84 )
V_31 |= 1 << 23 ;
if ( V_22 -> V_83 & V_85 )
V_31 |= 1 << 22 ;
if ( V_22 -> V_83 & V_86 )
V_31 |= 1 << 21 ;
if ( V_22 -> V_83 & V_87 )
V_31 |= 1 << 17 ;
if ( V_22 -> V_83 & V_88 )
V_31 |= 1 << 5 ;
if ( V_22 -> V_83 & V_89 )
V_31 |= 1 << 4 ;
if ( V_22 -> V_83 & V_90 )
V_31 |= 1 << 3 ;
F_4 ( V_31 , V_4 -> V_10 + V_91 ) ;
V_33 = V_30 << 16 ;
V_34 = 0x00000001 ;
if ( V_22 -> V_83 & V_88 )
V_34 = ( V_22 -> V_67 * V_25 -> V_42 [ 0 ] . V_92 ) - 10 ;
F_4 ( V_33 | V_34 , V_4 -> V_10 + V_93 ) ;
V_33 = 0x00010000 ;
V_34 = 0x00000001 ;
V_35 = 0 ;
div = 1 ;
if ( V_22 -> V_83 & V_94 )
div = 2 ;
if ( V_22 -> V_83 & V_90 ) {
V_33 = V_25 -> V_42 [ 0 ] . V_92 + V_25 -> V_42 [ 0 ] . V_95 ;
V_33 = ( ( V_22 -> V_67 * V_33 / div ) - 10 ) << 16 ;
}
if ( V_22 -> V_83 & V_89 ) {
V_34 = V_25 -> V_42 [ 0 ] . V_96 ;
V_34 = ( V_22 -> V_67 * V_34 / div ) - 12 ;
}
V_37 = V_30 / V_25 -> V_42 [ 0 ] . V_43 ;
if ( ( V_22 -> V_67 / div ) > V_37 ) {
V_32 = V_25 -> V_42 [ 0 ] . V_43 / V_37 ;
V_32 = V_25 -> V_42 [ 0 ] . V_43 - V_32 ;
V_35 = ( V_22 -> V_67 * V_32 ) ;
}
F_4 ( V_33 | ( V_34 + V_35 ) , V_4 -> V_10 + V_97 ) ;
F_15 ( 5 ) ;
F_7 ( V_25 -> V_98 , V_99 ) ;
F_15 ( 120 ) ;
F_9 ( V_25 -> V_98 , V_100 , 0x00 ) ;
F_9 ( V_25 -> V_98 , V_101 ,
V_29 << 4 ) ;
F_7 ( V_25 -> V_98 , V_102 ) ;
F_4 ( 0x00000f00 , V_23 + V_103 ) ;
return 0 ;
}
static void F_16 ( void * V_104 , struct V_105 * V_106 )
{
struct V_1 * V_4 = V_104 ;
struct V_21 * V_22 = V_4 -> V_20 -> V_107 . V_108 ;
int V_109 ;
F_17 ( & V_4 -> V_20 -> V_107 ) ;
V_109 = V_22 -> V_110 ( V_4 -> V_20 , V_4 -> V_23 , 1 ) ;
if ( V_109 < 0 )
goto V_111;
V_109 = F_13 ( V_4 , V_22 ) ;
if ( V_109 < 0 )
goto V_112;
F_10 ( V_4 , true ) ;
if ( V_4 -> V_113 )
V_4 -> V_113 ( V_4 -> V_114 , V_106 ) ;
return;
V_111:
F_18 ( & V_4 -> V_20 -> V_107 ) ;
V_112:
V_22 -> V_110 ( V_4 -> V_20 , V_4 -> V_23 , 0 ) ;
}
static void F_19 ( void * V_104 )
{
struct V_1 * V_4 = V_104 ;
struct V_21 * V_22 = V_4 -> V_20 -> V_107 . V_108 ;
if ( V_4 -> V_115 )
V_4 -> V_115 ( V_4 -> V_114 ) ;
F_10 ( V_4 , false ) ;
V_22 -> V_110 ( V_4 -> V_20 , V_4 -> V_23 , 0 ) ;
F_18 ( & V_4 -> V_20 -> V_107 ) ;
}
static int T_3 F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_4 ;
struct V_21 * V_22 = V_20 -> V_107 . V_108 ;
struct V_116 * V_117 = F_21 ( V_20 , V_118 , 0 ) ;
struct V_116 * V_119 = F_21 ( V_20 , V_118 , 1 ) ;
unsigned long V_120 , V_121 ;
int V_122 = V_20 -> V_123 , V_109 ;
if ( ! V_117 || ! V_119 || V_122 >= F_2 ( V_3 ) || ! V_22 )
return - V_14 ;
if ( ! V_22 -> V_110 )
return - V_63 ;
F_22 ( & V_124 ) ;
if ( V_122 < 0 )
for ( V_122 = 0 ; V_122 < F_2 ( V_3 ) && V_3 [ V_122 ] ; V_122 ++ )
;
if ( V_122 == F_2 ( V_3 ) ) {
V_109 = - V_125 ;
goto V_126;
}
V_4 = F_23 ( sizeof( * V_4 ) , V_127 ) ;
if ( ! V_4 ) {
V_109 = - V_128 ;
goto V_129;
}
if ( ! F_24 ( V_117 -> V_130 , F_25 ( V_117 ) , V_20 -> V_131 ) ) {
F_26 ( & V_20 -> V_107 , L_1 ) ;
V_109 = - V_125 ;
goto V_132;
}
V_4 -> V_23 = F_27 ( V_117 -> V_130 , F_25 ( V_117 ) ) ;
if ( ! V_4 -> V_23 ) {
V_109 = - V_128 ;
goto V_133;
}
if ( ! F_24 ( V_119 -> V_130 , F_25 ( V_119 ) , V_20 -> V_131 ) ) {
F_26 ( & V_20 -> V_107 , L_2 ) ;
V_109 = - V_125 ;
goto V_134;
}
V_4 -> V_10 = F_27 ( V_119 -> V_130 , F_25 ( V_119 ) ) ;
if ( ! V_4 -> V_10 ) {
V_109 = - V_128 ;
goto V_135;
}
V_4 -> V_20 = V_20 ;
V_4 -> V_136 = F_28 ( & V_20 -> V_107 , L_3 ) ;
if ( F_29 ( V_4 -> V_136 ) ) {
V_109 = F_30 ( V_4 -> V_136 ) ;
goto V_137;
}
V_121 = F_31 ( V_4 -> V_136 ) ;
V_120 = F_32 ( V_4 -> V_136 , 80000000 ) ;
if ( V_120 > 0 && V_120 != V_121 )
V_109 = F_33 ( V_4 -> V_136 , V_120 ) ;
else
V_109 = V_120 ;
if ( V_109 < 0 )
goto V_138;
F_34 ( & V_20 -> V_107 , L_4 , V_121 , V_120 ) ;
V_109 = F_35 ( V_4 -> V_136 ) ;
if ( V_109 < 0 )
goto V_139;
V_3 [ V_122 ] = V_4 ;
F_36 ( & V_20 -> V_107 ) ;
F_37 ( & V_20 -> V_107 ) ;
F_38 ( & V_124 ) ;
F_39 ( V_20 , V_4 ) ;
V_4 -> V_114 = V_22 -> V_26 -> V_140 . V_141 ;
V_4 -> V_113 = V_22 -> V_26 -> V_140 . V_142 ;
V_4 -> V_115 = V_22 -> V_26 -> V_140 . V_143 ;
V_22 -> V_26 -> V_140 . V_141 = V_4 ;
V_22 -> V_26 -> V_140 . V_142 = F_16 ;
V_22 -> V_26 -> V_140 . V_143 = F_19 ;
V_22 -> V_26 -> V_140 . V_144 = V_145 ;
return 0 ;
V_139:
V_138:
F_40 ( V_4 -> V_136 ) ;
V_137:
F_41 ( V_4 -> V_10 ) ;
V_135:
F_42 ( V_119 -> V_130 , F_25 ( V_119 ) ) ;
V_134:
F_41 ( V_4 -> V_23 ) ;
V_133:
F_42 ( V_117 -> V_130 , F_25 ( V_117 ) ) ;
V_132:
F_43 ( V_4 ) ;
V_129:
V_126:
F_38 ( & V_124 ) ;
return V_109 ;
}
static int T_5 F_44 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_107 . V_108 ;
struct V_116 * V_117 = F_21 ( V_20 , V_118 , 0 ) ;
struct V_116 * V_119 = F_21 ( V_20 , V_118 , 1 ) ;
struct V_1 * V_4 = F_12 ( V_20 ) ;
int V_146 , V_109 ;
F_22 ( & V_124 ) ;
for ( V_146 = 0 ; V_146 < F_2 ( V_3 ) && V_3 [ V_146 ] != V_4 ; V_146 ++ )
;
if ( V_146 == F_2 ( V_3 ) ) {
V_109 = - V_63 ;
} else {
V_109 = 0 ;
V_3 [ V_146 ] = NULL ;
}
F_38 ( & V_124 ) ;
if ( V_109 < 0 )
return V_109 ;
V_22 -> V_26 -> V_140 . V_144 = NULL ;
V_22 -> V_26 -> V_140 . V_142 = NULL ;
V_22 -> V_26 -> V_140 . V_143 = NULL ;
V_22 -> V_26 -> V_140 . V_141 = NULL ;
F_45 ( & V_20 -> V_107 ) ;
F_46 ( V_4 -> V_136 ) ;
F_40 ( V_4 -> V_136 ) ;
F_41 ( V_4 -> V_10 ) ;
if ( V_119 )
F_42 ( V_119 -> V_130 , F_25 ( V_119 ) ) ;
F_41 ( V_4 -> V_23 ) ;
if ( V_117 )
F_42 ( V_117 -> V_130 , F_25 ( V_117 ) ) ;
F_39 ( V_20 , NULL ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_147 , F_20 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_147 ) ;
}
