static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_7 . V_8 . V_9 = V_10 ;
V_7 . V_8 . V_11 = false ;
V_7 . V_8 . V_12 = false ;
V_7 . V_8 . V_13 = 24 ;
V_7 . V_8 . V_14 = 1 ;
F_2 ( V_4 , & V_7 . V_8 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_17 * V_18 = & V_7 . V_19 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
unsigned long V_24 ;
int V_25 ;
if ( V_16 == NULL || V_16 -> V_6 == NULL ) {
F_4 ( L_1 ) ;
return - V_26 ;
}
V_25 = F_5 ( V_2 ) ;
if ( V_25 ) {
F_4 ( L_2 ) ;
goto V_27;
}
V_25 = F_6 ( V_7 . V_28 ) ;
if ( V_25 )
goto V_29;
V_25 = F_7 () ;
if ( V_25 )
goto V_30;
V_18 -> V_31 = V_32 ;
V_18 -> V_33 = V_32 ;
V_25 = F_8 ( V_18 -> V_34 * 1000 , & V_21 , & V_23 ) ;
if ( V_25 )
goto V_35;
V_7 . V_8 . V_36 = V_23 ;
V_24 = V_21 . V_37 / V_23 . V_38 / V_23 . V_39 / 1000 ;
if ( V_24 != V_18 -> V_34 ) {
F_9 ( L_3
L_4 ,
V_18 -> V_34 , V_24 ) ;
V_18 -> V_34 = V_24 ;
}
F_10 ( V_16 -> V_6 , V_18 ) ;
V_25 = F_11 ( & V_21 ) ;
if ( V_25 )
goto V_40;
F_1 ( V_2 ) ;
F_12 ( V_16 -> V_6 -> V_41 , & V_7 . V_8 . V_36 ) ;
F_13 ( V_7 . V_42 ) ;
V_25 = F_14 () ;
if ( V_25 )
goto V_43;
F_15 ( 2 ) ;
V_25 = F_16 ( V_16 -> V_6 ) ;
if ( V_25 )
goto V_44;
return 0 ;
V_44:
F_17 () ;
V_43:
V_40:
V_35:
F_18 () ;
V_30:
F_19 ( V_7 . V_28 ) ;
V_29:
F_20 ( V_2 ) ;
V_27:
return V_25 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_22 ( V_4 ) ;
F_17 () ;
F_18 () ;
F_19 ( V_7 . V_28 ) ;
F_20 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_17 * V_19 )
{
V_7 . V_19 = * V_19 ;
}
void F_24 ( struct V_1 * V_2 , int V_42 )
{
V_7 . V_42 = V_42 ;
}
static int T_1 F_25 ( struct V_1 * V_2 )
{
F_26 ( L_5 ) ;
if ( V_7 . V_28 == NULL ) {
struct V_45 * V_46 ;
V_46 = F_27 () ;
if ( F_28 ( V_46 ) ) {
F_4 ( L_6 ) ;
return F_29 ( V_46 ) ;
}
V_7 . V_28 = V_46 ;
}
return 0 ;
}
static struct V_1 * T_1 F_30 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_51 . V_52 ;
const char * V_53 = F_31 () ;
struct V_1 * V_54 ;
int V_55 ;
V_54 = NULL ;
for ( V_55 = 0 ; V_55 < V_50 -> V_56 ; ++ V_55 ) {
struct V_1 * V_2 = V_50 -> V_57 [ V_55 ] ;
if ( V_2 -> type != V_58 )
continue;
if ( V_54 == NULL )
V_54 = V_2 ;
if ( V_53 != NULL &&
strcmp ( V_2 -> V_59 , V_53 ) == 0 ) {
V_54 = V_2 ;
break;
}
}
return V_54 ;
}
static void T_1 F_32 ( struct V_47 * V_60 )
{
struct V_1 * V_61 ;
struct V_1 * V_2 ;
int V_25 ;
V_61 = F_30 ( V_60 ) ;
if ( ! V_61 )
return;
V_2 = F_33 ( & V_60 -> V_51 ) ;
if ( ! V_2 )
return;
F_34 ( V_2 , V_61 ) ;
V_25 = F_25 ( V_2 ) ;
if ( V_25 ) {
F_4 ( L_7 , V_2 -> V_59 , V_25 ) ;
F_35 ( V_2 ) ;
return;
}
V_25 = F_36 ( & V_7 . V_5 , V_2 ) ;
if ( V_25 ) {
F_4 ( L_8 ,
V_2 -> V_59 ) ;
F_35 ( V_2 ) ;
return;
}
V_25 = F_37 ( V_2 ) ;
if ( V_25 ) {
F_4 ( L_9 , V_2 -> V_59 , V_25 ) ;
F_38 ( & V_7 . V_5 ) ;
F_35 ( V_2 ) ;
return;
}
}
static void T_1 F_39 ( struct V_47 * V_48 )
{
struct V_15 * V_16 = & V_7 . V_5 ;
V_16 -> V_48 = V_48 ;
V_16 -> V_41 = V_62 ;
V_16 -> type = V_58 ;
F_40 ( V_16 ) ;
}
static void T_2 F_41 ( struct V_47 * V_48 )
{
struct V_15 * V_16 = & V_7 . V_5 ;
F_42 ( V_16 ) ;
}
static int T_1 F_43 ( struct V_47 * V_48 )
{
F_39 ( V_48 ) ;
F_32 ( V_48 ) ;
return 0 ;
}
static int T_2 F_44 ( struct V_47 * V_48 )
{
F_45 ( & V_48 -> V_51 ) ;
F_41 ( V_48 ) ;
return 0 ;
}
int T_1 F_46 ( void )
{
return F_47 ( & V_63 , F_43 ) ;
}
void T_2 F_48 ( void )
{
F_49 ( & V_63 ) ;
}
