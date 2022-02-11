static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( 0 == F_2 ( V_4 -> V_5 ) &&
V_2 -> V_5 == V_4 -> V_5 -> V_6 &&
V_2 -> V_7 == F_3 ( V_4 -> V_8 ) &&
V_2 -> V_9 == F_4 ( V_4 -> V_8 ) ) ;
}
static int F_5 ( struct V_10 * V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_1 * V_2 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
switch ( V_11 -> type ) {
case V_18 :
V_15 = V_19 ;
break;
case V_20 :
V_15 = V_21 ;
break;
case V_22 :
if ( ( V_14 -> V_3 -> V_23 >> 16 ) == V_24 )
V_16 = 1 ;
break;
default:
return 0 ;
}
V_2 = (struct V_1 * ) ( V_11 + 1 ) ;
if ( V_2 -> V_25 & V_26 ) {
if ( ( V_14 -> V_3 -> V_27 &&
V_14 -> V_3 -> V_15 == V_15 ) || V_16 )
V_17 = ! ! ( V_2 -> V_25 & V_28 ) ;
} else
if ( F_1 ( V_2 , V_14 -> V_3 ) )
V_17 = ! ! ( V_2 -> V_25 & V_28 ) ;
V_14 -> V_29 = V_17 ;
return 0 ;
}
static void F_6 ( struct V_3 * V_3 )
{
int V_30 ;
struct V_13 V_14 = {
. V_3 = V_3 ,
. V_29 = 0 ,
} ;
V_30 = F_7 ( F_5 , & V_14 ) ;
if ( V_30 )
V_3 -> V_31 = 0 ;
else
V_3 -> V_31 = V_14 . V_29 ;
V_3 -> V_32 = 1 ;
}
int F_8 ( struct V_3 * V_33 )
{
if ( ! V_33 -> V_32 )
F_6 ( V_33 ) ;
return V_33 -> V_31 ;
}
static int F_9 ( struct V_10 * V_11 , void * V_12 )
{
struct V_1 * V_2 ;
if ( V_34 )
return 0 ;
switch ( V_11 -> type ) {
case V_18 :
case V_20 :
case V_22 :
V_2 = (struct V_1 * ) ( V_11 + 1 ) ;
V_34 = ! ! ( V_2 -> V_25 & V_28 ) ;
default:
return 0 ;
}
}
bool F_10 ( void )
{
static bool V_35 = false ;
if ( ! V_35 ) {
F_7 ( F_9 , NULL ) ;
V_35 = true ;
}
return V_34 ;
}
