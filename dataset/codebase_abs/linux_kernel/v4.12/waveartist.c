static inline void
F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned int V_5 = V_2 -> V_6 + V_7 ;
V_3 = ~ V_3 & F_2 ( V_5 ) ;
F_3 ( V_3 | V_4 , V_5 ) ;
}
static inline void
F_4 ( struct V_8 * V_9 )
{
unsigned int V_5 = V_9 -> V_2 . V_6 + V_7 ;
int V_10 ;
V_10 = F_2 ( V_5 ) & ~ V_11 ;
F_3 ( V_10 | V_11 , V_5 ) ;
F_3 ( V_10 , V_5 ) ;
}
static inline int
F_5 ( int V_12 )
{
unsigned int V_13 = F_6 ( V_12 * 100 ) ;
return F_7 ( V_13 ) ;
}
static int
F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
unsigned int V_13 , V_14 = - 1 ;
F_1 ( V_2 , - 1 , V_15 ) ;
F_5 ( 2 ) ;
F_1 ( V_2 , V_15 , 0 ) ;
V_13 = 500 ;
do {
F_9 ( 2 ) ;
if ( F_2 ( V_2 -> V_6 + V_16 ) & V_17 ) {
V_14 = F_10 ( V_2 -> V_6 + V_18 ) ;
if ( V_14 == 0x55aa )
break;
}
} while ( -- V_13 );
if ( V_13 == 0 ) {
F_11 ( V_19 L_1 ) ;
if ( V_14 != ( unsigned int ) - 1 )
F_11 ( L_2 , V_14 ) ;
F_11 ( L_3 ) ;
return 1 ;
}
return 0 ;
}
static int
F_12 ( struct V_8 * V_9 ,
int V_20 , unsigned int * V_21 ,
int V_22 , unsigned int * V_23 )
{
unsigned int V_6 = V_9 -> V_2 . V_6 ;
unsigned int V_24 = 0 ;
unsigned int V_25 ;
if ( V_26 & V_27 ) {
F_11 ( L_4 ) ;
for ( V_25 = 0 ; V_25 < V_20 ; V_25 ++ )
F_11 ( L_5 , V_21 [ V_25 ] ) ;
F_11 ( L_3 ) ;
}
if ( F_2 ( V_6 + V_16 ) & V_17 ) {
int V_28 ;
V_28 = F_10 ( V_6 + V_18 ) ;
if ( V_26 & V_27 )
F_11 ( L_6 , V_28 ) ;
F_13 ( 10 ) ;
}
for ( V_25 = 0 ; ! V_24 && V_25 < V_20 ; V_25 ++ ) {
int V_29 ;
for ( V_29 = 5000 ; V_29 ; V_29 -- )
if ( F_2 ( V_6 + V_16 ) & V_30 )
break;
if ( ! V_29 )
V_24 = 1 ;
else
F_14 ( V_21 [ V_25 ] , V_6 + V_18 ) ;
}
for ( V_25 = 0 ; ! V_24 && V_25 < V_22 ; V_25 ++ ) {
int V_29 ;
for ( V_29 = 5000 ; V_29 ; V_29 -- )
if ( F_2 ( V_6 + V_16 ) & V_17 )
break;
if ( ! V_29 )
V_24 = 1 ;
else
V_23 [ V_25 ] = F_10 ( V_6 + V_18 ) ;
}
if ( V_26 & V_27 ) {
if ( ! V_24 ) {
F_11 ( L_7 ) ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
F_11 ( L_5 , V_23 [ V_25 ] ) ;
F_11 ( L_3 ) ;
} else
F_11 ( L_8 ) ;
}
return V_24 ? 1 : 0 ;
}
static inline int
F_15 ( struct V_8 * V_9 , unsigned int V_21 )
{
return F_12 ( V_9 , 1 , & V_21 , 0 , NULL ) ;
}
static inline unsigned int
F_16 ( struct V_8 * V_9 , unsigned int V_21 )
{
unsigned int V_31 ;
F_12 ( V_9 , 1 , & V_21 , 1 , & V_31 ) ;
return V_31 ;
}
static inline int
F_17 ( struct V_8 * V_9 , unsigned int V_21 , unsigned int V_32 )
{
unsigned int V_33 [ 2 ] ;
V_33 [ 0 ] = V_21 ;
V_33 [ 1 ] = V_32 ;
return F_12 ( V_9 , 2 , V_33 , 1 , V_33 ) ;
}
static inline int
F_18 ( struct V_8 * V_9 , unsigned int V_21 ,
unsigned int V_34 , unsigned int V_35 )
{
unsigned int V_33 [ 3 ] ;
V_33 [ 0 ] = V_21 ;
V_33 [ 1 ] = V_34 ;
V_33 [ 2 ] = V_35 ;
return F_12 ( V_9 , 3 , V_33 , 0 , NULL ) ;
}
static int
F_19 ( struct V_8 * V_9 , char * V_36 )
{
unsigned int V_37 [ 2 ] ;
unsigned int V_21 = V_38 ;
F_12 ( V_9 , 1 , & V_21 , 2 , V_37 ) ;
V_36 [ 0 ] = V_37 [ 0 ] >> 8 ;
V_36 [ 1 ] = V_37 [ 0 ] & 255 ;
V_36 [ 2 ] = '\0' ;
return V_37 [ 0 ] ;
}
static int
F_20 ( int V_39 , int V_40 )
{
struct V_8 * V_9 ;
struct V_41 * V_42 ;
unsigned long V_43 ;
if ( V_39 < 0 || V_39 >= V_44 )
return - V_45 ;
V_9 = (struct V_8 * ) V_46 [ V_39 ] -> V_9 ;
V_42 = (struct V_41 * ) V_46 [ V_39 ] -> V_42 ;
F_21 ( & V_47 , V_43 ) ;
if ( V_42 -> V_48 || ( V_9 -> V_48 & V_40 ) ) {
F_22 ( & V_47 , V_43 ) ;
return - V_49 ;
}
V_9 -> V_50 = 0 ;
V_9 -> V_48 |= V_40 ;
V_42 -> V_48 = V_40 ;
F_23 ( V_39 , 0 ) ;
if ( V_40 & V_51 )
V_9 -> V_52 = V_39 ;
if ( V_40 & V_53 )
V_9 -> V_54 = V_39 ;
F_22 ( & V_47 , V_43 ) ;
return 0 ;
}
static void
F_24 ( int V_39 )
{
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
unsigned long V_43 ;
F_21 ( & V_47 , V_43 ) ;
F_25 ( V_39 ) ;
V_9 -> V_50 = 0 ;
V_9 -> V_48 &= ~ V_42 -> V_48 ;
V_42 -> V_48 = 0 ;
F_22 ( & V_47 , V_43 ) ;
}
static void
F_26 ( int V_39 , unsigned long V_55 , int V_56 , int V_57 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
unsigned long V_43 ;
unsigned int V_29 = V_56 ;
if ( V_26 & V_58 )
F_11 ( L_9 ,
V_55 , V_29 ) ;
if ( V_42 -> V_59 & ( V_60 | V_61 ) )
V_29 >>= 1 ;
if ( V_42 -> V_62 > 1 )
V_29 >>= 1 ;
V_29 -= 1 ;
if ( V_9 -> V_50 & V_63 &&
V_46 [ V_39 ] -> V_43 & V_64 &&
V_57 &&
V_29 == V_9 -> V_65 ) {
V_9 -> V_50 |= V_63 ;
return;
}
F_21 ( & V_47 , V_43 ) ;
F_17 ( V_9 , V_66 , V_29 ) ;
V_9 -> V_65 = V_29 ;
V_9 -> V_50 |= V_63 ;
F_22 ( & V_47 , V_43 ) ;
}
static void
F_27 ( int V_39 , unsigned long V_55 , int V_56 , int V_57 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
unsigned long V_43 ;
unsigned int V_29 = V_56 ;
if ( V_26 & V_67 )
F_11 ( L_10 ,
V_55 , V_29 ) ;
if ( V_42 -> V_59 & ( V_60 | V_61 ) )
V_29 >>= 1 ;
if ( V_42 -> V_62 > 1 )
V_29 >>= 1 ;
V_29 -= 1 ;
if ( V_9 -> V_50 & V_68 &&
V_46 [ V_39 ] -> V_43 & V_64 &&
V_57 &&
V_29 == V_9 -> V_65 ) {
V_9 -> V_50 |= V_68 ;
return;
}
F_21 ( & V_47 , V_43 ) ;
F_17 ( V_9 , V_69 , V_29 ) ;
V_9 -> V_65 = V_29 ;
V_9 -> V_50 |= V_68 ;
F_22 ( & V_47 , V_43 ) ;
}
static int
F_28 ( int V_39 , unsigned int V_21 , void T_1 * V_32 )
{
return - V_70 ;
}
static unsigned int
F_29 ( struct V_41 * V_42 )
{
unsigned int V_71 ;
if ( V_42 -> V_71 == 8000 )
V_71 = 0x2E71 ;
else if ( V_42 -> V_71 == 11025 )
V_71 = 0x4000 ;
else if ( V_42 -> V_71 == 22050 )
V_71 = 0x8000 ;
else if ( V_42 -> V_71 == 44100 )
V_71 = 0x0 ;
else {
V_71 = V_42 -> V_71 << 16 ;
V_71 = ( V_71 / 44100 ) & 65535 ;
}
return V_71 ;
}
static unsigned int
F_30 ( struct V_41 * V_42 )
{
unsigned int V_72 ;
if ( V_42 -> V_59 == V_60 )
V_72 = 1 ;
else if ( V_42 -> V_59 == V_73 )
V_72 = 0 ;
else
V_72 = 2 ;
return V_72 ;
}
static int
F_31 ( int V_39 , int V_74 , int V_75 )
{
unsigned long V_43 ;
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
unsigned int V_71 , V_72 ;
if ( V_9 -> V_50 )
return 0 ;
V_71 = F_29 ( V_42 ) ;
V_72 = F_30 ( V_42 ) ;
F_21 ( & V_47 , V_43 ) ;
if ( F_17 ( V_9 , V_76 , V_72 ) )
F_11 ( V_19 L_11
L_12 , V_42 -> V_59 ) ;
if ( F_17 ( V_9 , V_77 , V_42 -> V_62 ) )
F_11 ( V_19 L_13
L_14 , V_42 -> V_62 ) ;
if ( F_17 ( V_9 , V_78 , V_71 ) )
F_11 ( V_19 L_15
L_16 , V_42 -> V_71 ) ;
if ( F_17 ( V_9 , V_79 , 1 ) )
F_11 ( V_19 L_15
L_17 , 1 ) ;
if ( F_17 ( V_9 , V_76 , V_72 ) )
F_11 ( V_19 L_15
L_18 , V_42 -> V_59 ) ;
V_9 -> V_65 = 0 ;
F_22 ( & V_47 , V_43 ) ;
F_32 ( V_39 ) ;
if ( V_26 & V_80 ) {
F_11 ( L_19 ,
F_2 ( V_9 -> V_2 . V_6 + V_7 ) ) ;
F_11 ( L_20 ,
F_2 ( V_9 -> V_2 . V_6 + V_16 ) ) ;
F_11 ( L_21 ,
F_2 ( V_9 -> V_2 . V_6 + V_81 ) ) ;
}
return 0 ;
}
static int
F_33 ( int V_39 , int V_74 , int V_75 )
{
unsigned long V_43 ;
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
unsigned int V_71 , V_72 ;
V_71 = F_29 ( V_42 ) ;
V_72 = F_30 ( V_42 ) ;
F_21 ( & V_47 , V_43 ) ;
if ( F_17 ( V_9 , V_82 , V_71 ) &&
F_17 ( V_9 , V_82 , V_71 ) )
F_11 ( V_19 L_22
L_16 , V_42 -> V_71 ) ;
if ( F_17 ( V_9 , V_83 , V_42 -> V_62 ) )
F_11 ( V_19 L_22
L_14 , V_42 -> V_62 ) ;
if ( F_17 ( V_9 , V_84 , 0 ) )
F_11 ( V_19 L_22
L_17 , 0 ) ;
if ( F_17 ( V_9 , V_85 , V_72 ) )
F_11 ( V_19 L_22
L_18 , V_42 -> V_59 ) ;
V_9 -> V_65 = 0 ;
F_22 ( & V_47 , V_43 ) ;
F_34 ( V_39 ) ;
if ( V_26 & V_80 ) {
F_11 ( L_19 , F_2 ( V_9 -> V_2 . V_6 + V_7 ) ) ;
F_11 ( L_20 , F_2 ( V_9 -> V_2 . V_6 + V_16 ) ) ;
F_11 ( L_21 , F_2 ( V_9 -> V_2 . V_6 + V_81 ) ) ;
}
return 0 ;
}
static void
F_25 ( int V_39 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
struct V_8 * V_9 ;
if ( V_42 -> V_48 & V_53 )
F_34 ( V_39 ) ;
if ( V_42 -> V_48 & V_51 )
F_32 ( V_39 ) ;
V_9 = (struct V_8 * ) V_46 [ V_39 ] -> V_9 ;
V_9 -> V_50 = 0 ;
}
static void
F_32 ( int V_39 )
{
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
unsigned long V_43 ;
F_21 ( & V_47 , V_43 ) ;
F_15 ( V_9 , V_86 ) ;
V_9 -> V_50 &= ~ V_68 ;
if ( F_2 ( V_9 -> V_2 . V_6 + V_16 ) & V_87 )
F_4 ( V_9 ) ;
F_22 ( & V_47 , V_43 ) ;
}
static void
F_34 ( int V_39 )
{
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
unsigned long V_43 ;
F_21 ( & V_47 , V_43 ) ;
F_15 ( V_9 , V_88 ) ;
V_9 -> V_50 &= ~ V_63 ;
if ( F_2 ( V_9 -> V_2 . V_6 + V_16 ) & V_87 )
F_4 ( V_9 ) ;
F_22 ( & V_47 , V_43 ) ;
}
static void
F_23 ( int V_39 , int V_89 )
{
struct V_8 * V_9 = (struct V_8 * )
V_46 [ V_39 ] -> V_9 ;
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
unsigned long V_43 ;
if ( V_26 & V_90 ) {
F_11 ( L_23 ) ;
if ( V_89 & V_68 )
F_11 ( L_24 ) ;
if ( V_89 & V_63 )
F_11 ( L_25 ) ;
F_11 ( L_3 ) ;
}
F_21 ( & V_47 , V_43 ) ;
V_89 &= V_9 -> V_50 ;
if ( V_42 -> V_48 & V_51 &&
V_89 & V_68 )
F_15 ( V_9 , V_91 ) ;
if ( V_42 -> V_48 & V_53 &&
V_89 & V_63 )
F_15 ( V_9 , V_92 ) ;
F_22 ( & V_47 , V_43 ) ;
}
static int
F_35 ( int V_39 , int V_32 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
if ( V_32 <= 0 )
return V_42 -> V_71 ;
if ( V_32 < 5000 )
V_32 = 5000 ;
if ( V_32 > 44100 )
V_32 = 44100 ;
V_42 -> V_71 = V_32 ;
return V_42 -> V_71 ;
}
static short
F_36 ( int V_39 , short V_32 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
if ( V_32 != 1 && V_32 != 2 )
return V_42 -> V_62 ;
V_42 -> V_62 = V_32 ;
return V_32 ;
}
static unsigned int
F_37 ( int V_39 , unsigned int V_32 )
{
struct V_41 * V_42 = (struct V_41 * )
V_46 [ V_39 ] -> V_42 ;
if ( V_32 == 0 )
return V_42 -> V_59 ;
if ( ( V_32 != V_93 ) && ( V_32 != V_60 ) && ( V_32 != V_73 ) )
V_32 = V_93 ;
V_42 -> V_59 = V_32 ;
return V_32 ;
}
static T_2
F_38 ( int V_94 , void * V_95 )
{
struct V_8 * V_9 = V_95 ;
int V_96 , V_97 ;
F_39 ( & V_47 ) ;
V_96 = F_2 ( V_9 -> V_2 . V_6 + V_81 ) ;
V_97 = F_2 ( V_9 -> V_2 . V_6 + V_16 ) ;
if ( V_26 & V_80 )
F_11 ( L_26 ,
V_97 , V_96 ) ;
if ( V_97 & V_87 )
F_4 ( V_9 ) ;
else
F_11 ( V_19 L_27 ) ;
if ( V_96 & 0x01 ) {
int V_37 = 1 ;
if ( ( V_97 & V_98 ) && ( V_9 -> V_50 & V_63 ) ) {
F_40 ( V_9 -> V_54 , 1 ) ;
V_37 = 0 ;
}
if ( ( V_97 & V_99 ) && ( V_9 -> V_50 & V_68 ) ) {
F_41 ( V_9 -> V_52 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_11 ( V_19 L_28 ) ;
}
if ( V_96 & 0x2 )
F_11 ( V_19 L_29 ) ;
F_42 ( & V_47 ) ;
return V_100 ;
}
static void
F_43 ( struct V_8 * V_9 , int V_101 )
{
unsigned int V_102 , V_103 ;
V_102 = V_9 -> V_104 [ V_101 ] & 0xff ;
V_103 = V_9 -> V_104 [ V_101 ] >> 8 ;
if ( V_102 > 100 )
V_102 = 100 ;
if ( V_103 > 100 )
V_103 = 100 ;
#define F_44 ( T_3 , T_4 ) ((lev) * (max) / 100)
if ( F_45 () && V_101 == V_105 )
V_101 = V_106 ;
if ( V_107 [ V_101 ] . V_108 || V_107 [ V_101 ] . V_109 ) {
const struct V_110 * V_111 = V_107 + V_101 ;
unsigned int V_112 , V_113 , V_114 ;
V_112 = V_111 -> T_4 << V_111 -> V_115 ;
V_102 = F_44 ( V_102 , V_111 -> T_4 ) << V_111 -> V_115 ;
V_103 = F_44 ( V_103 , V_111 -> T_4 ) << V_111 -> V_115 ;
V_113 = F_16 ( V_9 , V_116 |
V_111 -> V_108 << 8 ) ;
V_114 = F_16 ( V_9 , V_116 |
V_111 -> V_109 << 8 ) ;
V_113 = ( V_113 & ~ V_112 ) | ( V_102 & V_112 ) ;
V_114 = ( V_114 & ~ V_112 ) | ( V_103 & V_112 ) ;
F_18 ( V_9 , V_117 , V_113 , V_114 ) ;
} else {
switch( V_101 ) {
case V_118 :
F_18 ( V_9 , V_119 ,
F_44 ( V_102 , 32767 ) ,
F_44 ( V_103 , 32767 ) ) ;
break;
case V_120 :
F_18 ( V_9 , 0x0100 | V_119 ,
F_44 ( V_102 , 32767 ) ,
F_44 ( V_103 , 32767 ) ) ;
break;
}
}
}
static void
F_46 ( struct V_8 * V_9 , char V_121 ,
char V_122 )
{
unsigned int V_123 , V_124 ;
V_123 = F_16 ( V_9 , V_116 | 0x0800 ) ;
V_124 = F_16 ( V_9 , V_116 | 0x0900 ) ;
V_123 = ( V_123 & ~ 0x3f ) | V_122 << 3 | V_121 ;
F_18 ( V_9 , V_117 , V_123 , V_124 ) ;
}
static unsigned int
F_47 ( struct V_8 * V_9 , unsigned int V_125 ,
unsigned char * V_126 , unsigned char * V_127 )
{
unsigned int V_128 = V_129 ;
if ( V_125 & V_130 ) {
V_125 = V_130 ;
V_128 = V_131 ;
} else if ( V_125 & V_132 ) {
V_125 = V_132 ;
V_128 = V_133 ;
} else if ( V_125 & V_134 ) {
V_125 = V_134 ;
V_128 = V_135 ;
} else if ( V_125 & V_136 ) {
V_125 = V_136 ;
V_128 = V_137 ;
} else if ( V_125 & V_138 ) {
V_125 = V_138 ;
V_128 = V_139 ;
}
* V_126 = * V_127 = V_128 ;
return V_125 ;
}
static int
F_48 ( struct V_8 * V_9 , int V_39 ,
unsigned char V_140 ,
unsigned char V_141 )
{
switch ( V_39 ) {
case V_106 :
case V_120 :
case V_118 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_9 -> V_104 [ V_39 ] = V_140 | V_141 << 8 ;
break;
case V_147 :
break;
default:
V_39 = - V_70 ;
break;
}
return V_39 ;
}
static int F_49 ( struct V_8 * V_9 , int V_39 )
{
return V_9 -> V_104 [ V_39 ] ;
}
static void
F_50 ( struct V_8 * V_9 , unsigned int V_125 )
{
unsigned char V_126 , V_127 ;
V_125 &= V_9 -> V_111 -> V_148 ;
if ( F_51 ( V_125 ) > 1 )
V_125 &= ~ V_9 -> V_125 ;
V_9 -> V_125 = V_9 -> V_111 -> V_149 ( V_9 , V_125 ,
& V_126 , & V_127 ) ;
F_46 ( V_9 , V_126 , V_127 ) ;
}
static int
F_52 ( struct V_8 * V_9 , int V_39 , unsigned int V_150 )
{
unsigned int V_102 = V_150 & 0x00ff ;
unsigned int V_103 = ( V_150 & 0xff00 ) >> 8 ;
if ( V_102 > 100 )
V_102 = 100 ;
if ( V_103 > 100 )
V_103 = 100 ;
if ( ! ( V_9 -> V_111 -> V_151 & ( 1 << V_39 ) ) )
V_103 = V_102 ;
V_39 = V_9 -> V_111 -> V_152 ( V_9 , V_39 , V_102 , V_103 ) ;
if ( V_39 >= 0 )
F_43 ( V_9 , V_39 ) ;
return V_39 < 0 ? V_39 : 0 ;
}
static int
F_53 ( int V_39 , unsigned int V_21 , void T_1 * V_32 )
{
struct V_8 * V_9 = (struct V_8 * ) V_46 [ V_39 ] -> V_9 ;
int V_31 = 0 , V_153 , V_154 ;
if ( ( ( V_21 >> 8 ) & 255 ) != 'M' )
return - V_155 ;
#ifdef F_54
if ( F_45 () ) {
V_31 = F_55 ( V_39 , V_21 , V_32 ) ;
if ( V_31 != - V_155 )
return V_31 ;
else
V_31 = 0 ;
}
#endif
V_154 = V_21 & 0xff ;
if ( F_56 ( V_21 ) & V_156 ) {
if ( F_57 ( V_153 , ( int T_1 * ) V_32 ) )
return - V_157 ;
switch ( V_154 ) {
case V_158 :
F_50 ( V_9 , V_153 ) ;
break;
default:
V_31 = - V_70 ;
if ( V_154 < V_159 &&
V_9 -> V_111 -> V_160 & ( 1 << V_154 ) )
V_31 = F_52 ( V_9 , V_154 , V_153 ) ;
}
}
if ( V_31 == 0 && F_56 ( V_21 ) & V_161 ) {
V_31 = - V_70 ;
switch ( V_154 ) {
case V_158 :
V_31 = V_9 -> V_125 ;
break;
case V_162 :
V_31 = V_9 -> V_111 -> V_160 ;
break;
case V_163 :
V_31 = V_9 -> V_111 -> V_151 ;
break;
case V_164 :
V_31 = V_9 -> V_111 -> V_148 ;
break;
case V_165 :
V_31 = V_166 ;
break;
default:
if ( V_154 < V_159 )
V_31 = V_9 -> V_111 -> V_167 ( V_9 , V_154 ) ;
break;
}
if ( V_31 >= 0 )
V_31 = F_58 ( V_31 , ( int T_1 * ) V_32 ) ? - V_157 : 0 ;
}
return V_31 ;
}
static void
F_59 ( struct V_8 * V_9 )
{
int V_25 ;
if ( V_26 & V_168 )
F_11 ( L_30 , V_9 -> V_2 . V_169 ) ;
F_15 ( V_9 , V_170 ) ;
F_18 ( V_9 , V_117 , 0x9800 , 0xa836 ) ;
F_18 ( V_9 , V_117 , 0x4c00 , 0x8c00 ) ;
F_18 ( V_9 , V_117 , 0x2801 , 0x6800 ) ;
F_50 ( V_9 , 0 ) ;
for ( V_25 = 0 ; V_25 < V_159 ; V_25 ++ )
F_43 ( V_9 , V_25 ) ;
}
static int T_5 F_60 ( struct V_8 * V_9 )
{
struct V_41 * V_42 ;
char V_36 [ 3 ] , V_171 [ 64 ] ;
int V_172 ;
if ( F_8 ( V_9 ) )
return - V_173 ;
sprintf ( V_171 , L_31 , V_9 -> V_2 . V_169 , V_9 -> V_174 ) ;
if ( F_19 ( V_9 , V_36 ) ) {
strcat ( V_171 , L_32 ) ;
strcat ( V_171 , V_36 ) ;
}
strcat ( V_171 , L_33 ) ;
F_61 ( V_171 , V_9 -> V_2 . V_6 , V_9 -> V_2 . V_94 ,
V_9 -> V_2 . V_175 , V_9 -> V_2 . V_176 ) ;
V_42 = F_62 ( sizeof( struct V_41 ) , V_177 ) ;
if ( V_42 == NULL )
goto V_178;
V_172 = F_63 ( V_179 , V_171 ,
& V_180 , sizeof( struct V_181 ) ,
V_9 -> V_182 , V_93 | V_60 | V_73 ,
V_9 , V_9 -> V_2 . V_175 , V_9 -> V_2 . V_176 ) ;
if ( V_172 < 0 )
goto free;
V_46 [ V_172 ] -> V_42 = V_42 ;
F_59 ( V_9 ) ;
F_4 ( V_9 ) ;
if ( F_64 ( V_9 -> V_2 . V_94 , F_38 , 0 , V_9 -> V_2 . V_169 , V_9 ) < 0 ) {
F_11 ( V_183 L_34 ,
V_9 -> V_2 . V_169 , V_9 -> V_2 . V_94 ) ;
goto V_184;
}
if ( F_65 ( V_9 -> V_2 . V_175 , V_9 -> V_2 . V_169 ) ) {
F_11 ( V_183 L_35 ,
V_9 -> V_2 . V_169 , V_9 -> V_2 . V_175 ) ;
goto V_185;
}
if ( V_9 -> V_2 . V_175 != V_9 -> V_2 . V_176 && V_9 -> V_2 . V_176 != V_186 )
if ( F_65 ( V_9 -> V_2 . V_176 , V_9 -> V_2 . V_169 ) ) {
F_11 ( V_183 L_36 ,
V_9 -> V_2 . V_169 , V_9 -> V_2 . V_176 ) ;
goto V_187;
}
F_1 ( & V_9 -> V_2 , 0 , V_188 | V_189 ) ;
V_46 [ V_172 ] -> V_190 =
F_66 ( V_191 ,
V_171 ,
& V_192 ,
sizeof( struct V_193 ) ,
V_9 ) ;
return V_172 ;
V_187:
F_67 ( V_9 -> V_2 . V_175 ) ;
V_185:
F_68 ( V_9 -> V_2 . V_94 , V_9 ) ;
V_184:
F_69 ( V_172 ) ;
free:
F_70 ( V_42 ) ;
V_178:
return - 1 ;
}
static int T_5 F_71 ( struct V_1 * V_194 )
{
struct V_8 * V_9 = & V_195 [ V_196 ] ;
if ( V_196 >= V_197 ) {
F_11 ( V_19 L_37 ) ;
return 0 ;
}
if ( ! F_72 ( V_194 -> V_6 , 15 , V_194 -> V_169 ) ) {
F_11 ( V_19 L_38 ) ;
return 0 ;
}
if ( V_194 -> V_94 > 15 || V_194 -> V_94 < 0 ) {
F_73 ( V_194 -> V_6 , 15 ) ;
F_11 ( V_19 L_39 ,
V_194 -> V_94 ) ;
return 0 ;
}
if ( V_194 -> V_175 != 3 ) {
F_73 ( V_194 -> V_6 , 15 ) ;
F_11 ( V_19 L_40 ,
V_194 -> V_175 ) ;
return 0 ;
}
V_194 -> V_169 = L_41 ;
V_9 -> V_2 = * V_194 ;
V_9 -> V_48 = 0 ;
V_9 -> V_174 = L_42 ;
return 1 ;
}
static void T_5
F_74 ( struct V_1 * V_2 , const struct V_198 * V_111 )
{
struct V_8 * V_9 = & V_195 [ V_196 ] ;
V_9 -> V_2 = * V_2 ;
V_9 -> V_2 . V_94 = ( V_2 -> V_94 > 0 ) ? V_2 -> V_94 : 0 ;
V_9 -> V_48 = 0 ;
V_9 -> V_54 = 0 ;
V_9 -> V_52 = 0 ;
V_9 -> V_182 = V_64 ;
V_9 -> V_104 = V_104 ;
if ( V_2 -> V_175 != V_2 -> V_176 && V_2 -> V_176 != V_186 )
V_9 -> V_182 |= V_199 ;
V_9 -> V_111 = V_111 ;
V_9 -> V_200 = F_60 ( V_9 ) ;
if ( V_9 -> V_200 < 0 )
F_73 ( V_2 -> V_6 , 15 ) ;
else {
#ifdef F_54
if ( F_45 () ) {
F_75 ( & V_201 , V_202 ,
V_196 ) ;
F_76 ( & V_201 , V_203 ) ;
F_77 ( V_9 , 0 ) ;
V_9 -> V_204 = 1 ;
}
#endif
V_196 += 1 ;
}
}
static void T_6 F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = NULL ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_196 ; V_25 ++ )
if ( V_2 -> V_6 == V_195 [ V_25 ] . V_2 . V_6 ) {
V_9 = V_195 + V_25 ;
break;
}
if ( V_9 != NULL ) {
int V_205 ;
#ifdef F_54
if ( F_45 () )
F_79 ( & V_201 ) ;
#endif
F_73 ( V_9 -> V_2 . V_6 , 15 ) ;
F_1 ( & V_9 -> V_2 , V_188 | V_189 , 0 ) ;
if ( V_9 -> V_2 . V_94 >= 0 )
F_68 ( V_9 -> V_2 . V_94 , V_9 ) ;
F_67 ( V_9 -> V_2 . V_175 ) ;
if ( V_9 -> V_2 . V_175 != V_9 -> V_2 . V_176 &&
V_9 -> V_2 . V_176 != V_186 )
F_67 ( V_9 -> V_2 . V_176 ) ;
V_205 = V_46 [ V_9 -> V_200 ] -> V_190 ;
if ( V_205 >= 0 )
F_80 ( V_205 ) ;
if ( V_9 -> V_200 >= 0 )
F_69 ( V_9 -> V_200 ) ;
V_196 -= 1 ;
for (; V_25 < V_196 ; V_25 ++ )
V_195 [ V_25 ] = V_195 [ V_25 + 1 ] ;
} else
F_11 ( V_19 L_43
L_44 ) ;
}
static inline void
F_81 ( struct V_8 * V_9 )
{
unsigned long V_43 ;
F_82 ( & V_206 , V_43 ) ;
F_83 ( V_207 , V_9 -> V_208 ? 0 : V_207 ) ;
F_84 ( & V_206 , V_43 ) ;
}
static void
F_85 ( struct V_8 * V_9 )
{
unsigned int V_113 , V_114 ;
V_113 = F_16 ( V_9 , V_116 ) ;
V_114 = F_16 ( V_9 , V_116 | 0x400 ) ;
if ( V_9 -> V_209 ) {
V_113 &= ~ 1 ;
V_114 &= ~ 1 ;
} else {
V_113 |= 1 ;
V_114 |= 1 ;
}
F_18 ( V_9 , V_117 , V_113 , V_114 ) ;
}
static int
F_86 ( struct V_8 * V_9 )
{
static signed int V_210 ;
unsigned long V_43 ;
signed int V_211 = 255 ;
* V_212 = 0x00ffffff ;
F_21 ( & V_47 , V_43 ) ;
F_3 ( 0xFF , 0x201 ) ;
* V_213 = V_214 | V_215 ;
while ( V_211 && ( F_2 ( 0x201 ) & 0x01 ) )
V_211 -- ;
* V_213 = 0 ;
F_22 ( & V_47 , V_43 ) ;
V_211 = 0x00ffffff - * V_216 ;
#ifndef F_87
V_211 = 150 - ( V_211 >> 5 ) ;
#else
V_211 = ( V_211 >> 6 ) - 25 ;
#endif
if ( V_211 < 0 )
V_211 = 0 ;
if ( V_211 > 100 )
V_211 = 100 ;
if ( abs ( V_211 - V_210 ) > 7 ) {
V_210 = V_211 ;
if ( V_26 & V_168 )
F_11 ( V_217 L_45 , V_211 ) ;
}
return V_210 ;
}
static unsigned int
F_88 ( struct V_8 * V_9 , unsigned int V_125 ,
unsigned char * V_126 , unsigned char * V_127 )
{
unsigned int V_218 = V_129 , V_219 = V_129 ;
if ( V_125 & V_130 ) {
V_125 = V_130 ;
V_218 = V_131 ;
V_219 = V_131 ;
} else if ( V_125 & V_136 ) {
V_125 = V_136 ;
V_218 = V_137 ;
V_219 = V_137 ;
} else if ( V_125 & V_134 ) {
V_125 = V_134 ;
F_15 ( V_9 , V_220 ) ;
V_218 = V_139 ;
V_219 = V_129 ;
} else if ( V_125 & V_221 ) {
V_125 = V_221 ;
F_15 ( V_9 , V_220 ) ;
V_218 = V_135 ;
V_219 = V_129 ;
} else if ( V_125 & V_138 ) {
V_125 = V_138 ;
F_15 ( V_9 , V_220 | 0x100 ) ;
V_218 = V_129 ;
V_219 = V_139 ;
}
* V_126 = V_218 ;
* V_127 = V_219 ;
return V_125 ;
}
static int
F_89 ( struct V_8 * V_9 , int V_39 , unsigned char V_140 ,
unsigned char V_141 )
{
switch ( V_39 ) {
case V_106 :
case V_120 :
case V_118 :
case V_142 :
case V_144 :
V_9 -> V_104 [ V_39 ] = V_140 | V_141 << 8 ;
break;
case V_143 :
V_9 -> V_104 [ V_143 ] &= 0xff ;
V_9 -> V_104 [ V_143 ] |= V_140 << 8 ;
break;
case V_145 :
V_9 -> V_104 [ V_143 ] &= 0xff00 ;
V_9 -> V_104 [ V_143 ] |= V_140 ;
V_39 = V_143 ;
break;
case V_222 :
V_9 -> V_104 [ V_145 ] = V_140 ;
V_39 = V_145 ;
break;
case V_147 :
case V_105 :
break;
default:
V_39 = - V_70 ;
break;
}
return V_39 ;
}
static int F_90 ( struct V_8 * V_9 , int V_39 )
{
int V_104 ;
switch ( V_39 ) {
case V_106 :
case V_120 :
case V_118 :
case V_142 :
case V_144 :
V_104 = V_9 -> V_104 [ V_39 ] ;
break;
case V_143 :
V_104 = V_9 -> V_104 [ V_143 ] >> 8 ;
V_104 |= V_104 << 8 ;
break;
case V_145 :
V_104 = V_9 -> V_104 [ V_143 ] & 0xff ;
V_104 |= V_104 << 8 ;
break;
case V_222 :
V_104 = V_9 -> V_104 [ V_145 ] & 0xff ;
V_104 |= V_104 << 8 ;
break;
default:
V_104 = 0 ;
}
return V_104 ;
}
static void
F_77 ( struct V_8 * V_9 , unsigned int V_125 )
{
if ( ! V_9 -> V_204 ) {
if ( V_9 -> V_223 ) {
V_125 = V_134 ;
V_9 -> V_208 = V_9 -> V_209 = 1 ;
} else if ( V_9 -> V_224 ) {
V_125 = V_221 ;
V_9 -> V_208 = V_9 -> V_209 = 1 ;
} else {
if ( ( V_9 -> V_125 & V_136 ) == 0 )
V_9 -> V_125 = V_138 ;
V_9 -> V_208 = V_9 -> V_209 = 0 ;
}
F_81 ( V_9 ) ;
F_85 ( V_9 ) ;
if ( V_125 != V_9 -> V_125 )
F_50 ( V_9 , V_125 ) ;
}
}
static int
F_91 ( struct V_8 * V_9 )
{
signed int V_225 ;
unsigned int V_37 , V_226 , V_227 ;
V_37 = F_2 ( 0x201 ) ;
V_226 = V_9 -> V_223 ;
V_227 = V_9 -> V_224 ;
V_9 -> V_223 = ! ( V_37 & 0x10 ) ;
V_9 -> V_224 = ! ! ( V_37 & 0x20 ) ;
if ( ! V_9 -> V_204 &&
( V_226 != V_9 -> V_223 ||
V_227 != V_9 -> V_224 ) )
F_77 ( V_9 , V_9 -> V_125 ) ;
V_225 = F_86 ( V_9 ) ;
if ( abs ( V_9 -> V_228 - V_225 ) > 20 )
V_9 -> V_229 = 1 ;
V_37 = V_104 [ V_106 ] & 0xFF ;
if ( V_225 != V_37 && V_9 -> V_229 ) {
V_9 -> V_228 = V_225 ;
F_52 ( V_9 , V_106 ,
V_225 | V_225 << 8 ) ;
return 1 ;
}
return 0 ;
}
static void
V_202 ( unsigned long V_230 )
{
int V_231 ;
if ( F_91 ( V_195 + V_230 ) )
V_231 = 5 ;
else
V_231 = V_232 ;
F_76 ( & V_201 , V_203 + V_231 ) ;
}
static int
F_55 ( int V_39 , unsigned int V_21 , int T_1 * V_32 )
{
struct V_8 * V_9 = (struct V_8 * ) V_46 [ V_39 ] -> V_9 ;
int V_153 ;
switch ( V_21 ) {
case V_233 :
{
T_7 V_234 , V_235 , V_236 ;
int V_153 ;
if ( F_57 ( V_153 , V_32 ) )
return - V_157 ;
if ( V_153 & ~ ( V_237 |
V_238 |
V_239 ) )
return - V_70 ;
V_236 = V_9 -> V_204 ;
V_234 = V_9 -> V_208 ;
V_235 = V_9 -> V_209 ;
V_9 -> V_204 = ( V_153 & V_239 ) ? 1 : 0 ;
V_9 -> V_208 = ( V_153 & V_237 ) ? 1 : 0 ;
V_9 -> V_209 = ( V_153 & V_238 ) ? 1 : 0 ;
if ( V_234 != V_9 -> V_208 )
F_81 ( V_9 ) ;
if ( V_235 != V_9 -> V_209 )
F_85 ( V_9 ) ;
if ( V_236 != V_9 -> V_204 )
F_77 ( V_9 , V_9 -> V_125 ) ;
return 0 ;
}
case V_240 :
if ( F_57 ( V_153 , V_32 ) )
return - V_157 ;
switch ( V_153 ) {
#define F_92 0x53
#define F_93 0x57
case F_92 :
F_15 ( V_9 , 0x16 ) ;
break;
case F_93 :
F_15 ( V_9 , 0x18 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
case V_241 :
{
unsigned long V_43 ;
int V_242 [ 15 ] , V_25 , V_153 ;
if ( F_57 ( V_153 , V_32 ) )
return - V_157 ;
if ( F_94 ( V_242 , ( void * ) V_153 , sizeof( V_242 ) ) )
return - V_157 ;
switch ( V_242 [ 14 ] ) {
case V_243 :
F_59 ( V_9 ) ;
break;
case V_244 :
F_18 ( V_9 , V_117 , V_242 [ 0 ] , V_242 [ 4 ] ) ;
F_18 ( V_9 , V_117 , V_242 [ 1 ] , V_242 [ 5 ] ) ;
F_18 ( V_9 , V_117 , V_242 [ 2 ] , V_242 [ 6 ] ) ;
F_18 ( V_9 , V_117 , V_242 [ 3 ] , V_242 [ 7 ] ) ;
F_18 ( V_9 , V_117 , V_242 [ 8 ] , V_242 [ 9 ] ) ;
F_18 ( V_9 , V_119 , V_242 [ 10 ] , V_242 [ 11 ] ) ;
F_18 ( V_9 , V_119 , V_242 [ 12 ] , V_242 [ 13 ] ) ;
break;
case V_245 :
F_21 ( & V_47 , V_43 ) ;
for ( V_25 = 0x30 ; V_25 < 14 << 8 ; V_25 += 1 << 8 )
F_12 ( V_9 , 1 , & V_25 , 1 , V_242 + ( V_25 >> 8 ) ) ;
F_22 ( & V_47 , V_43 ) ;
if ( F_95 ( ( void * ) V_153 , V_242 , sizeof( V_242 ) ) )
return - V_157 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
case V_246 :
V_153 = ( V_9 -> V_208 ? V_237 : 0 ) |
( V_9 -> V_209 ? V_238 : 0 ) |
( V_9 -> V_223 ? V_247 : 0 ) |
( V_9 -> V_224 ? V_248 : 0 ) |
( V_9 -> V_204 ? V_239 : 0 ) ;
return F_58 ( V_153 , V_32 ) ? - V_157 : 0 ;
}
if ( F_56 ( V_21 ) & V_156 ) {
if ( ( V_21 & 0xff ) == V_106 )
V_9 -> V_229 = 0 ;
if ( ( V_21 & 0xff ) == V_249 ) {
unsigned int V_153 , V_250 , V_251 ;
if ( F_57 ( V_153 , V_32 ) )
return - V_157 ;
V_250 = V_153 & 0x7f ;
V_251 = ( V_153 & 0x7f00 ) >> 8 ;
V_153 = ( V_250 + V_251 ) / 2 ;
V_9 -> V_104 [ V_249 ] = V_153 | ( V_153 << 8 ) ;
V_9 -> V_208 = ( V_153 <= 50 ) ;
F_81 ( V_9 ) ;
return 0 ;
}
}
return - V_155 ;
}
static int T_5 F_96 ( void )
{
const struct V_198 * V_111 ;
if ( ! V_252 && F_45 () ) {
V_252 = 0x250 ;
V_94 = 12 ;
V_175 = 3 ;
V_176 = 7 ;
}
V_111 = & V_253 ;
#ifdef F_54
if ( F_45 () )
V_111 = & V_254 ;
#endif
V_255 . V_6 = V_252 ;
V_255 . V_94 = V_94 ;
V_255 . V_175 = V_175 ;
V_255 . V_176 = V_176 ;
if ( ! F_71 ( & V_255 ) )
return - V_173 ;
F_74 ( & V_255 , V_111 ) ;
V_256 = 1 ;
return 0 ;
}
static void T_6 F_97 ( void )
{
if ( V_256 )
F_78 ( & V_255 ) ;
}
static int T_5 F_98 ( char * V_257 )
{
int V_258 [ 5 ] ;
V_257 = F_99 ( V_257 , F_100 ( V_258 ) , V_258 ) ;
V_252 = V_258 [ 1 ] ;
V_94 = V_258 [ 2 ] ;
V_175 = V_258 [ 3 ] ;
V_176 = V_258 [ 4 ] ;
return 1 ;
}
