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
return V_12 ;
default:
return V_13 ;
}
}
static bool F_5 ( struct V_1 * V_2 , enum V_14 V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ ) {
struct V_18 * V_19 = V_4 -> V_20 [ V_16 ] ;
if ( F_6 ( V_19 ) == V_15 )
return true ;
}
return false ;
}
static void F_7 ( void )
{
struct V_7 * V_8 = NULL ;
F_8 (dssdev)
V_8 -> V_21 -> V_22 ( V_8 ) ;
}
static int F_9 ( void )
{
int V_23 ;
struct V_7 * V_8 = NULL ;
bool V_24 = true ;
F_8 (dssdev) {
V_23 = V_8 -> V_21 -> V_25 ( V_8 ) ;
if ( V_23 == - V_26 ) {
F_10 ( V_8 ) ;
goto V_27;
} else if ( V_23 ) {
F_11 ( V_8 -> V_2 , L_2 ,
V_8 -> V_28 ) ;
} else {
V_24 = false ;
}
}
if ( V_24 )
return - V_26 ;
return 0 ;
V_27:
F_7 () ;
return V_23 ;
}
static int F_12 ( struct V_1 * V_2 , int V_29 ,
enum V_14 V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 ;
struct V_18 * V_19 ;
V_31 = F_13 ( V_2 , V_29 , V_32 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
V_19 = F_16 ( V_2 , V_31 , V_15 , V_29 ) ;
F_17 ( V_4 -> V_17 >= F_18 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 [ V_29 ] = V_19 ;
V_4 -> V_17 ++ ;
V_4 -> V_33 [ V_29 ] = V_31 ;
V_4 -> V_34 ++ ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_35 = F_20 () ;
int V_36 = F_21 () ;
int V_17 ;
int V_16 , V_29 = 0 ;
int V_37 ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
V_17 = F_24 ( V_38 , V_36 , V_35 ) ;
V_8 = NULL ;
F_8 (dssdev) {
struct V_39 * V_40 ;
struct V_41 * V_42 ;
enum V_14 V_15 ;
struct V_43 * V_44 ;
if ( ! F_25 ( V_8 ) )
continue;
V_42 = F_26 ( V_2 , V_8 ) ;
if ( ! V_42 ) {
F_27 ( V_2 -> V_2 , L_3 ,
V_8 -> V_28 ) ;
return - V_45 ;
}
V_40 = F_28 ( V_2 ,
F_4 ( V_8 ) , V_8 , V_42 ) ;
if ( ! V_40 ) {
F_27 ( V_2 -> V_2 , L_4 ,
V_8 -> V_28 ) ;
return - V_45 ;
}
F_17 ( V_4 -> V_46 >= F_18 ( V_4 -> V_47 ) ) ;
F_17 ( V_4 -> V_48 >= F_18 ( V_4 -> V_49 ) ) ;
V_4 -> V_47 [ V_4 -> V_46 ++ ] = V_42 ;
V_4 -> V_49 [ V_4 -> V_48 ++ ] = V_40 ;
F_29 ( V_40 , V_42 ) ;
if ( V_29 == V_17 )
continue;
V_44 = F_30 ( V_8 ) ;
V_15 = V_44 -> V_29 ;
if ( ! F_5 ( V_2 , V_15 ) ) {
V_37 = F_12 ( V_2 , V_29 , V_15 ) ;
if ( V_37 < 0 ) {
F_27 ( V_2 -> V_2 ,
L_5 ,
V_15 ) ;
return V_37 ;
}
V_29 ++ ;
}
}
for (; V_29 < V_17 ; V_29 ++ ) {
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
if ( ! F_5 ( V_2 , V_16 ) )
break;
}
if ( V_16 == V_36 ) {
F_27 ( V_2 -> V_2 , L_6 ) ;
return - V_45 ;
}
V_37 = F_12 ( V_2 , V_29 , V_16 ) ;
if ( V_37 < 0 ) {
F_27 ( V_2 -> V_2 ,
L_5 , V_16 ) ;
return V_37 ;
}
}
for (; V_29 < V_35 ; V_29 ++ ) {
struct V_30 * V_31 ;
V_31 = F_13 ( V_2 , V_29 , V_50 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
F_17 ( V_4 -> V_34 >= F_18 ( V_4 -> V_33 ) ) ;
V_4 -> V_33 [ V_4 -> V_34 ++ ] = V_31 ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_46 ; V_16 ++ ) {
struct V_41 * V_42 = V_4 -> V_47 [ V_16 ] ;
struct V_7 * V_8 =
F_31 ( V_42 ) ;
struct V_7 * V_51 ;
V_51 = F_32 ( V_8 ) ;
V_42 -> V_52 = 0 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_17 ; V_29 ++ ) {
struct V_18 * V_19 = V_4 -> V_20 [ V_29 ] ;
enum V_14 V_53 ;
V_53 = F_6 ( V_19 ) ;
if ( V_51 -> V_54 == V_53 ) {
V_42 -> V_52 |= ( 1 << V_29 ) ;
break;
}
}
F_10 ( V_51 ) ;
}
F_2 ( L_7 ,
V_4 -> V_34 , V_4 -> V_17 , V_4 -> V_46 ,
V_4 -> V_48 ) ;
V_2 -> V_55 . V_56 = 32 ;
V_2 -> V_55 . V_57 = 32 ;
V_2 -> V_55 . V_58 = 2048 ;
V_2 -> V_55 . V_59 = 2048 ;
V_2 -> V_55 . V_60 = & V_61 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * args = V_62 ;
F_2 ( L_8 , V_2 , args -> V_66 ) ;
switch ( args -> V_66 ) {
case V_67 :
args -> V_68 = V_4 -> V_69 ;
break;
default:
F_2 ( L_9 , args -> V_66 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * args = V_62 ;
switch ( args -> V_66 ) {
default:
F_2 ( L_9 , args -> V_66 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_71 * args = V_62 ;
F_38 ( L_10 , V_2 , V_64 ,
args -> V_72 . V_73 , args -> V_74 ) ;
return F_39 ( V_2 , V_64 , args -> V_72 ,
args -> V_74 , & args -> V_75 ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_76 * args = V_62 ;
struct V_77 * V_78 ;
int V_37 ;
F_38 ( L_11 , V_2 , V_64 , args -> V_75 , args -> V_79 ) ;
V_78 = F_41 ( V_2 , V_64 , args -> V_75 ) ;
if ( ! V_78 )
return - V_80 ;
V_37 = F_42 ( V_78 , args -> V_79 ) ;
if ( ! V_37 )
V_37 = F_43 ( V_78 , args -> V_79 ) ;
F_44 ( V_78 ) ;
return V_37 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_81 * args = V_62 ;
struct V_77 * V_78 ;
int V_37 ;
F_38 ( L_12 , V_2 , V_64 , args -> V_75 ) ;
V_78 = F_41 ( V_2 , V_64 , args -> V_75 ) ;
if ( ! V_78 )
return - V_80 ;
V_37 = 0 ;
if ( ! V_37 )
V_37 = F_46 ( V_78 , args -> V_79 ) ;
F_44 ( V_78 ) ;
return V_37 ;
}
static int F_47 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_82 * args = V_62 ;
struct V_77 * V_78 ;
int V_37 = 0 ;
F_38 ( L_12 , V_2 , V_64 , args -> V_75 ) ;
V_78 = F_41 ( V_2 , V_64 , args -> V_75 ) ;
if ( ! V_78 )
return - V_80 ;
args -> V_72 = F_48 ( V_78 ) ;
args -> V_83 = F_49 ( V_78 ) ;
F_44 ( V_78 ) ;
return V_37 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_74 )
{
struct V_84 * V_85 = V_2 -> V_2 -> V_86 ;
struct V_3 * V_4 ;
int V_37 ;
F_2 ( L_13 , V_2 ) ;
V_4 = F_51 ( sizeof( * V_4 ) , V_87 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_69 = V_85 -> V_69 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_88 = F_52 ( L_14 , 0 ) ;
F_53 ( & V_4 -> V_89 ) ;
F_54 ( & V_4 -> V_90 ) ;
F_55 ( V_2 ) ;
V_37 = F_19 ( V_2 ) ;
if ( V_37 ) {
F_27 ( V_2 -> V_2 , L_15 , V_37 ) ;
V_2 -> V_5 = NULL ;
F_56 ( V_4 ) ;
return V_37 ;
}
V_37 = F_57 ( V_2 , V_4 -> V_17 ) ;
if ( V_37 )
F_11 ( V_2 -> V_2 , L_16 ) ;
V_4 -> V_6 = F_58 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_11 ( V_2 -> V_2 , L_17 ) ;
}
F_59 ( V_2 -> V_2 , V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_16 ;
F_2 ( L_18 , V_2 ) ;
F_62 ( V_2 ) ;
if ( V_4 -> V_6 )
F_63 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ )
F_64 ( V_4 -> V_20 [ V_16 ] ) ;
F_33 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_4 -> V_88 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
F_56 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_59 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_63 * V_91 )
{
V_91 -> V_92 = NULL ;
F_2 ( L_19 , V_2 , V_91 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_37 ;
F_2 ( L_20 , V_2 ) ;
if ( V_4 -> V_93 ) {
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ ) {
F_71 ( & V_4 -> V_20 [ V_16 ] -> V_94 ,
V_4 -> V_93 , 0 ) ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_34 ; V_16 ++ ) {
F_71 ( & V_4 -> V_33 [ V_16 ] -> V_94 ,
V_4 -> V_93 , 0 ) ;
}
}
if ( V_4 -> V_6 ) {
V_37 = F_72 ( V_4 -> V_6 ) ;
if ( V_37 )
F_2 ( L_21 ) ;
}
}
static void F_73 ( struct V_1 * V_2 , struct V_63 * V_91 )
{
F_2 ( L_22 , V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_63 * V_91 )
{
F_2 ( L_23 , V_2 , V_91 ) ;
}
static int F_75 ( struct V_95 * V_96 )
{
int V_23 ;
if ( F_76 () == false )
return - V_26 ;
F_77 () ;
V_23 = F_9 () ;
if ( V_23 ) {
F_78 () ;
return V_23 ;
}
F_2 ( L_24 , V_96 -> V_28 ) ;
return F_79 ( & V_97 , V_96 ) ;
}
static int F_80 ( struct V_95 * V_96 )
{
F_2 ( L_25 ) ;
F_81 ( F_82 ( V_96 ) ) ;
F_7 () ;
F_78 () ;
return 0 ;
}
static int F_83 ( struct V_96 * V_2 )
{
struct V_1 * V_98 = F_84 ( V_2 ) ;
F_85 ( V_98 ) ;
return 0 ;
}
static int F_86 ( struct V_96 * V_2 )
{
struct V_1 * V_98 = F_84 ( V_2 ) ;
F_87 ( V_98 ) ;
return F_88 ( V_2 ) ;
}
static int T_1 F_89 ( void )
{
int V_23 ;
F_2 ( L_26 ) ;
V_23 = F_90 ( & V_99 ) ;
if ( V_23 ) {
F_91 ( L_27 ) ;
return V_23 ;
}
V_23 = F_90 ( & V_100 ) ;
if ( V_23 ) {
F_91 ( L_28 ) ;
F_92 ( & V_99 ) ;
return V_23 ;
}
return 0 ;
}
static void T_2 F_93 ( void )
{
F_2 ( L_29 ) ;
F_92 ( & V_100 ) ;
F_92 ( & V_99 ) ;
}
