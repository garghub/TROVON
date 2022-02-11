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
F_26 ( V_2 , V_24 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_28 * V_29 , * V_30 ;
struct V_31 * V_32 , * V_33 ;
unsigned long V_3 ;
if ( ! V_24 -> V_27 )
return;
F_28 ( & V_2 -> V_34 , V_3 ) ;
F_29 (v, vt, &private->pageflip_event_list,
base.link) {
if ( V_29 -> V_35 . V_26 == V_24 ) {
F_30 ( & V_29 -> V_35 . V_36 ) ;
F_31 ( V_2 , V_29 -> V_37 ) ;
V_29 -> V_35 . V_38 ( & V_29 -> V_35 ) ;
}
}
F_29 (e, et, &file->event_list, link) {
F_30 ( & V_32 -> V_36 ) ;
V_32 -> V_38 ( V_32 ) ;
}
F_32 ( & V_2 -> V_34 , V_3 ) ;
F_19 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_39 * V_40 )
{
int V_6 ;
V_6 = F_36 ( & V_40 -> V_2 , F_37 ( 32 ) ) ;
if ( V_6 )
return V_6 ;
return F_38 ( & V_41 , V_40 ) ;
}
static int F_39 ( struct V_39 * V_40 )
{
F_40 ( & V_41 , V_40 ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
int V_6 ;
#ifdef F_42
V_6 = F_43 ( & V_42 ) ;
if ( V_6 < 0 )
goto V_43;
#endif
#ifdef F_44
V_6 = F_43 ( & V_44 ) ;
if ( V_6 < 0 )
goto V_45;
V_6 = F_43 ( & V_46 ) ;
if ( V_6 < 0 )
goto V_47;
V_6 = F_43 ( & V_48 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_45 () ;
if ( V_6 < 0 )
goto V_50;
#endif
#ifdef F_46
V_6 = F_43 ( & V_51 ) ;
if ( V_6 < 0 )
goto V_52;
#endif
#ifdef F_47
V_6 = F_43 ( & V_53 ) ;
if ( V_6 < 0 )
goto V_54;
#endif
#ifdef F_48
V_6 = F_43 ( & V_55 ) ;
if ( V_6 < 0 )
goto V_56;
#endif
#ifdef F_49
V_6 = F_43 ( & V_57 ) ;
if ( V_6 < 0 )
goto V_58;
#endif
#ifdef F_50
V_6 = F_43 ( & V_59 ) ;
if ( V_6 < 0 )
goto V_60;
#endif
#ifdef F_51
V_6 = F_43 ( & V_61 ) ;
if ( V_6 < 0 )
goto V_62;
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_63;
#endif
V_6 = F_43 ( & V_64 ) ;
if ( V_6 < 0 )
goto V_65;
V_66 = F_53 ( L_3 , - 1 ,
NULL , 0 ) ;
if ( F_54 ( V_66 ) ) {
V_6 = F_55 ( V_66 ) ;
goto V_67;
}
return 0 ;
V_67:
F_56 ( & V_64 ) ;
V_65:
#ifdef F_51
F_57 () ;
V_63:
F_56 ( & V_61 ) ;
V_62:
#endif
#ifdef F_50
F_56 ( & V_59 ) ;
V_60:
#endif
#ifdef F_49
F_56 ( & V_57 ) ;
V_58:
#endif
#ifdef F_48
F_56 ( & V_55 ) ;
V_56:
#endif
#ifdef F_47
F_56 ( & V_53 ) ;
V_54:
#endif
#ifdef F_46
F_56 ( & V_51 ) ;
V_52:
#endif
#ifdef F_44
F_58 () ;
V_50:
F_56 ( & V_48 ) ;
V_49:
F_56 ( & V_46 ) ;
V_47:
F_56 ( & V_44 ) ;
V_45:
#endif
#ifdef F_42
F_56 ( & V_42 ) ;
V_43:
#endif
return V_6 ;
}
static void T_2 F_59 ( void )
{
F_60 ( V_66 ) ;
F_56 ( & V_64 ) ;
#ifdef F_51
F_57 () ;
F_56 ( & V_61 ) ;
#endif
#ifdef F_50
F_56 ( & V_59 ) ;
#endif
#ifdef F_49
F_56 ( & V_57 ) ;
#endif
#ifdef F_48
F_56 ( & V_55 ) ;
#endif
#ifdef F_47
F_56 ( & V_53 ) ;
#endif
#ifdef F_44
F_58 () ;
F_56 ( & V_48 ) ;
F_56 ( & V_46 ) ;
F_56 ( & V_44 ) ;
#endif
#ifdef F_46
F_56 ( & V_51 ) ;
#endif
#ifdef F_42
F_56 ( & V_42 ) ;
#endif
}
