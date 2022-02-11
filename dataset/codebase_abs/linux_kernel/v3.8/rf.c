BOOL F_1 ( T_1 V_1 , T_2 V_2 )
{
T_3 V_3 [ 4 ] ;
V_3 [ 0 ] = ( T_3 ) V_2 ;
V_3 [ 1 ] = ( T_3 ) ( V_2 >> 8 ) ;
V_3 [ 2 ] = ( T_3 ) ( V_2 >> 16 ) ;
V_3 [ 3 ] = ( T_3 ) ( V_2 >> 24 ) ;
F_2 ( V_1 ,
V_4 ,
0 ,
0 ,
4 ,
V_3
) ;
return TRUE ;
}
BOOL F_3 (
T_1 V_1 ,
unsigned int V_5 ,
unsigned int V_6
)
{
BOOL V_7 = TRUE ;
T_3 V_8 = V_1 -> V_9 ;
if ( V_1 -> V_10 != 0 ) {
return TRUE ;
}
if ( V_6 == 0 )
return - V_11 ;
switch ( V_5 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_8 = V_1 -> V_16 [ V_6 - 1 ] ;
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
if ( V_6 > V_24 ) {
V_8 = V_1 -> V_25 [ V_6 - 15 ] ;
} else {
V_8 = V_1 -> V_26 [ V_6 - 1 ] ;
}
break;
}
V_7 = F_4 ( V_1 , V_8 , V_5 ) ;
return V_7 ;
}
BOOL F_4 (
T_1 V_1 ,
T_3 V_8 ,
unsigned int V_5
)
{
BOOL V_7 = TRUE ;
if ( V_1 -> V_27 == V_8 )
return TRUE ;
V_1 -> V_27 = V_8 ;
switch ( V_1 -> V_28 ) {
case V_29 :
if ( V_1 -> V_27 >= V_30 )
return FALSE ;
V_7 &= F_1 ( V_1 , V_31 [ V_1 -> V_27 ] ) ;
if ( V_5 <= V_15 )
V_7 &= F_1 ( V_1 , 0x0001B400 + ( V_32 << 3 ) + V_33 ) ;
else
V_7 &= F_1 ( V_1 , 0x0005A400 + ( V_32 << 3 ) + V_33 ) ;
break;
case V_34 :
if ( V_1 -> V_27 >= V_30 )
return FALSE ;
V_7 &= F_1 ( V_1 , V_31 [ V_1 -> V_27 ] ) ;
if ( V_5 <= V_15 ) {
V_7 &= F_1 ( V_1 , 0x040C1400 + ( V_32 << 3 ) + V_33 ) ;
V_7 &= F_1 ( V_1 , 0x00299B00 + ( V_32 << 3 ) + V_33 ) ;
} else {
V_7 &= F_1 ( V_1 , 0x0005A400 + ( V_32 << 3 ) + V_33 ) ;
V_7 &= F_1 ( V_1 , 0x00099B00 + ( V_32 << 3 ) + V_33 ) ;
}
break;
case V_35 :
{
T_2 V_36 ;
if ( V_5 <= V_15 ) {
V_7 &= F_1 ( V_1 , 0x111BB900 + ( V_37 << 3 ) + V_33 ) ;
}
else {
V_7 &= F_1 ( V_1 , 0x221BB900 + ( V_37 << 3 ) + V_33 ) ;
}
if ( V_1 -> V_27 > V_38 ) return FALSE ;
V_36 = 0x080C0B00 | ( ( V_1 -> V_27 ) << 12 ) |
( V_37 << 3 ) | V_33 ;
V_7 &= F_1 ( V_1 , V_36 ) ;
break;
}
break;
case V_39 :
{
T_2 V_40 ;
if ( V_1 -> V_27 >= V_41 )
return FALSE ;
V_40 = ( ( 0x3F - V_1 -> V_27 ) << 20 ) | ( 0x17 << 8 ) |
( V_42 << 3 ) | V_33 ;
V_7 &= F_1 ( V_1 , V_40 ) ;
break;
}
case V_43 :
{
T_2 V_40 ;
if ( V_1 -> V_27 >= V_41 )
return FALSE ;
if ( V_5 <= V_15 ) {
V_40 = ( ( 0x3F - V_1 -> V_27 ) << 20 ) | ( 0xE07 << 8 ) |
( V_42 << 3 ) | V_33 ;
V_7 &= F_1 ( V_1 , V_40 ) ;
V_7 &= F_1 ( V_1 , 0x03C6A200 + ( V_42 << 3 ) + V_33 ) ;
if ( V_1 -> V_44 . V_45 != V_46 ) {
F_5 ( V_47 , V_48 L_1 , V_1 -> V_44 . V_49 ) ;
V_7 &= F_1 ( V_1 , V_50 [ V_1 -> V_44 . V_49 - 1 ] ) ;
} else {
F_5 ( V_47 , V_48 L_1 , V_1 -> V_44 . V_51 ) ;
V_7 &= F_1 ( V_1 , V_50 [ V_1 -> V_44 . V_51 - 1 ] ) ;
}
V_7 &= F_1 ( V_1 , 0x015C0800 + ( V_42 << 3 ) + V_33 ) ;
} else {
F_5 ( V_47 , V_48 L_2 ) ;
V_40 = ( ( 0x3F - V_1 -> V_27 ) << 20 ) | ( 0x7 << 8 ) |
( V_42 << 3 ) | V_33 ;
V_7 &= F_1 ( V_1 , V_40 ) ;
V_7 &= F_1 ( V_1 , 0x00C6A200 + ( V_42 << 3 ) + V_33 ) ;
V_7 &= F_1 ( V_1 , 0x016BC600 + ( V_42 << 3 ) + V_33 ) ;
V_7 &= F_1 ( V_1 , 0x00900800 + ( V_42 << 3 ) + V_33 ) ;
}
break;
}
case V_52 :
{
T_2 V_53 ;
if ( V_1 -> V_27 >= V_54 )
return FALSE ;
V_53 = ( ( 0x3F - V_1 -> V_27 ) << 20 ) | ( 0x27 << 8 ) |
( V_55 << 3 ) | V_33 ;
V_7 &= F_1 ( V_1 , V_53 ) ;
break;
}
default :
break;
}
return V_7 ;
}
void
F_6 (
T_1 V_1 ,
T_3 V_56 ,
long * V_57
)
{
T_3 V_58 = ( ( ( V_56 & 0xC0 ) >> 6 ) & 0x03 ) ;
signed long V_59 = ( V_56 & 0x3F ) ;
signed long V_60 = 0 ;
T_3 V_61 [ 4 ] = { 0 , 18 , 0 , 40 } ;
switch ( V_1 -> V_28 ) {
case V_29 :
case V_34 :
case V_35 :
case V_39 :
case V_43 :
case V_52 :
V_60 = V_61 [ V_58 ] ;
break;
default:
break;
}
* V_57 = - 1 * ( V_60 + V_59 * 2 ) ;
}
void
F_7 (
T_1 V_1
)
{
T_4 V_62 = 0 , V_63 = 0 , V_64 = 0 ;
T_5 V_65 = NULL , V_66 = NULL , V_67 = NULL ;
T_4 V_68 , V_69 ;
T_3 V_70 [ 256 ] ;
switch ( V_1 -> V_28 ) {
case V_29 :
case V_34 :
V_62 = V_71 * 3 ;
V_63 = V_24 * 3 ;
V_64 = V_24 * 3 ;
V_65 = & ( V_72 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_73 [ 0 ] [ 0 ] ) ;
V_67 = & ( V_74 [ 0 ] [ 0 ] ) ;
break;
case V_35 :
V_62 = V_75 * 3 ;
V_63 = V_76 * 3 ;
V_64 = V_76 * 3 ;
V_65 = & ( V_77 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_78 [ 0 ] [ 0 ] ) ;
V_67 = & ( V_79 [ 0 ] [ 0 ] ) ;
break;
case V_39 :
V_62 = V_80 * 3 ;
V_63 = V_24 * 3 ;
V_64 = V_24 * 3 ;
V_65 = & ( V_81 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_82 [ 0 ] [ 0 ] ) ;
V_67 = & ( V_83 [ 0 ] [ 0 ] ) ;
break;
case V_43 :
V_62 = V_80 * 3 ;
V_63 = V_24 * 3 ;
V_64 = V_24 * 3 ;
V_65 = & ( V_84 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_82 [ 0 ] [ 0 ] ) ;
V_67 = & ( V_83 [ 0 ] [ 0 ] ) ;
break;
case V_52 :
V_62 = V_85 * 3 ;
V_63 = V_76 * 3 ;
V_64 = V_76 * 3 ;
V_65 = & ( V_86 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_87 [ 0 ] [ 0 ] ) ;
V_67 = & ( V_88 [ 0 ] [ 0 ] ) ;
break;
}
memcpy ( V_70 , V_65 , V_62 ) ;
F_2 ( V_1 ,
V_89 ,
0 ,
V_90 ,
V_62 ,
V_70
) ;
V_69 = 0 ;
while ( V_63 > 0 ) {
if ( V_63 >= 64 ) {
V_68 = 64 ;
} else {
V_68 = V_63 ;
}
memcpy ( V_70 , V_66 , V_68 ) ;
F_2 ( V_1 ,
V_89 ,
V_69 ,
V_91 ,
V_68 ,
V_70 ) ;
V_63 -= V_68 ;
V_69 += V_68 ;
V_66 += V_68 ;
}
V_69 = 0 ;
while ( V_64 > 0 ) {
if ( V_64 >= 64 ) {
V_68 = 64 ;
} else {
V_68 = V_64 ;
}
memcpy ( V_70 , V_67 , V_68 ) ;
F_2 ( V_1 ,
V_89 ,
V_69 ,
V_92 ,
V_68 ,
V_70 ) ;
V_64 -= V_68 ;
V_69 += V_68 ;
V_67 += V_68 ;
}
if ( V_1 -> V_28 == V_35 ) {
V_62 = V_75 * 3 ;
V_63 = V_76 * 3 ;
V_65 = & ( V_93 [ 0 ] [ 0 ] ) ;
V_66 = & ( V_94 [ 0 ] [ 0 ] ) ;
memcpy ( V_70 , V_65 , V_62 ) ;
F_2 ( V_1 ,
V_89 ,
0 ,
V_95 ,
V_62 ,
V_70 ) ;
V_69 = 0 ;
while ( V_63 > 0 ) {
if ( V_63 >= 64 ) {
V_68 = 64 ;
} else {
V_68 = V_63 ;
}
memcpy ( V_70 , V_66 , V_68 ) ;
F_2 ( V_1 ,
V_89 ,
V_69 ,
V_96 ,
V_68 ,
V_70 ) ;
V_63 -= V_68 ;
V_69 += V_68 ;
V_66 += V_68 ;
}
}
}
BOOL F_8 (
T_1 V_1 ,
T_3 V_97 ,
BOOL V_98 )
{
BOOL V_7 ;
V_7 = TRUE ;
if( V_98 )
V_7 &= F_1 ( V_1 , V_50 [ V_97 - 1 ] ) ;
else
V_7 &= F_1 ( V_1 , 0x016BC600 + ( V_42 << 3 ) + V_33 ) ;
return V_7 ;
}
