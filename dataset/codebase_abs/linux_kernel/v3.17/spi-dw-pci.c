static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
int V_10 ;
F_2 ( & V_2 -> V_11 , L_1 ,
V_2 -> V_12 , V_2 -> V_13 ) ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_6 = F_4 ( & V_2 -> V_11 , sizeof( struct V_5 ) ,
V_14 ) ;
if ( ! V_6 )
return - V_15 ;
V_6 -> V_2 = V_2 ;
V_8 = & V_6 -> V_8 ;
V_8 -> V_16 = F_5 ( V_2 , V_9 ) ;
V_10 = F_6 ( V_2 , 1 , F_7 ( & V_2 -> V_11 ) ) ;
if ( V_10 )
return V_10 ;
V_8 -> V_17 = F_8 ( V_2 ) [ V_9 ] ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = 4 ;
V_8 -> V_20 = V_2 -> V_20 ;
if ( V_2 -> V_13 == 0x0800 ) {
V_10 = F_9 ( V_8 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_10 ( & V_2 -> V_11 , V_8 ) ;
if ( V_10 )
return V_10 ;
F_11 ( V_2 , V_6 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
F_14 ( & V_6 -> V_8 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_21 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
int V_10 ;
V_10 = F_16 ( & V_6 -> V_8 ) ;
if ( V_10 )
return V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , F_20 ( V_2 , V_21 ) ) ;
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
int V_10 ;
F_19 ( V_2 , V_22 ) ;
F_22 ( V_2 ) ;
V_10 = F_23 ( V_2 ) ;
if ( V_10 )
return V_10 ;
return F_24 ( & V_6 -> V_8 ) ;
}
