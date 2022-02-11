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
if ( V_2 -> V_31 -> V_134 )
F_5 ( V_6 , 0x1 , V_135 ) ;
F_48 ( V_6 ) ;
if ( V_2 -> V_31 -> V_125 )
F_5 ( V_6 , V_2 -> V_31 -> V_136 , V_137 ) ;
F_5 ( V_6 , 0 , V_138 ) ;
#if F_60 ( V_139 )
if ( V_2 -> V_31 -> V_140 )
F_5 ( V_6 , V_141 , V_49 ) ;
else
#endif
F_5 ( V_6 , 0 , V_49 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_39 , V_142 ) ;
F_5 ( V_6 , 0 , V_143 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_41 , V_144 ) ;
F_5 ( V_6 , V_145 | V_146 | V_147 , V_148 ) ;
if ( V_2 -> V_31 -> V_149 )
F_5 ( V_6 , 0x800 , V_150 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_36 , V_151 ) ;
if ( ! V_2 -> V_31 -> V_152 )
F_5 ( V_6 , 0 , V_153 ) ;
F_5 ( V_6 , V_6 -> V_123 + V_154 + V_155 + V_156 ,
V_157 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_158 ) , V_158 ) ;
if ( V_132 )
F_5 ( V_6 , V_2 -> V_31 -> V_159 , V_138 ) ;
V_133 = ( F_7 ( V_6 , V_14 ) & V_15 ) |
V_160 | ( V_2 -> V_13 ? V_15 : 0 ) | V_161 | V_162 ;
F_5 ( V_6 , V_133 , V_14 ) ;
if ( V_2 -> V_31 -> V_163 )
V_2 -> V_31 -> V_163 ( V_6 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_32 , V_164 ) ;
if ( V_132 )
F_5 ( V_6 , V_2 -> V_31 -> V_34 , V_165 ) ;
F_34 ( V_6 ) ;
if ( V_2 -> V_31 -> V_166 )
F_5 ( V_6 , V_167 , V_168 ) ;
if ( V_2 -> V_31 -> V_169 )
F_5 ( V_6 , V_170 , V_171 ) ;
if ( V_2 -> V_31 -> V_172 )
F_5 ( V_6 , V_173 , V_174 ) ;
if ( V_132 ) {
F_5 ( V_6 , V_175 , V_176 ) ;
F_61 ( V_6 ) ;
}
V_54:
return V_47 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_101 * V_102 ;
int V_177 = 0 ;
int V_178 = 0 ;
for (; V_2 -> V_106 - V_2 -> V_108 > 0 ; V_2 -> V_108 ++ ) {
V_178 = V_2 -> V_108 % V_2 -> V_98 ;
V_102 = & V_2 -> V_119 [ V_178 ] ;
if ( V_102 -> V_113 & F_28 ( V_2 , V_179 ) )
break;
if ( V_2 -> V_97 [ V_178 ] ) {
F_63 ( & V_6 -> V_111 , V_102 -> V_83 ,
V_102 -> V_116 , V_180 ) ;
F_64 ( V_2 -> V_97 [ V_178 ] ) ;
V_2 -> V_97 [ V_178 ] = NULL ;
V_177 ++ ;
}
V_102 -> V_113 = F_28 ( V_2 , V_120 ) ;
if ( V_178 >= V_2 -> V_98 - 1 )
V_102 -> V_113 |= F_28 ( V_2 , V_122 ) ;
V_6 -> V_181 . V_182 ++ ;
V_6 -> V_181 . V_183 += V_102 -> V_116 ;
}
return V_177 ;
}
static int F_65 ( struct V_5 * V_6 , T_1 V_184 , int * V_185 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_99 * V_100 ;
int V_178 = V_2 -> V_105 % V_2 -> V_96 ;
int V_186 = ( V_2 -> V_107 + V_2 -> V_96 ) - V_2 -> V_105 ;
struct V_67 * V_68 ;
int V_187 = 0 ;
T_3 V_188 = 0 ;
T_1 V_189 ;
V_100 = & V_2 -> V_109 [ V_178 ] ;
while ( ! ( V_100 -> V_113 & F_28 ( V_2 , V_114 ) ) ) {
V_189 = F_31 ( V_2 , V_100 -> V_113 ) ;
V_188 = V_100 -> V_190 ;
if ( -- V_186 < 0 )
break;
if ( * V_185 <= 0 ) {
V_187 = 1 ;
break;
}
( * V_185 ) -- ;
if ( ! ( V_189 & V_191 ) )
V_6 -> V_181 . V_192 ++ ;
if ( V_2 -> V_31 -> V_193 )
V_189 >>= 16 ;
if ( V_189 & ( V_194 | V_195 | V_196 | V_197 |
V_198 | V_199 | V_200 ) ) {
V_6 -> V_181 . V_201 ++ ;
if ( V_189 & V_194 )
V_6 -> V_181 . V_202 ++ ;
if ( V_189 & V_195 )
V_6 -> V_181 . V_203 ++ ;
if ( V_189 & V_196 )
V_6 -> V_181 . V_192 ++ ;
if ( V_189 & V_197 )
V_6 -> V_181 . V_192 ++ ;
if ( V_189 & V_199 )
V_6 -> V_181 . V_204 ++ ;
if ( V_189 & V_200 )
V_6 -> V_181 . V_205 ++ ;
} else {
if ( ! V_2 -> V_31 -> V_140 )
F_66 (
F_67 ( F_53 ( V_100 -> V_83 , 4 ) ) ,
V_188 + 2 ) ;
V_68 = V_2 -> V_95 [ V_178 ] ;
V_2 -> V_95 [ V_178 ] = NULL ;
if ( V_2 -> V_31 -> V_125 )
F_27 ( V_68 , V_126 ) ;
F_68 ( & V_6 -> V_111 , V_100 -> V_83 ,
V_2 -> V_110 ,
V_112 ) ;
F_69 ( V_68 , V_188 ) ;
V_68 -> V_206 = F_70 ( V_68 , V_6 ) ;
F_71 ( V_68 ) ;
V_6 -> V_181 . V_207 ++ ;
V_6 -> V_181 . V_208 += V_188 ;
}
V_100 -> V_113 |= F_28 ( V_2 , V_114 ) ;
V_178 = ( ++ V_2 -> V_105 ) % V_2 -> V_96 ;
V_100 = & V_2 -> V_109 [ V_178 ] ;
}
for (; V_2 -> V_105 - V_2 -> V_107 > 0 ; V_2 -> V_107 ++ ) {
V_178 = V_2 -> V_107 % V_2 -> V_96 ;
V_100 = & V_2 -> V_109 [ V_178 ] ;
V_100 -> V_116 = F_53 ( V_2 -> V_110 , 16 ) ;
if ( V_2 -> V_95 [ V_178 ] == NULL ) {
V_68 = F_49 ( V_6 , V_2 -> V_110 ) ;
V_2 -> V_95 [ V_178 ] = V_68 ;
if ( V_68 == NULL )
break;
F_50 ( & V_6 -> V_111 , V_68 -> V_71 , V_2 -> V_110 ,
V_112 ) ;
F_26 ( V_68 ) ;
F_72 ( V_68 ) ;
V_100 -> V_83 = F_51 ( F_52 ( V_68 -> V_71 , 4 ) ) ;
}
if ( V_178 >= V_2 -> V_96 - 1 )
V_100 -> V_113 |=
F_28 ( V_2 , V_114 | V_115 | V_118 ) ;
else
V_100 -> V_113 |=
F_28 ( V_2 , V_114 | V_115 ) ;
}
if ( ! ( F_7 ( V_6 , V_176 ) & V_175 ) ) {
if ( V_184 & V_209 )
V_2 -> V_105 = V_2 -> V_107 =
( F_7 ( V_6 , V_60 ) -
F_7 ( V_6 , V_59 ) ) >> 4 ;
F_5 ( V_6 , V_175 , V_176 ) ;
}
return V_187 ;
}
static void F_73 ( struct V_5 * V_6 )
{
F_5 ( V_6 , F_7 ( V_6 , V_14 ) &
~ ( V_162 | V_161 ) , V_14 ) ;
}
static void F_74 ( struct V_5 * V_6 )
{
F_5 ( V_6 , F_7 ( V_6 , V_14 ) |
( V_162 | V_161 ) , V_14 ) ;
}
static void F_75 ( struct V_5 * V_6 , int V_184 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_210 ;
T_1 V_211 ;
T_1 V_212 ;
if ( V_184 & V_213 ) {
V_210 = F_7 ( V_6 , V_164 ) ;
F_5 ( V_6 , V_210 , V_164 ) ;
if ( V_210 & V_214 )
V_6 -> V_181 . V_215 ++ ;
if ( V_210 & V_216 ) {
if ( V_2 -> V_31 -> V_217 || V_2 -> V_218 ) {
goto V_219;
} else {
V_211 = ( F_7 ( V_6 , V_220 ) ) ;
if ( V_2 -> V_221 )
V_211 = ~ V_211 ;
}
if ( ! ( V_211 & V_222 ) )
F_73 ( V_6 ) ;
else {
F_5 ( V_6 , F_7 ( V_6 , V_138 ) &
~ V_223 , V_138 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_164 ) ,
V_164 ) ;
F_5 ( V_6 , F_7 ( V_6 , V_138 ) |
V_223 , V_138 ) ;
F_74 ( V_6 ) ;
}
}
}
V_219:
if ( V_184 & V_224 ) {
if ( V_184 & V_225 ) {
V_6 -> V_181 . V_226 ++ ;
if ( F_76 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_3 ) ;
}
}
if ( V_184 & V_227 ) {
if ( V_184 & V_228 ) {
V_6 -> V_181 . V_203 ++ ;
if ( F_78 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_4 ) ;
}
}
if ( V_184 & V_229 ) {
V_6 -> V_181 . V_230 ++ ;
if ( F_76 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_5 ) ;
}
if ( V_184 & V_231 ) {
V_6 -> V_181 . V_230 ++ ;
if ( F_76 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_6 ) ;
}
if ( V_184 & V_209 ) {
V_6 -> V_181 . V_205 ++ ;
if ( F_78 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_7 ) ;
}
if ( V_184 & V_232 ) {
V_6 -> V_181 . V_233 ++ ;
if ( F_78 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_8 ) ;
}
if ( ! V_2 -> V_31 -> V_234 && ( V_184 & V_235 ) ) {
V_6 -> V_181 . V_230 ++ ;
if ( F_76 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_9 ) ;
}
V_212 = V_224 | V_225 | V_235 | V_229 | V_231 ;
if ( V_2 -> V_31 -> V_234 )
V_212 &= ~ V_235 ;
if ( V_184 & V_212 ) {
T_1 V_236 = F_7 ( V_6 , V_237 ) ;
F_77 ( & V_6 -> V_111 , L_10 ,
V_184 , V_2 -> V_106 ) ;
F_77 ( & V_6 -> V_111 , L_11 ,
V_2 -> V_108 , ( T_1 ) V_6 -> V_238 , V_236 ) ;
F_62 ( V_6 ) ;
if ( V_236 ^ F_36 ( V_2 ) ) {
F_5 ( V_6 , F_36 ( V_2 ) , V_237 ) ;
}
F_79 ( V_6 ) ;
}
}
static T_4 F_80 ( int V_239 , void * V_240 )
{
struct V_5 * V_6 = V_240 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
T_4 V_47 = V_241 ;
unsigned long V_184 , V_242 ;
F_81 ( & V_2 -> V_243 ) ;
V_184 = F_7 ( V_6 , V_158 ) ;
V_242 = F_7 ( V_6 , V_138 ) ;
V_184 &= V_242 | V_223 ;
if ( V_184 & ( V_244 | V_31 -> V_43 | V_31 -> V_45 ) )
V_47 = V_245 ;
else
goto V_246;
if ( V_184 & V_244 ) {
if ( F_82 ( & V_2 -> V_247 ) ) {
F_5 ( V_6 , V_242 & ~ V_244 ,
V_138 ) ;
F_83 ( & V_2 -> V_247 ) ;
} else {
F_84 ( & V_6 -> V_111 ,
L_12 ,
V_184 , V_242 ) ;
}
}
if ( V_184 & V_31 -> V_43 ) {
F_5 ( V_6 , V_184 & V_31 -> V_43 , V_158 ) ;
F_62 ( V_6 ) ;
F_79 ( V_6 ) ;
}
if ( V_184 & V_31 -> V_45 ) {
F_5 ( V_6 , V_184 & V_31 -> V_45 , V_158 ) ;
F_75 ( V_6 , V_184 ) ;
}
V_246:
F_85 ( & V_2 -> V_243 ) ;
return V_47 ;
}
static int F_86 ( struct V_248 * V_247 , int V_249 )
{
struct V_1 * V_2 = F_41 ( V_247 , struct V_1 ,
V_247 ) ;
struct V_5 * V_6 = V_247 -> V_111 ;
int V_185 = V_249 ;
unsigned long V_184 ;
for (; ; ) {
V_184 = F_7 ( V_6 , V_158 ) ;
if ( ! ( V_184 & V_244 ) )
break;
F_5 ( V_6 , V_184 & V_244 , V_158 ) ;
if ( F_65 ( V_6 , V_184 , & V_185 ) )
goto V_54;
}
F_87 ( V_247 ) ;
F_5 ( V_6 , V_2 -> V_31 -> V_159 , V_138 ) ;
V_54:
return V_249 - V_185 ;
}
static void F_88 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_250 * V_251 = V_2 -> V_251 ;
int V_252 = 0 ;
if ( V_251 -> V_253 ) {
if ( V_251 -> V_13 != V_2 -> V_13 ) {
V_252 = 1 ;
V_2 -> V_13 = V_251 -> V_13 ;
if ( V_2 -> V_31 -> V_254 )
V_2 -> V_31 -> V_254 ( V_6 ) ;
}
if ( V_251 -> V_16 != V_2 -> V_16 ) {
V_252 = 1 ;
V_2 -> V_16 = V_251 -> V_16 ;
if ( V_2 -> V_31 -> V_163 )
V_2 -> V_31 -> V_163 ( V_6 ) ;
}
if ( ! V_2 -> V_253 ) {
F_5 ( V_6 ,
( F_7 ( V_6 , V_14 ) & ~ V_255 ) , V_14 ) ;
V_252 = 1 ;
V_2 -> V_253 = V_251 -> V_253 ;
if ( V_2 -> V_31 -> V_217 || V_2 -> V_218 )
F_74 ( V_6 ) ;
}
} else if ( V_2 -> V_253 ) {
V_252 = 1 ;
V_2 -> V_253 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_13 = - 1 ;
if ( V_2 -> V_31 -> V_217 || V_2 -> V_218 )
F_73 ( V_6 ) ;
}
if ( V_252 && F_89 ( V_2 ) )
F_90 ( V_251 ) ;
}
static int F_91 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
char V_256 [ V_257 + 3 ] ;
struct V_250 * V_251 = NULL ;
snprintf ( V_256 , sizeof( V_256 ) , V_258 ,
V_2 -> V_259 -> V_260 , V_2 -> V_256 ) ;
V_2 -> V_253 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_13 = - 1 ;
V_251 = F_92 ( V_6 , V_256 , F_88 ,
V_2 -> V_8 ) ;
if ( F_93 ( V_251 ) ) {
F_77 ( & V_6 -> V_111 , L_13 ) ;
return F_94 ( V_251 ) ;
}
F_95 ( & V_6 -> V_111 , L_14 ,
V_251 -> V_83 , V_251 -> V_261 -> V_262 ) ;
V_2 -> V_251 = V_251 ;
return 0 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_47 ;
V_47 = F_91 ( V_6 ) ;
if ( V_47 )
return V_47 ;
F_97 ( V_2 -> V_251 , V_263 , V_264 ) ;
F_98 ( V_2 -> V_251 ) ;
return 0 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_267 ;
int V_47 ;
F_100 ( & V_2 -> V_243 , V_267 ) ;
V_47 = F_101 ( V_2 -> V_251 , V_266 ) ;
F_102 ( & V_2 -> V_243 , V_267 ) ;
return V_47 ;
}
static int F_103 ( struct V_5 * V_6 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_267 ;
int V_47 ;
F_100 ( & V_2 -> V_243 , V_267 ) ;
F_73 ( V_6 ) ;
V_47 = F_104 ( V_2 -> V_251 , V_266 ) ;
if ( V_47 )
goto V_268;
if ( V_266 -> V_13 == V_269 )
V_2 -> V_13 = 1 ;
else
V_2 -> V_13 = 0 ;
if ( V_2 -> V_31 -> V_254 )
V_2 -> V_31 -> V_254 ( V_6 ) ;
V_268:
F_16 ( 1 ) ;
F_74 ( V_6 ) ;
F_102 ( & V_2 -> V_243 , V_267 ) ;
return V_47 ;
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned long V_267 ;
int V_47 ;
F_100 ( & V_2 -> V_243 , V_267 ) ;
V_47 = F_106 ( V_2 -> V_251 ) ;
F_102 ( & V_2 -> V_243 , V_267 ) ;
return V_47 ;
}
static T_1 F_107 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return V_2 -> V_270 ;
}
static void F_108 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_270 = V_7 ;
}
static int F_109 ( struct V_5 * V_240 , int V_271 )
{
switch ( V_271 ) {
case V_272 :
return V_273 ;
default:
return - V_274 ;
}
}
static void F_110 ( struct V_5 * V_6 ,
struct V_275 * V_181 , T_5 * V_71 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 = 0 ;
V_71 [ V_20 ++ ] = V_2 -> V_105 ;
V_71 [ V_20 ++ ] = V_2 -> V_106 ;
V_71 [ V_20 ++ ] = V_2 -> V_107 ;
V_71 [ V_20 ++ ] = V_2 -> V_108 ;
}
static void F_111 ( struct V_5 * V_6 , T_1 V_276 , T_6 * V_71 )
{
switch ( V_276 ) {
case V_272 :
memcpy ( V_71 , * V_277 ,
sizeof( V_277 ) ) ;
break;
}
}
static void F_112 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_279 -> V_280 = V_281 ;
V_279 -> V_282 = V_283 ;
V_279 -> V_284 = V_2 -> V_96 ;
V_279 -> V_285 = V_2 -> V_98 ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_47 ;
if ( V_279 -> V_285 > V_283 ||
V_279 -> V_284 > V_281 ||
V_279 -> V_285 < V_286 ||
V_279 -> V_284 < V_287 )
return - V_288 ;
if ( V_279 -> V_289 || V_279 -> V_290 )
return - V_288 ;
if ( F_114 ( V_6 ) ) {
F_115 ( V_6 ) ;
F_5 ( V_6 , 0x0000 , V_138 ) ;
F_5 ( V_6 , 0 , V_237 ) ;
F_5 ( V_6 , 0 , V_176 ) ;
F_116 ( V_6 -> V_239 ) ;
}
F_45 ( V_6 ) ;
F_58 ( V_2 ) ;
V_2 -> V_96 = V_279 -> V_284 ;
V_2 -> V_98 = V_279 -> V_285 ;
V_47 = F_54 ( V_6 ) ;
if ( V_47 < 0 ) {
F_77 ( & V_6 -> V_111 , L_15 , V_291 ) ;
return V_47 ;
}
V_47 = F_59 ( V_6 , false ) ;
if ( V_47 < 0 ) {
F_77 ( & V_6 -> V_111 , L_16 , V_291 ) ;
return V_47 ;
}
if ( F_114 ( V_6 ) ) {
F_5 ( V_6 , V_2 -> V_31 -> V_159 , V_138 ) ;
F_5 ( V_6 , V_175 , V_176 ) ;
F_79 ( V_6 ) ;
}
return 0 ;
}
static int F_117 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_118 ( & V_2 -> V_292 -> V_111 ) ;
F_119 ( & V_2 -> V_247 ) ;
V_47 = F_120 ( V_6 -> V_239 , F_80 ,
V_2 -> V_31 -> V_293 , V_6 -> V_262 , V_6 ) ;
if ( V_47 ) {
F_77 ( & V_6 -> V_111 , L_17 ) ;
goto V_294;
}
V_47 = F_54 ( V_6 ) ;
if ( V_47 )
goto V_295;
V_47 = F_59 ( V_6 , true ) ;
if ( V_47 )
goto V_295;
V_47 = F_96 ( V_6 ) ;
if ( V_47 )
goto V_295;
return V_47 ;
V_295:
F_121 ( V_6 -> V_239 , V_6 ) ;
V_294:
F_122 ( & V_2 -> V_247 ) ;
F_123 ( & V_2 -> V_292 -> V_111 ) ;
return V_47 ;
}
static void F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_99 * V_100 ;
int V_20 ;
F_125 ( V_6 ) ;
if ( F_126 ( V_2 ) )
F_77 ( & V_6 -> V_111 , L_18
L_19 , V_6 -> V_262 , ( int ) F_7 ( V_6 , V_158 ) ) ;
V_6 -> V_181 . V_296 ++ ;
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
static int F_127 ( struct V_67 * V_68 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_101 * V_102 ;
T_1 V_178 ;
unsigned long V_267 ;
F_100 ( & V_2 -> V_243 , V_267 ) ;
if ( ( V_2 -> V_106 - V_2 -> V_108 ) >= ( V_2 -> V_98 - 4 ) ) {
if ( ! F_62 ( V_6 ) ) {
if ( F_128 ( V_2 ) )
F_84 ( & V_6 -> V_111 , L_20 ) ;
F_125 ( V_6 ) ;
F_102 ( & V_2 -> V_243 , V_267 ) ;
return V_297 ;
}
}
F_102 ( & V_2 -> V_243 , V_267 ) ;
V_178 = V_2 -> V_106 % V_2 -> V_98 ;
V_2 -> V_97 [ V_178 ] = V_68 ;
V_102 = & V_2 -> V_119 [ V_178 ] ;
if ( ! V_2 -> V_31 -> V_140 )
F_66 ( F_67 ( F_53 ( V_102 -> V_83 , 4 ) ) ,
V_68 -> V_298 + 2 ) ;
V_102 -> V_83 = F_50 ( & V_6 -> V_111 , V_68 -> V_71 , V_68 -> V_298 ,
V_180 ) ;
if ( V_68 -> V_298 < V_299 )
V_102 -> V_116 = V_299 ;
else
V_102 -> V_116 = V_68 -> V_298 ;
if ( V_178 >= V_2 -> V_98 - 1 )
V_102 -> V_113 |= F_28 ( V_2 , V_179 | V_122 ) ;
else
V_102 -> V_113 |= F_28 ( V_2 , V_179 ) ;
V_2 -> V_106 ++ ;
if ( ! ( F_7 ( V_6 , V_237 ) & F_36 ( V_2 ) ) )
F_5 ( V_6 , F_36 ( V_2 ) , V_237 ) ;
return V_300 ;
}
static int F_129 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_125 ( V_6 ) ;
F_5 ( V_6 , 0x0000 , V_138 ) ;
F_5 ( V_6 , 0 , V_237 ) ;
F_5 ( V_6 , 0 , V_176 ) ;
if ( V_2 -> V_251 ) {
F_130 ( V_2 -> V_251 ) ;
F_131 ( V_2 -> V_251 ) ;
}
F_121 ( V_6 -> V_239 , V_6 ) ;
F_122 ( & V_2 -> V_247 ) ;
F_45 ( V_6 ) ;
F_58 ( V_2 ) ;
F_123 ( & V_2 -> V_292 -> V_111 ) ;
return 0 ;
}
static struct V_301 * F_132 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_118 ( & V_2 -> V_292 -> V_111 ) ;
V_6 -> V_181 . V_302 += F_7 ( V_6 , V_303 ) ;
F_5 ( V_6 , 0 , V_303 ) ;
V_6 -> V_181 . V_304 += F_7 ( V_6 , V_305 ) ;
F_5 ( V_6 , 0 , V_305 ) ;
V_6 -> V_181 . V_215 += F_7 ( V_6 , V_306 ) ;
F_5 ( V_6 , 0 , V_306 ) ;
if ( F_1 ( V_2 ) ) {
V_6 -> V_181 . V_215 += F_7 ( V_6 , V_307 ) ;
F_5 ( V_6 , 0 , V_307 ) ;
V_6 -> V_181 . V_215 += F_7 ( V_6 , V_308 ) ;
F_5 ( V_6 , 0 , V_308 ) ;
} else {
V_6 -> V_181 . V_215 += F_7 ( V_6 , V_309 ) ;
F_5 ( V_6 , 0 , V_309 ) ;
}
F_123 ( & V_2 -> V_292 -> V_111 ) ;
return & V_6 -> V_181 ;
}
static int F_133 ( struct V_5 * V_6 , struct V_310 * V_311 ,
int V_312 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_250 * V_251 = V_2 -> V_251 ;
if ( ! F_114 ( V_6 ) )
return - V_288 ;
if ( ! V_251 )
return - V_313 ;
return F_134 ( V_251 , V_311 , V_312 ) ;
}
static void * F_135 ( struct V_1 * V_2 ,
int V_178 )
{
return F_136 ( V_2 , V_314 ) + ( V_178 / 8 * 4 ) ;
}
static T_1 F_137 ( int V_178 )
{
return 0x0f << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static T_1 F_138 ( struct V_1 * V_2 , int V_178 )
{
return ( 0x08 >> ( V_2 -> V_315 << 1 ) ) << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static void F_139 ( struct V_5 * V_6 ,
int V_178 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_316 ;
void * V_3 ;
V_3 = F_135 ( V_2 , V_178 ) ;
V_316 = F_12 ( V_3 ) ;
F_15 ( V_316 | F_138 ( V_2 , V_178 ) , V_3 ) ;
}
static bool F_140 ( struct V_5 * V_6 ,
int V_178 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_317 , V_318 , V_316 ;
void * V_3 ;
V_3 = F_135 ( V_2 , V_178 ) ;
V_317 = F_137 ( V_178 ) ;
V_318 = F_138 ( V_2 , V_178 ) & ~ V_317 ;
V_316 = F_12 ( V_3 ) ;
F_15 ( V_316 & ~ V_317 , V_3 ) ;
return V_316 & V_318 ;
}
static int F_141 ( struct V_5 * V_6 )
{
int V_319 = V_320 * 100 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
while ( ( F_142 ( V_2 , V_321 ) & V_322 ) ) {
F_143 ( 10 ) ;
V_319 -- ;
if ( V_319 <= 0 ) {
F_77 ( & V_6 -> V_111 , L_21 , V_291 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_144 ( struct V_5 * V_6 , void * V_323 ,
const T_6 * V_83 )
{
T_1 V_133 ;
V_133 = V_83 [ 0 ] << 24 | V_83 [ 1 ] << 16 | V_83 [ 2 ] << 8 | V_83 [ 3 ] ;
F_15 ( V_133 , V_323 ) ;
if ( F_141 ( V_6 ) < 0 )
return - V_324 ;
V_133 = V_83 [ 4 ] << 8 | V_83 [ 5 ] ;
F_15 ( V_133 , V_323 + 4 ) ;
if ( F_141 ( V_6 ) < 0 )
return - V_324 ;
return 0 ;
}
static void F_145 ( void * V_323 , T_6 * V_83 )
{
T_1 V_133 ;
V_133 = F_12 ( V_323 ) ;
V_83 [ 0 ] = ( V_133 >> 24 ) & 0xff ;
V_83 [ 1 ] = ( V_133 >> 16 ) & 0xff ;
V_83 [ 2 ] = ( V_133 >> 8 ) & 0xff ;
V_83 [ 3 ] = V_133 & 0xff ;
V_133 = F_12 ( V_323 + 4 ) ;
V_83 [ 4 ] = ( V_133 >> 8 ) & 0xff ;
V_83 [ 5 ] = V_133 & 0xff ;
}
static int F_146 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_136 ( V_2 , V_325 ) ;
int V_20 ;
T_6 V_326 [ V_327 ] ;
for ( V_20 = 0 ; V_20 < V_328 ; V_20 ++ , V_3 += 8 ) {
F_145 ( V_3 , V_326 ) ;
if ( memcmp ( V_83 , V_326 , V_327 ) == 0 )
return V_20 ;
}
return - V_329 ;
}
static int F_147 ( struct V_5 * V_6 )
{
T_6 V_330 [ V_327 ] ;
int V_178 ;
memset ( V_330 , 0 , sizeof( V_330 ) ) ;
V_178 = F_146 ( V_6 , V_330 ) ;
return ( V_178 < 0 ) ? - V_128 : V_178 ;
}
static int F_148 ( struct V_5 * V_6 ,
int V_178 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_136 ( V_2 , V_325 ) ;
int V_47 ;
T_6 V_330 [ V_327 ] ;
F_19 ( V_2 , F_142 ( V_2 , V_331 ) &
~ ( 1 << ( 31 - V_178 ) ) , V_331 ) ;
memset ( V_330 , 0 , sizeof( V_330 ) ) ;
V_47 = F_144 ( V_6 , V_3 + V_178 * 8 , V_330 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_149 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
void * V_3 = F_136 ( V_2 , V_325 ) ;
int V_20 , V_47 ;
if ( ! V_2 -> V_31 -> V_332 )
return 0 ;
V_20 = F_146 ( V_6 , V_83 ) ;
if ( V_20 < 0 ) {
V_20 = F_147 ( V_6 ) ;
if ( V_20 < 0 )
return - V_128 ;
V_47 = F_144 ( V_6 , V_3 + V_20 * 8 , V_83 ) ;
if ( V_47 < 0 )
return V_47 ;
F_19 ( V_2 , F_142 ( V_2 , V_331 ) |
( 1 << ( 31 - V_20 ) ) , V_331 ) ;
}
F_139 ( V_6 , V_20 ) ;
return 0 ;
}
static int F_150 ( struct V_5 * V_6 , const T_6 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 , V_47 ;
if ( ! V_2 -> V_31 -> V_332 )
return 0 ;
V_20 = F_146 ( V_6 , V_83 ) ;
if ( V_20 ) {
if ( F_140 ( V_6 , V_20 ) )
goto V_333;
V_47 = F_148 ( V_6 , V_20 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_333:
return 0 ;
}
static int F_151 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_20 , V_47 ;
if ( F_152 ( ! V_2 -> V_31 -> V_332 ) )
return 0 ;
for ( V_20 = 0 ; V_20 < V_328 ; V_20 ++ ) {
if ( F_140 ( V_6 , V_20 ) )
continue;
V_47 = F_148 ( V_6 , V_20 ) ;
if ( V_47 < 0 )
return V_47 ;
}
return 0 ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_6 V_83 [ V_327 ] ;
void * V_3 = F_136 ( V_2 , V_325 ) ;
int V_20 ;
if ( F_152 ( ! V_2 -> V_31 -> V_332 ) )
return;
for ( V_20 = 0 ; V_20 < V_328 ; V_20 ++ , V_3 += 8 ) {
F_145 ( V_3 , V_83 ) ;
if ( F_154 ( V_83 ) )
F_150 ( V_6 , V_83 ) ;
}
}
static void F_155 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
T_1 V_334 ;
int V_335 = 0 ;
unsigned long V_267 ;
F_100 ( & V_2 -> V_243 , V_267 ) ;
V_334 = ( F_7 ( V_6 , V_14 ) & ~ V_336 ) | V_337 ;
if ( ! ( V_6 -> V_267 & V_338 ) ) {
F_153 ( V_6 ) ;
V_335 = 1 ;
}
if ( V_6 -> V_267 & V_339 ) {
F_153 ( V_6 ) ;
V_334 &= ~ V_337 ;
V_335 = 1 ;
}
if ( V_6 -> V_267 & V_340 ) {
F_151 ( V_6 ) ;
V_334 = ( V_334 & ~ V_337 ) | V_336 ;
} else if ( V_2 -> V_31 -> V_332 ) {
struct V_341 * V_342 ;
F_156 (ha, ndev) {
if ( V_335 && F_154 ( V_342 -> V_83 ) )
continue;
if ( F_149 ( V_6 , V_342 -> V_83 ) < 0 ) {
if ( ! V_335 ) {
F_153 ( V_6 ) ;
V_334 &= ~ V_337 ;
V_335 = 1 ;
}
}
}
} else {
V_334 = ( V_334 & ~ V_336 ) | V_337 ;
}
F_5 ( V_6 , V_334 , V_14 ) ;
F_102 ( & V_2 -> V_243 , V_267 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_315 )
return V_343 ;
else
return V_344 ;
}
static int F_158 ( struct V_5 * V_6 ,
T_7 V_345 , T_3 V_346 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_347 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_31 -> V_332 ) )
return - V_348 ;
if ( ! V_346 )
return 0 ;
V_2 -> V_349 ++ ;
if ( V_2 -> V_349 > 1 ) {
F_19 ( V_2 , 0 , V_347 ) ;
return 0 ;
}
F_19 ( V_2 , V_350 | ( V_346 & V_351 ) ,
V_347 ) ;
return 0 ;
}
static int F_159 ( struct V_5 * V_6 ,
T_7 V_345 , T_3 V_346 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_347 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_31 -> V_332 ) )
return - V_348 ;
if ( ! V_346 )
return 0 ;
V_2 -> V_349 -- ;
F_19 ( V_2 , 0 , V_347 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_19 ( V_2 , 0 , V_352 ) ;
F_19 ( V_2 , 0 , V_353 ) ;
F_19 ( V_2 , 0 , V_354 ) ;
F_19 ( V_2 , 0xc , V_355 ) ;
F_19 ( V_2 , 0xc , V_356 ) ;
F_19 ( V_2 , 0 , V_357 ) ;
F_19 ( V_2 , 0 , V_358 ) ;
F_19 ( V_2 , 0 , V_359 ) ;
F_19 ( V_2 , 0 , V_360 ) ;
F_19 ( V_2 , V_361 | V_362 , V_363 ) ;
if ( F_1 ( V_2 ) ) {
F_19 ( V_2 , 0 , V_364 ) ;
F_19 ( V_2 , 0 , V_365 ) ;
} else {
F_19 ( V_2 , 0 , V_366 ) ;
F_19 ( V_2 , 0 , V_367 ) ;
}
F_19 ( V_2 , 0 , V_368 ) ;
F_19 ( V_2 , 0 , V_369 ) ;
F_19 ( V_2 , 0 , V_331 ) ;
F_19 ( V_2 , 0 , V_314 ) ;
F_19 ( V_2 , 0 , V_370 ) ;
F_19 ( V_2 , 0 , V_371 ) ;
F_19 ( V_2 , 0 , V_372 ) ;
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_259 * V_373 = F_162 ( & V_6 -> V_111 ) ;
F_163 ( V_373 ) ;
F_164 ( & V_6 -> V_111 , NULL ) ;
F_165 ( V_373 ) ;
return 0 ;
}
static int F_166 ( struct V_5 * V_6 , int V_260 ,
struct V_374 * V_375 )
{
int V_47 , V_20 ;
struct V_88 * V_89 ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
V_89 = F_167 ( & V_6 -> V_111 , sizeof( struct V_88 ) ,
V_127 ) ;
if ( ! V_89 ) {
V_47 = - V_128 ;
goto V_54;
}
V_89 -> V_83 = V_2 -> V_83 + V_2 -> V_3 [ V_376 ] ;
V_89 -> V_90 = V_375 -> V_377 ;
V_89 -> V_93 = V_378 ;
V_89 -> V_92 = V_379 ;
V_89 -> V_91 = V_380 ;
V_89 -> V_94 = V_381 ;
V_89 -> V_86 . V_382 = & V_383 ;
V_2 -> V_259 = F_168 ( & V_89 -> V_86 ) ;
if ( ! V_2 -> V_259 ) {
V_47 = - V_128 ;
goto V_54;
}
V_2 -> V_259 -> V_262 = L_22 ;
V_2 -> V_259 -> V_384 = & V_6 -> V_111 ;
snprintf ( V_2 -> V_259 -> V_260 , V_257 , L_23 ,
V_2 -> V_292 -> V_262 , V_260 ) ;
V_2 -> V_259 -> V_239 = F_167 ( & V_6 -> V_111 ,
sizeof( int ) * V_385 ,
V_127 ) ;
if ( ! V_2 -> V_259 -> V_239 ) {
V_47 = - V_128 ;
goto V_386;
}
for ( V_20 = 0 ; V_20 < V_385 ; V_20 ++ )
V_2 -> V_259 -> V_239 [ V_20 ] = V_387 ;
V_47 = F_169 ( V_2 -> V_259 ) ;
if ( V_47 )
goto V_386;
F_164 ( & V_6 -> V_111 , V_2 -> V_259 ) ;
return 0 ;
V_386:
F_165 ( V_2 -> V_259 ) ;
V_54:
return V_47 ;
}
static const T_3 * F_170 ( int V_388 )
{
const T_3 * V_3 = NULL ;
switch ( V_388 ) {
case V_389 :
V_3 = V_4 ;
break;
case V_390 :
V_3 = V_391 ;
break;
case V_392 :
V_3 = V_393 ;
break;
case V_394 :
V_3 = V_395 ;
break;
default:
F_24 ( L_24 , V_388 ) ;
break;
}
return V_3 ;
}
static int F_171 ( struct V_396 * V_292 )
{
int V_47 , V_397 = 0 ;
struct V_398 * V_399 ;
struct V_5 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_374 * V_375 = F_172 ( & V_292 -> V_111 ) ;
const struct V_400 * V_260 = F_173 ( V_292 ) ;
V_399 = F_174 ( V_292 , V_401 , 0 ) ;
if ( F_152 ( V_399 == NULL ) ) {
F_77 ( & V_292 -> V_111 , L_25 ) ;
V_47 = - V_288 ;
goto V_54;
}
V_6 = F_175 ( sizeof( struct V_1 ) ) ;
if ( ! V_6 ) {
V_47 = - V_128 ;
goto V_54;
}
V_6 -> V_402 = V_399 -> V_132 ;
V_397 = V_292 -> V_260 ;
if ( V_397 < 0 )
V_397 = 0 ;
V_6 -> V_403 = - 1 ;
V_47 = F_176 ( V_292 , 0 ) ;
if ( V_47 < 0 ) {
V_47 = - V_313 ;
goto V_404;
}
V_6 -> V_239 = V_47 ;
F_177 ( V_6 , & V_292 -> V_111 ) ;
V_2 = F_3 ( V_6 ) ;
V_2 -> V_98 = V_405 ;
V_2 -> V_96 = V_406 ;
V_2 -> V_83 = F_178 ( & V_292 -> V_111 , V_399 ) ;
if ( F_93 ( V_2 -> V_83 ) ) {
V_47 = F_94 ( V_2 -> V_83 ) ;
goto V_404;
}
F_179 ( & V_2 -> V_243 ) ;
V_2 -> V_292 = V_292 ;
F_180 ( & V_292 -> V_111 ) ;
F_181 ( & V_292 -> V_111 ) ;
V_2 -> V_256 = V_375 -> V_407 ;
V_2 -> V_8 = V_375 -> V_8 ;
V_2 -> V_74 = V_375 -> V_74 ;
V_2 -> V_218 = V_375 -> V_218 ;
V_2 -> V_221 = V_375 -> V_221 ;
V_2 -> V_31 = (struct V_30 * ) V_260 -> V_408 ;
V_2 -> V_3 = F_170 ( V_2 -> V_31 -> V_388 ) ;
F_22 ( V_2 -> V_31 ) ;
if ( V_2 -> V_31 -> V_332 )
V_6 -> V_409 = & V_410 ;
else
V_6 -> V_409 = & V_411 ;
F_182 ( V_6 , & V_412 ) ;
V_6 -> V_413 = V_414 ;
V_2 -> V_270 = V_415 ;
F_35 ( V_6 , V_375 -> V_416 ) ;
if ( ! F_183 ( V_6 -> V_77 ) ) {
F_84 ( & V_292 -> V_111 ,
L_26 ) ;
F_184 ( V_6 ) ;
}
if ( V_2 -> V_31 -> V_332 ) {
struct V_398 * V_417 ;
V_417 = F_174 ( V_292 , V_401 , 1 ) ;
V_2 -> V_418 = F_178 ( & V_292 -> V_111 , V_417 ) ;
if ( F_93 ( V_2 -> V_418 ) ) {
V_47 = F_94 ( V_2 -> V_418 ) ;
goto V_404;
}
V_2 -> V_315 = V_397 % 2 ;
V_6 -> V_419 = V_420 ;
}
if ( ! V_397 || V_375 -> V_421 ) {
if ( V_2 -> V_31 -> V_422 )
V_2 -> V_31 -> V_422 ( V_6 ) ;
if ( V_2 -> V_31 -> V_332 ) {
F_160 ( V_2 ) ;
}
}
F_185 ( V_6 , & V_2 -> V_247 , F_86 , 64 ) ;
V_47 = F_186 ( V_6 ) ;
if ( V_47 )
goto V_423;
V_47 = F_166 ( V_6 , V_292 -> V_260 , V_375 ) ;
if ( V_47 )
goto V_424;
F_187 ( L_27 ,
( T_1 ) V_6 -> V_402 , V_6 -> V_77 , V_6 -> V_239 ) ;
F_188 ( V_292 , V_6 ) ;
return V_47 ;
V_424:
F_189 ( V_6 ) ;
V_423:
F_190 ( & V_2 -> V_247 ) ;
V_404:
if ( V_6 )
F_191 ( V_6 ) ;
V_54:
return V_47 ;
}
static int F_192 ( struct V_396 * V_292 )
{
struct V_5 * V_6 = F_193 ( V_292 ) ;
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_161 ( V_6 ) ;
F_189 ( V_6 ) ;
F_190 ( & V_2 -> V_247 ) ;
F_194 ( & V_292 -> V_111 ) ;
F_191 ( V_6 ) ;
return 0 ;
}
static int F_195 ( struct V_425 * V_111 )
{
return 0 ;
}
