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
static int F_2 ( struct V_13 * V_14 , unsigned int V_3 ,
struct V_1 * * V_2 ,
struct V_4 * * V_5 )
{
struct V_1 * V_15 ;
V_15 = V_14 -> V_2 ;
if ( V_3 >= V_15 -> V_7 -> V_16 &&
V_3 < V_15 -> V_7 -> V_16 + V_15 -> V_7 -> V_17 ) {
* V_2 = V_15 ;
return F_1 ( V_15 , V_3 , V_5 ) ;
}
return - V_12 ;
}
static void F_3 ( struct V_4 * V_5 , unsigned int V_3 ,
enum V_18 V_19 ,
unsigned int * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = & V_5 -> V_24 [ V_19 ] ;
* V_20 = V_23 -> V_20 * 4 ;
* V_21 = V_23 -> V_21 + V_3 - V_5 -> V_10 ;
}
static int F_4 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
return V_14 -> V_7 -> V_27 ;
}
static const char * F_6 ( struct V_25 * V_26 ,
unsigned V_28 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
return V_14 -> V_7 -> V_29 [ V_28 ] . V_30 ;
}
static int F_7 ( struct V_25 * V_26 , unsigned V_28 ,
const unsigned * * V_31 , unsigned * V_17 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
* V_31 = V_14 -> V_7 -> V_29 [ V_28 ] . V_31 ;
* V_17 = V_14 -> V_7 -> V_29 [ V_28 ] . V_17 ;
return 0 ;
}
static void F_8 ( struct V_25 * V_26 , struct V_32 * V_33 ,
unsigned V_34 )
{
F_9 ( V_33 , L_1 , F_10 ( V_26 -> V_35 ) ) ;
}
static void F_11 ( struct V_13 * V_14 ,
unsigned int V_3 , int V_36 )
{
struct V_37 * V_38 ;
struct V_1 * V_2 ;
int V_6 , V_39 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_7 -> V_27 ; V_6 ++ ) {
V_38 = & V_14 -> V_7 -> V_29 [ V_6 ] ;
if ( V_38 -> V_40 || V_6 == V_36 )
continue;
for ( V_39 = 0 ; V_39 < V_38 -> V_17 ; V_39 ++ ) {
if ( V_38 -> V_31 [ V_39 ] == V_3 ) {
V_2 = V_14 -> V_2 ;
F_12 ( V_2 -> V_41 ,
V_38 -> V_20 * 4 ,
F_13 ( V_38 -> V_21 ) , 0 ) ;
}
}
}
}
static int F_14 ( struct V_25 * V_26 , unsigned V_42 ,
unsigned V_43 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
struct V_44 * V_45 = & V_14 -> V_7 -> V_46 [ V_42 ] ;
struct V_37 * V_38 = & V_14 -> V_7 -> V_29 [ V_43 ] ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_6 , V_47 = 0 ;
F_15 ( V_14 -> V_35 , L_2 , V_45 -> V_30 ,
V_38 -> V_30 ) ;
for ( V_6 = 0 ; V_6 < V_38 -> V_17 ; V_6 ++ )
F_11 ( V_14 , V_38 -> V_31 [ V_6 ] , V_43 ) ;
if ( V_42 )
V_47 = F_12 ( V_2 -> V_41 , V_38 -> V_20 * 4 ,
F_13 ( V_38 -> V_21 ) , F_13 ( V_38 -> V_21 ) ) ;
return V_47 ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_48 * V_49 ,
unsigned V_34 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
F_11 ( V_14 , V_49 -> V_16 + V_34 , - 1 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
return V_14 -> V_7 -> V_50 ;
}
static const char * F_18 ( struct V_25 * V_26 ,
unsigned V_28 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
return V_14 -> V_7 -> V_46 [ V_28 ] . V_30 ;
}
static int F_19 ( struct V_25 * V_26 , unsigned V_28 ,
const char * const * * V_29 ,
unsigned * const V_27 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
* V_29 = V_14 -> V_7 -> V_46 [ V_28 ] . V_29 ;
* V_27 = V_14 -> V_7 -> V_46 [ V_28 ] . V_27 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 , unsigned int V_3 ,
unsigned long * V_51 , unsigned V_52 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
enum V_53 V_54 ;
unsigned int V_20 , V_21 ;
int V_6 , V_47 ;
T_1 V_55 ;
V_47 = F_2 ( V_14 , V_3 , & V_2 , & V_5 ) ;
if ( V_47 )
return V_47 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ ) {
V_54 = F_21 ( V_51 [ V_6 ] ) ;
V_55 = F_22 ( V_51 [ V_6 ] ) ;
switch ( V_54 ) {
case V_56 :
F_15 ( V_14 -> V_35 , L_3 , V_3 ) ;
F_3 ( V_5 , V_3 , V_57 , & V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_58 , V_20 ,
F_13 ( V_21 ) , 0 ) ;
if ( V_47 )
return V_47 ;
break;
case V_59 :
F_15 ( V_14 -> V_35 , L_4 , V_3 ) ;
F_3 ( V_5 , V_3 , V_60 ,
& V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_61 , V_20 ,
F_13 ( V_21 ) , F_13 ( V_21 ) ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_57 , & V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_58 , V_20 ,
F_13 ( V_21 ) , F_13 ( V_21 ) ) ;
if ( V_47 )
return V_47 ;
break;
case V_62 :
F_15 ( V_14 -> V_35 , L_5 , V_3 ) ;
F_3 ( V_5 , V_3 , V_60 ,
& V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_61 , V_20 ,
F_13 ( V_21 ) , F_13 ( V_21 ) ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_57 , & V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_58 , V_20 ,
F_13 ( V_21 ) , 0 ) ;
if ( V_47 )
return V_47 ;
break;
default:
return - V_63 ;
}
}
return 0 ;
}
static int F_23 ( struct V_13 * V_14 , unsigned int V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned int V_20 , V_21 , V_64 ;
int V_47 , V_65 ;
V_47 = F_2 ( V_14 , V_3 , & V_2 , & V_5 ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_60 , & V_20 , & V_21 ) ;
V_47 = F_24 ( V_2 -> V_61 , V_20 , & V_64 ) ;
if ( V_47 )
return V_47 ;
if ( ! ( V_64 & F_13 ( V_21 ) ) ) {
V_65 = V_56 ;
} else {
F_3 ( V_5 , V_3 , V_57 , & V_20 , & V_21 ) ;
V_47 = F_24 ( V_2 -> V_58 , V_20 , & V_64 ) ;
if ( V_47 )
return V_47 ;
if ( V_64 & F_13 ( V_21 ) )
V_65 = V_59 ;
else
V_65 = V_62 ;
}
return V_65 ;
}
static int F_25 ( struct V_25 * V_26 , unsigned int V_3 ,
unsigned long * V_66 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
enum V_53 V_54 = F_21 ( * V_66 ) ;
T_1 V_55 ;
switch ( V_54 ) {
case V_56 :
case V_62 :
case V_59 :
if ( F_23 ( V_14 , V_3 ) == V_54 )
V_55 = 1 ;
else
return - V_12 ;
break;
default:
return - V_63 ;
}
* V_66 = F_26 ( V_54 , V_55 ) ;
F_15 ( V_14 -> V_35 , L_6 , V_3 , * V_66 ) ;
return 0 ;
}
static int F_27 ( struct V_25 * V_26 ,
unsigned int V_67 ,
unsigned long * V_51 , unsigned V_52 )
{
struct V_13 * V_14 = F_5 ( V_26 ) ;
struct V_37 * V_38 = & V_14 -> V_7 -> V_29 [ V_67 ] ;
int V_6 ;
F_15 ( V_14 -> V_35 , L_7 , V_38 -> V_30 ) ;
for ( V_6 = 0 ; V_6 < V_38 -> V_17 ; V_6 ++ ) {
F_20 ( V_26 , V_38 -> V_31 [ V_6 ] , V_51 ,
V_52 ) ;
}
return 0 ;
}
static int F_28 ( struct V_25 * V_26 ,
unsigned int V_38 , unsigned long * V_66 )
{
return - V_68 ;
}
static int F_29 ( struct V_69 * V_70 , unsigned V_71 )
{
return F_30 ( V_70 -> V_72 + V_71 ) ;
}
static void F_31 ( struct V_69 * V_70 , unsigned V_71 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
F_33 ( V_2 -> V_7 -> V_16 + V_71 ) ;
}
static int F_34 ( struct V_69 * V_70 , unsigned V_71 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
unsigned int V_20 , V_21 , V_3 ;
struct V_4 * V_5 ;
int V_47 ;
V_3 = V_2 -> V_7 -> V_16 + V_71 ;
V_47 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_73 , & V_20 , & V_21 ) ;
return F_12 ( V_2 -> V_74 , V_20 , F_13 ( V_21 ) , F_13 ( V_21 ) ) ;
}
static int F_35 ( struct V_69 * V_70 , unsigned V_71 ,
int V_75 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
unsigned int V_20 , V_21 , V_3 ;
struct V_4 * V_5 ;
int V_47 ;
V_3 = V_2 -> V_7 -> V_16 + V_71 ;
V_47 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_73 , & V_20 , & V_21 ) ;
V_47 = F_12 ( V_2 -> V_74 , V_20 , F_13 ( V_21 ) , 0 ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_76 , & V_20 , & V_21 ) ;
return F_12 ( V_2 -> V_74 , V_20 , F_13 ( V_21 ) ,
V_75 ? F_13 ( V_21 ) : 0 ) ;
}
static void F_36 ( struct V_69 * V_70 , unsigned V_71 , int V_75 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
unsigned int V_20 , V_21 , V_3 ;
struct V_4 * V_5 ;
int V_47 ;
V_3 = V_2 -> V_7 -> V_16 + V_71 ;
V_47 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_47 )
return;
F_3 ( V_5 , V_3 , V_76 , & V_20 , & V_21 ) ;
F_12 ( V_2 -> V_74 , V_20 , F_13 ( V_21 ) ,
V_75 ? F_13 ( V_21 ) : 0 ) ;
}
static int F_37 ( struct V_69 * V_70 , unsigned V_71 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
unsigned int V_20 , V_21 , V_64 , V_3 ;
struct V_4 * V_5 ;
int V_47 ;
V_3 = V_2 -> V_7 -> V_16 + V_71 ;
V_47 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_47 )
return V_47 ;
F_3 ( V_5 , V_3 , V_77 , & V_20 , & V_21 ) ;
F_24 ( V_2 -> V_74 , V_20 , & V_64 ) ;
return ! ! ( V_64 & F_13 ( V_21 ) ) ;
}
static int F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_47 ;
V_2 = V_14 -> V_2 ;
V_2 -> V_70 . V_78 = V_2 -> V_7 -> V_30 ;
V_2 -> V_70 . V_79 = V_14 -> V_35 ;
V_2 -> V_70 . V_80 = F_29 ;
V_2 -> V_70 . free = F_31 ;
V_2 -> V_70 . V_81 = F_34 ;
V_2 -> V_70 . V_82 = F_35 ;
V_2 -> V_70 . V_83 = F_37 ;
V_2 -> V_70 . V_84 = F_36 ;
V_2 -> V_70 . V_72 = V_2 -> V_7 -> V_16 ;
V_2 -> V_70 . V_85 = V_2 -> V_7 -> V_17 ;
V_2 -> V_70 . V_86 = false ;
V_2 -> V_70 . V_87 = V_2 -> V_87 ;
V_2 -> V_70 . V_88 = 2 ;
V_47 = F_39 ( & V_2 -> V_70 , V_2 ) ;
if ( V_47 ) {
F_40 ( V_14 -> V_35 , L_8 ,
V_2 -> V_7 -> V_30 ) ;
goto V_89;
}
V_47 = F_41 ( & V_2 -> V_70 , F_10 ( V_14 -> V_35 ) ,
0 , V_2 -> V_7 -> V_16 ,
V_2 -> V_70 . V_85 ) ;
if ( V_47 ) {
F_40 ( V_14 -> V_35 , L_9 ) ;
goto V_89;
}
return 0 ;
V_89:
F_42 ( & V_14 -> V_2 -> V_70 ) ;
return V_47 ;
}
static struct V_90 * F_43 ( struct V_13 * V_14 ,
struct V_91 * V_92 , char * V_30 )
{
struct V_93 V_94 ;
void T_2 * V_72 ;
int V_6 ;
V_6 = F_44 ( V_92 , L_10 , V_30 ) ;
if ( F_45 ( V_92 , V_6 , & V_94 ) )
return F_46 ( - V_95 ) ;
V_72 = F_47 ( V_14 -> V_35 , & V_94 ) ;
if ( F_48 ( V_72 ) )
return F_49 ( V_72 ) ;
V_96 . V_97 = F_50 ( & V_94 ) - 4 ;
V_96 . V_30 = F_51 ( V_14 -> V_35 , V_98 ,
L_11 , V_92 -> V_30 ,
V_30 ) ;
if ( ! V_96 . V_30 )
return F_46 ( - V_99 ) ;
return F_52 ( V_14 -> V_35 , V_72 , & V_96 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
struct V_91 * V_92 )
{
struct V_91 * V_100 ;
struct V_1 * V_2 ;
int V_101 = 0 ;
F_54 (node, np) {
if ( ! F_55 ( V_100 , L_12 , NULL ) )
continue;
V_101 ++ ;
}
if ( V_101 != 1 ) {
F_40 ( V_14 -> V_35 , L_13 ) ;
return - V_12 ;
}
V_14 -> V_2 = F_56 ( V_14 -> V_35 , sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_14 -> V_2 )
return - V_99 ;
V_2 = V_14 -> V_2 ;
V_2 -> V_7 = V_14 -> V_7 -> V_102 ;
F_54 (node, np) {
if ( ! F_55 ( V_100 , L_12 , NULL ) )
continue;
V_2 -> V_87 = V_100 ;
V_2 -> V_41 = F_43 ( V_14 , V_100 , L_14 ) ;
if ( F_48 ( V_2 -> V_41 ) ) {
F_40 ( V_14 -> V_35 , L_15 ) ;
return F_57 ( V_2 -> V_41 ) ;
}
V_2 -> V_58 = F_43 ( V_14 , V_100 , L_16 ) ;
if ( F_48 ( V_2 -> V_58 ) ) {
F_40 ( V_14 -> V_35 , L_17 ) ;
return F_57 ( V_2 -> V_58 ) ;
}
V_2 -> V_61 = F_43 ( V_14 , V_100 , L_18 ) ;
if ( F_48 ( V_2 -> V_61 ) )
V_2 -> V_61 = V_2 -> V_58 ;
V_2 -> V_74 = F_43 ( V_14 , V_100 , L_19 ) ;
if ( F_48 ( V_2 -> V_74 ) ) {
F_40 ( V_14 -> V_35 , L_20 ) ;
return F_57 ( V_2 -> V_74 ) ;
}
break;
}
return 0 ;
}
static int F_58 ( struct V_103 * V_104 )
{
const struct V_105 * V_106 ;
struct V_107 * V_35 = & V_104 -> V_35 ;
struct V_13 * V_14 ;
int V_47 ;
V_14 = F_56 ( V_35 , sizeof( struct V_13 ) , V_98 ) ;
if ( ! V_14 )
return - V_99 ;
V_14 -> V_35 = V_35 ;
V_106 = F_59 ( V_108 , V_104 -> V_35 . V_87 ) ;
V_14 -> V_7 = (struct V_109 * ) V_106 -> V_7 ;
V_47 = F_53 ( V_14 , V_104 -> V_35 . V_87 ) ;
if ( V_47 )
return V_47 ;
V_14 -> V_23 . V_30 = L_21 ;
V_14 -> V_23 . V_110 = V_111 ;
V_14 -> V_23 . V_112 = & V_113 ;
V_14 -> V_23 . V_114 = & V_115 ;
V_14 -> V_23 . V_116 = & V_117 ;
V_14 -> V_23 . V_31 = V_14 -> V_7 -> V_31 ;
V_14 -> V_23 . V_118 = V_14 -> V_7 -> V_17 ;
V_14 -> V_26 = F_60 ( V_14 -> V_35 , & V_14 -> V_23 , V_14 ) ;
if ( F_48 ( V_14 -> V_26 ) ) {
F_40 ( V_14 -> V_35 , L_22 ) ;
return F_57 ( V_14 -> V_26 ) ;
}
return F_38 ( V_14 ) ;
}
