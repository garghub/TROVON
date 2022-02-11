static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
struct V_4 * V_5 ;
int V_6 , V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_10 ;
struct V_11 * V_12 ;
struct V_10 * * V_13 ;
struct V_14 * V_14 ;
T_2 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_5 = F_2 ( V_2 , V_20 , 0 ) ;
V_3 = F_3 ( V_9 , V_5 ) ;
if ( F_4 ( V_3 ) )
return F_5 ( V_3 ) ;
V_14 = F_6 ( V_9 , V_3 , & V_21 ) ;
if ( F_4 ( V_14 ) )
return F_5 ( V_14 ) ;
V_15 = F_7 ( V_22 ) ;
V_19 = F_8 ( V_9 , sizeof( * V_19 ) + sizeof( * V_13 ) * V_15 ,
V_23 ) ;
if ( ! V_19 )
return - V_24 ;
V_13 = V_19 -> V_13 ;
V_12 = & V_19 -> V_12 ;
V_12 -> V_13 = V_13 ;
V_12 -> V_25 = V_15 ;
V_10 = F_9 ( V_9 , L_1 , NULL , V_26 , 19200000 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_10 = F_9 ( V_9 , L_2 , NULL ,
V_26 , 32768 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
if ( ! V_22 [ V_6 ] )
continue;
V_10 = F_10 ( V_9 , V_22 [ V_6 ] ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_13 [ V_6 ] = V_10 ;
}
V_7 = F_11 ( V_9 -> V_27 , V_28 , V_12 ) ;
if ( V_7 )
return V_7 ;
V_17 = & V_19 -> V_17 ;
V_17 -> V_29 . V_27 = V_9 -> V_27 ;
V_17 -> V_29 . V_30 = & V_31 ,
V_17 -> V_29 . V_32 = V_33 ,
V_17 -> V_29 . V_34 = F_7 ( V_35 ) ,
V_17 -> V_14 = V_14 ;
V_17 -> V_36 = V_35 ,
F_12 ( V_2 , & V_17 -> V_29 ) ;
V_7 = F_13 ( & V_17 -> V_29 ) ;
if ( V_7 )
F_14 ( V_9 -> V_27 ) ;
return V_7 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_9 . V_27 ) ;
F_16 ( F_17 ( V_2 ) ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_37 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_37 ) ;
}
