int F_1 ( T_1 * V_1 , char * V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_4 > 0 )
{
V_1 -> V_5 -> V_6 += V_4 ;
V_1 -> V_5 -> V_7 -= V_4 ;
}
return ( V_4 ) ;
}
int F_2 ( T_1 * V_1 , void * V_2 , int V_3 )
{
int V_8 ;
unsigned char V_9 [ V_10 ] ;
unsigned char * V_11 ;
int V_12 ;
unsigned int V_13 = 0 ;
V_14:
if ( F_3 ( V_1 ) && ! V_1 -> V_15 )
{
V_8 = V_1 -> V_16 ( V_1 ) ;
if ( V_8 < 0 ) return ( V_8 ) ;
if ( V_8 == 0 )
{
F_4 ( V_17 , V_18 ) ;
return ( - 1 ) ;
}
}
F_5 () ;
V_1 -> V_19 = V_20 ;
if ( V_3 <= 0 ) return ( V_3 ) ;
if ( V_1 -> V_5 -> V_6 != 0 )
{
if ( V_3 > V_1 -> V_5 -> V_6 )
V_8 = V_1 -> V_5 -> V_6 ;
else
V_8 = V_3 ;
memcpy ( V_2 , V_1 -> V_5 -> V_7 , ( unsigned int ) V_8 ) ;
V_1 -> V_5 -> V_6 -= V_8 ;
V_1 -> V_5 -> V_7 += V_8 ;
if ( V_1 -> V_5 -> V_6 == 0 )
V_1 -> V_21 = V_22 ;
return ( V_8 ) ;
}
if ( V_1 -> V_21 == V_22 )
{
if ( V_1 -> V_23 )
{
V_8 = F_6 ( V_1 , 5 , V_24 + 2 , 0 ) ;
if ( V_8 <= 0 ) return ( V_8 ) ;
V_1 -> V_23 = 0 ;
V_11 = V_1 -> V_25 ;
if ( ! ( ( V_11 [ 0 ] & 0x80 ) && (
( V_11 [ 2 ] == V_26 ) ||
( V_11 [ 2 ] == V_27 ) ) ) )
{
F_4 ( V_17 , V_28 ) ;
return ( - 1 ) ;
}
}
else
{
V_8 = F_6 ( V_1 , 2 , V_24 + 2 , 0 ) ;
if ( V_8 <= 0 ) return ( V_8 ) ;
}
V_1 -> V_21 = V_29 ;
V_11 = V_1 -> V_25 ;
V_1 -> V_5 -> V_30 = 0 ;
V_1 -> V_5 -> V_31 = ( ( ( unsigned int ) V_11 [ 0 ] ) << 8 ) | ( ( unsigned int ) V_11 [ 1 ] ) ;
if ( ( V_11 [ 0 ] & V_32 ) )
{
V_1 -> V_5 -> V_33 = 0 ;
V_1 -> V_5 -> V_31 &= V_34 ;
}
else
{
V_1 -> V_5 -> V_33 = 1 ;
V_1 -> V_5 -> V_31 &= V_35 ;
V_1 -> V_5 -> V_30 = ( ( V_11 [ 0 ] & V_36 ) ) ? 1 : 0 ;
}
}
if ( V_1 -> V_21 == V_29 )
{
V_8 = V_1 -> V_5 -> V_31 + 2 + V_1 -> V_5 -> V_33 ;
if ( V_8 > ( int ) V_1 -> V_37 )
{
V_8 -= V_1 -> V_37 ;
V_12 = F_6 ( V_1 , ( unsigned int ) V_8 , ( unsigned int ) V_8 , 1 ) ;
if ( V_12 <= 0 ) return ( V_12 ) ;
}
V_11 = & ( V_1 -> V_25 [ 2 ] ) ;
V_1 -> V_21 = V_22 ;
if ( V_1 -> V_5 -> V_33 )
V_1 -> V_5 -> V_38 = * ( V_11 ++ ) ;
else V_1 -> V_5 -> V_38 = 0 ;
if ( V_1 -> V_5 -> V_39 )
{
V_1 -> V_5 -> V_40 = V_11 ;
V_1 -> V_5 -> V_7 = V_11 ;
V_1 -> V_5 -> V_41 = NULL ;
}
else
{
V_13 = F_7 ( V_1 -> V_42 ) ;
V_1 -> V_5 -> V_40 = V_11 ;
V_1 -> V_5 -> V_7 = & V_11 [ V_13 ] ;
V_1 -> V_5 -> V_41 = & V_11 [ V_13 +
V_1 -> V_5 -> V_31 - V_1 -> V_5 -> V_38 ] ;
}
V_1 -> V_5 -> V_6 = V_1 -> V_5 -> V_31 ;
if ( ( ! V_1 -> V_5 -> V_39 ) &&
( V_1 -> V_5 -> V_31 >= V_13 ) )
{
F_8 ( V_1 , 0 ) ;
V_1 -> V_5 -> V_6 -= V_13 ;
F_9 ( V_1 , V_9 , 0 ) ;
V_1 -> V_5 -> V_6 -= V_1 -> V_5 -> V_38 ;
if ( ( memcmp ( V_9 , V_1 -> V_5 -> V_40 ,
( unsigned int ) V_13 ) != 0 ) ||
( V_1 -> V_5 -> V_31 % F_10 ( V_1 -> V_43 ) != 0 ) )
{
F_4 ( V_17 , V_44 ) ;
return ( - 1 ) ;
}
}
F_11 ( V_1 -> V_5 -> V_45 ) ;
#if 1
goto V_14;
#else
if ( V_1 -> V_5 -> V_6 == 0 )
return ( 0 ) ;
return ( F_2 ( V_1 , V_2 , V_3 ) ) ;
#endif
}
else
{
F_4 ( V_17 , V_46 ) ;
return ( - 1 ) ;
}
}
static int F_6 ( T_1 * V_1 , unsigned int V_8 , unsigned int V_47 ,
unsigned int V_48 )
{
int V_12 , V_49 , V_50 ;
if ( V_1 -> V_5 -> V_51 >= ( int ) V_8 )
{
if ( V_48 )
V_1 -> V_37 += V_8 ;
else
{
V_1 -> V_25 = & ( V_1 -> V_5 -> V_52 [ V_1 -> V_5 -> V_53 ] ) ;
V_1 -> V_37 = V_8 ;
}
V_1 -> V_5 -> V_51 -= V_8 ;
V_1 -> V_5 -> V_53 += V_8 ;
return ( V_8 ) ;
}
if ( ! V_1 -> V_54 ) V_47 = V_8 ;
if ( V_47 > ( unsigned int ) ( V_24 + 2 ) )
V_47 = V_24 + 2 ;
V_49 = 0 ;
if ( ( V_1 -> V_5 -> V_51 != 0 ) || ( ( V_1 -> V_37 != 0 ) && V_48 ) )
{
V_50 = V_1 -> V_5 -> V_51 ;
if ( V_48 )
{
V_49 = V_1 -> V_37 ;
if ( V_1 -> V_25 != V_1 -> V_5 -> V_52 )
memcpy ( V_1 -> V_5 -> V_52 , V_1 -> V_25 ,
( unsigned int ) V_50 + V_49 ) ;
}
else if ( V_1 -> V_5 -> V_53 != 0 )
{
memcpy ( V_1 -> V_5 -> V_52 , & ( V_1 -> V_5 -> V_52 [ V_1 -> V_5 -> V_53 ] ) ,
( unsigned int ) V_50 ) ;
V_1 -> V_5 -> V_53 = 0 ;
}
V_1 -> V_5 -> V_51 = 0 ;
}
else
V_50 = 0 ;
V_1 -> V_25 = V_1 -> V_5 -> V_52 ;
while ( V_50 < ( int ) V_8 )
{
F_5 () ;
if ( V_1 -> V_55 != NULL )
{
V_1 -> V_19 = V_56 ;
V_12 = F_12 ( V_1 -> V_55 , ( char * ) & ( V_1 -> V_5 -> V_52 [ V_49 + V_50 ] ) ,
V_47 - V_50 ) ;
}
else
{
F_4 ( V_57 , V_58 ) ;
V_12 = - 1 ;
}
#ifdef F_13
if ( V_1 -> V_59 & 0x01 ) F_14 ( 1 ) ;
#endif
if ( V_12 <= 0 )
{
V_1 -> V_5 -> V_51 += V_50 ;
return ( V_12 ) ;
}
V_50 += V_12 ;
}
if ( V_50 > ( int ) V_8 )
{
V_1 -> V_5 -> V_53 = V_8 + V_49 ;
V_1 -> V_5 -> V_51 = V_50 - V_8 ;
}
else
{
V_1 -> V_5 -> V_53 = 0 ;
V_1 -> V_5 -> V_51 = 0 ;
}
if ( V_48 )
V_1 -> V_37 += V_8 ;
else
V_1 -> V_37 = V_8 ;
V_1 -> V_19 = V_20 ;
return ( V_8 ) ;
}
int F_15 ( T_1 * V_1 , const void * V_60 , int V_3 )
{
const unsigned char * V_2 = V_60 ;
unsigned int V_8 , V_61 ;
int V_12 ;
if ( F_3 ( V_1 ) && ! V_1 -> V_15 )
{
V_12 = V_1 -> V_16 ( V_1 ) ;
if ( V_12 < 0 ) return ( V_12 ) ;
if ( V_12 == 0 )
{
F_4 ( V_62 , V_18 ) ;
return ( - 1 ) ;
}
}
if ( V_1 -> error )
{
F_16 ( V_1 ) ;
if ( V_1 -> error )
return ( - 1 ) ;
}
F_5 () ;
V_1 -> V_19 = V_20 ;
if ( V_3 <= 0 ) return ( V_3 ) ;
V_61 = V_1 -> V_5 -> V_63 ;
V_1 -> V_5 -> V_63 = 0 ;
V_8 = ( V_3 - V_61 ) ;
for (; ; )
{
V_12 = F_17 ( V_1 , & ( V_2 [ V_61 ] ) , V_8 ) ;
if ( V_12 <= 0 )
{
V_1 -> V_5 -> V_63 = V_61 ;
return ( V_12 ) ;
}
if ( V_12 == ( int ) V_8 ) return ( V_61 + V_12 ) ;
V_8 -= V_12 ;
V_61 += V_12 ;
}
}
static int F_18 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
int V_12 ;
if ( ( V_1 -> V_5 -> V_64 > ( int ) V_3 ) || ( V_1 -> V_5 -> V_65 != V_2 ) )
{
F_4 ( V_66 , V_67 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_5 () ;
if ( V_1 -> V_68 != NULL )
{
V_1 -> V_19 = V_69 ;
V_12 = F_19 ( V_1 -> V_68 ,
( char * ) & ( V_1 -> V_5 -> V_70 [ V_1 -> V_5 -> V_71 ] ) ,
( unsigned int ) V_1 -> V_5 -> V_72 ) ;
}
else
{
F_4 ( V_66 , V_73 ) ;
V_12 = - 1 ;
}
#ifdef F_13
if ( V_1 -> V_59 & 0x01 ) F_14 ( 1 ) ;
#endif
if ( V_12 == V_1 -> V_5 -> V_72 )
{
V_1 -> V_5 -> V_72 = 0 ;
V_1 -> V_19 = V_20 ;
return ( V_1 -> V_5 -> V_74 ) ;
}
else if ( V_12 <= 0 )
return ( V_12 ) ;
V_1 -> V_5 -> V_71 += V_12 ;
V_1 -> V_5 -> V_72 -= V_12 ;
}
}
static int F_17 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
unsigned int V_75 , V_76 , V_77 , V_11 , V_13 , V_78 ;
register unsigned char * V_79 ;
V_77 = V_3 ;
if ( V_1 -> V_5 -> V_72 != 0 ) return ( F_18 ( V_1 , V_2 , V_3 ) ) ;
if ( V_1 -> V_5 -> V_39 )
V_13 = 0 ;
else
V_13 = F_7 ( V_1 -> V_80 ) ;
if ( V_1 -> V_5 -> V_39 )
{
if ( V_3 > V_24 )
V_3 = V_24 ;
V_11 = 0 ;
V_1 -> V_5 -> V_33 = 0 ;
}
else
{
V_78 = F_10 ( V_1 -> V_43 ) ;
V_75 = V_3 + V_13 ;
if ( ( V_75 > V_81 ) &&
( ! V_1 -> V_5 -> V_30 ) )
{
if ( V_75 > V_24 )
V_75 = V_24 ;
V_76 = V_75 - ( V_75 % V_78 ) ;
V_3 = V_76 - V_13 ;
V_1 -> V_5 -> V_33 = 0 ;
V_11 = 0 ;
}
else if ( ( V_78 <= 1 ) && ( ! V_1 -> V_5 -> V_30 ) )
{
V_1 -> V_5 -> V_33 = 0 ;
V_11 = 0 ;
}
else
{
V_11 = ( V_75 % V_78 ) ;
V_11 = ( V_11 == 0 ) ? 0 : ( V_78 - V_11 ) ;
if ( V_1 -> V_5 -> V_30 )
V_1 -> V_5 -> V_33 = 1 ;
else
V_1 -> V_5 -> V_33 = ( V_11 == 0 ) ? 0 : 1 ;
}
}
V_1 -> V_5 -> V_82 = V_3 ;
V_1 -> V_5 -> V_38 = V_11 ;
V_1 -> V_5 -> V_40 = & ( V_1 -> V_5 -> V_83 [ 3 ] ) ;
V_1 -> V_5 -> V_84 = & ( V_1 -> V_5 -> V_83 [ 3 + V_13 ] ) ;
memcpy ( V_1 -> V_5 -> V_84 , V_2 , V_3 ) ;
#ifdef F_20
if ( V_11 )
memset ( & ( V_1 -> V_5 -> V_84 [ V_3 ] ) , 0 , V_11 ) ;
#endif
if ( ! V_1 -> V_5 -> V_39 )
{
V_1 -> V_5 -> V_85 = V_3 + V_11 ;
F_9 ( V_1 , V_1 -> V_5 -> V_40 , 1 ) ;
V_1 -> V_5 -> V_82 += V_11 + V_13 ;
F_8 ( V_1 , 1 ) ;
}
V_1 -> V_5 -> V_72 = V_1 -> V_5 -> V_82 ;
if ( V_1 -> V_5 -> V_33 )
{
V_79 = V_1 -> V_5 -> V_40 ;
V_79 -= 3 ;
V_79 [ 0 ] = ( V_1 -> V_5 -> V_82 >> 8 ) & ( V_35 >> 8 ) ;
if ( V_1 -> V_5 -> V_30 ) V_79 [ 0 ] |= V_36 ;
V_79 [ 1 ] = V_1 -> V_5 -> V_82 & 0xff ;
V_79 [ 2 ] = V_1 -> V_5 -> V_38 ;
V_1 -> V_5 -> V_72 += 3 ;
}
else
{
V_79 = V_1 -> V_5 -> V_40 ;
V_79 -= 2 ;
V_79 [ 0 ] = ( ( V_1 -> V_5 -> V_82 >> 8 ) & ( V_34 >> 8 ) ) | V_32 ;
V_79 [ 1 ] = V_1 -> V_5 -> V_82 & 0xff ;
V_1 -> V_5 -> V_72 += 2 ;
}
V_1 -> V_5 -> V_70 = V_79 ;
F_11 ( V_1 -> V_5 -> V_86 ) ;
V_1 -> V_5 -> V_64 = V_77 ;
V_1 -> V_5 -> V_65 = V_2 ;
V_1 -> V_5 -> V_74 = V_3 ;
V_1 -> V_5 -> V_71 = 0 ;
return ( F_18 ( V_1 , V_2 , V_77 ) ) ;
}
int F_21 ( T_1 * V_1 , unsigned long V_87 , int V_12 )
{
unsigned char * V_11 ;
int V_75 ;
if ( ( V_1 -> V_88 == 0 ) && ( V_12 >= 3 ) )
{
V_11 = ( unsigned char * ) V_1 -> V_89 -> V_90 ;
if ( V_11 [ 0 ] == V_91 )
{
V_75 = ( V_11 [ 1 ] << 8 ) | V_11 [ 2 ] ;
F_4 ( ( int ) V_87 , F_22 ( V_75 ) ) ;
}
}
if ( V_12 < 0 )
{
return ( V_12 ) ;
}
else
{
V_1 -> V_88 += V_12 ;
return ( 0 ) ;
}
}
int F_23 ( T_1 * V_1 )
{
int V_4 ;
V_4 = F_15 ( V_1 , & V_1 -> V_89 -> V_90 [ V_1 -> V_92 ] , V_1 -> V_88 ) ;
if ( V_4 == V_1 -> V_88 )
return ( 1 ) ;
if ( V_4 < 0 )
return ( - 1 ) ;
V_1 -> V_92 += V_4 ;
V_1 -> V_88 -= V_4 ;
return ( 0 ) ;
}
static int F_22 ( int V_8 )
{
int V_4 ;
switch ( V_8 )
{
case V_93 :
V_4 = V_94 ;
break;
case V_95 :
V_4 = V_96 ;
break;
case V_97 :
V_4 = V_98 ;
break;
case V_99 :
V_4 = V_100 ;
break;
default:
V_4 = V_101 ;
break;
}
return ( V_4 ) ;
}
