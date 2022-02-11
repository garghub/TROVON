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
static bool F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
F_22 ( V_23 -> V_24 , V_4 -> V_5 + V_25 ) ;
return true ;
}
static T_4 F_23 ( int V_18 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
struct V_27 * V_28 ;
V_28 = F_2 ( V_4 -> V_3 . V_29 . V_30 ,
struct V_27 , V_30 ) ;
if ( V_28 && V_28 -> V_31 )
V_28 -> V_31 ( & V_4 -> V_3 ) ;
return V_32 ;
}
static T_4 F_24 ( int V_18 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
struct V_33 * V_34 ;
T_4 V_35 = V_36 ;
unsigned long V_37 ;
F_25 ( & V_4 -> V_38 , V_37 ) ;
F_26 (info, &vp_dev->virtqueues, node) {
if ( F_27 ( V_18 , V_34 -> V_23 ) == V_32 )
V_35 = V_32 ;
}
F_28 ( & V_4 -> V_38 , V_37 ) ;
return V_35 ;
}
static T_4 F_29 ( int V_18 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
T_3 V_39 ;
V_39 = F_12 ( V_4 -> V_5 + V_40 ) ;
if ( ! V_39 )
return V_36 ;
if ( V_39 & V_41 )
F_23 ( V_18 , V_26 ) ;
return F_24 ( V_18 , V_26 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_16 ) {
F_31 ( V_4 -> V_17 -> V_18 , V_4 ) ;
V_4 -> V_16 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_42 ; ++ V_13 )
F_31 ( V_4 -> V_20 [ V_13 ] . V_21 , V_4 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_19 ; V_13 ++ )
if ( V_4 -> V_43 [ V_13 ] )
F_32 ( V_4 -> V_43 [ V_13 ] ) ;
if ( V_4 -> V_44 ) {
F_22 ( V_45 ,
V_4 -> V_5 + V_46 ) ;
F_33 ( V_4 -> V_5 + V_46 ) ;
F_34 ( V_4 -> V_17 ) ;
V_4 -> V_44 = 0 ;
}
V_4 -> V_19 = 0 ;
V_4 -> V_42 = 0 ;
F_35 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
F_35 ( V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
F_35 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
static int F_36 ( struct V_2 * V_3 , int V_48 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const char * V_50 = F_37 ( & V_4 -> V_3 . V_29 ) ;
unsigned V_13 , V_51 ;
int V_52 = - V_53 ;
V_4 -> V_19 = V_48 ;
V_4 -> V_20 = F_38 ( V_48 * sizeof * V_4 -> V_20 ,
V_54 ) ;
if ( ! V_4 -> V_20 )
goto error;
V_4 -> V_47 = F_38 ( V_48 * sizeof * V_4 -> V_47 ,
V_54 ) ;
if ( ! V_4 -> V_47 )
goto error;
V_4 -> V_43
= F_39 ( V_48 * sizeof * V_4 -> V_43 ,
V_54 ) ;
if ( ! V_4 -> V_43 )
goto error;
for ( V_13 = 0 ; V_13 < V_48 ; ++ V_13 )
if ( ! F_40 ( & V_4 -> V_43 [ V_13 ] ,
V_54 ) )
goto error;
for ( V_13 = 0 ; V_13 < V_48 ; ++ V_13 )
V_4 -> V_20 [ V_13 ] . V_55 = V_13 ;
V_52 = F_41 ( V_4 -> V_17 , V_4 -> V_20 , V_48 ) ;
if ( V_52 > 0 )
V_52 = - V_56 ;
if ( V_52 )
goto error;
V_4 -> V_44 = 1 ;
V_51 = V_4 -> V_42 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_1 , V_50 ) ;
V_52 = F_42 ( V_4 -> V_20 [ V_51 ] . V_21 ,
F_23 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_42 ;
F_22 ( V_51 , V_4 -> V_5 + V_46 ) ;
V_51 = F_33 ( V_4 -> V_5 + V_46 ) ;
if ( V_51 == V_45 ) {
V_52 = - V_57 ;
goto error;
}
if ( ! V_49 ) {
V_51 = V_4 -> V_42 ;
snprintf ( V_4 -> V_47 [ V_51 ] , sizeof * V_4 -> V_47 ,
L_2 , V_50 ) ;
V_52 = F_42 ( V_4 -> V_20 [ V_51 ] . V_21 ,
F_24 , 0 , V_4 -> V_47 [ V_51 ] ,
V_4 ) ;
if ( V_52 )
goto error;
++ V_4 -> V_42 ;
}
return 0 ;
error:
F_30 ( V_3 ) ;
return V_52 ;
}
static int F_43 ( struct V_2 * V_3 )
{
int V_52 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_52 = F_42 ( V_4 -> V_17 -> V_18 , F_29 ,
V_58 , F_37 ( & V_3 -> V_29 ) , V_4 ) ;
if ( ! V_52 )
V_4 -> V_16 = 1 ;
return V_52 ;
}
static struct V_22 * F_44 ( struct V_2 * V_3 , unsigned V_24 ,
void (* F_45)( struct V_22 * V_23 ) ,
const char * V_50 ,
T_5 V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_33 * V_34 ;
struct V_22 * V_23 ;
unsigned long V_37 , V_60 ;
T_5 V_61 ;
int V_52 ;
F_22 ( V_24 , V_4 -> V_5 + V_62 ) ;
V_61 = F_33 ( V_4 -> V_5 + V_63 ) ;
if ( ! V_61 || F_4 ( V_4 -> V_5 + V_64 ) )
return F_46 ( - V_65 ) ;
V_34 = F_38 ( sizeof( struct V_33 ) , V_54 ) ;
if ( ! V_34 )
return F_46 ( - V_53 ) ;
V_34 -> V_61 = V_61 ;
V_34 -> V_66 = V_59 ;
V_60 = F_47 ( F_48 ( V_61 , V_67 ) ) ;
V_34 -> V_68 = F_49 ( V_60 , V_54 | V_69 ) ;
if ( V_34 -> V_68 == NULL ) {
V_52 = - V_53 ;
goto V_70;
}
F_9 ( F_50 ( V_34 -> V_68 ) >> V_71 ,
V_4 -> V_5 + V_64 ) ;
V_23 = F_51 ( V_24 , V_34 -> V_61 , V_67 , V_3 ,
true , V_34 -> V_68 , F_21 , F_45 , V_50 ) ;
if ( ! V_23 ) {
V_52 = - V_53 ;
goto V_72;
}
V_23 -> V_73 = V_34 ;
V_34 -> V_23 = V_23 ;
if ( V_59 != V_45 ) {
F_22 ( V_59 , V_4 -> V_5 + V_74 ) ;
V_59 = F_33 ( V_4 -> V_5 + V_74 ) ;
if ( V_59 == V_45 ) {
V_52 = - V_57 ;
goto V_75;
}
}
if ( F_45 ) {
F_25 ( & V_4 -> V_38 , V_37 ) ;
F_52 ( & V_34 -> V_76 , & V_4 -> V_77 ) ;
F_28 ( & V_4 -> V_38 , V_37 ) ;
} else {
F_53 ( & V_34 -> V_76 ) ;
}
return V_23 ;
V_75:
F_54 ( V_23 ) ;
V_72:
F_9 ( 0 , V_4 -> V_5 + V_64 ) ;
F_55 ( V_34 -> V_68 , V_60 ) ;
V_70:
F_35 ( V_34 ) ;
return F_46 ( V_52 ) ;
}
static void F_56 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_33 * V_34 = V_23 -> V_73 ;
unsigned long V_37 , V_60 ;
F_25 ( & V_4 -> V_38 , V_37 ) ;
F_57 ( & V_34 -> V_76 ) ;
F_28 ( & V_4 -> V_38 , V_37 ) ;
F_22 ( V_23 -> V_24 , V_4 -> V_5 + V_62 ) ;
if ( V_4 -> V_44 ) {
F_22 ( V_45 ,
V_4 -> V_5 + V_74 ) ;
F_12 ( V_4 -> V_5 + V_40 ) ;
}
F_54 ( V_23 ) ;
F_9 ( 0 , V_4 -> V_5 + V_64 ) ;
V_60 = F_47 ( F_48 ( V_34 -> V_61 , V_67 ) ) ;
F_55 ( V_34 -> V_68 , V_60 ) ;
F_35 ( V_34 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_22 * V_23 , * V_78 ;
struct V_33 * V_34 ;
F_59 (vq, n, &vdev->vqs, list) {
V_34 = V_23 -> V_73 ;
if ( V_4 -> V_49 &&
V_34 -> V_66 != V_45 )
F_31 ( V_4 -> V_20 [ V_34 -> V_66 ] . V_21 ,
V_23 ) ;
F_56 ( V_23 ) ;
}
V_4 -> V_49 = false ;
F_30 ( V_3 ) ;
}
static int F_60 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] ,
bool V_83 ,
bool V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_13 , V_52 , V_48 , V_84 ;
if ( ! V_83 ) {
V_52 = F_43 ( V_3 ) ;
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
V_52 = F_36 ( V_3 , V_48 , V_49 ) ;
if ( V_52 )
goto V_85;
}
V_4 -> V_49 = V_49 ;
V_84 = V_4 -> V_42 ;
for ( V_13 = 0 ; V_13 < V_79 ; ++ V_13 ) {
if ( ! V_82 [ V_13 ] ) {
V_80 [ V_13 ] = NULL ;
continue;
} else if ( ! V_81 [ V_13 ] || ! V_4 -> V_44 )
V_59 = V_45 ;
else if ( V_4 -> V_49 )
V_59 = V_84 ++ ;
else
V_59 = V_86 ;
V_80 [ V_13 ] = F_44 ( V_3 , V_13 , V_81 [ V_13 ] , V_82 [ V_13 ] , V_59 ) ;
if ( F_61 ( V_80 [ V_13 ] ) ) {
V_52 = F_62 ( V_80 [ V_13 ] ) ;
goto V_87;
}
if ( ! V_4 -> V_49 || V_59 == V_45 )
continue;
snprintf ( V_4 -> V_47 [ V_59 ] ,
sizeof * V_4 -> V_47 ,
L_3 ,
F_37 ( & V_4 -> V_3 . V_29 ) , V_82 [ V_13 ] ) ;
V_52 = F_42 ( V_4 -> V_20 [ V_59 ] . V_21 ,
F_27 , 0 ,
V_4 -> V_47 [ V_59 ] ,
V_80 [ V_13 ] ) ;
if ( V_52 ) {
F_56 ( V_80 [ V_13 ] ) ;
goto V_87;
}
}
return 0 ;
V_87:
F_58 ( V_3 ) ;
V_85:
return V_52 ;
}
static int F_63 ( struct V_2 * V_3 , unsigned V_79 ,
struct V_22 * V_80 [] ,
T_6 * V_81 [] ,
const char * V_82 [] )
{
int V_52 ;
V_52 = F_60 ( V_3 , V_79 , V_80 , V_81 , V_82 , true , true ) ;
if ( ! V_52 )
return 0 ;
V_52 = F_60 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
true , false ) ;
if ( ! V_52 )
return 0 ;
return F_60 ( V_3 , V_79 , V_80 , V_81 , V_82 ,
false , false ) ;
}
static const char * F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_65 ( V_4 -> V_17 ) ;
}
static int F_66 ( struct V_22 * V_23 , int V_88 )
{
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_33 * V_34 = V_23 -> V_73 ;
struct V_89 * V_90 ;
unsigned int V_18 ;
if ( ! V_23 -> F_45 )
return - V_91 ;
if ( V_4 -> V_44 ) {
V_90 = V_4 -> V_43 [ V_34 -> V_66 ] ;
V_18 = V_4 -> V_20 [ V_34 -> V_66 ] . V_21 ;
if ( V_88 == - 1 )
F_67 ( V_18 , NULL ) ;
else {
F_68 ( V_88 , V_90 ) ;
F_67 ( V_18 , V_90 ) ;
}
}
return 0 ;
}
static void F_69 ( struct V_92 * V_93 )
{
}
static int F_70 ( struct V_17 * V_17 ,
const struct V_94 * V_95 )
{
struct V_1 * V_4 ;
int V_52 ;
if ( V_17 -> V_92 < 0x1000 || V_17 -> V_92 > 0x103f )
return - V_96 ;
if ( V_17 -> V_97 != V_98 ) {
F_71 ( V_99 L_4 ,
V_98 , V_17 -> V_97 ) ;
return - V_96 ;
}
V_4 = F_39 ( sizeof( struct V_1 ) , V_54 ) ;
if ( V_4 == NULL )
return - V_53 ;
V_4 -> V_3 . V_29 . V_100 = & V_17 -> V_29 ;
V_4 -> V_3 . V_29 . V_101 = F_69 ;
V_4 -> V_3 . V_102 = & V_103 ;
V_4 -> V_17 = V_17 ;
F_53 ( & V_4 -> V_77 ) ;
F_72 ( & V_4 -> V_38 ) ;
F_73 ( V_17 ) ;
V_52 = F_74 ( V_17 ) ;
if ( V_52 )
goto V_104;
V_52 = F_75 ( V_17 , L_5 ) ;
if ( V_52 )
goto V_105;
V_4 -> V_5 = F_76 ( V_17 , 0 , 0 ) ;
if ( V_4 -> V_5 == NULL ) {
V_52 = - V_53 ;
goto V_106;
}
F_77 ( V_17 , V_4 ) ;
F_78 ( V_17 ) ;
V_4 -> V_3 . V_95 . V_107 = V_17 -> V_108 ;
V_4 -> V_3 . V_95 . V_92 = V_17 -> V_109 ;
V_52 = F_79 ( & V_4 -> V_3 ) ;
if ( V_52 )
goto V_110;
return 0 ;
V_110:
F_80 ( V_17 , V_4 -> V_5 ) ;
V_106:
F_81 ( V_17 ) ;
V_105:
F_82 ( V_17 ) ;
V_104:
F_35 ( V_4 ) ;
return V_52 ;
}
static void F_83 ( struct V_17 * V_17 )
{
struct V_1 * V_4 = F_84 ( V_17 ) ;
F_85 ( & V_4 -> V_3 ) ;
F_58 ( & V_4 -> V_3 ) ;
F_80 ( V_17 , V_4 -> V_5 ) ;
F_81 ( V_17 ) ;
F_82 ( V_17 ) ;
F_35 ( V_4 ) ;
}
static int F_86 ( struct V_92 * V_29 )
{
struct V_17 * V_17 = F_87 ( V_29 ) ;
struct V_1 * V_4 = F_84 ( V_17 ) ;
struct V_27 * V_28 ;
int V_35 ;
V_28 = F_2 ( V_4 -> V_3 . V_29 . V_30 ,
struct V_27 , V_30 ) ;
V_35 = 0 ;
V_4 -> V_111 = F_15 ( & V_4 -> V_3 ) ;
if ( V_28 && V_28 -> V_112 )
V_35 = V_28 -> V_112 ( & V_4 -> V_3 ) ;
if ( ! V_35 )
F_82 ( V_17 ) ;
return V_35 ;
}
static int F_88 ( struct V_92 * V_29 )
{
struct V_17 * V_17 = F_87 ( V_29 ) ;
struct V_1 * V_4 = F_84 ( V_17 ) ;
struct V_27 * V_28 ;
int V_35 ;
V_28 = F_2 ( V_4 -> V_3 . V_29 . V_30 ,
struct V_27 , V_30 ) ;
V_35 = F_74 ( V_17 ) ;
if ( V_35 )
return V_35 ;
F_78 ( V_17 ) ;
F_5 ( & V_4 -> V_3 ) ;
if ( V_28 && V_28 -> V_113 )
V_35 = V_28 -> V_113 ( & V_4 -> V_3 ) ;
if ( ! V_35 )
F_16 ( & V_4 -> V_3 , V_4 -> V_111 ) ;
return V_35 ;
}
