static void F_1 ( void )
{
int V_1 ;
switch ( V_2 ) {
case V_3 :
V_1 = 1 ;
break;
case V_4 :
V_1 = 0 ;
break;
case V_5 :
V_1 = V_6 ;
break;
case V_7 :
default:
V_1 = ! V_6 ;
break;
}
if ( V_1 == V_8 )
return;
V_8 = V_1 ;
F_2 ( V_8 ) ;
}
static void F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( V_15 )
V_15 ( V_10 , V_12 , V_14 ) ;
if ( ! V_14 || ! F_2 )
return;
if ( strcmp ( L_1 , V_14 -> V_16 . V_17 ) == 0 && V_14 -> V_16 . V_18 == 0 ) {
V_6 = ( V_14 -> V_19 . integer . V_19 [ 0 ] ||
V_14 -> V_19 . integer . V_19 [ 1 ] ) ;
F_1 () ;
}
}
static int F_4 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
static const char * const V_22 [] = {
L_2 , L_3 , L_4 , L_5 ,
} ;
return F_5 ( V_21 , 1 , F_6 ( V_22 ) , V_22 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> V_19 . V_23 . V_24 [ 0 ] = V_2 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
unsigned int V_25 ;
V_25 = V_14 -> V_19 . V_23 . V_24 [ 0 ] ;
if ( V_25 > V_7 )
V_25 = V_7 ;
if ( V_25 == V_2 )
return 0 ;
V_2 = V_25 ;
F_1 () ;
return 1 ;
}
static void F_9 ( struct V_9 * V_10 ,
const struct V_26 * V_27 , int V_28 )
{
struct V_29 * V_30 = V_10 -> V_30 ;
bool V_31 = false ;
if ( V_28 == V_32 ) {
if ( ! F_2 )
F_2 = F_10 ( V_33 ) ;
if ( ! F_2 ) {
F_11 ( V_10 , L_6 ) ;
return;
}
V_31 = true ;
if ( F_2 ( false ) >= 0 ) {
V_8 = 0 ;
if ( V_30 -> V_34 . V_35 > 1 && ! V_30 -> V_34 . V_36 )
F_12 ( V_10 , L_7 ) ;
else {
V_15 = V_30 -> V_34 . V_37 ;
V_30 -> V_34 . V_37 = F_3 ;
V_31 = false ;
F_13 ( V_30 , V_38 ) ;
}
}
}
if ( F_2 && ( V_28 == V_39 || V_31 ) ) {
F_14 ( V_33 ) ;
F_2 = NULL ;
V_15 = NULL ;
}
}
static void F_9 ( struct V_9 * V_10 ,
const struct V_26 * V_27 , int V_28 )
{
}
