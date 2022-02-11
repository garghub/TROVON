static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 >= V_4 &&
V_2 -> V_3 <= V_5 ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 >= V_6 &&
V_2 -> V_3 <= V_7 ;
}
static inline int F_3 ( const struct V_8 * V_9 ,
struct V_10 * V_11 )
{
int V_12 ;
return F_4 ( V_9 -> V_13 ,
F_5 ( V_9 -> V_13 ,
V_9 -> V_14 -> V_15 ) ,
V_11 , V_11 -> V_16 , & V_12 ,
V_17 ) ;
}
static int F_6 ( const struct V_8 * V_9 , T_1 V_2 ,
struct V_10 * V_11 )
{
struct V_10 * V_18 ;
void * V_19 ;
int V_12 ;
int V_20 ;
int V_21 ;
unsigned long V_22 = V_23 + F_7 ( V_24 ) ;
V_19 = F_8 ( V_25 , V_26 ) ;
if ( ! V_19 )
return - V_27 ;
do {
V_20 = F_4 ( V_9 -> V_13 ,
F_9 ( V_9 -> V_13 ,
V_9 -> V_28 -> V_15 ) ,
V_19 , V_25 , & V_12 ,
V_24 ) ;
if ( V_20 < 0 )
goto V_29;
V_21 = 0 ;
while ( V_21 <= V_12 - V_30 ) {
V_18 = V_19 + V_21 ;
if ( V_18 -> V_16 == 0 ) {
V_21 = F_10 ( V_21 , F_11 ( V_9 -> V_28 ->
V_31 ) ) ;
continue;
}
if ( V_21 + V_18 -> V_16 > V_12 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_1 ) ;
break;
}
if ( V_18 -> V_2 == V_2 ) {
memcpy ( V_11 , V_18 , V_18 -> V_16 ) ;
goto V_29;
}
V_21 += V_18 -> V_16 ;
}
} while ( F_13 ( V_23 , V_22 ) );
V_20 = - V_33 ;
V_29:
F_14 ( V_19 ) ;
return V_20 ;
}
static int F_15 ( const struct V_8 * V_9 ,
T_1 V_34 , int V_35 )
{
struct V_10 * V_11 ;
int V_36 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_26 ) ;
if ( ! V_11 )
return - V_27 ;
V_11 -> V_2 = V_34 ;
V_11 -> V_16 = V_30 + sizeof( struct V_37 ) ;
V_11 -> V_38 . V_39 . V_35 = V_35 ;
V_11 -> V_38 . V_39 . V_40 = 0xff ;
V_36 = F_3 ( V_9 , V_11 ) ;
F_14 ( V_11 ) ;
return V_36 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_10 V_11 ;
int V_20 ;
V_20 = F_15 ( V_9 , V_41 , 0 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_9 , V_42 , & V_11 ) ;
if ( V_20 )
return V_20 ;
switch ( V_9 -> V_43 ) {
case V_44 :
V_9 -> V_45 = F_18 ( V_11 . V_38 . V_46 . V_47 . V_45 ) ;
V_9 -> V_48 =
F_11 ( V_11 . V_38 . V_46 . V_47 . V_49 ) ;
break;
case V_50 :
V_9 -> V_45 = F_18 ( V_11 . V_38 . V_51 . V_47 . V_45 ) ;
V_9 -> V_48 =
F_11 ( V_11 . V_38 . V_51 . V_47 . V_49 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_8 * V_9 )
{
struct V_10 V_11 ;
int V_20 ;
V_20 = F_15 ( V_9 , V_52 , 0 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_9 , V_53 , & V_11 ) ;
if ( V_20 )
return V_20 ;
V_9 -> V_54 = V_11 . V_38 . V_55 . V_54 ;
if ( ( V_9 -> V_54 > V_56 ) ||
( V_9 -> V_43 == V_50 &&
V_9 -> V_54 > V_57 ) )
return - V_33 ;
return 0 ;
}
static void F_20 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
unsigned long V_68 ;
T_1 V_35 , V_40 ;
V_35 = V_11 -> V_38 . V_69 . V_35 ;
V_40 = V_11 -> V_38 . V_69 . V_40 ;
if ( V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_35 ] ;
if ( ! F_21 ( V_63 -> V_71 ) )
return;
V_59 = & V_63 -> V_71 -> V_59 ;
V_61 = & V_63 -> V_72 [ V_40 % V_9 -> V_48 ] ;
if ( V_63 -> V_73 . V_74 &&
( V_63 -> V_73 . V_75 >= V_76 ) ) {
V_65 = F_22 ( V_63 -> V_71 , & V_67 ) ;
if ( V_65 ) {
V_67 -> V_77 |= V_78 ;
V_59 -> V_79 ++ ;
V_59 -> V_80 += V_67 -> V_81 ;
F_23 ( V_65 ) ;
} else {
F_24 ( V_63 -> V_71 ,
L_3 ) ;
}
V_63 -> V_73 . V_82 . V_83 ++ ;
F_25 ( V_63 -> V_71 ) ;
V_63 -> V_73 . V_75 = V_84 ;
}
V_59 -> V_85 ++ ;
V_59 -> V_86 += V_61 -> V_87 ;
F_26 ( & V_63 -> V_88 , V_68 ) ;
F_27 ( V_63 -> V_71 , V_61 -> V_89 ) ;
V_61 -> V_89 = V_9 -> V_48 ;
-- V_63 -> V_90 ;
F_28 ( V_63 -> V_71 ) ;
F_29 ( & V_63 -> V_88 , V_68 ) ;
}
static void F_30 ( struct V_91 * V_91 )
{
struct V_92 * V_71 = V_91 -> V_61 ;
F_14 ( V_91 -> V_93 ) ;
if ( V_91 -> V_94 )
F_31 ( V_71 , L_4 ,
V_91 -> V_94 ) ;
}
static int F_32 ( struct V_62 * V_63 ,
T_1 V_34 )
{
struct V_8 * V_9 = V_63 -> V_9 ;
struct V_92 * V_71 = V_63 -> V_71 ;
struct V_10 * V_11 ;
struct V_91 * V_91 ;
void * V_19 ;
int V_20 ;
V_91 = F_33 ( 0 , V_95 ) ;
if ( ! V_91 ) {
F_24 ( V_71 , L_5 ) ;
return - V_27 ;
}
V_19 = F_16 ( sizeof( struct V_10 ) , V_95 ) ;
if ( ! V_19 ) {
F_34 ( V_91 ) ;
return - V_27 ;
}
V_11 = (struct V_10 * ) V_19 ;
V_11 -> V_16 = V_30 + sizeof( struct V_37 ) ;
V_11 -> V_2 = V_34 ;
V_11 -> V_38 . V_39 . V_35 = V_63 -> V_35 ;
F_35 ( V_91 , V_9 -> V_13 ,
F_5 ( V_9 -> V_13 ,
V_9 -> V_14 -> V_15 ) ,
V_19 , V_11 -> V_16 ,
F_30 , V_71 ) ;
F_36 ( V_91 , & V_63 -> V_96 ) ;
V_20 = F_37 ( V_91 , V_95 ) ;
if ( V_20 ) {
F_24 ( V_71 , L_6 ) ;
F_38 ( V_91 ) ;
F_34 ( V_91 ) ;
return V_20 ;
}
F_34 ( V_91 ) ;
return 0 ;
}
static void F_39 ( struct V_62 * V_63 ,
const struct V_97 * V_98 ,
struct V_66 * V_67 )
{
struct V_8 * V_9 = V_63 -> V_9 ;
struct V_58 * V_59 = & V_63 -> V_71 -> V_59 ;
enum V_99 V_100 , V_101 , V_102 , V_103 ;
F_40 ( V_63 -> V_71 , L_7 , V_98 -> V_94 ) ;
V_101 = V_100 = V_63 -> V_73 . V_75 ;
if ( V_98 -> V_94 & ( V_104 | V_105 ) )
V_101 = V_76 ;
else if ( V_98 -> V_94 & V_106 )
V_101 = V_107 ;
else if ( V_98 -> V_94 & V_108 ) {
if ( V_100 < V_76 ) {
if ( ( V_98 -> V_109 >= 128 ) || ( V_98 -> V_110 >= 128 ) )
V_101 = V_107 ;
else if ( ( V_98 -> V_109 >= 96 ) || ( V_98 -> V_110 >= 96 ) )
V_101 = V_111 ;
else if ( V_100 > V_84 )
V_101 = V_84 ;
}
}
if ( ! V_98 -> V_94 )
V_101 = V_84 ;
if ( V_101 != V_100 ) {
V_102 = ( V_98 -> V_109 >= V_98 -> V_110 ) ? V_101 : 0 ;
V_103 = ( V_98 -> V_109 <= V_98 -> V_110 ) ? V_101 : 0 ;
F_41 ( V_63 -> V_71 , V_67 , V_102 , V_103 ) ;
}
if ( V_63 -> V_73 . V_74 &&
( V_100 >= V_76 ) &&
( V_101 < V_76 ) ) {
V_63 -> V_73 . V_82 . V_83 ++ ;
}
switch ( V_9 -> V_43 ) {
case V_44 :
if ( V_98 -> V_46 . V_112 ) {
V_63 -> V_73 . V_82 . V_113 ++ ;
V_59 -> V_114 ++ ;
}
break;
case V_50 :
if ( V_98 -> V_51 . V_115 & V_116 )
V_59 -> V_117 ++ ;
if ( V_98 -> V_51 . V_115 & V_118 )
V_59 -> V_114 ++ ;
if ( V_98 -> V_51 . V_115 & V_119 ) {
V_63 -> V_73 . V_82 . V_113 ++ ;
}
break;
}
V_63 -> V_120 . V_109 = V_98 -> V_109 ;
V_63 -> V_120 . V_110 = V_98 -> V_110 ;
}
static void F_42 ( const struct V_8 * V_9 ,
const struct V_97 * V_98 )
{
struct V_66 * V_67 , V_121 = { . V_77 = V_122 , . V_81 = V_123 } ;
struct V_64 * V_65 ;
struct V_58 * V_59 ;
struct V_62 * V_63 ;
enum V_99 V_124 , V_101 ;
if ( V_98 -> V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_98 -> V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_98 -> V_35 ] ;
V_59 = & V_63 -> V_71 -> V_59 ;
V_124 = V_63 -> V_73 . V_75 ;
F_39 ( V_63 , V_98 , & V_121 ) ;
V_101 = V_63 -> V_73 . V_75 ;
V_65 = F_22 ( V_63 -> V_71 , & V_67 ) ;
if ( ! V_65 ) {
V_59 -> V_125 ++ ;
return;
}
memcpy ( V_67 , & V_121 , sizeof( * V_67 ) ) ;
if ( V_101 != V_124 ) {
if ( V_98 -> V_94 &
( V_104 | V_105 ) ) {
if ( ! V_63 -> V_73 . V_74 )
F_32 ( V_63 , V_126 ) ;
F_43 ( V_63 -> V_71 ) ;
}
if ( V_63 -> V_73 . V_74 &&
( V_124 >= V_76 ) &&
( V_101 < V_76 ) ) {
V_67 -> V_77 |= V_78 ;
F_25 ( V_63 -> V_71 ) ;
}
}
switch ( V_9 -> V_43 ) {
case V_44 :
if ( V_98 -> V_46 . V_112 ) {
V_67 -> V_77 |= V_127 | V_128 ;
if ( V_98 -> V_46 . V_112 & V_129 )
V_67 -> V_130 [ 3 ] = V_131 ;
if ( V_98 -> V_46 . V_112 & V_132 )
V_67 -> V_130 [ 3 ] = V_133 ;
if ( V_98 -> V_46 . V_112 & V_134 )
V_67 -> V_130 [ 2 ] |= V_135 ;
if ( V_98 -> V_46 . V_112 & V_136 )
V_67 -> V_130 [ 2 ] |= V_137 ;
if ( V_98 -> V_46 . V_112 & V_138 )
V_67 -> V_130 [ 2 ] |= V_139 ;
if ( V_98 -> V_46 . V_112 & V_140 )
V_67 -> V_130 [ 2 ] |= V_141 ;
if ( V_98 -> V_46 . V_112 & V_142 )
V_67 -> V_130 [ 2 ] |= V_143 ;
}
break;
case V_50 :
if ( V_98 -> V_51 . V_115 & V_119 ) {
V_67 -> V_77 |= V_127 ;
}
break;
}
V_67 -> V_130 [ 6 ] = V_98 -> V_109 ;
V_67 -> V_130 [ 7 ] = V_98 -> V_110 ;
V_59 -> V_79 ++ ;
V_59 -> V_80 += V_67 -> V_81 ;
F_23 ( V_65 ) ;
}
static void F_44 ( const struct V_8 * V_9 ,
struct V_97 * V_98 )
{
struct V_62 * V_63 ;
int V_35 ;
bool V_144 ;
V_35 = V_98 -> V_35 ;
if ( V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_35 ] ;
V_144 = false ;
if ( V_98 -> V_109 != V_63 -> V_120 . V_109 ) {
V_98 -> V_51 . V_115 |= V_116 ;
V_144 = true ;
}
if ( V_98 -> V_110 != V_63 -> V_120 . V_110 ) {
V_98 -> V_51 . V_115 |= V_118 ;
V_144 = true ;
}
if ( ( V_98 -> V_94 & V_108 ) &&
! ( V_98 -> V_51 . V_145 & V_108 ) ) {
V_98 -> V_51 . V_115 |= V_119 ;
V_144 = true ;
}
if ( V_144 )
F_42 ( V_9 , V_98 ) ;
}
static void F_45 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_97 V_98 = { } ;
switch ( V_11 -> V_2 ) {
case V_146 :
V_98 . V_35 = V_11 -> V_38 . V_51 . V_147 . V_35 ;
V_98 . V_94 = V_11 -> V_38 . V_51 . V_147 . V_94 ;
V_98 . V_109 = V_11 -> V_38 . V_51 . V_147 . V_148 ;
V_98 . V_110 = V_11 -> V_38 . V_51 . V_147 . V_149 ;
F_44 ( V_9 , & V_98 ) ;
break;
case V_150 :
V_98 . V_35 = 0 ;
V_98 . V_94 = V_11 -> V_38 . V_51 . V_151 . V_152 ;
V_98 . V_109 = V_11 -> V_38 . V_51 . V_151 . V_153 ;
V_98 . V_110 = V_11 -> V_38 . V_51 . V_151 . V_154 ;
V_98 . V_51 . V_145 =
V_11 -> V_38 . V_51 . V_151 . V_155 ;
F_44 ( V_9 , & V_98 ) ;
if ( V_9 -> V_54 == V_57 ) {
V_98 . V_35 = 1 ;
V_98 . V_94 = V_11 -> V_38 . V_51 . V_151 . V_155 ;
V_98 . V_109 = V_11 -> V_38 . V_51 . V_151 . V_156 ;
V_98 . V_110 = V_11 -> V_38 . V_51 . V_151 . V_157 ;
V_98 . V_51 . V_145 =
V_11 -> V_38 . V_51 . V_151 . V_152 ;
F_44 ( V_9 , & V_98 ) ;
}
break;
default:
F_12 ( V_9 -> V_13 -> V_9 . V_32 , L_8 ,
V_11 -> V_2 ) ;
}
}
static void F_46 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_97 V_98 = { } ;
switch ( V_11 -> V_2 ) {
case V_150 :
V_98 . V_35 = V_11 -> V_38 . V_46 . V_151 . V_35 ;
V_98 . V_94 = V_11 -> V_38 . V_46 . V_151 . V_94 ;
V_98 . V_109 = V_11 -> V_38 . V_46 . V_151 . V_148 ;
V_98 . V_110 = V_11 -> V_38 . V_46 . V_151 . V_149 ;
V_98 . V_46 . V_112 = V_11 -> V_38 . V_46 . V_151 . V_112 ;
break;
case V_158 :
V_98 . V_35 = V_11 -> V_38 . V_46 . V_159 . V_35 ;
V_98 . V_94 = V_11 -> V_38 . V_46 . V_159 . V_130 [ 0 ] ;
V_98 . V_109 = V_11 -> V_38 . V_46 . V_159 . V_130 [ 2 ] ;
V_98 . V_110 = V_11 -> V_38 . V_46 . V_159 . V_130 [ 3 ] ;
V_98 . V_46 . V_112 = V_11 -> V_38 . V_46 . V_159 . V_130 [ 1 ] ;
break;
case V_146 :
V_98 . V_35 = V_11 -> V_38 . V_46 . V_147 . V_35 ;
V_98 . V_94 = V_11 -> V_38 . V_46 . V_147 . V_94 ;
V_98 . V_109 = V_11 -> V_38 . V_46 . V_147 . V_148 ;
V_98 . V_110 = V_11 -> V_38 . V_46 . V_147 . V_149 ;
V_98 . V_46 . V_112 = 0 ;
break;
default:
F_12 ( V_9 -> V_13 -> V_9 . V_32 , L_8 ,
V_11 -> V_2 ) ;
return;
}
F_42 ( V_9 , & V_98 ) ;
}
static void F_47 ( const struct V_62 * V_63 ,
const struct V_10 * V_11 )
{
struct V_66 * V_67 ;
struct V_64 * V_65 ;
struct V_58 * V_59 = & V_63 -> V_71 -> V_59 ;
if ( V_11 -> V_38 . V_160 . V_161 & ( V_162 |
V_163 ) ) {
F_24 ( V_63 -> V_71 , L_9 ,
V_11 -> V_38 . V_160 . V_161 ) ;
V_59 -> V_114 ++ ;
return;
}
if ( V_11 -> V_38 . V_160 . V_161 & V_164 ) {
V_59 -> V_165 ++ ;
V_59 -> V_114 ++ ;
V_65 = F_22 ( V_63 -> V_71 , & V_67 ) ;
if ( ! V_65 ) {
V_59 -> V_125 ++ ;
return;
}
V_67 -> V_77 |= V_166 ;
V_67 -> V_130 [ 1 ] = V_167 ;
V_59 -> V_79 ++ ;
V_59 -> V_80 += V_67 -> V_81 ;
F_23 ( V_65 ) ;
}
}
static void F_48 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_62 * V_63 ;
struct V_66 * V_67 ;
struct V_64 * V_65 ;
struct V_58 * V_59 ;
T_1 V_35 = V_11 -> V_38 . V_160 . V_35 ;
const T_1 * V_168 = NULL ;
if ( V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_35 ] ;
V_59 = & V_63 -> V_71 -> V_59 ;
if ( ( V_11 -> V_38 . V_160 . V_161 & V_162 ) &&
( V_9 -> V_43 == V_44 && V_11 -> V_2 == V_158 ) ) {
F_46 ( V_9 , V_11 ) ;
return;
} else if ( V_11 -> V_38 . V_160 . V_161 & ( V_162 |
V_163 |
V_164 ) ) {
F_47 ( V_63 , V_11 ) ;
return;
} else if ( V_11 -> V_38 . V_160 . V_161 & ~ V_169 ) {
F_31 ( V_63 -> V_71 ,
L_10 ,
V_11 -> V_38 . V_160 . V_161 ) ;
return;
}
switch ( V_9 -> V_43 ) {
case V_44 :
V_168 = V_11 -> V_38 . V_46 . V_170 . V_11 ;
break;
case V_50 :
V_168 = V_11 -> V_38 . V_51 . V_170 . V_11 ;
break;
}
V_65 = F_49 ( V_63 -> V_71 , & V_67 ) ;
if ( ! V_65 ) {
V_59 -> V_171 ++ ;
return;
}
if ( V_9 -> V_43 == V_44 && V_11 -> V_2 == V_158 ) {
V_67 -> V_77 = F_18 ( V_11 -> V_38 . V_46 . V_159 . V_2 ) ;
if ( V_67 -> V_77 & V_172 )
V_67 -> V_77 &= V_173 | V_174 ;
else
V_67 -> V_77 &= V_175 ;
V_67 -> V_81 = F_50 ( V_11 -> V_38 . V_46 . V_159 . V_87 ) ;
if ( V_11 -> V_38 . V_46 . V_159 . V_68 & V_169 )
V_67 -> V_77 |= V_176 ;
else
memcpy ( V_67 -> V_130 , & V_11 -> V_38 . V_46 . V_159 . V_130 ,
V_67 -> V_81 ) ;
} else {
V_67 -> V_77 = ( ( V_168 [ 0 ] & 0x1f ) << 6 ) | ( V_168 [ 1 ] & 0x3f ) ;
if ( V_11 -> V_2 == V_177 ) {
V_67 -> V_77 <<= 18 ;
V_67 -> V_77 |= ( ( V_168 [ 2 ] & 0x0f ) << 14 ) |
( ( V_168 [ 3 ] & 0xff ) << 6 ) |
( V_168 [ 4 ] & 0x3f ) ;
V_67 -> V_77 |= V_174 ;
}
V_67 -> V_81 = F_50 ( V_168 [ 5 ] ) ;
if ( V_11 -> V_38 . V_160 . V_161 & V_169 )
V_67 -> V_77 |= V_176 ;
else
memcpy ( V_67 -> V_130 , & V_168 [ 6 ] ,
V_67 -> V_81 ) ;
}
V_59 -> V_79 ++ ;
V_59 -> V_80 += V_67 -> V_81 ;
F_23 ( V_65 ) ;
}
static void F_51 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_62 * V_63 ;
T_1 V_35 = V_11 -> V_38 . V_39 . V_35 ;
if ( V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_35 ] ;
if ( F_52 ( & V_63 -> V_178 ) &&
F_53 ( V_63 -> V_71 ) ) {
F_28 ( V_63 -> V_71 ) ;
} else {
F_54 ( V_63 -> V_71 ) ;
F_55 ( & V_63 -> V_178 ) ;
}
}
static void F_56 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_62 * V_63 ;
T_1 V_35 = V_11 -> V_38 . V_39 . V_35 ;
if ( V_35 >= V_9 -> V_54 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_2 , V_35 ) ;
return;
}
V_63 = V_9 -> V_70 [ V_35 ] ;
F_55 ( & V_63 -> V_179 ) ;
}
static void F_57 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
switch ( V_11 -> V_2 ) {
case V_180 :
F_51 ( V_9 , V_11 ) ;
break;
case V_181 :
F_56 ( V_9 , V_11 ) ;
break;
case V_182 :
case V_177 :
F_48 ( V_9 , V_11 ) ;
break;
case V_158 :
if ( V_9 -> V_43 != V_44 )
goto V_183;
F_48 ( V_9 , V_11 ) ;
break;
case V_146 :
case V_150 :
if ( V_9 -> V_43 == V_44 )
F_46 ( V_9 , V_11 ) ;
else
F_45 ( V_9 , V_11 ) ;
break;
case V_184 :
F_20 ( V_9 , V_11 ) ;
break;
case V_185 :
if ( V_9 -> V_43 != V_50 )
goto V_183;
break;
default:
V_183: F_58 ( V_9 -> V_13 -> V_9 . V_32 ,
L_11 , V_11 -> V_2 ) ;
break;
}
}
static void F_59 ( struct V_91 * V_91 )
{
struct V_8 * V_9 = V_91 -> V_61 ;
struct V_10 * V_11 ;
int V_21 = 0 ;
int V_20 , V_186 ;
switch ( V_91 -> V_94 ) {
case 0 :
break;
case - V_187 :
case - V_188 :
return;
default:
F_60 ( V_9 -> V_13 -> V_9 . V_32 , L_12 ,
V_91 -> V_94 ) ;
goto V_189;
}
while ( V_21 <= V_91 -> V_190 - V_30 ) {
V_11 = V_91 -> V_93 + V_21 ;
if ( V_11 -> V_16 == 0 ) {
V_21 = F_10 ( V_21 , F_11 ( V_9 -> V_28 ->
V_31 ) ) ;
continue;
}
if ( V_21 + V_11 -> V_16 > V_91 -> V_190 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 , L_1 ) ;
break;
}
F_57 ( V_9 , V_11 ) ;
V_21 += V_11 -> V_16 ;
}
V_189:
F_35 ( V_91 , V_9 -> V_13 ,
F_9 ( V_9 -> V_13 ,
V_9 -> V_28 -> V_15 ) ,
V_91 -> V_93 , V_25 ,
F_59 , V_9 ) ;
V_20 = F_37 ( V_91 , V_95 ) ;
if ( V_20 == - V_191 ) {
for ( V_186 = 0 ; V_186 < V_9 -> V_54 ; V_186 ++ ) {
if ( ! V_9 -> V_70 [ V_186 ] )
continue;
F_61 ( V_9 -> V_70 [ V_186 ] -> V_71 ) ;
}
} else if ( V_20 ) {
F_12 ( V_9 -> V_13 -> V_9 . V_32 ,
L_13 , V_20 ) ;
}
return;
}
static int F_62 ( struct V_8 * V_9 )
{
int V_186 , V_20 = 0 ;
if ( V_9 -> V_192 )
return 0 ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ ) {
struct V_91 * V_91 = NULL ;
T_1 * V_19 = NULL ;
T_2 V_194 ;
V_91 = F_33 ( 0 , V_26 ) ;
if ( ! V_91 ) {
F_58 ( V_9 -> V_13 -> V_9 . V_32 ,
L_5 ) ;
V_20 = - V_27 ;
break;
}
V_19 = F_63 ( V_9 -> V_13 , V_25 ,
V_26 , & V_194 ) ;
if ( ! V_19 ) {
F_58 ( V_9 -> V_13 -> V_9 . V_32 ,
L_14 ) ;
F_34 ( V_91 ) ;
V_20 = - V_27 ;
break;
}
F_35 ( V_91 , V_9 -> V_13 ,
F_9 ( V_9 -> V_13 ,
V_9 -> V_28 -> V_15 ) ,
V_19 , V_25 ,
F_59 ,
V_9 ) ;
V_91 -> V_195 = V_194 ;
V_91 -> V_196 |= V_197 ;
F_36 ( V_91 , & V_9 -> V_198 ) ;
V_20 = F_37 ( V_91 , V_26 ) ;
if ( V_20 ) {
F_38 ( V_91 ) ;
F_64 ( V_9 -> V_13 , V_25 , V_19 ,
V_194 ) ;
F_34 ( V_91 ) ;
break;
}
V_9 -> V_199 [ V_186 ] = V_19 ;
V_9 -> V_200 [ V_186 ] = V_194 ;
F_34 ( V_91 ) ;
}
if ( V_186 == 0 ) {
F_58 ( V_9 -> V_13 -> V_9 . V_32 ,
L_15 , V_20 ) ;
return V_20 ;
} else if ( V_186 < V_193 ) {
F_58 ( V_9 -> V_13 -> V_9 . V_32 ,
L_16 ) ;
}
V_9 -> V_192 = true ;
return 0 ;
}
static int F_65 ( const struct V_62 * V_63 )
{
struct V_10 * V_11 ;
int V_36 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_26 ) ;
if ( ! V_11 )
return - V_27 ;
V_11 -> V_2 = V_201 ;
V_11 -> V_16 = V_30 + sizeof( struct V_202 ) ;
V_11 -> V_38 . V_203 . V_40 = 0xff ;
V_11 -> V_38 . V_203 . V_35 = V_63 -> V_35 ;
if ( V_63 -> V_73 . V_204 & V_205 )
V_11 -> V_38 . V_203 . V_203 = V_206 ;
else
V_11 -> V_38 . V_203 . V_203 = V_207 ;
V_36 = F_3 ( V_63 -> V_9 , V_11 ) ;
F_14 ( V_11 ) ;
return V_36 ;
}
static int F_66 ( struct V_62 * V_63 )
{
int V_20 ;
F_67 ( & V_63 -> V_178 ) ;
V_20 = F_15 ( V_63 -> V_9 , V_208 ,
V_63 -> V_35 ) ;
if ( V_20 )
return V_20 ;
if ( ! F_68 ( & V_63 -> V_178 ,
F_7 ( V_209 ) ) )
return - V_210 ;
return 0 ;
}
static int F_69 ( struct V_92 * V_71 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
struct V_8 * V_9 = V_63 -> V_9 ;
int V_20 ;
V_20 = F_71 ( V_71 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_62 ( V_9 ) ;
if ( V_20 )
goto error;
V_20 = F_65 ( V_63 ) ;
if ( V_20 )
goto error;
V_20 = F_66 ( V_63 ) ;
if ( V_20 ) {
F_31 ( V_71 , L_17 , V_20 ) ;
goto error;
}
V_63 -> V_73 . V_75 = V_84 ;
return 0 ;
error:
F_72 ( V_71 ) ;
return V_20 ;
}
static void F_73 ( struct V_62 * V_63 )
{
int V_186 , V_48 ;
V_48 = V_63 -> V_9 -> V_48 ;
V_63 -> V_90 = 0 ;
for ( V_186 = 0 ; V_186 < V_48 ; V_186 ++ )
V_63 -> V_72 [ V_186 ] . V_89 = V_48 ;
}
static void F_74 ( struct V_62 * V_63 )
{
F_75 ( & V_63 -> V_96 ) ;
F_73 ( V_63 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
int V_186 ;
F_75 ( & V_9 -> V_198 ) ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ )
F_64 ( V_9 -> V_13 , V_25 ,
V_9 -> V_199 [ V_186 ] ,
V_9 -> V_200 [ V_186 ] ) ;
for ( V_186 = 0 ; V_186 < V_9 -> V_54 ; V_186 ++ ) {
struct V_62 * V_63 = V_9 -> V_70 [ V_186 ] ;
if ( V_63 )
F_74 ( V_63 ) ;
}
}
static int F_77 ( struct V_62 * V_63 )
{
int V_20 ;
F_67 ( & V_63 -> V_179 ) ;
V_20 = F_15 ( V_63 -> V_9 , V_126 ,
V_63 -> V_35 ) ;
if ( V_20 )
return V_20 ;
if ( ! F_68 ( & V_63 -> V_179 ,
F_7 ( V_211 ) ) )
return - V_210 ;
return 0 ;
}
static int F_78 ( struct V_62 * V_63 )
{
struct V_10 * V_11 ;
int V_36 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_26 ) ;
if ( ! V_11 )
return - V_27 ;
V_11 -> V_2 = V_212 ;
V_11 -> V_16 = V_30 + sizeof( struct V_213 ) ;
V_11 -> V_38 . V_214 . V_35 = V_63 -> V_35 ;
V_11 -> V_38 . V_214 . V_68 = 0x00 ;
V_36 = F_3 ( V_63 -> V_9 , V_11 ) ;
F_14 ( V_11 ) ;
return V_36 ;
}
static int F_79 ( struct V_92 * V_71 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
struct V_8 * V_9 = V_63 -> V_9 ;
int V_20 ;
F_80 ( V_71 ) ;
V_20 = F_78 ( V_63 ) ;
if ( V_20 )
F_31 ( V_71 , L_18 , V_20 ) ;
if ( F_15 ( V_9 , V_215 , V_63 -> V_35 ) )
F_31 ( V_71 , L_19 , V_20 ) ;
V_20 = F_77 ( V_63 ) ;
if ( V_20 )
F_31 ( V_71 , L_20 , V_20 ) ;
F_74 ( V_63 ) ;
V_63 -> V_73 . V_75 = V_216 ;
F_72 ( V_63 -> V_71 ) ;
return 0 ;
}
static void F_81 ( struct V_91 * V_91 )
{
struct V_60 * V_61 = V_91 -> V_61 ;
struct V_62 * V_63 ;
struct V_92 * V_71 ;
if ( F_82 ( ! V_61 ) )
return;
V_63 = V_61 -> V_63 ;
V_71 = V_63 -> V_71 ;
F_14 ( V_91 -> V_93 ) ;
if ( ! F_21 ( V_71 ) )
return;
if ( V_91 -> V_94 )
F_83 ( V_71 , L_21 , V_91 -> V_94 ) ;
}
static T_3 F_84 ( struct V_64 * V_65 ,
struct V_92 * V_71 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
struct V_8 * V_9 = V_63 -> V_9 ;
struct V_58 * V_59 = & V_71 -> V_59 ;
struct V_66 * V_67 = (struct V_66 * ) V_65 -> V_130 ;
struct V_60 * V_61 = NULL ;
struct V_91 * V_91 ;
void * V_19 ;
struct V_10 * V_11 ;
int V_186 , V_20 , V_217 = V_218 ;
T_1 * V_219 = NULL ;
unsigned long V_68 ;
if ( F_85 ( V_71 , V_65 ) )
return V_218 ;
V_91 = F_33 ( 0 , V_95 ) ;
if ( ! V_91 ) {
F_24 ( V_71 , L_5 ) ;
V_59 -> V_171 ++ ;
F_86 ( V_65 ) ;
return V_218 ;
}
V_19 = F_16 ( sizeof( struct V_10 ) , V_95 ) ;
if ( ! V_19 ) {
V_59 -> V_171 ++ ;
F_86 ( V_65 ) ;
goto V_220;
}
V_11 = V_19 ;
V_11 -> V_16 = V_30 + sizeof( struct V_221 ) ;
V_11 -> V_38 . V_222 . V_35 = V_63 -> V_35 ;
switch ( V_9 -> V_43 ) {
case V_44 :
V_219 = & V_11 -> V_38 . V_222 . V_46 . V_68 ;
break;
case V_50 :
V_219 = & V_11 -> V_38 . V_222 . V_51 . V_68 ;
break;
}
* V_219 = 0 ;
if ( V_67 -> V_77 & V_174 ) {
V_11 -> V_2 = V_223 ;
V_11 -> V_38 . V_222 . V_11 [ 0 ] = ( V_67 -> V_77 >> 24 ) & 0x1f ;
V_11 -> V_38 . V_222 . V_11 [ 1 ] = ( V_67 -> V_77 >> 18 ) & 0x3f ;
V_11 -> V_38 . V_222 . V_11 [ 2 ] = ( V_67 -> V_77 >> 14 ) & 0x0f ;
V_11 -> V_38 . V_222 . V_11 [ 3 ] = ( V_67 -> V_77 >> 6 ) & 0xff ;
V_11 -> V_38 . V_222 . V_11 [ 4 ] = V_67 -> V_77 & 0x3f ;
} else {
V_11 -> V_2 = V_224 ;
V_11 -> V_38 . V_222 . V_11 [ 0 ] = ( V_67 -> V_77 >> 6 ) & 0x1f ;
V_11 -> V_38 . V_222 . V_11 [ 1 ] = V_67 -> V_77 & 0x3f ;
}
V_11 -> V_38 . V_222 . V_11 [ 5 ] = V_67 -> V_81 ;
memcpy ( & V_11 -> V_38 . V_222 . V_11 [ 6 ] , V_67 -> V_130 , V_67 -> V_81 ) ;
if ( V_67 -> V_77 & V_176 )
* V_219 |= V_169 ;
F_26 ( & V_63 -> V_88 , V_68 ) ;
for ( V_186 = 0 ; V_186 < V_9 -> V_48 ; V_186 ++ ) {
if ( V_63 -> V_72 [ V_186 ] . V_89 == V_9 -> V_48 ) {
V_61 = & V_63 -> V_72 [ V_186 ] ;
V_61 -> V_89 = V_186 ;
F_87 ( V_65 , V_71 , V_61 -> V_89 ) ;
++ V_63 -> V_90 ;
if ( V_63 -> V_90 >= V_9 -> V_48 )
F_80 ( V_71 ) ;
break;
}
}
F_29 ( & V_63 -> V_88 , V_68 ) ;
if ( ! V_61 ) {
F_31 ( V_71 , L_22 ) ;
F_14 ( V_19 ) ;
V_217 = V_225 ;
goto V_220;
}
V_61 -> V_63 = V_63 ;
V_61 -> V_87 = V_67 -> V_81 ;
V_11 -> V_38 . V_222 . V_40 = V_61 -> V_89 ;
F_35 ( V_91 , V_9 -> V_13 ,
F_5 ( V_9 -> V_13 ,
V_9 -> V_14 -> V_15 ) ,
V_19 , V_11 -> V_16 ,
F_81 , V_61 ) ;
F_36 ( V_91 , & V_63 -> V_96 ) ;
V_20 = F_37 ( V_91 , V_95 ) ;
if ( F_88 ( V_20 ) ) {
F_26 ( & V_63 -> V_88 , V_68 ) ;
F_89 ( V_71 , V_61 -> V_89 ) ;
V_61 -> V_89 = V_9 -> V_48 ;
-- V_63 -> V_90 ;
F_28 ( V_71 ) ;
F_29 ( & V_63 -> V_88 , V_68 ) ;
F_38 ( V_91 ) ;
V_59 -> V_171 ++ ;
if ( V_20 == - V_191 )
F_61 ( V_71 ) ;
else
F_31 ( V_71 , L_23 , V_20 ) ;
goto V_220;
}
V_217 = V_218 ;
V_220:
F_34 ( V_91 ) ;
return V_217 ;
}
static int F_90 ( struct V_92 * V_71 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
struct V_226 * V_227 = & V_63 -> V_73 . V_228 ;
struct V_8 * V_9 = V_63 -> V_9 ;
struct V_10 * V_11 ;
int V_36 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_26 ) ;
if ( ! V_11 )
return - V_27 ;
V_11 -> V_2 = V_229 ;
V_11 -> V_16 = V_30 + sizeof( struct V_230 ) ;
V_11 -> V_38 . V_231 . V_35 = V_63 -> V_35 ;
V_11 -> V_38 . V_231 . V_40 = 0xff ;
V_11 -> V_38 . V_231 . V_232 = F_91 ( V_227 -> V_232 ) ;
V_11 -> V_38 . V_231 . V_233 = V_227 -> V_233 ;
V_11 -> V_38 . V_231 . V_234 = V_227 -> V_235 + V_227 -> V_236 ;
V_11 -> V_38 . V_231 . V_237 = V_227 -> V_238 ;
if ( V_63 -> V_73 . V_204 & V_239 )
V_11 -> V_38 . V_231 . V_240 = 3 ;
else
V_11 -> V_38 . V_231 . V_240 = 1 ;
V_36 = F_3 ( V_9 , V_11 ) ;
F_14 ( V_11 ) ;
return V_36 ;
}
static int F_92 ( struct V_92 * V_71 ,
enum V_241 V_242 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
int V_20 ;
switch ( V_242 ) {
case V_243 :
V_20 = F_32 ( V_63 , V_208 ) ;
if ( V_20 )
return V_20 ;
break;
default:
return - V_244 ;
}
return 0 ;
}
static int F_93 ( const struct V_92 * V_71 ,
struct V_245 * V_120 )
{
struct V_62 * V_63 = F_70 ( V_71 ) ;
* V_120 = V_63 -> V_120 ;
return 0 ;
}
static void F_94 ( struct V_8 * V_9 )
{
int V_186 ;
for ( V_186 = 0 ; V_186 < V_9 -> V_54 ; V_186 ++ ) {
if ( ! V_9 -> V_70 [ V_186 ] )
continue;
F_95 ( V_9 -> V_70 [ V_186 ] -> V_71 ) ;
}
F_76 ( V_9 ) ;
for ( V_186 = 0 ; V_186 < V_9 -> V_54 ; V_186 ++ ) {
if ( ! V_9 -> V_70 [ V_186 ] )
continue;
F_96 ( V_9 -> V_70 [ V_186 ] -> V_71 ) ;
}
}
static int F_97 ( struct V_246 * V_247 ,
const struct V_1 * V_2 , int V_35 )
{
struct V_8 * V_9 = F_98 ( V_247 ) ;
struct V_92 * V_71 ;
struct V_62 * V_63 ;
int V_20 ;
V_20 = F_15 ( V_9 , V_215 , V_35 ) ;
if ( V_20 )
return V_20 ;
V_71 = F_99 ( sizeof( * V_63 ) +
V_9 -> V_48 * sizeof( * V_63 -> V_72 ) ,
V_9 -> V_48 ) ;
if ( ! V_71 ) {
F_12 ( & V_247 -> V_9 , L_24 ) ;
return - V_27 ;
}
V_63 = F_70 ( V_71 ) ;
F_100 ( & V_63 -> V_96 ) ;
F_67 ( & V_63 -> V_178 ) ;
F_67 ( & V_63 -> V_179 ) ;
V_63 -> V_9 = V_9 ;
V_63 -> V_71 = V_71 ;
V_63 -> V_35 = V_35 ;
F_101 ( & V_63 -> V_88 ) ;
F_73 ( V_63 ) ;
V_63 -> V_73 . V_75 = V_216 ;
V_63 -> V_73 . clock . V_248 = V_249 ;
V_63 -> V_73 . V_250 = & V_251 ;
V_63 -> V_73 . V_252 = F_90 ;
V_63 -> V_73 . V_253 = F_92 ;
if ( V_2 -> V_254 & V_255 )
V_63 -> V_73 . V_256 = F_93 ;
V_63 -> V_73 . V_257 = V_239 ;
if ( V_2 -> V_254 & V_258 )
V_63 -> V_73 . V_257 |= V_205 ;
V_71 -> V_68 |= V_259 ;
V_71 -> V_260 = & V_261 ;
F_102 ( V_71 , & V_247 -> V_9 ) ;
V_71 -> V_262 = V_35 ;
V_9 -> V_70 [ V_35 ] = V_63 ;
V_20 = F_103 ( V_71 ) ;
if ( V_20 ) {
F_12 ( & V_247 -> V_9 , L_25 ) ;
F_96 ( V_71 ) ;
V_9 -> V_70 [ V_35 ] = NULL ;
return V_20 ;
}
F_40 ( V_71 , L_26 ) ;
return 0 ;
}
static int F_104 ( const struct V_246 * V_247 ,
struct V_263 * * V_264 ,
struct V_263 * * V_265 )
{
const struct V_266 * V_267 ;
struct V_263 * V_268 ;
int V_186 ;
V_267 = & V_247 -> V_269 [ 0 ] ;
for ( V_186 = 0 ; V_186 < V_267 -> V_270 . V_271 ; ++ V_186 ) {
V_268 = & V_267 -> V_268 [ V_186 ] . V_270 ;
if ( ! * V_264 && F_105 ( V_268 ) )
* V_264 = V_268 ;
if ( ! * V_265 && F_106 ( V_268 ) )
* V_265 = V_268 ;
if ( * V_264 && * V_265 )
return 0 ;
}
return - V_191 ;
}
static int F_107 ( struct V_246 * V_247 ,
const struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_20 = - V_27 ;
int V_186 , V_272 = 3 ;
V_9 = F_108 ( & V_247 -> V_9 , sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
if ( F_1 ( V_2 ) ) {
V_9 -> V_43 = V_44 ;
} else if ( F_2 ( V_2 ) ) {
V_9 -> V_43 = V_50 ;
} else {
F_12 ( & V_247 -> V_9 ,
L_27 ,
V_2 -> V_3 ) ;
return - V_191 ;
}
V_20 = F_104 ( V_247 , & V_9 -> V_28 , & V_9 -> V_14 ) ;
if ( V_20 ) {
F_12 ( & V_247 -> V_9 , L_28 ) ;
return V_20 ;
}
V_9 -> V_13 = F_109 ( V_247 ) ;
F_100 ( & V_9 -> V_198 ) ;
F_110 ( V_247 , V_9 ) ;
do {
V_20 = F_17 ( V_9 ) ;
} while ( -- V_272 && V_20 == - V_210 );
if ( V_20 ) {
F_12 ( & V_247 -> V_9 ,
L_29 , V_20 ) ;
return V_20 ;
}
F_111 ( & V_247 -> V_9 , L_30 ,
( ( V_9 -> V_45 >> 24 ) & 0xff ) ,
( ( V_9 -> V_45 >> 16 ) & 0xff ) ,
( V_9 -> V_45 & 0xffff ) ) ;
F_111 ( & V_247 -> V_9 , L_31 , V_9 -> V_48 ) ;
V_20 = F_19 ( V_9 ) ;
if ( V_20 ) {
F_12 ( & V_247 -> V_9 ,
L_32 , V_20 ) ;
return V_20 ;
}
for ( V_186 = 0 ; V_186 < V_9 -> V_54 ; V_186 ++ ) {
V_20 = F_97 ( V_247 , V_2 , V_186 ) ;
if ( V_20 ) {
F_94 ( V_9 ) ;
return V_20 ;
}
}
return 0 ;
}
static void F_112 ( struct V_246 * V_247 )
{
struct V_8 * V_9 = F_98 ( V_247 ) ;
F_110 ( V_247 , NULL ) ;
if ( ! V_9 )
return;
F_94 ( V_9 ) ;
}
