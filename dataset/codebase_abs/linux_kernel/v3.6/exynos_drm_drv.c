static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_7 ;
F_2 ( L_1 , __FILE__ ) ;
V_5 = F_3 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_5 ) {
F_4 ( L_2 ) ;
return - V_9 ;
}
F_5 ( & V_5 -> V_10 ) ;
V_2 -> V_11 = ( void * ) V_5 ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
V_6 = F_9 ( V_2 , V_7 ) ;
if ( V_6 )
goto V_13;
}
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ ) {
struct V_15 * V_16 ;
unsigned int V_17 = ( 1 << V_12 ) - 1 ;
V_16 = F_10 ( V_2 , V_17 , false ) ;
if ( ! V_16 )
goto V_13;
}
V_6 = F_11 ( V_2 , V_12 ) ;
if ( V_6 )
goto V_13;
V_6 = F_12 ( V_2 ) ;
if ( V_6 )
goto V_18;
F_13 ( V_2 ) ;
V_6 = F_14 ( V_2 ) ;
if ( V_6 ) {
F_4 ( L_3 ) ;
goto V_19;
}
V_20 = V_21 ;
return 0 ;
V_19:
F_15 ( V_2 ) ;
V_18:
F_16 ( V_2 ) ;
V_13:
F_17 ( V_2 ) ;
F_18 ( V_5 ) ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_20 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_21 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_24 * V_25 ;
F_2 ( L_1 , __FILE__ ) ;
V_25 = F_3 ( sizeof( * V_25 ) , V_8 ) ;
if ( ! V_25 )
return - V_9 ;
V_23 -> V_26 = V_25 ;
return F_23 ( V_2 , V_23 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_27 * V_28 , * V_29 ;
unsigned long V_3 ;
F_2 ( L_1 , __FILE__ ) ;
F_25 ( & V_2 -> V_30 , V_3 ) ;
F_26 (e, t, &private->pageflip_event_list,
base.link) {
if ( V_28 -> V_31 . V_25 == V_23 ) {
F_27 ( & V_28 -> V_31 . V_32 ) ;
V_28 -> V_31 . V_33 ( & V_28 -> V_31 ) ;
}
}
F_28 ( & V_2 -> V_30 , V_3 ) ;
F_29 ( V_2 , V_23 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_23 -> V_26 )
return;
F_18 ( V_23 -> V_26 ) ;
V_23 -> V_26 = NULL ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_34 * V_35 )
{
F_2 ( L_1 , __FILE__ ) ;
V_36 . V_37 = F_34 ( V_38 ) ;
return F_35 ( & V_36 , V_35 ) ;
}
static int F_36 ( struct V_34 * V_35 )
{
F_2 ( L_1 , __FILE__ ) ;
F_37 ( & V_36 , V_35 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_6 ;
F_2 ( L_1 , __FILE__ ) ;
#ifdef F_39
V_6 = F_40 ( & V_39 ) ;
if ( V_6 < 0 )
goto V_40;
#endif
#ifdef F_41
V_6 = F_40 ( & V_41 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_40 ( & V_43 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_40 ( & V_45 ) ;
if ( V_6 < 0 )
goto V_46;
#endif
#ifdef F_42
V_6 = F_40 ( & V_47 ) ;
if ( V_6 < 0 )
goto V_48;
#endif
#ifdef F_43
V_6 = F_40 ( & V_49 ) ;
if ( V_6 < 0 )
goto V_50;
#endif
V_6 = F_40 ( & V_51 ) ;
if ( V_6 < 0 )
goto V_52;
return 0 ;
V_52:
#ifdef F_43
F_44 ( & V_49 ) ;
V_50:
#endif
#ifdef F_42
V_48:
F_44 ( & V_47 ) ;
#endif
#ifdef F_41
F_44 ( & V_45 ) ;
V_46:
F_44 ( & V_43 ) ;
V_44:
F_44 ( & V_41 ) ;
V_42:
#endif
#ifdef F_39
F_44 ( & V_39 ) ;
V_40:
#endif
return V_6 ;
}
static void T_2 F_45 ( void )
{
F_2 ( L_1 , __FILE__ ) ;
F_44 ( & V_51 ) ;
#ifdef F_43
F_44 ( & V_49 ) ;
#endif
#ifdef F_41
F_44 ( & V_45 ) ;
F_44 ( & V_43 ) ;
F_44 ( & V_41 ) ;
#endif
#ifdef F_42
F_44 ( & V_47 ) ;
#endif
#ifdef F_39
F_44 ( & V_39 ) ;
#endif
}
