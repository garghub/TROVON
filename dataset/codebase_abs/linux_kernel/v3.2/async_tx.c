static int T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 L_1 ) ;
return 0 ;
}
static void T_2 F_4 ( void )
{
F_5 () ;
}
struct V_2 *
F_6 ( struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 &&
F_7 ( V_6 , V_8 -> V_9 -> V_10 -> V_11 ) )
return V_8 -> V_9 ;
return F_8 ( V_6 ) ;
}
static void
F_9 ( struct V_7 * V_8 ,
struct V_7 * V_12 )
{
struct V_2 * V_9 = V_8 -> V_9 ;
struct V_13 * V_10 = V_9 -> V_10 ;
struct V_7 * V_14 = ( void * ) ~ 0 ;
F_10 ( V_8 ) ;
if ( F_11 ( V_8 ) && V_8 -> V_9 == V_12 -> V_9 ) {
F_12 ( V_8 , V_12 ) ;
V_14 = NULL ;
}
F_13 ( V_8 ) ;
if ( ! V_14 ) {
V_10 -> V_15 ( V_9 ) ;
return;
}
if ( F_7 ( V_16 , V_10 -> V_11 ) )
V_14 = V_10 -> V_17 ( V_9 , 0 ) ;
else
V_14 = NULL ;
if ( V_14 ) {
V_14 -> V_18 = NULL ;
V_14 -> V_19 = NULL ;
F_12 ( V_14 , V_12 ) ;
F_10 ( V_8 ) ;
if ( F_11 ( V_8 ) ) {
F_12 ( V_8 , V_14 ) ;
F_14 ( V_14 ) ;
V_14 = NULL ;
}
F_13 ( V_8 ) ;
if ( V_14 ) {
F_15 ( V_14 ) ;
V_14 -> V_20 ( V_14 ) ;
F_14 ( V_14 ) ;
}
V_10 -> V_15 ( V_9 ) ;
} else {
if ( F_16 ( V_8 ) == V_21 )
F_17 ( L_2 ,
V_22 ) ;
V_12 -> V_20 ( V_12 ) ;
}
}
void
F_18 ( struct V_2 * V_9 , struct V_7 * V_12 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_12 -> V_18 = V_4 -> V_23 ;
V_12 -> V_19 = V_4 -> V_24 ;
if ( V_8 ) {
enum V_25 V_26 ;
F_19 ( F_20 ( V_8 ) || F_21 ( V_8 ) ||
F_11 ( V_12 ) ) ;
F_10 ( V_8 ) ;
if ( F_11 ( V_8 ) ) {
if ( V_8 -> V_9 == V_9 ) {
F_12 ( V_8 , V_12 ) ;
V_26 = V_27 ;
} else
V_26 = V_28 ;
} else {
if ( V_8 -> V_9 == V_9 )
V_26 = V_29 ;
else
V_26 = V_28 ;
}
F_13 ( V_8 ) ;
switch ( V_26 ) {
case V_27 :
break;
case V_28 :
F_9 ( V_8 , V_12 ) ;
break;
case V_29 :
F_15 ( V_12 ) ;
V_12 -> V_20 ( V_12 ) ;
break;
}
} else {
F_15 ( V_12 ) ;
V_12 -> V_20 ( V_12 ) ;
}
if ( V_4 -> V_30 & V_31 )
F_14 ( V_12 ) ;
if ( V_8 )
F_14 ( V_8 ) ;
}
struct V_7 *
F_22 ( struct V_3 * V_4 )
{
struct V_2 * V_9 ;
struct V_13 * V_10 ;
struct V_7 * V_12 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 ) {
V_9 = V_8 -> V_9 ;
V_10 = V_9 -> V_10 ;
if ( V_10 && ! F_7 ( V_16 , V_10 -> V_11 ) )
V_10 = NULL ;
V_12 = V_10 ? V_10 -> V_17 ( V_9 , 0 ) : NULL ;
} else
V_12 = NULL ;
if ( V_12 ) {
F_23 ( L_3 , V_22 ) ;
F_18 ( V_9 , V_12 , V_4 ) ;
} else {
F_23 ( L_4 , V_22 ) ;
F_24 ( & V_4 -> V_8 ) ;
F_25 ( V_4 ) ;
}
return V_12 ;
}
void F_24 ( struct V_7 * * V_12 )
{
if ( * V_12 ) {
F_19 ( F_20 ( * V_12 ) ) ;
if ( F_16 ( * V_12 ) == V_21 )
F_17 ( L_5 ) ;
F_14 ( * V_12 ) ;
* V_12 = NULL ;
}
}
