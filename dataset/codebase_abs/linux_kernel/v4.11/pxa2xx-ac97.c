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
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_4 -> V_9 == V_10 )
V_8 = & V_11 ;
else
V_8 = & V_12 ;
F_7 ( V_6 , V_4 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_4 -> V_9 == V_10 )
V_8 = & V_13 ;
else
V_8 = & V_14 ;
F_7 ( V_6 , V_4 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 -> V_9 == V_10 )
return - V_15 ;
else
F_7 ( V_6 , V_4 ,
& V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 )
{
int V_19 ;
if ( V_18 -> V_20 != - 1 ) {
F_11 ( & V_18 -> V_21 , L_1 ) ;
return - V_22 ;
}
V_19 = F_12 ( V_18 ) ;
if ( V_19 ) {
F_11 ( & V_18 -> V_21 , L_2 , V_19 ) ;
return V_19 ;
}
V_19 = F_13 ( & V_23 ) ;
if ( V_19 != 0 )
return V_19 ;
return F_14 ( & V_18 -> V_21 , & V_24 ,
V_25 , F_15 ( V_25 ) ) ;
}
static int F_16 ( struct V_17 * V_18 )
{
F_17 ( & V_18 -> V_21 ) ;
F_13 ( NULL ) ;
F_18 ( V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_21 )
{
return F_20 () ;
}
static int F_21 ( struct V_26 * V_21 )
{
return F_22 () ;
}
