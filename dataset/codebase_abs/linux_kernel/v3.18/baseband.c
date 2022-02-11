static
void
F_1 (
struct V_1 * V_2
)
{
if ( V_2 -> V_3 == 0 ) {
V_2 -> V_3 = 1 ;
if ( V_2 -> V_4 == true )
F_2 ( V_2 -> V_5 , V_6 ) ;
else
F_2 ( V_2 -> V_5 , V_7 ) ;
} else {
V_2 -> V_3 = 0 ;
if ( V_2 -> V_4 == true )
F_2 ( V_2 -> V_5 , V_7 ) ;
else
F_2 ( V_2 -> V_5 , V_6 ) ;
}
if ( V_2 -> V_8 == 0 ) {
V_2 -> V_8 = 1 ;
F_3 ( V_2 -> V_5 , V_7 ) ;
} else {
V_2 -> V_8 = 0 ;
F_3 ( V_2 -> V_5 , V_6 ) ;
}
}
unsigned int
F_4 (
unsigned char V_9 ,
unsigned char V_10 ,
unsigned int V_11 ,
unsigned short V_12
)
{
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 = ( unsigned int ) V_12 ;
unsigned int V_17 = 0 ;
if ( V_16 > V_18 ) {
ASSERT ( 0 ) ;
return 0 ;
}
V_17 = ( unsigned int ) V_19 [ V_16 ] ;
if ( V_16 <= 3 ) {
if ( V_9 == 1 )
V_14 = 96 ;
else
V_14 = 192 ;
V_13 = ( V_11 * 80 ) / V_17 ;
V_15 = ( V_13 * V_17 ) / 80 ;
if ( V_11 != V_15 )
V_13 ++ ;
return V_14 + V_13 ;
} else {
V_13 = ( V_11 * 8 + 22 ) / V_17 ;
V_15 = ( ( V_13 * V_17 ) - 22 ) / 8 ;
if ( V_11 != V_15 )
V_13 ++ ;
V_13 = V_13 * 4 ;
if ( V_10 != V_20 )
V_13 += 6 ;
return 20 + V_13 ;
}
}
void F_5 ( struct V_1 * V_21 , T_1 V_22 ,
T_2 V_23 , T_3 V_24 , struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_28 = 0 ;
T_1 V_29 ;
int V_30 ;
T_3 V_31 = V_21 -> V_9 ;
V_27 = V_22 * 8 ;
V_30 = false ;
switch ( V_23 ) {
case V_32 :
V_28 = V_27 ;
V_26 -> signal = 0x00 ;
break;
case V_33 :
V_28 = V_27 / 2 ;
if ( V_31 == 1 )
V_26 -> signal = 0x09 ;
else
V_26 -> signal = 0x01 ;
break;
case V_34 :
V_28 = ( V_27 * 10 ) / 55 ;
V_29 = ( V_28 * 55 ) / 10 ;
if ( V_29 != V_27 )
V_28 ++ ;
if ( V_31 == 1 )
V_26 -> signal = 0x0a ;
else
V_26 -> signal = 0x02 ;
break;
case V_35 :
V_28 = V_27 / 11 ;
V_29 = V_28 * 11 ;
if ( V_29 != V_27 ) {
V_28 ++ ;
if ( ( V_27 - V_29 ) <= 3 )
V_30 = true ;
}
if ( V_31 == 1 )
V_26 -> signal = 0x0b ;
else
V_26 -> signal = 0x03 ;
break;
case V_36 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9b ;
else
V_26 -> signal = 0x8b ;
break;
case V_37 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9f ;
else
V_26 -> signal = 0x8f ;
break;
case V_38 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9a ;
else
V_26 -> signal = 0x8a ;
break;
case V_39 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9e ;
else
V_26 -> signal = 0x8e ;
break;
case V_40 :
if ( V_24 == V_20 )
V_26 -> signal = 0x99 ;
else
V_26 -> signal = 0x89 ;
break;
case V_41 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9d ;
else
V_26 -> signal = 0x8d ;
break;
case V_42 :
if ( V_24 == V_20 )
V_26 -> signal = 0x98 ;
else
V_26 -> signal = 0x88 ;
break;
case V_18 :
if ( V_24 == V_20 )
V_26 -> signal = 0x9c ;
else
V_26 -> signal = 0x8c ;
break;
default:
if ( V_24 == V_20 )
V_26 -> signal = 0x9c ;
else
V_26 -> signal = 0x8c ;
break;
}
if ( V_24 == V_43 ) {
V_26 -> V_44 = 0x00 ;
if ( V_30 )
V_26 -> V_44 |= 0x80 ;
V_26 -> V_45 = F_6 ( ( T_2 ) V_28 ) ;
} else {
V_26 -> V_44 = 0x00 ;
V_26 -> V_45 = F_6 ( ( T_2 ) V_22 ) ;
}
}
bool F_7 ( void T_4 * V_46 , unsigned char V_47 , unsigned char * V_48 )
{
unsigned short V_49 ;
unsigned char V_50 ;
F_8 ( V_46 + V_51 , V_47 ) ;
F_9 ( V_46 , V_52 , V_53 ) ;
for ( V_49 = 0 ; V_49 < V_54 ; V_49 ++ ) {
F_10 ( V_46 + V_52 , & V_50 ) ;
if ( V_50 & V_55 )
break;
}
F_10 ( V_46 + V_56 , V_48 ) ;
if ( V_49 == V_54 ) {
F_11 ( 0x30 ) ;
F_12 ( L_1 ) ;
return false ;
}
return true ;
}
bool F_13 ( void T_4 * V_46 , unsigned char V_47 , unsigned char V_57 )
{
unsigned short V_49 ;
unsigned char V_50 ;
F_8 ( V_46 + V_51 , V_47 ) ;
F_8 ( V_46 + V_56 , V_57 ) ;
F_9 ( V_46 , V_52 , V_58 ) ;
for ( V_49 = 0 ; V_49 < V_54 ; V_49 ++ ) {
F_10 ( V_46 + V_52 , & V_50 ) ;
if ( V_50 & V_55 )
break;
}
if ( V_49 == V_54 ) {
F_11 ( 0x31 ) ;
F_12 ( L_2 ) ;
return false ;
}
return true ;
}
bool F_14 ( void T_4 * V_46 , unsigned char V_47 , unsigned char V_59 )
{
unsigned char V_60 ;
F_7 ( V_46 , V_47 , & V_60 ) ;
return ( V_60 & V_59 ) == V_59 ;
}
bool F_15 ( void T_4 * V_46 , unsigned char V_47 , unsigned char V_59 )
{
unsigned char V_60 ;
F_7 ( V_46 , V_47 , & V_60 ) ;
return ( V_60 & V_59 ) == 0 ;
}
bool F_16 ( struct V_1 * V_2 )
{
bool V_61 = true ;
int V_62 ;
void T_4 * V_46 = V_2 -> V_5 ;
unsigned char V_63 = V_2 -> V_63 ;
unsigned char V_64 = V_2 -> V_64 ;
if ( V_63 == V_65 ) {
if ( V_64 <= V_66 ) {
for ( V_62 = 0 ; V_62 < V_67 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_68 [ V_62 ] [ 0 ] , V_68 [ V_62 ] [ 1 ] ) ;
} else {
for ( V_62 = 0 ; V_62 < V_69 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_70 [ V_62 ] [ 0 ] , V_70 [ V_62 ] [ 1 ] ) ;
for ( V_62 = 0 ; V_62 < V_71 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_72 [ V_62 ] [ 0 ] , V_72 [ V_62 ] [ 1 ] ) ;
F_17 ( V_46 + V_73 , 0x23 ) ;
F_9 ( V_46 , V_74 , V_75 ) ;
}
V_2 -> V_76 [ 0 ] = 0x18 ;
V_2 -> V_76 [ 1 ] = 0x0A ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 70 ;
V_2 -> V_77 [ 1 ] = - 50 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
} else if ( ( V_63 == V_78 ) || ( V_63 == V_79 ) ) {
for ( V_62 = 0 ; V_62 < V_80 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_81 [ V_62 ] [ 0 ] , V_81 [ V_62 ] [ 1 ] ) ;
for ( V_62 = 0 ; V_62 < V_82 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_83 [ V_62 ] [ 0 ] , V_83 [ V_62 ] [ 1 ] ) ;
V_2 -> V_76 [ 0 ] = 0x1C ;
V_2 -> V_76 [ 1 ] = 0x10 ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 70 ;
V_2 -> V_77 [ 1 ] = - 48 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
} else if ( V_63 == V_84 ) {
for ( V_62 = 0 ; V_62 < V_85 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_86 [ V_62 ] [ 0 ] , V_86 [ V_62 ] [ 1 ] ) ;
for ( V_62 = 0 ; V_62 < V_82 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_83 [ V_62 ] [ 0 ] , V_83 [ V_62 ] [ 1 ] ) ;
F_8 ( V_46 + V_73 , 0x23 ) ;
F_9 ( V_46 , V_74 , V_75 ) ;
V_2 -> V_76 [ 0 ] = 0x14 ;
V_2 -> V_76 [ 1 ] = 0x0A ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 60 ;
V_2 -> V_77 [ 1 ] = - 50 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
} else if ( V_63 == V_87 ) {
for ( V_62 = 0 ; V_62 < V_85 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_86 [ V_62 ] [ 0 ] , V_86 [ V_62 ] [ 1 ] ) ;
V_61 &= F_13 ( V_46 , 0xd7 , 0x06 ) ;
V_61 &= F_13 ( V_46 , 0x90 , 0x20 ) ;
V_61 &= F_13 ( V_46 , 0x97 , 0xeb ) ;
V_61 &= F_13 ( V_46 , 0xa6 , 0x00 ) ;
V_61 &= F_13 ( V_46 , 0xa8 , 0x30 ) ;
V_61 &= F_13 ( V_46 , 0xb0 , 0x58 ) ;
for ( V_62 = 0 ; V_62 < V_82 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_83 [ V_62 ] [ 0 ] , V_83 [ V_62 ] [ 1 ] ) ;
V_2 -> V_76 [ 0 ] = 0x14 ;
V_2 -> V_76 [ 1 ] = 0x0A ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 60 ;
V_2 -> V_77 [ 1 ] = - 50 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
} else if ( V_63 == V_88 ) {
for ( V_62 = 0 ; V_62 < V_80 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_81 [ V_62 ] [ 0 ] , V_81 [ V_62 ] [ 1 ] ) ;
for ( V_62 = 0 ; V_62 < V_82 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_83 [ V_62 ] [ 0 ] , V_83 [ V_62 ] [ 1 ] ) ;
V_2 -> V_76 [ 0 ] = 0x1C ;
V_2 -> V_76 [ 1 ] = 0x10 ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 70 ;
V_2 -> V_77 [ 1 ] = - 48 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
F_18 ( V_46 ) ;
} else if ( V_63 == V_89 ) {
for ( V_62 = 0 ; V_62 < V_80 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_81 [ V_62 ] [ 0 ] , V_81 [ V_62 ] [ 1 ] ) ;
V_61 &= F_13 ( V_46 , 0xd7 , 0x06 ) ;
for ( V_62 = 0 ; V_62 < V_82 ; V_62 ++ )
V_61 &= F_13 ( V_46 , V_83 [ V_62 ] [ 0 ] , V_83 [ V_62 ] [ 1 ] ) ;
V_2 -> V_76 [ 0 ] = 0x1C ;
V_2 -> V_76 [ 1 ] = 0x10 ;
V_2 -> V_76 [ 2 ] = 0x0 ;
V_2 -> V_76 [ 3 ] = 0x0 ;
V_2 -> V_77 [ 0 ] = - 70 ;
V_2 -> V_77 [ 1 ] = - 48 ;
V_2 -> V_77 [ 2 ] = 0 ;
V_2 -> V_77 [ 3 ] = 0 ;
} else {
V_2 -> V_90 = false ;
V_2 -> V_76 [ 0 ] = 0x1C ;
}
if ( V_64 > V_66 ) {
F_13 ( V_46 , 0x04 , 0x7F ) ;
F_13 ( V_46 , 0x0D , 0x01 ) ;
}
return V_61 ;
}
void F_19 ( void T_4 * V_46 , unsigned char * V_91 )
{
int V_62 ;
unsigned char V_92 = 1 ;
for ( V_62 = 0 ; V_62 < V_93 ; V_62 ++ ) {
F_7 ( V_46 , ( unsigned char ) ( V_62 * V_92 ) , V_91 ) ;
V_91 += V_92 ;
}
}
void F_20 ( struct V_1 * V_2 )
{
unsigned char V_57 ;
void T_4 * V_46 = V_2 -> V_5 ;
F_7 ( V_46 , 0xC9 , & V_2 -> V_94 ) ;
F_13 ( V_46 , 0xC9 , 0 ) ;
F_7 ( V_46 , 0x4D , & V_2 -> V_95 ) ;
F_13 ( V_46 , 0x4D , 0x90 ) ;
F_7 ( V_46 , 0x88 , & V_2 -> V_96 ) ;
if ( V_2 -> V_97 <= V_35 ) {
F_7 ( V_46 , 0x21 , & V_57 ) ;
F_13 ( V_46 , 0x21 , ( unsigned char ) ( V_57 | 0x01 ) ) ;
F_13 ( V_46 , 0x9A , 0 ) ;
F_13 ( V_46 , 0x88 , 0x02 ) ;
} else {
F_7 ( V_46 , 0x9A , & V_57 ) ;
F_13 ( V_46 , 0x9A , ( unsigned char ) ( V_57 | 0x01 ) ) ;
F_13 ( V_46 , 0x21 , 0 ) ;
F_13 ( V_46 , 0x88 , 0x03 ) ;
}
F_13 ( V_46 , 0x0E , 0 ) ;
F_7 ( V_2 -> V_5 , 0x09 , & V_2 -> V_98 ) ;
F_13 ( V_2 -> V_5 , 0x09 , ( unsigned char ) ( V_2 -> V_98 & 0xDE ) ) ;
}
void F_21 ( struct V_1 * V_2 )
{
unsigned char V_57 ;
void T_4 * V_46 = V_2 -> V_5 ;
F_13 ( V_46 , 0xC9 , V_2 -> V_94 ) ;
F_13 ( V_46 , 0x88 , V_2 -> V_96 ) ;
F_13 ( V_46 , 0x09 , V_2 -> V_98 ) ;
F_13 ( V_46 , 0x4D , V_2 -> V_95 ) ;
if ( V_2 -> V_97 <= V_35 ) {
F_7 ( V_46 , 0x21 , & V_57 ) ;
F_13 ( V_46 , 0x21 , ( unsigned char ) ( V_57 & 0xFE ) ) ;
} else {
F_7 ( V_46 , 0x9A , & V_57 ) ;
F_13 ( V_46 , 0x9A , ( unsigned char ) ( V_57 & 0xFE ) ) ;
}
F_7 ( V_46 , 0x0E , & V_57 ) ;
F_13 ( V_46 , 0x0E , ( unsigned char ) ( V_57 | 0x80 ) ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
unsigned char V_99 = 0 ;
unsigned char V_100 = 0 ;
F_7 ( V_2 -> V_5 , 0x0A , & V_99 ) ;
if ( V_2 -> V_101 )
V_99 &= 0xDF ;
else
V_99 |= 0x20 ;
F_7 ( V_2 -> V_5 , 0xE7 , & V_100 ) ;
if ( V_100 == V_2 -> V_76 [ 0 ] )
V_99 |= 0x20 ;
F_13 ( V_2 -> V_5 , 0x0A , V_99 ) ;
}
void F_23 ( struct V_1 * V_2 , unsigned char V_57 )
{
unsigned char V_99 = 0 ;
F_13 ( V_2 -> V_5 , 0xE7 , V_57 ) ;
F_7 ( V_2 -> V_5 , 0x0A , & V_99 ) ;
if ( V_57 == V_2 -> V_76 [ 0 ] )
V_99 |= 0x20 ;
else if ( V_2 -> V_101 )
V_99 &= 0xDF ;
else
V_99 |= 0x20 ;
V_2 -> V_102 = V_57 ;
F_13 ( V_2 -> V_5 , 0x0A , V_99 ) ;
}
void
F_24 ( void T_4 * V_46 )
{
F_13 ( V_46 , 0x50 , 0x40 ) ;
F_13 ( V_46 , 0x50 , 0 ) ;
F_13 ( V_46 , 0x9C , 0x01 ) ;
F_13 ( V_46 , 0x9C , 0 ) ;
}
void
F_25 ( void T_4 * V_46 )
{
unsigned char V_60 ;
F_7 ( V_46 , 0x0D , & V_60 ) ;
V_60 |= V_75 ;
F_13 ( V_46 , 0x0D , V_60 ) ;
}
void
F_26 ( void T_4 * V_46 )
{
unsigned char V_60 ;
F_7 ( V_46 , 0x0D , & V_60 ) ;
V_60 &= ~ ( V_75 ) ;
F_13 ( V_46 , 0x0D , V_60 ) ;
}
void
F_3 ( void T_4 * V_46 , unsigned char V_103 )
{
unsigned char V_104 ;
F_7 ( V_46 , 0x09 , & V_104 ) ;
if ( V_103 == V_105 ) {
V_104 |= 0x02 ;
} else if ( V_103 == V_6 ) {
V_104 &= 0xF9 ;
} else if ( V_103 == V_7 ) {
V_104 &= 0xFD ;
V_104 |= 0x04 ;
}
F_13 ( V_46 , 0x09 , V_104 ) ;
}
void
F_2 ( void T_4 * V_46 , unsigned char V_103 )
{
unsigned char V_99 ;
F_7 ( V_46 , 0x0A , & V_99 ) ;
if ( V_103 == V_105 ) {
V_99 |= 0x01 ;
} else if ( V_103 == V_6 ) {
V_99 &= 0xFC ;
} else if ( V_103 == V_7 ) {
V_99 &= 0xFE ;
V_99 |= 0x02 ;
}
F_13 ( V_46 , 0x0A , V_99 ) ;
}
void
F_27 ( void T_4 * V_46 , unsigned char V_64 )
{
F_13 ( V_46 , 0x0C , 0x17 ) ;
F_13 ( V_46 , 0x0D , 0xB9 ) ;
}
void
F_28 ( void T_4 * V_46 , unsigned char V_64 )
{
F_13 ( V_46 , 0x0C , 0x00 ) ;
F_13 ( V_46 , 0x0D , 0x01 ) ;
}
static
unsigned long
F_29 ( struct V_1 * V_2 )
{
unsigned long V_106 = 0 ;
unsigned long V_107 ;
unsigned long V_108 ;
V_107 = V_2 -> V_109 [ V_18 ] ;
if ( V_2 -> V_109 [ V_18 ] != 0 ) {
V_108 = V_2 -> V_109 [ V_18 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_111 ;
}
if ( V_2 -> V_109 [ V_42 ] > V_107 ) {
V_108 = V_2 -> V_109 [ V_18 ] + V_2 -> V_109 [ V_42 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_112 ;
V_107 = V_2 -> V_109 [ V_42 ] ;
}
if ( V_2 -> V_109 [ V_41 ] > V_107 ) {
V_108 = V_2 -> V_109 [ V_18 ] + V_2 -> V_109 [ V_42 ] +
V_2 -> V_109 [ V_41 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_113 ;
V_107 = V_2 -> V_109 [ V_41 ] ;
}
if ( V_2 -> V_109 [ V_40 ] > V_107 ) {
V_108 = V_2 -> V_109 [ V_18 ] + V_2 -> V_109 [ V_42 ] +
V_2 -> V_109 [ V_41 ] + V_2 -> V_109 [ V_40 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_114 ;
V_107 = V_2 -> V_109 [ V_40 ] ;
}
if ( V_2 -> V_109 [ V_39 ] > V_107 ) {
V_108 = V_2 -> V_109 [ V_18 ] + V_2 -> V_109 [ V_42 ] +
V_2 -> V_109 [ V_41 ] + V_2 -> V_109 [ V_40 ] +
V_2 -> V_109 [ V_39 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_115 ;
V_107 = V_2 -> V_109 [ V_39 ] ;
}
if ( V_2 -> V_109 [ V_38 ] > V_107 ) {
V_108 = V_2 -> V_109 [ V_18 ] + V_2 -> V_109 [ V_42 ] +
V_2 -> V_109 [ V_41 ] + V_2 -> V_109 [ V_40 ] +
V_2 -> V_109 [ V_39 ] + V_2 -> V_109 [ V_38 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_116 ;
V_107 = V_2 -> V_109 [ V_38 ] ;
}
if ( V_2 -> V_109 [ V_35 ] > V_107 ) {
V_108 = V_2 -> V_110 - V_2 -> V_109 [ V_32 ] -
V_2 -> V_109 [ V_33 ] - V_2 -> V_109 [ V_34 ] -
V_2 -> V_109 [ V_36 ] - V_2 -> V_109 [ V_37 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_117 ;
V_107 = V_2 -> V_109 [ V_35 ] ;
}
if ( V_2 -> V_109 [ V_37 ] > V_107 ) {
V_108 = V_2 -> V_110 - V_2 -> V_109 [ V_32 ] -
V_2 -> V_109 [ V_33 ] - V_2 -> V_109 [ V_34 ] -
V_2 -> V_109 [ V_36 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_118 ;
V_107 = V_2 -> V_109 [ V_37 ] ;
}
if ( V_2 -> V_109 [ V_36 ] > V_107 ) {
V_108 = V_2 -> V_110 - V_2 -> V_109 [ V_32 ] -
V_2 -> V_109 [ V_33 ] - V_2 -> V_109 [ V_34 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_119 ;
V_107 = V_2 -> V_109 [ V_36 ] ;
}
if ( V_2 -> V_109 [ V_34 ] > V_107 ) {
V_108 = V_2 -> V_110 - V_2 -> V_109 [ V_32 ] -
V_2 -> V_109 [ V_33 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_120 ;
V_107 = V_2 -> V_109 [ V_34 ] ;
}
if ( V_2 -> V_109 [ V_33 ] > V_107 ) {
V_108 = V_2 -> V_110 - V_2 -> V_109 [ V_32 ] ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_121 ;
V_107 = V_2 -> V_109 [ V_33 ] ;
}
if ( V_2 -> V_109 [ V_32 ] > V_107 ) {
V_108 = V_2 -> V_110 ;
V_106 = ( V_108 * 1000 / V_2 -> V_110 ) ;
V_106 += V_122 ;
}
return V_106 ;
}
void
F_30 ( struct V_1 * V_2 )
{
unsigned int V_62 ;
V_2 -> V_110 = 0 ;
for ( V_62 = 0 ; V_62 < V_123 ; V_62 ++ )
V_2 -> V_109 [ V_62 ] = 0 ;
}
void F_31 ( struct V_1 * V_2 ,
unsigned char V_124 , unsigned char V_125 )
{
if ( ( V_124 >= V_123 ) || ( V_2 -> V_126 >= V_123 ) )
return;
V_2 -> V_110 ++ ;
V_2 -> V_109 [ V_124 ] ++ ;
if ( V_2 -> V_127 == 0 ) {
if ( V_2 -> V_110 > V_2 -> V_128 ) {
F_12 ( L_3 ,
( int ) V_2 -> V_128 ,
( int ) V_2 -> V_109 [ ( int ) V_2 -> V_126 ] ) ;
if ( V_2 -> V_109 [ V_2 -> V_126 ] < V_2 -> V_110 / 2 ) {
V_2 -> V_129 = F_29 ( V_2 ) ;
F_12 ( L_4 ,
( int ) V_2 -> V_129 ) ;
if ( V_2 -> V_130 == 0 )
return;
F_12 ( L_5 ,
( int ) V_2 -> V_129 ,
( int ) V_2 -> V_126 ,
( int ) V_2 -> V_109 [ ( int ) V_2 -> V_126 ] ,
( int ) V_2 -> V_110 ) ;
F_1 ( V_2 ) ;
V_2 -> V_127 = 1 ;
F_32 ( & V_2 -> V_131 ) ;
F_32 ( & V_2 -> V_132 ) ;
V_2 -> V_133 . V_134 = F_33 ( V_2 -> V_130 * V_135 ) ;
F_34 ( & V_2 -> V_133 ) ;
} else {
V_2 -> V_131 . V_134 = F_33 ( V_2 -> V_136 * V_135 ) ;
F_34 ( & V_2 -> V_131 ) ;
}
F_30 ( V_2 ) ;
}
} else {
if ( V_2 -> V_110 > V_2 -> V_137 ) {
F_32 ( & V_2 -> V_133 ) ;
V_2 -> V_138 = F_29 ( V_2 ) ;
F_12 ( L_6 ,
( int ) V_2 -> V_129 ,
( int ) V_2 -> V_138 ) ;
if ( V_2 -> V_138 < V_2 -> V_129 ) {
F_12 ( L_7 ,
( int ) V_2 -> V_129 ,
( int ) V_2 -> V_138 ,
( int ) V_2 -> V_126 ,
( int ) V_2 -> V_109 [ ( int ) V_2 -> V_126 ] ,
( int ) V_2 -> V_110 ) ;
F_1 ( V_2 ) ;
V_2 -> V_131 . V_134 = F_33 ( V_2 -> V_136 * V_135 ) ;
V_2 -> V_132 . V_134 = F_33 ( V_2 -> V_139 * V_135 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_34 ( & V_2 -> V_132 ) ;
}
V_2 -> V_127 = 0 ;
F_30 ( V_2 ) ;
}
}
}
void
F_35 (
void * V_140
)
{
struct V_1 * V_2 = V_140 ;
F_12 ( L_8 ) ;
F_36 ( & V_2 -> V_141 ) ;
F_12 ( L_9 ,
( int ) V_2 -> V_129 , ( int ) V_2 -> V_138 ,
( int ) V_2 -> V_110 ) ;
F_1 ( V_2 ) ;
V_2 -> V_127 = 0 ;
F_30 ( V_2 ) ;
V_2 -> V_131 . V_134 = F_33 ( V_2 -> V_136 * V_135 ) ;
V_2 -> V_132 . V_134 = F_33 ( V_2 -> V_139 * V_135 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_34 ( & V_2 -> V_132 ) ;
F_37 ( & V_2 -> V_141 ) ;
}
void
F_38 (
void * V_140
)
{
struct V_1 * V_2 = V_140 ;
F_12 ( L_10 ) ;
F_36 ( & V_2 -> V_141 ) ;
if ( V_2 -> V_110 < V_2 -> V_137 / 100 ) {
F_1 ( V_2 ) ;
V_2 -> V_131 . V_134 = F_33 ( V_2 -> V_136 * V_135 ) ;
V_2 -> V_132 . V_134 = F_33 ( V_2 -> V_139 * V_135 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_34 ( & V_2 -> V_132 ) ;
} else {
V_2 -> V_138 = F_29 ( V_2 ) ;
F_12 ( L_11 ,
( int ) V_2 -> V_129 ,
( int ) V_2 -> V_138 ) ;
if ( V_2 -> V_138 < V_2 -> V_129 ) {
F_12 ( L_7 ,
( int ) V_2 -> V_129 ,
( int ) V_2 -> V_138 ,
( int ) V_2 -> V_126 ,
( int ) V_2 -> V_109 [ ( int ) V_2 -> V_126 ] ,
( int ) V_2 -> V_110 ) ;
F_1 ( V_2 ) ;
V_2 -> V_131 . V_134 = F_33 ( V_2 -> V_136 * V_135 ) ;
V_2 -> V_132 . V_134 = F_33 ( V_2 -> V_139 * V_135 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_34 ( & V_2 -> V_132 ) ;
}
}
V_2 -> V_127 = 0 ;
F_30 ( V_2 ) ;
F_37 ( & V_2 -> V_141 ) ;
}
