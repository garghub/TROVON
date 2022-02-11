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
static int F_9 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
unsigned int V_22 ;
unsigned long V_23 = V_21 -> V_24 ;
const struct V_25 * V_26 ;
bool V_27 = false ;
int V_7 ;
if ( V_19 -> V_17 . V_28 ) {
V_26 = F_10 ( V_29 , & V_19 -> V_17 ) ;
if ( ! V_26 ) {
F_6 ( & V_19 -> V_17 ,
L_3 ) ;
return - V_14 ;
}
V_23 = ( unsigned long ) V_26 -> V_16 ;
V_27 = F_11 ( V_19 -> V_17 . V_28 ,
L_4 ) ;
}
if ( ! V_23 ) {
F_6 ( & V_19 -> V_17 , L_5 ) ;
return - V_30 ;
}
V_2 = F_12 ( & V_19 -> V_17 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_13 ( V_19 , V_2 ) ;
V_2 -> V_17 = & V_19 -> V_17 ;
V_2 -> V_33 = V_23 ;
V_2 -> V_5 = F_14 ( V_19 , & V_34 ) ;
if ( F_15 ( V_2 -> V_5 ) ) {
V_7 = F_16 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_17 , L_6 ,
V_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_2 -> V_17 , - 1 , V_35 ,
F_18 ( V_35 ) , NULL , 0 , NULL ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_17 , L_7 , V_7 ) ;
return V_7 ;
}
V_7 = F_1 ( V_2 , V_36 , & V_22 ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_17 , L_8 ,
V_7 ) ;
return V_7 ;
}
if ( V_27 ) {
V_7 = F_7 ( V_2 , V_37 ,
V_38 , V_38 ,
V_9 ) ;
if ( V_7 )
F_19 ( V_2 -> V_17 , L_9 ) ;
}
F_20 ( V_2 -> V_17 , L_10 ,
( V_22 & V_39 ) >> 4 ,
V_22 & V_40 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_41 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_41 ) ;
}
