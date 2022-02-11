static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 , V_2 ) ;
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_6 ) ;
}
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
static void F_5 ( void )
{
int V_15 ;
F_2 ( L_3 ) ;
for ( V_15 = 0 ; V_15 < F_6 () ; V_15 ++ ) {
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_7 * V_8 = V_19 ?
V_19 -> V_21 ( V_19 ) : NULL ;
if ( V_8 ) {
F_2 ( L_4 , V_15 , V_17 -> V_12 , V_19 -> V_12 ,
V_8 -> V_12 ) ;
} else if ( V_19 ) {
F_2 ( L_5 , V_15 , V_17 -> V_12 , V_19 -> V_12 ) ;
} else {
F_2 ( L_6 , V_15 , V_17 -> V_12 ) ;
}
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 = F_9 ( V_2 , V_19 ) ;
if ( ! V_23 ) {
F_10 ( V_2 -> V_2 , L_7 ,
V_19 -> V_12 ) ;
return - V_24 ;
}
F_11 ( V_4 -> V_25 >= F_12 ( V_4 -> V_26 ) ) ;
V_4 -> V_26 [ V_4 -> V_25 ++ ] = V_23 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
static struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
if ( ! V_8 -> V_32 ) {
F_14 ( V_2 -> V_2 , L_8 ,
V_8 -> V_12 ) ;
return 0 ;
}
if ( ! ( V_8 -> V_32 -> V_33 ||
V_8 -> V_32 -> V_34 ) ) {
F_14 ( V_2 -> V_2 , L_9
L_10 ,
V_8 -> V_12 ) ;
return 0 ;
}
V_30 = F_15 ( V_2 ,
F_4 ( V_8 ) , V_8 ) ;
if ( ! V_30 ) {
F_10 ( V_2 -> V_2 , L_11 ,
V_8 -> V_12 ) ;
return - V_24 ;
}
F_11 ( V_4 -> V_35 >= F_12 ( V_4 -> V_36 ) ) ;
V_4 -> V_36 [ V_4 -> V_35 ++ ] = V_30 ;
#if 0
notifier = kzalloc(sizeof(struct notifier_block), GFP_KERNEL);
notifier->notifier_call = omap_drm_notifier;
omap_dss_add_notify(dssdev, notifier);
#else
V_28 = NULL ;
#endif
for ( V_31 = 0 ; V_31 < V_4 -> V_25 ; V_31 ++ ) {
struct V_18 * V_19 =
F_16 ( V_4 -> V_26 [ V_31 ] ) ;
if ( V_19 -> V_21 ( V_19 ) == V_8 ) {
F_17 ( V_30 ,
V_4 -> V_26 [ V_31 ] ) ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_16 * V_17 ,
int * V_31 , unsigned int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_19 = NULL ;
struct V_38 * V_39 ;
while ( * V_31 < V_4 -> V_35 && ! V_19 ) {
if ( V_37 & ( 1 << * V_31 ) ) {
struct V_22 * V_23 =
F_19 (
V_4 -> V_36 [ * V_31 ] ) ;
if ( V_23 ) {
V_19 = F_16 ( V_23 ) ;
}
}
( * V_31 ) ++ ;
}
while ( * V_31 < 2 * V_4 -> V_35 && ! V_19 ) {
int V_40 = * V_31 - V_4 -> V_35 ;
if ( ! ( V_37 & ( 1 << V_40 ) ) ) {
struct V_22 * V_23 =
F_19 (
V_4 -> V_36 [ V_40 ] ) ;
if ( V_23 ) {
V_19 = F_16 ( V_23 ) ;
}
}
( * V_31 ) ++ ;
}
V_39 = F_20 ( V_2 , V_17 , V_4 -> V_41 ) ;
if ( ! V_39 ) {
F_10 ( V_2 -> V_2 , L_12 ,
V_17 -> V_12 ) ;
return - V_24 ;
}
F_11 ( V_4 -> V_41 >= F_12 ( V_4 -> V_42 ) ) ;
V_4 -> V_42 [ V_4 -> V_41 ++ ] = V_39 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned int V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 =
F_22 ( V_2 , V_17 , V_43 , false ) ;
if ( ! V_45 ) {
F_10 ( V_2 -> V_2 , L_13 ,
V_17 -> V_12 ) ;
return - V_24 ;
}
F_11 ( V_4 -> V_46 >= F_12 ( V_4 -> V_47 ) ) ;
V_4 -> V_47 [ V_4 -> V_46 ++ ] = V_45 ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , void * V_48 )
{
return ! strcmp ( V_8 -> V_12 , V_48 ) ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_37 = 0 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_35 ; V_15 ++ ) {
struct V_29 * V_30 = V_4 -> V_36 [ V_15 ] ;
if ( F_25 ( V_30 , true ) ==
V_49 ) {
V_37 |= ( 1 << V_15 ) ;
}
}
return V_37 ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_50 * V_51 = V_2 -> V_2 -> V_52 ;
struct V_53 * V_54 = NULL ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
int V_15 , V_31 ;
unsigned int V_37 = 0 ;
F_27 ( V_2 ) ;
if ( V_51 && V_51 -> V_54 ) {
V_54 = V_51 -> V_54 ;
for ( V_15 = 0 ; V_15 < V_54 -> V_55 ; V_15 ++ ) {
struct V_18 * V_19 =
F_28 (
V_54 -> V_56 [ V_15 ] ) ;
F_8 ( V_2 , V_19 ) ;
}
for ( V_15 = 0 ; V_15 < V_54 -> V_57 ; V_15 ++ ) {
struct V_7 * V_8 =
F_29 (
( void * ) V_54 -> V_58 [ V_15 ] ,
F_23 ) ;
if ( ! V_8 ) {
F_14 ( V_2 -> V_2 , L_14 ,
V_54 -> V_58 [ V_15 ] ) ;
continue;
}
F_13 ( V_2 , V_8 ) ;
}
V_37 = F_24 ( V_2 ) ;
V_31 = 0 ;
for ( V_15 = 0 ; V_15 < V_54 -> V_59 ; V_15 ++ ) {
struct V_16 * V_17 =
F_7 ( V_54 -> V_60 [ V_15 ] ) ;
F_18 ( V_2 , V_17 , & V_31 , V_37 ) ;
}
for ( V_15 = 0 ; V_15 < V_54 -> V_61 ; V_15 ++ ) {
struct V_16 * V_17 =
F_7 ( V_54 -> V_62 [ V_15 ] ) ;
F_21 ( V_2 , V_17 , ( 1 << V_4 -> V_41 ) - 1 ) ;
}
} else {
int V_63 = F_30 ( F_6 () , V_64 ) ;
for ( V_15 = 0 ; V_15 < F_31 () ; V_15 ++ ) {
F_8 ( V_2 , F_28 ( V_15 ) ) ;
}
F_32 (dssdev) {
F_13 ( V_2 , V_8 ) ;
}
V_37 = F_24 ( V_2 ) ;
V_31 = 0 ;
for ( V_15 = 0 ; V_15 < V_63 ; V_15 ++ ) {
F_18 ( V_2 , F_7 ( V_15 ) ,
& V_31 , V_37 ) ;
}
for (; V_15 < F_6 () ; V_15 ++ ) {
struct V_16 * V_17 = F_7 ( V_15 ) ;
F_21 ( V_2 , V_17 , ( 1 << V_4 -> V_41 ) - 1 ) ;
}
}
for ( V_15 = 0 ; V_15 < V_4 -> V_25 ; V_15 ++ ) {
struct V_22 * V_23 = V_4 -> V_26 [ V_15 ] ;
struct V_18 * V_19 =
F_16 ( V_23 ) ;
V_23 -> V_43 = ( 1 << V_4 -> V_41 ) - 1 ;
F_2 ( L_15 , V_19 -> V_12 ,
V_23 -> V_43 ) ;
}
F_5 () ;
V_2 -> V_65 . V_66 = 32 ;
V_2 -> V_65 . V_67 = 32 ;
V_2 -> V_65 . V_68 = 2048 ;
V_2 -> V_65 . V_69 = 2048 ;
V_2 -> V_65 . V_70 = & V_71 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_74 * args = V_48 ;
F_2 ( L_16 , V_2 , args -> V_75 ) ;
switch ( args -> V_75 ) {
case V_76 :
args -> V_77 = V_78 ;
break;
default:
F_2 ( L_17 , args -> V_75 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_74 * args = V_48 ;
switch ( args -> V_75 ) {
default:
F_2 ( L_17 , args -> V_75 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_80 * args = V_48 ;
F_2 ( L_18 , V_2 , V_73 ,
args -> V_81 . V_82 , args -> V_83 ) ;
return F_38 ( V_2 , V_73 , args -> V_81 ,
args -> V_83 , & args -> V_84 ) ;
}
static int F_39 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_85 * args = V_48 ;
struct V_86 * V_87 ;
int V_88 ;
F_40 ( L_19 , V_2 , V_73 , args -> V_84 , args -> V_89 ) ;
V_87 = F_41 ( V_2 , V_73 , args -> V_84 ) ;
if ( ! V_87 ) {
return - V_90 ;
}
V_88 = F_42 ( V_87 , args -> V_89 ) ;
if ( ! V_88 ) {
V_88 = F_43 ( V_87 , args -> V_89 ) ;
}
F_44 ( V_87 ) ;
return V_88 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_91 * args = V_48 ;
struct V_86 * V_87 ;
int V_88 ;
F_40 ( L_20 , V_2 , V_73 , args -> V_84 ) ;
V_87 = F_41 ( V_2 , V_73 , args -> V_84 ) ;
if ( ! V_87 ) {
return - V_90 ;
}
V_88 = 0 ;
if ( ! V_88 ) {
V_88 = F_46 ( V_87 , args -> V_89 ) ;
}
F_44 ( V_87 ) ;
return V_88 ;
}
static int F_47 ( struct V_1 * V_2 , void * V_48 ,
struct V_72 * V_73 )
{
struct V_92 * args = V_48 ;
struct V_86 * V_87 ;
int V_88 = 0 ;
F_2 ( L_20 , V_2 , V_73 , args -> V_84 ) ;
V_87 = F_41 ( V_2 , V_73 , args -> V_84 ) ;
if ( ! V_87 ) {
return - V_90 ;
}
args -> V_81 = F_48 ( V_87 ) ;
args -> V_93 = F_49 ( V_87 ) ;
F_44 ( V_87 ) ;
return V_88 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_83 )
{
struct V_3 * V_4 ;
int V_88 ;
F_2 ( L_21 , V_2 ) ;
V_1 = V_2 ;
V_4 = F_51 ( sizeof( * V_4 ) , V_94 ) ;
if ( ! V_4 ) {
F_10 ( V_2 -> V_2 , L_22 ) ;
return - V_24 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_95 = F_52 ( L_23 , 0 ) ;
F_53 ( & V_4 -> V_96 ) ;
F_54 ( V_2 ) ;
V_88 = F_26 ( V_2 ) ;
if ( V_88 ) {
F_10 ( V_2 -> V_2 , L_24 , V_88 ) ;
V_2 -> V_5 = NULL ;
F_55 ( V_4 ) ;
return V_88 ;
}
V_4 -> V_6 = F_56 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_14 ( V_2 -> V_2 , L_25 ) ;
}
F_57 ( V_2 ) ;
V_88 = F_58 ( V_2 , V_4 -> V_41 ) ;
if ( V_88 ) {
F_14 ( V_2 -> V_2 , L_26 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_27 , V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_33 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_4 -> V_95 ) ;
F_65 ( V_4 -> V_95 ) ;
F_55 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_72 * V_97 )
{
V_97 -> V_98 = NULL ;
F_2 ( L_28 , V_2 , V_97 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_2 ( L_29 , V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
int V_15 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_88 ;
F_2 ( L_30 , V_2 ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_41 ; V_15 ++ ) {
F_69 ( & V_4 -> V_42 [ V_15 ] -> V_99 ,
V_4 -> V_100 , 0 ) ;
}
for ( V_15 = 0 ; V_15 < V_4 -> V_46 ; V_15 ++ ) {
F_69 ( & V_4 -> V_47 [ V_15 ] -> V_99 ,
V_4 -> V_100 , 0 ) ;
}
V_88 = F_70 ( V_4 -> V_6 ) ;
if ( V_88 )
F_2 ( L_31 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_72 * V_97 )
{
F_2 ( L_32 , V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 , struct V_72 * V_97 )
{
F_2 ( L_33 , V_2 , V_97 ) ;
}
static int F_73 ( struct V_1 * V_2 , int V_39 )
{
F_2 ( L_34 , V_2 , V_39 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , int V_39 )
{
F_2 ( L_35 , V_2 , V_39 ) ;
}
static T_1 F_75 ( T_2 )
{
return V_101 ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_2 ( L_36 , V_2 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
F_2 ( L_37 , V_2 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_2 ( L_38 , V_2 ) ;
}
static int F_79 ( struct V_102 * V_103 , T_3 V_104 )
{
F_2 ( L_39 ) ;
return 0 ;
}
static int F_80 ( struct V_102 * V_105 )
{
F_2 ( L_39 ) ;
return 0 ;
}
static void F_81 ( struct V_102 * V_105 )
{
F_2 ( L_39 ) ;
}
static int F_82 ( struct V_102 * V_105 )
{
F_2 ( L_40 , V_105 -> V_12 ) ;
return F_83 ( & V_106 , V_105 ) ;
}
static int F_84 ( struct V_102 * V_105 )
{
F_2 ( L_39 ) ;
F_85 ( & V_106 , V_105 ) ;
F_86 ( & V_107 ) ;
return 0 ;
}
static int T_4 F_87 ( void )
{
F_2 ( L_41 ) ;
if ( F_88 ( & V_107 ) ) {
F_10 ( NULL , L_42 ) ;
}
return F_88 ( & V_108 ) ;
}
static void T_5 F_89 ( void )
{
F_2 ( L_43 ) ;
F_86 ( & V_108 ) ;
}
