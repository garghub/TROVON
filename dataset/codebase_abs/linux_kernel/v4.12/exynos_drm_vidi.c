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
static int F_16 ( struct V_1 * V_7 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 ;
V_7 -> V_22 = V_22 ;
V_7 -> V_26 = V_24 -> V_26 ++ ;
return 0 ;
}
static void F_17 ( unsigned long V_27 )
{
struct V_1 * V_7 = ( void * ) V_27 ;
if ( V_7 -> V_26 < 0 )
return;
if ( F_18 ( & V_7 -> V_6 -> V_17 ) )
F_4 ( & V_7 -> V_10 ,
V_11 + F_5 ( V_12 ) - 1 ) ;
}
static T_2 F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
int V_33 ;
F_11 ( & V_7 -> V_20 ) ;
V_33 = sprintf ( V_32 , L_2 , V_7 -> V_34 ) ;
F_12 ( & V_7 -> V_20 ) ;
return V_33 ;
}
static T_2 F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_35 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
int V_36 ;
V_36 = F_22 ( V_32 , 0 , & V_7 -> V_34 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_34 > 1 )
return - V_37 ;
if ( ! V_7 -> V_38 )
V_7 -> V_38 = (struct V_39 * ) V_40 ;
if ( V_7 -> V_38 != (struct V_39 * ) V_40 ) {
F_9 ( L_3 ) ;
return - V_37 ;
}
F_9 ( L_4 ) ;
F_23 ( V_7 -> V_22 ) ;
return V_35 ;
}
int F_24 ( struct V_21 * V_22 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_7 = F_20 ( V_22 -> V_29 ) ;
struct V_44 * V_45 = V_41 ;
if ( ! V_45 ) {
F_9 ( L_5 ) ;
return - V_37 ;
}
if ( V_45 -> V_46 > 1 ) {
F_9 ( L_6 ) ;
return - V_37 ;
}
if ( V_7 -> V_34 == V_45 -> V_46 ) {
F_9 ( L_7 ) ;
return - V_37 ;
}
if ( V_45 -> V_46 ) {
struct V_39 * V_38 ;
V_38 = (struct V_39 * ) ( unsigned long ) V_45 -> V_39 ;
if ( ! F_25 ( V_38 ) ) {
F_9 ( L_8 ) ;
return - V_37 ;
}
V_7 -> V_38 = F_26 ( V_38 ) ;
if ( ! V_7 -> V_38 ) {
F_9 ( L_9 ) ;
return - V_47 ;
}
} else {
if ( V_7 -> V_38 && V_7 -> V_38 !=
(struct V_39 * ) V_40 ) {
F_27 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
}
}
V_7 -> V_34 = V_45 -> V_46 ;
F_23 ( V_7 -> V_22 ) ;
return 0 ;
}
static enum V_48 F_28 ( struct V_49 * V_50 ,
bool V_51 )
{
struct V_1 * V_7 = F_29 ( V_50 ) ;
return V_7 -> V_34 ? V_52 :
V_53 ;
}
static void F_30 ( struct V_49 * V_50 )
{
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_1 * V_7 = F_29 ( V_50 ) ;
struct V_39 * V_39 ;
int V_54 ;
if ( ! V_7 -> V_38 ) {
F_9 ( L_10 ) ;
return - V_55 ;
}
V_54 = ( 1 + V_7 -> V_38 -> V_56 ) * V_57 ;
V_39 = F_32 ( V_7 -> V_38 , V_54 , V_58 ) ;
if ( ! V_39 ) {
F_9 ( L_11 ) ;
return - V_47 ;
}
F_33 ( V_50 , V_39 ) ;
return F_34 ( V_50 , V_39 ) ;
}
static int F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_49 * V_50 = & V_7 -> V_50 ;
int V_36 ;
V_50 -> V_59 = V_60 ;
V_36 = F_36 ( V_7 -> V_22 , V_50 ,
& V_61 , V_62 ) ;
if ( V_36 ) {
F_37 ( L_12 ) ;
return V_36 ;
}
F_38 ( V_50 , & V_63 ) ;
F_39 ( V_50 , V_4 ) ;
return 0 ;
}
static void F_40 ( struct V_2 * V_4 ,
struct V_64 * V_65 ,
struct V_64 * V_66 )
{
}
static void F_41 ( struct V_2 * V_4 )
{
}
static void F_42 ( struct V_2 * V_4 )
{
}
static int F_43 ( struct V_28 * V_29 , struct V_28 * V_67 , void * V_41 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
struct V_21 * V_22 = V_41 ;
struct V_2 * V_4 = & V_7 -> V_4 ;
struct V_13 * V_68 ;
struct V_69 V_70 = { 0 } ;
unsigned int V_71 ;
int V_26 , V_36 ;
F_16 ( V_7 , V_22 ) ;
V_70 . V_72 = V_73 ;
V_70 . V_74 = F_44 ( V_73 ) ;
for ( V_71 = 0 ; V_71 < V_75 ; V_71 ++ ) {
V_70 . V_76 = V_71 ;
V_70 . type = V_77 [ V_71 ] ;
V_36 = F_45 ( V_22 , & V_7 -> V_78 [ V_71 ] , V_71 ,
1 << V_7 -> V_26 , & V_70 ) ;
if ( V_36 )
return V_36 ;
}
V_68 = & V_7 -> V_78 [ V_79 ] ;
V_7 -> V_6 = F_46 ( V_22 , & V_68 -> V_17 ,
V_7 -> V_26 , V_80 ,
& V_81 , V_7 ) ;
if ( F_47 ( V_7 -> V_6 ) ) {
F_37 ( L_13 ) ;
return F_48 ( V_7 -> V_6 ) ;
}
V_26 = F_49 ( V_22 ,
V_80 ) ;
if ( V_26 < 0 )
return V_26 ;
V_4 -> V_82 = 1 << V_26 ;
F_9 ( L_14 , V_4 -> V_82 ) ;
F_50 ( V_22 , V_4 , & V_83 ,
V_84 , NULL ) ;
F_51 ( V_4 , & V_85 ) ;
V_36 = F_35 ( V_4 ) ;
if ( V_36 ) {
F_37 ( L_15 , V_36 ) ;
F_52 ( V_4 ) ;
return V_36 ;
}
return 0 ;
}
static void F_53 ( struct V_28 * V_29 , struct V_28 * V_67 , void * V_41 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
F_54 ( & V_7 -> V_10 ) ;
}
static int F_55 ( struct V_86 * V_87 )
{
struct V_1 * V_7 ;
int V_36 ;
V_7 = F_56 ( & V_87 -> V_29 , sizeof( * V_7 ) , V_58 ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_87 = V_87 ;
F_57 ( & V_7 -> V_10 , F_17 , ( unsigned long ) V_7 ) ;
F_58 ( & V_7 -> V_20 ) ;
F_59 ( V_87 , V_7 ) ;
V_36 = F_60 ( & V_87 -> V_29 , & V_88 ) ;
if ( V_36 < 0 ) {
F_37 ( L_16 ) ;
return V_36 ;
}
V_36 = F_61 ( & V_87 -> V_29 , & V_89 ) ;
if ( V_36 )
goto V_90;
return V_36 ;
V_90:
F_62 ( & V_87 -> V_29 , & V_88 ) ;
return V_36 ;
}
static int F_63 ( struct V_86 * V_87 )
{
struct V_1 * V_7 = F_64 ( V_87 ) ;
if ( V_7 -> V_38 != (struct V_39 * ) V_40 ) {
F_27 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
return - V_37 ;
}
F_65 ( & V_87 -> V_29 , & V_89 ) ;
return 0 ;
}
