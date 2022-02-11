static bool F_1 ( int V_1 , int V_2 , unsigned long V_3 ,
unsigned long V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
V_7 -> V_8 . V_9 = V_1 ;
V_7 -> V_8 . V_10 = V_2 ;
V_7 -> V_8 . V_3 = V_3 ;
V_7 -> V_8 . V_4 = V_4 ;
return true ;
}
static bool F_2 ( unsigned long V_11 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
V_7 -> V_11 = V_11 ;
return F_3 ( V_11 , V_7 -> V_12 , V_7 -> V_13 ,
F_1 , V_7 ) ;
}
static int F_4 ( unsigned long V_14 ,
unsigned long * V_11 ,
struct V_15 * V_8 )
{
int V_16 ;
struct V_6 V_7 ;
for ( V_16 = 0 ; V_16 < 10 ; ++ V_16 ) {
bool V_17 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
if ( V_14 > 1000 * V_16 * V_16 * V_16 )
V_7 . V_12 = F_5 ( V_14 - 1000 * V_16 * V_16 * V_16 , 0lu ) ;
else
V_7 . V_12 = 0 ;
V_7 . V_13 = V_14 + 1000 * V_16 * V_16 * V_16 ;
V_17 = F_6 ( V_14 , V_7 . V_12 , F_2 , & V_7 ) ;
if ( V_17 ) {
* V_11 = V_7 . V_11 ;
* V_8 = V_7 . V_8 ;
return 0 ;
}
}
return - V_18 ;
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_23 . V_24 . V_25 ;
V_23 . V_26 . V_27 = V_28 ;
V_23 . V_26 . V_29 = false ;
V_23 . V_26 . V_30 = false ;
V_23 . V_26 . V_31 = 24 ;
V_23 . V_26 . V_32 = 1 ;
F_8 ( V_22 , & V_23 . V_26 ) ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_19 * V_33 = & V_23 . V_24 ;
struct V_34 * V_35 = & V_23 . V_36 ;
unsigned long V_11 ;
struct V_15 V_8 ;
unsigned long V_4 ;
int V_37 ;
if ( V_33 == NULL || V_33 -> V_25 == NULL ) {
F_10 ( L_1 ) ;
return - V_38 ;
}
V_37 = F_11 ( V_23 . V_39 ) ;
if ( V_37 )
goto V_40;
V_37 = F_12 () ;
if ( V_37 )
goto V_41;
V_35 -> V_42 = V_43 ;
V_35 -> V_44 = V_43 ;
V_37 = F_4 ( V_35 -> V_45 , & V_11 , & V_8 ) ;
if ( V_37 )
goto V_46;
V_23 . V_26 . V_47 = V_8 ;
V_4 = V_11 / V_8 . V_9 / V_8 . V_10 ;
if ( V_4 != V_35 -> V_45 ) {
F_13 ( L_2 ,
V_35 -> V_45 , V_4 ) ;
V_35 -> V_45 = V_4 ;
}
F_14 ( V_33 -> V_25 , V_35 ) ;
V_37 = F_15 ( V_11 ) ;
if ( V_37 )
goto V_48;
F_7 ( V_20 ) ;
F_16 ( V_33 -> V_25 -> V_49 , & V_23 . V_26 . V_47 ) ;
F_17 ( V_23 . V_50 ) ;
V_37 = F_18 () ;
if ( V_37 )
goto V_51;
F_19 ( 2 ) ;
V_37 = F_20 ( V_33 -> V_25 ) ;
if ( V_37 )
goto V_52;
return 0 ;
V_52:
F_21 () ;
V_51:
V_48:
V_46:
F_22 () ;
V_41:
F_23 ( V_23 . V_39 ) ;
V_40:
return V_37 ;
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_23 . V_24 . V_25 ;
F_25 ( V_22 ) ;
F_21 () ;
F_22 () ;
F_23 ( V_23 . V_39 ) ;
}
static void F_26 ( struct V_19 * V_20 ,
struct V_34 * V_36 )
{
V_23 . V_36 = * V_36 ;
}
static void F_27 ( struct V_19 * V_20 ,
struct V_34 * V_36 )
{
* V_36 = V_23 . V_36 ;
}
static int F_28 ( struct V_19 * V_20 ,
struct V_34 * V_36 )
{
struct V_21 * V_22 = V_23 . V_24 . V_25 ;
if ( V_22 && ! F_29 ( V_22 -> V_49 , V_36 ) )
return - V_18 ;
if ( V_36 -> V_45 == 0 )
return - V_18 ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 , int V_50 )
{
V_23 . V_50 = V_50 ;
}
static int F_31 ( void )
{
struct V_53 * V_54 ;
if ( V_23 . V_39 )
return 0 ;
V_54 = F_32 ( & V_23 . V_55 -> V_56 , L_3 ) ;
if ( F_33 ( V_54 ) ) {
if ( F_34 ( V_54 ) != - V_57 )
F_10 ( L_4 ) ;
return F_34 ( V_54 ) ;
}
V_23 . V_39 = V_54 ;
return 0 ;
}
static int F_35 ( struct V_19 * V_20 ,
struct V_19 * V_58 )
{
struct V_21 * V_22 ;
int V_37 ;
V_37 = F_31 () ;
if ( V_37 )
return V_37 ;
V_22 = F_36 ( V_20 -> V_59 ) ;
if ( ! V_22 )
return - V_38 ;
V_37 = F_37 ( V_22 , V_20 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_38 ( V_20 , V_58 ) ;
if ( V_37 ) {
F_10 ( L_5 ,
V_58 -> V_60 ) ;
F_39 ( V_22 , V_20 ) ;
return V_37 ;
}
return 0 ;
}
static void F_40 ( struct V_19 * V_20 ,
struct V_19 * V_58 )
{
F_41 ( V_58 != V_20 -> V_58 ) ;
if ( V_58 != V_20 -> V_58 )
return;
F_42 ( V_20 ) ;
if ( V_20 -> V_25 )
F_39 ( V_20 -> V_25 , V_20 ) ;
}
static void F_43 ( struct V_61 * V_55 )
{
struct V_19 * V_33 = & V_23 . V_24 ;
V_33 -> V_56 = & V_55 -> V_56 ;
V_33 -> V_49 = V_62 ;
V_33 -> V_63 = V_64 ;
V_33 -> V_60 = L_6 ;
V_33 -> V_59 = V_65 ;
V_33 -> V_66 = 1 ;
V_33 -> V_67 . V_23 = & V_68 ;
V_33 -> V_69 = V_70 ;
F_44 ( V_33 ) ;
}
static void T_1 F_45 ( struct V_61 * V_55 )
{
struct V_19 * V_33 = & V_23 . V_24 ;
F_46 ( V_33 ) ;
}
static int F_47 ( struct V_61 * V_55 )
{
V_23 . V_55 = V_55 ;
F_43 ( V_55 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_61 * V_55 )
{
F_45 ( V_55 ) ;
return 0 ;
}
int T_2 F_49 ( void )
{
return F_50 ( & V_71 ) ;
}
void T_1 F_51 ( void )
{
F_52 ( & V_71 ) ;
}
int T_2 F_53 ( struct V_61 * V_55 , struct V_72 * V_73 )
{
struct V_72 * V_74 ;
T_3 V_50 ;
int V_37 ;
V_74 = F_54 ( V_73 , NULL ) ;
if ( ! V_74 )
return 0 ;
V_37 = F_55 ( V_74 , L_7 , & V_50 ) ;
if ( V_37 ) {
F_10 ( L_8 ) ;
goto V_75;
}
V_23 . V_50 = V_50 ;
F_56 ( V_74 ) ;
V_23 . V_55 = V_55 ;
F_43 ( V_55 ) ;
V_23 . V_76 = true ;
return 0 ;
V_75:
F_56 ( V_74 ) ;
return V_37 ;
}
void T_1 F_57 ( struct V_72 * V_73 )
{
if ( ! V_23 . V_76 )
return;
F_45 ( V_23 . V_55 ) ;
}
