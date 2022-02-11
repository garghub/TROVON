static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_7 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
F_5 ( V_4 -> V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
F_7 ( V_4 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_9 ( V_10 ) ;
struct V_1 * V_8 = V_4 -> V_8 ;
F_10 ( V_8 ) ;
if ( V_4 -> V_6 )
F_11 ( V_4 -> V_6 ) ;
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_8 ;
struct V_11 * V_12 ;
int V_13 ;
V_4 = F_16 ( & V_10 -> V_2 , sizeof( * V_4 ) , V_14 ) ;
if ( V_4 == NULL )
return - V_15 ;
V_4 -> V_2 = & V_10 -> V_2 ;
V_4 -> V_16 = F_17 ( V_4 -> V_2 ) ;
F_18 ( V_10 , V_4 ) ;
V_12 = F_19 ( V_10 , V_17 , 0 ) ;
V_4 -> V_18 = F_20 ( & V_10 -> V_2 , V_12 ) ;
if ( F_21 ( V_4 -> V_18 ) )
return F_22 ( V_4 -> V_18 ) ;
V_8 = F_23 ( & V_19 , & V_10 -> V_2 ) ;
if ( F_21 ( V_8 ) )
return F_22 ( V_8 ) ;
V_4 -> V_8 = V_8 ;
V_8 -> V_5 = V_4 ;
V_13 = F_24 ( V_4 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_20 )
F_25 ( & V_10 -> V_2 ,
L_1 , V_13 ) ;
goto error;
}
V_8 -> V_21 = 1 ;
V_13 = F_26 ( V_8 , 0 ) ;
if ( V_13 )
goto error;
F_27 ( L_2 , F_28 ( & V_10 -> V_2 ) ) ;
return 0 ;
error:
F_8 ( V_10 ) ;
return V_13 ;
}
