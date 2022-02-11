unsigned F_1 ( unsigned V_1 , T_1 V_2 , unsigned V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , 1 ) ;
}
T_1 F_3 ( void * V_4 , T_1 V_5 , const void * V_6 , T_1 V_7 , void * V_8 , T_1 V_9 )
{
T_2 * const V_10 = ( T_2 * ) V_4 ;
T_2 * V_11 = V_10 ;
T_2 * const V_12 = V_10 + V_5 ;
T_3 V_3 = V_13 ;
T_3 V_14 = V_15 ;
T_4 * V_16 ;
T_3 * V_17 ;
T_5 * V_18 ;
T_1 V_19 = 0 ;
F_4 ( sizeof( T_4 ) == sizeof( T_3 ) ) ;
V_16 = ( T_4 * ) ( ( T_3 * ) V_8 + V_19 ) ;
V_19 += F_5 ( V_15 , V_13 ) ;
V_17 = ( T_3 * ) V_8 + V_19 ;
V_19 += V_13 + 1 ;
V_18 = ( T_5 * ) ( ( T_3 * ) V_8 + V_19 ) ;
V_19 += F_6 ( sizeof( T_5 ) * ( V_13 + 1 ) , sizeof( T_3 ) ) >> 2 ;
if ( ( V_19 << 2 ) > V_9 )
return ERROR ( V_20 ) ;
V_8 = ( T_3 * ) V_8 + V_19 ;
V_9 -= ( V_19 << 2 ) ;
if ( V_7 <= 1 )
return 0 ;
{
F_7 ( V_21 , F_8 ( V_17 , & V_3 , V_6 , V_7 ) ) ;
if ( V_21 == V_7 )
return 1 ;
if ( V_21 == 1 )
return 0 ;
}
V_14 = F_9 ( V_14 , V_7 , V_3 ) ;
F_10 ( F_11 ( V_18 , V_14 , V_17 , V_7 , V_3 ) ) ;
{
F_7 ( V_22 , F_12 ( V_11 , V_12 - V_11 , V_18 , V_3 , V_14 ) ) ;
V_11 += V_22 ;
}
F_10 ( F_13 ( V_16 , V_18 , V_3 , V_14 , V_8 , V_9 ) ) ;
{
F_7 ( V_23 , F_14 ( V_11 , V_12 - V_11 , V_6 , V_7 , V_16 ) ) ;
if ( V_23 == 0 )
return 0 ;
V_11 += V_23 ;
}
return V_11 - V_10 ;
}
T_1 F_15 ( void * V_4 , T_1 V_24 , const T_6 * V_16 , T_3 V_3 , T_3 V_25 , void * V_8 , T_1 V_9 )
{
T_2 * V_11 = ( T_2 * ) V_4 ;
T_3 V_26 ;
T_2 * V_27 ;
T_2 * V_28 ;
T_1 V_19 = 0 ;
V_27 = ( T_2 * ) ( ( T_3 * ) V_8 + V_19 ) ;
V_19 += F_6 ( V_13 + 1 , sizeof( T_3 ) ) >> 2 ;
V_28 = ( T_2 * ) ( ( T_3 * ) V_8 + V_19 ) ;
V_19 += F_6 ( V_29 , sizeof( T_3 ) ) >> 2 ;
if ( ( V_19 << 2 ) > V_9 )
return ERROR ( V_20 ) ;
V_8 = ( T_3 * ) V_8 + V_19 ;
V_9 -= ( V_19 << 2 ) ;
if ( V_3 > V_29 )
return ERROR ( V_30 ) ;
V_27 [ 0 ] = 0 ;
for ( V_26 = 1 ; V_26 < V_25 + 1 ; V_26 ++ )
V_27 [ V_26 ] = ( T_2 ) ( V_25 + 1 - V_26 ) ;
for ( V_26 = 0 ; V_26 < V_3 ; V_26 ++ )
V_28 [ V_26 ] = V_27 [ V_16 [ V_26 ] . V_31 ] ;
{
F_7 ( V_22 , F_3 ( V_11 + 1 , V_24 - 1 , V_28 , V_3 , V_8 , V_9 ) ) ;
if ( ( V_22 > 1 ) & ( V_22 < V_3 / 2 ) ) {
V_11 [ 0 ] = ( T_2 ) V_22 ;
return V_22 + 1 ;
}
}
if ( V_3 > ( 256 - 128 ) )
return ERROR ( V_32 ) ;
if ( ( ( V_3 + 1 ) / 2 ) + 1 > V_24 )
return ERROR ( V_33 ) ;
V_11 [ 0 ] = ( T_2 ) ( 128 + ( V_3 - 1 ) ) ;
V_28 [ V_3 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_3 ; V_26 += 2 )
V_11 [ ( V_26 / 2 ) + 1 ] = ( T_2 ) ( ( V_28 [ V_26 ] << 4 ) + V_28 [ V_26 + 1 ] ) ;
return ( ( V_3 + 1 ) / 2 ) + 1 ;
}
T_1 F_16 ( T_6 * V_16 , T_3 V_3 , const void * V_34 , T_1 V_2 , void * V_8 , T_1 V_9 )
{
T_3 * V_35 ;
T_2 * V_28 ;
T_3 V_14 = 0 ;
T_3 V_36 = 0 ;
T_1 V_37 ;
T_1 V_19 = 0 ;
V_35 = ( T_3 * ) V_8 + V_19 ;
V_19 += V_38 + 1 ;
V_28 = ( T_2 * ) ( ( T_3 * ) V_8 + V_19 ) ;
V_19 += F_6 ( V_29 + 1 , sizeof( T_3 ) ) >> 2 ;
if ( ( V_19 << 2 ) > V_9 )
return ERROR ( V_20 ) ;
V_8 = ( T_3 * ) V_8 + V_19 ;
V_9 -= ( V_19 << 2 ) ;
V_37 = F_17 ( V_28 , V_29 + 1 , V_35 , & V_36 , & V_14 , V_34 , V_2 , V_8 , V_9 ) ;
if ( F_18 ( V_37 ) )
return V_37 ;
if ( V_14 > V_13 )
return ERROR ( V_20 ) ;
if ( V_36 > V_3 + 1 )
return ERROR ( V_39 ) ;
{
T_3 V_26 , V_40 = 0 ;
for ( V_26 = 1 ; V_26 <= V_14 ; V_26 ++ ) {
T_3 V_41 = V_40 ;
V_40 += ( V_35 [ V_26 ] << ( V_26 - 1 ) ) ;
V_35 [ V_26 ] = V_41 ;
}
}
{
T_3 V_26 ;
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ ) {
const T_3 V_42 = V_28 [ V_26 ] ;
V_16 [ V_26 ] . V_31 = ( T_2 ) ( V_14 + 1 - V_42 ) ;
}
}
{
T_7 V_43 [ V_13 + 2 ] = { 0 } ;
T_7 V_44 [ V_13 + 2 ] = { 0 } ;
{
T_3 V_26 ;
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ )
V_43 [ V_16 [ V_26 ] . V_31 ] ++ ;
}
V_44 [ V_14 + 1 ] = 0 ;
{
T_7 V_45 = 0 ;
T_3 V_26 ;
for ( V_26 = V_14 ; V_26 > 0 ; V_26 -- ) {
V_44 [ V_26 ] = V_45 ;
V_45 += V_43 [ V_26 ] ;
V_45 >>= 1 ;
}
}
{
T_3 V_26 ;
for ( V_26 = 0 ; V_26 <= V_3 ; V_26 ++ )
V_16 [ V_26 ] . V_46 = V_44 [ V_16 [ V_26 ] . V_31 ] ++ ;
}
}
return V_37 ;
}
static T_3 F_19 ( T_8 * V_47 , T_3 V_48 , T_3 V_49 )
{
const T_3 V_50 = V_47 [ V_48 ] . V_31 ;
if ( V_50 <= V_49 )
return V_50 ;
{
int V_51 = 0 ;
const T_3 V_52 = 1 << ( V_50 - V_49 ) ;
T_3 V_26 = V_48 ;
while ( V_47 [ V_26 ] . V_31 > V_49 ) {
V_51 += V_52 - ( 1 << ( V_50 - V_47 [ V_26 ] . V_31 ) ) ;
V_47 [ V_26 ] . V_31 = ( T_2 ) V_49 ;
V_26 -- ;
}
while ( V_47 [ V_26 ] . V_31 == V_49 )
V_26 -- ;
V_51 >>= ( V_50 - V_49 ) ;
{
T_3 const V_53 = 0xF0F0F0F0 ;
T_3 V_54 [ V_13 + 2 ] ;
int V_55 ;
memset ( V_54 , 0xF0 , sizeof( V_54 ) ) ;
{
T_3 V_56 = V_49 ;
for ( V_55 = V_26 ; V_55 >= 0 ; V_55 -- ) {
if ( V_47 [ V_55 ] . V_31 >= V_56 )
continue;
V_56 = V_47 [ V_55 ] . V_31 ;
V_54 [ V_49 - V_56 ] = V_55 ;
}
}
while ( V_51 > 0 ) {
T_3 V_57 = F_20 ( V_51 ) + 1 ;
for (; V_57 > 1 ; V_57 -- ) {
T_3 V_58 = V_54 [ V_57 ] ;
T_3 V_59 = V_54 [ V_57 - 1 ] ;
if ( V_58 == V_53 )
continue;
if ( V_59 == V_53 )
break;
{
T_3 const V_60 = V_47 [ V_58 ] . V_17 ;
T_3 const V_61 = 2 * V_47 [ V_59 ] . V_17 ;
if ( V_60 <= V_61 )
break;
}
}
while ( ( V_57 <= V_13 ) && ( V_54 [ V_57 ] == V_53 ) )
V_57 ++ ;
V_51 -= 1 << ( V_57 - 1 ) ;
if ( V_54 [ V_57 - 1 ] == V_53 )
V_54 [ V_57 - 1 ] = V_54 [ V_57 ] ;
V_47 [ V_54 [ V_57 ] ] . V_31 ++ ;
if ( V_54 [ V_57 ] == 0 )
V_54 [ V_57 ] = V_53 ;
else {
V_54 [ V_57 ] -- ;
if ( V_47 [ V_54 [ V_57 ] ] . V_31 != V_49 - V_57 )
V_54 [ V_57 ] = V_53 ;
}
}
while ( V_51 < 0 ) {
if ( V_54 [ 1 ] == V_53 ) {
while ( V_47 [ V_26 ] . V_31 == V_49 )
V_26 -- ;
V_47 [ V_26 + 1 ] . V_31 -- ;
V_54 [ 1 ] = V_26 + 1 ;
V_51 ++ ;
continue;
}
V_47 [ V_54 [ 1 ] + 1 ] . V_31 -- ;
V_54 [ 1 ] ++ ;
V_51 ++ ;
}
}
}
return V_49 ;
}
static void F_21 ( T_8 * V_47 , const T_3 * V_17 , T_3 V_3 )
{
T_9 V_62 [ 32 ] ;
T_3 V_26 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
for ( V_26 = 0 ; V_26 <= V_3 ; V_26 ++ ) {
T_3 V_63 = F_20 ( V_17 [ V_26 ] + 1 ) ;
V_62 [ V_63 ] . V_64 ++ ;
}
for ( V_26 = 30 ; V_26 > 0 ; V_26 -- )
V_62 [ V_26 - 1 ] . V_64 += V_62 [ V_26 ] . V_64 ;
for ( V_26 = 0 ; V_26 < 32 ; V_26 ++ )
V_62 [ V_26 ] . V_41 = V_62 [ V_26 ] . V_64 ;
for ( V_26 = 0 ; V_26 <= V_3 ; V_26 ++ ) {
T_3 const V_65 = V_17 [ V_26 ] ;
T_3 const V_63 = F_20 ( V_65 + 1 ) + 1 ;
T_3 V_55 = V_62 [ V_63 ] . V_41 ++ ;
while ( ( V_55 > V_62 [ V_63 ] . V_64 ) && ( V_65 > V_47 [ V_55 - 1 ] . V_17 ) )
V_47 [ V_55 ] = V_47 [ V_55 - 1 ] , V_55 -- ;
V_47 [ V_55 ] . V_17 = V_65 ;
V_47 [ V_55 ] . V_66 = ( T_2 ) V_26 ;
}
}
T_1 F_22 ( T_6 * V_67 , const T_3 * V_17 , T_3 V_3 , T_3 V_49 , void * V_68 , T_1 V_69 )
{
T_8 * const V_70 = ( T_8 * ) V_68 ;
T_8 * const V_47 = V_70 + 1 ;
T_3 V_26 , V_71 ;
int V_72 , V_73 ;
T_7 V_74 = V_75 ;
T_3 V_76 ;
if ( V_69 < sizeof( V_77 ) )
return ERROR ( V_32 ) ;
if ( V_49 == 0 )
V_49 = V_78 ;
if ( V_3 > V_29 )
return ERROR ( V_32 ) ;
memset ( V_70 , 0 , sizeof( V_77 ) ) ;
F_21 ( V_47 , V_17 , V_3 ) ;
V_71 = V_3 ;
while ( V_47 [ V_71 ] . V_17 == 0 )
V_71 -- ;
V_72 = V_71 ;
V_76 = V_74 + V_72 - 1 ;
V_73 = V_74 ;
V_47 [ V_74 ] . V_17 = V_47 [ V_72 ] . V_17 + V_47 [ V_72 - 1 ] . V_17 ;
V_47 [ V_72 ] . V_79 = V_47 [ V_72 - 1 ] . V_79 = V_74 ;
V_74 ++ ;
V_72 -= 2 ;
for ( V_26 = V_74 ; V_26 <= V_76 ; V_26 ++ )
V_47 [ V_26 ] . V_17 = ( T_3 ) ( 1U << 30 ) ;
V_70 [ 0 ] . V_17 = ( T_3 ) ( 1U << 31 ) ;
while ( V_74 <= V_76 ) {
T_3 V_80 = ( V_47 [ V_72 ] . V_17 < V_47 [ V_73 ] . V_17 ) ? V_72 -- : V_73 ++ ;
T_3 V_81 = ( V_47 [ V_72 ] . V_17 < V_47 [ V_73 ] . V_17 ) ? V_72 -- : V_73 ++ ;
V_47 [ V_74 ] . V_17 = V_47 [ V_80 ] . V_17 + V_47 [ V_81 ] . V_17 ;
V_47 [ V_80 ] . V_79 = V_47 [ V_81 ] . V_79 = V_74 ;
V_74 ++ ;
}
V_47 [ V_76 ] . V_31 = 0 ;
for ( V_26 = V_76 - 1 ; V_26 >= V_75 ; V_26 -- )
V_47 [ V_26 ] . V_31 = V_47 [ V_47 [ V_26 ] . V_79 ] . V_31 + 1 ;
for ( V_26 = 0 ; V_26 <= V_71 ; V_26 ++ )
V_47 [ V_26 ] . V_31 = V_47 [ V_47 [ V_26 ] . V_79 ] . V_31 + 1 ;
V_49 = F_19 ( V_47 , V_71 , V_49 ) ;
{
T_7 V_43 [ V_13 + 1 ] = { 0 } ;
T_7 V_44 [ V_13 + 1 ] = { 0 } ;
if ( V_49 > V_13 )
return ERROR ( V_32 ) ;
for ( V_26 = 0 ; V_26 <= V_71 ; V_26 ++ )
V_43 [ V_47 [ V_26 ] . V_31 ] ++ ;
{
T_7 V_45 = 0 ;
for ( V_26 = V_49 ; V_26 > 0 ; V_26 -- ) {
V_44 [ V_26 ] = V_45 ;
V_45 += V_43 [ V_26 ] ;
V_45 >>= 1 ;
}
}
for ( V_26 = 0 ; V_26 <= V_3 ; V_26 ++ )
V_67 [ V_47 [ V_26 ] . V_66 ] . V_31 = V_47 [ V_26 ] . V_31 ;
for ( V_26 = 0 ; V_26 <= V_3 ; V_26 ++ )
V_67 [ V_26 ] . V_46 = V_44 [ V_67 [ V_26 ] . V_31 ] ++ ;
}
return V_49 ;
}
static T_1 F_23 ( T_6 * V_16 , const unsigned * V_17 , unsigned V_3 )
{
T_1 V_31 = 0 ;
int V_82 ;
for ( V_82 = 0 ; V_82 <= ( int ) V_3 ; ++ V_82 ) {
V_31 += V_16 [ V_82 ] . V_31 * V_17 [ V_82 ] ;
}
return V_31 >> 3 ;
}
static int F_24 ( const T_6 * V_16 , const unsigned * V_17 , unsigned V_3 )
{
int V_83 = 0 ;
int V_82 ;
for ( V_82 = 0 ; V_82 <= ( int ) V_3 ; ++ V_82 ) {
V_83 |= ( V_17 [ V_82 ] != 0 ) & ( V_16 [ V_82 ] . V_31 == 0 ) ;
}
return ! V_83 ;
}
static void F_25 ( T_10 * V_84 , T_3 V_85 , const T_6 * V_16 )
{
F_26 ( V_84 , V_16 [ V_85 ] . V_46 , V_16 [ V_85 ] . V_31 ) ;
}
T_1 F_27 ( T_1 V_86 ) { return F_28 ( V_86 ) ; }
T_1 F_29 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , const T_6 * V_16 )
{
const T_2 * V_87 = ( const T_2 * ) V_34 ;
T_2 * const V_10 = ( T_2 * ) V_4 ;
T_2 * const V_12 = V_10 + V_5 ;
T_2 * V_11 = V_10 ;
T_1 V_26 ;
T_10 V_88 ;
if ( V_5 < 8 )
return 0 ;
{
T_1 const V_89 = F_30 ( & V_88 , V_11 , V_12 - V_11 ) ;
if ( F_31 ( V_89 ) )
return 0 ;
}
V_26 = V_2 & ~ 3 ;
switch ( V_2 & 3 ) {
case 3 : F_25 ( & V_88 , V_87 [ V_26 + 2 ] , V_16 ) ; F_32 ( & V_88 ) ;
case 2 : F_25 ( & V_88 , V_87 [ V_26 + 1 ] , V_16 ) ; F_33 ( & V_88 ) ;
case 1 : F_25 ( & V_88 , V_87 [ V_26 + 0 ] , V_16 ) ; F_34 ( & V_88 ) ;
case 0 :
default: ;
}
for (; V_26 > 0 ; V_26 -= 4 ) {
F_25 ( & V_88 , V_87 [ V_26 - 1 ] , V_16 ) ;
F_33 ( & V_88 ) ;
F_25 ( & V_88 , V_87 [ V_26 - 2 ] , V_16 ) ;
F_32 ( & V_88 ) ;
F_25 ( & V_88 , V_87 [ V_26 - 3 ] , V_16 ) ;
F_33 ( & V_88 ) ;
F_25 ( & V_88 , V_87 [ V_26 - 4 ] , V_16 ) ;
F_34 ( & V_88 ) ;
}
return F_35 ( & V_88 ) ;
}
T_1 F_36 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , const T_6 * V_16 )
{
T_1 const V_90 = ( V_2 + 3 ) / 4 ;
const T_2 * V_87 = ( const T_2 * ) V_34 ;
const T_2 * const V_91 = V_87 + V_2 ;
T_2 * const V_10 = ( T_2 * ) V_4 ;
T_2 * const V_12 = V_10 + V_5 ;
T_2 * V_11 = V_10 ;
if ( V_5 < 6 + 1 + 1 + 1 + 8 )
return 0 ;
if ( V_2 < 12 )
return 0 ;
V_11 += 6 ;
{
F_7 ( V_23 , F_29 ( V_11 , V_12 - V_11 , V_87 , V_90 , V_16 ) ) ;
if ( V_23 == 0 )
return 0 ;
F_37 ( V_10 , ( T_7 ) V_23 ) ;
V_11 += V_23 ;
}
V_87 += V_90 ;
{
F_7 ( V_23 , F_29 ( V_11 , V_12 - V_11 , V_87 , V_90 , V_16 ) ) ;
if ( V_23 == 0 )
return 0 ;
F_37 ( V_10 + 2 , ( T_7 ) V_23 ) ;
V_11 += V_23 ;
}
V_87 += V_90 ;
{
F_7 ( V_23 , F_29 ( V_11 , V_12 - V_11 , V_87 , V_90 , V_16 ) ) ;
if ( V_23 == 0 )
return 0 ;
F_37 ( V_10 + 4 , ( T_7 ) V_23 ) ;
V_11 += V_23 ;
}
V_87 += V_90 ;
{
F_7 ( V_23 , F_29 ( V_11 , V_12 - V_11 , V_87 , V_91 - V_87 , V_16 ) ) ;
if ( V_23 == 0 )
return 0 ;
V_11 += V_23 ;
}
return V_11 - V_10 ;
}
static T_1 F_38 ( T_2 * const V_10 , T_2 * V_11 , T_2 * const V_12 , const void * V_34 , T_1 V_2 , unsigned V_92 ,
const T_6 * V_16 )
{
T_1 const V_23 =
V_92 ? F_29 ( V_11 , V_12 - V_11 , V_34 , V_2 , V_16 ) : F_36 ( V_11 , V_12 - V_11 , V_34 , V_2 , V_16 ) ;
if ( F_31 ( V_23 ) ) {
return V_23 ;
}
if ( V_23 == 0 ) {
return 0 ;
}
V_11 += V_23 ;
if ( ( T_1 ) ( V_11 - V_10 ) >= V_2 - 1 ) {
return 0 ;
}
return V_11 - V_10 ;
}
static T_1 F_39 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , unsigned V_3 , unsigned V_25 ,
unsigned V_92 , void * V_68 , T_1 V_69 , T_6 * V_93 , T_11 * V_94 , int V_95 )
{
T_2 * const V_10 = ( T_2 * ) V_4 ;
T_2 * const V_12 = V_10 + V_5 ;
T_2 * V_11 = V_10 ;
T_3 * V_17 ;
T_1 const V_96 = sizeof( T_3 ) * ( V_29 + 1 ) ;
T_6 * V_16 ;
T_1 const V_97 = sizeof( T_6 ) * ( V_29 + 1 ) ;
if ( V_69 < sizeof( V_77 ) + V_96 + V_97 )
return ERROR ( V_32 ) ;
if ( ! V_2 )
return 0 ;
if ( ! V_5 )
return 0 ;
if ( V_2 > V_98 )
return ERROR ( V_99 ) ;
if ( V_25 > V_13 )
return ERROR ( V_20 ) ;
if ( ! V_3 )
V_3 = V_29 ;
if ( ! V_25 )
V_25 = V_78 ;
V_17 = ( T_3 * ) V_68 ;
V_68 = ( T_2 * ) V_68 + V_96 ;
V_69 -= V_96 ;
V_16 = ( T_6 * ) V_68 ;
V_68 = ( T_2 * ) V_68 + V_97 ;
V_69 -= V_97 ;
if ( V_95 && V_94 && * V_94 == V_100 ) {
return F_38 ( V_10 , V_11 , V_12 , V_34 , V_2 , V_92 , V_93 ) ;
}
{
F_7 ( V_101 , F_40 ( V_17 , & V_3 , ( const T_2 * ) V_34 , V_2 , ( T_3 * ) V_68 ) ) ;
if ( V_101 == V_2 ) {
* V_10 = ( ( const T_2 * ) V_34 ) [ 0 ] ;
return 1 ;
}
if ( V_101 <= ( V_2 >> 7 ) + 1 )
return 0 ;
}
if ( V_94 && * V_94 == V_102 && ! F_24 ( V_93 , V_17 , V_3 ) ) {
* V_94 = V_103 ;
}
if ( V_95 && V_94 && * V_94 != V_103 ) {
return F_38 ( V_10 , V_11 , V_12 , V_34 , V_2 , V_92 , V_93 ) ;
}
V_25 = F_1 ( V_25 , V_2 , V_3 ) ;
{
F_7 ( V_104 , F_22 ( V_16 , V_17 , V_3 , V_25 , V_68 , V_69 ) ) ;
V_25 = ( T_3 ) V_104 ;
memset ( V_16 + V_3 + 1 , 0 , V_97 - ( V_3 + 1 ) * sizeof( T_6 ) ) ;
}
{
F_7 ( V_22 , F_15 ( V_11 , V_5 , V_16 , V_3 , V_25 , V_68 , V_69 ) ) ;
if ( V_94 && * V_94 != V_103 ) {
T_1 const V_105 = F_23 ( V_93 , V_17 , V_3 ) ;
T_1 const V_106 = F_23 ( V_16 , V_17 , V_3 ) ;
if ( V_105 <= V_22 + V_106 || V_22 + 12 >= V_2 ) {
return F_38 ( V_10 , V_11 , V_12 , V_34 , V_2 , V_92 , V_93 ) ;
}
}
if ( V_22 + 12ul >= V_2 ) {
return 0 ;
}
V_11 += V_22 ;
if ( V_94 ) {
* V_94 = V_103 ;
}
if ( V_93 ) {
memcpy ( V_93 , V_16 , V_97 ) ;
}
}
return F_38 ( V_10 , V_11 , V_12 , V_34 , V_2 , V_92 , V_16 ) ;
}
T_1 F_41 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , unsigned V_3 , unsigned V_25 , void * V_68 ,
T_1 V_69 )
{
return F_39 ( V_4 , V_5 , V_34 , V_2 , V_3 , V_25 , 1 , V_68 , V_69 , NULL , NULL , 0 ) ;
}
T_1 F_42 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , unsigned V_3 , unsigned V_25 , void * V_68 ,
T_1 V_69 , T_6 * V_107 , T_11 * V_94 , int V_95 )
{
return F_39 ( V_4 , V_5 , V_34 , V_2 , V_3 , V_25 , 1 , V_68 , V_69 , V_107 , V_94 ,
V_95 ) ;
}
T_1 F_43 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , unsigned V_3 , unsigned V_25 , void * V_68 ,
T_1 V_69 )
{
return F_39 ( V_4 , V_5 , V_34 , V_2 , V_3 , V_25 , 0 , V_68 , V_69 , NULL , NULL , 0 ) ;
}
T_1 F_44 ( void * V_4 , T_1 V_5 , const void * V_34 , T_1 V_2 , unsigned V_3 , unsigned V_25 , void * V_68 ,
T_1 V_69 , T_6 * V_107 , T_11 * V_94 , int V_95 )
{
return F_39 ( V_4 , V_5 , V_34 , V_2 , V_3 , V_25 , 0 , V_68 , V_69 , V_107 , V_94 ,
V_95 ) ;
}
