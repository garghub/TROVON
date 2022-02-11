static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 -> V_6 ,
V_7 , V_4 -> V_8 ,
V_4 -> V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 -> V_6 ,
V_7 , V_4 -> V_8 , ~ V_4 -> V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 ;
T_1 V_10 ;
V_9 = F_7 ( V_4 -> V_5 -> V_6 ,
V_7 , & V_10 ) ;
if ( V_9 < 0 )
return - V_11 ;
return V_10 & V_4 -> V_8 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_1 * V_4 )
{
struct V_14 * V_14 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
V_14 = F_9 ( V_13 , V_3 ) ;
if ( F_10 ( V_14 ) )
return - V_15 ;
V_4 -> V_16 = F_11 ( sizeof( struct V_17 ) , V_18 ) ;
if ( ! V_4 -> V_16 )
return - V_15 ;
V_4 -> V_16 -> V_19 = V_3 -> V_20 -> V_21 ;
V_4 -> V_16 -> V_14 = V_14 ;
F_12 ( V_4 -> V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_5 = F_14 ( V_23 -> V_13 . V_25 ) ;
struct V_1 * * V_26 ;
int V_27 , V_9 ;
V_26 = F_15 ( & V_23 -> V_13 , sizeof( struct V_1 * )
* V_28 , V_18 ) ;
if ( ! V_26 )
return - V_15 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_26 [ V_27 ] = F_15 ( & V_23 -> V_13 ,
sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_26 [ V_27 ] )
return - V_15 ;
}
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_26 [ V_27 ] -> V_5 = V_5 ;
V_26 [ V_27 ] -> V_8 = 1 << V_27 ;
V_26 [ V_27 ] -> V_3 . V_20 = & V_29 [ V_27 ] ;
V_9 = F_8 ( & V_23 -> V_13 , V_26 [ V_27 ] ) ;
if ( V_9 ) {
switch ( V_27 ) {
case V_30 :
F_16 ( & V_23 -> V_13 , L_1 ) ;
goto V_31;
break;
case V_32 :
F_16 ( & V_23 -> V_13 , L_2 ) ;
goto V_33;
break;
case V_34 :
F_16 ( & V_23 -> V_13 , L_3 ) ;
goto V_35;
}
}
}
F_17 ( V_23 , V_26 ) ;
goto V_36;
V_35:
F_18 ( V_26 [ V_32 ] -> V_16 ) ;
F_19 ( V_26 [ V_32 ] -> V_3 . V_14 ) ;
V_33:
F_18 ( V_26 [ V_30 ] -> V_16 ) ;
F_19 ( V_26 [ V_30 ] -> V_3 . V_14 ) ;
V_31:
V_36:
return V_9 ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_1 * * V_26 = F_21 ( V_23 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_18 ( V_26 [ V_27 ] -> V_16 ) ;
F_19 ( V_26 [ V_27 ] -> V_3 . V_14 ) ;
}
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_37 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_37 ) ;
}
