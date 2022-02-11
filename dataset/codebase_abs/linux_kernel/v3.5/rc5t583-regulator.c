static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
int V_6 = F_4 ( V_2 , V_5 ) ;
return F_5 ( V_6 , V_4 -> V_7 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_9 , unsigned int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_12 ;
V_11 = F_4 ( V_2 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = F_4 ( V_2 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_5 ( abs ( V_11 - V_12 ) ,
V_4 -> V_7 -> V_13 ) ;
}
static int T_1 F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_16 = F_8 ( V_15 -> V_17 . V_18 ) ;
struct V_19 * V_20 = F_9 ( V_16 -> V_17 ) ;
struct V_21 * V_22 ;
struct V_23 V_24 = { } ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_25 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_28 ;
int V_29 ;
if ( ! V_20 ) {
F_10 ( & V_15 -> V_17 , L_1 ) ;
return - V_30 ;
}
V_25 = F_11 ( & V_15 -> V_17 , V_31 *
sizeof( struct V_3 ) , V_32 ) ;
if ( ! V_25 ) {
F_10 ( & V_15 -> V_17 , L_2 ) ;
return - V_33 ;
}
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 ) {
V_22 = V_20 -> V_34 [ V_29 ] ;
if ( ! V_22 )
continue;
V_4 = & V_25 [ V_29 ] ;
V_27 = & V_35 [ V_29 ] ;
V_4 -> V_7 = V_27 ;
V_4 -> V_36 = V_16 ;
V_4 -> V_17 = & V_15 -> V_17 ;
if ( V_27 -> V_37 == V_38 )
goto V_39;
V_28 = F_12 ( V_16 -> V_17 ,
V_27 -> V_37 ,
V_20 -> V_40 [ V_29 ] ,
V_20 -> V_41 [ V_29 ] ) ;
if ( V_28 < 0 )
F_13 ( & V_15 -> V_17 ,
L_3 , V_29 ) ;
V_39:
V_24 . V_17 = & V_15 -> V_17 ;
V_24 . V_42 = V_22 ;
V_24 . V_43 = V_4 ;
V_24 . V_44 = V_16 -> V_44 ;
V_2 = F_14 ( & V_27 -> V_45 , & V_24 ) ;
if ( F_15 ( V_2 ) ) {
F_10 ( & V_15 -> V_17 , L_4 ,
V_27 -> V_45 . V_46 ) ;
V_28 = F_16 ( V_2 ) ;
goto V_47;
}
V_4 -> V_2 = V_2 ;
}
F_17 ( V_15 , V_25 ) ;
return 0 ;
V_47:
while ( -- V_29 >= 0 )
F_18 ( V_25 [ V_29 ] . V_2 ) ;
return V_28 ;
}
static int T_2 F_19 ( struct V_14 * V_15 )
{
struct V_3 * V_25 = F_20 ( V_15 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 )
F_18 ( V_25 [ V_29 ] . V_2 ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_48 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_48 ) ;
}
