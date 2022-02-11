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
static bool F_5 ( struct V_1 * V_2 , enum V_15 V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_18 ; V_17 ++ ) {
struct V_19 * V_20 = V_4 -> V_21 [ V_17 ] ;
if ( F_6 ( V_20 ) == V_16 )
return true ;
}
return false ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_22 = F_8 () ;
int V_23 = F_9 () ;
int V_18 ;
int V_17 , V_24 = 0 ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
V_18 = F_12 ( V_25 , V_23 , V_22 ) ;
V_8 = NULL ;
F_13 (dssdev) {
struct V_26 * V_27 ;
struct V_28 * V_29 ;
enum V_15 V_16 ;
if ( ! V_8 -> V_30 ) {
F_14 ( V_2 -> V_2 , L_3 ,
V_8 -> V_12 ) ;
continue;
}
if ( ! ( V_8 -> V_30 -> V_31 ||
V_8 -> V_30 -> V_32 ) ) {
F_14 ( V_2 -> V_2 , L_4
L_5 ,
V_8 -> V_12 ) ;
continue;
}
V_29 = F_15 ( V_2 , V_8 ) ;
if ( ! V_29 ) {
F_16 ( V_2 -> V_2 , L_6 ,
V_8 -> V_12 ) ;
return - V_33 ;
}
V_27 = F_17 ( V_2 ,
F_4 ( V_8 ) , V_8 , V_29 ) ;
if ( ! V_27 ) {
F_16 ( V_2 -> V_2 , L_7 ,
V_8 -> V_12 ) ;
return - V_33 ;
}
F_18 ( V_4 -> V_34 >= F_19 ( V_4 -> V_35 ) ) ;
F_18 ( V_4 -> V_36 >= F_19 ( V_4 -> V_37 ) ) ;
V_4 -> V_35 [ V_4 -> V_34 ++ ] = V_29 ;
V_4 -> V_37 [ V_4 -> V_36 ++ ] = V_27 ;
F_20 ( V_27 , V_29 ) ;
if ( V_24 == V_18 )
continue;
V_16 = V_8 -> V_38 -> V_39 ;
if ( ! F_5 ( V_2 , V_16 ) ) {
struct V_40 * V_41 ;
struct V_19 * V_20 ;
V_41 = F_21 ( V_2 , V_24 , true ) ;
V_20 = F_22 ( V_2 , V_41 , V_16 , V_24 ) ;
F_18 ( V_4 -> V_18 >= F_19 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_24 ] = V_20 ;
V_4 -> V_18 ++ ;
V_4 -> V_42 [ V_24 ] = V_41 ;
V_4 -> V_43 ++ ;
V_24 ++ ;
}
}
for (; V_24 < V_18 ; V_24 ++ ) {
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
if ( ! F_5 ( V_2 , V_17 ) ) {
struct V_40 * V_41 ;
struct V_19 * V_20 ;
V_41 = F_21 ( V_2 , V_24 , true ) ;
V_20 = F_22 ( V_2 , V_41 , V_17 , V_24 ) ;
F_18 ( V_4 -> V_18 >=
F_19 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_24 ] = V_20 ;
V_4 -> V_18 ++ ;
V_4 -> V_42 [ V_24 ] = V_41 ;
V_4 -> V_43 ++ ;
break;
} else {
continue;
}
}
if ( V_17 == V_23 ) {
F_16 ( V_2 -> V_2 , L_8 ) ;
return - V_33 ;
}
}
for (; V_24 < V_22 ; V_24 ++ ) {
struct V_40 * V_41 = F_21 ( V_2 , V_24 , false ) ;
F_18 ( V_4 -> V_43 >= F_19 ( V_4 -> V_42 ) ) ;
V_4 -> V_42 [ V_4 -> V_43 ++ ] = V_41 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_34 ; V_17 ++ ) {
struct V_28 * V_29 = V_4 -> V_35 [ V_17 ] ;
struct V_7 * V_8 =
F_23 ( V_29 ) ;
V_29 -> V_44 = 0 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_18 ; V_24 ++ ) {
struct V_19 * V_20 = V_4 -> V_21 [ V_24 ] ;
enum V_15 V_45 ;
enum V_46 V_47 ;
V_45 = F_6 ( V_20 ) ;
V_47 =
F_24 ( V_45 ) ;
if ( V_47 & V_8 -> V_38 -> V_24 )
V_29 -> V_44 |= ( 1 << V_24 ) ;
}
}
F_2 ( L_9 ,
V_4 -> V_43 , V_4 -> V_18 , V_4 -> V_34 ,
V_4 -> V_36 ) ;
V_2 -> V_48 . V_49 = 32 ;
V_2 -> V_48 . V_50 = 32 ;
V_2 -> V_48 . V_51 = 2048 ;
V_2 -> V_48 . V_52 = 2048 ;
V_2 -> V_48 . V_53 = & V_54 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_58 * args = V_55 ;
F_2 ( L_10 , V_2 , args -> V_59 ) ;
switch ( args -> V_59 ) {
case V_60 :
args -> V_61 = V_4 -> V_62 ;
break;
default:
F_2 ( L_11 , args -> V_59 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * args = V_55 ;
switch ( args -> V_59 ) {
default:
F_2 ( L_11 , args -> V_59 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_64 * args = V_55 ;
F_30 ( L_12 , V_2 , V_57 ,
args -> V_65 . V_66 , args -> V_67 ) ;
return F_31 ( V_2 , V_57 , args -> V_65 ,
args -> V_67 , & args -> V_68 ) ;
}
static int F_32 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_69 * args = V_55 ;
struct V_70 * V_71 ;
int V_72 ;
F_30 ( L_13 , V_2 , V_57 , args -> V_68 , args -> V_73 ) ;
V_71 = F_33 ( V_2 , V_57 , args -> V_68 ) ;
if ( ! V_71 )
return - V_74 ;
V_72 = F_34 ( V_71 , args -> V_73 ) ;
if ( ! V_72 )
V_72 = F_35 ( V_71 , args -> V_73 ) ;
F_36 ( V_71 ) ;
return V_72 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_75 * args = V_55 ;
struct V_70 * V_71 ;
int V_72 ;
F_30 ( L_14 , V_2 , V_57 , args -> V_68 ) ;
V_71 = F_33 ( V_2 , V_57 , args -> V_68 ) ;
if ( ! V_71 )
return - V_74 ;
V_72 = 0 ;
if ( ! V_72 )
V_72 = F_38 ( V_71 , args -> V_73 ) ;
F_36 ( V_71 ) ;
return V_72 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_76 * args = V_55 ;
struct V_70 * V_71 ;
int V_72 = 0 ;
F_30 ( L_14 , V_2 , V_57 , args -> V_68 ) ;
V_71 = F_33 ( V_2 , V_57 , args -> V_68 ) ;
if ( ! V_71 )
return - V_74 ;
args -> V_65 = F_40 ( V_71 ) ;
args -> V_77 = F_41 ( V_71 ) ;
F_36 ( V_71 ) ;
return V_72 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned long V_67 )
{
struct V_78 * V_79 = V_2 -> V_2 -> V_80 ;
struct V_3 * V_4 ;
int V_72 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_43 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
return - V_33 ;
V_4 -> V_62 = V_79 -> V_62 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_82 = F_44 ( L_16 , 0 ) ;
F_45 ( & V_4 -> V_83 ) ;
F_46 ( V_2 ) ;
V_72 = F_7 ( V_2 ) ;
if ( V_72 ) {
F_16 ( V_2 -> V_2 , L_17 , V_72 ) ;
V_2 -> V_5 = NULL ;
F_47 ( V_4 ) ;
return V_72 ;
}
V_72 = F_48 ( V_2 , V_4 -> V_18 ) ;
if ( V_72 )
F_14 ( V_2 -> V_2 , L_18 ) ;
V_4 -> V_6 = F_49 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_14 ( V_2 -> V_2 , L_19 ) ;
}
F_50 ( V_2 -> V_2 , V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_20 , V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_25 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_4 -> V_82 ) ;
F_59 ( V_4 -> V_82 ) ;
F_47 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_50 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_56 * V_84 )
{
V_84 -> V_85 = NULL ;
F_2 ( L_21 , V_2 , V_84 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_2 ( L_22 , V_2 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 ;
F_2 ( L_23 , V_2 ) ;
if ( V_4 -> V_86 ) {
for ( V_17 = 0 ; V_17 < V_4 -> V_18 ; V_17 ++ ) {
F_63 ( & V_4 -> V_21 [ V_17 ] -> V_87 ,
V_4 -> V_86 , 0 ) ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_43 ; V_17 ++ ) {
F_63 ( & V_4 -> V_42 [ V_17 ] -> V_87 ,
V_4 -> V_86 , 0 ) ;
}
}
F_64 ( V_2 ) ;
V_72 = F_65 ( V_4 -> V_6 ) ;
F_66 ( V_2 ) ;
if ( V_72 )
F_2 ( L_24 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_56 * V_84 )
{
F_2 ( L_25 , V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_56 * V_84 )
{
F_2 ( L_26 , V_2 , V_84 ) ;
}
static int F_69 ( struct V_88 * V_89 , T_1 V_90 )
{
F_2 ( L_27 ) ;
return 0 ;
}
static int F_70 ( struct V_88 * V_91 )
{
F_2 ( L_27 ) ;
return 0 ;
}
static void F_71 ( struct V_88 * V_91 )
{
F_2 ( L_27 ) ;
}
static int F_72 ( struct V_88 * V_91 )
{
if ( F_73 () == false )
return - V_92 ;
F_2 ( L_28 , V_91 -> V_12 ) ;
return F_74 ( & V_93 , V_91 ) ;
}
static int F_75 ( struct V_88 * V_91 )
{
F_2 ( L_27 ) ;
F_76 ( & V_93 , V_91 ) ;
F_77 ( & V_94 ) ;
return 0 ;
}
static int T_2 F_78 ( void )
{
F_2 ( L_29 ) ;
if ( F_79 ( & V_94 ) ) {
F_16 ( NULL , L_30 ) ;
}
return F_79 ( & V_95 ) ;
}
static void T_3 F_80 ( void )
{
F_2 ( L_31 ) ;
F_77 ( & V_95 ) ;
}
