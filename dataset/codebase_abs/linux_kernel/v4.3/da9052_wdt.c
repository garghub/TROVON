static void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_3 ( V_4 ) ;
struct V_8 * V_8 = V_7 -> V_8 ;
int V_9 , V_10 ;
V_9 = F_4 ( V_8 , V_11 ,
V_12 , 0 ) ;
if ( V_9 < 0 ) {
F_5 ( V_8 -> V_13 , L_1 ,
V_9 ) ;
return V_9 ;
}
if ( V_5 ) {
F_6 ( 150 ) ;
for ( V_10 = 0 ; V_10 < F_7 ( V_14 ) ; V_10 ++ )
if ( V_14 [ V_10 ] . time == V_5 )
break;
if ( V_10 == F_7 ( V_14 ) )
V_9 = - V_15 ;
else
V_9 = F_4 ( V_8 , V_11 ,
V_12 ,
V_14 [ V_10 ] . V_16 ) ;
if ( V_9 < 0 ) {
F_5 ( V_8 -> V_13 ,
L_2 , V_9 ) ;
return V_9 ;
}
V_4 -> V_5 = V_5 ;
V_7 -> V_17 = V_18 ;
}
return 0 ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 ) ;
F_9 ( & V_7 -> V_1 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 ) ;
F_11 ( & V_7 -> V_1 , F_1 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , V_4 -> V_5 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , 0 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 ) ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_19 , V_20 = V_18 ;
int V_9 ;
V_19 = ( V_20 - V_7 -> V_17 ) * 1000 / V_21 ;
if ( V_19 < V_22 )
F_15 ( V_19 ) ;
V_9 = F_4 ( V_8 , V_11 ,
V_23 , 1 << 7 ) ;
if ( V_9 < 0 )
goto V_24;
V_9 = F_4 ( V_8 , V_11 ,
V_23 , 0 << 7 ) ;
V_24:
return V_9 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_8 * V_8 = F_17 ( V_26 -> V_13 . V_27 ) ;
struct V_6 * V_7 ;
struct V_3 * V_28 ;
int V_9 ;
V_7 = F_18 ( & V_26 -> V_13 , sizeof( * V_7 ) ,
V_29 ) ;
if ( ! V_7 ) {
V_9 = - V_30 ;
goto V_31;
}
V_7 -> V_8 = V_8 ;
V_28 = & V_7 -> V_32 ;
V_28 -> V_5 = V_33 ;
V_28 -> V_34 = & V_35 ;
V_28 -> V_36 = & V_37 ;
V_28 -> V_27 = & V_26 -> V_13 ;
F_19 ( V_28 , V_7 ) ;
F_20 ( & V_7 -> V_1 ) ;
V_9 = F_4 ( V_8 , V_11 ,
V_12 , 0 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_26 -> V_13 , L_3 ,
V_9 ) ;
goto V_31;
}
V_9 = F_21 ( & V_7 -> V_32 ) ;
if ( V_9 != 0 ) {
F_5 ( V_8 -> V_13 , L_4 ,
V_9 ) ;
goto V_31;
}
F_22 ( V_26 , V_7 ) ;
V_31:
return V_9 ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = F_24 ( V_26 ) ;
F_25 ( & V_7 -> V_32 ) ;
F_11 ( & V_7 -> V_1 , F_1 ) ;
return 0 ;
}
