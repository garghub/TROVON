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
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return;
F_9 ( L_1 , V_15 -> V_16 ) ;
if ( V_7 -> V_11 )
F_5 ( & V_7 -> V_13 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_11 ( & V_7 -> V_17 ) ;
V_7 -> V_8 = false ;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
F_3 ( V_7 -> V_6 ) ;
F_12 ( & V_7 -> V_17 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_11 ( & V_7 -> V_17 ) ;
V_7 -> V_8 = true ;
F_12 ( & V_7 -> V_17 ) ;
}
static int F_14 ( struct V_1 * V_7 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
V_7 -> V_19 = V_19 ;
V_7 -> V_23 = V_21 -> V_23 ++ ;
return 0 ;
}
static void F_15 ( struct V_24 * V_13 )
{
struct V_1 * V_7 = F_2 ( V_13 , struct V_1 ,
V_13 ) ;
int V_25 ;
if ( V_7 -> V_23 < 0 )
return;
F_16 ( 16000 , 20000 ) ;
F_11 ( & V_7 -> V_17 ) ;
if ( V_7 -> V_12 ) {
F_17 ( & V_7 -> V_6 -> V_26 ) ;
V_7 -> V_12 = false ;
F_12 ( & V_7 -> V_17 ) ;
return;
}
F_12 ( & V_7 -> V_17 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
struct V_14 * V_15 = & V_7 -> V_28 [ V_25 ] ;
if ( ! V_15 -> V_29 )
continue;
F_18 ( V_7 -> V_6 , V_15 ) ;
}
}
static int F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_1 * V_7 = F_20 ( V_31 ) ;
int V_35 ;
F_11 ( & V_7 -> V_17 ) ;
V_35 = sprintf ( V_34 , L_2 , V_7 -> V_36 ) ;
F_12 ( & V_7 -> V_17 ) ;
return V_35 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_1 V_37 )
{
struct V_1 * V_7 = F_20 ( V_31 ) ;
int V_38 ;
V_38 = F_22 ( V_34 , 0 , & V_7 -> V_36 ) ;
if ( V_38 )
return V_38 ;
if ( V_7 -> V_36 > 1 )
return - V_39 ;
if ( ! V_7 -> V_40 )
V_7 -> V_40 = (struct V_41 * ) V_42 ;
if ( V_7 -> V_40 != (struct V_41 * ) V_42 ) {
F_9 ( L_3 ) ;
return - V_39 ;
}
F_9 ( L_4 ) ;
F_23 ( V_7 -> V_19 ) ;
return V_37 ;
}
int F_24 ( struct V_18 * V_19 , void * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_7 = F_20 ( V_19 -> V_31 ) ;
struct V_46 * V_47 = V_43 ;
if ( ! V_47 ) {
F_9 ( L_5 ) ;
return - V_39 ;
}
if ( V_47 -> V_48 > 1 ) {
F_9 ( L_6 ) ;
return - V_39 ;
}
if ( V_7 -> V_36 == V_47 -> V_48 ) {
F_9 ( L_7 ) ;
return - V_39 ;
}
if ( V_47 -> V_48 ) {
struct V_41 * V_40 = (struct V_41 * ) ( V_49 ) V_47 -> V_41 ;
if ( ! F_25 ( V_40 ) ) {
F_9 ( L_8 ) ;
return - V_39 ;
}
V_7 -> V_40 = F_26 ( V_40 ) ;
if ( ! V_7 -> V_40 ) {
F_9 ( L_9 ) ;
return - V_50 ;
}
} else {
if ( V_7 -> V_40 && V_7 -> V_40 !=
(struct V_41 * ) V_42 ) {
F_27 ( V_7 -> V_40 ) ;
V_7 -> V_40 = NULL ;
}
}
V_7 -> V_36 = V_47 -> V_48 ;
F_23 ( V_7 -> V_19 ) ;
return 0 ;
}
static enum V_51 F_28 ( struct V_52 * V_53 ,
bool V_54 )
{
struct V_1 * V_7 = F_29 ( V_53 ) ;
return V_7 -> V_36 ? V_55 :
V_56 ;
}
static void F_30 ( struct V_52 * V_53 )
{
}
static int F_31 ( struct V_52 * V_53 )
{
struct V_1 * V_7 = F_29 ( V_53 ) ;
struct V_41 * V_41 ;
int V_57 ;
if ( ! V_7 -> V_40 ) {
F_9 ( L_10 ) ;
return - V_58 ;
}
V_57 = ( 1 + V_7 -> V_40 -> V_59 ) * V_60 ;
V_41 = F_32 ( V_7 -> V_40 , V_57 , V_61 ) ;
if ( ! V_41 ) {
F_9 ( L_11 ) ;
return - V_50 ;
}
F_33 ( V_53 , V_41 ) ;
return F_34 ( V_53 , V_41 ) ;
}
static struct V_2 * F_35 ( struct V_52 * V_53 )
{
struct V_1 * V_7 = F_29 ( V_53 ) ;
return & V_7 -> V_4 ;
}
static int F_36 ( struct V_2 * V_4 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_52 * V_53 = & V_7 -> V_53 ;
int V_38 ;
V_53 -> V_62 = V_63 ;
V_38 = F_37 ( V_7 -> V_19 , V_53 ,
& V_64 , V_65 ) ;
if ( V_38 ) {
F_38 ( L_12 ) ;
return V_38 ;
}
F_39 ( V_53 , & V_66 ) ;
F_40 ( V_53 ) ;
F_41 ( V_53 , V_4 ) ;
return 0 ;
}
static bool F_42 ( struct V_2 * V_4 ,
const struct V_67 * V_68 ,
struct V_67 * V_69 )
{
return true ;
}
static void F_43 ( struct V_2 * V_4 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
}
static void F_44 ( struct V_2 * V_4 )
{
}
static void F_45 ( struct V_2 * V_4 )
{
}
static int F_46 ( struct V_30 * V_31 , struct V_30 * V_70 , void * V_43 )
{
struct V_1 * V_7 = F_20 ( V_31 ) ;
struct V_18 * V_19 = V_43 ;
struct V_2 * V_4 = & V_7 -> V_4 ;
struct V_14 * V_71 ;
enum V_72 type ;
unsigned int V_73 ;
int V_23 , V_38 ;
F_14 ( V_7 , V_19 ) ;
for ( V_73 = 0 ; V_73 < V_27 ; V_73 ++ ) {
type = F_47 ( V_73 , V_74 ) ;
V_38 = F_48 ( V_19 , & V_7 -> V_28 [ V_73 ] ,
1 << V_7 -> V_23 , type , V_75 ,
F_49 ( V_75 ) , V_73 ) ;
if ( V_38 )
return V_38 ;
}
V_71 = & V_7 -> V_28 [ V_76 ] ;
V_7 -> V_6 = F_50 ( V_19 , & V_71 -> V_26 ,
V_7 -> V_23 , V_77 ,
& V_78 , V_7 ) ;
if ( F_51 ( V_7 -> V_6 ) ) {
F_38 ( L_13 ) ;
return F_52 ( V_7 -> V_6 ) ;
}
V_23 = F_53 ( V_19 ,
V_77 ) ;
if ( V_23 < 0 )
return V_23 ;
V_4 -> V_79 = 1 << V_23 ;
F_9 ( L_14 , V_4 -> V_79 ) ;
F_54 ( V_19 , V_4 , & V_80 ,
V_81 ) ;
F_55 ( V_4 , & V_82 ) ;
V_38 = F_36 ( V_4 ) ;
if ( V_38 ) {
F_38 ( L_15 , V_38 ) ;
F_56 ( V_4 ) ;
return V_38 ;
}
return 0 ;
}
static void F_57 ( struct V_30 * V_31 , struct V_30 * V_70 , void * V_43 )
{
}
static int F_58 ( struct V_83 * V_84 )
{
struct V_1 * V_7 ;
int V_38 ;
V_7 = F_59 ( & V_84 -> V_31 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_50 ;
V_7 -> V_84 = V_84 ;
F_60 ( & V_7 -> V_13 , F_15 ) ;
F_61 ( & V_7 -> V_17 ) ;
F_62 ( V_84 , V_7 ) ;
V_38 = F_63 ( & V_84 -> V_31 , & V_85 ) ;
if ( V_38 < 0 ) {
F_38 ( L_16 ) ;
return V_38 ;
}
V_38 = F_64 ( & V_84 -> V_31 , & V_86 ) ;
if ( V_38 )
goto V_87;
return V_38 ;
V_87:
F_65 ( & V_84 -> V_31 , & V_85 ) ;
return V_38 ;
}
static int F_66 ( struct V_83 * V_84 )
{
struct V_1 * V_7 = F_67 ( V_84 ) ;
if ( V_7 -> V_40 != (struct V_41 * ) V_42 ) {
F_27 ( V_7 -> V_40 ) ;
V_7 -> V_40 = NULL ;
return - V_39 ;
}
F_68 ( & V_84 -> V_31 , & V_86 ) ;
return 0 ;
}
