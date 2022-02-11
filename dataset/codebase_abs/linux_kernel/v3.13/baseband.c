static
void
F_1 (
T_1 V_1
)
{
if ( V_1 -> V_2 == 0 ) {
V_1 -> V_2 = 1 ;
if ( V_1 -> V_3 == true )
F_2 ( V_1 -> V_4 , V_5 ) ;
else
F_2 ( V_1 -> V_4 , V_6 ) ;
} else {
V_1 -> V_2 = 0 ;
if ( V_1 -> V_3 == true )
F_2 ( V_1 -> V_4 , V_6 ) ;
else
F_2 ( V_1 -> V_4 , V_5 ) ;
}
if ( V_1 -> V_7 == 0 ) {
V_1 -> V_7 = 1 ;
F_3 ( V_1 -> V_4 , V_6 ) ;
} else {
V_1 -> V_7 = 0 ;
F_3 ( V_1 -> V_4 , V_5 ) ;
}
}
unsigned int
F_4 (
unsigned char V_8 ,
unsigned char V_9 ,
unsigned int V_10 ,
unsigned short V_11
)
{
unsigned int V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 = ( unsigned int ) V_11 ;
unsigned int V_16 = 0 ;
if ( V_15 > V_17 ) {
ASSERT ( 0 ) ;
return 0 ;
}
V_16 = ( unsigned int ) V_18 [ V_15 ] ;
if ( V_15 <= 3 ) {
if ( V_8 == 1 ) {
V_13 = 96 ;
} else {
V_13 = 192 ;
}
V_12 = ( V_10 * 80 ) / V_16 ;
V_14 = ( V_12 * V_16 ) / 80 ;
if ( V_10 != V_14 ) {
V_12 ++ ;
}
return V_13 + V_12 ;
} else {
V_12 = ( V_10 * 8 + 22 ) / V_16 ;
V_14 = ( ( V_12 * V_16 ) - 22 ) / 8 ;
if ( V_10 != V_14 ) {
V_12 ++ ;
}
V_12 = V_12 * 4 ;
if ( V_9 != V_19 ) {
V_12 += 6 ;
}
return 20 + V_12 ;
}
}
void
F_5 (
T_1 V_1 ,
unsigned int V_10 ,
unsigned short V_11 ,
unsigned char V_20 ,
unsigned short * V_21 ,
unsigned char * V_22 ,
unsigned char * V_23
)
{
unsigned int V_24 ;
unsigned int V_25 = 0 ;
unsigned int V_26 ;
bool V_27 ;
unsigned char V_8 = V_1 -> V_8 ;
bool V_28 = V_1 -> V_28 ;
V_24 = V_10 * 8 ;
V_27 = false ;
switch ( V_11 ) {
case V_29 :
V_25 = V_24 ;
* V_23 = 0x00 ;
break;
case V_30 :
V_25 = V_24 / 2 ;
if ( V_8 == 1 )
* V_23 = 0x09 ;
else
* V_23 = 0x01 ;
break;
case V_31 :
if ( V_28 == false )
V_24 ++ ;
V_25 = ( V_24 * 10 ) / 55 ;
V_26 = ( V_25 * 55 ) / 10 ;
if ( V_26 != V_24 )
V_25 ++ ;
if ( V_8 == 1 )
* V_23 = 0x0a ;
else
* V_23 = 0x02 ;
break;
case V_32 :
if ( V_28 == false )
V_24 ++ ;
V_25 = V_24 / 11 ;
V_26 = V_25 * 11 ;
if ( V_26 != V_24 ) {
V_25 ++ ;
if ( ( V_24 - V_26 ) <= 3 )
V_27 = true ;
}
if ( V_8 == 1 )
* V_23 = 0x0b ;
else
* V_23 = 0x03 ;
break;
case V_33 :
if ( V_20 == V_19 ) {
* V_23 = 0x9B ;
} else {
* V_23 = 0x8B ;
}
break;
case V_34 :
if ( V_20 == V_19 ) {
* V_23 = 0x9F ;
} else {
* V_23 = 0x8F ;
}
break;
case V_35 :
if ( V_20 == V_19 ) {
* V_23 = 0x9A ;
} else {
* V_23 = 0x8A ;
}
break;
case V_36 :
if ( V_20 == V_19 ) {
* V_23 = 0x9E ;
} else {
* V_23 = 0x8E ;
}
break;
case V_37 :
if ( V_20 == V_19 ) {
* V_23 = 0x99 ;
} else {
* V_23 = 0x89 ;
}
break;
case V_38 :
if ( V_20 == V_19 ) {
* V_23 = 0x9D ;
} else {
* V_23 = 0x8D ;
}
break;
case V_39 :
if ( V_20 == V_19 ) {
* V_23 = 0x98 ;
} else {
* V_23 = 0x88 ;
}
break;
case V_17 :
if ( V_20 == V_19 ) {
* V_23 = 0x9C ;
} else {
* V_23 = 0x8C ;
}
break;
default:
if ( V_20 == V_19 ) {
* V_23 = 0x9C ;
} else {
* V_23 = 0x8C ;
}
break;
}
if ( V_20 == V_40 ) {
* V_22 = 0x00 ;
if ( V_27 )
* V_22 = * V_22 | 0x80 ;
* V_21 = ( unsigned short ) V_25 ;
} else {
* V_22 = 0x00 ;
* V_21 = ( unsigned short ) V_10 ;
}
}
bool F_6 ( unsigned long V_41 , unsigned char V_42 , unsigned char * V_43 )
{
unsigned short V_44 ;
unsigned char V_45 ;
F_7 ( V_41 + V_46 , V_42 ) ;
F_8 ( V_41 , V_47 , V_48 ) ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ ) {
F_9 ( V_41 + V_47 , & V_45 ) ;
if ( V_45 & V_50 )
break;
}
F_9 ( V_41 + V_51 , V_43 ) ;
if ( V_44 == V_49 ) {
F_10 ( 0x30 ) ;
F_11 ( V_52 , V_53 L_1 ) ;
return false ;
}
return true ;
}
bool F_12 ( unsigned long V_41 , unsigned char V_42 , unsigned char V_54 )
{
unsigned short V_44 ;
unsigned char V_45 ;
F_7 ( V_41 + V_46 , V_42 ) ;
F_7 ( V_41 + V_51 , V_54 ) ;
F_8 ( V_41 , V_47 , V_55 ) ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ ) {
F_9 ( V_41 + V_47 , & V_45 ) ;
if ( V_45 & V_50 )
break;
}
if ( V_44 == V_49 ) {
F_10 ( 0x31 ) ;
F_11 ( V_52 , V_53 L_2 ) ;
return false ;
}
return true ;
}
bool F_13 ( unsigned long V_41 , unsigned char V_42 , unsigned char V_56 )
{
unsigned char V_57 ;
F_6 ( V_41 , V_42 , & V_57 ) ;
return ( V_57 & V_56 ) == V_56 ;
}
bool F_14 ( unsigned long V_41 , unsigned char V_42 , unsigned char V_56 )
{
unsigned char V_57 ;
F_6 ( V_41 , V_42 , & V_57 ) ;
return ( V_57 & V_56 ) == 0 ;
}
bool F_15 ( T_1 V_1 )
{
bool V_58 = true ;
int V_59 ;
unsigned long V_41 = V_1 -> V_4 ;
unsigned char V_60 = V_1 -> V_60 ;
unsigned char V_61 = V_1 -> V_61 ;
if ( V_60 == V_62 ) {
if ( V_61 <= V_63 ) {
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_65 [ V_59 ] [ 0 ] , V_65 [ V_59 ] [ 1 ] ) ;
}
} else {
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_67 [ V_59 ] [ 0 ] , V_67 [ V_59 ] [ 1 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_68 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_69 [ V_59 ] [ 0 ] , V_69 [ V_59 ] [ 1 ] ) ;
}
F_16 ( V_41 + V_70 , 0x23 ) ;
F_8 ( V_41 , V_71 , V_72 ) ;
}
V_1 -> V_73 [ 0 ] = 0x18 ;
V_1 -> V_73 [ 1 ] = 0x0A ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 70 ;
V_1 -> V_74 [ 1 ] = - 50 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
} else if ( ( V_60 == V_75 ) || ( V_60 == V_76 ) ) {
for ( V_59 = 0 ; V_59 < V_77 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_78 [ V_59 ] [ 0 ] , V_78 [ V_59 ] [ 1 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_79 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_80 [ V_59 ] [ 0 ] , V_80 [ V_59 ] [ 1 ] ) ;
}
V_1 -> V_73 [ 0 ] = 0x1C ;
V_1 -> V_73 [ 1 ] = 0x10 ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 70 ;
V_1 -> V_74 [ 1 ] = - 48 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
} else if ( V_60 == V_81 ) {
for ( V_59 = 0 ; V_59 < V_82 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_83 [ V_59 ] [ 0 ] , V_83 [ V_59 ] [ 1 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_79 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_80 [ V_59 ] [ 0 ] , V_80 [ V_59 ] [ 1 ] ) ;
}
F_7 ( V_41 + V_70 , 0x23 ) ;
F_8 ( V_41 , V_71 , V_72 ) ;
V_1 -> V_73 [ 0 ] = 0x14 ;
V_1 -> V_73 [ 1 ] = 0x0A ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 60 ;
V_1 -> V_74 [ 1 ] = - 50 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
} else if ( V_60 == V_84 ) {
for ( V_59 = 0 ; V_59 < V_82 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_83 [ V_59 ] [ 0 ] , V_83 [ V_59 ] [ 1 ] ) ;
}
V_58 &= F_12 ( V_41 , 0xd7 , 0x06 ) ;
V_58 &= F_12 ( V_41 , 0x90 , 0x20 ) ;
V_58 &= F_12 ( V_41 , 0x97 , 0xeb ) ;
V_58 &= F_12 ( V_41 , 0xa6 , 0x00 ) ;
V_58 &= F_12 ( V_41 , 0xa8 , 0x30 ) ;
V_58 &= F_12 ( V_41 , 0xb0 , 0x58 ) ;
for ( V_59 = 0 ; V_59 < V_79 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_80 [ V_59 ] [ 0 ] , V_80 [ V_59 ] [ 1 ] ) ;
}
V_1 -> V_73 [ 0 ] = 0x14 ;
V_1 -> V_73 [ 1 ] = 0x0A ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 60 ;
V_1 -> V_74 [ 1 ] = - 50 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
} else if ( V_60 == V_85 ) {
for ( V_59 = 0 ; V_59 < V_77 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_78 [ V_59 ] [ 0 ] , V_78 [ V_59 ] [ 1 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_79 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_80 [ V_59 ] [ 0 ] , V_80 [ V_59 ] [ 1 ] ) ;
}
V_1 -> V_73 [ 0 ] = 0x1C ;
V_1 -> V_73 [ 1 ] = 0x10 ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 70 ;
V_1 -> V_74 [ 1 ] = - 48 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
F_17 ( V_41 ) ;
} else if ( V_60 == V_86 ) {
for ( V_59 = 0 ; V_59 < V_77 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_78 [ V_59 ] [ 0 ] , V_78 [ V_59 ] [ 1 ] ) ;
}
V_58 &= F_12 ( V_41 , 0xd7 , 0x06 ) ;
for ( V_59 = 0 ; V_59 < V_79 ; V_59 ++ ) {
V_58 &= F_12 ( V_41 , V_80 [ V_59 ] [ 0 ] , V_80 [ V_59 ] [ 1 ] ) ;
}
V_1 -> V_73 [ 0 ] = 0x1C ;
V_1 -> V_73 [ 1 ] = 0x10 ;
V_1 -> V_73 [ 2 ] = 0x0 ;
V_1 -> V_73 [ 3 ] = 0x0 ;
V_1 -> V_74 [ 0 ] = - 70 ;
V_1 -> V_74 [ 1 ] = - 48 ;
V_1 -> V_74 [ 2 ] = 0 ;
V_1 -> V_74 [ 3 ] = 0 ;
} else {
V_1 -> V_87 = false ;
V_1 -> V_73 [ 0 ] = 0x1C ;
}
if ( V_61 > V_63 ) {
F_12 ( V_41 , 0x04 , 0x7F ) ;
F_12 ( V_41 , 0x0D , 0x01 ) ;
}
return V_58 ;
}
void F_18 ( unsigned long V_41 , unsigned char * V_88 )
{
int V_59 ;
unsigned char V_89 = 1 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
F_6 ( V_41 , ( unsigned char ) ( V_59 * V_89 ) , V_88 ) ;
V_88 += V_89 ;
}
}
void F_19 ( T_1 V_1 )
{
unsigned char V_54 ;
unsigned long V_41 = V_1 -> V_4 ;
F_6 ( V_41 , 0xC9 , & V_1 -> V_91 ) ;
F_12 ( V_41 , 0xC9 , 0 ) ;
F_6 ( V_41 , 0x4D , & V_1 -> V_92 ) ;
F_12 ( V_41 , 0x4D , 0x90 ) ;
F_6 ( V_41 , 0x88 , & V_1 -> V_93 ) ;
if ( V_1 -> V_94 <= V_32 ) {
F_6 ( V_41 , 0x21 , & V_54 ) ;
F_12 ( V_41 , 0x21 , ( unsigned char ) ( V_54 | 0x01 ) ) ;
F_12 ( V_41 , 0x9A , 0 ) ;
F_12 ( V_41 , 0x88 , 0x02 ) ;
} else {
F_6 ( V_41 , 0x9A , & V_54 ) ;
F_12 ( V_41 , 0x9A , ( unsigned char ) ( V_54 | 0x01 ) ) ;
F_12 ( V_41 , 0x21 , 0 ) ;
F_12 ( V_41 , 0x88 , 0x03 ) ;
}
F_12 ( V_41 , 0x0E , 0 ) ;
F_6 ( V_1 -> V_4 , 0x09 , & V_1 -> V_95 ) ;
F_12 ( V_1 -> V_4 , 0x09 , ( unsigned char ) ( V_1 -> V_95 & 0xDE ) ) ;
}
void F_20 ( T_1 V_1 )
{
unsigned char V_54 ;
unsigned long V_41 = V_1 -> V_4 ;
F_12 ( V_41 , 0xC9 , V_1 -> V_91 ) ;
F_12 ( V_41 , 0x88 , V_1 -> V_93 ) ;
F_12 ( V_41 , 0x09 , V_1 -> V_95 ) ;
F_12 ( V_41 , 0x4D , V_1 -> V_92 ) ;
if ( V_1 -> V_94 <= V_32 ) {
F_6 ( V_41 , 0x21 , & V_54 ) ;
F_12 ( V_41 , 0x21 , ( unsigned char ) ( V_54 & 0xFE ) ) ;
} else {
F_6 ( V_41 , 0x9A , & V_54 ) ;
F_12 ( V_41 , 0x9A , ( unsigned char ) ( V_54 & 0xFE ) ) ;
}
F_6 ( V_41 , 0x0E , & V_54 ) ;
F_12 ( V_41 , 0x0E , ( unsigned char ) ( V_54 | 0x80 ) ) ;
}
void
F_21 ( T_1 V_1 )
{
unsigned char V_96 = 0 ;
unsigned char V_97 = 0 ;
F_6 ( V_1 -> V_4 , 0x0A , & V_96 ) ;
if ( V_1 -> V_98 ) {
V_96 &= 0xDF ;
} else {
V_96 |= 0x20 ;
}
F_6 ( V_1 -> V_4 , 0xE7 , & V_97 ) ;
if ( V_97 == V_1 -> V_73 [ 0 ] ) {
V_96 |= 0x20 ;
}
F_12 ( V_1 -> V_4 , 0x0A , V_96 ) ;
}
void F_22 ( T_1 V_1 , unsigned char V_54 )
{
unsigned char V_96 = 0 ;
F_12 ( V_1 -> V_4 , 0xE7 , V_54 ) ;
F_6 ( V_1 -> V_4 , 0x0A , & V_96 ) ;
if ( V_54 == V_1 -> V_73 [ 0 ] )
V_96 |= 0x20 ;
else if ( V_1 -> V_98 )
V_96 &= 0xDF ;
else
V_96 |= 0x20 ;
V_1 -> V_99 = V_54 ;
F_12 ( V_1 -> V_4 , 0x0A , V_96 ) ;
}
void
F_23 ( unsigned long V_41 )
{
F_12 ( V_41 , 0x50 , 0x40 ) ;
F_12 ( V_41 , 0x50 , 0 ) ;
F_12 ( V_41 , 0x9C , 0x01 ) ;
F_12 ( V_41 , 0x9C , 0 ) ;
}
void
F_24 ( unsigned long V_41 )
{
unsigned char V_57 ;
F_6 ( V_41 , 0x0D , & V_57 ) ;
V_57 |= V_72 ;
F_12 ( V_41 , 0x0D , V_57 ) ;
}
void
F_25 ( unsigned long V_41 )
{
unsigned char V_57 ;
F_6 ( V_41 , 0x0D , & V_57 ) ;
V_57 &= ~ ( V_72 ) ;
F_12 ( V_41 , 0x0D , V_57 ) ;
}
void
F_3 ( unsigned long V_41 , unsigned char V_100 )
{
unsigned char V_101 ;
F_6 ( V_41 , 0x09 , & V_101 ) ;
if ( V_100 == V_102 ) {
V_101 |= 0x02 ;
} else if ( V_100 == V_5 ) {
V_101 &= 0xF9 ;
} else if ( V_100 == V_6 ) {
V_101 &= 0xFD ;
V_101 |= 0x04 ;
}
F_12 ( V_41 , 0x09 , V_101 ) ;
}
void
F_2 ( unsigned long V_41 , unsigned char V_100 )
{
unsigned char V_96 ;
F_6 ( V_41 , 0x0A , & V_96 ) ;
if ( V_100 == V_102 ) {
V_96 |= 0x01 ;
} else if ( V_100 == V_5 ) {
V_96 &= 0xFC ;
} else if ( V_100 == V_6 ) {
V_96 &= 0xFE ;
V_96 |= 0x02 ;
}
F_12 ( V_41 , 0x0A , V_96 ) ;
}
void
F_26 ( unsigned long V_41 , unsigned char V_61 )
{
F_12 ( V_41 , 0x0C , 0x17 ) ;
F_12 ( V_41 , 0x0D , 0xB9 ) ;
}
void
F_27 ( unsigned long V_41 , unsigned char V_61 )
{
F_12 ( V_41 , 0x0C , 0x00 ) ;
F_12 ( V_41 , 0x0D , 0x01 ) ;
}
static
unsigned long
F_28 ( T_1 V_1 )
{
unsigned long V_103 = 0 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_104 = V_1 -> V_106 [ V_17 ] ;
if ( V_1 -> V_106 [ V_17 ] != 0 ) {
V_105 = V_1 -> V_106 [ V_17 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_108 ;
}
if ( V_1 -> V_106 [ V_39 ] > V_104 ) {
V_105 = V_1 -> V_106 [ V_17 ] + V_1 -> V_106 [ V_39 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_109 ;
V_104 = V_1 -> V_106 [ V_39 ] ;
}
if ( V_1 -> V_106 [ V_38 ] > V_104 ) {
V_105 = V_1 -> V_106 [ V_17 ] + V_1 -> V_106 [ V_39 ] +
V_1 -> V_106 [ V_38 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_110 ;
V_104 = V_1 -> V_106 [ V_38 ] ;
}
if ( V_1 -> V_106 [ V_37 ] > V_104 ) {
V_105 = V_1 -> V_106 [ V_17 ] + V_1 -> V_106 [ V_39 ] +
V_1 -> V_106 [ V_38 ] + V_1 -> V_106 [ V_37 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_111 ;
V_104 = V_1 -> V_106 [ V_37 ] ;
}
if ( V_1 -> V_106 [ V_36 ] > V_104 ) {
V_105 = V_1 -> V_106 [ V_17 ] + V_1 -> V_106 [ V_39 ] +
V_1 -> V_106 [ V_38 ] + V_1 -> V_106 [ V_37 ] +
V_1 -> V_106 [ V_36 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_112 ;
V_104 = V_1 -> V_106 [ V_36 ] ;
}
if ( V_1 -> V_106 [ V_35 ] > V_104 ) {
V_105 = V_1 -> V_106 [ V_17 ] + V_1 -> V_106 [ V_39 ] +
V_1 -> V_106 [ V_38 ] + V_1 -> V_106 [ V_37 ] +
V_1 -> V_106 [ V_36 ] + V_1 -> V_106 [ V_35 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_113 ;
V_104 = V_1 -> V_106 [ V_35 ] ;
}
if ( V_1 -> V_106 [ V_32 ] > V_104 ) {
V_105 = V_1 -> V_107 - V_1 -> V_106 [ V_29 ] -
V_1 -> V_106 [ V_30 ] - V_1 -> V_106 [ V_31 ] -
V_1 -> V_106 [ V_33 ] - V_1 -> V_106 [ V_34 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_114 ;
V_104 = V_1 -> V_106 [ V_32 ] ;
}
if ( V_1 -> V_106 [ V_34 ] > V_104 ) {
V_105 = V_1 -> V_107 - V_1 -> V_106 [ V_29 ] -
V_1 -> V_106 [ V_30 ] - V_1 -> V_106 [ V_31 ] -
V_1 -> V_106 [ V_33 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_115 ;
V_104 = V_1 -> V_106 [ V_34 ] ;
}
if ( V_1 -> V_106 [ V_33 ] > V_104 ) {
V_105 = V_1 -> V_107 - V_1 -> V_106 [ V_29 ] -
V_1 -> V_106 [ V_30 ] - V_1 -> V_106 [ V_31 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_116 ;
V_104 = V_1 -> V_106 [ V_33 ] ;
}
if ( V_1 -> V_106 [ V_31 ] > V_104 ) {
V_105 = V_1 -> V_107 - V_1 -> V_106 [ V_29 ] -
V_1 -> V_106 [ V_30 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_117 ;
V_104 = V_1 -> V_106 [ V_31 ] ;
}
if ( V_1 -> V_106 [ V_30 ] > V_104 ) {
V_105 = V_1 -> V_107 - V_1 -> V_106 [ V_29 ] ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_118 ;
V_104 = V_1 -> V_106 [ V_30 ] ;
}
if ( V_1 -> V_106 [ V_29 ] > V_104 ) {
V_105 = V_1 -> V_107 ;
V_103 = ( V_105 * 1000 / V_1 -> V_107 ) ;
V_103 += V_119 ;
}
return V_103 ;
}
void
F_29 ( T_1 V_1 )
{
unsigned int V_59 ;
V_1 -> V_107 = 0 ;
for ( V_59 = 0 ; V_59 < V_120 ; V_59 ++ ) {
V_1 -> V_106 [ V_59 ] = 0 ;
}
}
void
F_30 ( T_1 V_1 , unsigned char V_121 , unsigned char V_122 )
{
if ( ( V_121 >= V_120 ) || ( V_1 -> V_123 >= V_120 ) ) {
return;
}
V_1 -> V_107 ++ ;
V_1 -> V_106 [ V_121 ] ++ ;
if ( V_1 -> V_124 == 0 ) {
if ( V_1 -> V_107 > V_1 -> V_125 ) {
F_11 ( V_52 , V_53 L_3 ,
( int ) V_1 -> V_125 , ( int ) V_1 -> V_106 [ ( int ) V_1 -> V_123 ] ) ;
if ( V_1 -> V_106 [ V_1 -> V_123 ] < V_1 -> V_107 / 2 ) {
V_1 -> V_126 = F_28 ( V_1 ) ;
F_11 ( V_52 , V_53 L_4 , ( int ) V_1 -> V_126 ) ;
if ( V_1 -> V_127 == 0 )
return;
F_11 ( V_52 , V_53 L_5 ,
( int ) V_1 -> V_126 , ( int ) V_1 -> V_123 ,
( int ) V_1 -> V_106 [ ( int ) V_1 -> V_123 ] , ( int ) V_1 -> V_107 ) ;
F_1 ( V_1 ) ;
V_1 -> V_124 = 1 ;
F_31 ( & V_1 -> V_128 ) ;
F_31 ( & V_1 -> V_129 ) ;
V_1 -> V_130 . V_131 = F_32 ( V_1 -> V_127 * V_132 ) ;
F_33 ( & V_1 -> V_130 ) ;
} else {
V_1 -> V_128 . V_131 = F_32 ( V_1 -> V_133 * V_132 ) ;
F_33 ( & V_1 -> V_128 ) ;
}
F_29 ( V_1 ) ;
}
} else {
if ( V_1 -> V_107 > V_1 -> V_134 ) {
F_31 ( & V_1 -> V_130 ) ;
V_1 -> V_135 = F_28 ( V_1 ) ;
F_11 ( V_52 , V_53 L_6 ,
( int ) V_1 -> V_126 , ( int ) V_1 -> V_135 ) ;
if ( V_1 -> V_135 < V_1 -> V_126 ) {
F_11 ( V_52 , V_53 L_7 ,
( int ) V_1 -> V_126 , ( int ) V_1 -> V_135 ,
( int ) V_1 -> V_123 ,
( int ) V_1 -> V_106 [ ( int ) V_1 -> V_123 ] , ( int ) V_1 -> V_107 ) ;
F_1 ( V_1 ) ;
V_1 -> V_128 . V_131 = F_32 ( V_1 -> V_133 * V_132 ) ;
V_1 -> V_129 . V_131 = F_32 ( V_1 -> V_136 * V_132 ) ;
F_33 ( & V_1 -> V_128 ) ;
F_33 ( & V_1 -> V_129 ) ;
}
V_1 -> V_124 = 0 ;
F_29 ( V_1 ) ;
}
}
}
void
F_34 (
void * V_137
)
{
T_1 V_1 = ( T_1 ) V_137 ;
F_11 ( V_52 , V_53 L_8 ) ;
F_35 ( & V_1 -> V_138 ) ;
F_11 ( V_52 , V_53 L_9 , ( int ) V_1 -> V_126 , ( int ) V_1 -> V_135 , ( int ) V_1 -> V_107 ) ;
F_1 ( V_1 ) ;
V_1 -> V_124 = 0 ;
F_29 ( V_1 ) ;
V_1 -> V_128 . V_131 = F_32 ( V_1 -> V_133 * V_132 ) ;
V_1 -> V_129 . V_131 = F_32 ( V_1 -> V_136 * V_132 ) ;
F_33 ( & V_1 -> V_128 ) ;
F_33 ( & V_1 -> V_129 ) ;
F_36 ( & V_1 -> V_138 ) ;
return;
}
void
F_37 (
void * V_137
)
{
T_1 V_1 = ( T_1 ) V_137 ;
F_11 ( V_52 , V_53 L_10 ) ;
F_35 ( & V_1 -> V_138 ) ;
if ( V_1 -> V_107 < V_1 -> V_134 / 100 ) {
F_1 ( V_1 ) ;
V_1 -> V_128 . V_131 = F_32 ( V_1 -> V_133 * V_132 ) ;
V_1 -> V_129 . V_131 = F_32 ( V_1 -> V_136 * V_132 ) ;
F_33 ( & V_1 -> V_128 ) ;
F_33 ( & V_1 -> V_129 ) ;
} else {
V_1 -> V_135 = F_28 ( V_1 ) ;
F_11 ( V_52 , V_53 L_11 ,
( int ) V_1 -> V_126 , ( int ) V_1 -> V_135 ) ;
if ( V_1 -> V_135 < V_1 -> V_126 ) {
F_11 ( V_52 , V_53 L_7 ,
( int ) V_1 -> V_126 , ( int ) V_1 -> V_135 ,
( int ) V_1 -> V_123 ,
( int ) V_1 -> V_106 [ ( int ) V_1 -> V_123 ] , ( int ) V_1 -> V_107 ) ;
F_1 ( V_1 ) ;
V_1 -> V_128 . V_131 = F_32 ( V_1 -> V_133 * V_132 ) ;
V_1 -> V_129 . V_131 = F_32 ( V_1 -> V_136 * V_132 ) ;
F_33 ( & V_1 -> V_128 ) ;
F_33 ( & V_1 -> V_129 ) ;
}
}
V_1 -> V_124 = 0 ;
F_29 ( V_1 ) ;
F_36 ( & V_1 -> V_138 ) ;
return;
}
