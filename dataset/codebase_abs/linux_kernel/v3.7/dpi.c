static struct V_1 * F_1 ( enum V_2 V_3 )
{
int V_4 ;
V_4 = V_3 == V_5 ? 0 : 1 ;
return F_2 ( V_4 ) ;
}
static bool F_3 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 . V_10 ==
V_5 ||
V_7 -> V_8 . V_9 . V_10 ==
V_11 ||
V_7 -> V_8 . V_9 . V_12 . V_13 ==
V_5 ||
V_7 -> V_8 . V_9 . V_12 . V_13 ==
V_11 )
return true ;
else
return false ;
}
static int F_4 ( struct V_6 * V_7 ,
unsigned long V_14 , unsigned long * V_15 , int * V_16 ,
int * V_17 )
{
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 ;
V_22 = F_5 ( V_23 . V_24 , V_14 , & V_19 ,
& V_21 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_6 ( V_23 . V_24 , & V_19 ) ;
if ( V_22 )
return V_22 ;
F_7 ( V_7 -> V_8 . V_9 . V_10 ) ;
V_23 . V_25 . V_26 = V_21 ;
* V_15 = V_19 . V_27 ;
* V_16 = V_21 . V_16 ;
* V_17 = V_21 . V_17 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned long V_14 , unsigned long * V_15 , int * V_16 ,
int * V_17 )
{
struct V_28 V_29 ;
struct V_20 V_21 ;
int V_22 ;
V_22 = F_9 ( V_14 , & V_29 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_10 ( & V_29 ) ;
if ( V_22 )
return V_22 ;
V_23 . V_25 . V_26 = V_21 ;
* V_15 = V_29 . V_15 ;
* V_16 = V_21 . V_16 ;
* V_17 = V_21 . V_17 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = & V_23 . V_32 ;
struct V_33 * V_34 = V_7 -> V_35 -> V_36 ;
int V_16 = 0 , V_17 = 0 ;
unsigned long V_15 = 0 ;
unsigned long V_37 ;
int V_22 = 0 ;
if ( F_3 ( V_7 ) )
V_22 = F_4 ( V_7 , V_31 -> V_38 * 1000 , & V_15 ,
& V_16 , & V_17 ) ;
else
V_22 = F_8 ( V_7 , V_31 -> V_38 * 1000 , & V_15 ,
& V_16 , & V_17 ) ;
if ( V_22 )
return V_22 ;
V_37 = V_15 / V_16 / V_17 / 1000 ;
if ( V_37 != V_31 -> V_38 ) {
F_12 ( L_1
L_2 ,
V_31 -> V_38 , V_37 ) ;
V_31 -> V_38 = V_37 ;
}
F_13 ( V_34 , V_31 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_35 -> V_36 ;
V_23 . V_25 . V_39 = V_40 ;
V_23 . V_25 . V_41 = false ;
V_23 . V_25 . V_42 = false ;
V_23 . V_25 . V_43 = V_23 . V_44 ;
V_23 . V_25 . V_45 = 0 ;
F_15 ( V_34 , & V_23 . V_25 ) ;
}
int F_16 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_35 ;
int V_22 ;
F_17 ( & V_23 . V_48 ) ;
if ( F_18 ( V_49 ) && ! V_23 . V_50 ) {
F_19 ( L_3 ) ;
V_22 = - V_51 ;
goto V_52;
}
if ( V_47 == NULL || V_47 -> V_36 == NULL ) {
F_19 ( L_4 ) ;
V_22 = - V_51 ;
goto V_53;
}
V_22 = F_20 ( V_7 ) ;
if ( V_22 ) {
F_19 ( L_5 ) ;
goto V_54;
}
if ( F_18 ( V_49 ) ) {
V_22 = F_21 ( V_23 . V_50 ) ;
if ( V_22 )
goto V_55;
}
V_22 = F_22 () ;
if ( V_22 )
goto V_56;
V_22 = F_23 ( V_7 -> V_12 ) ;
if ( V_22 )
goto V_57;
if ( F_3 ( V_7 ) ) {
V_22 = F_24 ( V_23 . V_24 ) ;
if ( V_22 )
goto V_58;
V_22 = F_25 ( V_23 . V_24 , 0 , 1 ) ;
if ( V_22 )
goto V_59;
}
V_22 = F_11 ( V_7 ) ;
if ( V_22 )
goto V_60;
F_14 ( V_7 ) ;
F_26 ( 2 ) ;
V_22 = F_27 ( V_47 -> V_36 ) ;
if ( V_22 )
goto V_61;
F_28 ( & V_23 . V_48 ) ;
return 0 ;
V_61:
V_60:
if ( F_3 ( V_7 ) )
F_29 ( V_23 . V_24 , true ) ;
V_59:
if ( F_3 ( V_7 ) )
F_30 ( V_23 . V_24 ) ;
V_58:
V_57:
F_31 () ;
V_56:
if ( F_18 ( V_49 ) )
F_32 ( V_23 . V_50 ) ;
V_55:
F_33 ( V_7 ) ;
V_54:
V_53:
V_52:
F_28 ( & V_23 . V_48 ) ;
return V_22 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_35 -> V_36 ;
F_17 ( & V_23 . V_48 ) ;
F_35 ( V_34 ) ;
if ( F_3 ( V_7 ) ) {
F_7 ( V_62 ) ;
F_29 ( V_23 . V_24 , true ) ;
F_30 ( V_23 . V_24 ) ;
}
F_31 () ;
if ( F_18 ( V_49 ) )
F_32 ( V_23 . V_50 ) ;
F_33 ( V_7 ) ;
F_28 ( & V_23 . V_48 ) ;
}
void F_36 ( struct V_6 * V_7 ,
struct V_30 * V_32 )
{
F_37 ( L_6 ) ;
F_17 ( & V_23 . V_48 ) ;
V_23 . V_32 = * V_32 ;
F_28 ( & V_23 . V_48 ) ;
}
int F_38 ( struct V_6 * V_7 ,
struct V_30 * V_32 )
{
int V_22 ;
struct V_33 * V_34 = V_7 -> V_35 -> V_36 ;
int V_16 , V_17 ;
unsigned long V_15 ;
unsigned long V_37 ;
struct V_20 V_21 ;
if ( F_39 ( V_34 , V_32 ) )
return - V_63 ;
if ( V_32 -> V_38 == 0 )
return - V_63 ;
if ( F_3 ( V_7 ) ) {
struct V_18 V_19 ;
V_22 = F_5 ( V_23 . V_24 ,
V_32 -> V_38 * 1000 ,
& V_19 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_15 = V_19 . V_27 ;
} else {
struct V_28 V_29 ;
V_22 = F_9 ( V_32 -> V_38 * 1000 ,
& V_29 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_15 = V_29 . V_15 ;
}
V_16 = V_21 . V_16 ;
V_17 = V_21 . V_17 ;
V_37 = V_15 / V_16 / V_17 / 1000 ;
V_32 -> V_38 = V_37 ;
return 0 ;
}
void F_40 ( struct V_6 * V_7 , int V_44 )
{
F_17 ( & V_23 . V_48 ) ;
V_23 . V_44 = V_44 ;
F_28 ( & V_23 . V_48 ) ;
}
static int T_1 F_41 ( struct V_6 * V_7 )
{
F_37 ( L_7 ) ;
if ( F_18 ( V_49 ) &&
V_23 . V_50 == NULL ) {
struct V_64 * V_65 ;
V_65 = F_42 () ;
if ( F_43 ( V_65 ) ) {
F_19 ( L_8 ) ;
return F_44 ( V_65 ) ;
}
V_23 . V_50 = V_65 ;
}
if ( F_3 ( V_7 ) ) {
enum V_2 V_10 =
V_7 -> V_8 . V_9 . V_10 ;
V_23 . V_24 = F_1 ( V_10 ) ;
}
return 0 ;
}
static struct V_6 * T_1 F_45 ( struct V_1 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 . V_70 ;
const char * V_71 = F_46 () ;
struct V_6 * V_72 ;
int V_73 ;
V_72 = NULL ;
for ( V_73 = 0 ; V_73 < V_68 -> V_74 ; ++ V_73 ) {
struct V_6 * V_7 = V_68 -> V_75 [ V_73 ] ;
if ( V_7 -> type != V_76 )
continue;
if ( V_72 == NULL )
V_72 = V_7 ;
if ( V_71 != NULL &&
strcmp ( V_7 -> V_77 , V_71 ) == 0 ) {
V_72 = V_7 ;
break;
}
}
return V_72 ;
}
static void T_1 F_47 ( struct V_1 * V_78 )
{
struct V_6 * V_79 ;
struct V_6 * V_7 ;
int V_22 ;
V_79 = F_45 ( V_78 ) ;
if ( ! V_79 )
return;
V_7 = F_48 ( & V_78 -> V_69 ) ;
if ( ! V_7 )
return;
F_49 ( V_7 , V_79 ) ;
V_22 = F_41 ( V_7 ) ;
if ( V_22 ) {
F_19 ( L_9 , V_7 -> V_77 , V_22 ) ;
F_50 ( V_7 ) ;
return;
}
V_22 = F_51 ( V_7 ) ;
if ( V_22 ) {
F_19 ( L_10 , V_7 -> V_77 , V_22 ) ;
F_50 ( V_7 ) ;
return;
}
}
static void T_1 F_52 ( struct V_1 * V_66 )
{
struct V_46 * V_47 = & V_23 . V_35 ;
V_47 -> V_66 = V_66 ;
V_47 -> V_80 = V_81 ;
V_47 -> type = V_76 ;
F_53 ( V_47 ) ;
}
static void T_2 F_54 ( struct V_1 * V_66 )
{
struct V_46 * V_47 = & V_23 . V_35 ;
F_55 ( V_47 ) ;
}
static int T_1 F_56 ( struct V_1 * V_66 )
{
F_57 ( & V_23 . V_48 ) ;
F_52 ( V_66 ) ;
F_47 ( V_66 ) ;
return 0 ;
}
static int T_2 F_58 ( struct V_1 * V_66 )
{
F_59 ( & V_66 -> V_69 ) ;
F_54 ( V_66 ) ;
return 0 ;
}
int T_1 F_60 ( void )
{
return F_61 ( & V_82 , F_56 ) ;
}
void T_2 F_62 ( void )
{
F_63 ( & V_82 ) ;
}
