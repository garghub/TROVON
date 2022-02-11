static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_6 * V_7 = & V_8 ;
struct V_9 * V_10 = V_4 -> V_11 . V_10 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned long V_16 ;
int V_17 ;
V_17 = F_2 () ;
F_3 ( V_16 ) ;
V_13 = F_4 ( V_10 , V_18 , sizeof( * V_15 ) ,
V_16 , V_17 ) ;
if ( ! V_13 )
return;
V_15 = F_5 ( V_13 ) ;
V_15 -> V_19 = V_2 -> V_19 ;
V_15 -> V_20 = V_2 -> V_20 ;
V_15 -> V_21 = V_2 -> V_21 ;
V_15 -> V_22 = V_2 -> V_22 ;
V_15 -> V_23 = V_2 -> V_23 ;
V_15 -> V_24 = V_2 -> V_24 ;
if ( ! F_6 ( V_7 , V_15 , V_10 , V_13 ) )
F_7 ( V_10 , V_13 ) ;
}
void F_8 ( bool V_25 )
{
if ( F_9 () != V_26 )
return;
if ( ! F_10 ( V_27 ) ) {
if ( V_25 )
V_28 = F_11 () ;
else
V_23 = F_11 () - V_28 ;
}
if ( V_25 )
V_24 ++ ;
}
static int F_12 ( void )
{
struct V_3 * V_4 = V_5 ;
T_1 V_29 , V_30 , V_31 , V_32 ;
T_2 V_33 , V_34 , V_35 = 0 ;
T_3 V_2 = 0 ;
T_3 V_36 = V_37 ;
T_3 V_38 = 0 ;
int V_39 = - 1 ;
F_13 ( V_36 , V_40 ) ;
V_26 = F_9 () ;
V_23 = 0 ;
V_24 = 0 ;
F_14 () ;
V_41 = true ;
F_15 ( V_32 , 0 ) ;
V_29 = F_11 () ;
do {
V_30 = F_11 () ;
V_31 = F_11 () ;
if ( F_16 ( V_32 ) ) {
V_33 = F_17 ( F_18 ( V_30 , V_32 ) ) ;
if ( V_33 < 0 ) {
F_19 ( V_42 L_1 ) ;
goto V_43;
}
if ( V_33 > V_38 )
V_38 = V_33 ;
}
V_32 = V_31 ;
V_34 = F_17 ( F_18 ( V_31 , V_29 ) ) ;
if ( V_34 < V_35 ) {
F_19 ( L_2 ) ;
break;
}
V_35 = V_34 ;
V_33 = F_17 ( F_18 ( V_31 , V_30 ) ) ;
if ( V_33 < 0 ) {
F_19 ( V_42 L_1 ) ;
goto V_43;
}
if ( V_33 > V_2 )
V_2 = V_33 ;
} while ( V_34 <= V_44 . V_45 );
F_14 () ;
V_41 = false ;
F_14 () ;
V_39 = 0 ;
if ( V_2 > V_36 || V_38 > V_36 ) {
struct V_1 V_46 ;
V_39 = 1 ;
if ( V_23 )
F_13 ( V_23 , V_40 ) ;
V_44 . V_47 ++ ;
V_46 . V_19 = V_44 . V_47 ;
V_46 . V_20 = V_2 ;
V_46 . V_21 = V_38 ;
V_46 . V_22 = V_48 ;
V_46 . V_23 = V_23 ;
V_46 . V_24 = V_24 ;
F_1 ( & V_46 ) ;
if ( V_2 > V_4 -> V_49 )
V_4 -> V_49 = V_2 ;
}
V_43:
return V_39 ;
}
static void F_20 ( void )
{
static struct V_50 * V_51 ;
int V_52 ;
if ( V_53 )
return;
if ( ! V_51 ) {
V_51 = & V_54 ;
F_21 () ;
F_22 ( V_51 , V_55 , V_56 ) ;
F_23 () ;
V_52 = F_24 ( V_51 ) ;
goto V_57;
}
if ( ! F_25 ( V_51 , & V_58 -> V_59 ) )
goto V_60;
F_21 () ;
F_22 ( V_51 , V_55 , V_56 ) ;
V_52 = F_26 ( F_9 () , V_51 ) ;
F_23 () ;
if ( V_52 >= V_61 )
V_52 = F_24 ( V_51 ) ;
V_57:
if ( V_52 >= V_61 )
goto V_60;
F_27 ( V_51 ) ;
F_28 ( V_52 , V_51 ) ;
F_29 ( 0 , V_51 ) ;
return;
V_60:
V_53 = true ;
}
static int F_30 ( void * V_62 )
{
T_3 V_63 ;
while ( ! F_31 () ) {
F_20 () ;
F_32 () ;
F_12 () ;
F_33 () ;
F_34 ( & V_44 . V_64 ) ;
V_63 = V_44 . V_65 - V_44 . V_45 ;
F_35 ( & V_44 . V_64 ) ;
F_13 ( V_63 , V_66 ) ;
if ( V_63 < 1 )
V_63 = 1 ;
if ( F_36 ( V_63 ) )
break;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_67 * V_68 ;
V_68 = F_38 ( F_30 , NULL , L_3 ) ;
if ( F_39 ( V_68 ) ) {
F_19 ( V_42 L_4 ) ;
return - V_69 ;
}
V_70 = V_68 ;
F_40 ( V_68 ) ;
return 0 ;
}
static void F_41 ( void )
{
if ( ! V_70 )
return;
F_42 ( V_70 ) ;
V_70 = NULL ;
}
static T_4 F_43 ( struct V_71 * V_72 , char T_5 * V_73 ,
T_6 V_74 , T_7 * V_75 )
{
char V_76 [ V_77 ] ;
T_3 * V_15 = V_72 -> V_78 ;
T_3 V_79 ;
int V_80 ;
if ( ! V_15 )
return - V_81 ;
if ( V_74 > sizeof( V_76 ) )
V_74 = sizeof( V_76 ) ;
V_79 = * V_15 ;
V_80 = snprintf ( V_76 , sizeof( V_76 ) , L_5 , V_79 ) ;
return F_44 ( V_73 , V_74 , V_75 , V_76 , V_80 ) ;
}
static T_4
F_45 ( struct V_71 * V_72 , const char T_5 * V_73 ,
T_6 V_74 , T_7 * V_75 )
{
T_3 V_79 ;
int V_82 ;
V_82 = F_46 ( V_73 , V_74 , 10 , & V_79 ) ;
if ( V_82 )
return V_82 ;
F_34 ( & V_44 . V_64 ) ;
if ( V_79 < V_44 . V_65 )
V_44 . V_45 = V_79 ;
else
V_82 = - V_83 ;
F_35 ( & V_44 . V_64 ) ;
if ( V_82 )
return V_82 ;
return V_74 ;
}
static T_4
F_47 ( struct V_71 * V_72 , const char T_5 * V_73 ,
T_6 V_74 , T_7 * V_75 )
{
T_3 V_79 ;
int V_82 ;
V_82 = F_46 ( V_73 , V_74 , 10 , & V_79 ) ;
if ( V_82 )
return V_82 ;
F_34 ( & V_44 . V_64 ) ;
if ( V_44 . V_45 < V_79 )
V_44 . V_65 = V_79 ;
else
V_82 = - V_83 ;
F_35 ( & V_44 . V_64 ) ;
if ( V_82 )
return V_82 ;
return V_74 ;
}
static int F_48 ( void )
{
struct V_84 * V_85 ;
struct V_84 * V_86 ;
V_85 = F_49 () ;
if ( F_39 ( V_85 ) )
return - V_69 ;
V_86 = F_50 ( L_6 , V_85 ) ;
if ( ! V_86 )
return - V_69 ;
V_87 = F_51 ( L_7 , 0640 ,
V_86 ,
& V_44 . V_65 ,
& V_88 ) ;
if ( ! V_87 )
goto V_82;
V_89 = F_51 ( L_8 , 0644 ,
V_86 ,
& V_44 . V_45 ,
& V_90 ) ;
if ( ! V_89 )
goto V_82;
return 0 ;
V_82:
F_52 ( V_86 ) ;
return - V_69 ;
}
static void F_53 ( struct V_3 * V_4 )
{
int V_82 ;
V_82 = F_37 ( V_4 ) ;
if ( V_82 )
F_19 ( V_42 L_9 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_41 () ;
}
static int F_55 ( struct V_3 * V_4 )
{
if ( V_91 )
return - V_92 ;
V_5 = V_4 ;
V_53 = false ;
V_44 . V_47 = 0 ;
V_4 -> V_49 = 0 ;
V_93 = V_37 ;
if ( ! V_37 )
V_37 = V_94 ;
if ( F_56 ( V_4 ) )
F_53 ( V_4 ) ;
V_91 = true ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_41 () ;
V_94 = V_37 ;
V_37 = V_93 ;
V_91 = false ;
}
T_8 static int F_58 ( void )
{
int V_39 ;
F_59 ( & V_44 . V_64 ) ;
V_39 = F_60 ( & V_95 ) ;
if ( V_39 )
return V_39 ;
F_48 () ;
return 0 ;
}
