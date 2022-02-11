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
F_4 ( V_3 , & V_3 -> V_13 . V_14 ) ;
F_5 ( V_3 , V_3 -> V_15 . V_16 . V_17 ) ;
V_5 = F_6 ( V_3 ) ;
if ( V_5 )
goto V_18;
if ( V_10 -> V_19 )
F_7 ( V_10 -> V_19 ) ;
if ( V_6 -> V_20 ) {
V_5 = V_6 -> V_20 ( V_3 ) ;
if ( V_5 )
goto V_21;
}
return 0 ;
V_21:
F_8 ( V_3 ) ;
V_18:
return V_5 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
struct V_10 * V_10 = V_8 -> V_10 ;
if ( V_3 -> V_11 != V_12 )
return;
if ( V_6 -> V_22 )
V_6 -> V_22 ( V_3 ) ;
if ( V_10 -> V_23 )
F_7 ( V_10 -> V_23 ) ;
F_8 ( V_3 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_10 * V_10 = NULL ;
struct V_7 * V_8 = NULL ;
int V_24 ;
F_11 ( & V_3 -> V_9 , L_1 ) ;
if ( ! V_6 || ! V_6 -> V_25 )
return - V_26 ;
for ( V_24 = 0 ; V_24 < F_12 ( V_27 ) ; V_24 ++ ) {
if ( strcmp ( V_6 -> V_25 , V_27 [ V_24 ] . V_25 ) == 0 ) {
V_10 = & V_27 [ V_24 ] ;
break;
}
}
if ( ! V_10 )
return - V_26 ;
V_3 -> V_13 . V_14 = V_10 -> V_14 ;
V_8 = F_13 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_10 = V_10 ;
F_14 ( & V_8 -> V_30 ) ;
F_15 ( & V_3 -> V_9 , V_8 ) ;
return 0 ;
}
static void T_1 F_16 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
F_11 ( & V_3 -> V_9 , L_2 ) ;
F_17 ( V_8 ) ;
F_15 ( & V_3 -> V_9 , NULL ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
int V_5 ;
F_19 ( & V_8 -> V_30 ) ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 )
goto V_31;
V_3 -> V_11 = V_12 ;
V_31:
F_20 ( & V_8 -> V_30 ) ;
return V_5 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
F_19 ( & V_8 -> V_30 ) ;
F_9 ( V_3 ) ;
V_3 -> V_11 = V_32 ;
F_20 ( & V_8 -> V_30 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_33 * V_14 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
F_19 ( & V_8 -> V_30 ) ;
F_4 ( V_3 , V_14 ) ;
V_3 -> V_13 . V_14 = * V_14 ;
F_20 ( & V_8 -> V_30 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_33 * V_14 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
F_19 ( & V_8 -> V_30 ) ;
* V_14 = V_3 -> V_13 . V_14 ;
F_20 ( & V_8 -> V_30 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_33 * V_14 )
{
struct V_7 * V_8 = F_3 ( & V_3 -> V_9 ) ;
int V_5 ;
F_19 ( & V_8 -> V_30 ) ;
V_5 = F_25 ( V_3 , V_14 ) ;
F_20 ( & V_8 -> V_30 ) ;
return V_5 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_34 ) ;
}
static void T_1 F_28 ( void )
{
F_29 ( & V_34 ) ;
}
