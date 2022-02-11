static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_7 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_2 -> V_11 = ( void * ) V_5 ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 ) {
F_5 ( L_1 ) ;
goto V_12;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
V_6 = F_9 ( V_2 , V_7 ) ;
if ( V_6 )
goto V_14;
}
for ( V_7 = 0 ; V_7 < V_15 ; V_7 ++ ) {
struct V_16 * V_17 ;
unsigned int V_18 = ( 1 << V_13 ) - 1 ;
V_17 = F_10 ( V_2 , V_18 , false ) ;
if ( ! V_17 )
goto V_14;
}
V_6 = F_11 ( V_2 , V_13 ) ;
if ( V_6 )
goto V_14;
V_6 = F_12 ( V_2 ) ;
if ( V_6 )
goto V_19;
F_13 ( V_2 ) ;
V_6 = F_14 ( V_2 ) ;
if ( V_6 ) {
F_5 ( L_2 ) ;
goto V_20;
}
V_21 = V_22 ;
return 0 ;
V_20:
F_15 ( V_2 ) ;
V_19:
F_16 ( V_2 ) ;
V_14:
F_17 ( V_2 ) ;
V_12:
F_18 ( V_2 ) ;
F_19 ( V_5 ) ;
return V_6 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_22 ( V_2 ) ;
F_18 ( V_2 ) ;
F_17 ( V_2 ) ;
F_19 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_25 * V_26 ;
int V_6 ;
V_26 = F_2 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
return - V_9 ;
V_24 -> V_27 = V_26 ;
V_6 = F_24 ( V_2 , V_24 ) ;
if ( V_6 ) {
F_19 ( V_26 ) ;
V_24 -> V_27 = NULL ;
}
return V_6 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_28 * V_29 , * V_30 ;
unsigned long V_3 ;
F_26 ( & V_2 -> V_31 , V_3 ) ;
F_27 (e, t, &private->pageflip_event_list,
base.link) {
if ( V_29 -> V_32 . V_26 == V_24 ) {
F_28 ( & V_29 -> V_32 . V_33 ) ;
V_29 -> V_32 . V_34 ( & V_29 -> V_32 ) ;
}
}
F_29 ( & V_2 -> V_31 , V_3 ) ;
F_30 ( V_2 , V_24 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( ! V_24 -> V_27 )
return;
F_19 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
}
static int F_34 ( struct V_35 * V_36 )
{
V_36 -> V_2 . V_37 = F_35 ( 32 ) ;
return F_36 ( & V_38 , V_36 ) ;
}
static int F_37 ( struct V_35 * V_36 )
{
F_38 ( & V_38 , V_36 ) ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_6 ;
#ifdef F_40
V_6 = F_41 ( & V_39 ) ;
if ( V_6 < 0 )
goto V_40;
#endif
#ifdef F_42
V_6 = F_41 ( & V_41 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_41 ( & V_43 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_41 ( & V_45 ) ;
if ( V_6 < 0 )
goto V_46;
V_6 = F_43 () ;
if ( V_6 < 0 )
goto V_47;
#endif
#ifdef F_44
V_6 = F_41 ( & V_48 ) ;
if ( V_6 < 0 )
goto V_49;
#endif
#ifdef F_45
V_6 = F_41 ( & V_50 ) ;
if ( V_6 < 0 )
goto V_51;
#endif
#ifdef F_46
V_6 = F_41 ( & V_52 ) ;
if ( V_6 < 0 )
goto V_53;
#endif
#ifdef F_47
V_6 = F_41 ( & V_54 ) ;
if ( V_6 < 0 )
goto V_55;
#endif
#ifdef F_48
V_6 = F_41 ( & V_56 ) ;
if ( V_6 < 0 )
goto V_57;
#endif
#ifdef F_49
V_6 = F_41 ( & V_58 ) ;
if ( V_6 < 0 )
goto V_59;
V_6 = F_50 () ;
if ( V_6 < 0 )
goto V_60;
#endif
V_6 = F_41 ( & V_61 ) ;
if ( V_6 < 0 )
goto V_62;
V_63 = F_51 ( L_3 , - 1 ,
NULL , 0 ) ;
if ( F_52 ( V_63 ) ) {
V_6 = F_53 ( V_63 ) ;
goto V_64;
}
return 0 ;
V_64:
F_54 ( & V_61 ) ;
V_62:
#ifdef F_49
F_55 () ;
V_60:
F_54 ( & V_58 ) ;
V_59:
#endif
#ifdef F_48
F_54 ( & V_56 ) ;
V_57:
#endif
#ifdef F_47
F_54 ( & V_54 ) ;
V_55:
#endif
#ifdef F_46
F_54 ( & V_52 ) ;
V_53:
#endif
#ifdef F_45
F_54 ( & V_50 ) ;
V_51:
#endif
#ifdef F_44
F_54 ( & V_48 ) ;
V_49:
#endif
#ifdef F_42
F_56 () ;
V_47:
F_54 ( & V_45 ) ;
V_46:
F_54 ( & V_43 ) ;
V_44:
F_54 ( & V_41 ) ;
V_42:
#endif
#ifdef F_40
F_54 ( & V_39 ) ;
V_40:
#endif
return V_6 ;
}
static void T_2 F_57 ( void )
{
F_58 ( V_63 ) ;
F_54 ( & V_61 ) ;
#ifdef F_49
F_55 () ;
F_54 ( & V_58 ) ;
#endif
#ifdef F_48
F_54 ( & V_56 ) ;
#endif
#ifdef F_47
F_54 ( & V_54 ) ;
#endif
#ifdef F_46
F_54 ( & V_52 ) ;
#endif
#ifdef F_45
F_54 ( & V_50 ) ;
#endif
#ifdef F_42
F_56 () ;
F_54 ( & V_45 ) ;
F_54 ( & V_43 ) ;
F_54 ( & V_41 ) ;
#endif
#ifdef F_44
F_54 ( & V_48 ) ;
#endif
#ifdef F_40
F_54 ( & V_39 ) ;
#endif
}
