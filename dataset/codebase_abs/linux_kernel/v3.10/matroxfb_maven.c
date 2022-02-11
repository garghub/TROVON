static int F_1 ( T_1 V_1 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 < V_4 [ V_2 ] . V_5 . V_6 ) {
if ( V_4 [ V_2 ] . V_5 . V_6 == 0x08000000 ) {
return - V_7 ;
}
return - V_8 ;
}
if ( V_1 == V_4 [ V_2 ] . V_5 . V_6 ) {
return V_2 ;
}
}
return - V_7 ;
}
static int * F_2 ( struct V_9 * V_10 , int V_11 ) {
return ( int * ) ( ( char * ) ( V_10 -> V_12 ) + V_4 [ V_11 ] . V_13 ) ;
}
static int F_3 ( struct V_14 * V_15 , char V_16 ) {
char V_17 ;
struct V_18 V_19 [] = {
{
. V_20 = V_15 -> V_20 ,
. V_21 = V_22 ,
. V_23 = sizeof( V_16 ) ,
. V_24 = & V_16
} ,
{
. V_20 = V_15 -> V_20 ,
. V_21 = V_25 | V_26 ,
. V_23 = sizeof( V_17 ) ,
. V_24 = & V_17
}
} ;
T_2 V_27 ;
V_27 = F_4 ( V_15 -> V_28 , V_19 , 2 ) ;
if ( V_27 < 0 )
F_5 ( V_29 L_1 , V_16 ) ;
return V_17 & 0xFF ;
}
static int F_6 ( struct V_14 * V_15 , int V_16 , int V_30 ) {
T_2 V_27 ;
V_27 = F_7 ( V_15 , V_16 , V_30 ) ;
if ( V_27 )
F_5 ( V_29 L_2 , V_16 ) ;
return V_27 ;
}
static int F_8 ( struct V_14 * V_15 , int V_16 , int V_30 ) {
T_2 V_27 ;
V_27 = F_9 ( V_15 , V_16 , V_30 ) ;
if ( V_27 )
F_5 ( V_29 L_3 , V_16 ) ;
return V_27 ;
}
static int F_10 ( const struct V_31 * V_32 ,
const struct V_33 * V_34 ,
unsigned int V_35 , unsigned int V_36 ,
unsigned int * V_37 , unsigned int * V_38 , unsigned int * V_39 ,
unsigned int * V_40 ) {
unsigned int V_41 = 0 ;
unsigned int V_42 = V_34 -> V_43 ;
unsigned int V_44 = V_32 -> V_45 / V_34 -> V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
F_11 (__func__)
V_49 = V_35 * ( V_36 - 1 ) ;
V_47 = V_35 * V_36 ;
V_50 = V_32 -> V_51 / V_34 -> V_46 ;
F_12 ( V_52 L_4 ,
V_47 , V_42 , V_35 , V_36 , V_50 ) ;
for ( V_48 = 1 ; V_48 <= V_32 -> V_53 ; V_48 ++ ) {
if ( V_47 * 2 > V_50 )
break;
V_47 *= 2 ;
}
if ( V_47 > V_50 )
return 0 ;
for (; V_48 -- > 0 ; V_47 >>= 1 ) {
unsigned int V_54 ;
if ( V_47 < V_44 ) break;
for ( V_54 = V_32 -> V_55 ; V_54 <= V_32 -> V_56 ; V_54 ++ ) {
unsigned int V_57 ;
unsigned int V_58 ;
unsigned int V_59 ;
V_57 = ( V_47 * V_54 ) / V_42 ;
if ( V_57 < V_32 -> V_60 )
continue;
if ( V_57 > V_32 -> V_61 )
break;
V_59 = V_42 * V_57 ;
V_58 = V_54 << V_48 ;
if ( V_59 % V_58 )
continue;
V_59 = V_59 / V_58 ;
if ( V_59 < V_49 + 2 )
continue;
V_59 = V_59 - V_49 ;
if ( V_59 > V_35 )
continue;
F_12 ( V_52 L_5 , V_57 , V_54 , V_48 , V_59 ) ;
if ( V_59 > V_41 ) {
F_12 ( V_52 L_6 ) ;
* V_40 = V_41 = V_59 ;
* V_39 = V_48 ;
* V_37 = V_54 ;
* V_38 = V_57 ;
}
}
}
if ( V_41 < 2 )
return 0 ;
F_12 ( V_62 L_7 , * V_37 , * V_38 , * V_39 , V_42 , V_47 ) ;
return V_42 * ( * V_38 ) / ( * V_37 ) * V_34 -> V_46 ;
}
static int F_13 ( const struct V_33 * V_34 ,
unsigned int V_35 , unsigned int V_36 ,
unsigned int * V_37 , unsigned int * V_38 , unsigned int * V_39 ,
unsigned int * V_63 ) {
unsigned int V_64 ;
unsigned int V_65 ( V_48 ) ;
V_64 = F_10 ( & V_66 , V_34 , V_35 , V_36 , V_37 , V_38 , & V_48 , V_63 ) ;
if ( ! V_64 )
return - V_7 ;
V_48 = ( 1 << V_48 ) - 1 ;
if ( V_64 <= 100000000 )
;
else if ( V_64 <= 140000000 )
V_48 |= 0x08 ;
else if ( V_64 <= 180000000 )
V_48 |= 0x10 ;
else
V_48 |= 0x18 ;
* V_39 = V_48 ;
return 0 ;
}
static void F_14 ( unsigned int V_67 , unsigned int V_50 ,
unsigned int * V_37 , unsigned int * V_38 , unsigned int * V_39 ) {
unsigned int V_64 ;
unsigned int V_48 ;
V_64 = F_15 ( & V_68 , V_67 , V_50 , V_37 , V_38 , & V_48 ) ;
V_48 = ( 1 << V_48 ) - 1 ;
if ( V_64 <= 100000 )
;
else if ( V_64 <= 140000 )
V_48 |= 0x08 ;
else if ( V_64 <= 180000 )
V_48 |= 0x10 ;
else
V_48 |= 0x18 ;
* V_39 = V_48 ;
return;
}
static unsigned char F_16 ( const struct V_9 * V_10 ) {
unsigned char V_69 ;
V_69 = ( V_10 -> V_70 == V_71 ? 0x40 : 0x00 ) ;
switch ( V_10 -> V_12 -> V_72 . V_73 . V_74 ) {
case 0 :
break;
case 1 :
V_69 |= 0xB1 ;
break;
case 2 :
V_69 |= 0xA2 ;
break;
}
return V_69 ;
}
static void F_17 ( const struct V_9 * V_10 ,
int * V_75 , int * V_76 ) {
const int V_77 = V_10 -> V_12 -> V_72 . V_73 . V_78 + V_79 ;
const int V_15 = V_10 -> V_12 -> V_72 . V_73 . V_80 ;
* V_75 = F_18 ( V_77 - V_15 , V_79 ) ;
* V_76 = F_19 ( V_77 + V_15 , V_81 ) ;
}
static const struct V_82 * F_20 ( const struct V_9 * V_10 ) {
return V_82 + V_10 -> V_12 -> V_72 . V_73 . gamma ;
}
static void F_21 ( const struct V_9 * V_10 , struct V_83 * V_84 ) {
static struct V_83 V_85 = { {
0x2A , 0x09 , 0x8A , 0xCB ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x7E ,
0x44 ,
0x9C ,
0x2E ,
0x21 ,
0x00 ,
0x3F , 0x03 ,
0x3F , 0x03 ,
0x1A ,
0x2A ,
0x1C , 0x3D , 0x14 ,
0x9C , 0x01 ,
0x00 ,
0xFE ,
0x7E ,
0x60 ,
0x05 ,
0x89 , 0x03 ,
0x72 ,
0x07 ,
0x72 ,
0x00 ,
0x00 ,
0x00 ,
0x08 ,
0x04 ,
0x00 ,
0x1A ,
0x55 , 0x01 ,
0x26 ,
0x07 , 0x7E ,
0x02 , 0x54 ,
0xB0 , 0x00 ,
0x14 ,
0x49 ,
0x00 ,
0x00 ,
0xA3 ,
0xC8 ,
0x22 ,
0x02 ,
0x22 ,
0x3F , 0x03 ,
0x00 ,
0x00 ,
} , V_86 , 625 , 50 } ;
static struct V_83 V_87 = { {
0x21 , 0xF0 , 0x7C , 0x1F ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x7E ,
0x43 ,
0x7E ,
0x3D ,
0x00 ,
0x00 ,
0x41 , 0x00 ,
0x3C , 0x00 ,
0x17 ,
0x21 ,
0x1B , 0x1B , 0x24 ,
0x83 , 0x01 ,
0x00 ,
0x0F ,
0x0F ,
0x60 ,
0x05 ,
0x89 , 0x02 ,
0x5F ,
0x04 ,
0x5F ,
0x01 ,
0x02 ,
0x00 ,
0x0A ,
0x05 ,
0x00 ,
0x10 ,
0xFF , 0x03 ,
0x24 ,
0x0F , 0x78 ,
0x00 , 0x00 ,
0xB2 , 0x04 ,
0x14 ,
0x02 ,
0x00 ,
0x00 ,
0xA3 ,
0xC8 ,
0x15 ,
0x05 ,
0x3B ,
0x3C , 0x00 ,
0x00 ,
0x00 ,
} , V_88 , 525 , 60 } ;
struct V_89 * V_90 = V_10 -> V_12 ;
if ( V_90 -> V_91 [ 1 ] . V_92 == V_86 )
* V_84 = V_85 ;
else
* V_84 = V_87 ;
V_84 -> V_93 [ 0x93 ] = F_16 ( V_10 ) ;
{
const struct V_82 * V_94 ;
V_94 = F_20 ( V_10 ) ;
V_84 -> V_93 [ 0x83 ] = V_94 -> V_95 ;
V_84 -> V_93 [ 0x84 ] = V_94 -> V_96 ;
V_84 -> V_93 [ 0x85 ] = V_94 -> V_97 ;
V_84 -> V_93 [ 0x86 ] = V_94 -> V_98 ;
V_84 -> V_93 [ 0x87 ] = V_94 -> V_99 ;
V_84 -> V_93 [ 0x88 ] = V_94 -> V_100 ;
V_84 -> V_93 [ 0x89 ] = V_94 -> V_101 ;
V_84 -> V_93 [ 0x8A ] = V_94 -> V_102 ;
V_84 -> V_93 [ 0x8B ] = V_94 -> V_103 ;
}
{
int V_75 , V_76 ;
F_17 ( V_10 , & V_75 , & V_76 ) ;
V_84 -> V_93 [ 0x0e ] = V_75 >> 2 ;
V_84 -> V_93 [ 0x0f ] = V_75 & 3 ;
V_84 -> V_93 [ 0x1e ] = V_76 >> 2 ;
V_84 -> V_93 [ 0x1f ] = V_76 & 3 ;
}
{
V_84 -> V_93 [ 0x20 ] =
V_84 -> V_93 [ 0x22 ] = V_90 -> V_72 . V_73 . V_104 ;
}
V_84 -> V_93 [ 0x25 ] = V_90 -> V_72 . V_73 . V_105 ;
return;
}
static void F_22 ( struct V_14 * V_15 , const struct V_83 * V_54 ) {
int V_30 ;
F_6 ( V_15 , 0x3E , 0x01 ) ;
F_3 ( V_15 , 0x82 ) ;
F_6 ( V_15 , 0x8C , 0x00 ) ;
F_3 ( V_15 , 0x94 ) ;
F_6 ( V_15 , 0x94 , 0xA2 ) ;
F_8 ( V_15 , 0x8E , 0x1EFF ) ;
F_6 ( V_15 , 0xC6 , 0x01 ) ;
F_3 ( V_15 , 0x06 ) ;
F_6 ( V_15 , 0x06 , 0xF9 ) ;
F_23 ( 0x00 ) ; F_23 ( 0x01 ) ; F_23 ( 0x02 ) ; F_23 ( 0x03 ) ;
F_23 ( 0x04 ) ;
F_23 ( 0x2C ) ;
F_23 ( 0x08 ) ;
F_23 ( 0x0A ) ;
F_23 ( 0x09 ) ;
F_23 ( 0x29 ) ;
F_24 ( 0x31 ) ;
F_24 ( 0x17 ) ;
F_23 ( 0x0B ) ;
F_23 ( 0x0C ) ;
if ( V_54 -> V_92 == V_86 ) {
F_6 ( V_15 , 0x35 , 0x10 ) ;
} else {
F_6 ( V_15 , 0x35 , 0x0F ) ;
}
F_24 ( 0x10 ) ;
F_24 ( 0x0E ) ;
F_24 ( 0x1E ) ;
F_23 ( 0x20 ) ;
F_23 ( 0x22 ) ;
F_23 ( 0x25 ) ;
F_23 ( 0x34 ) ;
F_23 ( 0x33 ) ;
F_23 ( 0x19 ) ;
F_23 ( 0x12 ) ;
F_23 ( 0x3B ) ;
F_23 ( 0x13 ) ;
F_23 ( 0x39 ) ;
F_23 ( 0x1D ) ;
F_23 ( 0x3A ) ;
F_23 ( 0x24 ) ;
F_23 ( 0x14 ) ;
F_23 ( 0x15 ) ;
F_23 ( 0x16 ) ;
F_24 ( 0x2D ) ;
F_24 ( 0x2F ) ;
F_23 ( 0x1A ) ;
F_23 ( 0x1B ) ;
F_23 ( 0x1C ) ;
F_23 ( 0x23 ) ;
F_23 ( 0x26 ) ;
F_23 ( 0x28 ) ;
F_23 ( 0x27 ) ;
F_23 ( 0x21 ) ;
F_24 ( 0x2A ) ;
if ( V_54 -> V_92 == V_86 )
F_6 ( V_15 , 0x35 , 0x1D ) ;
else
F_6 ( V_15 , 0x35 , 0x1C ) ;
F_24 ( 0x3C ) ;
F_23 ( 0x37 ) ;
F_23 ( 0x38 ) ;
F_6 ( V_15 , 0xB3 , 0x01 ) ;
F_3 ( V_15 , 0xB0 ) ;
F_6 ( V_15 , 0xB0 , 0x08 ) ;
F_3 ( V_15 , 0xB9 ) ;
F_6 ( V_15 , 0xB9 , 0x78 ) ;
F_3 ( V_15 , 0xBF ) ;
F_6 ( V_15 , 0xBF , 0x02 ) ;
F_3 ( V_15 , 0x94 ) ;
F_6 ( V_15 , 0x94 , 0xB3 ) ;
F_23 ( 0x80 ) ;
F_23 ( 0x81 ) ;
F_23 ( 0x82 ) ;
F_6 ( V_15 , 0x8C , 0x20 ) ;
F_3 ( V_15 , 0x8D ) ;
F_6 ( V_15 , 0x8D , 0x10 ) ;
F_23 ( 0x90 ) ;
F_23 ( 0x91 ) ;
F_23 ( 0x92 ) ;
F_24 ( 0x9A ) ;
F_24 ( 0x9C ) ;
F_24 ( 0x9E ) ;
F_24 ( 0xA0 ) ;
F_24 ( 0xA2 ) ;
F_24 ( 0xA4 ) ;
F_24 ( 0xA6 ) ;
F_24 ( 0xA8 ) ;
F_24 ( 0x98 ) ;
F_24 ( 0xAE ) ;
F_24 ( 0x96 ) ;
F_24 ( 0xAA ) ;
F_24 ( 0xAC ) ;
F_23 ( 0xBE ) ;
F_23 ( 0xC2 ) ;
F_3 ( V_15 , 0x8D ) ;
F_6 ( V_15 , 0x8D , 0x04 ) ;
F_23 ( 0x20 ) ;
F_23 ( 0x22 ) ;
F_23 ( 0x93 ) ;
F_23 ( 0x20 ) ;
F_23 ( 0x22 ) ;
F_23 ( 0x25 ) ;
F_24 ( 0x0E ) ;
F_24 ( 0x1E ) ;
F_24 ( 0x0E ) ;
F_24 ( 0x1E ) ;
F_23 ( 0x83 ) ;
F_23 ( 0x84 ) ;
F_23 ( 0x85 ) ;
F_23 ( 0x86 ) ;
F_23 ( 0x87 ) ;
F_23 ( 0x88 ) ;
F_23 ( 0x89 ) ;
F_23 ( 0x8A ) ;
F_23 ( 0x8B ) ;
V_30 = F_3 ( V_15 , 0x8D ) ;
V_30 &= 0x14 ;
F_6 ( V_15 , 0x8D , V_30 ) ;
F_23 ( 0x33 ) ;
F_23 ( 0x19 ) ;
F_23 ( 0x12 ) ;
F_23 ( 0x3B ) ;
F_23 ( 0x13 ) ;
F_23 ( 0x39 ) ;
F_23 ( 0x1D ) ;
F_23 ( 0x3A ) ;
F_23 ( 0x24 ) ;
F_23 ( 0x14 ) ;
F_23 ( 0x15 ) ;
F_23 ( 0x16 ) ;
F_24 ( 0x2D ) ;
F_24 ( 0x2F ) ;
F_23 ( 0x1A ) ;
F_23 ( 0x1B ) ;
F_23 ( 0x1C ) ;
F_23 ( 0x23 ) ;
F_23 ( 0x26 ) ;
F_23 ( 0x28 ) ;
F_23 ( 0x27 ) ;
F_23 ( 0x21 ) ;
F_24 ( 0x2A ) ;
if ( V_54 -> V_92 == V_86 )
F_6 ( V_15 , 0x35 , 0x1D ) ;
else
F_6 ( V_15 , 0x35 , 0x1C ) ;
F_24 ( 0x3C ) ;
F_23 ( 0x37 ) ;
F_23 ( 0x38 ) ;
F_3 ( V_15 , 0xB0 ) ;
F_23 ( 0xB0 ) ;
F_23 ( 0x90 ) ;
F_23 ( 0xBE ) ;
F_23 ( 0xC2 ) ;
F_24 ( 0x9A ) ;
F_24 ( 0xA2 ) ;
F_24 ( 0x9E ) ;
F_24 ( 0xA6 ) ;
F_24 ( 0xAA ) ;
F_24 ( 0xAC ) ;
F_6 ( V_15 , 0x3E , 0x00 ) ;
F_6 ( V_15 , 0x95 , 0x20 ) ;
}
static int F_25 ( unsigned int V_106 , unsigned int V_107 ,
struct V_83 * V_54 ) {
unsigned int V_108 ;
unsigned int V_27 = ~ 0 ;
V_54 -> V_93 [ 0x80 ] = 0x0F ;
V_54 -> V_93 [ 0x81 ] = 0x07 ;
V_54 -> V_93 [ 0x82 ] = 0x81 ;
for ( V_108 = 0 ; V_108 < 8 ; V_108 ++ ) {
unsigned int V_15 ;
unsigned int V_65 ( V_109 ) , V_65 ( V_77 ) ,
V_65 ( V_40 ) ;
unsigned int V_110 = V_106 + 2 + V_108 ;
if ( ! F_13 ( ( V_54 -> V_92 == V_86 ) ? & V_111 : & V_112 , V_110 , V_107 , & V_109 , & V_77 , & V_15 , & V_40 ) ) {
unsigned int V_113 = V_110 - V_40 ;
if ( V_113 < V_27 ) {
V_27 = V_113 ;
V_54 -> V_93 [ 0x80 ] = V_109 - 1 ;
V_54 -> V_93 [ 0x81 ] = V_77 - 1 ;
V_54 -> V_93 [ 0x82 ] = V_15 | 0x80 ;
V_54 -> V_114 = V_40 - 2 ;
V_54 -> V_35 = V_110 - 2 ;
}
}
}
return V_27 != ~ 0U ;
}
static inline int F_26 ( struct V_9 * V_10 ,
struct V_115 * V_116 ,
struct V_83 * V_54 ) {
unsigned int V_117 ;
unsigned int V_109 , V_118 , V_15 ;
struct V_89 * V_90 = V_10 -> V_12 ;
V_54 -> V_92 = V_90 -> V_91 [ 1 ] . V_92 ;
if ( V_54 -> V_92 != V_119 ) {
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
F_21 ( V_10 , V_54 ) ;
if ( F_25 ( V_116 -> V_125 , V_116 -> V_126 , V_54 ) == 0 )
return - V_7 ;
V_120 = V_116 -> V_125 - V_116 -> V_127 ;
V_124 = V_116 -> V_127 - V_116 -> V_128 ;
V_123 = V_116 -> V_125 - V_124 - V_116 -> V_129 ;
V_121 = V_116 -> V_126 - V_116 -> V_130 ;
V_122 = V_116 -> V_130 - V_116 -> V_131 ;
if ( V_54 -> V_114 < V_116 -> V_125 )
V_123 += V_54 -> V_114 ;
if ( V_123 > V_116 -> V_125 )
V_123 -= V_116 -> V_125 ;
if ( V_123 + 2 > V_116 -> V_125 )
V_123 = 0 ;
V_54 -> V_93 [ 0x96 ] = V_54 -> V_114 ;
V_54 -> V_93 [ 0x97 ] = V_54 -> V_114 >> 8 ;
V_54 -> V_93 [ 0x98 ] = 0x00 ; V_54 -> V_93 [ 0x99 ] = 0x00 ;
V_54 -> V_93 [ 0x9A ] = V_120 ;
V_54 -> V_93 [ 0x9B ] = V_120 >> 8 ;
V_54 -> V_93 [ 0x9C ] = 0x04 ;
V_54 -> V_93 [ 0x9D ] = 0x00 ;
V_54 -> V_93 [ 0xA0 ] = V_54 -> V_35 ;
V_54 -> V_93 [ 0xA1 ] = V_54 -> V_35 >> 8 ;
V_54 -> V_93 [ 0xA2 ] = V_116 -> V_126 - V_116 -> V_131 - 1 ;
V_54 -> V_93 [ 0xA3 ] = ( V_116 -> V_126 - V_116 -> V_131 - 1 ) >> 8 ;
if ( V_10 -> V_70 == V_71 ) {
V_54 -> V_93 [ 0xA4 ] = 0x04 ;
V_54 -> V_93 [ 0xA5 ] = 0x00 ;
} else {
V_54 -> V_93 [ 0xA4 ] = 0x01 ;
V_54 -> V_93 [ 0xA5 ] = 0x00 ;
}
V_54 -> V_93 [ 0xA6 ] = 0x00 ;
V_54 -> V_93 [ 0xA7 ] = 0x00 ;
V_54 -> V_93 [ 0xA8 ] = V_116 -> V_126 - 1 ;
V_54 -> V_93 [ 0xA9 ] = ( V_116 -> V_126 - 1 ) >> 8 ;
V_54 -> V_93 [ 0xAA ] = V_123 ;
V_54 -> V_93 [ 0xAB ] = V_123 >> 8 ;
V_54 -> V_93 [ 0xAC ] = V_116 -> V_126 - 2 ;
V_54 -> V_93 [ 0xAD ] = ( V_116 -> V_126 - 2 ) >> 8 ;
V_54 -> V_93 [ 0xAE ] = 0x01 ;
V_54 -> V_93 [ 0xAF ] = 0x00 ;
{
int V_132 ;
int V_133 ;
unsigned int V_134 = 4 + V_120 + V_116 -> V_135 ;
unsigned int V_136 ;
int V_2 ;
if ( V_116 -> V_125 )
V_132 = 94208 / ( V_116 -> V_125 ) ;
else
V_132 = 0x81 ;
if ( V_132 > 0x81 )
V_132 = 0x81 ;
if ( V_132 < 0x41 )
V_132 = 0x41 ;
V_132 -- ;
V_133 = 98304 - 128 - ( ( V_120 + V_116 -> V_135 - 8 ) * V_132 ) ;
if ( V_133 < 0 )
V_133 = 0 ;
V_133 = V_133 >> 8 ;
if ( V_133 > 0xFF )
V_133 = 0xFF ;
V_2 = 1 ;
do {
V_136 = ( ( 0x3C0000 * V_2 - 0x8000 ) / V_132 + 0x05E7 ) >> 8 ;
V_2 ++ ;
} while ( V_136 < V_134 );
if ( V_136 >= V_54 -> V_35 + 2 ) {
V_136 = V_134 ;
}
V_54 -> V_93 [ 0x90 ] = V_132 ;
V_54 -> V_93 [ 0xC2 ] = V_133 ;
V_54 -> V_93 [ 0x9E ] = V_136 ;
V_54 -> V_93 [ 0x9F ] = V_136 >> 8 ;
}
{
int V_137 ;
int V_138 ;
#define F_27
if ( V_116 -> V_126 ) {
#ifdef F_27
T_3 V_139 ;
T_4 V_109 ;
T_4 V_77 ;
V_109 = V_54 -> V_140 * ( V_54 -> V_35 + 2 ) ;
V_77 = ( V_116 -> V_126 - 1 ) * ( V_54 -> V_35 + 2 ) + V_54 -> V_114 + 2 ;
V_139 = ( ( T_3 ) V_109 ) << 15 ;
F_28 ( V_139 , V_77 ) ;
V_137 = V_139 ;
#else
V_137 = V_54 -> V_140 * 32768 / V_116 -> V_126 ;
#endif
} else
V_137 = 0x8000 ;
if ( V_137 > 0x8000 )
V_137 = 0x8000 ;
V_138 = ( V_122 + V_121 + V_116 -> V_141 ) * V_137 ;
V_138 = ( V_138 >> 16 ) - 146 ;
if ( V_138 < 0 )
V_138 = 0 ;
if ( V_138 > 0xFF )
V_138 = 0xFF ;
V_137 -- ;
V_54 -> V_93 [ 0x91 ] = V_137 ;
V_54 -> V_93 [ 0x92 ] = V_137 >> 8 ;
V_54 -> V_93 [ 0xBE ] = V_138 ;
}
V_54 -> V_93 [ 0xB0 ] = 0x08 ;
return 0 ;
}
F_14 ( V_116 -> V_142 , 450000 , & V_109 , & V_118 , & V_15 ) ;
V_54 -> V_93 [ 0x80 ] = V_109 ;
V_54 -> V_93 [ 0x81 ] = V_118 ;
V_54 -> V_93 [ 0x82 ] = V_15 | 0x80 ;
V_54 -> V_93 [ 0xB3 ] = 0x01 ;
V_54 -> V_93 [ 0x94 ] = 0xB2 ;
V_54 -> V_93 [ 0x96 ] = V_116 -> V_125 ;
V_54 -> V_93 [ 0x97 ] = V_116 -> V_125 >> 8 ;
V_54 -> V_93 [ 0x98 ] = 0x00 ;
V_54 -> V_93 [ 0x99 ] = 0x00 ;
V_117 = V_116 -> V_127 - V_116 -> V_128 ;
V_54 -> V_93 [ 0x9A ] = V_117 ;
V_54 -> V_93 [ 0x9B ] = V_117 >> 8 ;
V_117 = V_116 -> V_125 - V_116 -> V_128 ;
V_54 -> V_93 [ 0x9C ] = V_117 ;
V_54 -> V_93 [ 0x9D ] = V_117 >> 8 ;
V_117 += V_116 -> V_135 ;
V_54 -> V_93 [ 0x9E ] = V_117 ;
V_54 -> V_93 [ 0x9F ] = V_117 >> 8 ;
V_117 = V_116 -> V_125 + 1 ;
V_54 -> V_93 [ 0xA0 ] = V_117 ;
V_54 -> V_93 [ 0xA1 ] = V_117 >> 8 ;
V_117 = V_116 -> V_130 - V_116 -> V_131 - 1 ;
V_54 -> V_93 [ 0xA2 ] = V_117 ;
V_54 -> V_93 [ 0xA3 ] = V_117 >> 8 ;
V_117 = V_116 -> V_126 - V_116 -> V_131 ;
V_54 -> V_93 [ 0xA4 ] = V_117 ;
V_54 -> V_93 [ 0xA5 ] = V_117 >> 8 ;
V_117 = V_116 -> V_126 - 1 ;
V_54 -> V_93 [ 0xA6 ] = V_117 ;
V_54 -> V_93 [ 0xA7 ] = V_117 >> 8 ;
V_54 -> V_93 [ 0xA8 ] = V_117 ;
V_54 -> V_93 [ 0xA9 ] = V_117 >> 8 ;
V_117 = V_116 -> V_125 - V_116 -> V_129 ;
V_54 -> V_93 [ 0xAA ] = V_117 ;
V_54 -> V_93 [ 0xAB ] = V_117 >> 8 ;
V_117 = V_116 -> V_126 - 2 ;
V_54 -> V_93 [ 0xAC ] = V_117 ;
V_54 -> V_93 [ 0xAD ] = V_117 >> 8 ;
V_54 -> V_93 [ 0xAE ] = 0x00 ;
V_54 -> V_93 [ 0xAF ] = 0x00 ;
V_54 -> V_93 [ 0xB0 ] = 0x03 ;
V_54 -> V_93 [ 0xB1 ] = 0xA0 ;
V_54 -> V_93 [ 0x8C ] = 0x20 ;
V_54 -> V_93 [ 0x8D ] = 0x04 ;
V_54 -> V_93 [ 0xB9 ] = 0x1A ;
V_54 -> V_93 [ 0xBF ] = 0x22 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
const struct V_83 * V_54 ) {
struct V_14 * V_15 = V_10 -> V_143 ;
if ( V_54 -> V_92 == V_119 ) {
F_23 ( 0x80 ) ;
F_23 ( 0x81 ) ;
F_23 ( 0x82 ) ;
F_23 ( 0xB3 ) ;
F_23 ( 0x94 ) ;
F_24 ( 0x96 ) ;
F_24 ( 0x98 ) ;
F_24 ( 0x9A ) ;
F_24 ( 0x9C ) ;
F_24 ( 0x9E ) ;
F_24 ( 0xA0 ) ;
F_24 ( 0xA2 ) ;
F_24 ( 0xA4 ) ;
F_24 ( 0xA6 ) ;
F_24 ( 0xA8 ) ;
F_24 ( 0xAA ) ;
F_24 ( 0xAC ) ;
F_24 ( 0xAE ) ;
F_23 ( 0xB0 ) ;
F_23 ( 0xB1 ) ;
F_23 ( 0x8C ) ;
F_23 ( 0x8D ) ;
F_23 ( 0xB9 ) ;
F_23 ( 0xBF ) ;
} else {
F_22 ( V_15 , V_54 ) ;
}
return 0 ;
}
static inline int F_30 ( struct V_9 * V_10 ) {
struct V_14 * V_15 = V_10 -> V_143 ;
F_6 ( V_15 , 0x95 , 0x20 ) ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 ,
struct V_144 * V_48 ) {
int V_2 ;
V_2 = F_1 ( V_48 -> V_6 ) ;
if ( V_2 >= 0 ) {
* V_48 = V_4 [ V_2 ] . V_5 ;
return 0 ;
}
if ( V_2 == - V_8 ) {
static const struct V_144 V_145 =
{ . V_21 = V_146 } ;
V_2 = V_48 -> V_6 ;
* V_48 = V_145 ;
V_48 -> V_6 = V_2 ;
sprintf ( V_48 -> V_147 , L_8 , V_2 ) ;
return 0 ;
}
return - V_7 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_148 * V_48 ) {
int V_2 ;
V_2 = F_1 ( V_48 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
if ( V_48 -> V_149 == * F_2 ( V_10 , V_2 ) ) return 0 ;
if ( V_48 -> V_149 > V_4 [ V_2 ] . V_5 . V_150 ) return - V_7 ;
if ( V_48 -> V_149 < V_4 [ V_2 ] . V_5 . V_151 ) return - V_7 ;
* F_2 ( V_10 , V_2 ) = V_48 -> V_149 ;
switch ( V_48 -> V_6 ) {
case V_152 :
case V_153 :
{
int V_154 , V_155 ;
F_17 ( V_10 , & V_154 , & V_155 ) ;
V_154 = ( V_154 >> 2 ) | ( ( V_154 & 3 ) << 8 ) ;
V_155 = ( V_155 >> 2 ) | ( ( V_155 & 3 ) << 8 ) ;
F_8 ( V_10 -> V_143 , 0x0e , V_154 ) ;
F_8 ( V_10 -> V_143 , 0x1e , V_155 ) ;
}
break;
case V_156 :
{
F_6 ( V_10 -> V_143 , 0x20 , V_48 -> V_149 ) ;
F_6 ( V_10 -> V_143 , 0x22 , V_48 -> V_149 ) ;
}
break;
case V_157 :
{
F_6 ( V_10 -> V_143 , 0x25 , V_48 -> V_149 ) ;
}
break;
case V_158 :
{
const struct V_82 * V_94 ;
V_94 = F_20 ( V_10 ) ;
F_6 ( V_10 -> V_143 , 0x83 , V_94 -> V_95 ) ;
F_6 ( V_10 -> V_143 , 0x84 , V_94 -> V_96 ) ;
F_6 ( V_10 -> V_143 , 0x85 , V_94 -> V_97 ) ;
F_6 ( V_10 -> V_143 , 0x86 , V_94 -> V_98 ) ;
F_6 ( V_10 -> V_143 , 0x87 , V_94 -> V_99 ) ;
F_6 ( V_10 -> V_143 , 0x88 , V_94 -> V_100 ) ;
F_6 ( V_10 -> V_143 , 0x89 , V_94 -> V_101 ) ;
F_6 ( V_10 -> V_143 , 0x8a , V_94 -> V_102 ) ;
F_6 ( V_10 -> V_143 , 0x8b , V_94 -> V_103 ) ;
}
break;
case V_159 :
{
unsigned char V_30
= F_3 ( V_10 -> V_143 , 0x8d ) ;
if ( V_48 -> V_149 ) V_30 |= 0x10 ;
else V_30 &= ~ 0x10 ;
F_6 ( V_10 -> V_143 , 0x8d , V_30 ) ;
}
break;
case V_160 :
{
F_6 ( V_10 -> V_143 , 0x93 , F_16 ( V_10 ) ) ;
}
break;
}
return 0 ;
}
static int F_33 ( struct V_9 * V_10 ,
struct V_148 * V_48 ) {
int V_2 ;
V_2 = F_1 ( V_48 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
V_48 -> V_149 = * F_2 ( V_10 , V_2 ) ;
return 0 ;
}
static int F_34 ( void * V_10 , struct V_115 * V_116 ) {
#define F_35 ((struct maven_data*)md)
#define V_90 (mdinfo->primary_head)
return F_26 ( V_10 , V_116 , & V_90 -> V_161 . V_162 ) ;
#undef V_90
#undef F_35
}
static int F_36 ( void * V_10 ) {
#define F_35 ((struct maven_data*)md)
#define V_90 (mdinfo->primary_head)
return F_29 ( V_10 , & V_90 -> V_161 . V_162 ) ;
#undef V_90
#undef F_35
}
static int F_37 ( void * V_10 ) {
return F_30 ( V_10 ) ;
}
static int F_38 ( void * V_10 , T_5 V_163 ) {
switch ( V_163 ) {
case V_86 :
case V_88 :
case V_119 :
return 0 ;
}
return - V_7 ;
}
static int F_39 ( void * V_10 , struct V_144 * V_48 ) {
return F_31 ( V_10 , V_48 ) ;
}
static int F_40 ( void * V_10 , struct V_148 * V_48 ) {
return F_33 ( V_10 , V_48 ) ;
}
static int F_41 ( void * V_10 , struct V_148 * V_48 ) {
return F_32 ( V_10 , V_48 ) ;
}
static int F_42 ( struct V_14 * V_164 ) {
struct V_9 * V_10 = F_43 ( V_164 ) ;
struct V_89 * V_90 = F_44 ( V_164 -> V_28 ,
struct V_165 ,
V_28 ) -> V_90 ;
V_10 -> V_12 = V_90 ;
V_10 -> V_143 = V_164 ;
F_45 ( & V_90 -> V_72 . V_166 ) ;
V_90 -> V_91 [ 1 ] . V_167 = & V_168 ;
V_90 -> V_91 [ 1 ] . V_169 = V_90 -> V_91 [ 1 ] . V_170 ;
V_90 -> V_91 [ 1 ] . V_84 = V_10 ;
V_90 -> V_91 [ 1 ] . V_92 = V_119 ;
F_46 ( & V_90 -> V_72 . V_166 ) ;
if ( F_3 ( V_164 , 0xB2 ) < 0x14 ) {
V_10 -> V_70 = V_71 ;
} else {
V_10 -> V_70 = V_171 ;
}
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 ) {
* F_2 ( V_10 , V_2 ) = V_4 [ V_2 ] . V_5 . V_172 ;
}
}
return 0 ;
}
static int F_47 ( struct V_14 * V_164 ) {
struct V_9 * V_10 = F_43 ( V_164 ) ;
if ( V_10 -> V_12 ) {
struct V_89 * V_90 = V_10 -> V_12 ;
F_45 ( & V_90 -> V_72 . V_166 ) ;
V_90 -> V_91 [ 1 ] . V_169 = V_173 ;
V_90 -> V_91 [ 1 ] . V_167 = NULL ;
V_90 -> V_91 [ 1 ] . V_84 = NULL ;
V_90 -> V_91 [ 1 ] . V_92 = V_119 ;
F_46 ( & V_90 -> V_72 . V_166 ) ;
V_10 -> V_12 = NULL ;
}
return 0 ;
}
static int F_48 ( struct V_14 * V_143 ,
const struct V_174 * V_6 )
{
struct V_175 * V_28 = V_143 -> V_28 ;
int V_27 = - V_176 ;
struct V_9 * V_84 ;
if ( ! F_49 ( V_28 , V_177 |
V_178 |
V_179 |
V_180 ) )
goto V_181;
if ( ! ( V_84 = F_50 ( sizeof( * V_84 ) , V_182 ) ) ) {
V_27 = - V_183 ;
goto V_181;
}
F_51 ( V_143 , V_84 ) ;
V_27 = F_42 ( V_143 ) ;
if ( V_27 )
goto V_184;
return 0 ;
V_184: ;
F_52 ( V_84 ) ;
V_181: ;
return V_27 ;
}
static int F_53 ( struct V_14 * V_143 )
{
F_47 ( V_143 ) ;
F_52 ( F_43 ( V_143 ) ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_185 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_185 ) ;
}
