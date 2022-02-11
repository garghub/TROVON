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
F_24 ( & V_4 -> V_3 ) ;
return V_27 ;
}
static T_4 F_25 ( int V_18 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
struct V_28 * V_29 ;
T_4 V_30 = V_31 ;
unsigned long V_32 ;
F_26 ( & V_4 -> V_33 , V_32 ) ;
F_27 (info, &vp_dev->virtqueues, node) {
if ( F_28 ( V_18 , V_29 -> V_23 ) == V_27 )
V_30 = V_27 ;
}
F_29 ( & V_4 -> V_33 , V_32 ) ;
return V_30 ;
}
static T_4 F_30 ( int V_18 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
T_3 V_34 ;
V_34 = F_12 ( V_4 -> V_5 + V_35 ) ;
if ( ! V_34 )
return V_31 ;
if ( V_34 & V_36 )
F_23 ( V_18 , V_26 ) ;
return F_25 ( V_18 , V_26 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
if ( V_4 -> V_16 ) {
F_32 ( V_4 -> V_17 -> V_18 , V_4 ) ;
V_4 -> V_16 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_37 ; ++ V_13 )
F_32 ( V_4 -> V_20 [ V_13 ] . V_21 , V_4 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_19 ; V_13 ++ )
if ( V_4 -> V_38 [ V_13 ] )
F_33 ( V_4 -> V_38 [ V_13 ] ) ;
if ( V_4 -> V_39 ) {
F_22 ( V_40 ,
V_4 -> V_5 + V_41 ) ;
F_34 ( V_4 -> V_5 + V_41 ) ;
F_35 ( V_4 -> V_17 ) ;
V_4 -> V_39 = 0 ;
}
V_4 -> V_19 = 0 ;
V_4 -> V_37 = 0 ;
F_36 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
F_36 ( V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
F_36 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
}
static int F_37 ( struct V_2 * V_3 , int V_43 ,
bool V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const char * V_45 = F_38 ( & V_4 -> V_3 . V_46 ) ;
unsigned V_13 , V_47 ;
int V_48 = - V_49 ;
V_4 -> V_19 = V_43 ;
V_4 -> V_20 = F_39 ( V_43 * sizeof * V_4 -> V_20 ,
V_50 ) ;
if ( ! V_4 -> V_20 )
goto error;
V_4 -> V_42 = F_39 ( V_43 * sizeof * V_4 -> V_42 ,
V_50 ) ;
if ( ! V_4 -> V_42 )
goto error;
V_4 -> V_38
= F_40 ( V_43 * sizeof * V_4 -> V_38 ,
V_50 ) ;
if ( ! V_4 -> V_38 )
goto error;
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 )
if ( ! F_41 ( & V_4 -> V_38 [ V_13 ] ,
V_50 ) )
goto error;
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 )
V_4 -> V_20 [ V_13 ] . V_51 = V_13 ;
V_48 = F_42 ( V_4 -> V_17 ,
V_4 -> V_20 , V_43 ) ;
if ( V_48 )
goto error;
V_4 -> V_39 = 1 ;
V_47 = V_4 -> V_37 ;
snprintf ( V_4 -> V_42 [ V_47 ] , sizeof * V_4 -> V_42 ,
L_1 , V_45 ) ;
V_48 = F_43 ( V_4 -> V_20 [ V_47 ] . V_21 ,
F_23 , 0 , V_4 -> V_42 [ V_47 ] ,
V_4 ) ;
if ( V_48 )
goto error;
++ V_4 -> V_37 ;
F_22 ( V_47 , V_4 -> V_5 + V_41 ) ;
V_47 = F_34 ( V_4 -> V_5 + V_41 ) ;
if ( V_47 == V_40 ) {
V_48 = - V_52 ;
goto error;
}
if ( ! V_44 ) {
V_47 = V_4 -> V_37 ;
snprintf ( V_4 -> V_42 [ V_47 ] , sizeof * V_4 -> V_42 ,
L_2 , V_45 ) ;
V_48 = F_43 ( V_4 -> V_20 [ V_47 ] . V_21 ,
F_25 , 0 , V_4 -> V_42 [ V_47 ] ,
V_4 ) ;
if ( V_48 )
goto error;
++ V_4 -> V_37 ;
}
return 0 ;
error:
F_31 ( V_3 ) ;
return V_48 ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_48 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_48 = F_43 ( V_4 -> V_17 -> V_18 , F_30 ,
V_53 , F_38 ( & V_3 -> V_46 ) , V_4 ) ;
if ( ! V_48 )
V_4 -> V_16 = 1 ;
return V_48 ;
}
static struct V_22 * F_45 ( struct V_2 * V_3 , unsigned V_24 ,
void (* F_46)( struct V_22 * V_23 ) ,
const char * V_45 ,
T_5 V_54 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
struct V_22 * V_23 ;
unsigned long V_32 , V_55 ;
T_5 V_56 ;
int V_48 ;
F_22 ( V_24 , V_4 -> V_5 + V_57 ) ;
V_56 = F_34 ( V_4 -> V_5 + V_58 ) ;
if ( ! V_56 || F_4 ( V_4 -> V_5 + V_59 ) )
return F_47 ( - V_60 ) ;
V_29 = F_39 ( sizeof( struct V_28 ) , V_50 ) ;
if ( ! V_29 )
return F_47 ( - V_49 ) ;
V_29 -> V_56 = V_56 ;
V_29 -> V_61 = V_54 ;
V_55 = F_48 ( F_49 ( V_56 , V_62 ) ) ;
V_29 -> V_63 = F_50 ( V_55 , V_50 | V_64 ) ;
if ( V_29 -> V_63 == NULL ) {
V_48 = - V_49 ;
goto V_65;
}
F_9 ( F_51 ( V_29 -> V_63 ) >> V_66 ,
V_4 -> V_5 + V_59 ) ;
V_23 = F_52 ( V_24 , V_29 -> V_56 , V_62 , V_3 ,
true , V_29 -> V_63 , F_21 , F_46 , V_45 ) ;
if ( ! V_23 ) {
V_48 = - V_49 ;
goto V_67;
}
V_23 -> V_68 = V_29 ;
V_29 -> V_23 = V_23 ;
if ( V_54 != V_40 ) {
F_22 ( V_54 , V_4 -> V_5 + V_69 ) ;
V_54 = F_34 ( V_4 -> V_5 + V_69 ) ;
if ( V_54 == V_40 ) {
V_48 = - V_52 ;
goto V_70;
}
}
if ( F_46 ) {
F_26 ( & V_4 -> V_33 , V_32 ) ;
F_53 ( & V_29 -> V_71 , & V_4 -> V_72 ) ;
F_29 ( & V_4 -> V_33 , V_32 ) ;
} else {
F_54 ( & V_29 -> V_71 ) ;
}
return V_23 ;
V_70:
F_55 ( V_23 ) ;
V_67:
F_9 ( 0 , V_4 -> V_5 + V_59 ) ;
F_56 ( V_29 -> V_63 , V_55 ) ;
V_65:
F_36 ( V_29 ) ;
return F_47 ( V_48 ) ;
}
static void F_57 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_28 * V_29 = V_23 -> V_68 ;
unsigned long V_32 , V_55 ;
F_26 ( & V_4 -> V_33 , V_32 ) ;
F_58 ( & V_29 -> V_71 ) ;
F_29 ( & V_4 -> V_33 , V_32 ) ;
F_22 ( V_23 -> V_24 , V_4 -> V_5 + V_57 ) ;
if ( V_4 -> V_39 ) {
F_22 ( V_40 ,
V_4 -> V_5 + V_69 ) ;
F_12 ( V_4 -> V_5 + V_35 ) ;
}
F_55 ( V_23 ) ;
F_9 ( 0 , V_4 -> V_5 + V_59 ) ;
V_55 = F_48 ( F_49 ( V_29 -> V_56 , V_62 ) ) ;
F_56 ( V_29 -> V_63 , V_55 ) ;
F_36 ( V_29 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_22 * V_23 , * V_73 ;
struct V_28 * V_29 ;
F_60 (vq, n, &vdev->vqs, list) {
V_29 = V_23 -> V_68 ;
if ( V_4 -> V_44 &&
V_29 -> V_61 != V_40 )
F_32 ( V_4 -> V_20 [ V_29 -> V_61 ] . V_21 ,
V_23 ) ;
F_57 ( V_23 ) ;
}
V_4 -> V_44 = false ;
F_31 ( V_3 ) ;
}
static int F_61 ( struct V_2 * V_3 , unsigned V_74 ,
struct V_22 * V_75 [] ,
T_6 * V_76 [] ,
const char * V_77 [] ,
bool V_78 ,
bool V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_54 ;
int V_13 , V_48 , V_43 , V_79 ;
if ( ! V_78 ) {
V_48 = F_44 ( V_3 ) ;
if ( V_48 )
goto V_80;
} else {
if ( V_44 ) {
V_43 = 1 ;
for ( V_13 = 0 ; V_13 < V_74 ; ++ V_13 )
if ( V_76 [ V_13 ] )
++ V_43 ;
} else {
V_43 = 2 ;
}
V_48 = F_37 ( V_3 , V_43 , V_44 ) ;
if ( V_48 )
goto V_80;
}
V_4 -> V_44 = V_44 ;
V_79 = V_4 -> V_37 ;
for ( V_13 = 0 ; V_13 < V_74 ; ++ V_13 ) {
if ( ! V_77 [ V_13 ] ) {
V_75 [ V_13 ] = NULL ;
continue;
} else if ( ! V_76 [ V_13 ] || ! V_4 -> V_39 )
V_54 = V_40 ;
else if ( V_4 -> V_44 )
V_54 = V_79 ++ ;
else
V_54 = V_81 ;
V_75 [ V_13 ] = F_45 ( V_3 , V_13 , V_76 [ V_13 ] , V_77 [ V_13 ] , V_54 ) ;
if ( F_62 ( V_75 [ V_13 ] ) ) {
V_48 = F_63 ( V_75 [ V_13 ] ) ;
goto V_82;
}
if ( ! V_4 -> V_44 || V_54 == V_40 )
continue;
snprintf ( V_4 -> V_42 [ V_54 ] ,
sizeof * V_4 -> V_42 ,
L_3 ,
F_38 ( & V_4 -> V_3 . V_46 ) , V_77 [ V_13 ] ) ;
V_48 = F_43 ( V_4 -> V_20 [ V_54 ] . V_21 ,
F_28 , 0 ,
V_4 -> V_42 [ V_54 ] ,
V_75 [ V_13 ] ) ;
if ( V_48 ) {
F_57 ( V_75 [ V_13 ] ) ;
goto V_82;
}
}
return 0 ;
V_82:
F_59 ( V_3 ) ;
V_80:
return V_48 ;
}
static int F_64 ( struct V_2 * V_3 , unsigned V_74 ,
struct V_22 * V_75 [] ,
T_6 * V_76 [] ,
const char * V_77 [] )
{
int V_48 ;
V_48 = F_61 ( V_3 , V_74 , V_75 , V_76 , V_77 , true , true ) ;
if ( ! V_48 )
return 0 ;
V_48 = F_61 ( V_3 , V_74 , V_75 , V_76 , V_77 ,
true , false ) ;
if ( ! V_48 )
return 0 ;
return F_61 ( V_3 , V_74 , V_75 , V_76 , V_77 ,
false , false ) ;
}
static const char * F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_66 ( V_4 -> V_17 ) ;
}
static int F_67 ( struct V_22 * V_23 , int V_83 )
{
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_23 -> V_68 ;
struct V_84 * V_85 ;
unsigned int V_18 ;
if ( ! V_23 -> F_46 )
return - V_86 ;
if ( V_4 -> V_39 ) {
V_85 = V_4 -> V_38 [ V_29 -> V_61 ] ;
V_18 = V_4 -> V_20 [ V_29 -> V_61 ] . V_21 ;
if ( V_83 == - 1 )
F_68 ( V_18 , NULL ) ;
else {
F_69 ( V_83 , V_85 ) ;
F_68 ( V_18 , V_85 ) ;
}
}
return 0 ;
}
static void F_70 ( struct V_87 * V_88 )
{
}
static int F_71 ( struct V_17 * V_17 ,
const struct V_89 * V_90 )
{
struct V_1 * V_4 ;
int V_48 ;
if ( V_17 -> V_87 < 0x1000 || V_17 -> V_87 > 0x103f )
return - V_91 ;
if ( V_17 -> V_92 != V_93 ) {
F_72 ( V_94 L_4 ,
V_93 , V_17 -> V_92 ) ;
return - V_91 ;
}
V_4 = F_40 ( sizeof( struct V_1 ) , V_50 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_3 . V_46 . V_95 = & V_17 -> V_46 ;
V_4 -> V_3 . V_46 . V_96 = F_70 ;
V_4 -> V_3 . V_97 = & V_98 ;
V_4 -> V_17 = V_17 ;
F_54 ( & V_4 -> V_72 ) ;
F_73 ( & V_4 -> V_33 ) ;
F_74 ( V_17 ) ;
V_48 = F_75 ( V_17 ) ;
if ( V_48 )
goto V_99;
V_48 = F_76 ( V_17 , L_5 ) ;
if ( V_48 )
goto V_100;
V_4 -> V_5 = F_77 ( V_17 , 0 , 0 ) ;
if ( V_4 -> V_5 == NULL ) {
V_48 = - V_49 ;
goto V_101;
}
F_78 ( V_17 , V_4 ) ;
F_79 ( V_17 ) ;
V_4 -> V_3 . V_90 . V_102 = V_17 -> V_103 ;
V_4 -> V_3 . V_90 . V_87 = V_17 -> V_104 ;
V_48 = F_80 ( & V_4 -> V_3 ) ;
if ( V_48 )
goto V_105;
return 0 ;
V_105:
F_81 ( V_17 , V_4 -> V_5 ) ;
V_101:
F_82 ( V_17 ) ;
V_100:
F_83 ( V_17 ) ;
V_99:
F_36 ( V_4 ) ;
return V_48 ;
}
static void F_84 ( struct V_17 * V_17 )
{
struct V_1 * V_4 = F_85 ( V_17 ) ;
F_86 ( & V_4 -> V_3 ) ;
F_59 ( & V_4 -> V_3 ) ;
F_81 ( V_17 , V_4 -> V_5 ) ;
F_82 ( V_17 ) ;
F_83 ( V_17 ) ;
F_36 ( V_4 ) ;
}
static int F_87 ( struct V_87 * V_46 )
{
struct V_17 * V_17 = F_88 ( V_46 ) ;
struct V_1 * V_4 = F_85 ( V_17 ) ;
int V_30 ;
V_30 = F_89 ( & V_4 -> V_3 ) ;
if ( ! V_30 )
F_83 ( V_17 ) ;
return V_30 ;
}
static int F_90 ( struct V_87 * V_46 )
{
struct V_17 * V_17 = F_88 ( V_46 ) ;
struct V_1 * V_4 = F_85 ( V_17 ) ;
int V_30 ;
V_30 = F_75 ( V_17 ) ;
if ( V_30 )
return V_30 ;
F_79 ( V_17 ) ;
return F_91 ( & V_4 -> V_3 ) ;
}
