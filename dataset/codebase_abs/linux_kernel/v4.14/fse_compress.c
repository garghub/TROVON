T_1 F_1 ( T_2 * V_1 , const short * V_2 , unsigned V_3 , unsigned V_4 , void * V_5 , T_1 V_6 )
{
T_3 const V_7 = 1 << V_4 ;
T_3 const V_8 = V_7 - 1 ;
void * const V_9 = V_1 ;
T_4 * const V_10 = ( ( T_4 * ) V_9 ) + 2 ;
void * const V_11 = ( ( T_3 * ) V_9 ) + 1 + ( V_4 ? V_7 >> 1 : 1 ) ;
T_5 * const V_12 = ( T_5 * ) ( V_11 ) ;
T_3 const V_13 = F_2 ( V_7 ) ;
T_3 V_14 = V_7 - 1 ;
T_3 * V_15 ;
T_6 * V_16 ;
T_1 V_17 = 0 ;
V_15 = ( T_3 * ) V_5 + V_17 ;
V_17 += V_18 + 2 ;
V_16 = ( T_6 * ) ( ( T_3 * ) V_5 + V_17 ) ;
V_17 += F_3 ( sizeof( T_6 ) * ( ( T_1 ) 1 << V_4 ) , sizeof( T_3 ) ) >> 2 ;
if ( ( V_17 << 2 ) > V_6 )
return ERROR ( V_19 ) ;
V_5 = ( T_3 * ) V_5 + V_17 ;
V_6 -= ( V_17 << 2 ) ;
V_10 [ - 2 ] = ( T_4 ) V_4 ;
V_10 [ - 1 ] = ( T_4 ) V_3 ;
{
T_3 V_20 ;
V_15 [ 0 ] = 0 ;
for ( V_20 = 1 ; V_20 <= V_3 + 1 ; V_20 ++ ) {
if ( V_2 [ V_20 - 1 ] == - 1 ) {
V_15 [ V_20 ] = V_15 [ V_20 - 1 ] + 1 ;
V_16 [ V_14 -- ] = ( T_6 ) ( V_20 - 1 ) ;
} else {
V_15 [ V_20 ] = V_15 [ V_20 - 1 ] + V_2 [ V_20 - 1 ] ;
}
}
V_15 [ V_3 + 1 ] = V_7 + 1 ;
}
{
T_3 V_21 = 0 ;
T_3 V_22 ;
for ( V_22 = 0 ; V_22 <= V_3 ; V_22 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_2 [ V_22 ] ; V_23 ++ ) {
V_16 [ V_21 ] = ( T_6 ) V_22 ;
V_21 = ( V_21 + V_13 ) & V_8 ;
while ( V_21 > V_14 )
V_21 = ( V_21 + V_13 ) & V_8 ;
}
}
if ( V_21 != 0 )
return ERROR ( V_24 ) ;
}
{
T_3 V_20 ;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ ) {
T_6 V_25 = V_16 [ V_20 ] ;
V_10 [ V_15 [ V_25 ] ++ ] = ( T_4 ) ( V_7 + V_20 ) ;
}
}
{
unsigned V_26 = 0 ;
unsigned V_25 ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
switch ( V_2 [ V_25 ] ) {
case 0 : break;
case - 1 :
case 1 :
V_12 [ V_25 ] . V_27 = ( V_4 << 16 ) - ( 1 << V_4 ) ;
V_12 [ V_25 ] . V_28 = V_26 - 1 ;
V_26 ++ ;
break;
default: {
T_3 const V_29 = V_4 - F_4 ( V_2 [ V_25 ] - 1 ) ;
T_3 const V_30 = V_2 [ V_25 ] << V_29 ;
V_12 [ V_25 ] . V_27 = ( V_29 << 16 ) - V_30 ;
V_12 [ V_25 ] . V_28 = V_26 - V_2 [ V_25 ] ;
V_26 += V_2 [ V_25 ] ;
}
}
}
}
return 0 ;
}
T_1 F_5 ( unsigned V_3 , unsigned V_4 )
{
T_1 const V_31 = ( ( ( V_3 + 1 ) * V_4 ) >> 3 ) + 3 ;
return V_3 ? V_31 : V_32 ;
}
static T_1 F_6 ( void * V_33 , T_1 V_34 , const short * V_2 , unsigned V_3 , unsigned V_4 ,
unsigned V_35 )
{
T_7 * const V_36 = ( T_7 * ) V_33 ;
T_7 * V_37 = V_36 ;
T_7 * const V_38 = V_36 + V_34 ;
int V_39 ;
const int V_7 = 1 << V_4 ;
int V_40 ;
int V_41 ;
T_3 V_42 ;
int V_43 ;
unsigned V_44 = 0 ;
int V_45 = 0 ;
V_42 = 0 ;
V_43 = 0 ;
V_42 += ( V_4 - V_46 ) << V_43 ;
V_43 += 4 ;
V_40 = V_7 + 1 ;
V_41 = V_7 ;
V_39 = V_4 + 1 ;
while ( V_40 > 1 ) {
if ( V_45 ) {
unsigned V_47 = V_44 ;
while ( ! V_2 [ V_44 ] )
V_44 ++ ;
while ( V_44 >= V_47 + 24 ) {
V_47 += 24 ;
V_42 += 0xFFFFU << V_43 ;
if ( ( ! V_35 ) && ( V_37 > V_38 - 2 ) )
return ERROR ( V_48 ) ;
V_37 [ 0 ] = ( T_7 ) V_42 ;
V_37 [ 1 ] = ( T_7 ) ( V_42 >> 8 ) ;
V_37 += 2 ;
V_42 >>= 16 ;
}
while ( V_44 >= V_47 + 3 ) {
V_47 += 3 ;
V_42 += 3 << V_43 ;
V_43 += 2 ;
}
V_42 += ( V_44 - V_47 ) << V_43 ;
V_43 += 2 ;
if ( V_43 > 16 ) {
if ( ( ! V_35 ) && ( V_37 > V_38 - 2 ) )
return ERROR ( V_48 ) ;
V_37 [ 0 ] = ( T_7 ) V_42 ;
V_37 [ 1 ] = ( T_7 ) ( V_42 >> 8 ) ;
V_37 += 2 ;
V_42 >>= 16 ;
V_43 -= 16 ;
}
}
{
int V_49 = V_2 [ V_44 ++ ] ;
int const V_50 = ( 2 * V_41 - 1 ) - V_40 ;
V_40 -= V_49 < 0 ? - V_49 : V_49 ;
V_49 ++ ;
if ( V_49 >= V_41 )
V_49 += V_50 ;
V_42 += V_49 << V_43 ;
V_43 += V_39 ;
V_43 -= ( V_49 < V_50 ) ;
V_45 = ( V_49 == 1 ) ;
if ( V_40 < 1 )
return ERROR ( V_24 ) ;
while ( V_40 < V_41 )
V_39 -- , V_41 >>= 1 ;
}
if ( V_43 > 16 ) {
if ( ( ! V_35 ) && ( V_37 > V_38 - 2 ) )
return ERROR ( V_48 ) ;
V_37 [ 0 ] = ( T_7 ) V_42 ;
V_37 [ 1 ] = ( T_7 ) ( V_42 >> 8 ) ;
V_37 += 2 ;
V_42 >>= 16 ;
V_43 -= 16 ;
}
}
if ( ( ! V_35 ) && ( V_37 > V_38 - 2 ) )
return ERROR ( V_48 ) ;
V_37 [ 0 ] = ( T_7 ) V_42 ;
V_37 [ 1 ] = ( T_7 ) ( V_42 >> 8 ) ;
V_37 += ( V_43 + 7 ) / 8 ;
if ( V_44 > V_3 + 1 )
return ERROR ( V_24 ) ;
return ( V_37 - V_36 ) ;
}
T_1 F_7 ( void * V_51 , T_1 V_52 , const short * V_2 , unsigned V_3 , unsigned V_4 )
{
if ( V_4 > V_53 )
return ERROR ( V_19 ) ;
if ( V_4 < V_46 )
return ERROR ( V_24 ) ;
if ( V_52 < F_5 ( V_3 , V_4 ) )
return F_6 ( V_51 , V_52 , V_2 , V_3 , V_4 , 0 ) ;
return F_6 ( V_51 , V_52 , V_2 , V_3 , V_4 , 1 ) ;
}
T_1 F_8 ( unsigned * V_49 , unsigned * V_54 , const void * V_55 , T_1 V_56 )
{
const T_7 * V_57 = ( const T_7 * ) V_55 ;
const T_7 * const V_58 = V_57 + V_56 ;
unsigned V_3 = * V_54 ;
unsigned V_50 = 0 ;
memset ( V_49 , 0 , ( V_3 + 1 ) * sizeof( * V_49 ) ) ;
if ( V_56 == 0 ) {
* V_54 = 0 ;
return 0 ;
}
while ( V_57 < V_58 )
V_49 [ * V_57 ++ ] ++ ;
while ( ! V_49 [ V_3 ] )
V_3 -- ;
* V_54 = V_3 ;
{
T_3 V_25 ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ )
if ( V_49 [ V_25 ] > V_50 )
V_50 = V_49 [ V_25 ] ;
}
return ( T_1 ) V_50 ;
}
static T_1 F_9 ( unsigned * V_49 , unsigned * V_54 , const void * V_59 , T_1 V_60 , unsigned V_61 ,
unsigned * const V_62 )
{
const T_7 * V_57 = ( const T_7 * ) V_59 ;
const T_7 * const V_63 = V_57 + V_60 ;
unsigned V_3 = * V_54 ;
unsigned V_50 = 0 ;
T_3 * const V_64 = V_62 ;
T_3 * const V_65 = V_64 + 256 ;
T_3 * const V_66 = V_65 + 256 ;
T_3 * const V_67 = V_66 + 256 ;
memset ( V_64 , 0 , 4 * 256 * sizeof( unsigned ) ) ;
if ( ! V_60 ) {
memset ( V_49 , 0 , V_3 + 1 ) ;
* V_54 = 0 ;
return 0 ;
}
if ( ! V_3 )
V_3 = 255 ;
{
T_3 V_68 = F_10 ( V_57 ) ;
V_57 += 4 ;
while ( V_57 < V_63 - 15 ) {
T_3 V_69 = V_68 ;
V_68 = F_10 ( V_57 ) ;
V_57 += 4 ;
V_64 [ ( T_7 ) V_69 ] ++ ;
V_65 [ ( T_7 ) ( V_69 >> 8 ) ] ++ ;
V_66 [ ( T_7 ) ( V_69 >> 16 ) ] ++ ;
V_67 [ V_69 >> 24 ] ++ ;
V_69 = V_68 ;
V_68 = F_10 ( V_57 ) ;
V_57 += 4 ;
V_64 [ ( T_7 ) V_69 ] ++ ;
V_65 [ ( T_7 ) ( V_69 >> 8 ) ] ++ ;
V_66 [ ( T_7 ) ( V_69 >> 16 ) ] ++ ;
V_67 [ V_69 >> 24 ] ++ ;
V_69 = V_68 ;
V_68 = F_10 ( V_57 ) ;
V_57 += 4 ;
V_64 [ ( T_7 ) V_69 ] ++ ;
V_65 [ ( T_7 ) ( V_69 >> 8 ) ] ++ ;
V_66 [ ( T_7 ) ( V_69 >> 16 ) ] ++ ;
V_67 [ V_69 >> 24 ] ++ ;
V_69 = V_68 ;
V_68 = F_10 ( V_57 ) ;
V_57 += 4 ;
V_64 [ ( T_7 ) V_69 ] ++ ;
V_65 [ ( T_7 ) ( V_69 >> 8 ) ] ++ ;
V_66 [ ( T_7 ) ( V_69 >> 16 ) ] ++ ;
V_67 [ V_69 >> 24 ] ++ ;
}
V_57 -= 4 ;
}
while ( V_57 < V_63 )
V_64 [ * V_57 ++ ] ++ ;
if ( V_61 ) {
T_3 V_25 ;
for ( V_25 = 255 ; V_25 > V_3 ; V_25 -- ) {
V_64 [ V_25 ] += V_65 [ V_25 ] + V_66 [ V_25 ] + V_67 [ V_25 ] ;
if ( V_64 [ V_25 ] )
return ERROR ( V_70 ) ;
}
}
{
T_3 V_25 ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
V_49 [ V_25 ] = V_64 [ V_25 ] + V_65 [ V_25 ] + V_66 [ V_25 ] + V_67 [ V_25 ] ;
if ( V_49 [ V_25 ] > V_50 )
V_50 = V_49 [ V_25 ] ;
}
}
while ( ! V_49 [ V_3 ] )
V_3 -- ;
* V_54 = V_3 ;
return ( T_1 ) V_50 ;
}
T_1 F_11 ( unsigned * V_49 , unsigned * V_54 , const void * V_59 , T_1 V_60 , unsigned * V_62 )
{
if ( V_60 < 1500 )
return F_8 ( V_49 , V_54 , V_59 , V_60 ) ;
return F_9 ( V_49 , V_54 , V_59 , V_60 , 0 , V_62 ) ;
}
T_1 F_12 ( unsigned * V_49 , unsigned * V_54 , const void * V_59 , T_1 V_60 , unsigned * V_62 )
{
if ( * V_54 < 255 )
return F_9 ( V_49 , V_54 , V_59 , V_60 , 1 , V_62 ) ;
* V_54 = 255 ;
return F_11 ( V_49 , V_54 , V_59 , V_60 , V_62 ) ;
}
T_1 F_13 ( unsigned V_3 , unsigned V_4 )
{
if ( V_4 > V_53 )
return ERROR ( V_19 ) ;
return F_14 ( V_4 , V_3 ) * sizeof( T_3 ) ;
}
static unsigned F_15 ( T_1 V_56 , unsigned V_3 )
{
T_3 V_71 = F_4 ( ( T_3 ) ( V_56 - 1 ) ) + 1 ;
T_3 V_72 = F_4 ( V_3 ) + 2 ;
T_3 V_73 = V_71 < V_72 ? V_71 : V_72 ;
return V_73 ;
}
unsigned F_16 ( unsigned V_74 , T_1 V_56 , unsigned V_3 , unsigned V_75 )
{
T_3 V_76 = F_4 ( ( T_3 ) ( V_56 - 1 ) ) - V_75 ;
T_3 V_4 = V_74 ;
T_3 V_73 = F_15 ( V_56 , V_3 ) ;
if ( V_4 == 0 )
V_4 = V_77 ;
if ( V_76 < V_4 )
V_4 = V_76 ;
if ( V_73 > V_4 )
V_4 = V_73 ;
if ( V_4 < V_46 )
V_4 = V_46 ;
if ( V_4 > V_53 )
V_4 = V_53 ;
return V_4 ;
}
unsigned F_17 ( unsigned V_74 , T_1 V_56 , unsigned V_3 )
{
return F_16 ( V_74 , V_56 , V_3 , 2 ) ;
}
static T_1 F_18 ( short * V_78 , T_3 V_4 , const unsigned * V_49 , T_1 V_26 , T_3 V_3 )
{
short const V_79 = - 2 ;
T_3 V_25 ;
T_3 V_80 = 0 ;
T_3 V_81 ;
T_3 const V_82 = ( T_3 ) ( V_26 >> V_4 ) ;
T_3 V_83 = ( T_3 ) ( ( V_26 * 3 ) >> ( V_4 + 1 ) ) ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
if ( V_49 [ V_25 ] == 0 ) {
V_78 [ V_25 ] = 0 ;
continue;
}
if ( V_49 [ V_25 ] <= V_82 ) {
V_78 [ V_25 ] = - 1 ;
V_80 ++ ;
V_26 -= V_49 [ V_25 ] ;
continue;
}
if ( V_49 [ V_25 ] <= V_83 ) {
V_78 [ V_25 ] = 1 ;
V_80 ++ ;
V_26 -= V_49 [ V_25 ] ;
continue;
}
V_78 [ V_25 ] = V_79 ;
}
V_81 = ( 1 << V_4 ) - V_80 ;
if ( ( V_26 / V_81 ) > V_83 ) {
V_83 = ( T_3 ) ( ( V_26 * 3 ) / ( V_81 * 2 ) ) ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
if ( ( V_78 [ V_25 ] == V_79 ) && ( V_49 [ V_25 ] <= V_83 ) ) {
V_78 [ V_25 ] = 1 ;
V_80 ++ ;
V_26 -= V_49 [ V_25 ] ;
continue;
}
}
V_81 = ( 1 << V_4 ) - V_80 ;
}
if ( V_80 == V_3 + 1 ) {
T_3 V_84 = 0 , V_85 = 0 ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ )
if ( V_49 [ V_25 ] > V_85 )
V_84 = V_25 , V_85 = V_49 [ V_25 ] ;
V_78 [ V_84 ] += ( short ) V_81 ;
return 0 ;
}
if ( V_26 == 0 ) {
for ( V_25 = 0 ; V_81 > 0 ; V_25 = ( V_25 + 1 ) % ( V_3 + 1 ) )
if ( V_78 [ V_25 ] > 0 )
V_81 -- , V_78 [ V_25 ] ++ ;
return 0 ;
}
{
T_8 const V_86 = 62 - V_4 ;
T_8 const V_87 = ( 1ULL << ( V_86 - 1 ) ) - 1 ;
T_8 const V_88 = F_19 ( ( ( ( T_8 ) 1 << V_86 ) * V_81 ) + V_87 , ( T_3 ) V_26 ) ;
T_8 V_89 = V_87 ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
if ( V_78 [ V_25 ] == V_79 ) {
T_8 const V_58 = V_89 + ( V_49 [ V_25 ] * V_88 ) ;
T_3 const V_90 = ( T_3 ) ( V_89 >> V_86 ) ;
T_3 const V_91 = ( T_3 ) ( V_58 >> V_86 ) ;
T_3 const V_92 = V_91 - V_90 ;
if ( V_92 < 1 )
return ERROR ( V_24 ) ;
V_78 [ V_25 ] = ( short ) V_92 ;
V_89 = V_58 ;
}
}
}
return 0 ;
}
T_1 F_20 ( short * V_2 , unsigned V_4 , const unsigned * V_49 , T_1 V_26 , unsigned V_3 )
{
if ( V_4 == 0 )
V_4 = V_77 ;
if ( V_4 < V_46 )
return ERROR ( V_24 ) ;
if ( V_4 > V_53 )
return ERROR ( V_19 ) ;
if ( V_4 < F_15 ( V_26 , V_3 ) )
return ERROR ( V_24 ) ;
{
T_3 const V_93 [] = { 0 , 473195 , 504333 , 520860 , 550000 , 700000 , 750000 , 830000 } ;
T_8 const V_94 = 62 - V_4 ;
T_8 const V_13 = F_19 ( ( T_8 ) 1 << 62 , ( T_3 ) V_26 ) ;
T_8 const V_95 = 1ULL << ( V_94 - 20 ) ;
int V_96 = 1 << V_4 ;
unsigned V_25 ;
unsigned V_97 = 0 ;
short V_98 = 0 ;
T_3 V_82 = ( T_3 ) ( V_26 >> V_4 ) ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
if ( V_49 [ V_25 ] == V_26 )
return 0 ;
if ( V_49 [ V_25 ] == 0 ) {
V_2 [ V_25 ] = 0 ;
continue;
}
if ( V_49 [ V_25 ] <= V_82 ) {
V_2 [ V_25 ] = - 1 ;
V_96 -- ;
} else {
short V_99 = ( short ) ( ( V_49 [ V_25 ] * V_13 ) >> V_94 ) ;
if ( V_99 < 8 ) {
T_8 V_100 = V_95 * V_93 [ V_99 ] ;
V_99 += ( V_49 [ V_25 ] * V_13 ) - ( ( T_8 ) V_99 << V_94 ) > V_100 ;
}
if ( V_99 > V_98 )
V_98 = V_99 , V_97 = V_25 ;
V_2 [ V_25 ] = V_99 ;
V_96 -= V_99 ;
}
}
if ( - V_96 >= ( V_2 [ V_97 ] >> 1 ) ) {
T_1 const V_101 = F_18 ( V_2 , V_4 , V_49 , V_26 , V_3 ) ;
if ( F_21 ( V_101 ) )
return V_101 ;
} else
V_2 [ V_97 ] += ( short ) V_96 ;
}
return V_4 ;
}
T_1 F_22 ( T_2 * V_1 , unsigned V_39 )
{
const unsigned V_7 = 1 << V_39 ;
const unsigned V_8 = V_7 - 1 ;
const unsigned V_3 = V_8 ;
void * const V_9 = V_1 ;
T_4 * const V_10 = ( ( T_4 * ) V_9 ) + 2 ;
void * const V_11 = ( ( T_3 * ) V_9 ) + 1 + ( V_7 >> 1 ) ;
T_5 * const V_12 = ( T_5 * ) ( V_11 ) ;
unsigned V_25 ;
if ( V_39 < 1 )
return ERROR ( V_24 ) ;
V_10 [ - 2 ] = ( T_4 ) V_39 ;
V_10 [ - 1 ] = ( T_4 ) V_3 ;
for ( V_25 = 0 ; V_25 < V_7 ; V_25 ++ )
V_10 [ V_25 ] = ( T_4 ) ( V_7 + V_25 ) ;
{
const T_3 V_27 = ( V_39 << 16 ) - ( 1 << V_39 ) ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ ) {
V_12 [ V_25 ] . V_27 = V_27 ;
V_12 [ V_25 ] . V_28 = V_25 - 1 ;
}
}
return 0 ;
}
T_1 F_23 ( T_2 * V_1 , T_7 V_102 )
{
void * V_9 = V_1 ;
T_4 * V_10 = ( ( T_4 * ) V_9 ) + 2 ;
void * V_103 = ( T_3 * ) V_9 + 2 ;
T_5 * V_12 = ( T_5 * ) V_103 ;
V_10 [ - 2 ] = ( T_4 ) 0 ;
V_10 [ - 1 ] = ( T_4 ) V_102 ;
V_10 [ 0 ] = 0 ;
V_10 [ 1 ] = 0 ;
V_12 [ V_102 ] . V_27 = 0 ;
V_12 [ V_102 ] . V_28 = 0 ;
return 0 ;
}
static T_1 F_24 ( void * V_104 , T_1 V_105 , const void * V_55 , T_1 V_56 , const T_2 * V_1 , const unsigned V_106 )
{
const T_7 * const V_107 = ( const T_7 * ) V_55 ;
const T_7 * const V_63 = V_107 + V_56 ;
const T_7 * V_57 = V_63 ;
T_9 V_108 ;
T_10 V_109 , V_110 ;
if ( V_56 <= 2 )
return 0 ;
{
T_1 const V_111 = F_25 ( & V_108 , V_104 , V_105 ) ;
if ( F_21 ( V_111 ) )
return 0 ;
}
#define F_26 ( V_25 ) (fast ? BIT_flushBitsFast(s) : BIT_flushBits(s))
if ( V_56 & 1 ) {
F_27 ( & V_109 , V_1 , * -- V_57 ) ;
F_27 ( & V_110 , V_1 , * -- V_57 ) ;
F_28 ( & V_108 , & V_109 , * -- V_57 ) ;
F_26 ( & V_108 ) ;
} else {
F_27 ( & V_110 , V_1 , * -- V_57 ) ;
F_27 ( & V_109 , V_1 , * -- V_57 ) ;
}
V_56 -= 2 ;
if ( ( sizeof( V_108 . V_112 ) * 8 > V_53 * 4 + 7 ) && ( V_56 & 2 ) ) {
F_28 ( & V_108 , & V_110 , * -- V_57 ) ;
F_28 ( & V_108 , & V_109 , * -- V_57 ) ;
F_26 ( & V_108 ) ;
}
while ( V_57 > V_107 ) {
F_28 ( & V_108 , & V_110 , * -- V_57 ) ;
if ( sizeof( V_108 . V_112 ) * 8 < V_53 * 2 + 7 )
F_26 ( & V_108 ) ;
F_28 ( & V_108 , & V_109 , * -- V_57 ) ;
if ( sizeof( V_108 . V_112 ) * 8 > V_53 * 4 + 7 ) {
F_28 ( & V_108 , & V_110 , * -- V_57 ) ;
F_28 ( & V_108 , & V_109 , * -- V_57 ) ;
}
F_26 ( & V_108 ) ;
}
F_29 ( & V_108 , & V_110 ) ;
F_29 ( & V_108 , & V_109 ) ;
return F_30 ( & V_108 ) ;
}
T_1 F_31 ( void * V_104 , T_1 V_105 , const void * V_55 , T_1 V_56 , const T_2 * V_1 )
{
unsigned const V_106 = ( V_105 >= F_32 ( V_56 ) ) ;
if ( V_106 )
return F_24 ( V_104 , V_105 , V_55 , V_56 , V_1 , 1 ) ;
else
return F_24 ( V_104 , V_105 , V_55 , V_56 , V_1 , 0 ) ;
}
T_1 F_33 ( T_1 V_113 ) { return F_34 ( V_113 ) ; }
