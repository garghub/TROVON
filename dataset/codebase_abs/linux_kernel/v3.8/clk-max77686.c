static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_6 ;
V_5 = F_4 ( V_4 -> V_7 -> V_8 ,
V_9 , V_4 -> V_10 , V_4 -> V_10 ) ;
return V_5 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_4 ( V_4 -> V_7 -> V_8 ,
V_9 , V_4 -> V_10 , ~ V_4 -> V_10 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
T_1 V_11 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_6 ;
V_5 = F_7 ( V_4 -> V_7 -> V_8 ,
V_9 , & V_11 ) ;
if ( V_5 < 0 )
return - V_12 ;
return V_11 & V_4 -> V_10 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_1 * V_4 )
{
struct V_15 * V_15 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
V_15 = F_9 ( V_14 , V_3 ) ;
if ( F_10 ( V_15 ) )
return - V_6 ;
V_4 -> V_16 = F_11 ( V_14 , sizeof( struct V_17 ) ,
V_18 ) ;
if ( F_10 ( V_4 -> V_16 ) )
return - V_6 ;
V_4 -> V_16 -> V_19 = V_3 -> V_20 -> V_21 ;
V_4 -> V_16 -> V_15 = V_15 ;
F_12 ( V_4 -> V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_7 = F_14 ( V_23 -> V_14 . V_25 ) ;
struct V_1 * * V_26 ;
int V_27 , V_5 ;
V_26 = F_11 ( & V_23 -> V_14 , sizeof( struct V_1 * )
* V_28 , V_18 ) ;
if ( F_10 ( V_26 ) )
return - V_6 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_26 [ V_27 ] = F_11 ( & V_23 -> V_14 ,
sizeof( struct V_1 ) , V_18 ) ;
if ( F_10 ( V_26 [ V_27 ] ) )
return - V_6 ;
}
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_26 [ V_27 ] -> V_7 = V_7 ;
V_26 [ V_27 ] -> V_10 = 1 << V_27 ;
V_26 [ V_27 ] -> V_3 . V_20 = & V_29 [ V_27 ] ;
V_5 = F_8 ( & V_23 -> V_14 , V_26 [ V_27 ] ) ;
if ( V_5 ) {
switch ( V_27 ) {
case V_30 :
F_15 ( & V_23 -> V_14 , L_1 ) ;
goto V_31;
break;
case V_32 :
F_15 ( & V_23 -> V_14 , L_2 ) ;
goto V_33;
break;
case V_34 :
F_15 ( & V_23 -> V_14 , L_3 ) ;
goto V_35;
}
}
}
F_16 ( V_23 , V_26 ) ;
goto V_36;
V_35:
F_17 ( V_26 [ V_32 ] -> V_16 ) ;
F_18 ( V_26 [ V_32 ] -> V_3 . V_15 ) ;
V_33:
F_17 ( V_26 [ V_30 ] -> V_16 ) ;
F_18 ( V_26 [ V_30 ] -> V_3 . V_15 ) ;
V_31:
V_36:
return V_5 ;
}
static int F_19 ( struct V_22 * V_23 )
{
struct V_1 * * V_26 = F_20 ( V_23 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_17 ( V_26 [ V_27 ] -> V_16 ) ;
F_18 ( V_26 [ V_27 ] -> V_3 . V_15 ) ;
}
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_37 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_37 ) ;
}
