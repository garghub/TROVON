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
struct V_25 * V_26 = V_24 -> V_27 -> V_28 ;
V_29 . V_30 . V_31 = V_32 ;
V_29 . V_30 . V_33 = false ;
V_29 . V_30 . V_34 = false ;
V_29 . V_30 . V_35 = 24 ;
V_29 . V_30 . V_36 = 1 ;
F_8 ( V_26 , & V_29 . V_30 ) ;
}
int F_9 ( struct V_23 * V_24 )
{
struct V_37 * V_38 = V_24 -> V_27 ;
struct V_39 * V_40 = & V_29 . V_41 ;
struct V_18 V_13 ;
struct V_19 V_8 ;
unsigned long V_4 ;
int V_42 ;
if ( V_38 == NULL || V_38 -> V_28 == NULL ) {
F_10 ( L_1 ) ;
return - V_43 ;
}
V_42 = F_11 ( V_24 ) ;
if ( V_42 ) {
F_10 ( L_2 ) ;
goto V_44;
}
V_42 = F_12 ( V_29 . V_45 ) ;
if ( V_42 )
goto V_46;
V_42 = F_13 () ;
if ( V_42 )
goto V_47;
V_40 -> V_48 = V_49 ;
V_40 -> V_50 = V_49 ;
V_42 = F_4 ( V_40 -> V_51 * 1000 , & V_13 , & V_8 ) ;
if ( V_42 )
goto V_52;
V_29 . V_30 . V_53 = V_8 ;
V_4 = V_13 . V_12 / V_8 . V_9 / V_8 . V_10 / 1000 ;
if ( V_4 != V_40 -> V_51 ) {
F_14 ( L_3
L_4 ,
V_40 -> V_51 , V_4 ) ;
V_40 -> V_51 = V_4 ;
}
F_15 ( V_38 -> V_28 , V_40 ) ;
V_42 = F_16 ( & V_13 ) ;
if ( V_42 )
goto V_54;
F_7 ( V_24 ) ;
F_17 ( V_38 -> V_28 -> V_55 , & V_29 . V_30 . V_53 ) ;
F_18 ( V_29 . V_56 ) ;
V_42 = F_19 () ;
if ( V_42 )
goto V_57;
F_20 ( 2 ) ;
V_42 = F_21 ( V_38 -> V_28 ) ;
if ( V_42 )
goto V_58;
return 0 ;
V_58:
F_22 () ;
V_57:
V_54:
V_52:
F_23 () ;
V_47:
F_24 ( V_29 . V_45 ) ;
V_46:
F_25 ( V_24 ) ;
V_44:
return V_42 ;
}
void F_26 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 -> V_28 ;
F_27 ( V_26 ) ;
F_22 () ;
F_23 () ;
F_24 ( V_29 . V_45 ) ;
F_25 ( V_24 ) ;
}
void F_28 ( struct V_23 * V_24 ,
struct V_39 * V_41 )
{
V_29 . V_41 = * V_41 ;
}
void F_29 ( struct V_23 * V_24 , int V_56 )
{
V_29 . V_56 = V_56 ;
}
static int F_30 ( struct V_23 * V_24 )
{
F_31 ( L_5 ) ;
if ( V_29 . V_45 == NULL ) {
struct V_59 * V_60 ;
V_60 = F_32 () ;
if ( F_33 ( V_60 ) ) {
F_10 ( L_6 ) ;
return F_34 ( V_60 ) ;
}
V_29 . V_45 = V_60 ;
}
return 0 ;
}
static struct V_23 * F_35 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 . V_66 ;
const char * V_67 = F_36 () ;
struct V_23 * V_68 ;
int V_20 ;
V_68 = NULL ;
for ( V_20 = 0 ; V_20 < V_64 -> V_69 ; ++ V_20 ) {
struct V_23 * V_24 = V_64 -> V_70 [ V_20 ] ;
if ( V_24 -> type != V_71 )
continue;
if ( V_68 == NULL )
V_68 = V_24 ;
if ( V_67 != NULL &&
strcmp ( V_24 -> V_72 , V_67 ) == 0 ) {
V_68 = V_24 ;
break;
}
}
return V_68 ;
}
static int F_37 ( struct V_61 * V_73 )
{
struct V_23 * V_74 ;
struct V_23 * V_24 ;
int V_42 ;
V_74 = F_35 ( V_73 ) ;
if ( ! V_74 )
return 0 ;
V_24 = F_38 ( & V_73 -> V_65 ) ;
if ( ! V_24 )
return - V_75 ;
F_39 ( V_24 , V_74 ) ;
V_42 = F_30 ( V_24 ) ;
if ( V_42 ) {
F_10 ( L_7 , V_24 -> V_72 , V_42 ) ;
F_40 ( V_24 ) ;
return V_42 ;
}
V_42 = F_41 ( & V_29 . V_27 , V_24 ) ;
if ( V_42 ) {
F_10 ( L_8 ,
V_24 -> V_72 ) ;
F_40 ( V_24 ) ;
return V_42 ;
}
V_42 = F_42 ( V_24 ) ;
if ( V_42 ) {
F_10 ( L_9 , V_24 -> V_72 , V_42 ) ;
F_43 ( & V_29 . V_27 ) ;
F_40 ( V_24 ) ;
return V_42 ;
}
return 0 ;
}
static void F_44 ( struct V_61 * V_62 )
{
struct V_37 * V_38 = & V_29 . V_27 ;
V_38 -> V_62 = V_62 ;
V_38 -> V_55 = V_76 ;
V_38 -> type = V_71 ;
V_38 -> V_72 = L_10 ;
V_38 -> V_77 = V_78 ;
F_45 ( V_38 ) ;
}
static void T_1 F_46 ( struct V_61 * V_62 )
{
struct V_37 * V_38 = & V_29 . V_27 ;
F_47 ( V_38 ) ;
}
static int F_48 ( struct V_61 * V_62 )
{
int V_42 ;
F_44 ( V_62 ) ;
V_42 = F_37 ( V_62 ) ;
if ( V_42 ) {
F_46 ( V_62 ) ;
return V_42 ;
}
return 0 ;
}
static int T_1 F_49 ( struct V_61 * V_62 )
{
F_50 ( & V_62 -> V_65 ) ;
F_46 ( V_62 ) ;
return 0 ;
}
int T_2 F_51 ( void )
{
return F_52 ( & V_79 ) ;
}
void T_1 F_53 ( void )
{
F_54 ( & V_79 ) ;
}
