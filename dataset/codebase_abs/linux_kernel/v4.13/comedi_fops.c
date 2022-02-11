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
static struct V_1 * F_21 ( unsigned int V_7 )
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
static struct V_21 *
F_25 ( const struct V_1 * V_2 , unsigned int V_7 )
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
static struct V_1 * F_26 ( unsigned int V_7 )
{
struct V_1 * V_2 ;
F_16 ( & V_17 ) ;
V_2 = F_13 ( V_18 [ V_7 ] ) ;
F_19 ( & V_17 ) ;
return V_2 ;
}
static struct V_1 *
F_27 ( unsigned int V_7 )
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
struct V_1 * F_28 ( unsigned int V_7 )
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
F_34 ( V_34 -> V_29 , V_36 ) ;
F_34 ( V_34 -> V_31 , V_37 ) ;
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
return F_37 ( V_34 -> V_29 ) ;
}
static struct V_21 * F_38 ( struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
F_35 ( V_32 ) ;
return F_37 ( V_34 -> V_31 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int V_41 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
int V_44 ;
if ( V_41 > V_43 -> V_45 )
return - V_46 ;
if ( V_22 -> V_47 ) {
F_40 ( V_2 -> V_9 ,
L_1 ) ;
return - V_48 ;
}
if ( F_41 ( V_22 ) ) {
F_40 ( V_2 -> V_9 ,
L_2 ) ;
return - V_48 ;
}
V_41 = ( V_41 + V_49 - 1 ) & V_50 ;
V_44 = F_42 ( V_2 , V_22 , V_41 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_22 -> V_51 ) {
V_44 = V_22 -> V_51 ( V_2 , V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
}
F_40 ( V_2 -> V_9 , L_3 ,
V_22 -> V_52 , V_43 -> V_53 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
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
static T_1 F_45 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_46 ( V_57 , 10 , & V_59 ) ;
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
static T_1 F_47 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
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
static T_1 F_48 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_46 ( V_57 , 10 , & V_59 ) ;
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
V_62 = F_39 ( V_2 , V_22 , V_59 ) ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static T_1 F_49 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
char * V_57 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
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
static T_1 F_50 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_46 ( V_57 , 10 , & V_59 ) ;
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
static T_1 F_51 ( struct V_26 * V_54 ,
struct V_55 * V_56 , char * V_57 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
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
static T_1 F_52 ( struct V_26 * V_54 ,
struct V_55 * V_56 ,
const char * V_57 , T_2 V_61 )
{
unsigned int V_7 = F_44 ( V_54 -> V_58 ) ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned int V_59 ;
int V_62 ;
V_62 = F_46 ( V_57 , 10 , & V_59 ) ;
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
V_62 = F_39 ( V_2 , V_22 , V_59 ) ;
else
V_62 = - V_64 ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return V_62 ? V_62 : V_61 ;
}
static void F_53 ( struct V_21 * V_22 ,
unsigned int V_65 )
{
V_22 -> V_66 &= ~ V_65 ;
}
static void F_54 ( struct V_21 * V_22 ,
unsigned int V_65 )
{
V_22 -> V_66 |= V_65 ;
}
static void F_55 ( struct V_21 * V_22 ,
unsigned int V_67 ,
unsigned int V_65 )
{
unsigned long V_68 ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
F_53 ( V_22 , V_67 ) ;
F_54 ( V_22 , V_65 & V_67 ) ;
F_57 ( & V_22 -> V_69 , V_68 ) ;
}
static unsigned int F_58 ( struct V_21 * V_22 )
{
return V_22 -> V_66 ;
}
static unsigned int F_59 ( struct V_21 * V_22 )
{
unsigned long V_68 ;
unsigned int V_66 ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
V_66 = F_58 ( V_22 ) ;
F_57 ( & V_22 -> V_69 , V_68 ) ;
return V_66 ;
}
static bool F_60 ( unsigned int V_66 )
{
return V_66 & V_70 ;
}
static bool F_61 ( unsigned int V_66 )
{
return V_66 & V_71 ;
}
bool F_62 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_59 ( V_22 ) ;
return F_60 ( V_66 ) ;
}
static bool F_63 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_58 ( V_22 ) ;
return F_60 ( V_66 ) ;
}
bool F_64 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_58 ( V_22 ) ;
return V_66 & V_72 ;
}
void F_65 ( struct V_21 * V_22 )
{
F_54 ( V_22 , V_72 ) ;
}
void * F_66 ( struct V_21 * V_22 , T_2 V_59 )
{
V_22 -> V_73 = F_67 ( V_59 , V_74 ) ;
if ( V_22 -> V_73 )
F_65 ( V_22 ) ;
return V_22 -> V_73 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
F_55 ( V_22 , V_70 , 0 ) ;
if ( V_43 ) {
F_69 ( V_22 ) ;
V_43 -> V_75 = NULL ;
F_10 ( V_43 -> V_76 . V_77 ) ;
V_43 -> V_76 . V_77 = NULL ;
V_22 -> V_47 = NULL ;
F_70 ( & V_43 -> V_78 ) ;
} else {
F_71 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_47 = NULL ;
}
}
static int F_72 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_79 = 0 ;
if ( F_62 ( V_22 ) && V_22 -> V_80 )
V_79 = V_22 -> V_80 ( V_2 , V_22 ) ;
F_68 ( V_2 , V_22 ) ;
return V_79 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
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
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
if ( V_22 -> V_47 )
return 1 ;
if ( V_22 -> V_43 && F_41 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_83 T_3 * V_84 )
{
struct V_83 V_85 ;
if ( ! F_76 ( V_86 ) )
return - V_46 ;
if ( ! V_84 ) {
if ( F_74 ( V_2 ) )
return - V_48 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_77 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_87 ;
V_85 . V_88 [ V_89 - 1 ] = 0 ;
if ( V_85 . V_90 [ V_91 ] ) {
F_78 ( V_2 -> V_9 ,
L_6 ) ;
return - V_64 ;
}
if ( V_2 -> V_7 >= V_92 )
return - V_48 ;
return F_79 ( V_2 , & V_85 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_93 T_3 * V_84 )
{
struct V_93 V_94 ;
struct V_42 * V_43 ;
struct V_21 * V_22 ;
int V_44 = 0 ;
if ( F_77 ( & V_94 , V_84 , sizeof( V_94 ) ) )
return - V_87 ;
if ( V_94 . V_95 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_94 . V_95 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
F_40 ( V_2 -> V_9 ,
L_7 ) ;
V_94 . V_59 = 0 ;
V_94 . V_96 = 0 ;
goto V_97;
}
if ( V_94 . V_96 ) {
if ( ! F_76 ( V_86 ) )
return - V_46 ;
V_43 -> V_45 = V_94 . V_96 ;
}
if ( V_94 . V_59 ) {
V_44 = F_39 ( V_2 , V_22 , V_94 . V_59 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_94 . V_59 = V_43 -> V_53 ;
V_94 . V_96 = V_43 -> V_45 ;
V_97:
if ( F_81 ( V_84 , & V_94 , sizeof( V_94 ) ) )
return - V_87 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_98 T_3 * V_84 ,
struct V_32 * V_32 )
{
struct V_21 * V_22 ;
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = V_101 ;
V_99 . V_102 = V_2 -> V_81 ;
F_83 ( V_99 . V_103 , V_2 -> V_13 -> V_103 , V_89 ) ;
F_83 ( V_99 . V_88 , V_2 -> V_88 , V_89 ) ;
V_22 = F_36 ( V_32 ) ;
if ( V_22 )
V_99 . V_104 = V_22 -> V_52 ;
else
V_99 . V_104 = - 1 ;
V_22 = F_38 ( V_32 ) ;
if ( V_22 )
V_99 . V_105 = V_22 -> V_52 ;
else
V_99 . V_105 = - 1 ;
if ( F_81 ( V_84 , & V_99 , sizeof( V_99 ) ) )
return - V_87 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_106 T_3 * V_84 , void * V_32 )
{
int V_79 , V_15 ;
struct V_106 * V_107 , * V_108 ;
struct V_21 * V_22 ;
V_107 = F_85 ( V_2 -> V_81 , sizeof( * V_107 ) , V_74 ) ;
if ( ! V_107 )
return - V_109 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
V_108 = V_107 + V_15 ;
V_108 -> type = V_22 -> type ;
V_108 -> V_110 = V_22 -> V_110 ;
V_108 -> V_111 = V_22 -> V_27 ;
if ( F_62 ( V_22 ) )
V_108 -> V_111 |= V_112 ;
#define F_86 5
V_108 -> V_113 = F_86 ;
V_108 -> V_114 = V_22 -> V_114 ;
V_108 -> V_115 = V_22 -> V_115 ;
if ( V_22 -> V_116 ) {
V_108 -> V_117 =
( V_15 << 24 ) | ( 0 << 16 ) | ( V_22 -> V_116 -> V_118 ) ;
} else {
V_108 -> V_117 = 0 ;
}
if ( V_22 -> V_47 )
V_108 -> V_111 |= V_119 ;
if ( V_22 -> V_47 == V_32 )
V_108 -> V_111 |= V_120 ;
if ( V_22 -> V_121 )
V_108 -> V_111 |= V_122 ;
if ( V_22 -> V_121 == V_32 )
V_108 -> V_111 |= V_123 ;
if ( ! V_22 -> V_115 && V_22 -> V_124 )
V_108 -> V_111 |= V_125 ;
if ( V_22 -> V_126 )
V_108 -> V_111 |= V_127 ;
if ( V_22 -> V_128 )
V_108 -> V_111 |= V_129 ;
if ( V_22 -> V_130 != & V_131 )
V_108 -> V_132 = V_133 ;
else
V_108 -> V_132 = V_134 ;
}
V_79 = F_81 ( V_84 , V_107 , V_2 -> V_81 * sizeof( * V_107 ) ) ;
F_10 ( V_107 ) ;
return V_79 ? - V_87 : 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_135 T_3 * V_84 )
{
struct V_21 * V_22 ;
struct V_135 V_85 ;
if ( F_77 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_87 ;
if ( V_85 . V_136 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_85 . V_136 ] ;
if ( V_85 . V_124 ) {
if ( V_22 -> V_115 || ! V_22 -> V_124 )
return - V_64 ;
if ( F_81 ( V_85 . V_124 , V_22 -> V_124 ,
V_22 -> V_110 * sizeof( unsigned int ) ) )
return - V_87 ;
}
if ( V_85 . V_137 )
return - V_64 ;
if ( V_85 . V_138 ) {
int V_15 ;
if ( ! V_22 -> V_126 )
return - V_64 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_110 ; V_15 ++ ) {
int V_139 ;
V_139 = ( V_2 -> V_7 << 28 ) | ( V_85 . V_136 << 24 ) | ( V_15 << 16 ) |
( V_22 -> V_126 [ V_15 ] -> V_118 ) ;
if ( F_88 ( V_139 , V_85 . V_138 + V_15 ) )
return - V_87 ;
}
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_140 T_3 * V_84 , void * V_32 )
{
struct V_140 V_141 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_66 ;
int V_44 = 0 ;
bool V_142 = false ;
if ( F_77 ( & V_141 , V_84 , sizeof( V_141 ) ) )
return - V_87 ;
if ( V_141 . V_95 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_141 . V_95 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 || V_22 -> V_47 != V_32 )
return - V_64 ;
V_66 = F_59 ( V_22 ) ;
if ( ! ( V_43 -> V_76 . V_68 & V_143 ) ) {
if ( V_141 . V_144 ) {
F_90 ( V_22 , V_141 . V_144 ) ;
V_141 . V_144 = F_91 ( V_22 , V_141 . V_144 ) ;
}
if ( F_92 ( V_22 ) == 0 &&
! F_60 ( V_66 ) &&
( V_141 . V_144 == 0 ||
! F_61 ( V_66 ) ) ) {
V_142 = true ;
if ( F_61 ( V_66 ) )
V_44 = - V_145 ;
}
V_141 . V_146 = 0 ;
} else {
if ( ! F_60 ( V_66 ) ) {
V_141 . V_146 = 0 ;
V_142 = true ;
if ( F_61 ( V_66 ) )
V_44 = - V_145 ;
} else if ( V_141 . V_146 ) {
F_93 ( V_22 , V_141 . V_146 ) ;
V_141 . V_146 =
F_94 ( V_22 , V_141 . V_146 ) ;
}
V_141 . V_144 = 0 ;
}
V_141 . V_147 = V_43 -> V_147 ;
V_141 . V_148 = V_43 -> V_148 ;
V_141 . V_149 = V_43 -> V_149 ;
V_141 . V_150 = V_43 -> V_150 ;
if ( V_142 )
F_68 ( V_2 , V_22 ) ;
if ( V_44 )
return V_44 ;
if ( F_81 ( V_84 , & V_141 , sizeof( V_141 ) ) )
return - V_87 ;
return 0 ;
}
static int F_95 ( struct V_151 * V_152 ,
unsigned int * V_153 )
{
if ( V_152 -> V_154 < 1 )
return - V_64 ;
switch ( V_153 [ 0 ] ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
if ( V_152 -> V_154 == 1 )
return 0 ;
break;
case V_159 :
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
if ( V_152 -> V_154 == 2 )
return 0 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
if ( V_152 -> V_154 == 3 )
return 0 ;
break;
case V_182 :
case V_183 :
if ( V_152 -> V_154 == 5 )
return 0 ;
break;
case V_184 :
if ( V_152 -> V_154 == 6 )
return 0 ;
break;
default:
F_96 ( L_8 ,
V_153 [ 0 ] ) ;
F_96 ( L_9 , V_185 , __FILE__ ) ;
F_96 ( L_10 , V_152 -> V_154 ) ;
return 0 ;
}
return - V_64 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_151 * V_152 ,
unsigned int * V_153 , void * V_32 )
{
struct V_21 * V_22 ;
int V_79 = 0 ;
int V_15 ;
if ( V_152 -> V_152 & V_186 ) {
switch ( V_152 -> V_152 ) {
case V_187 :
{
struct V_188 V_189 ;
if ( V_152 -> V_154 != 2 ) {
V_79 = - V_64 ;
break;
}
F_98 ( & V_189 ) ;
V_153 [ 0 ] = ( unsigned int ) V_189 . V_190 ;
V_153 [ 1 ] = V_189 . V_191 / V_192 ;
V_79 = 2 ;
break;
}
case V_193 :
if ( V_152 -> V_154 != 1 || V_153 [ 0 ] >= 100000 ) {
V_79 = - V_64 ;
break;
}
F_99 ( V_153 [ 0 ] / 1000 ) ;
V_79 = 1 ;
break;
case V_194 :
if ( V_152 -> V_154 != 1 ) {
V_79 = - V_64 ;
break;
}
if ( V_152 -> V_136 >= V_2 -> V_81 ) {
F_40 ( V_2 -> V_9 ,
L_11 ,
V_152 -> V_136 ) ;
V_79 = - V_64 ;
break;
}
V_22 = & V_2 -> V_82 [ V_152 -> V_136 ] ;
if ( ! V_22 -> V_43 ) {
F_40 ( V_2 -> V_9 , L_12 ) ;
V_79 = - V_64 ;
break;
}
if ( ! V_22 -> V_43 -> V_75 ) {
F_40 ( V_2 -> V_9 , L_13 ) ;
V_79 = - V_195 ;
break;
}
V_79 = V_22 -> V_43 -> V_75 ( V_2 , V_22 , V_153 [ 0 ] ) ;
if ( V_79 >= 0 )
V_79 = 1 ;
break;
default:
F_40 ( V_2 -> V_9 , L_14 ) ;
V_79 = - V_64 ;
break;
}
} else {
unsigned int V_115 ;
if ( V_152 -> V_136 >= V_2 -> V_81 ) {
F_40 ( V_2 -> V_9 , L_15 ,
V_152 -> V_136 ) ;
V_79 = - V_64 ;
goto V_196;
}
V_22 = & V_2 -> V_82 [ V_152 -> V_136 ] ;
if ( V_22 -> type == V_197 ) {
F_40 ( V_2 -> V_9 , L_11 ,
V_152 -> V_136 ) ;
V_79 = - V_198 ;
goto V_196;
}
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 ) {
F_40 ( V_2 -> V_9 , L_16 ) ;
V_79 = - V_199 ;
goto V_196;
}
V_79 = F_100 ( V_22 , 1 , & V_152 -> V_200 ) ;
if ( V_79 < 0 ) {
V_79 = - V_64 ;
F_40 ( V_2 -> V_9 , L_17 ) ;
goto V_196;
}
if ( V_22 -> V_47 ) {
V_79 = - V_48 ;
goto V_196;
}
V_22 -> V_47 = F_97 ;
switch ( V_152 -> V_152 ) {
case V_201 :
V_79 = V_22 -> V_202 ( V_2 , V_22 , V_152 , V_153 ) ;
if ( V_79 == - V_203 ) {
F_40 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_52 ) ;
}
break;
case V_204 :
V_115 = V_22 -> V_124
? V_22 -> V_124 [ F_101 ( V_152 -> V_200 ) ]
: V_22 -> V_115 ;
for ( V_15 = 0 ; V_15 < V_152 -> V_154 ; ++ V_15 ) {
if ( V_153 [ V_15 ] > V_115 ) {
V_79 = - V_64 ;
F_40 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_79 == 0 ) {
V_79 = V_22 -> V_205 ( V_2 , V_22 , V_152 , V_153 ) ;
if ( V_79 == - V_203 ) {
F_40 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_52 ) ;
}
}
break;
case V_206 :
if ( V_152 -> V_154 != 2 ) {
V_79 = - V_64 ;
} else {
unsigned int V_207 = V_153 [ 0 ] ;
unsigned int V_208 = 0 ;
if ( V_22 -> V_110 <= 32 ) {
V_208 = F_101 ( V_152 -> V_200 ) ;
if ( V_208 > 0 ) {
V_152 -> V_200 = 0 ;
V_153 [ 0 ] <<= V_208 ;
V_153 [ 1 ] <<= V_208 ;
}
}
V_79 = V_22 -> V_130 ( V_2 , V_22 , V_152 , V_153 ) ;
V_153 [ 0 ] = V_207 ;
if ( V_208 > 0 )
V_153 [ 1 ] >>= V_208 ;
}
break;
case V_209 :
V_79 = F_95 ( V_152 , V_153 ) ;
if ( V_79 )
break;
V_79 = V_22 -> V_210 ( V_2 , V_22 , V_152 , V_153 ) ;
break;
default:
V_79 = - V_64 ;
break;
}
V_22 -> V_47 = NULL ;
}
V_196:
return V_79 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_211 T_3 * V_84 , void * V_32 )
{
struct V_211 V_212 ;
struct V_151 * V_213 = NULL ;
unsigned int * V_153 = NULL ;
int V_15 = 0 ;
int V_79 = 0 ;
if ( F_77 ( & V_212 , V_84 , sizeof( V_212 ) ) )
return - V_87 ;
V_153 = F_103 ( V_214 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_153 ) {
V_79 = - V_109 ;
goto error;
}
V_213 = F_85 ( V_212 . V_215 , sizeof( * V_213 ) , V_74 ) ;
if ( ! V_213 ) {
V_79 = - V_109 ;
goto error;
}
if ( F_77 ( V_213 , V_212 . V_213 ,
sizeof( * V_213 ) * V_212 . V_215 ) ) {
F_40 ( V_2 -> V_9 , L_21 ) ;
V_79 = - V_87 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_212 . V_215 ; V_15 ++ ) {
if ( V_213 [ V_15 ] . V_154 > V_214 ) {
F_40 ( V_2 -> V_9 ,
L_22 ) ;
V_79 = - V_64 ;
goto error;
}
if ( V_213 [ V_15 ] . V_152 & V_216 ) {
if ( F_77 ( V_153 , V_213 [ V_15 ] . V_153 ,
V_213 [ V_15 ] . V_154 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_21 ) ;
V_79 = - V_87 ;
goto error;
}
}
V_79 = F_97 ( V_2 , V_213 + V_15 , V_153 , V_32 ) ;
if ( V_79 < 0 )
goto error;
if ( V_213 [ V_15 ] . V_152 & V_217 ) {
if ( F_81 ( V_213 [ V_15 ] . V_153 , V_153 ,
V_213 [ V_15 ] . V_154 * sizeof( unsigned int ) ) ) {
F_40 ( V_2 -> V_9 ,
L_23 ) ;
V_79 = - V_87 ;
goto error;
}
}
if ( F_104 () )
F_105 () ;
}
error:
F_10 ( V_213 ) ;
F_10 ( V_153 ) ;
if ( V_79 < 0 )
return V_79 ;
return V_15 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_151 T_3 * V_84 , void * V_32 )
{
struct V_151 V_152 ;
unsigned int * V_153 = NULL ;
int V_79 = 0 ;
V_153 = F_103 ( V_214 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_153 ) {
V_79 = - V_109 ;
goto error;
}
if ( F_77 ( & V_152 , V_84 , sizeof( V_152 ) ) ) {
V_79 = - V_87 ;
goto error;
}
if ( V_152 . V_154 > V_214 )
V_152 . V_154 = V_214 ;
if ( V_152 . V_152 & V_216 ) {
if ( F_77 ( V_153 ,
V_152 . V_153 ,
V_152 . V_154 * sizeof( unsigned int ) ) ) {
V_79 = - V_87 ;
goto error;
}
}
V_79 = F_97 ( V_2 , & V_152 , V_153 , V_32 ) ;
if ( V_79 < 0 )
goto error;
if ( V_152 . V_152 & V_217 ) {
if ( F_81 ( V_152 . V_153 ,
V_153 ,
V_152 . V_154 * sizeof( unsigned int ) ) ) {
V_79 = - V_87 ;
goto error;
}
}
V_79 = V_152 . V_154 ;
error:
F_10 ( V_153 ) ;
return V_79 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_84 ,
struct V_218 * V_76 )
{
struct V_21 * V_22 ;
if ( F_77 ( V_76 , V_84 , sizeof( * V_76 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
return - V_87 ;
}
if ( V_76 -> V_136 >= V_2 -> V_81 ) {
F_40 ( V_2 -> V_9 , L_25 , V_76 -> V_136 ) ;
return - V_60 ;
}
V_22 = & V_2 -> V_82 [ V_76 -> V_136 ] ;
if ( V_22 -> type == V_197 ) {
F_40 ( V_2 -> V_9 , L_26 ,
V_76 -> V_136 ) ;
return - V_198 ;
}
if ( ! V_22 -> V_128 || ! V_22 -> V_219 || ! V_22 -> V_43 ) {
F_40 ( V_2 -> V_9 ,
L_27 ,
V_76 -> V_136 ) ;
return - V_198 ;
}
if ( V_76 -> V_220 > V_22 -> V_114 ) {
F_40 ( V_2 -> V_9 , L_28 ,
V_76 -> V_220 , V_22 -> V_114 ) ;
return - V_64 ;
}
switch ( V_22 -> V_27 & ( V_28 | V_30 ) ) {
case V_28 :
V_76 -> V_68 &= ~ V_143 ;
break;
case V_30 :
V_76 -> V_68 |= V_143 ;
break;
default:
break;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_221 ,
struct V_218 * V_76 )
{
unsigned int * V_77 ;
int V_79 ;
V_76 -> V_77 = NULL ;
V_77 = F_109 ( V_221 ,
V_76 -> V_220 * sizeof( unsigned int ) ) ;
if ( F_110 ( V_77 ) )
return F_111 ( V_77 ) ;
V_79 = F_100 ( V_22 , V_76 -> V_220 , V_77 ) ;
if ( V_79 < 0 ) {
F_10 ( V_77 ) ;
return V_79 ;
}
V_76 -> V_77 = V_77 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_84 , void * V_32 )
{
struct V_218 V_76 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int T_3 * V_221 ;
int V_79 ;
V_79 = F_107 ( V_2 , V_84 , & V_76 ) ;
if ( V_79 )
return V_79 ;
V_221 = ( unsigned int T_3 * ) V_76 . V_77 ;
V_22 = & V_2 -> V_82 [ V_76 . V_136 ] ;
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 ) {
F_40 ( V_2 -> V_9 , L_29 ) ;
return - V_199 ;
}
if ( V_22 -> V_47 ) {
F_40 ( V_2 -> V_9 , L_30 ) ;
return - V_48 ;
}
if ( V_76 . V_220 < 1 ) {
F_40 ( V_2 -> V_9 , L_31 ,
V_76 . V_220 ) ;
return - V_64 ;
}
V_43 -> V_76 = V_76 ;
V_43 -> V_76 . V_153 = NULL ;
V_79 = F_108 ( V_2 , V_22 , V_221 , & V_43 -> V_76 ) ;
if ( V_79 )
goto V_222;
V_79 = V_22 -> V_219 ( V_2 , V_22 , & V_43 -> V_76 ) ;
if ( V_43 -> V_76 . V_68 & V_223 || V_79 ) {
F_40 ( V_2 -> V_9 , L_32 , V_79 ) ;
V_76 = V_43 -> V_76 ;
V_76 . V_77 = ( unsigned int V_224 * ) V_221 ;
V_76 . V_153 = NULL ;
if ( F_81 ( V_84 , & V_76 , sizeof( V_76 ) ) ) {
F_40 ( V_2 -> V_9 , L_33 ) ;
V_79 = - V_87 ;
goto V_222;
}
V_79 = - V_195 ;
goto V_222;
}
if ( ! V_43 -> V_53 ) {
V_79 = - V_109 ;
F_40 ( V_2 -> V_9 , L_34 ) ;
goto V_222;
}
F_69 ( V_22 ) ;
V_43 -> V_225 = V_226 | V_227 ;
if ( V_43 -> V_76 . V_68 & V_228 )
V_43 -> V_225 |= V_229 ;
F_55 ( V_22 , V_230 ,
V_70 ) ;
V_22 -> V_47 = V_32 ;
V_79 = V_22 -> V_128 ( V_2 , V_22 ) ;
if ( V_79 == 0 )
return 0 ;
V_222:
F_68 ( V_2 , V_22 ) ;
return V_79 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_218 T_3 * V_84 , void * V_32 )
{
struct V_218 V_76 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_221 ;
int V_79 ;
V_79 = F_107 ( V_2 , V_84 , & V_76 ) ;
if ( V_79 )
return V_79 ;
V_221 = ( unsigned int T_3 * ) V_76 . V_77 ;
V_22 = & V_2 -> V_82 [ V_76 . V_136 ] ;
if ( V_221 ) {
V_79 = F_108 ( V_2 , V_22 , V_221 , & V_76 ) ;
if ( V_79 )
return V_79 ;
}
V_79 = V_22 -> V_219 ( V_2 , V_22 , & V_76 ) ;
F_10 ( V_76 . V_77 ) ;
V_76 . V_77 = ( unsigned int V_224 * ) V_221 ;
if ( F_81 ( V_84 , & V_76 , sizeof( V_76 ) ) ) {
F_40 ( V_2 -> V_9 , L_24 ) ;
V_79 = - V_87 ;
}
return V_79 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
int V_79 = 0 ;
unsigned long V_68 ;
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
if ( V_22 -> V_47 || V_22 -> V_121 )
V_79 = - V_48 ;
else
V_22 -> V_121 = V_32 ;
F_57 ( & V_22 -> V_69 , V_68 ) ;
return V_79 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
if ( V_22 -> V_47 )
return - V_48 ;
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 )
return - V_199 ;
if ( V_22 -> V_121 == V_32 )
V_22 -> V_121 = NULL ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
if ( ! V_22 -> V_43 )
return - V_64 ;
if ( ! V_22 -> V_47 )
return 0 ;
if ( V_22 -> V_47 != V_32 )
return - V_48 ;
return F_72 ( V_2 , V_22 ) ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
if ( ! V_22 -> V_47 )
return 0 ;
if ( V_22 -> V_47 != V_32 )
return - V_48 ;
if ( V_22 -> V_231 )
return V_22 -> V_231 ( V_2 , V_22 ) ;
return - V_64 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned long V_84 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_232 , * V_233 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_233 = & V_2 -> V_82 [ V_84 ] ;
V_232 = F_36 ( V_32 ) ;
if ( V_232 == V_233 )
return 0 ;
if ( ! ( V_233 -> V_27 & V_28 ) )
return - V_64 ;
if ( V_232 && V_232 -> V_47 == V_32 && V_232 -> V_43 &&
! ( V_232 -> V_43 -> V_76 . V_68 & V_143 ) )
return - V_48 ;
F_34 ( V_34 -> V_29 , V_233 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , unsigned long V_84 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_232 , * V_233 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_233 = & V_2 -> V_82 [ V_84 ] ;
V_232 = F_38 ( V_32 ) ;
if ( V_232 == V_233 )
return 0 ;
if ( ! ( V_233 -> V_27 & V_30 ) )
return - V_64 ;
if ( V_232 && V_232 -> V_47 == V_32 && V_232 -> V_43 &&
( V_232 -> V_43 -> V_76 . V_68 & V_143 ) )
return - V_48 ;
F_34 ( V_34 -> V_31 , V_233 ) ;
return 0 ;
}
static long F_120 ( struct V_32 * V_32 , unsigned int V_76 ,
unsigned long V_84 )
{
unsigned int V_7 = F_32 ( F_33 ( V_32 ) ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_234 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_76 == V_235 ) {
if ( V_7 >= V_23 ) {
V_234 = - V_236 ;
goto V_237;
}
V_234 = F_75 ( V_2 ,
(struct V_83 T_3 * ) V_84 ) ;
if ( V_234 == 0 ) {
if ( V_84 == 0 &&
V_2 -> V_7 >= V_92 ) {
if ( F_20 ( V_2 ) ) {
F_19 ( & V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return V_234 ;
}
}
}
goto V_237;
}
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_234 = - V_60 ;
goto V_237;
}
switch ( V_76 ) {
case V_238 :
V_234 = F_80 ( V_2 ,
(struct V_93 T_3 * ) V_84 ) ;
break;
case V_239 :
V_234 = F_82 ( V_2 , (struct V_98 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_240 :
V_234 = F_84 ( V_2 ,
(struct V_106 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_241 :
V_234 = F_87 ( V_2 , ( void T_3 * ) V_84 ) ;
break;
case V_242 :
V_234 = F_121 ( V_2 , ( void T_3 * ) V_84 ) ;
break;
case V_243 :
V_234 = F_89 ( V_2 ,
(struct V_140 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_244 :
V_234 = F_114 ( V_2 , V_84 , V_32 ) ;
break;
case V_245 :
V_234 = F_115 ( V_2 , V_84 , V_32 ) ;
break;
case V_246 :
V_234 = F_116 ( V_2 , V_84 , V_32 ) ;
break;
case V_247 :
V_234 = F_112 ( V_2 , (struct V_218 T_3 * ) V_84 , V_32 ) ;
break;
case V_248 :
V_234 = F_113 ( V_2 , (struct V_218 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_249 :
V_234 = F_102 ( V_2 ,
(struct V_211 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_250 :
V_234 = F_106 ( V_2 , (struct V_151 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_251 :
V_234 = F_117 ( V_2 , V_84 , V_32 ) ;
break;
case V_252 :
V_234 = F_118 ( V_2 , V_84 , V_32 ) ;
break;
case V_253 :
V_234 = F_119 ( V_2 , V_84 , V_32 ) ;
break;
default:
V_234 = - V_236 ;
break;
}
V_237:
F_19 ( & V_2 -> V_5 ) ;
return V_234 ;
}
static void F_122 ( struct V_254 * V_255 )
{
struct V_256 * V_257 ;
V_257 = V_255 -> V_258 ;
F_123 ( V_257 ) ;
}
static void F_124 ( struct V_254 * V_255 )
{
struct V_256 * V_257 ;
V_257 = V_255 -> V_258 ;
F_125 ( V_257 ) ;
}
static int F_126 ( struct V_254 * V_259 , unsigned long V_260 ,
void * V_57 , int V_261 , int V_262 )
{
struct V_256 * V_257 = V_259 -> V_258 ;
unsigned long V_263 =
V_260 - V_259 -> V_264 + ( V_259 -> V_265 << V_266 ) ;
if ( V_261 < 0 )
return - V_64 ;
if ( V_261 > V_259 -> V_267 - V_260 )
V_261 = V_259 -> V_267 - V_260 ;
return F_127 ( V_257 , V_263 , V_57 , V_261 , V_262 ) ;
}
static int F_128 ( struct V_32 * V_32 , struct V_254 * V_259 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
struct V_256 * V_257 = NULL ;
unsigned long V_268 = V_259 -> V_264 ;
unsigned long V_59 ;
int V_269 ;
int V_15 ;
int V_44 ;
if ( ! F_129 ( & V_2 -> V_6 ) )
return - V_195 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_237;
}
if ( V_259 -> V_270 & V_271 )
V_22 = F_38 ( V_32 ) ;
else
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 ) {
V_44 = - V_64 ;
goto V_237;
}
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
V_44 = - V_64 ;
goto V_237;
}
if ( V_259 -> V_265 != 0 ) {
F_40 ( V_2 -> V_9 , L_36 ) ;
V_44 = - V_64 ;
goto V_237;
}
V_59 = V_259 -> V_267 - V_259 -> V_264 ;
if ( V_59 > V_43 -> V_53 ) {
V_44 = - V_87 ;
goto V_237;
}
if ( F_130 ( V_59 ) ) {
V_44 = - V_87 ;
goto V_237;
}
V_269 = F_131 ( V_259 ) ;
V_257 = F_132 ( V_22 ) ;
if ( ! V_257 || V_269 > V_257 -> V_269 ) {
V_44 = - V_64 ;
goto V_237;
}
for ( V_15 = 0 ; V_15 < V_269 ; ++ V_15 ) {
struct V_272 * V_57 = & V_257 -> V_273 [ V_15 ] ;
if ( F_133 ( V_259 , V_268 ,
F_134 ( F_135 ( V_57 -> V_274 ) ) ,
V_49 , V_275 ) ) {
V_44 = - V_195 ;
goto V_237;
}
V_268 += V_49 ;
}
V_259 -> V_276 = & V_277 ;
V_259 -> V_258 = V_257 ;
V_259 -> V_276 -> V_278 ( V_259 ) ;
V_44 = 0 ;
V_237:
F_136 ( & V_2 -> V_6 ) ;
F_125 ( V_257 ) ;
return V_44 ;
}
static unsigned int F_137 ( struct V_32 * V_32 , T_4 * V_279 )
{
unsigned int V_67 = 0 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 , * V_280 ;
F_138 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
goto V_237;
}
V_22 = F_36 ( V_32 ) ;
V_280 = V_22 ;
if ( V_22 && V_22 -> V_43 ) {
F_139 ( V_32 , & V_22 -> V_43 -> V_78 , V_279 ) ;
if ( V_22 -> V_47 != V_32 || ! F_62 ( V_22 ) ||
( V_22 -> V_43 -> V_76 . V_68 & V_143 ) ||
F_92 ( V_22 ) > 0 )
V_67 |= V_281 | V_282 ;
}
V_22 = F_38 ( V_32 ) ;
if ( V_22 && V_22 -> V_43 ) {
unsigned int V_283 = F_140 ( V_22 ) ;
if ( V_22 != V_280 )
F_139 ( V_32 , & V_22 -> V_43 -> V_78 , V_279 ) ;
if ( V_22 -> V_47 != V_32 || ! F_62 ( V_22 ) ||
! ( V_22 -> V_43 -> V_76 . V_68 & V_143 ) ||
F_141 ( V_22 ) >= V_283 )
V_67 |= V_284 | V_285 ;
}
V_237:
F_136 ( & V_2 -> V_6 ) ;
return V_67 ;
}
static T_1 F_142 ( struct V_32 * V_32 , const char T_3 * V_57 ,
T_2 V_286 , T_5 * V_263 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_154 , V_287 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_143 ( V_279 , V_288 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
bool V_142 = false ;
bool V_289 ;
unsigned int V_290 ;
F_138 ( & V_2 -> V_6 ) ;
V_289 = true ;
V_290 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_196;
}
V_22 = F_38 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_198 ;
goto V_196;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ! ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
goto V_196;
}
F_144 ( & V_43 -> V_78 , & V_279 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned int V_66 ;
unsigned int V_291 , V_292 , V_293 ;
F_145 ( V_294 ) ;
V_66 = F_59 ( V_22 ) ;
if ( ! F_60 ( V_66 ) ) {
if ( F_61 ( V_66 ) )
V_44 = - V_145 ;
if ( V_44 || V_286 )
V_142 = true ;
break;
}
if ( V_286 == 0 )
break;
F_93 ( V_22 , V_43 -> V_53 ) ;
V_287 = F_146 ( V_22 ) ;
V_154 = F_147 ( T_2 , V_287 , V_286 ) ;
if ( V_154 == 0 ) {
if ( V_32 -> V_295 & V_296 ) {
V_44 = - V_195 ;
break;
}
F_105 () ;
if ( F_148 ( V_288 ) ) {
V_44 = - V_297 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
! ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
F_145 ( V_298 ) ;
V_291 = V_43 -> V_148 ;
V_292 = F_149 ( V_154 , V_43 -> V_53 - V_291 ) ;
V_293 = V_154 - V_292 ;
V_287 = F_77 ( V_43 -> V_299 + V_291 , V_57 , V_292 ) ;
if ( V_287 )
V_287 += V_293 ;
else if ( V_293 )
V_287 = F_77 ( V_43 -> V_299 , V_57 + V_292 , V_293 ) ;
if ( V_287 ) {
V_154 -= V_287 ;
V_44 = - V_87 ;
}
F_94 ( V_22 , V_154 ) ;
V_61 += V_154 ;
V_286 -= V_154 ;
V_57 += V_154 ;
}
F_150 ( & V_43 -> V_78 , & V_279 ) ;
F_145 ( V_298 ) ;
if ( V_142 && V_61 == 0 ) {
struct V_21 * V_300 ;
F_136 ( & V_2 -> V_6 ) ;
V_289 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_300 = F_38 ( V_32 ) ;
if ( V_2 -> V_12 && V_290 == V_2 -> V_40 &&
V_22 == V_300 && V_300 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
( V_43 -> V_76 . V_68 & V_143 ) &&
! F_62 ( V_22 ) )
F_68 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_196:
if ( V_289 )
F_136 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static T_1 F_151 ( struct V_32 * V_32 , char T_3 * V_57 , T_2 V_286 ,
T_5 * V_263 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_154 , V_287 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_143 ( V_279 , V_288 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned int V_290 ;
bool V_142 = false ;
bool V_289 ;
F_138 ( & V_2 -> V_6 ) ;
V_289 = true ;
V_290 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_40 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_196;
}
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_198 ;
goto V_196;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
goto V_196;
}
F_144 ( & V_43 -> V_78 , & V_279 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned int V_301 , V_292 , V_293 ;
F_145 ( V_294 ) ;
V_287 = F_92 ( V_22 ) ;
V_154 = F_147 ( T_2 , V_287 , V_286 ) ;
if ( V_154 == 0 ) {
unsigned int V_66 =
F_59 ( V_22 ) ;
if ( ! F_60 ( V_66 ) ) {
if ( F_61 ( V_66 ) )
V_44 = - V_145 ;
if ( V_44 || V_286 )
V_142 = true ;
break;
}
if ( V_286 == 0 )
break;
if ( V_32 -> V_295 & V_296 ) {
V_44 = - V_195 ;
break;
}
F_105 () ;
if ( F_148 ( V_288 ) ) {
V_44 = - V_297 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
F_145 ( V_298 ) ;
V_301 = V_43 -> V_150 ;
V_292 = F_149 ( V_154 , V_43 -> V_53 - V_301 ) ;
V_293 = V_154 - V_292 ;
V_287 = F_81 ( V_57 , V_43 -> V_299 + V_301 , V_292 ) ;
if ( V_287 )
V_287 += V_293 ;
else if ( V_293 )
V_287 = F_81 ( V_57 + V_292 , V_43 -> V_299 , V_293 ) ;
if ( V_287 ) {
V_154 -= V_287 ;
V_44 = - V_87 ;
}
F_90 ( V_22 , V_154 ) ;
F_91 ( V_22 , V_154 ) ;
V_61 += V_154 ;
V_286 -= V_154 ;
V_57 += V_154 ;
}
F_150 ( & V_43 -> V_78 , & V_279 ) ;
F_145 ( V_298 ) ;
if ( V_142 && V_61 == 0 ) {
struct V_21 * V_300 ;
F_136 ( & V_2 -> V_6 ) ;
V_289 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_300 = F_36 ( V_32 ) ;
if ( V_2 -> V_12 && V_290 == V_2 -> V_40 &&
V_22 == V_300 && V_300 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
! ( V_43 -> V_76 . V_68 & V_143 ) &&
! F_62 ( V_22 ) &&
F_92 ( V_22 ) == 0 )
F_68 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_196:
if ( V_289 )
F_136 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static int F_152 ( struct V_302 * V_302 , struct V_32 * V_32 )
{
const unsigned int V_7 = F_32 ( V_302 ) ;
struct V_33 * V_34 ;
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_234 ;
if ( ! V_2 ) {
F_153 ( L_37 ) ;
return - V_60 ;
}
V_34 = F_67 ( sizeof( * V_34 ) , V_74 ) ;
if ( ! V_34 )
return - V_109 ;
V_34 -> V_2 = V_2 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_76 ( V_86 ) ) {
F_40 ( V_2 -> V_9 , L_38 ) ;
V_234 = - V_60 ;
goto V_196;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_154 ( V_2 -> V_13 -> V_10 ) ) {
V_234 = - V_303 ;
goto V_196;
}
if ( V_2 -> V_278 ) {
V_234 = V_2 -> V_278 ( V_2 ) ;
if ( V_234 < 0 ) {
F_18 ( V_2 -> V_13 -> V_10 ) ;
goto V_196;
}
}
}
V_2 -> V_14 ++ ;
V_32 -> V_35 = V_34 ;
F_31 ( V_32 ) ;
V_234 = 0 ;
V_196:
F_19 ( & V_2 -> V_5 ) ;
if ( V_234 ) {
F_11 ( V_2 ) ;
F_10 ( V_34 ) ;
}
return V_234 ;
}
static int F_155 ( int V_304 , struct V_32 * V_32 , int V_305 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
return F_156 ( V_304 , V_32 , V_305 , & V_2 -> V_306 ) ;
}
static int F_157 ( struct V_302 * V_302 , struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 = NULL ;
int V_15 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_82 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
if ( V_22 -> V_47 == V_32 )
F_72 ( V_2 , V_22 ) ;
if ( V_22 -> V_121 == V_32 )
V_22 -> V_121 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_307 )
V_2 -> V_307 ( V_2 ) ;
F_18 ( V_2 -> V_13 -> V_10 ) ;
}
V_2 -> V_14 -- ;
F_19 ( & V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
F_10 ( V_34 ) ;
return 0 ;
}
void F_158 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
unsigned int V_308 ;
int V_309 = 0 ;
unsigned long V_68 ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
V_308 = V_43 -> V_308 ;
V_43 -> V_308 = 0 ;
if ( ! F_63 ( V_22 ) ) {
F_57 ( & V_22 -> V_69 , V_68 ) ;
return;
}
if ( V_308 & V_227 )
F_53 ( V_22 , V_70 ) ;
if ( V_308 & V_310 )
F_54 ( V_22 , V_71 ) ;
if ( V_43 -> V_225 & V_308 ) {
F_159 ( & V_43 -> V_78 ) ;
V_309 = V_43 -> V_76 . V_68 & V_143 ? V_311 : V_312 ;
}
F_57 ( & V_22 -> V_69 , V_68 ) ;
if ( V_309 )
F_160 ( & V_2 -> V_306 , V_313 , V_309 ) ;
}
struct V_1 * F_161 ( struct V_26 * V_314 )
{
struct V_1 * V_2 ;
struct V_26 * V_54 ;
unsigned int V_15 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return F_162 ( - V_109 ) ;
F_1 ( V_2 ) ;
F_163 ( V_2 , V_314 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_314 ? V_92 : 0 ;
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
F_71 ( V_314 ,
L_39 ) ;
return F_162 ( - V_48 ) ;
}
V_2 -> V_7 = V_15 ;
V_54 = F_164 ( V_19 , V_314 ,
F_24 ( V_20 , V_15 ) , NULL , L_40 , V_15 ) ;
if ( ! F_110 ( V_54 ) )
V_2 -> V_9 = F_165 ( V_54 ) ;
return V_2 ;
}
void F_166 ( struct V_26 * V_314 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_92 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_315 == V_314 ) {
V_18 [ V_7 ] = NULL ;
F_19 ( & V_17 ) ;
F_22 ( V_2 ) ;
break;
}
F_19 ( & V_17 ) ;
}
}
int F_167 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
struct V_26 * V_54 ;
unsigned int V_15 ;
F_16 ( & V_24 ) ;
for ( V_15 = 0 ; V_15 < V_316 ; ++ V_15 ) {
if ( ! V_25 [ V_15 ] ) {
V_25 [ V_15 ] = V_22 ;
break;
}
}
F_19 ( & V_24 ) ;
if ( V_15 == V_316 ) {
F_71 ( V_2 -> V_9 ,
L_41 ) ;
return - V_48 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_54 = F_164 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_42 ,
V_2 -> V_7 , V_22 -> V_52 ) ;
if ( ! F_110 ( V_54 ) )
V_22 -> V_9 = V_54 ;
return 0 ;
}
void F_168 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( ! V_22 )
return;
if ( V_22 -> V_7 < V_23 ||
V_22 -> V_7 >= V_317 )
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
static void F_169 ( void )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_2 = F_21 ( V_15 ) ;
F_22 ( V_2 ) ;
}
}
static int T_6 F_170 ( void )
{
int V_15 ;
int V_44 ;
F_171 ( L_43 V_318 L_44 ) ;
if ( V_92 > V_23 ) {
F_172 ( L_45 ,
V_23 ) ;
return - V_64 ;
}
V_44 = F_173 ( F_24 ( V_20 , 0 ) ,
V_317 , L_46 ) ;
if ( V_44 )
return V_44 ;
F_174 ( & V_319 , & V_320 ) ;
V_319 . V_321 = V_322 ;
V_44 = F_175 ( & V_319 . V_323 , L_46 ) ;
if ( V_44 )
goto V_324;
V_44 = F_176 ( & V_319 , F_24 ( V_20 , 0 ) ,
V_317 ) ;
if ( V_44 )
goto V_324;
V_19 = F_177 ( V_322 , L_46 ) ;
if ( F_110 ( V_19 ) ) {
V_44 = F_111 ( V_19 ) ;
F_172 ( L_47 ) ;
goto V_325;
}
V_19 -> V_326 = V_327 ;
for ( V_15 = 0 ; V_15 < V_92 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_161 ( NULL ) ;
if ( F_110 ( V_2 ) ) {
V_44 = F_111 ( V_2 ) ;
goto V_328;
}
F_19 ( & V_2 -> V_5 ) ;
}
F_178 () ;
return 0 ;
V_328:
F_169 () ;
F_179 ( V_19 ) ;
V_325:
F_180 ( & V_319 ) ;
V_324:
F_181 ( F_24 ( V_20 , 0 ) , V_317 ) ;
return V_44 ;
}
static void T_7 F_182 ( void )
{
F_169 () ;
F_179 ( V_19 ) ;
F_180 ( & V_319 ) ;
F_181 ( F_24 ( V_20 , 0 ) , V_317 ) ;
F_183 () ;
}
