static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
V_11 = F_2 ( V_2 , & V_9 ) ;
if ( V_11 == NULL || F_3 ( V_11 ) )
return V_13 ;
switch ( V_6 -> V_14 ) {
case V_15 :
V_12 = ( V_11 -> V_16 & ~ V_6 -> V_17 ) ^ V_6 -> V_18 ;
if ( V_11 -> V_16 != V_12 ) {
V_11 -> V_16 = V_12 ;
F_4 ( V_19 , V_11 ) ;
}
break;
case V_20 :
V_12 = ( V_11 -> V_16 & ~ V_6 -> V_17 ) ^
( V_2 -> V_16 & V_6 -> V_21 ) ;
if ( V_11 -> V_16 != V_12 ) {
V_11 -> V_16 = V_12 ;
F_4 ( V_19 , V_11 ) ;
}
break;
case V_22 :
V_12 = ( V_2 -> V_16 & ~ V_6 -> V_21 ) ^
( V_11 -> V_16 & V_6 -> V_17 ) ;
V_2 -> V_16 = V_12 ;
break;
}
return V_13 ;
}
static int F_5 ( const struct V_23 * V_4 )
{
int V_24 ;
V_24 = F_6 ( V_4 -> V_25 ) ;
if ( V_24 < 0 )
F_7 ( L_1 ,
V_4 -> V_25 ) ;
return V_24 ;
}
static void F_8 ( const struct V_26 * V_4 )
{
F_9 ( V_4 -> V_25 ) ;
}
static bool
F_10 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_27 * V_6 = V_4 -> V_28 ;
enum V_8 V_9 ;
const struct V_10 * V_11 ;
V_11 = F_2 ( V_2 , & V_9 ) ;
if ( V_11 == NULL || F_3 ( V_11 ) )
return false ;
return ( ( V_11 -> V_16 & V_6 -> V_29 ) == V_6 -> V_16 ) ^ V_6 -> V_30 ;
}
static int F_11 ( const struct V_31 * V_4 )
{
int V_24 ;
V_24 = F_6 ( V_4 -> V_25 ) ;
if ( V_24 < 0 )
F_7 ( L_1 ,
V_4 -> V_25 ) ;
return V_24 ;
}
static void F_12 ( const struct V_32 * V_4 )
{
F_9 ( V_4 -> V_25 ) ;
}
static int T_2 F_13 ( void )
{
int V_24 ;
V_24 = F_14 ( & V_33 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_15 ( & V_34 ) ;
if ( V_24 < 0 ) {
F_16 ( & V_33 ) ;
return V_24 ;
}
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_34 ) ;
F_16 ( & V_33 ) ;
}
