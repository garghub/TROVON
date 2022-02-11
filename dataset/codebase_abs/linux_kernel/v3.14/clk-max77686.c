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
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_12 )
{
return 32768 ;
}
static struct V_13 * F_9 ( struct V_14 * V_15 ,
struct V_1 * V_4 )
{
struct V_13 * V_13 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
V_13 = F_10 ( V_15 , V_3 ) ;
if ( F_11 ( V_13 ) )
return V_13 ;
V_4 -> V_16 = F_12 ( sizeof( struct V_17 ) , V_18 ) ;
if ( ! V_4 -> V_16 )
return F_13 ( - V_19 ) ;
V_4 -> V_16 -> V_20 = V_3 -> V_21 -> V_22 ;
V_4 -> V_16 -> V_13 = V_13 ;
F_14 ( V_4 -> V_16 ) ;
return V_13 ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_5 = F_16 ( V_24 -> V_15 . V_26 ) ;
struct V_1 * V_27 [ V_28 ] ;
struct V_13 * * V_29 ;
int V_30 , V_9 ;
V_29 = F_17 ( & V_24 -> V_15 , sizeof( struct V_13 * )
* V_28 , V_18 ) ;
if ( ! V_29 )
return - V_19 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_27 [ V_30 ] = F_17 ( & V_24 -> V_15 ,
sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_27 [ V_30 ] )
return - V_19 ;
}
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_27 [ V_30 ] -> V_5 = V_5 ;
V_27 [ V_30 ] -> V_8 = 1 << V_30 ;
V_27 [ V_30 ] -> V_3 . V_21 = & V_31 [ V_30 ] ;
V_29 [ V_30 ] = F_9 ( & V_24 -> V_15 , V_27 [ V_30 ] ) ;
if ( F_11 ( V_29 [ V_30 ] ) ) {
V_9 = F_18 ( V_29 [ V_30 ] ) ;
F_19 ( & V_24 -> V_15 , L_1 ,
V_27 [ V_30 ] -> V_3 . V_21 -> V_22 ) ;
goto V_32;
}
}
F_20 ( V_24 , V_29 ) ;
if ( V_5 -> V_15 -> V_33 ) {
struct V_34 * V_35 ;
V_35 = F_17 ( & V_24 -> V_15 ,
sizeof( * V_35 ) , V_18 ) ;
if ( ! V_35 ) {
V_9 = - V_19 ;
goto V_32;
}
V_35 -> V_36 = V_29 ;
V_35 -> V_37 = V_28 ;
V_9 = F_21 ( V_5 -> V_15 -> V_33 ,
V_38 , V_35 ) ;
if ( V_9 ) {
F_19 ( & V_24 -> V_15 , L_2 ) ;
goto V_32;
}
}
return 0 ;
V_32:
for ( -- V_30 ; V_30 >= 0 ; -- V_30 ) {
F_22 ( V_27 [ V_30 ] -> V_16 ) ;
F_23 ( V_27 [ V_30 ] -> V_3 . V_13 ) ;
}
return V_9 ;
}
static int F_24 ( struct V_23 * V_24 )
{
struct V_25 * V_5 = F_16 ( V_24 -> V_15 . V_26 ) ;
struct V_13 * * V_29 = F_25 ( V_24 ) ;
int V_30 ;
if ( V_5 -> V_15 -> V_33 )
F_26 ( V_5 -> V_15 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
struct V_2 * V_3 = F_27 ( V_29 [ V_30 ] ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_22 ( V_4 -> V_16 ) ;
F_23 ( V_29 [ V_30 ] ) ;
}
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_39 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_39 ) ;
}
