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
void *
F_28 ( T_1 * V_3 , void * V_58 , const T_4 V_25 , T_10 V_9 )
{
T_3 V_20 , V_49 ;
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
T_3 V_20 , V_49 ;
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
V_101 . V_110 = V_119 -> V_110 ;
V_101 . V_111 = V_119 -> V_111 ;
V_101 . V_112 = V_119 -> V_112 ;
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
T_3 V_20 ;
T_3 V_139 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_139 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_139 > ( T_3 ) V_142 ) {
V_139 = V_142 ;
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
static inline T_4
F_127 ( T_1 * V_3 , T_3 V_20 , T_3 V_139 , const T_21 * V_143 , T_22 * V_144 )
{
const T_7 * V_61 ;
const T_7 * V_141 ;
V_61 = F_22 ( V_3 , V_20 , V_139 ) ;
V_141 = F_128 ( V_61 , V_139 , V_143 , V_144 ) ;
if ( ! V_141 )
return - 1 ;
return ( T_4 ) ( ( V_141 - V_61 ) + V_20 ) ;
}
T_4
F_129 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 ,
const T_21 * V_143 , T_22 * V_144 )
{
const T_7 * V_141 ;
T_3 V_20 ;
T_3 V_139 ;
int V_28 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_28 = F_14 ( V_3 , V_25 , & V_20 , & V_139 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
if ( V_139 > ( T_3 ) V_142 ) {
V_139 = V_142 ;
}
if ( V_3 -> V_11 ) {
V_141 = F_128 ( V_3 -> V_11 + V_20 , V_139 , V_143 , V_144 ) ;
if ( V_141 == NULL ) {
return - 1 ;
}
else {
return ( T_4 ) ( V_141 - V_3 -> V_11 ) ;
}
}
if ( V_3 -> V_2 -> F_129 )
return V_3 -> V_2 -> F_129 ( V_3 , V_20 , V_139 , V_143 , V_144 ) ;
return F_127 ( V_3 , V_20 , V_139 , V_143 , V_144 ) ;
}
T_3
F_130 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_20 , V_145 ;
T_4 V_146 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_145 ) ;
V_146 = F_126 ( V_3 , V_20 , - 1 , 0 ) ;
if ( V_146 == - 1 ) {
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
return ( V_146 - V_20 ) + 1 ;
}
T_3
F_131 ( T_1 * V_3 , const T_4 V_25 )
{
T_3 V_37 = 0 ;
T_23 V_147 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
do {
V_147 = F_48 ( V_3 , V_25 + V_37 ) ;
V_37 += 2 ;
} while( V_147 != 0 );
return V_37 ;
}
T_4
F_132 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_142 )
{
T_4 V_148 ;
T_3 V_20 , V_145 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
F_16 ( V_3 , V_25 , 0 , & V_20 , & V_145 ) ;
V_148 = F_126 ( V_3 , V_20 , V_142 , 0 ) ;
if ( V_148 == - 1 ) {
return - 1 ;
}
else {
return V_148 - V_20 ;
}
}
T_4
F_133 ( T_1 * V_3 , const T_4 V_25 , const T_17 * V_149 , const T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_150 = strncmp ( ( const char * ) V_61 , V_149 , V_4 ) ;
return ( V_150 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_134 ( T_1 * V_3 , const T_4 V_25 , const T_17 * V_149 , const T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_150 = F_112 ( ( const char * ) V_61 , V_149 , V_4 ) ;
return ( V_150 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_4
F_135 ( T_1 * V_3 , const T_4 V_25 , const T_7 * V_149 , T_10 V_4 )
{
const T_7 * V_61 ;
V_61 = F_43 ( V_3 , V_25 , ( T_4 ) V_4 , NULL ) ;
if ( V_61 ) {
int V_150 = memcmp ( V_61 , V_149 , V_4 ) ;
return ( V_150 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_17 *
F_136 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_137 ( V_61 , V_45 ) ;
}
T_17 *
F_138 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 ;
T_4 V_45 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
return F_139 ( V_61 , V_45 ) ;
}
T_17 *
F_140 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 , * V_56 ;
T_4 V_45 ;
T_4 V_151 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_61 , V_151 = 0 ; V_151 < V_45 && * V_56 != '\0' ; V_56 ++ , V_151 ++ )
;
return F_137 ( V_61 , V_151 ) ;
}
T_17 *
F_141 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_4 )
{
const T_7 * V_61 , * V_56 ;
T_4 V_45 ;
T_4 V_151 ;
V_45 = ( V_4 > 0 ) ? V_4 : 0 ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
for ( V_56 = V_61 , V_151 = 0 ; V_151 < V_45 && * V_56 != '\0' ; V_56 ++ , V_151 ++ )
;
return F_139 ( V_61 , V_151 ) ;
}
static T_7 *
F_142 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_143 ( V_59 , V_61 , V_9 ) ;
}
static T_7 *
F_144 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_152 ;
F_35 ( V_3 , V_25 , V_9 ) ;
V_152 = ( T_7 * ) F_46 ( V_59 , V_9 + 1 ) ;
F_28 ( V_3 , V_152 , V_25 , V_9 ) ;
V_152 [ V_9 ] = '\0' ;
return V_152 ;
}
static inline T_7 *
F_108 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_9 )
{
T_7 * V_152 ;
T_4 V_49 = V_9 ;
F_5 ( V_25 >= 0 ) ;
F_5 ( V_49 >= - 1 ) ;
if ( V_49 < 0 )
V_49 = V_3 -> V_9 - V_25 ;
F_35 ( V_3 , V_25 , V_49 ) ;
V_152 = ( T_7 * ) F_46 ( V_59 , V_49 + 1 ) ;
F_28 ( V_3 , V_152 , V_25 , V_49 ) ;
V_152 [ V_49 ] = '\0' ;
return V_152 ;
}
static T_7 *
F_145 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_146 ( V_59 , V_61 , V_9 ) ;
}
static T_7 *
F_147 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 , const T_23 V_153 [ 0x80 ] )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_148 ( V_59 , V_61 , V_9 , V_153 ) ;
}
static T_7 *
F_149 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_150 ( V_59 , V_61 , V_9 , V_63 ) ;
}
static T_7 *
F_151 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_152 ( V_59 , V_61 , V_9 , V_63 ) ;
}
static T_17 *
F_153 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 V_9 , const T_3 V_63 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_154 ( V_59 , V_61 , V_9 , V_63 ) ;
}
T_17 *
F_155 ( T_11 * V_59 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_154 )
{
T_4 V_155 = V_32 >> 3 ;
T_4 V_9 = ( ( V_154 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_61 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_61 = F_22 ( V_3 , V_155 , V_9 ) ;
return F_156 ( V_59 , V_61 , V_32 , V_154 ) ;
}
T_17 *
F_157 ( T_11 * V_59 , T_1 * V_3 ,
const T_4 V_32 , T_4 V_154 )
{
T_4 V_155 = V_32 >> 3 ;
T_4 V_9 = ( ( V_154 + 1 ) * 7 + ( V_32 & 0x07 ) ) >> 3 ;
const T_7 * V_61 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_61 = F_22 ( V_3 , V_155 , V_9 ) ;
return F_158 ( V_59 , V_61 , V_32 , V_154 ) ;
}
static T_7 *
F_159 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 V_9 )
{
const T_7 * V_61 ;
V_61 = F_22 ( V_3 , V_25 , V_9 ) ;
return F_160 ( V_59 , V_61 , V_9 ) ;
}
T_7 *
F_161 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_63 )
{
T_7 * V_156 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_17 ( V_24 ) ;
}
switch ( V_63 & V_157 ) {
case V_158 :
default:
V_156 = F_142 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_159 :
V_156 = F_144 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_88 :
V_156 = F_151 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_89 :
V_156 = F_149 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_90 :
V_156 = F_153 ( V_59 , V_3 , V_25 , V_9 ,
V_63 & V_64 ) ;
break;
case V_160 :
V_156 = F_145 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
case V_161 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_162 ) ;
break;
case V_163 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_164 ) ;
break;
case V_165 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_166 ) ;
break;
case V_167 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_168 ) ;
break;
case V_169 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_170 ) ;
break;
case V_171 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_172 ) ;
break;
case V_173 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_174 ) ;
break;
case V_175 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_176 ) ;
break;
case V_177 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_178 ) ;
break;
case V_179 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_180 ) ;
break;
case V_181 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_182 ) ;
break;
case V_183 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_184 ) ;
break;
case V_185 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_186 ) ;
break;
case V_187 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_188 ) ;
break;
case V_189 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_190 ) ;
break;
case V_191 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_192 ) ;
break;
case V_193 :
V_156 = F_147 ( V_59 , V_3 , V_25 , V_9 , V_194 ) ;
break;
case V_91 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_154 = ( V_9 << 3 ) / 7 ;
V_156 = F_155 ( V_59 , V_3 , V_32 , V_154 ) ;
}
break;
case V_195 :
{
T_4 V_32 = V_25 << 3 ;
T_4 V_154 = ( V_9 << 3 ) / 7 ;
V_156 = F_157 ( V_59 , V_3 , V_32 , V_154 ) ;
}
break;
case V_92 :
V_156 = F_159 ( V_59 , V_3 , V_25 , V_9 ) ;
break;
}
return V_156 ;
}
T_7 *
F_162 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 ,
const T_4 V_9 , const T_3 V_63 )
{
return F_161 ( V_59 , V_3 , V_25 , V_9 , V_63 ) ;
}
static T_7 *
F_163 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_196 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_143 ( V_59 , V_61 , V_4 ) ;
}
static T_7 *
F_164 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_196 )
{
T_3 V_4 ;
T_7 * V_156 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_156 = ( T_7 * ) F_46 ( V_59 , V_4 ) ;
F_28 ( V_3 , V_156 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return V_156 ;
}
static T_7 *
F_165 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_196 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_146 ( V_59 , V_61 , V_4 ) ;
}
static T_7 *
F_166 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_196 , const T_23 V_153 [ 0x80 ] )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_148 ( V_59 , V_61 , V_4 , V_153 ) ;
}
const T_7 *
F_167 ( T_1 * V_3 , const T_4 V_25 , T_4 * V_196 )
{
T_3 V_4 ;
const T_7 * V_156 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_156 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return V_156 ;
}
static T_17 *
F_168 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_196 , const T_3 V_63 )
{
T_4 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_150 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_17 *
F_169 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_196 , const T_3 V_63 )
{
T_4 V_4 ;
const T_7 * V_61 ;
V_4 = F_131 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_152 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_17 *
F_170 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_196 , const T_3 V_63 )
{
T_4 V_4 ;
T_24 V_147 ;
const T_7 * V_61 ;
V_4 = 0 ;
do {
V_147 = F_52 ( V_3 , V_25 + V_4 ) ;
V_4 += 4 ;
} while( V_147 != 0 );
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_154 ( V_59 , V_61 , V_4 , V_63 ) ;
}
static T_7 *
F_171 ( T_11 * V_59 , T_1 * V_3 , T_4 V_25 , T_4 * V_196 )
{
T_3 V_4 ;
const T_7 * V_61 ;
V_4 = F_130 ( V_3 , V_25 ) ;
V_61 = F_22 ( V_3 , V_25 , V_4 ) ;
if ( V_196 )
* V_196 = V_4 ;
return F_160 ( V_59 , V_61 , V_4 ) ;
}
T_7 *
F_172 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , T_4 * V_196 , const T_3 V_63 )
{
T_7 * V_156 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
switch ( V_63 & V_157 ) {
case V_158 :
default:
V_156 = F_163 ( V_59 , V_3 , V_25 , V_196 ) ;
break;
case V_159 :
V_156 = F_164 ( V_59 , V_3 , V_25 , V_196 ) ;
break;
case V_88 :
V_156 = F_169 ( V_59 , V_3 , V_25 , V_196 ,
V_63 & V_64 ) ;
break;
case V_89 :
V_156 = F_168 ( V_59 , V_3 , V_25 , V_196 ,
V_63 & V_64 ) ;
break;
case V_90 :
V_156 = F_170 ( V_59 , V_3 , V_25 , V_196 ,
V_63 & V_64 ) ;
break;
case V_160 :
V_156 = F_165 ( V_59 , V_3 , V_25 , V_196 ) ;
break;
case V_161 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_162 ) ;
break;
case V_163 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_164 ) ;
break;
case V_165 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_166 ) ;
break;
case V_167 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_168 ) ;
break;
case V_169 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_170 ) ;
break;
case V_171 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_172 ) ;
break;
case V_173 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_174 ) ;
break;
case V_175 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_176 ) ;
break;
case V_177 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_178 ) ;
break;
case V_179 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_180 ) ;
break;
case V_181 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_182 ) ;
break;
case V_183 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_184 ) ;
break;
case V_185 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_186 ) ;
break;
case V_187 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_188 ) ;
break;
case V_189 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_190 ) ;
break;
case V_191 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_192 ) ;
break;
case V_193 :
V_156 = F_166 ( V_59 , V_3 , V_25 , V_196 , V_194 ) ;
break;
case V_91 :
F_106 ( L_20 ) ;
break;
case V_195 :
F_106 ( L_21 ) ;
break;
case V_92 :
V_156 = F_171 ( V_59 , V_3 , V_25 , V_196 ) ;
break;
}
return V_156 ;
}
static T_4
F_173 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_197 , T_7 * V_198 , T_4 * V_199 )
{
T_4 V_151 ;
T_3 V_20 ;
T_4 V_139 , V_45 ;
T_8 V_200 = FALSE ;
F_16 ( V_3 , V_25 , - 1 , & V_20 , & V_45 ) ;
F_5 ( V_197 != 0 ) ;
if ( V_197 == 1 ) {
V_198 [ 0 ] = 0 ;
* V_199 = 1 ;
return 0 ;
}
if ( V_45 == 0 ) {
F_17 ( V_24 ) ;
}
F_5 ( V_45 != - 1 ) ;
F_5 ( V_197 <= V_50 ) ;
if ( ( T_3 ) V_45 < V_197 ) {
V_139 = V_45 ;
V_200 = TRUE ;
}
else {
V_139 = V_197 ;
}
V_151 = F_132 ( V_3 , V_20 , V_139 - 1 ) ;
if ( V_151 == - 1 ) {
F_28 ( V_3 , V_198 , V_20 , V_139 ) ;
if ( V_200 ) {
V_198 [ V_139 ] = 0 ;
* V_199 = V_139 + 1 ;
}
else {
* V_199 = V_139 ;
}
return - 1 ;
}
F_28 ( V_3 , V_198 , V_20 , V_151 + 1 ) ;
* V_199 = V_151 + 1 ;
return V_151 ;
}
T_4
F_174 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_197 , T_7 * V_198 )
{
T_4 V_199 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
return F_173 ( V_3 , V_25 , V_197 , V_198 , & V_199 ) ;
}
T_4
F_175 ( T_1 * V_3 , const T_4 V_25 , const T_3 V_197 , T_7 * V_198 )
{
T_4 V_45 , V_199 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_45 = F_173 ( V_3 , V_25 , V_197 , V_198 , & V_199 ) ;
if ( V_45 == - 1 ) {
V_198 [ V_197 - 1 ] = 0 ;
return V_199 - 1 ;
}
else {
return V_45 ;
}
}
T_4
F_176 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_201 , const T_8 V_202 )
{
T_4 V_203 ;
T_4 V_204 ;
int V_205 ;
T_22 V_144 = 0 ;
static T_8 V_206 = FALSE ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
V_203 = V_25 + V_45 ;
if ( ! V_206 ) {
F_177 ( & V_207 , L_22 ) ;
V_206 = TRUE ;
}
V_204 = F_129 ( V_3 , V_25 , V_45 , & V_207 , & V_144 ) ;
if ( V_204 == - 1 ) {
if ( V_202 ) {
return - 1 ;
} else {
V_205 = V_203 - V_25 ;
if ( V_201 )
* V_201 = V_203 ;
}
} else {
V_205 = V_204 - V_25 ;
if ( V_144 == '\r' ) {
if ( V_204 + 1 >= V_203 ) {
if ( V_202 ) {
return - 1 ;
}
} else {
if ( F_47 ( V_3 , V_204 + 1 ) == '\n' ) {
V_204 ++ ;
}
}
}
if ( V_201 )
* V_201 = V_204 + 1 ;
}
return V_205 ;
}
T_4
F_178 ( T_1 * V_3 , const T_4 V_25 , int V_45 , T_4 * V_201 )
{
T_4 V_208 , V_209 ;
T_8 V_210 ;
T_22 V_211 = 0 ;
T_4 V_203 ;
int V_205 ;
static T_8 V_206 = FALSE ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( V_45 == - 1 )
V_45 = F_20 ( V_3 , V_25 ) ;
if ( ! V_206 ) {
F_177 ( & V_212 , L_23 ) ;
V_206 = TRUE ;
}
V_203 = V_25 + V_45 ;
V_208 = V_25 ;
V_210 = FALSE ;
for (; ; ) {
if ( V_210 ) {
V_209 = F_126 ( V_3 , V_208 , V_45 ,
'"' ) ;
} else {
V_209 = F_129 ( V_3 , V_208 , V_45 , & V_212 , & V_211 ) ;
}
if ( V_209 == - 1 ) {
V_205 = V_203 - V_25 ;
if ( V_201 )
* V_201 = V_203 ;
break;
}
if ( V_210 ) {
V_210 = FALSE ;
} else {
if ( V_211 == '"' ) {
V_210 = TRUE ;
} else {
V_205 = V_209 - V_25 ;
if ( V_211 == '\r' ) {
if ( V_209 + 1 < V_203 &&
F_47 ( V_3 , V_209 + 1 )
== '\n' ) {
V_209 ++ ;
}
}
if ( V_201 )
* V_201 = V_209 + 1 ;
break;
}
}
V_208 = V_209 + 1 ;
if ( V_208 >= V_203 ) {
V_205 = V_203 - V_25 ;
if ( V_201 )
* V_201 = V_203 ;
break;
}
}
return V_205 ;
}
T_4
F_179 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_142 )
{
T_4 V_52 = V_25 ;
T_4 V_96 , V_213 ;
T_7 V_214 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_213 = V_3 -> V_9 ;
V_96 = V_25 + V_142 ;
if ( V_96 >= V_213 )
{
V_96 = V_213 ;
}
for ( V_52 = V_25 ;
V_52 < V_96 &&
( ( V_214 = F_47 ( V_3 , V_52 ) ) == ' ' ||
V_214 == '\t' || V_214 == '\r' || V_214 == '\n' ) ;
V_52 ++ ) ;
return ( V_52 ) ;
}
T_4
F_180 ( T_1 * V_3 , const T_4 V_25 ) {
T_4 V_52 = V_25 ;
T_7 V_214 ;
for( V_52 = V_25 ; V_52 > 0 &&
( ( V_214 = F_47 ( V_3 , V_52 ) ) == ' ' ||
V_214 == '\t' || V_214 == '\n' || V_214 == '\r' ) ; V_52 -- ) ;
V_52 ++ ;
return ( V_52 ) ;
}
int
F_181 ( T_1 * V_3 , int V_25 , const int V_142 , const T_7 V_215 )
{
int V_96 , V_213 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
V_213 = V_3 -> V_9 ;
V_96 = V_25 + V_142 ;
if ( V_96 >= V_213 )
V_96 = V_213 ;
while ( V_25 < V_96 ) {
T_7 V_216 = F_47 ( V_3 , V_25 ) ;
if ( V_216 != V_215 )
break;
V_25 ++ ;
}
return V_25 ;
}
T_17 *
F_182 ( T_11 * V_59 , T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , const T_17 V_217 )
{
return ( T_17 * ) F_183 ( V_59 , F_22 ( V_3 , V_25 , V_45 ) , V_45 , V_217 ) ;
}
const T_17 *
F_184 ( T_1 * V_3 , const T_4 V_25 , const T_4 V_45 , T_25 * V_218 , T_8 V_219 )
{
int V_9 ;
T_7 V_220 ;
int V_37 = 0 ;
char * V_221 ;
T_4 V_222 = V_25 ;
F_5 ( V_3 && V_3 -> V_7 ) ;
if ( ! V_218 )
V_218 = & V_223 ;
if ( V_45 == - 1 ) {
V_9 = V_3 -> V_9 ;
if ( V_9 < V_25 ) {
return L_24 ;
}
} else {
V_9 = V_25 + V_45 ;
}
V_221 = ( char * ) F_46 ( F_109 () , ( V_9 - V_25 ) * 2 + 1 ) ;
while ( V_222 < V_9 ) {
V_220 = F_47 ( V_3 , V_222 ) ;
if ( ! V_219 ) {
V_221 [ V_37 ] = V_218 -> V_224 [ V_220 & 0x0f ] ;
V_37 ++ ;
}
V_219 = FALSE ;
V_220 = V_220 >> 4 ;
if ( V_220 == 0x0f )
break;
V_221 [ V_37 ] = V_218 -> V_224 [ V_220 & 0x0f ] ;
V_37 ++ ;
V_222 ++ ;
}
V_221 [ V_37 ] = '\0' ;
return V_221 ;
}
T_17 * F_185 ( T_11 * V_225 , T_1 * V_3 ,
const T_4 V_25 , const T_4 V_45 )
{
return F_186 ( V_225 , F_22 ( V_3 , V_25 , V_45 ) , V_45 ) ;
}
T_4
F_187 ( T_1 * V_226 , T_1 * V_227 , const T_4 V_228 )
{
T_3 V_229 , V_230 ;
const T_7 * V_231 ;
const T_7 * V_232 ;
const T_3 V_233 = V_227 -> V_9 ;
const T_7 * V_234 ;
F_5 ( V_226 && V_226 -> V_7 ) ;
if ( V_226 -> V_9 < 1 || V_227 -> V_9 < 1 ) {
return - 1 ;
}
V_231 = F_22 ( V_226 , 0 , - 1 ) ;
V_232 = F_22 ( V_227 , 0 , - 1 ) ;
F_16 ( V_226 , V_228 , - 1 ,
& V_229 , & V_230 ) ;
V_234 = F_188 ( V_231 + V_229 , V_230 ,
V_232 , V_233 ) ;
if ( V_234 ) {
return ( T_4 ) ( V_234 - V_231 ) ;
}
return - 1 ;
}
T_4
F_189 ( T_1 * V_3 )
{
return ( ( V_3 -> V_12 == - 1 ) ? ( V_3 -> V_12 = F_42 ( V_3 ) ) : V_3 -> V_12 ) ;
}
void
F_190 ( T_1 * V_3 )
{
V_3 -> V_8 |= V_22 ;
}
struct V_235 *
F_191 ( T_1 * V_3 )
{
return ( V_3 -> V_13 ) ;
}
