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
V_8 = F_27 ( V_2 ) ;
if ( V_8 )
goto V_30;
F_28 ( V_2 ) ;
V_8 = F_29 ( V_2 , 0 ) ;
if ( V_8 )
goto V_32;
return 0 ;
V_32:
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
V_30:
F_32 ( V_4 , V_2 ) ;
V_27:
F_33 ( V_2 ) ;
F_11 ( V_2 ) ;
V_24:
V_2 -> V_7 = NULL ;
F_18 ( V_4 , NULL ) ;
F_34 ( V_2 ) ;
return V_8 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_37 ( V_2 ) ;
F_31 ( V_2 ) ;
F_30 ( V_2 ) ;
F_38 ( V_2 ) ;
F_32 ( V_4 , V_2 ) ;
F_33 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_7 = NULL ;
F_18 ( V_4 , NULL ) ;
F_34 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_4 )
{
struct V_5 * V_33 = V_4 -> V_7 ;
F_40 ( & V_33 -> V_34 ) ;
}
static void F_41 ( struct V_1 * V_35 )
{
struct V_5 * V_33 = V_35 -> V_7 ;
F_42 () ;
F_43 ( & V_33 -> V_34 , 1 ) ;
F_44 () ;
}
static void F_45 ( struct V_1 * V_35 )
{
struct V_5 * V_33 = V_35 -> V_7 ;
F_42 () ;
F_43 ( & V_33 -> V_34 , 0 ) ;
F_44 () ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_35 = F_36 ( V_4 ) ;
struct V_5 * V_33 ;
if ( ! V_35 )
return 0 ;
F_47 ( V_35 ) ;
F_41 ( V_35 ) ;
V_33 = V_35 -> V_7 ;
V_33 -> V_36 = F_48 ( V_35 ) ;
if ( F_16 ( V_33 -> V_36 ) ) {
F_45 ( V_35 ) ;
F_49 ( V_35 ) ;
return F_17 ( V_33 -> V_36 ) ;
}
return 0 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_35 = F_36 ( V_4 ) ;
struct V_5 * V_33 ;
if ( ! V_35 )
return 0 ;
V_33 = V_35 -> V_7 ;
F_51 ( V_35 , V_33 -> V_36 ) ;
F_45 ( V_35 ) ;
F_49 ( V_35 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 , void * V_37 )
{
return V_4 == (struct V_3 * ) V_37 ;
}
static struct V_38 * F_53 ( struct V_3 * V_4 )
{
struct V_38 * V_39 = NULL ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_42 * V_43 = V_44 [ V_40 ] ;
struct V_3 * V_45 = NULL , * V_46 ;
do {
V_46 = F_54 ( & V_16 , V_45 , & V_43 -> V_47 ,
( void * ) V_16 . V_39 ) ;
F_55 ( V_45 ) ;
V_45 = V_46 ;
if ( ! V_46 )
break;
F_56 ( V_4 , & V_39 , F_52 , V_46 ) ;
} while ( true );
}
return V_39 ? : F_57 ( - V_48 ) ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_49 * V_50 = V_4 -> V_51 ;
struct V_49 * V_52 ;
bool V_53 = false ;
int V_40 ;
if ( ! V_50 )
return - V_48 ;
for ( V_40 = 0 ; ; V_40 ++ ) {
struct V_49 * V_54 ;
V_52 = F_59 ( V_50 , L_3 , V_40 ) ;
if ( ! V_52 )
break;
if ( ! F_60 ( V_52 -> V_55 ) ) {
F_61 ( V_52 ) ;
continue;
}
V_54 = F_59 ( V_52 -> V_55 , L_4 , 0 ) ;
if ( ! V_54 || ! F_60 ( V_54 -> V_55 ) ) {
F_62 ( V_4 , L_5 ,
V_52 -> V_55 ) ;
V_9 = false ;
}
V_53 = true ;
F_61 ( V_54 ) ;
F_61 ( V_52 ) ;
}
if ( V_40 == 0 ) {
F_3 ( V_4 , L_6 ) ;
return - V_48 ;
}
if ( ! V_53 ) {
F_3 ( V_4 , L_7 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_63 ( struct V_56 * V_57 )
{
struct V_3 * V_4 = & V_57 -> V_4 ;
struct V_38 * V_39 = NULL ;
int V_8 ;
V_8 = F_58 ( V_4 ) ;
if ( V_8 )
return V_8 ;
V_39 = F_53 ( V_4 ) ;
if ( F_16 ( V_39 ) )
return F_17 ( V_39 ) ;
return F_64 ( V_4 , & V_58 , V_39 ) ;
}
static int F_65 ( struct V_56 * V_57 )
{
F_66 ( & V_57 -> V_4 , & V_58 ) ;
return 0 ;
}
static int T_2 F_67 ( void )
{
int V_8 ;
V_41 = 0 ;
F_68 ( V_59 , V_60 ) ;
F_68 ( V_61 ,
V_62 ) ;
F_68 ( V_63 , V_64 ) ;
F_68 ( V_65 ,
V_66 ) ;
F_68 ( V_67 ,
V_68 ) ;
F_68 ( V_69 , V_70 ) ;
V_8 = F_69 ( V_44 ,
V_41 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_70 ( & V_71 ) ;
if ( V_8 )
goto V_72;
return 0 ;
V_72:
F_71 ( V_44 ,
V_41 ) ;
return V_8 ;
}
static void T_3 F_72 ( void )
{
F_73 ( & V_71 ) ;
F_71 ( V_44 ,
V_41 ) ;
}
