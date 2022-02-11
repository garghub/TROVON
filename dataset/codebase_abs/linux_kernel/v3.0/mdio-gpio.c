static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_3 )
F_3 ( V_5 -> V_6 , 1 ) ;
else
F_4 ( V_5 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
return F_6 ( V_5 -> V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
F_8 ( V_5 -> V_6 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
F_8 ( V_5 -> V_8 , V_7 ) ;
}
static struct V_9 * T_1 F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_14 )
{
struct V_9 * V_15 ;
struct V_4 * V_5 ;
int V_16 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
goto V_18;
V_5 -> V_2 . V_19 = & V_20 ;
V_5 -> V_8 = V_13 -> V_8 ;
V_5 -> V_6 = V_13 -> V_6 ;
V_15 = F_12 ( & V_5 -> V_2 ) ;
if ( ! V_15 )
goto V_21;
V_15 -> V_22 = L_1 ,
V_15 -> V_23 = V_13 -> V_23 ;
V_15 -> V_24 = V_13 -> V_25 ;
V_15 -> V_26 = V_11 ;
if ( V_15 -> V_23 == ~ 0 )
goto V_27;
for ( V_16 = 0 ; V_16 < V_28 ; V_16 ++ )
if ( ! V_15 -> V_24 [ V_16 ] )
V_15 -> V_24 [ V_16 ] = V_29 ;
snprintf ( V_15 -> V_30 , V_31 , L_2 , V_14 ) ;
if ( F_13 ( V_5 -> V_8 , L_3 ) )
goto V_27;
if ( F_13 ( V_5 -> V_6 , L_4 ) )
goto V_32;
F_3 ( V_5 -> V_8 , 0 ) ;
F_14 ( V_11 , V_15 ) ;
return V_15 ;
V_32:
F_15 ( V_5 -> V_8 ) ;
V_27:
F_16 ( V_15 ) ;
V_21:
F_17 ( V_5 ) ;
V_18:
return NULL ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_19 ( V_11 ) ;
struct V_4 * V_5 = V_33 -> V_34 ;
F_14 ( V_11 , NULL ) ;
F_15 ( V_5 -> V_6 ) ;
F_15 ( V_5 -> V_8 ) ;
F_16 ( V_33 ) ;
F_17 ( V_5 ) ;
}
static void T_2 F_20 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_19 ( V_11 ) ;
F_21 ( V_33 ) ;
F_18 ( V_11 ) ;
}
static int T_1 F_22 ( struct V_35 * V_36 )
{
struct V_12 * V_13 = V_36 -> V_11 . V_37 ;
struct V_9 * V_15 ;
int V_38 ;
if ( ! V_13 )
return - V_39 ;
V_15 = F_10 ( & V_36 -> V_11 , V_13 , V_36 -> V_30 ) ;
if ( ! V_15 )
return - V_39 ;
V_38 = F_23 ( V_15 ) ;
if ( V_38 )
F_18 ( & V_36 -> V_11 ) ;
return V_38 ;
}
static int T_2 F_24 ( struct V_35 * V_36 )
{
F_20 ( & V_36 -> V_11 ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_35 * V_40 )
{
struct V_12 * V_13 ;
struct V_9 * V_15 ;
int V_38 ;
V_13 = F_11 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
return - V_41 ;
V_38 = F_26 ( V_40 -> V_11 . V_42 , 0 ) ;
if ( V_38 < 0 )
goto V_43;
V_13 -> V_8 = V_38 ;
V_38 = F_26 ( V_40 -> V_11 . V_42 , 1 ) ;
if ( V_38 < 0 )
goto V_43;
V_13 -> V_6 = V_38 ;
V_15 = F_10 ( & V_40 -> V_11 , V_13 , V_13 -> V_8 ) ;
if ( ! V_15 )
goto V_43;
V_38 = F_27 ( V_15 , V_40 -> V_11 . V_42 ) ;
if ( V_38 )
F_18 ( & V_40 -> V_11 ) ;
return V_38 ;
V_43:
F_17 ( V_13 ) ;
return - V_39 ;
}
static int T_2 F_28 ( struct V_35 * V_40 )
{
F_20 ( & V_40 -> V_11 ) ;
F_17 ( V_40 -> V_11 . V_37 ) ;
return 0 ;
}
static inline int T_3 F_29 ( void )
{
return F_30 ( & V_44 ) ;
}
static inline void T_4 F_31 ( void )
{
F_32 ( & V_44 ) ;
}
static inline int T_3 F_29 ( void ) { return 0 ; }
static inline void T_4 F_31 ( void ) { }
static int T_3 F_33 ( void )
{
int V_38 ;
V_38 = F_29 () ;
if ( V_38 )
return V_38 ;
V_38 = F_30 ( & V_45 ) ;
if ( V_38 )
F_31 () ;
return V_38 ;
}
static void T_4 F_34 ( void )
{
F_32 ( & V_45 ) ;
F_31 () ;
}
