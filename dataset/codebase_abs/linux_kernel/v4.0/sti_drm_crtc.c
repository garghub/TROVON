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
F_16 ( struct V_1 * V_2 , struct V_18 * V_3 ,
struct V_18 * V_19 , int V_20 , int V_21 ,
struct V_22 * V_23 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_15 * V_16 ;
struct V_24 * V_24 ;
int V_25 = V_3 -> clock * 1000 ;
int V_26 ;
unsigned int V_27 , V_28 ;
F_2 ( L_7 ,
V_2 -> V_29 . V_11 , F_17 ( V_5 ) ,
V_2 -> V_17 -> V_30 -> V_29 . V_11 , V_3 -> V_29 . V_11 , V_3 -> V_31 ) ;
F_2 ( L_8 ,
V_3 -> V_32 , V_3 -> clock ,
V_3 -> V_33 ,
V_3 -> V_34 , V_3 -> V_35 ,
V_3 -> V_36 ,
V_3 -> V_37 ,
V_3 -> V_38 , V_3 -> V_39 ,
V_3 -> V_40 , V_3 -> type , V_3 -> V_41 ) ;
if ( V_5 -> V_11 == V_12 )
V_24 = V_9 -> V_42 ;
else
V_24 = V_9 -> V_43 ;
V_26 = F_18 ( V_24 , V_25 ) ;
if ( V_26 < 0 ) {
F_10 ( L_9 , V_25 ) ;
return - V_44 ;
}
if ( F_6 ( V_24 ) ) {
F_10 ( L_10 ) ;
return - V_44 ;
}
F_19 ( V_5 -> V_11 == V_12 ?
V_9 -> V_45 : V_9 -> V_46 , & V_2 -> V_3 ) ;
V_16 = F_11 ( V_2 -> V_17 ) ;
if ( ! V_16 ) {
F_10 ( L_11 ) ;
return - V_44 ;
}
memcpy ( & V_2 -> V_3 , V_19 , sizeof( * V_19 ) ) ;
V_26 = F_20 ( V_5 , V_16 ) ;
if ( V_26 ) {
F_10 ( L_12 ) ;
return - V_44 ;
}
V_26 = F_21 ( V_5 , & V_2 -> V_3 ) ;
if ( V_26 ) {
F_10 ( L_13 ) ;
return - V_44 ;
}
V_27 = V_2 -> V_17 -> V_30 -> V_47 - V_20 ;
V_28 = V_2 -> V_17 -> V_30 -> V_48 - V_21 ;
return F_22 ( V_16 , V_2 ,
V_2 -> V_17 -> V_30 , & V_2 -> V_3 ,
V_5 -> V_11 , 0 , 0 , V_27 , V_28 , V_20 , V_21 , V_27 , V_28 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_20 , int V_21 ,
struct V_22 * V_23 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_15 * V_16 ;
unsigned int V_27 , V_28 ;
int V_49 ;
F_2 ( L_14 ,
V_2 -> V_29 . V_11 , F_17 ( V_5 ) ,
V_2 -> V_17 -> V_30 -> V_29 . V_11 , V_20 , V_21 ) ;
V_16 = F_11 ( V_2 -> V_17 ) ;
if ( ! V_16 ) {
F_10 ( L_11 ) ;
V_49 = - V_44 ;
goto V_50;
}
V_27 = V_2 -> V_17 -> V_30 -> V_47 - V_2 -> V_20 ;
V_28 = V_2 -> V_17 -> V_30 -> V_48 - V_2 -> V_21 ;
V_49 = F_22 ( V_16 , V_2 ,
V_2 -> V_17 -> V_30 , & V_2 -> V_3 ,
V_5 -> V_11 , 0 , 0 , V_27 , V_28 ,
V_2 -> V_20 , V_2 -> V_21 , V_27 , V_28 ) ;
if ( V_49 ) {
F_10 ( L_15 ) ;
goto V_50;
}
F_9 ( V_2 ) ;
V_50:
return V_49 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_15 * V_16 ;
if ( ! V_5 -> V_10 )
return;
F_2 ( L_16 , V_2 -> V_29 . V_11 , F_17 ( V_5 ) ) ;
F_25 ( V_5 , false ) ;
V_16 = F_11 ( V_2 -> V_17 ) ;
if ( ! V_16 ) {
F_10 ( L_17 ) ;
return;
}
if ( F_13 ( V_5 , V_16 , false ) )
F_10 ( L_18 ,
F_26 ( V_16 ) ) ;
F_27 ( V_51 ) ;
F_28 ( V_16 ) ;
F_29 ( V_2 ) ;
if ( V_5 -> V_11 == V_12 ) {
F_30 ( V_9 -> V_42 ) ;
F_30 ( V_9 -> V_13 ) ;
} else {
F_30 ( V_9 -> V_43 ) ;
F_30 ( V_9 -> V_14 ) ;
}
V_5 -> V_10 = false ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_22 * V_30 ,
struct V_52 * V_53 ,
T_1 V_54 )
{
struct V_55 * V_56 = V_2 -> V_7 ;
struct V_22 * V_23 ;
struct V_4 * V_5 = F_4 ( V_2 ) ;
unsigned long V_41 ;
int V_49 ;
F_2 ( L_19 ,
V_2 -> V_17 -> V_30 -> V_29 . V_11 , V_30 -> V_29 . V_11 ) ;
F_32 ( & V_56 -> V_57 ) ;
V_23 = V_2 -> V_17 -> V_30 ;
V_2 -> V_17 -> V_30 = V_30 ;
V_49 = F_23 ( V_2 , V_2 -> V_20 , V_2 -> V_21 , V_23 ) ;
if ( V_49 ) {
F_10 ( L_20 ) ;
V_2 -> V_17 -> V_30 = V_23 ;
goto V_50;
}
if ( V_53 ) {
V_53 -> V_58 = V_5 -> V_11 ;
V_49 = F_33 ( V_56 , V_53 -> V_58 ) ;
if ( V_49 ) {
F_10 ( L_21 ) ;
goto V_50;
}
F_34 ( & V_56 -> V_59 , V_41 ) ;
if ( V_5 -> V_60 ) {
F_35 ( V_56 , V_53 -> V_58 ) ;
V_49 = - V_61 ;
} else {
V_5 -> V_60 = V_53 ;
}
F_36 ( & V_56 -> V_59 , V_41 ) ;
}
V_50:
F_37 ( & V_56 -> V_57 ) ;
return V_49 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
T_2 V_64 )
{
F_2 ( L_1 ) ;
return 0 ;
}
int F_41 ( struct V_65 * V_66 ,
unsigned long V_53 , void * V_67 )
{
struct V_55 * V_56 ;
struct V_8 * V_9 =
F_42 ( V_66 , struct V_8 , V_68 ) ;
int * V_2 = V_67 ;
unsigned long V_41 ;
struct V_69 * V_70 ;
V_56 = V_9 -> V_5 [ * V_2 ] -> V_1 . V_7 ;
V_70 = V_56 -> V_71 ;
if ( ( V_53 != V_72 ) &&
( V_53 != V_73 ) ) {
F_10 ( L_22 , V_53 ) ;
return - V_44 ;
}
F_43 ( V_56 , * V_2 ) ;
F_34 ( & V_56 -> V_59 , V_41 ) ;
if ( V_9 -> V_5 [ * V_2 ] -> V_60 ) {
F_44 ( V_56 , - 1 ,
V_9 -> V_5 [ * V_2 ] -> V_60 ) ;
F_35 ( V_56 , * V_2 ) ;
V_9 -> V_5 [ * V_2 ] -> V_60 = NULL ;
}
F_36 ( & V_56 -> V_59 , V_41 ) ;
return 0 ;
}
int F_45 ( struct V_55 * V_7 , int V_2 )
{
struct V_69 * V_74 = V_7 -> V_71 ;
struct V_8 * V_9 = V_74 -> V_9 ;
struct V_65 * V_68 = & V_9 -> V_68 ;
if ( F_46 ( V_2 == V_12 ?
V_9 -> V_45 : V_9 -> V_46 ,
V_68 , V_2 ) ) {
F_10 ( L_23 ) ;
return - V_44 ;
}
return 0 ;
}
void F_47 ( struct V_55 * V_7 , int V_2 )
{
struct V_69 * V_70 = V_7 -> V_71 ;
struct V_8 * V_9 = V_70 -> V_9 ;
struct V_65 * V_68 = & V_9 -> V_68 ;
F_48 ( L_1 ) ;
if ( F_49 ( V_2 == V_12 ?
V_9 -> V_45 : V_9 -> V_46 , V_68 ) )
F_48 ( L_24 ) ;
if ( V_9 -> V_5 [ V_2 ] -> V_60 ) {
F_35 ( V_7 , V_2 ) ;
V_9 -> V_5 [ V_2 ] -> V_60 = NULL ;
}
}
bool F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( V_5 -> V_11 == V_12 )
return true ;
return false ;
}
int F_51 ( struct V_55 * V_56 , struct V_4 * V_5 ,
struct V_75 * V_17 , struct V_75 * V_76 )
{
struct V_1 * V_2 = & V_5 -> V_1 ;
int V_26 ;
V_26 = F_52 ( V_56 , V_2 , V_17 , V_76 ,
& V_77 ) ;
if ( V_26 ) {
F_10 ( L_25 ) ;
return - V_44 ;
}
F_53 ( V_2 , & V_78 ) ;
F_48 ( L_26 ,
V_2 -> V_29 . V_11 , F_17 ( V_5 ) ) ;
return 0 ;
}
