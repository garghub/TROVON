static inline bool
F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , bool V_4 )
{
bool V_5 ;
F_2 ( L_1 ,
V_4 ? '!' : ' ' , V_1 , V_3 , V_2 ) ;
V_5 = ( V_3 >= V_1 && V_3 <= V_2 ) ^ V_4 ;
F_2 ( L_2 , V_5 ? L_3 : L_4 ) ;
return V_5 ;
}
static bool F_3 ( const struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 V_11 ;
const struct V_10 * V_12 ;
const struct V_13 * V_14 = V_9 -> V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
unsigned int V_18 = 0 ;
bool V_19 = false ;
struct V_20 V_21 ;
const struct V_20 * V_22 ;
int V_23 ;
V_23 = F_4 ( V_7 , & V_17 , V_24 , NULL ) ;
if ( V_23 < 0 ) {
if ( V_23 != - V_25 )
V_9 -> V_26 = true ;
return false ;
}
V_12 = F_5 ( V_7 , V_17 , sizeof( V_11 ) , & V_11 ) ;
if ( V_12 == NULL ) {
V_9 -> V_26 = true ;
return false ;
}
V_18 = F_6 ( V_12 ) ;
if ( V_7 -> V_27 - V_17 < V_18 ) {
return false ;
}
F_2 ( L_5 , V_18 , V_12 -> V_18 ) ;
F_2 ( L_6 , V_12 -> type ) ;
F_2 ( L_7 , V_12 -> V_28 , V_12 -> V_28 ) ;
F_2 ( L_8 ,
F_1 ( V_14 -> V_29 [ 0 ] , V_14 -> V_29 [ 1 ] ,
V_12 -> V_28 ,
! ! ( V_14 -> V_30 & V_31 ) ) ) ;
F_2 ( L_9 ,
V_14 -> V_32 , V_12 -> type ,
( ! ( V_14 -> V_33 & V_34 ) ||
( ( V_14 -> V_32 == V_12 -> type ) ^
! ! ( V_14 -> V_30 & V_35 ) ) ) ) ;
F_2 ( L_10 ,
V_14 -> V_18 , V_18 ,
! ( V_14 -> V_33 & V_36 ) ||
( ( V_14 -> V_18 == V_18 ) ^
! ! ( V_14 -> V_30 & V_37 ) ) ) ;
F_2 ( L_11 ,
V_14 -> V_33 & V_38 ,
( ( const struct V_39 * ) V_12 ) -> V_40 ,
! ( ( V_14 -> V_33 & V_38 ) &&
( ( ( const struct V_39 * ) V_12 ) -> V_40 ) ) ) ;
V_19 = ( V_12 != NULL ) &&
( F_1 ( V_14 -> V_29 [ 0 ] , V_14 -> V_29 [ 1 ] ,
V_12 -> V_28 ,
! ! ( V_14 -> V_30 & V_31 ) ) ) &&
( ! ( V_14 -> V_33 & V_36 ) ||
( ( V_14 -> V_18 == V_18 ) ^
! ! ( V_14 -> V_30 & V_37 ) ) ) &&
( ! ( V_14 -> V_33 & V_34 ) ||
( ( V_14 -> V_32 == V_12 -> type ) ^
! ! ( V_14 -> V_30 & V_35 ) ) ) ;
if ( V_19 && ( V_14 -> V_33 & V_38 ) ) {
const T_1 * V_41 ;
T_1 V_42 ;
V_41 = F_5 ( V_7 ,
V_17 + F_7 ( struct V_39 ,
V_40 ) ,
sizeof( V_42 ) ,
& V_42 ) ;
V_19 = ( * V_41 == 0 ) ;
}
F_2 ( L_12 , V_14 -> V_43 ) ;
if ( ! ( V_14 -> V_33 & V_44 ) ) {
return V_19 ;
} else if ( V_14 -> V_33 & V_45 ) {
F_2 ( L_13 ) ;
if ( V_14 -> V_43 > ( unsigned int ) ( ( V_18 - 8 ) / 16 ) ) {
F_2 ( L_14 ) ;
return false ;
} else {
unsigned int V_46 = 0 ;
F_2 ( L_12 , V_14 -> V_43 ) ;
for ( V_16 = 0 ;
V_16 < ( unsigned int ) ( ( V_18 - 8 ) / 16 ) ;
V_16 ++ ) {
V_22 = F_5 ( V_7 ,
V_17
+ sizeof( struct V_39 )
+ V_16 * sizeof( V_21 ) ,
sizeof( V_21 ) ,
& V_21 ) ;
F_8 ( V_22 == NULL ) ;
if ( F_9 ( V_22 , & V_14 -> V_47 [ V_46 ] ) ) {
F_2 ( L_15 , V_46 , V_16 ) ;
V_46 ++ ;
}
if ( V_46 == V_14 -> V_43 )
break;
}
F_2 ( L_16 , V_46 , V_14 -> V_43 ) ;
if ( V_46 == V_14 -> V_43 )
return V_19 ;
else
return false ;
}
} else {
F_2 ( L_17 ) ;
if ( V_14 -> V_43 > ( unsigned int ) ( ( V_18 - 8 ) / 16 ) ) {
F_2 ( L_14 ) ;
return false ;
} else {
F_2 ( L_12 , V_14 -> V_43 ) ;
for ( V_16 = 0 ; V_16 < V_14 -> V_43 ; V_16 ++ ) {
V_22 = F_5 ( V_7 ,
V_17
+ sizeof( struct V_39 )
+ V_16 * sizeof( V_21 ) ,
sizeof( V_21 ) ,
& V_21 ) ;
F_8 ( V_22 == NULL ) ;
if ( ! F_9 ( V_22 , & V_14 -> V_47 [ V_16 ] ) )
break;
}
F_2 ( L_18 , V_16 , V_14 -> V_43 ) ;
if ( V_16 == V_14 -> V_43 &&
V_16 == ( unsigned int ) ( ( V_18 - 8 ) / 16 ) )
return V_19 ;
else
return false ;
}
}
return false ;
}
static int F_10 ( const struct V_48 * V_9 )
{
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_14 -> V_30 & ~ V_49 ) {
F_2 ( L_19 , V_14 -> V_30 ) ;
return - V_50 ;
}
if ( ( V_14 -> V_33 & ( V_38 | V_51 ) ) &&
( ! ( V_14 -> V_33 & V_34 ) ||
( V_14 -> V_32 != 0 ) ||
( V_14 -> V_30 & V_35 ) ) ) {
F_2 ( L_20 ) ;
return - V_50 ;
}
return 0 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_52 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_52 ) ;
}
