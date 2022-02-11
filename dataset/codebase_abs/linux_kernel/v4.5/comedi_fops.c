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
F_16 ( & V_24 ) ;
V_22 = V_25 [ V_15 ] ;
if ( V_22 && V_22 -> V_26 != V_2 )
V_22 = NULL ;
F_19 ( & V_24 ) ;
return V_22 ;
}
static struct V_1 * F_26 ( unsigned V_7 )
{
struct V_1 * V_2 ;
F_16 ( & V_17 ) ;
V_2 = F_13 ( V_18 [ V_7 ] ) ;
F_19 ( & V_17 ) ;
return V_2 ;
}
static struct V_1 * F_27 ( unsigned V_7 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_15 = V_7 - V_23 ;
F_16 ( & V_24 ) ;
V_22 = V_25 [ V_15 ] ;
V_2 = F_13 ( V_22 ? V_22 -> V_26 : NULL ) ;
F_19 ( & V_24 ) ;
return V_2 ;
}
struct V_1 * F_28 ( unsigned V_7 )
{
if ( V_7 < V_23 )
return F_26 ( V_7 ) ;
return F_27 ( V_7 ) ;
}
static struct V_21 *
F_29 ( const struct V_1 * V_2 , unsigned int V_7 )
{
struct V_21 * V_22 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( ! V_22 || ( V_22 -> V_27 & V_28 ) )
return V_22 ;
}
return V_2 -> V_29 ;
}
static struct V_21 *
F_30 ( const struct V_1 * V_2 , unsigned int V_7 )
{
struct V_21 * V_22 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( ! V_22 || ( V_22 -> V_27 & V_30 ) )
return V_22 ;
}
return V_2 -> V_31 ;
}
static void F_31 ( struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 , * V_36 , * V_37 ;
unsigned int V_7 = F_32 ( F_33 ( V_32 ) ) ;
V_36 = V_2 -> V_29 ;
V_37 = V_2 -> V_31 ;
if ( V_7 >= V_23 ) {
V_22 = F_25 ( V_2 , V_7 ) ;
if ( ! V_22 || V_22 -> V_27 & V_28 )
V_36 = V_22 ;
if ( ! V_22 || V_22 -> V_27 & V_30 )
V_37 = V_22 ;
}
V_34 -> V_38 = V_2 -> V_12 ;
V_34 -> V_39 = V_2 -> V_40 ;
F_34 ( V_34 -> V_29 ) = V_36 ;
F_34 ( V_34 -> V_31 ) = V_37 ;
}
static void F_35 ( struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
if ( V_34 -> V_38 != V_2 -> V_12 ||
V_34 -> V_39 != V_2 -> V_40 )
F_31 ( V_32 ) ;
}
static struct V_21 * F_36 ( struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
F_35 ( V_32 ) ;
return F_34 ( V_34 -> V_29 ) ;
}
static struct V_21 * F_37 ( struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
F_35 ( V_32 ) ;
return F_34 ( V_34 -> V_31 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_21 * V_22 , unsigned V_41 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
int V_44 ;
if ( V_41 > V_43 -> V_45 )
return - V_46 ;
if ( V_22 -> V_47 ) {
F_39 ( V_2 -> V_9 ,
L_1 ) ;
return - V_48 ;
}
if ( F_40 ( V_22 ) ) {
F_39 ( V_2 -> V_9 ,
L_2 ) ;
return - V_48 ;
}
V_41 = ( V_41 + V_49 - 1 ) & V_50 ;
V_44 = F_41 ( V_2 , V_22 , V_41 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_22 -> V_51 ) {
V_44 = V_22 -> V_51 ( V_2 , V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_39 ( V_2 -> V_9 , L_3 ,
V_22 -> V_52 , V_43 -> V_53 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 = 0 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_29 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_28 ) && V_22 -> V_43 )
V_59 = V_22 -> V_43 -> V_45 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_57 , V_49 , L_4 , V_59 ) ;
}
static T_1 F_44 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_45 ( V_57 , 10 , & V_59 ) ;
if ( V_62 )
return V_62 ;
if ( V_59 > ( V_63 / 1024 ) )
return - V_64 ;
V_59 *= 1024 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_29 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_28 ) && V_22 -> V_43 )
V_22 -> V_43 -> V_45 = V_59 ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static T_1 F_46 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 = 0 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_29 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_28 ) && V_22 -> V_43 )
V_59 = V_22 -> V_43 -> V_53 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_57 , V_49 , L_4 , V_59 ) ;
}
static T_1 F_47 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_45 ( V_57 , 10 , & V_59 ) ;
if ( V_62 )
return V_62 ;
if ( V_59 > ( V_63 / 1024 ) )
return - V_64 ;
V_59 *= 1024 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_29 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_28 ) && V_22 -> V_43 )
V_62 = F_38 ( V_2 , V_22 , V_59 ) ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static T_1 F_48 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
char * V_57 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 = 0 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_30 ) && V_22 -> V_43 )
V_59 = V_22 -> V_43 -> V_45 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_57 , V_49 , L_4 , V_59 ) ;
}
static T_1 F_49 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_45 ( V_57 , 10 , & V_59 ) ;
if ( V_62 )
return V_62 ;
if ( V_59 > ( V_63 / 1024 ) )
return - V_64 ;
V_59 *= 1024 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_30 ) && V_22 -> V_43 )
V_22 -> V_43 -> V_45 = V_59 ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static T_1 F_50 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 = 0 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_30 ) && V_22 -> V_43 )
V_59 = V_22 -> V_43 -> V_53 / 1024 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return snprintf ( V_57 , V_49 , L_4 , V_59 ) ;
}
static T_1 F_51 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_43 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_45 ( V_57 , 10 , & V_59 ) ;
if ( V_62 )
return V_62 ;
if ( V_59 > ( V_63 / 1024 ) )
return - V_64 ;
V_59 *= 1024 ;
V_2 = F_28 ( V_7 ) ;
if ( ! V_2 )
return - V_60 ;
F_16 ( & V_2 -> V_5 ) ;
V_22 = F_30 ( V_2 , V_7 ) ;
if ( V_22 && ( V_22 -> V_27 & V_30 ) && V_22 -> V_43 )
V_62 = F_38 ( V_2 , V_22 , V_59 ) ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static void F_52 ( struct V_21 * V_22 ,
unsigned V_65 )
{
V_22 -> V_66 &= ~ V_65 ;
}
static void F_53 ( struct V_21 * V_22 ,
unsigned V_65 )
{
V_22 -> V_66 |= V_65 ;
}
static void F_54 ( struct V_21 * V_22 ,
unsigned V_67 , unsigned V_65 )
{
unsigned long V_68 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
F_52 ( V_22 , V_67 ) ;
F_53 ( V_22 , V_65 & V_67 ) ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
}
static unsigned F_57 ( struct V_21 * V_22 )
{
return V_22 -> V_66 ;
}
static unsigned F_58 ( struct V_21 * V_22 )
{
unsigned long V_68 ;
unsigned V_66 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
V_66 = F_57 ( V_22 ) ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
return V_66 ;
}
static bool F_59 ( unsigned V_66 )
{
return V_66 & V_70 ;
}
static bool F_60 ( unsigned V_66 )
{
return V_66 & V_71 ;
}
bool F_61 ( struct V_21 * V_22 )
{
unsigned V_66 = F_58 ( V_22 ) ;
return F_59 ( V_66 ) ;
}
static bool F_62 ( struct V_21 * V_22 )
{
unsigned V_66 = F_57 ( V_22 ) ;
return F_59 ( V_66 ) ;
}
static bool F_63 ( struct V_21 * V_22 )
{
unsigned V_66 = F_58 ( V_22 ) ;
return ! ( V_66 & V_72 ) ;
}
bool F_64 ( struct V_21 * V_22 )
{
unsigned V_66 = F_57 ( V_22 ) ;
return V_66 & V_73 ;
}
void F_65 ( struct V_21 * V_22 )
{
F_53 ( V_22 , V_73 ) ;
}
void * F_66 ( struct V_21 * V_22 , T_2 V_59 )
{
V_22 -> V_74 = F_67 ( V_59 , V_75 ) ;
if ( V_22 -> V_74 )
F_65 ( V_22 ) ;
return V_22 -> V_74 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
F_54 ( V_22 , V_70 , 0 ) ;
if ( V_43 ) {
F_69 ( V_22 ) ;
V_43 -> V_76 = NULL ;
F_10 ( V_43 -> V_77 . V_78 ) ;
V_43 -> V_77 . V_78 = NULL ;
V_22 -> V_47 = NULL ;
F_70 ( & V_43 -> V_79 ) ;
} else {
F_71 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_47 = NULL ;
}
}
static int F_72 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_80 = 0 ;
if ( F_61 ( V_22 ) && V_22 -> V_81 )
V_80 = V_22 -> V_81 ( V_2 , V_22 ) ;
F_68 ( V_2 , V_22 ) ;
return V_80 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_43 )
F_72 ( V_2 , V_22 ) ;
}
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_47 )
return 1 ;
if ( V_22 -> V_43 && F_40 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_84 T_3 * V_85 )
{
struct V_84 V_86 ;
if ( ! F_76 ( V_87 ) )
return - V_46 ;
if ( ! V_85 ) {
if ( F_74 ( V_2 ) )
return - V_48 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_77 ( & V_86 , V_85 , sizeof( V_86 ) ) )
return - V_88 ;
V_86 . V_89 [ V_90 - 1 ] = 0 ;
if ( V_86 . V_91 [ V_92 ] ) {
F_78 ( V_2 -> V_9 ,
L_6 ) ;
return - V_64 ;
}
if ( V_2 -> V_7 >= V_93 )
return - V_48 ;
return F_79 ( V_2 , & V_86 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_94 T_3 * V_85 )
{
struct V_94 V_95 ;
struct V_42 * V_43 ;
struct V_21 * V_22 ;
int V_44 = 0 ;
if ( F_77 ( & V_95 , V_85 , sizeof( V_95 ) ) )
return - V_88 ;
if ( V_95 . V_96 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_95 . V_96 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
F_39 ( V_2 -> V_9 ,
L_7 ) ;
V_95 . V_59 = 0 ;
V_95 . V_97 = 0 ;
goto V_98;
}
if ( V_95 . V_97 ) {
if ( ! F_76 ( V_87 ) )
return - V_46 ;
V_43 -> V_45 = V_95 . V_97 ;
}
if ( V_95 . V_59 ) {
V_44 = F_38 ( V_2 , V_22 , V_95 . V_59 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_95 . V_59 = V_43 -> V_53 ;
V_95 . V_97 = V_43 -> V_45 ;
V_98:
if ( F_81 ( V_85 , & V_95 , sizeof( V_95 ) ) )
return - V_88 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_99 T_3 * V_85 ,
struct V_32 * V_32 )
{
struct V_21 * V_22 ;
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_101 = V_102 ;
V_100 . V_103 = V_2 -> V_82 ;
F_83 ( V_100 . V_104 , V_2 -> V_13 -> V_104 , V_90 ) ;
F_83 ( V_100 . V_89 , V_2 -> V_89 , V_90 ) ;
V_22 = F_36 ( V_32 ) ;
if ( V_22 )
V_100 . V_105 = V_22 -> V_52 ;
else
V_100 . V_105 = - 1 ;
V_22 = F_37 ( V_32 ) ;
if ( V_22 )
V_100 . V_106 = V_22 -> V_52 ;
else
V_100 . V_106 = - 1 ;
if ( F_81 ( V_85 , & V_100 , sizeof( V_100 ) ) )
return - V_88 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_107 T_3 * V_85 , void * V_32 )
{
int V_80 , V_15 ;
struct V_107 * V_108 , * V_109 ;
struct V_21 * V_22 ;
V_108 = F_85 ( V_2 -> V_82 , sizeof( * V_108 ) , V_75 ) ;
if ( ! V_108 )
return - V_110 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
V_109 = V_108 + V_15 ;
V_109 -> type = V_22 -> type ;
V_109 -> V_111 = V_22 -> V_111 ;
V_109 -> V_112 = V_22 -> V_27 ;
if ( F_61 ( V_22 ) )
V_109 -> V_112 |= V_113 ;
#define F_86 5
V_109 -> V_114 = F_86 ;
V_109 -> V_115 = V_22 -> V_115 ;
V_109 -> V_116 = V_22 -> V_116 ;
if ( V_22 -> V_117 ) {
V_109 -> V_118 =
( V_15 << 24 ) | ( 0 << 16 ) | ( V_22 -> V_117 -> V_119 ) ;
} else {
V_109 -> V_118 = 0 ;
}
if ( V_22 -> V_47 )
V_109 -> V_112 |= V_120 ;
if ( V_22 -> V_47 == V_32 )
V_109 -> V_112 |= V_121 ;
if ( V_22 -> V_122 )
V_109 -> V_112 |= V_123 ;
if ( V_22 -> V_122 == V_32 )
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
V_80 = F_81 ( V_85 , V_108 , V_2 -> V_82 * sizeof( * V_108 ) ) ;
F_10 ( V_108 ) ;
return V_80 ? - V_88 : 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_136 T_3 * V_85 )
{
struct V_21 * V_22 ;
struct V_136 V_86 ;
if ( F_77 ( & V_86 , V_85 , sizeof( V_86 ) ) )
return - V_88 ;
if ( V_86 . V_137 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_86 . V_137 ] ;
if ( V_86 . V_125 ) {
if ( V_22 -> V_116 || ! V_22 -> V_125 )
return - V_64 ;
if ( F_81 ( V_86 . V_125 , V_22 -> V_125 ,
V_22 -> V_111 * sizeof( unsigned int ) ) )
return - V_88 ;
}
if ( V_86 . V_138 )
return - V_64 ;
if ( V_86 . V_139 ) {
int V_15 ;
if ( ! V_22 -> V_127 )
return - V_64 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_111 ; V_15 ++ ) {
int V_140 ;
V_140 = ( V_2 -> V_7 << 28 ) | ( V_86 . V_137 << 24 ) | ( V_15 << 16 ) |
( V_22 -> V_127 [ V_15 ] -> V_119 ) ;
if ( F_88 ( V_140 , V_86 . V_139 + V_15 ) )
return - V_88 ;
}
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_141 T_3 * V_85 , void * V_32 )
{
struct V_141 V_142 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
if ( F_77 ( & V_142 , V_85 , sizeof( V_142 ) ) )
return - V_88 ;
if ( V_142 . V_96 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_142 . V_96 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
F_39 ( V_2 -> V_9 ,
L_7 ) ;
V_142 . V_143 = 0 ;
V_142 . V_144 = 0 ;
V_142 . V_145 = 0 ;
V_142 . V_146 = 0 ;
V_142 . V_147 = 0 ;
V_142 . V_148 = 0 ;
goto V_98;
}
if ( ! V_22 -> V_47 ) {
V_142 . V_147 = 0 ;
V_142 . V_148 = 0 ;
goto V_149;
}
if ( V_22 -> V_47 != V_32 )
return - V_150 ;
if ( V_142 . V_147 && ! ( V_43 -> V_77 . V_68 & V_151 ) ) {
V_142 . V_147 = F_90 ( V_22 , V_142 . V_147 ) ;
F_91 ( V_22 , V_142 . V_147 ) ;
if ( F_63 ( V_22 ) &&
F_92 ( V_22 ) == 0 ) {
F_68 ( V_2 , V_22 ) ;
}
}
if ( V_142 . V_148 && ( V_43 -> V_77 . V_68 & V_151 ) ) {
V_142 . V_148 =
F_93 ( V_22 , V_142 . V_148 ) ;
F_94 ( V_22 , V_142 . V_148 ) ;
}
V_149:
V_142 . V_145 = V_43 -> V_145 ;
V_142 . V_143 = V_43 -> V_143 ;
V_142 . V_146 = V_43 -> V_146 ;
V_142 . V_144 = V_43 -> V_144 ;
V_98:
if ( F_81 ( V_85 , & V_142 , sizeof( V_142 ) ) )
return - V_88 ;
return 0 ;
}
static int F_95 ( struct V_152 * V_153 ,
unsigned int * V_154 )
{
if ( V_153 -> V_155 < 1 )
return - V_64 ;
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
F_96 ( L_8 ,
V_154 [ 0 ] ) ;
F_96 ( L_9 , V_186 , __FILE__ ) ;
F_96 ( L_10 , V_153 -> V_155 ) ;
return 0 ;
}
return - V_64 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_152 * V_153 ,
unsigned int * V_154 , void * V_32 )
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
V_80 = - V_64 ;
break;
}
F_98 ( & V_190 ) ;
V_154 [ 0 ] = V_190 . V_191 ;
V_154 [ 1 ] = V_190 . V_192 ;
V_80 = 2 ;
break;
}
case V_193 :
if ( V_153 -> V_155 != 1 || V_154 [ 0 ] >= 100000 ) {
V_80 = - V_64 ;
break;
}
F_99 ( V_154 [ 0 ] / 1000 ) ;
V_80 = 1 ;
break;
case V_194 :
if ( V_153 -> V_155 != 1 ) {
V_80 = - V_64 ;
break;
}
if ( V_153 -> V_137 >= V_2 -> V_82 ) {
F_39 ( V_2 -> V_9 ,
L_11 ,
V_153 -> V_137 ) ;
V_80 = - V_64 ;
break;
}
V_22 = & V_2 -> V_83 [ V_153 -> V_137 ] ;
if ( ! V_22 -> V_43 ) {
F_39 ( V_2 -> V_9 , L_12 ) ;
V_80 = - V_64 ;
break;
}
if ( ! V_22 -> V_43 -> V_76 ) {
F_39 ( V_2 -> V_9 , L_13 ) ;
V_80 = - V_195 ;
break;
}
V_80 = V_22 -> V_43 -> V_76 ( V_2 , V_22 , V_154 [ 0 ] ) ;
if ( V_80 >= 0 )
V_80 = 1 ;
break;
default:
F_39 ( V_2 -> V_9 , L_14 ) ;
V_80 = - V_64 ;
break;
}
} else {
unsigned int V_116 ;
if ( V_153 -> V_137 >= V_2 -> V_82 ) {
F_39 ( V_2 -> V_9 , L_15 ,
V_153 -> V_137 ) ;
V_80 = - V_64 ;
goto V_196;
}
V_22 = & V_2 -> V_83 [ V_153 -> V_137 ] ;
if ( V_22 -> type == V_197 ) {
F_39 ( V_2 -> V_9 , L_11 ,
V_153 -> V_137 ) ;
V_80 = - V_198 ;
goto V_196;
}
if ( V_22 -> V_122 && V_22 -> V_122 != V_32 ) {
F_39 ( V_2 -> V_9 , L_16 ) ;
V_80 = - V_150 ;
goto V_196;
}
V_80 = F_100 ( V_22 , 1 , & V_153 -> V_199 ) ;
if ( V_80 < 0 ) {
V_80 = - V_64 ;
F_39 ( V_2 -> V_9 , L_17 ) ;
goto V_196;
}
if ( V_22 -> V_47 ) {
V_80 = - V_48 ;
goto V_196;
}
V_22 -> V_47 = F_97 ;
switch ( V_153 -> V_153 ) {
case V_200 :
V_80 = V_22 -> V_201 ( V_2 , V_22 , V_153 , V_154 ) ;
if ( V_80 == - V_202 ) {
F_39 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_52 ) ;
}
break;
case V_203 :
V_116 = V_22 -> V_125
? V_22 -> V_125 [ F_101 ( V_153 -> V_199 ) ]
: V_22 -> V_116 ;
for ( V_15 = 0 ; V_15 < V_153 -> V_155 ; ++ V_15 ) {
if ( V_154 [ V_15 ] > V_116 ) {
V_80 = - V_64 ;
F_39 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_80 == 0 ) {
V_80 = V_22 -> V_204 ( V_2 , V_22 , V_153 , V_154 ) ;
if ( V_80 == - V_202 ) {
F_39 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_52 ) ;
}
}
break;
case V_205 :
if ( V_153 -> V_155 != 2 ) {
V_80 = - V_64 ;
} else {
unsigned int V_206 = V_154 [ 0 ] ;
unsigned int V_207 = 0 ;
if ( V_22 -> V_111 <= 32 ) {
V_207 = F_101 ( V_153 -> V_199 ) ;
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
V_80 = F_95 ( V_153 , V_154 ) ;
if ( V_80 )
break;
V_80 = V_22 -> V_209 ( V_2 , V_22 , V_153 , V_154 ) ;
break;
default:
V_80 = - V_64 ;
break;
}
V_22 -> V_47 = NULL ;
}
V_196:
return V_80 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_210 T_3 * V_85 , void * V_32 )
{
struct V_210 V_211 ;
struct V_152 * V_212 = NULL ;
unsigned int * V_154 = NULL ;
int V_15 = 0 ;
int V_80 = 0 ;
if ( F_77 ( & V_211 , V_85 , sizeof( V_211 ) ) )
return - V_88 ;
V_154 = F_103 ( V_213 , sizeof( unsigned int ) , V_75 ) ;
if ( ! V_154 ) {
V_80 = - V_110 ;
goto error;
}
V_212 = F_85 ( V_211 . V_214 , sizeof( * V_212 ) , V_75 ) ;
if ( ! V_212 ) {
V_80 = - V_110 ;
goto error;
}
if ( F_77 ( V_212 , V_211 . V_212 ,
sizeof( * V_212 ) * V_211 . V_214 ) ) {
F_39 ( V_2 -> V_9 , L_21 ) ;
V_80 = - V_88 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_211 . V_214 ; V_15 ++ ) {
if ( V_212 [ V_15 ] . V_155 > V_213 ) {
F_39 ( V_2 -> V_9 ,
L_22 ) ;
V_80 = - V_64 ;
goto error;
}
if ( V_212 [ V_15 ] . V_153 & V_215 ) {
if ( F_77 ( V_154 , V_212 [ V_15 ] . V_154 ,
V_212 [ V_15 ] . V_155 * sizeof( unsigned int ) ) ) {
F_39 ( V_2 -> V_9 ,
L_21 ) ;
V_80 = - V_88 ;
goto error;
}
}
V_80 = F_97 ( V_2 , V_212 + V_15 , V_154 , V_32 ) ;
if ( V_80 < 0 )
goto error;
if ( V_212 [ V_15 ] . V_153 & V_216 ) {
if ( F_81 ( V_212 [ V_15 ] . V_154 , V_154 ,
V_212 [ V_15 ] . V_155 * sizeof( unsigned int ) ) ) {
F_39 ( V_2 -> V_9 ,
L_23 ) ;
V_80 = - V_88 ;
goto error;
}
}
if ( F_104 () )
F_105 () ;
}
error:
F_10 ( V_212 ) ;
F_10 ( V_154 ) ;
if ( V_80 < 0 )
return V_80 ;
return V_15 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_152 T_3 * V_85 , void * V_32 )
{
struct V_152 V_153 ;
unsigned int * V_154 = NULL ;
int V_80 = 0 ;
V_154 = F_103 ( V_213 , sizeof( unsigned int ) , V_75 ) ;
if ( ! V_154 ) {
V_80 = - V_110 ;
goto error;
}
if ( F_77 ( & V_153 , V_85 , sizeof( V_153 ) ) ) {
V_80 = - V_88 ;
goto error;
}
if ( V_153 . V_155 > V_213 )
V_153 . V_155 = V_213 ;
if ( V_153 . V_153 & V_215 ) {
if ( F_77 ( V_154 ,
V_153 . V_154 ,
V_153 . V_155 * sizeof( unsigned int ) ) ) {
V_80 = - V_88 ;
goto error;
}
}
V_80 = F_97 ( V_2 , & V_153 , V_154 , V_32 ) ;
if ( V_80 < 0 )
goto error;
if ( V_153 . V_153 & V_216 ) {
if ( F_81 ( V_153 . V_154 ,
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
static int F_107 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 ,
struct V_217 * V_77 )
{
struct V_21 * V_22 ;
if ( F_77 ( V_77 , V_85 , sizeof( * V_77 ) ) ) {
F_39 ( V_2 -> V_9 , L_24 ) ;
return - V_88 ;
}
if ( V_77 -> V_137 >= V_2 -> V_82 ) {
F_39 ( V_2 -> V_9 , L_25 , V_77 -> V_137 ) ;
return - V_60 ;
}
V_22 = & V_2 -> V_83 [ V_77 -> V_137 ] ;
if ( V_22 -> type == V_197 ) {
F_39 ( V_2 -> V_9 , L_26 ,
V_77 -> V_137 ) ;
return - V_198 ;
}
if ( ! V_22 -> V_129 || ! V_22 -> V_218 || ! V_22 -> V_43 ) {
F_39 ( V_2 -> V_9 ,
L_27 ,
V_77 -> V_137 ) ;
return - V_198 ;
}
if ( V_77 -> V_219 > V_22 -> V_115 ) {
F_39 ( V_2 -> V_9 , L_28 ,
V_77 -> V_219 , V_22 -> V_115 ) ;
return - V_64 ;
}
switch ( V_22 -> V_27 & ( V_28 | V_30 ) ) {
case V_28 :
V_77 -> V_68 &= ~ V_151 ;
break;
case V_30 :
V_77 -> V_68 |= V_151 ;
break;
default:
break;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_220 ,
struct V_217 * V_77 )
{
unsigned int * V_78 ;
int V_80 ;
V_77 -> V_78 = NULL ;
V_78 = F_109 ( V_220 ,
V_77 -> V_219 * sizeof( unsigned int ) ) ;
if ( F_110 ( V_78 ) )
return F_111 ( V_78 ) ;
V_80 = F_100 ( V_22 , V_77 -> V_219 , V_78 ) ;
if ( V_80 < 0 ) {
F_10 ( V_78 ) ;
return V_80 ;
}
V_77 -> V_78 = V_78 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 , void * V_32 )
{
struct V_217 V_77 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int T_3 * V_220 ;
int V_80 ;
V_80 = F_107 ( V_2 , V_85 , & V_77 ) ;
if ( V_80 )
return V_80 ;
V_220 = ( unsigned int T_3 * ) V_77 . V_78 ;
V_22 = & V_2 -> V_83 [ V_77 . V_137 ] ;
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_122 && V_22 -> V_122 != V_32 ) {
F_39 ( V_2 -> V_9 , L_29 ) ;
return - V_150 ;
}
if ( V_22 -> V_47 ) {
F_39 ( V_2 -> V_9 , L_30 ) ;
return - V_48 ;
}
if ( V_77 . V_219 < 1 ) {
F_39 ( V_2 -> V_9 , L_31 ,
V_77 . V_219 ) ;
return - V_64 ;
}
V_43 -> V_77 = V_77 ;
V_43 -> V_77 . V_154 = NULL ;
V_80 = F_108 ( V_2 , V_22 , V_220 , & V_43 -> V_77 ) ;
if ( V_80 )
goto V_221;
V_80 = V_22 -> V_218 ( V_2 , V_22 , & V_43 -> V_77 ) ;
if ( V_43 -> V_77 . V_68 & V_222 || V_80 ) {
F_39 ( V_2 -> V_9 , L_32 , V_80 ) ;
V_77 = V_43 -> V_77 ;
V_77 . V_78 = ( unsigned int V_223 * ) V_220 ;
V_77 . V_154 = NULL ;
if ( F_81 ( V_85 , & V_77 , sizeof( V_77 ) ) ) {
F_39 ( V_2 -> V_9 , L_33 ) ;
V_80 = - V_88 ;
goto V_221;
}
V_80 = - V_195 ;
goto V_221;
}
if ( ! V_43 -> V_53 ) {
V_80 = - V_110 ;
F_39 ( V_2 -> V_9 , L_34 ) ;
goto V_221;
}
F_69 ( V_22 ) ;
V_43 -> V_224 = V_225 | V_226 ;
if ( V_43 -> V_77 . V_68 & V_227 )
V_43 -> V_224 |= V_228 ;
F_54 ( V_22 , V_72 ,
V_70 ) ;
V_22 -> V_47 = V_32 ;
V_80 = V_22 -> V_129 ( V_2 , V_22 ) ;
if ( V_80 == 0 )
return 0 ;
V_221:
F_68 ( V_2 , V_22 ) ;
return V_80 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_85 , void * V_32 )
{
struct V_217 V_77 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_220 ;
int V_80 ;
V_80 = F_107 ( V_2 , V_85 , & V_77 ) ;
if ( V_80 )
return V_80 ;
V_220 = ( unsigned int T_3 * ) V_77 . V_78 ;
V_22 = & V_2 -> V_83 [ V_77 . V_137 ] ;
if ( V_220 ) {
V_80 = F_108 ( V_2 , V_22 , V_220 , & V_77 ) ;
if ( V_80 )
return V_80 ;
}
V_80 = V_22 -> V_218 ( V_2 , V_22 , & V_77 ) ;
F_10 ( V_77 . V_78 ) ;
V_77 . V_78 = ( unsigned int V_223 * ) V_220 ;
if ( F_81 ( V_85 , & V_77 , sizeof( V_77 ) ) ) {
F_39 ( V_2 -> V_9 , L_24 ) ;
V_80 = - V_88 ;
}
return V_80 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_32 )
{
int V_80 = 0 ;
unsigned long V_68 ;
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
if ( V_22 -> V_47 || V_22 -> V_122 )
V_80 = - V_48 ;
else
V_22 -> V_122 = V_32 ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
return V_80 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( V_22 -> V_47 )
return - V_48 ;
if ( V_22 -> V_122 && V_22 -> V_122 != V_32 )
return - V_150 ;
if ( V_22 -> V_122 == V_32 )
V_22 -> V_122 = NULL ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( ! V_22 -> V_43 )
return - V_64 ;
if ( ! V_22 -> V_47 )
return 0 ;
if ( V_22 -> V_47 != V_32 )
return - V_48 ;
return F_72 ( V_2 , V_22 ) ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_85 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_22 = & V_2 -> V_83 [ V_85 ] ;
if ( ! V_22 -> V_47 )
return 0 ;
if ( V_22 -> V_47 != V_32 )
return - V_48 ;
if ( V_22 -> V_229 )
return V_22 -> V_229 ( V_2 , V_22 ) ;
return - V_64 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned long V_85 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_230 , * V_231 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_231 = & V_2 -> V_83 [ V_85 ] ;
V_230 = F_36 ( V_32 ) ;
if ( V_230 == V_231 )
return 0 ;
if ( ! ( V_231 -> V_27 & V_28 ) )
return - V_64 ;
if ( V_230 && V_230 -> V_47 == V_32 && V_230 -> V_43 &&
! ( V_230 -> V_43 -> V_77 . V_68 & V_151 ) )
return - V_48 ;
F_34 ( V_34 -> V_29 ) = V_231 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , unsigned long V_85 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_230 , * V_231 ;
if ( V_85 >= V_2 -> V_82 )
return - V_64 ;
V_231 = & V_2 -> V_83 [ V_85 ] ;
V_230 = F_37 ( V_32 ) ;
if ( V_230 == V_231 )
return 0 ;
if ( ! ( V_231 -> V_27 & V_30 ) )
return - V_64 ;
if ( V_230 && V_230 -> V_47 == V_32 && V_230 -> V_43 &&
( V_230 -> V_43 -> V_77 . V_68 & V_151 ) )
return - V_48 ;
F_34 ( V_34 -> V_31 ) = V_231 ;
return 0 ;
}
static long F_120 ( struct V_32 * V_32 , unsigned int V_77 ,
unsigned long V_85 )
{
unsigned V_7 = F_32 ( F_33 ( V_32 ) ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_232 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_77 == V_233 ) {
if ( V_7 >= V_23 ) {
V_232 = - V_234 ;
goto V_235;
}
V_232 = F_75 ( V_2 ,
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
F_39 ( V_2 -> V_9 , L_35 ) ;
V_232 = - V_60 ;
goto V_235;
}
switch ( V_77 ) {
case V_236 :
V_232 = F_80 ( V_2 ,
(struct V_94 T_3 * ) V_85 ) ;
break;
case V_237 :
V_232 = F_82 ( V_2 , (struct V_99 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_238 :
V_232 = F_84 ( V_2 ,
(struct V_107 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_239 :
V_232 = F_87 ( V_2 , ( void T_3 * ) V_85 ) ;
break;
case V_240 :
V_232 = F_121 ( V_2 , ( void T_3 * ) V_85 ) ;
break;
case V_241 :
V_232 = F_89 ( V_2 ,
(struct V_141 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_242 :
V_232 = F_114 ( V_2 , V_85 , V_32 ) ;
break;
case V_243 :
V_232 = F_115 ( V_2 , V_85 , V_32 ) ;
break;
case V_244 :
V_232 = F_116 ( V_2 , V_85 , V_32 ) ;
break;
case V_245 :
V_232 = F_112 ( V_2 , (struct V_217 T_3 * ) V_85 , V_32 ) ;
break;
case V_246 :
V_232 = F_113 ( V_2 , (struct V_217 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_247 :
V_232 = F_102 ( V_2 ,
(struct V_210 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_248 :
V_232 = F_106 ( V_2 , (struct V_152 T_3 * ) V_85 ,
V_32 ) ;
break;
case V_249 :
V_232 = F_117 ( V_2 , V_85 , V_32 ) ;
break;
case V_250 :
V_232 = F_118 ( V_2 , V_85 , V_32 ) ;
break;
case V_251 :
V_232 = F_119 ( V_2 , V_85 , V_32 ) ;
break;
default:
V_232 = - V_234 ;
break;
}
V_235:
F_19 ( & V_2 -> V_5 ) ;
return V_232 ;
}
static void F_122 ( struct V_252 * V_253 )
{
struct V_254 * V_255 ;
V_255 = V_253 -> V_256 ;
F_123 ( V_255 ) ;
}
static void F_124 ( struct V_252 * V_253 )
{
struct V_254 * V_255 ;
V_255 = V_253 -> V_256 ;
F_125 ( V_255 ) ;
}
static int F_126 ( struct V_32 * V_32 , struct V_252 * V_257 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
struct V_254 * V_255 = NULL ;
unsigned long V_258 = V_257 -> V_259 ;
unsigned long V_59 ;
int V_260 ;
int V_15 ;
int V_44 ;
if ( ! F_127 ( & V_2 -> V_6 ) )
return - V_195 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_235;
}
if ( V_257 -> V_261 & V_262 )
V_22 = F_37 ( V_32 ) ;
else
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 ) {
V_44 = - V_64 ;
goto V_235;
}
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
V_44 = - V_64 ;
goto V_235;
}
if ( V_257 -> V_263 != 0 ) {
F_39 ( V_2 -> V_9 , L_36 ) ;
V_44 = - V_64 ;
goto V_235;
}
V_59 = V_257 -> V_264 - V_257 -> V_259 ;
if ( V_59 > V_43 -> V_53 ) {
V_44 = - V_88 ;
goto V_235;
}
if ( V_59 & ( ~ V_50 ) ) {
V_44 = - V_88 ;
goto V_235;
}
V_260 = V_59 >> V_265 ;
V_255 = F_128 ( V_22 ) ;
if ( ! V_255 || V_260 > V_255 -> V_260 ) {
V_44 = - V_64 ;
goto V_235;
}
for ( V_15 = 0 ; V_15 < V_260 ; ++ V_15 ) {
struct V_266 * V_57 = & V_255 -> V_267 [ V_15 ] ;
if ( F_129 ( V_257 , V_258 ,
F_130 ( F_131 ( V_57 -> V_268 ) ) ,
V_49 , V_269 ) ) {
V_44 = - V_195 ;
goto V_235;
}
V_258 += V_49 ;
}
V_257 -> V_270 = & V_271 ;
V_257 -> V_256 = V_255 ;
V_257 -> V_270 -> V_272 ( V_257 ) ;
V_44 = 0 ;
V_235:
F_132 ( & V_2 -> V_6 ) ;
F_125 ( V_255 ) ;
return V_44 ;
}
static unsigned int F_133 ( struct V_32 * V_32 , T_4 * V_273 )
{
unsigned int V_67 = 0 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 , * V_274 ;
F_134 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
goto V_235;
}
V_22 = F_36 ( V_32 ) ;
V_274 = V_22 ;
if ( V_22 && V_22 -> V_43 ) {
F_135 ( V_32 , & V_22 -> V_43 -> V_79 , V_273 ) ;
if ( V_22 -> V_47 != V_32 || ! F_61 ( V_22 ) ||
( V_22 -> V_43 -> V_77 . V_68 & V_151 ) ||
F_92 ( V_22 ) > 0 )
V_67 |= V_275 | V_276 ;
}
V_22 = F_37 ( V_32 ) ;
if ( V_22 && V_22 -> V_43 ) {
unsigned int V_277 = F_136 ( V_22 ) ;
if ( V_22 != V_274 )
F_135 ( V_32 , & V_22 -> V_43 -> V_79 , V_273 ) ;
if ( V_22 -> V_47 != V_32 || ! F_61 ( V_22 ) ||
! ( V_22 -> V_43 -> V_77 . V_68 & V_151 ) ||
F_137 ( V_22 ) >= V_277 )
V_67 |= V_278 | V_279 ;
}
V_235:
F_132 ( & V_2 -> V_6 ) ;
return V_67 ;
}
static T_1 F_138 ( struct V_32 * V_32 , const char T_3 * V_57 ,
T_2 V_280 , T_5 * V_281 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_155 , V_282 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_139 ( V_273 , V_283 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
bool V_284 = false ;
bool V_285 ;
unsigned int V_286 ;
F_134 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_196;
}
V_22 = F_37 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_198 ;
goto V_196;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ! ( V_43 -> V_77 . V_68 & V_151 ) ) {
V_44 = - V_64 ;
goto V_196;
}
F_140 ( & V_43 -> V_79 , & V_273 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned V_66 ;
unsigned int V_287 , V_288 , V_289 ;
F_141 ( V_290 ) ;
V_66 = F_58 ( V_22 ) ;
if ( ! F_59 ( V_66 ) ) {
if ( F_60 ( V_66 ) )
V_44 = - V_291 ;
if ( V_44 || V_280 )
V_284 = true ;
break;
}
if ( V_280 == 0 )
break;
F_93 ( V_22 , V_43 -> V_53 ) ;
V_282 = F_142 ( V_22 ) ;
V_155 = F_143 ( T_2 , V_282 , V_280 ) ;
if ( V_155 == 0 ) {
if ( V_32 -> V_292 & V_293 ) {
V_44 = - V_195 ;
break;
}
F_105 () ;
if ( F_144 ( V_283 ) ) {
V_44 = - V_294 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
! ( V_43 -> V_77 . V_68 & V_151 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
V_287 = V_43 -> V_143 ;
V_288 = F_145 ( V_155 , V_43 -> V_53 - V_287 ) ;
V_289 = V_155 - V_288 ;
V_282 = F_77 ( V_43 -> V_295 + V_287 , V_57 , V_288 ) ;
if ( V_282 )
V_282 += V_289 ;
else if ( V_289 )
V_282 = F_77 ( V_43 -> V_295 , V_57 + V_288 , V_289 ) ;
if ( V_282 ) {
V_155 -= V_282 ;
V_44 = - V_88 ;
}
F_94 ( V_22 , V_155 ) ;
V_61 += V_155 ;
V_280 -= V_155 ;
V_57 += V_155 ;
}
F_146 ( & V_43 -> V_79 , & V_273 ) ;
F_141 ( V_296 ) ;
if ( V_284 && V_61 == 0 ) {
struct V_21 * V_297 ;
F_132 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_297 = F_37 ( V_32 ) ;
if ( V_2 -> V_12 && V_286 == V_2 -> V_40 &&
V_22 == V_297 && V_297 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
( V_43 -> V_77 . V_68 & V_151 ) &&
! F_61 ( V_22 ) )
F_68 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_196:
if ( V_285 )
F_132 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static T_1 F_147 ( struct V_32 * V_32 , char T_3 * V_57 , T_2 V_280 ,
T_5 * V_281 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_155 , V_282 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_139 ( V_273 , V_283 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned int V_286 ;
bool V_284 = false ;
bool V_285 ;
F_134 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_196;
}
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_198 ;
goto V_196;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ( V_43 -> V_77 . V_68 & V_151 ) ) {
V_44 = - V_64 ;
goto V_196;
}
F_140 ( & V_43 -> V_79 , & V_273 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned int V_298 , V_288 , V_289 ;
F_141 ( V_290 ) ;
V_282 = F_92 ( V_22 ) ;
V_155 = F_143 ( T_2 , V_282 , V_280 ) ;
if ( V_155 == 0 ) {
unsigned V_66 = F_58 ( V_22 ) ;
if ( ! F_59 ( V_66 ) ) {
if ( F_60 ( V_66 ) )
V_44 = - V_291 ;
if ( V_44 || V_280 )
V_284 = true ;
break;
}
if ( V_280 == 0 )
break;
if ( V_32 -> V_292 & V_293 ) {
V_44 = - V_195 ;
break;
}
F_105 () ;
if ( F_144 ( V_283 ) ) {
V_44 = - V_294 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
( V_43 -> V_77 . V_68 & V_151 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
V_298 = V_43 -> V_144 ;
V_288 = F_145 ( V_155 , V_43 -> V_53 - V_298 ) ;
V_289 = V_155 - V_288 ;
V_282 = F_81 ( V_57 , V_43 -> V_295 + V_298 , V_288 ) ;
if ( V_282 )
V_282 += V_289 ;
else if ( V_289 )
V_282 = F_81 ( V_57 + V_288 , V_43 -> V_295 , V_289 ) ;
if ( V_282 ) {
V_155 -= V_282 ;
V_44 = - V_88 ;
}
F_90 ( V_22 , V_155 ) ;
F_91 ( V_22 , V_155 ) ;
V_61 += V_155 ;
V_280 -= V_155 ;
V_57 += V_155 ;
}
F_146 ( & V_43 -> V_79 , & V_273 ) ;
F_141 ( V_296 ) ;
if ( V_284 && V_61 == 0 ) {
struct V_21 * V_297 ;
F_132 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_297 = F_36 ( V_32 ) ;
if ( V_2 -> V_12 && V_286 == V_2 -> V_40 &&
V_22 == V_297 && V_297 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
! ( V_43 -> V_77 . V_68 & V_151 ) &&
! F_61 ( V_22 ) &&
F_92 ( V_22 ) == 0 )
F_68 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_196:
if ( V_285 )
F_132 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static int F_148 ( struct V_299 * V_299 , struct V_32 * V_32 )
{
const unsigned V_7 = F_32 ( V_299 ) ;
struct V_33 * V_34 ;
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_232 ;
if ( ! V_2 ) {
F_149 ( L_37 ) ;
return - V_60 ;
}
V_34 = F_67 ( sizeof( * V_34 ) , V_75 ) ;
if ( ! V_34 )
return - V_110 ;
V_34 -> V_2 = V_2 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_76 ( V_87 ) ) {
F_39 ( V_2 -> V_9 , L_38 ) ;
V_232 = - V_60 ;
goto V_196;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_150 ( V_2 -> V_13 -> V_10 ) ) {
V_232 = - V_300 ;
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
V_32 -> V_35 = V_34 ;
F_31 ( V_32 ) ;
V_232 = 0 ;
V_196:
F_19 ( & V_2 -> V_5 ) ;
if ( V_232 ) {
F_11 ( V_2 ) ;
F_10 ( V_34 ) ;
}
return V_232 ;
}
static int F_151 ( int V_301 , struct V_32 * V_32 , int V_302 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
return F_152 ( V_301 , V_32 , V_302 , & V_2 -> V_303 ) ;
}
static int F_153 ( struct V_299 * V_299 , struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 = NULL ;
int V_15 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_83 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
V_22 = & V_2 -> V_83 [ V_15 ] ;
if ( V_22 -> V_47 == V_32 )
F_72 ( V_2 , V_22 ) ;
if ( V_22 -> V_122 == V_32 )
V_22 -> V_122 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_304 )
V_2 -> V_304 ( V_2 ) ;
F_18 ( V_2 -> V_13 -> V_10 ) ;
}
V_2 -> V_14 -- ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
F_10 ( V_34 ) ;
return 0 ;
}
void F_154 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
unsigned int V_305 ;
int V_306 = 0 ;
unsigned long V_68 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
V_305 = V_43 -> V_305 ;
V_43 -> V_305 = 0 ;
if ( ! F_62 ( V_22 ) ) {
F_56 ( & V_22 -> V_69 , V_68 ) ;
return;
}
if ( V_305 & V_226 )
F_52 ( V_22 , V_70 ) ;
if ( V_305 & V_307 )
F_53 ( V_22 , V_71 ) ;
if ( V_43 -> V_224 & V_305 ) {
F_155 ( & V_43 -> V_79 ) ;
V_306 = V_43 -> V_77 . V_68 & V_151 ? V_308 : V_309 ;
}
F_56 ( & V_22 -> V_69 , V_68 ) ;
if ( V_306 )
F_156 ( & V_2 -> V_303 , V_310 , V_306 ) ;
}
struct V_1 * F_157 ( struct V_26 * V_311 )
{
struct V_1 * V_2 ;
struct V_26 * V_54 ;
unsigned V_15 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return F_158 ( - V_110 ) ;
F_1 ( V_2 ) ;
F_159 ( V_2 , V_311 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_311 ? V_93 : 0 ;
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
F_71 ( V_311 ,
L_39 ) ;
return F_158 ( - V_48 ) ;
}
V_2 -> V_7 = V_15 ;
V_54 = F_160 ( V_19 , V_311 ,
F_24 ( V_20 , V_15 ) , NULL , L_40 , V_15 ) ;
if ( ! F_110 ( V_54 ) )
V_2 -> V_9 = F_161 ( V_54 ) ;
return V_2 ;
}
void F_162 ( struct V_26 * V_311 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_93 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_312 == V_311 ) {
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
struct V_1 * V_2 = V_22 -> V_26 ;
struct V_26 * V_54 ;
unsigned V_15 ;
F_16 ( & V_24 ) ;
for ( V_15 = 0 ; V_15 < V_313 ; ++ V_15 ) {
if ( ! V_25 [ V_15 ] ) {
V_25 [ V_15 ] = V_22 ;
break;
}
}
F_19 ( & V_24 ) ;
if ( V_15 == V_313 ) {
F_71 ( V_2 -> V_9 ,
L_41 ) ;
return - V_48 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_54 = F_160 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_42 ,
V_2 -> V_7 , V_22 -> V_52 ) ;
if ( ! F_110 ( V_54 ) )
V_22 -> V_9 = V_54 ;
return 0 ;
}
void F_164 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( ! V_22 )
return;
if ( V_22 -> V_7 < V_23 ||
V_22 -> V_7 >= V_314 )
return;
V_15 = V_22 -> V_7 - V_23 ;
F_16 ( & V_24 ) ;
if ( V_22 == V_25 [ V_15 ] )
V_25 [ V_15 ] = NULL ;
F_19 ( & V_24 ) ;
if ( V_22 -> V_9 ) {
F_23 ( V_19 , F_24 ( V_20 , V_22 -> V_7 ) ) ;
V_22 -> V_9 = NULL ;
}
}
static void F_165 ( void )
{
struct V_1 * V_2 ;
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_2 = F_21 ( V_15 ) ;
F_22 ( V_2 ) ;
}
}
static int T_6 F_166 ( void )
{
int V_15 ;
int V_44 ;
F_167 ( L_43 V_315 L_44 ) ;
if ( V_93 < 0 ||
V_93 > V_23 ) {
F_168 ( L_45 ,
V_23 ) ;
return - V_64 ;
}
V_44 = F_169 ( F_24 ( V_20 , 0 ) ,
V_314 , L_46 ) ;
if ( V_44 )
return - V_198 ;
F_170 ( & V_316 , & V_317 ) ;
V_316 . V_318 = V_319 ;
V_44 = F_171 ( & V_316 . V_320 , L_46 ) ;
if ( V_44 ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_314 ) ;
return V_44 ;
}
if ( F_173 ( & V_316 , F_24 ( V_20 , 0 ) , V_314 ) ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_314 ) ;
return - V_198 ;
}
V_19 = F_174 ( V_319 , L_46 ) ;
if ( F_110 ( V_19 ) ) {
F_168 ( L_47 ) ;
F_175 ( & V_316 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_314 ) ;
return F_111 ( V_19 ) ;
}
V_19 -> V_321 = V_322 ;
F_176 () ;
for ( V_15 = 0 ; V_15 < V_93 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_157 ( NULL ) ;
if ( F_110 ( V_2 ) ) {
F_165 () ;
F_175 ( & V_316 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_314 ) ;
return F_111 ( V_2 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
return 0 ;
}
static void T_7 F_177 ( void )
{
F_165 () ;
F_178 ( V_19 ) ;
F_175 ( & V_316 ) ;
F_172 ( F_24 ( V_20 , 0 ) , V_314 ) ;
F_179 () ;
}
