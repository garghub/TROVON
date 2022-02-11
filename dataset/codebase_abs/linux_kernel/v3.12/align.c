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
if ( F_11 ( F_13 ( V_19 , V_7 ^ V_21 ) ,
F_14 ( V_6 ) ) )
return - V_14 ;
if ( V_20 > 0 ) {
V_19 = & V_4 -> V_30 [ 0 ] ;
V_5 += V_16 ;
for ( V_7 = 0 ; V_7 < V_20 ; ++ V_7 , ++ V_6 )
if ( F_11 ( F_13 ( V_19 ,
V_7 ^ V_21 ) ,
F_14 ( V_6 ) ) )
return - V_14 ;
}
} else {
for ( V_7 = 0 ; V_7 < V_16 ; ++ V_7 , ++ V_6 )
if ( F_8 ( F_13 ( V_19 , V_7 ^ V_21 ) ,
F_14 ( V_6 ) ) )
return - V_14 ;
if ( V_20 > 0 ) {
V_19 = & V_4 -> V_30 [ 0 ] ;
V_5 += V_16 ;
for ( V_7 = 0 ; V_7 < V_20 ; ++ V_7 , ++ V_6 )
if ( F_8 ( F_13 ( V_19 ,
V_7 ^ V_21 ) ,
F_14 ( V_6 ) ) )
return - V_14 ;
}
}
return 1 ;
}
static int F_15 ( unsigned char T_1 * V_5 , unsigned int V_15 ,
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
V_36 |= F_16 ( V_31 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
V_36 |= F_16 ( V_35 [ V_7 ^ V_37 ] , V_5 + V_7 + 8 ) ;
} else {
V_36 |= F_17 ( V_31 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
V_36 |= F_17 ( V_35 [ V_7 ^ V_37 ] , V_5 + V_7 + 8 ) ;
}
}
if ( V_36 )
return - V_14 ;
return 1 ;
}
static int F_18 ( struct V_3 * V_4 , unsigned int V_15 ,
unsigned int V_1 )
{
int V_39 , V_36 ;
union {
T_2 V_40 ;
T_3 V_41 [ 2 ] ;
T_4 V_42 [ 4 ] ;
T_5 V_43 [ 8 ] ;
} V_44 , V_45 ;
unsigned char T_1 * V_6 , * V_5 ;
unsigned long * V_46 = & V_32 -> V_33 . V_46 [ V_15 ] ;
unsigned int V_16 , V_17 ;
V_1 = ( V_1 >> 1 ) & 0x1f ;
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
V_16 = V_47 [ V_1 ] . V_48 ;
V_17 = V_47 [ V_1 ] . V_17 ;
if ( F_10 ( F_6 ( V_4 ) &&
! F_7 ( ( V_17 & V_28 ? V_13 : V_29 ) ,
V_5 , V_16 ) ) )
return - V_14 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_19 ( V_32 ) ;
if ( V_17 & V_28 ) {
V_44 . V_40 = 0 ;
switch ( V_1 ) {
case V_49 :
case V_50 :
case V_51 :
V_44 . V_41 [ 0 ] = * V_46 ;
V_44 . V_41 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
case V_52 :
V_44 . V_42 [ 2 ] = * V_46 >> 16 ;
V_44 . V_42 [ 3 ] = V_4 -> V_30 [ V_15 ] >> 16 ;
break;
case V_53 :
V_44 . V_42 [ 2 ] = * V_46 & 0xffff ;
V_44 . V_42 [ 3 ] = V_4 -> V_30 [ V_15 ] & 0xffff ;
break;
case V_54 :
V_44 . V_41 [ 1 ] = * V_46 ;
break;
case V_55 :
V_44 . V_41 [ 1 ] = V_4 -> V_30 [ V_15 ] ;
break;
default:
return - V_56 ;
}
} else {
V_45 . V_40 = V_44 . V_40 = 0 ;
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_11 ( V_45 . V_43 [ 0 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_45 . V_43 [ 1 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_45 . V_43 [ 2 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_45 . V_43 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_11 ( V_45 . V_43 [ 4 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_45 . V_43 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_11 ( V_45 . V_43 [ 6 ] , V_6 ++ ) ;
V_36 |= F_11 ( V_45 . V_43 [ 7 ] , V_6 ++ ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
}
switch ( V_1 ) {
case V_57 :
case V_58 :
case V_59 :
V_44 . V_40 = V_45 . V_40 ;
break;
case V_60 :
V_44 . V_42 [ 0 ] = V_45 . V_42 [ 3 ] ;
V_44 . V_42 [ 2 ] = V_45 . V_42 [ 3 ] ;
break;
case V_61 :
case V_62 :
V_44 . V_42 [ 1 ] = V_45 . V_42 [ 3 ] ;
V_44 . V_42 [ 3 ] = V_45 . V_42 [ 3 ] ;
break;
case V_63 :
V_44 . V_42 [ 0 ] = V_45 . V_42 [ 2 ] ;
V_44 . V_42 [ 2 ] = V_45 . V_42 [ 3 ] ;
break;
case V_64 :
case V_65 :
V_44 . V_42 [ 1 ] = V_45 . V_42 [ 2 ] ;
V_44 . V_42 [ 3 ] = V_45 . V_42 [ 3 ] ;
break;
case V_66 :
V_44 . V_41 [ 0 ] = V_45 . V_41 [ 1 ] ;
V_44 . V_41 [ 1 ] = V_45 . V_41 [ 1 ] ;
break;
case V_67 :
V_44 . V_42 [ 0 ] = V_45 . V_42 [ 2 ] ;
V_44 . V_42 [ 1 ] = V_45 . V_42 [ 2 ] ;
V_44 . V_42 [ 2 ] = V_45 . V_42 [ 3 ] ;
V_44 . V_42 [ 3 ] = V_45 . V_42 [ 3 ] ;
break;
default:
return - V_56 ;
}
}
if ( V_17 & V_27 ) {
switch ( V_17 & 0xf0 ) {
case V_68 :
F_20 ( V_44 . V_43 [ 0 ] , V_44 . V_43 [ 7 ] ) ;
F_20 ( V_44 . V_43 [ 1 ] , V_44 . V_43 [ 6 ] ) ;
F_20 ( V_44 . V_43 [ 2 ] , V_44 . V_43 [ 5 ] ) ;
F_20 ( V_44 . V_43 [ 3 ] , V_44 . V_43 [ 4 ] ) ;
break;
case V_69 :
F_20 ( V_44 . V_43 [ 0 ] , V_44 . V_43 [ 3 ] ) ;
F_20 ( V_44 . V_43 [ 1 ] , V_44 . V_43 [ 2 ] ) ;
F_20 ( V_44 . V_43 [ 4 ] , V_44 . V_43 [ 7 ] ) ;
F_20 ( V_44 . V_43 [ 5 ] , V_44 . V_43 [ 6 ] ) ;
break;
default:
F_20 ( V_44 . V_43 [ 0 ] , V_44 . V_43 [ 1 ] ) ;
F_20 ( V_44 . V_43 [ 2 ] , V_44 . V_43 [ 3 ] ) ;
F_20 ( V_44 . V_43 [ 4 ] , V_44 . V_43 [ 5 ] ) ;
F_20 ( V_44 . V_43 [ 6 ] , V_44 . V_43 [ 7 ] ) ;
break;
}
}
if ( V_17 & V_70 ) {
V_44 . V_41 [ 0 ] = ( V_71 ) V_44 . V_42 [ 1 ] ;
V_44 . V_41 [ 1 ] = ( V_71 ) V_44 . V_42 [ 3 ] ;
}
if ( V_17 & V_28 ) {
V_36 = 0 ;
V_6 = V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_8 ( V_44 . V_43 [ 0 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_44 . V_43 [ 1 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_44 . V_43 [ 2 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_44 . V_43 [ 3 ] , V_6 ++ ) ;
case 4 :
V_36 |= F_8 ( V_44 . V_43 [ 4 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_44 . V_43 [ 5 ] , V_6 ++ ) ;
case 2 :
V_36 |= F_8 ( V_44 . V_43 [ 6 ] , V_6 ++ ) ;
V_36 |= F_8 ( V_44 . V_43 [ 7 ] , V_6 ++ ) ;
}
if ( F_10 ( V_36 ) )
return - V_14 ;
} else {
* V_46 = V_44 . V_41 [ 0 ] ;
V_4 -> V_30 [ V_15 ] = V_44 . V_41 [ 1 ] ;
}
return 1 ;
}
static int F_21 ( unsigned char T_1 * V_5 , unsigned int V_15 ,
unsigned int V_72 , struct V_3 * V_4 ,
unsigned int V_17 , unsigned int V_73 ,
unsigned int V_74 )
{
char * V_75 ;
unsigned long * V_76 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_7 , V_77 ;
if ( F_10 ( ! F_6 ( V_4 ) ) )
return 0 ;
F_22 ( V_32 ) ;
if ( V_15 < 32 )
V_75 = ( char * ) & V_32 -> V_33 . V_34 ( V_15 ) ;
else
V_75 = ( char * ) & V_32 -> V_33 . V_78 [ V_15 - 32 ] ;
V_76 = ( unsigned long * ) V_75 ;
if ( V_17 & V_27 )
V_37 = V_74 - 1 ;
for ( V_77 = 0 ; V_77 < V_73 ; V_77 += V_74 ) {
for ( V_7 = 0 ; V_7 < V_74 ; ++ V_7 ) {
if ( V_17 & V_28 )
V_36 |= F_17 ( V_75 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
else
V_36 |= F_16 ( V_75 [ V_7 ^ V_37 ] , V_5 + V_7 ) ;
}
V_75 += V_74 ;
V_5 += V_74 ;
}
if ( ! V_36 ) {
if ( V_17 & V_79 )
V_4 -> V_30 [ V_72 ] = V_4 -> V_12 ;
if ( V_17 & V_80 )
V_76 [ 1 ] = V_76 [ 0 ] ;
else if ( ! ( V_17 & V_28 ) && ( 8 == V_73 ) )
V_76 [ 1 ] = 0 ;
} else
return - V_14 ;
return 1 ;
}
int F_23 ( struct V_3 * V_4 )
{
unsigned int V_1 , V_16 , V_17 , V_81 = 0 ;
unsigned int V_15 , V_72 ;
unsigned int V_2 ;
unsigned char T_1 * V_5 ;
unsigned long V_6 , V_18 ;
int V_36 , V_39 ;
union {
T_2 V_40 ;
double V_82 ;
unsigned char V_43 [ 8 ] ;
struct {
unsigned V_83 ;
int V_84 ;
} V_85 ;
struct {
unsigned char V_86 [ 6 ] ;
short V_87 ;
} V_88 ;
} V_44 ;
F_24 ( V_4 ) ;
V_2 = V_4 -> V_2 ;
if ( F_25 ( V_89 ) ) {
unsigned long V_25 = V_4 -> V_26 ;
if ( F_25 ( V_90 ) && ( V_4 -> V_91 & V_92 ) )
V_25 ^= 4 ;
if ( F_10 ( F_11 ( V_1 ,
( unsigned int T_1 * ) V_25 ) ) )
return - V_14 ;
if ( F_25 ( V_93 ) && ( V_4 -> V_91 & V_92 ) )
V_1 = F_12 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
V_81 = V_1 ;
}
V_15 = ( V_2 >> 5 ) & 0x1f ;
V_72 = V_2 & 0x1f ;
#ifdef F_26
if ( ( V_1 >> 26 ) == 0x4 ) {
F_27 ( V_94 , V_4 ) ;
return F_18 ( V_4 , V_15 , V_1 ) ;
}
#endif
V_1 = ( V_2 >> 10 ) & 0x7f ;
V_1 |= ( V_2 >> 13 ) & 0x60 ;
V_16 = V_95 [ V_1 ] . V_48 ;
V_17 = V_95 [ V_1 ] . V_17 ;
if ( F_2 ( V_81 ) && ( ( V_81 >> 1 ) & 0x3ff ) == 532 ) {
V_16 = 8 ;
V_17 = V_96 + V_27 ;
} else if ( F_2 ( V_81 ) &&
( ( V_81 >> 1 ) & 0x3ff ) == 660 ) {
V_16 = 8 ;
V_17 = V_28 + V_27 ;
}
V_18 = 0 ;
if ( V_4 -> V_91 & V_92 ) {
V_17 ^= V_27 ;
if ( F_25 ( V_90 ) )
V_18 = 7 ;
}
V_5 = ( unsigned char T_1 * ) V_4 -> V_12 ;
#ifdef F_28
if ( ( V_81 & 0xfc00003e ) == 0x7c000018 ) {
unsigned int V_74 ;
V_15 |= ( V_81 & 0x1 ) << 5 ;
V_16 = 8 ;
if ( V_81 & 0x200 )
V_16 = 16 ;
V_74 = 4 ;
if ( V_81 & 0x80 )
V_74 = 8 ;
V_17 = 0 ;
if ( V_4 -> V_91 & V_92 )
V_17 |= V_27 ;
if ( V_81 & 0x100 )
V_17 |= V_28 ;
if ( V_81 & 0x040 )
V_17 |= V_79 ;
if ( ( V_81 & 0x400 ) == 0 ) {
V_17 |= V_80 ;
V_16 = 8 ;
}
F_27 ( V_97 , V_4 ) ;
return F_21 ( V_5 , V_15 , V_72 , V_4 , V_17 , V_16 , V_74 ) ;
}
#endif
if ( V_1 == V_98 ) {
F_27 ( V_99 , V_4 ) ;
return F_4 ( V_4 , V_5 ) ;
}
if ( F_10 ( V_16 == 0 ) )
return 0 ;
if ( V_17 & V_100 ) {
F_27 ( V_101 , V_4 ) ;
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
F_29 ( V_32 ) ;
}
if ( V_16 == 16 ) {
F_27 ( V_102 , V_4 ) ;
return F_15 ( V_5 , V_15 , V_17 ) ;
}
F_27 ( V_103 , V_4 ) ;
if ( ! ( V_17 & V_28 ) ) {
V_44 . V_40 = 0 ;
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_11 ( V_44 . V_43 [ 0 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_11 ( V_44 . V_43 [ 1 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_11 ( V_44 . V_43 [ 2 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_11 ( V_44 . V_43 [ 3 ] , F_14 ( V_6 ++ ) ) ;
case 4 :
V_36 |= F_11 ( V_44 . V_43 [ 4 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_11 ( V_44 . V_43 [ 5 ] , F_14 ( V_6 ++ ) ) ;
case 2 :
V_36 |= F_11 ( V_44 . V_43 [ 6 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_11 ( V_44 . V_43 [ 7 ] , F_14 ( V_6 ++ ) ) ;
if ( F_10 ( V_36 ) )
return - V_14 ;
}
} else if ( V_17 & V_38 ) {
V_44 . V_82 = V_32 -> V_33 . V_34 ( V_15 ) ;
if ( V_17 & V_104 ) {
#ifdef F_30
F_31 () ;
F_32 () ;
F_33 ( & V_44 . V_82 , ( float * ) & V_44 . V_43 [ 4 ] ) ;
F_34 () ;
#else
return 0 ;
#endif
}
} else
V_44 . V_40 = V_4 -> V_30 [ V_15 ] ;
if ( V_17 & V_27 ) {
switch ( V_16 ) {
case 8 :
F_20 ( V_44 . V_43 [ 0 ] , V_44 . V_43 [ 7 ] ) ;
F_20 ( V_44 . V_43 [ 1 ] , V_44 . V_43 [ 6 ] ) ;
F_20 ( V_44 . V_43 [ 2 ] , V_44 . V_43 [ 5 ] ) ;
F_20 ( V_44 . V_43 [ 3 ] , V_44 . V_43 [ 4 ] ) ;
break;
case 4 :
F_20 ( V_44 . V_43 [ 4 ] , V_44 . V_43 [ 7 ] ) ;
F_20 ( V_44 . V_43 [ 5 ] , V_44 . V_43 [ 6 ] ) ;
break;
case 2 :
F_20 ( V_44 . V_43 [ 6 ] , V_44 . V_43 [ 7 ] ) ;
break;
}
}
switch ( V_17 & ~ ( V_79 | V_27 ) ) {
case V_96 + V_70 :
case V_96 + V_38 + V_70 :
if ( V_16 == 2 )
V_44 . V_40 = V_44 . V_88 . V_87 ;
else
V_44 . V_40 = V_44 . V_85 . V_84 ;
break;
case V_96 + V_38 + V_104 :
#ifdef F_30
F_31 () ;
F_32 () ;
F_35 ( ( float * ) & V_44 . V_43 [ 4 ] , & V_44 . V_82 ) ;
F_34 () ;
#else
return 0 ;
#endif
break;
}
if ( V_17 & V_28 ) {
V_36 = 0 ;
V_6 = ( unsigned long ) V_5 ;
switch ( V_16 ) {
case 8 :
V_36 |= F_8 ( V_44 . V_43 [ 0 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_8 ( V_44 . V_43 [ 1 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_8 ( V_44 . V_43 [ 2 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_8 ( V_44 . V_43 [ 3 ] , F_14 ( V_6 ++ ) ) ;
case 4 :
V_36 |= F_8 ( V_44 . V_43 [ 4 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_8 ( V_44 . V_43 [ 5 ] , F_14 ( V_6 ++ ) ) ;
case 2 :
V_36 |= F_8 ( V_44 . V_43 [ 6 ] , F_14 ( V_6 ++ ) ) ;
V_36 |= F_8 ( V_44 . V_43 [ 7 ] , F_14 ( V_6 ++ ) ) ;
}
if ( F_10 ( V_36 ) )
return - V_14 ;
} else if ( V_17 & V_38 )
V_32 -> V_33 . V_34 ( V_15 ) = V_44 . V_82 ;
else
V_4 -> V_30 [ V_15 ] = V_44 . V_40 ;
if ( V_17 & V_79 )
V_4 -> V_30 [ V_72 ] = V_4 -> V_12 ;
return 1 ;
}
