static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_7 , V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] . V_10 == V_3 )
break;
if ( V_8 == F_3 ( V_9 ) )
V_7 = - V_11 ;
else
V_7 = F_4 ( V_6 , V_12 ,
V_13 ,
V_9 [ V_8 ] . V_14 <<
V_15 ) ;
if ( V_7 < 0 ) {
F_5 ( V_6 -> V_16 ,
L_1 , V_7 ) ;
return V_7 ;
}
V_2 -> V_3 = V_3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
F_7 ( V_17 ) ;
return F_4 ( V_6 , V_18 ,
V_19 , 1 ) ;
}
static void F_8 ( struct V_20 * V_21 )
{
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( & V_5 -> V_20 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( & V_5 -> V_20 , F_8 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_2 -> V_3 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 0 ) ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_6 * V_6 = F_16 ( V_23 -> V_16 . V_24 ) ;
struct V_4 * V_5 ;
struct V_1 * V_25 ;
int V_7 ;
V_5 = F_17 ( & V_23 -> V_16 , sizeof( * V_5 ) ,
V_26 ) ;
if ( ! V_5 )
return - V_27 ;
V_5 -> V_6 = V_6 ;
V_25 = & V_5 -> V_28 ;
V_25 -> V_3 = V_29 ;
V_25 -> V_30 = & V_31 ;
V_25 -> V_32 = & V_33 ;
F_18 ( V_25 , V_34 ) ;
F_19 ( V_25 , V_5 ) ;
F_20 ( & V_5 -> V_20 ) ;
V_7 = F_14 ( V_25 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_23 -> V_16 , L_2 , V_7 ) ;
goto V_35;
}
F_21 ( V_23 , V_5 ) ;
V_7 = F_22 ( & V_5 -> V_28 ) ;
if ( V_7 != 0 )
F_5 ( V_6 -> V_16 , L_3 ,
V_7 ) ;
V_35:
return V_7 ;
}
static int F_23 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = F_24 ( V_23 ) ;
F_25 ( & V_5 -> V_28 ) ;
F_12 ( & V_5 -> V_20 , F_8 ) ;
return 0 ;
}
