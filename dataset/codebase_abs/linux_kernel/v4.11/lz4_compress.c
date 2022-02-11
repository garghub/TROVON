static T_1 T_2 F_1 (
T_2 V_1 ,
T_3 const V_2 )
{
if ( V_2 == V_3 )
return ( ( V_1 * 2654435761U )
>> ( ( V_4 * 8 ) - ( V_5 + 1 ) ) ) ;
else
return ( ( V_1 * 2654435761U )
>> ( ( V_4 * 8 ) - V_5 ) ) ;
}
static T_1 T_2 F_2 (
T_4 V_1 ,
T_3 const V_2 )
{
const T_2 V_6 = ( V_2 == V_3 )
? V_5 + 1
: V_5 ;
#if V_7
static const T_4 V_8 = 889523592379ULL ;
return ( T_2 ) ( ( ( V_1 << 24 ) * V_8 ) >> ( 64 - V_6 ) ) ;
#else
static const T_4 V_9 = 11400714785074694791ULL ;
return ( T_2 ) ( ( ( V_1 >> 24 ) * V_9 ) >> ( 64 - V_6 ) ) ;
#endif
}
static T_1 T_2 F_3 (
const void * V_10 ,
T_3 const V_2 )
{
#if V_11
if ( V_2 == V_12 )
return F_2 ( F_4 ( V_10 ) , V_2 ) ;
#endif
return F_1 ( F_5 ( V_10 ) , V_2 ) ;
}
static void F_6 (
const T_5 * V_10 ,
T_2 V_13 ,
void * V_14 ,
T_3 const V_2 ,
const T_5 * V_15 )
{
switch ( V_2 ) {
case V_16 :
{
const T_5 * * V_17 = ( const T_5 * * ) V_14 ;
V_17 [ V_13 ] = V_10 ;
return;
}
case V_12 :
{
T_2 * V_17 = ( T_2 * ) V_14 ;
V_17 [ V_13 ] = ( T_2 ) ( V_10 - V_15 ) ;
return;
}
case V_3 :
{
T_6 * V_17 = ( T_6 * ) V_14 ;
V_17 [ V_13 ] = ( T_6 ) ( V_10 - V_15 ) ;
return;
}
}
}
static T_1 void F_7 (
const T_5 * V_10 ,
void * V_14 ,
T_3 V_2 ,
const T_5 * V_15 )
{
T_2 const V_13 = F_3 ( V_10 , V_2 ) ;
F_6 ( V_10 , V_13 , V_14 , V_2 , V_15 ) ;
}
static const T_5 * F_8 (
T_2 V_13 ,
void * V_14 ,
T_3 V_2 ,
const T_5 * V_15 )
{
if ( V_2 == V_16 ) {
const T_5 * * V_17 = ( const T_5 * * ) V_14 ;
return V_17 [ V_13 ] ;
}
if ( V_2 == V_12 ) {
const T_2 * const V_17 = ( T_2 * ) V_14 ;
return V_17 [ V_13 ] + V_15 ;
}
{
const T_6 * const V_17 = ( T_6 * ) V_14 ;
return V_17 [ V_13 ] + V_15 ;
}
}
static T_1 const T_5 * F_9 (
const T_5 * V_10 ,
void * V_14 ,
T_3 V_2 ,
const T_5 * V_15 )
{
T_2 const V_13 = F_3 ( V_10 , V_2 ) ;
return F_8 ( V_13 , V_14 , V_2 , V_15 ) ;
}
static T_1 int F_10 (
T_7 * const V_18 ,
const char * const V_19 ,
char * const V_20 ,
const int V_21 ,
const int V_22 ,
const T_8 V_23 ,
const T_3 V_2 ,
const T_9 V_24 ,
const T_10 V_25 ,
const T_2 V_26 )
{
const T_5 * V_27 = ( const T_5 * ) V_19 ;
const T_5 * V_28 ;
const T_5 * V_29 ;
const T_5 * const V_30 = V_27 - V_18 -> V_31 ;
const T_5 * const V_32 = V_18 -> V_32 ;
const T_5 * const V_33 = V_32 + V_18 -> V_31 ;
const T_11 V_34 = V_33 - ( const T_5 * ) V_19 ;
const T_5 * V_35 = ( const T_5 * ) V_19 ;
const T_5 * const V_36 = V_27 + V_21 ;
const T_5 * const V_37 = V_36 - V_38 ;
const T_5 * const V_39 = V_36 - V_40 ;
T_5 * V_41 = ( T_5 * ) V_20 ;
T_5 * const V_42 = V_41 + V_22 ;
T_2 V_43 ;
T_11 V_44 = 0 ;
if ( ( T_2 ) V_21 > ( T_2 ) V_45 ) {
return 0 ;
}
switch ( V_24 ) {
case V_46 :
default:
V_28 = ( const T_5 * ) V_19 ;
V_29 = ( const T_5 * ) V_19 ;
break;
case V_47 :
V_28 = ( const T_5 * ) V_19 - V_18 -> V_48 ;
V_29 = ( const T_5 * ) V_19 - V_18 -> V_31 ;
break;
case V_49 :
V_28 = ( const T_5 * ) V_19 - V_18 -> V_48 ;
V_29 = ( const T_5 * ) V_19 ;
break;
}
if ( ( V_2 == V_3 )
&& ( V_21 >= V_50 ) ) {
return 0 ;
}
if ( V_21 < V_51 ) {
goto V_52;
}
F_7 ( V_27 , V_18 -> V_17 , V_2 , V_28 ) ;
V_27 ++ ;
V_43 = F_3 ( V_27 , V_2 ) ;
for ( ; ; ) {
const T_5 * V_53 ;
T_5 * V_54 ;
{
const T_5 * V_55 = V_27 ;
unsigned int V_56 = 1 ;
unsigned int V_57 = V_26 << V_58 ;
do {
T_2 const V_13 = V_43 ;
V_27 = V_55 ;
V_55 += V_56 ;
V_56 = ( V_57 ++ >> V_58 ) ;
if ( F_11 ( V_55 > V_37 ) )
goto V_52;
V_53 = F_8 ( V_13 ,
V_18 -> V_17 ,
V_2 , V_28 ) ;
if ( V_24 == V_49 ) {
if ( V_53 < ( const T_5 * ) V_19 ) {
V_44 = V_34 ;
V_29 = V_32 ;
} else {
V_44 = 0 ;
V_29 = ( const T_5 * ) V_19 ;
} }
V_43 = F_3 ( V_55 ,
V_2 ) ;
F_6 ( V_27 , V_13 , V_18 -> V_17 ,
V_2 , V_28 ) ;
} while ( ( ( V_25 == V_59 )
? ( V_53 < V_30 )
: 0 )
|| ( ( V_2 == V_3 )
? 0
: ( V_53 + V_60 < V_27 ) )
|| ( F_5 ( V_53 + V_44 )
!= F_5 ( V_27 ) ) );
}
while ( ( ( V_27 > V_35 ) & ( V_53 + V_44 > V_29 ) )
&& ( F_11 ( V_27 [ - 1 ] == V_53 [ V_44 - 1 ] ) ) ) {
V_27 -- ;
V_53 -- ;
}
{
unsigned const int V_61 = ( unsigned int ) ( V_27 - V_35 ) ;
V_54 = V_41 ++ ;
if ( ( V_23 ) &&
( F_11 ( V_41 + V_61 +
( 2 + 1 + V_40 ) +
( V_61 / 255 ) > V_42 ) ) )
return 0 ;
if ( V_61 >= V_62 ) {
int V_63 = ( int ) V_61 - V_62 ;
* V_54 = ( V_62 << V_64 ) ;
for (; V_63 >= 255 ; V_63 -= 255 )
* V_41 ++ = 255 ;
* V_41 ++ = ( T_5 ) V_63 ;
} else
* V_54 = ( T_5 ) ( V_61 << V_64 ) ;
F_12 ( V_41 , V_35 , V_41 + V_61 ) ;
V_41 += V_61 ;
}
V_65:
F_13 ( V_41 , ( T_6 ) ( V_27 - V_53 ) ) ;
V_41 += 2 ;
{
unsigned int V_66 ;
if ( ( V_24 == V_49 )
&& ( V_29 == V_32 ) ) {
const T_5 * V_67 ;
V_53 += V_44 ;
V_67 = V_27 + ( V_33 - V_53 ) ;
if ( V_67 > V_39 )
V_67 = V_39 ;
V_66 = F_14 ( V_27 + V_4 ,
V_53 + V_4 , V_67 ) ;
V_27 += V_4 + V_66 ;
if ( V_27 == V_67 ) {
unsigned const int V_68 = F_14 ( V_27 ,
( const T_5 * ) V_19 ,
V_39 ) ;
V_66 += V_68 ;
V_27 += V_68 ;
}
} else {
V_66 = F_14 ( V_27 + V_4 ,
V_53 + V_4 , V_39 ) ;
V_27 += V_4 + V_66 ;
}
if ( V_23 &&
( F_11 ( V_41 +
( 1 + V_40 ) +
( V_66 >> 8 ) > V_42 ) ) )
return 0 ;
if ( V_66 >= V_69 ) {
* V_54 += V_69 ;
V_66 -= V_69 ;
F_15 ( V_41 , 0xFFFFFFFF ) ;
while ( V_66 >= 4 * 255 ) {
V_41 += 4 ;
F_15 ( V_41 , 0xFFFFFFFF ) ;
V_66 -= 4 * 255 ;
}
V_41 += V_66 / 255 ;
* V_41 ++ = ( T_5 ) ( V_66 % 255 ) ;
} else
* V_54 += ( T_5 ) ( V_66 ) ;
}
V_35 = V_27 ;
if ( V_27 > V_37 )
break;
F_7 ( V_27 - 2 , V_18 -> V_17 , V_2 , V_28 ) ;
V_53 = F_9 ( V_27 , V_18 -> V_17 ,
V_2 , V_28 ) ;
if ( V_24 == V_49 ) {
if ( V_53 < ( const T_5 * ) V_19 ) {
V_44 = V_34 ;
V_29 = V_32 ;
} else {
V_44 = 0 ;
V_29 = ( const T_5 * ) V_19 ;
}
}
F_7 ( V_27 , V_18 -> V_17 , V_2 , V_28 ) ;
if ( ( ( V_25 == V_59 ) ? ( V_53 >= V_30 ) : 1 )
&& ( V_53 + V_60 >= V_27 )
&& ( F_5 ( V_53 + V_44 ) == F_5 ( V_27 ) ) ) {
V_54 = V_41 ++ ;
* V_54 = 0 ;
goto V_65;
}
V_43 = F_3 ( ++ V_27 , V_2 ) ;
}
V_52:
{
T_11 const V_70 = ( T_11 ) ( V_36 - V_35 ) ;
if ( ( V_23 ) &&
( ( V_41 - ( T_5 * ) V_20 ) + V_70 + 1 +
( ( V_70 + 255 - V_62 ) / 255 ) > ( T_2 ) V_22 ) )
return 0 ;
if ( V_70 >= V_62 ) {
T_11 V_71 = V_70 - V_62 ;
* V_41 ++ = V_62 << V_64 ;
for (; V_71 >= 255 ; V_71 -= 255 )
* V_41 ++ = 255 ;
* V_41 ++ = ( T_5 ) V_71 ;
} else {
* V_41 ++ = ( T_5 ) ( V_70 << V_64 ) ;
}
memcpy ( V_41 , V_35 , V_70 ) ;
V_41 += V_70 ;
}
return ( int ) ( ( ( char * ) V_41 ) - V_20 ) ;
}
static int F_16 (
void * V_72 ,
const char * V_19 ,
char * V_20 ,
int V_21 ,
int V_22 ,
int V_26 )
{
T_7 * V_73 = & ( ( V_74 * ) V_72 ) -> V_75 ;
#if V_11
const T_3 V_2 = V_12 ;
#else
const T_3 V_2 = V_16 ;
#endif
F_17 ( ( V_74 * ) V_72 ) ;
if ( V_26 < 1 )
V_26 = V_76 ;
if ( V_22 >= F_18 ( V_21 ) ) {
if ( V_21 < V_50 )
return F_10 ( V_73 , V_19 ,
V_20 , V_21 , 0 ,
V_77 , V_3 , V_46 ,
V_78 , V_26 ) ;
else
return F_10 ( V_73 , V_19 ,
V_20 , V_21 , 0 ,
V_77 , V_2 , V_46 ,
V_78 , V_26 ) ;
} else {
if ( V_21 < V_50 )
return F_10 ( V_73 , V_19 ,
V_20 , V_21 ,
V_22 , V_79 , V_3 , V_46 ,
V_78 , V_26 ) ;
else
return F_10 ( V_73 , V_19 ,
V_20 , V_21 ,
V_22 , V_79 , V_2 , V_46 ,
V_78 , V_26 ) ;
}
}
int F_19 ( const char * V_19 , char * V_20 , int V_21 ,
int V_22 , int V_26 , void * V_80 )
{
return F_16 ( V_80 , V_19 , V_20 , V_21 ,
V_22 , V_26 ) ;
}
int F_20 ( const char * V_19 , char * V_20 , int V_21 ,
int V_22 , void * V_80 )
{
return F_19 ( V_19 , V_20 , V_21 ,
V_22 , V_76 , V_80 ) ;
}
static int F_21 (
T_7 * const V_73 ,
const char * const V_81 ,
char * const V_82 ,
int * const V_83 ,
const int V_84 ,
const T_3 V_2 )
{
const T_5 * V_27 = ( const T_5 * ) V_81 ;
const T_5 * V_28 = ( const T_5 * ) V_81 ;
const T_5 * V_29 = ( const T_5 * ) V_81 ;
const T_5 * V_35 = V_27 ;
const T_5 * const V_36 = V_27 + * V_83 ;
const T_5 * const V_37 = V_36 - V_38 ;
const T_5 * const V_39 = V_36 - V_40 ;
T_5 * V_41 = ( T_5 * ) V_82 ;
T_5 * const V_85 = V_41 + V_84 ;
T_5 * const V_86 = V_41 + V_84 - 2
- 8 - 1 ;
T_5 * const V_87 = V_41 + V_84
- ( V_40 + 1 ) ;
T_5 * const V_88 = V_86 - 1 ;
T_2 V_43 ;
if ( V_84 < 1 )
return 0 ;
if ( ( T_2 ) * V_83 > ( T_2 ) V_45 )
return 0 ;
if ( ( V_2 == V_3 ) && ( * V_83 >= V_50 ) )
return 0 ;
if ( * V_83 < V_51 )
goto V_52;
* V_83 = 0 ;
F_7 ( V_27 , V_73 -> V_17 , V_2 , V_28 ) ;
V_27 ++ ; V_43 = F_3 ( V_27 , V_2 ) ;
for ( ; ; ) {
const T_5 * V_53 ;
T_5 * V_54 ;
{
const T_5 * V_55 = V_27 ;
unsigned int V_56 = 1 ;
unsigned int V_57 = 1 << V_58 ;
do {
T_2 V_13 = V_43 ;
V_27 = V_55 ;
V_55 += V_56 ;
V_56 = ( V_57 ++ >> V_58 ) ;
if ( F_11 ( V_55 > V_37 ) )
goto V_52;
V_53 = F_8 ( V_13 , V_73 -> V_17 ,
V_2 , V_28 ) ;
V_43 = F_3 ( V_55 ,
V_2 ) ;
F_6 ( V_27 , V_13 ,
V_73 -> V_17 , V_2 ,
V_28 ) ;
} while ( ( ( V_2 == V_3 )
? 0
: ( V_53 + V_60 < V_27 ) )
|| ( F_5 ( V_53 ) != F_5 ( V_27 ) ) );
}
while ( ( V_27 > V_35 )
&& ( V_53 > V_29 )
&& ( F_11 ( V_27 [ - 1 ] == V_53 [ - 1 ] ) ) ) {
V_27 -- ;
V_53 -- ;
}
{
unsigned int V_61 = ( unsigned int ) ( V_27 - V_35 ) ;
V_54 = V_41 ++ ;
if ( V_41 + ( ( V_61 + 240 ) / 255 )
+ V_61 > V_86 ) {
V_41 -- ;
goto V_52;
}
if ( V_61 >= V_62 ) {
unsigned int V_63 = V_61 - V_62 ;
* V_54 = ( V_62 << V_64 ) ;
for (; V_63 >= 255 ; V_63 -= 255 )
* V_41 ++ = 255 ;
* V_41 ++ = ( T_5 ) V_63 ;
} else
* V_54 = ( T_5 ) ( V_61 << V_64 ) ;
F_12 ( V_41 , V_35 , V_41 + V_61 ) ;
V_41 += V_61 ;
}
V_65:
F_13 ( V_41 , ( T_6 ) ( V_27 - V_53 ) ) ; V_41 += 2 ;
{
T_11 V_89 = F_14 ( V_27 + V_4 ,
V_53 + V_4 , V_39 ) ;
if ( V_41 + ( ( V_89 + 240 ) / 255 ) > V_87 ) {
V_89 = ( 15 - 1 ) + ( V_87 - V_41 ) * 255 ;
}
V_27 += V_4 + V_89 ;
if ( V_89 >= V_69 ) {
* V_54 += V_69 ;
V_89 -= V_69 ;
while ( V_89 >= 255 ) {
V_89 -= 255 ;
* V_41 ++ = 255 ;
}
* V_41 ++ = ( T_5 ) V_89 ;
} else
* V_54 += ( T_5 ) ( V_89 ) ;
}
V_35 = V_27 ;
if ( V_27 > V_37 )
break;
if ( V_41 > V_88 )
break;
F_7 ( V_27 - 2 , V_73 -> V_17 , V_2 , V_28 ) ;
V_53 = F_9 ( V_27 , V_73 -> V_17 , V_2 , V_28 ) ;
F_7 ( V_27 , V_73 -> V_17 , V_2 , V_28 ) ;
if ( ( V_53 + V_60 >= V_27 )
&& ( F_5 ( V_53 ) == F_5 ( V_27 ) ) ) {
V_54 = V_41 ++ ; * V_54 = 0 ;
goto V_65;
}
V_43 = F_3 ( ++ V_27 , V_2 ) ;
}
V_52:
{
T_11 V_90 = ( T_11 ) ( V_36 - V_35 ) ;
if ( V_41 + 1
+ ( ( V_90 + 240 ) / 255 )
+ V_90 > V_85 ) {
V_90 = ( V_85 - V_41 ) - 1 ;
V_90 -= ( V_90 + 240 ) / 255 ;
}
V_27 = V_35 + V_90 ;
if ( V_90 >= V_62 ) {
T_11 V_71 = V_90 - V_62 ;
* V_41 ++ = V_62 << V_64 ;
for (; V_71 >= 255 ; V_71 -= 255 )
* V_41 ++ = 255 ;
* V_41 ++ = ( T_5 ) V_71 ;
} else {
* V_41 ++ = ( T_5 ) ( V_90 << V_64 ) ;
}
memcpy ( V_41 , V_35 , V_90 ) ;
V_41 += V_90 ;
}
* V_83 = ( int ) ( ( ( const char * ) V_27 ) - V_81 ) ;
return ( int ) ( ( ( char * ) V_41 ) - V_82 ) ;
}
static int F_22 (
V_74 * V_72 ,
const char * V_81 ,
char * V_82 ,
int * V_83 ,
int V_84 )
{
#if V_11
const T_3 V_2 = V_12 ;
#else
const T_3 V_2 = V_16 ;
#endif
F_17 ( V_72 ) ;
if ( V_84 >= F_18 ( * V_83 ) ) {
return F_16 (
V_72 , V_81 , V_82 , * V_83 ,
V_84 , 1 ) ;
} else {
if ( * V_83 < V_50 )
return F_21 (
& V_72 -> V_75 ,
V_81 , V_82 , V_83 ,
V_84 , V_3 ) ;
else
return F_21 (
& V_72 -> V_75 ,
V_81 , V_82 , V_83 ,
V_84 , V_2 ) ;
}
}
int F_23 (
const char * V_81 ,
char * V_82 ,
int * V_83 ,
int V_84 ,
void * V_80 )
{
return F_22 ( V_80 , V_81 , V_82 , V_83 ,
V_84 ) ;
}
void F_17 ( V_74 * V_91 )
{
memset ( V_91 , 0 , sizeof( V_74 ) ) ;
}
int F_24 ( V_74 * V_92 ,
const char * V_32 , int V_31 )
{
T_7 * V_24 = & V_92 -> V_75 ;
const T_5 * V_10 = ( const T_5 * ) V_32 ;
const T_5 * const V_33 = V_10 + V_31 ;
const T_5 * V_28 ;
if ( ( V_24 -> V_93 )
|| ( V_24 -> V_48 > 1 * V_94 ) ) {
F_17 ( V_92 ) ;
}
if ( V_31 < ( int ) V_95 ) {
V_24 -> V_32 = NULL ;
V_24 -> V_31 = 0 ;
return 0 ;
}
if ( ( V_33 - V_10 ) > 64 * V_96 )
V_10 = V_33 - 64 * V_96 ;
V_24 -> V_48 += 64 * V_96 ;
V_28 = V_10 - V_24 -> V_48 ;
V_24 -> V_32 = V_10 ;
V_24 -> V_31 = ( T_2 ) ( V_33 - V_10 ) ;
V_24 -> V_48 += V_24 -> V_31 ;
while ( V_10 <= V_33 - V_95 ) {
F_7 ( V_10 , V_24 -> V_17 , V_12 , V_28 ) ;
V_10 += 3 ;
}
return V_24 -> V_31 ;
}
static void F_25 ( T_7 * V_92 ,
const T_5 * V_81 )
{
if ( ( V_92 -> V_48 > 0x80000000 ) ||
( ( V_97 ) V_92 -> V_48 > ( V_97 ) V_81 ) ) {
T_2 const V_98 = V_92 -> V_48 - 64 * V_96 ;
const T_5 * V_33 = V_92 -> V_32 + V_92 -> V_31 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ ) {
if ( V_92 -> V_17 [ V_99 ] < V_98 )
V_92 -> V_17 [ V_99 ] = 0 ;
else
V_92 -> V_17 [ V_99 ] -= V_98 ;
}
V_92 -> V_48 = 64 * V_96 ;
if ( V_92 -> V_31 > 64 * V_96 )
V_92 -> V_31 = 64 * V_96 ;
V_92 -> V_32 = V_33 - V_92 -> V_31 ;
}
}
int F_26 ( V_74 * V_92 , char * V_101 , int V_31 )
{
T_7 * const V_24 = & V_92 -> V_75 ;
const T_5 * const V_102 = V_24 -> V_32 + V_24 -> V_31 ;
if ( ( T_2 ) V_31 > 64 * V_96 ) {
V_31 = 64 * V_96 ;
}
if ( ( T_2 ) V_31 > V_24 -> V_31 )
V_31 = V_24 -> V_31 ;
memmove ( V_101 , V_102 - V_31 , V_31 ) ;
V_24 -> V_32 = ( const T_5 * ) V_101 ;
V_24 -> V_31 = ( T_2 ) V_31 ;
return V_31 ;
}
int F_27 ( V_74 * V_91 , const char * V_19 ,
char * V_20 , int V_21 , int V_22 , int V_26 )
{
T_7 * V_103 = & V_91 -> V_75 ;
const T_5 * const V_33 = V_103 -> V_32
+ V_103 -> V_31 ;
const T_5 * V_104 = ( const T_5 * ) V_19 ;
if ( V_103 -> V_93 ) {
return 0 ;
}
if ( ( V_103 -> V_31 > 0 ) && ( V_104 > V_33 ) )
V_104 = V_33 ;
F_25 ( V_103 , V_104 ) ;
if ( V_26 < 1 )
V_26 = V_76 ;
{
const T_5 * V_105 = ( const T_5 * ) V_19 + V_21 ;
if ( ( V_105 > V_103 -> V_32 )
&& ( V_105 < V_33 ) ) {
V_103 -> V_31 = ( T_2 ) ( V_33 - V_105 ) ;
if ( V_103 -> V_31 > 64 * V_96 )
V_103 -> V_31 = 64 * V_96 ;
if ( V_103 -> V_31 < 4 )
V_103 -> V_31 = 0 ;
V_103 -> V_32 = V_33 - V_103 -> V_31 ;
}
}
if ( V_33 == ( const T_5 * ) V_19 ) {
int V_106 ;
if ( ( V_103 -> V_31 < 64 * V_96 ) &&
( V_103 -> V_31 < V_103 -> V_48 ) ) {
V_106 = F_10 (
V_103 , V_19 , V_20 , V_21 ,
V_22 , V_79 , V_12 ,
V_47 , V_59 , V_26 ) ;
} else {
V_106 = F_10 (
V_103 , V_19 , V_20 , V_21 ,
V_22 , V_79 , V_12 ,
V_47 , V_78 , V_26 ) ;
}
V_103 -> V_31 += ( T_2 ) V_21 ;
V_103 -> V_48 += ( T_2 ) V_21 ;
return V_106 ;
}
{
int V_106 ;
if ( ( V_103 -> V_31 < 64 * V_96 ) &&
( V_103 -> V_31 < V_103 -> V_48 ) ) {
V_106 = F_10 (
V_103 , V_19 , V_20 , V_21 ,
V_22 , V_79 , V_12 ,
V_49 , V_59 , V_26 ) ;
} else {
V_106 = F_10 (
V_103 , V_19 , V_20 , V_21 ,
V_22 , V_79 , V_12 ,
V_49 , V_78 , V_26 ) ;
}
V_103 -> V_32 = ( const T_5 * ) V_19 ;
V_103 -> V_31 = ( T_2 ) V_21 ;
V_103 -> V_48 += ( T_2 ) V_21 ;
return V_106 ;
}
}
