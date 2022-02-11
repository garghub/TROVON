static void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
struct V_4 * V_5 ;
enum V_6 V_7 ;
V_5 = F_2 ( V_2 , & V_7 ) ;
if ( V_5 && ! V_5 -> V_3 ) {
V_5 -> V_3 = V_2 -> V_3 ;
F_3 ( V_8 , V_5 ) ;
}
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
const struct V_4 * V_5 ;
enum V_6 V_7 ;
V_5 = F_2 ( V_2 , & V_7 ) ;
if ( V_5 && V_5 -> V_3 )
V_2 -> V_3 = V_5 -> V_3 ;
}
}
static unsigned int
F_5 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
const struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_12 -> V_14 ) {
case V_15 :
F_1 ( V_2 ) ;
break;
case V_16 :
F_4 ( V_2 ) ;
break;
default:
F_6 () ;
}
return V_17 ;
}
static int F_7 ( const struct V_18 * V_10 )
{
const struct V_11 * V_12 = V_10 -> V_13 ;
int V_19 ;
if ( strcmp ( V_10 -> V_20 , L_1 ) != 0 &&
strcmp ( V_10 -> V_20 , L_2 ) != 0 ) {
F_8 ( L_3
L_4 , V_10 -> V_20 ) ;
return - V_21 ;
}
switch ( V_12 -> V_14 ) {
case V_15 :
case V_16 :
break;
default:
F_8 ( L_5 , V_12 -> V_14 ) ;
return - V_21 ;
}
V_19 = F_9 ( V_10 -> V_22 , V_10 -> V_23 ) ;
if ( V_19 < 0 )
F_8 ( L_6 ,
V_10 -> V_23 ) ;
return V_19 ;
}
static void F_10 ( const struct V_24 * V_10 )
{
F_11 ( V_10 -> V_22 , V_10 -> V_23 ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_25 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_25 ) ;
}
