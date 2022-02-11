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
F_14 ( 0 , V_4 -> V_5 + V_14 ) ;
}
static void F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_17 -> V_3 ) ;
struct V_18 * V_19 = V_17 -> V_20 ;
F_20 ( V_19 -> V_21 , V_4 -> V_5 + V_22 ) ;
}
static T_4 F_21 ( int V_23 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
struct V_25 * V_26 ;
V_26 = F_2 ( V_4 -> V_3 . V_27 . V_28 ,
struct V_25 , V_28 ) ;
if ( V_26 && V_26 -> V_29 )
V_26 -> V_29 ( & V_4 -> V_3 ) ;
return V_30 ;
}
static T_4 F_22 ( int V_23 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
struct V_18 * V_19 ;
T_4 V_31 = V_32 ;
unsigned long V_33 ;
F_23 ( & V_4 -> V_34 , V_33 ) ;
F_24 (info, &vp_dev->virtqueues, node) {
if ( F_25 ( V_23 , V_19 -> V_17 ) == V_30 )
V_31 = V_30 ;
}
F_26 ( & V_4 -> V_34 , V_33 ) ;
return V_31 ;
}
static T_4 F_27 ( int V_23 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
T_3 V_35 ;
V_35 = F_12 ( V_4 -> V_5 + V_36 ) ;
if ( ! V_35 )
return V_32 ;
if ( V_35 & V_37 )
F_21 ( V_23 , V_24 ) ;
return F_22 ( V_23 , V_24 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_38 ) {
F_29 ( V_4 -> V_39 -> V_23 , V_4 ) ;
V_4 -> V_38 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; ++ V_13 )
F_29 ( V_4 -> V_41 [ V_13 ] . V_42 , V_4 ) ;
if ( V_4 -> V_43 ) {
F_20 ( V_44 ,
V_4 -> V_5 + V_45 ) ;
F_30 ( V_4 -> V_5 + V_45 ) ;
F_31 ( V_4 -> V_39 ) ;
V_4 -> V_43 = 0 ;
V_4 -> V_46 = 0 ;
}
V_4 -> V_40 = 0 ;
F_32 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
F_32 ( V_4 -> V_41 ) ;
V_4 -> V_41 = NULL ;
}
static int F_33 ( struct V_2 * V_3 , int V_48 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const char * V_50 = F_34 ( & V_4 -> V_3 . V_27 ) ;
unsigned V_13 , V_51 ;
int V_52 = - V_53 ;
V_4 -> V_41 = F_35 ( V_48 * sizeof * V_4 -> V_41 ,
V_54 ) ;
if ( ! V_4 -> V_41 )
goto error;
V_4 -> V_47 = F_35 ( V_48 * sizeof * V_4 -> V_47 ,
V_54 ) ;
if ( ! V_4 -> V_47 )
goto error;
for ( V_13 = 0 ; V_13 < V_48 ; ++ V_13 )
V_4 -> V_41 [ V_13 ] . V_55 = V_13 ;
V_52 = F_36 ( V_4 -> V_39 , V_4 -> V_41 , V_48 ) ;
if ( V_52 > 0 )
V_52 = - V_56 ;
if ( V_52 )
goto error;
V_4 -> V_46 = V_48 ;
V_4 -> V_43 = 1 ;
V_51 = V_4 -> V_40 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_1 , V_50 ) ;
V_52 = F_37 ( V_4 -> V_41 [ V_51 ] . V_42 ,
F_21 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_40 ;
F_20 ( V_51 , V_4 -> V_5 + V_45 ) ;
V_51 = F_30 ( V_4 -> V_5 + V_45 ) ;
if ( V_51 == V_44 ) {
V_52 = - V_57 ;
goto error;
}
if ( ! V_49 ) {
V_51 = V_4 -> V_40 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_2 , V_50 ) ;
V_52 = F_37 ( V_4 -> V_41 [ V_51 ] . V_42 ,
F_22 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_40 ;
}
return 0 ;
error:
F_28 ( V_3 ) ;
return V_52 ;
}
static int F_38 ( struct V_2 * V_3 )
{
int V_52 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_52 = F_37 ( V_4 -> V_39 -> V_23 , F_27 ,
V_58 , F_34 ( & V_3 -> V_27 ) , V_4 ) ;
if ( ! V_52 )
V_4 -> V_38 = 1 ;
return V_52 ;
}
static struct V_16 * F_39 ( struct V_2 * V_3 , unsigned V_59 ,
void (* F_40)( struct V_16 * V_17 ) ,
const char * V_50 ,
T_5 V_60 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
unsigned long V_33 , V_61 ;
T_5 V_62 ;
int V_52 ;
F_20 ( V_59 , V_4 -> V_5 + V_63 ) ;
V_62 = F_30 ( V_4 -> V_5 + V_64 ) ;
if ( ! V_62 || F_4 ( V_4 -> V_5 + V_65 ) )
return F_41 ( - V_66 ) ;
V_19 = F_35 ( sizeof( struct V_18 ) , V_54 ) ;
if ( ! V_19 )
return F_41 ( - V_53 ) ;
V_19 -> V_21 = V_59 ;
V_19 -> V_62 = V_62 ;
V_19 -> V_67 = V_60 ;
V_61 = F_42 ( F_43 ( V_62 , V_68 ) ) ;
V_19 -> V_69 = F_44 ( V_61 , V_54 | V_70 ) ;
if ( V_19 -> V_69 == NULL ) {
V_52 = - V_53 ;
goto V_71;
}
F_9 ( F_45 ( V_19 -> V_69 ) >> V_72 ,
V_4 -> V_5 + V_65 ) ;
V_17 = F_46 ( V_19 -> V_62 , V_68 ,
V_3 , V_19 -> V_69 , F_19 , F_40 , V_50 ) ;
if ( ! V_17 ) {
V_52 = - V_53 ;
goto V_73;
}
V_17 -> V_20 = V_19 ;
V_19 -> V_17 = V_17 ;
if ( V_60 != V_44 ) {
F_20 ( V_60 , V_4 -> V_5 + V_74 ) ;
V_60 = F_30 ( V_4 -> V_5 + V_74 ) ;
if ( V_60 == V_44 ) {
V_52 = - V_57 ;
goto V_75;
}
}
F_23 ( & V_4 -> V_34 , V_33 ) ;
F_47 ( & V_19 -> V_76 , & V_4 -> V_77 ) ;
F_26 ( & V_4 -> V_34 , V_33 ) ;
return V_17 ;
V_75:
F_48 ( V_17 ) ;
V_73:
F_9 ( 0 , V_4 -> V_5 + V_65 ) ;
F_49 ( V_19 -> V_69 , V_61 ) ;
V_71:
F_32 ( V_19 ) ;
return F_41 ( V_52 ) ;
}
static void F_50 ( struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_17 -> V_3 ) ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned long V_33 , V_61 ;
F_23 ( & V_4 -> V_34 , V_33 ) ;
F_51 ( & V_19 -> V_76 ) ;
F_26 ( & V_4 -> V_34 , V_33 ) ;
F_20 ( V_19 -> V_21 , V_4 -> V_5 + V_63 ) ;
if ( V_4 -> V_43 ) {
F_20 ( V_44 ,
V_4 -> V_5 + V_74 ) ;
F_12 ( V_4 -> V_5 + V_36 ) ;
}
F_48 ( V_17 ) ;
F_9 ( 0 , V_4 -> V_5 + V_65 ) ;
V_61 = F_42 ( F_43 ( V_19 -> V_62 , V_68 ) ) ;
F_49 ( V_19 -> V_69 , V_61 ) ;
F_32 ( V_19 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 , * V_78 ;
struct V_18 * V_19 ;
F_53 (vq, n, &vdev->vqs, list) {
V_19 = V_17 -> V_20 ;
if ( V_4 -> V_49 &&
V_19 -> V_67 != V_44 )
F_29 ( V_4 -> V_41 [ V_19 -> V_67 ] . V_42 ,
V_17 ) ;
F_50 ( V_17 ) ;
}
V_4 -> V_49 = false ;
F_28 ( V_3 ) ;
}
static int F_54 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_16 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] ,
bool V_83 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_60 ;
int V_13 , V_52 , V_48 , V_84 ;
if ( ! V_83 ) {
V_52 = F_38 ( V_3 ) ;
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
V_52 = F_33 ( V_3 , V_48 , V_49 ) ;
if ( V_52 )
goto V_85;
}
V_4 -> V_49 = V_49 ;
V_84 = V_4 -> V_40 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 ) {
if ( ! V_81 [ V_13 ] || ! V_4 -> V_43 )
V_60 = V_44 ;
else if ( V_4 -> V_49 )
V_60 = V_84 ++ ;
else
V_60 = V_86 ;
V_80 [ V_13 ] = F_39 ( V_3 , V_13 , V_81 [ V_13 ] , V_82 [ V_13 ] , V_60 ) ;
if ( F_55 ( V_80 [ V_13 ] ) ) {
V_52 = F_56 ( V_80 [ V_13 ] ) ;
goto V_87;
}
if ( ! V_4 -> V_49 || V_60 == V_44 )
continue;
snprintf ( V_4 -> V_47 [ V_60 ] ,
sizeof * V_4 -> V_47 ,
L_3 ,
F_34 ( & V_4 -> V_3 . V_27 ) , V_82 [ V_13 ] ) ;
V_52 = F_37 ( V_4 -> V_41 [ V_60 ] . V_42 ,
F_25 , 0 ,
V_4 -> V_47 [ V_60 ] ,
V_80 [ V_13 ] ) ;
if ( V_52 ) {
F_50 ( V_80 [ V_13 ] ) ;
goto V_87;
}
}
return 0 ;
V_87:
F_52 ( V_3 ) ;
V_85:
return V_52 ;
}
static int F_57 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_16 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] )
{
int V_52 ;
V_52 = F_54 ( V_3 , V_79 , V_80 , V_81 , V_82 , true , true ) ;
if ( ! V_52 )
return 0 ;
V_52 = F_54 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
true , false ) ;
if ( ! V_52 )
return 0 ;
return F_54 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
false , false ) ;
}
static void F_58 ( struct V_88 * V_89 )
{
struct V_2 * V_27 = F_2 ( V_89 , struct V_2 ,
V_27 ) ;
struct V_1 * V_4 = F_1 ( V_27 ) ;
F_32 ( V_4 ) ;
}
static int T_7 F_59 ( struct V_39 * V_39 ,
const struct V_90 * V_91 )
{
struct V_1 * V_4 ;
int V_52 ;
if ( V_39 -> V_88 < 0x1000 || V_39 -> V_88 > 0x103f )
return - V_92 ;
if ( V_39 -> V_93 != V_94 ) {
F_60 ( V_95 L_4 ,
V_94 , V_39 -> V_93 ) ;
return - V_92 ;
}
V_4 = F_61 ( sizeof( struct V_1 ) , V_54 ) ;
if ( V_4 == NULL )
return - V_53 ;
V_4 -> V_3 . V_27 . V_96 = & V_39 -> V_27 ;
V_4 -> V_3 . V_27 . V_97 = F_58 ;
V_4 -> V_3 . V_98 = & V_99 ;
V_4 -> V_39 = V_39 ;
F_62 ( & V_4 -> V_77 ) ;
F_63 ( & V_4 -> V_34 ) ;
F_64 ( V_39 ) ;
V_52 = F_65 ( V_39 ) ;
if ( V_52 )
goto V_100;
V_52 = F_66 ( V_39 , L_5 ) ;
if ( V_52 )
goto V_101;
V_4 -> V_5 = F_67 ( V_39 , 0 , 0 ) ;
if ( V_4 -> V_5 == NULL )
goto V_102;
F_68 ( V_39 , V_4 ) ;
F_69 ( V_39 ) ;
V_4 -> V_3 . V_91 . V_103 = V_39 -> V_104 ;
V_4 -> V_3 . V_91 . V_88 = V_39 -> V_105 ;
V_52 = F_70 ( & V_4 -> V_3 ) ;
if ( V_52 )
goto V_106;
return 0 ;
V_106:
F_68 ( V_39 , NULL ) ;
F_71 ( V_39 , V_4 -> V_5 ) ;
V_102:
F_72 ( V_39 ) ;
V_101:
F_73 ( V_39 ) ;
V_100:
F_32 ( V_4 ) ;
return V_52 ;
}
static void T_8 F_74 ( struct V_39 * V_39 )
{
struct V_1 * V_4 = F_75 ( V_39 ) ;
F_76 ( & V_4 -> V_3 ) ;
F_52 ( & V_4 -> V_3 ) ;
F_68 ( V_39 , NULL ) ;
F_71 ( V_39 , V_4 -> V_5 ) ;
F_72 ( V_39 ) ;
F_73 ( V_39 ) ;
}
static int F_77 ( struct V_39 * V_39 , T_9 V_107 )
{
F_78 ( V_39 ) ;
F_79 ( V_39 , V_108 ) ;
return 0 ;
}
static int F_80 ( struct V_39 * V_39 )
{
F_81 ( V_39 ) ;
F_79 ( V_39 , V_109 ) ;
return 0 ;
}
static int T_10 F_82 ( void )
{
return F_83 ( & V_110 ) ;
}
static void T_11 F_84 ( void )
{
F_85 ( & V_110 ) ;
}
