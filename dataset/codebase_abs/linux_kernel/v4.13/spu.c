void F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_1 * V_3 = V_1 ;
struct V_4 * V_5 = (struct V_4 * ) V_1 ;
unsigned int V_6 = 0 ;
unsigned int V_7 = 0 ;
unsigned int V_8 = 0 ;
unsigned int V_9 ;
T_2 V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_2 V_20 ;
F_2 ( L_1 ) ;
F_2 ( L_2 , V_1 , V_2 ) ;
F_2 ( L_3 , F_3 ( * ( ( T_2 * ) V_3 ) ) ) ;
if ( V_5 -> V_21 . V_22 & V_23 )
F_2 ( L_4 ) ;
if ( V_5 -> V_21 . V_22 & V_24 )
F_2 ( L_5 ) ;
if ( V_5 -> V_21 . V_22 & V_25 )
F_2 ( L_6 ) ;
if ( V_5 -> V_21 . V_22 & V_26 )
F_2 ( L_7 ) ;
if ( V_5 -> V_21 . V_22 & V_27 )
F_2 ( L_8 ) ;
if ( V_5 -> V_21 . V_22 & V_28 )
F_2 ( L_9 ) ;
F_2 ( L_10 , V_5 -> V_21 . V_29 ) ;
V_3 += sizeof( V_5 -> V_21 ) + sizeof( V_5 -> V_30 ) ;
if ( V_5 -> V_21 . V_22 & V_23 ) {
V_10 = F_3 ( V_5 -> V_31 . V_32 ) ;
F_2 ( L_11 , V_10 ) ;
V_19 = V_10 & V_33 ;
F_2 ( L_12 , V_19 ) ;
V_11 = F_3 ( V_5 -> V_31 . V_34 ) ;
F_2 ( L_13 , V_11 ) ;
F_2 ( L_14 ,
( V_11 & V_35 ) >> V_36 ) ;
F_2 ( L_15 ,
( V_11 & V_37 ) >> V_38 ) ;
F_2 ( L_16 ,
( V_11 & V_39 ) >> V_40 ) ;
V_13 = ( V_11 & V_41 ) >> V_42 ;
V_14 = ( V_11 & V_43 ) >> V_44 ;
V_15 = ( V_11 & V_45 ) >> V_46 ;
F_2 ( L_17 ,
V_13 , V_14 , V_15 ) ;
V_16 = ( V_11 & V_47 ) >> V_48 ;
V_17 = ( V_11 & V_49 ) >> V_50 ;
V_18 = ( V_11 & V_51 ) >> V_52 ;
F_2 ( L_18 ,
V_16 , V_17 , V_18 ) ;
F_2 ( L_19 , V_11 & V_53 ) ;
V_12 = F_3 ( V_5 -> V_31 . V_12 ) ;
F_2 ( L_20 , V_12 ) ;
F_2 ( L_21 ,
( V_12 & V_54 ) >> V_55 ,
( V_12 & V_56 ) >> V_57 ,
( V_12 & V_58 ) >> V_59 ) ;
F_2 ( L_22 ,
( V_12 & V_60 ) >> V_61 ) ;
F_2 ( L_23 ,
( V_12 & V_62 ) >> V_63 ,
( V_12 & V_64 ) >> V_65 ,
( V_12 & V_66 ) >> V_67 ) ;
F_2 ( L_24 ,
( V_12 & V_68 ) >> V_69 ,
V_12 & V_70 ) ;
V_3 += sizeof( struct V_71 ) ;
if ( V_16 && V_17 ) {
char * V_72 = L_25 ;
switch ( V_16 ) {
case V_73 :
V_6 = 16 ;
V_72 = L_26 ;
break;
case V_74 :
V_6 = 20 ;
V_72 = L_27 ;
break;
case V_75 :
V_6 = 28 ;
V_72 = L_28 ;
break;
case V_76 :
V_6 = 32 ;
V_72 = L_29 ;
break;
case V_77 :
V_6 = 48 ;
V_72 = L_30 ;
break;
case V_78 :
V_6 = 64 ;
V_72 = L_31 ;
break;
case V_79 :
V_6 = 0 ;
V_72 = L_32 ;
break;
case V_80 :
break;
}
F_2 ( L_33 ,
V_72 , V_6 ) ;
F_4 ( L_34 , V_3 , V_6 ) ;
V_3 += V_6 ;
} else if ( ( V_16 == V_79 ) &&
( V_17 == V_81 ) ) {
char * V_72 = L_25 ;
switch ( V_15 ) {
case V_82 :
V_6 = 16 ;
V_72 = L_35 ;
break;
case V_83 :
V_6 = 24 ;
V_72 = L_36 ;
break;
case V_84 :
V_6 = 32 ;
V_72 = L_37 ;
break;
}
F_2 ( L_33 ,
V_72 , V_6 ) ;
F_4 ( L_34 , V_3 , V_6 ) ;
V_3 += V_6 ;
}
if ( V_16 && ( V_17 == V_85 ) &&
( V_18 == V_86 ) ) {
char * V_72 = L_25 ;
switch ( V_16 ) {
case V_73 :
V_7 = 16 ;
V_72 = L_26 ;
break;
case V_74 :
V_7 = 20 ;
V_72 = L_27 ;
break;
case V_75 :
V_7 = 32 ;
V_72 = L_28 ;
break;
case V_76 :
V_7 = 32 ;
V_72 = L_29 ;
break;
case V_77 :
V_7 = 48 ;
V_72 = L_30 ;
break;
case V_78 :
V_7 = 64 ;
V_72 = L_31 ;
break;
case V_79 :
V_7 = 0 ;
V_72 = L_32 ;
break;
case V_80 :
break;
}
F_2 ( L_38 ,
V_72 , V_7 ) ;
F_4 ( L_39 , V_3 , V_7 ) ;
V_3 += V_7 ;
}
if ( V_13 ) {
char * V_72 = L_25 ;
switch ( V_13 ) {
case V_87 :
V_8 = 8 ;
V_72 = L_40 ;
break;
case V_88 :
V_8 = 24 ;
V_72 = L_41 ;
break;
case V_89 :
V_8 = 260 ;
V_72 = L_42 ;
break;
case V_90 :
switch ( V_15 ) {
case V_82 :
V_8 = 16 ;
V_72 = L_43 ;
break;
case V_83 :
V_8 = 24 ;
V_72 = L_44 ;
break;
case V_84 :
V_8 = 32 ;
V_72 = L_45 ;
break;
}
break;
case V_91 :
break;
}
F_2 ( L_46 ,
V_72 , V_8 ) ;
if ( V_14 == V_92 ) {
F_4 ( L_47 , V_3 , V_8 ) ;
V_3 += V_8 ;
F_4 ( L_48 , V_3 , V_8 ) ;
V_3 += V_8 ;
V_8 *= 2 ;
} else {
F_4 ( L_34 , V_3 , V_8 ) ;
V_3 += V_8 ;
}
if ( V_12 & V_62 ) {
V_20 = V_19 * sizeof( T_2 ) -
sizeof( struct V_71 ) ;
V_9 = V_20 -
( V_6 + V_7 +
V_8 ) ;
F_2 ( L_49 , V_9 ) ;
F_4 ( L_50 , V_3 , V_9 ) ;
V_3 += V_9 ;
}
}
}
if ( V_5 -> V_21 . V_22 & V_24 ) {
#ifdef F_5
struct V_93 * V_94 = (struct V_93 * ) V_3 ;
#endif
F_2 ( L_51 , F_3 ( * ( ( T_2 * ) V_3 ) ) ) ;
F_2 ( L_52 ,
F_6 ( V_94 -> V_95 ) ,
F_6 ( V_94 -> V_96 ) ) ;
V_3 += sizeof( T_2 ) ;
F_2 ( L_53 , F_3 ( * ( ( T_2 * ) V_3 ) ) ) ;
F_2 ( L_54 ,
F_6 ( V_94 -> V_97 ) ,
F_6 ( V_94 -> V_98 ) ) ;
V_3 += sizeof( T_2 ) ;
F_2 ( L_55 , F_3 ( * ( ( T_2 * ) V_3 ) ) ) ;
F_2 ( L_56 ,
F_6 ( V_94 -> V_99 ) ,
F_6 ( V_94 -> V_100 ) ) ;
V_3 += sizeof( T_2 ) ;
}
if ( V_5 -> V_21 . V_22 & V_26 ) {
#ifdef F_5
struct V_101 * V_102 = (struct V_101 * ) V_3 ;
#endif
F_2 ( L_57 , F_3 ( * ( ( T_2 * ) V_3 ) ) ) ;
F_2 ( L_58 ,
F_6 ( V_102 -> V_103 ) , F_6 ( V_102 -> V_104 ) ) ;
V_3 += 4 ;
}
if ( V_1 + V_2 != V_3 ) {
F_2 ( L_59 ) ;
F_2 ( L_60 ,
V_1 , V_2 , V_1 + V_2 , V_3 ) ;
}
F_2 ( L_1 ) ;
}
T_2 F_7 ( enum V_105 V_13 ,
enum V_106 V_14 ,
unsigned int V_107 )
{
T_2 V_108 = V_109 ;
T_2 V_110 ;
if ( V_14 == V_92 )
V_108 -= V_111 ;
V_110 = V_108 % V_107 ;
return V_108 - V_110 ;
}
T_2 F_8 ( enum V_105 V_13 ,
enum V_106 V_14 ,
unsigned int V_107 )
{
T_2 V_108 = V_112 ;
T_2 V_110 ;
if ( V_14 == V_92 )
V_108 -= V_111 ;
V_110 = V_108 % V_107 ;
return V_108 - V_110 ;
}
T_2 F_9 ( T_1 * V_113 )
{
struct V_101 * V_102 ;
T_2 V_114 ;
V_102 = (struct V_101 * ) ( V_113 + 8 ) ;
V_114 = F_6 ( V_102 -> V_103 ) ;
return V_114 ;
}
T_3 F_10 ( T_3 V_115 , T_3 V_116 , bool V_117 )
{
if ( V_117 )
return V_118 ;
else
return V_119 ;
}
T_3 F_11 ( enum V_16 V_16 , enum V_17 V_17 ,
T_2 V_120 , T_3 V_121 )
{
unsigned int V_122 ;
unsigned int V_123 ;
int V_124 ;
if ( ( V_16 == V_79 ) && ( V_17 == V_81 ) ) {
V_123 = V_120 % V_121 ;
V_124 = V_121 - V_123 ;
if ( V_124 >= V_121 )
V_124 -= V_121 ;
return V_124 ;
}
V_123 = V_120 % V_121 + 1 ;
if ( ( V_16 == V_77 ) || ( V_16 == V_78 ) )
V_122 = 2 * sizeof( V_125 ) ;
else
V_122 = sizeof( V_125 ) ;
V_123 += V_122 ;
V_124 = V_121 - V_123 ;
if ( V_124 < 0 )
V_124 += V_121 ;
V_124 += 1 + V_122 ;
return V_124 ;
}
T_2 F_12 ( enum V_106 V_14 ,
unsigned int V_126 )
{
T_2 V_127 = 0 ;
T_2 V_128 = V_129 - 1 ;
if ( ( V_14 == V_130 ) ||
( V_14 == V_131 ) )
V_127 = ( ( V_126 + V_128 ) & ~ V_128 ) - V_126 ;
return V_127 ;
}
T_2 F_13 ( enum V_106 V_14 ,
unsigned int V_132 , unsigned int V_9 ,
bool V_133 )
{
T_2 V_134 = 0 ;
T_2 V_135 ;
if ( V_132 )
V_134 = V_132 ;
if ( V_14 == V_130 ) {
V_135 = F_12 ( V_14 , V_134 ) ;
V_134 += V_135 ;
}
if ( V_14 == V_131 ) {
V_135 = F_12 ( V_14 , V_134 + 2 ) ;
V_134 += V_135 ;
}
return V_134 ;
}
T_1 F_14 ( enum V_106 V_14 , T_3 V_9 )
{
return 0 ;
}
enum V_18 F_15 ( T_2 V_136 )
{
return V_136 ? V_86 : V_137 ;
}
T_2 F_16 ( T_2 V_138 , enum V_16 V_139 ,
enum V_18 V_140 )
{
T_2 V_141 = V_138 ;
if ( ( V_140 == V_137 ) || ( V_140 == V_86 ) ) {
if ( V_139 == V_75 )
V_141 = V_142 ;
else if ( V_139 == V_77 )
V_141 = V_143 ;
}
return V_141 ;
}
T_2 F_17 ( T_1 * V_113 ,
struct V_144 * V_145 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
struct V_150 * V_151 ,
unsigned int V_126 )
{
struct V_4 * V_5 ;
struct V_93 * V_94 ;
struct V_101 * V_102 ;
T_1 * V_3 ;
T_2 V_152 = 0 ;
T_2 V_153 = 0 ;
T_2 V_154 = 0 ;
T_1 V_155 = 0 ;
unsigned int V_2 = 0 ;
unsigned int V_156 = V_149 -> V_157 + V_126 +
V_149 -> V_127 ;
unsigned int V_158 = V_151 -> V_159 +
V_151 -> V_9 + V_151 -> V_160 ;
unsigned int V_161 = F_18 ( V_151 -> V_159 ,
V_151 -> V_9 ,
V_149 -> V_157 ,
V_126 ,
V_151 -> V_160 ,
V_151 -> V_162 ,
V_149 -> V_127 ) ;
unsigned int V_163 = 0 ;
unsigned int V_100 = 0 ;
unsigned int V_164 ;
V_164 = V_161 ;
if ( V_145 -> V_165 && V_145 -> V_166 )
V_156 -= V_149 -> V_141 ;
if ( V_145 -> V_165 && V_145 -> V_166 )
V_164 -= V_149 -> V_141 ;
if ( ( V_149 -> V_139 == V_79 ) &&
( V_149 -> V_167 == V_81 ) ) {
V_164 -= V_149 -> V_127 ;
V_156 -= V_149 -> V_127 ;
}
F_19 ( L_61 , V_168 ) ;
F_19 ( L_62 ,
V_145 -> V_166 , V_145 -> V_169 ) ;
F_19 ( L_63 ,
F_20 ( V_147 -> V_139 , V_147 -> V_167 ) ,
V_147 -> V_139 , V_147 -> V_167 , V_147 -> type ) ;
F_19 ( L_64 , V_147 -> V_170 ) ;
F_21 ( L_65 , V_147 -> V_171 , V_147 -> V_170 ) ;
F_19 ( L_66 , V_147 -> V_9 ) ;
F_21 ( L_67 , V_147 -> V_172 , V_147 -> V_9 ) ;
F_19 ( L_68 ,
V_149 -> V_139 , V_149 -> V_167 , V_149 -> type ) ;
F_19 ( L_69 , V_149 -> V_141 ) ;
F_19 ( L_70 , V_149 -> V_170 ) ;
F_21 ( L_71 , V_149 -> V_171 , V_149 -> V_170 ) ;
F_19 ( L_72 , V_151 -> V_159 ) ;
F_19 ( L_73 , V_149 -> V_157 ) ;
F_19 ( L_74 , V_126 ) ;
F_19 ( L_75 , V_149 -> V_127 ) ;
F_19 ( L_76 , V_161 ) ;
F_19 ( L_77 ,
V_163 , V_164 , V_158 , V_156 ) ;
F_19 ( L_78 , V_151 -> V_9 ) ;
V_3 = V_113 ;
memset ( V_3 , 0 , sizeof( struct V_4 ) ) ;
V_5 = (struct V_4 * ) V_3 ;
V_3 += sizeof( struct V_4 ) ;
V_2 += sizeof( struct V_4 ) ;
V_5 -> V_21 . V_29 = V_173 ;
V_5 -> V_21 . V_22 |= ( V_23 | V_24 | V_26 ) ;
V_155 = 3 ;
if ( V_145 -> V_166 )
V_153 |= V_35 ;
if ( V_145 -> V_169 )
V_153 |= V_37 ;
V_153 |= V_147 -> V_139 << V_42 ;
V_153 |= V_147 -> V_167 << V_44 ;
V_153 |= V_147 -> type << V_46 ;
V_153 |= V_149 -> V_139 << V_48 ;
V_153 |= V_149 -> V_167 << V_50 ;
V_153 |= V_149 -> type << V_52 ;
if ( V_149 -> V_139 ) {
if ( V_149 -> V_170 ) {
memcpy ( V_3 , V_149 -> V_171 , V_149 -> V_170 ) ;
V_3 += V_149 -> V_170 ;
V_2 += V_149 -> V_170 ;
V_155 += V_149 -> V_170 / 4 ;
}
if ( ( V_147 -> V_167 == V_130 ) ||
( V_147 -> V_167 == V_131 ) )
V_100 = V_151 -> V_159 ;
if ( ! V_145 -> V_166 ) {
if ( ( V_147 -> V_167 == V_130 ) ||
( V_147 -> V_167 == V_131 ) )
V_154 |= 1 << V_55 ;
} else {
V_154 |= V_56 ;
}
if ( V_149 -> V_141 == 64 )
V_153 |= V_39 ;
else
V_154 |=
( V_149 -> V_141 / 4 ) << V_59 ;
}
if ( V_145 -> V_174 )
V_154 |= V_60 ;
if ( V_147 -> V_139 ) {
if ( V_147 -> V_170 ) {
memcpy ( V_3 , V_147 -> V_171 ,
V_147 -> V_170 ) ;
V_3 += V_147 -> V_170 ;
V_2 += V_147 -> V_170 ;
V_155 += V_147 -> V_170 / 4 ;
}
if ( V_147 -> V_172 && V_147 -> V_9 ) {
V_154 |= V_62 ;
memcpy ( V_3 , V_147 -> V_172 , V_147 -> V_9 ) ;
V_3 += V_147 -> V_9 ;
V_2 += V_147 -> V_9 ;
V_155 += V_147 -> V_9 / 4 ;
}
}
if ( V_145 -> V_175 ) {
if ( V_145 -> V_166 )
V_126 -= V_149 -> V_141 ;
V_100 = V_151 -> V_159 + V_126 ;
V_156 = 0 ;
V_158 = V_100 ;
V_164 = V_158 + V_151 -> V_162 ;
}
V_152 |= V_155 ;
V_5 -> V_31 . V_32 = F_22 ( V_152 ) ;
V_5 -> V_31 . V_34 = F_22 ( V_153 ) ;
V_5 -> V_31 . V_12 = F_22 ( V_154 ) ;
V_94 = (struct V_93 * ) V_3 ;
V_94 -> V_95 = F_23 ( V_163 ) ;
V_94 -> V_96 = F_23 ( V_164 ) ;
V_94 -> V_97 = F_23 ( V_158 ) ;
V_94 -> V_98 = F_23 ( V_156 ) ;
if ( V_147 -> V_167 == V_131 )
V_164 += F_24 ( V_164 ) ;
V_94 -> V_99 = F_23 ( V_164 ) ;
V_94 -> V_100 = F_23 ( V_100 ) ;
V_3 += sizeof( struct V_93 ) ;
V_2 += sizeof( struct V_93 ) ;
V_102 = (struct V_101 * ) V_3 ;
V_102 -> V_103 = F_23 ( V_161 ) ;
V_102 -> V_104 = 0 ;
V_3 += sizeof( struct V_101 ) ;
V_2 += sizeof( struct V_101 ) ;
F_4 ( L_79 , V_113 , V_2 ) ;
return V_2 ;
}
T_3 F_25 ( T_1 * V_113 , struct V_146 * V_147 )
{
struct V_4 * V_5 ;
T_2 V_152 = 0 ;
T_2 V_153 = 0 ;
T_2 V_154 = 0 ;
T_1 V_155 = 0 ;
T_1 * V_3 = V_113 ;
F_19 ( L_61 , V_168 ) ;
F_19 ( L_80 , V_147 -> V_139 ,
V_147 -> V_167 , V_147 -> type ) ;
F_19 ( L_81 , V_147 -> V_9 ) ;
F_19 ( L_64 , V_147 -> V_170 ) ;
F_21 ( L_65 , V_147 -> V_171 , V_147 -> V_170 ) ;
memset ( V_113 , 0 , sizeof( struct V_4 ) ) ;
V_3 += sizeof( struct V_4 ) ;
V_5 = (struct V_4 * ) V_113 ;
V_5 -> V_21 . V_29 = V_173 ;
V_5 -> V_21 . V_22 |= ( V_23 | V_24 | V_26 ) ;
V_155 = 3 ;
if ( V_147 -> V_139 ) {
if ( V_147 -> V_170 ) {
V_3 += V_147 -> V_170 ;
V_155 += V_147 -> V_170 / 4 ;
}
if ( V_147 -> V_9 ) {
V_154 |= V_62 ;
V_3 += V_147 -> V_9 ;
V_155 += V_147 -> V_9 / 4 ;
}
}
V_153 |= V_147 -> V_139 << V_42 ;
V_153 |= V_147 -> V_167 << V_44 ;
V_153 |= V_147 -> type << V_46 ;
if ( V_147 -> V_139 && V_147 -> V_170 )
memcpy ( V_5 + 1 , V_147 -> V_171 , V_147 -> V_170 ) ;
V_152 |= V_155 ;
V_5 -> V_31 . V_32 = F_22 ( V_152 ) ;
V_5 -> V_31 . V_34 = F_22 ( V_153 ) ;
V_5 -> V_31 . V_12 = F_22 ( V_154 ) ;
F_4 ( L_79 , V_113 ,
sizeof( struct V_4 ) ) ;
return sizeof( struct V_4 ) + V_147 -> V_170 +
V_147 -> V_9 + sizeof( struct V_93 ) +
sizeof( struct V_101 ) ;
}
void F_26 ( T_1 * V_113 ,
T_3 V_176 ,
unsigned int V_166 ,
struct V_146 * V_147 ,
bool V_177 ,
unsigned int V_126 )
{
struct V_4 * V_5 ;
struct V_93 * V_94 ;
struct V_101 * V_102 ;
T_1 * V_178 = V_113 + V_176 -
( sizeof( struct V_101 ) + sizeof( struct V_93 ) ) ;
T_2 V_153 ;
F_19 ( L_61 , V_168 ) ;
F_19 ( L_82 , V_166 ) ;
F_19 ( L_83 , V_147 -> V_139 ,
V_147 -> type ) ;
if ( V_177 ) {
F_19 ( L_84 , V_147 -> V_170 ) ;
F_21 ( L_85 , V_147 -> V_171 ,
V_147 -> V_170 ) ;
}
if ( V_147 -> V_167 == V_92 )
memset ( V_147 -> V_172 , 0 , V_147 -> V_9 ) ;
F_19 ( L_86 , V_147 -> V_9 ) ;
F_21 ( L_67 , V_147 -> V_172 , V_147 -> V_9 ) ;
F_19 ( L_87 , V_126 ) ;
V_5 = (struct V_4 * ) V_113 ;
V_153 = F_3 ( V_5 -> V_31 . V_34 ) ;
if ( V_166 )
V_153 |= V_35 ;
else
V_153 &= ~ V_35 ;
if ( V_177 ) {
V_5 -> V_31 . V_34 |=
V_147 -> type << V_46 ;
memcpy ( V_5 + 1 , V_147 -> V_171 , V_147 -> V_170 ) ;
}
if ( V_147 -> V_139 && V_147 -> V_172 && V_147 -> V_9 )
memcpy ( V_178 - V_147 -> V_9 , V_147 -> V_172 ,
V_147 -> V_9 ) ;
V_5 -> V_31 . V_34 = F_22 ( V_153 ) ;
V_94 = (struct V_93 * ) V_178 ;
V_94 -> V_95 = 0 ;
V_94 -> V_96 = 0 ;
V_94 -> V_97 = 0 ;
if ( V_147 -> V_167 == V_92 )
V_94 -> V_98 = F_23 ( V_126 +
V_111 ) ;
else
V_94 -> V_98 = F_23 ( V_126 ) ;
V_94 -> V_99 = 0 ;
V_94 -> V_100 = 0 ;
V_102 = (struct V_101 * ) ( V_178 + sizeof( struct V_93 ) ) ;
V_102 -> V_103 = F_23 ( V_126 ) ;
if ( V_147 -> V_167 == V_92 )
V_102 -> V_103 = F_23 ( V_126 + V_111 ) ;
else
V_102 -> V_103 = F_23 ( V_126 ) ;
V_102 -> V_104 = 0 ;
F_4 ( L_79 , V_113 , V_176 ) ;
}
void F_27 ( T_1 * V_179 ,
T_2 V_180 ,
T_2 V_124 ,
enum V_16 V_181 ,
enum V_17 V_182 ,
unsigned int V_183 , T_2 V_184 )
{
T_1 * V_3 = V_179 ;
if ( V_180 > 0 ) {
F_19 ( L_88 ,
V_180 ) ;
memset ( V_3 , 0 , V_180 ) ;
V_3 += V_180 ;
}
if ( V_124 > 0 ) {
memset ( V_3 , 0 , V_124 ) ;
if ( ( V_181 == V_79 ) &&
( V_182 == V_81 ) ) {
V_3 += V_124 ;
} else {
* V_3 = 0x80 ;
V_3 += ( V_124 - sizeof( V_125 ) ) ;
if ( V_181 == V_73 )
* ( V_125 * ) V_3 = F_28 ( ( V_125 ) V_183 * 8 ) ;
else
* ( V_125 * ) V_3 = F_29 ( ( V_125 ) V_183 * 8 ) ;
V_3 += sizeof( V_125 ) ;
}
}
if ( V_184 > 0 ) {
F_19 ( L_89 ,
V_184 ) ;
memset ( V_3 , 0 , V_184 ) ;
V_3 += V_184 ;
}
}
T_1 F_30 ( void )
{
return 1 ;
}
T_1 F_31 ( void )
{
return V_185 ;
}
T_1 F_32 ( void )
{
return V_186 ;
}
int F_33 ( T_1 * V_187 )
{
T_2 V_188 ;
V_188 = F_34 ( * ( V_189 * ) V_187 ) ;
F_19 ( L_90 , V_188 ) ;
if ( V_188 & V_190 ) {
F_35 ( L_91 ,
V_168 , V_188 ) ;
if ( V_188 & V_191 )
return V_192 ;
return - V_193 ;
}
return 0 ;
}
void F_36 ( unsigned int V_141 ,
struct V_146 * V_147 ,
unsigned int V_194 ,
unsigned int V_120 ,
bool V_133 ,
bool V_195 )
{
T_1 V_196 ;
T_1 V_197 ;
T_1 V_198 ;
if ( V_147 -> V_9 != V_199 ) {
F_35 ( L_92 ,
V_168 , V_147 -> V_9 , V_199 ) ;
return;
}
if ( V_195 ) {
V_196 = V_200 ;
} else {
V_196 = ( ( V_147 -> V_172 [ 0 ] & V_201 ) >>
V_202 ) + 1 ;
}
V_197 = ( V_141 - 2 ) >> 1 ;
V_198 = ( V_194 > 0 ) ;
V_147 -> V_172 [ 0 ] = ( V_198 << V_203 ) |
( V_197 << V_204 ) |
( ( V_196 - 1 ) << V_202 ) ;
if ( ! V_133 )
V_120 -= V_141 ;
F_37 ( V_120 , & V_147 -> V_172 [ 15 - V_196 + 1 ] , V_196 ) ;
}
T_2 F_24 ( T_2 V_126 )
{
return ( ( V_126 + 3 ) & ~ 3 ) - V_126 ;
}
