static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_1 V_7 , V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 . V_10 ;
V_7 = V_10 -> V_7 ;
for ( V_6 = 0 ; V_6 < V_10 -> V_12 ; V_6 ++ ) {
V_8 = F_2 ( V_2 , V_7 ) ;
* V_5 ++ = F_3 ( V_7 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_7 += V_10 -> V_13 ;
}
return V_10 -> V_12 * 2 * sizeof( T_1 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 , V_14 , V_15 = 0 ;
T_1 V_7 , V_8 ;
T_3 V_12 ;
struct V_16 * V_17 = & V_4 -> V_11 . V_18 ;
struct V_19 * V_20 = V_2 -> V_21 -> V_22 . V_23 ;
V_7 = V_17 -> V_7 ;
V_12 = V_17 -> V_12 ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
V_14 = 0 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
if ( ! ( V_17 -> V_24 & ( 1 << V_14 ) ) )
continue;
switch ( 1 << V_14 ) {
case V_25 :
F_5 ( V_2 , V_7 , V_17 -> V_26 ) ;
break;
case V_27 :
V_8 = F_2 ( V_2 , V_7 ) ;
F_5 ( V_2 , V_7 , V_8 ) ;
break;
case V_28 :
V_8 = F_2 ( V_2 , V_7 ) ;
F_5 ( V_2 , V_7 ,
( V_8 & V_17 -> V_29 ) ) ;
break;
case V_30 :
V_8 = F_2 ( V_2 , V_7 ) ;
F_5 ( V_2 , V_7 ,
( V_8 | V_17 -> V_31 ) ) ;
break;
case V_32 :
while ( V_15 <= V_17 -> V_15 ) {
V_8 = F_2 ( V_2 , V_7 ) ;
if ( ( V_8 & V_17 -> V_29 ) == V_17 -> V_26 )
break;
F_6 ( 1000 , 2000 ) ;
V_15 ++ ;
}
if ( V_15 > V_17 -> V_15 ) {
F_7 ( & V_2 -> V_33 -> V_34 ,
L_1 ) ;
return - V_35 ;
}
break;
case V_36 :
if ( V_17 -> V_37 )
V_7 = V_20 -> V_38 [ V_17 -> V_37 ] ;
V_8 = F_2 ( V_2 , V_7 ) ;
V_20 -> V_38 [ V_17 -> V_39 ] = V_8 ;
break;
case V_40 :
if ( V_17 -> V_39 )
V_8 = V_20 -> V_38 [ V_17 -> V_39 ] ;
else
V_8 = V_17 -> V_26 ;
if ( V_17 -> V_37 )
V_7 = V_20 -> V_38 [ V_17 -> V_37 ] ;
F_5 ( V_2 , V_7 , V_8 ) ;
break;
case V_41 :
V_8 = V_20 -> V_38 [ V_17 -> V_39 ] ;
V_8 <<= V_17 -> V_42 ;
V_8 >>= V_17 -> V_43 ;
if ( V_17 -> V_29 )
V_8 &= V_17 -> V_29 ;
V_8 |= V_17 -> V_31 ;
V_8 += V_17 -> V_26 ;
V_20 -> V_38 [ V_17 -> V_39 ] = V_8 ;
break;
default:
F_7 ( & V_2 -> V_33 -> V_34 ,
L_2 ) ;
break;
}
}
V_7 += V_17 -> V_13 ;
}
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_44 ;
T_1 V_45 , V_8 = 0 ;
struct V_46 * V_47 = & V_4 -> V_11 . V_47 ;
V_45 = V_47 -> V_45 ;
for ( V_44 = 0 ; V_44 < V_47 -> V_12 ; V_44 ++ ) {
F_5 ( V_2 , V_47 -> V_7 , V_45 ) ;
V_8 = F_2 ( V_2 , V_47 -> V_48 ) ;
* V_5 ++ = F_3 ( V_45 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_45 += V_47 -> V_49 ;
}
return 2 * V_47 -> V_12 * sizeof( T_1 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 , V_44 ;
T_1 V_50 , V_7 , V_8 , V_51 = 0 ;
struct V_52 * V_53 = & V_4 -> V_11 . V_53 ;
V_7 = V_53 -> V_48 ;
V_50 = V_53 -> V_54 ;
for ( V_44 = 0 ; V_44 < V_53 -> V_12 ; V_44 ++ ) {
F_5 ( V_2 , V_53 -> V_55 , V_51 ) ;
V_7 = V_53 -> V_48 ;
for ( V_6 = 0 ; V_6 < V_50 ; V_6 ++ ) {
V_8 = F_2 ( V_2 , V_7 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_7 += V_53 -> V_56 ;
}
V_51 += V_53 -> V_13 ;
}
return V_53 -> V_12 * V_50 * sizeof( T_1 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_1 V_8 ;
void T_4 * V_7 ;
struct V_57 * V_58 = & V_4 -> V_11 . V_58 ;
V_7 = V_2 -> V_21 -> V_59 + V_58 -> V_48 ;
for ( V_6 = 0 ; V_6 < V_58 -> V_12 ; V_6 ++ ) {
V_8 = F_11 ( V_7 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_7 += V_58 -> V_56 ;
}
return V_58 -> V_12 * sizeof( T_1 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 , V_60 = 0 ;
T_1 V_61 , V_62 , V_45 , V_63 , V_7 ;
struct V_64 * V_65 = & V_4 -> V_11 . V_66 ;
V_61 = V_65 -> V_7 ;
V_62 = V_65 -> V_62 / 4 ;
V_67:
V_63 = F_13 ( V_2 , V_68 ) ;
if ( ! V_63 && V_60 < V_69 ) {
F_6 ( 10000 , 11000 ) ;
V_60 ++ ;
goto V_67;
}
F_14 ( V_2 , V_70 ,
V_2 -> V_21 -> V_71 ) ;
for ( V_6 = 0 ; V_6 < V_62 ; V_6 ++ ) {
V_7 = V_61 & 0xFFFF0000 ;
F_5 ( V_2 , V_72 , V_7 ) ;
V_7 = F_15 ( V_61 ) + V_73 ;
V_45 = F_2 ( V_2 , V_7 ) ;
V_61 += 4 ;
* V_5 ++ = F_3 ( V_45 ) ;
}
F_13 ( V_2 , V_74 ) ;
return V_65 -> V_62 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_1 V_50 , V_45 , V_8 , V_7 ;
struct V_75 * V_76 = & V_4 -> V_11 . V_77 ;
V_45 = V_76 -> V_78 ;
for ( V_6 = 0 ; V_6 < V_76 -> V_12 ; V_6 ++ ) {
F_5 ( V_2 , V_76 -> V_7 , V_45 ) ;
F_5 ( V_2 , V_76 -> V_79 , F_15 ( V_76 -> V_80 ) ) ;
V_7 = V_76 -> V_48 ;
V_50 = V_76 -> V_81 ;
while ( V_50 ) {
V_8 = F_2 ( V_2 , V_7 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_7 += V_76 -> V_56 ;
V_50 -- ;
}
V_45 += V_76 -> V_13 ;
}
return V_76 -> V_12 * V_76 -> V_81 * sizeof( T_1 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_1 V_50 , V_45 , V_8 , V_7 ;
T_3 V_82 , V_83 , V_84 = 0 ;
struct V_75 * V_85 = & V_4 -> V_11 . V_77 ;
V_45 = V_85 -> V_78 ;
V_82 = F_18 ( F_19 ( V_85 -> V_80 ) ) ;
V_83 = F_20 ( F_19 ( V_85 -> V_80 ) ) ;
for ( V_6 = 0 ; V_6 < V_85 -> V_12 ; V_6 ++ ) {
F_5 ( V_2 , V_85 -> V_7 , V_45 ) ;
if ( F_15 ( V_85 -> V_80 ) )
F_5 ( V_2 , V_85 -> V_79 ,
F_15 ( V_85 -> V_80 ) ) ;
if ( ! V_82 )
goto V_86;
do {
V_8 = F_2 ( V_2 , V_85 -> V_79 ) ;
if ( ! ( V_8 & V_82 ) )
break;
F_6 ( 1000 , 2000 ) ;
V_84 ++ ;
} while ( V_84 <= V_83 );
if ( V_84 > V_83 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_3 ,
V_87 ) ;
return - V_35 ;
}
V_86:
V_7 = V_85 -> V_48 ;
V_50 = V_85 -> V_81 ;
while ( V_50 ) {
V_8 = F_2 ( V_2 , V_7 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_7 += V_85 -> V_56 ;
V_50 -- ;
}
V_45 += V_85 -> V_13 ;
}
return V_85 -> V_12 * V_85 -> V_81 * sizeof( T_1 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_64 * V_66 , T_2 * V_5 ,
int * V_88 )
{
T_1 V_7 , V_8 , V_89 ;
int V_6 , V_90 ;
V_90 = V_66 -> V_62 ;
V_7 = V_66 -> V_7 ;
if ( ( V_7 & 0xf ) || ( V_90 % 16 ) ) {
F_7 ( & V_2 -> V_33 -> V_34 ,
L_4 ,
V_7 , V_90 ) ;
* V_88 = - V_35 ;
return 0 ;
}
F_23 ( & V_2 -> V_21 -> V_91 ) ;
while ( V_90 != 0 ) {
F_5 ( V_2 , V_92 , V_7 ) ;
F_5 ( V_2 , V_93 , 0 ) ;
F_5 ( V_2 , V_94 , V_95 ) ;
for ( V_6 = 0 ; V_6 < V_69 ; V_6 ++ ) {
V_89 = F_2 ( V_2 , V_94 ) ;
if ( ! ( V_89 & V_96 ) )
break;
}
if ( V_6 == V_69 ) {
if ( F_24 () ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_5 ) ;
* V_88 = - V_97 ;
goto V_98;
}
}
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_8 = F_2 ( V_2 , V_99 [ V_6 ] ) ;
* V_5 ++ = F_3 ( V_8 ) ;
}
V_7 += 16 ;
V_90 -= 16 ;
V_88 += 16 ;
}
V_98:
F_25 ( & V_2 -> V_21 -> V_91 ) ;
return V_66 -> V_62 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_64 * V_66 )
{
struct V_19 * V_23 ;
struct V_100 * V_34 = & V_2 -> V_33 -> V_34 ;
T_1 V_101 , V_102 , V_103 ;
int V_6 , V_88 , V_104 ;
V_23 = V_2 -> V_21 -> V_22 . V_23 ;
V_101 = V_23 -> V_38 [ V_105 ] ;
V_102 = F_27 ( V_101 ) ;
V_103 = V_102 + V_106 ;
V_88 = F_28 ( V_2 , V_103 ,
V_66 -> V_107 ) ;
if ( V_88 )
return V_88 ;
V_103 = V_102 + V_108 ;
V_88 = F_28 ( V_2 , V_103 , 0 ) ;
if ( V_88 )
return V_88 ;
V_103 = V_102 + V_109 ;
V_88 = F_28 ( V_2 , V_103 ,
V_66 -> V_110 ) ;
if ( V_88 )
return V_88 ;
V_103 = V_102 + V_109 ;
for ( V_6 = 0 ; V_6 < 400 ; V_6 ++ ) {
V_104 = F_2 ( V_2 , V_103 ) ;
if ( V_104 & V_111 )
F_6 ( 250 , 500 ) ;
else
break;
}
if ( V_6 >= 400 ) {
F_7 ( V_34 , L_6 ) ;
V_88 = - V_97 ;
}
return V_88 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_64 * V_66 ,
T_2 * V_5 , int * V_88 )
{
struct V_112 * V_22 = & V_2 -> V_21 -> V_22 ;
T_1 V_113 , V_102 , V_62 = 0 , V_114 = 0 ;
struct V_115 * V_116 ;
struct V_19 * V_23 ;
struct V_100 * V_34 = & V_2 -> V_33 -> V_34 ;
T_5 V_117 ;
void * V_118 ;
V_23 = V_22 -> V_23 ;
V_113 = V_23 -> V_38 [ V_105 ] ;
V_102 = F_27 ( V_113 ) ;
V_113 = F_2 ( V_2 ,
V_102 + V_109 ) ;
if ( ! ( V_113 & V_119 ) ) {
F_7 ( V_34 , L_7 , V_87 ) ;
* V_88 = - V_97 ;
return 0 ;
}
V_116 = F_30 ( sizeof( struct V_115 ) ,
V_120 ) ;
if ( ! V_116 ) {
* V_88 = - V_121 ;
return 0 ;
}
V_117 = V_22 -> V_122 ;
V_118 = V_22 -> V_118 ;
V_113 = 0 ;
V_113 = V_66 -> V_123 & 0xff0f ;
V_113 |= ( V_2 -> V_21 -> V_71 & 0xf ) << 4 ;
V_116 -> V_123 = ( V_113 << 16 ) & 0xffff0000 ;
V_116 -> V_124 = F_31 ( V_117 ) ;
V_116 -> V_125 = F_32 ( V_117 ) ;
V_116 -> V_126 = 0 ;
while ( V_114 < V_66 -> V_62 ) {
if ( V_66 -> V_62 - V_114 >= V_127 )
V_62 = V_127 ;
else
V_62 = V_66 -> V_62 - V_114 ;
V_116 -> V_128 = V_66 -> V_7 + V_114 ;
V_116 -> V_129 = V_62 ;
V_113 = sizeof( struct V_115 ) / 16 ;
* V_88 = F_33 ( V_2 , V_66 -> V_107 ,
( T_1 * ) V_116 , V_113 ) ;
if ( * V_88 ) {
F_7 ( V_34 , L_8 ,
V_66 -> V_107 ) ;
goto V_130;
}
* V_88 = F_26 ( V_2 , V_66 ) ;
if ( * V_88 ) {
F_7 ( V_34 , L_9 ) ;
goto V_130;
}
memcpy ( V_5 , V_118 , V_62 ) ;
V_5 += V_62 / 4 ;
V_114 += V_62 ;
}
V_130:
F_34 ( V_116 ) ;
return V_114 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
struct V_112 * V_22 = & V_2 -> V_21 -> V_22 ;
struct V_100 * V_34 = & V_2 -> V_33 -> V_34 ;
struct V_64 * V_66 = & V_4 -> V_11 . V_66 ;
T_1 V_131 ;
int V_88 = 0 ;
if ( V_22 -> V_132 ) {
V_131 = F_29 ( V_2 , V_66 , V_5 ,
& V_88 ) ;
if ( V_88 )
F_7 ( V_34 ,
L_10 ,
V_4 -> V_133 . V_134 ) ;
else
return V_131 ;
}
V_131 = F_22 ( V_2 , V_66 , V_5 , & V_88 ) ;
if ( V_88 ) {
F_7 ( V_34 ,
L_11 ,
V_4 -> V_133 . V_134 ) ;
return 0 ;
} else {
return V_131 ;
}
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
V_4 -> V_133 . V_135 |= V_136 ;
return 0 ;
}
static int F_37 ( struct V_100 * V_34 ,
struct V_3 * V_4 , T_1 V_62 )
{
int V_88 = 1 ;
if ( V_62 != V_4 -> V_133 . V_137 ) {
F_21 ( V_34 ,
L_12 ,
V_4 -> V_133 . type , V_4 -> V_133 . V_134 , V_62 ,
V_4 -> V_133 . V_137 ) ;
V_88 = 0 ;
}
return V_88 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_5 )
{
struct V_138 * V_139 = & V_4 -> V_11 . V_140 ;
T_1 V_8 , V_141 , V_142 , V_113 ;
V_142 = V_139 -> V_142 ;
F_5 ( V_2 , V_139 -> V_143 , V_139 -> V_26 ) ;
V_141 = 0 ;
while ( V_141 < V_142 ) {
V_8 = F_2 ( V_2 , V_139 -> V_143 ) ;
if ( ( V_8 & V_139 -> V_82 ) != 0 )
break;
V_141 ++ ;
}
if ( V_141 == V_142 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_3 ,
V_87 ) ;
return 0 ;
}
V_8 = F_2 ( V_2 , V_139 -> V_144 ) & V_139 -> V_145 ;
F_5 ( V_2 , V_139 -> V_144 , V_8 ) ;
F_5 ( V_2 , V_139 -> V_143 , V_139 -> V_29 ) ;
V_141 = 0 ;
while ( V_141 < V_142 ) {
V_113 = F_2 ( V_2 , V_139 -> V_143 ) ;
if ( ( V_113 & V_139 -> V_82 ) != 0 )
break;
V_141 ++ ;
}
* V_5 ++ = F_3 ( V_139 -> V_144 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
return 2 * sizeof( T_1 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
struct V_146 * V_147 = & V_4 -> V_11 . V_147 ;
T_1 V_8 , V_141 , V_142 , V_148 ;
int V_6 ;
V_142 = V_147 -> V_142 ;
V_148 = V_147 -> V_148 ;
for ( V_6 = 0 ; V_6 < V_147 -> V_12 ; V_6 ++ ) {
F_5 ( V_2 , V_147 -> V_55 , V_148 ) ;
V_141 = 0 ;
while ( V_141 < V_142 ) {
V_8 = F_2 ( V_2 , V_147 -> V_55 ) ;
if ( ( V_8 & V_147 -> V_82 ) != 0 )
break;
V_141 ++ ;
}
if ( V_141 == V_142 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_3 ,
V_87 ) ;
return 0 ;
}
V_8 = F_2 ( V_2 , V_147 -> V_48 ) ;
* V_5 ++ = F_3 ( V_148 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_148 += V_147 -> V_149 ;
}
return V_147 -> V_12 * ( 2 * sizeof( T_1 ) ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
struct V_150 * V_151 = & V_4 -> V_11 . V_151 ;
T_1 V_8 ;
T_1 V_152 , V_153 , V_154 ;
int V_6 ;
V_153 = V_151 -> V_153 ;
V_154 = V_151 -> V_154 ;
for ( V_6 = 0 ; V_6 < V_151 -> V_12 ; V_6 ++ ) {
F_5 ( V_2 , V_151 -> V_155 , V_153 ) ;
V_152 = V_153 & V_151 -> V_156 ;
F_5 ( V_2 , V_151 -> V_157 , V_152 ) ;
V_8 = F_2 ( V_2 , V_151 -> V_48 ) ;
* V_5 ++ = F_3 ( V_152 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
F_5 ( V_2 , V_151 -> V_155 , V_154 ) ;
V_152 = V_154 & V_151 -> V_156 ;
F_5 ( V_2 , V_151 -> V_157 , V_152 ) ;
V_8 = F_2 ( V_2 , V_151 -> V_48 ) ;
* V_5 ++ = F_3 ( V_152 ) ;
* V_5 ++ = F_3 ( V_8 ) ;
V_153 += V_151 -> V_149 ;
V_154 += V_151 -> V_149 ;
}
return V_151 -> V_12 * ( 4 * sizeof( T_1 ) ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_5 )
{
T_1 V_61 , V_62 ;
struct V_64 * V_65 = & V_4 -> V_11 . V_66 ;
V_61 = V_65 -> V_7 ;
V_62 = V_65 -> V_62 / 4 ;
if ( ! F_42 ( V_2 , V_61 ,
( T_3 * ) V_5 , V_62 ) )
return V_65 -> V_62 ;
return 0 ;
}
static T_6 F_43 ( T_6 * V_158 , T_1 V_159 )
{
T_7 V_160 = 0 ;
int V_60 = V_159 / sizeof( T_6 ) ;
while ( V_60 -- > 0 )
V_160 += * V_158 ++ ;
while ( V_160 >> 32 )
V_160 = ( V_160 & 0xFFFFFFFF ) + ( V_160 >> 32 ) ;
return ~ V_160 ;
}
static int F_44 ( struct V_1 * V_2 ,
T_3 * V_5 , T_1 V_62 )
{
int V_88 = 0 ;
if ( F_45 ( V_2 ) )
return - V_97 ;
if ( F_46 ( V_2 ) )
return - V_97 ;
V_88 = F_42 ( V_2 ,
V_161 ,
V_5 , V_62 / sizeof( T_1 ) ) ;
F_47 ( V_2 ) ;
return V_88 ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_19 V_164 ;
T_1 V_62 = sizeof( struct V_19 ) / sizeof( T_1 ) ;
int V_88 = 0 ;
if ( F_45 ( V_2 ) )
return - V_97 ;
if ( F_46 ( V_2 ) )
return - V_97 ;
V_88 = F_42 ( V_2 ,
V_161 ,
( T_3 * ) & V_164 , V_62 ) ;
F_47 ( V_2 ) ;
V_163 -> V_165 . V_166 [ 2 ] = V_164 . V_62 ;
V_163 -> V_165 . V_166 [ 3 ] = V_164 . V_167 ;
return V_88 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_1 * V_167 , T_1 * V_159 ,
T_3 * V_168 )
{
int V_169 = 0 ;
struct V_162 V_163 ;
if ( F_50 ( & V_163 , V_2 , V_170 ) )
return - V_121 ;
V_169 = F_51 ( V_2 , & V_163 ) ;
if ( V_169 != V_171 ) {
if ( F_48 ( V_2 , & V_163 ) ) {
F_52 ( & V_163 ) ;
return - V_97 ;
}
* V_168 = 1 ;
}
* V_159 = V_163 . V_165 . V_166 [ 2 ] ;
* V_167 = V_163 . V_165 . V_166 [ 3 ] ;
F_52 ( & V_163 ) ;
if ( ! ( * V_159 ) )
return - V_97 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
T_1 * V_5 , T_1 V_159 )
{
int V_169 = 0 , V_6 ;
void * V_172 ;
T_2 * V_173 ;
struct V_162 V_163 ;
T_5 V_174 = 0 ;
V_172 = F_54 ( & V_2 -> V_33 -> V_34 , V_159 ,
& V_174 , V_120 ) ;
if ( ! V_172 )
return - V_121 ;
if ( F_50 ( & V_163 , V_2 , V_175 ) ) {
V_169 = - V_121 ;
goto V_176;
}
V_163 . V_177 . V_166 [ 1 ] = F_31 ( V_174 ) ;
V_163 . V_177 . V_166 [ 2 ] = F_32 ( V_174 ) ;
V_163 . V_177 . V_166 [ 3 ] = V_159 ;
V_169 = F_51 ( V_2 , & V_163 ) ;
V_173 = V_172 ;
if ( V_169 == V_171 ) {
for ( V_6 = 0 ; V_6 < V_159 / sizeof( T_1 ) ; V_6 ++ )
* V_5 ++ = F_55 ( * V_173 ++ ) ;
}
F_52 ( & V_163 ) ;
V_176:
F_56 ( & V_2 -> V_33 -> V_34 , V_159 , V_172 , V_174 ) ;
return V_169 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_169 ;
T_1 V_159 = 0 ;
T_1 V_167 , V_178 , * V_173 ;
struct V_179 * V_21 ;
struct V_19 * V_23 ;
T_3 V_168 = 0 ;
V_21 = V_2 -> V_21 ;
V_169 = F_49 ( V_2 , & V_167 , & V_159 ,
& V_168 ) ;
if ( V_169 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_13 , V_169 ) ;
return - V_97 ;
}
V_21 -> V_22 . V_23 = F_58 ( V_159 ) ;
if ( ! V_21 -> V_22 . V_23 )
return - V_121 ;
V_173 = ( T_1 * ) V_21 -> V_22 . V_23 ;
if ( V_168 )
goto V_180;
V_169 = F_53 ( V_2 , V_173 , V_159 ) ;
if ( V_169 ) {
V_180:
V_169 = F_44 ( V_2 , ( T_3 * ) V_173 ,
V_159 ) ;
if ( V_169 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_14 ,
V_169 ) ;
F_59 ( V_21 -> V_22 . V_23 ) ;
V_21 -> V_22 . V_23 = NULL ;
return - V_97 ;
}
}
V_178 = F_43 ( ( T_6 * ) V_173 , V_159 ) ;
if ( V_178 ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_15 ) ;
F_59 ( V_21 -> V_22 . V_23 ) ;
V_21 -> V_22 . V_23 = NULL ;
return - V_97 ;
}
V_23 = V_21 -> V_22 . V_23 ;
V_23 -> V_181 = V_23 -> V_182 ;
F_7 ( & V_2 -> V_33 -> V_34 ,
L_16 ,
V_23 -> V_182 ) ;
if ( ( V_23 -> V_167 & 0xfffff ) >= 0x20001 )
V_21 -> V_22 . V_132 = true ;
else
V_21 -> V_22 . V_132 = false ;
F_60 ( V_2 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
T_2 * V_5 ;
T_1 V_183 ;
char V_184 [ 64 ] ;
char * V_185 [] = { V_184 , NULL } ;
int V_6 , V_14 , V_186 , V_187 , V_188 = 0 ;
T_1 V_189 , V_190 , V_191 , V_192 = 0 ;
struct V_3 * V_4 ;
struct V_112 * V_22 = & V_2 -> V_21 -> V_22 ;
struct V_19 * V_23 = V_22 -> V_23 ;
static const struct V_193 * V_194 ;
struct V_100 * V_34 = & V_2 -> V_33 -> V_34 ;
struct V_179 * V_21 ;
void * V_158 ;
V_21 = V_2 -> V_21 ;
if ( ! V_23 )
return - V_97 ;
if ( ! F_62 ( V_2 ) ) {
F_7 ( & V_2 -> V_33 -> V_34 , L_17 ) ;
return - V_97 ;
}
if ( V_22 -> V_195 ) {
F_7 ( & V_2 -> V_33 -> V_34 ,
L_18 ) ;
return - V_97 ;
}
F_63 ( V_2 -> V_21 , V_196 , V_2 -> V_197 , L_19 ) ;
for ( V_6 = 2 , V_14 = 1 ; ( V_6 & V_198 ) ; V_6 <<= 1 , V_14 ++ )
if ( V_6 & V_23 -> V_181 )
V_188 += V_23 -> V_199 [ V_14 ] ;
if ( ! V_188 )
return - V_97 ;
V_22 -> V_8 = F_58 ( V_188 ) ;
if ( ! V_22 -> V_8 )
return - V_121 ;
V_5 = V_22 -> V_8 ;
V_22 -> V_62 = V_188 ;
V_191 = V_23 -> V_200 ;
V_189 = V_23 -> V_201 ;
V_23 -> V_202 [ 0 ] = V_203 ;
V_23 -> V_202 [ 1 ] = V_2 -> V_204 ;
if ( V_22 -> V_132 ) {
V_158 = F_54 ( V_34 , V_127 ,
& V_22 -> V_122 ,
V_120 ) ;
if ( ! V_158 )
V_22 -> V_132 = false ;
else
V_22 -> V_118 = V_158 ;
}
if ( F_45 ( V_2 ) ) {
V_186 = F_64 ( V_205 ) ;
V_194 = V_205 ;
} else {
V_186 = F_64 ( V_206 ) ;
V_194 = V_206 ;
V_183 = V_23 -> V_207 [ V_2 -> V_21 -> V_71 ] ;
V_23 -> V_38 [ V_208 ] = V_183 ;
V_23 -> V_38 [ V_209 ] = V_21 -> V_71 ;
}
for ( V_6 = 0 ; V_6 < V_191 ; V_6 ++ ) {
V_4 = ( void * ) V_23 + V_189 ;
if ( ! ( V_4 -> V_133 . V_134 & V_23 -> V_181 ) ) {
V_4 -> V_133 . V_135 |= V_136 ;
V_189 += V_4 -> V_133 . V_201 ;
continue;
}
V_187 = 0 ;
while ( V_187 < V_186 ) {
if ( V_4 -> V_133 . type == V_194 [ V_187 ] . V_24 )
break;
V_187 ++ ;
}
if ( V_187 == V_186 ) {
F_7 ( & V_2 -> V_33 -> V_34 ,
L_20 ,
V_4 -> V_133 . type ) ;
goto error;
}
V_190 = V_194 [ V_187 ] . F_65 ( V_2 , V_4 , V_5 ) ;
if ( ! F_37 ( & V_2 -> V_33 -> V_34 , V_4 , V_190 ) )
V_4 -> V_133 . V_135 |= V_136 ;
V_192 += V_4 -> V_133 . V_137 ;
V_189 += V_4 -> V_133 . V_201 ;
V_5 = V_22 -> V_8 + V_192 ;
}
if ( V_188 != V_192 ) {
F_7 ( & V_2 -> V_33 -> V_34 ,
L_21 ,
V_192 , V_188 ) ;
goto error;
} else {
V_22 -> V_195 = 1 ;
snprintf ( V_184 , sizeof( V_184 ) , L_22 ,
V_2 -> V_197 -> V_210 ) ;
F_7 ( & V_2 -> V_33 -> V_34 , L_23 ,
V_2 -> V_197 -> V_210 , V_22 -> V_62 ) ;
F_66 ( & V_2 -> V_33 -> V_34 . V_211 , V_212 , V_185 ) ;
return 0 ;
}
error:
if ( V_22 -> V_132 )
F_56 ( V_34 , V_127 ,
V_22 -> V_118 , V_22 -> V_122 ) ;
F_59 ( V_22 -> V_8 ) ;
return - V_35 ;
}
void F_67 ( struct V_1 * V_2 )
{
T_1 V_213 , V_214 ;
struct V_179 * V_21 = V_2 -> V_21 ;
struct V_112 * V_22 = & V_21 -> V_22 ;
struct V_215 * V_33 = V_2 -> V_33 ;
V_213 = V_2 -> V_204 ;
V_214 = F_68 ( V_2 ) ;
if ( V_22 -> V_23 == NULL || V_214 > V_213 ) {
if ( V_22 -> V_23 )
F_59 ( V_22 -> V_23 ) ;
if ( ! F_57 ( V_2 ) )
F_7 ( & V_33 -> V_34 , L_24 ) ;
}
}
