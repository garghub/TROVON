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
F_13 ( V_36 | V_37 ) ;
F_14 ( V_7 -> V_26 -> V_27 , V_7 -> V_33 . V_38 ,
V_7 -> V_33 . V_39 , V_7 -> V_33 . V_40 ) ;
V_14 = ( V_7 -> V_33 . V_38 & V_41 ) != 0 ;
if ( F_3 ( V_7 ) )
V_23 = F_4 ( V_7 , V_14 , V_32 -> V_42 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
else
V_23 = F_9 ( V_7 , V_14 , V_32 -> V_42 * 1000 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_23 )
goto V_43;
V_35 = V_16 / V_17 / V_18 / 1000 ;
if ( V_35 != V_32 -> V_42 ) {
F_15 ( L_1
L_2 ,
V_32 -> V_42 , V_35 ) ;
V_32 -> V_42 = V_35 ;
}
F_16 ( V_7 -> V_26 -> V_27 , V_32 ) ;
V_43:
F_17 ( V_36 | V_37 ) ;
return V_23 ;
}
static int F_18 ( struct V_6 * V_7 )
{
bool V_14 ;
V_14 = ( V_7 -> V_33 . V_38 & V_41 ) != 0 ;
F_19 ( V_7 -> V_26 -> V_27 ,
V_44 ) ;
F_20 ( V_7 -> V_26 -> V_27 , V_14 ?
V_45 : V_46 ) ;
F_21 ( V_7 -> V_26 -> V_27 ,
V_7 -> V_47 . V_24 . V_48 ) ;
return 0 ;
}
int F_22 ( struct V_6 * V_7 )
{
int V_23 ;
V_23 = F_23 ( V_7 ) ;
if ( V_23 ) {
F_24 ( L_3 ) ;
goto V_43;
}
if ( F_25 () ) {
V_23 = F_26 ( V_24 . V_49 ) ;
if ( V_23 )
goto V_50;
}
F_13 ( V_36 | V_37 ) ;
V_23 = F_18 ( V_7 ) ;
if ( V_23 )
goto V_51;
if ( F_3 ( V_7 ) ) {
F_13 ( V_52 ) ;
V_23 = F_27 ( V_24 . V_25 , 0 , 1 ) ;
if ( V_23 )
goto V_53;
}
V_23 = F_12 ( V_7 ) ;
if ( V_23 )
goto V_54;
F_28 ( 2 ) ;
V_7 -> V_26 -> V_55 ( V_7 -> V_26 ) ;
return 0 ;
V_54:
if ( F_3 ( V_7 ) )
F_29 ( V_24 . V_25 , true ) ;
V_53:
if ( F_3 ( V_7 ) )
F_17 ( V_52 ) ;
V_51:
F_17 ( V_36 | V_37 ) ;
if ( F_25 () )
F_30 ( V_24 . V_49 ) ;
V_50:
F_31 ( V_7 ) ;
V_43:
return V_23 ;
}
void F_32 ( struct V_6 * V_7 )
{
V_7 -> V_26 -> V_56 ( V_7 -> V_26 ) ;
if ( F_3 ( V_7 ) ) {
F_7 ( V_57 ) ;
F_29 ( V_24 . V_25 , true ) ;
F_17 ( V_52 ) ;
}
F_17 ( V_36 | V_37 ) ;
if ( F_25 () )
F_30 ( V_24 . V_49 ) ;
F_31 ( V_7 ) ;
}
void F_33 ( struct V_6 * V_7 ,
struct V_31 * V_34 )
{
F_34 ( L_4 ) ;
V_7 -> V_33 . V_34 = * V_34 ;
if ( V_7 -> V_58 == V_59 ) {
F_12 ( V_7 ) ;
F_35 ( V_7 -> V_26 -> V_27 ) ;
}
}
int F_36 ( struct V_6 * V_7 ,
struct V_31 * V_34 )
{
bool V_14 ;
int V_23 ;
int V_17 , V_18 ;
unsigned long V_16 ;
unsigned long V_35 ;
struct V_21 V_22 ;
if ( ! F_37 ( V_34 ) )
return - V_60 ;
if ( V_34 -> V_42 == 0 )
return - V_60 ;
V_14 = ( V_7 -> V_33 . V_38 & V_41 ) != 0 ;
if ( F_3 ( V_7 ) ) {
struct V_19 V_20 ;
V_23 = F_5 ( V_24 . V_25 , V_14 ,
V_34 -> V_42 * 1000 ,
& V_20 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_20 . V_28 ;
} else {
struct V_29 V_30 ;
V_23 = F_10 ( V_14 , V_34 -> V_42 * 1000 ,
& V_30 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_16 = V_30 . V_16 ;
}
V_17 = V_22 . V_17 ;
V_18 = V_22 . V_18 ;
V_35 = V_16 / V_17 / V_18 / 1000 ;
V_34 -> V_42 = V_35 ;
return 0 ;
}
int F_38 ( struct V_6 * V_7 )
{
F_34 ( L_5 ) ;
if ( F_25 () && V_24 . V_49 == NULL ) {
struct V_61 * V_62 ;
V_62 = F_39 () ;
if ( F_40 ( V_62 ) ) {
F_24 ( L_6 ) ;
return F_41 ( V_62 ) ;
}
V_24 . V_49 = V_62 ;
}
if ( F_3 ( V_7 ) ) {
enum V_2 V_10 =
V_7 -> V_8 . V_9 . V_10 ;
V_24 . V_25 = F_1 ( V_10 ) ;
}
return 0 ;
}
int F_42 ( void )
{
return 0 ;
}
void F_43 ( void )
{
}
