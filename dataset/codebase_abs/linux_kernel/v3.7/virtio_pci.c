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
F_22 ( F_23 ( V_23 ) ,
V_4 -> V_5 + V_24 ) ;
}
static T_4 F_24 ( int V_18 , void * V_25 )
{
struct V_1 * V_4 = V_25 ;
struct V_26 * V_27 ;
V_27 = F_2 ( V_4 -> V_3 . V_28 . V_29 ,
struct V_26 , V_29 ) ;
if ( V_27 && V_27 -> V_30 )
V_27 -> V_30 ( & V_4 -> V_3 ) ;
return V_31 ;
}
static T_4 F_25 ( int V_18 , void * V_25 )
{
struct V_1 * V_4 = V_25 ;
struct V_32 * V_33 ;
T_4 V_34 = V_35 ;
unsigned long V_36 ;
F_26 ( & V_4 -> V_37 , V_36 ) ;
F_27 (info, &vp_dev->virtqueues, node) {
if ( F_28 ( V_18 , V_33 -> V_23 ) == V_31 )
V_34 = V_31 ;
}
F_29 ( & V_4 -> V_37 , V_36 ) ;
return V_34 ;
}
static T_4 F_30 ( int V_18 , void * V_25 )
{
struct V_1 * V_4 = V_25 ;
T_3 V_38 ;
V_38 = F_12 ( V_4 -> V_5 + V_39 ) ;
if ( ! V_38 )
return V_35 ;
if ( V_38 & V_40 )
F_24 ( V_18 , V_25 ) ;
return F_25 ( V_18 , V_25 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_16 ) {
F_32 ( V_4 -> V_17 -> V_18 , V_4 ) ;
V_4 -> V_16 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_41 ; ++ V_13 )
F_32 ( V_4 -> V_20 [ V_13 ] . V_21 , V_4 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_19 ; V_13 ++ )
if ( V_4 -> V_42 [ V_13 ] )
F_33 ( V_4 -> V_42 [ V_13 ] ) ;
if ( V_4 -> V_43 ) {
F_22 ( V_44 ,
V_4 -> V_5 + V_45 ) ;
F_34 ( V_4 -> V_5 + V_45 ) ;
F_35 ( V_4 -> V_17 ) ;
V_4 -> V_43 = 0 ;
V_4 -> V_19 = 0 ;
}
V_4 -> V_41 = 0 ;
F_36 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
F_36 ( V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
F_36 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
static int F_37 ( struct V_2 * V_3 , int V_47 ,
bool V_48 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const char * V_49 = F_38 ( & V_4 -> V_3 . V_28 ) ;
unsigned V_13 , V_50 ;
int V_51 = - V_52 ;
V_4 -> V_20 = F_39 ( V_47 * sizeof * V_4 -> V_20 ,
V_53 ) ;
if ( ! V_4 -> V_20 )
goto error;
V_4 -> V_46 = F_39 ( V_47 * sizeof * V_4 -> V_46 ,
V_53 ) ;
if ( ! V_4 -> V_46 )
goto error;
V_4 -> V_42
= F_40 ( V_47 * sizeof * V_4 -> V_42 ,
V_53 ) ;
if ( ! V_4 -> V_42 )
goto error;
for ( V_13 = 0 ; V_13 < V_47 ; ++ V_13 )
if ( ! F_41 ( & V_4 -> V_42 [ V_13 ] ,
V_53 ) )
goto error;
for ( V_13 = 0 ; V_13 < V_47 ; ++ V_13 )
V_4 -> V_20 [ V_13 ] . V_54 = V_13 ;
V_51 = F_42 ( V_4 -> V_17 , V_4 -> V_20 , V_47 ) ;
if ( V_51 > 0 )
V_51 = - V_55 ;
if ( V_51 )
goto error;
V_4 -> V_19 = V_47 ;
V_4 -> V_43 = 1 ;
V_50 = V_4 -> V_41 ;
snprintf ( V_4 -> V_46 [ V_50 ] , sizeof * V_4 -> V_46 ,
L_1 , V_49 ) ;
V_51 = F_43 ( V_4 -> V_20 [ V_50 ] . V_21 ,
F_24 , 0 , V_4 -> V_46 [ V_50 ] ,
V_4 ) ;
if ( V_51 )
goto error;
++ V_4 -> V_41 ;
F_22 ( V_50 , V_4 -> V_5 + V_45 ) ;
V_50 = F_34 ( V_4 -> V_5 + V_45 ) ;
if ( V_50 == V_44 ) {
V_51 = - V_56 ;
goto error;
}
if ( ! V_48 ) {
V_50 = V_4 -> V_41 ;
snprintf ( V_4 -> V_46 [ V_50 ] , sizeof * V_4 -> V_46 ,
L_2 , V_49 ) ;
V_51 = F_43 ( V_4 -> V_20 [ V_50 ] . V_21 ,
F_25 , 0 , V_4 -> V_46 [ V_50 ] ,
V_4 ) ;
if ( V_51 )
goto error;
++ V_4 -> V_41 ;
}
return 0 ;
error:
F_31 ( V_3 ) ;
return V_51 ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_51 = F_43 ( V_4 -> V_17 -> V_18 , F_30 ,
V_57 , F_38 ( & V_3 -> V_28 ) , V_4 ) ;
if ( ! V_51 )
V_4 -> V_16 = 1 ;
return V_51 ;
}
static struct V_22 * F_45 ( struct V_2 * V_3 , unsigned V_58 ,
void (* F_46)( struct V_22 * V_23 ) ,
const char * V_49 ,
T_5 V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_22 * V_23 ;
unsigned long V_36 , V_60 ;
T_5 V_61 ;
int V_51 ;
F_22 ( V_58 , V_4 -> V_5 + V_62 ) ;
V_61 = F_34 ( V_4 -> V_5 + V_63 ) ;
if ( ! V_61 || F_4 ( V_4 -> V_5 + V_64 ) )
return F_47 ( - V_65 ) ;
V_33 = F_39 ( sizeof( struct V_32 ) , V_53 ) ;
if ( ! V_33 )
return F_47 ( - V_52 ) ;
V_33 -> V_61 = V_61 ;
V_33 -> V_66 = V_59 ;
V_60 = F_48 ( F_49 ( V_61 , V_67 ) ) ;
V_33 -> V_68 = F_50 ( V_60 , V_53 | V_69 ) ;
if ( V_33 -> V_68 == NULL ) {
V_51 = - V_52 ;
goto V_70;
}
F_9 ( F_51 ( V_33 -> V_68 ) >> V_71 ,
V_4 -> V_5 + V_64 ) ;
V_23 = F_52 ( V_58 , V_33 -> V_61 , V_67 , V_3 ,
true , V_33 -> V_68 , F_21 , F_46 , V_49 ) ;
if ( ! V_23 ) {
V_51 = - V_52 ;
goto V_72;
}
V_23 -> V_73 = V_33 ;
V_33 -> V_23 = V_23 ;
if ( V_59 != V_44 ) {
F_22 ( V_59 , V_4 -> V_5 + V_74 ) ;
V_59 = F_34 ( V_4 -> V_5 + V_74 ) ;
if ( V_59 == V_44 ) {
V_51 = - V_56 ;
goto V_75;
}
}
if ( F_46 ) {
F_26 ( & V_4 -> V_37 , V_36 ) ;
F_53 ( & V_33 -> V_76 , & V_4 -> V_77 ) ;
F_29 ( & V_4 -> V_37 , V_36 ) ;
} else {
F_54 ( & V_33 -> V_76 ) ;
}
return V_23 ;
V_75:
F_55 ( V_23 ) ;
V_72:
F_9 ( 0 , V_4 -> V_5 + V_64 ) ;
F_56 ( V_33 -> V_68 , V_60 ) ;
V_70:
F_36 ( V_33 ) ;
return F_47 ( V_51 ) ;
}
static void F_57 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_32 * V_33 = V_23 -> V_73 ;
unsigned long V_36 , V_60 ;
F_26 ( & V_4 -> V_37 , V_36 ) ;
F_58 ( & V_33 -> V_76 ) ;
F_29 ( & V_4 -> V_37 , V_36 ) ;
F_22 ( F_23 ( V_23 ) ,
V_4 -> V_5 + V_62 ) ;
if ( V_4 -> V_43 ) {
F_22 ( V_44 ,
V_4 -> V_5 + V_74 ) ;
F_12 ( V_4 -> V_5 + V_39 ) ;
}
F_55 ( V_23 ) ;
F_9 ( 0 , V_4 -> V_5 + V_64 ) ;
V_60 = F_48 ( F_49 ( V_33 -> V_61 , V_67 ) ) ;
F_56 ( V_33 -> V_68 , V_60 ) ;
F_36 ( V_33 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_22 * V_23 , * V_78 ;
struct V_32 * V_33 ;
F_60 (vq, n, &vdev->vqs, list) {
V_33 = V_23 -> V_73 ;
if ( V_4 -> V_48 &&
V_33 -> V_66 != V_44 )
F_32 ( V_4 -> V_20 [ V_33 -> V_66 ] . V_21 ,
V_23 ) ;
F_57 ( V_23 ) ;
}
V_4 -> V_48 = false ;
F_31 ( V_3 ) ;
}
static int F_61 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] ,
bool V_83 ,
bool V_48 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_13 , V_51 , V_47 , V_84 ;
if ( ! V_83 ) {
V_51 = F_44 ( V_3 ) ;
if ( V_51 )
goto V_85;
} else {
if ( V_48 ) {
V_47 = 1 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 )
if ( V_81 [ V_13 ] )
++ V_47 ;
} else {
V_47 = 2 ;
}
V_51 = F_37 ( V_3 , V_47 , V_48 ) ;
if ( V_51 )
goto V_85;
}
V_4 -> V_48 = V_48 ;
V_84 = V_4 -> V_41 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 ) {
if ( ! V_82 [ V_13 ] ) {
V_80 [ V_13 ] = NULL ;
continue;
} else if ( ! V_81 [ V_13 ] || ! V_4 -> V_43 )
V_59 = V_44 ;
else if ( V_4 -> V_48 )
V_59 = V_84 ++ ;
else
V_59 = V_86 ;
V_80 [ V_13 ] = F_45 ( V_3 , V_13 , V_81 [ V_13 ] , V_82 [ V_13 ] , V_59 ) ;
if ( F_62 ( V_80 [ V_13 ] ) ) {
V_51 = F_63 ( V_80 [ V_13 ] ) ;
goto V_87;
}
if ( ! V_4 -> V_48 || V_59 == V_44 )
continue;
snprintf ( V_4 -> V_46 [ V_59 ] ,
sizeof * V_4 -> V_46 ,
L_3 ,
F_38 ( & V_4 -> V_3 . V_28 ) , V_82 [ V_13 ] ) ;
V_51 = F_43 ( V_4 -> V_20 [ V_59 ] . V_21 ,
F_28 , 0 ,
V_4 -> V_46 [ V_59 ] ,
V_80 [ V_13 ] ) ;
if ( V_51 ) {
F_57 ( V_80 [ V_13 ] ) ;
goto V_87;
}
}
return 0 ;
V_87:
F_59 ( V_3 ) ;
V_85:
return V_51 ;
}
static int F_64 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] )
{
int V_51 ;
V_51 = F_61 ( V_3 , V_79 , V_80 , V_81 , V_82 , true , true ) ;
if ( ! V_51 )
return 0 ;
V_51 = F_61 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
true , false ) ;
if ( ! V_51 )
return 0 ;
return F_61 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
false , false ) ;
}
static const char * F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_66 ( V_4 -> V_17 ) ;
}
static int F_67 ( struct V_22 * V_23 , int V_88 )
{
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_32 * V_33 = V_23 -> V_73 ;
struct V_89 * V_90 ;
unsigned int V_18 ;
if ( ! V_23 -> F_46 )
return - V_91 ;
if ( V_4 -> V_43 ) {
V_90 = V_4 -> V_42 [ V_33 -> V_66 ] ;
V_18 = V_4 -> V_20 [ V_33 -> V_66 ] . V_21 ;
if ( V_88 == - 1 )
F_68 ( V_18 , NULL ) ;
else {
F_69 ( V_88 , V_90 ) ;
F_68 ( V_18 , V_90 ) ;
}
}
return 0 ;
}
static void F_70 ( struct V_92 * V_93 )
{
}
static int T_7 F_71 ( struct V_17 * V_17 ,
const struct V_94 * V_95 )
{
struct V_1 * V_4 ;
int V_51 ;
if ( V_17 -> V_92 < 0x1000 || V_17 -> V_92 > 0x103f )
return - V_96 ;
if ( V_17 -> V_97 != V_98 ) {
F_72 ( V_99 L_4 ,
V_98 , V_17 -> V_97 ) ;
return - V_96 ;
}
V_4 = F_40 ( sizeof( struct V_1 ) , V_53 ) ;
if ( V_4 == NULL )
return - V_52 ;
V_4 -> V_3 . V_28 . V_100 = & V_17 -> V_28 ;
V_4 -> V_3 . V_28 . V_101 = F_70 ;
V_4 -> V_3 . V_102 = & V_103 ;
V_4 -> V_17 = V_17 ;
F_54 ( & V_4 -> V_77 ) ;
F_73 ( & V_4 -> V_37 ) ;
F_74 ( V_17 ) ;
V_51 = F_75 ( V_17 ) ;
if ( V_51 )
goto V_104;
V_51 = F_76 ( V_17 , L_5 ) ;
if ( V_51 )
goto V_105;
V_4 -> V_5 = F_77 ( V_17 , 0 , 0 ) ;
if ( V_4 -> V_5 == NULL ) {
V_51 = - V_52 ;
goto V_106;
}
F_78 ( V_17 , V_4 ) ;
F_79 ( V_17 ) ;
V_4 -> V_3 . V_95 . V_107 = V_17 -> V_108 ;
V_4 -> V_3 . V_95 . V_92 = V_17 -> V_109 ;
V_51 = F_80 ( & V_4 -> V_3 ) ;
if ( V_51 )
goto V_110;
return 0 ;
V_110:
F_78 ( V_17 , NULL ) ;
F_81 ( V_17 , V_4 -> V_5 ) ;
V_106:
F_82 ( V_17 ) ;
V_105:
F_83 ( V_17 ) ;
V_104:
F_36 ( V_4 ) ;
return V_51 ;
}
static void T_8 F_84 ( struct V_17 * V_17 )
{
struct V_1 * V_4 = F_85 ( V_17 ) ;
F_86 ( & V_4 -> V_3 ) ;
F_59 ( & V_4 -> V_3 ) ;
F_78 ( V_17 , NULL ) ;
F_81 ( V_17 , V_4 -> V_5 ) ;
F_82 ( V_17 ) ;
F_83 ( V_17 ) ;
F_36 ( V_4 ) ;
}
static int F_87 ( struct V_92 * V_28 )
{
struct V_17 * V_17 = F_88 ( V_28 ) ;
struct V_1 * V_4 = F_85 ( V_17 ) ;
struct V_26 * V_27 ;
int V_34 ;
V_27 = F_2 ( V_4 -> V_3 . V_28 . V_29 ,
struct V_26 , V_29 ) ;
V_34 = 0 ;
V_4 -> V_111 = F_15 ( & V_4 -> V_3 ) ;
if ( V_27 && V_27 -> V_112 )
V_34 = V_27 -> V_112 ( & V_4 -> V_3 ) ;
if ( ! V_34 )
F_83 ( V_17 ) ;
return V_34 ;
}
static int F_89 ( struct V_92 * V_28 )
{
struct V_17 * V_17 = F_88 ( V_28 ) ;
struct V_1 * V_4 = F_85 ( V_17 ) ;
struct V_26 * V_27 ;
int V_34 ;
V_27 = F_2 ( V_4 -> V_3 . V_28 . V_29 ,
struct V_26 , V_29 ) ;
V_34 = F_75 ( V_17 ) ;
if ( V_34 )
return V_34 ;
F_79 ( V_17 ) ;
F_5 ( & V_4 -> V_3 ) ;
if ( V_27 && V_27 -> V_113 )
V_34 = V_27 -> V_113 ( & V_4 -> V_3 ) ;
if ( ! V_34 )
F_16 ( & V_4 -> V_3 , V_4 -> V_111 ) ;
return V_34 ;
}
static int T_9 F_90 ( void )
{
return F_91 ( & V_114 ) ;
}
static void T_10 F_92 ( void )
{
F_93 ( & V_114 ) ;
}
