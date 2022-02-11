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
if ( ( V_8 -= V_6 ) > 0 )
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
} while( V_11 < V_12 && V_11 -> V_13 != type );
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
} while( V_11 < V_12 && ! F_6 ( V_11 ) );
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
static int F_18 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_53 -> V_54 ;
struct V_40 * V_5 = V_53 -> V_5 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
bool V_59 = F_19 ( V_38 ) ;
V_56 = F_20 ( V_5 ) ;
if ( V_56 == NULL ) {
return - V_49 ;
}
V_58 = V_56 -> V_60 ;
F_21 ( V_53 -> V_58 ) ;
V_53 -> V_58 = F_22 ( V_58 ) ;
V_53 -> type = V_59 ? V_61 : V_62 ;
if ( ! V_5 -> V_63 ) {
V_53 -> V_64 = V_65 ;
V_53 -> V_66 = & V_67 ;
V_53 -> V_68 = V_69 ;
} else {
if ( V_59 ) {
V_53 -> V_64 = V_65 ;
F_11 ( V_38 , V_53 -> V_70 , V_5 , 1 ) ;
} else if ( V_5 -> V_71 & ( V_72 | V_73 ) ) {
V_53 -> V_64 = V_65 ;
memcpy ( V_53 -> V_70 , V_5 -> V_74 , V_5 -> V_7 ) ;
if ( V_5 -> V_71 & V_73 )
V_53 -> type = V_75 ;
} else if ( V_5 -> V_71 & V_76 ) {
V_53 -> V_64 = V_65 ;
memcpy ( V_53 -> V_70 , V_5 -> V_47 , V_5 -> V_7 ) ;
}
if ( V_5 -> V_63 -> V_77 )
V_53 -> V_66 = & V_78 ;
else
V_53 -> V_66 = & V_79 ;
if ( V_53 -> V_64 & V_80 )
V_53 -> V_68 = V_53 -> V_66 -> V_81 ;
else
V_53 -> V_68 = V_53 -> V_66 -> V_68 ;
}
F_23 ( V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_82 * V_83 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_83 -> V_84 ;
struct V_37 V_85 ;
struct V_40 * V_5 = V_83 -> V_5 ;
if ( V_5 == NULL || F_25 ( V_5 ) == NULL )
return - V_49 ;
F_26 ( V_38 , & V_85 ) ;
F_27 ( V_5 , & V_85 ) ;
return 0 ;
}
static void F_28 ( struct V_82 * V_83 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_83 -> V_84 ;
struct V_37 V_85 ;
struct V_40 * V_5 = V_83 -> V_5 ;
if ( V_5 == NULL || F_25 ( V_5 ) == NULL )
return;
F_26 ( V_38 , & V_85 ) ;
F_29 ( V_5 , & V_85 ) ;
}
static struct V_1 * F_30 ( struct V_40 * V_5 ,
int V_86 )
{
int V_87 = F_31 ( V_5 ) ;
int V_88 = V_5 -> V_89 ;
struct V_90 * V_91 = F_32 ( V_5 ) -> V_92 . V_93 ;
struct V_1 * V_2 ;
int V_94 ;
V_2 = F_33 ( V_91 ,
V_87 + sizeof( struct V_95 ) + V_86 + V_88 ,
1 , & V_94 ) ;
if ( ! V_2 ) {
F_9 ( 0 , V_94 , L_3 ,
V_28 , V_94 ) ;
return NULL ;
}
V_2 -> V_96 = F_34 ( V_97 ) ;
V_2 -> V_5 = V_5 ;
F_35 ( V_2 , V_87 + sizeof( struct V_95 ) ) ;
F_36 ( V_2 ) ;
return V_2 ;
}
static void F_37 ( struct V_1 * V_2 ,
const struct V_37 * V_98 ,
const struct V_37 * V_99 ,
int V_100 , int V_86 )
{
struct V_95 * V_101 ;
F_38 ( V_2 , sizeof( * V_101 ) ) ;
F_39 ( V_2 ) ;
V_101 = F_40 ( V_2 ) ;
F_41 ( V_101 , 0 , 0 ) ;
V_101 -> V_102 = F_34 ( V_86 ) ;
V_101 -> V_103 = V_104 ;
V_101 -> V_100 = V_100 ;
V_101 -> V_98 = * V_98 ;
V_101 -> V_99 = * V_99 ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_37 * V_99 ,
const struct V_37 * V_98 )
{
struct V_105 * V_106 = F_43 ( V_2 ) ;
struct V_107 * V_107 = F_32 ( V_2 -> V_5 ) ;
struct V_90 * V_91 = V_107 -> V_92 . V_93 ;
struct V_55 * V_108 ;
int V_94 ;
struct V_109 * V_110 = F_44 ( V_2 ) ;
T_1 type ;
type = V_110 -> V_111 ;
if ( ! V_106 ) {
struct V_90 * V_91 = V_107 -> V_92 . V_93 ;
struct V_112 V_113 ;
F_45 ( V_91 , & V_113 , type , V_98 , V_99 , V_2 -> V_5 -> V_114 ) ;
V_106 = F_46 ( V_2 -> V_5 , & V_113 ) ;
if ( F_47 ( V_106 ) ) {
F_48 ( V_2 ) ;
return;
}
F_49 ( V_2 , V_106 ) ;
}
V_110 -> V_115 = F_50 ( V_98 , V_99 , V_2 -> V_86 ,
V_104 ,
F_51 ( V_110 ,
V_2 -> V_86 , 0 ) ) ;
F_37 ( V_2 , V_98 , V_99 , F_52 ( V_91 ) -> V_100 , V_2 -> V_86 ) ;
F_53 () ;
V_108 = F_25 ( V_106 -> V_5 ) ;
F_54 ( V_107 , V_108 , V_116 , V_2 -> V_86 ) ;
V_94 = F_55 ( V_117 , V_118 , V_2 , NULL , V_106 -> V_5 ,
V_119 ) ;
if ( ! V_94 ) {
F_56 ( V_107 , V_108 , type ) ;
F_57 ( V_107 , V_108 , V_120 ) ;
}
F_58 () ;
}
static void F_59 ( struct V_40 * V_5 , struct V_52 * V_53 ,
const struct V_37 * V_99 ,
const struct V_37 * V_121 ,
bool V_122 , bool V_123 , bool V_124 , bool V_125 )
{
struct V_1 * V_2 ;
struct V_37 V_126 ;
struct V_127 * V_128 ;
const struct V_37 * V_129 ;
struct V_130 * V_131 ;
int V_132 = 0 ;
V_128 = F_60 ( F_32 ( V_5 ) , V_121 , V_5 , 1 ) ;
if ( V_128 ) {
V_129 = V_121 ;
if ( V_128 -> V_71 & V_133 )
V_124 = 0 ;
V_125 |= V_128 -> V_108 -> V_134 . V_135 ;
F_61 ( V_128 ) ;
} else {
if ( F_62 ( F_32 ( V_5 ) , V_5 , V_99 ,
F_52 ( F_32 ( V_5 ) -> V_92 . V_93 ) -> V_136 ,
& V_126 ) )
return;
V_129 = & V_126 ;
}
if ( ! V_5 -> V_7 )
V_125 = 0 ;
if ( V_125 )
V_132 += F_3 ( V_5 ) ;
V_2 = F_30 ( V_5 , sizeof( * V_131 ) + V_132 ) ;
if ( ! V_2 )
return;
V_131 = (struct V_130 * ) F_4 ( V_2 , sizeof( * V_131 ) ) ;
* V_131 = (struct V_130 ) {
. V_137 = {
. V_111 = V_138 ,
. V_139 = V_122 ,
. V_140 = V_123 ,
. V_141 = V_124 ,
} ,
. V_142 = * V_121 ,
} ;
if ( V_125 )
F_1 ( V_2 , V_23 ,
V_5 -> V_74 ) ;
F_42 ( V_2 , V_99 , V_129 ) ;
}
static void F_63 ( struct V_40 * V_5 )
{
struct V_55 * V_108 ;
struct V_127 * V_143 ;
V_108 = F_20 ( V_5 ) ;
if ( ! V_108 )
return;
F_64 ( & V_108 -> V_144 ) ;
F_65 (ifa, &idev->addr_list, if_list) {
F_59 ( V_5 , NULL , & V_145 , & V_143 -> V_38 ,
! ! V_108 -> V_134 . V_146 ,
false , true ,
true ) ;
}
F_66 ( & V_108 -> V_144 ) ;
F_23 ( V_108 ) ;
}
void F_67 ( struct V_40 * V_5 , struct V_52 * V_53 ,
const struct V_37 * V_147 ,
const struct V_37 * V_99 , const struct V_37 * V_98 )
{
struct V_1 * V_2 ;
struct V_37 V_148 ;
int V_125 = V_5 -> V_7 ;
int V_132 = 0 ;
struct V_130 * V_131 ;
if ( V_98 == NULL ) {
if ( F_68 ( V_5 , & V_148 ,
( V_149 | V_133 ) ) )
return;
V_98 = & V_148 ;
}
if ( F_69 ( V_98 ) )
V_125 = 0 ;
if ( V_125 )
V_132 += F_3 ( V_5 ) ;
V_2 = F_30 ( V_5 , sizeof( * V_131 ) + V_132 ) ;
if ( ! V_2 )
return;
V_131 = (struct V_130 * ) F_4 ( V_2 , sizeof( * V_131 ) ) ;
* V_131 = (struct V_130 ) {
. V_137 = {
. V_111 = V_150 ,
} ,
. V_142 = * V_147 ,
} ;
if ( V_125 )
F_1 ( V_2 , V_22 ,
V_5 -> V_74 ) ;
F_42 ( V_2 , V_99 , V_98 ) ;
}
void F_70 ( struct V_40 * V_5 , const struct V_37 * V_98 ,
const struct V_37 * V_99 )
{
struct V_1 * V_2 ;
struct V_151 * V_131 ;
int V_152 = V_5 -> V_7 ;
int V_132 = 0 ;
#ifdef F_71
if ( V_152 ) {
struct V_127 * V_128 = F_60 ( F_32 ( V_5 ) , V_98 ,
V_5 , 1 ) ;
if ( V_128 ) {
if ( V_128 -> V_71 & V_133 ) {
V_152 = 0 ;
}
F_61 ( V_128 ) ;
} else {
V_152 = 0 ;
}
}
#endif
if ( V_152 )
V_132 += F_3 ( V_5 ) ;
V_2 = F_30 ( V_5 , sizeof( * V_131 ) + V_132 ) ;
if ( ! V_2 )
return;
V_131 = (struct V_151 * ) F_4 ( V_2 , sizeof( * V_131 ) ) ;
* V_131 = (struct V_151 ) {
. V_137 = {
. V_111 = V_153 ,
} ,
} ;
if ( V_152 )
F_1 ( V_2 , V_22 ,
V_5 -> V_74 ) ;
F_42 ( V_2 , V_99 , V_98 ) ;
}
static void F_72 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
F_48 ( V_2 ) ;
}
static void F_74 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
struct V_37 * V_98 = NULL ;
struct V_37 V_154 ;
struct V_40 * V_5 = V_53 -> V_5 ;
struct V_37 * V_142 = (struct V_37 * ) & V_53 -> V_54 ;
int V_155 = F_75 ( & V_53 -> V_155 ) ;
if ( V_2 && F_76 ( F_32 ( V_5 ) , & F_40 ( V_2 ) -> V_98 , V_5 , 1 ) )
V_98 = & F_40 ( V_2 ) -> V_98 ;
if ( ( V_155 -= V_53 -> V_58 -> V_156 ) < 0 ) {
if ( ! ( V_53 -> V_64 & V_80 ) ) {
F_9 ( 1 , V_157 ,
L_4 ,
V_28 , V_142 ) ;
}
F_67 ( V_5 , V_53 , V_142 , V_142 , V_98 ) ;
} else if ( ( V_155 -= V_53 -> V_58 -> V_158 ) < 0 ) {
#ifdef F_77
F_78 ( V_53 ) ;
#endif
} else {
F_26 ( V_142 , & V_154 ) ;
F_67 ( V_5 , NULL , V_142 , & V_154 , V_98 ) ;
}
}
static int F_79 ( const void * V_50 ,
struct V_40 * V_5 )
{
struct V_82 * V_83 ;
int V_159 = - 1 ;
F_64 ( & V_160 . V_144 ) ;
V_83 = F_80 ( & V_160 , F_32 ( V_5 ) , V_50 , V_5 ) ;
if ( V_83 )
V_159 = ! ! ( V_83 -> V_71 & V_161 ) ;
F_66 ( & V_160 . V_144 ) ;
return V_159 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_130 * V_131 = (struct V_130 * ) F_82 ( V_2 ) ;
const struct V_37 * V_98 = & F_40 ( V_2 ) -> V_98 ;
const struct V_37 * V_99 = & F_40 ( V_2 ) -> V_99 ;
T_1 * V_162 = NULL ;
T_2 V_163 = V_2 -> V_164 - ( V_2 -> V_165 +
F_83 ( struct V_130 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_127 * V_128 ;
struct V_55 * V_108 = NULL ;
struct V_52 * V_53 ;
int V_166 = F_69 ( V_98 ) ;
bool V_167 ;
int V_168 = - 1 ;
if ( V_2 -> V_86 < sizeof( struct V_130 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( F_19 ( & V_131 -> V_142 ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( V_166 && ! F_84 ( V_99 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( ! F_8 ( V_131 -> V_9 , V_163 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_8 ) ;
return;
}
if ( V_19 . V_169 ) {
V_162 = F_85 ( V_19 . V_169 , V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_9 ) ;
return;
}
if ( V_166 ) {
F_9 ( 2 , V_27 ,
L_10 ) ;
return;
}
}
V_167 = F_19 ( V_99 ) ;
V_128 = F_60 ( F_32 ( V_5 ) , & V_131 -> V_142 , V_5 , 1 ) ;
if ( V_128 ) {
if ( V_128 -> V_71 & ( V_149 | V_133 ) ) {
if ( V_166 ) {
F_86 ( V_128 ) ;
return;
} else {
if ( ! ( V_128 -> V_71 & V_133 ) )
goto V_170;
}
}
V_108 = V_128 -> V_108 ;
} else {
struct V_107 * V_107 = F_32 ( V_5 ) ;
V_108 = F_20 ( V_5 ) ;
if ( ! V_108 ) {
return;
}
if ( F_87 ( V_107 , V_5 , & V_131 -> V_142 ) ||
( V_108 -> V_134 . V_146 &&
( V_107 -> V_92 . V_171 -> V_172 || V_108 -> V_134 . V_172 ) &&
( V_168 = F_79 ( & V_131 -> V_142 , V_5 ) ) >= 0 ) ) {
if ( ! ( F_88 ( V_2 ) -> V_71 & V_173 ) &&
V_2 -> V_174 != V_175 &&
V_167 != 0 &&
V_108 -> V_60 -> V_176 != 0 ) {
struct V_1 * V_83 = F_89 ( V_2 , V_177 ) ;
if ( V_83 )
F_90 ( & V_160 , V_108 -> V_60 , V_83 ) ;
goto V_170;
}
} else
goto V_170;
}
if ( V_168 < 0 )
V_168 = V_108 -> V_134 . V_146 ;
if ( V_166 ) {
F_59 ( V_5 , NULL , & V_145 , & V_131 -> V_142 ,
! ! V_168 , false , ( V_128 != NULL ) , true ) ;
goto V_170;
}
if ( V_167 )
F_91 ( & V_160 , V_178 ) ;
else
F_91 ( & V_160 , V_179 ) ;
V_53 = F_92 ( & V_160 , V_98 , V_5 ,
! V_167 || V_162 || ! V_5 -> V_7 ) ;
if ( V_53 )
F_93 ( V_53 , V_162 , V_180 ,
V_181 |
V_182 ) ;
if ( V_53 || ! V_5 -> V_63 ) {
F_59 ( V_5 , V_53 , V_98 , & V_131 -> V_142 ,
! ! V_168 ,
true , ( V_128 != NULL && V_167 ) , V_167 ) ;
if ( V_53 )
F_94 ( V_53 ) ;
}
V_170:
if ( V_128 )
F_61 ( V_128 ) ;
else
F_23 ( V_108 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_130 * V_131 = (struct V_130 * ) F_82 ( V_2 ) ;
const struct V_37 * V_98 = & F_40 ( V_2 ) -> V_98 ;
const struct V_37 * V_99 = & F_40 ( V_2 ) -> V_99 ;
T_1 * V_162 = NULL ;
T_2 V_163 = V_2 -> V_164 - ( V_2 -> V_165 +
F_83 ( struct V_130 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_127 * V_128 ;
struct V_52 * V_53 ;
if ( V_2 -> V_86 < sizeof( struct V_130 ) ) {
F_9 ( 2 , V_27 , L_11 ) ;
return;
}
if ( F_19 ( & V_131 -> V_142 ) ) {
F_9 ( 2 , V_27 , L_12 ) ;
return;
}
if ( F_19 ( V_99 ) &&
V_131 -> V_137 . V_140 ) {
F_9 ( 2 , V_27 , L_13 ) ;
return;
}
if ( ! F_8 ( V_131 -> V_9 , V_163 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_14 ) ;
return;
}
if ( V_19 . V_183 ) {
V_162 = F_85 ( V_19 . V_183 , V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_15 ) ;
return;
}
}
V_128 = F_60 ( F_32 ( V_5 ) , & V_131 -> V_142 , V_5 , 1 ) ;
if ( V_128 ) {
if ( V_2 -> V_174 != V_184
&& ( V_128 -> V_71 & V_149 ) ) {
F_86 ( V_128 ) ;
return;
}
if ( V_2 -> V_174 != V_184 )
F_9 ( 1 , V_27 ,
L_16 ,
& V_128 -> V_38 , V_128 -> V_108 -> V_5 -> V_185 ) ;
F_61 ( V_128 ) ;
return;
}
V_53 = F_96 ( & V_160 , & V_131 -> V_142 , V_5 ) ;
if ( V_53 ) {
T_1 V_186 = V_53 -> V_71 ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
if ( V_53 -> V_64 & V_187 )
goto V_170;
if ( V_162 && ! memcmp ( V_162 , V_5 -> V_74 , V_5 -> V_7 ) &&
V_107 -> V_92 . V_171 -> V_146 && V_107 -> V_92 . V_171 -> V_172 &&
F_97 ( & V_160 , V_107 , & V_131 -> V_142 , V_5 , 0 ) ) {
goto V_170;
}
F_93 ( V_53 , V_162 ,
V_131 -> V_137 . V_140 ? V_188 : V_180 ,
V_181 |
( V_131 -> V_137 . V_141 ? V_182 : 0 ) |
V_189 |
( V_131 -> V_137 . V_139 ? V_190 : 0 ) ) ;
if ( ( V_186 & ~ V_53 -> V_71 ) & V_161 ) {
struct V_191 * V_192 ;
V_192 = F_98 ( V_98 , V_5 ) ;
if ( V_192 )
F_99 ( V_192 ) ;
}
V_170:
F_94 ( V_53 ) ;
}
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_151 * V_151 = (struct V_151 * ) F_82 ( V_2 ) ;
unsigned long V_163 = V_2 -> V_86 - sizeof( * V_151 ) ;
struct V_52 * V_53 ;
struct V_55 * V_108 ;
const struct V_37 * V_98 = & F_40 ( V_2 ) -> V_98 ;
struct V_17 V_19 ;
T_1 * V_162 = NULL ;
if ( V_2 -> V_86 < sizeof( * V_151 ) )
return;
V_108 = F_25 ( V_2 -> V_5 ) ;
if ( ! V_108 ) {
F_9 ( 1 , V_94 , L_17 ) ;
return;
}
if ( ! V_108 -> V_134 . V_146 )
goto V_170;
if ( F_69 ( V_98 ) )
goto V_170;
if ( ! F_8 ( V_151 -> V_9 , V_163 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_18 ) ;
goto V_170;
}
if ( V_19 . V_169 ) {
V_162 = F_85 ( V_19 . V_169 ,
V_2 -> V_5 ) ;
if ( ! V_162 )
goto V_170;
}
V_53 = F_92 ( & V_160 , V_98 , V_2 -> V_5 , 1 ) ;
if ( V_53 ) {
F_93 ( V_53 , V_162 , V_180 ,
V_181 |
V_182 |
V_189 ) ;
F_94 ( V_53 ) ;
}
V_170:
return;
}
static void F_101 ( struct V_1 * V_193 , struct V_10 * V_9 )
{
struct V_109 * V_110 = (struct V_109 * ) F_82 ( V_193 ) ;
struct V_1 * V_2 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
struct V_107 * V_107 = F_32 ( V_193 -> V_5 ) ;
int V_94 ;
int V_198 = F_102 ( sizeof( struct V_196 )
+ ( V_9 -> V_14 << 3 ) ) ;
T_4 V_199 = V_198 + F_103 ( sizeof( struct V_37 ) ) ;
V_2 = F_104 ( V_199 , V_177 ) ;
if ( V_2 == NULL ) {
V_94 = - V_200 ;
goto V_201;
}
V_195 = F_105 ( V_2 , 0 , 0 , V_202 , V_198 , 0 ) ;
if ( V_195 == NULL ) {
goto V_203;
}
V_197 = F_106 ( V_195 ) ;
V_197 -> V_204 = V_205 ;
V_197 -> V_206 = V_193 -> V_5 -> V_114 ;
V_197 -> V_207 = V_110 -> V_111 ;
V_197 -> V_208 = V_110 -> V_209 ;
V_197 -> V_210 = V_9 -> V_14 << 3 ;
memcpy ( V_197 + 1 , V_9 , V_9 -> V_14 << 3 ) ;
if ( F_107 ( V_2 , V_211 , sizeof( struct V_37 ) ,
& F_40 ( V_193 ) -> V_98 ) )
goto V_203;
F_108 ( V_2 , V_195 ) ;
F_109 ( V_2 , V_107 , 0 , V_212 , NULL , V_177 ) ;
return;
V_203:
F_110 ( V_2 ) ;
V_94 = - V_213 ;
V_201:
F_111 ( V_107 , V_212 , V_94 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_214 * V_214 = (struct V_214 * ) F_82 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
struct V_55 * V_56 ;
struct V_191 * V_192 = NULL ;
int V_215 ;
struct V_17 V_19 ;
int V_132 ;
unsigned int V_216 = 0 ;
T_5 * V_9 = ( T_5 * ) ( V_214 + 1 ) ;
V_132 = ( V_2 -> V_164 - V_2 -> V_165 ) - sizeof( struct V_214 ) ;
if ( ! ( F_113 ( & F_40 ( V_2 ) -> V_98 ) & V_217 ) ) {
F_9 ( 2 , V_27 , L_19 ) ;
return;
}
if ( V_132 < 0 ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
#ifdef F_114
if ( V_2 -> V_218 == V_219 ) {
F_9 ( 2 , V_27 , L_21 ) ;
return;
}
#endif
V_56 = F_25 ( V_2 -> V_5 ) ;
if ( V_56 == NULL ) {
F_9 ( 0 , V_94 , L_22 ,
V_2 -> V_5 -> V_185 ) ;
return;
}
if ( ! F_8 ( V_9 , V_132 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_23 ) ;
return;
}
if ( ! F_115 ( V_56 ) )
goto V_220;
#ifdef F_114
if ( V_2 -> V_218 == V_221 )
goto V_220;
#endif
if ( V_56 -> V_222 & V_223 ) {
V_56 -> V_222 |= V_224 ;
}
V_56 -> V_222 = ( V_56 -> V_222 & ~ ( V_225 |
V_226 ) ) |
( V_214 -> V_137 . V_227 ?
V_225 : 0 ) |
( V_214 -> V_137 . V_228 ?
V_226 : 0 ) ;
if ( ! V_56 -> V_134 . V_229 )
goto V_230;
if ( F_76 ( F_32 ( V_56 -> V_5 ) , & F_40 ( V_2 ) -> V_98 , NULL , 0 ) )
goto V_230;
V_215 = F_116 ( V_214 -> V_137 . V_231 ) ;
#ifdef F_117
V_216 = V_214 -> V_137 . V_232 ;
if ( V_216 == V_233 ||
! V_56 -> V_134 . V_234 )
V_216 = V_235 ;
#endif
V_192 = F_98 ( & F_40 ( V_2 ) -> V_98 , V_2 -> V_5 ) ;
if ( V_192 ) {
V_53 = F_118 ( & V_192 -> V_106 , & F_40 ( V_2 ) -> V_98 ) ;
if ( ! V_53 ) {
F_9 ( 0 , V_94 ,
L_24 ,
V_28 ) ;
F_119 ( V_192 ) ;
return;
}
}
if ( V_192 && V_215 == 0 ) {
F_99 ( V_192 ) ;
V_192 = NULL ;
}
if ( V_192 == NULL && V_215 ) {
F_9 ( 3 , V_157 , L_25 ) ;
V_192 = F_120 ( & F_40 ( V_2 ) -> V_98 , V_2 -> V_5 , V_216 ) ;
if ( V_192 == NULL ) {
F_9 ( 0 , V_94 ,
L_26 ,
V_28 ) ;
return;
}
V_53 = F_118 ( & V_192 -> V_106 , & F_40 ( V_2 ) -> V_98 ) ;
if ( V_53 == NULL ) {
F_9 ( 0 , V_94 ,
L_24 ,
V_28 ) ;
F_119 ( V_192 ) ;
return;
}
V_53 -> V_71 |= V_161 ;
} else if ( V_192 ) {
V_192 -> V_236 = ( V_192 -> V_236 & ~ V_237 ) | F_121 ( V_216 ) ;
}
if ( V_192 )
F_122 ( V_192 , V_238 + ( V_239 * V_215 ) ) ;
if ( V_214 -> V_137 . V_240 ) {
V_56 -> V_134 . V_100 = V_214 -> V_137 . V_240 ;
if ( V_192 )
F_123 ( & V_192 -> V_106 , V_241 ,
V_214 -> V_137 . V_240 ) ;
}
V_230:
if ( V_56 -> V_60 ) {
unsigned long V_242 = F_124 ( V_214 -> V_243 ) ;
if ( V_242 && V_242 / 1000 < V_244 / V_239 ) {
V_242 = ( V_242 * V_239 ) / 1000 ;
if ( V_242 < V_239 / 10 )
V_242 = V_239 / 10 ;
V_56 -> V_60 -> V_245 = V_242 ;
V_56 -> V_246 = V_238 ;
F_125 ( V_247 , V_56 ) ;
}
V_242 = F_124 ( V_214 -> V_248 ) ;
if ( V_242 && V_242 / 1000 < V_244 / ( 3 * V_239 ) ) {
V_242 = ( V_242 * V_239 ) / 1000 ;
if ( V_242 < V_239 / 10 )
V_242 = V_239 / 10 ;
if ( V_242 != V_56 -> V_60 -> V_249 ) {
V_56 -> V_60 -> V_249 = V_242 ;
V_56 -> V_60 -> V_250 = 3 * V_242 ;
V_56 -> V_60 -> V_248 = F_126 ( V_242 ) ;
V_56 -> V_246 = V_238 ;
F_125 ( V_247 , V_56 ) ;
}
}
}
V_220:
if ( ! V_53 )
V_53 = F_92 ( & V_160 , & F_40 ( V_2 ) -> V_98 ,
V_2 -> V_5 , 1 ) ;
if ( V_53 ) {
T_1 * V_162 = NULL ;
if ( V_19 . V_169 ) {
V_162 = F_85 ( V_19 . V_169 ,
V_2 -> V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_27 ) ;
goto V_170;
}
}
F_93 ( V_53 , V_162 , V_180 ,
V_181 |
V_182 |
V_189 |
V_190 ) ;
}
if ( ! F_115 ( V_56 ) )
goto V_170;
#ifdef F_10
if ( F_76 ( F_32 ( V_56 -> V_5 ) , & F_40 ( V_2 ) -> V_98 , NULL , 0 ) )
goto V_251;
if ( V_56 -> V_134 . V_234 && V_19 . V_33 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_33 ;
V_252 ;
V_252 = F_5 ( V_252 , V_19 . V_32 ) ) {
struct V_253 * V_254 = (struct V_253 * ) V_252 ;
#ifdef F_114
if ( V_2 -> V_218 == V_221 &&
V_254 -> V_255 == 0 )
continue;
#endif
if ( V_254 -> V_255 > V_56 -> V_134 . V_256 )
continue;
F_127 ( V_2 -> V_5 , ( T_1 * ) V_252 , ( V_252 -> V_14 ) << 3 ,
& F_40 ( V_2 ) -> V_98 ) ;
}
}
V_251:
#endif
#ifdef F_114
if ( V_2 -> V_218 == V_221 )
goto V_170;
#endif
if ( V_56 -> V_134 . V_257 && V_19 . V_258 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_258 ;
V_252 ;
V_252 = F_5 ( V_252 , V_19 . V_30 ) ) {
F_128 ( V_2 -> V_5 , ( T_1 * ) V_252 ,
( V_252 -> V_14 ) << 3 ,
V_19 . V_169 != NULL ) ;
}
}
if ( V_19 . V_259 ) {
T_6 V_83 ;
T_2 V_260 ;
memcpy ( & V_83 , ( ( T_1 * ) ( V_19 . V_259 + 1 ) ) + 2 , sizeof( V_260 ) ) ;
V_260 = F_124 ( V_83 ) ;
if ( V_260 < V_261 || V_260 > V_2 -> V_5 -> V_260 ) {
F_9 ( 2 , V_27 , L_28 , V_260 ) ;
} else if ( V_56 -> V_134 . V_262 != V_260 ) {
V_56 -> V_134 . V_262 = V_260 ;
if ( V_192 )
F_123 ( & V_192 -> V_106 , V_263 , V_260 ) ;
F_129 ( V_2 -> V_5 , V_260 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_252 ;
for ( V_252 = V_19 . V_35 ;
V_252 ;
V_252 = F_7 ( V_252 , V_19 . V_34 ) ) {
F_101 ( V_2 , V_252 ) ;
}
}
if ( V_19 . V_183 || V_19 . V_264 ) {
F_9 ( 2 , V_27 , L_29 ) ;
}
V_170:
F_119 ( V_192 ) ;
if ( V_53 )
F_94 ( V_53 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
T_1 * V_101 ;
struct V_17 V_19 ;
struct V_265 * V_131 = (struct V_265 * ) F_82 ( V_2 ) ;
T_2 V_163 = V_2 -> V_164 - ( V_2 -> V_165 +
F_83 ( struct V_265 , V_9 ) ) ;
#ifdef F_114
switch ( V_2 -> V_218 ) {
case V_219 :
case V_221 :
F_9 ( 2 , V_27 ,
L_30 ) ;
return;
}
#endif
if ( ! ( F_113 ( & F_40 ( V_2 ) -> V_98 ) & V_217 ) ) {
F_9 ( 2 , V_27 ,
L_31 ) ;
return;
}
if ( ! F_8 ( V_131 -> V_9 , V_163 , & V_19 ) )
return;
if ( ! V_19 . V_264 )
return;
V_101 = ( T_1 * ) V_19 . V_264 ;
V_101 += 8 ;
if ( ! F_131 ( V_2 , V_101 - F_82 ( V_2 ) ) )
return;
F_132 ( V_2 , V_266 , 0 , 0 ) ;
}
static void F_133 ( struct V_1 * V_2 ,
struct V_1 * V_267 ,
int V_268 )
{
T_1 * V_9 = F_4 ( V_2 , V_268 ) ;
memset ( V_9 , 0 , 8 ) ;
* ( V_9 ++ ) = V_25 ;
* ( V_9 ++ ) = ( V_268 >> 3 ) ;
V_9 += 6 ;
memcpy ( V_9 , F_40 ( V_267 ) , V_268 - 8 ) ;
}
void F_134 ( struct V_1 * V_2 , const struct V_37 * V_142 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
struct V_90 * V_91 = V_107 -> V_92 . V_93 ;
int V_132 = 0 ;
struct V_269 * V_270 ;
struct V_1 * V_271 ;
struct V_265 * V_131 ;
struct V_37 V_272 ;
struct V_191 * V_192 ;
struct V_105 * V_106 ;
struct V_112 V_113 ;
int V_268 ;
T_1 V_273 [ V_274 ] , * V_70 = NULL ;
bool V_159 ;
if ( F_68 ( V_5 , & V_272 , V_149 ) ) {
F_9 ( 2 , V_27 , L_32 ,
V_5 -> V_185 ) ;
return;
}
if ( ! F_135 ( & F_40 ( V_2 ) -> V_99 , V_142 ) &&
F_113 ( V_142 ) != ( V_275 | V_217 ) ) {
F_9 ( 2 , V_27 ,
L_33 ) ;
return;
}
F_45 ( V_91 , & V_113 , V_266 ,
& V_272 , & F_40 ( V_2 ) -> V_98 , V_5 -> V_114 ) ;
V_106 = F_136 ( V_107 , NULL , & V_113 ) ;
if ( V_106 -> error ) {
F_137 ( V_106 ) ;
return;
}
V_106 = F_138 ( V_107 , V_106 , F_139 ( & V_113 ) , NULL , 0 ) ;
if ( F_47 ( V_106 ) )
return;
V_192 = (struct V_191 * ) V_106 ;
if ( V_192 -> V_236 & V_276 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_277;
}
V_270 = F_140 ( V_107 -> V_92 . V_278 , & V_192 -> V_279 . V_38 , 1 ) ;
V_159 = F_141 ( V_270 , 1 * V_239 ) ;
if ( V_270 )
F_142 ( V_270 ) ;
if ( ! V_159 )
goto V_277;
if ( V_5 -> V_7 ) {
struct V_52 * V_53 = F_118 ( F_43 ( V_2 ) , V_142 ) ;
if ( ! V_53 ) {
F_9 ( 2 , V_27 ,
L_35 ) ;
goto V_277;
}
F_64 ( & V_53 -> V_144 ) ;
if ( V_53 -> V_64 & V_80 ) {
memcpy ( V_273 , V_53 -> V_70 , V_5 -> V_7 ) ;
F_66 ( & V_53 -> V_144 ) ;
V_70 = V_273 ;
V_132 += F_3 ( V_5 ) ;
} else
F_66 ( & V_53 -> V_144 ) ;
F_94 ( V_53 ) ;
}
V_268 = F_143 (unsigned int,
IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(*msg) - optlen,
skb->len + 8 ) ;
V_268 &= ~ 0x7 ;
V_132 += V_268 ;
V_271 = F_30 ( V_5 , sizeof( * V_131 ) + V_132 ) ;
if ( ! V_271 )
goto V_277;
V_131 = (struct V_265 * ) F_4 ( V_271 , sizeof( * V_131 ) ) ;
* V_131 = (struct V_265 ) {
. V_137 = {
. V_111 = V_266 ,
} ,
. V_142 = * V_142 ,
. V_280 = F_40 ( V_2 ) -> V_99 ,
} ;
if ( V_70 )
F_1 ( V_271 , V_23 , V_70 ) ;
if ( V_268 )
F_133 ( V_271 , V_2 , V_268 ) ;
F_49 ( V_271 , V_106 ) ;
F_42 ( V_271 , & F_40 ( V_2 ) -> V_98 , & V_272 ) ;
return;
V_277:
F_137 ( V_106 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
F_48 ( V_2 ) ;
}
int F_145 ( struct V_1 * V_2 )
{
struct V_130 * V_131 ;
if ( F_146 ( V_2 ) )
return 0 ;
V_131 = (struct V_130 * ) F_82 ( V_2 ) ;
F_147 ( V_2 , V_2 -> V_3 - F_82 ( V_2 ) ) ;
if ( F_40 ( V_2 ) -> V_100 != 255 ) {
F_9 ( 2 , V_27 , L_36 ,
F_40 ( V_2 ) -> V_100 ) ;
return 0 ;
}
if ( V_131 -> V_137 . V_209 != 0 ) {
F_9 ( 2 , V_27 , L_37 ,
V_131 -> V_137 . V_209 ) ;
return 0 ;
}
memset ( F_88 ( V_2 ) , 0 , sizeof( struct V_281 ) ) ;
switch ( V_131 -> V_137 . V_111 ) {
case V_150 :
F_81 ( V_2 ) ;
break;
case V_138 :
F_95 ( V_2 ) ;
break;
case V_153 :
F_100 ( V_2 ) ;
break;
case V_282 :
F_112 ( V_2 ) ;
break;
case V_266 :
F_130 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_148 ( struct V_283 * V_284 , unsigned long V_285 , void * V_286 )
{
struct V_40 * V_5 = V_286 ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
struct V_55 * V_108 ;
switch ( V_285 ) {
case V_287 :
F_149 ( & V_160 , V_5 ) ;
F_150 ( ~ 0UL , V_107 ) ;
V_108 = F_20 ( V_5 ) ;
if ( ! V_108 )
break;
if ( V_108 -> V_134 . V_288 )
F_63 ( V_5 ) ;
F_23 ( V_108 ) ;
break;
case V_289 :
F_151 ( & V_160 , V_5 ) ;
F_150 ( ~ 0UL , V_107 ) ;
break;
case V_290 :
F_63 ( V_5 ) ;
break;
default:
break;
}
return V_291 ;
}
static void F_152 ( struct V_292 * V_293 ,
const char * V_294 , const char * V_295 )
{
static char V_296 [ V_297 ] ;
static int V_298 ;
if ( strcmp ( V_296 , V_299 -> V_300 ) && V_298 < 5 ) {
strcpy ( V_296 , V_299 -> V_300 ) ;
F_153 ( L_38 ,
V_296 , V_294 ,
V_295 , V_293 -> V_301 ,
V_295 , V_293 -> V_301 ) ;
V_298 ++ ;
}
}
int F_154 ( struct V_292 * V_293 , int V_302 , void T_7 * V_303 , T_4 * V_304 , T_8 * V_305 )
{
struct V_40 * V_5 = V_293 -> V_306 ;
struct V_55 * V_108 ;
int V_159 ;
if ( ( strcmp ( V_293 -> V_301 , L_39 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_40 ) == 0 ) )
F_152 ( V_293 , L_41 , V_5 ? V_5 -> V_185 : L_42 ) ;
if ( strcmp ( V_293 -> V_301 , L_39 ) == 0 )
V_159 = F_155 ( V_293 , V_302 , V_303 , V_304 , V_305 ) ;
else if ( strcmp ( V_293 -> V_301 , L_40 ) == 0 )
V_159 = F_156 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else if ( ( strcmp ( V_293 -> V_301 , L_43 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_44 ) == 0 ) )
V_159 = F_157 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else
V_159 = - 1 ;
if ( V_302 && V_159 == 0 && V_5 && ( V_108 = F_20 ( V_5 ) ) != NULL ) {
if ( V_293 -> V_3 == & V_108 -> V_60 -> V_249 )
V_108 -> V_60 -> V_248 = F_126 ( V_108 -> V_60 -> V_249 ) ;
V_108 -> V_246 = V_238 ;
F_125 ( V_247 , V_108 ) ;
F_23 ( V_108 ) ;
}
return V_159 ;
}
static int T_9 F_158 ( struct V_107 * V_107 )
{
struct V_307 * V_308 ;
struct V_90 * V_91 ;
int V_94 ;
V_94 = F_159 ( & V_91 , V_309 ,
V_310 , V_104 , V_107 ) ;
if ( V_94 < 0 ) {
F_9 ( 0 , V_94 ,
L_45 ,
V_94 ) ;
return V_94 ;
}
V_107 -> V_92 . V_93 = V_91 ;
V_308 = F_52 ( V_91 ) ;
V_308 -> V_100 = 255 ;
V_308 -> V_311 = 0 ;
return 0 ;
}
static void T_10 F_160 ( struct V_107 * V_107 )
{
F_161 ( V_107 -> V_92 . V_93 ) ;
}
int T_11 F_162 ( void )
{
int V_94 ;
V_94 = F_163 ( & V_312 ) ;
if ( V_94 )
return V_94 ;
F_164 ( & V_160 ) ;
#ifdef F_165
V_94 = F_166 ( NULL , & V_160 . V_58 , L_46 ,
& F_154 ) ;
if ( V_94 )
goto V_313;
#endif
V_94 = F_167 ( & V_314 ) ;
if ( V_94 )
goto V_315;
V_170:
return V_94 ;
V_315:
#ifdef F_165
F_168 ( & V_160 . V_58 ) ;
V_313:
#endif
F_169 ( & V_312 ) ;
goto V_170;
}
void F_170 ( void )
{
F_171 ( & V_314 ) ;
#ifdef F_165
F_168 ( & V_160 . V_58 ) ;
#endif
F_172 ( & V_160 ) ;
F_169 ( & V_312 ) ;
}
