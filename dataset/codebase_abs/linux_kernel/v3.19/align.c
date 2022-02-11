static int F_1 ( struct V_1 * V_2 , unsigned char T_1 * V_3 )
{
long T_1 * V_4 ;
int V_5 , V_6 ;
#ifdef F_2
V_6 = V_7 . V_8 ;
#else
V_6 = V_9 ;
#endif
V_4 = ( long T_1 * ) ( V_2 -> V_10 & - V_6 ) ;
if ( F_3 ( V_2 ) && ! F_4 ( V_11 , V_4 , V_6 ) )
return - V_12 ;
for ( V_5 = 0 ; V_5 < V_6 / sizeof( long ) ; ++ V_5 )
if ( F_5 ( 0 , V_4 + V_5 ) )
return - V_12 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char T_1 * V_3 ,
unsigned int V_13 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned long V_17 )
{
unsigned long * V_18 ;
unsigned int V_19 , V_5 , V_20 ;
unsigned long V_4 ;
if ( F_7 ( ( V_14 > 4 ) || ! F_3 ( V_2 ) ) )
return 0 ;
V_19 = 0 ;
if ( V_15 & V_21 ) {
if ( V_15 & V_22 ) {
V_14 = V_2 -> V_23 & 127 ;
if ( V_14 == 0 )
return 1 ;
} else {
unsigned long V_24 = V_2 -> V_25 ^ ( V_17 & 4 ) ;
if ( F_8 ( V_16 ,
( unsigned int T_1 * ) V_24 ) )
return - V_12 ;
if ( V_17 == 0 && ( V_15 & V_26 ) )
V_16 = F_9 ( V_16 ) ;
V_14 = ( V_16 >> 11 ) & 0x1f ;
if ( V_14 == 0 )
V_14 = 32 ;
}
if ( V_14 + V_13 * 4 > 128 ) {
V_19 = V_14 + V_13 * 4 - 128 ;
V_14 = 128 - V_13 * 4 ;
}
#ifdef F_10
V_15 ^= V_26 ;
#endif
} else {
V_14 = ( 32 - V_13 ) * 4 ;
}
if ( ! F_4 ( ( V_15 & V_27 ? V_11 : V_28 ) , V_3 , V_14 + V_19 ) )
return - V_12 ;
V_18 = & V_2 -> V_29 [ V_13 ] ;
V_4 = ( unsigned long ) V_3 ;
V_20 = ( V_15 & V_26 ) ? 3 : 0 ;
if ( ! ( V_15 & V_27 ) ) {
memset ( V_18 , 0 , ( ( V_14 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
if ( V_19 > 0 )
memset ( & V_2 -> V_29 [ 0 ] , 0 ,
( ( V_19 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
for ( V_5 = 0 ; V_5 < V_14 ; ++ V_5 , ++ V_4 )
if ( F_8 ( F_11 ( V_18 , V_5 ^ V_20 ) ,
F_12 ( V_4 ) ) )
return - V_12 ;
if ( V_19 > 0 ) {
V_18 = & V_2 -> V_29 [ 0 ] ;
V_3 += V_14 ;
for ( V_5 = 0 ; V_5 < V_19 ; ++ V_5 , ++ V_4 )
if ( F_8 ( F_11 ( V_18 ,
V_5 ^ V_20 ) ,
F_12 ( V_4 ) ) )
return - V_12 ;
}
} else {
for ( V_5 = 0 ; V_5 < V_14 ; ++ V_5 , ++ V_4 )
if ( F_5 ( F_11 ( V_18 , V_5 ^ V_20 ) ,
F_12 ( V_4 ) ) )
return - V_12 ;
if ( V_19 > 0 ) {
V_18 = & V_2 -> V_29 [ 0 ] ;
V_3 += V_14 ;
for ( V_5 = 0 ; V_5 < V_19 ; ++ V_5 , ++ V_4 )
if ( F_5 ( F_11 ( V_18 ,
V_5 ^ V_20 ) ,
F_12 ( V_4 ) ) )
return - V_12 ;
}
}
return 1 ;
}
static int F_13 ( unsigned char T_1 * V_3 , unsigned int V_13 ,
unsigned int V_15 )
{
char * V_30 = ( char * ) & V_31 -> V_32 . V_33 ( V_13 ) ;
char * V_34 = ( char * ) & V_31 -> V_32 . V_33 ( V_13 + 1 ) ;
int V_5 , V_35 , V_36 = 0 ;
if ( V_13 & 1 )
return 0 ;
if ( V_15 & V_26 )
V_36 = 7 ;
V_35 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( ! ( V_15 & V_27 ) ) {
V_35 |= F_14 ( V_30 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
V_35 |= F_14 ( V_34 [ V_5 ^ V_36 ] , V_3 + V_5 + 8 ) ;
} else {
V_35 |= F_15 ( V_30 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
V_35 |= F_15 ( V_34 [ V_5 ^ V_36 ] , V_3 + V_5 + 8 ) ;
}
}
if ( V_35 )
return - V_12 ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned char T_1 * V_3 ,
unsigned int V_13 , unsigned int V_15 )
{
char * V_30 = ( char * ) & V_2 -> V_29 [ V_13 ] ;
char * V_34 = ( char * ) & V_2 -> V_29 [ V_13 + 1 ] ;
int V_5 , V_35 , V_36 = 0 ;
if ( V_13 & 1 )
return 0 ;
if ( V_15 & V_26 )
V_36 = 7 ;
V_35 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( ! ( V_15 & V_27 ) ) {
V_35 |= F_14 ( V_30 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
V_35 |= F_14 ( V_34 [ V_5 ^ V_36 ] , V_3 + V_5 + 8 ) ;
} else {
V_35 |= F_15 ( V_30 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
V_35 |= F_15 ( V_34 [ V_5 ^ V_36 ] , V_3 + V_5 + 8 ) ;
}
}
if ( V_35 )
return - V_12 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_16 )
{
int V_35 ;
union {
T_2 V_37 ;
T_3 V_38 [ 2 ] ;
T_4 V_39 [ 4 ] ;
T_5 V_40 [ 8 ] ;
} V_41 , V_42 ;
unsigned char T_1 * V_4 , * V_3 ;
unsigned long * V_43 = & V_31 -> V_32 . V_43 [ V_13 ] ;
unsigned int V_14 , V_15 ;
V_16 = ( V_16 >> 1 ) & 0x1f ;
V_3 = ( unsigned char T_1 * ) V_2 -> V_10 ;
V_14 = V_44 [ V_16 ] . V_45 ;
V_15 = V_44 [ V_16 ] . V_15 ;
if ( F_7 ( F_3 ( V_2 ) &&
! F_4 ( ( V_15 & V_27 ? V_11 : V_28 ) ,
V_3 , V_14 ) ) )
return - V_12 ;
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_18 ( V_31 ) ;
if ( V_15 & V_27 ) {
V_41 . V_37 = 0 ;
switch ( V_16 ) {
case V_46 :
case V_47 :
case V_48 :
V_41 . V_38 [ 0 ] = * V_43 ;
V_41 . V_38 [ 1 ] = V_2 -> V_29 [ V_13 ] ;
break;
case V_49 :
V_41 . V_39 [ 2 ] = * V_43 >> 16 ;
V_41 . V_39 [ 3 ] = V_2 -> V_29 [ V_13 ] >> 16 ;
break;
case V_50 :
V_41 . V_39 [ 2 ] = * V_43 & 0xffff ;
V_41 . V_39 [ 3 ] = V_2 -> V_29 [ V_13 ] & 0xffff ;
break;
case V_51 :
V_41 . V_38 [ 1 ] = * V_43 ;
break;
case V_52 :
V_41 . V_38 [ 1 ] = V_2 -> V_29 [ V_13 ] ;
break;
default:
return - V_53 ;
}
} else {
V_42 . V_37 = V_41 . V_37 = 0 ;
V_35 = 0 ;
V_4 = V_3 ;
switch ( V_14 ) {
case 8 :
V_35 |= F_8 ( V_42 . V_40 [ 0 ] , V_4 ++ ) ;
V_35 |= F_8 ( V_42 . V_40 [ 1 ] , V_4 ++ ) ;
V_35 |= F_8 ( V_42 . V_40 [ 2 ] , V_4 ++ ) ;
V_35 |= F_8 ( V_42 . V_40 [ 3 ] , V_4 ++ ) ;
case 4 :
V_35 |= F_8 ( V_42 . V_40 [ 4 ] , V_4 ++ ) ;
V_35 |= F_8 ( V_42 . V_40 [ 5 ] , V_4 ++ ) ;
case 2 :
V_35 |= F_8 ( V_42 . V_40 [ 6 ] , V_4 ++ ) ;
V_35 |= F_8 ( V_42 . V_40 [ 7 ] , V_4 ++ ) ;
if ( F_7 ( V_35 ) )
return - V_12 ;
}
switch ( V_16 ) {
case V_54 :
case V_55 :
case V_56 :
V_41 . V_37 = V_42 . V_37 ;
break;
case V_57 :
V_41 . V_39 [ 0 ] = V_42 . V_39 [ 3 ] ;
V_41 . V_39 [ 2 ] = V_42 . V_39 [ 3 ] ;
break;
case V_58 :
case V_59 :
V_41 . V_39 [ 1 ] = V_42 . V_39 [ 3 ] ;
V_41 . V_39 [ 3 ] = V_42 . V_39 [ 3 ] ;
break;
case V_60 :
V_41 . V_39 [ 0 ] = V_42 . V_39 [ 2 ] ;
V_41 . V_39 [ 2 ] = V_42 . V_39 [ 3 ] ;
break;
case V_61 :
case V_62 :
V_41 . V_39 [ 1 ] = V_42 . V_39 [ 2 ] ;
V_41 . V_39 [ 3 ] = V_42 . V_39 [ 3 ] ;
break;
case V_63 :
V_41 . V_38 [ 0 ] = V_42 . V_38 [ 1 ] ;
V_41 . V_38 [ 1 ] = V_42 . V_38 [ 1 ] ;
break;
case V_64 :
V_41 . V_39 [ 0 ] = V_42 . V_39 [ 2 ] ;
V_41 . V_39 [ 1 ] = V_42 . V_39 [ 2 ] ;
V_41 . V_39 [ 2 ] = V_42 . V_39 [ 3 ] ;
V_41 . V_39 [ 3 ] = V_42 . V_39 [ 3 ] ;
break;
default:
return - V_53 ;
}
}
if ( V_15 & V_26 ) {
switch ( V_15 & 0xf0 ) {
case V_65 :
V_41 . V_37 = F_19 ( V_41 . V_37 ) ;
break;
case V_66 :
V_41 . V_38 [ 0 ] = F_20 ( V_41 . V_38 [ 0 ] ) ;
V_41 . V_38 [ 1 ] = F_20 ( V_41 . V_38 [ 1 ] ) ;
break;
default:
V_41 . V_39 [ 0 ] = F_21 ( V_41 . V_39 [ 0 ] ) ;
V_41 . V_39 [ 1 ] = F_21 ( V_41 . V_39 [ 1 ] ) ;
V_41 . V_39 [ 2 ] = F_21 ( V_41 . V_39 [ 2 ] ) ;
V_41 . V_39 [ 3 ] = F_21 ( V_41 . V_39 [ 3 ] ) ;
break;
}
}
if ( V_15 & V_67 ) {
V_41 . V_38 [ 0 ] = ( V_68 ) V_41 . V_39 [ 1 ] ;
V_41 . V_38 [ 1 ] = ( V_68 ) V_41 . V_39 [ 3 ] ;
}
if ( V_15 & V_27 ) {
V_35 = 0 ;
V_4 = V_3 ;
switch ( V_14 ) {
case 8 :
V_35 |= F_5 ( V_41 . V_40 [ 0 ] , V_4 ++ ) ;
V_35 |= F_5 ( V_41 . V_40 [ 1 ] , V_4 ++ ) ;
V_35 |= F_5 ( V_41 . V_40 [ 2 ] , V_4 ++ ) ;
V_35 |= F_5 ( V_41 . V_40 [ 3 ] , V_4 ++ ) ;
case 4 :
V_35 |= F_5 ( V_41 . V_40 [ 4 ] , V_4 ++ ) ;
V_35 |= F_5 ( V_41 . V_40 [ 5 ] , V_4 ++ ) ;
case 2 :
V_35 |= F_5 ( V_41 . V_40 [ 6 ] , V_4 ++ ) ;
V_35 |= F_5 ( V_41 . V_40 [ 7 ] , V_4 ++ ) ;
}
if ( F_7 ( V_35 ) )
return - V_12 ;
} else {
* V_43 = V_41 . V_38 [ 0 ] ;
V_2 -> V_29 [ V_13 ] = V_41 . V_38 [ 1 ] ;
}
return 1 ;
}
static int F_22 ( unsigned char T_1 * V_3 , unsigned int V_13 ,
unsigned int V_69 , struct V_1 * V_2 ,
unsigned int V_15 , unsigned int V_70 ,
unsigned int V_71 )
{
char * V_72 ;
unsigned long * V_73 ;
int V_35 = 0 ;
int V_36 = 0 ;
int V_5 , V_74 ;
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_23 ( V_31 ) ;
if ( V_13 < 32 )
V_72 = ( char * ) & V_31 -> V_32 . V_75 . V_76 [ V_13 ] [ 0 ] ;
else
V_72 = ( char * ) & V_31 -> V_32 . V_77 . V_78 [ V_13 - 32 ] ;
V_73 = ( unsigned long * ) V_72 ;
#ifdef F_10
if ( V_15 & V_26 ) {
V_71 = V_70 ;
V_36 = V_70 - 1 ;
} else {
V_3 += V_70 - V_71 ;
if ( V_70 == 8 )
V_72 += 8 ;
}
#else
if ( V_15 & V_26 )
V_36 = V_71 - 1 ;
#endif
for ( V_74 = 0 ; V_74 < V_70 ; V_74 += V_71 ) {
for ( V_5 = 0 ; V_5 < V_71 ; ++ V_5 ) {
if ( V_15 & V_27 )
V_35 |= F_15 ( V_72 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
else
V_35 |= F_14 ( V_72 [ V_5 ^ V_36 ] , V_3 + V_5 ) ;
}
V_72 += V_71 ;
#ifdef F_10
V_3 -= V_71 ;
#else
V_3 += V_71 ;
#endif
}
#ifdef F_24
#define F_25 0
#define F_26 1
#else
#define F_25 1
#define F_26 0
#endif
if ( ! V_35 ) {
if ( V_15 & V_79 )
V_2 -> V_29 [ V_69 ] = V_2 -> V_10 ;
if ( V_15 & V_80 )
V_73 [ F_26 ] = V_73 [ F_25 ] ;
else if ( ! ( V_15 & V_27 ) && ( 8 == V_70 ) )
V_73 [ F_26 ] = 0 ;
} else
return - V_12 ;
return 1 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_16 , V_14 , V_15 , V_81 = 0 ;
unsigned int V_13 , V_69 ;
unsigned int V_82 ;
unsigned char T_1 * V_3 ;
unsigned long V_4 , V_17 ;
int V_35 , V_5 ;
union V_41 {
T_2 V_37 ;
double V_83 ;
unsigned char V_40 [ 8 ] ;
struct {
#ifdef F_10
int V_84 ;
unsigned V_85 ;
#else
unsigned V_85 ;
int V_84 ;
#endif
} V_86 ;
struct {
#ifdef F_10
short V_87 ;
unsigned char V_88 [ 6 ] ;
#else
unsigned char V_88 [ 6 ] ;
short V_87 ;
#endif
} V_89 ;
} V_41 ;
F_28 ( V_2 ) ;
V_82 = V_2 -> V_82 ;
if ( F_29 ( V_90 ) ) {
unsigned long V_24 = V_2 -> V_25 ;
if ( F_29 ( V_91 ) && ( V_2 -> V_92 & V_93 ) )
V_24 ^= 4 ;
if ( F_7 ( F_8 ( V_16 ,
( unsigned int T_1 * ) V_24 ) ) )
return - V_12 ;
if ( F_29 ( V_94 ) && ( V_2 -> V_92 & V_93 ) )
V_16 = F_9 ( V_16 ) ;
V_82 = F_30 ( V_16 ) ;
V_81 = V_16 ;
}
V_13 = ( V_82 >> 5 ) & 0x1f ;
V_69 = V_82 & 0x1f ;
#ifdef F_31
if ( ( V_16 >> 26 ) == 0x4 ) {
F_32 ( V_95 , V_2 ) ;
return F_17 ( V_2 , V_13 , V_16 ) ;
}
#endif
V_16 = ( V_82 >> 10 ) & 0x7f ;
V_16 |= ( V_82 >> 13 ) & 0x60 ;
V_14 = V_96 [ V_16 ] . V_45 ;
V_15 = V_96 [ V_16 ] . V_15 ;
if ( F_33 ( V_81 ) && ( ( V_81 >> 1 ) & 0x3ff ) == 532 ) {
V_14 = 8 ;
V_15 = V_97 + V_26 ;
} else if ( F_33 ( V_81 ) &&
( ( V_81 >> 1 ) & 0x3ff ) == 660 ) {
V_14 = 8 ;
V_15 = V_27 + V_26 ;
}
V_17 = 0 ;
if ( ( V_2 -> V_92 & V_93 ) != ( V_98 & V_93 ) ) {
V_15 ^= V_26 ;
#ifdef F_24
if ( F_29 ( V_91 ) )
V_17 = 7 ;
#endif
}
V_3 = ( unsigned char T_1 * ) V_2 -> V_10 ;
#ifdef F_34
if ( ( V_81 & 0xfc00003e ) == 0x7c000018 ) {
unsigned int V_71 ;
V_13 |= ( V_81 & 0x1 ) << 5 ;
V_14 = 8 ;
if ( V_81 & 0x200 )
V_14 = 16 ;
V_71 = 4 ;
if ( V_81 & 0x80 )
V_71 = 8 ;
V_15 = 0 ;
if ( ( V_2 -> V_92 & V_93 ) != ( V_98 & V_93 ) )
V_15 |= V_26 ;
if ( V_81 & 0x100 )
V_15 |= V_27 ;
if ( V_81 & 0x040 )
V_15 |= V_79 ;
if ( ( V_81 & 0x400 ) == 0 ) {
V_15 |= V_80 ;
V_14 = 8 ;
}
F_32 ( V_99 , V_2 ) ;
return F_22 ( V_3 , V_13 , V_69 , V_2 , V_15 , V_14 , V_71 ) ;
}
#endif
if ( V_16 == V_100 ) {
F_32 ( V_101 , V_2 ) ;
return F_1 ( V_2 , V_3 ) ;
}
if ( F_7 ( V_14 == 0 ) )
return 0 ;
if ( V_15 & V_102 ) {
F_32 ( V_103 , V_2 ) ;
return F_6 ( V_2 , V_3 , V_13 , V_14 ,
V_15 , V_16 , V_17 ) ;
}
if ( F_7 ( F_3 ( V_2 ) &&
! F_4 ( ( V_15 & V_27 ? V_11 : V_28 ) ,
V_3 , V_14 ) ) )
return - V_12 ;
if ( V_15 & V_104 ) {
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_35 ( V_31 ) ;
}
if ( V_14 == 16 ) {
if ( V_15 & V_104 ) {
F_32 ( V_105 , V_2 ) ;
return F_13 ( V_3 , V_13 , V_15 ) ;
} else {
#ifdef F_36
F_32 ( V_106 , V_2 ) ;
return F_16 ( V_2 , V_3 , V_13 , V_15 ) ;
#else
return 0 ;
#endif
}
}
F_32 ( V_107 , V_2 ) ;
if ( ! ( V_15 & V_27 ) ) {
unsigned int V_108 = 0 ;
switch ( V_14 ) {
case 4 :
V_108 = F_37 ( union V_41 , V_86 . V_84 ) ;
break;
case 2 :
V_108 = F_37 ( union V_41 , V_89 . V_87 ) ;
break;
}
V_41 . V_37 = 0 ;
V_35 = 0 ;
V_4 = ( unsigned long ) V_3 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
V_35 |= F_8 ( V_41 . V_40 [ V_108 + V_5 ] ,
F_12 ( V_4 ++ ) ) ;
if ( F_7 ( V_35 ) )
return - V_12 ;
} else if ( V_15 & V_104 ) {
V_41 . V_37 = V_31 -> V_32 . V_33 ( V_13 ) ;
if ( V_15 & V_109 ) {
#ifdef F_38
F_39 () ;
F_40 () ;
F_41 ( & V_41 . V_83 , ( float * ) & V_41 . V_86 . V_84 ) ;
F_42 () ;
#else
return 0 ;
#endif
}
} else
V_41 . V_37 = V_2 -> V_29 [ V_13 ] ;
if ( V_15 & V_26 ) {
switch ( V_14 ) {
case 8 :
V_41 . V_37 = F_19 ( V_41 . V_37 ) ;
break;
case 4 :
V_41 . V_86 . V_84 = F_20 ( V_41 . V_86 . V_84 ) ;
break;
case 2 :
V_41 . V_89 . V_87 = F_21 ( V_41 . V_89 . V_87 ) ;
break;
}
}
switch ( V_15 & ~ ( V_79 | V_26 ) ) {
case V_97 + V_67 :
case V_97 + V_104 + V_67 :
if ( V_14 == 2 )
V_41 . V_37 = V_41 . V_89 . V_87 ;
else
V_41 . V_37 = V_41 . V_86 . V_84 ;
break;
case V_97 + V_104 + V_109 :
#ifdef F_38
F_39 () ;
F_40 () ;
F_43 ( ( float * ) & V_41 . V_86 . V_84 , & V_41 . V_83 ) ;
F_42 () ;
#else
return 0 ;
#endif
break;
}
if ( V_15 & V_27 ) {
unsigned int V_108 = 0 ;
switch ( V_14 ) {
case 4 :
V_108 = F_37 ( union V_41 , V_86 . V_84 ) ;
break;
case 2 :
V_108 = F_37 ( union V_41 , V_89 . V_87 ) ;
break;
}
V_35 = 0 ;
V_4 = ( unsigned long ) V_3 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
V_35 |= F_5 ( V_41 . V_40 [ V_108 + V_5 ] ,
F_12 ( V_4 ++ ) ) ;
if ( F_7 ( V_35 ) )
return - V_12 ;
} else if ( V_15 & V_104 )
V_31 -> V_32 . V_33 ( V_13 ) = V_41 . V_37 ;
else
V_2 -> V_29 [ V_13 ] = V_41 . V_37 ;
if ( V_15 & V_79 )
V_2 -> V_29 [ V_69 ] = V_2 -> V_10 ;
return 1 ;
}
