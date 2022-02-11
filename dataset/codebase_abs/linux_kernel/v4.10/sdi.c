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
enum V_21 V_22 = V_20 -> V_23 ;
V_24 . V_25 . V_26 = V_27 ;
V_24 . V_25 . V_28 = false ;
V_24 . V_25 . V_29 = false ;
V_24 . V_25 . V_30 = 24 ;
V_24 . V_25 . V_31 = 1 ;
F_8 ( V_22 , & V_24 . V_25 ) ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_19 * V_32 = & V_24 . V_33 ;
enum V_21 V_22 = V_20 -> V_23 ;
struct V_34 * V_35 = & V_24 . V_35 ;
unsigned long V_11 ;
struct V_15 V_8 ;
unsigned long V_4 ;
int V_36 ;
if ( ! V_32 -> V_37 ) {
F_10 ( L_1 ) ;
return - V_38 ;
}
V_36 = F_11 ( V_24 . V_39 ) ;
if ( V_36 )
goto V_40;
V_36 = F_12 () ;
if ( V_36 )
goto V_41;
V_35 -> V_42 |= V_43 | V_44 ;
V_36 = F_4 ( V_35 -> V_45 , & V_11 , & V_8 ) ;
if ( V_36 )
goto V_46;
V_24 . V_25 . V_47 = V_8 ;
V_4 = V_11 / V_8 . V_9 / V_8 . V_10 ;
if ( V_4 != V_35 -> V_45 ) {
F_13 ( L_2 ,
V_35 -> V_45 , V_4 ) ;
V_35 -> V_45 = V_4 ;
}
F_14 ( V_22 , V_35 ) ;
V_36 = F_15 ( V_11 ) ;
if ( V_36 )
goto V_48;
F_7 ( V_20 ) ;
F_16 ( V_22 , & V_24 . V_25 . V_47 ) ;
F_17 ( V_24 . V_49 ) ;
V_36 = F_18 () ;
if ( V_36 )
goto V_50;
F_19 ( 2 ) ;
V_36 = F_20 ( V_22 ) ;
if ( V_36 )
goto V_51;
return 0 ;
V_51:
F_21 () ;
V_50:
V_48:
V_46:
F_22 () ;
V_41:
F_23 ( V_24 . V_39 ) ;
V_40:
return V_36 ;
}
static void F_24 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_20 -> V_23 ;
F_25 ( V_22 ) ;
F_21 () ;
F_22 () ;
F_23 ( V_24 . V_39 ) ;
}
static void F_26 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
V_24 . V_35 = * V_35 ;
}
static void F_27 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
* V_35 = V_24 . V_35 ;
}
static int F_28 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
enum V_21 V_22 = V_20 -> V_23 ;
if ( ! F_29 ( V_22 , V_35 ) )
return - V_18 ;
if ( V_35 -> V_45 == 0 )
return - V_18 ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 , int V_49 )
{
V_24 . V_49 = V_49 ;
}
static int F_31 ( void )
{
struct V_52 * V_53 ;
if ( V_24 . V_39 )
return 0 ;
V_53 = F_32 ( & V_24 . V_54 -> V_55 , L_3 ) ;
if ( F_33 ( V_53 ) ) {
if ( F_34 ( V_53 ) != - V_56 )
F_10 ( L_4 ) ;
return F_34 ( V_53 ) ;
}
V_24 . V_39 = V_53 ;
return 0 ;
}
static int F_35 ( struct V_19 * V_20 ,
struct V_19 * V_57 )
{
enum V_21 V_22 = V_20 -> V_23 ;
int V_36 ;
V_36 = F_31 () ;
if ( V_36 )
return V_36 ;
V_36 = F_36 ( V_22 , V_20 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_37 ( V_20 , V_57 ) ;
if ( V_36 ) {
F_10 ( L_5 ,
V_57 -> V_58 ) ;
F_38 ( V_22 , V_20 ) ;
return V_36 ;
}
return 0 ;
}
static void F_39 ( struct V_19 * V_20 ,
struct V_19 * V_57 )
{
enum V_21 V_22 = V_20 -> V_23 ;
F_40 ( V_57 != V_20 -> V_57 ) ;
if ( V_57 != V_20 -> V_57 )
return;
F_41 ( V_20 ) ;
F_38 ( V_22 , V_20 ) ;
}
static void F_42 ( struct V_59 * V_54 )
{
struct V_19 * V_32 = & V_24 . V_33 ;
V_32 -> V_55 = & V_54 -> V_55 ;
V_32 -> V_60 = V_61 ;
V_32 -> V_62 = V_63 ;
V_32 -> V_58 = L_6 ;
V_32 -> V_23 = V_64 ;
V_32 -> V_65 = 1 ;
V_32 -> V_66 . V_24 = & V_67 ;
V_32 -> V_68 = V_69 ;
F_43 ( V_32 ) ;
}
static void F_44 ( struct V_59 * V_54 )
{
struct V_19 * V_32 = & V_24 . V_33 ;
F_45 ( V_32 ) ;
}
static int F_46 ( struct V_70 * V_55 , struct V_70 * V_71 , void * V_5 )
{
struct V_59 * V_54 = F_47 ( V_55 ) ;
V_24 . V_54 = V_54 ;
F_42 ( V_54 ) ;
return 0 ;
}
static void F_48 ( struct V_70 * V_55 , struct V_70 * V_71 , void * V_5 )
{
struct V_59 * V_54 = F_47 ( V_55 ) ;
F_44 ( V_54 ) ;
}
static int F_49 ( struct V_59 * V_54 )
{
return F_50 ( & V_54 -> V_55 , & V_72 ) ;
}
static int F_51 ( struct V_59 * V_54 )
{
F_52 ( & V_54 -> V_55 , & V_72 ) ;
return 0 ;
}
int T_1 F_53 ( void )
{
return F_54 ( & V_73 ) ;
}
void F_55 ( void )
{
F_56 ( & V_73 ) ;
}
int F_57 ( struct V_59 * V_54 , struct V_74 * V_75 )
{
struct V_74 * V_76 ;
T_2 V_49 ;
int V_36 ;
V_76 = F_58 ( V_75 , NULL ) ;
if ( ! V_76 )
return 0 ;
V_36 = F_59 ( V_76 , L_7 , & V_49 ) ;
if ( V_36 ) {
F_10 ( L_8 ) ;
goto V_77;
}
V_24 . V_49 = V_49 ;
F_60 ( V_76 ) ;
V_24 . V_54 = V_54 ;
F_42 ( V_54 ) ;
V_24 . V_78 = true ;
return 0 ;
V_77:
F_60 ( V_76 ) ;
return V_36 ;
}
void F_61 ( struct V_74 * V_75 )
{
if ( ! V_24 . V_78 )
return;
F_44 ( V_24 . V_54 ) ;
}
