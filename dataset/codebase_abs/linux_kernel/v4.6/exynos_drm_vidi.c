static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return - V_9 ;
if ( ! F_4 ( 0 , & V_7 -> V_10 ) )
V_7 -> V_11 = true ;
V_7 -> V_12 = true ;
F_5 ( & V_7 -> V_13 ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
V_7 -> V_11 = false ;
}
static void F_8 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_17 ;
struct V_1 * V_7 = V_6 -> V_7 ;
T_1 V_19 ;
if ( V_7 -> V_8 )
return;
V_19 = F_9 ( V_17 -> V_20 , 0 ) ;
F_10 ( L_1 , & V_19 ) ;
if ( V_7 -> V_11 )
F_5 ( & V_7 -> V_13 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_12 ( & V_7 -> V_21 ) ;
V_7 -> V_8 = false ;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
F_3 ( V_7 -> V_6 ) ;
F_13 ( & V_7 -> V_21 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_12 ( & V_7 -> V_21 ) ;
V_7 -> V_8 = true ;
F_13 ( & V_7 -> V_21 ) ;
}
static int F_15 ( struct V_1 * V_7 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_27 = V_25 -> V_27 ++ ;
return 0 ;
}
static void F_16 ( struct V_28 * V_13 )
{
struct V_1 * V_7 = F_2 ( V_13 , struct V_1 ,
V_13 ) ;
int V_29 ;
if ( V_7 -> V_27 < 0 )
return;
F_17 ( 16000 , 20000 ) ;
F_12 ( & V_7 -> V_21 ) ;
if ( V_7 -> V_12 ) {
F_18 ( & V_7 -> V_6 -> V_18 ) ;
V_7 -> V_12 = false ;
F_13 ( & V_7 -> V_21 ) ;
return;
}
F_13 ( & V_7 -> V_21 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
struct V_14 * V_15 = & V_7 -> V_31 [ V_29 ] ;
if ( ! V_15 -> V_32 )
continue;
F_19 ( V_7 -> V_6 , V_15 ) ;
}
}
static T_2 F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_1 * V_7 = F_21 ( V_34 ) ;
int V_38 ;
F_12 ( & V_7 -> V_21 ) ;
V_38 = sprintf ( V_37 , L_2 , V_7 -> V_39 ) ;
F_13 ( & V_7 -> V_21 ) ;
return V_38 ;
}
static T_2 F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_40 )
{
struct V_1 * V_7 = F_21 ( V_34 ) ;
int V_41 ;
V_41 = F_23 ( V_37 , 0 , & V_7 -> V_39 ) ;
if ( V_41 )
return V_41 ;
if ( V_7 -> V_39 > 1 )
return - V_42 ;
if ( ! V_7 -> V_43 )
V_7 -> V_43 = (struct V_44 * ) V_45 ;
if ( V_7 -> V_43 != (struct V_44 * ) V_45 ) {
F_10 ( L_3 ) ;
return - V_42 ;
}
F_10 ( L_4 ) ;
F_24 ( V_7 -> V_23 ) ;
return V_40 ;
}
int F_25 ( struct V_22 * V_23 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_7 = F_21 ( V_23 -> V_34 ) ;
struct V_49 * V_50 = V_46 ;
if ( ! V_50 ) {
F_10 ( L_5 ) ;
return - V_42 ;
}
if ( V_50 -> V_51 > 1 ) {
F_10 ( L_6 ) ;
return - V_42 ;
}
if ( V_7 -> V_39 == V_50 -> V_51 ) {
F_10 ( L_7 ) ;
return - V_42 ;
}
if ( V_50 -> V_51 ) {
struct V_44 * V_43 ;
V_43 = (struct V_44 * ) ( unsigned long ) V_50 -> V_44 ;
if ( ! F_26 ( V_43 ) ) {
F_10 ( L_8 ) ;
return - V_42 ;
}
V_7 -> V_43 = F_27 ( V_43 ) ;
if ( ! V_7 -> V_43 ) {
F_10 ( L_9 ) ;
return - V_52 ;
}
} else {
if ( V_7 -> V_43 && V_7 -> V_43 !=
(struct V_44 * ) V_45 ) {
F_28 ( V_7 -> V_43 ) ;
V_7 -> V_43 = NULL ;
}
}
V_7 -> V_39 = V_50 -> V_51 ;
F_24 ( V_7 -> V_23 ) ;
return 0 ;
}
static enum V_53 F_29 ( struct V_54 * V_55 ,
bool V_56 )
{
struct V_1 * V_7 = F_30 ( V_55 ) ;
return V_7 -> V_39 ? V_57 :
V_58 ;
}
static void F_31 ( struct V_54 * V_55 )
{
}
static int F_32 ( struct V_54 * V_55 )
{
struct V_1 * V_7 = F_30 ( V_55 ) ;
struct V_44 * V_44 ;
int V_59 ;
if ( ! V_7 -> V_43 ) {
F_10 ( L_10 ) ;
return - V_60 ;
}
V_59 = ( 1 + V_7 -> V_43 -> V_61 ) * V_62 ;
V_44 = F_33 ( V_7 -> V_43 , V_59 , V_63 ) ;
if ( ! V_44 ) {
F_10 ( L_11 ) ;
return - V_52 ;
}
F_34 ( V_55 , V_44 ) ;
return F_35 ( V_55 , V_44 ) ;
}
static struct V_2 * F_36 ( struct V_54 * V_55 )
{
struct V_1 * V_7 = F_30 ( V_55 ) ;
return & V_7 -> V_4 ;
}
static int F_37 ( struct V_2 * V_4 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_54 * V_55 = & V_7 -> V_55 ;
int V_41 ;
V_55 -> V_64 = V_65 ;
V_41 = F_38 ( V_7 -> V_23 , V_55 ,
& V_66 , V_67 ) ;
if ( V_41 ) {
F_39 ( L_12 ) ;
return V_41 ;
}
F_40 ( V_55 , & V_68 ) ;
F_41 ( V_55 ) ;
F_42 ( V_55 , V_4 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_4 ,
struct V_69 * V_70 ,
struct V_69 * V_71 )
{
}
static void F_44 ( struct V_2 * V_4 )
{
}
static void F_45 ( struct V_2 * V_4 )
{
}
static int F_46 ( struct V_33 * V_34 , struct V_33 * V_72 , void * V_46 )
{
struct V_1 * V_7 = F_21 ( V_34 ) ;
struct V_22 * V_23 = V_46 ;
struct V_2 * V_4 = & V_7 -> V_4 ;
struct V_14 * V_73 ;
struct V_74 V_75 = { 0 } ;
unsigned int V_76 ;
int V_27 , V_41 ;
F_15 ( V_7 , V_23 ) ;
V_75 . V_77 = V_78 ;
V_75 . V_79 = F_47 ( V_78 ) ;
for ( V_76 = 0 ; V_76 < V_30 ; V_76 ++ ) {
V_75 . V_80 = V_76 ;
V_75 . type = V_81 [ V_76 ] ;
V_41 = F_48 ( V_23 , & V_7 -> V_31 [ V_76 ] , V_76 ,
1 << V_7 -> V_27 , & V_75 ) ;
if ( V_41 )
return V_41 ;
}
V_73 = & V_7 -> V_31 [ V_82 ] ;
V_7 -> V_6 = F_49 ( V_23 , & V_73 -> V_18 ,
V_7 -> V_27 , V_83 ,
& V_84 , V_7 ) ;
if ( F_50 ( V_7 -> V_6 ) ) {
F_39 ( L_13 ) ;
return F_51 ( V_7 -> V_6 ) ;
}
V_27 = F_52 ( V_23 ,
V_83 ) ;
if ( V_27 < 0 )
return V_27 ;
V_4 -> V_85 = 1 << V_27 ;
F_10 ( L_14 , V_4 -> V_85 ) ;
F_53 ( V_23 , V_4 , & V_86 ,
V_87 , NULL ) ;
F_54 ( V_4 , & V_88 ) ;
V_41 = F_37 ( V_4 ) ;
if ( V_41 ) {
F_39 ( L_15 , V_41 ) ;
F_55 ( V_4 ) ;
return V_41 ;
}
return 0 ;
}
static void F_56 ( struct V_33 * V_34 , struct V_33 * V_72 , void * V_46 )
{
}
static int F_57 ( struct V_89 * V_90 )
{
struct V_1 * V_7 ;
int V_41 ;
V_7 = F_58 ( & V_90 -> V_34 , sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 )
return - V_52 ;
V_7 -> V_90 = V_90 ;
F_59 ( & V_7 -> V_13 , F_16 ) ;
F_60 ( & V_7 -> V_21 ) ;
F_61 ( V_90 , V_7 ) ;
V_41 = F_62 ( & V_90 -> V_34 , & V_91 ) ;
if ( V_41 < 0 ) {
F_39 ( L_16 ) ;
return V_41 ;
}
V_41 = F_63 ( & V_90 -> V_34 , & V_92 ) ;
if ( V_41 )
goto V_93;
return V_41 ;
V_93:
F_64 ( & V_90 -> V_34 , & V_91 ) ;
return V_41 ;
}
static int F_65 ( struct V_89 * V_90 )
{
struct V_1 * V_7 = F_66 ( V_90 ) ;
if ( V_7 -> V_43 != (struct V_44 * ) V_45 ) {
F_28 ( V_7 -> V_43 ) ;
V_7 -> V_43 = NULL ;
return - V_42 ;
}
F_67 ( & V_90 -> V_34 , & V_92 ) ;
return 0 ;
}
