int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
int V_6 ;
unsigned int V_7 ;
switch ( V_5 ) {
case V_8 :
return F_2 ( V_2 -> V_9 , V_3 , V_4 ) ;
case V_10 :
V_7 = V_3 ^ V_11 ;
V_6 = F_2 ( V_2 -> V_9 , V_12 ,
V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_2 ( V_2 -> V_9 , V_3 , V_4 ) ;
default:
return - V_13 ;
}
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_4 , unsigned int V_5 )
{
int V_6 ;
unsigned int V_15 ;
V_6 = F_4 ( V_2 -> V_9 , V_3 , & V_15 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_16 , L_1 , V_3 ) ;
return V_6 ;
}
V_15 &= ~ V_14 ;
V_15 |= V_4 & V_14 ;
F_6 ( & V_2 -> V_17 ) ;
V_6 = F_1 ( V_2 , V_3 , V_15 , V_5 ) ;
if ( V_6 )
F_5 ( V_2 -> V_16 , L_2 , V_3 ) ;
F_7 ( & V_2 -> V_17 ) ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_4 , unsigned int V_5 )
{
return F_3 ( V_2 , V_3 , V_14 , V_4 , V_5 ) ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 , unsigned int V_5 )
{
return F_3 ( V_2 , V_3 , V_14 , 0 , V_5 ) ;
}
static int F_10 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
const struct V_22 * V_23 ;
int V_6 ;
unsigned int V_24 ;
V_23 = F_11 ( V_25 , & V_19 -> V_16 ) ;
if ( ! V_23 ) {
F_5 ( & V_19 -> V_16 ,
L_3 ) ;
return - V_13 ;
}
V_2 = F_12 ( & V_19 -> V_16 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
F_13 ( V_19 , V_2 ) ;
V_2 -> V_16 = & V_19 -> V_16 ;
V_2 -> V_28 = V_19 -> V_28 ;
V_2 -> V_9 = F_14 ( V_19 , & V_29 ) ;
if ( F_15 ( V_2 -> V_9 ) ) {
V_6 = F_16 ( V_2 -> V_9 ) ;
F_5 ( V_2 -> V_16 , L_4 ,
V_6 ) ;
return V_6 ;
}
F_17 ( & V_2 -> V_17 ) ;
V_6 = F_18 ( V_2 -> V_9 , V_2 -> V_28 ,
V_30 , 0 , & V_31 ,
& V_2 -> V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 -> V_9 , V_33 , & V_24 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_16 , L_5 , V_6 ) ;
return V_6 ;
}
V_2 -> V_34 = V_24 & V_35 ;
V_6 = F_19 ( V_2 -> V_16 , V_36 , V_37 ,
F_20 ( V_37 ) , NULL , 0 ,
F_21 ( V_2 -> V_32 ) ) ;
if ( V_6 < 0 )
goto V_38;
return 0 ;
V_38:
F_22 ( V_2 -> V_28 , V_2 -> V_32 ) ;
return V_6 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_24 ( V_19 ) ;
F_22 ( V_2 -> V_28 , V_2 -> V_32 ) ;
return 0 ;
}
