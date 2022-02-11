static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_2 ( V_4 -> V_9 , L_1 , sizeof( V_4 -> V_9 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
if ( V_13 -> V_14 )
return F_5 ( V_13 -> V_14 , V_11 ) ;
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
if ( ! F_7 ( V_16 ) )
return - V_17 ;
if ( V_13 -> V_14 )
return F_8 ( V_13 -> V_14 , V_11 ) ;
return - V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
if ( ! F_7 ( V_16 ) )
return - V_17 ;
if ( V_13 -> V_14 )
return F_10 ( V_13 -> V_14 ) ;
return - V_15 ;
}
int F_11 ( struct V_1 * V_2 , struct V_18 * V_19 , int V_11 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
if ( ! F_12 ( V_2 ) )
return - V_15 ;
if ( ! V_13 -> V_14 )
return - V_15 ;
return F_13 ( V_13 -> V_14 , V_19 , V_11 ) ;
}
void F_14 ( struct V_12 * V_13 ,
T_1 V_20 )
{
if ( V_20 . V_21 . V_22 ) {
F_15 ( L_2 ,
F_16 ( V_13 -> V_23 ) , V_20 . V_21 . V_24 ,
( V_20 . V_21 . V_25 ) ? L_3 : L_4 ,
V_13 -> V_26 , V_13 -> V_27 ) ;
} else {
F_15 ( L_5 ,
F_16 ( V_13 -> V_23 ) ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
T_1 V_28 ;
V_28 . V_29 = 0 ;
V_28 . V_21 . V_22 = V_13 -> V_14 -> V_30 ? 1 : 0 ;
V_28 . V_21 . V_25 = V_13 -> V_14 -> V_31 ? 1 : 0 ;
V_28 . V_21 . V_24 = V_13 -> V_14 -> V_24 ;
V_13 -> V_28 = V_28 . V_29 ;
if ( V_13 -> V_32 )
V_13 -> V_32 ( V_2 ) ;
if ( V_13 -> V_33 != V_13 -> V_14 -> V_30 ) {
V_13 -> V_33 = V_13 -> V_14 -> V_30 ;
F_18 ( V_13 -> V_26 , V_28 ) ;
F_14 ( V_13 , V_28 ) ;
}
}
int F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_34 = F_20 ( V_13 -> V_26 ) ;
T_1 V_28 ;
union V_35 V_36 ;
int V_37 = F_21 ( V_13 -> V_26 ) ;
V_36 . V_29 = F_22 ( F_23 ( V_37 , V_34 ) ) ;
V_36 . V_21 . V_38 = 0 ;
F_24 ( F_23 ( V_37 , V_34 ) , V_36 . V_29 ) ;
V_13 -> V_32 = NULL ;
if ( V_13 -> V_14 )
F_25 ( V_13 -> V_14 ) ;
V_13 -> V_14 = NULL ;
if ( V_13 -> V_33 ) {
V_28 . V_29 = 0 ;
V_13 -> V_33 = 0 ;
F_18 ( V_13 -> V_26 , V_28 ) ;
F_14 ( V_13 , V_28 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_39 * V_40 ;
if ( ! V_13 -> V_41 )
goto V_42;
V_40 = F_27 ( V_13 -> V_41 , L_6 , 0 ) ;
if ( ! V_40 && F_28 ( V_13 -> V_41 ) ) {
int V_43 ;
V_43 = F_29 ( V_13 -> V_41 ) ;
if ( V_43 )
return V_43 ;
V_40 = F_30 ( V_13 -> V_41 ) ;
}
if ( ! V_40 )
goto V_42;
V_13 -> V_14 = F_31 ( V_2 , V_40 , F_17 , 0 ,
V_44 ) ;
if ( ! V_13 -> V_14 )
return - V_45 ;
V_13 -> V_33 = 0 ;
F_10 ( V_13 -> V_14 ) ;
return 0 ;
V_42:
F_32 ( V_2 ) ;
return 0 ;
}
