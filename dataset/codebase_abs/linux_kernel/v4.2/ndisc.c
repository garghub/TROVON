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
const struct V_37 * V_100 , const struct V_37 * V_99 )
{
struct V_1 * V_2 ;
struct V_37 V_149 ;
int V_126 = V_5 -> V_7 ;
int V_133 = 0 ;
struct V_131 * V_132 ;
if ( ! V_99 ) {
if ( F_71 ( V_5 , & V_149 ,
( V_150 | V_134 ) ) )
return;
V_99 = & V_149 ;
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
. V_112 = V_151 ,
} ,
. V_143 = * V_148 ,
} ;
if ( V_126 )
F_1 ( V_2 , V_22 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_99 ) ;
}
void F_73 ( struct V_40 * V_5 , const struct V_37 * V_99 ,
const struct V_37 * V_100 )
{
struct V_1 * V_2 ;
struct V_152 * V_132 ;
int V_153 = V_5 -> V_7 ;
int V_133 = 0 ;
#ifdef F_74
if ( V_153 ) {
struct V_128 * V_129 = F_63 ( F_34 ( V_5 ) , V_99 ,
V_5 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_72 & V_134 ) {
V_153 = 0 ;
}
F_64 ( V_129 ) ;
} else {
V_153 = 0 ;
}
}
#endif
if ( V_153 )
V_133 += F_3 ( V_5 ) ;
V_2 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_2 )
return;
V_132 = (struct V_152 * ) F_4 ( V_2 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_152 ) {
. V_138 = {
. V_112 = V_154 ,
} ,
} ;
if ( V_153 )
F_1 ( V_2 , V_22 ,
V_5 -> V_75 ) ;
F_45 ( V_2 , V_100 , V_99 ) ;
}
static void F_75 ( struct V_52 * V_54 , struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static void F_77 ( struct V_52 * V_54 , struct V_1 * V_2 )
{
struct V_37 * V_99 = NULL ;
struct V_37 V_155 ;
struct V_40 * V_5 = V_54 -> V_5 ;
struct V_37 * V_143 = (struct V_37 * ) & V_54 -> V_55 ;
int V_156 = F_78 ( & V_54 -> V_156 ) ;
if ( V_2 && F_79 ( F_34 ( V_5 ) , & F_43 ( V_2 ) -> V_99 ,
V_5 , 1 ,
V_150 | V_134 ) )
V_99 = & F_43 ( V_2 ) -> V_99 ;
V_156 -= F_80 ( V_54 -> V_59 , V_157 ) ;
if ( V_156 < 0 ) {
if ( ! ( V_54 -> V_65 & V_81 ) ) {
F_9 ( 1 , V_158 ,
L_4 ,
V_28 , V_143 ) ;
}
F_70 ( V_5 , V_54 , V_143 , V_143 , V_99 ) ;
} else if ( ( V_156 -= F_80 ( V_54 -> V_59 , V_159 ) ) < 0 ) {
F_81 ( V_54 ) ;
} else {
F_28 ( V_143 , & V_155 ) ;
F_70 ( V_5 , NULL , V_143 , & V_155 , V_99 ) ;
}
}
static int F_82 ( const void * V_50 ,
struct V_40 * V_5 )
{
struct V_83 * V_53 ;
int V_160 = - 1 ;
F_67 ( & V_161 . V_145 ) ;
V_53 = F_83 ( & V_161 , F_34 ( V_5 ) , V_50 , V_5 ) ;
if ( V_53 )
V_160 = ! ! ( V_53 -> V_72 & V_162 ) ;
F_69 ( & V_161 . V_145 ) ;
return V_160 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = (struct V_131 * ) F_85 ( V_2 ) ;
const struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_163 = NULL ;
T_2 V_164 = F_86 ( V_2 ) - ( F_85 ( V_2 ) +
F_87 ( struct V_131 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_128 * V_129 ;
struct V_56 * V_109 = NULL ;
struct V_52 * V_54 ;
int V_165 = F_72 ( V_99 ) ;
bool V_166 ;
int V_167 = - 1 ;
if ( V_2 -> V_86 < sizeof( struct V_131 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( F_21 ( & V_132 -> V_143 ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( V_165 && ! F_88 ( V_100 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( ! F_8 ( V_132 -> V_9 , V_164 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_8 ) ;
return;
}
if ( V_19 . V_168 ) {
V_163 = F_89 ( V_19 . V_168 , V_5 ) ;
if ( ! V_163 ) {
F_9 ( 2 , V_27 ,
L_9 ) ;
return;
}
if ( V_165 ) {
F_9 ( 2 , V_27 ,
L_10 ) ;
return;
}
}
V_166 = F_21 ( V_100 ) ;
V_129 = F_63 ( F_34 ( V_5 ) , & V_132 -> V_143 , V_5 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_72 & ( V_150 | V_134 ) ) {
if ( V_165 ) {
F_90 ( V_129 ) ;
return;
} else {
if ( ! ( V_129 -> V_72 & V_134 ) )
goto V_169;
}
}
V_109 = V_129 -> V_109 ;
} else {
struct V_108 * V_108 = F_34 ( V_5 ) ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 ) {
return;
}
if ( F_91 ( V_108 , V_5 , & V_132 -> V_143 ) ||
( V_109 -> V_135 . V_147 &&
( V_108 -> V_92 . V_170 -> V_171 || V_109 -> V_135 . V_171 ) &&
( V_167 = F_82 ( & V_132 -> V_143 , V_5 ) ) >= 0 ) ) {
if ( ! ( F_92 ( V_2 ) -> V_72 & V_172 ) &&
V_2 -> V_173 != V_174 &&
V_166 &&
F_80 ( V_109 -> V_61 , V_175 ) != 0 ) {
struct V_1 * V_53 = F_93 ( V_2 , V_95 ) ;
if ( V_53 )
F_94 ( & V_161 , V_109 -> V_61 , V_53 ) ;
goto V_169;
}
} else
goto V_169;
}
if ( V_167 < 0 )
V_167 = V_109 -> V_135 . V_147 ;
if ( V_165 ) {
F_62 ( V_5 , NULL , & V_146 , & V_132 -> V_143 ,
! ! V_167 , false , ( V_129 != NULL ) , true ) ;
goto V_169;
}
if ( V_166 )
F_95 ( & V_161 , V_176 ) ;
else
F_95 ( & V_161 , V_177 ) ;
V_54 = F_96 ( & V_161 , V_99 , V_5 ,
! V_166 || V_163 || ! V_5 -> V_7 ) ;
if ( V_54 )
F_97 ( V_54 , V_163 , V_178 ,
V_179 |
V_180 ) ;
if ( V_54 || ! V_5 -> V_64 ) {
F_62 ( V_5 , V_54 , V_99 , & V_132 -> V_143 ,
! ! V_167 ,
true , ( V_129 != NULL && V_166 ) , V_166 ) ;
if ( V_54 )
F_98 ( V_54 ) ;
}
V_169:
if ( V_129 )
F_64 ( V_129 ) ;
else
F_25 ( V_109 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = (struct V_131 * ) F_85 ( V_2 ) ;
struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
const struct V_37 * V_100 = & F_43 ( V_2 ) -> V_100 ;
T_1 * V_163 = NULL ;
T_2 V_164 = F_86 ( V_2 ) - ( F_85 ( V_2 ) +
F_87 ( struct V_131 , V_9 ) ) ;
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
if ( ! F_8 ( V_132 -> V_9 , V_164 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_14 ) ;
return;
}
if ( V_19 . V_181 ) {
V_163 = F_89 ( V_19 . V_181 , V_5 ) ;
if ( ! V_163 ) {
F_9 ( 2 , V_27 ,
L_15 ) ;
return;
}
}
V_129 = F_63 ( F_34 ( V_5 ) , & V_132 -> V_143 , V_5 , 1 ) ;
if ( V_129 ) {
if ( V_2 -> V_173 != V_182
&& ( V_129 -> V_72 & V_150 ) ) {
F_90 ( V_129 ) ;
return;
}
if ( V_2 -> V_173 != V_182 )
F_9 ( 1 , V_27 ,
L_16 ,
& V_129 -> V_38 , V_129 -> V_109 -> V_5 -> V_183 ) ;
F_64 ( V_129 ) ;
return;
}
V_54 = F_100 ( & V_161 , & V_132 -> V_143 , V_5 ) ;
if ( V_54 ) {
T_1 V_184 = V_54 -> V_72 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
if ( V_54 -> V_65 & V_185 )
goto V_169;
if ( V_163 && ! memcmp ( V_163 , V_5 -> V_75 , V_5 -> V_7 ) &&
V_108 -> V_92 . V_170 -> V_147 && V_108 -> V_92 . V_170 -> V_171 &&
F_101 ( & V_161 , V_108 , & V_132 -> V_143 , V_5 , 0 ) ) {
goto V_169;
}
F_97 ( V_54 , V_163 ,
V_132 -> V_138 . V_141 ? V_186 : V_178 ,
V_179 |
( V_132 -> V_138 . V_142 ? V_180 : 0 ) |
V_187 |
( V_132 -> V_138 . V_140 ? V_188 : 0 ) ) ;
if ( ( V_184 & ~ V_54 -> V_72 ) & V_162 ) {
F_102 ( F_34 ( V_5 ) , V_99 ) ;
}
V_169:
F_98 ( V_54 ) ;
}
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_152 * V_152 = (struct V_152 * ) F_85 ( V_2 ) ;
unsigned long V_164 = V_2 -> V_86 - sizeof( * V_152 ) ;
struct V_52 * V_54 ;
struct V_56 * V_109 ;
const struct V_37 * V_99 = & F_43 ( V_2 ) -> V_99 ;
struct V_17 V_19 ;
T_1 * V_163 = NULL ;
if ( V_2 -> V_86 < sizeof( * V_152 ) )
return;
V_109 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_109 ) {
F_9 ( 1 , V_96 , L_17 ) ;
return;
}
if ( ! V_109 -> V_135 . V_147 )
goto V_169;
if ( F_72 ( V_99 ) )
goto V_169;
if ( ! F_8 ( V_152 -> V_9 , V_164 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_18 ) ;
goto V_169;
}
if ( V_19 . V_168 ) {
V_163 = F_89 ( V_19 . V_168 ,
V_2 -> V_5 ) ;
if ( ! V_163 )
goto V_169;
}
V_54 = F_96 ( & V_161 , V_99 , V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
F_97 ( V_54 , V_163 , V_178 ,
V_179 |
V_180 |
V_187 ) ;
F_98 ( V_54 ) ;
}
V_169:
return;
}
static void F_104 ( struct V_1 * V_189 , struct V_10 * V_9 )
{
struct V_110 * V_111 = (struct V_110 * ) F_85 ( V_189 ) ;
struct V_1 * V_2 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_108 * V_108 = F_34 ( V_189 -> V_5 ) ;
int V_96 ;
int V_194 = F_105 ( sizeof( struct V_192 )
+ ( V_9 -> V_14 << 3 ) ) ;
T_4 V_195 = V_194 + F_106 ( sizeof( struct V_37 ) ) ;
V_2 = F_107 ( V_195 , V_95 ) ;
if ( ! V_2 ) {
V_96 = - V_196 ;
goto V_197;
}
V_191 = F_108 ( V_2 , 0 , 0 , V_198 , V_194 , 0 ) ;
if ( ! V_191 ) {
goto V_199;
}
V_193 = F_109 ( V_191 ) ;
V_193 -> V_200 = V_201 ;
V_193 -> V_202 = V_189 -> V_5 -> V_115 ;
V_193 -> V_203 = V_111 -> V_112 ;
V_193 -> V_204 = V_111 -> V_205 ;
V_193 -> V_206 = V_9 -> V_14 << 3 ;
memcpy ( V_193 + 1 , V_9 , V_9 -> V_14 << 3 ) ;
if ( F_110 ( V_2 , V_207 , & F_43 ( V_189 ) -> V_99 ) )
goto V_199;
F_111 ( V_2 , V_191 ) ;
F_112 ( V_2 , V_108 , 0 , V_208 , NULL , V_95 ) ;
return;
V_199:
F_113 ( V_2 ) ;
V_96 = - V_209 ;
V_197:
F_114 ( V_108 , V_208 , V_96 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_210 * V_210 = (struct V_210 * ) F_85 ( V_2 ) ;
struct V_52 * V_54 = NULL ;
struct V_56 * V_57 ;
struct V_211 * V_212 = NULL ;
int V_213 ;
struct V_17 V_19 ;
int V_133 ;
unsigned int V_214 = 0 ;
T_5 * V_9 = ( T_5 * ) ( V_210 + 1 ) ;
V_133 = ( F_86 ( V_2 ) - F_85 ( V_2 ) ) -
sizeof( struct V_210 ) ;
F_9 ( 2 , V_215 ,
L_19 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
if ( ! ( F_116 ( & F_43 ( V_2 ) -> V_99 ) & V_216 ) ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
if ( V_133 < 0 ) {
F_9 ( 2 , V_27 , L_21 ) ;
return;
}
#ifdef F_117
if ( V_2 -> V_217 == V_218 ) {
F_9 ( 2 , V_27 , L_22 ) ;
return;
}
#endif
V_57 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_57 ) {
F_9 ( 0 , V_96 , L_23 ,
V_2 -> V_5 -> V_183 ) ;
return;
}
if ( ! F_8 ( V_9 , V_133 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_24 ) ;
return;
}
if ( ! F_118 ( V_57 ) ) {
F_9 ( 2 , V_215 ,
L_25 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
goto V_219;
}
#ifdef F_117
if ( V_2 -> V_217 == V_220 ) {
F_9 ( 2 , V_215 ,
L_26 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
goto V_219;
}
#endif
if ( V_57 -> V_221 & V_222 ) {
V_57 -> V_221 |= V_223 ;
}
V_57 -> V_221 = ( V_57 -> V_221 & ~ ( V_224 |
V_225 ) ) |
( V_210 -> V_138 . V_226 ?
V_224 : 0 ) |
( V_210 -> V_138 . V_227 ?
V_225 : 0 ) ;
if ( ! V_57 -> V_135 . V_228 ) {
F_9 ( 2 , V_215 ,
L_27 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
goto V_229;
}
if ( ! V_57 -> V_135 . V_230 &&
F_119 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
NULL , 0 ) ) {
F_9 ( 2 , V_215 ,
L_28 ,
V_2 -> V_5 -> V_183 ) ;
goto V_229;
}
V_213 = F_120 ( V_210 -> V_138 . V_231 ) ;
#ifdef F_121
V_214 = V_210 -> V_138 . V_232 ;
if ( V_214 == V_233 ||
! V_57 -> V_135 . V_234 )
V_214 = V_235 ;
#endif
V_212 = F_122 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 ) ;
if ( V_212 ) {
V_54 = F_123 ( & V_212 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_124 ( V_212 ) ;
return;
}
}
if ( V_212 && V_213 == 0 ) {
F_125 ( V_212 ) ;
V_212 = NULL ;
}
F_9 ( 3 , V_215 , L_30 ,
V_212 , V_213 , V_2 -> V_5 -> V_183 ) ;
if ( ! V_212 && V_213 ) {
F_9 ( 3 , V_215 , L_31 ) ;
V_212 = F_126 ( & F_43 ( V_2 ) -> V_99 , V_2 -> V_5 , V_214 ) ;
if ( ! V_212 ) {
F_9 ( 0 , V_96 ,
L_32 ,
V_28 ) ;
return;
}
V_54 = F_123 ( & V_212 -> V_107 , & F_43 ( V_2 ) -> V_99 ) ;
if ( ! V_54 ) {
F_9 ( 0 , V_96 ,
L_29 ,
V_28 ) ;
F_124 ( V_212 ) ;
return;
}
V_54 -> V_72 |= V_162 ;
} else if ( V_212 ) {
V_212 -> V_236 = ( V_212 -> V_236 & ~ V_237 ) | F_127 ( V_214 ) ;
}
if ( V_212 )
F_128 ( V_212 , V_238 + ( V_239 * V_213 ) ) ;
if ( V_210 -> V_138 . V_240 ) {
if ( V_57 -> V_135 . V_101 < V_210 -> V_138 . V_240 ) {
V_57 -> V_135 . V_101 = V_210 -> V_138 . V_240 ;
} else {
F_9 ( 2 , V_27 , L_33 ) ;
}
if ( V_212 )
F_129 ( & V_212 -> V_107 , V_241 ,
V_210 -> V_138 . V_240 ) ;
}
V_229:
if ( V_57 -> V_61 ) {
unsigned long V_242 = F_130 ( V_210 -> V_243 ) ;
if ( V_242 && V_242 / 1000 < V_244 / V_239 ) {
V_242 = ( V_242 * V_239 ) / 1000 ;
if ( V_242 < V_239 / 10 )
V_242 = V_239 / 10 ;
F_131 ( V_57 -> V_61 , V_245 , V_242 ) ;
V_57 -> V_246 = V_238 ;
F_132 ( V_247 , V_57 ) ;
}
V_242 = F_130 ( V_210 -> V_248 ) ;
if ( V_242 && V_242 / 1000 < V_244 / ( 3 * V_239 ) ) {
V_242 = ( V_242 * V_239 ) / 1000 ;
if ( V_242 < V_239 / 10 )
V_242 = V_239 / 10 ;
if ( V_242 != F_80 ( V_57 -> V_61 , V_249 ) ) {
F_131 ( V_57 -> V_61 ,
V_249 , V_242 ) ;
F_131 ( V_57 -> V_61 ,
V_250 , 3 * V_242 ) ;
V_57 -> V_61 -> V_248 = F_133 ( V_242 ) ;
V_57 -> V_246 = V_238 ;
F_132 ( V_247 , V_57 ) ;
}
}
}
V_219:
if ( ! V_54 )
V_54 = F_96 ( & V_161 , & F_43 ( V_2 ) -> V_99 ,
V_2 -> V_5 , 1 ) ;
if ( V_54 ) {
T_1 * V_163 = NULL ;
if ( V_19 . V_168 ) {
V_163 = F_89 ( V_19 . V_168 ,
V_2 -> V_5 ) ;
if ( ! V_163 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_169;
}
}
F_97 ( V_54 , V_163 , V_178 ,
V_179 |
V_180 |
V_187 |
V_188 ) ;
}
if ( ! F_118 ( V_57 ) ) {
F_9 ( 2 , V_215 ,
L_35 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
goto V_169;
}
#ifdef F_10
if ( ! V_57 -> V_135 . V_230 &&
F_119 ( F_34 ( V_57 -> V_5 ) , & F_43 ( V_2 ) -> V_99 ,
NULL , 0 ) ) {
F_9 ( 2 , V_215 ,
L_36 ,
V_2 -> V_5 -> V_183 ) ;
goto V_251;
}
if ( V_57 -> V_135 . V_234 && V_19 . V_33 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_33 ;
V_252 ;
V_252 = F_5 ( V_252 , V_19 . V_32 ) ) {
struct V_253 * V_254 = (struct V_253 * ) V_252 ;
#ifdef F_117
if ( V_2 -> V_217 == V_220 &&
V_254 -> V_255 == 0 )
continue;
#endif
if ( V_254 -> V_255 == 0 &&
! V_57 -> V_135 . V_228 )
continue;
if ( V_254 -> V_255 > V_57 -> V_135 . V_256 )
continue;
F_134 ( V_2 -> V_5 , ( T_1 * ) V_252 , ( V_252 -> V_14 ) << 3 ,
& F_43 ( V_2 ) -> V_99 ) ;
}
}
V_251:
#endif
#ifdef F_117
if ( V_2 -> V_217 == V_220 ) {
F_9 ( 2 , V_215 ,
L_37 ,
V_28 , V_2 -> V_5 -> V_183 ) ;
goto V_169;
}
#endif
if ( V_57 -> V_135 . V_257 && V_19 . V_258 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_258 ;
V_252 ;
V_252 = F_5 ( V_252 , V_19 . V_30 ) ) {
F_135 ( V_2 -> V_5 , ( T_1 * ) V_252 ,
( V_252 -> V_14 ) << 3 ,
V_19 . V_168 != NULL ) ;
}
}
if ( V_19 . V_259 && V_57 -> V_135 . V_260 ) {
T_6 V_53 ;
T_2 V_261 ;
memcpy ( & V_53 , ( ( T_1 * ) ( V_19 . V_259 + 1 ) ) + 2 , sizeof( V_261 ) ) ;
V_261 = F_130 ( V_53 ) ;
if ( V_261 < V_262 || V_261 > V_2 -> V_5 -> V_261 ) {
F_9 ( 2 , V_27 , L_38 , V_261 ) ;
} else if ( V_57 -> V_135 . V_263 != V_261 ) {
V_57 -> V_135 . V_263 = V_261 ;
if ( V_212 )
F_129 ( & V_212 -> V_107 , V_264 , V_261 ) ;
F_136 ( V_2 -> V_5 , V_261 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_35 ;
V_252 ;
V_252 = F_7 ( V_252 , V_19 . V_34 ) ) {
F_104 ( V_2 , V_252 ) ;
}
}
if ( V_19 . V_181 || V_19 . V_265 ) {
F_9 ( 2 , V_27 , L_39 ) ;
}
V_169:
F_124 ( V_212 ) ;
if ( V_54 )
F_98 ( V_54 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
T_1 * V_102 ;
struct V_17 V_19 ;
struct V_266 * V_132 = (struct V_266 * ) F_85 ( V_2 ) ;
T_2 V_164 = F_86 ( V_2 ) - ( F_85 ( V_2 ) +
F_87 ( struct V_266 , V_9 ) ) ;
#ifdef F_117
switch ( V_2 -> V_217 ) {
case V_218 :
case V_220 :
F_9 ( 2 , V_27 ,
L_40 ) ;
return;
}
#endif
if ( ! ( F_116 ( & F_43 ( V_2 ) -> V_99 ) & V_216 ) ) {
F_9 ( 2 , V_27 ,
L_41 ) ;
return;
}
if ( ! F_8 ( V_132 -> V_9 , V_164 , & V_19 ) )
return;
if ( ! V_19 . V_265 ) {
F_138 ( V_2 , F_34 ( V_2 -> V_5 ) ,
V_2 -> V_5 -> V_115 , 0 ) ;
return;
}
V_102 = ( T_1 * ) V_19 . V_265 ;
V_102 += 8 ;
if ( ! F_139 ( V_2 , V_102 - F_85 ( V_2 ) ) )
return;
F_140 ( V_2 , V_267 , 0 , 0 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_1 * V_268 ,
int V_269 )
{
T_1 * V_9 = F_4 ( V_2 , V_269 ) ;
memset ( V_9 , 0 , 8 ) ;
* ( V_9 ++ ) = V_25 ;
* ( V_9 ++ ) = ( V_269 >> 3 ) ;
V_9 += 6 ;
memcpy ( V_9 , F_43 ( V_268 ) , V_269 - 8 ) ;
}
void F_142 ( struct V_1 * V_2 , const struct V_37 * V_143 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_90 * V_91 = V_108 -> V_92 . V_93 ;
int V_133 = 0 ;
struct V_270 * V_271 ;
struct V_1 * V_272 ;
struct V_266 * V_132 ;
struct V_37 V_273 ;
struct V_211 * V_212 ;
struct V_106 * V_107 ;
struct V_113 V_114 ;
int V_269 ;
T_1 V_274 [ V_275 ] , * V_71 = NULL ;
bool V_160 ;
if ( F_71 ( V_5 , & V_273 , V_150 ) ) {
F_9 ( 2 , V_27 , L_42 ,
V_5 -> V_183 ) ;
return;
}
if ( ! F_143 ( & F_43 ( V_2 ) -> V_100 , V_143 ) &&
F_116 ( V_143 ) != ( V_276 | V_216 ) ) {
F_9 ( 2 , V_27 ,
L_43 ) ;
return;
}
F_48 ( V_91 , & V_114 , V_267 ,
& V_273 , & F_43 ( V_2 ) -> V_99 , V_5 -> V_115 ) ;
V_107 = F_144 ( V_108 , NULL , & V_114 ) ;
if ( V_107 -> error ) {
F_145 ( V_107 ) ;
return;
}
V_107 = F_146 ( V_108 , V_107 , F_147 ( & V_114 ) , NULL , 0 ) ;
if ( F_50 ( V_107 ) )
return;
V_212 = (struct V_211 * ) V_107 ;
if ( V_212 -> V_236 & V_277 ) {
F_9 ( 2 , V_27 ,
L_44 ) ;
goto V_278;
}
V_271 = F_148 ( V_108 -> V_92 . V_279 , & F_43 ( V_2 ) -> V_99 , 1 ) ;
V_160 = F_149 ( V_271 , 1 * V_239 ) ;
if ( V_271 )
F_150 ( V_271 ) ;
if ( ! V_160 )
goto V_278;
if ( V_5 -> V_7 ) {
struct V_52 * V_54 = F_123 ( F_46 ( V_2 ) , V_143 ) ;
if ( ! V_54 ) {
F_9 ( 2 , V_27 ,
L_45 ) ;
goto V_278;
}
F_67 ( & V_54 -> V_145 ) ;
if ( V_54 -> V_65 & V_81 ) {
memcpy ( V_274 , V_54 -> V_71 , V_5 -> V_7 ) ;
F_69 ( & V_54 -> V_145 ) ;
V_71 = V_274 ;
V_133 += F_3 ( V_5 ) ;
} else
F_69 ( & V_54 -> V_145 ) ;
F_98 ( V_54 ) ;
}
V_269 = F_151 (unsigned int,
IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(*msg) - optlen,
skb->len + 8 ) ;
V_269 &= ~ 0x7 ;
V_133 += V_269 ;
V_272 = F_32 ( V_5 , sizeof( * V_132 ) + V_133 ) ;
if ( ! V_272 )
goto V_278;
V_132 = (struct V_266 * ) F_4 ( V_272 , sizeof( * V_132 ) ) ;
* V_132 = (struct V_266 ) {
. V_138 = {
. V_112 = V_267 ,
} ,
. V_143 = * V_143 ,
. V_280 = F_43 ( V_2 ) -> V_100 ,
} ;
if ( V_71 )
F_1 ( V_272 , V_23 , V_71 ) ;
if ( V_269 )
F_141 ( V_272 , V_2 , V_269 ) ;
F_52 ( V_272 , V_107 ) ;
F_45 ( V_272 , & F_43 ( V_2 ) -> V_99 , & V_273 ) ;
return;
V_278:
F_145 ( V_107 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static bool F_153 ( struct V_1 * V_2 )
{
struct V_56 * V_109 = F_27 ( V_2 -> V_5 ) ;
if ( ! V_109 )
return true ;
if ( F_154 ( V_2 ) -> V_72 & V_281 &&
V_109 -> V_135 . V_282 ) {
F_155 ( L_46 ) ;
return true ;
}
return false ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
if ( F_153 ( V_2 ) )
return 0 ;
if ( F_157 ( V_2 ) )
return 0 ;
V_132 = (struct V_131 * ) F_85 ( V_2 ) ;
F_158 ( V_2 , V_2 -> V_3 - F_85 ( V_2 ) ) ;
if ( F_43 ( V_2 ) -> V_101 != 255 ) {
F_9 ( 2 , V_27 , L_47 ,
F_43 ( V_2 ) -> V_101 ) ;
return 0 ;
}
if ( V_132 -> V_138 . V_205 != 0 ) {
F_9 ( 2 , V_27 , L_48 ,
V_132 -> V_138 . V_205 ) ;
return 0 ;
}
memset ( F_92 ( V_2 ) , 0 , sizeof( struct V_283 ) ) ;
switch ( V_132 -> V_138 . V_112 ) {
case V_151 :
F_84 ( V_2 ) ;
break;
case V_139 :
F_99 ( V_2 ) ;
break;
case V_154 :
F_103 ( V_2 ) ;
break;
case V_284 :
F_115 ( V_2 ) ;
break;
case V_267 :
F_137 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_159 ( struct V_285 * V_286 , unsigned long V_287 , void * V_288 )
{
struct V_40 * V_5 = F_160 ( V_288 ) ;
struct V_289 * V_290 ;
struct V_108 * V_108 = F_34 ( V_5 ) ;
struct V_56 * V_109 ;
switch ( V_287 ) {
case V_291 :
F_161 ( & V_161 , V_5 ) ;
F_162 ( 0 , V_108 , false ) ;
V_109 = F_22 ( V_5 ) ;
if ( ! V_109 )
break;
if ( V_109 -> V_135 . V_292 )
F_66 ( V_5 ) ;
F_25 ( V_109 ) ;
break;
case V_293 :
V_290 = V_288 ;
if ( V_290 -> V_294 & V_73 )
F_161 ( & V_161 , V_5 ) ;
break;
case V_295 :
F_163 ( & V_161 , V_5 ) ;
F_162 ( 0 , V_108 , false ) ;
break;
case V_296 :
F_66 ( V_5 ) ;
break;
default:
break;
}
return V_297 ;
}
static void F_164 ( struct V_298 * V_299 ,
const char * V_300 , const char * V_301 )
{
static char V_302 [ V_303 ] ;
static int V_304 ;
if ( strcmp ( V_302 , V_305 -> V_306 ) && V_304 < 5 ) {
strcpy ( V_302 , V_305 -> V_306 ) ;
F_165 ( L_49 ,
V_302 , V_300 ,
V_301 , V_299 -> V_307 ,
V_301 , V_299 -> V_307 ) ;
V_304 ++ ;
}
}
int F_166 ( struct V_298 * V_299 , int V_308 , void T_7 * V_309 , T_4 * V_310 , T_8 * V_311 )
{
struct V_40 * V_5 = V_299 -> V_312 ;
struct V_56 * V_109 ;
int V_160 ;
if ( ( strcmp ( V_299 -> V_307 , L_50 ) == 0 ) ||
( strcmp ( V_299 -> V_307 , L_51 ) == 0 ) )
F_164 ( V_299 , L_52 , V_5 ? V_5 -> V_183 : L_53 ) ;
if ( strcmp ( V_299 -> V_307 , L_50 ) == 0 )
V_160 = F_167 ( V_299 , V_308 , V_309 , V_310 , V_311 ) ;
else if ( strcmp ( V_299 -> V_307 , L_51 ) == 0 )
V_160 = F_168 ( V_299 , V_308 ,
V_309 , V_310 , V_311 ) ;
else if ( ( strcmp ( V_299 -> V_307 , L_54 ) == 0 ) ||
( strcmp ( V_299 -> V_307 , L_55 ) == 0 ) )
V_160 = F_169 ( V_299 , V_308 ,
V_309 , V_310 , V_311 ) ;
else
V_160 = - 1 ;
if ( V_308 && V_160 == 0 && V_5 && ( V_109 = F_22 ( V_5 ) ) != NULL ) {
if ( V_299 -> V_3 == & F_80 ( V_109 -> V_61 , V_249 ) )
V_109 -> V_61 -> V_248 =
F_133 ( F_80 ( V_109 -> V_61 , V_249 ) ) ;
V_109 -> V_246 = V_238 ;
F_132 ( V_247 , V_109 ) ;
F_25 ( V_109 ) ;
}
return V_160 ;
}
static int T_9 F_170 ( struct V_108 * V_108 )
{
struct V_313 * V_314 ;
struct V_90 * V_91 ;
int V_96 ;
V_96 = F_171 ( & V_91 , V_315 ,
V_316 , V_105 , V_108 ) ;
if ( V_96 < 0 ) {
F_9 ( 0 , V_96 ,
L_56 ,
V_96 ) ;
return V_96 ;
}
V_108 -> V_92 . V_93 = V_91 ;
V_314 = F_55 ( V_91 ) ;
V_314 -> V_101 = 255 ;
V_314 -> V_317 = 0 ;
return 0 ;
}
static void T_10 F_172 ( struct V_108 * V_108 )
{
F_173 ( V_108 -> V_92 . V_93 ) ;
}
int T_11 F_174 ( void )
{
int V_96 ;
V_96 = F_175 ( & V_318 ) ;
if ( V_96 )
return V_96 ;
F_176 ( V_319 , & V_161 ) ;
#ifdef F_177
V_96 = F_178 ( NULL , & V_161 . V_59 ,
F_166 ) ;
if ( V_96 )
goto V_320;
V_169:
#endif
return V_96 ;
#ifdef F_177
V_320:
F_179 ( & V_318 ) ;
goto V_169;
#endif
}
int T_11 F_180 ( void )
{
return F_181 ( & V_321 ) ;
}
void F_182 ( void )
{
F_183 ( & V_321 ) ;
}
void F_184 ( void )
{
#ifdef F_177
F_185 ( & V_161 . V_59 ) ;
#endif
F_186 ( V_319 , & V_161 ) ;
F_179 ( & V_318 ) ;
}
