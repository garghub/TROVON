static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , L_1 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_6 , V_7 , sizeof( V_4 -> V_6 ) ) ;
F_2 ( V_4 -> V_8 , L_2 , sizeof( V_4 -> V_8 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
if ( V_12 -> V_13 )
return F_5 ( V_12 -> V_13 , V_10 ) ;
return - V_14 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
if ( ! F_7 ( V_15 ) )
return - V_16 ;
if ( V_12 -> V_13 )
return F_8 ( V_12 -> V_13 , V_10 ) ;
return - V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
if ( ! F_7 ( V_15 ) )
return - V_16 ;
if ( V_12 -> V_13 )
return F_10 ( V_12 -> V_13 ) ;
return - V_14 ;
}
int F_11 ( struct V_1 * V_2 , struct V_17 * V_18 , int V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
if ( ! F_12 ( V_2 ) )
return - V_14 ;
if ( ! V_12 -> V_13 )
return - V_14 ;
return F_13 ( V_12 -> V_13 , V_18 , V_10 ) ;
}
static void F_14 ( struct V_11 * V_12 ,
T_1 V_19 )
{
if ( V_19 . V_20 . V_21 ) {
F_15 ( L_3 ,
F_16 ( V_12 -> V_22 ) , V_19 . V_20 . V_23 ,
( V_19 . V_20 . V_24 ) ? L_4 : L_5 ,
V_12 -> V_25 ) ;
} else {
F_15 ( L_6 ,
F_16 ( V_12 -> V_22 ) ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
T_1 V_26 ;
if ( V_12 -> V_27 != V_12 -> V_13 -> V_28 ) {
V_12 -> V_27 = V_12 -> V_13 -> V_28 ;
V_26 . V_29 = 0 ;
V_26 . V_20 . V_21 = V_12 -> V_27 ? 1 : 0 ;
V_26 . V_20 . V_24 = V_12 -> V_13 -> V_30 ? 1 : 0 ;
V_26 . V_20 . V_23 = V_12 -> V_13 -> V_23 ;
F_18 ( V_12 -> V_25 , V_26 ) ;
F_14 ( V_12 , V_26 ) ;
}
}
int F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
T_1 V_26 ;
V_12 -> V_31 = NULL ;
if ( V_12 -> V_13 )
F_20 ( V_12 -> V_13 ) ;
V_12 -> V_13 = NULL ;
if ( V_12 -> V_27 ) {
V_26 . V_29 = 0 ;
V_12 -> V_27 = 0 ;
F_18 ( V_12 -> V_25 , V_26 ) ;
F_14 ( V_12 , V_26 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_32 * V_33 ;
if ( ! V_12 -> V_34 )
goto V_35;
V_33 = F_22 ( V_12 -> V_34 , L_7 , 0 ) ;
if ( ! V_33 )
goto V_35;
V_12 -> V_13 = F_23 ( V_2 , V_33 , F_17 , 0 ,
V_36 ) ;
if ( V_12 -> V_13 == NULL )
return - V_37 ;
V_12 -> V_27 = 0 ;
F_10 ( V_12 -> V_13 ) ;
return 0 ;
V_35:
F_24 ( V_2 ) ;
return 0 ;
}
