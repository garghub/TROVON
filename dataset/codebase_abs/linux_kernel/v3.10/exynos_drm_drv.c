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
V_6 = F_6 ( V_2 ) ;
if ( V_6 < 0 ) {
F_4 ( L_3 ) ;
goto V_12;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
V_6 = F_10 ( V_2 , V_7 ) ;
if ( V_6 )
goto V_14;
}
for ( V_7 = 0 ; V_7 < V_15 ; V_7 ++ ) {
struct V_16 * V_17 ;
unsigned int V_18 = ( 1 << V_13 ) - 1 ;
V_17 = F_11 ( V_2 , V_18 , false ) ;
if ( ! V_17 )
goto V_14;
}
V_6 = F_12 ( V_2 , V_13 ) ;
if ( V_6 )
goto V_14;
V_6 = F_13 ( V_2 ) ;
if ( V_6 )
goto V_19;
F_14 ( V_2 ) ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 ) {
F_4 ( L_4 ) ;
goto V_20;
}
V_21 = V_22 ;
return 0 ;
V_20:
F_16 ( V_2 ) ;
V_19:
F_17 ( V_2 ) ;
V_14:
F_18 ( V_2 ) ;
V_12:
F_19 ( V_2 ) ;
F_20 ( V_5 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_22 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_23 ( V_2 ) ;
F_19 ( V_2 ) ;
F_18 ( V_2 ) ;
F_20 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_25 * V_26 ;
F_2 ( L_1 , __FILE__ ) ;
V_26 = F_3 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
return - V_9 ;
V_24 -> V_27 = V_26 ;
return F_25 ( V_2 , V_24 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_28 * V_29 , * V_30 ;
unsigned long V_3 ;
F_2 ( L_1 , __FILE__ ) ;
F_27 ( & V_2 -> V_31 , V_3 ) ;
F_28 (e, t, &private->pageflip_event_list,
base.link) {
if ( V_29 -> V_32 . V_26 == V_24 ) {
F_29 ( & V_29 -> V_32 . V_33 ) ;
V_29 -> V_32 . V_34 ( & V_29 -> V_32 ) ;
}
}
F_30 ( & V_2 -> V_31 , V_3 ) ;
F_31 ( V_2 , V_24 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_24 -> V_27 )
return;
F_20 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_35 * V_36 )
{
F_2 ( L_1 , __FILE__ ) ;
V_36 -> V_2 . V_37 = F_36 ( 32 ) ;
V_38 . V_39 = F_37 ( V_40 ) ;
return F_38 ( & V_38 , V_36 ) ;
}
static int F_39 ( struct V_35 * V_36 )
{
F_2 ( L_1 , __FILE__ ) ;
F_40 ( & V_38 , V_36 ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
int V_6 ;
F_2 ( L_1 , __FILE__ ) ;
#ifdef F_42
V_6 = F_43 ( & V_41 ) ;
if ( V_6 < 0 )
goto V_42;
#endif
#ifdef F_44
V_6 = F_43 ( & V_43 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_43 ( & V_45 ) ;
if ( V_6 < 0 )
goto V_46;
V_6 = F_43 ( & V_47 ) ;
if ( V_6 < 0 )
goto V_48;
V_6 = F_45 () ;
if ( V_6 < 0 )
goto V_49;
#endif
#ifdef F_46
V_6 = F_43 ( & V_50 ) ;
if ( V_6 < 0 )
goto V_51;
#endif
#ifdef F_47
V_6 = F_43 ( & V_52 ) ;
if ( V_6 < 0 )
goto V_53;
#endif
#ifdef F_48
V_6 = F_43 ( & V_54 ) ;
if ( V_6 < 0 )
goto V_55;
#endif
#ifdef F_49
V_6 = F_43 ( & V_56 ) ;
if ( V_6 < 0 )
goto V_57;
#endif
#ifdef F_50
V_6 = F_43 ( & V_58 ) ;
if ( V_6 < 0 )
goto V_59;
#endif
#ifdef F_51
V_6 = F_43 ( & V_60 ) ;
if ( V_6 < 0 )
goto V_61;
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_62;
#endif
V_6 = F_43 ( & V_63 ) ;
if ( V_6 < 0 )
goto V_64;
V_65 = F_53 ( L_5 , - 1 ,
NULL , 0 ) ;
if ( F_54 ( V_65 ) ) {
V_6 = F_55 ( V_65 ) ;
goto V_66;
}
return 0 ;
V_66:
F_56 ( & V_63 ) ;
V_64:
#ifdef F_51
F_57 () ;
V_62:
F_56 ( & V_60 ) ;
V_61:
#endif
#ifdef F_50
F_56 ( & V_58 ) ;
V_59:
#endif
#ifdef F_49
F_56 ( & V_56 ) ;
V_57:
#endif
#ifdef F_48
F_56 ( & V_54 ) ;
V_55:
#endif
#ifdef F_47
F_56 ( & V_52 ) ;
V_53:
#endif
#ifdef F_46
F_56 ( & V_50 ) ;
V_51:
#endif
#ifdef F_44
F_58 () ;
V_49:
F_56 ( & V_47 ) ;
V_48:
F_56 ( & V_45 ) ;
V_46:
F_56 ( & V_43 ) ;
V_44:
#endif
#ifdef F_42
F_56 ( & V_41 ) ;
V_42:
#endif
return V_6 ;
}
static void T_2 F_59 ( void )
{
F_2 ( L_1 , __FILE__ ) ;
F_60 ( V_65 ) ;
F_56 ( & V_63 ) ;
#ifdef F_51
F_57 () ;
F_56 ( & V_60 ) ;
#endif
#ifdef F_50
F_56 ( & V_58 ) ;
#endif
#ifdef F_49
F_56 ( & V_56 ) ;
#endif
#ifdef F_48
F_56 ( & V_54 ) ;
#endif
#ifdef F_47
F_56 ( & V_52 ) ;
#endif
#ifdef F_44
F_58 () ;
F_56 ( & V_47 ) ;
F_56 ( & V_45 ) ;
F_56 ( & V_43 ) ;
#endif
#ifdef F_46
F_56 ( & V_50 ) ;
#endif
#ifdef F_42
F_56 ( & V_41 ) ;
#endif
}
