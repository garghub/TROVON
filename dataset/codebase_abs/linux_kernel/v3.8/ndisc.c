static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + F_3 ( V_2 -> type ) ) ;
}
static T_1 * F_4 ( T_1 * V_4 , int type , void * V_5 , int V_6 ,
unsigned short V_7 )
{
int V_8 = F_3 ( V_7 ) ;
int V_9 = F_2 ( V_6 + V_8 ) ;
V_4 [ 0 ] = type ;
V_4 [ 1 ] = V_9 >> 3 ;
memset ( V_4 + 2 , 0 , V_8 ) ;
V_4 += V_8 ;
V_9 -= V_8 ;
memcpy ( V_4 + 2 , V_5 , V_6 ) ;
V_6 += 2 ;
V_4 += V_6 ;
if ( ( V_9 -= V_6 ) > 0 )
memset ( V_4 , 0 , V_9 ) ;
return V_4 + V_9 ;
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
static inline int F_6 ( struct V_10 * V_4 )
{
return V_4 -> V_13 == V_15 ||
V_4 -> V_13 == V_16 ;
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
struct V_17 * F_8 ( T_1 * V_4 , int V_18 ,
struct V_17 * V_19 )
{
struct V_10 * V_20 = (struct V_10 * ) V_4 ;
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
int F_11 ( const struct V_37 * V_38 , char * V_39 , struct V_1 * V_2 , int V_40 )
{
switch ( V_2 -> type ) {
case V_41 :
case V_42 :
case V_43 :
F_12 ( V_38 , V_39 ) ;
return 0 ;
case V_44 :
F_13 ( V_38 , V_39 ) ;
return 0 ;
case V_45 :
F_14 ( V_38 , V_2 -> V_46 , V_39 ) ;
return 0 ;
case V_47 :
return F_15 ( V_38 , V_2 -> V_46 , V_39 ) ;
default:
if ( V_40 ) {
memcpy ( V_39 , V_2 -> V_46 , V_2 -> V_3 ) ;
return 0 ;
}
}
return - V_48 ;
}
static T_2 F_16 ( const void * V_49 ,
const struct V_1 * V_2 ,
T_3 * V_50 )
{
return F_17 ( V_49 , V_2 , V_50 ) ;
}
static int F_18 ( struct V_51 * V_52 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_52 -> V_53 ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
bool V_58 = F_19 ( V_38 ) ;
V_55 = F_20 ( V_2 ) ;
if ( V_55 == NULL ) {
return - V_48 ;
}
V_57 = V_55 -> V_59 ;
F_21 ( V_52 -> V_57 ) ;
V_52 -> V_57 = F_22 ( V_57 ) ;
V_52 -> type = V_58 ? V_60 : V_61 ;
if ( ! V_2 -> V_62 ) {
V_52 -> V_63 = V_64 ;
V_52 -> V_65 = & V_66 ;
V_52 -> V_67 = V_68 ;
} else {
if ( V_58 ) {
V_52 -> V_63 = V_64 ;
F_11 ( V_38 , V_52 -> V_69 , V_2 , 1 ) ;
} else if ( V_2 -> V_70 & ( V_71 | V_72 ) ) {
V_52 -> V_63 = V_64 ;
memcpy ( V_52 -> V_69 , V_2 -> V_73 , V_2 -> V_3 ) ;
if ( V_2 -> V_70 & V_72 )
V_52 -> type = V_74 ;
} else if ( V_2 -> V_70 & V_75 ) {
V_52 -> V_63 = V_64 ;
memcpy ( V_52 -> V_69 , V_2 -> V_46 , V_2 -> V_3 ) ;
}
if ( V_2 -> V_62 -> V_76 )
V_52 -> V_65 = & V_77 ;
else
V_52 -> V_65 = & V_78 ;
if ( V_52 -> V_63 & V_79 )
V_52 -> V_67 = V_52 -> V_65 -> V_80 ;
else
V_52 -> V_67 = V_52 -> V_65 -> V_67 ;
}
F_23 ( V_55 ) ;
return 0 ;
}
static int F_24 ( struct V_81 * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_82 -> V_83 ;
struct V_37 V_84 ;
struct V_1 * V_2 = V_82 -> V_2 ;
if ( V_2 == NULL || F_25 ( V_2 ) == NULL )
return - V_48 ;
F_26 ( V_38 , & V_84 ) ;
F_27 ( V_2 , & V_84 ) ;
return 0 ;
}
static void F_28 ( struct V_81 * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) & V_82 -> V_83 ;
struct V_37 V_84 ;
struct V_1 * V_2 = V_82 -> V_2 ;
if ( V_2 == NULL || F_25 ( V_2 ) == NULL )
return;
F_26 ( V_38 , & V_84 ) ;
F_29 ( V_2 , & V_84 ) ;
}
static struct V_85 * F_30 ( struct V_1 * V_2 ,
const struct V_37 * V_86 ,
const struct V_37 * V_87 ,
struct V_88 * V_89 ,
const struct V_37 * V_90 ,
int V_91 )
{
struct V_92 * V_92 = F_31 ( V_2 ) ;
struct V_93 * V_94 = V_92 -> V_95 . V_96 ;
struct V_85 * V_97 ;
struct V_88 * V_98 ;
int V_99 = F_32 ( V_2 ) ;
int V_100 = V_2 -> V_101 ;
int V_102 ;
int V_103 ;
T_1 * V_4 ;
if ( ! V_2 -> V_3 )
V_91 = 0 ;
V_102 = sizeof( struct V_88 ) + ( V_90 ? sizeof( * V_90 ) : 0 ) ;
if ( V_91 )
V_102 += F_1 ( V_2 ) ;
V_97 = F_33 ( V_94 ,
( V_104 + sizeof( struct V_105 ) +
V_102 + V_99 + V_100 ) ,
1 , & V_103 ) ;
if ( ! V_97 ) {
F_9 ( 0 , V_103 , L_3 ,
V_28 , V_103 ) ;
return NULL ;
}
F_34 ( V_97 , V_99 ) ;
F_35 ( V_94 , V_97 , V_2 , V_87 , V_86 , V_106 , V_102 ) ;
V_97 -> V_107 = V_97 -> V_108 ;
F_36 ( V_97 , V_102 ) ;
V_98 = (struct V_88 * ) F_37 ( V_97 ) ;
memcpy ( V_98 , V_89 , sizeof( * V_98 ) ) ;
V_4 = F_37 ( V_97 ) + sizeof( struct V_88 ) ;
if ( V_90 ) {
* (struct V_37 * ) V_4 = * V_90 ;
V_4 += sizeof( * V_90 ) ;
}
if ( V_91 )
F_4 ( V_4 , V_91 , V_2 -> V_73 ,
V_2 -> V_3 , V_2 -> type ) ;
V_98 -> V_109 = F_38 ( V_87 , V_86 , V_102 ,
V_106 ,
F_39 ( V_98 ,
V_102 , 0 ) ) ;
return V_97 ;
}
static void F_40 ( struct V_85 * V_97 , struct V_1 * V_2 ,
struct V_51 * V_52 ,
const struct V_37 * V_86 ,
const struct V_37 * V_87 ,
struct V_88 * V_89 )
{
struct V_110 V_111 ;
struct V_112 * V_113 ;
struct V_92 * V_92 = F_31 ( V_2 ) ;
struct V_93 * V_94 = V_92 -> V_95 . V_96 ;
struct V_54 * V_114 ;
int V_103 ;
T_1 type ;
type = V_89 -> V_115 ;
F_41 ( V_94 , & V_111 , type , V_87 , V_86 , V_2 -> V_116 ) ;
V_113 = F_42 ( V_2 , V_52 , & V_111 ) ;
if ( F_43 ( V_113 ) ) {
F_44 ( V_97 ) ;
return;
}
F_45 ( V_97 , V_113 ) ;
F_46 () ;
V_114 = F_25 ( V_113 -> V_2 ) ;
F_47 ( V_92 , V_114 , V_117 , V_97 -> V_102 ) ;
V_103 = F_48 ( V_118 , V_119 , V_97 , NULL , V_113 -> V_2 ,
V_120 ) ;
if ( ! V_103 ) {
F_49 ( V_92 , V_114 , type ) ;
F_50 ( V_92 , V_114 , V_121 ) ;
}
F_51 () ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
const struct V_37 * V_86 ,
const struct V_37 * V_87 ,
struct V_88 * V_89 , const struct V_37 * V_90 ,
int V_91 )
{
struct V_85 * V_97 ;
V_97 = F_30 ( V_2 , V_86 , V_87 , V_89 , V_90 , V_91 ) ;
if ( ! V_97 )
return;
F_40 ( V_97 , V_2 , V_52 , V_86 , V_87 , V_89 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_51 * V_52 ,
const struct V_37 * V_86 ,
const struct V_37 * V_122 ,
int V_123 , int V_124 , int V_125 , int V_126 )
{
struct V_37 V_127 ;
struct V_128 * V_129 ;
const struct V_37 * V_130 ;
struct V_88 V_89 = {
. V_115 = V_131 ,
} ;
V_129 = F_54 ( F_31 ( V_2 ) , V_122 , V_2 , 1 ) ;
if ( V_129 ) {
V_130 = V_122 ;
if ( V_129 -> V_70 & V_132 )
V_125 = 0 ;
V_126 |= V_129 -> V_114 -> V_133 . V_134 ;
F_55 ( V_129 ) ;
} else {
if ( F_56 ( F_31 ( V_2 ) , V_2 , V_86 ,
F_57 ( F_31 ( V_2 ) -> V_95 . V_96 ) -> V_135 ,
& V_127 ) )
return;
V_130 = & V_127 ;
}
V_89 . V_136 = V_123 ;
V_89 . V_137 = V_124 ;
V_89 . V_138 = V_125 ;
F_52 ( V_2 , V_52 , V_86 , V_130 ,
& V_89 , V_122 ,
V_126 ? V_23 : 0 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_54 * V_114 ;
struct V_128 * V_139 ;
V_114 = F_20 ( V_2 ) ;
if ( ! V_114 )
return;
F_59 ( & V_114 -> V_140 ) ;
F_60 (ifa, &idev->addr_list, if_list) {
F_53 ( V_2 , NULL , & V_141 , & V_139 -> V_38 ,
! ! V_114 -> V_133 . V_142 ,
false , true ,
true ) ;
}
F_61 ( & V_114 -> V_140 ) ;
F_23 ( V_114 ) ;
}
void F_62 ( struct V_1 * V_2 , struct V_51 * V_52 ,
const struct V_37 * V_143 ,
const struct V_37 * V_86 , const struct V_37 * V_87 )
{
struct V_37 V_144 ;
struct V_88 V_89 = {
. V_115 = V_145 ,
} ;
if ( V_87 == NULL ) {
if ( F_63 ( V_2 , & V_144 ,
( V_146 | V_132 ) ) )
return;
V_87 = & V_144 ;
}
F_52 ( V_2 , V_52 , V_86 , V_87 ,
& V_89 , V_143 ,
! F_64 ( V_87 ) ? V_22 : 0 ) ;
}
void F_65 ( struct V_1 * V_2 , const struct V_37 * V_87 ,
const struct V_37 * V_86 )
{
struct V_88 V_89 = {
. V_115 = V_147 ,
} ;
int V_148 = V_2 -> V_3 ;
#ifdef F_66
if ( V_148 ) {
struct V_128 * V_129 = F_54 ( F_31 ( V_2 ) , V_87 ,
V_2 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_70 & V_132 ) {
V_148 = 0 ;
}
F_55 ( V_129 ) ;
} else {
V_148 = 0 ;
}
}
#endif
F_52 ( V_2 , NULL , V_86 , V_87 ,
& V_89 , NULL ,
V_148 ? V_22 : 0 ) ;
}
static void F_67 ( struct V_51 * V_52 , struct V_85 * V_97 )
{
F_68 ( V_97 ) ;
F_44 ( V_97 ) ;
}
static void F_69 ( struct V_51 * V_52 , struct V_85 * V_97 )
{
struct V_37 * V_87 = NULL ;
struct V_37 V_149 ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_37 * V_90 = (struct V_37 * ) & V_52 -> V_53 ;
int V_150 = F_70 ( & V_52 -> V_150 ) ;
if ( V_97 && F_71 ( F_31 ( V_2 ) , & F_72 ( V_97 ) -> V_87 , V_2 , 1 ) )
V_87 = & F_72 ( V_97 ) -> V_87 ;
if ( ( V_150 -= V_52 -> V_57 -> V_151 ) < 0 ) {
if ( ! ( V_52 -> V_63 & V_79 ) ) {
F_9 ( 1 , V_152 ,
L_4 ,
V_28 , V_90 ) ;
}
F_62 ( V_2 , V_52 , V_90 , V_90 , V_87 ) ;
} else if ( ( V_150 -= V_52 -> V_57 -> V_153 ) < 0 ) {
#ifdef F_73
F_74 ( V_52 ) ;
#endif
} else {
F_26 ( V_90 , & V_149 ) ;
F_62 ( V_2 , NULL , V_90 , & V_149 , V_87 ) ;
}
}
static int F_75 ( const void * V_49 ,
struct V_1 * V_2 )
{
struct V_81 * V_82 ;
int V_154 = - 1 ;
F_59 ( & V_155 . V_140 ) ;
V_82 = F_76 ( & V_155 , F_31 ( V_2 ) , V_49 , V_2 ) ;
if ( V_82 )
V_154 = ! ! ( V_82 -> V_70 & V_156 ) ;
F_61 ( & V_155 . V_140 ) ;
return V_154 ;
}
static void F_77 ( struct V_85 * V_97 )
{
struct V_157 * V_158 = (struct V_157 * ) F_37 ( V_97 ) ;
const struct V_37 * V_87 = & F_72 ( V_97 ) -> V_87 ;
const struct V_37 * V_86 = & F_72 ( V_97 ) -> V_86 ;
T_1 * V_159 = NULL ;
T_2 V_160 = V_97 -> V_108 - ( V_97 -> V_107 +
F_78 ( struct V_157 , V_4 ) ) ;
struct V_17 V_19 ;
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_128 * V_129 ;
struct V_54 * V_114 = NULL ;
struct V_51 * V_52 ;
int V_161 = F_64 ( V_87 ) ;
bool V_162 ;
int V_163 = - 1 ;
if ( F_19 ( & V_158 -> V_90 ) ) {
F_9 ( 2 , V_27 , L_5 ) ;
return;
}
if ( V_161 &&
! ( V_86 -> V_164 [ 0 ] == F_79 ( 0xff020000 ) &&
V_86 -> V_164 [ 1 ] == F_79 ( 0x00000000 ) &&
V_86 -> V_164 [ 2 ] == F_79 ( 0x00000001 ) &&
V_86 -> V_165 [ 12 ] == 0xff ) ) {
F_9 ( 2 , V_27 , L_6 ) ;
return;
}
if ( ! F_8 ( V_158 -> V_4 , V_160 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_7 ) ;
return;
}
if ( V_19 . V_166 ) {
V_159 = F_80 ( V_19 . V_166 , V_2 ) ;
if ( ! V_159 ) {
F_9 ( 2 , V_27 ,
L_8 ) ;
return;
}
if ( V_161 ) {
F_9 ( 2 , V_27 ,
L_9 ) ;
return;
}
}
V_162 = F_19 ( V_86 ) ;
V_129 = F_54 ( F_31 ( V_2 ) , & V_158 -> V_90 , V_2 , 1 ) ;
if ( V_129 ) {
if ( V_129 -> V_70 & ( V_146 | V_132 ) ) {
if ( V_161 ) {
F_81 ( V_129 ) ;
return;
} else {
if ( ! ( V_129 -> V_70 & V_132 ) )
goto V_167;
}
}
V_114 = V_129 -> V_114 ;
} else {
struct V_92 * V_92 = F_31 ( V_2 ) ;
V_114 = F_20 ( V_2 ) ;
if ( ! V_114 ) {
return;
}
if ( F_82 ( V_92 , V_2 , & V_158 -> V_90 ) ||
( V_114 -> V_133 . V_142 &&
( V_92 -> V_95 . V_168 -> V_169 || V_114 -> V_133 . V_169 ) &&
( V_163 = F_75 ( & V_158 -> V_90 , V_2 ) ) >= 0 ) ) {
if ( ! ( F_83 ( V_97 ) -> V_70 & V_170 ) &&
V_97 -> V_171 != V_172 &&
V_162 != 0 &&
V_114 -> V_59 -> V_173 != 0 ) {
struct V_85 * V_82 = F_84 ( V_97 , V_174 ) ;
if ( V_82 )
F_85 ( & V_155 , V_114 -> V_59 , V_82 ) ;
goto V_167;
}
} else
goto V_167;
}
if ( V_163 < 0 )
V_163 = ! ! V_114 -> V_133 . V_142 ;
if ( V_161 ) {
F_53 ( V_2 , NULL , & V_141 , & V_158 -> V_90 ,
V_163 , 0 , ( V_129 != NULL ) , 1 ) ;
goto V_167;
}
if ( V_162 )
F_86 ( & V_155 , V_175 ) ;
else
F_86 ( & V_155 , V_176 ) ;
V_52 = F_87 ( & V_155 , V_87 , V_2 ,
! V_162 || V_159 || ! V_2 -> V_3 ) ;
if ( V_52 )
F_88 ( V_52 , V_159 , V_177 ,
V_178 |
V_179 ) ;
if ( V_52 || ! V_2 -> V_62 ) {
F_53 ( V_2 , V_52 , V_87 , & V_158 -> V_90 ,
V_163 ,
1 , ( V_129 != NULL && V_162 ) , V_162 ) ;
if ( V_52 )
F_89 ( V_52 ) ;
}
V_167:
if ( V_129 )
F_55 ( V_129 ) ;
else
F_23 ( V_114 ) ;
}
static void F_90 ( struct V_85 * V_97 )
{
struct V_157 * V_158 = (struct V_157 * ) F_37 ( V_97 ) ;
const struct V_37 * V_87 = & F_72 ( V_97 ) -> V_87 ;
const struct V_37 * V_86 = & F_72 ( V_97 ) -> V_86 ;
T_1 * V_159 = NULL ;
T_2 V_160 = V_97 -> V_108 - ( V_97 -> V_107 +
F_78 ( struct V_157 , V_4 ) ) ;
struct V_17 V_19 ;
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_128 * V_129 ;
struct V_51 * V_52 ;
if ( V_97 -> V_102 < sizeof( struct V_157 ) ) {
F_9 ( 2 , V_27 , L_10 ) ;
return;
}
if ( F_19 ( & V_158 -> V_90 ) ) {
F_9 ( 2 , V_27 , L_11 ) ;
return;
}
if ( F_19 ( V_86 ) &&
V_158 -> V_180 . V_137 ) {
F_9 ( 2 , V_27 , L_12 ) ;
return;
}
if ( ! F_8 ( V_158 -> V_4 , V_160 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_13 ) ;
return;
}
if ( V_19 . V_181 ) {
V_159 = F_80 ( V_19 . V_181 , V_2 ) ;
if ( ! V_159 ) {
F_9 ( 2 , V_27 ,
L_14 ) ;
return;
}
}
V_129 = F_54 ( F_31 ( V_2 ) , & V_158 -> V_90 , V_2 , 1 ) ;
if ( V_129 ) {
if ( V_97 -> V_171 != V_182
&& ( V_129 -> V_70 & V_146 ) ) {
F_81 ( V_129 ) ;
return;
}
if ( V_97 -> V_171 != V_182 )
F_9 ( 1 , V_27 ,
L_15 ,
& V_129 -> V_38 , V_129 -> V_114 -> V_2 -> V_183 ) ;
F_55 ( V_129 ) ;
return;
}
V_52 = F_91 ( & V_155 , & V_158 -> V_90 , V_2 ) ;
if ( V_52 ) {
T_1 V_184 = V_52 -> V_70 ;
struct V_92 * V_92 = F_31 ( V_2 ) ;
if ( V_52 -> V_63 & V_185 )
goto V_167;
if ( V_159 && ! memcmp ( V_159 , V_2 -> V_73 , V_2 -> V_3 ) &&
V_92 -> V_95 . V_168 -> V_142 && V_92 -> V_95 . V_168 -> V_169 &&
F_92 ( & V_155 , V_92 , & V_158 -> V_90 , V_2 , 0 ) ) {
goto V_167;
}
F_88 ( V_52 , V_159 ,
V_158 -> V_180 . V_137 ? V_186 : V_177 ,
V_178 |
( V_158 -> V_180 . V_138 ? V_179 : 0 ) |
V_187 |
( V_158 -> V_180 . V_136 ? V_188 : 0 ) ) ;
if ( ( V_184 & ~ V_52 -> V_70 ) & V_156 ) {
struct V_189 * V_190 ;
V_190 = F_93 ( V_87 , V_2 ) ;
if ( V_190 )
F_94 ( V_190 ) ;
}
V_167:
F_89 ( V_52 ) ;
}
}
static void F_95 ( struct V_85 * V_97 )
{
struct V_191 * V_191 = (struct V_191 * ) F_37 ( V_97 ) ;
unsigned long V_160 = V_97 -> V_102 - sizeof( * V_191 ) ;
struct V_51 * V_52 ;
struct V_54 * V_114 ;
const struct V_37 * V_87 = & F_72 ( V_97 ) -> V_87 ;
struct V_17 V_19 ;
T_1 * V_159 = NULL ;
if ( V_97 -> V_102 < sizeof( * V_191 ) )
return;
V_114 = F_25 ( V_97 -> V_2 ) ;
if ( ! V_114 ) {
F_9 ( 1 , V_103 , L_16 ) ;
return;
}
if ( ! V_114 -> V_133 . V_142 )
goto V_167;
if ( F_64 ( V_87 ) )
goto V_167;
if ( ! F_8 ( V_191 -> V_4 , V_160 , & V_19 ) ) {
F_9 ( 2 , V_36 , L_17 ) ;
goto V_167;
}
if ( V_19 . V_166 ) {
V_159 = F_80 ( V_19 . V_166 ,
V_97 -> V_2 ) ;
if ( ! V_159 )
goto V_167;
}
V_52 = F_87 ( & V_155 , V_87 , V_97 -> V_2 , 1 ) ;
if ( V_52 ) {
F_88 ( V_52 , V_159 , V_177 ,
V_178 |
V_179 |
V_187 ) ;
F_89 ( V_52 ) ;
}
V_167:
return;
}
static void F_96 ( struct V_85 * V_192 , struct V_10 * V_4 )
{
struct V_88 * V_89 = (struct V_88 * ) F_37 ( V_192 ) ;
struct V_85 * V_97 ;
struct V_193 * V_194 ;
struct V_195 * V_196 ;
struct V_92 * V_92 = F_31 ( V_192 -> V_2 ) ;
int V_103 ;
int V_197 = F_97 ( sizeof( struct V_195 )
+ ( V_4 -> V_14 << 3 ) ) ;
T_4 V_198 = V_197 + F_98 ( sizeof( struct V_37 ) ) ;
V_97 = F_99 ( V_198 , V_174 ) ;
if ( V_97 == NULL ) {
V_103 = - V_199 ;
goto V_200;
}
V_194 = F_100 ( V_97 , 0 , 0 , V_201 , V_197 , 0 ) ;
if ( V_194 == NULL ) {
goto V_202;
}
V_196 = F_101 ( V_194 ) ;
V_196 -> V_203 = V_204 ;
V_196 -> V_205 = V_192 -> V_2 -> V_116 ;
V_196 -> V_206 = V_89 -> V_115 ;
V_196 -> V_207 = V_89 -> V_208 ;
V_196 -> V_209 = V_4 -> V_14 << 3 ;
memcpy ( V_196 + 1 , V_4 , V_4 -> V_14 << 3 ) ;
if ( F_102 ( V_97 , V_210 , sizeof( struct V_37 ) ,
& F_72 ( V_192 ) -> V_87 ) )
goto V_202;
F_103 ( V_97 , V_194 ) ;
F_104 ( V_97 , V_92 , 0 , V_211 , NULL , V_174 ) ;
return;
V_202:
F_105 ( V_97 ) ;
V_103 = - V_212 ;
V_200:
F_106 ( V_92 , V_211 , V_103 ) ;
}
static void F_107 ( struct V_85 * V_97 )
{
struct V_213 * V_213 = (struct V_213 * ) F_37 ( V_97 ) ;
struct V_51 * V_52 = NULL ;
struct V_54 * V_55 ;
struct V_189 * V_190 = NULL ;
int V_214 ;
struct V_17 V_19 ;
int V_215 ;
unsigned int V_216 = 0 ;
T_5 * V_4 = ( T_5 * ) ( V_213 + 1 ) ;
V_215 = ( V_97 -> V_108 - V_97 -> V_107 ) - sizeof( struct V_213 ) ;
if ( ! ( F_108 ( & F_72 ( V_97 ) -> V_87 ) & V_217 ) ) {
F_9 ( 2 , V_27 , L_18 ) ;
return;
}
if ( V_215 < 0 ) {
F_9 ( 2 , V_27 , L_19 ) ;
return;
}
#ifdef F_109
if ( V_97 -> V_218 == V_219 ) {
F_9 ( 2 , V_27 , L_20 ) ;
return;
}
#endif
V_55 = F_25 ( V_97 -> V_2 ) ;
if ( V_55 == NULL ) {
F_9 ( 0 , V_103 , L_21 ,
V_97 -> V_2 -> V_183 ) ;
return;
}
if ( ! F_8 ( V_4 , V_215 , & V_19 ) ) {
F_9 ( 2 , V_27 , L_22 ) ;
return;
}
if ( ! F_110 ( V_55 ) )
goto V_220;
#ifdef F_109
if ( V_97 -> V_218 == V_221 )
goto V_220;
#endif
if ( V_55 -> V_222 & V_223 ) {
V_55 -> V_222 |= V_224 ;
}
V_55 -> V_222 = ( V_55 -> V_222 & ~ ( V_225 |
V_226 ) ) |
( V_213 -> V_180 . V_227 ?
V_225 : 0 ) |
( V_213 -> V_180 . V_228 ?
V_226 : 0 ) ;
if ( ! V_55 -> V_133 . V_229 )
goto V_230;
if ( F_71 ( F_31 ( V_55 -> V_2 ) , & F_72 ( V_97 ) -> V_87 , NULL , 0 ) )
goto V_230;
V_214 = F_111 ( V_213 -> V_180 . V_231 ) ;
#ifdef F_112
V_216 = V_213 -> V_180 . V_232 ;
if ( V_216 == V_233 ||
! V_55 -> V_133 . V_234 )
V_216 = V_235 ;
#endif
V_190 = F_93 ( & F_72 ( V_97 ) -> V_87 , V_97 -> V_2 ) ;
if ( V_190 ) {
V_52 = F_113 ( & V_190 -> V_113 , & F_72 ( V_97 ) -> V_87 ) ;
if ( ! V_52 ) {
F_9 ( 0 , V_103 ,
L_23 ,
V_28 ) ;
F_114 ( V_190 ) ;
return;
}
}
if ( V_190 && V_214 == 0 ) {
F_94 ( V_190 ) ;
V_190 = NULL ;
}
if ( V_190 == NULL && V_214 ) {
F_9 ( 3 , V_152 , L_24 ) ;
V_190 = F_115 ( & F_72 ( V_97 ) -> V_87 , V_97 -> V_2 , V_216 ) ;
if ( V_190 == NULL ) {
F_9 ( 0 , V_103 ,
L_25 ,
V_28 ) ;
return;
}
V_52 = F_113 ( & V_190 -> V_113 , & F_72 ( V_97 ) -> V_87 ) ;
if ( V_52 == NULL ) {
F_9 ( 0 , V_103 ,
L_23 ,
V_28 ) ;
F_114 ( V_190 ) ;
return;
}
V_52 -> V_70 |= V_156 ;
} else if ( V_190 ) {
V_190 -> V_236 = ( V_190 -> V_236 & ~ V_237 ) | F_116 ( V_216 ) ;
}
if ( V_190 )
F_117 ( V_190 , V_238 + ( V_239 * V_214 ) ) ;
if ( V_213 -> V_180 . V_240 ) {
V_55 -> V_133 . V_241 = V_213 -> V_180 . V_240 ;
if ( V_190 )
F_118 ( & V_190 -> V_113 , V_242 ,
V_213 -> V_180 . V_240 ) ;
}
V_230:
if ( V_55 -> V_59 ) {
unsigned long V_243 = F_119 ( V_213 -> V_244 ) ;
if ( V_243 && V_243 / 1000 < V_245 / V_239 ) {
V_243 = ( V_243 * V_239 ) / 1000 ;
if ( V_243 < V_239 / 10 )
V_243 = V_239 / 10 ;
V_55 -> V_59 -> V_246 = V_243 ;
V_55 -> V_247 = V_238 ;
F_120 ( V_248 , V_55 ) ;
}
V_243 = F_119 ( V_213 -> V_249 ) ;
if ( V_243 && V_243 / 1000 < V_245 / ( 3 * V_239 ) ) {
V_243 = ( V_243 * V_239 ) / 1000 ;
if ( V_243 < V_239 / 10 )
V_243 = V_239 / 10 ;
if ( V_243 != V_55 -> V_59 -> V_250 ) {
V_55 -> V_59 -> V_250 = V_243 ;
V_55 -> V_59 -> V_251 = 3 * V_243 ;
V_55 -> V_59 -> V_249 = F_121 ( V_243 ) ;
V_55 -> V_247 = V_238 ;
F_120 ( V_248 , V_55 ) ;
}
}
}
V_220:
if ( ! V_52 )
V_52 = F_87 ( & V_155 , & F_72 ( V_97 ) -> V_87 ,
V_97 -> V_2 , 1 ) ;
if ( V_52 ) {
T_1 * V_159 = NULL ;
if ( V_19 . V_166 ) {
V_159 = F_80 ( V_19 . V_166 ,
V_97 -> V_2 ) ;
if ( ! V_159 ) {
F_9 ( 2 , V_27 ,
L_26 ) ;
goto V_167;
}
}
F_88 ( V_52 , V_159 , V_177 ,
V_178 |
V_179 |
V_187 |
V_188 ) ;
}
if ( ! F_110 ( V_55 ) )
goto V_167;
#ifdef F_10
if ( F_71 ( F_31 ( V_55 -> V_2 ) , & F_72 ( V_97 ) -> V_87 , NULL , 0 ) )
goto V_252;
if ( V_55 -> V_133 . V_234 && V_19 . V_33 ) {
struct V_10 * V_253 ;
for ( V_253 = V_19 . V_33 ;
V_253 ;
V_253 = F_5 ( V_253 , V_19 . V_32 ) ) {
struct V_254 * V_255 = (struct V_254 * ) V_253 ;
#ifdef F_109
if ( V_97 -> V_218 == V_221 &&
V_255 -> V_256 == 0 )
continue;
#endif
if ( V_255 -> V_256 > V_55 -> V_133 . V_257 )
continue;
F_122 ( V_97 -> V_2 , ( T_1 * ) V_253 , ( V_253 -> V_14 ) << 3 ,
& F_72 ( V_97 ) -> V_87 ) ;
}
}
V_252:
#endif
#ifdef F_109
if ( V_97 -> V_218 == V_221 )
goto V_167;
#endif
if ( V_55 -> V_133 . V_258 && V_19 . V_259 ) {
struct V_10 * V_253 ;
for ( V_253 = V_19 . V_259 ;
V_253 ;
V_253 = F_5 ( V_253 , V_19 . V_30 ) ) {
F_123 ( V_97 -> V_2 , ( T_1 * ) V_253 ,
( V_253 -> V_14 ) << 3 ,
V_19 . V_166 != NULL ) ;
}
}
if ( V_19 . V_260 ) {
T_6 V_82 ;
T_2 V_261 ;
memcpy ( & V_82 , ( ( T_1 * ) ( V_19 . V_260 + 1 ) ) + 2 , sizeof( V_261 ) ) ;
V_261 = F_119 ( V_82 ) ;
if ( V_261 < V_262 || V_261 > V_97 -> V_2 -> V_261 ) {
F_9 ( 2 , V_27 , L_27 , V_261 ) ;
} else if ( V_55 -> V_133 . V_263 != V_261 ) {
V_55 -> V_133 . V_263 = V_261 ;
if ( V_190 )
F_118 ( & V_190 -> V_113 , V_264 , V_261 ) ;
F_124 ( V_97 -> V_2 , V_261 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_10 * V_253 ;
for ( V_253 = V_19 . V_35 ;
V_253 ;
V_253 = F_7 ( V_253 , V_19 . V_34 ) ) {
F_96 ( V_97 , V_253 ) ;
}
}
if ( V_19 . V_181 || V_19 . V_265 ) {
F_9 ( 2 , V_27 , L_28 ) ;
}
V_167:
F_114 ( V_190 ) ;
if ( V_52 )
F_89 ( V_52 ) ;
}
static void F_125 ( struct V_85 * V_97 )
{
T_1 * V_98 ;
struct V_17 V_19 ;
struct V_266 * V_158 = (struct V_266 * ) F_37 ( V_97 ) ;
T_2 V_160 = V_97 -> V_108 - ( V_97 -> V_107 +
F_78 ( struct V_266 , V_4 ) ) ;
#ifdef F_109
switch ( V_97 -> V_218 ) {
case V_219 :
case V_221 :
F_9 ( 2 , V_27 ,
L_29 ) ;
return;
}
#endif
if ( ! ( F_108 ( & F_72 ( V_97 ) -> V_87 ) & V_217 ) ) {
F_9 ( 2 , V_27 ,
L_30 ) ;
return;
}
if ( ! F_8 ( V_158 -> V_4 , V_160 , & V_19 ) )
return;
if ( ! V_19 . V_265 )
return;
V_98 = ( T_1 * ) V_19 . V_265 ;
V_98 += 8 ;
if ( ! F_126 ( V_97 , V_98 - F_37 ( V_97 ) ) )
return;
F_127 ( V_97 , V_267 , 0 , 0 ) ;
}
void F_128 ( struct V_85 * V_97 , const struct V_37 * V_90 )
{
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_92 * V_92 = F_31 ( V_2 ) ;
struct V_93 * V_94 = V_92 -> V_95 . V_96 ;
int V_102 = sizeof( struct V_88 ) + 2 * sizeof( struct V_37 ) ;
struct V_268 * V_269 ;
struct V_85 * V_270 ;
struct V_88 * V_180 ;
struct V_37 V_271 ;
struct V_37 * V_272 ;
struct V_189 * V_190 ;
struct V_112 * V_113 ;
struct V_54 * V_114 ;
struct V_110 V_111 ;
T_1 * V_4 ;
int V_99 , V_100 ;
int V_273 ;
int V_103 ;
T_1 V_274 [ V_275 ] , * V_69 = NULL ;
bool V_154 ;
if ( F_63 ( V_2 , & V_271 , V_146 ) ) {
F_9 ( 2 , V_27 , L_31 ,
V_2 -> V_183 ) ;
return;
}
if ( ! F_129 ( & F_72 ( V_97 ) -> V_86 , V_90 ) &&
F_108 ( V_90 ) != ( V_276 | V_217 ) ) {
F_9 ( 2 , V_27 ,
L_32 ) ;
return;
}
F_41 ( V_94 , & V_111 , V_267 ,
& V_271 , & F_72 ( V_97 ) -> V_87 , V_2 -> V_116 ) ;
V_113 = F_130 ( V_92 , NULL , & V_111 ) ;
if ( V_113 -> error ) {
F_131 ( V_113 ) ;
return;
}
V_113 = F_132 ( V_92 , V_113 , F_133 ( & V_111 ) , NULL , 0 ) ;
if ( F_43 ( V_113 ) )
return;
V_190 = (struct V_189 * ) V_113 ;
if ( V_190 -> V_236 & V_277 ) {
F_9 ( 2 , V_27 ,
L_33 ) ;
goto V_278;
}
V_269 = F_134 ( V_92 -> V_95 . V_279 , & V_190 -> V_280 . V_38 , 1 ) ;
V_154 = F_135 ( V_269 , 1 * V_239 ) ;
if ( V_269 )
F_136 ( V_269 ) ;
if ( ! V_154 )
goto V_278;
if ( V_2 -> V_3 ) {
struct V_51 * V_52 = F_113 ( F_137 ( V_97 ) , V_90 ) ;
if ( ! V_52 ) {
F_9 ( 2 , V_27 ,
L_34 ) ;
goto V_278;
}
F_59 ( & V_52 -> V_140 ) ;
if ( V_52 -> V_63 & V_79 ) {
memcpy ( V_274 , V_52 -> V_69 , V_2 -> V_3 ) ;
F_61 ( & V_52 -> V_140 ) ;
V_69 = V_274 ;
V_102 += F_1 ( V_2 ) ;
} else
F_61 ( & V_52 -> V_140 ) ;
F_89 ( V_52 ) ;
}
V_273 = F_138 (unsigned int,
IPV6_MIN_MTU-sizeof(struct ipv6hdr)-len, skb->len + 8 ) ;
V_273 &= ~ 0x7 ;
V_102 += V_273 ;
V_99 = F_32 ( V_2 ) ;
V_100 = V_2 -> V_101 ;
V_270 = F_33 ( V_94 ,
( V_104 + sizeof( struct V_105 ) +
V_102 + V_99 + V_100 ) ,
1 , & V_103 ) ;
if ( V_270 == NULL ) {
F_9 ( 0 , V_103 ,
L_35 ,
V_28 , V_103 ) ;
goto V_278;
}
F_34 ( V_270 , V_99 ) ;
F_35 ( V_94 , V_270 , V_2 , & V_271 , & F_72 ( V_97 ) -> V_87 ,
V_106 , V_102 ) ;
F_139 ( V_270 , F_140 ( V_270 ) - V_270 -> V_5 ) ;
F_36 ( V_270 , V_102 ) ;
V_180 = F_141 ( V_270 ) ;
memset ( V_180 , 0 , sizeof( struct V_88 ) ) ;
V_180 -> V_115 = V_267 ;
V_272 = (struct V_37 * ) ( V_180 + 1 ) ;
* V_272 = * V_90 ;
V_272 ++ ;
* V_272 = F_72 ( V_97 ) -> V_86 ;
V_4 = ( T_1 * ) ( V_272 + 1 ) ;
if ( V_69 )
V_4 = F_4 ( V_4 , V_23 , V_69 ,
V_2 -> V_3 , V_2 -> type ) ;
memset ( V_4 , 0 , 8 ) ;
* ( V_4 ++ ) = V_25 ;
* ( V_4 ++ ) = ( V_273 >> 3 ) ;
V_4 += 6 ;
memcpy ( V_4 , F_72 ( V_97 ) , V_273 - 8 ) ;
V_180 -> V_109 = F_38 ( & V_271 , & F_72 ( V_97 ) -> V_87 ,
V_102 , V_106 ,
F_39 ( V_180 , V_102 , 0 ) ) ;
F_45 ( V_270 , V_113 ) ;
F_46 () ;
V_114 = F_25 ( V_113 -> V_2 ) ;
F_47 ( V_92 , V_114 , V_117 , V_97 -> V_102 ) ;
V_103 = F_48 ( V_118 , V_119 , V_270 , NULL , V_113 -> V_2 ,
V_120 ) ;
if ( ! V_103 ) {
F_49 ( V_92 , V_114 , V_267 ) ;
F_50 ( V_92 , V_114 , V_121 ) ;
}
F_51 () ;
return;
V_278:
F_131 ( V_113 ) ;
}
static void F_142 ( struct V_85 * V_97 )
{
F_77 ( V_97 ) ;
F_44 ( V_97 ) ;
}
int F_143 ( struct V_85 * V_97 )
{
struct V_157 * V_158 ;
if ( ! F_144 ( V_97 , V_97 -> V_102 ) )
return 0 ;
V_158 = (struct V_157 * ) F_37 ( V_97 ) ;
F_145 ( V_97 , V_97 -> V_5 - F_37 ( V_97 ) ) ;
if ( F_72 ( V_97 ) -> V_241 != 255 ) {
F_9 ( 2 , V_27 , L_36 ,
F_72 ( V_97 ) -> V_241 ) ;
return 0 ;
}
if ( V_158 -> V_180 . V_208 != 0 ) {
F_9 ( 2 , V_27 , L_37 ,
V_158 -> V_180 . V_208 ) ;
return 0 ;
}
memset ( F_83 ( V_97 ) , 0 , sizeof( struct V_281 ) ) ;
switch ( V_158 -> V_180 . V_115 ) {
case V_145 :
F_77 ( V_97 ) ;
break;
case V_131 :
F_90 ( V_97 ) ;
break;
case V_147 :
F_95 ( V_97 ) ;
break;
case V_282 :
F_107 ( V_97 ) ;
break;
case V_267 :
F_125 ( V_97 ) ;
break;
}
return 0 ;
}
static int F_146 ( struct V_283 * V_284 , unsigned long V_285 , void * V_286 )
{
struct V_1 * V_2 = V_286 ;
struct V_92 * V_92 = F_31 ( V_2 ) ;
struct V_54 * V_114 ;
switch ( V_285 ) {
case V_287 :
F_147 ( & V_155 , V_2 ) ;
F_148 ( ~ 0UL , V_92 ) ;
V_114 = F_20 ( V_2 ) ;
if ( ! V_114 )
break;
if ( V_114 -> V_133 . V_288 )
F_58 ( V_2 ) ;
F_23 ( V_114 ) ;
break;
case V_289 :
F_149 ( & V_155 , V_2 ) ;
F_148 ( ~ 0UL , V_92 ) ;
break;
case V_290 :
F_58 ( V_2 ) ;
break;
default:
break;
}
return V_291 ;
}
static void F_150 ( struct V_292 * V_293 ,
const char * V_294 , const char * V_295 )
{
static char V_296 [ V_297 ] ;
static int V_298 ;
if ( strcmp ( V_296 , V_299 -> V_300 ) && V_298 < 5 ) {
strcpy ( V_296 , V_299 -> V_300 ) ;
F_151 ( L_38 ,
V_296 , V_294 ,
V_295 , V_293 -> V_301 ,
V_295 , V_293 -> V_301 ) ;
V_298 ++ ;
}
}
int F_152 ( struct V_292 * V_293 , int V_302 , void T_7 * V_303 , T_4 * V_304 , T_8 * V_305 )
{
struct V_1 * V_2 = V_293 -> V_306 ;
struct V_54 * V_114 ;
int V_154 ;
if ( ( strcmp ( V_293 -> V_301 , L_39 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_40 ) == 0 ) )
F_150 ( V_293 , L_41 , V_2 ? V_2 -> V_183 : L_42 ) ;
if ( strcmp ( V_293 -> V_301 , L_39 ) == 0 )
V_154 = F_153 ( V_293 , V_302 , V_303 , V_304 , V_305 ) ;
else if ( strcmp ( V_293 -> V_301 , L_40 ) == 0 )
V_154 = F_154 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else if ( ( strcmp ( V_293 -> V_301 , L_43 ) == 0 ) ||
( strcmp ( V_293 -> V_301 , L_44 ) == 0 ) )
V_154 = F_155 ( V_293 , V_302 ,
V_303 , V_304 , V_305 ) ;
else
V_154 = - 1 ;
if ( V_302 && V_154 == 0 && V_2 && ( V_114 = F_20 ( V_2 ) ) != NULL ) {
if ( V_293 -> V_5 == & V_114 -> V_59 -> V_250 )
V_114 -> V_59 -> V_249 = F_121 ( V_114 -> V_59 -> V_250 ) ;
V_114 -> V_247 = V_238 ;
F_120 ( V_248 , V_114 ) ;
F_23 ( V_114 ) ;
}
return V_154 ;
}
static int T_9 F_156 ( struct V_92 * V_92 )
{
struct V_307 * V_308 ;
struct V_93 * V_94 ;
int V_103 ;
V_103 = F_157 ( & V_94 , V_309 ,
V_310 , V_106 , V_92 ) ;
if ( V_103 < 0 ) {
F_9 ( 0 , V_103 ,
L_45 ,
V_103 ) ;
return V_103 ;
}
V_92 -> V_95 . V_96 = V_94 ;
V_308 = F_57 ( V_94 ) ;
V_308 -> V_241 = 255 ;
V_308 -> V_311 = 0 ;
return 0 ;
}
static void T_10 F_158 ( struct V_92 * V_92 )
{
F_159 ( V_92 -> V_95 . V_96 ) ;
}
int T_11 F_160 ( void )
{
int V_103 ;
V_103 = F_161 ( & V_312 ) ;
if ( V_103 )
return V_103 ;
F_162 ( & V_155 ) ;
#ifdef F_163
V_103 = F_164 ( NULL , & V_155 . V_57 , L_46 ,
& F_152 ) ;
if ( V_103 )
goto V_313;
#endif
V_103 = F_165 ( & V_314 ) ;
if ( V_103 )
goto V_315;
V_167:
return V_103 ;
V_315:
#ifdef F_163
F_166 ( & V_155 . V_57 ) ;
V_313:
#endif
F_167 ( & V_312 ) ;
goto V_167;
}
void F_168 ( void )
{
F_169 ( & V_314 ) ;
#ifdef F_163
F_166 ( & V_155 . V_57 ) ;
#endif
F_170 ( & V_155 ) ;
F_167 ( & V_312 ) ;
}
