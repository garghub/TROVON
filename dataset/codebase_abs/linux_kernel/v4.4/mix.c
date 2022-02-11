static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_4 ) ;
}
static void F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
F_2 ( V_2 , V_8 , 0 ) ;
F_2 ( V_2 , V_9 , 0 ) ;
F_2 ( V_2 , V_10 , 0 ) ;
F_2 ( V_2 , V_11 , 0 ) ;
F_2 ( V_2 , V_12 , 0 ) ;
F_2 ( V_2 , V_8 , 1 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_13 * V_14 )
{
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
F_2 ( V_2 , V_15 , F_8 ( V_2 , V_7 ) ) ;
F_9 ( V_14 , V_7 ) ;
F_2 ( V_2 , V_16 , 0 ) ;
F_2 ( V_2 , V_17 , 0 ) ;
F_4 ( V_7 , V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_13 * V_14 )
{
F_12 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_13 ( struct V_13 * V_14 , int V_18 )
{
if ( F_14 ( V_18 < 0 || V_18 >= F_15 ( V_14 ) ) )
V_18 = 0 ;
return F_16 ( (struct V_19 * ) ( V_14 -> V_20 ) + V_18 ) ;
}
static void F_17 ( struct V_21 * V_22 ,
const struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 = F_18 ( V_14 ) ;
struct V_31 * V_32 = & V_22 -> V_32 ;
int V_33 ;
if ( ! V_24 )
return;
V_26 = F_19 ( V_32 -> V_34 , L_1 ) ;
if ( ! V_26 )
return;
V_33 = F_20 ( V_26 ) ;
if ( ! V_33 )
goto V_35;
V_28 = F_21 ( V_32 ,
sizeof( struct V_27 ) * V_33 ,
V_36 ) ;
if ( ! V_28 ) {
F_22 ( V_32 , L_2 ) ;
goto V_35;
}
V_30 -> V_28 = V_28 ;
V_30 -> V_37 = V_33 ;
V_35:
F_23 ( V_26 ) ;
}
int F_24 ( struct V_21 * V_22 ,
const struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_29 * V_30 = F_18 ( V_14 ) ;
struct V_31 * V_32 = F_25 ( V_14 ) ;
struct V_19 * V_20 ;
struct V_38 * V_38 ;
char V_39 [ V_40 ] ;
int V_41 , V_33 , V_42 ;
if ( F_26 ( V_14 ) )
return 0 ;
F_17 ( V_22 , V_24 , V_14 ) ;
V_33 = V_30 -> V_37 ;
if ( ! V_33 )
return 0 ;
V_20 = F_21 ( V_32 , sizeof( * V_20 ) * V_33 , V_36 ) ;
if ( ! V_20 )
return - V_43 ;
V_14 -> V_44 = V_33 ;
V_14 -> V_20 = V_20 ;
F_27 (mix, priv, i) {
snprintf ( V_39 , V_40 , L_3 ,
V_45 , V_41 ) ;
V_38 = F_28 ( V_32 , V_39 ) ;
if ( F_29 ( V_38 ) )
return F_30 ( V_38 ) ;
V_20 -> V_30 = & V_30 -> V_28 [ V_41 ] ;
V_42 = F_31 ( V_14 , F_16 ( V_20 ) , & V_46 ,
V_38 , V_47 , V_41 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
void F_32 ( struct V_21 * V_22 ,
struct V_13 * V_14 )
{
struct V_19 * V_20 ;
int V_41 ;
F_27 (mix, priv, i) {
F_33 ( F_16 ( V_20 ) ) ;
}
}
