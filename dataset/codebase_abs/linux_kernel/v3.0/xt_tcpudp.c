static inline bool
F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , bool V_4 )
{
return ( V_3 >= V_1 && V_3 <= V_2 ) ^ V_4 ;
}
static bool
F_2 ( T_2 V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
unsigned int V_9 ,
bool V_4 ,
bool * V_10 )
{
const T_2 * V_11 ;
T_2 V_12 [ 60 - sizeof( struct V_13 ) ] ;
unsigned int V_14 ;
F_3 ( L_1 ) ;
if ( ! V_9 )
return V_4 ;
V_11 = F_4 ( V_7 , V_8 + sizeof( struct V_13 ) ,
V_9 , V_12 ) ;
if ( V_11 == NULL ) {
* V_10 = true ;
return false ;
}
for ( V_14 = 0 ; V_14 < V_9 ; ) {
if ( V_11 [ V_14 ] == V_5 ) return ! V_4 ;
if ( V_11 [ V_14 ] < 2 ) V_14 ++ ;
else V_14 += V_11 [ V_14 + 1 ] ? : 1 ;
}
return V_4 ;
}
static bool F_5 ( const struct V_6 * V_7 , struct V_15 * V_16 )
{
const struct V_13 * V_17 ;
struct V_13 V_18 ;
const struct V_19 * V_20 = V_16 -> V_21 ;
if ( V_16 -> V_22 != 0 ) {
if ( V_16 -> V_22 == 1 ) {
F_3 ( L_2 ) ;
V_16 -> V_10 = true ;
}
return false ;
}
#define F_6 ( bool , T_3 ) ((bool) ^ !!(tcpinfo->invflags & (invflg)))
V_17 = F_4 ( V_7 , V_16 -> V_23 , sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL ) {
F_3 ( L_3 ) ;
V_16 -> V_10 = true ;
return false ;
}
if ( ! F_1 ( V_20 -> V_24 [ 0 ] , V_20 -> V_24 [ 1 ] ,
F_7 ( V_17 -> V_25 ) ,
! ! ( V_20 -> V_26 & V_27 ) ) )
return false ;
if ( ! F_1 ( V_20 -> V_28 [ 0 ] , V_20 -> V_28 [ 1 ] ,
F_7 ( V_17 -> V_29 ) ,
! ! ( V_20 -> V_26 & V_30 ) ) )
return false ;
if ( ! F_6 ( ( ( ( unsigned char * ) V_17 ) [ 13 ] & V_20 -> V_31 )
== V_20 -> V_32 ,
V_33 ) )
return false ;
if ( V_20 -> V_5 ) {
if ( V_17 -> V_34 * 4 < sizeof( V_18 ) ) {
V_16 -> V_10 = true ;
return false ;
}
if ( ! F_2 ( V_20 -> V_5 , V_7 , V_16 -> V_23 ,
V_17 -> V_34 * 4 - sizeof( V_18 ) ,
V_20 -> V_26 & V_35 ,
& V_16 -> V_10 ) )
return false ;
}
return true ;
}
static int F_8 ( const struct V_36 * V_16 )
{
const struct V_19 * V_20 = V_16 -> V_21 ;
return ( V_20 -> V_26 & ~ V_37 ) ? - V_38 : 0 ;
}
static bool F_9 ( const struct V_6 * V_7 , struct V_15 * V_16 )
{
const struct V_39 * V_40 ;
struct V_39 V_41 ;
const struct V_42 * V_43 = V_16 -> V_21 ;
if ( V_16 -> V_22 != 0 )
return false ;
V_40 = F_4 ( V_7 , V_16 -> V_23 , sizeof( V_41 ) , & V_41 ) ;
if ( V_40 == NULL ) {
F_3 ( L_4 ) ;
V_16 -> V_10 = true ;
return false ;
}
return F_1 ( V_43 -> V_24 [ 0 ] , V_43 -> V_24 [ 1 ] ,
F_7 ( V_40 -> V_25 ) ,
! ! ( V_43 -> V_26 & V_44 ) )
&& F_1 ( V_43 -> V_28 [ 0 ] , V_43 -> V_28 [ 1 ] ,
F_7 ( V_40 -> V_29 ) ,
! ! ( V_43 -> V_26 & V_45 ) ) ;
}
static int F_10 ( const struct V_36 * V_16 )
{
const struct V_42 * V_43 = V_16 -> V_21 ;
return ( V_43 -> V_26 & ~ V_46 ) ? - V_38 : 0 ;
}
static int T_4 F_11 ( void )
{
return F_12 ( V_47 , F_13 ( V_47 ) ) ;
}
static void T_5 F_14 ( void )
{
F_15 ( V_47 , F_13 ( V_47 ) ) ;
}
