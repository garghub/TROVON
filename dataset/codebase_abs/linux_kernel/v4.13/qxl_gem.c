void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = (struct V_5 * ) V_2 -> V_9 -> V_10 ;
F_3 ( V_6 , V_4 , false ) ;
V_8 = & V_4 -> V_8 ;
F_4 ( & V_8 ) ;
}
int F_5 ( struct V_5 * V_6 , int V_11 ,
int V_12 , int V_13 ,
bool V_14 , bool V_15 ,
struct V_16 * V_17 ,
struct V_1 * * V_18 )
{
struct V_3 * V_19 ;
int V_20 ;
* V_18 = NULL ;
if ( V_12 < V_21 )
V_12 = V_21 ;
V_20 = F_6 ( V_6 , V_11 , V_15 , false , V_13 , V_17 , & V_19 ) ;
if ( V_20 ) {
if ( V_20 != - V_22 )
F_7 (
L_1 ,
V_11 , V_13 , V_12 , V_20 ) ;
return V_20 ;
}
* V_18 = & V_19 -> V_23 ;
F_8 ( & V_6 -> V_24 . V_25 ) ;
F_9 ( & V_19 -> V_26 , & V_6 -> V_24 . V_27 ) ;
F_10 ( & V_6 -> V_24 . V_25 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_11 ,
struct V_16 * V_17 ,
struct V_3 * * V_4 ,
T_3 * V_31 )
{
struct V_1 * V_2 ;
int V_20 ;
F_12 ( ! V_4 ) ;
F_12 ( ! V_31 ) ;
V_20 = F_5 ( V_6 , V_11 , 0 ,
V_30 ,
false , false , V_17 ,
& V_2 ) ;
if ( V_20 )
return - V_32 ;
V_20 = F_13 ( V_29 , V_2 , V_31 ) ;
if ( V_20 )
return V_20 ;
* V_4 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_18 , struct V_28 * V_29 )
{
return 0 ;
}
void F_16 ( struct V_1 * V_18 ,
struct V_28 * V_29 )
{
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_24 . V_27 ) ;
}
void F_19 ( struct V_5 * V_6 )
{
F_20 ( V_6 ) ;
}
