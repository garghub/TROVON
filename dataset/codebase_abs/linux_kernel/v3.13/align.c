static inline unsigned F_1 ( unsigned V_1 )
{
unsigned V_2 ;
V_2 = ( V_1 & 0x03ff0000 ) >> 16 ;
if ( F_2 ( V_1 ) ) {
V_2 |= ( V_1 & 0x00000006 ) << 14 ;
V_2 |= ( V_1 & 0x00000040 ) << 8 ;
V_2 |= ( V_1 & 0x00000780 ) << 3 ;
} else {
V_2 |= ( V_1 & 0x04000000 ) >> 12 ;
V_2 |= ( V_1 & 0x78000000 ) >> 17 ;
if ( F_3 ( V_1 ) )
V_2 |= ( V_1 & 0x00000003 ) << 18 ;
}
return V_2 ;
}
static int F_4 ( struct V_3 * V_4 , unsigned char T_1 * V_5 )
{
long T_1 * V_6 ;
int V_7 , V_8 ;
#ifdef F_5
V_8 = V_9 . V_10 ;
#else
V_8 = V_11 ;
#endif
V_6 = ( long T_1 * ) ( V_4 -> V_12 & - V_8 ) ;
if ( F_6 ( V_4 ) && ! F_7 ( V_13 , V_6 , V_8 ) )
return - V_14 ;
for ( V_7 = 0 ; V_7 < V_8 / sizeof( long ) ; ++ V_7 )
if ( F_8 ( 0 , V_6 + V_7 ) )
return - V_14 ;
return 1 ;
}
static int F_9 ( struct V_3 * V_4 , unsigned char T_1 * V_5 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_1 ,
unsigned long V_18 )
{
unsigned long * V_19 ;
unsigned int V_20 , V_7 , V_21 ;
unsigned long V_6 ;
if ( F_10 ( ( V_16 > 4 ) || ! F_6 ( V_4 ) ) )
return 0 ;
V_20 = 0 ;
if ( V_17 & V_22 ) {
if ( V_17 & V_23 ) {
V_16 = V_4 -> V_24 & 127 ;
if ( V_16 == 0 )
return 1 ;
} else {
unsigned long V_25 = V_4 -> V_26 ^ ( V_18 & 4 ) ;
if ( F_11 ( V_1 ,
( unsigned int T_1 * ) V_25 ) )
return - V_14 ;
if ( V_18 == 0 && ( V_17 & V_27 ) )
V_1 = F_12 ( V_1 ) ;
V_16 = ( V_1 >> 11 ) & 0x1f ;
if ( V_16 == 0 )
V_16 = 32 ;
}
if ( V_16 + V_15 * 4 > 128 ) {
V_20 = V_16 + V_15 * 4 - 128 ;
V_16 = 128 - V_15 * 4 ;
}
#ifdef F_13
V_17 ^= V_27 ;
#endif
} else {
V_16 = ( 32 - V_15 ) * 4 ;
}
if ( ! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) , V_5 , V_16 + V_20 ) )
return - V_14 ;
V_19 = & V_4 -> V_30 [ V_15 ] ;
V_6 = ( unsigned long ) V_5 ;
V_21 = ( V_17 & V_27 ) ? 3 : 0 ;
if ( ! ( V_17 & V_28 ) ) {
memset ( V_19 , 0 , ( ( V_16 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
if ( V_20 > 0 )
memset ( & V_4 -> V_30 [ 0 ] , 0 ,
( ( V_20 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
for ( V_7 = 0 ; V_7 < V_16 ; ++ V_7 , ++ V_6 )
if ( F_11 ( F_14 ( V_19 , V_7 ^ V_21 ) ,
F_15 ( V_6 ) ) )
return - V_14 ;
if ( V_20 > 0 ) {
V_19 = & V_4 -> V_30 [ 0 ] ;
V_5 += V_16 ;
for ( V_7 = 0 ; V_7 < V_20 ; ++ V_7 , ++ V_6 )
if ( F_11 ( F_14 ( V_19 ,
V_7 ^ V_21 ) ,
F_15 ( V_6 ) ) )
return - V_14 ;
}
} else {
for ( V_7 = 0 ; V_7 < V_16 ; ++ V_7 , ++ V_6 )
if ( F_8 ( F_14 ( V_19 , V_7 ^ V_21 ) ,
F_15 ( V_6 ) ) )
return - V_14 ;
if ( V_20 > 0 ) {
V_19 = & V_4 -> V_30 [ 0 ] ;
V_5 += V_16 ;
for ( V_7 = 0 ; V_7 < V_20 ; ++ V_7 , ++ V_6 )
if ( F_8 ( F_14 ( V_19 ,
V_7 ^ V_21 ) ,
F_15 ( V_6 ) ) )
return - V_14 ;
}
}
return 1 ;
}
static int F_16 ( unsigned char T_1 * V_5 , unsigned int V_15 ,
unsigned int V_17 )
{
char * V_31 = ( char * ) & V_32 -> V_33 . V_34 ( V_15 ) ;
char * V_35 = ( char * ) & V_32 -> V_33 . V_34 ( V_15 + 1 ) ;
int V_7 , V_36 , V_37 = 0 ;
if ( ! ( V_17 & V_38 ) )
return 0 ;
if ( V_15 & 1 )
return 0 ;
if ( V_17 & V_27 )
V_37 = 7 ;
V_36 = 0 ;
for ( V_7 = 0 ; V_7 < 8 ; ++ V_7 ) {
if ( ! ( V_17 & V_28 ) ) {
V_36 |= F_17 ( V_31 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
V_36 |= F_17 ( V_35 [ V_7 ^ V_37 ] , V_5 + V_7 + 8 ) ;
} else {
V_36 |= F_18 ( V_31 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
V_36 |= F_18 ( V_35 [ V_7 ^ V_37 ] , V_5 + V_7 + 8 ) ;
}
}
if ( V_36 )
return - V_14 ;
return 1 ;
}
static int F_19 ( struct V_3 * V_4 , unsigned int V_15 ,
unsigned int V_1 )
{
int V_36 ;
union {
T_2 V_39 ;
T_3 V_40 [ 2 ] ;
T_4 V_41 [ 4 ] ;
T_5 V_42 [ 8 ] ;
} V_43 , V_44 ;
unsigned char T_1 * V_6 , * V_5 ;
unsigned long * V_45 = & V_32 -> V_33 . V_45 [ V_15 ] ;
unsigned int V_16 , V_17 ;
V_1 = ( V_1 >> 1 ) & 0x1f ;
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
V_16 = V_46 [ V_1 ] . V_47 ;
V_17 = V_46 [ V_1 ] . V_17 ;
if ( F_10 ( F_6 ( V_4 ) &&
! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) ,
V_5 , V_16 ) ) )
return - V_14 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_20 ( V_32 ) ;
if ( V_17 & V_28 ) {
V_43 . V_39 = 0 ;
switch ( V_1 ) {
case V_48 :
case V_49 :
case V_50 :
V_43 . V_40 [ 0 ] = * V_45 ;
V_43 . V_40 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
case V_51 :
V_43 . V_41 [ 2 ] = * V_45 >> 16 ;
V_43 . V_41 [ 3 ] = V_4 -> V_30 [ V_15 ] >> 16 ;
break;
case V_52 :
V_43 . V_41 [ 2 ] = * V_45 & 0xffff ;
V_43 . V_41 [ 3 ] = V_4 -> V_30 [ V_15 ] & 0xffff ;
break;
case V_53 :
V_43 . V_40 [ 1 ] = * V_45 ;
break;
case V_54 :
V_43 . V_40 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
default:
return - V_55 ;
}
} else {
V_44 . V_39 = V_43 . V_39 = 0 ;
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_11 ( V_44 . V_42 [ 0 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_44 . V_42 [ 1 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_44 . V_42 [ 2 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_44 . V_42 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_11 ( V_44 . V_42 [ 4 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_44 . V_42 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_11 ( V_44 . V_42 [ 6 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_44 . V_42 [ 7 ] , V_6 ++ ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
}
switch ( V_1 ) {
case V_56 :
case V_57 :
case V_58 :
V_43 . V_39 = V_44 . V_39 ;
break;
case V_59 :
V_43 . V_41 [ 0 ] = V_44 . V_41 [ 3 ] ;
V_43 . V_41 [ 2 ] = V_44 . V_41 [ 3 ] ;
break;
case V_60 :
case V_61 :
V_43 . V_41 [ 1 ] = V_44 . V_41 [ 3 ] ;
V_43 . V_41 [ 3 ] = V_44 . V_41 [ 3 ] ;
break;
case V_62 :
V_43 . V_41 [ 0 ] = V_44 . V_41 [ 2 ] ;
V_43 . V_41 [ 2 ] = V_44 . V_41 [ 3 ] ;
break;
case V_63 :
case V_64 :
V_43 . V_41 [ 1 ] = V_44 . V_41 [ 2 ] ;
V_43 . V_41 [ 3 ] = V_44 . V_41 [ 3 ] ;
break;
case V_65 :
V_43 . V_40 [ 0 ] = V_44 . V_40 [ 1 ] ;
V_43 . V_40 [ 1 ] = V_44 . V_40 [ 1 ] ;
break;
case V_66 :
V_43 . V_41 [ 0 ] = V_44 . V_41 [ 2 ] ;
V_43 . V_41 [ 1 ] = V_44 . V_41 [ 2 ] ;
V_43 . V_41 [ 2 ] = V_44 . V_41 [ 3 ] ;
V_43 . V_41 [ 3 ] = V_44 . V_41 [ 3 ] ;
break;
default:
return - V_55 ;
}
}
if ( V_17 & V_27 ) {
switch ( V_17 & 0xf0 ) {
case V_67 :
V_43 . V_39 = F_21 ( V_43 . V_39 ) ;
break;
case V_68 :
V_43 . V_40 [ 0 ] = F_22 ( V_43 . V_40 [ 0 ] ) ;
V_43 . V_40 [ 1 ] = F_22 ( V_43 . V_40 [ 1 ] ) ;
break;
default:
V_43 . V_41 [ 0 ] = F_23 ( V_43 . V_41 [ 0 ] ) ;
V_43 . V_41 [ 1 ] = F_23 ( V_43 . V_41 [ 1 ] ) ;
V_43 . V_41 [ 2 ] = F_23 ( V_43 . V_41 [ 2 ] ) ;
V_43 . V_41 [ 3 ] = F_23 ( V_43 . V_41 [ 3 ] ) ;
break;
}
}
if ( V_17 & V_69 ) {
V_43 . V_40 [ 0 ] = ( V_70 ) V_43 . V_41 [ 1 ] ;
V_43 . V_40 [ 1 ] = ( V_70 ) V_43 . V_41 [ 3 ] ;
}
if ( V_17 & V_28 ) {
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_8 ( V_43 . V_42 [ 0 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_43 . V_42 [ 1 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_43 . V_42 [ 2 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_43 . V_42 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_8 ( V_43 . V_42 [ 4 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_43 . V_42 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_8 ( V_43 . V_42 [ 6 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_43 . V_42 [ 7 ] , V_6 ++ ) ;
}
if ( F_10 ( V_36 ) )
return - V_14 ;
} else {
* V_45 = V_43 . V_40 [ 0 ] ;
V_4 -> V_30 [ V_15 ] = V_43 . V_40 [ 1 ] ;
}
return 1 ;
}
static int F_24 ( unsigned char T_1 * V_5 , unsigned int V_15 ,
unsigned int V_71 , struct V_3 * V_4 ,
unsigned int V_17 , unsigned int V_72 ,
unsigned int V_73 )
{
char * V_74 ;
unsigned long * V_75 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_7 , V_76 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_25 ( V_32 ) ;
if ( V_15 < 32 )
V_74 = ( char * ) & V_32 -> V_33 . V_77 . V_78 [ V_15 ] [ 0 ] ;
else
V_74 = ( char * ) & V_32 -> V_33 . V_79 . V_80 [ V_15 - 32 ] ;
V_75 = ( unsigned long * ) V_74 ;
#ifdef F_13
if ( V_17 & V_27 ) {
V_73 = V_72 ;
V_37 = V_72 - 1 ;
} else {
V_5 += V_72 - V_73 ;
if ( V_72 == 8 )
V_74 += 8 ;
}
#else
if ( V_17 & V_27 )
V_37 = V_73 - 1 ;
#endif
for ( V_76 = 0 ; V_76 < V_72 ; V_76 += V_73 ) {
for ( V_7 = 0 ; V_7 < V_73 ; ++ V_7 ) {
if ( V_17 & V_28 )
V_36 |= F_18 ( V_74 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
else
V_36 |= F_17 ( V_74 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
}
V_74 += V_73 ;
#ifdef F_13
V_5 -= V_73 ;
#else
V_5 += V_73 ;
#endif
}
#ifdef F_26
#define F_27 0
#define F_28 1
#else
#define F_27 1
#define F_28 0
#endif
if ( ! V_36 ) {
if ( V_17 & V_81 )
V_4 -> V_30 [ V_71 ] = V_4 -> V_12 ;
if ( V_17 & V_82 )
V_75 [ F_28 ] = V_75 [ F_27 ] ;
else if ( ! ( V_17 & V_28 ) && ( 8 == V_72 ) )
V_75 [ F_28 ] = 0 ;
} else
return - V_14 ;
return 1 ;
}
int F_29 ( struct V_3 * V_4 )
{
unsigned int V_1 , V_16 , V_17 , V_83 = 0 ;
unsigned int V_15 , V_71 ;
unsigned int V_2 ;
unsigned char T_1 * V_5 ;
unsigned long V_6 , V_18 ;
int V_36 , V_7 ;
union V_43 {
T_2 V_39 ;
double V_84 ;
unsigned char V_42 [ 8 ] ;
struct {
#ifdef F_13
int V_85 ;
unsigned V_86 ;
#else
unsigned V_86 ;
int V_85 ;
#endif
} V_87 ;
struct {
#ifdef F_13
short V_88 ;
unsigned char V_89 [ 6 ] ;
#else
unsigned char V_89 [ 6 ] ;
short V_88 ;
#endif
} V_90 ;
} V_43 ;
F_30 ( V_4 ) ;
V_2 = V_4 -> V_2 ;
if ( F_31 ( V_91 ) ) {
unsigned long V_25 = V_4 -> V_26 ;
if ( F_31 ( V_92 ) && ( V_4 -> V_93 & V_94 ) )
V_25 ^= 4 ;
if ( F_10 ( F_11 ( V_1 ,
( unsigned int T_1 * ) V_25 ) ) )
return - V_14 ;
if ( F_31 ( V_95 ) && ( V_4 -> V_93 & V_94 ) )
V_1 = F_12 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
V_83 = V_1 ;
}
V_15 = ( V_2 >> 5 ) & 0x1f ;
V_71 = V_2 & 0x1f ;
#ifdef F_32
if ( ( V_1 >> 26 ) == 0x4 ) {
F_33 ( V_96 , V_4 ) ;
return F_19 ( V_4 , V_15 , V_1 ) ;
}
#endif
V_1 = ( V_2 >> 10 ) & 0x7f ;
V_1 |= ( V_2 >> 13 ) & 0x60 ;
V_16 = V_97 [ V_1 ] . V_47 ;
V_17 = V_97 [ V_1 ] . V_17 ;
if ( F_2 ( V_83 ) && ( ( V_83 >> 1 ) & 0x3ff ) == 532 ) {
V_16 = 8 ;
V_17 = V_98 + V_27 ;
} else if ( F_2 ( V_83 ) &&
( ( V_83 >> 1 ) & 0x3ff ) == 660 ) {
V_16 = 8 ;
V_17 = V_28 + V_27 ;
}
V_18 = 0 ;
if ( ( V_4 -> V_93 & V_94 ) != ( V_99 & V_94 ) ) {
V_17 ^= V_27 ;
#ifdef F_26
if ( F_31 ( V_92 ) )
V_18 = 7 ;
#endif
}
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
#ifdef F_34
if ( ( V_83 & 0xfc00003e ) == 0x7c000018 ) {
unsigned int V_73 ;
V_15 |= ( V_83 & 0x1 ) << 5 ;
V_16 = 8 ;
if ( V_83 & 0x200 )
V_16 = 16 ;
V_73 = 4 ;
if ( V_83 & 0x80 )
V_73 = 8 ;
V_17 = 0 ;
if ( ( V_4 -> V_93 & V_94 ) != ( V_99 & V_94 ) )
V_17 |= V_27 ;
if ( V_83 & 0x100 )
V_17 |= V_28 ;
if ( V_83 & 0x040 )
V_17 |= V_81 ;
if ( ( V_83 & 0x400 ) == 0 ) {
V_17 |= V_82 ;
V_16 = 8 ;
}
F_33 ( V_100 , V_4 ) ;
return F_24 ( V_5 , V_15 , V_71 , V_4 , V_17 , V_16 , V_73 ) ;
}
#endif
if ( V_1 == V_101 ) {
F_33 ( V_102 , V_4 ) ;
return F_4 ( V_4 , V_5 ) ;
}
if ( F_10 ( V_16 == 0 ) )
return 0 ;
if ( V_17 & V_103 ) {
F_33 ( V_104 , V_4 ) ;
return F_9 ( V_4 , V_5 , V_15 , V_16 ,
V_17 , V_1 , V_18 ) ;
}
if ( F_10 ( F_6 ( V_4 ) &&
! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) ,
V_5 , V_16 ) ) )
return - V_14 ;
if ( V_17 & V_38 ) {
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_35 ( V_32 ) ;
}
if ( V_16 == 16 ) {
F_33 ( V_105 , V_4 ) ;
return F_16 ( V_5 , V_15 , V_17 ) ;
}
F_33 ( V_106 , V_4 ) ;
if ( ! ( V_17 & V_28 ) ) {
unsigned int V_107 = 0 ;
switch ( V_16 ) {
case 4 :
V_107 = F_36 ( union V_43 , V_87 . V_85 ) ;
break;
case 2 :
V_107 = F_36 ( union V_43 , V_90 . V_88 ) ;
break;
}
V_43 . V_39 = 0 ;
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ )
V_36 |= F_11 ( V_43 . V_42 [ V_107 + V_7 ] ,
F_15 ( V_6 ++ ) ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
} else if ( V_17 & V_38 ) {
V_43 . V_39 = V_32 -> V_33 . V_34 ( V_15 ) ;
if ( V_17 & V_108 ) {
#ifdef F_37
F_38 () ;
F_39 () ;
F_40 ( & V_43 . V_84 , ( float * ) & V_43 . V_87 . V_85 ) ;
F_41 () ;
#else
return 0 ;
#endif
}
} else
V_43 . V_39 = V_4 -> V_30 [ V_15 ] ;
if ( V_17 & V_27 ) {
switch ( V_16 ) {
case 8 :
V_43 . V_39 = F_21 ( V_43 . V_39 ) ;
break;
case 4 :
V_43 . V_87 . V_85 = F_22 ( V_43 . V_87 . V_85 ) ;
break;
case 2 :
V_43 . V_90 . V_88 = F_23 ( V_43 . V_90 . V_88 ) ;
break;
}
}
switch ( V_17 & ~ ( V_81 | V_27 ) ) {
case V_98 + V_69 :
case V_98 + V_38 + V_69 :
if ( V_16 == 2 )
V_43 . V_39 = V_43 . V_90 . V_88 ;
else
V_43 . V_39 = V_43 . V_87 . V_85 ;
break;
case V_98 + V_38 + V_108 :
#ifdef F_37
F_38 () ;
F_39 () ;
F_42 ( ( float * ) & V_43 . V_87 . V_85 , & V_43 . V_84 ) ;
F_41 () ;
#else
return 0 ;
#endif
break;
}
if ( V_17 & V_28 ) {
unsigned int V_107 = 0 ;
switch ( V_16 ) {
case 4 :
V_107 = F_36 ( union V_43 , V_87 . V_85 ) ;
break;
case 2 :
V_107 = F_36 ( union V_43 , V_90 . V_88 ) ;
break;
}
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ )
V_36 |= F_8 ( V_43 . V_42 [ V_107 + V_7 ] ,
F_15 ( V_6 ++ ) ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
} else if ( V_17 & V_38 )
V_32 -> V_33 . V_34 ( V_15 ) = V_43 . V_39 ;
else
V_4 -> V_30 [ V_15 ] = V_43 . V_39 ;
if ( V_17 & V_81 )
V_4 -> V_30 [ V_71 ] = V_4 -> V_12 ;
return 1 ;
}
