static void F_1 ( const struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_2 ( V_2 -> V_5 . V_7 [ V_4 ] , V_3 & ( 1 << V_4 ) ) ;
}
static int F_3 ( struct V_8 * V_9 , void * V_5 , T_1 V_10 )
{
struct V_1 * V_2 = V_5 ;
F_1 ( V_2 , V_2 -> V_5 . V_11 [ V_10 ] ) ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 , void * V_5 , T_1 V_10 )
{
struct V_1 * V_2 = V_5 ;
F_1 ( V_2 , V_2 -> V_5 . V_12 ) ;
return 0 ;
}
static int T_2 F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_8 * V_17 ;
int (* F_6) ( struct V_8 * , void * , T_1 );
unsigned V_18 ;
int V_4 , V_19 ;
V_16 = V_14 -> V_20 . V_21 ;
if ( ! V_16 ) {
F_7 ( & V_14 -> V_20 , L_1 ) ;
return - V_22 ;
}
V_17 = F_8 ( V_16 -> V_17 ) ;
if ( ! V_17 ) {
F_7 ( & V_14 -> V_20 , L_2 ,
V_16 -> V_17 ) ;
return - V_22 ;
}
V_2 = F_9 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 ) {
V_19 = - V_24 ;
goto V_25;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = * V_16 ;
V_2 -> V_9 = F_9 ( sizeof( struct V_8 * ) * V_16 -> V_26 ,
V_23 ) ;
if ( ! V_2 -> V_9 ) {
V_19 = - V_24 ;
goto V_27;
}
if ( V_16 -> V_12 != V_28 ) {
V_18 = V_16 -> V_12 ;
F_6 = F_4 ;
} else {
V_18 = V_16 -> V_11 [ 0 ] ;
F_6 = NULL ;
}
for ( V_4 = 0 ; V_4 < V_16 -> V_6 ; V_4 ++ ) {
V_19 = F_10 ( V_16 -> V_7 [ V_4 ] , L_3 ) ;
if ( V_19 )
goto V_29;
F_11 ( V_16 -> V_7 [ V_4 ] ,
V_18 & ( 1 << V_4 ) ) ;
}
for ( V_4 = 0 ; V_4 < V_16 -> V_26 ; V_4 ++ ) {
T_1 V_30 = V_16 -> V_31 ? ( V_16 -> V_31 + V_4 ) : 0 ;
V_2 -> V_9 [ V_4 ] = F_12 ( V_17 , V_2 , V_30 , V_4 ,
F_3 , F_6 ) ;
if ( ! V_2 -> V_9 [ V_4 ] ) {
V_19 = - V_22 ;
F_7 ( & V_14 -> V_20 , L_4 , V_4 ) ;
goto V_32;
}
}
F_13 ( & V_14 -> V_20 , L_5 ,
V_16 -> V_26 , V_17 -> V_33 ) ;
F_14 ( V_14 , V_2 ) ;
return 0 ;
V_32:
for (; V_4 > 0 ; V_4 -- )
F_15 ( V_2 -> V_9 [ V_4 - 1 ] ) ;
V_4 = V_16 -> V_6 ;
V_29:
for (; V_4 > 0 ; V_4 -- )
F_16 ( V_16 -> V_7 [ V_4 - 1 ] ) ;
F_17 ( V_2 -> V_9 ) ;
V_27:
F_17 ( V_2 ) ;
V_25:
F_18 ( V_17 ) ;
return V_19 ;
}
static int T_3 F_19 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_20 ( V_14 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_26 ; V_4 ++ )
F_15 ( V_2 -> V_9 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_16 ( V_2 -> V_5 . V_7 [ V_4 ] ) ;
F_14 ( V_14 , NULL ) ;
F_18 ( V_2 -> V_17 ) ;
F_17 ( V_2 -> V_9 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_34 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_34 ) ;
}
