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
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_21 = F_8 () ;
int V_22 = F_9 () ;
int V_17 ;
int V_16 , V_23 = 0 ;
int V_24 ;
F_10 () ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_17 = F_13 ( V_25 , V_22 , V_21 ) ;
V_8 = NULL ;
F_14 (dssdev) {
struct V_26 * V_27 ;
struct V_28 * V_29 ;
enum V_14 V_15 ;
struct V_30 * V_31 ;
if ( ! V_8 -> V_32 ) {
F_15 ( V_2 -> V_2 , L_2 ,
V_8 -> V_33 ) ;
continue;
}
if ( ! ( V_8 -> V_32 -> V_34 ||
V_8 -> V_32 -> V_35 ) ) {
F_15 ( V_2 -> V_2 , L_3
L_4 ,
V_8 -> V_33 ) ;
continue;
}
V_24 = V_8 -> V_32 -> V_36 ( V_8 ) ;
if ( V_24 ) {
F_16 ( V_2 -> V_2 , L_5 ,
V_8 -> V_33 ) ;
continue;
}
V_29 = F_17 ( V_2 , V_8 ) ;
if ( ! V_29 ) {
F_16 ( V_2 -> V_2 , L_6 ,
V_8 -> V_33 ) ;
return - V_37 ;
}
V_27 = F_18 ( V_2 ,
F_4 ( V_8 ) , V_8 , V_29 ) ;
if ( ! V_27 ) {
F_16 ( V_2 -> V_2 , L_7 ,
V_8 -> V_33 ) ;
return - V_37 ;
}
F_19 ( V_4 -> V_38 >= F_20 ( V_4 -> V_39 ) ) ;
F_19 ( V_4 -> V_40 >= F_20 ( V_4 -> V_41 ) ) ;
V_4 -> V_39 [ V_4 -> V_38 ++ ] = V_29 ;
V_4 -> V_41 [ V_4 -> V_40 ++ ] = V_27 ;
F_21 ( V_27 , V_29 ) ;
if ( V_23 == V_17 )
continue;
V_31 = F_22 ( V_8 ) ;
V_15 = V_31 -> V_23 ;
if ( ! F_5 ( V_2 , V_15 ) ) {
struct V_42 * V_43 ;
struct V_18 * V_19 ;
V_43 = F_23 ( V_2 , V_23 , true ) ;
V_19 = F_24 ( V_2 , V_43 , V_15 , V_23 ) ;
F_19 ( V_4 -> V_17 >= F_20 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 [ V_23 ] = V_19 ;
V_4 -> V_17 ++ ;
V_4 -> V_44 [ V_23 ] = V_43 ;
V_4 -> V_45 ++ ;
V_23 ++ ;
}
}
for (; V_23 < V_17 ; V_23 ++ ) {
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( ! F_5 ( V_2 , V_16 ) ) {
struct V_42 * V_43 ;
struct V_18 * V_19 ;
V_43 = F_23 ( V_2 , V_23 , true ) ;
V_19 = F_24 ( V_2 , V_43 , V_16 , V_23 ) ;
F_19 ( V_4 -> V_17 >=
F_20 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 [ V_23 ] = V_19 ;
V_4 -> V_17 ++ ;
V_4 -> V_44 [ V_23 ] = V_43 ;
V_4 -> V_45 ++ ;
break;
} else {
continue;
}
}
if ( V_16 == V_22 ) {
F_16 ( V_2 -> V_2 , L_8 ) ;
return - V_37 ;
}
}
for (; V_23 < V_21 ; V_23 ++ ) {
struct V_42 * V_43 = F_23 ( V_2 , V_23 , false ) ;
F_19 ( V_4 -> V_45 >= F_20 ( V_4 -> V_44 ) ) ;
V_4 -> V_44 [ V_4 -> V_45 ++ ] = V_43 ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_38 ; V_16 ++ ) {
struct V_28 * V_29 = V_4 -> V_39 [ V_16 ] ;
struct V_7 * V_8 =
F_25 ( V_29 ) ;
struct V_7 * V_46 ;
V_46 = F_26 ( V_8 ) ;
V_29 -> V_47 = 0 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_17 ; V_23 ++ ) {
struct V_18 * V_19 = V_4 -> V_20 [ V_23 ] ;
enum V_14 V_48 ;
enum V_49 V_50 ;
V_48 = F_6 ( V_19 ) ;
V_50 =
F_27 ( V_48 ) ;
if ( V_50 & V_46 -> V_23 )
V_29 -> V_47 |= ( 1 << V_23 ) ;
}
F_28 ( V_46 ) ;
}
F_2 ( L_9 ,
V_4 -> V_45 , V_4 -> V_17 , V_4 -> V_38 ,
V_4 -> V_40 ) ;
V_2 -> V_51 . V_52 = 32 ;
V_2 -> V_51 . V_53 = 32 ;
V_2 -> V_51 . V_54 = 2048 ;
V_2 -> V_51 . V_55 = 2048 ;
V_2 -> V_51 . V_56 = & V_57 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_61 * args = V_58 ;
F_2 ( L_10 , V_2 , args -> V_62 ) ;
switch ( args -> V_62 ) {
case V_63 :
args -> V_64 = V_4 -> V_65 ;
break;
default:
F_2 ( L_11 , args -> V_62 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * args = V_58 ;
switch ( args -> V_62 ) {
default:
F_2 ( L_11 , args -> V_62 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_67 * args = V_58 ;
F_34 ( L_12 , V_2 , V_60 ,
args -> V_68 . V_69 , args -> V_70 ) ;
return F_35 ( V_2 , V_60 , args -> V_68 ,
args -> V_70 , & args -> V_71 ) ;
}
static int F_36 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_72 * args = V_58 ;
struct V_73 * V_74 ;
int V_75 ;
F_34 ( L_13 , V_2 , V_60 , args -> V_71 , args -> V_76 ) ;
V_74 = F_37 ( V_2 , V_60 , args -> V_71 ) ;
if ( ! V_74 )
return - V_77 ;
V_75 = F_38 ( V_74 , args -> V_76 ) ;
if ( ! V_75 )
V_75 = F_39 ( V_74 , args -> V_76 ) ;
F_40 ( V_74 ) ;
return V_75 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_78 * args = V_58 ;
struct V_73 * V_74 ;
int V_75 ;
F_34 ( L_14 , V_2 , V_60 , args -> V_71 ) ;
V_74 = F_37 ( V_2 , V_60 , args -> V_71 ) ;
if ( ! V_74 )
return - V_77 ;
V_75 = 0 ;
if ( ! V_75 )
V_75 = F_42 ( V_74 , args -> V_76 ) ;
F_40 ( V_74 ) ;
return V_75 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_79 * args = V_58 ;
struct V_73 * V_74 ;
int V_75 = 0 ;
F_34 ( L_14 , V_2 , V_60 , args -> V_71 ) ;
V_74 = F_37 ( V_2 , V_60 , args -> V_71 ) ;
if ( ! V_74 )
return - V_77 ;
args -> V_68 = F_44 ( V_74 ) ;
args -> V_80 = F_45 ( V_74 ) ;
F_40 ( V_74 ) ;
return V_75 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned long V_70 )
{
struct V_81 * V_82 = V_2 -> V_2 -> V_83 ;
struct V_3 * V_4 ;
int V_75 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_47 ( sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_65 = V_82 -> V_65 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_85 = F_48 ( L_16 , 0 ) ;
F_49 ( & V_4 -> V_86 ) ;
F_50 ( V_2 ) ;
V_75 = F_7 ( V_2 ) ;
if ( V_75 ) {
F_16 ( V_2 -> V_2 , L_17 , V_75 ) ;
V_2 -> V_5 = NULL ;
F_51 ( V_4 ) ;
return V_75 ;
}
V_75 = F_52 ( V_2 , V_4 -> V_17 ) ;
if ( V_75 )
F_15 ( V_2 -> V_2 , L_18 ) ;
V_4 -> V_6 = F_53 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_15 ( V_2 -> V_2 , L_19 ) ;
}
F_54 ( V_2 -> V_2 , V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_20 , V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_29 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_4 -> V_85 ) ;
F_63 ( V_4 -> V_85 ) ;
F_51 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_54 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_59 * V_87 )
{
V_87 -> V_88 = NULL ;
F_2 ( L_21 , V_2 , V_87 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_2 ( L_22 , V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 ;
F_2 ( L_23 , V_2 ) ;
if ( V_4 -> V_89 ) {
for ( V_16 = 0 ; V_16 < V_4 -> V_17 ; V_16 ++ ) {
F_67 ( & V_4 -> V_20 [ V_16 ] -> V_90 ,
V_4 -> V_89 , 0 ) ;
}
for ( V_16 = 0 ; V_16 < V_4 -> V_45 ; V_16 ++ ) {
F_67 ( & V_4 -> V_44 [ V_16 ] -> V_90 ,
V_4 -> V_89 , 0 ) ;
}
}
F_68 ( V_2 ) ;
V_75 = F_69 ( V_4 -> V_6 ) ;
F_70 ( V_2 ) ;
if ( V_75 )
F_2 ( L_24 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_59 * V_87 )
{
F_2 ( L_25 , V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 , struct V_59 * V_87 )
{
F_2 ( L_26 , V_2 , V_87 ) ;
}
static int F_73 ( struct V_91 * V_92 , T_1 V_93 )
{
F_2 ( L_27 ) ;
return 0 ;
}
static int F_74 ( struct V_91 * V_94 )
{
F_2 ( L_27 ) ;
return 0 ;
}
static void F_75 ( struct V_91 * V_94 )
{
F_2 ( L_27 ) ;
}
static int F_76 ( struct V_91 * V_94 )
{
if ( F_77 () == false )
return - V_95 ;
F_2 ( L_28 , V_94 -> V_33 ) ;
return F_78 ( & V_96 , V_94 ) ;
}
static int F_79 ( struct V_91 * V_94 )
{
F_2 ( L_27 ) ;
F_80 ( & V_96 , V_94 ) ;
F_81 ( & V_97 ) ;
return 0 ;
}
static int T_2 F_82 ( void )
{
F_2 ( L_29 ) ;
if ( F_83 ( & V_97 ) ) {
F_16 ( NULL , L_30 ) ;
}
return F_83 ( & V_98 ) ;
}
static void T_3 F_84 ( void )
{
F_2 ( L_31 ) ;
F_81 ( & V_98 ) ;
}
