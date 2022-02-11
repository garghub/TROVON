static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_6 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_6 ) ;
* V_7 = V_5 ;
}
}
static void F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_8 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_8 ) ;
* V_7 = V_5 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_9 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_9 ) ;
* V_7 = V_5 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_10 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_10 ) ;
* V_7 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_11 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_11 ) ;
* V_7 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 ) {
V_5 &= ~ ( 1 << V_12 ) ;
* V_7 = V_5 ;
} else {
V_5 |= ( 1 << V_12 ) ;
* V_7 = V_5 ;
}
}
static int F_7 ( struct V_13 * V_14 )
{
int V_15 ;
V_7 = ( unsigned short * ) F_8 ( & V_14 -> V_16 ,
F_9 ( 2 ) , 512 ) ;
if ( ! V_7 )
return - V_17 ;
V_5 = 0xffff ;
* V_7 = V_5 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_18 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_20 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_21 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_22 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( & V_14 -> V_16 , & V_23 ) ;
if ( V_15 < 0 )
return V_15 ;
return V_15 ;
}
