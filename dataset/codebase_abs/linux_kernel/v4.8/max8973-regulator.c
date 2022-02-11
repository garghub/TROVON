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
if ( V_34 <= 12000 )
V_35 = V_36 ;
else if ( V_34 <= 25000 )
V_35 = V_37 ;
else if ( V_34 <= 50000 )
V_35 = V_38 ;
else if ( V_34 <= 200000 )
V_35 = V_39 ;
else
return - V_32 ;
V_19 = F_8 ( V_17 -> V_20 , V_33 ,
V_40 , V_35 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_4 ,
V_33 , V_19 ) ;
return V_19 ;
}
static int F_13 ( struct V_15 * V_16 ,
int V_41 , int V_42 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_43 ;
int V_19 ;
if ( V_42 <= 9000000 )
V_43 = V_44 ;
else if ( V_42 <= 12000000 )
V_43 = V_45 ;
else
V_43 = V_46 ;
V_19 = F_8 ( V_17 -> V_20 , V_47 ,
V_48 , V_43 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_5 ,
V_47 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_49 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_47 , & V_49 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_6 ,
V_47 , V_19 ) ;
return V_19 ;
}
switch ( V_49 & V_48 ) {
case V_46 :
return 15000000 ;
case V_45 :
return 12000000 ;
case V_44 :
return 9000000 ;
default:
break;
}
return 9000000 ;
}
static int F_15 ( struct V_1 * V_17 ,
struct V_50 * V_51 )
{
int V_19 ;
T_1 V_52 = 0 ;
T_1 V_49 = 0 ;
unsigned int V_18 ;
V_19 = F_4 ( V_17 -> V_20 , V_33 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_7 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_52 = V_18 & V_40 ;
switch ( V_52 ) {
case V_36 :
V_17 -> V_53 . V_34 = 12000 ;
break;
case V_37 :
V_17 -> V_53 . V_34 = 25000 ;
break;
case V_38 :
V_17 -> V_53 . V_34 = 50000 ;
break;
case V_39 :
V_17 -> V_53 . V_34 = 200000 ;
break;
}
if ( V_51 -> V_54 & V_55 )
V_52 |= V_56 ;
if ( ! ( V_51 -> V_54 & V_57 ) )
V_52 |= V_58 ;
if ( V_51 -> V_54 & V_59 )
V_52 |= V_60 ;
if ( V_51 -> V_54 & V_61 ) {
V_52 |= V_62 ;
V_17 -> V_53 . V_63 = 20 ;
} else {
V_17 -> V_53 . V_63 = 240 ;
}
if ( V_51 -> V_54 & V_64 )
V_52 |= V_65 ;
if ( ( V_51 -> V_66 == V_67 ) &&
( V_17 -> V_68 == V_69 ) )
V_49 |= V_70 ;
if ( ! ( V_51 -> V_54 & V_71 ) )
V_49 |= V_72 ;
switch ( V_51 -> V_54 & V_73 ) {
case V_74 :
V_49 |= V_46 ;
break;
case V_75 :
V_49 |= V_44 ;
break;
case V_76 :
V_49 |= V_45 ;
break;
case V_77 :
V_49 |= V_78 ;
break;
}
switch ( V_51 -> V_54 & V_79 ) {
case V_80 :
V_49 |= V_81 ;
break;
case V_82 :
V_49 |= V_83 ;
break;
case V_84 :
V_49 |= V_85 ;
break;
case V_86 :
V_49 |= V_87 ;
break;
}
V_19 = F_16 ( V_17 -> V_20 , V_33 , V_52 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_8 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_19 = F_16 ( V_17 -> V_20 , V_47 , V_49 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_8 ,
V_47 , V_19 ) ;
return V_19 ;
}
if ( V_17 -> V_88 && ( V_17 -> V_68 == V_89 ) ) {
V_19 = F_8 ( V_17 -> V_20 , V_14 ,
V_90 , 0 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_9 ,
V_14 , V_19 ) ;
}
return V_19 ;
}
static int F_17 ( void * V_18 , int * V_91 )
{
struct V_1 * V_92 = V_18 ;
unsigned int V_43 ;
int V_19 ;
V_19 = F_4 ( V_92 -> V_20 , V_93 , & V_43 ) ;
if ( V_19 < 0 ) {
F_5 ( V_92 -> V_22 , L_10 , V_19 ) ;
return V_19 ;
}
if ( V_43 & V_94 )
* V_91 = V_92 -> V_66 + 1000 ;
else
* V_91 = V_95 ;
return 0 ;
}
static T_2 F_18 ( int V_96 , void * V_18 )
{
struct V_1 * V_92 = V_18 ;
F_19 ( V_92 -> V_97 ) ;
return V_98 ;
}
static int F_20 ( struct V_1 * V_92 )
{
struct V_99 * V_100 ;
struct V_101 * V_101 ;
unsigned long V_102 = 0 ;
int V_19 ;
if ( V_92 -> V_68 != V_69 )
return 0 ;
V_100 = F_21 ( V_92 -> V_22 , 0 , V_92 ,
& V_103 ) ;
if ( F_22 ( V_100 ) ) {
V_19 = F_23 ( V_100 ) ;
F_5 ( V_92 -> V_22 , L_11 ,
V_19 ) ;
return V_19 ;
}
if ( V_92 -> V_96 <= 0 )
return 0 ;
V_101 = F_24 ( V_92 -> V_96 ) ;
if ( V_101 )
V_102 = F_25 ( V_101 ) ;
V_19 = F_26 ( V_92 -> V_22 , V_92 -> V_96 , NULL ,
F_18 ,
V_104 | V_105 | V_102 ,
F_27 ( V_92 -> V_22 ) , V_92 ) ;
if ( V_19 < 0 ) {
F_5 ( V_92 -> V_22 , L_12 ,
V_92 -> V_96 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static struct V_50 * F_28 (
struct V_106 * V_22 )
{
struct V_50 * V_51 ;
struct V_107 * V_108 = V_22 -> V_109 ;
int V_19 ;
T_3 V_110 ;
bool V_111 ;
bool V_112 ;
V_51 = F_29 ( V_22 , sizeof( * V_51 ) , V_113 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_114 = F_30 ( V_108 ,
L_13 ) ;
V_51 -> V_115 = F_31 ( V_108 , L_14 , 0 ) ;
V_51 -> V_26 = F_31 ( V_108 , L_15 , 0 ) ;
V_19 = F_32 ( V_108 , L_16 , & V_110 ) ;
if ( ! V_19 )
V_51 -> V_116 = V_110 ;
if ( F_30 ( V_108 , L_17 ) )
V_51 -> V_54 |= V_55 ;
if ( F_30 ( V_108 , L_18 ) )
V_51 -> V_54 |=
V_57 ;
if ( F_30 ( V_108 , L_19 ) )
V_51 -> V_54 |=
V_59 ;
if ( F_30 ( V_108 , L_20 ) )
V_51 -> V_54 |= V_64 ;
if ( F_30 ( V_108 , L_21 ) )
V_51 -> V_54 |= V_61 ;
V_111 = F_30 ( V_108 , L_22 ) ;
V_112 = F_30 ( V_108 ,
L_23 ) ;
if ( V_112 )
V_111 = true ;
if ( V_111 ) {
if ( V_112 )
V_51 -> V_54 |=
V_75 ;
else
V_51 -> V_54 |=
V_76 ;
} else {
V_51 -> V_54 |= V_74 ;
}
V_51 -> V_66 = V_117 ;
V_19 = F_32 ( V_108 , L_24 , & V_110 ) ;
if ( ! V_19 && ( V_110 <= V_67 ) )
V_51 -> V_66 = V_67 ;
return V_51 ;
}
static int F_33 ( struct V_118 * V_119 ,
const struct V_120 * V_68 )
{
struct V_50 * V_51 ;
struct V_121 * V_122 ;
struct V_123 V_124 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_17 ;
bool V_125 = false ;
unsigned int V_126 ;
int V_19 ;
V_51 = F_34 ( & V_119 -> V_22 ) ;
if ( ! V_51 && V_119 -> V_22 . V_109 ) {
V_51 = F_28 ( & V_119 -> V_22 ) ;
V_125 = true ;
}
if ( ! V_51 ) {
F_5 ( & V_119 -> V_22 , L_25 ) ;
return - V_127 ;
}
if ( ( V_51 -> V_26 == - V_128 ) ||
( V_51 -> V_115 == - V_128 ) )
return - V_128 ;
V_17 = F_29 ( & V_119 -> V_22 , sizeof( * V_17 ) , V_113 ) ;
if ( ! V_17 )
return - V_129 ;
V_17 -> V_20 = F_35 ( V_119 , & V_130 ) ;
if ( F_22 ( V_17 -> V_20 ) ) {
V_19 = F_23 ( V_17 -> V_20 ) ;
F_5 ( & V_119 -> V_22 , L_26 , V_19 ) ;
return V_19 ;
}
if ( V_119 -> V_22 . V_109 ) {
const struct V_131 * V_132 ;
V_132 = F_36 ( F_37 ( V_133 ) ,
& V_119 -> V_22 ) ;
if ( ! V_132 )
return - V_134 ;
V_17 -> V_68 = ( T_3 ) ( ( V_135 ) V_132 -> V_18 ) ;
} else {
V_17 -> V_68 = V_68 -> V_136 ;
}
V_19 = F_4 ( V_17 -> V_20 , V_93 , & V_126 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_119 -> V_22 , L_27 , V_19 ) ;
return V_19 ;
}
F_38 ( & V_119 -> V_22 , L_28 ,
( V_126 >> 4 ) & 0xF , ( V_126 >> 1 ) & 0x7 ) ;
F_39 ( V_119 , V_17 ) ;
V_17 -> V_137 = V_138 ;
V_17 -> V_22 = & V_119 -> V_22 ;
V_17 -> V_53 . V_139 = V_68 -> V_139 ;
V_17 -> V_53 . V_68 = 0 ;
V_17 -> V_53 . V_137 = & V_17 -> V_137 ;
V_17 -> V_53 . type = V_140 ;
V_17 -> V_53 . V_141 = V_142 ;
V_17 -> V_53 . V_143 = V_144 ;
V_17 -> V_53 . V_145 = V_146 ;
V_17 -> V_53 . V_147 = V_148 ;
V_17 -> V_26 = ( V_51 -> V_26 ) ? V_51 -> V_26 : - V_32 ;
V_17 -> V_115 = ( V_51 -> V_115 ) ? V_51 -> V_115 : - V_32 ;
V_17 -> V_88 = V_51 -> V_114 ;
V_17 -> V_25 = V_51 -> V_116 ;
V_17 -> V_21 = V_14 + V_51 -> V_116 ;
V_17 -> V_66 = V_51 -> V_66 ;
if ( F_7 ( V_17 -> V_115 ) )
V_17 -> V_88 = true ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
if ( F_7 ( V_17 -> V_26 ) ) {
int V_149 ;
int V_6 ;
V_149 = ( V_51 -> V_116 ) ?
V_150 : V_151 ;
V_19 = F_40 ( & V_119 -> V_22 , V_17 -> V_26 ,
V_149 , L_29 ) ;
if ( V_19 ) {
F_5 ( & V_119 -> V_22 ,
L_30 ,
V_17 -> V_26 , V_19 ) ;
return V_19 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 )
V_17 -> V_9 [ V_6 ] = V_6 ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
V_17 -> V_9 [ V_17 -> V_21 ] = 0 ;
} else {
V_17 -> V_137 . V_152 = V_153 ;
V_17 -> V_137 . V_154 = V_155 ;
V_17 -> V_53 . V_156 = V_17 -> V_21 ;
V_17 -> V_53 . V_157 = V_23 ;
}
if ( V_125 )
V_51 -> V_158 = F_41 ( & V_119 -> V_22 ,
V_119 -> V_22 . V_109 , & V_17 -> V_53 ) ;
V_122 = V_51 -> V_158 ;
switch ( V_17 -> V_68 ) {
case V_89 :
if ( ! V_51 -> V_114 ) {
V_17 -> V_53 . V_159 = V_14 ;
V_17 -> V_53 . V_160 = V_90 ;
V_17 -> V_137 . V_161 = V_162 ;
V_17 -> V_137 . V_163 = V_164 ;
V_17 -> V_137 . V_165 = V_166 ;
break;
}
if ( F_7 ( V_17 -> V_115 ) ) {
V_124 . V_167 = V_151 ;
if ( V_122 && ( V_122 -> V_168 . V_169 ||
V_122 -> V_168 . V_170 ) )
V_124 . V_167 = V_150 ;
V_124 . V_171 = V_17 -> V_115 ;
}
break;
case V_69 :
if ( F_7 ( V_17 -> V_115 ) ) {
V_19 = F_40 ( & V_119 -> V_22 ,
V_17 -> V_115 , V_150 ,
L_31 ) ;
if ( V_19 ) {
F_5 ( & V_119 -> V_22 ,
L_32 ,
V_17 -> V_115 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_53 . V_159 = V_14 ;
V_17 -> V_53 . V_160 = V_90 ;
V_17 -> V_137 . V_161 = V_162 ;
V_17 -> V_137 . V_163 = V_164 ;
V_17 -> V_137 . V_165 = V_166 ;
V_17 -> V_137 . V_172 = F_13 ;
V_17 -> V_137 . V_173 = F_14 ;
break;
default:
break;
}
V_19 = F_15 ( V_17 , V_51 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_33 , V_19 ) ;
return V_19 ;
}
V_124 . V_22 = & V_119 -> V_22 ;
V_124 . V_174 = V_51 -> V_158 ;
V_124 . V_136 = V_17 ;
V_124 . V_109 = V_119 -> V_22 . V_109 ;
V_124 . V_20 = V_17 -> V_20 ;
V_16 = F_42 ( & V_119 -> V_22 , & V_17 -> V_53 , & V_124 ) ;
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
return F_44 ( & V_175 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_175 ) ;
}
