static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_2 -> V_6 [ 0 ] ;
V_4 -> V_7 = V_2 -> V_8 [ 0 ] ;
V_4 -> V_9 = F_2 ( V_2 , 0 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_2 -> V_10 [ 0 ] ;
V_4 -> V_7 = V_2 -> V_11 [ 0 ] ;
V_4 -> V_9 = F_4 ( V_2 , 0 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = F_6 ( V_2 -> V_12 ) ;
V_4 -> V_7 = F_7 ( V_2 -> V_12 , 0 ) ;
V_4 -> V_9 = F_8 ( V_2 -> V_12 , 1 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_13 * V_14 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_14 ;
V_4 -> V_7 = NULL ;
V_4 -> V_9 = 0 ;
}
inline void F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 , int V_15 )
{
F_11 ( V_2 -> V_16 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_18 = F_13 ( V_2 -> V_12 ) ;
struct V_3 V_4 ;
#ifdef F_14
struct V_19 * V_20 = V_19 ( V_17 , V_18 ) ;
#endif
F_15 ( F_16 ( V_20 ) + V_21 != - V_2 -> V_22 [ 0 ] ,
L_1 ,
- V_2 -> V_22 [ 0 ] , V_20 ) ;
F_5 ( V_2 , & V_4 ) ;
F_17 ( & V_4 , 0 , V_18 , 1 , - 1 ) ;
if ( ! V_18 && V_2 -> V_23 [ 0 ] ) {
if ( F_18 ( V_17 ) ) {
F_19 ( V_2 , V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] , V_17 , 0 ) ;
} else {
if ( ! F_8 ( V_2 -> V_12 , 1 ) )
F_19 ( V_2 , V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] ,
F_7 ( V_2 -> V_12 , 0 ) , 0 ) ;
}
}
F_15 ( ! V_18 && ! V_2 -> V_23 [ 0 ] ,
L_2 , V_2 -> V_23 [ 0 ] ,
V_2 -> V_6 [ 0 ] ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_18 = F_13 ( V_2 -> V_12 ) ;
struct V_19 * V_20 = V_19 ( V_17 , V_18 ) ;
int V_25 = V_2 -> V_12 -> V_25 ;
struct V_3 V_4 ;
F_5 ( V_2 , & V_4 ) ;
if ( F_21 ( V_20 ) ) {
V_2 -> V_22 [ 0 ] = - 1 ;
F_22 ( & V_4 , V_18 , V_25 ,
- V_2 -> V_22 [ 0 ] ) ;
F_15 ( ! V_18 && ! V_25 && ! V_2 -> V_23 [ 0 ] ,
L_3 ,
V_2 -> V_23 [ 0 ] ) ;
if ( ! V_18 && ! V_25 && V_2 -> V_23 [ 0 ] )
F_19 ( V_2 , V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] , V_17 , 0 ) ;
} else {
F_22 ( & V_4 , V_18 , V_25 ,
- V_2 -> V_22 [ 0 ] ) ;
F_15 ( ! F_16 ( V_20 ) ,
L_4
L_5 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
if ( V_2 -> V_27 [ 0 ] == - 1 ) {
if ( V_2 -> V_28 [ 0 ] == - 1 ) {
if ( V_2 -> V_11 [ 0 ] == F_7 ( V_2 -> V_12 , 0 ) ) {
if ( F_8 ( V_2 -> V_12 , 1 ) == 0 &&
1 < F_18 ( V_2 -> V_11 [ 0 ] ) )
F_19 ( V_2 , V_2 -> V_23 [ 0 ] ,
V_2 -> V_24 [ 0 ] , V_2 -> V_11 [ 0 ] , 1 ) ;
F_24 ( V_29 , V_2 , V_26 , - 1 ,
NULL ) ;
F_24 ( V_30 , V_2 ,
F_18 ( V_2 -> V_10 [ 0 ] ) , - 1 ,
NULL ) ;
F_25 ( V_2 , V_17 ) ;
F_25 ( V_2 , V_2 -> V_10 [ 0 ] ) ;
return 0 ;
}
F_24 ( V_31 , V_2 , V_26 , - 1 , NULL ) ;
F_24 ( V_32 , V_2 ,
F_18 ( V_2 -> V_6 [ 0 ] ) , - 1 , NULL ) ;
F_19 ( V_2 , V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] , V_2 -> V_10 [ 0 ] , 0 ) ;
F_25 ( V_2 , V_17 ) ;
F_25 ( V_2 , V_2 -> V_6 [ 0 ] ) ;
return - 1 ;
}
F_15 ( V_2 -> V_28 [ 0 ] != 0 ,
L_6 , V_2 -> V_28 [ 0 ] ) ;
F_26 ( V_2 , V_26 , - 1 ) ;
F_25 ( V_2 , V_17 ) ;
return 0 ;
}
F_15 ( ( V_2 -> V_27 [ 0 ] + V_2 -> V_28 [ 0 ] < V_26 ) ||
( V_2 -> V_27 [ 0 ] + V_2 -> V_28 [ 0 ] > V_26 + 1 ) ,
L_7
L_8 ,
V_2 -> V_28 [ 0 ] , V_2 -> V_27 [ 0 ] , V_26 ) ;
F_15 ( ( V_2 -> V_27 [ 0 ] + V_2 -> V_28 [ 0 ] == V_26 ) &&
( V_2 -> V_35 != - 1 || V_2 -> V_36 != - 1 ) ,
L_9
L_10 ,
V_2 -> V_36 , V_2 -> V_35 ) ;
F_15 ( ( V_2 -> V_27 [ 0 ] + V_2 -> V_28 [ 0 ] == V_26 + 1 ) &&
( V_2 -> V_35 < 1 || V_2 -> V_36 != - 1 ) ,
L_11
L_12 ,
V_2 -> V_36 , V_2 -> V_35 ) ;
F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 ) ;
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 ) ;
F_25 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_15 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_18 = F_13 ( V_2 -> V_12 ) ;
struct V_3 V_4 ;
int V_26 ;
struct V_19 * V_20 ;
F_15 ( V_2 -> V_11 [ 0 ] && F_29 ( V_2 -> V_11 [ 0 ] ) != V_37 + 1 ,
L_13 , V_2 -> V_11 [ 0 ] ) ;
F_15 ( V_2 -> V_38 [ 0 ] > 1 ,
L_14 , V_2 -> V_38 [ 0 ] ) ;
F_15 ( ! V_2 -> V_38 [ 0 ] && ! F_7 ( V_2 -> V_12 , 0 ) ,
L_15 ) ;
V_20 = V_19 ( V_17 , V_18 ) ;
F_5 ( V_2 , & V_4 ) ;
F_30 ( V_15 != V_39 && V_15 != V_40 ) ;
if ( V_15 == V_39 )
F_12 ( V_2 ) ;
else
F_20 ( V_2 ) ;
V_26 = F_18 ( V_17 ) ;
if ( V_2 -> V_27 [ 0 ] )
return F_23 ( V_2 ) ;
if ( V_2 -> V_28 [ 0 ] == - 1 ) {
F_27 ( V_2 , V_26 , - 1 ) ;
F_25 ( V_2 , V_17 ) ;
return 0 ;
}
F_15 ( V_2 -> V_28 [ 0 ] ,
L_16 , V_2 -> V_28 [ 0 ] ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
int V_42 ;
struct V_3 V_4 ;
int V_26 = F_18 ( V_2 -> V_6 [ 0 ] ) ;
if ( V_2 -> V_18 == V_2 -> V_27 [ 0 ] - 1 && V_2 -> V_35 != - 1 ) {
int V_43 , V_44 ;
int V_45 ;
V_42 = F_26 ( V_2 , V_2 -> V_27 [ 0 ] - 1 , - 1 ) ;
V_43 = F_16 ( V_20 ) - V_2 -> V_35 ;
F_32 ( V_20 , F_16 ( V_20 ) - V_43 ) ;
F_15 ( F_16 ( V_20 ) <= 0 ,
L_17
L_18 , F_16 ( V_20 ) ) ;
F_1 ( V_2 , & V_4 ) ;
F_33 ( & V_4 , V_26 + V_2 -> V_18 - V_42 , V_20 , V_41 ,
F_34 ( int , V_2 -> V_46 , F_16 ( V_20 ) ) ) ;
V_45 = F_35 ( V_20 ) ;
V_44 = 0 ;
if ( F_36 ( V_20 ) )
V_44 = V_2 -> V_47 -> V_48 - V_49 ;
F_37 ( V_20 , V_2 -> V_35 << V_44 ) ;
F_32 ( V_20 , V_43 ) ;
if ( V_2 -> V_35 > V_2 -> V_46 ) {
V_41 += ( V_2 -> V_35 - V_2 -> V_46 ) ;
V_2 -> V_46 = 0 ;
} else
V_2 -> V_46 -= V_2 -> V_35 ;
F_15 ( F_16 ( V_20 ) <= 0 ,
L_19
L_18 , F_16 ( V_20 ) ) ;
} else {
V_42 = F_26 ( V_2 , V_2 -> V_27 [ 0 ] - 1 , V_2 -> V_35 ) ;
F_1 ( V_2 , & V_4 ) ;
F_33 ( & V_4 , V_26 + V_2 -> V_18 - V_42 , V_20 , V_41 ,
V_2 -> V_46 ) ;
V_2 -> V_22 [ 0 ] = 0 ;
V_2 -> V_46 = 0 ;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
int V_26 = F_18 ( V_2 -> V_6 [ 0 ] ) ;
struct V_3 V_4 ;
F_15 ( V_2 -> V_46 ,
L_20 ) ;
if ( V_2 -> V_35 > V_2 -> V_25 ) {
struct V_19 * V_50 ;
int V_42 , V_51 = V_2 -> V_25 ;
V_42 = F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 - 1 ) ;
if ( V_42 && ! V_2 -> V_18 ) {
V_50 = V_19 ( V_2 -> V_6 [ 0 ] , F_18 ( V_2 -> V_6 [ 0 ] ) - 1 ) ;
V_51 += F_39 ( V_50 ) -
( V_2 -> V_35 - 1 ) ;
}
F_1 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_26 + V_2 -> V_18 - V_42 ,
V_51 , V_2 -> V_22 [ 0 ] ,
V_41 , V_2 -> V_46 ) ;
F_41 ( & V_4 , V_26 + V_2 -> V_18 - V_42 ,
V_51 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
V_2 -> V_22 [ 0 ] = 0 ;
} else {
F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 ) ;
}
V_2 -> V_25 -= V_2 -> V_35 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_2 -> V_6 [ 0 ] ) ;
struct V_3 V_4 ;
if ( F_21 ( V_19 ( V_17 , V_2 -> V_18 ) ) ) {
F_38 ( V_2 , V_20 , V_41 ) ;
return;
}
F_15 ( V_2 -> V_35 <= 0 ,
L_21
L_22 , V_2 -> V_35 ) ;
F_15 ( V_2 -> V_25 != F_16 ( V_19 ( V_17 , V_2 -> V_18 ) ) ,
L_23
L_24 ,
F_16 ( V_19 ( V_17 , V_2 -> V_18 ) ) , V_2 -> V_25 ) ;
if ( V_2 -> V_35 >= V_2 -> V_25 ) {
struct V_19 * V_54 , * V_55 ;
struct V_19 * V_56 ;
struct V_57 * V_58 ;
int V_42 , V_59 , V_45 , V_60 ;
V_54 = V_19 ( V_17 , V_2 -> V_18 ) ;
V_56 = V_19 ( V_17 , 0 ) ;
V_59 = V_2 -> V_35 - V_2 -> V_25 ;
V_2 -> V_22 [ 0 ] -= V_59 ;
F_15 ( V_2 -> V_22 [ 0 ] <= 0 ,
L_25
L_26 , V_2 -> V_22 [ 0 ] ) ;
V_42 = F_26 ( V_2 , V_2 -> V_27 [ 0 ] ,
F_16 ( V_54 ) ) ;
V_55 = V_19 ( V_2 -> V_6 [ 0 ] , V_26 + V_2 -> V_18 - V_42 ) ;
F_1 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_26 + V_2 -> V_18 - V_42 ,
F_16 ( V_55 ) , V_59 , V_41 ,
F_34 ( int , V_59 , V_2 -> V_46 ) ) ;
V_60 = V_59 ;
F_15 ( F_16 ( V_56 ) ,
L_27 ) ;
F_15 ( F_43 ( & V_56 -> V_61 ,
F_44 ( V_2 -> V_6 [ 0 ] , V_26 + V_2 -> V_18 - V_42 ) ) ,
L_28 ) ;
if ( F_36 ( V_55 ) ) {
int V_44 = V_2 -> V_47 -> V_48 - V_49 ;
V_60 = V_59 << V_44 ;
}
V_45 = F_35 ( V_56 ) ;
F_45 ( V_45 , & V_56 -> V_61 , V_60 ) ;
V_58 = F_46 ( V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] ) ;
F_45 ( V_45 , V_58 , V_60 ) ;
if ( V_59 > V_2 -> V_46 ) {
V_41 += ( V_59 - V_2 -> V_46 ) ;
V_2 -> V_46 = 0 ;
} else
V_2 -> V_46 -= V_59 ;
V_2 -> V_25 = 0 ;
F_15 ( F_43 ( & V_56 -> V_61 ,
F_44 ( V_2 -> V_6 [ 0 ] ,
F_18 ( V_2 -> V_6 [ 0 ] ) - 1 ) ) ||
! F_47 ( F_44 ( V_17 , 0 ) , V_17 -> V_62 ) ||
! F_47 ( V_58 , V_17 -> V_62 ) ,
L_29
L_30 ) ;
} else {
V_2 -> V_25 -= V_2 -> V_35 ;
F_15 ( V_2 -> V_25 <= 0 ,
L_31 ,
V_2 -> V_25 ) ;
F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 ) ;
}
}
static void F_48 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_2 -> V_6 [ 0 ] ) ;
struct V_3 V_4 ;
struct V_19 * V_50 ;
int V_42 ;
if ( ! V_2 -> V_18 &&
F_47 ( F_44 ( V_17 , 0 ) , V_17 -> V_62 ) ) {
V_50 = V_19 ( V_2 -> V_6 [ 0 ] , V_26 - 1 ) ;
if ( F_21 ( V_50 ) )
V_2 -> V_25 += F_39 ( V_50 ) ;
else
V_2 -> V_25 += F_16 ( V_50 ) ;
}
V_42 = F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 ) ;
F_1 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_26 + V_2 -> V_18 - V_42 , V_2 -> V_25 ,
V_2 -> V_22 [ 0 ] , V_41 , V_2 -> V_46 ) ;
V_50 = V_19 ( V_2 -> V_6 [ 0 ] , V_26 + V_2 -> V_18 - V_42 ) ;
if ( F_21 ( V_50 ) )
F_41 ( & V_4 , V_26 + V_2 -> V_18 - V_42 ,
V_2 -> V_25 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
if ( F_36 ( V_50 ) )
F_49 ( V_50 , 0 ) ;
V_2 -> V_22 [ 0 ] = 0 ;
V_2 -> V_46 = 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
if ( V_2 -> V_18 == V_2 -> V_27 [ 0 ] - 1 && V_2 -> V_35 != - 1 )
F_42 ( V_2 , V_20 , V_41 ) ;
else
F_48 ( V_2 , V_20 , V_41 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_19 * V_20 ,
const char * V_41 , int V_15 )
{
if ( V_2 -> V_27 [ 0 ] <= 0 )
return;
if ( V_2 -> V_18 < V_2 -> V_27 [ 0 ] ) {
F_30 ( V_15 != V_63 && V_15 != V_64 ) ;
if ( V_15 == V_63 )
F_31 ( V_2 , V_20 , V_41 ) ;
else
F_50 ( V_2 , V_20 , V_41 ) ;
} else
F_26 ( V_2 , V_2 -> V_27 [ 0 ] , V_2 -> V_35 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
struct V_3 V_4 ;
int V_42 ;
if ( V_26 - V_2 -> V_28 [ 0 ] >= V_2 -> V_18 ) {
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 ) ;
return;
}
if ( V_2 -> V_18 == V_26 - V_2 -> V_28 [ 0 ] + 1 && V_2 -> V_36 != - 1 ) {
T_1 V_65 , V_66 , V_67 ;
const char * V_68 ;
int V_45 , V_44 ;
T_1 V_69 ;
F_27 ( V_2 , V_2 -> V_28 [ 0 ] - 1 , - 1 ) ;
V_45 = F_35 ( V_20 ) ;
V_65 = F_53 ( V_20 ) ;
V_66 = F_16 ( V_20 ) ;
V_44 = 0 ;
if ( F_36 ( V_20 ) )
V_44 = V_2 -> V_47 -> V_48 - V_49 ;
V_69 = F_53 ( V_20 ) + ( ( V_66 - V_2 -> V_36 ) << V_44 ) ;
F_54 ( V_20 , V_69 ) ;
F_32 ( V_20 , V_2 -> V_36 ) ;
F_3 ( V_2 , & V_4 ) ;
if ( ( V_66 - V_2 -> V_36 ) > V_2 -> V_46 ) {
V_67 = 0 ;
V_68 = V_41 + ( V_66 - V_2 -> V_36 ) - V_2 -> V_46 ;
} else {
V_68 = V_41 ;
V_67 = V_2 -> V_46 -
( V_66 - V_2 -> V_36 ) ;
V_2 -> V_46 -= V_67 ;
}
F_33 ( & V_4 , 0 , V_20 , V_68 , V_67 ) ;
F_19 ( V_2 , V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] , V_2 -> V_10 [ 0 ] , 0 ) ;
F_54 ( V_20 , V_65 ) ;
F_32 ( V_20 , V_66 - V_2 -> V_36 ) ;
V_2 -> V_22 [ 0 ] -= V_2 -> V_36 ;
} else {
V_42 = F_27 ( V_2 , V_2 -> V_28 [ 0 ] - 1 , V_2 -> V_36 ) ;
F_3 ( V_2 , & V_4 ) ;
F_33 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] - 1 ,
V_20 , V_41 , V_2 -> V_46 ) ;
if ( V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] - 1 == 0 )
F_19 ( V_2 , V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] , V_2 -> V_10 [ 0 ] , 0 ) ;
V_2 -> V_46 = V_2 -> V_22 [ 0 ] = 0 ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_3 V_4 ;
int V_70 ;
F_15 ( V_2 -> V_46 ,
L_32 ) ;
V_70 = F_39 ( V_19 ( V_17 , V_2 -> V_18 ) ) ;
if ( V_70 - V_2 -> V_36 < V_2 -> V_25 ) {
int V_71 ;
F_15 ( V_2 -> V_36 - 1 >= V_70 || ! V_2 -> V_22 [ 0 ] ,
L_33
L_34 , V_2 -> V_36 , V_70 ) ;
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 - 1 ) ;
V_71 = V_2 -> V_25 - V_70 +
V_2 -> V_36 - 1 ;
F_3 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , 0 , V_71 ,
V_2 -> V_22 [ 0 ] , V_41 , V_2 -> V_46 ) ;
F_41 ( & V_4 , 0 , V_71 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
if ( V_71 == 0 )
F_19 ( V_2 , V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] , V_2 -> V_10 [ 0 ] , 0 ) ;
V_2 -> V_22 [ 0 ] = 0 ;
V_2 -> V_25 ++ ;
} else {
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 ) ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_72 , V_73 , V_67 , V_45 ;
unsigned long V_74 ;
const char * V_68 ;
struct V_3 V_4 ;
if ( F_21 ( V_19 ( V_17 , V_2 -> V_18 ) ) ) {
F_55 ( V_2 , V_20 , V_41 ) ;
return;
}
V_72 = V_2 -> V_36 - V_2 -> V_22 [ 0 ] ;
if ( V_72 < 0 )
V_72 = 0 ;
F_15 ( V_2 -> V_25 != F_16 ( V_19 ( V_17 , V_2 -> V_18 ) ) ,
L_35
L_36 , V_2 -> V_25 ,
F_16 ( V_19 ( V_17 , V_2 -> V_18 ) ) ) ;
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_72 ) ;
V_73 = V_2 -> V_22 [ 0 ] - V_2 -> V_36 ;
if ( V_73 < 0 )
V_73 = 0 ;
V_74 = V_73 ;
V_45 = F_35 ( V_19 ( V_2 -> V_10 [ 0 ] , 0 ) ) ;
if ( F_57 ( V_45 , F_44 ( V_2 -> V_10 [ 0 ] , 0 ) ) ) {
int V_44 = V_2 -> V_47 -> V_48 - V_49 ;
V_74 = V_73 << V_44 ;
}
F_45 ( V_45 , F_44 ( V_2 -> V_10 [ 0 ] , 0 ) , V_74 ) ;
F_45 ( V_45 , F_46 ( V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] ) ,
V_74 ) ;
F_58 ( V_2 , V_2 -> V_33 [ 0 ] , 0 ) ;
F_3 ( V_2 , & V_4 ) ;
if ( V_73 > V_2 -> V_46 ) {
V_67 = 0 ;
V_68 = V_41 + V_73 - V_2 -> V_46 ;
} else {
V_68 = V_41 ;
V_67 = V_2 -> V_46 - V_73 ;
V_2 -> V_46 -= V_67 ;
}
F_40 ( & V_4 , 0 , V_72 , V_2 -> V_22 [ 0 ] - V_73 ,
V_68 , V_67 ) ;
if ( F_36 ( V_19 ( V_2 -> V_10 [ 0 ] , 0 ) ) )
F_49 ( V_19 ( V_2 -> V_10 [ 0 ] , 0 ) , 0 ) ;
V_2 -> V_22 [ 0 ] = V_73 ;
if ( ! V_73 )
V_2 -> V_25 ++ ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
struct V_19 * V_50 ;
struct V_3 V_4 ;
F_3 ( V_2 , & V_4 ) ;
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 ) ;
if ( V_2 -> V_25 >= 0 ) {
F_3 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] ,
V_2 -> V_25 , V_2 -> V_22 [ 0 ] , V_41 ,
V_2 -> V_46 ) ;
}
V_50 = V_19 ( V_2 -> V_10 [ 0 ] , V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] ) ;
if ( F_21 ( V_50 ) && V_2 -> V_25 >= 0 ) {
F_41 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] ,
V_2 -> V_25 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
if ( ! V_2 -> V_25 ) {
F_15 ( V_2 -> V_18 - V_26 + V_2 -> V_28 [ 0 ] ,
L_37
L_38 ) ;
F_19 ( V_2 , V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] , V_2 -> V_10 [ 0 ] , 0 ) ;
}
}
if ( F_36 ( V_50 ) )
F_49 ( V_50 , 0 ) ;
V_2 -> V_46 = V_2 -> V_22 [ 0 ] = 0 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_19 * V_20 , const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
if ( V_26 - V_2 -> V_28 [ 0 ] > V_2 -> V_18 ) {
F_27 ( V_2 , V_2 -> V_28 [ 0 ] , V_2 -> V_36 ) ;
return;
}
if ( V_2 -> V_18 == V_26 - V_2 -> V_28 [ 0 ] && V_2 -> V_36 != - 1 )
F_56 ( V_2 , V_20 , V_41 ) ;
else
F_59 ( V_2 , V_20 , V_41 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_19 * V_20 ,
const char * V_41 , int V_15 )
{
if ( V_2 -> V_28 [ 0 ] <= 0 )
return;
F_30 ( V_15 != V_63 && V_15 != V_64 ) ;
if ( V_15 == V_63 )
F_52 ( V_2 , V_20 , V_41 ) ;
else
F_60 ( V_2 , V_20 , V_41 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_77 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
struct V_3 V_4 ;
int V_44 ;
if ( V_26 - V_2 -> V_78 [ V_77 ] >= V_2 -> V_18 ) {
F_24 ( V_79 , V_2 ,
V_2 -> V_78 [ V_77 ] , V_2 -> V_80 [ V_77 ] , V_2 -> V_81 [ V_77 ] ) ;
return;
}
if ( V_2 -> V_18 == V_26 - V_2 -> V_78 [ V_77 ] + 1 && V_2 -> V_80 [ V_77 ] != - 1 ) {
int V_65 , V_66 , V_67 ;
const char * V_68 ;
int V_45 ;
F_24 ( V_79 , V_2 , V_2 -> V_78 [ V_77 ] - 1 , - 1 ,
V_2 -> V_81 [ V_77 ] ) ;
V_45 = F_35 ( V_20 ) ;
V_65 = F_53 ( V_20 ) ;
V_66 = F_16 ( V_20 ) ;
V_44 = 0 ;
if ( F_36 ( V_20 ) )
V_44 = V_2 -> V_47 -> V_48 - V_49 ;
F_54 ( V_20 ,
F_53 ( V_20 ) +
( ( V_66 - V_2 -> V_80 [ V_77 ] ) << V_44 ) ) ;
F_32 ( V_20 , V_2 -> V_80 [ V_77 ] ) ;
F_9 ( V_2 , & V_4 , V_2 -> V_81 [ V_77 ] ) ;
if ( ( V_66 - V_2 -> V_80 [ V_77 ] ) > V_2 -> V_46 ) {
V_67 = 0 ;
V_68 = V_41 + ( V_66 - V_2 -> V_80 [ V_77 ] ) -
V_2 -> V_46 ;
} else {
V_68 = V_41 ;
V_67 = V_2 -> V_46 - ( V_66 -
V_2 -> V_80 [ V_77 ] ) ;
V_2 -> V_46 -= V_67 ;
}
F_33 ( & V_4 , 0 , V_20 , V_68 , V_67 ) ;
F_54 ( V_20 , V_65 ) ;
F_32 ( V_20 , V_66 - V_2 -> V_80 [ V_77 ] ) ;
V_2 -> V_22 [ 0 ] -= V_2 -> V_80 [ V_77 ] ;
} else {
F_24 ( V_79 , V_2 ,
V_2 -> V_78 [ V_77 ] - 1 , V_2 -> V_80 [ V_77 ] , V_2 -> V_81 [ V_77 ] ) ;
F_9 ( V_2 , & V_4 , V_2 -> V_81 [ V_77 ] ) ;
F_33 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_78 [ V_77 ] - 1 ,
V_20 , V_41 , V_2 -> V_46 ) ;
V_2 -> V_46 = V_2 -> V_22 [ 0 ] = 0 ;
}
}
static void F_63 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_77 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_19 * V_82 = V_19 ( V_17 , V_2 -> V_18 ) ;
int V_70 = F_39 ( V_82 ) ;
struct V_3 V_4 ;
if ( V_70 - V_2 -> V_80 [ V_77 ] < V_2 -> V_25 &&
V_2 -> V_25 <= V_70 ) {
F_15 ( ! V_2 -> V_22 [ 0 ] ,
L_39 ) ;
F_15 ( V_2 -> V_80 [ V_77 ] - 1 >= V_70 ,
L_40 ,
V_2 -> V_80 [ V_77 ] - 1 , V_70 ) ;
F_24 ( V_79 , V_2 , V_2 -> V_78 [ V_77 ] ,
V_2 -> V_80 [ V_77 ] - 1 , V_2 -> V_81 [ V_77 ] ) ;
F_9 ( V_2 , & V_4 , V_2 -> V_81 [ V_77 ] ) ;
F_40 ( & V_4 , 0 , V_2 -> V_25 - V_70 +
V_2 -> V_80 [ V_77 ] - 1 , V_2 -> V_22 [ 0 ] ,
V_41 , V_2 -> V_46 ) ;
F_41 ( & V_4 , 0 , V_2 -> V_25 - V_70 +
V_2 -> V_80 [ V_77 ] - 1 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
V_2 -> V_22 [ 0 ] = 0 ;
V_2 -> V_25 ++ ;
} else {
F_24 ( V_79 , V_2 , V_2 -> V_78 [ V_77 ] ,
V_2 -> V_80 [ V_77 ] , V_2 -> V_81 [ V_77 ] ) ;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_77 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_19 * V_82 = V_19 ( V_17 , V_2 -> V_18 ) ;
int V_72 , V_73 , V_67 , V_44 ;
const char * V_68 ;
struct V_19 * V_83 ;
struct V_3 V_4 ;
F_15 ( V_20 , L_41 ) ;
if ( F_21 ( V_82 ) ) {
F_63 ( V_2 , V_20 , V_41 , V_75 ,
V_76 , V_77 ) ;
return;
}
F_15 ( V_2 -> V_25 != F_16 ( V_19 ( V_17 , V_2 -> V_18 ) ) ||
V_2 -> V_22 [ 0 ] <= 0 ,
L_42 ) ;
V_72 = V_2 -> V_80 [ V_77 ] - V_2 -> V_22 [ 0 ] ;
if ( V_72 < 0 )
V_72 = 0 ;
F_24 ( V_79 , V_2 , V_2 -> V_78 [ V_77 ] , V_72 ,
V_2 -> V_81 [ V_77 ] ) ;
V_73 = V_2 -> V_22 [ 0 ] - V_2 -> V_80 [ V_77 ] ;
if ( V_73 < 0 )
V_73 = 0 ;
F_9 ( V_2 , & V_4 , V_2 -> V_81 [ V_77 ] ) ;
if ( V_73 > V_2 -> V_46 ) {
V_67 = 0 ;
V_68 = V_41 + V_73 - V_2 -> V_46 ;
} else {
V_68 = V_41 ;
V_67 = V_2 -> V_46 - V_73 ;
V_2 -> V_46 -= V_67 ;
}
F_40 ( & V_4 , 0 , V_72 , V_2 -> V_22 [ 0 ] - V_73 ,
V_68 , V_67 ) ;
V_83 = V_19 ( V_2 -> V_81 [ V_77 ] , 0 ) ;
V_44 = 0 ;
if ( F_36 ( V_83 ) ) {
F_49 ( V_83 , 0 ) ;
V_44 = V_2 -> V_47 -> V_48 - V_49 ;
}
F_37 ( V_83 , V_73 << V_44 ) ;
V_2 -> V_22 [ 0 ] = V_73 ;
if ( ! V_73 )
V_2 -> V_25 ++ ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_77 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
int V_84 ;
struct V_19 * V_50 ;
struct V_3 V_4 ;
#ifdef F_14
struct V_19 * V_85 = V_19 ( V_17 , V_2 -> V_18 ) ;
if ( ! F_21 ( V_85 ) &&
( V_2 -> V_25 != F_16 ( V_85 ) ||
V_2 -> V_22 [ 0 ] <= 0 ) )
F_66 ( V_2 -> V_47 ,
L_43 ,
L_44 ) ;
#endif
V_84 = F_24 ( V_79 , V_2 , V_2 -> V_78 [ V_77 ] ,
V_2 -> V_80 [ V_77 ] , V_2 -> V_81 [ V_77 ] ) ;
F_15 ( V_84 ,
L_45 ,
V_84 ) ;
F_9 ( V_2 , & V_4 , V_2 -> V_81 [ V_77 ] ) ;
F_40 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_78 [ V_77 ] ,
V_2 -> V_25 , V_2 -> V_22 [ 0 ] ,
V_41 , V_2 -> V_46 ) ;
V_50 = V_19 ( V_2 -> V_81 [ V_77 ] , V_2 -> V_18 - V_26 +
V_2 -> V_78 [ V_77 ] ) ;
if ( F_21 ( V_50 ) )
F_41 ( & V_4 , V_2 -> V_18 - V_26 + V_2 -> V_78 [ V_77 ] ,
V_2 -> V_25 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
if ( F_36 ( V_50 ) )
F_49 ( V_50 , 0 ) ;
V_2 -> V_46 = V_2 -> V_22 [ 0 ] = 0 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_77 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
int V_26 = F_18 ( V_17 ) ;
if ( V_26 - V_2 -> V_78 [ V_77 ] > V_2 -> V_18 ) {
F_24 ( V_79 , V_2 ,
V_2 -> V_78 [ V_77 ] , V_2 -> V_80 [ V_77 ] , V_2 -> V_81 [ V_77 ] ) ;
return;
}
if ( V_2 -> V_18 == V_26 - V_2 -> V_78 [ V_77 ] && V_2 -> V_80 [ V_77 ] != - 1 )
F_64 ( V_2 , V_20 , V_41 , V_75 ,
V_76 , V_77 ) ;
else
F_65 ( V_2 , V_20 , V_41 , V_75 ,
V_76 , V_77 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 ,
int V_15 )
{
int V_77 ;
for ( V_77 = V_2 -> V_38 [ 0 ] - 2 ; V_77 >= 0 ; V_77 -- ) {
F_30 ( V_15 != V_63 && V_15 != V_64 ) ;
F_15 ( ! V_2 -> V_78 [ V_77 ] ,
L_46 , V_77 ,
V_2 -> V_78 [ V_77 ] ) ;
V_2 -> V_81 [ V_77 ] = F_69 ( V_2 ) ;
F_70 ( F_71 ( V_2 -> V_81 [ V_77 ] ) , V_37 ) ;
if ( V_15 == V_63 )
F_62 ( V_2 , V_20 , V_41 , V_75 ,
V_76 , V_77 ) ;
else
F_67 ( V_2 , V_20 , V_41 , V_75 ,
V_76 , V_77 ) ;
memcpy ( V_75 + V_77 , F_44 ( V_2 -> V_81 [ V_77 ] , 0 ) , V_86 ) ;
V_76 [ V_77 ] = V_2 -> V_81 [ V_77 ] ;
F_15 ( ! F_72 ( V_2 -> V_81 [ V_77 ] )
|| F_73 ( V_2 -> V_81 [ V_77 ] )
|| F_74 ( V_2 -> V_81 [ V_77 ] ) ,
L_47 ,
V_77 , V_2 -> V_81 [ V_77 ] ) ;
}
}
static void F_75 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_3 V_4 ;
F_5 ( V_2 , & V_4 ) ;
F_33 ( & V_4 , V_2 -> V_18 , V_20 , V_41 , V_2 -> V_46 ) ;
if ( V_2 -> V_18 == 0 ) {
if ( V_2 -> V_23 [ 0 ] )
F_19 ( V_2 , V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] , V_17 , 0 ) ;
}
}
static void F_76 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_19 * V_50 = V_19 ( V_17 , V_2 -> V_18 ) ;
struct V_3 V_4 ;
if ( V_2 -> V_25 >= 0 && V_2 -> V_25 <= F_39 ( V_50 ) ) {
F_15 ( ! V_2 -> V_22 [ 0 ] ,
L_48 ) ;
F_5 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_2 -> V_18 , V_2 -> V_25 ,
V_2 -> V_22 [ 0 ] , V_41 , V_2 -> V_46 ) ;
F_41 ( & V_4 , V_2 -> V_18 , V_2 -> V_25 , 1 ,
(struct V_52 * ) V_41 ,
V_41 + V_53 , V_2 -> V_22 [ 0 ] ) ;
if ( ! V_2 -> V_18 && ! V_2 -> V_25 ) {
F_15 ( ! V_2 -> V_23 [ 0 ] || ! V_2 -> V_6 [ 0 ] ,
L_49 ) ;
if ( V_2 -> V_23 [ 0 ] )
F_19 ( V_2 , V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] ,
V_17 , 0 ) ;
}
V_2 -> V_22 [ 0 ] = 0 ;
}
}
static void F_77 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
struct V_3 V_4 ;
struct V_19 * V_50 = V_19 ( V_17 , V_2 -> V_18 ) ;
if ( F_21 ( V_50 ) ) {
F_76 ( V_2 , V_20 , V_41 ) ;
return;
}
if ( V_2 -> V_25 == F_16 ( V_50 ) ) {
F_15 ( V_2 -> V_22 [ 0 ] <= 0 ,
L_50 ,
V_2 -> V_22 [ 0 ] ) ;
F_5 ( V_2 , & V_4 ) ;
F_40 ( & V_4 , V_2 -> V_18 ,
V_2 -> V_25 , V_2 -> V_22 [ 0 ] , V_41 ,
V_2 -> V_46 ) ;
if ( F_36 ( V_50 ) )
F_49 ( V_50 , 0 ) ;
V_2 -> V_22 [ 0 ] = 0 ;
}
#ifdef F_14
else if ( V_2 -> V_22 [ 0 ] ) {
F_78 ( L_51 ) ;
F_66 ( V_2 -> V_47 , L_52 ,
L_53 , V_2 -> V_22 [ 0 ] ) ;
}
#endif
}
static void F_79 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_41 , int V_15 )
{
if ( 0 <= V_2 -> V_18 && V_2 -> V_18 < V_2 -> V_87 ) {
if ( V_15 == V_63 )
F_75 ( V_2 , V_20 , V_41 ) ;
else
F_77 ( V_2 , V_20 , V_41 ) ;
}
}
static int F_80 ( struct V_1 * V_2 , struct V_19 * V_20 ,
const char * V_41 , int V_15 ,
struct V_19 * V_75 ,
struct V_13 * * V_76 )
{
struct V_13 * V_17 = F_6 ( V_2 -> V_12 ) ;
F_81 ( V_2 -> V_47 , V_88 [ 0 ] ) ;
if ( V_2 -> V_22 [ 0 ] < 0 )
return F_28 ( V_2 , V_15 ) ;
V_2 -> V_18 = F_13 ( V_2 -> V_12 ) ,
V_2 -> V_25 = V_2 -> V_12 -> V_25 ,
V_2 -> V_46 = 0 ;
if ( V_15 == V_63 && ! V_41 )
V_2 -> V_46 = F_16 ( V_20 ) ;
if ( V_15 != V_63
&& F_36 ( V_19 ( V_17 , V_2 -> V_18 ) ) )
V_2 -> V_25 *= V_89 ;
F_51 ( V_2 , V_20 , V_41 , V_15 ) ;
V_2 -> V_18 -= ( V_2 -> V_27 [ 0 ] - ( ( V_2 -> V_35 != - 1 ) ? 1 : 0 ) ) ;
F_61 ( V_2 , V_20 , V_41 , V_15 ) ;
F_15 ( V_2 -> V_38 [ 0 ] > 3 ,
L_54 , V_2 -> V_38 [ 0 ] ) ;
F_15 ( V_2 -> V_38 [ 0 ] < 0 ,
L_55 , V_2 -> V_38 [ 0 ] ) ;
if ( V_2 -> V_38 [ 0 ] == 0 ) {
F_15 ( ! V_2 -> V_27 [ 0 ] || ! V_2 -> V_28 [ 0 ] ,
L_56 ) ;
if ( V_2 -> V_23 [ 0 ] ) {
if ( ! V_2 -> V_33 [ 0 ] )
F_66 ( V_2 -> V_47 , L_57 ,
L_58 ) ;
F_82 ( F_46 ( V_2 -> V_23 [ 0 ] , V_2 -> V_24 [ 0 ] ) ,
F_46 ( V_2 -> V_33 [ 0 ] , V_2 -> V_34 [ 0 ] ) ) ;
F_58 ( V_2 , V_2 -> V_23 [ 0 ] , 0 ) ;
}
F_25 ( V_2 , V_17 ) ;
return 0 ;
}
F_68 ( V_2 , V_20 , V_41 , V_75 , V_76 , V_15 ) ;
F_79 ( V_2 , V_20 , V_41 , V_15 ) ;
#ifdef F_14
if ( V_15 == V_64 && V_2 -> V_22 [ 0 ] ) {
F_78 ( L_59 ) ;
F_66 ( V_2 -> V_47 ,
L_60 , L_61 ,
V_2 -> V_22 [ 0 ] ) ;
}
#endif
return 0 ;
}
void F_83 ( struct V_3 * V_4 )
{
struct V_90 * V_91 ;
F_15 ( V_4 -> V_5 == NULL , L_62 ) ;
V_91 = F_71 ( V_4 -> V_5 ) ;
F_84 ( V_91 , 0 ) ;
F_85 ( V_91 , F_86 ( V_4 -> V_5 ) ) ;
if ( V_4 -> V_7 )
F_87 ( V_4 -> V_7 , V_4 -> V_9 ) -> V_92 = 0 ;
}
struct V_13 * F_69 ( struct V_1 * V_2 )
{
int V_77 ;
struct V_3 V_4 ;
for ( V_77 = 0 ; V_77 < V_93 ; V_77 ++ )
if ( V_2 -> V_94 [ V_77 ] != NULL )
break;
if ( V_77 == V_93 )
F_66 ( V_2 -> V_47 , L_63 , L_64 ) ;
F_9 ( V_2 , & V_4 , V_2 -> V_94 [ V_77 ] ) ;
F_83 ( & V_4 ) ;
F_88 ( V_2 -> V_94 [ V_77 ] ) ;
V_2 -> V_95 [ V_77 ] = V_2 -> V_94 [ V_77 ] ;
V_2 -> V_94 [ V_77 ] = NULL ;
return V_2 -> V_95 [ V_77 ] ;
}
static void F_89 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_77 ;
if ( F_74 ( V_14 ) )
F_90 ( V_2 -> V_47 , L_65 ,
L_66 ) ;
for ( V_77 = 0 ; V_77 < F_91 ( V_2 -> V_96 ) ; V_77 ++ )
if ( ! V_2 -> V_96 [ V_77 ] ) {
V_2 -> V_96 [ V_77 ] = V_14 ;
F_92 ( V_14 ) ;
return;
}
F_90 ( V_2 -> V_47 , L_67 ,
L_68 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_77 ;
T_2 V_97 ;
for ( V_77 = 0 ; V_77 < F_91 ( V_2 -> V_96 ) ; V_77 ++ ) {
if ( V_2 -> V_96 [ V_77 ] ) {
V_97 = V_2 -> V_96 [ V_77 ] -> V_98 ;
if ( F_74 ( V_2 -> V_96 [ V_77 ] ) )
F_90 ( V_2 -> V_47 , L_69 ,
L_70 ,
V_97 ) ;
F_94 ( V_2 -> V_96 [ V_77 ] ) ;
F_95 ( V_2 -> V_16 , NULL ,
V_97 , 0 ) ;
}
}
}
void F_25 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_90 * V_91 ;
V_91 = F_71 ( V_14 ) ;
F_70 ( V_91 , V_99 ) ;
F_84 ( V_91 , 0 ) ;
F_96 ( V_14 ) ;
F_89 ( V_2 , V_14 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_13 * V_100 , int V_101 ,
struct V_13 * V_102 , int V_103 )
{
F_15 ( V_100 == NULL || V_102 == NULL ,
L_71 ,
V_102 , V_100 ) ;
F_15 ( ! F_97 ( V_100 ) ,
L_72 ,
V_100 ) ;
F_15 ( V_101 < 0 || V_103 < 0 ,
L_73 , V_103 , V_101 ) ;
F_15 ( V_101 >= F_18 ( V_100 ) || V_103 >= F_18 ( V_102 ) ,
L_74 ,
V_103 , F_18 ( V_102 ) , V_101 , F_18 ( V_100 ) ) ;
if ( F_98 ( V_102 ) )
memcpy ( F_46 ( V_100 , V_101 ) , V_19 ( V_102 , V_103 ) ,
V_86 ) ;
else
memcpy ( F_46 ( V_100 , V_101 ) , F_46 ( V_102 , V_103 ) ,
V_86 ) ;
F_58 ( V_2 , V_100 , 0 ) ;
}
int F_2 ( struct V_1 * V_2 , int V_104 )
{
int V_105 = F_8 ( V_2 -> V_12 , V_104 + 1 ) ;
F_15 ( F_7 ( V_2 -> V_12 , V_104 ) == NULL || V_2 -> V_8 [ V_104 ] == NULL ,
L_75 ,
V_104 , V_2 -> V_8 [ V_104 ] , V_104 , F_7 ( V_2 -> V_12 , V_104 ) ) ;
if ( V_105 == 0 )
return F_18 ( V_2 -> V_8 [ V_104 ] ) ;
else
return V_105 - 1 ;
}
int F_4 ( struct V_1 * V_2 , int V_104 )
{
int V_105 = F_8 ( V_2 -> V_12 , V_104 + 1 ) ;
F_15 ( F_7 ( V_2 -> V_12 , V_104 ) == NULL || V_2 -> V_11 [ V_104 ] == NULL ,
L_76 ,
V_104 , F_7 ( V_2 -> V_12 , V_104 ) , V_104 , V_2 -> V_11 [ V_104 ] ) ;
if ( V_105 == F_18 ( F_7 ( V_2 -> V_12 , V_104 ) ) )
return 0 ;
else
return V_105 + 1 ;
}
static void F_99 ( struct V_106 * V_107 , struct V_13 * V_14 ,
char * V_108 )
{
struct V_109 * V_110 ;
int V_77 ;
F_15 ( ! V_14 , L_77 ) ;
if ( ! V_14 || ! F_100 ( V_14 ) )
return;
F_15 ( ! F_74 ( V_14 ) &&
! ( F_72 ( V_14 ) || F_73 ( V_14 ) ) ,
L_78 , V_14 ) ;
V_110 = F_87 ( V_14 , 0 ) ;
for ( V_77 = 0 ; V_77 <= F_18 ( V_14 ) ; V_77 ++ , V_110 ++ ) {
if ( ! F_101 ( V_107 , F_102 ( V_110 ) , 1 ) ) {
F_78 ( V_108 ) ;
F_66 ( V_107 , L_79 ,
L_80 ,
V_110 , V_14 ) ;
}
}
}
static int F_103 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_111 )
{
if ( ( ! F_104 ( V_14 ) && F_105 ( V_14 ) ) ||
! F_100 ( V_14 ) ) {
F_90 ( V_2 -> V_47 , L_81 , L_82 , V_111 , V_14 ) ;
return 1 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_112 = 0 ;
if ( F_107 ( V_2 -> V_47 ) -> V_113 ) {
F_66 ( V_2 -> V_47 , L_83 , L_84
L_85
L_86
L_87
L_88 ) ;
}
if ( V_2 -> V_27 [ 0 ] ) {
V_112 |= F_103 ( V_2 , V_2 -> V_6 [ 0 ] , L_89 ) ;
V_112 |= F_103 ( V_2 , V_2 -> V_8 [ 0 ] , L_90 ) ;
V_112 |= F_103 ( V_2 , V_2 -> V_23 [ 0 ] , L_91 ) ;
F_108 ( V_2 -> V_6 [ 0 ] ) ;
}
if ( V_2 -> V_28 [ 0 ] ) {
V_112 |= F_103 ( V_2 , V_2 -> V_10 [ 0 ] , L_92 ) ;
V_112 |= F_103 ( V_2 , V_2 -> V_11 [ 0 ] , L_93 ) ;
V_112 |= F_103 ( V_2 , V_2 -> V_33 [ 0 ] , L_94 ) ;
F_108 ( V_2 -> V_10 [ 0 ] ) ;
}
V_112 |= F_103 ( V_2 , F_6 ( V_2 -> V_12 ) ,
L_95 ) ;
F_108 ( F_6 ( V_2 -> V_12 ) ) ;
return V_112 ;
}
static void F_109 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 [ 0 ] ) {
if ( F_110 ( V_2 -> V_6 [ 0 ] ) !=
F_86 ( V_2 -> V_6 [ 0 ] ) -
V_92 ( F_87
( V_2 -> V_8 [ 0 ] , F_2 ( V_2 , 0 ) ) ) ) {
F_78 ( L_96 ) ;
F_66 ( V_2 -> V_47 , L_97 ,
L_98 ) ;
}
}
if ( V_2 -> V_28 [ 0 ] ) {
if ( F_110 ( V_2 -> V_10 [ 0 ] ) !=
F_86 ( V_2 -> V_10 [ 0 ] ) -
V_92 ( F_87
( V_2 -> V_11 [ 0 ] , F_4 ( V_2 , 0 ) ) ) ) {
F_78 ( L_99 ) ;
F_66 ( V_2 -> V_47 , L_100 ,
L_101 ) ;
}
}
if ( F_111 ( V_2 -> V_12 , 1 ) &&
( F_110 ( F_111 ( V_2 -> V_12 , 0 ) ) !=
( F_86 ( F_111 ( V_2 -> V_12 , 0 ) ) -
V_92 ( F_87 ( F_111 ( V_2 -> V_12 , 1 ) ,
F_8 ( V_2 -> V_12 , 1 ) ) ) ) ) ) {
int V_114 = F_110 ( F_111 ( V_2 -> V_12 , 0 ) ) ;
int V_115 = ( F_86 ( F_111 ( V_2 -> V_12 , 0 ) ) -
V_92 ( F_87 ( F_111 ( V_2 -> V_12 , 1 ) ,
F_8 ( V_2 -> V_12 ,
1 ) ) ) ) ;
F_78 ( L_102 ) ;
F_90 ( V_2 -> V_47 , L_103 ,
L_104
L_105 ,
V_114 ,
F_86 ( F_111 ( V_2 -> V_12 , 0 ) ) ,
F_111 ( V_2 -> V_12 , 1 ) ,
F_8 ( V_2 -> V_12 , 1 ) ,
V_92 ( F_87
( F_111 ( V_2 -> V_12 , 1 ) ,
F_8 ( V_2 -> V_12 , 1 ) ) ) ,
V_115 ) ;
F_66 ( V_2 -> V_47 , L_106 , L_107 ) ;
}
}
static void F_112 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> V_6 [ 0 ] ) ;
F_108 ( V_2 -> V_10 [ 0 ] ) ;
F_108 ( F_6 ( V_2 -> V_12 ) ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
int V_104 ;
for ( V_104 = 1 ; V_2 -> V_22 [ V_104 ] ; V_104 ++ ) {
F_99 ( V_2 -> V_47 , F_111 ( V_2 -> V_12 , V_104 ) ,
L_108 ) ;
if ( V_2 -> V_27 [ V_104 ] )
F_99 ( V_2 -> V_47 , V_2 -> V_6 [ V_104 ] , L_109 ) ;
if ( V_2 -> V_28 [ V_104 ] )
F_99 ( V_2 -> V_47 , V_2 -> V_10 [ V_104 ] , L_110 ) ;
}
}
static inline void F_114 ( struct V_1 * V_2 )
{
F_15 ( F_106 ( V_2 ) , L_111 ) ;
#ifdef F_14
F_107 ( V_2 -> V_47 ) -> V_113 = V_2 ;
#endif
}
static inline void F_115 ( struct V_1 * V_2 )
{
#ifdef F_14
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_107 ( V_2 -> V_47 ) -> V_113 = NULL ;
#endif
F_107 ( V_2 -> V_47 ) -> V_116 ++ ;
F_116 ( V_2 ) ;
F_93 ( V_2 ) ;
}
void F_117 ( struct V_1 * V_2 , struct V_19 * V_20 ,
const char * V_41 , int V_15 )
{
int V_117 ;
int V_104 ;
struct V_19 V_75 [ 2 ] ;
struct V_13 * V_76 [ 2 ] ;
V_2 -> V_118 = V_15 ;
V_2 -> V_119 = 0 ;
if ( F_118 ( V_2 ) ) {
F_66 ( V_2 -> V_47 , L_112 , L_113
L_114 ) ;
}
if ( ! V_2 -> V_22 [ 0 ] ) {
F_90 ( V_2 -> V_47 , L_115 ,
L_116 , V_15 ) ;
F_116 ( V_2 ) ;
return;
}
F_119 ( & F_120 ( V_2 -> V_47 ) ) ;
F_114 ( V_2 ) ;
V_117 = F_121 ( V_2 -> V_12 , 0 ) +
F_80 ( V_2 , V_20 , V_41 , V_15 , V_75 , V_76 ) ;
#ifdef F_14
F_109 ( V_2 ) ;
#endif
for ( V_104 = 1 ; V_104 < V_120 && V_2 -> V_22 [ V_104 ] ; V_104 ++ )
V_117 = F_122 ( V_2 , V_104 , V_117 , V_75 ,
V_76 ) ;
F_115 ( V_2 ) ;
}
