static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 -> V_5 -> V_6 ) ;
void T_1 * V_7 = V_2 -> V_8 ;
int V_9 , V_10 ;
if ( ! F_3 ( V_7 ) )
return 1 ;
V_10 = F_4 ( V_2 ) ;
V_9 = F_3 ( V_4 -> V_11 + F_5 ( V_10 ) ) ;
F_6 ( V_4 -> V_5 . V_6 ,
L_1 ,
V_10 , V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
void T_1 * V_12 = V_2 -> V_8 ;
F_8 ( V_13 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( 10 ) ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_18 , V_19 ;
if ( ! V_15 -> V_6 . V_20 )
return - V_21 ;
V_4 = F_12 ( & V_15 -> V_6 ,
sizeof( struct V_3 ) +
V_22 * sizeof( * V_2 ) ,
V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_17 = F_13 ( V_15 , V_25 , 0 ) ;
V_4 -> V_11 = F_14 ( & V_15 -> V_6 , V_17 ) ;
if ( F_15 ( V_4 -> V_11 ) )
return F_16 ( V_4 -> V_11 ) ;
V_4 -> V_26 = F_17 ( & V_15 -> V_6 , L_2 ) ;
if ( F_15 ( V_4 -> V_26 ) ) {
F_18 ( & V_15 -> V_6 , L_3 ) ;
return F_16 ( V_4 -> V_26 ) ;
}
F_19 ( V_4 -> V_26 ) ;
F_8 ( V_27 , V_4 -> V_11 + V_28 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_18 ] ;
V_2 -> V_8 = V_4 -> V_11 + F_20 ( V_18 ) ;
}
F_21 ( V_15 , V_4 ) ;
F_22 ( & V_15 -> V_6 ) ;
V_19 = F_23 ( & V_4 -> V_5 , & V_15 -> V_6 ,
& V_29 , 0 , V_22 ) ;
if ( V_19 ) {
F_24 ( & V_15 -> V_6 ) ;
F_25 ( V_4 -> V_26 ) ;
return V_19 ;
}
return 0 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_27 ( V_15 ) ;
F_28 ( & V_4 -> V_5 ) ;
F_24 ( & V_15 -> V_6 ) ;
F_25 ( V_4 -> V_26 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_30 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_30 ) ;
}
