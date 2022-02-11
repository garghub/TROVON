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
if ( V_2 -> V_13 )
F_7 ( V_2 -> V_13 ) ;
F_1 ( V_2 , 1 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ,
struct V_1 ,
V_12 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ,
struct V_1 ,
V_12 ) ;
int V_14 ;
T_1 V_4 ;
V_14 = F_10 ( V_2 -> V_6 -> V_7 , V_2 -> V_8 , & V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
return ( V_4 & V_5 ) ? 0 : 1 ;
}
static int F_11 ( struct V_2 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
if ( V_2 -> V_16 )
return - V_17 ;
F_13 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
if ( V_2 -> V_16 )
return - V_17 ;
if ( V_2 -> V_13 ) {
int V_14 ;
V_14 = F_15 ( V_2 -> V_13 ) ;
if ( V_14 )
return V_14 ;
}
return F_16 ( V_2 -> V_18 ) ;
}
static int F_17 ( struct V_2 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
if ( V_2 -> V_19 ) {
F_18 ( V_2 -> V_19 ) ;
F_19 ( 10 ) ;
F_20 ( V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_21 ( void * V_20 )
{
struct V_1 * V_21 = V_20 ;
if ( ! V_21 -> V_16 ) {
F_22 ( V_21 -> V_22 ) ;
F_23 ( V_21 -> V_18 ) ;
}
if ( V_21 -> V_23 )
F_24 ( V_21 -> V_23 ) ;
}
static int F_25 ( struct V_24 * V_6 ,
struct V_25 * V_26 )
{
struct V_1 * V_21 ;
unsigned int V_8 ;
const char * V_27 ;
struct V_28 V_29 ;
int V_30 , V_31 ;
V_21 = F_26 ( V_6 -> V_32 , sizeof( * V_21 ) , V_33 ) ;
if ( ! V_21 )
return - V_34 ;
V_21 -> V_6 = V_6 ;
V_21 -> V_22 = V_26 ;
if ( F_27 ( V_26 , L_1 , & V_8 ) ) {
F_28 ( V_6 -> V_32 , L_2 ,
V_26 -> V_35 ) ;
return - V_36 ;
}
V_21 -> V_19 = F_29 ( V_26 , L_3 ) ;
if ( F_30 ( V_21 -> V_19 ) )
V_21 -> V_19 = NULL ;
V_21 -> V_8 = V_8 ;
V_21 -> V_23 = F_31 ( V_26 , L_4 ) ;
if ( F_30 ( V_21 -> V_23 ) )
V_21 -> V_23 = NULL ;
V_31 = 0 ;
V_29 . V_35 = NULL ;
while ( V_6 -> V_37 -> V_38 [ V_31 ] . V_39 ) {
if ( V_6 -> V_37 -> V_38 [ V_31 ] . V_39 == V_8 ) {
V_29 . V_35 = V_6 -> V_37 -> V_38 [ V_31 ] . V_40 ;
break;
}
V_31 ++ ;
}
if ( ! V_29 . V_35 ) {
F_28 ( V_6 -> V_32 , L_5 ) ;
return - V_36 ;
}
if ( V_41 && V_6 -> V_37 -> V_42 == V_31 ) {
F_32 ( V_6 -> V_32 , L_6 , V_31 ) ;
V_21 -> V_16 = true ;
} else {
if ( V_21 -> V_23 ) {
V_27 = F_33 ( V_21 -> V_23 ) ;
V_29 . V_43 = 0 ;
V_29 . V_44 = & V_27 ;
V_29 . V_45 = 1 ;
} else {
V_29 . V_43 = 0 ;
V_29 . V_44 = NULL ;
V_29 . V_45 = 0 ;
}
V_29 . V_46 = & V_47 ;
V_21 -> V_12 . V_29 = & V_29 ;
V_21 -> V_18 = F_34 ( V_6 -> V_32 , & V_21 -> V_12 ) ;
if ( F_30 ( V_21 -> V_18 ) ) {
V_30 = F_35 ( V_21 -> V_18 ) ;
goto V_48;
}
V_30 = F_36 ( V_26 , V_49 ,
V_21 -> V_18 ) ;
if ( V_30 < 0 )
goto V_50;
}
V_30 = F_37 ( V_6 -> V_32 , F_21 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
V_21 -> V_2 = F_38 ( V_6 -> V_32 , V_26 , & V_46 ) ;
if ( F_30 ( V_21 -> V_2 ) ) {
F_28 ( V_6 -> V_32 , L_7 ) ;
return F_35 ( V_21 -> V_2 ) ;
}
F_39 ( V_21 -> V_2 , V_21 ) ;
V_21 -> V_13 = F_40 ( & V_21 -> V_2 -> V_32 , L_8 ) ;
if ( F_30 ( V_21 -> V_13 ) ) {
if ( F_35 ( V_21 -> V_13 ) == - V_51 )
return F_35 ( V_21 -> V_13 ) ;
V_21 -> V_13 = NULL ;
}
if ( V_21 -> V_16 )
return F_16 ( V_21 -> V_23 ) ;
else
return F_1 ( V_21 , 1 ) ;
V_50:
if ( ! V_21 -> V_16 )
F_23 ( V_21 -> V_18 ) ;
V_48:
if ( V_21 -> V_23 )
F_24 ( V_21 -> V_23 ) ;
return V_30 ;
}
static int T_2 F_41 ( struct V_52 * V_53 )
{
T_1 V_4 ;
int V_14 ;
V_4 = F_2 ( V_54
| V_55
| V_5 ,
V_54
| V_55
| V_5 ) ;
V_14 = F_3 ( V_53 , V_56 , V_4 ) ;
if ( V_14 )
return V_14 ;
V_4 = F_2 ( V_57 ,
V_57 ) ;
V_14 = F_3 ( V_53 , V_58 , V_4 ) ;
if ( V_14 )
return V_14 ;
V_4 = F_2 ( V_59
| V_60
| V_61 ,
V_62
| V_63
| V_64
| V_61 ) ;
V_14 = F_3 ( V_53 , V_65 , V_4 ) ;
if ( V_14 )
return V_14 ;
V_4 = F_2 ( V_66
| V_67 ,
V_66
| V_67 ) ;
V_14 = F_3 ( V_53 , V_65 , V_4 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_42 ( struct V_68 * V_69 )
{
struct V_70 * V_32 = & V_69 -> V_32 ;
struct V_24 * V_71 ;
struct V_72 * V_72 ;
const struct V_73 * V_74 ;
struct V_25 * V_26 ;
int V_30 ;
V_71 = F_26 ( V_32 , sizeof( * V_71 ) , V_33 ) ;
if ( ! V_71 )
return - V_34 ;
V_74 = F_43 ( V_32 -> V_75 -> V_76 , V_32 ) ;
if ( ! V_74 || ! V_74 -> V_20 ) {
F_28 ( V_32 , L_9 ) ;
return - V_36 ;
}
V_71 -> V_37 = V_74 -> V_20 ;
V_71 -> V_32 = V_32 ;
V_71 -> V_7 = F_44 ( - V_77 ) ;
if ( V_32 -> V_78 && V_32 -> V_78 -> V_79 )
V_71 -> V_7 = F_45 (
V_32 -> V_78 -> V_79 ) ;
if ( F_30 ( V_71 -> V_7 ) )
V_71 -> V_7 = F_46 (
V_32 -> V_79 , L_10 ) ;
if ( F_30 ( V_71 -> V_7 ) ) {
F_28 ( & V_69 -> V_32 , L_11 ) ;
return F_35 ( V_71 -> V_7 ) ;
}
F_47 (dev->of_node, child) {
V_30 = F_25 ( V_71 , V_26 ) ;
if ( V_30 ) {
F_48 ( V_26 ) ;
return V_30 ;
}
}
V_72 = F_49 ( V_32 , V_80 ) ;
return F_50 ( V_72 ) ;
}
static int T_2 F_51 ( void )
{
const struct V_73 * V_74 ;
const struct V_81 * V_20 ;
struct V_25 * V_22 ;
struct V_52 * V_53 ;
int V_14 ;
if ( ! V_41 )
return 0 ;
V_22 = F_52 ( NULL , V_82 ,
& V_74 ) ;
if ( ! V_22 ) {
F_53 ( L_12 , V_83 ) ;
return - V_84 ;
}
F_54 ( L_13 , V_83 , V_74 -> V_85 ) ;
V_20 = V_74 -> V_20 ;
if ( ! V_20 -> V_86 ) {
F_53 ( L_14 ,
V_83 , V_74 -> V_85 ) ;
return - V_84 ;
}
V_53 = F_44 ( - V_77 ) ;
if ( V_22 -> V_78 )
V_53 = F_45 ( V_22 -> V_78 ) ;
if ( F_30 ( V_53 ) )
V_53 = F_46 ( V_22 , L_10 ) ;
if ( F_30 ( V_53 ) ) {
F_53 ( L_15 ,
V_83 , F_35 ( V_53 ) ) ;
return F_35 ( V_53 ) ;
}
V_14 = V_20 -> V_86 ( V_53 ) ;
if ( V_14 ) {
F_53 ( L_16 , V_83 , V_14 ) ;
V_41 = 0 ;
return V_14 ;
}
return 0 ;
}
static int T_2 F_55 ( char * V_87 )
{
V_41 = true ;
return 0 ;
}
