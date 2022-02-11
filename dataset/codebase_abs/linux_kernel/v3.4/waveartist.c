static inline void
F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned int V_5 = V_2 -> V_6 + V_7 ;
V_3 = ~ V_3 & F_2 ( V_5 ) ;
F_3 ( V_3 | V_4 , V_5 ) ;
}
static inline void
F_4 ( T_1 * V_8 )
{
unsigned int V_5 = V_8 -> V_2 . V_6 + V_7 ;
int V_9 ;
V_9 = F_2 ( V_5 ) & ~ V_10 ;
F_3 ( V_9 | V_10 , V_5 ) ;
F_3 ( V_9 , V_5 ) ;
}
static inline int
F_5 ( int V_11 )
{
unsigned int V_12 = F_6 ( V_11 * 100 ) ;
return F_7 ( V_12 ) ;
}
static int
F_8 ( T_1 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
unsigned int V_12 , V_13 = - 1 ;
F_1 ( V_2 , - 1 , V_14 ) ;
F_5 ( 2 ) ;
F_1 ( V_2 , V_14 , 0 ) ;
V_12 = 500 ;
do {
F_9 ( 2 ) ;
if ( F_2 ( V_2 -> V_6 + V_15 ) & V_16 ) {
V_13 = F_10 ( V_2 -> V_6 + V_17 ) ;
if ( V_13 == 0x55aa )
break;
}
} while ( -- V_12 );
if ( V_12 == 0 ) {
F_11 ( V_18 L_1 ) ;
if ( V_13 != ( unsigned int ) - 1 )
F_11 ( L_2 , V_13 ) ;
F_11 ( L_3 ) ;
return 1 ;
}
return 0 ;
}
static int
F_12 ( T_1 * V_8 ,
int V_19 , unsigned int * V_20 ,
int V_21 , unsigned int * V_22 )
{
unsigned int V_6 = V_8 -> V_2 . V_6 ;
unsigned int V_23 = 0 ;
unsigned int V_24 ;
if ( V_25 & V_26 ) {
F_11 ( L_4 ) ;
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ )
F_11 ( L_5 , V_20 [ V_24 ] ) ;
F_11 ( L_3 ) ;
}
if ( F_2 ( V_6 + V_15 ) & V_16 ) {
int V_27 ;
V_27 = F_10 ( V_6 + V_17 ) ;
if ( V_25 & V_26 )
F_11 ( L_6 , V_27 ) ;
F_13 ( 10 ) ;
}
for ( V_24 = 0 ; ! V_23 && V_24 < V_19 ; V_24 ++ ) {
int V_28 ;
for ( V_28 = 5000 ; V_28 ; V_28 -- )
if ( F_2 ( V_6 + V_15 ) & V_29 )
break;
if ( ! V_28 )
V_23 = 1 ;
else
F_14 ( V_20 [ V_24 ] , V_6 + V_17 ) ;
}
for ( V_24 = 0 ; ! V_23 && V_24 < V_21 ; V_24 ++ ) {
int V_28 ;
for ( V_28 = 5000 ; V_28 ; V_28 -- )
if ( F_2 ( V_6 + V_15 ) & V_16 )
break;
if ( ! V_28 )
V_23 = 1 ;
else
V_22 [ V_24 ] = F_10 ( V_6 + V_17 ) ;
}
if ( V_25 & V_26 ) {
if ( ! V_23 ) {
F_11 ( L_7 ) ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ )
F_11 ( L_5 , V_22 [ V_24 ] ) ;
F_11 ( L_3 ) ;
} else
F_11 ( L_8 ) ;
}
return V_23 ? 1 : 0 ;
}
static inline int
F_15 ( T_1 * V_8 , unsigned int V_20 )
{
return F_12 ( V_8 , 1 , & V_20 , 0 , NULL ) ;
}
static inline unsigned int
F_16 ( T_1 * V_8 , unsigned int V_20 )
{
unsigned int V_30 ;
F_12 ( V_8 , 1 , & V_20 , 1 , & V_30 ) ;
return V_30 ;
}
static inline int
F_17 ( T_1 * V_8 , unsigned int V_20 , unsigned int V_31 )
{
unsigned int V_32 [ 2 ] ;
V_32 [ 0 ] = V_20 ;
V_32 [ 1 ] = V_31 ;
return F_12 ( V_8 , 2 , V_32 , 1 , V_32 ) ;
}
static inline int
F_18 ( T_1 * V_8 , unsigned int V_20 ,
unsigned int V_33 , unsigned int V_34 )
{
unsigned int V_32 [ 3 ] ;
V_32 [ 0 ] = V_20 ;
V_32 [ 1 ] = V_33 ;
V_32 [ 2 ] = V_34 ;
return F_12 ( V_8 , 3 , V_32 , 0 , NULL ) ;
}
static int
F_19 ( T_1 * V_8 , char * V_35 )
{
unsigned int V_36 [ 2 ] ;
unsigned int V_20 = V_37 ;
F_12 ( V_8 , 1 , & V_20 , 2 , V_36 ) ;
V_35 [ 0 ] = V_36 [ 0 ] >> 8 ;
V_35 [ 1 ] = V_36 [ 0 ] & 255 ;
V_35 [ 2 ] = '\0' ;
return V_36 [ 0 ] ;
}
static int
F_20 ( int V_38 , int V_39 )
{
T_1 * V_8 ;
T_2 * V_40 ;
unsigned long V_41 ;
if ( V_38 < 0 || V_38 >= V_42 )
return - V_43 ;
V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
F_21 ( & V_45 , V_41 ) ;
if ( V_40 -> V_46 || ( V_8 -> V_46 & V_39 ) ) {
F_22 ( & V_45 , V_41 ) ;
return - V_47 ;
}
V_8 -> V_48 = 0 ;
V_8 -> V_46 |= V_39 ;
V_40 -> V_46 = V_39 ;
F_23 ( V_38 , 0 ) ;
if ( V_39 & V_49 )
V_8 -> V_50 = V_38 ;
if ( V_39 & V_51 )
V_8 -> V_52 = V_38 ;
F_22 ( & V_45 , V_41 ) ;
return 0 ;
}
static void
F_24 ( int V_38 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
unsigned long V_41 ;
F_21 ( & V_45 , V_41 ) ;
F_25 ( V_38 ) ;
V_8 -> V_48 = 0 ;
V_8 -> V_46 &= ~ V_40 -> V_46 ;
V_40 -> V_46 = 0 ;
F_22 ( & V_45 , V_41 ) ;
}
static void
F_26 ( int V_38 , unsigned long V_53 , int V_54 , int V_55 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
unsigned long V_41 ;
unsigned int V_28 = V_54 ;
if ( V_25 & V_56 )
F_11 ( L_9 ,
V_53 , V_28 ) ;
if ( V_40 -> V_57 & ( V_58 | V_59 ) )
V_28 >>= 1 ;
if ( V_40 -> V_60 > 1 )
V_28 >>= 1 ;
V_28 -= 1 ;
if ( V_8 -> V_48 & V_61 &&
V_44 [ V_38 ] -> V_41 & V_62 &&
V_55 &&
V_28 == V_8 -> V_63 ) {
V_8 -> V_48 |= V_61 ;
return;
}
F_21 ( & V_45 , V_41 ) ;
F_17 ( V_8 , V_64 , V_28 ) ;
V_8 -> V_63 = V_28 ;
V_8 -> V_48 |= V_61 ;
F_22 ( & V_45 , V_41 ) ;
}
static void
F_27 ( int V_38 , unsigned long V_53 , int V_54 , int V_55 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
unsigned long V_41 ;
unsigned int V_28 = V_54 ;
if ( V_25 & V_65 )
F_11 ( L_10 ,
V_53 , V_28 ) ;
if ( V_40 -> V_57 & ( V_58 | V_59 ) )
V_28 >>= 1 ;
if ( V_40 -> V_60 > 1 )
V_28 >>= 1 ;
V_28 -= 1 ;
if ( V_8 -> V_48 & V_66 &&
V_44 [ V_38 ] -> V_41 & V_62 &&
V_55 &&
V_28 == V_8 -> V_63 ) {
V_8 -> V_48 |= V_66 ;
return;
}
F_21 ( & V_45 , V_41 ) ;
F_17 ( V_8 , V_67 , V_28 ) ;
V_8 -> V_63 = V_28 ;
V_8 -> V_48 |= V_66 ;
F_22 ( & V_45 , V_41 ) ;
}
static int
F_28 ( int V_38 , unsigned int V_20 , void T_3 * V_31 )
{
return - V_68 ;
}
static unsigned int
F_29 ( T_2 * V_40 )
{
unsigned int V_69 ;
if ( V_40 -> V_69 == 8000 )
V_69 = 0x2E71 ;
else if ( V_40 -> V_69 == 11025 )
V_69 = 0x4000 ;
else if ( V_40 -> V_69 == 22050 )
V_69 = 0x8000 ;
else if ( V_40 -> V_69 == 44100 )
V_69 = 0x0 ;
else {
V_69 = V_40 -> V_69 << 16 ;
V_69 = ( V_69 / 44100 ) & 65535 ;
}
return V_69 ;
}
static unsigned int
F_30 ( T_2 * V_40 )
{
unsigned int V_70 ;
if ( V_40 -> V_57 == V_58 )
V_70 = 1 ;
else if ( V_40 -> V_57 == V_71 )
V_70 = 0 ;
else
V_70 = 2 ;
return V_70 ;
}
static int
F_31 ( int V_38 , int V_72 , int V_73 )
{
unsigned long V_41 ;
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
unsigned int V_69 , V_70 ;
if ( V_8 -> V_48 )
return 0 ;
V_69 = F_29 ( V_40 ) ;
V_70 = F_30 ( V_40 ) ;
F_21 ( & V_45 , V_41 ) ;
if ( F_17 ( V_8 , V_74 , V_70 ) )
F_11 ( V_18 L_11
L_12 , V_40 -> V_57 ) ;
if ( F_17 ( V_8 , V_75 , V_40 -> V_60 ) )
F_11 ( V_18 L_13
L_14 , V_40 -> V_60 ) ;
if ( F_17 ( V_8 , V_76 , V_69 ) )
F_11 ( V_18 L_15
L_16 , V_40 -> V_69 ) ;
if ( F_17 ( V_8 , V_77 , 1 ) )
F_11 ( V_18 L_15
L_17 , 1 ) ;
if ( F_17 ( V_8 , V_74 , V_70 ) )
F_11 ( V_18 L_15
L_18 , V_40 -> V_57 ) ;
V_8 -> V_63 = 0 ;
F_22 ( & V_45 , V_41 ) ;
F_32 ( V_38 ) ;
if ( V_25 & V_78 ) {
F_11 ( L_19 ,
F_2 ( V_8 -> V_2 . V_6 + V_7 ) ) ;
F_11 ( L_20 ,
F_2 ( V_8 -> V_2 . V_6 + V_15 ) ) ;
F_11 ( L_21 ,
F_2 ( V_8 -> V_2 . V_6 + V_79 ) ) ;
}
return 0 ;
}
static int
F_33 ( int V_38 , int V_72 , int V_73 )
{
unsigned long V_41 ;
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
unsigned int V_69 , V_70 ;
V_69 = F_29 ( V_40 ) ;
V_70 = F_30 ( V_40 ) ;
F_21 ( & V_45 , V_41 ) ;
if ( F_17 ( V_8 , V_80 , V_69 ) &&
F_17 ( V_8 , V_80 , V_69 ) )
F_11 ( V_18 L_22
L_16 , V_40 -> V_69 ) ;
if ( F_17 ( V_8 , V_81 , V_40 -> V_60 ) )
F_11 ( V_18 L_22
L_14 , V_40 -> V_60 ) ;
if ( F_17 ( V_8 , V_82 , 0 ) )
F_11 ( V_18 L_22
L_17 , 0 ) ;
if ( F_17 ( V_8 , V_83 , V_70 ) )
F_11 ( V_18 L_22
L_18 , V_40 -> V_57 ) ;
V_8 -> V_63 = 0 ;
F_22 ( & V_45 , V_41 ) ;
F_34 ( V_38 ) ;
if ( V_25 & V_78 ) {
F_11 ( L_19 , F_2 ( V_8 -> V_2 . V_6 + V_7 ) ) ;
F_11 ( L_20 , F_2 ( V_8 -> V_2 . V_6 + V_15 ) ) ;
F_11 ( L_21 , F_2 ( V_8 -> V_2 . V_6 + V_79 ) ) ;
}
return 0 ;
}
static void
F_25 ( int V_38 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
T_1 * V_8 ;
if ( V_40 -> V_46 & V_51 )
F_34 ( V_38 ) ;
if ( V_40 -> V_46 & V_49 )
F_32 ( V_38 ) ;
V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
V_8 -> V_48 = 0 ;
}
static void
F_32 ( int V_38 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
unsigned long V_41 ;
F_21 ( & V_45 , V_41 ) ;
F_15 ( V_8 , V_84 ) ;
V_8 -> V_48 &= ~ V_66 ;
if ( F_2 ( V_8 -> V_2 . V_6 + V_15 ) & V_85 )
F_4 ( V_8 ) ;
F_22 ( & V_45 , V_41 ) ;
}
static void
F_34 ( int V_38 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
unsigned long V_41 ;
F_21 ( & V_45 , V_41 ) ;
F_15 ( V_8 , V_86 ) ;
V_8 -> V_48 &= ~ V_61 ;
if ( F_2 ( V_8 -> V_2 . V_6 + V_15 ) & V_85 )
F_4 ( V_8 ) ;
F_22 ( & V_45 , V_41 ) ;
}
static void
F_23 ( int V_38 , int V_87 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
unsigned long V_41 ;
if ( V_25 & V_88 ) {
F_11 ( L_23 ) ;
if ( V_87 & V_66 )
F_11 ( L_24 ) ;
if ( V_87 & V_61 )
F_11 ( L_25 ) ;
F_11 ( L_3 ) ;
}
F_21 ( & V_45 , V_41 ) ;
V_87 &= V_8 -> V_48 ;
if ( V_40 -> V_46 & V_49 &&
V_87 & V_66 )
F_15 ( V_8 , V_89 ) ;
if ( V_40 -> V_46 & V_51 &&
V_87 & V_61 )
F_15 ( V_8 , V_90 ) ;
F_22 ( & V_45 , V_41 ) ;
}
static int
F_35 ( int V_38 , int V_31 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
if ( V_31 <= 0 )
return V_40 -> V_69 ;
if ( V_31 < 5000 )
V_31 = 5000 ;
if ( V_31 > 44100 )
V_31 = 44100 ;
V_40 -> V_69 = V_31 ;
return V_40 -> V_69 ;
}
static short
F_36 ( int V_38 , short V_31 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
if ( V_31 != 1 && V_31 != 2 )
return V_40 -> V_60 ;
V_40 -> V_60 = V_31 ;
return V_31 ;
}
static unsigned int
F_37 ( int V_38 , unsigned int V_31 )
{
T_2 * V_40 = ( T_2 * ) V_44 [ V_38 ] -> V_40 ;
if ( V_31 == 0 )
return V_40 -> V_57 ;
if ( ( V_31 != V_91 ) && ( V_31 != V_58 ) && ( V_31 != V_71 ) )
V_31 = V_91 ;
V_40 -> V_57 = V_31 ;
return V_31 ;
}
static T_4
F_38 ( int V_92 , void * V_93 )
{
T_1 * V_8 = V_93 ;
int V_94 , V_95 ;
F_39 ( & V_45 ) ;
V_94 = F_2 ( V_8 -> V_2 . V_6 + V_79 ) ;
V_95 = F_2 ( V_8 -> V_2 . V_6 + V_15 ) ;
if ( V_25 & V_78 )
F_11 ( L_26 ,
V_95 , V_94 ) ;
if ( V_95 & V_85 )
F_4 ( V_8 ) ;
else
F_11 ( V_18 L_27 ) ;
if ( V_94 & 0x01 ) {
int V_36 = 1 ;
if ( ( V_95 & V_96 ) && ( V_8 -> V_48 & V_61 ) ) {
F_40 ( V_8 -> V_52 , 1 ) ;
V_36 = 0 ;
}
if ( ( V_95 & V_97 ) && ( V_8 -> V_48 & V_66 ) ) {
F_41 ( V_8 -> V_50 ) ;
V_36 = 0 ;
}
if ( V_36 )
F_11 ( V_18 L_28 ) ;
}
if ( V_94 & 0x2 )
F_11 ( V_18 L_29 ) ;
F_42 ( & V_45 ) ;
return V_98 ;
}
static void
F_43 ( T_1 * V_8 , int V_99 )
{
unsigned int V_100 , V_101 ;
V_100 = V_8 -> V_102 [ V_99 ] & 0xff ;
V_101 = V_8 -> V_102 [ V_99 ] >> 8 ;
if ( V_100 > 100 )
V_100 = 100 ;
if ( V_101 > 100 )
V_101 = 100 ;
#define F_44 ( T_5 , T_6 ) ((lev) * (max) / 100)
if ( F_45 () && V_99 == V_103 )
V_99 = V_104 ;
if ( V_105 [ V_99 ] . V_106 || V_105 [ V_99 ] . V_107 ) {
const struct V_108 * V_109 = V_105 + V_99 ;
unsigned int V_110 , V_111 , V_112 ;
V_110 = V_109 -> T_6 << V_109 -> V_113 ;
V_100 = F_44 ( V_100 , V_109 -> T_6 ) << V_109 -> V_113 ;
V_101 = F_44 ( V_101 , V_109 -> T_6 ) << V_109 -> V_113 ;
V_111 = F_16 ( V_8 , V_114 |
V_109 -> V_106 << 8 ) ;
V_112 = F_16 ( V_8 , V_114 |
V_109 -> V_107 << 8 ) ;
V_111 = ( V_111 & ~ V_110 ) | ( V_100 & V_110 ) ;
V_112 = ( V_112 & ~ V_110 ) | ( V_101 & V_110 ) ;
F_18 ( V_8 , V_115 , V_111 , V_112 ) ;
} else {
switch( V_99 ) {
case V_116 :
F_18 ( V_8 , V_117 ,
F_44 ( V_100 , 32767 ) ,
F_44 ( V_101 , 32767 ) ) ;
break;
case V_118 :
F_18 ( V_8 , 0x0100 | V_117 ,
F_44 ( V_100 , 32767 ) ,
F_44 ( V_101 , 32767 ) ) ;
break;
}
}
}
static void
F_46 ( T_1 * V_8 , char V_119 , char V_120 )
{
unsigned int V_121 , V_122 ;
V_121 = F_16 ( V_8 , V_114 | 0x0800 ) ;
V_122 = F_16 ( V_8 , V_114 | 0x0900 ) ;
V_121 = ( V_121 & ~ 0x3f ) | V_120 << 3 | V_119 ;
F_18 ( V_8 , V_115 , V_121 , V_122 ) ;
}
static unsigned int
F_47 ( T_1 * V_8 , unsigned int V_123 ,
unsigned char * V_124 , unsigned char * V_125 )
{
unsigned int V_126 = V_127 ;
if ( V_123 & V_128 ) {
V_123 = V_128 ;
V_126 = V_129 ;
} else if ( V_123 & V_130 ) {
V_123 = V_130 ;
V_126 = V_131 ;
} else if ( V_123 & V_132 ) {
V_123 = V_132 ;
V_126 = V_133 ;
} else if ( V_123 & V_134 ) {
V_123 = V_134 ;
V_126 = V_135 ;
} else if ( V_123 & V_136 ) {
V_123 = V_136 ;
V_126 = V_137 ;
}
* V_124 = * V_125 = V_126 ;
return V_123 ;
}
static int
F_48 ( T_1 * V_8 , int V_38 , unsigned char V_138 ,
unsigned char V_139 )
{
switch ( V_38 ) {
case V_104 :
case V_118 :
case V_116 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_8 -> V_102 [ V_38 ] = V_138 | V_139 << 8 ;
break;
case V_145 :
break;
default:
V_38 = - V_68 ;
break;
}
return V_38 ;
}
static int F_49 ( T_1 * V_8 , int V_38 )
{
return V_8 -> V_102 [ V_38 ] ;
}
static void
F_50 ( T_1 * V_8 , unsigned int V_123 )
{
unsigned char V_124 , V_125 ;
V_123 &= V_8 -> V_109 -> V_146 ;
if ( F_51 ( V_123 ) > 1 )
V_123 &= ~ V_8 -> V_123 ;
V_8 -> V_123 = V_8 -> V_109 -> V_147 ( V_8 , V_123 ,
& V_124 , & V_125 ) ;
F_46 ( V_8 , V_124 , V_125 ) ;
}
static int
F_52 ( T_1 * V_8 , int V_38 , unsigned int V_148 )
{
unsigned int V_100 = V_148 & 0x00ff ;
unsigned int V_101 = ( V_148 & 0xff00 ) >> 8 ;
if ( V_100 > 100 )
V_100 = 100 ;
if ( V_101 > 100 )
V_101 = 100 ;
if ( ! ( V_8 -> V_109 -> V_149 & ( 1 << V_38 ) ) )
V_101 = V_100 ;
V_38 = V_8 -> V_109 -> V_150 ( V_8 , V_38 , V_100 , V_101 ) ;
if ( V_38 >= 0 )
F_43 ( V_8 , V_38 ) ;
return V_38 < 0 ? V_38 : 0 ;
}
static int
F_53 ( int V_38 , unsigned int V_20 , void T_3 * V_31 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
int V_30 = 0 , V_151 , V_152 ;
if ( ( ( V_20 >> 8 ) & 255 ) != 'M' )
return - V_153 ;
#ifdef F_54
if ( F_45 () ) {
V_30 = F_55 ( V_38 , V_20 , V_31 ) ;
if ( V_30 != - V_153 )
return V_30 ;
else
V_30 = 0 ;
}
#endif
V_152 = V_20 & 0xff ;
if ( F_56 ( V_20 ) & V_154 ) {
if ( F_57 ( V_151 , ( int T_3 * ) V_31 ) )
return - V_155 ;
switch ( V_152 ) {
case V_156 :
F_50 ( V_8 , V_151 ) ;
break;
default:
V_30 = - V_68 ;
if ( V_152 < V_157 &&
V_8 -> V_109 -> V_158 & ( 1 << V_152 ) )
V_30 = F_52 ( V_8 , V_152 , V_151 ) ;
}
}
if ( V_30 == 0 && F_56 ( V_20 ) & V_159 ) {
V_30 = - V_68 ;
switch ( V_152 ) {
case V_156 :
V_30 = V_8 -> V_123 ;
break;
case V_160 :
V_30 = V_8 -> V_109 -> V_158 ;
break;
case V_161 :
V_30 = V_8 -> V_109 -> V_149 ;
break;
case V_162 :
V_30 = V_8 -> V_109 -> V_146 ;
break;
case V_163 :
V_30 = V_164 ;
break;
default:
if ( V_152 < V_157 )
V_30 = V_8 -> V_109 -> V_165 ( V_8 , V_152 ) ;
break;
}
if ( V_30 >= 0 )
V_30 = F_58 ( V_30 , ( int T_3 * ) V_31 ) ? - V_155 : 0 ;
}
return V_30 ;
}
static void
F_59 ( T_1 * V_8 )
{
int V_24 ;
if ( V_25 & V_166 )
F_11 ( L_30 , V_8 -> V_2 . V_167 ) ;
F_15 ( V_8 , V_168 ) ;
F_18 ( V_8 , V_115 , 0x9800 , 0xa836 ) ;
F_18 ( V_8 , V_115 , 0x4c00 , 0x8c00 ) ;
F_18 ( V_8 , V_115 , 0x2801 , 0x6800 ) ;
F_50 ( V_8 , 0 ) ;
for ( V_24 = 0 ; V_24 < V_157 ; V_24 ++ )
F_43 ( V_8 , V_24 ) ;
}
static int T_7 F_60 ( T_1 * V_8 )
{
T_2 * V_40 ;
char V_35 [ 3 ] , V_169 [ 64 ] ;
int V_170 ;
if ( F_8 ( V_8 ) )
return - V_171 ;
sprintf ( V_169 , L_31 , V_8 -> V_2 . V_167 , V_8 -> V_172 ) ;
if ( F_19 ( V_8 , V_35 ) ) {
strcat ( V_169 , L_32 ) ;
strcat ( V_169 , V_35 ) ;
}
strcat ( V_169 , L_33 ) ;
F_61 ( V_169 , V_8 -> V_2 . V_6 , V_8 -> V_2 . V_92 ,
V_8 -> V_2 . V_173 , V_8 -> V_2 . V_174 ) ;
V_40 = F_62 ( sizeof( T_2 ) , V_175 ) ;
if ( V_40 == NULL )
goto V_176;
V_170 = F_63 ( V_177 , V_169 ,
& V_178 , sizeof( struct V_179 ) ,
V_8 -> V_180 , V_91 | V_58 | V_71 ,
V_8 , V_8 -> V_2 . V_173 , V_8 -> V_2 . V_174 ) ;
if ( V_170 < 0 )
goto free;
V_44 [ V_170 ] -> V_40 = V_40 ;
F_59 ( V_8 ) ;
F_4 ( V_8 ) ;
if ( F_64 ( V_8 -> V_2 . V_92 , F_38 , 0 , V_8 -> V_2 . V_167 , V_8 ) < 0 ) {
F_11 ( V_181 L_34 ,
V_8 -> V_2 . V_167 , V_8 -> V_2 . V_92 ) ;
goto V_182;
}
if ( F_65 ( V_8 -> V_2 . V_173 , V_8 -> V_2 . V_167 ) ) {
F_11 ( V_181 L_35 ,
V_8 -> V_2 . V_167 , V_8 -> V_2 . V_173 ) ;
goto V_183;
}
if ( V_8 -> V_2 . V_173 != V_8 -> V_2 . V_174 && V_8 -> V_2 . V_174 != V_184 )
if ( F_65 ( V_8 -> V_2 . V_174 , V_8 -> V_2 . V_167 ) ) {
F_11 ( V_181 L_36 ,
V_8 -> V_2 . V_167 , V_8 -> V_2 . V_174 ) ;
goto V_185;
}
F_1 ( & V_8 -> V_2 , 0 , V_186 | V_187 ) ;
V_44 [ V_170 ] -> V_188 =
F_66 ( V_189 ,
V_169 ,
& V_190 ,
sizeof( struct V_191 ) ,
V_8 ) ;
return V_170 ;
V_185:
F_67 ( V_8 -> V_2 . V_173 ) ;
V_183:
F_68 ( V_8 -> V_2 . V_92 , V_8 ) ;
V_182:
F_69 ( V_170 ) ;
free:
F_70 ( V_40 ) ;
V_176:
return - 1 ;
}
static int T_7 F_71 ( struct V_1 * V_192 )
{
T_1 * V_8 = & V_193 [ V_194 ] ;
if ( V_194 >= V_195 ) {
F_11 ( V_18 L_37 ) ;
return 0 ;
}
if ( ! F_72 ( V_192 -> V_6 , 15 , V_192 -> V_167 ) ) {
F_11 ( V_18 L_38 ) ;
return 0 ;
}
if ( V_192 -> V_92 > 15 || V_192 -> V_92 < 0 ) {
F_73 ( V_192 -> V_6 , 15 ) ;
F_11 ( V_18 L_39 ,
V_192 -> V_92 ) ;
return 0 ;
}
if ( V_192 -> V_173 != 3 ) {
F_73 ( V_192 -> V_6 , 15 ) ;
F_11 ( V_18 L_40 ,
V_192 -> V_173 ) ;
return 0 ;
}
V_192 -> V_167 = L_41 ;
V_8 -> V_2 = * V_192 ;
V_8 -> V_46 = 0 ;
V_8 -> V_172 = L_42 ;
return 1 ;
}
static void T_7
F_74 ( struct V_1 * V_2 , const struct V_196 * V_109 )
{
T_1 * V_8 = & V_193 [ V_194 ] ;
V_8 -> V_2 = * V_2 ;
V_8 -> V_2 . V_92 = ( V_2 -> V_92 > 0 ) ? V_2 -> V_92 : 0 ;
V_8 -> V_46 = 0 ;
V_8 -> V_52 = 0 ;
V_8 -> V_50 = 0 ;
V_8 -> V_180 = V_62 ;
V_8 -> V_102 = V_102 ;
if ( V_2 -> V_173 != V_2 -> V_174 && V_2 -> V_174 != V_184 )
V_8 -> V_180 |= V_197 ;
V_8 -> V_109 = V_109 ;
V_8 -> V_198 = F_60 ( V_8 ) ;
if ( V_8 -> V_198 < 0 )
F_73 ( V_2 -> V_6 , 15 ) ;
else {
#ifdef F_54
if ( F_45 () ) {
F_75 ( & V_199 ) ;
V_199 . V_200 = V_201 ;
V_199 . V_202 = V_203 ;
V_199 . V_204 = V_194 ;
F_76 ( & V_199 ) ;
F_77 ( V_8 , 0 ) ;
V_8 -> V_205 = 1 ;
}
#endif
V_194 += 1 ;
}
}
static void T_8 F_78 ( struct V_1 * V_2 )
{
T_1 * V_8 = NULL ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_194 ; V_24 ++ )
if ( V_2 -> V_6 == V_193 [ V_24 ] . V_2 . V_6 ) {
V_8 = V_193 + V_24 ;
break;
}
if ( V_8 != NULL ) {
int V_206 ;
#ifdef F_54
if ( F_45 () )
F_79 ( & V_199 ) ;
#endif
F_73 ( V_8 -> V_2 . V_6 , 15 ) ;
F_1 ( & V_8 -> V_2 , V_186 | V_187 , 0 ) ;
if ( V_8 -> V_2 . V_92 >= 0 )
F_68 ( V_8 -> V_2 . V_92 , V_8 ) ;
F_67 ( V_8 -> V_2 . V_173 ) ;
if ( V_8 -> V_2 . V_173 != V_8 -> V_2 . V_174 &&
V_8 -> V_2 . V_174 != V_184 )
F_67 ( V_8 -> V_2 . V_174 ) ;
V_206 = V_44 [ V_8 -> V_198 ] -> V_188 ;
if ( V_206 >= 0 )
F_80 ( V_206 ) ;
if ( V_8 -> V_198 >= 0 )
F_69 ( V_8 -> V_198 ) ;
V_194 -= 1 ;
for (; V_24 < V_194 ; V_24 ++ )
V_193 [ V_24 ] = V_193 [ V_24 + 1 ] ;
} else
F_11 ( V_18 L_43
L_44 ) ;
}
static inline void
F_81 ( T_1 * V_8 )
{
unsigned long V_41 ;
F_21 ( & V_207 , V_41 ) ;
F_82 ( V_208 , V_8 -> V_209 ? 0 : V_208 ) ;
F_22 ( & V_207 , V_41 ) ;
}
static void
F_83 ( T_1 * V_8 )
{
unsigned int V_111 , V_112 ;
V_111 = F_16 ( V_8 , V_114 ) ;
V_112 = F_16 ( V_8 , V_114 | 0x400 ) ;
if ( V_8 -> V_210 ) {
V_111 &= ~ 1 ;
V_112 &= ~ 1 ;
} else {
V_111 |= 1 ;
V_112 |= 1 ;
}
F_18 ( V_8 , V_115 , V_111 , V_112 ) ;
}
static int
F_84 ( T_1 * V_8 )
{
static signed int V_211 ;
unsigned long V_41 ;
signed int V_212 = 255 ;
* V_213 = 0x00ffffff ;
F_21 ( & V_45 , V_41 ) ;
F_3 ( 0xFF , 0x201 ) ;
* V_214 = V_215 | V_216 ;
while ( V_212 && ( F_2 ( 0x201 ) & 0x01 ) )
V_212 -- ;
* V_214 = 0 ;
F_22 ( & V_45 , V_41 ) ;
V_212 = 0x00ffffff - * V_217 ;
#ifndef F_85
V_212 = 150 - ( V_212 >> 5 ) ;
#else
V_212 = ( V_212 >> 6 ) - 25 ;
#endif
if ( V_212 < 0 )
V_212 = 0 ;
if ( V_212 > 100 )
V_212 = 100 ;
if ( abs ( V_212 - V_211 ) > 7 ) {
V_211 = V_212 ;
if ( V_25 & V_166 )
F_11 ( V_218 L_45 , V_212 ) ;
}
return V_211 ;
}
static unsigned int
F_86 ( T_1 * V_8 , unsigned int V_123 ,
unsigned char * V_124 , unsigned char * V_125 )
{
unsigned int V_219 = V_127 , V_220 = V_127 ;
if ( V_123 & V_128 ) {
V_123 = V_128 ;
V_219 = V_129 ;
V_220 = V_129 ;
} else if ( V_123 & V_134 ) {
V_123 = V_134 ;
V_219 = V_135 ;
V_220 = V_135 ;
} else if ( V_123 & V_132 ) {
V_123 = V_132 ;
F_15 ( V_8 , V_221 ) ;
V_219 = V_137 ;
V_220 = V_127 ;
} else if ( V_123 & V_222 ) {
V_123 = V_222 ;
F_15 ( V_8 , V_221 ) ;
V_219 = V_133 ;
V_220 = V_127 ;
} else if ( V_123 & V_136 ) {
V_123 = V_136 ;
F_15 ( V_8 , V_221 | 0x100 ) ;
V_219 = V_127 ;
V_220 = V_137 ;
}
* V_124 = V_219 ;
* V_125 = V_220 ;
return V_123 ;
}
static int
F_87 ( T_1 * V_8 , int V_38 , unsigned char V_138 ,
unsigned char V_139 )
{
switch ( V_38 ) {
case V_104 :
case V_118 :
case V_116 :
case V_140 :
case V_142 :
V_8 -> V_102 [ V_38 ] = V_138 | V_139 << 8 ;
break;
case V_141 :
V_8 -> V_102 [ V_141 ] &= 0xff ;
V_8 -> V_102 [ V_141 ] |= V_138 << 8 ;
break;
case V_143 :
V_8 -> V_102 [ V_141 ] &= 0xff00 ;
V_8 -> V_102 [ V_141 ] |= V_138 ;
V_38 = V_141 ;
break;
case V_223 :
V_8 -> V_102 [ V_143 ] = V_138 ;
V_38 = V_143 ;
break;
case V_145 :
case V_103 :
break;
default:
V_38 = - V_68 ;
break;
}
return V_38 ;
}
static int F_88 ( T_1 * V_8 , int V_38 )
{
int V_102 ;
switch ( V_38 ) {
case V_104 :
case V_118 :
case V_116 :
case V_140 :
case V_142 :
V_102 = V_8 -> V_102 [ V_38 ] ;
break;
case V_141 :
V_102 = V_8 -> V_102 [ V_141 ] >> 8 ;
V_102 |= V_102 << 8 ;
break;
case V_143 :
V_102 = V_8 -> V_102 [ V_141 ] & 0xff ;
V_102 |= V_102 << 8 ;
break;
case V_223 :
V_102 = V_8 -> V_102 [ V_143 ] & 0xff ;
V_102 |= V_102 << 8 ;
break;
default:
V_102 = 0 ;
}
return V_102 ;
}
static void
F_77 ( T_1 * V_8 , unsigned int V_123 )
{
if ( ! V_8 -> V_205 ) {
if ( V_8 -> V_224 ) {
V_123 = V_132 ;
V_8 -> V_209 = V_8 -> V_210 = 1 ;
} else if ( V_8 -> V_225 ) {
V_123 = V_222 ;
V_8 -> V_209 = V_8 -> V_210 = 1 ;
} else {
if ( ( V_8 -> V_123 & V_134 ) == 0 )
V_8 -> V_123 = V_136 ;
V_8 -> V_209 = V_8 -> V_210 = 0 ;
}
F_81 ( V_8 ) ;
F_83 ( V_8 ) ;
if ( V_123 != V_8 -> V_123 )
F_50 ( V_8 , V_123 ) ;
}
}
static int
F_89 ( T_1 * V_8 )
{
signed int V_226 ;
unsigned int V_36 , V_227 , V_228 ;
V_36 = F_2 ( 0x201 ) ;
V_227 = V_8 -> V_224 ;
V_228 = V_8 -> V_225 ;
V_8 -> V_224 = ! ( V_36 & 0x10 ) ;
V_8 -> V_225 = ! ! ( V_36 & 0x20 ) ;
if ( ! V_8 -> V_205 &&
( V_227 != V_8 -> V_224 ||
V_228 != V_8 -> V_225 ) )
F_77 ( V_8 , V_8 -> V_123 ) ;
V_226 = F_84 ( V_8 ) ;
if ( abs ( V_8 -> V_229 - V_226 ) > 20 )
V_8 -> V_230 = 1 ;
V_36 = V_102 [ V_104 ] & 0xFF ;
if ( V_226 != V_36 && V_8 -> V_230 ) {
V_8 -> V_229 = V_226 ;
F_52 ( V_8 , V_104 ,
V_226 | V_226 << 8 ) ;
return 1 ;
}
return 0 ;
}
static void
V_201 ( unsigned long V_204 )
{
int V_231 ;
if ( F_89 ( V_193 + V_204 ) )
V_231 = 5 ;
else
V_231 = V_232 ;
F_90 ( & V_199 , V_203 + V_231 ) ;
}
static int
F_55 ( int V_38 , unsigned int V_20 , int T_3 * V_31 )
{
T_1 * V_8 = ( T_1 * ) V_44 [ V_38 ] -> V_8 ;
int V_151 ;
switch ( V_20 ) {
case V_233 :
{
T_9 V_234 , V_235 , V_236 ;
int V_151 ;
if ( F_57 ( V_151 , V_31 ) )
return - V_155 ;
if ( V_151 & ~ ( V_237 |
V_238 |
V_239 ) )
return - V_68 ;
V_236 = V_8 -> V_205 ;
V_234 = V_8 -> V_209 ;
V_235 = V_8 -> V_210 ;
V_8 -> V_205 = ( V_151 & V_239 ) ? 1 : 0 ;
V_8 -> V_209 = ( V_151 & V_237 ) ? 1 : 0 ;
V_8 -> V_210 = ( V_151 & V_238 ) ? 1 : 0 ;
if ( V_234 != V_8 -> V_209 )
F_81 ( V_8 ) ;
if ( V_235 != V_8 -> V_210 )
F_83 ( V_8 ) ;
if ( V_236 != V_8 -> V_205 )
F_77 ( V_8 , V_8 -> V_123 ) ;
return 0 ;
}
case V_240 :
if ( F_57 ( V_151 , V_31 ) )
return - V_155 ;
switch ( V_151 ) {
#define F_91 0x53
#define F_92 0x57
case F_91 :
F_15 ( V_8 , 0x16 ) ;
break;
case F_92 :
F_15 ( V_8 , 0x18 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
case V_241 :
{
unsigned long V_41 ;
int V_242 [ 15 ] , V_24 , V_151 ;
if ( F_57 ( V_151 , V_31 ) )
return - V_155 ;
if ( F_93 ( V_242 , ( void * ) V_151 , sizeof( V_242 ) ) )
return - V_155 ;
switch ( V_242 [ 14 ] ) {
case V_243 :
F_59 ( V_8 ) ;
break;
case V_244 :
F_18 ( V_8 , V_115 , V_242 [ 0 ] , V_242 [ 4 ] ) ;
F_18 ( V_8 , V_115 , V_242 [ 1 ] , V_242 [ 5 ] ) ;
F_18 ( V_8 , V_115 , V_242 [ 2 ] , V_242 [ 6 ] ) ;
F_18 ( V_8 , V_115 , V_242 [ 3 ] , V_242 [ 7 ] ) ;
F_18 ( V_8 , V_115 , V_242 [ 8 ] , V_242 [ 9 ] ) ;
F_18 ( V_8 , V_117 , V_242 [ 10 ] , V_242 [ 11 ] ) ;
F_18 ( V_8 , V_117 , V_242 [ 12 ] , V_242 [ 13 ] ) ;
break;
case V_245 :
F_21 ( & V_45 , V_41 ) ;
for ( V_24 = 0x30 ; V_24 < 14 << 8 ; V_24 += 1 << 8 )
F_12 ( V_8 , 1 , & V_24 , 1 , V_242 + ( V_24 >> 8 ) ) ;
F_22 ( & V_45 , V_41 ) ;
if ( F_94 ( ( void * ) V_151 , V_242 , sizeof( V_242 ) ) )
return - V_155 ;
break;
default:
return - V_68 ;
}
return 0 ;
}
case V_246 :
V_151 = ( V_8 -> V_209 ? V_237 : 0 ) |
( V_8 -> V_210 ? V_238 : 0 ) |
( V_8 -> V_224 ? V_247 : 0 ) |
( V_8 -> V_225 ? V_248 : 0 ) |
( V_8 -> V_205 ? V_239 : 0 ) ;
return F_58 ( V_151 , V_31 ) ? - V_155 : 0 ;
}
if ( F_56 ( V_20 ) & V_154 ) {
if ( ( V_20 & 0xff ) == V_104 )
V_8 -> V_230 = 0 ;
if ( ( V_20 & 0xff ) == V_249 ) {
unsigned int V_151 , V_250 , V_251 ;
if ( F_57 ( V_151 , V_31 ) )
return - V_155 ;
V_250 = V_151 & 0x7f ;
V_251 = ( V_151 & 0x7f00 ) >> 8 ;
V_151 = ( V_250 + V_251 ) / 2 ;
V_8 -> V_102 [ V_249 ] = V_151 | ( V_151 << 8 ) ;
V_8 -> V_209 = ( V_151 <= 50 ) ;
F_81 ( V_8 ) ;
return 0 ;
}
}
return - V_153 ;
}
static int T_7 F_95 ( void )
{
const struct V_196 * V_109 ;
if ( ! V_252 && F_45 () ) {
V_252 = 0x250 ;
V_92 = 12 ;
V_173 = 3 ;
V_174 = 7 ;
}
V_109 = & V_253 ;
#ifdef F_54
if ( F_45 () )
V_109 = & V_254 ;
#endif
V_255 . V_6 = V_252 ;
V_255 . V_92 = V_92 ;
V_255 . V_173 = V_173 ;
V_255 . V_174 = V_174 ;
if ( ! F_71 ( & V_255 ) )
return - V_171 ;
F_74 ( & V_255 , V_109 ) ;
V_256 = 1 ;
return 0 ;
}
static void T_8 F_96 ( void )
{
if ( V_256 )
F_78 ( & V_255 ) ;
}
static int T_7 F_97 ( char * V_257 )
{
int V_258 [ 5 ] ;
V_257 = F_98 ( V_257 , F_99 ( V_258 ) , V_258 ) ;
V_252 = V_258 [ 1 ] ;
V_92 = V_258 [ 2 ] ;
V_173 = V_258 [ 3 ] ;
V_174 = V_258 [ 4 ] ;
return 1 ;
}
