static struct V_1 * F_1 ( enum V_2 V_3 )
{
switch ( F_2 () ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return NULL ;
default:
break;
}
switch ( V_3 ) {
case V_9 :
return F_3 ( 0 ) ;
case V_10 :
return F_3 ( 1 ) ;
default:
return NULL ;
}
}
static enum V_11 F_4 ( enum V_2 V_3 )
{
switch ( V_3 ) {
case V_9 :
return V_12 ;
case V_10 :
return V_13 ;
default:
F_5 ( 1 ) ;
return V_14 ;
}
}
static int F_6 ( struct V_15 * V_16 ,
unsigned long V_17 , unsigned long * V_18 , int * V_19 ,
int * V_20 )
{
struct V_21 * V_22 = V_16 -> V_23 -> V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
int V_29 ;
V_29 = F_7 ( V_30 . V_31 , V_17 , & V_26 ,
& V_28 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_8 ( V_30 . V_31 , & V_26 ) ;
if ( V_29 )
return V_29 ;
F_9 ( V_22 -> V_32 ,
F_4 ( V_22 -> V_32 ) ) ;
V_30 . V_33 . V_34 = V_28 ;
* V_18 = V_26 . V_35 ;
* V_19 = V_28 . V_19 ;
* V_20 = V_28 . V_20 ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 ,
unsigned long V_17 , unsigned long * V_18 , int * V_19 ,
int * V_20 )
{
struct V_36 V_37 ;
struct V_27 V_28 ;
int V_29 ;
V_29 = F_11 ( V_17 , & V_37 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_12 ( & V_37 ) ;
if ( V_29 )
return V_29 ;
V_30 . V_33 . V_34 = V_28 ;
* V_18 = V_37 . V_18 ;
* V_19 = V_28 . V_19 ;
* V_20 = V_28 . V_20 ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_38 * V_39 = & V_30 . V_40 ;
struct V_21 * V_22 = V_16 -> V_23 -> V_24 ;
int V_19 = 0 , V_20 = 0 ;
unsigned long V_18 = 0 ;
unsigned long V_41 ;
int V_29 = 0 ;
if ( V_30 . V_31 )
V_29 = F_6 ( V_16 , V_39 -> V_42 * 1000 , & V_18 ,
& V_19 , & V_20 ) ;
else
V_29 = F_10 ( V_16 , V_39 -> V_42 * 1000 , & V_18 ,
& V_19 , & V_20 ) ;
if ( V_29 )
return V_29 ;
V_41 = V_18 / V_19 / V_20 / 1000 ;
if ( V_41 != V_39 -> V_42 ) {
F_14 ( L_1
L_2 ,
V_39 -> V_42 , V_41 ) ;
V_39 -> V_42 = V_41 ;
}
F_15 ( V_22 , V_39 ) ;
return 0 ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_16 -> V_23 -> V_24 ;
V_30 . V_33 . V_43 = V_44 ;
V_30 . V_33 . V_45 = false ;
V_30 . V_33 . V_46 = false ;
V_30 . V_33 . V_47 = V_30 . V_48 ;
V_30 . V_33 . V_49 = 0 ;
F_17 ( V_22 , & V_30 . V_33 ) ;
}
int F_18 ( struct V_15 * V_16 )
{
struct V_50 * V_51 = V_16 -> V_23 ;
int V_29 ;
F_19 ( & V_30 . V_52 ) ;
if ( F_20 ( V_53 ) && ! V_30 . V_54 ) {
F_21 ( L_3 ) ;
V_29 = - V_55 ;
goto V_56;
}
if ( V_51 == NULL || V_51 -> V_24 == NULL ) {
F_21 ( L_4 ) ;
V_29 = - V_55 ;
goto V_57;
}
V_29 = F_22 ( V_16 ) ;
if ( V_29 ) {
F_21 ( L_5 ) ;
goto V_58;
}
if ( F_20 ( V_53 ) ) {
V_29 = F_23 ( V_30 . V_54 ) ;
if ( V_29 )
goto V_59;
}
V_29 = F_24 () ;
if ( V_29 )
goto V_60;
V_29 = F_25 ( V_16 -> V_3 ) ;
if ( V_29 )
goto V_61;
if ( V_30 . V_31 ) {
V_29 = F_26 ( V_30 . V_31 ) ;
if ( V_29 )
goto V_62;
V_29 = F_27 ( V_30 . V_31 , 0 , 1 ) ;
if ( V_29 )
goto V_63;
}
V_29 = F_13 ( V_16 ) ;
if ( V_29 )
goto V_64;
F_16 ( V_16 ) ;
F_28 ( 2 ) ;
V_29 = F_29 ( V_51 -> V_24 ) ;
if ( V_29 )
goto V_65;
F_30 ( & V_30 . V_52 ) ;
return 0 ;
V_65:
V_64:
if ( V_30 . V_31 )
F_31 ( V_30 . V_31 , true ) ;
V_63:
if ( V_30 . V_31 )
F_32 ( V_30 . V_31 ) ;
V_62:
V_61:
F_33 () ;
V_60:
if ( F_20 ( V_53 ) )
F_34 ( V_30 . V_54 ) ;
V_59:
F_35 ( V_16 ) ;
V_58:
V_57:
V_56:
F_30 ( & V_30 . V_52 ) ;
return V_29 ;
}
void F_36 ( struct V_15 * V_16 )
{
struct V_21 * V_22 = V_16 -> V_23 -> V_24 ;
F_19 ( & V_30 . V_52 ) ;
F_37 ( V_22 ) ;
if ( V_30 . V_31 ) {
F_9 ( V_22 -> V_32 , V_14 ) ;
F_31 ( V_30 . V_31 , true ) ;
F_32 ( V_30 . V_31 ) ;
}
F_33 () ;
if ( F_20 ( V_53 ) )
F_34 ( V_30 . V_54 ) ;
F_35 ( V_16 ) ;
F_30 ( & V_30 . V_52 ) ;
}
void F_38 ( struct V_15 * V_16 ,
struct V_38 * V_40 )
{
F_39 ( L_6 ) ;
F_19 ( & V_30 . V_52 ) ;
V_30 . V_40 = * V_40 ;
F_30 ( & V_30 . V_52 ) ;
}
int F_40 ( struct V_15 * V_16 ,
struct V_38 * V_40 )
{
int V_29 ;
struct V_21 * V_22 = V_16 -> V_23 -> V_24 ;
int V_19 , V_20 ;
unsigned long V_18 ;
unsigned long V_41 ;
struct V_27 V_28 ;
if ( V_22 && ! F_41 ( V_22 -> V_32 , V_40 ) )
return - V_66 ;
if ( V_40 -> V_42 == 0 )
return - V_66 ;
if ( V_30 . V_31 ) {
struct V_25 V_26 ;
V_29 = F_7 ( V_30 . V_31 ,
V_40 -> V_42 * 1000 ,
& V_26 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_18 = V_26 . V_35 ;
} else {
struct V_36 V_37 ;
V_29 = F_11 ( V_40 -> V_42 * 1000 ,
& V_37 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_18 = V_37 . V_18 ;
}
V_19 = V_28 . V_19 ;
V_20 = V_28 . V_20 ;
V_41 = V_18 / V_19 / V_20 / 1000 ;
V_40 -> V_42 = V_41 ;
return 0 ;
}
void F_42 ( struct V_15 * V_16 , int V_48 )
{
F_19 ( & V_30 . V_52 ) ;
V_30 . V_48 = V_48 ;
F_30 ( & V_30 . V_52 ) ;
}
static int T_1 F_43 ( struct V_1 * V_31 )
{
int V_29 ;
V_29 = F_26 ( V_31 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_27 ( V_31 , 0 , 1 ) ;
if ( V_29 ) {
F_32 ( V_31 ) ;
return V_29 ;
}
F_31 ( V_31 , true ) ;
F_32 ( V_31 ) ;
return 0 ;
}
static int T_1 F_44 ( struct V_15 * V_16 )
{
struct V_1 * V_31 ;
F_39 ( L_7 ) ;
if ( F_20 ( V_53 ) &&
V_30 . V_54 == NULL ) {
struct V_67 * V_68 ;
V_68 = F_45 () ;
if ( F_46 ( V_68 ) ) {
F_21 ( L_8 ) ;
return F_47 ( V_68 ) ;
}
V_30 . V_54 = V_68 ;
}
V_31 = F_1 ( V_16 -> V_3 ) ;
if ( V_31 && F_43 ( V_31 ) ) {
V_31 = NULL ;
F_14 ( L_9 ) ;
}
if ( V_31 )
F_39 ( L_10 ) ;
V_30 . V_31 = V_31 ;
return 0 ;
}
static struct V_15 * T_1 F_48 ( struct V_1 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_72 . V_73 ;
const char * V_74 = F_49 () ;
struct V_15 * V_75 ;
int V_76 ;
V_75 = NULL ;
for ( V_76 = 0 ; V_76 < V_71 -> V_77 ; ++ V_76 ) {
struct V_15 * V_16 = V_71 -> V_78 [ V_76 ] ;
if ( V_16 -> type != V_79 )
continue;
if ( V_75 == NULL )
V_75 = V_16 ;
if ( V_74 != NULL &&
strcmp ( V_16 -> V_80 , V_74 ) == 0 ) {
V_75 = V_16 ;
break;
}
}
return V_75 ;
}
static void T_1 F_50 ( struct V_1 * V_81 )
{
struct V_15 * V_82 ;
struct V_15 * V_16 ;
int V_29 ;
V_82 = F_48 ( V_81 ) ;
if ( ! V_82 )
return;
V_16 = F_51 ( & V_81 -> V_72 ) ;
if ( ! V_16 )
return;
F_52 ( V_16 , V_82 ) ;
V_29 = F_44 ( V_16 ) ;
if ( V_29 ) {
F_21 ( L_11 , V_16 -> V_80 , V_29 ) ;
F_53 ( V_16 ) ;
return;
}
V_29 = F_54 ( & V_30 . V_23 , V_16 ) ;
if ( V_29 ) {
F_21 ( L_12 ,
V_16 -> V_80 ) ;
F_53 ( V_16 ) ;
return;
}
V_29 = F_55 ( V_16 ) ;
if ( V_29 ) {
F_21 ( L_13 , V_16 -> V_80 , V_29 ) ;
F_56 ( & V_30 . V_23 ) ;
F_53 ( V_16 ) ;
return;
}
}
static void T_1 F_57 ( struct V_1 * V_69 )
{
struct V_50 * V_51 = & V_30 . V_23 ;
V_51 -> V_69 = V_69 ;
V_51 -> V_32 = V_83 ;
V_51 -> type = V_79 ;
F_58 ( V_51 ) ;
}
static void T_2 F_59 ( struct V_1 * V_69 )
{
struct V_50 * V_51 = & V_30 . V_23 ;
F_60 ( V_51 ) ;
}
static int T_1 F_61 ( struct V_1 * V_69 )
{
F_62 ( & V_30 . V_52 ) ;
F_57 ( V_69 ) ;
F_50 ( V_69 ) ;
return 0 ;
}
static int T_2 F_63 ( struct V_1 * V_69 )
{
F_64 ( & V_69 -> V_72 ) ;
F_59 ( V_69 ) ;
return 0 ;
}
int T_1 F_65 ( void )
{
return F_66 ( & V_84 , F_61 ) ;
}
void T_2 F_67 ( void )
{
F_68 ( & V_84 ) ;
}
