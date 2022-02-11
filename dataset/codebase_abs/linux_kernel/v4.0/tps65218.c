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
default:
return - V_13 ;
}
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_4 , unsigned int V_6 )
{
int V_7 ;
unsigned int V_15 ;
V_7 = F_1 ( V_2 , V_3 , & V_15 ) ;
if ( V_7 ) {
F_6 ( V_2 -> V_16 , L_1 , V_3 ) ;
return V_7 ;
}
V_15 &= ~ V_14 ;
V_15 |= V_4 & V_14 ;
F_7 ( & V_2 -> V_17 ) ;
V_7 = F_3 ( V_2 , V_3 , V_15 , V_6 ) ;
if ( V_7 )
F_6 ( V_2 -> V_16 , L_2 , V_3 ) ;
F_8 ( & V_2 -> V_17 ) ;
return V_7 ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_4 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_14 , V_4 , V_6 ) ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_14 , 0 , V_6 ) ;
}
static int F_11 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
const struct V_22 * V_23 ;
int V_7 ;
V_23 = F_12 ( V_24 , & V_19 -> V_16 ) ;
if ( ! V_23 ) {
F_6 ( & V_19 -> V_16 ,
L_3 ) ;
return - V_13 ;
}
V_2 = F_13 ( & V_19 -> V_16 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
F_14 ( V_19 , V_2 ) ;
V_2 -> V_16 = & V_19 -> V_16 ;
V_2 -> V_27 = V_19 -> V_27 ;
V_2 -> V_5 = F_15 ( V_19 , & V_28 ) ;
if ( F_16 ( V_2 -> V_5 ) ) {
V_7 = F_17 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_16 , L_4 ,
V_7 ) ;
return V_7 ;
}
F_18 ( & V_2 -> V_17 ) ;
V_7 = F_19 ( V_2 -> V_5 , V_2 -> V_27 ,
V_29 , 0 , & V_30 ,
& V_2 -> V_31 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_19 -> V_16 . V_32 , NULL , NULL ,
& V_19 -> V_16 ) ;
if ( V_7 < 0 )
goto V_33;
return 0 ;
V_33:
F_21 ( V_2 -> V_27 , V_2 -> V_31 ) ;
return V_7 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_23 ( V_19 ) ;
F_21 ( V_2 -> V_27 , V_2 -> V_31 ) ;
return 0 ;
}
