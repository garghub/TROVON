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
F_20 ( & V_46 . V_22 ) ;
V_46 . V_23 = V_23 ;
V_46 . V_24 = V_24 ;
F_1 ( & V_46 ) ;
if ( V_2 > V_4 -> V_48 )
V_4 -> V_48 = V_2 ;
}
V_43:
return V_39 ;
}
static void F_21 ( void )
{
struct V_49 * V_50 = & V_51 ;
int V_52 ;
if ( V_53 )
return;
if ( ! F_22 ( V_50 , & V_54 -> V_55 ) )
goto V_56;
F_23 () ;
F_24 ( V_50 , V_57 , V_58 ) ;
V_52 = F_25 ( F_9 () , V_50 ) ;
F_26 () ;
if ( V_52 >= V_59 )
V_52 = F_27 ( V_50 ) ;
if ( V_52 >= V_59 )
goto V_56;
F_28 ( V_50 ) ;
F_29 ( V_52 , V_50 ) ;
F_30 ( 0 , V_50 ) ;
return;
V_56:
V_53 = true ;
}
static int F_31 ( void * V_60 )
{
T_3 V_61 ;
while ( ! F_32 () ) {
F_21 () ;
F_33 () ;
F_12 () ;
F_34 () ;
F_35 ( & V_44 . V_62 ) ;
V_61 = V_44 . V_63 - V_44 . V_45 ;
F_36 ( & V_44 . V_62 ) ;
F_13 ( V_61 , V_64 ) ;
if ( V_61 < 1 )
V_61 = 1 ;
if ( F_37 ( V_61 ) )
break;
}
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_49 * V_50 = & V_51 ;
struct V_65 * V_66 ;
int V_52 ;
V_50 = & V_51 ;
F_23 () ;
F_24 ( V_50 , V_57 , V_58 ) ;
F_26 () ;
V_52 = F_27 ( V_50 ) ;
V_66 = F_39 ( F_31 , NULL , L_3 ) ;
if ( F_40 ( V_66 ) ) {
F_19 ( V_42 L_4 ) ;
return - V_67 ;
}
F_28 ( V_50 ) ;
F_29 ( V_52 , V_50 ) ;
F_30 ( V_66 -> V_68 , V_50 ) ;
V_69 = V_66 ;
F_41 ( V_66 ) ;
return 0 ;
}
static void F_42 ( void )
{
if ( ! V_69 )
return;
F_43 ( V_69 ) ;
V_69 = NULL ;
}
static T_4 F_44 ( struct V_70 * V_71 , char T_5 * V_72 ,
T_6 V_73 , T_7 * V_74 )
{
char V_75 [ V_76 ] ;
T_3 * V_15 = V_71 -> V_77 ;
T_3 V_78 ;
int V_79 ;
if ( ! V_15 )
return - V_80 ;
if ( V_73 > sizeof( V_75 ) )
V_73 = sizeof( V_75 ) ;
V_78 = * V_15 ;
V_79 = snprintf ( V_75 , sizeof( V_75 ) , L_5 , V_78 ) ;
return F_45 ( V_72 , V_73 , V_74 , V_75 , V_79 ) ;
}
static T_4
F_46 ( struct V_70 * V_71 , const char T_5 * V_72 ,
T_6 V_73 , T_7 * V_74 )
{
T_3 V_78 ;
int V_81 ;
V_81 = F_47 ( V_72 , V_73 , 10 , & V_78 ) ;
if ( V_81 )
return V_81 ;
F_35 ( & V_44 . V_62 ) ;
if ( V_78 < V_44 . V_63 )
V_44 . V_45 = V_78 ;
else
V_81 = - V_82 ;
F_36 ( & V_44 . V_62 ) ;
if ( V_81 )
return V_81 ;
return V_73 ;
}
static T_4
F_48 ( struct V_70 * V_71 , const char T_5 * V_72 ,
T_6 V_73 , T_7 * V_74 )
{
T_3 V_78 ;
int V_81 ;
V_81 = F_47 ( V_72 , V_73 , 10 , & V_78 ) ;
if ( V_81 )
return V_81 ;
F_35 ( & V_44 . V_62 ) ;
if ( V_44 . V_45 < V_78 )
V_44 . V_63 = V_78 ;
else
V_81 = - V_82 ;
F_36 ( & V_44 . V_62 ) ;
if ( V_81 )
return V_81 ;
return V_73 ;
}
static int F_49 ( void )
{
struct V_83 * V_84 ;
struct V_83 * V_85 ;
V_84 = F_50 () ;
if ( F_40 ( V_84 ) )
return - V_67 ;
V_85 = F_51 ( L_6 , V_84 ) ;
if ( ! V_85 )
return - V_67 ;
V_86 = F_52 ( L_7 , 0640 ,
V_85 ,
& V_44 . V_63 ,
& V_87 ) ;
if ( ! V_86 )
goto V_81;
V_88 = F_52 ( L_8 , 0644 ,
V_85 ,
& V_44 . V_45 ,
& V_89 ) ;
if ( ! V_88 )
goto V_81;
return 0 ;
V_81:
F_53 ( V_85 ) ;
return - V_67 ;
}
static void F_54 ( struct V_3 * V_4 )
{
int V_81 ;
V_81 = F_38 ( V_4 ) ;
if ( V_81 )
F_19 ( V_42 L_9 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_42 () ;
}
static int F_56 ( struct V_3 * V_4 )
{
if ( V_90 )
return - V_91 ;
V_5 = V_4 ;
V_53 = false ;
V_44 . V_47 = 0 ;
V_4 -> V_48 = 0 ;
V_92 = V_37 ;
if ( ! V_37 )
V_37 = V_93 ;
if ( F_57 ( V_4 ) )
F_54 ( V_4 ) ;
V_90 = true ;
return 0 ;
}
static void F_58 ( struct V_3 * V_4 )
{
F_42 () ;
V_93 = V_37 ;
V_37 = V_92 ;
V_90 = false ;
}
T_8 static int F_59 ( void )
{
int V_39 ;
F_60 ( & V_44 . V_62 ) ;
V_39 = F_61 ( & V_94 ) ;
if ( V_39 )
return V_39 ;
F_49 () ;
return 0 ;
}
