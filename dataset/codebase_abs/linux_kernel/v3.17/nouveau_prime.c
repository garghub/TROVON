struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_6 = V_5 -> V_7 . V_8 ;
return F_3 ( V_5 -> V_7 . V_9 -> V_10 , V_6 ) ;
}
void * F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 ;
V_11 = F_5 ( & V_5 -> V_7 , 0 , V_5 -> V_7 . V_8 ,
& V_5 -> V_12 ) ;
if ( V_11 )
return F_6 ( V_11 ) ;
return V_5 -> V_12 . V_13 ;
}
void F_7 ( struct V_2 * V_3 , void * V_14 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_8 ( & V_5 -> V_12 ) ;
}
struct V_2 * F_9 ( struct V_15 * V_16 ,
T_1 V_17 ,
struct V_1 * V_18 )
{
struct V_4 * V_5 ;
T_2 V_19 = 0 ;
int V_11 ;
V_19 = V_20 ;
V_11 = F_10 ( V_16 , V_17 , 0 , V_19 , 0 , 0 ,
V_18 , & V_5 ) ;
if ( V_11 )
return F_6 ( V_11 ) ;
V_5 -> V_21 = V_22 ;
V_11 = F_11 ( V_16 , & V_5 -> V_23 , V_5 -> V_7 . V_24 . V_17 ) ;
if ( V_11 ) {
F_12 ( NULL , & V_5 ) ;
return F_6 ( - V_25 ) ;
}
return & V_5 -> V_23 ;
}
int F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 ;
V_11 = F_14 ( V_5 , V_20 ) ;
if ( V_11 )
return - V_26 ;
return 0 ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_16 ( V_5 ) ;
}
struct V_27 * F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_7 . V_28 ;
}
