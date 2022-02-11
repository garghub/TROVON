static
void
F_1 (
struct V_1 * V_2
)
{
if ( V_2 -> V_3 == 0 ) {
V_2 -> V_3 = 1 ;
if ( V_2 -> V_4 == true )
F_2 ( V_2 , V_5 ) ;
else
F_2 ( V_2 , V_6 ) ;
} else {
V_2 -> V_3 = 0 ;
if ( V_2 -> V_4 == true )
F_2 ( V_2 , V_6 ) ;
else
F_2 ( V_2 , V_5 ) ;
}
if ( V_2 -> V_7 == 0 ) {
V_2 -> V_7 = 1 ;
F_3 ( V_2 , V_6 ) ;
} else {
V_2 -> V_7 = 0 ;
F_3 ( V_2 , V_5 ) ;
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
if ( V_8 == 1 )
V_13 = 96 ;
else
V_13 = 192 ;
V_12 = ( V_10 * 80 ) / V_16 ;
V_14 = ( V_12 * V_16 ) / 80 ;
if ( V_10 != V_14 )
V_12 ++ ;
return V_13 + V_12 ;
}
V_12 = ( V_10 * 8 + 22 ) / V_16 ;
V_14 = ( ( V_12 * V_16 ) - 22 ) / 8 ;
if ( V_10 != V_14 )
V_12 ++ ;
V_12 = V_12 * 4 ;
if ( V_9 != V_19 )
V_12 += 6 ;
return 20 + V_12 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_20 ,
T_2 V_21 , T_3 V_22 , struct V_23 * V_24 )
{
T_1 V_25 ;
T_1 V_26 = 0 ;
T_1 V_27 ;
int V_28 ;
T_3 V_29 = V_2 -> V_8 ;
V_25 = V_20 * 8 ;
V_28 = false ;
switch ( V_21 ) {
case V_30 :
V_26 = V_25 ;
V_24 -> signal = 0x00 ;
break;
case V_31 :
V_26 = V_25 / 2 ;
if ( V_29 == 1 )
V_24 -> signal = 0x09 ;
else
V_24 -> signal = 0x01 ;
break;
case V_32 :
V_26 = ( V_25 * 10 ) / 55 ;
V_27 = ( V_26 * 55 ) / 10 ;
if ( V_27 != V_25 )
V_26 ++ ;
if ( V_29 == 1 )
V_24 -> signal = 0x0a ;
else
V_24 -> signal = 0x02 ;
break;
case V_33 :
V_26 = V_25 / 11 ;
V_27 = V_26 * 11 ;
if ( V_27 != V_25 ) {
V_26 ++ ;
if ( ( V_25 - V_27 ) <= 3 )
V_28 = true ;
}
if ( V_29 == 1 )
V_24 -> signal = 0x0b ;
else
V_24 -> signal = 0x03 ;
break;
case V_34 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9b ;
else
V_24 -> signal = 0x8b ;
break;
case V_35 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9f ;
else
V_24 -> signal = 0x8f ;
break;
case V_36 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9a ;
else
V_24 -> signal = 0x8a ;
break;
case V_37 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9e ;
else
V_24 -> signal = 0x8e ;
break;
case V_38 :
if ( V_22 == V_19 )
V_24 -> signal = 0x99 ;
else
V_24 -> signal = 0x89 ;
break;
case V_39 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9d ;
else
V_24 -> signal = 0x8d ;
break;
case V_40 :
if ( V_22 == V_19 )
V_24 -> signal = 0x98 ;
else
V_24 -> signal = 0x88 ;
break;
case V_17 :
if ( V_22 == V_19 )
V_24 -> signal = 0x9c ;
else
V_24 -> signal = 0x8c ;
break;
default:
if ( V_22 == V_19 )
V_24 -> signal = 0x9c ;
else
V_24 -> signal = 0x8c ;
break;
}
if ( V_22 == V_41 ) {
V_24 -> V_42 = 0x00 ;
if ( V_28 )
V_24 -> V_42 |= 0x80 ;
V_24 -> V_43 = F_6 ( ( T_2 ) V_26 ) ;
} else {
V_24 -> V_42 = 0x00 ;
V_24 -> V_43 = F_6 ( ( T_2 ) V_20 ) ;
}
}
bool F_7 ( struct V_1 * V_2 ,
unsigned char V_44 , unsigned char * V_45 )
{
void T_4 * V_46 = V_2 -> V_47 ;
unsigned short V_48 ;
unsigned char V_49 ;
F_8 ( V_46 + V_50 , V_44 ) ;
F_9 ( V_46 , V_51 , V_52 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
F_10 ( V_46 + V_51 , & V_49 ) ;
if ( V_49 & V_54 )
break;
}
F_10 ( V_46 + V_55 , V_45 ) ;
if ( V_48 == V_53 ) {
F_11 ( 0x30 ) ;
F_12 ( L_1 ) ;
return false ;
}
return true ;
}
bool F_13 ( struct V_1 * V_2 ,
unsigned char V_44 , unsigned char V_56 )
{
void T_4 * V_46 = V_2 -> V_47 ;
unsigned short V_48 ;
unsigned char V_49 ;
F_8 ( V_46 + V_50 , V_44 ) ;
F_8 ( V_46 + V_55 , V_56 ) ;
F_9 ( V_46 , V_51 , V_57 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
F_10 ( V_46 + V_51 , & V_49 ) ;
if ( V_49 & V_54 )
break;
}
if ( V_48 == V_53 ) {
F_11 ( 0x31 ) ;
F_12 ( L_2 ) ;
return false ;
}
return true ;
}
bool F_14 ( struct V_1 * V_2 )
{
bool V_58 = true ;
int V_59 ;
void T_4 * V_46 = V_2 -> V_47 ;
unsigned char V_60 = V_2 -> V_60 ;
unsigned char V_61 = V_2 -> V_61 ;
if ( V_60 == V_62 ) {
if ( V_61 <= V_63 ) {
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_65 [ V_59 ] [ 0 ] , V_65 [ V_59 ] [ 1 ] ) ;
} else {
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_67 [ V_59 ] [ 0 ] , V_67 [ V_59 ] [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_68 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_69 [ V_59 ] [ 0 ] , V_69 [ V_59 ] [ 1 ] ) ;
F_15 ( V_46 + V_70 , 0x23 ) ;
F_9 ( V_46 , V_71 , F_16 ( 0 ) ) ;
}
V_2 -> V_72 [ 0 ] = 0x18 ;
V_2 -> V_72 [ 1 ] = 0x0A ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 70 ;
V_2 -> V_73 [ 1 ] = - 50 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
} else if ( ( V_60 == V_74 ) || ( V_60 == V_75 ) ) {
for ( V_59 = 0 ; V_59 < V_76 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_77 [ V_59 ] [ 0 ] , V_77 [ V_59 ] [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_79 [ V_59 ] [ 0 ] , V_79 [ V_59 ] [ 1 ] ) ;
V_2 -> V_72 [ 0 ] = 0x1C ;
V_2 -> V_72 [ 1 ] = 0x10 ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 70 ;
V_2 -> V_73 [ 1 ] = - 48 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
} else if ( V_60 == V_80 ) {
for ( V_59 = 0 ; V_59 < V_81 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_82 [ V_59 ] [ 0 ] , V_82 [ V_59 ] [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_79 [ V_59 ] [ 0 ] , V_79 [ V_59 ] [ 1 ] ) ;
F_8 ( V_46 + V_70 , 0x23 ) ;
F_9 ( V_46 , V_71 , F_16 ( 0 ) ) ;
V_2 -> V_72 [ 0 ] = 0x14 ;
V_2 -> V_72 [ 1 ] = 0x0A ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 60 ;
V_2 -> V_73 [ 1 ] = - 50 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
} else if ( V_60 == V_83 ) {
for ( V_59 = 0 ; V_59 < V_81 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_82 [ V_59 ] [ 0 ] , V_82 [ V_59 ] [ 1 ] ) ;
V_58 &= F_13 ( V_2 , 0xd7 , 0x06 ) ;
V_58 &= F_13 ( V_2 , 0x90 , 0x20 ) ;
V_58 &= F_13 ( V_2 , 0x97 , 0xeb ) ;
V_58 &= F_13 ( V_2 , 0xa6 , 0x00 ) ;
V_58 &= F_13 ( V_2 , 0xa8 , 0x30 ) ;
V_58 &= F_13 ( V_2 , 0xb0 , 0x58 ) ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_79 [ V_59 ] [ 0 ] , V_79 [ V_59 ] [ 1 ] ) ;
V_2 -> V_72 [ 0 ] = 0x14 ;
V_2 -> V_72 [ 1 ] = 0x0A ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 60 ;
V_2 -> V_73 [ 1 ] = - 50 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
} else if ( V_60 == V_84 ) {
for ( V_59 = 0 ; V_59 < V_76 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_77 [ V_59 ] [ 0 ] , V_77 [ V_59 ] [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_79 [ V_59 ] [ 0 ] , V_79 [ V_59 ] [ 1 ] ) ;
V_2 -> V_72 [ 0 ] = 0x1C ;
V_2 -> V_72 [ 1 ] = 0x10 ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 70 ;
V_2 -> V_73 [ 1 ] = - 48 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
F_17 ( V_46 ) ;
} else if ( V_60 == V_85 ) {
for ( V_59 = 0 ; V_59 < V_76 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_77 [ V_59 ] [ 0 ] , V_77 [ V_59 ] [ 1 ] ) ;
V_58 &= F_13 ( V_2 , 0xd7 , 0x06 ) ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ )
V_58 &= F_13 ( V_2 , V_79 [ V_59 ] [ 0 ] , V_79 [ V_59 ] [ 1 ] ) ;
V_2 -> V_72 [ 0 ] = 0x1C ;
V_2 -> V_72 [ 1 ] = 0x10 ;
V_2 -> V_72 [ 2 ] = 0x0 ;
V_2 -> V_72 [ 3 ] = 0x0 ;
V_2 -> V_73 [ 0 ] = - 70 ;
V_2 -> V_73 [ 1 ] = - 48 ;
V_2 -> V_73 [ 2 ] = 0 ;
V_2 -> V_73 [ 3 ] = 0 ;
} else {
V_2 -> V_86 = false ;
V_2 -> V_72 [ 0 ] = 0x1C ;
}
if ( V_61 > V_63 ) {
F_13 ( V_2 , 0x04 , 0x7F ) ;
F_13 ( V_2 , 0x0D , 0x01 ) ;
}
return V_58 ;
}
void
F_18 ( struct V_1 * V_2 )
{
unsigned char V_87 = 0 ;
unsigned char V_88 = 0 ;
F_7 ( V_2 , 0x0A , & V_87 ) ;
if ( V_2 -> V_89 )
V_87 &= 0xDF ;
else
V_87 |= 0x20 ;
F_7 ( V_2 , 0xE7 , & V_88 ) ;
if ( V_88 == V_2 -> V_72 [ 0 ] )
V_87 |= 0x20 ;
F_13 ( V_2 , 0x0A , V_87 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned char V_56 )
{
unsigned char V_87 = 0 ;
F_13 ( V_2 , 0xE7 , V_56 ) ;
F_7 ( V_2 , 0x0A , & V_87 ) ;
if ( V_56 == V_2 -> V_72 [ 0 ] )
V_87 |= 0x20 ;
else if ( V_2 -> V_89 )
V_87 &= 0xDF ;
else
V_87 |= 0x20 ;
V_2 -> V_90 = V_56 ;
F_13 ( V_2 , 0x0A , V_87 ) ;
}
void
F_20 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0x50 , 0x40 ) ;
F_13 ( V_2 , 0x50 , 0 ) ;
F_13 ( V_2 , 0x9C , 0x01 ) ;
F_13 ( V_2 , 0x9C , 0 ) ;
}
void
F_21 ( struct V_1 * V_2 )
{
unsigned char V_91 ;
F_7 ( V_2 , 0x0D , & V_91 ) ;
V_91 |= F_16 ( 0 ) ;
F_13 ( V_2 , 0x0D , V_91 ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
unsigned char V_91 ;
F_7 ( V_2 , 0x0D , & V_91 ) ;
V_91 &= ~ ( F_16 ( 0 ) ) ;
F_13 ( V_2 , 0x0D , V_91 ) ;
}
void
F_3 ( struct V_1 * V_2 , unsigned char V_92 )
{
unsigned char V_93 ;
F_7 ( V_2 , 0x09 , & V_93 ) ;
if ( V_92 == V_94 ) {
V_93 |= 0x02 ;
} else if ( V_92 == V_5 ) {
V_93 &= 0xF9 ;
} else if ( V_92 == V_6 ) {
V_93 &= 0xFD ;
V_93 |= 0x04 ;
}
F_13 ( V_2 , 0x09 , V_93 ) ;
}
void
F_2 ( struct V_1 * V_2 , unsigned char V_92 )
{
unsigned char V_87 ;
F_7 ( V_2 , 0x0A , & V_87 ) ;
if ( V_92 == V_94 ) {
V_87 |= 0x01 ;
} else if ( V_92 == V_5 ) {
V_87 &= 0xFC ;
} else if ( V_92 == V_6 ) {
V_87 &= 0xFE ;
V_87 |= 0x02 ;
}
F_13 ( V_2 , 0x0A , V_87 ) ;
}
void
F_23 ( struct V_1 * V_2 , unsigned char V_61 )
{
F_13 ( V_2 , 0x0C , 0x17 ) ;
F_13 ( V_2 , 0x0D , 0xB9 ) ;
}
void
F_24 ( struct V_1 * V_2 , unsigned char V_61 )
{
F_13 ( V_2 , 0x0C , 0x00 ) ;
F_13 ( V_2 , 0x0D , 0x01 ) ;
}
static
unsigned long
F_25 ( struct V_1 * V_2 )
{
unsigned long V_95 = 0 ;
unsigned long V_96 ;
unsigned long V_97 ;
V_96 = V_2 -> V_98 [ V_17 ] ;
if ( V_2 -> V_98 [ V_17 ] != 0 ) {
V_97 = V_2 -> V_98 [ V_17 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_100 ;
}
if ( V_2 -> V_98 [ V_40 ] > V_96 ) {
V_97 = V_2 -> V_98 [ V_17 ] + V_2 -> V_98 [ V_40 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_101 ;
V_96 = V_2 -> V_98 [ V_40 ] ;
}
if ( V_2 -> V_98 [ V_39 ] > V_96 ) {
V_97 = V_2 -> V_98 [ V_17 ] + V_2 -> V_98 [ V_40 ] +
V_2 -> V_98 [ V_39 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_102 ;
V_96 = V_2 -> V_98 [ V_39 ] ;
}
if ( V_2 -> V_98 [ V_38 ] > V_96 ) {
V_97 = V_2 -> V_98 [ V_17 ] + V_2 -> V_98 [ V_40 ] +
V_2 -> V_98 [ V_39 ] + V_2 -> V_98 [ V_38 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_103 ;
V_96 = V_2 -> V_98 [ V_38 ] ;
}
if ( V_2 -> V_98 [ V_37 ] > V_96 ) {
V_97 = V_2 -> V_98 [ V_17 ] + V_2 -> V_98 [ V_40 ] +
V_2 -> V_98 [ V_39 ] + V_2 -> V_98 [ V_38 ] +
V_2 -> V_98 [ V_37 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_104 ;
V_96 = V_2 -> V_98 [ V_37 ] ;
}
if ( V_2 -> V_98 [ V_36 ] > V_96 ) {
V_97 = V_2 -> V_98 [ V_17 ] + V_2 -> V_98 [ V_40 ] +
V_2 -> V_98 [ V_39 ] + V_2 -> V_98 [ V_38 ] +
V_2 -> V_98 [ V_37 ] + V_2 -> V_98 [ V_36 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_105 ;
V_96 = V_2 -> V_98 [ V_36 ] ;
}
if ( V_2 -> V_98 [ V_33 ] > V_96 ) {
V_97 = V_2 -> V_99 - V_2 -> V_98 [ V_30 ] -
V_2 -> V_98 [ V_31 ] - V_2 -> V_98 [ V_32 ] -
V_2 -> V_98 [ V_34 ] - V_2 -> V_98 [ V_35 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_106 ;
V_96 = V_2 -> V_98 [ V_33 ] ;
}
if ( V_2 -> V_98 [ V_35 ] > V_96 ) {
V_97 = V_2 -> V_99 - V_2 -> V_98 [ V_30 ] -
V_2 -> V_98 [ V_31 ] - V_2 -> V_98 [ V_32 ] -
V_2 -> V_98 [ V_34 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_107 ;
V_96 = V_2 -> V_98 [ V_35 ] ;
}
if ( V_2 -> V_98 [ V_34 ] > V_96 ) {
V_97 = V_2 -> V_99 - V_2 -> V_98 [ V_30 ] -
V_2 -> V_98 [ V_31 ] - V_2 -> V_98 [ V_32 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_108 ;
V_96 = V_2 -> V_98 [ V_34 ] ;
}
if ( V_2 -> V_98 [ V_32 ] > V_96 ) {
V_97 = V_2 -> V_99 - V_2 -> V_98 [ V_30 ] -
V_2 -> V_98 [ V_31 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_109 ;
V_96 = V_2 -> V_98 [ V_32 ] ;
}
if ( V_2 -> V_98 [ V_31 ] > V_96 ) {
V_97 = V_2 -> V_99 - V_2 -> V_98 [ V_30 ] ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_110 ;
V_96 = V_2 -> V_98 [ V_31 ] ;
}
if ( V_2 -> V_98 [ V_30 ] > V_96 ) {
V_97 = V_2 -> V_99 ;
V_95 = ( V_97 * 1000 / V_2 -> V_99 ) ;
V_95 += V_111 ;
}
return V_95 ;
}
void
F_26 ( struct V_1 * V_2 )
{
unsigned int V_59 ;
V_2 -> V_99 = 0 ;
for ( V_59 = 0 ; V_59 < V_112 ; V_59 ++ )
V_2 -> V_98 [ V_59 ] = 0 ;
}
void F_27 ( struct V_1 * V_2 ,
unsigned char V_113 , unsigned char V_114 )
{
if ( ( V_113 >= V_112 ) || ( V_2 -> V_115 >= V_112 ) )
return;
V_2 -> V_99 ++ ;
V_2 -> V_98 [ V_113 ] ++ ;
if ( V_2 -> V_116 == 0 ) {
if ( V_2 -> V_99 > V_2 -> V_117 ) {
F_12 ( L_3 ,
( int ) V_2 -> V_117 ,
( int ) V_2 -> V_98 [ ( int ) V_2 -> V_115 ] ) ;
if ( V_2 -> V_98 [ V_2 -> V_115 ] < V_2 -> V_99 / 2 ) {
V_2 -> V_118 = F_25 ( V_2 ) ;
F_12 ( L_4 ,
( int ) V_2 -> V_118 ) ;
if ( V_2 -> V_119 == 0 )
return;
F_12 ( L_5 ,
( int ) V_2 -> V_118 ,
( int ) V_2 -> V_115 ,
( int ) V_2 -> V_98 [ ( int ) V_2 -> V_115 ] ,
( int ) V_2 -> V_99 ) ;
F_1 ( V_2 ) ;
V_2 -> V_116 = 1 ;
F_28 ( & V_2 -> V_120 ) ;
F_28 ( & V_2 -> V_121 ) ;
V_2 -> V_122 . V_123 = F_29 ( V_2 -> V_119 * V_124 ) ;
F_30 ( & V_2 -> V_122 ) ;
} else {
V_2 -> V_120 . V_123 = F_29 ( V_2 -> V_125 * V_124 ) ;
F_30 ( & V_2 -> V_120 ) ;
}
F_26 ( V_2 ) ;
}
} else {
if ( V_2 -> V_99 > V_2 -> V_126 ) {
F_28 ( & V_2 -> V_122 ) ;
V_2 -> V_127 = F_25 ( V_2 ) ;
F_12 ( L_6 ,
( int ) V_2 -> V_118 ,
( int ) V_2 -> V_127 ) ;
if ( V_2 -> V_127 < V_2 -> V_118 ) {
F_12 ( L_7 ,
( int ) V_2 -> V_118 ,
( int ) V_2 -> V_127 ,
( int ) V_2 -> V_115 ,
( int ) V_2 -> V_98 [ ( int ) V_2 -> V_115 ] ,
( int ) V_2 -> V_99 ) ;
F_1 ( V_2 ) ;
V_2 -> V_120 . V_123 = F_29 ( V_2 -> V_125 * V_124 ) ;
V_2 -> V_121 . V_123 = F_29 ( V_2 -> V_128 * V_124 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_30 ( & V_2 -> V_121 ) ;
}
V_2 -> V_116 = 0 ;
F_26 ( V_2 ) ;
}
}
}
void
F_31 (
unsigned long V_129
)
{
struct V_1 * V_2 = (struct V_1 * ) V_129 ;
unsigned long V_130 ;
F_12 ( L_8 ) ;
F_32 ( & V_2 -> V_131 , V_130 ) ;
F_12 ( L_9 ,
( int ) V_2 -> V_118 , ( int ) V_2 -> V_127 ,
( int ) V_2 -> V_99 ) ;
F_1 ( V_2 ) ;
V_2 -> V_116 = 0 ;
F_26 ( V_2 ) ;
V_2 -> V_120 . V_123 = F_29 ( V_2 -> V_125 * V_124 ) ;
V_2 -> V_121 . V_123 = F_29 ( V_2 -> V_128 * V_124 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_30 ( & V_2 -> V_121 ) ;
F_33 ( & V_2 -> V_131 , V_130 ) ;
}
void
F_34 (
unsigned long V_129
)
{
struct V_1 * V_2 = (struct V_1 * ) V_129 ;
unsigned long V_130 ;
F_12 ( L_10 ) ;
F_32 ( & V_2 -> V_131 , V_130 ) ;
if ( V_2 -> V_99 < V_2 -> V_126 / 100 ) {
F_1 ( V_2 ) ;
V_2 -> V_120 . V_123 = F_29 ( V_2 -> V_125 * V_124 ) ;
V_2 -> V_121 . V_123 = F_29 ( V_2 -> V_128 * V_124 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_30 ( & V_2 -> V_121 ) ;
} else {
V_2 -> V_127 = F_25 ( V_2 ) ;
F_12 ( L_11 ,
( int ) V_2 -> V_118 ,
( int ) V_2 -> V_127 ) ;
if ( V_2 -> V_127 < V_2 -> V_118 ) {
F_12 ( L_7 ,
( int ) V_2 -> V_118 ,
( int ) V_2 -> V_127 ,
( int ) V_2 -> V_115 ,
( int ) V_2 -> V_98 [ ( int ) V_2 -> V_115 ] ,
( int ) V_2 -> V_99 ) ;
F_1 ( V_2 ) ;
V_2 -> V_120 . V_123 = F_29 ( V_2 -> V_125 * V_124 ) ;
V_2 -> V_121 . V_123 = F_29 ( V_2 -> V_128 * V_124 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_30 ( & V_2 -> V_121 ) ;
}
}
V_2 -> V_116 = 0 ;
F_26 ( V_2 ) ;
F_33 ( & V_2 -> V_131 , V_130 ) ;
}
