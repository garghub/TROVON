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
return F_21 ( V_3 , V_35 , V_36 , V_36 ) ;
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
T_3 V_20 = 0 , V_48 = 0 ;
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
T_3 V_20 = 0 , V_49 = 0 ;
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
void *
F_28 ( T_1 * V_3 , void * V_58 , const T_4 V_25 , T_10 V_9 )
{
T_3 V_20 = 0 , V_49 = 0 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_5 ( V_9 <= 0x7FFFFFFF ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
if ( V_3 -> V_11 ) {
return memcpy ( V_58 , V_3 -> V_11 + V_20 , V_49 ) ;
}
if ( V_3 -> V_2 -> F_28 )
return V_3 -> V_2 -> F_28 ( V_3 , V_58 , V_20 , V_49 ) ;
if ( V_9 != 0 ) {
F_41 () ;
}
return NULL ;
}
void *
F_45 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_10 V_9 )
{
T_3 V_20 = 0 , V_49 = 0 ;
void * V_60 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , ( T_4 ) V_9 , & V_20 , & V_49 ) ;
V_60 = F_46 ( V_59 , V_49 ) ;
return F_28 ( V_3 , V_60 , V_20 , V_49 ) ;
}
const T_7 *
V_55 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
return F_22 ( V_3 , V_25 , V_9 ) ;
}
T_7
F_47 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_7 ) ) ;
return * V_61 ;
}
T_12
F_48 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_12 ) ) ;
return F_49 ( V_61 ) ;
}
T_5
F_50 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 3 ) ;
return F_51 ( V_61 ) ;
}
T_5
F_52 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_53 ( V_61 ) ;
}
T_9
F_54 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 5 ) ;
return F_55 ( V_61 ) ;
}
T_13
F_56 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_54 ( V_3 , V_25 ) , 40 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_58 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 6 ) ;
return F_59 ( V_61 ) ;
}
T_13
F_60 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_58 ( V_3 , V_25 ) , 48 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_61 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 7 ) ;
return F_62 ( V_61 ) ;
}
T_13
F_63 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_61 ( V_3 , V_25 ) , 56 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_64 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_9 ) ) ;
return F_65 ( V_61 ) ;
}
T_12
F_66 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_67 ( V_3 , V_25 ) ;
} else {
return F_48 ( V_3 , V_25 ) ;
}
}
T_5
F_68 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_69 ( V_3 , V_25 ) ;
} else {
return F_50 ( V_3 , V_25 ) ;
}
}
T_5
F_70 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_71 ( V_3 , V_25 ) ;
} else {
return F_52 ( V_3 , V_25 ) ;
}
}
T_9
F_72 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_73 ( V_3 , V_25 ) ;
} else {
return F_54 ( V_3 , V_25 ) ;
}
}
T_13
F_74 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_75 ( V_3 , V_25 ) ;
} else {
return F_56 ( V_3 , V_25 ) ;
}
}
T_9
F_76 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_77 ( V_3 , V_25 ) ;
} else {
return F_58 ( V_3 , V_25 ) ;
}
}
T_13
F_78 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_79 ( V_3 , V_25 ) ;
} else {
return F_60 ( V_3 , V_25 ) ;
}
}
T_9
F_80 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_81 ( V_3 , V_25 ) ;
} else {
return F_61 ( V_3 , V_25 ) ;
}
}
T_13
F_82 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_83 ( V_3 , V_25 ) ;
} else {
return F_63 ( V_3 , V_25 ) ;
}
}
T_9
F_84 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_85 ( V_3 , V_25 ) ;
} else {
return F_64 ( V_3 , V_25 ) ;
}
}
T_14
F_86 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_87 ( V_3 , V_25 ) ;
} else {
return F_88 ( V_3 , V_25 ) ;
}
}
T_15
F_89 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_63 ) {
if ( V_63 & V_64 ) {
return F_90 ( V_3 , V_25 ) ;
} else {
return F_91 ( V_3 , V_25 ) ;
}
}
static int
F_92 ( const T_5 V_65 )
{
return ( ( V_65 & ~ V_66 ) == 0 ) ;
}
static T_14
F_93 ( const T_5 V_65 )
{
long V_67 ;
long V_68 ;
long V_69 ;
V_67 = V_65 & V_66 ;
V_68 = V_65 & V_70 ;
V_69 = V_65 & V_71 ;
if ( F_92 ( V_65 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_68 = ( ( V_68 >> V_72 ) - V_73 ) -
V_72 ;
V_69 |= V_74 ;
if ( V_67 )
return - V_69 * pow ( 2 , V_68 ) ;
else
return V_69 * pow ( 2 , V_68 ) ;
}
static int
F_94 ( const T_9 V_65 )
{
return ( ( V_65 & ~ V_66 ) == 0 ) ;
}
static T_15
F_95 ( const T_9 V_65 )
{
T_13 V_67 ;
T_13 V_68 ;
T_13 V_69 ;
V_67 = V_65 & V_75 ;
V_68 = V_65 & V_76 ;
V_69 = V_65 & V_77 ;
if ( F_94 ( V_65 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_68 = ( ( V_68 >> V_78 ) - V_79 ) -
V_78 ;
V_69 |= V_80 ;
if ( V_67 )
return - V_69 * pow ( 2 , V_68 ) ;
else
return V_69 * pow ( 2 , V_68 ) ;
}
T_14
F_88 ( T_1 * V_3 , const int V_25 )
{
#if F_96 ( V_81 )
return F_93 ( F_52 ( V_3 , V_25 ) ) ;
#else
union {
T_14 V_82 ;
T_5 V_65 ;
} V_83 ;
V_83 . V_65 = F_52 ( V_3 , V_25 ) ;
return V_83 . V_82 ;
#endif
}
T_15
F_91 ( T_1 * V_3 , const int V_25 )
{
#if F_96 ( V_81 )
union {
T_5 V_65 [ 2 ] ;
T_9 V_84 ;
} V_83 ;
#else
union {
T_15 V_85 ;
T_5 V_65 [ 2 ] ;
} V_83 ;
#endif
#ifdef F_97
V_83 . V_65 [ 0 ] = F_52 ( V_3 , V_25 ) ;
V_83 . V_65 [ 1 ] = F_52 ( V_3 , V_25 + 4 ) ;
#else
V_83 . V_65 [ 0 ] = F_52 ( V_3 , V_25 + 4 ) ;
V_83 . V_65 [ 1 ] = F_52 ( V_3 , V_25 ) ;
#endif
#if F_96 ( V_81 )
return F_95 ( V_83 . V_84 ) ;
#else
return V_83 . V_85 ;
#endif
}
T_12
F_67 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_12 ) ) ;
return F_98 ( V_61 ) ;
}
T_5
F_69 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 3 ) ;
return F_99 ( V_61 ) ;
}
T_5
F_71 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
return F_100 ( V_61 ) ;
}
T_9
F_73 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 5 ) ;
return F_101 ( V_61 ) ;
}
T_13
F_75 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_73 ( V_3 , V_25 ) , 40 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_77 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 6 ) ;
return F_102 ( V_61 ) ;
}
T_13
F_79 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_77 ( V_3 , V_25 ) , 48 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_81 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , 7 ) ;
return F_103 ( V_61 ) ;
}
T_13
F_83 ( T_1 * V_3 , const T_4 V_25 )
{
T_9 V_62 ;
V_62 = F_57 ( F_81 ( V_3 , V_25 ) , 56 ) ;
return ( T_13 ) V_62 ;
}
T_9
F_85 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_9 ) ) ;
return F_104 ( V_61 ) ;
}
T_14
F_87 ( T_1 * V_3 , const int V_25 )
{
#if F_96 ( V_81 )
return F_93 ( F_71 ( V_3 , V_25 ) ) ;
#else
union {
T_14 V_82 ;
T_5 V_65 ;
} V_83 ;
V_83 . V_65 = F_71 ( V_3 , V_25 ) ;
return V_83 . V_82 ;
#endif
}
T_15
F_90 ( T_1 * V_3 , const int V_25 )
{
#if F_96 ( V_81 )
union {
T_5 V_65 [ 2 ] ;
T_9 V_84 ;
} V_83 ;
#else
union {
T_15 V_85 ;
T_5 V_65 [ 2 ] ;
} V_83 ;
#endif
#ifdef F_97
V_83 . V_65 [ 0 ] = F_71 ( V_3 , V_25 + 4 ) ;
V_83 . V_65 [ 1 ] = F_71 ( V_3 , V_25 ) ;
#else
V_83 . V_65 [ 0 ] = F_71 ( V_3 , V_25 ) ;
V_83 . V_65 [ 1 ] = F_71 ( V_3 , V_25 + 4 ) ;
#endif
#if F_96 ( V_81 )
return F_95 ( V_83 . V_84 ) ;
#else
return V_83 . V_85 ;
#endif
}
static inline void
F_105 ( const T_3 V_63 )
{
const T_3 V_86 = V_63 & ~ V_87 ;
switch ( V_86 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_106 ( L_1 ) ;
break;
default:
break;
}
if ( V_86 == 0 )
F_106 ( L_2 ) ;
}
T_16 *
F_107 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 ,
const T_3 V_63 , T_16 * V_93 , T_4 * V_94 )
{
const T_17 * V_61 = ( T_17 * ) F_108 ( F_109 () , V_3 , V_25 , V_9 ) ;
const T_17 * V_95 = V_61 ;
const T_17 * V_96 = NULL ;
T_16 * V_97 = NULL ;
V_98 = V_99 ;
F_105 ( V_63 ) ;
if ( V_94 ) * V_94 = 0 ;
while ( * V_95 == ' ' ) V_95 ++ ;
if ( * V_95 && V_93 ) {
if ( F_110 ( V_95 , V_93 , & V_96 , V_63 , FALSE ) ) {
if ( V_93 -> V_45 > 0 ) {
if ( V_94 ) * V_94 = V_25 + ( T_4 ) ( V_96 - V_61 ) ;
V_98 = 0 ;
V_97 = V_93 ;
}
}
}
return V_97 ;
}
T_18 *
F_111 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_9 ,
const T_3 V_63 , T_18 * V_100 , T_4 * V_94 )
{
const T_17 * V_95 = ( T_17 * ) F_108 ( F_109 () , V_3 , V_25 , V_9 ) ;
const T_17 * V_61 = V_95 ;
const T_17 * V_96 = NULL ;
struct V_101 V_101 ;
T_18 * V_97 = NULL ;
char V_67 = '+' ;
int V_102 = 0 ;
int V_103 = 0 ;
int V_104 = 0 ;
T_8 V_105 = FALSE ;
V_98 = V_99 ;
F_105 ( V_63 ) ;
F_5 ( V_100 ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_106 = - 1 ;
V_100 -> V_107 = 0 ;
V_100 -> V_108 = 0 ;
while ( * V_61 == ' ' ) V_61 ++ ;
if ( * V_61 ) {
if ( ( V_63 & V_109 ) == V_109 ) {
if ( sscanf ( V_61 , L_3 ,
& V_101 . V_110 ,
& V_101 . V_111 ,
& V_101 . V_112 ,
& V_101 . V_113 ,
& V_101 . V_114 ,
& V_101 . V_115 ,
& V_67 ,
& V_102 ,
& V_103 ,
& V_104 ) >= 9 )
{
V_105 = TRUE ;
}
else if ( sscanf ( V_61 , L_4 ,
& V_101 . V_110 ,
& V_101 . V_111 ,
& V_101 . V_112 ,
& V_101 . V_113 ,
& V_101 . V_114 ,
& V_67 ,
& V_102 ,
& V_103 ,
& V_104 ) >= 8 )
{
V_105 = TRUE ;
}
else if ( sscanf ( V_61 , L_5 ,
& V_101 . V_110 ,
& V_101 . V_111 ,
& V_101 . V_112 ,
& V_101 . V_113 ,
& V_101 . V_114 ,
& V_101 . V_115 ,
& V_104 ) >= 6 )
{
V_105 = TRUE ;
V_102 = 0 ;
V_103 = 0 ;
}
else if ( sscanf ( V_61 , L_6 ,
& V_101 . V_110 ,
& V_101 . V_111 ,
& V_101 . V_112 ,
& V_101 . V_113 ,
& V_101 . V_114 ,
& V_104 ) >= 5 )
{
V_105 = TRUE ;
V_102 = 0 ;
V_103 = 0 ;
}
if ( V_105 ) {
V_98 = 0 ;
V_96 = V_61 + V_104 ;
V_101 . V_111 -- ;
if ( V_101 . V_110 > 1900 ) V_101 . V_110 -= 1900 ;
if ( V_67 == '-' ) V_102 = - V_102 ;
}
}
else if ( V_63 & V_116 ) {
if ( sscanf ( V_61 , L_7 ,
& V_101 . V_110 ,
& V_101 . V_111 ,
& V_101 . V_112 ,
& V_104 ) >= 3 )
{
V_98 = 0 ;
V_96 = V_61 + V_104 ;
V_101 . V_111 -- ;
if ( V_101 . V_110 > 1900 ) V_101 . V_110 -= 1900 ;
}
}
else if ( V_63 & V_117 ) {
if ( sscanf ( V_61 , L_8 ,
& V_101 . V_113 ,
& V_101 . V_114 ,
& V_101 . V_115 ,
& V_104 ) >= 2 )
{
T_19 V_118 = time ( NULL ) ;
struct V_101 * V_119 = gmtime ( & V_118 ) ;
if ( V_119 != NULL ) {
V_101 . V_110 = V_119 -> V_110 ;
V_101 . V_111 = V_119 -> V_111 ;
V_101 . V_112 = V_119 -> V_112 ;
} else {
V_101 . V_110 = 69 ;
V_101 . V_111 = 12 ;
V_101 . V_112 = 31 ;
}
V_96 = V_61 + V_104 ;
V_98 = 0 ;
}
}
else if ( V_63 & V_120 || V_63 & V_121 ) {
if ( V_63 & V_120 ) {
V_96 = strptime ( V_61 , L_9 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_10 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_11 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_12 , & V_101 ) ;
}
else if ( V_63 & V_121 ) {
V_96 = strptime ( V_61 , L_13 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_14 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_15 , & V_101 ) ;
if ( ! V_96 ) V_96 = strptime ( V_61 , L_16 , & V_101 ) ;
}
if ( V_96 ) {
V_98 = 0 ;
if ( * V_96 == ' ' ) V_96 ++ ;
if ( F_112 ( V_96 , L_17 , 2 ) == 0 )
{
V_96 += 2 ;
}
else if ( F_112 ( V_96 , L_18 , 3 ) == 0 )
{
V_96 += 3 ;
}
else if ( sscanf ( V_96 , L_19 ,
& V_67 ,
& V_102 ,
& V_103 ,
& V_104 ) < 3 )
{
V_98 = V_122 ;
}
if ( V_67 == '-' ) V_102 = - V_102 ;
}
}
}
if ( V_98 == 0 ) {
V_100 -> V_107 = F_113 ( & V_101 ) ;
if ( V_102 > 0 )
V_100 -> V_107 += ( V_102 * 3600 ) + ( V_103 * 60 ) ;
else if ( V_102 < 0 )
V_100 -> V_107 -= ( ( - V_102 ) * 3600 ) + ( V_103 * 60 ) ;
V_97 = V_100 ;
if ( V_94 )
* V_94 = ( T_4 ) ( V_25 + ( V_96 - V_95 ) ) ;
}
return V_97 ;
}
T_5
F_114 ( T_1 * V_3 , const T_4 V_25 )
{
const T_7 * V_61 ;
T_5 V_123 ;
V_61 = F_44 ( V_3 , V_25 , sizeof( T_5 ) ) ;
memcpy ( & V_123 , V_61 , sizeof V_123 ) ;
return V_123 ;
}
void
F_115 ( T_1 * V_3 , const T_4 V_25 , struct V_124 * V_123 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , sizeof( * V_123 ) ) ;
memcpy ( V_123 , V_61 , sizeof *V_123 ) ;
}
void
F_116 ( T_1 * V_3 , const T_4 V_25 , T_20 * V_125 )
{
const T_7 * V_61 = F_22 ( V_3 , V_25 , V_126 ) ;
V_125 -> V_127 = F_53 ( V_61 + 0 ) ;
V_125 -> V_128 = F_49 ( V_61 + 4 ) ;
V_125 -> V_129 = F_49 ( V_61 + 6 ) ;
memcpy ( V_125 -> V_130 , V_61 + 8 , sizeof V_125 -> V_130 ) ;
}
void
F_117 ( T_1 * V_3 , const T_4 V_25 , T_20 * V_125 )
{
const T_7 * V_61 = F_22 ( V_3 , V_25 , V_126 ) ;
V_125 -> V_127 = F_100 ( V_61 + 0 ) ;
V_125 -> V_128 = F_98 ( V_61 + 4 ) ;
V_125 -> V_129 = F_98 ( V_61 + 6 ) ;
memcpy ( V_125 -> V_130 , V_61 + 8 , sizeof V_125 -> V_130 ) ;
}
void
F_118 ( T_1 * V_3 , const T_4 V_25 , T_20 * V_125 , const T_3 V_63 )
{
if ( V_63 ) {
F_117 ( V_3 , V_25 , V_125 ) ;
} else {
F_116 ( V_3 , V_25 , V_125 ) ;
}
}
T_7
F_119 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 )
{
return ( T_7 ) F_120 ( V_3 , V_32 , V_33 ) ;
}
T_12
F_121 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_63 V_131 )
{
return ( T_12 ) F_120 ( V_3 , V_32 , V_33 ) ;
}
T_5
F_122 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_63 V_131 )
{
return ( T_5 ) F_120 ( V_3 , V_32 , V_33 ) ;
}
T_9
F_123 ( T_1 * V_3 , T_3 V_32 , const T_4 V_33 , const T_3 V_63 V_131 )
{
return F_120 ( V_3 , V_32 , V_33 ) ;
}
static T_9
F_120 ( T_1 * V_3 , T_3 V_32 , const T_4 V_132 )
{
T_9 V_133 ;
T_3 V_134 = V_32 >> 3 ;
T_7 V_135 = 8 - ( V_32 % 8 ) ;
if( V_135 > V_132 )
{
T_7 V_136 = V_135 - V_132 ;
V_133 = ( F_47 ( V_3 , V_134 ) >> V_136 ) & V_137 [ V_132 % 8 ] ;
}
else
{
T_7 V_138 = V_132 ;
V_133 = 0 ;
V_135 %= 8 ;
if( V_135 != 0 )
{
V_133 = F_47 ( V_3 , V_134 ) & V_137 [ V_135 ] ;
V_138 -= V_135 ;
V_134 ++ ;
}
while ( V_138 > 7 )
{
switch ( V_138 >> 4 )
{
case 0 :
V_133 <<= 8 ;
V_133 += F_47 ( V_3 , V_134 ) ;
V_138 -= 8 ;
V_134 ++ ;
break;
case 1 :
V_133 <<= 16 ;
V_133 += F_48 ( V_3 , V_134 ) ;
V_138 -= 16 ;
V_134 += 2 ;
break;
case 2 :
case 3 :
V_133 <<= 32 ;
V_133 += F_52 ( V_3 , V_134 ) ;
V_138 -= 32 ;
V_134 += 4 ;
break;
default:
V_133 = F_64 ( V_3 , V_134 ) ;
V_138 -= 64 ;
V_134 += 8 ;
break;
}
}
if( V_138 )
{
V_133 <<= V_138 ;
V_133 += ( F_47 ( V_3 , V_134 ) >> ( 8 - V_138 ) ) ;
}
}
return V_133 ;
}
T_5
F_124 ( T_1 * V_3 , const T_3 V_32 , const T_4 V_33 , const T_3 V_63 V_131 )
{
return ( T_5 ) F_120 ( V_3 , V_32 , V_33 ) ;
}
static T_4
F_125 ( T_1 * V_3 , T_3 V_20 , T_3 V_139 , T_7 V_140 )
{
const T_7 * V_61 ;
const T_7 * V_141 ;
V_61 = F_22 ( V_3 , V_20 , V_139 ) ;
V_141 = ( const T_7 * ) memchr ( V_61 , V_140 , V_139 ) ;
if ( ! V_141 )
return - 1 ;
return ( T_4 ) ( ( V_141 - V_61 ) + V_20 ) ;
}
T_4
F_126 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 , const T_7 V_140 )
{
const T_7 * V_141 ;
T_3 V_20 = 0 ;
T_3 V_139 = 0 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_139 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_142 >= 0 && V_139 > ( T_3 ) V_142 ) {
V_139 = ( T_3 ) V_142 ;
}
if ( V_3 -> V_11 ) {
V_141 = ( const T_7 * ) memchr ( V_3 -> V_11 + V_20 , V_140 , V_139 ) ;
if ( V_141 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_141 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_126 )
return V_3 -> V_2 -> F_126 ( V_3 , V_20 , V_139 , V_140 ) ;
return F_125 ( V_3 , V_25 , V_139 , V_140 ) ;
}
T_4
F_127 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 ,
const T_12 V_140 )
{
const T_7 V_143 = ( ( V_140 & 0xFF00 ) >> 8 ) ;
const T_7 V_144 = ( ( V_140 & 0x00FF ) >> 0 ) ;
T_4 V_145 = 0 ;
T_4 V_146 = V_25 ;
do {
T_4 V_147 =
F_126 ( V_3 , V_146 , V_142 - V_145 , V_143 ) ;
T_4 V_148 = - 1 ;
if ( V_147 == - 1 ) {
return - 1 ;
}
V_145 = V_25 - V_146 + 1 ;
if ( ( V_142 != - 1 ) && ( V_145 >= V_142 ) ) {
return - 1 ;
}
V_148 = F_126 ( V_3 , V_147 + 1 , 1 , V_144 ) ;
V_145 += 1 ;
if ( V_148 != - 1 ) {
if ( ( V_142 != - 1 ) && ( V_145 > V_142 ) ) {
return - 1 ;
}
return V_147 ;
}
V_146 = V_147 + 1 ;
} while ( V_145 < V_142 );
return - 1 ;
}
static inline T_4
F_128 ( T_1 * V_3 , T_3 V_20 , T_3 V_139 , const T_21 * V_149 , T_22 * V_150 )
{
const T_7 * V_61 ;
const T_7 * V_141 ;
V_61 = F_22 ( V_3 , V_20 , V_139 ) ;
V_141 = F_129 ( V_61 , V_139 , V_149 , V_150 ) ;
if ( ! V_141 )
return - 1 ;
return ( T_4 ) ( ( V_141 - V_61 ) + V_20 ) ;
}
T_4
F_130 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 ,
const T_21 * V_149 , T_22 * V_150 )
{
const T_7 * V_141 ;
T_3 V_20 = 0 ;
T_3 V_139 = 0 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_139 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_139 > ( T_3 ) V_142 ) {
V_139 = V_142 ;
}
if ( V_3 -> V_11 ) {
V_141 = F_129 ( V_3 -> V_11 + V_20 , V_139 , V_149 , V_150 ) ;
if ( V_141 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_141 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_130 )
return V_3 -> V_2 -> F_130 ( V_3 , V_20 , V_139 , V_149 , V_150 ) ;
return F_128 ( V_3 , V_20 , V_139 , V_149 , V_150 ) ;
}
T_3
F_131 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 = 0 , V_151 ;
T_4 V_152 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_151 ) ;
V_152 = F_126 ( V_3 , V_20 , - 1 , 0 ) ;
if ( V_152 == - 1 ) {
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
return ( V_152 - V_20 ) + 1 ;
}
T_3
F_132 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_37 = 0 ;
T_23 V_153 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
do {
V_153 = F_48 ( V_3 , V_25 + V_37 ) ;
V_37 += 2 ;
} while( V_153 != 0 );
return V_37 ;
}
T_4
F_133 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_142 )
{
T_4 V_154 ;
T_3 V_20 = 0 , V_151 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_151 ) ;
V_154 = F_126 ( V_3 , V_20 , V_142 , 0 ) ;
if ( V_154 == - 1 ) {
return - 1 ;
}
else {
return V_154 - V_20 ;
}
}
T_4
F_134 ( T_1 * V_3 , const T_4 V_25 , const T_17 * V_155 , const T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_156 = strncmp ( ( const char * ) V_61 , V_155 , V_4 ) ;
return ( V_156 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_135 ( T_1 * V_3 , const T_4 V_25 , const T_17 * V_155 , const T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_156 = F_112 ( ( const char * ) V_61 , V_155 , V_4 ) ;
return ( V_156 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_136 ( T_1 * V_3 , const T_4 V_25 , const T_7 * V_155 , T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_156 = memcmp ( V_61 , V_155 , V_4 ) ;
return ( V_156 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_17 *
F_137 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_138 ( F_109 () , V_61 , V_45 ) ;
}
T_17 *
F_139 ( T_11 * V_157 , T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_140 ( V_157 , V_61 , V_45 ) ;
}
T_17 *
F_141 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 , * V_56 ;
T_4 V_45 ;
T_4 V_158 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_61 , V_158 = 0 ; V_158 < V_45 && * V_56 != '\0' ; V_56 ++ , V_158 ++ )
;
return F_138 ( F_109 () , V_61 , V_158 ) ;
}
T_17 *
F_142 ( T_11 * V_157 , T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 , * V_56 ;
T_4 V_45 ;
T_4 V_158 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_61 , V_158 = 0 ; V_158 < V_45 && * V_56 != '\0' ; V_56 ++ , V_158 ++ )
;
return F_140 ( V_157 , V_61 , V_158 ) ;
}
static T_7 *
F_143 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_144 ( V_59 , V_61 , V_9 ) ;
}
static T_7 *
F_145 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_159 ;
F_35 ( V_3 , V_25 , V_9 ) ;
V_159 = ( T_7 * ) F_46 ( V_59 , V_9 + 1 ) ;
F_28 ( V_3 , V_159 , V_25 , V_9 ) ;
V_159 [ V_9 ] = '\0' ;
return V_159 ;
}
static inline T_7 *
F_108 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_159 ;
T_4 V_49 = V_9 ;
F_5 ( V_25 >= 0 ) ;
F_5 ( V_49 >= - 1 ) ;
if ( V_49 < 0 )
V_49 = V_3 -> V_9 - V_25 ;
F_35 ( V_3 , V_25 , V_49 ) ;
V_159 = ( T_7 * ) F_46 ( V_59 , V_49 + 1 ) ;
F_28 ( V_3 , V_159 , V_25 , V_49 ) ;
V_159 [ V_49 ] = '\0' ;
return V_159 ;
}
static T_7 *
F_146 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_147 ( V_59 , V_61 , V_9 ) ;
}
static T_7 *
F_148 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 , const T_23 V_160 [ 0x80 ] )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_149 ( V_59 , V_61 , V_9 , V_160 ) ;
}
static T_7 *
F_150 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_151 ( V_59 , V_61 , V_9 , V_63 ) ;
}
static T_7 *
F_152 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_153 ( V_59 , V_61 , V_9 , V_63 ) ;
}
static T_17 *
F_154 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_155 ( V_59 , V_61 , V_9 , V_63 ) ;
}
T_17 *
F_156 ( T_11 * V_59 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_161 )
{
T_4 V_162 = V_32 >> 3 ;
T_4 V_9 = ( ( V_161 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_61 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_61 = F_22 ( V_3 , V_162 , V_9 ) ;
return F_157 ( V_59 , V_61 , V_32 , V_161 ) ;
}
T_17 *
F_158 ( T_11 * V_59 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_161 )
{
T_4 V_162 = V_32 >> 3 ;
T_4 V_9 = ( ( V_161 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_61 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_61 = F_22 ( V_3 , V_162 , V_9 ) ;
return F_159 ( V_59 , V_61 , V_32 , V_161 ) ;
}
static T_7 *
F_160 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 , const T_23 V_160 [ 256 ] )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_161 ( V_59 , V_61 , V_9 , V_160 ) ;
}
static T_7 *
F_162 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_163 ( V_59 , V_61 , V_9 ) ;
}
T_7 *
F_164 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_63 )
{
T_7 * V_163 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_17 ( V_24 ) ;
}
switch ( V_63 & V_164 ) {
case V_165 :
default:
V_163 = F_143 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_166 :
V_163 = F_145 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_88 :
V_163 = F_152 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_89 :
V_163 = F_150 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_90 :
V_163 = F_154 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_167 :
V_163 = F_146 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_168 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_169 ) ;
break;
case V_170 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_171 ) ;
break;
case V_172 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_173 ) ;
break;
case V_174 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_175 ) ;
break;
case V_176 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_177 ) ;
break;
case V_178 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_179 ) ;
break;
case V_180 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_181 ) ;
break;
case V_182 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_183 ) ;
break;
case V_184 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_185 ) ;
break;
case V_186 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_187 ) ;
break;
case V_188 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_189 ) ;
break;
case V_190 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_191 ) ;
break;
case V_192 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_193 ) ;
break;
case V_194 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_195 ) ;
break;
case V_196 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_197 ) ;
break;
case V_198 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_199 ) ;
break;
case V_200 :
V_163 = F_148 ( V_59 , V_3 , V_25 , V_9 , V_201 ) ;
break;
case V_91 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_161 = ( V_9 << 3 ) / 7 ;
V_163 = F_156 ( V_59 , V_3 , V_32 , V_161 ) ;
}
break;
case V_202 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_161 = ( V_9 << 3 ) / 7 ;
V_163 = F_158 ( V_59 , V_3 , V_32 , V_161 ) ;
}
break;
case V_92 :
V_163 = F_160 ( V_59 , V_3 , V_25 , V_9 , V_203 ) ;
break;
case V_204 :
V_163 = F_160 ( V_59 , V_3 , V_25 , V_9 , V_205 ) ;
break;
case V_206 :
V_163 = F_162 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
}
return V_163 ;
}
T_7 *
F_165 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_63 )
{
return F_164 ( V_59 , V_3 , V_25 , V_9 , V_63 ) ;
}
static T_7 *
F_166 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_207 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_144 ( V_59 , V_61 , V_4 ) ;
}
static T_7 *
F_167 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_207 )
{
T_3 V_4 ;
T_7 * V_163 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_163 = ( T_7 * ) F_46 ( V_59 , V_4 ) ;
F_28 ( V_3 , V_163 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return V_163 ;
}
static T_7 *
F_168 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_207 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_147 ( V_59 , V_61 , V_4 ) ;
}
static T_7 *
F_169 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_207 , const T_23 V_160 [ 0x80 ] )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_149 ( V_59 , V_61 , V_4 , V_160 ) ;
}
const T_7 *
F_170 ( T_1 * V_3 , const T_4 V_25 , T_4 * V_207 )
{
T_3 V_4 ;
const T_7 * V_163 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_163 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return V_163 ;
}
static T_17 *
F_171 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_207 , const T_3 V_63 )
{
T_4 V_4 ;
const T_7 * V_61 ;
V_4 = F_132 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_151 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_17 *
F_172 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_207 , const T_3 V_63 )
{
T_4 V_4 ;
const T_7 * V_61 ;
V_4 = F_132 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_153 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_17 *
F_173 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_207 , const T_3 V_63 )
{
T_4 V_4 ;
T_24 V_153 ;
const T_7 * V_61 ;
V_4 = 0 ;
do {
V_153 = F_52 ( V_3 , V_25 + V_4 ) ;
V_4 += 4 ;
} while( V_153 != 0 );
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_155 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_7 *
F_174 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_207 , const T_23 V_160 [ 256 ] )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_161 ( V_59 , V_61 , V_4 , V_160 ) ;
}
static T_7 *
F_175 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_207 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_207 )
* V_207 = V_4 ;
return F_163 ( V_59 , V_61 , V_4 ) ;
}
T_7 *
F_176 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_207 , const T_3 V_63 )
{
T_7 * V_163 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
switch ( V_63 & V_164 ) {
case V_165 :
default:
V_163 = F_166 ( V_59 , V_3 , V_25 , V_207 ) ;
break;
case V_166 :
V_163 = F_167 ( V_59 , V_3 , V_25 , V_207 ) ;
break;
case V_88 :
V_163 = F_172 ( V_59 , V_3 , V_25 , V_207 ,
V_63 & V_64 ) ;
break;
case V_89 :
V_163 = F_171 ( V_59 , V_3 , V_25 , V_207 ,
V_63 & V_64 ) ;
break;
case V_90 :
V_163 = F_173 ( V_59 , V_3 , V_25 , V_207 ,
V_63 & V_64 ) ;
break;
case V_167 :
V_163 = F_168 ( V_59 , V_3 , V_25 , V_207 ) ;
break;
case V_168 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_169 ) ;
break;
case V_170 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_171 ) ;
break;
case V_172 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_173 ) ;
break;
case V_174 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_175 ) ;
break;
case V_176 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_177 ) ;
break;
case V_178 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_179 ) ;
break;
case V_180 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_181 ) ;
break;
case V_182 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_183 ) ;
break;
case V_184 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_185 ) ;
break;
case V_186 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_187 ) ;
break;
case V_188 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_189 ) ;
break;
case V_190 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_191 ) ;
break;
case V_192 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_193 ) ;
break;
case V_194 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_195 ) ;
break;
case V_196 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_197 ) ;
break;
case V_198 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_199 ) ;
break;
case V_200 :
V_163 = F_169 ( V_59 , V_3 , V_25 , V_207 , V_201 ) ;
break;
case V_91 :
F_106 ( L_20 ) ;
break;
case V_202 :
F_106 ( L_21 ) ;
break;
case V_92 :
V_163 = F_174 ( V_59 , V_3 , V_25 , V_207 , V_203 ) ;
break;
case V_204 :
V_163 = F_174 ( V_59 , V_3 , V_25 , V_207 , V_205 ) ;
break;
case V_206 :
V_163 = F_175 ( V_59 , V_3 , V_25 , V_207 ) ;
break;
}
return V_163 ;
}
static T_4
F_177 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_208 , T_7 * V_209 , T_4 * V_210 )
{
T_4 V_158 ;
T_3 V_20 = 0 ;
T_4 V_139 , V_45 = 0 ;
T_8 V_211 = FALSE ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_45 ) ;
F_5 ( V_208 != 0 ) ;
if ( V_208 == 1 ) {
V_209 [ 0 ] = 0 ;
* V_210 = 1 ;
return 0 ;
}
if ( V_45 == 0 ) {
F_17 ( V_24 ) ;
}
F_5 ( V_45 != - 1 ) ;
F_5 ( V_208 <= V_50 ) ;
if ( ( T_3 ) V_45 < V_208 ) {
V_139 = V_45 ;
V_211 = TRUE ;
}
else {
V_139 = V_208 ;
}
V_158 = F_133 ( V_3 , V_20 , V_139 - 1 ) ;
if ( V_158 == - 1 ) {
F_28 ( V_3 , V_209 , V_20 , V_139 ) ;
if ( V_211 ) {
V_209 [ V_139 ] = 0 ;
* V_210 = V_139 + 1 ;
}
else {
* V_210 = V_139 ;
}
return - 1 ;
}
F_28 ( V_3 , V_209 , V_20 , V_158 + 1 ) ;
* V_210 = V_158 + 1 ;
return V_158 ;
}
T_4
F_178 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_208 , T_7 * V_209 )
{
T_4 V_210 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
return F_177 ( V_3 , V_25 , V_208 , V_209 , & V_210 ) ;
}
T_4
F_179 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_208 , T_7 * V_209 )
{
T_4 V_45 , V_210 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_45 = F_177 ( V_3 , V_25 , V_208 , V_209 , & V_210 ) ;
if ( V_45 == - 1 ) {
V_209 [ V_208 - 1 ] = 0 ;
return V_210 - 1 ;
}
else {
return V_45 ;
}
}
T_4
F_180 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_212 , const T_8 V_213 )
{
T_4 V_214 ;
T_4 V_215 ;
int V_216 ;
T_22 V_150 = 0 ;
static T_8 V_217 = FALSE ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 ) {
V_45 = F_20 ( V_3 , V_25 ) ;
}
V_214 = V_25 + V_45 ;
if ( ! V_217 ) {
F_181 ( & V_218 , L_22 ) ;
V_217 = TRUE ;
}
V_215 = F_130 ( V_3 , V_25 , V_45 , & V_218 , & V_150 ) ;
if ( V_215 == - 1 ) {
if ( V_213 ) {
return - 1 ;
} else {
V_216 = V_214 - V_25 ;
if ( V_212 )
* V_212 = V_214 ;
}
} else {
V_216 = V_215 - V_25 ;
if ( V_150 == '\r' ) {
if ( V_215 + 1 >= V_214 ) {
if ( V_213 ) {
return - 1 ;
}
} else {
if ( F_47 ( V_3 , V_215 + 1 ) == '\n' ) {
V_215 ++ ;
}
}
}
if ( V_212 )
* V_212 = V_215 + 1 ;
}
return V_216 ;
}
T_4
F_182 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_212 )
{
T_4 V_219 , V_220 ;
T_8 V_221 ;
T_22 V_222 = 0 ;
T_4 V_214 ;
int V_216 ;
static T_8 V_217 = FALSE ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
if ( ! V_217 ) {
F_181 ( & V_223 , L_23 ) ;
V_217 = TRUE ;
}
V_214 = V_25 + V_45 ;
V_219 = V_25 ;
V_221 = FALSE ;
for (; ; ) {
if ( V_221 ) {
V_220 = F_126 ( V_3 , V_219 , V_45 ,
'"' ) ;
} else {
V_220 = F_130 ( V_3 , V_219 , V_45 , & V_223 , & V_222 ) ;
}
if ( V_220 == - 1 ) {
V_216 = V_214 - V_25 ;
if ( V_212 )
* V_212 = V_214 ;
break;
}
if ( V_221 ) {
V_221 = FALSE ;
} else {
if ( V_222 == '"' ) {
V_221 = TRUE ;
} else {
V_216 = V_220 - V_25 ;
if ( V_222 == '\r' ) {
if ( V_220 + 1 < V_214 &&
F_47 ( V_3 , V_220 + 1 )
== '\n' ) {
V_220 ++ ;
}
}
if ( V_212 )
* V_212 = V_220 + 1 ;
break;
}
}
V_219 = V_220 + 1 ;
if ( V_219 >= V_214 ) {
V_216 = V_214 - V_25 ;
if ( V_212 )
* V_212 = V_214 ;
break;
}
}
return V_216 ;
}
T_4
F_183 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 )
{
T_4 V_52 = V_25 ;
T_4 V_96 , V_224 ;
T_7 V_225 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_224 = V_3 -> V_9 ;
V_96 = V_25 + V_142 ;
if ( V_96 >= V_224 )
{
V_96 = V_224 ;
}
for ( V_52 = V_25 ;
V_52 < V_96 &&
( ( V_225 = F_47 ( V_3 , V_52 ) ) == ' ' ||
V_225 == '\t' || V_225 == '\r' || V_225 == '\n' ) ;
V_52 ++ ) ;
return ( V_52 ) ;
}
T_4
F_184 ( T_1 * V_3 , const T_4 V_25 ) {
T_4 V_52 = V_25 ;
T_7 V_225 ;
for( V_52 = V_25 ; V_52 > 0 &&
( ( V_225 = F_47 ( V_3 , V_52 ) ) == ' ' ||
V_225 == '\t' || V_225 == '\n' || V_225 == '\r' ) ; V_52 -- ) ;
V_52 ++ ;
return ( V_52 ) ;
}
int
F_185 ( T_1 * V_3 , int V_25 , const int V_142 , const T_7 V_226 )
{
int V_96 , V_224 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_224 = V_3 -> V_9 ;
V_96 = V_25 + V_142 ;
if ( V_96 >= V_224 )
V_96 = V_224 ;
while ( V_25 < V_96 ) {
T_7 V_227 = F_47 ( V_3 , V_25 ) ;
if ( V_227 != V_226 )
break;
V_25 ++ ;
}
return V_25 ;
}
T_17 *
F_186 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , const T_17 V_228 )
{
return F_187 ( V_59 , F_22 ( V_3 , V_25 , V_45 ) , V_45 , V_228 ) ;
}
const T_17 *
F_188 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , const T_25 * V_229 , T_8 V_230 )
{
int V_9 ;
T_7 V_231 ;
int V_37 = 0 ;
char * V_232 ;
T_4 V_233 = V_25 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( ! V_229 )
V_229 = & V_234 ;
if ( V_45 == - 1 ) {
V_9 = V_3 -> V_9 ;
if ( V_9 < V_25 ) {
return L_24 ;
}
} else {
V_9 = V_25 + V_45 ;
}
V_232 = ( char * ) F_46 ( F_109 () , ( V_9 - V_25 ) * 2 + 1 ) ;
while ( V_233 < V_9 ) {
V_231 = F_47 ( V_3 , V_233 ) ;
if ( ! V_230 ) {
V_232 [ V_37 ] = V_229 -> V_235 [ V_231 & 0x0f ] ;
V_37 ++ ;
}
V_230 = FALSE ;
V_231 = V_231 >> 4 ;
if ( V_233 == V_9 - 1 && V_231 == 0x0f ) {
break;
}
V_232 [ V_37 ] = V_229 -> V_235 [ V_231 & 0x0f ] ;
V_37 ++ ;
V_233 ++ ;
}
V_232 [ V_37 ] = '\0' ;
return V_232 ;
}
T_17 * F_189 ( T_11 * V_157 , T_1 * V_3 ,
const T_4 V_25 , const T_4 V_45 )
{
return F_190 ( V_157 , F_22 ( V_3 , V_25 , V_45 ) , V_45 ) ;
}
T_4
F_191 ( T_1 * V_236 , T_1 * V_237 , const T_4 V_238 )
{
T_3 V_239 = 0 , V_240 = 0 ;
const T_7 * V_241 ;
const T_7 * V_242 ;
const T_3 V_243 = V_237 -> V_9 ;
const T_7 * V_244 ;
F_5 ( V_236 && V_236 -> V_7 ) ;
if ( V_236 -> V_9 < 1 || V_237 -> V_9 < 1 ) {
return - 1 ;
}
V_241 = F_22 ( V_236 , 0 , - 1 ) ;
V_242 = F_22 ( V_237 , 0 , - 1 ) ;
F_16 ( V_236 , V_238 , - 1 ,
& V_239 , & V_240 ) ;
V_244 = F_192 ( V_241 + V_239 , V_240 ,
V_242 , V_243 ) ;
if ( V_244 ) {
return ( T_4 ) ( V_244 - V_241 ) ;
}
return - 1 ;
}
T_4
F_193 ( T_1 * V_3 )
{
return ( ( V_3 -> V_12 == - 1 ) ? ( V_3 -> V_12 = F_42 ( V_3 ) ) : V_3 -> V_12 ) ;
}
void
F_194 ( T_1 * V_3 )
{
V_3 -> V_8 |= V_22 ;
}
struct V_245 *
F_195 ( T_1 * V_3 )
{
return ( V_3 -> V_13 ) ;
}
