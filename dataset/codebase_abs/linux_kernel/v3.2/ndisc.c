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
T_3 V_54 )
{
const T_2 * V_55 = V_53 ;
T_2 V_56 , V_57 ;
V_56 = 0 ;
for ( V_57 = 0 ; V_57 < ( sizeof( struct V_41 ) / sizeof( T_2 ) ) ; V_57 ++ )
V_56 ^= * V_55 ++ ;
return F_19 ( V_56 , V_3 -> V_58 , V_54 ) ;
}
static int F_20 ( struct V_59 * V_60 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_60 -> V_61 ;
struct V_2 * V_3 = V_60 -> V_3 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int V_66 = F_21 ( V_42 ) ;
V_63 = F_22 ( V_3 ) ;
if ( V_63 == NULL ) {
return - V_52 ;
}
V_65 = V_63 -> V_67 ;
F_23 ( V_60 -> V_65 ) ;
V_60 -> V_65 = F_24 ( V_65 ) ;
V_60 -> type = V_66 ? V_68 : V_69 ;
if ( ! V_3 -> V_70 ) {
V_60 -> V_71 = V_72 ;
V_60 -> V_73 = & V_74 ;
V_60 -> V_75 = V_76 ;
} else {
if ( V_66 ) {
V_60 -> V_71 = V_72 ;
F_12 ( V_42 , V_60 -> V_77 , V_3 , 1 ) ;
} else if ( V_3 -> V_78 & ( V_79 | V_80 ) ) {
V_60 -> V_71 = V_72 ;
memcpy ( V_60 -> V_77 , V_3 -> V_81 , V_3 -> V_4 ) ;
if ( V_3 -> V_78 & V_80 )
V_60 -> type = V_82 ;
} else if ( V_3 -> V_78 & V_83 ) {
V_60 -> V_71 = V_72 ;
memcpy ( V_60 -> V_77 , V_3 -> V_50 , V_3 -> V_4 ) ;
}
if ( V_3 -> V_70 -> V_84 )
V_60 -> V_73 = & V_85 ;
else
V_60 -> V_73 = & V_86 ;
if ( V_60 -> V_71 & V_87 )
V_60 -> V_75 = V_60 -> V_73 -> V_88 ;
else
V_60 -> V_75 = V_60 -> V_73 -> V_75 ;
}
F_25 ( V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_89 * V_90 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_90 -> V_91 ;
struct V_41 V_92 ;
struct V_2 * V_3 = V_90 -> V_3 ;
if ( V_3 == NULL || F_27 ( V_3 ) == NULL )
return - V_52 ;
F_28 ( V_42 , & V_92 ) ;
F_29 ( V_3 , & V_92 ) ;
return 0 ;
}
static void F_30 ( struct V_89 * V_90 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_90 -> V_91 ;
struct V_41 V_92 ;
struct V_2 * V_3 = V_90 -> V_3 ;
if ( V_3 == NULL || F_27 ( V_3 ) == NULL )
return;
F_28 ( V_42 , & V_92 ) ;
F_31 ( V_3 , & V_92 ) ;
}
struct V_93 * F_32 ( struct V_2 * V_3 ,
const struct V_41 * V_94 ,
const struct V_41 * V_95 ,
struct V_96 * V_97 ,
const struct V_41 * V_98 ,
int V_99 )
{
struct V_100 * V_100 = F_33 ( V_3 ) ;
struct V_101 * V_102 = V_100 -> V_103 . V_104 ;
struct V_93 * V_105 ;
struct V_96 * V_106 ;
int V_107 ;
int V_108 ;
T_1 * V_5 ;
if ( ! V_3 -> V_4 )
V_99 = 0 ;
V_107 = sizeof( struct V_96 ) + ( V_98 ? sizeof( * V_98 ) : 0 ) ;
if ( V_99 )
V_107 += F_2 ( V_3 ) ;
V_105 = F_34 ( V_102 ,
( V_109 + sizeof( struct V_110 ) +
V_107 + F_35 ( V_3 ) ) ,
1 , & V_108 ) ;
if ( ! V_105 ) {
F_36 ( V_111
L_3 ,
V_28 , V_108 ) ;
return NULL ;
}
F_37 ( V_105 , F_38 ( V_3 ) ) ;
F_39 ( V_102 , V_105 , V_3 , V_95 , V_94 , V_112 , V_107 ) ;
V_105 -> V_113 = V_105 -> V_114 ;
F_40 ( V_105 , V_107 ) ;
V_106 = (struct V_96 * ) F_41 ( V_105 ) ;
memcpy ( V_106 , V_97 , sizeof( * V_106 ) ) ;
V_5 = F_41 ( V_105 ) + sizeof( struct V_96 ) ;
if ( V_98 ) {
F_42 ( (struct V_41 * ) V_5 , V_98 ) ;
V_5 += sizeof( * V_98 ) ;
}
if ( V_99 )
F_4 ( V_5 , V_99 , V_3 -> V_81 ,
V_3 -> V_4 , V_3 -> type ) ;
V_106 -> V_115 = F_43 ( V_95 , V_94 , V_107 ,
V_112 ,
F_44 ( V_106 ,
V_107 , 0 ) ) ;
return V_105 ;
}
void F_45 ( struct V_93 * V_105 ,
struct V_2 * V_3 ,
struct V_59 * V_60 ,
const struct V_41 * V_94 ,
const struct V_41 * V_95 ,
struct V_96 * V_97 )
{
struct V_116 V_117 ;
struct V_118 * V_119 ;
struct V_100 * V_100 = F_33 ( V_3 ) ;
struct V_101 * V_102 = V_100 -> V_103 . V_104 ;
struct V_62 * V_120 ;
int V_108 ;
T_1 type ;
type = V_97 -> V_121 ;
F_46 ( V_102 , & V_117 , type , V_95 , V_94 , V_3 -> V_58 ) ;
V_119 = F_47 ( V_3 , V_60 , V_94 ) ;
if ( ! V_119 ) {
F_48 ( V_105 ) ;
return;
}
V_119 = F_49 ( V_100 , V_119 , F_50 ( & V_117 ) , NULL , 0 ) ;
if ( F_51 ( V_119 ) ) {
F_48 ( V_105 ) ;
return;
}
F_52 ( V_105 , V_119 ) ;
F_53 () ;
V_120 = F_27 ( V_119 -> V_3 ) ;
F_54 ( V_100 , V_120 , V_122 , V_105 -> V_107 ) ;
V_108 = F_55 ( V_123 , V_124 , V_105 , NULL , V_119 -> V_3 ,
V_125 ) ;
if ( ! V_108 ) {
F_56 ( V_100 , V_120 , type ) ;
F_57 ( V_100 , V_120 , V_126 ) ;
}
F_58 () ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_59 * V_60 ,
const struct V_41 * V_94 ,
const struct V_41 * V_95 ,
struct V_96 * V_97 , const struct V_41 * V_98 ,
int V_99 )
{
struct V_93 * V_105 ;
V_105 = F_32 ( V_3 , V_94 , V_95 , V_97 , V_98 , V_99 ) ;
if ( ! V_105 )
return;
F_45 ( V_105 , V_3 , V_60 , V_94 , V_95 , V_97 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_59 * V_60 ,
const struct V_41 * V_94 ,
const struct V_41 * V_127 ,
int V_128 , int V_129 , int V_130 , int V_131 )
{
struct V_41 V_132 ;
struct V_133 * V_134 ;
const struct V_41 * V_135 ;
struct V_96 V_97 = {
. V_121 = V_136 ,
} ;
V_134 = F_61 ( F_33 ( V_3 ) , V_127 , V_3 , 1 ) ;
if ( V_134 ) {
V_135 = V_127 ;
if ( V_134 -> V_78 & V_137 )
V_130 = 0 ;
V_131 |= V_134 -> V_120 -> V_138 . V_139 ;
F_62 ( V_134 ) ;
} else {
if ( F_63 ( F_33 ( V_3 ) , V_3 , V_94 ,
F_64 ( F_33 ( V_3 ) -> V_103 . V_104 ) -> V_140 ,
& V_132 ) )
return;
V_135 = & V_132 ;
}
V_97 . V_141 = V_128 ;
V_97 . V_142 = V_129 ;
V_97 . V_143 = V_130 ;
F_59 ( V_3 , V_60 , V_94 , V_135 ,
& V_97 , V_127 ,
V_131 ? V_23 : 0 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_62 * V_120 ;
struct V_133 * V_144 ;
struct V_41 V_145 ;
V_120 = F_22 ( V_3 ) ;
if ( ! V_120 )
return;
F_66 ( & V_120 -> V_146 ) ;
F_67 (ifa, &idev->addr_list, if_list) {
F_28 ( & V_144 -> V_42 , & V_145 ) ;
F_60 ( V_3 , NULL , & V_145 , & V_144 -> V_42 ,
! ! V_120 -> V_138 . V_147 ,
false , true ,
true ) ;
}
F_68 ( & V_120 -> V_146 ) ;
F_25 ( V_120 ) ;
}
void F_69 ( struct V_2 * V_3 , struct V_59 * V_60 ,
const struct V_41 * V_148 ,
const struct V_41 * V_94 , const struct V_41 * V_95 )
{
struct V_41 V_149 ;
struct V_96 V_97 = {
. V_121 = V_150 ,
} ;
if ( V_95 == NULL ) {
if ( F_70 ( V_3 , & V_149 ,
( V_151 | V_137 ) ) )
return;
V_95 = & V_149 ;
}
F_59 ( V_3 , V_60 , V_94 , V_95 ,
& V_97 , V_148 ,
! F_71 ( V_95 ) ? V_22 : 0 ) ;
}
void F_72 ( struct V_2 * V_3 , const struct V_41 * V_95 ,
const struct V_41 * V_94 )
{
struct V_96 V_97 = {
. V_121 = V_152 ,
} ;
int V_153 = V_3 -> V_4 ;
#ifdef F_73
if ( V_153 ) {
struct V_133 * V_134 = F_61 ( F_33 ( V_3 ) , V_95 ,
V_3 , 1 ) ;
if ( V_134 ) {
if ( V_134 -> V_78 & V_137 ) {
V_153 = 0 ;
}
F_62 ( V_134 ) ;
} else {
V_153 = 0 ;
}
}
#endif
F_59 ( V_3 , NULL , V_94 , V_95 ,
& V_97 , NULL ,
V_153 ? V_22 : 0 ) ;
}
static void F_74 ( struct V_59 * V_60 , struct V_93 * V_105 )
{
F_75 ( V_105 ) ;
F_48 ( V_105 ) ;
}
static void F_76 ( struct V_59 * V_60 , struct V_93 * V_105 )
{
struct V_41 * V_95 = NULL ;
struct V_41 V_145 ;
struct V_2 * V_3 = V_60 -> V_3 ;
struct V_41 * V_98 = (struct V_41 * ) & V_60 -> V_61 ;
int V_154 = F_77 ( & V_60 -> V_154 ) ;
if ( V_105 && F_78 ( F_33 ( V_3 ) , & F_79 ( V_105 ) -> V_95 , V_3 , 1 ) )
V_95 = & F_79 ( V_105 ) -> V_95 ;
if ( ( V_154 -= V_60 -> V_65 -> V_155 ) < 0 ) {
if ( ! ( V_60 -> V_71 & V_87 ) ) {
F_80 ( V_156 L_4 ,
V_28 , V_98 ) ;
}
F_69 ( V_3 , V_60 , V_98 , V_98 , V_95 ) ;
} else if ( ( V_154 -= V_60 -> V_65 -> V_157 ) < 0 ) {
#ifdef F_81
F_82 ( V_60 ) ;
#endif
} else {
F_28 ( V_98 , & V_145 ) ;
F_69 ( V_3 , NULL , V_98 , & V_145 , V_95 ) ;
}
}
static int F_83 ( const void * V_53 ,
struct V_2 * V_3 )
{
struct V_89 * V_90 ;
int V_158 = - 1 ;
F_66 ( & V_159 . V_146 ) ;
V_90 = F_84 ( & V_159 , F_33 ( V_3 ) , V_53 , V_3 ) ;
if ( V_90 )
V_158 = ! ! ( V_90 -> V_78 & V_160 ) ;
F_68 ( & V_159 . V_146 ) ;
return V_158 ;
}
static void F_85 ( struct V_93 * V_105 )
{
struct V_161 * V_162 = (struct V_161 * ) F_41 ( V_105 ) ;
const struct V_41 * V_95 = & F_79 ( V_105 ) -> V_95 ;
const struct V_41 * V_94 = & F_79 ( V_105 ) -> V_94 ;
T_1 * V_38 = NULL ;
T_2 V_163 = V_105 -> V_114 - ( V_105 -> V_113 +
F_86 ( struct V_161 , V_5 ) ) ;
struct V_17 V_19 ;
struct V_2 * V_3 = V_105 -> V_3 ;
struct V_133 * V_134 ;
struct V_62 * V_120 = NULL ;
struct V_59 * V_60 ;
int V_164 = F_71 ( V_95 ) ;
int V_165 ;
int V_166 = - 1 ;
if ( F_21 ( & V_162 -> V_98 ) ) {
F_9 ( V_27
L_5 ) ;
return;
}
if ( V_164 &&
! ( V_94 -> V_167 [ 0 ] == F_87 ( 0xff020000 ) &&
V_94 -> V_167 [ 1 ] == F_87 ( 0x00000000 ) &&
V_94 -> V_167 [ 2 ] == F_87 ( 0x00000001 ) &&
V_94 -> V_168 [ 12 ] == 0xff ) ) {
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
V_165 = F_21 ( V_94 ) ;
V_134 = F_61 ( F_33 ( V_3 ) , & V_162 -> V_98 , V_3 , 1 ) ;
if ( V_134 ) {
if ( V_134 -> V_78 & ( V_151 | V_137 ) ) {
if ( V_164 ) {
if ( V_3 -> type == V_48 ) {
const unsigned char * V_170 ;
V_170 = F_88 ( V_105 ) ;
if ( ( ( V_170 [ 8 ] ^ V_3 -> V_81 [ 0 ] ) & 0x7f ) == 0 &&
V_170 [ 9 ] == V_3 -> V_81 [ 1 ] &&
V_170 [ 10 ] == V_3 -> V_81 [ 2 ] &&
V_170 [ 11 ] == V_3 -> V_81 [ 3 ] &&
V_170 [ 12 ] == V_3 -> V_81 [ 4 ] &&
V_170 [ 13 ] == V_3 -> V_81 [ 5 ] ) {
goto V_171;
}
}
F_89 ( V_134 ) ;
return;
} else {
if ( ! ( V_134 -> V_78 & V_137 ) )
goto V_171;
}
}
V_120 = V_134 -> V_120 ;
} else {
struct V_100 * V_100 = F_33 ( V_3 ) ;
V_120 = F_22 ( V_3 ) ;
if ( ! V_120 ) {
return;
}
if ( F_90 ( V_100 , V_3 , & V_162 -> V_98 ) ||
( V_120 -> V_138 . V_147 &&
( V_100 -> V_103 . V_172 -> V_173 || V_120 -> V_138 . V_173 ) &&
( V_166 = F_83 ( & V_162 -> V_98 , V_3 ) ) >= 0 ) ) {
if ( ! ( F_91 ( V_105 ) -> V_78 & V_174 ) &&
V_105 -> V_175 != V_176 &&
V_165 != 0 &&
V_120 -> V_67 -> V_177 != 0 ) {
struct V_93 * V_90 = F_92 ( V_105 , V_178 ) ;
if ( V_90 )
F_93 ( & V_159 , V_120 -> V_67 , V_90 ) ;
goto V_171;
}
} else
goto V_171;
}
if ( V_166 < 0 )
V_166 = ! ! V_120 -> V_138 . V_147 ;
if ( V_164 ) {
F_60 ( V_3 , NULL , & V_179 , & V_162 -> V_98 ,
V_166 , 0 , ( V_134 != NULL ) , 1 ) ;
goto V_171;
}
if ( V_165 )
F_94 ( & V_159 , V_180 ) ;
else
F_94 ( & V_159 , V_181 ) ;
V_60 = F_95 ( & V_159 , V_95 , V_3 ,
! V_165 || V_38 || ! V_3 -> V_4 ) ;
if ( V_60 )
F_96 ( V_60 , V_38 , V_182 ,
V_183 |
V_184 ) ;
if ( V_60 || ! V_3 -> V_70 ) {
F_60 ( V_3 , V_60 , V_95 , & V_162 -> V_98 ,
V_166 ,
1 , ( V_134 != NULL && V_165 ) , V_165 ) ;
if ( V_60 )
F_97 ( V_60 ) ;
}
V_171:
if ( V_134 )
F_62 ( V_134 ) ;
else
F_25 ( V_120 ) ;
}
static void F_98 ( struct V_93 * V_105 )
{
struct V_161 * V_162 = (struct V_161 * ) F_41 ( V_105 ) ;
const struct V_41 * V_95 = & F_79 ( V_105 ) -> V_95 ;
const struct V_41 * V_94 = & F_79 ( V_105 ) -> V_94 ;
T_1 * V_38 = NULL ;
T_2 V_163 = V_105 -> V_114 - ( V_105 -> V_113 +
F_86 ( struct V_161 , V_5 ) ) ;
struct V_17 V_19 ;
struct V_2 * V_3 = V_105 -> V_3 ;
struct V_133 * V_134 ;
struct V_59 * V_60 ;
if ( V_105 -> V_107 < sizeof( struct V_161 ) ) {
F_9 ( V_27
L_10 ) ;
return;
}
if ( F_21 ( & V_162 -> V_98 ) ) {
F_9 ( V_27
L_11 ) ;
return;
}
if ( F_21 ( V_94 ) &&
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
V_134 = F_61 ( F_33 ( V_3 ) , & V_162 -> V_98 , V_3 , 1 ) ;
if ( V_134 ) {
if ( V_105 -> V_175 != V_187
&& ( V_134 -> V_78 & V_151 ) ) {
F_89 ( V_134 ) ;
return;
}
if ( V_105 -> V_175 != V_187 )
F_80 ( V_27
L_15 ,
& V_134 -> V_42 , V_134 -> V_120 -> V_3 -> V_188 ) ;
F_62 ( V_134 ) ;
return;
}
V_60 = F_99 ( & V_159 , & V_162 -> V_98 , V_3 ) ;
if ( V_60 ) {
T_1 V_189 = V_60 -> V_78 ;
struct V_100 * V_100 = F_33 ( V_3 ) ;
if ( V_60 -> V_71 & V_190 )
goto V_171;
if ( V_38 && ! memcmp ( V_38 , V_3 -> V_81 , V_3 -> V_4 ) &&
V_100 -> V_103 . V_172 -> V_147 && V_100 -> V_103 . V_172 -> V_173 &&
F_100 ( & V_159 , V_100 , & V_162 -> V_98 , V_3 , 0 ) ) {
goto V_171;
}
F_96 ( V_60 , V_38 ,
V_162 -> V_185 . V_142 ? V_191 : V_182 ,
V_183 |
( V_162 -> V_185 . V_143 ? V_184 : 0 ) |
V_192 |
( V_162 -> V_185 . V_141 ? V_193 : 0 ) ) ;
if ( ( V_189 & ~ V_60 -> V_78 ) & V_160 ) {
struct V_194 * V_195 ;
V_195 = F_101 ( V_95 , V_3 ) ;
if ( V_195 )
F_102 ( V_195 ) ;
}
V_171:
F_97 ( V_60 ) ;
}
}
static void F_103 ( struct V_93 * V_105 )
{
struct V_196 * V_196 = (struct V_196 * ) F_41 ( V_105 ) ;
unsigned long V_163 = V_105 -> V_107 - sizeof( * V_196 ) ;
struct V_59 * V_60 ;
struct V_62 * V_120 ;
const struct V_41 * V_95 = & F_79 ( V_105 ) -> V_95 ;
struct V_17 V_19 ;
T_1 * V_38 = NULL ;
if ( V_105 -> V_107 < sizeof( * V_196 ) )
return;
V_120 = F_27 ( V_105 -> V_3 ) ;
if ( ! V_120 ) {
if ( F_104 () )
F_80 ( L_16 ) ;
return;
}
if ( ! V_120 -> V_138 . V_147 )
goto V_171;
if ( F_71 ( V_95 ) )
goto V_171;
if ( ! F_8 ( V_196 -> V_5 , V_163 , & V_19 ) ) {
if ( F_104 () )
F_9 ( L_17 ) ;
goto V_171;
}
if ( V_19 . V_169 ) {
V_38 = F_11 ( V_19 . V_169 ,
V_105 -> V_3 ) ;
if ( ! V_38 )
goto V_171;
}
V_60 = F_95 ( & V_159 , V_95 , V_105 -> V_3 , 1 ) ;
if ( V_60 ) {
F_96 ( V_60 , V_38 , V_182 ,
V_183 |
V_184 |
V_192 ) ;
F_97 ( V_60 ) ;
}
V_171:
return;
}
static void F_105 ( struct V_93 * V_197 , struct V_11 * V_5 )
{
struct V_96 * V_97 = (struct V_96 * ) F_41 ( V_197 ) ;
struct V_93 * V_105 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_100 * V_100 = F_33 ( V_197 -> V_3 ) ;
int V_108 ;
int V_202 = F_106 ( sizeof( struct V_200 )
+ ( V_5 -> V_15 << 3 ) ) ;
T_4 V_203 = V_202 + F_107 ( sizeof( struct V_41 ) ) ;
V_105 = F_108 ( V_203 , V_178 ) ;
if ( V_105 == NULL ) {
V_108 = - V_204 ;
goto V_205;
}
V_199 = F_109 ( V_105 , 0 , 0 , V_206 , V_202 , 0 ) ;
if ( V_199 == NULL ) {
goto V_207;
}
V_201 = F_110 ( V_199 ) ;
V_201 -> V_208 = V_209 ;
V_201 -> V_210 = V_197 -> V_3 -> V_58 ;
V_201 -> V_211 = V_97 -> V_121 ;
V_201 -> V_212 = V_97 -> V_213 ;
V_201 -> V_214 = V_5 -> V_15 << 3 ;
memcpy ( V_201 + 1 , V_5 , V_5 -> V_15 << 3 ) ;
F_111 ( V_105 , V_215 , sizeof( struct V_41 ) ,
& F_79 ( V_197 ) -> V_95 ) ;
F_112 ( V_105 , V_199 ) ;
F_113 ( V_105 , V_100 , 0 , V_216 , NULL , V_178 ) ;
return;
V_207:
F_114 ( V_105 ) ;
V_108 = - V_217 ;
V_205:
F_115 ( V_100 , V_216 , V_108 ) ;
}
static inline int F_116 ( struct V_62 * V_63 )
{
if ( V_63 -> V_138 . V_147 && V_63 -> V_138 . F_116 < 2 )
return 0 ;
return V_63 -> V_138 . F_116 ;
}
static void F_117 ( struct V_93 * V_105 )
{
struct V_218 * V_218 = (struct V_218 * ) F_41 ( V_105 ) ;
struct V_59 * V_60 = NULL ;
struct V_62 * V_63 ;
struct V_194 * V_195 = NULL ;
int V_219 ;
struct V_17 V_19 ;
int V_220 ;
unsigned int V_221 = 0 ;
T_5 * V_5 = ( T_5 * ) ( V_218 + 1 ) ;
V_220 = ( V_105 -> V_114 - V_105 -> V_113 ) - sizeof( struct V_218 ) ;
if ( ! ( F_118 ( & F_79 ( V_105 ) -> V_95 ) & V_222 ) ) {
F_9 ( V_27
L_18 ) ;
return;
}
if ( V_220 < 0 ) {
F_9 ( V_27
L_19 ) ;
return;
}
#ifdef F_119
if ( V_105 -> V_223 == V_224 ) {
F_9 ( V_27
L_20 ) ;
return;
}
#endif
V_63 = F_27 ( V_105 -> V_3 ) ;
if ( V_63 == NULL ) {
F_36 ( V_111
L_21 ,
V_105 -> V_3 -> V_188 ) ;
return;
}
if ( ! F_8 ( V_5 , V_220 , & V_19 ) ) {
F_9 ( V_27
L_22 ) ;
return;
}
if ( ! F_116 ( V_63 ) )
goto V_225;
#ifdef F_119
if ( V_105 -> V_223 == V_226 )
goto V_225;
#endif
if ( V_63 -> V_227 & V_228 ) {
V_63 -> V_227 |= V_229 ;
}
V_63 -> V_227 = ( V_63 -> V_227 & ~ ( V_230 |
V_231 ) ) |
( V_218 -> V_185 . V_232 ?
V_230 : 0 ) |
( V_218 -> V_185 . V_233 ?
V_231 : 0 ) ;
if ( ! V_63 -> V_138 . V_234 )
goto V_235;
if ( F_78 ( F_33 ( V_63 -> V_3 ) , & F_79 ( V_105 ) -> V_95 , NULL , 0 ) )
goto V_235;
V_219 = F_120 ( V_218 -> V_185 . V_236 ) ;
#ifdef F_121
V_221 = V_218 -> V_185 . V_237 ;
if ( V_221 == V_238 ||
! V_63 -> V_138 . V_239 )
V_221 = V_240 ;
#endif
V_195 = F_101 ( & F_79 ( V_105 ) -> V_95 , V_105 -> V_3 ) ;
if ( V_195 )
V_60 = F_122 ( & V_195 -> V_119 ) ;
if ( V_195 && V_219 == 0 ) {
F_123 ( V_60 ) ;
F_102 ( V_195 ) ;
V_195 = NULL ;
}
if ( V_195 == NULL && V_219 ) {
F_124 ( V_156
L_23 ) ;
V_195 = F_125 ( & F_79 ( V_105 ) -> V_95 , V_105 -> V_3 , V_221 ) ;
if ( V_195 == NULL ) {
F_36 ( V_111
L_24 ,
V_28 ) ;
return;
}
V_60 = F_122 ( & V_195 -> V_119 ) ;
if ( V_60 == NULL ) {
F_36 ( V_111
L_25 ,
V_28 ) ;
F_126 ( & V_195 -> V_119 ) ;
return;
}
V_60 -> V_78 |= V_160 ;
} else if ( V_195 ) {
V_195 -> V_241 = ( V_195 -> V_241 & ~ V_242 ) | F_127 ( V_221 ) ;
}
if ( V_195 )
V_195 -> V_243 = V_244 + ( V_245 * V_219 ) ;
if ( V_218 -> V_185 . V_246 ) {
V_63 -> V_138 . V_247 = V_218 -> V_185 . V_246 ;
if ( V_195 )
F_128 ( & V_195 -> V_119 , V_248 ,
V_218 -> V_185 . V_246 ) ;
}
V_235:
if ( V_63 -> V_67 ) {
unsigned long V_249 = F_129 ( V_218 -> V_250 ) ;
if ( V_249 && V_249 / 1000 < V_251 / V_245 ) {
V_249 = ( V_249 * V_245 ) / 1000 ;
if ( V_249 < V_245 / 10 )
V_249 = V_245 / 10 ;
V_63 -> V_67 -> V_252 = V_249 ;
V_63 -> V_253 = V_244 ;
F_130 ( V_254 , V_63 ) ;
}
V_249 = F_129 ( V_218 -> V_255 ) ;
if ( V_249 && V_249 / 1000 < V_251 / ( 3 * V_245 ) ) {
V_249 = ( V_249 * V_245 ) / 1000 ;
if ( V_249 < V_245 / 10 )
V_249 = V_245 / 10 ;
if ( V_249 != V_63 -> V_67 -> V_256 ) {
V_63 -> V_67 -> V_256 = V_249 ;
V_63 -> V_67 -> V_257 = 3 * V_249 ;
V_63 -> V_67 -> V_255 = F_131 ( V_249 ) ;
V_63 -> V_253 = V_244 ;
F_130 ( V_254 , V_63 ) ;
}
}
}
V_225:
if ( ! V_60 )
V_60 = F_95 ( & V_159 , & F_79 ( V_105 ) -> V_95 ,
V_105 -> V_3 , 1 ) ;
if ( V_60 ) {
T_1 * V_38 = NULL ;
if ( V_19 . V_169 ) {
V_38 = F_11 ( V_19 . V_169 ,
V_105 -> V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_26 ) ;
goto V_171;
}
}
F_96 ( V_60 , V_38 , V_182 ,
V_183 |
V_184 |
V_192 |
V_193 ) ;
}
if ( ! F_116 ( V_63 ) )
goto V_171;
#ifdef F_10
if ( F_78 ( F_33 ( V_63 -> V_3 ) , & F_79 ( V_105 ) -> V_95 , NULL , 0 ) )
goto V_258;
if ( V_63 -> V_138 . V_239 && V_19 . V_33 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_33 ;
V_37 ;
V_37 = F_5 ( V_37 , V_19 . V_32 ) ) {
struct V_259 * V_260 = (struct V_259 * ) V_37 ;
#ifdef F_119
if ( V_105 -> V_223 == V_226 &&
V_260 -> V_261 == 0 )
continue;
#endif
if ( V_260 -> V_261 > V_63 -> V_138 . V_262 )
continue;
F_132 ( V_105 -> V_3 , ( T_1 * ) V_37 , ( V_37 -> V_15 ) << 3 ,
& F_79 ( V_105 ) -> V_95 ) ;
}
}
V_258:
#endif
#ifdef F_119
if ( V_105 -> V_223 == V_226 )
goto V_171;
#endif
if ( V_63 -> V_138 . V_263 && V_19 . V_264 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_264 ;
V_37 ;
V_37 = F_5 ( V_37 , V_19 . V_30 ) ) {
F_133 ( V_105 -> V_3 , ( T_1 * ) V_37 , ( V_37 -> V_15 ) << 3 ) ;
}
}
if ( V_19 . V_265 ) {
T_6 V_90 ;
T_2 V_266 ;
memcpy ( & V_90 , ( ( T_1 * ) ( V_19 . V_265 + 1 ) ) + 2 , sizeof( V_266 ) ) ;
V_266 = F_129 ( V_90 ) ;
if ( V_266 < V_267 || V_266 > V_105 -> V_3 -> V_266 ) {
F_9 ( V_27
L_27 ,
V_266 ) ;
} else if ( V_63 -> V_138 . V_268 != V_266 ) {
V_63 -> V_138 . V_268 = V_266 ;
if ( V_195 )
F_128 ( & V_195 -> V_119 , V_269 , V_266 ) ;
F_134 ( V_105 -> V_3 , V_266 ) ;
}
}
if ( V_19 . V_35 ) {
struct V_11 * V_37 ;
for ( V_37 = V_19 . V_35 ;
V_37 ;
V_37 = F_7 ( V_37 , V_19 . V_34 ) ) {
F_105 ( V_105 , V_37 ) ;
}
}
if ( V_19 . V_186 || V_19 . V_270 ) {
F_9 ( V_27
L_28 ) ;
}
V_171:
if ( V_195 )
F_126 ( & V_195 -> V_119 ) ;
else if ( V_60 )
F_97 ( V_60 ) ;
}
static void F_135 ( struct V_93 * V_105 )
{
struct V_62 * V_63 ;
struct V_96 * V_185 ;
const struct V_41 * V_271 ;
const struct V_41 * V_98 ;
struct V_59 * V_60 ;
int V_272 = 0 ;
struct V_17 V_19 ;
int V_220 ;
T_1 * V_38 = NULL ;
#ifdef F_119
switch ( V_105 -> V_223 ) {
case V_224 :
case V_226 :
F_9 ( V_27
L_29 ) ;
return;
}
#endif
if ( ! ( F_118 ( & F_79 ( V_105 ) -> V_95 ) & V_222 ) ) {
F_9 ( V_27
L_30 ) ;
return;
}
V_220 = V_105 -> V_114 - V_105 -> V_113 ;
V_220 -= sizeof( struct V_96 ) + 2 * sizeof( struct V_41 ) ;
if ( V_220 < 0 ) {
F_9 ( V_27
L_31 ) ;
return;
}
V_185 = F_136 ( V_105 ) ;
V_98 = ( const struct V_41 * ) ( V_185 + 1 ) ;
V_271 = V_98 + 1 ;
if ( F_21 ( V_271 ) ) {
F_9 ( V_27
L_32 ) ;
return;
}
if ( F_137 ( V_271 , V_98 ) ) {
V_272 = 1 ;
} else if ( F_118 ( V_98 ) !=
( V_273 | V_222 ) ) {
F_9 ( V_27
L_33 ) ;
return;
}
V_63 = F_27 ( V_105 -> V_3 ) ;
if ( ! V_63 )
return;
if ( V_63 -> V_138 . V_147 || ! V_63 -> V_138 . V_274 )
return;
if ( ! F_8 ( ( T_1 * ) ( V_271 + 1 ) , V_220 , & V_19 ) ) {
F_9 ( V_27
L_34 ) ;
return;
}
if ( V_19 . V_186 ) {
V_38 = F_11 ( V_19 . V_186 ,
V_105 -> V_3 ) ;
if ( ! V_38 ) {
F_9 ( V_27
L_35 ) ;
return;
}
}
V_60 = F_95 ( & V_159 , V_98 , V_105 -> V_3 , 1 ) ;
if ( V_60 ) {
F_138 ( V_271 , & F_79 ( V_105 ) -> V_94 ,
& F_79 ( V_105 ) -> V_95 , V_60 , V_38 ,
V_272 ) ;
F_97 ( V_60 ) ;
}
}
void F_139 ( struct V_93 * V_105 , struct V_59 * V_60 ,
const struct V_41 * V_98 )
{
struct V_2 * V_3 = V_105 -> V_3 ;
struct V_100 * V_100 = F_33 ( V_3 ) ;
struct V_101 * V_102 = V_100 -> V_103 . V_104 ;
int V_107 = sizeof( struct V_96 ) + 2 * sizeof( struct V_41 ) ;
struct V_93 * V_275 ;
struct V_96 * V_185 ;
struct V_41 V_276 ;
struct V_41 * V_277 ;
struct V_194 * V_195 ;
struct V_118 * V_119 ;
struct V_62 * V_120 ;
struct V_116 V_117 ;
T_1 * V_5 ;
int V_278 ;
int V_108 ;
T_1 V_279 [ V_280 ] , * V_77 = NULL ;
if ( F_70 ( V_3 , & V_276 , V_151 ) ) {
F_9 ( V_27
L_36 ,
V_3 -> V_188 ) ;
return;
}
if ( ! F_137 ( & F_79 ( V_105 ) -> V_94 , V_98 ) &&
F_118 ( V_98 ) != ( V_273 | V_222 ) ) {
F_9 ( V_27
L_33 ) ;
return;
}
F_46 ( V_102 , & V_117 , V_281 ,
& V_276 , & F_79 ( V_105 ) -> V_95 , V_3 -> V_58 ) ;
V_119 = F_140 ( V_100 , NULL , & V_117 ) ;
if ( V_119 == NULL )
return;
V_119 = F_49 ( V_100 , V_119 , F_50 ( & V_117 ) , NULL , 0 ) ;
if ( F_51 ( V_119 ) )
return;
V_195 = (struct V_194 * ) V_119 ;
if ( V_195 -> V_241 & V_282 ) {
F_9 ( V_27
L_37 ) ;
goto V_283;
}
if ( ! V_195 -> V_284 )
F_141 ( V_195 , 1 ) ;
if ( ! F_142 ( V_195 -> V_284 , 1 * V_245 ) )
goto V_283;
if ( V_3 -> V_4 ) {
F_66 ( & V_60 -> V_146 ) ;
if ( V_60 -> V_71 & V_87 ) {
memcpy ( V_279 , V_60 -> V_77 , V_3 -> V_4 ) ;
F_68 ( & V_60 -> V_146 ) ;
V_77 = V_279 ;
V_107 += F_2 ( V_3 ) ;
} else
F_68 ( & V_60 -> V_146 ) ;
}
V_278 = F_143 (unsigned int,
IPV6_MIN_MTU-sizeof(struct ipv6hdr)-len, skb->len + 8 ) ;
V_278 &= ~ 0x7 ;
V_107 += V_278 ;
V_275 = F_34 ( V_102 ,
( V_109 + sizeof( struct V_110 ) +
V_107 + F_35 ( V_3 ) ) ,
1 , & V_108 ) ;
if ( V_275 == NULL ) {
F_36 ( V_111
L_38 ,
V_28 , V_108 ) ;
goto V_283;
}
F_37 ( V_275 , F_38 ( V_3 ) ) ;
F_39 ( V_102 , V_275 , V_3 , & V_276 , & F_79 ( V_105 ) -> V_95 ,
V_112 , V_107 ) ;
F_144 ( V_275 , F_145 ( V_275 ) - V_275 -> V_6 ) ;
F_40 ( V_275 , V_107 ) ;
V_185 = F_136 ( V_275 ) ;
memset ( V_185 , 0 , sizeof( struct V_96 ) ) ;
V_185 -> V_121 = V_281 ;
V_277 = (struct V_41 * ) ( V_185 + 1 ) ;
F_42 ( V_277 , V_98 ) ;
V_277 ++ ;
F_42 ( V_277 , & F_79 ( V_105 ) -> V_94 ) ;
V_5 = ( T_1 * ) ( V_277 + 1 ) ;
if ( V_77 )
V_5 = F_4 ( V_5 , V_23 , V_77 ,
V_3 -> V_4 , V_3 -> type ) ;
memset ( V_5 , 0 , 8 ) ;
* ( V_5 ++ ) = V_25 ;
* ( V_5 ++ ) = ( V_278 >> 3 ) ;
V_5 += 6 ;
memcpy ( V_5 , F_79 ( V_105 ) , V_278 - 8 ) ;
V_185 -> V_115 = F_43 ( & V_276 , & F_79 ( V_105 ) -> V_95 ,
V_107 , V_112 ,
F_44 ( V_185 , V_107 , 0 ) ) ;
F_52 ( V_275 , V_119 ) ;
F_53 () ;
V_120 = F_27 ( V_119 -> V_3 ) ;
F_54 ( V_100 , V_120 , V_122 , V_105 -> V_107 ) ;
V_108 = F_55 ( V_123 , V_124 , V_275 , NULL , V_119 -> V_3 ,
V_125 ) ;
if ( ! V_108 ) {
F_56 ( V_100 , V_120 , V_281 ) ;
F_57 ( V_100 , V_120 , V_126 ) ;
}
F_58 () ;
return;
V_283:
F_126 ( V_119 ) ;
}
static void F_146 ( struct V_93 * V_105 )
{
F_85 ( V_105 ) ;
F_48 ( V_105 ) ;
}
int F_147 ( struct V_93 * V_105 )
{
struct V_161 * V_162 ;
if ( ! F_148 ( V_105 , V_105 -> V_107 ) )
return 0 ;
V_162 = (struct V_161 * ) F_41 ( V_105 ) ;
F_149 ( V_105 , V_105 -> V_6 - F_41 ( V_105 ) ) ;
if ( F_79 ( V_105 ) -> V_247 != 255 ) {
F_9 ( V_27
L_39 ,
F_79 ( V_105 ) -> V_247 ) ;
return 0 ;
}
if ( V_162 -> V_185 . V_213 != 0 ) {
F_9 ( V_27
L_40 ,
V_162 -> V_185 . V_213 ) ;
return 0 ;
}
memset ( F_91 ( V_105 ) , 0 , sizeof( struct V_285 ) ) ;
switch ( V_162 -> V_185 . V_121 ) {
case V_150 :
F_85 ( V_105 ) ;
break;
case V_136 :
F_98 ( V_105 ) ;
break;
case V_152 :
F_103 ( V_105 ) ;
break;
case V_286 :
F_117 ( V_105 ) ;
break;
case V_281 :
F_135 ( V_105 ) ;
break;
}
return 0 ;
}
static int F_150 ( struct V_287 * V_288 , unsigned long V_289 , void * V_290 )
{
struct V_2 * V_3 = V_290 ;
struct V_100 * V_100 = F_33 ( V_3 ) ;
switch ( V_289 ) {
case V_291 :
F_151 ( & V_159 , V_3 ) ;
F_152 ( ~ 0UL , V_100 ) ;
break;
case V_292 :
F_153 ( & V_159 , V_3 ) ;
F_152 ( ~ 0UL , V_100 ) ;
break;
case V_293 :
F_65 ( V_3 ) ;
break;
default:
break;
}
return V_294 ;
}
static void F_154 ( struct V_295 * V_296 ,
const char * V_297 , const char * V_298 )
{
static char V_299 [ V_300 ] ;
static int V_301 ;
if ( strcmp ( V_299 , V_302 -> V_303 ) && V_301 < 5 ) {
strcpy ( V_299 , V_302 -> V_303 ) ;
F_155 ( V_27
L_41
L_42
L_43
L_44 ,
V_299 , V_297 ,
V_298 , V_296 -> V_304 ,
V_298 , V_296 -> V_304 ) ;
V_301 ++ ;
}
}
int F_156 ( struct V_295 * V_296 , int V_305 , void T_7 * V_306 , T_4 * V_307 , T_8 * V_308 )
{
struct V_2 * V_3 = V_296 -> V_309 ;
struct V_62 * V_120 ;
int V_158 ;
if ( ( strcmp ( V_296 -> V_304 , L_45 ) == 0 ) ||
( strcmp ( V_296 -> V_304 , L_46 ) == 0 ) )
F_154 ( V_296 , L_47 , V_3 ? V_3 -> V_188 : L_48 ) ;
if ( strcmp ( V_296 -> V_304 , L_45 ) == 0 )
V_158 = F_157 ( V_296 , V_305 , V_306 , V_307 , V_308 ) ;
else if ( strcmp ( V_296 -> V_304 , L_46 ) == 0 )
V_158 = F_158 ( V_296 , V_305 ,
V_306 , V_307 , V_308 ) ;
else if ( ( strcmp ( V_296 -> V_304 , L_49 ) == 0 ) ||
( strcmp ( V_296 -> V_304 , L_50 ) == 0 ) )
V_158 = F_159 ( V_296 , V_305 ,
V_306 , V_307 , V_308 ) ;
else
V_158 = - 1 ;
if ( V_305 && V_158 == 0 && V_3 && ( V_120 = F_22 ( V_3 ) ) != NULL ) {
if ( V_296 -> V_6 == & V_120 -> V_67 -> V_256 )
V_120 -> V_67 -> V_255 = F_131 ( V_120 -> V_67 -> V_256 ) ;
V_120 -> V_253 = V_244 ;
F_130 ( V_254 , V_120 ) ;
F_25 ( V_120 ) ;
}
return V_158 ;
}
static int T_9 F_160 ( struct V_100 * V_100 )
{
struct V_310 * V_311 ;
struct V_101 * V_102 ;
int V_108 ;
V_108 = F_161 ( & V_102 , V_312 ,
V_313 , V_112 , V_100 ) ;
if ( V_108 < 0 ) {
F_36 ( V_111
L_51 ,
V_108 ) ;
return V_108 ;
}
V_100 -> V_103 . V_104 = V_102 ;
V_311 = F_64 ( V_102 ) ;
V_311 -> V_247 = 255 ;
V_311 -> V_314 = 0 ;
return 0 ;
}
static void T_10 F_162 ( struct V_100 * V_100 )
{
F_163 ( V_100 -> V_103 . V_104 ) ;
}
int T_11 F_164 ( void )
{
int V_108 ;
V_108 = F_165 ( & V_315 ) ;
if ( V_108 )
return V_108 ;
F_166 ( & V_159 ) ;
#ifdef F_167
V_108 = F_168 ( NULL , & V_159 . V_65 , L_52 ,
& F_156 ) ;
if ( V_108 )
goto V_316;
#endif
V_108 = F_169 ( & V_317 ) ;
if ( V_108 )
goto V_318;
V_171:
return V_108 ;
V_318:
#ifdef F_167
F_170 ( & V_159 . V_65 ) ;
V_316:
#endif
F_171 ( & V_315 ) ;
goto V_171;
}
void F_172 ( void )
{
F_173 ( & V_317 ) ;
#ifdef F_167
F_170 ( & V_159 . V_65 ) ;
#endif
F_174 ( & V_159 ) ;
F_171 ( & V_315 ) ;
}
