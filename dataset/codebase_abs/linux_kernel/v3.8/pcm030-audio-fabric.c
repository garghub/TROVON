static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_3 * V_7 ;
struct V_8 * V_9 = & V_10 ;
struct V_11 * V_12 ;
int V_13 ;
int V_14 ;
if ( ! F_2 ( L_1 ) )
return - V_15 ;
V_12 = F_3 ( & V_2 -> V_5 , sizeof( struct V_11 ) ,
V_16 ) ;
if ( ! V_12 )
return - V_17 ;
V_9 -> V_5 = & V_2 -> V_5 ;
F_4 ( V_2 , V_12 ) ;
V_12 -> V_9 = V_9 ;
V_7 = F_5 ( V_4 , L_2 , 0 ) ;
if ( ! V_7 ) {
F_6 ( & V_2 -> V_5 , L_3 ) ;
return - V_15 ;
}
for ( V_14 = 0 ; V_14 < V_9 -> V_18 ; V_14 ++ )
V_9 -> V_19 [ V_14 ] . V_20 = V_7 ;
V_13 = F_7 ( L_4 ) ;
if ( V_13 )
F_6 ( & V_2 -> V_5 , L_5 , V_13 ) ;
V_12 -> V_21 = F_8 ( L_6 , - 1 ) ;
if ( ! V_12 -> V_21 )
F_6 ( & V_2 -> V_5 , L_7 ) ;
V_13 = F_9 ( V_12 -> V_21 ) ;
if ( V_13 )
F_6 ( & V_2 -> V_5 , L_8 , V_13 ) ;
V_13 = F_10 ( V_9 ) ;
if ( V_13 )
F_6 ( & V_2 -> V_5 , L_9 , V_13 ) ;
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_12 ( V_2 ) ;
int V_13 ;
V_13 = F_13 ( V_12 -> V_9 ) ;
F_14 ( V_12 -> V_21 ) ;
return V_13 ;
}
