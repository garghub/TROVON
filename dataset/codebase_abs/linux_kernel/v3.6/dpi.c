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
struct V_30 * V_31 = & V_7 -> V_32 . V_33 ;
int V_16 = 0 , V_17 = 0 ;
unsigned long V_15 = 0 ;
unsigned long V_34 ;
int V_22 = 0 ;
if ( F_3 ( V_7 ) )
V_22 = F_4 ( V_7 , V_31 -> V_35 * 1000 , & V_15 ,
& V_16 , & V_17 ) ;
else
V_22 = F_8 ( V_7 , V_31 -> V_35 * 1000 , & V_15 ,
& V_16 , & V_17 ) ;
if ( V_22 )
return V_22 ;
V_34 = V_15 / V_16 / V_17 / 1000 ;
if ( V_34 != V_31 -> V_35 ) {
F_12 ( L_1
L_2 ,
V_31 -> V_35 , V_34 ) ;
V_31 -> V_35 = V_34 ;
}
F_13 ( V_7 -> V_36 , V_31 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
V_23 . V_25 . V_37 = V_38 ;
V_23 . V_25 . V_39 = false ;
V_23 . V_25 . V_40 = false ;
V_23 . V_25 . V_41 = V_7 -> V_42 . V_23 . V_43 ;
V_23 . V_25 . V_44 = 0 ;
F_15 ( V_7 -> V_36 , & V_23 . V_25 ) ;
}
int F_16 ( struct V_6 * V_7 )
{
int V_22 ;
if ( F_17 () && ! V_23 . V_45 ) {
F_18 ( L_3 ) ;
return - V_46 ;
}
if ( V_7 -> V_36 == NULL ) {
F_18 ( L_4 ) ;
return - V_46 ;
}
V_22 = F_19 ( V_7 ) ;
if ( V_22 ) {
F_18 ( L_5 ) ;
goto V_47;
}
if ( F_17 () ) {
V_22 = F_20 ( V_23 . V_45 ) ;
if ( V_22 )
goto V_48;
}
V_22 = F_21 () ;
if ( V_22 )
goto V_49;
if ( F_3 ( V_7 ) ) {
V_22 = F_22 ( V_23 . V_24 ) ;
if ( V_22 )
goto V_50;
V_22 = F_23 ( V_23 . V_24 , 0 , 1 ) ;
if ( V_22 )
goto V_51;
}
V_22 = F_11 ( V_7 ) ;
if ( V_22 )
goto V_52;
F_14 ( V_7 ) ;
F_24 ( 2 ) ;
V_22 = F_25 ( V_7 -> V_36 ) ;
if ( V_22 )
goto V_53;
return 0 ;
V_53:
V_52:
if ( F_3 ( V_7 ) )
F_26 ( V_23 . V_24 , true ) ;
V_51:
if ( F_3 ( V_7 ) )
F_27 ( V_23 . V_24 ) ;
V_50:
F_28 () ;
V_49:
if ( F_17 () )
F_29 ( V_23 . V_45 ) ;
V_48:
F_30 ( V_7 ) ;
V_47:
return V_22 ;
}
void F_31 ( struct V_6 * V_7 )
{
F_32 ( V_7 -> V_36 ) ;
if ( F_3 ( V_7 ) ) {
F_7 ( V_54 ) ;
F_26 ( V_23 . V_24 , true ) ;
F_27 ( V_23 . V_24 ) ;
}
F_28 () ;
if ( F_17 () )
F_29 ( V_23 . V_45 ) ;
F_30 ( V_7 ) ;
}
void F_33 ( struct V_6 * V_7 ,
struct V_30 * V_33 )
{
int V_22 ;
F_34 ( L_6 ) ;
V_7 -> V_32 . V_33 = * V_33 ;
if ( V_7 -> V_55 == V_56 ) {
V_22 = F_21 () ;
if ( V_22 )
return;
F_11 ( V_7 ) ;
F_28 () ;
} else {
F_13 ( V_7 -> V_36 , V_33 ) ;
}
}
int F_35 ( struct V_6 * V_7 ,
struct V_30 * V_33 )
{
int V_22 ;
int V_16 , V_17 ;
unsigned long V_15 ;
unsigned long V_34 ;
struct V_20 V_21 ;
if ( F_36 ( V_7 -> V_36 , V_33 ) )
return - V_57 ;
if ( V_33 -> V_35 == 0 )
return - V_57 ;
if ( F_3 ( V_7 ) ) {
struct V_18 V_19 ;
V_22 = F_5 ( V_23 . V_24 ,
V_33 -> V_35 * 1000 ,
& V_19 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_15 = V_19 . V_27 ;
} else {
struct V_28 V_29 ;
V_22 = F_9 ( V_33 -> V_35 * 1000 ,
& V_29 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_15 = V_29 . V_15 ;
}
V_16 = V_21 . V_16 ;
V_17 = V_21 . V_17 ;
V_34 = V_15 / V_16 / V_17 / 1000 ;
V_33 -> V_35 = V_34 ;
return 0 ;
}
static int T_1 F_37 ( struct V_6 * V_7 )
{
F_34 ( L_7 ) ;
if ( F_17 () && V_23 . V_45 == NULL ) {
struct V_58 * V_59 ;
V_59 = F_38 () ;
if ( F_39 ( V_59 ) ) {
F_18 ( L_8 ) ;
return F_40 ( V_59 ) ;
}
V_23 . V_45 = V_59 ;
}
if ( F_3 ( V_7 ) ) {
enum V_2 V_10 =
V_7 -> V_8 . V_9 . V_10 ;
V_23 . V_24 = F_1 ( V_10 ) ;
}
return 0 ;
}
static void T_1 F_41 ( struct V_1 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_63 . V_64 ;
int V_65 , V_22 ;
for ( V_65 = 0 ; V_65 < V_62 -> V_66 ; ++ V_65 ) {
struct V_6 * V_7 = V_62 -> V_67 [ V_65 ] ;
if ( V_7 -> type != V_68 )
continue;
V_22 = F_37 ( V_7 ) ;
if ( V_22 ) {
F_18 ( L_9 , V_7 -> V_69 , V_22 ) ;
continue;
}
V_22 = F_42 ( V_7 , & V_60 -> V_63 , V_65 ) ;
if ( V_22 )
F_18 ( L_10 ,
V_7 -> V_69 , V_22 ) ;
}
}
static int T_1 F_43 ( struct V_1 * V_60 )
{
F_41 ( V_60 ) ;
return 0 ;
}
static int T_2 F_44 ( struct V_1 * V_60 )
{
F_45 ( & V_60 -> V_63 ) ;
return 0 ;
}
int T_1 F_46 ( void )
{
return F_47 ( & V_70 , F_43 ) ;
}
void T_2 F_48 ( void )
{
F_49 ( & V_70 ) ;
}
