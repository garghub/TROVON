static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
T_1 V_5 = 0 ;
F_3 ( V_2 , V_3 , & V_5 ) ;
if ( V_5 )
F_4 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_6 V_7 )
{
int V_8 = 0 ;
switch ( V_7 ) {
case V_9 :
V_8 = F_1 ( V_2 ) ;
break;
case V_10 :
break;
default:
break;
}
return V_8 ;
}
static int F_6 ( struct V_11 * V_12 )
{
return F_7 ( F_8 ( V_12 ) ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
return F_10 ( F_8 ( V_12 ) ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
return F_12 ( F_8 ( V_12 ) ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
return F_14 ( F_8 ( V_12 ) ) ;
}
static int F_15 ( struct V_11 * V_12 )
{
return F_16 ( F_8 ( V_12 ) ) ;
}
static void F_17 ( struct V_13 * V_14 )
{
F_18 ( (struct V_1 * ) F_19 ( V_14 ) ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
F_21 ( & V_14 -> V_12 ) ;
F_22 ( & V_14 -> V_12 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static int
F_25 ( struct V_13 * V_14 , const struct V_15 * V_16 )
{
struct V_1 * V_2 ;
void T_2 * V_17 ;
int V_8 ;
V_8 = F_26 ( V_14 ) ;
if ( V_8 ) {
F_27 ( & V_14 -> V_12 , L_1 ) ;
return V_8 ;
}
F_28 ( V_14 ) ;
V_8 = F_29 ( V_14 , 1 << 0 , V_18 ) ;
if ( V_8 < 0 ) {
F_27 ( & V_14 -> V_12 , L_2 ) ;
return V_8 ;
}
V_17 = F_30 ( V_14 ) [ 0 ] ;
V_8 = F_31 ( & V_14 -> V_12 , & V_2 ) ;
if ( V_8 ) {
F_27 ( & V_14 -> V_12 , L_3 ) ;
return V_8 ;
}
V_2 -> V_19 = (struct V_20 * ) V_16 -> V_21 ;
V_8 = F_32 ( V_2 , V_17 , V_14 -> V_22 ) ;
if ( V_8 ) {
F_27 ( & V_14 -> V_12 , L_4 ) ;
F_24 ( V_2 ) ;
return V_8 ;
}
F_33 ( V_14 , V_2 ) ;
F_34 ( & V_14 -> V_12 ) ;
F_35 ( & V_14 -> V_12 ) ;
return 0 ;
}
