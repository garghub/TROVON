static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
return 1 ;
else
return 0 ;
}
static void F_2 ( struct V_5 * V_6 )
{
T_1 V_7 = 0x0 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_7 = 0x2 ;
break;
case V_10 :
V_7 = 0x1 ;
break;
case V_11 :
V_7 = 0x0 ;
break;
default:
F_4 ( L_1 ) ;
V_7 = 0x1 ;
break;
}
F_5 ( V_6 , V_7 , V_12 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( V_2 -> V_13 )
F_5 ( V_6 , F_7 ( V_6 , V_14 ) | V_15 , V_14 ) ;
else
F_5 ( V_6 , F_7 ( V_6 , V_14 ) & ~ V_15 , V_14 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_16 ) {
case 10 :
F_5 ( V_6 , F_7 ( V_6 , V_14 ) & ~ V_17 , V_14 ) ;
break;
case 100 :
F_5 ( V_6 , F_7 ( V_6 , V_14 ) | V_17 , V_14 ) ;
break;
default:
break;
}
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_16 ) {
case 10 :
F_5 ( V_6 , F_7 ( V_6 , V_14 ) & ~ V_18 , V_14 ) ;
break;
case 100 :
F_5 ( V_6 , F_7 ( V_6 , V_14 ) | V_18 , V_14 ) ;
break;
default:
break;
}
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_16 ) {
case 10 :
F_5 ( V_6 , 0 , V_19 ) ;
break;
case 100 :
F_5 ( V_6 , 1 , V_19 ) ;
break;
default:
break;
}
}
static void F_11 ( struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_21 [ 2 ] , V_22 [ 2 ] ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_22 [ V_20 ] = F_12 ( ( void * ) F_13 ( V_20 ) ) ;
V_21 [ V_20 ] = F_12 ( ( void * ) F_14 ( V_20 ) ) ;
}
F_15 ( V_23 , ( void * ) ( V_24 + 0x1800 ) ) ;
F_16 ( 1 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
F_15 ( V_22 [ V_20 ] , ( void * ) F_13 ( V_20 ) ) ;
F_15 ( V_21 [ V_20 ] , ( void * ) F_14 ( V_20 ) ) ;
}
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_16 ) {
case 10 :
F_5 ( V_6 , 0x00000000 , V_25 ) ;
break;
case 100 :
F_5 ( V_6 , 0x00000010 , V_25 ) ;
break;
case 1000 :
F_5 ( V_6 , 0x00000020 , V_25 ) ;
break;
default:
break;
}
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_19 ( V_2 , V_23 , V_26 ) ;
F_16 ( 1 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
switch ( V_2 -> V_16 ) {
case 10 :
F_5 ( V_6 , V_27 , V_25 ) ;
break;
case 100 :
F_5 ( V_6 , V_28 , V_25 ) ;
break;
case 1000 :
F_5 ( V_6 , V_29 , V_25 ) ;
break;
default:
break;
}
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_19 ( V_2 , V_23 , V_26 ) ;
F_16 ( 1 ) ;
F_2 ( V_6 ) ;
}
static void F_22 ( struct V_30 * V_31 )
{
if ( ! V_31 -> V_32 )
V_31 -> V_32 = V_33 ;
if ( ! V_31 -> V_34 )
V_31 -> V_34 = V_35 ;
if ( ! V_31 -> V_36 )
V_31 -> V_36 = V_37 | \
V_38 ;
if ( ! V_31 -> V_39 )
V_31 -> V_39 = V_40 ;
if ( ! V_31 -> V_41 )
V_31 -> V_41 = V_42 ;
if ( ! V_31 -> V_43 )
V_31 -> V_43 = V_44 ;
if ( ! V_31 -> V_45 )
V_31 -> V_45 = V_46 ;
}
static int F_23 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
int V_48 = 100 ;
while ( V_48 > 0 ) {
if ( ! ( F_7 ( V_6 , V_49 ) & 0x3 ) )
break;
F_16 ( 1 ) ;
V_48 -- ;
}
if ( V_48 <= 0 ) {
F_24 ( L_2 ) ;
V_47 = - V_50 ;
}
return V_47 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_47 = 0 ;
if ( F_1 ( V_2 ) ) {
F_5 ( V_6 , V_51 , V_52 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_49 ) | V_53 ,
V_49 ) ;
V_47 = F_23 ( V_6 ) ;
if ( V_47 )
goto V_54;
F_5 ( V_6 , 0x0 , V_55 ) ;
F_5 ( V_6 , 0x0 , V_56 ) ;
F_5 ( V_6 , 0x0 , V_57 ) ;
F_5 ( V_6 , 0x0 , V_58 ) ;
F_5 ( V_6 , 0x0 , V_59 ) ;
F_5 ( V_6 , 0x0 , V_60 ) ;
F_5 ( V_6 , 0x0 , V_61 ) ;
F_5 ( V_6 , 0x0 , V_62 ) ;
if ( V_2 -> V_31 -> V_63 )
F_5 ( V_6 , 0x0 , V_64 ) ;
if ( V_2 -> V_31 -> V_65 )
F_2 ( V_6 ) ;
} else {
F_5 ( V_6 , F_7 ( V_6 , V_49 ) | V_66 ,
V_49 ) ;
F_16 ( 3 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_49 ) & ~ V_66 ,
V_49 ) ;
}
V_54:
return V_47 ;
}
static void F_26 ( struct V_67 * V_68 )
{
int V_69 ;
V_69 = V_70 - ( ( T_1 ) V_68 -> V_71 & ( V_70 - 1 ) ) ;
if ( V_69 )
F_27 ( V_68 , V_69 ) ;
}
static void F_26 ( struct V_67 * V_68 )
{
F_27 ( V_68 , V_72 ) ;
}
static inline T_2 F_28 ( struct V_1 * V_2 , T_1 V_73 )
{
switch ( V_2 -> V_74 ) {
case V_75 :
return F_29 ( V_73 ) ;
case V_76 :
return F_30 ( V_73 ) ;
}
return V_73 ;
}
static inline T_2 F_31 ( struct V_1 * V_2 , T_1 V_73 )
{
switch ( V_2 -> V_74 ) {
case V_75 :
return F_32 ( V_73 ) ;
case V_76 :
return F_33 ( V_73 ) ;
}
return V_73 ;
}
static void F_34 ( struct V_5 * V_6 )
{
F_5 ( V_6 ,
( V_6 -> V_77 [ 0 ] << 24 ) | ( V_6 -> V_77 [ 1 ] << 16 ) |
( V_6 -> V_77 [ 2 ] << 8 ) | ( V_6 -> V_77 [ 3 ] ) , V_78 ) ;
F_5 ( V_6 ,
( V_6 -> V_77 [ 4 ] << 8 ) | ( V_6 -> V_77 [ 5 ] ) , V_79 ) ;
}
static void F_35 ( struct V_5 * V_6 , unsigned char * V_80 )
{
if ( V_80 [ 0 ] || V_80 [ 1 ] || V_80 [ 2 ] || V_80 [ 3 ] || V_80 [ 4 ] || V_80 [ 5 ] ) {
memcpy ( V_6 -> V_77 , V_80 , 6 ) ;
} else {
V_6 -> V_77 [ 0 ] = ( F_7 ( V_6 , V_78 ) >> 24 ) ;
V_6 -> V_77 [ 1 ] = ( F_7 ( V_6 , V_78 ) >> 16 ) & 0xFF ;
V_6 -> V_77 [ 2 ] = ( F_7 ( V_6 , V_78 ) >> 8 ) & 0xFF ;
V_6 -> V_77 [ 3 ] = ( F_7 ( V_6 , V_78 ) & 0xFF ) ;
V_6 -> V_77 [ 4 ] = ( F_7 ( V_6 , V_79 ) >> 8 ) & 0xFF ;
V_6 -> V_77 [ 5 ] = ( F_7 ( V_6 , V_79 ) & 0xFF ) ;
}
}
static unsigned long F_36 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_81 ;
else
return V_82 ;
}
static void F_37 ( void * V_83 , T_1 V_84 )
{
F_15 ( F_12 ( V_83 ) | V_84 , V_83 ) ;
}
static void F_38 ( void * V_83 , T_1 V_84 )
{
F_15 ( ( F_12 ( V_83 ) & ~ V_84 ) , V_83 ) ;
}
static int F_39 ( void * V_83 , T_1 V_84 )
{
return ( F_12 ( V_83 ) & V_84 ) != 0 ;
}
static void F_40 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_41 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_37 ( V_89 -> V_83 , V_89 -> V_91 ) ;
else
F_38 ( V_89 -> V_83 , V_89 -> V_91 ) ;
}
static void F_42 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_41 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_37 ( V_89 -> V_83 , V_89 -> V_92 ) ;
else
F_38 ( V_89 -> V_83 , V_89 -> V_92 ) ;
}
static int F_43 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = F_41 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
return F_39 ( V_89 -> V_83 , V_89 -> V_93 ) ;
}
static void F_44 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_41 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_37 ( V_89 -> V_83 , V_89 -> V_94 ) ;
else
F_38 ( V_89 -> V_83 , V_89 -> V_94 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 ;
if ( V_2 -> V_95 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_96 ; V_20 ++ ) {
if ( V_2 -> V_95 [ V_20 ] )
F_46 ( V_2 -> V_95 [ V_20 ] ) ;
}
}
F_47 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
if ( V_2 -> V_97 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_98 ; V_20 ++ ) {
if ( V_2 -> V_97 [ V_20 ] )
F_46 ( V_2 -> V_97 [ V_20 ] ) ;
}
}
F_47 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 ;
struct V_67 * V_68 ;
struct V_99 * V_100 = NULL ;
struct V_101 * V_102 = NULL ;
int V_103 = sizeof( * V_100 ) * V_2 -> V_96 ;
int V_104 = sizeof( * V_102 ) * V_2 -> V_98 ;
V_2 -> V_105 = V_2 -> V_106 = 0 ;
V_2 -> V_107 = V_2 -> V_108 = 0 ;
memset ( V_2 -> V_109 , 0 , V_103 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_96 ; V_20 ++ ) {
V_2 -> V_95 [ V_20 ] = NULL ;
V_68 = F_49 ( V_6 , V_2 -> V_110 ) ;
V_2 -> V_95 [ V_20 ] = V_68 ;
if ( V_68 == NULL )
break;
F_50 ( & V_6 -> V_111 , V_68 -> V_71 , V_2 -> V_110 ,
V_112 ) ;
F_26 ( V_68 ) ;
V_100 = & V_2 -> V_109 [ V_20 ] ;
V_100 -> V_83 = F_51 ( F_52 ( V_68 -> V_71 , 4 ) ) ;
V_100 -> V_113 = F_28 ( V_2 , V_114 | V_115 ) ;
V_100 -> V_116 = F_53 ( V_2 -> V_110 , 16 ) ;
if ( V_20 == 0 ) {
F_5 ( V_6 , V_2 -> V_117 , V_59 ) ;
if ( F_1 ( V_2 ) )
F_5 ( V_6 , V_2 -> V_117 , V_60 ) ;
}
}
V_2 -> V_107 = ( T_1 ) ( V_20 - V_2 -> V_96 ) ;
V_100 -> V_113 |= F_28 ( V_2 , V_118 ) ;
memset ( V_2 -> V_119 , 0 , V_104 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_98 ; V_20 ++ ) {
V_2 -> V_97 [ V_20 ] = NULL ;
V_102 = & V_2 -> V_119 [ V_20 ] ;
V_102 -> V_113 = F_28 ( V_2 , V_120 ) ;
V_102 -> V_116 = 0 ;
if ( V_20 == 0 ) {
F_5 ( V_6 , V_2 -> V_121 , V_55 ) ;
if ( F_1 ( V_2 ) )
F_5 ( V_6 , V_2 -> V_121 , V_56 ) ;
}
}
V_102 -> V_113 |= F_28 ( V_2 , V_122 ) ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_103 , V_104 , V_47 = 0 ;
V_2 -> V_110 = ( V_6 -> V_123 <= 1492 ? V_124 :
( ( ( V_6 -> V_123 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_31 -> V_125 )
V_2 -> V_110 += V_126 ;
V_2 -> V_95 = F_55 ( V_2 -> V_96 ,
sizeof( * V_2 -> V_95 ) , V_127 ) ;
if ( ! V_2 -> V_95 ) {
V_47 = - V_128 ;
return V_47 ;
}
V_2 -> V_97 = F_55 ( V_2 -> V_98 ,
sizeof( * V_2 -> V_97 ) , V_127 ) ;
if ( ! V_2 -> V_97 ) {
V_47 = - V_128 ;
goto V_129;
}
V_103 = sizeof( struct V_99 ) * V_2 -> V_96 ;
V_2 -> V_109 = F_56 ( NULL , V_103 , & V_2 -> V_117 ,
V_127 ) ;
if ( ! V_2 -> V_109 ) {
V_47 = - V_128 ;
goto V_130;
}
V_2 -> V_107 = 0 ;
V_104 = sizeof( struct V_101 ) * V_2 -> V_98 ;
V_2 -> V_119 = F_56 ( NULL , V_104 , & V_2 -> V_121 ,
V_127 ) ;
if ( ! V_2 -> V_119 ) {
V_47 = - V_128 ;
goto V_130;
}
return V_47 ;
V_130:
F_57 ( NULL , V_103 , V_2 -> V_109 , V_2 -> V_117 ) ;
V_129:
F_45 ( V_6 ) ;
V_2 -> V_119 = NULL ;
V_2 -> V_109 = NULL ;
return V_47 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_131 ;
if ( V_2 -> V_109 ) {
V_131 = sizeof( struct V_99 ) * V_2 -> V_96 ;
F_57 ( NULL , V_131 , V_2 -> V_109 ,
V_2 -> V_117 ) ;
V_2 -> V_109 = NULL ;
}
if ( V_2 -> V_119 ) {
V_131 = sizeof( struct V_101 ) * V_2 -> V_98 ;
F_57 ( NULL , V_131 , V_2 -> V_119 ,
V_2 -> V_121 ) ;
V_2 -> V_119 = NULL ;
}
}
static int F_59 ( struct V_5 * V_6 , bool V_132 )
{
int V_47 = 0 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_133 ;
V_47 = F_25 ( V_6 ) ;
if ( V_47 )
goto V_54;
F_48 ( V_6 ) ;
if ( V_2 -> V_31 -> V_125 )
F_5 ( V_6 , V_2 -> V_31 -> V_134 , V_135 ) ;
F_5 ( V_6 , 0 , V_136 ) ;
#if F_60 ( V_137 )
if ( V_2 -> V_31 -> V_138 )
F_5 ( V_6 , V_139 , V_49 ) ;
else
#endif
F_5 ( V_6 , 0 , V_49 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_39 , V_140 ) ;
F_5 ( V_6 , 0 , V_141 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_41 , V_142 ) ;
F_5 ( V_6 , V_143 | V_144 | V_145 , V_146 ) ;
if ( V_2 -> V_31 -> V_147 )
F_5 ( V_6 , 0x800 , V_148 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_36 , V_149 ) ;
if ( ! V_2 -> V_31 -> V_150 )
F_5 ( V_6 , 0 , V_151 ) ;
F_5 ( V_6 , V_6 -> V_123 + V_152 + V_153 + V_154 ,
V_155 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_156 ) , V_156 ) ;
if ( V_132 )
F_5 ( V_6 , V_2 -> V_31 -> V_157 , V_136 ) ;
V_133 = ( F_7 ( V_6 , V_14 ) & V_15 ) |
V_158 | ( V_2 -> V_13 ? V_15 : 0 ) | V_159 | V_160 ;
F_5 ( V_6 , V_133 , V_14 ) ;
if ( V_2 -> V_31 -> V_161 )
V_2 -> V_31 -> V_161 ( V_6 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_32 , V_162 ) ;
if ( V_132 )
F_5 ( V_6 , V_2 -> V_31 -> V_34 , V_163 ) ;
F_34 ( V_6 ) ;
if ( V_2 -> V_31 -> V_164 )
F_5 ( V_6 , V_165 , V_166 ) ;
if ( V_2 -> V_31 -> V_167 )
F_5 ( V_6 , V_168 , V_169 ) ;
if ( V_2 -> V_31 -> V_170 )
F_5 ( V_6 , V_171 , V_172 ) ;
if ( V_132 ) {
F_5 ( V_6 , V_173 , V_174 ) ;
F_61 ( V_6 ) ;
}
V_54:
return V_47 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_101 * V_102 ;
int V_175 = 0 ;
int V_176 = 0 ;
for (; V_2 -> V_106 - V_2 -> V_108 > 0 ; V_2 -> V_108 ++ ) {
V_176 = V_2 -> V_108 % V_2 -> V_98 ;
V_102 = & V_2 -> V_119 [ V_176 ] ;
if ( V_102 -> V_113 & F_28 ( V_2 , V_177 ) )
break;
if ( V_2 -> V_97 [ V_176 ] ) {
F_63 ( & V_6 -> V_111 , V_102 -> V_83 ,
V_102 -> V_116 , V_178 ) ;
F_64 ( V_2 -> V_97 [ V_176 ] ) ;
V_2 -> V_97 [ V_176 ] = NULL ;
V_175 ++ ;
}
V_102 -> V_113 = F_28 ( V_2 , V_120 ) ;
if ( V_176 >= V_2 -> V_98 - 1 )
V_102 -> V_113 |= F_28 ( V_2 , V_122 ) ;
V_6 -> V_179 . V_180 ++ ;
V_6 -> V_179 . V_181 += V_102 -> V_116 ;
}
return V_175 ;
}
static int F_65 ( struct V_5 * V_6 , T_1 V_182 , int * V_183 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_99 * V_100 ;
int V_176 = V_2 -> V_105 % V_2 -> V_96 ;
int V_184 = ( V_2 -> V_107 + V_2 -> V_96 ) - V_2 -> V_105 ;
struct V_67 * V_68 ;
int V_185 = 0 ;
T_3 V_186 = 0 ;
T_1 V_187 ;
V_100 = & V_2 -> V_109 [ V_176 ] ;
while ( ! ( V_100 -> V_113 & F_28 ( V_2 , V_114 ) ) ) {
V_187 = F_31 ( V_2 , V_100 -> V_113 ) ;
V_186 = V_100 -> V_188 ;
if ( -- V_184 < 0 )
break;
if ( * V_183 <= 0 ) {
V_185 = 1 ;
break;
}
( * V_183 ) -- ;
if ( ! ( V_187 & V_189 ) )
V_6 -> V_179 . V_190 ++ ;
if ( V_2 -> V_31 -> V_191 )
V_187 >>= 16 ;
if ( V_187 & ( V_192 | V_193 | V_194 | V_195 |
V_196 | V_197 | V_198 ) ) {
V_6 -> V_179 . V_199 ++ ;
if ( V_187 & V_192 )
V_6 -> V_179 . V_200 ++ ;
if ( V_187 & V_193 )
V_6 -> V_179 . V_201 ++ ;
if ( V_187 & V_194 )
V_6 -> V_179 . V_190 ++ ;
if ( V_187 & V_195 )
V_6 -> V_179 . V_190 ++ ;
if ( V_187 & V_197 )
V_6 -> V_179 . V_202 ++ ;
if ( V_187 & V_198 )
V_6 -> V_179 . V_203 ++ ;
} else {
if ( ! V_2 -> V_31 -> V_138 )
F_66 (
F_67 ( F_53 ( V_100 -> V_83 , 4 ) ) ,
V_186 + 2 ) ;
V_68 = V_2 -> V_95 [ V_176 ] ;
V_2 -> V_95 [ V_176 ] = NULL ;
if ( V_2 -> V_31 -> V_125 )
F_27 ( V_68 , V_126 ) ;
F_68 ( V_68 , V_186 ) ;
V_68 -> V_204 = F_69 ( V_68 , V_6 ) ;
F_70 ( V_68 ) ;
V_6 -> V_179 . V_205 ++ ;
V_6 -> V_179 . V_206 += V_186 ;
}
V_100 -> V_113 |= F_28 ( V_2 , V_114 ) ;
V_176 = ( ++ V_2 -> V_105 ) % V_2 -> V_96 ;
V_100 = & V_2 -> V_109 [ V_176 ] ;
}
for (; V_2 -> V_105 - V_2 -> V_107 > 0 ; V_2 -> V_107 ++ ) {
V_176 = V_2 -> V_107 % V_2 -> V_96 ;
V_100 = & V_2 -> V_109 [ V_176 ] ;
V_100 -> V_116 = F_53 ( V_2 -> V_110 , 16 ) ;
if ( V_2 -> V_95 [ V_176 ] == NULL ) {
V_68 = F_49 ( V_6 , V_2 -> V_110 ) ;
V_2 -> V_95 [ V_176 ] = V_68 ;
if ( V_68 == NULL )
break;
F_50 ( & V_6 -> V_111 , V_68 -> V_71 , V_2 -> V_110 ,
V_112 ) ;
F_26 ( V_68 ) ;
F_71 ( V_68 ) ;
V_100 -> V_83 = F_51 ( F_52 ( V_68 -> V_71 , 4 ) ) ;
}
if ( V_176 >= V_2 -> V_96 - 1 )
V_100 -> V_113 |=
F_28 ( V_2 , V_114 | V_115 | V_118 ) ;
else
V_100 -> V_113 |=
F_28 ( V_2 , V_114 | V_115 ) ;
}
if ( ! ( F_7 ( V_6 , V_174 ) & V_173 ) ) {
if ( V_182 & V_207 )
V_2 -> V_105 = V_2 -> V_107 =
( F_7 ( V_6 , V_60 ) -
F_7 ( V_6 , V_59 ) ) >> 4 ;
F_5 ( V_6 , V_173 , V_174 ) ;
}
return V_185 ;
}
static void F_72 ( struct V_5 * V_6 )
{
F_5 ( V_6 , F_7 ( V_6 , V_14 ) &
~ ( V_160 | V_159 ) , V_14 ) ;
}
static void F_73 ( struct V_5 * V_6 )
{
F_5 ( V_6 , F_7 ( V_6 , V_14 ) |
( V_160 | V_159 ) , V_14 ) ;
}
static void F_74 ( struct V_5 * V_6 , int V_182 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
if ( V_182 & V_211 ) {
V_208 = F_7 ( V_6 , V_162 ) ;
F_5 ( V_6 , V_208 , V_162 ) ;
if ( V_208 & V_212 )
V_6 -> V_179 . V_213 ++ ;
if ( V_208 & V_214 ) {
if ( V_2 -> V_31 -> V_215 || V_2 -> V_216 ) {
goto V_217;
} else {
V_209 = ( F_7 ( V_6 , V_218 ) ) ;
if ( V_2 -> V_219 )
V_209 = ~ V_209 ;
}
if ( ! ( V_209 & V_220 ) )
F_72 ( V_6 ) ;
else {
F_5 ( V_6 , F_7 ( V_6 , V_136 ) &
~ V_221 , V_136 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_162 ) ,
V_162 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_136 ) |
V_221 , V_136 ) ;
F_73 ( V_6 ) ;
}
}
}
V_217:
if ( V_182 & V_222 ) {
if ( V_182 & V_223 ) {
V_6 -> V_179 . V_224 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_3 ) ;
}
}
if ( V_182 & V_225 ) {
if ( V_182 & V_226 ) {
V_6 -> V_179 . V_201 ++ ;
if ( F_77 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_4 ) ;
}
}
if ( V_182 & V_227 ) {
V_6 -> V_179 . V_228 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_5 ) ;
}
if ( V_182 & V_229 ) {
V_6 -> V_179 . V_228 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_6 ) ;
}
if ( V_182 & V_207 ) {
V_6 -> V_179 . V_203 ++ ;
if ( F_77 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_7 ) ;
}
if ( V_182 & V_230 ) {
V_6 -> V_179 . V_231 ++ ;
if ( F_77 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_8 ) ;
}
if ( ! V_2 -> V_31 -> V_232 && ( V_182 & V_233 ) ) {
V_6 -> V_179 . V_228 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_9 ) ;
}
V_210 = V_222 | V_223 | V_233 | V_227 | V_229 ;
if ( V_2 -> V_31 -> V_232 )
V_210 &= ~ V_233 ;
if ( V_182 & V_210 ) {
T_1 V_234 = F_7 ( V_6 , V_235 ) ;
F_76 ( & V_6 -> V_111 , L_10 ,
V_182 , V_2 -> V_106 ) ;
F_76 ( & V_6 -> V_111 , L_11 ,
V_2 -> V_108 , ( T_1 ) V_6 -> V_236 , V_234 ) ;
F_62 ( V_6 ) ;
if ( V_234 ^ F_36 ( V_2 ) ) {
F_5 ( V_6 , F_36 ( V_2 ) , V_235 ) ;
}
F_78 ( V_6 ) ;
}
}
static T_4 F_79 ( int V_237 , void * V_238 )
{
struct V_5 * V_6 = V_238 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
T_4 V_47 = V_239 ;
unsigned long V_182 , V_240 ;
F_80 ( & V_2 -> V_241 ) ;
V_182 = F_7 ( V_6 , V_156 ) ;
V_240 = F_7 ( V_6 , V_136 ) ;
V_182 &= V_240 | V_221 ;
if ( V_182 & ( V_242 | V_31 -> V_43 | V_31 -> V_45 ) )
V_47 = V_243 ;
else
goto V_244;
if ( V_182 & V_242 ) {
if ( F_81 ( & V_2 -> V_245 ) ) {
F_5 ( V_6 , V_240 & ~ V_242 ,
V_136 ) ;
F_82 ( & V_2 -> V_245 ) ;
} else {
F_83 ( & V_6 -> V_111 ,
L_12 ,
V_182 , V_240 ) ;
}
}
if ( V_182 & V_31 -> V_43 ) {
F_5 ( V_6 , V_182 & V_31 -> V_43 , V_156 ) ;
F_62 ( V_6 ) ;
F_78 ( V_6 ) ;
}
if ( V_182 & V_31 -> V_45 ) {
F_5 ( V_6 , V_182 & V_31 -> V_45 , V_156 ) ;
F_74 ( V_6 , V_182 ) ;
}
V_244:
F_84 ( & V_2 -> V_241 ) ;
return V_47 ;
}
static int F_85 ( struct V_246 * V_245 , int V_247 )
{
struct V_1 * V_2 = F_41 ( V_245 , struct V_1 ,
V_245 ) ;
struct V_5 * V_6 = V_245 -> V_111 ;
int V_183 = V_247 ;
unsigned long V_182 ;
for (; ; ) {
V_182 = F_7 ( V_6 , V_156 ) ;
if ( ! ( V_182 & V_242 ) )
break;
F_5 ( V_6 , V_182 & V_242 , V_156 ) ;
if ( F_65 ( V_6 , V_182 , & V_183 ) )
goto V_54;
}
F_86 ( V_245 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_157 , V_136 ) ;
V_54:
return V_247 - V_183 ;
}
static void F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_248 * V_249 = V_2 -> V_249 ;
int V_250 = 0 ;
if ( V_249 -> V_251 ) {
if ( V_249 -> V_13 != V_2 -> V_13 ) {
V_250 = 1 ;
V_2 -> V_13 = V_249 -> V_13 ;
if ( V_2 -> V_31 -> V_252 )
V_2 -> V_31 -> V_252 ( V_6 ) ;
}
if ( V_249 -> V_16 != V_2 -> V_16 ) {
V_250 = 1 ;
V_2 -> V_16 = V_249 -> V_16 ;
if ( V_2 -> V_31 -> V_161 )
V_2 -> V_31 -> V_161 ( V_6 ) ;
}
if ( ! V_2 -> V_251 ) {
F_5 ( V_6 ,
( F_7 ( V_6 , V_14 ) & ~ V_253 ) , V_14 ) ;
V_250 = 1 ;
V_2 -> V_251 = V_249 -> V_251 ;
if ( V_2 -> V_31 -> V_215 || V_2 -> V_216 )
F_73 ( V_6 ) ;
}
} else if ( V_2 -> V_251 ) {
V_250 = 1 ;
V_2 -> V_251 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_13 = - 1 ;
if ( V_2 -> V_31 -> V_215 || V_2 -> V_216 )
F_72 ( V_6 ) ;
}
if ( V_250 && F_88 ( V_2 ) )
F_89 ( V_249 ) ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
char V_254 [ V_255 + 3 ] ;
struct V_248 * V_249 = NULL ;
snprintf ( V_254 , sizeof( V_254 ) , V_256 ,
V_2 -> V_257 -> V_258 , V_2 -> V_254 ) ;
V_2 -> V_251 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_13 = - 1 ;
V_249 = F_91 ( V_6 , V_254 , F_87 ,
V_2 -> V_8 ) ;
if ( F_92 ( V_249 ) ) {
F_76 ( & V_6 -> V_111 , L_13 ) ;
return F_93 ( V_249 ) ;
}
F_94 ( & V_6 -> V_111 , L_14 ,
V_249 -> V_83 , V_249 -> V_259 -> V_260 ) ;
V_2 -> V_249 = V_249 ;
return 0 ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_47 ;
V_47 = F_90 ( V_6 ) ;
if ( V_47 )
return V_47 ;
F_96 ( V_2 -> V_249 , V_261 , V_262 ) ;
F_97 ( V_2 -> V_249 ) ;
return 0 ;
}
static int F_98 ( struct V_5 * V_6 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_265 ;
int V_47 ;
F_99 ( & V_2 -> V_241 , V_265 ) ;
V_47 = F_100 ( V_2 -> V_249 , V_264 ) ;
F_101 ( & V_2 -> V_241 , V_265 ) ;
return V_47 ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_265 ;
int V_47 ;
F_99 ( & V_2 -> V_241 , V_265 ) ;
F_72 ( V_6 ) ;
V_47 = F_103 ( V_2 -> V_249 , V_264 ) ;
if ( V_47 )
goto V_266;
if ( V_264 -> V_13 == V_267 )
V_2 -> V_13 = 1 ;
else
V_2 -> V_13 = 0 ;
if ( V_2 -> V_31 -> V_252 )
V_2 -> V_31 -> V_252 ( V_6 ) ;
V_266:
F_16 ( 1 ) ;
F_73 ( V_6 ) ;
F_101 ( & V_2 -> V_241 , V_265 ) ;
return V_47 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_265 ;
int V_47 ;
F_99 ( & V_2 -> V_241 , V_265 ) ;
V_47 = F_105 ( V_2 -> V_249 ) ;
F_101 ( & V_2 -> V_241 , V_265 ) ;
return V_47 ;
}
static T_1 F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return V_2 -> V_268 ;
}
static void F_107 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_268 = V_7 ;
}
static int F_108 ( struct V_5 * V_238 , int V_269 )
{
switch ( V_269 ) {
case V_270 :
return V_271 ;
default:
return - V_272 ;
}
}
static void F_109 ( struct V_5 * V_6 ,
struct V_273 * V_179 , T_5 * V_71 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 = 0 ;
V_71 [ V_20 ++ ] = V_2 -> V_105 ;
V_71 [ V_20 ++ ] = V_2 -> V_106 ;
V_71 [ V_20 ++ ] = V_2 -> V_107 ;
V_71 [ V_20 ++ ] = V_2 -> V_108 ;
}
static void F_110 ( struct V_5 * V_6 , T_1 V_274 , T_6 * V_71 )
{
switch ( V_274 ) {
case V_270 :
memcpy ( V_71 , * V_275 ,
sizeof( V_275 ) ) ;
break;
}
}
static void F_111 ( struct V_5 * V_6 ,
struct V_276 * V_277 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_277 -> V_278 = V_279 ;
V_277 -> V_280 = V_281 ;
V_277 -> V_282 = V_2 -> V_96 ;
V_277 -> V_283 = V_2 -> V_98 ;
}
static int F_112 ( struct V_5 * V_6 ,
struct V_276 * V_277 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_47 ;
if ( V_277 -> V_283 > V_281 ||
V_277 -> V_282 > V_279 ||
V_277 -> V_283 < V_284 ||
V_277 -> V_282 < V_285 )
return - V_286 ;
if ( V_277 -> V_287 || V_277 -> V_288 )
return - V_286 ;
if ( F_113 ( V_6 ) ) {
F_114 ( V_6 ) ;
F_5 ( V_6 , 0x0000 , V_136 ) ;
F_5 ( V_6 , 0 , V_235 ) ;
F_5 ( V_6 , 0 , V_174 ) ;
F_115 ( V_6 -> V_237 ) ;
}
F_45 ( V_6 ) ;
F_58 ( V_2 ) ;
V_2 -> V_96 = V_277 -> V_282 ;
V_2 -> V_98 = V_277 -> V_283 ;
V_47 = F_54 ( V_6 ) ;
if ( V_47 < 0 ) {
F_76 ( & V_6 -> V_111 , L_15 , V_289 ) ;
return V_47 ;
}
V_47 = F_59 ( V_6 , false ) ;
if ( V_47 < 0 ) {
F_76 ( & V_6 -> V_111 , L_16 , V_289 ) ;
return V_47 ;
}
if ( F_113 ( V_6 ) ) {
F_5 ( V_6 , V_2 -> V_31 -> V_157 , V_136 ) ;
F_5 ( V_6 , V_173 , V_174 ) ;
F_78 ( V_6 ) ;
}
return 0 ;
}
static int F_116 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_117 ( & V_2 -> V_290 -> V_111 ) ;
V_47 = F_118 ( V_6 -> V_237 , F_79 ,
V_2 -> V_31 -> V_291 , V_6 -> V_260 , V_6 ) ;
if ( V_47 ) {
F_76 ( & V_6 -> V_111 , L_17 ) ;
return V_47 ;
}
V_47 = F_54 ( V_6 ) ;
if ( V_47 )
goto V_292;
V_47 = F_59 ( V_6 , true ) ;
if ( V_47 )
goto V_292;
V_47 = F_95 ( V_6 ) ;
if ( V_47 )
goto V_292;
F_119 ( & V_2 -> V_245 ) ;
return V_47 ;
V_292:
F_120 ( V_6 -> V_237 , V_6 ) ;
F_121 ( & V_2 -> V_290 -> V_111 ) ;
return V_47 ;
}
static void F_122 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_99 * V_100 ;
int V_20 ;
F_123 ( V_6 ) ;
if ( F_124 ( V_2 ) )
F_76 ( & V_6 -> V_111 , L_18
L_19 , V_6 -> V_260 , ( int ) F_7 ( V_6 , V_156 ) ) ;
V_6 -> V_179 . V_293 ++ ;
for ( V_20 = 0 ; V_20 < V_2 -> V_96 ; V_20 ++ ) {
V_100 = & V_2 -> V_109 [ V_20 ] ;
V_100 -> V_113 = 0 ;
V_100 -> V_83 = 0xBADF00D0 ;
if ( V_2 -> V_95 [ V_20 ] )
F_46 ( V_2 -> V_95 [ V_20 ] ) ;
V_2 -> V_95 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_2 -> V_98 ; V_20 ++ ) {
if ( V_2 -> V_97 [ V_20 ] )
F_46 ( V_2 -> V_97 [ V_20 ] ) ;
V_2 -> V_97 [ V_20 ] = NULL ;
}
F_59 ( V_6 , true ) ;
}
static int F_125 ( struct V_67 * V_68 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_101 * V_102 ;
T_1 V_176 ;
unsigned long V_265 ;
F_99 ( & V_2 -> V_241 , V_265 ) ;
if ( ( V_2 -> V_106 - V_2 -> V_108 ) >= ( V_2 -> V_98 - 4 ) ) {
if ( ! F_62 ( V_6 ) ) {
if ( F_126 ( V_2 ) )
F_83 ( & V_6 -> V_111 , L_20 ) ;
F_123 ( V_6 ) ;
F_101 ( & V_2 -> V_241 , V_265 ) ;
return V_294 ;
}
}
F_101 ( & V_2 -> V_241 , V_265 ) ;
V_176 = V_2 -> V_106 % V_2 -> V_98 ;
V_2 -> V_97 [ V_176 ] = V_68 ;
V_102 = & V_2 -> V_119 [ V_176 ] ;
if ( ! V_2 -> V_31 -> V_138 )
F_66 ( F_67 ( F_53 ( V_102 -> V_83 , 4 ) ) ,
V_68 -> V_295 + 2 ) ;
V_102 -> V_83 = F_50 ( & V_6 -> V_111 , V_68 -> V_71 , V_68 -> V_295 ,
V_178 ) ;
if ( V_68 -> V_295 < V_296 )
V_102 -> V_116 = V_296 ;
else
V_102 -> V_116 = V_68 -> V_295 ;
if ( V_176 >= V_2 -> V_98 - 1 )
V_102 -> V_113 |= F_28 ( V_2 , V_177 | V_122 ) ;
else
V_102 -> V_113 |= F_28 ( V_2 , V_177 ) ;
V_2 -> V_106 ++ ;
if ( ! ( F_7 ( V_6 , V_235 ) & F_36 ( V_2 ) ) )
F_5 ( V_6 , F_36 ( V_2 ) , V_235 ) ;
return V_297 ;
}
static int F_127 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_128 ( & V_2 -> V_245 ) ;
F_123 ( V_6 ) ;
F_5 ( V_6 , 0x0000 , V_136 ) ;
F_5 ( V_6 , 0 , V_235 ) ;
F_5 ( V_6 , 0 , V_174 ) ;
if ( V_2 -> V_249 ) {
F_129 ( V_2 -> V_249 ) ;
F_130 ( V_2 -> V_249 ) ;
}
F_120 ( V_6 -> V_237 , V_6 ) ;
F_45 ( V_6 ) ;
F_58 ( V_2 ) ;
F_121 ( & V_2 -> V_290 -> V_111 ) ;
return 0 ;
}
static struct V_298 * F_131 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_117 ( & V_2 -> V_290 -> V_111 ) ;
V_6 -> V_179 . V_299 += F_7 ( V_6 , V_300 ) ;
F_5 ( V_6 , 0 , V_300 ) ;
V_6 -> V_179 . V_301 += F_7 ( V_6 , V_302 ) ;
F_5 ( V_6 , 0 , V_302 ) ;
V_6 -> V_179 . V_213 += F_7 ( V_6 , V_303 ) ;
F_5 ( V_6 , 0 , V_303 ) ;
if ( F_1 ( V_2 ) ) {
V_6 -> V_179 . V_213 += F_7 ( V_6 , V_304 ) ;
F_5 ( V_6 , 0 , V_304 ) ;
V_6 -> V_179 . V_213 += F_7 ( V_6 , V_305 ) ;
F_5 ( V_6 , 0 , V_305 ) ;
} else {
V_6 -> V_179 . V_213 += F_7 ( V_6 , V_306 ) ;
F_5 ( V_6 , 0 , V_306 ) ;
}
F_121 ( & V_2 -> V_290 -> V_111 ) ;
return & V_6 -> V_179 ;
}
static int F_132 ( struct V_5 * V_6 , struct V_307 * V_308 ,
int V_309 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_248 * V_249 = V_2 -> V_249 ;
if ( ! F_113 ( V_6 ) )
return - V_286 ;
if ( ! V_249 )
return - V_310 ;
return F_133 ( V_249 , V_308 , V_309 ) ;
}
static void * F_134 ( struct V_1 * V_2 ,
int V_176 )
{
return F_135 ( V_2 , V_311 ) + ( V_176 / 8 * 4 ) ;
}
static T_1 F_136 ( int V_176 )
{
return 0x0f << ( 28 - ( ( V_176 % 8 ) * 4 ) ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , int V_176 )
{
return ( 0x08 >> ( V_2 -> V_312 << 1 ) ) << ( 28 - ( ( V_176 % 8 ) * 4 ) ) ;
}
static void F_138 ( struct V_5 * V_6 ,
int V_176 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_313 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_176 ) ;
V_313 = F_12 ( V_3 ) ;
F_15 ( V_313 | F_137 ( V_2 , V_176 ) , V_3 ) ;
}
static bool F_139 ( struct V_5 * V_6 ,
int V_176 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_314 , V_315 , V_313 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_176 ) ;
V_314 = F_136 ( V_176 ) ;
V_315 = F_137 ( V_2 , V_176 ) & ~ V_314 ;
V_313 = F_12 ( V_3 ) ;
F_15 ( V_313 & ~ V_314 , V_3 ) ;
return V_313 & V_315 ;
}
static int F_140 ( struct V_5 * V_6 )
{
int V_316 = V_317 * 100 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
while ( ( F_141 ( V_2 , V_318 ) & V_319 ) ) {
F_142 ( 10 ) ;
V_316 -- ;
if ( V_316 <= 0 ) {
F_76 ( & V_6 -> V_111 , L_21 , V_289 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_143 ( struct V_5 * V_6 , void * V_320 ,
const T_6 * V_83 )
{
T_1 V_133 ;
V_133 = V_83 [ 0 ] << 24 | V_83 [ 1 ] << 16 | V_83 [ 2 ] << 8 | V_83 [ 3 ] ;
F_15 ( V_133 , V_320 ) ;
if ( F_140 ( V_6 ) < 0 )
return - V_321 ;
V_133 = V_83 [ 4 ] << 8 | V_83 [ 5 ] ;
F_15 ( V_133 , V_320 + 4 ) ;
if ( F_140 ( V_6 ) < 0 )
return - V_321 ;
return 0 ;
}
static void F_144 ( void * V_320 , T_6 * V_83 )
{
T_1 V_133 ;
V_133 = F_12 ( V_320 ) ;
V_83 [ 0 ] = ( V_133 >> 24 ) & 0xff ;
V_83 [ 1 ] = ( V_133 >> 16 ) & 0xff ;
V_83 [ 2 ] = ( V_133 >> 8 ) & 0xff ;
V_83 [ 3 ] = V_133 & 0xff ;
V_133 = F_12 ( V_320 + 4 ) ;
V_83 [ 4 ] = ( V_133 >> 8 ) & 0xff ;
V_83 [ 5 ] = V_133 & 0xff ;
}
static int F_145 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_135 ( V_2 , V_322 ) ;
int V_20 ;
T_6 V_323 [ V_324 ] ;
for ( V_20 = 0 ; V_20 < V_325 ; V_20 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_323 ) ;
if ( memcmp ( V_83 , V_323 , V_324 ) == 0 )
return V_20 ;
}
return - V_326 ;
}
static int F_146 ( struct V_5 * V_6 )
{
T_6 V_327 [ V_324 ] ;
int V_176 ;
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
V_176 = F_145 ( V_6 , V_327 ) ;
return ( V_176 < 0 ) ? - V_128 : V_176 ;
}
static int F_147 ( struct V_5 * V_6 ,
int V_176 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_135 ( V_2 , V_322 ) ;
int V_47 ;
T_6 V_327 [ V_324 ] ;
F_19 ( V_2 , F_141 ( V_2 , V_328 ) &
~ ( 1 << ( 31 - V_176 ) ) , V_328 ) ;
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
V_47 = F_143 ( V_6 , V_3 + V_176 * 8 , V_327 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_148 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_135 ( V_2 , V_322 ) ;
int V_20 , V_47 ;
if ( ! V_2 -> V_31 -> V_329 )
return 0 ;
V_20 = F_145 ( V_6 , V_83 ) ;
if ( V_20 < 0 ) {
V_20 = F_146 ( V_6 ) ;
if ( V_20 < 0 )
return - V_128 ;
V_47 = F_143 ( V_6 , V_3 + V_20 * 8 , V_83 ) ;
if ( V_47 < 0 )
return V_47 ;
F_19 ( V_2 , F_141 ( V_2 , V_328 ) |
( 1 << ( 31 - V_20 ) ) , V_328 ) ;
}
F_138 ( V_6 , V_20 ) ;
return 0 ;
}
static int F_149 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 , V_47 ;
if ( ! V_2 -> V_31 -> V_329 )
return 0 ;
V_20 = F_145 ( V_6 , V_83 ) ;
if ( V_20 ) {
if ( F_139 ( V_6 , V_20 ) )
goto V_330;
V_47 = F_147 ( V_6 , V_20 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_330:
return 0 ;
}
static int F_150 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 , V_47 ;
if ( F_151 ( ! V_2 -> V_31 -> V_329 ) )
return 0 ;
for ( V_20 = 0 ; V_20 < V_325 ; V_20 ++ ) {
if ( F_139 ( V_6 , V_20 ) )
continue;
V_47 = F_147 ( V_6 , V_20 ) ;
if ( V_47 < 0 )
return V_47 ;
}
return 0 ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_6 V_83 [ V_324 ] ;
void * V_3 = F_135 ( V_2 , V_322 ) ;
int V_20 ;
if ( F_151 ( ! V_2 -> V_31 -> V_329 ) )
return;
for ( V_20 = 0 ; V_20 < V_325 ; V_20 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_83 ) ;
if ( F_153 ( V_83 ) )
F_149 ( V_6 , V_83 ) ;
}
}
static void F_154 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_331 ;
int V_332 = 0 ;
unsigned long V_265 ;
F_99 ( & V_2 -> V_241 , V_265 ) ;
V_331 = ( F_7 ( V_6 , V_14 ) & ~ V_333 ) | V_334 ;
if ( ! ( V_6 -> V_265 & V_335 ) ) {
F_152 ( V_6 ) ;
V_332 = 1 ;
}
if ( V_6 -> V_265 & V_336 ) {
F_152 ( V_6 ) ;
V_331 &= ~ V_334 ;
V_332 = 1 ;
}
if ( V_6 -> V_265 & V_337 ) {
F_150 ( V_6 ) ;
V_331 = ( V_331 & ~ V_334 ) | V_333 ;
} else if ( V_2 -> V_31 -> V_329 ) {
struct V_338 * V_339 ;
F_155 (ha, ndev) {
if ( V_332 && F_153 ( V_339 -> V_83 ) )
continue;
if ( F_148 ( V_6 , V_339 -> V_83 ) < 0 ) {
if ( ! V_332 ) {
F_152 ( V_6 ) ;
V_331 &= ~ V_334 ;
V_332 = 1 ;
}
}
}
} else {
V_331 = ( V_331 & ~ V_333 ) | V_334 ;
}
F_5 ( V_6 , V_331 , V_14 ) ;
F_101 ( & V_2 -> V_241 , V_265 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_312 )
return V_340 ;
else
return V_341 ;
}
static int F_157 ( struct V_5 * V_6 ,
T_7 V_342 , T_3 V_343 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_344 = F_156 ( V_2 ) ;
if ( F_151 ( ! V_2 -> V_31 -> V_329 ) )
return - V_345 ;
if ( ! V_343 )
return 0 ;
V_2 -> V_346 ++ ;
if ( V_2 -> V_346 > 1 ) {
F_19 ( V_2 , 0 , V_344 ) ;
return 0 ;
}
F_19 ( V_2 , V_347 | ( V_343 & V_348 ) ,
V_344 ) ;
return 0 ;
}
static int F_158 ( struct V_5 * V_6 ,
T_7 V_342 , T_3 V_343 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_344 = F_156 ( V_2 ) ;
if ( F_151 ( ! V_2 -> V_31 -> V_329 ) )
return - V_345 ;
if ( ! V_343 )
return 0 ;
V_2 -> V_346 -- ;
F_19 ( V_2 , 0 , V_344 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_19 ( V_2 , 0 , V_349 ) ;
F_19 ( V_2 , 0 , V_350 ) ;
F_19 ( V_2 , 0 , V_351 ) ;
F_19 ( V_2 , 0xc , V_352 ) ;
F_19 ( V_2 , 0xc , V_353 ) ;
F_19 ( V_2 , 0 , V_354 ) ;
F_19 ( V_2 , 0 , V_355 ) ;
F_19 ( V_2 , 0 , V_356 ) ;
F_19 ( V_2 , 0 , V_357 ) ;
F_19 ( V_2 , V_358 | V_359 , V_360 ) ;
if ( F_1 ( V_2 ) ) {
F_19 ( V_2 , 0 , V_361 ) ;
F_19 ( V_2 , 0 , V_362 ) ;
} else {
F_19 ( V_2 , 0 , V_363 ) ;
F_19 ( V_2 , 0 , V_364 ) ;
}
F_19 ( V_2 , 0 , V_365 ) ;
F_19 ( V_2 , 0 , V_366 ) ;
F_19 ( V_2 , 0 , V_328 ) ;
F_19 ( V_2 , 0 , V_311 ) ;
F_19 ( V_2 , 0 , V_367 ) ;
F_19 ( V_2 , 0 , V_368 ) ;
F_19 ( V_2 , 0 , V_369 ) ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_257 * V_370 = F_161 ( & V_6 -> V_111 ) ;
F_162 ( V_370 ) ;
F_163 ( & V_6 -> V_111 , NULL ) ;
F_164 ( V_370 ) ;
return 0 ;
}
static int F_165 ( struct V_5 * V_6 , int V_258 ,
struct V_371 * V_372 )
{
int V_47 , V_20 ;
struct V_88 * V_89 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_89 = F_166 ( & V_6 -> V_111 , sizeof( struct V_88 ) ,
V_127 ) ;
if ( ! V_89 ) {
V_47 = - V_128 ;
goto V_54;
}
V_89 -> V_83 = V_2 -> V_83 + V_2 -> V_3 [ V_373 ] ;
V_89 -> V_90 = V_372 -> V_374 ;
V_89 -> V_93 = V_375 ;
V_89 -> V_92 = V_376 ;
V_89 -> V_91 = V_377 ;
V_89 -> V_94 = V_378 ;
V_89 -> V_86 . V_379 = & V_380 ;
V_2 -> V_257 = F_167 ( & V_89 -> V_86 ) ;
if ( ! V_2 -> V_257 ) {
V_47 = - V_128 ;
goto V_54;
}
V_2 -> V_257 -> V_260 = L_22 ;
V_2 -> V_257 -> V_381 = & V_6 -> V_111 ;
snprintf ( V_2 -> V_257 -> V_258 , V_255 , L_23 ,
V_2 -> V_290 -> V_260 , V_258 ) ;
V_2 -> V_257 -> V_237 = F_166 ( & V_6 -> V_111 ,
sizeof( int ) * V_382 ,
V_127 ) ;
if ( ! V_2 -> V_257 -> V_237 ) {
V_47 = - V_128 ;
goto V_383;
}
for ( V_20 = 0 ; V_20 < V_382 ; V_20 ++ )
V_2 -> V_257 -> V_237 [ V_20 ] = V_384 ;
V_47 = F_168 ( V_2 -> V_257 ) ;
if ( V_47 )
goto V_383;
F_163 ( & V_6 -> V_111 , V_2 -> V_257 ) ;
return 0 ;
V_383:
F_164 ( V_2 -> V_257 ) ;
V_54:
return V_47 ;
}
static const T_3 * F_169 ( int V_385 )
{
const T_3 * V_3 = NULL ;
switch ( V_385 ) {
case V_386 :
V_3 = V_4 ;
break;
case V_387 :
V_3 = V_388 ;
break;
case V_389 :
V_3 = V_390 ;
break;
case V_391 :
V_3 = V_392 ;
break;
default:
F_24 ( L_24 , V_385 ) ;
break;
}
return V_3 ;
}
static int F_170 ( struct V_393 * V_290 )
{
int V_47 , V_394 = 0 ;
struct V_395 * V_396 ;
struct V_5 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_371 * V_372 = V_290 -> V_111 . V_397 ;
const struct V_398 * V_258 = F_171 ( V_290 ) ;
V_396 = F_172 ( V_290 , V_399 , 0 ) ;
if ( F_151 ( V_396 == NULL ) ) {
F_76 ( & V_290 -> V_111 , L_25 ) ;
V_47 = - V_286 ;
goto V_54;
}
V_6 = F_173 ( sizeof( struct V_1 ) ) ;
if ( ! V_6 ) {
V_47 = - V_128 ;
goto V_54;
}
V_6 -> V_400 = V_396 -> V_132 ;
V_394 = V_290 -> V_258 ;
if ( V_394 < 0 )
V_394 = 0 ;
V_6 -> V_401 = - 1 ;
V_47 = F_174 ( V_290 , 0 ) ;
if ( V_47 < 0 ) {
V_47 = - V_310 ;
goto V_402;
}
V_6 -> V_237 = V_47 ;
F_175 ( V_6 , & V_290 -> V_111 ) ;
F_176 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
V_2 -> V_98 = V_403 ;
V_2 -> V_96 = V_404 ;
V_2 -> V_83 = F_177 ( & V_290 -> V_111 , V_396 ) ;
if ( F_92 ( V_2 -> V_83 ) ) {
V_47 = F_93 ( V_2 -> V_83 ) ;
goto V_402;
}
F_178 ( & V_2 -> V_241 ) ;
V_2 -> V_290 = V_290 ;
F_179 ( & V_290 -> V_111 ) ;
F_180 ( & V_290 -> V_111 ) ;
V_2 -> V_254 = V_372 -> V_405 ;
V_2 -> V_8 = V_372 -> V_8 ;
V_2 -> V_74 = V_372 -> V_74 ;
V_2 -> V_216 = V_372 -> V_216 ;
V_2 -> V_219 = V_372 -> V_219 ;
V_2 -> V_3 = F_169 ( V_372 -> V_385 ) ;
V_2 -> V_31 = (struct V_30 * ) V_258 -> V_406 ;
F_22 ( V_2 -> V_31 ) ;
if ( V_2 -> V_31 -> V_329 )
V_6 -> V_407 = & V_408 ;
else
V_6 -> V_407 = & V_409 ;
F_181 ( V_6 , & V_410 ) ;
V_6 -> V_411 = V_412 ;
V_2 -> V_268 = V_413 ;
F_35 ( V_6 , V_372 -> V_414 ) ;
if ( ! F_182 ( V_6 -> V_77 ) ) {
F_83 ( & V_290 -> V_111 ,
L_26 ) ;
F_183 ( V_6 ) ;
}
if ( V_2 -> V_31 -> V_329 ) {
struct V_395 * V_415 ;
V_415 = F_172 ( V_290 , V_399 , 1 ) ;
V_2 -> V_416 = F_177 ( & V_290 -> V_111 , V_415 ) ;
if ( F_92 ( V_2 -> V_416 ) ) {
V_47 = F_93 ( V_2 -> V_416 ) ;
goto V_402;
}
V_2 -> V_312 = V_394 % 2 ;
V_6 -> V_417 = V_418 ;
}
if ( ! V_394 || V_372 -> V_419 ) {
if ( V_2 -> V_31 -> V_420 )
V_2 -> V_31 -> V_420 ( V_6 ) ;
if ( V_2 -> V_31 -> V_329 ) {
F_159 ( V_2 ) ;
}
}
F_184 ( V_6 , & V_2 -> V_245 , F_85 , 64 ) ;
V_47 = F_185 ( V_6 ) ;
if ( V_47 )
goto V_421;
V_47 = F_165 ( V_6 , V_290 -> V_258 , V_372 ) ;
if ( V_47 )
goto V_422;
F_186 ( L_27 ,
( T_1 ) V_6 -> V_400 , V_6 -> V_77 , V_6 -> V_237 ) ;
F_187 ( V_290 , V_6 ) ;
return V_47 ;
V_422:
F_188 ( V_6 ) ;
V_421:
F_189 ( & V_2 -> V_245 ) ;
V_402:
if ( V_6 )
F_190 ( V_6 ) ;
V_54:
return V_47 ;
}
static int F_191 ( struct V_393 * V_290 )
{
struct V_5 * V_6 = F_192 ( V_290 ) ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_160 ( V_6 ) ;
F_188 ( V_6 ) ;
F_189 ( & V_2 -> V_245 ) ;
F_193 ( & V_290 -> V_111 ) ;
F_190 ( V_6 ) ;
return 0 ;
}
static int F_194 ( struct V_423 * V_111 )
{
return 0 ;
}
