static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
T_1 V_4 = F_2 ( V_3 ? V_5 : 0 , V_5 ) ;
return F_3 ( V_2 -> V_6 -> V_7 , V_2 -> V_8 , V_4 ) ;
}
static unsigned long F_4 ( struct V_9 * V_10 ,
unsigned long V_11 )
{
return 480000000 ;
}
static void F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ,
struct V_1 ,
V_12 ) ;
F_1 ( V_2 , 1 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ,
struct V_1 ,
V_12 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ,
struct V_1 ,
V_12 ) ;
int V_13 ;
T_1 V_4 ;
V_13 = F_9 ( V_2 -> V_6 -> V_7 , V_2 -> V_8 , & V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
return ( V_4 & V_5 ) ? 0 : 1 ;
}
static int F_10 ( struct V_2 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_15 )
return - V_16 ;
F_12 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_15 )
return - V_16 ;
return F_14 ( V_2 -> V_17 ) ;
}
static int F_15 ( struct V_2 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_18 ) {
F_16 ( V_2 -> V_18 ) ;
F_17 ( 10 ) ;
F_18 ( V_2 -> V_18 ) ;
}
return 0 ;
}
static void F_19 ( void * V_19 )
{
struct V_1 * V_20 = V_19 ;
if ( ! V_20 -> V_15 ) {
F_20 ( V_20 -> V_21 ) ;
F_21 ( V_20 -> V_17 ) ;
}
if ( V_20 -> V_22 )
F_22 ( V_20 -> V_22 ) ;
}
static int F_23 ( struct V_23 * V_6 ,
struct V_24 * V_25 )
{
struct V_1 * V_20 ;
unsigned int V_8 ;
const char * V_26 ;
struct V_27 V_28 ;
int V_29 , V_30 ;
V_20 = F_24 ( V_6 -> V_31 , sizeof( * V_20 ) , V_32 ) ;
if ( ! V_20 )
return - V_33 ;
V_20 -> V_6 = V_6 ;
V_20 -> V_21 = V_25 ;
if ( F_25 ( V_25 , L_1 , & V_8 ) ) {
F_26 ( V_6 -> V_31 , L_2 ,
V_25 -> V_34 ) ;
return - V_35 ;
}
V_20 -> V_18 = F_27 ( V_25 , L_3 ) ;
if ( F_28 ( V_20 -> V_18 ) )
V_20 -> V_18 = NULL ;
V_20 -> V_8 = V_8 ;
V_20 -> V_22 = F_29 ( V_25 , L_4 ) ;
if ( F_28 ( V_20 -> V_22 ) )
V_20 -> V_22 = NULL ;
V_30 = 0 ;
V_28 . V_34 = NULL ;
while ( V_6 -> V_36 -> V_37 [ V_30 ] . V_38 ) {
if ( V_6 -> V_36 -> V_37 [ V_30 ] . V_38 == V_8 ) {
V_28 . V_34 = V_6 -> V_36 -> V_37 [ V_30 ] . V_39 ;
break;
}
V_30 ++ ;
}
if ( ! V_28 . V_34 ) {
F_26 ( V_6 -> V_31 , L_5 ) ;
return - V_35 ;
}
if ( V_40 && V_6 -> V_36 -> V_41 == V_30 ) {
F_30 ( V_6 -> V_31 , L_6 , V_30 ) ;
V_20 -> V_15 = true ;
} else {
if ( V_20 -> V_22 ) {
V_26 = F_31 ( V_20 -> V_22 ) ;
V_28 . V_42 = 0 ;
V_28 . V_43 = & V_26 ;
V_28 . V_44 = 1 ;
} else {
V_28 . V_42 = 0 ;
V_28 . V_43 = NULL ;
V_28 . V_44 = 0 ;
}
V_28 . V_45 = & V_46 ;
V_20 -> V_12 . V_28 = & V_28 ;
V_20 -> V_17 = F_32 ( V_6 -> V_31 , & V_20 -> V_12 ) ;
if ( F_28 ( V_20 -> V_17 ) ) {
V_29 = F_33 ( V_20 -> V_17 ) ;
goto V_47;
}
V_29 = F_34 ( V_25 , V_48 ,
V_20 -> V_17 ) ;
if ( V_29 < 0 )
goto V_49;
}
V_29 = F_35 ( V_6 -> V_31 , F_19 ,
V_20 ) ;
if ( V_29 )
return V_29 ;
V_20 -> V_2 = F_36 ( V_6 -> V_31 , V_25 , & V_45 ) ;
if ( F_28 ( V_20 -> V_2 ) ) {
F_26 ( V_6 -> V_31 , L_7 ) ;
return F_33 ( V_20 -> V_2 ) ;
}
F_37 ( V_20 -> V_2 , V_20 ) ;
if ( V_20 -> V_15 )
return F_14 ( V_20 -> V_22 ) ;
else
return F_1 ( V_20 , 1 ) ;
V_49:
if ( ! V_20 -> V_15 )
F_21 ( V_20 -> V_17 ) ;
V_47:
if ( V_20 -> V_22 )
F_22 ( V_20 -> V_22 ) ;
return V_29 ;
}
static int T_2 F_38 ( struct V_50 * V_51 )
{
T_1 V_4 ;
int V_13 ;
V_4 = F_2 ( V_52
| V_53
| V_5 ,
V_52
| V_53
| V_5 ) ;
V_13 = F_3 ( V_51 , V_54 , V_4 ) ;
if ( V_13 )
return V_13 ;
V_4 = F_2 ( V_55 ,
V_55 ) ;
V_13 = F_3 ( V_51 , V_56 , V_4 ) ;
if ( V_13 )
return V_13 ;
V_4 = F_2 ( V_57
| V_58
| V_59 ,
V_60
| V_61
| V_62
| V_59 ) ;
V_13 = F_3 ( V_51 , V_63 , V_4 ) ;
if ( V_13 )
return V_13 ;
V_4 = F_2 ( V_64
| V_65 ,
V_64
| V_65 ) ;
V_13 = F_3 ( V_51 , V_63 , V_4 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_39 ( struct V_66 * V_67 )
{
struct V_68 * V_31 = & V_67 -> V_31 ;
struct V_23 * V_69 ;
struct V_70 * V_70 ;
const struct V_71 * V_72 ;
struct V_24 * V_25 ;
int V_29 ;
V_69 = F_24 ( V_31 , sizeof( * V_69 ) , V_32 ) ;
if ( ! V_69 )
return - V_33 ;
V_72 = F_40 ( V_31 -> V_73 -> V_74 , V_31 ) ;
if ( ! V_72 || ! V_72 -> V_19 ) {
F_26 ( V_31 , L_8 ) ;
return - V_35 ;
}
V_69 -> V_36 = V_72 -> V_19 ;
V_69 -> V_31 = V_31 ;
V_69 -> V_7 = F_41 ( - V_75 ) ;
if ( V_31 -> V_76 && V_31 -> V_76 -> V_77 )
V_69 -> V_7 = F_42 (
V_31 -> V_76 -> V_77 ) ;
if ( F_28 ( V_69 -> V_7 ) )
V_69 -> V_7 = F_43 (
V_31 -> V_77 , L_9 ) ;
if ( F_28 ( V_69 -> V_7 ) ) {
F_26 ( & V_67 -> V_31 , L_10 ) ;
return F_33 ( V_69 -> V_7 ) ;
}
F_44 (dev->of_node, child) {
V_29 = F_23 ( V_69 , V_25 ) ;
if ( V_29 ) {
F_45 ( V_25 ) ;
return V_29 ;
}
}
V_70 = F_46 ( V_31 , V_78 ) ;
return F_47 ( V_70 ) ;
}
static int T_2 F_48 ( void )
{
const struct V_71 * V_72 ;
const struct V_79 * V_19 ;
struct V_24 * V_21 ;
struct V_50 * V_51 ;
int V_13 ;
if ( ! V_40 )
return 0 ;
V_21 = F_49 ( NULL , V_80 ,
& V_72 ) ;
if ( ! V_21 ) {
F_50 ( L_11 , V_81 ) ;
return - V_82 ;
}
F_51 ( L_12 , V_81 , V_72 -> V_83 ) ;
V_19 = V_72 -> V_19 ;
if ( ! V_19 -> V_84 ) {
F_50 ( L_13 ,
V_81 , V_72 -> V_83 ) ;
return - V_82 ;
}
V_51 = F_41 ( - V_75 ) ;
if ( V_21 -> V_76 )
V_51 = F_42 ( V_21 -> V_76 ) ;
if ( F_28 ( V_51 ) )
V_51 = F_43 ( V_21 , L_9 ) ;
if ( F_28 ( V_51 ) ) {
F_50 ( L_14 ,
V_81 , F_33 ( V_51 ) ) ;
return F_33 ( V_51 ) ;
}
V_13 = V_19 -> V_84 ( V_51 ) ;
if ( V_13 ) {
F_50 ( L_15 , V_81 , V_13 ) ;
V_40 = 0 ;
return V_13 ;
}
return 0 ;
}
static int T_2 F_52 ( char * V_85 )
{
V_40 = true ;
return 0 ;
}
