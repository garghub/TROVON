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
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_29 = F_13 () ;
int V_30 = F_14 () ;
int V_17 ;
int V_16 , V_31 = 0 ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_17 = F_17 ( V_32 , V_30 , V_29 ) ;
V_8 = NULL ;
F_8 (dssdev) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
enum V_14 V_15 ;
struct V_37 * V_38 ;
if ( ! F_18 ( V_8 ) )
continue;
V_36 = F_19 ( V_2 , V_8 ) ;
if ( ! V_36 ) {
F_20 ( V_2 -> V_2 , L_3 ,
V_8 -> V_28 ) ;
return - V_39 ;
}
V_34 = F_21 ( V_2 ,
F_4 ( V_8 ) , V_8 , V_36 ) ;
if ( ! V_34 ) {
F_20 ( V_2 -> V_2 , L_4 ,
V_8 -> V_28 ) ;
return - V_39 ;
}
F_22 ( V_4 -> V_40 >= F_23 ( V_4 -> V_41 ) ) ;
F_22 ( V_4 -> V_42 >= F_23 ( V_4 -> V_43 ) ) ;
V_4 -> V_41 [ V_4 -> V_40 ++ ] = V_36 ;
V_4 -> V_43 [ V_4 -> V_42 ++ ] = V_34 ;
F_24 ( V_34 , V_36 ) ;
if ( V_31 == V_17 )
continue;
V_38 = F_25 ( V_8 ) ;
V_15 = V_38 -> V_31 ;
if ( ! F_5 ( V_2 , V_15 ) ) {
struct V_44 * V_45 ;
struct V_18 * V_19 ;
V_45 = F_26 ( V_2 , V_31 , true ) ;
V_19 = F_27 ( V_2 , V_45 , V_15 , V_31 ) ;
F_22 ( V_4 -> V_17 >= F_23 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 [ V_31 ] = V_19 ;
V_4 -> V_17 ++ ;
V_4 -> V_46 [ V_31 ] = V_45 ;
V_4 -> V_47 ++ ;
V_31 ++ ;
}
}
for (; V_31 < V_17 ; V_31 ++ ) {
for ( V_16 = 0 ; V_16 < V_30 ; V_16 ++ ) {
if ( ! F_5 ( V_2 , V_16 ) ) {
struct V_44 * V_45 ;
struct V_18 * V_19 ;
V_45 = F_26 ( V_2 , V_31 , true ) ;
V_19 = F_27 ( V_2 , V_45 , V_16 , V_31 ) ;
F_22 ( V_4 -> V_17 >=
F_23 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 [ V_31 ] = V_19 ;
V_4 -> V_17 ++ ;
V_4 -> V_46 [ V_31 ] = V_45 ;
V_4 -> V_47 ++ ;
break;
} else {
continue;
}
}
if ( V_16 == V_30 ) {
F_20 ( V_2 -> V_2 , L_5 ) ;
return - V_39 ;
}
}
for (; V_31 < V_29 ; V_31 ++ ) {
struct V_44 * V_45 = F_26 ( V_2 , V_31 , false ) ;
F_22 ( V_4 -> V_47 >= F_23 ( V_4 -> V_46 ) ) ;
V_4 -> V_46 [ V_4 -> V_47 ++ ] = V_45 ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_40 ; V_16 ++ ) {
struct V_35 * V_36 = V_4 -> V_41 [ V_16 ] ;
struct V_7 * V_8 =
F_28 ( V_36 ) ;
struct V_7 * V_48 ;
V_48 = F_29 ( V_8 ) ;
V_36 -> V_49 = 0 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_17 ; V_31 ++ ) {
struct V_18 * V_19 = V_4 -> V_20 [ V_31 ] ;
enum V_14 V_50 ;
enum V_51 V_52 ;
V_50 = F_6 ( V_19 ) ;
V_52 =
F_30 ( V_50 ) ;
if ( V_52 & V_48 -> V_31 )
V_36 -> V_49 |= ( 1 << V_31 ) ;
}
F_10 ( V_48 ) ;
}
F_2 ( L_6 ,
V_4 -> V_47 , V_4 -> V_17 , V_4 -> V_40 ,
V_4 -> V_42 ) ;
V_2 -> V_53 . V_54 = 32 ;
V_2 -> V_53 . V_55 = 32 ;
V_2 -> V_53 . V_56 = 2048 ;
V_2 -> V_53 . V_57 = 2048 ;
V_2 -> V_53 . V_58 = & V_59 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * args = V_60 ;
F_2 ( L_7 , V_2 , args -> V_64 ) ;
switch ( args -> V_64 ) {
case V_65 :
args -> V_66 = V_4 -> V_67 ;
break;
default:
F_2 ( L_8 , args -> V_64 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * args = V_60 ;
switch ( args -> V_64 ) {
default:
F_2 ( L_8 , args -> V_64 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_69 * args = V_60 ;
F_36 ( L_9 , V_2 , V_62 ,
args -> V_70 . V_71 , args -> V_72 ) ;
return F_37 ( V_2 , V_62 , args -> V_70 ,
args -> V_72 , & args -> V_73 ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_74 * args = V_60 ;
struct V_75 * V_76 ;
int V_77 ;
F_36 ( L_10 , V_2 , V_62 , args -> V_73 , args -> V_78 ) ;
V_76 = F_39 ( V_2 , V_62 , args -> V_73 ) ;
if ( ! V_76 )
return - V_79 ;
V_77 = F_40 ( V_76 , args -> V_78 ) ;
if ( ! V_77 )
V_77 = F_41 ( V_76 , args -> V_78 ) ;
F_42 ( V_76 ) ;
return V_77 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_80 * args = V_60 ;
struct V_75 * V_76 ;
int V_77 ;
F_36 ( L_11 , V_2 , V_62 , args -> V_73 ) ;
V_76 = F_39 ( V_2 , V_62 , args -> V_73 ) ;
if ( ! V_76 )
return - V_79 ;
V_77 = 0 ;
if ( ! V_77 )
V_77 = F_44 ( V_76 , args -> V_78 ) ;
F_42 ( V_76 ) ;
return V_77 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_81 * args = V_60 ;
struct V_75 * V_76 ;
int V_77 = 0 ;
F_36 ( L_11 , V_2 , V_62 , args -> V_73 ) ;
V_76 = F_39 ( V_2 , V_62 , args -> V_73 ) ;
if ( ! V_76 )
return - V_79 ;
args -> V_70 = F_46 ( V_76 ) ;
args -> V_82 = F_47 ( V_76 ) ;
F_42 ( V_76 ) ;
return V_77 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned long V_72 )
{
struct V_83 * V_84 = V_2 -> V_2 -> V_85 ;
struct V_3 * V_4 ;
int V_77 ;
F_2 ( L_12 , V_2 ) ;
V_4 = F_49 ( sizeof( * V_4 ) , V_86 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_67 = V_84 -> V_67 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_87 = F_50 ( L_13 , 0 ) ;
F_51 ( & V_4 -> V_88 ) ;
F_52 ( V_2 ) ;
V_77 = F_12 ( V_2 ) ;
if ( V_77 ) {
F_20 ( V_2 -> V_2 , L_14 , V_77 ) ;
V_2 -> V_5 = NULL ;
F_53 ( V_4 ) ;
return V_77 ;
}
V_77 = F_54 ( V_2 , V_4 -> V_17 ) ;
if ( V_77 )
F_11 ( V_2 -> V_2 , L_15 ) ;
V_4 -> V_6 = F_55 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_11 ( V_2 -> V_2 , L_16 ) ;
}
F_56 ( V_2 -> V_2 , V_2 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_16 ;
F_2 ( L_17 , V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ )
F_61 ( V_4 -> V_20 [ V_16 ] ) ;
F_31 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_4 -> V_87 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_53 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_56 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_61 * V_89 )
{
V_89 -> V_90 = NULL ;
F_2 ( L_18 , V_2 , V_89 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 ;
F_2 ( L_19 , V_2 ) ;
if ( V_4 -> V_91 ) {
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ ) {
F_68 ( & V_4 -> V_20 [ V_16 ] -> V_92 ,
V_4 -> V_91 , 0 ) ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_47 ; V_16 ++ ) {
F_68 ( & V_4 -> V_46 [ V_16 ] -> V_92 ,
V_4 -> V_91 , 0 ) ;
}
}
V_77 = F_69 ( V_4 -> V_6 ) ;
if ( V_77 )
F_2 ( L_20 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_61 * V_89 )
{
F_2 ( L_21 , V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_61 * V_89 )
{
F_2 ( L_22 , V_2 , V_89 ) ;
}
static int F_72 ( struct V_93 * V_94 , T_1 V_95 )
{
F_2 ( L_23 ) ;
return 0 ;
}
static int F_73 ( struct V_93 * V_96 )
{
F_2 ( L_23 ) ;
return 0 ;
}
static void F_74 ( struct V_93 * V_96 )
{
F_2 ( L_23 ) ;
}
static int F_75 ( struct V_93 * V_96 )
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
static int F_80 ( struct V_93 * V_96 )
{
F_2 ( L_23 ) ;
F_81 ( F_82 ( V_96 ) ) ;
F_7 () ;
F_78 () ;
return 0 ;
}
static int T_2 F_83 ( void )
{
int V_23 ;
F_2 ( L_25 ) ;
V_23 = F_84 ( & V_98 ) ;
if ( V_23 ) {
F_85 ( L_26 ) ;
return V_23 ;
}
V_23 = F_84 ( & V_99 ) ;
if ( V_23 ) {
F_85 ( L_27 ) ;
F_86 ( & V_98 ) ;
return V_23 ;
}
return 0 ;
}
static void T_3 F_87 ( void )
{
F_2 ( L_28 ) ;
F_86 ( & V_99 ) ;
F_86 ( & V_98 ) ;
}
