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
static bool F_2 ( int V_11 , unsigned long V_12 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
V_7 -> V_13 . V_12 = V_12 ;
V_7 -> V_13 . V_14 = V_11 ;
return F_3 ( V_12 , V_7 -> V_15 , V_7 -> V_16 ,
F_1 , V_7 ) ;
}
static int F_4 ( unsigned long V_17 ,
struct V_18 * V_13 ,
struct V_19 * V_8 )
{
int V_20 ;
struct V_6 V_7 ;
for ( V_20 = 0 ; V_20 < 10 ; ++ V_20 ) {
bool V_21 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
if ( V_17 > 1000 * V_20 * V_20 * V_20 )
V_7 . V_15 = F_5 ( V_17 - 1000 * V_20 * V_20 * V_20 , 0lu ) ;
else
V_7 . V_15 = 0 ;
V_7 . V_16 = V_17 + 1000 * V_20 * V_20 * V_20 ;
V_21 = F_6 ( V_7 . V_15 , F_2 , & V_7 ) ;
if ( V_21 ) {
* V_13 = V_7 . V_13 ;
* V_8 = V_7 . V_8 ;
return 0 ;
}
}
return - V_22 ;
}
static void F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_27 . V_28 . V_29 ;
V_27 . V_30 . V_31 = V_32 ;
V_27 . V_30 . V_33 = false ;
V_27 . V_30 . V_34 = false ;
V_27 . V_30 . V_35 = 24 ;
V_27 . V_30 . V_36 = 1 ;
F_8 ( V_26 , & V_27 . V_30 ) ;
}
int F_9 ( struct V_23 * V_24 )
{
struct V_23 * V_37 = & V_27 . V_28 ;
struct V_38 * V_39 = & V_27 . V_40 ;
struct V_18 V_13 ;
struct V_19 V_8 ;
unsigned long V_4 ;
int V_41 ;
if ( V_37 == NULL || V_37 -> V_29 == NULL ) {
F_10 ( L_1 ) ;
return - V_42 ;
}
V_41 = F_11 ( V_27 . V_43 ) ;
if ( V_41 )
goto V_44;
V_41 = F_12 () ;
if ( V_41 )
goto V_45;
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = V_47 ;
V_41 = F_4 ( V_39 -> V_49 * 1000 , & V_13 , & V_8 ) ;
if ( V_41 )
goto V_50;
V_27 . V_30 . V_51 = V_8 ;
V_4 = V_13 . V_12 / V_8 . V_9 / V_8 . V_10 / 1000 ;
if ( V_4 != V_39 -> V_49 ) {
F_13 ( L_2
L_3 ,
V_39 -> V_49 , V_4 ) ;
V_39 -> V_49 = V_4 ;
}
F_14 ( V_37 -> V_29 , V_39 ) ;
V_41 = F_15 ( & V_13 ) ;
if ( V_41 )
goto V_52;
F_7 ( V_24 ) ;
F_16 ( V_37 -> V_29 -> V_53 , & V_27 . V_30 . V_51 ) ;
F_17 ( V_27 . V_54 ) ;
V_41 = F_18 () ;
if ( V_41 )
goto V_55;
F_19 ( 2 ) ;
V_41 = F_20 ( V_37 -> V_29 ) ;
if ( V_41 )
goto V_56;
return 0 ;
V_56:
F_21 () ;
V_55:
V_52:
V_50:
F_22 () ;
V_45:
F_23 ( V_27 . V_43 ) ;
V_44:
return V_41 ;
}
void F_24 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_27 . V_28 . V_29 ;
F_25 ( V_26 ) ;
F_21 () ;
F_22 () ;
F_23 ( V_27 . V_43 ) ;
}
void F_26 ( struct V_23 * V_24 ,
struct V_38 * V_40 )
{
V_27 . V_40 = * V_40 ;
}
static void F_27 ( struct V_23 * V_24 ,
struct V_38 * V_40 )
{
* V_40 = V_27 . V_40 ;
}
static int F_28 ( struct V_23 * V_24 ,
struct V_38 * V_40 )
{
struct V_25 * V_26 = V_27 . V_28 . V_29 ;
if ( V_26 && ! F_29 ( V_26 -> V_53 , V_40 ) )
return - V_22 ;
if ( V_40 -> V_49 == 0 )
return - V_22 ;
return 0 ;
}
void F_30 ( struct V_23 * V_24 , int V_54 )
{
V_27 . V_54 = V_54 ;
}
static int F_31 ( void )
{
struct V_57 * V_58 ;
if ( V_27 . V_43 )
return 0 ;
V_58 = F_32 () ;
if ( F_33 ( V_58 ) ) {
V_58 = F_34 ( & V_27 . V_59 -> V_60 , L_4 ) ;
if ( F_33 ( V_58 ) ) {
F_10 ( L_5 ) ;
return F_35 ( V_58 ) ;
}
}
V_27 . V_43 = V_58 ;
return 0 ;
}
static struct V_23 * F_36 ( struct V_61 * V_59 )
{
struct V_62 * V_63 = V_59 -> V_60 . V_64 ;
const char * V_65 = F_37 () ;
struct V_23 * V_66 ;
int V_20 ;
V_66 = NULL ;
for ( V_20 = 0 ; V_20 < V_63 -> V_67 ; ++ V_20 ) {
struct V_23 * V_24 = V_63 -> V_68 [ V_20 ] ;
if ( V_24 -> type != V_69 )
continue;
if ( V_66 == NULL )
V_66 = V_24 ;
if ( V_65 != NULL &&
strcmp ( V_24 -> V_70 , V_65 ) == 0 ) {
V_66 = V_24 ;
break;
}
}
return V_66 ;
}
static int F_38 ( struct V_61 * V_71 )
{
struct V_23 * V_72 ;
struct V_23 * V_24 ;
int V_41 ;
V_72 = F_36 ( V_71 ) ;
if ( ! V_72 )
return 0 ;
V_24 = F_39 ( & V_71 -> V_60 ) ;
if ( ! V_24 )
return - V_73 ;
F_40 ( V_24 , V_72 ) ;
V_41 = F_31 () ;
if ( V_41 ) {
F_10 ( L_6 , V_24 -> V_70 , V_41 ) ;
F_41 ( V_24 ) ;
return V_41 ;
}
V_41 = F_42 ( & V_27 . V_28 , V_24 ) ;
if ( V_41 ) {
F_10 ( L_7 ,
V_24 -> V_70 ) ;
F_41 ( V_24 ) ;
return V_41 ;
}
V_41 = F_43 ( V_24 ) ;
if ( V_41 ) {
F_10 ( L_8 , V_24 -> V_70 , V_41 ) ;
F_44 ( & V_27 . V_28 ) ;
F_41 ( V_24 ) ;
return V_41 ;
}
return 0 ;
}
static int F_45 ( struct V_23 * V_24 ,
struct V_23 * V_74 )
{
struct V_25 * V_26 ;
int V_41 ;
V_41 = F_31 () ;
if ( V_41 )
return V_41 ;
V_26 = F_46 ( V_24 -> V_75 ) ;
if ( ! V_26 )
return - V_42 ;
V_41 = F_47 ( V_26 , V_24 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_42 ( V_24 , V_74 ) ;
if ( V_41 ) {
F_10 ( L_7 ,
V_74 -> V_70 ) ;
F_48 ( V_26 , V_24 ) ;
return V_41 ;
}
return 0 ;
}
static void F_49 ( struct V_23 * V_24 ,
struct V_23 * V_74 )
{
F_50 ( V_74 != V_24 -> V_76 ) ;
if ( V_74 != V_24 -> V_76 )
return;
F_44 ( V_24 ) ;
if ( V_24 -> V_29 )
F_48 ( V_24 -> V_29 , V_24 ) ;
}
static void F_51 ( struct V_61 * V_59 )
{
struct V_23 * V_37 = & V_27 . V_28 ;
V_37 -> V_60 = & V_59 -> V_60 ;
V_37 -> V_53 = V_77 ;
V_37 -> V_78 = V_69 ;
V_37 -> V_70 = L_9 ;
V_37 -> V_75 = V_79 ;
V_37 -> V_80 . V_27 = & V_81 ;
V_37 -> V_82 = V_83 ;
F_52 ( V_37 ) ;
}
static void T_1 F_53 ( struct V_61 * V_59 )
{
struct V_23 * V_37 = & V_27 . V_28 ;
F_54 ( V_37 ) ;
}
static int F_55 ( struct V_61 * V_59 )
{
int V_41 ;
V_27 . V_59 = V_59 ;
F_51 ( V_59 ) ;
if ( V_59 -> V_60 . V_64 ) {
V_41 = F_38 ( V_59 ) ;
if ( V_41 )
goto V_84;
}
return 0 ;
V_84:
F_53 ( V_59 ) ;
return V_41 ;
}
static int T_1 F_56 ( struct V_61 * V_59 )
{
F_57 ( & V_59 -> V_60 ) ;
F_53 ( V_59 ) ;
return 0 ;
}
int T_2 F_58 ( void )
{
return F_59 ( & V_85 ) ;
}
void T_1 F_60 ( void )
{
F_61 ( & V_85 ) ;
}
