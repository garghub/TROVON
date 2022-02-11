static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
return ( V_3 -> V_4 >> V_2 -> V_5 ) & 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_6 ;
T_1 V_7 = 1 << V_2 -> V_5 ;
int V_8 = 0 ;
F_3 ( & V_2 -> V_9 , V_6 ) ;
if ( F_4 ( V_3 , V_10 ) & V_7 ) {
F_5 ( V_3 , V_11 , V_7 ) ;
V_8 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_6 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_13 = 1 << V_2 -> V_5 ;
unsigned long V_6 ;
F_3 ( & V_2 -> V_9 , V_6 ) ;
if ( V_12 )
V_3 -> V_4 |= V_13 ;
else
V_3 -> V_4 &= ~ V_13 ;
F_5 ( V_3 , V_11 , V_13 ) ;
F_5 ( V_3 , V_14 ,
F_8 ( V_3 -> V_4 ) |
( F_9 ( V_3 ) >> 16 ) ) ;
F_6 ( & V_2 -> V_9 , V_6 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
int V_15 ;
unsigned char * V_16 ;
V_2 -> V_17 = ( V_2 -> V_18 & 0x08 ) ? 1 : 0 ;
V_2 -> V_19 = F_11 ( V_3 -> V_20 / V_2 -> V_21 , 1 ) ;
if ( V_2 -> V_18 == V_22 ) {
V_2 -> V_23 = V_3 -> V_24 >> 1 ;
V_2 -> V_25 = V_3 -> V_26 ;
if ( V_3 -> type == V_27 ) {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_30 ;
V_15 = sizeof( V_30 ) ;
} else {
V_16 = V_31 ;
V_15 = sizeof( V_31 ) ;
}
} else {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_32 ;
V_15 = sizeof( V_32 ) ;
} else {
V_16 = V_33 ;
V_15 = sizeof( V_33 ) ;
}
}
} else {
V_2 -> V_23 = V_3 -> V_24 ;
V_2 -> V_25 = V_3 -> V_26 << 1 ;
V_2 -> V_19 <<= 2 ;
if ( V_3 -> type == V_27 ) {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_34 ;
V_15 = sizeof( V_34 ) ;
} else {
V_16 = V_35 ;
V_15 = sizeof( V_35 ) ;
}
} else {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_36 ;
V_15 = sizeof( V_36 ) ;
} else {
V_16 = V_37 ;
V_15 = sizeof( V_37 ) ;
}
}
}
memcpy ( V_2 -> V_16 , V_16 , V_15 ) ;
if ( V_3 -> type == V_38 ) {
T_2 V_20 = V_3 -> V_20 * 1000 ;
T_2 V_21 = V_2 -> V_21 * 1000 ;
V_16 = V_2 -> V_16 ;
V_16 [ 22 ] = V_20 >> 4 ;
V_16 [ 23 ] = ( ( V_20 << 4 ) & 0xf0 ) | 0x0c
| ( ( V_21 >> 13 ) & 0x3 ) ;
V_16 [ 24 ] = ( V_21 >> 5 ) & 0xff ;
V_16 [ 25 ] = ( ( V_21 << 3 ) & 0xf8 ) | 0x04 ;
}
V_2 -> V_15 = V_15 ;
V_16 = V_2 -> V_39 ;
V_16 [ V_40 + 5 ] = 0xff & ( V_2 -> V_25 >> 8 ) ;
V_16 [ V_40 + 6 ] = 0xff & V_2 -> V_25 ;
V_16 [ V_40 + 7 ] = 0xff & ( V_2 -> V_23 >> 8 ) ;
V_16 [ V_40 + 8 ] = 0xff & V_2 -> V_23 ;
memcpy ( V_16 + V_41 ,
V_42 [ F_12 ( V_3 , V_2 -> V_5 ) ] , V_43 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_3 V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_21 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_19 > V_3 -> V_44 )
return - V_45 ;
V_2 -> V_46 = 0 ;
V_3 -> V_44 -= V_2 -> V_19 ;
if ( V_2 -> type == V_47 )
F_5 ( V_3 , F_14 ( V_5 ) , 1 ) ;
F_5 ( V_3 , F_15 ( V_5 ) , 0 ) ;
F_5 ( V_3 , F_16 ( V_5 ) ,
V_2 -> V_17 ? 1 : 0 ) ;
if ( V_2 -> V_17 )
V_21 = V_2 -> V_21 - 1 ;
else
V_21 = V_2 -> V_21 ;
F_5 ( V_3 , F_17 ( V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_18 ( V_5 ) , V_2 -> V_49 ) ;
F_5 ( V_3 , F_19 ( V_5 ) , V_21 ) ;
F_5 ( V_3 , F_20 ( V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_21 ( V_5 ) , V_2 -> V_49 ) ;
F_5 ( V_3 , F_22 ( V_5 ) , V_21 ) ;
F_5 ( V_3 , F_15 ( V_5 ) , V_2 -> V_18 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
V_3 -> V_44 += V_2 -> V_19 ;
F_5 ( V_3 , F_15 ( V_2 -> V_5 ) , 0 ) ;
F_5 ( V_3 , F_14 ( V_2 -> V_5 ) , 0 ) ;
}
static int F_24 ( struct V_3 * V_3 , T_4 V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
int V_8 ;
if ( V_51 > F_25 ( V_3 ) )
return - V_53 ;
if ( V_51 + V_52 <= F_25 ( V_3 ) ) {
return F_26 ( V_3 , 0 , V_50 ,
F_27 ( V_3 ) + V_51 , V_52 ,
0 , 0 ) ;
}
V_8 = F_26 ( V_3 , 0 , V_50 ,
F_27 ( V_3 ) + V_51 ,
F_25 ( V_3 ) - V_51 , 0 , 0 ) ;
if ( ! V_8 ) {
V_8 = F_26 ( V_3 , 0 ,
V_50 + F_25 ( V_3 ) - V_51 ,
F_27 ( V_3 ) ,
V_52 + V_51 - F_25 ( V_3 ) , 0 , 0 ) ;
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 , int V_54 ,
struct V_55 * V_56 , int V_51 , int V_52 ,
unsigned int V_57 , unsigned int V_58 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_59 * V_60 ;
int V_61 ;
int V_8 ;
if ( F_29 ( V_52 > V_62 ) )
return - V_53 ;
V_2 -> V_63 = 1 ;
F_30 (vbuf->sglist, sg, vbuf->num_pages, i) {
struct V_64 * V_65 ;
T_4 V_50 ;
int V_66 ;
int V_67 = V_58 - V_51 ;
V_65 = & V_2 -> V_68 [ V_2 -> V_63 ++ ] ;
V_50 = F_31 ( V_60 ) ;
V_66 = F_32 ( V_60 ) ;
F_33 ( V_54 >= V_66 ) ;
if ( V_54 ) {
V_66 -= V_54 ;
V_50 += V_54 ;
V_52 -= V_54 ;
V_54 = 0 ;
}
V_66 = F_34 ( V_66 , V_52 ) ;
if ( V_66 <= V_67 ) {
F_35 ( V_65 , 0 , V_50 , V_57 + V_51 ,
V_66 , 0 , 0 ) ;
} else {
V_8 = F_26 ( V_3 , 0 , V_50 , V_57 + V_51 ,
V_67 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_26 ( V_3 , 0 , V_50 + V_67 , V_57 ,
V_66 - V_67 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_63 -- ;
}
V_52 -= V_66 ;
if ( V_52 <= 0 )
break;
V_51 += V_66 ;
if ( V_51 >= V_58 )
V_51 -= V_58 ;
if ( V_2 -> V_63 >= ( V_2 -> V_69 - 1 ) ) {
V_8 = F_36 ( V_3 , V_2 -> V_68 ,
V_2 -> V_70 ,
V_2 -> V_63 - 1 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_63 = 1 ;
}
}
if ( V_2 -> V_63 <= 1 )
return 0 ;
return F_36 ( V_3 , V_2 -> V_68 , V_2 -> V_70 ,
V_2 -> V_63 - 1 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_71 * V_72 , struct V_73 * V_74 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_38 ( V_72 , 0 ) ;
int V_75 ;
int V_8 ;
V_72 -> V_76 . V_6 |= V_77 ;
if ( F_39 ( V_72 , 0 ) < V_74 -> V_78 + V_2 -> V_79 )
return - V_80 ;
F_40 ( V_56 -> V_81 , V_56 -> V_82 ,
V_2 -> V_39 ,
V_2 -> V_79 ) ;
V_75 = ( V_74 -> V_78 + V_2 -> V_79 + ( V_83 - 1 ) )
& ~ ( V_83 - 1 ) ;
F_41 ( V_72 , 0 , V_74 -> V_78 + V_2 -> V_79 ) ;
F_42 ( & V_3 -> V_84 -> V_85 , V_56 -> V_81 , V_56 -> V_82 ,
V_86 ) ;
V_8 = F_28 ( V_2 , V_2 -> V_79 , V_56 , V_74 -> V_87 ,
V_75 , F_43 ( V_3 ) ,
F_44 ( V_3 ) ) ;
F_45 ( & V_3 -> V_84 -> V_85 , V_56 -> V_81 , V_56 -> V_82 ,
V_86 ) ;
return V_8 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_71 * V_72 , struct V_73 * V_74 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_38 ( V_72 , 0 ) ;
int V_88 , V_75 ;
int V_54 = 0 ;
int V_8 ;
if ( F_39 ( V_72 , 0 ) < V_74 -> V_89 )
return - V_80 ;
if ( ! V_74 -> V_90 ) {
F_40 ( V_56 -> V_81 , V_56 -> V_82 ,
V_2 -> V_16 ,
V_2 -> V_15 ) ;
V_54 = V_2 -> V_15 ;
V_72 -> V_76 . V_6 |= V_77 ;
F_41 ( V_72 , 0 , V_74 -> V_89 + V_2 -> V_15 ) ;
} else {
V_72 -> V_76 . V_6 |= V_91 ;
F_41 ( V_72 , 0 , V_74 -> V_89 ) ;
}
V_88 = ( V_74 -> V_92 + sizeof( * V_74 ) )
% F_25 ( V_3 ) ;
V_75 = ( V_74 -> V_89 + V_54 + ( V_83 - 1 ) )
& ~ ( V_83 - 1 ) ;
F_42 ( & V_3 -> V_84 -> V_85 , V_56 -> V_81 , V_56 -> V_82 ,
V_86 ) ;
V_8 = F_28 ( V_2 , V_54 , V_56 , V_88 , V_75 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
F_45 ( & V_3 -> V_84 -> V_85 , V_56 -> V_81 , V_56 -> V_82 ,
V_86 ) ;
return V_8 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_71 * V_72 , struct V_93 * V_94 )
{
struct V_73 * V_74 = V_94 -> V_74 ;
int V_8 ;
V_72 -> V_76 . V_6 &= ~ ( V_95 |
V_96 ) ;
if ( F_1 ( V_2 ) ) {
V_72 -> V_76 . V_6 |= V_95 ;
if ( V_94 -> V_97 )
V_72 -> V_76 . V_6 |= V_96 ;
}
switch ( V_2 -> V_98 ) {
case V_99 :
case V_100 :
V_8 = F_46 ( V_2 , V_72 , V_74 ) ;
break;
default:
V_8 = F_37 ( V_2 , V_72 , V_74 ) ;
break;
}
if ( ! V_8 ) {
V_72 -> V_76 . V_46 = V_2 -> V_46 ++ ;
V_72 -> V_76 . V_101 . V_102 = V_74 -> V_103 ;
V_72 -> V_76 . V_101 . V_104 = V_74 -> V_105 ;
}
F_48 ( V_72 , V_8 ? V_106 : V_107 ) ;
return V_8 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_108 * V_72 ;
unsigned long V_6 ;
F_50 ( & V_2 -> V_109 ) ;
if ( V_2 -> type != V_94 -> type )
goto V_110;
F_3 ( & V_2 -> V_111 , V_6 ) ;
if ( F_51 ( & V_2 -> V_112 ) ) {
F_6 ( & V_2 -> V_111 , V_6 ) ;
goto V_110;
}
V_72 = F_52 ( & V_2 -> V_112 , struct V_108 , V_113 ) ;
F_53 ( & V_72 -> V_113 ) ;
F_6 ( & V_2 -> V_111 , V_6 ) ;
F_47 ( V_2 , & V_72 -> V_72 , V_94 ) ;
V_110:
F_54 ( & V_2 -> V_109 ) ;
}
void F_55 ( struct V_3 * V_3 )
{
F_56 ( & V_3 -> V_114 ) ;
}
static void F_57 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_93 V_94 ;
T_1 V_115 , V_51 ;
T_3 V_5 ;
T_3 V_116 ;
V_116 = F_4 ( V_3 , F_58 ( 11 ) ) & 0xff ;
if ( V_116 == V_3 -> V_117 )
break;
V_115 = F_4 ( V_3 ,
F_59 ( V_3 -> V_117 ) ) ;
V_3 -> V_117 = ( V_3 -> V_117 + 1 ) % V_118 ;
V_5 = ( V_115 >> 24 ) & 0x1f ;
V_51 = V_115 & 0x00ffffff ;
if ( V_5 >= V_119 ) {
V_5 -= V_119 ;
V_94 . type = V_47 ;
} else
V_94 . type = V_120 ;
V_2 = V_3 -> V_121 [ V_5 ] ;
if ( V_2 == NULL ) {
F_60 ( & V_3 -> V_84 -> V_85 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_122 , V_51 ,
sizeof( struct V_73 ) ) )
continue;
V_94 . V_74 = (struct V_73 * ) V_3 -> V_123 ;
V_94 . V_74 -> V_92 -= F_27 ( V_3 ) ;
V_94 . V_74 -> V_87 -= F_43 ( V_3 ) ;
if ( V_94 . V_74 -> V_92 != V_51 )
continue;
if ( F_2 ( V_2 ) )
V_94 . V_97 = 1 ;
else
V_94 . V_97 = 0 ;
F_49 ( V_2 , & V_94 ) ;
}
}
static int F_61 ( void * V_124 )
{
struct V_3 * V_3 = V_124 ;
F_62 ( V_125 , V_126 ) ;
F_63 () ;
F_64 ( & V_3 -> V_114 , & V_125 ) ;
for (; ; ) {
long V_127 = F_65 ( V_128 ) ;
if ( V_127 == - V_129 || F_66 () )
break;
F_67 ( V_3 , V_130 ) ;
F_57 ( V_3 ) ;
F_68 ( V_3 , V_130 ) ;
F_69 () ;
}
F_70 ( & V_3 -> V_114 , & V_125 ) ;
return 0 ;
}
static int F_71 ( struct V_131 * V_132 , const struct V_133 * V_98 ,
unsigned int * V_134 , unsigned int * V_135 ,
unsigned int V_136 [] , void * V_137 [] )
{
V_136 [ 0 ] = V_62 ;
* V_135 = 1 ;
if ( * V_134 < V_138 )
* V_134 = V_138 ;
return 0 ;
}
static void F_72 ( struct V_71 * V_72 )
{
struct V_131 * V_139 = V_72 -> V_131 ;
struct V_1 * V_2 = F_73 ( V_139 ) ;
struct V_108 * V_140 =
F_74 ( V_72 , struct V_108 , V_72 ) ;
F_75 ( & V_2 -> V_111 ) ;
F_76 ( & V_140 -> V_113 , & V_2 -> V_112 ) ;
F_77 ( & V_2 -> V_111 ) ;
}
static int F_78 ( struct V_3 * V_3 )
{
V_3 -> V_141 = F_79 ( F_61 , V_3 ,
V_142 L_2 ) ;
if ( F_80 ( V_3 -> V_141 ) ) {
int V_143 = F_81 ( V_3 -> V_141 ) ;
V_3 -> V_141 = NULL ;
return V_143 ;
}
F_68 ( V_3 , V_130 ) ;
return 0 ;
}
static void F_82 ( struct V_3 * V_3 )
{
if ( V_3 -> V_141 ) {
F_83 ( V_3 -> V_141 ) ;
V_3 -> V_141 = NULL ;
}
F_67 ( V_3 , V_130 ) ;
}
static int F_84 ( struct V_131 * V_132 , unsigned int V_144 )
{
struct V_1 * V_2 = F_73 ( V_132 ) ;
int V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_78 ( V_2 -> V_3 ) ;
}
static int F_85 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_73 ( V_132 ) ;
F_23 ( V_2 ) ;
F_86 ( & V_2 -> V_112 ) ;
F_82 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_87 ( struct V_145 * V_145 , void * V_146 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_148 -> V_149 , V_142 ) ;
snprintf ( V_148 -> V_150 , sizeof( V_148 -> V_150 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_148 -> V_151 , sizeof( V_148 -> V_151 ) , L_4 ,
F_89 ( V_3 -> V_84 ) ) ;
V_148 -> V_152 = V_153 |
V_154 | V_155 ;
V_148 -> V_156 = V_148 -> V_152 | V_157 ;
return 0 ;
}
static int F_90 ( struct V_145 * V_145 , void * V_146 ,
struct V_158 * V_159 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_159 -> V_160 )
return - V_53 ;
snprintf ( V_159 -> V_161 , sizeof( V_159 -> V_161 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_159 -> type = V_162 ;
V_159 -> V_163 = V_2 -> V_164 -> V_165 ;
if ( ! F_91 ( V_3 , V_2 -> V_5 ) )
V_159 -> V_166 = V_167 ;
return 0 ;
}
static int F_92 ( struct V_145 * V_145 , void * V_146 ,
unsigned int V_160 )
{
if ( V_160 )
return - V_53 ;
return 0 ;
}
static int F_93 ( struct V_145 * V_145 , void * V_146 ,
unsigned int * V_160 )
{
* V_160 = 0 ;
return 0 ;
}
static int F_94 ( struct V_145 * V_145 , void * V_146 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
int V_170 = V_2 -> V_3 -> type ;
switch ( V_169 -> V_160 ) {
case 0 :
switch ( V_170 ) {
case V_38 :
V_169 -> V_171 = V_99 ;
strcpy ( V_169 -> V_172 , L_6 ) ;
break;
case V_27 :
V_169 -> V_171 = V_100 ;
strcpy ( V_169 -> V_172 , L_7 ) ;
break;
}
break;
case 1 :
V_169 -> V_171 = V_173 ;
strcpy ( V_169 -> V_172 , L_8 ) ;
break;
default:
return - V_53 ;
}
V_169 -> V_6 = V_174 ;
return 0 ;
}
static inline int F_95 ( T_1 V_175 , int V_170 )
{
return ( V_175 == V_100 && V_170 == V_27 )
|| ( V_175 == V_99 && V_170 == V_38 )
|| V_175 == V_173 ? 0 : - V_53 ;
}
static int F_96 ( struct V_145 * V_145 , void * V_146 ,
struct V_133 * V_169 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_176 * V_177 = & V_169 -> V_98 . V_177 ;
if ( F_95 ( V_177 -> V_171 , V_3 -> type ) )
return - V_53 ;
if ( V_177 -> V_23 < V_3 -> V_24 ||
V_177 -> V_25 < V_3 -> V_26 << 1 ) {
V_177 -> V_23 = V_3 -> V_24 >> 1 ;
V_177 -> V_25 = V_3 -> V_26 ;
} else {
V_177 -> V_23 = V_3 -> V_24 ;
V_177 -> V_25 = V_3 -> V_26 << 1 ;
}
switch ( V_177 -> V_178 ) {
case V_179 :
case V_180 :
break;
case V_181 :
default:
V_177 -> V_178 = V_180 ;
break;
}
V_177 -> V_182 = V_183 ;
V_177 -> V_184 = V_62 ;
V_177 -> V_185 = 0 ;
V_177 -> V_146 = 0 ;
return 0 ;
}
static int F_97 ( struct V_145 * V_145 , void * V_146 ,
struct V_133 * V_169 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_176 * V_177 = & V_169 -> V_98 . V_177 ;
int V_8 ;
if ( F_98 ( & V_2 -> V_186 ) )
return - V_45 ;
V_8 = F_96 ( V_145 , V_146 , V_169 ) ;
if ( V_8 )
return V_8 ;
if ( V_177 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_187 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_98 = V_177 -> V_171 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_145 * V_145 , void * V_146 ,
struct V_133 * V_169 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_176 * V_177 = & V_169 -> V_98 . V_177 ;
V_177 -> V_23 = V_2 -> V_23 ;
V_177 -> V_25 = V_2 -> V_25 ;
V_177 -> V_171 = V_2 -> V_98 ;
V_177 -> V_178 = V_2 -> V_17 ? V_180 :
V_179 ;
V_177 -> V_184 = V_62 ;
V_177 -> V_182 = V_183 ;
V_177 -> V_146 = 0 ;
return 0 ;
}
static int F_100 ( struct V_145 * V_145 , void * V_146 , T_5 * V_61 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_61 = V_188 ;
else
* V_61 = V_189 ;
return 0 ;
}
static int F_101 ( struct V_145 * V_145 , void * V_146 , T_5 V_163 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
return F_102 ( V_2 -> V_3 , V_163 & V_189 ) ;
}
static int F_103 ( struct V_145 * V_145 , void * V_146 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_95 ( V_191 -> V_192 , V_3 -> type ) )
return - V_53 ;
switch ( V_191 -> V_160 ) {
case 0 :
V_191 -> V_193 . V_23 = V_3 -> V_24 >> 1 ;
V_191 -> V_193 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_191 -> V_193 . V_23 = V_3 -> V_24 ;
V_191 -> V_193 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_53 ;
}
V_191 -> type = V_194 ;
return 0 ;
}
static int F_104 ( struct V_145 * V_145 , void * V_146 ,
struct V_195 * V_196 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_95 ( V_196 -> V_192 , V_3 -> type ) )
return - V_53 ;
if ( V_196 -> V_160 )
return - V_53 ;
if ( ( V_196 -> V_23 != V_3 -> V_24 >> 1 ||
V_196 -> V_25 != V_3 -> V_26 ) &&
( V_196 -> V_23 != V_3 -> V_24 ||
V_196 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_53 ;
V_196 -> type = V_197 ;
V_196 -> V_198 . F_34 . V_199 = 1 ;
V_196 -> V_198 . F_34 . V_200 = V_3 -> V_20 ;
V_196 -> V_198 . F_11 . V_199 = 15 ;
V_196 -> V_198 . F_11 . V_200 = V_3 -> V_20 ;
V_196 -> V_198 . V_201 . V_199 = 1 ;
V_196 -> V_198 . V_201 . V_200 = V_3 -> V_20 ;
return 0 ;
}
static int F_105 ( struct V_145 * V_145 , void * V_146 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_204 * V_205 = & V_203 -> V_206 . V_207 ;
V_205 -> V_208 = V_209 ;
V_205 -> V_210 . V_199 = V_2 -> V_21 ;
V_205 -> V_210 . V_200 = V_3 -> V_20 ;
V_205 -> V_211 = 0 ;
V_205 -> V_212 = 2 ;
return 0 ;
}
static int F_106 ( struct V_145 * V_145 , void * V_146 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_204 * V_205 = & V_203 -> V_206 . V_207 ;
if ( F_107 ( & V_2 -> V_186 ) )
return - V_45 ;
if ( ( V_205 -> V_210 . V_199 == 0 ) ||
( V_205 -> V_210 . V_200 == 0 ) ) {
V_205 -> V_210 . V_199 = 1 ;
V_205 -> V_210 . V_200 = V_3 -> V_20 ;
}
if ( V_205 -> V_210 . V_200 != V_3 -> V_20 )
V_205 -> V_210 . V_200 = V_3 -> V_20 ;
if ( V_205 -> V_210 . V_199 > 15 )
V_205 -> V_210 . V_199 = 15 ;
V_2 -> V_21 = V_205 -> V_210 . V_199 ;
V_205 -> V_208 = V_209 ;
V_205 -> V_212 = 2 ;
F_10 ( V_2 ) ;
return 0 ;
}
static long F_108 ( struct V_145 * V_145 , void * V_213 ,
bool V_214 , unsigned int V_215 , void * V_216 )
{
struct V_1 * V_2 = F_88 ( V_145 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_217 * V_218 = V_216 ;
switch ( V_215 ) {
case V_219 :
* V_218 = V_2 -> V_220 ;
return 0 ;
case V_221 :
if ( ! V_214 )
return - V_45 ;
V_2 -> V_220 = * V_218 ;
if ( V_2 -> V_222 && ! V_2 -> V_223 )
return F_109 ( V_3 , V_2 -> V_5 ,
& V_2 -> V_220 ) ;
return 0 ;
default:
return - V_224 ;
}
}
static int F_110 ( struct V_225 * V_226 )
{
struct V_1 * V_2 =
F_74 ( V_226 -> V_227 , struct V_1 , V_228 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_143 ;
switch ( V_226 -> V_229 ) {
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
return F_111 ( V_3 , V_226 -> V_229 , V_2 -> V_5 ,
V_226 -> V_235 ) ;
case V_236 :
V_2 -> V_48 = V_226 -> V_235 ;
return 0 ;
case V_237 :
V_2 -> V_238 = V_226 -> V_235 ;
if ( ! V_2 -> V_223 || ! V_2 -> V_222 )
return 0 ;
return F_112 ( V_3 , V_2 -> V_5 , V_226 -> V_235 ) ;
case V_239 :
V_2 -> V_223 = V_226 -> V_235 == 1 ;
V_2 -> V_222 = V_226 -> V_235 > 0 ;
if ( V_226 -> V_235 ) {
if ( V_2 -> V_223 )
F_112 ( V_3 , V_2 -> V_5 ,
V_2 -> V_238 ) ;
else
F_109 ( V_3 , V_2 -> V_5 ,
& V_2 -> V_220 ) ;
}
F_7 ( V_2 , V_226 -> V_235 ) ;
return 0 ;
case V_240 :
strcpy ( V_2 -> V_241 , V_226 -> string ) ;
V_143 = F_113 ( V_2 ) ;
return V_143 ;
default:
return - V_53 ;
}
return 0 ;
}
static struct V_1 * F_114 ( struct V_3 * V_3 ,
T_3 V_5 , unsigned V_242 )
{
struct V_1 * V_2 ;
struct V_243 * V_228 ;
int V_8 ;
int V_244 , V_245 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_246 ) ;
if ( ! V_2 )
return F_116 ( - V_247 ) ;
V_228 = & V_2 -> V_228 ;
F_117 ( V_228 , 10 ) ;
F_118 ( V_228 , & V_248 ,
V_230 , 0 , 255 , 1 , 128 ) ;
F_118 ( V_228 , & V_248 ,
V_231 , 0 , 255 , 1 , 128 ) ;
F_118 ( V_228 , & V_248 ,
V_232 , 0 , 255 , 1 , 128 ) ;
F_118 ( V_228 , & V_248 ,
V_233 , 0 , 255 , 1 , 128 ) ;
if ( F_119 ( V_3 , V_5 ) )
F_118 ( V_228 , & V_248 ,
V_234 , 0 , 15 , 1 , 0 ) ;
F_118 ( V_228 , & V_248 ,
V_236 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_120 ( V_228 , & V_249 , NULL ) ;
F_120 ( V_228 , & V_250 , NULL ) ;
F_120 ( V_228 , & V_251 , NULL ) ;
if ( V_228 -> error ) {
V_8 = V_228 -> error ;
goto V_252;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_121 ( & V_2 -> V_109 ) ;
F_122 ( & V_2 -> V_111 ) ;
F_86 ( & V_2 -> V_112 ) ;
V_2 -> V_98 = ( V_3 -> type == V_38 ) ?
V_99 : V_100 ;
V_2 -> type = V_120 ;
V_2 -> V_49 = V_253 ;
V_2 -> V_48 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_223 = true ;
V_2 -> V_238 = V_254 ;
for ( V_245 = 0 ; V_245 < V_255 ; V_245 ++ )
for ( V_244 = 0 ; V_244 < V_255 ; V_244 ++ )
V_2 -> V_220 . V_218 [ V_245 ] [ V_244 ] =
V_254 ;
V_2 -> V_186 . type = V_256 ;
V_2 -> V_186 . V_257 = V_258 | V_259 | V_260 ;
V_2 -> V_186 . V_261 = & V_262 ;
V_2 -> V_186 . V_263 = & V_264 ;
V_2 -> V_186 . V_265 = V_2 ;
V_2 -> V_186 . V_266 = V_267 ;
V_2 -> V_186 . V_268 = V_269 ;
V_2 -> V_186 . V_270 = sizeof( struct V_108 ) ;
V_2 -> V_186 . V_109 = & V_2 -> V_109 ;
V_8 = F_123 ( & V_2 -> V_186 ) ;
if ( V_8 )
goto V_252;
F_10 ( V_2 ) ;
F_122 ( & V_2 -> V_9 ) ;
V_2 -> V_79 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_79 ) ;
V_2 -> V_69 = 32 ;
V_2 -> V_68 = F_124 ( V_3 -> V_84 ,
sizeof( struct V_64 ) *
V_2 -> V_69 , & V_2 -> V_70 ) ;
V_8 = - V_247 ;
if ( V_2 -> V_68 == NULL )
goto V_252;
V_2 -> V_164 = F_125 () ;
if ( ! V_2 -> V_164 )
goto V_271;
* V_2 -> V_164 = V_272 ;
V_2 -> V_164 -> V_273 = & V_3 -> V_273 ;
V_2 -> V_164 -> V_274 = V_228 ;
V_2 -> V_164 -> V_275 = & V_2 -> V_186 ;
V_2 -> V_164 -> V_109 = & V_2 -> V_109 ;
F_126 ( V_276 , & V_2 -> V_164 -> V_6 ) ;
F_127 ( V_2 -> V_164 , V_2 ) ;
V_8 = F_128 ( V_2 -> V_164 , V_277 , V_242 ) ;
if ( V_8 < 0 )
goto V_278;
snprintf ( V_2 -> V_164 -> V_161 , sizeof( V_2 -> V_164 -> V_161 ) ,
L_9 , V_142 , V_3 -> V_164 -> V_279 ,
V_2 -> V_164 -> V_279 ) ;
return V_2 ;
V_278:
F_129 ( V_2 -> V_164 ) ;
V_271:
F_130 ( V_2 -> V_3 -> V_84 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
V_252:
F_131 ( V_228 ) ;
F_132 ( V_2 ) ;
return F_116 ( V_8 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_134 ( V_2 -> V_164 ) ;
F_131 ( & V_2 -> V_228 ) ;
F_132 ( V_2 ) ;
}
int F_135 ( struct V_3 * V_3 , unsigned V_242 )
{
int V_61 ;
F_136 ( & V_3 -> V_114 ) ;
V_3 -> V_280 = sizeof( struct V_73 ) ;
V_3 -> V_123 = F_124 ( V_3 -> V_84 ,
V_3 -> V_280 ,
& V_3 -> V_122 ) ;
if ( V_3 -> V_123 == NULL )
return - V_247 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_281 ; V_61 ++ ) {
V_3 -> V_121 [ V_61 ] = F_114 ( V_3 , V_61 , V_242 ) ;
if ( F_80 ( V_3 -> V_121 [ V_61 ] ) )
break;
}
if ( V_61 != V_3 -> V_281 ) {
int V_8 = F_81 ( V_3 -> V_121 [ V_61 ] ) ;
while ( V_61 -- )
F_133 ( V_3 -> V_121 [ V_61 ] ) ;
F_130 ( V_3 -> V_84 , V_3 -> V_280 ,
V_3 -> V_123 , V_3 -> V_122 ) ;
V_3 -> V_123 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_137 ( & V_3 -> V_84 -> V_85 , L_10 ,
V_3 -> V_121 [ 0 ] -> V_164 -> V_279 ,
V_3 -> V_121 [ V_3 -> V_281 - 1 ] -> V_164 -> V_279 ) ;
return 0 ;
}
void F_138 ( struct V_3 * V_3 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_281 ; V_61 ++ )
F_133 ( V_3 -> V_121 [ V_61 ] ) ;
if ( V_3 -> V_123 )
F_130 ( V_3 -> V_84 , V_3 -> V_280 ,
V_3 -> V_123 , V_3 -> V_122 ) ;
}
