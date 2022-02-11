static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 + V_6 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( F_8 ( V_3 -> V_7 ) != 1 ) ;
F_9 ( V_3 -> V_7 [ 0 ] , V_4 -> V_5 + V_8 ) ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_9 ,
void * V_10 , unsigned V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
void T_2 * V_5 = V_4 -> V_5 +
F_11 ( V_4 ) + V_9 ;
T_3 * V_12 = V_10 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_12 [ V_13 ] = F_12 ( V_5 + V_13 ) ;
}
static void F_13 ( struct V_2 * V_3 , unsigned V_9 ,
const void * V_10 , unsigned V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
void T_2 * V_5 = V_4 -> V_5 +
F_11 ( V_4 ) + V_9 ;
const T_3 * V_12 = V_10 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
F_14 ( V_12 [ V_13 ] , V_5 + V_13 ) ;
}
static T_3 F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_12 ( V_4 -> V_5 + V_14 ) ;
}
static void F_16 ( struct V_2 * V_3 , T_3 V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_17 ( V_15 == 0 ) ;
F_14 ( V_15 , V_4 -> V_5 + V_14 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_16 )
F_19 ( V_4 -> V_17 -> V_18 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_19 ; ++ V_13 )
F_19 ( V_4 -> V_20 [ V_13 ] . V_21 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_14 ( 0 , V_4 -> V_5 + V_14 ) ;
F_12 ( V_4 -> V_5 + V_14 ) ;
F_18 ( V_3 ) ;
}
static void F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
F_22 ( V_25 -> V_27 , V_4 -> V_5 + V_28 ) ;
}
static T_4 F_23 ( int V_18 , void * V_29 )
{
struct V_1 * V_4 = V_29 ;
struct V_30 * V_31 ;
V_31 = F_2 ( V_4 -> V_3 . V_32 . V_33 ,
struct V_30 , V_33 ) ;
if ( V_31 && V_31 -> V_34 )
V_31 -> V_34 ( & V_4 -> V_3 ) ;
return V_35 ;
}
static T_4 F_24 ( int V_18 , void * V_29 )
{
struct V_1 * V_4 = V_29 ;
struct V_24 * V_25 ;
T_4 V_36 = V_37 ;
unsigned long V_38 ;
F_25 ( & V_4 -> V_39 , V_38 ) ;
F_26 (info, &vp_dev->virtqueues, node) {
if ( F_27 ( V_18 , V_25 -> V_23 ) == V_35 )
V_36 = V_35 ;
}
F_28 ( & V_4 -> V_39 , V_38 ) ;
return V_36 ;
}
static T_4 F_29 ( int V_18 , void * V_29 )
{
struct V_1 * V_4 = V_29 ;
T_3 V_40 ;
V_40 = F_12 ( V_4 -> V_5 + V_41 ) ;
if ( ! V_40 )
return V_37 ;
if ( V_40 & V_42 )
F_23 ( V_18 , V_29 ) ;
return F_24 ( V_18 , V_29 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_16 ) {
F_31 ( V_4 -> V_17 -> V_18 , V_4 ) ;
V_4 -> V_16 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_43 ; ++ V_13 )
F_31 ( V_4 -> V_20 [ V_13 ] . V_21 , V_4 ) ;
if ( V_4 -> V_44 ) {
F_22 ( V_45 ,
V_4 -> V_5 + V_46 ) ;
F_32 ( V_4 -> V_5 + V_46 ) ;
F_33 ( V_4 -> V_17 ) ;
V_4 -> V_44 = 0 ;
V_4 -> V_19 = 0 ;
}
V_4 -> V_43 = 0 ;
F_34 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
F_34 ( V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
}
static int F_35 ( struct V_2 * V_3 , int V_48 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const char * V_50 = F_36 ( & V_4 -> V_3 . V_32 ) ;
unsigned V_13 , V_51 ;
int V_52 = - V_53 ;
V_4 -> V_20 = F_37 ( V_48 * sizeof * V_4 -> V_20 ,
V_54 ) ;
if ( ! V_4 -> V_20 )
goto error;
V_4 -> V_47 = F_37 ( V_48 * sizeof * V_4 -> V_47 ,
V_54 ) ;
if ( ! V_4 -> V_47 )
goto error;
for ( V_13 = 0 ; V_13 < V_48 ; ++ V_13 )
V_4 -> V_20 [ V_13 ] . V_55 = V_13 ;
V_52 = F_38 ( V_4 -> V_17 , V_4 -> V_20 , V_48 ) ;
if ( V_52 > 0 )
V_52 = - V_56 ;
if ( V_52 )
goto error;
V_4 -> V_19 = V_48 ;
V_4 -> V_44 = 1 ;
V_51 = V_4 -> V_43 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_1 , V_50 ) ;
V_52 = F_39 ( V_4 -> V_20 [ V_51 ] . V_21 ,
F_23 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_43 ;
F_22 ( V_51 , V_4 -> V_5 + V_46 ) ;
V_51 = F_32 ( V_4 -> V_5 + V_46 ) ;
if ( V_51 == V_45 ) {
V_52 = - V_57 ;
goto error;
}
if ( ! V_49 ) {
V_51 = V_4 -> V_43 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_2 , V_50 ) ;
V_52 = F_39 ( V_4 -> V_20 [ V_51 ] . V_21 ,
F_24 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_43 ;
}
return 0 ;
error:
F_30 ( V_3 ) ;
return V_52 ;
}
static int F_40 ( struct V_2 * V_3 )
{
int V_52 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_52 = F_39 ( V_4 -> V_17 -> V_18 , F_29 ,
V_58 , F_36 ( & V_3 -> V_32 ) , V_4 ) ;
if ( ! V_52 )
V_4 -> V_16 = 1 ;
return V_52 ;
}
static struct V_22 * F_41 ( struct V_2 * V_3 , unsigned V_59 ,
void (* F_42)( struct V_22 * V_23 ) ,
const char * V_50 ,
T_5 V_60 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_25 ;
struct V_22 * V_23 ;
unsigned long V_38 , V_61 ;
T_5 V_62 ;
int V_52 ;
F_22 ( V_59 , V_4 -> V_5 + V_63 ) ;
V_62 = F_32 ( V_4 -> V_5 + V_64 ) ;
if ( ! V_62 || F_4 ( V_4 -> V_5 + V_65 ) )
return F_43 ( - V_66 ) ;
V_25 = F_37 ( sizeof( struct V_24 ) , V_54 ) ;
if ( ! V_25 )
return F_43 ( - V_53 ) ;
V_25 -> V_27 = V_59 ;
V_25 -> V_62 = V_62 ;
V_25 -> V_67 = V_60 ;
V_61 = F_44 ( F_45 ( V_62 , V_68 ) ) ;
V_25 -> V_69 = F_46 ( V_61 , V_54 | V_70 ) ;
if ( V_25 -> V_69 == NULL ) {
V_52 = - V_53 ;
goto V_71;
}
F_9 ( F_47 ( V_25 -> V_69 ) >> V_72 ,
V_4 -> V_5 + V_65 ) ;
V_23 = F_48 ( V_25 -> V_62 , V_68 , V_3 ,
true , V_25 -> V_69 , F_21 , F_42 , V_50 ) ;
if ( ! V_23 ) {
V_52 = - V_53 ;
goto V_73;
}
V_23 -> V_26 = V_25 ;
V_25 -> V_23 = V_23 ;
if ( V_60 != V_45 ) {
F_22 ( V_60 , V_4 -> V_5 + V_74 ) ;
V_60 = F_32 ( V_4 -> V_5 + V_74 ) ;
if ( V_60 == V_45 ) {
V_52 = - V_57 ;
goto V_75;
}
}
if ( F_42 ) {
F_25 ( & V_4 -> V_39 , V_38 ) ;
F_49 ( & V_25 -> V_76 , & V_4 -> V_77 ) ;
F_28 ( & V_4 -> V_39 , V_38 ) ;
} else {
F_50 ( & V_25 -> V_76 ) ;
}
return V_23 ;
V_75:
F_51 ( V_23 ) ;
V_73:
F_9 ( 0 , V_4 -> V_5 + V_65 ) ;
F_52 ( V_25 -> V_69 , V_61 ) ;
V_71:
F_34 ( V_25 ) ;
return F_43 ( V_52 ) ;
}
static void F_53 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_38 , V_61 ;
F_25 ( & V_4 -> V_39 , V_38 ) ;
F_54 ( & V_25 -> V_76 ) ;
F_28 ( & V_4 -> V_39 , V_38 ) ;
F_22 ( V_25 -> V_27 , V_4 -> V_5 + V_63 ) ;
if ( V_4 -> V_44 ) {
F_22 ( V_45 ,
V_4 -> V_5 + V_74 ) ;
F_12 ( V_4 -> V_5 + V_41 ) ;
}
F_51 ( V_23 ) ;
F_9 ( 0 , V_4 -> V_5 + V_65 ) ;
V_61 = F_44 ( F_45 ( V_25 -> V_62 , V_68 ) ) ;
F_52 ( V_25 -> V_69 , V_61 ) ;
F_34 ( V_25 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_22 * V_23 , * V_78 ;
struct V_24 * V_25 ;
F_56 (vq, n, &vdev->vqs, list) {
V_25 = V_23 -> V_26 ;
if ( V_4 -> V_49 &&
V_25 -> V_67 != V_45 )
F_31 ( V_4 -> V_20 [ V_25 -> V_67 ] . V_21 ,
V_23 ) ;
F_53 ( V_23 ) ;
}
V_4 -> V_49 = false ;
F_30 ( V_3 ) ;
}
static int F_57 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] ,
bool V_83 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_60 ;
int V_13 , V_52 , V_48 , V_84 ;
if ( ! V_83 ) {
V_52 = F_40 ( V_3 ) ;
if ( V_52 )
goto V_85;
} else {
if ( V_49 ) {
V_48 = 1 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 )
if ( V_81 [ V_13 ] )
++ V_48 ;
} else {
V_48 = 2 ;
}
V_52 = F_35 ( V_3 , V_48 , V_49 ) ;
if ( V_52 )
goto V_85;
}
V_4 -> V_49 = V_49 ;
V_84 = V_4 -> V_43 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 ) {
if ( ! V_81 [ V_13 ] || ! V_4 -> V_44 )
V_60 = V_45 ;
else if ( V_4 -> V_49 )
V_60 = V_84 ++ ;
else
V_60 = V_86 ;
V_80 [ V_13 ] = F_41 ( V_3 , V_13 , V_81 [ V_13 ] , V_82 [ V_13 ] , V_60 ) ;
if ( F_58 ( V_80 [ V_13 ] ) ) {
V_52 = F_59 ( V_80 [ V_13 ] ) ;
goto V_87;
}
if ( ! V_4 -> V_49 || V_60 == V_45 )
continue;
snprintf ( V_4 -> V_47 [ V_60 ] ,
sizeof * V_4 -> V_47 ,
L_3 ,
F_36 ( & V_4 -> V_3 . V_32 ) , V_82 [ V_13 ] ) ;
V_52 = F_39 ( V_4 -> V_20 [ V_60 ] . V_21 ,
F_27 , 0 ,
V_4 -> V_47 [ V_60 ] ,
V_80 [ V_13 ] ) ;
if ( V_52 ) {
F_53 ( V_80 [ V_13 ] ) ;
goto V_87;
}
}
return 0 ;
V_87:
F_55 ( V_3 ) ;
V_85:
return V_52 ;
}
static int F_60 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] )
{
int V_52 ;
V_52 = F_57 ( V_3 , V_79 , V_80 , V_81 , V_82 , true , true ) ;
if ( ! V_52 )
return 0 ;
V_52 = F_57 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
true , false ) ;
if ( ! V_52 )
return 0 ;
return F_57 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
false , false ) ;
}
static const char * F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_62 ( V_4 -> V_17 ) ;
}
static void F_63 ( struct V_88 * V_89 )
{
}
static int T_7 F_64 ( struct V_17 * V_17 ,
const struct V_90 * V_91 )
{
struct V_1 * V_4 ;
int V_52 ;
if ( V_17 -> V_88 < 0x1000 || V_17 -> V_88 > 0x103f )
return - V_92 ;
if ( V_17 -> V_93 != V_94 ) {
F_65 ( V_95 L_4 ,
V_94 , V_17 -> V_93 ) ;
return - V_92 ;
}
V_4 = F_66 ( sizeof( struct V_1 ) , V_54 ) ;
if ( V_4 == NULL )
return - V_53 ;
V_4 -> V_3 . V_32 . V_96 = & V_17 -> V_32 ;
V_4 -> V_3 . V_32 . V_97 = F_63 ;
V_4 -> V_3 . V_98 = & V_99 ;
V_4 -> V_17 = V_17 ;
F_50 ( & V_4 -> V_77 ) ;
F_67 ( & V_4 -> V_39 ) ;
F_68 ( V_17 ) ;
V_52 = F_69 ( V_17 ) ;
if ( V_52 )
goto V_100;
V_52 = F_70 ( V_17 , L_5 ) ;
if ( V_52 )
goto V_101;
V_4 -> V_5 = F_71 ( V_17 , 0 , 0 ) ;
if ( V_4 -> V_5 == NULL )
goto V_102;
F_72 ( V_17 , V_4 ) ;
F_73 ( V_17 ) ;
V_4 -> V_3 . V_91 . V_103 = V_17 -> V_104 ;
V_4 -> V_3 . V_91 . V_88 = V_17 -> V_105 ;
V_52 = F_74 ( & V_4 -> V_3 ) ;
if ( V_52 )
goto V_106;
return 0 ;
V_106:
F_72 ( V_17 , NULL ) ;
F_75 ( V_17 , V_4 -> V_5 ) ;
V_102:
F_76 ( V_17 ) ;
V_101:
F_77 ( V_17 ) ;
V_100:
F_34 ( V_4 ) ;
return V_52 ;
}
static void T_8 F_78 ( struct V_17 * V_17 )
{
struct V_1 * V_4 = F_79 ( V_17 ) ;
F_80 ( & V_4 -> V_3 ) ;
F_55 ( & V_4 -> V_3 ) ;
F_72 ( V_17 , NULL ) ;
F_75 ( V_17 , V_4 -> V_5 ) ;
F_76 ( V_17 ) ;
F_77 ( V_17 ) ;
F_34 ( V_4 ) ;
}
static int F_81 ( struct V_88 * V_32 )
{
struct V_17 * V_17 = F_82 ( V_32 ) ;
struct V_1 * V_4 = F_79 ( V_17 ) ;
struct V_30 * V_31 ;
int V_36 ;
V_31 = F_2 ( V_4 -> V_3 . V_32 . V_33 ,
struct V_30 , V_33 ) ;
V_36 = 0 ;
V_4 -> V_107 = F_15 ( & V_4 -> V_3 ) ;
if ( V_31 && V_31 -> V_108 )
V_36 = V_31 -> V_108 ( & V_4 -> V_3 ) ;
if ( ! V_36 )
F_77 ( V_17 ) ;
return V_36 ;
}
static int F_83 ( struct V_88 * V_32 )
{
struct V_17 * V_17 = F_82 ( V_32 ) ;
struct V_1 * V_4 = F_79 ( V_17 ) ;
struct V_30 * V_31 ;
int V_36 ;
V_31 = F_2 ( V_4 -> V_3 . V_32 . V_33 ,
struct V_30 , V_33 ) ;
V_36 = F_69 ( V_17 ) ;
if ( V_36 )
return V_36 ;
F_73 ( V_17 ) ;
F_5 ( & V_4 -> V_3 ) ;
if ( V_31 && V_31 -> V_109 )
V_36 = V_31 -> V_109 ( & V_4 -> V_3 ) ;
if ( ! V_36 )
F_16 ( & V_4 -> V_3 , V_4 -> V_107 ) ;
return V_36 ;
}
static int T_9 F_84 ( void )
{
return F_85 ( & V_110 ) ;
}
static void T_10 F_86 ( void )
{
F_87 ( & V_110 ) ;
}
