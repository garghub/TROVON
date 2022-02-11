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
if ( ( V_52 -> V_67 == V_68 ) &&
( V_17 -> V_69 == V_70 ) )
V_50 |= V_71 ;
if ( ! ( V_52 -> V_55 & V_72 ) )
V_50 |= V_73 ;
switch ( V_52 -> V_55 & V_74 ) {
case V_75 :
V_50 |= V_47 ;
break;
case V_76 :
V_50 |= V_45 ;
break;
case V_77 :
V_50 |= V_46 ;
break;
case V_78 :
V_50 |= V_79 ;
break;
}
switch ( V_52 -> V_55 & V_80 ) {
case V_81 :
V_50 |= V_82 ;
break;
case V_83 :
V_50 |= V_84 ;
break;
case V_85 :
V_50 |= V_86 ;
break;
case V_87 :
V_50 |= V_88 ;
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
if ( V_17 -> V_89 && ( V_17 -> V_69 == V_90 ) ) {
V_19 = F_8 ( V_17 -> V_20 , V_14 ,
V_91 , 0 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_9 ,
V_14 , V_19 ) ;
}
return V_19 ;
}
static int F_17 ( void * V_18 , int * V_92 )
{
struct V_1 * V_93 = V_18 ;
unsigned int V_44 ;
int V_19 ;
V_19 = F_4 ( V_93 -> V_20 , V_94 , & V_44 ) ;
if ( V_19 < 0 ) {
F_5 ( V_93 -> V_22 , L_10 , V_19 ) ;
return V_19 ;
}
if ( V_44 & V_95 )
* V_92 = V_93 -> V_67 + 1000 ;
else
* V_92 = V_96 ;
return 0 ;
}
static T_2 F_18 ( int V_97 , void * V_18 )
{
struct V_1 * V_93 = V_18 ;
F_19 ( V_93 -> V_98 ) ;
return V_99 ;
}
static int F_20 ( struct V_1 * V_93 )
{
struct V_100 * V_101 ;
struct V_102 * V_102 ;
unsigned long V_103 = 0 ;
int V_19 ;
if ( V_93 -> V_69 != V_70 )
return 0 ;
V_101 = F_21 ( V_93 -> V_22 , 0 , V_93 ,
& V_104 ) ;
if ( F_22 ( V_101 ) ) {
V_19 = F_23 ( V_101 ) ;
F_5 ( V_93 -> V_22 , L_11 ,
V_19 ) ;
return V_19 ;
}
if ( V_93 -> V_97 <= 0 )
return 0 ;
V_102 = F_24 ( V_93 -> V_97 ) ;
if ( V_102 )
V_103 = F_25 ( V_102 ) ;
V_19 = F_26 ( V_93 -> V_22 , V_93 -> V_97 , NULL ,
F_18 ,
V_105 | V_106 | V_103 ,
F_27 ( V_93 -> V_22 ) , V_93 ) ;
if ( V_19 < 0 ) {
F_5 ( V_93 -> V_22 , L_12 ,
V_93 -> V_97 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static struct V_51 * F_28 (
struct V_107 * V_22 )
{
struct V_51 * V_52 ;
struct V_108 * V_109 = V_22 -> V_110 ;
int V_19 ;
T_3 V_111 ;
bool V_112 ;
bool V_113 ;
V_52 = F_29 ( V_22 , sizeof( * V_52 ) , V_114 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_115 = F_30 ( V_109 ,
L_13 ) ;
V_52 -> V_116 = F_31 ( V_109 , L_14 , 0 ) ;
V_52 -> V_26 = F_31 ( V_109 , L_15 , 0 ) ;
V_19 = F_32 ( V_109 , L_16 , & V_111 ) ;
if ( ! V_19 )
V_52 -> V_117 = V_111 ;
if ( F_30 ( V_109 , L_17 ) )
V_52 -> V_55 |= V_56 ;
if ( F_30 ( V_109 , L_18 ) )
V_52 -> V_55 |=
V_58 ;
if ( F_30 ( V_109 , L_19 ) )
V_52 -> V_55 |=
V_60 ;
if ( F_30 ( V_109 , L_20 ) )
V_52 -> V_55 |= V_65 ;
if ( F_30 ( V_109 , L_21 ) )
V_52 -> V_55 |= V_62 ;
V_112 = F_30 ( V_109 , L_22 ) ;
V_113 = F_30 ( V_109 ,
L_23 ) ;
if ( V_113 )
V_112 = true ;
if ( V_112 ) {
if ( V_113 )
V_52 -> V_55 |=
V_76 ;
else
V_52 -> V_55 |=
V_77 ;
} else {
V_52 -> V_55 |= V_75 ;
}
V_52 -> V_67 = V_118 ;
V_19 = F_32 ( V_109 , L_24 , & V_111 ) ;
if ( ! V_19 && ( V_111 <= V_68 ) )
V_52 -> V_67 = V_68 ;
return V_52 ;
}
static int F_33 ( struct V_119 * V_120 ,
const struct V_121 * V_69 )
{
struct V_51 * V_52 ;
struct V_122 * V_123 ;
struct V_124 V_125 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_17 ;
bool V_126 = false ;
unsigned int V_127 ;
int V_19 ;
V_52 = F_34 ( & V_120 -> V_22 ) ;
if ( ! V_52 && V_120 -> V_22 . V_110 ) {
V_52 = F_28 ( & V_120 -> V_22 ) ;
V_126 = true ;
}
if ( ! V_52 ) {
F_5 ( & V_120 -> V_22 , L_25 ) ;
return - V_128 ;
}
if ( ( V_52 -> V_26 == - V_129 ) ||
( V_52 -> V_116 == - V_129 ) )
return - V_129 ;
V_17 = F_29 ( & V_120 -> V_22 , sizeof( * V_17 ) , V_114 ) ;
if ( ! V_17 )
return - V_130 ;
V_17 -> V_20 = F_35 ( V_120 , & V_131 ) ;
if ( F_22 ( V_17 -> V_20 ) ) {
V_19 = F_23 ( V_17 -> V_20 ) ;
F_5 ( & V_120 -> V_22 , L_26 , V_19 ) ;
return V_19 ;
}
if ( V_120 -> V_22 . V_110 ) {
const struct V_132 * V_133 ;
V_133 = F_36 ( F_37 ( V_134 ) ,
& V_120 -> V_22 ) ;
if ( ! V_133 )
return - V_135 ;
V_17 -> V_69 = ( T_3 ) ( ( V_136 ) V_133 -> V_18 ) ;
} else {
V_17 -> V_69 = V_69 -> V_137 ;
}
V_19 = F_4 ( V_17 -> V_20 , V_94 , & V_127 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_120 -> V_22 , L_27 , V_19 ) ;
return V_19 ;
}
F_38 ( & V_120 -> V_22 , L_28 ,
( V_127 >> 4 ) & 0xF , ( V_127 >> 1 ) & 0x7 ) ;
F_39 ( V_120 , V_17 ) ;
V_17 -> V_138 = V_139 ;
V_17 -> V_22 = & V_120 -> V_22 ;
V_17 -> V_54 . V_140 = V_69 -> V_140 ;
V_17 -> V_54 . V_69 = 0 ;
V_17 -> V_54 . V_138 = & V_17 -> V_138 ;
V_17 -> V_54 . type = V_141 ;
V_17 -> V_54 . V_142 = V_143 ;
V_17 -> V_54 . V_144 = V_145 ;
V_17 -> V_54 . V_146 = V_147 ;
V_17 -> V_54 . V_148 = V_149 ;
V_17 -> V_26 = ( V_52 -> V_26 ) ? V_52 -> V_26 : - V_32 ;
V_17 -> V_116 = ( V_52 -> V_116 ) ? V_52 -> V_116 : - V_32 ;
V_17 -> V_89 = V_52 -> V_115 ;
V_17 -> V_25 = V_52 -> V_117 ;
V_17 -> V_21 = V_14 + V_52 -> V_117 ;
V_17 -> V_67 = V_52 -> V_67 ;
if ( F_7 ( V_17 -> V_116 ) )
V_17 -> V_89 = true ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
if ( F_7 ( V_17 -> V_26 ) ) {
int V_150 ;
int V_6 ;
V_150 = ( V_52 -> V_117 ) ?
V_151 : V_152 ;
V_19 = F_40 ( & V_120 -> V_22 , V_17 -> V_26 ,
V_150 , L_29 ) ;
if ( V_19 ) {
F_5 ( & V_120 -> V_22 ,
L_30 ,
V_17 -> V_26 , V_19 ) ;
return V_19 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 )
V_17 -> V_9 [ V_6 ] = V_6 ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
V_17 -> V_9 [ V_17 -> V_21 ] = 0 ;
} else {
V_17 -> V_138 . V_153 = V_154 ;
V_17 -> V_138 . V_155 = V_156 ;
V_17 -> V_54 . V_157 = V_17 -> V_21 ;
V_17 -> V_54 . V_158 = V_23 ;
}
if ( V_126 )
V_52 -> V_159 = F_41 ( & V_120 -> V_22 ,
V_120 -> V_22 . V_110 , & V_17 -> V_54 ) ;
V_123 = V_52 -> V_159 ;
switch ( V_17 -> V_69 ) {
case V_90 :
if ( ! V_52 -> V_115 ) {
V_17 -> V_54 . V_160 = V_14 ;
V_17 -> V_54 . V_161 = V_91 ;
V_17 -> V_138 . V_162 = V_163 ;
V_17 -> V_138 . V_164 = V_165 ;
V_17 -> V_138 . V_166 = V_167 ;
break;
}
if ( F_7 ( V_17 -> V_116 ) ) {
V_125 . V_168 = V_152 ;
if ( V_123 && ( V_123 -> V_169 . V_170 ||
V_123 -> V_169 . V_171 ) )
V_125 . V_168 = V_151 ;
V_125 . V_172 = V_17 -> V_116 ;
}
break;
case V_70 :
if ( F_7 ( V_17 -> V_116 ) ) {
V_19 = F_40 ( & V_120 -> V_22 ,
V_17 -> V_116 , V_151 ,
L_31 ) ;
if ( V_19 ) {
F_5 ( & V_120 -> V_22 ,
L_32 ,
V_17 -> V_116 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_54 . V_160 = V_14 ;
V_17 -> V_54 . V_161 = V_91 ;
V_17 -> V_138 . V_162 = V_163 ;
V_17 -> V_138 . V_164 = V_165 ;
V_17 -> V_138 . V_166 = V_167 ;
V_17 -> V_138 . V_173 = F_13 ;
V_17 -> V_138 . V_174 = F_14 ;
break;
default:
break;
}
V_19 = F_15 ( V_17 , V_52 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_33 , V_19 ) ;
return V_19 ;
}
V_125 . V_22 = & V_120 -> V_22 ;
V_125 . V_175 = V_52 -> V_159 ;
V_125 . V_137 = V_17 ;
V_125 . V_110 = V_120 -> V_22 . V_110 ;
V_125 . V_20 = V_17 -> V_20 ;
V_16 = F_42 ( & V_120 -> V_22 , & V_17 -> V_54 , & V_125 ) ;
if ( F_22 ( V_16 ) ) {
V_19 = F_23 ( V_16 ) ;
F_5 ( V_17 -> V_22 , L_34 , V_19 ) ;
return V_19 ;
}
F_20 ( V_17 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_176 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_176 ) ;
}
