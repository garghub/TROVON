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
F_15 ( V_2 -> V_23 , V_2 ) ;
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
static int F_24 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_25 * V_28 ;
int V_6 ;
V_27 = F_2 ( sizeof( * V_27 ) , V_8 ) ;
if ( ! V_27 )
return - V_9 ;
V_25 -> V_29 = V_27 ;
V_6 = F_25 ( V_2 , V_25 ) ;
if ( V_6 )
goto V_30;
V_28 = F_26 ( L_3 , & V_31 ,
NULL , 0 ) ;
if ( F_27 ( V_28 ) ) {
V_6 = F_28 ( V_28 ) ;
goto V_32;
}
V_28 -> V_33 = V_34 | V_35 ;
V_27 -> V_28 = V_28 ;
return V_6 ;
V_32:
F_29 ( V_2 , V_25 ) ;
V_30:
F_20 ( V_27 ) ;
V_25 -> V_29 = NULL ;
return V_6 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
F_29 ( V_2 , V_25 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_26 * V_27 ;
struct V_36 * V_37 , * V_38 ;
struct V_39 * V_40 , * V_41 ;
unsigned long V_3 ;
if ( ! V_25 -> V_29 )
return;
F_32 ( & V_2 -> V_42 , V_3 ) ;
F_33 (v, vt, &private->pageflip_event_list,
base.link) {
if ( V_37 -> V_43 . V_27 == V_25 ) {
F_34 ( & V_37 -> V_43 . V_44 ) ;
F_35 ( V_2 , V_37 -> V_45 ) ;
V_37 -> V_43 . V_46 ( & V_37 -> V_43 ) ;
}
}
F_33 (e, et, &file->event_list, link) {
F_34 ( & V_40 -> V_44 ) ;
V_40 -> V_46 ( V_40 ) ;
}
F_36 ( & V_2 -> V_42 , V_3 ) ;
V_27 = V_25 -> V_29 ;
if ( V_27 -> V_28 )
F_37 ( V_27 -> V_28 ) ;
F_20 ( V_25 -> V_29 ) ;
V_25 -> V_29 = NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_47 * V_48 )
{
int V_6 ;
V_6 = F_41 ( & V_48 -> V_2 , F_42 ( 32 ) ) ;
if ( V_6 )
return V_6 ;
return F_43 ( & V_49 , V_48 ) ;
}
static int F_44 ( struct V_47 * V_48 )
{
F_45 ( F_46 ( V_48 ) ) ;
return 0 ;
}
static int T_1 F_47 ( void )
{
int V_6 ;
#ifdef F_48
V_6 = F_49 ( & V_50 ) ;
if ( V_6 < 0 )
goto V_51;
#endif
#ifdef F_50
V_6 = F_49 ( & V_52 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_49 ( & V_54 ) ;
if ( V_6 < 0 )
goto V_55;
V_6 = F_49 ( & V_56 ) ;
if ( V_6 < 0 )
goto V_57;
V_6 = F_51 () ;
if ( V_6 < 0 )
goto V_58;
#endif
#ifdef F_52
V_6 = F_49 ( & V_59 ) ;
if ( V_6 < 0 )
goto V_60;
#endif
#ifdef F_53
V_6 = F_49 ( & V_61 ) ;
if ( V_6 < 0 )
goto V_62;
#endif
#ifdef F_54
V_6 = F_49 ( & V_63 ) ;
if ( V_6 < 0 )
goto V_64;
#endif
#ifdef F_55
V_6 = F_49 ( & V_65 ) ;
if ( V_6 < 0 )
goto V_66;
#endif
#ifdef F_56
V_6 = F_49 ( & V_67 ) ;
if ( V_6 < 0 )
goto V_68;
#endif
#ifdef F_57
V_6 = F_49 ( & V_69 ) ;
if ( V_6 < 0 )
goto V_70;
V_6 = F_58 () ;
if ( V_6 < 0 )
goto V_71;
#endif
V_6 = F_49 ( & V_72 ) ;
if ( V_6 < 0 )
goto V_73;
V_74 = F_59 ( L_4 , - 1 ,
NULL , 0 ) ;
if ( F_27 ( V_74 ) ) {
V_6 = F_28 ( V_74 ) ;
goto V_75;
}
return 0 ;
V_75:
F_60 ( & V_72 ) ;
V_73:
#ifdef F_57
F_61 () ;
V_71:
F_60 ( & V_69 ) ;
V_70:
#endif
#ifdef F_56
F_60 ( & V_67 ) ;
V_68:
#endif
#ifdef F_55
F_60 ( & V_65 ) ;
V_66:
#endif
#ifdef F_54
F_60 ( & V_63 ) ;
V_64:
#endif
#ifdef F_53
F_60 ( & V_61 ) ;
V_62:
#endif
#ifdef F_52
F_60 ( & V_59 ) ;
V_60:
#endif
#ifdef F_50
F_62 () ;
V_58:
F_60 ( & V_56 ) ;
V_57:
F_60 ( & V_54 ) ;
V_55:
F_60 ( & V_52 ) ;
V_53:
#endif
#ifdef F_48
F_60 ( & V_50 ) ;
V_51:
#endif
return V_6 ;
}
static void T_2 F_63 ( void )
{
F_64 ( V_74 ) ;
F_60 ( & V_72 ) ;
#ifdef F_57
F_61 () ;
F_60 ( & V_69 ) ;
#endif
#ifdef F_56
F_60 ( & V_67 ) ;
#endif
#ifdef F_55
F_60 ( & V_65 ) ;
#endif
#ifdef F_54
F_60 ( & V_63 ) ;
#endif
#ifdef F_53
F_60 ( & V_61 ) ;
#endif
#ifdef F_50
F_62 () ;
F_60 ( & V_56 ) ;
F_60 ( & V_54 ) ;
F_60 ( & V_52 ) ;
#endif
#ifdef F_52
F_60 ( & V_59 ) ;
#endif
#ifdef F_48
F_60 ( & V_50 ) ;
#endif
}
