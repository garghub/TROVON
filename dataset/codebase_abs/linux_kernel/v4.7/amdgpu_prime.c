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
struct V_2 *
F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = V_18 -> V_22 -> V_21 ;
struct V_23 * V_24 = V_16 -> V_25 ;
struct V_4 * V_5 ;
int V_11 ;
F_10 ( & V_21 -> V_26 , NULL ) ;
V_11 = F_11 ( V_24 , V_18 -> V_22 -> V_27 , V_28 , false ,
V_29 , 0 , V_19 , V_21 , & V_5 ) ;
F_12 ( & V_21 -> V_26 ) ;
if ( V_11 )
return F_6 ( V_11 ) ;
return & V_5 -> V_30 ;
}
int F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 = 0 ;
V_11 = F_14 ( V_5 , false ) ;
if ( F_15 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_16 ( V_5 , V_29 , NULL ) ;
F_17 ( V_5 ) ;
return V_11 ;
}
void F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 = 0 ;
V_11 = F_14 ( V_5 , false ) ;
if ( F_15 ( V_11 != 0 ) )
return;
F_19 ( V_5 ) ;
F_17 ( V_5 ) ;
}
struct V_20 * F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_7 . V_21 ;
}
struct V_31 * F_21 ( struct V_15 * V_16 ,
struct V_2 * V_32 ,
int V_33 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
if ( F_22 ( V_5 -> V_7 . V_9 ) )
return F_6 ( - V_34 ) ;
return F_23 ( V_16 , V_32 , V_33 ) ;
}
