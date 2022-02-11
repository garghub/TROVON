static int F_1 ( struct V_1 * V_2 , unsigned char T_1 * V_3 )
{
long T_1 * V_4 ;
int V_5 , V_6 ;
#ifdef F_2
V_6 = V_7 . V_8 . V_9 ;
#else
V_6 = V_10 ;
#endif
V_4 = ( long T_1 * ) ( V_2 -> V_11 & - V_6 ) ;
if ( F_3 ( V_2 ) && ! F_4 ( V_12 , V_4 , V_6 ) )
return - V_13 ;
for ( V_5 = 0 ; V_5 < V_6 / sizeof( long ) ; ++ V_5 )
if ( F_5 ( 0 , V_4 + V_5 ) )
return - V_13 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char T_1 * V_3 ,
unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_17 ,
unsigned long V_18 )
{
unsigned long * V_19 ;
unsigned int V_20 , V_5 , V_21 ;
unsigned long V_4 ;
if ( F_7 ( ( V_15 > 4 ) || ! F_3 ( V_2 ) ) )
return 0 ;
V_20 = 0 ;
if ( V_16 & V_22 ) {
if ( V_16 & V_23 ) {
V_15 = V_2 -> V_24 & 127 ;
if ( V_15 == 0 )
return 1 ;
} else {
unsigned long V_25 = V_2 -> V_26 ^ ( V_18 & 4 ) ;
if ( F_8 ( V_17 ,
( unsigned int T_1 * ) V_25 ) )
return - V_13 ;
if ( V_18 == 0 && ( V_16 & V_27 ) )
V_17 = F_9 ( V_17 ) ;
V_15 = ( V_17 >> 11 ) & 0x1f ;
if ( V_15 == 0 )
V_15 = 32 ;
}
if ( V_15 + V_14 * 4 > 128 ) {
V_20 = V_15 + V_14 * 4 - 128 ;
V_15 = 128 - V_14 * 4 ;
}
#ifdef F_10
V_16 ^= V_27 ;
#endif
} else {
V_15 = ( 32 - V_14 ) * 4 ;
}
if ( ! F_4 ( ( V_16 & V_28 ? V_12 : V_29 ) , V_3 , V_15 + V_20 ) )
return - V_13 ;
V_19 = & V_2 -> V_30 [ V_14 ] ;
V_4 = ( unsigned long ) V_3 ;
V_21 = ( V_16 & V_27 ) ? 3 : 0 ;
if ( ! ( V_16 & V_28 ) ) {
memset ( V_19 , 0 , ( ( V_15 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
if ( V_20 > 0 )
memset ( & V_2 -> V_30 [ 0 ] , 0 ,
( ( V_20 + 3 ) / 4 ) * sizeof( unsigned long ) ) ;
for ( V_5 = 0 ; V_5 < V_15 ; ++ V_5 , ++ V_4 )
if ( F_8 ( F_11 ( V_19 , V_5 ^ V_21 ) ,
F_12 ( V_4 ) ) )
return - V_13 ;
if ( V_20 > 0 ) {
V_19 = & V_2 -> V_30 [ 0 ] ;
V_3 += V_15 ;
for ( V_5 = 0 ; V_5 < V_20 ; ++ V_5 , ++ V_4 )
if ( F_8 ( F_11 ( V_19 ,
V_5 ^ V_21 ) ,
F_12 ( V_4 ) ) )
return - V_13 ;
}
} else {
for ( V_5 = 0 ; V_5 < V_15 ; ++ V_5 , ++ V_4 )
if ( F_5 ( F_11 ( V_19 , V_5 ^ V_21 ) ,
F_12 ( V_4 ) ) )
return - V_13 ;
if ( V_20 > 0 ) {
V_19 = & V_2 -> V_30 [ 0 ] ;
V_3 += V_15 ;
for ( V_5 = 0 ; V_5 < V_20 ; ++ V_5 , ++ V_4 )
if ( F_5 ( F_11 ( V_19 ,
V_5 ^ V_21 ) ,
F_12 ( V_4 ) ) )
return - V_13 ;
}
}
return 1 ;
}
static int F_13 ( unsigned char T_1 * V_3 , unsigned int V_14 ,
unsigned int V_16 )
{
char * V_31 = ( char * ) & V_32 -> V_33 . V_34 ( V_14 ) ;
char * V_35 = ( char * ) & V_32 -> V_33 . V_34 ( V_14 + 1 ) ;
int V_5 , V_36 , V_37 = 0 ;
if ( V_14 & 1 )
return 0 ;
if ( V_16 & V_27 )
V_37 = 7 ;
V_36 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( ! ( V_16 & V_28 ) ) {
V_36 |= F_14 ( V_31 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
V_36 |= F_14 ( V_35 [ V_5 ^ V_37 ] , V_3 + V_5 + 8 ) ;
} else {
V_36 |= F_15 ( V_31 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
V_36 |= F_15 ( V_35 [ V_5 ^ V_37 ] , V_3 + V_5 + 8 ) ;
}
}
if ( V_36 )
return - V_13 ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned char T_1 * V_3 ,
unsigned int V_14 , unsigned int V_16 )
{
char * V_31 = ( char * ) & V_2 -> V_30 [ V_14 ] ;
char * V_35 = ( char * ) & V_2 -> V_30 [ V_14 + 1 ] ;
int V_5 , V_36 , V_37 = 0 ;
if ( V_14 & 1 )
return 0 ;
if ( V_16 & V_27 )
V_37 = 7 ;
V_36 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( ! ( V_16 & V_28 ) ) {
V_36 |= F_14 ( V_31 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
V_36 |= F_14 ( V_35 [ V_5 ^ V_37 ] , V_3 + V_5 + 8 ) ;
} else {
V_36 |= F_15 ( V_31 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
V_36 |= F_15 ( V_35 [ V_5 ^ V_37 ] , V_3 + V_5 + 8 ) ;
}
}
if ( V_36 )
return - V_13 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_17 )
{
int V_36 ;
union {
T_2 V_38 ;
T_3 V_39 [ 2 ] ;
T_4 V_40 [ 4 ] ;
T_5 V_41 [ 8 ] ;
} V_42 , V_43 ;
unsigned char T_1 * V_4 , * V_3 ;
unsigned long * V_44 = & V_32 -> V_33 . V_44 [ V_14 ] ;
unsigned int V_15 , V_16 ;
V_17 = ( V_17 >> 1 ) & 0x1f ;
V_3 = ( unsigned char T_1 * ) V_2 -> V_11 ;
V_15 = V_45 [ V_17 ] . V_46 ;
V_16 = V_45 [ V_17 ] . V_16 ;
if ( F_7 ( F_3 ( V_2 ) &&
! F_4 ( ( V_16 & V_28 ? V_12 : V_29 ) ,
V_3 , V_15 ) ) )
return - V_13 ;
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_18 ( V_32 ) ;
if ( V_16 & V_28 ) {
V_42 . V_38 = 0 ;
switch ( V_17 ) {
case V_47 :
case V_48 :
case V_49 :
V_42 . V_39 [ 0 ] = * V_44 ;
V_42 . V_39 [ 1 ] = V_2 -> V_30 [ V_14 ] ;
break;
case V_50 :
V_42 . V_40 [ 2 ] = * V_44 >> 16 ;
V_42 . V_40 [ 3 ] = V_2 -> V_30 [ V_14 ] >> 16 ;
break;
case V_51 :
V_42 . V_40 [ 2 ] = * V_44 & 0xffff ;
V_42 . V_40 [ 3 ] = V_2 -> V_30 [ V_14 ] & 0xffff ;
break;
case V_52 :
V_42 . V_39 [ 1 ] = * V_44 ;
break;
case V_53 :
V_42 . V_39 [ 1 ] = V_2 -> V_30 [ V_14 ] ;
break;
default:
return - V_54 ;
}
} else {
V_43 . V_38 = V_42 . V_38 = 0 ;
V_36 = 0 ;
V_4 = V_3 ;
switch ( V_15 ) {
case 8 :
V_36 |= F_8 ( V_43 . V_41 [ 0 ] , V_4 ++ ) ;
V_36 |= F_8 ( V_43 . V_41 [ 1 ] , V_4 ++ ) ;
V_36 |= F_8 ( V_43 . V_41 [ 2 ] , V_4 ++ ) ;
V_36 |= F_8 ( V_43 . V_41 [ 3 ] , V_4 ++ ) ;
case 4 :
V_36 |= F_8 ( V_43 . V_41 [ 4 ] , V_4 ++ ) ;
V_36 |= F_8 ( V_43 . V_41 [ 5 ] , V_4 ++ ) ;
case 2 :
V_36 |= F_8 ( V_43 . V_41 [ 6 ] , V_4 ++ ) ;
V_36 |= F_8 ( V_43 . V_41 [ 7 ] , V_4 ++ ) ;
if ( F_7 ( V_36 ) )
return - V_13 ;
}
switch ( V_17 ) {
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
if ( V_16 & V_27 ) {
switch ( V_16 & 0xf0 ) {
case V_66 :
V_42 . V_38 = F_19 ( V_42 . V_38 ) ;
break;
case V_67 :
V_42 . V_39 [ 0 ] = F_20 ( V_42 . V_39 [ 0 ] ) ;
V_42 . V_39 [ 1 ] = F_20 ( V_42 . V_39 [ 1 ] ) ;
break;
default:
V_42 . V_40 [ 0 ] = F_21 ( V_42 . V_40 [ 0 ] ) ;
V_42 . V_40 [ 1 ] = F_21 ( V_42 . V_40 [ 1 ] ) ;
V_42 . V_40 [ 2 ] = F_21 ( V_42 . V_40 [ 2 ] ) ;
V_42 . V_40 [ 3 ] = F_21 ( V_42 . V_40 [ 3 ] ) ;
break;
}
}
if ( V_16 & V_68 ) {
V_42 . V_39 [ 0 ] = ( V_69 ) V_42 . V_40 [ 1 ] ;
V_42 . V_39 [ 1 ] = ( V_69 ) V_42 . V_40 [ 3 ] ;
}
if ( V_16 & V_28 ) {
V_36 = 0 ;
V_4 = V_3 ;
switch ( V_15 ) {
case 8 :
V_36 |= F_5 ( V_42 . V_41 [ 0 ] , V_4 ++ ) ;
V_36 |= F_5 ( V_42 . V_41 [ 1 ] , V_4 ++ ) ;
V_36 |= F_5 ( V_42 . V_41 [ 2 ] , V_4 ++ ) ;
V_36 |= F_5 ( V_42 . V_41 [ 3 ] , V_4 ++ ) ;
case 4 :
V_36 |= F_5 ( V_42 . V_41 [ 4 ] , V_4 ++ ) ;
V_36 |= F_5 ( V_42 . V_41 [ 5 ] , V_4 ++ ) ;
case 2 :
V_36 |= F_5 ( V_42 . V_41 [ 6 ] , V_4 ++ ) ;
V_36 |= F_5 ( V_42 . V_41 [ 7 ] , V_4 ++ ) ;
}
if ( F_7 ( V_36 ) )
return - V_13 ;
} else {
* V_44 = V_42 . V_39 [ 0 ] ;
V_2 -> V_30 [ V_14 ] = V_42 . V_39 [ 1 ] ;
}
return 1 ;
}
static int F_22 ( unsigned char T_1 * V_3 , unsigned int V_14 ,
unsigned int V_70 , struct V_1 * V_2 ,
unsigned int V_16 , unsigned int V_71 ,
unsigned int V_72 )
{
char * V_73 ;
unsigned long * V_74 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_5 , V_75 ;
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_23 ( V_32 ) ;
if ( V_14 < 32 )
V_73 = ( char * ) & V_32 -> V_33 . V_76 . V_77 [ V_14 ] [ 0 ] ;
else
V_73 = ( char * ) & V_32 -> V_33 . V_78 . V_79 [ V_14 - 32 ] ;
V_74 = ( unsigned long * ) V_73 ;
#ifdef F_10
if ( V_16 & V_27 ) {
V_72 = V_71 ;
V_37 = V_71 - 1 ;
} else {
V_3 += V_71 - V_72 ;
if ( V_71 == 8 )
V_73 += 8 ;
}
#else
if ( V_16 & V_27 )
V_37 = V_72 - 1 ;
#endif
for ( V_75 = 0 ; V_75 < V_71 ; V_75 += V_72 ) {
for ( V_5 = 0 ; V_5 < V_72 ; ++ V_5 ) {
if ( V_16 & V_28 )
V_36 |= F_15 ( V_73 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
else
V_36 |= F_14 ( V_73 [ V_5 ^ V_37 ] , V_3 + V_5 ) ;
}
V_73 += V_72 ;
#ifdef F_10
V_3 -= V_72 ;
#else
V_3 += V_72 ;
#endif
}
#ifdef F_24
#define F_25 0
#define F_26 1
#else
#define F_25 1
#define F_26 0
#endif
if ( ! V_36 ) {
if ( V_16 & V_80 )
V_2 -> V_30 [ V_70 ] = V_2 -> V_11 ;
if ( V_16 & V_81 )
V_74 [ F_26 ] = V_74 [ F_25 ] ;
else if ( ! ( V_16 & V_28 ) && ( 8 == V_71 ) )
V_74 [ F_26 ] = 0 ;
} else
return - V_13 ;
return 1 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_17 , V_15 , V_16 , V_82 = 0 ;
unsigned int V_14 , V_70 ;
unsigned int V_83 ;
unsigned char T_1 * V_3 ;
unsigned long V_4 , V_18 ;
int V_36 , V_5 ;
union V_42 {
T_2 V_38 ;
double V_84 ;
unsigned char V_41 [ 8 ] ;
struct {
#ifdef F_10
int V_85 ;
unsigned V_86 ;
#else
unsigned V_86 ;
int V_85 ;
#endif
} V_87 ;
struct {
#ifdef F_10
short V_88 ;
unsigned char V_89 [ 6 ] ;
#else
unsigned char V_89 [ 6 ] ;
short V_88 ;
#endif
} V_90 ;
} V_42 ;
F_28 ( V_2 ) ;
V_83 = V_2 -> V_83 ;
if ( F_29 ( V_91 ) ) {
unsigned long V_25 = V_2 -> V_26 ;
if ( F_29 ( V_92 ) && ( V_2 -> V_93 & V_94 ) )
V_25 ^= 4 ;
if ( F_7 ( F_8 ( V_17 ,
( unsigned int T_1 * ) V_25 ) ) )
return - V_13 ;
if ( F_29 ( V_95 ) && ( V_2 -> V_93 & V_94 ) )
V_17 = F_9 ( V_17 ) ;
V_83 = F_30 ( V_17 ) ;
V_82 = V_17 ;
}
V_14 = ( V_83 >> 5 ) & 0x1f ;
V_70 = V_83 & 0x1f ;
#ifdef F_31
if ( ( V_17 >> 26 ) == 0x4 ) {
F_32 ( V_96 , V_2 ) ;
return F_17 ( V_2 , V_14 , V_17 ) ;
}
#endif
V_17 = ( V_83 >> 10 ) & 0x7f ;
V_17 |= ( V_83 >> 13 ) & 0x60 ;
V_15 = V_97 [ V_17 ] . V_46 ;
V_16 = V_97 [ V_17 ] . V_16 ;
if ( F_33 ( V_82 ) ) {
switch ( F_34 ( V_82 ) ) {
case 532 :
V_15 = 8 ;
V_16 = V_98 + V_27 ;
break;
case 660 :
V_15 = 8 ;
V_16 = V_28 + V_27 ;
break;
case 20 :
case 84 :
case 116 :
case 276 :
return 0 ;
}
}
V_18 = 0 ;
if ( ( V_2 -> V_93 & V_94 ) != ( V_99 & V_94 ) ) {
V_16 ^= V_27 ;
#ifdef F_24
if ( F_29 ( V_92 ) )
V_18 = 7 ;
#endif
}
V_3 = ( unsigned char T_1 * ) V_2 -> V_11 ;
#ifdef F_35
if ( ( V_82 & 0xfc00003e ) == 0x7c000018 ) {
unsigned int V_72 ;
V_14 |= ( V_82 & 0x1 ) << 5 ;
V_15 = 8 ;
if ( V_82 & 0x200 )
V_15 = 16 ;
V_72 = 4 ;
if ( V_82 & 0x80 )
V_72 = 8 ;
V_16 = 0 ;
if ( ( V_2 -> V_93 & V_94 ) != ( V_99 & V_94 ) )
V_16 |= V_27 ;
if ( V_82 & 0x100 )
V_16 |= V_28 ;
if ( V_82 & 0x040 )
V_16 |= V_80 ;
if ( ( V_82 & 0x400 ) == 0 ) {
V_16 |= V_81 ;
V_15 = 8 ;
}
F_32 ( V_100 , V_2 ) ;
return F_22 ( V_3 , V_14 , V_70 , V_2 , V_16 , V_15 , V_72 ) ;
}
#endif
if ( ( V_82 & 0xfc0006fe ) == V_101 )
return - V_102 ;
if ( V_17 == V_103 ) {
F_32 ( V_104 , V_2 ) ;
return F_1 ( V_2 , V_3 ) ;
}
if ( F_7 ( V_15 == 0 ) )
return 0 ;
if ( V_16 & V_105 ) {
F_32 ( V_106 , V_2 ) ;
return F_6 ( V_2 , V_3 , V_14 , V_15 ,
V_16 , V_17 , V_18 ) ;
}
if ( F_7 ( F_3 ( V_2 ) &&
! F_4 ( ( V_16 & V_28 ? V_12 : V_29 ) ,
V_3 , V_15 ) ) )
return - V_13 ;
if ( V_16 & V_107 ) {
if ( F_7 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_36 ( V_32 ) ;
}
if ( V_15 == 16 ) {
if ( V_16 & V_107 ) {
F_32 ( V_108 , V_2 ) ;
return F_13 ( V_3 , V_14 , V_16 ) ;
} else {
#ifdef F_37
F_32 ( V_109 , V_2 ) ;
return F_16 ( V_2 , V_3 , V_14 , V_16 ) ;
#else
return 0 ;
#endif
}
}
F_32 ( V_110 , V_2 ) ;
if ( ! ( V_16 & V_28 ) ) {
unsigned int V_111 = 0 ;
switch ( V_15 ) {
case 4 :
V_111 = F_38 ( union V_42 , V_87 . V_85 ) ;
break;
case 2 :
V_111 = F_38 ( union V_42 , V_90 . V_88 ) ;
break;
}
V_42 . V_38 = 0 ;
V_36 = 0 ;
V_4 = ( unsigned long ) V_3 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
V_36 |= F_8 ( V_42 . V_41 [ V_111 + V_5 ] ,
F_12 ( V_4 ++ ) ) ;
if ( F_7 ( V_36 ) )
return - V_13 ;
} else if ( V_16 & V_107 ) {
V_42 . V_38 = V_32 -> V_33 . V_34 ( V_14 ) ;
if ( V_16 & V_112 ) {
#ifdef F_39
F_40 () ;
F_41 () ;
F_42 ( & V_42 . V_84 , ( float * ) & V_42 . V_87 . V_85 ) ;
F_43 () ;
F_44 () ;
#else
return 0 ;
#endif
}
} else
V_42 . V_38 = V_2 -> V_30 [ V_14 ] ;
if ( V_16 & V_27 ) {
switch ( V_15 ) {
case 8 :
V_42 . V_38 = F_19 ( V_42 . V_38 ) ;
break;
case 4 :
V_42 . V_87 . V_85 = F_20 ( V_42 . V_87 . V_85 ) ;
break;
case 2 :
V_42 . V_90 . V_88 = F_21 ( V_42 . V_90 . V_88 ) ;
break;
}
}
switch ( V_16 & ~ ( V_80 | V_27 ) ) {
case V_98 + V_68 :
case V_98 + V_107 + V_68 :
if ( V_15 == 2 )
V_42 . V_38 = V_42 . V_90 . V_88 ;
else
V_42 . V_38 = V_42 . V_87 . V_85 ;
break;
case V_98 + V_107 + V_112 :
#ifdef F_39
F_40 () ;
F_41 () ;
F_45 ( ( float * ) & V_42 . V_87 . V_85 , & V_42 . V_84 ) ;
F_43 () ;
F_44 () ;
#else
return 0 ;
#endif
break;
}
if ( V_16 & V_28 ) {
unsigned int V_111 = 0 ;
switch ( V_15 ) {
case 4 :
V_111 = F_38 ( union V_42 , V_87 . V_85 ) ;
break;
case 2 :
V_111 = F_38 ( union V_42 , V_90 . V_88 ) ;
break;
}
V_36 = 0 ;
V_4 = ( unsigned long ) V_3 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
V_36 |= F_5 ( V_42 . V_41 [ V_111 + V_5 ] ,
F_12 ( V_4 ++ ) ) ;
if ( F_7 ( V_36 ) )
return - V_13 ;
} else if ( V_16 & V_107 )
V_32 -> V_33 . V_34 ( V_14 ) = V_42 . V_38 ;
else
V_2 -> V_30 [ V_14 ] = V_42 . V_38 ;
if ( V_16 & V_80 )
V_2 -> V_30 [ V_70 ] = V_2 -> V_11 ;
return 1 ;
}
