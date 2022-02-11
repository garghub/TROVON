static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_2 ( V_2 , V_9 , F_6 ( V_2 , V_6 ) ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_9 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_10 ( struct V_7 * V_8 , int V_10 )
{
if ( F_11 ( V_10 < 0 || V_10 >= F_12 ( V_8 ) ) )
V_10 = 0 ;
return F_13 ( (struct V_11 * ) ( V_8 -> V_12 ) + V_10 ) ;
}
static void F_14 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_7 * V_8 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = F_15 ( V_8 ) ;
struct V_23 * V_24 = & V_14 -> V_24 ;
int V_25 ;
if ( ! V_16 )
return;
V_18 = F_16 ( V_24 -> V_26 , L_1 ) ;
if ( ! V_18 )
return;
V_25 = F_17 ( V_18 ) ;
if ( ! V_25 )
goto V_27;
V_20 = F_18 ( V_24 ,
sizeof( struct V_19 ) * V_25 ,
V_28 ) ;
if ( ! V_20 ) {
F_19 ( V_24 , L_2 ) ;
goto V_27;
}
V_22 -> V_20 = V_20 ;
V_22 -> V_29 = V_25 ;
V_27:
F_20 ( V_18 ) ;
}
int F_21 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_7 * V_8 )
{
struct V_21 * V_22 = F_15 ( V_8 ) ;
struct V_23 * V_24 = F_22 ( V_8 ) ;
struct V_11 * V_12 ;
struct V_30 * V_30 ;
char V_31 [ V_32 ] ;
int V_33 , V_25 , V_34 ;
if ( F_23 ( V_8 ) )
return 0 ;
F_14 ( V_14 , V_16 , V_8 ) ;
V_25 = V_22 -> V_29 ;
if ( ! V_25 )
return 0 ;
V_12 = F_18 ( V_24 , sizeof( * V_12 ) * V_25 , V_28 ) ;
if ( ! V_12 )
return - V_35 ;
V_8 -> V_36 = V_25 ;
V_8 -> V_12 = V_12 ;
F_24 (ctu, priv, i) {
snprintf ( V_31 , V_32 , L_3 ,
V_37 , V_33 / 4 ) ;
V_30 = F_25 ( V_24 , V_31 ) ;
if ( F_26 ( V_30 ) )
return F_27 ( V_30 ) ;
V_12 -> V_22 = & V_22 -> V_20 [ V_33 ] ;
V_34 = F_28 ( V_8 , F_13 ( V_12 ) , & V_38 ,
V_30 , V_39 , V_33 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
void F_29 ( struct V_13 * V_14 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 ;
int V_33 ;
F_24 (ctu, priv, i) {
F_30 ( F_13 ( V_12 ) ) ;
}
}
