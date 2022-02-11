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
if ( V_23 )
return V_23 ;
* V_16 = V_20 . V_28 ;
* V_17 = V_22 . V_17 ;
* V_18 = V_22 . V_18 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , bool V_14 ,
unsigned long V_15 , unsigned long * V_16 , int * V_17 ,
int * V_18 )
{
struct V_29 V_30 ;
struct V_21 V_22 ;
int V_23 ;
V_23 = F_10 ( V_14 , V_15 , & V_30 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_11 ( & V_30 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_8 ( V_7 -> V_26 -> V_27 , & V_22 ) ;
if ( V_23 )
return V_23 ;
* V_16 = V_30 . V_16 ;
* V_17 = V_22 . V_17 ;
* V_18 = V_22 . V_18 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_31 * V_32 = & V_7 -> V_33 . V_34 ;
int V_17 = 0 , V_18 = 0 ;
unsigned long V_16 = 0 ;
unsigned long V_35 ;
bool V_14 ;
int V_23 = 0 ;
F_13 ( V_7 -> V_26 -> V_27 , V_7 -> V_33 . V_36 ,
V_7 -> V_33 . V_37 , V_7 -> V_33 . V_38 ) ;
V_14 = ( V_7 -> V_33 . V_36 & V_39 ) != 0 ;
if ( F_3 ( V_7 ) )
V_23 = F_4 ( V_7 , V_14 , V_32 -> V_40 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
else
V_23 = F_9 ( V_7 , V_14 , V_32 -> V_40 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_23 )
return V_23 ;
V_35 = V_16 / V_17 / V_18 / 1000 ;
if ( V_35 != V_32 -> V_40 ) {
F_14 ( L_1
L_2 ,
V_32 -> V_40 , V_35 ) ;
V_32 -> V_40 = V_35 ;
}
F_15 ( V_7 -> V_26 -> V_27 , V_32 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
bool V_14 ;
V_14 = ( V_7 -> V_33 . V_36 & V_39 ) != 0 ;
F_17 ( V_7 -> V_26 -> V_27 ,
V_41 ) ;
F_18 ( V_7 -> V_26 -> V_27 , V_14 ?
V_42 : V_43 ) ;
F_19 ( V_7 -> V_26 -> V_27 ,
V_7 -> V_44 . V_24 . V_45 ) ;
}
int F_20 ( struct V_6 * V_7 )
{
int V_23 ;
V_23 = F_21 ( V_7 ) ;
if ( V_23 ) {
F_22 ( L_3 ) ;
goto V_46;
}
if ( F_23 () ) {
V_23 = F_24 ( V_24 . V_47 ) ;
if ( V_23 )
goto V_48;
}
V_23 = F_25 () ;
if ( V_23 )
goto V_49;
V_23 = F_26 () ;
if ( V_23 )
goto V_50;
F_16 ( V_7 ) ;
if ( F_3 ( V_7 ) ) {
V_23 = F_27 ( V_24 . V_25 ) ;
if ( V_23 )
goto V_51;
V_23 = F_28 ( V_24 . V_25 , 0 , 1 ) ;
if ( V_23 )
goto V_52;
}
V_23 = F_12 ( V_7 ) ;
if ( V_23 )
goto V_53;
F_29 ( 2 ) ;
V_7 -> V_26 -> V_54 ( V_7 -> V_26 ) ;
return 0 ;
V_53:
if ( F_3 ( V_7 ) )
F_30 ( V_24 . V_25 , true ) ;
V_52:
if ( F_3 ( V_7 ) )
F_31 ( V_24 . V_25 ) ;
V_51:
F_32 () ;
V_50:
F_33 () ;
V_49:
if ( F_23 () )
F_34 ( V_24 . V_47 ) ;
V_48:
F_35 ( V_7 ) ;
V_46:
return V_23 ;
}
void F_36 ( struct V_6 * V_7 )
{
V_7 -> V_26 -> V_55 ( V_7 -> V_26 ) ;
if ( F_3 ( V_7 ) ) {
F_7 ( V_56 ) ;
F_30 ( V_24 . V_25 , true ) ;
F_31 ( V_24 . V_25 ) ;
}
F_32 () ;
F_33 () ;
if ( F_23 () )
F_34 ( V_24 . V_47 ) ;
F_35 ( V_7 ) ;
}
void F_37 ( struct V_6 * V_7 ,
struct V_31 * V_34 )
{
int V_23 ;
F_38 ( L_4 ) ;
V_7 -> V_33 . V_34 = * V_34 ;
if ( V_7 -> V_57 == V_58 ) {
V_23 = F_25 () ;
if ( V_23 )
return;
V_23 = F_26 () ;
if ( V_23 ) {
F_33 () ;
return;
}
F_12 ( V_7 ) ;
F_39 ( V_7 -> V_26 -> V_27 ) ;
F_32 () ;
F_33 () ;
}
}
int F_40 ( struct V_6 * V_7 ,
struct V_31 * V_34 )
{
bool V_14 ;
int V_23 ;
int V_17 , V_18 ;
unsigned long V_16 ;
unsigned long V_35 ;
struct V_21 V_22 ;
if ( ! F_41 ( V_34 ) )
return - V_59 ;
if ( V_34 -> V_40 == 0 )
return - V_59 ;
V_14 = ( V_7 -> V_33 . V_36 & V_39 ) != 0 ;
if ( F_3 ( V_7 ) ) {
struct V_19 V_20 ;
V_23 = F_5 ( V_24 . V_25 , V_14 ,
V_34 -> V_40 * 1000 ,
& V_20 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_20 . V_28 ;
} else {
struct V_29 V_30 ;
V_23 = F_10 ( V_14 , V_34 -> V_40 * 1000 ,
& V_30 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_30 . V_16 ;
}
V_17 = V_22 . V_17 ;
V_18 = V_22 . V_18 ;
V_35 = V_16 / V_17 / V_18 / 1000 ;
V_34 -> V_40 = V_35 ;
return 0 ;
}
int F_42 ( struct V_6 * V_7 )
{
F_38 ( L_5 ) ;
if ( F_23 () && V_24 . V_47 == NULL ) {
struct V_60 * V_61 ;
V_61 = F_43 () ;
if ( F_44 ( V_61 ) ) {
F_22 ( L_6 ) ;
return F_45 ( V_61 ) ;
}
V_24 . V_47 = V_61 ;
}
if ( F_3 ( V_7 ) ) {
enum V_2 V_10 =
V_7 -> V_8 . V_9 . V_10 ;
V_24 . V_25 = F_1 ( V_10 ) ;
}
return 0 ;
}
int F_46 ( void )
{
return 0 ;
}
void F_47 ( void )
{
}
