int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_2 ( struct V_1 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_5 )
F_4 ( & V_5 ) ;
}
int F_5 ( struct V_6 * V_7 , int V_8 ,
int V_9 , int V_10 ,
bool V_11 , bool V_12 ,
struct V_13 * V_14 ,
struct V_1 * * V_2 )
{
struct V_4 * V_15 ;
int V_16 ;
* V_2 = NULL ;
if ( V_9 < V_17 )
V_9 = V_17 ;
V_16 = F_6 ( V_7 , V_8 , V_12 , false , V_10 , V_14 , & V_15 ) ;
if ( V_16 ) {
if ( V_16 != - V_18 )
F_7 (
L_1 ,
V_8 , V_10 , V_9 , V_16 ) ;
return V_16 ;
}
* V_2 = & V_15 -> V_19 ;
F_8 ( & V_7 -> V_20 . V_21 ) ;
F_9 ( & V_15 -> V_22 , & V_7 -> V_20 . V_23 ) ;
F_10 ( & V_7 -> V_20 . V_21 ) ;
return 0 ;
}
int F_11 ( struct V_6 * V_7 ,
struct V_24 * V_25 ,
T_1 V_26 ,
T_2 V_8 ,
struct V_13 * V_14 ,
struct V_4 * * V_5 ,
T_3 * V_27 )
{
struct V_1 * V_3 ;
int V_16 ;
F_12 ( ! V_5 ) ;
F_12 ( ! V_27 ) ;
V_16 = F_5 ( V_7 , V_8 , 0 ,
V_26 ,
false , false , V_14 ,
& V_3 ) ;
if ( V_16 )
return - V_28 ;
V_16 = F_13 ( V_25 , V_3 , V_27 ) ;
if ( V_16 )
return V_16 ;
* V_5 = F_3 ( V_3 ) ;
F_14 ( V_3 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
return 0 ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
}
int F_17 ( struct V_6 * V_7 )
{
F_18 ( & V_7 -> V_20 . V_23 ) ;
return 0 ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 ( V_7 ) ;
}
