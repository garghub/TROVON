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
V_68 -> V_103 = V_104 ;
if ( V_71 -> V_33 == 3 ) {
V_68 -> V_105 = V_72 -> V_106 ;
V_68 -> V_107 . V_82 = V_71 -> V_107 . V_82 ;
V_68 -> V_107 . V_85 = V_71 -> V_107 . V_85 ;
V_68 -> V_108 = V_71 -> V_108 ;
V_68 -> V_109 = V_71 -> V_109 ;
V_68 -> V_110 = V_9 -> V_111 ;
V_68 -> V_112 = V_69 ;
memset ( V_68 -> V_113 , 0 , sizeof( V_68 -> V_113 ) ) ;
F_20 ( & V_68 -> V_114 , & V_9 -> V_115 -> V_116 . V_117 ) ;
V_68 -> V_118 = 0 ;
} else {
V_68 -> V_118 = V_71 -> V_118 ;
}
}
static void
F_21 (
struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_67 * V_119 ;
V_119 = F_13 ( V_36 , V_38 , V_120 ) ;
F_18 ( V_9 , V_119 , V_9 -> V_121 -> V_4 . V_122 ) ;
F_15 ( V_36 , * V_38 , F_9 ( V_9 -> V_11 . V_33 ) ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_37 * V_38 = NULL ;
struct V_32 * V_34 ;
ASSERT ( V_9 -> V_11 . V_33 > 1 ) ;
V_34 = F_13 ( V_36 , & V_38 , V_123 ) ;
V_34 -> V_124 = V_125 ;
V_34 -> V_126 = V_9 -> V_111 ;
V_34 -> V_127 = V_9 -> V_128 . V_129 ;
V_34 -> V_130 = V_9 -> V_128 . V_131 ;
V_34 -> V_132 = V_9 -> V_128 . V_133 ;
V_34 -> V_134 = V_135 ;
V_34 -> V_49 = 2 ;
V_34 -> V_48 = 0 ;
V_34 -> V_64 = 0 ;
V_34 -> V_136 = 0 ;
F_20 ( & V_34 -> V_56 . V_60 , & V_137 ) ;
F_15 ( V_36 , V_38 , sizeof( * V_34 ) ) ;
F_21 ( V_9 , V_36 , & V_38 ) ;
F_11 ( V_5 , V_34 , V_36 , & V_38 ) ;
if ( F_10 ( V_9 ) ) {
F_17 ( V_5 , V_34 , V_36 , & V_38 ) ;
} else {
V_5 -> V_14 &=
~ ( V_31 | V_30 | V_27 ) ;
}
V_34 -> V_134 |= ( V_5 -> V_14 & ~ V_138 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_24 ( V_9 , V_139 ) ) ;
F_25 ( V_9 , V_140 ) ;
F_26 ( & V_9 -> V_141 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_28 ( V_9 , V_140 ) ;
ASSERT ( F_29 ( & V_9 -> V_141 ) > 0 ) ;
if ( F_30 ( & V_9 -> V_141 ) )
F_31 ( & V_9 -> V_142 , V_143 ) ;
}
STATIC void
F_32 (
struct V_2 * V_3 ,
struct V_144 * V_145 )
{
ASSERT ( F_33 ( F_1 ( V_3 ) -> V_10 ) ) ;
F_34 ( V_3 , V_145 ) ;
}
STATIC T_3
F_35 (
struct V_2 * V_3 ,
struct V_146 * V_147 )
__releases( &lip->li_ailp->xa_lock
STATIC void
F_36 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
unsigned short V_148 ;
ASSERT ( V_9 -> V_121 != NULL ) ;
ASSERT ( F_24 ( V_9 , V_139 ) ) ;
V_148 = V_5 -> V_149 ;
V_5 -> V_149 = 0 ;
if ( V_148 )
F_37 ( V_9 , V_148 ) ;
}
STATIC T_2
F_38 (
struct V_2 * V_3 ,
T_2 V_69 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
if ( F_39 ( V_9 , V_150 ) ) {
F_27 ( V_3 , 0 ) ;
return - 1 ;
}
return V_69 ;
}
STATIC void
F_40 (
struct V_2 * V_3 ,
T_2 V_69 )
{
F_1 ( V_3 ) -> V_151 = V_69 ;
}
void
F_41 (
struct V_8 * V_9 ,
struct V_152 * V_153 )
{
struct V_1 * V_5 ;
ASSERT ( V_9 -> V_121 == NULL ) ;
V_5 = V_9 -> V_121 = F_42 ( V_154 , V_155 ) ;
V_5 -> V_10 = V_9 ;
F_43 ( V_153 , & V_5 -> V_4 , V_125 ,
& V_156 ) ;
}
void
F_44 (
T_4 * V_9 )
{
F_45 ( V_9 -> V_121 -> V_4 . V_157 ) ;
F_46 ( V_154 , V_9 -> V_121 ) ;
}
void
F_47 (
struct V_144 * V_145 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_158 ;
struct V_2 * V_159 ;
struct V_2 * V_160 ;
struct V_161 * V_162 = V_3 -> V_163 ;
int V_164 = 0 ;
V_158 = V_145 -> V_165 ;
V_160 = NULL ;
while ( V_158 != NULL ) {
if ( V_158 -> V_166 != F_47 ) {
V_160 = V_158 ;
V_158 = V_158 -> V_167 ;
continue;
}
V_159 = V_158 -> V_167 ;
if ( ! V_160 ) {
V_145 -> V_165 = V_159 ;
} else {
V_160 -> V_167 = V_159 ;
}
V_158 -> V_167 = V_3 -> V_167 ;
V_3 -> V_167 = V_158 ;
V_5 = F_1 ( V_158 ) ;
if ( ( V_5 -> V_168 && V_158 -> V_122 == V_5 -> V_169 ) ||
( V_158 -> V_170 & V_171 ) )
V_164 ++ ;
V_158 = V_159 ;
}
V_5 = F_1 ( V_3 ) ;
if ( ( V_5 -> V_168 && V_3 -> V_122 == V_5 -> V_169 ) ||
V_3 -> V_170 & V_171 )
V_164 ++ ;
if ( V_164 ) {
bool V_172 = false ;
F_48 ( & V_162 -> V_173 ) ;
for ( V_158 = V_3 ; V_158 ; V_158 = V_158 -> V_167 ) {
if ( F_1 ( V_158 ) -> V_168 &&
V_158 -> V_122 == F_1 ( V_158 ) -> V_169 )
V_172 |= F_49 ( V_162 , V_158 ) ;
else {
F_50 ( V_158 ) ;
}
}
if ( V_172 ) {
if ( ! F_51 ( V_162 -> V_174 ) )
F_52 ( V_162 -> V_174 ) ;
if ( F_53 ( & V_162 -> V_175 ) )
F_54 ( & V_162 -> V_176 ) ;
}
F_55 ( & V_162 -> V_173 ) ;
if ( V_172 )
F_56 ( V_162 -> V_174 ) ;
}
for ( V_158 = V_3 ; V_158 ; V_158 = V_159 ) {
V_159 = V_158 -> V_167 ;
V_158 -> V_167 = NULL ;
V_5 = F_1 ( V_158 ) ;
V_5 -> V_168 = 0 ;
V_5 -> V_177 = 0 ;
F_57 ( V_5 -> V_10 ) ;
}
}
void
F_58 (
T_4 * V_9 ,
bool V_178 )
{
T_5 * V_5 = V_9 -> V_121 ;
if ( V_5 ) {
if ( V_5 -> V_4 . V_170 & V_179 ) {
F_59 ( & V_5 -> V_4 ,
V_178 ? V_180 :
V_181 ) ;
}
V_5 -> V_168 = 0 ;
V_5 -> V_177 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_182 = 0 ;
}
F_57 ( V_9 ) ;
}
void
F_60 (
struct V_144 * V_145 ,
struct V_2 * V_3 )
{
F_58 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_61 (
struct V_37 * V_183 ,
struct V_32 * V_184 )
{
struct V_185 * V_186 = V_183 -> V_187 ;
if ( V_183 -> V_188 != sizeof( * V_186 ) )
return - V_189 ;
V_184 -> V_124 = V_186 -> V_124 ;
V_184 -> V_49 = V_186 -> V_49 ;
V_184 -> V_134 = V_186 -> V_134 ;
V_184 -> V_64 = V_186 -> V_64 ;
V_184 -> V_48 = V_186 -> V_48 ;
V_184 -> V_126 = V_186 -> V_126 ;
F_20 ( & V_184 -> V_56 . V_60 , & V_186 -> V_56 . V_60 ) ;
V_184 -> V_127 = V_186 -> V_127 ;
V_184 -> V_130 = V_186 -> V_130 ;
V_184 -> V_132 = V_186 -> V_132 ;
return 0 ;
}
