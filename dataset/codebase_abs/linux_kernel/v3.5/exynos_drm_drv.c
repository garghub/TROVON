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
V_6 = F_10 ( V_2 , V_7 ) ;
if ( V_6 )
goto V_13;
}
V_6 = F_11 ( V_2 , V_12 ) ;
if ( V_6 )
goto V_13;
V_6 = F_12 ( V_2 ) ;
if ( V_6 )
goto V_15;
F_13 ( V_2 ) ;
V_6 = F_14 ( V_2 ) ;
if ( V_6 ) {
F_4 ( L_3 ) ;
goto V_16;
}
V_17 = V_18 ;
return 0 ;
V_16:
F_15 ( V_2 ) ;
V_15:
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
static int F_22 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_2 ( L_1 , __FILE__ ) ;
V_22 = F_3 ( sizeof( * V_22 ) , V_8 ) ;
if ( ! V_22 )
return - V_9 ;
F_23 ( & V_20 -> V_23 ) ;
V_20 -> V_24 = V_22 ;
return F_24 ( V_2 , V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_25 * V_26 , * V_27 ;
unsigned long V_3 ;
F_2 ( L_1 , __FILE__ ) ;
F_26 ( & V_2 -> V_28 , V_3 ) ;
F_27 (e, t, &private->pageflip_event_list,
base.link) {
if ( V_26 -> V_29 . V_22 == V_20 ) {
F_28 ( & V_26 -> V_29 . V_30 ) ;
V_26 -> V_29 . V_31 ( & V_26 -> V_29 ) ;
}
}
F_29 ( & V_20 -> V_23 ) ;
F_30 ( & V_2 -> V_28 , V_3 ) ;
F_31 ( V_2 , V_20 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_20 -> V_24 )
return;
F_18 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_32 * V_33 )
{
F_2 ( L_1 , __FILE__ ) ;
V_34 . V_35 = F_36 ( V_36 ) ;
return F_37 ( & V_34 , V_33 ) ;
}
static int F_38 ( struct V_32 * V_33 )
{
F_2 ( L_1 , __FILE__ ) ;
F_39 ( & V_34 , V_33 ) ;
return 0 ;
}
static int T_1 F_40 ( void )
{
int V_6 ;
F_2 ( L_1 , __FILE__ ) ;
#ifdef F_41
V_6 = F_42 ( & V_37 ) ;
if ( V_6 < 0 )
goto V_38;
#endif
#ifdef F_43
V_6 = F_42 ( & V_39 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_42 ( & V_41 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_42 ( & V_43 ) ;
if ( V_6 < 0 )
goto V_44;
#endif
#ifdef F_44
V_6 = F_42 ( & V_45 ) ;
if ( V_6 < 0 )
goto V_46;
#endif
#ifdef F_45
V_6 = F_42 ( & V_47 ) ;
if ( V_6 < 0 )
goto V_48;
#endif
V_6 = F_42 ( & V_49 ) ;
if ( V_6 < 0 )
goto V_50;
return 0 ;
V_50:
#ifdef F_45
F_46 ( & V_47 ) ;
V_48:
#endif
#ifdef F_44
V_46:
F_46 ( & V_45 ) ;
#endif
#ifdef F_43
F_46 ( & V_43 ) ;
V_44:
F_46 ( & V_41 ) ;
V_42:
F_46 ( & V_39 ) ;
V_40:
#endif
#ifdef F_41
F_46 ( & V_37 ) ;
V_38:
#endif
return V_6 ;
}
static void T_2 F_47 ( void )
{
F_2 ( L_1 , __FILE__ ) ;
F_46 ( & V_49 ) ;
#ifdef F_45
F_46 ( & V_47 ) ;
#endif
#ifdef F_43
F_46 ( & V_43 ) ;
F_46 ( & V_41 ) ;
F_46 ( & V_39 ) ;
#endif
#ifdef F_44
F_46 ( & V_45 ) ;
#endif
#ifdef F_41
F_46 ( & V_37 ) ;
#endif
}
