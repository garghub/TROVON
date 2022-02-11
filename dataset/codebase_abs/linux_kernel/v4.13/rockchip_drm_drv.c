int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_8 = F_2 ( V_6 -> V_10 , V_4 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_1 ) ;
return V_8 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_10 = V_6 -> V_10 ;
if ( ! V_9 )
return;
F_5 ( V_10 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_12 * V_13 ;
T_1 V_14 , V_15 ;
if ( ! V_9 )
return 0 ;
V_6 -> V_10 = F_7 ( & V_16 ) ;
if ( ! V_6 -> V_10 )
return - V_17 ;
V_13 = & V_6 -> V_10 -> V_13 ;
V_14 = V_13 -> V_18 ;
V_15 = V_13 -> V_19 ;
F_8 ( L_2 ,
V_14 , V_15 ) ;
F_9 ( & V_6 -> V_20 , V_14 , V_15 - V_14 + 1 ) ;
F_10 ( & V_6 -> V_21 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_9 )
return;
F_12 ( & V_6 -> V_20 ) ;
F_13 ( V_6 -> V_10 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_8 ;
V_2 = F_15 ( & V_22 , V_4 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
F_18 ( V_4 , V_2 ) ;
V_6 = F_19 ( V_2 -> V_4 , sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 ) {
V_8 = - V_17 ;
goto V_24;
}
V_2 -> V_7 = V_6 ;
F_20 ( & V_6 -> V_25 ) ;
F_21 ( & V_6 -> V_26 ) ;
V_8 = F_6 ( V_2 ) ;
if ( V_8 )
goto V_24;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
V_8 = F_24 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_27;
V_8 = F_25 ( V_2 , V_2 -> V_28 . V_29 ) ;
if ( V_8 )
goto V_30;
F_26 ( V_2 ) ;
V_2 -> V_31 = true ;
F_27 ( V_2 ) ;
V_8 = F_28 ( V_2 ) ;
if ( V_8 )
goto V_32;
V_8 = F_29 ( V_2 , 0 ) ;
if ( V_8 )
goto V_33;
return 0 ;
V_33:
F_30 ( V_2 ) ;
V_32:
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
V_30:
F_33 ( V_4 , V_2 ) ;
V_27:
F_34 ( V_2 ) ;
F_11 ( V_2 ) ;
V_24:
V_2 -> V_7 = NULL ;
F_18 ( V_4 , NULL ) ;
F_35 ( V_2 ) ;
return V_8 ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_37 ( V_4 ) ;
F_38 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_39 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_4 , V_2 ) ;
F_34 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_7 = NULL ;
F_18 ( V_4 , NULL ) ;
F_35 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_4 )
{
struct V_5 * V_34 = V_4 -> V_7 ;
F_41 ( & V_34 -> V_35 ) ;
}
static void F_42 ( struct V_1 * V_36 )
{
struct V_5 * V_34 = V_36 -> V_7 ;
F_43 () ;
F_44 ( & V_34 -> V_35 , 1 ) ;
F_45 () ;
}
static void F_46 ( struct V_1 * V_36 )
{
struct V_5 * V_34 = V_36 -> V_7 ;
F_43 () ;
F_44 ( & V_34 -> V_35 , 0 ) ;
F_45 () ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_36 = F_37 ( V_4 ) ;
struct V_5 * V_34 ;
if ( ! V_36 )
return 0 ;
F_48 ( V_36 ) ;
F_42 ( V_36 ) ;
V_34 = V_36 -> V_7 ;
V_34 -> V_37 = F_49 ( V_36 ) ;
if ( F_16 ( V_34 -> V_37 ) ) {
F_46 ( V_36 ) ;
F_50 ( V_36 ) ;
return F_17 ( V_34 -> V_37 ) ;
}
return 0 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_36 = F_37 ( V_4 ) ;
struct V_5 * V_34 ;
if ( ! V_36 )
return 0 ;
V_34 = V_36 -> V_7 ;
F_52 ( V_36 , V_34 -> V_37 ) ;
F_46 ( V_36 ) ;
F_50 ( V_36 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 , void * V_38 )
{
return V_4 == (struct V_3 * ) V_38 ;
}
static struct V_39 * F_54 ( struct V_3 * V_4 )
{
struct V_39 * V_40 = NULL ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
struct V_43 * V_44 = V_45 [ V_41 ] ;
struct V_3 * V_46 = NULL , * V_47 ;
do {
V_47 = F_55 ( & V_16 , V_46 , & V_44 -> V_48 ,
( void * ) V_16 . V_40 ) ;
F_56 ( V_46 ) ;
V_46 = V_47 ;
if ( ! V_47 )
break;
F_57 ( V_4 , & V_40 , F_53 , V_47 ) ;
} while ( true );
}
return V_40 ? : F_58 ( - V_49 ) ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_50 * V_51 = V_4 -> V_52 ;
struct V_50 * V_53 ;
bool V_54 = false ;
int V_41 ;
if ( ! V_51 )
return - V_49 ;
for ( V_41 = 0 ; ; V_41 ++ ) {
struct V_50 * V_55 ;
V_53 = F_60 ( V_51 , L_3 , V_41 ) ;
if ( ! V_53 )
break;
if ( ! F_61 ( V_53 -> V_56 ) ) {
F_62 ( V_53 ) ;
continue;
}
V_55 = F_60 ( V_53 -> V_56 , L_4 , 0 ) ;
if ( ! V_55 || ! F_61 ( V_55 -> V_56 ) ) {
F_63 ( V_4 , L_5 ,
V_53 -> V_56 -> V_57 ) ;
V_9 = false ;
}
V_54 = true ;
F_62 ( V_55 ) ;
F_62 ( V_53 ) ;
}
if ( V_41 == 0 ) {
F_3 ( V_4 , L_6 ) ;
return - V_49 ;
}
if ( ! V_54 ) {
F_3 ( V_4 , L_7 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_64 ( struct V_58 * V_59 )
{
struct V_3 * V_4 = & V_59 -> V_4 ;
struct V_39 * V_40 = NULL ;
int V_8 ;
V_8 = F_59 ( V_4 ) ;
if ( V_8 )
return V_8 ;
V_40 = F_54 ( V_4 ) ;
if ( F_16 ( V_40 ) )
return F_17 ( V_40 ) ;
return F_65 ( V_4 , & V_60 , V_40 ) ;
}
static int F_66 ( struct V_58 * V_59 )
{
F_67 ( & V_59 -> V_4 , & V_60 ) ;
return 0 ;
}
static int T_2 F_68 ( void )
{
int V_8 ;
V_42 = 0 ;
F_69 ( V_61 , V_62 ) ;
F_69 ( V_63 ,
V_64 ) ;
F_69 ( V_65 , V_66 ) ;
F_69 ( V_67 ,
V_68 ) ;
F_69 ( V_69 ,
V_70 ) ;
F_69 ( V_71 , V_72 ) ;
V_8 = F_70 ( V_45 ,
V_42 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_71 ( & V_73 ) ;
if ( V_8 )
goto V_74;
return 0 ;
V_74:
F_72 ( V_45 ,
V_42 ) ;
return V_8 ;
}
static void T_3 F_73 ( void )
{
F_74 ( & V_73 ) ;
F_72 ( V_45 ,
V_42 ) ;
}
