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
static int F_4 ( struct V_6 * V_7 , bool V_14 ,
unsigned long V_15 , unsigned long * V_16 , int * V_17 ,
int * V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 ;
int V_23 ;
V_23 = F_5 ( V_24 . V_25 , V_14 , V_15 ,
& V_20 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_6 ( V_24 . V_25 , & V_20 ) ;
if ( V_23 )
return V_23 ;
F_7 ( V_7 -> V_8 . V_9 . V_10 ) ;
V_23 = F_8 ( V_7 -> V_26 -> V_27 , & V_22 ) ;
if ( V_23 ) {
F_7 ( V_28 ) ;
return V_23 ;
}
* V_16 = V_20 . V_29 ;
* V_17 = V_22 . V_17 ;
* V_18 = V_22 . V_18 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , bool V_14 ,
unsigned long V_15 , unsigned long * V_16 , int * V_17 ,
int * V_18 )
{
struct V_30 V_31 ;
struct V_21 V_22 ;
int V_23 ;
V_23 = F_10 ( V_14 , V_15 , & V_31 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_11 ( & V_31 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_8 ( V_7 -> V_26 -> V_27 , & V_22 ) ;
if ( V_23 )
return V_23 ;
* V_16 = V_31 . V_16 ;
* V_17 = V_22 . V_17 ;
* V_18 = V_22 . V_18 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = & V_7 -> V_34 . V_35 ;
int V_17 = 0 , V_18 = 0 ;
unsigned long V_16 = 0 ;
unsigned long V_36 ;
bool V_14 ;
int V_23 = 0 ;
F_13 ( V_7 -> V_26 -> V_27 , V_7 -> V_34 . V_37 ,
V_7 -> V_34 . V_38 , V_7 -> V_34 . V_39 ) ;
V_14 = ( V_7 -> V_34 . V_37 & V_40 ) != 0 ;
if ( F_3 ( V_7 ) )
V_23 = F_4 ( V_7 , V_14 , V_33 -> V_41 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
else
V_23 = F_9 ( V_7 , V_14 , V_33 -> V_41 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_23 )
return V_23 ;
V_36 = V_16 / V_17 / V_18 / 1000 ;
if ( V_36 != V_33 -> V_41 ) {
F_14 ( L_1
L_2 ,
V_33 -> V_41 , V_36 ) ;
V_33 -> V_41 = V_36 ;
}
F_15 ( V_7 -> V_26 , V_33 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
bool V_14 ;
V_14 = ( V_7 -> V_34 . V_37 & V_40 ) != 0 ;
F_17 ( V_42 ) ;
F_18 ( V_7 -> V_26 -> V_27 , false ) ;
F_19 ( V_7 -> V_26 -> V_27 , V_14 ?
V_43 : V_44 ) ;
F_20 ( V_7 -> V_26 -> V_27 ,
V_7 -> V_45 . V_24 . V_46 ) ;
}
int F_21 ( struct V_6 * V_7 )
{
int V_23 ;
if ( F_22 () && ! V_24 . V_47 ) {
F_23 ( L_3 ) ;
return - V_48 ;
}
if ( V_7 -> V_26 == NULL ) {
F_23 ( L_4 ) ;
return - V_48 ;
}
V_23 = F_24 ( V_7 ) ;
if ( V_23 ) {
F_23 ( L_5 ) ;
goto V_49;
}
if ( F_22 () ) {
V_23 = F_25 ( V_24 . V_47 ) ;
if ( V_23 )
goto V_50;
}
V_23 = F_26 () ;
if ( V_23 )
goto V_51;
F_16 ( V_7 ) ;
if ( F_3 ( V_7 ) ) {
V_23 = F_27 ( V_24 . V_25 ) ;
if ( V_23 )
goto V_52;
V_23 = F_28 ( V_24 . V_25 , 0 , 1 ) ;
if ( V_23 )
goto V_53;
}
V_23 = F_12 ( V_7 ) ;
if ( V_23 )
goto V_54;
F_29 ( 2 ) ;
V_23 = F_30 ( V_7 -> V_26 ) ;
if ( V_23 )
goto V_55;
return 0 ;
V_55:
V_54:
if ( F_3 ( V_7 ) )
F_31 ( V_24 . V_25 , true ) ;
V_53:
if ( F_3 ( V_7 ) )
F_32 ( V_24 . V_25 ) ;
V_52:
F_33 () ;
V_51:
if ( F_22 () )
F_34 ( V_24 . V_47 ) ;
V_50:
F_35 ( V_7 ) ;
V_49:
return V_23 ;
}
void F_36 ( struct V_6 * V_7 )
{
F_37 ( V_7 -> V_26 ) ;
if ( F_3 ( V_7 ) ) {
F_7 ( V_28 ) ;
F_31 ( V_24 . V_25 , true ) ;
F_32 ( V_24 . V_25 ) ;
}
F_33 () ;
if ( F_22 () )
F_34 ( V_24 . V_47 ) ;
F_35 ( V_7 ) ;
}
void F_38 ( struct V_6 * V_7 ,
struct V_32 * V_35 )
{
int V_23 ;
F_39 ( L_6 ) ;
V_7 -> V_34 . V_35 = * V_35 ;
if ( V_7 -> V_56 == V_57 ) {
V_23 = F_26 () ;
if ( V_23 )
return;
F_12 ( V_7 ) ;
F_33 () ;
} else {
F_15 ( V_7 -> V_26 , V_35 ) ;
}
}
int F_40 ( struct V_6 * V_7 ,
struct V_32 * V_35 )
{
bool V_14 ;
int V_23 ;
int V_17 , V_18 ;
unsigned long V_16 ;
unsigned long V_36 ;
struct V_21 V_22 ;
if ( F_41 ( V_7 -> V_26 , V_35 ) )
return - V_58 ;
if ( V_35 -> V_41 == 0 )
return - V_58 ;
V_14 = ( V_7 -> V_34 . V_37 & V_40 ) != 0 ;
if ( F_3 ( V_7 ) ) {
struct V_19 V_20 ;
V_23 = F_5 ( V_24 . V_25 , V_14 ,
V_35 -> V_41 * 1000 ,
& V_20 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_20 . V_29 ;
} else {
struct V_30 V_31 ;
V_23 = F_10 ( V_14 , V_35 -> V_41 * 1000 ,
& V_31 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_31 . V_16 ;
}
V_17 = V_22 . V_17 ;
V_18 = V_22 . V_18 ;
V_36 = V_16 / V_17 / V_18 / 1000 ;
V_35 -> V_41 = V_36 ;
return 0 ;
}
static int T_1 F_42 ( struct V_6 * V_7 )
{
F_39 ( L_7 ) ;
if ( F_22 () && V_24 . V_47 == NULL ) {
struct V_59 * V_60 ;
V_60 = F_43 () ;
if ( F_44 ( V_60 ) ) {
F_23 ( L_8 ) ;
return F_45 ( V_60 ) ;
}
V_24 . V_47 = V_60 ;
}
if ( F_3 ( V_7 ) ) {
enum V_2 V_10 =
V_7 -> V_8 . V_9 . V_10 ;
V_24 . V_25 = F_1 ( V_10 ) ;
}
return 0 ;
}
static void T_1 F_46 ( struct V_1 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_64 . V_65 ;
int V_66 , V_23 ;
for ( V_66 = 0 ; V_66 < V_63 -> V_67 ; ++ V_66 ) {
struct V_6 * V_7 = V_63 -> V_68 [ V_66 ] ;
if ( V_7 -> type != V_69 )
continue;
V_23 = F_42 ( V_7 ) ;
if ( V_23 ) {
F_23 ( L_9 , V_7 -> V_70 , V_23 ) ;
continue;
}
V_23 = F_47 ( V_7 , & V_61 -> V_64 , V_66 ) ;
if ( V_23 )
F_23 ( L_10 ,
V_7 -> V_70 , V_23 ) ;
}
}
static int T_1 F_48 ( struct V_1 * V_61 )
{
F_46 ( V_61 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_1 * V_61 )
{
F_50 ( & V_61 -> V_64 ) ;
return 0 ;
}
int T_1 F_51 ( void )
{
return F_52 ( & V_71 , F_48 ) ;
}
void T_2 F_53 ( void )
{
F_54 ( & V_71 ) ;
}
