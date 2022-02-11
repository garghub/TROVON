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
static void F_15 ( void * V_18 )
{
struct V_1 * V_19 = V_18 ;
if ( ! V_19 -> V_15 ) {
F_16 ( V_19 -> V_20 ) ;
F_17 ( V_19 -> V_17 ) ;
}
if ( V_19 -> V_21 )
F_18 ( V_19 -> V_21 ) ;
}
static int F_19 ( struct V_22 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_19 ;
unsigned int V_8 ;
const char * V_25 ;
struct V_26 V_27 ;
int V_28 , V_29 ;
V_19 = F_20 ( V_6 -> V_30 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 )
return - V_32 ;
V_19 -> V_6 = V_6 ;
V_19 -> V_20 = V_24 ;
if ( F_21 ( V_24 , L_1 , & V_8 ) ) {
F_22 ( V_6 -> V_30 , L_2 ,
V_24 -> V_33 ) ;
return - V_34 ;
}
V_19 -> V_8 = V_8 ;
V_19 -> V_21 = F_23 ( V_24 , L_3 ) ;
if ( F_24 ( V_19 -> V_21 ) )
V_19 -> V_21 = NULL ;
V_29 = 0 ;
V_27 . V_33 = NULL ;
while ( V_6 -> V_35 -> V_36 [ V_29 ] . V_37 ) {
if ( V_6 -> V_35 -> V_36 [ V_29 ] . V_37 == V_8 ) {
V_27 . V_33 = V_6 -> V_35 -> V_36 [ V_29 ] . V_38 ;
break;
}
V_29 ++ ;
}
if ( ! V_27 . V_33 ) {
F_22 ( V_6 -> V_30 , L_4 ) ;
return - V_34 ;
}
if ( V_39 && V_6 -> V_35 -> V_40 == V_29 ) {
F_25 ( V_6 -> V_30 , L_5 , V_29 ) ;
V_19 -> V_15 = true ;
} else {
if ( V_19 -> V_21 ) {
V_25 = F_26 ( V_19 -> V_21 ) ;
V_27 . V_41 = 0 ;
V_27 . V_42 = & V_25 ;
V_27 . V_43 = 1 ;
} else {
V_27 . V_41 = 0 ;
V_27 . V_42 = NULL ;
V_27 . V_43 = 0 ;
}
V_27 . V_44 = & V_45 ;
V_19 -> V_12 . V_27 = & V_27 ;
V_19 -> V_17 = F_27 ( V_6 -> V_30 , & V_19 -> V_12 ) ;
if ( F_24 ( V_19 -> V_17 ) ) {
V_28 = F_28 ( V_19 -> V_17 ) ;
goto V_46;
}
V_28 = F_29 ( V_24 , V_47 ,
V_19 -> V_17 ) ;
if ( V_28 < 0 )
goto V_48;
}
V_28 = F_30 ( V_6 -> V_30 , F_15 , V_19 ) ;
if ( V_28 )
goto V_49;
V_19 -> V_2 = F_31 ( V_6 -> V_30 , V_24 , & V_44 ) ;
if ( F_24 ( V_19 -> V_2 ) ) {
F_22 ( V_6 -> V_30 , L_6 ) ;
return F_28 ( V_19 -> V_2 ) ;
}
F_32 ( V_19 -> V_2 , V_19 ) ;
if ( V_19 -> V_15 )
return F_14 ( V_19 -> V_21 ) ;
else
return F_1 ( V_19 , 1 ) ;
V_49:
if ( ! V_19 -> V_15 )
F_16 ( V_24 ) ;
V_48:
if ( ! V_19 -> V_15 )
F_17 ( V_19 -> V_17 ) ;
V_46:
if ( V_19 -> V_21 )
F_18 ( V_19 -> V_21 ) ;
return V_28 ;
}
static int T_2 F_33 ( struct V_50 * V_51 )
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
static int F_34 ( struct V_66 * V_67 )
{
struct V_68 * V_30 = & V_67 -> V_30 ;
struct V_22 * V_69 ;
struct V_70 * V_70 ;
const struct V_71 * V_72 ;
struct V_23 * V_24 ;
int V_28 ;
V_69 = F_20 ( V_30 , sizeof( * V_69 ) , V_31 ) ;
if ( ! V_69 )
return - V_32 ;
V_72 = F_35 ( V_30 -> V_73 -> V_74 , V_30 ) ;
if ( ! V_72 || ! V_72 -> V_18 ) {
F_22 ( V_30 , L_7 ) ;
return - V_34 ;
}
V_69 -> V_35 = V_72 -> V_18 ;
V_69 -> V_30 = V_30 ;
V_69 -> V_7 = F_36 ( V_30 -> V_75 ,
L_8 ) ;
if ( F_24 ( V_69 -> V_7 ) ) {
F_22 ( & V_67 -> V_30 , L_9 ) ;
return F_28 ( V_69 -> V_7 ) ;
}
F_37 (dev->of_node, child) {
V_28 = F_19 ( V_69 , V_24 ) ;
if ( V_28 ) {
F_38 ( V_24 ) ;
return V_28 ;
}
}
V_70 = F_39 ( V_30 , V_76 ) ;
return F_40 ( V_70 ) ;
}
static int T_2 F_41 ( void )
{
const struct V_71 * V_72 ;
const struct V_77 * V_18 ;
struct V_23 * V_20 ;
struct V_50 * V_51 ;
int V_13 ;
if ( ! V_39 )
return 0 ;
V_20 = F_42 ( NULL , V_78 ,
& V_72 ) ;
if ( ! V_20 ) {
F_43 ( L_10 , V_79 ) ;
return - V_80 ;
}
F_44 ( L_11 , V_79 , V_72 -> V_81 ) ;
V_18 = V_72 -> V_18 ;
if ( ! V_18 -> V_82 ) {
F_43 ( L_12 ,
V_79 , V_72 -> V_81 ) ;
return - V_80 ;
}
V_51 = F_36 ( V_20 , L_8 ) ;
if ( F_24 ( V_51 ) ) {
F_43 ( L_13 ,
V_79 , F_28 ( V_51 ) ) ;
return F_28 ( V_51 ) ;
}
V_13 = V_18 -> V_82 ( V_51 ) ;
if ( V_13 ) {
F_43 ( L_14 , V_79 , V_13 ) ;
V_39 = 0 ;
return V_13 ;
}
return 0 ;
}
static int T_2 F_45 ( char * V_83 )
{
V_39 = true ;
return 0 ;
}
