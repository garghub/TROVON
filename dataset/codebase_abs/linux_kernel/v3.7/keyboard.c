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
V_30 [ 1 ] . V_32 = V_9 -> V_30 [ V_33 ] ;
V_30 [ 1 ] . V_34 = V_9 -> V_30 [ V_35 ] ;
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
static void F_22 ( struct V_36 * V_37 , int V_38 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( V_40 ) {
F_23 ( V_40 , V_38 , 0 ) ;
F_24 ( V_40 ) ;
}
}
static void F_25 ( struct V_36 * V_37 , char * V_42 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( ! V_40 )
return;
while ( * V_42 ) {
F_23 ( V_40 , * V_42 , 0 ) ;
V_42 ++ ;
}
F_24 ( V_40 ) ;
}
static void F_26 ( struct V_36 * V_37 , int V_43 , char V_44 )
{
static char V_45 [] = { 0x1b , 'O' , 0x00 , 0x00 } ;
V_45 [ 1 ] = ( V_44 ? 'O' : '[' ) ;
V_45 [ 2 ] = V_43 ;
F_25 ( V_37 , V_45 ) ;
}
static void F_27 ( struct V_36 * V_37 , T_1 V_46 )
{
if ( V_46 < 0x80 )
F_22 ( V_37 , V_46 ) ;
else if ( V_46 < 0x800 ) {
F_22 ( V_37 , 0xc0 | ( V_46 >> 6 ) ) ;
F_22 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
} else if ( V_46 < 0x10000 ) {
if ( V_46 >= 0xD800 && V_46 < 0xE000 )
return;
if ( V_46 == 0xFFFF )
return;
F_22 ( V_37 , 0xe0 | ( V_46 >> 12 ) ) ;
F_22 ( V_37 , 0x80 | ( ( V_46 >> 6 ) & 0x3f ) ) ;
F_22 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
} else if ( V_46 < 0x110000 ) {
F_22 ( V_37 , 0xf0 | ( V_46 >> 18 ) ) ;
F_22 ( V_37 , 0x80 | ( ( V_46 >> 12 ) & 0x3f ) ) ;
F_22 ( V_37 , 0x80 | ( ( V_46 >> 6 ) & 0x3f ) ) ;
F_22 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
}
}
static void F_28 ( void )
{
unsigned int V_47 , V_48 , V_49 , V_50 , V_51 ;
V_52 = 0 ;
memset ( V_53 , 0 , sizeof( V_53 ) ) ;
for ( V_47 = 0 ; V_47 < F_29 ( V_54 ) ; V_47 ++ ) {
if ( ! V_54 [ V_47 ] )
continue;
V_49 = V_47 * V_55 ;
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ , V_49 ++ ) {
if ( ! F_14 ( V_49 , V_54 ) )
continue;
V_50 = F_30 ( V_56 [ 0 ] [ V_49 ] ) ;
if ( F_31 ( V_50 ) != V_57 && F_31 ( V_50 ) != V_58 )
continue;
V_51 = F_32 ( V_50 ) ;
if ( V_51 == F_32 ( V_59 ) )
V_51 = F_32 ( V_60 ) ;
V_53 [ V_51 ] ++ ;
V_52 |= ( 1 << V_51 ) ;
}
}
}
void F_33 ( void )
{
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
F_28 () ;
F_35 ( & V_61 , V_12 ) ;
}
static unsigned int F_36 ( struct V_36 * V_37 , unsigned int V_38 )
{
unsigned int V_8 = V_62 ;
unsigned int V_47 ;
V_62 = 0 ;
if ( ( V_8 & ~ 0xff ) == V_63 ) {
if ( ( V_38 & ~ 0xff ) == V_63 )
return V_8 | V_38 ;
} else {
for ( V_47 = 0 ; V_47 < V_64 ; V_47 ++ )
if ( V_65 [ V_47 ] . V_62 == V_8 && V_65 [ V_47 ] . V_66 == V_38 )
return V_65 [ V_47 ] . V_67 ;
}
if ( V_38 == ' ' || V_38 == ( V_63 | 0 ) || V_38 == V_8 )
return V_8 ;
if ( V_68 -> V_69 == V_70 )
F_27 ( V_37 , V_8 ) ;
else {
int V_46 = F_37 ( V_8 ) ;
if ( V_46 != - 1 )
F_22 ( V_37 , V_46 ) ;
}
return V_38 ;
}
static void F_38 ( struct V_36 * V_37 )
{
if ( V_62 ) {
if ( V_68 -> V_69 == V_70 )
F_27 ( V_37 , V_62 ) ;
else {
int V_46 = F_37 ( V_62 ) ;
if ( V_46 != - 1 )
F_22 ( V_37 , V_46 ) ;
}
V_62 = 0 ;
}
F_22 ( V_37 , 13 ) ;
if ( F_39 ( V_68 , V_71 ) )
F_22 ( V_37 , 10 ) ;
}
static void F_40 ( struct V_36 * V_37 )
{
if ( V_30 )
return;
F_41 ( V_68 , V_72 ) ;
}
static void F_42 ( struct V_36 * V_37 )
{
if ( V_30 )
return;
F_43 ( V_68 , V_72 ) ;
}
static void F_44 ( struct V_36 * V_37 )
{
struct V_73 * V_74 = F_45 () ;
if ( V_74 )
F_46 ( V_74 ) ;
}
static void F_47 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( V_30 || ! V_40 )
return;
if ( V_40 -> V_75 )
F_48 ( V_40 ) ;
else
F_49 ( V_40 ) ;
}
static void F_50 ( struct V_36 * V_37 )
{
if ( F_39 ( V_68 , V_76 ) )
F_26 ( V_37 , 'P' , 1 ) ;
else
F_51 ( V_37 ) ;
}
static void F_51 ( struct V_36 * V_37 )
{
if ( ! V_30 )
F_41 ( V_68 , V_77 ) ;
}
static void F_52 ( struct V_36 * V_37 )
{
F_53 ( V_78 ) ;
}
static void F_54 ( struct V_36 * V_37 )
{
int V_47 , V_79 = V_80 ;
if ( V_81 != - 1 )
V_79 = V_81 ;
for ( V_47 = V_79 - 1 ; V_47 != V_79 ; V_47 -- ) {
if ( V_47 == - 1 )
V_47 = V_82 - 1 ;
if ( F_55 ( V_47 ) )
break;
}
F_53 ( V_47 ) ;
}
static void F_56 ( struct V_36 * V_37 )
{
int V_47 , V_79 = V_80 ;
if ( V_81 != - 1 )
V_79 = V_81 ;
for ( V_47 = V_79 + 1 ; V_47 != V_79 ; V_47 ++ ) {
if ( V_47 == V_82 )
V_47 = 0 ;
if ( F_55 ( V_47 ) )
break;
}
F_53 ( V_47 ) ;
}
static void F_57 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( ! V_40 )
return;
F_23 ( V_40 , 0 , V_83 ) ;
F_24 ( V_40 ) ;
}
static void F_58 ( struct V_36 * V_37 )
{
F_59 ( V_37 , 0 ) ;
}
static void F_60 ( struct V_36 * V_37 )
{
F_61 ( V_37 , 0 ) ;
}
static void F_62 ( struct V_36 * V_37 )
{
F_63 ( 0 ) ;
}
static void F_64 ( struct V_36 * V_37 )
{
F_65 () ;
}
static void F_66 ( struct V_36 * V_37 )
{
F_67 () ;
}
static void F_68 ( struct V_36 * V_37 )
{
V_84 = true ;
}
static void F_69 ( struct V_36 * V_37 )
{
F_70 ( & V_85 . V_86 ) ;
if ( V_85 . V_87 )
if ( F_71 ( V_85 . V_87 , V_85 . V_88 , 1 ) ) {
F_72 ( V_85 . V_87 ) ;
V_85 . V_87 = NULL ;
}
F_73 ( & V_85 . V_86 ) ;
}
static void F_74 ( struct V_36 * V_37 )
{
struct V_89 * V_90 = & V_91 [ V_80 ] . V_90 ;
F_75 ( V_90 ) ;
}
static void F_76 ( struct V_36 * V_37 )
{
F_28 () ;
}
static void F_77 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
}
static void F_78 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
if ( V_93 )
return;
if ( V_92 >= F_29 ( V_94 ) )
return;
if ( ( V_68 -> V_69 == V_95 ||
V_68 -> V_69 == V_96 ||
V_68 -> V_69 == V_97 ) &&
V_92 != F_32 ( V_98 ) )
return;
V_94 [ V_92 ] ( V_37 ) ;
}
static void F_79 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
F_80 ( L_1 ) ;
}
static void F_81 ( struct V_36 * V_37 , unsigned int V_92 , char V_93 )
{
if ( V_93 )
return;
if ( V_62 )
V_92 = F_36 ( V_37 , V_92 ) ;
if ( V_84 ) {
V_84 = false ;
V_62 = V_92 ;
return;
}
if ( V_68 -> V_69 == V_70 )
F_27 ( V_37 , V_92 ) ;
else {
int V_46 = F_37 ( V_92 ) ;
if ( V_46 != - 1 )
F_22 ( V_37 , V_46 ) ;
}
}
static void F_82 ( struct V_36 * V_37 , unsigned int V_92 , char V_93 )
{
if ( V_93 )
return;
V_62 = ( V_62 ? F_36 ( V_37 , V_92 ) : V_92 ) ;
}
static void F_83 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
F_81 ( V_37 , F_84 ( V_92 ) , V_93 ) ;
}
static void F_85 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
F_82 ( V_37 , V_92 , V_93 ) ;
}
static void F_86 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
static const unsigned char V_99 [ V_100 ] = { '`' , '\'' , '^' , '~' , '"' , ',' } ;
F_82 ( V_37 , V_99 [ V_92 ] , V_93 ) ;
}
static void F_87 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
if ( V_93 )
return;
F_53 ( V_92 ) ;
}
static void F_88 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
if ( V_93 )
return;
if ( ( unsigned ) V_92 < F_29 ( V_101 ) ) {
if ( V_101 [ V_92 ] )
F_25 ( V_37 , V_101 [ V_92 ] ) ;
} else
F_80 ( L_2 , V_92 ) ;
}
static void F_89 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
static const char V_102 [] = L_3 ;
if ( V_93 )
return;
F_26 ( V_37 , V_102 [ V_92 ] , F_39 ( V_68 , V_103 ) ) ;
}
static void F_90 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
static const char V_104 [] = L_4 ;
static const char V_105 [] = L_5 ;
if ( V_93 )
return;
if ( F_39 ( V_68 , V_76 ) && ! V_53 [ V_106 ] ) {
F_26 ( V_37 , V_105 [ V_92 ] , 1 ) ;
return;
}
if ( ! F_91 ( V_68 , V_77 ) ) {
switch ( V_92 ) {
case F_32 ( V_107 ) :
case F_32 ( V_108 ) :
F_88 ( V_37 , F_32 ( V_109 ) , 0 ) ;
return;
case F_32 ( V_110 ) :
F_88 ( V_37 , F_32 ( V_111 ) , 0 ) ;
return;
case F_32 ( V_112 ) :
F_88 ( V_37 , F_32 ( V_113 ) , 0 ) ;
return;
case F_32 ( V_114 ) :
F_89 ( V_37 , F_32 ( V_115 ) , 0 ) ;
return;
case F_32 ( V_116 ) :
F_88 ( V_37 , F_32 ( V_117 ) , 0 ) ;
return;
case F_32 ( V_118 ) :
F_89 ( V_37 , F_32 ( V_119 ) , 0 ) ;
return;
case F_32 ( V_120 ) :
F_89 ( V_37 , F_32 ( V_121 ) , 0 ) ;
return;
case F_32 ( V_122 ) :
F_88 ( V_37 , F_32 ( V_123 ) , 0 ) ;
return;
case F_32 ( V_124 ) :
F_89 ( V_37 , F_32 ( V_125 ) , 0 ) ;
return;
case F_32 ( V_126 ) :
F_88 ( V_37 , F_32 ( V_127 ) , 0 ) ;
return;
case F_32 ( V_128 ) :
F_26 ( V_37 , 'G' , F_39 ( V_68 , V_76 ) ) ;
return;
}
}
F_22 ( V_37 , V_104 [ V_92 ] ) ;
if ( V_92 == F_32 ( V_129 ) && F_39 ( V_68 , V_71 ) )
F_22 ( V_37 , 10 ) ;
}
static void F_92 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
int V_130 = V_52 ;
if ( V_30 )
return;
if ( V_92 == F_32 ( V_59 ) ) {
V_92 = F_32 ( V_60 ) ;
if ( ! V_93 )
F_93 ( V_68 , V_72 ) ;
}
if ( V_93 ) {
if ( V_53 [ V_92 ] )
V_53 [ V_92 ] -- ;
} else
V_53 [ V_92 ] ++ ;
if ( V_53 [ V_92 ] )
V_52 |= ( 1 << V_92 ) ;
else
V_52 &= ~ ( 1 << V_92 ) ;
if ( V_93 && V_52 != V_130 && V_131 != - 1 ) {
if ( V_68 -> V_69 == V_70 )
F_27 ( V_37 , V_131 ) ;
else
F_22 ( V_37 , V_131 & 0xff ) ;
V_131 = - 1 ;
}
}
static void F_94 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
if ( V_93 )
return;
if ( F_39 ( V_68 , V_132 ) ) {
F_22 ( V_37 , '\033' ) ;
F_22 ( V_37 , V_92 ) ;
} else
F_22 ( V_37 , V_92 | 0x80 ) ;
}
static void F_95 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
int V_66 ;
if ( V_93 )
return;
if ( V_92 < 10 ) {
V_66 = 10 ;
} else {
V_92 -= 10 ;
V_66 = 16 ;
}
if ( V_131 == - 1 )
V_131 = V_92 ;
else
V_131 = V_131 * V_66 + V_92 ;
}
static void F_96 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
if ( V_93 || V_30 )
return;
F_97 ( V_68 , V_92 ) ;
}
static void F_98 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
F_92 ( V_37 , V_92 , V_93 ) ;
if ( V_93 || V_30 )
return;
F_99 ( V_68 , V_92 ) ;
if ( ! V_56 [ V_68 -> V_133 ^ V_68 -> V_134 ] ) {
V_68 -> V_134 = 0 ;
F_99 ( V_68 , V_92 ) ;
}
}
static void F_100 ( struct V_36 * V_37 , unsigned int V_135 , char V_93 )
{
static unsigned long V_136 ;
static unsigned V_137 ;
if ( ! V_138 )
F_82 ( V_37 , V_63 | V_135 , V_93 ) ;
else {
V_137 |= V_135 ;
V_136 ++ ;
if ( V_136 == V_138 ) {
F_81 ( V_37 , V_63 | V_137 , V_93 ) ;
V_136 = 0 ;
V_137 = 0 ;
}
}
}
static void F_101 ( struct V_36 * V_37 , unsigned char V_92 , char V_93 )
{
static unsigned V_139 , V_140 ;
static unsigned long V_141 ;
if ( V_68 -> V_69 != V_70 ) {
if ( ! V_93 )
F_102 ( L_6 ) ;
return;
}
if ( ! V_92 ) {
F_81 ( V_37 , V_63 , V_93 ) ;
return;
}
if ( V_92 > 8 )
return;
if ( ! V_93 ) {
V_139 |= 1 << ( V_92 - 1 ) ;
if ( ! V_142 )
V_140 = V_139 ;
} else if ( V_142 ) {
if ( ! V_140 ||
F_103 ( V_28 ,
V_141 + F_104 ( V_142 ) ) ) {
V_140 = V_139 ;
V_141 = V_28 ;
}
V_139 &= ~ ( 1 << ( V_92 - 1 ) ) ;
if ( ! V_139 && V_140 ) {
F_100 ( V_37 , V_140 , 0 ) ;
V_140 = 0 ;
}
} else {
if ( V_140 ) {
F_100 ( V_37 , V_140 , 0 ) ;
V_140 = 0 ;
}
V_139 &= ~ ( 1 << ( V_92 - 1 ) ) ;
}
}
static unsigned char F_105 ( void )
{
return V_143 ;
}
void F_106 ( struct V_144 * V_68 , unsigned int V_145 )
{
unsigned long V_12 ;
F_34 ( & V_146 , V_12 ) ;
if ( ! ( V_145 & ~ 7 ) ) {
V_147 = V_145 ;
V_68 -> V_148 = V_149 ;
} else
V_68 -> V_148 = V_150 ;
F_107 () ;
F_35 ( & V_146 , V_12 ) ;
}
static inline unsigned char F_108 ( void )
{
struct V_144 * V_68 = V_151 + V_80 ;
unsigned char V_152 ;
int V_47 ;
if ( V_68 -> V_148 == V_149 )
return V_147 ;
V_152 = V_68 -> V_153 ;
if ( V_68 -> V_148 == V_154 ) {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ )
if ( V_155 [ V_47 ] . V_156 ) {
if ( * V_155 [ V_47 ] . V_157 & V_155 [ V_47 ] . V_158 )
V_152 |= ( 1 << V_47 ) ;
else
V_152 &= ~ ( 1 << V_47 ) ;
}
}
return V_152 ;
}
static int F_109 ( struct V_4 * V_5 , void * V_6 )
{
unsigned char V_152 = * ( unsigned char * ) V_6 ;
if ( F_14 ( V_159 , V_5 -> V_9 -> V_20 ) ) {
F_15 ( V_5 , V_159 , V_160 , ! ! ( V_152 & 0x01 ) ) ;
F_15 ( V_5 , V_159 , V_161 , ! ! ( V_152 & 0x02 ) ) ;
F_15 ( V_5 , V_159 , V_162 , ! ! ( V_152 & 0x04 ) ) ;
F_15 ( V_5 , V_163 , V_164 , 0 ) ;
}
return 0 ;
}
int F_110 ( int V_165 , int V_166 )
{
struct V_144 * V_68 = V_151 + V_165 ;
int V_167 ;
unsigned long V_12 ;
F_34 ( & V_146 , V_12 ) ;
V_167 = F_91 ( V_68 , V_166 ) ;
F_35 ( & V_146 , V_12 ) ;
return V_167 ;
}
void F_111 ( int V_165 , int V_152 )
{
struct V_144 * V_68 = V_151 + V_165 ;
F_106 ( V_68 , V_152 ) ;
}
void F_112 ( int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
F_34 ( & V_146 , V_12 ) ;
F_93 ( V_68 , V_168 ) ;
F_107 () ;
F_35 ( & V_146 , V_12 ) ;
}
void F_113 ( int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
F_34 ( & V_146 , V_12 ) ;
F_43 ( V_68 , V_168 ) ;
F_107 () ;
F_35 ( & V_146 , V_12 ) ;
}
static void F_114 ( unsigned long V_169 )
{
unsigned char V_152 ;
unsigned long V_12 ;
F_34 ( & V_146 , V_12 ) ;
V_152 = F_108 () ;
F_35 ( & V_146 , V_12 ) ;
if ( V_152 != V_143 ) {
F_9 ( & V_16 , & V_152 ,
F_109 ) ;
V_143 = V_152 ;
}
}
static int F_115 ( struct V_36 * V_37 , unsigned int V_14 ,
unsigned char V_93 )
{
int V_170 ;
switch ( V_14 ) {
case V_171 :
F_22 ( V_37 , 0xe1 ) ;
F_22 ( V_37 , 0x1d | V_93 ) ;
F_22 ( V_37 , 0x45 | V_93 ) ;
break;
case V_172 :
if ( ! V_93 )
F_22 ( V_37 , 0xf2 ) ;
break;
case V_173 :
if ( ! V_93 )
F_22 ( V_37 , 0xf1 ) ;
break;
case V_174 :
if ( F_14 ( V_175 , V_54 ) ||
F_14 ( V_176 , V_54 ) ) {
F_22 ( V_37 , 0x54 | V_93 ) ;
} else {
F_22 ( V_37 , 0xe0 ) ;
F_22 ( V_37 , 0x2a | V_93 ) ;
F_22 ( V_37 , 0xe0 ) ;
F_22 ( V_37 , 0x37 | V_93 ) ;
}
break;
default:
if ( V_14 > 255 )
return - 1 ;
V_170 = V_177 [ V_14 ] ;
if ( ! V_170 )
return - 1 ;
if ( V_170 & 0x100 )
F_22 ( V_37 , 0xe0 ) ;
F_22 ( V_37 , ( V_170 & 0x7f ) | V_93 ) ;
break;
}
return 0 ;
}
static int F_115 ( struct V_36 * V_37 , unsigned int V_14 , unsigned char V_93 )
{
if ( V_14 > 127 )
return - 1 ;
F_22 ( V_37 , V_14 | V_93 ) ;
return 0 ;
}
static void F_116 ( unsigned char V_6 )
{
struct V_36 * V_37 = V_91 [ V_80 ] . V_8 ;
V_68 = V_151 + V_37 -> V_178 ;
if ( V_68 -> V_69 == V_95 )
F_22 ( V_37 , V_6 ) ;
}
static void F_117 ( unsigned int V_14 , int V_179 , int V_180 )
{
struct V_36 * V_37 = V_91 [ V_80 ] . V_8 ;
unsigned short V_181 , * V_182 ;
unsigned char type ;
bool V_183 ;
struct V_39 * V_40 ;
int V_184 ;
struct V_185 V_186 = { . V_37 = V_37 , . V_92 = V_14 , . V_179 = V_179 } ;
int V_187 ;
V_40 = V_37 -> V_41 . V_40 ;
if ( V_40 && ( ! V_40 -> V_188 ) ) {
V_40 -> V_188 = V_37 ;
}
V_68 = V_151 + V_37 -> V_178 ;
#ifdef F_118
if ( V_14 == V_189 )
V_190 = V_179 ;
#endif
V_30 = ( V_179 == 2 ) ;
V_183 = ( V_68 -> V_69 == V_95 ) ;
if ( V_183 && ! V_180 )
if ( F_115 ( V_37 , V_14 , ! V_179 << 7 ) )
if ( V_14 < V_191 && F_119 () )
F_102 ( L_7 ,
V_14 ) ;
#ifdef F_118
if ( V_14 == V_192 && V_190 ) {
V_190 = false ;
F_120 () ;
}
#endif
if ( V_68 -> V_69 == V_96 ) {
if ( V_14 < 128 ) {
F_22 ( V_37 , V_14 | ( ! V_179 << 7 ) ) ;
} else {
F_22 ( V_37 , ! V_179 << 7 ) ;
F_22 ( V_37 , ( V_14 >> 7 ) | 0x80 ) ;
F_22 ( V_37 , V_14 | 0x80 ) ;
}
V_183 = true ;
}
if ( V_179 )
F_121 ( V_14 , V_54 ) ;
else
F_122 ( V_14 , V_54 ) ;
if ( V_30 &&
( ! F_39 ( V_68 , V_193 ) ||
( V_40 && ! F_123 ( V_40 ) && F_124 ( V_40 ) ) ) ) {
return;
}
V_186 . V_194 = V_184 = ( V_52 | V_68 -> V_134 ) ^ V_68 -> V_133 ;
V_186 . V_143 = V_68 -> V_153 ;
V_182 = V_56 [ V_184 ] ;
V_187 = F_125 ( & V_3 ,
V_195 , & V_186 ) ;
if ( V_187 == V_196 || ! V_182 ) {
F_125 ( & V_3 ,
V_197 , & V_186 ) ;
F_28 () ;
V_68 -> V_134 = 0 ;
return;
}
if ( V_14 < V_198 )
V_181 = V_182 [ V_14 ] ;
else if ( V_14 >= V_199 && V_14 <= V_200 )
V_181 = F_30 ( F_126 ( V_201 , V_14 - V_199 + 1 ) ) ;
else
return;
type = F_31 ( V_181 ) ;
if ( type < 0xf0 ) {
V_186 . V_92 = V_181 ;
V_187 = F_125 ( & V_3 ,
V_202 , & V_186 ) ;
if ( V_187 != V_196 )
if ( V_179 && ! V_183 )
F_27 ( V_37 , V_181 ) ;
return;
}
type -= 0xf0 ;
if ( type == V_203 ) {
type = V_204 ;
if ( F_91 ( V_68 , V_72 ) ) {
V_182 = V_56 [ V_184 ^ ( 1 << V_106 ) ] ;
if ( V_182 )
V_181 = V_182 [ V_14 ] ;
}
}
V_186 . V_92 = V_181 ;
V_187 = F_125 ( & V_3 ,
V_205 , & V_186 ) ;
if ( V_187 == V_196 )
return;
if ( ( V_183 || V_68 -> V_69 == V_97 ) && type != V_206 && type != V_57 )
return;
(* F_127 [ type ])( V_37 , V_181 & 0xff , ! V_179 ) ;
V_186 . V_143 = V_68 -> V_153 ;
F_125 ( & V_3 , V_207 , & V_186 ) ;
if ( type != V_58 )
V_68 -> V_134 = 0 ;
}
static void F_128 ( struct V_4 * V_5 , unsigned int V_208 ,
unsigned int V_209 , int V_92 )
{
F_70 ( & V_61 ) ;
if ( V_208 == V_210 && V_209 == V_211 && F_129 ( V_5 -> V_9 ) )
F_116 ( V_92 ) ;
if ( V_208 == V_212 )
F_117 ( V_209 , V_92 , F_129 ( V_5 -> V_9 ) ) ;
F_73 ( & V_61 ) ;
F_130 ( & V_213 ) ;
V_214 = 1 ;
F_131 () ;
}
static bool F_132 ( struct V_215 * V_216 , struct V_18 * V_9 )
{
int V_47 ;
if ( F_14 ( V_19 , V_9 -> V_20 ) )
return true ;
if ( F_14 ( V_212 , V_9 -> V_20 ) ) {
for ( V_47 = V_217 ; V_47 < V_191 ; V_47 ++ )
if ( F_14 ( V_47 , V_9 -> V_218 ) )
return true ;
for ( V_47 = V_199 ; V_47 <= V_219 ; V_47 ++ )
if ( F_14 ( V_47 , V_9 -> V_218 ) )
return true ;
}
return false ;
}
static int F_133 ( struct V_215 * V_216 , struct V_18 * V_9 ,
const struct V_220 * V_221 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_134 ( sizeof( struct V_4 ) , V_222 ) ;
if ( ! V_5 )
return - V_223 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_216 = V_216 ;
V_5 -> V_224 = L_8 ;
error = F_135 ( V_5 ) ;
if ( error )
goto V_225;
error = F_136 ( V_5 ) ;
if ( error )
goto V_226;
return 0 ;
V_226:
F_137 ( V_5 ) ;
V_225:
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
F_142 ( & V_213 ) ;
if ( V_143 != 0xff )
F_109 ( V_5 , & V_143 ) ;
F_143 ( & V_213 ) ;
}
int T_2 F_144 ( void )
{
int V_47 ;
int error ;
for ( V_47 = 0 ; V_47 < V_82 ; V_47 ++ ) {
V_151 [ V_47 ] . V_153 = F_1 () ;
V_151 [ V_47 ] . V_227 = F_1 () ;
V_151 [ V_47 ] . V_148 = V_150 ;
V_151 [ V_47 ] . V_133 = V_228 ;
V_151 [ V_47 ] . V_134 = 0 ;
V_151 [ V_47 ] . V_229 = V_230 ;
V_151 [ V_47 ] . V_69 = V_231 ? V_70 : V_232 ;
}
error = F_145 ( & V_16 ) ;
if ( error )
return error ;
F_143 ( & V_213 ) ;
F_130 ( & V_213 ) ;
return 0 ;
}
int F_146 ( unsigned int V_233 , void T_3 * V_234 , int V_235 )
{
struct V_236 T_3 * V_237 = V_234 ;
unsigned long V_12 ;
int V_238 ;
int V_167 = 0 ;
switch ( V_233 ) {
case V_239 :
{
struct V_240 * V_62 ;
int V_47 ;
V_62 = F_147 ( V_241 * sizeof( struct V_240 ) ,
V_222 ) ;
if ( V_62 == NULL )
return - V_223 ;
F_34 ( & V_61 , V_12 ) ;
V_238 = V_64 ;
for ( V_47 = 0 ; V_47 < V_238 ; V_47 ++ ) {
V_62 [ V_47 ] . V_62 = F_37 (
V_65 [ V_47 ] . V_62 ) ;
V_62 [ V_47 ] . V_66 = F_37 (
V_65 [ V_47 ] . V_66 ) ;
V_62 [ V_47 ] . V_67 = F_37 (
V_65 [ V_47 ] . V_67 ) ;
}
F_35 ( & V_61 , V_12 ) ;
if ( F_148 ( V_238 , & V_237 -> V_242 ) )
V_167 = - V_243 ;
else if ( F_149 ( V_237 -> V_240 , V_62 ,
V_238 * sizeof( struct V_240 ) ) )
V_167 = - V_243 ;
F_138 ( V_62 ) ;
return V_167 ;
}
case V_244 :
{
struct V_245 T_3 * V_237 = V_234 ;
void * V_45 ;
V_45 = F_147 ( V_241 * sizeof( struct V_246 ) ,
V_222 ) ;
if ( V_45 == NULL )
return - V_223 ;
F_34 ( & V_61 , V_12 ) ;
V_238 = V_64 ;
memcpy ( V_45 , V_65 , V_238 * sizeof( struct V_246 ) ) ;
F_35 ( & V_61 , V_12 ) ;
if ( F_148 ( V_238 , & V_237 -> V_242 ) )
V_167 = - V_243 ;
else if ( F_149 ( V_237 -> V_246 , V_45 ,
V_238 * sizeof( struct V_246 ) ) )
V_167 = - V_243 ;
F_138 ( V_45 ) ;
return V_167 ;
}
case V_247 :
{
struct V_236 T_3 * V_237 = V_234 ;
struct V_240 * V_62 = NULL ;
unsigned int V_248 ;
int V_47 ;
if ( ! V_235 )
return - V_249 ;
if ( F_150 ( V_248 , & V_237 -> V_242 ) )
return - V_243 ;
if ( V_248 >= V_241 )
return - V_250 ;
if ( V_248 ) {
V_62 = F_147 ( sizeof( struct V_240 ) * V_248 ,
V_222 ) ;
if ( V_62 == NULL )
return - V_223 ;
if ( F_151 ( V_62 , V_237 -> V_240 ,
sizeof( struct V_240 ) * V_248 ) ) {
F_138 ( V_62 ) ;
return - V_243 ;
}
}
F_34 ( & V_61 , V_12 ) ;
V_64 = V_248 ;
for ( V_47 = 0 ; V_47 < V_248 ; V_47 ++ ) {
V_65 [ V_47 ] . V_62 =
F_84 ( V_62 [ V_47 ] . V_62 ) ;
V_65 [ V_47 ] . V_66 =
F_84 ( V_62 [ V_47 ] . V_66 ) ;
V_65 [ V_47 ] . V_67 =
F_84 ( V_62 [ V_47 ] . V_67 ) ;
}
F_35 ( & V_61 , V_12 ) ;
F_138 ( V_62 ) ;
return 0 ;
}
case V_251 :
{
struct V_245 T_3 * V_237 = V_234 ;
unsigned int V_248 ;
void * V_45 = NULL ;
if ( ! V_235 )
return - V_249 ;
if ( F_150 ( V_248 , & V_237 -> V_242 ) )
return - V_243 ;
if ( V_248 >= V_241 )
return - V_250 ;
if ( V_248 ) {
V_45 = F_147 ( V_248 * sizeof( struct V_246 ) ,
V_222 ) ;
if ( V_45 == NULL )
return - V_223 ;
if ( F_151 ( V_45 , V_237 -> V_246 ,
V_248 * sizeof( struct V_246 ) ) ) {
F_138 ( V_45 ) ;
return - V_243 ;
}
}
F_34 ( & V_61 , V_12 ) ;
if ( V_248 )
memcpy ( V_65 , V_45 ,
V_248 * sizeof( struct V_246 ) ) ;
V_64 = V_248 ;
F_35 ( & V_61 , V_12 ) ;
F_138 ( V_45 ) ;
return 0 ;
}
}
return V_167 ;
}
int F_152 ( int V_165 , unsigned int V_252 )
{
struct V_144 * V_68 = V_151 + V_165 ;
int V_167 = 0 ;
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
switch( V_252 ) {
case V_253 :
V_68 -> V_69 = V_95 ;
break;
case V_254 :
V_68 -> V_69 = V_96 ;
break;
case V_255 :
V_68 -> V_69 = V_232 ;
F_28 () ;
break;
case V_256 :
V_68 -> V_69 = V_70 ;
F_28 () ;
break;
case V_257 :
V_68 -> V_69 = V_97 ;
break;
default:
V_167 = - V_250 ;
}
F_35 ( & V_61 , V_12 ) ;
return V_167 ;
}
int F_153 ( int V_165 , unsigned int V_252 )
{
struct V_144 * V_68 = V_151 + V_165 ;
int V_167 = 0 ;
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
switch( V_252 ) {
case V_258 :
F_154 ( V_68 , V_132 ) ;
break;
case V_259 :
F_155 ( V_68 , V_132 ) ;
break;
default:
V_167 = - V_250 ;
}
F_35 ( & V_61 , V_12 ) ;
return V_167 ;
}
int F_156 ( int V_233 , struct V_260 T_3 * V_261 ,
int V_235 )
{
struct V_260 V_262 ;
int V_263 = 0 ;
if ( F_151 ( & V_262 , V_261 , sizeof( struct V_260 ) ) )
return - V_243 ;
switch ( V_233 ) {
case V_264 :
V_263 = F_8 ( V_262 . V_11 ) ;
if ( V_263 >= 0 )
V_263 = F_148 ( V_263 , & V_261 -> V_14 ) ;
break;
case V_265 :
if ( ! V_235 )
return - V_249 ;
V_263 = F_12 ( V_262 . V_11 , V_262 . V_14 ) ;
break;
}
return V_263 ;
}
int F_157 ( int V_233 , struct V_266 T_3 * V_267 , int V_235 ,
int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
struct V_266 V_262 ;
T_4 * V_182 , * V_268 , V_51 , V_269 ;
unsigned long V_12 ;
if ( F_151 ( & V_262 , V_267 , sizeof( struct V_266 ) ) )
return - V_243 ;
if ( ! F_158 ( V_270 ) )
V_235 = 0 ;
switch ( V_233 ) {
case V_271 :
F_34 ( & V_61 , V_12 ) ;
V_182 = V_56 [ V_272 ] ;
if ( V_182 ) {
V_51 = F_30 ( V_182 [ V_47 ] ) ;
if ( V_68 -> V_69 != V_70 && F_31 ( V_51 ) >= V_273 )
V_51 = V_274 ;
} else
V_51 = ( V_47 ? V_274 : V_275 ) ;
F_35 ( & V_61 , V_12 ) ;
return F_148 ( V_51 , & V_267 -> V_276 ) ;
case V_277 :
if ( ! V_235 )
return - V_249 ;
if ( ! V_47 && V_278 == V_275 ) {
F_34 ( & V_61 , V_12 ) ;
V_182 = V_56 [ V_272 ] ;
if ( V_272 && V_182 ) {
V_56 [ V_272 ] = NULL ;
if ( V_182 [ 0 ] == F_30 ( V_279 ) ) {
F_138 ( V_182 ) ;
V_280 -- ;
}
}
F_35 ( & V_61 , V_12 ) ;
break;
}
if ( F_31 ( V_278 ) < V_273 ) {
if ( F_32 ( V_278 ) > V_281 [ F_31 ( V_278 ) ] )
return - V_250 ;
} else
if ( V_68 -> V_69 != V_70 )
return - V_250 ;
#if ! F_159 ( V_282 ) && ! F_159 ( V_283 )
if ( ! V_47 )
break;
#endif
V_268 = F_147 ( sizeof( V_284 ) , V_222 ) ;
if ( ! V_268 )
return - V_223 ;
F_34 ( & V_61 , V_12 ) ;
V_182 = V_56 [ V_272 ] ;
if ( V_182 == NULL ) {
int V_48 ;
if ( V_280 >= V_285 &&
! F_158 ( V_286 ) ) {
F_35 ( & V_61 , V_12 ) ;
F_138 ( V_268 ) ;
return - V_249 ;
}
V_56 [ V_272 ] = V_268 ;
V_182 = V_268 ;
V_182 [ 0 ] = F_30 ( V_279 ) ;
for ( V_48 = 1 ; V_48 < V_198 ; V_48 ++ )
V_182 [ V_48 ] = F_30 ( V_274 ) ;
V_280 ++ ;
} else
F_138 ( V_268 ) ;
V_269 = F_30 ( V_182 [ V_47 ] ) ;
if ( V_278 == V_269 )
goto V_287;
if ( ( ( V_269 == V_98 ) || ( V_278 == V_98 ) ) && ! F_158 ( V_288 ) ) {
F_35 ( & V_61 , V_12 ) ;
return - V_249 ;
}
V_182 [ V_47 ] = F_30 ( V_278 ) ;
if ( ! V_272 && ( F_31 ( V_269 ) == V_57 || F_31 ( V_278 ) == V_57 ) )
F_28 () ;
V_287:
F_35 ( & V_61 , V_12 ) ;
break;
}
return 0 ;
}
int F_160 ( int V_233 , struct V_289 T_3 * V_290 , int V_235 )
{
struct V_289 * V_291 ;
char * V_292 ;
T_5 * V_293 ;
T_5 T_3 * V_234 ;
int V_294 ;
int V_295 ;
char * V_296 , * V_297 , * V_298 ;
int V_47 , V_48 , V_49 ;
int V_167 ;
if ( ! F_158 ( V_270 ) )
V_235 = 0 ;
V_291 = F_147 ( sizeof( * V_291 ) , V_222 ) ;
if ( ! V_291 ) {
V_167 = - V_223 ;
goto V_299;
}
if ( F_151 ( V_291 , V_290 , sizeof( struct V_289 ) ) ) {
V_167 = - V_243 ;
goto V_299;
}
V_291 -> V_300 [ sizeof( V_291 -> V_300 ) - 1 ] = '\0' ;
V_47 = V_291 -> V_301 ;
switch ( V_233 ) {
case V_302 :
V_294 = sizeof( V_291 -> V_300 ) - 1 ;
V_234 = V_290 -> V_300 ;
V_292 = V_101 [ V_47 ] ;
if( V_292 )
for ( ; * V_292 && V_294 ; V_292 ++ , V_294 -- )
if ( F_148 ( * V_292 , V_234 ++ ) ) {
V_167 = - V_243 ;
goto V_299;
}
if ( F_148 ( '\0' , V_234 ) ) {
V_167 = - V_243 ;
goto V_299;
}
F_138 ( V_291 ) ;
return ( ( V_292 && * V_292 ) ? - V_303 : 0 ) ;
case V_304 :
if ( ! V_235 ) {
V_167 = - V_249 ;
goto V_299;
}
V_293 = V_101 [ V_47 ] ;
V_296 = V_305 + ( V_306 - V_307 ) ;
for ( V_48 = V_47 + 1 ; V_48 < V_308 && ! V_101 [ V_48 ] ; V_48 ++ )
;
if ( V_48 < V_308 )
V_297 = V_101 [ V_48 ] ;
else
V_297 = V_296 ;
V_295 = ( V_293 ? - strlen ( V_293 ) : 1 ) + strlen ( V_291 -> V_300 ) ;
if ( V_295 <= V_307 ) {
if ( V_48 < V_308 ) {
memmove ( V_297 + V_295 , V_297 , V_296 - V_297 ) ;
for ( V_49 = V_48 ; V_49 < V_308 ; V_49 ++ )
if ( V_101 [ V_49 ] )
V_101 [ V_49 ] += V_295 ;
}
if ( ! V_293 )
V_101 [ V_47 ] = V_297 ;
V_307 -= V_295 ;
} else {
V_294 = 256 ;
while ( V_294 < V_306 - V_307 + V_295 )
V_294 <<= 1 ;
V_298 = F_147 ( V_294 , V_222 ) ;
if( ! V_298 ) {
V_167 = - V_223 ;
goto V_299;
}
if ( ! V_293 )
V_101 [ V_47 ] = V_297 ;
if ( V_297 > V_305 )
memmove ( V_298 , V_305 , V_297 - V_305 ) ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
if ( V_101 [ V_49 ] )
V_101 [ V_49 ] = V_298 + ( V_101 [ V_49 ] - V_305 ) ;
if ( V_296 > V_297 ) {
memmove ( V_298 + ( V_297 - V_305 ) + V_295 , V_297 , V_296 - V_297 ) ;
for ( V_49 = V_48 ; V_49 < V_308 ; V_49 ++ )
if ( V_101 [ V_49 ] )
V_101 [ V_49 ] = V_298 + ( V_101 [ V_49 ] - V_305 ) + V_295 ;
}
if ( V_305 != V_309 )
F_138 ( V_305 ) ;
V_305 = V_298 ;
V_307 = V_307 - V_295 + V_294 - V_306 ;
V_306 = V_294 ;
}
strcpy ( V_101 [ V_47 ] , V_291 -> V_300 ) ;
break;
}
V_167 = 0 ;
V_299:
F_138 ( V_291 ) ;
return V_167 ;
}
int F_161 ( int V_165 , int V_233 , unsigned long V_252 , int V_235 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
unsigned char V_310 ;
switch( V_233 ) {
case V_311 :
F_34 ( & V_61 , V_12 ) ;
V_310 = V_68 -> V_153 | ( V_68 -> V_227 << 4 ) ;
F_35 ( & V_61 , V_12 ) ;
return F_148 ( V_310 , ( char T_3 * ) V_252 ) ;
case V_312 :
if ( ! V_235 )
return - V_249 ;
if ( V_252 & ~ 0x77 )
return - V_250 ;
F_34 ( & V_146 , V_12 ) ;
V_68 -> V_153 = ( V_252 & 7 ) ;
V_68 -> V_227 = ( ( V_252 >> 4 ) & 7 ) ;
F_107 () ;
F_35 ( & V_146 , V_12 ) ;
return 0 ;
case V_313 :
V_310 = F_105 () ;
return F_148 ( V_310 , ( char T_3 * ) V_252 ) ;
case V_314 :
if ( ! V_235 )
return - V_249 ;
F_106 ( V_68 , V_252 ) ;
return 0 ;
}
return - V_315 ;
}
int F_162 ( int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
switch ( V_68 -> V_69 ) {
case V_95 :
return V_253 ;
case V_96 :
return V_254 ;
case V_70 :
return V_256 ;
case V_97 :
return V_257 ;
default:
return V_255 ;
}
}
int F_163 ( int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
return F_39 ( V_68 , V_132 ) ? V_259 : V_258 ;
}
void F_164 ( int V_165 )
{
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
V_151 [ V_165 ] . V_69 = V_231 ? V_70 : V_232 ;
F_35 ( & V_61 , V_12 ) ;
}
int F_165 ( void )
{
return V_52 ;
}
void F_166 ( int V_165 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
F_155 ( V_68 , V_193 ) ;
F_154 ( V_68 , V_103 ) ;
F_154 ( V_68 , V_76 ) ;
F_154 ( V_68 , V_71 ) ;
V_68 -> V_133 = 0 ;
V_68 -> V_134 = 0 ;
F_70 ( & V_146 ) ;
V_68 -> V_148 = V_150 ;
V_68 -> V_153 = V_68 -> V_227 ;
F_73 ( & V_146 ) ;
F_35 ( & V_61 , V_12 ) ;
}
int F_167 ( int V_165 , int V_316 )
{
struct V_144 * V_68 = V_151 + V_165 ;
return F_39 ( V_68 , V_316 ) ;
}
void F_168 ( int V_165 , int V_316 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
F_155 ( V_68 , V_316 ) ;
F_35 ( & V_61 , V_12 ) ;
}
void F_169 ( int V_165 , int V_316 )
{
struct V_144 * V_68 = V_151 + V_165 ;
unsigned long V_12 ;
F_34 ( & V_61 , V_12 ) ;
F_154 ( V_68 , V_316 ) ;
F_35 ( & V_61 , V_12 ) ;
}
