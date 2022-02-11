int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
V_8 -> error = F_6 ( V_5 -> V_9 , & V_8 -> V_10 ) ;
return V_8 -> error == 0 ;
}
int F_7 ( unsigned int V_11 )
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
F_8 ( & V_16 , & V_8 , F_5 ) ;
return V_8 . error ? : V_8 . V_10 . V_14 ;
}
static int F_9 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
V_8 -> error = F_10 ( V_5 -> V_9 , & V_8 -> V_10 ) ;
return V_8 -> error == 0 ;
}
int F_11 ( unsigned int V_11 , unsigned int V_14 )
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
F_8 ( & V_16 , & V_8 , F_9 ) ;
return V_8 . error ;
}
static int F_12 ( struct V_4 * V_5 , void * V_6 )
{
unsigned int * V_17 = V_6 ;
struct V_18 * V_9 = V_5 -> V_9 ;
if ( F_13 ( V_19 , V_9 -> V_20 ) ) {
if ( F_13 ( V_21 , V_9 -> V_22 ) ) {
F_14 ( V_5 , V_19 , V_21 , * V_17 ) ;
if ( * V_17 )
return 0 ;
}
if ( F_13 ( V_23 , V_9 -> V_22 ) )
F_14 ( V_5 , V_19 , V_23 , * V_17 ? 1 : 0 ) ;
}
return 0 ;
}
static void F_15 ( unsigned long V_24 )
{
static unsigned int V_25 ;
F_8 ( & V_16 , & V_25 , F_12 ) ;
}
void F_16 ( unsigned int V_17 , unsigned int V_26 )
{
F_17 ( & V_27 ) ;
F_8 ( & V_16 , & V_17 , F_12 ) ;
if ( V_17 && V_26 )
F_18 ( & V_27 , V_28 + V_26 ) ;
}
static int F_19 ( struct V_4 * V_5 , void * V_6 )
{
struct V_18 * V_9 = V_5 -> V_9 ;
struct V_29 * V_30 = V_6 ;
if ( F_13 ( V_31 , V_9 -> V_20 ) ) {
if ( V_30 [ 0 ] . V_32 > 0 )
F_14 ( V_5 ,
V_31 , V_33 , V_30 [ 0 ] . V_32 ) ;
if ( V_30 [ 0 ] . V_34 > 0 )
F_14 ( V_5 ,
V_31 , V_35 , V_30 [ 0 ] . V_34 ) ;
V_30 [ 1 ] . V_32 = V_9 -> V_30 [ V_33 ] ;
V_30 [ 1 ] . V_34 = V_9 -> V_30 [ V_35 ] ;
}
return 0 ;
}
int F_20 ( struct V_29 * V_30 )
{
struct V_29 V_6 [ 2 ] = { * V_30 } ;
F_8 ( & V_16 , V_6 , F_19 ) ;
* V_30 = V_6 [ 1 ] ;
return 0 ;
}
static void F_21 ( struct V_36 * V_37 , int V_38 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( V_40 ) {
F_22 ( V_40 , V_38 , 0 ) ;
F_23 ( V_40 ) ;
}
}
static void F_24 ( struct V_36 * V_37 , char * V_42 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( ! V_40 )
return;
while ( * V_42 ) {
F_22 ( V_40 , * V_42 , 0 ) ;
V_42 ++ ;
}
F_23 ( V_40 ) ;
}
static void F_25 ( struct V_36 * V_37 , int V_43 , char V_44 )
{
static char V_45 [] = { 0x1b , 'O' , 0x00 , 0x00 } ;
V_45 [ 1 ] = ( V_44 ? 'O' : '[' ) ;
V_45 [ 2 ] = V_43 ;
F_24 ( V_37 , V_45 ) ;
}
static void F_26 ( struct V_36 * V_37 , T_1 V_46 )
{
if ( V_46 < 0x80 )
F_21 ( V_37 , V_46 ) ;
else if ( V_46 < 0x800 ) {
F_21 ( V_37 , 0xc0 | ( V_46 >> 6 ) ) ;
F_21 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
} else if ( V_46 < 0x10000 ) {
if ( V_46 >= 0xD800 && V_46 < 0xE000 )
return;
if ( V_46 == 0xFFFF )
return;
F_21 ( V_37 , 0xe0 | ( V_46 >> 12 ) ) ;
F_21 ( V_37 , 0x80 | ( ( V_46 >> 6 ) & 0x3f ) ) ;
F_21 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
} else if ( V_46 < 0x110000 ) {
F_21 ( V_37 , 0xf0 | ( V_46 >> 18 ) ) ;
F_21 ( V_37 , 0x80 | ( ( V_46 >> 12 ) & 0x3f ) ) ;
F_21 ( V_37 , 0x80 | ( ( V_46 >> 6 ) & 0x3f ) ) ;
F_21 ( V_37 , 0x80 | ( V_46 & 0x3f ) ) ;
}
}
void F_27 ( void )
{
unsigned int V_47 , V_48 , V_49 , V_50 , V_51 ;
V_52 = 0 ;
memset ( V_53 , 0 , sizeof( V_53 ) ) ;
for ( V_47 = 0 ; V_47 < F_28 ( V_54 ) ; V_47 ++ ) {
if ( ! V_54 [ V_47 ] )
continue;
V_49 = V_47 * V_55 ;
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ , V_49 ++ ) {
if ( ! F_13 ( V_49 , V_54 ) )
continue;
V_50 = F_29 ( V_56 [ 0 ] [ V_49 ] ) ;
if ( F_30 ( V_50 ) != V_57 && F_30 ( V_50 ) != V_58 )
continue;
V_51 = F_31 ( V_50 ) ;
if ( V_51 == F_31 ( V_59 ) )
V_51 = F_31 ( V_60 ) ;
V_53 [ V_51 ] ++ ;
V_52 |= ( 1 << V_51 ) ;
}
}
}
static unsigned int F_32 ( struct V_36 * V_37 , unsigned int V_38 )
{
unsigned int V_8 = V_61 ;
unsigned int V_47 ;
V_61 = 0 ;
if ( ( V_8 & ~ 0xff ) == V_62 ) {
if ( ( V_38 & ~ 0xff ) == V_62 )
return V_8 | V_38 ;
} else {
for ( V_47 = 0 ; V_47 < V_63 ; V_47 ++ )
if ( V_64 [ V_47 ] . V_61 == V_8 && V_64 [ V_47 ] . V_65 == V_38 )
return V_64 [ V_47 ] . V_66 ;
}
if ( V_38 == ' ' || V_38 == ( V_62 | 0 ) || V_38 == V_8 )
return V_8 ;
if ( V_67 -> V_68 == V_69 )
F_26 ( V_37 , V_8 ) ;
else {
int V_46 = F_33 ( V_8 ) ;
if ( V_46 != - 1 )
F_21 ( V_37 , V_46 ) ;
}
return V_38 ;
}
static void F_34 ( struct V_36 * V_37 )
{
if ( V_61 ) {
if ( V_67 -> V_68 == V_69 )
F_26 ( V_37 , V_61 ) ;
else {
int V_46 = F_33 ( V_61 ) ;
if ( V_46 != - 1 )
F_21 ( V_37 , V_46 ) ;
}
V_61 = 0 ;
}
F_21 ( V_37 , 13 ) ;
if ( F_35 ( V_67 , V_70 ) )
F_21 ( V_37 , 10 ) ;
}
static void F_36 ( struct V_36 * V_37 )
{
if ( V_30 )
return;
F_37 ( V_67 , V_71 ) ;
}
static void F_38 ( struct V_36 * V_37 )
{
if ( V_30 )
return;
F_39 ( V_67 , V_71 ) ;
}
static void F_40 ( struct V_36 * V_37 )
{
struct V_72 * V_73 = F_41 () ;
if ( V_73 )
F_42 ( V_73 ) ;
}
static void F_43 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( V_30 || ! V_40 )
return;
if ( V_40 -> V_74 )
F_44 ( V_40 ) ;
else
F_45 ( V_40 ) ;
}
static void F_46 ( struct V_36 * V_37 )
{
if ( F_35 ( V_67 , V_75 ) )
F_25 ( V_37 , 'P' , 1 ) ;
else
F_47 ( V_37 ) ;
}
static void F_47 ( struct V_36 * V_37 )
{
if ( ! V_30 )
F_37 ( V_67 , V_76 ) ;
}
static void F_48 ( struct V_36 * V_37 )
{
F_49 ( V_77 ) ;
}
static void F_50 ( struct V_36 * V_37 )
{
int V_47 , V_78 = V_79 ;
if ( V_80 != - 1 )
V_78 = V_80 ;
for ( V_47 = V_78 - 1 ; V_47 != V_78 ; V_47 -- ) {
if ( V_47 == - 1 )
V_47 = V_81 - 1 ;
if ( F_51 ( V_47 ) )
break;
}
F_49 ( V_47 ) ;
}
static void F_52 ( struct V_36 * V_37 )
{
int V_47 , V_78 = V_79 ;
if ( V_80 != - 1 )
V_78 = V_80 ;
for ( V_47 = V_78 + 1 ; V_47 != V_78 ; V_47 ++ ) {
if ( V_47 == V_81 )
V_47 = 0 ;
if ( F_51 ( V_47 ) )
break;
}
F_49 ( V_47 ) ;
}
static void F_53 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_41 . V_40 ;
if ( ! V_40 )
return;
F_22 ( V_40 , 0 , V_82 ) ;
F_23 ( V_40 ) ;
}
static void F_54 ( struct V_36 * V_37 )
{
F_55 ( V_37 , 0 ) ;
}
static void F_56 ( struct V_36 * V_37 )
{
F_57 ( V_37 , 0 ) ;
}
static void F_58 ( struct V_36 * V_37 )
{
F_59 ( 0 ) ;
}
static void F_60 ( struct V_36 * V_37 )
{
F_61 () ;
}
static void F_62 ( struct V_36 * V_37 )
{
F_63 () ;
}
static void F_64 ( struct V_36 * V_37 )
{
V_83 = true ;
}
static void F_65 ( struct V_36 * V_37 )
{
F_66 ( & V_84 . V_85 ) ;
if ( V_84 . V_86 )
if ( F_67 ( V_84 . V_86 , V_84 . V_87 , 1 ) ) {
F_68 ( V_84 . V_86 ) ;
V_84 . V_86 = NULL ;
}
F_69 ( & V_84 . V_85 ) ;
}
static void F_70 ( struct V_36 * V_37 )
{
struct V_88 * V_89 = & V_90 [ V_79 ] . V_89 ;
F_71 ( V_89 ) ;
}
static void F_72 ( struct V_36 * V_37 )
{
F_27 () ;
}
static void F_73 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
}
static void F_74 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
if ( V_92 )
return;
if ( V_91 >= F_28 ( V_93 ) )
return;
if ( ( V_67 -> V_68 == V_94 ||
V_67 -> V_68 == V_95 ||
V_67 -> V_68 == V_96 ) &&
V_91 != F_31 ( V_97 ) )
return;
V_93 [ V_91 ] ( V_37 ) ;
}
static void F_75 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
F_76 ( L_1 ) ;
}
static void F_77 ( struct V_36 * V_37 , unsigned int V_91 , char V_92 )
{
if ( V_92 )
return;
if ( V_61 )
V_91 = F_32 ( V_37 , V_91 ) ;
if ( V_83 ) {
V_83 = false ;
V_61 = V_91 ;
return;
}
if ( V_67 -> V_68 == V_69 )
F_26 ( V_37 , V_91 ) ;
else {
int V_46 = F_33 ( V_91 ) ;
if ( V_46 != - 1 )
F_21 ( V_37 , V_46 ) ;
}
}
static void F_78 ( struct V_36 * V_37 , unsigned int V_91 , char V_92 )
{
if ( V_92 )
return;
V_61 = ( V_61 ? F_32 ( V_37 , V_91 ) : V_91 ) ;
}
static void F_79 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
F_77 ( V_37 , F_80 ( V_91 ) , V_92 ) ;
}
static void F_81 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
F_78 ( V_37 , V_91 , V_92 ) ;
}
static void F_82 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
static const unsigned char V_98 [ V_99 ] = { '`' , '\'' , '^' , '~' , '"' , ',' } ;
F_78 ( V_37 , V_98 [ V_91 ] , V_92 ) ;
}
static void F_83 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
if ( V_92 )
return;
F_49 ( V_91 ) ;
}
static void F_84 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
if ( V_92 )
return;
if ( ( unsigned ) V_91 < F_28 ( V_100 ) ) {
if ( V_100 [ V_91 ] )
F_24 ( V_37 , V_100 [ V_91 ] ) ;
} else
F_76 ( L_2 , V_91 ) ;
}
static void F_85 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
static const char V_101 [] = L_3 ;
if ( V_92 )
return;
F_25 ( V_37 , V_101 [ V_91 ] , F_35 ( V_67 , V_102 ) ) ;
}
static void F_86 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
static const char V_103 [] = L_4 ;
static const char V_104 [] = L_5 ;
if ( V_92 )
return;
if ( F_35 ( V_67 , V_75 ) && ! V_53 [ V_105 ] ) {
F_25 ( V_37 , V_104 [ V_91 ] , 1 ) ;
return;
}
if ( ! F_87 ( V_67 , V_76 ) ) {
switch ( V_91 ) {
case F_31 ( V_106 ) :
case F_31 ( V_107 ) :
F_84 ( V_37 , F_31 ( V_108 ) , 0 ) ;
return;
case F_31 ( V_109 ) :
F_84 ( V_37 , F_31 ( V_110 ) , 0 ) ;
return;
case F_31 ( V_111 ) :
F_84 ( V_37 , F_31 ( V_112 ) , 0 ) ;
return;
case F_31 ( V_113 ) :
F_85 ( V_37 , F_31 ( V_114 ) , 0 ) ;
return;
case F_31 ( V_115 ) :
F_84 ( V_37 , F_31 ( V_116 ) , 0 ) ;
return;
case F_31 ( V_117 ) :
F_85 ( V_37 , F_31 ( V_118 ) , 0 ) ;
return;
case F_31 ( V_119 ) :
F_85 ( V_37 , F_31 ( V_120 ) , 0 ) ;
return;
case F_31 ( V_121 ) :
F_84 ( V_37 , F_31 ( V_122 ) , 0 ) ;
return;
case F_31 ( V_123 ) :
F_85 ( V_37 , F_31 ( V_124 ) , 0 ) ;
return;
case F_31 ( V_125 ) :
F_84 ( V_37 , F_31 ( V_126 ) , 0 ) ;
return;
case F_31 ( V_127 ) :
F_25 ( V_37 , 'G' , F_35 ( V_67 , V_75 ) ) ;
return;
}
}
F_21 ( V_37 , V_103 [ V_91 ] ) ;
if ( V_91 == F_31 ( V_128 ) && F_35 ( V_67 , V_70 ) )
F_21 ( V_37 , 10 ) ;
}
static void F_88 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
int V_129 = V_52 ;
if ( V_30 )
return;
if ( V_91 == F_31 ( V_59 ) ) {
V_91 = F_31 ( V_60 ) ;
if ( ! V_92 )
F_89 ( V_67 , V_71 ) ;
}
if ( V_92 ) {
if ( V_53 [ V_91 ] )
V_53 [ V_91 ] -- ;
} else
V_53 [ V_91 ] ++ ;
if ( V_53 [ V_91 ] )
V_52 |= ( 1 << V_91 ) ;
else
V_52 &= ~ ( 1 << V_91 ) ;
if ( V_92 && V_52 != V_129 && V_130 != - 1 ) {
if ( V_67 -> V_68 == V_69 )
F_26 ( V_37 , V_130 ) ;
else
F_21 ( V_37 , V_130 & 0xff ) ;
V_130 = - 1 ;
}
}
static void F_90 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
if ( V_92 )
return;
if ( F_35 ( V_67 , V_131 ) ) {
F_21 ( V_37 , '\033' ) ;
F_21 ( V_37 , V_91 ) ;
} else
F_21 ( V_37 , V_91 | 0x80 ) ;
}
static void F_91 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
int V_65 ;
if ( V_92 )
return;
if ( V_91 < 10 ) {
V_65 = 10 ;
} else {
V_91 -= 10 ;
V_65 = 16 ;
}
if ( V_130 == - 1 )
V_130 = V_91 ;
else
V_130 = V_130 * V_65 + V_91 ;
}
static void F_92 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
if ( V_92 || V_30 )
return;
F_93 ( V_67 , V_91 ) ;
}
static void F_94 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
F_88 ( V_37 , V_91 , V_92 ) ;
if ( V_92 || V_30 )
return;
F_95 ( V_67 , V_91 ) ;
if ( ! V_56 [ V_67 -> V_132 ^ V_67 -> V_133 ] ) {
V_67 -> V_133 = 0 ;
F_95 ( V_67 , V_91 ) ;
}
}
static void F_96 ( struct V_36 * V_37 , unsigned int V_134 , char V_92 )
{
static unsigned long V_135 ;
static unsigned V_136 ;
if ( ! V_137 )
F_78 ( V_37 , V_62 | V_134 , V_92 ) ;
else {
V_136 |= V_134 ;
V_135 ++ ;
if ( V_135 == V_137 ) {
F_77 ( V_37 , V_62 | V_136 , V_92 ) ;
V_135 = 0 ;
V_136 = 0 ;
}
}
}
static void F_97 ( struct V_36 * V_37 , unsigned char V_91 , char V_92 )
{
static unsigned V_138 , V_139 ;
static unsigned long V_140 ;
if ( V_67 -> V_68 != V_69 ) {
if ( ! V_92 )
F_98 ( L_6 ) ;
return;
}
if ( ! V_91 ) {
F_77 ( V_37 , V_62 , V_92 ) ;
return;
}
if ( V_91 > 8 )
return;
if ( ! V_92 ) {
V_138 |= 1 << ( V_91 - 1 ) ;
if ( ! V_141 )
V_139 = V_138 ;
} else if ( V_141 ) {
if ( ! V_139 ||
F_99 ( V_28 ,
V_140 + F_100 ( V_141 ) ) ) {
V_139 = V_138 ;
V_140 = V_28 ;
}
V_138 &= ~ ( 1 << ( V_91 - 1 ) ) ;
if ( ! V_138 && V_139 ) {
F_96 ( V_37 , V_139 , 0 ) ;
V_139 = 0 ;
}
} else {
if ( V_139 ) {
F_96 ( V_37 , V_139 , 0 ) ;
V_139 = 0 ;
}
V_138 &= ~ ( 1 << ( V_91 - 1 ) ) ;
}
}
unsigned char F_101 ( void )
{
return V_142 ;
}
void F_102 ( struct V_143 * V_67 , unsigned int V_144 )
{
if ( ! ( V_144 & ~ 7 ) ) {
V_145 = V_144 ;
V_67 -> V_146 = V_147 ;
} else
V_67 -> V_146 = V_148 ;
F_103 () ;
}
static inline unsigned char F_104 ( void )
{
struct V_143 * V_67 = V_149 + V_79 ;
unsigned char V_150 ;
int V_47 ;
if ( V_67 -> V_146 == V_147 )
return V_145 ;
V_150 = V_67 -> V_151 ;
if ( V_67 -> V_146 == V_152 ) {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ )
if ( V_153 [ V_47 ] . V_154 ) {
if ( * V_153 [ V_47 ] . V_155 & V_153 [ V_47 ] . V_156 )
V_150 |= ( 1 << V_47 ) ;
else
V_150 &= ~ ( 1 << V_47 ) ;
}
}
return V_150 ;
}
static int F_105 ( struct V_4 * V_5 , void * V_6 )
{
unsigned char V_150 = * ( unsigned char * ) V_6 ;
if ( F_13 ( V_157 , V_5 -> V_9 -> V_20 ) ) {
F_14 ( V_5 , V_157 , V_158 , ! ! ( V_150 & 0x01 ) ) ;
F_14 ( V_5 , V_157 , V_159 , ! ! ( V_150 & 0x02 ) ) ;
F_14 ( V_5 , V_157 , V_160 , ! ! ( V_150 & 0x04 ) ) ;
F_14 ( V_5 , V_161 , V_162 , 0 ) ;
}
return 0 ;
}
static void F_106 ( unsigned long V_163 )
{
unsigned char V_150 = F_104 () ;
if ( V_150 != V_142 ) {
F_8 ( & V_16 , & V_150 ,
F_105 ) ;
V_142 = V_150 ;
}
}
static int F_107 ( struct V_36 * V_37 , unsigned int V_14 ,
unsigned char V_92 )
{
int V_164 ;
switch ( V_14 ) {
case V_165 :
F_21 ( V_37 , 0xe1 ) ;
F_21 ( V_37 , 0x1d | V_92 ) ;
F_21 ( V_37 , 0x45 | V_92 ) ;
break;
case V_166 :
if ( ! V_92 )
F_21 ( V_37 , 0xf2 ) ;
break;
case V_167 :
if ( ! V_92 )
F_21 ( V_37 , 0xf1 ) ;
break;
case V_168 :
if ( F_13 ( V_169 , V_54 ) ||
F_13 ( V_170 , V_54 ) ) {
F_21 ( V_37 , 0x54 | V_92 ) ;
} else {
F_21 ( V_37 , 0xe0 ) ;
F_21 ( V_37 , 0x2a | V_92 ) ;
F_21 ( V_37 , 0xe0 ) ;
F_21 ( V_37 , 0x37 | V_92 ) ;
}
break;
default:
if ( V_14 > 255 )
return - 1 ;
V_164 = V_171 [ V_14 ] ;
if ( ! V_164 )
return - 1 ;
if ( V_164 & 0x100 )
F_21 ( V_37 , 0xe0 ) ;
F_21 ( V_37 , ( V_164 & 0x7f ) | V_92 ) ;
break;
}
return 0 ;
}
static int F_107 ( struct V_36 * V_37 , unsigned int V_14 , unsigned char V_92 )
{
if ( V_14 > 127 )
return - 1 ;
F_21 ( V_37 , V_14 | V_92 ) ;
return 0 ;
}
static void F_108 ( unsigned char V_6 )
{
struct V_36 * V_37 = V_90 [ V_79 ] . V_8 ;
V_67 = V_149 + V_37 -> V_172 ;
if ( V_67 -> V_68 == V_94 )
F_21 ( V_37 , V_6 ) ;
}
static void F_109 ( unsigned int V_14 , int V_173 , int V_174 )
{
struct V_36 * V_37 = V_90 [ V_79 ] . V_8 ;
unsigned short V_175 , * V_176 ;
unsigned char type ;
bool V_177 ;
struct V_39 * V_40 ;
int V_178 ;
struct V_179 V_180 = { . V_37 = V_37 , . V_91 = V_14 , . V_173 = V_173 } ;
int V_181 ;
V_40 = V_37 -> V_41 . V_40 ;
if ( V_40 && ( ! V_40 -> V_182 ) ) {
V_40 -> V_182 = V_37 ;
}
V_67 = V_149 + V_37 -> V_172 ;
#ifdef F_110
if ( V_14 == V_183 )
V_184 = V_173 ;
#endif
V_30 = ( V_173 == 2 ) ;
V_177 = ( V_67 -> V_68 == V_94 ) ;
if ( V_177 && ! V_174 )
if ( F_107 ( V_37 , V_14 , ! V_173 << 7 ) )
if ( V_14 < V_185 && F_111 () )
F_98 ( L_7 ,
V_14 ) ;
#ifdef F_110
if ( V_14 == V_186 && V_184 ) {
V_184 = false ;
F_112 () ;
}
#endif
if ( V_67 -> V_68 == V_95 ) {
if ( V_14 < 128 ) {
F_21 ( V_37 , V_14 | ( ! V_173 << 7 ) ) ;
} else {
F_21 ( V_37 , ! V_173 << 7 ) ;
F_21 ( V_37 , ( V_14 >> 7 ) | 0x80 ) ;
F_21 ( V_37 , V_14 | 0x80 ) ;
}
V_177 = true ;
}
if ( V_173 )
F_113 ( V_14 , V_54 ) ;
else
F_114 ( V_14 , V_54 ) ;
if ( V_30 &&
( ! F_35 ( V_67 , V_187 ) ||
( V_40 && ! F_115 ( V_40 ) && F_116 ( V_40 ) ) ) ) {
return;
}
V_180 . V_188 = V_178 = ( V_52 | V_67 -> V_133 ) ^ V_67 -> V_132 ;
V_180 . V_142 = V_67 -> V_151 ;
V_176 = V_56 [ V_178 ] ;
V_181 = F_117 ( & V_3 ,
V_189 , & V_180 ) ;
if ( V_181 == V_190 || ! V_176 ) {
F_117 ( & V_3 ,
V_191 , & V_180 ) ;
F_27 () ;
V_67 -> V_133 = 0 ;
return;
}
if ( V_14 < V_192 )
V_175 = V_176 [ V_14 ] ;
else if ( V_14 >= V_193 && V_14 <= V_194 )
V_175 = F_29 ( F_118 ( V_195 , V_14 - V_193 + 1 ) ) ;
else
return;
type = F_30 ( V_175 ) ;
if ( type < 0xf0 ) {
V_180 . V_91 = V_175 ;
V_181 = F_117 ( & V_3 ,
V_196 , & V_180 ) ;
if ( V_181 != V_190 )
if ( V_173 && ! V_177 )
F_26 ( V_37 , V_175 ) ;
return;
}
type -= 0xf0 ;
if ( type == V_197 ) {
type = V_198 ;
if ( F_87 ( V_67 , V_71 ) ) {
V_176 = V_56 [ V_178 ^ ( 1 << V_105 ) ] ;
if ( V_176 )
V_175 = V_176 [ V_14 ] ;
}
}
V_180 . V_91 = V_175 ;
V_181 = F_117 ( & V_3 ,
V_199 , & V_180 ) ;
if ( V_181 == V_190 )
return;
if ( ( V_177 || V_67 -> V_68 == V_96 ) && type != V_200 && type != V_57 )
return;
(* F_119 [ type ])( V_37 , V_175 & 0xff , ! V_173 ) ;
V_180 . V_142 = V_67 -> V_151 ;
F_117 ( & V_3 , V_201 , & V_180 ) ;
if ( type != V_58 )
V_67 -> V_133 = 0 ;
}
static void F_120 ( struct V_4 * V_5 , unsigned int V_202 ,
unsigned int V_203 , int V_91 )
{
F_66 ( & V_204 ) ;
if ( V_202 == V_205 && V_203 == V_206 && F_121 ( V_5 -> V_9 ) )
F_108 ( V_91 ) ;
if ( V_202 == V_207 )
F_109 ( V_203 , V_91 , F_121 ( V_5 -> V_9 ) ) ;
F_69 ( & V_204 ) ;
F_122 ( & V_208 ) ;
V_209 = 1 ;
F_123 () ;
}
static bool F_124 ( struct V_210 * V_211 , struct V_18 * V_9 )
{
int V_47 ;
if ( F_13 ( V_19 , V_9 -> V_20 ) )
return true ;
if ( F_13 ( V_207 , V_9 -> V_20 ) ) {
for ( V_47 = V_212 ; V_47 < V_185 ; V_47 ++ )
if ( F_13 ( V_47 , V_9 -> V_213 ) )
return true ;
for ( V_47 = V_193 ; V_47 <= V_214 ; V_47 ++ )
if ( F_13 ( V_47 , V_9 -> V_213 ) )
return true ;
}
return false ;
}
static int F_125 ( struct V_210 * V_211 , struct V_18 * V_9 ,
const struct V_215 * V_216 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_126 ( sizeof( struct V_4 ) , V_217 ) ;
if ( ! V_5 )
return - V_218 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_211 = V_211 ;
V_5 -> V_219 = L_8 ;
error = F_127 ( V_5 ) ;
if ( error )
goto V_220;
error = F_128 ( V_5 ) ;
if ( error )
goto V_221;
return 0 ;
V_221:
F_129 ( V_5 ) ;
V_220:
F_130 ( V_5 ) ;
return error ;
}
static void F_131 ( struct V_4 * V_5 )
{
F_132 ( V_5 ) ;
F_129 ( V_5 ) ;
F_130 ( V_5 ) ;
}
static void F_133 ( struct V_4 * V_5 )
{
F_134 ( & V_208 ) ;
if ( V_142 != 0xff )
F_105 ( V_5 , & V_142 ) ;
F_135 ( & V_208 ) ;
}
int T_2 F_136 ( void )
{
int V_47 ;
int error ;
for ( V_47 = 0 ; V_47 < V_81 ; V_47 ++ ) {
V_149 [ V_47 ] . V_151 = V_222 ;
V_149 [ V_47 ] . V_223 = V_222 ;
V_149 [ V_47 ] . V_146 = V_148 ;
V_149 [ V_47 ] . V_132 = V_224 ;
V_149 [ V_47 ] . V_133 = 0 ;
V_149 [ V_47 ] . V_225 = V_226 ;
V_149 [ V_47 ] . V_68 = V_227 ? V_69 : V_228 ;
}
error = F_137 ( & V_16 ) ;
if ( error )
return error ;
F_135 ( & V_208 ) ;
F_122 ( & V_208 ) ;
return 0 ;
}
