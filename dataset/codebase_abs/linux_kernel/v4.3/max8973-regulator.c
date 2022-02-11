static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 , int * V_5 )
{
int V_6 ;
bool V_7 = false ;
int V_8 = V_2 -> V_9 [ V_10 - 1 ] ;
int V_11 = V_10 - 1 ;
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_2 -> V_9 [ V_6 ] ] == V_3 ) {
V_8 = V_2 -> V_9 [ V_6 ] ;
V_11 = V_6 ;
V_7 = true ;
goto V_13;
}
}
V_13:
for ( V_6 = V_11 ; V_6 > 0 ; V_6 -- )
V_2 -> V_9 [ V_6 ] = V_2 -> V_9 [ V_6 - 1 ] ;
V_2 -> V_9 [ 0 ] = V_8 ;
* V_5 = V_8 ;
* V_4 = V_14 + V_8 ;
return V_7 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_17 -> V_21 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_1 ,
V_17 -> V_21 , V_19 ) ;
return V_19 ;
}
return V_18 & V_23 ;
}
static int F_6 ( struct V_15 * V_16 ,
unsigned V_24 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
bool V_7 = false ;
int V_4 = V_17 -> V_21 ;
int V_5 = V_17 -> V_25 ;
if ( F_7 ( V_17 -> V_26 ) )
V_7 = F_1 ( V_17 , V_24 ,
& V_4 , & V_5 ) ;
if ( ! V_7 ) {
V_19 = F_8 ( V_17 -> V_20 , V_4 ,
V_23 , V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_2 ,
V_4 , V_19 ) ;
return V_19 ;
}
V_17 -> V_21 = V_4 ;
V_17 -> V_12 [ V_5 ] = V_24 ;
}
if ( F_7 ( V_17 -> V_26 ) ) {
F_9 ( V_17 -> V_26 , V_5 & 0x1 ) ;
V_17 -> V_25 = V_5 ;
}
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , unsigned int V_27 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
int V_28 ;
switch ( V_27 ) {
case V_29 :
V_28 = V_30 ;
break;
case V_31 :
V_28 = 0 ;
break;
default:
return - V_32 ;
}
V_19 = F_8 ( V_17 -> V_20 , V_33 ,
V_30 , V_28 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_2 ,
V_33 , V_19 ) ;
return V_19 ;
}
static unsigned int F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_33 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_3 ,
V_33 , V_19 ) ;
return V_19 ;
}
return ( V_18 & V_30 ) ?
V_29 : V_31 ;
}
static int F_12 ( struct V_15 * V_16 ,
int V_34 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_35 ;
int V_19 ;
int V_36 ;
if ( V_34 < 25000 ) {
V_35 = V_37 ;
V_36 = 12000 ;
} else if ( V_34 < 50000 ) {
V_35 = V_38 ;
V_36 = 25000 ;
} else if ( V_34 < 200000 ) {
V_35 = V_39 ;
V_36 = 50000 ;
} else {
V_35 = V_40 ;
V_36 = 200000 ;
}
V_19 = F_8 ( V_17 -> V_20 , V_33 ,
V_41 , V_35 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_4 ,
V_33 , V_19 ) ;
return V_19 ;
}
static int F_13 ( struct V_15 * V_16 ,
int V_42 , int V_43 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_44 ;
int V_19 ;
if ( V_43 <= 9000000 )
V_44 = V_45 ;
else if ( V_43 <= 12000000 )
V_44 = V_46 ;
else
V_44 = V_47 ;
V_19 = F_8 ( V_17 -> V_20 , V_48 ,
V_49 , V_44 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_5 ,
V_48 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_50 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_48 , & V_50 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_6 ,
V_48 , V_19 ) ;
return V_19 ;
}
switch ( V_50 & V_49 ) {
case V_47 :
return 15000000 ;
case V_46 :
return 12000000 ;
case V_45 :
return 9000000 ;
default:
break;
}
return 9000000 ;
}
static int F_15 ( struct V_1 * V_17 ,
struct V_51 * V_52 )
{
int V_19 ;
T_1 V_53 = 0 ;
T_1 V_50 = 0 ;
unsigned int V_18 ;
V_19 = F_4 ( V_17 -> V_20 , V_33 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_7 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_53 = V_18 & V_41 ;
switch ( V_53 ) {
case V_37 :
V_17 -> V_54 . V_34 = 12000 ;
break;
case V_38 :
V_17 -> V_54 . V_34 = 25000 ;
break;
case V_39 :
V_17 -> V_54 . V_34 = 50000 ;
break;
case V_40 :
V_17 -> V_54 . V_34 = 200000 ;
break;
}
if ( V_52 -> V_55 & V_56 )
V_53 |= V_57 ;
if ( ! ( V_52 -> V_55 & V_58 ) )
V_53 |= V_59 ;
if ( V_52 -> V_55 & V_60 )
V_53 |= V_61 ;
if ( V_52 -> V_55 & V_62 ) {
V_53 |= V_63 ;
V_17 -> V_54 . V_64 = 20 ;
} else {
V_17 -> V_54 . V_64 = 240 ;
}
if ( V_52 -> V_55 & V_65 )
V_53 |= V_66 ;
if ( ! ( V_52 -> V_55 & V_67 ) )
V_50 |= V_68 ;
switch ( V_52 -> V_55 & V_69 ) {
case V_70 :
V_50 |= V_47 ;
break;
case V_71 :
V_50 |= V_45 ;
break;
case V_72 :
V_50 |= V_46 ;
break;
case V_73 :
V_50 |= V_74 ;
break;
}
switch ( V_52 -> V_55 & V_75 ) {
case V_76 :
V_50 |= V_77 ;
break;
case V_78 :
V_50 |= V_79 ;
break;
case V_80 :
V_50 |= V_81 ;
break;
case V_82 :
V_50 |= V_83 ;
break;
}
V_19 = F_16 ( V_17 -> V_20 , V_33 , V_53 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_8 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_19 = F_16 ( V_17 -> V_20 , V_48 , V_50 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_8 ,
V_48 , V_19 ) ;
return V_19 ;
}
if ( V_17 -> V_84 && ( V_17 -> V_85 == V_86 ) ) {
V_19 = F_8 ( V_17 -> V_20 , V_14 ,
V_87 , 0 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_9 ,
V_14 , V_19 ) ;
}
return V_19 ;
}
static struct V_51 * F_17 (
struct V_88 * V_22 )
{
struct V_51 * V_52 ;
struct V_89 * V_90 = V_22 -> V_91 ;
int V_19 ;
T_2 V_92 ;
bool V_93 ;
bool V_94 ;
V_52 = F_18 ( V_22 , sizeof( * V_52 ) , V_95 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_96 = F_19 ( V_90 ,
L_10 ) ;
V_52 -> V_97 = F_20 ( V_90 , L_11 , 0 ) ;
V_52 -> V_26 = F_20 ( V_90 , L_12 , 0 ) ;
V_19 = F_21 ( V_90 , L_13 , & V_92 ) ;
if ( ! V_19 )
V_52 -> V_98 = V_92 ;
if ( F_19 ( V_90 , L_14 ) )
V_52 -> V_55 |= V_56 ;
if ( F_19 ( V_90 , L_15 ) )
V_52 -> V_55 |=
V_58 ;
if ( F_19 ( V_90 , L_16 ) )
V_52 -> V_55 |=
V_60 ;
if ( F_19 ( V_90 , L_17 ) )
V_52 -> V_55 |= V_65 ;
if ( F_19 ( V_90 , L_18 ) )
V_52 -> V_55 |= V_62 ;
V_93 = F_19 ( V_90 , L_19 ) ;
V_94 = F_19 ( V_90 ,
L_20 ) ;
if ( V_94 )
V_93 = true ;
if ( V_93 ) {
if ( V_94 )
V_52 -> V_55 |=
V_71 ;
else
V_52 -> V_55 |=
V_72 ;
} else {
V_52 -> V_55 |= V_70 ;
}
return V_52 ;
}
static int F_22 ( struct V_99 * V_100 ,
const struct V_101 * V_85 )
{
struct V_51 * V_52 ;
struct V_102 * V_103 ;
struct V_104 V_105 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_17 ;
bool V_106 = false ;
unsigned int V_107 ;
int V_19 ;
V_52 = F_23 ( & V_100 -> V_22 ) ;
if ( ! V_52 && V_100 -> V_22 . V_91 ) {
V_52 = F_17 ( & V_100 -> V_22 ) ;
V_106 = true ;
}
if ( ! V_52 ) {
F_5 ( & V_100 -> V_22 , L_21 ) ;
return - V_108 ;
}
if ( ( V_52 -> V_26 == - V_109 ) ||
( V_52 -> V_97 == - V_109 ) )
return - V_109 ;
V_17 = F_18 ( & V_100 -> V_22 , sizeof( * V_17 ) , V_95 ) ;
if ( ! V_17 )
return - V_110 ;
V_17 -> V_20 = F_24 ( V_100 , & V_111 ) ;
if ( F_25 ( V_17 -> V_20 ) ) {
V_19 = F_26 ( V_17 -> V_20 ) ;
F_5 ( & V_100 -> V_22 , L_22 , V_19 ) ;
return V_19 ;
}
if ( V_100 -> V_22 . V_91 ) {
const struct V_112 * V_113 ;
V_113 = F_27 ( F_28 ( V_114 ) ,
& V_100 -> V_22 ) ;
if ( ! V_113 )
return - V_115 ;
V_17 -> V_85 = ( T_2 ) ( ( V_116 ) V_113 -> V_18 ) ;
} else {
V_17 -> V_85 = V_85 -> V_117 ;
}
V_19 = F_4 ( V_17 -> V_20 , V_118 , & V_107 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_100 -> V_22 , L_23 , V_19 ) ;
return V_19 ;
}
F_29 ( & V_100 -> V_22 , L_24 ,
( V_107 >> 4 ) & 0xF , ( V_107 >> 1 ) & 0x7 ) ;
F_30 ( V_100 , V_17 ) ;
V_17 -> V_119 = V_120 ;
V_17 -> V_22 = & V_100 -> V_22 ;
V_17 -> V_54 . V_121 = V_85 -> V_121 ;
V_17 -> V_54 . V_85 = 0 ;
V_17 -> V_54 . V_119 = & V_17 -> V_119 ;
V_17 -> V_54 . type = V_122 ;
V_17 -> V_54 . V_123 = V_124 ;
V_17 -> V_54 . V_125 = V_126 ;
V_17 -> V_54 . V_127 = V_128 ;
V_17 -> V_54 . V_129 = V_130 ;
V_17 -> V_26 = ( V_52 -> V_26 ) ? V_52 -> V_26 : - V_32 ;
V_17 -> V_97 = ( V_52 -> V_97 ) ? V_52 -> V_97 : - V_32 ;
V_17 -> V_84 = V_52 -> V_96 ;
V_17 -> V_25 = V_52 -> V_98 ;
V_17 -> V_21 = V_14 + V_52 -> V_98 ;
if ( F_7 ( V_17 -> V_97 ) )
V_17 -> V_84 = true ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
if ( F_7 ( V_17 -> V_26 ) ) {
int V_131 ;
int V_6 ;
V_131 = ( V_52 -> V_98 ) ?
V_132 : V_133 ;
V_19 = F_31 ( & V_100 -> V_22 , V_17 -> V_26 ,
V_131 , L_25 ) ;
if ( V_19 ) {
F_5 ( & V_100 -> V_22 ,
L_26 ,
V_17 -> V_26 , V_19 ) ;
return V_19 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 )
V_17 -> V_9 [ V_6 ] = V_6 ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
V_17 -> V_9 [ V_17 -> V_21 ] = 0 ;
} else {
V_17 -> V_119 . V_134 = V_135 ;
V_17 -> V_119 . V_136 = V_137 ;
V_17 -> V_54 . V_138 = V_17 -> V_21 ;
V_17 -> V_54 . V_139 = V_23 ;
}
if ( V_106 )
V_52 -> V_140 = F_32 ( & V_100 -> V_22 ,
V_100 -> V_22 . V_91 , & V_17 -> V_54 ) ;
V_103 = V_52 -> V_140 ;
switch ( V_17 -> V_85 ) {
case V_86 :
if ( ! V_52 -> V_96 ) {
V_17 -> V_54 . V_141 = V_14 ;
V_17 -> V_54 . V_142 = V_87 ;
V_17 -> V_119 . V_143 = V_144 ;
V_17 -> V_119 . V_145 = V_146 ;
V_17 -> V_119 . V_147 = V_148 ;
break;
}
if ( F_7 ( V_17 -> V_97 ) ) {
V_105 . V_149 = V_133 ;
if ( V_103 && ( V_103 -> V_150 . V_151 ||
V_103 -> V_150 . V_152 ) )
V_105 . V_149 = V_132 ;
V_105 . V_153 = V_17 -> V_97 ;
}
break;
case V_154 :
if ( F_7 ( V_17 -> V_97 ) ) {
V_19 = F_31 ( & V_100 -> V_22 ,
V_17 -> V_97 , V_132 ,
L_27 ) ;
if ( V_19 ) {
F_5 ( & V_100 -> V_22 ,
L_28 ,
V_17 -> V_97 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_54 . V_141 = V_14 ;
V_17 -> V_54 . V_142 = V_87 ;
V_17 -> V_119 . V_143 = V_144 ;
V_17 -> V_119 . V_145 = V_146 ;
V_17 -> V_119 . V_147 = V_148 ;
V_17 -> V_119 . V_155 = F_13 ;
V_17 -> V_119 . V_156 = F_14 ;
break;
default:
break;
}
V_19 = F_15 ( V_17 , V_52 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_29 , V_19 ) ;
return V_19 ;
}
V_105 . V_22 = & V_100 -> V_22 ;
V_105 . V_157 = V_52 -> V_140 ;
V_105 . V_117 = V_17 ;
V_105 . V_91 = V_100 -> V_22 . V_91 ;
V_105 . V_20 = V_17 -> V_20 ;
V_16 = F_33 ( & V_100 -> V_22 , & V_17 -> V_54 , & V_105 ) ;
if ( F_25 ( V_16 ) ) {
V_19 = F_26 ( V_16 ) ;
F_5 ( V_17 -> V_22 , L_30 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_158 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_158 ) ;
}
