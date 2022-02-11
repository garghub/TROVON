void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 )
F_3 ( & V_4 ) ;
}
int F_4 ( struct V_5 * V_6 , int V_7 ,
int V_8 , int V_9 ,
bool V_10 , bool V_11 ,
struct V_12 * V_13 ,
struct V_1 * * V_14 )
{
struct V_3 * V_15 ;
int V_16 ;
* V_14 = NULL ;
if ( V_8 < V_17 )
V_8 = V_17 ;
V_16 = F_5 ( V_6 , V_7 , V_11 , false , V_9 , V_13 , & V_15 ) ;
if ( V_16 ) {
if ( V_16 != - V_18 )
F_6 (
L_1 ,
V_7 , V_9 , V_8 , V_16 ) ;
return V_16 ;
}
* V_14 = & V_15 -> V_19 ;
F_7 ( & V_6 -> V_20 . V_21 ) ;
F_8 ( & V_15 -> V_22 , & V_6 -> V_20 . V_23 ) ;
F_9 ( & V_6 -> V_20 . V_21 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_6 ,
struct V_24 * V_25 ,
T_1 V_26 ,
T_2 V_7 ,
struct V_12 * V_13 ,
struct V_3 * * V_4 ,
T_3 * V_27 )
{
struct V_1 * V_2 ;
int V_16 ;
F_11 ( ! V_4 ) ;
F_11 ( ! V_27 ) ;
V_16 = F_4 ( V_6 , V_7 , 0 ,
V_26 ,
false , false , V_13 ,
& V_2 ) ;
if ( V_16 )
return - V_28 ;
V_16 = F_12 ( V_25 , V_2 , V_27 ) ;
if ( V_16 )
return V_16 ;
* V_4 = F_2 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_14 , struct V_24 * V_25 )
{
return 0 ;
}
void F_15 ( struct V_1 * V_14 ,
struct V_24 * V_25 )
{
}
int F_16 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_20 . V_23 ) ;
return 0 ;
}
void F_18 ( struct V_5 * V_6 )
{
F_19 ( V_6 ) ;
}
