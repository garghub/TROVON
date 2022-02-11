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
return V_5 -> V_14 == V_16 ;
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
static struct V_17 * F_8 ( T_1 * V_5 , int V_18 ,
struct V_17 * V_19 )
{
struct V_11 * V_20 = (struct V_11 * ) V_5 ;
if ( ! V_20 || V_18 < 0 || ! V_19 )
return NULL ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
while ( V_18 ) {
int V_21 ;
if ( V_18 < sizeof( struct V_11 ) )
return NULL ;
V_21 = V_20 -> V_15 << 3 ;
if ( V_18 < V_21 || V_21 == 0 )
return NULL ;
switch ( V_20 -> V_14 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if ( V_19 -> V_26 [ V_20 -> V_14 ] ) {
F_9 ( V_27
L_1 ,
V_28 ,
V_20 -> V_14 ) ;
} else {
V_19 -> V_26 [ V_20 -> V_14 ] = V_20 ;
}
break;
case V_29 :
V_19 -> V_30 = V_20 ;
if ( ! V_19 -> V_26 [ V_20 -> V_14 ] )
V_19 -> V_26 [ V_20 -> V_14 ] = V_20 ;
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
F_9 ( V_36
L_2 ,
V_28 ,
V_20 -> V_14 , V_20 -> V_15 ) ;
}
}
V_18 -= V_21 ;
V_20 = ( ( void * ) V_20 ) + V_21 ;
}
return V_19 ;
}
static inline T_1 * F_11 ( struct V_11 * V_37 ,
struct V_2 * V_3 )
{
T_1 * V_38 = ( T_1 * ) ( V_37 + 1 ) ;
int V_39 = V_37 -> V_15 << 3 ;
int V_40 = F_1 ( V_3 -> type ) ;
if ( V_39 != F_3 ( V_3 -> V_4 + V_40 ) )
return NULL ;
return V_38 + V_40 ;
}
int F_12 ( const struct V_41 * V_42 , char * V_43 , struct V_2 * V_3 , int V_44 )
{
switch ( V_3 -> type ) {
case V_45 :
case V_46 :
case V_47 :
F_13 ( V_42 , V_43 ) ;
return 0 ;
case V_48 :
F_14 ( V_42 , V_43 ) ;
return 0 ;
case V_49 :
F_15 ( V_42 , V_43 ) ;
return 0 ;
case V_1 :
F_16 ( V_42 , V_3 -> V_50 , V_43 ) ;
return 0 ;
case V_51 :
return F_17 ( V_42 , V_3 -> V_50 , V_43 ) ;
default:
if ( V_44 ) {
memcpy ( V_43 , V_3 -> V_50 , V_3 -> V_4 ) ;
return 0 ;
}
}
return - V_52 ;
}
static T_2 F_18 ( const void * V_53 ,
const struct V_2 * V_3 ,
T_3 * V_54 )
{
return F_19 ( V_53 , V_3 , V_54 ) ;
}
static int F_20 ( struct V_55 * V_56 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_56 -> V_57 ;
struct V_2 * V_3 = V_56 -> V_3 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_62 = F_21 ( V_42 ) ;
V_59 = F_22 ( V_3 ) ;
if ( V_59 == NULL ) {
return - V_52 ;
}
V_61 = V_59 -> V_63 ;
F_23 ( V_56 -> V_61 ) ;
V_56 -> V_61 = F_24 ( V_61 ) ;
V_56 -> type = V_62 ? V_64 : V_65 ;
if ( ! V_3 -> V_66 ) {
V_56 -> V_67 = V_68 ;
V_56 -> V_69 = & V_70 ;
V_56 -> V_71 = V_72 ;
} else {
if ( V_62 ) {
V_56 -> V_67 = V_68 ;
F_12 ( V_42 , V_56 -> V_73 , V_3 , 1 ) ;
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
F_25 ( V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_85 * V_86 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_86 -> V_87 ;
struct V_41 V_88 ;
struct V_2 * V_3 = V_86 -> V_3 ;
if ( V_3 == NULL || F_27 ( V_3 ) == NULL )
return - V_52 ;
F_28 ( V_42 , & V_88 ) ;
F_29 ( V_3 , & V_88 ) ;
return 0 ;
}
static void F_30 ( struct V_85 * V_86 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_86 -> V_87 ;
struct V_41 V_88 ;
struct V_2 * V_3 = V_86 -> V_3 ;
if ( V_3 == NULL || F_27 ( V_3 ) == NULL )
return;
F_28 ( V_42 , & V_88 ) ;
F_31 ( V_3 , & V_88 ) ;
}
struct V_89 * F_32 ( struct V_2 * V_3 ,
const struct V_41 * V_90 ,
const struct V_41 * V_91 ,
struct V_92 * V_93 ,
const struct V_41 * V_94 ,
int V_95 )
{
struct V_96 * V_96 = F_33 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
struct V_89 * V_101 ;
struct V_92 * V_102 ;
int V_103 = F_34 ( V_3 ) ;
int V_104 = V_3 -> V_105 ;
int V_106 ;
int V_107 ;
T_1 * V_5 ;
if ( ! V_3 -> V_4 )
V_95 = 0 ;
V_106 = sizeof( struct V_92 ) + ( V_94 ? sizeof( * V_94 ) : 0 ) ;
if ( V_95 )
V_106 += F_2 ( V_3 ) ;
V_101 = F_35 ( V_98 ,
( V_108 + sizeof( struct V_109 ) +
V_106 + V_103 + V_104 ) ,
1 , & V_107 ) ;
if ( ! V_101 ) {
F_36 ( V_110
L_3 ,
V_28 , V_107 ) ;
return NULL ;
}
F_37 ( V_101 , V_103 ) ;
F_38 ( V_98 , V_101 , V_3 , V_91 , V_90 , V_111 , V_106 ) ;
V_101 -> V_112 = V_101 -> V_113 ;
F_39 ( V_101 , V_106 ) ;
V_102 = (struct V_92 * ) F_40 ( V_101 ) ;
memcpy ( V_102 , V_93 , sizeof( * V_102 ) ) ;
V_5 = F_40 ( V_101 ) + sizeof( struct V_92 ) ;
if ( V_94 ) {
* (struct V_41 * ) V_5 = * V_94 ;
V_5 += sizeof( * V_94 ) ;
}
if ( V_95 )
F_4 ( V_5 , V_95 , V_3 -> V_77 ,
V_3 -> V_4 , V_3 -> type ) ;
V_102 -> V_114 = F_41 ( V_91 , V_90 , V_106 ,
V_111 ,
F_42 ( V_102 ,
V_106 , 0 ) ) ;
return V_101 ;
}
void F_43 ( struct V_89 * V_101 ,
struct V_2 * V_3 ,
struct V_55 * V_56 ,
const struct V_41 * V_90 ,
const struct V_41 * V_91 ,
struct V_92 * V_93 )
{
struct V_115 V_116 ;
struct V_117 * V_118 ;
struct V_96 * V_96 = F_33 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
struct V_58 * V_119 ;
int V_107 ;
T_1 type ;
type = V_93 -> V_120 ;
F_44 ( V_98 , & V_116 , type , V_91 , V_90 , V_3 -> V_121 ) ;
V_118 = F_45 ( V_3 , V_56 , & V_116 ) ;
if ( F_46 ( V_118 ) ) {
F_47 ( V_101 ) ;
return;
}
F_48 ( V_101 , V_118 ) ;
F_49 () ;
V_119 = F_27 ( V_118 -> V_3 ) ;
F_50 ( V_96 , V_119 , V_122 , V_101 -> V_106 ) ;
V_107 = F_51 ( V_123 , V_124 , V_101 , NULL , V_118 -> V_3 ,
V_125 ) ;
if ( ! V_107 ) {
F_52 ( V_96 , V_119 , type ) ;
F_53 ( V_96 , V_119 , V_126 ) ;
}
F_54 () ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_55 * V_56 ,
const struct V_41 * V_90 ,
const struct V_41 * V_91 ,
struct V_92 * V_93 , const struct V_41 * V_94 ,
int V_95 )
{
struct V_89 * V_101 ;
V_101 = F_32 ( V_3 , V_90 , V_91 , V_93 , V_94 , V_95 ) ;
if ( ! V_101 )
return;
F_43 ( V_101 , V_3 , V_56 , V_90 , V_91 , V_93 ) ;
}
static void F_56 ( struct V_2 * V_3 , struct V_55 * V_56 ,
const struct V_41 * V_90 ,
const struct V_41 * V_127 ,
int V_128 , int V_129 , int V_130 , int V_131 )
{
struct V_41 V_132 ;
struct V_133 * V_134 ;
const struct V_41 * V_135 ;
struct V_92 V_93 = {
. V_120 = V_136 ,
} ;
V_134 = F_57 ( F_33 ( V_3 ) , V_127 , V_3 , 1 ) ;
if ( V_134 ) {
V_135 = V_127 ;
if ( V_134 -> V_74 & V_137 )
V_130 = 0 ;
V_131 |= V_134 -> V_119 -> V_138 . V_139 ;
F_58 ( V_134 ) ;
} else {
if ( F_59 ( F_33 ( V_3 ) , V_3 , V_90 ,
F_60 ( F_33 ( V_3 ) -> V_99 . V_100 ) -> V_140 ,
& V_132 ) )
return;
V_135 = & V_132 ;
}
V_93 . V_141 = V_128 ;
V_93 . V_142 = V_129 ;
V_93 . V_143 = V_130 ;
F_55 ( V_3 , V_56 , V_90 , V_135 ,
& V_93 , V_127 ,
V_131 ? V_23 : 0 ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_58 * V_119 ;
struct V_133 * V_144 ;
struct V_41 V_145 ;
V_119 = F_22 ( V_3 ) ;
if ( ! V_119 )
return;
F_62 ( & V_119 -> V_146 ) ;
F_63 (ifa, &idev->addr_list, if_list) {
F_28 ( & V_144 -> V_42 , & V_145 ) ;
F_56 ( V_3 , NULL , & V_145 , & V_144 -> V_42 ,
! ! V_119 -> V_138 . V_147 ,
false , true ,
true ) ;
}
F_64 ( & V_119 -> V_146 ) ;
F_25 ( V_119 ) ;
}
void F_65 ( struct V_2 * V_3 , struct V_55 * V_56 ,
const struct V_41 * V_148 ,
const struct V_41 * V_90 , const struct V_41 * V_91 )
{
struct V_41 V_149 ;
struct V_92 V_93 = {
. V_120 = V_150 ,
} ;
if ( V_91 == NULL ) {
if ( F_66 ( V_3 , & V_149 ,
( V_151 | V_137 ) ) )
return;
V_91 = & V_149 ;
}
F_55 ( V_3 , V_56 , V_90 , V_91 ,
& V_93 , V_148 ,
! F_67 ( V_91 ) ? V_22 : 0 ) ;
}
void F_68 ( struct V_2 * V_3 , const struct V_41 * V_91 ,
const struct V_41 * V_90 )
{
struct V_92 V_93 = {
. V_120 = V_152 ,
} ;
int V_153 = V_3 -> V_4 ;
#ifdef F_69
if ( V_153 ) {
struct V_133 * V_134 = F_57 ( F_33 ( V_3 ) , V_91 ,
V_3 , 1 ) ;
if ( V_134 ) {
if ( V_134 -> V_74 & V_137 ) {
V_153 = 0 ;
}
F_58 ( V_134 ) ;
} else {
V_153 = 0 ;
}
}
#endif
F_55 ( V_3 , NULL , V_90 , V_91 ,
& V_93 , NULL ,
V_153 ? V_22 : 0 ) ;
}
static void F_70 ( struct V_55 * V_56 , struct V_89 * V_101 )
{
F_71 ( V_101 ) ;
F_47 ( V_101 ) ;
}
static void F_72 ( struct V_55 * V_56 , struct V_89 * V_101 )
{
struct V_41 * V_91 = NULL ;
struct V_41 V_145 ;
struct V_2 * V_3 = V_56 -> V_3 ;
struct V_41 * V_94 = (struct V_41 * ) & V_56 -> V_57 ;
int V_154 = F_73 ( & V_56 -> V_154 ) ;
if ( V_101 && F_74 ( F_33 ( V_3 ) , & F_75 ( V_101 ) -> V_91 , V_3 , 1 ) )
V_91 = & F_75 ( V_101 ) -> V_91 ;
if ( ( V_154 -= V_56 -> V_61 -> V_155 ) < 0 ) {
if ( ! ( V_56 -> V_67 & V_83 ) ) {
F_76 ( V_156 L_4 ,
V_28 , V_94 ) ;
}
F_65 ( V_3 , V_56 , V_94 , V_94 , V_91 ) ;
} else if ( ( V_154 -= V_56 -> V_61 -> V_157 ) < 0 ) {
#ifdef F_77
F_78 ( V_56 ) ;
#endif
} else {
F_28 ( V_94 , & V_145 ) ;
F_65 ( V_3 , NULL , V_94 , & V_145 , V_91 ) ;
}
}
static int F_79 ( const void * V_53 ,
struct V_2 * V_3 )
{
struct V_85 * V_86 ;
int V_158 = - 1 ;
F_62 ( & V_159 . V_146 ) ;
V_86 = F_80 ( & V_159 , F_33 ( V_3 ) , V_53 , V_3 ) ;
if ( V_86 )
V_158 = ! ! ( V_86 -> V_74 & V_160 ) ;
F_64 ( & V_159 . V_146 ) ;
return V_158 ;
}
static void F_81 ( struct V_89 * V_101 )
{
struct V_161 * V_162 = (struct V_161 * ) F_40 ( V_101 ) ;
const struct V_41 * V_91 = & F_75 ( V_101 ) -> V_91 ;
const struct V_41 * V_90 = & F_75 ( V_101 ) -> V_90 ;
T_1 * V_38 = NULL ;
T_2 V_163 = V_101 -> V_113 - ( V_101 -> V_112 +
F_82 ( struct V_161 , V_5 ) ) ;
struct V_17 V_19 ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_133 * V_134 ;
struct V_58 * V_119 = NULL ;
struct V_55 * V_56 ;
int V_164 = F_67 ( V_91 ) ;
int V_165 ;
int V_166 = - 1 ;
if ( F_21 ( & V_162 -> V_94 ) ) {
F_9 ( V_27
L_5 ) ;
return;
}
if ( V_164 &&
! ( V_90 -> V_167 [ 0 ] == F_83 ( 0xff020000 ) &&
V_90 -> V_167 [ 1 ] == F_83 ( 0x00000000 ) &&
V_90 -> V_167 [ 2 ] == F_83 ( 0x00000001 ) &&
V_90 -> V_168 [ 12 ] == 0xff ) ) {
F_9 ( V_27
L_6 ) ;
return;
}
if ( ! F_8 ( V_162 -> V_5 , V_163 , & V_19 ) ) {
F_9 ( V_27
L_7 ) ;
return;
}
if ( V_19 . V_169 ) {
V_38 = F_11 ( V_19 . V_169 , V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_8 ) ;
return;
}
if ( V_164 ) {
F_9 ( V_27
L_9 ) ;
return;
}
}
V_165 = F_21 ( V_90 ) ;
V_134 = F_57 ( F_33 ( V_3 ) , & V_162 -> V_94 , V_3 , 1 ) ;
if ( V_134 ) {
if ( V_134 -> V_74 & ( V_151 | V_137 ) ) {
if ( V_164 ) {
if ( V_3 -> type == V_48 ) {
const unsigned char * V_170 ;
V_170 = F_84 ( V_101 ) ;
if ( ( ( V_170 [ 8 ] ^ V_3 -> V_77 [ 0 ] ) & 0x7f ) == 0 &&
V_170 [ 9 ] == V_3 -> V_77 [ 1 ] &&
V_170 [ 10 ] == V_3 -> V_77 [ 2 ] &&
V_170 [ 11 ] == V_3 -> V_77 [ 3 ] &&
V_170 [ 12 ] == V_3 -> V_77 [ 4 ] &&
V_170 [ 13 ] == V_3 -> V_77 [ 5 ] ) {
goto V_171;
}
}
F_85 ( V_134 ) ;
return;
} else {
if ( ! ( V_134 -> V_74 & V_137 ) )
goto V_171;
}
}
V_119 = V_134 -> V_119 ;
} else {
struct V_96 * V_96 = F_33 ( V_3 ) ;
V_119 = F_22 ( V_3 ) ;
if ( ! V_119 ) {
return;
}
if ( F_86 ( V_96 , V_3 , & V_162 -> V_94 ) ||
( V_119 -> V_138 . V_147 &&
( V_96 -> V_99 . V_172 -> V_173 || V_119 -> V_138 . V_173 ) &&
( V_166 = F_79 ( & V_162 -> V_94 , V_3 ) ) >= 0 ) ) {
if ( ! ( F_87 ( V_101 ) -> V_74 & V_174 ) &&
V_101 -> V_175 != V_176 &&
V_165 != 0 &&
V_119 -> V_63 -> V_177 != 0 ) {
struct V_89 * V_86 = F_88 ( V_101 , V_178 ) ;
if ( V_86 )
F_89 ( & V_159 , V_119 -> V_63 , V_86 ) ;
goto V_171;
}
} else
goto V_171;
}
if ( V_166 < 0 )
V_166 = ! ! V_119 -> V_138 . V_147 ;
if ( V_164 ) {
F_56 ( V_3 , NULL , & V_179 , & V_162 -> V_94 ,
V_166 , 0 , ( V_134 != NULL ) , 1 ) ;
goto V_171;
}
if ( V_165 )
F_90 ( & V_159 , V_180 ) ;
else
F_90 ( & V_159 , V_181 ) ;
V_56 = F_91 ( & V_159 , V_91 , V_3 ,
! V_165 || V_38 || ! V_3 -> V_4 ) ;
if ( V_56 )
F_92 ( V_56 , V_38 , V_182 ,
V_183 |
V_184 ) ;
if ( V_56 || ! V_3 -> V_66 ) {
F_56 ( V_3 , V_56 , V_91 , & V_162 -> V_94 ,
V_166 ,
1 , ( V_134 != NULL && V_165 ) , V_165 ) ;
if ( V_56 )
F_93 ( V_56 ) ;
}
V_171:
if ( V_134 )
F_58 ( V_134 ) ;
else
F_25 ( V_119 ) ;
}
static void F_94 ( struct V_89 * V_101 )
{
struct V_161 * V_162 = (struct V_161 * ) F_40 ( V_101 ) ;
const struct V_41 * V_91 = & F_75 ( V_101 ) -> V_91 ;
const struct V_41 * V_90 = & F_75 ( V_101 ) -> V_90 ;
T_1 * V_38 = NULL ;
T_2 V_163 = V_101 -> V_113 - ( V_101 -> V_112 +
F_82 ( struct V_161 , V_5 ) ) ;
struct V_17 V_19 ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_133 * V_134 ;
struct V_55 * V_56 ;
if ( V_101 -> V_106 < sizeof( struct V_161 ) ) {
F_9 ( V_27
L_10 ) ;
return;
}
if ( F_21 ( & V_162 -> V_94 ) ) {
F_9 ( V_27
L_11 ) ;
return;
}
if ( F_21 ( V_90 ) &&
V_162 -> V_185 . V_142 ) {
F_9 ( V_27
L_12 ) ;
return;
}
if ( ! F_8 ( V_162 -> V_5 , V_163 , & V_19 ) ) {
F_9 ( V_27
L_13 ) ;
return;
}
if ( V_19 . V_186 ) {
V_38 = F_11 ( V_19 . V_186 , V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_14 ) ;
return;
}
}
V_134 = F_57 ( F_33 ( V_3 ) , & V_162 -> V_94 , V_3 , 1 ) ;
if ( V_134 ) {
if ( V_101 -> V_175 != V_187
&& ( V_134 -> V_74 & V_151 ) ) {
F_85 ( V_134 ) ;
return;
}
if ( V_101 -> V_175 != V_187 )
F_76 ( V_27
L_15 ,
& V_134 -> V_42 , V_134 -> V_119 -> V_3 -> V_188 ) ;
F_58 ( V_134 ) ;
return;
}
V_56 = F_95 ( & V_159 , & V_162 -> V_94 , V_3 ) ;
if ( V_56 ) {
T_1 V_189 = V_56 -> V_74 ;
struct V_96 * V_96 = F_33 ( V_3 ) ;
if ( V_56 -> V_67 & V_190 )
goto V_171;
if ( V_38 && ! memcmp ( V_38 , V_3 -> V_77 , V_3 -> V_4 ) &&
V_96 -> V_99 . V_172 -> V_147 && V_96 -> V_99 . V_172 -> V_173 &&
F_96 ( & V_159 , V_96 , & V_162 -> V_94 , V_3 , 0 ) ) {
goto V_171;
}
F_92 ( V_56 , V_38 ,
V_162 -> V_185 . V_142 ? V_191 : V_182 ,
V_183 |
( V_162 -> V_185 . V_143 ? V_184 : 0 ) |
V_192 |
( V_162 -> V_185 . V_141 ? V_193 : 0 ) ) ;
if ( ( V_189 & ~ V_56 -> V_74 ) & V_160 ) {
struct V_194 * V_195 ;
V_195 = F_97 ( V_91 , V_3 ) ;
if ( V_195 )
F_98 ( V_195 ) ;
}
V_171:
F_93 ( V_56 ) ;
}
}
static void F_99 ( struct V_89 * V_101 )
{
struct V_196 * V_196 = (struct V_196 * ) F_40 ( V_101 ) ;
unsigned long V_163 = V_101 -> V_106 - sizeof( * V_196 ) ;
struct V_55 * V_56 ;
struct V_58 * V_119 ;
const struct V_41 * V_91 = & F_75 ( V_101 ) -> V_91 ;
struct V_17 V_19 ;
T_1 * V_38 = NULL ;
if ( V_101 -> V_106 < sizeof( * V_196 ) )
return;
V_119 = F_27 ( V_101 -> V_3 ) ;
if ( ! V_119 ) {
if ( F_100 () )
F_76 ( L_16 ) ;
return;
}
if ( ! V_119 -> V_138 . V_147 )
goto V_171;
if ( F_67 ( V_91 ) )
goto V_171;
if ( ! F_8 ( V_196 -> V_5 , V_163 , & V_19 ) ) {
if ( F_100 () )
F_9 ( L_17 ) ;
goto V_171;
}
if ( V_19 . V_169 ) {
V_38 = F_11 ( V_19 . V_169 ,
V_101 -> V_3 ) ;
if ( ! V_38 )
goto V_171;
}
V_56 = F_91 ( & V_159 , V_91 , V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
F_92 ( V_56 , V_38 , V_182 ,
V_183 |
V_184 |
V_192 ) ;
F_93 ( V_56 ) ;
}
V_171:
return;
}
static void F_101 ( struct V_89 * V_197 , struct V_11 * V_5 )
{
struct V_92 * V_93 = (struct V_92 * ) F_40 ( V_197 ) ;
struct V_89 * V_101 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_96 * V_96 = F_33 ( V_197 -> V_3 ) ;
int V_107 ;
int V_202 = F_102 ( sizeof( struct V_200 )
+ ( V_5 -> V_15 << 3 ) ) ;
T_4 V_203 = V_202 + F_103 ( sizeof( struct V_41 ) ) ;
V_101 = F_104 ( V_203 , V_178 ) ;
if ( V_101 == NULL ) {
V_107 = - V_204 ;
goto V_205;
}
V_199 = F_105 ( V_101 , 0 , 0 , V_206 , V_202 , 0 ) ;
if ( V_199 == NULL ) {
goto V_207;
}
V_201 = F_106 ( V_199 ) ;
V_201 -> V_208 = V_209 ;
V_201 -> V_210 = V_197 -> V_3 -> V_121 ;
V_201 -> V_211 = V_93 -> V_120 ;
V_201 -> V_212 = V_93 -> V_213 ;
V_201 -> V_214 = V_5 -> V_15 << 3 ;
memcpy ( V_201 + 1 , V_5 , V_5 -> V_15 << 3 ) ;
F_107 ( V_101 , V_215 , sizeof( struct V_41 ) ,
& F_75 ( V_197 ) -> V_91 ) ;
F_108 ( V_101 , V_199 ) ;
F_109 ( V_101 , V_96 , 0 , V_216 , NULL , V_178 ) ;
return;
V_207:
F_110 ( V_101 ) ;
V_107 = - V_217 ;
V_205:
F_111 ( V_96 , V_216 , V_107 ) ;
}
static inline int F_112 ( struct V_58 * V_59 )
{
if ( V_59 -> V_138 . V_147 && V_59 -> V_138 . F_112 < 2 )
return 0 ;
return V_59 -> V_138 . F_112 ;
}
static void F_113 ( struct V_89 * V_101 )
{
struct V_218 * V_218 = (struct V_218 * ) F_40 ( V_101 ) ;
struct V_55 * V_56 = NULL ;
struct V_58 * V_59 ;
struct V_194 * V_195 = NULL ;
int V_219 ;
struct V_17 V_19 ;
int V_220 ;
unsigned int V_221 = 0 ;
T_5 * V_5 = ( T_5 * ) ( V_218 + 1 ) ;
V_220 = ( V_101 -> V_113 - V_101 -> V_112 ) - sizeof( struct V_218 ) ;
if ( ! ( F_114 ( & F_75 ( V_101 ) -> V_91 ) & V_222 ) ) {
F_9 ( V_27
L_18 ) ;
return;
}
if ( V_220 < 0 ) {
F_9 ( V_27
L_19 ) ;
return;
}
#ifdef F_115
if ( V_101 -> V_223 == V_224 ) {
F_9 ( V_27
L_20 ) ;
return;
}
#endif
V_59 = F_27 ( V_101 -> V_3 ) ;
if ( V_59 == NULL ) {
F_36 ( V_110
L_21 ,
V_101 -> V_3 -> V_188 ) ;
return;
}
if ( ! F_8 ( V_5 , V_220 , & V_19 ) ) {
F_9 ( V_27
L_22 ) ;
return;
}
if ( ! F_112 ( V_59 ) )
goto V_225;
#ifdef F_115
if ( V_101 -> V_223 == V_226 )
goto V_225;
#endif
if ( V_59 -> V_227 & V_228 ) {
V_59 -> V_227 |= V_229 ;
}
V_59 -> V_227 = ( V_59 -> V_227 & ~ ( V_230 |
V_231 ) ) |
( V_218 -> V_185 . V_232 ?
V_230 : 0 ) |
( V_218 -> V_185 . V_233 ?
V_231 : 0 ) ;
if ( ! V_59 -> V_138 . V_234 )
goto V_235;
if ( F_74 ( F_33 ( V_59 -> V_3 ) , & F_75 ( V_101 ) -> V_91 , NULL , 0 ) )
goto V_235;
V_219 = F_116 ( V_218 -> V_185 . V_236 ) ;
#ifdef F_117
V_221 = V_218 -> V_185 . V_237 ;
if ( V_221 == V_238 ||
! V_59 -> V_138 . V_239 )
V_221 = V_240 ;
#endif
V_195 = F_97 ( & F_75 ( V_101 ) -> V_91 , V_101 -> V_3 ) ;
if ( V_195 ) {
V_56 = F_118 ( & V_195 -> V_118 , & F_75 ( V_101 ) -> V_91 ) ;
if ( ! V_56 ) {
F_36 ( V_110
L_23 ,
V_28 ) ;
F_119 ( & V_195 -> V_118 ) ;
return;
}
}
if ( V_195 && V_219 == 0 ) {
F_98 ( V_195 ) ;
V_195 = NULL ;
}
if ( V_195 == NULL && V_219 ) {
F_120 ( V_156
L_24 ) ;
V_195 = F_121 ( & F_75 ( V_101 ) -> V_91 , V_101 -> V_3 , V_221 ) ;
if ( V_195 == NULL ) {
F_36 ( V_110
L_25 ,
V_28 ) ;
return;
}
V_56 = F_118 ( & V_195 -> V_118 , & F_75 ( V_101 ) -> V_91 ) ;
if ( V_56 == NULL ) {
F_36 ( V_110
L_23 ,
V_28 ) ;
F_119 ( & V_195 -> V_118 ) ;
return;
}
V_56 -> V_74 |= V_160 ;
} else if ( V_195 ) {
V_195 -> V_241 = ( V_195 -> V_241 & ~ V_242 ) | F_122 ( V_221 ) ;
}
if ( V_195 )
F_123 ( V_195 , V_243 + ( V_244 * V_219 ) ) ;
if ( V_218 -> V_185 . V_245 ) {
V_59 -> V_138 . V_246 = V_218 -> V_185 . V_245 ;
if ( V_195 )
F_124 ( & V_195 -> V_118 , V_247 ,
V_218 -> V_185 . V_245 ) ;
}
V_235:
if ( V_59 -> V_63 ) {
unsigned long V_248 = F_125 ( V_218 -> V_249 ) ;
if ( V_248 && V_248 / 1000 < V_250 / V_244 ) {
V_248 = ( V_248 * V_244 ) / 1000 ;
if ( V_248 < V_244 / 10 )
V_248 = V_244 / 10 ;
V_59 -> V_63 -> V_251 = V_248 ;
V_59 -> V_252 = V_243 ;
F_126 ( V_253 , V_59 ) ;
}
V_248 = F_125 ( V_218 -> V_254 ) ;
if ( V_248 && V_248 / 1000 < V_250 / ( 3 * V_244 ) ) {
V_248 = ( V_248 * V_244 ) / 1000 ;
if ( V_248 < V_244 / 10 )
V_248 = V_244 / 10 ;
if ( V_248 != V_59 -> V_63 -> V_255 ) {
V_59 -> V_63 -> V_255 = V_248 ;
V_59 -> V_63 -> V_256 = 3 * V_248 ;
V_59 -> V_63 -> V_254 = F_127 ( V_248 ) ;
V_59 -> V_252 = V_243 ;
F_126 ( V_253 , V_59 ) ;
}
}
}
V_225:
if ( ! V_56 )
V_56 = F_91 ( & V_159 , & F_75 ( V_101 ) -> V_91 ,
V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
T_1 * V_38 = NULL ;
if ( V_19 . V_169 ) {
V_38 = F_11 ( V_19 . V_169 ,
V_101 -> V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_26 ) ;
goto V_171;
}
}
F_92 ( V_56 , V_38 , V_182 ,
V_183 |
V_184 |
V_192 |
V_193 ) ;
}
if ( ! F_112 ( V_59 ) )
goto V_171;
#ifdef F_10
if ( F_74 ( F_33 ( V_59 -> V_3 ) , & F_75 ( V_101 ) -> V_91 , NULL , 0 ) )
goto V_257;
if ( V_59 -> V_138 . V_239 && V_19 . V_33 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_33 ;
V_37 ;
V_37 = F_5 ( V_37 , V_19 . V_32 ) ) {
struct V_258 * V_259 = (struct V_258 * ) V_37 ;
#ifdef F_115
if ( V_101 -> V_223 == V_226 &&
V_259 -> V_260 == 0 )
continue;
#endif
if ( V_259 -> V_260 > V_59 -> V_138 . V_261 )
continue;
F_128 ( V_101 -> V_3 , ( T_1 * ) V_37 , ( V_37 -> V_15 ) << 3 ,
& F_75 ( V_101 ) -> V_91 ) ;
}
}
V_257:
#endif
#ifdef F_115
if ( V_101 -> V_223 == V_226 )
goto V_171;
#endif
if ( V_59 -> V_138 . V_262 && V_19 . V_263 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_263 ;
V_37 ;
V_37 = F_5 ( V_37 , V_19 . V_30 ) ) {
F_129 ( V_101 -> V_3 , ( T_1 * ) V_37 ,
( V_37 -> V_15 ) << 3 ,
V_19 . V_169 != NULL ) ;
}
}
if ( V_19 . V_264 ) {
T_6 V_86 ;
T_2 V_265 ;
memcpy ( & V_86 , ( ( T_1 * ) ( V_19 . V_264 + 1 ) ) + 2 , sizeof( V_265 ) ) ;
V_265 = F_125 ( V_86 ) ;
if ( V_265 < V_266 || V_265 > V_101 -> V_3 -> V_265 ) {
F_9 ( V_27
L_27 ,
V_265 ) ;
} else if ( V_59 -> V_138 . V_267 != V_265 ) {
V_59 -> V_138 . V_267 = V_265 ;
if ( V_195 )
F_124 ( & V_195 -> V_118 , V_268 , V_265 ) ;
F_130 ( V_101 -> V_3 , V_265 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_35 ;
V_37 ;
V_37 = F_7 ( V_37 , V_19 . V_34 ) ) {
F_101 ( V_101 , V_37 ) ;
}
}
if ( V_19 . V_186 || V_19 . V_269 ) {
F_9 ( V_27
L_28 ) ;
}
V_171:
if ( V_195 )
F_119 ( & V_195 -> V_118 ) ;
if ( V_56 )
F_93 ( V_56 ) ;
}
static void F_131 ( struct V_89 * V_101 )
{
struct V_58 * V_59 ;
struct V_92 * V_185 ;
const struct V_41 * V_270 ;
const struct V_41 * V_94 ;
struct V_55 * V_56 ;
int V_271 = 0 ;
struct V_17 V_19 ;
int V_220 ;
T_1 * V_38 = NULL ;
#ifdef F_115
switch ( V_101 -> V_223 ) {
case V_224 :
case V_226 :
F_9 ( V_27
L_29 ) ;
return;
}
#endif
if ( ! ( F_114 ( & F_75 ( V_101 ) -> V_91 ) & V_222 ) ) {
F_9 ( V_27
L_30 ) ;
return;
}
V_220 = V_101 -> V_113 - V_101 -> V_112 ;
V_220 -= sizeof( struct V_92 ) + 2 * sizeof( struct V_41 ) ;
if ( V_220 < 0 ) {
F_9 ( V_27
L_31 ) ;
return;
}
V_185 = F_132 ( V_101 ) ;
V_94 = ( const struct V_41 * ) ( V_185 + 1 ) ;
V_270 = V_94 + 1 ;
if ( F_21 ( V_270 ) ) {
F_9 ( V_27
L_32 ) ;
return;
}
if ( F_133 ( V_270 , V_94 ) ) {
V_271 = 1 ;
} else if ( F_114 ( V_94 ) !=
( V_272 | V_222 ) ) {
F_9 ( V_27
L_33 ) ;
return;
}
V_59 = F_27 ( V_101 -> V_3 ) ;
if ( ! V_59 )
return;
if ( V_59 -> V_138 . V_147 || ! V_59 -> V_138 . V_273 )
return;
if ( ! F_8 ( ( T_1 * ) ( V_270 + 1 ) , V_220 , & V_19 ) ) {
F_9 ( V_27
L_34 ) ;
return;
}
if ( V_19 . V_186 ) {
V_38 = F_11 ( V_19 . V_186 ,
V_101 -> V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_35 ) ;
return;
}
}
V_56 = F_91 ( & V_159 , V_94 , V_101 -> V_3 , 1 ) ;
if ( V_56 ) {
F_134 ( V_270 , & F_75 ( V_101 ) -> V_90 ,
& F_75 ( V_101 ) -> V_91 , V_56 , V_38 ,
V_271 ) ;
F_93 ( V_56 ) ;
}
}
void F_135 ( struct V_89 * V_101 , const struct V_41 * V_94 )
{
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_96 * V_96 = F_33 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_99 . V_100 ;
int V_106 = sizeof( struct V_92 ) + 2 * sizeof( struct V_41 ) ;
struct V_89 * V_274 ;
struct V_92 * V_185 ;
struct V_41 V_275 ;
struct V_41 * V_276 ;
struct V_194 * V_195 ;
struct V_117 * V_118 ;
struct V_58 * V_119 ;
struct V_115 V_116 ;
T_1 * V_5 ;
int V_103 , V_104 ;
int V_277 ;
int V_107 ;
T_1 V_278 [ V_279 ] , * V_73 = NULL ;
if ( F_66 ( V_3 , & V_275 , V_151 ) ) {
F_9 ( V_27
L_36 ,
V_3 -> V_188 ) ;
return;
}
if ( ! F_133 ( & F_75 ( V_101 ) -> V_90 , V_94 ) &&
F_114 ( V_94 ) != ( V_272 | V_222 ) ) {
F_9 ( V_27
L_33 ) ;
return;
}
F_44 ( V_98 , & V_116 , V_280 ,
& V_275 , & F_75 ( V_101 ) -> V_91 , V_3 -> V_121 ) ;
V_118 = F_136 ( V_96 , NULL , & V_116 ) ;
if ( V_118 -> error ) {
F_119 ( V_118 ) ;
return;
}
V_118 = F_137 ( V_96 , V_118 , F_138 ( & V_116 ) , NULL , 0 ) ;
if ( F_46 ( V_118 ) )
return;
V_195 = (struct V_194 * ) V_118 ;
if ( V_195 -> V_241 & V_281 ) {
F_9 ( V_27
L_37 ) ;
goto V_282;
}
if ( ! V_195 -> V_283 )
F_139 ( V_195 , 1 ) ;
if ( ! F_140 ( V_195 -> V_283 , 1 * V_244 ) )
goto V_282;
if ( V_3 -> V_4 ) {
struct V_55 * V_56 = F_118 ( F_141 ( V_101 ) , V_94 ) ;
if ( ! V_56 ) {
F_9 ( V_27
L_38 ) ;
goto V_282;
}
F_62 ( & V_56 -> V_146 ) ;
if ( V_56 -> V_67 & V_83 ) {
memcpy ( V_278 , V_56 -> V_73 , V_3 -> V_4 ) ;
F_64 ( & V_56 -> V_146 ) ;
V_73 = V_278 ;
V_106 += F_2 ( V_3 ) ;
} else
F_64 ( & V_56 -> V_146 ) ;
F_93 ( V_56 ) ;
}
V_277 = F_142 (unsigned int,
IPV6_MIN_MTU-sizeof(struct ipv6hdr)-len, skb->len + 8 ) ;
V_277 &= ~ 0x7 ;
V_106 += V_277 ;
V_103 = F_34 ( V_3 ) ;
V_104 = V_3 -> V_105 ;
V_274 = F_35 ( V_98 ,
( V_108 + sizeof( struct V_109 ) +
V_106 + V_103 + V_104 ) ,
1 , & V_107 ) ;
if ( V_274 == NULL ) {
F_36 ( V_110
L_39 ,
V_28 , V_107 ) ;
goto V_282;
}
F_37 ( V_274 , V_103 ) ;
F_38 ( V_98 , V_274 , V_3 , & V_275 , & F_75 ( V_101 ) -> V_91 ,
V_111 , V_106 ) ;
F_143 ( V_274 , F_144 ( V_274 ) - V_274 -> V_6 ) ;
F_39 ( V_274 , V_106 ) ;
V_185 = F_132 ( V_274 ) ;
memset ( V_185 , 0 , sizeof( struct V_92 ) ) ;
V_185 -> V_120 = V_280 ;
V_276 = (struct V_41 * ) ( V_185 + 1 ) ;
* V_276 = * V_94 ;
V_276 ++ ;
* V_276 = F_75 ( V_101 ) -> V_90 ;
V_5 = ( T_1 * ) ( V_276 + 1 ) ;
if ( V_73 )
V_5 = F_4 ( V_5 , V_23 , V_73 ,
V_3 -> V_4 , V_3 -> type ) ;
memset ( V_5 , 0 , 8 ) ;
* ( V_5 ++ ) = V_25 ;
* ( V_5 ++ ) = ( V_277 >> 3 ) ;
V_5 += 6 ;
memcpy ( V_5 , F_75 ( V_101 ) , V_277 - 8 ) ;
V_185 -> V_114 = F_41 ( & V_275 , & F_75 ( V_101 ) -> V_91 ,
V_106 , V_111 ,
F_42 ( V_185 , V_106 , 0 ) ) ;
F_48 ( V_274 , V_118 ) ;
F_49 () ;
V_119 = F_27 ( V_118 -> V_3 ) ;
F_50 ( V_96 , V_119 , V_122 , V_101 -> V_106 ) ;
V_107 = F_51 ( V_123 , V_124 , V_274 , NULL , V_118 -> V_3 ,
V_125 ) ;
if ( ! V_107 ) {
F_52 ( V_96 , V_119 , V_280 ) ;
F_53 ( V_96 , V_119 , V_126 ) ;
}
F_54 () ;
return;
V_282:
F_119 ( V_118 ) ;
}
static void F_145 ( struct V_89 * V_101 )
{
F_81 ( V_101 ) ;
F_47 ( V_101 ) ;
}
int F_146 ( struct V_89 * V_101 )
{
struct V_161 * V_162 ;
if ( ! F_147 ( V_101 , V_101 -> V_106 ) )
return 0 ;
V_162 = (struct V_161 * ) F_40 ( V_101 ) ;
F_148 ( V_101 , V_101 -> V_6 - F_40 ( V_101 ) ) ;
if ( F_75 ( V_101 ) -> V_246 != 255 ) {
F_9 ( V_27
L_40 ,
F_75 ( V_101 ) -> V_246 ) ;
return 0 ;
}
if ( V_162 -> V_185 . V_213 != 0 ) {
F_9 ( V_27
L_41 ,
V_162 -> V_185 . V_213 ) ;
return 0 ;
}
memset ( F_87 ( V_101 ) , 0 , sizeof( struct V_284 ) ) ;
switch ( V_162 -> V_185 . V_120 ) {
case V_150 :
F_81 ( V_101 ) ;
break;
case V_136 :
F_94 ( V_101 ) ;
break;
case V_152 :
F_99 ( V_101 ) ;
break;
case V_285 :
F_113 ( V_101 ) ;
break;
case V_280 :
F_131 ( V_101 ) ;
break;
}
return 0 ;
}
static int F_149 ( struct V_286 * V_287 , unsigned long V_288 , void * V_289 )
{
struct V_2 * V_3 = V_289 ;
struct V_96 * V_96 = F_33 ( V_3 ) ;
switch ( V_288 ) {
case V_290 :
F_150 ( & V_159 , V_3 ) ;
F_151 ( ~ 0UL , V_96 ) ;
break;
case V_291 :
F_152 ( & V_159 , V_3 ) ;
F_151 ( ~ 0UL , V_96 ) ;
break;
case V_292 :
F_61 ( V_3 ) ;
break;
default:
break;
}
return V_293 ;
}
static void F_153 ( struct V_294 * V_295 ,
const char * V_296 , const char * V_297 )
{
static char V_298 [ V_299 ] ;
static int V_300 ;
if ( strcmp ( V_298 , V_301 -> V_302 ) && V_300 < 5 ) {
strcpy ( V_298 , V_301 -> V_302 ) ;
F_154 ( V_27
L_42
L_43
L_44
L_45 ,
V_298 , V_296 ,
V_297 , V_295 -> V_303 ,
V_297 , V_295 -> V_303 ) ;
V_300 ++ ;
}
}
int F_155 ( struct V_294 * V_295 , int V_304 , void T_7 * V_305 , T_4 * V_306 , T_8 * V_307 )
{
struct V_2 * V_3 = V_295 -> V_308 ;
struct V_58 * V_119 ;
int V_158 ;
if ( ( strcmp ( V_295 -> V_303 , L_46 ) == 0 ) ||
( strcmp ( V_295 -> V_303 , L_47 ) == 0 ) )
F_153 ( V_295 , L_48 , V_3 ? V_3 -> V_188 : L_49 ) ;
if ( strcmp ( V_295 -> V_303 , L_46 ) == 0 )
V_158 = F_156 ( V_295 , V_304 , V_305 , V_306 , V_307 ) ;
else if ( strcmp ( V_295 -> V_303 , L_47 ) == 0 )
V_158 = F_157 ( V_295 , V_304 ,
V_305 , V_306 , V_307 ) ;
else if ( ( strcmp ( V_295 -> V_303 , L_50 ) == 0 ) ||
( strcmp ( V_295 -> V_303 , L_51 ) == 0 ) )
V_158 = F_158 ( V_295 , V_304 ,
V_305 , V_306 , V_307 ) ;
else
V_158 = - 1 ;
if ( V_304 && V_158 == 0 && V_3 && ( V_119 = F_22 ( V_3 ) ) != NULL ) {
if ( V_295 -> V_6 == & V_119 -> V_63 -> V_255 )
V_119 -> V_63 -> V_254 = F_127 ( V_119 -> V_63 -> V_255 ) ;
V_119 -> V_252 = V_243 ;
F_126 ( V_253 , V_119 ) ;
F_25 ( V_119 ) ;
}
return V_158 ;
}
static int T_9 F_159 ( struct V_96 * V_96 )
{
struct V_309 * V_310 ;
struct V_97 * V_98 ;
int V_107 ;
V_107 = F_160 ( & V_98 , V_311 ,
V_312 , V_111 , V_96 ) ;
if ( V_107 < 0 ) {
F_36 ( V_110
L_52 ,
V_107 ) ;
return V_107 ;
}
V_96 -> V_99 . V_100 = V_98 ;
V_310 = F_60 ( V_98 ) ;
V_310 -> V_246 = 255 ;
V_310 -> V_313 = 0 ;
return 0 ;
}
static void T_10 F_161 ( struct V_96 * V_96 )
{
F_162 ( V_96 -> V_99 . V_100 ) ;
}
int T_11 F_163 ( void )
{
int V_107 ;
V_107 = F_164 ( & V_314 ) ;
if ( V_107 )
return V_107 ;
F_165 ( & V_159 ) ;
#ifdef F_166
V_107 = F_167 ( NULL , & V_159 . V_61 , L_53 ,
& F_155 ) ;
if ( V_107 )
goto V_315;
#endif
V_107 = F_168 ( & V_316 ) ;
if ( V_107 )
goto V_317;
V_171:
return V_107 ;
V_317:
#ifdef F_166
F_169 ( & V_159 . V_61 ) ;
V_315:
#endif
F_170 ( & V_314 ) ;
goto V_171;
}
void F_171 ( void )
{
F_172 ( & V_316 ) ;
#ifdef F_166
F_169 ( & V_159 . V_61 ) ;
#endif
F_173 ( & V_159 ) ;
F_170 ( & V_314 ) ;
}
