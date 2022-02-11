unsigned int
F_1 (
unsigned char V_1 ,
unsigned char V_2 ,
unsigned int V_3 ,
unsigned short V_4
)
{
unsigned int V_5 ;
unsigned int V_6 ;
unsigned int V_7 ;
unsigned int V_8 = ( unsigned int ) V_4 ;
unsigned int V_9 = 0 ;
if ( V_8 > V_10 ) {
ASSERT ( 0 ) ;
return 0 ;
}
V_9 = ( unsigned int ) V_11 [ V_8 ] ;
if ( V_8 <= 3 ) {
if ( V_1 == 1 )
V_6 = 96 ;
else
V_6 = 192 ;
V_5 = ( V_3 * 80 ) / V_9 ;
V_7 = ( V_5 * V_9 ) / 80 ;
if ( V_3 != V_7 )
V_5 ++ ;
return V_6 + V_5 ;
}
V_5 = ( V_3 * 8 + 22 ) / V_9 ;
V_7 = ( ( V_5 * V_9 ) - 22 ) / 8 ;
if ( V_3 != V_7 )
V_5 ++ ;
V_5 = V_5 * 4 ;
if ( V_2 != V_12 )
V_5 += 6 ;
return 20 + V_5 ;
}
void F_2 ( struct V_13 * V_14 , T_1 V_15 ,
T_2 V_16 , T_3 V_17 , struct V_18 * V_19 )
{
T_1 V_20 ;
T_1 V_21 = 0 ;
T_1 V_22 ;
int V_23 ;
T_3 V_24 = V_14 -> V_1 ;
V_20 = V_15 * 8 ;
V_23 = false ;
switch ( V_16 ) {
case V_25 :
V_21 = V_20 ;
V_19 -> signal = 0x00 ;
break;
case V_26 :
V_21 = V_20 / 2 ;
if ( V_24 == 1 )
V_19 -> signal = 0x09 ;
else
V_19 -> signal = 0x01 ;
break;
case V_27 :
V_21 = ( V_20 * 10 ) / 55 ;
V_22 = ( V_21 * 55 ) / 10 ;
if ( V_22 != V_20 )
V_21 ++ ;
if ( V_24 == 1 )
V_19 -> signal = 0x0a ;
else
V_19 -> signal = 0x02 ;
break;
case V_28 :
V_21 = V_20 / 11 ;
V_22 = V_21 * 11 ;
if ( V_22 != V_20 ) {
V_21 ++ ;
if ( ( V_20 - V_22 ) <= 3 )
V_23 = true ;
}
if ( V_24 == 1 )
V_19 -> signal = 0x0b ;
else
V_19 -> signal = 0x03 ;
break;
case V_29 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9b ;
else
V_19 -> signal = 0x8b ;
break;
case V_30 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9f ;
else
V_19 -> signal = 0x8f ;
break;
case V_31 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9a ;
else
V_19 -> signal = 0x8a ;
break;
case V_32 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9e ;
else
V_19 -> signal = 0x8e ;
break;
case V_33 :
if ( V_17 == V_12 )
V_19 -> signal = 0x99 ;
else
V_19 -> signal = 0x89 ;
break;
case V_34 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9d ;
else
V_19 -> signal = 0x8d ;
break;
case V_35 :
if ( V_17 == V_12 )
V_19 -> signal = 0x98 ;
else
V_19 -> signal = 0x88 ;
break;
case V_10 :
if ( V_17 == V_12 )
V_19 -> signal = 0x9c ;
else
V_19 -> signal = 0x8c ;
break;
default:
if ( V_17 == V_12 )
V_19 -> signal = 0x9c ;
else
V_19 -> signal = 0x8c ;
break;
}
if ( V_17 == V_36 ) {
V_19 -> V_37 = 0x00 ;
if ( V_23 )
V_19 -> V_37 |= 0x80 ;
V_19 -> V_38 = F_3 ( ( T_2 ) V_21 ) ;
} else {
V_19 -> V_37 = 0x00 ;
V_19 -> V_38 = F_3 ( ( T_2 ) V_15 ) ;
}
}
bool F_4 ( struct V_13 * V_14 ,
unsigned char V_39 , unsigned char * V_40 )
{
void T_4 * V_41 = V_14 -> V_42 ;
unsigned short V_43 ;
unsigned char V_44 ;
F_5 ( V_41 + V_45 , V_39 ) ;
F_6 ( V_41 , V_46 , V_47 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
F_7 ( V_41 + V_46 , & V_44 ) ;
if ( V_44 & V_49 )
break;
}
F_7 ( V_41 + V_50 , V_40 ) ;
if ( V_43 == V_48 ) {
F_8 ( 0x30 ) ;
F_9 ( L_1 ) ;
return false ;
}
return true ;
}
bool F_10 ( struct V_13 * V_14 ,
unsigned char V_39 , unsigned char V_51 )
{
void T_4 * V_41 = V_14 -> V_42 ;
unsigned short V_43 ;
unsigned char V_44 ;
F_5 ( V_41 + V_45 , V_39 ) ;
F_5 ( V_41 + V_50 , V_51 ) ;
F_6 ( V_41 , V_46 , V_52 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
F_7 ( V_41 + V_46 , & V_44 ) ;
if ( V_44 & V_49 )
break;
}
if ( V_43 == V_48 ) {
F_8 ( 0x31 ) ;
F_9 ( L_2 ) ;
return false ;
}
return true ;
}
bool F_11 ( struct V_13 * V_14 )
{
bool V_53 = true ;
int V_54 ;
void T_4 * V_41 = V_14 -> V_42 ;
unsigned char V_55 = V_14 -> V_55 ;
unsigned char V_56 = V_14 -> V_56 ;
if ( V_55 == V_57 ) {
if ( V_56 <= V_58 ) {
for ( V_54 = 0 ; V_54 < V_59 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_60 [ V_54 ] [ 0 ] ,
V_60 [ V_54 ] [ 1 ] ) ;
} else {
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_62 [ V_54 ] [ 0 ] ,
V_62 [ V_54 ] [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < V_63 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_64 [ V_54 ] [ 0 ] ,
V_64 [ V_54 ] [ 1 ] ) ;
F_12 ( V_41 + V_65 , 0x23 ) ;
F_6 ( V_41 , V_66 , F_13 ( 0 ) ) ;
}
V_14 -> V_67 [ 0 ] = 0x18 ;
V_14 -> V_67 [ 1 ] = 0x0A ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 70 ;
V_14 -> V_68 [ 1 ] = - 50 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
} else if ( ( V_55 == V_69 ) || ( V_55 == V_70 ) ) {
for ( V_54 = 0 ; V_54 < V_71 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_72 [ V_54 ] [ 0 ] ,
V_72 [ V_54 ] [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < V_73 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_74 [ V_54 ] [ 0 ] , V_74 [ V_54 ] [ 1 ] ) ;
V_14 -> V_67 [ 0 ] = 0x1C ;
V_14 -> V_67 [ 1 ] = 0x10 ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 70 ;
V_14 -> V_68 [ 1 ] = - 48 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
} else if ( V_55 == V_75 ) {
for ( V_54 = 0 ; V_54 < V_76 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_77 [ V_54 ] [ 0 ] ,
V_77 [ V_54 ] [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < V_73 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_74 [ V_54 ] [ 0 ] ,
V_74 [ V_54 ] [ 1 ] ) ;
F_5 ( V_41 + V_65 , 0x23 ) ;
F_6 ( V_41 , V_66 , F_13 ( 0 ) ) ;
V_14 -> V_67 [ 0 ] = 0x14 ;
V_14 -> V_67 [ 1 ] = 0x0A ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 60 ;
V_14 -> V_68 [ 1 ] = - 50 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
} else if ( V_55 == V_78 ) {
for ( V_54 = 0 ; V_54 < V_76 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_77 [ V_54 ] [ 0 ] ,
V_77 [ V_54 ] [ 1 ] ) ;
V_53 &= F_10 ( V_14 , 0xd7 , 0x06 ) ;
V_53 &= F_10 ( V_14 , 0x90 , 0x20 ) ;
V_53 &= F_10 ( V_14 , 0x97 , 0xeb ) ;
V_53 &= F_10 ( V_14 , 0xa6 , 0x00 ) ;
V_53 &= F_10 ( V_14 , 0xa8 , 0x30 ) ;
V_53 &= F_10 ( V_14 , 0xb0 , 0x58 ) ;
for ( V_54 = 0 ; V_54 < V_73 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_74 [ V_54 ] [ 0 ] , V_74 [ V_54 ] [ 1 ] ) ;
V_14 -> V_67 [ 0 ] = 0x14 ;
V_14 -> V_67 [ 1 ] = 0x0A ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 60 ;
V_14 -> V_68 [ 1 ] = - 50 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
} else if ( V_55 == V_79 ) {
for ( V_54 = 0 ; V_54 < V_71 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_72 [ V_54 ] [ 0 ] ,
V_72 [ V_54 ] [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < V_73 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_74 [ V_54 ] [ 0 ] , V_74 [ V_54 ] [ 1 ] ) ;
V_14 -> V_67 [ 0 ] = 0x1C ;
V_14 -> V_67 [ 1 ] = 0x10 ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 70 ;
V_14 -> V_68 [ 1 ] = - 48 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
F_14 ( V_41 ) ;
} else if ( V_55 == V_80 ) {
for ( V_54 = 0 ; V_54 < V_71 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_72 [ V_54 ] [ 0 ] ,
V_72 [ V_54 ] [ 1 ] ) ;
V_53 &= F_10 ( V_14 , 0xd7 , 0x06 ) ;
for ( V_54 = 0 ; V_54 < V_73 ; V_54 ++ )
V_53 &= F_10 ( V_14 ,
V_74 [ V_54 ] [ 0 ] , V_74 [ V_54 ] [ 1 ] ) ;
V_14 -> V_67 [ 0 ] = 0x1C ;
V_14 -> V_67 [ 1 ] = 0x10 ;
V_14 -> V_67 [ 2 ] = 0x0 ;
V_14 -> V_67 [ 3 ] = 0x0 ;
V_14 -> V_68 [ 0 ] = - 70 ;
V_14 -> V_68 [ 1 ] = - 48 ;
V_14 -> V_68 [ 2 ] = 0 ;
V_14 -> V_68 [ 3 ] = 0 ;
} else {
V_14 -> V_81 = false ;
V_14 -> V_67 [ 0 ] = 0x1C ;
}
if ( V_56 > V_58 ) {
F_10 ( V_14 , 0x04 , 0x7F ) ;
F_10 ( V_14 , 0x0D , 0x01 ) ;
}
return V_53 ;
}
void
F_15 ( struct V_13 * V_14 )
{
unsigned char V_82 = 0 ;
unsigned char V_83 = 0 ;
F_4 ( V_14 , 0x0A , & V_82 ) ;
if ( V_14 -> V_84 )
V_82 &= 0xDF ;
else
V_82 |= 0x20 ;
F_4 ( V_14 , 0xE7 , & V_83 ) ;
if ( V_83 == V_14 -> V_67 [ 0 ] )
V_82 |= 0x20 ;
F_10 ( V_14 , 0x0A , V_82 ) ;
}
void F_16 ( struct V_13 * V_14 , unsigned char V_51 )
{
unsigned char V_82 = 0 ;
F_10 ( V_14 , 0xE7 , V_51 ) ;
F_4 ( V_14 , 0x0A , & V_82 ) ;
if ( V_51 == V_14 -> V_67 [ 0 ] )
V_82 |= 0x20 ;
else if ( V_14 -> V_84 )
V_82 &= 0xDF ;
else
V_82 |= 0x20 ;
V_14 -> V_85 = V_51 ;
F_10 ( V_14 , 0x0A , V_82 ) ;
}
void
F_17 ( struct V_13 * V_14 )
{
F_10 ( V_14 , 0x50 , 0x40 ) ;
F_10 ( V_14 , 0x50 , 0 ) ;
F_10 ( V_14 , 0x9C , 0x01 ) ;
F_10 ( V_14 , 0x9C , 0 ) ;
}
void
F_18 ( struct V_13 * V_14 )
{
unsigned char V_86 ;
F_4 ( V_14 , 0x0D , & V_86 ) ;
V_86 |= F_13 ( 0 ) ;
F_10 ( V_14 , 0x0D , V_86 ) ;
}
void
F_19 ( struct V_13 * V_14 )
{
unsigned char V_86 ;
F_4 ( V_14 , 0x0D , & V_86 ) ;
V_86 &= ~ ( F_13 ( 0 ) ) ;
F_10 ( V_14 , 0x0D , V_86 ) ;
}
void
F_20 ( struct V_13 * V_14 , unsigned char V_87 )
{
unsigned char V_88 ;
F_4 ( V_14 , 0x09 , & V_88 ) ;
if ( V_87 == V_89 ) {
V_88 |= 0x02 ;
} else if ( V_87 == V_90 ) {
V_88 &= 0xF9 ;
} else if ( V_87 == V_91 ) {
V_88 &= 0xFD ;
V_88 |= 0x04 ;
}
F_10 ( V_14 , 0x09 , V_88 ) ;
}
void
F_21 ( struct V_13 * V_14 , unsigned char V_87 )
{
unsigned char V_82 ;
F_4 ( V_14 , 0x0A , & V_82 ) ;
if ( V_87 == V_89 ) {
V_82 |= 0x01 ;
} else if ( V_87 == V_90 ) {
V_82 &= 0xFC ;
} else if ( V_87 == V_91 ) {
V_82 &= 0xFE ;
V_82 |= 0x02 ;
}
F_10 ( V_14 , 0x0A , V_82 ) ;
}
void
F_22 ( struct V_13 * V_14 , unsigned char V_56 )
{
F_10 ( V_14 , 0x0C , 0x17 ) ;
F_10 ( V_14 , 0x0D , 0xB9 ) ;
}
void
F_23 ( struct V_13 * V_14 , unsigned char V_56 )
{
F_10 ( V_14 , 0x0C , 0x00 ) ;
F_10 ( V_14 , 0x0D , 0x01 ) ;
}
