static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
F_2 ( V_6 ) ;
if ( ! V_2 -> V_9 -> V_10 )
return - V_11 ;
if ( V_4 -> V_7 -> V_12 != V_13 &&
V_4 -> V_7 -> V_12 != V_14 )
return - V_11 ;
if ( ! V_6 -> V_15 )
return - V_16 ;
V_8 = F_3 ( V_2 , V_4 ) ;
if ( ! V_8 ) {
V_6 -> V_15 = 0 ;
V_6 -> V_17 = NULL ;
V_6 -> V_18 = 0 ;
}
return V_8 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
F_5 ( V_6 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
F_6 ( V_6 ) ;
return V_8 ;
}
void F_7 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_21 * V_21 = V_6 -> V_21 ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
F_9 ( V_4 , V_20 ) ;
F_5 ( V_6 ) ;
if ( F_10 ( V_6 -> V_12 != V_13 &&
V_6 -> V_12 != V_14 ) )
goto V_22;
V_6 -> V_17 = V_20 -> V_23 ;
F_11 ( V_2 , V_4 , V_20 , V_24 ) ;
V_22:
F_6 ( V_6 ) ;
return;
}
bool F_12 ( struct V_3 * V_4 ,
const T_1 * V_25 , T_2 V_26 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
bool V_27 ;
F_13 ( V_4 , V_25 ) ;
if ( F_10 ( V_6 -> V_12 != V_13 &&
V_6 -> V_12 != V_14 ) ) {
F_14 ( false ) ;
return false ;
}
V_27 = F_15 ( V_4 , V_25 , V_26 ) ;
F_14 ( V_27 ) ;
return V_27 ;
}
bool F_16 ( struct V_3 * V_4 ,
const T_1 * V_25 , T_2 V_26 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
bool V_27 ;
F_17 ( V_4 , V_25 ) ;
if ( F_10 ( V_6 -> V_12 != V_13 &&
V_6 -> V_12 != V_14 &&
V_6 -> V_12 != V_28 ) ) {
F_14 ( false ) ;
return false ;
}
V_27 = F_18 ( V_4 , V_25 , V_26 ) ;
F_14 ( V_27 ) ;
return V_27 ;
}
