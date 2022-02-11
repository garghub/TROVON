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
V_124 = false ;
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
V_125 = false ;
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
T_2 V_163 = F_83 ( V_2 ) - ( F_82 ( V_2 ) +
F_84 ( struct V_130 , V_9 ) ) ;
struct V_17 V_19 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_127 * V_128 ;
struct V_55 * V_108 = NULL ;
struct V_52 * V_53 ;
int V_164 = F_69 ( V_98 ) ;
bool V_165 ;
int V_166 = - 1 ;
if ( V_2 -> V_86 < sizeof( struct V_130 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( F_19 ( & V_131 -> V_142 ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( V_164 && ! F_85 ( V_99 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( ! F_8 ( V_131 -> V_9 , V_163 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_8 ) ;
return;
}
if ( V_19 . V_167 ) {
V_162 = F_86 ( V_19 . V_167 , V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_9 ) ;
return;
}
if ( V_164 ) {
F_9 ( 2 , V_27 ,
L_10 ) ;
return;
}
}
V_165 = F_19 ( V_99 ) ;
V_128 = F_60 ( F_32 ( V_5 ) , & V_131 -> V_142 , V_5 , 1 ) ;
if ( V_128 ) {
if ( V_128 -> V_71 & ( V_149 | V_133 ) ) {
if ( V_164 ) {
F_87 ( V_128 ) ;
return;
} else {
if ( ! ( V_128 -> V_71 & V_133 ) )
goto V_168;
}
}
V_108 = V_128 -> V_108 ;
} else {
struct V_107 * V_107 = F_32 ( V_5 ) ;
V_108 = F_20 ( V_5 ) ;
if ( ! V_108 ) {
return;
}
if ( F_88 ( V_107 , V_5 , & V_131 -> V_142 ) ||
( V_108 -> V_134 . V_146 &&
( V_107 -> V_92 . V_169 -> V_170 || V_108 -> V_134 . V_170 ) &&
( V_166 = F_79 ( & V_131 -> V_142 , V_5 ) ) >= 0 ) ) {
if ( ! ( F_89 ( V_2 ) -> V_71 & V_171 ) &&
V_2 -> V_172 != V_173 &&
V_165 &&
V_108 -> V_60 -> V_174 != 0 ) {
struct V_1 * V_83 = F_90 ( V_2 , V_175 ) ;
if ( V_83 )
F_91 ( & V_160 , V_108 -> V_60 , V_83 ) ;
goto V_168;
}
} else
goto V_168;
}
if ( V_166 < 0 )
V_166 = V_108 -> V_134 . V_146 ;
if ( V_164 ) {
F_59 ( V_5 , NULL , & V_145 , & V_131 -> V_142 ,
! ! V_166 , false , ( V_128 != NULL ) , true ) ;
goto V_168;
}
if ( V_165 )
F_92 ( & V_160 , V_176 ) ;
else
F_92 ( & V_160 , V_177 ) ;
V_53 = F_93 ( & V_160 , V_98 , V_5 ,
! V_165 || V_162 || ! V_5 -> V_7 ) ;
if ( V_53 )
F_94 ( V_53 , V_162 , V_178 ,
V_179 |
V_180 ) ;
if ( V_53 || ! V_5 -> V_63 ) {
F_59 ( V_5 , V_53 , V_98 , & V_131 -> V_142 ,
! ! V_166 ,
true , ( V_128 != NULL && V_165 ) , V_165 ) ;
if ( V_53 )
F_95 ( V_53 ) ;
}
V_168:
if ( V_128 )
F_61 ( V_128 ) ;
else
F_23 ( V_108 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_130 * V_131 = (struct V_130 * ) F_82 ( V_2 ) ;
const struct V_37 * V_98 = & F_40 ( V_2 ) -> V_98 ;
const struct V_37 * V_99 = & F_40 ( V_2 ) -> V_99 ;
T_1 * V_162 = NULL ;
T_2 V_163 = F_83 ( V_2 ) - ( F_82 ( V_2 ) +
F_84 ( struct V_130 , V_9 ) ) ;
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
if ( V_19 . V_181 ) {
V_162 = F_86 ( V_19 . V_181 , V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_15 ) ;
return;
}
}
V_128 = F_60 ( F_32 ( V_5 ) , & V_131 -> V_142 , V_5 , 1 ) ;
if ( V_128 ) {
if ( V_2 -> V_172 != V_182
&& ( V_128 -> V_71 & V_149 ) ) {
F_87 ( V_128 ) ;
return;
}
if ( V_2 -> V_172 != V_182 )
F_9 ( 1 , V_27 ,
L_16 ,
& V_128 -> V_38 , V_128 -> V_108 -> V_5 -> V_183 ) ;
F_61 ( V_128 ) ;
return;
}
V_53 = F_97 ( & V_160 , & V_131 -> V_142 , V_5 ) ;
if ( V_53 ) {
T_1 V_184 = V_53 -> V_71 ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
if ( V_53 -> V_64 & V_185 )
goto V_168;
if ( V_162 && ! memcmp ( V_162 , V_5 -> V_74 , V_5 -> V_7 ) &&
V_107 -> V_92 . V_169 -> V_146 && V_107 -> V_92 . V_169 -> V_170 &&
F_98 ( & V_160 , V_107 , & V_131 -> V_142 , V_5 , 0 ) ) {
goto V_168;
}
F_94 ( V_53 , V_162 ,
V_131 -> V_137 . V_140 ? V_186 : V_178 ,
V_179 |
( V_131 -> V_137 . V_141 ? V_180 : 0 ) |
V_187 |
( V_131 -> V_137 . V_139 ? V_188 : 0 ) ) ;
if ( ( V_184 & ~ V_53 -> V_71 ) & V_161 ) {
struct V_189 * V_190 ;
V_190 = F_99 ( V_98 , V_5 ) ;
if ( V_190 )
F_100 ( V_190 ) ;
}
V_168:
F_95 ( V_53 ) ;
}
}
static void F_101 ( struct V_1 * V_2 )
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
goto V_168;
if ( F_69 ( V_98 ) )
goto V_168;
if ( ! F_8 ( V_151 -> V_9 , V_163 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_18 ) ;
goto V_168;
}
if ( V_19 . V_167 ) {
V_162 = F_86 ( V_19 . V_167 ,
V_2 -> V_5 ) ;
if ( ! V_162 )
goto V_168;
}
V_53 = F_93 ( & V_160 , V_98 , V_2 -> V_5 , 1 ) ;
if ( V_53 ) {
F_94 ( V_53 , V_162 , V_178 ,
V_179 |
V_180 |
V_187 ) ;
F_95 ( V_53 ) ;
}
V_168:
return;
}
static void F_102 ( struct V_1 * V_191 , struct V_10 * V_9 )
{
struct V_109 * V_110 = (struct V_109 * ) F_82 ( V_191 ) ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
struct V_107 * V_107 = F_32 ( V_191 -> V_5 ) ;
int V_94 ;
int V_196 = F_103 ( sizeof( struct V_194 )
+ ( V_9 -> V_14 << 3 ) ) ;
T_4 V_197 = V_196 + F_104 ( sizeof( struct V_37 ) ) ;
V_2 = F_105 ( V_197 , V_175 ) ;
if ( V_2 == NULL ) {
V_94 = - V_198 ;
goto V_199;
}
V_193 = F_106 ( V_2 , 0 , 0 , V_200 , V_196 , 0 ) ;
if ( V_193 == NULL ) {
goto V_201;
}
V_195 = F_107 ( V_193 ) ;
V_195 -> V_202 = V_203 ;
V_195 -> V_204 = V_191 -> V_5 -> V_114 ;
V_195 -> V_205 = V_110 -> V_111 ;
V_195 -> V_206 = V_110 -> V_207 ;
V_195 -> V_208 = V_9 -> V_14 << 3 ;
memcpy ( V_195 + 1 , V_9 , V_9 -> V_14 << 3 ) ;
if ( F_108 ( V_2 , V_209 , sizeof( struct V_37 ) ,
& F_40 ( V_191 ) -> V_98 ) )
goto V_201;
F_109 ( V_2 , V_193 ) ;
F_110 ( V_2 , V_107 , 0 , V_210 , NULL , V_175 ) ;
return;
V_201:
F_111 ( V_2 ) ;
V_94 = - V_211 ;
V_199:
F_112 ( V_107 , V_210 , V_94 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_212 * V_212 = (struct V_212 * ) F_82 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
struct V_55 * V_56 ;
struct V_189 * V_190 = NULL ;
int V_213 ;
struct V_17 V_19 ;
int V_132 ;
unsigned int V_214 = 0 ;
T_5 * V_9 = ( T_5 * ) ( V_212 + 1 ) ;
V_132 = ( F_83 ( V_2 ) - F_82 ( V_2 ) ) -
sizeof( struct V_212 ) ;
if ( ! ( F_114 ( & F_40 ( V_2 ) -> V_98 ) & V_215 ) ) {
F_9 ( 2 , V_27 , L_19 ) ;
return;
}
if ( V_132 < 0 ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
#ifdef F_115
if ( V_2 -> V_216 == V_217 ) {
F_9 ( 2 , V_27 , L_21 ) ;
return;
}
#endif
V_56 = F_25 ( V_2 -> V_5 ) ;
if ( V_56 == NULL ) {
F_9 ( 0 , V_94 , L_22 ,
V_2 -> V_5 -> V_183 ) ;
return;
}
if ( ! F_8 ( V_9 , V_132 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_23 ) ;
return;
}
if ( ! F_116 ( V_56 ) )
goto V_218;
#ifdef F_115
if ( V_2 -> V_216 == V_219 )
goto V_218;
#endif
if ( V_56 -> V_220 & V_221 ) {
V_56 -> V_220 |= V_222 ;
}
V_56 -> V_220 = ( V_56 -> V_220 & ~ ( V_223 |
V_224 ) ) |
( V_212 -> V_137 . V_225 ?
V_223 : 0 ) |
( V_212 -> V_137 . V_226 ?
V_224 : 0 ) ;
if ( ! V_56 -> V_134 . V_227 )
goto V_228;
if ( F_76 ( F_32 ( V_56 -> V_5 ) , & F_40 ( V_2 ) -> V_98 , NULL , 0 ) )
goto V_228;
V_213 = F_117 ( V_212 -> V_137 . V_229 ) ;
#ifdef F_118
V_214 = V_212 -> V_137 . V_230 ;
if ( V_214 == V_231 ||
! V_56 -> V_134 . V_232 )
V_214 = V_233 ;
#endif
V_190 = F_99 ( & F_40 ( V_2 ) -> V_98 , V_2 -> V_5 ) ;
if ( V_190 ) {
V_53 = F_119 ( & V_190 -> V_106 , & F_40 ( V_2 ) -> V_98 ) ;
if ( ! V_53 ) {
F_9 ( 0 , V_94 ,
L_24 ,
V_28 ) ;
F_120 ( V_190 ) ;
return;
}
}
if ( V_190 && V_213 == 0 ) {
F_100 ( V_190 ) ;
V_190 = NULL ;
}
if ( V_190 == NULL && V_213 ) {
F_9 ( 3 , V_157 , L_25 ) ;
V_190 = F_121 ( & F_40 ( V_2 ) -> V_98 , V_2 -> V_5 , V_214 ) ;
if ( V_190 == NULL ) {
F_9 ( 0 , V_94 ,
L_26 ,
V_28 ) ;
return;
}
V_53 = F_119 ( & V_190 -> V_106 , & F_40 ( V_2 ) -> V_98 ) ;
if ( V_53 == NULL ) {
F_9 ( 0 , V_94 ,
L_24 ,
V_28 ) ;
F_120 ( V_190 ) ;
return;
}
V_53 -> V_71 |= V_161 ;
} else if ( V_190 ) {
V_190 -> V_234 = ( V_190 -> V_234 & ~ V_235 ) | F_122 ( V_214 ) ;
}
if ( V_190 )
F_123 ( V_190 , V_236 + ( V_237 * V_213 ) ) ;
if ( V_212 -> V_137 . V_238 ) {
V_56 -> V_134 . V_100 = V_212 -> V_137 . V_238 ;
if ( V_190 )
F_124 ( & V_190 -> V_106 , V_239 ,
V_212 -> V_137 . V_238 ) ;
}
V_228:
if ( V_56 -> V_60 ) {
unsigned long V_240 = F_125 ( V_212 -> V_241 ) ;
if ( V_240 && V_240 / 1000 < V_242 / V_237 ) {
V_240 = ( V_240 * V_237 ) / 1000 ;
if ( V_240 < V_237 / 10 )
V_240 = V_237 / 10 ;
V_56 -> V_60 -> V_243 = V_240 ;
V_56 -> V_244 = V_236 ;
F_126 ( V_245 , V_56 ) ;
}
V_240 = F_125 ( V_212 -> V_246 ) ;
if ( V_240 && V_240 / 1000 < V_242 / ( 3 * V_237 ) ) {
V_240 = ( V_240 * V_237 ) / 1000 ;
if ( V_240 < V_237 / 10 )
V_240 = V_237 / 10 ;
if ( V_240 != V_56 -> V_60 -> V_247 ) {
V_56 -> V_60 -> V_247 = V_240 ;
V_56 -> V_60 -> V_248 = 3 * V_240 ;
V_56 -> V_60 -> V_246 = F_127 ( V_240 ) ;
V_56 -> V_244 = V_236 ;
F_126 ( V_245 , V_56 ) ;
}
}
}
V_218:
if ( ! V_53 )
V_53 = F_93 ( & V_160 , & F_40 ( V_2 ) -> V_98 ,
V_2 -> V_5 , 1 ) ;
if ( V_53 ) {
T_1 * V_162 = NULL ;
if ( V_19 . V_167 ) {
V_162 = F_86 ( V_19 . V_167 ,
V_2 -> V_5 ) ;
if ( ! V_162 ) {
F_9 ( 2 , V_27 ,
L_27 ) ;
goto V_168;
}
}
F_94 ( V_53 , V_162 , V_178 ,
V_179 |
V_180 |
V_187 |
V_188 ) ;
}
if ( ! F_116 ( V_56 ) )
goto V_168;
#ifdef F_10
if ( F_76 ( F_32 ( V_56 -> V_5 ) , & F_40 ( V_2 ) -> V_98 , NULL , 0 ) )
goto V_249;
if ( V_56 -> V_134 . V_232 && V_19 . V_33 ) {
struct V_10 * V_250 ;
for ( V_250 = V_19 . V_33 ;
V_250 ;
V_250 = F_5 ( V_250 , V_19 . V_32 ) ) {
struct V_251 * V_252 = (struct V_251 * ) V_250 ;
#ifdef F_115
if ( V_2 -> V_216 == V_219 &&
V_252 -> V_253 == 0 )
continue;
#endif
if ( V_252 -> V_253 > V_56 -> V_134 . V_254 )
continue;
F_128 ( V_2 -> V_5 , ( T_1 * ) V_250 , ( V_250 -> V_14 ) << 3 ,
& F_40 ( V_2 ) -> V_98 ) ;
}
}
V_249:
#endif
#ifdef F_115
if ( V_2 -> V_216 == V_219 )
goto V_168;
#endif
if ( V_56 -> V_134 . V_255 && V_19 . V_256 ) {
struct V_10 * V_250 ;
for ( V_250 = V_19 . V_256 ;
V_250 ;
V_250 = F_5 ( V_250 , V_19 . V_30 ) ) {
F_129 ( V_2 -> V_5 , ( T_1 * ) V_250 ,
( V_250 -> V_14 ) << 3 ,
V_19 . V_167 != NULL ) ;
}
}
if ( V_19 . V_257 ) {
T_6 V_83 ;
T_2 V_258 ;
memcpy ( & V_83 , ( ( T_1 * ) ( V_19 . V_257 + 1 ) ) + 2 , sizeof( V_258 ) ) ;
V_258 = F_125 ( V_83 ) ;
if ( V_258 < V_259 || V_258 > V_2 -> V_5 -> V_258 ) {
F_9 ( 2 , V_27 , L_28 , V_258 ) ;
} else if ( V_56 -> V_134 . V_260 != V_258 ) {
V_56 -> V_134 . V_260 = V_258 ;
if ( V_190 )
F_124 ( & V_190 -> V_106 , V_261 , V_258 ) ;
F_130 ( V_2 -> V_5 , V_258 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_250 ;
for ( V_250 = V_19 . V_35 ;
V_250 ;
V_250 = F_7 ( V_250 , V_19 . V_34 ) ) {
F_102 ( V_2 , V_250 ) ;
}
}
if ( V_19 . V_181 || V_19 . V_262 ) {
F_9 ( 2 , V_27 , L_29 ) ;
}
V_168:
F_120 ( V_190 ) ;
if ( V_53 )
F_95 ( V_53 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
T_1 * V_101 ;
struct V_17 V_19 ;
struct V_263 * V_131 = (struct V_263 * ) F_82 ( V_2 ) ;
T_2 V_163 = F_83 ( V_2 ) - ( F_82 ( V_2 ) +
F_84 ( struct V_263 , V_9 ) ) ;
#ifdef F_115
switch ( V_2 -> V_216 ) {
case V_217 :
case V_219 :
F_9 ( 2 , V_27 ,
L_30 ) ;
return;
}
#endif
if ( ! ( F_114 ( & F_40 ( V_2 ) -> V_98 ) & V_215 ) ) {
F_9 ( 2 , V_27 ,
L_31 ) ;
return;
}
if ( ! F_8 ( V_131 -> V_9 , V_163 , & V_19 ) )
return;
if ( ! V_19 . V_262 ) {
F_132 ( V_2 , F_32 ( V_2 -> V_5 ) , 0 , 0 ) ;
return;
}
V_101 = ( T_1 * ) V_19 . V_262 ;
V_101 += 8 ;
if ( ! F_133 ( V_2 , V_101 - F_82 ( V_2 ) ) )
return;
F_134 ( V_2 , V_264 , 0 , 0 ) ;
}
static void F_135 ( struct V_1 * V_2 ,
struct V_1 * V_265 ,
int V_266 )
{
T_1 * V_9 = F_4 ( V_2 , V_266 ) ;
memset ( V_9 , 0 , 8 ) ;
* ( V_9 ++ ) = V_25 ;
* ( V_9 ++ ) = ( V_266 >> 3 ) ;
V_9 += 6 ;
memcpy ( V_9 , F_40 ( V_265 ) , V_266 - 8 ) ;
}
void F_136 ( struct V_1 * V_2 , const struct V_37 * V_142 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
struct V_90 * V_91 = V_107 -> V_92 . V_93 ;
int V_132 = 0 ;
struct V_267 * V_268 ;
struct V_1 * V_269 ;
struct V_263 * V_131 ;
struct V_37 V_270 ;
struct V_189 * V_190 ;
struct V_105 * V_106 ;
struct V_112 V_113 ;
int V_266 ;
T_1 V_271 [ V_272 ] , * V_70 = NULL ;
bool V_159 ;
if ( F_68 ( V_5 , & V_270 , V_149 ) ) {
F_9 ( 2 , V_27 , L_32 ,
V_5 -> V_183 ) ;
return;
}
if ( ! F_137 ( & F_40 ( V_2 ) -> V_99 , V_142 ) &&
F_114 ( V_142 ) != ( V_273 | V_215 ) ) {
F_9 ( 2 , V_27 ,
L_33 ) ;
return;
}
F_45 ( V_91 , & V_113 , V_264 ,
& V_270 , & F_40 ( V_2 ) -> V_98 , V_5 -> V_114 ) ;
V_106 = F_138 ( V_107 , NULL , & V_113 ) ;
if ( V_106 -> error ) {
F_139 ( V_106 ) ;
return;
}
V_106 = F_140 ( V_107 , V_106 , F_141 ( & V_113 ) , NULL , 0 ) ;
if ( F_47 ( V_106 ) )
return;
V_190 = (struct V_189 * ) V_106 ;
if ( V_190 -> V_234 & V_274 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_275;
}
V_268 = F_142 ( V_107 -> V_92 . V_276 , & V_190 -> V_277 . V_38 , 1 ) ;
V_159 = F_143 ( V_268 , 1 * V_237 ) ;
if ( V_268 )
F_144 ( V_268 ) ;
if ( ! V_159 )
goto V_275;
if ( V_5 -> V_7 ) {
struct V_52 * V_53 = F_119 ( F_43 ( V_2 ) , V_142 ) ;
if ( ! V_53 ) {
F_9 ( 2 , V_27 ,
L_35 ) ;
goto V_275;
}
F_64 ( & V_53 -> V_144 ) ;
if ( V_53 -> V_64 & V_80 ) {
memcpy ( V_271 , V_53 -> V_70 , V_5 -> V_7 ) ;
F_66 ( & V_53 -> V_144 ) ;
V_70 = V_271 ;
V_132 += F_3 ( V_5 ) ;
} else
F_66 ( & V_53 -> V_144 ) ;
F_95 ( V_53 ) ;
}
V_266 = F_145 (unsigned int,
IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(*msg) - optlen,
skb->len + 8 ) ;
V_266 &= ~ 0x7 ;
V_132 += V_266 ;
V_269 = F_30 ( V_5 , sizeof( * V_131 ) + V_132 ) ;
if ( ! V_269 )
goto V_275;
V_131 = (struct V_263 * ) F_4 ( V_269 , sizeof( * V_131 ) ) ;
* V_131 = (struct V_263 ) {
. V_137 = {
. V_111 = V_264 ,
} ,
. V_142 = * V_142 ,
. V_278 = F_40 ( V_2 ) -> V_99 ,
} ;
if ( V_70 )
F_1 ( V_269 , V_23 , V_70 ) ;
if ( V_266 )
F_135 ( V_269 , V_2 , V_266 ) ;
F_49 ( V_269 , V_106 ) ;
F_42 ( V_269 , & F_40 ( V_2 ) -> V_98 , & V_270 ) ;
return;
V_275:
F_139 ( V_106 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
F_48 ( V_2 ) ;
}
int F_147 ( struct V_1 * V_2 )
{
struct V_130 * V_131 ;
if ( F_148 ( V_2 ) )
return 0 ;
V_131 = (struct V_130 * ) F_82 ( V_2 ) ;
F_149 ( V_2 , V_2 -> V_3 - F_82 ( V_2 ) ) ;
if ( F_40 ( V_2 ) -> V_100 != 255 ) {
F_9 ( 2 , V_27 , L_36 ,
F_40 ( V_2 ) -> V_100 ) ;
return 0 ;
}
if ( V_131 -> V_137 . V_207 != 0 ) {
F_9 ( 2 , V_27 , L_37 ,
V_131 -> V_137 . V_207 ) ;
return 0 ;
}
memset ( F_89 ( V_2 ) , 0 , sizeof( struct V_279 ) ) ;
switch ( V_131 -> V_137 . V_111 ) {
case V_150 :
F_81 ( V_2 ) ;
break;
case V_138 :
F_96 ( V_2 ) ;
break;
case V_153 :
F_101 ( V_2 ) ;
break;
case V_280 :
F_113 ( V_2 ) ;
break;
case V_264 :
F_131 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_150 ( struct V_281 * V_282 , unsigned long V_283 , void * V_284 )
{
struct V_40 * V_5 = F_151 ( V_284 ) ;
struct V_107 * V_107 = F_32 ( V_5 ) ;
struct V_55 * V_108 ;
switch ( V_283 ) {
case V_285 :
F_152 ( & V_160 , V_5 ) ;
F_153 ( 0 , V_107 , false ) ;
V_108 = F_20 ( V_5 ) ;
if ( ! V_108 )
break;
if ( V_108 -> V_134 . V_286 )
F_63 ( V_5 ) ;
F_23 ( V_108 ) ;
break;
case V_287 :
F_154 ( & V_160 , V_5 ) ;
F_153 ( 0 , V_107 , false ) ;
break;
case V_288 :
F_63 ( V_5 ) ;
break;
default:
break;
}
return V_289 ;
}
static void F_155 ( struct V_290 * V_291 ,
const char * V_292 , const char * V_293 )
{
static char V_294 [ V_295 ] ;
static int V_296 ;
if ( strcmp ( V_294 , V_297 -> V_298 ) && V_296 < 5 ) {
strcpy ( V_294 , V_297 -> V_298 ) ;
F_156 ( L_38 ,
V_294 , V_292 ,
V_293 , V_291 -> V_299 ,
V_293 , V_291 -> V_299 ) ;
V_296 ++ ;
}
}
int F_157 ( struct V_290 * V_291 , int V_300 , void T_7 * V_301 , T_4 * V_302 , T_8 * V_303 )
{
struct V_40 * V_5 = V_291 -> V_304 ;
struct V_55 * V_108 ;
int V_159 ;
if ( ( strcmp ( V_291 -> V_299 , L_39 ) == 0 ) ||
( strcmp ( V_291 -> V_299 , L_40 ) == 0 ) )
F_155 ( V_291 , L_41 , V_5 ? V_5 -> V_183 : L_42 ) ;
if ( strcmp ( V_291 -> V_299 , L_39 ) == 0 )
V_159 = F_158 ( V_291 , V_300 , V_301 , V_302 , V_303 ) ;
else if ( strcmp ( V_291 -> V_299 , L_40 ) == 0 )
V_159 = F_159 ( V_291 , V_300 ,
V_301 , V_302 , V_303 ) ;
else if ( ( strcmp ( V_291 -> V_299 , L_43 ) == 0 ) ||
( strcmp ( V_291 -> V_299 , L_44 ) == 0 ) )
V_159 = F_160 ( V_291 , V_300 ,
V_301 , V_302 , V_303 ) ;
else
V_159 = - 1 ;
if ( V_300 && V_159 == 0 && V_5 && ( V_108 = F_20 ( V_5 ) ) != NULL ) {
if ( V_291 -> V_3 == & V_108 -> V_60 -> V_247 )
V_108 -> V_60 -> V_246 = F_127 ( V_108 -> V_60 -> V_247 ) ;
V_108 -> V_244 = V_236 ;
F_126 ( V_245 , V_108 ) ;
F_23 ( V_108 ) ;
}
return V_159 ;
}
static int T_9 F_161 ( struct V_107 * V_107 )
{
struct V_305 * V_306 ;
struct V_90 * V_91 ;
int V_94 ;
V_94 = F_162 ( & V_91 , V_307 ,
V_308 , V_104 , V_107 ) ;
if ( V_94 < 0 ) {
F_9 ( 0 , V_94 ,
L_45 ,
V_94 ) ;
return V_94 ;
}
V_107 -> V_92 . V_93 = V_91 ;
V_306 = F_52 ( V_91 ) ;
V_306 -> V_100 = 255 ;
V_306 -> V_309 = 0 ;
return 0 ;
}
static void T_10 F_163 ( struct V_107 * V_107 )
{
F_164 ( V_107 -> V_92 . V_93 ) ;
}
int T_11 F_165 ( void )
{
int V_94 ;
V_94 = F_166 ( & V_310 ) ;
if ( V_94 )
return V_94 ;
F_167 ( & V_160 ) ;
#ifdef F_168
V_94 = F_169 ( NULL , & V_160 . V_58 , L_46 ,
& F_157 ) ;
if ( V_94 )
goto V_311;
#endif
V_94 = F_170 ( & V_312 ) ;
if ( V_94 )
goto V_313;
V_168:
return V_94 ;
V_313:
#ifdef F_168
F_171 ( & V_160 . V_58 ) ;
V_311:
#endif
F_172 ( & V_310 ) ;
goto V_168;
}
void F_173 ( void )
{
F_174 ( & V_312 ) ;
#ifdef F_168
F_171 ( & V_160 . V_58 ) ;
#endif
F_175 ( & V_160 ) ;
F_172 ( & V_310 ) ;
}
