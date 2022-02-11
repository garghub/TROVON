static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
struct V_10 * V_10 = V_8 -> V_10 ;
if ( V_3 -> V_11 == V_12 )
return 0 ;
V_5 = F_4 ( V_3 ) ;
if ( V_5 )
goto V_13;
if ( V_10 -> V_14 )
F_5 ( V_10 -> V_14 ) ;
if ( V_6 -> V_15 ) {
V_5 = V_6 -> V_15 ( V_3 ) ;
if ( V_5 )
goto V_16;
}
return 0 ;
V_16:
F_6 ( V_3 ) ;
V_13:
return V_5 ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
struct V_10 * V_10 = V_8 -> V_10 ;
if ( V_3 -> V_11 != V_12 )
return;
if ( V_6 -> V_17 )
V_6 -> V_17 ( V_3 ) ;
if ( V_10 -> V_18 )
F_5 ( V_10 -> V_18 ) ;
F_6 ( V_3 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_10 * V_10 = NULL ;
struct V_7 * V_8 = NULL ;
int V_19 ;
F_9 ( & V_3 -> V_9 , L_1 ) ;
if ( ! V_6 || ! V_6 -> V_20 )
return - V_21 ;
for ( V_19 = 0 ; V_19 < F_10 ( V_22 ) ; V_19 ++ ) {
if ( strcmp ( V_6 -> V_20 , V_22 [ V_19 ] . V_20 ) == 0 ) {
V_10 = & V_22 [ V_19 ] ;
break;
}
}
if ( ! V_10 )
return - V_21 ;
V_3 -> V_23 . V_24 = V_10 -> V_24 ;
V_3 -> V_23 . V_25 = V_10 -> V_25 ;
V_3 -> V_23 . V_26 = V_10 -> V_26 ;
V_3 -> V_23 . V_27 = V_10 -> V_27 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_10 = V_10 ;
F_12 ( & V_3 -> V_9 , V_8 ) ;
return 0 ;
}
static void T_1 F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
F_9 ( & V_3 -> V_9 , L_2 ) ;
F_14 ( V_8 ) ;
F_12 ( & V_3 -> V_9 , NULL ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
int V_5 = 0 ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_11 = V_12 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
V_3 -> V_11 = V_30 ;
}
static int F_17 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
V_3 -> V_11 = V_31 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
int V_5 = 0 ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_11 = V_12 ;
return 0 ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_32 * V_25 )
{
F_20 ( V_3 , V_25 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_32 * V_25 )
{
return F_22 ( V_3 , V_25 ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_1 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
