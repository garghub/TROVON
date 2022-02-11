static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
int V_8 ;
F_2 ( V_2 -> V_9 , L_1 , V_3 ) ;
if ( F_3 ( V_2 -> V_10 ) ) {
V_6 = 0x15 ;
V_5 = 0x0 ;
V_7 = 3 ;
} else {
V_6 = V_11 ;
V_5 = V_12 ;
V_7 = 0 ;
}
V_8 = F_4 ( V_2 -> V_9 , V_6 , V_5 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_2 , __LINE__ ) ;
return;
}
if ( F_3 ( V_2 -> V_10 ) ) {
V_8 = F_6 ( V_2 -> V_9 , 0x11 , 0x00 , 0x2 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_3 , __LINE__ ) ;
goto V_13;
}
}
if ( V_3 )
V_4 |= ( 1 << V_7 ) ;
else
V_4 &= ~ ( 1 << V_7 ) ;
V_8 = F_6 ( V_2 -> V_9 , V_6 , V_5 , V_4 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_3 , __LINE__ ) ;
}
V_13:
if ( F_3 ( V_2 -> V_10 ) ) {
V_8 = F_6 ( V_2 -> V_9 , 0x11 , 0x00 , 0x0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_3 , __LINE__ ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( V_2 -> V_16 ) {
if ( ! V_2 -> V_17 . V_18 &&
! V_2 -> V_19 . V_18 &&
V_2 -> V_20 ) {
V_2 -> V_20 = false ;
F_1 ( V_2 , false ) ;
} else if ( ! V_2 -> V_20 &&
( V_2 -> V_19 . V_18 ||
V_2 -> V_17 . V_18 ) ) {
V_2 -> V_20 = true ;
F_1 ( V_2 , true ) ;
}
}
F_8 ( V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
bool V_21 )
{
if ( V_21 != V_2 -> V_17 . V_18 ) {
F_2 ( V_2 -> V_9 , L_4 , V_21 ) ;
V_2 -> V_17 . V_18 = V_21 ;
F_10 ( & V_2 -> V_22 . V_15 . V_9 -> V_23 , NULL , L_5 ) ;
if ( V_21 ) {
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_26 ,
V_27 ) ;
} else {
F_14 ( & V_2 -> V_26 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
}
}
}
static int F_15 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_19 . V_18 ) {
V_28 = F_16 ( V_2 -> V_29 , V_30 ) ;
if ( V_28 < 0 )
F_5 ( V_2 -> V_9 , L_6 , V_31 ) ;
} else {
V_28 = 0 ;
}
return V_28 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_8 = 0 ;
if ( V_2 -> V_19 . V_32 ) {
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_34 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return 0 ;
}
if ( V_4 & V_35 )
V_8 = 1 ;
else
V_8 = 0 ;
}
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_17 . V_18 ) {
V_28 = F_16 ( V_2 -> V_29 , V_36 ) ;
if ( V_28 < 0 )
F_5 ( V_2 -> V_9 , L_8 , V_31 ) ;
} else {
V_28 = 0 ;
}
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_17 . V_32 ) {
V_37 = F_16 ( V_2 -> V_29 , V_38 ) ;
if ( V_37 < 0 )
F_5 ( V_2 -> V_9 , L_8 , V_31 ) ;
} else {
V_37 = 0 ;
}
return V_37 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_19 . V_32 ) {
V_37 = F_16 ( V_2 -> V_29 , V_39 ) ;
if ( V_37 < 0 )
F_5 ( V_2 -> V_9 , L_8 , V_31 ) ;
} else {
V_37 = 0 ;
}
return V_37 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_4 ;
if ( V_2 -> V_17 . V_32 ) {
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_40 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return 0 ;
}
if ( V_4 & V_41 )
V_8 = 1 ;
else
V_8 = 0 ;
} else {
V_8 = 0 ;
}
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 , bool V_42 )
{
int V_43 = V_44 ;
int V_8 ;
T_1 V_4 ;
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_34 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
if ( V_4 & V_45 )
V_43 = V_46 ;
if ( ! V_42 ) {
F_23 ( 110 ) ;
}
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_40 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
F_2 ( V_2 -> V_9 ,
L_9 , V_31 ,
V_4 ) ;
if ( ( V_4 & V_47 ) && ( V_4 & V_48 ) )
V_43 |= V_49 ;
return V_43 ;
}
static int F_24 ( struct V_1 * V_2 ,
enum V_50 V_51 )
{
int V_8 = 0 ;
V_2 -> V_52 = false ;
switch ( V_51 ) {
case V_53 :
case V_54 :
case V_55 :
F_2 ( V_2 -> V_9 , L_10
L_11 ) ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = true ;
V_2 -> V_59 = 0 ;
break;
case V_60 :
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = true ;
V_2 -> V_59 = 0 ;
break;
case V_61 :
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = true ;
V_2 -> V_59 = 0 ;
break;
case V_62 :
V_2 -> V_56 = V_63 ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 0 ;
break;
case V_64 :
F_2 ( V_2 -> V_9 , L_12 ) ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 1 ;
break;
case V_65 :
V_2 -> V_56 = V_66 ;
F_2 ( V_2 -> V_9 , L_13 , V_51 ,
V_2 -> V_56 ) ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 1 ;
break;
case V_67 :
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = true ;
V_2 -> V_59 = 0 ;
break;
case V_68 :
V_2 -> V_56 = V_69 ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 0 ;
break;
case V_70 :
case V_71 :
V_2 -> V_56 = V_69 ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 1 ;
break;
case V_72 :
if ( V_2 -> V_73 ) {
V_2 -> V_52 = true ;
F_2 ( V_2 -> V_9 , L_14 ) ;
V_2 -> V_56 = V_69 ;
break;
}
case V_74 :
F_5 ( V_2 -> V_9 , L_15 ) ;
V_2 -> V_56 = V_75 ;
V_8 = - V_76 ;
break;
case V_77 :
if ( F_3 ( V_2 -> V_10 ) ) {
V_2 -> V_78 . V_79 = true ;
F_5 ( V_2 -> V_9 , L_16
L_17 ) ;
V_8 = - V_76 ;
break;
}
if ( F_25 ( V_2 -> V_10 ) || F_26 ( V_2 -> V_10 ) ) {
F_2 ( V_2 -> V_9 , L_15 ) ;
V_2 -> V_56 = V_75 ;
F_2 ( V_2 -> V_9 , L_13 ,
V_51 , V_2 -> V_56 ) ;
V_8 = - V_76 ;
break;
}
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_2 -> V_56 = V_57 ;
F_2 ( V_2 -> V_9 , L_13 , V_51 ,
V_2 -> V_56 ) ;
case V_84 :
F_5 ( V_2 -> V_9 , L_18 ) ;
V_2 -> V_56 = V_57 ;
break;
default:
F_5 ( V_2 -> V_9 , L_19 ) ;
V_2 -> V_56 = V_75 ;
V_8 = - V_76 ;
break;
} ;
F_2 ( V_2 -> V_9 , L_13 ,
V_51 , V_2 -> V_56 ) ;
return V_8 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_4 ;
V_8 = F_4 ( V_2 -> V_9 ,
V_85 , V_86 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
if ( F_3 ( V_2 -> V_10 ) ) {
V_8 = F_4 ( V_2 -> V_9 , V_87 ,
V_88 , & V_4 ) ;
} else {
if ( F_25 ( V_2 -> V_10 ) || F_26 ( V_2 -> V_10 ) )
V_8 = F_4 ( V_2 -> V_9 ,
V_87 , V_89 , & V_4 ) ;
}
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
V_4 = ( V_4 & V_90 ) >> 3 ;
V_8 = F_24 ( V_2 ,
(enum V_50 ) V_4 ) ;
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_91 , V_8 ;
T_1 V_4 ;
for ( V_91 = 0 ; V_91 < 10 ; V_91 ++ ) {
F_23 ( 250 ) ;
V_8 = F_4 ( V_2 -> V_9 ,
V_85 , V_86 ,
& V_4 ) ;
F_2 ( V_2 -> V_9 , L_20 ,
V_31 , V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
if ( F_3 ( V_2 -> V_10 ) )
V_8 = F_4 ( V_2 -> V_9 ,
V_87 , V_88 , & V_4 ) ;
else
V_8 = F_4 ( V_2 -> V_9 ,
V_87 , V_89 , & V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return V_8 ;
}
F_2 ( V_2 -> V_9 , L_21 , V_31 ,
V_4 ) ;
V_4 = ( V_4 & V_90 ) >> 3 ;
if ( V_4 )
break;
}
V_8 = F_24 ( V_2 ,
(enum V_50 ) V_4 ) ;
return V_8 ;
}
static int F_29 ( int V_92 )
{
int V_91 ;
if ( V_92 < V_93 [ 0 ] )
return V_94 ;
for ( V_91 = 1 ; V_91 < F_30 ( V_93 ) ; V_91 ++ ) {
if ( V_92 < V_93 [ V_91 ] )
return V_91 - 1 ;
}
V_91 = F_30 ( V_93 ) - 1 ;
if ( V_92 == V_93 [ V_91 ] )
return V_91 ;
else
return - 1 ;
}
static int F_31 ( int V_95 )
{
int V_91 ;
if ( V_95 < V_96 [ 0 ] )
return 0 ;
for ( V_91 = 0 ; V_91 < F_30 ( V_96 ) ; V_91 ++ ) {
if ( V_95 < V_96 [ V_91 ] )
return V_91 - 1 ;
}
V_91 = F_30 ( V_96 ) - 1 ;
if ( V_95 == V_96 [ V_91 ] )
return V_91 ;
else
return - 1 ;
}
static int F_32 ( int V_95 )
{
int V_91 ;
if ( V_95 < V_97 [ 0 ] )
return 0 ;
for ( V_91 = 0 ; V_91 < F_30 ( V_97 ) ; V_91 ++ ) {
if ( V_95 < V_97 [ V_91 ] )
return V_91 - 1 ;
}
V_91 = F_30 ( V_97 ) - 1 ;
if ( V_95 == V_97 [ V_91 ] )
return V_91 ;
else
return - 1 ;
}
static int F_33 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_98 . V_99 ) {
case 100 :
V_2 -> V_56 = V_100 ;
break;
case 200 :
V_2 -> V_56 = V_101 ;
break;
case 300 :
V_2 -> V_56 = V_102 ;
break;
case 400 :
V_2 -> V_56 = V_103 ;
break;
case 500 :
V_2 -> V_56 = V_57 ;
break;
default:
V_2 -> V_56 = V_75 ;
return - 1 ;
break;
} ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_37 , int V_5 )
{
int V_8 = 0 ;
int V_104 , V_105 , V_106 , V_107 , V_91 ;
T_1 V_108 ;
T_2 V_109 ;
bool V_110 = false ;
F_35 ( & V_2 -> V_111 ) ;
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_5 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_22 , V_31 ) ;
goto V_112;
}
switch ( V_5 ) {
case V_113 :
V_107 = V_114 ;
V_106 = ( V_108 >> V_107 ) ;
V_105 = F_31 ( V_37 ) ;
V_109 = V_115 ;
if ( ! V_2 -> V_19 . V_18 )
V_110 = true ;
break;
case V_116 :
V_107 = V_117 ;
V_106 = ( V_108 >> V_107 ) ;
V_105 = F_32 ( V_37 ) ;
V_109 = V_115 * 100 ;
V_8 = F_4 ( V_2 -> V_9 , V_33 ,
V_118 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_22 , V_31 ) ;
goto V_112;
}
V_104 =
V_108 >> V_119 ;
F_2 ( V_2 -> V_9 , L_23 ,
V_31 ,
V_97 [ V_104 ] ) ;
V_106 = F_36 ( V_106 , V_104 ) ;
if ( ! V_2 -> V_17 . V_18 )
V_110 = true ;
break;
case V_120 :
V_107 = 0 ;
V_106 = ( V_108 >> V_107 ) ;
V_105 = F_31 ( V_37 ) ;
V_109 = V_115 ;
if ( V_105 && ( V_105 - V_106 ) > 1 )
V_109 *= 100 ;
if ( ! V_2 -> V_17 . V_18 && ! V_2 -> V_19 . V_18 )
V_110 = true ;
break;
default:
F_5 ( V_2 -> V_9 , L_24 , V_31 ) ;
V_8 = - V_76 ;
goto V_112;
}
if ( V_105 < 0 ) {
F_5 ( V_2 -> V_9 , L_25 ) ;
V_8 = - V_76 ;
goto V_112;
}
if ( V_106 == V_105 ) {
F_2 ( V_2 -> V_9 , L_26 ,
V_31 , V_5 ) ;
V_8 = 0 ;
goto V_112;
}
F_2 ( V_2 -> V_9 , L_27 ,
V_31 , V_37 , V_5 ) ;
if ( V_110 ) {
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_5 , ( T_1 ) V_105 << V_107 ) ;
if ( V_8 )
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
} else if ( V_106 > V_105 ) {
for ( V_91 = V_106 - 1 ; V_91 >= V_105 ; V_91 -- ) {
F_2 ( V_2 -> V_9 , L_29 ,
( T_1 ) V_91 << V_107 , V_5 ) ;
V_8 = F_6 ( V_2 -> V_9 ,
V_33 , V_5 , ( T_1 ) V_91 << V_107 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
goto V_112;
}
if ( V_91 != V_105 )
F_37 ( V_109 , V_109 * 2 ) ;
}
} else {
for ( V_91 = V_106 + 1 ; V_91 <= V_105 ; V_91 ++ ) {
F_2 ( V_2 -> V_9 , L_30 ,
( T_1 ) V_91 << V_107 , V_5 ) ;
V_8 = F_6 ( V_2 -> V_9 ,
V_33 , V_5 , ( T_1 ) V_91 << V_107 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
goto V_112;
}
if ( V_91 != V_105 )
F_37 ( V_109 , V_109 * 2 ) ;
}
}
V_112:
F_38 ( & V_2 -> V_111 ) ;
return V_8 ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_121 )
{
int V_122 ;
int V_8 ;
V_122 = F_36 ( V_2 -> V_123 -> V_124 -> V_125 , V_121 ) ;
switch ( V_122 ) {
case 100 :
if ( V_2 -> V_126 < V_127 )
V_122 = V_75 ;
break;
case 500 :
if ( V_2 -> V_126 < V_127 )
V_122 = V_128 ;
break;
default:
break;
}
F_40 ( V_2 -> V_9 , L_31 , V_122 ) ;
F_11 ( & V_2 -> V_129 ) ;
V_8 = F_34 ( V_2 , V_122 ,
V_116 ) ;
F_12 ( & V_2 -> V_129 ) ;
return V_8 ;
}
static int F_41 ( struct V_1 * V_2 ,
int V_121 )
{
return F_34 ( V_2 , V_121 ,
V_113 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_130 )
{
return F_34 ( V_2 , V_130 ,
V_120 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_131 )
{
int V_8 ;
if ( V_131 ) {
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_132 ,
( V_133 | V_134 ) ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_32 ) ;
return V_8 ;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_135 ,
V_136 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_33 ) ;
return V_8 ;
}
} else {
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_132 ,
V_137 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_34 ) ;
return V_8 ;
}
}
return V_8 ;
}
static int F_44 ( struct V_138 * V_139 ,
int V_140 , int V_141 , int V_142 )
{
int V_8 ;
int V_143 ;
int V_105 ;
int V_144 ;
T_1 V_145 = 0 ;
struct V_1 * V_2 = F_45 ( V_139 ) ;
if ( V_140 ) {
if ( ! V_2 -> V_19 . V_18 ) {
F_5 ( V_2 -> V_9 , L_35 ) ;
return - V_76 ;
}
F_2 ( V_2 -> V_9 , L_36 , V_141 , V_142 ) ;
if ( ! V_2 -> V_146 ) {
F_46 ( V_2 -> V_147 ) ;
V_2 -> V_146 = true ;
}
V_143 = F_29 ( V_141 ) ;
V_105 = F_31 ( V_142 ) ;
V_144 = F_31 (
V_2 -> V_123 -> V_124 -> V_148 ) ;
if ( V_143 < 0 || V_105 < 0 || V_144 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_37
L_38 ) ;
return - V_76 ;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_149 , ( T_1 ) V_143 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
return V_8 ;
}
V_8 = F_41 ( V_2 ,
V_2 -> V_123 -> V_124 -> V_148 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_39 ,
V_31 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 , V_142 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_40
L_41 ,
V_31 ) ;
return V_8 ;
}
if ( ! V_2 -> V_123 -> V_150 )
V_145 = V_151 ;
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_152 , V_153 | V_145 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
return V_8 ;
}
V_8 = F_43 ( V_2 , true ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_42 ) ;
V_2 -> V_19 . V_32 = 1 ;
} else {
if ( F_47 ( V_2 -> V_10 ) ) {
if ( V_2 -> V_154 ) {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_155 ,
F_48 ( V_156 ) ) ;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_149 , V_157 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_28 , V_31 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 , 0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_40
L_41 ,
V_31 ) ;
return V_8 ;
}
} else {
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_152 , 0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_28 , V_31 ) ;
return V_8 ;
}
}
V_8 = F_43 ( V_2 , false ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_43 ) ;
V_2 -> V_19 . V_32 = 0 ;
V_2 -> V_19 . V_158 = false ;
if ( V_2 -> V_146 ) {
F_49 ( V_2 -> V_147 ) ;
V_2 -> V_146 = false ;
}
F_2 ( V_2 -> V_9 , L_44 , V_31 ) ;
}
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
return V_8 ;
}
static int F_50 ( struct V_138 * V_139 ,
int V_140 , int V_141 , int V_130 )
{
int V_8 ;
int V_143 ;
int V_105 ;
T_1 V_145 = 0 ;
struct V_1 * V_2 = F_51 ( V_139 ) ;
if ( V_140 ) {
if ( ! V_2 -> V_17 . V_18 ) {
F_5 ( V_2 -> V_9 , L_45 ) ;
return - V_76 ;
}
if ( ! V_2 -> V_160 ) {
F_46 ( V_2 -> V_147 ) ;
V_2 -> V_160 = true ;
}
F_2 ( V_2 -> V_9 , L_46 , V_141 , V_130 ) ;
V_143 = F_29 ( V_141 ) ;
V_105 = F_31 ( V_130 ) ;
if ( V_143 < 0 || V_105 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_37
L_38 ) ;
return - V_76 ;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_149 , ( T_1 ) V_143 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
return V_8 ;
}
if ( ! V_2 -> V_123 -> V_150 )
V_145 = V_161 ;
F_2 ( V_2 -> V_9 ,
L_47 ) ;
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_162 , V_163 | V_145 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
return V_8 ;
}
V_8 = F_43 ( V_2 , true ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_42 ) ;
V_2 -> V_17 . V_32 = 1 ;
V_8 = F_39 ( V_2 , V_2 -> V_56 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_48 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 , V_130 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_40
L_41 ,
V_31 ) ;
return V_8 ;
}
F_13 ( V_2 -> V_25 , & V_2 -> V_164 , V_27 ) ;
} else {
F_2 ( V_2 -> V_9 , L_49 , V_31 ) ;
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_162 , 0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_28 , V_31 ) ;
return V_8 ;
}
V_8 = F_43 ( V_2 , false ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_43 ) ;
V_8 = F_39 ( V_2 , 0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_48 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 , 0 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_40
L_50 ,
V_31 ) ;
return V_8 ;
}
V_2 -> V_17 . V_32 = 0 ;
V_2 -> V_17 . V_158 = false ;
if ( V_2 -> V_160 ) {
F_49 ( V_2 -> V_147 ) ;
V_2 -> V_160 = false ;
}
F_2 ( V_2 -> V_9 , L_49 , V_31 ) ;
if ( F_52 ( & V_2 -> V_164 ) )
F_53 ( & V_2 -> V_164 ) ;
}
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
return V_8 ;
}
static int F_54 ( struct V_138 * V_139 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( V_139 -> V_15 . type == V_165 )
V_2 = F_45 ( V_139 ) ;
else if ( V_139 -> V_15 . type == V_166 )
V_2 = F_51 ( V_139 ) ;
else
return - V_76 ;
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_167 , V_168 ) ;
if ( V_8 )
F_5 ( V_2 -> V_9 , L_51 ) ;
return V_8 ;
}
static int F_55 ( struct V_138 * V_139 ,
int V_130 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( V_139 -> V_15 . type == V_165 )
V_2 = F_45 ( V_139 ) ;
else if ( V_139 -> V_15 . type == V_166 )
V_2 = F_51 ( V_139 ) ;
else
return - V_76 ;
V_8 = F_42 ( V_2 , V_130 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_40
L_41 ,
V_31 ) ;
return V_8 ;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_169 ,
0x1 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_28 , V_31 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_56 ( struct V_170 * V_9 , void * V_171 )
{
struct V_14 * V_15 ;
struct V_14 * V_172 ;
struct V_1 * V_2 ;
union V_173 V_8 ;
int V_91 , V_174 ;
bool V_175 = false ;
struct V_138 * V_22 ;
V_22 = (struct V_138 * ) V_171 ;
V_15 = & V_22 -> V_15 ;
V_2 = F_51 ( V_22 ) ;
V_172 = F_57 ( V_9 ) ;
for ( V_91 = 0 ; V_91 < V_172 -> V_176 ; V_91 ++ ) {
if ( ! strcmp ( V_172 -> V_177 [ V_91 ] , V_15 -> V_178 ) )
V_175 = true ;
}
if ( ! V_175 )
return 0 ;
for ( V_174 = 0 ; V_174 < V_172 -> V_179 ; V_174 ++ ) {
enum V_180 V_181 ;
V_181 = V_172 -> V_182 [ V_174 ] ;
if ( V_172 -> V_183 ( V_172 , V_181 , & V_8 ) )
continue;
switch ( V_181 ) {
case V_184 :
switch ( V_172 -> type ) {
case V_185 :
V_2 -> V_126 = V_8 . V_186 / 1000 ;
break;
default:
break;
}
break;
default:
break;
}
}
return 0 ;
}
static void F_58 ( struct V_187 * V_188 )
{
int V_189 = 10 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_164 . V_188 ) ;
F_60 ( V_190 , NULL ,
& V_2 -> V_22 . V_15 , F_56 ) ;
if ( V_2 -> V_191 == 0 )
V_2 -> V_191 = V_2 -> V_126 ;
if ( ! ( ( V_2 -> V_191 <= V_127 &&
V_2 -> V_126 <= V_127 ) ||
( V_2 -> V_191 > V_127 &&
V_2 -> V_126 > V_127 ) ) ) {
F_2 ( V_2 -> V_9 , L_52
L_53 , V_2 -> V_56 , V_2 -> V_126 ,
V_2 -> V_191 ) ;
F_39 ( V_2 , V_2 -> V_56 ) ;
F_8 ( & V_2 -> V_22 . V_15 ) ;
}
V_2 -> V_191 = V_2 -> V_126 ;
if ( V_2 -> V_126 < ( V_127 + 100 ) &&
( V_2 -> V_126 > ( V_127 - 100 ) ) )
V_189 = 1 ;
F_13 ( V_2 -> V_25 , & V_2 -> V_164 , V_189 * V_27 ) ;
}
static void F_61 ( struct V_187 * V_188 )
{
int V_8 ;
T_1 V_108 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_192 . V_188 ) ;
if ( V_2 -> V_78 . V_193 ) {
V_8 = F_4 ( V_2 -> V_9 ,
V_33 , V_194 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return;
}
if ( ! ( V_108 & V_195 ) ) {
V_2 -> V_78 . V_193 = false ;
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
}
}
if ( V_2 -> V_78 . V_196 ) {
V_8 = F_4 ( V_2 -> V_9 ,
V_33 , V_118 ,
& V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return;
}
if ( ! ( V_108 & V_197 ) ) {
V_2 -> V_78 . V_196 = false ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
}
if ( V_2 -> V_78 . V_193 || V_2 -> V_78 . V_196 ) {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_192 , F_48 ( V_27 ) ) ;
}
}
static void F_62 ( struct V_187 * V_188 )
{
int V_8 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_155 . V_188 ) ;
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_167 , V_168 ) ;
if ( V_8 )
F_5 ( V_2 -> V_9 , L_51 ) ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_155 , F_48 ( V_156 ) ) ;
}
static void F_63 ( struct V_187 * V_188 )
{
int V_8 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_198 ) ;
V_8 = F_22 ( V_2 , false ) ;
if ( V_8 < 0 )
return;
if ( V_8 & V_46 ) {
V_2 -> V_19 . V_18 = 1 ;
V_2 -> V_154 = true ;
} else {
V_2 -> V_19 . V_18 = 0 ;
}
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
F_10 ( & V_2 -> V_159 . V_15 . V_9 -> V_23 , NULL , L_5 ) ;
}
static void F_64 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 ,
V_26 . V_188 ) ;
int V_199 = ( V_200 | V_201 ) ;
int V_8 , V_91 ;
T_1 V_202 ;
for ( V_91 = 0 ; V_91 < 10 ; V_91 ++ ) {
V_8 = F_4 ( V_2 -> V_9 ,
V_33 ,
V_40 ,
& V_202 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_54 , __LINE__ ) ;
goto V_203;
}
if ( ( V_202 & V_199 ) != V_199 )
goto V_203;
F_23 ( V_204 ) ;
}
F_50 ( & V_2 -> V_22 , 0 , 0 , 0 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
return;
V_203:
F_13 ( V_2 -> V_25 ,
& V_2 -> V_26 ,
V_27 ) ;
}
static void F_65 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 ,
V_205 . V_188 ) ;
int V_206 = ( V_207 |
V_208 ) ;
int V_8 , V_91 ;
T_1 V_202 ;
for ( V_91 = 0 ; V_91 < 10 ; V_91 ++ ) {
V_8 = F_4 ( V_2 -> V_9 ,
V_33 ,
V_194 ,
& V_202 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_54 , __LINE__ ) ;
goto V_203;
}
if ( ( V_202 & V_206 ) != V_206 )
goto V_203;
F_23 ( V_204 ) ;
}
F_44 ( & V_2 -> V_159 , 0 , 0 , 0 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_198 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
return;
V_203:
F_13 ( V_2 -> V_25 ,
& V_2 -> V_205 ,
V_27 ) ;
}
static void F_67 ( struct V_187 * V_188 )
{
int V_8 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_209 ) ;
V_8 = F_22 ( V_2 , false ) ;
if ( V_8 < 0 )
return;
if ( ! ( V_8 & V_49 ) ) {
F_2 ( V_2 -> V_9 , L_55 , V_31 ) ;
V_2 -> V_73 = false ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
} else {
F_2 ( V_2 -> V_9 , L_56 , V_31 ) ;
V_2 -> V_73 = true ;
if ( F_47 ( V_2 -> V_10 ) ) {
V_8 = F_28 ( V_2 ) ;
if ( ! V_8 ) {
F_9 ( V_2 , true ) ;
F_7 ( V_2 ,
& V_2 -> V_22 . V_15 ) ;
}
} else {
if ( V_2 -> V_210 ) {
V_2 -> V_210 = false ;
V_8 = F_28 ( V_2 ) ;
if ( ! V_8 ) {
F_9 ( V_2 ,
true ) ;
F_7 ( V_2 ,
& V_2 -> V_22 . V_15 ) ;
}
}
}
}
}
static void F_68 ( struct V_187 * V_188 )
{
struct V_1 * V_2 =
F_59 ( V_188 , struct V_1 , V_211 . V_188 ) ;
int V_8 ;
if ( ! V_2 -> V_17 . V_32 ) {
V_8 = F_39 ( V_2 , V_2 -> V_56 ) ;
if ( V_8 )
return;
}
F_9 ( V_2 , true ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
static void F_69 ( struct V_187 * V_188 )
{
int V_212 ;
int V_8 ;
T_1 V_4 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_213 ) ;
V_212 = F_22 ( V_2 , false ) ;
if ( V_212 < 0 )
return;
V_8 = F_4 ( V_2 -> V_9 , V_87 ,
V_88 , & V_4 ) ;
if ( V_8 >= 0 )
F_2 ( V_2 -> V_9 , L_57 , V_4 ) ;
else
F_2 ( V_2 -> V_9 , L_58 ) ;
if ( V_212 & V_49 ) {
if ( ( ( V_4 & V_90 ) >> 3 ) == V_84 &&
V_2 -> V_214 == 0 ) {
F_2 ( V_2 -> V_9 , L_59 ) ;
F_70 ( V_2 -> V_9 ,
V_33 , V_162 , 0x01 , 0x01 ) ;
F_70 ( V_2 -> V_9 , V_87 ,
V_113 , 0x01 , 0x01 ) ;
V_2 -> V_214 = 1 ;
return;
}
if ( V_2 -> V_214 == 1 ) {
F_2 ( V_2 -> V_9 , L_60 ) ;
F_70 ( V_2 -> V_9 , V_87 ,
V_113 , 0x01 , 0x00 ) ;
V_8 = F_4 ( V_2 -> V_9 , V_87 ,
V_88 , & V_4 ) ;
F_2 ( V_2 -> V_9 , L_61 ,
( V_4 & V_90 ) >> 3 ) ;
V_2 -> V_214 = 2 ;
}
} else {
V_2 -> V_214 = 0 ;
}
if ( ! ( V_212 & V_49 ) ) {
V_2 -> V_73 = false ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
return;
}
F_2 ( V_2 -> V_9 , L_56 , V_31 ) ;
V_2 -> V_73 = true ;
V_8 = F_27 ( V_2 ) ;
if ( V_8 ) {
if ( V_8 == - V_76 ) {
F_9 ( V_2 , false ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
return;
}
if ( V_2 -> V_52 ) {
F_2 ( V_2 -> V_9 ,
L_62
L_63
L_64 ,
V_215 ) ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_211 ,
F_71 ( V_215 ) ) ;
} else if ( V_2 -> V_59 == 1 ) {
V_2 -> V_59 ++ ;
F_2 ( V_2 -> V_9 ,
L_65 ,
V_31 , V_215 ) ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_211 ,
F_71 ( V_215 ) ) ;
} else {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_211 ,
0 ) ;
}
}
static void F_72 ( struct V_187 * V_188 )
{
int V_8 ;
unsigned long V_78 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_216 . V_188 ) ;
if ( ! V_2 -> V_73 ) {
F_2 ( V_2 -> V_9 ,
L_66 ,
V_31 ) ;
return;
}
F_73 ( & V_2 -> V_98 . V_217 , V_78 ) ;
V_2 -> V_98 . V_218 = V_2 -> V_98 . V_219 ;
V_2 -> V_98 . V_99 = V_2 -> V_98 . V_220 ;
F_74 ( & V_2 -> V_98 . V_217 , V_78 ) ;
F_2 ( V_2 -> V_9 , L_67 ,
V_31 , V_2 -> V_98 . V_218 , V_2 -> V_98 . V_99 ) ;
switch ( V_2 -> V_98 . V_218 ) {
case V_221 :
case V_222 :
case V_223 :
case V_224 :
F_9 ( V_2 , false ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
break;
case V_225 :
F_23 ( 1000 ) ;
case V_226 :
if ( ! F_33 ( V_2 ) ) {
V_8 = F_39 ( V_2 ,
V_2 -> V_56 ) ;
if ( V_8 )
return;
F_9 ( V_2 , true ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
break;
default:
break;
} ;
}
static void F_75 ( struct V_187 * V_188 )
{
int V_8 ;
T_1 V_108 ;
bool V_227 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_228 . V_188 ) ;
V_8 = F_4 ( V_2 -> V_9 ,
V_33 , V_118 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return;
}
V_227 = V_2 -> V_78 . V_229 ;
if ( V_108 & V_230 ) {
V_2 -> V_78 . V_229 = true ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_228 , V_27 ) ;
} else {
V_2 -> V_78 . V_229 = false ;
V_2 -> V_78 . V_79 = false ;
}
if ( V_227 != V_2 -> V_78 . V_229 )
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
static void F_76 (
struct V_187 * V_188 )
{
int V_8 ;
T_1 V_108 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_231 ) ;
V_8 = F_4 ( V_2 -> V_9 ,
V_33 , V_194 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return;
}
if ( V_108 & V_232 )
V_2 -> V_78 . V_233 = true ;
else
V_2 -> V_78 . V_233 = false ;
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
}
static void F_77 (
struct V_187 * V_188 )
{
int V_8 ;
T_1 V_108 ;
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_234 ) ;
V_8 = F_4 ( V_2 -> V_9 ,
V_33 , V_118 , & V_108 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_7 , V_31 ) ;
return;
}
if ( V_108 & V_235 )
V_2 -> V_78 . V_236 = true ;
else
V_2 -> V_78 . V_236 = false ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
static T_3 F_78 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_68 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_198 ) ;
F_14 ( & V_2 -> V_205 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
return V_239 ;
}
static T_3 F_79 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_69 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_198 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_24 ) ;
F_13 ( V_2 -> V_25 ,
& V_2 -> V_205 ,
V_27 ) ;
return V_239 ;
}
static T_3 F_80 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_70 ) ;
V_2 -> V_78 . V_193 = true ;
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
F_13 ( V_2 -> V_25 , & V_2 -> V_192 , 0 ) ;
return V_239 ;
}
static T_3 F_81 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 ,
L_71 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_231 ) ;
return V_239 ;
}
static T_3 F_82 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 ,
L_72 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_231 ) ;
return V_239 ;
}
static void F_83 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_59 ( V_188 ,
struct V_1 , V_240 . V_188 ) ;
V_2 -> V_78 . V_241 = false ;
F_6 ( V_2 -> V_9 ,
V_33 , V_169 , 0x01 ) ;
if ( V_2 -> V_17 . V_18 )
F_39 ( V_2 , V_2 -> V_56 ) ;
}
static T_3 F_84 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
V_2 -> V_73 = false ;
F_2 ( V_2 -> V_9 , L_73 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_209 ) ;
return V_239 ;
}
static T_3 F_85 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
V_2 -> V_73 = true ;
F_2 ( V_2 -> V_9 , L_74 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_209 ) ;
return V_239 ;
}
static T_3 F_86 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_75 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_213 ) ;
return V_239 ;
}
static T_3 F_87 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 ,
L_76 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_234 ) ;
return V_239 ;
}
static T_3 F_88 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 ,
L_77 ) ;
F_66 ( V_2 -> V_25 , & V_2 -> V_234 ) ;
return V_239 ;
}
static T_3 F_89 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_78 ) ;
F_13 ( V_2 -> V_25 , & V_2 -> V_228 , 0 ) ;
return V_239 ;
}
static T_3 F_90 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_79 ) ;
if ( V_2 -> V_19 . V_32 ) {
V_2 -> V_19 . V_158 = true ;
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
}
if ( V_2 -> V_17 . V_32 ) {
V_2 -> V_17 . V_158 = true ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
}
return V_239 ;
}
static T_3 F_91 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_80 ) ;
V_2 -> V_78 . V_241 = true ;
F_13 ( V_2 -> V_25 , & V_2 -> V_240 ,
F_48 ( 30 * V_27 ) ) ;
return V_239 ;
}
static T_3 F_92 ( int V_237 , void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_2 ( V_2 -> V_9 , L_81 ) ;
V_2 -> V_78 . V_196 = true ;
F_7 ( V_2 , & V_2 -> V_22 . V_15 ) ;
F_13 ( V_2 -> V_25 , & V_2 -> V_192 , 0 ) ;
return V_239 ;
}
static int F_93 ( struct V_14 * V_15 ,
enum V_180 V_242 ,
union V_173 * V_4 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_45 ( F_94 ( V_15 ) ) ;
switch ( V_242 ) {
case V_243 :
if ( V_2 -> V_78 . V_193 )
V_4 -> V_186 = V_244 ;
else if ( V_2 -> V_19 . V_158 || V_2 -> V_17 . V_158 )
V_4 -> V_186 = V_245 ;
else if ( V_2 -> V_78 . V_233 )
V_4 -> V_186 = V_246 ;
else
V_4 -> V_186 = V_247 ;
break;
case V_248 :
V_4 -> V_186 = V_2 -> V_19 . V_32 ;
break;
case V_249 :
V_4 -> V_186 = V_2 -> V_19 . V_18 ;
break;
case V_184 :
V_8 = F_15 ( V_2 ) ;
if ( V_8 >= 0 )
V_2 -> V_19 . V_250 = V_8 ;
V_4 -> V_186 = V_2 -> V_19 . V_250 * 1000 ;
break;
case V_251 :
V_2 -> V_19 . V_252 = F_17 ( V_2 ) ;
V_4 -> V_186 = V_2 -> V_19 . V_252 ;
break;
case V_253 :
V_8 = F_20 ( V_2 ) ;
if ( V_8 >= 0 )
V_2 -> V_19 . V_254 = V_8 ;
V_4 -> V_186 = V_2 -> V_19 . V_254 * 1000 ;
break;
default:
return - V_255 ;
}
return 0 ;
}
static int F_95 ( struct V_14 * V_15 ,
enum V_180 V_242 ,
union V_173 * V_4 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_51 ( F_94 ( V_15 ) ) ;
switch ( V_242 ) {
case V_243 :
if ( V_2 -> V_78 . V_229 )
V_4 -> V_186 = V_244 ;
else if ( V_2 -> V_19 . V_158 || V_2 -> V_17 . V_158 )
V_4 -> V_186 = V_245 ;
else if ( V_2 -> V_78 . V_236 )
V_4 -> V_186 = V_246 ;
else if ( V_2 -> V_78 . V_196 )
V_4 -> V_186 = V_256 ;
else
V_4 -> V_186 = V_247 ;
break;
case V_248 :
V_4 -> V_186 = V_2 -> V_17 . V_32 ;
break;
case V_249 :
V_4 -> V_186 = V_2 -> V_17 . V_18 ;
break;
case V_184 :
V_8 = F_18 ( V_2 ) ;
if ( V_8 >= 0 )
V_2 -> V_17 . V_250 = V_8 ;
V_4 -> V_186 = V_2 -> V_17 . V_250 * 1000 ;
break;
case V_251 :
V_2 -> V_17 . V_252 = F_21 ( V_2 ) ;
V_4 -> V_186 = V_2 -> V_17 . V_252 ;
break;
case V_253 :
V_8 = F_19 ( V_2 ) ;
if ( V_8 >= 0 )
V_2 -> V_17 . V_254 = V_8 ;
V_4 -> V_186 = V_2 -> V_17 . V_254 * 1000 ;
break;
case V_257 :
if ( V_2 -> V_78 . V_79 )
V_4 -> V_186 = 1 ;
else
V_4 -> V_186 = 0 ;
break;
default:
return - V_255 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( ! F_47 ( V_2 -> V_10 ) ) {
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_258 , V_259 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_82 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_261 , V_262 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_83 ) ;
goto V_260;
}
}
if ( F_97 ( V_2 -> V_10 ) || F_98 ( V_2 -> V_10 ) )
V_8 = F_70 ( V_2 -> V_9 ,
V_33 ,
V_263 ,
V_264 ,
V_264 ) ;
else
V_8 = F_6 ( V_2 -> V_9 ,
V_33 ,
V_263 ,
V_265 | V_264 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 ,
L_84 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_266 , V_267 , V_268 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_85 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_269 ,
V_270 , V_271 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_86 ) ;
goto V_260;
}
F_99 ( 63 ) ;
V_8 = F_6 ( V_2 -> V_9 ,
V_269 ,
V_270 ,
( V_271 | V_272 ) ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_87 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_269 ,
V_270 , V_273 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_88 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_274 , V_275 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_89 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_274 , V_275 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_89 ) ;
goto V_260;
}
V_8 = F_43 ( V_2 , false ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 -> V_9 , L_43 ) ;
goto V_260;
}
V_8 = F_6 ( V_2 -> V_9 ,
V_276 ,
V_277 ,
V_2 -> V_123 -> V_278 |
V_2 -> V_123 -> V_279 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_90 ) ;
goto V_260;
}
F_70 ( V_2 -> V_9 ,
V_276 , V_280 ,
V_281 , V_281 ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_91 , V_31 ) ;
V_260:
return V_8 ;
}
static int F_100 ( struct V_282 * V_283 ,
unsigned long V_284 , void * V_285 )
{
struct V_1 * V_2 =
F_59 ( V_283 , struct V_1 , V_283 ) ;
enum V_286 V_287 ;
unsigned V_288 = * ( ( unsigned * ) V_285 ) ;
if ( ! V_2 )
return V_289 ;
if ( V_284 != V_290 ) {
F_2 ( V_2 -> V_9 , L_92 ) ;
return V_289 ;
}
if ( ( V_2 -> V_98 . V_99 == 2 ) && ( V_288 > 2 ) )
V_287 = V_225 ;
else if ( V_288 == 0 )
V_287 = V_221 ;
else if ( V_288 == 2 )
V_287 = V_223 ;
else if ( V_288 >= 8 )
V_287 = V_226 ;
else
V_287 = V_222 ;
F_2 ( V_2 -> V_9 , L_93 ,
V_31 , V_287 , V_288 ) ;
F_101 ( & V_2 -> V_98 . V_217 ) ;
V_2 -> V_98 . V_219 = V_287 ;
V_2 -> V_98 . V_220 = V_288 ;
F_102 ( & V_2 -> V_98 . V_217 ) ;
F_13 ( V_2 -> V_25 , & V_2 -> V_216 , V_27 / 2 ) ;
return V_291 ;
}
static int F_103 ( struct V_292 * V_293 )
{
int V_8 ;
struct V_1 * V_2 = F_104 ( V_293 ) ;
if ( V_2 -> V_154 && F_47 ( V_2 -> V_10 ) ) {
V_8 = F_6 ( V_2 -> V_9 , V_33 ,
V_167 , V_168 ) ;
if ( V_8 )
F_5 ( V_2 -> V_9 , L_51 ) ;
if ( ! F_52 (
& V_2 -> V_155 ) ) {
F_13 ( V_2 -> V_25 , & V_2 -> V_155 ,
F_48 ( V_156 ) ) ;
}
}
if ( V_2 -> V_78 . V_193 || V_2 -> V_78 . V_196 ) {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_192 , 0 ) ;
}
if ( V_2 -> V_78 . V_241 )
F_13 ( V_2 -> V_25 , & V_2 -> V_240 , 0 ) ;
return 0 ;
}
static int F_105 ( struct V_292 * V_293 ,
T_4 V_218 )
{
struct V_1 * V_2 = F_104 ( V_293 ) ;
if ( F_52 ( & V_2 -> V_192 ) )
F_53 ( & V_2 -> V_192 ) ;
if ( F_52 ( & V_2 -> V_240 ) )
F_53 ( & V_2 -> V_240 ) ;
F_106 ( & V_2 -> V_211 ) ;
F_106 ( & V_2 -> V_26 ) ;
F_106 ( & V_2 -> V_205 ) ;
F_106 ( & V_2 -> V_228 ) ;
F_106 ( & V_2 -> V_164 ) ;
F_106 ( & V_2 -> V_155 ) ;
F_107 ( & V_2 -> V_213 ) ;
F_107 ( & V_2 -> V_198 ) ;
F_107 ( & V_2 -> V_209 ) ;
if ( F_108 ( & V_2 -> V_111 ) )
return - V_294 ;
return 0 ;
}
static int F_109 ( struct V_292 * V_293 )
{
struct V_1 * V_2 = F_104 ( V_293 ) ;
int V_91 , V_237 , V_8 ;
F_44 ( & V_2 -> V_159 , false , 0 , 0 ) ;
F_50 ( & V_2 -> V_22 , false , 0 , 0 ) ;
for ( V_91 = 0 ; V_91 < F_30 ( V_295 ) ; V_91 ++ ) {
V_237 = F_110 ( V_293 , V_295 [ V_91 ] . V_178 ) ;
F_111 ( V_237 , V_2 ) ;
}
V_8 = F_70 ( V_2 -> V_9 ,
V_276 , V_280 , V_281 , 0 ) ;
if ( V_8 < 0 )
F_5 ( V_2 -> V_9 , L_91 , V_31 ) ;
F_112 ( V_2 -> V_296 , & V_2 -> V_283 ) ;
F_113 ( V_2 -> V_296 ) ;
F_114 ( V_2 -> V_25 ) ;
F_115 () ;
if( V_2 -> V_22 . V_297 )
F_116 ( & V_2 -> V_22 . V_15 ) ;
#if ! F_117 ( V_298 )
if( V_2 -> V_159 . V_297 )
F_116 ( & V_2 -> V_159 . V_15 ) ;
#endif
F_118 ( V_293 , NULL ) ;
return 0 ;
}
static int F_119 ( struct V_292 * V_293 )
{
struct V_299 * V_300 = V_293 -> V_9 . V_301 ;
struct V_302 * V_303 = V_293 -> V_9 . V_304 ;
struct V_1 * V_2 ;
int V_237 , V_91 , V_305 , V_8 = 0 , V_306 ;
V_2 = F_120 ( & V_293 -> V_9 , sizeof( * V_2 ) , V_307 ) ;
if ( ! V_2 ) {
F_5 ( & V_293 -> V_9 , L_94 , V_31 ) ;
return - V_308 ;
}
if ( ! V_303 ) {
F_5 ( & V_293 -> V_9 , L_95 ) ;
return - V_255 ;
}
V_2 -> V_123 = V_303 ;
if ( V_300 ) {
V_8 = F_121 ( & V_293 -> V_9 , V_300 , V_2 -> V_123 ) ;
if ( V_8 ) {
F_5 ( & V_293 -> V_9 , L_96 ) ;
return V_8 ;
}
V_2 -> V_16 = F_122 ( V_300 , L_97 ) ;
} else
V_2 -> V_16 = false ;
V_2 -> V_9 = & V_293 -> V_9 ;
V_2 -> V_10 = F_57 ( V_293 -> V_9 . V_10 ) ;
V_2 -> V_29 = F_123 ( L_98 ) ;
F_124 ( & V_2 -> V_98 . V_217 ) ;
F_125 ( & V_2 -> V_129 ) ;
V_2 -> V_20 = false ;
V_2 -> V_214 = 0 ;
V_2 -> V_159 . V_15 . V_178 = L_99 ;
V_2 -> V_159 . V_15 . type = V_165 ;
V_2 -> V_159 . V_15 . V_182 = V_309 ;
V_2 -> V_159 . V_15 . V_179 = F_30 ( V_309 ) ;
V_2 -> V_159 . V_15 . V_183 = F_93 ;
V_2 -> V_159 . V_15 . V_177 = V_310 ;
V_2 -> V_159 . V_15 . V_176 = F_30 ( V_310 ) ,
V_2 -> V_159 . V_311 . V_140 = & F_44 ;
V_2 -> V_159 . V_311 . V_312 = & F_54 ;
V_2 -> V_159 . V_311 . V_313 = & F_55 ;
V_2 -> V_159 . V_314 = V_93 [
F_30 ( V_93 ) - 1 ] ;
V_2 -> V_159 . V_315 = V_96 [
F_30 ( V_96 ) - 1 ] ;
V_2 -> V_159 . V_316 = V_317 ;
V_2 -> V_159 . V_297 = V_2 -> V_123 -> V_318 ;
V_2 -> V_159 . V_319 = false ;
V_2 -> V_22 . V_15 . V_178 = L_100 ;
V_2 -> V_22 . V_15 . type = V_166 ;
V_2 -> V_22 . V_15 . V_182 = V_320 ;
V_2 -> V_22 . V_15 . V_179 = F_30 ( V_320 ) ;
V_2 -> V_22 . V_15 . V_183 = F_95 ;
V_2 -> V_22 . V_15 . V_177 = V_310 ;
V_2 -> V_22 . V_15 . V_176 = F_30 ( V_310 ) ,
V_2 -> V_22 . V_311 . V_140 = & F_50 ;
V_2 -> V_22 . V_311 . V_312 = & F_54 ;
V_2 -> V_22 . V_311 . V_313 = & F_55 ;
V_2 -> V_22 . V_314 = V_93 [
F_30 ( V_93 ) - 1 ] ;
V_2 -> V_22 . V_315 = V_96 [
F_30 ( V_96 ) - 1 ] ;
V_2 -> V_22 . V_316 = V_317 ;
V_2 -> V_22 . V_297 = V_2 -> V_123 -> V_321 ;
V_2 -> V_22 . V_319 = false ;
V_2 -> V_25 =
F_126 ( L_101 ) ;
if ( V_2 -> V_25 == NULL ) {
F_5 ( V_2 -> V_9 , L_102 ) ;
return - V_308 ;
}
F_125 ( & V_2 -> V_24 ) ;
F_127 ( & V_2 -> V_192 ,
F_61 ) ;
F_127 ( & V_2 -> V_228 ,
F_75 ) ;
F_128 ( & V_2 -> V_205 ,
F_65 ) ;
F_128 ( & V_2 -> V_26 ,
F_64 ) ;
F_127 ( & V_2 -> V_155 ,
F_62 ) ;
F_127 ( & V_2 -> V_164 ,
F_58 ) ;
F_128 ( & V_2 -> V_211 ,
F_68 ) ;
F_128 ( & V_2 -> V_216 ,
F_72 ) ;
F_128 ( & V_2 -> V_240 ,
F_83 ) ;
F_129 ( & V_2 -> V_213 ,
F_69 ) ;
F_129 ( & V_2 -> V_198 , F_63 ) ;
F_129 ( & V_2 -> V_209 ,
F_67 ) ;
F_129 ( & V_2 -> V_231 ,
F_76 ) ;
F_129 ( & V_2 -> V_234 ,
F_77 ) ;
V_2 -> V_147 = F_130 ( V_2 -> V_9 , L_103 ) ;
if ( F_131 ( V_2 -> V_147 ) ) {
V_8 = F_132 ( V_2 -> V_147 ) ;
F_5 ( V_2 -> V_9 , L_104 ) ;
goto V_322;
}
V_8 = F_96 ( V_2 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_105 ) ;
goto V_322;
}
if( V_2 -> V_159 . V_297 ) {
V_8 = F_133 ( V_2 -> V_9 , & V_2 -> V_159 . V_15 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_106 ) ;
goto V_322;
}
}
if( V_2 -> V_22 . V_297 ) {
V_8 = F_133 ( V_2 -> V_9 , & V_2 -> V_22 . V_15 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_107 ) ;
goto V_323;
}
}
V_2 -> V_296 = F_134 ( V_324 ) ;
if ( F_135 ( V_2 -> V_296 ) ) {
F_5 ( V_2 -> V_9 , L_108 ) ;
V_8 = - V_255 ;
goto V_325;
}
V_2 -> V_283 . V_326 = F_100 ;
V_8 = F_136 ( V_2 -> V_296 , & V_2 -> V_283 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , L_109 ) ;
goto V_327;
}
V_305 = F_22 ( V_2 , true ) ;
if ( V_305 & V_46 ) {
V_2 -> V_19 . V_18 = 1 ;
V_2 -> V_154 = true ;
F_7 ( V_2 , & V_2 -> V_159 . V_15 ) ;
F_10 ( & V_2 -> V_159 . V_15 . V_9 -> V_23 , NULL , L_5 ) ;
}
if ( V_305 & V_49 ) {
V_2 -> V_73 = true ;
V_2 -> V_210 = true ;
F_66 ( V_2 -> V_25 ,
& V_2 -> V_209 ) ;
}
for ( V_91 = 0 ; V_91 < F_30 ( V_295 ) ; V_91 ++ ) {
V_237 = F_110 ( V_293 , V_295 [ V_91 ] . V_178 ) ;
V_8 = F_137 ( V_237 , NULL , V_295 [ V_91 ] . V_328 ,
V_329 | V_330 ,
V_295 [ V_91 ] . V_178 , V_2 ) ;
if ( V_8 != 0 ) {
F_5 ( V_2 -> V_9 , L_110
, V_295 [ V_91 ] . V_178 , V_237 , V_8 ) ;
goto F_111;
}
F_2 ( V_2 -> V_9 , L_111 ,
V_295 [ V_91 ] . V_178 , V_237 , V_8 ) ;
}
F_118 ( V_293 , V_2 ) ;
F_11 ( & V_2 -> V_24 ) ;
V_306 = F_22 ( V_2 , false ) ;
if ( ( V_306 & V_46 ) == V_46 ) {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_205 ,
V_27 ) ;
}
if ( ( V_306 & V_49 ) == V_49 ) {
F_13 ( V_2 -> V_25 ,
& V_2 -> V_26 ,
V_27 ) ;
}
F_12 ( & V_2 -> V_24 ) ;
return V_8 ;
F_111:
F_112 ( V_2 -> V_296 , & V_2 -> V_283 ) ;
for ( V_91 = V_91 - 1 ; V_91 >= 0 ; V_91 -- ) {
V_237 = F_110 ( V_293 , V_295 [ V_91 ] . V_178 ) ;
F_111 ( V_237 , V_2 ) ;
}
V_327:
F_113 ( V_2 -> V_296 ) ;
V_325:
if( V_2 -> V_22 . V_297 )
F_116 ( & V_2 -> V_22 . V_15 ) ;
V_323:
if( V_2 -> V_159 . V_297 )
F_116 ( & V_2 -> V_159 . V_15 ) ;
V_322:
F_114 ( V_2 -> V_25 ) ;
return V_8 ;
}
static int T_5 F_138 ( void )
{
return F_139 ( & V_331 ) ;
}
static void T_6 F_140 ( void )
{
F_141 ( & V_331 ) ;
}
