int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_6 )
{
int V_7 ;
unsigned int V_8 ;
switch ( V_6 ) {
case V_9 :
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
case V_10 :
V_8 = V_3 ^ V_11 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
case V_13 :
V_8 = V_3 ^ V_11 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
default:
return - V_14 ;
}
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_4 , unsigned int V_6 )
{
int V_7 ;
unsigned int V_16 ;
V_7 = F_1 ( V_2 , V_3 , & V_16 ) ;
if ( V_7 ) {
F_6 ( V_2 -> V_17 , L_1 , V_3 ) ;
return V_7 ;
}
V_16 &= ~ V_15 ;
V_16 |= V_4 & V_15 ;
V_7 = F_3 ( V_2 , V_3 , V_16 , V_6 ) ;
if ( V_7 )
F_6 ( V_2 -> V_17 , L_2 , V_3 ) ;
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_4 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_15 , V_4 , V_6 ) ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_15 , 0 , V_6 ) ;
}
static int T_1 F_9 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
unsigned int V_22 ;
unsigned int V_23 = V_21 -> V_24 ;
const struct V_25 * V_26 ;
int V_7 ;
if ( V_19 -> V_17 . V_27 ) {
V_26 = F_10 ( V_28 , & V_19 -> V_17 ) ;
if ( ! V_26 ) {
F_6 ( & V_19 -> V_17 ,
L_3 ) ;
return - V_14 ;
}
V_23 = ( unsigned int ) V_26 -> V_16 ;
}
if ( ! V_23 ) {
F_6 ( & V_19 -> V_17 , L_4 ) ;
return - V_29 ;
}
V_2 = F_11 ( & V_19 -> V_17 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
F_12 ( V_19 , V_2 ) ;
V_2 -> V_17 = & V_19 -> V_17 ;
V_2 -> V_32 = V_23 ;
V_2 -> V_5 = F_13 ( V_19 , & V_33 ) ;
if ( F_14 ( V_2 -> V_5 ) ) {
V_7 = F_15 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_17 , L_5 ,
V_7 ) ;
return V_7 ;
}
V_7 = F_16 ( V_2 -> V_17 , - 1 , V_34 ,
F_17 ( V_34 ) , NULL , 0 , NULL ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_17 , L_6 , V_7 ) ;
return V_7 ;
}
V_7 = F_1 ( V_2 , V_35 , & V_22 ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_17 , L_7 ,
V_7 ) ;
return V_7 ;
}
F_18 ( V_2 -> V_17 , L_8 ,
( V_22 & V_36 ) >> 4 ,
V_22 & V_37 ) ;
return 0 ;
}
static int T_2 F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
F_21 ( V_2 -> V_17 ) ;
return 0 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_38 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_38 ) ;
}
