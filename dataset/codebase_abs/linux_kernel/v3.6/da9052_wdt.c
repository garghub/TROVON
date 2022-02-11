static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_1 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
struct V_8 * V_8 = V_4 -> V_8 ;
int V_9 , V_10 ;
V_9 = F_6 ( V_8 , V_11 ,
V_12 , 0 ) ;
if ( V_9 < 0 ) {
F_7 ( V_8 -> V_13 , L_1 ,
V_9 ) ;
return V_9 ;
}
if ( V_7 ) {
F_8 ( 150 ) ;
for ( V_10 = 0 ; V_10 < F_9 ( V_14 ) ; V_10 ++ )
if ( V_14 [ V_10 ] . time == V_7 )
break;
if ( V_10 == F_9 ( V_14 ) )
V_9 = - V_15 ;
else
V_9 = F_6 ( V_8 , V_11 ,
V_12 ,
V_14 [ V_10 ] . V_16 ) ;
if ( V_9 < 0 ) {
F_7 ( V_8 -> V_13 ,
L_2 , V_9 ) ;
return V_9 ;
}
V_6 -> V_7 = V_7 ;
V_4 -> V_17 = V_18 ;
}
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
F_11 ( & V_4 -> V_1 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
F_13 ( & V_4 -> V_1 , F_1 ) ;
}
static int F_14 ( struct V_5 * V_6 )
{
return F_4 ( V_6 , V_6 -> V_7 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
return F_4 ( V_6 , 0 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
struct V_8 * V_8 = V_4 -> V_8 ;
unsigned long V_19 , V_20 = V_18 ;
int V_9 ;
V_19 = ( V_20 - V_4 -> V_17 ) * 1000 / V_21 ;
if ( V_19 < V_22 )
F_17 ( V_19 ) ;
V_9 = F_6 ( V_8 , V_11 ,
V_23 , 1 << 7 ) ;
if ( V_9 < 0 )
goto V_24;
V_9 = F_6 ( V_8 , V_11 ,
V_23 , 0 << 7 ) ;
V_24:
return V_9 ;
}
static int T_1 F_18 ( struct V_25 * V_26 )
{
struct V_8 * V_8 = F_19 ( V_26 -> V_13 . V_27 ) ;
struct V_3 * V_4 ;
struct V_5 * V_28 ;
int V_9 ;
V_4 = F_20 ( & V_26 -> V_13 , sizeof( * V_4 ) ,
V_29 ) ;
if ( ! V_4 ) {
F_7 ( V_8 -> V_13 , L_3 ) ;
V_9 = - V_30 ;
goto V_31;
}
V_4 -> V_8 = V_8 ;
V_28 = & V_4 -> V_32 ;
V_28 -> V_7 = V_33 ;
V_28 -> V_34 = & V_35 ;
V_28 -> V_36 = & V_37 ;
F_21 ( V_28 , V_4 ) ;
F_22 ( & V_4 -> V_1 ) ;
V_9 = F_6 ( V_8 , V_11 ,
V_12 , 0 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_26 -> V_13 , L_4 ,
V_9 ) ;
goto V_31;
}
V_9 = F_23 ( & V_4 -> V_32 ) ;
if ( V_9 != 0 ) {
F_7 ( V_8 -> V_13 , L_5 ,
V_9 ) ;
goto V_31;
}
F_24 ( & V_26 -> V_13 , V_4 ) ;
V_31:
return V_9 ;
}
static int T_2 F_25 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_19 ( & V_26 -> V_13 ) ;
F_26 ( & V_4 -> V_32 ) ;
F_13 ( & V_4 -> V_1 , F_1 ) ;
return 0 ;
}
