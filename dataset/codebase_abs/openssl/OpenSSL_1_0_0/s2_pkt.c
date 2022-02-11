static int F_1 ( T_1 * V_1 , void * V_2 , int V_3 , int V_4 )
{
int V_5 ;
unsigned char V_6 [ V_7 ] ;
unsigned char * V_8 ;
int V_9 ;
int V_10 ;
V_11:
if ( F_2 ( V_1 ) && ! V_1 -> V_12 )
{
V_5 = V_1 -> V_13 ( V_1 ) ;
if ( V_5 < 0 ) return ( V_5 ) ;
if ( V_5 == 0 )
{
F_3 ( V_14 , V_15 ) ;
return ( - 1 ) ;
}
}
F_4 () ;
V_1 -> V_16 = V_17 ;
if ( V_3 <= 0 ) return ( V_3 ) ;
if ( V_1 -> V_18 -> V_19 != 0 )
{
if ( V_3 > V_1 -> V_18 -> V_19 )
V_5 = V_1 -> V_18 -> V_19 ;
else
V_5 = V_3 ;
memcpy ( V_2 , V_1 -> V_18 -> V_20 , ( unsigned int ) V_5 ) ;
if ( ! V_4 )
{
V_1 -> V_18 -> V_19 -= V_5 ;
V_1 -> V_18 -> V_20 += V_5 ;
if ( V_1 -> V_18 -> V_19 == 0 )
V_1 -> V_21 = V_22 ;
}
return ( V_5 ) ;
}
if ( V_1 -> V_21 == V_22 )
{
if ( V_1 -> V_23 )
{
V_5 = F_5 ( V_1 , 5 , V_24 + 2 , 0 ) ;
if ( V_5 <= 0 ) return ( V_5 ) ;
V_1 -> V_23 = 0 ;
V_8 = V_1 -> V_25 ;
if ( ! ( ( V_8 [ 0 ] & 0x80 ) && (
( V_8 [ 2 ] == V_26 ) ||
( V_8 [ 2 ] == V_27 ) ) ) )
{
F_3 ( V_14 , V_28 ) ;
return ( - 1 ) ;
}
}
else
{
V_5 = F_5 ( V_1 , 2 , V_24 + 2 , 0 ) ;
if ( V_5 <= 0 ) return ( V_5 ) ;
}
V_1 -> V_21 = V_29 ;
V_8 = V_1 -> V_25 ;
V_1 -> V_18 -> V_30 = 0 ;
V_1 -> V_18 -> V_31 = ( ( ( unsigned int ) V_8 [ 0 ] ) << 8 ) | ( ( unsigned int ) V_8 [ 1 ] ) ;
if ( ( V_8 [ 0 ] & V_32 ) )
{
V_1 -> V_18 -> V_33 = 0 ;
V_1 -> V_18 -> V_31 &= V_34 ;
}
else
{
V_1 -> V_18 -> V_33 = 1 ;
V_1 -> V_18 -> V_31 &= V_35 ;
V_1 -> V_18 -> V_30 = ( ( V_8 [ 0 ] & V_36 ) ) ? 1 : 0 ;
}
}
if ( V_1 -> V_21 == V_29 )
{
V_5 = V_1 -> V_18 -> V_31 + 2 + V_1 -> V_18 -> V_33 ;
if ( V_5 > ( int ) V_1 -> V_37 )
{
V_5 -= V_1 -> V_37 ;
V_9 = F_5 ( V_1 , ( unsigned int ) V_5 , ( unsigned int ) V_5 , 1 ) ;
if ( V_9 <= 0 ) return ( V_9 ) ;
}
V_8 = & ( V_1 -> V_25 [ 2 ] ) ;
V_1 -> V_21 = V_22 ;
if ( V_1 -> V_18 -> V_33 )
V_1 -> V_18 -> V_38 = * ( V_8 ++ ) ;
else V_1 -> V_18 -> V_38 = 0 ;
if ( V_1 -> V_18 -> V_39 )
{
V_10 = 0 ;
V_1 -> V_18 -> V_40 = V_8 ;
V_1 -> V_18 -> V_20 = V_8 ;
if ( V_1 -> V_18 -> V_38 )
{
F_3 ( V_14 , V_41 ) ;
return ( - 1 ) ;
}
}
else
{
V_10 = F_6 ( V_1 -> V_42 ) ;
if ( V_10 < 0 )
return - 1 ;
F_7 ( V_10 <= V_7 ) ;
V_1 -> V_18 -> V_40 = V_8 ;
V_1 -> V_18 -> V_20 = & V_8 [ V_10 ] ;
if ( V_1 -> V_18 -> V_38 + V_10 > V_1 -> V_18 -> V_31 )
{
F_3 ( V_14 , V_41 ) ;
return ( - 1 ) ;
}
}
V_1 -> V_18 -> V_19 = V_1 -> V_18 -> V_31 ;
if ( ( ! V_1 -> V_18 -> V_39 ) &&
( V_1 -> V_18 -> V_31 >= ( unsigned int ) V_10 ) )
{
F_8 ( V_1 , 0 ) ;
V_1 -> V_18 -> V_19 -= V_10 ;
F_9 ( V_1 , V_6 , 0 ) ;
V_1 -> V_18 -> V_19 -= V_1 -> V_18 -> V_38 ;
if ( ( memcmp ( V_6 , V_1 -> V_18 -> V_40 ,
( unsigned int ) V_10 ) != 0 ) ||
( V_1 -> V_18 -> V_31 % F_10 ( V_1 -> V_43 ) != 0 ) )
{
F_3 ( V_14 , V_44 ) ;
return ( - 1 ) ;
}
}
F_11 ( V_1 -> V_18 -> V_45 ) ;
goto V_11;
}
else
{
F_3 ( V_14 , V_46 ) ;
return ( - 1 ) ;
}
}
int F_12 ( T_1 * V_1 , void * V_2 , int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , 0 ) ;
}
int F_13 ( T_1 * V_1 , void * V_2 , int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , 1 ) ;
}
static int F_5 ( T_1 * V_1 , unsigned int V_5 , unsigned int V_47 ,
unsigned int V_48 )
{
int V_9 , V_49 , V_50 ;
if ( V_1 -> V_18 -> V_51 >= ( int ) V_5 )
{
if ( V_48 )
V_1 -> V_37 += V_5 ;
else
{
V_1 -> V_25 = & ( V_1 -> V_18 -> V_52 [ V_1 -> V_18 -> V_53 ] ) ;
V_1 -> V_37 = V_5 ;
}
V_1 -> V_18 -> V_51 -= V_5 ;
V_1 -> V_18 -> V_53 += V_5 ;
return ( V_5 ) ;
}
if ( ! V_1 -> V_54 ) V_47 = V_5 ;
if ( V_47 > ( unsigned int ) ( V_24 + 2 ) )
V_47 = V_24 + 2 ;
V_49 = 0 ;
if ( ( V_1 -> V_18 -> V_51 != 0 ) || ( ( V_1 -> V_37 != 0 ) && V_48 ) )
{
V_50 = V_1 -> V_18 -> V_51 ;
if ( V_48 )
{
V_49 = V_1 -> V_37 ;
if ( V_1 -> V_25 != V_1 -> V_18 -> V_52 )
memcpy ( V_1 -> V_18 -> V_52 , V_1 -> V_25 ,
( unsigned int ) V_50 + V_49 ) ;
}
else if ( V_1 -> V_18 -> V_53 != 0 )
{
memcpy ( V_1 -> V_18 -> V_52 , & ( V_1 -> V_18 -> V_52 [ V_1 -> V_18 -> V_53 ] ) ,
( unsigned int ) V_50 ) ;
V_1 -> V_18 -> V_53 = 0 ;
}
V_1 -> V_18 -> V_51 = 0 ;
}
else
V_50 = 0 ;
V_1 -> V_25 = V_1 -> V_18 -> V_52 ;
while ( V_50 < ( int ) V_5 )
{
F_4 () ;
if ( V_1 -> V_55 != NULL )
{
V_1 -> V_16 = V_56 ;
V_9 = F_14 ( V_1 -> V_55 , ( char * ) & ( V_1 -> V_18 -> V_52 [ V_49 + V_50 ] ) ,
V_47 - V_50 ) ;
}
else
{
F_3 ( V_57 , V_58 ) ;
V_9 = - 1 ;
}
#ifdef F_15
if ( V_1 -> V_59 & 0x01 ) F_16 ( 1 ) ;
#endif
if ( V_9 <= 0 )
{
V_1 -> V_18 -> V_51 += V_50 ;
return ( V_9 ) ;
}
V_50 += V_9 ;
}
if ( V_50 > ( int ) V_5 )
{
V_1 -> V_18 -> V_53 = V_5 + V_49 ;
V_1 -> V_18 -> V_51 = V_50 - V_5 ;
}
else
{
V_1 -> V_18 -> V_53 = 0 ;
V_1 -> V_18 -> V_51 = 0 ;
}
if ( V_48 )
V_1 -> V_37 += V_5 ;
else
V_1 -> V_37 = V_5 ;
V_1 -> V_16 = V_17 ;
return ( V_5 ) ;
}
int F_17 ( T_1 * V_1 , const void * V_60 , int V_3 )
{
const unsigned char * V_2 = V_60 ;
unsigned int V_5 , V_61 ;
int V_9 ;
if ( F_2 ( V_1 ) && ! V_1 -> V_12 )
{
V_9 = V_1 -> V_13 ( V_1 ) ;
if ( V_9 < 0 ) return ( V_9 ) ;
if ( V_9 == 0 )
{
F_3 ( V_62 , V_15 ) ;
return ( - 1 ) ;
}
}
if ( V_1 -> error )
{
F_18 ( V_1 ) ;
if ( V_1 -> error )
return ( - 1 ) ;
}
F_4 () ;
V_1 -> V_16 = V_17 ;
if ( V_3 <= 0 ) return ( V_3 ) ;
V_61 = V_1 -> V_18 -> V_63 ;
V_1 -> V_18 -> V_63 = 0 ;
V_5 = ( V_3 - V_61 ) ;
for (; ; )
{
V_9 = F_19 ( V_1 , & ( V_2 [ V_61 ] ) , V_5 ) ;
if ( V_9 <= 0 )
{
V_1 -> V_18 -> V_63 = V_61 ;
return ( V_9 ) ;
}
if ( ( V_9 == ( int ) V_5 ) ||
( V_1 -> V_64 & V_65 ) )
{
return ( V_61 + V_9 ) ;
}
V_5 -= V_9 ;
V_61 += V_9 ;
}
}
static int F_20 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
int V_9 ;
if ( ( V_1 -> V_18 -> V_66 > ( int ) V_3 ) ||
( ( V_1 -> V_18 -> V_67 != V_2 ) &&
! ( V_1 -> V_64 & V_68 ) ) )
{
F_3 ( V_69 , V_70 ) ;
return ( - 1 ) ;
}
for (; ; )
{
F_4 () ;
if ( V_1 -> V_71 != NULL )
{
V_1 -> V_16 = V_72 ;
V_9 = F_21 ( V_1 -> V_71 ,
( char * ) & ( V_1 -> V_18 -> V_73 [ V_1 -> V_18 -> V_74 ] ) ,
( unsigned int ) V_1 -> V_18 -> V_75 ) ;
}
else
{
F_3 ( V_69 , V_76 ) ;
V_9 = - 1 ;
}
#ifdef F_15
if ( V_1 -> V_59 & 0x01 ) F_16 ( 1 ) ;
#endif
if ( V_9 == V_1 -> V_18 -> V_75 )
{
V_1 -> V_18 -> V_75 = 0 ;
V_1 -> V_16 = V_17 ;
return ( V_1 -> V_18 -> V_77 ) ;
}
else if ( V_9 <= 0 )
return ( V_9 ) ;
V_1 -> V_18 -> V_74 += V_9 ;
V_1 -> V_18 -> V_75 -= V_9 ;
}
}
static int F_19 ( T_1 * V_1 , const unsigned char * V_2 , unsigned int V_3 )
{
unsigned int V_78 , V_79 , V_80 , V_8 , V_81 ;
int V_10 ;
register unsigned char * V_82 ;
V_80 = V_3 ;
if ( V_1 -> V_18 -> V_75 != 0 ) return ( F_20 ( V_1 , V_2 , V_3 ) ) ;
if ( V_1 -> V_18 -> V_39 )
V_10 = 0 ;
else
{
V_10 = F_6 ( V_1 -> V_83 ) ;
if ( V_10 < 0 )
return - 1 ;
}
if ( V_1 -> V_18 -> V_39 )
{
if ( V_3 > V_24 )
V_3 = V_24 ;
V_8 = 0 ;
V_1 -> V_18 -> V_33 = 0 ;
}
else
{
V_81 = F_10 ( V_1 -> V_43 ) ;
V_78 = V_3 + V_10 ;
if ( ( V_78 > V_84 ) &&
( ! V_1 -> V_18 -> V_30 ) )
{
if ( V_78 > V_24 )
V_78 = V_24 ;
V_79 = V_78 - ( V_78 % V_81 ) ;
V_3 = V_79 - V_10 ;
V_1 -> V_18 -> V_33 = 0 ;
V_8 = 0 ;
}
else if ( ( V_81 <= 1 ) && ( ! V_1 -> V_18 -> V_30 ) )
{
V_1 -> V_18 -> V_33 = 0 ;
V_8 = 0 ;
}
else
{
V_8 = ( V_78 % V_81 ) ;
V_8 = ( V_8 == 0 ) ? 0 : ( V_81 - V_8 ) ;
if ( V_1 -> V_18 -> V_30 )
{
V_1 -> V_18 -> V_33 = 1 ;
if ( V_78 > V_84 )
V_78 = V_84 ;
}
else
V_1 -> V_18 -> V_33 = ( V_8 == 0 ) ? 0 : 1 ;
}
}
V_1 -> V_18 -> V_85 = V_3 ;
V_1 -> V_18 -> V_38 = V_8 ;
V_1 -> V_18 -> V_40 = & ( V_1 -> V_18 -> V_86 [ 3 ] ) ;
V_1 -> V_18 -> V_87 = & ( V_1 -> V_18 -> V_86 [ 3 + V_10 ] ) ;
memcpy ( V_1 -> V_18 -> V_87 , V_2 , V_3 ) ;
if ( V_8 )
memset ( & ( V_1 -> V_18 -> V_87 [ V_3 ] ) , 0 , V_8 ) ;
if ( ! V_1 -> V_18 -> V_39 )
{
V_1 -> V_18 -> V_88 = V_3 + V_8 ;
F_9 ( V_1 , V_1 -> V_18 -> V_40 , 1 ) ;
V_1 -> V_18 -> V_85 += V_8 + V_10 ;
F_8 ( V_1 , 1 ) ;
}
V_1 -> V_18 -> V_75 = V_1 -> V_18 -> V_85 ;
if ( V_1 -> V_18 -> V_33 )
{
V_82 = V_1 -> V_18 -> V_40 ;
V_82 -= 3 ;
V_82 [ 0 ] = ( V_1 -> V_18 -> V_85 >> 8 ) & ( V_35 >> 8 ) ;
if ( V_1 -> V_18 -> V_30 ) V_82 [ 0 ] |= V_36 ;
V_82 [ 1 ] = V_1 -> V_18 -> V_85 & 0xff ;
V_82 [ 2 ] = V_1 -> V_18 -> V_38 ;
V_1 -> V_18 -> V_75 += 3 ;
}
else
{
V_82 = V_1 -> V_18 -> V_40 ;
V_82 -= 2 ;
V_82 [ 0 ] = ( ( V_1 -> V_18 -> V_85 >> 8 ) & ( V_34 >> 8 ) ) | V_32 ;
V_82 [ 1 ] = V_1 -> V_18 -> V_85 & 0xff ;
V_1 -> V_18 -> V_75 += 2 ;
}
V_1 -> V_18 -> V_73 = V_82 ;
F_11 ( V_1 -> V_18 -> V_89 ) ;
V_1 -> V_18 -> V_66 = V_80 ;
V_1 -> V_18 -> V_67 = V_2 ;
V_1 -> V_18 -> V_77 = V_3 ;
V_1 -> V_18 -> V_74 = 0 ;
return ( F_20 ( V_1 , V_2 , V_80 ) ) ;
}
int F_22 ( T_1 * V_1 , unsigned long V_90 , int V_9 )
{
unsigned char * V_8 ;
int V_78 ;
if ( V_9 < 0 )
{
return ( V_9 ) ;
}
else
{
V_1 -> V_91 += V_9 ;
if ( V_1 -> V_91 >= 3 )
{
V_8 = ( unsigned char * ) V_1 -> V_92 -> V_93 ;
if ( V_8 [ 0 ] == V_94 )
{
V_78 = ( V_8 [ 1 ] << 8 ) | V_8 [ 2 ] ;
F_3 ( ( int ) V_90 , F_23 ( V_78 ) ) ;
V_1 -> V_91 -= 3 ;
if ( V_1 -> V_91 > 0 )
memmove ( V_8 , V_8 + 3 , V_1 -> V_91 ) ;
}
}
return ( 0 ) ;
}
}
int F_24 ( T_1 * V_1 )
{
int V_95 ;
V_95 = F_17 ( V_1 , & V_1 -> V_92 -> V_93 [ V_1 -> V_96 ] , V_1 -> V_91 ) ;
if ( V_95 == V_1 -> V_91 )
{
if ( V_1 -> V_97 )
V_1 -> V_97 ( 1 , V_1 -> V_98 , 0 , V_1 -> V_92 -> V_93 , ( V_99 ) ( V_1 -> V_96 + V_1 -> V_91 ) , V_1 , V_1 -> V_100 ) ;
return ( 1 ) ;
}
if ( V_95 < 0 )
return ( - 1 ) ;
V_1 -> V_96 += V_95 ;
V_1 -> V_91 -= V_95 ;
return ( 0 ) ;
}
static int F_23 ( int V_5 )
{
int V_95 ;
switch ( V_5 )
{
case V_101 :
V_95 = V_102 ;
break;
case V_103 :
V_95 = V_104 ;
break;
case V_105 :
V_95 = V_106 ;
break;
case V_107 :
V_95 = V_108 ;
break;
default:
V_95 = V_109 ;
break;
}
return ( V_95 ) ;
}
