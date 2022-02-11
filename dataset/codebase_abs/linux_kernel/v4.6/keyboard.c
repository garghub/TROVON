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
unsigned int V_46 , V_47 , V_48 , V_49 , V_50 ;
V_51 = 0 ;
memset ( V_52 , 0 , sizeof( V_52 ) ) ;
for ( V_46 = 0 ; V_46 < F_29 ( V_53 ) ; V_46 ++ ) {
if ( ! V_53 [ V_46 ] )
continue;
V_48 = V_46 * V_54 ;
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ , V_48 ++ ) {
if ( ! F_14 ( V_48 , V_53 ) )
continue;
V_49 = F_30 ( V_55 [ 0 ] [ V_48 ] ) ;
if ( F_31 ( V_49 ) != V_56 && F_31 ( V_49 ) != V_57 )
continue;
V_50 = F_32 ( V_49 ) ;
if ( V_50 == F_32 ( V_58 ) )
V_50 = F_32 ( V_59 ) ;
V_52 [ V_50 ] ++ ;
V_51 |= ( 1 << V_50 ) ;
}
}
}
void F_33 ( void )
{
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_28 () ;
F_35 ( & V_60 , V_12 ) ;
}
static unsigned int F_36 ( struct V_37 * V_38 , unsigned int V_39 )
{
unsigned int V_8 = V_61 ;
unsigned int V_46 ;
V_61 = 0 ;
if ( ( V_8 & ~ 0xff ) == V_62 ) {
if ( ( V_39 & ~ 0xff ) == V_62 )
return V_8 | V_39 ;
} else {
for ( V_46 = 0 ; V_46 < V_63 ; V_46 ++ )
if ( V_64 [ V_46 ] . V_61 == V_8 && V_64 [ V_46 ] . V_65 == V_39 )
return V_64 [ V_46 ] . V_66 ;
}
if ( V_39 == ' ' || V_39 == ( V_62 | 0 ) || V_39 == V_8 )
return V_8 ;
if ( V_67 -> V_68 == V_69 )
F_27 ( V_38 , V_8 ) ;
else {
int V_45 = F_37 ( V_8 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
return V_39 ;
}
static void F_38 ( struct V_37 * V_38 )
{
if ( V_61 ) {
if ( V_67 -> V_68 == V_69 )
F_27 ( V_38 , V_61 ) ;
else {
int V_45 = F_37 ( V_61 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
V_61 = 0 ;
}
F_22 ( V_38 , 13 ) ;
if ( F_39 ( V_67 , V_70 ) )
F_22 ( V_38 , 10 ) ;
}
static void F_40 ( struct V_37 * V_38 )
{
if ( V_36 )
return;
F_41 ( V_67 , V_71 ) ;
}
static void F_42 ( struct V_37 * V_38 )
{
if ( V_36 )
return;
F_43 ( V_67 , V_71 ) ;
}
static void F_44 ( struct V_37 * V_38 )
{
struct V_72 * V_73 = F_45 () ;
if ( V_73 )
F_46 ( V_73 ) ;
}
static void F_47 ( struct V_37 * V_38 )
{
struct V_74 * V_75 = V_38 -> V_40 . V_75 ;
if ( V_36 || ! V_75 )
return;
if ( V_75 -> V_76 )
F_48 ( V_75 ) ;
else
F_49 ( V_75 ) ;
}
static void F_50 ( struct V_37 * V_38 )
{
if ( F_39 ( V_67 , V_77 ) )
F_26 ( V_38 , 'P' , 1 ) ;
else
F_51 ( V_38 ) ;
}
static void F_51 ( struct V_37 * V_38 )
{
if ( ! V_36 )
F_41 ( V_67 , V_78 ) ;
}
static void F_52 ( struct V_37 * V_38 )
{
F_53 ( V_79 ) ;
}
static void F_54 ( struct V_37 * V_38 )
{
int V_46 , V_80 = V_81 ;
if ( V_82 != - 1 )
V_80 = V_82 ;
for ( V_46 = V_80 - 1 ; V_46 != V_80 ; V_46 -- ) {
if ( V_46 == - 1 )
V_46 = V_83 - 1 ;
if ( F_55 ( V_46 ) )
break;
}
F_53 ( V_46 ) ;
}
static void F_56 ( struct V_37 * V_38 )
{
int V_46 , V_80 = V_81 ;
if ( V_82 != - 1 )
V_80 = V_82 ;
for ( V_46 = V_80 + 1 ; V_46 != V_80 ; V_46 ++ ) {
if ( V_46 == V_83 )
V_46 = 0 ;
if ( F_55 ( V_46 ) )
break;
}
F_53 ( V_46 ) ;
}
static void F_57 ( struct V_37 * V_38 )
{
F_23 ( & V_38 -> V_40 , 0 , V_84 ) ;
F_24 ( & V_38 -> V_40 ) ;
}
static void F_58 ( struct V_37 * V_38 )
{
F_59 ( V_38 , 0 ) ;
}
static void F_60 ( struct V_37 * V_38 )
{
F_61 ( V_38 , 0 ) ;
}
static void F_62 ( struct V_37 * V_38 )
{
F_63 ( 0 ) ;
}
static void F_64 ( struct V_37 * V_38 )
{
F_65 () ;
}
static void F_66 ( struct V_37 * V_38 )
{
F_67 () ;
}
static void F_68 ( struct V_37 * V_38 )
{
V_85 = true ;
}
static void F_69 ( struct V_37 * V_38 )
{
F_70 ( & V_86 . V_87 ) ;
if ( V_86 . V_88 )
if ( F_71 ( V_86 . V_88 , V_86 . V_89 , 1 ) ) {
F_72 ( V_86 . V_88 ) ;
V_86 . V_88 = NULL ;
}
F_73 ( & V_86 . V_87 ) ;
}
static void F_74 ( struct V_37 * V_38 )
{
struct V_90 * V_91 = & V_92 [ V_81 ] . V_91 ;
F_75 ( V_91 ) ;
}
static void F_76 ( struct V_37 * V_38 )
{
F_28 () ;
}
static void F_77 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
}
static void F_78 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
if ( V_94 )
return;
if ( V_93 >= F_29 ( V_95 ) )
return;
if ( ( V_67 -> V_68 == V_96 ||
V_67 -> V_68 == V_97 ||
V_67 -> V_68 == V_98 ) &&
V_93 != F_32 ( V_99 ) )
return;
V_95 [ V_93 ] ( V_38 ) ;
}
static void F_79 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
F_80 ( L_1 ) ;
}
static void F_81 ( struct V_37 * V_38 , unsigned int V_93 , char V_94 )
{
if ( V_94 )
return;
if ( V_61 )
V_93 = F_36 ( V_38 , V_93 ) ;
if ( V_85 ) {
V_85 = false ;
V_61 = V_93 ;
return;
}
if ( V_67 -> V_68 == V_69 )
F_27 ( V_38 , V_93 ) ;
else {
int V_45 = F_37 ( V_93 ) ;
if ( V_45 != - 1 )
F_22 ( V_38 , V_45 ) ;
}
}
static void F_82 ( struct V_37 * V_38 , unsigned int V_93 , char V_94 )
{
if ( V_94 )
return;
V_61 = ( V_61 ? F_36 ( V_38 , V_93 ) : V_93 ) ;
}
static void F_83 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
F_81 ( V_38 , F_84 ( V_93 ) , V_94 ) ;
}
static void F_85 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
F_82 ( V_38 , V_93 , V_94 ) ;
}
static void F_86 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
static const unsigned char V_100 [ V_101 ] = { '`' , '\'' , '^' , '~' , '"' , ',' } ;
F_82 ( V_38 , V_100 [ V_93 ] , V_94 ) ;
}
static void F_87 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
if ( V_94 )
return;
F_53 ( V_93 ) ;
}
static void F_88 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
if ( V_94 )
return;
if ( ( unsigned ) V_93 < F_29 ( V_102 ) ) {
if ( V_102 [ V_93 ] )
F_25 ( V_38 , V_102 [ V_93 ] ) ;
} else
F_80 ( L_2 , V_93 ) ;
}
static void F_89 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
static const char V_103 [] = L_3 ;
if ( V_94 )
return;
F_26 ( V_38 , V_103 [ V_93 ] , F_39 ( V_67 , V_104 ) ) ;
}
static void F_90 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
static const char V_105 [] = L_4 ;
static const char V_106 [] = L_5 ;
if ( V_94 )
return;
if ( F_39 ( V_67 , V_77 ) && ! V_52 [ V_107 ] ) {
F_26 ( V_38 , V_106 [ V_93 ] , 1 ) ;
return;
}
if ( ! F_91 ( V_67 , V_78 ) ) {
switch ( V_93 ) {
case F_32 ( V_108 ) :
case F_32 ( V_109 ) :
F_88 ( V_38 , F_32 ( V_110 ) , 0 ) ;
return;
case F_32 ( V_111 ) :
F_88 ( V_38 , F_32 ( V_112 ) , 0 ) ;
return;
case F_32 ( V_113 ) :
F_88 ( V_38 , F_32 ( V_114 ) , 0 ) ;
return;
case F_32 ( V_115 ) :
F_89 ( V_38 , F_32 ( V_116 ) , 0 ) ;
return;
case F_32 ( V_117 ) :
F_88 ( V_38 , F_32 ( V_118 ) , 0 ) ;
return;
case F_32 ( V_119 ) :
F_89 ( V_38 , F_32 ( V_120 ) , 0 ) ;
return;
case F_32 ( V_121 ) :
F_89 ( V_38 , F_32 ( V_122 ) , 0 ) ;
return;
case F_32 ( V_123 ) :
F_88 ( V_38 , F_32 ( V_124 ) , 0 ) ;
return;
case F_32 ( V_125 ) :
F_89 ( V_38 , F_32 ( V_126 ) , 0 ) ;
return;
case F_32 ( V_127 ) :
F_88 ( V_38 , F_32 ( V_128 ) , 0 ) ;
return;
case F_32 ( V_129 ) :
F_26 ( V_38 , 'G' , F_39 ( V_67 , V_77 ) ) ;
return;
}
}
F_22 ( V_38 , V_105 [ V_93 ] ) ;
if ( V_93 == F_32 ( V_130 ) && F_39 ( V_67 , V_70 ) )
F_22 ( V_38 , 10 ) ;
}
static void F_92 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
int V_131 = V_51 ;
if ( V_36 )
return;
if ( V_93 == F_32 ( V_58 ) ) {
V_93 = F_32 ( V_59 ) ;
if ( ! V_94 )
F_93 ( V_67 , V_71 ) ;
}
if ( V_94 ) {
if ( V_52 [ V_93 ] )
V_52 [ V_93 ] -- ;
} else
V_52 [ V_93 ] ++ ;
if ( V_52 [ V_93 ] )
V_51 |= ( 1 << V_93 ) ;
else
V_51 &= ~ ( 1 << V_93 ) ;
if ( V_94 && V_51 != V_131 && V_132 != - 1 ) {
if ( V_67 -> V_68 == V_69 )
F_27 ( V_38 , V_132 ) ;
else
F_22 ( V_38 , V_132 & 0xff ) ;
V_132 = - 1 ;
}
}
static void F_94 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
if ( V_94 )
return;
if ( F_39 ( V_67 , V_133 ) ) {
F_22 ( V_38 , '\033' ) ;
F_22 ( V_38 , V_93 ) ;
} else
F_22 ( V_38 , V_93 | 0x80 ) ;
}
static void F_95 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
int V_65 ;
if ( V_94 )
return;
if ( V_93 < 10 ) {
V_65 = 10 ;
} else {
V_93 -= 10 ;
V_65 = 16 ;
}
if ( V_132 == - 1 )
V_132 = V_93 ;
else
V_132 = V_132 * V_65 + V_93 ;
}
static void F_96 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
if ( V_94 || V_36 )
return;
F_97 ( V_67 , V_93 ) ;
}
static void F_98 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
F_92 ( V_38 , V_93 , V_94 ) ;
if ( V_94 || V_36 )
return;
F_99 ( V_67 , V_93 ) ;
if ( ! V_55 [ V_67 -> V_134 ^ V_67 -> V_135 ] ) {
V_67 -> V_135 = 0 ;
F_99 ( V_67 , V_93 ) ;
}
}
static void F_100 ( struct V_37 * V_38 , unsigned int V_136 , char V_94 )
{
static unsigned long V_137 ;
static unsigned V_138 ;
if ( ! V_139 )
F_82 ( V_38 , V_62 | V_136 , V_94 ) ;
else {
V_138 |= V_136 ;
V_137 ++ ;
if ( V_137 == V_139 ) {
F_81 ( V_38 , V_62 | V_138 , V_94 ) ;
V_137 = 0 ;
V_138 = 0 ;
}
}
}
static void F_101 ( struct V_37 * V_38 , unsigned char V_93 , char V_94 )
{
static unsigned V_140 , V_141 ;
static unsigned long V_142 ;
if ( V_67 -> V_68 != V_69 ) {
if ( ! V_94 )
F_102 ( L_6 ) ;
return;
}
if ( ! V_93 ) {
F_81 ( V_38 , V_62 , V_94 ) ;
return;
}
if ( V_93 > 8 )
return;
if ( ! V_94 ) {
V_140 |= 1 << ( V_93 - 1 ) ;
if ( ! V_143 )
V_141 = V_140 ;
} else if ( V_143 ) {
if ( ! V_141 ||
F_103 ( V_28 ,
V_142 + F_104 ( V_143 ) ) ) {
V_141 = V_140 ;
V_142 = V_28 ;
}
V_140 &= ~ ( 1 << ( V_93 - 1 ) ) ;
if ( ! V_140 && V_141 ) {
F_100 ( V_38 , V_141 , 0 ) ;
V_141 = 0 ;
}
} else {
if ( V_141 ) {
F_100 ( V_38 , V_141 , 0 ) ;
V_141 = 0 ;
}
V_140 &= ~ ( 1 << ( V_93 - 1 ) ) ;
}
}
static void F_105 ( struct V_144 * V_145 )
{
struct V_146 * V_147 =
F_106 ( V_145 -> V_147 , struct V_146 , V_147 ) ;
F_107 ( & V_148 ) ;
if ( V_149 != - 1U )
F_108 ( & V_147 -> V_147 ,
V_149 & V_147 -> V_150 ?
V_151 : V_152 ) ;
F_109 ( & V_148 ) ;
}
static void F_110 ( unsigned int V_131 ,
unsigned int V_153 )
{
struct V_146 * V_147 ;
unsigned int V_154 = V_131 ^ V_153 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_29 ( V_155 ) ; V_46 ++ ) {
V_147 = & V_155 [ V_46 ] ;
if ( V_154 & V_147 -> V_150 )
F_108 ( & V_147 -> V_147 ,
V_153 & V_147 -> V_150 ?
V_151 : V_152 ) ;
}
}
static int F_111 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int V_156 = * ( unsigned int * ) V_6 ;
if ( F_14 ( V_157 , V_5 -> V_9 -> V_20 ) )
F_110 ( ~ V_156 , V_156 ) ;
return 0 ;
}
static void F_112 ( void )
{
int error ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_29 ( V_155 ) ; V_46 ++ ) {
error = F_113 ( & V_155 [ V_46 ] . V_147 ) ;
if ( error )
F_80 ( L_7 ,
error , V_155 [ V_46 ] . V_147 . V_158 ) ;
}
}
static int F_111 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int V_159 = * ( unsigned int * ) V_6 ;
if ( F_14 ( V_157 , V_5 -> V_9 -> V_20 ) ) {
F_15 ( V_5 , V_157 , V_160 , ! ! ( V_159 & 0x01 ) ) ;
F_15 ( V_5 , V_157 , V_161 , ! ! ( V_159 & 0x02 ) ) ;
F_15 ( V_5 , V_157 , V_162 , ! ! ( V_159 & 0x04 ) ) ;
F_15 ( V_5 , V_163 , V_164 , 0 ) ;
}
return 0 ;
}
static void F_110 ( unsigned int V_131 ,
unsigned int V_153 )
{
F_9 ( & V_16 , & V_153 ,
F_111 ) ;
}
static void F_112 ( void )
{
}
static unsigned char F_114 ( void )
{
return V_149 & 0xff ;
}
void F_115 ( struct V_165 * V_166 , unsigned int V_167 )
{
unsigned long V_12 ;
F_34 ( & V_168 , V_12 ) ;
if ( ! ( V_167 & ~ 7 ) ) {
V_169 = V_167 ;
V_166 -> V_170 = V_171 ;
} else
V_166 -> V_170 = V_172 ;
F_116 () ;
F_35 ( & V_168 , V_12 ) ;
}
static inline unsigned char F_117 ( void )
{
struct V_165 * V_166 = V_173 + V_81 ;
if ( V_166 -> V_170 == V_171 )
return V_169 ;
return V_166 -> V_174 ;
}
int F_118 ( int V_175 , int V_176 )
{
struct V_165 * V_166 = V_173 + V_175 ;
int V_177 ;
unsigned long V_12 ;
F_34 ( & V_168 , V_12 ) ;
V_177 = F_91 ( V_166 , V_176 ) ;
F_35 ( & V_168 , V_12 ) ;
return V_177 ;
}
void F_119 ( int V_175 , int V_159 )
{
struct V_165 * V_166 = V_173 + V_175 ;
F_115 ( V_166 , V_159 ) ;
}
void F_120 ( int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
F_34 ( & V_168 , V_12 ) ;
F_93 ( V_166 , V_178 ) ;
F_116 () ;
F_35 ( & V_168 , V_12 ) ;
}
void F_121 ( int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
F_34 ( & V_168 , V_12 ) ;
F_43 ( V_166 , V_178 ) ;
F_116 () ;
F_35 ( & V_168 , V_12 ) ;
}
static void F_122 ( unsigned long V_179 )
{
unsigned int V_159 ;
unsigned long V_12 ;
F_34 ( & V_168 , V_12 ) ;
V_159 = F_117 () ;
V_159 |= ( unsigned int ) V_67 -> V_134 << 8 ;
F_35 ( & V_168 , V_12 ) ;
if ( V_159 != V_149 ) {
F_110 ( V_149 , V_159 ) ;
V_149 = V_159 ;
}
}
static int F_123 ( struct V_37 * V_38 , unsigned int V_14 ,
unsigned char V_94 )
{
int V_180 ;
switch ( V_14 ) {
case V_181 :
F_22 ( V_38 , 0xe1 ) ;
F_22 ( V_38 , 0x1d | V_94 ) ;
F_22 ( V_38 , 0x45 | V_94 ) ;
break;
case V_182 :
if ( ! V_94 )
F_22 ( V_38 , 0xf2 ) ;
break;
case V_183 :
if ( ! V_94 )
F_22 ( V_38 , 0xf1 ) ;
break;
case V_184 :
if ( F_14 ( V_185 , V_53 ) ||
F_14 ( V_186 , V_53 ) ) {
F_22 ( V_38 , 0x54 | V_94 ) ;
} else {
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , 0x2a | V_94 ) ;
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , 0x37 | V_94 ) ;
}
break;
default:
if ( V_14 > 255 )
return - 1 ;
V_180 = V_187 [ V_14 ] ;
if ( ! V_180 )
return - 1 ;
if ( V_180 & 0x100 )
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , ( V_180 & 0x7f ) | V_94 ) ;
break;
}
return 0 ;
}
static int F_123 ( struct V_37 * V_38 , unsigned int V_14 , unsigned char V_94 )
{
if ( V_14 > 127 )
return - 1 ;
F_22 ( V_38 , V_14 | V_94 ) ;
return 0 ;
}
static void F_124 ( unsigned char V_6 )
{
struct V_37 * V_38 = V_92 [ V_81 ] . V_8 ;
V_67 = V_173 + V_38 -> V_188 ;
if ( V_67 -> V_68 == V_96 )
F_22 ( V_38 , V_6 ) ;
}
static void F_125 ( unsigned int V_14 , int V_189 , int V_190 )
{
struct V_37 * V_38 = V_92 [ V_81 ] . V_8 ;
unsigned short V_191 , * V_192 ;
unsigned char type ;
bool V_193 ;
struct V_74 * V_75 ;
int V_194 ;
struct V_195 V_196 = { . V_38 = V_38 , . V_93 = V_14 , . V_189 = V_189 } ;
int V_197 ;
V_75 = V_38 -> V_40 . V_75 ;
if ( V_75 && ( ! V_75 -> V_198 ) ) {
V_75 -> V_198 = V_38 ;
}
V_67 = V_173 + V_38 -> V_188 ;
#ifdef F_126
if ( V_14 == V_199 )
V_200 = V_189 ;
#endif
V_36 = ( V_189 == 2 ) ;
V_193 = ( V_67 -> V_68 == V_96 ) ;
if ( V_193 && ! V_190 )
if ( F_123 ( V_38 , V_14 , ! V_189 << 7 ) )
if ( V_14 < V_201 && F_127 () )
F_102 ( L_8 ,
V_14 ) ;
#ifdef F_126
if ( V_14 == V_202 && V_200 ) {
V_200 = false ;
F_128 () ;
}
#endif
if ( V_67 -> V_68 == V_97 ) {
if ( V_14 < 128 ) {
F_22 ( V_38 , V_14 | ( ! V_189 << 7 ) ) ;
} else {
F_22 ( V_38 , ! V_189 << 7 ) ;
F_22 ( V_38 , ( V_14 >> 7 ) | 0x80 ) ;
F_22 ( V_38 , V_14 | 0x80 ) ;
}
V_193 = true ;
}
if ( V_189 )
F_129 ( V_14 , V_53 ) ;
else
F_130 ( V_14 , V_53 ) ;
if ( V_36 &&
( ! F_39 ( V_67 , V_203 ) ||
( V_75 && ! F_131 ( V_75 ) && F_132 ( V_75 ) ) ) ) {
return;
}
V_196 . V_204 = V_194 = ( V_51 | V_67 -> V_135 ) ^ V_67 -> V_134 ;
V_196 . V_149 = V_67 -> V_174 ;
V_192 = V_55 [ V_194 ] ;
V_197 = F_133 ( & V_3 ,
V_205 , & V_196 ) ;
if ( V_197 == V_206 || ! V_192 ) {
F_133 ( & V_3 ,
V_207 , & V_196 ) ;
F_28 () ;
V_67 -> V_135 = 0 ;
return;
}
if ( V_14 < V_208 )
V_191 = V_192 [ V_14 ] ;
else if ( V_14 >= V_209 && V_14 <= V_210 )
V_191 = F_30 ( F_134 ( V_211 , V_14 - V_209 + 1 ) ) ;
else
return;
type = F_31 ( V_191 ) ;
if ( type < 0xf0 ) {
V_196 . V_93 = V_191 ;
V_197 = F_133 ( & V_3 ,
V_212 , & V_196 ) ;
if ( V_197 != V_206 )
if ( V_189 && ! V_193 )
F_27 ( V_38 , V_191 ) ;
return;
}
type -= 0xf0 ;
if ( type == V_213 ) {
type = V_214 ;
if ( F_91 ( V_67 , V_71 ) ) {
V_192 = V_55 [ V_194 ^ ( 1 << V_107 ) ] ;
if ( V_192 )
V_191 = V_192 [ V_14 ] ;
}
}
V_196 . V_93 = V_191 ;
V_197 = F_133 ( & V_3 ,
V_215 , & V_196 ) ;
if ( V_197 == V_206 )
return;
if ( ( V_193 || V_67 -> V_68 == V_98 ) && type != V_216 && type != V_56 )
return;
(* F_135 [ type ])( V_38 , V_191 & 0xff , ! V_189 ) ;
V_196 . V_149 = V_67 -> V_174 ;
F_133 ( & V_3 , V_217 , & V_196 ) ;
if ( type != V_57 )
V_67 -> V_135 = 0 ;
}
static void F_136 ( struct V_4 * V_5 , unsigned int V_218 ,
unsigned int V_219 , int V_93 )
{
F_70 ( & V_60 ) ;
if ( V_218 == V_220 && V_219 == V_221 && F_137 ( V_5 -> V_9 ) )
F_124 ( V_93 ) ;
if ( V_218 == V_222 )
F_125 ( V_219 , V_93 , F_137 ( V_5 -> V_9 ) ) ;
F_73 ( & V_60 ) ;
F_138 ( & V_148 ) ;
V_223 = 1 ;
F_139 () ;
}
static bool F_140 ( struct V_224 * V_225 , struct V_18 * V_9 )
{
int V_46 ;
if ( F_14 ( V_19 , V_9 -> V_20 ) )
return true ;
if ( F_14 ( V_222 , V_9 -> V_20 ) ) {
for ( V_46 = V_226 ; V_46 < V_201 ; V_46 ++ )
if ( F_14 ( V_46 , V_9 -> V_227 ) )
return true ;
for ( V_46 = V_209 ; V_46 <= V_228 ; V_46 ++ )
if ( F_14 ( V_46 , V_9 -> V_227 ) )
return true ;
}
return false ;
}
static int F_141 ( struct V_224 * V_225 , struct V_18 * V_9 ,
const struct V_229 * V_230 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_142 ( sizeof( struct V_4 ) , V_231 ) ;
if ( ! V_5 )
return - V_232 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_225 = V_225 ;
V_5 -> V_158 = L_9 ;
error = F_143 ( V_5 ) ;
if ( error )
goto V_233;
error = F_144 ( V_5 ) ;
if ( error )
goto V_234;
return 0 ;
V_234:
F_145 ( V_5 ) ;
V_233:
F_146 ( V_5 ) ;
return error ;
}
static void F_147 ( struct V_4 * V_5 )
{
F_148 ( V_5 ) ;
F_145 ( V_5 ) ;
F_146 ( V_5 ) ;
}
static void F_149 ( struct V_4 * V_5 )
{
F_107 ( & V_148 ) ;
if ( V_149 != - 1U )
F_111 ( V_5 , & V_149 ) ;
F_109 ( & V_148 ) ;
}
int T_2 F_150 ( void )
{
int V_46 ;
int error ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
V_173 [ V_46 ] . V_174 = F_1 () ;
V_173 [ V_46 ] . V_235 = F_1 () ;
V_173 [ V_46 ] . V_170 = V_172 ;
V_173 [ V_46 ] . V_134 = V_236 ;
V_173 [ V_46 ] . V_135 = 0 ;
V_173 [ V_46 ] . V_237 = V_238 ;
V_173 [ V_46 ] . V_68 = V_239 ? V_69 : V_240 ;
}
F_112 () ;
error = F_151 ( & V_16 ) ;
if ( error )
return error ;
F_109 ( & V_148 ) ;
F_138 ( & V_148 ) ;
return 0 ;
}
int F_152 ( unsigned int V_241 , void T_3 * V_242 , int V_243 )
{
unsigned long V_12 ;
int V_244 ;
int V_177 = 0 ;
switch ( V_241 ) {
case V_245 :
{
struct V_246 T_3 * V_247 = V_242 ;
struct V_248 * V_249 ;
int V_46 ;
V_249 = F_153 ( V_250 * sizeof( struct V_248 ) ,
V_231 ) ;
if ( ! V_249 )
return - V_232 ;
F_34 ( & V_60 , V_12 ) ;
V_244 = V_63 ;
for ( V_46 = 0 ; V_46 < V_244 ; V_46 ++ ) {
V_249 [ V_46 ] . V_61 = F_37 (
V_64 [ V_46 ] . V_61 ) ;
V_249 [ V_46 ] . V_65 = F_37 (
V_64 [ V_46 ] . V_65 ) ;
V_249 [ V_46 ] . V_66 = F_37 (
V_64 [ V_46 ] . V_66 ) ;
}
F_35 ( & V_60 , V_12 ) ;
if ( F_154 ( V_244 , & V_247 -> V_251 ) )
V_177 = - V_252 ;
else if ( F_155 ( V_247 -> V_248 , V_249 ,
V_244 * sizeof( struct V_248 ) ) )
V_177 = - V_252 ;
F_146 ( V_249 ) ;
return V_177 ;
}
case V_253 :
{
struct V_254 T_3 * V_247 = V_242 ;
void * V_44 ;
V_44 = F_153 ( V_250 * sizeof( struct V_255 ) ,
V_231 ) ;
if ( V_44 == NULL )
return - V_232 ;
F_34 ( & V_60 , V_12 ) ;
V_244 = V_63 ;
memcpy ( V_44 , V_64 , V_244 * sizeof( struct V_255 ) ) ;
F_35 ( & V_60 , V_12 ) ;
if ( F_154 ( V_244 , & V_247 -> V_251 ) )
V_177 = - V_252 ;
else if ( F_155 ( V_247 -> V_255 , V_44 ,
V_244 * sizeof( struct V_255 ) ) )
V_177 = - V_252 ;
F_146 ( V_44 ) ;
return V_177 ;
}
case V_256 :
{
struct V_246 T_3 * V_247 = V_242 ;
struct V_248 * V_249 = NULL ;
unsigned int V_257 ;
int V_46 ;
if ( ! V_243 )
return - V_258 ;
if ( F_156 ( V_257 , & V_247 -> V_251 ) )
return - V_252 ;
if ( V_257 >= V_250 )
return - V_259 ;
if ( V_257 ) {
V_249 = F_157 ( V_247 -> V_248 ,
sizeof( struct V_248 ) * V_257 ) ;
if ( F_158 ( V_249 ) )
return F_159 ( V_249 ) ;
}
F_34 ( & V_60 , V_12 ) ;
V_63 = V_257 ;
for ( V_46 = 0 ; V_46 < V_257 ; V_46 ++ ) {
V_64 [ V_46 ] . V_61 =
F_84 ( V_249 [ V_46 ] . V_61 ) ;
V_64 [ V_46 ] . V_65 =
F_84 ( V_249 [ V_46 ] . V_65 ) ;
V_64 [ V_46 ] . V_66 =
F_84 ( V_249 [ V_46 ] . V_66 ) ;
}
F_35 ( & V_60 , V_12 ) ;
F_146 ( V_249 ) ;
return 0 ;
}
case V_260 :
{
struct V_254 T_3 * V_247 = V_242 ;
unsigned int V_257 ;
void * V_44 = NULL ;
if ( ! V_243 )
return - V_258 ;
if ( F_156 ( V_257 , & V_247 -> V_251 ) )
return - V_252 ;
if ( V_257 >= V_250 )
return - V_259 ;
if ( V_257 ) {
V_44 = F_153 ( V_257 * sizeof( struct V_255 ) ,
V_231 ) ;
if ( V_44 == NULL )
return - V_232 ;
if ( F_160 ( V_44 , V_247 -> V_255 ,
V_257 * sizeof( struct V_255 ) ) ) {
F_146 ( V_44 ) ;
return - V_252 ;
}
}
F_34 ( & V_60 , V_12 ) ;
if ( V_257 )
memcpy ( V_64 , V_44 ,
V_257 * sizeof( struct V_255 ) ) ;
V_63 = V_257 ;
F_35 ( & V_60 , V_12 ) ;
F_146 ( V_44 ) ;
return 0 ;
}
}
return V_177 ;
}
int F_161 ( int V_175 , unsigned int V_261 )
{
struct V_165 * V_166 = V_173 + V_175 ;
int V_177 = 0 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
switch( V_261 ) {
case V_262 :
V_166 -> V_68 = V_96 ;
break;
case V_263 :
V_166 -> V_68 = V_97 ;
break;
case V_264 :
V_166 -> V_68 = V_240 ;
F_28 () ;
break;
case V_265 :
V_166 -> V_68 = V_69 ;
F_28 () ;
break;
case V_266 :
V_166 -> V_68 = V_98 ;
break;
default:
V_177 = - V_259 ;
}
F_35 ( & V_60 , V_12 ) ;
return V_177 ;
}
int F_162 ( int V_175 , unsigned int V_261 )
{
struct V_165 * V_166 = V_173 + V_175 ;
int V_177 = 0 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
switch( V_261 ) {
case V_267 :
F_163 ( V_166 , V_133 ) ;
break;
case V_268 :
F_164 ( V_166 , V_133 ) ;
break;
default:
V_177 = - V_259 ;
}
F_35 ( & V_60 , V_12 ) ;
return V_177 ;
}
int F_165 ( int V_241 , struct V_269 T_3 * V_270 ,
int V_243 )
{
struct V_269 V_271 ;
int V_272 = 0 ;
if ( F_160 ( & V_271 , V_270 , sizeof( struct V_269 ) ) )
return - V_252 ;
switch ( V_241 ) {
case V_273 :
V_272 = F_8 ( V_271 . V_11 ) ;
if ( V_272 >= 0 )
V_272 = F_154 ( V_272 , & V_270 -> V_14 ) ;
break;
case V_274 :
if ( ! V_243 )
return - V_258 ;
V_272 = F_12 ( V_271 . V_11 , V_271 . V_14 ) ;
break;
}
return V_272 ;
}
int F_166 ( int V_241 , struct V_275 T_3 * V_276 , int V_243 ,
int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
struct V_275 V_271 ;
T_4 * V_192 , * V_277 , V_50 , V_278 ;
unsigned long V_12 ;
if ( F_160 ( & V_271 , V_276 , sizeof( struct V_275 ) ) )
return - V_252 ;
if ( ! F_167 ( V_279 ) )
V_243 = 0 ;
switch ( V_241 ) {
case V_280 :
F_34 ( & V_60 , V_12 ) ;
V_192 = V_55 [ V_281 ] ;
if ( V_192 ) {
V_50 = F_30 ( V_192 [ V_46 ] ) ;
if ( V_166 -> V_68 != V_69 && F_31 ( V_50 ) >= V_282 )
V_50 = V_283 ;
} else
V_50 = ( V_46 ? V_283 : V_284 ) ;
F_35 ( & V_60 , V_12 ) ;
return F_154 ( V_50 , & V_276 -> V_285 ) ;
case V_286 :
if ( ! V_243 )
return - V_258 ;
if ( ! V_46 && V_287 == V_284 ) {
F_34 ( & V_60 , V_12 ) ;
V_192 = V_55 [ V_281 ] ;
if ( V_281 && V_192 ) {
V_55 [ V_281 ] = NULL ;
if ( V_192 [ 0 ] == F_30 ( V_288 ) ) {
F_146 ( V_192 ) ;
V_289 -- ;
}
}
F_35 ( & V_60 , V_12 ) ;
break;
}
if ( F_31 ( V_287 ) < V_282 ) {
if ( F_32 ( V_287 ) > V_290 [ F_31 ( V_287 ) ] )
return - V_259 ;
} else
if ( V_166 -> V_68 != V_69 )
return - V_259 ;
#if ! F_168 ( V_291 ) && ! F_168 ( V_292 )
if ( ! V_46 )
break;
#endif
V_277 = F_153 ( sizeof( V_293 ) , V_231 ) ;
if ( ! V_277 )
return - V_232 ;
F_34 ( & V_60 , V_12 ) ;
V_192 = V_55 [ V_281 ] ;
if ( V_192 == NULL ) {
int V_47 ;
if ( V_289 >= V_294 &&
! F_167 ( V_295 ) ) {
F_35 ( & V_60 , V_12 ) ;
F_146 ( V_277 ) ;
return - V_258 ;
}
V_55 [ V_281 ] = V_277 ;
V_192 = V_277 ;
V_192 [ 0 ] = F_30 ( V_288 ) ;
for ( V_47 = 1 ; V_47 < V_208 ; V_47 ++ )
V_192 [ V_47 ] = F_30 ( V_283 ) ;
V_289 ++ ;
} else
F_146 ( V_277 ) ;
V_278 = F_30 ( V_192 [ V_46 ] ) ;
if ( V_287 == V_278 )
goto V_296;
if ( ( ( V_278 == V_99 ) || ( V_287 == V_99 ) ) && ! F_167 ( V_297 ) ) {
F_35 ( & V_60 , V_12 ) ;
return - V_258 ;
}
V_192 [ V_46 ] = F_30 ( V_287 ) ;
if ( ! V_281 && ( F_31 ( V_278 ) == V_56 || F_31 ( V_287 ) == V_56 ) )
F_28 () ;
V_296:
F_35 ( & V_60 , V_12 ) ;
break;
}
return 0 ;
}
int F_169 ( int V_241 , struct V_298 T_3 * V_299 , int V_243 )
{
struct V_298 * V_300 ;
char * V_301 ;
T_5 * V_302 ;
T_5 T_3 * V_303 ;
int V_304 ;
int V_305 ;
char * V_306 , * V_307 , * V_308 ;
int V_46 , V_47 , V_48 ;
int V_177 ;
if ( ! F_167 ( V_279 ) )
V_243 = 0 ;
V_300 = F_153 ( sizeof( * V_300 ) , V_231 ) ;
if ( ! V_300 ) {
V_177 = - V_232 ;
goto V_309;
}
if ( F_160 ( V_300 , V_299 , sizeof( struct V_298 ) ) ) {
V_177 = - V_252 ;
goto V_309;
}
V_300 -> V_310 [ sizeof( V_300 -> V_310 ) - 1 ] = '\0' ;
V_46 = V_300 -> V_311 ;
switch ( V_241 ) {
case V_312 :
V_304 = sizeof( V_300 -> V_310 ) - 1 ;
V_303 = V_299 -> V_310 ;
V_301 = V_102 [ V_46 ] ;
if( V_301 )
for ( ; * V_301 && V_304 ; V_301 ++ , V_304 -- )
if ( F_154 ( * V_301 , V_303 ++ ) ) {
V_177 = - V_252 ;
goto V_309;
}
if ( F_154 ( '\0' , V_303 ) ) {
V_177 = - V_252 ;
goto V_309;
}
F_146 ( V_300 ) ;
return ( ( V_301 && * V_301 ) ? - V_313 : 0 ) ;
case V_314 :
if ( ! V_243 ) {
V_177 = - V_258 ;
goto V_309;
}
V_302 = V_102 [ V_46 ] ;
V_306 = V_315 + ( V_316 - V_317 ) ;
for ( V_47 = V_46 + 1 ; V_47 < V_318 && ! V_102 [ V_47 ] ; V_47 ++ )
;
if ( V_47 < V_318 )
V_307 = V_102 [ V_47 ] ;
else
V_307 = V_306 ;
V_305 = ( V_302 ? - strlen ( V_302 ) : 1 ) + strlen ( V_300 -> V_310 ) ;
if ( V_305 <= V_317 ) {
if ( V_47 < V_318 ) {
memmove ( V_307 + V_305 , V_307 , V_306 - V_307 ) ;
for ( V_48 = V_47 ; V_48 < V_318 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] += V_305 ;
}
if ( ! V_302 )
V_102 [ V_46 ] = V_307 ;
V_317 -= V_305 ;
} else {
V_304 = 256 ;
while ( V_304 < V_316 - V_317 + V_305 )
V_304 <<= 1 ;
V_308 = F_153 ( V_304 , V_231 ) ;
if( ! V_308 ) {
V_177 = - V_232 ;
goto V_309;
}
if ( ! V_302 )
V_102 [ V_46 ] = V_307 ;
if ( V_307 > V_315 )
memmove ( V_308 , V_315 , V_307 - V_315 ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] = V_308 + ( V_102 [ V_48 ] - V_315 ) ;
if ( V_306 > V_307 ) {
memmove ( V_308 + ( V_307 - V_315 ) + V_305 , V_307 , V_306 - V_307 ) ;
for ( V_48 = V_47 ; V_48 < V_318 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] = V_308 + ( V_102 [ V_48 ] - V_315 ) + V_305 ;
}
if ( V_315 != V_319 )
F_146 ( V_315 ) ;
V_315 = V_308 ;
V_317 = V_317 - V_305 + V_304 - V_316 ;
V_316 = V_304 ;
}
strcpy ( V_102 [ V_46 ] , V_300 -> V_310 ) ;
break;
}
V_177 = 0 ;
V_309:
F_146 ( V_300 ) ;
return V_177 ;
}
int F_170 ( int V_175 , int V_241 , unsigned long V_261 , int V_243 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
unsigned char V_320 ;
switch( V_241 ) {
case V_321 :
F_34 ( & V_60 , V_12 ) ;
V_320 = V_166 -> V_174 | ( V_166 -> V_235 << 4 ) ;
F_35 ( & V_60 , V_12 ) ;
return F_154 ( V_320 , ( char T_3 * ) V_261 ) ;
case V_322 :
if ( ! V_243 )
return - V_258 ;
if ( V_261 & ~ 0x77 )
return - V_259 ;
F_34 ( & V_168 , V_12 ) ;
V_166 -> V_174 = ( V_261 & 7 ) ;
V_166 -> V_235 = ( ( V_261 >> 4 ) & 7 ) ;
F_116 () ;
F_35 ( & V_168 , V_12 ) ;
return 0 ;
case V_323 :
V_320 = F_114 () ;
return F_154 ( V_320 , ( char T_3 * ) V_261 ) ;
case V_324 :
if ( ! V_243 )
return - V_258 ;
F_115 ( V_166 , V_261 ) ;
return 0 ;
}
return - V_325 ;
}
int F_171 ( int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
switch ( V_166 -> V_68 ) {
case V_96 :
return V_262 ;
case V_97 :
return V_263 ;
case V_69 :
return V_265 ;
case V_98 :
return V_266 ;
default:
return V_264 ;
}
}
int F_172 ( int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
return F_39 ( V_166 , V_133 ) ? V_268 : V_267 ;
}
void F_173 ( int V_175 )
{
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
V_173 [ V_175 ] . V_68 = V_239 ? V_69 : V_240 ;
F_35 ( & V_60 , V_12 ) ;
}
int F_174 ( void )
{
return V_51 ;
}
void F_175 ( int V_175 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_164 ( V_166 , V_203 ) ;
F_163 ( V_166 , V_104 ) ;
F_163 ( V_166 , V_77 ) ;
F_163 ( V_166 , V_70 ) ;
V_166 -> V_134 = 0 ;
V_166 -> V_135 = 0 ;
F_70 ( & V_168 ) ;
V_166 -> V_170 = V_172 ;
V_166 -> V_174 = V_166 -> V_235 ;
F_73 ( & V_168 ) ;
F_35 ( & V_60 , V_12 ) ;
}
int F_176 ( int V_175 , int V_326 )
{
struct V_165 * V_166 = V_173 + V_175 ;
return F_39 ( V_166 , V_326 ) ;
}
void F_177 ( int V_175 , int V_326 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_164 ( V_166 , V_326 ) ;
F_35 ( & V_60 , V_12 ) ;
}
void F_178 ( int V_175 , int V_326 )
{
struct V_165 * V_166 = V_173 + V_175 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_163 ( V_166 , V_326 ) ;
F_35 ( & V_60 , V_12 ) ;
}
