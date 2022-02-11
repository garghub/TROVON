T_1 *
F_1 ( const struct V_1 * V_2 )
{
T_1 * V_3 ;
T_2 V_4 = V_2 -> V_5 ;
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
V_4 = V_3 -> V_2 -> V_5 ;
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
F_11 ( const T_1 * V_3 ,
const T_3 V_20 , T_3 const V_21 ,
T_4 * V_22 , T_4 * V_23 )
{
T_4 V_24 ;
int V_25 = 0 ;
F_5 ( V_22 ) ;
F_5 ( V_23 ) ;
F_12 ( V_3 , V_20 , V_22 , V_25 ) ;
if ( V_25 )
return V_25 ;
if ( V_21 < - 1 ) {
return V_26 ;
}
if ( V_21 == - 1 )
* V_23 = V_3 -> V_9 - * V_22 ;
else
* V_23 = V_21 ;
V_24 = * V_22 + * V_23 ;
if ( V_24 < * V_22 )
return V_26 ;
if ( F_13 ( V_24 <= V_3 -> V_9 ) )
return 0 ;
else if ( V_24 <= V_3 -> V_10 )
return V_26 ;
else if ( V_3 -> V_8 & V_27 )
return V_28 ;
else
return V_29 ;
}
static inline void
F_14 ( const T_1 * V_3 ,
const T_3 V_20 , T_3 const V_21 ,
T_4 * V_22 , T_4 * V_23 )
{
int V_25 ;
V_25 = F_11 ( V_3 , V_20 , V_21 , V_22 , V_23 ) ;
if ( V_25 )
F_15 ( V_25 ) ;
}
void
F_16 ( const T_1 * V_3 ,
const T_3 V_20 , T_3 const V_21 ,
T_4 * V_22 , T_4 * V_23 )
{
F_14 ( V_3 , V_20 , V_21 , V_22 , V_23 ) ;
}
T_1 *
F_17 ( T_1 * V_3 , T_5 V_30 , T_6 V_31 )
{
T_1 * V_32 = NULL ;
T_5 V_33 ;
T_6 V_34 , V_35 ;
T_7 V_36 , V_37 , V_38 , * V_39 ;
const T_7 * V_40 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_33 = V_30 >> 3 ;
V_36 = V_30 % 8 ;
V_37 = 8 - V_36 ;
if ( V_31 == - 1 ) {
V_34 = F_18 ( V_3 , V_33 ) ;
V_38 = 0 ;
} else {
V_34 = V_31 >> 3 ;
V_38 = V_31 % 8 ;
if ( V_38 ) {
V_34 ++ ;
}
}
if ( ( V_36 == 0 ) && ( V_38 == 0 ) ) {
return F_19 ( V_3 , V_33 , V_34 , - 1 ) ;
}
F_5 ( V_34 > 0 ) ;
if ( F_18 ( V_3 , V_33 ) > V_34 ) {
V_40 = F_20 ( V_3 , V_33 , V_34 + 1 ) ;
V_39 = ( T_7 * ) F_21 ( V_34 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ )
V_39 [ V_35 ] = ( V_40 [ V_35 ] << V_36 ) | ( V_40 [ V_35 + 1 ] >> V_37 ) ;
} else {
V_40 = F_20 ( V_3 , V_33 , V_34 ) ;
V_39 = ( T_7 * ) F_21 ( V_34 ) ;
for ( V_35 = 0 ; V_35 < ( V_34 - 1 ) ; V_35 ++ )
V_39 [ V_35 ] = ( V_40 [ V_35 ] << V_36 ) | ( V_40 [ V_35 + 1 ] >> V_37 ) ;
V_39 [ V_34 - 1 ] = V_40 [ V_34 - 1 ] << V_36 ;
}
V_39 [ V_34 - 1 ] &= V_41 [ V_38 ] ;
V_32 = F_22 ( V_3 , V_39 , V_34 , V_34 ) ;
F_23 ( V_32 , V_42 ) ;
return V_32 ;
}
static T_1 *
F_24 ( T_1 * V_3 , T_4 V_20 , T_4 V_43 )
{
T_1 * V_44 ;
T_7 * V_40 = ( T_7 * ) F_21 ( V_43 ) ;
F_25 ( V_3 , V_40 , V_20 , V_43 ) ;
V_44 = F_26 ( V_40 , V_43 , V_43 ) ;
F_23 ( V_44 , V_42 ) ;
return V_44 ;
}
T_1 *
F_27 ( T_1 * V_3 , T_4 V_20 , T_4 V_43 )
{
if ( V_3 -> V_2 -> V_45 ) {
T_1 * V_44 ;
V_44 = V_3 -> V_2 -> V_45 ( V_3 , V_20 , V_43 ) ;
if ( V_44 )
return V_44 ;
}
return F_24 ( V_3 , V_20 , V_43 ) ;
}
T_1 *
V_45 ( T_1 * V_3 )
{
return F_27 ( V_3 , 0 , V_3 -> V_9 ) ;
}
T_4
F_28 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_9 ;
}
static inline T_3
F_18 ( const T_1 * V_3 , const T_3 V_20 )
{
T_4 V_46 , V_47 ;
int V_25 = 0 ;
F_29 ( V_3 , V_20 , & V_46 , V_47 , V_25 ) ;
if ( V_25 )
return 0 ;
return V_47 ;
}
T_3
F_30 ( const T_1 * V_3 , const T_3 V_20 )
{
T_4 V_46 , V_47 ;
int V_25 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_29 ( V_3 , V_20 , & V_46 , V_47 , V_25 ) ;
if ( V_25 )
return 0 ;
return V_47 ;
}
T_4
F_31 ( const T_1 * V_3 , const T_3 V_20 )
{
T_4 V_46 , V_47 ;
int V_25 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_29 ( V_3 , V_20 , & V_46 , V_47 , V_25 ) ;
if ( V_25 )
F_15 ( V_25 ) ;
if ( V_47 == 0 ) {
if ( V_46 >= V_3 -> V_10 ) {
if ( V_3 -> V_8 & V_27 ) {
F_15 ( V_28 ) ;
} else {
F_15 ( V_29 ) ;
}
} else
F_15 ( V_26 ) ;
}
return V_47 ;
}
T_8
F_32 ( const T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
T_4 V_46 , V_48 ;
int V_25 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_25 = F_11 ( V_3 , V_20 , V_9 , & V_46 , & V_48 ) ;
if ( V_25 )
return FALSE ;
return TRUE ;
}
void
F_33 ( const T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
T_4 V_49 , V_24 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_15 ( V_29 ) ;
}
if ( V_20 >= 0 ) {
if ( ( T_4 ) V_20 <= V_3 -> V_9 ) {
V_49 = V_20 ;
} else if ( ( T_4 ) V_20 <= V_3 -> V_10 ) {
F_15 ( V_26 ) ;
} else if ( V_3 -> V_8 & V_27 ) {
F_15 ( V_28 ) ;
} else {
F_15 ( V_29 ) ;
}
}
else {
if ( ( T_4 ) - V_20 <= V_3 -> V_9 ) {
V_49 = V_3 -> V_9 + V_20 ;
} else if ( ( T_4 ) - V_20 <= V_3 -> V_10 ) {
F_15 ( V_26 ) ;
} else if ( V_3 -> V_8 & V_27 ) {
F_15 ( V_28 ) ;
} else {
F_15 ( V_29 ) ;
}
}
V_24 = V_49 + V_9 ;
if ( V_24 < V_49 )
F_15 ( V_26 ) ;
if ( F_13 ( V_24 <= V_3 -> V_9 ) )
return;
else if ( V_24 <= V_3 -> V_10 )
F_15 ( V_26 ) ;
else if ( V_3 -> V_8 & V_27 )
F_15 ( V_28 ) ;
else
F_15 ( V_29 ) ;
}
T_8
F_34 ( const T_1 * V_3 , const T_3 V_20 )
{
T_4 V_22 ;
int V_25 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_12 ( V_3 , V_20 , & V_22 , V_25 ) ;
if ( V_25 )
return FALSE ;
if ( V_22 < V_3 -> V_9 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_4
F_35 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_10 ;
}
T_3
F_36 ( const T_1 * V_3 , const T_3 V_20 )
{
T_4 V_22 ;
int V_25 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_12 ( V_3 , V_20 , & V_22 , V_25 ) ;
if ( V_25 )
return 0 ;
if ( V_3 -> V_10 >= V_22 )
return V_3 -> V_10 - V_22 ;
else
return 0 ;
}
void
F_37 ( T_1 * V_3 , const T_4 V_10 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_10 > V_3 -> V_10 )
F_15 ( V_29 ) ;
V_3 -> V_10 = V_10 ;
if ( V_10 < V_3 -> V_9 )
V_3 -> V_9 = V_10 ;
}
T_4
F_38 ( const T_1 * V_3 , const T_4 V_50 )
{
if ( V_3 -> V_2 -> V_51 )
return V_3 -> V_2 -> V_51 ( V_3 , V_50 ) ;
F_39 () ;
return 0 ;
}
T_4
F_40 ( const T_1 * V_3 )
{
return F_38 ( V_3 , 0 ) ;
}
static inline const T_7 *
F_41 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_9 , int * V_52 )
{
T_4 V_46 , V_48 ;
int V_25 ;
V_25 = F_11 ( V_3 , V_20 , V_9 , & V_46 , & V_48 ) ;
if ( V_25 ) {
if ( V_52 )
* V_52 = V_25 ;
return NULL ;
}
if ( V_3 -> V_11 )
return V_3 -> V_11 + V_46 ;
if ( V_3 -> V_2 -> V_53 )
return V_3 -> V_2 -> V_53 ( V_3 , V_46 , V_48 ) ;
F_39 () ;
return NULL ;
}
static inline const T_7 *
F_20 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
int V_25 = 0 ;
const T_7 * V_54 ;
V_54 = F_41 ( V_3 , V_20 , V_9 , & V_25 ) ;
if ( V_54 == NULL ) {
F_5 ( V_25 > 0 ) ;
F_15 ( V_25 ) ;
}
return V_54 ;
}
static inline const T_7 *
F_42 ( T_1 * V_3 , const T_3 V_20 , const T_4 V_9 )
{
T_4 V_24 ;
T_4 V_55 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 8 ) ;
if ( V_20 < 0 || ! V_3 -> V_11 ) {
return F_20 ( V_3 , V_20 , V_9 ) ;
}
V_55 = V_20 ;
V_24 = V_55 + V_9 ;
if ( V_24 <= V_3 -> V_9 ) {
return V_3 -> V_11 + V_55 ;
}
if ( V_24 > V_3 -> V_10 ) {
if ( V_3 -> V_8 & V_27 ) {
F_15 ( V_28 ) ;
} else {
F_15 ( V_29 ) ;
}
}
F_15 ( V_26 ) ;
return NULL ;
}
static inline const T_7 *
F_43 ( const T_7 * V_56 , T_9 V_57 , const T_7 * V_58 , T_10 * V_59 )
{
T_11 V_19 [ 256 ] = { 0 } ;
const T_7 * V_60 ;
while ( * V_58 )
V_19 [ * V_58 ++ ] = 1 ;
V_60 = V_56 + V_57 ;
while ( V_56 < V_60 ) {
if ( V_19 [ * V_56 ] ) {
if ( V_59 )
* V_59 = * V_56 ;
return V_56 ;
}
V_56 ++ ;
}
return NULL ;
}
void *
F_25 ( T_1 * V_3 , void * V_61 , const T_3 V_20 , T_9 V_9 )
{
T_4 V_46 , V_48 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 0x7FFFFFFF ) ;
F_14 ( V_3 , V_20 , ( T_3 ) V_9 , & V_46 , & V_48 ) ;
if ( V_3 -> V_11 ) {
return memcpy ( V_61 , V_3 -> V_11 + V_46 , V_48 ) ;
}
if ( V_3 -> V_2 -> F_25 )
return V_3 -> V_2 -> F_25 ( V_3 , V_61 , V_46 , V_48 ) ;
F_39 () ;
return NULL ;
}
void *
F_44 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_9 V_9 )
{
T_4 V_46 , V_48 ;
void * V_63 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_14 ( V_3 , V_20 , ( T_3 ) V_9 , & V_46 , & V_48 ) ;
V_63 = F_45 ( V_62 , V_48 ) ;
return F_25 ( V_3 , V_63 , V_46 , V_48 ) ;
}
const T_7 *
V_53 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
return F_20 ( V_3 , V_20 , V_9 ) ;
}
T_7
F_46 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_7 ) ) ;
return * V_64 ;
}
T_13
F_47 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_13 ) ) ;
return F_48 ( V_64 ) ;
}
T_5
F_49 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 3 ) ;
return F_50 ( V_64 ) ;
}
T_5
F_51 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_5 ) ) ;
return F_52 ( V_64 ) ;
}
T_14
F_53 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 5 ) ;
return F_54 ( V_64 ) ;
}
T_15
F_55 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_53 ( V_3 , V_20 ) , 40 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_57 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 6 ) ;
return F_58 ( V_64 ) ;
}
T_15
F_59 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_57 ( V_3 , V_20 ) , 48 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_60 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 7 ) ;
return F_61 ( V_64 ) ;
}
T_15
F_62 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_60 ( V_3 , V_20 ) , 56 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_63 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_14 ) ) ;
return F_64 ( V_64 ) ;
}
static int
F_65 ( const T_5 V_66 )
{
return ( ( V_66 & ~ V_67 ) == 0 ) ;
}
static T_16
F_66 ( const T_5 V_66 )
{
long V_68 ;
long V_69 ;
long V_70 ;
V_68 = V_66 & V_67 ;
V_69 = V_66 & V_71 ;
V_70 = V_66 & V_72 ;
if ( F_65 ( V_66 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_69 = ( ( V_69 >> V_73 ) - V_74 ) -
V_73 ;
V_70 |= V_75 ;
if ( V_68 )
return - V_70 * pow ( 2 , V_69 ) ;
else
return V_70 * pow ( 2 , V_69 ) ;
}
static int
F_67 ( const T_14 V_66 )
{
return ( ( V_66 & ~ V_67 ) == 0 ) ;
}
static T_17
F_68 ( const T_14 V_66 )
{
T_15 V_68 ;
T_15 V_69 ;
T_15 V_70 ;
V_68 = V_66 & V_76 ;
V_69 = V_66 & V_77 ;
V_70 = V_66 & V_78 ;
if ( F_67 ( V_66 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_69 = ( ( V_69 >> V_79 ) - V_80 ) -
V_79 ;
V_70 |= V_81 ;
if ( V_68 )
return - V_70 * pow ( 2 , V_69 ) ;
else
return V_70 * pow ( 2 , V_69 ) ;
}
T_16
F_69 ( T_1 * V_3 , const int V_20 )
{
#if F_70 ( V_82 )
return F_66 ( F_51 ( V_3 , V_20 ) ) ;
#else
union {
T_16 V_83 ;
T_5 V_66 ;
} V_84 ;
V_84 . V_66 = F_51 ( V_3 , V_20 ) ;
return V_84 . V_83 ;
#endif
}
T_17
F_71 ( T_1 * V_3 , const int V_20 )
{
#if F_70 ( V_82 )
union {
T_5 V_66 [ 2 ] ;
T_14 V_85 ;
} V_84 ;
#else
union {
T_17 V_86 ;
T_5 V_66 [ 2 ] ;
} V_84 ;
#endif
#ifdef F_72
V_84 . V_66 [ 0 ] = F_51 ( V_3 , V_20 ) ;
V_84 . V_66 [ 1 ] = F_51 ( V_3 , V_20 + 4 ) ;
#else
V_84 . V_66 [ 0 ] = F_51 ( V_3 , V_20 + 4 ) ;
V_84 . V_66 [ 1 ] = F_51 ( V_3 , V_20 ) ;
#endif
#if F_70 ( V_82 )
return F_68 ( V_84 . V_85 ) ;
#else
return V_84 . V_86 ;
#endif
}
T_13
F_73 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_13 ) ) ;
return F_74 ( V_64 ) ;
}
T_5
F_75 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 3 ) ;
return F_76 ( V_64 ) ;
}
T_5
F_77 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_5 ) ) ;
return F_78 ( V_64 ) ;
}
T_14
F_79 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 5 ) ;
return F_80 ( V_64 ) ;
}
T_15
F_81 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_79 ( V_3 , V_20 ) , 40 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_82 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 6 ) ;
return F_83 ( V_64 ) ;
}
T_15
F_84 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_82 ( V_3 , V_20 ) , 48 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_85 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , 7 ) ;
return F_86 ( V_64 ) ;
}
T_15
F_87 ( T_1 * V_3 , const T_3 V_20 )
{
T_14 V_65 ;
V_65 = F_56 ( F_85 ( V_3 , V_20 ) , 56 ) ;
return ( T_15 ) V_65 ;
}
T_14
F_88 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_14 ) ) ;
return F_89 ( V_64 ) ;
}
T_16
F_90 ( T_1 * V_3 , const int V_20 )
{
#if F_70 ( V_82 )
return F_66 ( F_77 ( V_3 , V_20 ) ) ;
#else
union {
T_16 V_83 ;
T_5 V_66 ;
} V_84 ;
V_84 . V_66 = F_77 ( V_3 , V_20 ) ;
return V_84 . V_83 ;
#endif
}
T_17
F_91 ( T_1 * V_3 , const int V_20 )
{
#if F_70 ( V_82 )
union {
T_5 V_66 [ 2 ] ;
T_14 V_85 ;
} V_84 ;
#else
union {
T_17 V_86 ;
T_5 V_66 [ 2 ] ;
} V_84 ;
#endif
#ifdef F_72
V_84 . V_66 [ 0 ] = F_77 ( V_3 , V_20 + 4 ) ;
V_84 . V_66 [ 1 ] = F_77 ( V_3 , V_20 ) ;
#else
V_84 . V_66 [ 0 ] = F_77 ( V_3 , V_20 ) ;
V_84 . V_66 [ 1 ] = F_77 ( V_3 , V_20 + 4 ) ;
#endif
#if F_70 ( V_82 )
return F_68 ( V_84 . V_85 ) ;
#else
return V_84 . V_86 ;
#endif
}
static inline void
F_92 ( const T_4 V_87 )
{
const T_4 V_88 = V_87 & ~ V_89 ;
switch ( V_88 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
F_93 ( L_1 ) ;
break;
default:
break;
}
if ( V_88 == 0 )
F_93 ( L_2 ) ;
}
T_18 *
F_94 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_9 ,
const T_4 V_87 , T_18 * V_95 , T_3 * V_96 )
{
const T_11 * V_64 = ( T_11 * ) F_95 ( F_96 () , V_3 , V_20 , V_9 ) ;
const T_11 * V_97 = V_64 ;
const T_11 * V_98 = NULL ;
T_18 * V_99 = NULL ;
V_100 = V_101 ;
F_92 ( V_87 ) ;
if ( V_96 ) * V_96 = 0 ;
while ( * V_97 == ' ' ) V_97 ++ ;
if ( * V_97 && V_95 ) {
if ( F_97 ( V_97 , V_95 , & V_98 , V_87 , FALSE ) ) {
if ( V_95 -> V_43 > 0 ) {
if ( V_96 ) * V_96 = V_20 + ( T_3 ) ( V_98 - V_64 ) ;
V_100 = 0 ;
V_99 = V_95 ;
}
}
}
return V_99 ;
}
T_19 *
F_98 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_9 ,
const T_4 V_87 , T_19 * V_102 , T_3 * V_96 )
{
const T_11 * V_97 = ( T_11 * ) F_95 ( F_96 () , V_3 , V_20 , V_9 ) ;
const T_11 * V_64 = V_97 ;
const T_11 * V_98 = NULL ;
struct V_103 V_103 ;
T_19 * V_99 = NULL ;
char V_68 = '+' ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
T_8 V_107 = FALSE ;
V_100 = V_101 ;
F_92 ( V_87 ) ;
F_5 ( V_102 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_108 = - 1 ;
V_102 -> V_109 = 0 ;
V_102 -> V_110 = 0 ;
while ( * V_64 == ' ' ) V_64 ++ ;
if ( * V_64 ) {
if ( ( V_87 & V_111 ) == V_111 ) {
if ( sscanf ( V_64 , L_3 ,
& V_103 . V_112 ,
& V_103 . V_113 ,
& V_103 . V_114 ,
& V_103 . V_115 ,
& V_103 . V_116 ,
& V_103 . V_117 ,
& V_68 ,
& V_104 ,
& V_105 ,
& V_106 ) >= 9 )
{
V_107 = TRUE ;
}
else if ( sscanf ( V_64 , L_4 ,
& V_103 . V_112 ,
& V_103 . V_113 ,
& V_103 . V_114 ,
& V_103 . V_115 ,
& V_103 . V_116 ,
& V_68 ,
& V_104 ,
& V_105 ,
& V_106 ) >= 8 )
{
V_107 = TRUE ;
}
else if ( sscanf ( V_64 , L_5 ,
& V_103 . V_112 ,
& V_103 . V_113 ,
& V_103 . V_114 ,
& V_103 . V_115 ,
& V_103 . V_116 ,
& V_103 . V_117 ,
& V_106 ) >= 6 )
{
V_107 = TRUE ;
V_104 = 0 ;
V_105 = 0 ;
}
else if ( sscanf ( V_64 , L_6 ,
& V_103 . V_112 ,
& V_103 . V_113 ,
& V_103 . V_114 ,
& V_103 . V_115 ,
& V_103 . V_116 ,
& V_106 ) >= 5 )
{
V_107 = TRUE ;
V_104 = 0 ;
V_105 = 0 ;
}
if ( V_107 ) {
V_100 = 0 ;
V_98 = V_64 + V_106 ;
V_103 . V_113 -- ;
if ( V_103 . V_112 > 1900 ) V_103 . V_112 -= 1900 ;
if ( V_68 == '-' ) V_104 = - V_104 ;
}
}
else if ( V_87 & V_118 ) {
if ( sscanf ( V_64 , L_7 ,
& V_103 . V_112 ,
& V_103 . V_113 ,
& V_103 . V_114 ,
& V_106 ) >= 3 )
{
V_100 = 0 ;
V_98 = V_64 + V_106 ;
V_103 . V_113 -- ;
if ( V_103 . V_112 > 1900 ) V_103 . V_112 -= 1900 ;
}
}
else if ( V_87 & V_119 ) {
if ( sscanf ( V_64 , L_8 ,
& V_103 . V_115 ,
& V_103 . V_116 ,
& V_103 . V_117 ,
& V_106 ) >= 2 )
{
T_20 V_120 = time ( NULL ) ;
struct V_103 * V_121 = gmtime ( & V_120 ) ;
V_103 . V_112 = V_121 -> V_112 ;
V_103 . V_113 = V_121 -> V_113 ;
V_103 . V_114 = V_121 -> V_114 ;
V_98 = V_64 + V_106 ;
V_100 = 0 ;
}
}
else if ( V_87 & V_122 || V_87 & V_123 ) {
if ( V_87 & V_122 ) {
V_98 = strptime ( V_64 , L_9 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_10 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_11 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_12 , & V_103 ) ;
}
else if ( V_87 & V_123 ) {
V_98 = strptime ( V_64 , L_13 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_14 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_15 , & V_103 ) ;
if ( ! V_98 ) V_98 = strptime ( V_64 , L_16 , & V_103 ) ;
}
if ( V_98 ) {
V_100 = 0 ;
if ( * V_98 == ' ' ) V_98 ++ ;
if ( F_99 ( V_98 , L_17 , 2 ) == 0 )
{
V_98 += 2 ;
}
else if ( F_99 ( V_98 , L_18 , 3 ) == 0 )
{
V_98 += 3 ;
}
else if ( sscanf ( V_98 , L_19 ,
& V_68 ,
& V_104 ,
& V_105 ,
& V_106 ) < 3 )
{
V_100 = V_124 ;
}
if ( V_68 == '-' ) V_104 = - V_104 ;
}
}
}
if ( V_100 == 0 ) {
V_102 -> V_109 = F_100 ( & V_103 ) ;
if ( V_104 > 0 )
V_102 -> V_109 += ( V_104 * 3600 ) + ( V_105 * 60 ) ;
else if ( V_104 < 0 )
V_102 -> V_109 -= ( ( - V_104 ) * 3600 ) + ( V_105 * 60 ) ;
V_99 = V_102 ;
if ( V_96 )
* V_96 = ( T_3 ) ( V_20 + ( V_98 - V_97 ) ) ;
}
return V_99 ;
}
T_5
F_101 ( T_1 * V_3 , const T_3 V_20 )
{
const T_7 * V_64 ;
T_5 V_125 ;
V_64 = F_42 ( V_3 , V_20 , sizeof( T_5 ) ) ;
memcpy ( & V_125 , V_64 , sizeof V_125 ) ;
return V_125 ;
}
void
F_102 ( T_1 * V_3 , const T_3 V_20 , struct V_126 * V_125 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , sizeof( * V_125 ) ) ;
memcpy ( V_125 , V_64 , sizeof *V_125 ) ;
}
void
F_103 ( T_1 * V_3 , const T_3 V_20 , T_21 * V_127 )
{
const T_7 * V_64 = F_20 ( V_3 , V_20 , V_128 ) ;
V_127 -> V_129 = F_52 ( V_64 + 0 ) ;
V_127 -> V_130 = F_48 ( V_64 + 4 ) ;
V_127 -> V_131 = F_48 ( V_64 + 6 ) ;
memcpy ( V_127 -> V_132 , V_64 + 8 , sizeof V_127 -> V_132 ) ;
}
void
F_104 ( T_1 * V_3 , const T_3 V_20 , T_21 * V_127 )
{
const T_7 * V_64 = F_20 ( V_3 , V_20 , V_128 ) ;
V_127 -> V_129 = F_78 ( V_64 + 0 ) ;
V_127 -> V_130 = F_74 ( V_64 + 4 ) ;
V_127 -> V_131 = F_74 ( V_64 + 6 ) ;
memcpy ( V_127 -> V_132 , V_64 + 8 , sizeof V_127 -> V_132 ) ;
}
void
F_105 ( T_1 * V_3 , const T_3 V_20 , T_21 * V_127 , const T_4 V_133 )
{
if ( V_133 ) {
F_104 ( V_3 , V_20 , V_127 ) ;
} else {
F_103 ( V_3 , V_20 , V_127 ) ;
}
}
T_7
F_106 ( T_1 * V_3 , T_4 V_30 , const T_3 V_31 )
{
return ( T_7 ) F_107 ( V_3 , V_30 , V_31 ) ;
}
T_13
F_108 ( T_1 * V_3 , T_4 V_30 , const T_3 V_31 , const T_4 V_87 V_134 )
{
return ( T_13 ) F_107 ( V_3 , V_30 , V_31 ) ;
}
T_5
F_109 ( T_1 * V_3 , T_4 V_30 , const T_3 V_31 , const T_4 V_87 V_134 )
{
return ( T_5 ) F_107 ( V_3 , V_30 , V_31 ) ;
}
T_14
F_110 ( T_1 * V_3 , T_4 V_30 , const T_3 V_31 , const T_4 V_87 V_134 )
{
return F_107 ( V_3 , V_30 , V_31 ) ;
}
static T_14
F_107 ( T_1 * V_3 , T_4 V_30 , const T_3 V_135 )
{
T_14 V_136 ;
T_4 V_137 = V_30 >> 3 ;
T_7 V_138 = 8 - ( V_30 % 8 ) ;
if( V_138 > V_135 )
{
T_7 V_139 = V_138 - V_135 ;
V_136 = ( F_46 ( V_3 , V_137 ) >> V_139 ) & V_140 [ V_135 % 8 ] ;
}
else
{
T_7 V_141 = V_135 ;
V_136 = 0 ;
V_138 %= 8 ;
if( V_138 != 0 )
{
V_136 = F_46 ( V_3 , V_137 ) & V_140 [ V_138 ] ;
V_141 -= V_138 ;
V_137 ++ ;
}
while ( V_141 > 7 )
{
switch ( V_141 >> 4 )
{
case 0 :
V_136 <<= 8 ;
V_136 += F_46 ( V_3 , V_137 ) ;
V_141 -= 8 ;
V_137 ++ ;
break;
case 1 :
V_136 <<= 16 ;
V_136 += F_47 ( V_3 , V_137 ) ;
V_141 -= 16 ;
V_137 += 2 ;
break;
case 2 :
case 3 :
V_136 <<= 32 ;
V_136 += F_51 ( V_3 , V_137 ) ;
V_141 -= 32 ;
V_137 += 4 ;
break;
default:
V_136 = F_63 ( V_3 , V_137 ) ;
V_141 -= 64 ;
V_137 += 8 ;
break;
}
}
if( V_141 )
{
V_136 <<= V_141 ;
V_136 += ( F_46 ( V_3 , V_137 ) >> ( 8 - V_141 ) ) ;
}
}
return V_136 ;
}
T_5
F_111 ( T_1 * V_3 , const T_4 V_30 , const T_3 V_31 , const T_4 V_87 V_134 )
{
return ( T_5 ) F_107 ( V_3 , V_30 , V_31 ) ;
}
static T_3
F_112 ( T_1 * V_3 , T_4 V_46 , T_4 V_142 , T_7 V_143 )
{
const T_7 * V_64 ;
const T_7 * V_144 ;
V_64 = F_20 ( V_3 , V_46 , V_142 ) ;
V_144 = ( const T_7 * ) memchr ( V_64 , V_143 , V_142 ) ;
if ( ! V_144 )
return - 1 ;
return ( T_3 ) ( ( V_144 - V_64 ) + V_46 ) ;
}
T_3
F_113 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_145 , const T_7 V_143 )
{
const T_7 * V_144 ;
T_4 V_46 ;
T_4 V_146 ;
T_4 V_142 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_14 ( V_3 , V_20 , - 1 , & V_46 , & V_146 ) ;
if ( V_145 == - 1 ) {
V_142 = V_146 ;
}
else if ( V_146 < ( T_4 ) V_145 ) {
V_142 = V_146 ;
}
else {
V_142 = V_145 ;
}
if ( V_3 -> V_11 ) {
V_144 = ( const T_7 * ) memchr ( V_3 -> V_11 + V_46 , V_143 , V_142 ) ;
if ( V_144 == NULL ) {
return - 1 ;
}
else {
return ( T_3 ) ( V_144 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_113 )
return V_3 -> V_2 -> F_113 ( V_3 , V_46 , V_142 , V_143 ) ;
return F_112 ( V_3 , V_20 , V_142 , V_143 ) ;
}
static inline T_3
F_114 ( T_1 * V_3 , T_4 V_46 , T_4 V_142 , const T_7 * V_58 , T_10 * V_59 )
{
const T_7 * V_64 ;
const T_7 * V_144 ;
V_64 = F_20 ( V_3 , V_46 , V_142 ) ;
V_144 = F_43 ( V_64 , V_142 , V_58 , V_59 ) ;
if ( ! V_144 )
return - 1 ;
return ( T_3 ) ( ( V_144 - V_64 ) + V_46 ) ;
}
T_3
F_115 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_145 , const T_7 * V_58 , T_10 * V_59 )
{
const T_7 * V_144 ;
T_4 V_46 ;
T_4 V_146 ;
T_4 V_142 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_14 ( V_3 , V_20 , - 1 , & V_46 , & V_146 ) ;
if ( V_145 == - 1 ) {
V_142 = V_146 ;
}
else if ( V_146 < ( T_4 ) V_145 ) {
V_142 = V_146 ;
}
else {
V_142 = V_145 ;
}
if ( V_3 -> V_11 ) {
V_144 = F_43 ( V_3 -> V_11 + V_46 , V_142 , V_58 , V_59 ) ;
if ( V_144 == NULL ) {
return - 1 ;
}
else {
return ( T_3 ) ( V_144 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_115 )
return V_3 -> V_2 -> F_115 ( V_3 , V_46 , V_142 , V_58 , V_59 ) ;
return F_114 ( V_3 , V_46 , V_142 , V_58 , V_59 ) ;
}
T_4
F_116 ( T_1 * V_3 , const T_3 V_20 )
{
T_4 V_46 , V_147 ;
T_3 V_148 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_14 ( V_3 , V_20 , 0 , & V_46 , & V_147 ) ;
V_148 = F_113 ( V_3 , V_46 , - 1 , 0 ) ;
if ( V_148 == - 1 ) {
if ( V_3 -> V_9 < V_3 -> V_10 ) {
F_15 ( V_26 ) ;
} else {
if ( V_3 -> V_8 & V_27 ) {
F_15 ( V_28 ) ;
} else {
F_15 ( V_29 ) ;
}
}
}
return ( V_148 - V_46 ) + 1 ;
}
T_4
F_117 ( T_1 * V_3 , const T_3 V_20 )
{
T_4 V_35 = 0 ;
T_22 V_149 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
do {
V_149 = F_47 ( V_3 , V_20 + V_35 ) ;
V_35 += 2 ;
} while( V_149 != 0 );
return V_35 ;
}
T_3
F_118 ( T_1 * V_3 , const T_3 V_20 , const T_4 V_145 )
{
T_3 V_150 ;
T_4 V_46 , V_147 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_14 ( V_3 , V_20 , 0 , & V_46 , & V_147 ) ;
V_150 = F_113 ( V_3 , V_46 , V_145 , 0 ) ;
if ( V_150 == - 1 ) {
return - 1 ;
}
else {
return V_150 - V_46 ;
}
}
T_3
F_119 ( T_1 * V_3 , const T_3 V_20 , const T_11 * V_151 , const T_9 V_4 )
{
const T_7 * V_64 ;
V_64 = F_41 ( V_3 , V_20 , ( T_3 ) V_4 , NULL ) ;
if ( V_64 ) {
int V_152 = strncmp ( ( const char * ) V_64 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_3
F_120 ( T_1 * V_3 , const T_3 V_20 , const T_11 * V_151 , const T_9 V_4 )
{
const T_7 * V_64 ;
V_64 = F_41 ( V_3 , V_20 , ( T_3 ) V_4 , NULL ) ;
if ( V_64 ) {
int V_152 = F_99 ( ( const char * ) V_64 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_3
F_121 ( T_1 * V_3 , const T_3 V_20 , const T_7 * V_151 , T_9 V_4 )
{
const T_7 * V_64 ;
V_64 = F_41 ( V_3 , V_20 , ( T_3 ) V_4 , NULL ) ;
if ( V_64 ) {
int V_152 = memcmp ( V_64 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_11 *
F_122 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_4 )
{
const T_7 * V_64 ;
T_3 V_43 ;
V_43 = ( V_4 > 0 ) ? V_4 : 0 ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
return F_123 ( V_64 , V_43 ) ;
}
T_11 *
F_124 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_4 )
{
const T_7 * V_64 ;
T_3 V_43 ;
V_43 = ( V_4 > 0 ) ? V_4 : 0 ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
return F_125 ( V_64 , V_43 ) ;
}
T_11 *
F_126 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_4 )
{
const T_7 * V_64 , * V_54 ;
T_3 V_43 ;
T_3 V_153 ;
V_43 = ( V_4 > 0 ) ? V_4 : 0 ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
for ( V_54 = V_64 , V_153 = 0 ; V_153 < V_43 && * V_54 != '\0' ; V_54 ++ , V_153 ++ )
;
return F_123 ( V_64 , V_153 ) ;
}
T_11 *
F_127 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_4 )
{
const T_7 * V_64 , * V_54 ;
T_3 V_43 ;
T_3 V_153 ;
V_43 = ( V_4 > 0 ) ? V_4 : 0 ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
for ( V_54 = V_64 , V_153 = 0 ; V_153 < V_43 && * V_54 != '\0' ; V_54 ++ , V_153 ++ )
;
return F_125 ( V_64 , V_153 ) ;
}
static T_7 *
F_128 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 V_9 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_129 ( V_62 , V_64 , V_9 ) ;
}
static T_7 *
F_130 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
T_7 * V_154 ;
F_33 ( V_3 , V_20 , V_9 ) ;
V_154 = ( T_7 * ) F_45 ( V_62 , V_9 + 1 ) ;
F_25 ( V_3 , V_154 , V_20 , V_9 ) ;
V_154 [ V_9 ] = '\0' ;
return V_154 ;
}
static inline T_7 *
F_95 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , const T_3 V_9 )
{
T_7 * V_154 ;
T_3 V_48 = V_9 ;
F_5 ( V_20 >= 0 ) ;
F_5 ( V_48 >= - 1 ) ;
if ( V_48 < 0 )
V_48 = V_3 -> V_9 - V_20 ;
F_33 ( V_3 , V_20 , V_48 ) ;
V_154 = ( T_7 * ) F_45 ( V_62 , V_48 + 1 ) ;
F_25 ( V_3 , V_154 , V_20 , V_48 ) ;
V_154 [ V_48 ] = '\0' ;
return V_154 ;
}
static T_7 *
F_131 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 V_9 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_132 ( V_62 , V_64 , V_9 ) ;
}
static T_7 *
F_133 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 V_9 , const T_22 V_155 [ 0x80 ] )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_134 ( V_62 , V_64 , V_9 , V_155 ) ;
}
static T_7 *
F_135 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 V_9 , const T_4 V_87 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_136 ( V_62 , V_64 , V_9 , V_87 ) ;
}
static T_7 *
F_137 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 V_9 , const T_4 V_87 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_138 ( V_62 , V_64 , V_9 , V_87 ) ;
}
static T_11 *
F_139 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 V_9 , const T_4 V_87 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_140 ( V_62 , V_64 , V_9 , V_87 ) ;
}
T_11 *
F_141 ( T_12 * V_62 , T_1 * V_3 ,
const T_3 V_30 , T_3 V_156 )
{
T_3 V_157 = V_30 >> 3 ;
T_3 V_9 = ( ( V_156 + 1 ) * 7 + ( V_30 & 0x07 ) ) >> 3 ;
const T_7 * V_64 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_64 = F_20 ( V_3 , V_157 , V_9 ) ;
return F_142 ( V_62 , V_64 , V_30 , V_156 ) ;
}
T_11 *
F_143 ( T_12 * V_62 , T_1 * V_3 ,
const T_3 V_30 , T_3 V_156 )
{
T_3 V_157 = V_30 >> 3 ;
T_3 V_9 = ( ( V_156 + 1 ) * 7 + ( V_30 & 0x07 ) ) >> 3 ;
const T_7 * V_64 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_64 = F_20 ( V_3 , V_157 , V_9 ) ;
return F_144 ( V_62 , V_64 , V_30 , V_156 ) ;
}
static T_7 *
F_145 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 V_9 )
{
const T_7 * V_64 ;
V_64 = F_20 ( V_3 , V_20 , V_9 ) ;
return F_146 ( V_62 , V_64 , V_9 ) ;
}
T_7 *
F_147 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 ,
const T_3 V_9 , const T_4 V_87 )
{
T_7 * V_158 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_15 ( V_29 ) ;
}
switch ( V_87 & V_159 ) {
case V_160 :
default:
V_158 = F_128 ( V_62 , V_3 , V_20 , V_9 ) ;
break;
case V_161 :
V_158 = F_130 ( V_62 , V_3 , V_20 , V_9 ) ;
break;
case V_90 :
V_158 = F_137 ( V_62 , V_3 , V_20 , V_9 ,
V_87 & V_162 ) ;
break;
case V_91 :
V_158 = F_135 ( V_62 , V_3 , V_20 , V_9 ,
V_87 & V_162 ) ;
break;
case V_92 :
V_158 = F_139 ( V_62 , V_3 , V_20 , V_9 ,
V_87 & V_162 ) ;
break;
case V_163 :
V_158 = F_131 ( V_62 , V_3 , V_20 , V_9 ) ;
break;
case V_164 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_165 ) ;
break;
case V_166 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_167 ) ;
break;
case V_168 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_169 ) ;
break;
case V_170 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_171 ) ;
break;
case V_172 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_173 ) ;
break;
case V_174 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_175 ) ;
break;
case V_176 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_177 ) ;
break;
case V_178 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_179 ) ;
break;
case V_180 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_181 ) ;
break;
case V_182 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_183 ) ;
break;
case V_184 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_185 ) ;
break;
case V_186 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_187 ) ;
break;
case V_188 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_189 ) ;
break;
case V_190 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_191 ) ;
break;
case V_192 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_193 ) ;
break;
case V_194 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_195 ) ;
break;
case V_196 :
V_158 = F_133 ( V_62 , V_3 , V_20 , V_9 , V_197 ) ;
break;
case V_93 :
{
T_3 V_30 = V_20 << 3 ;
T_3 V_156 = ( V_9 << 3 ) / 7 ;
V_158 = F_141 ( V_62 , V_3 , V_30 , V_156 ) ;
}
break;
case V_198 :
{
T_3 V_30 = V_20 << 3 ;
T_3 V_156 = ( V_9 << 3 ) / 7 ;
V_158 = F_143 ( V_62 , V_3 , V_30 , V_156 ) ;
}
break;
case V_94 :
V_158 = F_145 ( V_62 , V_3 , V_20 , V_9 ) ;
break;
}
return V_158 ;
}
T_7 *
F_148 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 ,
const T_3 V_9 , const T_4 V_87 )
{
return F_147 ( V_62 , V_3 , V_20 , V_9 , V_87 ) ;
}
static T_7 *
F_149 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 * V_199 )
{
T_4 V_4 ;
const T_7 * V_64 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_129 ( V_62 , V_64 , V_4 ) ;
}
static T_7 *
F_150 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 * V_199 )
{
T_4 V_4 ;
T_7 * V_158 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_158 = ( T_7 * ) F_45 ( V_62 , V_4 ) ;
F_25 ( V_3 , V_158 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return V_158 ;
}
static T_7 *
F_151 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 * V_199 )
{
T_4 V_4 ;
const T_7 * V_64 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_132 ( V_62 , V_64 , V_4 ) ;
}
static T_7 *
F_152 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 * V_199 , const T_22 V_155 [ 0x80 ] )
{
T_4 V_4 ;
const T_7 * V_64 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_134 ( V_62 , V_64 , V_4 , V_155 ) ;
}
const T_7 *
F_153 ( T_1 * V_3 , const T_3 V_20 , T_3 * V_199 )
{
T_4 V_4 ;
const T_7 * V_158 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_158 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return V_158 ;
}
static T_11 *
F_154 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 * V_199 , const T_4 V_87 )
{
T_3 V_4 ;
const T_7 * V_64 ;
V_4 = F_117 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_136 ( V_62 , V_64 , V_4 , V_87 ) ;
}
static T_11 *
F_155 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 * V_199 , const T_4 V_87 )
{
T_3 V_4 ;
const T_7 * V_64 ;
V_4 = F_117 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_138 ( V_62 , V_64 , V_4 , V_87 ) ;
}
static T_11 *
F_156 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 * V_199 , const T_4 V_87 )
{
T_3 V_4 ;
T_23 V_149 ;
const T_7 * V_64 ;
V_4 = 0 ;
do {
V_149 = F_51 ( V_3 , V_20 + V_4 ) ;
V_4 += 4 ;
} while( V_149 != 0 );
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_140 ( V_62 , V_64 , V_4 , V_87 ) ;
}
static T_7 *
F_157 ( T_12 * V_62 , T_1 * V_3 , T_3 V_20 , T_3 * V_199 )
{
T_4 V_4 ;
const T_7 * V_64 ;
V_4 = F_116 ( V_3 , V_20 ) ;
V_64 = F_20 ( V_3 , V_20 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_146 ( V_62 , V_64 , V_4 ) ;
}
T_7 *
F_158 ( T_12 * V_62 , T_1 * V_3 , const T_3 V_20 , T_3 * V_199 , const T_4 V_87 )
{
T_7 * V_158 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
switch ( V_87 & V_159 ) {
case V_160 :
default:
V_158 = F_149 ( V_62 , V_3 , V_20 , V_199 ) ;
break;
case V_161 :
V_158 = F_150 ( V_62 , V_3 , V_20 , V_199 ) ;
break;
case V_90 :
V_158 = F_155 ( V_62 , V_3 , V_20 , V_199 ,
V_87 & V_162 ) ;
break;
case V_91 :
V_158 = F_154 ( V_62 , V_3 , V_20 , V_199 ,
V_87 & V_162 ) ;
break;
case V_92 :
V_158 = F_156 ( V_62 , V_3 , V_20 , V_199 ,
V_87 & V_162 ) ;
break;
case V_163 :
V_158 = F_151 ( V_62 , V_3 , V_20 , V_199 ) ;
break;
case V_164 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_165 ) ;
break;
case V_166 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_167 ) ;
break;
case V_168 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_169 ) ;
break;
case V_170 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_171 ) ;
break;
case V_172 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_173 ) ;
break;
case V_174 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_175 ) ;
break;
case V_176 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_177 ) ;
break;
case V_178 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_179 ) ;
break;
case V_180 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_181 ) ;
break;
case V_182 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_183 ) ;
break;
case V_184 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_185 ) ;
break;
case V_186 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_187 ) ;
break;
case V_188 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_189 ) ;
break;
case V_190 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_191 ) ;
break;
case V_192 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_193 ) ;
break;
case V_194 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_195 ) ;
break;
case V_196 :
V_158 = F_152 ( V_62 , V_3 , V_20 , V_199 , V_197 ) ;
break;
case V_93 :
F_93 ( L_20 ) ;
break;
case V_198 :
F_93 ( L_21 ) ;
break;
case V_94 :
V_158 = F_157 ( V_62 , V_3 , V_20 , V_199 ) ;
break;
}
return V_158 ;
}
static T_3
F_159 ( T_1 * V_3 , const T_3 V_20 , const T_4 V_200 , T_7 * V_201 , T_3 * V_202 )
{
T_3 V_153 ;
T_4 V_46 ;
T_3 V_142 , V_43 ;
T_8 V_203 = FALSE ;
F_14 ( V_3 , V_20 , - 1 , & V_46 , & V_43 ) ;
F_5 ( V_200 != 0 ) ;
if ( V_200 == 1 ) {
V_201 [ 0 ] = 0 ;
* V_202 = 1 ;
return 0 ;
}
if ( V_43 == 0 ) {
F_15 ( V_29 ) ;
}
F_5 ( V_43 != - 1 ) ;
F_5 ( V_200 <= V_204 ) ;
if ( ( T_4 ) V_43 < V_200 ) {
V_142 = V_43 ;
V_203 = TRUE ;
}
else {
V_142 = V_200 ;
}
V_153 = F_118 ( V_3 , V_46 , V_142 - 1 ) ;
if ( V_153 == - 1 ) {
F_25 ( V_3 , V_201 , V_46 , V_142 ) ;
if ( V_203 ) {
V_201 [ V_142 ] = 0 ;
* V_202 = V_142 + 1 ;
}
else {
* V_202 = V_142 ;
}
return - 1 ;
}
F_25 ( V_3 , V_201 , V_46 , V_153 + 1 ) ;
* V_202 = V_153 + 1 ;
return V_153 ;
}
T_3
F_160 ( T_1 * V_3 , const T_3 V_20 , const T_4 V_200 , T_7 * V_201 )
{
T_3 V_202 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
return F_159 ( V_3 , V_20 , V_200 , V_201 , & V_202 ) ;
}
T_3
F_161 ( T_1 * V_3 , const T_3 V_20 , const T_4 V_200 , T_7 * V_201 )
{
T_3 V_43 , V_202 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_43 = F_159 ( V_3 , V_20 , V_200 , V_201 , & V_202 ) ;
if ( V_43 == - 1 ) {
V_201 [ V_200 - 1 ] = 0 ;
return V_202 - 1 ;
}
else {
return V_43 ;
}
}
T_3
F_162 ( T_1 * V_3 , const T_3 V_20 , int V_43 , T_3 * V_205 , const T_8 V_206 )
{
T_3 V_207 ;
T_3 V_208 ;
int V_209 ;
T_10 V_59 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_43 == - 1 )
V_43 = F_18 ( V_3 , V_20 ) ;
V_207 = V_20 + V_43 ;
V_208 = F_115 ( V_3 , V_20 , V_43 , L_22 , & V_59 ) ;
if ( V_208 == - 1 ) {
if ( V_206 ) {
return - 1 ;
} else {
V_209 = V_207 - V_20 ;
if ( V_205 )
* V_205 = V_207 ;
}
} else {
V_209 = V_208 - V_20 ;
if ( V_59 == '\r' ) {
if ( V_208 + 1 >= V_207 ) {
if ( V_206 ) {
return - 1 ;
}
} else {
if ( F_46 ( V_3 , V_208 + 1 ) == '\n' ) {
V_208 ++ ;
}
}
}
if ( V_205 )
* V_205 = V_208 + 1 ;
}
return V_209 ;
}
T_3
F_163 ( T_1 * V_3 , const T_3 V_20 , int V_43 , T_3 * V_205 )
{
T_3 V_210 , V_211 ;
T_8 V_212 ;
T_10 V_213 = 0 ;
T_3 V_207 ;
int V_209 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_43 == - 1 )
V_43 = F_18 ( V_3 , V_20 ) ;
V_207 = V_20 + V_43 ;
V_210 = V_20 ;
V_212 = FALSE ;
for (; ; ) {
if ( V_212 ) {
V_211 = F_113 ( V_3 , V_210 , V_43 ,
'"' ) ;
} else {
V_211 = F_115 ( V_3 , V_210 , V_43 , L_23 , & V_213 ) ;
}
if ( V_211 == - 1 ) {
V_209 = V_207 - V_20 ;
if ( V_205 )
* V_205 = V_207 ;
break;
}
if ( V_212 ) {
V_212 = FALSE ;
} else {
if ( V_213 == '"' ) {
V_212 = TRUE ;
} else {
V_209 = V_211 - V_20 ;
if ( V_213 == '\r' ) {
if ( V_211 + 1 < V_207 &&
F_46 ( V_3 , V_211 + 1 )
== '\n' ) {
V_211 ++ ;
}
}
if ( V_205 )
* V_205 = V_211 + 1 ;
break;
}
}
V_210 = V_211 + 1 ;
if ( V_210 >= V_207 ) {
V_209 = V_207 - V_20 ;
if ( V_205 )
* V_205 = V_207 ;
break;
}
}
return V_209 ;
}
T_3
F_164 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_145 )
{
T_3 V_50 = V_20 ;
T_3 V_98 , V_214 ;
T_7 V_215 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_214 = V_3 -> V_9 ;
V_98 = V_20 + V_145 ;
if ( V_98 >= V_214 )
{
V_98 = V_214 ;
}
for ( V_50 = V_20 ;
V_50 < V_98 &&
( ( V_215 = F_46 ( V_3 , V_50 ) ) == ' ' ||
V_215 == '\t' || V_215 == '\r' || V_215 == '\n' ) ;
V_50 ++ ) ;
return ( V_50 ) ;
}
T_3
F_165 ( T_1 * V_3 , const T_3 V_20 ) {
T_3 V_50 = V_20 ;
T_7 V_215 ;
for( V_50 = V_20 ; V_50 > 0 &&
( ( V_215 = F_46 ( V_3 , V_50 ) ) == ' ' ||
V_215 == '\t' || V_215 == '\n' || V_215 == '\r' ) ; V_50 -- ) ;
V_50 ++ ;
return ( V_50 ) ;
}
int
F_166 ( T_1 * V_3 , int V_20 , const int V_145 , const T_7 V_216 )
{
int V_98 , V_214 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_214 = V_3 -> V_9 ;
V_98 = V_20 + V_145 ;
if ( V_98 >= V_214 )
V_98 = V_214 ;
while ( V_20 < V_98 ) {
T_7 V_217 = F_46 ( V_3 , V_20 ) ;
if ( V_217 != V_216 )
break;
V_20 ++ ;
}
return V_20 ;
}
T_11 *
F_167 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_43 , const T_11 V_218 )
{
return F_168 ( F_20 ( V_3 , V_20 , V_43 ) , V_43 , V_218 ) ;
}
const T_11 *
F_169 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_43 , T_24 * V_219 , T_8 V_220 )
{
int V_9 ;
T_7 V_221 ;
int V_35 = 0 ;
char * V_222 ;
T_3 V_223 = V_20 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( ! V_219 )
V_219 = & V_224 ;
if ( V_43 == - 1 ) {
V_9 = V_3 -> V_9 ;
if ( V_9 < V_20 ) {
return L_24 ;
}
} else {
V_9 = V_20 + V_43 ;
}
V_222 = ( char * ) F_45 ( F_96 () , ( V_9 - V_20 ) * 2 + 1 ) ;
while ( V_223 < V_9 ) {
V_221 = F_46 ( V_3 , V_223 ) ;
if ( ! V_220 ) {
V_222 [ V_35 ] = V_219 -> V_225 [ V_221 & 0x0f ] ;
V_35 ++ ;
}
V_220 = FALSE ;
V_221 = V_221 >> 4 ;
if ( V_221 == 0x0f )
break;
V_222 [ V_35 ] = V_219 -> V_225 [ V_221 & 0x0f ] ;
V_35 ++ ;
V_223 ++ ;
}
V_222 [ V_35 ] = '\0' ;
return V_222 ;
}
T_11 *
F_170 ( T_1 * V_3 , const T_3 V_20 , const T_3 V_43 )
{
return F_171 ( F_20 ( V_3 , V_20 , V_43 ) , V_43 ) ;
}
T_3
F_172 ( T_1 * V_226 , T_1 * V_227 , const T_3 V_228 )
{
T_4 V_229 , V_230 ;
const T_7 * V_231 ;
const T_7 * V_232 ;
const T_4 V_233 = V_227 -> V_9 ;
const T_7 * V_234 ;
F_5 ( V_226 && V_226 -> V_7 ) ;
if ( V_226 -> V_9 < 1 || V_227 -> V_9 < 1 ) {
return - 1 ;
}
V_231 = F_20 ( V_226 , 0 , - 1 ) ;
V_232 = F_20 ( V_227 , 0 , - 1 ) ;
F_14 ( V_226 , V_228 , - 1 ,
& V_229 , & V_230 ) ;
V_234 = F_173 ( V_231 + V_229 , V_230 ,
V_232 , V_233 ) ;
if ( V_234 ) {
return ( T_3 ) ( V_234 - V_231 ) ;
}
return - 1 ;
}
T_3
F_174 ( T_1 * V_3 )
{
return ( ( V_3 -> V_12 == - 1 ) ? ( V_3 -> V_12 = F_40 ( V_3 ) ) : V_3 -> V_12 ) ;
}
void
F_175 ( T_1 * V_3 )
{
V_3 -> V_8 |= V_27 ;
}
struct V_235 *
F_176 ( T_1 * V_3 )
{
return ( V_3 -> V_13 ) ;
}
