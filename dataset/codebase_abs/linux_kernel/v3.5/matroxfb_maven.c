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
struct V_18 V_19 [] = { { V_15 -> V_20 , V_21 , sizeof( V_16 ) , & V_16 } ,
{ V_15 -> V_20 , V_22 | V_23 , sizeof( V_17 ) , & V_17 } } ;
T_2 V_24 ;
V_24 = F_4 ( V_15 -> V_25 , V_19 , 2 ) ;
if ( V_24 < 0 )
F_5 ( V_26 L_1 , V_16 ) ;
return V_17 & 0xFF ;
}
static int F_6 ( struct V_14 * V_15 , int V_16 , int V_27 ) {
T_2 V_24 ;
V_24 = F_7 ( V_15 , V_16 , V_27 ) ;
if ( V_24 )
F_5 ( V_26 L_2 , V_16 ) ;
return V_24 ;
}
static int F_8 ( struct V_14 * V_15 , int V_16 , int V_27 ) {
T_2 V_24 ;
V_24 = F_9 ( V_15 , V_16 , V_27 ) ;
if ( V_24 )
F_5 ( V_26 L_3 , V_16 ) ;
return V_24 ;
}
static int F_10 ( const struct V_28 * V_29 ,
const struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 ,
unsigned int * V_34 , unsigned int * V_35 , unsigned int * V_36 ,
unsigned int * V_37 ) {
unsigned int V_38 = 0 ;
unsigned int V_39 = V_31 -> V_40 ;
unsigned int V_41 = V_29 -> V_42 / V_31 -> V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
F_11 (__func__)
V_46 = V_32 * ( V_33 - 1 ) ;
V_44 = V_32 * V_33 ;
V_47 = V_29 -> V_48 / V_31 -> V_43 ;
F_12 ( V_49 L_4 ,
V_44 , V_39 , V_32 , V_33 , V_47 ) ;
for ( V_45 = 1 ; V_45 <= V_29 -> V_50 ; V_45 ++ ) {
if ( V_44 * 2 > V_47 )
break;
V_44 *= 2 ;
}
if ( V_44 > V_47 )
return 0 ;
for (; V_45 -- > 0 ; V_44 >>= 1 ) {
unsigned int V_51 ;
if ( V_44 < V_41 ) break;
for ( V_51 = V_29 -> V_52 ; V_51 <= V_29 -> V_53 ; V_51 ++ ) {
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_56 ;
V_54 = ( V_44 * V_51 ) / V_39 ;
if ( V_54 < V_29 -> V_57 )
continue;
if ( V_54 > V_29 -> V_58 )
break;
V_56 = V_39 * V_54 ;
V_55 = V_51 << V_45 ;
if ( V_56 % V_55 )
continue;
V_56 = V_56 / V_55 ;
if ( V_56 < V_46 + 2 )
continue;
V_56 = V_56 - V_46 ;
if ( V_56 > V_32 )
continue;
F_12 ( V_49 L_5 , V_54 , V_51 , V_45 , V_56 ) ;
if ( V_56 > V_38 ) {
F_12 ( V_49 L_6 ) ;
* V_37 = V_38 = V_56 ;
* V_36 = V_45 ;
* V_34 = V_51 ;
* V_35 = V_54 ;
}
}
}
if ( V_38 < 2 )
return 0 ;
F_12 ( V_59 L_7 , * V_34 , * V_35 , * V_36 , V_39 , V_44 ) ;
return V_39 * ( * V_35 ) / ( * V_34 ) * V_31 -> V_43 ;
}
static int F_13 ( const struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 ,
unsigned int * V_34 , unsigned int * V_35 , unsigned int * V_36 ,
unsigned int * V_60 ) {
unsigned int V_61 ;
unsigned int V_62 ( V_45 ) ;
V_61 = F_10 ( & V_63 , V_31 , V_32 , V_33 , V_34 , V_35 , & V_45 , V_60 ) ;
if ( ! V_61 )
return - V_7 ;
V_45 = ( 1 << V_45 ) - 1 ;
if ( V_61 <= 100000000 )
;
else if ( V_61 <= 140000000 )
V_45 |= 0x08 ;
else if ( V_61 <= 180000000 )
V_45 |= 0x10 ;
else
V_45 |= 0x18 ;
* V_36 = V_45 ;
return 0 ;
}
static void F_14 ( unsigned int V_64 , unsigned int V_47 ,
unsigned int * V_34 , unsigned int * V_35 , unsigned int * V_36 ) {
unsigned int V_61 ;
unsigned int V_45 ;
V_61 = F_15 ( & V_65 , V_64 , V_47 , V_34 , V_35 , & V_45 ) ;
V_45 = ( 1 << V_45 ) - 1 ;
if ( V_61 <= 100000 )
;
else if ( V_61 <= 140000 )
V_45 |= 0x08 ;
else if ( V_61 <= 180000 )
V_45 |= 0x10 ;
else
V_45 |= 0x18 ;
* V_36 = V_45 ;
return;
}
static unsigned char F_16 ( const struct V_9 * V_10 ) {
unsigned char V_66 ;
V_66 = ( V_10 -> V_67 == V_68 ? 0x40 : 0x00 ) ;
switch ( V_10 -> V_12 -> V_69 . V_70 . V_71 ) {
case 0 :
break;
case 1 :
V_66 |= 0xB1 ;
break;
case 2 :
V_66 |= 0xA2 ;
break;
}
return V_66 ;
}
static void F_17 ( const struct V_9 * V_10 ,
int * V_72 , int * V_73 ) {
const int V_74 = V_10 -> V_12 -> V_69 . V_70 . V_75 + V_76 ;
const int V_15 = V_10 -> V_12 -> V_69 . V_70 . V_77 ;
* V_72 = F_18 ( V_74 - V_15 , V_76 ) ;
* V_73 = F_19 ( V_74 + V_15 , V_78 ) ;
}
static const struct V_79 * F_20 ( const struct V_9 * V_10 ) {
return V_79 + V_10 -> V_12 -> V_69 . V_70 . gamma ;
}
static void F_21 ( const struct V_9 * V_10 , struct V_80 * V_81 ) {
static struct V_80 V_82 = { {
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
} , V_83 , 625 , 50 } ;
static struct V_80 V_84 = { {
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
} , V_85 , 525 , 60 } ;
struct V_86 * V_87 = V_10 -> V_12 ;
if ( V_87 -> V_88 [ 1 ] . V_89 == V_83 )
* V_81 = V_82 ;
else
* V_81 = V_84 ;
V_81 -> V_90 [ 0x93 ] = F_16 ( V_10 ) ;
{
const struct V_79 * V_91 ;
V_91 = F_20 ( V_10 ) ;
V_81 -> V_90 [ 0x83 ] = V_91 -> V_92 ;
V_81 -> V_90 [ 0x84 ] = V_91 -> V_93 ;
V_81 -> V_90 [ 0x85 ] = V_91 -> V_94 ;
V_81 -> V_90 [ 0x86 ] = V_91 -> V_95 ;
V_81 -> V_90 [ 0x87 ] = V_91 -> V_96 ;
V_81 -> V_90 [ 0x88 ] = V_91 -> V_97 ;
V_81 -> V_90 [ 0x89 ] = V_91 -> V_98 ;
V_81 -> V_90 [ 0x8A ] = V_91 -> V_99 ;
V_81 -> V_90 [ 0x8B ] = V_91 -> V_100 ;
}
{
int V_72 , V_73 ;
F_17 ( V_10 , & V_72 , & V_73 ) ;
V_81 -> V_90 [ 0x0e ] = V_72 >> 2 ;
V_81 -> V_90 [ 0x0f ] = V_72 & 3 ;
V_81 -> V_90 [ 0x1e ] = V_73 >> 2 ;
V_81 -> V_90 [ 0x1f ] = V_73 & 3 ;
}
{
V_81 -> V_90 [ 0x20 ] =
V_81 -> V_90 [ 0x22 ] = V_87 -> V_69 . V_70 . V_101 ;
}
V_81 -> V_90 [ 0x25 ] = V_87 -> V_69 . V_70 . V_102 ;
return;
}
static void F_22 ( struct V_14 * V_15 , const struct V_80 * V_51 ) {
int V_27 ;
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
if ( V_51 -> V_89 == V_83 ) {
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
if ( V_51 -> V_89 == V_83 )
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
V_27 = F_3 ( V_15 , 0x8D ) ;
V_27 &= 0x14 ;
F_6 ( V_15 , 0x8D , V_27 ) ;
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
if ( V_51 -> V_89 == V_83 )
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
static int F_25 ( unsigned int V_103 , unsigned int V_104 ,
struct V_80 * V_51 ) {
unsigned int V_105 ;
unsigned int V_24 = ~ 0 ;
V_51 -> V_90 [ 0x80 ] = 0x0F ;
V_51 -> V_90 [ 0x81 ] = 0x07 ;
V_51 -> V_90 [ 0x82 ] = 0x81 ;
for ( V_105 = 0 ; V_105 < 8 ; V_105 ++ ) {
unsigned int V_15 ;
unsigned int V_62 ( V_106 ) , V_62 ( V_74 ) ,
V_62 ( V_37 ) ;
unsigned int V_107 = V_103 + 2 + V_105 ;
if ( ! F_13 ( ( V_51 -> V_89 == V_83 ) ? & V_108 : & V_109 , V_107 , V_104 , & V_106 , & V_74 , & V_15 , & V_37 ) ) {
unsigned int V_110 = V_107 - V_37 ;
if ( V_110 < V_24 ) {
V_24 = V_110 ;
V_51 -> V_90 [ 0x80 ] = V_106 - 1 ;
V_51 -> V_90 [ 0x81 ] = V_74 - 1 ;
V_51 -> V_90 [ 0x82 ] = V_15 | 0x80 ;
V_51 -> V_111 = V_37 - 2 ;
V_51 -> V_32 = V_107 - 2 ;
}
}
}
return V_24 != ~ 0U ;
}
static inline int F_26 ( struct V_9 * V_10 ,
struct V_112 * V_113 ,
struct V_80 * V_51 ) {
unsigned int V_114 ;
unsigned int V_106 , V_115 , V_15 ;
struct V_86 * V_87 = V_10 -> V_12 ;
V_51 -> V_89 = V_87 -> V_88 [ 1 ] . V_89 ;
if ( V_51 -> V_89 != V_116 ) {
unsigned int V_117 ;
unsigned int V_118 ;
unsigned int V_119 ;
unsigned int V_120 ;
unsigned int V_121 ;
F_21 ( V_10 , V_51 ) ;
if ( F_25 ( V_113 -> V_122 , V_113 -> V_123 , V_51 ) == 0 )
return - V_7 ;
V_117 = V_113 -> V_122 - V_113 -> V_124 ;
V_121 = V_113 -> V_124 - V_113 -> V_125 ;
V_120 = V_113 -> V_122 - V_121 - V_113 -> V_126 ;
V_118 = V_113 -> V_123 - V_113 -> V_127 ;
V_119 = V_113 -> V_127 - V_113 -> V_128 ;
if ( V_51 -> V_111 < V_113 -> V_122 )
V_120 += V_51 -> V_111 ;
if ( V_120 > V_113 -> V_122 )
V_120 -= V_113 -> V_122 ;
if ( V_120 + 2 > V_113 -> V_122 )
V_120 = 0 ;
V_51 -> V_90 [ 0x96 ] = V_51 -> V_111 ;
V_51 -> V_90 [ 0x97 ] = V_51 -> V_111 >> 8 ;
V_51 -> V_90 [ 0x98 ] = 0x00 ; V_51 -> V_90 [ 0x99 ] = 0x00 ;
V_51 -> V_90 [ 0x9A ] = V_117 ;
V_51 -> V_90 [ 0x9B ] = V_117 >> 8 ;
V_51 -> V_90 [ 0x9C ] = 0x04 ;
V_51 -> V_90 [ 0x9D ] = 0x00 ;
V_51 -> V_90 [ 0xA0 ] = V_51 -> V_32 ;
V_51 -> V_90 [ 0xA1 ] = V_51 -> V_32 >> 8 ;
V_51 -> V_90 [ 0xA2 ] = V_113 -> V_123 - V_113 -> V_128 - 1 ;
V_51 -> V_90 [ 0xA3 ] = ( V_113 -> V_123 - V_113 -> V_128 - 1 ) >> 8 ;
if ( V_10 -> V_67 == V_68 ) {
V_51 -> V_90 [ 0xA4 ] = 0x04 ;
V_51 -> V_90 [ 0xA5 ] = 0x00 ;
} else {
V_51 -> V_90 [ 0xA4 ] = 0x01 ;
V_51 -> V_90 [ 0xA5 ] = 0x00 ;
}
V_51 -> V_90 [ 0xA6 ] = 0x00 ;
V_51 -> V_90 [ 0xA7 ] = 0x00 ;
V_51 -> V_90 [ 0xA8 ] = V_113 -> V_123 - 1 ;
V_51 -> V_90 [ 0xA9 ] = ( V_113 -> V_123 - 1 ) >> 8 ;
V_51 -> V_90 [ 0xAA ] = V_120 ;
V_51 -> V_90 [ 0xAB ] = V_120 >> 8 ;
V_51 -> V_90 [ 0xAC ] = V_113 -> V_123 - 2 ;
V_51 -> V_90 [ 0xAD ] = ( V_113 -> V_123 - 2 ) >> 8 ;
V_51 -> V_90 [ 0xAE ] = 0x01 ;
V_51 -> V_90 [ 0xAF ] = 0x00 ;
{
int V_129 ;
int V_130 ;
unsigned int V_131 = 4 + V_117 + V_113 -> V_132 ;
unsigned int V_133 ;
int V_2 ;
if ( V_113 -> V_122 )
V_129 = 94208 / ( V_113 -> V_122 ) ;
else
V_129 = 0x81 ;
if ( V_129 > 0x81 )
V_129 = 0x81 ;
if ( V_129 < 0x41 )
V_129 = 0x41 ;
V_129 -- ;
V_130 = 98304 - 128 - ( ( V_117 + V_113 -> V_132 - 8 ) * V_129 ) ;
if ( V_130 < 0 )
V_130 = 0 ;
V_130 = V_130 >> 8 ;
if ( V_130 > 0xFF )
V_130 = 0xFF ;
V_2 = 1 ;
do {
V_133 = ( ( 0x3C0000 * V_2 - 0x8000 ) / V_129 + 0x05E7 ) >> 8 ;
V_2 ++ ;
} while ( V_133 < V_131 );
if ( V_133 >= V_51 -> V_32 + 2 ) {
V_133 = V_131 ;
}
V_51 -> V_90 [ 0x90 ] = V_129 ;
V_51 -> V_90 [ 0xC2 ] = V_130 ;
V_51 -> V_90 [ 0x9E ] = V_133 ;
V_51 -> V_90 [ 0x9F ] = V_133 >> 8 ;
}
{
int V_134 ;
int V_135 ;
#define F_27
if ( V_113 -> V_123 ) {
#ifdef F_27
T_3 V_136 ;
T_4 V_106 ;
T_4 V_74 ;
V_106 = V_51 -> V_137 * ( V_51 -> V_32 + 2 ) ;
V_74 = ( V_113 -> V_123 - 1 ) * ( V_51 -> V_32 + 2 ) + V_51 -> V_111 + 2 ;
V_136 = ( ( T_3 ) V_106 ) << 15 ;
F_28 ( V_136 , V_74 ) ;
V_134 = V_136 ;
#else
V_134 = V_51 -> V_137 * 32768 / V_113 -> V_123 ;
#endif
} else
V_134 = 0x8000 ;
if ( V_134 > 0x8000 )
V_134 = 0x8000 ;
V_135 = ( V_119 + V_118 + V_113 -> V_138 ) * V_134 ;
V_135 = ( V_135 >> 16 ) - 146 ;
if ( V_135 < 0 )
V_135 = 0 ;
if ( V_135 > 0xFF )
V_135 = 0xFF ;
V_134 -- ;
V_51 -> V_90 [ 0x91 ] = V_134 ;
V_51 -> V_90 [ 0x92 ] = V_134 >> 8 ;
V_51 -> V_90 [ 0xBE ] = V_135 ;
}
V_51 -> V_90 [ 0xB0 ] = 0x08 ;
return 0 ;
}
F_14 ( V_113 -> V_139 , 450000 , & V_106 , & V_115 , & V_15 ) ;
V_51 -> V_90 [ 0x80 ] = V_106 ;
V_51 -> V_90 [ 0x81 ] = V_115 ;
V_51 -> V_90 [ 0x82 ] = V_15 | 0x80 ;
V_51 -> V_90 [ 0xB3 ] = 0x01 ;
V_51 -> V_90 [ 0x94 ] = 0xB2 ;
V_51 -> V_90 [ 0x96 ] = V_113 -> V_122 ;
V_51 -> V_90 [ 0x97 ] = V_113 -> V_122 >> 8 ;
V_51 -> V_90 [ 0x98 ] = 0x00 ;
V_51 -> V_90 [ 0x99 ] = 0x00 ;
V_114 = V_113 -> V_124 - V_113 -> V_125 ;
V_51 -> V_90 [ 0x9A ] = V_114 ;
V_51 -> V_90 [ 0x9B ] = V_114 >> 8 ;
V_114 = V_113 -> V_122 - V_113 -> V_125 ;
V_51 -> V_90 [ 0x9C ] = V_114 ;
V_51 -> V_90 [ 0x9D ] = V_114 >> 8 ;
V_114 += V_113 -> V_132 ;
V_51 -> V_90 [ 0x9E ] = V_114 ;
V_51 -> V_90 [ 0x9F ] = V_114 >> 8 ;
V_114 = V_113 -> V_122 + 1 ;
V_51 -> V_90 [ 0xA0 ] = V_114 ;
V_51 -> V_90 [ 0xA1 ] = V_114 >> 8 ;
V_114 = V_113 -> V_127 - V_113 -> V_128 - 1 ;
V_51 -> V_90 [ 0xA2 ] = V_114 ;
V_51 -> V_90 [ 0xA3 ] = V_114 >> 8 ;
V_114 = V_113 -> V_123 - V_113 -> V_128 ;
V_51 -> V_90 [ 0xA4 ] = V_114 ;
V_51 -> V_90 [ 0xA5 ] = V_114 >> 8 ;
V_114 = V_113 -> V_123 - 1 ;
V_51 -> V_90 [ 0xA6 ] = V_114 ;
V_51 -> V_90 [ 0xA7 ] = V_114 >> 8 ;
V_51 -> V_90 [ 0xA8 ] = V_114 ;
V_51 -> V_90 [ 0xA9 ] = V_114 >> 8 ;
V_114 = V_113 -> V_122 - V_113 -> V_126 ;
V_51 -> V_90 [ 0xAA ] = V_114 ;
V_51 -> V_90 [ 0xAB ] = V_114 >> 8 ;
V_114 = V_113 -> V_123 - 2 ;
V_51 -> V_90 [ 0xAC ] = V_114 ;
V_51 -> V_90 [ 0xAD ] = V_114 >> 8 ;
V_51 -> V_90 [ 0xAE ] = 0x00 ;
V_51 -> V_90 [ 0xAF ] = 0x00 ;
V_51 -> V_90 [ 0xB0 ] = 0x03 ;
V_51 -> V_90 [ 0xB1 ] = 0xA0 ;
V_51 -> V_90 [ 0x8C ] = 0x20 ;
V_51 -> V_90 [ 0x8D ] = 0x04 ;
V_51 -> V_90 [ 0xB9 ] = 0x1A ;
V_51 -> V_90 [ 0xBF ] = 0x22 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
const struct V_80 * V_51 ) {
struct V_14 * V_15 = V_10 -> V_140 ;
if ( V_51 -> V_89 == V_116 ) {
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
F_22 ( V_15 , V_51 ) ;
}
return 0 ;
}
static inline int F_30 ( struct V_9 * V_10 ) {
struct V_14 * V_15 = V_10 -> V_140 ;
F_6 ( V_15 , 0x95 , 0x20 ) ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 ,
struct V_141 * V_45 ) {
int V_2 ;
V_2 = F_1 ( V_45 -> V_6 ) ;
if ( V_2 >= 0 ) {
* V_45 = V_4 [ V_2 ] . V_5 ;
return 0 ;
}
if ( V_2 == - V_8 ) {
static const struct V_141 V_142 =
{ . V_143 = V_144 } ;
V_2 = V_45 -> V_6 ;
* V_45 = V_142 ;
V_45 -> V_6 = V_2 ;
sprintf ( V_45 -> V_145 , L_8 , V_2 ) ;
return 0 ;
}
return - V_7 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_146 * V_45 ) {
int V_2 ;
V_2 = F_1 ( V_45 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
if ( V_45 -> V_147 == * F_2 ( V_10 , V_2 ) ) return 0 ;
if ( V_45 -> V_147 > V_4 [ V_2 ] . V_5 . V_148 ) return - V_7 ;
if ( V_45 -> V_147 < V_4 [ V_2 ] . V_5 . V_149 ) return - V_7 ;
* F_2 ( V_10 , V_2 ) = V_45 -> V_147 ;
switch ( V_45 -> V_6 ) {
case V_150 :
case V_151 :
{
int V_152 , V_153 ;
F_17 ( V_10 , & V_152 , & V_153 ) ;
V_152 = ( V_152 >> 2 ) | ( ( V_152 & 3 ) << 8 ) ;
V_153 = ( V_153 >> 2 ) | ( ( V_153 & 3 ) << 8 ) ;
F_8 ( V_10 -> V_140 , 0x0e , V_152 ) ;
F_8 ( V_10 -> V_140 , 0x1e , V_153 ) ;
}
break;
case V_154 :
{
F_6 ( V_10 -> V_140 , 0x20 , V_45 -> V_147 ) ;
F_6 ( V_10 -> V_140 , 0x22 , V_45 -> V_147 ) ;
}
break;
case V_155 :
{
F_6 ( V_10 -> V_140 , 0x25 , V_45 -> V_147 ) ;
}
break;
case V_156 :
{
const struct V_79 * V_91 ;
V_91 = F_20 ( V_10 ) ;
F_6 ( V_10 -> V_140 , 0x83 , V_91 -> V_92 ) ;
F_6 ( V_10 -> V_140 , 0x84 , V_91 -> V_93 ) ;
F_6 ( V_10 -> V_140 , 0x85 , V_91 -> V_94 ) ;
F_6 ( V_10 -> V_140 , 0x86 , V_91 -> V_95 ) ;
F_6 ( V_10 -> V_140 , 0x87 , V_91 -> V_96 ) ;
F_6 ( V_10 -> V_140 , 0x88 , V_91 -> V_97 ) ;
F_6 ( V_10 -> V_140 , 0x89 , V_91 -> V_98 ) ;
F_6 ( V_10 -> V_140 , 0x8a , V_91 -> V_99 ) ;
F_6 ( V_10 -> V_140 , 0x8b , V_91 -> V_100 ) ;
}
break;
case V_157 :
{
unsigned char V_27
= F_3 ( V_10 -> V_140 , 0x8d ) ;
if ( V_45 -> V_147 ) V_27 |= 0x10 ;
else V_27 &= ~ 0x10 ;
F_6 ( V_10 -> V_140 , 0x8d , V_27 ) ;
}
break;
case V_158 :
{
F_6 ( V_10 -> V_140 , 0x93 , F_16 ( V_10 ) ) ;
}
break;
}
return 0 ;
}
static int F_33 ( struct V_9 * V_10 ,
struct V_146 * V_45 ) {
int V_2 ;
V_2 = F_1 ( V_45 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
V_45 -> V_147 = * F_2 ( V_10 , V_2 ) ;
return 0 ;
}
static int F_34 ( void * V_10 , struct V_112 * V_113 ) {
#define F_35 ((struct maven_data*)md)
#define V_87 (mdinfo->primary_head)
return F_26 ( V_10 , V_113 , & V_87 -> V_159 . V_160 ) ;
#undef V_87
#undef F_35
}
static int F_36 ( void * V_10 ) {
#define F_35 ((struct maven_data*)md)
#define V_87 (mdinfo->primary_head)
return F_29 ( V_10 , & V_87 -> V_159 . V_160 ) ;
#undef V_87
#undef F_35
}
static int F_37 ( void * V_10 ) {
return F_30 ( V_10 ) ;
}
static int F_38 ( void * V_10 , T_5 V_161 ) {
switch ( V_161 ) {
case V_83 :
case V_85 :
case V_116 :
return 0 ;
}
return - V_7 ;
}
static int F_39 ( void * V_10 , struct V_141 * V_45 ) {
return F_31 ( V_10 , V_45 ) ;
}
static int F_40 ( void * V_10 , struct V_146 * V_45 ) {
return F_33 ( V_10 , V_45 ) ;
}
static int F_41 ( void * V_10 , struct V_146 * V_45 ) {
return F_32 ( V_10 , V_45 ) ;
}
static int F_42 ( struct V_14 * V_162 ) {
struct V_9 * V_10 = F_43 ( V_162 ) ;
struct V_86 * V_87 = F_44 ( V_162 -> V_25 ,
struct V_163 ,
V_25 ) -> V_87 ;
V_10 -> V_12 = V_87 ;
V_10 -> V_140 = V_162 ;
F_45 ( & V_87 -> V_69 . V_164 ) ;
V_87 -> V_88 [ 1 ] . V_165 = & V_166 ;
V_87 -> V_88 [ 1 ] . V_167 = V_87 -> V_88 [ 1 ] . V_168 ;
V_87 -> V_88 [ 1 ] . V_81 = V_10 ;
V_87 -> V_88 [ 1 ] . V_89 = V_116 ;
F_46 ( & V_87 -> V_69 . V_164 ) ;
if ( F_3 ( V_162 , 0xB2 ) < 0x14 ) {
V_10 -> V_67 = V_68 ;
} else {
V_10 -> V_67 = V_169 ;
}
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 ) {
* F_2 ( V_10 , V_2 ) = V_4 [ V_2 ] . V_5 . V_170 ;
}
}
return 0 ;
}
static int F_47 ( struct V_14 * V_162 ) {
struct V_9 * V_10 = F_43 ( V_162 ) ;
if ( V_10 -> V_12 ) {
struct V_86 * V_87 = V_10 -> V_12 ;
F_45 ( & V_87 -> V_69 . V_164 ) ;
V_87 -> V_88 [ 1 ] . V_167 = V_171 ;
V_87 -> V_88 [ 1 ] . V_165 = NULL ;
V_87 -> V_88 [ 1 ] . V_81 = NULL ;
V_87 -> V_88 [ 1 ] . V_89 = V_116 ;
F_46 ( & V_87 -> V_69 . V_164 ) ;
V_10 -> V_12 = NULL ;
}
return 0 ;
}
static int F_48 ( struct V_14 * V_140 ,
const struct V_172 * V_6 )
{
struct V_173 * V_25 = V_140 -> V_25 ;
int V_24 = - V_174 ;
struct V_9 * V_81 ;
if ( ! F_49 ( V_25 , V_175 |
V_176 |
V_177 |
V_178 ) )
goto V_179;
if ( ! ( V_81 = F_50 ( sizeof( * V_81 ) , V_180 ) ) ) {
V_24 = - V_181 ;
goto V_179;
}
F_51 ( V_140 , V_81 ) ;
V_24 = F_42 ( V_140 ) ;
if ( V_24 )
goto V_182;
return 0 ;
V_182: ;
F_52 ( V_81 ) ;
V_179: ;
return V_24 ;
}
static int F_53 ( struct V_14 * V_140 )
{
F_47 ( V_140 ) ;
F_52 ( F_43 ( V_140 ) ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_183 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_183 ) ;
}
