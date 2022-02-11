static inline bool
F_1 ( const struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
unsigned int V_5 ;
T_1 V_6 , V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
V_6 = V_2 -> V_9 [ V_5 ] ;
if ( V_2 -> V_10 [ V_5 ] ) {
V_7 = V_2 -> V_9 [ ++ V_5 ] ;
F_2 ( L_1 , V_6 , V_7 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
if ( V_3 >= V_6 && V_3 <= V_7 )
return true ^ V_2 -> V_13 ;
break;
case V_14 :
if ( V_4 >= V_6 && V_4 <= V_7 )
return true ^ V_2 -> V_13 ;
break;
case V_15 :
if ( ( V_4 >= V_6 && V_4 <= V_7 ) ||
( V_3 >= V_6 && V_3 <= V_7 ) )
return true ^ V_2 -> V_13 ;
break;
default:
break;
}
} else {
F_2 ( L_2 , V_6 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
if ( V_3 == V_6 )
return true ^ V_2 -> V_13 ;
break;
case V_14 :
if ( V_4 == V_6 )
return true ^ V_2 -> V_13 ;
break;
case V_15 :
if ( V_3 == V_6 || V_4 == V_6 )
return true ^ V_2 -> V_13 ;
break;
default:
break;
}
}
}
return V_2 -> V_13 ;
}
static bool
F_3 ( const struct V_16 * V_17 , struct V_18 * V_19 )
{
const T_2 * V_20 ;
T_2 V_21 [ 2 ] ;
const struct V_1 * V_22 = V_19 -> V_23 ;
if ( V_19 -> V_24 != 0 )
return false ;
V_20 = F_4 ( V_17 , V_19 -> V_25 , sizeof( V_21 ) , V_21 ) ;
if ( V_20 == NULL ) {
F_2 ( L_3 ) ;
V_19 -> V_26 = true ;
return false ;
}
return F_1 ( V_22 , F_5 ( V_20 [ 0 ] ) , F_5 ( V_20 [ 1 ] ) ) ;
}
static inline bool
F_6 ( T_1 V_27 ,
T_3 V_28 ,
T_3 V_29 ,
T_3 V_8 )
{
return ( V_27 == V_30 || V_27 == V_31
|| V_27 == V_32
|| V_27 == V_33 || V_27 == V_34 )
&& ! ( V_28 & V_35 )
&& ( V_29 == V_12
|| V_29 == V_14
|| V_29 == V_15 )
&& V_8 <= V_36 ;
}
static int F_7 ( const struct V_37 * V_19 )
{
const struct V_38 * V_39 = V_19 -> V_40 ;
const struct V_1 * V_22 = V_19 -> V_23 ;
return F_6 ( V_39 -> V_27 , V_39 -> V_41 , V_22 -> V_11 ,
V_22 -> V_8 ) ? 0 : - V_42 ;
}
static int F_8 ( const struct V_37 * V_19 )
{
const struct V_43 * V_39 = V_19 -> V_40 ;
const struct V_1 * V_22 = V_19 -> V_23 ;
return F_6 ( V_39 -> V_27 , V_39 -> V_41 , V_22 -> V_11 ,
V_22 -> V_8 ) ? 0 : - V_42 ;
}
static int T_4 F_9 ( void )
{
return F_10 ( V_44 ,
F_11 ( V_44 ) ) ;
}
static void T_5 F_12 ( void )
{
F_13 ( V_44 , F_11 ( V_44 ) ) ;
}
