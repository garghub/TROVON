void
F_1 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 == V_4 )
return;
else if( V_2 -> V_3 >= V_5 )
F_2 ( V_2 -> V_6 , 0x2f , 0x01 ) ;
else
F_2 ( V_2 -> V_6 , 0x24 , 0x01 ) ;
}
static
void
F_3 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 == V_4 )
return;
else if( V_2 -> V_3 >= V_5 )
F_4 ( V_2 -> V_6 , 0x2F , 0xFE ) ;
else
F_4 ( V_2 -> V_6 , 0x24 , 0xFE ) ;
}
static void
F_5 ( struct V_1 * V_2 , unsigned short V_7 , unsigned short V_8 )
{
if( V_2 -> V_3 >= V_9 ) {
V_7 &= 0x0f ;
V_8 &= 0x0f ;
}
F_6 ( V_2 -> V_10 , 0x11 , V_7 , V_8 ) ;
}
static unsigned char *
F_7 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned char * V_13 = NULL ;
unsigned short V_14 = 0 , V_15 = 0 , V_16 = 0 ;
if( ( V_2 -> V_17 ) &&
( ( V_2 -> V_18 & V_19 ) || ( ! V_2 -> V_20 ) ) ) {
if( V_2 -> V_3 < V_9 ) V_15 = 0x3c ;
else V_15 = 0x7d ;
V_16 = ( F_8 ( V_2 -> V_21 , V_15 ) & 0x1f ) * 26 ;
if( V_16 < ( 8 * 26 ) ) {
V_13 = ( unsigned char * ) & V_22 [ V_16 ] ;
}
V_14 = F_9 ( 0x100 ) ;
if( V_14 ) {
V_14 += V_16 ;
V_13 = & V_11 [ V_14 ] ;
}
}
return V_13 ;
}
static unsigned short
F_10 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 = 0 ;
if( ( V_2 -> V_17 ) &&
( ( V_2 -> V_18 & V_19 ) || ( ! V_2 -> V_20 ) ) ) {
V_23 = F_9 ( 0x102 ) ;
V_23 += ( ( F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ) * V_2 -> V_24 ) ;
}
return V_23 ;
}
static bool
F_11 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_27 , unsigned short * V_28 )
{
unsigned short V_29 = 0 , V_30 , V_31 ;
V_30 = V_2 -> V_32 [ V_27 + ( * V_28 ) ] . V_33 ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_36 ) {
V_29 |= V_37 ;
if( V_2 -> V_3 >= V_5 ) {
V_29 |= V_38 ;
if( V_2 -> V_18 & V_39 ) {
V_29 |= V_40 ;
if( V_2 -> V_18 & V_41 ) {
V_29 |= V_42 ;
}
}
}
} else if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
V_29 |= V_45 ;
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_18 & V_34 ) {
if( ( V_2 -> V_46 & V_47 ) && ( V_2 -> V_46 & V_48 ) ) {
if( V_30 == 0x2e ) V_29 |= V_49 ;
}
}
}
} else if( V_2 -> V_35 & V_50 ) {
V_29 |= V_51 ;
} else if( V_2 -> V_35 & ( V_52 | V_53 | V_54 | V_55 ) ) {
V_29 |= V_56 ;
if( V_2 -> V_18 & V_39 ) {
V_29 |= V_57 ;
if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_59 ) {
V_29 |= V_60 ;
}
}
}
}
} else {
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_35 & V_62 ) {
V_29 |= V_63 ;
}
}
if( V_2 -> V_35 & V_43 ) {
V_29 |= V_45 ;
}
}
for(; V_2 -> V_32 [ V_27 + ( * V_28 ) ] . V_33 == V_30 ; ( * V_28 ) -- ) {
V_31 = V_2 -> V_32 [ V_27 + ( * V_28 ) ] . V_64 ;
if( V_31 & V_29 ) return true ;
if( ( * V_28 ) == 0 ) break;
}
for( ( * V_28 ) = 0 ; ; ( * V_28 ) ++ ) {
if( V_2 -> V_32 [ V_27 + ( * V_28 ) ] . V_33 != V_30 ) break;
V_31 = V_2 -> V_32 [ V_27 + ( * V_28 ) ] . V_64 ;
if( V_31 & V_29 ) return true ;
}
return false ;
}
unsigned short
F_12 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_27 , V_28 , V_65 ;
unsigned short V_66 , V_67 , V_68 , V_69 ;
static const unsigned short V_70 [] = {
0x00 , 0x00 , 0x01 , 0x01 ,
0x01 , 0x01 , 0x01 , 0x01 ,
0x01 , 0x01 , 0x01 , 0x01 ,
0x01 , 0x01 , 0x01 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00
} ;
if( V_25 == 0xfe ) return 0 ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
}
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_35 & V_62 ) {
if( V_66 & V_75 ) return 0 ;
}
}
if( V_25 < 0x14 ) return 0xFFFF ;
V_67 = ( F_8 ( V_2 -> V_21 , 0x33 ) >> V_2 -> V_76 ) & 0x0F ;
V_69 = V_67 ;
if( V_67 > 0 ) V_67 -- ;
if( V_2 -> V_77 & V_78 ) {
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_18 & V_79 ) V_67 = 0 ;
else if( V_2 -> V_46 & V_47 ) V_67 = V_69 = 0 ;
}
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_18 & V_79 ) ) {
V_68 = V_70 [ F_13 ( V_2 ) ] ;
if( V_67 > V_68 ) V_67 = V_68 ;
}
}
} else {
if( V_2 -> V_35 & ( V_43 | V_44 ) ) V_67 = 0 ;
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_35 & V_62 ) V_67 = 0 ;
}
}
}
V_27 = V_2 -> V_73 [ V_26 ] . V_80 ;
V_25 = V_2 -> V_32 [ V_27 ] . V_33 ;
if( V_2 -> V_3 >= V_5 ) {
if( ! ( V_2 -> V_35 & V_81 ) ) {
if( ( V_2 -> V_73 [ V_26 ] . V_82 == 0x105 ) ||
( V_2 -> V_73 [ V_26 ] . V_82 == 0x107 ) ) {
if( V_69 <= 1 ) V_27 ++ ;
}
}
}
V_28 = 0 ;
do {
if( V_2 -> V_32 [ V_27 + V_28 ] . V_33 != V_25 ) break;
V_68 = V_2 -> V_32 [ V_27 + V_28 ] . V_64 ;
V_68 &= V_83 ;
if( V_68 < V_2 -> V_84 ) break;
V_28 ++ ;
V_67 -- ;
} while( V_67 != 0xFFFF );
if( ! ( V_2 -> V_35 & V_36 ) ) {
if( V_2 -> V_35 & V_85 ) {
V_68 = V_2 -> V_32 [ V_27 + V_28 - 1 ] . V_64 ;
if( V_68 & V_86 ) V_28 ++ ;
}
}
V_28 -- ;
if( ( V_2 -> V_77 & V_78 ) && ( ! ( V_2 -> V_35 & V_87 ) ) ) {
V_65 = V_28 ;
if( ! ( F_11 ( V_2 , V_25 , V_26 , V_27 , & V_28 ) ) ) {
V_28 = V_65 ;
}
}
return ( V_27 + V_28 ) ;
}
static void
F_14 ( struct V_1 * V_2 , unsigned short V_25 )
{
unsigned short V_88 , V_89 ;
F_15 ( V_2 -> V_21 , 0x34 , V_25 ) ;
V_88 = ( V_2 -> V_35 & V_85 ) >> 8 ;
V_89 = ~ ( V_85 >> 8 ) ;
F_6 ( V_2 -> V_21 , 0x31 , V_89 , V_88 ) ;
}
static bool
F_16 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_68 , V_88 ;
if( V_2 -> V_90 ) {
if( ( V_11 [ 0x233 ] == 0x12 ) && ( V_11 [ 0x234 ] == 0x34 ) ) {
V_68 = 1 << ( ( F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ) & 0x0f ) ;
V_88 = F_9 ( 0x23b ) ;
if( V_88 & V_68 ) return true ;
}
}
return false ;
}
static bool
F_17 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_68 , V_88 ;
if( V_2 -> V_90 ) {
if( ( V_11 [ 0x233 ] == 0x12 ) && ( V_11 [ 0x234 ] == 0x34 ) ) {
V_68 = 1 << ( ( F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ) & 0x0f ) ;
V_88 = F_9 ( 0x23d ) ;
if( V_88 & V_68 ) return true ;
}
}
return false ;
}
void
F_18 ( struct V_1 * V_2 , unsigned int V_91 )
{
while ( V_91 -- > 0 )
F_8 ( V_2 -> V_10 , 0x05 ) ;
}
static void
F_19 ( struct V_1 * V_2 , unsigned short V_92 )
{
F_18 ( V_2 , V_92 * 36 ) ;
}
static void
F_20 ( struct V_1 * V_2 , unsigned short V_92 )
{
while( V_92 -- ) {
F_19 ( V_2 , 6623 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 , unsigned short V_92 )
{
while( V_92 -- ) {
F_19 ( V_2 , 66 ) ;
}
}
static void
F_22 ( struct V_1 * V_2 , unsigned short V_93 )
{
#if F_23 ( V_94 ) || F_23 ( V_95 )
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_96 , V_97 , V_98 = 0 ;
#endif
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
V_96 = F_8 ( V_2 -> V_21 , 0x36 ) ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_18 & V_99 ) V_96 &= 0xf7 ;
if( ! ( F_8 ( V_2 -> V_10 , 0x18 ) & 0x10 ) ) V_96 = 0x12 ;
}
V_97 = V_96 >> 4 ;
if( ( V_93 >= 2 ) && ( ( V_96 & 0x0f ) == 1 ) ) {
V_98 = 3 ;
} else {
if( V_93 >= 2 ) V_93 -= 2 ;
if( ! ( V_93 & 0x01 ) ) {
V_98 = V_2 -> V_100 [ V_97 ] . V_101 [ 0 ] ;
} else {
V_98 = V_2 -> V_100 [ V_97 ] . V_101 [ 1 ] ;
}
if( V_2 -> V_90 ) {
if( V_11 [ 0x220 ] & 0x40 ) {
if( ! ( V_93 & 0x01 ) ) V_98 = ( unsigned short ) V_11 [ 0x225 ] ;
else V_98 = ( unsigned short ) V_11 [ 0x226 ] ;
}
}
}
F_21 ( V_2 , V_98 ) ;
#endif
} else {
#ifdef V_95
if( ( V_2 -> V_3 >= V_9 ) ||
( V_2 -> V_3 <= V_102 ) ||
( V_2 -> V_3 == V_103 ) ||
( V_2 -> V_17 ) ) {
if( ! ( V_93 & 0x01 ) ) {
F_18 ( V_2 , 0x1000 ) ;
} else {
F_18 ( V_2 , 0x4000 ) ;
}
} else if( ( V_2 -> V_104 == 1 ) ) {
if( V_2 -> V_61 == 0 ) {
V_96 = F_8 ( V_2 -> V_21 , 0x36 ) ;
if( V_2 -> V_105 == V_106 ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x1b ) & 0x10 ) ) V_96 = 0x12 ;
}
if( V_2 -> V_105 == V_107 ) {
V_97 = V_96 & 0x0f ;
} else {
V_97 = V_96 >> 4 ;
}
if( ( V_93 >= 2 ) && ( ( V_96 & 0x0f ) == 1 ) ) {
V_98 = 3 ;
} else {
if( V_93 >= 2 ) V_93 -= 2 ;
if( ! ( V_93 & 0x01 ) ) {
V_98 = V_2 -> V_108 [ V_97 ] . V_101 [ 0 ] ;
} else {
V_98 = V_2 -> V_108 [ V_97 ] . V_101 [ 1 ] ;
}
if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
if( V_11 [ 0x13c ] & 0x40 ) {
if( ! ( V_93 & 0x01 ) ) {
V_98 = ( unsigned short ) V_11 [ 0x17e ] ;
} else {
V_98 = ( unsigned short ) V_11 [ 0x17f ] ;
}
}
}
}
F_21 ( V_2 , V_98 ) ;
}
} else if( V_2 -> V_18 & V_34 ) {
V_97 = F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ;
if( ! ( V_93 & 0x01 ) ) {
V_98 = V_2 -> V_100 [ V_97 ] . V_101 [ 0 ] ;
} else {
V_98 = V_2 -> V_100 [ V_97 ] . V_101 [ 1 ] ;
}
V_98 <<= 8 ;
F_18 ( V_2 , V_98 ) ;
}
#endif
}
}
static void
F_24 ( struct V_1 * V_2 , unsigned short V_93 , unsigned short V_109 )
{
int V_28 ;
for( V_28 = 0 ; V_28 < V_109 ; V_28 ++ ) {
F_22 ( V_2 , V_93 ) ;
}
}
void
F_25 ( struct V_1 * V_2 )
{
unsigned short V_110 ;
if( F_8 ( V_2 -> V_10 , 0x1f ) & 0xc0 ) return;
if( ! ( F_8 ( V_2 -> V_21 , 0x17 ) & 0x80 ) ) return;
V_110 = 65535 ;
while( ( F_26 ( V_2 -> V_111 ) & 0x08 ) && -- V_110 ) ;
V_110 = 65535 ;
while( ( ! ( F_26 ( V_2 -> V_111 ) & 0x08 ) ) && -- V_110 ) ;
}
static void
F_27 ( struct V_1 * V_2 , unsigned short V_15 )
{
unsigned short V_110 ;
V_110 = 65535 ;
while( ( F_8 ( V_2 -> V_6 , V_15 ) & 0x02 ) && -- V_110 ) ;
V_110 = 65535 ;
while( ( ! ( F_8 ( V_2 -> V_6 , V_15 ) & 0x02 ) ) && -- V_110 ) ;
}
static void
F_28 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( V_2 -> V_18 & V_39 ) {
if( ! ( F_8 ( V_2 -> V_6 , 0x00 ) & 0x20 ) ) return;
}
if( ! ( F_8 ( V_2 -> V_6 , 0x00 ) & 0x80 ) ) {
F_25 ( V_2 ) ;
} else {
F_27 ( V_2 , 0x25 ) ;
}
#endif
} else {
#ifdef V_95
if( ! ( F_8 ( V_2 -> V_6 , 0x00 ) & 0x40 ) ) {
F_25 ( V_2 ) ;
} else {
F_27 ( V_2 , 0x30 ) ;
}
#endif
}
}
static void
F_29 ( struct V_1 * V_2 )
{
unsigned short V_112 , V_68 , V_28 , V_113 ;
V_68 = 0 ;
for( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
for( V_113 = 0 ; V_113 < 100 ; V_113 ++ ) {
V_112 = F_26 ( V_2 -> V_111 ) ;
if( V_68 & 0x01 ) {
if( ( V_112 & 0x08 ) ) continue;
else break;
} else {
if( ! ( V_112 & 0x08 ) ) continue;
else break;
}
}
V_68 ^= 0x01 ;
}
}
static void
F_30 ( struct V_1 * V_2 )
{
if( V_2 -> V_35 & V_62 ) {
F_29 ( V_2 ) ;
} else {
F_25 ( V_2 ) ;
}
}
static bool
F_31 ( struct V_1 * V_2 )
{
if( F_8 ( V_2 -> V_114 , 0x01 ) >= 0xb0 ) return true ;
return false ;
}
static bool
F_32 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 == V_115 ) {
if( F_8 ( V_2 -> V_10 , 0x13 ) & 0x20 ) return true ;
}
if( F_8 ( V_2 -> V_21 , 0x30 ) & 0x20 ) return true ;
return false ;
}
bool
F_33 ( struct V_1 * V_2 )
{
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( ( V_2 -> V_3 != V_116 ) || ( F_8 ( V_2 -> V_21 , 0x5f ) & 0xf0 ) ) {
if( F_8 ( V_2 -> V_21 , 0x38 ) & V_117 ) return true ;
}
}
#endif
return false ;
}
bool
F_34 ( struct V_1 * V_2 )
{
#ifdef V_95
unsigned short V_118 ;
if( V_2 -> V_3 >= V_5 ) {
V_118 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( ( V_118 & V_117 ) && ( V_118 & V_119 ) ) return true ;
}
#endif
return false ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
if( F_34 ( V_2 ) ) return true ;
if( F_32 ( V_2 ) ) return true ;
return false ;
}
static bool
F_36 ( struct V_1 * V_2 )
{
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( ( F_32 ( V_2 ) ) ||
( F_34 ( V_2 ) ) ) {
if( V_2 -> V_46 & V_120 ) return true ;
}
}
#endif
return false ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
if( ( F_8 ( V_2 -> V_121 , 0x00 ) & 0x0f ) != 0x0c ) return true ;
if( V_2 -> V_18 & V_122 ) {
if( F_8 ( V_2 -> V_121 , 0x4d ) & 0x10 ) return true ;
}
return false ;
}
static bool
F_38 ( struct V_1 * V_2 )
{
if( F_8 ( V_2 -> V_6 , 0x13 ) & 0x04 ) return true ;
return false ;
}
static bool
F_39 ( struct V_1 * V_2 )
{
if( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_3 < V_9 ) ) {
if( F_8 ( V_2 -> V_21 , 0x79 ) & 0x10 ) return true ;
}
return false ;
}
static bool
F_40 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
if( V_2 -> V_3 == V_116 ) {
V_118 = F_8 ( V_2 -> V_21 , 0x5f ) & 0xf0 ;
if( ( V_118 == 0xe0 ) || ( V_118 == 0xc0 ) ||
( V_118 == 0xb0 ) || ( V_118 == 0x90 ) ) return false ;
} else if( V_2 -> V_3 >= V_9 ) return false ;
return true ;
}
static bool
F_41 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 >= V_5 ) {
if( F_8 ( V_2 -> V_21 , 0x38 ) & V_123 ) return true ;
}
return false ;
}
static bool
F_42 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 >= V_5 ) {
if( F_8 ( V_2 -> V_21 , 0x38 ) & V_124 ) return true ;
}
return false ;
}
static bool
F_43 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
if( V_2 -> V_3 >= V_5 ) {
V_118 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( V_118 & V_62 ) return true ;
V_118 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( V_118 & V_123 ) return true ;
if( V_118 & V_124 ) return true ;
} else {
V_118 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( V_118 & V_62 ) return true ;
}
return false ;
}
static bool
F_44 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
if( V_2 -> V_3 >= V_5 ) {
V_118 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( V_118 & V_43 ) return true ;
V_118 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( V_118 & V_119 ) return true ;
} else {
V_118 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( V_118 & V_43 ) return true ;
}
return false ;
}
static bool
F_45 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
if( V_2 -> V_104 == 1 ) {
return true ;
} else if( V_2 -> V_18 & V_34 ) {
V_118 = F_8 ( V_2 -> V_114 , 0x00 ) ;
if( ( V_118 == 1 ) || ( V_118 == 2 ) ) return true ;
}
return false ;
}
static bool
F_46 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
if( F_45 ( V_2 ) ) {
V_118 = F_8 ( V_2 -> V_6 , 0x00 ) ;
if( V_2 -> V_3 < V_5 ) {
V_118 &= 0xa0 ;
if( ( V_118 == 0x80 ) || ( V_118 == 0x20 ) ) return true ;
} else {
V_118 &= 0x50 ;
if( ( V_118 == 0x40 ) || ( V_118 == 0x10 ) ) return true ;
}
}
return false ;
}
static bool
F_47 ( struct V_1 * V_2 )
{
unsigned short V_125 ;
V_125 = F_8 ( V_2 -> V_21 , 0x31 ) ;
if( V_125 & ( V_85 >> 8 ) ) return true ;
return false ;
}
void
F_48 ( struct V_1 * V_2 , unsigned short V_126 )
{
unsigned int V_127 ;
unsigned short V_68 ;
if( ! ( V_2 -> V_128 ) ) return;
V_127 = F_49 ( V_2 , 0x74 ) ;
V_127 &= 0xFFFF ;
if( ! V_127 ) return;
V_68 = F_50 ( ( V_127 + 0x3c ) ) ;
V_68 &= 0xFEFF ;
F_51 ( ( V_127 + 0x3c ) , V_68 ) ;
V_68 = F_50 ( ( V_127 + 0x3c ) ) ;
V_68 = F_50 ( ( V_127 + 0x3a ) ) ;
V_68 &= 0xFEFF ;
if( ! ( V_126 & V_62 ) ) V_68 |= 0x0100 ;
F_51 ( ( V_127 + 0x3a ) , V_68 ) ;
V_68 = F_50 ( ( V_127 + 0x3a ) ) ;
}
void
F_52 ( struct V_1 * V_2 , unsigned short V_25 ,
unsigned short V_26 , int V_129 )
{
unsigned short V_130 , V_131 , V_68 ;
unsigned short V_66 , V_132 = 0 ;
V_2 -> V_77 = 0 ;
V_66 = F_53 ( V_2 , V_25 , V_26 ) ;
V_2 -> V_84 = V_66 & V_83 ;
if( ( V_25 > 0x13 ) && ( ! V_2 -> V_133 ) ) {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
V_131 = 0 ;
if( F_45 ( V_2 ) ) {
V_68 = F_8 ( V_2 -> V_21 , 0x30 ) ;
V_131 |= V_68 ;
V_130 = F_8 ( V_2 -> V_21 , 0x31 ) << 8 ;
V_130 &= ( V_81 | V_135 | V_136 | V_137 ) ;
V_131 |= V_130 ;
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_18 & V_138 ) {
if( V_25 == 0x03 ) {
F_4 ( V_2 -> V_21 , 0x31 , 0xbf ) ;
}
if( ! ( F_8 ( V_2 -> V_21 , 0x31 ) & ( V_81 >> 8 ) ) ) {
F_4 ( V_2 -> V_21 , 0x38 , 0xfc ) ;
}
if( V_139 ) {
if( V_2 -> V_140 ) {
if( F_8 ( V_2 -> V_21 , 0x5f ) & 0xF0 ) {
if( ( V_25 <= 0x13 ) || ( ! ( F_8 ( V_2 -> V_21 , 0x31 ) & ( V_81 >> 8 ) ) ) ) {
F_2 ( V_2 -> V_21 , 0x38 , ( V_117 | V_119 ) ) ;
}
}
}
}
V_68 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( ( V_68 & ( V_117 | V_119 ) ) == ( V_117 | V_119 ) ) {
V_131 |= V_44 ;
}
}
if( V_2 -> V_3 >= V_9 ) {
V_131 &= ~ ( V_52 | V_50 ) ;
if( F_8 ( V_2 -> V_21 , 0x38 ) & 0x04 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x35 ) & 0xe0 ;
if( V_68 == 0x60 ) V_131 |= V_50 ;
else if( V_2 -> V_18 & V_122 ) {
V_131 |= V_52 ;
}
}
}
if( V_2 -> V_104 == 1 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( V_68 & V_119 ) {
V_131 |= V_44 ;
}
if( V_2 -> V_61 != 0 ) {
if( V_68 & V_123 ) {
V_131 |= V_141 ;
}
}
}
}
#endif
if( ! ( V_2 -> V_18 & V_142 ) ) {
V_131 &= ~ ( V_36 ) ;
}
if( V_2 -> V_18 & V_34 ) {
V_68 = V_54 |
V_53 |
V_55 |
V_44 |
V_43 |
V_36 |
V_50 |
V_52 ;
} else {
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_61 != 0 ) {
V_68 = V_53 |
V_54 |
V_55 |
V_44 |
V_43 |
V_141 ;
} else {
V_68 = V_44 |
V_43 ;
}
} else {
if( V_2 -> V_61 != 0 ) {
V_68 = V_62 | V_43 ;
} else {
V_68 = V_43 ;
}
}
}
if( ! ( V_131 & V_68 ) ) {
V_130 = V_87 ;
V_131 = 0 ;
}
if( V_2 -> V_18 & V_34 ) {
unsigned short V_143 = ( V_81 |
V_87 |
V_135 |
V_136 |
V_85 |
V_137 |
V_144 |
V_145 ) ;
if( V_131 & V_44 ) V_131 &= ( V_143 | V_44 ) ;
if( V_131 & V_36 ) V_131 &= ( V_143 | V_36 ) ;
if( V_131 & V_43 ) V_131 &= ( V_143 | V_43 ) ;
if( V_131 & V_55 ) V_131 &= ( V_143 | V_55 ) ;
if( V_131 & V_50 ) V_131 &= ( V_143 | V_50 ) ;
if( V_131 & V_52 ) V_131 &= ( V_143 | V_52 ) ;
} else {
if( V_2 -> V_3 >= V_5 ) {
if( V_131 & V_44 ) {
V_131 &= ( 0xFF00 | V_144 | V_145 ) ;
}
}
if( V_2 -> V_61 != 0 ) {
if( V_131 & V_62 ) {
V_131 &= ( 0xFF00 | V_62 | V_144 | V_145 ) ;
}
}
if( V_131 & V_43 ) {
V_131 &= ( 0xFF00 | V_43 | V_144 | V_145 ) ;
}
if( V_2 -> V_3 >= V_5 ) {
if( V_131 & V_44 ) {
V_131 |= V_43 ;
}
}
}
if( V_130 & V_87 ) {
if( ! ( V_131 & ( V_144 | V_145 ) ) ) {
V_131 = V_145 | V_87 ;
}
}
if( ! ( V_131 & V_81 ) ) V_131 |= V_145 ;
if( V_2 -> V_84 <= V_146 ) {
if( ( V_2 -> V_104 == 1 ) ||
( ( V_2 -> V_18 & V_79 ) && ( V_131 & V_43 ) ) ) {
V_66 &= ( ~ V_147 ) ;
}
}
if( ! ( V_131 & V_145 ) ) {
if( V_131 & V_144 ) {
if( ( ! ( V_66 & V_147 ) ) && ( V_129 ) ) {
if( V_132 != V_148 ) {
V_131 |= V_145 ;
}
}
} else {
if( F_46 ( V_2 ) ) {
if( ! ( V_131 & V_81 ) ) {
if( F_47 ( V_2 ) ) {
V_131 |= V_145 ;
}
}
}
}
}
if( ! ( V_131 & V_87 ) ) {
if( V_131 & V_81 ) {
if( V_131 & V_145 ) {
if( ( ! ( V_66 & V_147 ) ) && ( V_129 ) ) {
if( V_132 != V_148 ) {
V_131 |= V_85 ;
}
}
}
} else {
V_131 |= V_85 ;
}
}
}
V_2 -> V_35 = V_131 ;
#ifdef V_94
if( V_2 -> V_3 == V_149 ) {
F_48 ( V_2 , V_2 -> V_35 ) ;
}
#endif
#if 0
printk(KERN_DEBUG "sisfb: (init301: VBInfo= 0x%04x, SetFlag=0x%04x)\n",
SiS_Pr->SiS_VBInfo, SiS_Pr->SiS_SetFlag);
#endif
}
void
F_54 ( struct V_1 * V_2 )
{
unsigned char V_68 ;
V_2 -> V_150 = 0 ;
if( V_2 -> V_3 >= V_9 ) return;
if( V_2 -> V_18 ) {
if( V_2 -> V_35 & V_50 ) {
V_2 -> V_150 = V_151 ;
}
}
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_18 & V_122 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( V_68 & 0x08 ) {
switch( ( V_68 >> 4 ) ) {
case 0x00 : V_2 -> V_150 = V_152 ; break;
case 0x01 : V_2 -> V_150 = V_153 ; break;
case 0x02 : V_2 -> V_150 = V_154 ; break;
case 0x03 : V_2 -> V_150 = V_151 ; break;
}
}
}
}
}
void
F_55 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_68 , V_88 , V_132 = 0 , V_14 = 0 ;
unsigned char V_155 = * V_2 -> V_156 ;
V_2 -> V_58 = 0 ;
if( ! ( V_2 -> V_35 & V_62 ) ) return;
if( V_2 -> V_133 ) return;
if( V_25 > 0x13 ) {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
if( V_2 -> V_3 < V_9 ) {
if( V_2 -> V_35 & V_137 ) V_2 -> V_58 |= V_157 ;
if( V_2 -> V_18 & V_34 ) {
V_68 = 0 ;
if( ( V_2 -> V_3 == V_149 ) ||
( V_2 -> V_3 == V_115 ) ) {
V_68 = 0x35 ;
V_14 = 0xfe ;
} else if( V_2 -> V_3 >= V_5 ) {
V_68 = 0x38 ;
if( V_2 -> V_3 < V_4 ) {
V_14 = 0xf3 ;
if( V_2 -> V_3 >= V_103 ) V_14 = 0x11b ;
}
}
if( V_68 ) {
if( V_14 && V_2 -> V_90 && ( ! ( V_2 -> V_17 ) ) ) {
V_155 = V_11 [ V_14 ] ;
if( ! ( V_155 & V_158 ) ) {
F_4 ( V_2 -> V_21 , V_68 , 0x3F ) ;
}
}
V_88 = F_8 ( V_2 -> V_21 , V_68 ) ;
if( V_2 -> V_58 & V_157 ) {
if( V_88 & V_159 ) {
V_2 -> V_58 |= V_160 ;
V_2 -> V_58 &= ~ V_157 ;
} else if( V_88 & V_161 ) {
V_2 -> V_58 |= V_162 ;
}
} else {
if( V_88 & V_163 ) {
V_2 -> V_58 |= V_164 ;
}
}
}
if( V_2 -> V_35 & V_50 ) {
if( V_2 -> V_150 == V_154 ) V_2 -> V_58 |= V_59 ;
else if( V_2 -> V_150 == V_153 ) V_2 -> V_58 |= V_165 ;
else if( V_2 -> V_150 == V_151 ) V_2 -> V_58 |= V_166 ;
else V_2 -> V_58 |= V_167 ;
if( V_2 -> V_58 & ( V_59 | V_165 | V_167 ) ) {
V_2 -> V_35 &= ~ V_50 ;
V_2 -> V_35 |= V_52 ;
} else if( V_2 -> V_58 & V_166 ) {
V_2 -> V_58 |= V_157 ;
}
}
} else if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_168 ) {
if( V_2 -> V_61 == 1 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x35 ) ;
if( ( V_68 & V_169 ) || ( V_2 -> V_168 == 1 ) ) {
V_2 -> V_58 |= V_170 ;
}
} else if( V_2 -> V_61 == 2 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x79 ) ;
if( ( V_68 & 0x80 ) || ( V_2 -> V_168 == 1 ) ) {
V_2 -> V_58 |= V_170 ;
}
}
if( V_2 -> V_171 ) {
V_2 -> V_58 |= V_170 ;
}
}
if( V_2 -> V_61 == 2 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x38 ) ;
if( V_2 -> V_58 & V_157 ) {
if( V_68 & V_159 ) V_2 -> V_58 |= V_160 ;
else if( V_68 & V_161 ) V_2 -> V_58 |= V_162 ;
} else {
if( V_68 & V_163 ) {
V_2 -> V_58 |= V_164 ;
}
}
}
}
} else {
V_88 = F_8 ( V_2 -> V_21 , 0x35 ) ;
if( V_88 & 0x01 ) {
V_2 -> V_58 |= V_157 ;
if( V_88 & 0x08 ) {
V_2 -> V_58 |= V_162 ;
} else if( V_88 & 0x04 ) {
if( V_2 -> V_18 & V_34 ) {
V_2 -> V_58 &= ~ V_157 ;
}
V_2 -> V_58 |= V_160 ;
}
} else {
if( V_88 & 0x02 ) {
V_2 -> V_58 |= V_164 ;
}
}
if( V_2 -> V_61 == 2 ) {
if( V_2 -> V_168 ) {
if( ( V_88 & 0x10 ) || ( V_2 -> V_168 == 1 ) ) {
V_2 -> V_58 |= V_170 ;
}
}
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_52 ) {
V_88 &= 0xe0 ;
if( V_88 == 0x00 ) V_2 -> V_58 |= V_167 ;
else if( V_88 == 0x20 ) V_2 -> V_58 |= V_165 ;
else if( V_88 == 0x40 ) V_2 -> V_58 |= V_59 ;
} else if( V_2 -> V_35 & V_50 ) {
V_2 -> V_58 |= ( V_166 | V_157 ) ;
}
if( V_2 -> V_35 & ( V_52 | V_50 ) ) {
if( V_132 == V_172 || V_132 == V_173 || V_132 == V_174 ) {
V_2 -> V_58 |= V_175 ;
} else {
V_88 = F_8 ( V_2 -> V_21 , 0x39 ) ;
if( V_88 & 0x02 ) {
if( V_2 -> V_58 & ( V_59 | V_166 ) ) {
V_2 -> V_58 |= V_175 ;
} else {
V_2 -> V_58 |= V_176 ;
}
} else {
V_2 -> V_58 |= V_177 ;
}
}
}
}
}
if( V_2 -> V_35 & V_55 ) V_2 -> V_58 |= V_157 ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_50 ) {
V_2 -> V_58 |= V_157 ;
V_2 -> V_58 &= ~ ( V_160 | V_162 | V_164 ) ;
} else if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & ( V_167 | V_165 | V_59 ) ) {
V_2 -> V_58 &= ~ ( V_157 | V_164 | V_160 | V_162 ) ;
}
}
if( V_2 -> V_35 & V_85 ) {
if( ! ( V_2 -> V_35 & V_136 ) ) {
V_2 -> V_58 |= V_178 ;
}
}
if( ! ( V_2 -> V_58 & V_157 ) ) {
if( V_132 == V_179 ) {
if( V_2 -> V_58 & V_165 ) {
V_2 -> V_58 |= V_180 ;
} else if( ! ( V_2 -> V_58 & ( V_166 | V_59 ) ) ) {
V_2 -> V_58 |= V_181 ;
}
}
}
V_2 -> V_58 |= V_182 ;
if( ( V_2 -> V_35 & V_50 ) &&
( V_2 -> V_35 & V_85 ) ) {
V_2 -> V_58 &= ~ V_182 ;
} else if( V_2 -> V_58 & ( V_165 | V_59 ) ) {
V_2 -> V_58 &= ~ V_182 ;
} else if( ! ( V_2 -> V_18 & V_39 ) ) {
if( V_2 -> V_58 & V_178 ) {
V_2 -> V_58 &= ~ V_182 ;
}
}
}
V_2 -> V_35 &= ~ V_137 ;
}
static unsigned short
F_13 ( struct V_1 * V_2 )
{
unsigned short V_68 = V_2 -> V_183 ;
switch( V_68 ) {
case V_184 : V_68 = V_185 ; break;
case V_186 : V_68 = V_187 ; break;
case V_188 : V_68 = V_189 ; break;
}
return V_68 ;
}
static void
F_56 ( struct V_1 * V_2 )
{
#ifdef V_95
unsigned char * V_11 ;
unsigned short V_68 ;
if( ( V_11 = F_7 ( V_2 ) ) ) {
if( ( V_68 = F_9 ( 6 ) ) != V_2 -> V_190 ) {
V_2 -> V_191 = true ;
V_2 -> V_190 = V_68 ;
}
if( ( V_68 = F_9 ( 8 ) ) != V_2 -> V_192 ) {
V_2 -> V_191 = true ;
V_2 -> V_192 = V_68 ;
}
V_2 -> V_193 = F_9 ( 10 ) ;
V_2 -> V_194 = F_9 ( 12 ) ;
V_2 -> V_195 = F_9 ( 14 ) ;
V_2 -> V_196 = F_9 ( 16 ) ;
V_2 -> V_197 = V_198 ;
V_2 -> V_199 [ V_198 ] . CLOCK =
V_2 -> V_200 [ V_198 ] . CLOCK = ( unsigned short ) ( ( unsigned char ) V_11 [ 18 ] ) ;
V_2 -> V_199 [ V_198 ] . V_201 =
V_2 -> V_200 [ V_198 ] . V_202 = V_11 [ 19 ] ;
V_2 -> V_199 [ V_198 ] . V_203 =
V_2 -> V_200 [ V_198 ] . V_204 = V_11 [ 20 ] ;
}
#endif
}
static void
F_57 ( struct V_1 * V_2 , unsigned short V_132 ,
const unsigned char * V_205 )
{
int V_28 = 0 ;
while( V_205 [ V_28 ] != 0xff ) {
if( V_205 [ V_28 ++ ] == V_132 ) {
if( ( V_2 -> V_35 & V_43 ) ||
( V_2 -> V_206 == - 1 ) ) {
V_2 -> V_46 |= V_47 ;
}
break;
}
}
}
void
F_58 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_68 , V_66 , V_132 = 0 , V_207 = 0 , V_208 = 0 ;
bool V_209 = false ;
#ifdef V_94
unsigned char * V_11 = V_2 -> V_12 ;
static const unsigned char V_210 [] =
{ 0 , 1 , 2 , 3 , 7 , 4 , 5 , 8 ,
0 , 0 , 10 , 0 , 0 , 0 , 0 , 15 } ;
#endif
#ifdef V_95
unsigned char * V_13 = NULL ;
#endif
V_2 -> V_183 = 0 ;
V_2 -> V_211 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_193 = 999 ;
V_2 -> V_194 = 999 ;
V_2 -> V_195 = 999 ;
V_2 -> V_196 = 999 ;
V_2 -> V_191 = false ;
V_2 -> V_212 = false ;
if( ! ( V_2 -> V_35 & ( V_43 | V_44 ) ) ) return;
V_66 = F_53 ( V_2 , V_25 , V_26 ) ;
if( ( V_25 > 0x13 ) && ( ! V_2 -> V_133 ) ) {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
V_207 = V_2 -> V_213 [ V_132 ] . V_214 ;
V_208 = V_2 -> V_213 [ V_132 ] . V_215 ;
}
V_68 = F_8 ( V_2 -> V_21 , 0x36 ) ;
if( V_68 == 0 ) V_68 = 0x02 ;
if( ( V_2 -> V_3 >= V_9 ) || ( V_2 -> V_17 ) ) {
V_2 -> V_211 = ( F_8 ( V_2 -> V_21 , 0x39 ) & 0x7c ) >> 2 ;
} else if( ( V_2 -> V_3 < V_5 ) || ( V_2 -> V_3 >= V_9 ) ) {
V_2 -> V_211 = V_68 >> 4 ;
} else {
V_2 -> V_211 = ( V_68 & 0x0F ) - 1 ;
}
V_68 &= 0x0f ;
#ifdef V_94
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_18 & V_99 ) {
if( V_68 < 0x0f ) V_68 &= 0x07 ;
}
V_68 = V_210 [ V_68 ] ;
}
#endif
#ifdef V_95
if( V_2 -> V_3 == V_216 ) {
if ( V_68 == V_217 ) V_68 = V_218 ;
else if( V_68 == V_219 ) V_68 = V_218 ;
else if( V_68 == V_220 ) V_68 = V_221 ;
} else if( V_2 -> V_3 >= V_9 ) {
if( V_68 == V_189 ) V_68 = V_188 ;
}
#endif
if( V_2 -> V_18 & V_19 ) {
if( V_68 == V_222 ) {
V_68 = V_184 ;
}
if( V_2 -> V_17 ) {
if( V_68 == V_223 ) {
V_68 = V_186 ;
}
}
}
V_2 -> V_183 = V_68 ;
#ifdef V_94
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_105 == V_224 ) {
V_2 -> V_183 = V_225 ;
} else if( V_2 -> V_105 == V_226 ) {
V_2 -> V_183 = V_227 ;
} else if( V_2 -> V_105 == V_228 ) {
V_2 -> V_183 = V_229 ;
}
}
#endif
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_183 < V_2 -> V_230 )
V_2 -> V_183 = V_2 -> V_230 ;
} else {
if( V_2 -> V_183 < V_2 -> V_231 )
V_2 -> V_183 = V_2 -> V_231 ;
}
V_68 = F_8 ( V_2 -> V_21 , 0x37 ) ;
V_2 -> V_46 = V_68 & ~ 0x000e ;
switch( V_2 -> V_183 ) {
case V_232 :
case V_218 :
case V_221 :
case V_233 :
V_2 -> V_46 &= ~ V_47 ;
break;
case V_234 :
V_2 -> V_46 |= V_47 ;
}
V_209 = ( bool ) ( V_2 -> V_46 & V_47 ) ;
if( ! V_2 -> V_206 ) V_2 -> V_46 &= ~ V_47 ;
else if( V_2 -> V_206 == 1 ) V_2 -> V_46 |= V_47 ;
#ifdef V_95
if( V_2 -> V_3 >= V_9 ) {
if( V_2 -> V_46 & V_47 ) {
if( V_68 & 0x08 ) V_2 -> V_46 |= V_48 ;
}
if( V_2 -> V_18 & V_235 ) {
if( V_2 -> V_17 ) {
if( V_68 & 0x02 ) V_2 -> V_46 |= V_120 ;
} else if( ( V_13 = F_7 ( V_2 ) ) ) {
if( V_13 [ 2 ] & 0x01 ) V_2 -> V_46 |= V_120 ;
}
}
} else if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_46 & V_47 ) {
if( F_8 ( V_2 -> V_21 , 0x39 ) & 0x01 ) V_2 -> V_46 |= V_48 ;
}
if( ( V_2 -> V_17 ) && ( ! ( V_2 -> V_20 ) ) ) {
V_2 -> V_46 &= ~ ( V_236 ) ;
V_68 = F_8 ( V_2 -> V_21 , 0x35 ) ;
if( V_68 & 0x01 ) V_2 -> V_46 |= V_236 ;
if( V_2 -> V_18 & V_235 ) {
if( V_68 & 0x02 ) V_2 -> V_46 |= V_120 ;
}
} else if( ! ( V_2 -> V_17 ) ) {
if( V_2 -> V_18 & V_235 ) {
if( ( V_2 -> V_105 == V_237 ) &&
( V_2 -> V_183 == V_238 ) ) {
V_2 -> V_46 |= V_120 ;
}
if( ( V_2 -> V_183 == V_239 ) ||
( V_2 -> V_183 == V_240 ) ||
( V_2 -> V_183 == V_241 ) ||
( V_2 -> V_183 == V_242 ) ) {
V_2 -> V_46 |= V_120 ;
}
}
}
}
#endif
if( ( V_2 -> V_104 == 1 ) || ( V_2 -> V_18 & V_79 ) ) {
V_2 -> V_46 &= ~ V_48 ;
} else if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_18 & V_19 ) {
V_2 -> V_46 &= ~ V_48 ;
} else {
if( V_209 ) V_2 -> V_46 |= V_48 ;
if( V_2 -> V_243 == 1 ) V_2 -> V_46 &= ~ V_48 ;
}
}
V_2 -> V_244 = V_245 ;
V_2 -> V_197 = V_246 ;
switch( V_2 -> V_183 ) {
case V_232 :
case V_218 :
case V_221 : V_2 -> V_247 = 640 ; V_2 -> V_248 = 480 ;
V_2 -> V_195 = 24 ; V_2 -> V_196 = 3 ;
V_2 -> V_244 = V_249 ;
V_2 -> V_197 = V_249 ;
break;
case V_234 : V_2 -> V_247 = 640 ; V_2 -> V_248 = 480 ;
V_2 -> V_196 = 3 ;
V_2 -> V_244 = V_249 ;
V_2 -> V_197 = V_249 ;
break;
case V_250 : V_2 -> V_247 = 800 ; V_2 -> V_248 = 600 ;
V_2 -> V_190 = 1056 ; V_2 -> V_192 = 628 ;
V_2 -> V_193 = 40 ; V_2 -> V_194 = 128 ;
V_2 -> V_195 = 1 ; V_2 -> V_196 = 4 ;
V_2 -> V_244 = V_251 ;
V_2 -> V_197 = V_251 ;
break;
case V_252 : V_2 -> V_247 = 1024 ; V_2 -> V_248 = 600 ;
V_2 -> V_190 = 1344 ; V_2 -> V_192 = 800 ;
V_2 -> V_193 = 24 ; V_2 -> V_194 = 136 ;
V_2 -> V_195 = 2 ; V_2 -> V_196 = 6 ;
V_2 -> V_244 = V_245 ;
V_2 -> V_197 = V_253 ;
break;
case V_238 : V_2 -> V_247 = 1024 ; V_2 -> V_248 = 768 ;
V_2 -> V_190 = 1344 ; V_2 -> V_192 = 806 ;
V_2 -> V_193 = 24 ; V_2 -> V_194 = 136 ;
V_2 -> V_195 = 3 ; V_2 -> V_196 = 6 ;
if( V_2 -> V_3 < V_5 ) {
V_2 -> V_193 = 23 ;
V_2 -> V_196 = 5 ;
}
V_2 -> V_244 = V_245 ;
V_2 -> V_197 = V_253 ;
F_56 ( V_2 ) ;
break;
case V_254 : V_2 -> V_247 = 1152 ; V_2 -> V_248 = 768 ;
V_2 -> V_190 = 1344 ; V_2 -> V_192 = 806 ;
V_2 -> V_193 = 24 ; V_2 -> V_194 = 136 ;
V_2 -> V_195 = 3 ; V_2 -> V_196 = 6 ;
if( V_2 -> V_3 < V_5 ) {
V_2 -> V_193 = 23 ;
V_2 -> V_196 = 5 ;
}
V_2 -> V_244 = V_245 ;
V_2 -> V_197 = V_253 ;
break;
case V_255 : V_2 -> V_247 = 1152 ; V_2 -> V_248 = 864 ;
break;
case V_256 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 720 ;
V_2 -> V_190 = 1650 ; V_2 -> V_192 = 750 ;
V_2 -> V_193 = 110 ; V_2 -> V_194 = 40 ;
V_2 -> V_195 = 5 ; V_2 -> V_196 = 5 ;
V_2 -> V_197 = V_257 ;
F_56 ( V_2 ) ;
break;
case V_185 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 768 ;
if( V_2 -> V_104 == 1 ) {
V_2 -> V_190 = 1408 ; V_2 -> V_192 = 806 ;
V_2 -> V_244 = V_258 ;
V_2 -> V_197 = V_259 ;
} else {
V_2 -> V_190 = 1688 ; V_2 -> V_192 = 802 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 3 ; V_2 -> V_196 = 6 ;
V_2 -> V_244 = V_258 ;
V_2 -> V_197 = V_259 ;
}
break;
case V_184 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 768 ;
V_2 -> V_190 = 1660 ; V_2 -> V_192 = 806 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 3 ; V_2 -> V_196 = 6 ;
V_2 -> V_197 = V_260 ;
F_56 ( V_2 ) ;
break;
case V_187 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 800 ;
V_2 -> V_190 = 1408 ; V_2 -> V_192 = 816 ;
V_2 -> V_193 = 21 ; V_2 -> V_194 = 24 ;
V_2 -> V_195 = 4 ; V_2 -> V_196 = 3 ;
V_2 -> V_197 = V_261 ;
F_56 ( V_2 ) ;
break;
case V_186 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 800 ;
V_2 -> V_190 = 1552 ; V_2 -> V_192 = 812 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 4 ; V_2 -> V_196 = 3 ;
V_2 -> V_197 = V_262 ;
F_56 ( V_2 ) ;
break;
case V_188 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 854 ;
V_2 -> V_190 = 1664 ; V_2 -> V_192 = 861 ;
V_2 -> V_193 = 16 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 1 ; V_2 -> V_196 = 3 ;
V_2 -> V_197 = V_263 ;
F_56 ( V_2 ) ;
break;
case V_233 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 960 ;
V_2 -> V_190 = 1800 ; V_2 -> V_192 = 1000 ;
V_2 -> V_244 = V_264 ;
V_2 -> V_197 = V_265 ;
if( V_132 == V_266 ) {
V_2 -> V_244 = V_267 ;
V_2 -> V_197 = V_268 ;
}
break;
case V_239 : V_2 -> V_247 = 1280 ; V_2 -> V_248 = 1024 ;
V_2 -> V_190 = 1688 ; V_2 -> V_192 = 1066 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 1 ; V_2 -> V_196 = 3 ;
V_2 -> V_244 = V_264 ;
V_2 -> V_197 = V_246 ;
F_56 ( V_2 ) ;
break;
case V_240 : V_2 -> V_247 = 1400 ; V_2 -> V_248 = 1050 ;
V_2 -> V_190 = 1688 ; V_2 -> V_192 = 1066 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 112 ;
V_2 -> V_195 = 1 ; V_2 -> V_196 = 3 ;
V_2 -> V_197 = V_246 ;
F_56 ( V_2 ) ;
break;
case V_241 : V_2 -> V_247 = 1600 ; V_2 -> V_248 = 1200 ;
V_2 -> V_190 = 2160 ; V_2 -> V_192 = 1250 ;
V_2 -> V_193 = 64 ; V_2 -> V_194 = 192 ;
V_2 -> V_195 = 1 ; V_2 -> V_196 = 3 ;
V_2 -> V_197 = V_269 ;
if( V_2 -> V_18 & V_270 ) {
if( V_2 -> V_35 & V_44 ) {
V_2 -> V_190 = 1760 ; V_2 -> V_192 = 1235 ;
V_2 -> V_193 = 48 ; V_2 -> V_194 = 32 ;
V_2 -> V_195 = 2 ; V_2 -> V_196 = 4 ;
V_2 -> V_197 = V_271 ;
V_2 -> V_212 = true ;
}
} else if( V_2 -> V_104 ) {
V_2 -> V_190 = 2048 ; V_2 -> V_192 = 1320 ;
V_2 -> V_193 = V_2 -> V_194 = 999 ;
V_2 -> V_195 = V_2 -> V_196 = 999 ;
}
F_56 ( V_2 ) ;
break;
case V_242 : V_2 -> V_247 = 1680 ; V_2 -> V_248 = 1050 ;
V_2 -> V_190 = 1900 ; V_2 -> V_192 = 1066 ;
V_2 -> V_193 = 26 ; V_2 -> V_194 = 76 ;
V_2 -> V_195 = 3 ; V_2 -> V_196 = 6 ;
V_2 -> V_197 = V_272 ;
F_56 ( V_2 ) ;
break;
case V_225 : V_2 -> V_247 = 1360 ; V_2 -> V_248 = 1024 ;
V_2 -> V_190 = 1688 ; V_2 -> V_192 = 1066 ;
break;
case V_227 : V_2 -> V_247 = 848 ; V_2 -> V_248 = 480 ;
V_2 -> V_190 = 1088 ; V_2 -> V_192 = 525 ;
break;
case V_229 : V_2 -> V_247 = 856 ; V_2 -> V_248 = 480 ;
V_2 -> V_190 = 1088 ; V_2 -> V_192 = 525 ;
break;
case V_273 : V_2 -> V_247 = V_2 -> V_274 ;
V_2 -> V_248 = V_2 -> V_275 ;
V_2 -> V_190 = V_2 -> V_276 ;
V_2 -> V_192 = V_2 -> V_277 ;
if( V_2 -> V_278 != - 1 ) {
V_2 -> V_247 = V_2 -> V_279 [ V_2 -> V_278 ] ;
V_2 -> V_248 = V_2 -> V_280 [ V_2 -> V_278 ] ;
V_2 -> V_190 = V_2 -> V_281 [ V_2 -> V_278 ] ;
V_2 -> V_192 = V_2 -> V_282 [ V_2 -> V_278 ] ;
V_2 -> V_193 = V_2 -> V_283 [ V_2 -> V_278 ] ;
V_2 -> V_194 = V_2 -> V_284 [ V_2 -> V_278 ] ;
V_2 -> V_195 = V_2 -> V_285 [ V_2 -> V_278 ] ;
V_2 -> V_196 = V_2 -> V_286 [ V_2 -> V_278 ] ;
V_2 -> V_193 -= V_2 -> V_247 ;
V_2 -> V_194 -= V_2 -> V_193 ;
V_2 -> V_195 -= V_2 -> V_248 ;
V_2 -> V_196 -= V_2 -> V_195 ;
if( V_2 -> V_287 ) {
int V_16 ;
V_2 -> V_197 = V_198 ;
V_2 -> V_244 = V_288 ;
if( V_2 -> V_3 < V_5 ) V_16 = V_288 ;
else V_16 = V_198 ;
V_2 -> V_199 [ V_16 ] . CLOCK =
V_2 -> V_200 [ V_16 ] . CLOCK = V_2 -> V_287 ;
V_2 -> V_199 [ V_16 ] . V_201 =
V_2 -> V_200 [ V_16 ] . V_202 = V_2 -> V_289 ;
V_2 -> V_199 [ V_16 ] . V_203 =
V_2 -> V_200 [ V_16 ] . V_204 = V_2 -> V_290 ;
}
}
break;
default: V_2 -> V_247 = 1024 ; V_2 -> V_248 = 768 ;
V_2 -> V_190 = 1344 ; V_2 -> V_192 = 806 ;
break;
}
if( ( V_2 -> V_291 ) ||
( V_2 -> V_292 ) ||
( V_2 -> V_105 == V_224 ) ||
( V_2 -> V_105 == V_293 ) ||
( V_2 -> V_105 == V_226 ) ||
( V_2 -> V_105 == V_228 ) ) {
V_2 -> V_193 = 999 ;
V_2 -> V_194 = 999 ;
}
if( ( V_2 -> V_105 == V_224 ) ||
( V_2 -> V_105 == V_293 ) ||
( V_2 -> V_105 == V_226 ) ||
( V_2 -> V_105 == V_228 ) ) {
V_2 -> V_195 = 999 ;
V_2 -> V_196 = 999 ;
}
if( ( V_2 -> V_18 & V_34 ) && ( ! ( V_2 -> V_18 & V_79 ) ) ) {
if( ( V_2 -> V_35 & V_43 ) && ( V_66 & V_294 ) ) {
V_2 -> V_46 |= V_47 ;
}
switch( V_2 -> V_183 ) {
case V_273 :
case V_255 :
case V_185 :
V_2 -> V_46 |= V_47 ;
break;
case V_250 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_238 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_256 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
if( V_2 -> V_190 == 1650 ) {
V_2 -> V_46 |= V_47 ;
}
break;
}
case V_184 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
switch( V_132 ) {
case V_174 : if( V_2 -> V_206 == - 1 ) {
V_2 -> V_46 |= V_47 ;
}
break;
}
break;
}
case V_187 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_174 , V_304 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_186 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
switch( V_132 ) {
case V_174 :
case V_304 : if( V_2 -> V_206 == - 1 ) {
V_2 -> V_46 |= V_47 ;
}
break;
}
break;
}
case V_188 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
switch( V_132 ) {
case V_174 :
case V_304 :
case V_305 : if( V_2 -> V_206 == - 1 ) {
V_2 -> V_46 |= V_47 ;
}
break;
}
break;
}
case V_233 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_306 , V_174 , V_304 , V_305 ,
V_307 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_239 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_306 , V_174 , V_304 , V_305 ,
V_307 , V_308 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_240 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_306 , V_304 , V_305 , V_307 ,
V_308 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
switch( V_132 ) {
case V_174 : if( V_2 -> V_206 == - 1 ) {
V_2 -> V_46 |= V_47 ;
}
break;
case V_266 : V_2 -> V_46 |= V_47 ;
break;
}
break;
}
case V_241 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_306 , V_174 , V_304 , V_305 ,
V_307 , V_308 , V_309 , V_310 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
case V_242 : {
static const unsigned char V_205 [] = {
V_295 , V_296 , V_297 , V_172 , V_298 ,
V_299 , V_300 , V_301 , V_173 , V_302 ,
V_303 , V_306 , V_307 , V_308 , V_309 ,
V_310 , 0xff
} ;
F_57 ( V_2 , V_132 , V_205 ) ;
break;
}
}
}
#ifdef V_94
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_105 == V_226 || V_2 -> V_105 == V_228 ) {
V_2 -> V_46 = 0x80 | 0x40 | 0x20 ;
}
}
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_90 ) {
if( ( V_11 [ 0x233 ] == 0x12 ) && ( V_11 [ 0x234 ] == 0x34 ) ) {
if( ! ( V_11 [ 0x235 ] & 0x02 ) ) {
V_2 -> V_46 &= ( ~ V_47 ) ;
}
}
}
} else if( V_2 -> V_18 & V_39 ) {
if( ( V_2 -> V_77 & V_311 ) && ( ( V_25 == 0x03 ) || ( V_25 == 0x10 ) ) ) {
V_2 -> V_46 &= ( ~ V_47 ) ;
}
}
}
#endif
if( V_207 == V_2 -> V_247 && V_208 == V_2 -> V_248 ) {
V_2 -> V_46 &= ~ V_48 ;
}
if( V_2 -> V_312 ) {
V_2 -> V_46 |= ( V_47 | V_48 ) ;
}
switch( V_2 -> V_183 ) {
case V_234 :
V_2 -> V_46 |= ( V_47 | V_48 ) ;
break;
case V_187 :
if( V_2 -> V_243 == - 1 ) V_2 -> V_46 &= ~ V_48 ;
break;
case V_233 :
V_2 -> V_46 &= ~ V_48 ;
break;
case V_273 :
if( ( ! V_2 -> V_287 ) ||
( V_207 > V_2 -> V_247 ) || ( V_208 > V_2 -> V_248 ) ) {
V_2 -> V_46 |= V_48 ;
}
break;
}
if( ( V_2 -> V_133 ) || ( V_2 -> V_105 == V_313 ) ) {
V_2 -> V_46 |= ( V_47 | V_48 ) ;
}
if( ! ( V_2 -> V_46 & V_47 ) ) {
V_2 -> V_46 &= ~ V_48 ;
}
if( ! ( ( V_2 -> V_3 < V_5 ) && ( V_2 -> V_77 & V_311 ) ) ) {
if( ( V_2 -> V_104 == 1 ) || ( V_2 -> V_18 & V_79 ) ) {
if( V_2 -> V_312 == 0 ) {
if( V_25 == 0x12 ) {
if( V_2 -> V_46 & V_48 ) {
V_2 -> V_77 |= V_314 ;
}
} else if( V_25 > 0x13 ) {
if( V_2 -> V_183 == V_252 ) {
if( ! ( V_2 -> V_46 & V_47 ) ) {
if( ( V_132 == V_315 ) || ( V_132 == V_316 ) ) {
V_2 -> V_77 |= V_314 ;
}
}
}
}
}
}
if( V_66 & V_75 ) {
if( V_2 -> V_312 == 1 ) {
V_2 -> V_77 |= V_314 ;
} else if( V_2 -> V_46 & V_47 ) {
V_2 -> V_77 |= V_314 ;
} else if( V_2 -> V_183 == V_234 ) {
V_2 -> V_77 |= V_314 ;
} else if( V_25 > 0x13 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_132 == V_317 ) V_2 -> V_77 |= V_314 ;
} else if( V_2 -> V_183 == V_250 ) {
if( V_132 == V_316 ) V_2 -> V_77 |= V_314 ;
}
}
}
}
if( V_2 -> V_35 & V_85 ) {
if( V_2 -> V_35 & V_136 ) {
V_2 -> V_77 |= V_318 ;
}
} else {
V_2 -> V_77 |= V_318 ;
}
#if 0
printk(KERN_DEBUG "sisfb: (LCDInfo=0x%04x LCDResInfo=0x%02x LCDTypeInfo=0x%02x)\n",
SiS_Pr->SiS_LCDInfo, SiS_Pr->SiS_LCDResInfo, SiS_Pr->SiS_LCDTypeInfo);
#endif
}
unsigned short
F_59 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_320 , V_321 = 0 , V_322 = 0 , V_323 = 0 ;
unsigned short V_66 , V_132 , V_131 ;
const unsigned char * V_324 = NULL ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
V_320 = V_2 -> V_71 [ V_26 ] . V_326 ;
V_322 = ( F_26 ( ( V_2 -> V_327 + 0x02 ) ) >> 2 ) & 0x03 ;
V_323 = V_322 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
V_320 = V_2 -> V_32 [ V_319 ] . V_328 ;
V_322 = V_2 -> V_32 [ V_319 ] . V_329 ;
V_323 = F_60 ( V_2 , V_319 ,
( V_2 -> V_77 & V_78 ) ? V_2 -> V_330 : V_2 -> V_331 ) ;
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_77 & V_78 ) {
V_320 >>= 6 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_3 < V_5 ) {
V_321 = V_2 -> V_244 ;
if( ( V_2 -> V_46 & V_47 ) && ( V_2 -> V_46 & V_48 ) ) {
V_321 = V_322 ;
}
} else {
V_321 = V_2 -> V_197 ;
if( ( V_2 -> V_46 & V_47 ) && ( V_2 -> V_46 & V_48 ) ) {
switch( V_132 ) {
case V_295 : V_321 = V_332 ; break;
case V_296 : V_321 = V_333 ; break;
case V_297 : V_321 = V_334 ; break;
case V_298 : V_321 = V_335 ; break;
case V_299 : V_321 = V_336 ; break;
case V_172 : V_321 = V_337 ; break;
case V_173 : V_321 = V_338 ; break;
case V_306 : V_321 = V_339 ; break;
case V_174 : V_321 = V_257 ; break;
case V_309 : V_321 = V_340 ; break;
default: V_321 = V_322 ;
}
if( V_25 <= 0x13 ) {
if( V_2 -> V_3 <= V_102 ) {
if( V_2 -> V_71 [ V_26 ] . V_326 == 1 ) V_321 = 0x42 ;
} else {
if( V_2 -> V_71 [ V_26 ] . V_326 == 1 ) V_321 = 0x00 ;
}
}
if( V_2 -> V_3 <= V_102 ) {
if( V_321 == 0 ) V_321 = 0x41 ;
if( V_321 == 1 ) V_321 = 0x43 ;
if( V_321 == 4 ) V_321 = 0x44 ;
}
}
}
} else if( V_2 -> V_35 & V_62 ) {
if( V_2 -> V_35 & V_50 ) {
if( V_2 -> V_58 & V_182 ) V_321 = V_341 ;
else V_321 = V_342 ;
if( V_2 -> V_58 & V_178 ) V_321 = V_343 ;
} else if( V_2 -> V_58 & V_59 ) V_321 = V_344 ;
else if( V_2 -> V_58 & V_165 ) V_321 = V_345 ;
else if( V_2 -> V_58 & V_182 ) V_321 = V_345 ;
else V_321 = V_346 ;
if( V_2 -> V_3 < V_5 ) V_321 += V_347 ;
else V_321 += V_348 ;
} else {
V_321 = V_323 ;
if( V_2 -> V_3 < V_5 ) {
if( V_25 > 0x13 ) {
if( ( V_2 -> V_3 == V_149 ) &&
( V_2 -> V_349 >= 0x30 ) ) {
if( V_321 == 0x14 ) V_321 = 0x34 ;
}
if( V_321 == 0x17 ) V_321 = 0x45 ;
}
}
}
} else {
V_321 = V_323 ;
if( V_2 -> V_3 < V_5 ) {
if( V_25 > 0x13 ) {
if( ( V_2 -> V_3 != V_149 ) &&
( V_2 -> V_3 != V_350 ) ) {
if( V_321 == 0x1b ) V_321 = 0x48 ;
}
}
}
}
} else {
V_321 = V_320 ;
if( V_2 -> V_77 & V_78 ) {
if( ( V_2 -> V_61 != 0 ) && ( V_2 -> V_35 & V_62 ) ) {
V_321 &= 0x1f ;
V_131 = 0 ;
if( V_2 -> V_58 & V_170 ) V_131 += 1 ;
if( V_2 -> V_58 & V_157 ) {
V_131 += 2 ;
if( V_2 -> V_84 > V_146 ) {
if( V_2 -> V_171 ) V_131 = 8 ;
}
if( V_2 -> V_58 & V_160 ) {
V_131 = 4 ;
if( V_2 -> V_58 & V_170 ) V_131 += 1 ;
} else if( V_2 -> V_58 & V_162 ) {
V_131 = 6 ;
if( V_2 -> V_58 & V_170 ) V_131 += 1 ;
}
}
switch( V_131 ) {
case 0 : V_324 = V_2 -> V_351 ; break;
case 1 : V_324 = V_2 -> V_352 ; break;
case 2 : V_324 = V_2 -> V_353 ; break;
case 3 : V_324 = V_2 -> V_354 ; break;
case 4 : V_324 = V_2 -> V_355 ; break;
case 5 : V_324 = V_2 -> V_356 ; break;
case 6 : V_324 = V_2 -> V_357 ; break;
case 7 : V_324 = V_2 -> V_358 ; break;
case 8 : V_324 = V_2 -> V_359 ; break;
default: V_324 = V_2 -> V_354 ; break;
}
V_321 = V_324 [ V_321 ] ;
} else if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_3 < V_5 ) {
V_321 = V_2 -> V_244 ;
} else {
V_321 = V_2 -> V_197 ;
}
#ifdef V_94
if( V_2 -> V_105 == V_224 ) V_321 = 0x44 ;
if( V_2 -> V_105 == V_226 || V_2 -> V_105 == V_228 ) {
if( V_2 -> V_3 < V_5 ) {
V_321 = V_360 ;
} else {
V_321 = V_361 ;
}
}
#endif
} else {
V_321 = V_323 ;
if( V_2 -> V_3 < V_5 ) {
if( V_25 > 0x13 ) {
if( ( V_2 -> V_3 == V_149 ) &&
( V_2 -> V_349 >= 0x30 ) ) {
if( V_321 == 0x14 ) V_321 = 0x2e ;
}
}
}
}
} else {
V_321 = V_323 ;
if( V_2 -> V_3 < V_5 ) {
if( V_25 > 0x13 ) {
if( ( V_2 -> V_3 != V_149 ) &&
( V_2 -> V_3 != V_350 ) ) {
if( V_321 == 0x1b ) V_321 = 0x48 ;
}
#if 0
if(SiS_Pr->ChipType == SIS_730) {
if(VCLKIndex == 0x0b) VCLKIndex = 0x40;
if(VCLKIndex == 0x0d) VCLKIndex = 0x41;
}
#endif
}
}
}
}
return V_321 ;
}
static void
F_61 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_28 , V_113 , V_66 , V_362 = 0 ;
short V_363 ;
#if F_23 ( V_94 ) || F_23 ( V_95 )
unsigned short V_364 ;
#endif
#ifdef V_95
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_365 , V_366 ;
#endif
V_66 = F_53 ( V_2 , V_25 , V_26 ) ;
if( V_2 -> V_35 & V_44 ) {
F_6 ( V_2 -> V_6 , 0x00 , 0xAF , 0x40 ) ;
F_4 ( V_2 -> V_6 , 0x2E , 0xF7 ) ;
} else {
for( V_28 = 0 , V_113 = 4 ; V_28 < 3 ; V_28 ++ , V_113 ++ ) F_15 ( V_2 -> V_6 , V_113 , 0 ) ;
if( V_2 -> V_3 >= V_5 ) {
F_4 ( V_2 -> V_6 , 0x02 , 0x7F ) ;
}
V_363 = V_2 -> V_84 ;
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( V_2 -> V_18 & V_79 ) {
V_364 = F_8 ( V_2 -> V_10 , 0x32 ) ;
V_364 &= 0xef ;
V_364 |= 0x02 ;
if( ( V_2 -> V_35 & V_62 ) || ( V_2 -> V_35 & V_36 ) ) {
V_364 |= 0x10 ;
V_364 &= 0xfd ;
}
F_15 ( V_2 -> V_10 , 0x32 , V_364 ) ;
}
if( V_25 > 0x13 ) {
V_363 -= V_146 ;
if( V_363 >= 0 ) {
V_362 = ( ( 0x10 >> V_363 ) | 0x80 ) ;
}
} else V_362 = 0x80 ;
if( V_2 -> V_35 & V_85 ) V_362 ^= 0xA0 ;
#endif
} else {
#ifdef V_95
if( V_25 > 0x13 ) {
V_363 -= V_146 ;
if( V_363 >= 0 ) {
V_362 = ( 0x08 >> V_363 ) ;
if ( V_362 == 0 ) V_362 = 1 ;
V_362 |= 0x40 ;
}
} else V_362 = 0x40 ;
if( V_2 -> V_35 & V_85 ) V_362 ^= 0x50 ;
#endif
}
if( V_2 -> V_35 & V_87 ) V_362 = 0 ;
if( V_2 -> V_3 < V_5 ) {
F_15 ( V_2 -> V_6 , 0x00 , V_362 ) ;
} else {
#ifdef V_95
if( V_2 -> V_104 == 1 ) {
F_6 ( V_2 -> V_6 , 0x00 , 0xa0 , V_362 ) ;
} else if( V_2 -> V_18 & V_34 ) {
if( V_367 ) {
F_15 ( V_2 -> V_6 , 0x00 , V_362 ) ;
} else {
F_6 ( V_2 -> V_6 , 0x00 , 0xa0 , V_362 ) ;
}
}
#endif
}
if( V_2 -> V_18 & V_34 ) {
V_362 = 0x01 ;
if( ! ( V_2 -> V_35 & V_85 ) ) {
V_362 |= 0x02 ;
}
if( ! ( V_2 -> V_35 & V_36 ) ) {
V_362 ^= 0x05 ;
if( ! ( V_2 -> V_35 & V_43 ) ) {
V_362 ^= 0x01 ;
}
}
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_35 & V_87 ) V_362 = 0 ;
V_362 = ( V_362 << 5 ) & 0xFF ;
F_15 ( V_2 -> V_6 , 0x01 , V_362 ) ;
V_362 = ( V_362 >> 5 ) & 0xFF ;
} else {
if( V_2 -> V_35 & V_87 ) V_362 = 0x08 ;
else if( ! ( F_33 ( V_2 ) ) ) V_362 |= 0x08 ;
F_6 ( V_2 -> V_6 , 0x2E , 0xF0 , V_362 ) ;
V_362 &= ~ 0x08 ;
}
if( ( V_2 -> V_84 == V_146 ) && ( ! ( V_2 -> V_35 & V_85 ) ) ) {
V_362 |= 0x10 ;
}
V_362 |= 0x80 ;
if( V_2 -> V_18 & V_99 ) {
if( V_2 -> V_247 < 1280 && V_2 -> V_248 < 960 ) V_362 &= ~ 0x80 ;
}
if( V_2 -> V_35 & V_62 ) {
if( ! ( V_2 -> V_58 & ( V_59 | V_165 ) ) ) {
if( V_2 -> V_35 & V_85 ) {
V_362 |= 0x20 ;
}
}
}
F_6 ( V_2 -> V_114 , 0x0D , 0x40 , V_362 ) ;
V_362 = 0x80 ;
if( V_2 -> V_18 & V_99 ) {
if( V_2 -> V_247 < 1280 && V_2 -> V_248 < 960 ) V_362 = 0 ;
}
if( F_36 ( V_2 ) ) V_362 |= 0x40 ;
if( V_2 -> V_35 & V_62 ) {
if( V_2 -> V_58 & V_182 ) {
V_362 |= 0x40 ;
}
}
F_15 ( V_2 -> V_114 , 0x0C , V_362 ) ;
} else {
if( V_2 -> V_3 >= V_5 ) {
#ifdef V_95
V_362 = 0x80 ;
if( ( V_66 & V_147 ) && ( V_2 -> V_84 > V_146 ) ) {
if( V_2 -> V_35 & V_81 ) {
V_362 |= 0x02 ;
}
}
if( ! ( V_2 -> V_35 & V_85 ) ) V_362 |= 0x02 ;
if( V_2 -> V_35 & V_62 ) V_362 ^= 0x01 ;
if( V_2 -> V_35 & V_87 ) V_362 = 1 ;
F_6 ( V_2 -> V_6 , 0x2e , 0xF0 , V_362 ) ;
#endif
} else {
#ifdef V_94
V_362 = 0 ;
if( ( ! ( V_2 -> V_35 & V_85 ) ) && ( V_2 -> V_84 > V_146 ) ) {
V_362 |= 0x02 ;
}
V_362 <<= 5 ;
if( V_2 -> V_35 & V_87 ) V_362 = 0 ;
F_15 ( V_2 -> V_6 , 0x01 , V_362 ) ;
#endif
}
}
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_3 >= V_5 ) {
#ifdef V_95
if( ! ( V_367 ) ) {
V_362 = 0x04 ;
V_364 = 0xfb ;
if( ! ( V_2 -> V_35 & V_44 ) ) {
V_362 = 0x00 ;
if( F_33 ( V_2 ) ) {
V_364 = 0xff ;
}
}
F_6 ( V_2 -> V_6 , 0x13 , V_364 , V_362 ) ;
}
if( ( V_367 ) || ( V_2 -> V_3 >= V_9 ) || ( V_2 -> V_17 ) ) {
V_362 = 0x30 ;
V_364 = 0xc0 ;
if( ( V_2 -> V_35 & V_87 ) ||
( ( V_2 -> V_17 ) && ( ! ( V_11 [ 0x5b ] & 0x04 ) ) ) ) {
V_362 = 0x00 ;
V_364 = 0x00 ;
}
F_6 ( V_2 -> V_6 , 0x2c , 0xcf , V_362 ) ;
F_6 ( V_2 -> V_114 , 0x21 , 0x3f , V_364 ) ;
} else if( V_2 -> V_18 & V_99 ) {
F_4 ( V_2 -> V_6 , 0x2c , 0xcf ) ;
F_4 ( V_2 -> V_114 , 0x21 , 0x3f ) ;
} else if( V_2 -> V_18 & V_19 ) {
F_2 ( V_2 -> V_6 , 0x2c , 0x30 ) ;
F_2 ( V_2 -> V_114 , 0x21 , 0xc0 ) ;
} else if( V_2 -> V_18 & V_79 ) {
V_362 = 0x30 ; V_365 = 0xc0 ;
V_364 = 0xcf ; V_366 = 0x3f ;
if( V_2 -> V_368 == 0 ) {
V_362 = V_365 = 0x00 ;
} else if( V_2 -> V_368 == - 1 ) {
if( ! ( V_369 ) ) {
V_362 = V_365 = 0x00 ;
}
}
F_6 ( V_2 -> V_6 , 0x2c , V_364 , V_362 ) ;
F_6 ( V_2 -> V_114 , 0x21 , V_366 , V_365 ) ;
} else {
V_362 = 0x30 ; V_365 = 0xc0 ;
V_364 = 0xcf ; V_366 = 0x3f ;
if( ! ( V_2 -> V_35 & V_44 ) ) {
V_362 = V_365 = 0x00 ;
if( F_33 ( V_2 ) ) {
V_364 = V_366 = 0xff ;
}
}
F_6 ( V_2 -> V_6 , 0x2c , V_364 , V_362 ) ;
F_6 ( V_2 -> V_114 , 0x21 , V_366 , V_365 ) ;
}
if( V_367 ) {
V_362 = 0x80 ;
if( V_2 -> V_35 & V_87 ) V_362 = 0x00 ;
F_6 ( V_2 -> V_114 , 0x23 , 0x7f , V_362 ) ;
} else {
V_362 = 0x00 ;
V_364 = 0x7f ;
if( ! ( V_2 -> V_35 & V_44 ) ) {
V_364 = 0xff ;
if( ! ( F_33 ( V_2 ) ) ) V_362 = 0x80 ;
}
F_6 ( V_2 -> V_114 , 0x23 , V_364 , V_362 ) ;
}
#endif
} else if( V_2 -> V_18 & V_39 ) {
#ifdef V_94
F_4 ( V_2 -> V_114 , 0x21 , 0x3f ) ;
if( ( V_2 -> V_35 & V_87 ) ||
( ( V_2 -> V_18 & V_79 ) &&
( V_2 -> V_35 & V_43 ) ) ) {
F_4 ( V_2 -> V_114 , 0x23 , 0x7F ) ;
} else {
F_2 ( V_2 -> V_114 , 0x23 , 0x80 ) ;
}
#endif
}
if( V_2 -> V_18 & V_39 ) {
F_2 ( V_2 -> V_114 , 0x0D , 0x80 ) ;
if( V_2 -> V_18 & V_370 ) {
F_2 ( V_2 -> V_114 , 0x3A , 0xC0 ) ;
}
}
} else {
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_61 != 0 ) {
V_362 = 0x04 ;
V_364 = 0xfb ;
if( ! ( V_2 -> V_35 & V_44 ) ) {
V_362 = 0x00 ;
if( F_33 ( V_2 ) ) V_364 = 0xff ;
}
F_6 ( V_2 -> V_6 , 0x13 , V_364 , V_362 ) ;
if( V_2 -> V_35 & V_87 ) {
F_4 ( V_2 -> V_6 , 0x13 , 0xfb ) ;
}
F_2 ( V_2 -> V_6 , 0x2c , 0x30 ) ;
} else if( V_2 -> V_3 == V_216 ) {
F_4 ( V_2 -> V_6 , 0x13 , 0xfb ) ;
F_2 ( V_2 -> V_6 , 0x2c , 0x30 ) ;
}
}
#endif
}
}
unsigned short
F_62 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
if( V_25 <= 0x13 )
return ( ( unsigned short ) V_2 -> V_71 [ V_26 ] . V_325 ) ;
else
return ( ( unsigned short ) V_2 -> V_73 [ V_26 ] . V_134 ) ;
}
static void
F_63 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_371 , V_372 , V_66 = 0 , V_373 ;
if( V_2 -> V_133 ) {
V_371 = V_2 -> V_374 ;
if( V_2 -> V_375 & V_75 ) V_371 <<= 1 ;
V_2 -> V_376 = V_2 -> V_377 = V_371 ;
V_2 -> V_378 = V_2 -> V_379 = V_2 -> V_380 ;
return;
}
V_373 = F_62 ( V_2 , V_25 , V_26 ) ;
if( V_25 <= 0x13 ) {
V_371 = V_2 -> V_381 [ V_373 ] . V_214 ;
V_372 = V_2 -> V_381 [ V_373 ] . V_215 ;
} else {
V_371 = V_2 -> V_213 [ V_373 ] . V_214 ;
V_372 = V_2 -> V_213 [ V_373 ] . V_215 ;
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
}
if( ! V_2 -> V_292 && ! V_2 -> V_291 ) {
if( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_104 == 1 ) ) {
if( ( V_25 != 0x03 ) && ( V_2 -> V_77 & V_311 ) ) {
if( V_372 == 350 ) V_372 = 400 ;
}
if( F_8 ( V_2 -> V_21 , 0x3a ) & 0x01 ) {
if( V_25 == 0x12 ) V_372 = 400 ;
}
}
if( V_66 & V_75 ) V_371 <<= 1 ;
if( V_66 & V_382 ) V_372 <<= 1 ;
}
if( ( V_2 -> V_18 & V_34 ) && ( ! ( V_2 -> V_18 & V_79 ) ) ) {
if( V_2 -> V_35 & V_43 ) {
switch( V_2 -> V_183 ) {
case V_238 :
if( ! ( V_2 -> V_77 & V_318 ) ) {
if( ! ( V_2 -> V_46 & V_47 ) ) {
if( V_372 == 350 ) V_372 = 357 ;
if( V_372 == 400 ) V_372 = 420 ;
if( V_372 == 480 ) V_372 = 525 ;
}
}
break;
case V_239 :
if( ! ( V_2 -> V_46 & V_47 ) ) {
if( V_372 == 400 ) V_372 = 405 ;
}
if( V_372 == 350 ) V_372 = 360 ;
if( V_2 -> V_77 & V_318 ) {
if( V_372 == 360 ) V_372 = 375 ;
}
break;
case V_241 :
if( ! ( V_2 -> V_77 & V_318 ) ) {
if( V_372 == 1024 ) V_372 = 1056 ;
}
break;
}
}
} else {
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & ( V_43 | V_50 ) ) {
if( V_371 == 720 ) V_371 = 640 ;
}
} else if( V_371 == 720 ) V_371 = 640 ;
if( V_2 -> V_77 & V_311 ) {
V_372 = 400 ;
if( V_2 -> V_3 >= V_5 ) {
if( F_8 ( V_2 -> V_10 , 0x17 ) & 0x80 ) V_372 = 480 ;
} else {
if( F_8 ( V_2 -> V_10 , 0x13 ) & 0x80 ) V_372 = 480 ;
}
if( V_2 -> V_292 || V_2 -> V_291 ) V_372 = 480 ;
}
}
V_2 -> V_376 = V_2 -> V_377 = V_371 ;
V_2 -> V_378 = V_2 -> V_379 = V_372 ;
}
static void
F_64 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 , unsigned short * V_320 ,
unsigned short * V_383 )
{
unsigned short V_131 = 0 , V_112 = 0 , V_132 = 0 ;
if( V_25 <= 0x13 ) {
V_112 = V_2 -> V_71 [ V_26 ] . V_326 ;
} else {
V_112 = V_2 -> V_32 [ V_319 ] . V_328 ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
if( ( V_2 -> V_18 & V_34 ) && ( V_2 -> V_104 == 0 ) ) {
if( V_2 -> V_35 & V_43 ) {
V_131 = V_2 -> V_183 ;
if( ! ( V_2 -> V_77 & V_318 ) ) V_131 += 32 ;
if( V_2 -> V_183 == V_242 ) {
if ( V_132 == V_305 ) V_112 = 9 ;
else if( V_132 == V_384 ) V_112 = 11 ;
} else if( ( V_2 -> V_183 == V_187 ) ||
( V_2 -> V_183 == V_186 ) ||
( V_2 -> V_183 == V_188 ) ) {
if ( V_132 == V_304 ) V_112 = 9 ;
}
if( V_2 -> V_46 & V_47 ) {
V_131 = 100 ;
if( V_25 >= 0x13 ) {
V_112 = V_2 -> V_32 [ V_319 ] . V_385 ;
}
}
#ifdef V_95
if( V_2 -> V_105 == V_107 ) {
if( V_2 -> V_183 == V_239 ) {
if( ! ( V_2 -> V_46 & V_47 ) ) {
V_131 = 200 ;
if( ! ( V_2 -> V_77 & V_318 ) ) V_131 ++ ;
}
}
}
#endif
} else {
if( V_2 -> V_35 & V_50 ) {
V_131 = 2 ;
if( V_2 -> V_35 & V_85 ) {
V_131 = 13 ;
if( ! ( V_2 -> V_58 & V_178 ) ) V_131 = 14 ;
}
} else if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_59 ) V_131 = 7 ;
else if( V_2 -> V_58 & V_165 ) V_131 = 6 ;
else V_131 = 5 ;
if( V_2 -> V_58 & V_178 ) V_131 += 5 ;
} else {
if( V_2 -> V_58 & V_157 ) V_131 = 3 ;
else V_131 = 4 ;
if( V_2 -> V_58 & V_178 ) V_131 += 5 ;
}
}
V_112 &= 0x3F ;
if( V_25 > 0x13 ) {
if( V_2 -> V_35 & V_386 ) {
switch( V_132 ) {
case V_295 :
V_112 = 6 ;
if( V_2 -> V_58 & ( V_157 | V_162 ) ) V_112 = 9 ;
break;
case V_296 :
case V_297 :
case V_173 :
V_112 = 6 ;
if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_59 ) V_112 = 8 ;
}
break;
case V_172 :
V_112 = 4 ;
break;
case V_317 :
case V_179 :
V_112 = 7 ;
if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_165 ) V_112 = 8 ;
}
break;
case V_174 :
if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_59 ) V_112 = 9 ;
}
break;
}
}
}
* V_320 = V_131 ;
* V_383 = V_112 ;
} else {
V_131 = 0 ;
if( ( V_2 -> V_61 ) && ( V_2 -> V_35 & V_62 ) ) {
V_131 = 90 ;
if( V_2 -> V_58 & V_157 ) {
V_131 = 92 ;
if( V_2 -> V_84 > V_146 ) {
if( V_2 -> V_171 ) V_131 = 99 ;
}
if( V_2 -> V_58 & V_160 ) V_131 = 94 ;
else if( V_2 -> V_58 & V_162 ) V_131 = 96 ;
}
if( V_131 != 99 ) {
if( V_2 -> V_58 & V_170 ) V_131 ++ ;
}
} else {
switch( V_2 -> V_183 ) {
case V_234 : V_131 = 12 ; break;
case V_232 : V_131 = 10 ; break;
case V_218 :
case V_221 : V_131 = 14 ; break;
case V_250 : V_131 = 16 ; break;
case V_252 : V_131 = 18 ; break;
case V_254 :
case V_238 : V_131 = 20 ; break;
case V_185 : V_131 = 22 ; break;
case V_239 : V_131 = 24 ; break;
case V_240 : V_131 = 26 ; break;
case V_241 : V_131 = 28 ; break;
#ifdef V_94
case V_225 : V_131 = 80 ; break;
#endif
}
switch( V_2 -> V_183 ) {
case V_232 :
case V_218 :
case V_221 :
case V_234 :
break;
default:
if( V_2 -> V_46 & V_47 ) V_131 ++ ;
}
if( V_2 -> V_46 & V_48 ) V_131 = 30 ;
#ifdef V_94
if( V_2 -> V_105 == V_293 ) {
V_131 = 82 ;
if( V_2 -> V_46 & V_47 ) V_131 ++ ;
} else if( V_2 -> V_105 == V_226 || V_2 -> V_105 == V_228 ) {
V_131 = 84 ;
if( V_2 -> V_46 & V_47 ) V_131 ++ ;
}
#endif
}
( * V_320 ) = V_131 ;
( * V_383 ) = V_112 & 0x1F ;
}
}
static void
F_65 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_130 = 0 , V_131 = 0 , V_67 , V_387 ;
unsigned short V_88 = 0 , V_66 = 0 , V_388 = 0 ;
V_2 -> V_389 = 1 ;
V_2 -> V_390 = 1 ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_67 = F_66 ( V_2 , V_25 , V_26 ) ;
V_130 = V_2 -> V_391 [ V_67 ] . V_392 [ 0 ] ;
V_131 = V_2 -> V_391 [ V_67 ] . V_392 [ 6 ] ;
V_88 = V_2 -> V_391 [ V_67 ] . V_392 [ 7 ] ;
V_387 = ( V_66 & V_393 ) ? 8 : 9 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_67 = F_67 ( V_2 , V_319 , V_2 -> V_330 ) ;
V_130 = V_2 -> V_394 [ V_67 ] . V_395 [ 0 ] ;
V_130 |= ( V_2 -> V_394 [ V_67 ] . V_395 [ 14 ] << 8 ) ;
V_130 &= 0x03FF ;
V_131 = V_2 -> V_394 [ V_67 ] . V_395 [ 6 ] ;
V_388 = V_2 -> V_394 [ V_67 ] . V_395 [ 13 ] << 8 ;
V_388 &= 0x0100 ;
V_388 <<= 2 ;
V_131 |= V_388 ;
V_88 = V_2 -> V_394 [ V_67 ] . V_395 [ 7 ] ;
V_387 = 8 ;
}
if( V_88 & 0x01 ) V_131 |= 0x0100 ;
if( V_88 & 0x20 ) V_131 |= 0x0200 ;
V_130 += 5 ;
V_130 *= V_387 ;
if( V_66 & V_75 ) V_130 <<= 1 ;
V_131 ++ ;
V_2 -> V_396 = V_2 -> V_397 = V_130 ;
V_2 -> V_398 = V_2 -> V_399 = V_131 ;
}
static void
F_68 ( struct V_1 * V_2 , unsigned short V_25 ,
unsigned short V_26 , unsigned short V_319 )
{
unsigned short V_383 ;
if( V_2 -> V_46 & V_47 ) {
if( V_2 -> V_46 & V_48 ) {
if( V_2 -> V_133 ) {
V_383 = V_2 -> V_276 ;
if( V_2 -> V_375 & V_75 ) V_383 <<= 1 ;
V_2 -> V_396 = V_2 -> V_397 = V_383 ;
V_2 -> V_398 = V_2 -> V_399 = V_2 -> V_277 ;
} else {
if( V_25 < 0x13 ) {
V_383 = V_2 -> V_71 [ V_26 ] . V_326 ;
} else {
V_383 = V_2 -> V_32 [ V_319 ] . V_385 ;
}
if( V_383 == 0x09 ) {
if( V_2 -> V_212 ) V_383 = 0x20 ;
else if( V_2 -> V_104 == 1 ) V_383 = 0x21 ;
}
V_2 -> V_396 = V_2 -> V_400 [ V_383 ] . V_401 ;
V_2 -> V_398 = V_2 -> V_400 [ V_383 ] . V_402 ;
V_2 -> V_397 = V_2 -> V_400 [ V_383 ] . V_403 ;
V_2 -> V_399 = V_2 -> V_400 [ V_383 ] . V_404 ;
}
} else {
V_2 -> V_396 = V_2 -> V_397 = V_2 -> V_190 ;
V_2 -> V_398 = V_2 -> V_399 = V_2 -> V_192 ;
}
} else {
V_2 -> V_377 = V_2 -> V_247 ;
V_2 -> V_379 = V_2 -> V_248 ;
V_2 -> V_397 = V_2 -> V_190 ;
V_2 -> V_399 = V_2 -> V_192 ;
V_2 -> V_396 = V_2 -> V_190 - ( V_2 -> V_247 - V_2 -> V_376 ) ;
V_2 -> V_398 = V_2 -> V_192 - ( V_2 -> V_248 - V_2 -> V_378 ) ;
}
}
static void
F_69 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_320 , V_383 , V_405 ;
const struct V_406 * V_407 = NULL ;
F_63 ( V_2 , V_25 , V_26 ) ;
if( V_2 -> V_18 & V_34 ) {
V_2 -> V_389 = 1 ;
V_2 -> V_390 = 1 ;
V_2 -> V_408 = 0 ;
V_2 -> V_409 = 50 ;
V_2 -> V_410 = 0 ;
V_2 -> V_411 = 0 ;
V_2 -> V_412 = 0 ;
V_2 -> V_413 = 0 ;
V_2 -> V_414 = 0 ;
}
if( ( V_2 -> V_18 & V_34 ) && ( V_2 -> V_35 & V_44 ) ) {
#ifdef V_95
F_68 ( V_2 , V_25 , V_26 , V_319 ) ;
F_70 ( V_2 , V_25 , V_26 ) ;
#endif
} else {
V_405 = V_2 -> V_104 ;
if( ( V_2 -> V_18 & V_79 ) && ( V_2 -> V_35 & V_43 ) ) {
V_2 -> V_104 = 1 ;
}
F_64 ( V_2 , V_25 , V_26 , V_319 ,
& V_320 , & V_383 ) ;
V_2 -> V_104 = V_405 ;
switch( V_320 ) {
case 10 : V_407 = V_2 -> V_415 ; break;
case 14 : V_407 = V_2 -> V_416 ; break;
case 12 : V_407 = V_2 -> V_417 ; break;
case 16 : V_407 = V_2 -> V_418 ; break;
case 18 : V_407 = V_2 -> V_419 ; break;
case 20 : V_407 = V_2 -> V_420 ; break;
#ifdef V_94
case 80 : V_407 = V_2 -> V_421 ; break;
case 81 : V_407 = V_2 -> V_422 ; break;
case 82 : V_407 = V_2 -> V_423 ; break;
case 84 : V_407 = V_2 -> V_424 ; break;
case 85 : V_407 = V_2 -> V_425 ; break;
#endif
case 90 : V_407 = V_2 -> V_426 ; break;
case 91 : V_407 = V_2 -> V_427 ; break;
case 92 : V_407 = V_2 -> V_428 ; break;
case 93 : V_407 = V_2 -> V_429 ; break;
case 94 : V_407 = V_2 -> V_430 ; break;
case 95 : V_407 = V_2 -> V_431 ; break;
case 96 : V_407 = V_2 -> V_432 ; break;
case 97 : V_407 = V_2 -> V_433 ; break;
case 99 : V_407 = V_2 -> V_434 ; break;
}
if( V_407 ) {
V_2 -> V_396 = ( V_407 + V_383 ) -> V_401 ;
V_2 -> V_398 = ( V_407 + V_383 ) -> V_402 ;
V_2 -> V_397 = ( V_407 + V_383 ) -> V_403 ;
V_2 -> V_399 = ( V_407 + V_383 ) -> V_404 ;
} else {
F_68 ( V_2 , V_25 , V_26 , V_319 ) ;
}
if( ( ! ( V_2 -> V_18 & V_34 ) ) &&
( V_2 -> V_35 & V_43 ) &&
( ! ( V_2 -> V_46 & V_48 ) ) ) {
if( ( ! ( V_2 -> V_46 & V_47 ) ) ||
( V_2 -> V_77 & V_311 ) ) {
V_2 -> V_377 = V_2 -> V_247 ;
V_2 -> V_379 = V_2 -> V_248 ;
#ifdef V_94
if( V_2 -> V_105 == V_224 ) {
if( V_383 < 0x08 ) {
V_2 -> V_377 = 1280 ;
V_2 -> V_379 = 1024 ;
}
}
#endif
}
}
}
}
static void
F_71 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned char * V_11 = NULL ;
unsigned short V_130 , V_131 , V_66 , V_23 = 0 ;
unsigned short V_132 , V_320 , V_383 ;
const struct V_435 * V_436 = NULL ;
const struct V_437 * V_438 = NULL ;
#ifdef V_95
short V_439 ;
#endif
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
V_132 = 0 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
#ifdef V_95
V_439 = V_2 -> V_73 [ V_26 ] . V_440 ;
if( ( V_2 -> V_35 & V_43 ) &&
( V_2 -> V_77 & V_318 ) &&
( V_439 >= 0 ) &&
( V_2 -> V_191 ) ) {
if( ( V_11 = F_7 ( V_2 ) ) ) {
if( ( V_23 = ( F_9 ( 21 ) ) ) ) {
V_23 += ( V_439 * 10 ) ;
V_11 = V_2 -> V_12 ;
}
}
}
#endif
}
V_2 -> V_408 = 0 ;
V_2 -> V_409 = 50 ;
V_2 -> V_410 = 0 ;
V_2 -> V_411 = 0 ;
V_2 -> V_412 = 0 ;
V_2 -> V_413 = 0 ;
V_2 -> V_414 = 0 ;
F_63 ( V_2 , V_25 , V_26 ) ;
if( V_2 -> V_35 & V_36 ) {
if( V_2 -> V_133 ) {
V_2 -> V_389 = 1 ;
V_2 -> V_390 = 1 ;
V_2 -> V_377 = V_2 -> V_376 ;
V_2 -> V_379 = V_2 -> V_378 ;
V_130 = V_2 -> V_276 ;
if( V_66 & V_75 ) V_130 <<= 1 ;
V_2 -> V_396 = V_2 -> V_397 = V_130 ;
V_2 -> V_398 = V_2 -> V_399 = V_2 -> V_277 ;
} else {
F_65 ( V_2 , V_25 , V_26 , V_319 ) ;
}
} else if( V_2 -> V_35 & V_62 ) {
F_64 ( V_2 , V_25 , V_26 , V_319 ,
& V_320 , & V_383 ) ;
switch( V_320 ) {
case 2 : V_438 = V_2 -> V_441 ; break;
case 3 : V_438 = V_2 -> V_442 ; break;
case 4 : V_438 = V_2 -> V_443 ; break;
case 5 : V_438 = V_2 -> V_444 ; break;
case 6 : V_438 = V_2 -> V_445 ; break;
case 7 : V_438 = V_2 -> V_446 ; break;
case 8 : V_438 = V_2 -> V_447 ; break;
case 9 : V_438 = V_2 -> V_448 ; break;
case 10 : V_438 = V_2 -> V_449 ; break;
case 11 : V_438 = V_2 -> V_450 ; break;
case 12 : V_438 = V_2 -> V_451 ; break;
case 13 : V_438 = V_2 -> V_452 ; break;
case 14 : V_438 = V_2 -> V_453 ; break;
default: V_438 = V_2 -> V_447 ; break;
}
V_2 -> V_389 = ( V_438 + V_383 ) -> V_454 ;
V_2 -> V_390 = ( V_438 + V_383 ) -> V_455 ;
V_2 -> V_396 = ( V_438 + V_383 ) -> V_401 ;
V_2 -> V_398 = ( V_438 + V_383 ) -> V_402 ;
V_2 -> V_377 = ( V_438 + V_383 ) -> V_456 ;
V_2 -> V_379 = ( V_438 + V_383 ) -> V_457 ;
V_2 -> V_414 = ( V_438 + V_383 ) -> V_458 & 0x0fff ;
if( V_66 & V_75 ) {
V_2 -> V_409 = ( V_438 + V_383 ) -> V_459 ;
if( V_2 -> V_414 ) {
V_2 -> V_414 = ( ( V_2 -> V_414 + 3 ) >> 1 ) - 3 ;
V_130 = ( ( V_438 + V_383 ) -> V_458 >> 12 ) & 0x07 ;
if( ( V_438 + V_383 ) -> V_458 & 0x8000 ) V_2 -> V_414 -= V_130 ;
else V_2 -> V_414 += V_130 ;
}
} else {
V_2 -> V_409 = ( V_438 + V_383 ) -> V_460 ;
}
V_2 -> V_408 = ( ( V_438 + V_383 ) -> V_461 ) << 7 ;
if( V_2 -> V_35 & V_50 ) {
if( ( V_132 == V_301 ) ||
( V_132 == V_179 ) ||
( V_132 == V_266 ) ||
( V_132 == V_174 ) ) {
V_2 -> V_408 = 0x40 ;
}
if( V_2 -> V_378 == 350 ) V_2 -> V_58 |= V_178 ;
V_2 -> V_397 = V_462 ;
V_2 -> V_399 = V_463 ;
if( V_2 -> V_35 & V_85 ) {
if( V_2 -> V_58 & V_178 ) {
V_2 -> V_397 = V_464 ;
V_2 -> V_399 = V_465 ;
}
}
} else if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_59 ) {
V_2 -> V_397 = 1650 ;
V_2 -> V_399 = 750 ;
} else if( V_2 -> V_58 & V_165 ) {
V_2 -> V_397 = V_466 ;
if( V_2 -> V_58 & V_180 ) V_2 -> V_397 = V_467 ;
V_2 -> V_399 = V_468 ;
} else {
V_2 -> V_397 = V_466 ;
if( V_2 -> V_58 & V_181 ) V_2 -> V_397 = V_467 ;
V_2 -> V_399 = V_468 ;
}
} else {
V_2 -> V_410 = ( V_438 + V_383 ) -> V_469 ;
V_2 -> V_411 = ( V_438 + V_383 ) -> V_470 ;
V_2 -> V_412 = ( V_438 + V_383 ) -> V_471 ;
V_2 -> V_413 = ( V_438 + V_383 ) -> V_472 ;
if( V_66 & V_75 ) {
V_2 -> V_410 = 0x00 ;
V_2 -> V_411 = 0xf4 ;
V_2 -> V_412 = 0x10 ;
V_2 -> V_413 = 0x38 ;
}
if( ! ( V_2 -> V_58 & V_157 ) ) {
V_2 -> V_397 = V_466 ;
if( V_2 -> V_58 & V_181 ) V_2 -> V_397 = V_467 ;
V_2 -> V_399 = V_468 ;
} else {
V_2 -> V_397 = V_473 ;
V_2 -> V_399 = V_474 ;
}
}
} else if( V_2 -> V_35 & V_43 ) {
V_2 -> V_389 = 1 ;
V_2 -> V_390 = 1 ;
if( V_2 -> V_133 ) {
V_2 -> V_377 = V_2 -> V_376 ;
V_2 -> V_379 = V_2 -> V_378 ;
V_130 = V_2 -> V_276 ;
if( V_66 & V_75 ) V_130 <<= 1 ;
V_2 -> V_396 = V_2 -> V_397 = V_130 ;
V_2 -> V_398 = V_2 -> V_399 = V_2 -> V_277 ;
} else {
bool V_475 = false ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
V_2 -> V_396 = V_2 -> V_190 ;
V_2 -> V_398 = V_2 -> V_192 ;
V_2 -> V_397 = V_2 -> V_190 ;
V_2 -> V_399 = V_2 -> V_192 ;
V_475 = true ;
} else if( ( ! ( V_2 -> V_46 & V_47 ) ) && ( V_23 ) && ( V_11 ) ) {
#ifdef V_95
V_2 -> V_389 = V_11 [ V_23 ] ;
V_2 -> V_390 = V_11 [ V_23 + 1 ] ;
V_2 -> V_396 = V_11 [ V_23 + 2 ] | ( ( V_11 [ V_23 + 3 ] & 0x0f ) << 8 ) ;
V_2 -> V_398 = ( V_11 [ V_23 + 4 ] << 4 ) | ( ( V_11 [ V_23 + 3 ] & 0xf0 ) >> 4 ) ;
V_2 -> V_397 = V_11 [ V_23 + 5 ] | ( ( V_11 [ V_23 + 6 ] & 0x0f ) << 8 ) ;
V_2 -> V_399 = ( V_11 [ V_23 + 7 ] << 4 ) | ( ( V_11 [ V_23 + 6 ] & 0xf0 ) >> 4 ) ;
V_2 -> V_414 = V_11 [ V_23 + 8 ] | ( ( V_11 [ V_23 + 9 ] & 0x0f ) << 8 ) ;
if( ( V_2 -> V_414 ) && ( V_66 & V_75 ) ) {
V_2 -> V_414 = ( ( V_2 -> V_414 + 3 ) >> 1 ) - 3 ;
V_130 = ( V_11 [ V_23 + 9 ] >> 4 ) & 0x07 ;
if( V_11 [ V_23 + 9 ] & 0x80 ) V_2 -> V_414 -= V_130 ;
else V_2 -> V_414 += V_130 ;
}
if( V_2 -> V_396 ) V_475 = true ;
else {
V_2 -> V_46 |= V_47 ;
V_2 -> V_46 &= ~ V_48 ;
V_2 -> V_389 = 1 ;
V_2 -> V_390 = 1 ;
V_2 -> V_396 = V_2 -> V_190 ;
V_2 -> V_398 = V_2 -> V_192 ;
V_2 -> V_397 = V_2 -> V_190 ;
V_2 -> V_399 = V_2 -> V_192 ;
V_2 -> V_414 = 0 ;
V_475 = true ;
}
#endif
}
if( ! V_475 ) {
F_64 ( V_2 , V_25 , V_26 , V_319 ,
& V_320 , & V_383 ) ;
switch( V_320 ) {
case V_238 : V_436 = V_2 -> V_476 ; break;
case V_238 + 32 : V_436 = V_2 -> V_477 ; break;
case V_256 :
case V_256 + 32 : V_436 = V_2 -> V_478 ; break;
case V_184 : V_436 = V_2 -> V_479 ; break;
case V_184 + 32 : V_436 = V_2 -> V_480 ; break;
case V_187 :
case V_187 + 32 : V_436 = V_2 -> V_481 ; break;
case V_186 :
case V_186 + 32 : V_436 = V_2 -> V_482 ; break;
case V_188 :
case V_188 + 32 : V_436 = V_2 -> V_483 ; break;
case V_233 :
case V_233 + 32 : V_436 = V_2 -> V_484 ; break;
case V_239 : V_436 = V_2 -> V_485 ; break;
case V_239 + 32 : V_436 = V_2 -> V_486 ; break;
case V_240 : V_436 = V_2 -> V_487 ; break;
case V_240 + 32 : V_436 = V_2 -> V_488 ; break;
case V_241 : V_436 = V_2 -> V_489 ; break;
case V_241 + 32 : V_436 = V_2 -> V_490 ; break;
case V_242 :
case V_242 + 32 : V_436 = V_2 -> V_491 ; break;
case 100 : V_436 = V_2 -> V_400 ; break;
#ifdef V_95
case 200 : V_436 = V_492 ; break;
case 201 : V_436 = V_2 -> V_486 ; break;
#endif
default : V_436 = V_2 -> V_476 ; break;
}
V_2 -> V_389 = ( V_436 + V_383 ) -> V_454 ;
V_2 -> V_390 = ( V_436 + V_383 ) -> V_455 ;
V_2 -> V_396 = ( V_436 + V_383 ) -> V_401 ;
V_2 -> V_398 = ( V_436 + V_383 ) -> V_402 ;
V_2 -> V_397 = ( V_436 + V_383 ) -> V_403 ;
V_2 -> V_399 = ( V_436 + V_383 ) -> V_404 ;
}
V_130 = V_2 -> V_247 ;
V_131 = V_2 -> V_248 ;
switch( V_2 -> V_183 ) {
case V_238 :
if( V_2 -> V_77 & V_318 ) {
if( V_2 -> V_3 < V_5 ) {
if ( V_2 -> V_378 == 350 ) V_131 = 560 ;
else if( V_2 -> V_378 == 400 ) V_131 = 640 ;
}
} else {
if ( V_2 -> V_378 == 357 ) V_131 = 527 ;
else if( V_2 -> V_378 == 420 ) V_131 = 620 ;
else if( V_2 -> V_378 == 525 ) V_131 = 775 ;
else if( V_2 -> V_378 == 600 ) V_131 = 775 ;
else if( V_2 -> V_378 == 350 ) V_131 = 560 ;
else if( V_2 -> V_378 == 400 ) V_131 = 640 ;
}
break;
case V_233 :
if ( V_2 -> V_378 == 350 ) V_131 = 700 ;
else if( V_2 -> V_378 == 400 ) V_131 = 800 ;
else if( V_2 -> V_378 == 1024 ) V_131 = 960 ;
break;
case V_239 :
if ( V_2 -> V_378 == 360 ) V_131 = 768 ;
else if( V_2 -> V_378 == 375 ) V_131 = 800 ;
else if( V_2 -> V_378 == 405 ) V_131 = 864 ;
break;
case V_241 :
if( ! ( V_2 -> V_77 & V_318 ) ) {
if ( V_2 -> V_378 == 350 ) V_131 = 875 ;
else if( V_2 -> V_378 == 400 ) V_131 = 1000 ;
}
break;
}
if( V_2 -> V_46 & V_47 ) {
V_130 = V_2 -> V_376 ;
V_131 = V_2 -> V_378 ;
}
V_2 -> V_377 = V_130 ;
V_2 -> V_379 = V_131 ;
}
}
}
static void
F_72 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_44 ) {
F_69 ( V_2 , V_25 , V_26 , V_319 ) ;
} else {
if( ( V_2 -> V_18 & V_79 ) && ( V_2 -> V_35 & V_43 ) ) {
F_69 ( V_2 , V_25 , V_26 , V_319 ) ;
} else {
F_71 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
} else {
F_69 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
static const struct V_493 *
F_73 ( struct V_1 * V_2 )
{
const struct V_493 * V_494 = NULL ;
#ifdef V_94
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_211 == 4 ) {
if( V_2 -> V_105 == V_224 ) {
V_494 = V_2 -> V_495 ;
if( V_2 -> V_46 & V_47 ) {
V_494 = V_2 -> V_496 ;
}
} else if( V_2 -> V_105 == V_293 ) {
V_494 = V_2 -> V_497 ;
if( V_2 -> V_46 & V_47 ) {
V_494 = V_2 -> V_498 ;
}
}
}
}
}
#endif
return V_494 ;
}
static void
F_74 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_66 , V_383 ;
const struct V_493 * V_494 = NULL ;
V_2 -> V_499 = 0 ;
V_2 -> V_500 = 0 ;
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_312 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_378 == V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
}
}
return;
}
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_183 == V_234 && V_2 -> V_211 == 3 ) {
V_2 -> V_499 = 8 ;
if ( V_2 -> V_378 >= 480 ) V_2 -> V_500 = 512 ;
else if( V_2 -> V_378 >= 400 ) V_2 -> V_500 = 436 ;
else if( V_2 -> V_378 >= 350 ) V_2 -> V_500 = 440 ;
return;
}
}
}
if( ( V_2 -> V_133 ) ||
( V_2 -> V_183 == V_273 ) ||
( V_2 -> V_105 == V_226 ) ||
( V_2 -> V_105 == V_228 ) ||
( V_2 -> V_46 & V_48 ) ) {
return;
}
if( V_25 <= 0x13 ) V_383 = V_2 -> V_71 [ V_26 ] . V_326 ;
else V_383 = V_2 -> V_32 [ V_319 ] . V_328 ;
if( ( V_2 -> V_18 & V_39 ) && ( V_2 -> V_35 & V_44 ) ) {
#ifdef V_95
if( V_2 -> V_46 & V_47 ) {
if( V_2 -> V_376 != V_2 -> V_247 ) {
V_2 -> V_499 = V_2 -> V_397 - ( ( V_2 -> V_247 - V_2 -> V_376 ) / 2 ) ;
}
if( V_2 -> V_378 != V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_399 - ( ( V_2 -> V_248 - V_2 -> V_378 ) / 2 ) ;
}
}
if( V_2 -> V_378 == V_2 -> V_248 ) {
switch( V_2 -> V_105 ) {
case V_501 :
case V_502 :
case V_106 :
if( V_2 -> V_183 == V_238 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
}
break;
}
switch( V_2 -> V_183 ) {
case V_239 :
if( V_2 -> V_105 != V_107 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
}
break;
case V_187 :
case V_186 :
case V_188 :
V_2 -> V_500 = V_2 -> V_192 - 1 ;
break;
}
}
#endif
} else {
if( ( V_2 -> V_61 != 0 ) && ( V_2 -> V_35 & V_62 ) ) {
if( ( V_2 -> V_58 & V_157 ) && ( ! ( V_2 -> V_58 & V_160 ) ) ) {
if( V_383 <= 3 ) V_2 -> V_499 = 256 ;
}
} else if( ( V_494 = F_73 ( V_2 ) ) ) {
V_2 -> V_499 = ( V_494 + V_383 ) -> V_503 ;
V_2 -> V_500 = ( V_494 + V_383 ) -> V_504 ;
} else if( V_2 -> V_46 & V_47 ) {
if( V_2 -> V_376 != V_2 -> V_247 ) {
V_2 -> V_499 = V_2 -> V_397 - ( ( V_2 -> V_247 - V_2 -> V_376 ) / 2 ) ;
}
if( V_2 -> V_378 != V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_399 - ( ( V_2 -> V_248 - V_2 -> V_378 ) / 2 ) ;
} else {
if( V_2 -> V_3 < V_5 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
} else {
switch( V_2 -> V_183 ) {
case V_250 :
case V_238 :
case V_239 :
V_2 -> V_500 = V_2 -> V_192 ;
break;
case V_240 :
V_2 -> V_500 = V_2 -> V_192 - 1 ;
break;
}
}
}
} else {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
switch( V_2 -> V_183 ) {
case V_250 :
if( V_2 -> V_378 == V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
} else {
V_2 -> V_499 = V_2 -> V_190 + 3 ;
V_2 -> V_500 = V_2 -> V_192 ;
if( V_2 -> V_378 == 400 ) V_2 -> V_500 -= 2 ;
else V_2 -> V_500 -= 4 ;
}
break;
case V_238 :
if( V_2 -> V_378 == V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
} else {
V_2 -> V_499 = V_2 -> V_190 - 1 ;
if( V_2 -> V_378 <= 400 ) V_2 -> V_500 = V_2 -> V_192 - 8 ;
if( V_2 -> V_378 <= 350 ) V_2 -> V_500 = V_2 -> V_192 - 12 ;
}
break;
case V_252 :
default:
if( ( V_2 -> V_376 == V_2 -> V_247 ) &&
( V_2 -> V_378 == V_2 -> V_248 ) ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
} else {
V_2 -> V_499 = V_2 -> V_190 - 1 ;
}
break;
}
switch( V_2 -> V_211 ) {
case 1 :
V_2 -> V_499 = V_2 -> V_500 = 0 ;
break;
case 3 :
V_2 -> V_499 = 8 ;
if ( V_2 -> V_378 >= 480 ) V_2 -> V_500 = 512 ;
else if( V_2 -> V_378 >= 400 ) V_2 -> V_500 = 436 ;
else if( V_2 -> V_378 >= 350 ) V_2 -> V_500 = 440 ;
break;
}
#endif
} else {
#ifdef V_95
switch( V_2 -> V_183 ) {
case V_238 :
case V_239 :
if( V_2 -> V_378 == V_2 -> V_248 ) {
V_2 -> V_500 = V_2 -> V_192 - 1 ;
}
break;
case V_232 :
case V_218 :
case V_221 :
V_2 -> V_500 = 524 ;
break;
}
#endif
}
}
if( ( V_25 <= 0x13 ) && ( V_2 -> V_46 & V_47 ) ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
if( ( V_2 -> V_18 & V_39 ) && ( V_2 -> V_35 & V_44 ) ) {
if( ! ( V_66 & V_75 ) ) V_2 -> V_499 = 632 ;
} else if( ! ( V_2 -> V_77 & V_311 ) ) {
if( V_2 -> V_183 != V_239 ) {
if( V_2 -> V_183 >= V_238 ) {
if( V_2 -> V_3 < V_5 ) {
if( ! ( V_66 & V_75 ) ) V_2 -> V_499 = 320 ;
} else {
#ifdef V_95
if( V_2 -> V_183 == V_238 ) V_2 -> V_499 = 480 ;
if( V_2 -> V_183 == V_240 ) V_2 -> V_499 = 804 ;
if( V_2 -> V_183 == V_241 ) V_2 -> V_499 = 704 ;
if( ! ( V_66 & V_75 ) ) {
V_2 -> V_499 = 320 ;
if( V_2 -> V_183 == V_240 ) V_2 -> V_499 = 632 ;
if( V_2 -> V_183 == V_241 ) V_2 -> V_499 = 542 ;
}
#endif
}
}
}
}
}
}
}
static int
F_75 ( struct V_1 * V_2 )
{
int V_505 = 0 ;
#ifdef F_76
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 = F_10 ( V_2 ) ;
unsigned char V_506 = F_8 ( V_2 -> V_21 , 0x31 ) & 0x40 ;
unsigned short V_68 ;
if( ( V_2 -> V_18 & V_507 ) &&
( V_23 ) &&
( V_2 -> V_508 ) ) {
F_15 ( V_2 -> V_114 , 0x2b , V_11 [ V_23 + V_2 -> V_508 + 0 ] ) ;
F_15 ( V_2 -> V_114 , 0x2c , V_11 [ V_23 + V_2 -> V_508 + 1 ] ) ;
F_15 ( V_2 -> V_114 , 0x2d , V_11 [ V_23 + V_2 -> V_508 + 2 ] ) ;
F_15 ( V_2 -> V_114 , 0x2e , V_11 [ V_23 + V_2 -> V_508 + 3 ] ) ;
F_15 ( V_2 -> V_114 , 0x2f , V_11 [ V_23 + V_2 -> V_508 + 4 ] ) ;
V_68 = 0x00 ;
if( ( V_11 [ V_23 + 2 ] & ( 0x06 << 1 ) ) && ! V_506 ) {
V_68 = 0x80 ;
V_505 = 1 ;
}
F_6 ( V_2 -> V_114 , 0x27 , 0x7f , V_68 ) ;
}
#endif
return V_505 ;
}
void
F_77 ( struct V_1 * V_2 )
{
#ifdef V_95
unsigned short V_362 , V_509 = 0 , V_510 ;
#endif
unsigned short V_68 = 0 ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_18 & V_39 ) {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( ! ( F_16 ( V_2 ) ) ) {
if( V_2 -> V_18 & V_19 ) {
F_4 ( V_2 -> V_114 , 0x26 , 0xFE ) ;
} else {
F_5 ( V_2 , 0xF7 , 0x08 ) ;
}
F_22 ( V_2 , 3 ) ;
}
if( F_31 ( V_2 ) ) {
F_4 ( V_2 -> V_114 , 0x1f , 0x3f ) ;
F_21 ( V_2 , 1 ) ;
}
F_4 ( V_2 -> V_121 , 0x00 , 0xDF ) ;
F_78 ( V_2 ) ;
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
F_4 ( V_2 -> V_10 , 0x1E , 0xDF ) ;
F_1 ( V_2 ) ;
if( ! ( V_2 -> V_18 & V_19 ) ) {
F_2 ( V_2 -> V_6 , 0x01 , 0x80 ) ;
F_2 ( V_2 -> V_6 , 0x02 , 0x40 ) ;
}
if( ( ! ( F_32 ( V_2 ) ) ) ||
( ! ( F_17 ( V_2 ) ) ) ) {
F_22 ( V_2 , 2 ) ;
if( V_2 -> V_18 & V_19 ) {
F_4 ( V_2 -> V_114 , 0x26 , 0xFD ) ;
} else {
F_5 ( V_2 , 0xFB , 0x04 ) ;
}
}
#endif
} else {
#ifdef V_95
int V_511 = 0 ;
bool V_512 = ( V_2 -> V_105 == V_107 ) ||
( V_2 -> V_105 == V_106 ) ;
V_510 = F_8 ( V_2 -> V_21 , 0x34 ) & 0x7f ;
if( V_2 -> V_18 & V_19 ) {
#ifdef F_79
if( V_2 -> V_18 & V_513 ) {
if( V_2 -> V_105 != V_106 ) {
F_4 ( V_2 -> V_114 , 0x30 , 0x0c ) ;
}
}
#endif
V_511 = F_75 ( V_2 ) ;
if( ( V_510 <= 0x13 ) ||
( F_34 ( V_2 ) ) ||
( ! ( F_33 ( V_2 ) ) ) ) {
if( ! V_511 ) {
F_4 ( V_2 -> V_114 , 0x26 , 0xfe ) ;
if( V_512 ) F_22 ( V_2 , 3 ) ;
} else {
F_4 ( V_2 -> V_114 , 0x26 , 0xfc ) ;
}
}
if( ! V_512 ) {
F_18 ( V_2 , 0xff00 ) ;
F_18 ( V_2 , 0xe000 ) ;
F_80 ( V_2 -> V_514 , 0x00 ) ;
V_509 = F_8 ( V_2 -> V_10 , 0x06 ) ;
if( V_367 ) {
F_4 ( V_2 -> V_10 , 0x06 , 0xE3 ) ;
}
F_22 ( V_2 , 3 ) ;
}
}
if( ! ( F_40 ( V_2 ) ) ) {
V_362 = 0xef ;
if( F_34 ( V_2 ) ) V_362 = 0xf7 ;
F_4 ( V_2 -> V_6 , 0x4c , V_362 ) ;
}
if( V_2 -> V_18 & V_19 ) {
F_4 ( V_2 -> V_114 , 0x1F , ~ 0x10 ) ;
}
V_362 = 0x3f ;
if( F_33 ( V_2 ) ) {
V_362 = 0x7f ;
if( ! ( F_34 ( V_2 ) ) ) V_362 = 0xbf ;
}
F_4 ( V_2 -> V_114 , 0x1F , V_362 ) ;
if( ( F_34 ( V_2 ) ) ||
( ( V_2 -> V_18 & V_19 ) && ( V_510 <= 0x13 ) ) ) {
F_78 ( V_2 ) ;
if( V_2 -> V_18 & V_19 ) {
F_22 ( V_2 , 2 ) ;
}
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
F_4 ( V_2 -> V_6 , 0x1E , 0xDF ) ;
}
if( ( ! ( F_34 ( V_2 ) ) ) ||
( ( V_2 -> V_18 & V_19 ) && ( V_510 <= 0x13 ) ) ) {
if( ! ( F_33 ( V_2 ) ) ) {
F_4 ( V_2 -> V_121 , 0x00 , 0xdf ) ;
F_78 ( V_2 ) ;
}
F_2 ( V_2 -> V_6 , 0x00 , 0x80 ) ;
if( V_2 -> V_18 & V_19 ) {
F_22 ( V_2 , 2 ) ;
}
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
V_68 = F_8 ( V_2 -> V_6 , 0x00 ) ;
F_2 ( V_2 -> V_6 , 0x00 , 0x10 ) ;
F_4 ( V_2 -> V_10 , 0x1E , 0xDF ) ;
F_15 ( V_2 -> V_6 , 0x00 , V_68 ) ;
}
if( F_40 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x2e , 0x7f ) ;
}
if( V_2 -> V_18 & V_19 ) {
if( ( ! ( F_34 ( V_2 ) ) ) &&
( ! ( F_32 ( V_2 ) ) ) &&
( ! ( F_33 ( V_2 ) ) ) ) {
if( V_512 ) F_22 ( V_2 , 2 ) ;
if( ! V_511 ) {
F_4 ( V_2 -> V_114 , 0x26 , 0xFD ) ;
}
if( V_512 ) F_22 ( V_2 , 4 ) ;
}
if( ! V_512 ) {
F_15 ( V_2 -> V_10 , 0x06 , V_509 ) ;
if( V_2 -> V_18 & V_513 ) {
if( F_35 ( V_2 ) ) {
F_24 ( V_2 , 3 , 20 ) ;
}
}
}
}
#endif
}
} else {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( ! ( F_16 ( V_2 ) ) ) {
F_5 ( V_2 , 0xF7 , 0x08 ) ;
F_22 ( V_2 , 3 ) ;
}
#endif
}
F_4 ( V_2 -> V_121 , 0x00 , 0xDF ) ;
F_78 ( V_2 ) ;
if( V_2 -> V_3 >= V_5 ) {
F_2 ( V_2 -> V_6 , 0x00 , 0x80 ) ;
}
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
if( V_2 -> V_3 >= V_5 ) {
V_68 = F_8 ( V_2 -> V_6 , 0x00 ) ;
F_2 ( V_2 -> V_6 , 0x00 , 0x10 ) ;
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_15 ( V_2 -> V_6 , 0x00 , V_68 ) ;
} else {
#ifdef V_94
F_4 ( V_2 -> V_10 , 0x1E , 0xDF ) ;
if( ( ! ( F_32 ( V_2 ) ) ) ||
( ! ( F_17 ( V_2 ) ) ) ) {
F_22 ( V_2 , 2 ) ;
F_5 ( V_2 , 0xFB , 0x04 ) ;
}
#endif
}
}
} else {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( V_2 -> V_61 == 1 ) {
F_81 ( V_2 , 0x0E , 0x09 ) ;
}
if( V_2 -> V_3 == V_115 ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x11 ) & 0x08 ) ) {
F_28 ( V_2 ) ;
}
if( ! ( F_16 ( V_2 ) ) ) {
F_5 ( V_2 , 0xF7 , 0x08 ) ;
F_22 ( V_2 , 3 ) ;
}
} else {
if( ! ( F_8 ( V_2 -> V_10 , 0x11 ) & 0x08 ) ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x13 ) & 0x40 ) ) {
if( ! ( F_16 ( V_2 ) ) ) {
F_28 ( V_2 ) ;
if( ! ( F_8 ( V_2 -> V_10 , 0x06 ) & 0x1c ) ) {
F_78 ( V_2 ) ;
}
F_5 ( V_2 , 0xF7 , 0x08 ) ;
F_22 ( V_2 , 3 ) ;
}
}
}
}
F_78 ( V_2 ) ;
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
F_4 ( V_2 -> V_10 , 0x1E , 0xDF ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_6 , 0x01 , 0x80 ) ;
F_2 ( V_2 -> V_6 , 0x02 , 0x40 ) ;
if( ( ! ( F_32 ( V_2 ) ) ) ||
( ! ( F_17 ( V_2 ) ) ) ) {
F_22 ( V_2 , 2 ) ;
F_5 ( V_2 , 0xFB , 0x04 ) ;
}
#endif
} else {
#ifdef V_95
if( ! ( F_40 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , 0x4c , ~ 0x18 ) ;
}
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_3 == V_515 ) {
V_68 = F_82 ( V_2 , 0x61 ) ;
if( V_68 < 1 ) {
F_83 ( V_2 , 0x76 , 0xac ) ;
F_83 ( V_2 , 0x66 , 0x00 ) ;
}
if( ( ! ( F_33 ( V_2 ) ) ) ||
( F_43 ( V_2 ) ) ) {
F_83 ( V_2 , 0x49 , 0x3e ) ;
}
}
if( ( ! ( F_33 ( V_2 ) ) ) ||
( F_34 ( V_2 ) ) ) {
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
}
if( V_2 -> V_3 != V_515 ) {
if( ( ! ( F_33 ( V_2 ) ) ) ||
( F_43 ( V_2 ) ) ) {
F_83 ( V_2 , 0x49 , 0x01 ) ;
}
}
}
if( V_2 -> V_61 == 0 ) {
F_5 ( V_2 , 0xF7 , 0x08 ) ;
F_22 ( V_2 , 3 ) ;
}
if( ( V_2 -> V_61 == 0 ) ||
( ! ( F_33 ( V_2 ) ) ) ||
( ! ( F_43 ( V_2 ) ) ) ) {
F_78 ( V_2 ) ;
}
if( ( V_2 -> V_61 == 0 ) ||
( ! ( F_33 ( V_2 ) ) ) ||
( ! ( F_34 ( V_2 ) ) ) ) {
F_2 ( V_2 -> V_6 , 0x00 , 0x80 ) ;
}
if( V_2 -> V_3 == V_515 ) {
F_4 ( V_2 -> V_6 , 0x2e , 0x7f ) ;
}
F_4 ( V_2 -> V_10 , 0x32 , 0xDF ) ;
if( ( V_2 -> V_61 == 0 ) ||
( ! ( F_33 ( V_2 ) ) ) ||
( ! ( F_34 ( V_2 ) ) ) ) {
F_4 ( V_2 -> V_10 , 0x1E , 0xDF ) ;
}
if( V_2 -> V_61 == 0 ) {
if( F_32 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x1e , 0xdf ) ;
if( V_2 -> V_3 == V_216 ) {
F_4 ( V_2 -> V_6 , 0x1e , 0xbf ) ;
F_4 ( V_2 -> V_6 , 0x1e , 0xef ) ;
}
}
} else {
if( V_2 -> V_3 == V_515 ) {
if( F_44 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x1e , 0xdf ) ;
}
} else if( F_34 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x1e , 0xdf ) ;
}
}
if( V_2 -> V_61 != 0 ) {
if( F_33 ( V_2 ) ) {
} else {
F_4 ( V_2 -> V_6 , 0x13 , 0xfb ) ;
}
}
F_1 ( V_2 ) ;
if( V_2 -> V_3 == V_216 ) {
F_2 ( V_2 -> V_6 , 0x01 , 0x80 ) ;
F_2 ( V_2 -> V_6 , 0x02 , 0x40 ) ;
} else if( ( V_2 -> V_61 == 0 ) ||
( ! ( F_33 ( V_2 ) ) ) ||
( ! ( F_34 ( V_2 ) ) ) ) {
F_4 ( V_2 -> V_6 , 0x2e , 0xf7 ) ;
}
if( V_2 -> V_61 == 0 ) {
if( F_32 ( V_2 ) ) {
if( ! ( F_39 ( V_2 ) ) ) {
F_22 ( V_2 , 2 ) ;
F_5 ( V_2 , 0xFB , 0x04 ) ;
}
}
}
#endif
}
}
}
static
void
F_86 ( struct V_1 * V_2 )
{
unsigned short V_68 = 0 , V_362 ;
#ifdef V_95
unsigned short V_88 , V_509 = 0 ;
bool V_516 = false ;
#endif
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_18 & V_39 ) {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( F_32 ( V_2 ) ) {
if( V_2 -> V_18 & V_19 ) {
F_2 ( V_2 -> V_114 , 0x26 , 0x02 ) ;
} else if( V_2 -> V_18 & V_79 ) {
F_5 ( V_2 , 0xFB , 0x00 ) ;
}
if( V_2 -> V_18 & ( V_19 | V_79 ) ) {
if( ! ( F_17 ( V_2 ) ) ) {
F_22 ( V_2 , 0 ) ;
}
}
}
if( ( V_2 -> V_18 & V_79 ) &&
( F_32 ( V_2 ) ) ) {
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_87 ( V_2 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_6 , 0x02 , 0xBF ) ;
if( F_47 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x01 , 0x1F ) ;
} else {
F_6 ( V_2 -> V_6 , 0x01 , 0x1F , 0x40 ) ;
}
if( ! ( F_8 ( V_2 -> V_10 , 0x13 ) & 0x40 ) ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x16 ) & 0x10 ) ) {
if( ! ( F_16 ( V_2 ) ) ) {
F_22 ( V_2 , 1 ) ;
}
F_28 ( V_2 ) ;
F_5 ( V_2 , 0xF7 , 0x00 ) ;
}
}
} else {
V_68 = F_8 ( V_2 -> V_10 , 0x32 ) & 0xDF ;
if( F_47 ( V_2 ) ) {
V_362 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( ! ( V_362 & V_36 ) ) V_68 |= 0x20 ;
}
F_15 ( V_2 -> V_10 , 0x32 , V_68 ) ;
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_6 ( V_2 -> V_121 , 0x00 , 0x1F , 0x20 ) ;
F_2 ( V_2 -> V_114 , 0x1F , 0xC0 ) ;
F_87 ( V_2 ) ;
if( V_2 -> V_18 & V_19 ) {
if( F_32 ( V_2 ) ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x16 ) & 0x10 ) ) {
if( ! ( F_16 ( V_2 ) ) ) {
F_22 ( V_2 , 1 ) ;
}
F_2 ( V_2 -> V_114 , 0x26 , 0x01 ) ;
}
}
}
}
#endif
} else {
#ifdef V_95
#ifdef F_79
unsigned char V_517 = 0 , V_518 = 0 , V_519 = 0 , V_520 = 0 , V_521 = 0 ;
int V_511 = 0 ;
#endif
if( V_2 -> V_18 & V_19 ) {
F_4 ( V_2 -> V_114 , 0x1f , 0xef ) ;
#ifdef F_79
if( V_2 -> V_18 & V_513 ) {
F_4 ( V_2 -> V_114 , 0x30 , 0x0c ) ;
}
#endif
}
if( ! ( F_40 ( V_2 ) ) ) {
V_362 = 0x10 ;
if( F_38 ( V_2 ) ) {
if( F_37 ( V_2 ) ) V_362 = 0x18 ;
else V_362 = 0x08 ;
}
F_15 ( V_2 -> V_6 , 0x4c , V_362 ) ;
}
if( V_2 -> V_18 & V_19 ) {
F_80 ( V_2 -> V_514 , 0x00 ) ;
F_78 ( V_2 ) ;
V_509 = F_8 ( V_2 -> V_10 , 0x06 ) ;
if( V_367 ) {
F_4 ( V_2 -> V_10 , 0x06 , 0xE3 ) ;
}
V_511 = F_75 ( V_2 ) ;
if( F_35 ( V_2 ) ) {
if( ! V_511 ) {
if( ! ( F_8 ( V_2 -> V_114 , 0x26 ) & 0x02 ) ) {
F_24 ( V_2 , 3 , 2 ) ;
F_2 ( V_2 -> V_114 , 0x26 , 0x02 ) ;
F_24 ( V_2 , 3 , 2 ) ;
if( V_2 -> V_18 & V_513 ) {
F_19 ( V_2 , 17664 ) ;
}
}
} else {
F_24 ( V_2 , 3 , 2 ) ;
if( V_2 -> V_18 & V_513 ) {
F_19 ( V_2 , 17664 ) ;
}
}
}
if( ! ( F_8 ( V_2 -> V_21 , 0x31 ) & 0x40 ) ) {
F_24 ( V_2 , 3 , 10 ) ;
V_516 = true ;
}
}
if( ! ( F_34 ( V_2 ) ) ) {
V_68 = F_8 ( V_2 -> V_10 , 0x32 ) & 0xDF ;
if( F_47 ( V_2 ) ) {
V_362 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( ! ( V_362 & V_36 ) ) {
if( ! ( F_38 ( V_2 ) ) ) V_68 |= 0x20 ;
}
}
F_15 ( V_2 -> V_10 , 0x32 , V_68 ) ;
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_4 ( V_2 -> V_6 , 0x2e , 0x7f ) ;
F_2 ( V_2 -> V_6 , 0x2e , 0x80 ) ;
if( V_2 -> V_18 & V_19 ) {
F_22 ( V_2 , 2 ) ;
}
} else {
F_2 ( V_2 -> V_6 , 0x1e , 0x20 ) ;
}
F_6 ( V_2 -> V_121 , 0x00 , 0x1f , 0x20 ) ;
F_2 ( V_2 -> V_6 , 0x2e , 0x80 ) ;
if( V_2 -> V_18 & V_522 ) {
if( ( F_38 ( V_2 ) ) ||
( F_32 ( V_2 ) ) ) {
F_4 ( V_2 -> V_114 , 0x2a , 0x7f ) ;
F_4 ( V_2 -> V_114 , 0x30 , 0x7f ) ;
}
}
V_362 = 0xc0 ;
if( F_33 ( V_2 ) ) {
V_362 = 0x80 ;
if( ! ( F_34 ( V_2 ) ) ) V_362 = 0x40 ;
}
F_2 ( V_2 -> V_114 , 0x1F , V_362 ) ;
if( V_2 -> V_18 & V_19 ) {
F_22 ( V_2 , 2 ) ;
F_2 ( V_2 -> V_114 , 0x1f , 0x10 ) ;
F_2 ( V_2 -> V_6 , 0x2e , 0x80 ) ;
if( V_2 -> V_105 != V_106 ) {
#ifdef F_79
if( V_2 -> V_18 & V_513 ) {
F_4 ( V_2 -> V_114 , 0x30 , 0x0c ) ;
F_19 ( V_2 , 2048 ) ;
}
#endif
F_2 ( V_2 -> V_114 , 0x27 , 0x0c ) ;
if( V_2 -> V_18 & V_513 ) {
#ifdef F_79
V_521 = F_8 ( V_2 -> V_21 , 0x36 ) ;
if( V_2 -> V_17 ) {
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 = F_10 ( V_2 ) ;
if( V_23 ) {
F_2 ( V_2 -> V_114 , 0x30 , 0x20 ) ;
V_2 -> V_523 = 0 ;
V_2 -> V_524 = V_11 [ V_23 + V_2 -> V_525 + 0 ] ;
V_2 -> V_526 = V_11 [ V_23 + V_2 -> V_525 + 1 ] ;
V_2 -> V_527 = V_11 [ V_23 + V_2 -> V_525 + 2 ] ;
if( V_11 [ V_23 + 1 ] & 0x10 ) V_2 -> V_523 = 0x40 ;
V_2 -> V_528 = V_2 -> V_529 = V_2 -> V_530 = true ;
}
}
if( V_2 -> V_528 ) {
V_517 = V_2 -> V_523 ; V_518 = V_2 -> V_524 ;
V_519 = V_2 -> V_526 ; V_520 = V_2 -> V_527 ;
} else {
V_517 = 0 ;
}
if( ( ! V_2 -> V_528 ) || ( ! V_2 -> V_529 ) ) {
switch( ( V_521 & 0x0f ) ) {
case 2 :
V_517 |= 0x40 ;
if( V_2 -> V_105 == V_237 ) V_517 &= ~ 0x40 ;
if( ! V_2 -> V_528 ) {
V_518 = 0x05 ; V_519 = 0x60 ; V_520 = 0x33 ;
if( ( V_521 & 0xf0 ) == 0x30 ) {
V_518 = 0x0d ; V_519 = 0x70 ; V_520 = 0x40 ;
}
}
break;
case 3 :
if( V_2 -> V_105 == V_107 ) V_517 |= 0x40 ;
if( ! V_2 -> V_528 ) {
V_518 = 0x12 ; V_519 = 0xd0 ; V_520 = 0x6b ;
if( V_2 -> V_105 == V_107 ) {
V_518 = 0x0d ; V_519 = 0x70 ; V_520 = 0x6b ;
}
}
break;
case 9 :
V_517 |= 0x40 ;
if( ! V_2 -> V_528 ) {
V_518 = 0x05 ; V_519 = 0x60 ; V_520 = 0x00 ;
if( V_2 -> V_105 == V_531 ) {
V_518 = 0x0d ; V_519 = 0x70 ; V_520 = 0x40 ;
}
}
break;
case 11 :
V_517 |= 0x40 ;
if( ! V_2 -> V_528 ) {
V_518 = 0x05 ; V_519 = 0x60 ; V_520 = 0x00 ;
}
}
}
if( ! V_2 -> V_530 ) {
#ifdef F_88
if( V_2 -> V_105 == V_531 ) {
if( ( V_521 & 0x0f ) == 0x09 ) {
V_517 = 0x60 ; V_518 = 0x05 ; V_519 = 0x60 ; V_520 = 0x00 ;
}
}
#endif
#ifdef F_89
if( V_2 -> V_105 == V_107 ) {
if( ( V_521 & 0x0f ) == 0x03 ) {
V_517 = 0x20 ; V_518 = 0x12 ; V_519 = 0xd0 ; V_520 = 0x6b ;
}
}
#endif
#ifdef F_90
if( V_2 -> V_105 == V_532 ) {
if( ( V_521 & 0x0f ) == 0x02 ) {
}
}
#endif
}
if( ! ( V_2 -> V_530 && ( ! V_517 ) && ( ! V_518 ) && ( ! V_519 ) && ( ! V_520 ) ) ) {
F_2 ( V_2 -> V_114 , 0x30 , 0x20 ) ;
F_19 ( V_2 , 2048 ) ;
}
F_15 ( V_2 -> V_114 , 0x31 , V_518 ) ;
F_15 ( V_2 -> V_114 , 0x32 , V_519 ) ;
F_15 ( V_2 -> V_114 , 0x33 , V_520 ) ;
#endif
F_15 ( V_2 -> V_114 , 0x34 , 0x10 ) ;
#ifdef F_79
if( ( F_38 ( V_2 ) ) ||
( F_32 ( V_2 ) ) ) {
if( V_517 & 0x40 ) {
F_24 ( V_2 , 3 , 5 ) ;
if( V_516 ) {
F_24 ( V_2 , 3 , 5 ) ;
V_516 = false ;
}
F_28 ( V_2 ) ;
F_28 ( V_2 ) ;
if( V_2 -> V_105 == V_532 ) {
F_19 ( V_2 , 1280 ) ;
}
F_2 ( V_2 -> V_114 , 0x30 , 0x40 ) ;
}
}
#endif
}
}
if( ! ( F_39 ( V_2 ) ) ) {
if( F_35 ( V_2 ) ) {
F_24 ( V_2 , 3 , 10 ) ;
if( V_516 ) {
F_24 ( V_2 , 3 , 10 ) ;
}
F_28 ( V_2 ) ;
if( V_2 -> V_18 & V_513 ) {
F_19 ( V_2 , 2048 ) ;
F_28 ( V_2 ) ;
}
if( ! V_511 ) {
F_2 ( V_2 -> V_114 , 0x26 , 0x01 ) ;
} else {
F_2 ( V_2 -> V_114 , 0x26 , 0x03 ) ;
}
}
}
F_15 ( V_2 -> V_10 , 0x06 , V_509 ) ;
F_87 ( V_2 ) ;
F_80 ( V_2 -> V_514 , 0xff ) ;
}
if( ! ( F_39 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , 0x00 , 0x7f ) ;
}
#endif
}
} else {
if( V_2 -> V_3 < V_5 ) {
if( F_32 ( V_2 ) ) {
F_5 ( V_2 , 0xFB , 0x00 ) ;
F_22 ( V_2 , 0 ) ;
}
}
V_68 = F_8 ( V_2 -> V_10 , 0x32 ) & 0xDF ;
if( F_47 ( V_2 ) ) {
V_362 = F_8 ( V_2 -> V_21 , 0x30 ) ;
if( ! ( V_362 & V_36 ) ) V_68 |= 0x20 ;
}
F_15 ( V_2 -> V_10 , 0x32 , V_68 ) ;
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
if( V_2 -> V_3 >= V_5 ) {
V_68 = F_8 ( V_2 -> V_6 , 0x2E ) ;
if( ! ( V_68 & 0x80 ) ) {
F_2 ( V_2 -> V_6 , 0x2E , 0x80 ) ;
}
}
F_6 ( V_2 -> V_121 , 0x00 , 0x1F , 0x20 ) ;
F_30 ( V_2 ) ;
F_87 ( V_2 ) ;
if( V_2 -> V_3 >= V_5 ) {
F_4 ( V_2 -> V_6 , 0x00 , 0x7f ) ;
}
F_30 ( V_2 ) ;
if( V_2 -> V_3 < V_5 ) {
if( F_32 ( V_2 ) ) {
F_22 ( V_2 , 1 ) ;
F_5 ( V_2 , 0xF7 , 0x00 ) ;
}
}
}
} else {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( F_32 ( V_2 ) ) {
if( V_2 -> V_3 == V_115 ) {
F_22 ( V_2 , 1 ) ;
F_22 ( V_2 , 1 ) ;
F_22 ( V_2 , 1 ) ;
}
F_5 ( V_2 , 0xFB , 0x00 ) ;
if( ! ( F_17 ( V_2 ) ) ) {
F_22 ( V_2 , 0 ) ;
}
}
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_87 ( V_2 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_6 , 0x02 , 0xBF ) ;
if( F_47 ( V_2 ) ) {
F_4 ( V_2 -> V_6 , 0x01 , 0x1F ) ;
} else {
F_6 ( V_2 -> V_6 , 0x01 , 0x1F , 0x40 ) ;
}
if( V_2 -> V_61 == 1 ) {
if( ! ( F_32 ( V_2 ) ) ) {
F_28 ( V_2 ) ;
F_81 ( V_2 , 0x0E , 0x0B ) ;
}
}
if( F_32 ( V_2 ) ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x13 ) & 0x40 ) ) {
if( ! ( F_8 ( V_2 -> V_10 , 0x16 ) & 0x10 ) ) {
if( ! ( F_16 ( V_2 ) ) ) {
F_22 ( V_2 , 1 ) ;
F_22 ( V_2 , 1 ) ;
}
F_28 ( V_2 ) ;
F_5 ( V_2 , 0xF7 , 0x00 ) ;
}
}
}
#endif
} else {
#ifdef V_95
if( ! ( F_40 ( V_2 ) ) ) {
F_2 ( V_2 -> V_6 , 0x4c , 0x18 ) ;
}
if( V_2 -> V_61 == 0 ) {
if( F_32 ( V_2 ) ) {
F_5 ( V_2 , 0xFB , 0x00 ) ;
F_22 ( V_2 , 0 ) ;
}
}
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_6 , 0x2e , 0xf7 ) ;
if( V_2 -> V_61 == 2 ) {
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 &= 0x20 ;
F_84 ( V_2 ) ;
}
if( V_2 -> V_3 != V_216 ) {
F_4 ( V_2 -> V_6 , 0x2e , 0x7f ) ;
}
if( V_2 -> V_3 == V_515 ) {
if( V_2 -> V_61 == 2 ) {
if( F_44 ( V_2 ) ) {
F_2 ( V_2 -> V_6 , 0x1E , 0x20 ) ;
}
}
}
V_88 = F_8 ( V_2 -> V_6 , 0x2E ) ;
if( ! ( V_88 & 0x80 ) ) {
F_2 ( V_2 -> V_6 , 0x2E , 0x80 ) ;
}
if( V_2 -> V_61 == 2 ) {
if( V_68 ) {
F_91 ( V_2 ) ;
}
}
if( V_2 -> V_61 == 0 ) {
if( F_32 ( V_2 ) ) {
F_2 ( V_2 -> V_6 , 0x1E , 0x20 ) ;
if( V_2 -> V_3 == V_216 ) {
F_2 ( V_2 -> V_6 , 0x1E , 0x40 ) ;
F_2 ( V_2 -> V_6 , 0x1E , 0x10 ) ;
}
}
} else if( F_34 ( V_2 ) ) {
if( V_2 -> V_3 != V_515 ) {
F_2 ( V_2 -> V_6 , 0x1E , 0x20 ) ;
}
}
if( ! ( F_39 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , 0x00 , 0x7f ) ;
}
if( V_2 -> V_61 == 2 ) {
if( F_43 ( V_2 ) ) {
F_92 ( V_2 ) ;
}
if( ( F_34 ( V_2 ) ) ||
( F_44 ( V_2 ) ) ) {
F_93 ( V_2 ) ;
}
}
if( V_2 -> V_61 == 2 ) {
if( ! ( F_39 ( V_2 ) ) ) {
if( ( F_34 ( V_2 ) ) ||
( F_44 ( V_2 ) ) ) {
F_91 ( V_2 ) ;
F_94 ( V_2 ) ;
}
}
} else if( V_2 -> V_61 == 0 ) {
if( ! ( F_39 ( V_2 ) ) ) {
if( F_32 ( V_2 ) ) {
F_22 ( V_2 , 1 ) ;
F_5 ( V_2 , 0xF7 , 0x00 ) ;
}
}
}
#endif
}
}
}
static void
F_95 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_27 )
{
unsigned short V_533 ;
unsigned char V_68 ;
if( V_2 -> V_35 & V_85 ) return;
V_533 = F_96 ( V_2 , V_25 , V_26 , V_27 ) ;
F_15 ( V_2 -> V_6 , 0x07 , ( V_533 & 0xFF ) ) ;
F_15 ( V_2 -> V_6 , 0x09 , ( V_533 >> 8 ) ) ;
V_68 = ( unsigned char ) ( ( ( V_533 >> 3 ) & 0xFF ) + 1 ) ;
if( V_533 & 0x07 ) V_68 ++ ;
F_15 ( V_2 -> V_6 , 0x03 , V_68 ) ;
}
static void
F_97 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_319 )
{
unsigned short V_362 = 0 , V_364 , V_31 ;
V_364 = 0xC0 ;
if( V_2 -> V_133 ) {
V_31 = V_2 -> V_534 ;
} else {
V_31 = V_2 -> V_32 [ V_319 ] . V_64 ;
}
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_35 & V_62 ) {
V_362 = 0 ;
} else if( ( V_2 -> V_35 & V_43 ) && ( V_2 -> V_46 & V_535 ) ) {
V_362 = V_2 -> V_46 ;
} else V_362 = V_31 >> 8 ;
V_362 &= 0xC0 ;
V_362 |= 0x20 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_362 |= 0x10 ;
if( V_2 -> V_35 & V_43 ) {
if( ( V_2 -> V_105 == V_224 ) ||
( V_2 -> V_105 == V_293 ) ) {
V_362 |= 0xf0 ;
}
if( ( V_2 -> V_291 ) ||
( V_2 -> V_292 ) ||
( V_2 -> V_312 ) ||
( V_2 -> V_105 == V_226 ) ||
( V_2 -> V_105 == V_228 ) ) {
V_362 |= 0x30 ;
}
if( ( V_2 -> V_291 ) ||
( V_2 -> V_292 ) ) {
V_362 &= ~ 0xc0 ;
}
}
if( V_2 -> V_35 & V_62 ) {
if( V_2 -> V_3 >= V_5 ) {
V_362 >>= 3 ;
V_362 &= 0x18 ;
F_6 ( V_2 -> V_6 , 0x13 , 0xE7 , V_362 ) ;
} else {
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , 0xe0 ) ;
}
} else {
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , V_362 ) ;
}
} else if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( V_2 -> V_18 & V_39 ) {
V_362 = V_31 >> 8 ;
V_364 = 0 ;
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_46 & V_535 ) {
V_362 = V_2 -> V_46 ;
V_364 = ( V_362 >> 6 ) & 0x03 ;
}
}
V_362 &= 0xC0 ;
V_362 |= 0x20 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_362 |= 0x10 ;
V_362 |= 0xc0 ;
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , V_362 ) ;
if( ( V_2 -> V_35 & V_43 ) && ( ! ( V_2 -> V_18 & V_79 ) ) ) {
F_6 ( V_2 -> V_121 , 0x1a , 0xf0 , V_364 ) ;
}
} else {
V_362 = ( ( V_31 >> 8 ) & 0xc0 ) | 0x20 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_362 |= 0x10 ;
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , V_362 ) ;
}
#endif
} else {
#ifdef V_95
if( V_2 -> V_18 & V_19 ) {
V_364 = 0 ;
if( ( V_2 -> V_105 == V_107 ) &&
( V_2 -> V_183 == V_239 ) ) {
V_362 = V_31 >> 8 ;
if( V_2 -> V_46 & V_535 ) {
V_364 = ( ( V_2 -> V_46 & 0xc0 ) >> 6 ) ;
}
} else if( ( V_2 -> V_105 == V_106 ) &&
( V_2 -> V_183 == V_240 ) ) {
V_362 = V_31 >> 8 ;
V_364 = 0x03 ;
} else {
V_362 = F_8 ( V_2 -> V_21 , 0x37 ) ;
V_364 = ( V_362 >> 6 ) & 0x03 ;
V_364 |= 0x08 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_364 |= 0x04 ;
}
V_362 &= 0xC0 ;
V_362 |= 0x20 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_362 |= 0x10 ;
if( V_2 -> V_35 & V_44 ) V_362 |= 0xc0 ;
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , V_362 ) ;
if( V_2 -> V_18 & V_39 ) {
if( V_2 -> V_35 & V_43 ) {
F_6 ( V_2 -> V_121 , 0x1a , 0xf0 , V_364 ) ;
}
}
} else {
V_362 = V_364 = V_31 >> 8 ;
if( ! V_2 -> V_133 ) {
V_364 = 0 ;
if( ( V_2 -> V_18 & V_536 ) && ( V_2 -> V_35 & V_36 ) ) {
if( V_25 <= 0x13 ) {
V_362 = F_26 ( ( V_2 -> V_327 + 0x02 ) ) ;
}
}
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
if( V_2 -> V_46 & V_535 ) {
V_362 = V_2 -> V_46 ;
V_364 = ( V_362 >> 6 ) & 0x03 ;
}
}
}
}
V_362 &= 0xC0 ;
V_362 |= 0x20 ;
if( ! ( V_2 -> V_46 & V_236 ) ) V_362 |= 0x10 ;
if( V_2 -> V_18 & V_79 ) {
if( V_2 -> V_35 & V_62 ) V_362 |= 0xc0 ;
}
if( ( V_2 -> V_18 & V_536 ) && ( V_2 -> V_35 & V_36 ) ) {
V_362 >>= 3 ;
V_362 &= 0x18 ;
F_6 ( V_2 -> V_6 , 0x13 , 0xe7 , V_362 ) ;
} else {
F_6 ( V_2 -> V_6 , 0x19 , 0x0F , V_362 ) ;
if( V_2 -> V_18 & V_39 ) {
if( V_2 -> V_35 & V_43 ) {
F_6 ( V_2 -> V_121 , 0x1a , 0xf0 , V_364 ) ;
}
}
}
}
#endif
}
}
}
static void
F_98 ( struct V_1 * V_2 , unsigned short V_25 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_68 , V_67 , V_537 , V_538 ;
unsigned short V_539 = 0 , V_540 , V_541 = 0 , V_542 = 0 ;
unsigned short V_131 , V_363 , V_543 , V_544 , V_545 ;
unsigned int V_546 , V_547 , V_548 ;
static const unsigned char V_549 [] = {
1 , 1 , 2 , 2 , 3 , 4
} ;
V_545 = V_2 -> V_76 ;
if( ! V_2 -> V_550 ) {
V_543 = V_2 -> V_551 ;
F_99 ( V_2 , & V_543 , & V_537 ) ;
V_2 -> V_77 &= ( ~ V_78 ) ;
V_2 -> V_76 = 0 ;
V_538 = F_12 ( V_2 , V_543 , V_537 ) ;
if( V_543 >= 0x13 ) {
V_67 = F_60 ( V_2 , V_538 , V_2 -> V_331 ) ;
V_539 = V_2 -> V_199 [ V_67 ] . CLOCK ;
V_541 = F_100 ( V_2 , V_543 , V_537 ) >> 1 ;
if( ! V_541 ) V_541 ++ ;
}
} else {
V_543 = 0xfe ;
V_539 = V_2 -> V_552 ;
V_541 = V_549 [ ( ( V_2 -> V_553 & V_83 ) - 2 ) ] ;
}
if( V_543 >= 0x13 ) {
if( V_2 -> V_3 == V_350 ) {
V_67 = F_8 ( V_2 -> V_10 , 0x3A ) ;
} else {
V_67 = F_8 ( V_2 -> V_10 , 0x1A ) ;
}
V_67 &= 0x07 ;
V_540 = V_2 -> V_554 [ V_67 ] . CLOCK ;
V_68 = ( ( F_8 ( V_2 -> V_10 , 0x14 ) >> 6 ) & 0x03 ) << 1 ;
if( ! V_68 ) V_68 ++ ;
V_68 <<= 2 ;
V_542 = V_68 - ( ( V_541 * V_539 ) / V_540 ) ;
V_68 = ( 28 * 16 ) % V_542 ;
V_542 = ( 28 * 16 ) / V_542 ;
if( V_68 ) V_542 ++ ;
if( V_2 -> V_3 == V_350 ) {
F_101 ( V_2 , & V_131 , & V_363 ) ;
V_546 = F_102 ( V_131 , V_363 ) ;
} else {
V_547 = F_103 ( V_2 , 0x50 ) ;
V_548 = F_103 ( V_2 , 0xa0 ) ;
if( V_2 -> V_3 == V_115 ) {
V_67 = ( unsigned short ) ( ( ( V_548 >> 28 ) & 0x0f ) * 3 ) ;
V_67 += ( unsigned short ) ( ( ( V_547 >> 9 ) ) & 0x03 ) ;
V_67 = 0 ;
} else {
V_547 >>= 24 ;
V_548 >>= 24 ;
V_67 = ( V_547 >> 1 ) & 0x07 ;
if( V_547 & 0x01 ) V_67 += 6 ;
if( ! ( V_548 & 0x01 ) ) V_67 += 24 ;
if( F_8 ( V_2 -> V_10 , 0x14 ) & 0x80 ) V_67 += 12 ;
}
V_546 = F_104 ( V_2 , V_67 ) + 15 ;
if( ! ( F_8 ( V_2 -> V_10 , 0x14 ) & 0x80 ) ) V_546 += 5 ;
}
V_546 += V_542 ;
V_2 -> V_77 |= V_78 ;
V_2 -> V_76 = V_545 ;
if( ! V_2 -> V_133 ) {
V_544 = V_25 ;
F_99 ( V_2 , & V_544 , & V_537 ) ;
V_538 = F_12 ( V_2 , V_544 , V_537 ) ;
V_67 = F_59 ( V_2 , V_544 , V_537 , V_538 ) ;
V_539 = V_2 -> V_199 [ V_67 ] . CLOCK ;
if( ( V_2 -> V_105 == V_224 ) || ( V_2 -> V_105 == V_293 ) ) {
if( V_2 -> V_90 ) {
if( V_11 [ 0x220 ] & 0x01 ) {
V_539 = V_11 [ 0x229 ] | ( V_11 [ 0x22a ] << 8 ) ;
}
}
}
} else {
V_544 = 0xfe ;
V_539 = V_2 -> V_555 ;
}
V_541 = F_100 ( V_2 , V_544 , V_537 ) >> 1 ;
if( ! V_541 ) V_541 ++ ;
V_546 = V_546 * V_539 * V_541 ;
V_68 = V_546 % ( V_540 << 4 ) ;
V_546 = V_546 / ( V_540 << 4 ) ;
if( V_68 ) V_546 ++ ;
if( V_546 < 6 ) V_546 = 6 ;
else if( V_546 > 0x14 ) V_546 = 0x14 ;
if( V_2 -> V_3 == V_350 ) {
V_68 = 0x16 ;
if( ( V_546 <= 0x0f ) || ( V_2 -> V_183 == V_239 ) )
V_68 = 0x13 ;
} else {
V_68 = 0x16 ;
if( ( ( V_2 -> V_3 == V_149 ) ||
( V_2 -> V_3 == V_115 ) ) &&
( V_2 -> V_349 >= 0x30 ) )
V_68 = 0x1b ;
}
F_6 ( V_2 -> V_6 , 0x01 , 0xe0 , V_68 ) ;
if( ( V_2 -> V_3 == V_149 ) &&
( V_2 -> V_349 >= 0x30 ) ) {
if( V_546 > 0x13 ) V_546 = 0x13 ;
}
F_6 ( V_2 -> V_6 , 0x02 , 0xe0 , V_546 ) ;
} else {
V_2 -> V_77 |= V_78 ;
V_2 -> V_76 = V_545 ;
}
}
static void
F_105 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_6 , 0x01 , 0x3B ) ;
if( ( V_2 -> V_3 == V_556 ) &&
( V_2 -> V_557 & V_558 ) &&
( V_2 -> V_84 == V_559 ) &&
( V_2 -> V_376 >= 1280 ) &&
( V_2 -> V_378 >= 1024 ) ) {
F_15 ( V_2 -> V_6 , 0x2f , 0x03 ) ;
F_15 ( V_2 -> V_6 , 0x01 , 0x3b ) ;
F_15 ( V_2 -> V_6 , 0x4d , 0xc0 ) ;
F_15 ( V_2 -> V_6 , 0x2f , 0x01 ) ;
F_15 ( V_2 -> V_6 , 0x4d , 0xc0 ) ;
F_15 ( V_2 -> V_6 , 0x02 , 0x6e ) ;
} else {
F_6 ( V_2 -> V_6 , 0x02 , ~ 0x3f , 0x04 ) ;
}
}
static unsigned short
F_106 ( struct V_1 * V_2 )
{
unsigned int V_130 , V_131 ;
V_131 = ( V_2 -> V_398 - V_2 -> V_378 ) * V_2 -> V_389 ;
V_130 = ( V_2 -> V_399 - V_2 -> V_379 ) * V_2 -> V_390 ;
V_130 = ( V_130 * V_2 -> V_397 ) / V_131 ;
return ( unsigned short ) V_130 ;
}
static void
F_107 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_68 , V_66 , V_28 , V_113 , V_371 = 0 , V_560 ;
static const unsigned short V_561 [] = {
0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 , 0x09 , 0x0a ,
0x00 , 0x0b , 0x17 , 0x18 , 0x19 , 0x00 , 0x1a , 0x00 ,
0x0c , 0x0d , 0x0e , 0x00 , 0x0f , 0x10 , 0x11 , 0x00
} ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
V_371 = V_2 -> V_374 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_371 = V_2 -> V_32 [ V_319 ] . V_562 ;
}
if( V_2 -> V_3 >= V_5 ) {
if( V_371 >= 1600 ) {
F_2 ( V_2 -> V_10 , 0x31 , 0x04 ) ;
}
}
V_2 -> V_276 = 8224 ;
V_2 -> V_374 = V_2 -> V_376 ;
if( V_66 & V_75 ) V_2 -> V_374 >>= 1 ;
V_2 -> V_563 = V_2 -> V_374 ;
if( V_2 -> V_35 & V_62 ) {
V_2 -> V_563 += 16 ;
}
V_2 -> V_564 = 32 ;
if( V_2 -> V_35 & V_43 ) {
if( V_371 == 1600 ) V_2 -> V_564 += 80 ;
}
V_68 = V_2 -> V_396 - 96 ;
if( ! ( V_66 & V_75 ) ) V_68 -= 32 ;
if( V_2 -> V_46 & V_48 ) {
V_68 = F_8 ( V_2 -> V_21 , 0x04 ) ;
V_68 |= ( ( F_8 ( V_2 -> V_10 , 0x0b ) & 0xc0 ) << 2 ) ;
V_68 -= 3 ;
V_68 <<= 3 ;
} else {
if( V_2 -> V_414 ) V_68 = V_2 -> V_414 ;
}
V_2 -> V_565 = V_68 ;
V_2 -> V_566 = 0xffe8 ;
V_2 -> V_277 = 2049 ;
V_560 = V_2 -> V_378 ;
if ( V_560 == 357 ) V_560 = 350 ;
else if( V_560 == 360 ) V_560 = 350 ;
else if( V_560 == 375 ) V_560 = 350 ;
else if( V_560 == 405 ) V_560 = 400 ;
else if( V_560 == 420 ) V_560 = 400 ;
else if( V_560 == 525 ) V_560 = 480 ;
else if( V_560 == 1056 ) V_560 = 1024 ;
V_2 -> V_380 = V_560 ;
V_2 -> V_567 = V_2 -> V_380 ;
V_2 -> V_568 = 1 ;
if( V_25 == 0x3c ) V_2 -> V_568 = 226 ;
V_68 = ( V_2 -> V_398 - V_560 ) >> 1 ;
V_2 -> V_569 = V_560 + V_68 ;
V_68 >>= 3 ;
V_2 -> V_570 = V_2 -> V_569 + V_68 ;
F_108 ( V_2 , 0 ) ;
V_2 -> V_571 [ 16 ] &= ~ 0xE0 ;
for( V_28 = 0 ; V_28 <= 7 ; V_28 ++ ) {
F_15 ( V_2 -> V_6 , V_561 [ V_28 ] , V_2 -> V_571 [ V_28 ] ) ;
}
for( V_28 = 0x10 , V_113 = 8 ; V_28 <= 0x12 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_6 , V_561 [ V_28 ] , V_2 -> V_571 [ V_113 ] ) ;
}
for( V_28 = 0x15 , V_113 = 11 ; V_28 <= 0x16 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_6 , V_561 [ V_28 ] , V_2 -> V_571 [ V_113 ] ) ;
}
for( V_28 = 0x0a , V_113 = 13 ; V_28 <= 0x0c ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_6 , V_561 [ V_28 ] , V_2 -> V_571 [ V_113 ] ) ;
}
V_68 = V_2 -> V_571 [ 16 ] & 0xE0 ;
F_6 ( V_2 -> V_6 , V_561 [ 0x0E ] , 0x1F , V_68 ) ;
V_68 = ( V_2 -> V_571 [ 16 ] & 0x01 ) << 5 ;
if( V_66 & V_382 ) V_68 |= 0x80 ;
F_6 ( V_2 -> V_6 , V_561 [ 0x09 ] , 0x5F , V_68 ) ;
V_68 = 0 ;
V_68 |= ( F_8 ( V_2 -> V_10 , 0x01 ) & 0x01 ) ;
if( V_66 & V_75 ) V_68 |= 0x08 ;
F_15 ( V_2 -> V_6 , 0x16 , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x0F , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x12 , 0x00 ) ;
V_68 = 0 ;
if( V_2 -> V_46 & V_236 ) {
V_68 = ( F_8 ( V_2 -> V_6 , 0x00 ) & 0x01 ) << 7 ;
}
F_15 ( V_2 -> V_6 , 0x1A , V_68 ) ;
V_68 = F_26 ( ( V_2 -> V_327 + 0x02 ) ) ;
F_15 ( V_2 -> V_6 , 0x1b , V_68 ) ;
}
static void
F_109 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_66 , V_132 = 0 ;
unsigned short V_572 , V_130 , V_131 , V_388 , V_68 ;
unsigned int V_573 = 0 , V_574 , V_575 , V_576 = 0 ;
bool V_577 = false , V_578 = false , V_579 = false ;
#ifdef V_94
unsigned short V_580 = 0 ;
#endif
#ifdef V_95
unsigned short V_581 ;
#endif
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
#ifdef V_94
V_580 = V_2 -> V_71 [ V_26 ] . V_326 ;
#endif
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
#ifdef V_94
V_580 = V_2 -> V_32 [ V_319 ] . V_328 ;
#endif
}
if( ( V_2 -> V_104 == 1 ) || ( V_2 -> V_18 & V_79 ) ) {
V_577 = true ;
}
if( ( V_2 -> V_18 & V_34 ) && ( ! ( V_2 -> V_18 & V_79 ) ) ) {
V_578 = true ;
}
if( ( V_2 -> V_3 >= V_5 ) && ( V_577 ) && ( ! ( V_2 -> V_35 & V_44 ) ) ) {
if( ( ! V_2 -> V_291 ) && ( ! V_2 -> V_292 ) ) {
V_579 = true ;
}
}
#ifdef V_95
if( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_35 & V_44 ) ) {
if( V_582 ) {
F_2 ( V_2 -> V_6 , 0x2D , 0x10 ) ;
} else if( V_367 ) {
if( V_577 ) {
F_6 ( V_2 -> V_6 , 0x13 , 0xfb , 0x04 ) ;
F_2 ( V_2 -> V_6 , 0x2D , 0x03 ) ;
} else if( V_2 -> V_18 & V_34 ) {
F_2 ( V_2 -> V_6 , 0x2D , 0x10 ) ;
}
} else {
if( V_577 ) {
F_6 ( V_2 -> V_6 , 0x13 , 0xfb , 0x04 ) ;
F_2 ( V_2 -> V_6 , 0x2D , 0x00 ) ;
} else if( V_2 -> V_18 & V_34 ) {
F_4 ( V_2 -> V_6 , 0x2D , 0x0f ) ;
if( V_2 -> V_18 & V_536 ) {
if( ( V_2 -> V_183 == V_238 ) ||
( V_2 -> V_183 == V_239 ) ) {
F_2 ( V_2 -> V_6 , 0x2D , 0x20 ) ;
}
}
}
}
}
#endif
V_130 = V_2 -> V_499 ;
if( V_577 ) {
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! V_2 -> V_291 && ! V_2 -> V_292 ) {
if( ( V_2 -> V_183 == V_234 ) &&
( ! ( V_2 -> V_35 & V_85 ) ) ) {
V_130 -= 8 ;
}
}
}
}
V_68 = ( V_130 & 0x0007 ) ;
F_15 ( V_2 -> V_6 , 0x1A , V_68 ) ;
V_68 = ( V_130 >> 3 ) & 0x00FF ;
F_15 ( V_2 -> V_6 , 0x16 , V_68 ) ;
V_131 = V_2 -> V_377 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_131 = V_2 -> V_247 ;
}
if( ( V_2 -> V_183 == V_232 ) ||
( V_2 -> V_183 == V_218 ) ||
( V_2 -> V_183 == V_221 ) ) {
V_131 >>= 1 ;
}
}
V_130 += V_131 ;
if( V_130 >= V_2 -> V_397 ) V_130 -= V_2 -> V_397 ;
V_68 = V_130 ;
if( V_68 & 0x07 ) V_68 += 8 ;
V_68 >>= 3 ;
F_15 ( V_2 -> V_6 , 0x17 , V_68 ) ;
V_388 = ( V_2 -> V_397 - V_131 ) >> 2 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
if( V_2 -> V_193 != 999 ) V_388 = V_2 -> V_193 ;
}
}
V_388 += V_130 ;
if( V_388 >= V_2 -> V_397 ) V_388 -= V_2 -> V_397 ;
V_68 = ( V_388 >> 3 ) & 0x00FF ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_312 ) {
if( V_2 -> V_183 == V_238 ) {
switch( V_25 ) {
case 0x04 :
case 0x05 :
case 0x0d : V_68 = 0x56 ; break;
case 0x10 : V_68 = 0x60 ; break;
case 0x13 : V_68 = 0x5f ; break;
case 0x40 :
case 0x41 :
case 0x4f :
case 0x43 :
case 0x44 :
case 0x62 :
case 0x56 :
case 0x53 :
case 0x5d :
case 0x5e : V_68 = 0x54 ; break;
}
}
}
}
F_15 ( V_2 -> V_6 , 0x14 , V_68 ) ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
V_68 += 2 ;
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_68 += 8 ;
if( V_2 -> V_194 != 999 ) {
V_68 = V_388 + V_2 -> V_194 ;
if( V_68 >= V_2 -> V_397 ) V_68 -= V_2 -> V_397 ;
V_68 >>= 3 ;
}
}
} else {
V_68 += 10 ;
}
V_68 &= 0x1F ;
V_68 |= ( ( V_388 & 0x07 ) << 5 ) ;
F_15 ( V_2 -> V_6 , 0x15 , V_68 ) ;
V_130 = V_2 -> V_378 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_130 = V_2 -> V_248 ;
}
}
V_131 = V_2 -> V_500 + V_130 ;
if( V_131 >= V_2 -> V_399 ) V_131 -= V_2 -> V_399 ;
V_572 = V_131 ;
V_388 = V_2 -> V_398 - V_2 -> V_378 ;
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_388 = V_2 -> V_398 - V_2 -> V_248 ;
}
}
}
if( V_577 ) V_388 >>= 1 ;
else V_388 >>= 2 ;
if( ( V_2 -> V_35 & ( V_43 | V_44 ) ) &&
( ! ( V_2 -> V_46 & V_48 ) ) &&
( V_2 -> V_195 != 999 ) ) {
V_388 = V_2 -> V_195 ;
V_131 += V_388 ;
if( V_578 ) V_131 ++ ;
} else {
V_131 += V_388 ;
if( V_2 -> V_3 < V_5 ) V_131 ++ ;
else if( V_578 ) V_131 ++ ;
}
if( V_131 >= V_2 -> V_399 ) V_131 -= V_2 -> V_399 ;
V_68 = V_131 & 0x00FF ;
if( V_2 -> V_312 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_25 == 0x10 ) V_68 = 0xa9 ;
}
}
F_15 ( V_2 -> V_6 , 0x18 , V_68 ) ;
V_388 >>= 3 ;
V_388 ++ ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
if( V_2 -> V_196 != 999 ) V_388 = V_2 -> V_196 ;
}
}
V_388 += V_131 ;
V_68 = V_388 & 0x000F ;
F_6 ( V_2 -> V_6 , 0x19 , 0xF0 , V_68 ) ;
V_68 = ( ( V_131 >> 8 ) & 0x07 ) << 3 ;
if( V_2 -> V_291 || V_2 -> V_292 ) {
if( V_2 -> V_377 != 640 ) {
if( V_2 -> V_378 != V_2 -> V_379 ) V_68 |= 0x40 ;
}
} else if( V_2 -> V_378 != V_2 -> V_379 ) V_68 |= 0x40 ;
if( V_2 -> V_77 & V_314 ) V_68 |= 0x40 ;
V_131 = 0x87 ;
if( ( V_2 -> V_3 >= V_5 ) ||
( V_2 -> V_349 >= 0x30 ) ) {
V_131 = 0x07 ;
if( ( V_2 -> V_61 == 1 ) && ( V_2 -> V_35 & V_62 ) ) {
if( F_8 ( V_2 -> V_6 , 0x00 ) & 0x03 ) V_68 |= 0x80 ;
}
if( V_2 -> V_46 & V_236 ) {
if( V_2 -> V_35 & V_44 ) {
if( F_8 ( V_2 -> V_10 , 0x06 ) & 0x10 ) V_68 |= 0x80 ;
} else {
if( F_8 ( V_2 -> V_6 , 0x00 ) & 0x01 ) V_68 |= 0x80 ;
}
}
}
F_6 ( V_2 -> V_6 , 0x1A , V_131 , V_68 ) ;
V_131 = V_572 ;
V_388 = V_2 -> V_500 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
switch( V_2 -> V_183 ) {
case V_234 :
V_131 = V_2 -> V_378 - 1 ;
V_388 = V_2 -> V_378 ;
break;
case V_250 :
if( ! ( V_2 -> V_35 & V_85 ) ) {
if( V_132 == V_315 ) V_388 ++ ;
}
break;
case V_252 :
if( ! ( V_2 -> V_35 & V_85 ) ) {
if( V_132 == V_302 ) V_388 ++ ;
if( V_2 -> V_46 & V_47 ) {
if( V_132 == V_315 ) V_388 ++ ;
}
}
break;
case V_238 :
if( V_2 -> V_3 < V_5 ) {
if( ! ( V_2 -> V_35 & V_85 ) ) {
if( V_132 == V_179 ) V_388 ++ ;
}
}
break;
}
}
V_68 = ( ( V_131 >> 8 ) & 0x07 ) << 3 ;
V_68 |= ( ( V_388 >> 8 ) & 0x07 ) ;
F_15 ( V_2 -> V_6 , 0x1D , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x1C , V_131 ) ;
F_15 ( V_2 -> V_6 , 0x1B , V_388 ) ;
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
V_573 = V_2 -> V_378 << 6 ;
V_68 = ( V_573 % ( unsigned int ) V_2 -> V_379 ) ;
V_573 = V_573 / ( unsigned int ) V_2 -> V_379 ;
if( V_68 ) V_573 ++ ;
if( V_2 -> V_77 & V_314 ) V_573 = 0x3F ;
V_68 = ( unsigned short ) ( V_573 & 0x00FF ) ;
F_15 ( V_2 -> V_6 , 0x1E , V_68 ) ;
V_576 = V_68 ;
#endif
} else {
#ifdef V_95
V_573 = V_2 -> V_378 << 18 ;
V_574 = V_2 -> V_379 ;
V_68 = ( V_573 % V_574 ) ;
V_573 = V_573 / V_574 ;
if( V_68 ) V_573 ++ ;
V_576 = V_573 ;
V_68 = ( unsigned short ) ( V_573 & 0x00FF ) ;
F_15 ( V_2 -> V_6 , 0x37 , V_68 ) ;
V_68 = ( unsigned short ) ( ( V_573 & 0x00FF00 ) >> 8 ) ;
F_15 ( V_2 -> V_6 , 0x36 , V_68 ) ;
V_68 = ( unsigned short ) ( ( V_573 & 0x00030000 ) >> 16 ) ;
if( V_2 -> V_379 == V_2 -> V_378 ) V_68 |= 0x04 ;
F_15 ( V_2 -> V_6 , 0x35 , V_68 ) ;
if( V_2 -> V_18 & V_583 ) {
V_68 = ( unsigned short ) ( V_573 & 0x00FF ) ;
F_15 ( V_2 -> V_114 , 0x3c , V_68 ) ;
V_68 = ( unsigned short ) ( ( V_573 & 0x00FF00 ) >> 8 ) ;
F_15 ( V_2 -> V_114 , 0x3b , V_68 ) ;
V_68 = ( unsigned short ) ( ( ( V_573 & 0x00030000 ) >> 16 ) << 6 ) ;
F_6 ( V_2 -> V_114 , 0x3a , 0x3f , V_68 ) ;
V_68 = 0 ;
if( V_2 -> V_379 != V_2 -> V_378 ) V_68 |= 0x08 ;
F_6 ( V_2 -> V_114 , 0x30 , 0xf3 , V_68 ) ;
}
#endif
}
V_573 = V_2 -> V_376 ;
if( V_579 ) {
if( V_66 & V_75 ) V_573 >>= 1 ;
}
V_574 = V_573 << 16 ;
if( V_2 -> V_377 == V_573 ) {
V_575 = 0xFFFF ;
} else {
V_575 = V_574 / V_2 -> V_377 ;
if( V_2 -> V_3 >= V_5 ) {
if( V_574 % V_2 -> V_377 ) V_575 ++ ;
}
}
if( V_2 -> V_3 >= V_5 ) {
V_573 = ( V_574 / V_575 ) - 1 ;
} else {
V_573 = ( ( V_2 -> V_396 << 16 ) / V_575 ) - 1 ;
}
V_575 = ( V_575 << 16 ) | ( V_573 & 0xFFFF ) ;
V_68 = ( unsigned short ) ( V_575 & 0x00FF ) ;
F_15 ( V_2 -> V_6 , 0x1F , V_68 ) ;
if( V_2 -> V_3 >= V_5 ) {
V_573 = ( V_2 -> V_378 << 18 ) / V_576 ;
V_131 = ( unsigned short ) ( V_573 & 0xFFFF ) ;
} else {
V_573 = V_2 -> V_378 << 6 ;
V_131 = V_576 & 0x3f ;
if( V_131 == 0 ) V_131 = 64 ;
V_573 /= V_131 ;
V_131 = ( unsigned short ) ( V_573 & 0xFFFF ) ;
}
if( V_2 -> V_183 == V_238 ) V_131 -- ;
if( V_2 -> V_77 & V_314 ) {
if( ( ! V_2 -> V_291 ) && ( ! V_2 -> V_292 ) ) V_131 = 1 ;
else if( V_2 -> V_183 != V_234 ) V_131 = 1 ;
}
V_68 = ( ( V_131 >> 8 ) & 0x07 ) << 3 ;
V_68 = V_68 | ( ( V_575 >> 8 ) & 0x07 ) ;
F_15 ( V_2 -> V_6 , 0x20 , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x21 , V_131 ) ;
V_575 >>= 16 ;
if( ! V_579 ) {
if( V_66 & V_75 ) V_575 >>= 1 ;
}
V_68 = ( unsigned short ) ( ( V_575 & 0xFF00 ) >> 8 ) ;
F_15 ( V_2 -> V_6 , 0x22 , V_68 ) ;
V_68 = ( unsigned short ) ( V_575 & 0x00FF ) ;
F_15 ( V_2 -> V_6 , 0x23 , V_68 ) ;
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_35 & V_44 ) {
if( ( V_577 ) || ( V_2 -> V_35 & V_19 ) ) {
F_15 ( V_2 -> V_6 , 0x1e , 0x20 ) ;
}
} else {
if( V_577 ) {
if( V_2 -> V_3 == V_515 ) {
F_2 ( V_2 -> V_6 , 0x1e , 0x03 ) ;
} else {
F_15 ( V_2 -> V_6 , 0x1e , 0x23 ) ;
}
}
}
}
#endif
#ifdef V_94
if( V_2 -> V_312 ) {
unsigned char * V_11 = V_2 -> V_12 ;
unsigned char * V_584 ;
int V_28 , V_113 = V_580 ;
unsigned char V_585 [ 4 ] = { 0x01 , 0x10 , 0x2c , 0x00 } ;
unsigned char V_586 [ 4 ] = { 0x01 , 0x10 , 0x27 , 0x00 } ;
unsigned char V_587 [ 4 ] = { 0x01 , 0x16 , 0x10 , 0x00 } ;
if( V_2 -> V_90 ) {
V_584 = & V_11 [ 0x8001 + ( V_113 * 80 ) ] ;
} else {
if( V_2 -> V_211 == 0x0e ) V_113 += 7 ;
V_584 = & V_588 [ V_113 ] [ 0 ] ;
}
F_4 ( V_2 -> V_6 , 0x02 , 0xbf ) ;
for( V_28 = 0 ; V_28 < 5 ; V_28 ++ ) {
F_110 ( V_2 , V_584 ) ;
}
if( V_2 -> V_183 == V_238 ) {
if( V_25 == 0x13 ) {
for( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_110 ( V_2 , & V_585 [ 0 ] ) ;
}
} else if( V_25 == 0x10 ) {
for( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_110 ( V_2 , & V_586 [ 0 ] ) ;
F_110 ( V_2 , & V_587 [ 0 ] ) ;
}
}
}
F_2 ( V_2 -> V_6 , 0x02 , 0x40 ) ;
}
#endif
#ifdef V_95
if( V_2 -> V_291 || V_2 -> V_292 ) {
F_15 ( V_2 -> V_6 , 0x25 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x26 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x27 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x28 , 0x87 ) ;
F_15 ( V_2 -> V_6 , 0x29 , 0x5A ) ;
F_15 ( V_2 -> V_6 , 0x2A , 0x4B ) ;
F_6 ( V_2 -> V_6 , 0x44 , ~ 0x07 , 0x03 ) ;
V_130 = V_2 -> V_377 ;
if( V_2 -> V_183 == V_232 ||
V_2 -> V_183 == V_218 ||
V_2 -> V_183 == V_221 ) V_130 >>= 1 ;
V_130 += 64 ;
F_15 ( V_2 -> V_6 , 0x38 , V_130 & 0xff ) ;
V_68 = ( V_130 >> 8 ) << 3 ;
F_6 ( V_2 -> V_6 , 0x35 , ~ 0x078 , V_68 ) ;
V_130 += 32 ;
F_15 ( V_2 -> V_6 , 0x39 , V_130 & 0xff ) ;
F_15 ( V_2 -> V_6 , 0x3A , 0x00 ) ;
F_4 ( V_2 -> V_6 , 0x3C , ~ 0x007 ) ;
V_130 = V_2 -> V_379 ;
if( V_2 -> V_183 == V_232 ||
V_2 -> V_183 == V_218 ||
V_2 -> V_183 == V_221 ) V_130 >>= 1 ;
V_130 >>= 1 ;
F_15 ( V_2 -> V_6 , 0x3B , V_130 & 0xff ) ;
V_68 = ( V_130 >> 8 ) << 3 ;
F_6 ( V_2 -> V_6 , 0x3C , ~ 0x038 , V_68 ) ;
V_573 = V_2 -> V_377 ;
if( V_2 -> V_183 == V_232 ||
V_2 -> V_183 == V_218 ||
V_2 -> V_183 == V_221 ) V_573 >>= 1 ;
V_573 <<= 2 ;
V_68 = V_573 & 0x7f ;
V_573 >>= 7 ;
if( V_68 ) V_573 ++ ;
V_68 = V_573 & 0x3f ;
F_15 ( V_2 -> V_6 , 0x45 , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x3F , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x3E , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x3D , 0x10 ) ;
F_4 ( V_2 -> V_6 , 0x3C , ~ 0x040 ) ;
V_130 = V_2 -> V_377 ;
if( V_2 -> V_183 == V_232 ||
V_2 -> V_183 == V_218 ||
V_2 -> V_183 == V_221 ) V_130 >>= 1 ;
V_130 >>= 4 ;
V_581 = V_130 ;
V_68 = V_130 & 0x00FF ;
F_15 ( V_2 -> V_6 , 0x43 , V_68 ) ;
V_68 = ( ( V_130 & 0xFF00 ) >> 8 ) << 3 ;
F_6 ( V_2 -> V_6 , 0x44 , 0x07 , V_68 ) ;
V_130 = V_2 -> V_379 ;
if( V_2 -> V_183 == V_232 ||
V_2 -> V_183 == V_218 ||
V_2 -> V_183 == V_221 ) V_130 >>= 1 ;
V_573 = V_130 * V_581 ;
V_68 = V_573 & 0xFF ;
F_15 ( V_2 -> V_6 , 0x42 , V_68 ) ;
V_68 = ( V_573 & 0xFF00 ) >> 8 ;
F_15 ( V_2 -> V_6 , 0x41 , V_68 ) ;
V_68 = ( ( V_573 & 0xFF0000 ) >> 16 ) | 0x10 ;
F_15 ( V_2 -> V_6 , 0x40 , V_68 ) ;
V_68 = ( ( V_573 & 0x01000000 ) >> 24 ) << 7 ;
F_6 ( V_2 -> V_6 , 0x3C , 0x7F , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x2F , 0x03 ) ;
F_15 ( V_2 -> V_6 , 0x03 , 0x50 ) ;
F_15 ( V_2 -> V_6 , 0x04 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x2F , 0x01 ) ;
F_15 ( V_2 -> V_6 , 0x19 , 0x38 ) ;
if( V_2 -> V_291 ) {
F_15 ( V_2 -> V_6 , 0x2b , 0x02 ) ;
F_15 ( V_2 -> V_6 , 0x2c , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x2d , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x35 , 0x0c ) ;
F_15 ( V_2 -> V_6 , 0x36 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x37 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x38 , 0x80 ) ;
F_15 ( V_2 -> V_6 , 0x39 , 0xA0 ) ;
F_15 ( V_2 -> V_6 , 0x3a , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x3b , 0xf0 ) ;
F_15 ( V_2 -> V_6 , 0x3c , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x3d , 0x10 ) ;
F_15 ( V_2 -> V_6 , 0x3e , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x3f , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x40 , 0x10 ) ;
F_15 ( V_2 -> V_6 , 0x41 , 0x25 ) ;
F_15 ( V_2 -> V_6 , 0x42 , 0x80 ) ;
F_15 ( V_2 -> V_6 , 0x43 , 0x14 ) ;
F_15 ( V_2 -> V_6 , 0x44 , 0x03 ) ;
F_15 ( V_2 -> V_6 , 0x45 , 0x0a ) ;
}
}
#endif
}
static void
F_111 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
#if F_23 ( V_94 ) || F_23 ( V_95 )
unsigned char * V_11 = V_2 -> V_12 ;
#endif
unsigned short V_68 = 0 , V_130 = 0 , V_131 = 0 , V_388 = 0 , V_589 = 0 ;
unsigned short V_590 = 0 , V_591 = 0 , V_66 , V_132 = 0 ;
#ifdef V_95
unsigned short V_364 = 0 ;
#endif
if( V_2 -> V_35 & V_44 ) {
F_109 ( V_2 , V_25 , V_26 , V_319 ) ;
return;
}
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
} else {
V_591 = F_67 ( V_2 , V_319 , V_2 -> V_330 ) ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
}
F_95 ( V_2 , V_25 , V_26 , V_319 ) ;
if( ! ( ( V_2 -> V_3 >= V_5 ) &&
( V_2 -> V_104 == 1 ) &&
( V_2 -> V_35 & V_85 ) ) ) {
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
F_98 ( V_2 , V_25 ) ;
#endif
} else {
#ifdef V_95
F_105 ( V_2 ) ;
#endif
}
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
V_68 = ( V_2 -> V_396 - 1 ) & 0x0FF ;
F_15 ( V_2 -> V_6 , 0x08 , V_68 ) ;
V_68 = ( ( ( V_2 -> V_396 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_6 ( V_2 -> V_6 , 0x09 , 0x0f , V_68 ) ;
V_68 = ( V_2 -> V_376 + 12 ) & 0x0FF ;
F_15 ( V_2 -> V_6 , 0x0A , V_68 ) ;
V_590 = V_2 -> V_376 + 12 ;
V_388 = ( V_2 -> V_396 - V_2 -> V_376 ) >> 2 ;
V_131 = V_590 + V_388 ;
V_388 <<= 1 ;
V_388 += V_131 ;
V_589 = 12 ;
#endif
} else {
#ifdef V_95
V_388 = V_2 -> V_396 ;
if( V_66 & V_75 ) {
if( V_2 -> V_18 & V_34 ) {
V_388 >>= 1 ;
} else {
V_130 = V_2 -> V_376 >> 1 ;
V_388 = V_2 -> V_397 - V_2 -> V_377 + V_130 ;
if( V_2 -> V_46 & V_47 ) {
V_388 = V_2 -> V_397 - V_130 ;
}
}
}
V_388 -- ;
F_15 ( V_2 -> V_6 , 0x08 , V_388 ) ;
V_68 = ( V_388 >> 4 ) & 0xF0 ;
F_6 ( V_2 -> V_6 , 0x09 , 0x0F , V_68 ) ;
V_388 = V_2 -> V_396 ;
V_131 = V_2 -> V_376 ;
V_388 -= V_131 ;
V_388 >>= 2 ;
if( V_66 & V_75 ) {
V_131 >>= 1 ;
V_388 >>= 1 ;
}
V_131 += 16 ;
F_15 ( V_2 -> V_6 , 0x0A , V_131 ) ;
V_590 = V_131 ;
V_388 >>= 1 ;
V_131 += V_388 ;
V_388 += V_131 ;
V_589 = 16 ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_3 >= V_9 ) {
if( ( V_2 -> V_183 == V_241 ) ||
( V_2 -> V_183 == V_239 ) ) {
if( V_132 == V_266 ) {
V_388 = ( V_388 & 0xff00 ) | 0x30 ;
} else if( V_132 == V_148 ) {
V_388 = ( V_388 & 0xff00 ) | 0xff ;
}
}
}
}
#endif
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_133 ) {
V_131 = V_2 -> V_565 + V_589 ;
V_388 = V_2 -> V_566 + V_589 ;
V_130 = V_2 -> V_396 ;
if( V_66 & V_75 ) V_130 >>= 1 ;
V_130 -- ;
if( V_388 > V_130 ) V_388 = V_130 ;
}
if( V_2 -> V_35 & V_36 ) {
unsigned char V_592 , V_593 , V_594 , V_595 ;
if( V_2 -> V_133 ) {
V_592 = V_2 -> V_571 [ 4 ] ;
V_593 = V_2 -> V_571 [ 14 ] ;
V_594 = V_2 -> V_571 [ 5 ] ;
V_595 = V_2 -> V_571 [ 15 ] ;
} else {
V_592 = V_2 -> V_394 [ V_591 ] . V_395 [ 4 ] ;
V_593 = V_2 -> V_394 [ V_591 ] . V_395 [ 14 ] ;
V_594 = V_2 -> V_394 [ V_591 ] . V_395 [ 5 ] ;
V_595 = V_2 -> V_394 [ V_591 ] . V_395 [ 15 ] ;
}
V_131 = ( ( V_592 | ( ( V_593 & 0xC0 ) << 2 ) ) - 3 ) << 3 ;
V_388 = ( ( ( V_594 & 0x1f ) | ( ( V_595 & 0x04 ) << ( 5 - 2 ) ) ) - 3 ) << 3 ;
V_388 &= 0x00FF ;
V_388 |= ( V_131 & 0xFF00 ) ;
V_131 += V_589 ;
V_388 += V_589 ;
V_130 = V_2 -> V_396 ;
if( V_66 & V_75 ) V_130 >>= 1 ;
V_130 -- ;
if( V_388 > V_130 ) V_388 = V_130 ;
}
if( V_2 -> V_58 & ( V_181 | V_180 ) ) {
V_131 = 1040 ;
V_388 = 1044 ;
}
}
F_15 ( V_2 -> V_6 , 0x0B , V_131 ) ;
F_15 ( V_2 -> V_6 , 0x0D , V_388 ) ;
V_68 = ( ( V_131 >> 8 ) & 0x0F ) | ( ( V_590 >> 4 ) & 0xF0 ) ;
F_15 ( V_2 -> V_6 , 0x0C , V_68 ) ;
V_388 = V_2 -> V_398 - 1 ;
V_68 = V_388 & 0x00FF ;
if( V_2 -> V_3 < V_9 ) {
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_35 & ( V_54 | V_53 ) ) {
V_68 -- ;
}
}
} else {
V_68 -- ;
}
} else if( V_2 -> V_3 >= V_5 ) {
V_68 -- ;
}
}
F_15 ( V_2 -> V_6 , 0x0E , V_68 ) ;
V_131 = V_2 -> V_378 - 1 ;
F_15 ( V_2 -> V_6 , 0x0F , V_131 ) ;
V_68 = ( ( V_131 >> 5 ) & 0x38 ) | ( ( V_388 >> 8 ) & 0x07 ) ;
F_15 ( V_2 -> V_6 , 0x12 , V_68 ) ;
if( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_3 < V_9 ) ) {
V_131 ++ ;
V_130 = V_131 ;
V_388 ++ ;
V_388 -= V_130 ;
V_388 >>= 2 ;
V_131 += V_388 ;
if( V_388 < 4 ) V_388 = 4 ;
V_388 >>= 2 ;
V_388 += V_131 ;
V_388 ++ ;
} else {
V_131 = ( V_2 -> V_398 + V_2 -> V_378 ) >> 1 ;
V_388 = ( ( V_2 -> V_398 - V_2 -> V_378 ) >> 4 ) + V_131 + 1 ;
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_133 ) {
V_131 = V_2 -> V_569 ;
V_388 = V_2 -> V_570 ;
}
if( V_2 -> V_35 & V_36 ) {
unsigned char V_596 , V_597 , V_598 ;
if( V_2 -> V_133 ) {
V_596 = V_2 -> V_571 [ 8 ] ;
V_597 = V_2 -> V_571 [ 7 ] ;
V_598 = V_2 -> V_571 [ 13 ] ;
V_388 = V_2 -> V_571 [ 9 ] ;
} else {
V_596 = V_2 -> V_394 [ V_591 ] . V_395 [ 8 ] ;
V_597 = V_2 -> V_394 [ V_591 ] . V_395 [ 7 ] ;
V_598 = V_2 -> V_394 [ V_591 ] . V_395 [ 13 ] ;
V_388 = V_2 -> V_394 [ V_591 ] . V_395 [ 9 ] ;
}
V_131 = V_596 ;
if( V_597 & 0x04 ) V_131 |= 0x0100 ;
if( V_597 & 0x80 ) V_131 |= 0x0200 ;
if( V_598 & 0x08 ) V_131 |= 0x0400 ;
}
}
F_15 ( V_2 -> V_6 , 0x10 , V_131 ) ;
V_68 = ( ( V_131 >> 4 ) & 0x70 ) | ( V_388 & 0x0F ) ;
F_15 ( V_2 -> V_6 , 0x11 , V_68 ) ;
if( V_2 -> V_3 < V_5 ) {
#ifdef V_94
if( V_2 -> V_18 & V_34 ) {
V_68 = 0x20 ;
if( V_2 -> V_3 == V_350 ) {
V_68 = 0x10 ;
if( V_2 -> V_183 == V_238 ) V_68 = 0x2c ;
if( V_2 -> V_183 == V_239 ) V_68 = 0x20 ;
}
if( V_2 -> V_18 & V_99 ) {
if( V_2 -> V_183 == V_239 ) V_68 = 0x20 ;
}
if( V_2 -> V_183 == V_233 ) V_68 = 0x24 ;
if( V_2 -> V_183 == V_273 ) V_68 = 0x2c ;
if( V_2 -> V_35 & V_62 ) V_68 = 0x08 ;
if( V_2 -> V_35 & V_50 ) {
if( V_2 -> V_35 & V_85 ) V_68 = 0x2c ;
else V_68 = 0x20 ;
}
if( V_2 -> V_90 ) {
if( V_11 [ 0x220 ] & 0x80 ) {
if( V_2 -> V_35 & V_599 )
V_68 = V_11 [ 0x221 ] ;
else if( V_2 -> V_35 & V_50 )
V_68 = V_11 [ 0x222 ] ;
else if( V_2 -> V_183 == V_239 )
V_68 = V_11 [ 0x223 ] ;
else
V_68 = V_11 [ 0x224 ] ;
}
}
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_600 != - 1 ) V_68 = V_2 -> V_600 ;
}
} else {
V_68 = 0x20 ;
if( ! ( V_2 -> V_35 & V_62 ) ) {
if( V_2 -> V_183 == V_234 ) V_68 = 0x04 ;
}
if( V_2 -> V_90 ) {
if( V_11 [ 0x220 ] & 0x80 ) {
V_68 = V_11 [ 0x220 ] ;
}
}
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_600 != - 1 ) V_68 = V_2 -> V_600 ;
}
}
V_68 &= 0x3c ;
F_6 ( V_2 -> V_6 , 0x13 , ~ 0x3C , V_68 ) ;
#endif
} else {
#ifdef V_95
if( V_2 -> V_3 < V_9 ) {
if( V_2 -> V_104 == 1 ) {
if( V_2 -> V_3 == V_515 ) V_68 = 0x03 ;
else V_68 = 0x00 ;
if( V_2 -> V_35 & V_62 ) V_68 = 0x0a ;
V_364 = 0xF0 ;
if( V_2 -> V_3 == V_116 ) {
if( V_2 -> V_61 != 0 ) {
if( ! ( V_2 -> V_35 & V_62 ) ) V_364 = 0x0F ;
}
}
if( V_2 -> V_292 || V_2 -> V_291 ) {
V_68 = 0x08 ;
V_364 = 0 ;
if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
if( V_11 [ 0x13c ] & 0x80 ) V_364 = 0xf0 ;
}
}
F_6 ( V_2 -> V_6 , 0x2D , V_364 , V_68 ) ;
}
}
V_130 = 0 ;
if( V_66 & V_382 ) V_130 |= 0x80 ;
if( V_66 & V_75 ) V_130 |= 0x40 ;
F_6 ( V_2 -> V_6 , 0x2C , 0x3f , V_130 ) ;
#endif
}
}
if( V_2 -> V_18 & V_34 ) {
if( ( V_2 -> V_18 & V_79 ) && ( V_2 -> V_35 & V_43 ) ) {
F_109 ( V_2 , V_25 , V_26 , V_319 ) ;
} else if( V_2 -> V_35 & V_85 ) {
F_107 ( V_2 , V_25 , V_26 , V_319 ) ;
}
} else {
if( V_2 -> V_3 < V_5 ) {
F_109 ( V_2 , V_25 , V_26 , V_319 ) ;
} else {
if( V_2 -> V_61 != 0 ) {
if( ( ! ( V_2 -> V_35 & V_62 ) ) || ( V_2 -> V_35 & V_85 ) ) {
F_109 ( V_2 , V_25 , V_26 , V_319 ) ;
}
} else {
F_109 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
}
}
static unsigned char *
F_112 ( struct V_1 * V_2 , int V_601 )
{
const unsigned char * V_602 = NULL ;
unsigned short V_603 , V_604 , V_605 = 0 ;
V_603 = V_2 -> V_376 ;
V_604 = V_2 -> V_377 ;
if( V_601 ) {
V_603 = V_2 -> V_378 ;
V_604 = V_2 -> V_379 ;
}
if( V_603 < V_604 ) {
V_602 = V_606 ;
} else if( V_603 == V_604 ) {
V_602 = V_607 ;
} else {
if( V_2 -> V_58 & V_157 ) {
V_602 = V_608 ;
} else {
V_602 = V_609 ;
}
if( V_2 -> V_35 & V_52 ) {
if( V_2 -> V_58 & V_167 ) V_602 = V_609 ;
else if( V_2 -> V_58 & V_165 ) V_602 = V_609 ;
else V_602 = V_610 ;
} else if( V_2 -> V_35 & V_50 ) {
V_602 = V_611 ;
}
do {
if( ( V_602 [ V_605 ] | V_602 [ V_605 + 1 ] << 8 ) == V_603 ) break;
V_605 += 0x42 ;
} while( ( V_602 [ V_605 ] | V_602 [ V_605 + 1 ] << 8 ) != 0xffff );
if( ( V_602 [ V_605 ] | V_602 [ V_605 + 1 ] << 8 ) == 0xffff ) V_605 -= 0x42 ;
}
V_605 += 2 ;
return ( ( unsigned char * ) & V_602 [ V_605 ] ) ;
}
static void
F_113 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned char * V_602 ;
unsigned char V_68 ;
int V_28 , V_113 ;
if( ! ( V_2 -> V_18 & V_612 ) ) return;
V_602 = F_112 ( V_2 , 0 ) ;
for( V_28 = 0x80 , V_113 = 0 ; V_28 <= 0xbf ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_602 [ V_113 ] ) ;
}
if( V_2 -> V_35 & V_62 ) {
V_602 = F_112 ( V_2 , 1 ) ;
for( V_28 = 0xc0 , V_113 = 0 ; V_28 <= 0xff ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_602 [ V_113 ] ) ;
}
}
V_68 = 0x10 ;
if( V_2 -> V_35 & V_62 ) V_68 |= 0x04 ;
F_6 ( V_2 -> V_121 , 0x4e , 0xeb , V_68 ) ;
}
static bool
F_114 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 , unsigned short * V_320 ,
unsigned short * V_383 )
{
if( V_2 -> V_3 < V_5 ) return false ;
if( V_25 <= 0x13 )
( * V_383 ) = V_2 -> V_71 [ V_26 ] . V_326 ;
else
( * V_383 ) = V_2 -> V_32 [ V_319 ] . V_328 ;
( * V_383 ) &= 0x3f ;
( * V_320 ) = 0 ;
if( V_2 -> V_183 == V_238 ) {
if( ! ( V_2 -> V_77 & V_318 ) ) {
( * V_320 ) = 200 ;
}
}
if( V_2 -> V_105 == V_532 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_77 & V_318 ) ( * V_320 ) = 206 ;
}
}
return ( ( ( * V_320 ) != 0 ) ) ;
}
static void
F_115 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_580 )
{
unsigned short V_388 ;
static const unsigned char V_613 [] = {
0xc3 , 0x9e , 0xc3 , 0x9e , 0x02 , 0x02 , 0x02 ,
0xab , 0x87 , 0xab , 0x9e , 0xe7 , 0x02 , 0x02
} ;
if( ! V_2 -> V_133 ) {
if( ( ( ( V_2 -> V_3 == V_149 ) ||
( V_2 -> V_3 == V_115 ) ) &&
( V_2 -> V_349 > 2 ) ) &&
( V_2 -> V_183 == V_238 ) &&
( ! ( V_2 -> V_77 & V_318 ) ) &&
( ! ( V_2 -> V_46 & V_47 ) ) ) {
if( V_25 == 0x13 ) {
F_15 ( V_2 -> V_121 , 0x04 , 0xB9 ) ;
F_15 ( V_2 -> V_121 , 0x05 , 0xCC ) ;
F_15 ( V_2 -> V_121 , 0x06 , 0xA6 ) ;
} else if( ( V_580 & 0x3F ) == 4 ) {
F_15 ( V_2 -> V_121 , 0x01 , 0x2B ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x13 ) ;
F_15 ( V_2 -> V_121 , 0x04 , 0xE5 ) ;
F_15 ( V_2 -> V_121 , 0x05 , 0x08 ) ;
F_15 ( V_2 -> V_121 , 0x06 , 0xE2 ) ;
}
}
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_211 == 0x0c ) {
V_580 &= 0x1f ;
V_388 = 0 ;
if( ! ( V_2 -> V_35 & V_136 ) ) {
if( V_2 -> V_35 & V_85 ) {
V_388 += 7 ;
}
}
V_388 += V_580 ;
if( V_580 >= 4 ) {
F_15 ( V_2 -> V_121 , 0x06 , 0xff ) ;
}
if( ! ( V_2 -> V_35 & V_136 ) ) {
if( V_2 -> V_35 & V_85 ) {
if( V_580 == 4 ) {
F_15 ( V_2 -> V_121 , 0x01 , 0x28 ) ;
}
}
}
F_15 ( V_2 -> V_121 , 0x02 , 0x18 ) ;
F_15 ( V_2 -> V_121 , 0x04 , V_613 [ V_388 ] ) ;
}
}
}
}
static void
F_116 ( struct V_1 * V_2 , unsigned short V_26 , unsigned short V_319 ,
unsigned short V_25 )
{
const struct V_614 * V_615 = NULL ;
unsigned short V_580 , V_373 ;
int V_28 , V_113 ;
if( V_2 -> V_3 != V_350 ) return;
if( ! ( V_2 -> V_18 & V_39 ) ) return;
if( V_2 -> V_133 ) return;
if( V_25 <= 0x13 ) {
V_580 = V_2 -> V_71 [ V_26 ] . V_326 ;
} else {
V_580 = V_2 -> V_32 [ V_319 ] . V_328 ;
}
V_373 = V_580 & 0x3F ;
if( V_2 -> V_77 & V_318 ) V_615 = V_2 -> V_616 ;
else V_615 = V_2 -> V_617 ;
if( V_25 > 0x13 ) {
V_615 = V_2 -> V_616 ;
V_373 = 4 ;
}
F_6 ( V_2 -> V_121 , 0x01 , 0x80 , ( V_615 + V_373 ) -> V_395 [ 0 ] ) ;
F_6 ( V_2 -> V_121 , 0x02 , 0x80 , ( V_615 + V_373 ) -> V_395 [ 1 ] ) ;
for( V_28 = 2 , V_113 = 0x04 ; V_113 <= 0x06 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
for( V_113 = 0x1c ; V_113 <= 0x1d ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
for( V_113 = 0x1f ; V_113 <= 0x21 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
F_15 ( V_2 -> V_121 , 0x23 , ( V_615 + V_373 ) -> V_395 [ 10 ] ) ;
F_6 ( V_2 -> V_121 , 0x25 , 0x0f , ( V_615 + V_373 ) -> V_395 [ 11 ] ) ;
}
static void
F_117 ( struct V_1 * V_2 , unsigned short V_25 )
{
if( ! ( V_2 -> V_18 & V_39 ) ) return;
if( ! ( V_2 -> V_35 & V_386 ) ) return;
if( V_2 -> V_58 & ( V_165 | V_59 ) ) return;
if( ! ( V_2 -> V_58 & V_157 ) ) {
if( V_2 -> V_58 & V_181 ) {
const unsigned char V_618 [] = {
0xa7 , 0x07 , 0xf2 , 0x6e , 0x17 , 0x8b , 0x73 , 0x53 ,
0x13 , 0x40 , 0x34 , 0xf4 , 0x63 , 0xbb , 0xcc , 0x7a ,
0x58 , 0xe4 , 0x73 , 0xda , 0x13
} ;
int V_28 , V_113 ;
for( V_28 = 0x1c , V_113 = 0 ; V_28 <= 0x30 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_618 [ V_113 ] ) ;
}
F_15 ( V_2 -> V_121 , 0x43 , 0x72 ) ;
if( ! ( V_2 -> V_35 & V_52 ) ) {
if( V_2 -> V_58 & V_160 ) {
F_15 ( V_2 -> V_121 , 0x01 , 0x14 ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x1b ) ;
} else {
F_15 ( V_2 -> V_121 , 0x01 , 0x14 ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x1a ) ;
}
}
}
} else {
if( ( V_25 == 0x38 ) || ( V_25 == 0x4a ) || ( V_25 == 0x64 ) ||
( V_25 == 0x52 ) || ( V_25 == 0x58 ) || ( V_25 == 0x5c ) ) {
F_15 ( V_2 -> V_121 , 0x01 , 0x1b ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x54 ) ;
} else {
F_15 ( V_2 -> V_121 , 0x01 , 0x1a ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x53 ) ;
}
}
}
static void
F_118 ( struct V_1 * V_2 , unsigned short V_25 )
{
unsigned short V_68 ;
if( ! ( V_2 -> V_77 & V_318 ) ) {
if( V_2 -> V_378 == 525 ) {
V_68 = 0xc3 ;
if( V_2 -> V_84 <= V_146 ) {
V_68 ++ ;
if( V_2 -> V_18 & V_39 ) V_68 += 2 ;
}
F_15 ( V_2 -> V_121 , 0x2f , V_68 ) ;
F_15 ( V_2 -> V_121 , 0x30 , 0xb3 ) ;
} else if( V_2 -> V_378 == 420 ) {
V_68 = 0x4d ;
if( V_2 -> V_84 <= V_146 ) {
V_68 ++ ;
if( V_2 -> V_18 & V_39 ) V_68 ++ ;
}
F_15 ( V_2 -> V_121 , 0x2f , V_68 ) ;
}
}
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_183 == V_240 ) {
if( V_2 -> V_18 & V_619 ) {
F_2 ( V_2 -> V_121 , 0x1a , 0x03 ) ;
}
V_68 = 1 ;
if( V_25 <= 0x13 ) V_68 = 3 ;
F_15 ( V_2 -> V_121 , 0x0b , V_68 ) ;
}
#if 0
if((SiS_Pr->SiS_PanelXRes == 1280) && (SiS_Pr->SiS_PanelYRes == 768)) {
if(SiS_Pr->SiS_VBInfo & SetSimuScanMode) {
if(((SiS_Pr->SiS_HDE == 640) && (SiS_Pr->SiS_VDE == 480)) ||
((SiS_Pr->SiS_HDE == 320) && (SiS_Pr->SiS_VDE == 240))) {
SiS_SetReg(SiS_Part2Port,0x01,0x2b);
SiS_SetReg(SiS_Part2Port,0x02,0x13);
SiS_SetReg(SiS_Part2Port,0x04,0xe5);
SiS_SetReg(SiS_Part2Port,0x05,0x08);
SiS_SetReg(SiS_Part2Port,0x06,0xe2);
SiS_SetReg(SiS_Part2Port,0x1c,0x21);
SiS_SetReg(SiS_Part2Port,0x1d,0x45);
SiS_SetReg(SiS_Part2Port,0x1f,0x0b);
SiS_SetReg(SiS_Part2Port,0x20,0x00);
SiS_SetReg(SiS_Part2Port,0x21,0xa9);
SiS_SetReg(SiS_Part2Port,0x23,0x0b);
SiS_SetReg(SiS_Part2Port,0x25,0x04);
}
}
}
#endif
}
}
static void
F_119 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_28 , V_113 , V_130 , V_131 , V_388 , V_620 , V_363 , V_68 ;
unsigned short V_572 , V_66 , V_580 , V_621 ;
unsigned int V_622 , V_623 ;
bool V_624 ;
const unsigned char * V_625 ;
#ifdef V_95
unsigned short V_373 , V_320 ;
const struct V_614 * V_615 = NULL ;
if( V_2 -> V_35 & V_44 ) return;
#endif
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_580 = V_2 -> V_71 [ V_26 ] . V_326 ;
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
V_580 = 0 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_580 = V_2 -> V_32 [ V_319 ] . V_328 ;
}
V_68 = 0 ;
if( ! ( V_2 -> V_35 & V_53 ) ) V_68 |= 0x08 ;
if( ! ( V_2 -> V_35 & V_54 ) ) V_68 |= 0x04 ;
if( V_2 -> V_35 & V_55 ) V_68 |= 0x02 ;
if( V_2 -> V_35 & V_50 ) V_68 |= 0x01 ;
if( ! ( V_2 -> V_58 & V_157 ) ) V_68 |= 0x10 ;
F_15 ( V_2 -> V_121 , 0x00 , V_68 ) ;
V_623 = 0x01 ;
V_625 = V_2 -> V_626 ;
V_624 = false ;
if( ( V_2 -> V_18 & V_39 ) &&
( ( ! ( V_2 -> V_35 & V_85 ) ) ||
( V_2 -> V_58 & V_178 ) ) ) {
V_624 = true ;
}
if( V_2 -> V_35 & V_50 ) {
V_625 = V_2 -> V_627 ;
if( V_2 -> V_35 & V_85 ) {
V_625 = V_2 -> V_628 ;
if( V_2 -> V_58 & V_178 ) {
V_625 = V_2 -> V_629 ;
}
}
} else if( V_2 -> V_35 & V_52 ) {
V_28 = 0 ;
if( V_2 -> V_58 & V_59 ) V_28 = 2 ;
else if( V_2 -> V_58 & V_165 ) V_28 = 1 ;
V_625 = & V_630 [ V_28 ] [ 0 ] ;
V_623 = 0x00 ;
} else if( V_2 -> V_58 & V_157 ) {
if( V_624 ) V_623 = 0x09 ;
} else {
V_625 = V_2 -> V_631 ;
V_623 = ( V_2 -> V_58 & V_164 ) ? 0x01 : 0x00 ;
if( V_624 ) V_623 += 8 ;
}
if( V_2 -> V_58 & ( V_160 | V_162 ) ) {
V_623 = ( V_2 -> V_58 & V_160 ) ? 0x02 : 0x03 ;
if( V_624 ) V_623 += 8 ;
}
if( V_2 -> V_58 & V_181 ) {
if( V_2 -> V_58 & V_160 ) {
V_623 = 0x05 ;
} else if( V_2 -> V_58 & V_164 ) {
V_623 = 0x11 ;
} else {
V_623 = 0x10 ;
}
}
for( V_28 = 0x31 , V_113 = 0 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_632 [ ( V_623 * 4 ) + V_113 ] ) ;
}
for( V_28 = 0x01 , V_113 = 0 ; V_28 <= 0x2D ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_625 [ V_113 ] ) ;
}
for( V_28 = 0x39 ; V_28 <= 0x45 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_625 [ V_113 ] ) ;
}
if( V_2 -> V_35 & V_62 ) {
if( V_2 -> V_84 != V_633 ) {
F_4 ( V_2 -> V_121 , 0x3A , 0x1F ) ;
}
}
F_2 ( V_2 -> V_121 , 0x0A , V_2 -> V_408 ) ;
F_15 ( V_2 -> V_121 , 0x35 , V_2 -> V_410 ) ;
F_15 ( V_2 -> V_121 , 0x36 , V_2 -> V_411 ) ;
F_15 ( V_2 -> V_121 , 0x37 , V_2 -> V_412 ) ;
F_15 ( V_2 -> V_121 , 0x38 , V_2 -> V_413 ) ;
if( V_2 -> V_35 & V_50 ) V_130 = 950 ;
else if( V_2 -> V_58 & V_59 ) V_130 = 680 ;
else if( V_2 -> V_58 & V_157 ) V_130 = 520 ;
else V_130 = 440 ;
if( ( ( V_2 -> V_35 & V_50 ) && ( V_2 -> V_379 <= V_130 ) ) ||
( ( V_2 -> V_35 & V_386 ) &&
( ( V_2 -> V_376 == 1024 ) || ( V_2 -> V_379 <= V_130 ) ) ) ) {
V_130 -= V_2 -> V_379 ;
V_130 >>= 1 ;
if( ! ( V_2 -> V_58 & ( V_165 | V_59 ) ) ) {
V_130 >>= 1 ;
}
V_130 &= 0x00ff ;
V_68 = V_130 + ( unsigned short ) V_625 [ 0 ] ;
F_15 ( V_2 -> V_121 , 0x01 , V_68 ) ;
V_68 = V_130 + ( unsigned short ) V_625 [ 1 ] ;
F_15 ( V_2 -> V_121 , 0x02 , V_68 ) ;
if( ( V_2 -> V_35 & V_599 ) && ( V_2 -> V_376 >= 1024 ) ) {
if( V_2 -> V_58 & V_157 ) {
F_15 ( V_2 -> V_121 , 0x01 , 0x1b ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x54 ) ;
} else {
F_15 ( V_2 -> V_121 , 0x01 , 0x17 ) ;
F_15 ( V_2 -> V_121 , 0x02 , 0x1d ) ;
}
}
}
V_388 = V_2 -> V_397 ;
if( F_36 ( V_2 ) ) V_388 >>= 1 ;
V_388 -- ;
if( V_2 -> V_18 & V_39 ) V_388 -- ;
F_15 ( V_2 -> V_121 , 0x1B , V_388 ) ;
F_6 ( V_2 -> V_121 , 0x1D , 0xF0 , ( ( V_388 >> 8 ) & 0x0f ) ) ;
V_388 = V_2 -> V_397 >> 1 ;
if( F_36 ( V_2 ) ) V_388 >>= 1 ;
V_388 += 7 ;
if( V_2 -> V_35 & V_50 ) V_388 -= 4 ;
F_6 ( V_2 -> V_121 , 0x22 , 0x0F , ( ( V_388 << 4 ) & 0xf0 ) ) ;
V_131 = V_625 [ V_113 ] | ( V_625 [ V_113 + 1 ] << 8 ) ;
V_131 += V_388 ;
F_15 ( V_2 -> V_121 , 0x24 , V_131 ) ;
F_6 ( V_2 -> V_121 , 0x25 , 0x0F , ( ( V_131 >> 4 ) & 0xf0 ) ) ;
V_131 += 8 ;
if( V_2 -> V_35 & V_50 ) {
V_131 -= 4 ;
V_388 = V_131 ;
}
F_6 ( V_2 -> V_121 , 0x29 , 0x0F , ( ( V_131 << 4 ) & 0xf0 ) ) ;
V_113 += 2 ;
V_388 += ( V_625 [ V_113 ] | ( V_625 [ V_113 + 1 ] << 8 ) ) ;
F_15 ( V_2 -> V_121 , 0x27 , V_388 ) ;
F_6 ( V_2 -> V_121 , 0x28 , 0x0F , ( ( V_388 >> 4 ) & 0xf0 ) ) ;
V_388 += 8 ;
if( V_2 -> V_35 & V_50 ) V_388 -= 4 ;
F_6 ( V_2 -> V_121 , 0x2A , 0x0F , ( ( V_388 << 4 ) & 0xf0 ) ) ;
V_388 = V_2 -> V_397 >> 1 ;
if( F_36 ( V_2 ) ) V_388 >>= 1 ;
V_113 += 2 ;
V_388 -= ( V_625 [ V_113 ] | ( ( V_625 [ V_113 + 1 ] ) << 8 ) ) ;
F_6 ( V_2 -> V_121 , 0x2D , 0x0F , ( ( V_388 << 4 ) & 0xf0 ) ) ;
V_388 -= 11 ;
if( ! ( V_2 -> V_35 & V_62 ) ) {
V_388 = F_106 ( V_2 ) - 1 ;
}
F_15 ( V_2 -> V_121 , 0x2E , V_388 ) ;
V_131 = V_2 -> V_379 ;
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_378 == 360 ) V_131 = 746 ;
if( V_2 -> V_378 == 375 ) V_131 = 746 ;
if( V_2 -> V_378 == 405 ) V_131 = 853 ;
} else if( ( V_2 -> V_35 & V_62 ) &&
( ! ( V_2 -> V_58 & ( V_165 | V_59 ) ) ) ) {
V_131 >>= 1 ;
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_58 & V_178 ) {
if( ( V_25 <= 0x13 ) && ( V_580 == 1 ) ) V_131 ++ ;
} else if( V_2 -> V_35 & V_85 ) {
if( V_2 -> V_84 <= V_146 ) {
if( V_580 == 4 ) V_131 ++ ;
}
}
}
if( V_2 -> V_35 & V_85 ) {
if( V_2 -> V_35 & V_50 ) {
if( ( V_25 == 0x2f ) || ( V_25 == 0x5d ) || ( V_25 == 0x5e ) ) V_131 ++ ;
}
if( ! ( V_2 -> V_58 & V_157 ) ) {
if( V_25 == 0x03 ) V_131 ++ ;
}
}
}
V_131 -= 2 ;
F_15 ( V_2 -> V_121 , 0x2F , V_131 ) ;
V_68 = ( V_388 >> 8 ) & 0x0F ;
V_68 |= ( ( V_131 >> 2 ) & 0xC0 ) ;
if( V_2 -> V_35 & ( V_54 | V_53 ) ) {
V_68 |= 0x10 ;
if( V_2 -> V_35 & V_53 ) V_68 |= 0x20 ;
}
F_15 ( V_2 -> V_121 , 0x30 , V_68 ) ;
if( V_2 -> V_18 & V_634 ) {
F_6 ( V_2 -> V_114 , 0x10 , 0xdf , ( ( V_131 & 0x0400 ) >> 5 ) ) ;
}
if( V_2 -> V_18 & V_39 ) {
V_131 = V_2 -> V_379 ;
if( ( V_2 -> V_35 & V_62 ) &&
( ! ( V_2 -> V_58 & ( V_165 | V_59 ) ) ) ) {
V_131 >>= 1 ;
}
V_131 -= 3 ;
V_68 = ( ( V_131 >> 3 ) & 0x60 ) | 0x18 ;
F_15 ( V_2 -> V_121 , 0x46 , V_68 ) ;
F_15 ( V_2 -> V_121 , 0x47 , V_131 ) ;
if( V_2 -> V_18 & V_634 ) {
F_6 ( V_2 -> V_114 , 0x10 , 0xbf , ( ( V_131 & 0x0400 ) >> 4 ) ) ;
}
}
V_131 = 0 ;
if( ! ( V_66 & V_75 ) ) {
if( V_2 -> V_376 >= V_2 -> V_377 ) {
V_130 = 0 ;
V_131 |= 0x20 ;
}
}
V_620 = V_363 = 0x01 ;
if( V_2 -> V_35 & V_62 ) {
if( V_2 -> V_376 >= 960 ) {
if( ( ! ( V_66 & V_75 ) ) || ( V_2 -> V_3 < V_5 ) ) {
V_363 = 0x20 ;
if( V_2 -> V_376 >= 1280 ) {
V_620 = 20 ;
V_131 &= ~ 0x20 ;
} else if( V_2 -> V_376 >= 1024 ) {
V_620 = 25 ;
} else {
V_620 = 25 ;
}
}
}
}
if( ! ( V_131 & 0x20 ) ) {
if( V_66 & V_75 ) V_363 <<= 1 ;
V_622 = ( ( V_2 -> V_376 * V_620 ) / V_363 ) << 13 ;
if( V_2 -> V_18 & V_39 ) V_622 <<= 3 ;
V_130 = V_622 / V_2 -> V_377 ;
if( V_622 % V_2 -> V_377 ) V_130 ++ ;
V_131 |= ( ( V_130 >> 8 ) & 0x1F ) ;
V_388 = V_130 >> 13 ;
}
F_15 ( V_2 -> V_121 , 0x44 , V_130 ) ;
F_6 ( V_2 -> V_121 , 0x45 , 0xC0 , V_131 ) ;
if( V_2 -> V_18 & V_39 ) {
V_388 &= 0x07 ;
if( V_131 & 0x20 ) V_388 = 0 ;
F_6 ( V_2 -> V_121 , 0x46 , 0xF8 , V_388 ) ;
if( V_2 -> V_58 & V_157 ) {
V_131 = 0x0382 ;
V_388 = 0x007e ;
} else {
V_131 = 0x0369 ;
V_388 = 0x0061 ;
}
F_15 ( V_2 -> V_121 , 0x4B , V_131 ) ;
F_15 ( V_2 -> V_121 , 0x4C , V_388 ) ;
V_68 = ( V_388 & 0x0300 ) >> 6 ;
V_68 |= ( ( V_131 >> 8 ) & 0x03 ) ;
if( V_2 -> V_35 & V_52 ) {
V_68 |= 0x10 ;
if( V_2 -> V_58 & V_165 ) V_68 |= 0x20 ;
else if( V_2 -> V_58 & V_59 ) V_68 |= 0x40 ;
}
F_15 ( V_2 -> V_121 , 0x4D , V_68 ) ;
V_68 = F_8 ( V_2 -> V_121 , 0x43 ) ;
F_15 ( V_2 -> V_121 , 0x43 , ( V_68 - 3 ) ) ;
F_117 ( V_2 , V_25 ) ;
if( V_2 -> V_18 & V_370 ) {
V_68 = 0 ;
if( V_2 -> V_58 & V_160 ) V_68 = 8 ;
F_6 ( V_2 -> V_121 , 0x4e , 0xf7 , V_68 ) ;
}
}
if( V_2 -> V_58 & V_160 ) {
if( ! ( V_2 -> V_58 & V_181 ) ) {
V_68 = F_8 ( V_2 -> V_121 , 0x01 ) ;
F_15 ( V_2 -> V_121 , 0x01 , ( V_68 - 1 ) ) ;
}
F_4 ( V_2 -> V_121 , 0x00 , 0xEF ) ;
}
if( V_2 -> V_35 & V_50 ) {
if( ! ( V_2 -> V_35 & V_85 ) ) {
F_15 ( V_2 -> V_121 , 0x0B , 0x00 ) ;
}
}
if( V_2 -> V_35 & V_62 ) return;
V_131 = V_2 -> V_377 ;
if( F_36 ( V_2 ) ) V_131 >>= 1 ;
V_131 -- ;
F_15 ( V_2 -> V_121 , 0x2C , V_131 ) ;
F_6 ( V_2 -> V_121 , 0x2B , 0x0F , ( ( V_131 >> 4 ) & 0xf0 ) ) ;
V_68 = 0x01 ;
if( V_2 -> V_183 == V_239 ) {
if( V_2 -> V_84 == V_635 ) {
if( V_2 -> V_376 >= 1024 ) {
V_68 = 0x02 ;
if( V_2 -> V_77 & V_318 ) {
V_68 = 0x01 ;
}
}
}
}
F_15 ( V_2 -> V_121 , 0x0B , V_68 ) ;
V_131 = V_2 -> V_379 - 1 ;
F_15 ( V_2 -> V_121 , 0x03 , V_131 ) ;
F_6 ( V_2 -> V_121 , 0x0C , 0xF8 , ( ( V_131 >> 8 ) & 0x07 ) ) ;
V_388 = V_2 -> V_399 - 1 ;
F_15 ( V_2 -> V_121 , 0x19 , V_388 ) ;
V_68 = ( V_388 >> 3 ) & 0xE0 ;
if( V_2 -> V_46 & V_236 ) {
if( F_8 ( V_2 -> V_6 , 0x00 ) & 0x01 ) {
V_68 |= 0x10 ;
}
}
F_6 ( V_2 -> V_121 , 0x1A , 0x0f , V_68 ) ;
F_4 ( V_2 -> V_121 , 0x09 , 0xF0 ) ;
F_4 ( V_2 -> V_121 , 0x0A , 0xF0 ) ;
F_4 ( V_2 -> V_121 , 0x17 , 0xFB ) ;
F_4 ( V_2 -> V_121 , 0x18 , 0xDF ) ;
#ifdef V_95
if( F_114 ( V_2 , V_25 , V_26 , V_319 ,
& V_320 , & V_373 ) ) {
switch( V_320 ) {
case 206 : V_615 = V_636 ; break;
default:
case 200 : V_615 = V_2 -> V_616 ; break;
}
F_6 ( V_2 -> V_121 , 0x01 , 0x80 , ( V_615 + V_373 ) -> V_395 [ 0 ] ) ;
F_6 ( V_2 -> V_121 , 0x02 , 0x80 , ( V_615 + V_373 ) -> V_395 [ 1 ] ) ;
for( V_28 = 2 , V_113 = 0x04 ; V_113 <= 0x06 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
for( V_113 = 0x1c ; V_113 <= 0x1d ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
for( V_113 = 0x1f ; V_113 <= 0x21 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_113 , ( V_615 + V_373 ) -> V_395 [ V_28 ] ) ;
}
F_15 ( V_2 -> V_121 , 0x23 , ( V_615 + V_373 ) -> V_395 [ 10 ] ) ;
F_6 ( V_2 -> V_121 , 0x25 , 0x0f , ( V_615 + V_373 ) -> V_395 [ 11 ] ) ;
F_118 ( V_2 , V_25 ) ;
} else {
#endif
if( V_2 -> V_46 & V_47 ) {
if( ( V_2 -> V_46 & V_48 ) || ( V_2 -> V_248 == V_2 -> V_379 ) ) {
V_131 = V_2 -> V_379 - 1 ;
V_388 = V_2 -> V_399 - 1 ;
} else {
V_131 = V_2 -> V_379 + ( ( V_2 -> V_248 - V_2 -> V_379 ) / 2 ) ;
V_388 = V_2 -> V_399 - ( ( V_2 -> V_248 - V_2 -> V_379 ) / 2 ) ;
}
} else {
V_131 = V_2 -> V_248 ;
V_388 = V_2 -> V_399 ;
V_130 = 1 ;
if( V_2 -> V_248 != V_2 -> V_379 ) {
V_130 = V_2 -> V_248 ;
if( V_2 -> V_248 < V_2 -> V_379 ) {
V_130 = V_388 = 0 ;
} else {
V_130 -= V_2 -> V_379 ;
}
V_130 >>= 1 ;
}
V_388 -= V_130 ;
V_131 -= V_130 ;
}
F_15 ( V_2 -> V_121 , 0x05 , V_388 ) ;
F_15 ( V_2 -> V_121 , 0x06 , V_131 ) ;
V_68 = ( V_131 >> 5 ) & 0x38 ;
V_68 |= ( ( V_388 >> 8 ) & 0x07 ) ;
F_15 ( V_2 -> V_121 , 0x02 , V_68 ) ;
V_130 = V_2 -> V_379 ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
V_130 = V_2 -> V_248 ;
}
V_388 = ( V_2 -> V_399 - V_130 ) >> 4 ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
if( V_2 -> V_248 != V_2 -> V_379 ) {
V_388 = ( V_2 -> V_399 - V_130 ) / 10 ;
}
}
V_131 = ( ( V_2 -> V_399 + V_2 -> V_379 ) >> 1 ) - 1 ;
if( V_2 -> V_46 & V_47 ) {
if( V_2 -> V_248 != V_2 -> V_379 ) {
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_130 = V_2 -> V_399 - V_2 -> V_248 ;
if( V_130 % 4 ) { V_130 >>= 2 ; V_130 ++ ; }
else { V_130 >>= 2 ; }
V_131 -= ( V_130 - 1 ) ;
} else {
V_131 -= 10 ;
if( V_131 <= V_2 -> V_379 ) V_131 = V_2 -> V_379 + 1 ;
}
}
}
if( V_2 -> V_183 == V_238 ) {
V_131 ++ ;
if( ( ! ( V_2 -> V_46 & V_47 ) ) || ( V_580 == 6 ) ) {
if( V_2 -> V_77 & V_318 ) {
V_131 = 770 ;
V_388 = 3 ;
}
}
}
if( V_2 -> V_133 ) {
V_131 = V_2 -> V_569 ;
}
F_15 ( V_2 -> V_121 , 0x04 , V_131 ) ;
V_68 = ( V_131 >> 4 ) & 0xF0 ;
V_131 += ( V_388 + 1 ) ;
V_68 |= ( V_131 & 0x0F ) ;
if( V_2 -> V_133 ) {
V_68 &= 0xf0 ;
V_68 |= ( V_2 -> V_570 & 0x0f ) ;
}
F_15 ( V_2 -> V_121 , 0x01 , V_68 ) ;
#ifdef V_94
F_115 ( V_2 , V_25 , V_580 ) ;
#endif
V_621 = 7 ;
if( V_2 -> V_18 & V_39 ) V_621 += 2 ;
if( V_2 -> V_18 & V_370 ) V_621 += 2 ;
if( F_36 ( V_2 ) ) V_621 ++ ;
else if( V_2 -> V_18 & V_637 ) V_621 ++ ;
V_68 = 0 ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
if( V_2 -> V_247 != V_2 -> V_377 ) {
V_68 = V_2 -> V_397 - ( ( V_2 -> V_247 - V_2 -> V_377 ) / 2 ) ;
if( F_36 ( V_2 ) ) V_68 >>= 1 ;
}
}
V_68 += V_621 ;
F_15 ( V_2 -> V_121 , 0x1F , V_68 ) ;
F_6 ( V_2 -> V_121 , 0x20 , 0x0F , ( ( V_68 >> 4 ) & 0xf0 ) ) ;
V_388 = V_2 -> V_397 ;
V_130 = V_131 = V_2 -> V_377 ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
if( V_2 -> V_247 != V_2 -> V_377 ) {
V_130 = V_2 -> V_247 ;
V_131 = V_2 -> V_247 - ( ( V_2 -> V_247 - V_2 -> V_377 ) / 2 ) ;
}
}
if( F_36 ( V_2 ) ) {
V_388 >>= 1 ;
V_131 >>= 1 ;
V_130 >>= 1 ;
}
V_131 += V_621 ;
F_15 ( V_2 -> V_121 , 0x23 , V_131 ) ;
F_6 ( V_2 -> V_121 , 0x25 , 0xF0 , ( ( V_131 >> 8 ) & 0x0f ) ) ;
V_388 = ( V_388 - V_130 ) >> 2 ;
V_131 += V_388 ;
V_572 = V_131 ;
if( V_2 -> V_183 == V_239 ) {
if( V_2 -> V_46 & V_47 ) {
if( V_2 -> V_46 & V_48 ) {
if( V_2 -> V_377 == 1280 ) V_131 = ( V_131 & 0xff00 ) | 0x47 ;
}
}
}
if( V_2 -> V_133 ) {
V_131 = V_2 -> V_565 ;
if( V_66 & V_75 ) V_131 <<= 1 ;
if( F_36 ( V_2 ) ) V_131 >>= 1 ;
V_131 += V_621 ;
}
F_15 ( V_2 -> V_121 , 0x1C , V_131 ) ;
F_6 ( V_2 -> V_121 , 0x1D , 0x0F , ( ( V_131 >> 4 ) & 0xf0 ) ) ;
V_131 = V_572 ;
V_388 <<= 1 ;
if( ( V_2 -> V_46 & V_47 ) && ( ! ( V_2 -> V_46 & V_48 ) ) ) {
if( V_2 -> V_247 != V_2 -> V_377 ) V_388 >>= 2 ;
}
V_131 += V_388 ;
if( V_2 -> V_133 ) {
V_131 = V_2 -> V_566 ;
if( V_66 & V_75 ) V_131 <<= 1 ;
if( F_36 ( V_2 ) ) V_131 >>= 1 ;
V_131 += V_621 ;
}
F_15 ( V_2 -> V_121 , 0x21 , V_131 ) ;
F_118 ( V_2 , V_25 ) ;
#ifdef V_94
F_116 ( V_2 , V_26 , V_319 , V_25 ) ;
#endif
#ifdef V_95
}
#endif
}
static void
F_120 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_28 ;
const unsigned char * V_638 ;
if( V_2 -> V_35 & V_44 ) return;
#ifndef F_121
F_15 ( V_2 -> V_639 , 0x00 , 0x00 ) ;
#else
F_122
#endif
if( V_2 -> V_58 & V_157 ) {
F_15 ( V_2 -> V_639 , 0x13 , 0xFA ) ;
F_15 ( V_2 -> V_639 , 0x14 , 0xC8 ) ;
} else {
F_15 ( V_2 -> V_639 , 0x13 , 0xF5 ) ;
F_15 ( V_2 -> V_639 , 0x14 , 0xB7 ) ;
}
if( V_2 -> V_58 & V_160 ) {
F_15 ( V_2 -> V_639 , 0x13 , 0xFA ) ;
F_15 ( V_2 -> V_639 , 0x14 , 0xC8 ) ;
F_15 ( V_2 -> V_639 , 0x3D , 0xA8 ) ;
}
V_638 = NULL ;
if( V_2 -> V_35 & V_50 ) {
V_638 = V_2 -> V_640 ;
if( V_2 -> V_58 & V_178 ) {
V_638 = V_2 -> V_641 ;
}
} else if( V_2 -> V_35 & V_52 ) {
if( ! ( V_2 -> V_58 & V_167 ) ) {
V_638 = V_642 ;
if( V_2 -> V_58 & V_59 ) V_638 = V_643 ;
}
}
if( V_638 ) {
for( V_28 = 0 ; V_28 <= 0x3E ; V_28 ++ ) {
F_15 ( V_2 -> V_639 , V_28 , V_638 [ V_28 ] ) ;
}
if( V_2 -> V_18 & V_370 ) {
if( V_2 -> V_58 & V_165 ) {
F_15 ( V_2 -> V_639 , 0x28 , 0x3f ) ;
}
}
}
#ifdef F_121
V_644
#endif
}
static void
F_123 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_68 , V_88 , V_132 = 0 ;
unsigned char * V_11 = V_2 -> V_12 ;
if( ! ( V_2 -> V_18 & V_370 ) ) return;
if( ! ( V_2 -> V_35 & ( V_50 | V_52 ) ) ) return;
if( V_2 -> V_3 >= V_4 ) return;
if( ( V_2 -> V_3 >= V_9 ) && ( V_2 -> V_17 ) ) {
if( ! ( V_11 [ 0x61 ] & 0x04 ) ) return;
}
if( V_25 > 0x13 ) {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
F_2 ( V_2 -> V_114 , 0x3a , 0x08 ) ;
V_68 = F_8 ( V_2 -> V_114 , 0x3a ) ;
if( ! ( V_68 & 0x01 ) ) {
F_4 ( V_2 -> V_114 , 0x3a , 0xdf ) ;
F_4 ( V_2 -> V_114 , 0x25 , 0xfc ) ;
if( ( V_2 -> V_3 < V_9 ) && ( ! ( V_2 -> V_17 ) ) ) {
F_4 ( V_2 -> V_114 , 0x25 , 0xf8 ) ;
}
F_4 ( V_2 -> V_114 , 0x0f , 0xfb ) ;
if( V_2 -> V_58 & V_59 ) V_68 = 0x0000 ;
else if( V_2 -> V_58 & V_165 ) V_68 = 0x0002 ;
else if( V_2 -> V_58 & V_166 ) V_68 = 0x0400 ;
else V_68 = 0x0402 ;
if( ( V_2 -> V_3 >= V_9 ) || ( V_2 -> V_17 ) ) {
V_88 = 0 ;
if( V_2 -> V_58 & V_177 ) V_88 = 4 ;
F_6 ( V_2 -> V_114 , 0x0f , 0xfb , V_88 ) ;
if( V_2 -> V_58 & V_176 ) V_68 |= 0x01 ;
F_6 ( V_2 -> V_114 , 0x26 , 0x7c , ( V_68 & 0xff ) ) ;
F_6 ( V_2 -> V_114 , 0x3a , 0xfb , ( V_68 >> 8 ) ) ;
if( V_25 > 0x13 ) {
F_4 ( V_2 -> V_21 , 0x39 , 0xfd ) ;
}
} else {
V_88 = F_8 ( V_2 -> V_21 , 0x3b ) & 0x03 ;
if( V_88 == 0x01 ) V_68 |= 0x01 ;
if( V_88 == 0x03 ) V_68 |= 0x04 ;
F_6 ( V_2 -> V_114 , 0x26 , 0xf8 , ( V_68 & 0xff ) ) ;
F_6 ( V_2 -> V_114 , 0x3a , 0xfb , ( V_68 >> 8 ) ) ;
if( V_25 > 0x13 ) {
F_4 ( V_2 -> V_114 , 0x3b , 0xfd ) ;
}
}
#if 0
if(SiS_Pr->ChipType >= SIS_661) {
if(SiS_Pr->SiS_TVMode & TVAspect43) {
if(SiS_Pr->SiS_TVMode & TVSetYPbPr750p) {
if(resinfo == SIS_RI_1024x768) {
SiS_ShiftXPos(SiS_Pr, 97);
} else {
SiS_ShiftXPos(SiS_Pr, 111);
}
} else if(SiS_Pr->SiS_TVMode & TVSetHiVision) {
SiS_ShiftXPos(SiS_Pr, 136);
}
}
}
#endif
}
}
static void
F_124 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_645 , V_68 , V_646 , V_647 ;
if( V_2 -> V_133 ) {
V_646 = V_2 -> V_648 ;
V_647 = V_2 -> V_649 ;
} else {
V_645 = F_59 ( V_2 , V_25 , V_26 , V_319 ) ;
V_646 = V_2 -> V_200 [ V_645 ] . V_202 ;
V_647 = V_2 -> V_200 [ V_645 ] . V_204 ;
}
if( V_2 -> V_18 & V_39 ) {
if( V_2 -> V_58 & ( V_181 | V_180 ) ) {
F_15 ( V_2 -> V_114 , 0x0a , 0x57 ) ;
F_15 ( V_2 -> V_114 , 0x0b , 0x46 ) ;
F_15 ( V_2 -> V_114 , 0x1f , 0xf6 ) ;
} else {
F_15 ( V_2 -> V_114 , 0x0a , V_646 ) ;
F_15 ( V_2 -> V_114 , 0x0b , V_647 ) ;
}
} else {
F_15 ( V_2 -> V_114 , 0x0a , 0x01 ) ;
F_15 ( V_2 -> V_114 , 0x0b , V_647 ) ;
F_15 ( V_2 -> V_114 , 0x0a , V_646 ) ;
}
F_15 ( V_2 -> V_114 , 0x12 , 0x00 ) ;
V_68 = 0x08 ;
if( V_2 -> V_35 & V_36 ) V_68 |= 0x20 ;
F_2 ( V_2 -> V_114 , 0x12 , V_68 ) ;
}
static void
F_125 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_18 & V_235 ) {
if( ( F_32 ( V_2 ) ) ||
( F_34 ( V_2 ) ) ) {
if( V_2 -> V_46 & V_120 ) {
F_2 ( V_2 -> V_114 , 0x27 , 0x2c ) ;
} else {
F_4 ( V_2 -> V_114 , 0x27 , ~ 0x20 ) ;
}
}
}
}
if( V_2 -> V_18 & V_513 ) {
F_15 ( V_2 -> V_114 , 0x2a , 0x00 ) ;
#ifdef F_79
F_4 ( V_2 -> V_114 , 0x30 , 0x0c ) ;
#endif
F_15 ( V_2 -> V_114 , 0x34 , 0x10 ) ;
}
}
static void
F_126 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_130 , V_388 , V_131 , V_66 , V_68 , V_132 ;
unsigned int V_574 , V_573 , V_650 ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
} else if( V_2 -> V_133 ) {
V_66 = V_2 -> V_375 ;
V_132 = 0 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_18 & V_19 ) {
if( V_2 -> V_35 & V_44 ) {
F_15 ( V_2 -> V_114 , 0x24 , 0x0e ) ;
}
}
}
if( V_2 -> V_18 & ( V_370 | V_637 ) ) {
if( V_2 -> V_35 & V_62 ) {
F_4 ( V_2 -> V_114 , 0x10 , 0x9f ) ;
}
}
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_35 & V_44 ) {
F_125 ( V_2 ) ;
return;
}
}
F_15 ( V_2 -> V_114 , 0x13 , V_2 -> V_390 ) ;
V_131 = V_2 -> V_389 ;
F_15 ( V_2 -> V_114 , 0x14 , V_131 ) ;
V_68 = ( V_131 >> 1 ) & 0x80 ;
V_388 = V_2 -> V_396 - 1 ;
F_15 ( V_2 -> V_114 , 0x16 , V_388 ) ;
V_68 |= ( ( V_388 >> 5 ) & 0x78 ) ;
V_388 = V_2 -> V_398 - 1 ;
if( ! ( V_2 -> V_35 & V_62 ) ) V_388 -= 5 ;
F_15 ( V_2 -> V_114 , 0x17 , V_388 ) ;
V_68 |= ( ( V_388 >> 8 ) & 0x07 ) ;
F_15 ( V_2 -> V_114 , 0x15 , V_68 ) ;
V_131 = V_2 -> V_376 ;
if( V_66 & V_75 ) V_131 >>= 1 ;
if( F_36 ( V_2 ) ) V_131 >>= 1 ;
if( V_2 -> V_35 & V_43 ) {
V_68 = 0 ;
if( V_131 > 800 ) V_68 = 0x60 ;
} else if( V_2 -> V_35 & V_50 ) {
V_68 = 0 ;
if( V_131 > 1024 ) V_68 = 0xC0 ;
else if( V_131 >= 960 ) V_68 = 0xA0 ;
} else if( V_2 -> V_58 & ( V_165 | V_59 ) ) {
V_68 = 0 ;
if( V_131 >= 1280 ) V_68 = 0x40 ;
else if( V_131 >= 1024 ) V_68 = 0x20 ;
} else {
V_68 = 0x80 ;
if( V_131 >= 1024 ) V_68 = 0xA0 ;
}
V_68 |= V_2 -> V_651 ;
if( V_2 -> V_18 & V_99 ) {
if( V_2 -> V_183 != V_239 ) {
V_68 &= 0xf0 ;
V_68 |= 0x0A ;
}
}
F_6 ( V_2 -> V_114 , 0x0E , 0x10 , V_68 ) ;
V_573 = V_2 -> V_378 ;
V_574 = V_2 -> V_379 ;
if( V_2 -> V_35 & V_50 ) {
if( ! ( V_68 & 0xE0 ) ) V_574 >>= 1 ;
}
V_388 = V_2 -> V_409 ;
F_15 ( V_2 -> V_114 , 0x18 , V_388 ) ;
V_388 >>= 8 ;
V_388 |= 0x40 ;
if( V_573 <= V_574 ) {
V_388 ^= 0x40 ;
} else {
V_573 -= V_574 ;
}
V_573 *= ( 256 * 1024 ) ;
V_650 = V_573 % V_574 ;
V_573 /= V_574 ;
if( V_650 ) V_573 ++ ;
V_68 = ( unsigned short ) ( V_573 & 0x000000FF ) ;
F_15 ( V_2 -> V_114 , 0x1B , V_68 ) ;
V_68 = ( unsigned short ) ( ( V_573 & 0x0000FF00 ) >> 8 ) ;
F_15 ( V_2 -> V_114 , 0x1A , V_68 ) ;
V_68 = ( unsigned short ) ( ( V_573 >> 12 ) & 0x70 ) ;
V_68 |= ( V_388 & 0x4F ) ;
F_15 ( V_2 -> V_114 , 0x19 , V_68 ) ;
if( V_2 -> V_18 & V_39 ) {
F_15 ( V_2 -> V_114 , 0x1C , 0x28 ) ;
V_131 = 0 ;
if( V_2 -> V_58 & ( V_166 | V_59 ) ) V_131 = 0x08 ;
V_130 = V_2 -> V_376 ;
if( V_66 & V_75 ) V_130 >>= 1 ;
if( F_36 ( V_2 ) ) V_130 >>= 1 ;
if( V_130 > 800 ) {
if( V_2 -> V_35 & V_43 ) {
V_130 -= 800 ;
} else {
V_131 = 0x08 ;
if( V_130 == 960 ) V_130 *= 25 ;
else if( V_130 == 1024 ) V_130 *= 25 ;
else V_130 *= 20 ;
V_68 = V_130 % 32 ;
V_130 /= 32 ;
if( V_68 ) V_130 ++ ;
V_130 ++ ;
if( V_2 -> V_35 & V_62 ) {
if( V_132 == V_179 ||
V_132 == V_173 ||
V_132 == V_266 ||
V_132 == V_174 ) {
V_130 = ( V_130 & 0xff00 ) | 0x20 ;
}
}
}
}
V_130 -- ;
V_68 = ( ( V_130 >> 4 ) & 0x30 ) | V_131 ;
F_15 ( V_2 -> V_114 , 0x1D , V_130 ) ;
F_15 ( V_2 -> V_114 , 0x1E , V_68 ) ;
V_68 = 0x0036 ; V_131 = 0xD0 ;
if( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_18 & V_19 ) ) {
V_68 = 0x0026 ; V_131 = 0xC0 ;
}
if( V_2 -> V_35 & V_62 ) {
if( ! ( V_2 -> V_58 & ( V_181 | V_166 | V_59 | V_165 ) ) ) {
V_68 |= 0x01 ;
if( V_2 -> V_35 & V_85 ) {
if( ! ( V_2 -> V_58 & V_178 ) ) {
V_68 &= ~ 0x01 ;
}
}
}
}
F_6 ( V_2 -> V_114 , 0x1F , V_131 , V_68 ) ;
V_131 = V_2 -> V_397 >> 1 ;
if( F_36 ( V_2 ) ) V_131 >>= 1 ;
V_131 -= 2 ;
F_15 ( V_2 -> V_114 , 0x22 , V_131 ) ;
V_68 = ( V_131 >> 5 ) & 0x38 ;
F_6 ( V_2 -> V_114 , 0x21 , 0xC0 , V_68 ) ;
if( V_2 -> V_18 & V_19 ) {
if( V_2 -> V_35 & V_43 ) {
F_15 ( V_2 -> V_114 , 0x24 , 0x0e ) ;
}
}
F_125 ( V_2 ) ;
}
F_124 ( V_2 , V_25 , V_26 , V_319 ) ;
}
static void
F_127 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
if( V_2 -> V_35 & V_44 ) return;
if( V_2 -> V_84 == V_146 ) {
if( ! ( V_2 -> V_35 & ( V_85 | V_135 ) ) ) {
F_2 ( V_2 -> V_10 , 0x1E , 0x20 ) ;
F_128 ( V_2 , V_25 , V_26 ) ;
}
}
}
static bool
F_129 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 , unsigned short * V_383 ,
unsigned short * V_652 )
{
unsigned short V_66 = 0 ;
bool V_653 = true ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
( * V_383 ) = V_2 -> V_71 [ V_26 ] . V_326 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
( * V_383 ) = V_2 -> V_32 [ V_319 ] . V_328 ;
}
( * V_383 ) &= 0x3F ;
if( ( V_2 -> V_61 ) && ( V_2 -> V_35 & V_62 ) ) {
( * V_652 ) = 80 ;
if( ( V_2 -> V_58 & V_157 ) && ( ! ( V_2 -> V_58 & V_160 ) ) ) {
( * V_652 ) = 82 ;
if( V_2 -> V_84 > V_146 ) {
if( V_2 -> V_171 ) ( * V_652 ) = 84 ;
}
}
if( ( * V_652 ) != 84 ) {
if( V_2 -> V_58 & V_170 ) ( * V_652 ) ++ ;
}
} else {
( * V_652 = 0 ) ;
switch( V_2 -> V_183 ) {
case V_232 : ( * V_652 ) = 50 ;
V_653 = false ;
break;
case V_218 : ( * V_652 ) = 14 ;
break;
case V_221 : ( * V_652 ) = 18 ;
break;
case V_234 : ( * V_652 ) = 10 ;
break;
case V_252 : ( * V_652 ) = 26 ;
break;
default: return true ;
}
if( V_653 ) {
if( V_66 & V_75 ) ( * V_652 ) ++ ;
}
if( V_2 -> V_183 == V_252 ) {
if( V_2 -> V_46 & V_47 ) ( * V_652 ) += 2 ;
}
}
return true ;
}
static void
F_130 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_362 , V_28 , V_66 , V_113 , V_383 , V_652 ;
const struct V_654 * V_655 = NULL ;
static const unsigned short V_656 [] = {
0x00 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 ,
0x07 , 0x10 , 0x11 , 0x15 , 0x16
} ;
if( ( V_2 -> V_105 == V_224 ) ||
( V_2 -> V_105 == V_293 ) ||
( V_2 -> V_105 == V_226 ) ||
( V_2 -> V_105 == V_228 ) )
return;
if( V_2 -> V_104 ) {
if( ! ( V_2 -> V_35 & V_44 ) ) {
if( ! ( V_2 -> V_35 & V_85 ) ) return;
}
} else if( V_2 -> V_18 & V_34 ) {
if( ! ( V_2 -> V_35 & V_85 ) ) return;
} else return;
if( V_2 -> V_46 & V_48 ) return;
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_77 & V_311 ) return;
}
if( ! ( F_129 ( V_2 , V_25 , V_26 , V_319 ,
& V_383 , & V_652 ) ) ) {
return;
}
switch( V_652 ) {
case 50 : V_655 = V_2 -> V_657 ; break;
case 14 : V_655 = V_2 -> V_658 ; break;
case 15 : V_655 = V_2 -> V_659 ; break;
case 18 : V_655 = V_2 -> V_660 ; break;
case 19 : V_655 = V_2 -> V_661 ; break;
case 10 : V_655 = V_2 -> V_662 ; break;
case 11 : V_655 = V_2 -> V_663 ; break;
#if 0
case 26: LVDSCRT1Ptr = SiS_Pr->SiS_LVDSCRT11024x600_1; break;
case 27: LVDSCRT1Ptr = SiS_Pr->SiS_LVDSCRT11024x600_1_H; break;
case 28: LVDSCRT1Ptr = SiS_Pr->SiS_LVDSCRT11024x600_2; break;
case 29: LVDSCRT1Ptr = SiS_Pr->SiS_LVDSCRT11024x600_2_H; break;
#endif
case 80 : V_655 = V_2 -> V_664 ; break;
case 81 : V_655 = V_2 -> V_665 ; break;
case 82 : V_655 = V_2 -> V_666 ; break;
case 83 : V_655 = V_2 -> V_667 ; break;
case 84 : V_655 = V_2 -> V_668 ; break;
}
if( V_655 ) {
F_4 ( V_2 -> V_21 , 0x11 , 0x7f ) ;
for( V_28 = 0 ; V_28 <= 10 ; V_28 ++ ) {
V_362 = ( V_655 + V_383 ) -> V_395 [ V_28 ] ;
F_15 ( V_2 -> V_21 , V_656 [ V_28 ] , V_362 ) ;
}
for( V_28 = 0x0A , V_113 = 11 ; V_28 <= 0x0C ; V_28 ++ , V_113 ++ ) {
V_362 = ( V_655 + V_383 ) -> V_395 [ V_113 ] ;
F_15 ( V_2 -> V_10 , V_28 , V_362 ) ;
}
V_362 = ( V_655 + V_383 ) -> V_395 [ 14 ] & 0xE0 ;
F_6 ( V_2 -> V_10 , 0x0E , 0x1f , V_362 ) ;
if( V_25 <= 0x13 ) V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
else V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_362 = ( ( V_655 + V_383 ) -> V_395 [ 14 ] & 0x01 ) << 5 ;
if( V_66 & V_382 ) V_362 |= 0x80 ;
F_6 ( V_2 -> V_21 , 0x09 , ~ 0x020 , V_362 ) ;
} else {
F_70 ( V_2 , V_25 , V_26 ) ;
}
}
static void
F_131 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_669 , V_645 = 0 ;
unsigned char V_670 , V_671 ;
if( V_2 -> V_46 & V_48 ) {
V_2 -> V_77 &= ( ~ V_78 ) ;
if( V_2 -> V_32 [ V_319 ] . V_329 == 2 ) {
V_319 -- ;
}
V_645 = F_59 ( V_2 , V_25 , V_26 ,
V_319 ) ;
V_2 -> V_77 |= V_78 ;
} else {
V_645 = F_59 ( V_2 , V_25 , V_26 ,
V_319 ) ;
}
V_670 = V_2 -> V_199 [ V_645 ] . V_201 ;
V_671 = V_2 -> V_199 [ V_645 ] . V_203 ;
if( ( V_2 -> V_105 == V_224 ) || ( V_2 -> V_105 == V_293 ) ) {
if( V_2 -> V_90 ) {
if( V_11 [ 0x220 ] & 0x01 ) {
V_670 = V_11 [ 0x227 ] ;
V_671 = V_11 [ 0x228 ] ;
}
}
}
V_669 = 0x02B ;
if( ! ( V_2 -> V_35 & V_44 ) ) {
if( ! ( V_2 -> V_35 & V_85 ) ) {
V_669 += 3 ;
}
}
F_15 ( V_2 -> V_10 , 0x31 , 0x20 ) ;
F_15 ( V_2 -> V_10 , V_669 , V_670 ) ;
F_15 ( V_2 -> V_10 , V_669 + 1 , V_671 ) ;
F_15 ( V_2 -> V_10 , 0x31 , 0x10 ) ;
F_15 ( V_2 -> V_10 , V_669 , V_670 ) ;
F_15 ( V_2 -> V_10 , V_669 + 1 , V_671 ) ;
F_15 ( V_2 -> V_10 , 0x31 , 0x00 ) ;
F_15 ( V_2 -> V_10 , V_669 , V_670 ) ;
F_15 ( V_2 -> V_10 , V_669 + 1 , V_671 ) ;
}
static void
F_132 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_319 )
{
unsigned short V_672 , V_373 ;
const struct V_673 * V_674 = NULL ;
if( V_25 <= 0x13 )
V_373 = V_2 -> V_71 [ V_26 ] . V_326 ;
else
V_373 = V_2 -> V_32 [ V_319 ] . V_328 ;
V_373 &= 0x3F ;
V_672 = 0 ;
if( V_2 -> V_58 & V_170 ) V_672 += 1 ;
if( V_2 -> V_58 & V_157 ) {
V_672 += 2 ;
if( V_2 -> V_84 > V_146 ) {
if( V_2 -> V_171 ) V_672 = 8 ;
}
if( V_2 -> V_58 & V_160 ) {
V_672 = 4 ;
if( V_2 -> V_58 & V_170 ) V_672 += 1 ;
} else if( V_2 -> V_58 & V_162 ) {
V_672 = 6 ;
if( V_2 -> V_58 & V_170 ) V_672 += 1 ;
}
}
switch( V_672 ) {
case 0 : V_674 = V_2 -> V_675 ; break;
case 1 : V_674 = V_2 -> V_676 ; break;
case 2 : V_674 = V_2 -> V_677 ; break;
case 3 : V_674 = V_2 -> V_678 ; break;
case 4 : V_674 = V_2 -> V_679 ; break;
case 5 : V_674 = V_2 -> V_680 ; break;
case 6 : V_674 = V_2 -> V_681 ; break;
case 7 : V_674 = V_2 -> V_682 ; break;
case 8 : V_674 = V_2 -> V_683 ; break;
default: V_674 = V_2 -> V_678 ; break;
}
if( V_2 -> V_61 == 1 ) {
#ifdef V_94
if ( V_373 > 5 ) return;
if( V_2 -> V_58 & V_157 ) {
F_81 ( V_2 , 0x04 , 0x43 ) ;
F_81 ( V_2 , 0x09 , 0x69 ) ;
} else {
F_81 ( V_2 , 0x04 , 0x03 ) ;
F_81 ( V_2 , 0x09 , 0x71 ) ;
}
F_81 ( V_2 , 0x00 , V_674 [ V_373 ] . V_684 [ 0 ] ) ;
F_81 ( V_2 , 0x07 , V_674 [ V_373 ] . V_684 [ 1 ] ) ;
F_81 ( V_2 , 0x08 , V_674 [ V_373 ] . V_684 [ 2 ] ) ;
F_81 ( V_2 , 0x0a , V_674 [ V_373 ] . V_684 [ 3 ] ) ;
F_81 ( V_2 , 0x0b , V_674 [ V_373 ] . V_684 [ 4 ] ) ;
F_81 ( V_2 , 0x01 , 0x28 ) ;
F_81 ( V_2 , 0x03 , 0xb1 ) ;
#ifndef F_121
F_133 ( V_2 , 0x3d , 0x00 ) ;
#endif
F_134 ( V_2 , 0x10 , 0x00 , 0x1F ) ;
F_134 ( V_2 , 0x11 , 0x02 , 0xF8 ) ;
F_134 ( V_2 , 0x1c , 0x00 , 0xEF ) ;
if( ! ( V_2 -> V_58 & V_157 ) ) {
if( V_2 -> V_58 & V_170 ) {
if( V_373 == 0x04 ) {
F_134 ( V_2 , 0x20 , 0x00 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x01 , 0xFE ) ;
} else if( V_373 == 0x05 ) {
F_134 ( V_2 , 0x18 , 0x01 , 0xF0 ) ;
F_134 ( V_2 , 0x19 , 0x0C , 0xF0 ) ;
F_134 ( V_2 , 0x1a , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x1b , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x1c , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x1d , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x1e , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x1f , 0x00 , 0xF0 ) ;
F_134 ( V_2 , 0x20 , 0x01 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x00 , 0xFE ) ;
}
} else {
if( V_373 == 0x04 ) {
F_134 ( V_2 , 0x20 , 0x00 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x01 , 0xFE ) ;
} else if( V_373 == 0x05 ) {
#if 0
SiS_SetCH70xxANDOR(SiS_Pr,0x18,0x01,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x19,0x09,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1a,0x08,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1b,0x0b,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1c,0x04,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1d,0x01,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1e,0x06,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x1f,0x05,0xF0);
SiS_SetCH70xxANDOR(SiS_Pr,0x20,0x00,0xEF);
SiS_SetCH70xxANDOR(SiS_Pr,0x21,0x00,0xFE); * ACIV off, need to set FSCI */
#endif
F_134 ( V_2 , 0x20 , 0x00 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x01 , 0xFE ) ;
}
}
} else {
if( V_373 == 0x04 ) {
F_134 ( V_2 , 0x20 , 0x00 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x01 , 0xFE ) ;
} else {
F_134 ( V_2 , 0x20 , 0x00 , 0xEF ) ;
F_134 ( V_2 , 0x21 , 0x01 , 0xFE ) ;
}
}
#endif
} else {
#ifdef V_95
unsigned short V_68 ;
if ( V_373 > 6 ) return;
V_68 = V_674 [ V_373 ] . V_684 [ 0 ] ;
if( V_2 -> V_58 & V_164 ) V_68 |= 0x10 ;
F_83 ( V_2 , 0x00 , V_68 ) ;
F_83 ( V_2 , 0x01 , V_674 [ V_373 ] . V_684 [ 1 ] ) ;
F_83 ( V_2 , 0x02 , V_674 [ V_373 ] . V_684 [ 2 ] ) ;
F_83 ( V_2 , 0x04 , V_674 [ V_373 ] . V_684 [ 3 ] ) ;
F_83 ( V_2 , 0x03 , V_674 [ V_373 ] . V_684 [ 4 ] ) ;
F_83 ( V_2 , 0x05 , V_674 [ V_373 ] . V_684 [ 5 ] ) ;
F_83 ( V_2 , 0x06 , V_674 [ V_373 ] . V_684 [ 6 ] ) ;
V_68 = V_674 [ V_373 ] . V_684 [ 7 ] ;
if( V_2 -> V_58 & V_164 ) V_68 = 0x66 ;
F_83 ( V_2 , 0x07 , V_68 ) ;
F_83 ( V_2 , 0x08 , V_674 [ V_373 ] . V_684 [ 8 ] ) ;
F_83 ( V_2 , 0x15 , V_674 [ V_373 ] . V_684 [ 9 ] ) ;
F_83 ( V_2 , 0x1f , V_674 [ V_373 ] . V_684 [ 10 ] ) ;
F_83 ( V_2 , 0x0c , V_674 [ V_373 ] . V_684 [ 11 ] ) ;
F_83 ( V_2 , 0x0d , V_674 [ V_373 ] . V_684 [ 12 ] ) ;
F_83 ( V_2 , 0x0e , V_674 [ V_373 ] . V_684 [ 13 ] ) ;
F_83 ( V_2 , 0x0f , V_674 [ V_373 ] . V_684 [ 14 ] ) ;
F_83 ( V_2 , 0x10 , V_674 [ V_373 ] . V_684 [ 15 ] ) ;
V_68 = F_82 ( V_2 , 0x21 ) & ~ 0x02 ;
if( V_2 -> V_58 & ( V_162 | V_164 ) ) V_68 |= 0x02 ;
F_83 ( V_2 , 0x21 , V_68 ) ;
#endif
}
#ifdef F_121
V_685
#endif
}
void
F_91 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_61 == 2 ) {
if( V_2 -> V_3 == V_515 ) {
F_83 ( V_2 , 0x66 , 0x65 ) ;
} else {
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 |= 0x20 ;
F_83 ( V_2 , 0x66 , V_68 ) ;
}
}
}
void
F_84 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_61 == 2 ) {
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 &= 0xDF ;
F_83 ( V_2 , 0x66 , V_68 ) ;
}
}
static void
F_135 ( struct V_1 * V_2 )
{
static const unsigned char V_686 [] = { 0x67 , 0x68 , 0x69 , 0x6a , 0x6b } ;
static const unsigned char V_687 [] = { 0x01 , 0x02 , 0x01 , 0x01 , 0x01 } ;
static const unsigned char V_688 [] = { 0x01 , 0x6e , 0x01 , 0x01 , 0x01 } ;
static const unsigned char V_689 [] = { 0x19 , 0x6e , 0x01 , 0x19 , 0x09 } ;
static const unsigned char V_690 [] = { 0x19 , 0x6e , 0x01 , 0x19 , 0x09 } ;
static const unsigned char V_691 [] = { 0x01 , 0x02 , 0x01 , 0x01 , 0x02 } ;
static const unsigned char V_692 [] = { 0x01 , 0x02 , 0x01 , 0x01 , 0x02 } ;
const unsigned char * V_602 = NULL ;
int V_28 ;
if( V_2 -> V_3 == V_515 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_105 == V_693 ) V_602 = V_689 ;
else V_602 = V_687 ;
} else if( ( V_2 -> V_183 == V_239 ) ||
( V_2 -> V_183 == V_240 ) ||
( V_2 -> V_183 == V_241 ) ) {
if( V_2 -> V_105 == V_693 ) V_602 = V_690 ;
else V_602 = V_688 ;
} else return;
} else {
if( V_2 -> V_183 == V_238 ) {
V_602 = V_691 ;
} else if( ( V_2 -> V_183 == V_239 ) ||
( V_2 -> V_183 == V_240 ) ||
( V_2 -> V_183 == V_241 ) ) {
V_602 = V_692 ;
} else return;
}
for( V_28 = 0 ; V_28 < 5 ; V_28 ++ ) {
F_83 ( V_2 , V_686 [ V_28 ] , V_602 [ V_28 ] ) ;
}
}
static void
F_136 ( struct V_1 * V_2 )
{
const unsigned char * V_602 = NULL ;
unsigned short V_694 ;
int V_28 ;
static const unsigned char V_686 [] = {
0x1c , 0x5f , 0x64 , 0x6f , 0x70 , 0x71 ,
0x72 , 0x73 , 0x74 , 0x76 , 0x78 , 0x7d , 0x66
} ;
static const unsigned char V_687 [] = {
0x60 , 0x02 , 0x00 , 0x07 , 0x40 , 0xed ,
0xa3 , 0xc8 , 0xc7 , 0xac , 0xe0 , 0x02 , 0x44
} ;
static const unsigned char V_695 [] = {
0x60 , 0x03 , 0x11 , 0x00 , 0x40 , 0xe3 ,
0xad , 0xdb , 0xf6 , 0xac , 0xe0 , 0x02 , 0x44
} ;
static const unsigned char V_688 [] = {
0x60 , 0x03 , 0x11 , 0x00 , 0x40 , 0xe3 ,
0xad , 0xdb , 0xf6 , 0xac , 0xe0 , 0x02 , 0x44
} ;
static const unsigned char V_696 [] = {
0x60 , 0x04 , 0x11 , 0x00 , 0x40 , 0xe3 ,
0xad , 0xde , 0xf6 , 0xac , 0x60 , 0x1a , 0x44
} ;
static const unsigned char V_691 [] = {
0x60 , 0x02 , 0x00 , 0x07 , 0x40 , 0xed ,
0xa3 , 0xc8 , 0xc7 , 0xac , 0x60 , 0x02
} ;
static const unsigned char V_697 [] = {
0x60 , 0x03 , 0x11 , 0x00 , 0x40 , 0xe3 ,
0xad , 0xdb , 0xf6 , 0xac , 0xe0 , 0x02
} ;
static const unsigned char V_692 [] = {
0x60 , 0x03 , 0x11 , 0x00 , 0x40 , 0xef ,
0xad , 0xdb , 0xf6 , 0xac , 0x60 , 0x02
} ;
static const unsigned char V_698 [] = {
0x60 , 0x04 , 0x11 , 0x00 , 0x40 , 0xe3 ,
0xad , 0xde , 0xf6 , 0xac , 0x60 , 0x1a
} ;
if( V_2 -> V_3 == V_515 ) {
if( V_2 -> V_183 == V_238 ) V_602 = V_687 ;
else if( V_2 -> V_183 == V_239 ) V_602 = V_695 ;
else if( V_2 -> V_183 == V_240 ) V_602 = V_688 ;
else if( V_2 -> V_183 == V_241 ) V_602 = V_696 ;
else return;
} else {
if( V_2 -> V_183 == V_238 ) V_602 = V_691 ;
else if( V_2 -> V_183 == V_239 ) V_602 = V_697 ;
else if( V_2 -> V_183 == V_240 ) V_602 = V_692 ;
else if( V_2 -> V_183 == V_241 ) V_602 = V_698 ;
else return;
}
V_694 = F_82 ( V_2 , 0x74 ) ;
if( ( V_694 == 0xf6 ) || ( V_694 == 0xc7 ) ) {
V_694 = F_82 ( V_2 , 0x73 ) ;
if( V_694 == 0xc8 ) {
if( V_2 -> V_183 == V_238 ) return;
} else if( V_694 == 0xdb ) {
if( V_2 -> V_183 == V_239 ) return;
if( V_2 -> V_183 == V_240 ) return;
} else if( V_694 == 0xde ) {
if( V_2 -> V_183 == V_241 ) return;
}
}
if( V_2 -> V_3 == V_515 ) V_694 = 0x0d ;
else V_694 = 0x0c ;
for( V_28 = 0 ; V_28 < V_694 ; V_28 ++ ) {
F_83 ( V_2 , V_686 [ V_28 ] , V_602 [ V_28 ] ) ;
}
F_135 ( V_2 ) ;
V_694 = F_82 ( V_2 , 0x1e ) ;
V_694 |= 0xc0 ;
F_83 ( V_2 , 0x1e , V_694 ) ;
if( V_2 -> V_3 == V_515 ) {
V_694 = F_82 ( V_2 , 0x1c ) ;
V_694 &= 0xfb ;
F_83 ( V_2 , 0x1c , V_694 ) ;
F_15 ( V_2 -> V_6 , 0x2d , 0x03 ) ;
V_694 = F_82 ( V_2 , 0x64 ) ;
V_694 |= 0x40 ;
F_83 ( V_2 , 0x64 , V_694 ) ;
V_694 = F_82 ( V_2 , 0x03 ) ;
V_694 &= 0x3f ;
F_83 ( V_2 , 0x03 , V_694 ) ;
}
}
static void
F_137 ( struct V_1 * V_2 )
{
unsigned char V_68 , V_88 ;
V_88 = F_82 ( V_2 , 0x49 ) ;
F_83 ( V_2 , 0x49 , 0x3e ) ;
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 &= 0x7f ;
F_83 ( V_2 , 0x47 , V_68 ) ;
F_20 ( V_2 , 3 ) ;
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 |= 0x80 ;
F_83 ( V_2 , 0x47 , V_68 ) ;
F_83 ( V_2 , 0x49 , V_88 ) ;
}
static void
F_92 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_61 == 2 ) {
if( V_2 -> V_3 == V_515 ) {
V_68 = F_82 ( V_2 , 0x1c ) ;
V_68 |= 0x04 ;
F_83 ( V_2 , 0x1c , V_68 ) ;
}
if( F_41 ( V_2 ) ) {
V_68 = F_82 ( V_2 , 0x01 ) ;
V_68 &= 0x3f ;
V_68 |= 0x80 ;
F_83 ( V_2 , 0x01 , V_68 ) ;
}
if( F_42 ( V_2 ) ) {
V_68 = F_82 ( V_2 , 0x01 ) ;
V_68 &= 0x3f ;
V_68 |= 0xc0 ;
F_83 ( V_2 , 0x01 , V_68 ) ;
}
if( V_2 -> V_3 == V_515 ) {
F_137 ( V_2 ) ;
F_83 ( V_2 , 0x49 , 0x20 ) ;
} else {
F_83 ( V_2 , 0x49 , 0x20 ) ;
V_68 = F_82 ( V_2 , 0x49 ) ;
if( F_41 ( V_2 ) ) {
V_68 = F_82 ( V_2 , 0x73 ) ;
V_68 |= 0x60 ;
F_83 ( V_2 , 0x73 , V_68 ) ;
}
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 &= 0x7f ;
F_83 ( V_2 , 0x47 , V_68 ) ;
F_20 ( V_2 , 2 ) ;
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 |= 0x80 ;
F_83 ( V_2 , 0x47 , V_68 ) ;
}
}
}
static void
F_85 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_61 == 2 ) {
if( V_2 -> V_3 == V_515 ) {
F_20 ( V_2 , 1 ) ;
F_19 ( V_2 , 5887 ) ;
F_83 ( V_2 , 0x76 , 0xac ) ;
F_83 ( V_2 , 0x66 , 0x00 ) ;
} else {
F_20 ( V_2 , 2 ) ;
V_68 = F_82 ( V_2 , 0x76 ) ;
V_68 &= 0xfc ;
F_83 ( V_2 , 0x76 , V_68 ) ;
F_83 ( V_2 , 0x66 , 0x00 ) ;
}
}
}
static void
F_138 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_3 == V_515 ) {
V_68 = F_82 ( V_2 , 0x4a ) ;
V_68 &= 0x01 ;
if( ! V_68 ) {
if( F_39 ( V_2 ) ) {
V_68 = F_82 ( V_2 , 0x49 ) ;
F_83 ( V_2 , 0x49 , 0x3e ) ;
}
F_83 ( V_2 , 0x48 , 0x10 ) ;
F_20 ( V_2 , 1 ) ;
F_83 ( V_2 , 0x48 , 0x18 ) ;
if( F_39 ( V_2 ) ) {
F_137 ( V_2 ) ;
F_83 ( V_2 , 0x49 , V_68 ) ;
}
} else {
V_68 = F_82 ( V_2 , 0x5c ) ;
V_68 &= 0xef ;
F_83 ( V_2 , 0x5c , V_68 ) ;
V_68 = F_82 ( V_2 , 0x5c ) ;
V_68 |= 0x10 ;
F_83 ( V_2 , 0x5c , V_68 ) ;
V_68 = F_82 ( V_2 , 0x5c ) ;
V_68 &= 0xef ;
F_83 ( V_2 , 0x5c , V_68 ) ;
V_68 = F_82 ( V_2 , 0x61 ) ;
if( ! V_68 ) {
F_136 ( V_2 ) ;
}
}
} else {
F_83 ( V_2 , 0x48 , 0x10 ) ;
F_20 ( V_2 , 1 ) ;
F_83 ( V_2 , 0x48 , 0x18 ) ;
}
}
static void
F_94 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
if( V_2 -> V_3 == V_515 ) {
if( F_39 ( V_2 ) ) {
F_137 ( V_2 ) ;
}
} else {
F_83 ( V_2 , 0x76 , 0xaf ) ;
V_68 = F_82 ( V_2 , 0x49 ) ;
V_68 &= 1 ;
if( V_68 != 1 ) {
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 &= 0x70 ;
F_83 ( V_2 , 0x47 , V_68 ) ;
F_20 ( V_2 , 3 ) ;
V_68 = F_82 ( V_2 , 0x47 ) ;
V_68 |= 0x80 ;
F_83 ( V_2 , 0x47 , V_68 ) ;
}
}
}
static void
F_139 ( struct V_1 * V_2 , unsigned short V_25 )
{
unsigned short V_68 , V_88 ;
if( V_2 -> V_3 == V_515 ) {
V_68 = F_82 ( V_2 , 0x61 ) ;
if( V_68 < 1 ) {
V_68 ++ ;
F_83 ( V_2 , 0x61 , V_68 ) ;
}
F_83 ( V_2 , 0x66 , 0x45 ) ;
F_83 ( V_2 , 0x76 , 0xaf ) ;
F_20 ( V_2 , 1 ) ;
F_19 ( V_2 , 5887 ) ;
} else {
V_88 = 0 ;
V_68 = F_82 ( V_2 , 0x61 ) ;
if( V_68 < 2 ) {
V_68 ++ ;
F_83 ( V_2 , 0x61 , V_68 ) ;
V_88 = 1 ;
}
F_83 ( V_2 , 0x76 , 0xac ) ;
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 |= 0x5f ;
F_83 ( V_2 , 0x66 , V_68 ) ;
if( V_25 > 0x13 ) {
if( F_39 ( V_2 ) ) {
F_19 ( V_2 , 1023 ) ;
} else {
F_19 ( V_2 , 767 ) ;
}
} else {
if( ! V_88 )
F_19 ( V_2 , 767 ) ;
}
V_68 = F_82 ( V_2 , 0x76 ) ;
V_68 |= 0x03 ;
F_83 ( V_2 , 0x76 , V_68 ) ;
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 &= 0x7f ;
F_83 ( V_2 , 0x66 , V_68 ) ;
F_20 ( V_2 , 1 ) ;
}
}
static void
F_140 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
F_20 ( V_2 , 1 ) ;
do {
V_68 = F_82 ( V_2 , 0x66 ) ;
V_68 &= 0x04 ;
if( V_68 == 0x04 ) break;
if( V_2 -> V_3 == V_515 ) {
F_83 ( V_2 , 0x76 , 0xac ) ;
}
F_136 ( V_2 ) ;
V_68 = F_82 ( V_2 , 0x76 ) ;
V_68 &= 0xfb ;
F_83 ( V_2 , 0x76 , V_68 ) ;
F_20 ( V_2 , 2 ) ;
V_68 = F_82 ( V_2 , 0x76 ) ;
V_68 |= 0x04 ;
F_83 ( V_2 , 0x76 , V_68 ) ;
if( V_2 -> V_3 == V_515 ) {
F_83 ( V_2 , 0x78 , 0xe0 ) ;
} else {
F_83 ( V_2 , 0x78 , 0x60 ) ;
}
F_20 ( V_2 , 2 ) ;
} while( 0 );
F_83 ( V_2 , 0x77 , 0x00 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
unsigned short V_68 ;
V_68 = F_82 ( V_2 , 0x03 ) ;
V_68 |= 0x80 ;
V_68 &= 0xbf ;
F_83 ( V_2 , 0x03 , V_68 ) ;
if( V_2 -> V_3 == V_515 ) {
V_68 = F_82 ( V_2 , 0x1c ) ;
V_68 &= 0xfb ;
F_83 ( V_2 , 0x1c , V_68 ) ;
F_15 ( V_2 -> V_6 , 0x2d , 0x03 ) ;
V_68 = F_82 ( V_2 , 0x64 ) ;
V_68 |= 0x40 ;
F_83 ( V_2 , 0x64 , V_68 ) ;
V_68 = F_82 ( V_2 , 0x03 ) ;
V_68 &= 0x3f ;
F_83 ( V_2 , 0x03 , V_68 ) ;
if( V_2 -> V_105 == V_693 ) {
F_83 ( V_2 , 0x63 , 0x40 ) ;
F_20 ( V_2 , 1 ) ;
F_83 ( V_2 , 0x63 , 0x00 ) ;
F_138 ( V_2 ) ;
F_140 ( V_2 ) ;
F_139 ( V_2 , 0 ) ;
} else {
V_68 = F_82 ( V_2 , 0x66 ) ;
if( V_68 != 0x45 ) {
F_138 ( V_2 ) ;
F_140 ( V_2 ) ;
F_139 ( V_2 , 0 ) ;
}
}
} else {
F_138 ( V_2 ) ;
F_140 ( V_2 ) ;
V_68 = F_8 ( V_2 -> V_21 , 0x34 ) ;
F_139 ( V_2 , V_68 ) ;
F_83 ( V_2 , 0x76 , 0xaf ) ;
}
}
bool
F_141 ( struct V_1 * V_2 , unsigned short V_25 )
{
#ifdef V_94
unsigned char * V_11 = V_2 -> V_12 ;
#endif
unsigned short V_26 , V_319 ;
V_2 -> V_77 |= V_78 ;
if( ! V_2 -> V_133 ) {
F_99 ( V_2 , & V_25 , & V_26 ) ;
} else {
V_26 = 0 ;
}
V_2 -> V_76 = 4 ;
F_1 ( V_2 ) ;
V_319 = F_12 ( V_2 , V_25 , V_26 ) ;
F_14 ( V_2 , V_25 ) ;
if( V_2 -> V_77 & V_699 ) {
F_77 ( V_2 ) ;
if( ( V_2 -> V_104 == 1 ) && ( V_2 -> V_3 == V_115 ) ) {
F_15 ( V_2 -> V_6 , 0x00 , 0x80 ) ;
}
F_61 ( V_2 , V_25 , V_26 ) ;
}
if( V_2 -> V_35 & V_87 ) {
F_3 ( V_2 ) ;
F_87 ( V_2 ) ;
return true ;
}
F_72 ( V_2 , V_25 , V_26 , V_319 ) ;
V_2 -> V_499 = V_2 -> V_500 = 0 ;
if( ( V_2 -> V_104 == 1 ) ||
( ( V_2 -> V_18 & V_79 ) && ( V_2 -> V_35 & V_43 ) ) ||
( ( V_2 -> V_3 >= V_5 ) && ( V_2 -> V_18 & V_39 ) ) ) {
F_74 ( V_2 , V_25 , V_26 , V_319 ) ;
}
if( V_2 -> V_77 & V_699 ) {
F_111 ( V_2 , V_25 , V_26 , V_319 ) ;
}
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_77 & V_699 ) {
F_119 ( V_2 , V_25 , V_26 , V_319 ) ;
#ifdef V_95
F_113 ( V_2 , V_25 , V_26 , V_319 ) ;
#endif
F_120 ( V_2 , V_25 , V_26 ) ;
F_126 ( V_2 , V_25 , V_26 , V_319 ) ;
#ifdef V_95
F_123 ( V_2 , V_25 , V_26 ) ;
#endif
F_127 ( V_2 , V_25 , V_26 ) ;
F_97 ( V_2 , V_25 , V_319 ) ;
if( ( V_2 -> V_18 & V_79 ) && ( V_2 -> V_35 & V_43 ) ) {
if( ! ( ( V_2 -> V_77 & V_311 ) && ( ( V_25 == 0x03 ) || ( V_25 == 0x10 ) ) ) ) {
if( V_2 -> V_35 & V_85 ) {
F_130 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
F_131 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
} else {
F_97 ( V_2 , V_25 , V_319 ) ;
F_130 ( V_2 , V_25 , V_26 , V_319 ) ;
F_131 ( V_2 , V_25 , V_26 , V_319 ) ;
if( V_2 -> V_77 & V_699 ) {
if( V_2 -> V_61 != 0 ) {
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_61 == 2 ) {
#ifdef V_95
F_136 ( V_2 ) ;
#endif
}
}
if( V_2 -> V_35 & V_62 ) {
F_132 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
}
}
#ifdef V_94
if( V_2 -> V_3 < V_5 ) {
if( V_2 -> V_77 & V_699 ) {
if( V_2 -> V_700 ) {
if( ( V_2 -> V_90 ) && ( V_2 -> V_700 == - 1 ) ) {
if( ( V_11 [ 0x233 ] == 0x12 ) && ( V_11 [ 0x234 ] == 0x34 ) ) {
F_142 ( V_2 , V_25 , V_26 , V_319 ) ;
}
} else {
F_142 ( V_2 , V_25 , V_26 , V_319 ) ;
}
}
if( V_2 -> V_104 == 1 ) {
if( ( V_2 -> V_105 == V_224 ) ||
( V_2 -> V_105 == V_293 ) ) {
F_143 ( V_2 , V_25 , V_26 , V_319 ) ;
}
F_87 ( V_2 ) ;
}
}
}
#endif
#ifdef V_95
if( V_2 -> V_3 >= V_5 ) {
if( V_2 -> V_77 & V_699 ) {
if( V_2 -> V_3 < V_9 ) {
F_144 ( V_2 , V_25 , V_26 ) ;
F_145 ( V_2 , V_25 , V_26 , V_319 ) ;
} else {
F_146 ( V_2 , V_25 , V_26 , V_319 ) ;
}
F_2 ( V_2 -> V_6 , 0x01 , 0x40 ) ;
}
}
#endif
if( V_2 -> V_77 & V_699 ) {
F_86 ( V_2 ) ;
}
F_87 ( V_2 ) ;
if( V_2 -> V_61 == 1 ) {
if( V_2 -> V_35 & V_62 ) {
F_5 ( V_2 , 0xFF , 0x0C ) ;
} else {
F_134 ( V_2 , 0x0e , 0x01 , 0xf8 ) ;
}
}
if( V_2 -> V_77 & V_699 ) {
F_3 ( V_2 ) ;
}
return true ;
}
void
F_147 ( struct V_1 * V_2 )
{
F_18 ( V_2 , 0xff00 ) ;
if( ! ( F_8 ( V_2 -> V_114 , 0x26 ) & 0x02 ) ) {
F_2 ( V_2 -> V_114 , 0x26 , 0x02 ) ;
F_28 ( V_2 ) ;
}
if( ! ( F_8 ( V_2 -> V_114 , 0x26 ) & 0x01 ) ) {
F_2 ( V_2 -> V_114 , 0x26 , 0x01 ) ;
}
}
void
F_148 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_114 , 0x26 , 0xFE ) ;
F_18 ( V_2 , 0xff00 ) ;
}
static void
F_149 ( struct V_1 * V_2 )
{
V_2 -> V_701 = ~ V_2 -> V_702 ;
V_2 -> V_703 = ~ V_2 -> V_704 ;
if( ( V_2 -> V_705 == 0x11 ) && ( V_2 -> V_706 ) ) {
V_2 -> V_701 &= 0x0f ;
V_2 -> V_703 &= 0x0f ;
}
}
static unsigned char *
F_150 ( struct V_1 * V_2 , unsigned char * V_707 )
{
int V_28 , V_113 , V_708 ;
unsigned short V_362 , V_68 ;
unsigned char * V_709 ;
for( V_28 = 0 ; V_28 < 20 ; V_28 ++ ) {
V_709 = V_707 ;
V_708 = * V_709 ++ ;
if( ! V_708 ) return V_709 ;
if( V_28 ) {
F_151 ( V_2 ) ;
F_18 ( V_2 , V_710 * 2 ) ;
}
if( F_152 ( V_2 ) ) continue;
V_362 = V_2 -> V_711 ;
V_68 = F_153 ( V_2 , V_362 ) ;
if( V_68 ) continue;
V_362 = * V_709 ++ ;
V_68 = F_153 ( V_2 , V_362 ) ;
if( V_68 ) continue;
for( V_113 = 0 ; V_113 < V_708 ; V_113 ++ ) {
V_362 = * V_709 ++ ;
V_68 = F_153 ( V_2 , V_362 ) ;
if( V_68 ) break;
}
if( V_68 ) continue;
if( F_151 ( V_2 ) ) continue;
return V_709 ;
}
return NULL ;
}
static bool
F_110 ( struct V_1 * V_2 , unsigned char * V_707 )
{
V_2 -> V_711 = 0xF0 ;
V_2 -> V_705 = 0x11 ;
V_2 -> V_702 = 0x02 ;
V_2 -> V_704 = 0x01 ;
F_149 ( V_2 ) ;
F_154 ( V_2 ) ;
while( * V_707 ) {
V_707 = F_150 ( V_2 , V_707 ) ;
if( ! V_707 ) return false ;
}
return true ;
}
static bool
F_155 ( struct V_1 * V_2 , unsigned short V_15 , unsigned char V_712 , unsigned short V_713 )
{
unsigned short V_68 , V_28 ;
for( V_28 = 0 ; V_28 < 20 ; V_28 ++ ) {
if( V_28 ) {
F_151 ( V_2 ) ;
F_18 ( V_2 , V_710 * 4 ) ;
}
if( F_152 ( V_2 ) ) continue;
V_68 = F_153 ( V_2 , V_2 -> V_711 ) ;
if( V_68 ) continue;
V_68 = F_153 ( V_2 , ( V_15 | V_713 ) ) ;
if( V_68 ) continue;
V_68 = F_153 ( V_2 , V_712 ) ;
if( V_68 ) continue;
if( F_151 ( V_2 ) ) continue;
V_2 -> V_714 = 1 ;
return true ;
}
return false ;
}
void
F_81 ( struct V_1 * V_2 , unsigned short V_15 , unsigned char V_712 )
{
V_2 -> V_711 = 0xEA ;
F_18 ( V_2 , V_710 ) ;
if( ! ( V_2 -> V_714 ) ) {
V_2 -> V_705 = 0x11 ;
V_2 -> V_702 = 0x02 ;
V_2 -> V_704 = 0x01 ;
F_149 ( V_2 ) ;
}
if( ( ! ( F_155 ( V_2 , V_15 , V_712 , 0x80 ) ) ) &&
( ! ( V_2 -> V_714 ) ) ) {
V_2 -> V_705 = 0x0a ;
V_2 -> V_702 = 0x80 ;
V_2 -> V_704 = 0x40 ;
F_149 ( V_2 ) ;
F_155 ( V_2 , V_15 , V_712 , 0x80 ) ;
}
}
void
F_83 ( struct V_1 * V_2 , unsigned short V_15 , unsigned char V_712 )
{
V_2 -> V_705 = 0x11 ;
V_2 -> V_702 = 0x08 ;
V_2 -> V_704 = 0x04 ;
F_149 ( V_2 ) ;
V_2 -> V_711 = 0xEA ;
F_155 ( V_2 , V_15 , V_712 , 0 ) ;
}
static
void
F_133 ( struct V_1 * V_2 , unsigned short V_15 , unsigned char V_712 )
{
if( V_2 -> V_61 == 1 )
F_81 ( V_2 , V_15 , V_712 ) ;
else
F_83 ( V_2 , V_15 , V_712 ) ;
}
static unsigned short
F_156 ( struct V_1 * V_2 , unsigned short V_713 )
{
unsigned short V_362 , V_68 , V_28 ;
for( V_28 = 0 ; V_28 < 20 ; V_28 ++ ) {
if( V_28 ) {
F_151 ( V_2 ) ;
F_18 ( V_2 , V_710 * 4 ) ;
}
if( F_152 ( V_2 ) ) continue;
V_68 = F_153 ( V_2 , V_2 -> V_711 ) ;
if( V_68 ) continue;
V_68 = F_153 ( V_2 , V_2 -> V_715 | V_713 ) ;
if( V_68 ) continue;
if ( F_152 ( V_2 ) ) continue;
V_68 = F_153 ( V_2 , V_2 -> V_711 | 0x01 ) ;
if( V_68 ) continue;
V_362 = F_157 ( V_2 ) ;
if( F_151 ( V_2 ) ) continue;
V_2 -> V_714 = 1 ;
return V_362 ;
}
return 0xFFFF ;
}
unsigned short
F_158 ( struct V_1 * V_2 , unsigned short V_131 )
{
unsigned short V_716 ;
V_2 -> V_711 = 0xEA ;
F_18 ( V_2 , V_710 ) ;
if( ! ( V_2 -> V_714 ) ) {
V_2 -> V_705 = 0x11 ;
V_2 -> V_702 = 0x02 ;
V_2 -> V_704 = 0x01 ;
F_149 ( V_2 ) ;
}
V_2 -> V_715 = V_131 ;
if( ( ( V_716 = F_156 ( V_2 , 0x80 ) ) == 0xFFFF ) &&
( ! V_2 -> V_714 ) ) {
V_2 -> V_705 = 0x0a ;
V_2 -> V_702 = 0x80 ;
V_2 -> V_704 = 0x40 ;
F_149 ( V_2 ) ;
V_716 = F_156 ( V_2 , 0x80 ) ;
}
return V_716 ;
}
unsigned short
F_82 ( struct V_1 * V_2 , unsigned short V_131 )
{
V_2 -> V_705 = 0x11 ;
V_2 -> V_702 = 0x08 ;
V_2 -> V_704 = 0x04 ;
F_149 ( V_2 ) ;
V_2 -> V_711 = 0xEA ;
V_2 -> V_715 = V_131 ;
return F_156 ( V_2 , 0 ) ;
}
static
unsigned short
F_159 ( struct V_1 * V_2 , unsigned short V_131 )
{
if( V_2 -> V_61 == 1 )
return F_158 ( V_2 , V_131 ) ;
else
return F_82 ( V_2 , V_131 ) ;
}
void
F_134 ( struct V_1 * V_2 , unsigned short V_15 ,
unsigned char V_713 , unsigned short V_717 )
{
unsigned short V_364 ;
V_364 = ( F_159 ( V_2 , ( V_15 & 0xFF ) ) & V_717 ) | V_713 ;
F_133 ( V_2 , V_15 , V_364 ) ;
}
static
unsigned short
F_160 ( struct V_1 * V_2 , unsigned int V_718 , int V_719 ,
unsigned short V_720 , unsigned short V_721 , bool V_722 ,
unsigned int V_723 )
{
unsigned char V_724 [] = { 0xa0 , 0xa0 , 0xa0 , 0xa2 , 0xa6 } ;
unsigned char V_118 , V_725 ;
unsigned short V_68 = 0 , V_726 = V_720 ;
if( V_720 != 0 ) {
if( ! ( V_723 & V_727 ) ) return 0xFFFF ;
if( ( V_723 & V_728 ) && ( V_720 == 1 ) ) return 0xFFFF ;
}
V_2 -> V_714 = 0 ;
V_2 -> V_729 = 0 ;
V_2 -> V_711 = V_724 [ V_721 ] ;
V_2 -> V_730 = V_2 -> V_10 ;
V_2 -> V_705 = 0x11 ;
V_118 = 0xff ;
V_725 = F_8 ( V_2 -> V_21 , 0x32 ) ;
#if 0
if(VBFlags2 & VB2_SISBRIDGE) {
if(myadaptnum == 0) {
if(!(cr32 & 0x20)) {
myadaptnum = 2;
if(!(cr32 & 0x10)) {
myadaptnum = 1;
if(!(cr32 & 0x08)) {
myadaptnum = 0;
}
}
}
}
}
#endif
if( V_719 == V_731 ) {
if( V_726 != 0 ) {
V_118 = 0 ;
if( V_723 & V_732 ) {
V_2 -> V_730 = V_2 -> V_114 ;
V_2 -> V_705 = 0x0f ;
}
}
if( ! ( V_723 & V_733 ) ) {
if( ( V_725 & 0x80 ) && ( V_722 ) ) {
if( V_726 >= 1 ) {
if( ! ( V_725 & 0x08 ) ) {
V_726 = 1 ;
if( ! ( V_725 & 0x10 ) ) return 0xFFFF ;
}
}
}
}
V_68 = 4 - ( V_726 * 2 ) ;
if( V_118 ) V_68 = 0 ;
} else {
if( V_723 & V_732 ) {
if( V_726 == 2 ) {
V_726 = 1 ;
}
}
if( V_726 == 1 ) {
V_118 = 0 ;
if( V_723 & V_732 ) {
V_2 -> V_730 = V_2 -> V_114 ;
V_2 -> V_705 = 0x0f ;
}
}
if( ( V_725 & 0x80 ) && ( V_722 ) ) {
if( V_726 >= 1 ) {
if( ! ( V_725 & 0x08 ) ) {
V_726 = 1 ;
if( ! ( V_725 & 0x10 ) ) return 0xFFFF ;
}
}
}
V_68 = V_726 ;
if( V_726 == 1 ) {
V_68 = 0 ;
if( V_723 & V_734 ) V_118 = 0xff ;
}
if( V_118 ) V_68 = 0 ;
}
V_2 -> V_702 = 0x02 << V_68 ;
V_2 -> V_704 = 0x01 << V_68 ;
F_149 ( V_2 ) ;
return 0 ;
}
static unsigned short
F_161 ( struct V_1 * V_2 )
{
if( F_152 ( V_2 ) ) return 0xFFFF ;
if( F_153 ( V_2 , V_2 -> V_711 ) ) {
return 0xFFFF ;
}
if( F_153 ( V_2 , V_2 -> V_729 ) ) {
return 0xFFFF ;
}
return 0 ;
}
static unsigned short
F_162 ( struct V_1 * V_2 )
{
if( F_152 ( V_2 ) ) return 0xFFFF ;
if( F_153 ( V_2 , ( V_2 -> V_711 | 0x01 ) ) ) {
return 0xFFFF ;
}
return 0 ;
}
static unsigned short
F_163 ( struct V_1 * V_2 )
{
if( F_161 ( V_2 ) ) F_161 ( V_2 ) ;
if( F_162 ( V_2 ) ) return ( F_162 ( V_2 ) ) ;
return 0 ;
}
static void
F_164 ( struct V_1 * V_2 , unsigned short V_735 )
{
F_165 ( V_2 ) ;
if( V_735 ) {
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
} else {
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
0 ) ;
}
F_166 ( V_2 ) ;
}
static unsigned short
F_167 ( struct V_1 * V_2 )
{
unsigned char V_736 , V_737 ;
unsigned short V_68 , V_505 = 0 ;
bool V_738 = false ;
F_154 ( V_2 ) ;
if( F_163 ( V_2 ) ) {
F_151 ( V_2 ) ;
return 0xFFFF ;
}
V_736 = 0xf0 ;
V_737 = 0x20 ;
if( V_2 -> V_711 == 0xa0 ) {
V_68 = ( unsigned char ) F_157 ( V_2 ) ;
F_164 ( V_2 , 0 ) ;
if( V_68 == 0 ) {
V_736 = 0xff ;
V_737 = 0xff ;
} else {
V_738 = true ;
V_505 = 0xFFFF ;
}
}
if( ! V_738 ) {
V_68 = ( unsigned char ) F_157 ( V_2 ) ;
F_164 ( V_2 , 1 ) ;
V_68 &= V_736 ;
if( V_68 == V_737 ) V_505 = 0 ;
else {
V_505 = 0xFFFF ;
if( V_2 -> V_711 == 0xa0 ) {
if( V_68 == 0x30 ) V_505 = 0 ;
}
}
}
F_151 ( V_2 ) ;
return V_505 ;
}
static
unsigned short
F_168 ( struct V_1 * V_2 )
{
unsigned short V_118 ;
V_118 = 0x180 ;
V_2 -> V_711 = 0xa0 ;
if( ! ( F_167 ( V_2 ) ) ) V_118 |= 0x02 ;
V_2 -> V_711 = 0xa2 ;
if( ! ( F_167 ( V_2 ) ) ) V_118 |= 0x08 ;
V_2 -> V_711 = 0xa6 ;
if( ! ( F_167 ( V_2 ) ) ) V_118 |= 0x10 ;
if( ! ( V_118 & 0x1a ) ) V_118 = 0 ;
return V_118 ;
}
static
unsigned short
F_169 ( struct V_1 * V_2 , unsigned short V_721 , unsigned char * V_739 )
{
unsigned short V_118 , V_740 , V_28 ;
unsigned char V_741 , V_742 ;
if( V_721 > 4 ) return 0xFFFF ;
V_118 = 0 ;
F_154 ( V_2 ) ;
if( ! ( F_163 ( V_2 ) ) ) {
V_740 = 127 ;
if( V_721 != 1 ) V_740 = 255 ;
V_741 = 0 ;
V_742 = 0 ;
for( V_28 = 0 ; V_28 < V_740 ; V_28 ++ ) {
V_739 [ V_28 ] = ( unsigned char ) F_157 ( V_2 ) ;
V_741 += V_739 [ V_28 ] ;
V_742 |= V_739 [ V_28 ] ;
F_164 ( V_2 , 0 ) ;
}
V_739 [ V_28 ] = ( unsigned char ) F_157 ( V_2 ) ;
V_741 += V_739 [ V_28 ] ;
F_164 ( V_2 , 1 ) ;
if( V_742 ) V_118 = ( unsigned short ) V_741 ;
else V_118 = 0xFFFF ;
} else {
V_118 = 0xFFFF ;
}
F_151 ( V_2 ) ;
return V_118 ;
}
unsigned short
F_170 ( struct V_1 * V_2 , unsigned int V_718 , int V_719 ,
unsigned short V_720 , unsigned short V_721 , unsigned char * V_739 ,
unsigned int V_723 )
{
unsigned char V_743 , V_744 = 1 ;
unsigned short V_716 ;
if( V_720 > 2 )
return 0xFFFF ;
if( V_721 > 4 )
return 0xFFFF ;
if( ( ! ( V_723 & V_745 ) ) && ( V_720 > 0 ) )
return 0xFFFF ;
if( F_160 ( V_2 , V_718 , V_719 , V_720 , V_721 , false , V_723 ) == 0xFFFF )
return 0xFFFF ;
V_743 = F_8 ( V_2 -> V_10 , 0x1f ) ;
F_6 ( V_2 -> V_10 , 0x1f , 0x3f , 0x04 ) ;
if( V_719 == V_731 ) {
V_744 = F_8 ( V_2 -> V_21 , 0x17 ) & 0x80 ;
if( ! V_744 ) {
F_2 ( V_2 -> V_21 , 0x17 , 0x80 ) ;
F_15 ( V_2 -> V_10 , 0x00 , 0x01 ) ;
F_15 ( V_2 -> V_10 , 0x00 , 0x03 ) ;
}
}
if( ( V_743 ) || ( ! V_744 ) ) {
F_25 ( V_2 ) ;
F_25 ( V_2 ) ;
F_25 ( V_2 ) ;
F_25 ( V_2 ) ;
}
if( V_721 == 0 ) {
V_716 = F_168 ( V_2 ) ;
} else {
V_716 = F_169 ( V_2 , V_721 , V_739 ) ;
if( ( ! V_716 ) && ( V_721 == 1 ) ) {
if( ( V_739 [ 0 ] == 0x00 ) && ( V_739 [ 1 ] == 0xff ) &&
( V_739 [ 2 ] == 0xff ) && ( V_739 [ 3 ] == 0xff ) &&
( V_739 [ 4 ] == 0xff ) && ( V_739 [ 5 ] == 0xff ) &&
( V_739 [ 6 ] == 0xff ) && ( V_739 [ 7 ] == 0x00 ) &&
( V_739 [ 0x12 ] == 1 ) ) {
if( ! V_2 -> V_746 ) {
if( V_720 == 1 ) {
if( ! ( V_739 [ 0x14 ] & 0x80 ) ) V_716 = 0xFFFE ;
} else {
if( V_739 [ 0x14 ] & 0x80 ) V_716 = 0xFFFE ;
}
}
}
}
}
F_15 ( V_2 -> V_10 , 0x1f , V_743 ) ;
if( V_719 == V_731 ) {
F_6 ( V_2 -> V_21 , 0x17 , 0x7f , V_744 ) ;
}
return V_716 ;
}
static void
F_154 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_25 ( V_2 ) ;
F_165 ( V_2 ) ;
F_25 ( V_2 ) ;
}
unsigned short
F_171 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
return ( ( F_8 ( V_2 -> V_10 , 0x11 ) & 0x02 ) >> 1 ) ;
}
static unsigned short
F_152 ( struct V_1 * V_2 )
{
if( F_165 ( V_2 ) ) return 0xFFFF ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
if( F_166 ( V_2 ) ) return 0xFFFF ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
0x00 ) ;
if( F_166 ( V_2 ) ) return 0xFFFF ;
return 0 ;
}
static unsigned short
F_151 ( struct V_1 * V_2 )
{
if( F_165 ( V_2 ) ) return 0xFFFF ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
0x00 ) ;
if( F_166 ( V_2 ) ) return 0xFFFF ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
if( F_166 ( V_2 ) ) return 0xFFFF ;
return 0 ;
}
static unsigned short
F_153 ( struct V_1 * V_2 , unsigned short V_130 )
{
unsigned short V_28 , V_118 , V_68 ;
V_118 = 0x80 ;
for( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
F_165 ( V_2 ) ;
if( V_130 & V_118 ) {
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
} else {
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
0x00 ) ;
}
F_166 ( V_2 ) ;
V_118 >>= 1 ;
}
V_68 = F_172 ( V_2 ) ;
return V_68 ;
}
static unsigned short
F_157 ( struct V_1 * V_2 )
{
unsigned short V_28 , V_68 , V_747 ;
V_747 = 0 ;
for( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_747 <<= 1 ;
F_165 ( V_2 ) ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
F_166 ( V_2 ) ;
V_68 = F_8 ( V_2 -> V_730 , V_2 -> V_705 ) ;
if( V_68 & V_2 -> V_702 ) V_747 |= 0x01 ;
}
return V_747 ;
}
static unsigned short
F_165 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_703 ,
0x00 ) ;
F_18 ( V_2 , V_710 ) ;
return 0 ;
}
static unsigned short
F_166 ( struct V_1 * V_2 )
{
unsigned short V_68 , V_110 = 1000 ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_703 ,
V_2 -> V_704 ) ;
do {
V_68 = F_8 ( V_2 -> V_730 , V_2 -> V_705 ) ;
} while( ( ! ( V_68 & V_2 -> V_704 ) ) && -- V_110 );
if ( ! V_110 ) {
return 0xFFFF ;
}
F_18 ( V_2 , V_710 ) ;
return 0 ;
}
static unsigned short
F_172 ( struct V_1 * V_2 )
{
unsigned short V_362 ;
F_165 ( V_2 ) ;
F_6 ( V_2 -> V_730 ,
V_2 -> V_705 ,
V_2 -> V_701 ,
V_2 -> V_702 ) ;
F_166 ( V_2 ) ;
V_362 = F_8 ( V_2 -> V_730 , V_2 -> V_705 ) ;
F_165 ( V_2 ) ;
if( V_362 & V_2 -> V_702 ) return 1 ;
return 0 ;
}
static unsigned short
F_173 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 ;
if( V_2 -> V_3 < V_103 ) {
V_23 = F_9 ( 0x128 ) ;
if( V_2 -> V_18 & V_619 )
V_23 = F_9 ( 0x12a ) ;
} else {
V_23 = F_9 ( 0x1a8 ) ;
if( V_2 -> V_18 & V_619 )
V_23 = F_9 ( 0x1aa ) ;
}
return V_23 ;
}
static unsigned short
F_174 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 ;
if( V_2 -> V_3 < V_103 ) {
V_23 = F_9 ( 0x120 ) ;
if( V_2 -> V_18 & V_39 )
V_23 = F_9 ( 0x122 ) ;
} else {
V_23 = F_9 ( 0x1a0 ) ;
if( V_2 -> V_18 & V_39 )
V_23 = F_9 ( 0x1a2 ) ;
}
return V_23 ;
}
static unsigned short
F_175 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 ;
if( V_2 -> V_3 < V_103 ) {
V_23 = F_9 ( 0x114 ) ;
if( V_2 -> V_18 & V_39 )
V_23 = F_9 ( 0x11a ) ;
} else {
V_23 = F_9 ( 0x194 ) ;
if( V_2 -> V_18 & V_39 )
V_23 = F_9 ( 0x19a ) ;
}
return V_23 ;
}
static unsigned short
F_176 ( struct V_1 * V_2 )
{
unsigned short V_67 ;
if( ( V_139 ) && ( V_2 -> V_18 & V_19 ) ) {
if( ! ( F_40 ( V_2 ) ) ) {
if( ( V_67 = F_8 ( V_2 -> V_21 , 0x36 ) & 0xf0 ) ) {
V_67 >>= 4 ;
V_67 *= 3 ;
if( V_2 -> V_46 & V_47 ) V_67 += 2 ;
else if( ! ( V_2 -> V_77 & V_318 ) ) V_67 ++ ;
return V_67 ;
}
}
}
V_67 = F_13 ( V_2 ) & 0x0F ;
if( V_2 -> V_183 == V_240 ) V_67 -= 5 ;
if( V_2 -> V_18 & V_748 ) {
if( V_2 -> V_183 == V_241 ) V_67 -= 5 ;
if( V_2 -> V_183 == V_185 ) V_67 -= 5 ;
} else {
if( V_2 -> V_183 == V_241 ) V_67 -= 6 ;
}
V_67 -- ;
V_67 *= 3 ;
if( V_2 -> V_46 & V_47 ) V_67 += 2 ;
else if( ! ( V_2 -> V_77 & V_318 ) ) V_67 ++ ;
return V_67 ;
}
static unsigned short
F_177 ( struct V_1 * V_2 )
{
unsigned short V_67 ;
V_67 = ( ( F_13 ( V_2 ) & 0x0F ) - 1 ) * 3 ;
if( V_2 -> V_46 & V_47 ) V_67 += 2 ;
else if( ! ( V_2 -> V_77 & V_318 ) ) V_67 ++ ;
return V_67 ;
}
static unsigned short
F_178 ( struct V_1 * V_2 )
{
unsigned short V_67 ;
V_67 = 0 ;
if( V_2 -> V_58 & V_157 ) V_67 = 1 ;
if( V_2 -> V_35 & V_50 ) V_67 = 2 ;
if( V_2 -> V_35 & V_52 ) V_67 = 0 ;
V_67 <<= 1 ;
if( ( V_2 -> V_35 & V_85 ) &&
( V_2 -> V_58 & V_178 ) ) {
V_67 ++ ;
}
return V_67 ;
}
static unsigned int
F_179 ( struct V_1 * V_2 , int V_749 )
{
unsigned short V_67 = 0 , V_68 = 0 ;
if( V_2 -> V_58 & V_157 ) V_67 = 1 ;
if( V_2 -> V_58 & V_160 ) V_67 = 2 ;
if( V_2 -> V_58 & V_162 ) V_67 = 3 ;
if( V_2 -> V_58 & V_164 ) V_67 = 6 ;
if( V_2 -> V_58 & V_181 ) {
V_67 = 4 ;
if( V_2 -> V_58 & V_160 ) V_67 ++ ;
if( V_2 -> V_58 & V_164 ) V_67 = 7 ;
}
if( V_2 -> V_18 & V_39 ) {
if( ( ! ( V_2 -> V_35 & V_85 ) ) ||
( V_2 -> V_58 & V_178 ) ) {
V_67 += V_749 ;
V_68 ++ ;
}
V_68 += 0x0100 ;
}
return ( unsigned int ) ( V_67 | ( V_68 << 16 ) ) ;
}
static unsigned int
F_180 ( struct V_1 * V_2 )
{
return ( F_179 ( V_2 , 8 ) ) ;
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
if( V_2 -> V_58 & V_157 ) V_67 = 2 ;
if( V_2 -> V_17 ) {
if( V_2 -> V_58 & V_167 ) V_67 = 4 ;
if( V_2 -> V_58 & V_165 ) V_67 = 6 ;
if( V_2 -> V_58 & V_59 ) V_67 = 8 ;
if( V_2 -> V_58 & V_166 ) V_67 = 10 ;
} else {
if( V_2 -> V_58 & V_166 ) V_67 = 4 ;
if( V_2 -> V_58 & V_167 ) V_67 = 6 ;
if( V_2 -> V_58 & V_165 ) V_67 = 8 ;
if( V_2 -> V_58 & V_59 ) V_67 = 10 ;
}
if( V_2 -> V_58 & V_178 ) V_67 ++ ;
return V_67 ;
}
static void
F_182 ( struct V_1 * V_2 , unsigned short V_25 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_92 = 0 , V_67 , V_750 , V_68 , V_23 = 0 ;
bool V_751 = true ;
if( V_2 -> V_35 & V_44 ) {
F_4 ( V_2 -> V_6 , 0x20 , 0xbf ) ;
} else {
F_4 ( V_2 -> V_6 , 0x35 , 0x7f ) ;
}
if( V_2 -> V_35 & V_36 ) {
if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
V_23 = F_173 ( V_2 ) ;
}
if( V_23 ) V_92 = V_11 [ V_23 ] ;
else {
V_92 = 0x04 ;
if( V_2 -> V_18 & V_619 ) {
if( V_139 ) {
V_92 = 0x0a ;
} else if( V_367 ) {
V_92 = 0x00 ;
} else if( V_2 -> V_3 < V_103 ) {
V_92 = 0x0c ;
} else {
V_92 = 0x0c ;
}
} else if( V_2 -> V_104 == 1 ) {
V_92 = 0x00 ;
}
}
} else if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
bool V_752 = false ;
if( V_2 -> V_35 & V_43 ) {
if( V_2 -> V_600 != - 1 ) {
F_6 ( V_2 -> V_6 , 0x2d , 0xf0 , ( ( V_2 -> V_600 >> 1 ) & 0x0f ) ) ;
F_6 ( V_2 -> V_6 , 0x35 , 0x7f , ( ( V_2 -> V_600 & 0x01 ) << 7 ) ) ;
return;
}
} else {
if( V_2 -> V_753 != - 1 ) {
F_6 ( V_2 -> V_6 , 0x2d , 0x0f , ( ( V_2 -> V_753 << 3 ) & 0xf0 ) ) ;
F_6 ( V_2 -> V_6 , 0x20 , 0xbf , ( ( V_2 -> V_753 & 0x01 ) << 6 ) ) ;
return;
}
}
if( V_2 -> V_183 == V_273 ) {
if( V_2 -> V_35 & V_44 ) {
V_92 = 0x00 ;
if( ( V_2 -> V_247 <= 1280 ) && ( V_2 -> V_248 <= 1024 ) ) {
V_92 = 0x20 ;
}
F_6 ( V_2 -> V_6 , 0x2d , 0x0f , V_92 ) ;
} else {
V_92 = 0x0c ;
if( V_2 -> V_18 & V_748 ) {
V_92 = 0x03 ;
if( ( V_2 -> V_247 > 1280 ) && ( V_2 -> V_248 > 1024 ) ) {
V_92 = 0x00 ;
}
} else if( V_2 -> V_18 & V_19 ) {
if( V_367 ) V_92 = 0x01 ;
else V_92 = 0x03 ;
}
F_6 ( V_2 -> V_6 , 0x2d , 0xf0 , V_92 ) ;
}
return;
}
switch( V_2 -> V_105 ) {
case V_107 :
case V_754 :
if( V_2 -> V_183 == V_239 ) {
V_752 = true ;
V_751 = false ;
V_92 = 0x03 ;
}
break;
case V_106 :
case V_755 :
V_752 = true ;
V_751 = false ;
V_92 = 0x02 ;
break;
case V_237 :
case V_756 :
if( V_2 -> V_183 == V_238 ) {
V_752 = true ;
V_751 = false ;
V_92 = 0x33 ;
F_15 ( V_2 -> V_6 , 0x2D , V_92 ) ;
V_92 &= 0x0f ;
}
break;
}
if( ! V_752 ) {
V_67 = F_176 ( V_2 ) ;
V_750 = F_177 ( V_2 ) ;
if( V_139 && ( V_2 -> V_18 & V_19 ) ) {
if( F_40 ( V_2 ) ) {
if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
V_23 = F_9 ( 0x122 ) ;
if( ! V_23 ) return;
V_92 = V_11 [ ( V_23 + V_67 ) ] ;
} else {
V_92 = V_757 [ V_750 ] ;
}
} else {
V_92 = V_758 [ V_750 ] ;
if( V_2 -> V_18 & ( V_637 | V_759 ) )
V_92 = V_760 [ V_750 ] ;
}
} else if( V_2 -> V_90 &&
( ! ( V_2 -> V_17 ) ) &&
( V_2 -> V_183 != V_239 ) &&
( V_2 -> V_183 != V_185 ) &&
( V_2 -> V_183 != V_233 ) &&
( V_2 -> V_183 != V_241 ) &&
( ( V_23 = F_174 ( V_2 ) ) ) ) {
V_92 = V_11 [ ( V_23 + V_67 ) ] ;
} else if( V_2 -> V_104 == 1 ) {
if( V_367 ) V_92 = 0x03 ;
else V_92 = 0x00 ;
} else {
V_92 = V_761 [ V_750 ] ;
if( V_2 -> V_18 & V_19 ) {
if( V_367 ) V_92 = 0x01 ;
else if( V_2 -> V_3 <= V_102 ) V_92 = V_762 [ V_750 ] ;
else V_92 = V_757 [ V_750 ] ;
} else if( V_2 -> V_18 & V_748 ) {
if( V_367 ) V_92 = 0x01 ;
else V_92 = 0x03 ;
if( V_2 -> V_183 == V_241 ) V_92 = 0x00 ;
} else if( V_2 -> V_18 & V_619 ) {
if( V_367 ) V_92 = 0x01 ;
else V_92 = V_763 [ V_750 ] ;
}
}
}
if( V_2 -> V_35 & V_44 ) {
F_6 ( V_2 -> V_6 , 0x2D , 0x0F , ( ( V_92 << 4 ) & 0xf0 ) ) ;
V_751 = false ;
}
} else if( V_2 -> V_35 & V_62 ) {
V_67 = F_178 ( V_2 ) ;
if( V_139 && ( V_2 -> V_18 & V_19 ) ) {
if( F_40 ( V_2 ) ) {
if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
V_23 = F_9 ( 0x11a ) ;
if( ! V_23 ) return;
V_92 = V_11 [ V_23 + V_67 ] ;
} else {
V_92 = V_764 [ V_67 ] ;
}
} else {
switch( V_2 -> V_105 ) {
case V_107 :
case V_754 :
case V_106 :
case V_755 :
V_92 = 0x02 ;
V_751 = false ;
break;
case V_237 :
case V_756 :
V_92 = 0x03 ;
V_751 = false ;
break;
default:
V_92 = V_765 [ V_67 ] ;
if( V_2 -> V_18 & V_637 ) {
V_92 = V_766 [ V_67 ] ;
}
}
}
} else if( ( V_2 -> V_90 ) && ( ! ( V_2 -> V_17 ) ) ) {
V_23 = F_175 ( V_2 ) ;
if( ! V_23 ) return;
V_92 = V_11 [ V_23 + V_67 ] ;
} else if( V_2 -> V_104 == 1 ) {
V_92 = V_767 [ V_67 ] ;
} else {
V_92 = V_768 [ V_67 ] ;
if( V_2 -> V_18 & V_39 ) {
if( V_367 ) {
V_92 = V_769 [ V_67 ] ;
} else {
V_92 = V_764 [ V_67 ] ;
if( V_2 -> V_18 & V_748 ) V_92 = 0x02 ;
}
}
}
if( F_38 ( V_2 ) ) {
V_92 &= 0x0f ;
V_751 = false ;
}
} else return;
if( V_2 -> V_18 & V_34 ) {
if( V_139 && ( V_2 -> V_18 & V_19 ) && V_751 ) {
V_68 = ( F_8 ( V_2 -> V_21 , 0x36 ) & 0xf0 ) >> 4 ;
if( V_68 == 8 ) {
V_92 &= 0x0f ;
V_92 |= 0xb0 ;
} else if( V_68 == 6 ) {
V_92 &= 0x0f ;
V_92 |= 0xc0 ;
} else if( V_68 > 7 ) {
V_92 = 0x35 ;
}
F_15 ( V_2 -> V_6 , 0x2D , V_92 ) ;
} else {
F_6 ( V_2 -> V_6 , 0x2D , 0xF0 , V_92 ) ;
}
} else {
if( V_2 -> V_35 & V_62 ) {
F_6 ( V_2 -> V_6 , 0x2D , 0xF0 , V_92 ) ;
} else {
if( V_139 && ( V_2 -> V_61 != 0 ) ) {
V_92 <<= 4 ;
F_6 ( V_2 -> V_6 , 0x2D , 0x0F , V_92 ) ;
} else {
F_6 ( V_2 -> V_6 , 0x2D , 0xF0 , V_92 ) ;
}
}
}
}
static void
F_183 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_88 , V_23 = 0 ;
if( V_2 -> V_58 & ( V_59 | V_165 ) ) return;
if( V_25 <= 0x13 )
V_67 = V_2 -> V_71 [ V_26 ] . V_770 ;
else
V_67 = V_2 -> V_73 [ V_26 ] . V_771 ;
V_68 = F_178 ( V_2 ) ;
V_68 >>= 1 ;
V_88 = V_68 ;
if( V_2 -> V_90 && ( ! ( V_2 -> V_17 ) ) ) {
if( V_2 -> V_3 >= V_9 ) {
V_88 = F_181 ( V_2 ) ;
V_88 >>= 1 ;
V_23 = F_9 ( 0x260 ) ;
if( V_2 -> V_3 >= V_556 ) {
V_23 = F_9 ( 0x360 ) ;
}
} else if( V_2 -> V_3 >= V_103 ) {
V_23 = F_9 ( 0x192 ) ;
} else {
V_23 = F_9 ( 0x112 ) ;
}
}
if( V_23 ) {
V_88 <<= 1 ;
V_68 = V_11 [ V_23 + V_88 + V_67 ] ;
} else {
V_68 = V_772 [ V_68 ] [ V_67 ] ;
}
V_68 <<= 4 ;
F_6 ( V_2 -> V_121 , 0x0A , 0x8f , V_68 ) ;
}
static void
F_184 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_88 , V_23 = 0 ;
V_68 = V_88 = F_178 ( V_2 ) >> 1 ;
if( V_25 <= 0x13 )
V_67 = V_2 -> V_71 [ V_26 ] . V_773 ;
else
V_67 = V_2 -> V_73 [ V_26 ] . V_774 ;
if( V_2 -> V_90 && ( ! ( V_2 -> V_17 ) ) ) {
if( V_2 -> V_3 >= V_9 ) {
V_23 = F_9 ( 0x26c ) ;
if( V_2 -> V_3 >= V_556 ) {
V_23 = F_9 ( 0x36c ) ;
}
V_88 = F_181 ( V_2 ) ;
V_88 >>= 1 ;
} else if( V_2 -> V_3 >= V_103 ) {
V_23 = F_9 ( 0x1a4 ) ;
} else {
V_23 = F_9 ( 0x124 ) ;
}
}
if( V_23 ) {
V_88 <<= 1 ;
V_68 = V_11 [ V_23 + V_88 + V_67 ] ;
} else {
V_68 = V_775 [ V_68 ] [ V_67 ] ;
}
V_68 <<= 5 ;
F_6 ( V_2 -> V_121 , 0x3A , 0x1F , V_68 ) ;
}
static void
F_185 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_67 , V_68 , V_28 , V_113 ;
if( V_25 <= 0x13 ) {
V_67 = V_2 -> V_71 [ V_26 ] . V_776 ;
} else {
V_67 = V_2 -> V_73 [ V_26 ] . V_777 ;
}
V_68 = F_178 ( V_2 ) >> 1 ;
if( V_2 -> V_58 & V_164 ) V_68 = 1 ;
else if( V_2 -> V_58 & V_160 ) V_68 = 3 ;
else if( V_2 -> V_58 & V_162 ) V_68 = 4 ;
if( V_2 -> V_35 & V_50 ) V_68 = 1 ;
if( V_2 -> V_18 & V_39 ) {
for( V_28 = 0x35 , V_113 = 0 ; V_28 <= 0x38 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_778 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
for( V_28 = 0x48 ; V_28 <= 0x4A ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_778 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
} else {
for( V_28 = 0x35 , V_113 = 0 ; V_28 <= 0x38 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_779 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
}
}
static void
F_186 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_28 , V_113 , V_132 , V_23 = 0 ;
unsigned int V_780 ;
if( ! ( V_2 -> V_35 & V_62 ) ) return;
if( V_2 -> V_58 & V_164 ) return;
if( ( V_2 -> V_3 >= V_9 ) || V_2 -> V_17 ) {
V_780 = F_180 ( V_2 ) & 0xffff ;
V_780 <<= 2 ;
for( V_113 = 0 , V_28 = 0x31 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_632 [ V_780 + V_113 ] ) ;
}
return;
}
if( V_2 -> V_58 & ( V_160 | V_162 ) ) return;
if( V_25 <= 0x13 ) {
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
} else {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
}
V_68 = F_178 ( V_2 ) ;
if( V_2 -> V_90 ) {
V_23 = F_9 ( 0x116 ) ;
if( V_2 -> V_3 >= V_103 ) {
V_23 = F_9 ( 0x196 ) ;
}
if( V_2 -> V_18 & V_39 ) {
V_23 = F_9 ( 0x11c ) ;
if( V_2 -> V_3 >= V_103 ) {
V_23 = F_9 ( 0x19c ) ;
}
if( ( V_2 -> V_35 & V_85 ) && ( ! ( V_2 -> V_58 & V_178 ) ) ) {
V_23 = F_9 ( 0x116 ) ;
if( V_2 -> V_3 >= V_103 ) {
V_23 = F_9 ( 0x196 ) ;
}
}
}
}
if( V_23 ) {
V_23 += ( V_68 << 2 ) ;
for( V_113 = 0 , V_28 = 0x31 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_11 [ V_23 + V_113 ] ) ;
}
} else {
V_67 = V_68 % 2 ;
V_68 >>= 1 ;
for( V_113 = 0 , V_28 = 0x31 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
if( ! ( V_2 -> V_18 & V_39 ) )
F_15 ( V_2 -> V_121 , V_28 , V_781 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
else if( ( ! ( V_2 -> V_35 & V_85 ) ) || ( V_2 -> V_58 & V_178 ) )
F_15 ( V_2 -> V_121 , V_28 , V_782 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
else
F_15 ( V_2 -> V_121 , V_28 , V_781 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
}
if( ( V_2 -> V_18 & V_39 ) && ( ! ( V_2 -> V_35 & V_50 ) ) ) {
if( ( ! ( V_2 -> V_58 & ( V_157 | V_165 | V_59 ) ) ) && ( V_25 > 0x13 ) ) {
if( ( V_132 == V_783 ) ||
( V_132 == V_315 ) ) {
F_15 ( V_2 -> V_121 , 0x31 , 0x21 ) ;
F_15 ( V_2 -> V_121 , 0x32 , 0xf0 ) ;
F_15 ( V_2 -> V_121 , 0x33 , 0xf5 ) ;
F_15 ( V_2 -> V_121 , 0x34 , 0x7f ) ;
} else if( V_132 == V_179 ) {
F_15 ( V_2 -> V_121 , 0x31 , 0x1e ) ;
F_15 ( V_2 -> V_121 , 0x32 , 0x8b ) ;
F_15 ( V_2 -> V_121 , 0x33 , 0xfb ) ;
F_15 ( V_2 -> V_121 , 0x34 , 0x7b ) ;
}
}
}
}
static void
F_187 ( struct V_1 * V_2 , unsigned short V_25 ,
unsigned short V_26 , unsigned short V_784 )
{
unsigned short V_92 = 0 , V_23 = 0 , V_67 , V_785 ;
unsigned char * V_11 = V_2 -> V_12 ;
if( ! ( V_2 -> V_35 & ( V_62 | V_43 | V_44 | V_36 ) ) )
return;
if( V_2 -> V_17 ) {
if( ( V_2 -> V_35 & V_36 ) ||
( ( V_2 -> V_35 & ( V_43 | V_44 ) ) &&
( V_2 -> V_46 & V_48 ) ) ) {
V_67 = 25 ;
if( V_2 -> V_133 ) {
V_67 = V_2 -> V_555 ;
} else if( V_25 > 0x13 ) {
V_67 = F_59 ( V_2 , V_25 , V_26 , V_784 ) ;
V_67 = V_2 -> V_199 [ V_67 ] . CLOCK ;
}
if( V_67 < 25 ) V_67 = 25 ;
V_67 = ( ( V_67 / 25 ) - 1 ) << 1 ;
if( ( V_11 [ 0x5b ] & 0x80 ) || ( V_2 -> V_35 & ( V_36 | V_43 ) ) ) {
V_67 ++ ;
}
V_23 = F_9 ( 0x104 ) ;
V_92 = V_11 [ V_23 + V_67 ] ;
if( V_2 -> V_35 & ( V_36 | V_43 ) ) {
F_6 ( V_2 -> V_6 , 0x2d , 0xf0 , ( ( V_92 >> 1 ) & 0x0f ) ) ;
F_6 ( V_2 -> V_6 , 0x35 , 0x7f , ( ( V_92 & 0x01 ) << 7 ) ) ;
} else {
F_6 ( V_2 -> V_6 , 0x2d , 0x0f , ( ( V_92 << 3 ) & 0xf0 ) ) ;
F_6 ( V_2 -> V_6 , 0x20 , 0xbf , ( ( V_92 & 0x01 ) << 6 ) ) ;
}
return;
}
}
if( V_2 -> V_133 ) V_92 = 0x04 ;
else if( V_25 <= 0x13 ) V_92 = 0x04 ;
else V_92 = ( V_2 -> V_32 [ V_784 ] . V_786 >> 4 ) ;
V_92 |= ( V_92 << 8 ) ;
if( V_2 -> V_3 >= V_4 ) {
V_92 = 0x0606 ;
if( V_2 -> V_35 & V_62 ) {
V_92 = 0x0404 ;
if( V_2 -> V_787 ) {
V_67 = F_178 ( V_2 ) ;
if( ( V_23 = F_9 ( 0x35e ) ) ) {
V_92 = ( V_11 [ V_23 + V_67 ] & 0x0f ) << 1 ;
V_92 |= ( V_92 << 8 ) ;
}
}
if( V_2 -> V_35 & V_50 ) {
if( V_2 -> V_3 == V_788 && V_2 -> V_349 == 0x02 ) {
V_92 -= 0x0404 ;
}
}
}
} else if( V_2 -> V_3 >= V_789 ) {
V_92 = 0x0606 ;
if( V_2 -> V_35 & V_62 ) {
V_92 = 0x0404 ;
}
} else if( V_2 -> V_35 & V_62 ) {
V_67 = F_181 ( V_2 ) ;
if( V_2 -> V_17 ) {
V_23 = F_9 ( 0x106 ) ;
if( V_2 -> V_18 & V_790 ) V_23 += 12 ;
V_92 = V_11 [ V_23 + V_67 ] ;
} else {
V_92 = 0x04 ;
if( V_67 > 3 ) V_92 = 0 ;
}
} else if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( ( V_2 -> V_183 != V_273 ) &&
( ( V_23 = F_10 ( V_2 ) ) ) ) {
V_785 = ( V_2 -> V_18 & V_790 ) ? 14 : 12 ;
V_92 = V_11 [ V_23 + V_785 + 1 ] ;
V_92 |= ( V_11 [ V_23 + V_785 ] << 8 ) ;
} else {
if( ! ( V_2 -> V_46 & V_48 ) ) {
switch( V_2 -> V_183 ) {
case V_238 : V_92 = 0x0008 ; break;
case V_256 : V_92 = 0x0004 ; break;
case V_185 :
case V_184 : V_92 = 0x0004 ; break;
case V_187 :
case V_186 : V_92 = 0x0004 ; break;
case V_188 : V_92 = 0x0004 ; break;
case V_239 : V_92 = 0x1e04 ; break;
case V_240 : V_92 = 0x0004 ; break;
case V_241 : V_92 = 0x0400 ; break;
case V_242 : V_92 = 0x0e04 ; break;
default:
if( ( V_2 -> V_247 <= 1024 ) && ( V_2 -> V_248 <= 768 ) ) {
V_92 = 0x0008 ;
} else if( ( V_2 -> V_247 == 1280 ) && ( V_2 -> V_248 == 1024 ) ) {
V_92 = 0x1e04 ;
} else if( ( V_2 -> V_247 <= 1400 ) && ( V_2 -> V_248 <= 1050 ) ) {
V_92 = 0x0004 ;
} else if( ( V_2 -> V_247 <= 1600 ) && ( V_2 -> V_248 <= 1200 ) ) {
V_92 = 0x0400 ;
} else
V_92 = 0x0e04 ;
break;
}
}
if( ( V_2 -> V_35 & V_43 ) && ( V_2 -> V_600 != - 1 ) ) {
V_92 = V_2 -> V_600 & 0x1f ;
}
if( ( V_2 -> V_35 & V_44 ) && ( V_2 -> V_753 != - 1 ) ) {
V_92 = ( V_2 -> V_753 & 0x1f ) << 8 ;
}
}
}
if( V_2 -> V_35 & V_44 ) {
V_92 >>= 8 ;
F_6 ( V_2 -> V_6 , 0x2d , 0x0f , ( ( V_92 << 3 ) & 0xf0 ) ) ;
F_6 ( V_2 -> V_6 , 0x20 , 0xbf , ( ( V_92 & 0x01 ) << 6 ) ) ;
} else {
F_6 ( V_2 -> V_6 , 0x2d , 0xf0 , ( ( V_92 >> 1 ) & 0x0f ) ) ;
F_6 ( V_2 -> V_6 , 0x35 , 0x7f , ( ( V_92 & 0x01 ) << 7 ) ) ;
}
}
static void
F_188 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_784 )
{
unsigned short V_31 ;
unsigned char V_68 ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_25 <= 0x13 ) {
V_31 = F_26 ( V_2 -> V_327 + 2 ) ;
} else if( V_2 -> V_133 ) {
V_31 = V_2 -> V_534 ;
} else {
V_31 = V_2 -> V_32 [ V_784 ] . V_64 ;
}
if( ! ( V_2 -> V_46 & V_48 ) ) {
V_31 = F_8 ( V_2 -> V_21 , 0x37 ) ;
}
V_31 &= 0xc0 ;
if( V_2 -> V_35 & V_43 ) {
V_68 = ( V_31 >> 6 ) | 0x0c ;
if( V_2 -> V_46 & V_236 ) {
V_68 ^= 0x04 ;
if( V_2 -> V_84 >= V_791 ) V_68 |= 0x10 ;
}
F_6 ( V_2 -> V_121 , 0x1a , 0xe0 , V_68 ) ;
} else {
V_68 = 0x30 ;
if( V_2 -> V_46 & V_236 ) V_68 = 0x20 ;
V_68 |= V_31 ;
F_6 ( V_2 -> V_6 , 0x19 , 0x0f , V_68 ) ;
V_68 = 0 ;
if( V_2 -> V_46 & V_236 ) {
if( V_2 -> V_84 >= V_791 ) V_68 |= 0x80 ;
}
F_6 ( V_2 -> V_6 , 0x1a , 0x7f , V_68 ) ;
}
}
}
static void
F_189 ( struct V_1 * V_2 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_23 , V_88 , V_89 ;
if( V_2 -> V_18 & ( V_19 | V_536 ) ) {
F_4 ( V_2 -> V_114 , 0x24 , 0x0f ) ;
}
if( V_2 -> V_18 & V_19 ) {
if( V_2 -> V_792 != - 1 ) {
F_6 ( V_2 -> V_114 , 0x24 , 0xfc , V_2 -> V_792 ) ;
}
}
if( V_2 -> V_17 ) {
if( ( V_23 = F_10 ( V_2 ) ) ) {
if( V_2 -> V_18 & V_19 ) {
V_88 = ( V_11 [ V_23 ] & 0x03 ) | 0x0c ;
V_89 = 0xfc ;
if( V_2 -> V_792 != - 1 ) {
V_88 &= 0xfc ;
V_89 = 0xf3 ;
}
F_6 ( V_2 -> V_114 , 0x24 , V_89 , V_88 ) ;
}
if( V_2 -> V_35 & V_43 ) {
V_88 = ( V_11 [ V_23 + 1 ] & 0x80 ) >> 1 ;
F_6 ( V_2 -> V_114 , 0x0d , 0xbf , V_88 ) ;
}
}
}
}
static void
F_145 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 , unsigned short V_27 )
{
if( ( V_2 -> V_17 ) && ( V_2 -> V_18 & V_19 ) ) {
F_187 ( V_2 , V_25 , V_26 , V_27 ) ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
F_188 ( V_2 , V_25 , V_27 ) ;
F_189 ( V_2 ) ;
}
} else {
F_182 ( V_2 , V_25 ) ;
}
if( ( V_2 -> V_18 & V_34 ) && ( V_2 -> V_35 & V_62 ) ) {
F_183 ( V_2 , V_25 , V_26 ) ;
F_186 ( V_2 , V_25 , V_26 ) ;
F_185 ( V_2 , V_25 , V_26 ) ;
if( V_2 -> V_18 & V_99 ) {
F_184 ( V_2 , V_25 , V_26 ) ;
}
}
}
static void
F_146 ( struct V_1 * V_2 , unsigned short V_25 ,
unsigned short V_26 , unsigned short V_27 )
{
if( V_2 -> V_18 & V_34 ) {
F_187 ( V_2 , V_25 , V_26 , V_27 ) ;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
F_188 ( V_2 , V_25 , V_27 ) ;
F_189 ( V_2 ) ;
}
if( V_2 -> V_35 & V_62 ) {
F_186 ( V_2 , V_25 , V_26 ) ;
F_185 ( V_2 , V_25 , V_26 ) ;
F_183 ( V_2 , V_25 , V_26 ) ;
if( V_2 -> V_18 & V_99 ) {
F_184 ( V_2 , V_25 , V_26 ) ;
}
}
}
}
static void
F_144 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned short V_363 , V_620 , V_364 , V_694 , V_131 , V_130 , V_68 ;
unsigned short V_132 , V_66 ;
if( ! ( V_2 -> V_18 & V_19 ) ) return;
if( V_2 -> V_17 ) return;
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_792 != - 1 ) {
F_6 ( V_2 -> V_114 , 0x24 , 0xfc , V_2 -> V_792 ) ;
}
}
if( V_2 -> V_183 == V_273 ) return;
if( V_2 -> V_133 ) return;
switch( V_2 -> V_105 ) {
case V_107 :
case V_754 :
case V_106 :
case V_755 :
return;
}
if( V_25 <= 0x13 ) {
V_132 = V_2 -> V_71 [ V_26 ] . V_325 ;
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
} else {
V_132 = V_2 -> V_73 [ V_26 ] . V_134 ;
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
}
if( V_139 ) {
if( ! ( F_8 ( V_2 -> V_21 , 0x5f ) & 0xf0 ) ) {
if( V_2 -> V_105 == V_237 ) {
F_2 ( V_2 -> V_6 , 0x1e , 0x02 ) ;
} else {
F_2 ( V_2 -> V_6 , 0x1e , 0x03 ) ;
}
}
}
if( V_2 -> V_105 == V_237 ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_792 == - 1 ) {
F_6 ( V_2 -> V_114 , 0x24 , 0xfc , 0x01 ) ;
}
return;
}
}
if( V_2 -> V_105 == V_756 ) {
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_792 == - 1 ) {
F_6 ( V_2 -> V_114 , 0x24 , 0xfc , 0x01 ) ;
}
if( V_2 -> V_35 & V_44 ) {
V_620 = F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ;
if( V_620 == 3 ) {
F_15 ( V_2 -> V_6 , 0x18 , 0x02 ) ;
F_15 ( V_2 -> V_6 , 0x1b , 0x25 ) ;
F_15 ( V_2 -> V_6 , 0x1c , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x1d , 0x1b ) ;
}
}
return;
}
}
}
if( V_2 -> V_35 & ( V_43 | V_44 ) ) {
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_18 & V_513 ) {
F_15 ( V_2 -> V_114 , 0x2a , 0x00 ) ;
#ifdef F_79
F_4 ( V_2 -> V_114 , 0x30 , 0x0c ) ;
#endif
F_15 ( V_2 -> V_114 , 0x34 , 0x10 ) ;
}
} else if( V_2 -> V_183 == V_239 ) {
if( V_2 -> V_792 == - 1 ) {
F_6 ( V_2 -> V_114 , 0x24 , 0xfc , 0x01 ) ;
}
}
V_620 = F_8 ( V_2 -> V_21 , 0x36 ) >> 4 ;
if( V_2 -> V_35 & V_44 ) {
if( V_2 -> V_183 == V_240 ) {
F_15 ( V_2 -> V_6 , 0x1f , 0x76 ) ;
} else if( V_2 -> V_183 == V_238 ) {
if( V_620 == 0x03 ) {
F_15 ( V_2 -> V_6 , 0x18 , 0x02 ) ;
F_15 ( V_2 -> V_6 , 0x1b , 0x25 ) ;
F_15 ( V_2 -> V_6 , 0x1c , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x1d , 0x1b ) ;
}
if( V_2 -> V_793 && ( V_2 -> V_794 == V_25 ) ) {
F_15 ( V_2 -> V_6 , 0x14 , V_2 -> V_795 ) ;
F_15 ( V_2 -> V_6 , 0x15 , V_2 -> V_796 ) ;
F_15 ( V_2 -> V_6 , 0x16 , V_2 -> V_797 ) ;
F_15 ( V_2 -> V_6 , 0x17 , V_2 -> V_798 ) ;
F_15 ( V_2 -> V_6 , 0x18 , V_2 -> V_799 ) ;
F_15 ( V_2 -> V_6 , 0x19 , V_2 -> V_800 ) ;
F_15 ( V_2 -> V_6 , 0x1a , V_2 -> V_801 ) ;
F_15 ( V_2 -> V_6 , 0x1b , V_2 -> V_802 ) ;
F_15 ( V_2 -> V_6 , 0x1c , V_2 -> V_803 ) ;
F_15 ( V_2 -> V_6 , 0x1d , V_2 -> V_804 ) ;
} else if( ! ( V_2 -> V_46 & V_47 ) ) {
F_15 ( V_2 -> V_6 , 0x14 , 0x90 ) ;
if( V_25 <= 0x13 ) {
F_15 ( V_2 -> V_6 , 0x18 , 0x11 ) ;
if( ( V_132 == 0 ) || ( V_132 == 2 ) ) return;
F_15 ( V_2 -> V_6 , 0x18 , 0x18 ) ;
if( ( V_132 == 1 ) || ( V_132 == 3 ) ) return;
}
F_15 ( V_2 -> V_6 , 0x18 , 0x02 ) ;
if( ( V_25 > 0x13 ) && ( V_132 == V_179 ) ) {
F_15 ( V_2 -> V_6 , 0x18 , 0x02 ) ;
#if 0
tempbx = 806;
tempbx--;
temp = tempbx & 0xff;
SiS_SetReg(SiS_Pr->SiS_Part1Port,0x1b,temp);
temp = (tempbx >> 8) & 0x03;
SiS_SetRegANDOR(SiS_Pr->SiS_Part1Port,0x1d,0xf8,temp);
#endif
}
} else if( V_25 <= 0x13 ) {
if( V_25 <= 1 ) {
F_15 ( V_2 -> V_6 , 0x18 , 0x70 ) ;
F_15 ( V_2 -> V_6 , 0x19 , 0xff ) ;
F_15 ( V_2 -> V_6 , 0x1b , 0x48 ) ;
F_15 ( V_2 -> V_6 , 0x1d , 0x12 ) ;
}
if( ! ( V_66 & V_75 ) ) {
F_15 ( V_2 -> V_6 , 0x14 , 0x20 ) ;
F_15 ( V_2 -> V_6 , 0x15 , 0x1a ) ;
F_15 ( V_2 -> V_6 , 0x16 , 0x28 ) ;
F_15 ( V_2 -> V_6 , 0x17 , 0x00 ) ;
F_15 ( V_2 -> V_6 , 0x18 , 0x4c ) ;
F_15 ( V_2 -> V_6 , 0x19 , 0xdc ) ;
if( V_25 == 0x12 ) {
switch( V_620 ) {
case 0 :
F_15 ( V_2 -> V_6 , 0x18 , 0x95 ) ;
F_15 ( V_2 -> V_6 , 0x19 , 0xdc ) ;
F_15 ( V_2 -> V_6 , 0x1a , 0x10 ) ;
F_15 ( V_2 -> V_6 , 0x1b , 0x95 ) ;
F_15 ( V_2 -> V_6 , 0x1c , 0x48 ) ;
F_15 ( V_2 -> V_6 , 0x1d , 0x12 ) ;
break;
case 2 :
F_15 ( V_2 -> V_6 , 0x18 , 0x95 ) ;
F_15 ( V_2 -> V_6 , 0x1b , 0x48 ) ;
break;
case 3 :
F_15 ( V_2 -> V_6 , 0x1b , 0x95 ) ;
break;
}
}
}
}
}
} else {
V_363 = V_694 = F_8 ( V_2 -> V_121 , 0x01 ) ;
V_363 &= 0x0f ;
V_694 &= 0x70 ;
V_694 >>= 4 ;
V_364 = F_8 ( V_2 -> V_121 , 0x04 ) ;
V_131 = ( V_694 << 8 ) | V_364 ;
if( V_2 -> V_183 == V_238 ) {
if( ( V_132 == V_179 ) || ( ! ( V_2 -> V_46 & V_47 ) ) ) {
if( V_2 -> V_77 & V_318 ) {
V_131 = 770 ;
} else {
if( V_131 > 770 ) V_131 = 770 ;
if( V_2 -> V_378 < 600 ) {
V_130 = 768 - V_2 -> V_378 ;
V_130 >>= 4 ;
if( V_2 -> V_378 <= 480 ) V_130 >>= 4 ;
V_131 -= V_130 ;
}
}
} else return;
}
V_68 = V_131 & 0xff ;
F_15 ( V_2 -> V_121 , 0x04 , V_68 ) ;
V_68 = ( ( V_131 & 0xff00 ) >> 4 ) | V_363 ;
F_6 ( V_2 -> V_121 , 0x01 , 0x80 , V_68 ) ;
}
}
}
static void
F_143 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_805 )
{
unsigned short V_580 = 0 , V_66 , V_750 = 0 ;
unsigned char V_68 ;
int V_28 ;
if( V_25 <= 0x13 ) {
V_66 = V_2 -> V_71 [ V_26 ] . V_72 ;
V_580 = V_2 -> V_71 [ V_26 ] . V_326 ;
} else {
V_66 = V_2 -> V_73 [ V_26 ] . V_74 ;
V_580 = V_2 -> V_32 [ V_805 ] . V_328 ;
}
V_580 &= 0x3f ;
if( V_2 -> V_105 == V_293 ) {
F_4 ( V_2 -> V_6 , 0x13 , 0xdf ) ;
}
if( V_2 -> V_105 == V_224 ) {
if( V_66 & V_75 ) V_750 = 1 ;
if( V_2 -> V_77 & V_699 ) {
for( V_28 = 0 ; V_28 < 7 ; V_28 ++ ) {
if( V_806 [ V_750 ] [ V_580 ] [ V_28 ] [ 0 ] ) {
F_6 ( V_2 -> V_6 ,
V_806 [ V_750 ] [ V_580 ] [ V_28 ] [ 0 ] ,
V_806 [ V_750 ] [ V_580 ] [ V_28 ] [ 2 ] ,
V_806 [ V_750 ] [ V_580 ] [ V_28 ] [ 1 ] ) ;
}
}
}
V_68 = F_8 ( V_2 -> V_6 , 0x00 ) ;
if( V_68 & 0x80 ) {
V_68 = F_8 ( V_2 -> V_6 , 0x18 ) ;
V_68 ++ ;
F_15 ( V_2 -> V_6 , 0x18 , V_68 ) ;
}
}
}
static unsigned short
F_190 ( struct V_1 * V_2 , int V_807 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_131 = 0 , V_23 = 0 ;
static const unsigned char V_808 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
static const unsigned char V_809 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
if( V_2 -> V_3 == V_350 ) {
V_131 = F_8 ( V_2 -> V_21 , 0x36 ) & 0x0f ;
if( V_2 -> V_18 & V_99 ) V_131 &= 0x07 ;
V_131 -= 2 ;
if( ! ( V_2 -> V_77 & V_318 ) ) V_131 += 4 ;
if( V_2 -> V_183 == V_238 ) {
if( V_2 -> V_46 & V_47 ) V_131 += 3 ;
}
if( V_2 -> V_90 ) {
if( V_11 [ 0x235 ] & 0x80 ) {
V_131 = V_2 -> V_211 ;
if( V_807 ) {
V_23 = F_9 ( 0x255 ) ;
if( V_23 ) V_131 = V_11 [ V_23 + V_2 -> V_211 ] ;
else V_131 = V_808 [ V_2 -> V_211 ] ;
if( V_131 == 0xFF ) return 0xFFFF ;
}
V_131 <<= 1 ;
if( ! ( V_2 -> V_77 & V_318 ) ) V_131 ++ ;
}
}
} else {
if( V_807 ) {
if( V_2 -> V_90 ) {
V_23 = F_9 ( 0x255 ) ;
if( V_23 ) V_131 = V_11 [ V_23 + V_2 -> V_211 ] ;
else V_131 = 0xff ;
} else {
V_131 = V_809 [ V_2 -> V_211 ] ;
}
if( V_131 == 0xFF ) return 0xFFFF ;
V_131 <<= 2 ;
if( V_2 -> V_35 & V_85 ) V_131 += 2 ;
if( V_2 -> V_46 & V_47 ) V_131 ++ ;
return V_131 ;
}
V_131 = V_2 -> V_211 << 2 ;
if( V_2 -> V_35 & V_85 ) V_131 += 2 ;
if( V_2 -> V_46 & V_47 ) V_131 ++ ;
}
return V_131 ;
}
static void
F_191 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_23 = 0 ;
if( V_2 -> V_183 == V_273 ) return;
if( V_2 -> V_90 ) {
if( ! ( V_11 [ 0x237 ] & 0x01 ) ) return;
if( ! ( V_11 [ 0x237 ] & 0x02 ) ) return;
V_23 = F_9 ( 0x24b ) ;
}
if( V_2 -> V_600 != - 1 ) return;
V_68 = F_190 ( V_2 , 0 ) ;
if( V_2 -> V_133 )
V_67 = 0 ;
else
V_67 = V_2 -> V_810 [ V_26 ] . V_811 ;
if( V_2 -> V_3 != V_350 ) {
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += V_67 ;
V_68 = V_11 [ V_23 ] ;
} else {
if( V_2 -> V_18 & V_34 ) {
V_68 = V_812 [ V_68 ] [ V_67 ] ;
} else {
V_68 = V_813 [ V_68 ] [ V_67 ] ;
}
}
} else {
if( V_2 -> V_90 && ( V_11 [ 0x235 ] & 0x80 ) ) {
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += V_67 ;
V_68 = V_11 [ V_23 ] ;
} else {
V_68 = V_814 [ V_68 ] [ V_67 ] ;
}
} else {
if( V_2 -> V_90 ) {
V_23 = V_11 [ 0x249 ] | ( V_11 [ 0x24a ] << 8 ) ;
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += V_67 ;
V_68 = V_11 [ V_23 ] ;
} else {
V_68 = V_815 [ V_68 ] [ V_67 ] ;
}
} else {
V_68 = V_815 [ V_68 ] [ V_67 ] ;
}
}
}
V_68 &= 0x3c ;
F_6 ( V_2 -> V_6 , 0x13 , ~ 0x3C , V_68 ) ;
}
static void
F_192 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
#if 0
unsigned char *ROMAddr = SiS_Pr->VirtualRomBase;
unsigned short index,temp;
if((SiS_Pr->SiS_UseROM) {
if(!(ROMAddr[0x237] & 0x01)) return;
if(!(ROMAddr[0x237] & 0x04)) return;
}
temp = GetOEMLCDPtr(SiS_Pr, 1);
if(temp == 0xFFFF) return;
index = SiS_Pr->SiS_VBModeIDTable[ModeIdIndex]._VB_LCDHIndex;
for(i=0x14, j=0; i<=0x17; i++, j++) {
SiS_SetReg(SiS_Pr->SiS_Part1Port,i,SiS300_LCDHData[temp][index][j]);
}
SiS_SetRegANDOR(SiS_SiS_Part1Port,0x1a, 0xf8, (SiS300_LCDHData[temp][index][j] & 0x07));
index = SiS_Pr->SiS_VBModeIDTable[ModeIdIndex]._VB_LCDVIndex;
SiS_SetReg(SiS_SiS_Part1Port,0x18, SiS300_LCDVData[temp][index][0]);
SiS_SetRegANDOR(SiS_SiS_Part1Port,0x19, 0xF0, SiS300_LCDVData[temp][index][1]);
SiS_SetRegANDOR(SiS_SiS_Part1Port,0x1A, 0xC7, (SiS300_LCDVData[temp][index][2] & 0x38));
for(i=0x1b, j=3; i<=0x1d; i++, j++) {
SiS_SetReg(SiS_Pr->SiS_Part1Port,i,SiS300_LCDVData[temp][index][j]);
}
#endif
}
static unsigned short
F_193 ( struct V_1 * V_2 )
{
unsigned short V_67 ;
V_67 = 0 ;
if( ! ( V_2 -> V_35 & V_85 ) ) V_67 += 4 ;
if( V_2 -> V_18 & V_34 ) {
if( V_2 -> V_35 & V_55 ) V_67 += 2 ;
else if( V_2 -> V_35 & V_50 ) V_67 += 3 ;
else if( V_2 -> V_58 & V_157 ) V_67 += 1 ;
} else {
if( V_2 -> V_58 & V_170 ) V_67 += 2 ;
if( V_2 -> V_58 & V_157 ) V_67 += 1 ;
}
return V_67 ;
}
static void
F_194 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_23 = 0 ;
if( V_2 -> V_90 ) {
if( ! ( V_11 [ 0x238 ] & 0x01 ) ) return;
if( ! ( V_11 [ 0x238 ] & 0x02 ) ) return;
V_23 = F_9 ( 0x241 ) ;
}
V_68 = F_193 ( V_2 ) ;
V_67 = V_2 -> V_810 [ V_26 ] . V_816 ;
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += V_67 ;
V_68 = V_11 [ V_23 ] ;
} else {
if( V_2 -> V_18 & V_34 ) {
V_68 = V_817 [ V_68 ] [ V_67 ] ;
} else {
V_68 = V_818 [ V_68 ] [ V_67 ] ;
}
}
V_68 &= 0x3c ;
F_6 ( V_2 -> V_6 , 0x13 , ~ 0x3C , V_68 ) ;
}
static void
F_195 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_23 = 0 ;
if( V_2 -> V_90 ) {
if( ! ( V_11 [ 0x238 ] & 0x01 ) ) return;
if( ! ( V_11 [ 0x238 ] & 0x04 ) ) return;
V_23 = F_9 ( 0x243 ) ;
}
V_68 = F_193 ( V_2 ) ;
V_67 = V_2 -> V_810 [ V_26 ] . V_819 ;
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += V_67 ;
V_68 = V_11 [ V_23 ] ;
} else {
V_68 = V_820 [ V_68 ] [ V_67 ] ;
}
V_68 &= 0x70 ;
F_6 ( V_2 -> V_121 , 0x0A , 0x8F , V_68 ) ;
}
static void
F_196 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_28 , V_113 , V_68 , V_23 = 0 ;
if( V_2 -> V_35 & V_50 ) return;
if( V_2 -> V_58 & ( V_181 | V_164 | V_160 | V_162 ) ) return;
if( V_2 -> V_90 ) {
if( ! ( V_11 [ 0x238 ] & 0x01 ) ) return;
if( ! ( V_11 [ 0x238 ] & 0x08 ) ) return;
V_23 = F_9 ( 0x245 ) ;
}
V_68 = F_193 ( V_2 ) ;
V_67 = V_2 -> V_810 [ V_26 ] . V_821 ;
if( V_2 -> V_18 & V_39 ) {
for( V_28 = 0x31 , V_113 = 0 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_822 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
} else {
if( V_23 ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += ( V_67 * 4 ) ;
for( V_28 = 0x31 , V_113 = 0 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_11 [ V_23 + V_113 ] ) ;
}
} else {
for( V_28 = 0x31 , V_113 = 0 ; V_28 <= 0x34 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_823 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
}
}
}
static void
F_197 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 )
{
unsigned char * V_11 = V_2 -> V_12 ;
unsigned short V_67 , V_68 , V_28 , V_113 , V_23 = 0 ;
if( V_2 -> V_35 & ( V_55 | V_50 | V_52 ) ) return;
if( V_2 -> V_90 ) {
if( ! ( V_11 [ 0x238 ] & 0x01 ) ) return;
if( ! ( V_11 [ 0x238 ] & 0x10 ) ) return;
V_23 = F_9 ( 0x247 ) ;
}
V_68 = F_193 ( V_2 ) ;
if( V_2 -> V_58 & V_160 ) V_68 = 8 ;
else if( V_2 -> V_58 & V_162 ) V_68 = 9 ;
V_67 = V_2 -> V_810 [ V_26 ] . V_824 ;
if( V_2 -> V_18 & V_39 ) {
for( V_28 = 0x35 , V_113 = 0 ; V_28 <= 0x38 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_825 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
for( V_28 = 0x48 ; V_28 <= 0x4A ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_825 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
} else {
if( ( V_23 ) && ( ! ( V_2 -> V_58 & ( V_160 | V_162 ) ) ) ) {
V_23 += ( V_68 * 2 ) ;
V_23 = F_9 ( V_23 ) ;
V_23 += ( V_67 * 4 ) ;
for( V_28 = 0x35 , V_113 = 0 ; V_28 <= 0x38 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_11 [ V_23 + V_113 ] ) ;
}
} else {
for( V_28 = 0x35 , V_113 = 0 ; V_28 <= 0x38 ; V_28 ++ , V_113 ++ ) {
F_15 ( V_2 -> V_121 , V_28 , V_826 [ V_68 ] [ V_67 ] [ V_113 ] ) ;
}
}
}
}
static unsigned short
F_198 ( struct V_1 * V_2 , unsigned short * V_25 )
{
unsigned short V_26 ;
unsigned char V_827 = V_2 -> V_828 ;
if( * V_25 <= 5 ) * V_25 |= 1 ;
for( V_26 = 0 ; ; V_26 ++ ) {
if( V_2 -> V_810 [ V_26 ] . V_33 == * V_25 ) break;
if( V_2 -> V_810 [ V_26 ] . V_33 == 0xFF ) return 0 ;
}
if( * V_25 != 0x07 ) {
if( * V_25 > 0x03 ) return V_26 ;
if( V_827 & 0x80 ) return V_26 ;
V_26 ++ ;
}
if( V_827 & 0x10 ) V_26 ++ ;
return V_26 ;
}
static void
F_142 ( struct V_1 * V_2 , unsigned short V_25 , unsigned short V_26 ,
unsigned short V_829 )
{
unsigned short V_830 = 0 ;
if( ! V_2 -> V_133 ) {
V_830 = F_198 ( V_2 , & V_25 ) ;
if( ! ( V_830 ) ) return;
}
if( V_2 -> V_35 & V_43 ) {
F_191 ( V_2 , V_25 , V_830 ) ;
if( V_2 -> V_104 == 1 ) {
F_192 ( V_2 , V_25 , V_830 ) ;
}
}
if( V_2 -> V_133 ) return;
if( V_2 -> V_35 & V_62 ) {
F_194 ( V_2 , V_25 , V_830 ) ;
if( V_2 -> V_18 & V_34 ) {
F_195 ( V_2 , V_25 , V_830 ) ;
F_196 ( V_2 , V_25 , V_830 ) ;
F_197 ( V_2 , V_25 , V_830 ) ;
}
}
}
