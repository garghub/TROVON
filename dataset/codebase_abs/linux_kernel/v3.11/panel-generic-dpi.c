static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
int V_5 , V_6 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
struct V_11 * V_11 = V_9 -> V_11 ;
if ( V_3 -> V_12 == V_13 )
return 0 ;
F_4 ( V_3 , & V_3 -> V_14 . V_15 ) ;
F_5 ( V_3 , V_3 -> V_16 . V_17 . V_18 ) ;
V_5 = F_6 ( V_3 ) ;
if ( V_5 )
goto V_19;
if ( V_11 -> V_20 )
F_7 ( V_11 -> V_20 ) ;
for ( V_6 = 0 ; V_6 < V_7 -> V_21 ; ++ V_6 ) {
F_8 ( V_7 -> V_22 [ V_6 ] ,
V_7 -> V_23 [ V_6 ] ? 0 : 1 ) ;
}
return 0 ;
V_19:
return V_5 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
struct V_11 * V_11 = V_9 -> V_11 ;
int V_6 ;
if ( V_3 -> V_12 != V_13 )
return;
for ( V_6 = V_7 -> V_21 - 1 ; V_6 >= 0 ; -- V_6 ) {
F_8 ( V_7 -> V_22 [ V_6 ] ,
V_7 -> V_23 [ V_6 ] ? 1 : 0 ) ;
}
if ( V_11 -> V_24 )
F_7 ( V_11 -> V_24 ) ;
F_10 ( V_3 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_8 * V_9 = NULL ;
int V_6 , V_5 ;
F_12 ( V_3 -> V_10 , L_1 ) ;
if ( ! V_7 || ! V_7 -> V_25 )
return - V_26 ;
for ( V_6 = 0 ; V_6 < F_13 ( V_27 ) ; V_6 ++ ) {
if ( strcmp ( V_7 -> V_25 , V_27 [ V_6 ] . V_25 ) == 0 ) {
V_11 = & V_27 [ V_6 ] ;
break;
}
}
if ( ! V_11 )
return - V_26 ;
for ( V_6 = 0 ; V_6 < V_7 -> V_21 ; ++ V_6 ) {
V_5 = F_14 ( V_3 -> V_10 , V_7 -> V_22 [ V_6 ] ,
V_7 -> V_23 [ V_6 ] ?
V_28 : V_29 ,
L_2 ) ;
if ( V_5 )
return V_5 ;
}
V_3 -> V_14 . V_15 = V_11 -> V_15 ;
V_9 = F_15 ( V_3 -> V_10 , sizeof( * V_9 ) , V_30 ) ;
if ( ! V_9 )
return - V_31 ;
V_9 -> V_3 = V_3 ;
V_9 -> V_11 = V_11 ;
F_16 ( & V_9 -> V_32 ) ;
F_17 ( V_3 -> V_10 , V_9 ) ;
return 0 ;
}
static void T_1 F_18 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_10 , L_3 ) ;
F_17 ( V_3 -> V_10 , NULL ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
int V_5 ;
F_20 ( & V_9 -> V_32 ) ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 )
goto V_33;
V_3 -> V_12 = V_13 ;
V_33:
F_21 ( & V_9 -> V_32 ) ;
return V_5 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
F_20 ( & V_9 -> V_32 ) ;
F_9 ( V_3 ) ;
V_3 -> V_12 = V_34 ;
F_21 ( & V_9 -> V_32 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_35 * V_15 )
{
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
F_20 ( & V_9 -> V_32 ) ;
F_4 ( V_3 , V_15 ) ;
V_3 -> V_14 . V_15 = * V_15 ;
F_21 ( & V_9 -> V_32 ) ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_35 * V_15 )
{
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
F_20 ( & V_9 -> V_32 ) ;
* V_15 = V_3 -> V_14 . V_15 ;
F_21 ( & V_9 -> V_32 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_35 * V_15 )
{
struct V_8 * V_9 = F_3 ( V_3 -> V_10 ) ;
int V_5 ;
F_20 ( & V_9 -> V_32 ) ;
V_5 = F_26 ( V_3 , V_15 ) ;
F_21 ( & V_9 -> V_32 ) ;
return V_5 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_36 ) ;
}
static void T_1 F_29 ( void )
{
F_30 ( & V_36 ) ;
}
