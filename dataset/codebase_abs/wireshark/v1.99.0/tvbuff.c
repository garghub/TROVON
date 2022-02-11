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
static inline int
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
static inline int
F_14 ( const T_1 * V_3 , const T_4 V_25 , T_3 * V_26 , T_3 * V_27 )
{
int V_28 ;
V_28 = F_13 ( V_3 , V_25 , V_26 ) ;
if ( ! V_28 )
* V_27 = V_3 -> V_9 - * V_26 ;
return V_28 ;
}
static inline int
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
static inline void
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
F_5 ( V_3 && V_3 -> V_7 ) ;
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
T_7 * V_42 ;
F_5 ( F_27 ( V_3 , V_25 , V_45 ) ) ;
V_42 = ( T_7 * ) F_23 ( V_45 ) ;
F_28 ( V_3 , V_42 , V_25 , V_45 ) ;
V_46 = F_29 ( V_42 , V_45 , V_45 ) ;
F_25 ( V_46 , V_44 ) ;
return V_46 ;
}
T_1 *
F_30 ( T_1 * V_3 , T_3 V_25 , T_3 V_45 )
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
return F_30 ( V_3 , 0 , V_3 -> V_9 ) ;
}
T_3
F_31 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_9 ;
}
static inline T_4
F_20 ( const T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_48 ;
int V_28 ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_48 ) ;
if ( V_28 )
return 0 ;
return V_48 ;
}
T_4
F_32 ( const T_1 * V_3 , const T_4 V_25 )
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
F_33 ( const T_1 * V_3 , const T_4 V_25 )
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
F_27 ( const T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
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
F_34 ( const T_1 * V_3 , const T_4 V_25 , const T_9 V_9 )
{
if ( V_9 > V_50 ) {
F_17 ( V_24 ) ;
}
F_35 ( V_3 , V_25 , ( T_4 ) V_9 ) ;
}
void
F_35 ( const T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_3 V_51 , V_31 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_17 ( V_24 ) ;
}
if ( V_25 >= 0 ) {
if ( ( T_3 ) V_25 <= V_3 -> V_9 ) {
V_51 = V_25 ;
} else if ( ( T_3 ) V_25 <= V_3 -> V_10 ) {
F_17 ( V_21 ) ;
} else if ( V_3 -> V_8 & V_22 ) {
F_17 ( V_23 ) ;
} else {
F_17 ( V_24 ) ;
}
}
else {
if ( ( T_3 ) - V_25 <= V_3 -> V_9 ) {
V_51 = V_3 -> V_9 + V_25 ;
} else if ( ( T_3 ) - V_25 <= V_3 -> V_10 ) {
F_17 ( V_21 ) ;
} else if ( V_3 -> V_8 & V_22 ) {
F_17 ( V_23 ) ;
} else {
F_17 ( V_24 ) ;
}
}
V_31 = V_51 + V_9 ;
if ( V_31 < V_51 )
F_17 ( V_21 ) ;
if ( F_12 ( V_31 <= V_3 -> V_9 ) )
return;
else if ( V_31 <= V_3 -> V_10 )
F_17 ( V_21 ) ;
else if ( V_3 -> V_8 & V_22 )
F_17 ( V_23 ) ;
else
F_17 ( V_24 ) ;
}
T_8
F_36 ( const T_1 * V_3 , const T_4 V_25 )
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
T_3
F_37 ( const T_1 * V_3 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
return V_3 -> V_10 ;
}
T_4
F_38 ( const T_1 * V_3 , const T_4 V_25 )
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
F_39 ( T_1 * V_3 , const T_3 V_10 )
{
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_10 > V_3 -> V_10 )
F_17 ( V_24 ) ;
V_3 -> V_10 = V_10 ;
if ( V_10 < V_3 -> V_9 )
V_3 -> V_9 = V_10 ;
}
T_3
F_40 ( const T_1 * V_3 , const T_3 V_52 )
{
if ( V_3 -> V_2 -> V_53 )
return V_3 -> V_2 -> V_53 ( V_3 , V_52 ) ;
F_41 () ;
return 0 ;
}
T_3
F_42 ( const T_1 * V_3 )
{
return F_40 ( V_3 , 0 ) ;
}
static inline const T_7 *
F_43 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 , int * V_54 )
{
T_3 V_20 , V_49 ;
int V_28 ;
V_28 = F_15 ( V_3 , V_25 , V_9 , & V_20 , & V_49 ) ;
if ( V_28 ) {
if ( V_54 )
* V_54 = V_28 ;
return NULL ;
}
if ( V_3 -> V_11 )
return V_3 -> V_11 + V_20 ;
if ( V_3 -> V_2 -> V_55 )
return V_3 -> V_2 -> V_55 ( V_3 , V_20 , V_49 ) ;
F_41 () ;
return NULL ;
}
static inline const T_7 *
F_22 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
int V_28 = 0 ;
const T_7 * V_56 ;
V_56 = F_43 ( V_3 , V_25 , V_9 , & V_28 ) ;
if ( V_56 == NULL ) {
F_5 ( V_28 > 0 ) ;
F_17 ( V_28 ) ;
}
return V_56 ;
}
static inline const T_7 *
F_44 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_9 )
{
T_3 V_31 ;
T_3 V_57 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 8 ) ;
if ( V_25 < 0 || ! V_3 -> V_11 ) {
return F_22 ( V_3 , V_25 , V_9 ) ;
}
V_57 = V_25 ;
V_31 = V_57 + V_9 ;
if ( V_31 <= V_3 -> V_9 ) {
return V_3 -> V_11 + V_57 ;
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
static inline const T_7 *
F_45 ( const T_7 * V_58 , T_10 V_59 , const T_7 * V_60 , T_11 * V_61 )
{
const T_7 * V_62 = F_46 ( V_58 , V_59 , V_60 ) ;
if ( V_62 && V_61 )
* V_61 = * V_62 ;
return V_62 ;
}
void *
F_28 ( T_1 * V_3 , void * V_63 , const T_4 V_25 , T_10 V_9 )
{
T_3 V_20 , V_49 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 0x7FFFFFFF ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
if ( V_3 -> V_11 ) {
return memcpy ( V_63 , V_3 -> V_11 + V_20 , V_49 ) ;
}
if ( V_3 -> V_2 -> F_28 )
return V_3 -> V_2 -> F_28 ( V_3 , V_63 , V_20 , V_49 ) ;
if ( V_9 != 0 ) {
F_41 () ;
}
return NULL ;
}
void *
F_47 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_10 V_9 )
{
T_3 V_20 , V_49 ;
void * V_65 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
V_65 = F_48 ( V_64 , V_49 ) ;
return F_28 ( V_3 , V_65 , V_20 , V_49 ) ;
}
const T_7 *
V_55 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
return F_22 ( V_3 , V_25 , V_9 ) ;
}
T_7
F_49 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_7 ) ) ;
return * V_66 ;
}
T_13
F_50 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_13 ) ) ;
return F_51 ( V_66 ) ;
}
T_5
F_52 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 3 ) ;
return F_53 ( V_66 ) ;
}
T_5
F_54 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_55 ( V_66 ) ;
}
T_9
F_56 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 5 ) ;
return F_57 ( V_66 ) ;
}
T_14
F_58 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_56 ( V_3 , V_25 ) , 40 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_60 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 6 ) ;
return F_61 ( V_66 ) ;
}
T_14
F_62 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_60 ( V_3 , V_25 ) , 48 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_63 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 7 ) ;
return F_64 ( V_66 ) ;
}
T_14
F_65 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_63 ( V_3 , V_25 ) , 56 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_66 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_9 ) ) ;
return F_67 ( V_66 ) ;
}
static int
F_68 ( const T_5 V_68 )
{
return ( ( V_68 & ~ V_69 ) == 0 ) ;
}
static T_15
F_69 ( const T_5 V_68 )
{
long V_70 ;
long V_71 ;
long V_72 ;
V_70 = V_68 & V_69 ;
V_71 = V_68 & V_73 ;
V_72 = V_68 & V_74 ;
if ( F_68 ( V_68 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_71 = ( ( V_71 >> V_75 ) - V_76 ) -
V_75 ;
V_72 |= V_77 ;
if ( V_70 )
return - V_72 * pow ( 2 , V_71 ) ;
else
return V_72 * pow ( 2 , V_71 ) ;
}
static int
F_70 ( const T_9 V_68 )
{
return ( ( V_68 & ~ V_69 ) == 0 ) ;
}
static T_16
F_71 ( const T_9 V_68 )
{
T_14 V_70 ;
T_14 V_71 ;
T_14 V_72 ;
V_70 = V_68 & V_78 ;
V_71 = V_68 & V_79 ;
V_72 = V_68 & V_80 ;
if ( F_70 ( V_68 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_71 = ( ( V_71 >> V_81 ) - V_82 ) -
V_81 ;
V_72 |= V_83 ;
if ( V_70 )
return - V_72 * pow ( 2 , V_71 ) ;
else
return V_72 * pow ( 2 , V_71 ) ;
}
T_15
F_72 ( T_1 * V_3 , const int V_25 )
{
#if F_73 ( V_84 )
return F_69 ( F_54 ( V_3 , V_25 ) ) ;
#else
union {
T_15 V_85 ;
T_5 V_68 ;
} V_86 ;
V_86 . V_68 = F_54 ( V_3 , V_25 ) ;
return V_86 . V_85 ;
#endif
}
T_16
F_74 ( T_1 * V_3 , const int V_25 )
{
#if F_73 ( V_84 )
union {
T_5 V_68 [ 2 ] ;
T_9 V_87 ;
} V_86 ;
#else
union {
T_16 V_88 ;
T_5 V_68 [ 2 ] ;
} V_86 ;
#endif
#ifdef F_75
V_86 . V_68 [ 0 ] = F_54 ( V_3 , V_25 ) ;
V_86 . V_68 [ 1 ] = F_54 ( V_3 , V_25 + 4 ) ;
#else
V_86 . V_68 [ 0 ] = F_54 ( V_3 , V_25 + 4 ) ;
V_86 . V_68 [ 1 ] = F_54 ( V_3 , V_25 ) ;
#endif
#if F_73 ( V_84 )
return F_71 ( V_86 . V_87 ) ;
#else
return V_86 . V_88 ;
#endif
}
T_13
F_76 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_13 ) ) ;
return F_77 ( V_66 ) ;
}
T_5
F_78 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 3 ) ;
return F_79 ( V_66 ) ;
}
T_5
F_80 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_81 ( V_66 ) ;
}
T_9
F_82 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 5 ) ;
return F_83 ( V_66 ) ;
}
T_14
F_84 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_82 ( V_3 , V_25 ) , 40 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_85 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 6 ) ;
return F_86 ( V_66 ) ;
}
T_14
F_87 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_85 ( V_3 , V_25 ) , 48 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_88 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , 7 ) ;
return F_89 ( V_66 ) ;
}
T_14
F_90 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_67 ;
V_67 = F_59 ( F_88 ( V_3 , V_25 ) , 56 ) ;
return ( T_14 ) V_67 ;
}
T_9
F_91 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_9 ) ) ;
return F_92 ( V_66 ) ;
}
T_15
F_93 ( T_1 * V_3 , const int V_25 )
{
#if F_73 ( V_84 )
return F_69 ( F_80 ( V_3 , V_25 ) ) ;
#else
union {
T_15 V_85 ;
T_5 V_68 ;
} V_86 ;
V_86 . V_68 = F_80 ( V_3 , V_25 ) ;
return V_86 . V_85 ;
#endif
}
T_16
F_94 ( T_1 * V_3 , const int V_25 )
{
#if F_73 ( V_84 )
union {
T_5 V_68 [ 2 ] ;
T_9 V_87 ;
} V_86 ;
#else
union {
T_16 V_88 ;
T_5 V_68 [ 2 ] ;
} V_86 ;
#endif
#ifdef F_75
V_86 . V_68 [ 0 ] = F_80 ( V_3 , V_25 + 4 ) ;
V_86 . V_68 [ 1 ] = F_80 ( V_3 , V_25 ) ;
#else
V_86 . V_68 [ 0 ] = F_80 ( V_3 , V_25 ) ;
V_86 . V_68 [ 1 ] = F_80 ( V_3 , V_25 + 4 ) ;
#endif
#if F_73 ( V_84 )
return F_71 ( V_86 . V_87 ) ;
#else
return V_86 . V_88 ;
#endif
}
static inline void
F_95 ( const T_3 V_89 )
{
const T_3 V_90 = V_89 & ~ V_91 ;
switch ( V_90 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
F_96 ( L_1 ) ;
break;
default:
break;
}
if ( V_90 == 0 )
F_96 ( L_2 ) ;
}
T_17 *
F_97 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 ,
const T_3 V_89 , T_17 * V_97 , T_4 * V_98 )
{
const T_18 * V_66 = ( T_18 * ) F_98 ( F_99 () , V_3 , V_25 , V_9 ) ;
const T_18 * V_99 = V_66 ;
const T_18 * V_100 = NULL ;
T_17 * V_101 = NULL ;
V_102 = V_103 ;
F_95 ( V_89 ) ;
if ( V_98 ) * V_98 = 0 ;
while ( * V_99 == ' ' ) V_99 ++ ;
if ( * V_99 && V_97 ) {
if ( F_100 ( V_99 , V_97 , & V_100 , V_89 , FALSE ) ) {
if ( V_97 -> V_45 > 0 ) {
if ( V_98 ) * V_98 = V_25 + ( T_4 ) ( V_100 - V_66 ) ;
V_102 = 0 ;
V_101 = V_97 ;
}
}
}
return V_101 ;
}
T_19 *
F_101 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 ,
const T_3 V_89 , T_19 * V_104 , T_4 * V_98 )
{
const T_18 * V_99 = ( T_18 * ) F_98 ( F_99 () , V_3 , V_25 , V_9 ) ;
const T_18 * V_66 = V_99 ;
const T_18 * V_100 = NULL ;
struct V_105 V_105 ;
T_19 * V_101 = NULL ;
char V_70 = '+' ;
int V_106 = 0 ;
int V_107 = 0 ;
int V_108 = 0 ;
T_8 V_109 = FALSE ;
V_102 = V_103 ;
F_95 ( V_89 ) ;
F_5 ( V_104 ) ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_110 = - 1 ;
V_104 -> V_111 = 0 ;
V_104 -> V_112 = 0 ;
while ( * V_66 == ' ' ) V_66 ++ ;
if ( * V_66 ) {
if ( ( V_89 & V_113 ) == V_113 ) {
if ( sscanf ( V_66 , L_3 ,
& V_105 . V_114 ,
& V_105 . V_115 ,
& V_105 . V_116 ,
& V_105 . V_117 ,
& V_105 . V_118 ,
& V_105 . V_119 ,
& V_70 ,
& V_106 ,
& V_107 ,
& V_108 ) >= 9 )
{
V_109 = TRUE ;
}
else if ( sscanf ( V_66 , L_4 ,
& V_105 . V_114 ,
& V_105 . V_115 ,
& V_105 . V_116 ,
& V_105 . V_117 ,
& V_105 . V_118 ,
& V_70 ,
& V_106 ,
& V_107 ,
& V_108 ) >= 8 )
{
V_109 = TRUE ;
}
else if ( sscanf ( V_66 , L_5 ,
& V_105 . V_114 ,
& V_105 . V_115 ,
& V_105 . V_116 ,
& V_105 . V_117 ,
& V_105 . V_118 ,
& V_105 . V_119 ,
& V_108 ) >= 6 )
{
V_109 = TRUE ;
V_106 = 0 ;
V_107 = 0 ;
}
else if ( sscanf ( V_66 , L_6 ,
& V_105 . V_114 ,
& V_105 . V_115 ,
& V_105 . V_116 ,
& V_105 . V_117 ,
& V_105 . V_118 ,
& V_108 ) >= 5 )
{
V_109 = TRUE ;
V_106 = 0 ;
V_107 = 0 ;
}
if ( V_109 ) {
V_102 = 0 ;
V_100 = V_66 + V_108 ;
V_105 . V_115 -- ;
if ( V_105 . V_114 > 1900 ) V_105 . V_114 -= 1900 ;
if ( V_70 == '-' ) V_106 = - V_106 ;
}
}
else if ( V_89 & V_120 ) {
if ( sscanf ( V_66 , L_7 ,
& V_105 . V_114 ,
& V_105 . V_115 ,
& V_105 . V_116 ,
& V_108 ) >= 3 )
{
V_102 = 0 ;
V_100 = V_66 + V_108 ;
V_105 . V_115 -- ;
if ( V_105 . V_114 > 1900 ) V_105 . V_114 -= 1900 ;
}
}
else if ( V_89 & V_121 ) {
if ( sscanf ( V_66 , L_8 ,
& V_105 . V_117 ,
& V_105 . V_118 ,
& V_105 . V_119 ,
& V_108 ) >= 2 )
{
T_20 V_122 = time ( NULL ) ;
struct V_105 * V_123 = gmtime ( & V_122 ) ;
V_105 . V_114 = V_123 -> V_114 ;
V_105 . V_115 = V_123 -> V_115 ;
V_105 . V_116 = V_123 -> V_116 ;
V_100 = V_66 + V_108 ;
V_102 = 0 ;
}
}
else if ( V_89 & V_124 || V_89 & V_125 ) {
if ( V_89 & V_124 ) {
V_100 = strptime ( V_66 , L_9 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_10 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_11 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_12 , & V_105 ) ;
}
else if ( V_89 & V_125 ) {
V_100 = strptime ( V_66 , L_13 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_14 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_15 , & V_105 ) ;
if ( ! V_100 ) V_100 = strptime ( V_66 , L_16 , & V_105 ) ;
}
if ( V_100 ) {
V_102 = 0 ;
if ( * V_100 == ' ' ) V_100 ++ ;
if ( F_102 ( V_100 , L_17 , 2 ) == 0 )
{
V_100 += 2 ;
}
else if ( F_102 ( V_100 , L_18 , 3 ) == 0 )
{
V_100 += 3 ;
}
else if ( sscanf ( V_100 , L_19 ,
& V_70 ,
& V_106 ,
& V_107 ,
& V_108 ) < 3 )
{
V_102 = V_126 ;
}
if ( V_70 == '-' ) V_106 = - V_106 ;
}
}
}
if ( V_102 == 0 ) {
V_104 -> V_111 = F_103 ( & V_105 ) ;
if ( V_106 > 0 )
V_104 -> V_111 += ( V_106 * 3600 ) + ( V_107 * 60 ) ;
else if ( V_106 < 0 )
V_104 -> V_111 -= ( ( - V_106 ) * 3600 ) + ( V_107 * 60 ) ;
V_101 = V_104 ;
if ( V_98 )
* V_98 = ( T_4 ) ( V_25 + ( V_100 - V_99 ) ) ;
}
return V_101 ;
}
T_5
F_104 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_66 ;
T_5 V_127 ;
V_66 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
memcpy ( & V_127 , V_66 , sizeof V_127 ) ;
return V_127 ;
}
void
F_105 ( T_1 * V_3 , const T_4 V_25 , struct V_128 * V_127 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , sizeof( * V_127 ) ) ;
memcpy ( V_127 , V_66 , sizeof *V_127 ) ;
}
void
F_106 ( T_1 * V_3 , const T_4 V_25 , T_21 * V_129 )
{
const T_7 * V_66 = F_22 ( V_3 , V_25 , V_130 ) ;
V_129 -> V_131 = F_55 ( V_66 + 0 ) ;
V_129 -> V_132 = F_51 ( V_66 + 4 ) ;
V_129 -> V_133 = F_51 ( V_66 + 6 ) ;
memcpy ( V_129 -> V_134 , V_66 + 8 , sizeof V_129 -> V_134 ) ;
}
void
F_107 ( T_1 * V_3 , const T_4 V_25 , T_21 * V_129 )
{
const T_7 * V_66 = F_22 ( V_3 , V_25 , V_130 ) ;
V_129 -> V_131 = F_81 ( V_66 + 0 ) ;
V_129 -> V_132 = F_77 ( V_66 + 4 ) ;
V_129 -> V_133 = F_77 ( V_66 + 6 ) ;
memcpy ( V_129 -> V_134 , V_66 + 8 , sizeof V_129 -> V_134 ) ;
}
void
F_108 ( T_1 * V_3 , const T_4 V_25 , T_21 * V_129 , const T_3 V_135 )
{
if ( V_135 ) {
F_107 ( V_3 , V_25 , V_129 ) ;
} else {
F_106 ( V_3 , V_25 , V_129 ) ;
}
}
T_7
F_109 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 )
{
return ( T_7 ) F_110 ( V_3 , V_32 , V_33 ) ;
}
T_13
F_111 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_89 V_136 )
{
return ( T_13 ) F_110 ( V_3 , V_32 , V_33 ) ;
}
T_5
F_112 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_89 V_136 )
{
return ( T_5 ) F_110 ( V_3 , V_32 , V_33 ) ;
}
T_9
F_113 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_89 V_136 )
{
return F_110 ( V_3 , V_32 , V_33 ) ;
}
static T_9
F_110 ( T_1 * V_3 , T_3 V_32 , const T_4 V_137 )
{
T_9 V_138 ;
T_3 V_139 = V_32 >> 3 ;
T_7 V_140 = 8 - ( V_32 % 8 ) ;
if( V_140 > V_137 )
{
T_7 V_141 = V_140 - V_137 ;
V_138 = ( F_49 ( V_3 , V_139 ) >> V_141 ) & V_142 [ V_137 % 8 ] ;
}
else
{
T_7 V_143 = V_137 ;
V_138 = 0 ;
V_140 %= 8 ;
if( V_140 != 0 )
{
V_138 = F_49 ( V_3 , V_139 ) & V_142 [ V_140 ] ;
V_143 -= V_140 ;
V_139 ++ ;
}
while ( V_143 > 7 )
{
switch ( V_143 >> 4 )
{
case 0 :
V_138 <<= 8 ;
V_138 += F_49 ( V_3 , V_139 ) ;
V_143 -= 8 ;
V_139 ++ ;
break;
case 1 :
V_138 <<= 16 ;
V_138 += F_50 ( V_3 , V_139 ) ;
V_143 -= 16 ;
V_139 += 2 ;
break;
case 2 :
case 3 :
V_138 <<= 32 ;
V_138 += F_54 ( V_3 , V_139 ) ;
V_143 -= 32 ;
V_139 += 4 ;
break;
default:
V_138 = F_66 ( V_3 , V_139 ) ;
V_143 -= 64 ;
V_139 += 8 ;
break;
}
}
if( V_143 )
{
V_138 <<= V_143 ;
V_138 += ( F_49 ( V_3 , V_139 ) >> ( 8 - V_143 ) ) ;
}
}
return V_138 ;
}
T_5
F_114 ( T_1 * V_3 , const T_3 V_32 , const T_4 V_33 , const T_3 V_89 V_136 )
{
return ( T_5 ) F_110 ( V_3 , V_32 , V_33 ) ;
}
static T_4
F_115 ( T_1 * V_3 , T_3 V_20 , T_3 V_144 , T_7 V_145 )
{
const T_7 * V_66 ;
const T_7 * V_62 ;
V_66 = F_22 ( V_3 , V_20 , V_144 ) ;
V_62 = ( const T_7 * ) memchr ( V_66 , V_145 , V_144 ) ;
if ( ! V_62 )
return - 1 ;
return ( T_4 ) ( ( V_62 - V_66 ) + V_20 ) ;
}
T_4
F_116 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_146 , const T_7 V_145 )
{
const T_7 * V_62 ;
T_3 V_20 ;
T_3 V_144 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_144 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_144 > ( T_3 ) V_146 ) {
V_144 = V_146 ;
}
if ( V_3 -> V_11 ) {
V_62 = ( const T_7 * ) memchr ( V_3 -> V_11 + V_20 , V_145 , V_144 ) ;
if ( V_62 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_62 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_116 )
return V_3 -> V_2 -> F_116 ( V_3 , V_20 , V_144 , V_145 ) ;
return F_115 ( V_3 , V_25 , V_144 , V_145 ) ;
}
static inline T_4
F_117 ( T_1 * V_3 , T_3 V_20 , T_3 V_144 , const T_7 * V_60 , T_11 * V_61 )
{
const T_7 * V_66 ;
const T_7 * V_62 ;
V_66 = F_22 ( V_3 , V_20 , V_144 ) ;
V_62 = F_45 ( V_66 , V_144 , V_60 , V_61 ) ;
if ( ! V_62 )
return - 1 ;
return ( T_4 ) ( ( V_62 - V_66 ) + V_20 ) ;
}
T_4
F_118 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_146 , const T_7 * V_60 , T_11 * V_61 )
{
const T_7 * V_62 ;
T_3 V_20 ;
T_3 V_144 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_144 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_144 > ( T_3 ) V_146 ) {
V_144 = V_146 ;
}
if ( V_3 -> V_11 ) {
V_62 = F_45 ( V_3 -> V_11 + V_20 , V_144 , V_60 , V_61 ) ;
if ( V_62 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_62 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_118 )
return V_3 -> V_2 -> F_118 ( V_3 , V_20 , V_144 , V_60 , V_61 ) ;
return F_117 ( V_3 , V_20 , V_144 , V_60 , V_61 ) ;
}
T_3
F_119 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_147 ;
T_4 V_148 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_147 ) ;
V_148 = F_116 ( V_3 , V_20 , - 1 , 0 ) ;
if ( V_148 == - 1 ) {
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
return ( V_148 - V_20 ) + 1 ;
}
T_3
F_120 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_37 = 0 ;
T_22 V_149 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
do {
V_149 = F_50 ( V_3 , V_25 + V_37 ) ;
V_37 += 2 ;
} while( V_149 != 0 );
return V_37 ;
}
T_4
F_121 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_146 )
{
T_4 V_150 ;
T_3 V_20 , V_147 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_147 ) ;
V_150 = F_116 ( V_3 , V_20 , V_146 , 0 ) ;
if ( V_150 == - 1 ) {
return - 1 ;
}
else {
return V_150 - V_20 ;
}
}
T_4
F_122 ( T_1 * V_3 , const T_4 V_25 , const T_18 * V_151 , const T_10 V_4 )
{
const T_7 * V_66 ;
V_66 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_66 ) {
int V_152 = strncmp ( ( const char * ) V_66 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_123 ( T_1 * V_3 , const T_4 V_25 , const T_18 * V_151 , const T_10 V_4 )
{
const T_7 * V_66 ;
V_66 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_66 ) {
int V_152 = F_102 ( ( const char * ) V_66 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_124 ( T_1 * V_3 , const T_4 V_25 , const T_7 * V_151 , T_10 V_4 )
{
const T_7 * V_66 ;
V_66 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_66 ) {
int V_152 = memcmp ( V_66 , V_151 , V_4 ) ;
return ( V_152 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_18 *
F_125 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_66 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_126 ( V_66 , V_45 ) ;
}
T_18 *
F_127 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_66 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_128 ( V_66 , V_45 ) ;
}
T_18 *
F_129 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_66 , * V_56 ;
T_4 V_45 ;
T_4 V_153 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_66 , V_153 = 0 ; V_153 < V_45 && * V_56 != '\0' ; V_56 ++ , V_153 ++ )
;
return F_126 ( V_66 , V_153 ) ;
}
T_18 *
F_130 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_66 , * V_56 ;
T_4 V_45 ;
T_4 V_153 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_66 , V_153 = 0 ; V_153 < V_45 && * V_56 != '\0' ; V_56 ++ , V_153 ++ )
;
return F_128 ( V_66 , V_153 ) ;
}
static T_7 *
F_131 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_132 ( V_64 , V_66 , V_9 ) ;
}
static T_7 *
F_133 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_154 ;
F_35 ( V_3 , V_25 , V_9 ) ;
V_154 = ( T_7 * ) F_48 ( V_64 , V_9 + 1 ) ;
F_28 ( V_3 , V_154 , V_25 , V_9 ) ;
V_154 [ V_9 ] = '\0' ;
return V_154 ;
}
static inline T_7 *
F_98 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_154 ;
T_4 V_49 = V_9 ;
F_5 ( V_25 >= 0 ) ;
F_5 ( V_49 >= - 1 ) ;
if ( V_49 < 0 )
V_49 = V_3 -> V_9 - V_25 ;
F_35 ( V_3 , V_25 , V_49 ) ;
V_154 = ( T_7 * ) F_48 ( V_64 , V_49 + 1 ) ;
F_28 ( V_3 , V_154 , V_25 , V_49 ) ;
V_154 [ V_49 ] = '\0' ;
return V_154 ;
}
static T_7 *
F_134 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_135 ( V_64 , V_66 , V_9 ) ;
}
static T_7 *
F_136 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 V_9 , const T_22 V_155 [ 0x80 ] )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_137 ( V_64 , V_66 , V_9 , V_155 ) ;
}
static T_7 *
F_138 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_89 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_139 ( V_64 , V_66 , V_9 , V_89 ) ;
}
static T_7 *
F_140 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_89 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_141 ( V_64 , V_66 , V_9 , V_89 ) ;
}
static T_18 *
F_142 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_89 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_143 ( V_64 , V_66 , V_9 , V_89 ) ;
}
T_18 *
F_144 ( T_12 * V_64 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_156 )
{
T_4 V_157 = V_32 >> 3 ;
T_4 V_9 = ( ( V_156 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_66 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_66 = F_22 ( V_3 , V_157 , V_9 ) ;
return F_145 ( V_64 , V_66 , V_32 , V_156 ) ;
}
T_18 *
F_146 ( T_12 * V_64 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_156 )
{
T_4 V_157 = V_32 >> 3 ;
T_4 V_9 = ( ( V_156 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_66 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_66 = F_22 ( V_3 , V_157 , V_9 ) ;
return F_147 ( V_64 , V_66 , V_32 , V_156 ) ;
}
static T_7 *
F_148 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_66 ;
V_66 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_149 ( V_64 , V_66 , V_9 ) ;
}
T_7 *
F_150 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_89 )
{
T_7 * V_158 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_17 ( V_24 ) ;
}
switch ( V_89 & V_159 ) {
case V_160 :
default:
V_158 = F_131 ( V_64 , V_3 , V_25 , V_9 ) ;
break;
case V_161 :
V_158 = F_133 ( V_64 , V_3 , V_25 , V_9 ) ;
break;
case V_92 :
V_158 = F_140 ( V_64 , V_3 , V_25 , V_9 ,
V_89 & V_162 ) ;
break;
case V_93 :
V_158 = F_138 ( V_64 , V_3 , V_25 , V_9 ,
V_89 & V_162 ) ;
break;
case V_94 :
V_158 = F_142 ( V_64 , V_3 , V_25 , V_9 ,
V_89 & V_162 ) ;
break;
case V_163 :
V_158 = F_134 ( V_64 , V_3 , V_25 , V_9 ) ;
break;
case V_164 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_165 ) ;
break;
case V_166 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_167 ) ;
break;
case V_168 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_169 ) ;
break;
case V_170 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_171 ) ;
break;
case V_172 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_173 ) ;
break;
case V_174 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_175 ) ;
break;
case V_176 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_177 ) ;
break;
case V_178 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_179 ) ;
break;
case V_180 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_181 ) ;
break;
case V_182 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_183 ) ;
break;
case V_184 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_185 ) ;
break;
case V_186 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_187 ) ;
break;
case V_188 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_189 ) ;
break;
case V_190 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_191 ) ;
break;
case V_192 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_193 ) ;
break;
case V_194 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_195 ) ;
break;
case V_196 :
V_158 = F_136 ( V_64 , V_3 , V_25 , V_9 , V_197 ) ;
break;
case V_95 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_156 = ( V_9 << 3 ) / 7 ;
V_158 = F_144 ( V_64 , V_3 , V_32 , V_156 ) ;
}
break;
case V_198 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_156 = ( V_9 << 3 ) / 7 ;
V_158 = F_146 ( V_64 , V_3 , V_32 , V_156 ) ;
}
break;
case V_96 :
V_158 = F_148 ( V_64 , V_3 , V_25 , V_9 ) ;
break;
}
return V_158 ;
}
T_7 *
F_151 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_89 )
{
return F_150 ( V_64 , V_3 , V_25 , V_9 , V_89 ) ;
}
static T_7 *
F_152 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 * V_199 )
{
T_3 V_4 ;
const T_7 * V_66 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_132 ( V_64 , V_66 , V_4 ) ;
}
static T_7 *
F_153 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 * V_199 )
{
T_3 V_4 ;
T_7 * V_158 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_158 = ( T_7 * ) F_48 ( V_64 , V_4 ) ;
F_28 ( V_3 , V_158 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return V_158 ;
}
static T_7 *
F_154 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 * V_199 )
{
T_3 V_4 ;
const T_7 * V_66 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_135 ( V_64 , V_66 , V_4 ) ;
}
static T_7 *
F_155 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 * V_199 , const T_22 V_155 [ 0x80 ] )
{
T_3 V_4 ;
const T_7 * V_66 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_137 ( V_64 , V_66 , V_4 , V_155 ) ;
}
const T_7 *
F_156 ( T_1 * V_3 , const T_4 V_25 , T_4 * V_199 )
{
T_3 V_4 ;
const T_7 * V_158 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_158 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return V_158 ;
}
static T_18 *
F_157 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 * V_199 , const T_3 V_89 )
{
T_4 V_4 ;
const T_7 * V_66 ;
V_4 = F_120 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_139 ( V_64 , V_66 , V_4 , V_89 ) ;
}
static T_18 *
F_158 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 * V_199 , const T_3 V_89 )
{
T_4 V_4 ;
const T_7 * V_66 ;
V_4 = F_120 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_141 ( V_64 , V_66 , V_4 , V_89 ) ;
}
static T_18 *
F_159 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 * V_199 , const T_3 V_89 )
{
T_4 V_4 ;
T_23 V_149 ;
const T_7 * V_66 ;
V_4 = 0 ;
do {
V_149 = F_54 ( V_3 , V_25 + V_4 ) ;
V_4 += 4 ;
} while( V_149 != 0 );
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_143 ( V_64 , V_66 , V_4 , V_89 ) ;
}
static T_7 *
F_160 ( T_12 * V_64 , T_1 * V_3 , T_4 V_25 , T_4 * V_199 )
{
T_3 V_4 ;
const T_7 * V_66 ;
V_4 = F_119 ( V_3 , V_25 ) ;
V_66 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_199 )
* V_199 = V_4 ;
return F_149 ( V_64 , V_66 , V_4 ) ;
}
T_7 *
F_161 ( T_12 * V_64 , T_1 * V_3 , const T_4 V_25 , T_4 * V_199 , const T_3 V_89 )
{
T_7 * V_158 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
switch ( V_89 & V_159 ) {
case V_160 :
default:
V_158 = F_152 ( V_64 , V_3 , V_25 , V_199 ) ;
break;
case V_161 :
V_158 = F_153 ( V_64 , V_3 , V_25 , V_199 ) ;
break;
case V_92 :
V_158 = F_158 ( V_64 , V_3 , V_25 , V_199 ,
V_89 & V_162 ) ;
break;
case V_93 :
V_158 = F_157 ( V_64 , V_3 , V_25 , V_199 ,
V_89 & V_162 ) ;
break;
case V_94 :
V_158 = F_159 ( V_64 , V_3 , V_25 , V_199 ,
V_89 & V_162 ) ;
break;
case V_163 :
V_158 = F_154 ( V_64 , V_3 , V_25 , V_199 ) ;
break;
case V_164 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_165 ) ;
break;
case V_166 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_167 ) ;
break;
case V_168 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_169 ) ;
break;
case V_170 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_171 ) ;
break;
case V_172 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_173 ) ;
break;
case V_174 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_175 ) ;
break;
case V_176 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_177 ) ;
break;
case V_178 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_179 ) ;
break;
case V_180 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_181 ) ;
break;
case V_182 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_183 ) ;
break;
case V_184 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_185 ) ;
break;
case V_186 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_187 ) ;
break;
case V_188 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_189 ) ;
break;
case V_190 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_191 ) ;
break;
case V_192 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_193 ) ;
break;
case V_194 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_195 ) ;
break;
case V_196 :
V_158 = F_155 ( V_64 , V_3 , V_25 , V_199 , V_197 ) ;
break;
case V_95 :
F_96 ( L_20 ) ;
break;
case V_198 :
F_96 ( L_21 ) ;
break;
case V_96 :
V_158 = F_160 ( V_64 , V_3 , V_25 , V_199 ) ;
break;
}
return V_158 ;
}
static T_4
F_162 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_200 , T_7 * V_201 , T_4 * V_202 )
{
T_4 V_153 ;
T_3 V_20 ;
T_4 V_144 , V_45 ;
T_8 V_203 = FALSE ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_45 ) ;
F_5 ( V_200 != 0 ) ;
if ( V_200 == 1 ) {
V_201 [ 0 ] = 0 ;
* V_202 = 1 ;
return 0 ;
}
if ( V_45 == 0 ) {
F_17 ( V_24 ) ;
}
F_5 ( V_45 != - 1 ) ;
F_5 ( V_200 <= V_50 ) ;
if ( ( T_3 ) V_45 < V_200 ) {
V_144 = V_45 ;
V_203 = TRUE ;
}
else {
V_144 = V_200 ;
}
V_153 = F_121 ( V_3 , V_20 , V_144 - 1 ) ;
if ( V_153 == - 1 ) {
F_28 ( V_3 , V_201 , V_20 , V_144 ) ;
if ( V_203 ) {
V_201 [ V_144 ] = 0 ;
* V_202 = V_144 + 1 ;
}
else {
* V_202 = V_144 ;
}
return - 1 ;
}
F_28 ( V_3 , V_201 , V_20 , V_153 + 1 ) ;
* V_202 = V_153 + 1 ;
return V_153 ;
}
T_4
F_163 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_200 , T_7 * V_201 )
{
T_4 V_202 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
return F_162 ( V_3 , V_25 , V_200 , V_201 , & V_202 ) ;
}
T_4
F_164 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_200 , T_7 * V_201 )
{
T_4 V_45 , V_202 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_45 = F_162 ( V_3 , V_25 , V_200 , V_201 , & V_202 ) ;
if ( V_45 == - 1 ) {
V_201 [ V_200 - 1 ] = 0 ;
return V_202 - 1 ;
}
else {
return V_45 ;
}
}
T_4
F_165 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_204 , const T_8 V_205 )
{
#ifdef F_166
static const char V_206 ( F_167 ( 16 ) ) V_207 [] = L_22 ;
#else
static const char V_207 [] V_208 ( ( F_168 ( 16 ) ) ) = L_22 ;
#endif
T_4 V_209 ;
T_4 V_210 ;
int V_211 ;
T_11 V_61 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
V_209 = V_25 + V_45 ;
V_210 = F_118 ( V_3 , V_25 , V_45 , V_207 , & V_61 ) ;
if ( V_210 == - 1 ) {
if ( V_205 ) {
return - 1 ;
} else {
V_211 = V_209 - V_25 ;
if ( V_204 )
* V_204 = V_209 ;
}
} else {
V_211 = V_210 - V_25 ;
if ( V_61 == '\r' ) {
if ( V_210 + 1 >= V_209 ) {
if ( V_205 ) {
return - 1 ;
}
} else {
if ( F_49 ( V_3 , V_210 + 1 ) == '\n' ) {
V_210 ++ ;
}
}
}
if ( V_204 )
* V_204 = V_210 + 1 ;
}
return V_211 ;
}
T_4
F_169 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_204 )
{
T_4 V_212 , V_213 ;
T_8 V_214 ;
T_11 V_215 = 0 ;
T_4 V_209 ;
int V_211 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
V_209 = V_25 + V_45 ;
V_212 = V_25 ;
V_214 = FALSE ;
for (; ; ) {
if ( V_214 ) {
V_213 = F_116 ( V_3 , V_212 , V_45 ,
'"' ) ;
} else {
V_213 = F_118 ( V_3 , V_212 , V_45 , L_23 , & V_215 ) ;
}
if ( V_213 == - 1 ) {
V_211 = V_209 - V_25 ;
if ( V_204 )
* V_204 = V_209 ;
break;
}
if ( V_214 ) {
V_214 = FALSE ;
} else {
if ( V_215 == '"' ) {
V_214 = TRUE ;
} else {
V_211 = V_213 - V_25 ;
if ( V_215 == '\r' ) {
if ( V_213 + 1 < V_209 &&
F_49 ( V_3 , V_213 + 1 )
== '\n' ) {
V_213 ++ ;
}
}
if ( V_204 )
* V_204 = V_213 + 1 ;
break;
}
}
V_212 = V_213 + 1 ;
if ( V_212 >= V_209 ) {
V_211 = V_209 - V_25 ;
if ( V_204 )
* V_204 = V_209 ;
break;
}
}
return V_211 ;
}
T_4
F_170 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_146 )
{
T_4 V_52 = V_25 ;
T_4 V_100 , V_216 ;
T_7 V_217 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_216 = V_3 -> V_9 ;
V_100 = V_25 + V_146 ;
if ( V_100 >= V_216 )
{
V_100 = V_216 ;
}
for ( V_52 = V_25 ;
V_52 < V_100 &&
( ( V_217 = F_49 ( V_3 , V_52 ) ) == ' ' ||
V_217 == '\t' || V_217 == '\r' || V_217 == '\n' ) ;
V_52 ++ ) ;
return ( V_52 ) ;
}
T_4
F_171 ( T_1 * V_3 , const T_4 V_25 ) {
T_4 V_52 = V_25 ;
T_7 V_217 ;
for( V_52 = V_25 ; V_52 > 0 &&
( ( V_217 = F_49 ( V_3 , V_52 ) ) == ' ' ||
V_217 == '\t' || V_217 == '\n' || V_217 == '\r' ) ; V_52 -- ) ;
V_52 ++ ;
return ( V_52 ) ;
}
int
F_172 ( T_1 * V_3 , int V_25 , const int V_146 , const T_7 V_218 )
{
int V_100 , V_216 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_216 = V_3 -> V_9 ;
V_100 = V_25 + V_146 ;
if ( V_100 >= V_216 )
V_100 = V_216 ;
while ( V_25 < V_100 ) {
T_7 V_219 = F_49 ( V_3 , V_25 ) ;
if ( V_219 != V_218 )
break;
V_25 ++ ;
}
return V_25 ;
}
T_18 *
F_173 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , const T_18 V_220 )
{
return F_174 ( F_22 ( V_3 , V_25 , V_45 ) , V_45 , V_220 ) ;
}
const T_18 *
F_175 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , T_24 * V_221 , T_8 V_222 )
{
int V_9 ;
T_7 V_223 ;
int V_37 = 0 ;
char * V_224 ;
T_4 V_225 = V_25 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( ! V_221 )
V_221 = & V_226 ;
if ( V_45 == - 1 ) {
V_9 = V_3 -> V_9 ;
if ( V_9 < V_25 ) {
return L_24 ;
}
} else {
V_9 = V_25 + V_45 ;
}
V_224 = ( char * ) F_48 ( F_99 () , ( V_9 - V_25 ) * 2 + 1 ) ;
while ( V_225 < V_9 ) {
V_223 = F_49 ( V_3 , V_225 ) ;
if ( ! V_222 ) {
V_224 [ V_37 ] = V_221 -> V_227 [ V_223 & 0x0f ] ;
V_37 ++ ;
}
V_222 = FALSE ;
V_223 = V_223 >> 4 ;
if ( V_223 == 0x0f )
break;
V_224 [ V_37 ] = V_221 -> V_227 [ V_223 & 0x0f ] ;
V_37 ++ ;
V_225 ++ ;
}
V_224 [ V_37 ] = '\0' ;
return V_224 ;
}
T_18 *
F_176 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 )
{
return F_177 ( F_22 ( V_3 , V_25 , V_45 ) , V_45 ) ;
}
T_4
F_178 ( T_1 * V_228 , T_1 * V_229 , const T_4 V_230 )
{
T_3 V_231 , V_232 ;
const T_7 * V_233 ;
const T_7 * V_234 ;
const T_3 V_235 = V_229 -> V_9 ;
const T_7 * V_236 ;
F_5 ( V_228 && V_228 -> V_7 ) ;
if ( V_228 -> V_9 < 1 || V_229 -> V_9 < 1 ) {
return - 1 ;
}
V_233 = F_22 ( V_228 , 0 , - 1 ) ;
V_234 = F_22 ( V_229 , 0 , - 1 ) ;
F_16 ( V_228 , V_230 , - 1 ,
& V_231 , & V_232 ) ;
V_236 = F_179 ( V_233 + V_231 , V_232 ,
V_234 , V_235 ) ;
if ( V_236 ) {
return ( T_4 ) ( V_236 - V_233 ) ;
}
return - 1 ;
}
T_4
F_180 ( T_1 * V_3 )
{
return ( ( V_3 -> V_12 == - 1 ) ? ( V_3 -> V_12 = F_42 ( V_3 ) ) : V_3 -> V_12 ) ;
}
void
F_181 ( T_1 * V_3 )
{
V_3 -> V_8 |= V_22 ;
}
struct V_237 *
F_182 ( T_1 * V_3 )
{
return ( V_3 -> V_13 ) ;
}
