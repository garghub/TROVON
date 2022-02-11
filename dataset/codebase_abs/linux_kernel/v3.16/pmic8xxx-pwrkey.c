static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 1 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) )
F_8 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) )
F_10 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_14 = F_12 ( V_13 , 0 ) ;
int V_11 = F_12 ( V_13 , 1 ) ;
int V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
struct V_18 * V_18 ;
struct V_9 * V_10 ;
T_2 V_19 ;
bool V_20 ;
if ( F_13 ( V_13 -> V_8 . V_21 , L_1 , & V_19 ) )
V_19 = 15625 ;
if ( V_19 > 62500 || V_19 == 0 ) {
F_14 ( & V_13 -> V_8 , L_2 ) ;
return - V_22 ;
}
V_20 = F_15 ( V_13 -> V_8 . V_21 , L_3 ) ;
V_18 = F_16 ( V_13 -> V_8 . V_23 , NULL ) ;
if ( ! V_18 ) {
F_14 ( & V_13 -> V_8 , L_4 ) ;
return - V_24 ;
}
V_10 = F_17 ( & V_13 -> V_8 , sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 )
return - V_26 ;
V_10 -> V_11 = V_11 ;
V_4 = F_18 ( & V_13 -> V_8 ) ;
if ( ! V_4 ) {
F_19 ( & V_13 -> V_8 , L_5 ) ;
return - V_26 ;
}
F_20 ( V_4 , V_27 , V_5 ) ;
V_4 -> V_28 = L_6 ;
V_4 -> V_29 = L_7 ;
V_16 = ( V_19 << 10 ) / V_30 ;
V_16 = 1 + F_21 ( V_16 ) ;
V_15 = F_22 ( V_18 , V_31 , & V_17 ) ;
if ( V_15 < 0 ) {
F_14 ( & V_13 -> V_8 , L_8 , V_15 ) ;
return V_15 ;
}
V_17 &= ~ V_32 ;
V_17 |= ( V_16 & V_32 ) ;
if ( V_20 )
V_17 |= V_33 ;
else
V_17 &= ~ V_33 ;
V_15 = F_23 ( V_18 , V_31 , V_17 ) ;
if ( V_15 < 0 ) {
F_14 ( & V_13 -> V_8 , L_9 , V_15 ) ;
return V_15 ;
}
V_15 = F_24 ( & V_13 -> V_8 , V_11 , F_1 ,
V_34 ,
L_10 , V_4 ) ;
if ( V_15 ) {
F_14 ( & V_13 -> V_8 , L_11 ,
V_11 , V_15 ) ;
return V_15 ;
}
V_15 = F_24 ( & V_13 -> V_8 , V_14 , F_4 ,
V_34 ,
L_12 , V_4 ) ;
if ( V_15 ) {
F_14 ( & V_13 -> V_8 , L_11 ,
V_14 , V_15 ) ;
return V_15 ;
}
V_15 = F_25 ( V_4 ) ;
if ( V_15 ) {
F_14 ( & V_13 -> V_8 , L_13 , V_15 ) ;
return V_15 ;
}
F_26 ( V_13 , V_10 ) ;
F_27 ( & V_13 -> V_8 , 1 ) ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
F_27 ( & V_13 -> V_8 , 0 ) ;
return 0 ;
}
