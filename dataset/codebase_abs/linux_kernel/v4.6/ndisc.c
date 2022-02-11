static void F_1 ( struct V_1 * V_2 , int type , void * V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 -> type ) ;
int V_6 = V_2 -> V_5 -> V_7 ;
int V_8 = F_3 ( V_2 -> V_5 ) ;
T_1 * V_9 = F_4 ( V_2 , V_8 ) ;
V_9 [ 0 ] = type ;
V_9 [ 1 ] = V_8 >> 3 ;
memset ( V_9 + 2 , 0 , V_4 ) ;
V_9 += V_4 ;
V_8 -= V_4 ;
memcpy ( V_9 + 2 , V_3 , V_6 ) ;
V_6 += 2 ;
V_9 += V_6 ;
V_8 -= V_6 ;
if ( V_8 > 0 )
memset ( V_9 , 0 , V_8 ) ;
}
static struct V_10 * F_5 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
int type ;
if ( ! V_11 || ! V_12 || V_11 >= V_12 )
return NULL ;
type = V_11 -> V_13 ;
do {
V_11 = ( ( void * ) V_11 ) + ( V_11 -> V_14 << 3 ) ;
} while ( V_11 < V_12 && V_11 -> V_13 != type );
return V_11 <= V_12 && V_11 -> V_13 == type ? V_11 : NULL ;
}
static inline int F_6 ( struct V_10 * V_9 )
{
return V_9 -> V_13 == V_15 ||
V_9 -> V_13 == V_16 ;
}
static struct V_10 * F_7 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
if ( ! V_11 || ! V_12 || V_11 >= V_12 )
return NULL ;
do {
V_11 = ( ( void * ) V_11 ) + ( V_11 -> V_14 << 3 ) ;
} while ( V_11 < V_12 && ! F_6 ( V_11 ) );
return V_11 <= V_12 && F_6 ( V_11 ) ? V_11 : NULL ;
}
struct V_17 * F_8 ( T_1 * V_9 , int V_18 ,
struct V_17 * V_19 )
{
struct V_10 * V_20 = (struct V_10 * ) V_9 ;
if ( ! V_20 || V_18 < 0 || ! V_19 )
return NULL ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
while ( V_18 ) {
int V_21 ;
if ( V_18 < sizeof( struct V_10 ) )
return NULL ;
V_21 = V_20 -> V_14 << 3 ;
if ( V_18 < V_21 || V_21 == 0 )
return NULL ;
switch ( V_20 -> V_13 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if ( V_19 -> V_26 [ V_20 -> V_13 ] ) {
F_9 ( 2 , V_27 ,
L_1 ,
V_28 , V_20 -> V_13 ) ;
} else {
V_19 -> V_26 [ V_20 -> V_13 ] = V_20 ;
}
break;
case V_29 :
V_19 -> V_30 = V_20 ;
if ( ! V_19 -> V_26 [ V_20 -> V_13 ] )
V_19 -> V_26 [ V_20 -> V_13 ] = V_20 ;
break;
#ifdef F_10
case V_31 :
V_19 -> V_32 = V_20 ;
if ( ! V_19 -> V_33 )
V_19 -> V_33 = V_20 ;
break;
#endif
default:
if ( F_6 ( V_20 ) ) {
V_19 -> V_34 = V_20 ;
if ( ! V_19 -> V_35 )
V_19 -> V_35 = V_20 ;
} else {
F_9 ( 2 , V_36 ,
L_2 ,
V_28 ,
V_20 -> V_13 ,
V_20 -> V_14 ) ;
}
}
V_18 -= V_21 ;
V_20 = ( ( void * ) V_20 ) + V_21 ;
}
return V_19 ;
}
int F_11 ( const struct V_37 * V_38 , char * V_39 , struct V_40 * V_5 , int V_41 )
{
switch ( V_5 -> type ) {
case V_42 :
case V_43 :
case V_44 :
F_12 ( V_38 , V_39 ) ;
return 0 ;
case V_45 :
F_13 ( V_38 , V_39 ) ;
return 0 ;
case V_46 :
F_14 ( V_38 , V_5 -> V_47 , V_39 ) ;
return 0 ;
case V_48 :
return F_15 ( V_38 , V_5 -> V_47 , V_39 ) ;
default:
if ( V_41 ) {
memcpy ( V_39 , V_5 -> V_47 , V_5 -> V_7 ) ;
return 0 ;
}
}
return - V_49 ;
}
static T_2 F_16 ( const void * V_50 ,
const struct V_40 * V_5 ,
T_3 * V_51 )
{
return F_17 ( V_50 , V_5 , V_51 ) ;
}
static bool F_18 ( const struct V_52 * V_53 , const void * V_50 )
{
return F_19 ( V_53 , V_50 ) ;
}
static int F_20 ( struct V_52 * V_54 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_54 -> V_55 ;
struct V_40 * V_5 = V_54 -> V_5 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
bool V_60 = F_21 ( V_38 ) ;
V_57 = F_22 ( V_5 ) ;
if ( ! V_57 ) {
return - V_49 ;
}
V_59 = V_57 -> V_61 ;
F_23 ( V_54 -> V_59 ) ;
V_54 -> V_59 = F_24 ( V_59 ) ;
V_54 -> type = V_60 ? V_62 : V_63 ;
if ( ! V_5 -> V_64 ) {
V_54 -> V_65 = V_66 ;
V_54 -> V_67 = & V_68 ;
V_54 -> V_69 = V_70 ;
} else {
if ( V_60 ) {
V_54 -> V_65 = V_66 ;
F_11 ( V_38 , V_54 -> V_71 , V_5 , 1 ) ;
} else if ( V_5 -> V_72 & ( V_73 | V_74 ) ) {
V_54 -> V_65 = V_66 ;
memcpy ( V_54 -> V_71 , V_5 -> V_75 , V_5 -> V_7 ) ;
if ( V_5 -> V_72 & V_74 )
V_54 -> type = V_76 ;
} else if ( V_5 -> V_72 & V_77 ) {
V_54 -> V_65 = V_66 ;
memcpy ( V_54 -> V_71 , V_5 -> V_47 , V_5 -> V_7 ) ;
}
if ( V_5 -> V_64 -> V_78 )
V_54 -> V_67 = & V_79 ;
else
V_54 -> V_67 = & V_80 ;
if ( V_54 -> V_65 & V_81 )
V_54 -> V_69 = V_54 -> V_67 -> V_82 ;
else
V_54 -> V_69 = V_54 -> V_67 -> V_69 ;
}
F_25 ( V_57 ) ;
return 0 ;
}
static int F_26 ( struct V_83 * V_53 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_53 -> V_84 ;
struct V_37 V_85 ;
struct V_40 * V_5 = V_53 -> V_5 ;
if ( ! V_5 || ! F_27 ( V_5 ) )
return - V_49 ;
F_28 ( V_38 , & V_85 ) ;
F_29 ( V_5 , & V_85 ) ;
return 0 ;
}
static void F_30 ( struct V_83 * V_53 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_53 -> V_84 ;
struct V_37 V_85 ;
struct V_40 * V_5 = V_53 -> V_5 ;
if ( ! V_5 || ! F_27 ( V_5 ) )
return;
F_28 ( V_38 , & V_85 ) ;
F_31 ( V_5 , & V_85 ) ;
}
static struct V_1 * F_32 ( struct V_40 * V_5 ,
int V_86 )
{
int V_87 = F_33 ( V_5 ) ;
int V_88 = V_5 -> V_89 ;
struct V_90 * V_91 = F_34 ( V_5 ) -> V_92 . V_93 ;
struct V_1 * V_2 ;
V_2 = F_35 ( V_87 + sizeof( struct V_94 ) + V_86 + V_88 , V_95 ) ;
if ( ! V_2 ) {
F_9 ( 0 , V_96 , L_3 ,
V_28 ) ;
return NULL ;
}
V_2 -> V_97 = F_36 ( V_98 ) ;
V_2 -> V_5 = V_5 ;
F_37 ( V_2 , V_87 + sizeof( struct V_94 ) ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 , V_91 ) ;
return V_2 ;
}
static void F_40 ( struct V_1 * V_2 ,
const struct V_37 * V_99 ,
const struct V_37 * V_100 ,
int V_101 , int V_86 )
{
struct V_94 * V_102 ;
F_41 ( V_2 , sizeof( * V_102 ) ) ;
F_42 ( V_2 ) ;
V_102 = F_43 ( V_2 ) ;
F_44 ( V_102 , 0 , 0 ) ;
V_102 -> V_103 = F_36 ( V_86 ) ;
V_102 -> V_104 = V_105 ;
V_102 -> V_101 = V_101 ;
V_102 -> V_99 = * V_99 ;
V_102 -> V_100 = * V_100 ;
}
static void F_45 ( struct V_1 * V_2 ,
const struct V_37 * V_100 ,
const struct V_37 * V_99 )
{
struct V_106 * V_107 = F_46 ( V_2 ) ;
struct V_108 * V_108 = F_34 ( V_2 -> V_5 ) ;
struct V_90 * V_91 = V_108 -> V_92 . V_93 ;
struct V_56 * V_109 ;
int V_96 ;
struct V_110 * V_111 = F_47 ( V_2 ) ;
T_1 type ;
type = V_111 -> V_112 ;
if ( ! V_107 ) {
struct V_113 V_114 ;
int V_115 = F_48 ( V_2 -> V_5 ) ;
F_49 ( V_91 , & V_114 , type , V_99 , V_100 , V_115 ) ;
if ( V_115 != V_2 -> V_5 -> V_116 )
V_114 . V_117 |= V_118 ;
V_107 = F_50 ( V_2 -> V_5 , & V_114 ) ;
if ( F_51 ( V_107 ) ) {
F_52 ( V_2 ) ;
return;
}
F_53 ( V_2 , V_107 ) ;
}
V_111 -> V_119 = F_54 ( V_99 , V_100 , V_2 -> V_86 ,
V_105 ,
F_55 ( V_111 ,
V_2 -> V_86 , 0 ) ) ;
F_40 ( V_2 , V_99 , V_100 , F_56 ( V_91 ) -> V_101 , V_2 -> V_86 ) ;
F_57 () ;
V_109 = F_27 ( V_107 -> V_5 ) ;
F_58 ( V_108 , V_109 , V_120 , V_2 -> V_86 ) ;
V_96 = F_59 ( V_121 , V_122 ,
V_108 , V_91 , V_2 , NULL , V_107 -> V_5 ,
V_123 ) ;
if ( ! V_96 ) {
F_60 ( V_108 , V_109 , type ) ;
F_61 ( V_108 , V_109 , V_124 ) ;
}
F_62 () ;
}
void F_63 ( struct V_40 * V_5 , const struct V_37 * V_100 ,
const struct V_37 * V_125 ,
bool V_126 , bool V_127 , bool V_128 , bool V_129 )
{
struct V_1 * V_2 ;
struct V_37 V_130 ;
struct V_131 * V_132 ;
const struct V_37 * V_133 ;
struct V_134 * V_135 ;
int V_136 = 0 ;
V_132 = F_64 ( F_34 ( V_5 ) , V_125 , V_5 , 1 ) ;
if ( V_132 ) {
V_133 = V_125 ;
if ( V_132 -> V_72 & V_137 )
V_128 = false ;
V_129 |= V_132 -> V_109 -> V_138 . V_139 ;
F_65 ( V_132 ) ;
} else {
if ( F_66 ( F_34 ( V_5 ) , V_5 , V_100 ,
F_56 ( F_34 ( V_5 ) -> V_92 . V_93 ) -> V_140 ,
& V_130 ) )
return;
V_133 = & V_130 ;
}
if ( ! V_5 -> V_7 )
V_129 = 0 ;
if ( V_129 )
V_136 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_135 ) + V_136 ) ;
if ( ! V_2 )
return;
V_135 = (struct V_134 * ) F_4 ( V_2 , sizeof( * V_135 ) ) ;
* V_135 = (struct V_134 ) {
. V_141 = {
. V_112 = V_142 ,
. V_143 = V_126 ,
. V_144 = V_127 ,
. V_145 = V_128 ,
} ,
. V_146 = * V_125 ,
} ;
if ( V_129 )
F_1 ( V_2 , V_23 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_133 ) ;
}
static void F_67 ( struct V_40 * V_5 )
{
struct V_56 * V_109 ;
struct V_131 * V_147 ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 )
return;
F_68 ( & V_109 -> V_148 ) ;
F_69 (ifa, &idev->addr_list, if_list) {
F_63 ( V_5 , & V_149 , & V_147 -> V_38 ,
! ! V_109 -> V_138 . V_150 ,
false , true ,
true ) ;
}
F_70 ( & V_109 -> V_148 ) ;
F_25 ( V_109 ) ;
}
void F_71 ( struct V_40 * V_5 , const struct V_37 * V_151 ,
const struct V_37 * V_100 , const struct V_37 * V_99 )
{
struct V_1 * V_2 ;
struct V_37 V_152 ;
int V_129 = V_5 -> V_7 ;
int V_136 = 0 ;
struct V_134 * V_135 ;
if ( ! V_99 ) {
if ( F_72 ( V_5 , & V_152 ,
( V_153 | V_137 ) ) )
return;
V_99 = & V_152 ;
}
if ( F_73 ( V_99 ) )
V_129 = false ;
if ( V_129 )
V_136 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_135 ) + V_136 ) ;
if ( ! V_2 )
return;
V_135 = (struct V_134 * ) F_4 ( V_2 , sizeof( * V_135 ) ) ;
* V_135 = (struct V_134 ) {
. V_141 = {
. V_112 = V_154 ,
} ,
. V_146 = * V_151 ,
} ;
if ( V_129 )
F_1 ( V_2 , V_22 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_99 ) ;
}
void F_74 ( struct V_40 * V_5 , const struct V_37 * V_99 ,
const struct V_37 * V_100 )
{
struct V_1 * V_2 ;
struct V_155 * V_135 ;
int V_156 = V_5 -> V_7 ;
int V_136 = 0 ;
#ifdef F_75
if ( V_156 ) {
struct V_131 * V_132 = F_64 ( F_34 ( V_5 ) , V_99 ,
V_5 , 1 ) ;
if ( V_132 ) {
if ( V_132 -> V_72 & V_137 ) {
V_156 = 0 ;
}
F_65 ( V_132 ) ;
} else {
V_156 = 0 ;
}
}
#endif
if ( V_156 )
V_136 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_135 ) + V_136 ) ;
if ( ! V_2 )
return;
V_135 = (struct V_155 * ) F_4 ( V_2 , sizeof( * V_135 ) ) ;
* V_135 = (struct V_155 ) {
. V_141 = {
. V_112 = V_157 ,
} ,
} ;
if ( V_156 )
F_1 ( V_2 , V_22 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_99 ) ;
}
static void F_76 ( struct V_52 * V_54 , struct V_1 * V_2 )
{
F_77 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static void F_78 ( struct V_52 * V_54 , struct V_1 * V_2 )
{
struct V_37 * V_99 = NULL ;
struct V_37 V_158 ;
struct V_40 * V_5 = V_54 -> V_5 ;
struct V_37 * V_146 = (struct V_37 * ) & V_54 -> V_55 ;
int V_159 = F_79 ( & V_54 -> V_159 ) ;
if ( V_2 && F_80 ( F_34 ( V_5 ) , & F_43 ( V_2 ) -> V_99 ,
V_5 , 1 ,
V_153 | V_137 ) )
V_99 = & F_43 ( V_2 ) -> V_99 ;
V_159 -= F_81 ( V_54 -> V_59 , V_160 ) ;
if ( V_159 < 0 ) {
if ( ! ( V_54 -> V_65 & V_81 ) ) {
F_9 ( 1 , V_161 ,
L_4 ,
V_28 , V_146 ) ;
}
F_71 ( V_5 , V_146 , V_146 , V_99 ) ;
} else if ( ( V_159 -= F_81 ( V_54 -> V_59 , V_162 ) ) < 0 ) {
F_82 ( V_54 ) ;
} else {
F_28 ( V_146 , & V_158 ) ;
F_71 ( V_5 , V_146 , & V_158 , V_99 ) ;
}
}
static int F_83 ( const void * V_50 ,
struct V_40 * V_5 )
{
struct V_83 * V_53 ;
int V_163 = - 1 ;
F_68 ( & V_164 . V_148 ) ;
V_53 = F_84 ( & V_164 , F_34 ( V_5 ) , V_50 , V_5 ) ;
if ( V_53 )
V_163 = ! ! ( V_53 -> V_72 & V_165 ) ;
F_70 ( & V_164 . V_148 ) ;
return V_163 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = (struct V_134 * ) F_86 ( V_2 ) ;
const struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_166 = NULL ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_134 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_131 * V_132 ;
struct V_56 * V_109 = NULL ;
struct V_52 * V_54 ;
int V_168 = F_73 ( V_99 ) ;
bool V_169 ;
int V_170 = - 1 ;
if ( V_2 -> V_86 < sizeof( struct V_134 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( F_21 ( & V_135 -> V_146 ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( V_168 && ! F_89 ( V_100 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( ! F_8 ( V_135 -> V_9 , V_167 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_8 ) ;
return;
}
if ( V_19 . V_171 ) {
V_166 = F_90 ( V_19 . V_171 , V_5 ) ;
if ( ! V_166 ) {
F_9 ( 2 , V_27 ,
L_9 ) ;
return;
}
if ( V_168 ) {
F_9 ( 2 , V_27 ,
L_10 ) ;
return;
}
}
V_169 = F_21 ( V_100 ) ;
V_132 = F_64 ( F_34 ( V_5 ) , & V_135 -> V_146 , V_5 , 1 ) ;
if ( V_132 ) {
V_172:
if ( V_132 -> V_72 & ( V_153 | V_137 ) ) {
if ( V_168 ) {
F_91 ( V_132 ) ;
return;
} else {
if ( ! ( V_132 -> V_72 & V_137 ) )
goto V_173;
}
}
V_109 = V_132 -> V_109 ;
} else {
struct V_108 * V_108 = F_34 ( V_5 ) ;
if ( F_92 ( V_5 ) ) {
struct V_40 * V_174 ;
V_174 = F_93 ( V_5 ) ;
if ( V_174 ) {
V_132 = F_64 ( V_108 , & V_135 -> V_146 , V_174 , 1 ) ;
if ( V_132 )
goto V_172;
}
}
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 ) {
return;
}
if ( F_94 ( V_108 , V_5 , & V_135 -> V_146 ) ||
( V_109 -> V_138 . V_150 &&
( V_108 -> V_92 . V_175 -> V_176 || V_109 -> V_138 . V_176 ) &&
( V_170 = F_83 ( & V_135 -> V_146 , V_5 ) ) >= 0 ) ) {
if ( ! ( F_95 ( V_2 ) -> V_72 & V_177 ) &&
V_2 -> V_178 != V_179 &&
V_169 &&
F_81 ( V_109 -> V_61 , V_180 ) != 0 ) {
struct V_1 * V_53 = F_96 ( V_2 , V_95 ) ;
if ( V_53 )
F_97 ( & V_164 , V_109 -> V_61 , V_53 ) ;
goto V_173;
}
} else
goto V_173;
}
if ( V_170 < 0 )
V_170 = V_109 -> V_138 . V_150 ;
if ( V_168 ) {
F_63 ( V_5 , & V_149 , & V_135 -> V_146 ,
! ! V_170 , false , ( V_132 != NULL ) , true ) ;
goto V_173;
}
if ( V_169 )
F_98 ( & V_164 , V_181 ) ;
else
F_98 ( & V_164 , V_182 ) ;
V_54 = F_99 ( & V_164 , V_99 , V_5 ,
! V_169 || V_166 || ! V_5 -> V_7 ) ;
if ( V_54 )
F_100 ( V_54 , V_166 , V_183 ,
V_184 |
V_185 ) ;
if ( V_54 || ! V_5 -> V_64 ) {
F_63 ( V_5 , V_99 , & V_135 -> V_146 , ! ! V_170 ,
true , ( V_132 != NULL && V_169 ) , V_169 ) ;
if ( V_54 )
F_101 ( V_54 ) ;
}
V_173:
if ( V_132 )
F_65 ( V_132 ) ;
else
F_25 ( V_109 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = (struct V_134 * ) F_86 ( V_2 ) ;
struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_166 = NULL ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_134 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_56 * V_109 = F_27 ( V_5 ) ;
struct V_131 * V_132 ;
struct V_52 * V_54 ;
if ( V_2 -> V_86 < sizeof( struct V_134 ) ) {
F_9 ( 2 , V_27 , L_11 ) ;
return;
}
if ( F_21 ( & V_135 -> V_146 ) ) {
F_9 ( 2 , V_27 , L_12 ) ;
return;
}
if ( F_21 ( V_100 ) &&
V_135 -> V_141 . V_144 ) {
F_9 ( 2 , V_27 , L_13 ) ;
return;
}
if ( ! V_135 -> V_141 . V_144 && V_109 &&
V_109 -> V_138 . V_186 )
return;
if ( ! F_8 ( V_135 -> V_9 , V_167 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_14 ) ;
return;
}
if ( V_19 . V_187 ) {
V_166 = F_90 ( V_19 . V_187 , V_5 ) ;
if ( ! V_166 ) {
F_9 ( 2 , V_27 ,
L_15 ) ;
return;
}
}
V_132 = F_64 ( F_34 ( V_5 ) , & V_135 -> V_146 , V_5 , 1 ) ;
if ( V_132 ) {
if ( V_2 -> V_178 != V_188
&& ( V_132 -> V_72 & V_153 ) ) {
F_91 ( V_132 ) ;
return;
}
if ( V_2 -> V_178 != V_188 )
F_9 ( 1 , V_27 ,
L_16 ,
& V_132 -> V_38 , V_132 -> V_109 -> V_5 -> V_189 ) ;
F_65 ( V_132 ) ;
return;
}
V_54 = F_103 ( & V_164 , & V_135 -> V_146 , V_5 ) ;
if ( V_54 ) {
T_1 V_190 = V_54 -> V_72 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
if ( V_54 -> V_65 & V_191 )
goto V_173;
if ( V_166 && ! memcmp ( V_166 , V_5 -> V_75 , V_5 -> V_7 ) &&
V_108 -> V_92 . V_175 -> V_150 && V_108 -> V_92 . V_175 -> V_176 &&
F_104 ( & V_164 , V_108 , & V_135 -> V_146 , V_5 , 0 ) ) {
goto V_173;
}
F_100 ( V_54 , V_166 ,
V_135 -> V_141 . V_144 ? V_192 : V_183 ,
V_184 |
( V_135 -> V_141 . V_145 ? V_185 : 0 ) |
V_193 |
( V_135 -> V_141 . V_143 ? V_194 : 0 ) ) ;
if ( ( V_190 & ~ V_54 -> V_72 ) & V_165 ) {
F_105 ( F_34 ( V_5 ) , V_99 ) ;
}
V_173:
F_101 ( V_54 ) ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_155 * V_155 = (struct V_155 * ) F_86 ( V_2 ) ;
unsigned long V_167 = V_2 -> V_86 - sizeof( * V_155 ) ;
struct V_52 * V_54 ;
struct V_56 * V_109 ;
const struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
struct V_17 V_19 ;
T_1 * V_166 = NULL ;
if ( V_2 -> V_86 < sizeof( * V_155 ) )
return;
V_109 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_109 ) {
F_9 ( 1 , V_96 , L_17 ) ;
return;
}
if ( ! V_109 -> V_138 . V_150 )
goto V_173;
if ( F_73 ( V_99 ) )
goto V_173;
if ( ! F_8 ( V_155 -> V_9 , V_167 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_18 ) ;
goto V_173;
}
if ( V_19 . V_171 ) {
V_166 = F_90 ( V_19 . V_171 ,
V_2 -> V_5 ) ;
if ( ! V_166 )
goto V_173;
}
V_54 = F_99 ( & V_164 , V_99 , V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
F_100 ( V_54 , V_166 , V_183 ,
V_184 |
V_185 |
V_193 ) ;
F_101 ( V_54 ) ;
}
V_173:
return;
}
static void F_107 ( struct V_1 * V_195 , struct V_10 * V_9 )
{
struct V_110 * V_111 = (struct V_110 * ) F_86 ( V_195 ) ;
struct V_1 * V_2 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_108 * V_108 = F_34 ( V_195 -> V_5 ) ;
int V_96 ;
int V_200 = F_108 ( sizeof( struct V_198 )
+ ( V_9 -> V_14 << 3 ) ) ;
T_4 V_201 = V_200 + F_109 ( sizeof( struct V_37 ) ) ;
V_2 = F_110 ( V_201 , V_95 ) ;
if ( ! V_2 ) {
V_96 = - V_202 ;
goto V_203;
}
V_197 = F_111 ( V_2 , 0 , 0 , V_204 , V_200 , 0 ) ;
if ( ! V_197 ) {
goto V_205;
}
V_199 = F_112 ( V_197 ) ;
V_199 -> V_206 = V_207 ;
V_199 -> V_208 = V_195 -> V_5 -> V_116 ;
V_199 -> V_209 = V_111 -> V_112 ;
V_199 -> V_210 = V_111 -> V_211 ;
V_199 -> V_212 = V_9 -> V_14 << 3 ;
memcpy ( V_199 + 1 , V_9 , V_9 -> V_14 << 3 ) ;
if ( F_113 ( V_2 , V_213 , & F_43 ( V_195 ) -> V_99 ) )
goto V_205;
F_114 ( V_2 , V_197 ) ;
F_115 ( V_2 , V_108 , 0 , V_214 , NULL , V_95 ) ;
return;
V_205:
F_116 ( V_2 ) ;
V_96 = - V_215 ;
V_203:
F_117 ( V_108 , V_214 , V_96 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_216 * V_216 = (struct V_216 * ) F_86 ( V_2 ) ;
struct V_52 * V_54 = NULL ;
struct V_56 * V_57 ;
struct V_217 * V_218 = NULL ;
int V_219 ;
struct V_17 V_19 ;
int V_136 ;
unsigned int V_220 = 0 ;
T_3 V_221 ;
bool V_222 = false ;
T_5 * V_9 = ( T_5 * ) ( V_216 + 1 ) ;
V_136 = ( F_87 ( V_2 ) - F_86 ( V_2 ) ) -
sizeof( struct V_216 ) ;
F_9 ( 2 , V_223 ,
L_19 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
if ( ! ( F_119 ( & F_43 ( V_2 ) -> V_99 ) & V_224 ) ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
if ( V_136 < 0 ) {
F_9 ( 2 , V_27 , L_21 ) ;
return;
}
#ifdef F_120
if ( V_2 -> V_225 == V_226 ) {
F_9 ( 2 , V_27 , L_22 ) ;
return;
}
#endif
V_57 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_57 ) {
F_9 ( 0 , V_96 , L_23 ,
V_2 -> V_5 -> V_189 ) ;
return;
}
if ( ! F_8 ( V_9 , V_136 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_24 ) ;
return;
}
if ( ! F_121 ( V_57 ) ) {
F_9 ( 2 , V_223 ,
L_25 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
goto V_227;
}
#ifdef F_120
if ( V_2 -> V_225 == V_228 ) {
F_9 ( 2 , V_223 ,
L_26 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
goto V_227;
}
#endif
if ( V_57 -> V_229 & V_230 ) {
V_57 -> V_229 |= V_231 ;
}
V_221 = V_57 -> V_229 ;
V_57 -> V_229 = ( V_57 -> V_229 & ~ ( V_232 |
V_233 ) ) |
( V_216 -> V_141 . V_234 ?
V_232 : 0 ) |
( V_216 -> V_141 . V_235 ?
V_233 : 0 ) ;
if ( V_221 != V_57 -> V_229 )
V_222 = true ;
if ( ! V_57 -> V_138 . V_236 ) {
F_9 ( 2 , V_223 ,
L_27 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
goto V_237;
}
if ( ! V_57 -> V_138 . V_238 &&
F_122 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
V_57 -> V_5 , 0 ) ) {
F_9 ( 2 , V_223 ,
L_28 ,
V_2 -> V_5 -> V_189 ) ;
goto V_237;
}
V_219 = F_123 ( V_216 -> V_141 . V_239 ) ;
#ifdef F_124
V_220 = V_216 -> V_141 . V_240 ;
if ( V_220 == V_241 ||
! V_57 -> V_138 . V_242 )
V_220 = V_243 ;
#endif
V_218 = F_125 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 ) ;
if ( V_218 ) {
V_54 = F_126 ( & V_218 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_127 ( V_218 ) ;
return;
}
}
if ( V_218 && V_219 == 0 ) {
F_128 ( V_218 ) ;
V_218 = NULL ;
}
F_9 ( 3 , V_223 , L_30 ,
V_218 , V_219 , V_2 -> V_5 -> V_189 ) ;
if ( ! V_218 && V_219 ) {
F_9 ( 3 , V_223 , L_31 ) ;
V_218 = F_129 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 , V_220 ) ;
if ( ! V_218 ) {
F_9 ( 0 , V_96 ,
L_32 ,
V_28 ) ;
return;
}
V_54 = F_126 ( & V_218 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_127 ( V_218 ) ;
return;
}
V_54 -> V_72 |= V_165 ;
} else if ( V_218 ) {
V_218 -> V_244 = ( V_218 -> V_244 & ~ V_245 ) | F_130 ( V_220 ) ;
}
if ( V_218 )
F_131 ( V_218 , V_246 + ( V_247 * V_219 ) ) ;
if ( V_57 -> V_138 . V_248 < 256 &&
V_216 -> V_141 . V_249 ) {
if ( V_57 -> V_138 . V_248 <= V_216 -> V_141 . V_249 ) {
V_57 -> V_138 . V_101 = V_216 -> V_141 . V_249 ;
if ( V_218 )
F_132 ( & V_218 -> V_107 , V_250 ,
V_216 -> V_141 . V_249 ) ;
} else {
F_9 ( 2 , V_27 , L_33 ) ;
}
}
V_237:
if ( V_57 -> V_61 ) {
unsigned long V_251 = F_133 ( V_216 -> V_252 ) ;
if ( V_251 && V_251 / 1000 < V_253 / V_247 ) {
V_251 = ( V_251 * V_247 ) / 1000 ;
if ( V_251 < V_247 / 10 )
V_251 = V_247 / 10 ;
F_134 ( V_57 -> V_61 , V_254 , V_251 ) ;
V_57 -> V_255 = V_246 ;
V_222 = true ;
}
V_251 = F_133 ( V_216 -> V_256 ) ;
if ( V_251 && V_251 / 1000 < V_253 / ( 3 * V_247 ) ) {
V_251 = ( V_251 * V_247 ) / 1000 ;
if ( V_251 < V_247 / 10 )
V_251 = V_247 / 10 ;
if ( V_251 != F_81 ( V_57 -> V_61 , V_257 ) ) {
F_134 ( V_57 -> V_61 ,
V_257 , V_251 ) ;
F_134 ( V_57 -> V_61 ,
V_258 , 3 * V_251 ) ;
V_57 -> V_61 -> V_256 = F_135 ( V_251 ) ;
V_57 -> V_255 = V_246 ;
V_222 = true ;
}
}
}
if ( V_222 )
F_136 ( V_259 , V_57 ) ;
V_227:
if ( ! V_54 )
V_54 = F_99 ( & V_164 , & F_43 ( V_2 ) -> V_99 ,
V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
T_1 * V_166 = NULL ;
if ( V_19 . V_171 ) {
V_166 = F_90 ( V_19 . V_171 ,
V_2 -> V_5 ) ;
if ( ! V_166 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_173;
}
}
F_100 ( V_54 , V_166 , V_183 ,
V_184 |
V_185 |
V_193 |
V_194 ) ;
}
if ( ! F_121 ( V_57 ) ) {
F_9 ( 2 , V_223 ,
L_35 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
goto V_173;
}
#ifdef F_10
if ( ! V_57 -> V_138 . V_238 &&
F_122 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
V_57 -> V_5 , 0 ) ) {
F_9 ( 2 , V_223 ,
L_36 ,
V_2 -> V_5 -> V_189 ) ;
goto V_260;
}
if ( V_57 -> V_138 . V_242 && V_19 . V_33 ) {
struct V_10 * V_261 ;
for ( V_261 = V_19 . V_33 ;
V_261 ;
V_261 = F_5 ( V_261 , V_19 . V_32 ) ) {
struct V_262 * V_263 = (struct V_262 * ) V_261 ;
#ifdef F_120
if ( V_2 -> V_225 == V_228 &&
V_263 -> V_264 == 0 )
continue;
#endif
if ( V_263 -> V_264 == 0 &&
! V_57 -> V_138 . V_236 )
continue;
if ( V_263 -> V_264 > V_57 -> V_138 . V_265 )
continue;
F_137 ( V_2 -> V_5 , ( T_1 * ) V_261 , ( V_261 -> V_14 ) << 3 ,
& F_43 ( V_2 ) -> V_99 ) ;
}
}
V_260:
#endif
#ifdef F_120
if ( V_2 -> V_225 == V_228 ) {
F_9 ( 2 , V_223 ,
L_37 ,
V_28 , V_2 -> V_5 -> V_189 ) ;
goto V_173;
}
#endif
if ( V_57 -> V_138 . V_266 && V_19 . V_267 ) {
struct V_10 * V_261 ;
for ( V_261 = V_19 . V_267 ;
V_261 ;
V_261 = F_5 ( V_261 , V_19 . V_30 ) ) {
F_138 ( V_2 -> V_5 , ( T_1 * ) V_261 ,
( V_261 -> V_14 ) << 3 ,
V_19 . V_171 != NULL ) ;
}
}
if ( V_19 . V_268 && V_57 -> V_138 . V_269 ) {
T_6 V_53 ;
T_2 V_270 ;
memcpy ( & V_53 , ( ( T_1 * ) ( V_19 . V_268 + 1 ) ) + 2 , sizeof( V_270 ) ) ;
V_270 = F_133 ( V_53 ) ;
if ( V_270 < V_271 || V_270 > V_2 -> V_5 -> V_270 ) {
F_9 ( 2 , V_27 , L_38 , V_270 ) ;
} else if ( V_57 -> V_138 . V_272 != V_270 ) {
V_57 -> V_138 . V_272 = V_270 ;
if ( V_218 )
F_132 ( & V_218 -> V_107 , V_273 , V_270 ) ;
F_139 ( V_2 -> V_5 , V_270 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_261 ;
for ( V_261 = V_19 . V_35 ;
V_261 ;
V_261 = F_7 ( V_261 , V_19 . V_34 ) ) {
F_107 ( V_2 , V_261 ) ;
}
}
if ( V_19 . V_187 || V_19 . V_274 ) {
F_9 ( 2 , V_27 , L_39 ) ;
}
V_173:
F_127 ( V_218 ) ;
if ( V_54 )
F_101 ( V_54 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
T_1 * V_102 ;
struct V_17 V_19 ;
struct V_275 * V_135 = (struct V_275 * ) F_86 ( V_2 ) ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_275 , V_9 ) ) ;
#ifdef F_120
switch ( V_2 -> V_225 ) {
case V_226 :
case V_228 :
F_9 ( 2 , V_27 ,
L_40 ) ;
return;
}
#endif
if ( ! ( F_119 ( & F_43 ( V_2 ) -> V_99 ) & V_224 ) ) {
F_9 ( 2 , V_27 ,
L_41 ) ;
return;
}
if ( ! F_8 ( V_135 -> V_9 , V_167 , & V_19 ) )
return;
if ( ! V_19 . V_274 ) {
F_141 ( V_2 , F_34 ( V_2 -> V_5 ) ,
V_2 -> V_5 -> V_116 , 0 ) ;
return;
}
V_102 = ( T_1 * ) V_19 . V_274 ;
V_102 += 8 ;
if ( ! F_142 ( V_2 , V_102 - F_86 ( V_2 ) ) )
return;
F_143 ( V_2 , V_276 , 0 , 0 ) ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_1 * V_277 ,
int V_278 )
{
T_1 * V_9 = F_4 ( V_2 , V_278 ) ;
memset ( V_9 , 0 , 8 ) ;
* ( V_9 ++ ) = V_25 ;
* ( V_9 ++ ) = ( V_278 >> 3 ) ;
V_9 += 6 ;
memcpy ( V_9 , F_43 ( V_277 ) , V_278 - 8 ) ;
}
void F_145 ( struct V_1 * V_2 , const struct V_37 * V_146 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_90 * V_91 = V_108 -> V_92 . V_93 ;
int V_136 = 0 ;
struct V_279 * V_280 ;
struct V_1 * V_281 ;
struct V_275 * V_135 ;
struct V_37 V_282 ;
struct V_217 * V_218 ;
struct V_106 * V_107 ;
struct V_113 V_114 ;
int V_278 ;
T_1 V_283 [ V_284 ] , * V_71 = NULL ;
int V_115 = F_48 ( V_5 ) ;
bool V_163 ;
if ( F_72 ( V_5 , & V_282 , V_153 ) ) {
F_9 ( 2 , V_27 , L_42 ,
V_5 -> V_189 ) ;
return;
}
if ( ! F_146 ( & F_43 ( V_2 ) -> V_100 , V_146 ) &&
F_119 ( V_146 ) != ( V_285 | V_224 ) ) {
F_9 ( 2 , V_27 ,
L_43 ) ;
return;
}
F_49 ( V_91 , & V_114 , V_276 ,
& V_282 , & F_43 ( V_2 ) -> V_99 , V_115 ) ;
if ( V_115 != V_2 -> V_5 -> V_116 )
V_114 . V_117 |= V_118 ;
V_107 = F_147 ( V_108 , NULL , & V_114 ) ;
if ( V_107 -> error ) {
F_148 ( V_107 ) ;
return;
}
V_107 = F_149 ( V_108 , V_107 , F_150 ( & V_114 ) , NULL , 0 ) ;
if ( F_51 ( V_107 ) )
return;
V_218 = (struct V_217 * ) V_107 ;
if ( V_218 -> V_244 & V_286 ) {
F_9 ( 2 , V_27 ,
L_44 ) ;
goto V_287;
}
V_280 = F_151 ( V_108 -> V_92 . V_288 , & F_43 ( V_2 ) -> V_99 , 1 ) ;
V_163 = F_152 ( V_280 , 1 * V_247 ) ;
if ( V_280 )
F_153 ( V_280 ) ;
if ( ! V_163 )
goto V_287;
if ( V_5 -> V_7 ) {
struct V_52 * V_54 = F_126 ( F_46 ( V_2 ) , V_146 ) ;
if ( ! V_54 ) {
F_9 ( 2 , V_27 ,
L_45 ) ;
goto V_287;
}
F_68 ( & V_54 -> V_148 ) ;
if ( V_54 -> V_65 & V_81 ) {
memcpy ( V_283 , V_54 -> V_71 , V_5 -> V_7 ) ;
F_70 ( & V_54 -> V_148 ) ;
V_71 = V_283 ;
V_136 += F_3 ( V_5 ) ;
} else
F_70 ( & V_54 -> V_148 ) ;
F_101 ( V_54 ) ;
}
V_278 = F_154 (unsigned int,
IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(*msg) - optlen,
skb->len + 8 ) ;
V_278 &= ~ 0x7 ;
V_136 += V_278 ;
V_281 = F_32 ( V_5 , sizeof( * V_135 ) + V_136 ) ;
if ( ! V_281 )
goto V_287;
V_135 = (struct V_275 * ) F_4 ( V_281 , sizeof( * V_135 ) ) ;
* V_135 = (struct V_275 ) {
. V_141 = {
. V_112 = V_276 ,
} ,
. V_146 = * V_146 ,
. V_289 = F_43 ( V_2 ) -> V_100 ,
} ;
if ( V_71 )
F_1 ( V_281 , V_23 , V_71 ) ;
if ( V_278 )
F_144 ( V_281 , V_2 , V_278 ) ;
F_53 ( V_281 , V_107 ) ;
F_45 ( V_281 , & F_43 ( V_2 ) -> V_99 , & V_282 ) ;
return;
V_287:
F_148 ( V_107 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
F_85 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_56 * V_109 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_109 )
return true ;
if ( F_157 ( V_2 ) -> V_72 & V_290 &&
V_109 -> V_138 . V_291 ) {
F_158 ( L_46 ) ;
return true ;
}
return false ;
}
int F_159 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
if ( F_156 ( V_2 ) )
return 0 ;
if ( F_160 ( V_2 ) )
return 0 ;
V_135 = (struct V_134 * ) F_86 ( V_2 ) ;
F_161 ( V_2 , V_2 -> V_3 - F_86 ( V_2 ) ) ;
if ( F_43 ( V_2 ) -> V_101 != 255 ) {
F_9 ( 2 , V_27 , L_47 ,
F_43 ( V_2 ) -> V_101 ) ;
return 0 ;
}
if ( V_135 -> V_141 . V_211 != 0 ) {
F_9 ( 2 , V_27 , L_48 ,
V_135 -> V_141 . V_211 ) ;
return 0 ;
}
memset ( F_95 ( V_2 ) , 0 , sizeof( struct V_292 ) ) ;
switch ( V_135 -> V_141 . V_112 ) {
case V_154 :
F_85 ( V_2 ) ;
break;
case V_142 :
F_102 ( V_2 ) ;
break;
case V_157 :
F_106 ( V_2 ) ;
break;
case V_293 :
F_118 ( V_2 ) ;
break;
case V_276 :
F_140 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_162 ( struct V_294 * V_295 , unsigned long V_296 , void * V_297 )
{
struct V_40 * V_5 = F_163 ( V_297 ) ;
struct V_298 * V_299 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_56 * V_109 ;
switch ( V_296 ) {
case V_300 :
F_164 ( & V_164 , V_5 ) ;
F_165 ( 0 , V_108 , false ) ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 )
break;
if ( V_109 -> V_138 . V_301 )
F_67 ( V_5 ) ;
F_25 ( V_109 ) ;
break;
case V_302 :
V_299 = V_297 ;
if ( V_299 -> V_303 & V_73 )
F_164 ( & V_164 , V_5 ) ;
break;
case V_304 :
F_166 ( & V_164 , V_5 ) ;
F_165 ( 0 , V_108 , false ) ;
break;
case V_305 :
F_67 ( V_5 ) ;
break;
default:
break;
}
return V_306 ;
}
static void F_167 ( struct V_307 * V_308 ,
const char * V_309 , const char * V_310 )
{
static char V_311 [ V_312 ] ;
static int V_313 ;
if ( strcmp ( V_311 , V_314 -> V_315 ) && V_313 < 5 ) {
strcpy ( V_311 , V_314 -> V_315 ) ;
F_168 ( L_49 ,
V_311 , V_309 ,
V_310 , V_308 -> V_316 ,
V_310 , V_308 -> V_316 ) ;
V_313 ++ ;
}
}
int F_169 ( struct V_307 * V_308 , int V_317 , void T_7 * V_318 , T_4 * V_319 , T_8 * V_320 )
{
struct V_40 * V_5 = V_308 -> V_321 ;
struct V_56 * V_109 ;
int V_163 ;
if ( ( strcmp ( V_308 -> V_316 , L_50 ) == 0 ) ||
( strcmp ( V_308 -> V_316 , L_51 ) == 0 ) )
F_167 ( V_308 , L_52 , V_5 ? V_5 -> V_189 : L_53 ) ;
if ( strcmp ( V_308 -> V_316 , L_50 ) == 0 )
V_163 = F_170 ( V_308 , V_317 , V_318 , V_319 , V_320 ) ;
else if ( strcmp ( V_308 -> V_316 , L_51 ) == 0 )
V_163 = F_171 ( V_308 , V_317 ,
V_318 , V_319 , V_320 ) ;
else if ( ( strcmp ( V_308 -> V_316 , L_54 ) == 0 ) ||
( strcmp ( V_308 -> V_316 , L_55 ) == 0 ) )
V_163 = F_172 ( V_308 , V_317 ,
V_318 , V_319 , V_320 ) ;
else
V_163 = - 1 ;
if ( V_317 && V_163 == 0 && V_5 && ( V_109 = F_22 ( V_5 ) ) != NULL ) {
if ( V_308 -> V_3 == & F_81 ( V_109 -> V_61 , V_257 ) )
V_109 -> V_61 -> V_256 =
F_135 ( F_81 ( V_109 -> V_61 , V_257 ) ) ;
V_109 -> V_255 = V_246 ;
F_136 ( V_259 , V_109 ) ;
F_25 ( V_109 ) ;
}
return V_163 ;
}
static int T_9 F_173 ( struct V_108 * V_108 )
{
struct V_322 * V_323 ;
struct V_90 * V_91 ;
int V_96 ;
V_96 = F_174 ( & V_91 , V_324 ,
V_325 , V_105 , V_108 ) ;
if ( V_96 < 0 ) {
F_9 ( 0 , V_96 ,
L_56 ,
V_96 ) ;
return V_96 ;
}
V_108 -> V_92 . V_93 = V_91 ;
V_323 = F_56 ( V_91 ) ;
V_323 -> V_101 = 255 ;
V_323 -> V_326 = 0 ;
return 0 ;
}
static void T_10 F_175 ( struct V_108 * V_108 )
{
F_176 ( V_108 -> V_92 . V_93 ) ;
}
int T_11 F_177 ( void )
{
int V_96 ;
V_96 = F_178 ( & V_327 ) ;
if ( V_96 )
return V_96 ;
F_179 ( V_328 , & V_164 ) ;
#ifdef F_180
V_96 = F_181 ( NULL , & V_164 . V_59 ,
F_169 ) ;
if ( V_96 )
goto V_329;
V_173:
#endif
return V_96 ;
#ifdef F_180
V_329:
F_182 ( & V_327 ) ;
goto V_173;
#endif
}
int T_11 F_183 ( void )
{
return F_184 ( & V_330 ) ;
}
void F_185 ( void )
{
F_186 ( & V_330 ) ;
}
void F_187 ( void )
{
#ifdef F_180
F_188 ( & V_164 . V_59 ) ;
#endif
F_189 ( V_328 , & V_164 ) ;
F_182 ( & V_327 ) ;
}
