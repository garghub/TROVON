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
V_7 = ( unsigned short * ) F_8 ( F_9 ( 2 ) , 512 ) ;
if ( ! V_7 ) {
V_15 = - V_16 ;
goto V_17;
}
V_5 = 0xffff ;
* V_7 = V_5 ;
V_15 = F_10 ( & V_14 -> V_18 , & V_19 ) ;
if ( V_15 < 0 )
goto V_20;
V_15 = F_10 ( & V_14 -> V_18 , & V_21 ) ;
if ( V_15 < 0 )
goto V_22;
V_15 = F_10 ( & V_14 -> V_18 , & V_23 ) ;
if ( V_15 < 0 )
goto V_24;
V_15 = F_10 ( & V_14 -> V_18 , & V_25 ) ;
if ( V_15 < 0 )
goto V_26;
V_15 = F_10 ( & V_14 -> V_18 , & V_27 ) ;
if ( V_15 < 0 )
goto V_28;
V_15 = F_10 ( & V_14 -> V_18 , & V_29 ) ;
if ( V_15 < 0 )
goto V_30;
return V_15 ;
V_30:
F_11 ( & V_27 ) ;
V_28:
F_11 ( & V_25 ) ;
V_26:
F_11 ( & V_23 ) ;
V_24:
F_11 ( & V_21 ) ;
V_22:
F_11 ( & V_19 ) ;
V_20:
F_12 ( V_7 ) ;
V_17:
return V_15 ;
}
static int F_13 ( struct V_13 * V_14 )
{
F_11 ( & V_19 ) ;
F_11 ( & V_21 ) ;
F_11 ( & V_23 ) ;
F_11 ( & V_25 ) ;
F_11 ( & V_27 ) ;
F_11 ( & V_29 ) ;
F_12 ( V_7 ) ;
return 0 ;
}
