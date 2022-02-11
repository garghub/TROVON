static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_6 = 1 ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_6 = 0 ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
}
int
F_7 ( struct V_1 * V_2 , int V_7 )
{
unsigned long V_3 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
if ( V_2 -> V_8 == V_7 ) {
F_4 ( & V_2 -> V_5 , V_3 ) ;
return F_8 ( V_2 ) ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 , const void T_1 * V_9 ,
long V_10 , int V_7 )
{
struct V_11 V_12 ;
unsigned long V_3 ;
int V_13 ;
if ( V_10 < ( long ) sizeof( V_12 ) ) {
F_10 ( V_14 L_1 , V_10 ) ;
return - V_15 ;
}
if ( F_11 ( & V_12 , V_9 , sizeof( V_12 ) ) )
return - V_16 ;
V_10 -= sizeof( V_12 ) ;
V_9 += sizeof( V_12 ) ;
if ( V_12 . V_17 != V_18 ) {
F_10 ( V_14 L_2 , V_12 . V_17 ) ;
return - V_15 ;
}
if ( V_10 < V_12 . V_19 ) {
F_10 ( V_14 L_3 ,
V_10 , V_12 . V_19 ) ;
return - V_15 ;
}
if ( V_12 . V_19 < 0 ) {
F_10 ( V_14 L_4 , V_12 . V_19 ) ;
return - V_15 ;
}
if ( V_12 . type == V_20 ) {
F_1 ( V_2 ) ;
V_13 = F_12 ( V_2 , V_9 , V_10 , V_7 ) ;
F_5 ( V_2 ) ;
return V_13 ;
}
F_3 ( & V_2 -> V_5 , V_3 ) ;
if ( V_2 -> V_8 != V_7 ) {
F_4 ( & V_2 -> V_5 , V_3 ) ;
return - V_21 ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
F_1 ( V_2 ) ;
V_13 = - V_15 ;
switch ( V_12 . type ) {
case V_22 :
V_13 = F_13 ( V_2 , V_9 , V_10 ) ;
break;
case V_23 :
V_13 = F_14 ( V_2 , V_9 , V_10 ) ;
break;
case V_24 :
V_13 = F_8 ( V_2 ) ;
break;
case V_25 :
break;
case V_26 :
V_13 = F_15 ( V_2 , V_9 , V_10 ) ;
break;
case V_27 :
V_13 = F_16 ( V_2 , V_12 . V_28 ) ;
break;
case V_29 :
if ( ! V_2 -> V_30 ) {
F_10 ( V_14 L_5
L_6 ) ;
V_13 = - V_15 ;
} else {
int V_31 , V_32 ;
V_31 = ( ( unsigned short ) V_12 . V_28 >> 8 ) & 0xff ;
V_32 = ( unsigned short ) V_12 . V_28 & 0xff ;
if ( ! F_17 ( V_2 , V_2 -> V_30 , V_31 , V_32 ) )
V_13 = - V_15 ;
else
V_13 = 0 ;
}
break;
}
F_5 ( V_2 ) ;
return V_13 ;
}
static inline int
F_18 ( int type )
{
type &= 0x0f ;
return ( type == V_33 ||
type == V_34 ) ;
}
static int
F_12 ( struct V_1 * V_2 , const char T_1 * V_9 ,
int V_10 , int V_7 )
{
struct V_35 V_36 ;
struct V_37 * V_38 ;
unsigned long V_3 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
if ( V_2 -> V_8 >= 0 || V_2 -> V_30 ) {
F_4 ( & V_2 -> V_5 , V_3 ) ;
return - V_21 ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
if ( F_11 ( & V_36 , V_9 , sizeof( V_36 ) ) )
return - V_16 ;
if ( F_18 ( V_36 . type ) ) {
V_36 . type |= V_39 ;
V_38 = F_19 ( V_2 , V_36 . type , NULL ) ;
} else
V_38 = F_19 ( V_2 , V_36 . type , V_36 . V_40 ) ;
if ( V_38 == NULL ) {
return - V_41 ;
}
F_3 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_8 = V_7 ;
V_2 -> V_30 = V_38 ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
return 0 ;
}
static struct V_37 *
F_19 ( struct V_1 * V_2 , int type , char * V_40 )
{
struct V_37 * V_38 ;
if ( type & V_39 ) {
for ( V_38 = V_2 -> V_42 ; V_38 ; V_38 = V_38 -> V_43 ) {
if ( F_20 ( V_38 , type , V_40 ) ) {
return V_38 ;
}
}
}
V_38 = F_21 ( sizeof( * V_38 ) , V_44 ) ;
if ( V_38 == NULL )
return NULL ;
V_38 -> V_45 = V_2 -> V_46 ;
V_2 -> V_46 ++ ;
V_38 -> V_43 = V_2 -> V_42 ;
V_2 -> V_42 = V_38 ;
V_38 -> type = type ;
V_38 -> V_47 = NULL ;
V_38 -> V_48 = NULL ;
if ( V_40 )
memcpy ( V_38 -> V_40 , V_40 , V_49 ) ;
return V_38 ;
}
static int
F_20 ( struct V_37 * V_38 , int type , unsigned char * V_40 )
{
return ( ( V_38 -> type & V_39 ) &&
( V_38 -> type & 0x0f ) == ( type & 0x0f ) &&
( V_40 == NULL ||
memcmp ( V_38 -> V_40 , V_40 , V_49 ) == 0 ) ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_8 = - 1 ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , int V_50 )
{
if ( V_2 -> V_30 ) {
if ( F_23 ( V_2 -> V_30 , V_50 ) )
return 0 ;
}
return - V_15 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_51 * V_52 )
{
V_52 -> V_53 = V_2 -> V_54 ++ ;
if ( V_38 -> type & V_55 )
V_2 -> V_56 = V_2 -> V_54 ;
}
static struct V_51 *
F_25 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_51 * V_52 ;
if ( ( V_52 = F_21 ( sizeof( * V_52 ) , V_44 ) ) == NULL )
return NULL ;
V_52 -> V_43 = V_38 -> V_47 ;
V_38 -> V_47 = V_52 ;
F_26 ( & V_52 -> V_57 ) ;
F_24 ( V_2 , V_38 , V_52 ) ;
return V_52 ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_58 * V_59 )
{
V_59 -> V_53 = V_2 -> V_60 ++ ;
if ( V_38 -> type & V_55 )
V_2 -> V_61 = V_2 -> V_60 ;
}
static struct V_58 *
F_28 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_58 * V_59 ;
if ( ( V_59 = F_21 ( sizeof( * V_59 ) , V_44 ) ) == NULL )
return NULL ;
V_59 -> V_43 = V_38 -> V_48 ;
V_38 -> V_48 = V_59 ;
F_27 ( V_2 , V_38 , V_59 ) ;
return V_59 ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_58 * V_59 )
{
if ( V_59 == V_38 -> V_48 ) {
V_38 -> V_48 = V_59 -> V_43 ;
F_30 ( V_59 ) ;
}
}
static int
F_15 ( struct V_1 * V_2 , const void T_1 * V_9 , int V_10 )
{
struct V_51 * V_52 , * V_62 ;
struct V_37 * V_38 ;
struct V_63 V_64 ;
if ( V_10 < ( int ) sizeof( V_64 ) )
return - V_15 ;
if ( F_11 ( & V_64 , V_9 , sizeof( V_64 ) ) )
return - V_16 ;
if ( V_64 . V_65 < 0 || V_64 . V_65 >= V_66 )
return - V_15 ;
V_38 = F_19 ( V_2 , V_34 | V_39 , NULL ) ;
if ( V_38 == NULL )
return - V_41 ;
V_62 = NULL ;
for ( V_52 = V_38 -> V_47 ; V_52 ; V_62 = V_52 , V_52 = V_52 -> V_43 ) {
if ( V_52 -> V_67 &&
V_52 -> V_32 == V_64 . V_65 &&
V_52 -> V_31 == V_64 . V_68 &&
V_52 -> V_57 . V_69 == V_64 . V_70 &&
V_52 -> V_57 . V_71 == V_64 . V_72 &&
V_52 -> V_57 . V_73 == V_64 . V_74 &&
V_52 -> V_57 . V_75 == V_64 . V_76 ) {
if ( V_62 ) {
V_62 -> V_43 = V_52 -> V_43 ;
V_52 -> V_43 = V_38 -> V_47 ;
V_38 -> V_47 = V_52 ;
}
F_24 ( V_2 , V_38 , V_52 ) ;
return 0 ;
}
}
if ( ( V_52 = F_25 ( V_2 , V_38 ) ) == NULL )
return - V_41 ;
V_52 -> V_31 = V_64 . V_68 ;
V_52 -> V_32 = V_64 . V_65 ;
V_52 -> V_67 = 1 ;
if ( V_64 . V_70 >= 0 ) {
V_52 -> V_57 . V_69 = V_64 . V_70 ;
V_52 -> V_57 . V_77 = V_64 . V_70 ;
}
V_52 -> V_57 . V_71 = V_64 . V_72 ;
V_52 -> V_57 . V_73 = V_64 . V_74 ;
V_52 -> V_57 . V_75 = V_64 . V_76 ;
V_52 -> V_57 . V_78 = V_38 -> V_45 ;
F_31 ( V_2 , V_52 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_37 * V_38 ,
int V_31 , int V_32 )
{
struct V_51 * V_79 , * V_43 , * V_80 ;
int V_81 = 0 ;
V_79 = NULL ;
for ( V_80 = V_38 -> V_47 ; V_80 ; V_80 = V_43 ) {
V_43 = V_80 -> V_43 ;
if ( ! V_80 -> V_67 &&
V_80 -> V_31 == V_31 && V_80 -> V_32 == V_32 ) {
if ( V_79 )
V_79 -> V_43 = V_43 ;
else
V_38 -> V_47 = V_43 ;
V_81 ++ ;
F_30 ( V_80 ) ;
} else
V_79 = V_80 ;
}
if ( V_81 )
F_22 ( V_2 ) ;
return V_81 ;
}
static int
F_13 ( struct V_1 * V_2 , const void T_1 * V_9 , long V_10 )
{
struct V_37 * V_38 ;
struct V_51 * V_82 ;
struct V_83 V_84 ;
int V_85 ;
if ( ( V_38 = V_2 -> V_30 ) == NULL )
return - V_15 ;
if ( F_18 ( V_38 -> type ) )
return - V_15 ;
if ( V_10 < ( long ) sizeof( V_84 ) ) {
F_32 ( V_14 L_7 ) ;
return - V_15 ;
}
if ( F_11 ( ( char * ) & V_84 , V_9 , sizeof( V_84 ) ) )
return - V_16 ;
V_9 += sizeof( V_84 ) ;
V_10 -= sizeof( V_84 ) ;
if ( V_84 . V_86 <= 0 || V_84 . V_86 >= 100 ) {
F_32 ( V_14 L_8 ,
V_84 . V_86 ) ;
return - V_15 ;
}
if ( V_10 < ( long ) sizeof( struct V_87 ) * V_84 . V_86 ) {
F_32 ( V_14 L_9
L_10 ,
V_10 , V_84 . V_86 ) ;
return - V_15 ;
}
switch ( V_84 . V_88 ) {
case V_89 :
for ( V_82 = V_38 -> V_47 ; V_82 ; V_82 = V_82 -> V_43 ) {
if ( ! V_82 -> V_67 &&
V_82 -> V_31 == V_84 . V_31 &&
V_82 -> V_32 == V_84 . V_32 )
return - V_15 ;
}
break;
case V_90 :
F_17 ( V_2 , V_38 , V_84 . V_31 , V_84 . V_32 ) ;
break;
}
for ( V_85 = 0 ; V_85 < V_84 . V_86 ; V_85 ++ ) {
struct V_51 V_91 ;
if ( F_11 ( & V_91 . V_57 , V_9 , sizeof( V_91 . V_57 ) ) ) {
return - V_16 ;
}
V_9 += sizeof( V_91 . V_57 ) ;
V_10 -= sizeof( V_91 . V_57 ) ;
V_91 . V_31 = V_84 . V_31 ;
V_91 . V_32 = V_84 . V_32 ;
V_91 . V_67 = 0 ;
V_91 . V_57 . V_78 = V_38 -> V_45 ;
if ( V_91 . V_57 . V_92 & V_93 )
F_33 ( & V_91 . V_57 . V_36 ) ;
if ( ( V_82 = F_25 ( V_2 , V_38 ) ) == NULL ) {
return - V_41 ;
}
V_82 -> V_31 = V_91 . V_31 ;
V_82 -> V_32 = V_91 . V_32 ;
V_82 -> V_57 = V_91 . V_57 ;
V_82 -> V_94 = F_34 ( V_38 , & V_82 -> V_57 ) ;
}
return 0 ;
}
static void
F_26 ( struct V_87 * V_95 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_96 = 60 ;
V_95 -> V_77 = 127 ;
V_95 -> V_97 = 127 ;
V_95 -> V_75 = - 1 ;
V_95 -> V_98 = - 1 ;
V_95 -> V_99 = - 1 ;
V_95 -> V_100 = - 1 ;
V_95 -> V_101 = 127 ;
V_95 -> V_102 = 100 ;
F_33 ( & V_95 -> V_36 ) ;
}
static void
F_33 ( struct V_103 * V_104 )
{
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_105 = 0x8000 ;
V_104 -> V_106 = 0x7f7f ;
V_104 -> V_107 = 0x7f7f ;
V_104 -> V_108 = 0x807f ;
V_104 -> V_109 = 0x8000 ;
V_104 -> V_110 = 0x7f7f ;
V_104 -> V_111 = 0x7f7f ;
V_104 -> V_112 = 0x807f ;
V_104 -> V_113 = 0x8000 ;
V_104 -> V_114 = 0x8000 ;
V_104 -> V_115 = 0xff ;
}
static struct V_58 *
F_34 ( struct V_37 * V_38 , struct V_87 * V_95 )
{
struct V_58 * V_94 ;
V_94 = F_23 ( V_38 , V_95 -> V_94 ) ;
if ( V_94 == NULL )
return NULL ;
V_95 -> V_71 += V_94 -> V_57 . V_71 ;
V_95 -> V_73 += V_94 -> V_57 . V_73 ;
V_95 -> V_116 += V_94 -> V_57 . V_116 ;
V_95 -> V_117 += V_94 -> V_57 . V_117 ;
V_95 -> V_118 = V_94 -> V_57 . V_119 ;
return V_94 ;
}
static struct V_58 *
F_23 ( struct V_37 * V_38 , int V_50 )
{
struct V_58 * V_80 ;
if ( V_38 == NULL )
return NULL ;
for ( V_80 = V_38 -> V_48 ; V_80 ; V_80 = V_80 -> V_43 ) {
if ( V_80 -> V_57 . V_94 == V_50 )
return V_80 ;
}
return NULL ;
}
static int
F_14 ( struct V_1 * V_2 , const void T_1 * V_9 , long V_10 )
{
struct V_37 * V_38 ;
struct V_120 V_121 ;
struct V_58 * V_59 ;
long V_122 ;
if ( ( V_38 = V_2 -> V_30 ) == NULL )
return - V_15 ;
if ( F_18 ( V_38 -> type ) )
return - V_15 ;
if ( F_11 ( & V_121 , V_9 , sizeof( V_121 ) ) )
return - V_16 ;
V_122 = sizeof( V_121 ) ;
if ( V_121 . V_123 != ( V_10 - V_122 ) / 2 )
return - V_15 ;
if ( F_23 ( V_38 , V_121 . V_94 ) ) {
if ( V_38 -> type & V_39 )
return 0 ;
return - V_15 ;
}
if ( ( V_59 = F_28 ( V_2 , V_38 ) ) == NULL )
return - V_41 ;
V_59 -> V_57 = V_121 ;
V_59 -> V_57 . V_78 = V_38 -> V_45 ;
V_59 -> V_57 . V_124 = 0 ;
V_59 -> V_57 . V_125 = V_59 -> V_57 . V_123 ;
if ( V_59 -> V_57 . V_123 > 0 ) {
int V_13 ;
V_13 = V_2 -> V_126 . V_127
( V_2 -> V_126 . V_128 , V_59 , V_2 -> V_129 ,
V_9 + V_122 , V_10 - V_122 ) ;
if ( V_13 < 0 ) {
F_29 ( V_2 , V_38 , V_59 ) ;
return V_13 ;
}
V_2 -> V_130 += V_59 -> V_57 . V_125 ;
}
return V_10 ;
}
int
F_35 ( unsigned int V_131 , int V_132 , int V_133 )
{
int V_57 ;
int V_134 , V_69 , V_135 ;
if ( V_131 < 2 )
return 0 ;
for ( V_135 = 0 ; ! ( V_131 & 0x80000000L ) ; V_135 ++ )
V_131 <<= 1 ;
V_134 = ( V_131 >> 24 ) & 0x7f ;
V_69 = ( V_131 >> 16 ) & 0xff ;
V_57 = ( V_136 [ V_134 + 1 ] * V_69 + V_136 [ V_134 ] * ( 0x100 - V_69 ) ) >> 8 ;
V_57 -= V_132 ;
V_57 = ( V_57 * V_133 ) >> 16 ;
V_57 += ( 24 - V_135 ) * V_133 ;
return V_57 ;
}
static int
F_36 ( int V_137 )
{
return F_35 ( V_137 , V_138 , V_139 ) ;
}
static int
F_37 ( int V_140 )
{
return F_35 ( V_140 , V_141 , V_142 ) ;
}
static int
F_38 ( int V_143 , int V_71 , int V_73 )
{
int V_144 , V_80 , V_145 ;
V_144 = ( 3 - ( ( V_143 >> 6 ) & 3 ) ) * 3 ;
V_80 = V_143 & 0x3f ;
V_145 = V_73 - V_71 ;
if ( V_145 < 0 ) V_145 = - V_145 ;
if ( 13 > V_144 )
V_145 = V_145 << ( 13 - V_144 ) ;
else
V_145 = V_145 >> ( V_144 - 13 ) ;
return ( V_145 * 10 ) / ( V_80 * 441 ) ;
}
int
F_39 ( int V_146 )
{
int V_147 = ( 0x7f * 92 - V_146 ) / 92 ;
if ( V_147 < 1 ) V_147 = 1 ;
if ( V_147 >= 126 ) V_147 = 126 ;
return V_147 ;
}
static int
F_40 ( int V_146 , short * V_148 )
{
int V_149 = 1 , V_150 = 127 , V_151 ;
while ( V_149 < V_150 ) {
V_151 = ( V_149 + V_150 ) / 2 ;
if ( V_146 < ( int ) V_148 [ V_151 ] )
V_149 = V_151 + 1 ;
else
V_150 = V_151 ;
}
return V_149 ;
}
int
F_41 ( int V_146 )
{
return F_40 ( V_146 , V_152 ) ;
}
int
F_42 ( int V_146 )
{
return F_40 ( V_146 , V_153 ) ;
}
static int
F_43 ( struct V_1 * V_2 , const char T_1 * V_9 ,
long V_10 , int V_7 )
{
struct V_154 V_12 ;
struct V_37 * V_38 ;
struct V_51 * V_82 ;
struct V_58 * V_155 ;
int V_156 , V_50 ;
int V_13 ;
if ( V_10 < ( long ) sizeof( V_12 ) ) {
F_10 ( V_14 L_1 , V_10 ) ;
return - V_15 ;
}
if ( F_11 ( & V_12 , V_9 , sizeof( V_12 ) ) )
return - V_16 ;
V_10 -= sizeof( V_12 ) ;
V_9 += sizeof( V_12 ) ;
V_38 = F_19 ( V_2 , V_33 | V_39 , NULL ) ;
if ( V_38 == NULL )
return - V_41 ;
if ( ( V_155 = F_28 ( V_2 , V_38 ) ) == NULL )
return - V_41 ;
V_50 = V_2 -> V_60 ;
V_155 -> V_57 . V_94 = V_50 ;
V_155 -> V_57 . V_71 = 0 ;
V_155 -> V_57 . V_73 = V_12 . V_19 ;
V_155 -> V_57 . V_116 = V_12 . V_157 ;
V_155 -> V_57 . V_117 = V_12 . V_158 ;
V_155 -> V_57 . V_123 = V_12 . V_19 ;
V_155 -> V_57 . V_119 = 0 ;
if ( ! ( V_12 . V_92 & V_159 ) )
V_155 -> V_57 . V_119 |= V_160 ;
if ( V_12 . V_92 & V_161 )
V_155 -> V_57 . V_119 |= V_162 ;
V_155 -> V_57 . V_119 |= V_163 ;
if ( ! ( V_12 . V_92 & ( V_164 | V_165 | V_166 ) ) )
V_155 -> V_57 . V_119 |= V_167 ;
if ( V_12 . V_92 & V_165 )
V_155 -> V_57 . V_119 |= V_168 ;
if ( V_12 . V_92 & V_166 )
V_155 -> V_57 . V_119 |= V_169 ;
if ( V_12 . V_92 & V_159 ) {
V_155 -> V_57 . V_123 /= 2 ;
V_155 -> V_57 . V_73 /= 2 ;
V_155 -> V_57 . V_116 /= 2 ;
V_155 -> V_57 . V_117 /= 2 ;
}
V_155 -> V_57 . V_124 = 0 ;
V_155 -> V_57 . V_125 = 0 ;
V_155 -> V_57 . V_78 = V_38 -> V_45 ;
if ( ( V_82 = F_25 ( V_2 , V_38 ) ) == NULL ) {
F_29 ( V_2 , V_38 , V_155 ) ;
return - V_41 ;
}
if ( V_2 -> V_126 . V_127 ) {
V_13 = V_2 -> V_126 . V_127
( V_2 -> V_126 . V_128 , V_155 , V_2 -> V_129 ,
V_9 , V_10 ) ;
if ( V_13 < 0 ) {
F_29 ( V_2 , V_38 , V_155 ) ;
F_30 ( V_82 ) ;
return V_13 ;
}
}
V_2 -> V_130 += V_155 -> V_57 . V_125 ;
V_82 -> V_57 . V_94 = V_50 ;
V_82 -> V_57 . V_170 = F_37 ( V_12 . V_171 ) ;
V_156 = F_36 ( V_12 . V_172 ) ;
V_82 -> V_57 . V_96 = V_156 / 100 ;
V_82 -> V_57 . V_173 = - ( V_156 % 100 ) ;
V_82 -> V_57 . V_69 = ( F_36 ( V_12 . V_174 ) + 99 ) / 100 ;
V_82 -> V_57 . V_77 = F_36 ( V_12 . V_175 ) / 100 ;
V_82 -> V_57 . V_100 = ( V_12 . V_176 + 128 ) / 2 ;
#if 0
snd_printk(KERN_DEBUG
"gus: basefrq=%d (ofs=%d) root=%d,tune=%d, range:%d-%d\n",
(int)patch.base_freq, zone->v.rate_offset,
zone->v.root, zone->v.tune, zone->v.low, zone->v.high);
#endif
if ( V_12 . V_92 & V_177 ) {
int V_178 , V_179 , V_180 , V_181 ;
V_178 = F_38
( V_12 . V_182 [ 0 ] , 0 , V_12 . V_183 [ 0 ] ) ;
V_179 = F_38
( V_12 . V_182 [ 1 ] , V_12 . V_183 [ 0 ] ,
V_12 . V_183 [ 1 ] ) ;
V_180 = F_38
( V_12 . V_182 [ 2 ] , V_12 . V_183 [ 1 ] ,
V_12 . V_183 [ 2 ] ) ;
V_181 = F_38
( V_12 . V_182 [ 3 ] , V_12 . V_183 [ 1 ] ,
V_12 . V_183 [ 4 ] ) ;
V_181 += F_38
( V_12 . V_182 [ 4 ] , V_12 . V_183 [ 3 ] ,
V_12 . V_183 [ 4 ] ) ;
V_181 += F_38
( V_12 . V_182 [ 5 ] , V_12 . V_183 [ 4 ] ,
V_12 . V_183 [ 5 ] ) ;
V_82 -> V_57 . V_36 . V_110 =
( F_39 ( V_179 ) << 8 ) |
F_41 ( V_178 ) ;
V_82 -> V_57 . V_36 . V_111 = ( F_44 ( V_12 . V_183 [ 2 ] ) << 8 ) |
F_42 ( V_180 ) ;
V_82 -> V_57 . V_36 . V_112 = 0x8000 | F_42 ( V_181 ) ;
V_82 -> V_57 . V_184 = F_45 ( V_12 . V_183 [ 0 ] ) ;
#if 0
snd_printk(KERN_DEBUG
"gus: atkhld=%x, dcysus=%x, volrel=%x, att=%d\n",
zone->v.parm.volatkhld,
zone->v.parm.voldcysus,
zone->v.parm.volrelease,
zone->v.attenuation);
#endif
}
if ( V_12 . V_92 & V_185 ) {
V_82 -> V_57 . V_36 . V_112 = 0x807f ;
}
if ( V_12 . V_92 & V_186 ) {
int V_143 = ( V_12 . V_187 * 1000 / 38 ) / 42 ;
V_82 -> V_57 . V_36 . V_188 = ( ( V_12 . V_189 / 2 ) << 8 ) | V_143 ;
}
if ( V_12 . V_92 & V_190 ) {
int V_143 = ( V_12 . V_191 * 1000 / 38 ) / 42 ;
V_82 -> V_57 . V_36 . V_192 = ( ( V_12 . V_193 / 6 ) << 8 ) | V_143 ;
}
if ( ! ( V_155 -> V_57 . V_119 & V_167 ) )
V_82 -> V_57 . V_92 = V_194 ;
else
V_82 -> V_57 . V_92 = 0 ;
V_82 -> V_31 = 0 ;
V_82 -> V_32 = V_12 . V_195 ;
V_82 -> V_67 = 0 ;
V_82 -> V_57 . V_78 = V_38 -> V_45 ;
V_82 -> V_94 = F_34 ( V_38 , & V_82 -> V_57 ) ;
F_31 ( V_2 , V_82 ) ;
return 0 ;
}
int
F_46 ( struct V_1 * V_2 , const char T_1 * V_9 ,
long V_10 , int V_7 )
{
int V_13 ;
F_1 ( V_2 ) ;
V_13 = F_43 ( V_2 , V_9 , V_10 , V_7 ) ;
F_5 ( V_2 ) ;
return V_13 ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_51 * V_196 ;
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
for ( V_38 = V_2 -> V_42 ; V_38 ; V_38 = V_38 -> V_43 ) {
for ( V_196 = V_38 -> V_47 ; V_196 ; V_196 = V_196 -> V_43 ) {
if ( ! V_196 -> V_67 && V_196 -> V_94 == NULL ) {
V_196 -> V_94 = F_34 ( V_38 , & V_196 -> V_57 ) ;
if ( V_196 -> V_94 == NULL )
continue;
}
F_31 ( V_2 , V_196 ) ;
}
}
}
static void
F_31 ( struct V_1 * V_2 , struct V_51 * V_196 )
{
struct V_51 * V_82 ;
int V_198 ;
V_82 = F_47 ( V_2 , V_196 -> V_31 , V_196 -> V_32 , V_196 -> V_57 . V_69 ) ;
if ( V_82 && V_82 -> V_57 . V_78 != V_196 -> V_57 . V_78 ) {
struct V_51 * V_80 ;
for ( V_80 = V_82 ; V_80 ; V_80 = V_80 -> V_199 ) {
if ( V_80 -> V_53 > V_196 -> V_53 )
return;
}
F_48 ( V_2 , V_82 ) ;
V_82 = NULL ;
}
if ( ( V_198 = F_49 ( V_196 -> V_31 , V_196 -> V_32 , V_196 -> V_57 . V_69 ) ) < 0 )
return;
V_196 -> V_199 = V_82 ;
V_196 -> V_200 = V_2 -> V_197 [ V_198 ] ;
V_2 -> V_197 [ V_198 ] = V_196 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_198 ;
struct V_51 * V_80 ;
if ( ( V_198 = F_49 ( V_52 -> V_31 , V_52 -> V_32 , V_52 -> V_57 . V_69 ) ) < 0 )
return;
for ( V_80 = V_2 -> V_197 [ V_198 ] ; V_80 ; V_80 = V_80 -> V_200 ) {
while ( V_80 -> V_200 == V_52 ) {
V_80 -> V_200 = V_52 -> V_200 ;
V_52 = V_52 -> V_199 ;
if ( V_52 == NULL )
return;
}
}
}
int
F_50 ( struct V_1 * V_2 , int * V_201 , int V_202 ,
int V_203 , int V_31 ,
int V_204 , int V_205 ,
struct V_51 * * V_148 , int V_206 )
{
int V_86 ;
unsigned long V_3 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
if ( V_2 -> V_6 ) {
F_4 ( & V_2 -> V_5 , V_3 ) ;
return 0 ;
}
V_86 = F_51 ( V_2 , V_201 , V_202 , V_203 , V_31 ,
V_148 , V_206 , 0 ) ;
if ( ! V_86 ) {
if ( V_203 != V_204 || V_31 != V_205 )
V_86 = F_51 ( V_2 , V_201 , V_202 ,
V_204 , V_205 ,
V_148 , V_206 , 0 ) ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
return V_86 ;
}
static struct V_51 *
F_47 ( struct V_1 * V_2 , int V_31 , int V_203 , int V_17 )
{
int V_198 ;
struct V_51 * V_52 ;
if ( ( V_198 = F_49 ( V_31 , V_203 , V_17 ) ) < 0 )
return NULL ;
for ( V_52 = V_2 -> V_197 [ V_198 ] ; V_52 ; V_52 = V_52 -> V_200 ) {
if ( V_52 -> V_32 == V_203 && V_52 -> V_31 == V_31 )
return V_52 ;
}
return NULL ;
}
static int
F_51 ( struct V_1 * V_2 , int * V_201 , int V_202 ,
int V_203 , int V_31 , struct V_51 * * V_148 ,
int V_206 , int V_207 )
{
struct V_51 * V_52 ;
int V_86 ;
V_52 = F_47 ( V_2 , V_31 , V_203 , * V_201 ) ;
V_86 = 0 ;
for (; V_52 ; V_52 = V_52 -> V_199 ) {
if ( * V_201 >= V_52 -> V_57 . V_69 && * V_201 <= V_52 -> V_57 . V_77 &&
V_202 >= V_52 -> V_57 . V_208 && V_202 <= V_52 -> V_57 . V_97 ) {
if ( V_52 -> V_67 ) {
int V_17 = V_52 -> V_57 . V_75 ;
V_203 = V_52 -> V_57 . V_71 ;
V_31 = V_52 -> V_57 . V_73 ;
if ( V_207 > 5 )
return 0 ;
if ( V_17 < 0 )
V_17 = * V_201 ;
V_86 = F_51 ( V_2 , & V_17 , V_202 ,
V_203 , V_31 , V_148 ,
V_206 , V_207 + 1 ) ;
if ( V_86 > 0 )
* V_201 = V_17 ;
break;
}
V_148 [ V_86 ++ ] = V_52 ;
if ( V_86 >= V_206 )
break;
}
}
return V_86 ;
}
static int
F_49 ( int V_31 , int V_32 , int V_17 )
{
int V_198 ;
if ( F_52 ( V_31 ) )
V_198 = V_17 + V_66 ;
else
V_198 = V_32 ;
V_198 = V_198 % V_209 ;
if ( V_198 < 0 )
return - 1 ;
return V_198 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
V_2 -> V_130 = 0 ;
V_2 -> V_30 = NULL ;
V_2 -> V_8 = - 1 ;
V_2 -> V_42 = NULL ;
V_2 -> V_46 = 0 ;
V_2 -> V_54 = 0 ;
V_2 -> V_60 = 0 ;
V_2 -> V_56 = 0 ;
V_2 -> V_61 = 0 ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_37 * V_38 , * V_210 ;
struct V_51 * V_52 , * V_211 ;
struct V_58 * V_59 , * V_212 ;
for ( V_38 = V_2 -> V_42 ; V_38 ; V_38 = V_210 ) {
V_210 = V_38 -> V_43 ;
for ( V_52 = V_38 -> V_47 ; V_52 ; V_52 = V_211 ) {
V_211 = V_52 -> V_43 ;
F_30 ( V_52 ) ;
}
for ( V_59 = V_38 -> V_48 ; V_59 ; V_59 = V_212 ) {
V_212 = V_59 -> V_43 ;
if ( V_2 -> V_126 . V_213 )
V_2 -> V_126 . V_213 ( V_2 -> V_126 . V_128 ,
V_59 , V_2 -> V_129 ) ;
F_30 ( V_59 ) ;
}
F_30 ( V_38 ) ;
}
F_53 ( V_2 ) ;
}
struct V_1 *
F_55 ( struct V_214 * V_126 , struct V_215 * V_84 )
{
struct V_1 * V_2 ;
if ( ( V_2 = F_21 ( sizeof( * V_2 ) , V_44 ) ) == NULL )
return NULL ;
F_56 ( & V_2 -> V_4 ) ;
F_57 ( & V_2 -> V_5 ) ;
V_2 -> V_129 = V_84 ;
if ( V_126 )
V_2 -> V_126 = * V_126 ;
F_53 ( V_2 ) ;
return V_2 ;
}
void
F_58 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_1 ( V_2 ) ;
if ( V_2 -> V_126 . V_216 )
V_2 -> V_126 . V_216 ( V_2 -> V_126 . V_128 ) ;
F_54 ( V_2 ) ;
F_5 ( V_2 ) ;
F_30 ( V_2 ) ;
}
int
F_59 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_126 . V_216 )
V_2 -> V_126 . V_216 ( V_2 -> V_126 . V_128 ) ;
F_54 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int
F_60 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_51 * V_52 , * V_211 ;
struct V_58 * V_59 , * V_212 ;
F_1 ( V_2 ) ;
if ( V_2 -> V_126 . V_216 )
V_2 -> V_126 . V_216 ( V_2 -> V_126 . V_128 ) ;
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
for ( V_38 = V_2 -> V_42 ; V_38 ; V_38 = V_38 -> V_43 ) {
for ( V_52 = V_38 -> V_47 ; V_52 ; V_52 = V_211 ) {
if ( V_52 -> V_53 < V_2 -> V_56 )
break;
V_211 = V_52 -> V_43 ;
V_38 -> V_47 = V_211 ;
F_30 ( V_52 ) ;
}
for ( V_59 = V_38 -> V_48 ; V_59 ; V_59 = V_212 ) {
if ( V_59 -> V_53 < V_2 -> V_61 )
break;
V_212 = V_59 -> V_43 ;
V_38 -> V_48 = V_212 ;
V_2 -> V_130 -= V_59 -> V_57 . V_125 ;
if ( V_2 -> V_126 . V_213 )
V_2 -> V_126 . V_213 ( V_2 -> V_126 . V_128 ,
V_59 , V_2 -> V_129 ) ;
F_30 ( V_59 ) ;
}
}
V_2 -> V_54 = V_2 -> V_56 ;
V_2 -> V_60 = V_2 -> V_61 ;
F_22 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
