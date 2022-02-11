static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_7 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
F_4 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_11 = ( void * ) V_5 ;
V_6 = F_5 ( V_2 ) ;
if ( V_6 < 0 ) {
F_6 ( L_1 ) ;
goto V_12;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_13;
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ ) {
struct V_15 * V_16 ;
unsigned long V_17 = ( 1 << V_18 ) - 1 ;
V_16 = F_10 ( V_2 , V_17 , false ) ;
if ( ! V_16 )
goto V_19;
}
V_6 = F_11 ( V_2 ) ;
if ( V_6 )
goto V_19;
F_12 ( V_2 ) ;
V_6 = F_13 ( V_2 , V_18 ) ;
if ( V_6 )
goto V_20;
V_6 = F_14 ( V_2 ) ;
if ( V_6 )
goto V_21;
F_15 ( V_2 ) ;
V_22 = V_23 ;
F_16 ( V_2 -> V_24 , V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
V_21:
F_18 ( V_2 ) ;
V_20:
F_19 ( V_2 ) ;
V_19:
F_20 ( V_2 ) ;
V_13:
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_12:
F_23 ( V_5 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_18 ( V_2 ) ;
F_27 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_26 * V_27 ;
F_29 ( V_2 ) ;
F_30 (connector, &dev->mode_config.connector_list, head) {
int V_28 = V_27 -> V_29 ;
if ( V_27 -> V_30 -> V_29 )
V_27 -> V_30 -> V_29 ( V_27 , V_31 ) ;
V_27 -> V_29 = V_28 ;
}
F_31 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
F_29 ( V_2 ) ;
F_30 (connector, &dev->mode_config.connector_list, head) {
if ( V_27 -> V_30 -> V_29 )
V_27 -> V_30 -> V_29 ( V_27 , V_27 -> V_29 ) ;
}
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_33 * V_36 ;
int V_6 ;
V_35 = F_2 ( sizeof( * V_35 ) , V_8 ) ;
if ( ! V_35 )
return - V_9 ;
V_33 -> V_37 = V_35 ;
V_6 = F_35 ( V_2 , V_33 ) ;
if ( V_6 )
goto V_38;
V_36 = F_36 ( L_2 , & V_39 ,
NULL , 0 ) ;
if ( F_37 ( V_36 ) ) {
V_6 = F_38 ( V_36 ) ;
goto V_40;
}
V_36 -> V_41 = V_42 | V_43 ;
V_35 -> V_36 = V_36 ;
return V_6 ;
V_40:
F_39 ( V_2 , V_33 ) ;
V_38:
F_23 ( V_35 ) ;
V_33 -> V_37 = NULL ;
return V_6 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
F_39 ( V_2 , V_33 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_34 * V_35 ;
struct V_44 * V_45 , * V_46 ;
struct V_47 * V_48 , * V_49 ;
unsigned long V_3 ;
if ( ! V_33 -> V_37 )
return;
F_42 ( & V_2 -> V_50 , V_3 ) ;
F_43 (v, vt, &private->pageflip_event_list,
base.link) {
if ( V_45 -> V_51 . V_35 == V_33 ) {
F_44 ( & V_45 -> V_51 . V_52 ) ;
F_45 ( V_2 , V_45 -> V_53 ) ;
V_45 -> V_51 . V_54 ( & V_45 -> V_51 ) ;
}
}
F_43 (e, et, &file->event_list, link) {
F_44 ( & V_48 -> V_52 ) ;
V_48 -> V_54 ( V_48 ) ;
}
F_46 ( & V_2 -> V_50 , V_3 ) ;
V_35 = V_33 -> V_37 ;
if ( V_35 -> V_36 )
F_47 ( V_35 -> V_36 ) ;
F_23 ( V_33 -> V_37 ) ;
V_33 -> V_37 = NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_55 * V_56 )
{
int V_6 ;
V_6 = F_51 ( & V_56 -> V_2 , F_52 ( 32 ) ) ;
if ( V_6 )
return V_6 ;
F_53 ( & V_56 -> V_2 ) ;
F_54 ( & V_56 -> V_2 ) ;
return F_55 ( & V_57 , V_56 ) ;
}
static int F_56 ( struct V_55 * V_56 )
{
F_57 ( F_58 ( V_56 ) ) ;
return 0 ;
}
static int F_59 ( struct V_58 * V_2 )
{
struct V_1 * V_59 = F_60 ( V_2 ) ;
T_1 V_60 ;
if ( F_61 ( V_2 ) )
return 0 ;
V_60 . V_61 = V_62 ;
return F_28 ( V_59 , V_60 ) ;
}
static int F_62 ( struct V_58 * V_2 )
{
struct V_1 * V_59 = F_60 ( V_2 ) ;
if ( F_61 ( V_2 ) )
return 0 ;
return F_32 ( V_59 ) ;
}
static int F_63 ( struct V_58 * V_2 )
{
struct V_1 * V_59 = F_60 ( V_2 ) ;
T_1 V_60 ;
if ( F_61 ( V_2 ) )
return 0 ;
V_60 . V_61 = V_62 ;
return F_28 ( V_59 , V_60 ) ;
}
static int F_64 ( struct V_58 * V_2 )
{
struct V_1 * V_59 = F_60 ( V_2 ) ;
if ( ! F_61 ( V_2 ) )
return 0 ;
return F_32 ( V_59 ) ;
}
static int T_2 F_65 ( void )
{
int V_6 ;
#ifdef F_66
V_6 = F_67 ( & V_63 ) ;
if ( V_6 < 0 )
goto V_64;
#endif
#ifdef F_68
V_6 = F_67 ( & V_65 ) ;
if ( V_6 < 0 )
goto V_66;
#endif
#ifdef F_69
V_6 = F_67 ( & V_67 ) ;
if ( V_6 < 0 )
goto V_68;
#endif
#ifdef F_70
V_6 = F_67 ( & V_69 ) ;
if ( V_6 < 0 )
goto V_70;
V_6 = F_67 ( & V_71 ) ;
if ( V_6 < 0 )
goto V_72;
#endif
#ifdef F_71
V_6 = F_67 ( & V_73 ) ;
if ( V_6 < 0 )
goto V_74;
#endif
#ifdef F_72
V_6 = F_67 ( & V_75 ) ;
if ( V_6 < 0 )
goto V_76;
#endif
#ifdef F_73
V_6 = F_67 ( & V_77 ) ;
if ( V_6 < 0 )
goto V_78;
#endif
#ifdef F_74
V_6 = F_67 ( & V_79 ) ;
if ( V_6 < 0 )
goto V_80;
#endif
#ifdef F_75
V_6 = F_67 ( & V_81 ) ;
if ( V_6 < 0 )
goto V_82;
#endif
#ifdef F_76
V_6 = F_67 ( & V_83 ) ;
if ( V_6 < 0 )
goto V_84;
V_6 = F_77 () ;
if ( V_6 < 0 )
goto V_85;
#endif
V_6 = F_67 ( & V_86 ) ;
if ( V_6 < 0 )
goto V_87;
V_88 = F_78 ( L_3 , - 1 ,
NULL , 0 ) ;
if ( F_37 ( V_88 ) ) {
V_6 = F_38 ( V_88 ) ;
goto V_89;
}
return 0 ;
V_89:
F_79 ( & V_86 ) ;
V_87:
#ifdef F_76
F_80 () ;
V_85:
F_79 ( & V_83 ) ;
V_84:
#endif
#ifdef F_75
F_79 ( & V_81 ) ;
V_82:
#endif
#ifdef F_74
F_79 ( & V_79 ) ;
V_80:
#endif
#ifdef F_73
F_79 ( & V_77 ) ;
V_78:
#endif
#ifdef F_72
F_79 ( & V_75 ) ;
V_76:
#endif
#ifdef F_71
F_79 ( & V_73 ) ;
V_74:
#endif
#ifdef F_70
F_79 ( & V_71 ) ;
V_72:
F_79 ( & V_69 ) ;
V_70:
#endif
#ifdef F_69
F_79 ( & V_67 ) ;
V_68:
#endif
#ifdef F_68
F_79 ( & V_65 ) ;
V_66:
#endif
#ifdef F_66
F_79 ( & V_63 ) ;
V_64:
#endif
return V_6 ;
}
static void T_3 F_81 ( void )
{
F_82 ( V_88 ) ;
F_79 ( & V_86 ) ;
#ifdef F_76
F_80 () ;
F_79 ( & V_83 ) ;
#endif
#ifdef F_75
F_79 ( & V_81 ) ;
#endif
#ifdef F_74
F_79 ( & V_79 ) ;
#endif
#ifdef F_73
F_79 ( & V_77 ) ;
#endif
#ifdef F_72
F_79 ( & V_75 ) ;
#endif
#ifdef F_70
F_79 ( & V_71 ) ;
F_79 ( & V_69 ) ;
#endif
#ifdef F_71
F_79 ( & V_73 ) ;
#endif
#ifdef F_69
F_79 ( & V_67 ) ;
#endif
#ifdef F_68
F_79 ( & V_65 ) ;
#endif
#ifdef F_66
F_79 ( & V_63 ) ;
#endif
}
