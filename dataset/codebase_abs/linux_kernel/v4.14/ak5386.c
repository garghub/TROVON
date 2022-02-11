static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( F_4 ( V_4 -> V_5 ) , V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( F_4 ( V_4 -> V_5 ) , V_4 -> V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( F_4 ( V_4 -> V_5 ) , V_4 -> V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( F_4 ( V_4 -> V_5 ) , V_4 -> V_5 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
V_8 &= V_9 ;
if ( V_8 != V_10 &&
V_8 != V_11 ) {
F_10 ( V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_6 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_12 ( V_4 -> V_19 ) )
F_13 ( V_4 -> V_19 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_6 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_12 ( V_4 -> V_19 ) )
F_13 ( V_4 -> V_19 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_12 = & V_21 -> V_12 ;
struct V_3 * V_4 ;
int V_23 , V_24 ;
V_4 = F_16 ( V_12 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_4 -> V_19 = - V_13 ;
F_17 ( V_12 , V_4 ) ;
for ( V_24 = 0 ; V_24 < F_4 ( V_27 ) ; V_24 ++ )
V_4 -> V_5 [ V_24 ] . V_28 = V_27 [ V_24 ] ;
V_23 = F_18 ( V_12 , F_4 ( V_4 -> V_5 ) ,
V_4 -> V_5 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( F_19 ( F_20 ( V_29 ) , V_12 ) )
V_4 -> V_19 = F_21 ( V_12 -> V_30 ,
L_2 , 0 ) ;
if ( F_12 ( V_4 -> V_19 ) )
if ( F_22 ( V_12 , V_4 -> V_19 ,
V_31 ,
L_3 ) )
V_4 -> V_19 = - V_13 ;
return F_23 ( V_12 , & V_32 ,
& V_33 , 1 ) ;
}
static int F_24 ( struct V_20 * V_21 )
{
F_25 ( & V_21 -> V_12 ) ;
return 0 ;
}
