static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = - 1 ;
}
static void F_6 ( struct V_8 * V_8 )
{
struct V_1 * V_2 =
F_7 ( V_8 , struct V_1 , V_3 ) ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( V_2 -> V_9 ) ;
F_10 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( V_2 )
return F_12 ( & V_2 -> V_3 , F_6 ) ;
return 1 ;
}
static struct V_1 * F_13 ( struct V_1 * V_2 )
{
if ( V_2 )
F_14 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = NULL ;
if ( V_2 == NULL )
return;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_12 )
V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
if ( V_11 && V_2 -> V_14 )
F_18 ( V_11 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
unsigned int V_15 = V_2 -> V_7 ;
bool V_16 = false ;
F_16 ( & V_17 ) ;
if ( V_2 == V_18 [ V_15 ] ) {
V_18 [ V_15 ] = NULL ;
V_16 = true ;
}
F_19 ( & V_17 ) ;
return V_16 ;
}
static struct V_1 * F_21 ( unsigned V_7 )
{
struct V_1 * V_2 ;
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
V_18 [ V_7 ] = NULL ;
F_19 ( & V_17 ) ;
return V_2 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_15 ( V_2 ) ;
if ( V_2 -> V_9 ) {
F_23 ( V_19 ,
F_24 ( V_20 , V_2 -> V_7 ) ) ;
}
F_11 ( V_2 ) ;
}
}
static struct V_21
* F_25 ( const struct V_1 * V_2 , unsigned V_7 )
{
struct V_21 * V_22 ;
unsigned int V_15 = V_7 - V_23 ;
F_26 ( V_15 >= V_24 ) ;
F_16 ( & V_25 ) ;
V_22 = V_26 [ V_15 ] ;
if ( V_22 && V_22 -> V_27 != V_2 )
V_22 = NULL ;
F_19 ( & V_25 ) ;
return V_22 ;
}
static struct V_1 * F_27 ( unsigned V_7 )
{
struct V_1 * V_2 ;
F_26 ( V_7 >= V_23 ) ;
F_16 ( & V_17 ) ;
V_2 = F_13 ( V_18 [ V_7 ] ) ;
F_19 ( & V_17 ) ;
return V_2 ;
}
static struct V_1 * F_28 ( unsigned V_7 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_15 = V_7 - V_23 ;
F_26 ( V_15 >= V_24 ) ;
F_16 ( & V_25 ) ;
V_22 = V_26 [ V_15 ] ;
V_2 = F_13 ( V_22 ? V_22 -> V_27 : NULL ) ;
F_19 ( & V_25 ) ;
return V_2 ;
}
struct V_1 * F_29 ( unsigned V_7 )
{
if ( V_7 < V_23 )
return F_27 ( V_7 ) ;
return F_28 ( V_7 ) ;
}
static struct V_21 *
F_30 ( const struct V_1 * V_2 , unsigned int V_7 )
{
struct V_21 * V_22 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( V_22 == NULL || ( V_22 -> V_28 & V_29 ) )
return V_22 ;
}
return V_2 -> V_30 ;
}
static struct V_21 *
F_31 ( const struct V_1 * V_2 , unsigned int V_7 )
{
struct V_21 * V_22 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( V_22 == NULL || ( V_22 -> V_28 & V_31 ) )
return V_22 ;
}
return V_2 -> V_32 ;
}
static void F_32 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 , * V_37 , * V_38 ;
unsigned int V_7 = F_33 ( F_34 ( V_33 ) ) ;
V_37 = V_2 -> V_30 ;
V_38 = V_2 -> V_32 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( V_22 == NULL || V_22 -> V_28 & V_29 )
V_37 = V_22 ;
if ( V_22 == NULL || V_22 -> V_28 & V_31 )
V_38 = V_22 ;
}
V_35 -> V_39 = V_2 -> V_12 ;
V_35 -> V_40 = V_2 -> V_41 ;
F_35 ( V_35 -> V_30 ) = V_37 ;
F_35 ( V_35 -> V_32 ) = V_38 ;
}
static void F_36 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_35 -> V_39 != V_2 -> V_12 ||
V_35 -> V_40 != V_2 -> V_41 )
F_32 ( V_33 ) ;
}
static struct V_21 * F_37 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
F_36 ( V_33 ) ;
return F_35 ( V_35 -> V_30 ) ;
}
static struct V_21 * F_38 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
F_36 ( V_33 ) ;
return F_35 ( V_35 -> V_32 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_21 * V_22 , unsigned V_42 )
{
struct V_43 * V_44 = V_22 -> V_44 ;
int V_45 ;
if ( V_42 > V_44 -> V_46 )
return - V_47 ;
if ( V_22 -> V_48 ) {
F_40 ( V_2 -> V_9 ,
L_1 ) ;
return - V_49 ;
}
if ( F_41 ( V_22 ) ) {
F_40 ( V_2 -> V_9 ,
L_2 ) ;
return - V_49 ;
}
V_42 = ( V_42 + V_50 - 1 ) & V_51 ;
V_45 = F_42 ( V_2 , V_22 , V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_22 -> V_52 ) {
V_45 = V_22 -> V_52 ( V_2 , V_22 ) ;
if ( V_45 < 0 )
return V_45 ;
}
F_40 ( V_2 -> V_9 , L_3 ,
V_22 -> V_53 , V_44 -> V_54 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_27 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_44 )
V_60 = V_22 -> V_44 -> V_46 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_58 , V_50 , L_4 , V_60 ) ;
}
static T_1 F_45 ( struct V_27 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_2 V_62 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 ;
int V_63 ;
V_63 = F_46 ( V_58 , 10 , & V_60 ) ;
if ( V_63 )
return V_63 ;
if ( V_60 > ( V_64 / 1024 ) )
return - V_65 ;
V_60 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_44 )
V_22 -> V_44 -> V_46 = V_60 ;
else
V_63 = - V_65 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_63 ? V_63 : V_62 ;
}
static T_1 F_47 ( struct V_27 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_44 )
V_60 = V_22 -> V_44 -> V_54 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_58 , V_50 , L_4 , V_60 ) ;
}
static T_1 F_48 ( struct V_27 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_2 V_62 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 ;
int V_63 ;
V_63 = F_46 ( V_58 , 10 , & V_60 ) ;
if ( V_63 )
return V_63 ;
if ( V_60 > ( V_64 / 1024 ) )
return - V_65 ;
V_60 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_44 )
V_63 = F_39 ( V_2 , V_22 , V_60 ) ;
else
V_63 = - V_65 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_63 ? V_63 : V_62 ;
}
static T_1 F_49 ( struct V_27 * V_55 ,
struct V_56 * V_57 ,
char * V_58 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_44 )
V_60 = V_22 -> V_44 -> V_46 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_58 , V_50 , L_4 , V_60 ) ;
}
static T_1 F_50 ( struct V_27 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_2 V_62 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 ;
int V_63 ;
V_63 = F_46 ( V_58 , 10 , & V_60 ) ;
if ( V_63 )
return V_63 ;
if ( V_60 > ( V_64 / 1024 ) )
return - V_65 ;
V_60 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_44 )
V_22 -> V_44 -> V_46 = V_60 ;
else
V_63 = - V_65 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_63 ? V_63 : V_62 ;
}
static T_1 F_51 ( struct V_27 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_44 )
V_60 = V_22 -> V_44 -> V_54 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_58 , V_50 , L_4 , V_60 ) ;
}
static T_1 F_52 ( struct V_27 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_2 V_62 )
{
unsigned int V_7 = F_44 ( V_55 -> V_59 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_60 ;
int V_63 ;
V_63 = F_46 ( V_58 , 10 , & V_60 ) ;
if ( V_63 )
return V_63 ;
if ( V_60 > ( V_64 / 1024 ) )
return - V_65 ;
V_60 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_44 )
V_63 = F_39 ( V_2 , V_22 , V_60 ) ;
else
V_63 = - V_65 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_63 ? V_63 : V_62 ;
}
static void F_53 ( struct V_21 * V_22 ,
unsigned V_66 , unsigned V_67 )
{
unsigned long V_68 ;
F_54 ( & V_22 -> V_69 , V_68 ) ;
V_22 -> V_70 &= ~ V_66 ;
V_22 -> V_70 |= ( V_67 & V_66 ) ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
}
static unsigned F_56 ( struct V_21 * V_22 )
{
unsigned long V_68 ;
unsigned V_70 ;
F_54 ( & V_22 -> V_69 , V_68 ) ;
V_70 = V_22 -> V_70 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
return V_70 ;
}
bool F_57 ( struct V_21 * V_22 )
{
unsigned V_70 = F_56 ( V_22 ) ;
return ( V_70 & V_71 ) ? true : false ;
}
static bool F_58 ( struct V_21 * V_22 )
{
unsigned V_70 = F_56 ( V_22 ) ;
return ( V_70 & V_72 ) ? true : false ;
}
static bool F_59 ( struct V_21 * V_22 )
{
unsigned V_70 = F_56 ( V_22 ) ;
return ( V_70 & ( V_72 | V_71 ) ) ? false : true ;
}
void * F_60 ( struct V_21 * V_22 , T_2 V_60 )
{
V_22 -> V_73 = F_61 ( V_60 , V_74 ) ;
if ( V_22 -> V_73 )
V_22 -> V_70 |= V_75 ;
return V_22 -> V_73 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_43 * V_44 = V_22 -> V_44 ;
F_53 ( V_22 , V_71 , 0 ) ;
if ( V_44 ) {
F_63 ( V_22 ) ;
V_44 -> V_76 = NULL ;
F_10 ( V_44 -> V_77 . V_78 ) ;
V_44 -> V_77 . V_78 = NULL ;
V_22 -> V_48 = NULL ;
F_64 ( & V_22 -> V_44 -> V_79 ) ;
} else {
F_65 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_48 = NULL ;
}
}
static int F_66 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_80 = 0 ;
if ( F_57 ( V_22 ) && V_22 -> V_81 )
V_80 = V_22 -> V_81 ( V_2 , V_22 ) ;
F_62 ( V_2 , V_22 ) ;
return V_80 ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_44 )
F_66 ( V_2 , V_22 ) ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_48 )
return 1 ;
if ( V_22 -> V_44 && F_41 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_84 T_3 * V_85 )
{
struct V_84 V_86 ;
if ( ! F_70 ( V_87 ) )
return - V_47 ;
if ( V_85 == NULL ) {
if ( F_68 ( V_2 ) )
return - V_49 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_71 ( & V_86 , V_85 , sizeof( V_86 ) ) )
return - V_88 ;
V_86 . V_89 [ V_90 - 1 ] = 0 ;
if ( V_86 . V_91 [ V_92 ] ) {
F_72 ( V_2 -> V_9 ,
L_6 ) ;
return - V_65 ;
}
if ( V_2 -> V_7 >= V_93 )
return - V_49 ;
return F_73 ( V_2 , & V_86 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_94 T_3 * V_85 )
{
struct V_94 V_95 ;
struct V_43 * V_44 ;
struct V_21 * V_22 ;
int V_45 = 0 ;
if ( F_71 ( & V_95 , V_85 , sizeof( V_95 ) ) )
return - V_88 ;
if ( V_95 . V_96 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_95 . V_96 ] ;
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
F_40 ( V_2 -> V_9 ,
L_7 ) ;
V_95 . V_60 = 0 ;
V_95 . V_97 = 0 ;
goto V_98;
}
if ( V_95 . V_97 ) {
if ( ! F_70 ( V_87 ) )
return - V_47 ;
V_44 -> V_46 = V_95 . V_97 ;
}
if ( V_95 . V_60 ) {
V_45 = F_39 ( V_2 , V_22 , V_95 . V_60 ) ;
if ( V_45 < 0 )
return V_45 ;
}
V_95 . V_60 = V_44 -> V_54 ;
V_95 . V_97 = V_44 -> V_46 ;
V_98:
if ( F_75 ( V_85 , & V_95 , sizeof( V_95 ) ) )
return - V_88 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_99 T_3 * V_85 ,
struct V_33 * V_33 )
{
struct V_21 * V_22 ;
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_101 = V_102 ;
V_100 . V_103 = V_2 -> V_82 ;
F_77 ( V_100 . V_104 , V_2 -> V_13 -> V_104 , V_90 ) ;
F_77 ( V_100 . V_89 , V_2 -> V_89 , V_90 ) ;
V_22 = F_37 ( V_33 ) ;
if ( V_22 )
V_100 . V_105 = V_22 -> V_53 ;
else
V_100 . V_105 = - 1 ;
V_22 = F_38 ( V_33 ) ;
if ( V_22 )
V_100 . V_106 = V_22 -> V_53 ;
else
V_100 . V_106 = - 1 ;
if ( F_75 ( V_85 , & V_100 , sizeof( V_100 ) ) )
return - V_88 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_107 T_3 * V_85 , void * V_33 )
{
int V_80 , V_15 ;
struct V_107 * V_108 , * V_109 ;
struct V_21 * V_22 ;
V_108 = F_79 ( V_2 -> V_82 , sizeof( * V_108 ) , V_74 ) ;
if ( ! V_108 )
return - V_110 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
V_109 = V_108 + V_15 ;
V_109 -> type = V_22 -> type ;
V_109 -> V_111 = V_22 -> V_111 ;
V_109 -> V_112 = V_22 -> V_28 ;
if ( F_57 ( V_22 ) )
V_109 -> V_112 |= V_113 ;
#define F_80 5
V_109 -> V_114 = F_80 ;
V_109 -> V_115 = V_22 -> V_115 ;
V_109 -> V_116 = V_22 -> V_116 ;
if ( V_22 -> V_117 ) {
V_109 -> V_118 =
( V_15 << 24 ) | ( 0 << 16 ) | ( V_22 -> V_117 -> V_119 ) ;
} else {
V_109 -> V_118 = 0 ;
}
if ( V_22 -> V_48 )
V_109 -> V_112 |= V_120 ;
if ( V_22 -> V_48 == V_33 )
V_109 -> V_112 |= V_121 ;
if ( V_22 -> V_122 )
V_109 -> V_112 |= V_123 ;
if ( V_22 -> V_122 == V_33 )
V_109 -> V_112 |= V_124 ;
if ( ! V_22 -> V_116 && V_22 -> V_125 )
V_109 -> V_112 |= V_126 ;
if ( V_22 -> V_127 )
V_109 -> V_112 |= V_128 ;
if ( V_22 -> V_129 )
V_109 -> V_112 |= V_130 ;
if ( V_22 -> V_131 != & V_132 )
V_109 -> V_133 = V_134 ;
else
V_109 -> V_133 = V_135 ;
}
V_80 = F_75 ( V_85 , V_108 , V_2 -> V_82 * sizeof( * V_108 ) ) ;
F_10 ( V_108 ) ;
return V_80 ? - V_88 : 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_136 T_3 * V_85 )
{
struct V_21 * V_22 ;
struct V_136 V_86 ;
if ( F_71 ( & V_86 , V_85 , sizeof( V_86 ) ) )
return - V_88 ;
if ( V_86 . V_137 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_86 . V_137 ] ;
if ( V_86 . V_125 ) {
if ( V_22 -> V_116 || ! V_22 -> V_125 )
return - V_65 ;
if ( F_75 ( V_86 . V_125 , V_22 -> V_125 ,
V_22 -> V_111 * sizeof( unsigned int ) ) )
return - V_88 ;
}
if ( V_86 . V_138 )
return - V_65 ;
if ( V_86 . V_139 ) {
int V_15 ;
if ( ! V_22 -> V_127 )
return - V_65 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_111 ; V_15 ++ ) {
int V_140 ;
V_140 = ( V_2 -> V_7 << 28 ) | ( V_86 . V_137 << 24 ) | ( V_15 << 16 ) |
( V_22 -> V_127 [ V_15 ] -> V_119 ) ;
if ( F_82 ( V_140 , V_86 . V_139 + V_15 ) )
return - V_88 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_141 T_3 * V_85 , void * V_33 )
{
struct V_141 V_142 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
if ( F_71 ( & V_142 , V_85 , sizeof( V_142 ) ) )
return - V_88 ;
if ( V_142 . V_96 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_142 . V_96 ] ;
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
F_40 ( V_2 -> V_9 ,
L_7 ) ;
V_142 . V_143 = 0 ;
V_142 . V_144 = 0 ;
V_142 . V_145 = 0 ;
V_142 . V_146 = 0 ;
V_142 . V_147 = 0 ;
V_142 . V_148 = 0 ;
goto V_98;
}
if ( ! V_22 -> V_48 ) {
V_142 . V_147 = 0 ;
V_142 . V_148 = 0 ;
goto V_149;
}
if ( V_22 -> V_48 != V_33 )
return - V_150 ;
if ( V_142 . V_147 && ! ( V_44 -> V_77 . V_68 & V_151 ) ) {
V_142 . V_147 = F_84 ( V_22 , V_142 . V_147 ) ;
F_85 ( V_22 , V_142 . V_147 ) ;
if ( F_59 ( V_22 ) &&
F_86 ( V_22 ) == 0 ) {
F_62 ( V_2 , V_22 ) ;
}
}
if ( V_142 . V_148 && ( V_44 -> V_77 . V_68 & V_151 ) ) {
V_142 . V_148 =
F_87 ( V_22 , V_142 . V_148 ) ;
F_88 ( V_22 , V_142 . V_148 ) ;
}
V_149:
V_142 . V_145 = V_44 -> V_145 ;
V_142 . V_143 = V_44 -> V_143 ;
V_142 . V_146 = V_44 -> V_146 ;
V_142 . V_144 = V_44 -> V_144 ;
V_98:
if ( F_75 ( V_85 , & V_142 , sizeof( V_142 ) ) )
return - V_88 ;
return 0 ;
}
static int F_89 ( struct V_152 * V_153 ,
unsigned int * V_154 )
{
if ( V_153 -> V_155 < 1 )
return - V_65 ;
switch ( V_154 [ 0 ] ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
if ( V_153 -> V_155 == 1 )
return 0 ;
break;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_153 -> V_155 == 2 )
return 0 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
if ( V_153 -> V_155 == 3 )
return 0 ;
break;
case V_183 :
case V_184 :
if ( V_153 -> V_155 == 5 )
return 0 ;
break;
case V_185 :
if ( V_153 -> V_155 == 6 )
return 0 ;
break;
default:
F_90 ( L_8 ,
V_154 [ 0 ] ) ;
F_90 ( L_9 , V_186 , __FILE__ ) ;
F_90 ( L_10 , V_153 -> V_155 ) ;
return 0 ;
}
return - V_65 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_152 * V_153 ,
unsigned int * V_154 , void * V_33 )
{
struct V_21 * V_22 ;
int V_80 = 0 ;
int V_15 ;
if ( V_153 -> V_153 & V_187 ) {
switch ( V_153 -> V_153 ) {
case V_188 :
{
struct V_189 V_190 ;
if ( V_153 -> V_155 != 2 ) {
V_80 = - V_65 ;
break;
}
F_92 ( & V_190 ) ;
V_154 [ 0 ] = V_190 . V_191 ;
V_154 [ 1 ] = V_190 . V_192 ;
V_80 = 2 ;
break;
}
case V_193 :
if ( V_153 -> V_155 != 1 || V_154 [ 0 ] >= 100000 ) {
V_80 = - V_65 ;
break;
}
F_93 ( V_154 [ 0 ] / 1000 ) ;
V_80 = 1 ;
break;
case V_194 :
if ( V_153 -> V_155 != 1 ) {
V_80 = - V_65 ;
break;
}
if ( V_153 -> V_137 >= V_2 -> V_82 ) {
F_40 ( V_2 -> V_9 ,
L_11 ,
V_153 -> V_137 ) ;
V_80 = - V_65 ;
break;
}
V_22 = & V_2 -> V_83 [ V_153 -> V_137 ] ;
if ( ! V_22 -> V_44 ) {
F_40 ( V_2 -> V_9 , L_12 ) ;
V_80 = - V_65 ;
break;
}
if ( ! V_22 -> V_44 -> V_76 ) {
F_40 ( V_2 -> V_9 , L_13 ) ;
V_80 = - V_195 ;
break;
}
V_80 = V_22 -> V_44 -> V_76 ( V_2 , V_22 , V_154 [ 0 ] ) ;
if ( V_80 >= 0 )
V_80 = 1 ;
break;
default:
F_40 ( V_2 -> V_9 , L_14 ) ;
V_80 = - V_65 ;
break;
}
} else {
unsigned int V_116 ;
if ( V_153 -> V_137 >= V_2 -> V_82 ) {
F_40 ( V_2 -> V_9 , L_15 ,
V_153 -> V_137 ) ;
V_80 = - V_65 ;
goto V_196;
}
V_22 = & V_2 -> V_83 [ V_153 -> V_137 ] ;
if ( V_22 -> type == V_197 ) {
F_40 ( V_2 -> V_9 , L_11 ,
V_153 -> V_137 ) ;
V_80 = - V_198 ;
goto V_196;
}
if ( V_22 -> V_122 && V_22 -> V_122 != V_33 ) {
F_40 ( V_2 -> V_9 , L_16 ) ;
V_80 = - V_150 ;
goto V_196;
}
V_80 = F_94 ( V_22 , 1 , & V_153 -> V_199 ) ;
if ( V_80 < 0 ) {
V_80 = - V_65 ;
F_40 ( V_2 -> V_9 , L_17 ) ;
goto V_196;
}
if ( V_22 -> V_48 ) {
V_80 = - V_49 ;
goto V_196;
}
V_22 -> V_48 = & F_91 ;
switch ( V_153 -> V_153 ) {
case V_200 :
V_80 = V_22 -> V_201 ( V_2 , V_22 , V_153 , V_154 ) ;
if ( V_80 == - V_202 ) {
F_40 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_53 ) ;
}
break;
case V_203 :
V_116 = V_22 -> V_125
? V_22 -> V_125 [ F_95 ( V_153 -> V_199 ) ]
: V_22 -> V_116 ;
for ( V_15 = 0 ; V_15 < V_153 -> V_155 ; ++ V_15 ) {
if ( V_154 [ V_15 ] > V_116 ) {
V_80 = - V_65 ;
F_40 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_80 == 0 ) {
V_80 = V_22 -> V_204 ( V_2 , V_22 , V_153 , V_154 ) ;
if ( V_80 == - V_202 ) {
F_40 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_53 ) ;
}
}
break;
case V_205 :
if ( V_153 -> V_155 != 2 ) {
V_80 = - V_65 ;
} else {
unsigned int V_206 = V_154 [ 0 ] ;
unsigned int V_207 = 0 ;
if ( V_22 -> V_111 <= 32 ) {
V_207 = F_95 ( V_153 -> V_199 ) ;
if ( V_207 > 0 ) {
V_153 -> V_199 = 0 ;
V_154 [ 0 ] <<= V_207 ;
V_154 [ 1 ] <<= V_207 ;
}
}
V_80 = V_22 -> V_131 ( V_2 , V_22 , V_153 , V_154 ) ;
V_154 [ 0 ] = V_206 ;
if ( V_207 > 0 )
V_154 [ 1 ] >>= V_207 ;
}
break;
case V_208 :
V_80 = F_89 ( V_153 , V_154 ) ;
if ( V_80 )
break;
V_80 = V_22 -> V_209 ( V_2 , V_22 , V_153 , V_154 ) ;
break;
default:
V_80 = - V_65 ;
break;
}
V_22 -> V_48 = NULL ;
}
V_196:
return V_80 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_210 T_3 * V_85 , void * V_33 )
{
struct V_210 V_211 ;
struct V_152 * V_212 = NULL ;
unsigned int * V_154 = NULL ;
int V_15 = 0 ;
int V_80 = 0 ;
if ( F_71 ( & V_211 , V_85 , sizeof( V_211 ) ) )
return - V_88 ;
V_154 = F_97 ( V_213 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_154 ) {
V_80 = - V_110 ;
goto error;
}
V_212 = F_79 ( V_211 . V_214 , sizeof( * V_212 ) , V_74 ) ;
if ( ! V_212 ) {
V_80 = - V_110 ;
goto error;
}
if ( F_71 ( V_212 , V_211 . V_212 ,
sizeof( * V_212 ) * V_211 . V_214 ) ) {
F_40 ( V_2 -> V_9 , L_21 ) ;
V_80 = - V_88 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_211 . V_214 ; V_15 ++ ) {
if ( V_212 [ V_15 ] . V_155 > V_213 ) {
F_40 ( V_2 -> V_9 ,
L_22 ) ;
V_80 = - V_65 ;
goto error;
}
if ( V_212 [ V_15 ] . V_153 & V_215 ) {
if ( F_71 ( V_154 , V_212 [ V_15 ] . V_154 ,
V_212 [ V_15 ] . V_155 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_21 ) ;
V_80 = - V_88 ;
goto error;
}
}
V_80 = F_91 ( V_2 , V_212 + V_15 , V_154 , V_33 ) ;
if ( V_80 < 0 )
goto error;
if ( V_212 [ V_15 ] . V_153 & V_216 ) {
if ( F_75 ( V_212 [ V_15 ] . V_154 , V_154 ,
V_212 [ V_15 ] . V_155 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_23 ) ;
V_80 = - V_88 ;
goto error;
}
}
if ( F_98 () )
F_99 () ;
}
error:
F_10 ( V_212 ) ;
F_10 ( V_154 ) ;
if ( V_80 < 0 )
return V_80 ;
return V_15 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_152 T_3 * V_85 , void * V_33 )
{
struct V_152 V_153 ;
unsigned int * V_154 = NULL ;
int V_80 = 0 ;
V_154 = F_97 ( V_213 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_154 ) {
V_80 = - V_110 ;
goto error;
}
if ( F_71 ( & V_153 , V_85 , sizeof( V_153 ) ) ) {
V_80 = - V_88 ;
goto error;
}
if ( V_153 . V_155 > V_213 )
V_153 . V_155 = V_213 ;
if ( V_153 . V_153 & V_215 ) {
if ( F_71 ( V_154 ,
V_153 . V_154 ,
V_153 . V_155 * sizeof( unsigned int ) ) ) {
V_80 = - V_88 ;
goto error;
}
}
V_80 = F_91 ( V_2 , & V_153 , V_154 , V_33 ) ;
if ( V_80 < 0 )
goto error;
if ( V_153 . V_153 & V_216 ) {
if ( F_75 ( V_153 . V_154 ,
V_154 ,
V_153 . V_155 * sizeof( unsigned int ) ) ) {
V_80 = - V_88 ;
goto error;
}
}
V_80 = V_153 . V_155 ;
error:
F_10 ( V_154 ) ;
return V_80 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 ,
struct V_217 * V_77 )
{
struct V_21 * V_22 ;
if ( F_71 ( V_77 , V_85 , sizeof( * V_77 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
return - V_88 ;
}
if ( V_77 -> V_137 >= V_2 -> V_82 ) {
F_40 ( V_2 -> V_9 , L_25 , V_77 -> V_137 ) ;
return - V_61 ;
}
V_22 = & V_2 -> V_83 [ V_77 -> V_137 ] ;
if ( V_22 -> type == V_197 ) {
F_40 ( V_2 -> V_9 , L_26 ,
V_77 -> V_137 ) ;
return - V_198 ;
}
if ( ! V_22 -> V_129 || ! V_22 -> V_218 || ! V_22 -> V_44 ) {
F_40 ( V_2 -> V_9 ,
L_27 ,
V_77 -> V_137 ) ;
return - V_198 ;
}
if ( V_77 -> V_219 > V_22 -> V_115 ) {
F_40 ( V_2 -> V_9 , L_28 ,
V_77 -> V_219 , V_22 -> V_115 ) ;
return - V_65 ;
}
switch ( V_22 -> V_28 & ( V_29 | V_31 ) ) {
case V_29 :
V_77 -> V_68 &= ~ V_151 ;
break;
case V_31 :
V_77 -> V_68 |= V_151 ;
break;
default:
break;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_220 ,
struct V_217 * V_77 )
{
unsigned int * V_78 ;
int V_80 ;
V_77 -> V_78 = NULL ;
V_78 = F_103 ( V_220 ,
V_77 -> V_219 * sizeof( unsigned int ) ) ;
if ( F_104 ( V_78 ) )
return F_105 ( V_78 ) ;
V_80 = F_94 ( V_22 , V_77 -> V_219 , V_78 ) ;
if ( V_80 < 0 ) {
F_10 ( V_78 ) ;
return V_80 ;
}
V_77 -> V_78 = V_78 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 , void * V_33 )
{
struct V_217 V_77 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
unsigned int T_3 * V_220 ;
int V_80 ;
V_80 = F_101 ( V_2 , V_85 , & V_77 ) ;
if ( V_80 )
return V_80 ;
V_220 = ( unsigned int T_3 * ) V_77 . V_78 ;
V_22 = & V_2 -> V_83 [ V_77 . V_137 ] ;
V_44 = V_22 -> V_44 ;
if ( V_22 -> V_122 && V_22 -> V_122 != V_33 ) {
F_40 ( V_2 -> V_9 , L_29 ) ;
return - V_150 ;
}
if ( V_22 -> V_48 ) {
F_40 ( V_2 -> V_9 , L_30 ) ;
return - V_49 ;
}
if ( V_77 . V_219 < 1 ) {
F_40 ( V_2 -> V_9 , L_31 ,
V_77 . V_219 ) ;
return - V_65 ;
}
V_44 -> V_77 = V_77 ;
V_44 -> V_77 . V_154 = NULL ;
V_80 = F_102 ( V_2 , V_22 , V_220 , & V_44 -> V_77 ) ;
if ( V_80 )
goto V_221;
V_80 = V_22 -> V_218 ( V_2 , V_22 , & V_44 -> V_77 ) ;
if ( V_44 -> V_77 . V_68 & V_222 || V_80 ) {
F_40 ( V_2 -> V_9 , L_32 , V_80 ) ;
V_77 = V_44 -> V_77 ;
V_77 . V_78 = ( unsigned int V_223 * ) V_220 ;
V_77 . V_154 = NULL ;
if ( F_75 ( V_85 , & V_77 , sizeof( V_77 ) ) ) {
F_40 ( V_2 -> V_9 , L_33 ) ;
V_80 = - V_88 ;
goto V_221;
}
V_80 = - V_195 ;
goto V_221;
}
if ( ! V_44 -> V_54 ) {
V_80 = - V_110 ;
F_40 ( V_2 -> V_9 , L_34 ) ;
goto V_221;
}
F_63 ( V_22 ) ;
V_44 -> V_224 = V_225 | V_226 ;
if ( V_44 -> V_77 . V_68 & V_227 )
V_44 -> V_224 |= V_228 ;
F_53 ( V_22 , V_72 | V_71 , V_71 ) ;
V_22 -> V_48 = V_33 ;
V_80 = V_22 -> V_129 ( V_2 , V_22 ) ;
if ( V_80 == 0 )
return 0 ;
V_221:
F_62 ( V_2 , V_22 ) ;
return V_80 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 , void * V_33 )
{
struct V_217 V_77 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_220 ;
int V_80 ;
V_80 = F_101 ( V_2 , V_85 , & V_77 ) ;
if ( V_80 )
return V_80 ;
V_220 = ( unsigned int T_3 * ) V_77 . V_78 ;
V_22 = & V_2 -> V_83 [ V_77 . V_137 ] ;
if ( V_220 ) {
V_80 = F_102 ( V_2 , V_22 , V_220 , & V_77 ) ;
if ( V_80 )
return V_80 ;
}
V_80 = V_22 -> V_218 ( V_2 , V_22 , & V_77 ) ;
F_10 ( V_77 . V_78 ) ;
V_77 . V_78 = ( unsigned int V_223 * ) V_220 ;
if ( F_75 ( V_85 , & V_77 , sizeof( V_77 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
V_80 = - V_88 ;
}
return V_80 ;
}
static int F_108 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_33 )
{
int V_80 = 0 ;
unsigned long V_68 ;
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
F_54 ( & V_22 -> V_69 , V_68 ) ;
if ( V_22 -> V_48 || V_22 -> V_122 )
V_80 = - V_49 ;
else
V_22 -> V_122 = V_33 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
return V_80 ;
}
static int F_109 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( V_22 -> V_48 )
return - V_49 ;
if ( V_22 -> V_122 && V_22 -> V_122 != V_33 )
return - V_150 ;
if ( V_22 -> V_122 == V_33 )
V_22 -> V_122 = NULL ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( V_22 -> V_44 == NULL )
return - V_65 ;
if ( ! V_22 -> V_48 )
return 0 ;
if ( V_22 -> V_48 != V_33 )
return - V_49 ;
return F_66 ( V_2 , V_22 ) ;
}
static int F_111 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( ! V_22 -> V_48 )
return 0 ;
if ( V_22 -> V_48 != V_33 )
return - V_49 ;
if ( V_22 -> V_229 )
return V_22 -> V_229 ( V_2 , V_22 ) ;
return - V_65 ;
}
static int F_112 ( struct V_1 * V_2 , unsigned long V_85 ,
struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_21 * V_230 , * V_231 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_231 = & V_2 -> V_83 [ V_85 ] ;
V_230 = F_37 ( V_33 ) ;
if ( V_230 == V_231 )
return 0 ;
if ( ! ( V_231 -> V_28 & V_29 ) )
return - V_65 ;
if ( V_230 && V_230 -> V_48 == V_33 && V_230 -> V_44 &&
! ( V_230 -> V_44 -> V_77 . V_68 & V_151 ) )
return - V_49 ;
F_35 ( V_35 -> V_30 ) = V_231 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , unsigned long V_85 ,
struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_21 * V_230 , * V_231 ;
if ( V_85 >= V_2 -> V_82 )
return - V_65 ;
V_231 = & V_2 -> V_83 [ V_85 ] ;
V_230 = F_38 ( V_33 ) ;
if ( V_230 == V_231 )
return 0 ;
if ( ! ( V_231 -> V_28 & V_31 ) )
return - V_65 ;
if ( V_230 && V_230 -> V_48 == V_33 && V_230 -> V_44 &&
( V_230 -> V_44 -> V_77 . V_68 & V_151 ) )
return - V_49 ;
F_35 ( V_35 -> V_32 ) = V_231 ;
return 0 ;
}
static long F_114 ( struct V_33 * V_33 , unsigned int V_77 ,
unsigned long V_85 )
{
unsigned V_7 = F_33 ( F_34 ( V_33 ) ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_232 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_77 == V_233 ) {
if ( V_7 >= V_23 ) {
V_232 = - V_234 ;
goto V_235;
}
V_232 = F_69 ( V_2 ,
(struct V_84 T_3 * ) V_85 ) ;
if ( V_232 == 0 ) {
if ( V_85 == 0 &&
V_2 -> V_7 >= V_93 ) {
if ( F_20 ( V_2 ) ) {
F_19 ( & V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return V_232 ;
}
}
}
goto V_235;
}
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_232 = - V_61 ;
goto V_235;
}
switch ( V_77 ) {
case V_236 :
V_232 = F_74 ( V_2 ,
(struct V_94 T_3 * ) V_85 ) ;
break;
case V_237 :
V_232 = F_76 ( V_2 , (struct V_99 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_238 :
V_232 = F_78 ( V_2 ,
(struct V_107 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_239 :
V_232 = F_81 ( V_2 , ( void T_3 * ) V_85 ) ;
break;
case V_240 :
V_232 = F_115 ( V_2 , ( void T_3 * ) V_85 ) ;
break;
case V_241 :
V_232 = F_83 ( V_2 ,
(struct V_141 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_242 :
V_232 = F_108 ( V_2 , V_85 , V_33 ) ;
break;
case V_243 :
V_232 = F_109 ( V_2 , V_85 , V_33 ) ;
break;
case V_244 :
V_232 = F_110 ( V_2 , V_85 , V_33 ) ;
break;
case V_245 :
V_232 = F_106 ( V_2 , (struct V_217 T_3 * ) V_85 , V_33 ) ;
break;
case V_246 :
V_232 = F_107 ( V_2 , (struct V_217 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_247 :
V_232 = F_96 ( V_2 ,
(struct V_210 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_248 :
V_232 = F_100 ( V_2 , (struct V_152 T_3 * ) V_85 ,
V_33 ) ;
break;
case V_249 :
V_232 = F_111 ( V_2 , V_85 , V_33 ) ;
break;
case V_250 :
V_232 = F_112 ( V_2 , V_85 , V_33 ) ;
break;
case V_251 :
V_232 = F_113 ( V_2 , V_85 , V_33 ) ;
break;
default:
V_232 = - V_234 ;
break;
}
V_235:
F_19 ( & V_2 -> V_5 ) ;
return V_232 ;
}
static void F_116 ( struct V_252 * V_253 )
{
struct V_254 * V_255 ;
V_255 = V_253 -> V_256 ;
F_117 ( V_255 ) ;
}
static void F_118 ( struct V_252 * V_253 )
{
struct V_254 * V_255 ;
V_255 = V_253 -> V_256 ;
F_119 ( V_255 ) ;
}
static int F_120 ( struct V_33 * V_33 , struct V_252 * V_257 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
struct V_254 * V_255 = NULL ;
unsigned long V_258 = V_257 -> V_259 ;
unsigned long V_60 ;
int V_260 ;
int V_15 ;
int V_45 ;
if ( ! F_121 ( & V_2 -> V_6 ) )
return - V_195 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_235;
}
if ( V_257 -> V_261 & V_262 )
V_22 = F_38 ( V_33 ) ;
else
V_22 = F_37 ( V_33 ) ;
if ( ! V_22 ) {
V_45 = - V_65 ;
goto V_235;
}
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
V_45 = - V_65 ;
goto V_235;
}
if ( V_257 -> V_263 != 0 ) {
F_40 ( V_2 -> V_9 , L_36 ) ;
V_45 = - V_65 ;
goto V_235;
}
V_60 = V_257 -> V_264 - V_257 -> V_259 ;
if ( V_60 > V_44 -> V_54 ) {
V_45 = - V_88 ;
goto V_235;
}
if ( V_60 & ( ~ V_51 ) ) {
V_45 = - V_88 ;
goto V_235;
}
V_260 = V_60 >> V_265 ;
V_255 = F_122 ( V_22 ) ;
if ( ! V_255 || V_260 > V_255 -> V_260 ) {
V_45 = - V_65 ;
goto V_235;
}
for ( V_15 = 0 ; V_15 < V_260 ; ++ V_15 ) {
struct V_266 * V_58 = & V_255 -> V_267 [ V_15 ] ;
if ( F_123 ( V_257 , V_258 ,
F_124 ( F_125 ( V_58 -> V_268 ) ) ,
V_50 , V_269 ) ) {
V_45 = - V_195 ;
goto V_235;
}
V_258 += V_50 ;
}
V_257 -> V_270 = & V_271 ;
V_257 -> V_256 = V_255 ;
V_257 -> V_270 -> V_272 ( V_257 ) ;
V_45 = 0 ;
V_235:
F_126 ( & V_2 -> V_6 ) ;
F_119 ( V_255 ) ;
return V_45 ;
}
static unsigned int F_127 ( struct V_33 * V_33 , T_4 * V_273 )
{
unsigned int V_66 = 0 ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
goto V_235;
}
V_22 = F_37 ( V_33 ) ;
if ( V_22 && V_22 -> V_44 ) {
F_128 ( V_33 , & V_22 -> V_44 -> V_79 , V_273 ) ;
if ( ! V_22 -> V_48 || ! F_57 ( V_22 ) ||
( V_22 -> V_44 -> V_77 . V_68 & V_151 ) ||
F_129 ( V_22 ) > 0 )
V_66 |= V_274 | V_275 ;
}
V_22 = F_38 ( V_33 ) ;
if ( V_22 && V_22 -> V_44 ) {
unsigned int V_276 = F_130 ( V_22 ) ;
F_128 ( V_33 , & V_22 -> V_44 -> V_79 , V_273 ) ;
F_87 ( V_22 , V_22 -> V_44 -> V_54 ) ;
if ( ! V_22 -> V_48 || ! F_57 ( V_22 ) ||
! ( V_22 -> V_44 -> V_77 . V_68 & V_151 ) ||
F_131 ( V_22 ) >= V_276 )
V_66 |= V_277 | V_278 ;
}
V_235:
F_19 ( & V_2 -> V_5 ) ;
return V_66 ;
}
static T_1 F_132 ( struct V_33 * V_33 , const char T_3 * V_58 ,
T_2 V_279 , T_5 * V_280 )
{
struct V_21 * V_22 ;
struct V_43 * V_44 ;
int V_155 , V_281 , V_62 = 0 , V_45 = 0 ;
F_133 ( V_273 , V_282 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
bool V_283 = false ;
bool V_284 ;
unsigned int V_285 ;
F_134 ( & V_2 -> V_6 ) ;
V_284 = true ;
V_285 = V_2 -> V_41 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_196;
}
V_22 = F_38 ( V_33 ) ;
if ( ! V_22 || ! V_22 -> V_44 ) {
V_45 = - V_198 ;
goto V_196;
}
V_44 = V_22 -> V_44 ;
if ( ! V_22 -> V_48 || ! V_279 )
goto V_196;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_150 ;
goto V_196;
}
if ( ! ( V_44 -> V_77 . V_68 & V_151 ) ) {
V_45 = - V_65 ;
goto V_196;
}
F_135 ( & V_44 -> V_79 , & V_273 ) ;
V_283 = true ;
while ( V_279 > 0 && ! V_45 ) {
F_136 ( V_286 ) ;
if ( ! F_57 ( V_22 ) ) {
if ( V_62 == 0 ) {
struct V_21 * V_287 ;
if ( F_58 ( V_22 ) )
V_45 = - V_288 ;
else
V_45 = 0 ;
F_137 ( & V_44 -> V_79 , & V_273 ) ;
V_283 = false ;
F_126 ( & V_2 -> V_6 ) ;
V_284 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_287 = F_38 ( V_33 ) ;
if ( V_2 -> V_12 &&
V_285 == V_2 -> V_41 &&
V_22 == V_287 && V_287 -> V_44 == V_44 )
F_62 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
break;
}
V_155 = V_279 ;
V_281 = V_155 ;
if ( V_44 -> V_143 + V_281 > V_44 -> V_54 )
V_281 = V_44 -> V_54 - V_44 -> V_143 ;
F_87 ( V_22 , V_44 -> V_54 ) ;
if ( V_281 > F_131 ( V_22 ) )
V_281 = F_131 ( V_22 ) ;
if ( V_281 < V_155 )
V_155 = V_281 ;
if ( V_155 == 0 ) {
if ( V_33 -> V_289 & V_290 ) {
V_45 = - V_195 ;
break;
}
F_99 () ;
if ( F_138 ( V_282 ) ) {
V_45 = - V_291 ;
break;
}
if ( ! V_22 -> V_48 )
break;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_150 ;
break;
}
if ( ! ( V_44 -> V_77 . V_68 & V_151 ) ) {
V_45 = - V_65 ;
break;
}
continue;
}
V_281 = F_71 ( V_44 -> V_292 + V_44 -> V_143 ,
V_58 , V_155 ) ;
if ( V_281 ) {
V_155 -= V_281 ;
V_45 = - V_88 ;
}
F_88 ( V_22 , V_155 ) ;
V_62 += V_155 ;
V_279 -= V_155 ;
V_58 += V_155 ;
break;
}
V_196:
if ( V_283 )
F_137 ( & V_44 -> V_79 , & V_273 ) ;
F_136 ( V_293 ) ;
if ( V_284 )
F_126 ( & V_2 -> V_6 ) ;
return V_62 ? V_62 : V_45 ;
}
static T_1 F_139 ( struct V_33 * V_33 , char T_3 * V_58 , T_2 V_279 ,
T_5 * V_280 )
{
struct V_21 * V_22 ;
struct V_43 * V_44 ;
int V_155 , V_281 , V_62 = 0 , V_45 = 0 ;
F_133 ( V_273 , V_282 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_285 ;
bool V_294 = false ;
bool V_284 ;
F_134 ( & V_2 -> V_6 ) ;
V_284 = true ;
V_285 = V_2 -> V_41 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_196;
}
V_22 = F_37 ( V_33 ) ;
if ( ! V_22 || ! V_22 -> V_44 ) {
V_45 = - V_198 ;
goto V_196;
}
V_44 = V_22 -> V_44 ;
if ( ! V_22 -> V_48 || ! V_279 )
goto V_196;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_150 ;
goto V_196;
}
if ( V_44 -> V_77 . V_68 & V_151 ) {
V_45 = - V_65 ;
goto V_196;
}
F_135 ( & V_44 -> V_79 , & V_273 ) ;
while ( V_279 > 0 && ! V_45 ) {
F_136 ( V_286 ) ;
V_155 = V_279 ;
V_281 = F_129 ( V_22 ) ;
if ( V_44 -> V_144 + V_281 > V_44 -> V_54 )
V_281 = V_44 -> V_54 - V_44 -> V_144 ;
if ( V_281 < V_155 )
V_155 = V_281 ;
if ( V_155 == 0 ) {
if ( ! F_57 ( V_22 ) ) {
if ( F_58 ( V_22 ) )
V_45 = - V_288 ;
else
V_45 = 0 ;
V_294 = true ;
break;
}
if ( V_33 -> V_289 & V_290 ) {
V_45 = - V_195 ;
break;
}
F_99 () ;
if ( F_138 ( V_282 ) ) {
V_45 = - V_291 ;
break;
}
if ( ! V_22 -> V_48 ) {
V_45 = 0 ;
break;
}
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_150 ;
break;
}
if ( V_44 -> V_77 . V_68 & V_151 ) {
V_45 = - V_65 ;
break;
}
continue;
}
V_281 = F_75 ( V_58 , V_44 -> V_292 +
V_44 -> V_144 , V_155 ) ;
if ( V_281 ) {
V_155 -= V_281 ;
V_45 = - V_88 ;
}
F_84 ( V_22 , V_155 ) ;
F_85 ( V_22 , V_155 ) ;
V_62 += V_155 ;
V_279 -= V_155 ;
V_58 += V_155 ;
break;
}
F_137 ( & V_44 -> V_79 , & V_273 ) ;
F_136 ( V_293 ) ;
if ( V_294 || F_59 ( V_22 ) ) {
struct V_21 * V_287 ;
F_126 ( & V_2 -> V_6 ) ;
V_284 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_287 = F_37 ( V_33 ) ;
if ( V_2 -> V_12 && V_285 == V_2 -> V_41 &&
V_22 == V_287 && V_287 -> V_44 == V_44 ) {
if ( V_294 || F_86 ( V_22 ) == 0 )
F_62 ( V_2 , V_22 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
V_196:
if ( V_284 )
F_126 ( & V_2 -> V_6 ) ;
return V_62 ? V_62 : V_45 ;
}
static int F_140 ( struct V_295 * V_295 , struct V_33 * V_33 )
{
const unsigned V_7 = F_33 ( V_295 ) ;
struct V_34 * V_35 ;
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_232 ;
if ( ! V_2 ) {
F_141 ( L_37 ) ;
return - V_61 ;
}
V_35 = F_61 ( sizeof( * V_35 ) , V_74 ) ;
if ( ! V_35 )
return - V_110 ;
V_35 -> V_2 = V_2 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_70 ( V_296 ) ) {
F_40 ( V_2 -> V_9 , L_38 ) ;
V_232 = - V_61 ;
goto V_196;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_142 ( V_2 -> V_13 -> V_10 ) ) {
V_232 = - V_297 ;
goto V_196;
}
if ( V_2 -> V_272 ) {
V_232 = V_2 -> V_272 ( V_2 ) ;
if ( V_232 < 0 ) {
F_18 ( V_2 -> V_13 -> V_10 ) ;
goto V_196;
}
}
}
V_2 -> V_14 ++ ;
V_33 -> V_36 = V_35 ;
F_32 ( V_33 ) ;
V_232 = 0 ;
V_196:
F_19 ( & V_2 -> V_5 ) ;
if ( V_232 ) {
F_11 ( V_2 ) ;
F_10 ( V_35 ) ;
}
return V_232 ;
}
static int F_143 ( int V_298 , struct V_33 * V_33 , int V_299 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
return F_144 ( V_298 , V_33 , V_299 , & V_2 -> V_300 ) ;
}
static int F_145 ( struct V_295 * V_295 , struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 = NULL ;
int V_15 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_83 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_48 == V_33 )
F_66 ( V_2 , V_22 ) ;
if ( V_22 -> V_122 == V_33 )
V_22 -> V_122 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_301 )
V_2 -> V_301 ( V_2 ) ;
F_18 ( V_2 -> V_13 -> V_10 ) ;
}
V_2 -> V_14 -- ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
F_10 ( V_35 ) ;
return 0 ;
}
void F_146 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_43 * V_44 = V_22 -> V_44 ;
unsigned V_70 = 0 ;
unsigned V_302 = 0 ;
if ( ! F_57 ( V_22 ) )
return;
if ( V_22 -> V_44 -> V_303 & V_226 )
V_302 |= V_71 ;
if ( V_22 -> V_44 -> V_303 & V_304 ) {
V_302 |= V_72 ;
V_70 |= V_72 ;
}
if ( V_302 ) {
F_53 ( V_22 , V_302 , V_70 ) ;
}
if ( V_44 -> V_224 & V_22 -> V_44 -> V_303 ) {
F_147 ( & V_44 -> V_79 ) ;
if ( V_22 -> V_28 & V_29 )
F_148 ( & V_2 -> V_300 , V_305 , V_306 ) ;
if ( V_22 -> V_28 & V_31 )
F_148 ( & V_2 -> V_300 , V_305 , V_307 ) ;
}
V_22 -> V_44 -> V_303 = 0 ;
}
struct V_1 * F_149 ( struct V_27 * V_308 )
{
struct V_1 * V_2 ;
struct V_27 * V_55 ;
unsigned V_15 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_74 ) ;
if ( V_2 == NULL )
return F_150 ( - V_110 ) ;
F_1 ( V_2 ) ;
F_151 ( V_2 , V_308 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_308 ? V_93 : 0 ;
V_15 < V_23 ; ++ V_15 ) {
if ( V_18 [ V_15 ] == NULL ) {
V_18 [ V_15 ] = V_2 ;
break;
}
}
F_19 ( & V_17 ) ;
if ( V_15 == V_23 ) {
F_19 ( & V_2 -> V_5 ) ;
F_15 ( V_2 ) ;
F_11 ( V_2 ) ;
F_152 ( L_39 ) ;
return F_150 ( - V_49 ) ;
}
V_2 -> V_7 = V_15 ;
V_55 = F_153 ( V_19 , V_308 ,
F_24 ( V_20 , V_15 ) , NULL , L_40 , V_15 ) ;
if ( ! F_104 ( V_55 ) )
V_2 -> V_9 = F_154 ( V_55 ) ;
return V_2 ;
}
static void F_155 ( unsigned V_7 )
{
F_26 ( V_7 >= V_23 ) ;
F_22 ( F_21 ( V_7 ) ) ;
}
void F_156 ( struct V_27 * V_308 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_93 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_309 == V_308 ) {
V_18 [ V_7 ] = NULL ;
F_19 ( & V_17 ) ;
F_22 ( V_2 ) ;
break;
}
F_19 ( & V_17 ) ;
}
}
int F_157 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_27 ;
struct V_27 * V_55 ;
unsigned V_15 ;
F_16 ( & V_25 ) ;
for ( V_15 = 0 ; V_15 < V_24 ; ++ V_15 ) {
if ( V_26 [ V_15 ] == NULL ) {
V_26 [ V_15 ] = V_22 ;
break;
}
}
F_19 ( & V_25 ) ;
if ( V_15 == V_24 ) {
F_152 ( L_41 ) ;
return - V_49 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_55 = F_153 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_42 ,
V_2 -> V_7 , V_22 -> V_53 ) ;
if ( ! F_104 ( V_55 ) )
V_22 -> V_9 = V_55 ;
return 0 ;
}
void F_158 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( V_22 == NULL )
return;
if ( V_22 -> V_7 < 0 )
return;
F_26 ( V_22 -> V_7 >= V_310 ) ;
F_26 ( V_22 -> V_7 < V_23 ) ;
V_15 = V_22 -> V_7 - V_23 ;
F_16 ( & V_25 ) ;
if ( V_22 == V_26 [ V_15 ] )
V_26 [ V_15 ] = NULL ;
F_19 ( & V_25 ) ;
if ( V_22 -> V_9 ) {
F_23 ( V_19 , F_24 ( V_20 , V_22 -> V_7 ) ) ;
V_22 -> V_9 = NULL ;
}
}
static void F_159 ( void )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ )
F_155 ( V_15 ) ;
}
static int T_6 F_160 ( void )
{
int V_15 ;
int V_45 ;
F_161 ( L_43 V_311 L_44 ) ;
if ( V_93 < 0 ||
V_93 > V_23 ) {
F_152 ( L_45 ,
V_23 ) ;
return - V_65 ;
}
V_45 = F_162 ( F_24 ( V_20 , 0 ) ,
V_310 , L_46 ) ;
if ( V_45 )
return - V_198 ;
F_163 ( & V_312 , & V_313 ) ;
V_312 . V_314 = V_315 ;
V_45 = F_164 ( & V_312 . V_316 , L_46 ) ;
if ( V_45 ) {
F_165 ( F_24 ( V_20 , 0 ) ,
V_310 ) ;
return V_45 ;
}
if ( F_166 ( & V_312 , F_24 ( V_20 , 0 ) , V_310 ) ) {
F_165 ( F_24 ( V_20 , 0 ) ,
V_310 ) ;
return - V_198 ;
}
V_19 = F_167 ( V_315 , L_46 ) ;
if ( F_104 ( V_19 ) ) {
F_152 ( L_47 ) ;
F_168 ( & V_312 ) ;
F_165 ( F_24 ( V_20 , 0 ) ,
V_310 ) ;
return F_105 ( V_19 ) ;
}
V_19 -> V_317 = V_318 ;
F_169 () ;
for ( V_15 = 0 ; V_15 < V_93 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_149 ( NULL ) ;
if ( F_104 ( V_2 ) ) {
F_159 () ;
F_168 ( & V_312 ) ;
F_165 ( F_24 ( V_20 , 0 ) ,
V_310 ) ;
return F_105 ( V_2 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
return 0 ;
}
static void T_7 F_170 ( void )
{
int V_15 ;
F_159 () ;
for ( V_15 = 0 ; V_15 < V_23 ; ++ V_15 )
F_26 ( V_18 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_24 ; ++ V_15 )
F_26 ( V_26 [ V_15 ] ) ;
F_171 ( V_19 ) ;
F_168 ( & V_312 ) ;
F_165 ( F_24 ( V_20 , 0 ) , V_310 ) ;
F_172 () ;
}
