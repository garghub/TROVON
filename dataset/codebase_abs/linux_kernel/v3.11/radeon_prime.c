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
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_4 * V_5 ;
int V_11 ;
V_11 = F_10 ( V_20 , V_17 , V_22 , false ,
V_23 , V_18 , & V_5 ) ;
if ( V_11 )
return F_6 ( V_11 ) ;
V_5 -> V_24 . V_25 = V_5 ;
F_11 ( & V_20 -> V_26 . V_27 ) ;
F_12 ( & V_5 -> V_28 , & V_20 -> V_26 . V_29 ) ;
F_13 ( & V_20 -> V_26 . V_27 ) ;
return & V_5 -> V_24 ;
}
int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 = 0 ;
V_11 = F_15 ( V_5 , false ) ;
if ( F_16 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_17 ( V_5 , V_23 , NULL ) ;
F_18 ( V_5 ) ;
return V_11 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_11 = 0 ;
V_11 = F_15 ( V_5 , false ) ;
if ( F_16 ( V_11 != 0 ) )
return;
F_20 ( V_5 ) ;
F_18 ( V_5 ) ;
}
