int F_1 ( const T_1 * V_1 ,
T_2 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
unsigned V_5 , V_6 ;
const unsigned V_7 = 1 + V_4 ;
if ( V_7 > V_2 -> V_8 )
return 0 ;
V_5 = V_2 -> V_9 [ V_2 -> V_8 - 1 ] ;
V_6 = F_2 ( V_2 -> V_8 , V_5 + V_7 ) ;
V_6 &= F_2 ( V_3 , V_5 + 1 ) ;
V_5 = V_6 & ( V_5 + 1 ) ;
V_2 -> V_8 -= V_5 ;
V_2 -> type |= V_5 << 8 ;
return F_3 ( V_6 , 1 , - 1 ) ;
}
int F_4 ( const T_1 * V_1 ,
T_2 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
unsigned V_5 , V_6 , V_10 , V_11 ;
const unsigned V_7 = 1 + V_4 ;
if ( F_5 ( V_1 ) ) {
if ( V_7 + V_3 > V_2 -> V_8 )
return 0 ;
V_2 -> V_9 += V_3 ;
V_2 -> V_12 += V_3 ;
V_2 -> V_8 -= V_3 ;
} else if ( V_7 > V_2 -> V_8 )
return 0 ;
V_5 = V_2 -> V_9 [ V_2 -> V_8 - 1 ] ;
if ( ( V_1 -> V_13 & V_14 ) && ! V_1 -> V_15 ) {
if ( ( memcmp ( V_1 -> V_16 -> V_17 , L_1 , 8 ) == 0 ) &&
! ( V_5 & 1 ) ) {
V_1 -> V_16 -> V_18 |= V_19 ;
}
if ( ( V_1 -> V_16 -> V_18 & V_19 ) && V_5 > 0 ) {
V_5 -- ;
}
}
if ( F_6 ( V_1 -> V_20 -> V_21 ) & V_22 ) {
V_2 -> V_8 -= V_5 + 1 ;
return 1 ;
}
V_6 = F_2 ( V_2 -> V_8 , V_7 + V_5 ) ;
V_10 = 255 ;
if ( V_10 > V_2 -> V_8 - 1 )
V_10 = V_2 -> V_8 - 1 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
unsigned char V_23 = F_7 ( V_5 , V_11 ) ;
unsigned char V_24 = V_2 -> V_9 [ V_2 -> V_8 - 1 - V_11 ] ;
V_6 &= ~ ( V_23 & ( V_5 ^ V_24 ) ) ;
}
V_6 = F_8 ( 0xff , V_6 & 0xff ) ;
V_5 = V_6 & ( V_5 + 1 ) ;
V_2 -> V_8 -= V_5 ;
V_2 -> type |= V_5 << 8 ;
return F_3 ( V_6 , 1 , - 1 ) ;
}
void F_9 ( unsigned char * V_25 ,
const T_2 * V_2 ,
unsigned V_26 , unsigned V_27 )
{
#if F_10 ( V_28 )
unsigned char V_29 [ 64 + V_30 ] ;
unsigned char * V_31 ;
#else
unsigned char V_31 [ V_30 ] ;
#endif
unsigned V_32 = V_2 -> V_8 ;
unsigned V_33 = V_32 - V_26 ;
unsigned V_34 = 0 ;
unsigned V_11 , V_35 ;
unsigned V_36 ;
unsigned V_37 ;
F_11 ( V_27 >= V_26 ) ;
F_11 ( V_26 <= V_30 ) ;
#if F_10 ( V_28 )
V_31 = V_29 + ( ( 0 - ( V_38 ) V_29 ) & 63 ) ;
#endif
if ( V_27 > V_26 + 255 + 1 )
V_34 = V_27 - ( V_26 + 255 + 1 ) ;
V_36 = V_26 >> 1 ;
V_36 <<= ( sizeof( V_36 ) - 1 ) * 8 ;
V_37 = ( V_36 + V_33 - V_34 ) % V_26 ;
memset ( V_31 , 0 , V_26 ) ;
for ( V_11 = V_34 , V_35 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned char V_39 = F_7 ( V_11 , V_33 ) ;
unsigned char V_40 = F_7 ( V_11 , V_32 ) ;
unsigned char V_24 = V_2 -> V_9 [ V_11 ] ;
V_31 [ V_35 ++ ] |= V_24 & V_39 & ~ V_40 ;
V_35 &= F_12 ( V_35 , V_26 ) ;
}
#if F_10 ( V_28 )
V_35 = 0 ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ ) {
( ( volatile unsigned char * ) V_31 ) [ V_37 ^ 32 ] ;
V_25 [ V_35 ++ ] = V_31 [ V_37 ++ ] ;
V_37 &= F_12 ( V_37 , V_26 ) ;
}
#else
memset ( V_25 , 0 , V_26 ) ;
V_37 = V_26 - V_37 ;
V_37 &= F_12 ( V_37 , V_26 ) ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ ) {
for ( V_35 = 0 ; V_35 < V_26 ; V_35 ++ )
V_25 [ V_35 ] |= V_31 [ V_11 ] & F_13 ( V_35 , V_37 ) ;
V_37 ++ ;
V_37 &= F_12 ( V_37 , V_26 ) ;
}
#endif
}
static void F_14 ( void * V_41 , unsigned char * V_42 )
{
T_3 * V_43 = V_41 ;
F_15 ( V_43 -> V_44 , V_42 ) ;
F_15 ( V_43 -> V_45 , V_42 ) ;
F_15 ( V_43 -> V_46 , V_42 ) ;
F_15 ( V_43 -> V_47 , V_42 ) ;
}
static void F_16 ( void * V_41 , unsigned char * V_42 )
{
T_4 * V_48 = V_41 ;
F_17 ( V_48 -> V_49 , V_42 ) ;
F_17 ( V_48 -> V_50 , V_42 ) ;
F_17 ( V_48 -> V_51 , V_42 ) ;
F_17 ( V_48 -> V_52 , V_42 ) ;
F_17 ( V_48 -> V_53 , V_42 ) ;
}
static void F_18 ( void * V_41 , unsigned char * V_42 )
{
T_5 * V_54 = V_41 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
F_17 ( V_54 -> V_55 [ V_11 ] , V_42 ) ;
}
}
static void F_19 ( void * V_41 , unsigned char * V_42 )
{
T_6 * V_56 = V_41 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
F_20 ( V_56 -> V_55 [ V_11 ] , V_42 ) ;
}
}
char F_21 ( const T_7 * V_41 )
{
#ifdef F_22
if ( F_23 () )
return 0 ;
#endif
switch ( F_24 ( V_41 ) ) {
case V_57 :
case V_58 :
#ifndef F_25
case V_59 :
case V_60 :
#endif
#ifndef F_26
case V_61 :
case V_62 :
#endif
return 1 ;
default:
return 0 ;
}
}
void F_27 ( const T_7 * V_41 ,
unsigned char * V_42 ,
V_38 * V_63 ,
const unsigned char V_64 [ 13 ] ,
const unsigned char * V_9 ,
V_38 V_65 ,
V_38 V_66 ,
const unsigned char * V_67 ,
unsigned V_68 , char V_69 )
{
union {
double V_70 ;
unsigned char V_71 [ sizeof( V_72 ) ] ;
} V_73 ;
void (* F_28) ( void * V_41 , unsigned char * V_42 );
void (* F_29) ( void * V_41 , const unsigned char * V_74 );
unsigned V_26 , V_75 = 64 ;
unsigned V_76 = 40 , V_77 , V_78 ,
V_79 , V_80 , V_81 ,
V_82 , V_83 , V_84 , V_71 , V_85 , V_86 ;
unsigned int V_87 ;
unsigned char V_88 [ V_89 ] ;
unsigned char V_90 [ V_91 ] ;
unsigned char V_92 [ V_91 ] ;
unsigned char V_93 [ V_30 ] ;
unsigned V_11 , V_35 , V_94 ;
T_7 V_95 ;
unsigned V_96 = 8 ;
char V_97 = 1 ;
F_11 ( V_66 < 1024 * 1024 ) ;
switch ( F_24 ( V_41 ) ) {
case V_57 :
F_30 ( ( T_3 * ) V_73 . V_71 ) ;
F_28 = F_14 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_98 ;
V_26 = 16 ;
V_76 = 48 ;
V_97 = 0 ;
break;
case V_58 :
F_31 ( ( T_4 * ) V_73 . V_71 ) ;
F_28 = F_16 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_99 ;
V_26 = 20 ;
break;
#ifndef F_25
case V_59 :
F_32 ( ( T_5 * ) V_73 . V_71 ) ;
F_28 = F_18 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_100 ;
V_26 = 224 / 8 ;
break;
case V_60 :
F_33 ( ( T_5 * ) V_73 . V_71 ) ;
F_28 = F_18 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_100 ;
V_26 = 32 ;
break;
#endif
#ifndef F_26
case V_61 :
F_34 ( ( T_6 * ) V_73 . V_71 ) ;
F_28 = F_19 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_101 ;
V_26 = 384 / 8 ;
V_75 = 128 ;
V_96 = 16 ;
break;
case V_62 :
F_35 ( ( T_6 * ) V_73 . V_71 ) ;
F_28 = F_19 ;
F_29 =
( void (*) ( void * V_41 , const unsigned char * V_74 ) ) V_101 ;
V_26 = 64 ;
V_75 = 128 ;
V_96 = 16 ;
break;
#endif
default:
F_11 ( 0 ) ;
if ( V_63 )
* V_63 = - 1 ;
return;
}
F_11 ( V_96 <= V_89 ) ;
F_11 ( V_75 <= V_91 ) ;
F_11 ( V_26 <= V_30 ) ;
V_77 = 13 ;
if ( V_69 ) {
V_77 = V_68 + V_76 + 8 +
1 +
2 ;
}
V_78 = V_69 ? 2 : 6 ;
V_79 = V_66 + V_77 ;
V_80 = V_79 - V_26 - 1 ;
V_81 =
( V_80 + 1 + V_96 + V_75 -
1 ) / V_75 ;
V_82 = 0 ;
V_83 = 0 ;
V_84 = V_65 + V_77 - V_26 ;
V_71 = V_84 % V_75 ;
V_85 = V_84 / V_75 ;
V_86 = ( V_84 + V_96 ) / V_75 ;
if ( V_81 > V_78 + ( V_69 ? 1 : 0 ) ) {
V_82 = V_81 - V_78 ;
V_83 = V_75 * V_82 ;
}
V_87 = 8 * V_84 ;
if ( ! V_69 ) {
V_87 += 8 * V_75 ;
memset ( V_90 , 0 , V_75 ) ;
F_11 ( V_68 <= sizeof( V_90 ) ) ;
memcpy ( V_90 , V_67 , V_68 ) ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
V_90 [ V_11 ] ^= 0x36 ;
F_29 ( V_73 . V_71 , V_90 ) ;
}
if ( V_97 ) {
memset ( V_88 , 0 , V_96 - 4 ) ;
V_88 [ V_96 - 4 ] = ( unsigned char ) ( V_87 >> 24 ) ;
V_88 [ V_96 - 3 ] = ( unsigned char ) ( V_87 >> 16 ) ;
V_88 [ V_96 - 2 ] = ( unsigned char ) ( V_87 >> 8 ) ;
V_88 [ V_96 - 1 ] = ( unsigned char ) V_87 ;
} else {
memset ( V_88 , 0 , V_96 ) ;
V_88 [ V_96 - 5 ] = ( unsigned char ) ( V_87 >> 24 ) ;
V_88 [ V_96 - 6 ] = ( unsigned char ) ( V_87 >> 16 ) ;
V_88 [ V_96 - 7 ] = ( unsigned char ) ( V_87 >> 8 ) ;
V_88 [ V_96 - 8 ] = ( unsigned char ) V_87 ;
}
if ( V_83 > 0 ) {
if ( V_69 ) {
unsigned V_102 = V_77 - V_75 ;
F_29 ( V_73 . V_71 , V_64 ) ;
memcpy ( V_92 , V_64 + V_75 , V_102 ) ;
memcpy ( V_92 + V_102 , V_9 , V_75 - V_102 ) ;
F_29 ( V_73 . V_71 , V_92 ) ;
for ( V_11 = 1 ; V_11 < V_83 / V_75 - 1 ; V_11 ++ )
F_29 ( V_73 . V_71 , V_9 + V_75 * V_11 - V_102 ) ;
} else {
memcpy ( V_92 , V_64 , 13 ) ;
memcpy ( V_92 + 13 , V_9 , V_75 - 13 ) ;
F_29 ( V_73 . V_71 , V_92 ) ;
for ( V_11 = 1 ; V_11 < V_83 / V_75 ; V_11 ++ )
F_29 ( V_73 . V_71 , V_9 + V_75 * V_11 - 13 ) ;
}
}
memset ( V_93 , 0 , sizeof( V_93 ) ) ;
for ( V_11 = V_82 ; V_11 <= V_82 + V_78 ;
V_11 ++ ) {
unsigned char V_74 [ V_91 ] ;
unsigned char V_103 = F_13 ( V_11 , V_85 ) ;
unsigned char V_104 = F_13 ( V_11 , V_86 ) ;
for ( V_35 = 0 ; V_35 < V_75 ; V_35 ++ ) {
unsigned char V_24 = 0 , V_105 , V_106 ;
if ( V_83 < V_77 )
V_24 = V_64 [ V_83 ] ;
else if ( V_83 < V_66 + V_77 )
V_24 = V_9 [ V_83 - V_77 ] ;
V_83 ++ ;
V_105 = V_103 & F_7 ( V_35 , V_71 ) ;
V_106 = V_103 & F_7 ( V_35 , V_71 + 1 ) ;
V_24 = F_36 ( V_105 , 0x80 , V_24 ) ;
V_24 = V_24 & ~ V_106 ;
V_24 &= ~ V_104 | V_103 ;
if ( V_35 >= V_75 - V_96 ) {
V_24 = F_36 ( V_104 ,
V_88 [ V_35 -
( V_75 -
V_96 ) ] , V_24 ) ;
}
V_74 [ V_35 ] = V_24 ;
}
F_29 ( V_73 . V_71 , V_74 ) ;
F_28 ( V_73 . V_71 , V_74 ) ;
for ( V_35 = 0 ; V_35 < V_26 ; V_35 ++ )
V_93 [ V_35 ] |= V_74 [ V_35 ] & V_104 ;
}
F_37 ( & V_95 ) ;
F_38 ( & V_95 , V_41 -> V_107 , NULL ) ;
if ( V_69 ) {
memset ( V_90 , 0x5c , V_76 ) ;
F_39 ( & V_95 , V_67 , V_68 ) ;
F_39 ( & V_95 , V_90 , V_76 ) ;
F_39 ( & V_95 , V_93 , V_26 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
V_90 [ V_11 ] ^= 0x6a ;
F_39 ( & V_95 , V_90 , V_75 ) ;
F_39 ( & V_95 , V_93 , V_26 ) ;
}
F_40 ( & V_95 , V_42 , & V_94 ) ;
if ( V_63 )
* V_63 = V_94 ;
F_41 ( & V_95 ) ;
}
void F_42 ( const T_8 * V_108 ,
T_7 * V_109 , const unsigned char * V_9 ,
V_38 V_110 , V_38 V_27 )
{
V_38 V_3 , V_111 , V_112 , V_113 ;
if ( F_43 ( V_108 ) != V_114 )
return;
V_3 = F_44 ( V_109 ) ;
V_111 = V_3 == 64 ? 21 : 29 ;
V_113 = ( V_27 + V_111 ) / V_3 ;
V_112 = ( V_110 + V_111 ) / V_3 ;
F_45 ( V_109 , V_9 ,
( V_113 - V_112 + 1 ) * V_3 ) ;
}
