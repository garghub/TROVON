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
static void F_20 ( bool V_50 )
{
static struct V_51 * V_52 ;
int V_53 ;
if ( V_54 )
return;
if ( V_50 ) {
V_52 = & V_55 ;
F_21 () ;
F_22 ( V_52 , V_56 , V_57 ) ;
F_23 () ;
V_53 = F_24 ( V_52 ) ;
goto V_58;
}
if ( ! F_25 ( V_52 , & V_59 -> V_60 ) )
goto V_61;
F_21 () ;
F_22 ( V_52 , V_56 , V_57 ) ;
V_53 = F_26 ( F_9 () , V_52 ) ;
F_23 () ;
if ( V_53 >= V_62 )
V_53 = F_24 ( V_52 ) ;
V_58:
if ( V_53 >= V_62 )
goto V_61;
F_27 ( V_52 ) ;
F_28 ( V_53 , V_52 ) ;
F_29 ( 0 , V_52 ) ;
return;
V_61:
V_54 = true ;
}
static int F_30 ( void * V_63 )
{
T_3 V_64 ;
bool V_50 = true ;
while ( ! F_31 () ) {
F_20 ( V_50 ) ;
V_50 = false ;
F_32 () ;
F_12 () ;
F_33 () ;
F_34 ( & V_44 . V_65 ) ;
V_64 = V_44 . V_66 - V_44 . V_45 ;
F_35 ( & V_44 . V_65 ) ;
F_13 ( V_64 , V_67 ) ;
if ( V_64 < 1 )
V_64 = 1 ;
if ( F_36 ( V_64 ) )
break;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_68 * V_69 ;
V_69 = F_38 ( F_30 , NULL , L_3 ) ;
if ( F_39 ( V_69 ) ) {
F_19 ( V_42 L_4 ) ;
return - V_70 ;
}
V_71 = V_69 ;
F_40 ( V_69 ) ;
return 0 ;
}
static void F_41 ( void )
{
if ( ! V_71 )
return;
F_42 ( V_71 ) ;
V_71 = NULL ;
}
static T_4 F_43 ( struct V_72 * V_73 , char T_5 * V_74 ,
T_6 V_75 , T_7 * V_76 )
{
char V_77 [ V_78 ] ;
T_3 * V_15 = V_73 -> V_79 ;
T_3 V_80 ;
int V_81 ;
if ( ! V_15 )
return - V_82 ;
if ( V_75 > sizeof( V_77 ) )
V_75 = sizeof( V_77 ) ;
V_80 = * V_15 ;
V_81 = snprintf ( V_77 , sizeof( V_77 ) , L_5 , V_80 ) ;
return F_44 ( V_74 , V_75 , V_76 , V_77 , V_81 ) ;
}
static T_4
F_45 ( struct V_72 * V_73 , const char T_5 * V_74 ,
T_6 V_75 , T_7 * V_76 )
{
T_3 V_80 ;
int V_83 ;
V_83 = F_46 ( V_74 , V_75 , 10 , & V_80 ) ;
if ( V_83 )
return V_83 ;
F_34 ( & V_44 . V_65 ) ;
if ( V_80 < V_44 . V_66 )
V_44 . V_45 = V_80 ;
else
V_83 = - V_84 ;
F_35 ( & V_44 . V_65 ) ;
if ( V_83 )
return V_83 ;
return V_75 ;
}
static T_4
F_47 ( struct V_72 * V_73 , const char T_5 * V_74 ,
T_6 V_75 , T_7 * V_76 )
{
T_3 V_80 ;
int V_83 ;
V_83 = F_46 ( V_74 , V_75 , 10 , & V_80 ) ;
if ( V_83 )
return V_83 ;
F_34 ( & V_44 . V_65 ) ;
if ( V_44 . V_45 < V_80 )
V_44 . V_66 = V_80 ;
else
V_83 = - V_84 ;
F_35 ( & V_44 . V_65 ) ;
if ( V_83 )
return V_83 ;
return V_75 ;
}
static int F_48 ( void )
{
struct V_85 * V_86 ;
struct V_85 * V_87 ;
V_86 = F_49 () ;
if ( F_39 ( V_86 ) )
return - V_70 ;
V_87 = F_50 ( L_6 , V_86 ) ;
if ( ! V_87 )
return - V_70 ;
V_88 = F_51 ( L_7 , 0640 ,
V_87 ,
& V_44 . V_66 ,
& V_89 ) ;
if ( ! V_88 )
goto V_83;
V_90 = F_51 ( L_8 , 0644 ,
V_87 ,
& V_44 . V_45 ,
& V_91 ) ;
if ( ! V_90 )
goto V_83;
return 0 ;
V_83:
F_52 ( V_87 ) ;
return - V_70 ;
}
static void F_53 ( struct V_3 * V_4 )
{
int V_83 ;
V_83 = F_37 ( V_4 ) ;
if ( V_83 )
F_19 ( V_42 L_9 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_41 () ;
}
static int F_55 ( struct V_3 * V_4 )
{
if ( V_92 )
return - V_93 ;
V_5 = V_4 ;
V_54 = false ;
V_44 . V_47 = 0 ;
V_4 -> V_49 = 0 ;
V_94 = V_37 ;
if ( ! V_37 )
V_37 = V_95 ;
if ( F_56 ( V_4 ) )
F_53 ( V_4 ) ;
V_92 = true ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_41 () ;
V_95 = V_37 ;
V_37 = V_94 ;
V_92 = false ;
}
T_8 static int F_58 ( void )
{
int V_39 ;
F_59 ( & V_44 . V_65 ) ;
V_39 = F_60 ( & V_96 ) ;
if ( V_39 )
return V_39 ;
F_48 () ;
return 0 ;
}
