T_1 *
F_1 ( const struct V_1 * V_2 )
{
T_1 * V_3 ;
T_2 V_4 = V_2 -> V_5 ? V_2 -> V_5 : sizeof( * V_3 ) ;
F_2 ( V_4 >= sizeof( * V_3 ) ) ;
V_3 = ( T_1 * ) F_3 ( V_4 ) ;
V_3 -> V_6 = NULL ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = FALSE ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = - 1 ;
V_3 -> V_13 = NULL ;
return V_3 ;
}
static void
F_4 ( T_1 * V_3 )
{
T_2 V_4 ;
F_5 ( V_3 ) ;
if ( V_3 -> V_2 -> V_14 )
V_3 -> V_2 -> V_14 ( V_3 ) ;
V_4 = ( V_3 -> V_2 -> V_5 ) ? V_3 -> V_2 -> V_5 : sizeof( * V_3 ) ;
F_6 ( V_4 , V_3 ) ;
}
void
V_14 ( T_1 * V_3 )
{
F_7 ( V_3 ) ;
}
void
F_7 ( T_1 * V_3 )
{
T_1 * V_15 ;
F_5 ( V_3 ) ;
while ( V_3 ) {
V_15 = V_3 -> V_6 ;
F_4 ( V_3 ) ;
V_3 = V_15 ;
}
}
T_1 *
F_8 ( T_1 * V_16 , T_1 * V_17 )
{
T_1 * V_3 = F_9 ( V_17 ) ;
F_10 ( V_16 , V_3 ) ;
return V_3 ;
}
void
F_10 ( T_1 * V_16 , T_1 * V_18 )
{
T_1 * V_19 = V_18 ;
F_5 ( V_16 ) ;
F_5 ( V_18 ) ;
while ( V_18 ) {
V_19 = V_18 ;
V_18 = V_18 -> V_6 ;
V_19 -> V_6 = V_16 -> V_6 ;
V_16 -> V_6 = V_19 ;
}
}
static inline int
F_11 ( const T_1 * V_3 , const T_3 V_20 )
{
if ( F_12 ( V_20 <= V_3 -> V_9 ) )
return 0 ;
else if ( V_20 <= V_3 -> V_10 )
return V_21 ;
else if ( V_3 -> V_8 & V_22 )
return V_23 ;
else
return V_24 ;
}
static int
F_13 ( const T_1 * V_3 , const T_4 V_25 , T_3 * V_26 )
{
if ( V_25 >= 0 ) {
if ( ( T_3 ) V_25 <= V_3 -> V_9 ) {
* V_26 = V_25 ;
} else if ( ( T_3 ) V_25 <= V_3 -> V_10 ) {
return V_21 ;
} else if ( V_3 -> V_8 & V_22 ) {
return V_23 ;
} else {
return V_24 ;
}
}
else {
if ( ( T_3 ) - V_25 <= V_3 -> V_9 ) {
* V_26 = V_3 -> V_9 + V_25 ;
} else if ( ( T_3 ) - V_25 <= V_3 -> V_10 ) {
return V_21 ;
} else if ( V_3 -> V_8 & V_22 ) {
return V_23 ;
} else {
return V_24 ;
}
}
return 0 ;
}
static int
F_14 ( const T_1 * V_3 , const T_4 V_25 , T_3 * V_26 , T_3 * V_27 )
{
int V_28 ;
V_28 = F_13 ( V_3 , V_25 , V_26 ) ;
if ( ! V_28 )
* V_27 = V_3 -> V_9 - * V_26 ;
return V_28 ;
}
static int
F_15 ( const T_1 * V_3 ,
const T_4 V_25 , T_4 const V_29 ,
T_3 * V_26 , T_3 * V_30 )
{
T_3 V_31 ;
int V_28 ;
F_5 ( V_26 ) ;
F_5 ( V_30 ) ;
V_28 = F_13 ( V_3 , V_25 , V_26 ) ;
if ( V_28 )
return V_28 ;
if ( V_29 < - 1 ) {
return V_21 ;
}
if ( V_29 == - 1 )
* V_30 = V_3 -> V_9 - * V_26 ;
else
* V_30 = V_29 ;
V_31 = * V_26 + * V_30 ;
if ( V_31 < * V_26 )
return V_21 ;
return F_11 ( V_3 , V_31 ) ;
}
static void
F_16 ( const T_1 * V_3 ,
const T_4 V_25 , T_4 const V_29 ,
T_3 * V_26 , T_3 * V_30 )
{
int V_28 ;
V_28 = F_15 ( V_3 , V_25 , V_29 , V_26 , V_30 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
}
void
F_18 ( const T_1 * V_3 ,
const T_4 V_25 , T_4 const V_29 ,
T_3 * V_26 , T_3 * V_30 )
{
F_16 ( V_3 , V_25 , V_29 , V_26 , V_30 ) ;
}
T_1 *
F_19 ( T_1 * V_3 , T_5 V_32 , T_6 V_33 )
{
T_1 * V_34 = NULL ;
T_5 V_35 ;
T_6 V_36 , V_37 ;
T_7 V_38 , V_39 , V_40 , * V_41 ;
const T_7 * V_42 ;
V_35 = V_32 >> 3 ;
V_38 = V_32 % 8 ;
V_39 = 8 - V_38 ;
if ( V_33 == - 1 ) {
V_36 = F_20 ( V_3 , V_35 ) ;
V_40 = 0 ;
} else {
V_36 = V_33 >> 3 ;
V_40 = V_33 % 8 ;
if ( V_40 ) {
V_36 ++ ;
}
}
if ( ( V_38 == 0 ) && ( V_40 == 0 ) ) {
return F_21 ( V_3 , V_35 , V_36 , - 1 ) ;
}
F_5 ( V_36 > 0 ) ;
if ( F_20 ( V_3 , V_35 ) > V_36 ) {
V_42 = F_22 ( V_3 , V_35 , V_36 + 1 ) ;
V_41 = ( T_7 * ) F_23 ( V_36 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
V_41 [ V_37 ] = ( V_42 [ V_37 ] << V_38 ) | ( V_42 [ V_37 + 1 ] >> V_39 ) ;
} else {
V_42 = F_22 ( V_3 , V_35 , V_36 ) ;
V_41 = ( T_7 * ) F_23 ( V_36 ) ;
for ( V_37 = 0 ; V_37 < ( V_36 - 1 ) ; V_37 ++ )
V_41 [ V_37 ] = ( V_42 [ V_37 ] << V_38 ) | ( V_42 [ V_37 + 1 ] >> V_39 ) ;
V_41 [ V_36 - 1 ] = V_42 [ V_36 - 1 ] << V_38 ;
}
V_41 [ V_36 - 1 ] &= V_43 [ V_40 ] ;
V_34 = F_24 ( V_3 , V_41 , V_36 , V_36 ) ;
F_25 ( V_34 , V_44 ) ;
return V_34 ;
}
static T_1 *
F_26 ( T_1 * V_3 , T_3 V_25 , T_3 V_45 )
{
T_1 * V_46 ;
T_7 * V_42 = ( T_7 * ) F_23 ( V_45 ) ;
F_27 ( V_3 , V_42 , V_25 , V_45 ) ;
V_46 = F_28 ( V_42 , V_45 , V_45 ) ;
F_25 ( V_46 , V_44 ) ;
return V_46 ;
}
T_1 *
F_29 ( T_1 * V_3 , T_3 V_25 , T_3 V_45 )
{
if ( V_3 -> V_2 -> V_47 ) {
T_1 * V_46 ;
V_46 = V_3 -> V_2 -> V_47 ( V_3 , V_25 , V_45 ) ;
if ( V_46 )
return V_46 ;
}
return F_26 ( V_3 , V_25 , V_45 ) ;
}
T_1 *
V_47 ( T_1 * V_3 )
{
return F_29 ( V_3 , 0 , V_3 -> V_9 ) ;
}
T_3
F_30 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_9 ;
}
T_4
F_20 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_48 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_48 ) ;
if ( V_28 )
return 0 ;
return V_48 ;
}
T_3
F_31 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_48 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_48 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_48 == 0 ) {
if ( V_20 >= V_3 -> V_10 ) {
if ( V_3 -> V_8 & V_22 ) {
F_17 ( V_23 ) ;
} else {
F_17 ( V_24 ) ;
}
} else
F_17 ( V_21 ) ;
}
return V_48 ;
}
T_8
F_32 ( const T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_3 V_20 , V_49 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_15 ( V_3 , V_25 , V_9 , & V_20 , & V_49 ) ;
if ( V_28 )
return FALSE ;
return TRUE ;
}
void
F_33 ( const T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_3 V_20 , V_49 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_17 ( V_24 ) ;
}
F_16 ( V_3 , V_25 , V_9 , & V_20 , & V_49 ) ;
}
T_8
F_34 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_13 ( V_3 , V_25 , & V_20 ) ;
if ( V_28 )
return FALSE ;
if ( V_20 < V_3 -> V_9 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
void
F_35 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_13 ( V_3 , V_25 , & V_20 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
}
T_3
F_36 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_10 ;
}
T_4
F_37 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_13 ( V_3 , V_25 , & V_20 ) ;
if ( V_28 )
return 0 ;
if ( V_3 -> V_10 >= V_20 )
return V_3 -> V_10 - V_20 ;
else
return 0 ;
}
void
F_38 ( T_1 * V_3 , const T_3 V_10 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_10 > V_3 -> V_10 )
F_17 ( V_24 ) ;
V_3 -> V_10 = V_10 ;
if ( V_10 < V_3 -> V_9 )
V_3 -> V_9 = V_10 ;
}
T_3
F_39 ( const T_1 * V_3 , const T_3 V_50 )
{
if ( V_3 -> V_2 -> V_51 )
return V_3 -> V_2 -> V_51 ( V_3 , V_50 ) ;
F_40 () ;
return 0 ;
}
T_3
F_41 ( const T_1 * V_3 )
{
return F_39 ( V_3 , 0 ) ;
}
static const T_7 *
F_42 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 , int * V_52 )
{
T_3 V_20 , V_49 ;
int V_28 ;
V_28 = F_15 ( V_3 , V_25 , V_9 , & V_20 , & V_49 ) ;
if ( V_28 ) {
if ( V_52 )
* V_52 = V_28 ;
return NULL ;
}
if ( V_3 -> V_11 )
return V_3 -> V_11 + V_20 ;
if ( V_3 -> V_2 -> F_22 )
return V_3 -> V_2 -> F_22 ( V_3 , V_20 , V_49 ) ;
F_40 () ;
return NULL ;
}
static const T_7 *
F_43 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
int V_28 = 0 ;
const T_7 * V_53 ;
V_53 = F_42 ( V_3 , V_25 , V_9 , & V_28 ) ;
if ( V_53 == NULL ) {
F_5 ( V_28 > 0 ) ;
F_17 ( V_28 ) ;
}
return V_53 ;
}
static const T_7 *
F_44 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_9 )
{
T_3 V_31 ;
T_3 V_54 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 8 ) ;
if ( V_25 < 0 || ! V_3 -> V_11 ) {
return F_43 ( V_3 , V_25 , V_9 ) ;
}
V_54 = V_25 ;
V_31 = V_54 + V_9 ;
if ( V_31 <= V_3 -> V_9 ) {
return V_3 -> V_11 + V_54 ;
}
if ( V_31 > V_3 -> V_10 ) {
if ( V_3 -> V_8 & V_22 ) {
F_17 ( V_23 ) ;
} else {
F_17 ( V_24 ) ;
}
}
F_17 ( V_21 ) ;
return NULL ;
}
static const T_7 *
F_45 ( const T_7 * V_55 , T_9 V_56 , const T_7 * V_57 , T_10 * V_58 )
{
T_11 V_19 [ 256 ] = { 0 } ;
const T_7 * V_59 ;
while ( * V_57 )
V_19 [ * V_57 ++ ] = 1 ;
V_59 = V_55 + V_56 ;
while ( V_55 < V_59 ) {
if ( V_19 [ * V_55 ] ) {
if ( V_58 )
* V_58 = * V_55 ;
return V_55 ;
}
V_55 ++ ;
}
return NULL ;
}
void *
F_27 ( T_1 * V_3 , void * V_60 , const T_4 V_25 , T_9 V_9 )
{
T_3 V_20 , V_49 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 0x7FFFFFFF ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
if ( V_3 -> V_11 ) {
return memcpy ( V_60 , V_3 -> V_11 + V_20 , V_49 ) ;
}
if ( V_3 -> V_2 -> F_27 )
return V_3 -> V_2 -> F_27 ( V_3 , V_60 , V_20 , V_49 ) ;
F_40 () ;
return NULL ;
}
void *
F_46 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , T_9 V_9 )
{
T_3 V_20 , V_49 ;
void * V_62 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
V_62 = F_47 ( V_61 , V_49 ) ;
return F_27 ( V_3 , V_62 , V_20 , V_49 ) ;
}
const T_7 *
F_22 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
return F_43 ( V_3 , V_25 , V_9 ) ;
}
T_7
F_48 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_7 ) ) ;
return * V_63 ;
}
T_13
F_49 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_13 ) ) ;
return F_50 ( V_63 ) ;
}
T_5
F_51 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 3 ) ;
return F_52 ( V_63 ) ;
}
T_5
F_53 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_54 ( V_63 ) ;
}
T_14
F_55 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 5 ) ;
return F_56 ( V_63 ) ;
}
T_14
F_57 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 6 ) ;
return F_58 ( V_63 ) ;
}
T_14
F_59 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 7 ) ;
return F_60 ( V_63 ) ;
}
T_14
F_61 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_14 ) ) ;
return F_62 ( V_63 ) ;
}
static int
F_63 ( const T_5 V_64 )
{
return ( ( V_64 & ~ V_65 ) == 0 ) ;
}
static T_15
F_64 ( const T_5 V_64 )
{
long V_66 ;
long V_67 ;
long V_68 ;
V_66 = V_64 & V_65 ;
V_67 = V_64 & V_69 ;
V_68 = V_64 & V_70 ;
if ( F_63 ( V_64 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_67 = ( ( V_67 >> V_71 ) - V_72 ) -
V_71 ;
V_68 |= V_73 ;
if ( V_66 )
return - V_68 * pow ( 2 , V_67 ) ;
else
return V_68 * pow ( 2 , V_67 ) ;
}
static int
F_65 ( const T_14 V_64 )
{
return ( ( V_64 & ~ V_65 ) == 0 ) ;
}
static T_16
F_66 ( const T_14 V_64 )
{
T_17 V_66 ;
T_17 V_67 ;
T_17 V_68 ;
V_66 = V_64 & V_74 ;
V_67 = V_64 & V_75 ;
V_68 = V_64 & V_76 ;
if ( F_65 ( V_64 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_67 = ( ( V_67 >> V_77 ) - V_78 ) -
V_77 ;
V_68 |= V_79 ;
if ( V_66 )
return - V_68 * pow ( 2 , V_67 ) ;
else
return V_68 * pow ( 2 , V_67 ) ;
}
T_15
F_67 ( T_1 * V_3 , const int V_25 )
{
#if F_68 ( V_80 )
return F_64 ( F_53 ( V_3 , V_25 ) ) ;
#else
union {
T_15 V_81 ;
T_5 V_64 ;
} V_82 ;
V_82 . V_64 = F_53 ( V_3 , V_25 ) ;
return V_82 . V_81 ;
#endif
}
T_16
F_69 ( T_1 * V_3 , const int V_25 )
{
#if F_68 ( V_80 )
union {
T_5 V_64 [ 2 ] ;
T_14 V_83 ;
} V_82 ;
#else
union {
T_16 V_84 ;
T_5 V_64 [ 2 ] ;
} V_82 ;
#endif
#ifdef F_70
V_82 . V_64 [ 0 ] = F_53 ( V_3 , V_25 ) ;
V_82 . V_64 [ 1 ] = F_53 ( V_3 , V_25 + 4 ) ;
#else
V_82 . V_64 [ 0 ] = F_53 ( V_3 , V_25 + 4 ) ;
V_82 . V_64 [ 1 ] = F_53 ( V_3 , V_25 ) ;
#endif
#if F_68 ( V_80 )
return F_66 ( V_82 . V_83 ) ;
#else
return V_82 . V_84 ;
#endif
}
T_13
F_71 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_13 ) ) ;
return F_72 ( V_63 ) ;
}
T_5
F_73 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 3 ) ;
return F_74 ( V_63 ) ;
}
T_5
F_75 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_76 ( V_63 ) ;
}
T_14
F_77 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 5 ) ;
return F_78 ( V_63 ) ;
}
T_14
F_79 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 6 ) ;
return F_80 ( V_63 ) ;
}
T_14
F_81 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , 7 ) ;
return F_82 ( V_63 ) ;
}
T_14
F_83 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_14 ) ) ;
return F_84 ( V_63 ) ;
}
T_15
F_85 ( T_1 * V_3 , const int V_25 )
{
#if F_68 ( V_80 )
return F_64 ( F_75 ( V_3 , V_25 ) ) ;
#else
union {
T_15 V_81 ;
T_5 V_64 ;
} V_82 ;
V_82 . V_64 = F_75 ( V_3 , V_25 ) ;
return V_82 . V_81 ;
#endif
}
T_16
F_86 ( T_1 * V_3 , const int V_25 )
{
#if F_68 ( V_80 )
union {
T_5 V_64 [ 2 ] ;
T_14 V_83 ;
} V_82 ;
#else
union {
T_16 V_84 ;
T_5 V_64 [ 2 ] ;
} V_82 ;
#endif
#ifdef F_70
V_82 . V_64 [ 0 ] = F_75 ( V_3 , V_25 + 4 ) ;
V_82 . V_64 [ 1 ] = F_75 ( V_3 , V_25 ) ;
#else
V_82 . V_64 [ 0 ] = F_75 ( V_3 , V_25 ) ;
V_82 . V_64 [ 1 ] = F_75 ( V_3 , V_25 + 4 ) ;
#endif
#if F_68 ( V_80 )
return F_66 ( V_82 . V_83 ) ;
#else
return V_82 . V_84 ;
#endif
}
T_5
F_87 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_63 ;
T_5 V_85 ;
V_63 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
memcpy ( & V_85 , V_63 , sizeof V_85 ) ;
return V_85 ;
}
void
F_88 ( T_1 * V_3 , const T_4 V_25 , struct V_86 * V_85 )
{
const T_7 * V_63 ;
V_63 = F_43 ( V_3 , V_25 , sizeof( * V_85 ) ) ;
memcpy ( V_85 , V_63 , sizeof *V_85 ) ;
}
void
F_89 ( T_1 * V_3 , const T_4 V_25 , T_18 * V_87 )
{
F_43 ( V_3 , V_25 , sizeof( * V_87 ) ) ;
V_87 -> V_88 = F_53 ( V_3 , V_25 ) ;
V_87 -> V_89 = F_49 ( V_3 , V_25 + 4 ) ;
V_87 -> V_90 = F_49 ( V_3 , V_25 + 6 ) ;
F_27 ( V_3 , V_87 -> V_91 , V_25 + 8 , sizeof V_87 -> V_91 ) ;
}
void
F_90 ( T_1 * V_3 , const T_4 V_25 , T_18 * V_87 )
{
F_43 ( V_3 , V_25 , sizeof( * V_87 ) ) ;
V_87 -> V_88 = F_75 ( V_3 , V_25 ) ;
V_87 -> V_89 = F_71 ( V_3 , V_25 + 4 ) ;
V_87 -> V_90 = F_71 ( V_3 , V_25 + 6 ) ;
F_27 ( V_3 , V_87 -> V_91 , V_25 + 8 , sizeof V_87 -> V_91 ) ;
}
void
F_91 ( T_1 * V_3 , const T_4 V_25 , T_18 * V_87 , const T_3 V_92 )
{
if ( V_92 ) {
F_90 ( V_3 , V_25 , V_87 ) ;
} else {
F_89 ( V_3 , V_25 , V_87 ) ;
}
}
T_7
F_92 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 )
{
return ( T_7 ) F_93 ( V_3 , V_32 , V_33 ) ;
}
void
F_94 ( T_1 * V_3 , T_3 V_32 , T_4 V_33 , T_7 * V_41 , T_8 V_93 )
{
T_7 V_94 , V_95 ;
T_4 V_25 = V_32 >> 3 ;
V_32 = V_32 & 0x7 ;
V_94 = ( V_93 ) ? 0xff : V_96 [ V_32 ] ;
V_95 = ( V_93 ) ? V_32 : ( 8 - V_32 ) ;
if ( F_12 ( V_32 != 0 ) ) {
T_13 V_97 = ( T_13 ) F_48 ( V_3 , V_25 ) ;
while ( V_33 >= 8 ) {
V_25 ++ ;
V_97 = ( ( V_97 & V_94 ) << 8 ) | F_48 ( V_3 , V_25 ) ;
if ( V_93 )
* V_41 ++ = ( T_7 ) ( F_95 ( V_97 ) >> V_95 ) ;
else
* V_41 ++ = ( T_7 ) ( V_97 >> V_95 ) ;
V_33 -= 8 ;
}
if ( V_33 > 0 ) {
T_7 V_98 = V_32 + V_33 ;
if ( V_98 > 8 ) {
V_25 ++ ;
V_97 = ( ( V_97 & V_94 ) << 8 ) | F_48 ( V_3 , V_25 ) ;
}
if ( V_93 ) {
if ( V_98 > 8 )
V_97 = ( F_95 ( V_97 ) >> V_32 ) & ( V_99 [ V_33 ] ) ;
else
V_97 = ( V_97 >> V_32 ) & ( V_99 [ V_33 ] ) ;
} else {
if ( V_98 > 8 )
V_97 = V_97 >> ( 16 - V_98 ) ;
else
V_97 = ( V_97 & V_94 ) >> ( 8 - V_98 ) ;
}
* V_41 = ( T_7 ) V_97 ;
}
} else {
while ( V_33 >= 8 ) {
* V_41 ++ = F_48 ( V_3 , V_25 ) ;
V_25 ++ ;
V_33 -= 8 ;
}
if ( V_33 > 0 ) {
if ( V_93 )
* V_41 = F_48 ( V_3 , V_25 ) & V_99 [ V_33 ] ;
else
* V_41 = F_48 ( V_3 , V_25 ) >> ( 8 - V_33 ) ;
}
}
}
T_7 *
F_96 ( T_1 * V_3 , T_3 V_32 , T_4 V_33 , T_8 V_93 )
{
T_4 V_100 ;
T_7 * V_41 ;
if ( V_33 < 0 ) {
F_40 () ;
}
V_100 = ( V_33 >> 3 ) + ( ( V_33 & 0x7 ) != 0 ) ;
V_41 = ( T_7 * ) F_47 ( F_97 () , V_100 ) ;
F_94 ( V_3 , V_32 , V_33 , V_41 , V_93 ) ;
return V_41 ;
}
T_13
F_98 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 T_19 V_101 )
{
return ( T_13 ) F_93 ( V_3 , V_32 , V_33 ) ;
}
T_5
F_99 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 T_19 V_101 )
{
return ( T_5 ) F_93 ( V_3 , V_32 , V_33 ) ;
}
T_14
F_100 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 T_19 V_101 )
{
return F_93 ( V_3 , V_32 , V_33 ) ;
}
static T_14
F_93 ( T_1 * V_3 , T_3 V_32 , const T_4 V_102 )
{
T_14 V_97 ;
T_3 V_103 = V_32 >> 3 ;
T_7 V_104 = 8 - ( V_32 % 8 ) ;
if( V_104 > V_102 )
{
T_7 V_105 = V_104 - V_102 ;
V_97 = ( F_48 ( V_3 , V_103 ) >> V_105 ) & V_99 [ V_102 % 8 ] ;
}
else
{
T_7 V_106 = V_102 ;
V_97 = 0 ;
V_104 %= 8 ;
if( V_104 != 0 )
{
V_97 = F_48 ( V_3 , V_103 ) & V_99 [ V_104 ] ;
V_106 -= V_104 ;
V_103 ++ ;
}
while ( V_106 > 7 )
{
switch ( V_106 >> 4 )
{
case 0 :
V_97 <<= 8 ;
V_97 += F_48 ( V_3 , V_103 ) ;
V_106 -= 8 ;
V_103 ++ ;
break;
case 1 :
V_97 <<= 16 ;
V_97 += F_49 ( V_3 , V_103 ) ;
V_106 -= 16 ;
V_103 += 2 ;
break;
case 2 :
case 3 :
V_97 <<= 32 ;
V_97 += F_53 ( V_3 , V_103 ) ;
V_106 -= 32 ;
V_103 += 4 ;
break;
default:
V_97 = F_61 ( V_3 , V_103 ) ;
V_106 -= 64 ;
V_103 += 8 ;
break;
}
}
if( V_106 )
{
V_97 <<= V_106 ;
V_97 += ( F_48 ( V_3 , V_103 ) >> ( 8 - V_106 ) ) ;
}
}
return V_97 ;
}
T_5
F_101 ( T_1 * V_3 , const T_3 V_32 , const T_4 V_33 , const T_3 T_19 V_101 )
{
return ( T_5 ) F_93 ( V_3 , V_32 , V_33 ) ;
}
static T_4
F_102 ( T_1 * V_3 , T_3 V_20 , T_3 V_107 , T_7 V_108 )
{
const T_7 * V_63 ;
const T_7 * V_109 ;
V_63 = F_22 ( V_3 , V_20 , V_107 ) ;
V_109 = ( const T_7 * ) memchr ( V_63 , V_108 , V_107 ) ;
if ( ! V_109 )
return - 1 ;
return ( T_4 ) ( ( V_109 - V_63 ) + V_20 ) ;
}
T_4
F_103 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_110 , const T_7 V_108 )
{
const T_7 * V_109 ;
T_3 V_20 ;
T_3 V_111 ;
T_3 V_107 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_111 ) ;
if ( V_110 == - 1 ) {
V_107 = V_111 ;
}
else if ( V_111 < ( T_3 ) V_110 ) {
V_107 = V_111 ;
}
else {
V_107 = V_110 ;
}
if ( V_3 -> V_11 ) {
V_109 = ( const T_7 * ) memchr ( V_3 -> V_11 + V_20 , V_108 , V_107 ) ;
if ( V_109 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_109 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_103 )
return V_3 -> V_2 -> F_103 ( V_3 , V_20 , V_107 , V_108 ) ;
return F_102 ( V_3 , V_25 , V_107 , V_108 ) ;
}
static T_4
F_104 ( T_1 * V_3 , T_3 V_20 , T_3 V_107 , const T_7 * V_57 , T_10 * V_58 )
{
const T_7 * V_63 ;
const T_7 * V_109 ;
V_63 = F_22 ( V_3 , V_20 , V_107 ) ;
V_109 = F_45 ( V_63 , V_107 , V_57 , V_58 ) ;
if ( ! V_109 )
return - 1 ;
return ( T_4 ) ( ( V_109 - V_63 ) + V_20 ) ;
}
T_4
F_105 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_110 , const T_7 * V_57 , T_10 * V_58 )
{
const T_7 * V_109 ;
T_3 V_20 ;
T_3 V_111 ;
T_3 V_107 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_111 ) ;
if ( V_110 == - 1 ) {
V_107 = V_111 ;
}
else if ( V_111 < ( T_3 ) V_110 ) {
V_107 = V_111 ;
}
else {
V_107 = V_110 ;
}
if ( V_3 -> V_11 ) {
V_109 = F_45 ( V_3 -> V_11 + V_20 , V_107 , V_57 , V_58 ) ;
if ( V_109 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_109 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_105 )
return V_3 -> V_2 -> F_105 ( V_3 , V_20 , V_107 , V_57 , V_58 ) ;
return F_104 ( V_3 , V_20 , V_107 , V_57 , V_58 ) ;
}
T_3
F_106 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_112 ;
T_4 V_113 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_112 ) ;
V_113 = F_103 ( V_3 , V_20 , - 1 , 0 ) ;
if ( V_113 == - 1 ) {
if ( V_3 -> V_9 < V_3 -> V_10 ) {
F_17 ( V_21 ) ;
} else {
if ( V_3 -> V_8 & V_22 ) {
F_17 ( V_23 ) ;
} else {
F_17 ( V_24 ) ;
}
}
}
return ( V_113 - V_20 ) + 1 ;
}
T_3
F_107 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_37 = 0 ;
T_20 V_114 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
do {
V_114 = F_49 ( V_3 , V_25 + V_37 ) ;
V_37 += 2 ;
} while( V_114 != 0 );
return V_37 ;
}
T_4
F_108 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_110 )
{
T_4 V_115 ;
T_3 V_20 , V_112 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_112 ) ;
V_115 = F_103 ( V_3 , V_20 , V_110 , 0 ) ;
if ( V_115 == - 1 ) {
return - 1 ;
}
else {
return V_115 - V_20 ;
}
}
T_4
F_109 ( T_1 * V_3 , const T_4 V_25 , const T_11 * V_116 , const T_9 V_4 )
{
const T_7 * V_63 ;
V_63 = F_42 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_63 ) {
int V_117 = strncmp ( ( const char * ) V_63 , V_116 , V_4 ) ;
return ( V_117 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_110 ( T_1 * V_3 , const T_4 V_25 , const T_11 * V_116 , const T_9 V_4 )
{
const T_7 * V_63 ;
V_63 = F_42 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_63 ) {
int V_117 = F_111 ( ( const char * ) V_63 , V_116 , V_4 ) ;
return ( V_117 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_112 ( T_1 * V_3 , const T_4 V_25 , const T_7 * V_116 , T_9 V_4 )
{
const T_7 * V_63 ;
V_63 = F_42 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_63 ) {
int V_117 = memcmp ( V_63 , V_116 , V_4 ) ;
return ( V_117 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
char *
F_113 ( T_12 * V_61 , T_1 * V_3 , int V_25 ,
const int V_45 , const T_8 V_118 )
{
char * V_119 ;
int V_37 ;
T_13 V_120 ;
F_33 ( V_3 , V_25 , 2 * V_45 ) ;
V_119 = ( char * ) F_47 ( V_61 , V_45 + 1 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; V_37 ++ ) {
V_120 = V_118 ? F_71 ( V_3 , V_25 )
: F_49 ( V_3 , V_25 ) ;
V_119 [ V_37 ] = V_120 < 256 ? V_120 : '.' ;
V_25 += 2 ;
}
V_119 [ V_45 ] = 0 ;
return V_119 ;
}
T_11 *
F_114 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_63 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
if ( ( V_63 = F_43 ( V_3 , V_25 , V_4 ) ) == NULL ) {
V_45 = F_20 ( V_3 , V_25 ) ;
V_63 = F_43 ( V_3 , V_25 , V_45 ) ;
}
return F_115 ( V_63 , V_45 ) ;
}
T_11 *
F_116 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_63 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
if ( ( V_63 = F_43 ( V_3 , V_25 , V_4 ) ) == NULL ) {
V_45 = F_20 ( V_3 , V_25 ) ;
V_63 = F_43 ( V_3 , V_25 , V_45 ) ;
}
return F_117 ( V_63 , V_45 ) ;
}
T_11 *
F_118 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_63 , * V_53 ;
T_4 V_45 ;
T_4 V_121 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
if ( ( V_63 = F_43 ( V_3 , V_25 , V_4 ) ) == NULL ) {
V_45 = F_20 ( V_3 , V_25 ) ;
V_63 = F_43 ( V_3 , V_25 , V_45 ) ;
}
for ( V_53 = V_63 , V_121 = 0 ; V_121 < V_45 && * V_53 != '\0' ; V_53 ++ , V_121 ++ )
;
return F_115 ( V_63 , V_121 ) ;
}
T_11 *
F_119 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_63 , * V_53 ;
T_4 V_45 ;
T_4 V_121 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
if ( ( V_63 = F_43 ( V_3 , V_25 , V_4 ) ) == NULL ) {
V_45 = F_20 ( V_3 , V_25 ) ;
V_63 = F_43 ( V_3 , V_25 , V_45 ) ;
}
for ( V_53 = V_63 , V_121 = 0 ; V_121 < V_45 && * V_53 != '\0' ; V_53 ++ , V_121 ++ )
;
return F_117 ( V_63 , V_121 ) ;
}
T_7 *
F_120 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_122 ;
F_33 ( V_3 , V_25 , V_9 ) ;
V_122 = ( T_7 * ) F_47 ( V_61 , V_9 + 1 ) ;
F_27 ( V_3 , V_122 , V_25 , V_9 ) ;
V_122 [ V_9 ] = '\0' ;
return V_122 ;
}
T_11 *
F_121 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 T_19 )
{
T_20 V_114 ;
T_4 V_37 ;
T_21 * V_122 ;
F_33 ( V_3 , V_25 , V_9 ) ;
V_122 = F_122 ( V_61 , NULL ) ;
for( V_37 = 0 ; V_37 < V_9 ; V_37 += 2 ) {
if ( T_19 == V_123 )
V_114 = F_49 ( V_3 , V_25 + V_37 ) ;
else
V_114 = F_71 ( V_3 , V_25 + V_37 ) ;
F_123 ( V_122 , V_114 ) ;
}
return ( T_11 * ) F_124 ( V_122 ) ;
}
T_7 *
F_125 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 T_19 )
{
const T_7 * V_63 ;
T_7 * V_122 ;
switch ( T_19 & V_124 ) {
case V_125 :
default:
V_122 = F_120 ( V_61 , V_3 , V_25 , V_9 ) ;
break;
case V_126 :
V_122 = F_120 ( V_61 , V_3 , V_25 , V_9 ) ;
break;
case V_127 :
V_122 = F_121 ( V_61 , V_3 , V_25 , V_9 ,
T_19 & V_128 ) ;
break;
case V_129 :
V_122 = F_121 ( V_61 , V_3 , V_25 , V_9 ,
T_19 & V_128 ) ;
break;
case V_130 :
F_33 ( V_3 , V_25 , V_9 ) ;
V_122 = ( T_7 * ) F_47 ( V_61 , V_9 + 1 ) ;
if ( V_9 != 0 ) {
V_63 = F_43 ( V_3 , V_25 , V_9 ) ;
memcpy ( V_122 , V_63 , V_9 ) ;
F_126 ( V_122 , V_9 ) ;
}
V_122 [ V_9 ] = '\0' ;
break;
}
return V_122 ;
}
T_7 *
F_127 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , T_4 * V_131 )
{
T_3 V_4 ;
T_7 * V_132 ;
V_4 = F_106 ( V_3 , V_25 ) ;
V_132 = ( T_7 * ) F_47 ( V_61 , V_4 ) ;
F_27 ( V_3 , V_132 , V_25 , V_4 ) ;
if ( V_131 )
* V_131 = V_4 ;
return V_132 ;
}
T_7 *
F_128 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , T_4 * V_131 , const T_3 T_19 )
{
T_3 V_4 ;
T_7 * V_132 ;
switch ( T_19 & V_124 ) {
case V_125 :
default:
V_132 = F_127 ( V_61 , V_3 , V_25 , V_131 ) ;
break;
case V_126 :
V_132 = F_127 ( V_61 , V_3 , V_25 , V_131 ) ;
break;
case V_127 :
V_132 = F_129 ( V_61 , V_3 , V_25 , V_131 ,
T_19 & V_128 ) ;
break;
case V_129 :
V_132 = F_129 ( V_61 , V_3 , V_25 , V_131 ,
T_19 & V_128 ) ;
break;
case V_130 :
V_4 = F_106 ( V_3 , V_25 ) ;
V_132 = ( T_7 * ) F_47 ( V_61 , V_4 ) ;
F_27 ( V_3 , V_132 , V_25 , V_4 ) ;
F_126 ( V_132 , V_4 ) ;
if ( V_131 )
* V_131 = V_4 ;
break;
}
return V_132 ;
}
const T_7 *
F_130 ( T_1 * V_3 , const T_4 V_25 , T_4 * V_131 )
{
T_3 V_4 ;
const T_7 * V_132 ;
V_4 = F_106 ( V_3 , V_25 ) ;
V_132 = F_43 ( V_3 , V_25 , V_4 ) ;
if ( V_131 )
* V_131 = V_4 ;
return V_132 ;
}
T_11 *
F_129 ( T_12 * V_61 , T_1 * V_3 , const T_4 V_25 , T_4 * V_131 , const T_3 T_19 )
{
T_20 V_114 ;
T_4 V_4 ;
T_4 V_37 ;
T_21 * V_122 ;
V_4 = F_107 ( V_3 , V_25 ) ;
V_122 = F_122 ( V_61 , NULL ) ;
for( V_37 = 0 ; V_37 < V_4 ; V_37 += 2 ) {
if ( T_19 == V_123 )
V_114 = F_49 ( V_3 , V_25 + V_37 ) ;
else
V_114 = F_71 ( V_3 , V_25 + V_37 ) ;
F_123 ( V_122 , V_114 ) ;
}
if ( V_131 )
* V_131 = V_37 ;
return ( T_11 * ) F_124 ( V_122 ) ;
}
static T_4
F_131 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_133 , T_7 * V_119 , T_4 * V_134 )
{
T_4 V_121 ;
T_3 V_20 ;
T_4 V_107 , V_45 ;
T_8 V_135 = FALSE ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_45 ) ;
F_5 ( V_133 != 0 ) ;
if ( V_133 == 1 ) {
V_119 [ 0 ] = 0 ;
* V_134 = 1 ;
return 0 ;
}
if ( V_45 == 0 ) {
F_17 ( V_24 ) ;
}
F_5 ( V_45 != - 1 ) ;
F_5 ( V_133 <= V_136 ) ;
if ( ( T_3 ) V_45 < V_133 ) {
V_107 = V_45 ;
V_135 = TRUE ;
}
else {
V_107 = V_133 ;
}
V_121 = F_108 ( V_3 , V_20 , V_107 - 1 ) ;
if ( V_121 == - 1 ) {
F_27 ( V_3 , V_119 , V_20 , V_107 ) ;
if ( V_135 ) {
V_119 [ V_107 ] = 0 ;
* V_134 = V_107 + 1 ;
}
else {
* V_134 = V_107 ;
}
return - 1 ;
}
F_27 ( V_3 , V_119 , V_20 , V_121 + 1 ) ;
* V_134 = V_121 + 1 ;
return V_121 ;
}
T_4
F_132 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_133 , T_7 * V_119 )
{
T_4 V_134 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
return F_131 ( V_3 , V_25 , V_133 , V_119 , & V_134 ) ;
}
T_4
F_133 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_133 , T_7 * V_119 )
{
T_4 V_45 , V_134 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_45 = F_131 ( V_3 , V_25 , V_133 , V_119 , & V_134 ) ;
if ( V_45 == - 1 ) {
V_119 [ V_133 - 1 ] = 0 ;
return V_134 - 1 ;
}
else {
return V_45 ;
}
}
T_4
F_134 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_137 , const T_8 V_138 )
{
T_4 V_139 ;
T_4 V_140 ;
int V_141 ;
T_10 V_58 = 0 ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
V_139 = V_25 + V_45 ;
V_140 = F_105 ( V_3 , V_25 , V_45 , L_1 , & V_58 ) ;
if ( V_140 == - 1 ) {
if ( V_138 ) {
return - 1 ;
} else {
V_141 = V_139 - V_25 ;
if ( V_137 )
* V_137 = V_139 ;
}
} else {
V_141 = V_140 - V_25 ;
if ( V_58 == '\r' ) {
if ( V_140 + 1 >= V_139 ) {
if ( V_138 ) {
return - 1 ;
}
} else {
if ( F_48 ( V_3 , V_140 + 1 ) == '\n' ) {
V_140 ++ ;
}
}
}
if ( V_137 )
* V_137 = V_140 + 1 ;
}
return V_141 ;
}
T_4
F_135 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_137 )
{
T_4 V_142 , V_143 ;
T_8 V_144 ;
T_10 V_145 = 0 ;
T_4 V_139 ;
int V_141 ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
V_139 = V_25 + V_45 ;
V_142 = V_25 ;
V_144 = FALSE ;
for (; ; ) {
if ( V_144 ) {
V_143 = F_103 ( V_3 , V_142 , V_45 ,
'"' ) ;
} else {
V_143 = F_105 ( V_3 , V_142 , V_45 , L_2 , & V_145 ) ;
}
if ( V_143 == - 1 ) {
V_141 = V_139 - V_25 ;
if ( V_137 )
* V_137 = V_139 ;
break;
}
if ( V_144 ) {
V_144 = FALSE ;
} else {
if ( V_145 == '"' ) {
V_144 = TRUE ;
} else {
V_141 = V_143 - V_25 ;
if ( V_145 == '\r' ) {
if ( V_143 + 1 < V_139 &&
F_48 ( V_3 , V_143 + 1 )
== '\n' ) {
V_143 ++ ;
}
}
if ( V_137 )
* V_137 = V_143 + 1 ;
break;
}
}
V_142 = V_143 + 1 ;
if ( V_142 >= V_139 ) {
V_141 = V_139 - V_25 ;
if ( V_137 )
* V_137 = V_139 ;
break;
}
}
return V_141 ;
}
T_4
F_136 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_110 )
{
T_4 V_50 = V_25 ;
T_4 V_146 , V_147 ;
T_7 V_148 ;
V_147 = F_30 ( V_3 ) ;
V_146 = V_25 + V_110 ;
if ( V_146 >= V_147 )
{
V_146 = V_147 ;
}
for ( V_50 = V_25 ;
V_50 < V_146 &&
( ( V_148 = F_48 ( V_3 , V_50 ) ) == ' ' ||
V_148 == '\t' || V_148 == '\r' || V_148 == '\n' ) ;
V_50 ++ ) ;
return ( V_50 ) ;
}
T_4
F_137 ( T_1 * V_3 , const T_4 V_25 ) {
T_4 V_50 = V_25 ;
T_7 V_148 ;
for( V_50 = V_25 ; V_50 > 0 &&
( ( V_148 = F_48 ( V_3 , V_50 ) ) == ' ' ||
V_148 == '\t' || V_148 == '\n' || V_148 == '\r' ) ; V_50 -- ) ;
V_50 ++ ;
return ( V_50 ) ;
}
T_11 *
F_138 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , const T_11 V_149 )
{
return F_139 ( F_43 ( V_3 , V_25 , V_45 ) , V_45 , V_149 ) ;
}
const T_11 *
F_140 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , T_22 * V_150 , T_8 V_151 )
{
int V_9 ;
T_7 V_152 ;
int V_37 = 0 ;
char * V_153 ;
T_4 V_154 = V_25 ;
if ( ! V_150 )
V_150 = & V_155 ;
if ( V_45 == - 1 ) {
V_9 = F_30 ( V_3 ) ;
if ( V_9 < V_25 ) {
return L_3 ;
}
} else {
V_9 = V_25 + V_45 ;
}
V_153 = ( char * ) F_47 ( F_97 () , ( V_9 - V_25 ) * 2 + 1 ) ;
while ( V_154 < V_9 ) {
V_152 = F_48 ( V_3 , V_154 ) ;
if ( ! V_151 ) {
V_153 [ V_37 ] = V_150 -> V_156 [ V_152 & 0x0f ] ;
V_37 ++ ;
}
V_151 = FALSE ;
V_152 = V_152 >> 4 ;
if ( V_152 == 0x0f )
break;
V_153 [ V_37 ] = V_150 -> V_156 [ V_152 & 0x0f ] ;
V_37 ++ ;
V_154 ++ ;
}
V_153 [ V_37 ] = '\0' ;
return V_153 ;
}
T_11 *
F_141 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 )
{
return F_142 ( F_43 ( V_3 , V_25 , V_45 ) , V_45 ) ;
}
T_4
F_143 ( T_1 * V_157 , T_1 * V_158 , const T_4 V_159 )
{
T_3 V_160 , V_161 ;
const T_7 * V_162 ;
const T_7 * V_163 ;
const T_3 V_164 = V_158 -> V_9 ;
const T_7 * V_165 ;
F_5 ( V_157 && V_157 -> V_7 ) ;
if ( V_157 -> V_9 < 1 || V_158 -> V_9 < 1 ) {
return - 1 ;
}
V_162 = F_43 ( V_157 , 0 , - 1 ) ;
V_163 = F_43 ( V_158 , 0 , - 1 ) ;
F_16 ( V_157 , V_159 , - 1 ,
& V_160 , & V_161 ) ;
V_165 = F_144 ( V_162 + V_160 , V_161 ,
V_163 , V_164 ) ;
if ( V_165 ) {
return ( T_4 ) ( V_165 - V_162 ) ;
}
return - 1 ;
}
T_1 *
F_145 ( T_1 * V_3 , const int V_25 , int V_166 )
{
T_4 V_167 = V_168 ;
T_3 V_169 = 0 ;
T_7 * V_170 = NULL ;
T_7 * V_171 = NULL ;
T_1 * V_172 = NULL ;
T_23 V_173 = NULL ;
T_24 * V_174 = NULL ;
T_3 V_175 = 0 ;
T_4 V_176 = V_177 ;
T_7 * V_6 = NULL ;
T_3 V_178 = V_179 ;
#ifdef F_146
T_3 V_180 = 0 ;
T_3 V_181 = F_20 ( V_3 , V_25 ) ;
#endif
if ( V_3 == NULL ) {
return NULL ;
}
V_170 = ( T_7 * ) F_46 ( NULL , V_3 , V_25 , V_166 ) ;
if ( ! V_170 )
return NULL ;
V_178 = F_20 ( V_3 , V_25 ) * 2 ;
V_178 = F_147 ( V_178 , V_179 , V_182 ) ;
#ifdef F_146
printf ( L_4 , V_178 ) ;
#endif
V_6 = V_170 ;
V_173 = F_148 ( V_183 , 1 ) ;
V_173 -> V_184 = V_6 ;
V_173 -> V_185 = V_166 ;
V_174 = ( T_24 * ) F_149 ( V_178 ) ;
V_173 -> V_186 = V_174 ;
V_173 -> V_187 = V_178 ;
V_167 = F_150 ( V_173 , V_176 ) ;
V_175 = 1 ;
if ( V_167 != V_168 ) {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_170 ) ;
V_44 ( V_174 ) ;
return NULL ;
}
while ( 1 ) {
memset ( V_174 , '\0' , V_178 ) ;
V_173 -> V_186 = V_174 ;
V_173 -> V_187 = V_178 ;
V_167 = F_152 ( V_173 , V_188 ) ;
if ( V_167 == V_168 || V_167 == V_189 ) {
T_3 V_190 = V_178 - V_173 -> V_187 ;
#ifdef F_146
++ V_180 ;
#endif
if ( V_171 == NULL ) {
V_171 = ( T_7 * ) ( ( V_190 || V_167 != V_189 ) ?
F_153 ( V_174 , V_190 ) :
F_154 ( L_3 ) ) ;
} else {
T_7 * V_191 = ( T_7 * ) F_149 ( V_169 + V_190 ) ;
memcpy ( V_191 , V_171 , V_169 ) ;
memcpy ( V_191 + V_169 , V_174 , V_190 ) ;
V_44 ( V_171 ) ;
V_171 = V_191 ;
}
V_169 += V_190 ;
if ( V_167 == V_189 ) {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_174 ) ;
break;
}
} else if ( V_167 == V_192 ) {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_174 ) ;
if ( V_171 != NULL ) {
break;
} else {
V_44 ( V_170 ) ;
return NULL ;
}
} else if ( V_167 == V_193 && V_175 == 1
&& V_171 == NULL && ( * V_170 == 0x1f ) &&
( * ( V_170 + 1 ) == 0x8b ) ) {
T_24 * V_145 = V_170 + 2 ;
T_24 V_8 = 0 ;
if ( * V_145 == V_194 ) {
V_145 ++ ;
} else {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_170 ) ;
V_44 ( V_174 ) ;
return NULL ;
}
V_8 = * V_145 ;
V_145 += 7 ;
if ( V_8 & ( 1 << 2 ) ) {
T_4 V_195 = ( T_4 ) ( * V_145 |
( * ( V_145 + 1 ) << 8 ) ) ;
V_145 += V_195 ;
}
if ( V_8 & ( 1 << 3 ) ) {
while ( ( V_145 - V_170 ) < V_166 && * V_145 != '\0' ) {
V_145 ++ ;
}
V_145 ++ ;
}
if ( V_8 & ( 1 << 4 ) ) {
while ( ( V_145 - V_170 ) < V_166 && * V_145 != '\0' ) {
V_145 ++ ;
}
V_145 ++ ;
}
F_155 ( V_173 ) ;
V_6 = V_145 ;
V_173 -> V_184 = V_6 ;
if ( V_145 - V_170 > V_166 ) {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_170 ) ;
V_44 ( V_174 ) ;
return NULL ;
}
V_166 -= ( int ) ( V_145 - V_170 ) ;
F_151 ( V_173 ) ;
F_150 ( V_173 , V_176 ) ;
V_175 ++ ;
} else if ( V_167 == V_193 && V_171 == NULL &&
V_175 <= 3 ) {
V_176 = - V_177 ;
F_155 ( V_173 ) ;
V_173 -> V_184 = V_6 ;
V_173 -> V_185 = V_166 ;
F_151 ( V_173 ) ;
memset ( V_174 , '\0' , V_178 ) ;
V_173 -> V_186 = V_174 ;
V_173 -> V_187 = V_178 ;
V_167 = F_150 ( V_173 , V_176 ) ;
V_175 ++ ;
if ( V_167 != V_168 ) {
V_44 ( V_173 ) ;
V_44 ( V_174 ) ;
V_44 ( V_170 ) ;
V_44 ( V_171 ) ;
return NULL ;
}
} else {
F_151 ( V_173 ) ;
V_44 ( V_173 ) ;
V_44 ( V_174 ) ;
if ( V_171 == NULL ) {
V_44 ( V_170 ) ;
return NULL ;
}
break;
}
}
#ifdef F_146
printf ( L_5 , V_180 ) ;
printf ( L_6 , V_181 , V_169 ) ;
#endif
if ( V_171 != NULL ) {
V_172 = F_28 ( ( T_7 * ) V_171 , V_169 , V_169 ) ;
F_25 ( V_172 , V_44 ) ;
}
V_44 ( V_170 ) ;
return V_172 ;
}
T_1 *
F_145 ( T_1 * V_3 V_101 , const int V_25 V_101 , int V_166 V_101 )
{
return NULL ;
}
T_1 *
F_156 ( T_1 * V_16 , T_1 * V_3 , const int V_25 , int V_166 )
{
T_1 * V_196 = F_145 ( V_3 , V_25 , V_166 ) ;
if ( V_196 )
F_157 ( V_16 , V_196 ) ;
return V_196 ;
}
T_4
F_158 ( T_1 * V_3 )
{
return ( ( V_3 -> V_12 == - 1 ) ? ( V_3 -> V_12 = F_41 ( V_3 ) ) : V_3 -> V_12 ) ;
}
void
F_159 ( T_1 * V_3 )
{
V_3 -> V_8 |= V_22 ;
}
struct V_197 *
F_160 ( T_1 * V_3 )
{
return ( V_3 -> V_13 ) ;
}
