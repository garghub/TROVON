static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_9 ;
struct V_12 * V_13 ;
int V_14 ;
V_13 = F_2 ( V_11 -> V_15 , V_2 ) ;
if ( ! V_13 )
return 0 ;
if ( V_8 -> V_4 == NULL ) {
V_8 -> V_4 = V_13 ;
V_14 = F_3 ( L_1 , V_16 ,
V_17 , V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 -> V_18 = V_14 ;
} else if ( V_8 -> V_4 != V_13 ) {
F_4 ( V_8 -> V_18 ) ;
V_8 -> V_4 = V_13 ;
V_14 = F_3 ( L_1 , V_16 ,
V_17 , V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 -> V_18 = V_14 ;
}
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
F_7 ( V_2 ) ;
if ( V_8 -> V_18 >= 0 ) {
F_4 ( V_8 -> V_18 ) ;
V_8 -> V_18 = - 1 ;
V_8 -> V_4 = NULL ;
}
return 0 ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_20 -> V_19 ;
struct V_21 * V_22 = V_11 -> V_22 ;
int V_14 = 0 ;
if ( ! V_20 -> V_23 -> V_24 )
V_20 -> V_23 -> V_24 = & V_25 ;
if ( ! V_20 -> V_23 -> V_26 )
V_20 -> V_23 -> V_26 = F_9 ( 32 ) ;
if ( V_22 -> V_27 [ V_28 ] . V_2 ) {
V_14 = F_10 ( V_22 ,
V_28 ) ;
if ( V_14 )
goto V_29;
}
if ( V_22 -> V_27 [ V_30 ] . V_2 ) {
V_14 = F_10 ( V_22 ,
V_30 ) ;
if ( V_14 )
goto V_29;
}
V_29:
return V_14 ;
}
static int F_11 ( struct V_31 * V_32 )
{
return F_12 ( & V_32 -> V_23 , & V_33 ) ;
}
static int F_13 ( struct V_31 * V_32 )
{
F_14 ( & V_32 -> V_23 ) ;
return 0 ;
}
