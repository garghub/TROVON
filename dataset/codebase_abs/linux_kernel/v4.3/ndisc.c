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
F_48 ( V_91 , & V_114 , type , V_99 , V_100 , V_2 -> V_5 -> V_115 ) ;
V_107 = F_49 ( V_2 -> V_5 , & V_114 ) ;
if ( F_50 ( V_107 ) ) {
F_51 ( V_2 ) ;
return;
}
F_52 ( V_2 , V_107 ) ;
}
V_111 -> V_116 = F_53 ( V_99 , V_100 , V_2 -> V_86 ,
V_105 ,
F_54 ( V_111 ,
V_2 -> V_86 , 0 ) ) ;
F_40 ( V_2 , V_99 , V_100 , F_55 ( V_91 ) -> V_101 , V_2 -> V_86 ) ;
F_56 () ;
V_109 = F_27 ( V_107 -> V_5 ) ;
F_57 ( V_108 , V_109 , V_117 , V_2 -> V_86 ) ;
V_96 = F_58 ( V_118 , V_119 , V_91 , V_2 ,
NULL , V_107 -> V_5 ,
V_120 ) ;
if ( ! V_96 ) {
F_59 ( V_108 , V_109 , type ) ;
F_60 ( V_108 , V_109 , V_121 ) ;
}
F_61 () ;
}
void F_62 ( struct V_40 * V_5 , struct V_52 * V_54 ,
const struct V_37 * V_100 ,
const struct V_37 * V_122 ,
bool V_123 , bool V_124 , bool V_125 , bool V_126 )
{
struct V_1 * V_2 ;
struct V_37 V_127 ;
struct V_128 * V_129 ;
const struct V_37 * V_130 ;
struct V_131 * V_132 ;
int V_133 = 0 ;
V_129 = F_63 ( F_34 ( V_5 ) , V_122 , V_5 , 1 ) ;
if ( V_129 ) {
V_130 = V_122 ;
if ( V_129 -> V_72 & V_134 )
V_125 = false ;
V_126 |= V_129 -> V_109 -> V_135 . V_136 ;
F_64 ( V_129 ) ;
} else {
if ( F_65 ( F_34 ( V_5 ) , V_5 , V_100 ,
F_55 ( F_34 ( V_5 ) -> V_92 . V_93 ) -> V_137 ,
& V_127 ) )
return;
V_130 = & V_127 ;
}
if ( ! V_5 -> V_7 )
V_126 = 0 ;
if ( V_126 )
V_133 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_2 )
return;
V_132 = (struct V_131 * ) F_4 ( V_2 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_131 ) {
. V_138 = {
. V_112 = V_139 ,
. V_140 = V_123 ,
. V_141 = V_124 ,
. V_142 = V_125 ,
} ,
. V_143 = * V_122 ,
} ;
if ( V_126 )
F_1 ( V_2 , V_23 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_130 ) ;
}
static void F_66 ( struct V_40 * V_5 )
{
struct V_56 * V_109 ;
struct V_128 * V_144 ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 )
return;
F_67 ( & V_109 -> V_145 ) ;
F_68 (ifa, &idev->addr_list, if_list) {
F_62 ( V_5 , NULL , & V_146 , & V_144 -> V_38 ,
! ! V_109 -> V_135 . V_147 ,
false , true ,
true ) ;
}
F_69 ( & V_109 -> V_145 ) ;
F_25 ( V_109 ) ;
}
void F_70 ( struct V_40 * V_5 , struct V_52 * V_54 ,
const struct V_37 * V_148 ,
const struct V_37 * V_100 , const struct V_37 * V_99 ,
struct V_1 * V_149 )
{
struct V_1 * V_2 ;
struct V_37 V_150 ;
int V_126 = V_5 -> V_7 ;
int V_133 = 0 ;
struct V_131 * V_132 ;
if ( ! V_99 ) {
if ( F_71 ( V_5 , & V_150 ,
( V_151 | V_134 ) ) )
return;
V_99 = & V_150 ;
}
if ( F_72 ( V_99 ) )
V_126 = false ;
if ( V_126 )
V_133 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_2 )
return;
V_132 = (struct V_131 * ) F_4 ( V_2 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_131 ) {
. V_138 = {
. V_112 = V_152 ,
} ,
. V_143 = * V_148 ,
} ;
if ( V_126 )
F_1 ( V_2 , V_22 ,
V_5 -> V_75 ) ;
if ( ! ( V_5 -> V_153 & V_154 ) && V_149 )
F_73 ( V_2 , V_149 ) ;
F_45 ( V_2 , V_100 , V_99 ) ;
}
void F_74 ( struct V_40 * V_5 , const struct V_37 * V_99 ,
const struct V_37 * V_100 )
{
struct V_1 * V_2 ;
struct V_155 * V_132 ;
int V_156 = V_5 -> V_7 ;
int V_133 = 0 ;
#ifdef F_75
if ( V_156 ) {
struct V_128 * V_129 = F_63 ( F_34 ( V_5 ) , V_99 ,
V_5 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_72 & V_134 ) {
V_156 = 0 ;
}
F_64 ( V_129 ) ;
} else {
V_156 = 0 ;
}
}
#endif
if ( V_156 )
V_133 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_2 )
return;
V_132 = (struct V_155 * ) F_4 ( V_2 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_155 ) {
. V_138 = {
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
F_51 ( V_2 ) ;
}
static void F_78 ( struct V_52 * V_54 , struct V_1 * V_2 )
{
struct V_37 * V_99 = NULL ;
struct V_37 V_158 ;
struct V_40 * V_5 = V_54 -> V_5 ;
struct V_37 * V_143 = (struct V_37 * ) & V_54 -> V_55 ;
int V_159 = F_79 ( & V_54 -> V_159 ) ;
if ( V_2 && F_80 ( F_34 ( V_5 ) , & F_43 ( V_2 ) -> V_99 ,
V_5 , 1 ,
V_151 | V_134 ) )
V_99 = & F_43 ( V_2 ) -> V_99 ;
V_159 -= F_81 ( V_54 -> V_59 , V_160 ) ;
if ( V_159 < 0 ) {
if ( ! ( V_54 -> V_65 & V_81 ) ) {
F_9 ( 1 , V_161 ,
L_4 ,
V_28 , V_143 ) ;
}
F_70 ( V_5 , V_54 , V_143 , V_143 , V_99 , V_2 ) ;
} else if ( ( V_159 -= F_81 ( V_54 -> V_59 , V_162 ) ) < 0 ) {
F_82 ( V_54 ) ;
} else {
F_28 ( V_143 , & V_158 ) ;
F_70 ( V_5 , NULL , V_143 , & V_158 , V_99 , V_2 ) ;
}
}
static int F_83 ( const void * V_50 ,
struct V_40 * V_5 )
{
struct V_83 * V_53 ;
int V_163 = - 1 ;
F_67 ( & V_164 . V_145 ) ;
V_53 = F_84 ( & V_164 , F_34 ( V_5 ) , V_50 , V_5 ) ;
if ( V_53 )
V_163 = ! ! ( V_53 -> V_72 & V_165 ) ;
F_69 ( & V_164 . V_145 ) ;
return V_163 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = (struct V_131 * ) F_86 ( V_2 ) ;
const struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_166 = NULL ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_131 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_128 * V_129 ;
struct V_56 * V_109 = NULL ;
struct V_52 * V_54 ;
int V_168 = F_72 ( V_99 ) ;
bool V_169 ;
int V_170 = - 1 ;
if ( V_2 -> V_86 < sizeof( struct V_131 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( F_21 ( & V_132 -> V_143 ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( V_168 && ! F_89 ( V_100 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( ! F_8 ( V_132 -> V_9 , V_167 , & V_19 ) ) {
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
V_129 = F_63 ( F_34 ( V_5 ) , & V_132 -> V_143 , V_5 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_72 & ( V_151 | V_134 ) ) {
if ( V_168 ) {
F_91 ( V_129 ) ;
return;
} else {
if ( ! ( V_129 -> V_72 & V_134 ) )
goto V_172;
}
}
V_109 = V_129 -> V_109 ;
} else {
struct V_108 * V_108 = F_34 ( V_5 ) ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 ) {
return;
}
if ( F_92 ( V_108 , V_5 , & V_132 -> V_143 ) ||
( V_109 -> V_135 . V_147 &&
( V_108 -> V_92 . V_173 -> V_174 || V_109 -> V_135 . V_174 ) &&
( V_170 = F_83 ( & V_132 -> V_143 , V_5 ) ) >= 0 ) ) {
if ( ! ( F_93 ( V_2 ) -> V_72 & V_175 ) &&
V_2 -> V_176 != V_177 &&
V_169 &&
F_81 ( V_109 -> V_61 , V_178 ) != 0 ) {
struct V_1 * V_53 = F_94 ( V_2 , V_95 ) ;
if ( V_53 )
F_95 ( & V_164 , V_109 -> V_61 , V_53 ) ;
goto V_172;
}
} else
goto V_172;
}
if ( V_170 < 0 )
V_170 = V_109 -> V_135 . V_147 ;
if ( V_168 ) {
F_62 ( V_5 , NULL , & V_146 , & V_132 -> V_143 ,
! ! V_170 , false , ( V_129 != NULL ) , true ) ;
goto V_172;
}
if ( V_169 )
F_96 ( & V_164 , V_179 ) ;
else
F_96 ( & V_164 , V_180 ) ;
V_54 = F_97 ( & V_164 , V_99 , V_5 ,
! V_169 || V_166 || ! V_5 -> V_7 ) ;
if ( V_54 )
F_98 ( V_54 , V_166 , V_181 ,
V_182 |
V_183 ) ;
if ( V_54 || ! V_5 -> V_64 ) {
F_62 ( V_5 , V_54 , V_99 , & V_132 -> V_143 ,
! ! V_170 ,
true , ( V_129 != NULL && V_169 ) , V_169 ) ;
if ( V_54 )
F_99 ( V_54 ) ;
}
V_172:
if ( V_129 )
F_64 ( V_129 ) ;
else
F_25 ( V_109 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = (struct V_131 * ) F_86 ( V_2 ) ;
struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_166 = NULL ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_131 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_128 * V_129 ;
struct V_52 * V_54 ;
if ( V_2 -> V_86 < sizeof( struct V_131 ) ) {
F_9 ( 2 , V_27 , L_11 ) ;
return;
}
if ( F_21 ( & V_132 -> V_143 ) ) {
F_9 ( 2 , V_27 , L_12 ) ;
return;
}
if ( F_21 ( V_100 ) &&
V_132 -> V_138 . V_141 ) {
F_9 ( 2 , V_27 , L_13 ) ;
return;
}
if ( ! F_8 ( V_132 -> V_9 , V_167 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_14 ) ;
return;
}
if ( V_19 . V_184 ) {
V_166 = F_90 ( V_19 . V_184 , V_5 ) ;
if ( ! V_166 ) {
F_9 ( 2 , V_27 ,
L_15 ) ;
return;
}
}
V_129 = F_63 ( F_34 ( V_5 ) , & V_132 -> V_143 , V_5 , 1 ) ;
if ( V_129 ) {
if ( V_2 -> V_176 != V_185
&& ( V_129 -> V_72 & V_151 ) ) {
F_91 ( V_129 ) ;
return;
}
if ( V_2 -> V_176 != V_185 )
F_9 ( 1 , V_27 ,
L_16 ,
& V_129 -> V_38 , V_129 -> V_109 -> V_5 -> V_186 ) ;
F_64 ( V_129 ) ;
return;
}
V_54 = F_101 ( & V_164 , & V_132 -> V_143 , V_5 ) ;
if ( V_54 ) {
T_1 V_187 = V_54 -> V_72 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
if ( V_54 -> V_65 & V_188 )
goto V_172;
if ( V_166 && ! memcmp ( V_166 , V_5 -> V_75 , V_5 -> V_7 ) &&
V_108 -> V_92 . V_173 -> V_147 && V_108 -> V_92 . V_173 -> V_174 &&
F_102 ( & V_164 , V_108 , & V_132 -> V_143 , V_5 , 0 ) ) {
goto V_172;
}
F_98 ( V_54 , V_166 ,
V_132 -> V_138 . V_141 ? V_189 : V_181 ,
V_182 |
( V_132 -> V_138 . V_142 ? V_183 : 0 ) |
V_190 |
( V_132 -> V_138 . V_140 ? V_191 : 0 ) ) ;
if ( ( V_187 & ~ V_54 -> V_72 ) & V_165 ) {
F_103 ( F_34 ( V_5 ) , V_99 ) ;
}
V_172:
F_99 ( V_54 ) ;
}
}
static void F_104 ( struct V_1 * V_2 )
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
if ( ! V_109 -> V_135 . V_147 )
goto V_172;
if ( F_72 ( V_99 ) )
goto V_172;
if ( ! F_8 ( V_155 -> V_9 , V_167 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_18 ) ;
goto V_172;
}
if ( V_19 . V_171 ) {
V_166 = F_90 ( V_19 . V_171 ,
V_2 -> V_5 ) ;
if ( ! V_166 )
goto V_172;
}
V_54 = F_97 ( & V_164 , V_99 , V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
F_98 ( V_54 , V_166 , V_181 ,
V_182 |
V_183 |
V_190 ) ;
F_99 ( V_54 ) ;
}
V_172:
return;
}
static void F_105 ( struct V_1 * V_192 , struct V_10 * V_9 )
{
struct V_110 * V_111 = (struct V_110 * ) F_86 ( V_192 ) ;
struct V_1 * V_2 ;
struct V_193 * V_194 ;
struct V_195 * V_196 ;
struct V_108 * V_108 = F_34 ( V_192 -> V_5 ) ;
int V_96 ;
int V_197 = F_106 ( sizeof( struct V_195 )
+ ( V_9 -> V_14 << 3 ) ) ;
T_4 V_198 = V_197 + F_107 ( sizeof( struct V_37 ) ) ;
V_2 = F_108 ( V_198 , V_95 ) ;
if ( ! V_2 ) {
V_96 = - V_199 ;
goto V_200;
}
V_194 = F_109 ( V_2 , 0 , 0 , V_201 , V_197 , 0 ) ;
if ( ! V_194 ) {
goto V_202;
}
V_196 = F_110 ( V_194 ) ;
V_196 -> V_203 = V_204 ;
V_196 -> V_205 = V_192 -> V_5 -> V_115 ;
V_196 -> V_206 = V_111 -> V_112 ;
V_196 -> V_207 = V_111 -> V_208 ;
V_196 -> V_209 = V_9 -> V_14 << 3 ;
memcpy ( V_196 + 1 , V_9 , V_9 -> V_14 << 3 ) ;
if ( F_111 ( V_2 , V_210 , & F_43 ( V_192 ) -> V_99 ) )
goto V_202;
F_112 ( V_2 , V_194 ) ;
F_113 ( V_2 , V_108 , 0 , V_211 , NULL , V_95 ) ;
return;
V_202:
F_114 ( V_2 ) ;
V_96 = - V_212 ;
V_200:
F_115 ( V_108 , V_211 , V_96 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_213 * V_213 = (struct V_213 * ) F_86 ( V_2 ) ;
struct V_52 * V_54 = NULL ;
struct V_56 * V_57 ;
struct V_214 * V_215 = NULL ;
int V_216 ;
struct V_17 V_19 ;
int V_133 ;
unsigned int V_217 = 0 ;
T_3 V_218 ;
bool V_219 = false ;
T_5 * V_9 = ( T_5 * ) ( V_213 + 1 ) ;
V_133 = ( F_87 ( V_2 ) - F_86 ( V_2 ) ) -
sizeof( struct V_213 ) ;
F_9 ( 2 , V_220 ,
L_19 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
if ( ! ( F_117 ( & F_43 ( V_2 ) -> V_99 ) & V_221 ) ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
if ( V_133 < 0 ) {
F_9 ( 2 , V_27 , L_21 ) ;
return;
}
#ifdef F_118
if ( V_2 -> V_222 == V_223 ) {
F_9 ( 2 , V_27 , L_22 ) ;
return;
}
#endif
V_57 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_57 ) {
F_9 ( 0 , V_96 , L_23 ,
V_2 -> V_5 -> V_186 ) ;
return;
}
if ( ! F_8 ( V_9 , V_133 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_24 ) ;
return;
}
if ( ! F_119 ( V_57 ) ) {
F_9 ( 2 , V_220 ,
L_25 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
goto V_224;
}
#ifdef F_118
if ( V_2 -> V_222 == V_225 ) {
F_9 ( 2 , V_220 ,
L_26 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
goto V_224;
}
#endif
if ( V_57 -> V_226 & V_227 ) {
V_57 -> V_226 |= V_228 ;
}
V_218 = V_57 -> V_226 ;
V_57 -> V_226 = ( V_57 -> V_226 & ~ ( V_229 |
V_230 ) ) |
( V_213 -> V_138 . V_231 ?
V_229 : 0 ) |
( V_213 -> V_138 . V_232 ?
V_230 : 0 ) ;
if ( V_218 != V_57 -> V_226 )
V_219 = true ;
if ( ! V_57 -> V_135 . V_233 ) {
F_9 ( 2 , V_220 ,
L_27 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
goto V_234;
}
if ( ! V_57 -> V_135 . V_235 &&
F_120 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
NULL , 0 ) ) {
F_9 ( 2 , V_220 ,
L_28 ,
V_2 -> V_5 -> V_186 ) ;
goto V_234;
}
V_216 = F_121 ( V_213 -> V_138 . V_236 ) ;
#ifdef F_122
V_217 = V_213 -> V_138 . V_237 ;
if ( V_217 == V_238 ||
! V_57 -> V_135 . V_239 )
V_217 = V_240 ;
#endif
V_215 = F_123 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 ) ;
if ( V_215 ) {
V_54 = F_124 ( & V_215 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_125 ( V_215 ) ;
return;
}
}
if ( V_215 && V_216 == 0 ) {
F_126 ( V_215 ) ;
V_215 = NULL ;
}
F_9 ( 3 , V_220 , L_30 ,
V_215 , V_216 , V_2 -> V_5 -> V_186 ) ;
if ( ! V_215 && V_216 ) {
F_9 ( 3 , V_220 , L_31 ) ;
V_215 = F_127 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 , V_217 ) ;
if ( ! V_215 ) {
F_9 ( 0 , V_96 ,
L_32 ,
V_28 ) ;
return;
}
V_54 = F_124 ( & V_215 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_125 ( V_215 ) ;
return;
}
V_54 -> V_72 |= V_165 ;
} else if ( V_215 ) {
V_215 -> V_241 = ( V_215 -> V_241 & ~ V_242 ) | F_128 ( V_217 ) ;
}
if ( V_215 )
F_129 ( V_215 , V_243 + ( V_244 * V_216 ) ) ;
if ( V_57 -> V_135 . V_245 < 256 &&
V_213 -> V_138 . V_246 ) {
if ( V_57 -> V_135 . V_245 <= V_213 -> V_138 . V_246 ) {
V_57 -> V_135 . V_101 = V_213 -> V_138 . V_246 ;
if ( V_215 )
F_130 ( & V_215 -> V_107 , V_247 ,
V_213 -> V_138 . V_246 ) ;
} else {
F_9 ( 2 , V_27 , L_33 ) ;
}
}
V_234:
if ( V_57 -> V_61 ) {
unsigned long V_248 = F_131 ( V_213 -> V_249 ) ;
if ( V_248 && V_248 / 1000 < V_250 / V_244 ) {
V_248 = ( V_248 * V_244 ) / 1000 ;
if ( V_248 < V_244 / 10 )
V_248 = V_244 / 10 ;
F_132 ( V_57 -> V_61 , V_251 , V_248 ) ;
V_57 -> V_252 = V_243 ;
V_219 = true ;
}
V_248 = F_131 ( V_213 -> V_253 ) ;
if ( V_248 && V_248 / 1000 < V_250 / ( 3 * V_244 ) ) {
V_248 = ( V_248 * V_244 ) / 1000 ;
if ( V_248 < V_244 / 10 )
V_248 = V_244 / 10 ;
if ( V_248 != F_81 ( V_57 -> V_61 , V_254 ) ) {
F_132 ( V_57 -> V_61 ,
V_254 , V_248 ) ;
F_132 ( V_57 -> V_61 ,
V_255 , 3 * V_248 ) ;
V_57 -> V_61 -> V_253 = F_133 ( V_248 ) ;
V_57 -> V_252 = V_243 ;
V_219 = true ;
}
}
}
if ( V_219 )
F_134 ( V_256 , V_57 ) ;
V_224:
if ( ! V_54 )
V_54 = F_97 ( & V_164 , & F_43 ( V_2 ) -> V_99 ,
V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
T_1 * V_166 = NULL ;
if ( V_19 . V_171 ) {
V_166 = F_90 ( V_19 . V_171 ,
V_2 -> V_5 ) ;
if ( ! V_166 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_172;
}
}
F_98 ( V_54 , V_166 , V_181 ,
V_182 |
V_183 |
V_190 |
V_191 ) ;
}
if ( ! F_119 ( V_57 ) ) {
F_9 ( 2 , V_220 ,
L_35 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
goto V_172;
}
#ifdef F_10
if ( ! V_57 -> V_135 . V_235 &&
F_120 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
NULL , 0 ) ) {
F_9 ( 2 , V_220 ,
L_36 ,
V_2 -> V_5 -> V_186 ) ;
goto V_257;
}
if ( V_57 -> V_135 . V_239 && V_19 . V_33 ) {
struct V_10 * V_258 ;
for ( V_258 = V_19 . V_33 ;
V_258 ;
V_258 = F_5 ( V_258 , V_19 . V_32 ) ) {
struct V_259 * V_260 = (struct V_259 * ) V_258 ;
#ifdef F_118
if ( V_2 -> V_222 == V_225 &&
V_260 -> V_261 == 0 )
continue;
#endif
if ( V_260 -> V_261 == 0 &&
! V_57 -> V_135 . V_233 )
continue;
if ( V_260 -> V_261 > V_57 -> V_135 . V_262 )
continue;
F_135 ( V_2 -> V_5 , ( T_1 * ) V_258 , ( V_258 -> V_14 ) << 3 ,
& F_43 ( V_2 ) -> V_99 ) ;
}
}
V_257:
#endif
#ifdef F_118
if ( V_2 -> V_222 == V_225 ) {
F_9 ( 2 , V_220 ,
L_37 ,
V_28 , V_2 -> V_5 -> V_186 ) ;
goto V_172;
}
#endif
if ( V_57 -> V_135 . V_263 && V_19 . V_264 ) {
struct V_10 * V_258 ;
for ( V_258 = V_19 . V_264 ;
V_258 ;
V_258 = F_5 ( V_258 , V_19 . V_30 ) ) {
F_136 ( V_2 -> V_5 , ( T_1 * ) V_258 ,
( V_258 -> V_14 ) << 3 ,
V_19 . V_171 != NULL ) ;
}
}
if ( V_19 . V_265 && V_57 -> V_135 . V_266 ) {
T_6 V_53 ;
T_2 V_267 ;
memcpy ( & V_53 , ( ( T_1 * ) ( V_19 . V_265 + 1 ) ) + 2 , sizeof( V_267 ) ) ;
V_267 = F_131 ( V_53 ) ;
if ( V_267 < V_268 || V_267 > V_2 -> V_5 -> V_267 ) {
F_9 ( 2 , V_27 , L_38 , V_267 ) ;
} else if ( V_57 -> V_135 . V_269 != V_267 ) {
V_57 -> V_135 . V_269 = V_267 ;
if ( V_215 )
F_130 ( & V_215 -> V_107 , V_270 , V_267 ) ;
F_137 ( V_2 -> V_5 , V_267 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_258 ;
for ( V_258 = V_19 . V_35 ;
V_258 ;
V_258 = F_7 ( V_258 , V_19 . V_34 ) ) {
F_105 ( V_2 , V_258 ) ;
}
}
if ( V_19 . V_184 || V_19 . V_271 ) {
F_9 ( 2 , V_27 , L_39 ) ;
}
V_172:
F_125 ( V_215 ) ;
if ( V_54 )
F_99 ( V_54 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
T_1 * V_102 ;
struct V_17 V_19 ;
struct V_272 * V_132 = (struct V_272 * ) F_86 ( V_2 ) ;
T_2 V_167 = F_87 ( V_2 ) - ( F_86 ( V_2 ) +
F_88 ( struct V_272 , V_9 ) ) ;
#ifdef F_118
switch ( V_2 -> V_222 ) {
case V_223 :
case V_225 :
F_9 ( 2 , V_27 ,
L_40 ) ;
return;
}
#endif
if ( ! ( F_117 ( & F_43 ( V_2 ) -> V_99 ) & V_221 ) ) {
F_9 ( 2 , V_27 ,
L_41 ) ;
return;
}
if ( ! F_8 ( V_132 -> V_9 , V_167 , & V_19 ) )
return;
if ( ! V_19 . V_271 ) {
F_139 ( V_2 , F_34 ( V_2 -> V_5 ) ,
V_2 -> V_5 -> V_115 , 0 ) ;
return;
}
V_102 = ( T_1 * ) V_19 . V_271 ;
V_102 += 8 ;
if ( ! F_140 ( V_2 , V_102 - F_86 ( V_2 ) ) )
return;
F_141 ( V_2 , V_273 , 0 , 0 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_1 * V_274 ,
int V_275 )
{
T_1 * V_9 = F_4 ( V_2 , V_275 ) ;
memset ( V_9 , 0 , 8 ) ;
* ( V_9 ++ ) = V_25 ;
* ( V_9 ++ ) = ( V_275 >> 3 ) ;
V_9 += 6 ;
memcpy ( V_9 , F_43 ( V_274 ) , V_275 - 8 ) ;
}
void F_143 ( struct V_1 * V_2 , const struct V_37 * V_143 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_90 * V_91 = V_108 -> V_92 . V_93 ;
int V_133 = 0 ;
struct V_276 * V_277 ;
struct V_1 * V_278 ;
struct V_272 * V_132 ;
struct V_37 V_279 ;
struct V_214 * V_215 ;
struct V_106 * V_107 ;
struct V_113 V_114 ;
int V_275 ;
T_1 V_280 [ V_281 ] , * V_71 = NULL ;
bool V_163 ;
if ( F_71 ( V_5 , & V_279 , V_151 ) ) {
F_9 ( 2 , V_27 , L_42 ,
V_5 -> V_186 ) ;
return;
}
if ( ! F_144 ( & F_43 ( V_2 ) -> V_100 , V_143 ) &&
F_117 ( V_143 ) != ( V_282 | V_221 ) ) {
F_9 ( 2 , V_27 ,
L_43 ) ;
return;
}
F_48 ( V_91 , & V_114 , V_273 ,
& V_279 , & F_43 ( V_2 ) -> V_99 , V_5 -> V_115 ) ;
V_107 = F_145 ( V_108 , NULL , & V_114 ) ;
if ( V_107 -> error ) {
F_146 ( V_107 ) ;
return;
}
V_107 = F_147 ( V_108 , V_107 , F_148 ( & V_114 ) , NULL , 0 ) ;
if ( F_50 ( V_107 ) )
return;
V_215 = (struct V_214 * ) V_107 ;
if ( V_215 -> V_241 & V_283 ) {
F_9 ( 2 , V_27 ,
L_44 ) ;
goto V_284;
}
V_277 = F_149 ( V_108 -> V_92 . V_285 , & F_43 ( V_2 ) -> V_99 , 1 ) ;
V_163 = F_150 ( V_277 , 1 * V_244 ) ;
if ( V_277 )
F_151 ( V_277 ) ;
if ( ! V_163 )
goto V_284;
if ( V_5 -> V_7 ) {
struct V_52 * V_54 = F_124 ( F_46 ( V_2 ) , V_143 ) ;
if ( ! V_54 ) {
F_9 ( 2 , V_27 ,
L_45 ) ;
goto V_284;
}
F_67 ( & V_54 -> V_145 ) ;
if ( V_54 -> V_65 & V_81 ) {
memcpy ( V_280 , V_54 -> V_71 , V_5 -> V_7 ) ;
F_69 ( & V_54 -> V_145 ) ;
V_71 = V_280 ;
V_133 += F_3 ( V_5 ) ;
} else
F_69 ( & V_54 -> V_145 ) ;
F_99 ( V_54 ) ;
}
V_275 = F_152 (unsigned int,
IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(*msg) - optlen,
skb->len + 8 ) ;
V_275 &= ~ 0x7 ;
V_133 += V_275 ;
V_278 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_278 )
goto V_284;
V_132 = (struct V_272 * ) F_4 ( V_278 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_272 ) {
. V_138 = {
. V_112 = V_273 ,
} ,
. V_143 = * V_143 ,
. V_286 = F_43 ( V_2 ) -> V_100 ,
} ;
if ( V_71 )
F_1 ( V_278 , V_23 , V_71 ) ;
if ( V_275 )
F_142 ( V_278 , V_2 , V_275 ) ;
F_52 ( V_278 , V_107 ) ;
F_45 ( V_278 , & F_43 ( V_2 ) -> V_99 , & V_279 ) ;
return;
V_284:
F_146 ( V_107 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
F_85 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static bool F_154 ( struct V_1 * V_2 )
{
struct V_56 * V_109 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_109 )
return true ;
if ( F_155 ( V_2 ) -> V_72 & V_287 &&
V_109 -> V_135 . V_288 ) {
F_156 ( L_46 ) ;
return true ;
}
return false ;
}
int F_157 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
if ( F_154 ( V_2 ) )
return 0 ;
if ( F_158 ( V_2 ) )
return 0 ;
V_132 = (struct V_131 * ) F_86 ( V_2 ) ;
F_159 ( V_2 , V_2 -> V_3 - F_86 ( V_2 ) ) ;
if ( F_43 ( V_2 ) -> V_101 != 255 ) {
F_9 ( 2 , V_27 , L_47 ,
F_43 ( V_2 ) -> V_101 ) ;
return 0 ;
}
if ( V_132 -> V_138 . V_208 != 0 ) {
F_9 ( 2 , V_27 , L_48 ,
V_132 -> V_138 . V_208 ) ;
return 0 ;
}
memset ( F_93 ( V_2 ) , 0 , sizeof( struct V_289 ) ) ;
switch ( V_132 -> V_138 . V_112 ) {
case V_152 :
F_85 ( V_2 ) ;
break;
case V_139 :
F_100 ( V_2 ) ;
break;
case V_157 :
F_104 ( V_2 ) ;
break;
case V_290 :
F_116 ( V_2 ) ;
break;
case V_273 :
F_138 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_160 ( struct V_291 * V_292 , unsigned long V_293 , void * V_294 )
{
struct V_40 * V_5 = F_161 ( V_294 ) ;
struct V_295 * V_296 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_56 * V_109 ;
switch ( V_293 ) {
case V_297 :
F_162 ( & V_164 , V_5 ) ;
F_163 ( 0 , V_108 , false ) ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 )
break;
if ( V_109 -> V_135 . V_298 )
F_66 ( V_5 ) ;
F_25 ( V_109 ) ;
break;
case V_299 :
V_296 = V_294 ;
if ( V_296 -> V_300 & V_73 )
F_162 ( & V_164 , V_5 ) ;
break;
case V_301 :
F_164 ( & V_164 , V_5 ) ;
F_163 ( 0 , V_108 , false ) ;
break;
case V_302 :
F_66 ( V_5 ) ;
break;
default:
break;
}
return V_303 ;
}
static void F_165 ( struct V_304 * V_305 ,
const char * V_306 , const char * V_307 )
{
static char V_308 [ V_309 ] ;
static int V_310 ;
if ( strcmp ( V_308 , V_311 -> V_312 ) && V_310 < 5 ) {
strcpy ( V_308 , V_311 -> V_312 ) ;
F_166 ( L_49 ,
V_308 , V_306 ,
V_307 , V_305 -> V_313 ,
V_307 , V_305 -> V_313 ) ;
V_310 ++ ;
}
}
int F_167 ( struct V_304 * V_305 , int V_314 , void T_7 * V_315 , T_4 * V_316 , T_8 * V_317 )
{
struct V_40 * V_5 = V_305 -> V_318 ;
struct V_56 * V_109 ;
int V_163 ;
if ( ( strcmp ( V_305 -> V_313 , L_50 ) == 0 ) ||
( strcmp ( V_305 -> V_313 , L_51 ) == 0 ) )
F_165 ( V_305 , L_52 , V_5 ? V_5 -> V_186 : L_53 ) ;
if ( strcmp ( V_305 -> V_313 , L_50 ) == 0 )
V_163 = F_168 ( V_305 , V_314 , V_315 , V_316 , V_317 ) ;
else if ( strcmp ( V_305 -> V_313 , L_51 ) == 0 )
V_163 = F_169 ( V_305 , V_314 ,
V_315 , V_316 , V_317 ) ;
else if ( ( strcmp ( V_305 -> V_313 , L_54 ) == 0 ) ||
( strcmp ( V_305 -> V_313 , L_55 ) == 0 ) )
V_163 = F_170 ( V_305 , V_314 ,
V_315 , V_316 , V_317 ) ;
else
V_163 = - 1 ;
if ( V_314 && V_163 == 0 && V_5 && ( V_109 = F_22 ( V_5 ) ) != NULL ) {
if ( V_305 -> V_3 == & F_81 ( V_109 -> V_61 , V_254 ) )
V_109 -> V_61 -> V_253 =
F_133 ( F_81 ( V_109 -> V_61 , V_254 ) ) ;
V_109 -> V_252 = V_243 ;
F_134 ( V_256 , V_109 ) ;
F_25 ( V_109 ) ;
}
return V_163 ;
}
static int T_9 F_171 ( struct V_108 * V_108 )
{
struct V_319 * V_320 ;
struct V_90 * V_91 ;
int V_96 ;
V_96 = F_172 ( & V_91 , V_321 ,
V_322 , V_105 , V_108 ) ;
if ( V_96 < 0 ) {
F_9 ( 0 , V_96 ,
L_56 ,
V_96 ) ;
return V_96 ;
}
V_108 -> V_92 . V_93 = V_91 ;
V_320 = F_55 ( V_91 ) ;
V_320 -> V_101 = 255 ;
V_320 -> V_323 = 0 ;
return 0 ;
}
static void T_10 F_173 ( struct V_108 * V_108 )
{
F_174 ( V_108 -> V_92 . V_93 ) ;
}
int T_11 F_175 ( void )
{
int V_96 ;
V_96 = F_176 ( & V_324 ) ;
if ( V_96 )
return V_96 ;
F_177 ( V_325 , & V_164 ) ;
#ifdef F_178
V_96 = F_179 ( NULL , & V_164 . V_59 ,
F_167 ) ;
if ( V_96 )
goto V_326;
V_172:
#endif
return V_96 ;
#ifdef F_178
V_326:
F_180 ( & V_324 ) ;
goto V_172;
#endif
}
int T_11 F_181 ( void )
{
return F_182 ( & V_327 ) ;
}
void F_183 ( void )
{
F_184 ( & V_327 ) ;
}
void F_185 ( void )
{
#ifdef F_178
F_186 ( & V_164 . V_59 ) ;
#endif
F_187 ( V_325 , & V_164 ) ;
F_180 ( & V_324 ) ;
}
