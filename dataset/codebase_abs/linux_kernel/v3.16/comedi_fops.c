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
else
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
static int F_32 ( struct V_1 * V_2 ,
struct V_21 * V_22 , unsigned V_33 )
{
struct V_34 * V_35 = V_22 -> V_35 ;
int V_36 ;
if ( V_33 > V_35 -> V_37 )
return - V_38 ;
if ( V_22 -> V_39 ) {
F_33 ( V_2 -> V_9 ,
L_1 ) ;
return - V_40 ;
}
if ( F_34 ( V_22 ) ) {
F_33 ( V_2 -> V_9 ,
L_2 ) ;
return - V_40 ;
}
V_33 = ( V_33 + V_41 - 1 ) & V_42 ;
V_36 = F_35 ( V_2 , V_22 , V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_22 -> V_43 ) {
V_36 = V_22 -> V_43 ( V_2 , V_22 , V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_33 ( V_2 -> V_9 , L_3 ,
V_22 -> V_44 , V_35 -> V_45 ) ;
return 0 ;
}
static T_1 F_36 ( struct V_27 * V_46 ,
struct V_47 * V_48 , char * V_49 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_35 )
V_51 = V_22 -> V_35 -> V_37 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_49 , V_41 , L_4 , V_51 ) ;
}
static T_1 F_38 ( struct V_27 * V_46 ,
struct V_47 * V_48 ,
const char * V_49 , T_2 V_53 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 ;
int V_54 ;
V_54 = F_39 ( V_49 , 10 , & V_51 ) ;
if ( V_54 )
return V_54 ;
if ( V_51 > ( V_55 / 1024 ) )
return - V_56 ;
V_51 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_35 )
V_22 -> V_35 -> V_37 = V_51 ;
else
V_54 = - V_56 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_54 ? V_54 : V_53 ;
}
static T_1 F_40 ( struct V_27 * V_46 ,
struct V_47 * V_48 , char * V_49 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_35 )
V_51 = V_22 -> V_35 -> V_45 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_49 , V_41 , L_4 , V_51 ) ;
}
static T_1 F_41 ( struct V_27 * V_46 ,
struct V_47 * V_48 ,
const char * V_49 , T_2 V_53 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 ;
int V_54 ;
V_54 = F_39 ( V_49 , 10 , & V_51 ) ;
if ( V_54 )
return V_54 ;
if ( V_51 > ( V_55 / 1024 ) )
return - V_56 ;
V_51 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_29 ) && V_22 -> V_35 )
V_54 = F_32 ( V_2 , V_22 , V_51 ) ;
else
V_54 = - V_56 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_54 ? V_54 : V_53 ;
}
static T_1 F_42 ( struct V_27 * V_46 ,
struct V_47 * V_48 ,
char * V_49 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_35 )
V_51 = V_22 -> V_35 -> V_37 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_49 , V_41 , L_4 , V_51 ) ;
}
static T_1 F_43 ( struct V_27 * V_46 ,
struct V_47 * V_48 ,
const char * V_49 , T_2 V_53 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 ;
int V_54 ;
V_54 = F_39 ( V_49 , 10 , & V_51 ) ;
if ( V_54 )
return V_54 ;
if ( V_51 > ( V_55 / 1024 ) )
return - V_56 ;
V_51 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_35 )
V_22 -> V_35 -> V_37 = V_51 ;
else
V_54 = - V_56 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_54 ? V_54 : V_53 ;
}
static T_1 F_44 ( struct V_27 * V_46 ,
struct V_47 * V_48 , char * V_49 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 = 0 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_35 )
V_51 = V_22 -> V_35 -> V_45 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_49 , V_41 , L_4 , V_51 ) ;
}
static T_1 F_45 ( struct V_27 * V_46 ,
struct V_47 * V_48 ,
const char * V_49 , T_2 V_53 )
{
unsigned int V_7 = F_37 ( V_46 -> V_50 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_51 ;
int V_54 ;
V_54 = F_39 ( V_49 , 10 , & V_51 ) ;
if ( V_54 )
return V_54 ;
if ( V_51 > ( V_55 / 1024 ) )
return - V_56 ;
V_51 *= 1024 ;
V_2 = F_29 ( V_7 ) ;
if ( ! V_2 )
return - V_52 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_28 & V_31 ) && V_22 -> V_35 )
V_54 = F_32 ( V_2 , V_22 , V_51 ) ;
else
V_54 = - V_56 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_54 ? V_54 : V_53 ;
}
static void F_46 ( struct V_21 * V_22 ,
unsigned V_57 , unsigned V_58 )
{
unsigned long V_59 ;
F_47 ( & V_22 -> V_60 , V_59 ) ;
V_22 -> V_61 &= ~ V_57 ;
V_22 -> V_61 |= ( V_58 & V_57 ) ;
F_48 ( & V_22 -> V_60 , V_59 ) ;
}
static unsigned F_49 ( struct V_21 * V_22 )
{
unsigned long V_59 ;
unsigned V_61 ;
F_47 ( & V_22 -> V_60 , V_59 ) ;
V_61 = V_22 -> V_61 ;
F_48 ( & V_22 -> V_60 , V_59 ) ;
return V_61 ;
}
bool F_50 ( struct V_21 * V_22 )
{
unsigned V_61 = F_49 ( V_22 ) ;
return ( V_61 & V_62 ) ? true : false ;
}
static bool F_51 ( struct V_21 * V_22 )
{
unsigned V_61 = F_49 ( V_22 ) ;
return ( V_61 & V_63 ) ? true : false ;
}
static bool F_52 ( struct V_21 * V_22 )
{
unsigned V_61 = F_49 ( V_22 ) ;
return ( V_61 & ( V_63 | V_62 ) ) ? false : true ;
}
void * F_53 ( struct V_21 * V_22 , T_2 V_51 )
{
V_22 -> V_64 = F_54 ( V_51 , V_65 ) ;
if ( V_22 -> V_64 )
V_22 -> V_61 |= V_66 ;
return V_22 -> V_64 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_34 * V_35 = V_22 -> V_35 ;
F_46 ( V_22 , V_62 , 0 ) ;
if ( V_35 ) {
F_56 ( V_22 ) ;
V_35 -> V_67 = NULL ;
F_10 ( V_35 -> V_68 . V_69 ) ;
V_35 -> V_68 . V_69 = NULL ;
V_22 -> V_39 = NULL ;
F_57 ( & V_22 -> V_35 -> V_70 ) ;
} else {
F_58 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_39 = NULL ;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_71 = 0 ;
if ( F_50 ( V_22 ) && V_22 -> V_72 )
V_71 = V_22 -> V_72 ( V_2 , V_22 ) ;
F_55 ( V_2 , V_22 ) ;
return V_71 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_73 ; V_15 ++ ) {
V_22 = & V_2 -> V_74 [ V_15 ] ;
if ( V_22 -> V_35 )
F_59 ( V_2 , V_22 ) ;
}
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_73 ; V_15 ++ ) {
V_22 = & V_2 -> V_74 [ V_15 ] ;
if ( V_22 -> V_39 )
return 1 ;
if ( V_22 -> V_35 && F_34 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_75 T_3 * V_76 )
{
struct V_75 V_77 ;
if ( ! F_63 ( V_78 ) )
return - V_38 ;
if ( V_76 == NULL ) {
if ( F_61 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_64 ( & V_77 , V_76 , sizeof( V_77 ) ) )
return - V_79 ;
V_77 . V_80 [ V_81 - 1 ] = 0 ;
if ( V_77 . V_82 [ V_83 ] ) {
F_65 ( V_2 -> V_9 ,
L_6 ) ;
return - V_56 ;
}
if ( V_2 -> V_7 >= V_84 )
return - V_40 ;
return F_66 ( V_2 , & V_77 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_85 T_3 * V_76 )
{
struct V_85 V_86 ;
struct V_34 * V_35 ;
struct V_21 * V_22 ;
int V_36 = 0 ;
if ( F_64 ( & V_86 , V_76 , sizeof( V_86 ) ) )
return - V_79 ;
if ( V_86 . V_87 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_86 . V_87 ] ;
V_35 = V_22 -> V_35 ;
if ( ! V_35 ) {
F_33 ( V_2 -> V_9 ,
L_7 ) ;
V_86 . V_51 = 0 ;
V_86 . V_88 = 0 ;
goto V_89;
}
if ( V_86 . V_88 ) {
if ( ! F_63 ( V_78 ) )
return - V_38 ;
V_35 -> V_37 = V_86 . V_88 ;
}
if ( V_86 . V_51 ) {
V_36 = F_32 ( V_2 , V_22 , V_86 . V_51 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_86 . V_51 = V_35 -> V_45 ;
V_86 . V_88 = V_35 -> V_37 ;
V_89:
if ( F_68 ( V_76 , & V_86 , sizeof( V_86 ) ) )
return - V_79 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_90 T_3 * V_76 ,
struct V_91 * V_91 )
{
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_21 * V_22 ;
struct V_90 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_93 = V_94 ;
V_92 . V_95 = V_2 -> V_73 ;
F_72 ( V_92 . V_96 , V_2 -> V_13 -> V_96 , V_81 ) ;
F_72 ( V_92 . V_80 , V_2 -> V_80 , V_81 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 )
V_92 . V_97 = V_22 -> V_44 ;
else
V_92 . V_97 = - 1 ;
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 )
V_92 . V_98 = V_22 -> V_44 ;
else
V_92 . V_98 = - 1 ;
if ( F_68 ( V_76 , & V_92 , sizeof( V_92 ) ) )
return - V_79 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_99 T_3 * V_76 , void * V_91 )
{
int V_71 , V_15 ;
struct V_99 * V_100 , * V_101 ;
struct V_21 * V_22 ;
V_100 = F_74 ( V_2 -> V_73 , sizeof( * V_100 ) , V_65 ) ;
if ( ! V_100 )
return - V_102 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_73 ; V_15 ++ ) {
V_22 = & V_2 -> V_74 [ V_15 ] ;
V_101 = V_100 + V_15 ;
V_101 -> type = V_22 -> type ;
V_101 -> V_103 = V_22 -> V_103 ;
V_101 -> V_104 = V_22 -> V_28 ;
if ( F_50 ( V_22 ) )
V_101 -> V_104 |= V_105 ;
#define F_75 5
V_101 -> V_106 = F_75 ;
V_101 -> V_107 = V_22 -> V_107 ;
V_101 -> V_108 = V_22 -> V_108 ;
if ( V_22 -> V_109 ) {
V_101 -> V_110 =
( V_15 << 24 ) | ( 0 << 16 ) | ( V_22 -> V_109 -> V_111 ) ;
} else {
V_101 -> V_110 = 0 ;
}
if ( V_22 -> V_39 )
V_101 -> V_104 |= V_112 ;
if ( V_22 -> V_39 == V_91 )
V_101 -> V_104 |= V_113 ;
if ( V_22 -> V_114 )
V_101 -> V_104 |= V_115 ;
if ( V_22 -> V_114 == V_91 )
V_101 -> V_104 |= V_116 ;
if ( ! V_22 -> V_108 && V_22 -> V_117 )
V_101 -> V_104 |= V_118 ;
if ( V_22 -> V_119 )
V_101 -> V_104 |= V_120 ;
if ( V_22 -> V_121 )
V_101 -> V_104 |= V_122 ;
if ( V_22 -> V_123 != & V_124 )
V_101 -> V_125 = V_126 ;
else
V_101 -> V_125 = V_127 ;
}
V_71 = F_68 ( V_76 , V_100 , V_2 -> V_73 * sizeof( * V_100 ) ) ;
F_10 ( V_100 ) ;
return V_71 ? - V_79 : 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_128 T_3 * V_76 )
{
struct V_21 * V_22 ;
struct V_128 V_77 ;
if ( F_64 ( & V_77 , V_76 , sizeof( V_77 ) ) )
return - V_79 ;
if ( V_77 . V_129 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_77 . V_129 ] ;
if ( V_77 . V_117 ) {
if ( V_22 -> V_108 || ! V_22 -> V_117 )
return - V_56 ;
if ( F_68 ( V_77 . V_117 , V_22 -> V_117 ,
V_22 -> V_103 * sizeof( unsigned int ) ) )
return - V_79 ;
}
if ( V_77 . V_130 )
return - V_56 ;
if ( V_77 . V_131 ) {
int V_15 ;
if ( ! V_22 -> V_119 )
return - V_56 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_103 ; V_15 ++ ) {
int V_132 ;
V_132 = ( V_2 -> V_7 << 28 ) | ( V_77 . V_129 << 24 ) | ( V_15 << 16 ) |
( V_22 -> V_119 [ V_15 ] -> V_111 ) ;
if ( F_77 ( V_132 , V_77 . V_131 + V_15 ) )
return - V_79 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_133 T_3 * V_76 , void * V_91 )
{
struct V_133 V_134 ;
struct V_21 * V_22 ;
struct V_34 * V_35 ;
if ( F_64 ( & V_134 , V_76 , sizeof( V_134 ) ) )
return - V_79 ;
if ( V_134 . V_87 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_134 . V_87 ] ;
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 )
return - V_135 ;
V_35 = V_22 -> V_35 ;
if ( ! V_35 ) {
F_33 ( V_2 -> V_9 ,
L_7 ) ;
V_134 . V_136 = 0 ;
V_134 . V_137 = 0 ;
V_134 . V_138 = 0 ;
V_134 . V_139 = 0 ;
V_134 . V_140 = 0 ;
V_134 . V_141 = 0 ;
goto V_89;
}
if ( ! V_22 -> V_39 ) {
V_134 . V_140 = 0 ;
V_134 . V_141 = 0 ;
goto V_142;
}
if ( V_22 -> V_39 != V_91 )
return - V_135 ;
if ( V_134 . V_140 && ( V_22 -> V_28 & V_29 ) ) {
V_134 . V_140 = F_79 ( V_22 , V_134 . V_140 ) ;
F_80 ( V_22 , V_134 . V_140 ) ;
if ( F_52 ( V_22 ) &&
V_35 -> V_138 == V_35 -> V_139 ) {
F_55 ( V_2 , V_22 ) ;
}
}
if ( V_134 . V_141 && ( V_22 -> V_28 & V_31 ) ) {
V_134 . V_141 =
F_81 ( V_22 , V_134 . V_141 ) ;
F_82 ( V_22 , V_134 . V_141 ) ;
}
V_142:
V_134 . V_138 = V_35 -> V_138 ;
V_134 . V_136 = V_35 -> V_136 ;
V_134 . V_139 = V_35 -> V_139 ;
V_134 . V_137 = V_35 -> V_137 ;
V_89:
if ( F_68 ( V_76 , & V_134 , sizeof( V_134 ) ) )
return - V_79 ;
return 0 ;
}
static int F_83 ( struct V_143 * V_144 ,
unsigned int * V_145 )
{
if ( V_144 -> V_146 < 1 )
return - V_56 ;
switch ( V_145 [ 0 ] ) {
case V_147 :
case V_148 :
case V_149 :
case V_150 :
if ( V_144 -> V_146 == 1 )
return 0 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
if ( V_144 -> V_146 == 2 )
return 0 ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_144 -> V_146 == 3 )
return 0 ;
break;
case V_174 :
case V_175 :
if ( V_144 -> V_146 == 5 )
return 0 ;
break;
case V_176 :
if ( V_144 -> V_146 == 6 )
return 0 ;
break;
default:
F_84 ( L_8 ,
V_145 [ 0 ] ) ;
F_84 ( L_9 ,
V_177 , __FILE__ ) ;
F_84 ( L_10 , V_144 -> V_146 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_143 * V_144 ,
unsigned int * V_145 , void * V_91 )
{
struct V_21 * V_22 ;
int V_71 = 0 ;
int V_15 ;
if ( V_144 -> V_144 & V_178 ) {
switch ( V_144 -> V_144 ) {
case V_179 :
{
struct V_180 V_181 ;
if ( V_144 -> V_146 != 2 ) {
V_71 = - V_56 ;
break;
}
F_86 ( & V_181 ) ;
V_145 [ 0 ] = V_181 . V_182 ;
V_145 [ 1 ] = V_181 . V_183 ;
V_71 = 2 ;
break;
}
case V_184 :
if ( V_144 -> V_146 != 1 || V_145 [ 0 ] >= 100000 ) {
V_71 = - V_56 ;
break;
}
F_87 ( V_145 [ 0 ] / 1000 ) ;
V_71 = 1 ;
break;
case V_185 :
if ( V_144 -> V_146 != 1 ) {
V_71 = - V_56 ;
break;
}
if ( V_144 -> V_129 >= V_2 -> V_73 ) {
F_33 ( V_2 -> V_9 ,
L_11 ,
V_144 -> V_129 ) ;
V_71 = - V_56 ;
break;
}
V_22 = & V_2 -> V_74 [ V_144 -> V_129 ] ;
if ( ! V_22 -> V_35 ) {
F_33 ( V_2 -> V_9 , L_12 ) ;
V_71 = - V_56 ;
break;
}
if ( ! V_22 -> V_35 -> V_67 ) {
F_33 ( V_2 -> V_9 , L_13 ) ;
V_71 = - V_186 ;
break;
}
V_71 = V_22 -> V_35 -> V_67 ( V_2 , V_22 , V_145 [ 0 ] ) ;
if ( V_71 >= 0 )
V_71 = 1 ;
break;
default:
F_33 ( V_2 -> V_9 , L_14 ) ;
V_71 = - V_56 ;
break;
}
} else {
unsigned int V_108 ;
if ( V_144 -> V_129 >= V_2 -> V_73 ) {
F_33 ( V_2 -> V_9 , L_15 ,
V_144 -> V_129 ) ;
V_71 = - V_56 ;
goto V_187;
}
V_22 = & V_2 -> V_74 [ V_144 -> V_129 ] ;
if ( V_22 -> type == V_188 ) {
F_33 ( V_2 -> V_9 , L_11 ,
V_144 -> V_129 ) ;
V_71 = - V_189 ;
goto V_187;
}
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 ) {
F_33 ( V_2 -> V_9 , L_16 ) ;
V_71 = - V_135 ;
goto V_187;
}
V_71 = F_88 ( V_22 , 1 , & V_144 -> V_190 ) ;
if ( V_71 < 0 ) {
V_71 = - V_56 ;
F_33 ( V_2 -> V_9 , L_17 ) ;
goto V_187;
}
if ( V_22 -> V_39 ) {
V_71 = - V_40 ;
goto V_187;
}
V_22 -> V_39 = & F_85 ;
switch ( V_144 -> V_144 ) {
case V_191 :
V_71 = V_22 -> V_192 ( V_2 , V_22 , V_144 , V_145 ) ;
if ( V_71 == - V_193 ) {
F_33 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_44 ) ;
}
break;
case V_194 :
V_108 = V_22 -> V_117
? V_22 -> V_117 [ F_89 ( V_144 -> V_190 ) ]
: V_22 -> V_108 ;
for ( V_15 = 0 ; V_15 < V_144 -> V_146 ; ++ V_15 ) {
if ( V_145 [ V_15 ] > V_108 ) {
V_71 = - V_56 ;
F_33 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_71 == 0 ) {
V_71 = V_22 -> V_195 ( V_2 , V_22 , V_144 , V_145 ) ;
if ( V_71 == - V_193 ) {
F_33 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_44 ) ;
}
}
break;
case V_196 :
if ( V_144 -> V_146 != 2 ) {
V_71 = - V_56 ;
} else {
unsigned int V_197 ;
unsigned int V_198 ;
V_198 = V_145 [ 0 ] ;
if ( V_22 -> V_103 <= 32 ) {
V_197 = F_89 ( V_144 -> V_190 ) ;
if ( V_197 > 0 ) {
V_144 -> V_190 = 0 ;
V_145 [ 0 ] <<= V_197 ;
V_145 [ 1 ] <<= V_197 ;
}
} else
V_197 = 0 ;
V_71 = V_22 -> V_123 ( V_2 , V_22 , V_144 , V_145 ) ;
V_145 [ 0 ] = V_198 ;
if ( V_197 > 0 )
V_145 [ 1 ] >>= V_197 ;
}
break;
case V_199 :
V_71 = F_83 ( V_144 , V_145 ) ;
if ( V_71 )
break;
V_71 = V_22 -> V_200 ( V_2 , V_22 , V_144 , V_145 ) ;
break;
default:
V_71 = - V_56 ;
break;
}
V_22 -> V_39 = NULL ;
}
V_187:
return V_71 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_201 T_3 * V_76 , void * V_91 )
{
struct V_201 V_202 ;
struct V_143 * V_203 = NULL ;
unsigned int * V_145 = NULL ;
int V_15 = 0 ;
int V_71 = 0 ;
if ( F_64 ( & V_202 , V_76 , sizeof( V_202 ) ) )
return - V_79 ;
V_145 = F_91 ( sizeof( unsigned int ) * V_204 , V_65 ) ;
if ( ! V_145 ) {
V_71 = - V_102 ;
goto error;
}
V_203 = F_74 ( V_202 . V_205 , sizeof( * V_203 ) , V_65 ) ;
if ( ! V_203 ) {
V_71 = - V_102 ;
goto error;
}
if ( F_64 ( V_203 , V_202 . V_203 ,
sizeof( * V_203 ) * V_202 . V_205 ) ) {
F_33 ( V_2 -> V_9 , L_21 ) ;
V_71 = - V_79 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_202 . V_205 ; V_15 ++ ) {
if ( V_203 [ V_15 ] . V_146 > V_204 ) {
F_33 ( V_2 -> V_9 ,
L_22 ) ;
V_71 = - V_56 ;
goto error;
}
if ( V_203 [ V_15 ] . V_144 & V_206 ) {
if ( F_64 ( V_145 , V_203 [ V_15 ] . V_145 ,
V_203 [ V_15 ] . V_146 * sizeof( unsigned int ) ) ) {
F_33 ( V_2 -> V_9 ,
L_21 ) ;
V_71 = - V_79 ;
goto error;
}
}
V_71 = F_85 ( V_2 , V_203 + V_15 , V_145 , V_91 ) ;
if ( V_71 < 0 )
goto error;
if ( V_203 [ V_15 ] . V_144 & V_207 ) {
if ( F_68 ( V_203 [ V_15 ] . V_145 , V_145 ,
V_203 [ V_15 ] . V_146 * sizeof( unsigned int ) ) ) {
F_33 ( V_2 -> V_9 ,
L_23 ) ;
V_71 = - V_79 ;
goto error;
}
}
if ( F_92 () )
F_93 () ;
}
error:
F_10 ( V_203 ) ;
F_10 ( V_145 ) ;
if ( V_71 < 0 )
return V_71 ;
return V_15 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_143 T_3 * V_76 , void * V_91 )
{
struct V_143 V_144 ;
unsigned int * V_145 = NULL ;
int V_71 = 0 ;
V_145 = F_91 ( sizeof( unsigned int ) * V_204 , V_65 ) ;
if ( ! V_145 ) {
V_71 = - V_102 ;
goto error;
}
if ( F_64 ( & V_144 , V_76 , sizeof( V_144 ) ) ) {
V_71 = - V_79 ;
goto error;
}
if ( V_144 . V_146 > V_204 )
V_144 . V_146 = V_204 ;
if ( V_144 . V_144 & V_206 ) {
if ( F_64 ( V_145 ,
V_144 . V_145 ,
V_144 . V_146 * sizeof( unsigned int ) ) ) {
V_71 = - V_79 ;
goto error;
}
}
V_71 = F_85 ( V_2 , & V_144 , V_145 , V_91 ) ;
if ( V_71 < 0 )
goto error;
if ( V_144 . V_144 & V_207 ) {
if ( F_68 ( V_144 . V_145 ,
V_145 ,
V_144 . V_146 * sizeof( unsigned int ) ) ) {
V_71 = - V_79 ;
goto error;
}
}
V_71 = V_144 . V_146 ;
error:
F_10 ( V_145 ) ;
return V_71 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_208 T_3 * V_76 ,
struct V_208 * V_68 )
{
struct V_21 * V_22 ;
if ( F_64 ( V_68 , V_76 , sizeof( * V_68 ) ) ) {
F_33 ( V_2 -> V_9 , L_24 ) ;
return - V_79 ;
}
if ( V_68 -> V_129 >= V_2 -> V_73 ) {
F_33 ( V_2 -> V_9 , L_25 , V_68 -> V_129 ) ;
return - V_52 ;
}
V_22 = & V_2 -> V_74 [ V_68 -> V_129 ] ;
if ( V_22 -> type == V_188 ) {
F_33 ( V_2 -> V_9 , L_26 ,
V_68 -> V_129 ) ;
return - V_189 ;
}
if ( ! V_22 -> V_121 || ! V_22 -> V_209 || ! V_22 -> V_35 ) {
F_33 ( V_2 -> V_9 ,
L_27 ,
V_68 -> V_129 ) ;
return - V_189 ;
}
if ( V_68 -> V_210 > V_22 -> V_107 ) {
F_33 ( V_2 -> V_9 , L_28 ,
V_68 -> V_210 , V_22 -> V_107 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_211 ,
struct V_208 * V_68 )
{
unsigned int * V_69 ;
int V_71 ;
if ( ! V_211 )
return 0 ;
V_69 = F_97 ( V_211 ,
V_68 -> V_210 * sizeof( unsigned int ) ) ;
if ( F_98 ( V_69 ) )
return F_99 ( V_69 ) ;
V_71 = F_88 ( V_22 , V_68 -> V_210 , V_69 ) ;
if ( V_71 < 0 ) {
F_10 ( V_69 ) ;
return V_71 ;
}
V_68 -> V_69 = V_69 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_208 T_3 * V_76 , void * V_91 )
{
struct V_208 V_68 ;
struct V_21 * V_22 ;
struct V_34 * V_35 ;
unsigned int T_3 * V_211 ;
int V_71 ;
V_71 = F_95 ( V_2 , V_76 , & V_68 ) ;
if ( V_71 )
return V_71 ;
V_211 = ( unsigned int T_3 * ) V_68 . V_69 ;
V_22 = & V_2 -> V_74 [ V_68 . V_129 ] ;
V_35 = V_22 -> V_35 ;
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 ) {
F_33 ( V_2 -> V_9 , L_29 ) ;
return - V_135 ;
}
if ( V_22 -> V_39 ) {
F_33 ( V_2 -> V_9 , L_30 ) ;
return - V_40 ;
}
if ( V_68 . V_210 < 1 ) {
F_33 ( V_2 -> V_9 , L_31 ,
V_68 . V_210 ) ;
return - V_56 ;
}
V_35 -> V_68 = V_68 ;
V_35 -> V_68 . V_145 = NULL ;
V_71 = F_96 ( V_2 , V_22 , V_211 , & V_35 -> V_68 ) ;
if ( V_71 )
goto V_212;
V_71 = V_22 -> V_209 ( V_2 , V_22 , & V_35 -> V_68 ) ;
if ( V_35 -> V_68 . V_59 & V_213 || V_71 ) {
F_33 ( V_2 -> V_9 , L_32 , V_71 ) ;
V_68 = V_35 -> V_68 ;
V_68 . V_69 = ( unsigned int V_214 * ) V_211 ;
V_68 . V_145 = NULL ;
if ( F_68 ( V_76 , & V_68 , sizeof( V_68 ) ) ) {
F_33 ( V_2 -> V_9 , L_33 ) ;
V_71 = - V_79 ;
goto V_212;
}
V_71 = - V_186 ;
goto V_212;
}
if ( ! V_35 -> V_45 ) {
V_71 = - V_102 ;
F_33 ( V_2 -> V_9 , L_34 ) ;
goto V_212;
}
F_56 ( V_22 ) ;
V_35 -> V_215 =
V_216 | V_217 | V_218 |
V_219 ;
if ( V_35 -> V_68 . V_59 & V_220 )
V_35 -> V_215 |= V_221 ;
F_46 ( V_22 , V_63 | V_62 , V_62 ) ;
V_22 -> V_39 = V_91 ;
V_71 = V_22 -> V_121 ( V_2 , V_22 ) ;
if ( V_71 == 0 )
return 0 ;
V_212:
F_55 ( V_2 , V_22 ) ;
return V_71 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_208 T_3 * V_76 , void * V_91 )
{
struct V_208 V_68 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_211 ;
int V_71 ;
V_71 = F_95 ( V_2 , V_76 , & V_68 ) ;
if ( V_71 )
return V_71 ;
V_211 = ( unsigned int T_3 * ) V_68 . V_69 ;
V_22 = & V_2 -> V_74 [ V_68 . V_129 ] ;
V_71 = F_96 ( V_2 , V_22 , V_211 , & V_68 ) ;
if ( V_71 )
return V_71 ;
V_71 = V_22 -> V_209 ( V_2 , V_22 , & V_68 ) ;
V_68 . V_69 = ( unsigned int V_214 * ) V_211 ;
if ( F_68 ( V_76 , & V_68 , sizeof( V_68 ) ) ) {
F_33 ( V_2 -> V_9 , L_24 ) ;
V_71 = - V_79 ;
}
return V_71 ;
}
static int F_102 ( struct V_1 * V_2 , unsigned int V_76 ,
void * V_91 )
{
int V_71 = 0 ;
unsigned long V_59 ;
struct V_21 * V_22 ;
if ( V_76 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_76 ] ;
F_47 ( & V_22 -> V_60 , V_59 ) ;
if ( V_22 -> V_39 || V_22 -> V_114 )
V_71 = - V_40 ;
else
V_22 -> V_114 = V_91 ;
F_48 ( & V_22 -> V_60 , V_59 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_71 ;
}
static int F_103 ( struct V_1 * V_2 , unsigned int V_76 ,
void * V_91 )
{
struct V_21 * V_22 ;
if ( V_76 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_76 ] ;
if ( V_22 -> V_39 )
return - V_40 ;
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 )
return - V_135 ;
if ( V_22 -> V_114 == V_91 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_22 -> V_114 = NULL ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , unsigned int V_76 ,
void * V_91 )
{
struct V_21 * V_22 ;
int V_71 ;
if ( V_76 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_76 ] ;
if ( V_22 -> V_35 == NULL )
return - V_56 ;
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 )
return - V_135 ;
if ( ! V_22 -> V_39 )
return 0 ;
if ( V_22 -> V_39 != V_91 )
return - V_40 ;
V_71 = F_59 ( V_2 , V_22 ) ;
return V_71 ;
}
static int F_105 ( struct V_1 * V_2 , unsigned int V_76 ,
void * V_91 )
{
struct V_21 * V_22 ;
if ( V_76 >= V_2 -> V_73 )
return - V_56 ;
V_22 = & V_2 -> V_74 [ V_76 ] ;
if ( V_22 -> V_114 && V_22 -> V_114 != V_91 )
return - V_135 ;
if ( ! V_22 -> V_39 )
return 0 ;
if ( V_22 -> V_39 != V_91 )
return - V_40 ;
if ( V_22 -> V_222 )
return V_22 -> V_222 ( V_2 , V_22 ) ;
return - V_56 ;
}
static long F_106 ( struct V_91 * V_91 , unsigned int V_68 ,
unsigned long V_76 )
{
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_1 * V_2 = V_91 -> V_223 ;
int V_224 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_68 == V_225 ) {
if ( V_7 >= V_23 ) {
V_224 = - V_226 ;
goto V_227;
}
V_224 = F_62 ( V_2 ,
(struct V_75 T_3 * ) V_76 ) ;
if ( V_224 == 0 ) {
if ( V_76 == 0 &&
V_2 -> V_7 >= V_84 ) {
if ( F_20 ( V_2 ) ) {
F_19 ( & V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return V_224 ;
}
}
}
goto V_227;
}
if ( ! V_2 -> V_12 ) {
F_33 ( V_2 -> V_9 , L_35 ) ;
V_224 = - V_52 ;
goto V_227;
}
switch ( V_68 ) {
case V_228 :
V_224 = F_67 ( V_2 ,
(struct V_85 T_3 * ) V_76 ) ;
break;
case V_229 :
V_224 = F_69 ( V_2 , (struct V_90 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_230 :
V_224 = F_73 ( V_2 ,
(struct V_99 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_231 :
V_224 = F_76 ( V_2 , ( void T_3 * ) V_76 ) ;
break;
case V_232 :
V_224 = F_107 ( V_2 , ( void T_3 * ) V_76 ) ;
break;
case V_233 :
V_224 = F_78 ( V_2 ,
(struct V_133 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_234 :
V_224 = F_102 ( V_2 , V_76 , V_91 ) ;
break;
case V_235 :
V_224 = F_103 ( V_2 , V_76 , V_91 ) ;
break;
case V_236 :
V_224 = F_104 ( V_2 , V_76 , V_91 ) ;
break;
case V_237 :
V_224 = F_100 ( V_2 , (struct V_208 T_3 * ) V_76 , V_91 ) ;
break;
case V_238 :
V_224 = F_101 ( V_2 , (struct V_208 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_239 :
V_224 = F_90 ( V_2 ,
(struct V_201 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_240 :
V_224 = F_94 ( V_2 , (struct V_143 T_3 * ) V_76 ,
V_91 ) ;
break;
case V_241 :
V_224 = F_105 ( V_2 , V_76 , V_91 ) ;
break;
default:
V_224 = - V_226 ;
break;
}
V_227:
F_19 ( & V_2 -> V_5 ) ;
return V_224 ;
}
static void F_108 ( struct V_242 * V_243 )
{
struct V_244 * V_245 ;
V_245 = V_243 -> V_246 ;
F_109 ( V_245 ) ;
}
static void F_110 ( struct V_242 * V_243 )
{
struct V_244 * V_245 ;
V_245 = V_243 -> V_246 ;
F_111 ( V_245 ) ;
}
static int F_112 ( struct V_91 * V_91 , struct V_242 * V_247 )
{
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_1 * V_2 = V_91 -> V_223 ;
struct V_21 * V_22 ;
struct V_34 * V_35 ;
struct V_244 * V_245 = NULL ;
unsigned long V_248 = V_247 -> V_249 ;
unsigned long V_51 ;
int V_250 ;
int V_15 ;
int V_36 ;
if ( ! F_113 ( & V_2 -> V_6 ) )
return - V_186 ;
if ( ! V_2 -> V_12 ) {
F_33 ( V_2 -> V_9 , L_35 ) ;
V_36 = - V_52 ;
goto V_227;
}
if ( V_247 -> V_251 & V_252 )
V_22 = F_31 ( V_2 , V_7 ) ;
else
V_22 = F_30 ( V_2 , V_7 ) ;
if ( ! V_22 ) {
V_36 = - V_56 ;
goto V_227;
}
V_35 = V_22 -> V_35 ;
if ( ! V_35 ) {
V_36 = - V_56 ;
goto V_227;
}
if ( V_247 -> V_253 != 0 ) {
F_33 ( V_2 -> V_9 , L_36 ) ;
V_36 = - V_56 ;
goto V_227;
}
V_51 = V_247 -> V_254 - V_247 -> V_249 ;
if ( V_51 > V_35 -> V_45 ) {
V_36 = - V_79 ;
goto V_227;
}
if ( V_51 & ( ~ V_42 ) ) {
V_36 = - V_79 ;
goto V_227;
}
V_250 = V_51 >> V_255 ;
V_245 = F_114 ( V_22 ) ;
if ( ! V_245 || V_250 > V_245 -> V_250 ) {
V_36 = - V_56 ;
goto V_227;
}
for ( V_15 = 0 ; V_15 < V_250 ; ++ V_15 ) {
struct V_256 * V_49 = & V_245 -> V_257 [ V_15 ] ;
if ( F_115 ( V_247 , V_248 ,
F_116 ( F_117 ( V_49 -> V_258 ) ) ,
V_41 , V_259 ) ) {
V_36 = - V_186 ;
goto V_227;
}
V_248 += V_41 ;
}
V_247 -> V_260 = & V_261 ;
V_247 -> V_246 = V_245 ;
V_247 -> V_260 -> V_262 ( V_247 ) ;
V_36 = 0 ;
V_227:
F_118 ( & V_2 -> V_6 ) ;
F_111 ( V_245 ) ;
return V_36 ;
}
static unsigned int F_119 ( struct V_91 * V_91 , T_4 * V_263 )
{
unsigned int V_57 = 0 ;
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_1 * V_2 = V_91 -> V_223 ;
struct V_21 * V_22 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 ) {
F_33 ( V_2 -> V_9 , L_35 ) ;
goto V_227;
}
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && V_22 -> V_35 ) {
F_120 ( V_91 , & V_22 -> V_35 -> V_70 , V_263 ) ;
if ( ! V_22 -> V_39 || ! F_50 ( V_22 ) ||
F_121 ( V_22 ) > 0 )
V_57 |= V_264 | V_265 ;
}
V_22 = F_31 ( V_2 , V_7 ) ;
if ( V_22 && V_22 -> V_35 ) {
unsigned int V_266 = F_122 ( V_22 ) ;
F_120 ( V_91 , & V_22 -> V_35 -> V_70 , V_263 ) ;
F_81 ( V_22 , V_22 -> V_35 -> V_45 ) ;
if ( ! V_22 -> V_39 || ! F_50 ( V_22 ) ||
F_123 ( V_22 ) >= V_266 )
V_57 |= V_267 | V_268 ;
}
V_227:
F_19 ( & V_2 -> V_5 ) ;
return V_57 ;
}
static T_1 F_124 ( struct V_91 * V_91 , const char T_3 * V_49 ,
T_2 V_269 , T_5 * V_270 )
{
struct V_21 * V_22 ;
struct V_34 * V_35 ;
int V_146 , V_271 , V_53 = 0 , V_36 = 0 ;
F_125 ( V_263 , V_272 ) ;
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_1 * V_2 = V_91 -> V_223 ;
bool V_273 = false ;
bool V_274 ;
unsigned int V_275 ;
F_126 ( & V_2 -> V_6 ) ;
V_274 = true ;
V_275 = V_2 -> V_276 ;
if ( ! V_2 -> V_12 ) {
F_33 ( V_2 -> V_9 , L_35 ) ;
V_36 = - V_52 ;
goto V_187;
}
V_22 = F_31 ( V_2 , V_7 ) ;
if ( ! V_22 || ! V_22 -> V_35 ) {
V_36 = - V_189 ;
goto V_187;
}
V_35 = V_22 -> V_35 ;
if ( ! V_22 -> V_39 || ! V_269 )
goto V_187;
if ( V_22 -> V_39 != V_91 ) {
V_36 = - V_135 ;
goto V_187;
}
F_127 ( & V_35 -> V_70 , & V_263 ) ;
V_273 = true ;
while ( V_269 > 0 && ! V_36 ) {
F_128 ( V_277 ) ;
if ( ! F_50 ( V_22 ) ) {
if ( V_53 == 0 ) {
struct V_21 * V_278 ;
if ( F_51 ( V_22 ) )
V_36 = - V_279 ;
else
V_36 = 0 ;
F_129 ( & V_35 -> V_70 , & V_263 ) ;
V_273 = false ;
F_118 ( & V_2 -> V_6 ) ;
V_274 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_278 = F_31 ( V_2 , V_7 ) ;
if ( V_2 -> V_12 &&
V_275 == V_2 -> V_276 &&
V_22 == V_278 && V_278 -> V_35 == V_35 )
F_55 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
break;
}
V_146 = V_269 ;
V_271 = V_146 ;
if ( V_35 -> V_136 + V_271 > V_35 -> V_45 )
V_271 = V_35 -> V_45 - V_35 -> V_136 ;
F_81 ( V_22 , V_35 -> V_45 ) ;
if ( V_271 > F_123 ( V_22 ) )
V_271 = F_123 ( V_22 ) ;
if ( V_271 < V_146 )
V_146 = V_271 ;
if ( V_146 == 0 ) {
if ( V_91 -> V_280 & V_281 ) {
V_36 = - V_186 ;
break;
}
F_93 () ;
if ( F_130 ( V_272 ) ) {
V_36 = - V_282 ;
break;
}
if ( ! V_22 -> V_39 )
break;
if ( V_22 -> V_39 != V_91 ) {
V_36 = - V_135 ;
break;
}
continue;
}
V_271 = F_64 ( V_35 -> V_283 + V_35 -> V_136 ,
V_49 , V_146 ) ;
if ( V_271 ) {
V_146 -= V_271 ;
V_36 = - V_79 ;
}
F_82 ( V_22 , V_146 ) ;
V_53 += V_146 ;
V_269 -= V_146 ;
V_49 += V_146 ;
break;
}
V_187:
if ( V_273 )
F_129 ( & V_35 -> V_70 , & V_263 ) ;
F_128 ( V_284 ) ;
if ( V_274 )
F_118 ( & V_2 -> V_6 ) ;
return V_53 ? V_53 : V_36 ;
}
static T_1 F_131 ( struct V_91 * V_91 , char T_3 * V_49 , T_2 V_269 ,
T_5 * V_270 )
{
struct V_21 * V_22 ;
struct V_34 * V_35 ;
int V_146 , V_271 , V_53 = 0 , V_36 = 0 ;
F_125 ( V_263 , V_272 ) ;
const unsigned V_7 = F_70 ( F_71 ( V_91 ) ) ;
struct V_1 * V_2 = V_91 -> V_223 ;
unsigned int V_275 ;
bool V_285 = false ;
bool V_274 ;
F_126 ( & V_2 -> V_6 ) ;
V_274 = true ;
V_275 = V_2 -> V_276 ;
if ( ! V_2 -> V_12 ) {
F_33 ( V_2 -> V_9 , L_35 ) ;
V_36 = - V_52 ;
goto V_187;
}
V_22 = F_30 ( V_2 , V_7 ) ;
if ( ! V_22 || ! V_22 -> V_35 ) {
V_36 = - V_189 ;
goto V_187;
}
V_35 = V_22 -> V_35 ;
if ( ! V_22 -> V_39 || ! V_269 )
goto V_187;
if ( V_22 -> V_39 != V_91 ) {
V_36 = - V_135 ;
goto V_187;
}
F_127 ( & V_35 -> V_70 , & V_263 ) ;
while ( V_269 > 0 && ! V_36 ) {
F_128 ( V_277 ) ;
V_146 = V_269 ;
V_271 = F_121 ( V_22 ) ;
if ( V_35 -> V_137 + V_271 > V_35 -> V_45 )
V_271 = V_35 -> V_45 - V_35 -> V_137 ;
if ( V_271 < V_146 )
V_146 = V_271 ;
if ( V_146 == 0 ) {
if ( ! F_50 ( V_22 ) ) {
if ( F_51 ( V_22 ) )
V_36 = - V_279 ;
else
V_36 = 0 ;
V_285 = true ;
break;
}
if ( V_91 -> V_280 & V_281 ) {
V_36 = - V_186 ;
break;
}
F_93 () ;
if ( F_130 ( V_272 ) ) {
V_36 = - V_282 ;
break;
}
if ( ! V_22 -> V_39 ) {
V_36 = 0 ;
break;
}
if ( V_22 -> V_39 != V_91 ) {
V_36 = - V_135 ;
break;
}
continue;
}
V_271 = F_68 ( V_49 , V_35 -> V_283 +
V_35 -> V_137 , V_146 ) ;
if ( V_271 ) {
V_146 -= V_271 ;
V_36 = - V_79 ;
}
F_79 ( V_22 , V_146 ) ;
F_80 ( V_22 , V_146 ) ;
V_53 += V_146 ;
V_269 -= V_146 ;
V_49 += V_146 ;
break;
}
F_129 ( & V_35 -> V_70 , & V_263 ) ;
F_128 ( V_284 ) ;
if ( V_285 || F_52 ( V_22 ) ) {
struct V_21 * V_278 ;
F_118 ( & V_2 -> V_6 ) ;
V_274 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_278 = F_30 ( V_2 , V_7 ) ;
if ( V_2 -> V_12 && V_275 == V_2 -> V_276 &&
V_22 == V_278 && V_278 -> V_35 == V_35 ) {
if ( V_285 ||
V_35 -> V_139 - V_35 -> V_138 == 0 )
F_55 ( V_2 , V_22 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
V_187:
if ( V_274 )
F_118 ( & V_2 -> V_6 ) ;
return V_53 ? V_53 : V_36 ;
}
static int F_132 ( struct V_286 * V_286 , struct V_91 * V_91 )
{
const unsigned V_7 = F_70 ( V_286 ) ;
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_224 ;
if ( ! V_2 ) {
F_133 ( L_37 ) ;
return - V_52 ;
}
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_63 ( V_287 ) ) {
F_33 ( V_2 -> V_9 , L_38 ) ;
V_224 = - V_52 ;
goto V_187;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_134 ( V_2 -> V_13 -> V_10 ) ) {
V_224 = - V_288 ;
goto V_187;
}
if ( V_2 -> V_262 ) {
V_224 = V_2 -> V_262 ( V_2 ) ;
if ( V_224 < 0 ) {
F_18 ( V_2 -> V_13 -> V_10 ) ;
goto V_187;
}
}
}
V_2 -> V_14 ++ ;
V_91 -> V_223 = V_2 ;
V_224 = 0 ;
V_187:
F_19 ( & V_2 -> V_5 ) ;
if ( V_224 )
F_11 ( V_2 ) ;
return V_224 ;
}
static int F_135 ( int V_289 , struct V_91 * V_91 , int V_290 )
{
struct V_1 * V_2 = V_91 -> V_223 ;
return F_136 ( V_289 , V_91 , V_290 , & V_2 -> V_291 ) ;
}
static int F_137 ( struct V_286 * V_286 , struct V_91 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_223 ;
struct V_21 * V_22 = NULL ;
int V_15 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_74 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_73 ; V_15 ++ ) {
V_22 = & V_2 -> V_74 [ V_15 ] ;
if ( V_22 -> V_39 == V_91 )
F_59 ( V_2 , V_22 ) ;
if ( V_22 -> V_114 == V_91 )
V_22 -> V_114 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_292 )
V_2 -> V_292 ( V_2 ) ;
F_18 ( V_2 -> V_13 -> V_10 ) ;
}
V_2 -> V_14 -- ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_138 ( const struct V_1 * V_2 , const char * V_22 )
{
F_58 ( V_2 -> V_9 , L_39 , V_2 -> V_13 -> V_96 , V_22 ) ;
}
void F_139 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_22 -> V_35 ;
unsigned V_61 = 0 ;
unsigned V_293 = 0 ;
if ( ! F_50 ( V_22 ) )
return;
if ( V_22 ->
V_35 -> V_294 & ( V_216 | V_218 |
V_219 ) ) {
V_293 |= V_62 ;
}
if ( V_22 -> V_35 -> V_294 & ( V_218 | V_219 ) ) {
V_293 |= V_63 ;
V_61 |= V_63 ;
}
if ( V_293 ) {
F_46 ( V_22 , V_293 , V_61 ) ;
}
if ( V_35 -> V_215 & V_22 -> V_35 -> V_294 ) {
F_140 ( & V_35 -> V_70 ) ;
if ( V_22 -> V_28 & V_29 )
F_141 ( & V_2 -> V_291 , V_295 , V_296 ) ;
if ( V_22 -> V_28 & V_31 )
F_141 ( & V_2 -> V_291 , V_295 , V_297 ) ;
}
V_22 -> V_35 -> V_294 = 0 ;
}
struct V_1 * F_142 ( struct V_27 * V_298 )
{
struct V_1 * V_2 ;
struct V_27 * V_46 ;
unsigned V_15 ;
V_2 = F_54 ( sizeof( struct V_1 ) , V_65 ) ;
if ( V_2 == NULL )
return F_143 ( - V_102 ) ;
F_1 ( V_2 ) ;
F_144 ( V_2 , V_298 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_298 ? V_84 : 0 ;
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
F_145 ( L_40 ) ;
return F_143 ( - V_40 ) ;
}
V_2 -> V_7 = V_15 ;
V_46 = F_146 ( V_19 , V_298 ,
F_24 ( V_20 , V_15 ) , NULL , L_41 , V_15 ) ;
if ( ! F_98 ( V_46 ) )
V_2 -> V_9 = F_147 ( V_46 ) ;
return V_2 ;
}
static void F_148 ( unsigned V_7 )
{
F_26 ( V_7 >= V_23 ) ;
F_22 ( F_21 ( V_7 ) ) ;
}
void F_149 ( struct V_27 * V_298 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_84 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_299 == V_298 ) {
V_18 [ V_7 ] = NULL ;
F_19 ( & V_17 ) ;
F_22 ( V_2 ) ;
break;
}
F_19 ( & V_17 ) ;
}
}
int F_150 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_27 ;
struct V_27 * V_46 ;
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
F_145 ( L_42 ) ;
return - V_40 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_46 = F_146 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_43 ,
V_2 -> V_7 , V_22 -> V_44 ) ;
if ( ! F_98 ( V_46 ) )
V_22 -> V_9 = V_46 ;
return 0 ;
}
void F_151 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( V_22 == NULL )
return;
if ( V_22 -> V_7 < 0 )
return;
F_26 ( V_22 -> V_7 >= V_300 ) ;
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
static void F_152 ( void )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ )
F_148 ( V_15 ) ;
}
static int T_6 F_153 ( void )
{
int V_15 ;
int V_36 ;
F_154 ( L_44 V_301 L_45 ) ;
if ( V_84 < 0 ||
V_84 > V_23 ) {
F_145 ( L_46 ,
V_23 ) ;
return - V_56 ;
}
V_36 = F_155 ( F_24 ( V_20 , 0 ) ,
V_300 , L_47 ) ;
if ( V_36 )
return - V_189 ;
F_156 ( & V_302 , & V_303 ) ;
V_302 . V_304 = V_305 ;
F_157 ( & V_302 . V_306 , L_47 ) ;
if ( F_158 ( & V_302 , F_24 ( V_20 , 0 ) , V_300 ) ) {
F_159 ( F_24 ( V_20 , 0 ) ,
V_300 ) ;
return - V_189 ;
}
V_19 = F_160 ( V_305 , L_47 ) ;
if ( F_98 ( V_19 ) ) {
F_145 ( L_48 ) ;
F_161 ( & V_302 ) ;
F_159 ( F_24 ( V_20 , 0 ) ,
V_300 ) ;
return F_99 ( V_19 ) ;
}
V_19 -> V_307 = V_308 ;
F_162 () ;
for ( V_15 = 0 ; V_15 < V_84 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_142 ( NULL ) ;
if ( F_98 ( V_2 ) ) {
F_152 () ;
F_161 ( & V_302 ) ;
F_159 ( F_24 ( V_20 , 0 ) ,
V_300 ) ;
return F_99 ( V_2 ) ;
} else {
F_19 ( & V_2 -> V_5 ) ;
}
}
return 0 ;
}
static void T_7 F_163 ( void )
{
int V_15 ;
F_152 () ;
for ( V_15 = 0 ; V_15 < V_23 ; ++ V_15 )
F_26 ( V_18 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_24 ; ++ V_15 )
F_26 ( V_26 [ V_15 ] ) ;
F_164 ( V_19 ) ;
F_161 ( & V_302 ) ;
F_159 ( F_24 ( V_20 , 0 ) , V_300 ) ;
F_165 () ;
}
