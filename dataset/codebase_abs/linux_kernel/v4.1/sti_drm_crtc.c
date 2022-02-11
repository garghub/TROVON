static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( L_1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
V_5 -> V_10 = true ;
if ( V_5 -> V_11 == V_12 ) {
if ( F_6 ( V_9 -> V_13 ) )
F_7 ( L_2 ) ;
} else {
if ( F_6 ( V_9 -> V_14 ) )
F_7 ( L_3 ) ;
}
F_8 ( V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_15 * V_16 ;
if ( ( ! V_5 || ! V_9 ) ) {
F_10 ( L_4 ) ;
return;
}
V_16 = F_11 ( V_2 -> V_17 ) ;
if ( V_16 )
F_12 ( V_16 ) ;
else
F_10 ( L_5 ) ;
if ( F_13 ( V_5 , V_16 , true ) )
F_10 ( L_6 ) ;
F_14 ( V_2 ) ;
}
static bool F_15 ( struct V_1 * V_2 ,
const struct V_18 * V_3 ,
struct V_18 * V_19 )
{
return true ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_18 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_20 * V_20 ;
int V_21 = V_3 -> clock * 1000 ;
int V_22 ;
F_2 ( L_7 ,
V_2 -> V_23 . V_11 , F_17 ( V_5 ) ,
V_3 -> V_23 . V_11 , V_3 -> V_24 ) ;
F_2 ( L_8 ,
V_3 -> V_25 , V_3 -> clock ,
V_3 -> V_26 ,
V_3 -> V_27 , V_3 -> V_28 ,
V_3 -> V_29 ,
V_3 -> V_30 ,
V_3 -> V_31 , V_3 -> V_32 ,
V_3 -> V_33 , V_3 -> type , V_3 -> V_34 ) ;
if ( V_5 -> V_11 == V_12 )
V_20 = V_9 -> V_35 ;
else
V_20 = V_9 -> V_36 ;
V_22 = F_18 ( V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_10 ( L_9 , V_21 ) ;
return - V_37 ;
}
if ( F_6 ( V_20 ) ) {
F_10 ( L_10 ) ;
return - V_37 ;
}
F_19 ( V_5 -> V_11 == V_12 ?
V_9 -> V_38 : V_9 -> V_39 , & V_2 -> V_3 ) ;
V_22 = F_20 ( V_5 , & V_2 -> V_3 ) ;
if ( V_22 ) {
F_10 ( L_11 ) ;
return - V_37 ;
}
return V_22 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
if ( ! V_5 -> V_10 )
return;
F_2 ( L_12 , V_2 -> V_23 . V_11 , F_17 ( V_5 ) ) ;
F_22 ( V_5 , false ) ;
F_23 ( V_2 ) ;
if ( V_5 -> V_11 == V_12 ) {
F_24 ( V_9 -> V_35 ) ;
F_24 ( V_9 -> V_13 ) ;
} else {
F_24 ( V_9 -> V_36 ) ;
F_24 ( V_9 -> V_14 ) ;
}
V_5 -> V_10 = false ;
}
static void
F_25 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_16 ( V_2 , & V_2 -> V_40 -> V_19 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( V_2 -> V_40 -> V_41 ) {
V_2 -> V_40 -> V_41 -> V_42 = F_27 ( V_2 ) ;
F_28 ( F_29 ( V_2 ) != 0 ) ;
V_5 -> V_43 = V_2 -> V_40 -> V_41 ;
V_2 -> V_40 -> V_41 = NULL ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_1 V_46 )
{
F_2 ( L_1 ) ;
return 0 ;
}
int F_34 ( struct V_47 * V_48 ,
unsigned long V_41 , void * V_49 )
{
struct V_50 * V_51 ;
struct V_8 * V_9 =
F_35 ( V_48 , struct V_8 , V_52 ) ;
int * V_2 = V_49 ;
unsigned long V_34 ;
struct V_53 * V_54 ;
V_51 = V_9 -> V_5 [ * V_2 ] -> V_1 . V_7 ;
V_54 = V_51 -> V_55 ;
if ( ( V_41 != V_56 ) &&
( V_41 != V_57 ) ) {
F_10 ( L_13 , V_41 ) ;
return - V_37 ;
}
F_36 ( V_51 , * V_2 ) ;
F_37 ( & V_51 -> V_58 , V_34 ) ;
if ( V_9 -> V_5 [ * V_2 ] -> V_43 ) {
F_38 ( V_51 , - 1 ,
V_9 -> V_5 [ * V_2 ] -> V_43 ) ;
F_39 ( V_51 , * V_2 ) ;
V_9 -> V_5 [ * V_2 ] -> V_43 = NULL ;
}
F_40 ( & V_51 -> V_58 , V_34 ) ;
return 0 ;
}
int F_41 ( struct V_50 * V_7 , int V_2 )
{
struct V_53 * V_59 = V_7 -> V_55 ;
struct V_8 * V_9 = V_59 -> V_9 ;
struct V_47 * V_52 = & V_9 -> V_52 ;
if ( F_42 ( V_2 == V_12 ?
V_9 -> V_38 : V_9 -> V_39 ,
V_52 , V_2 ) ) {
F_10 ( L_14 ) ;
return - V_37 ;
}
return 0 ;
}
void F_43 ( struct V_50 * V_7 , int V_2 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_8 * V_9 = V_54 -> V_9 ;
struct V_47 * V_52 = & V_9 -> V_52 ;
F_44 ( L_1 ) ;
if ( F_45 ( V_2 == V_12 ?
V_9 -> V_38 : V_9 -> V_39 , V_52 ) )
F_44 ( L_15 ) ;
if ( V_9 -> V_5 [ V_2 ] -> V_43 ) {
F_39 ( V_7 , V_2 ) ;
V_9 -> V_5 [ V_2 ] -> V_43 = NULL ;
}
}
bool F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( V_5 -> V_11 == V_12 )
return true ;
return false ;
}
int F_47 ( struct V_50 * V_51 , struct V_4 * V_5 ,
struct V_60 * V_17 , struct V_60 * V_61 )
{
struct V_1 * V_2 = & V_5 -> V_1 ;
int V_22 ;
V_22 = F_48 ( V_51 , V_2 , V_17 , V_61 ,
& V_62 ) ;
if ( V_22 ) {
F_10 ( L_16 ) ;
return - V_37 ;
}
F_49 ( V_2 , & V_63 ) ;
F_44 ( L_17 ,
V_2 -> V_23 . V_11 , F_17 ( V_5 ) ) ;
return 0 ;
}
