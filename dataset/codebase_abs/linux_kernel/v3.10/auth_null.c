static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
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
return F_5 ( & V_12 ) ;
}
static void
F_6 ( struct V_8 * V_13 )
{
}
static int
F_7 ( struct V_9 * V_10 , struct V_8 * V_13 , int V_14 )
{
return 1 ;
}
static T_2 *
F_8 ( struct V_15 * V_16 , T_2 * V_17 )
{
* V_17 ++ = F_9 ( V_18 ) ;
* V_17 ++ = 0 ;
* V_17 ++ = F_9 ( V_18 ) ;
* V_17 ++ = 0 ;
return V_17 ;
}
static int
F_10 ( struct V_15 * V_16 )
{
F_11 ( V_19 , & V_16 -> V_20 -> V_21 -> V_22 ) ;
return 0 ;
}
static T_2 *
F_12 ( struct V_15 * V_16 , T_2 * V_17 )
{
T_1 V_4 ;
T_3 V_23 ;
V_4 = F_13 ( * V_17 ++ ) ;
if ( V_4 != V_18 ) {
F_14 ( L_1 , V_4 ) ;
return NULL ;
}
V_23 = F_13 ( * V_17 ++ ) ;
if ( V_23 != 0 ) {
F_14 ( L_2 , V_23 ) ;
return NULL ;
}
return V_17 ;
}
