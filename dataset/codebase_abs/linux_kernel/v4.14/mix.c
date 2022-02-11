static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
F_2 ( V_2 , V_7 , 0 ) ;
F_2 ( V_2 , V_8 , 0 ) ;
F_2 ( V_2 , V_9 , 0 ) ;
F_2 ( V_2 , V_10 , 0 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_11 , F_6 ( V_6 ) ) ;
F_2 ( V_2 , V_12 , 0 ) ;
F_2 ( V_2 , V_13 , 0 ) ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
F_2 ( V_2 , V_14 , 0 ) ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 , V_14 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
return F_9 ( V_6 , F_10 ( V_2 ) ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
F_12 ( V_2 ) ;
F_1 ( V_2 ) ;
F_5 ( V_6 , V_2 ) ;
F_7 ( V_6 , V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
F_3 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_15 ( struct V_15 * V_16 , int V_17 )
{
if ( F_16 ( V_17 < 0 || V_17 >= F_17 ( V_16 ) ) )
V_17 = 0 ;
return F_18 ( F_19 ( V_16 , V_17 ) ) ;
}
int F_20 ( struct V_15 * V_16 )
{
struct V_18 * V_19 ;
struct V_18 * V_20 ;
struct V_21 * V_22 = F_21 ( V_16 ) ;
struct V_23 * V_24 ;
struct V_25 * V_25 ;
char V_26 [ V_27 ] ;
int V_28 , V_29 , V_30 ;
if ( F_22 ( V_16 ) )
return 0 ;
V_19 = F_23 ( V_16 ) ;
if ( ! V_19 )
return 0 ;
V_29 = F_24 ( V_19 ) ;
if ( ! V_29 ) {
V_30 = - V_31 ;
goto V_32;
}
V_24 = F_25 ( V_22 , sizeof( * V_24 ) * V_29 , V_33 ) ;
if ( ! V_24 ) {
V_30 = - V_34 ;
goto V_32;
}
V_16 -> V_35 = V_29 ;
V_16 -> V_24 = V_24 ;
V_28 = 0 ;
V_30 = 0 ;
F_26 (node, np) {
V_24 = F_19 ( V_16 , V_28 ) ;
snprintf ( V_26 , V_27 , L_1 ,
V_36 , V_28 ) ;
V_25 = F_27 ( V_22 , V_26 ) ;
if ( F_28 ( V_25 ) ) {
V_30 = F_29 ( V_25 ) ;
F_30 ( V_20 ) ;
goto V_32;
}
V_30 = F_31 ( V_16 , F_18 ( V_24 ) , & V_37 ,
V_25 , V_38 , V_39 , V_28 ) ;
if ( V_30 ) {
F_30 ( V_20 ) ;
goto V_32;
}
V_28 ++ ;
}
V_32:
F_30 ( V_19 ) ;
return V_30 ;
}
void F_32 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
int V_28 ;
F_33 (mix, priv, i) {
F_34 ( F_18 ( V_24 ) ) ;
}
}
