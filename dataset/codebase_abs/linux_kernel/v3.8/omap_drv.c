static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 , V_2 ) ;
if ( V_4 -> V_6 )
F_3 ( V_4 -> V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_9 :
return V_10 ;
case V_11 :
if ( ! strcmp ( V_8 -> V_12 , L_2 ) )
return V_13 ;
default:
return V_14 ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_15 = F_6 () ;
int V_16 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < F_9 ( V_17 , V_15 ) ; V_16 ++ ) {
struct V_18 * V_19 ;
struct V_20 * V_21 ;
V_19 = F_10 ( V_2 , V_16 , true ) ;
V_21 = F_11 ( V_2 , V_19 , F_12 ( V_16 ) , V_16 ) ;
F_13 ( V_4 -> V_22 >= F_14 ( V_4 -> V_23 ) ) ;
V_4 -> V_23 [ V_16 ] = V_21 ;
V_4 -> V_22 ++ ;
V_4 -> V_24 [ V_16 ] = V_19 ;
V_4 -> V_25 ++ ;
}
for (; V_16 < V_15 ; V_16 ++ ) {
struct V_18 * V_19 = F_10 ( V_2 , V_16 , false ) ;
F_13 ( V_4 -> V_25 >= F_14 ( V_4 -> V_24 ) ) ;
V_4 -> V_24 [ V_4 -> V_25 ++ ] = V_19 ;
}
F_15 (dssdev) {
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( ! V_8 -> V_30 ) {
F_16 ( V_2 -> V_2 , L_3 ,
V_8 -> V_12 ) ;
return 0 ;
}
if ( ! ( V_8 -> V_30 -> V_31 ||
V_8 -> V_30 -> V_32 ) ) {
F_16 ( V_2 -> V_2 , L_4
L_5 ,
V_8 -> V_12 ) ;
return 0 ;
}
V_29 = F_17 ( V_2 , V_8 ) ;
if ( ! V_29 ) {
F_18 ( V_2 -> V_2 , L_6 ,
V_8 -> V_12 ) ;
return - V_33 ;
}
V_27 = F_19 ( V_2 ,
F_4 ( V_8 ) , V_8 , V_29 ) ;
if ( ! V_27 ) {
F_18 ( V_2 -> V_2 , L_7 ,
V_8 -> V_12 ) ;
return - V_33 ;
}
F_13 ( V_4 -> V_34 >= F_14 ( V_4 -> V_35 ) ) ;
F_13 ( V_4 -> V_36 >= F_14 ( V_4 -> V_37 ) ) ;
V_4 -> V_35 [ V_4 -> V_34 ++ ] = V_29 ;
V_4 -> V_37 [ V_4 -> V_36 ++ ] = V_27 ;
F_20 ( V_27 , V_29 ) ;
V_29 -> V_38 = 0 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_22 ; V_16 ++ ) {
enum V_39 V_40 =
F_21 ( F_12 ( V_16 ) ) ;
if ( V_40 & V_8 -> V_41 -> V_16 )
V_29 -> V_38 |= ( 1 << V_16 ) ;
}
}
V_2 -> V_42 . V_43 = 32 ;
V_2 -> V_42 . V_44 = 32 ;
V_2 -> V_42 . V_45 = 2048 ;
V_2 -> V_42 . V_46 = 2048 ;
V_2 -> V_42 . V_47 = & V_48 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * args = V_49 ;
F_2 ( L_8 , V_2 , args -> V_53 ) ;
switch ( args -> V_53 ) {
case V_54 :
args -> V_55 = V_4 -> V_56 ;
break;
default:
F_2 ( L_9 , args -> V_53 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * args = V_49 ;
switch ( args -> V_53 ) {
default:
F_2 ( L_9 , args -> V_53 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_58 * args = V_49 ;
F_27 ( L_10 , V_2 , V_51 ,
args -> V_59 . V_60 , args -> V_61 ) ;
return F_28 ( V_2 , V_51 , args -> V_59 ,
args -> V_61 , & args -> V_62 ) ;
}
static int F_29 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_63 * args = V_49 ;
struct V_64 * V_65 ;
int V_66 ;
F_27 ( L_11 , V_2 , V_51 , args -> V_62 , args -> V_67 ) ;
V_65 = F_30 ( V_2 , V_51 , args -> V_62 ) ;
if ( ! V_65 )
return - V_68 ;
V_66 = F_31 ( V_65 , args -> V_67 ) ;
if ( ! V_66 )
V_66 = F_32 ( V_65 , args -> V_67 ) ;
F_33 ( V_65 ) ;
return V_66 ;
}
static int F_34 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_69 * args = V_49 ;
struct V_64 * V_65 ;
int V_66 ;
F_27 ( L_12 , V_2 , V_51 , args -> V_62 ) ;
V_65 = F_30 ( V_2 , V_51 , args -> V_62 ) ;
if ( ! V_65 )
return - V_68 ;
V_66 = 0 ;
if ( ! V_66 )
V_66 = F_35 ( V_65 , args -> V_67 ) ;
F_33 ( V_65 ) ;
return V_66 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_70 * args = V_49 ;
struct V_64 * V_65 ;
int V_66 = 0 ;
F_27 ( L_12 , V_2 , V_51 , args -> V_62 ) ;
V_65 = F_30 ( V_2 , V_51 , args -> V_62 ) ;
if ( ! V_65 )
return - V_68 ;
args -> V_59 = F_37 ( V_65 ) ;
args -> V_71 = F_38 ( V_65 ) ;
F_33 ( V_65 ) ;
return V_66 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_61 )
{
struct V_72 * V_73 = V_2 -> V_2 -> V_74 ;
struct V_3 * V_4 ;
int V_66 ;
F_2 ( L_13 , V_2 ) ;
V_4 = F_40 ( sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 ) {
F_18 ( V_2 -> V_2 , L_14 ) ;
return - V_33 ;
}
V_4 -> V_56 = V_73 -> V_56 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_76 = F_41 ( L_15 , 0 ) ;
F_42 ( & V_4 -> V_77 ) ;
F_43 ( V_2 ) ;
V_66 = F_5 ( V_2 ) ;
if ( V_66 ) {
F_18 ( V_2 -> V_2 , L_16 , V_66 ) ;
V_2 -> V_5 = NULL ;
F_44 ( V_4 ) ;
return V_66 ;
}
V_66 = F_45 ( V_2 , V_4 -> V_22 ) ;
if ( V_66 )
F_16 ( V_2 -> V_2 , L_17 ) ;
V_4 -> V_6 = F_46 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_16 ( V_2 -> V_2 , L_18 ) ;
}
F_47 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_19 , V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_22 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_4 -> V_76 ) ;
F_55 ( V_4 -> V_76 ) ;
F_44 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_50 * V_78 )
{
V_78 -> V_79 = NULL ;
F_2 ( L_20 , V_2 , V_78 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_2 ( L_21 , V_2 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_80 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
F_2 ( L_22 , V_2 ) ;
if ( V_4 -> V_81 ) {
for ( V_80 = 0 ; V_80 < V_4 -> V_22 ; V_80 ++ ) {
F_59 ( & V_4 -> V_23 [ V_80 ] -> V_82 ,
V_4 -> V_81 , 0 ) ;
}
for ( V_80 = 0 ; V_80 < V_4 -> V_25 ; V_80 ++ ) {
F_59 ( & V_4 -> V_24 [ V_80 ] -> V_82 ,
V_4 -> V_81 , 0 ) ;
}
}
F_60 ( & V_2 -> V_42 . V_83 ) ;
V_66 = F_61 ( V_4 -> V_6 ) ;
F_62 ( & V_2 -> V_42 . V_83 ) ;
if ( V_66 )
F_2 ( L_23 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_50 * V_78 )
{
F_2 ( L_24 , V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_50 * V_78 )
{
F_2 ( L_25 , V_2 , V_78 ) ;
}
static int F_65 ( struct V_84 * V_85 , T_1 V_86 )
{
F_2 ( L_26 ) ;
return 0 ;
}
static int F_66 ( struct V_84 * V_87 )
{
F_2 ( L_26 ) ;
return 0 ;
}
static void F_67 ( struct V_84 * V_87 )
{
F_2 ( L_26 ) ;
}
static int F_68 ( struct V_84 * V_87 )
{
F_2 ( L_27 , V_87 -> V_12 ) ;
return F_69 ( & V_88 , V_87 ) ;
}
static int F_70 ( struct V_84 * V_87 )
{
F_2 ( L_26 ) ;
F_71 ( & V_88 , V_87 ) ;
F_72 ( & V_89 ) ;
return 0 ;
}
static int T_2 F_73 ( void )
{
F_2 ( L_28 ) ;
if ( F_74 ( & V_89 ) ) {
F_18 ( NULL , L_29 ) ;
}
return F_74 ( & V_90 ) ;
}
static void T_3 F_75 ( void )
{
F_2 ( L_30 ) ;
F_72 ( & V_90 ) ;
}
