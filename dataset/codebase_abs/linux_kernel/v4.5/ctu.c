static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return F_4 ( V_6 , F_5 ( V_2 ) / 4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_2 ( V_2 , V_9 , F_9 ( V_2 , V_6 ) ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_12 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_13 ( struct V_7 * V_8 , int V_10 )
{
if ( F_14 ( V_10 < 0 || V_10 >= F_15 ( V_8 ) ) )
V_10 = 0 ;
return F_16 ( F_17 ( V_8 , V_10 ) ) ;
}
int F_18 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
struct V_11 * V_13 ;
struct V_14 * V_15 = F_19 ( V_8 ) ;
struct V_16 * V_17 ;
struct V_18 * V_18 ;
char V_19 [ V_20 ] ;
int V_21 , V_22 , V_23 ;
if ( F_20 ( V_8 ) )
return 0 ;
V_12 = F_21 ( V_8 ) ;
if ( ! V_12 )
return 0 ;
V_22 = F_22 ( V_12 ) ;
if ( ! V_22 ) {
V_23 = - V_24 ;
goto V_25;
}
V_17 = F_23 ( V_15 , sizeof( * V_17 ) * V_22 , V_26 ) ;
if ( ! V_17 ) {
V_23 = - V_27 ;
goto V_25;
}
V_8 -> V_28 = V_22 ;
V_8 -> V_17 = V_17 ;
V_21 = 0 ;
V_23 = 0 ;
F_24 (node, np) {
V_17 = F_17 ( V_8 , V_21 ) ;
snprintf ( V_19 , V_20 , L_1 ,
V_29 , V_21 / 4 ) ;
V_18 = F_25 ( V_15 , V_19 ) ;
if ( F_26 ( V_18 ) ) {
V_23 = F_27 ( V_18 ) ;
goto V_25;
}
V_23 = F_28 ( V_8 , F_16 ( V_17 ) , & V_30 ,
V_18 , V_31 , V_21 ) ;
if ( V_23 )
goto V_25;
V_21 ++ ;
}
V_25:
F_29 ( V_12 ) ;
return V_23 ;
}
void F_30 ( struct V_7 * V_8 )
{
struct V_16 * V_17 ;
int V_21 ;
F_31 (ctu, priv, i) {
F_32 ( F_16 ( V_17 ) ) ;
}
}
