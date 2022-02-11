static struct V_1 *
F_1 ( struct V_2 * args , struct V_3 * V_4 )
{
F_2 ( & V_5 . V_6 ) ;
return & V_5 ;
}
static void
F_3 ( struct V_1 * V_7 )
{
}
static struct V_8 *
F_4 ( struct V_1 * V_7 , struct V_9 * V_10 , int V_11 )
{
if ( V_11 & V_12 )
return & V_13 ;
return F_5 ( & V_13 ) ;
}
static void
F_6 ( struct V_8 * V_14 )
{
}
static int
F_7 ( struct V_9 * V_10 , struct V_8 * V_14 , int V_15 )
{
return 1 ;
}
static T_1 *
F_8 ( struct V_16 * V_17 , T_1 * V_18 )
{
* V_18 ++ = F_9 ( V_19 ) ;
* V_18 ++ = 0 ;
* V_18 ++ = F_9 ( V_19 ) ;
* V_18 ++ = 0 ;
return V_18 ;
}
static int
F_10 ( struct V_16 * V_17 )
{
F_11 ( V_20 , & V_17 -> V_21 -> V_22 -> V_23 ) ;
return 0 ;
}
static T_1 *
F_12 ( struct V_16 * V_17 , T_1 * V_18 )
{
T_2 V_24 ;
T_3 V_25 ;
V_24 = F_13 ( * V_18 ++ ) ;
if ( V_24 != V_19 ) {
F_14 ( L_1 , V_24 ) ;
return F_15 ( - V_26 ) ;
}
V_25 = F_13 ( * V_18 ++ ) ;
if ( V_25 != 0 ) {
F_14 ( L_2 , V_25 ) ;
return F_15 ( - V_26 ) ;
}
return V_18 ;
}
