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
if ( ! V_2 )
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
if ( ! V_22 || ( V_22 -> V_28 & V_29 ) )
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
if ( ! V_22 || ( V_22 -> V_28 & V_31 ) )
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
if ( ! V_22 || V_22 -> V_28 & V_29 )
V_37 = V_22 ;
if ( ! V_22 || V_22 -> V_28 & V_31 )
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
unsigned V_66 )
{
V_22 -> V_67 &= ~ V_66 ;
}
static void F_54 ( struct V_21 * V_22 ,
unsigned V_66 )
{
V_22 -> V_67 |= V_66 ;
}
static void F_55 ( struct V_21 * V_22 ,
unsigned V_68 , unsigned V_66 )
{
unsigned long V_69 ;
F_56 ( & V_22 -> V_70 , V_69 ) ;
F_53 ( V_22 , V_68 ) ;
F_54 ( V_22 , V_66 & V_68 ) ;
F_57 ( & V_22 -> V_70 , V_69 ) ;
}
static unsigned F_58 ( struct V_21 * V_22 )
{
return V_22 -> V_67 ;
}
static unsigned F_59 ( struct V_21 * V_22 )
{
unsigned long V_69 ;
unsigned V_67 ;
F_56 ( & V_22 -> V_70 , V_69 ) ;
V_67 = F_58 ( V_22 ) ;
F_57 ( & V_22 -> V_70 , V_69 ) ;
return V_67 ;
}
static bool F_60 ( unsigned V_67 )
{
return V_67 & V_71 ;
}
static bool F_61 ( unsigned V_67 )
{
return V_67 & V_72 ;
}
bool F_62 ( struct V_21 * V_22 )
{
unsigned V_67 = F_59 ( V_22 ) ;
return F_60 ( V_67 ) ;
}
static bool F_63 ( struct V_21 * V_22 )
{
unsigned V_67 = F_58 ( V_22 ) ;
return F_60 ( V_67 ) ;
}
static bool F_64 ( struct V_21 * V_22 )
{
unsigned V_67 = F_59 ( V_22 ) ;
return ! ( V_67 & V_73 ) ;
}
bool F_65 ( struct V_21 * V_22 )
{
unsigned V_67 = F_58 ( V_22 ) ;
return V_67 & V_74 ;
}
void F_66 ( struct V_21 * V_22 )
{
F_54 ( V_22 , V_74 ) ;
}
void * F_67 ( struct V_21 * V_22 , T_2 V_60 )
{
V_22 -> V_75 = F_68 ( V_60 , V_76 ) ;
if ( V_22 -> V_75 )
F_66 ( V_22 ) ;
return V_22 -> V_75 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_43 * V_44 = V_22 -> V_44 ;
F_55 ( V_22 , V_71 , 0 ) ;
if ( V_44 ) {
F_70 ( V_22 ) ;
V_44 -> V_77 = NULL ;
F_10 ( V_44 -> V_78 . V_79 ) ;
V_44 -> V_78 . V_79 = NULL ;
V_22 -> V_48 = NULL ;
F_71 ( & V_44 -> V_80 ) ;
} else {
F_72 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_48 = NULL ;
}
}
static int F_73 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_81 = 0 ;
if ( F_62 ( V_22 ) && V_22 -> V_82 )
V_81 = V_22 -> V_82 ( V_2 , V_22 ) ;
F_69 ( V_2 , V_22 ) ;
return V_81 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ ) {
V_22 = & V_2 -> V_84 [ V_15 ] ;
if ( V_22 -> V_44 )
F_73 ( V_2 , V_22 ) ;
}
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ ) {
V_22 = & V_2 -> V_84 [ V_15 ] ;
if ( V_22 -> V_48 )
return 1 ;
if ( V_22 -> V_44 && F_41 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_85 T_3 * V_86 )
{
struct V_85 V_87 ;
if ( ! F_77 ( V_88 ) )
return - V_47 ;
if ( ! V_86 ) {
if ( F_75 ( V_2 ) )
return - V_49 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_78 ( & V_87 , V_86 , sizeof( V_87 ) ) )
return - V_89 ;
V_87 . V_90 [ V_91 - 1 ] = 0 ;
if ( V_87 . V_92 [ V_93 ] ) {
F_79 ( V_2 -> V_9 ,
L_6 ) ;
return - V_65 ;
}
if ( V_2 -> V_7 >= V_94 )
return - V_49 ;
return F_80 ( V_2 , & V_87 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_95 T_3 * V_86 )
{
struct V_95 V_96 ;
struct V_43 * V_44 ;
struct V_21 * V_22 ;
int V_45 = 0 ;
if ( F_78 ( & V_96 , V_86 , sizeof( V_96 ) ) )
return - V_89 ;
if ( V_96 . V_97 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_96 . V_97 ] ;
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
F_40 ( V_2 -> V_9 ,
L_7 ) ;
V_96 . V_60 = 0 ;
V_96 . V_98 = 0 ;
goto V_99;
}
if ( V_96 . V_98 ) {
if ( ! F_77 ( V_88 ) )
return - V_47 ;
V_44 -> V_46 = V_96 . V_98 ;
}
if ( V_96 . V_60 ) {
V_45 = F_39 ( V_2 , V_22 , V_96 . V_60 ) ;
if ( V_45 < 0 )
return V_45 ;
}
V_96 . V_60 = V_44 -> V_54 ;
V_96 . V_98 = V_44 -> V_46 ;
V_99:
if ( F_82 ( V_86 , & V_96 , sizeof( V_96 ) ) )
return - V_89 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_100 T_3 * V_86 ,
struct V_33 * V_33 )
{
struct V_21 * V_22 ;
struct V_100 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_102 = V_103 ;
V_101 . V_104 = V_2 -> V_83 ;
F_84 ( V_101 . V_105 , V_2 -> V_13 -> V_105 , V_91 ) ;
F_84 ( V_101 . V_90 , V_2 -> V_90 , V_91 ) ;
V_22 = F_37 ( V_33 ) ;
if ( V_22 )
V_101 . V_106 = V_22 -> V_53 ;
else
V_101 . V_106 = - 1 ;
V_22 = F_38 ( V_33 ) ;
if ( V_22 )
V_101 . V_107 = V_22 -> V_53 ;
else
V_101 . V_107 = - 1 ;
if ( F_82 ( V_86 , & V_101 , sizeof( V_101 ) ) )
return - V_89 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_108 T_3 * V_86 , void * V_33 )
{
int V_81 , V_15 ;
struct V_108 * V_109 , * V_110 ;
struct V_21 * V_22 ;
V_109 = F_86 ( V_2 -> V_83 , sizeof( * V_109 ) , V_76 ) ;
if ( ! V_109 )
return - V_111 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ ) {
V_22 = & V_2 -> V_84 [ V_15 ] ;
V_110 = V_109 + V_15 ;
V_110 -> type = V_22 -> type ;
V_110 -> V_112 = V_22 -> V_112 ;
V_110 -> V_113 = V_22 -> V_28 ;
if ( F_62 ( V_22 ) )
V_110 -> V_113 |= V_114 ;
#define F_87 5
V_110 -> V_115 = F_87 ;
V_110 -> V_116 = V_22 -> V_116 ;
V_110 -> V_117 = V_22 -> V_117 ;
if ( V_22 -> V_118 ) {
V_110 -> V_119 =
( V_15 << 24 ) | ( 0 << 16 ) | ( V_22 -> V_118 -> V_120 ) ;
} else {
V_110 -> V_119 = 0 ;
}
if ( V_22 -> V_48 )
V_110 -> V_113 |= V_121 ;
if ( V_22 -> V_48 == V_33 )
V_110 -> V_113 |= V_122 ;
if ( V_22 -> V_123 )
V_110 -> V_113 |= V_124 ;
if ( V_22 -> V_123 == V_33 )
V_110 -> V_113 |= V_125 ;
if ( ! V_22 -> V_117 && V_22 -> V_126 )
V_110 -> V_113 |= V_127 ;
if ( V_22 -> V_128 )
V_110 -> V_113 |= V_129 ;
if ( V_22 -> V_130 )
V_110 -> V_113 |= V_131 ;
if ( V_22 -> V_132 != & V_133 )
V_110 -> V_134 = V_135 ;
else
V_110 -> V_134 = V_136 ;
}
V_81 = F_82 ( V_86 , V_109 , V_2 -> V_83 * sizeof( * V_109 ) ) ;
F_10 ( V_109 ) ;
return V_81 ? - V_89 : 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_137 T_3 * V_86 )
{
struct V_21 * V_22 ;
struct V_137 V_87 ;
if ( F_78 ( & V_87 , V_86 , sizeof( V_87 ) ) )
return - V_89 ;
if ( V_87 . V_138 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_87 . V_138 ] ;
if ( V_87 . V_126 ) {
if ( V_22 -> V_117 || ! V_22 -> V_126 )
return - V_65 ;
if ( F_82 ( V_87 . V_126 , V_22 -> V_126 ,
V_22 -> V_112 * sizeof( unsigned int ) ) )
return - V_89 ;
}
if ( V_87 . V_139 )
return - V_65 ;
if ( V_87 . V_140 ) {
int V_15 ;
if ( ! V_22 -> V_128 )
return - V_65 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_112 ; V_15 ++ ) {
int V_141 ;
V_141 = ( V_2 -> V_7 << 28 ) | ( V_87 . V_138 << 24 ) | ( V_15 << 16 ) |
( V_22 -> V_128 [ V_15 ] -> V_120 ) ;
if ( F_89 ( V_141 , V_87 . V_140 + V_15 ) )
return - V_89 ;
}
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_142 T_3 * V_86 , void * V_33 )
{
struct V_142 V_143 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
if ( F_78 ( & V_143 , V_86 , sizeof( V_143 ) ) )
return - V_89 ;
if ( V_143 . V_97 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_143 . V_97 ] ;
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
F_40 ( V_2 -> V_9 ,
L_7 ) ;
V_143 . V_144 = 0 ;
V_143 . V_145 = 0 ;
V_143 . V_146 = 0 ;
V_143 . V_147 = 0 ;
V_143 . V_148 = 0 ;
V_143 . V_149 = 0 ;
goto V_99;
}
if ( ! V_22 -> V_48 ) {
V_143 . V_148 = 0 ;
V_143 . V_149 = 0 ;
goto V_150;
}
if ( V_22 -> V_48 != V_33 )
return - V_151 ;
if ( V_143 . V_148 && ! ( V_44 -> V_78 . V_69 & V_152 ) ) {
V_143 . V_148 = F_91 ( V_22 , V_143 . V_148 ) ;
F_92 ( V_22 , V_143 . V_148 ) ;
if ( F_64 ( V_22 ) &&
F_93 ( V_22 ) == 0 ) {
F_69 ( V_2 , V_22 ) ;
}
}
if ( V_143 . V_149 && ( V_44 -> V_78 . V_69 & V_152 ) ) {
V_143 . V_149 =
F_94 ( V_22 , V_143 . V_149 ) ;
F_95 ( V_22 , V_143 . V_149 ) ;
}
V_150:
V_143 . V_146 = V_44 -> V_146 ;
V_143 . V_144 = V_44 -> V_144 ;
V_143 . V_147 = V_44 -> V_147 ;
V_143 . V_145 = V_44 -> V_145 ;
V_99:
if ( F_82 ( V_86 , & V_143 , sizeof( V_143 ) ) )
return - V_89 ;
return 0 ;
}
static int F_96 ( struct V_153 * V_154 ,
unsigned int * V_155 )
{
if ( V_154 -> V_156 < 1 )
return - V_65 ;
switch ( V_155 [ 0 ] ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
if ( V_154 -> V_156 == 1 )
return 0 ;
break;
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
case V_174 :
if ( V_154 -> V_156 == 2 )
return 0 ;
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( V_154 -> V_156 == 3 )
return 0 ;
break;
case V_184 :
case V_185 :
if ( V_154 -> V_156 == 5 )
return 0 ;
break;
case V_186 :
if ( V_154 -> V_156 == 6 )
return 0 ;
break;
default:
F_97 ( L_8 ,
V_155 [ 0 ] ) ;
F_97 ( L_9 , V_187 , __FILE__ ) ;
F_97 ( L_10 , V_154 -> V_156 ) ;
return 0 ;
}
return - V_65 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_153 * V_154 ,
unsigned int * V_155 , void * V_33 )
{
struct V_21 * V_22 ;
int V_81 = 0 ;
int V_15 ;
if ( V_154 -> V_154 & V_188 ) {
switch ( V_154 -> V_154 ) {
case V_189 :
{
struct V_190 V_191 ;
if ( V_154 -> V_156 != 2 ) {
V_81 = - V_65 ;
break;
}
F_99 ( & V_191 ) ;
V_155 [ 0 ] = V_191 . V_192 ;
V_155 [ 1 ] = V_191 . V_193 ;
V_81 = 2 ;
break;
}
case V_194 :
if ( V_154 -> V_156 != 1 || V_155 [ 0 ] >= 100000 ) {
V_81 = - V_65 ;
break;
}
F_100 ( V_155 [ 0 ] / 1000 ) ;
V_81 = 1 ;
break;
case V_195 :
if ( V_154 -> V_156 != 1 ) {
V_81 = - V_65 ;
break;
}
if ( V_154 -> V_138 >= V_2 -> V_83 ) {
F_40 ( V_2 -> V_9 ,
L_11 ,
V_154 -> V_138 ) ;
V_81 = - V_65 ;
break;
}
V_22 = & V_2 -> V_84 [ V_154 -> V_138 ] ;
if ( ! V_22 -> V_44 ) {
F_40 ( V_2 -> V_9 , L_12 ) ;
V_81 = - V_65 ;
break;
}
if ( ! V_22 -> V_44 -> V_77 ) {
F_40 ( V_2 -> V_9 , L_13 ) ;
V_81 = - V_196 ;
break;
}
V_81 = V_22 -> V_44 -> V_77 ( V_2 , V_22 , V_155 [ 0 ] ) ;
if ( V_81 >= 0 )
V_81 = 1 ;
break;
default:
F_40 ( V_2 -> V_9 , L_14 ) ;
V_81 = - V_65 ;
break;
}
} else {
unsigned int V_117 ;
if ( V_154 -> V_138 >= V_2 -> V_83 ) {
F_40 ( V_2 -> V_9 , L_15 ,
V_154 -> V_138 ) ;
V_81 = - V_65 ;
goto V_197;
}
V_22 = & V_2 -> V_84 [ V_154 -> V_138 ] ;
if ( V_22 -> type == V_198 ) {
F_40 ( V_2 -> V_9 , L_11 ,
V_154 -> V_138 ) ;
V_81 = - V_199 ;
goto V_197;
}
if ( V_22 -> V_123 && V_22 -> V_123 != V_33 ) {
F_40 ( V_2 -> V_9 , L_16 ) ;
V_81 = - V_151 ;
goto V_197;
}
V_81 = F_101 ( V_22 , 1 , & V_154 -> V_200 ) ;
if ( V_81 < 0 ) {
V_81 = - V_65 ;
F_40 ( V_2 -> V_9 , L_17 ) ;
goto V_197;
}
if ( V_22 -> V_48 ) {
V_81 = - V_49 ;
goto V_197;
}
V_22 -> V_48 = & F_98 ;
switch ( V_154 -> V_154 ) {
case V_201 :
V_81 = V_22 -> V_202 ( V_2 , V_22 , V_154 , V_155 ) ;
if ( V_81 == - V_203 ) {
F_40 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_53 ) ;
}
break;
case V_204 :
V_117 = V_22 -> V_126
? V_22 -> V_126 [ F_102 ( V_154 -> V_200 ) ]
: V_22 -> V_117 ;
for ( V_15 = 0 ; V_15 < V_154 -> V_156 ; ++ V_15 ) {
if ( V_155 [ V_15 ] > V_117 ) {
V_81 = - V_65 ;
F_40 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_81 == 0 ) {
V_81 = V_22 -> V_205 ( V_2 , V_22 , V_154 , V_155 ) ;
if ( V_81 == - V_203 ) {
F_40 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_53 ) ;
}
}
break;
case V_206 :
if ( V_154 -> V_156 != 2 ) {
V_81 = - V_65 ;
} else {
unsigned int V_207 = V_155 [ 0 ] ;
unsigned int V_208 = 0 ;
if ( V_22 -> V_112 <= 32 ) {
V_208 = F_102 ( V_154 -> V_200 ) ;
if ( V_208 > 0 ) {
V_154 -> V_200 = 0 ;
V_155 [ 0 ] <<= V_208 ;
V_155 [ 1 ] <<= V_208 ;
}
}
V_81 = V_22 -> V_132 ( V_2 , V_22 , V_154 , V_155 ) ;
V_155 [ 0 ] = V_207 ;
if ( V_208 > 0 )
V_155 [ 1 ] >>= V_208 ;
}
break;
case V_209 :
V_81 = F_96 ( V_154 , V_155 ) ;
if ( V_81 )
break;
V_81 = V_22 -> V_210 ( V_2 , V_22 , V_154 , V_155 ) ;
break;
default:
V_81 = - V_65 ;
break;
}
V_22 -> V_48 = NULL ;
}
V_197:
return V_81 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_211 T_3 * V_86 , void * V_33 )
{
struct V_211 V_212 ;
struct V_153 * V_213 = NULL ;
unsigned int * V_155 = NULL ;
int V_15 = 0 ;
int V_81 = 0 ;
if ( F_78 ( & V_212 , V_86 , sizeof( V_212 ) ) )
return - V_89 ;
V_155 = F_104 ( V_214 , sizeof( unsigned int ) , V_76 ) ;
if ( ! V_155 ) {
V_81 = - V_111 ;
goto error;
}
V_213 = F_86 ( V_212 . V_215 , sizeof( * V_213 ) , V_76 ) ;
if ( ! V_213 ) {
V_81 = - V_111 ;
goto error;
}
if ( F_78 ( V_213 , V_212 . V_213 ,
sizeof( * V_213 ) * V_212 . V_215 ) ) {
F_40 ( V_2 -> V_9 , L_21 ) ;
V_81 = - V_89 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_212 . V_215 ; V_15 ++ ) {
if ( V_213 [ V_15 ] . V_156 > V_214 ) {
F_40 ( V_2 -> V_9 ,
L_22 ) ;
V_81 = - V_65 ;
goto error;
}
if ( V_213 [ V_15 ] . V_154 & V_216 ) {
if ( F_78 ( V_155 , V_213 [ V_15 ] . V_155 ,
V_213 [ V_15 ] . V_156 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_21 ) ;
V_81 = - V_89 ;
goto error;
}
}
V_81 = F_98 ( V_2 , V_213 + V_15 , V_155 , V_33 ) ;
if ( V_81 < 0 )
goto error;
if ( V_213 [ V_15 ] . V_154 & V_217 ) {
if ( F_82 ( V_213 [ V_15 ] . V_155 , V_155 ,
V_213 [ V_15 ] . V_156 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_23 ) ;
V_81 = - V_89 ;
goto error;
}
}
if ( F_105 () )
F_106 () ;
}
error:
F_10 ( V_213 ) ;
F_10 ( V_155 ) ;
if ( V_81 < 0 )
return V_81 ;
return V_15 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_153 T_3 * V_86 , void * V_33 )
{
struct V_153 V_154 ;
unsigned int * V_155 = NULL ;
int V_81 = 0 ;
V_155 = F_104 ( V_214 , sizeof( unsigned int ) , V_76 ) ;
if ( ! V_155 ) {
V_81 = - V_111 ;
goto error;
}
if ( F_78 ( & V_154 , V_86 , sizeof( V_154 ) ) ) {
V_81 = - V_89 ;
goto error;
}
if ( V_154 . V_156 > V_214 )
V_154 . V_156 = V_214 ;
if ( V_154 . V_154 & V_216 ) {
if ( F_78 ( V_155 ,
V_154 . V_155 ,
V_154 . V_156 * sizeof( unsigned int ) ) ) {
V_81 = - V_89 ;
goto error;
}
}
V_81 = F_98 ( V_2 , & V_154 , V_155 , V_33 ) ;
if ( V_81 < 0 )
goto error;
if ( V_154 . V_154 & V_217 ) {
if ( F_82 ( V_154 . V_155 ,
V_155 ,
V_154 . V_156 * sizeof( unsigned int ) ) ) {
V_81 = - V_89 ;
goto error;
}
}
V_81 = V_154 . V_156 ;
error:
F_10 ( V_155 ) ;
return V_81 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_86 ,
struct V_218 * V_78 )
{
struct V_21 * V_22 ;
if ( F_78 ( V_78 , V_86 , sizeof( * V_78 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
return - V_89 ;
}
if ( V_78 -> V_138 >= V_2 -> V_83 ) {
F_40 ( V_2 -> V_9 , L_25 , V_78 -> V_138 ) ;
return - V_61 ;
}
V_22 = & V_2 -> V_84 [ V_78 -> V_138 ] ;
if ( V_22 -> type == V_198 ) {
F_40 ( V_2 -> V_9 , L_26 ,
V_78 -> V_138 ) ;
return - V_199 ;
}
if ( ! V_22 -> V_130 || ! V_22 -> V_219 || ! V_22 -> V_44 ) {
F_40 ( V_2 -> V_9 ,
L_27 ,
V_78 -> V_138 ) ;
return - V_199 ;
}
if ( V_78 -> V_220 > V_22 -> V_116 ) {
F_40 ( V_2 -> V_9 , L_28 ,
V_78 -> V_220 , V_22 -> V_116 ) ;
return - V_65 ;
}
switch ( V_22 -> V_28 & ( V_29 | V_31 ) ) {
case V_29 :
V_78 -> V_69 &= ~ V_152 ;
break;
case V_31 :
V_78 -> V_69 |= V_152 ;
break;
default:
break;
}
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_221 ,
struct V_218 * V_78 )
{
unsigned int * V_79 ;
int V_81 ;
V_78 -> V_79 = NULL ;
V_79 = F_110 ( V_221 ,
V_78 -> V_220 * sizeof( unsigned int ) ) ;
if ( F_111 ( V_79 ) )
return F_112 ( V_79 ) ;
V_81 = F_101 ( V_22 , V_78 -> V_220 , V_79 ) ;
if ( V_81 < 0 ) {
F_10 ( V_79 ) ;
return V_81 ;
}
V_78 -> V_79 = V_79 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_86 , void * V_33 )
{
struct V_218 V_78 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
unsigned int T_3 * V_221 ;
int V_81 ;
V_81 = F_108 ( V_2 , V_86 , & V_78 ) ;
if ( V_81 )
return V_81 ;
V_221 = ( unsigned int T_3 * ) V_78 . V_79 ;
V_22 = & V_2 -> V_84 [ V_78 . V_138 ] ;
V_44 = V_22 -> V_44 ;
if ( V_22 -> V_123 && V_22 -> V_123 != V_33 ) {
F_40 ( V_2 -> V_9 , L_29 ) ;
return - V_151 ;
}
if ( V_22 -> V_48 ) {
F_40 ( V_2 -> V_9 , L_30 ) ;
return - V_49 ;
}
if ( V_78 . V_220 < 1 ) {
F_40 ( V_2 -> V_9 , L_31 ,
V_78 . V_220 ) ;
return - V_65 ;
}
V_44 -> V_78 = V_78 ;
V_44 -> V_78 . V_155 = NULL ;
V_81 = F_109 ( V_2 , V_22 , V_221 , & V_44 -> V_78 ) ;
if ( V_81 )
goto V_222;
V_81 = V_22 -> V_219 ( V_2 , V_22 , & V_44 -> V_78 ) ;
if ( V_44 -> V_78 . V_69 & V_223 || V_81 ) {
F_40 ( V_2 -> V_9 , L_32 , V_81 ) ;
V_78 = V_44 -> V_78 ;
V_78 . V_79 = ( unsigned int V_224 * ) V_221 ;
V_78 . V_155 = NULL ;
if ( F_82 ( V_86 , & V_78 , sizeof( V_78 ) ) ) {
F_40 ( V_2 -> V_9 , L_33 ) ;
V_81 = - V_89 ;
goto V_222;
}
V_81 = - V_196 ;
goto V_222;
}
if ( ! V_44 -> V_54 ) {
V_81 = - V_111 ;
F_40 ( V_2 -> V_9 , L_34 ) ;
goto V_222;
}
F_70 ( V_22 ) ;
V_44 -> V_225 = V_226 | V_227 ;
if ( V_44 -> V_78 . V_69 & V_228 )
V_44 -> V_225 |= V_229 ;
F_55 ( V_22 , V_73 ,
V_71 ) ;
V_22 -> V_48 = V_33 ;
V_81 = V_22 -> V_130 ( V_2 , V_22 ) ;
if ( V_81 == 0 )
return 0 ;
V_222:
F_69 ( V_2 , V_22 ) ;
return V_81 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_86 , void * V_33 )
{
struct V_218 V_78 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_221 ;
int V_81 ;
V_81 = F_108 ( V_2 , V_86 , & V_78 ) ;
if ( V_81 )
return V_81 ;
V_221 = ( unsigned int T_3 * ) V_78 . V_79 ;
V_22 = & V_2 -> V_84 [ V_78 . V_138 ] ;
if ( V_221 ) {
V_81 = F_109 ( V_2 , V_22 , V_221 , & V_78 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = V_22 -> V_219 ( V_2 , V_22 , & V_78 ) ;
F_10 ( V_78 . V_79 ) ;
V_78 . V_79 = ( unsigned int V_224 * ) V_221 ;
if ( F_82 ( V_86 , & V_78 , sizeof( V_78 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
V_81 = - V_89 ;
}
return V_81 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned long V_86 ,
void * V_33 )
{
int V_81 = 0 ;
unsigned long V_69 ;
struct V_21 * V_22 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_86 ] ;
F_56 ( & V_22 -> V_70 , V_69 ) ;
if ( V_22 -> V_48 || V_22 -> V_123 )
V_81 = - V_49 ;
else
V_22 -> V_123 = V_33 ;
F_57 ( & V_22 -> V_70 , V_69 ) ;
return V_81 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned long V_86 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_86 ] ;
if ( V_22 -> V_48 )
return - V_49 ;
if ( V_22 -> V_123 && V_22 -> V_123 != V_33 )
return - V_151 ;
if ( V_22 -> V_123 == V_33 )
V_22 -> V_123 = NULL ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_86 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_86 ] ;
if ( ! V_22 -> V_44 )
return - V_65 ;
if ( ! V_22 -> V_48 )
return 0 ;
if ( V_22 -> V_48 != V_33 )
return - V_49 ;
return F_73 ( V_2 , V_22 ) ;
}
static int F_118 ( struct V_1 * V_2 , unsigned long V_86 ,
void * V_33 )
{
struct V_21 * V_22 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_22 = & V_2 -> V_84 [ V_86 ] ;
if ( ! V_22 -> V_48 )
return 0 ;
if ( V_22 -> V_48 != V_33 )
return - V_49 ;
if ( V_22 -> V_230 )
return V_22 -> V_230 ( V_2 , V_22 ) ;
return - V_65 ;
}
static int F_119 ( struct V_1 * V_2 , unsigned long V_86 ,
struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_21 * V_231 , * V_232 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_232 = & V_2 -> V_84 [ V_86 ] ;
V_231 = F_37 ( V_33 ) ;
if ( V_231 == V_232 )
return 0 ;
if ( ! ( V_232 -> V_28 & V_29 ) )
return - V_65 ;
if ( V_231 && V_231 -> V_48 == V_33 && V_231 -> V_44 &&
! ( V_231 -> V_44 -> V_78 . V_69 & V_152 ) )
return - V_49 ;
F_35 ( V_35 -> V_30 ) = V_232 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 , unsigned long V_86 ,
struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_21 * V_231 , * V_232 ;
if ( V_86 >= V_2 -> V_83 )
return - V_65 ;
V_232 = & V_2 -> V_84 [ V_86 ] ;
V_231 = F_38 ( V_33 ) ;
if ( V_231 == V_232 )
return 0 ;
if ( ! ( V_232 -> V_28 & V_31 ) )
return - V_65 ;
if ( V_231 && V_231 -> V_48 == V_33 && V_231 -> V_44 &&
( V_231 -> V_44 -> V_78 . V_69 & V_152 ) )
return - V_49 ;
F_35 ( V_35 -> V_32 ) = V_232 ;
return 0 ;
}
static long F_121 ( struct V_33 * V_33 , unsigned int V_78 ,
unsigned long V_86 )
{
unsigned V_7 = F_33 ( F_34 ( V_33 ) ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_233 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_78 == V_234 ) {
if ( V_7 >= V_23 ) {
V_233 = - V_235 ;
goto V_236;
}
V_233 = F_76 ( V_2 ,
(struct V_85 T_3 * ) V_86 ) ;
if ( V_233 == 0 ) {
if ( V_86 == 0 &&
V_2 -> V_7 >= V_94 ) {
if ( F_20 ( V_2 ) ) {
F_19 ( & V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return V_233 ;
}
}
}
goto V_236;
}
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_233 = - V_61 ;
goto V_236;
}
switch ( V_78 ) {
case V_237 :
V_233 = F_81 ( V_2 ,
(struct V_95 T_3 * ) V_86 ) ;
break;
case V_238 :
V_233 = F_83 ( V_2 , (struct V_100 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_239 :
V_233 = F_85 ( V_2 ,
(struct V_108 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_240 :
V_233 = F_88 ( V_2 , ( void T_3 * ) V_86 ) ;
break;
case V_241 :
V_233 = F_122 ( V_2 , ( void T_3 * ) V_86 ) ;
break;
case V_242 :
V_233 = F_90 ( V_2 ,
(struct V_142 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_243 :
V_233 = F_115 ( V_2 , V_86 , V_33 ) ;
break;
case V_244 :
V_233 = F_116 ( V_2 , V_86 , V_33 ) ;
break;
case V_245 :
V_233 = F_117 ( V_2 , V_86 , V_33 ) ;
break;
case V_246 :
V_233 = F_113 ( V_2 , (struct V_218 T_3 * ) V_86 , V_33 ) ;
break;
case V_247 :
V_233 = F_114 ( V_2 , (struct V_218 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_248 :
V_233 = F_103 ( V_2 ,
(struct V_211 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_249 :
V_233 = F_107 ( V_2 , (struct V_153 T_3 * ) V_86 ,
V_33 ) ;
break;
case V_250 :
V_233 = F_118 ( V_2 , V_86 , V_33 ) ;
break;
case V_251 :
V_233 = F_119 ( V_2 , V_86 , V_33 ) ;
break;
case V_252 :
V_233 = F_120 ( V_2 , V_86 , V_33 ) ;
break;
default:
V_233 = - V_235 ;
break;
}
V_236:
F_19 ( & V_2 -> V_5 ) ;
return V_233 ;
}
static void F_123 ( struct V_253 * V_254 )
{
struct V_255 * V_256 ;
V_256 = V_254 -> V_257 ;
F_124 ( V_256 ) ;
}
static void F_125 ( struct V_253 * V_254 )
{
struct V_255 * V_256 ;
V_256 = V_254 -> V_257 ;
F_126 ( V_256 ) ;
}
static int F_127 ( struct V_33 * V_33 , struct V_253 * V_258 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 ;
struct V_43 * V_44 ;
struct V_255 * V_256 = NULL ;
unsigned long V_259 = V_258 -> V_260 ;
unsigned long V_60 ;
int V_261 ;
int V_15 ;
int V_45 ;
if ( ! F_128 ( & V_2 -> V_6 ) )
return - V_196 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_236;
}
if ( V_258 -> V_262 & V_263 )
V_22 = F_38 ( V_33 ) ;
else
V_22 = F_37 ( V_33 ) ;
if ( ! V_22 ) {
V_45 = - V_65 ;
goto V_236;
}
V_44 = V_22 -> V_44 ;
if ( ! V_44 ) {
V_45 = - V_65 ;
goto V_236;
}
if ( V_258 -> V_264 != 0 ) {
F_40 ( V_2 -> V_9 , L_36 ) ;
V_45 = - V_65 ;
goto V_236;
}
V_60 = V_258 -> V_265 - V_258 -> V_260 ;
if ( V_60 > V_44 -> V_54 ) {
V_45 = - V_89 ;
goto V_236;
}
if ( V_60 & ( ~ V_51 ) ) {
V_45 = - V_89 ;
goto V_236;
}
V_261 = V_60 >> V_266 ;
V_256 = F_129 ( V_22 ) ;
if ( ! V_256 || V_261 > V_256 -> V_261 ) {
V_45 = - V_65 ;
goto V_236;
}
for ( V_15 = 0 ; V_15 < V_261 ; ++ V_15 ) {
struct V_267 * V_58 = & V_256 -> V_268 [ V_15 ] ;
if ( F_130 ( V_258 , V_259 ,
F_131 ( F_132 ( V_58 -> V_269 ) ) ,
V_50 , V_270 ) ) {
V_45 = - V_196 ;
goto V_236;
}
V_259 += V_50 ;
}
V_258 -> V_271 = & V_272 ;
V_258 -> V_257 = V_256 ;
V_258 -> V_271 -> V_273 ( V_258 ) ;
V_45 = 0 ;
V_236:
F_133 ( & V_2 -> V_6 ) ;
F_126 ( V_256 ) ;
return V_45 ;
}
static unsigned int F_134 ( struct V_33 * V_33 , T_4 * V_274 )
{
unsigned int V_68 = 0 ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
goto V_236;
}
V_22 = F_37 ( V_33 ) ;
if ( V_22 && V_22 -> V_44 ) {
F_135 ( V_33 , & V_22 -> V_44 -> V_80 , V_274 ) ;
if ( ! V_22 -> V_48 || ! F_62 ( V_22 ) ||
( V_22 -> V_44 -> V_78 . V_69 & V_152 ) ||
F_136 ( V_22 ) > 0 )
V_68 |= V_275 | V_276 ;
}
V_22 = F_38 ( V_33 ) ;
if ( V_22 && V_22 -> V_44 ) {
unsigned int V_277 = F_137 ( V_22 ) ;
F_135 ( V_33 , & V_22 -> V_44 -> V_80 , V_274 ) ;
F_94 ( V_22 , V_22 -> V_44 -> V_54 ) ;
if ( ! V_22 -> V_48 || ! F_62 ( V_22 ) ||
! ( V_22 -> V_44 -> V_78 . V_69 & V_152 ) ||
F_138 ( V_22 ) >= V_277 )
V_68 |= V_278 | V_279 ;
}
V_236:
F_19 ( & V_2 -> V_5 ) ;
return V_68 ;
}
static T_1 F_139 ( struct V_33 * V_33 , const char T_3 * V_58 ,
T_2 V_280 , T_5 * V_281 )
{
struct V_21 * V_22 ;
struct V_43 * V_44 ;
int V_156 , V_282 , V_62 = 0 , V_45 = 0 ;
F_140 ( V_274 , V_283 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
bool V_284 = false ;
bool V_285 ;
unsigned int V_286 ;
F_141 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_41 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_197;
}
V_22 = F_38 ( V_33 ) ;
if ( ! V_22 || ! V_22 -> V_44 ) {
V_45 = - V_199 ;
goto V_197;
}
V_44 = V_22 -> V_44 ;
if ( ! V_22 -> V_48 || ! V_280 )
goto V_197;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_151 ;
goto V_197;
}
if ( ! ( V_44 -> V_78 . V_69 & V_152 ) ) {
V_45 = - V_65 ;
goto V_197;
}
F_142 ( & V_44 -> V_80 , & V_274 ) ;
V_284 = true ;
while ( V_280 > 0 && ! V_45 ) {
unsigned V_67 ;
F_143 ( V_287 ) ;
V_67 = F_59 ( V_22 ) ;
if ( ! F_60 ( V_67 ) ) {
if ( V_62 == 0 ) {
struct V_21 * V_288 ;
if ( F_61 ( V_67 ) )
V_45 = - V_289 ;
else
V_45 = 0 ;
F_144 ( & V_44 -> V_80 , & V_274 ) ;
V_284 = false ;
F_133 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_288 = F_38 ( V_33 ) ;
if ( V_2 -> V_12 &&
V_286 == V_2 -> V_41 &&
V_22 == V_288 && V_288 -> V_44 == V_44 )
F_69 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
break;
}
V_156 = V_280 ;
V_282 = V_156 ;
if ( V_44 -> V_144 + V_282 > V_44 -> V_54 )
V_282 = V_44 -> V_54 - V_44 -> V_144 ;
F_94 ( V_22 , V_44 -> V_54 ) ;
if ( V_282 > F_138 ( V_22 ) )
V_282 = F_138 ( V_22 ) ;
if ( V_282 < V_156 )
V_156 = V_282 ;
if ( V_156 == 0 ) {
if ( V_33 -> V_290 & V_291 ) {
V_45 = - V_196 ;
break;
}
F_106 () ;
if ( F_145 ( V_283 ) ) {
V_45 = - V_292 ;
break;
}
if ( ! V_22 -> V_48 )
break;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_151 ;
break;
}
if ( ! ( V_44 -> V_78 . V_69 & V_152 ) ) {
V_45 = - V_65 ;
break;
}
continue;
}
V_282 = F_78 ( V_44 -> V_293 + V_44 -> V_144 ,
V_58 , V_156 ) ;
if ( V_282 ) {
V_156 -= V_282 ;
V_45 = - V_89 ;
}
F_95 ( V_22 , V_156 ) ;
V_62 += V_156 ;
V_280 -= V_156 ;
V_58 += V_156 ;
break;
}
V_197:
if ( V_284 )
F_144 ( & V_44 -> V_80 , & V_274 ) ;
F_143 ( V_294 ) ;
if ( V_285 )
F_133 ( & V_2 -> V_6 ) ;
return V_62 ? V_62 : V_45 ;
}
static T_1 F_146 ( struct V_33 * V_33 , char T_3 * V_58 , T_2 V_280 ,
T_5 * V_281 )
{
struct V_21 * V_22 ;
struct V_43 * V_44 ;
int V_156 , V_282 , V_62 = 0 , V_45 = 0 ;
F_140 ( V_274 , V_283 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_286 ;
bool V_295 = false ;
bool V_285 ;
F_141 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_41 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_45 = - V_61 ;
goto V_197;
}
V_22 = F_37 ( V_33 ) ;
if ( ! V_22 || ! V_22 -> V_44 ) {
V_45 = - V_199 ;
goto V_197;
}
V_44 = V_22 -> V_44 ;
if ( ! V_22 -> V_48 || ! V_280 )
goto V_197;
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_151 ;
goto V_197;
}
if ( V_44 -> V_78 . V_69 & V_152 ) {
V_45 = - V_65 ;
goto V_197;
}
F_142 ( & V_44 -> V_80 , & V_274 ) ;
while ( V_280 > 0 && ! V_45 ) {
F_143 ( V_287 ) ;
V_156 = V_280 ;
V_282 = F_136 ( V_22 ) ;
if ( V_44 -> V_145 + V_282 > V_44 -> V_54 )
V_282 = V_44 -> V_54 - V_44 -> V_145 ;
if ( V_282 < V_156 )
V_156 = V_282 ;
if ( V_156 == 0 ) {
unsigned V_67 = F_59 ( V_22 ) ;
if ( ! F_60 ( V_67 ) ) {
if ( F_61 ( V_67 ) )
V_45 = - V_289 ;
else
V_45 = 0 ;
V_295 = true ;
break;
}
if ( V_33 -> V_290 & V_291 ) {
V_45 = - V_196 ;
break;
}
F_106 () ;
if ( F_145 ( V_283 ) ) {
V_45 = - V_292 ;
break;
}
if ( ! V_22 -> V_48 ) {
V_45 = 0 ;
break;
}
if ( V_22 -> V_48 != V_33 ) {
V_45 = - V_151 ;
break;
}
if ( V_44 -> V_78 . V_69 & V_152 ) {
V_45 = - V_65 ;
break;
}
continue;
}
V_282 = F_82 ( V_58 , V_44 -> V_293 +
V_44 -> V_145 , V_156 ) ;
if ( V_282 ) {
V_156 -= V_282 ;
V_45 = - V_89 ;
}
F_91 ( V_22 , V_156 ) ;
F_92 ( V_22 , V_156 ) ;
V_62 += V_156 ;
V_280 -= V_156 ;
V_58 += V_156 ;
break;
}
F_144 ( & V_44 -> V_80 , & V_274 ) ;
F_143 ( V_294 ) ;
if ( V_295 || F_64 ( V_22 ) ) {
struct V_21 * V_288 ;
F_133 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_288 = F_37 ( V_33 ) ;
if ( V_2 -> V_12 && V_286 == V_2 -> V_41 &&
V_22 == V_288 && V_288 -> V_44 == V_44 ) {
if ( V_295 || F_93 ( V_22 ) == 0 )
F_69 ( V_2 , V_22 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
V_197:
if ( V_285 )
F_133 ( & V_2 -> V_6 ) ;
return V_62 ? V_62 : V_45 ;
}
static int F_147 ( struct V_296 * V_296 , struct V_33 * V_33 )
{
const unsigned V_7 = F_33 ( V_296 ) ;
struct V_34 * V_35 ;
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_233 ;
if ( ! V_2 ) {
F_148 ( L_37 ) ;
return - V_61 ;
}
V_35 = F_68 ( sizeof( * V_35 ) , V_76 ) ;
if ( ! V_35 )
return - V_111 ;
V_35 -> V_2 = V_2 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_77 ( V_297 ) ) {
F_40 ( V_2 -> V_9 , L_38 ) ;
V_233 = - V_61 ;
goto V_197;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_149 ( V_2 -> V_13 -> V_10 ) ) {
V_233 = - V_298 ;
goto V_197;
}
if ( V_2 -> V_273 ) {
V_233 = V_2 -> V_273 ( V_2 ) ;
if ( V_233 < 0 ) {
F_18 ( V_2 -> V_13 -> V_10 ) ;
goto V_197;
}
}
}
V_2 -> V_14 ++ ;
V_33 -> V_36 = V_35 ;
F_32 ( V_33 ) ;
V_233 = 0 ;
V_197:
F_19 ( & V_2 -> V_5 ) ;
if ( V_233 ) {
F_11 ( V_2 ) ;
F_10 ( V_35 ) ;
}
return V_233 ;
}
static int F_150 ( int V_299 , struct V_33 * V_33 , int V_300 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
return F_151 ( V_299 , V_33 , V_300 , & V_2 -> V_301 ) ;
}
static int F_152 ( struct V_296 * V_296 , struct V_33 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_21 * V_22 = NULL ;
int V_15 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_84 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ ) {
V_22 = & V_2 -> V_84 [ V_15 ] ;
if ( V_22 -> V_48 == V_33 )
F_73 ( V_2 , V_22 ) ;
if ( V_22 -> V_123 == V_33 )
V_22 -> V_123 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_302 )
V_2 -> V_302 ( V_2 ) ;
F_18 ( V_2 -> V_13 -> V_10 ) ;
}
V_2 -> V_14 -- ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
F_10 ( V_35 ) ;
return 0 ;
}
void F_153 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_43 * V_44 = V_22 -> V_44 ;
unsigned int V_303 ;
int V_304 = 0 ;
unsigned long V_69 ;
F_56 ( & V_22 -> V_70 , V_69 ) ;
V_303 = V_44 -> V_303 ;
V_44 -> V_303 = 0 ;
if ( ! F_63 ( V_22 ) ) {
F_57 ( & V_22 -> V_70 , V_69 ) ;
return;
}
if ( V_303 & V_227 )
F_53 ( V_22 , V_71 ) ;
if ( V_303 & V_305 )
F_54 ( V_22 , V_72 ) ;
if ( V_44 -> V_225 & V_303 ) {
F_154 ( & V_44 -> V_80 ) ;
V_304 = V_44 -> V_78 . V_69 & V_152 ? V_306 : V_307 ;
}
F_57 ( & V_22 -> V_70 , V_69 ) ;
if ( V_304 )
F_155 ( & V_2 -> V_301 , V_308 , V_304 ) ;
}
struct V_1 * F_156 ( struct V_27 * V_309 )
{
struct V_1 * V_2 ;
struct V_27 * V_55 ;
unsigned V_15 ;
V_2 = F_68 ( sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return F_157 ( - V_111 ) ;
F_1 ( V_2 ) ;
F_158 ( V_2 , V_309 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_309 ? V_94 : 0 ;
V_15 < V_23 ; ++ V_15 ) {
if ( ! V_18 [ V_15 ] ) {
V_18 [ V_15 ] = V_2 ;
break;
}
}
F_19 ( & V_17 ) ;
if ( V_15 == V_23 ) {
F_19 ( & V_2 -> V_5 ) ;
F_15 ( V_2 ) ;
F_11 ( V_2 ) ;
F_72 ( V_309 ,
L_39 ) ;
return F_157 ( - V_49 ) ;
}
V_2 -> V_7 = V_15 ;
V_55 = F_159 ( V_19 , V_309 ,
F_24 ( V_20 , V_15 ) , NULL , L_40 , V_15 ) ;
if ( ! F_111 ( V_55 ) )
V_2 -> V_9 = F_160 ( V_55 ) ;
return V_2 ;
}
static void F_161 ( unsigned V_7 )
{
F_26 ( V_7 >= V_23 ) ;
F_22 ( F_21 ( V_7 ) ) ;
}
void F_162 ( struct V_27 * V_309 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_94 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_310 == V_309 ) {
V_18 [ V_7 ] = NULL ;
F_19 ( & V_17 ) ;
F_22 ( V_2 ) ;
break;
}
F_19 ( & V_17 ) ;
}
}
int F_163 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_27 ;
struct V_27 * V_55 ;
unsigned V_15 ;
F_16 ( & V_25 ) ;
for ( V_15 = 0 ; V_15 < V_24 ; ++ V_15 ) {
if ( ! V_26 [ V_15 ] ) {
V_26 [ V_15 ] = V_22 ;
break;
}
}
F_19 ( & V_25 ) ;
if ( V_15 == V_24 ) {
F_72 ( V_2 -> V_9 ,
L_41 ) ;
return - V_49 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_55 = F_159 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_42 ,
V_2 -> V_7 , V_22 -> V_53 ) ;
if ( ! F_111 ( V_55 ) )
V_22 -> V_9 = V_55 ;
return 0 ;
}
void F_164 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( ! V_22 )
return;
if ( V_22 -> V_7 < 0 )
return;
F_26 ( V_22 -> V_7 >= V_311 ) ;
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
static void F_165 ( void )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ )
F_161 ( V_15 ) ;
}
static int T_6 F_166 ( void )
{
int V_15 ;
int V_45 ;
F_167 ( L_43 V_312 L_44 ) ;
if ( V_94 < 0 ||
V_94 > V_23 ) {
F_168 ( L_45 ,
V_23 ) ;
return - V_65 ;
}
V_45 = F_169 ( F_24 ( V_20 , 0 ) ,
V_311 , L_46 ) ;
if ( V_45 )
return - V_199 ;
F_170 ( & V_313 , & V_314 ) ;
V_313 . V_315 = V_316 ;
V_45 = F_171 ( & V_313 . V_317 , L_46 ) ;
if ( V_45 ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_311 ) ;
return V_45 ;
}
if ( F_173 ( & V_313 , F_24 ( V_20 , 0 ) , V_311 ) ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_311 ) ;
return - V_199 ;
}
V_19 = F_174 ( V_316 , L_46 ) ;
if ( F_111 ( V_19 ) ) {
F_168 ( L_47 ) ;
F_175 ( & V_313 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_311 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_318 = V_319 ;
F_176 () ;
for ( V_15 = 0 ; V_15 < V_94 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_156 ( NULL ) ;
if ( F_111 ( V_2 ) ) {
F_165 () ;
F_175 ( & V_313 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_311 ) ;
return F_112 ( V_2 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
return 0 ;
}
static void T_7 F_177 ( void )
{
int V_15 ;
F_165 () ;
for ( V_15 = 0 ; V_15 < V_23 ; ++ V_15 )
F_26 ( V_18 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_24 ; ++ V_15 )
F_26 ( V_26 [ V_15 ] ) ;
F_178 ( V_19 ) ;
F_175 ( & V_313 ) ;
F_172 ( F_24 ( V_20 , 0 ) , V_311 ) ;
F_179 () ;
}
