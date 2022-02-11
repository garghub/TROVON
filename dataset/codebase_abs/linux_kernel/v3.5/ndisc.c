static int F_1 ( unsigned short type )
{
switch ( type ) {
case V_1 : return 2 ;
default: return 0 ;
}
}
static inline int F_2 ( struct V_2 * V_3 )
{
return F_3 ( V_3 -> V_4 + F_1 ( V_3 -> type ) ) ;
}
static T_1 * F_4 ( T_1 * V_5 , int type , void * V_6 , int V_7 ,
unsigned short V_8 )
{
int V_9 = F_3 ( V_7 ) ;
int V_10 = F_1 ( V_8 ) ;
V_5 [ 0 ] = type ;
V_5 [ 1 ] = V_9 >> 3 ;
memset ( V_5 + 2 , 0 , V_10 ) ;
V_5 += V_10 ;
V_9 -= V_10 ;
memcpy ( V_5 + 2 , V_6 , V_7 ) ;
V_7 += 2 ;
V_5 += V_7 ;
if ( ( V_9 -= V_7 ) > 0 )
memset ( V_5 , 0 , V_9 ) ;
return V_5 + V_9 ;
}
static struct V_11 * F_5 ( struct V_11 * V_12 ,
struct V_11 * V_13 )
{
int type ;
if ( ! V_12 || ! V_13 || V_12 >= V_13 )
return NULL ;
type = V_12 -> V_14 ;
do {
V_12 = ( ( void * ) V_12 ) + ( V_12 -> V_15 << 3 ) ;
} while( V_12 < V_13 && V_12 -> V_14 != type );
return V_12 <= V_13 && V_12 -> V_14 == type ? V_12 : NULL ;
}
static inline int F_6 ( struct V_11 * V_5 )
{
return V_5 -> V_14 == V_16 ||
V_5 -> V_14 == V_17 ;
}
static struct V_11 * F_7 ( struct V_11 * V_12 ,
struct V_11 * V_13 )
{
if ( ! V_12 || ! V_13 || V_12 >= V_13 )
return NULL ;
do {
V_12 = ( ( void * ) V_12 ) + ( V_12 -> V_15 << 3 ) ;
} while( V_12 < V_13 && ! F_6 ( V_12 ) );
return V_12 <= V_13 && F_6 ( V_12 ) ? V_12 : NULL ;
}
static struct V_18 * F_8 ( T_1 * V_5 , int V_19 ,
struct V_18 * V_20 )
{
struct V_11 * V_21 = (struct V_11 * ) V_5 ;
if ( ! V_21 || V_19 < 0 || ! V_20 )
return NULL ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
while ( V_19 ) {
int V_22 ;
if ( V_19 < sizeof( struct V_11 ) )
return NULL ;
V_22 = V_21 -> V_15 << 3 ;
if ( V_19 < V_22 || V_22 == 0 )
return NULL ;
switch ( V_21 -> V_14 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
if ( V_20 -> V_27 [ V_21 -> V_14 ] ) {
F_9 ( 2 , V_28 ,
L_1 ,
V_29 , V_21 -> V_14 ) ;
} else {
V_20 -> V_27 [ V_21 -> V_14 ] = V_21 ;
}
break;
case V_30 :
V_20 -> V_31 = V_21 ;
if ( ! V_20 -> V_27 [ V_21 -> V_14 ] )
V_20 -> V_27 [ V_21 -> V_14 ] = V_21 ;
break;
#ifdef F_10
case V_32 :
V_20 -> V_33 = V_21 ;
if ( ! V_20 -> V_34 )
V_20 -> V_34 = V_21 ;
break;
#endif
default:
if ( F_6 ( V_21 ) ) {
V_20 -> V_35 = V_21 ;
if ( ! V_20 -> V_36 )
V_20 -> V_36 = V_21 ;
} else {
F_9 ( 2 , V_37 ,
L_2 ,
V_29 ,
V_21 -> V_14 ,
V_21 -> V_15 ) ;
}
}
V_19 -= V_22 ;
V_21 = ( ( void * ) V_21 ) + V_22 ;
}
return V_20 ;
}
static inline T_1 * F_11 ( struct V_11 * V_38 ,
struct V_2 * V_3 )
{
T_1 * V_39 = ( T_1 * ) ( V_38 + 1 ) ;
int V_40 = V_38 -> V_15 << 3 ;
int V_41 = F_1 ( V_3 -> type ) ;
if ( V_40 != F_3 ( V_3 -> V_4 + V_41 ) )
return NULL ;
return V_39 + V_41 ;
}
int F_12 ( const struct V_42 * V_43 , char * V_44 , struct V_2 * V_3 , int V_45 )
{
switch ( V_3 -> type ) {
case V_46 :
case V_47 :
case V_48 :
F_13 ( V_43 , V_44 ) ;
return 0 ;
case V_49 :
F_14 ( V_43 , V_44 ) ;
return 0 ;
case V_1 :
F_15 ( V_43 , V_3 -> V_50 , V_44 ) ;
return 0 ;
case V_51 :
return F_16 ( V_43 , V_3 -> V_50 , V_44 ) ;
default:
if ( V_45 ) {
memcpy ( V_44 , V_3 -> V_50 , V_3 -> V_4 ) ;
return 0 ;
}
}
return - V_52 ;
}
static T_2 F_17 ( const void * V_53 ,
const struct V_2 * V_3 ,
T_3 * V_54 )
{
return F_18 ( V_53 , V_3 , V_54 ) ;
}
static int F_19 ( struct V_55 * V_56 )
{
struct V_42 * V_43 = (struct V_42 * ) & V_56 -> V_57 ;
struct V_2 * V_3 = V_56 -> V_3 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
bool V_62 = F_20 ( V_43 ) ;
V_59 = F_21 ( V_3 ) ;
if ( V_59 == NULL ) {
return - V_52 ;
}
V_61 = V_59 -> V_63 ;
F_22 ( V_56 -> V_61 ) ;
V_56 -> V_61 = F_23 ( V_61 ) ;
V_56 -> type = V_62 ? V_64 : V_65 ;
if ( ! V_3 -> V_66 ) {
V_56 -> V_67 = V_68 ;
V_56 -> V_69 = & V_70 ;
V_56 -> V_71 = V_72 ;
} else {
if ( V_62 ) {
V_56 -> V_67 = V_68 ;
F_12 ( V_43 , V_56 -> V_73 , V_3 , 1 ) ;
} else if ( V_3 -> V_74 & ( V_75 | V_76 ) ) {
V_56 -> V_67 = V_68 ;
memcpy ( V_56 -> V_73 , V_3 -> V_77 , V_3 -> V_4 ) ;
if ( V_3 -> V_74 & V_76 )
V_56 -> type = V_78 ;
} else if ( V_3 -> V_74 & V_79 ) {
V_56 -> V_67 = V_68 ;
memcpy ( V_56 -> V_73 , V_3 -> V_50 , V_3 -> V_4 ) ;
}
if ( V_3 -> V_66 -> V_80 )
V_56 -> V_69 = & V_81 ;
else
V_56 -> V_69 = & V_82 ;
if ( V_56 -> V_67 & V_83 )
V_56 -> V_71 = V_56 -> V_69 -> V_84 ;
else
V_56 -> V_71 = V_56 -> V_69 -> V_71 ;
}
F_24 ( V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_85 * V_86 )
{
struct V_42 * V_43 = (struct V_42 * ) & V_86 -> V_87 ;
struct V_42 V_88 ;
struct V_2 * V_3 = V_86 -> V_3 ;
if ( V_3 == NULL || F_26 ( V_3 ) == NULL )
return - V_52 ;
F_27 ( V_43 , & V_88 ) ;
F_28 ( V_3 , & V_88 ) ;
return 0 ;
}
static void F_29 ( struct V_85 * V_86 )
{
struct V_42 * V_43 = (struct V_42 * ) & V_86 -> V_87 ;
struct V_42 V_88 ;
struct V_2 * V_3 = V_86 -> V_3 ;
if ( V_3 == NULL || F_26 ( V_3 ) == NULL )
return;
F_27 ( V_43 , & V_88 ) ;
F_30 ( V_3 , & V_88 ) ;
}
struct V_89 * F_31 ( struct V_2 * V_3 ,
const struct V_42 * V_90 ,
const struct V_42 * V_91 ,
struct V_92 * V_93 ,
const struct V_42 * V_94 ,
int V_95 )
{
struct V_96 * V_96 = F_32 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
struct V_89 * V_101 ;
struct V_92 * V_102 ;
int V_103 = F_33 ( V_3 ) ;
int V_104 = V_3 -> V_105 ;
int V_106 ;
int V_107 ;
T_1 * V_5 ;
if ( ! V_3 -> V_4 )
V_95 = 0 ;
V_106 = sizeof( struct V_92 ) + ( V_94 ? sizeof( * V_94 ) : 0 ) ;
if ( V_95 )
V_106 += F_2 ( V_3 ) ;
V_101 = F_34 ( V_98 ,
( V_108 + sizeof( struct V_109 ) +
V_106 + V_103 + V_104 ) ,
1 , & V_107 ) ;
if ( ! V_101 ) {
F_9 ( 0 , V_107 , L_3 ,
V_29 , V_107 ) ;
return NULL ;
}
F_35 ( V_101 , V_103 ) ;
F_36 ( V_98 , V_101 , V_3 , V_91 , V_90 , V_110 , V_106 ) ;
V_101 -> V_111 = V_101 -> V_112 ;
F_37 ( V_101 , V_106 ) ;
V_102 = (struct V_92 * ) F_38 ( V_101 ) ;
memcpy ( V_102 , V_93 , sizeof( * V_102 ) ) ;
V_5 = F_38 ( V_101 ) + sizeof( struct V_92 ) ;
if ( V_94 ) {
* (struct V_42 * ) V_5 = * V_94 ;
V_5 += sizeof( * V_94 ) ;
}
if ( V_95 )
F_4 ( V_5 , V_95 , V_3 -> V_77 ,
V_3 -> V_4 , V_3 -> type ) ;
V_102 -> V_113 = F_39 ( V_91 , V_90 , V_106 ,
V_110 ,
F_40 ( V_102 ,
V_106 , 0 ) ) ;
return V_101 ;
}
void F_41 ( struct V_89 * V_101 ,
struct V_2 * V_3 ,
struct V_55 * V_56 ,
const struct V_42 * V_90 ,
const struct V_42 * V_91 ,
struct V_92 * V_93 )
{
struct V_114 V_115 ;
struct V_116 * V_117 ;
struct V_96 * V_96 = F_32 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
struct V_58 * V_118 ;
int V_107 ;
T_1 type ;
type = V_93 -> V_119 ;
F_42 ( V_98 , & V_115 , type , V_91 , V_90 , V_3 -> V_120 ) ;
V_117 = F_43 ( V_3 , V_56 , & V_115 ) ;
if ( F_44 ( V_117 ) ) {
F_45 ( V_101 ) ;
return;
}
F_46 ( V_101 , V_117 ) ;
F_47 () ;
V_118 = F_26 ( V_117 -> V_3 ) ;
F_48 ( V_96 , V_118 , V_121 , V_101 -> V_106 ) ;
V_107 = F_49 ( V_122 , V_123 , V_101 , NULL , V_117 -> V_3 ,
V_124 ) ;
if ( ! V_107 ) {
F_50 ( V_96 , V_118 , type ) ;
F_51 ( V_96 , V_118 , V_125 ) ;
}
F_52 () ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
const struct V_42 * V_90 ,
const struct V_42 * V_91 ,
struct V_92 * V_93 , const struct V_42 * V_94 ,
int V_95 )
{
struct V_89 * V_101 ;
V_101 = F_31 ( V_3 , V_90 , V_91 , V_93 , V_94 , V_95 ) ;
if ( ! V_101 )
return;
F_41 ( V_101 , V_3 , V_56 , V_90 , V_91 , V_93 ) ;
}
static void F_54 ( struct V_2 * V_3 , struct V_55 * V_56 ,
const struct V_42 * V_90 ,
const struct V_42 * V_126 ,
int V_127 , int V_128 , int V_129 , int V_130 )
{
struct V_42 V_131 ;
struct V_132 * V_133 ;
const struct V_42 * V_134 ;
struct V_92 V_93 = {
. V_119 = V_135 ,
} ;
V_133 = F_55 ( F_32 ( V_3 ) , V_126 , V_3 , 1 ) ;
if ( V_133 ) {
V_134 = V_126 ;
if ( V_133 -> V_74 & V_136 )
V_129 = 0 ;
V_130 |= V_133 -> V_118 -> V_137 . V_138 ;
F_56 ( V_133 ) ;
} else {
if ( F_57 ( F_32 ( V_3 ) , V_3 , V_90 ,
F_58 ( F_32 ( V_3 ) -> V_99 . V_100 ) -> V_139 ,
& V_131 ) )
return;
V_134 = & V_131 ;
}
V_93 . V_140 = V_127 ;
V_93 . V_141 = V_128 ;
V_93 . V_142 = V_129 ;
F_53 ( V_3 , V_56 , V_90 , V_134 ,
& V_93 , V_126 ,
V_130 ? V_24 : 0 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_58 * V_118 ;
struct V_132 * V_143 ;
struct V_42 V_144 ;
V_118 = F_21 ( V_3 ) ;
if ( ! V_118 )
return;
F_60 ( & V_118 -> V_145 ) ;
F_61 (ifa, &idev->addr_list, if_list) {
F_27 ( & V_143 -> V_43 , & V_144 ) ;
F_54 ( V_3 , NULL , & V_144 , & V_143 -> V_43 ,
! ! V_118 -> V_137 . V_146 ,
false , true ,
true ) ;
}
F_62 ( & V_118 -> V_145 ) ;
F_24 ( V_118 ) ;
}
void F_63 ( struct V_2 * V_3 , struct V_55 * V_56 ,
const struct V_42 * V_147 ,
const struct V_42 * V_90 , const struct V_42 * V_91 )
{
struct V_42 V_148 ;
struct V_92 V_93 = {
. V_119 = V_149 ,
} ;
if ( V_91 == NULL ) {
if ( F_64 ( V_3 , & V_148 ,
( V_150 | V_136 ) ) )
return;
V_91 = & V_148 ;
}
F_53 ( V_3 , V_56 , V_90 , V_91 ,
& V_93 , V_147 ,
! F_65 ( V_91 ) ? V_23 : 0 ) ;
}
void F_66 ( struct V_2 * V_3 , const struct V_42 * V_91 ,
const struct V_42 * V_90 )
{
struct V_92 V_93 = {
. V_119 = V_151 ,
} ;
int V_152 = V_3 -> V_4 ;
#ifdef F_67
if ( V_152 ) {
struct V_132 * V_133 = F_55 ( F_32 ( V_3 ) , V_91 ,
V_3 , 1 ) ;
if ( V_133 ) {
if ( V_133 -> V_74 & V_136 ) {
V_152 = 0 ;
}
F_56 ( V_133 ) ;
} else {
V_152 = 0 ;
}
}
#endif
F_53 ( V_3 , NULL , V_90 , V_91 ,
& V_93 , NULL ,
V_152 ? V_23 : 0 ) ;
}
static void F_68 ( struct V_55 * V_56 , struct V_89 * V_101 )
{
F_69 ( V_101 ) ;
F_45 ( V_101 ) ;
}
static void F_70 ( struct V_55 * V_56 , struct V_89 * V_101 )
{
struct V_42 * V_91 = NULL ;
struct V_42 V_144 ;
struct V_2 * V_3 = V_56 -> V_3 ;
struct V_42 * V_94 = (struct V_42 * ) & V_56 -> V_57 ;
int V_153 = F_71 ( & V_56 -> V_153 ) ;
if ( V_101 && F_72 ( F_32 ( V_3 ) , & F_73 ( V_101 ) -> V_91 , V_3 , 1 ) )
V_91 = & F_73 ( V_101 ) -> V_91 ;
if ( ( V_153 -= V_56 -> V_61 -> V_154 ) < 0 ) {
if ( ! ( V_56 -> V_67 & V_83 ) ) {
F_9 ( 1 , V_155 ,
L_4 ,
V_29 , V_94 ) ;
}
F_63 ( V_3 , V_56 , V_94 , V_94 , V_91 ) ;
} else if ( ( V_153 -= V_56 -> V_61 -> V_156 ) < 0 ) {
#ifdef F_74
F_75 ( V_56 ) ;
#endif
} else {
F_27 ( V_94 , & V_144 ) ;
F_63 ( V_3 , NULL , V_94 , & V_144 , V_91 ) ;
}
}
static int F_76 ( const void * V_53 ,
struct V_2 * V_3 )
{
struct V_85 * V_86 ;
int V_157 = - 1 ;
F_60 ( & V_158 . V_145 ) ;
V_86 = F_77 ( & V_158 , F_32 ( V_3 ) , V_53 , V_3 ) ;
if ( V_86 )
V_157 = ! ! ( V_86 -> V_74 & V_159 ) ;
F_62 ( & V_158 . V_145 ) ;
return V_157 ;
}
static void F_78 ( struct V_89 * V_101 )
{
struct V_160 * V_161 = (struct V_160 * ) F_38 ( V_101 ) ;
const struct V_42 * V_91 = & F_73 ( V_101 ) -> V_91 ;
const struct V_42 * V_90 = & F_73 ( V_101 ) -> V_90 ;
T_1 * V_39 = NULL ;
T_2 V_162 = V_101 -> V_112 - ( V_101 -> V_111 +
F_79 ( struct V_160 , V_5 ) ) ;
struct V_18 V_20 ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_132 * V_133 ;
struct V_58 * V_118 = NULL ;
struct V_55 * V_56 ;
int V_163 = F_65 ( V_91 ) ;
bool V_164 ;
int V_165 = - 1 ;
if ( F_20 ( & V_161 -> V_94 ) ) {
F_9 ( 2 , V_28 , L_5 ) ;
return;
}
if ( V_163 &&
! ( V_90 -> V_166 [ 0 ] == F_80 ( 0xff020000 ) &&
V_90 -> V_166 [ 1 ] == F_80 ( 0x00000000 ) &&
V_90 -> V_166 [ 2 ] == F_80 ( 0x00000001 ) &&
V_90 -> V_167 [ 12 ] == 0xff ) ) {
F_9 ( 2 , V_28 , L_6 ) ;
return;
}
if ( ! F_8 ( V_161 -> V_5 , V_162 , & V_20 ) ) {
F_9 ( 2 , V_28 , L_7 ) ;
return;
}
if ( V_20 . V_168 ) {
V_39 = F_11 ( V_20 . V_168 , V_3 ) ;
if ( ! V_39 ) {
F_9 ( 2 , V_28 ,
L_8 ) ;
return;
}
if ( V_163 ) {
F_9 ( 2 , V_28 ,
L_9 ) ;
return;
}
}
V_164 = F_20 ( V_90 ) ;
V_133 = F_55 ( F_32 ( V_3 ) , & V_161 -> V_94 , V_3 , 1 ) ;
if ( V_133 ) {
if ( V_133 -> V_74 & ( V_150 | V_136 ) ) {
if ( V_163 ) {
F_81 ( V_133 ) ;
return;
} else {
if ( ! ( V_133 -> V_74 & V_136 ) )
goto V_169;
}
}
V_118 = V_133 -> V_118 ;
} else {
struct V_96 * V_96 = F_32 ( V_3 ) ;
V_118 = F_21 ( V_3 ) ;
if ( ! V_118 ) {
return;
}
if ( F_82 ( V_96 , V_3 , & V_161 -> V_94 ) ||
( V_118 -> V_137 . V_146 &&
( V_96 -> V_99 . V_170 -> V_171 || V_118 -> V_137 . V_171 ) &&
( V_165 = F_76 ( & V_161 -> V_94 , V_3 ) ) >= 0 ) ) {
if ( ! ( F_83 ( V_101 ) -> V_74 & V_172 ) &&
V_101 -> V_173 != V_174 &&
V_164 != 0 &&
V_118 -> V_63 -> V_175 != 0 ) {
struct V_89 * V_86 = F_84 ( V_101 , V_176 ) ;
if ( V_86 )
F_85 ( & V_158 , V_118 -> V_63 , V_86 ) ;
goto V_169;
}
} else
goto V_169;
}
if ( V_165 < 0 )
V_165 = ! ! V_118 -> V_137 . V_146 ;
if ( V_163 ) {
F_54 ( V_3 , NULL , & V_177 , & V_161 -> V_94 ,
V_165 , 0 , ( V_133 != NULL ) , 1 ) ;
goto V_169;
}
if ( V_164 )
F_86 ( & V_158 , V_178 ) ;
else
F_86 ( & V_158 , V_179 ) ;
V_56 = F_87 ( & V_158 , V_91 , V_3 ,
! V_164 || V_39 || ! V_3 -> V_4 ) ;
if ( V_56 )
F_88 ( V_56 , V_39 , V_180 ,
V_181 |
V_182 ) ;
if ( V_56 || ! V_3 -> V_66 ) {
F_54 ( V_3 , V_56 , V_91 , & V_161 -> V_94 ,
V_165 ,
1 , ( V_133 != NULL && V_164 ) , V_164 ) ;
if ( V_56 )
F_89 ( V_56 ) ;
}
V_169:
if ( V_133 )
F_56 ( V_133 ) ;
else
F_24 ( V_118 ) ;
}
static void F_90 ( struct V_89 * V_101 )
{
struct V_160 * V_161 = (struct V_160 * ) F_38 ( V_101 ) ;
const struct V_42 * V_91 = & F_73 ( V_101 ) -> V_91 ;
const struct V_42 * V_90 = & F_73 ( V_101 ) -> V_90 ;
T_1 * V_39 = NULL ;
T_2 V_162 = V_101 -> V_112 - ( V_101 -> V_111 +
F_79 ( struct V_160 , V_5 ) ) ;
struct V_18 V_20 ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_132 * V_133 ;
struct V_55 * V_56 ;
if ( V_101 -> V_106 < sizeof( struct V_160 ) ) {
F_9 ( 2 , V_28 , L_10 ) ;
return;
}
if ( F_20 ( & V_161 -> V_94 ) ) {
F_9 ( 2 , V_28 , L_11 ) ;
return;
}
if ( F_20 ( V_90 ) &&
V_161 -> V_183 . V_141 ) {
F_9 ( 2 , V_28 , L_12 ) ;
return;
}
if ( ! F_8 ( V_161 -> V_5 , V_162 , & V_20 ) ) {
F_9 ( 2 , V_28 , L_13 ) ;
return;
}
if ( V_20 . V_184 ) {
V_39 = F_11 ( V_20 . V_184 , V_3 ) ;
if ( ! V_39 ) {
F_9 ( 2 , V_28 ,
L_14 ) ;
return;
}
}
V_133 = F_55 ( F_32 ( V_3 ) , & V_161 -> V_94 , V_3 , 1 ) ;
if ( V_133 ) {
if ( V_101 -> V_173 != V_185
&& ( V_133 -> V_74 & V_150 ) ) {
F_81 ( V_133 ) ;
return;
}
if ( V_101 -> V_173 != V_185 )
F_9 ( 1 , V_28 ,
L_15 ,
& V_133 -> V_43 , V_133 -> V_118 -> V_3 -> V_186 ) ;
F_56 ( V_133 ) ;
return;
}
V_56 = F_91 ( & V_158 , & V_161 -> V_94 , V_3 ) ;
if ( V_56 ) {
T_1 V_187 = V_56 -> V_74 ;
struct V_96 * V_96 = F_32 ( V_3 ) ;
if ( V_56 -> V_67 & V_188 )
goto V_169;
if ( V_39 && ! memcmp ( V_39 , V_3 -> V_77 , V_3 -> V_4 ) &&
V_96 -> V_99 . V_170 -> V_146 && V_96 -> V_99 . V_170 -> V_171 &&
F_92 ( & V_158 , V_96 , & V_161 -> V_94 , V_3 , 0 ) ) {
goto V_169;
}
F_88 ( V_56 , V_39 ,
V_161 -> V_183 . V_141 ? V_189 : V_180 ,
V_181 |
( V_161 -> V_183 . V_142 ? V_182 : 0 ) |
V_190 |
( V_161 -> V_183 . V_140 ? V_191 : 0 ) ) ;
if ( ( V_187 & ~ V_56 -> V_74 ) & V_159 ) {
struct V_192 * V_193 ;
V_193 = F_93 ( V_91 , V_3 ) ;
if ( V_193 )
F_94 ( V_193 ) ;
}
V_169:
F_89 ( V_56 ) ;
}
}
static void F_95 ( struct V_89 * V_101 )
{
struct V_194 * V_194 = (struct V_194 * ) F_38 ( V_101 ) ;
unsigned long V_162 = V_101 -> V_106 - sizeof( * V_194 ) ;
struct V_55 * V_56 ;
struct V_58 * V_118 ;
const struct V_42 * V_91 = & F_73 ( V_101 ) -> V_91 ;
struct V_18 V_20 ;
T_1 * V_39 = NULL ;
if ( V_101 -> V_106 < sizeof( * V_194 ) )
return;
V_118 = F_26 ( V_101 -> V_3 ) ;
if ( ! V_118 ) {
F_9 ( 1 , V_107 , L_16 ) ;
return;
}
if ( ! V_118 -> V_137 . V_146 )
goto V_169;
if ( F_65 ( V_91 ) )
goto V_169;
if ( ! F_8 ( V_194 -> V_5 , V_162 , & V_20 ) ) {
F_9 ( 2 , V_37 , L_17 ) ;
goto V_169;
}
if ( V_20 . V_168 ) {
V_39 = F_11 ( V_20 . V_168 ,
V_101 -> V_3 ) ;
if ( ! V_39 )
goto V_169;
}
V_56 = F_87 ( & V_158 , V_91 , V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
F_88 ( V_56 , V_39 , V_180 ,
V_181 |
V_182 |
V_190 ) ;
F_89 ( V_56 ) ;
}
V_169:
return;
}
static void F_96 ( struct V_89 * V_195 , struct V_11 * V_5 )
{
struct V_92 * V_93 = (struct V_92 * ) F_38 ( V_195 ) ;
struct V_89 * V_101 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_96 * V_96 = F_32 ( V_195 -> V_3 ) ;
int V_107 ;
int V_200 = F_97 ( sizeof( struct V_198 )
+ ( V_5 -> V_15 << 3 ) ) ;
T_4 V_201 = V_200 + F_98 ( sizeof( struct V_42 ) ) ;
V_101 = F_99 ( V_201 , V_176 ) ;
if ( V_101 == NULL ) {
V_107 = - V_202 ;
goto V_203;
}
V_197 = F_100 ( V_101 , 0 , 0 , V_204 , V_200 , 0 ) ;
if ( V_197 == NULL ) {
goto V_205;
}
V_199 = F_101 ( V_197 ) ;
V_199 -> V_206 = V_207 ;
V_199 -> V_208 = V_195 -> V_3 -> V_120 ;
V_199 -> V_209 = V_93 -> V_119 ;
V_199 -> V_210 = V_93 -> V_211 ;
V_199 -> V_212 = V_5 -> V_15 << 3 ;
memcpy ( V_199 + 1 , V_5 , V_5 -> V_15 << 3 ) ;
if ( F_102 ( V_101 , V_213 , sizeof( struct V_42 ) ,
& F_73 ( V_195 ) -> V_91 ) )
goto V_205;
F_103 ( V_101 , V_197 ) ;
F_104 ( V_101 , V_96 , 0 , V_214 , NULL , V_176 ) ;
return;
V_205:
F_105 ( V_101 ) ;
V_107 = - V_215 ;
V_203:
F_106 ( V_96 , V_214 , V_107 ) ;
}
static inline int F_107 ( struct V_58 * V_59 )
{
if ( V_59 -> V_137 . V_146 && V_59 -> V_137 . F_107 < 2 )
return 0 ;
return V_59 -> V_137 . F_107 ;
}
static void F_108 ( struct V_89 * V_101 )
{
struct V_216 * V_216 = (struct V_216 * ) F_38 ( V_101 ) ;
struct V_55 * V_56 = NULL ;
struct V_58 * V_59 ;
struct V_192 * V_193 = NULL ;
int V_217 ;
struct V_18 V_20 ;
int V_218 ;
unsigned int V_219 = 0 ;
T_5 * V_5 = ( T_5 * ) ( V_216 + 1 ) ;
V_218 = ( V_101 -> V_112 - V_101 -> V_111 ) - sizeof( struct V_216 ) ;
if ( ! ( F_109 ( & F_73 ( V_101 ) -> V_91 ) & V_220 ) ) {
F_9 ( 2 , V_28 , L_18 ) ;
return;
}
if ( V_218 < 0 ) {
F_9 ( 2 , V_28 , L_19 ) ;
return;
}
#ifdef F_110
if ( V_101 -> V_221 == V_222 ) {
F_9 ( 2 , V_28 , L_20 ) ;
return;
}
#endif
V_59 = F_26 ( V_101 -> V_3 ) ;
if ( V_59 == NULL ) {
F_9 ( 0 , V_107 , L_21 ,
V_101 -> V_3 -> V_186 ) ;
return;
}
if ( ! F_8 ( V_5 , V_218 , & V_20 ) ) {
F_9 ( 2 , V_28 , L_22 ) ;
return;
}
if ( ! F_107 ( V_59 ) )
goto V_223;
#ifdef F_110
if ( V_101 -> V_221 == V_224 )
goto V_223;
#endif
if ( V_59 -> V_225 & V_226 ) {
V_59 -> V_225 |= V_227 ;
}
V_59 -> V_225 = ( V_59 -> V_225 & ~ ( V_228 |
V_229 ) ) |
( V_216 -> V_183 . V_230 ?
V_228 : 0 ) |
( V_216 -> V_183 . V_231 ?
V_229 : 0 ) ;
if ( ! V_59 -> V_137 . V_232 )
goto V_233;
if ( F_72 ( F_32 ( V_59 -> V_3 ) , & F_73 ( V_101 ) -> V_91 , NULL , 0 ) )
goto V_233;
V_217 = F_111 ( V_216 -> V_183 . V_234 ) ;
#ifdef F_112
V_219 = V_216 -> V_183 . V_235 ;
if ( V_219 == V_236 ||
! V_59 -> V_137 . V_237 )
V_219 = V_238 ;
#endif
V_193 = F_93 ( & F_73 ( V_101 ) -> V_91 , V_101 -> V_3 ) ;
if ( V_193 ) {
V_56 = F_113 ( & V_193 -> V_117 , & F_73 ( V_101 ) -> V_91 ) ;
if ( ! V_56 ) {
F_9 ( 0 , V_107 ,
L_23 ,
V_29 ) ;
F_114 ( & V_193 -> V_117 ) ;
return;
}
}
if ( V_193 && V_217 == 0 ) {
F_94 ( V_193 ) ;
V_193 = NULL ;
}
if ( V_193 == NULL && V_217 ) {
F_9 ( 3 , V_155 , L_24 ) ;
V_193 = F_115 ( & F_73 ( V_101 ) -> V_91 , V_101 -> V_3 , V_219 ) ;
if ( V_193 == NULL ) {
F_9 ( 0 , V_107 ,
L_25 ,
V_29 ) ;
return;
}
V_56 = F_113 ( & V_193 -> V_117 , & F_73 ( V_101 ) -> V_91 ) ;
if ( V_56 == NULL ) {
F_9 ( 0 , V_107 ,
L_23 ,
V_29 ) ;
F_114 ( & V_193 -> V_117 ) ;
return;
}
V_56 -> V_74 |= V_159 ;
} else if ( V_193 ) {
V_193 -> V_239 = ( V_193 -> V_239 & ~ V_240 ) | F_116 ( V_219 ) ;
}
if ( V_193 )
F_117 ( V_193 , V_241 + ( V_242 * V_217 ) ) ;
if ( V_216 -> V_183 . V_243 ) {
V_59 -> V_137 . V_244 = V_216 -> V_183 . V_243 ;
if ( V_193 )
F_118 ( & V_193 -> V_117 , V_245 ,
V_216 -> V_183 . V_243 ) ;
}
V_233:
if ( V_59 -> V_63 ) {
unsigned long V_246 = F_119 ( V_216 -> V_247 ) ;
if ( V_246 && V_246 / 1000 < V_248 / V_242 ) {
V_246 = ( V_246 * V_242 ) / 1000 ;
if ( V_246 < V_242 / 10 )
V_246 = V_242 / 10 ;
V_59 -> V_63 -> V_249 = V_246 ;
V_59 -> V_250 = V_241 ;
F_120 ( V_251 , V_59 ) ;
}
V_246 = F_119 ( V_216 -> V_252 ) ;
if ( V_246 && V_246 / 1000 < V_248 / ( 3 * V_242 ) ) {
V_246 = ( V_246 * V_242 ) / 1000 ;
if ( V_246 < V_242 / 10 )
V_246 = V_242 / 10 ;
if ( V_246 != V_59 -> V_63 -> V_253 ) {
V_59 -> V_63 -> V_253 = V_246 ;
V_59 -> V_63 -> V_254 = 3 * V_246 ;
V_59 -> V_63 -> V_252 = F_121 ( V_246 ) ;
V_59 -> V_250 = V_241 ;
F_120 ( V_251 , V_59 ) ;
}
}
}
V_223:
if ( ! V_56 )
V_56 = F_87 ( & V_158 , & F_73 ( V_101 ) -> V_91 ,
V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
T_1 * V_39 = NULL ;
if ( V_20 . V_168 ) {
V_39 = F_11 ( V_20 . V_168 ,
V_101 -> V_3 ) ;
if ( ! V_39 ) {
F_9 ( 2 , V_28 ,
L_26 ) ;
goto V_169;
}
}
F_88 ( V_56 , V_39 , V_180 ,
V_181 |
V_182 |
V_190 |
V_191 ) ;
}
if ( ! F_107 ( V_59 ) )
goto V_169;
#ifdef F_10
if ( F_72 ( F_32 ( V_59 -> V_3 ) , & F_73 ( V_101 ) -> V_91 , NULL , 0 ) )
goto V_255;
if ( V_59 -> V_137 . V_237 && V_20 . V_34 ) {
struct V_11 * V_38 ;
for ( V_38 = V_20 . V_34 ;
V_38 ;
V_38 = F_5 ( V_38 , V_20 . V_33 ) ) {
struct V_256 * V_257 = (struct V_256 * ) V_38 ;
#ifdef F_110
if ( V_101 -> V_221 == V_224 &&
V_257 -> V_258 == 0 )
continue;
#endif
if ( V_257 -> V_258 > V_59 -> V_137 . V_259 )
continue;
F_122 ( V_101 -> V_3 , ( T_1 * ) V_38 , ( V_38 -> V_15 ) << 3 ,
& F_73 ( V_101 ) -> V_91 ) ;
}
}
V_255:
#endif
#ifdef F_110
if ( V_101 -> V_221 == V_224 )
goto V_169;
#endif
if ( V_59 -> V_137 . V_260 && V_20 . V_261 ) {
struct V_11 * V_38 ;
for ( V_38 = V_20 . V_261 ;
V_38 ;
V_38 = F_5 ( V_38 , V_20 . V_31 ) ) {
F_123 ( V_101 -> V_3 , ( T_1 * ) V_38 ,
( V_38 -> V_15 ) << 3 ,
V_20 . V_168 != NULL ) ;
}
}
if ( V_20 . V_262 ) {
T_6 V_86 ;
T_2 V_263 ;
memcpy ( & V_86 , ( ( T_1 * ) ( V_20 . V_262 + 1 ) ) + 2 , sizeof( V_263 ) ) ;
V_263 = F_119 ( V_86 ) ;
if ( V_263 < V_264 || V_263 > V_101 -> V_3 -> V_263 ) {
F_9 ( 2 , V_28 , L_27 , V_263 ) ;
} else if ( V_59 -> V_137 . V_265 != V_263 ) {
V_59 -> V_137 . V_265 = V_263 ;
if ( V_193 )
F_118 ( & V_193 -> V_117 , V_266 , V_263 ) ;
F_124 ( V_101 -> V_3 , V_263 ) ;
}
}
if ( V_20 . V_36 ) {
struct V_11 * V_38 ;
for ( V_38 = V_20 . V_36 ;
V_38 ;
V_38 = F_7 ( V_38 , V_20 . V_35 ) ) {
F_96 ( V_101 , V_38 ) ;
}
}
if ( V_20 . V_184 || V_20 . V_267 ) {
F_9 ( 2 , V_28 , L_28 ) ;
}
V_169:
if ( V_193 )
F_114 ( & V_193 -> V_117 ) ;
if ( V_56 )
F_89 ( V_56 ) ;
}
static void F_125 ( struct V_89 * V_101 )
{
struct V_58 * V_59 ;
struct V_92 * V_183 ;
const struct V_42 * V_268 ;
const struct V_42 * V_94 ;
struct V_55 * V_56 ;
int V_269 = 0 ;
struct V_18 V_20 ;
int V_218 ;
T_1 * V_39 = NULL ;
#ifdef F_110
switch ( V_101 -> V_221 ) {
case V_222 :
case V_224 :
F_9 ( 2 , V_28 ,
L_29 ) ;
return;
}
#endif
if ( ! ( F_109 ( & F_73 ( V_101 ) -> V_91 ) & V_220 ) ) {
F_9 ( 2 , V_28 ,
L_30 ) ;
return;
}
V_218 = V_101 -> V_112 - V_101 -> V_111 ;
V_218 -= sizeof( struct V_92 ) + 2 * sizeof( struct V_42 ) ;
if ( V_218 < 0 ) {
F_9 ( 2 , V_28 , L_31 ) ;
return;
}
V_183 = F_126 ( V_101 ) ;
V_94 = ( const struct V_42 * ) ( V_183 + 1 ) ;
V_268 = V_94 + 1 ;
if ( F_20 ( V_268 ) ) {
F_9 ( 2 , V_28 ,
L_32 ) ;
return;
}
if ( F_127 ( V_268 , V_94 ) ) {
V_269 = 1 ;
} else if ( F_109 ( V_94 ) !=
( V_270 | V_220 ) ) {
F_9 ( 2 , V_28 ,
L_33 ) ;
return;
}
V_59 = F_26 ( V_101 -> V_3 ) ;
if ( ! V_59 )
return;
if ( V_59 -> V_137 . V_146 || ! V_59 -> V_137 . V_271 )
return;
if ( ! F_8 ( ( T_1 * ) ( V_268 + 1 ) , V_218 , & V_20 ) ) {
F_9 ( 2 , V_28 , L_34 ) ;
return;
}
if ( V_20 . V_184 ) {
V_39 = F_11 ( V_20 . V_184 ,
V_101 -> V_3 ) ;
if ( ! V_39 ) {
F_9 ( 2 , V_28 ,
L_35 ) ;
return;
}
}
V_56 = F_87 ( & V_158 , V_94 , V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
F_128 ( V_268 , & F_73 ( V_101 ) -> V_90 ,
& F_73 ( V_101 ) -> V_91 , V_56 , V_39 ,
V_269 ) ;
F_89 ( V_56 ) ;
}
}
void F_129 ( struct V_89 * V_101 , const struct V_42 * V_94 )
{
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_96 * V_96 = F_32 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
int V_106 = sizeof( struct V_92 ) + 2 * sizeof( struct V_42 ) ;
struct V_89 * V_272 ;
struct V_92 * V_183 ;
struct V_42 V_273 ;
struct V_42 * V_274 ;
struct V_192 * V_193 ;
struct V_116 * V_117 ;
struct V_58 * V_118 ;
struct V_114 V_115 ;
T_1 * V_5 ;
int V_103 , V_104 ;
int V_275 ;
int V_107 ;
T_1 V_276 [ V_277 ] , * V_73 = NULL ;
if ( F_64 ( V_3 , & V_273 , V_150 ) ) {
F_9 ( 2 , V_28 , L_36 ,
V_3 -> V_186 ) ;
return;
}
if ( ! F_127 ( & F_73 ( V_101 ) -> V_90 , V_94 ) &&
F_109 ( V_94 ) != ( V_270 | V_220 ) ) {
F_9 ( 2 , V_28 ,
L_33 ) ;
return;
}
F_42 ( V_98 , & V_115 , V_278 ,
& V_273 , & F_73 ( V_101 ) -> V_91 , V_3 -> V_120 ) ;
V_117 = F_130 ( V_96 , NULL , & V_115 ) ;
if ( V_117 -> error ) {
F_114 ( V_117 ) ;
return;
}
V_117 = F_131 ( V_96 , V_117 , F_132 ( & V_115 ) , NULL , 0 ) ;
if ( F_44 ( V_117 ) )
return;
V_193 = (struct V_192 * ) V_117 ;
if ( V_193 -> V_239 & V_279 ) {
F_9 ( 2 , V_28 ,
L_37 ) ;
goto V_280;
}
if ( ! V_193 -> V_281 )
F_133 ( V_193 , 1 ) ;
if ( ! F_134 ( V_193 -> V_281 , 1 * V_242 ) )
goto V_280;
if ( V_3 -> V_4 ) {
struct V_55 * V_56 = F_113 ( F_135 ( V_101 ) , V_94 ) ;
if ( ! V_56 ) {
F_9 ( 2 , V_28 ,
L_38 ) ;
goto V_280;
}
F_60 ( & V_56 -> V_145 ) ;
if ( V_56 -> V_67 & V_83 ) {
memcpy ( V_276 , V_56 -> V_73 , V_3 -> V_4 ) ;
F_62 ( & V_56 -> V_145 ) ;
V_73 = V_276 ;
V_106 += F_2 ( V_3 ) ;
} else
F_62 ( & V_56 -> V_145 ) ;
F_89 ( V_56 ) ;
}
V_275 = F_136 (unsigned int,
IPV6_MIN_MTU-sizeof(struct ipv6hdr)-len, skb->len + 8 ) ;
V_275 &= ~ 0x7 ;
V_106 += V_275 ;
V_103 = F_33 ( V_3 ) ;
V_104 = V_3 -> V_105 ;
V_272 = F_34 ( V_98 ,
( V_108 + sizeof( struct V_109 ) +
V_106 + V_103 + V_104 ) ,
1 , & V_107 ) ;
if ( V_272 == NULL ) {
F_9 ( 0 , V_107 ,
L_39 ,
V_29 , V_107 ) ;
goto V_280;
}
F_35 ( V_272 , V_103 ) ;
F_36 ( V_98 , V_272 , V_3 , & V_273 , & F_73 ( V_101 ) -> V_91 ,
V_110 , V_106 ) ;
F_137 ( V_272 , F_138 ( V_272 ) - V_272 -> V_6 ) ;
F_37 ( V_272 , V_106 ) ;
V_183 = F_126 ( V_272 ) ;
memset ( V_183 , 0 , sizeof( struct V_92 ) ) ;
V_183 -> V_119 = V_278 ;
V_274 = (struct V_42 * ) ( V_183 + 1 ) ;
* V_274 = * V_94 ;
V_274 ++ ;
* V_274 = F_73 ( V_101 ) -> V_90 ;
V_5 = ( T_1 * ) ( V_274 + 1 ) ;
if ( V_73 )
V_5 = F_4 ( V_5 , V_24 , V_73 ,
V_3 -> V_4 , V_3 -> type ) ;
memset ( V_5 , 0 , 8 ) ;
* ( V_5 ++ ) = V_26 ;
* ( V_5 ++ ) = ( V_275 >> 3 ) ;
V_5 += 6 ;
memcpy ( V_5 , F_73 ( V_101 ) , V_275 - 8 ) ;
V_183 -> V_113 = F_39 ( & V_273 , & F_73 ( V_101 ) -> V_91 ,
V_106 , V_110 ,
F_40 ( V_183 , V_106 , 0 ) ) ;
F_46 ( V_272 , V_117 ) ;
F_47 () ;
V_118 = F_26 ( V_117 -> V_3 ) ;
F_48 ( V_96 , V_118 , V_121 , V_101 -> V_106 ) ;
V_107 = F_49 ( V_122 , V_123 , V_272 , NULL , V_117 -> V_3 ,
V_124 ) ;
if ( ! V_107 ) {
F_50 ( V_96 , V_118 , V_278 ) ;
F_51 ( V_96 , V_118 , V_125 ) ;
}
F_52 () ;
return;
V_280:
F_114 ( V_117 ) ;
}
static void F_139 ( struct V_89 * V_101 )
{
F_78 ( V_101 ) ;
F_45 ( V_101 ) ;
}
int F_140 ( struct V_89 * V_101 )
{
struct V_160 * V_161 ;
if ( ! F_141 ( V_101 , V_101 -> V_106 ) )
return 0 ;
V_161 = (struct V_160 * ) F_38 ( V_101 ) ;
F_142 ( V_101 , V_101 -> V_6 - F_38 ( V_101 ) ) ;
if ( F_73 ( V_101 ) -> V_244 != 255 ) {
F_9 ( 2 , V_28 , L_40 ,
F_73 ( V_101 ) -> V_244 ) ;
return 0 ;
}
if ( V_161 -> V_183 . V_211 != 0 ) {
F_9 ( 2 , V_28 , L_41 ,
V_161 -> V_183 . V_211 ) ;
return 0 ;
}
memset ( F_83 ( V_101 ) , 0 , sizeof( struct V_282 ) ) ;
switch ( V_161 -> V_183 . V_119 ) {
case V_149 :
F_78 ( V_101 ) ;
break;
case V_135 :
F_90 ( V_101 ) ;
break;
case V_151 :
F_95 ( V_101 ) ;
break;
case V_283 :
F_108 ( V_101 ) ;
break;
case V_278 :
F_125 ( V_101 ) ;
break;
}
return 0 ;
}
static int F_143 ( struct V_284 * V_285 , unsigned long V_286 , void * V_287 )
{
struct V_2 * V_3 = V_287 ;
struct V_96 * V_96 = F_32 ( V_3 ) ;
switch ( V_286 ) {
case V_288 :
F_144 ( & V_158 , V_3 ) ;
F_145 ( ~ 0UL , V_96 ) ;
break;
case V_289 :
F_146 ( & V_158 , V_3 ) ;
F_145 ( ~ 0UL , V_96 ) ;
break;
case V_290 :
F_59 ( V_3 ) ;
break;
default:
break;
}
return V_291 ;
}
static void F_147 ( struct V_292 * V_293 ,
const char * V_294 , const char * V_295 )
{
static char V_296 [ V_297 ] ;
static int V_298 ;
if ( strcmp ( V_296 , V_299 -> V_300 ) && V_298 < 5 ) {
strcpy ( V_296 , V_299 -> V_300 ) ;
F_148 ( L_42 ,
V_296 , V_294 ,
V_295 , V_293 -> V_301 ,
V_295 , V_293 -> V_301 ) ;
V_298 ++ ;
}
}
int F_149 ( struct V_292 * V_293 , int V_302 , void T_7 * V_303 , T_4 * V_304 , T_8 * V_305 )
{
struct V_2 * V_3 = V_293 -> V_306 ;
struct V_58 * V_118 ;
int V_157 ;
if ( ( strcmp ( V_293 -> V_301 , L_43 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_44 ) == 0 ) )
F_147 ( V_293 , L_45 , V_3 ? V_3 -> V_186 : L_46 ) ;
if ( strcmp ( V_293 -> V_301 , L_43 ) == 0 )
V_157 = F_150 ( V_293 , V_302 , V_303 , V_304 , V_305 ) ;
else if ( strcmp ( V_293 -> V_301 , L_44 ) == 0 )
V_157 = F_151 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else if ( ( strcmp ( V_293 -> V_301 , L_47 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_48 ) == 0 ) )
V_157 = F_152 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else
V_157 = - 1 ;
if ( V_302 && V_157 == 0 && V_3 && ( V_118 = F_21 ( V_3 ) ) != NULL ) {
if ( V_293 -> V_6 == & V_118 -> V_63 -> V_253 )
V_118 -> V_63 -> V_252 = F_121 ( V_118 -> V_63 -> V_253 ) ;
V_118 -> V_250 = V_241 ;
F_120 ( V_251 , V_118 ) ;
F_24 ( V_118 ) ;
}
return V_157 ;
}
static int T_9 F_153 ( struct V_96 * V_96 )
{
struct V_307 * V_308 ;
struct V_97 * V_98 ;
int V_107 ;
V_107 = F_154 ( & V_98 , V_309 ,
V_310 , V_110 , V_96 ) ;
if ( V_107 < 0 ) {
F_9 ( 0 , V_107 ,
L_49 ,
V_107 ) ;
return V_107 ;
}
V_96 -> V_99 . V_100 = V_98 ;
V_308 = F_58 ( V_98 ) ;
V_308 -> V_244 = 255 ;
V_308 -> V_311 = 0 ;
return 0 ;
}
static void T_10 F_155 ( struct V_96 * V_96 )
{
F_156 ( V_96 -> V_99 . V_100 ) ;
}
int T_11 F_157 ( void )
{
int V_107 ;
V_107 = F_158 ( & V_312 ) ;
if ( V_107 )
return V_107 ;
F_159 ( & V_158 ) ;
#ifdef F_160
V_107 = F_161 ( NULL , & V_158 . V_61 , L_50 ,
& F_149 ) ;
if ( V_107 )
goto V_313;
#endif
V_107 = F_162 ( & V_314 ) ;
if ( V_107 )
goto V_315;
V_169:
return V_107 ;
V_315:
#ifdef F_160
F_163 ( & V_158 . V_61 ) ;
V_313:
#endif
F_164 ( & V_312 ) ;
goto V_169;
}
void F_165 ( void )
{
F_166 ( & V_314 ) ;
#ifdef F_160
F_163 ( & V_158 . V_61 ) ;
#endif
F_167 ( & V_158 ) ;
F_164 ( & V_312 ) ;
}
