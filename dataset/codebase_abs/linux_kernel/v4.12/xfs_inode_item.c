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
ASSERT ( F_12 ( & V_9 -> V_17 ) > 0 ) ;
V_43 = F_13 ( V_36 , V_38 , V_46 ) ;
V_39 = F_14 ( V_9 , V_43 , V_47 ) ;
F_15 ( V_36 , * V_38 , V_39 ) ;
ASSERT ( V_39 <= V_9 -> V_17 . V_18 ) ;
V_34 -> V_48 = V_39 ;
V_34 -> V_49 ++ ;
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
ASSERT ( V_9 -> V_17 . V_50 != NULL ) ;
F_16 ( V_36 , V_38 , V_51 ,
V_9 -> V_17 . V_50 ,
V_9 -> V_17 . V_21 ) ;
V_34 -> V_48 = V_9 -> V_17 . V_21 ;
V_34 -> V_49 ++ ;
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
ASSERT ( V_9 -> V_17 . V_52 == 0 ||
V_9 -> V_17 . V_52 >= V_39 ) ;
ASSERT ( V_9 -> V_17 . V_44 . V_53 != NULL ) ;
ASSERT ( V_9 -> V_11 . V_54 > 0 ) ;
F_16 ( V_36 , V_38 , V_55 ,
V_9 -> V_17 . V_44 . V_53 , V_39 ) ;
V_34 -> V_48 = ( unsigned ) V_39 ;
V_34 -> V_49 ++ ;
} else {
V_5 -> V_14 &= ~ V_23 ;
}
break;
case V_24 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_41 ) ;
if ( V_5 -> V_14 & V_40 )
V_34 -> V_56 . V_57 = V_9 -> V_17 . V_58 . V_59 ;
break;
case V_25 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_40 ) ;
if ( V_5 -> V_14 & V_41 )
V_34 -> V_56 . V_60 = V_9 -> V_17 . V_58 . V_61 ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_17 (
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
ASSERT ( F_12 ( V_9 -> V_29 ) ==
V_9 -> V_11 . V_28 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_45 != NULL ) ;
V_43 = F_13 ( V_36 , V_38 , V_62 ) ;
V_39 = F_14 ( V_9 , V_43 , V_63 ) ;
F_15 ( V_36 , * V_38 , V_39 ) ;
V_34 -> V_64 = V_39 ;
V_34 -> V_49 ++ ;
} else {
V_5 -> V_14 &= ~ V_27 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_31 | V_27 ) ;
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
ASSERT ( V_9 -> V_29 -> V_50 != NULL ) ;
F_16 ( V_36 , V_38 , V_65 ,
V_9 -> V_29 -> V_50 ,
V_9 -> V_29 -> V_21 ) ;
V_34 -> V_64 = V_9 -> V_29 -> V_21 ;
V_34 -> V_49 ++ ;
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
ASSERT ( V_9 -> V_29 -> V_52 == 0 ||
V_9 -> V_29 -> V_52 >= V_39 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_53 != NULL ) ;
F_16 ( V_36 , V_38 , V_66 ,
V_9 -> V_29 -> V_44 . V_53 ,
V_39 ) ;
V_34 -> V_64 = ( unsigned ) V_39 ;
V_34 -> V_49 ++ ;
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
F_18 (
struct V_8 * V_9 ,
struct V_67 * V_68 ,
T_2 V_69 )
{
struct V_70 * V_71 = & V_9 -> V_11 ;
struct V_72 * V_72 = F_19 ( V_9 ) ;
V_68 -> V_73 = V_74 ;
V_68 -> V_33 = V_71 -> V_33 ;
V_68 -> V_12 = V_71 -> V_12 ;
V_68 -> V_75 = V_71 -> V_75 ;
V_68 -> V_76 = V_71 -> V_76 ;
V_68 -> V_77 = V_71 -> V_77 ;
V_68 -> V_78 = V_71 -> V_78 ;
memset ( V_68 -> V_79 , 0 , sizeof( V_68 -> V_79 ) ) ;
memset ( V_68 -> V_80 , 0 , sizeof( V_68 -> V_80 ) ) ;
V_68 -> V_81 . V_82 = V_72 -> V_83 . V_84 ;
V_68 -> V_81 . V_85 = V_72 -> V_83 . V_86 ;
V_68 -> V_87 . V_82 = V_72 -> V_88 . V_84 ;
V_68 -> V_87 . V_85 = V_72 -> V_88 . V_86 ;
V_68 -> V_89 . V_82 = V_72 -> V_90 . V_84 ;
V_68 -> V_89 . V_85 = V_72 -> V_90 . V_86 ;
V_68 -> V_91 = V_72 -> V_92 ;
V_68 -> V_93 = V_72 -> V_94 ;
V_68 -> V_95 = V_72 -> V_96 ;
V_68 -> V_54 = V_71 -> V_54 ;
V_68 -> V_97 = V_71 -> V_97 ;
V_68 -> V_98 = V_71 -> V_98 ;
V_68 -> V_16 = V_71 -> V_16 ;
V_68 -> V_28 = V_71 -> V_28 ;
V_68 -> V_99 = V_71 -> V_99 ;
V_68 -> V_26 = V_71 -> V_26 ;
V_68 -> V_100 = V_71 -> V_100 ;
V_68 -> V_101 = V_71 -> V_101 ;
V_68 -> V_102 = V_71 -> V_102 ;
if ( V_71 -> V_33 == 3 ) {
V_68 -> V_103 = V_72 -> V_104 ;
V_68 -> V_105 . V_82 = V_71 -> V_105 . V_82 ;
V_68 -> V_105 . V_85 = V_71 -> V_105 . V_85 ;
V_68 -> V_106 = V_71 -> V_106 ;
V_68 -> V_107 = V_71 -> V_107 ;
V_68 -> V_108 = V_9 -> V_109 ;
V_68 -> V_110 = V_69 ;
memset ( V_68 -> V_111 , 0 , sizeof( V_68 -> V_111 ) ) ;
F_20 ( & V_68 -> V_112 , & V_9 -> V_113 -> V_114 . V_115 ) ;
V_68 -> V_116 = 0 ;
} else {
V_68 -> V_116 = V_71 -> V_116 ;
}
}
static void
F_21 (
struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_67 * V_117 ;
V_117 = F_13 ( V_36 , V_38 , V_118 ) ;
F_18 ( V_9 , V_117 , V_9 -> V_119 -> V_4 . V_120 ) ;
F_15 ( V_36 , * V_38 , F_9 ( V_9 -> V_11 . V_33 ) ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_32 * V_34 ;
struct V_37 * V_38 = NULL ;
ASSERT ( V_9 -> V_11 . V_33 > 1 ) ;
V_34 = F_13 ( V_36 , & V_38 , V_121 ) ;
V_34 -> V_122 = V_123 ;
V_34 -> V_124 = V_9 -> V_109 ;
V_34 -> V_125 = V_9 -> V_126 . V_127 ;
V_34 -> V_128 = V_9 -> V_126 . V_129 ;
V_34 -> V_130 = V_9 -> V_126 . V_131 ;
V_34 -> V_132 = V_133 ;
V_34 -> V_49 = 2 ;
F_15 ( V_36 , V_38 , sizeof( struct V_32 ) ) ;
F_21 ( V_9 , V_36 , & V_38 ) ;
F_11 ( V_5 , V_34 , V_36 , & V_38 ) ;
if ( F_10 ( V_9 ) ) {
F_17 ( V_5 , V_34 , V_36 , & V_38 ) ;
} else {
V_5 -> V_14 &=
~ ( V_31 | V_30 | V_27 ) ;
}
V_34 -> V_132 |= ( V_5 -> V_14 & ~ V_134 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_24 ( V_9 , V_135 ) ) ;
F_25 ( V_9 , V_136 ) ;
F_26 ( & V_9 -> V_137 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_28 ( V_9 , V_136 ) ;
ASSERT ( F_29 ( & V_9 -> V_137 ) > 0 ) ;
if ( F_30 ( & V_9 -> V_137 ) )
F_31 ( & V_9 -> V_138 , V_139 ) ;
}
STATIC T_3
F_32 (
struct V_2 * V_3 ,
struct V_140 * V_141 )
__releases( &lip->li_ailp->xa_lock
STATIC void
F_33 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
unsigned short V_142 ;
ASSERT ( V_9 -> V_119 != NULL ) ;
ASSERT ( F_24 ( V_9 , V_135 ) ) ;
V_142 = V_5 -> V_143 ;
V_5 -> V_143 = 0 ;
if ( V_142 )
F_34 ( V_9 , V_142 ) ;
}
STATIC T_2
F_35 (
struct V_2 * V_3 ,
T_2 V_69 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
if ( F_36 ( V_9 , V_144 ) ) {
F_27 ( V_3 , 0 ) ;
return - 1 ;
}
return V_69 ;
}
STATIC void
F_37 (
struct V_2 * V_3 ,
T_2 V_69 )
{
F_1 ( V_3 ) -> V_145 = V_69 ;
}
void
F_38 (
struct V_8 * V_9 ,
struct V_146 * V_147 )
{
struct V_1 * V_5 ;
ASSERT ( V_9 -> V_119 == NULL ) ;
V_5 = V_9 -> V_119 = F_39 ( V_148 , V_149 ) ;
V_5 -> V_10 = V_9 ;
F_40 ( V_147 , & V_5 -> V_4 , V_123 ,
& V_150 ) ;
}
void
F_41 (
T_4 * V_9 )
{
F_42 ( V_9 -> V_119 -> V_4 . V_151 ) ;
F_43 ( V_148 , V_9 -> V_119 ) ;
}
void
F_44 (
struct V_152 * V_153 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_154 ;
struct V_2 * V_155 ;
struct V_2 * V_156 ;
struct V_157 * V_158 = V_3 -> V_159 ;
int V_160 = 0 ;
V_154 = V_153 -> V_161 ;
V_156 = NULL ;
while ( V_154 != NULL ) {
if ( V_154 -> V_162 != F_44 ) {
V_156 = V_154 ;
V_154 = V_154 -> V_163 ;
continue;
}
V_155 = V_154 -> V_163 ;
if ( ! V_156 ) {
V_153 -> V_161 = V_155 ;
} else {
V_156 -> V_163 = V_155 ;
}
V_154 -> V_163 = V_3 -> V_163 ;
V_3 -> V_163 = V_154 ;
V_5 = F_1 ( V_154 ) ;
if ( V_5 -> V_164 && V_154 -> V_120 == V_5 -> V_165 )
V_160 ++ ;
V_154 = V_155 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_164 && V_3 -> V_120 == V_5 -> V_165 )
V_160 ++ ;
if ( V_160 ) {
bool V_166 = false ;
F_45 ( & V_158 -> V_167 ) ;
for ( V_154 = V_3 ; V_154 ; V_154 = V_154 -> V_163 ) {
if ( F_1 ( V_154 ) -> V_164 &&
V_154 -> V_120 == F_1 ( V_154 ) -> V_165 )
V_166 |= F_46 ( V_158 , V_154 ) ;
}
if ( V_166 ) {
if ( ! F_47 ( V_158 -> V_168 ) )
F_48 ( V_158 -> V_168 ) ;
if ( F_49 ( & V_158 -> V_169 ) )
F_50 ( & V_158 -> V_170 ) ;
}
F_51 ( & V_158 -> V_167 ) ;
if ( V_166 )
F_52 ( V_158 -> V_168 ) ;
}
for ( V_154 = V_3 ; V_154 ; V_154 = V_155 ) {
V_155 = V_154 -> V_163 ;
V_154 -> V_163 = NULL ;
V_5 = F_1 ( V_154 ) ;
V_5 -> V_164 = 0 ;
V_5 -> V_171 = 0 ;
F_53 ( V_5 -> V_10 ) ;
}
}
void
F_54 (
T_4 * V_9 ,
bool V_172 )
{
T_5 * V_5 = V_9 -> V_119 ;
if ( V_5 ) {
if ( V_5 -> V_4 . V_173 & V_174 ) {
F_55 ( & V_5 -> V_4 ,
V_172 ? V_175 :
V_176 ) ;
}
V_5 -> V_164 = 0 ;
V_5 -> V_171 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_177 = 0 ;
}
F_53 ( V_9 ) ;
}
void
F_56 (
struct V_152 * V_153 ,
struct V_2 * V_3 )
{
F_54 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_57 (
T_6 * V_178 ,
T_7 * V_179 )
{
if ( V_178 -> V_180 == sizeof( V_181 ) ) {
V_181 * V_182 = V_178 -> V_183 ;
V_179 -> V_122 = V_182 -> V_122 ;
V_179 -> V_49 = V_182 -> V_49 ;
V_179 -> V_132 = V_182 -> V_132 ;
V_179 -> V_64 = V_182 -> V_64 ;
V_179 -> V_48 = V_182 -> V_48 ;
V_179 -> V_124 = V_182 -> V_124 ;
memcpy ( V_179 -> V_56 . V_60 . V_184 ,
V_182 -> V_56 . V_60 . V_184 ,
sizeof( V_185 ) ) ;
V_179 -> V_125 = V_182 -> V_125 ;
V_179 -> V_128 = V_182 -> V_128 ;
V_179 -> V_130 = V_182 -> V_130 ;
return 0 ;
} else if ( V_178 -> V_180 == sizeof( V_186 ) ) {
V_186 * V_187 = V_178 -> V_183 ;
V_179 -> V_122 = V_187 -> V_122 ;
V_179 -> V_49 = V_187 -> V_49 ;
V_179 -> V_132 = V_187 -> V_132 ;
V_179 -> V_64 = V_187 -> V_64 ;
V_179 -> V_48 = V_187 -> V_48 ;
V_179 -> V_124 = V_187 -> V_124 ;
memcpy ( V_179 -> V_56 . V_60 . V_184 ,
V_187 -> V_56 . V_60 . V_184 ,
sizeof( V_185 ) ) ;
V_179 -> V_125 = V_187 -> V_125 ;
V_179 -> V_128 = V_187 -> V_128 ;
V_179 -> V_130 = V_187 -> V_130 ;
return 0 ;
}
return - V_188 ;
}
