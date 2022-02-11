static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_2 ( V_4 -> V_9 , L_1 , sizeof( V_4 -> V_9 ) ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_10 ) )
return - V_11 ;
if ( V_2 -> V_12 )
return F_5 ( V_2 -> V_12 ) ;
return - V_13 ;
}
int F_6 ( struct V_1 * V_2 , struct V_14 * V_15 , int V_16 )
{
if ( ! F_7 ( V_2 ) )
return - V_13 ;
if ( ! V_2 -> V_12 )
return - V_13 ;
return F_8 ( V_2 -> V_12 , V_15 , V_16 ) ;
}
void F_9 ( struct V_17 * V_18 ,
T_1 V_19 )
{
if ( V_19 . V_20 . V_21 ) {
F_10 ( L_2 ,
F_11 ( V_18 -> V_22 ) , V_19 . V_20 . V_23 ,
( V_19 . V_20 . V_24 ) ? L_3 : L_4 ,
V_18 -> V_25 , V_18 -> V_26 ) ;
} else {
F_10 ( L_5 ,
F_11 ( V_18 -> V_22 ) ) ;
}
}
void F_12 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_13 ( V_2 ) ;
T_1 V_27 ;
V_27 . V_28 = 0 ;
V_27 . V_20 . V_21 = V_2 -> V_12 -> V_29 ? 1 : 0 ;
V_27 . V_20 . V_24 = V_2 -> V_12 -> V_30 ? 1 : 0 ;
V_27 . V_20 . V_23 = V_2 -> V_12 -> V_23 ;
V_18 -> V_27 = V_27 . V_28 ;
if ( V_18 -> V_31 )
V_18 -> V_31 ( V_2 ) ;
if ( V_18 -> V_32 != V_2 -> V_12 -> V_29 ) {
V_18 -> V_32 = V_2 -> V_12 -> V_29 ;
F_14 ( V_18 -> V_25 , V_27 ) ;
F_9 ( V_18 , V_27 ) ;
}
}
int F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_13 ( V_2 ) ;
int V_33 = F_16 ( V_18 -> V_25 ) ;
T_1 V_27 ;
union V_34 V_35 ;
int V_36 = F_17 ( V_18 -> V_25 ) ;
V_35 . V_28 = F_18 ( F_19 ( V_36 , V_33 ) ) ;
V_35 . V_20 . V_37 = 0 ;
F_20 ( F_19 ( V_36 , V_33 ) , V_35 . V_28 ) ;
V_18 -> V_31 = NULL ;
if ( V_2 -> V_12 )
F_21 ( V_2 -> V_12 ) ;
if ( V_18 -> V_32 ) {
V_27 . V_28 = 0 ;
V_18 -> V_32 = 0 ;
F_14 ( V_18 -> V_25 , V_27 ) ;
F_9 ( V_18 , V_27 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_13 ( V_2 ) ;
struct V_38 * V_39 ;
struct V_40 * V_12 = NULL ;
if ( ! V_18 -> V_41 )
goto V_42;
V_39 = F_23 ( V_18 -> V_41 , L_6 , 0 ) ;
if ( ! V_39 && F_24 ( V_18 -> V_41 ) ) {
int V_43 ;
V_43 = F_25 ( V_18 -> V_41 ) ;
if ( V_43 )
return V_43 ;
V_39 = F_26 ( V_18 -> V_41 ) ;
}
if ( ! V_39 )
goto V_42;
V_12 = F_27 ( V_2 , V_39 , F_12 , 0 ,
V_44 ) ;
F_28 ( V_39 ) ;
if ( ! V_12 )
return - V_45 ;
V_18 -> V_32 = 0 ;
F_5 ( V_12 ) ;
return 0 ;
V_42:
F_29 ( V_2 ) ;
return 0 ;
}
