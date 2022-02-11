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
static unsigned char F_105 ( void )
{
return V_144 ;
}
void F_106 ( struct V_145 * V_146 , unsigned int V_147 )
{
unsigned long V_12 ;
F_34 ( & V_148 , V_12 ) ;
if ( ! ( V_147 & ~ 7 ) ) {
V_149 = V_147 ;
V_146 -> V_150 = V_151 ;
} else
V_146 -> V_150 = V_152 ;
F_107 () ;
F_35 ( & V_148 , V_12 ) ;
}
static inline unsigned char F_108 ( void )
{
struct V_145 * V_146 = V_153 + V_81 ;
if ( V_146 -> V_150 == V_151 )
return V_149 ;
return V_146 -> V_154 ;
}
static int F_109 ( struct V_4 * V_5 , void * V_6 )
{
unsigned char V_155 = * ( unsigned char * ) V_6 ;
if ( F_14 ( V_156 , V_5 -> V_9 -> V_20 ) ) {
F_15 ( V_5 , V_156 , V_157 , ! ! ( V_155 & 0x01 ) ) ;
F_15 ( V_5 , V_156 , V_158 , ! ! ( V_155 & 0x02 ) ) ;
F_15 ( V_5 , V_156 , V_159 , ! ! ( V_155 & 0x04 ) ) ;
F_15 ( V_5 , V_160 , V_161 , 0 ) ;
}
return 0 ;
}
int F_110 ( int V_162 , int V_163 )
{
struct V_145 * V_146 = V_153 + V_162 ;
int V_164 ;
unsigned long V_12 ;
F_34 ( & V_148 , V_12 ) ;
V_164 = F_91 ( V_146 , V_163 ) ;
F_35 ( & V_148 , V_12 ) ;
return V_164 ;
}
void F_111 ( int V_162 , int V_155 )
{
struct V_145 * V_146 = V_153 + V_162 ;
F_106 ( V_146 , V_155 ) ;
}
void F_112 ( int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
F_34 ( & V_148 , V_12 ) ;
F_93 ( V_146 , V_165 ) ;
F_107 () ;
F_35 ( & V_148 , V_12 ) ;
}
void F_113 ( int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
F_34 ( & V_148 , V_12 ) ;
F_43 ( V_146 , V_165 ) ;
F_107 () ;
F_35 ( & V_148 , V_12 ) ;
}
static void F_114 ( unsigned long V_166 )
{
unsigned char V_155 ;
unsigned long V_12 ;
F_34 ( & V_148 , V_12 ) ;
V_155 = F_108 () ;
F_35 ( & V_148 , V_12 ) ;
if ( V_155 != V_144 ) {
F_9 ( & V_16 , & V_155 ,
F_109 ) ;
V_144 = V_155 ;
}
}
static int F_115 ( struct V_37 * V_38 , unsigned int V_14 ,
unsigned char V_94 )
{
int V_167 ;
switch ( V_14 ) {
case V_168 :
F_22 ( V_38 , 0xe1 ) ;
F_22 ( V_38 , 0x1d | V_94 ) ;
F_22 ( V_38 , 0x45 | V_94 ) ;
break;
case V_169 :
if ( ! V_94 )
F_22 ( V_38 , 0xf2 ) ;
break;
case V_170 :
if ( ! V_94 )
F_22 ( V_38 , 0xf1 ) ;
break;
case V_171 :
if ( F_14 ( V_172 , V_53 ) ||
F_14 ( V_173 , V_53 ) ) {
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
V_167 = V_174 [ V_14 ] ;
if ( ! V_167 )
return - 1 ;
if ( V_167 & 0x100 )
F_22 ( V_38 , 0xe0 ) ;
F_22 ( V_38 , ( V_167 & 0x7f ) | V_94 ) ;
break;
}
return 0 ;
}
static int F_115 ( struct V_37 * V_38 , unsigned int V_14 , unsigned char V_94 )
{
if ( V_14 > 127 )
return - 1 ;
F_22 ( V_38 , V_14 | V_94 ) ;
return 0 ;
}
static void F_116 ( unsigned char V_6 )
{
struct V_37 * V_38 = V_92 [ V_81 ] . V_8 ;
V_67 = V_153 + V_38 -> V_175 ;
if ( V_67 -> V_68 == V_96 )
F_22 ( V_38 , V_6 ) ;
}
static void F_117 ( unsigned int V_14 , int V_176 , int V_177 )
{
struct V_37 * V_38 = V_92 [ V_81 ] . V_8 ;
unsigned short V_178 , * V_179 ;
unsigned char type ;
bool V_180 ;
struct V_74 * V_75 ;
int V_181 ;
struct V_182 V_183 = { . V_38 = V_38 , . V_93 = V_14 , . V_176 = V_176 } ;
int V_184 ;
V_75 = V_38 -> V_40 . V_75 ;
if ( V_75 && ( ! V_75 -> V_185 ) ) {
V_75 -> V_185 = V_38 ;
}
V_67 = V_153 + V_38 -> V_175 ;
#ifdef F_118
if ( V_14 == V_186 )
V_187 = V_176 ;
#endif
V_36 = ( V_176 == 2 ) ;
V_180 = ( V_67 -> V_68 == V_96 ) ;
if ( V_180 && ! V_177 )
if ( F_115 ( V_38 , V_14 , ! V_176 << 7 ) )
if ( V_14 < V_188 && F_119 () )
F_102 ( L_7 ,
V_14 ) ;
#ifdef F_118
if ( V_14 == V_189 && V_187 ) {
V_187 = false ;
F_120 () ;
}
#endif
if ( V_67 -> V_68 == V_97 ) {
if ( V_14 < 128 ) {
F_22 ( V_38 , V_14 | ( ! V_176 << 7 ) ) ;
} else {
F_22 ( V_38 , ! V_176 << 7 ) ;
F_22 ( V_38 , ( V_14 >> 7 ) | 0x80 ) ;
F_22 ( V_38 , V_14 | 0x80 ) ;
}
V_180 = true ;
}
if ( V_176 )
F_121 ( V_14 , V_53 ) ;
else
F_122 ( V_14 , V_53 ) ;
if ( V_36 &&
( ! F_39 ( V_67 , V_190 ) ||
( V_75 && ! F_123 ( V_75 ) && F_124 ( V_75 ) ) ) ) {
return;
}
V_183 . V_191 = V_181 = ( V_51 | V_67 -> V_135 ) ^ V_67 -> V_134 ;
V_183 . V_144 = V_67 -> V_154 ;
V_179 = V_55 [ V_181 ] ;
V_184 = F_125 ( & V_3 ,
V_192 , & V_183 ) ;
if ( V_184 == V_193 || ! V_179 ) {
F_125 ( & V_3 ,
V_194 , & V_183 ) ;
F_28 () ;
V_67 -> V_135 = 0 ;
return;
}
if ( V_14 < V_195 )
V_178 = V_179 [ V_14 ] ;
else if ( V_14 >= V_196 && V_14 <= V_197 )
V_178 = F_30 ( F_126 ( V_198 , V_14 - V_196 + 1 ) ) ;
else
return;
type = F_31 ( V_178 ) ;
if ( type < 0xf0 ) {
V_183 . V_93 = V_178 ;
V_184 = F_125 ( & V_3 ,
V_199 , & V_183 ) ;
if ( V_184 != V_193 )
if ( V_176 && ! V_180 )
F_27 ( V_38 , V_178 ) ;
return;
}
type -= 0xf0 ;
if ( type == V_200 ) {
type = V_201 ;
if ( F_91 ( V_67 , V_71 ) ) {
V_179 = V_55 [ V_181 ^ ( 1 << V_107 ) ] ;
if ( V_179 )
V_178 = V_179 [ V_14 ] ;
}
}
V_183 . V_93 = V_178 ;
V_184 = F_125 ( & V_3 ,
V_202 , & V_183 ) ;
if ( V_184 == V_193 )
return;
if ( ( V_180 || V_67 -> V_68 == V_98 ) && type != V_203 && type != V_56 )
return;
(* F_127 [ type ])( V_38 , V_178 & 0xff , ! V_176 ) ;
V_183 . V_144 = V_67 -> V_154 ;
F_125 ( & V_3 , V_204 , & V_183 ) ;
if ( type != V_57 )
V_67 -> V_135 = 0 ;
}
static void F_128 ( struct V_4 * V_5 , unsigned int V_205 ,
unsigned int V_206 , int V_93 )
{
F_70 ( & V_60 ) ;
if ( V_205 == V_207 && V_206 == V_208 && F_129 ( V_5 -> V_9 ) )
F_116 ( V_93 ) ;
if ( V_205 == V_209 )
F_117 ( V_206 , V_93 , F_129 ( V_5 -> V_9 ) ) ;
F_73 ( & V_60 ) ;
F_130 ( & V_210 ) ;
V_211 = 1 ;
F_131 () ;
}
static bool F_132 ( struct V_212 * V_213 , struct V_18 * V_9 )
{
int V_46 ;
if ( F_14 ( V_19 , V_9 -> V_20 ) )
return true ;
if ( F_14 ( V_209 , V_9 -> V_20 ) ) {
for ( V_46 = V_214 ; V_46 < V_188 ; V_46 ++ )
if ( F_14 ( V_46 , V_9 -> V_215 ) )
return true ;
for ( V_46 = V_196 ; V_46 <= V_216 ; V_46 ++ )
if ( F_14 ( V_46 , V_9 -> V_215 ) )
return true ;
}
return false ;
}
static int F_133 ( struct V_212 * V_213 , struct V_18 * V_9 ,
const struct V_217 * V_218 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_134 ( sizeof( struct V_4 ) , V_219 ) ;
if ( ! V_5 )
return - V_220 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_213 = V_213 ;
V_5 -> V_221 = L_8 ;
error = F_135 ( V_5 ) ;
if ( error )
goto V_222;
error = F_136 ( V_5 ) ;
if ( error )
goto V_223;
return 0 ;
V_223:
F_137 ( V_5 ) ;
V_222:
F_138 ( V_5 ) ;
return error ;
}
static void F_139 ( struct V_4 * V_5 )
{
F_140 ( V_5 ) ;
F_137 ( V_5 ) ;
F_138 ( V_5 ) ;
}
static void F_141 ( struct V_4 * V_5 )
{
F_142 ( & V_210 ) ;
if ( V_144 != 0xff )
F_109 ( V_5 , & V_144 ) ;
F_143 ( & V_210 ) ;
}
int T_2 F_144 ( void )
{
int V_46 ;
int error ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
V_153 [ V_46 ] . V_154 = F_1 () ;
V_153 [ V_46 ] . V_224 = F_1 () ;
V_153 [ V_46 ] . V_150 = V_152 ;
V_153 [ V_46 ] . V_134 = V_225 ;
V_153 [ V_46 ] . V_135 = 0 ;
V_153 [ V_46 ] . V_226 = V_227 ;
V_153 [ V_46 ] . V_68 = V_228 ? V_69 : V_229 ;
}
error = F_145 ( & V_16 ) ;
if ( error )
return error ;
F_143 ( & V_210 ) ;
F_130 ( & V_210 ) ;
return 0 ;
}
int F_146 ( unsigned int V_230 , void T_3 * V_231 , int V_232 )
{
unsigned long V_12 ;
int V_233 ;
int V_164 = 0 ;
switch ( V_230 ) {
case V_234 :
{
struct V_235 T_3 * V_236 = V_231 ;
struct V_237 * V_238 ;
int V_46 ;
V_238 = F_147 ( V_239 * sizeof( struct V_237 ) ,
V_219 ) ;
if ( ! V_238 )
return - V_220 ;
F_34 ( & V_60 , V_12 ) ;
V_233 = V_63 ;
for ( V_46 = 0 ; V_46 < V_233 ; V_46 ++ ) {
V_238 [ V_46 ] . V_61 = F_37 (
V_64 [ V_46 ] . V_61 ) ;
V_238 [ V_46 ] . V_65 = F_37 (
V_64 [ V_46 ] . V_65 ) ;
V_238 [ V_46 ] . V_66 = F_37 (
V_64 [ V_46 ] . V_66 ) ;
}
F_35 ( & V_60 , V_12 ) ;
if ( F_148 ( V_233 , & V_236 -> V_240 ) )
V_164 = - V_241 ;
else if ( F_149 ( V_236 -> V_237 , V_238 ,
V_233 * sizeof( struct V_237 ) ) )
V_164 = - V_241 ;
F_138 ( V_238 ) ;
return V_164 ;
}
case V_242 :
{
struct V_243 T_3 * V_236 = V_231 ;
void * V_44 ;
V_44 = F_147 ( V_239 * sizeof( struct V_244 ) ,
V_219 ) ;
if ( V_44 == NULL )
return - V_220 ;
F_34 ( & V_60 , V_12 ) ;
V_233 = V_63 ;
memcpy ( V_44 , V_64 , V_233 * sizeof( struct V_244 ) ) ;
F_35 ( & V_60 , V_12 ) ;
if ( F_148 ( V_233 , & V_236 -> V_240 ) )
V_164 = - V_241 ;
else if ( F_149 ( V_236 -> V_244 , V_44 ,
V_233 * sizeof( struct V_244 ) ) )
V_164 = - V_241 ;
F_138 ( V_44 ) ;
return V_164 ;
}
case V_245 :
{
struct V_235 T_3 * V_236 = V_231 ;
struct V_237 * V_238 = NULL ;
unsigned int V_246 ;
int V_46 ;
if ( ! V_232 )
return - V_247 ;
if ( F_150 ( V_246 , & V_236 -> V_240 ) )
return - V_241 ;
if ( V_246 >= V_239 )
return - V_248 ;
if ( V_246 ) {
V_238 = F_147 ( sizeof( struct V_237 ) * V_246 ,
V_219 ) ;
if ( ! V_238 )
return - V_220 ;
if ( F_151 ( V_238 , V_236 -> V_237 ,
sizeof( struct V_237 ) * V_246 ) ) {
F_138 ( V_238 ) ;
return - V_241 ;
}
}
F_34 ( & V_60 , V_12 ) ;
V_63 = V_246 ;
for ( V_46 = 0 ; V_46 < V_246 ; V_46 ++ ) {
V_64 [ V_46 ] . V_61 =
F_84 ( V_238 [ V_46 ] . V_61 ) ;
V_64 [ V_46 ] . V_65 =
F_84 ( V_238 [ V_46 ] . V_65 ) ;
V_64 [ V_46 ] . V_66 =
F_84 ( V_238 [ V_46 ] . V_66 ) ;
}
F_35 ( & V_60 , V_12 ) ;
F_138 ( V_238 ) ;
return 0 ;
}
case V_249 :
{
struct V_243 T_3 * V_236 = V_231 ;
unsigned int V_246 ;
void * V_44 = NULL ;
if ( ! V_232 )
return - V_247 ;
if ( F_150 ( V_246 , & V_236 -> V_240 ) )
return - V_241 ;
if ( V_246 >= V_239 )
return - V_248 ;
if ( V_246 ) {
V_44 = F_147 ( V_246 * sizeof( struct V_244 ) ,
V_219 ) ;
if ( V_44 == NULL )
return - V_220 ;
if ( F_151 ( V_44 , V_236 -> V_244 ,
V_246 * sizeof( struct V_244 ) ) ) {
F_138 ( V_44 ) ;
return - V_241 ;
}
}
F_34 ( & V_60 , V_12 ) ;
if ( V_246 )
memcpy ( V_64 , V_44 ,
V_246 * sizeof( struct V_244 ) ) ;
V_63 = V_246 ;
F_35 ( & V_60 , V_12 ) ;
F_138 ( V_44 ) ;
return 0 ;
}
}
return V_164 ;
}
int F_152 ( int V_162 , unsigned int V_250 )
{
struct V_145 * V_146 = V_153 + V_162 ;
int V_164 = 0 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
switch( V_250 ) {
case V_251 :
V_146 -> V_68 = V_96 ;
break;
case V_252 :
V_146 -> V_68 = V_97 ;
break;
case V_253 :
V_146 -> V_68 = V_229 ;
F_28 () ;
break;
case V_254 :
V_146 -> V_68 = V_69 ;
F_28 () ;
break;
case V_255 :
V_146 -> V_68 = V_98 ;
break;
default:
V_164 = - V_248 ;
}
F_35 ( & V_60 , V_12 ) ;
return V_164 ;
}
int F_153 ( int V_162 , unsigned int V_250 )
{
struct V_145 * V_146 = V_153 + V_162 ;
int V_164 = 0 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
switch( V_250 ) {
case V_256 :
F_154 ( V_146 , V_133 ) ;
break;
case V_257 :
F_155 ( V_146 , V_133 ) ;
break;
default:
V_164 = - V_248 ;
}
F_35 ( & V_60 , V_12 ) ;
return V_164 ;
}
int F_156 ( int V_230 , struct V_258 T_3 * V_259 ,
int V_232 )
{
struct V_258 V_260 ;
int V_261 = 0 ;
if ( F_151 ( & V_260 , V_259 , sizeof( struct V_258 ) ) )
return - V_241 ;
switch ( V_230 ) {
case V_262 :
V_261 = F_8 ( V_260 . V_11 ) ;
if ( V_261 >= 0 )
V_261 = F_148 ( V_261 , & V_259 -> V_14 ) ;
break;
case V_263 :
if ( ! V_232 )
return - V_247 ;
V_261 = F_12 ( V_260 . V_11 , V_260 . V_14 ) ;
break;
}
return V_261 ;
}
int F_157 ( int V_230 , struct V_264 T_3 * V_265 , int V_232 ,
int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
struct V_264 V_260 ;
T_4 * V_179 , * V_266 , V_50 , V_267 ;
unsigned long V_12 ;
if ( F_151 ( & V_260 , V_265 , sizeof( struct V_264 ) ) )
return - V_241 ;
if ( ! F_158 ( V_268 ) )
V_232 = 0 ;
switch ( V_230 ) {
case V_269 :
F_34 ( & V_60 , V_12 ) ;
V_179 = V_55 [ V_270 ] ;
if ( V_179 ) {
V_50 = F_30 ( V_179 [ V_46 ] ) ;
if ( V_146 -> V_68 != V_69 && F_31 ( V_50 ) >= V_271 )
V_50 = V_272 ;
} else
V_50 = ( V_46 ? V_272 : V_273 ) ;
F_35 ( & V_60 , V_12 ) ;
return F_148 ( V_50 , & V_265 -> V_274 ) ;
case V_275 :
if ( ! V_232 )
return - V_247 ;
if ( ! V_46 && V_276 == V_273 ) {
F_34 ( & V_60 , V_12 ) ;
V_179 = V_55 [ V_270 ] ;
if ( V_270 && V_179 ) {
V_55 [ V_270 ] = NULL ;
if ( V_179 [ 0 ] == F_30 ( V_277 ) ) {
F_138 ( V_179 ) ;
V_278 -- ;
}
}
F_35 ( & V_60 , V_12 ) ;
break;
}
if ( F_31 ( V_276 ) < V_271 ) {
if ( F_32 ( V_276 ) > V_279 [ F_31 ( V_276 ) ] )
return - V_248 ;
} else
if ( V_146 -> V_68 != V_69 )
return - V_248 ;
#if ! F_159 ( V_280 ) && ! F_159 ( V_281 )
if ( ! V_46 )
break;
#endif
V_266 = F_147 ( sizeof( V_282 ) , V_219 ) ;
if ( ! V_266 )
return - V_220 ;
F_34 ( & V_60 , V_12 ) ;
V_179 = V_55 [ V_270 ] ;
if ( V_179 == NULL ) {
int V_47 ;
if ( V_278 >= V_283 &&
! F_158 ( V_284 ) ) {
F_35 ( & V_60 , V_12 ) ;
F_138 ( V_266 ) ;
return - V_247 ;
}
V_55 [ V_270 ] = V_266 ;
V_179 = V_266 ;
V_179 [ 0 ] = F_30 ( V_277 ) ;
for ( V_47 = 1 ; V_47 < V_195 ; V_47 ++ )
V_179 [ V_47 ] = F_30 ( V_272 ) ;
V_278 ++ ;
} else
F_138 ( V_266 ) ;
V_267 = F_30 ( V_179 [ V_46 ] ) ;
if ( V_276 == V_267 )
goto V_285;
if ( ( ( V_267 == V_99 ) || ( V_276 == V_99 ) ) && ! F_158 ( V_286 ) ) {
F_35 ( & V_60 , V_12 ) ;
return - V_247 ;
}
V_179 [ V_46 ] = F_30 ( V_276 ) ;
if ( ! V_270 && ( F_31 ( V_267 ) == V_56 || F_31 ( V_276 ) == V_56 ) )
F_28 () ;
V_285:
F_35 ( & V_60 , V_12 ) ;
break;
}
return 0 ;
}
int F_160 ( int V_230 , struct V_287 T_3 * V_288 , int V_232 )
{
struct V_287 * V_289 ;
char * V_290 ;
T_5 * V_291 ;
T_5 T_3 * V_292 ;
int V_293 ;
int V_294 ;
char * V_295 , * V_296 , * V_297 ;
int V_46 , V_47 , V_48 ;
int V_164 ;
if ( ! F_158 ( V_268 ) )
V_232 = 0 ;
V_289 = F_147 ( sizeof( * V_289 ) , V_219 ) ;
if ( ! V_289 ) {
V_164 = - V_220 ;
goto V_298;
}
if ( F_151 ( V_289 , V_288 , sizeof( struct V_287 ) ) ) {
V_164 = - V_241 ;
goto V_298;
}
V_289 -> V_299 [ sizeof( V_289 -> V_299 ) - 1 ] = '\0' ;
V_46 = V_289 -> V_300 ;
switch ( V_230 ) {
case V_301 :
V_293 = sizeof( V_289 -> V_299 ) - 1 ;
V_292 = V_288 -> V_299 ;
V_290 = V_102 [ V_46 ] ;
if( V_290 )
for ( ; * V_290 && V_293 ; V_290 ++ , V_293 -- )
if ( F_148 ( * V_290 , V_292 ++ ) ) {
V_164 = - V_241 ;
goto V_298;
}
if ( F_148 ( '\0' , V_292 ) ) {
V_164 = - V_241 ;
goto V_298;
}
F_138 ( V_289 ) ;
return ( ( V_290 && * V_290 ) ? - V_302 : 0 ) ;
case V_303 :
if ( ! V_232 ) {
V_164 = - V_247 ;
goto V_298;
}
V_291 = V_102 [ V_46 ] ;
V_295 = V_304 + ( V_305 - V_306 ) ;
for ( V_47 = V_46 + 1 ; V_47 < V_307 && ! V_102 [ V_47 ] ; V_47 ++ )
;
if ( V_47 < V_307 )
V_296 = V_102 [ V_47 ] ;
else
V_296 = V_295 ;
V_294 = ( V_291 ? - strlen ( V_291 ) : 1 ) + strlen ( V_289 -> V_299 ) ;
if ( V_294 <= V_306 ) {
if ( V_47 < V_307 ) {
memmove ( V_296 + V_294 , V_296 , V_295 - V_296 ) ;
for ( V_48 = V_47 ; V_48 < V_307 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] += V_294 ;
}
if ( ! V_291 )
V_102 [ V_46 ] = V_296 ;
V_306 -= V_294 ;
} else {
V_293 = 256 ;
while ( V_293 < V_305 - V_306 + V_294 )
V_293 <<= 1 ;
V_297 = F_147 ( V_293 , V_219 ) ;
if( ! V_297 ) {
V_164 = - V_220 ;
goto V_298;
}
if ( ! V_291 )
V_102 [ V_46 ] = V_296 ;
if ( V_296 > V_304 )
memmove ( V_297 , V_304 , V_296 - V_304 ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] = V_297 + ( V_102 [ V_48 ] - V_304 ) ;
if ( V_295 > V_296 ) {
memmove ( V_297 + ( V_296 - V_304 ) + V_294 , V_296 , V_295 - V_296 ) ;
for ( V_48 = V_47 ; V_48 < V_307 ; V_48 ++ )
if ( V_102 [ V_48 ] )
V_102 [ V_48 ] = V_297 + ( V_102 [ V_48 ] - V_304 ) + V_294 ;
}
if ( V_304 != V_308 )
F_138 ( V_304 ) ;
V_304 = V_297 ;
V_306 = V_306 - V_294 + V_293 - V_305 ;
V_305 = V_293 ;
}
strcpy ( V_102 [ V_46 ] , V_289 -> V_299 ) ;
break;
}
V_164 = 0 ;
V_298:
F_138 ( V_289 ) ;
return V_164 ;
}
int F_161 ( int V_162 , int V_230 , unsigned long V_250 , int V_232 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
unsigned char V_309 ;
switch( V_230 ) {
case V_310 :
F_34 ( & V_60 , V_12 ) ;
V_309 = V_146 -> V_154 | ( V_146 -> V_224 << 4 ) ;
F_35 ( & V_60 , V_12 ) ;
return F_148 ( V_309 , ( char T_3 * ) V_250 ) ;
case V_311 :
if ( ! V_232 )
return - V_247 ;
if ( V_250 & ~ 0x77 )
return - V_248 ;
F_34 ( & V_148 , V_12 ) ;
V_146 -> V_154 = ( V_250 & 7 ) ;
V_146 -> V_224 = ( ( V_250 >> 4 ) & 7 ) ;
F_107 () ;
F_35 ( & V_148 , V_12 ) ;
return 0 ;
case V_312 :
V_309 = F_105 () ;
return F_148 ( V_309 , ( char T_3 * ) V_250 ) ;
case V_313 :
if ( ! V_232 )
return - V_247 ;
F_106 ( V_146 , V_250 ) ;
return 0 ;
}
return - V_314 ;
}
int F_162 ( int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
switch ( V_146 -> V_68 ) {
case V_96 :
return V_251 ;
case V_97 :
return V_252 ;
case V_69 :
return V_254 ;
case V_98 :
return V_255 ;
default:
return V_253 ;
}
}
int F_163 ( int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
return F_39 ( V_146 , V_133 ) ? V_257 : V_256 ;
}
void F_164 ( int V_162 )
{
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
V_153 [ V_162 ] . V_68 = V_228 ? V_69 : V_229 ;
F_35 ( & V_60 , V_12 ) ;
}
int F_165 ( void )
{
return V_51 ;
}
void F_166 ( int V_162 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_155 ( V_146 , V_190 ) ;
F_154 ( V_146 , V_104 ) ;
F_154 ( V_146 , V_77 ) ;
F_154 ( V_146 , V_70 ) ;
V_146 -> V_134 = 0 ;
V_146 -> V_135 = 0 ;
F_70 ( & V_148 ) ;
V_146 -> V_150 = V_152 ;
V_146 -> V_154 = V_146 -> V_224 ;
F_73 ( & V_148 ) ;
F_35 ( & V_60 , V_12 ) ;
}
int F_167 ( int V_162 , int V_315 )
{
struct V_145 * V_146 = V_153 + V_162 ;
return F_39 ( V_146 , V_315 ) ;
}
void F_168 ( int V_162 , int V_315 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_155 ( V_146 , V_315 ) ;
F_35 ( & V_60 , V_12 ) ;
}
void F_169 ( int V_162 , int V_315 )
{
struct V_145 * V_146 = V_153 + V_162 ;
unsigned long V_12 ;
F_34 ( & V_60 , V_12 ) ;
F_154 ( V_146 , V_315 ) ;
F_35 ( & V_60 , V_12 ) ;
}
