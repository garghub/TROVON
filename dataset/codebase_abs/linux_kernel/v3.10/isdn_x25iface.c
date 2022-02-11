static void F_1 ( unsigned V_1 , unsigned char V_2 )
{
F_2 ( V_3 L_1
L_2 , V_2 , V_1 ) ;
}
static int F_3 ( T_1 * V_4 ) {
if ( V_4 && V_4 -> V_5 == V_6 ) return 0 ;
F_2 ( V_3
L_3 ) ;
return 1 ;
}
struct V_7 * F_4 ( void )
{
T_1 * V_8 = F_5 ( sizeof( T_1 ) , V_9 ) ;
F_6 ( L_4 ) ;
if ( V_8 ) {
V_8 -> V_5 = V_6 ;
V_8 -> V_1 = V_10 ;
F_7 ( & V_8 -> V_11 . V_12 ) ;
V_8 -> V_11 . V_13 = NULL ;
V_8 -> V_11 . V_14 = NULL ;
V_8 -> V_11 . V_15 = & V_16 ;
V_8 -> V_11 . V_17 = 0 ;
V_8 -> V_11 . V_18 = V_8 ;
return ( & ( V_8 -> V_11 ) ) ;
}
return NULL ;
}
static int F_8 ( struct V_7 * V_19 ) {
T_1 * V_8 ;
int V_20 = 0 ;
T_2 V_17 ;
if ( ! V_19 ) {
F_2 ( V_21 L_5
L_6 ) ;
return - 1 ;
}
F_6 ( L_7 , F_9 ( V_19 -> V_14 ) ) ;
F_10 ( & V_19 -> V_12 , V_17 ) ;
V_19 -> V_13 = NULL ;
V_19 -> V_14 = NULL ;
V_8 = V_19 -> V_18 ;
if ( F_3 ( V_8 ) ) {
V_20 = - 1 ;
} else {
V_8 -> V_1 = V_10 ;
}
F_11 ( & V_19 -> V_12 , V_17 ) ;
return V_20 ;
}
static void F_12 ( struct V_7 * V_19 ) {
T_1 * V_8 ;
F_6 ( L_8 ) ;
if ( ! V_19 ) {
F_2 ( V_21 L_9
L_10 ) ;
return;
}
V_8 = V_19 -> V_18 ;
if ( V_8 == NULL ) {
F_2 ( V_21 L_11
L_12 ) ;
return;
}
if ( V_19 -> V_13 ) F_8 ( V_19 ) ;
V_8 -> V_5 = 0 ;
V_19 -> V_18 = NULL ;
F_13 ( V_8 ) ;
return;
}
static int F_14 ( struct V_7 * V_19 ,
struct V_22 * V_23 ,
struct V_24 * V_13 )
{
T_1 * V_4 = V_19 -> V_18 ;
T_2 V_17 ;
F_6 ( L_13 , F_9 ( V_23 ) ) ;
if ( F_3 ( V_4 ) ) return - 1 ;
if ( ! ( V_13 && V_13 -> V_25 && V_13 -> V_26
&& V_13 -> V_27 ) ) {
F_2 ( V_3 L_14
L_15 ) ;
F_8 ( V_19 ) ;
return - 1 ;
}
F_10 ( & V_19 -> V_12 , V_17 ) ;
V_19 -> V_14 = V_23 ;
V_19 -> V_15 = & V_16 ;
V_19 -> V_13 = V_13 ;
V_4 -> V_1 = V_28 ;
F_11 ( & V_19 -> V_12 , V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_19 , struct V_29 * V_30 )
{
F_6 ( L_16 , F_9 ( V_19 -> V_14 ) ) ;
if ( ( ( T_1 * ) ( V_19 -> V_18 ) )
-> V_1 == V_31 ) {
if ( F_16 ( V_30 , 1 ) ) {
V_30 -> V_32 [ 0 ] = V_33 ;
V_30 -> V_34 = F_17 ( V_30 , V_19 -> V_14 ) ;
F_18 ( V_30 ) ;
return 0 ;
}
}
F_2 ( V_3 L_17 , F_9 ( V_19 -> V_14 ) ) ;
F_19 ( V_30 ) ;
return - 1 ;
}
static int F_20 ( struct V_7 * V_19 )
{
struct V_29 * V_30 ;
enum V_35 * V_36
= & ( ( ( T_1 * ) ( V_19 -> V_18 ) ) -> V_1 ) ;
F_6 ( L_18
, F_9 ( V_19 -> V_14 ) ) ;
if ( * V_36 == V_10 ) {
F_2 ( V_3
L_19
, F_9 ( V_19 -> V_14 ) ) ;
return - 1 ;
}
* V_36 = V_31 ;
V_30 = F_21 ( 1 ) ;
if ( V_30 ) {
* ( F_22 ( V_30 , 1 ) ) = V_37 ;
V_30 -> V_34 = F_17 ( V_30 , V_19 -> V_14 ) ;
F_18 ( V_30 ) ;
return 0 ;
} else {
F_2 ( V_3 L_20
L_21 ) ;
V_19 -> V_13 -> V_27 ( V_19 ) ;
return - 1 ;
}
}
static int F_23 ( struct V_7 * V_19 )
{
struct V_29 * V_30 ;
enum V_35 * V_36
= & ( ( ( T_1 * ) ( V_19 -> V_18 ) ) -> V_1 ) ;
F_6 ( L_22 , F_9 ( V_19 -> V_14 ) ) ;
if ( * V_36 == V_10 ) {
F_2 ( V_3
L_23 ) ;
return - 1 ;
}
if ( ! V_19 -> V_14 ) return - 1 ;
* V_36 = V_28 ;
V_30 = F_21 ( 1 ) ;
if ( V_30 ) {
* ( F_22 ( V_30 , 1 ) ) = V_38 ;
V_30 -> V_34 = F_17 ( V_30 , V_19 -> V_14 ) ;
F_18 ( V_30 ) ;
return 0 ;
} else {
F_2 ( V_3 L_24
L_25 ) ;
return - 1 ;
}
}
static int F_24 ( struct V_7 * V_19 , struct V_29 * V_30 )
{
unsigned char V_2 = V_30 -> V_32 [ 0 ] ;
enum V_35 * V_1 = & ( ( T_1 * ) V_19 -> V_18 ) -> V_1 ;
int V_20 = 0 ;
F_6 ( L_26 ,
F_9 ( V_19 -> V_14 ) , V_2 , * V_1 ) ;
switch ( V_2 ) {
case V_33 :
if ( * V_1 == V_31 ) {
F_25 ( V_30 , 1 ) ;
V_19 -> V_14 -> V_39 = V_40 ;
V_20 = ( V_19 -> V_13 -> V_25 ( V_19 , V_30 ) ) ;
if ( V_20 ) F_16 ( V_30 , 1 ) ;
return V_20 ;
}
F_1 ( * V_1 , V_2 ) ;
break;
case V_37 :
if ( * V_1 == V_28 ) {
* V_1 = V_41 ;
V_20 = V_19 -> V_13 -> V_26 ( V_19 ) ;
if ( V_20 ) {
F_23 ( V_19 ) ;
}
} else {
F_1 ( * V_1 , V_2 ) ;
}
break;
case V_38 :
switch ( * V_1 ) {
case V_28 :
F_2 ( V_3 L_27
L_28 ) ;
F_23 ( V_19 ) ;
break;
case V_41 :
case V_31 :
* V_1 = V_28 ;
V_19 -> V_13 -> V_27 ( V_19 ) ;
break;
default:
F_1 ( * V_1 , V_2 ) ;
}
break;
case V_42 :
F_2 ( V_3 L_29
L_30 ) ;
break;
default:
F_2 ( V_3 L_31
L_32 , V_2 ) ;
}
F_19 ( V_30 ) ;
return 0 ;
}
