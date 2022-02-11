static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 -> V_8 ; V_6 ++ ) {
if ( V_3 >= V_2 -> V_7 -> V_9 [ V_6 ] . V_10 &&
V_3 <= V_2 -> V_7 -> V_9 [ V_6 ] . V_11 ) {
* V_5 = & V_2 -> V_7 -> V_9 [ V_6 ] ;
return 0 ;
}
}
return - V_12 ;
}
static void F_2 ( struct V_4 * V_5 , unsigned int V_3 ,
enum V_13 V_14 ,
unsigned int * V_15 , unsigned int * V_16 )
{
struct V_17 * V_18 = & V_5 -> V_19 [ V_14 ] ;
* V_15 = V_18 -> V_15 * 4 ;
* V_16 = V_18 -> V_16 + V_3 - V_5 -> V_10 ;
}
static int F_3 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return V_2 -> V_7 -> V_22 ;
}
static const char * F_5 ( struct V_20 * V_21 ,
unsigned V_23 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return V_2 -> V_7 -> V_24 [ V_23 ] . V_25 ;
}
static int F_6 ( struct V_20 * V_21 , unsigned V_23 ,
const unsigned * * V_26 , unsigned * V_27 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
* V_26 = V_2 -> V_7 -> V_24 [ V_23 ] . V_26 ;
* V_27 = V_2 -> V_7 -> V_24 [ V_23 ] . V_27 ;
return 0 ;
}
static void F_7 ( struct V_20 * V_21 , struct V_28 * V_29 ,
unsigned V_30 )
{
F_8 ( V_29 , L_1 , F_9 ( V_21 -> V_31 ) ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_32 )
{
struct V_33 * V_34 ;
int V_6 , V_35 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 -> V_22 ; V_6 ++ ) {
V_34 = & V_2 -> V_7 -> V_24 [ V_6 ] ;
if ( V_34 -> V_36 || V_6 == V_32 )
continue;
for ( V_35 = 0 ; V_35 < V_34 -> V_27 ; V_35 ++ ) {
if ( V_34 -> V_26 [ V_35 ] == V_3 ) {
F_11 ( V_2 -> V_37 ,
V_34 -> V_15 * 4 ,
F_12 ( V_34 -> V_16 ) , 0 ) ;
}
}
}
}
static int F_13 ( struct V_20 * V_21 , unsigned V_38 ,
unsigned V_39 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
struct V_40 * V_41 = & V_2 -> V_7 -> V_42 [ V_38 ] ;
struct V_33 * V_34 = & V_2 -> V_7 -> V_24 [ V_39 ] ;
int V_6 , V_43 = 0 ;
F_14 ( V_2 -> V_31 , L_2 , V_41 -> V_25 ,
V_34 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < V_34 -> V_27 ; V_6 ++ )
F_10 ( V_2 , V_34 -> V_26 [ V_6 ] , V_39 ) ;
if ( V_38 )
V_43 = F_11 ( V_2 -> V_37 , V_34 -> V_15 * 4 ,
F_12 ( V_34 -> V_16 ) , F_12 ( V_34 -> V_16 ) ) ;
return V_43 ;
}
static int F_15 ( struct V_20 * V_21 ,
struct V_44 * V_45 ,
unsigned V_30 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
F_10 ( V_2 , V_45 -> V_46 + V_30 , - 1 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return V_2 -> V_7 -> V_47 ;
}
static const char * F_17 ( struct V_20 * V_21 ,
unsigned V_23 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return V_2 -> V_7 -> V_42 [ V_23 ] . V_25 ;
}
static int F_18 ( struct V_20 * V_21 , unsigned V_23 ,
const char * const * * V_24 ,
unsigned * const V_22 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
* V_24 = V_2 -> V_7 -> V_42 [ V_23 ] . V_24 ;
* V_22 = V_2 -> V_7 -> V_42 [ V_23 ] . V_22 ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , unsigned int V_3 ,
unsigned long * V_48 , unsigned V_49 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
struct V_4 * V_5 ;
enum V_50 V_51 ;
unsigned int V_15 , V_16 ;
int V_6 , V_43 ;
T_1 V_52 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return V_43 ;
for ( V_6 = 0 ; V_6 < V_49 ; V_6 ++ ) {
V_51 = F_20 ( V_48 [ V_6 ] ) ;
V_52 = F_21 ( V_48 [ V_6 ] ) ;
switch ( V_51 ) {
case V_53 :
F_14 ( V_2 -> V_31 , L_3 , V_3 ) ;
F_2 ( V_5 , V_3 , V_54 , & V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_55 , V_15 ,
F_12 ( V_16 ) , 0 ) ;
if ( V_43 )
return V_43 ;
break;
case V_56 :
F_14 ( V_2 -> V_31 , L_4 , V_3 ) ;
F_2 ( V_5 , V_3 , V_57 ,
& V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_58 , V_15 ,
F_12 ( V_16 ) , F_12 ( V_16 ) ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_54 , & V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_55 , V_15 ,
F_12 ( V_16 ) , F_12 ( V_16 ) ) ;
if ( V_43 )
return V_43 ;
break;
case V_59 :
F_14 ( V_2 -> V_31 , L_5 , V_3 ) ;
F_2 ( V_5 , V_3 , V_57 ,
& V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_58 , V_15 ,
F_12 ( V_16 ) , F_12 ( V_16 ) ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_54 , & V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_55 , V_15 ,
F_12 ( V_16 ) , 0 ) ;
if ( V_43 )
return V_43 ;
break;
default:
return - V_60 ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
unsigned int V_15 , V_16 , V_61 ;
int V_43 , V_62 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_57 , & V_15 , & V_16 ) ;
V_43 = F_23 ( V_2 -> V_58 , V_15 , & V_61 ) ;
if ( V_43 )
return V_43 ;
if ( ! ( V_61 & F_12 ( V_16 ) ) ) {
V_62 = V_53 ;
} else {
F_2 ( V_5 , V_3 , V_54 , & V_15 , & V_16 ) ;
V_43 = F_23 ( V_2 -> V_55 , V_15 , & V_61 ) ;
if ( V_43 )
return V_43 ;
if ( V_61 & F_12 ( V_16 ) )
V_62 = V_56 ;
else
V_62 = V_59 ;
}
return V_62 ;
}
static int F_24 ( struct V_20 * V_21 , unsigned int V_3 ,
unsigned long * V_63 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
enum V_50 V_51 = F_20 ( * V_63 ) ;
T_1 V_52 ;
switch ( V_51 ) {
case V_53 :
case V_59 :
case V_56 :
if ( F_22 ( V_2 , V_3 ) == V_51 )
V_52 = 1 ;
else
return - V_12 ;
break;
default:
return - V_60 ;
}
* V_63 = F_25 ( V_51 , V_52 ) ;
F_14 ( V_2 -> V_31 , L_6 , V_3 , * V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 ,
unsigned int V_64 ,
unsigned long * V_48 , unsigned V_49 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
struct V_33 * V_34 = & V_2 -> V_7 -> V_24 [ V_64 ] ;
int V_6 ;
F_14 ( V_2 -> V_31 , L_7 , V_34 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < V_34 -> V_27 ; V_6 ++ ) {
F_19 ( V_21 , V_34 -> V_26 [ V_6 ] , V_48 ,
V_49 ) ;
}
return 0 ;
}
static int F_27 ( struct V_20 * V_21 ,
unsigned int V_34 , unsigned long * V_63 )
{
return - V_65 ;
}
static int F_28 ( struct V_66 * V_67 , unsigned V_68 )
{
return F_29 ( V_67 -> V_69 + V_68 ) ;
}
static void F_30 ( struct V_66 * V_67 , unsigned V_68 )
{
struct V_1 * V_2 = F_31 ( V_67 ) ;
F_32 ( V_2 -> V_7 -> V_46 + V_68 ) ;
}
static int F_33 ( struct V_66 * V_67 , unsigned V_68 )
{
struct V_1 * V_2 = F_31 ( V_67 ) ;
unsigned int V_15 , V_16 , V_3 ;
struct V_4 * V_5 ;
int V_43 ;
V_3 = V_2 -> V_7 -> V_46 + V_68 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_70 , & V_15 , & V_16 ) ;
return F_11 ( V_2 -> V_71 , V_15 , F_12 ( V_16 ) , F_12 ( V_16 ) ) ;
}
static int F_34 ( struct V_66 * V_67 , unsigned V_68 ,
int V_72 )
{
struct V_1 * V_2 = F_31 ( V_67 ) ;
unsigned int V_15 , V_16 , V_3 ;
struct V_4 * V_5 ;
int V_43 ;
V_3 = V_2 -> V_7 -> V_46 + V_68 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_70 , & V_15 , & V_16 ) ;
V_43 = F_11 ( V_2 -> V_71 , V_15 , F_12 ( V_16 ) , 0 ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_73 , & V_15 , & V_16 ) ;
return F_11 ( V_2 -> V_71 , V_15 , F_12 ( V_16 ) ,
V_72 ? F_12 ( V_16 ) : 0 ) ;
}
static void F_35 ( struct V_66 * V_67 , unsigned V_68 , int V_72 )
{
struct V_1 * V_2 = F_31 ( V_67 ) ;
unsigned int V_15 , V_16 , V_3 ;
struct V_4 * V_5 ;
int V_43 ;
V_3 = V_2 -> V_7 -> V_46 + V_68 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return;
F_2 ( V_5 , V_3 , V_73 , & V_15 , & V_16 ) ;
F_11 ( V_2 -> V_71 , V_15 , F_12 ( V_16 ) ,
V_72 ? F_12 ( V_16 ) : 0 ) ;
}
static int F_36 ( struct V_66 * V_67 , unsigned V_68 )
{
struct V_1 * V_2 = F_31 ( V_67 ) ;
unsigned int V_15 , V_16 , V_61 , V_3 ;
struct V_4 * V_5 ;
int V_43 ;
V_3 = V_2 -> V_7 -> V_46 + V_68 ;
V_43 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_43 )
return V_43 ;
F_2 ( V_5 , V_3 , V_74 , & V_15 , & V_16 ) ;
F_23 ( V_2 -> V_71 , V_15 , & V_61 ) ;
return ! ! ( V_61 & F_12 ( V_16 ) ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_43 ;
V_2 -> V_67 . V_75 = V_2 -> V_7 -> V_25 ;
V_2 -> V_67 . V_76 = V_2 -> V_31 ;
V_2 -> V_67 . V_77 = F_28 ;
V_2 -> V_67 . free = F_30 ;
V_2 -> V_67 . V_78 = F_33 ;
V_2 -> V_67 . V_79 = F_34 ;
V_2 -> V_67 . V_80 = F_36 ;
V_2 -> V_67 . V_81 = F_35 ;
V_2 -> V_67 . V_69 = V_2 -> V_7 -> V_46 ;
V_2 -> V_67 . V_82 = V_2 -> V_7 -> V_27 ;
V_2 -> V_67 . V_83 = false ;
V_2 -> V_67 . V_84 = V_2 -> V_84 ;
V_2 -> V_67 . V_85 = 2 ;
V_43 = F_38 ( & V_2 -> V_67 , V_2 ) ;
if ( V_43 ) {
F_39 ( V_2 -> V_31 , L_8 ,
V_2 -> V_7 -> V_25 ) ;
goto V_86;
}
V_43 = F_40 ( & V_2 -> V_67 , F_9 ( V_2 -> V_31 ) ,
0 , V_2 -> V_7 -> V_46 ,
V_2 -> V_67 . V_82 ) ;
if ( V_43 ) {
F_39 ( V_2 -> V_31 , L_9 ) ;
goto V_86;
}
return 0 ;
V_86:
F_41 ( & V_2 -> V_67 ) ;
return V_43 ;
}
static struct V_87 * F_42 ( struct V_1 * V_2 ,
struct V_88 * V_89 , char * V_25 )
{
struct V_90 V_91 ;
void T_2 * V_69 ;
int V_6 ;
V_6 = F_43 ( V_89 , L_10 , V_25 ) ;
if ( F_44 ( V_89 , V_6 , & V_91 ) )
return F_45 ( - V_92 ) ;
V_69 = F_46 ( V_2 -> V_31 , & V_91 ) ;
if ( F_47 ( V_69 ) )
return F_48 ( V_69 ) ;
V_93 . V_94 = F_49 ( & V_91 ) - 4 ;
V_93 . V_25 = F_50 ( V_2 -> V_31 , V_95 ,
L_11 , V_89 -> V_25 ,
V_25 ) ;
if ( ! V_93 . V_25 )
return F_45 ( - V_96 ) ;
return F_51 ( V_2 -> V_31 , V_69 , & V_93 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_88 * V_97 , * V_98 = NULL ;
F_53 (node, np) {
if ( ! F_54 ( V_97 , L_12 , NULL ) )
continue;
if ( V_98 ) {
F_39 ( V_2 -> V_31 , L_13 ) ;
return - V_12 ;
}
V_98 = V_97 ;
}
if ( ! V_98 ) {
F_39 ( V_2 -> V_31 , L_14 ) ;
return - V_12 ;
}
V_2 -> V_84 = V_98 ;
V_2 -> V_37 = F_42 ( V_2 , V_98 , L_15 ) ;
if ( F_47 ( V_2 -> V_37 ) ) {
F_39 ( V_2 -> V_31 , L_16 ) ;
return F_55 ( V_2 -> V_37 ) ;
}
V_2 -> V_55 = F_42 ( V_2 , V_98 , L_17 ) ;
if ( F_47 ( V_2 -> V_55 ) ) {
F_39 ( V_2 -> V_31 , L_18 ) ;
return F_55 ( V_2 -> V_55 ) ;
}
V_2 -> V_58 = F_42 ( V_2 , V_98 , L_19 ) ;
if ( F_47 ( V_2 -> V_58 ) )
V_2 -> V_58 = V_2 -> V_55 ;
V_2 -> V_71 = F_42 ( V_2 , V_98 , L_20 ) ;
if ( F_47 ( V_2 -> V_71 ) ) {
F_39 ( V_2 -> V_31 , L_21 ) ;
return F_55 ( V_2 -> V_71 ) ;
}
return 0 ;
}
static int F_56 ( struct V_99 * V_100 )
{
const struct V_101 * V_102 ;
struct V_103 * V_31 = & V_100 -> V_31 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_57 ( V_31 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_31 = V_31 ;
V_102 = F_58 ( V_104 , V_100 -> V_31 . V_84 ) ;
V_2 -> V_7 = (struct V_105 * ) V_102 -> V_7 ;
V_43 = F_52 ( V_2 , V_100 -> V_31 . V_84 ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_18 . V_25 = L_22 ;
V_2 -> V_18 . V_106 = V_107 ;
V_2 -> V_18 . V_108 = & V_109 ;
V_2 -> V_18 . V_110 = & V_111 ;
V_2 -> V_18 . V_112 = & V_113 ;
V_2 -> V_18 . V_26 = V_2 -> V_7 -> V_26 ;
V_2 -> V_18 . V_114 = V_2 -> V_7 -> V_27 ;
V_2 -> V_21 = F_59 ( V_2 -> V_31 , & V_2 -> V_18 , V_2 ) ;
if ( F_47 ( V_2 -> V_21 ) ) {
F_39 ( V_2 -> V_31 , L_23 ) ;
return F_55 ( V_2 -> V_21 ) ;
}
return F_37 ( V_2 ) ;
}
