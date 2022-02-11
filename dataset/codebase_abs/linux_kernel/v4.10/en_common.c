int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 , int V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_5 , V_6 , & V_4 -> V_8 ) ;
if ( V_7 )
return V_7 ;
F_3 ( & V_4 -> V_9 , & V_2 -> V_10 . V_11 . V_12 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( V_2 , V_4 -> V_8 ) ;
F_6 ( & V_4 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_13 ,
struct V_14 * V_15 )
{
int V_6 = F_8 ( V_16 ) ;
void * V_17 ;
T_1 * V_5 ;
int V_7 ;
V_5 = F_9 ( V_6 ) ;
if ( ! V_5 )
return - V_18 ;
V_17 = F_10 ( V_16 , V_5 , V_19 ) ;
F_11 ( V_17 , V_17 , V_20 , V_21 ) ;
F_11 ( V_17 , V_17 , V_22 , 1 ) ;
F_11 ( V_17 , V_17 , V_23 , 1 ) ;
F_11 ( V_17 , V_17 , V_24 , V_13 ) ;
F_11 ( V_17 , V_17 , V_25 , 1 ) ;
F_11 ( V_17 , V_17 , V_26 , 0xffffff ) ;
V_7 = F_12 ( V_2 , V_15 , V_5 , V_6 ) ;
F_13 ( V_5 ) ;
return V_7 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_10 ;
int V_7 ;
V_7 = F_15 ( V_2 , & V_28 -> V_29 , false ) ;
if ( V_7 ) {
F_16 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_2 , & V_28 -> V_13 ) ;
if ( V_7 ) {
F_16 ( V_2 , L_2 , V_7 ) ;
goto V_30;
}
V_7 = F_18 ( V_2 , & V_28 -> V_11 . V_31 ) ;
if ( V_7 ) {
F_16 ( V_2 , L_3 , V_7 ) ;
goto V_32;
}
V_7 = F_7 ( V_2 , V_28 -> V_13 , & V_28 -> V_15 ) ;
if ( V_7 ) {
F_16 ( V_2 , L_4 , V_7 ) ;
goto V_33;
}
F_19 ( & V_2 -> V_10 . V_11 . V_12 ) ;
return 0 ;
V_33:
F_20 ( V_2 , V_28 -> V_11 . V_31 ) ;
V_32:
F_21 ( V_2 , V_28 -> V_13 ) ;
V_30:
F_22 ( V_2 , & V_28 -> V_29 ) ;
return V_7 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_10 ;
F_24 ( V_2 , & V_28 -> V_15 ) ;
F_20 ( V_2 , V_28 -> V_11 . V_31 ) ;
F_21 ( V_2 , V_28 -> V_13 ) ;
F_22 ( V_2 , & V_28 -> V_29 ) ;
}
int F_25 ( struct V_1 * V_2 ,
bool V_34 )
{
struct V_3 * V_4 ;
void * V_5 ;
int V_6 ;
int V_7 = 0 ;
V_6 = F_8 ( V_35 ) ;
V_5 = F_9 ( V_6 ) ;
if ( ! V_5 )
return - V_18 ;
if ( V_34 )
F_11 ( V_35 , V_5 , V_36 . V_37 ,
V_38 ) ;
F_11 ( V_35 , V_5 , V_39 . V_40 , 1 ) ;
F_26 (tir, &mdev->mlx5e_res.td.tirs_list, list) {
V_7 = F_27 ( V_2 , V_4 -> V_8 , V_5 , V_6 ) ;
if ( V_7 )
goto V_41;
}
V_41:
F_13 ( V_5 ) ;
return V_7 ;
}
