static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return - V_9 ;
F_4 ( & V_7 -> V_10 ,
V_11 + F_5 ( V_12 ) - 1 ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
}
static void F_7 ( struct V_5 * V_6 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_16 ;
struct V_1 * V_7 = V_6 -> V_7 ;
T_1 V_18 ;
if ( V_7 -> V_8 )
return;
V_18 = F_8 ( V_16 -> V_19 , 0 ) ;
F_9 ( L_1 , & V_18 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_11 ( & V_7 -> V_20 ) ;
V_7 -> V_8 = false ;
F_12 ( & V_7 -> V_20 ) ;
F_13 ( & V_6 -> V_17 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_15 ( & V_6 -> V_17 ) ;
F_11 ( & V_7 -> V_20 ) ;
V_7 -> V_8 = true ;
F_12 ( & V_7 -> V_20 ) ;
}
static void F_16 ( unsigned long V_21 )
{
struct V_1 * V_7 = ( void * ) V_21 ;
if ( F_17 ( & V_7 -> V_6 -> V_17 ) )
F_4 ( & V_7 -> V_10 ,
V_11 + F_5 ( V_12 ) - 1 ) ;
}
static T_2 F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_7 = F_19 ( V_23 ) ;
int V_27 ;
F_11 ( & V_7 -> V_20 ) ;
V_27 = sprintf ( V_26 , L_2 , V_7 -> V_28 ) ;
F_12 ( & V_7 -> V_20 ) ;
return V_27 ;
}
static T_2 F_20 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_3 V_29 )
{
struct V_1 * V_7 = F_19 ( V_23 ) ;
int V_30 ;
V_30 = F_21 ( V_26 , 0 , & V_7 -> V_28 ) ;
if ( V_30 )
return V_30 ;
if ( V_7 -> V_28 > 1 )
return - V_31 ;
if ( ! V_7 -> V_32 )
V_7 -> V_32 = (struct V_33 * ) V_34 ;
if ( V_7 -> V_32 != (struct V_33 * ) V_34 ) {
F_9 ( L_3 ) ;
return - V_31 ;
}
F_9 ( L_4 ) ;
F_22 ( V_7 -> V_35 ) ;
return V_29 ;
}
int F_23 ( struct V_36 * V_35 , void * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_7 = F_19 ( V_35 -> V_23 ) ;
struct V_40 * V_41 = V_37 ;
if ( ! V_41 ) {
F_9 ( L_5 ) ;
return - V_31 ;
}
if ( V_41 -> V_42 > 1 ) {
F_9 ( L_6 ) ;
return - V_31 ;
}
if ( V_7 -> V_28 == V_41 -> V_42 ) {
F_9 ( L_7 ) ;
return - V_31 ;
}
if ( V_41 -> V_42 ) {
struct V_33 * V_32 ;
V_32 = (struct V_33 * ) ( unsigned long ) V_41 -> V_33 ;
if ( ! F_24 ( V_32 ) ) {
F_9 ( L_8 ) ;
return - V_31 ;
}
V_7 -> V_32 = F_25 ( V_32 ) ;
if ( ! V_7 -> V_32 ) {
F_9 ( L_9 ) ;
return - V_43 ;
}
} else {
if ( V_7 -> V_32 && V_7 -> V_32 !=
(struct V_33 * ) V_34 ) {
F_26 ( V_7 -> V_32 ) ;
V_7 -> V_32 = NULL ;
}
}
V_7 -> V_28 = V_41 -> V_42 ;
F_22 ( V_7 -> V_35 ) ;
return 0 ;
}
static enum V_44 F_27 ( struct V_45 * V_46 ,
bool V_47 )
{
struct V_1 * V_7 = F_28 ( V_46 ) ;
return V_7 -> V_28 ? V_48 :
V_49 ;
}
static void F_29 ( struct V_45 * V_46 )
{
}
static int F_30 ( struct V_45 * V_46 )
{
struct V_1 * V_7 = F_28 ( V_46 ) ;
struct V_33 * V_33 ;
int V_50 ;
if ( ! V_7 -> V_32 ) {
F_9 ( L_10 ) ;
return - V_51 ;
}
V_50 = ( 1 + V_7 -> V_32 -> V_52 ) * V_53 ;
V_33 = F_31 ( V_7 -> V_32 , V_50 , V_54 ) ;
if ( ! V_33 ) {
F_9 ( L_11 ) ;
return - V_43 ;
}
F_32 ( V_46 , V_33 ) ;
return F_33 ( V_46 , V_33 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_45 * V_46 = & V_7 -> V_46 ;
int V_30 ;
V_46 -> V_55 = V_56 ;
V_30 = F_35 ( V_7 -> V_35 , V_46 ,
& V_57 , V_58 ) ;
if ( V_30 ) {
F_36 ( L_12 ) ;
return V_30 ;
}
F_37 ( V_46 , & V_59 ) ;
F_38 ( V_46 , V_4 ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_4 ,
struct V_60 * V_61 ,
struct V_60 * V_62 )
{
}
static void F_40 ( struct V_2 * V_4 )
{
}
static void F_41 ( struct V_2 * V_4 )
{
}
static int F_42 ( struct V_22 * V_23 , struct V_22 * V_63 , void * V_37 )
{
struct V_1 * V_7 = F_19 ( V_23 ) ;
struct V_36 * V_35 = V_37 ;
struct V_2 * V_4 = & V_7 -> V_4 ;
struct V_13 * V_64 ;
struct V_65 V_66 = { 0 } ;
unsigned int V_67 ;
int V_68 , V_30 ;
V_7 -> V_35 = V_35 ;
V_66 . V_69 = V_70 ;
V_66 . V_71 = F_43 ( V_70 ) ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
V_66 . V_73 = V_67 ;
V_66 . type = V_74 [ V_67 ] ;
V_30 = F_44 ( V_35 , & V_7 -> V_75 [ V_67 ] , V_67 ,
& V_66 ) ;
if ( V_30 )
return V_30 ;
}
V_64 = & V_7 -> V_75 [ V_76 ] ;
V_7 -> V_6 = F_45 ( V_35 , & V_64 -> V_17 ,
V_77 , & V_78 , V_7 ) ;
if ( F_46 ( V_7 -> V_6 ) ) {
F_36 ( L_13 ) ;
return F_47 ( V_7 -> V_6 ) ;
}
V_68 = F_48 ( V_35 ,
V_77 ) ;
if ( V_68 < 0 )
return V_68 ;
V_4 -> V_79 = 1 << V_68 ;
F_9 ( L_14 , V_4 -> V_79 ) ;
F_49 ( V_35 , V_4 , & V_80 ,
V_81 , NULL ) ;
F_50 ( V_4 , & V_82 ) ;
V_30 = F_34 ( V_4 ) ;
if ( V_30 ) {
F_36 ( L_15 , V_30 ) ;
F_51 ( V_4 ) ;
return V_30 ;
}
return 0 ;
}
static void F_52 ( struct V_22 * V_23 , struct V_22 * V_63 , void * V_37 )
{
struct V_1 * V_7 = F_19 ( V_23 ) ;
F_53 ( & V_7 -> V_10 ) ;
}
static int F_54 ( struct V_83 * V_84 )
{
struct V_1 * V_7 ;
int V_30 ;
V_7 = F_55 ( & V_84 -> V_23 , sizeof( * V_7 ) , V_54 ) ;
if ( ! V_7 )
return - V_43 ;
V_7 -> V_84 = V_84 ;
F_56 ( & V_7 -> V_10 , F_16 , ( unsigned long ) V_7 ) ;
F_57 ( & V_7 -> V_20 ) ;
F_58 ( V_84 , V_7 ) ;
V_30 = F_59 ( & V_84 -> V_23 , & V_85 ) ;
if ( V_30 < 0 ) {
F_36 ( L_16 ) ;
return V_30 ;
}
V_30 = F_60 ( & V_84 -> V_23 , & V_86 ) ;
if ( V_30 )
goto V_87;
return V_30 ;
V_87:
F_61 ( & V_84 -> V_23 , & V_85 ) ;
return V_30 ;
}
static int F_62 ( struct V_83 * V_84 )
{
struct V_1 * V_7 = F_63 ( V_84 ) ;
if ( V_7 -> V_32 != (struct V_33 * ) V_34 ) {
F_26 ( V_7 -> V_32 ) ;
V_7 -> V_32 = NULL ;
return - V_31 ;
}
F_64 ( & V_84 -> V_23 , & V_86 ) ;
return 0 ;
}
