static int F_1 ( T_1 * V_1 , void * V_2 , int V_3 , int V_4 )
{
int V_5 ;
unsigned char V_6 [ V_7 ] ;
unsigned char * V_8 ;
int V_9 ;
int V_10 ;
V_11:
if ( F_2 ( V_1 ) && ! V_1 -> V_12 ) {
V_5 = V_1 -> V_13 ( V_1 ) ;
if ( V_5 < 0 )
return ( V_5 ) ;
if ( V_5 == 0 ) {
F_3 ( V_14 , V_15 ) ;
return ( - 1 ) ;
}
}
F_4 () ;
V_1 -> V_16 = V_17 ;
if ( V_3 <= 0 )
return ( V_3 ) ;
if ( V_1 -> V_18 -> V_19 != 0 ) {
if ( V_3 > V_1 -> V_18 -> V_19 )
V_5 = V_1 -> V_18 -> V_19 ;
else
V_5 = V_3 ;
memcpy ( V_2 , V_1 -> V_18 -> V_20 , ( unsigned int ) V_5 ) ;
if ( ! V_4 ) {
V_1 -> V_18 -> V_19 -= V_5 ;
V_1 -> V_18 -> V_20 += V_5 ;
if ( V_1 -> V_18 -> V_19 == 0 )
V_1 -> V_21 = V_22 ;
}
return ( V_5 ) ;
}
if ( V_1 -> V_21 == V_22 ) {
if ( V_1 -> V_23 ) {
V_5 = F_5 ( V_1 , 5 , V_24 + 2 , 0 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
V_1 -> V_23 = 0 ;
V_8 = V_1 -> V_25 ;
if ( ! ( ( V_8 [ 0 ] & 0x80 ) && ( ( V_8 [ 2 ] == V_26 ) ||
( V_8 [ 2 ] == V_27 ) ) ) ) {
F_3 ( V_14 ,
V_28 ) ;
return ( - 1 ) ;
}
} else {
V_5 = F_5 ( V_1 , 2 , V_24 + 2 , 0 ) ;
if ( V_5 <= 0 )
return ( V_5 ) ;
}
V_1 -> V_21 = V_29 ;
V_8 = V_1 -> V_25 ;
V_1 -> V_18 -> V_30 = 0 ;
V_1 -> V_18 -> V_31 = ( ( ( unsigned int ) V_8 [ 0 ] ) << 8 ) | ( ( unsigned int ) V_8 [ 1 ] ) ;
if ( ( V_8 [ 0 ] & V_32 ) ) {
V_1 -> V_18 -> V_33 = 0 ;
V_1 -> V_18 -> V_31 &= V_34 ;
} else {
V_1 -> V_18 -> V_33 = 1 ;
V_1 -> V_18 -> V_31 &= V_35 ;
V_1 -> V_18 -> V_30 = ( ( V_8 [ 0 ] & V_36 ) ) ? 1 : 0 ;
}
}
if ( V_1 -> V_21 == V_29 ) {
V_5 = V_1 -> V_18 -> V_31 + 2 + V_1 -> V_18 -> V_33 ;
if ( V_5 > ( int ) V_1 -> V_37 ) {
V_5 -= V_1 -> V_37 ;
V_9 = F_5 ( V_1 , ( unsigned int ) V_5 , ( unsigned int ) V_5 , 1 ) ;
if ( V_9 <= 0 )
return ( V_9 ) ;
}
V_8 = & ( V_1 -> V_25 [ 2 ] ) ;
V_1 -> V_21 = V_22 ;
if ( V_1 -> V_18 -> V_33 )
V_1 -> V_18 -> V_38 = * ( V_8 ++ ) ;
else
V_1 -> V_18 -> V_38 = 0 ;
if ( V_1 -> V_18 -> V_39 ) {
V_10 = 0 ;
V_1 -> V_18 -> V_40 = V_8 ;
V_1 -> V_18 -> V_20 = V_8 ;
if ( V_1 -> V_18 -> V_38 ) {
F_3 ( V_14 , V_41 ) ;
return ( - 1 ) ;
}
} else {
V_10 = F_6 ( V_1 -> V_42 ) ;
if ( V_10 < 0 )
return - 1 ;
F_7 ( V_10 <= V_7 ) ;
V_1 -> V_18 -> V_40 = V_8 ;
V_1 -> V_18 -> V_20 = & V_8 [ V_10 ] ;
if ( V_1 -> V_18 -> V_38 + V_10 > V_1 -> V_18 -> V_31 ) {
F_3 ( V_14 , V_41 ) ;
return ( - 1 ) ;
}
}
V_1 -> V_18 -> V_19 = V_1 -> V_18 -> V_31 ;
if ( ( ! V_1 -> V_18 -> V_39 ) &&
( V_1 -> V_18 -> V_31 >= ( unsigned int ) V_10 ) ) {
if ( ! F_8 ( V_1 , 0 ) ) {
F_3 ( V_14 , V_43 ) ;
return ( - 1 ) ;
}
V_1 -> V_18 -> V_19 -= V_10 ;
F_9 ( V_1 , V_6 , 0 ) ;
V_1 -> V_18 -> V_19 -= V_1 -> V_18 -> V_38 ;
if ( ( F_10 ( V_6 , V_1 -> V_18 -> V_40 , V_10 ) != 0 ) ||
( V_1 -> V_18 -> V_31 %
F_11 ( V_1 -> V_44 ) != 0 ) ) {
F_3 ( V_14 , V_45 ) ;
return ( - 1 ) ;
}
}
F_12 ( V_1 -> V_18 -> V_46 ) ;
goto V_11;
} else {
F_3 ( V_14 , V_47 ) ;
return ( - 1 ) ;
}
}
int F_13 ( T_1 * V_1 , void * V_2 , int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , 0 ) ;
}
int F_14 ( T_1 * V_1 , void * V_2 , int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , 1 ) ;
}
static int F_5 ( T_1 * V_1 , unsigned int V_5 , unsigned int V_48 ,
unsigned int V_49 )
{
int V_9 , V_50 , V_51 ;
if ( V_1 -> V_18 -> V_52 >= ( int ) V_5 ) {
if ( V_49 )
V_1 -> V_37 += V_5 ;
else {
V_1 -> V_25 = & ( V_1 -> V_18 -> V_53 [ V_1 -> V_18 -> V_54 ] ) ;
V_1 -> V_37 = V_5 ;
}
V_1 -> V_18 -> V_52 -= V_5 ;
V_1 -> V_18 -> V_54 += V_5 ;
return ( V_5 ) ;
}
if ( ! V_1 -> V_55 )
V_48 = V_5 ;
if ( V_48 > ( unsigned int ) ( V_24 + 2 ) )
V_48 = V_24 + 2 ;
V_50 = 0 ;
if ( ( V_1 -> V_18 -> V_52 != 0 ) || ( ( V_1 -> V_37 != 0 ) && V_49 ) ) {
V_51 = V_1 -> V_18 -> V_52 ;
if ( V_49 ) {
V_50 = V_1 -> V_37 ;
if ( V_1 -> V_25 != V_1 -> V_18 -> V_53 )
memcpy ( V_1 -> V_18 -> V_53 , V_1 -> V_25 , ( unsigned int ) V_51 + V_50 ) ;
} else if ( V_1 -> V_18 -> V_54 != 0 ) {
memcpy ( V_1 -> V_18 -> V_53 , & ( V_1 -> V_18 -> V_53 [ V_1 -> V_18 -> V_54 ] ) ,
( unsigned int ) V_51 ) ;
V_1 -> V_18 -> V_54 = 0 ;
}
V_1 -> V_18 -> V_52 = 0 ;
} else
V_51 = 0 ;
V_1 -> V_25 = V_1 -> V_18 -> V_53 ;
while ( V_51 < ( int ) V_5 ) {
F_4 () ;
if ( V_1 -> V_56 != NULL ) {
V_1 -> V_16 = V_57 ;
V_9 = F_15 ( V_1 -> V_56 , ( char * ) & ( V_1 -> V_18 -> V_53 [ V_50 + V_51 ] ) ,
V_48 - V_51 ) ;
} else {
F_3 ( V_58 , V_59 ) ;
V_9 = - 1 ;
}
# ifdef F_16
if ( V_1 -> V_60 & 0x01 )
F_17 ( 1 ) ;
# endif
if ( V_9 <= 0 ) {
V_1 -> V_18 -> V_52 += V_51 ;
return ( V_9 ) ;
}
V_51 += V_9 ;
}
if ( V_51 > ( int ) V_5 ) {
V_1 -> V_18 -> V_54 = V_5 + V_50 ;
V_1 -> V_18 -> V_52 = V_51 - V_5 ;
} else {
V_1 -> V_18 -> V_54 = 0 ;
V_1 -> V_18 -> V_52 = 0 ;
}
if ( V_49 )
V_1 -> V_37 += V_5 ;
else
V_1 -> V_37 = V_5 ;
V_1 -> V_16 = V_17 ;
return ( V_5 ) ;
}
int F_18 ( T_1 * V_1 , const void * V_61 , int V_3 )
{
const unsigned char * V_2 = V_61 ;
unsigned int V_5 , V_62 ;
int V_9 ;
if ( F_2 ( V_1 ) && ! V_1 -> V_12 ) {
V_9 = V_1 -> V_13 ( V_1 ) ;
if ( V_9 < 0 )
return ( V_9 ) ;
if ( V_9 == 0 ) {
F_3 ( V_63 , V_15 ) ;
return ( - 1 ) ;
}
}
if ( V_1 -> error ) {
F_19 ( V_1 ) ;
if ( V_1 -> error )
return ( - 1 ) ;
}
F_4 () ;
V_1 -> V_16 = V_17 ;
if ( V_3 <= 0 )
return ( V_3 ) ;
V_62 = V_1 -> V_18 -> V_64 ;
V_1 -> V_18 -> V_64 = 0 ;
V_5 = ( V_3 - V_62 ) ;
for (; ; ) {
V_9 = F_20 ( V_1 , & ( V_2 [ V_62 ] ) , V_5 ) ;
if ( V_9 <= 0 ) {
V_1 -> V_18 -> V_64 = V_62 ;
return ( V_9 ) ;
}
if ( ( V_9 == ( int ) V_5 ) || ( V_1 -> V_65 & V_66 ) ) {
return ( V_62 + V_9 ) ;
}
V_5 -= V_9 ;
V_62 += V_9 ;
}
}
static int F_21 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
int V_9 ;
if ( ( V_1 -> V_18 -> V_67 > ( int ) V_3 ) ||
( ( V_1 -> V_18 -> V_68 != V_2 ) &&
! ( V_1 -> V_65 & V_69 ) ) ) {
F_3 ( V_70 , V_71 ) ;
return ( - 1 ) ;
}
for (; ; ) {
F_4 () ;
if ( V_1 -> V_72 != NULL ) {
V_1 -> V_16 = V_73 ;
V_9 = F_22 ( V_1 -> V_72 ,
( char * ) & ( V_1 -> V_18 -> V_74 [ V_1 -> V_18 -> V_75 ] ) ,
( unsigned int ) V_1 -> V_18 -> V_76 ) ;
} else {
F_3 ( V_70 , V_77 ) ;
V_9 = - 1 ;
}
# ifdef F_16
if ( V_1 -> V_60 & 0x01 )
F_17 ( 1 ) ;
# endif
if ( V_9 == V_1 -> V_18 -> V_76 ) {
V_1 -> V_18 -> V_76 = 0 ;
V_1 -> V_16 = V_17 ;
return ( V_1 -> V_18 -> V_78 ) ;
} else if ( V_9 <= 0 )
return ( V_9 ) ;
V_1 -> V_18 -> V_75 += V_9 ;
V_1 -> V_18 -> V_76 -= V_9 ;
}
}
static int F_20 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
unsigned int V_79 , V_80 , V_81 , V_8 , V_82 ;
int V_10 ;
register unsigned char * V_83 ;
V_81 = V_3 ;
if ( V_1 -> V_18 -> V_76 != 0 )
return ( F_21 ( V_1 , V_2 , V_3 ) ) ;
if ( V_1 -> V_18 -> V_39 )
V_10 = 0 ;
else {
V_10 = F_6 ( V_1 -> V_84 ) ;
if ( V_10 < 0 )
return - 1 ;
}
if ( V_1 -> V_18 -> V_39 ) {
if ( V_3 > V_24 )
V_3 = V_24 ;
V_8 = 0 ;
V_1 -> V_18 -> V_33 = 0 ;
} else {
V_82 = F_11 ( V_1 -> V_44 ) ;
V_79 = V_3 + V_10 ;
if ( ( V_79 > V_85 ) && ( ! V_1 -> V_18 -> V_30 ) ) {
if ( V_79 > V_24 )
V_79 = V_24 ;
V_80 = V_79 - ( V_79 % V_82 ) ;
V_3 = V_80 - V_10 ;
V_1 -> V_18 -> V_33 = 0 ;
V_8 = 0 ;
} else if ( ( V_82 <= 1 ) && ( ! V_1 -> V_18 -> V_30 ) ) {
V_1 -> V_18 -> V_33 = 0 ;
V_8 = 0 ;
} else {
V_8 = ( V_79 % V_82 ) ;
V_8 = ( V_8 == 0 ) ? 0 : ( V_82 - V_8 ) ;
if ( V_1 -> V_18 -> V_30 ) {
V_1 -> V_18 -> V_33 = 1 ;
if ( V_79 > V_85 )
V_79 = V_85 ;
} else
V_1 -> V_18 -> V_33 = ( V_8 == 0 ) ? 0 : 1 ;
}
}
V_1 -> V_18 -> V_86 = V_3 ;
V_1 -> V_18 -> V_38 = V_8 ;
V_1 -> V_18 -> V_40 = & ( V_1 -> V_18 -> V_87 [ 3 ] ) ;
V_1 -> V_18 -> V_88 = & ( V_1 -> V_18 -> V_87 [ 3 + V_10 ] ) ;
memcpy ( V_1 -> V_18 -> V_88 , V_2 , V_3 ) ;
if ( V_8 )
memset ( & ( V_1 -> V_18 -> V_88 [ V_3 ] ) , 0 , V_8 ) ;
if ( ! V_1 -> V_18 -> V_39 ) {
V_1 -> V_18 -> V_89 = V_3 + V_8 ;
F_9 ( V_1 , V_1 -> V_18 -> V_40 , 1 ) ;
V_1 -> V_18 -> V_86 += V_8 + V_10 ;
if ( F_8 ( V_1 , 1 ) < 1 )
return - 1 ;
}
V_1 -> V_18 -> V_76 = V_1 -> V_18 -> V_86 ;
if ( V_1 -> V_18 -> V_33 ) {
V_83 = V_1 -> V_18 -> V_40 ;
V_83 -= 3 ;
V_83 [ 0 ] = ( V_1 -> V_18 -> V_86 >> 8 ) & ( V_35 >> 8 ) ;
if ( V_1 -> V_18 -> V_30 )
V_83 [ 0 ] |= V_36 ;
V_83 [ 1 ] = V_1 -> V_18 -> V_86 & 0xff ;
V_83 [ 2 ] = V_1 -> V_18 -> V_38 ;
V_1 -> V_18 -> V_76 += 3 ;
} else {
V_83 = V_1 -> V_18 -> V_40 ;
V_83 -= 2 ;
V_83 [ 0 ] = ( ( V_1 -> V_18 -> V_86 >> 8 ) & ( V_34 >> 8 ) ) | V_32 ;
V_83 [ 1 ] = V_1 -> V_18 -> V_86 & 0xff ;
V_1 -> V_18 -> V_76 += 2 ;
}
V_1 -> V_18 -> V_74 = V_83 ;
F_12 ( V_1 -> V_18 -> V_90 ) ;
V_1 -> V_18 -> V_67 = V_81 ;
V_1 -> V_18 -> V_68 = V_2 ;
V_1 -> V_18 -> V_78 = V_3 ;
V_1 -> V_18 -> V_75 = 0 ;
return ( F_21 ( V_1 , V_2 , V_81 ) ) ;
}
int F_23 ( T_1 * V_1 , unsigned long V_91 , int V_9 )
{
unsigned char * V_8 ;
int V_79 ;
if ( V_9 < 0 ) {
return ( V_9 ) ;
} else {
V_1 -> V_92 += V_9 ;
if ( V_1 -> V_92 >= 3 ) {
V_8 = ( unsigned char * ) V_1 -> V_93 -> V_94 ;
if ( V_8 [ 0 ] == V_95 ) {
V_79 = ( V_8 [ 1 ] << 8 ) | V_8 [ 2 ] ;
F_3 ( ( int ) V_91 , F_24 ( V_79 ) ) ;
V_1 -> V_92 -= 3 ;
if ( V_1 -> V_92 > 0 )
memmove ( V_8 , V_8 + 3 , V_1 -> V_92 ) ;
}
}
return ( 0 ) ;
}
}
int F_25 ( T_1 * V_1 )
{
int V_96 ;
V_96 = F_18 ( V_1 , & V_1 -> V_93 -> V_94 [ V_1 -> V_97 ] , V_1 -> V_92 ) ;
if ( V_96 == V_1 -> V_92 ) {
if ( V_1 -> V_98 )
V_1 -> V_98 ( 1 , V_1 -> V_99 , 0 , V_1 -> V_93 -> V_94 ,
( V_100 ) ( V_1 -> V_97 + V_1 -> V_92 ) , V_1 ,
V_1 -> V_101 ) ;
return ( 1 ) ;
}
if ( V_96 < 0 )
return ( - 1 ) ;
V_1 -> V_97 += V_96 ;
V_1 -> V_92 -= V_96 ;
return ( 0 ) ;
}
static int F_24 ( int V_5 )
{
int V_96 ;
switch ( V_5 ) {
case V_102 :
V_96 = V_103 ;
break;
case V_104 :
V_96 = V_105 ;
break;
case V_106 :
V_96 = V_107 ;
break;
case V_108 :
V_96 = V_109 ;
break;
default:
V_96 = V_110 ;
break;
}
return ( V_96 ) ;
}
