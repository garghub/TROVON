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
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_7 -> V_16 ; V_6 ++ ) {
V_15 = & V_14 -> V_17 [ V_6 ] ;
if ( V_3 >= V_15 -> V_7 -> V_18 &&
V_3 < V_15 -> V_7 -> V_18 + V_15 -> V_7 -> V_19 ) {
* V_2 = V_15 ;
return F_1 ( V_15 , V_3 , V_5 ) ;
}
}
return - V_12 ;
}
static void F_3 ( struct V_4 * V_5 , unsigned int V_3 ,
enum V_20 V_21 ,
unsigned int * V_22 , unsigned int * V_23 )
{
struct V_24 * V_25 = & V_5 -> V_26 [ V_21 ] ;
* V_22 = V_25 -> V_22 * 4 ;
* V_23 = V_25 -> V_23 + V_3 - V_5 -> V_10 ;
}
static int F_4 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
return V_14 -> V_7 -> V_29 ;
}
static const char * F_6 ( struct V_27 * V_28 ,
unsigned V_30 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
return V_14 -> V_7 -> V_31 [ V_30 ] . V_32 ;
}
static int F_7 ( struct V_27 * V_28 , unsigned V_30 ,
const unsigned * * V_33 , unsigned * V_19 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
* V_33 = V_14 -> V_7 -> V_31 [ V_30 ] . V_33 ;
* V_19 = V_14 -> V_7 -> V_31 [ V_30 ] . V_19 ;
return 0 ;
}
static void F_8 ( struct V_27 * V_28 , struct V_34 * V_35 ,
unsigned V_36 )
{
F_9 ( V_35 , L_1 , F_10 ( V_28 -> V_37 ) ) ;
}
static void F_11 ( struct V_13 * V_14 ,
unsigned int V_3 , int V_38 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
int V_6 , V_41 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_7 -> V_29 ; V_6 ++ ) {
V_40 = & V_14 -> V_7 -> V_31 [ V_6 ] ;
if ( V_40 -> V_42 || V_6 == V_38 )
continue;
for ( V_41 = 0 ; V_41 < V_40 -> V_19 ; V_41 ++ ) {
if ( V_40 -> V_33 [ V_41 ] == V_3 ) {
V_2 = & V_14 -> V_17 [ V_40 -> V_2 ] ;
F_12 ( V_2 -> V_43 ,
V_40 -> V_22 * 4 ,
F_13 ( V_40 -> V_23 ) , 0 ) ;
}
}
}
}
static int F_14 ( struct V_27 * V_28 , unsigned V_44 ,
unsigned V_45 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
struct V_46 * V_47 = & V_14 -> V_7 -> V_48 [ V_44 ] ;
struct V_39 * V_40 = & V_14 -> V_7 -> V_31 [ V_45 ] ;
struct V_1 * V_2 = & V_14 -> V_17 [ V_40 -> V_2 ] ;
int V_6 , V_49 = 0 ;
F_15 ( V_14 -> V_37 , L_2 , V_47 -> V_32 ,
V_40 -> V_32 ) ;
for ( V_6 = 0 ; V_6 < V_40 -> V_19 ; V_6 ++ )
F_11 ( V_14 , V_40 -> V_33 [ V_6 ] , V_45 ) ;
if ( V_44 )
V_49 = F_12 ( V_2 -> V_43 , V_40 -> V_22 * 4 ,
F_13 ( V_40 -> V_23 ) , F_13 ( V_40 -> V_23 ) ) ;
return V_49 ;
}
static int F_16 ( struct V_27 * V_28 ,
struct V_50 * V_51 ,
unsigned V_36 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
F_11 ( V_14 , V_51 -> V_18 + V_36 , - 1 ) ;
return 0 ;
}
static int F_17 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
return V_14 -> V_7 -> V_52 ;
}
static const char * F_18 ( struct V_27 * V_28 ,
unsigned V_30 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
return V_14 -> V_7 -> V_48 [ V_30 ] . V_32 ;
}
static int F_19 ( struct V_27 * V_28 , unsigned V_30 ,
const char * const * * V_31 ,
unsigned * const V_29 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
* V_31 = V_14 -> V_7 -> V_48 [ V_30 ] . V_31 ;
* V_29 = V_14 -> V_7 -> V_48 [ V_30 ] . V_29 ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 , unsigned int V_3 ,
unsigned long * V_53 , unsigned V_54 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
enum V_55 V_56 ;
unsigned int V_22 , V_23 ;
int V_6 , V_49 ;
T_1 V_57 ;
V_49 = F_2 ( V_14 , V_3 , & V_2 , & V_5 ) ;
if ( V_49 )
return V_49 ;
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ ) {
V_56 = F_21 ( V_53 [ V_6 ] ) ;
V_57 = F_22 ( V_53 [ V_6 ] ) ;
switch ( V_56 ) {
case V_58 :
F_15 ( V_14 -> V_37 , L_3 , V_3 ) ;
F_3 ( V_5 , V_3 , V_59 , & V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_60 , V_22 ,
F_13 ( V_23 ) , 0 ) ;
if ( V_49 )
return V_49 ;
break;
case V_61 :
F_15 ( V_14 -> V_37 , L_4 , V_3 ) ;
F_3 ( V_5 , V_3 , V_62 ,
& V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_63 , V_22 ,
F_13 ( V_23 ) , F_13 ( V_23 ) ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_59 , & V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_60 , V_22 ,
F_13 ( V_23 ) , F_13 ( V_23 ) ) ;
if ( V_49 )
return V_49 ;
break;
case V_64 :
F_15 ( V_14 -> V_37 , L_5 , V_3 ) ;
F_3 ( V_5 , V_3 , V_62 ,
& V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_63 , V_22 ,
F_13 ( V_23 ) , F_13 ( V_23 ) ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_59 , & V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_60 , V_22 ,
F_13 ( V_23 ) , 0 ) ;
if ( V_49 )
return V_49 ;
break;
default:
return - V_65 ;
}
}
return 0 ;
}
static int F_23 ( struct V_13 * V_14 , unsigned int V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned int V_22 , V_23 , V_66 ;
int V_49 , V_67 ;
V_49 = F_2 ( V_14 , V_3 , & V_2 , & V_5 ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_62 , & V_22 , & V_23 ) ;
V_49 = F_24 ( V_2 -> V_63 , V_22 , & V_66 ) ;
if ( V_49 )
return V_49 ;
if ( ! ( V_66 & F_13 ( V_23 ) ) ) {
V_67 = V_58 ;
} else {
F_3 ( V_5 , V_3 , V_59 , & V_22 , & V_23 ) ;
V_49 = F_24 ( V_2 -> V_60 , V_22 , & V_66 ) ;
if ( V_49 )
return V_49 ;
if ( V_66 & F_13 ( V_23 ) )
V_67 = V_61 ;
else
V_67 = V_64 ;
}
return V_67 ;
}
static int F_25 ( struct V_27 * V_28 , unsigned int V_3 ,
unsigned long * V_68 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
enum V_55 V_56 = F_21 ( * V_68 ) ;
T_1 V_57 ;
switch ( V_56 ) {
case V_58 :
case V_64 :
case V_61 :
if ( F_23 ( V_14 , V_3 ) == V_56 )
V_57 = 1 ;
else
return - V_12 ;
break;
default:
return - V_65 ;
}
* V_68 = F_26 ( V_56 , V_57 ) ;
F_15 ( V_14 -> V_37 , L_6 , V_3 , * V_68 ) ;
return 0 ;
}
static int F_27 ( struct V_27 * V_28 ,
unsigned int V_69 ,
unsigned long * V_53 , unsigned V_54 )
{
struct V_13 * V_14 = F_5 ( V_28 ) ;
struct V_39 * V_40 = & V_14 -> V_7 -> V_31 [ V_69 ] ;
int V_6 ;
F_15 ( V_14 -> V_37 , L_7 , V_40 -> V_32 ) ;
for ( V_6 = 0 ; V_6 < V_40 -> V_19 ; V_6 ++ ) {
F_20 ( V_28 , V_40 -> V_33 [ V_6 ] , V_53 ,
V_54 ) ;
}
return 0 ;
}
static int F_28 ( struct V_27 * V_28 ,
unsigned int V_40 , unsigned long * V_68 )
{
return - V_70 ;
}
static inline struct V_1 * F_29 ( struct V_71 * V_72 )
{
return F_30 ( V_72 , struct V_1 , V_72 ) ;
}
static int F_31 ( struct V_71 * V_72 , unsigned V_73 )
{
return F_32 ( V_72 -> V_74 + V_73 ) ;
}
static void F_33 ( struct V_71 * V_72 , unsigned V_73 )
{
struct V_1 * V_2 = F_29 ( V_72 ) ;
F_34 ( V_2 -> V_7 -> V_18 + V_73 ) ;
}
static int F_35 ( struct V_71 * V_72 , unsigned V_73 )
{
struct V_1 * V_2 = F_29 ( V_72 ) ;
unsigned int V_22 , V_23 , V_3 ;
struct V_4 * V_5 ;
int V_49 ;
V_3 = V_2 -> V_7 -> V_18 + V_73 ;
V_49 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_75 , & V_22 , & V_23 ) ;
return F_12 ( V_2 -> V_76 , V_22 , F_13 ( V_23 ) , F_13 ( V_23 ) ) ;
}
static int F_36 ( struct V_71 * V_72 , unsigned V_73 ,
int V_77 )
{
struct V_1 * V_2 = F_29 ( V_72 ) ;
unsigned int V_22 , V_23 , V_3 ;
struct V_4 * V_5 ;
int V_49 ;
V_3 = V_2 -> V_7 -> V_18 + V_73 ;
V_49 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_75 , & V_22 , & V_23 ) ;
V_49 = F_12 ( V_2 -> V_76 , V_22 , F_13 ( V_23 ) , 0 ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_78 , & V_22 , & V_23 ) ;
return F_12 ( V_2 -> V_76 , V_22 , F_13 ( V_23 ) ,
V_77 ? F_13 ( V_23 ) : 0 ) ;
}
static void F_37 ( struct V_71 * V_72 , unsigned V_73 , int V_77 )
{
struct V_1 * V_2 = F_29 ( V_72 ) ;
unsigned int V_22 , V_23 , V_3 ;
struct V_4 * V_5 ;
int V_49 ;
V_3 = V_2 -> V_7 -> V_18 + V_73 ;
V_49 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_49 )
return;
F_3 ( V_5 , V_3 , V_78 , & V_22 , & V_23 ) ;
F_12 ( V_2 -> V_76 , V_22 , F_13 ( V_23 ) ,
V_77 ? F_13 ( V_23 ) : 0 ) ;
}
static int F_38 ( struct V_71 * V_72 , unsigned V_73 )
{
struct V_1 * V_2 = F_29 ( V_72 ) ;
unsigned int V_22 , V_23 , V_66 , V_3 ;
struct V_4 * V_5 ;
int V_49 ;
V_3 = V_2 -> V_7 -> V_18 + V_73 ;
V_49 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_49 )
return V_49 ;
F_3 ( V_5 , V_3 , V_79 , & V_22 , & V_23 ) ;
F_24 ( V_2 -> V_76 , V_22 , & V_66 ) ;
return ! ! ( V_66 & F_13 ( V_23 ) ) ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_6 , V_49 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_7 -> V_16 ; V_6 ++ ) {
V_2 = & V_14 -> V_17 [ V_6 ] ;
V_2 -> V_72 . V_80 = V_2 -> V_7 -> V_32 ;
V_2 -> V_72 . V_37 = V_14 -> V_37 ;
V_2 -> V_72 . V_81 = F_31 ;
V_2 -> V_72 . free = F_33 ;
V_2 -> V_72 . V_82 = F_35 ;
V_2 -> V_72 . V_83 = F_36 ;
V_2 -> V_72 . V_84 = F_38 ;
V_2 -> V_72 . V_85 = F_37 ;
V_2 -> V_72 . V_74 = V_2 -> V_7 -> V_18 ;
V_2 -> V_72 . V_86 = V_2 -> V_7 -> V_19 ;
V_2 -> V_72 . V_87 = false ;
V_2 -> V_72 . V_88 = V_2 -> V_88 ;
V_2 -> V_72 . V_89 = 2 ;
V_49 = F_40 ( & V_2 -> V_72 ) ;
if ( V_49 ) {
F_41 ( V_14 -> V_37 , L_8 ,
V_2 -> V_7 -> V_32 ) ;
goto V_90;
}
V_49 = F_42 ( & V_2 -> V_72 , F_10 ( V_14 -> V_37 ) ,
0 , V_2 -> V_7 -> V_18 ,
V_2 -> V_72 . V_86 ) ;
if ( V_49 ) {
F_41 ( V_14 -> V_37 , L_9 ) ;
goto V_90;
}
}
return 0 ;
V_90:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- )
F_43 ( & V_14 -> V_17 [ V_6 ] . V_72 ) ;
return V_49 ;
}
static struct V_91 * F_44 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_7 -> V_16 ; V_6 ++ ) {
if ( ! strcmp ( V_93 -> V_32 , V_14 -> V_7 -> V_94 [ V_6 ] . V_32 ) )
return & V_14 -> V_7 -> V_94 [ V_6 ] ;
}
return NULL ;
}
static struct V_95 * F_45 ( struct V_13 * V_14 ,
struct V_92 * V_96 , char * V_32 )
{
struct V_97 V_98 ;
void T_2 * V_74 ;
int V_6 ;
V_6 = F_46 ( V_96 , L_10 , V_32 ) ;
if ( F_47 ( V_96 , V_6 , & V_98 ) )
return F_48 ( - V_99 ) ;
V_74 = F_49 ( V_14 -> V_37 , & V_98 ) ;
if ( F_50 ( V_74 ) )
return F_51 ( V_74 ) ;
V_100 . V_101 = F_52 ( & V_98 ) - 4 ;
V_100 . V_32 = F_53 ( V_14 -> V_37 , V_102 ,
L_11 , V_96 -> V_32 ,
V_32 ) ;
if ( ! V_100 . V_32 )
return F_48 ( - V_103 ) ;
return F_54 ( V_14 -> V_37 , V_74 , & V_100 ) ;
}
static int F_55 ( struct V_13 * V_14 ,
struct V_92 * V_96 )
{
struct V_92 * V_93 ;
struct V_1 * V_2 ;
int V_6 = 0 , V_16 = 0 ;
F_56 (node, np) {
if ( ! F_57 ( V_93 , L_12 , NULL ) )
continue;
V_16 ++ ;
}
if ( V_16 != V_14 -> V_7 -> V_16 ) {
F_41 ( V_14 -> V_37 , L_13 ) ;
return - V_12 ;
}
V_14 -> V_17 = F_58 ( V_14 -> V_37 , V_16 *
sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_14 -> V_17 )
return - V_103 ;
F_56 (node, np) {
if ( ! F_57 ( V_93 , L_12 , NULL ) )
continue;
V_2 = & V_14 -> V_17 [ V_6 ] ;
V_2 -> V_7 = F_44 ( V_14 , V_93 ) ;
if ( ! V_2 -> V_7 ) {
F_41 ( V_14 -> V_37 , L_14 ,
V_93 -> V_32 ) ;
return - V_104 ;
}
V_2 -> V_88 = V_93 ;
V_2 -> V_43 = F_45 ( V_14 , V_93 , L_15 ) ;
if ( F_50 ( V_2 -> V_43 ) ) {
F_41 ( V_14 -> V_37 , L_16 ) ;
return F_59 ( V_2 -> V_43 ) ;
}
V_2 -> V_60 = F_45 ( V_14 , V_93 , L_17 ) ;
if ( F_50 ( V_2 -> V_60 ) ) {
F_41 ( V_14 -> V_37 , L_18 ) ;
return F_59 ( V_2 -> V_60 ) ;
}
V_2 -> V_63 = F_45 ( V_14 , V_93 , L_19 ) ;
if ( F_50 ( V_2 -> V_63 ) )
V_2 -> V_63 = V_2 -> V_60 ;
V_2 -> V_76 = F_45 ( V_14 , V_93 , L_20 ) ;
if ( F_50 ( V_2 -> V_76 ) ) {
F_41 ( V_14 -> V_37 , L_21 ) ;
return F_59 ( V_2 -> V_76 ) ;
}
V_6 ++ ;
}
return 0 ;
}
static int F_60 ( struct V_105 * V_106 )
{
const struct V_107 * V_108 ;
struct V_109 * V_37 = & V_106 -> V_37 ;
struct V_13 * V_14 ;
int V_49 ;
V_14 = F_58 ( V_37 , sizeof( struct V_13 ) , V_102 ) ;
if ( ! V_14 )
return - V_103 ;
V_14 -> V_37 = V_37 ;
V_108 = F_61 ( V_110 , V_106 -> V_37 . V_88 ) ;
V_14 -> V_7 = (struct V_111 * ) V_108 -> V_7 ;
V_49 = F_55 ( V_14 , V_106 -> V_37 . V_88 ) ;
if ( V_49 )
return V_49 ;
V_14 -> V_25 . V_32 = L_22 ;
V_14 -> V_25 . V_112 = V_113 ;
V_14 -> V_25 . V_114 = & V_115 ;
V_14 -> V_25 . V_116 = & V_117 ;
V_14 -> V_25 . V_118 = & V_119 ;
V_14 -> V_25 . V_33 = V_14 -> V_7 -> V_33 ;
V_14 -> V_25 . V_120 = V_14 -> V_7 -> V_19 ;
V_14 -> V_28 = F_62 ( & V_14 -> V_25 , V_14 -> V_37 , V_14 ) ;
if ( F_50 ( V_14 -> V_28 ) ) {
F_41 ( V_14 -> V_37 , L_23 ) ;
return F_59 ( V_14 -> V_28 ) ;
}
V_49 = F_39 ( V_14 ) ;
if ( V_49 ) {
F_63 ( V_14 -> V_28 ) ;
return V_49 ;
}
return 0 ;
}
