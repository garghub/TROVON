static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static void F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
const struct V_1 * V_9 ;
unsigned int V_10 , V_11 , V_12 = 1 ;
V_9 = F_1 ( V_8 -> V_13 . V_14 . V_15 ) ;
if ( ! V_9 ) {
V_9 = & V_4 [ 0 ] ;
V_8 -> V_13 . V_14 . V_15 = V_9 -> V_2 ;
}
V_10 = 704 ;
if ( V_8 -> V_13 . V_14 . V_10 < V_10 * 3 / 4 )
V_10 /= 2 ;
V_11 = ( V_6 -> V_16 & V_17 ) ? 576 : 480 ;
if ( V_8 -> V_13 . V_14 . V_11 < V_11 * 3 / 4 )
V_12 = 2 ;
switch ( V_8 -> V_13 . V_14 . V_18 ) {
case V_19 :
case V_20 :
V_12 = 2 ;
break;
case V_21 :
if ( V_12 > 1 )
V_8 -> V_13 . V_14 . V_18 = V_20 ;
break;
default:
if ( V_12 > 1 )
V_8 -> V_13 . V_14 . V_18 = V_19 ;
else
V_8 -> V_13 . V_14 . V_18 = V_22 ;
}
V_11 /= V_12 ;
V_8 -> V_13 . V_14 . V_10 = V_10 ;
V_8 -> V_13 . V_14 . V_11 = V_11 ;
V_8 -> V_13 . V_14 . V_23 = V_8 -> V_13 . V_14 . V_10 * V_9 -> V_24 / 8 ;
V_8 -> V_13 . V_14 . V_25 = V_8 -> V_13 . V_14 . V_11 * V_8 -> V_13 . V_14 . V_23 ;
V_8 -> V_13 . V_14 . V_26 = V_27 ;
}
static int F_4 ( struct V_28 * V_29 , unsigned int * V_30 ,
unsigned int * V_31 , unsigned int V_32 [] ,
struct V_33 * V_34 [] )
{
struct V_5 * V_6 = F_5 ( V_29 ) ;
unsigned int V_35 = V_6 -> V_10 * V_6 -> V_11 * V_6 -> V_9 -> V_24 / 8 ;
if ( * V_30 < 2 )
* V_30 = 2 ;
if ( * V_31 )
return V_32 [ 0 ] < V_35 ? - V_36 : 0 ;
V_32 [ 0 ] = V_35 ;
* V_31 = 1 ;
return 0 ;
}
static void F_6 ( struct V_37 * V_38 )
{
struct V_5 * V_6 = F_5 ( V_38 -> V_28 ) ;
struct V_39 * V_40 = F_7 ( V_38 ) ;
struct V_41 * V_42 ;
V_42 = F_8 ( V_40 , struct V_41 , V_38 ) ;
F_9 ( & V_6 -> V_43 ) ;
F_10 ( & V_42 -> V_44 , & V_6 -> V_45 ) ;
F_11 ( & V_6 -> V_43 ) ;
}
static void F_12 ( struct V_5 * V_6 , unsigned int V_46 )
{
V_47:
while ( ! F_13 ( & V_6 -> V_45 ) ) {
struct V_48 * V_49 = V_6 -> V_50 [ V_46 ] ;
struct V_41 * V_42 ;
struct V_51 * V_40 ;
struct V_52 * V_53 ;
unsigned int V_54 , V_55 = 0 ;
int V_56 ;
V_42 = F_14 ( & V_6 -> V_45 , struct V_41 ,
V_44 ) ;
F_15 ( & V_42 -> V_44 ) ;
V_54 = V_6 -> V_10 * V_6 -> V_11 * V_6 -> V_9 -> V_24 / 8 ;
if ( F_16 ( & V_42 -> V_38 . V_57 , 0 ) < V_54 ) {
F_17 ( L_1 ) ;
F_18 ( & V_42 -> V_38 . V_57 , V_58 ) ;
goto V_47;
}
V_40 = F_19 ( & V_42 -> V_38 . V_57 , 0 ) ;
F_20 (vbuf->sgl, sg, vbuf->nents, i) {
T_1 V_59 = F_21 ( V_53 ) ;
unsigned int V_60 = F_22 ( V_53 ) ;
while ( V_60 && V_54 ) {
unsigned int V_61 = F_23 (unsigned int, len,
MAX_SG_ENTRY_SIZE) ;
V_61 = F_24 ( V_61 , V_54 ) ;
if ( V_55 == V_62 ) {
F_17 ( L_2 ) ;
F_18 ( & V_42 -> V_38 . V_57 ,
V_58 ) ;
goto V_47;
}
V_49 [ V_55 ] . V_59 = F_25 ( V_59 ) ;
V_49 [ V_55 ++ ] . V_63 =
F_25 ( 0x40000000 |
V_61 ) ;
V_59 += V_61 ;
V_60 -= V_61 ;
V_54 -= V_61 ;
}
if ( ! V_54 )
break;
}
while ( V_55 < V_62 ) {
V_49 [ V_55 ] . V_59 = 0 ;
V_49 [ V_55 ++ ] . V_63 = 0 ;
}
V_42 -> V_38 . V_57 . V_64 = V_65 ;
V_6 -> V_66 [ V_46 ] = V_42 ;
return;
}
V_6 -> V_66 [ V_46 ] = NULL ;
}
static void F_26 ( struct V_5 * V_6 )
{
unsigned int V_67 = 704 ;
unsigned int V_68 = ( V_6 -> V_16 & V_17 ) ?
288 : 240 ;
unsigned int V_69 = F_27 ( V_6 -> V_70 ) ? 0 :
V_6 -> V_71 * V_62 ;
unsigned int V_72 = V_69 + V_62 - 1 ;
T_2 V_73 = ( 0 << 30 ) |
( 1 << 29 ) |
( ( V_6 -> V_11 < 300 ) << 28 ) |
( 1 << 27 ) |
( 0 << 25 ) |
( 0 << 24 ) |
( ( V_6 -> V_10 < 400 ) << 23 ) |
( V_6 -> V_9 -> V_74 << 20 ) |
( V_72 << 10 ) |
V_69 ;
T_2 V_75 ;
F_28 ( V_6 -> V_70 , V_76 [ V_6 -> V_71 ] , V_73 ) ;
F_28 ( V_6 -> V_70 , V_77 [ V_6 -> V_71 ] , ( 1 << 31 ) | ( V_68 << 16 )
| V_67 ) ;
V_75 = F_29 ( V_6 -> V_70 , V_78 ) ;
if ( V_6 -> V_16 & V_17 )
V_75 |= 1 << ( V_6 -> V_71 + 13 ) ;
else
V_75 &= ~ ( 1 << ( V_6 -> V_71 + 13 ) ) ;
F_28 ( V_6 -> V_70 , V_78 , V_75 ) ;
}
static int F_30 ( struct V_28 * V_29 , unsigned int V_55 )
{
struct V_5 * V_6 = F_5 ( V_29 ) ;
struct V_79 * V_70 = V_6 -> V_70 ;
T_2 V_80 ;
unsigned int V_46 ;
F_26 ( V_6 ) ;
F_9 ( & V_6 -> V_43 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
F_12 ( V_6 , V_46 ) ;
F_11 ( & V_6 -> V_43 ) ;
V_70 -> V_81 |= 1 << V_6 -> V_71 ;
V_6 -> V_82 = 0 ;
V_80 = F_29 ( V_70 , V_83 ) | ( 1 << V_6 -> V_71 ) ;
F_28 ( V_70 , V_83 , V_80 ) ;
F_28 ( V_70 , V_84 , ( 1 << 31 ) | V_80 ) ;
return 0 ;
}
static void F_31 ( struct V_28 * V_29 )
{
struct V_5 * V_6 = F_5 ( V_29 ) ;
struct V_79 * V_70 = V_6 -> V_70 ;
T_2 V_80 = F_29 ( V_70 , V_83 ) ;
T_2 V_85 = F_29 ( V_70 , V_84 ) ;
unsigned int V_46 ;
V_80 &= ~ ( 1 << V_6 -> V_71 ) ;
F_28 ( V_70 , V_83 , V_80 ) ;
V_70 -> V_81 &= ~ ( 1 << V_6 -> V_71 ) ;
V_85 &= ~ ( 1 << V_6 -> V_71 ) ;
F_28 ( V_70 , V_84 , V_85 ) ;
if ( ! V_70 -> V_81 ) {
F_28 ( V_70 , V_84 , 0 ) ;
F_28 ( V_70 , V_83 , 0 ) ;
}
F_9 ( & V_6 -> V_43 ) ;
while ( ! F_13 ( & V_6 -> V_45 ) ) {
struct V_41 * V_42 ;
V_42 = F_32 ( V_6 -> V_45 . V_86 , struct V_41 ,
V_44 ) ;
F_15 ( & V_42 -> V_44 ) ;
F_18 ( & V_42 -> V_38 . V_57 , V_58 ) ;
}
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
if ( V_6 -> V_66 [ V_46 ] )
F_18 ( & V_6 -> V_66 [ V_46 ] -> V_38 . V_57 ,
V_58 ) ;
F_11 ( & V_6 -> V_43 ) ;
}
static int F_33 ( struct V_87 * V_88 )
{
struct V_5 * V_6 ;
struct V_79 * V_70 ;
unsigned int V_71 ;
V_6 = F_8 ( V_88 -> V_89 , struct V_5 ,
V_90 ) ;
V_70 = V_6 -> V_70 ;
V_71 = V_6 -> V_71 ;
switch ( V_88 -> V_91 ) {
case V_92 :
F_28 ( V_70 , V_93 [ V_71 ] , V_88 -> V_94 & 0xFF ) ;
return 0 ;
case V_95 :
F_28 ( V_70 , V_96 [ V_71 ] , V_88 -> V_94 ) ;
return 0 ;
case V_97 :
F_28 ( V_70 , V_98 [ V_71 ] , V_88 -> V_94 ) ;
F_28 ( V_70 , V_99 [ V_71 ] , V_88 -> V_94 ) ;
return 0 ;
case V_100 :
F_28 ( V_70 , V_101 [ V_71 ] , V_88 -> V_94 & 0xFF ) ;
return 0 ;
}
return - V_36 ;
}
static int F_34 ( struct V_102 * V_102 , void * V_103 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
V_8 -> V_13 . V_14 . V_10 = V_6 -> V_10 ;
V_8 -> V_13 . V_14 . V_11 = V_6 -> V_11 ;
V_8 -> V_13 . V_14 . V_18 = V_6 -> V_18 ;
V_8 -> V_13 . V_14 . V_15 = V_6 -> V_9 -> V_2 ;
V_8 -> V_13 . V_14 . V_26 = V_27 ;
V_8 -> V_13 . V_14 . V_23 = V_8 -> V_13 . V_14 . V_10 * V_6 -> V_9 -> V_24 / 8 ;
V_8 -> V_13 . V_14 . V_25 = V_8 -> V_13 . V_14 . V_11 * V_8 -> V_13 . V_14 . V_23 ;
return 0 ;
}
static int F_36 ( struct V_102 * V_102 , void * V_103 ,
struct V_7 * V_8 )
{
F_3 ( F_35 ( V_102 ) , V_8 ) ;
return 0 ;
}
static int F_37 ( struct V_102 * V_102 , void * V_103 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
F_3 ( V_6 , V_8 ) ;
V_6 -> V_9 = F_1 ( V_8 -> V_13 . V_14 . V_15 ) ;
V_6 -> V_18 = V_8 -> V_13 . V_14 . V_18 ;
V_6 -> V_10 = V_8 -> V_13 . V_14 . V_10 ;
V_6 -> V_11 = V_8 -> V_13 . V_14 . V_11 ;
return 0 ;
}
static int F_38 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
struct V_79 * V_70 = V_6 -> V_70 ;
strcpy ( V_105 -> V_106 , L_3 ) ;
strcpy ( V_105 -> V_107 , V_70 -> V_108 ) ;
sprintf ( V_105 -> V_109 , L_4 , F_39 ( V_70 -> V_110 ) ) ;
V_105 -> V_111 = V_112 | V_113 ;
V_105 -> V_114 = V_105 -> V_111 | V_115 ;
return 0 ;
}
static int F_40 ( struct V_102 * V_102 , void * V_103 , T_3 V_91 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
unsigned int V_3 ;
T_2 V_116 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_117 ) ; V_3 ++ )
if ( V_91 & V_117 [ V_3 ] ) {
V_116 = V_3 ;
break;
}
F_28 ( V_6 -> V_70 , V_118 [ V_6 -> V_71 ] , V_116 ) ;
V_6 -> V_16 = V_117 [ V_116 ] ;
return 0 ;
}
static int F_41 ( struct V_102 * V_102 , void * V_103 , T_3 * V_91 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
* V_91 = V_6 -> V_16 ;
return 0 ;
}
static int F_42 ( struct V_102 * V_102 , void * V_103 ,
struct V_119 * V_8 )
{
if ( V_8 -> V_120 >= F_2 ( V_4 ) )
return - V_36 ;
F_43 ( V_8 -> V_121 , V_4 [ V_8 -> V_120 ] . V_108 , sizeof( V_8 -> V_121 ) ) ;
V_8 -> V_15 = V_4 [ V_8 -> V_120 ] . V_2 ;
return 0 ;
}
static int F_44 ( struct V_102 * V_102 , void * V_103 ,
struct V_122 * V_123 )
{
struct V_5 * V_6 = F_35 ( V_102 ) ;
if ( V_123 -> type != V_124 )
return - V_36 ;
memset ( & V_123 -> V_125 . V_126 , 0 , sizeof( V_123 -> V_125 . V_126 ) ) ;
V_123 -> V_125 . V_126 . V_127 = V_128 ;
F_45 ( V_6 -> V_16 ,
& V_123 -> V_125 . V_126 . V_129 ) ;
return 0 ;
}
static int F_46 ( struct V_102 * V_102 , void * V_103 ,
struct V_130 * V_131 )
{
if ( V_131 -> V_120 )
return - V_36 ;
snprintf ( V_131 -> V_108 , sizeof( V_131 -> V_108 ) , L_5 ) ;
V_131 -> type = V_132 ;
V_131 -> V_133 = V_134 ;
V_131 -> V_114 = V_135 ;
return 0 ;
}
static int F_47 ( struct V_102 * V_102 , void * V_103 , unsigned int * V_136 )
{
* V_136 = 0 ;
return 0 ;
}
static int F_48 ( struct V_102 * V_102 , void * V_103 , unsigned int V_136 )
{
if ( V_136 )
return - V_36 ;
return 0 ;
}
static int F_49 ( void * V_137 )
{
struct V_79 * V_70 = V_137 ;
F_50 ( V_138 , V_139 ) ;
F_51 () ;
F_52 ( & V_70 -> V_140 , & V_138 ) ;
while ( 1 ) {
long V_141 = F_53 ( V_142 ) ;
unsigned int V_71 ;
if ( V_141 == - V_143 || F_54 () )
break;
for ( V_71 = 0 ; V_71 < F_55 ( V_70 ) ; V_71 ++ ) {
struct V_5 * V_6 ;
unsigned long V_144 ;
T_2 V_145 , V_46 , V_146 = V_147 ;
V_6 = & V_70 -> V_148 [ V_71 ] ;
if ( ! ( V_70 -> V_81 & ( 1 << V_71 ) ) )
continue;
F_56 ( & V_70 -> V_149 ) ;
V_145 = V_70 -> V_150 & ( 0x01000001 << V_71 ) ;
if ( V_145 )
V_70 -> V_150 &= ~ V_145 ;
F_57 ( & V_70 -> V_149 ) ;
if ( ! V_145 )
continue;
V_145 >>= V_71 ;
if ( ( V_145 & 0x01000000 ) |
( F_29 ( V_70 , V_151 ) & ( 0x01010001 << V_71 ) ) |
( F_29 ( V_70 , V_152 ) & ( 0x00000101 << V_71 ) ) ) {
T_2 V_75 ;
F_58 ( & V_70 -> V_149 , V_144 ) ;
V_75 = F_29 ( V_70 , V_84 ) ;
F_28 ( V_70 , V_84 , V_75 & ~ ( 1 << V_71 ) ) ;
F_28 ( V_70 , V_84 , V_75 ) ;
F_59 ( & V_70 -> V_149 , V_144 ) ;
V_146 = V_58 ;
}
F_60 ( & V_6 -> V_153 ) ;
F_9 ( & V_6 -> V_43 ) ;
V_46 = ! ! ( F_29 ( V_70 , V_154 ) & ( 1 << V_71 ) ) ;
if ( V_6 -> V_66 [ V_46 ] ) {
struct V_39 * V_38 ;
V_38 = & V_6 -> V_66 [ V_46 ] -> V_38 ;
V_38 -> V_57 . V_155 = F_61 () ;
V_38 -> V_18 = V_6 -> V_18 ;
if ( F_62 ( V_6 -> V_18 ) )
V_38 -> V_156 = V_6 -> V_82 ++ ;
else
V_38 -> V_156 = ( V_6 -> V_82 ++ ) / 2 ;
F_63 ( & V_38 -> V_57 , 0 ,
V_6 -> V_10 * V_6 -> V_11 * V_6 -> V_9 -> V_24 / 8 ) ;
F_18 ( & V_38 -> V_57 , V_146 ) ;
}
F_12 ( V_6 , V_46 ) ;
F_11 ( & V_6 -> V_43 ) ;
F_64 ( & V_6 -> V_153 ) ;
}
F_65 () ;
}
F_66 ( & V_70 -> V_140 , & V_138 ) ;
return 0 ;
}
int F_67 ( struct V_79 * V_70 )
{
unsigned long V_144 , V_157 = 0 ;
T_2 V_158 ;
F_58 ( & V_70 -> V_149 , V_144 ) ;
V_158 = V_70 -> V_150 ;
F_59 ( & V_70 -> V_149 , V_144 ) ;
if ( V_158 & V_70 -> V_81 ) {
F_68 ( & V_70 -> V_140 ) ;
V_157 = 1 ;
}
return V_157 ;
}
void F_69 ( struct V_79 * V_70 )
{
unsigned int V_71 , V_46 ;
if ( V_70 -> F_49 )
F_70 ( V_70 -> F_49 ) ;
for ( V_71 = 0 ; V_71 < F_55 ( V_70 ) ; V_71 ++ ) {
struct V_5 * V_6 = & V_70 -> V_148 [ V_71 ] ;
F_71 ( & V_6 -> V_90 ) ;
if ( V_6 -> V_33 )
F_72 ( V_6 -> V_33 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
struct V_159 * V_49 = & V_6 -> V_160 [ V_46 ] ;
if ( V_49 -> V_161 )
F_73 ( V_70 -> V_110 , V_49 -> V_35 ,
V_49 -> V_161 , V_49 -> V_59 ) ;
}
}
F_74 ( & V_70 -> V_162 ) ;
}
int F_75 ( struct V_79 * V_70 )
{
unsigned int V_71 , V_46 ;
int V_163 ;
F_76 ( & V_70 -> V_140 ) ;
V_163 = F_77 ( & V_70 -> V_110 -> V_70 , & V_70 -> V_162 ) ;
if ( V_163 )
return V_163 ;
F_28 ( V_70 , V_78 , 0 ) ;
F_28 ( V_70 , V_164 , 0x00001518 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
if ( F_27 ( V_70 ) ) {
for ( V_71 = 0 ; V_71 < F_55 ( V_70 ) ; V_71 ++ )
V_70 -> V_148 [ V_71 ] . V_160 [ V_46 ] . V_35 =
V_165 ;
} else
V_70 -> V_148 [ 0 ] . V_160 [ V_46 ] . V_35 =
F_55 ( V_70 ) * V_165 ;
for ( V_71 = 0 ; V_71 < F_55 ( V_70 ) ; V_71 ++ ) {
struct V_5 * V_6 = & V_70 -> V_148 [ V_71 ] ;
struct V_166 * V_167 ;
F_78 ( & V_6 -> V_153 ) ;
F_79 ( & V_6 -> V_43 ) ;
F_80 ( & V_6 -> V_45 ) ;
V_6 -> V_70 = V_70 ;
V_6 -> V_71 = V_71 ;
V_6 -> V_9 = & V_4 [ 0 ] ;
V_6 -> V_16 = V_168 ;
F_28 ( V_6 -> V_70 , V_118 [ V_6 -> V_71 ] , 0 ) ;
V_6 -> V_18 = V_21 ;
V_6 -> V_10 = 704 ;
V_6 -> V_11 = 480 ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
void * V_169 ;
if ( V_6 -> V_160 [ V_46 ] . V_35 ) {
unsigned int V_75 = V_46 ? V_170 [ V_71 ] :
V_171 [ V_71 ] ;
V_169 = F_81 ( V_70 -> V_110 ,
V_6 -> V_160 [ V_46 ] . V_35 ,
& V_6 -> V_160 [ V_46 ] . V_59 ) ;
if ( ! V_169 ) {
F_17 ( L_6 ) ;
V_163 = - V_172 ;
goto error;
}
V_6 -> V_160 [ V_46 ] . V_161 = V_169 ;
F_28 ( V_70 , V_75 , V_6 -> V_160 [ V_46 ] . V_59 ) ;
} else
V_169 = V_70 -> V_148 [ 0 ] . V_160 [ V_46 ] . V_161 +
V_71 * V_165 ;
V_6 -> V_50 [ V_46 ] = V_169 ;
}
F_28 ( V_70 , V_173 [ 0 ] , 0x24 ) ;
F_28 ( V_70 , V_174 [ 0 ] , 0xA5 ) ;
if ( F_55 ( V_70 ) > 4 ) {
F_28 ( V_70 , V_173 [ 1 ] , 0x24 ) ;
F_28 ( V_70 , V_174 [ 1 ] , 0xA5 ) ;
}
F_28 ( V_70 , V_175 [ V_71 ] , 0 ) ;
F_28 ( V_70 , V_176 [ V_71 ] , 0x14 ) ;
V_167 = F_82 () ;
if ( ! V_167 ) {
F_83 ( L_7 ) ;
V_163 = - V_172 ;
goto error;
}
V_6 -> V_177 . type = V_124 ;
V_6 -> V_177 . V_178 = V_179 | V_180 | V_181 ;
V_6 -> V_177 . V_182 = V_6 ;
V_6 -> V_177 . V_183 = sizeof( struct V_41 ) ;
V_6 -> V_177 . V_184 = & V_185 ;
V_6 -> V_177 . V_186 = & V_187 ;
V_6 -> V_177 . V_188 = V_189 ;
V_6 -> V_177 . V_190 = 2 ;
V_6 -> V_177 . V_191 = & V_6 -> V_153 ;
V_6 -> V_177 . V_70 = & V_70 -> V_110 -> V_70 ;
V_6 -> V_177 . V_192 = V_193 ;
V_163 = F_84 ( & V_6 -> V_177 ) ;
if ( V_163 )
goto error;
strcpy ( V_167 -> V_108 , L_8 ) ;
snprintf ( V_167 -> V_108 , sizeof( V_167 -> V_108 ) , L_9 , V_70 -> V_108 ) ;
V_167 -> V_194 = & V_195 ;
V_167 -> V_196 = & V_197 ;
V_167 -> V_198 = V_199 ;
V_167 -> V_162 = & V_70 -> V_162 ;
V_167 -> V_200 = & V_6 -> V_177 ;
V_167 -> V_201 = V_134 ;
V_167 -> V_202 = - 1 ;
V_167 -> V_191 = & V_6 -> V_153 ;
V_70 -> V_148 [ V_71 ] . V_33 = V_167 ;
F_85 ( V_167 , V_6 ) ;
V_163 = F_86 ( V_167 , V_203 , - 1 ) ;
if ( V_163 < 0 )
goto error;
F_87 ( & V_6 -> V_90 ,
4 ) ;
V_167 -> V_90 = & V_6 -> V_90 ;
F_88 ( & V_6 -> V_90 , & V_204 ,
V_92 , - 128 , 127 , 1 , 0 ) ;
F_88 ( & V_6 -> V_90 , & V_204 ,
V_95 , 0 , 255 , 1 , 64 ) ;
F_88 ( & V_6 -> V_90 , & V_204 ,
V_97 , 0 , 255 , 1 , 128 ) ;
F_88 ( & V_6 -> V_90 , & V_204 , V_100 ,
- 124 , 127 , 1 , 0 ) ;
V_163 = V_6 -> V_90 . error ;
if ( V_163 )
goto error;
F_89 ( & V_6 -> V_90 ) ;
}
V_70 -> F_49 = F_90 ( F_49 , V_70 , L_10 ) ;
if ( F_91 ( V_70 -> F_49 ) ) {
V_163 = F_92 ( V_70 -> F_49 ) ;
goto error;
}
return 0 ;
error:
F_69 ( V_70 ) ;
return V_163 ;
}
