static void F_1 ( void * V_1 , T_1 V_2 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 V_4 = & V_3 -> V_5 ;
bool V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
V_6 = ( V_10 -> V_11 >= 0x01 ) ? true : false ;
if ( V_4 -> V_2 == V_2 )
return;
V_4 -> V_2 = V_2 ;
V_2 = V_2 & 0x3F ;
F_3 (
V_3 -> V_8 ,
V_12 ,
0x00FFF000 ,
( V_2 | ( V_2 << 6 ) )
) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_1 ,
V_2
)
) ;
}
static T_1 F_5 ( void * V_1 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_1 V_2 = 0x20 ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
V_2 = V_10 -> V_2 ;
V_2 = V_2 & 0x3f ;
return V_2 ;
}
static void F_6 ( void * V_1 , bool V_15 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 V_4 = & V_3 -> V_5 ;
if ( V_4 -> V_16 == V_15 )
return;
F_3 (
V_3 -> V_8 ,
F_7 ( V_17 , V_3 ) ,
F_8 ( V_17 , V_3 ) ,
V_15
) ;
V_4 -> V_16 = V_15 ;
}
static bool F_9 ( void * V_1 )
{
bool V_15 ;
T_2 V_3 = ( T_2 ) V_1 ;
V_15 = ( bool ) F_10 (
V_3 -> V_8 ,
F_7 ( V_17 , V_3 ) ,
F_8 ( V_17 , V_3 )
) ;
return V_15 ;
}
void F_11 ( void * V_1 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 V_4 = & V_3 -> V_5 ;
V_4 -> V_18 = F_5 ( V_3 ) ;
V_4 -> V_19 = true ;
F_1 ( V_3 , V_4 -> V_18 ) ;
F_6 ( V_3 , true ) ;
}
void F_12 ( void * V_1 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 V_4 = & V_3 -> V_5 ;
V_4 -> V_18 =
V_4 -> V_2 = F_5 ( V_3 ) ;
V_4 -> V_16 = F_9 ( V_3 ) ;
V_4 -> V_19 = true ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_2 )
) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_3 ,
V_4 -> V_16 ,
V_4 -> V_18
)
) ;
}
void F_13 ( void * V_1 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 V_4 = & V_3 -> V_5 ;
int V_20 , V_21 , V_22 = 0 ;
int V_23 ;
int V_2 = ( int ) V_4 -> V_2 ;
T_1 V_24 = 1 ;
if ( ! ( V_3 -> V_25 & V_26 ) ) {
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_4 )
) ;
return;
}
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_5 )
) ;
if ( ! V_3 -> V_27 || ! V_3 -> V_28 ) {
F_11 ( V_3 ) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_6 ,
V_3 -> V_27 ,
V_3 -> V_28
)
) ;
} else {
if ( V_4 -> V_29 == V_4 -> V_30 ) {
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_7
)
) ;
return;
}
V_4 -> V_30 = V_4 -> V_29 ;
V_20 = ( int ) ( V_4 -> V_31 [ 0 ] * 3125 ) / 1280 ;
V_21 = ( int ) ( V_4 -> V_31 [ 1 ] * 3125 ) / 1280 ;
if ( V_3 -> V_32 < V_33 )
V_22 = V_20 ;
else
V_22 = ( int ) ( V_20 + V_21 ) >> 1 ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_8 ,
V_20 ,
V_21 ,
V_22
)
) ;
V_23 =
( V_4 -> V_34 >= V_22 ) ?
( V_4 -> V_34 - V_22 ) :
( V_22 - V_4 -> V_34 ) ;
if (
V_23 > 20 &&
V_4 -> V_35 == 0 &&
! V_4 -> V_19
) {
F_4 ( V_3 , V_13 , V_14 , ( L_9 ) ) ;
V_4 -> V_35 = 1 ;
return;
} else
V_4 -> V_35 = 0 ;
V_4 -> V_34 = V_22 ;
if ( V_4 -> V_19 == false ) {
if ( V_22 > V_36 || V_22 < ( - V_36 ) )
V_4 -> V_19 = true ;
} else {
if ( V_22 < V_37 && V_22 > ( - V_37 ) )
V_4 -> V_19 = false ;
}
if ( V_3 -> V_38 ) {
V_4 -> V_19 = false ;
F_1 ( V_3 , V_4 -> V_18 ) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_10 )
) ;
}
if ( V_4 -> V_19 ) {
if ( V_22 > V_37 )
V_24 = V_24 + ( ( V_22 - V_37 ) >> 2 ) ;
else if ( V_22 < ( - V_37 ) )
V_24 = V_24 + ( ( V_37 - V_22 ) >> 2 ) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_11 ,
V_24
)
) ;
}
if ( V_4 -> V_19 ) {
if ( V_22 > V_37 )
V_2 = V_2 + V_24 ;
else if ( V_22 < ( - V_37 ) )
V_2 = V_2 - V_24 ;
if ( V_2 > 0x3f )
V_2 = 0x3f ;
else if ( V_2 < 0 )
V_2 = 0 ;
F_1 ( V_3 , ( T_1 ) V_2 ) ;
}
F_4 (
V_3 ,
V_13 ,
V_14 ,
(
L_12 ,
V_4 -> V_2 ,
V_4 -> V_18
)
) ;
if ( V_22 < V_39 && V_22 > - V_39 ) {
F_6 ( V_3 , false ) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_13 )
) ;
} else {
F_6 ( V_3 , true ) ;
F_4 (
V_3 ,
V_13 ,
V_14 ,
( L_14 )
) ;
}
}
}
void F_14 ( void * V_1 , void * V_40 , T_4 * V_41 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_5 V_42 = ( T_5 ) V_40 ;
T_3 V_4 = & V_3 -> V_5 ;
T_1 V_43 ;
if ( ! ( V_3 -> V_25 & V_26 ) )
return;
if ( V_42 -> V_44 != 0 ) {
for ( V_43 = V_45 ; V_43 <= V_46 ; V_43 ++ )
V_4 -> V_31 [ V_43 ] = ( int ) V_41 [ V_43 ] ;
if ( V_4 -> V_29 == 0xffffffff )
V_4 -> V_29 = 0 ;
else
V_4 -> V_29 ++ ;
}
}
