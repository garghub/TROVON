static inline int F_1 ( T_1 * V_1 )
{
return ( ( V_1 [ 0 ] == V_2 ) &&
( V_1 [ 1 ] == V_3 ) &&
( V_1 [ 2 ] == V_4 ) &&
( V_1 [ 3 ] == V_5 ) &&
( V_1 [ 4 ] == V_6 ) ) ;
}
static inline T_2 F_2 ( struct V_7 * V_8 )
{
return ( V_8 -> V_9 -> V_10 << 8 ) | V_8 -> V_11 ;
}
static int F_3 ( struct V_7 * V_12 )
{
unsigned long V_13 ;
int V_14 ;
V_13 = F_4 ( 9 ) ;
V_14 = F_5 ( 0 , & V_13 ) ;
if ( ! V_14 )
F_6 ( & V_12 -> V_15 , L_1 ) ;
return V_14 ;
}
int F_7 ( struct V_7 * V_12 )
{
if ( F_8 ( V_16 ) )
return F_3 ( V_12 ) ;
F_6 ( & V_12 -> V_15 , L_2 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
if ( V_21 -> V_24 [ V_22 ] . V_12 == V_12 )
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_25 ;
T_2 V_26 ;
if ( ! F_13 ( V_15 ) )
return - V_27 ;
V_12 = F_11 ( V_15 ) ;
V_25 = F_2 ( V_12 ) ;
if ( V_21 -> V_28 == V_21 -> V_23 )
return - V_27 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
if ( V_21 -> V_24 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_28 ++ ;
V_21 -> V_24 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_24 [ V_22 ] . V_29 = V_25 ;
V_26 =
F_14 ( V_21 -> V_30 + V_31 ) ;
F_15 ( V_25 | V_32 ,
V_21 -> V_33 + V_26 + ( V_22 * 4 ) ) ;
return V_22 ;
}
}
return - V_34 ;
}
static int F_16 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_26 ;
if ( ! F_13 ( V_15 ) )
return - V_27 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
if ( V_21 -> V_24 [ V_22 ] . V_12 == V_12 ) {
V_26 =
F_14 ( V_21 -> V_30 + V_31 ) ;
F_15 ( 0 , V_21 -> V_33 + V_26 + ( V_22 * 4 ) ) ;
V_21 -> V_24 [ V_22 ] . V_12 = NULL ;
V_21 -> V_24 [ V_22 ] . V_29 = 0 ;
V_21 -> V_28 -- ;
return V_22 ;
}
}
return - V_27 ;
}
static T_1 F_17 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_35 )
{
T_1 V_36 ;
struct V_20 * V_21 = F_10 ( V_18 ) ;
int V_22 , V_37 , V_38 , V_39 ;
T_1 V_40 ;
V_36 = 0 ;
V_37 = F_18 ( V_35 ) ;
for ( V_22 = 0 ; V_22 < V_41 ; V_22 ++ ) {
V_40 = V_21 -> V_1 [ V_22 ] ;
if ( V_40 & V_42 ) {
V_38 = V_40 &
~ ( V_42 | V_43 ) ;
V_39 = ( V_37 & ( 1 << V_38 ) ) ? 1 : 0 ;
} else if ( V_40 & V_43 ) {
V_38 = V_40 & ~ V_43 ;
V_39 = ( V_37 & ( 1 << V_38 ) ) ? 0 : 1 ;
} else {
V_39 = ( V_40 & V_44 ) ? 1 : 0 ;
}
V_36 |= ( V_39 << V_22 ) ;
}
return V_36 ;
}
static int F_19 ( void * V_33 , T_2 V_45 )
{
int V_46 = 0 ;
T_3 V_47 ;
T_2 V_26 ;
V_26 = F_14 ( V_33 + V_45 + V_31 ) ;
if ( V_26 == 0 )
return 0 ;
do {
V_47 = F_20 ( V_33 + V_26 + ( V_46 * sizeof( T_3 ) ) ) ;
V_46 ++ ;
} while ( ( V_47 & V_48 ) == 0 );
return V_46 ;
}
static inline int F_21 ( T_1 * V_1 )
{
return ( ( V_1 [ 0 ] == V_49 ) &&
( V_1 [ 1 ] == V_49 ) &&
( V_1 [ 2 ] == V_49 ) &&
( V_1 [ 3 ] == V_49 ) &&
( V_1 [ 4 ] == V_49 ) ) ;
}
struct V_17 * F_22 ( struct V_7 * V_12 , void T_4 * V_33 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_46 ;
int V_22 ;
int V_50 ;
T_2 V_45 ;
T_2 V_51 ;
T_2 V_52 ;
T_1 V_38 ;
union {
T_5 V_53 ;
struct {
T_3 V_54 ;
T_3 V_55 ;
};
} V_1 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
V_45 = F_14 ( V_33 + V_56 ) ;
if ( V_45 == 0 )
return NULL ;
V_46 = F_19 ( V_33 , V_45 ) ;
if ( V_46 == 0 )
return NULL ;
V_18 = F_23 ( & V_57 ,
sizeof( * V_21 )
+ ( sizeof( struct V_58 ) * V_46 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_33 = V_33 ;
V_21 -> V_30 = V_33 + V_45 ;
V_21 -> V_23 = V_46 ;
V_51 = F_14 ( V_21 -> V_30 + V_59 ) ;
if ( ( V_51 & V_60 ) == 0 ) {
V_51 |= V_60 ;
F_24 ( V_51 ,
V_21 -> V_30 + V_59 ) ;
}
V_52 = F_14 ( V_21 -> V_30 + V_61 ) ;
if ( ( V_52 & V_62 ) == 0 ) {
V_52 |= V_62 ;
F_24 ( V_52 ,
V_21 -> V_30 + V_61 ) ;
}
V_1 . V_54 =
F_20 ( V_21 -> V_30 + V_63 ) ;
V_1 . V_55 =
F_20 ( V_21 -> V_30 + V_64 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
V_38 = V_1 . V_53 >> ( 8 * V_22 ) ;
V_21 -> V_1 [ V_22 ] = V_38 & V_65 ;
}
if ( F_21 ( V_21 -> V_1 ) ) {
F_25 ( 1 , V_66 ,
L_3 ,
F_26 ( & V_12 -> V_15 ) ,
F_27 ( & V_12 -> V_15 ) ) ;
F_28 ( V_18 ) ;
return NULL ;
}
V_50 = F_29 ( V_18 , & V_12 -> V_15 ) ;
if ( V_50 ) {
F_28 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
