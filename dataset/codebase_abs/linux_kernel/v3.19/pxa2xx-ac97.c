static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( V_4 -> V_11 == V_12 )
V_10 = & V_13 ;
else
V_10 = & V_14 ;
F_7 ( V_8 , V_4 , V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( V_4 -> V_11 == V_12 )
V_10 = & V_15 ;
else
V_10 = & V_16 ;
F_7 ( V_8 , V_4 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( V_4 -> V_11 == V_12 )
return - V_17 ;
else
F_7 ( V_8 , V_4 ,
& V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
int V_21 ;
if ( V_20 -> V_22 != - 1 ) {
F_11 ( & V_20 -> V_23 , L_1 ) ;
return - V_24 ;
}
V_21 = F_12 ( V_20 ) ;
if ( V_21 ) {
F_11 ( & V_20 -> V_23 , L_2 , V_21 ) ;
return V_21 ;
}
V_21 = F_13 ( & V_25 ) ;
if ( V_21 != 0 )
return V_21 ;
return F_14 ( & V_20 -> V_23 , & V_26 ,
V_27 , F_15 ( V_27 ) ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
F_17 ( & V_20 -> V_23 ) ;
F_13 ( NULL ) ;
F_18 ( V_20 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_23 )
{
return F_20 () ;
}
static int F_21 ( struct V_28 * V_23 )
{
return F_22 () ;
}
