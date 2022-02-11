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
static int F_19 ( struct V_3 * V_4 , unsigned char T_1 * V_5 ,
unsigned int V_15 , unsigned int V_17 )
{
char * V_31 = ( char * ) & V_4 -> V_30 [ V_15 ] ;
char * V_35 = ( char * ) & V_4 -> V_30 [ V_15 + 1 ] ;
int V_7 , V_36 , V_37 = 0 ;
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
static int F_20 ( struct V_3 * V_4 , unsigned int V_15 ,
unsigned int V_1 )
{
int V_36 ;
union {
T_2 V_38 ;
T_3 V_39 [ 2 ] ;
T_4 V_40 [ 4 ] ;
T_5 V_41 [ 8 ] ;
} V_42 , V_43 ;
unsigned char T_1 * V_6 , * V_5 ;
unsigned long * V_44 = & V_32 -> V_33 . V_44 [ V_15 ] ;
unsigned int V_16 , V_17 ;
V_1 = ( V_1 >> 1 ) & 0x1f ;
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
V_16 = V_45 [ V_1 ] . V_46 ;
V_17 = V_45 [ V_1 ] . V_17 ;
if ( F_10 ( F_6 ( V_4 ) &&
! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) ,
V_5 , V_16 ) ) )
return - V_14 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_21 ( V_32 ) ;
if ( V_17 & V_28 ) {
V_42 . V_38 = 0 ;
switch ( V_1 ) {
case V_47 :
case V_48 :
case V_49 :
V_42 . V_39 [ 0 ] = * V_44 ;
V_42 . V_39 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
case V_50 :
V_42 . V_40 [ 2 ] = * V_44 >> 16 ;
V_42 . V_40 [ 3 ] = V_4 -> V_30 [ V_15 ] >> 16 ;
break;
case V_51 :
V_42 . V_40 [ 2 ] = * V_44 & 0xffff ;
V_42 . V_40 [ 3 ] = V_4 -> V_30 [ V_15 ] & 0xffff ;
break;
case V_52 :
V_42 . V_39 [ 1 ] = * V_44 ;
break;
case V_53 :
V_42 . V_39 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
default:
return - V_54 ;
}
} else {
V_43 . V_38 = V_42 . V_38 = 0 ;
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_11 ( V_43 . V_41 [ 0 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_43 . V_41 [ 1 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_43 . V_41 [ 2 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_43 . V_41 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_11 ( V_43 . V_41 [ 4 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_43 . V_41 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_11 ( V_43 . V_41 [ 6 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_43 . V_41 [ 7 ] , V_6 ++ ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
}
switch ( V_1 ) {
case V_55 :
case V_56 :
case V_57 :
V_42 . V_38 = V_43 . V_38 ;
break;
case V_58 :
V_42 . V_40 [ 0 ] = V_43 . V_40 [ 3 ] ;
V_42 . V_40 [ 2 ] = V_43 . V_40 [ 3 ] ;
break;
case V_59 :
case V_60 :
V_42 . V_40 [ 1 ] = V_43 . V_40 [ 3 ] ;
V_42 . V_40 [ 3 ] = V_43 . V_40 [ 3 ] ;
break;
case V_61 :
V_42 . V_40 [ 0 ] = V_43 . V_40 [ 2 ] ;
V_42 . V_40 [ 2 ] = V_43 . V_40 [ 3 ] ;
break;
case V_62 :
case V_63 :
V_42 . V_40 [ 1 ] = V_43 . V_40 [ 2 ] ;
V_42 . V_40 [ 3 ] = V_43 . V_40 [ 3 ] ;
break;
case V_64 :
V_42 . V_39 [ 0 ] = V_43 . V_39 [ 1 ] ;
V_42 . V_39 [ 1 ] = V_43 . V_39 [ 1 ] ;
break;
case V_65 :
V_42 . V_40 [ 0 ] = V_43 . V_40 [ 2 ] ;
V_42 . V_40 [ 1 ] = V_43 . V_40 [ 2 ] ;
V_42 . V_40 [ 2 ] = V_43 . V_40 [ 3 ] ;
V_42 . V_40 [ 3 ] = V_43 . V_40 [ 3 ] ;
break;
default:
return - V_54 ;
}
}
if ( V_17 & V_27 ) {
switch ( V_17 & 0xf0 ) {
case V_66 :
V_42 . V_38 = F_22 ( V_42 . V_38 ) ;
break;
case V_67 :
V_42 . V_39 [ 0 ] = F_23 ( V_42 . V_39 [ 0 ] ) ;
V_42 . V_39 [ 1 ] = F_23 ( V_42 . V_39 [ 1 ] ) ;
break;
default:
V_42 . V_40 [ 0 ] = F_24 ( V_42 . V_40 [ 0 ] ) ;
V_42 . V_40 [ 1 ] = F_24 ( V_42 . V_40 [ 1 ] ) ;
V_42 . V_40 [ 2 ] = F_24 ( V_42 . V_40 [ 2 ] ) ;
V_42 . V_40 [ 3 ] = F_24 ( V_42 . V_40 [ 3 ] ) ;
break;
}
}
if ( V_17 & V_68 ) {
V_42 . V_39 [ 0 ] = ( V_69 ) V_42 . V_40 [ 1 ] ;
V_42 . V_39 [ 1 ] = ( V_69 ) V_42 . V_40 [ 3 ] ;
}
if ( V_17 & V_28 ) {
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_8 ( V_42 . V_41 [ 0 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_42 . V_41 [ 1 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_42 . V_41 [ 2 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_42 . V_41 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_8 ( V_42 . V_41 [ 4 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_42 . V_41 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_8 ( V_42 . V_41 [ 6 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_42 . V_41 [ 7 ] , V_6 ++ ) ;
}
if ( F_10 ( V_36 ) )
return - V_14 ;
} else {
* V_44 = V_42 . V_39 [ 0 ] ;
V_4 -> V_30 [ V_15 ] = V_42 . V_39 [ 1 ] ;
}
return 1 ;
}
static int F_25 ( unsigned char T_1 * V_5 , unsigned int V_15 ,
unsigned int V_70 , struct V_3 * V_4 ,
unsigned int V_17 , unsigned int V_71 ,
unsigned int V_72 )
{
char * V_73 ;
unsigned long * V_74 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_7 , V_75 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_26 ( V_32 ) ;
if ( V_15 < 32 )
V_73 = ( char * ) & V_32 -> V_33 . V_76 . V_77 [ V_15 ] [ 0 ] ;
else
V_73 = ( char * ) & V_32 -> V_33 . V_78 . V_79 [ V_15 - 32 ] ;
V_74 = ( unsigned long * ) V_73 ;
#ifdef F_13
if ( V_17 & V_27 ) {
V_72 = V_71 ;
V_37 = V_71 - 1 ;
} else {
V_5 += V_71 - V_72 ;
if ( V_71 == 8 )
V_73 += 8 ;
}
#else
if ( V_17 & V_27 )
V_37 = V_72 - 1 ;
#endif
for ( V_75 = 0 ; V_75 < V_71 ; V_75 += V_72 ) {
for ( V_7 = 0 ; V_7 < V_72 ; ++ V_7 ) {
if ( V_17 & V_28 )
V_36 |= F_18 ( V_73 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
else
V_36 |= F_17 ( V_73 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
}
V_73 += V_72 ;
#ifdef F_13
V_5 -= V_72 ;
#else
V_5 += V_72 ;
#endif
}
#ifdef F_27
#define F_28 0
#define F_29 1
#else
#define F_28 1
#define F_29 0
#endif
if ( ! V_36 ) {
if ( V_17 & V_80 )
V_4 -> V_30 [ V_70 ] = V_4 -> V_12 ;
if ( V_17 & V_81 )
V_74 [ F_29 ] = V_74 [ F_28 ] ;
else if ( ! ( V_17 & V_28 ) && ( 8 == V_71 ) )
V_74 [ F_29 ] = 0 ;
} else
return - V_14 ;
return 1 ;
}
int F_30 ( struct V_3 * V_4 )
{
unsigned int V_1 , V_16 , V_17 , V_82 = 0 ;
unsigned int V_15 , V_70 ;
unsigned int V_2 ;
unsigned char T_1 * V_5 ;
unsigned long V_6 , V_18 ;
int V_36 , V_7 ;
union V_42 {
T_2 V_38 ;
double V_83 ;
unsigned char V_41 [ 8 ] ;
struct {
#ifdef F_13
int V_84 ;
unsigned V_85 ;
#else
unsigned V_85 ;
int V_84 ;
#endif
} V_86 ;
struct {
#ifdef F_13
short V_87 ;
unsigned char V_88 [ 6 ] ;
#else
unsigned char V_88 [ 6 ] ;
short V_87 ;
#endif
} V_89 ;
} V_42 ;
F_31 ( V_4 ) ;
V_2 = V_4 -> V_2 ;
if ( F_32 ( V_90 ) ) {
unsigned long V_25 = V_4 -> V_26 ;
if ( F_32 ( V_91 ) && ( V_4 -> V_92 & V_93 ) )
V_25 ^= 4 ;
if ( F_10 ( F_11 ( V_1 ,
( unsigned int T_1 * ) V_25 ) ) )
return - V_14 ;
if ( F_32 ( V_94 ) && ( V_4 -> V_92 & V_93 ) )
V_1 = F_12 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
V_82 = V_1 ;
}
V_15 = ( V_2 >> 5 ) & 0x1f ;
V_70 = V_2 & 0x1f ;
#ifdef F_33
if ( ( V_1 >> 26 ) == 0x4 ) {
F_34 ( V_95 , V_4 ) ;
return F_20 ( V_4 , V_15 , V_1 ) ;
}
#endif
V_1 = ( V_2 >> 10 ) & 0x7f ;
V_1 |= ( V_2 >> 13 ) & 0x60 ;
V_16 = V_96 [ V_1 ] . V_46 ;
V_17 = V_96 [ V_1 ] . V_17 ;
if ( F_2 ( V_82 ) && ( ( V_82 >> 1 ) & 0x3ff ) == 532 ) {
V_16 = 8 ;
V_17 = V_97 + V_27 ;
} else if ( F_2 ( V_82 ) &&
( ( V_82 >> 1 ) & 0x3ff ) == 660 ) {
V_16 = 8 ;
V_17 = V_28 + V_27 ;
}
V_18 = 0 ;
if ( ( V_4 -> V_92 & V_93 ) != ( V_98 & V_93 ) ) {
V_17 ^= V_27 ;
#ifdef F_27
if ( F_32 ( V_91 ) )
V_18 = 7 ;
#endif
}
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
#ifdef F_35
if ( ( V_82 & 0xfc00003e ) == 0x7c000018 ) {
unsigned int V_72 ;
V_15 |= ( V_82 & 0x1 ) << 5 ;
V_16 = 8 ;
if ( V_82 & 0x200 )
V_16 = 16 ;
V_72 = 4 ;
if ( V_82 & 0x80 )
V_72 = 8 ;
V_17 = 0 ;
if ( ( V_4 -> V_92 & V_93 ) != ( V_98 & V_93 ) )
V_17 |= V_27 ;
if ( V_82 & 0x100 )
V_17 |= V_28 ;
if ( V_82 & 0x040 )
V_17 |= V_80 ;
if ( ( V_82 & 0x400 ) == 0 ) {
V_17 |= V_81 ;
V_16 = 8 ;
}
F_34 ( V_99 , V_4 ) ;
return F_25 ( V_5 , V_15 , V_70 , V_4 , V_17 , V_16 , V_72 ) ;
}
#endif
if ( V_1 == V_100 ) {
F_34 ( V_101 , V_4 ) ;
return F_4 ( V_4 , V_5 ) ;
}
if ( F_10 ( V_16 == 0 ) )
return 0 ;
if ( V_17 & V_102 ) {
F_34 ( V_103 , V_4 ) ;
return F_9 ( V_4 , V_5 , V_15 , V_16 ,
V_17 , V_1 , V_18 ) ;
}
if ( F_10 ( F_6 ( V_4 ) &&
! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) ,
V_5 , V_16 ) ) )
return - V_14 ;
if ( V_17 & V_104 ) {
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_36 ( V_32 ) ;
}
if ( ( V_16 == 16 ) ) {
if ( V_17 & V_104 ) {
F_34 ( V_105 , V_4 ) ;
return F_16 ( V_5 , V_15 , V_17 ) ;
} else {
#ifdef F_37
F_34 ( V_106 , V_4 ) ;
return F_19 ( V_4 , V_5 , V_15 , V_17 ) ;
#else
return 0 ;
#endif
}
}
F_34 ( V_107 , V_4 ) ;
if ( ! ( V_17 & V_28 ) ) {
unsigned int V_108 = 0 ;
switch ( V_16 ) {
case 4 :
V_108 = F_38 ( union V_42 , V_86 . V_84 ) ;
break;
case 2 :
V_108 = F_38 ( union V_42 , V_89 . V_87 ) ;
break;
}
V_42 . V_38 = 0 ;
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ )
V_36 |= F_11 ( V_42 . V_41 [ V_108 + V_7 ] ,
F_15 ( V_6 ++ ) ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
} else if ( V_17 & V_104 ) {
V_42 . V_38 = V_32 -> V_33 . V_34 ( V_15 ) ;
if ( V_17 & V_109 ) {
#ifdef F_39
F_40 () ;
F_41 () ;
F_42 ( & V_42 . V_83 , ( float * ) & V_42 . V_86 . V_84 ) ;
F_43 () ;
#else
return 0 ;
#endif
}
} else
V_42 . V_38 = V_4 -> V_30 [ V_15 ] ;
if ( V_17 & V_27 ) {
switch ( V_16 ) {
case 8 :
V_42 . V_38 = F_22 ( V_42 . V_38 ) ;
break;
case 4 :
V_42 . V_86 . V_84 = F_23 ( V_42 . V_86 . V_84 ) ;
break;
case 2 :
V_42 . V_89 . V_87 = F_24 ( V_42 . V_89 . V_87 ) ;
break;
}
}
switch ( V_17 & ~ ( V_80 | V_27 ) ) {
case V_97 + V_68 :
case V_97 + V_104 + V_68 :
if ( V_16 == 2 )
V_42 . V_38 = V_42 . V_89 . V_87 ;
else
V_42 . V_38 = V_42 . V_86 . V_84 ;
break;
case V_97 + V_104 + V_109 :
#ifdef F_39
F_40 () ;
F_41 () ;
F_44 ( ( float * ) & V_42 . V_86 . V_84 , & V_42 . V_83 ) ;
F_43 () ;
#else
return 0 ;
#endif
break;
}
if ( V_17 & V_28 ) {
unsigned int V_108 = 0 ;
switch ( V_16 ) {
case 4 :
V_108 = F_38 ( union V_42 , V_86 . V_84 ) ;
break;
case 2 :
V_108 = F_38 ( union V_42 , V_89 . V_87 ) ;
break;
}
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ )
V_36 |= F_8 ( V_42 . V_41 [ V_108 + V_7 ] ,
F_15 ( V_6 ++ ) ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
} else if ( V_17 & V_104 )
V_32 -> V_33 . V_34 ( V_15 ) = V_42 . V_38 ;
else
V_4 -> V_30 [ V_15 ] = V_42 . V_38 ;
if ( V_17 & V_80 )
V_4 -> V_30 [ V_70 ] = V_4 -> V_12 ;
return 1 ;
}
