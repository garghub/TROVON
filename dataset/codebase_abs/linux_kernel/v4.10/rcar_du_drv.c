static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( & V_4 -> V_8 [ V_7 ] , true ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( & V_4 -> V_8 [ V_7 ] , false ) ;
}
static int F_6 ( struct V_9 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
F_8 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
F_10 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_12 ( V_12 ) ;
struct V_1 * V_10 = V_4 -> V_10 ;
F_13 ( V_10 ) ;
if ( V_4 -> V_6 )
F_14 ( V_4 -> V_6 ) ;
F_15 ( V_10 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_1 * V_10 ;
struct V_13 * V_14 ;
int V_15 ;
V_4 = F_19 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_16 ) ;
if ( V_4 == NULL )
return - V_17 ;
F_20 ( & V_4 -> V_18 . V_19 ) ;
V_4 -> V_2 = & V_12 -> V_2 ;
V_4 -> V_20 = F_21 ( V_21 , V_4 -> V_2 ) -> V_22 ;
F_22 ( V_12 , V_4 ) ;
V_14 = F_23 ( V_12 , V_23 , 0 ) ;
V_4 -> V_24 = F_24 ( & V_12 -> V_2 , V_14 ) ;
if ( F_25 ( V_4 -> V_24 ) )
return F_26 ( V_4 -> V_24 ) ;
V_10 = F_27 ( & V_25 , & V_12 -> V_2 ) ;
if ( F_25 ( V_10 ) )
return F_26 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
V_10 -> V_5 = V_4 ;
V_15 = F_28 ( V_4 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_26 )
F_29 ( & V_12 -> V_2 ,
L_1 , V_15 ) ;
goto error;
}
V_10 -> V_27 = 1 ;
V_15 = F_30 ( V_10 , 0 ) ;
if ( V_15 )
goto error;
F_31 ( L_2 , F_32 ( & V_12 -> V_2 ) ) ;
return 0 ;
error:
F_11 ( V_12 ) ;
return V_15 ;
}
