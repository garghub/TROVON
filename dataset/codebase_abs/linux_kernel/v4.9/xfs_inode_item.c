static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC void
F_3 (
struct V_1 * V_5 ,
int * V_6 ,
int * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_13 :
if ( ( V_5 -> V_14 & V_15 ) &&
V_9 -> V_11 . V_16 > 0 &&
V_9 -> V_17 . V_18 > 0 ) {
* V_7 += F_4 ( V_9 ) ;
* V_6 += 1 ;
}
break;
case V_19 :
if ( ( V_5 -> V_14 & V_20 ) &&
V_9 -> V_17 . V_21 > 0 ) {
* V_7 += V_9 -> V_17 . V_21 ;
* V_6 += 1 ;
}
break;
case V_22 :
if ( ( V_5 -> V_14 & V_23 ) &&
V_9 -> V_17 . V_18 > 0 ) {
* V_7 += F_5 ( V_9 -> V_17 . V_18 , 4 ) ;
* V_6 += 1 ;
}
break;
case V_24 :
case V_25 :
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_6 (
struct V_1 * V_5 ,
int * V_6 ,
int * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
switch ( V_9 -> V_11 . V_26 ) {
case V_13 :
if ( ( V_5 -> V_14 & V_27 ) &&
V_9 -> V_11 . V_28 > 0 &&
V_9 -> V_29 -> V_18 > 0 ) {
* V_7 += F_7 ( V_9 ) ;
* V_6 += 1 ;
}
break;
case V_19 :
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
* V_7 += V_9 -> V_29 -> V_21 ;
* V_6 += 1 ;
}
break;
case V_22 :
if ( ( V_5 -> V_14 & V_31 ) &&
V_9 -> V_29 -> V_18 > 0 ) {
* V_7 += F_5 ( V_9 -> V_29 -> V_18 , 4 ) ;
* V_6 += 1 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int * V_6 ,
int * V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
* V_6 += 2 ;
* V_7 += sizeof( struct V_32 ) +
F_9 ( V_9 -> V_11 . V_33 ) ;
F_3 ( V_5 , V_6 , V_7 ) ;
if ( F_10 ( V_9 ) )
F_6 ( V_5 , V_6 , V_7 ) ;
}
STATIC void
F_11 (
struct V_1 * V_5 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_39 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_15 ) &&
V_9 -> V_11 . V_16 > 0 &&
V_9 -> V_17 . V_18 > 0 ) {
struct V_42 * V_43 ;
ASSERT ( V_9 -> V_17 . V_44 . V_45 != NULL ) ;
ASSERT ( V_9 -> V_17 . V_18 / sizeof( V_46 ) > 0 ) ;
V_43 = F_12 ( V_36 , V_38 , V_47 ) ;
V_39 = F_13 ( V_9 , V_43 , V_48 ) ;
F_14 ( V_36 , * V_38 , V_39 ) ;
ASSERT ( V_39 <= V_9 -> V_17 . V_18 ) ;
V_34 -> V_49 = V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_15 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_23 | V_15 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_20 ) &&
V_9 -> V_17 . V_21 > 0 ) {
ASSERT ( V_9 -> V_17 . V_51 != NULL ) ;
F_15 ( V_36 , V_38 , V_52 ,
V_9 -> V_17 . V_51 ,
V_9 -> V_17 . V_21 ) ;
V_34 -> V_49 = V_9 -> V_17 . V_21 ;
V_34 -> V_50 ++ ;
} else {
ASSERT ( ! ( V_5 -> V_14 &
V_20 ) ) ;
V_5 -> V_14 &= ~ V_20 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_15 | V_20 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_23 ) &&
V_9 -> V_17 . V_18 > 0 ) {
V_39 = F_5 ( V_9 -> V_17 . V_18 , 4 ) ;
ASSERT ( V_9 -> V_17 . V_53 == 0 ||
V_9 -> V_17 . V_53 >= V_39 ) ;
ASSERT ( V_9 -> V_17 . V_44 . V_54 != NULL ) ;
ASSERT ( V_9 -> V_11 . V_55 > 0 ) ;
F_15 ( V_36 , V_38 , V_56 ,
V_9 -> V_17 . V_44 . V_54 , V_39 ) ;
V_34 -> V_49 = ( unsigned ) V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_23 ;
}
break;
case V_24 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_41 ) ;
if ( V_5 -> V_14 & V_40 )
V_34 -> V_57 . V_58 = V_9 -> V_17 . V_59 . V_60 ;
break;
case V_25 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_40 ) ;
if ( V_5 -> V_14 & V_41 )
V_34 -> V_57 . V_61 = V_9 -> V_17 . V_59 . V_62 ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_16 (
struct V_1 * V_5 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_39 ;
switch ( V_9 -> V_11 . V_26 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_31 | V_30 ) ;
if ( ( V_5 -> V_14 & V_27 ) &&
V_9 -> V_11 . V_28 > 0 &&
V_9 -> V_29 -> V_18 > 0 ) {
struct V_42 * V_43 ;
ASSERT ( V_9 -> V_29 -> V_18 / sizeof( V_46 ) ==
V_9 -> V_11 . V_28 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_45 != NULL ) ;
V_43 = F_12 ( V_36 , V_38 , V_63 ) ;
V_39 = F_13 ( V_9 , V_43 , V_64 ) ;
F_14 ( V_36 , * V_38 , V_39 ) ;
V_34 -> V_65 = V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_27 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_31 | V_27 ) ;
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
ASSERT ( V_9 -> V_29 -> V_51 != NULL ) ;
F_15 ( V_36 , V_38 , V_66 ,
V_9 -> V_29 -> V_51 ,
V_9 -> V_29 -> V_21 ) ;
V_34 -> V_65 = V_9 -> V_29 -> V_21 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_30 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_27 | V_30 ) ;
if ( ( V_5 -> V_14 & V_31 ) &&
V_9 -> V_29 -> V_18 > 0 ) {
V_39 = F_5 ( V_9 -> V_29 -> V_18 , 4 ) ;
ASSERT ( V_9 -> V_29 -> V_53 == 0 ||
V_9 -> V_29 -> V_53 >= V_39 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_54 != NULL ) ;
F_15 ( V_36 , V_38 , V_67 ,
V_9 -> V_29 -> V_44 . V_54 ,
V_39 ) ;
V_34 -> V_65 = ( unsigned ) V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_31 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
}
static void
F_17 (
struct V_8 * V_9 ,
struct V_68 * V_69 ,
T_2 V_70 )
{
struct V_71 * V_72 = & V_9 -> V_11 ;
struct V_73 * V_73 = F_18 ( V_9 ) ;
V_69 -> V_74 = V_75 ;
V_69 -> V_33 = V_72 -> V_33 ;
V_69 -> V_12 = V_72 -> V_12 ;
V_69 -> V_76 = V_72 -> V_76 ;
V_69 -> V_77 = V_72 -> V_77 ;
V_69 -> V_78 = V_72 -> V_78 ;
V_69 -> V_79 = V_72 -> V_79 ;
memset ( V_69 -> V_80 , 0 , sizeof( V_69 -> V_80 ) ) ;
memset ( V_69 -> V_81 , 0 , sizeof( V_69 -> V_81 ) ) ;
V_69 -> V_82 . V_83 = V_73 -> V_84 . V_85 ;
V_69 -> V_82 . V_86 = V_73 -> V_84 . V_87 ;
V_69 -> V_88 . V_83 = V_73 -> V_89 . V_85 ;
V_69 -> V_88 . V_86 = V_73 -> V_89 . V_87 ;
V_69 -> V_90 . V_83 = V_73 -> V_91 . V_85 ;
V_69 -> V_90 . V_86 = V_73 -> V_91 . V_87 ;
V_69 -> V_92 = V_73 -> V_93 ;
V_69 -> V_94 = V_73 -> V_95 ;
V_69 -> V_96 = V_73 -> V_97 ;
V_69 -> V_55 = V_72 -> V_55 ;
V_69 -> V_98 = V_72 -> V_98 ;
V_69 -> V_99 = V_72 -> V_99 ;
V_69 -> V_16 = V_72 -> V_16 ;
V_69 -> V_28 = V_72 -> V_28 ;
V_69 -> V_100 = V_72 -> V_100 ;
V_69 -> V_26 = V_72 -> V_26 ;
V_69 -> V_101 = V_72 -> V_101 ;
V_69 -> V_102 = V_72 -> V_102 ;
V_69 -> V_103 = V_72 -> V_103 ;
if ( V_72 -> V_33 == 3 ) {
V_69 -> V_104 = V_73 -> V_105 ;
V_69 -> V_106 . V_83 = V_72 -> V_106 . V_83 ;
V_69 -> V_106 . V_86 = V_72 -> V_106 . V_86 ;
V_69 -> V_107 = V_72 -> V_107 ;
V_69 -> V_108 = V_72 -> V_108 ;
V_69 -> V_109 = V_9 -> V_110 ;
V_69 -> V_111 = V_70 ;
memset ( V_69 -> V_112 , 0 , sizeof( V_69 -> V_112 ) ) ;
F_19 ( & V_69 -> V_113 , & V_9 -> V_114 -> V_115 . V_116 ) ;
V_69 -> V_117 = 0 ;
} else {
V_69 -> V_117 = V_72 -> V_117 ;
}
}
static void
F_20 (
struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_68 * V_118 ;
V_118 = F_12 ( V_36 , V_38 , V_119 ) ;
F_17 ( V_9 , V_118 , V_9 -> V_120 -> V_4 . V_121 ) ;
F_14 ( V_36 , * V_38 , F_9 ( V_9 -> V_11 . V_33 ) ) ;
}
STATIC void
F_21 (
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_32 * V_34 ;
struct V_37 * V_38 = NULL ;
ASSERT ( V_9 -> V_11 . V_33 > 1 ) ;
V_34 = F_12 ( V_36 , & V_38 , V_122 ) ;
V_34 -> V_123 = V_124 ;
V_34 -> V_125 = V_9 -> V_110 ;
V_34 -> V_126 = V_9 -> V_127 . V_128 ;
V_34 -> V_129 = V_9 -> V_127 . V_130 ;
V_34 -> V_131 = V_9 -> V_127 . V_132 ;
V_34 -> V_133 = V_134 ;
V_34 -> V_50 = 2 ;
F_14 ( V_36 , V_38 , sizeof( struct V_32 ) ) ;
F_20 ( V_9 , V_36 , & V_38 ) ;
F_11 ( V_5 , V_34 , V_36 , & V_38 ) ;
if ( F_10 ( V_9 ) ) {
F_16 ( V_5 , V_34 , V_36 , & V_38 ) ;
} else {
V_5 -> V_14 &=
~ ( V_31 | V_30 | V_27 ) ;
}
V_34 -> V_133 |= ( V_5 -> V_14 & ~ V_135 ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_23 ( V_9 , V_136 ) ) ;
F_24 ( V_9 , V_137 ) ;
F_25 ( & V_9 -> V_138 ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_27 ( V_9 , V_137 ) ;
ASSERT ( F_28 ( & V_9 -> V_138 ) > 0 ) ;
if ( F_29 ( & V_9 -> V_138 ) )
F_30 ( & V_9 -> V_139 , V_140 ) ;
}
STATIC T_3
F_31 (
struct V_2 * V_3 ,
struct V_141 * V_142 )
__releases( &lip->li_ailp->xa_lock
STATIC void
F_32 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
unsigned short V_143 ;
ASSERT ( V_9 -> V_120 != NULL ) ;
ASSERT ( F_23 ( V_9 , V_136 ) ) ;
V_143 = V_5 -> V_144 ;
V_5 -> V_144 = 0 ;
if ( V_143 )
F_33 ( V_9 , V_143 ) ;
}
STATIC T_2
F_34 (
struct V_2 * V_3 ,
T_2 V_70 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
if ( F_35 ( V_9 , V_145 ) ) {
F_26 ( V_3 , 0 ) ;
return - 1 ;
}
return V_70 ;
}
STATIC void
F_36 (
struct V_2 * V_3 ,
T_2 V_70 )
{
F_1 ( V_3 ) -> V_146 = V_70 ;
}
void
F_37 (
struct V_8 * V_9 ,
struct V_147 * V_148 )
{
struct V_1 * V_5 ;
ASSERT ( V_9 -> V_120 == NULL ) ;
V_5 = V_9 -> V_120 = F_38 ( V_149 , V_150 ) ;
V_5 -> V_10 = V_9 ;
F_39 ( V_148 , & V_5 -> V_4 , V_124 ,
& V_151 ) ;
}
void
F_40 (
T_4 * V_9 )
{
F_41 ( V_9 -> V_120 -> V_4 . V_152 ) ;
F_42 ( V_149 , V_9 -> V_120 ) ;
}
void
F_43 (
struct V_153 * V_154 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_155 ;
struct V_2 * V_156 ;
struct V_2 * V_157 ;
struct V_158 * V_159 = V_3 -> V_160 ;
int V_161 = 0 ;
V_155 = V_154 -> V_162 ;
V_157 = NULL ;
while ( V_155 != NULL ) {
if ( V_155 -> V_163 != F_43 ) {
V_157 = V_155 ;
V_155 = V_155 -> V_164 ;
continue;
}
V_156 = V_155 -> V_164 ;
if ( ! V_157 ) {
V_154 -> V_162 = V_156 ;
} else {
V_157 -> V_164 = V_156 ;
}
V_155 -> V_164 = V_3 -> V_164 ;
V_3 -> V_164 = V_155 ;
V_5 = F_1 ( V_155 ) ;
if ( V_5 -> V_165 && V_155 -> V_121 == V_5 -> V_166 )
V_161 ++ ;
V_155 = V_156 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_165 && V_3 -> V_121 == V_5 -> V_166 )
V_161 ++ ;
if ( V_161 ) {
struct V_2 * V_167 [ V_161 ] ;
int V_168 = 0 ;
F_44 ( & V_159 -> V_169 ) ;
for ( V_155 = V_3 ; V_155 ; V_155 = V_155 -> V_164 ) {
V_5 = F_1 ( V_155 ) ;
if ( V_5 -> V_165 &&
V_155 -> V_121 == V_5 -> V_166 ) {
V_167 [ V_168 ++ ] = V_155 ;
}
ASSERT ( V_168 <= V_161 ) ;
}
F_45 ( V_159 , V_167 , V_168 ,
V_170 ) ;
}
for ( V_155 = V_3 ; V_155 ; V_155 = V_156 ) {
V_156 = V_155 -> V_164 ;
V_155 -> V_164 = NULL ;
V_5 = F_1 ( V_155 ) ;
V_5 -> V_165 = 0 ;
V_5 -> V_171 = 0 ;
F_46 ( V_5 -> V_10 ) ;
}
}
void
F_47 (
T_4 * V_9 ,
bool V_172 )
{
T_5 * V_5 = V_9 -> V_120 ;
if ( V_5 ) {
if ( V_5 -> V_4 . V_173 & V_174 ) {
F_48 ( & V_5 -> V_4 ,
V_172 ? V_175 :
V_170 ) ;
}
V_5 -> V_165 = 0 ;
V_5 -> V_171 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_176 = 0 ;
}
F_46 ( V_9 ) ;
}
void
F_49 (
struct V_153 * V_154 ,
struct V_2 * V_3 )
{
F_47 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_50 (
T_6 * V_177 ,
T_7 * V_178 )
{
if ( V_177 -> V_179 == sizeof( V_180 ) ) {
V_180 * V_181 = V_177 -> V_182 ;
V_178 -> V_123 = V_181 -> V_123 ;
V_178 -> V_50 = V_181 -> V_50 ;
V_178 -> V_133 = V_181 -> V_133 ;
V_178 -> V_65 = V_181 -> V_65 ;
V_178 -> V_49 = V_181 -> V_49 ;
V_178 -> V_125 = V_181 -> V_125 ;
memcpy ( V_178 -> V_57 . V_61 . V_183 ,
V_181 -> V_57 . V_61 . V_183 ,
sizeof( V_184 ) ) ;
V_178 -> V_126 = V_181 -> V_126 ;
V_178 -> V_129 = V_181 -> V_129 ;
V_178 -> V_131 = V_181 -> V_131 ;
return 0 ;
} else if ( V_177 -> V_179 == sizeof( V_185 ) ) {
V_185 * V_186 = V_177 -> V_182 ;
V_178 -> V_123 = V_186 -> V_123 ;
V_178 -> V_50 = V_186 -> V_50 ;
V_178 -> V_133 = V_186 -> V_133 ;
V_178 -> V_65 = V_186 -> V_65 ;
V_178 -> V_49 = V_186 -> V_49 ;
V_178 -> V_125 = V_186 -> V_125 ;
memcpy ( V_178 -> V_57 . V_61 . V_183 ,
V_186 -> V_57 . V_61 . V_183 ,
sizeof( V_184 ) ) ;
V_178 -> V_126 = V_186 -> V_126 ;
V_178 -> V_129 = V_186 -> V_129 ;
V_178 -> V_131 = V_186 -> V_131 ;
return 0 ;
}
return - V_187 ;
}
