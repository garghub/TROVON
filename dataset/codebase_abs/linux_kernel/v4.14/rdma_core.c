int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
int V_3 = ( * V_1 & V_4 ) >> V_5 ;
if ( V_3 >= V_2 )
return - V_6 ;
* V_1 &= ~ V_4 ;
return V_3 ;
}
const struct V_7 * F_2 ( const struct V_8 * V_9 ,
T_2 V_10 )
{
const struct V_11 * V_12 = V_9 -> V_13 ;
const struct V_14 * V_15 ;
int V_3 = F_1 ( & V_10 , V_12 -> V_16 ) ;
if ( V_3 < 0 )
return NULL ;
V_15 = V_12 -> V_17 [ V_3 ] ;
if ( V_10 >= V_15 -> V_18 )
return NULL ;
return V_15 -> V_15 [ V_10 ] ;
}
const struct V_19 * F_3 ( const struct V_7 * V_10 ,
T_2 V_20 )
{
const struct V_21 * V_22 ;
int V_3 = F_1 ( & V_20 , V_10 -> V_16 ) ;
if ( V_3 < 0 )
return NULL ;
V_22 = V_10 -> V_23 [ V_3 ] ;
if ( V_20 >= V_22 -> V_24 )
return NULL ;
return V_22 -> V_22 [ V_20 ] ;
}
void F_4 ( struct V_25 * V_26 )
{
F_5 ( & V_26 -> V_27 ) ;
}
static void F_6 ( struct V_28 * V_27 )
{
struct V_25 * V_29 =
F_7 ( V_27 , struct V_25 , V_27 ) ;
if ( V_29 -> type -> V_30 -> V_31 )
F_8 ( V_29 , V_32 ) ;
else
F_9 ( V_29 ) ;
}
void F_10 ( struct V_25 * V_26 )
{
F_11 ( & V_26 -> V_27 , F_6 ) ;
}
static int F_12 ( struct V_25 * V_29 , bool V_33 )
{
if ( ! V_33 )
return F_13 ( & V_29 -> V_34 , 1 , - 1 ) == - 1 ?
- V_35 : 0 ;
return F_14 ( & V_29 -> V_34 , 0 , - 1 ) == 0 ? 0 : - V_35 ;
}
static struct V_25 * F_15 ( struct V_36 * V_37 ,
const struct V_38 * type )
{
struct V_25 * V_29 = F_16 ( type -> V_39 , V_40 ) ;
if ( ! V_29 )
return F_17 ( - V_41 ) ;
V_29 -> V_37 = V_37 ;
V_29 -> type = type ;
F_18 ( & V_29 -> V_34 , 0 ) ;
F_19 ( & V_29 -> V_27 ) ;
return V_29 ;
}
static int F_20 ( struct V_25 * V_29 )
{
int V_3 ;
F_21 ( V_40 ) ;
F_22 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
V_3 = F_23 ( & V_29 -> V_37 -> V_42 -> V_44 , NULL , 0 ,
F_24 (unsigned long, U32_MAX - 1 , INT_MAX) , V_45 ) ;
if ( V_3 >= 0 )
V_29 -> V_1 = V_3 ;
F_25 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
F_26 () ;
return V_3 < 0 ? V_3 : 0 ;
}
static void F_27 ( struct V_25 * V_29 )
{
F_22 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
F_28 ( & V_29 -> V_37 -> V_42 -> V_44 , V_29 -> V_1 ) ;
F_25 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
}
static struct V_25 * F_29 ( const struct V_38 * type ,
struct V_36 * V_46 ,
int V_1 , bool V_33 )
{
struct V_25 * V_29 ;
F_30 () ;
V_29 = F_31 ( & V_46 -> V_42 -> V_44 , V_1 ) ;
if ( ! V_29 ) {
V_29 = F_17 ( - V_47 ) ;
goto free;
}
F_4 ( V_29 ) ;
free:
F_32 () ;
return V_29 ;
}
static struct V_25 * F_33 ( const struct V_38 * type ,
struct V_36 * V_46 ,
int V_1 , bool V_33 )
{
struct V_48 * V_49 ;
struct V_25 * V_26 ;
const struct V_50 * V_51 =
F_7 ( type , struct V_50 , type ) ;
if ( V_33 )
return F_17 ( - V_52 ) ;
V_49 = F_34 ( V_1 ) ;
if ( ! V_49 )
return F_17 ( - V_53 ) ;
V_26 = V_49 -> V_54 ;
if ( V_49 -> V_55 != V_51 -> V_56 ) {
F_35 ( V_49 ) ;
return F_17 ( - V_53 ) ;
}
F_4 ( V_26 ) ;
return V_26 ;
}
struct V_25 * F_36 ( const struct V_38 * type ,
struct V_36 * V_46 ,
int V_1 , bool V_33 )
{
struct V_25 * V_29 ;
int V_3 ;
V_29 = type -> V_30 -> V_57 ( type , V_46 , V_1 , V_33 ) ;
if ( F_37 ( V_29 ) )
return V_29 ;
if ( V_29 -> type != type ) {
V_3 = - V_6 ;
goto free;
}
V_3 = F_12 ( V_29 , V_33 ) ;
if ( V_3 ) {
F_38 ( V_46 -> V_58 ,
L_1 ) ;
goto free;
}
return V_29 ;
free:
V_29 -> type -> V_30 -> V_59 ( V_29 , V_33 ) ;
F_10 ( V_29 ) ;
return F_17 ( V_3 ) ;
}
static struct V_25 * F_39 ( const struct V_38 * type ,
struct V_36 * V_46 )
{
int V_3 ;
struct V_25 * V_29 ;
V_29 = F_15 ( V_46 , type ) ;
if ( F_37 ( V_29 ) )
return V_29 ;
V_3 = F_20 ( V_29 ) ;
if ( V_3 )
goto V_60;
V_3 = F_40 ( & V_29 -> V_61 , V_46 -> V_62 ,
V_63 ) ;
if ( V_3 )
goto F_28;
return V_29 ;
F_28:
F_27 ( V_29 ) ;
V_60:
F_10 ( V_29 ) ;
return F_17 ( V_3 ) ;
}
static struct V_25 * F_41 ( const struct V_38 * type ,
struct V_36 * V_46 )
{
const struct V_50 * V_51 =
F_7 ( type , struct V_50 , type ) ;
int V_64 ;
struct V_25 * V_29 ;
struct V_65 * V_66 ;
struct V_48 * V_67 ;
V_64 = F_42 ( V_68 ) ;
if ( V_64 < 0 )
return F_17 ( V_64 ) ;
V_29 = F_15 ( V_46 , type ) ;
if ( F_37 ( V_29 ) ) {
F_43 ( V_64 ) ;
return V_29 ;
}
V_66 = F_7 ( V_29 , struct V_65 , V_29 ) ;
V_67 = F_44 ( V_51 -> V_69 ,
V_51 -> V_56 ,
V_66 ,
V_51 -> V_70 ) ;
if ( F_37 ( V_67 ) ) {
F_43 ( V_64 ) ;
F_10 ( V_29 ) ;
return ( void * ) V_67 ;
}
V_66 -> V_29 . V_1 = V_64 ;
V_66 -> V_29 . V_10 = V_67 ;
V_66 -> V_42 = V_46 -> V_42 ;
F_45 ( & V_29 -> V_71 ) ;
F_5 ( & V_66 -> V_42 -> V_27 ) ;
return V_29 ;
}
struct V_25 * F_46 ( const struct V_38 * type ,
struct V_36 * V_46 )
{
return type -> V_30 -> V_72 ( type , V_46 ) ;
}
static void F_47 ( struct V_25 * V_26 )
{
F_48 ( & V_26 -> V_37 -> V_73 ) ;
F_49 ( & V_26 -> V_71 , & V_26 -> V_37 -> V_74 ) ;
F_50 ( & V_26 -> V_37 -> V_73 ) ;
}
static int T_3 F_51 ( struct V_25 * V_29 ,
enum V_75 V_76 )
{
const struct V_77 * V_78 =
F_7 ( V_29 -> type , struct V_77 ,
type ) ;
int V_3 = V_78 -> V_79 ( V_29 , V_76 ) ;
if ( V_76 == V_80 && V_3 )
return V_3 ;
F_52 ( & V_29 -> V_61 , V_29 -> V_37 -> V_62 ,
V_63 ) ;
F_27 ( V_29 ) ;
return V_3 ;
}
static void F_53 ( struct V_25 * V_29 )
{
struct V_65 * V_66 =
F_7 ( V_29 , struct V_65 , V_29 ) ;
struct V_48 * V_67 = V_29 -> V_10 ;
int V_1 = V_66 -> V_29 . V_1 ;
F_35 ( V_67 ) ;
F_43 ( V_1 ) ;
}
static int T_3 F_54 ( struct V_25 * V_29 ,
enum V_75 V_76 )
{
const struct V_50 * V_51 =
F_7 ( V_29 -> type , struct V_50 , type ) ;
struct V_65 * V_66 =
F_7 ( V_29 , struct V_65 , V_29 ) ;
int V_3 = V_51 -> V_81 ( V_66 , V_76 ) ;
if ( V_76 == V_80 && V_3 )
return V_3 ;
if ( V_76 == V_82 ) {
F_53 ( V_29 ) ;
return V_3 ;
}
V_66 -> V_29 . V_37 = NULL ;
return V_3 ;
}
static void F_55 ( struct V_25 * V_29 , bool V_33 )
{
#ifdef F_56
if ( V_33 )
F_57 ( F_58 ( & V_29 -> V_34 ) > 0 ) ;
else
F_57 ( F_58 ( & V_29 -> V_34 ) == - 1 ) ;
#endif
}
static int T_3 F_59 ( struct V_25 * V_29 ,
enum V_75 V_76 )
{
int V_3 ;
struct V_36 * V_46 = V_29 -> V_37 ;
V_3 = V_29 -> type -> V_30 -> V_83 ( V_29 , V_76 ) ;
if ( V_3 && V_76 == V_80 ) {
F_18 ( & V_29 -> V_34 , 0 ) ;
V_29 -> type -> V_30 -> V_59 ( V_29 , true ) ;
} else {
F_48 ( & V_46 -> V_73 ) ;
F_60 ( & V_29 -> V_71 ) ;
F_50 ( & V_46 -> V_73 ) ;
F_10 ( V_29 ) ;
}
return V_3 ;
}
int T_3 F_61 ( struct V_25 * V_29 )
{
int V_3 ;
struct V_36 * V_46 = V_29 -> V_37 ;
F_10 ( V_29 ) ;
if ( ! F_62 ( & V_46 -> V_84 ) ) {
F_38 ( true , L_2 ) ;
return 0 ;
}
F_55 ( V_29 , true ) ;
V_3 = F_59 ( V_29 , V_80 ) ;
F_63 ( & V_46 -> V_84 ) ;
return V_3 ;
}
static int F_64 ( struct V_25 * V_29 ,
enum V_75 V_76 )
{
return 0 ;
}
int F_65 ( struct V_25 * V_26 )
{
int V_3 ;
struct V_36 * V_46 = V_26 -> V_37 ;
if ( ! F_62 ( & V_46 -> V_84 ) ) {
F_38 ( true , L_2 ) ;
return 0 ;
}
F_55 ( V_26 , true ) ;
V_3 = V_26 -> type -> V_30 -> V_83 ( V_26 ,
V_80 ) ;
if ( V_3 )
return V_3 ;
V_26 -> type = & V_85 ;
F_63 ( & V_46 -> V_84 ) ;
return 0 ;
}
static void F_66 ( struct V_25 * V_29 )
{
F_47 ( V_29 ) ;
F_22 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
F_57 ( F_67 ( & V_29 -> V_37 -> V_42 -> V_44 ,
V_29 , V_29 -> V_1 ) ) ;
F_25 ( & V_29 -> V_37 -> V_42 -> V_43 ) ;
}
static void F_68 ( struct V_25 * V_29 )
{
struct V_65 * V_66 =
F_7 ( V_29 , struct V_65 , V_29 ) ;
F_47 ( & V_66 -> V_29 ) ;
F_69 ( V_66 -> V_29 . V_1 , V_29 -> V_10 ) ;
V_66 -> V_29 . V_1 = 0 ;
F_4 ( & V_66 -> V_29 ) ;
}
int F_70 ( struct V_25 * V_29 )
{
if ( ! F_62 ( & V_29 -> V_37 -> V_84 ) ) {
int V_3 ;
F_38 ( true , L_3 ) ;
V_3 = V_29 -> type -> V_30 -> V_83 ( V_29 ,
V_82 ) ;
if ( V_3 )
F_71 ( L_4 ,
V_29 -> V_1 ) ;
return V_3 ;
}
V_29 -> type -> V_30 -> V_86 ( V_29 ) ;
F_63 ( & V_29 -> V_37 -> V_84 ) ;
return 0 ;
}
static void F_72 ( struct V_25 * V_29 )
{
F_27 ( V_29 ) ;
F_52 ( & V_29 -> V_61 , V_29 -> V_37 -> V_62 ,
V_63 ) ;
F_10 ( V_29 ) ;
}
void F_73 ( struct V_25 * V_29 )
{
V_29 -> type -> V_30 -> V_87 ( V_29 ) ;
}
static void F_74 ( struct V_25 * V_29 , bool V_33 )
{
}
static void F_75 ( struct V_25 * V_29 , bool V_33 )
{
struct V_48 * V_67 = V_29 -> V_10 ;
F_57 ( V_33 ) ;
F_35 ( V_67 ) ;
}
void F_76 ( struct V_25 * V_29 , bool V_33 )
{
F_55 ( V_29 , V_33 ) ;
V_29 -> type -> V_30 -> V_59 ( V_29 , V_33 ) ;
if ( ! V_33 )
F_77 ( & V_29 -> V_34 ) ;
else
F_18 ( & V_29 -> V_34 , 0 ) ;
F_10 ( V_29 ) ;
}
static void F_78 ( struct V_65 * V_66 )
{
struct V_36 * V_46 ;
struct V_88 * V_42 = V_66 -> V_42 ;
int V_3 ;
F_48 ( & V_66 -> V_42 -> V_89 ) ;
if ( ! V_66 -> V_29 . V_37 ||
! F_62 ( & V_66 -> V_29 . V_37 -> V_84 ) )
goto V_90;
V_46 = V_66 -> V_29 . V_37 ;
V_3 = F_59 ( & V_66 -> V_29 , V_91 ) ;
F_63 ( & V_46 -> V_84 ) ;
if ( V_3 )
F_71 ( L_5 ) ;
V_90:
F_50 ( & V_42 -> V_89 ) ;
}
void F_79 ( struct V_48 * V_49 )
{
struct V_65 * V_66 = V_49 -> V_54 ;
struct V_28 * V_92 = & V_66 -> V_42 -> V_27 ;
F_78 ( V_66 ) ;
F_10 ( & V_66 -> V_29 ) ;
F_11 ( V_92 , V_93 ) ;
}
void F_80 ( struct V_36 * V_46 , bool V_94 )
{
enum V_75 V_95 = V_94 ?
V_96 : V_91 ;
unsigned int V_97 = 0 ;
V_46 -> V_58 = V_95 ;
F_81 ( & V_46 -> V_84 ) ;
while ( ! F_82 ( & V_46 -> V_74 ) ) {
struct V_25 * V_98 , * V_99 ;
unsigned int V_100 = V_101 ;
F_48 ( & V_46 -> V_73 ) ;
F_83 (obj, next_obj, &ucontext->uobjects,
list) {
if ( V_98 -> type -> V_102 == V_97 ) {
int V_3 ;
F_57 ( F_12 ( V_98 , true ) ) ;
V_3 = V_98 -> type -> V_30 -> V_83 ( V_98 ,
V_95 ) ;
F_60 ( & V_98 -> V_71 ) ;
if ( V_3 )
F_71 ( L_6 ,
V_98 -> V_1 , V_97 ) ;
F_10 ( V_98 ) ;
} else {
V_100 = F_84 ( V_100 ,
V_98 -> type -> V_102 ) ;
}
}
F_50 ( & V_46 -> V_73 ) ;
V_97 = V_100 ;
}
F_85 ( & V_46 -> V_84 ) ;
}
void F_86 ( struct V_36 * V_46 )
{
V_46 -> V_58 = 0 ;
F_87 ( & V_46 -> V_73 ) ;
F_45 ( & V_46 -> V_74 ) ;
F_88 ( & V_46 -> V_84 ) ;
}
struct V_25 * F_89 ( const struct V_38 * V_103 ,
struct V_36 * V_46 ,
enum V_104 V_105 ,
int V_1 )
{
switch ( V_105 ) {
case V_106 :
return F_36 ( V_103 , V_46 , V_1 , false ) ;
case V_107 :
case V_108 :
return F_36 ( V_103 , V_46 , V_1 , true ) ;
case V_109 :
return F_46 ( V_103 , V_46 ) ;
default:
F_57 ( true ) ;
return F_17 ( - V_52 ) ;
}
}
int F_90 ( struct V_25 * V_29 ,
enum V_104 V_105 ,
bool V_110 )
{
int V_3 = 0 ;
switch ( V_105 ) {
case V_106 :
F_76 ( V_29 , false ) ;
break;
case V_108 :
F_76 ( V_29 , true ) ;
break;
case V_107 :
if ( V_110 )
V_3 = F_61 ( V_29 ) ;
else
F_76 ( V_29 , true ) ;
break;
case V_109 :
if ( V_110 )
V_3 = F_70 ( V_29 ) ;
else
F_73 ( V_29 ) ;
break;
default:
F_57 ( true ) ;
V_3 = - V_52 ;
}
return V_3 ;
}
int F_91 ( struct V_111 * V_112 ,
struct V_113 * const * V_114 ,
T_4 V_115 ,
bool V_110 )
{
unsigned int V_116 ;
int V_3 = 0 ;
for ( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
struct V_117 * V_118 =
& V_112 -> V_119 [ V_116 ] ;
const struct V_113 * V_120 =
V_114 [ V_116 ] ;
unsigned int V_121 ;
for ( V_121 = 0 ; V_121 < V_118 -> V_122 ; V_121 ++ ) {
struct V_123 * V_124 ;
const struct V_125 * V_126 ;
if ( ! F_92 ( V_118 , V_121 ) )
continue;
V_124 = & V_118 -> V_127 [ V_121 ] ;
V_126 = & V_120 -> V_127 [ V_121 ] ;
if ( V_126 -> type == V_128 ||
V_126 -> type == V_129 ) {
int V_130 ;
V_130 = F_90 ( V_124 -> V_131 . V_26 ,
V_126 -> V_98 . V_105 ,
V_110 ) ;
if ( ! V_3 )
V_3 = V_130 ;
}
}
}
return V_3 ;
}
