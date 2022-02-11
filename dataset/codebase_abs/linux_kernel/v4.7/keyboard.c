static inline int F_1 ( void )
{
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
return F_3 ( & V_3 , V_2 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_3 , V_2 ) ;
}
static int F_6 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
V_8 -> error = F_7 ( V_5 -> V_9 , & V_8 -> V_10 ) ;
return V_8 -> error == 0 ;
}
static int F_8 ( unsigned int V_11 )
{
struct V_7 V_8 = {
. V_10 = {
. V_12 = 0 ,
. V_13 = sizeof( V_11 ) ,
. V_14 = 0 ,
} ,
. error = - V_15 ,
} ;
memcpy ( V_8 . V_10 . V_11 , & V_11 , sizeof( V_11 ) ) ;
F_9 ( & V_16 , & V_8 , F_6 ) ;
return V_8 . error ? : V_8 . V_10 . V_14 ;
}
static int F_10 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
V_8 -> error = F_11 ( V_5 -> V_9 , & V_8 -> V_10 ) ;
return V_8 -> error == 0 ;
}
static int F_12 ( unsigned int V_11 , unsigned int V_14 )
{
struct V_7 V_8 = {
. V_10 = {
. V_12 = 0 ,
. V_13 = sizeof( V_11 ) ,
. V_14 = V_14 ,
} ,
. error = - V_15 ,
} ;
memcpy ( V_8 . V_10 . V_11 , & V_11 , sizeof( V_11 ) ) ;
F_9 ( & V_16 , & V_8 , F_10 ) ;
return V_8 . error ;
}
static int F_13 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int * V_17 = V_6 ;
struct V_18 * V_9 = V_5 -> V_9 ;
if ( F_14 ( V_19 , V_9 -> V_20 ) ) {
if ( F_14 ( V_21 , V_9 -> V_22 ) ) {
F_15 ( V_5 , V_19 , V_21 , * V_17 ) ;
if ( * V_17 )
return 0 ;
}
if ( F_14 ( V_23 , V_9 -> V_22 ) )
F_15 ( V_5 , V_19 , V_23 , * V_17 ? 1 : 0 ) ;
}
return 0 ;
}
static void F_16 ( unsigned long V_24 )
{
static unsigned int V_25 ;
F_9 ( & V_16 , & V_25 , F_13 ) ;
}
void F_17 ( unsigned int V_17 , unsigned int V_26 )
{
F_18 ( & V_27 ) ;
F_9 ( & V_16 , & V_17 , F_13 ) ;
if ( V_17 && V_26 )
F_19 ( & V_27 , V_28 + V_26 ) ;
}
static int F_20 ( struct V_4 * V_5 , void * V_6 )
{
struct V_18 * V_9 = V_5 -> V_9 ;
struct V_29 * V_30 = V_6 ;
if ( F_14 ( V_31 , V_9 -> V_20 ) ) {
if ( V_30 [ 0 ] . V_32 > 0 )
F_15 ( V_5 ,
V_31 , V_33 , V_30 [ 0 ] . V_32 ) ;
if ( V_30 [ 0 ] . V_34 > 0 )
F_15 ( V_5 ,
V_31 , V_35 , V_30 [ 0 ] . V_34 ) ;
V_30 [ 1 ] . V_32 = V_9 -> V_36 [ V_33 ] ;
V_30 [ 1 ] . V_34 = V_9 -> V_36 [ V_35 ] ;
}
return 0 ;
}
int F_21 ( struct V_29 * V_30 )
{
struct V_29 V_6 [ 2 ] = { * V_30 } ;
F_9 ( & V_16 , V_6 , F_20 ) ;
* V_30 = V_6 [ 1 ] ;
return 0 ;
}
static void F_22 ( struct V_37 * V_38 , int V_39 )
{
F_23 ( & V_38 -> V_40 , V_39 , 0 ) ;
F_24 ( & V_38 -> V_40 ) ;
}
static void F_25 ( struct V_37 * V_38 , char * V_41 )
{
while ( * V_41 ) {
F_23 ( & V_38 -> V_40 , * V_41 , 0 ) ;
V_41 ++ ;
}
F_24 ( & V_38 -> V_40 ) ;
}
static void F_26 ( struct V_37 * V_38 , int V_42 , char V_43 )
{
static char V_44 [] = { 0x1b , 'O' , 0x00 , 0x00 } ;
V_44 [ 1 ] = ( V_43 ? 'O' : '[' ) ;
V_44 [ 2 ] = V_42 ;
F_25 ( V_38 , V_44 ) ;
}
static void F_27 ( struct V_37 * V_38 , T_1 V_45 )
{
if ( V_45 < 0x80 )
F_22 ( V_38 , V_45 ) ;
else if ( V_45 < 0x800 ) {
F_22 ( V_38 , 0xc0 | ( V_45 >> 6 ) ) ;
F_22 ( V_38 , 0x80 | ( V_45 & 0x3f ) ) ;
} else if ( V_45 < 0x10000 ) {
if ( V_45 >= 0xD800 && V_45 < 0xE000 )
return;
if ( V_45 == 0xFFFF )
return;
F_22 ( V_38 , 0xe0 | ( V_45 >> 12 ) ) ;
F_22 ( V_38 , 0x80 | ( ( V_45 >> 6 ) & 0x3f ) ) ;
F_22 ( V_38 , 0x80 | ( V_45 & 0x3f ) ) ;
} else if ( V_45 < 0x110000 ) {
F_22 ( V_38 , 0xf0 | ( V_45 >> 18 ) ) ;
F_22 ( V_38 , 0x80 | ( ( V_45 >> 12 ) & 0x3f ) ) ;
F_22 ( V_38 , 0x80 | ( ( V_45 >> 6 ) & 0x3f ) ) ;
F_22 ( V_38 , 0x80 | ( V_45 & 0x3f ) ) ;
}
}
static void F_28 ( void )
{
unsigned int V_46 , V_47 , V_48 ;
V_49 = 0 ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
F_29 (k, key_down, min(NR_KEYS, KEY_CNT)) {
V_47 = F_30 ( V_51 [ 0 ] [ V_46 ] ) ;
if ( F_31 ( V_47 ) != V_52 && F_31 ( V_47 ) != V_53 )
continue;
V_48 = F_32 ( V_47 ) ;
if ( V_48 == F_32 ( V_54 ) )
V_48 = F_32 ( V_55 ) ;
V_50 [ V_48 ] ++ ;
V_49 |= F_33 ( V_48 ) ;
}
}
void F_34 ( void )
{
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
F_28 () ;
F_36 ( & V_56 , V_12 ) ;
}
static unsigned int F_37 ( struct V_37 * V_38 , unsigned int V_39 )
{
unsigned int V_8 = V_57 ;
unsigned int V_58 ;
V_57 = 0 ;
if ( ( V_8 & ~ 0xff ) == V_59 ) {
if ( ( V_39 & ~ 0xff ) == V_59 )
return V_8 | V_39 ;
} else {
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ )
if ( V_61 [ V_58 ] . V_57 == V_8 && V_61 [ V_58 ] . V_62 == V_39 )
return V_61 [ V_58 ] . V_63 ;
}
if ( V_39 == ' ' || V_39 == ( V_59 | 0 ) || V_39 == V_8 )
return V_8 ;
if ( V_64 -> V_65 == V_66 )
F_27 ( V_38 , V_8 ) ;
else {
int V_45 = F_38 ( V_8 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
return V_39 ;
}
static void F_39 ( struct V_37 * V_38 )
{
if ( V_57 ) {
if ( V_64 -> V_65 == V_66 )
F_27 ( V_38 , V_57 ) ;
else {
int V_45 = F_38 ( V_57 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
V_57 = 0 ;
}
F_22 ( V_38 , 13 ) ;
if ( F_40 ( V_64 , V_67 ) )
F_22 ( V_38 , 10 ) ;
}
static void F_41 ( struct V_37 * V_38 )
{
if ( V_36 )
return;
F_42 ( V_64 , V_68 ) ;
}
static void F_43 ( struct V_37 * V_38 )
{
if ( V_36 )
return;
F_44 ( V_64 , V_68 ) ;
}
static void F_45 ( struct V_37 * V_38 )
{
struct V_69 * V_70 = F_46 () ;
if ( V_70 )
F_47 ( V_70 ) ;
}
static void F_48 ( struct V_37 * V_38 )
{
struct V_71 * V_72 = V_38 -> V_40 . V_72 ;
if ( V_36 || ! V_72 )
return;
if ( V_72 -> V_73 )
F_49 ( V_72 ) ;
else
F_50 ( V_72 ) ;
}
static void F_51 ( struct V_37 * V_38 )
{
if ( F_40 ( V_64 , V_74 ) )
F_26 ( V_38 , 'P' , 1 ) ;
else
F_52 ( V_38 ) ;
}
static void F_52 ( struct V_37 * V_38 )
{
if ( ! V_36 )
F_42 ( V_64 , V_75 ) ;
}
static void F_53 ( struct V_37 * V_38 )
{
F_54 ( V_76 ) ;
}
static void F_55 ( struct V_37 * V_38 )
{
int V_58 , V_77 = V_78 ;
if ( V_79 != - 1 )
V_77 = V_79 ;
for ( V_58 = V_77 - 1 ; V_58 != V_77 ; V_58 -- ) {
if ( V_58 == - 1 )
V_58 = V_80 - 1 ;
if ( F_56 ( V_58 ) )
break;
}
F_54 ( V_58 ) ;
}
static void F_57 ( struct V_37 * V_38 )
{
int V_58 , V_77 = V_78 ;
if ( V_79 != - 1 )
V_77 = V_79 ;
for ( V_58 = V_77 + 1 ; V_58 != V_77 ; V_58 ++ ) {
if ( V_58 == V_80 )
V_58 = 0 ;
if ( F_56 ( V_58 ) )
break;
}
F_54 ( V_58 ) ;
}
static void F_58 ( struct V_37 * V_38 )
{
F_23 ( & V_38 -> V_40 , 0 , V_81 ) ;
F_24 ( & V_38 -> V_40 ) ;
}
static void F_59 ( struct V_37 * V_38 )
{
F_60 ( V_38 , 0 ) ;
}
static void F_61 ( struct V_37 * V_38 )
{
F_62 ( V_38 , 0 ) ;
}
static void F_63 ( struct V_37 * V_38 )
{
F_64 ( 0 ) ;
}
static void F_65 ( struct V_37 * V_38 )
{
F_66 () ;
}
static void F_67 ( struct V_37 * V_38 )
{
F_68 () ;
}
static void F_69 ( struct V_37 * V_38 )
{
V_82 = true ;
}
static void F_70 ( struct V_37 * V_38 )
{
F_71 ( & V_83 . V_84 ) ;
if ( V_83 . V_85 )
if ( F_72 ( V_83 . V_85 , V_83 . V_86 , 1 ) ) {
F_73 ( V_83 . V_85 ) ;
V_83 . V_85 = NULL ;
}
F_74 ( & V_83 . V_84 ) ;
}
static void F_75 ( struct V_37 * V_38 )
{
struct V_87 * V_88 = & V_89 [ V_78 ] . V_88 ;
F_76 ( V_88 ) ;
}
static void F_77 ( struct V_37 * V_38 )
{
F_28 () ;
}
static void F_78 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
}
static void F_79 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
if ( V_91 )
return;
if ( V_90 >= F_80 ( V_92 ) )
return;
if ( ( V_64 -> V_65 == V_93 ||
V_64 -> V_65 == V_94 ||
V_64 -> V_65 == V_95 ) &&
V_90 != F_32 ( V_96 ) )
return;
V_92 [ V_90 ] ( V_38 ) ;
}
static void F_81 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
F_82 ( L_1 ) ;
}
static void F_83 ( struct V_37 * V_38 , unsigned int V_90 , char V_91 )
{
if ( V_91 )
return;
if ( V_57 )
V_90 = F_37 ( V_38 , V_90 ) ;
if ( V_82 ) {
V_82 = false ;
V_57 = V_90 ;
return;
}
if ( V_64 -> V_65 == V_66 )
F_27 ( V_38 , V_90 ) ;
else {
int V_45 = F_38 ( V_90 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
}
static void F_84 ( struct V_37 * V_38 , unsigned int V_90 , char V_91 )
{
if ( V_91 )
return;
V_57 = ( V_57 ? F_37 ( V_38 , V_90 ) : V_90 ) ;
}
static void F_85 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
F_83 ( V_38 , F_86 ( V_90 ) , V_91 ) ;
}
static void F_87 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
F_84 ( V_38 , V_90 , V_91 ) ;
}
static void F_88 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
static const unsigned char V_97 [ V_98 ] = { '`' , '\'' , '^' , '~' , '"' , ',' } ;
F_84 ( V_38 , V_97 [ V_90 ] , V_91 ) ;
}
static void F_89 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
if ( V_91 )
return;
F_54 ( V_90 ) ;
}
static void F_90 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
if ( V_91 )
return;
if ( ( unsigned ) V_90 < F_80 ( V_99 ) ) {
if ( V_99 [ V_90 ] )
F_25 ( V_38 , V_99 [ V_90 ] ) ;
} else
F_82 ( L_2 , V_90 ) ;
}
static void F_91 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
static const char V_100 [] = L_3 ;
if ( V_91 )
return;
F_26 ( V_38 , V_100 [ V_90 ] , F_40 ( V_64 , V_101 ) ) ;
}
static void F_92 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
static const char V_102 [] = L_4 ;
static const char V_103 [] = L_5 ;
if ( V_91 )
return;
if ( F_40 ( V_64 , V_74 ) && ! V_50 [ V_104 ] ) {
F_26 ( V_38 , V_103 [ V_90 ] , 1 ) ;
return;
}
if ( ! F_93 ( V_64 , V_75 ) ) {
switch ( V_90 ) {
case F_32 ( V_105 ) :
case F_32 ( V_106 ) :
F_90 ( V_38 , F_32 ( V_107 ) , 0 ) ;
return;
case F_32 ( V_108 ) :
F_90 ( V_38 , F_32 ( V_109 ) , 0 ) ;
return;
case F_32 ( V_110 ) :
F_90 ( V_38 , F_32 ( V_111 ) , 0 ) ;
return;
case F_32 ( V_112 ) :
F_91 ( V_38 , F_32 ( V_113 ) , 0 ) ;
return;
case F_32 ( V_114 ) :
F_90 ( V_38 , F_32 ( V_115 ) , 0 ) ;
return;
case F_32 ( V_116 ) :
F_91 ( V_38 , F_32 ( V_117 ) , 0 ) ;
return;
case F_32 ( V_118 ) :
F_91 ( V_38 , F_32 ( V_119 ) , 0 ) ;
return;
case F_32 ( V_120 ) :
F_90 ( V_38 , F_32 ( V_121 ) , 0 ) ;
return;
case F_32 ( V_122 ) :
F_91 ( V_38 , F_32 ( V_123 ) , 0 ) ;
return;
case F_32 ( V_124 ) :
F_90 ( V_38 , F_32 ( V_125 ) , 0 ) ;
return;
case F_32 ( V_126 ) :
F_26 ( V_38 , 'G' , F_40 ( V_64 , V_74 ) ) ;
return;
}
}
F_22 ( V_38 , V_102 [ V_90 ] ) ;
if ( V_90 == F_32 ( V_127 ) && F_40 ( V_64 , V_67 ) )
F_22 ( V_38 , 10 ) ;
}
static void F_94 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
int V_128 = V_49 ;
if ( V_36 )
return;
if ( V_90 == F_32 ( V_54 ) ) {
V_90 = F_32 ( V_55 ) ;
if ( ! V_91 )
F_95 ( V_64 , V_68 ) ;
}
if ( V_91 ) {
if ( V_50 [ V_90 ] )
V_50 [ V_90 ] -- ;
} else
V_50 [ V_90 ] ++ ;
if ( V_50 [ V_90 ] )
V_49 |= ( 1 << V_90 ) ;
else
V_49 &= ~ ( 1 << V_90 ) ;
if ( V_91 && V_49 != V_128 && V_129 != - 1 ) {
if ( V_64 -> V_65 == V_66 )
F_27 ( V_38 , V_129 ) ;
else
F_22 ( V_38 , V_129 & 0xff ) ;
V_129 = - 1 ;
}
}
static void F_96 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
if ( V_91 )
return;
if ( F_40 ( V_64 , V_130 ) ) {
F_22 ( V_38 , '\033' ) ;
F_22 ( V_38 , V_90 ) ;
} else
F_22 ( V_38 , V_90 | 0x80 ) ;
}
static void F_97 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
int V_62 ;
if ( V_91 )
return;
if ( V_90 < 10 ) {
V_62 = 10 ;
} else {
V_90 -= 10 ;
V_62 = 16 ;
}
if ( V_129 == - 1 )
V_129 = V_90 ;
else
V_129 = V_129 * V_62 + V_90 ;
}
static void F_98 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
if ( V_91 || V_36 )
return;
F_99 ( V_64 , V_90 ) ;
}
static void F_100 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
F_94 ( V_38 , V_90 , V_91 ) ;
if ( V_91 || V_36 )
return;
F_101 ( V_64 , V_90 ) ;
if ( ! V_51 [ V_64 -> V_131 ^ V_64 -> V_132 ] ) {
V_64 -> V_132 = 0 ;
F_101 ( V_64 , V_90 ) ;
}
}
static void F_102 ( struct V_37 * V_38 , unsigned int V_133 , char V_91 )
{
static unsigned long V_134 ;
static unsigned V_135 ;
if ( ! V_136 )
F_84 ( V_38 , V_59 | V_133 , V_91 ) ;
else {
V_135 |= V_133 ;
V_134 ++ ;
if ( V_134 == V_136 ) {
F_83 ( V_38 , V_59 | V_135 , V_91 ) ;
V_134 = 0 ;
V_135 = 0 ;
}
}
}
static void F_103 ( struct V_37 * V_38 , unsigned char V_90 , char V_91 )
{
static unsigned V_137 , V_138 ;
static unsigned long V_139 ;
if ( V_64 -> V_65 != V_66 ) {
if ( ! V_91 )
F_104 ( L_6 ) ;
return;
}
if ( ! V_90 ) {
F_83 ( V_38 , V_59 , V_91 ) ;
return;
}
if ( V_90 > 8 )
return;
if ( ! V_91 ) {
V_137 |= 1 << ( V_90 - 1 ) ;
if ( ! V_140 )
V_138 = V_137 ;
} else if ( V_140 ) {
if ( ! V_138 ||
F_105 ( V_28 ,
V_139 + F_106 ( V_140 ) ) ) {
V_138 = V_137 ;
V_139 = V_28 ;
}
V_137 &= ~ ( 1 << ( V_90 - 1 ) ) ;
if ( ! V_137 && V_138 ) {
F_102 ( V_38 , V_138 , 0 ) ;
V_138 = 0 ;
}
} else {
if ( V_138 ) {
F_102 ( V_38 , V_138 , 0 ) ;
V_138 = 0 ;
}
V_137 &= ~ ( 1 << ( V_90 - 1 ) ) ;
}
}
static void F_107 ( struct V_141 * V_142 )
{
struct V_143 * V_144 =
F_108 ( V_142 -> V_144 , struct V_143 , V_144 ) ;
F_109 ( & V_145 ) ;
if ( V_146 != - 1U )
F_110 ( & V_144 -> V_144 ,
V_146 & V_144 -> V_147 ?
V_148 : V_149 ) ;
F_111 ( & V_145 ) ;
}
static void F_112 ( unsigned int V_128 ,
unsigned int V_150 )
{
struct V_143 * V_144 ;
unsigned int V_151 = V_128 ^ V_150 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < F_80 ( V_152 ) ; V_58 ++ ) {
V_144 = & V_152 [ V_58 ] ;
if ( V_151 & V_144 -> V_147 )
F_110 ( & V_144 -> V_144 ,
V_150 & V_144 -> V_147 ?
V_148 : V_149 ) ;
}
}
static int F_113 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int V_153 = * ( unsigned int * ) V_6 ;
if ( F_14 ( V_154 , V_5 -> V_9 -> V_20 ) )
F_112 ( ~ V_153 , V_153 ) ;
return 0 ;
}
static void F_114 ( void )
{
int error ;
int V_58 ;
for ( V_58 = 0 ; V_58 < F_80 ( V_152 ) ; V_58 ++ ) {
error = F_115 ( & V_152 [ V_58 ] . V_144 ) ;
if ( error )
F_82 ( L_7 ,
error , V_152 [ V_58 ] . V_144 . V_155 ) ;
}
}
static int F_113 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int V_156 = * ( unsigned int * ) V_6 ;
if ( F_14 ( V_154 , V_5 -> V_9 -> V_20 ) ) {
F_15 ( V_5 , V_154 , V_157 , ! ! ( V_156 & 0x01 ) ) ;
F_15 ( V_5 , V_154 , V_158 , ! ! ( V_156 & 0x02 ) ) ;
F_15 ( V_5 , V_154 , V_159 , ! ! ( V_156 & 0x04 ) ) ;
F_15 ( V_5 , V_160 , V_161 , 0 ) ;
}
return 0 ;
}
static void F_112 ( unsigned int V_128 ,
unsigned int V_150 )
{
F_9 ( & V_16 , & V_150 ,
F_113 ) ;
}
static void F_114 ( void )
{
}
static unsigned char F_116 ( void )
{
return V_146 & 0xff ;
}
void F_117 ( struct V_162 * V_163 , unsigned int V_164 )
{
unsigned long V_12 ;
F_35 ( & V_165 , V_12 ) ;
if ( ! ( V_164 & ~ 7 ) ) {
V_166 = V_164 ;
V_163 -> V_167 = V_168 ;
} else
V_163 -> V_167 = V_169 ;
F_118 () ;
F_36 ( & V_165 , V_12 ) ;
}
static inline unsigned char F_119 ( void )
{
struct V_162 * V_163 = V_170 + V_78 ;
if ( V_163 -> V_167 == V_168 )
return V_166 ;
return V_163 -> V_171 ;
}
int F_120 ( int V_172 , int V_173 )
{
struct V_162 * V_163 = V_170 + V_172 ;
int V_174 ;
unsigned long V_12 ;
F_35 ( & V_165 , V_12 ) ;
V_174 = F_93 ( V_163 , V_173 ) ;
F_36 ( & V_165 , V_12 ) ;
return V_174 ;
}
void F_121 ( int V_172 , int V_156 )
{
struct V_162 * V_163 = V_170 + V_172 ;
F_117 ( V_163 , V_156 ) ;
}
void F_122 ( int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
F_35 ( & V_165 , V_12 ) ;
F_95 ( V_163 , V_175 ) ;
F_118 () ;
F_36 ( & V_165 , V_12 ) ;
}
void F_123 ( int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
F_35 ( & V_165 , V_12 ) ;
F_44 ( V_163 , V_175 ) ;
F_118 () ;
F_36 ( & V_165 , V_12 ) ;
}
static void F_124 ( unsigned long V_176 )
{
unsigned int V_156 ;
unsigned long V_12 ;
F_35 ( & V_165 , V_12 ) ;
V_156 = F_119 () ;
V_156 |= ( unsigned int ) V_64 -> V_131 << 8 ;
F_36 ( & V_165 , V_12 ) ;
if ( V_156 != V_146 ) {
F_112 ( V_146 , V_156 ) ;
V_146 = V_156 ;
}
}
static int F_125 ( struct V_37 * V_38 , unsigned int V_14 ,
unsigned char V_91 )
{
int V_177 ;
switch ( V_14 ) {
case V_178 :
F_22 ( V_38 , 0xe1 ) ;
F_22 ( V_38 , 0x1d | V_91 ) ;
F_22 ( V_38 , 0x45 | V_91 ) ;
break;
case V_179 :
if ( ! V_91 )
F_22 ( V_38 , 0xf2 ) ;
break;
case V_180 :
if ( ! V_91 )
F_22 ( V_38 , 0xf1 ) ;
break;
case V_181 :
if ( F_14 ( V_182 , V_183 ) ||
F_14 ( V_184 , V_183 ) ) {
F_22 ( V_38 , 0x54 | V_91 ) ;
} else {
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , 0x2a | V_91 ) ;
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , 0x37 | V_91 ) ;
}
break;
default:
if ( V_14 > 255 )
return - 1 ;
V_177 = V_185 [ V_14 ] ;
if ( ! V_177 )
return - 1 ;
if ( V_177 & 0x100 )
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , ( V_177 & 0x7f ) | V_91 ) ;
break;
}
return 0 ;
}
static int F_125 ( struct V_37 * V_38 , unsigned int V_14 , unsigned char V_91 )
{
if ( V_14 > 127 )
return - 1 ;
F_22 ( V_38 , V_14 | V_91 ) ;
return 0 ;
}
static void F_126 ( unsigned char V_6 )
{
struct V_37 * V_38 = V_89 [ V_78 ] . V_8 ;
V_64 = V_170 + V_38 -> V_186 ;
if ( V_64 -> V_65 == V_93 )
F_22 ( V_38 , V_6 ) ;
}
static void F_127 ( unsigned int V_14 , int V_187 , int V_188 )
{
struct V_37 * V_38 = V_89 [ V_78 ] . V_8 ;
unsigned short V_189 , * V_190 ;
unsigned char type ;
bool V_191 ;
struct V_71 * V_72 ;
int V_192 ;
struct V_193 V_194 = { . V_38 = V_38 , . V_90 = V_14 , . V_187 = V_187 } ;
int V_195 ;
V_72 = V_38 -> V_40 . V_72 ;
if ( V_72 && ( ! V_72 -> V_196 ) ) {
V_72 -> V_196 = V_38 ;
}
V_64 = V_170 + V_38 -> V_186 ;
#ifdef F_128
if ( V_14 == V_197 )
V_198 = V_187 ;
#endif
V_36 = ( V_187 == 2 ) ;
V_191 = ( V_64 -> V_65 == V_93 ) ;
if ( V_191 && ! V_188 )
if ( F_125 ( V_38 , V_14 , ! V_187 << 7 ) )
if ( V_14 < V_199 && F_129 () )
F_104 ( L_8 ,
V_14 ) ;
#ifdef F_128
if ( V_14 == V_200 && V_198 ) {
V_198 = false ;
F_130 () ;
}
#endif
if ( V_64 -> V_65 == V_94 ) {
if ( V_14 < 128 ) {
F_22 ( V_38 , V_14 | ( ! V_187 << 7 ) ) ;
} else {
F_22 ( V_38 , ! V_187 << 7 ) ;
F_22 ( V_38 , ( V_14 >> 7 ) | 0x80 ) ;
F_22 ( V_38 , V_14 | 0x80 ) ;
}
V_191 = true ;
}
if ( V_187 )
F_131 ( V_14 , V_183 ) ;
else
F_132 ( V_14 , V_183 ) ;
if ( V_36 &&
( ! F_40 ( V_64 , V_201 ) ||
( V_72 && ! F_133 ( V_72 ) && F_134 ( V_72 ) ) ) ) {
return;
}
V_194 . V_202 = V_192 = ( V_49 | V_64 -> V_132 ) ^ V_64 -> V_131 ;
V_194 . V_146 = V_64 -> V_171 ;
V_190 = V_51 [ V_192 ] ;
V_195 = F_135 ( & V_3 ,
V_203 , & V_194 ) ;
if ( V_195 == V_204 || ! V_190 ) {
F_135 ( & V_3 ,
V_205 , & V_194 ) ;
F_28 () ;
V_64 -> V_132 = 0 ;
return;
}
if ( V_14 < V_206 )
V_189 = V_190 [ V_14 ] ;
else if ( V_14 >= V_207 && V_14 <= V_208 )
V_189 = F_30 ( F_136 ( V_209 , V_14 - V_207 + 1 ) ) ;
else
return;
type = F_31 ( V_189 ) ;
if ( type < 0xf0 ) {
V_194 . V_90 = V_189 ;
V_195 = F_135 ( & V_3 ,
V_210 , & V_194 ) ;
if ( V_195 != V_204 )
if ( V_187 && ! V_191 )
F_27 ( V_38 , V_189 ) ;
return;
}
type -= 0xf0 ;
if ( type == V_211 ) {
type = V_212 ;
if ( F_93 ( V_64 , V_68 ) ) {
V_190 = V_51 [ V_192 ^ ( 1 << V_104 ) ] ;
if ( V_190 )
V_189 = V_190 [ V_14 ] ;
}
}
V_194 . V_90 = V_189 ;
V_195 = F_135 ( & V_3 ,
V_213 , & V_194 ) ;
if ( V_195 == V_204 )
return;
if ( ( V_191 || V_64 -> V_65 == V_95 ) && type != V_214 && type != V_52 )
return;
(* F_137 [ type ])( V_38 , V_189 & 0xff , ! V_187 ) ;
V_194 . V_146 = V_64 -> V_171 ;
F_135 ( & V_3 , V_215 , & V_194 ) ;
if ( type != V_53 )
V_64 -> V_132 = 0 ;
}
static void F_138 ( struct V_4 * V_5 , unsigned int V_216 ,
unsigned int V_217 , int V_90 )
{
F_71 ( & V_56 ) ;
if ( V_216 == V_218 && V_217 == V_219 && F_139 ( V_5 -> V_9 ) )
F_126 ( V_90 ) ;
if ( V_216 == V_220 )
F_127 ( V_217 , V_90 , F_139 ( V_5 -> V_9 ) ) ;
F_74 ( & V_56 ) ;
F_140 ( & V_145 ) ;
V_221 = 1 ;
F_141 () ;
}
static bool F_142 ( struct V_222 * V_223 , struct V_18 * V_9 )
{
int V_58 ;
if ( F_14 ( V_19 , V_9 -> V_20 ) )
return true ;
if ( F_14 ( V_220 , V_9 -> V_20 ) ) {
for ( V_58 = V_224 ; V_58 < V_199 ; V_58 ++ )
if ( F_14 ( V_58 , V_9 -> V_225 ) )
return true ;
for ( V_58 = V_207 ; V_58 <= V_226 ; V_58 ++ )
if ( F_14 ( V_58 , V_9 -> V_225 ) )
return true ;
}
return false ;
}
static int F_143 ( struct V_222 * V_223 , struct V_18 * V_9 ,
const struct V_227 * V_228 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_144 ( sizeof( struct V_4 ) , V_229 ) ;
if ( ! V_5 )
return - V_230 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_223 = V_223 ;
V_5 -> V_155 = L_9 ;
error = F_145 ( V_5 ) ;
if ( error )
goto V_231;
error = F_146 ( V_5 ) ;
if ( error )
goto V_232;
return 0 ;
V_232:
F_147 ( V_5 ) ;
V_231:
F_148 ( V_5 ) ;
return error ;
}
static void F_149 ( struct V_4 * V_5 )
{
F_150 ( V_5 ) ;
F_147 ( V_5 ) ;
F_148 ( V_5 ) ;
}
static void F_151 ( struct V_4 * V_5 )
{
F_109 ( & V_145 ) ;
if ( V_146 != - 1U )
F_113 ( V_5 , & V_146 ) ;
F_111 ( & V_145 ) ;
}
int T_2 F_152 ( void )
{
int V_58 ;
int error ;
for ( V_58 = 0 ; V_58 < V_80 ; V_58 ++ ) {
V_170 [ V_58 ] . V_171 = F_1 () ;
V_170 [ V_58 ] . V_233 = F_1 () ;
V_170 [ V_58 ] . V_167 = V_169 ;
V_170 [ V_58 ] . V_131 = V_234 ;
V_170 [ V_58 ] . V_132 = 0 ;
V_170 [ V_58 ] . V_235 = V_236 ;
V_170 [ V_58 ] . V_65 = V_237 ? V_66 : V_238 ;
}
F_114 () ;
error = F_153 ( & V_16 ) ;
if ( error )
return error ;
F_111 ( & V_145 ) ;
F_140 ( & V_145 ) ;
return 0 ;
}
int F_154 ( unsigned int V_239 , void T_3 * V_240 , int V_241 )
{
unsigned long V_12 ;
int V_242 ;
int V_174 = 0 ;
switch ( V_239 ) {
case V_243 :
{
struct V_244 T_3 * V_245 = V_240 ;
struct V_246 * V_247 ;
int V_58 ;
V_247 = F_155 ( V_248 * sizeof( struct V_246 ) ,
V_229 ) ;
if ( ! V_247 )
return - V_230 ;
F_35 ( & V_56 , V_12 ) ;
V_242 = V_60 ;
for ( V_58 = 0 ; V_58 < V_242 ; V_58 ++ ) {
V_247 [ V_58 ] . V_57 = F_38 (
V_61 [ V_58 ] . V_57 ) ;
V_247 [ V_58 ] . V_62 = F_38 (
V_61 [ V_58 ] . V_62 ) ;
V_247 [ V_58 ] . V_63 = F_38 (
V_61 [ V_58 ] . V_63 ) ;
}
F_36 ( & V_56 , V_12 ) ;
if ( F_156 ( V_242 , & V_245 -> V_249 ) )
V_174 = - V_250 ;
else if ( F_157 ( V_245 -> V_246 , V_247 ,
V_242 * sizeof( struct V_246 ) ) )
V_174 = - V_250 ;
F_148 ( V_247 ) ;
return V_174 ;
}
case V_251 :
{
struct V_252 T_3 * V_245 = V_240 ;
void * V_44 ;
V_44 = F_155 ( V_248 * sizeof( struct V_253 ) ,
V_229 ) ;
if ( V_44 == NULL )
return - V_230 ;
F_35 ( & V_56 , V_12 ) ;
V_242 = V_60 ;
memcpy ( V_44 , V_61 , V_242 * sizeof( struct V_253 ) ) ;
F_36 ( & V_56 , V_12 ) ;
if ( F_156 ( V_242 , & V_245 -> V_249 ) )
V_174 = - V_250 ;
else if ( F_157 ( V_245 -> V_253 , V_44 ,
V_242 * sizeof( struct V_253 ) ) )
V_174 = - V_250 ;
F_148 ( V_44 ) ;
return V_174 ;
}
case V_254 :
{
struct V_244 T_3 * V_245 = V_240 ;
struct V_246 * V_247 = NULL ;
unsigned int V_255 ;
int V_58 ;
if ( ! V_241 )
return - V_256 ;
if ( F_158 ( V_255 , & V_245 -> V_249 ) )
return - V_250 ;
if ( V_255 >= V_248 )
return - V_257 ;
if ( V_255 ) {
V_247 = F_159 ( V_245 -> V_246 ,
sizeof( struct V_246 ) * V_255 ) ;
if ( F_160 ( V_247 ) )
return F_161 ( V_247 ) ;
}
F_35 ( & V_56 , V_12 ) ;
V_60 = V_255 ;
for ( V_58 = 0 ; V_58 < V_255 ; V_58 ++ ) {
V_61 [ V_58 ] . V_57 =
F_86 ( V_247 [ V_58 ] . V_57 ) ;
V_61 [ V_58 ] . V_62 =
F_86 ( V_247 [ V_58 ] . V_62 ) ;
V_61 [ V_58 ] . V_63 =
F_86 ( V_247 [ V_58 ] . V_63 ) ;
}
F_36 ( & V_56 , V_12 ) ;
F_148 ( V_247 ) ;
return 0 ;
}
case V_258 :
{
struct V_252 T_3 * V_245 = V_240 ;
unsigned int V_255 ;
void * V_44 = NULL ;
if ( ! V_241 )
return - V_256 ;
if ( F_158 ( V_255 , & V_245 -> V_249 ) )
return - V_250 ;
if ( V_255 >= V_248 )
return - V_257 ;
if ( V_255 ) {
V_44 = F_155 ( V_255 * sizeof( struct V_253 ) ,
V_229 ) ;
if ( V_44 == NULL )
return - V_230 ;
if ( F_162 ( V_44 , V_245 -> V_253 ,
V_255 * sizeof( struct V_253 ) ) ) {
F_148 ( V_44 ) ;
return - V_250 ;
}
}
F_35 ( & V_56 , V_12 ) ;
if ( V_255 )
memcpy ( V_61 , V_44 ,
V_255 * sizeof( struct V_253 ) ) ;
V_60 = V_255 ;
F_36 ( & V_56 , V_12 ) ;
F_148 ( V_44 ) ;
return 0 ;
}
}
return V_174 ;
}
int F_163 ( int V_172 , unsigned int V_259 )
{
struct V_162 * V_163 = V_170 + V_172 ;
int V_174 = 0 ;
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
switch( V_259 ) {
case V_260 :
V_163 -> V_65 = V_93 ;
break;
case V_261 :
V_163 -> V_65 = V_94 ;
break;
case V_262 :
V_163 -> V_65 = V_238 ;
F_28 () ;
break;
case V_263 :
V_163 -> V_65 = V_66 ;
F_28 () ;
break;
case V_264 :
V_163 -> V_65 = V_95 ;
break;
default:
V_174 = - V_257 ;
}
F_36 ( & V_56 , V_12 ) ;
return V_174 ;
}
int F_164 ( int V_172 , unsigned int V_259 )
{
struct V_162 * V_163 = V_170 + V_172 ;
int V_174 = 0 ;
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
switch( V_259 ) {
case V_265 :
F_165 ( V_163 , V_130 ) ;
break;
case V_266 :
F_166 ( V_163 , V_130 ) ;
break;
default:
V_174 = - V_257 ;
}
F_36 ( & V_56 , V_12 ) ;
return V_174 ;
}
int F_167 ( int V_239 , struct V_267 T_3 * V_268 ,
int V_241 )
{
struct V_267 V_269 ;
int V_270 = 0 ;
if ( F_162 ( & V_269 , V_268 , sizeof( struct V_267 ) ) )
return - V_250 ;
switch ( V_239 ) {
case V_271 :
V_270 = F_8 ( V_269 . V_11 ) ;
if ( V_270 >= 0 )
V_270 = F_156 ( V_270 , & V_268 -> V_14 ) ;
break;
case V_272 :
if ( ! V_241 )
return - V_256 ;
V_270 = F_12 ( V_269 . V_11 , V_269 . V_14 ) ;
break;
}
return V_270 ;
}
int F_168 ( int V_239 , struct V_273 T_3 * V_274 , int V_241 ,
int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
struct V_273 V_269 ;
T_4 * V_190 , * V_275 , V_48 , V_276 ;
unsigned long V_12 ;
if ( F_162 ( & V_269 , V_274 , sizeof( struct V_273 ) ) )
return - V_250 ;
if ( ! F_169 ( V_277 ) )
V_241 = 0 ;
switch ( V_239 ) {
case V_278 :
F_35 ( & V_56 , V_12 ) ;
V_190 = V_51 [ V_279 ] ;
if ( V_190 ) {
V_48 = F_30 ( V_190 [ V_58 ] ) ;
if ( V_163 -> V_65 != V_66 && F_31 ( V_48 ) >= V_280 )
V_48 = V_281 ;
} else
V_48 = ( V_58 ? V_281 : V_282 ) ;
F_36 ( & V_56 , V_12 ) ;
return F_156 ( V_48 , & V_274 -> V_283 ) ;
case V_284 :
if ( ! V_241 )
return - V_256 ;
if ( ! V_58 && V_285 == V_282 ) {
F_35 ( & V_56 , V_12 ) ;
V_190 = V_51 [ V_279 ] ;
if ( V_279 && V_190 ) {
V_51 [ V_279 ] = NULL ;
if ( V_190 [ 0 ] == F_30 ( V_286 ) ) {
F_148 ( V_190 ) ;
V_287 -- ;
}
}
F_36 ( & V_56 , V_12 ) ;
break;
}
if ( F_31 ( V_285 ) < V_280 ) {
if ( F_32 ( V_285 ) > V_288 [ F_31 ( V_285 ) ] )
return - V_257 ;
} else
if ( V_163 -> V_65 != V_66 )
return - V_257 ;
#if ! F_170 ( V_289 ) && ! F_170 ( V_290 )
if ( ! V_58 )
break;
#endif
V_275 = F_155 ( sizeof( V_291 ) , V_229 ) ;
if ( ! V_275 )
return - V_230 ;
F_35 ( & V_56 , V_12 ) ;
V_190 = V_51 [ V_279 ] ;
if ( V_190 == NULL ) {
int V_292 ;
if ( V_287 >= V_293 &&
! F_169 ( V_294 ) ) {
F_36 ( & V_56 , V_12 ) ;
F_148 ( V_275 ) ;
return - V_256 ;
}
V_51 [ V_279 ] = V_275 ;
V_190 = V_275 ;
V_190 [ 0 ] = F_30 ( V_286 ) ;
for ( V_292 = 1 ; V_292 < V_206 ; V_292 ++ )
V_190 [ V_292 ] = F_30 ( V_281 ) ;
V_287 ++ ;
} else
F_148 ( V_275 ) ;
V_276 = F_30 ( V_190 [ V_58 ] ) ;
if ( V_285 == V_276 )
goto V_295;
if ( ( ( V_276 == V_96 ) || ( V_285 == V_96 ) ) && ! F_169 ( V_296 ) ) {
F_36 ( & V_56 , V_12 ) ;
return - V_256 ;
}
V_190 [ V_58 ] = F_30 ( V_285 ) ;
if ( ! V_279 && ( F_31 ( V_276 ) == V_52 || F_31 ( V_285 ) == V_52 ) )
F_28 () ;
V_295:
F_36 ( & V_56 , V_12 ) ;
break;
}
return 0 ;
}
int F_171 ( int V_239 , struct V_297 T_3 * V_298 , int V_241 )
{
struct V_297 * V_299 ;
char * V_300 ;
T_5 * V_301 ;
T_5 T_3 * V_302 ;
int V_303 ;
int V_304 ;
char * V_305 , * V_306 , * V_307 ;
int V_58 , V_292 , V_46 ;
int V_174 ;
if ( ! F_169 ( V_277 ) )
V_241 = 0 ;
V_299 = F_155 ( sizeof( * V_299 ) , V_229 ) ;
if ( ! V_299 ) {
V_174 = - V_230 ;
goto V_308;
}
if ( F_162 ( V_299 , V_298 , sizeof( struct V_297 ) ) ) {
V_174 = - V_250 ;
goto V_308;
}
V_299 -> V_309 [ sizeof( V_299 -> V_309 ) - 1 ] = '\0' ;
V_58 = V_299 -> V_310 ;
switch ( V_239 ) {
case V_311 :
V_303 = sizeof( V_299 -> V_309 ) - 1 ;
V_302 = V_298 -> V_309 ;
V_300 = V_99 [ V_58 ] ;
if( V_300 )
for ( ; * V_300 && V_303 ; V_300 ++ , V_303 -- )
if ( F_156 ( * V_300 , V_302 ++ ) ) {
V_174 = - V_250 ;
goto V_308;
}
if ( F_156 ( '\0' , V_302 ) ) {
V_174 = - V_250 ;
goto V_308;
}
F_148 ( V_299 ) ;
return ( ( V_300 && * V_300 ) ? - V_312 : 0 ) ;
case V_313 :
if ( ! V_241 ) {
V_174 = - V_256 ;
goto V_308;
}
V_301 = V_99 [ V_58 ] ;
V_305 = V_314 + ( V_315 - V_316 ) ;
for ( V_292 = V_58 + 1 ; V_292 < V_317 && ! V_99 [ V_292 ] ; V_292 ++ )
;
if ( V_292 < V_317 )
V_306 = V_99 [ V_292 ] ;
else
V_306 = V_305 ;
V_304 = ( V_301 ? - strlen ( V_301 ) : 1 ) + strlen ( V_299 -> V_309 ) ;
if ( V_304 <= V_316 ) {
if ( V_292 < V_317 ) {
memmove ( V_306 + V_304 , V_306 , V_305 - V_306 ) ;
for ( V_46 = V_292 ; V_46 < V_317 ; V_46 ++ )
if ( V_99 [ V_46 ] )
V_99 [ V_46 ] += V_304 ;
}
if ( ! V_301 )
V_99 [ V_58 ] = V_306 ;
V_316 -= V_304 ;
} else {
V_303 = 256 ;
while ( V_303 < V_315 - V_316 + V_304 )
V_303 <<= 1 ;
V_307 = F_155 ( V_303 , V_229 ) ;
if( ! V_307 ) {
V_174 = - V_230 ;
goto V_308;
}
if ( ! V_301 )
V_99 [ V_58 ] = V_306 ;
if ( V_306 > V_314 )
memmove ( V_307 , V_314 , V_306 - V_314 ) ;
for ( V_46 = 0 ; V_46 < V_292 ; V_46 ++ )
if ( V_99 [ V_46 ] )
V_99 [ V_46 ] = V_307 + ( V_99 [ V_46 ] - V_314 ) ;
if ( V_305 > V_306 ) {
memmove ( V_307 + ( V_306 - V_314 ) + V_304 , V_306 , V_305 - V_306 ) ;
for ( V_46 = V_292 ; V_46 < V_317 ; V_46 ++ )
if ( V_99 [ V_46 ] )
V_99 [ V_46 ] = V_307 + ( V_99 [ V_46 ] - V_314 ) + V_304 ;
}
if ( V_314 != V_318 )
F_148 ( V_314 ) ;
V_314 = V_307 ;
V_316 = V_316 - V_304 + V_303 - V_315 ;
V_315 = V_303 ;
}
strcpy ( V_99 [ V_58 ] , V_299 -> V_309 ) ;
break;
}
V_174 = 0 ;
V_308:
F_148 ( V_299 ) ;
return V_174 ;
}
int F_172 ( int V_172 , int V_239 , unsigned long V_259 , int V_241 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
unsigned char V_319 ;
switch( V_239 ) {
case V_320 :
F_35 ( & V_56 , V_12 ) ;
V_319 = V_163 -> V_171 | ( V_163 -> V_233 << 4 ) ;
F_36 ( & V_56 , V_12 ) ;
return F_156 ( V_319 , ( char T_3 * ) V_259 ) ;
case V_321 :
if ( ! V_241 )
return - V_256 ;
if ( V_259 & ~ 0x77 )
return - V_257 ;
F_35 ( & V_165 , V_12 ) ;
V_163 -> V_171 = ( V_259 & 7 ) ;
V_163 -> V_233 = ( ( V_259 >> 4 ) & 7 ) ;
F_118 () ;
F_36 ( & V_165 , V_12 ) ;
return 0 ;
case V_322 :
V_319 = F_116 () ;
return F_156 ( V_319 , ( char T_3 * ) V_259 ) ;
case V_323 :
if ( ! V_241 )
return - V_256 ;
F_117 ( V_163 , V_259 ) ;
return 0 ;
}
return - V_324 ;
}
int F_173 ( int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
switch ( V_163 -> V_65 ) {
case V_93 :
return V_260 ;
case V_94 :
return V_261 ;
case V_66 :
return V_263 ;
case V_95 :
return V_264 ;
default:
return V_262 ;
}
}
int F_174 ( int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
return F_40 ( V_163 , V_130 ) ? V_266 : V_265 ;
}
void F_175 ( int V_172 )
{
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
V_170 [ V_172 ] . V_65 = V_237 ? V_66 : V_238 ;
F_36 ( & V_56 , V_12 ) ;
}
int F_176 ( void )
{
return V_49 ;
}
void F_177 ( int V_172 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
F_166 ( V_163 , V_201 ) ;
F_165 ( V_163 , V_101 ) ;
F_165 ( V_163 , V_74 ) ;
F_165 ( V_163 , V_67 ) ;
V_163 -> V_131 = 0 ;
V_163 -> V_132 = 0 ;
F_71 ( & V_165 ) ;
V_163 -> V_167 = V_169 ;
V_163 -> V_171 = V_163 -> V_233 ;
F_74 ( & V_165 ) ;
F_36 ( & V_56 , V_12 ) ;
}
int F_178 ( int V_172 , int V_325 )
{
struct V_162 * V_163 = V_170 + V_172 ;
return F_40 ( V_163 , V_325 ) ;
}
void F_179 ( int V_172 , int V_325 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
F_166 ( V_163 , V_325 ) ;
F_36 ( & V_56 , V_12 ) ;
}
void F_180 ( int V_172 , int V_325 )
{
struct V_162 * V_163 = V_170 + V_172 ;
unsigned long V_12 ;
F_35 ( & V_56 , V_12 ) ;
F_165 ( V_163 , V_325 ) ;
F_36 ( & V_56 , V_12 ) ;
}
