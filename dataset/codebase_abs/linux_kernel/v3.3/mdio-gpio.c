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
V_5 -> V_2 . V_21 = V_13 -> V_21 ;
V_5 -> V_8 = V_13 -> V_8 ;
V_5 -> V_6 = V_13 -> V_6 ;
V_15 = F_12 ( & V_5 -> V_2 ) ;
if ( ! V_15 )
goto V_22;
V_15 -> V_23 = L_1 ,
V_15 -> V_24 = V_13 -> V_24 ;
V_15 -> V_25 = V_13 -> V_26 ;
V_15 -> V_27 = V_11 ;
if ( V_15 -> V_24 == ~ 0 )
goto V_28;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ )
if ( ! V_15 -> V_25 [ V_16 ] )
V_15 -> V_25 [ V_16 ] = V_30 ;
snprintf ( V_15 -> V_31 , V_32 , L_2 , V_14 ) ;
if ( F_13 ( V_5 -> V_8 , L_3 ) )
goto V_28;
if ( F_13 ( V_5 -> V_6 , L_4 ) )
goto V_33;
F_3 ( V_5 -> V_8 , 0 ) ;
F_14 ( V_11 , V_15 ) ;
return V_15 ;
V_33:
F_15 ( V_5 -> V_8 ) ;
V_28:
F_16 ( V_15 ) ;
V_22:
F_17 ( V_5 ) ;
V_18:
return NULL ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_19 ( V_11 ) ;
struct V_4 * V_5 = V_34 -> V_35 ;
F_14 ( V_11 , NULL ) ;
F_15 ( V_5 -> V_6 ) ;
F_15 ( V_5 -> V_8 ) ;
F_16 ( V_34 ) ;
F_17 ( V_5 ) ;
}
static void T_2 F_20 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_19 ( V_11 ) ;
F_21 ( V_34 ) ;
F_18 ( V_11 ) ;
}
static int T_1 F_22 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_11 . V_38 ;
struct V_9 * V_15 ;
int V_39 ;
if ( ! V_13 )
return - V_40 ;
V_15 = F_10 ( & V_37 -> V_11 , V_13 , V_37 -> V_31 ) ;
if ( ! V_15 )
return - V_40 ;
V_39 = F_23 ( V_15 ) ;
if ( V_39 )
F_18 ( & V_37 -> V_11 ) ;
return V_39 ;
}
static int T_2 F_24 ( struct V_36 * V_37 )
{
F_20 ( & V_37 -> V_11 ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_36 * V_41 )
{
struct V_12 * V_13 ;
struct V_9 * V_15 ;
int V_39 ;
V_13 = F_11 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
return - V_42 ;
V_39 = F_26 ( V_41 -> V_11 . V_43 , 0 ) ;
if ( V_39 < 0 )
goto V_44;
V_13 -> V_8 = V_39 ;
V_39 = F_26 ( V_41 -> V_11 . V_43 , 1 ) ;
if ( V_39 < 0 )
goto V_44;
V_13 -> V_6 = V_39 ;
V_15 = F_10 ( & V_41 -> V_11 , V_13 , V_13 -> V_8 ) ;
if ( ! V_15 )
goto V_44;
V_39 = F_27 ( V_15 , V_41 -> V_11 . V_43 ) ;
if ( V_39 )
F_18 ( & V_41 -> V_11 ) ;
return V_39 ;
V_44:
F_17 ( V_13 ) ;
return - V_40 ;
}
static int T_2 F_28 ( struct V_36 * V_41 )
{
F_20 ( & V_41 -> V_11 ) ;
F_17 ( V_41 -> V_11 . V_38 ) ;
return 0 ;
}
static inline int T_3 F_29 ( void )
{
return F_30 ( & V_45 ) ;
}
static inline void T_4 F_31 ( void )
{
F_32 ( & V_45 ) ;
}
static inline int T_3 F_29 ( void ) { return 0 ; }
static inline void T_4 F_31 ( void ) { }
static int T_3 F_33 ( void )
{
int V_39 ;
V_39 = F_29 () ;
if ( V_39 )
return V_39 ;
V_39 = F_30 ( & V_46 ) ;
if ( V_39 )
F_31 () ;
return V_39 ;
}
static void T_4 F_34 ( void )
{
F_32 ( & V_46 ) ;
F_31 () ;
}
