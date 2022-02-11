static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
return ! ! F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
F_4 ( 0 , V_3 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
int V_10 , V_11 ;
if ( ! V_6 -> V_12 . V_13 )
return - V_14 ;
V_8 = F_6 ( & V_6 -> V_12 , sizeof( * V_8 ) +
sizeof( * V_9 ) * V_15 , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
V_8 -> V_18 = F_7 ( V_6 -> V_12 . V_13 , 0 ) ;
if ( ! V_8 -> V_18 )
return - V_17 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
V_9 = & V_8 -> V_19 . V_2 [ V_10 ] ;
V_9 -> V_4 = V_8 -> V_18 + F_8 ( V_10 ) ;
}
F_9 ( V_6 , V_8 ) ;
F_10 ( & V_6 -> V_12 ) ;
V_11 = F_11 ( & V_8 -> V_19 , & V_6 -> V_12 ,
& V_20 , 0 ,
V_15 ) ;
if ( V_11 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_6 -> V_12 ) ;
F_13 ( V_8 -> V_18 ) ;
return V_11 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_15 ( V_6 ) ;
int V_11 ;
V_11 = F_16 ( & V_8 -> V_19 ) ;
if ( V_11 ) {
F_17 ( & V_6 -> V_12 , L_1 , V_22 , V_11 ) ;
return V_11 ;
}
F_12 ( & V_6 -> V_12 ) ;
F_13 ( V_8 -> V_18 ) ;
return 0 ;
}
