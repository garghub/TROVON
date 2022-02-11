static void F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
F_3 ( & V_4 -> V_5 , V_3 ) ;
F_3 ( & V_4 -> V_6 , V_3 ) ;
F_3 ( & V_4 -> V_7 , V_3 ) ;
F_3 ( & V_4 -> V_8 , V_3 ) ;
}
static void F_4 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
F_3 ( & V_9 -> V_10 , V_3 ) ;
F_3 ( & V_9 -> V_11 , V_3 ) ;
F_3 ( & V_9 -> V_12 , V_3 ) ;
F_3 ( & V_9 -> V_13 , V_3 ) ;
}
static void F_5 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
F_6 ( & V_4 -> V_5 , V_3 ) ;
F_6 ( & V_4 -> V_6 , V_3 ) ;
F_6 ( & V_4 -> V_7 , V_3 ) ;
F_6 ( & V_4 -> V_8 , V_3 ) ;
}
static void F_7 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
F_6 ( & V_9 -> V_10 , V_3 ) ;
F_6 ( & V_9 -> V_11 , V_3 ) ;
F_6 ( & V_9 -> V_12 , V_3 ) ;
F_6 ( & V_9 -> V_13 , V_3 ) ;
}
static void F_8 ( bool V_14 , T_1 V_3 )
{
if ( V_14 )
F_3 ( & V_4 -> V_15 , V_3 ) ;
else
F_6 ( & V_4 -> V_15 , V_3 ) ;
}
static void F_9 ( bool V_14 , T_1 V_3 )
{
if ( V_14 )
F_3 ( & V_9 -> V_15 [ 0 ] , V_3 ) ;
else
F_6 ( & V_9 -> V_15 [ 0 ] , V_3 ) ;
}
static void F_10 ( int V_1 , int V_16 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
switch ( V_16 ) {
case V_17 :
F_3 ( & V_4 -> V_18 , V_3 ) ;
break;
case V_19 :
F_3 ( & V_4 -> V_20 , V_3 ) ;
break;
default:
F_11 ( L_1 , V_16 ) ;
break;
}
}
static void F_12 ( int V_1 , int V_16 )
{
int V_2 = F_2 ( V_1 ) ;
T_1 V_3 = 1 << F_13 ( V_1 ) ;
switch ( V_16 ) {
case V_17 :
F_3 ( & V_9 -> V_21 , 1 << V_2 ) ;
break;
case V_19 :
F_3 ( & V_9 -> V_22 , V_3 ) ;
break;
case V_23 :
F_3 ( & V_9 -> V_24 , V_3 ) ;
break;
case V_25 :
F_3 ( & V_9 -> V_26 , V_3 ) ;
break;
default:
F_11 ( L_1 , V_16 ) ;
}
}
static void F_14 ( int V_1 )
{
F_10 ( V_1 , V_19 ) ;
}
static void F_15 ( int V_1 )
{
int V_27 = F_16 ( V_1 ) ;
F_17 ( V_27 ) ;
}
static void F_18 ( int V_1 )
{
#ifdef F_19
int V_28 ;
if ( V_29 == 2 ) {
V_28 = F_20 ( V_1 ) ;
if ( F_21 ( V_28 ) && F_21 ( V_28 + 1 ) ) {
F_12 ( V_1 , V_23 ) ;
} else {
F_15 ( V_1 ) ;
}
}
#endif
if ( V_29 == 1 )
F_12 ( V_1 , V_23 ) ;
}
static void F_22 ( int V_1 , int V_16 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned int V_3 = 1 << V_2 ;
switch ( V_16 ) {
case V_17 :
F_6 ( & V_4 -> V_18 , V_3 ) ;
break;
case V_19 :
F_6 ( & V_4 -> V_20 , V_3 ) ;
break;
default:
F_11 ( L_1 , V_16 ) ;
break;
}
}
static void F_23 ( int V_1 )
{
F_22 ( V_1 , V_19 ) ;
F_5 ( V_1 ) ;
}
static void F_24 ( int V_1 , int V_16 )
{
int V_2 = F_2 ( V_1 ) ;
T_1 V_3 = 1 << F_13 ( V_1 ) ;
switch ( V_16 ) {
case V_17 :
F_3 ( & V_9 -> V_30 , 1 << V_2 ) ;
break;
case V_19 :
F_3 ( & V_9 -> V_31 , V_3 ) ;
break;
case V_23 :
F_3 ( & V_9 -> V_32 , V_3 ) ;
break;
case V_25 :
F_3 ( & V_9 -> V_33 , V_3 ) ;
break;
default:
F_11 ( L_1 , V_16 ) ;
}
}
static void F_25 ( int V_1 )
{
F_24 ( V_1 , V_23 ) ;
F_7 ( V_1 ) ;
}
static int F_26 ( int V_16 )
{
T_1 * V_34 = & V_4 -> V_35 ;
int V_36 = 0 ;
int V_37 ;
switch ( V_16 ) {
case V_38 :
F_3 ( V_34 , V_39 ) ;
V_37 = F_27 (
! ( F_28 ( V_34 ) & V_39 ) , 10000 , 10 ) ;
if ( ! V_37 ) {
F_29 ( L_2 ) ;
V_36 = - V_40 ;
}
break;
default:
F_11 ( L_3 , V_16 ) ;
V_36 = - V_41 ;
}
return V_36 ;
}
static int F_30 ( int V_16 )
{
T_1 * V_34 = & V_9 -> V_35 ;
int V_36 = 0 ;
int V_37 ;
switch ( V_16 ) {
case V_42 :
F_3 ( V_34 , V_43 ) ;
F_3 ( V_34 , V_44 ) ;
V_37 = F_27 (
! ( F_28 ( V_34 ) & V_45 ) , 10000 , 10 ) ;
if ( ! V_37 ) {
F_29 ( L_4 ) ;
V_36 = - V_40 ;
}
break;
default:
F_11 ( L_5 , V_16 ) ;
V_36 = - V_41 ;
}
return V_36 ;
}
static int F_31 ( void )
{
return F_26 ( V_38 ) ;
}
static int F_32 ( void )
{
return F_30 ( V_42 ) ;
}
static void F_33 ( T_1 * V_46 , int V_47 )
{
static T_1 V_3 ;
if ( V_47 ) {
V_3 = F_28 ( V_46 ) ;
F_6 ( V_46 , V_3 ) ;
} else {
F_3 ( V_46 , V_3 ) ;
}
F_28 ( V_46 ) ;
}
static void F_34 ( bool V_47 )
{
F_33 ( & V_4 -> V_48 , V_47 ) ;
}
static void F_35 ( bool V_47 )
{
F_33 ( & V_9 -> V_49 , V_47 ) ;
}
static unsigned int F_36 ( void )
{
return V_50 ;
}
int T_2 F_37 ( void )
{
struct V_51 * V_52 ;
const struct V_53 * V_54 ;
void T_3 * V_55 ;
V_52 = F_38 ( NULL , V_56 , & V_54 ) ;
if ( ! V_52 )
return 0 ;
V_55 = F_39 ( V_52 , 0 ) ;
F_40 ( V_52 ) ;
if ( ! V_55 ) {
F_29 ( L_6 ) ;
return - V_57 ;
}
V_4 = V_55 ;
V_9 = V_55 ;
V_50 = V_58 ;
V_59 = V_54 -> V_60 ;
return 0 ;
}
