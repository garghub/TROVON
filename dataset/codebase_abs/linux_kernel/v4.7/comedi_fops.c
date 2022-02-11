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
struct V_21 * V_22 ,
unsigned int V_41 )
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
unsigned int V_65 )
{
V_22 -> V_66 &= ~ V_65 ;
}
static void F_53 ( struct V_21 * V_22 ,
unsigned int V_65 )
{
V_22 -> V_66 |= V_65 ;
}
static void F_54 ( struct V_21 * V_22 ,
unsigned int V_67 ,
unsigned int V_65 )
{
unsigned long V_68 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
F_52 ( V_22 , V_67 ) ;
F_53 ( V_22 , V_65 & V_67 ) ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
}
static unsigned int F_57 ( struct V_21 * V_22 )
{
return V_22 -> V_66 ;
}
static unsigned int F_58 ( struct V_21 * V_22 )
{
unsigned long V_68 ;
unsigned int V_66 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
V_66 = F_57 ( V_22 ) ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
return V_66 ;
}
static bool F_59 ( unsigned int V_66 )
{
return V_66 & V_70 ;
}
static bool F_60 ( unsigned int V_66 )
{
return V_66 & V_71 ;
}
bool F_61 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_58 ( V_22 ) ;
return F_59 ( V_66 ) ;
}
static bool F_62 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_57 ( V_22 ) ;
return F_59 ( V_66 ) ;
}
bool F_63 ( struct V_21 * V_22 )
{
unsigned int V_66 = F_57 ( V_22 ) ;
return V_66 & V_72 ;
}
void F_64 ( struct V_21 * V_22 )
{
F_53 ( V_22 , V_72 ) ;
}
void * F_65 ( struct V_21 * V_22 , T_2 V_59 )
{
V_22 -> V_73 = F_66 ( V_59 , V_74 ) ;
if ( V_22 -> V_73 )
F_64 ( V_22 ) ;
return V_22 -> V_73 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
F_54 ( V_22 , V_70 , 0 ) ;
if ( V_43 ) {
F_68 ( V_22 ) ;
V_43 -> V_75 = NULL ;
F_10 ( V_43 -> V_76 . V_77 ) ;
V_43 -> V_76 . V_77 = NULL ;
V_22 -> V_47 = NULL ;
F_69 ( & V_43 -> V_78 ) ;
} else {
F_70 ( V_2 -> V_9 ,
L_5 ) ;
V_22 -> V_47 = NULL ;
}
}
static int F_71 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_79 = 0 ;
if ( F_61 ( V_22 ) && V_22 -> V_80 )
V_79 = V_22 -> V_80 ( V_2 , V_22 ) ;
F_67 ( V_2 , V_22 ) ;
return V_79 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
if ( V_22 -> V_43 )
F_71 ( V_2 , V_22 ) ;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_2 -> V_12 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
if ( V_22 -> V_47 )
return 1 ;
if ( V_22 -> V_43 && F_40 ( V_22 ) )
return 1 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_83 T_3 * V_84 )
{
struct V_83 V_85 ;
if ( ! F_75 ( V_86 ) )
return - V_46 ;
if ( ! V_84 ) {
if ( F_73 ( V_2 ) )
return - V_48 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = V_2 -> V_13 -> V_10 ;
F_17 ( V_2 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
if ( F_76 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_87 ;
V_85 . V_88 [ V_89 - 1 ] = 0 ;
if ( V_85 . V_90 [ V_91 ] ) {
F_77 ( V_2 -> V_9 ,
L_6 ) ;
return - V_64 ;
}
if ( V_2 -> V_7 >= V_92 )
return - V_48 ;
return F_78 ( V_2 , & V_85 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_93 T_3 * V_84 )
{
struct V_93 V_94 ;
struct V_42 * V_43 ;
struct V_21 * V_22 ;
int V_44 = 0 ;
if ( F_76 ( & V_94 , V_84 , sizeof( V_94 ) ) )
return - V_87 ;
if ( V_94 . V_95 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_94 . V_95 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
F_39 ( V_2 -> V_9 ,
L_7 ) ;
V_94 . V_59 = 0 ;
V_94 . V_96 = 0 ;
goto V_97;
}
if ( V_94 . V_96 ) {
if ( ! F_75 ( V_86 ) )
return - V_46 ;
V_43 -> V_45 = V_94 . V_96 ;
}
if ( V_94 . V_59 ) {
V_44 = F_38 ( V_2 , V_22 , V_94 . V_59 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_94 . V_59 = V_43 -> V_53 ;
V_94 . V_96 = V_43 -> V_45 ;
V_97:
if ( F_80 ( V_84 , & V_94 , sizeof( V_94 ) ) )
return - V_87 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_98 T_3 * V_84 ,
struct V_32 * V_32 )
{
struct V_21 * V_22 ;
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = V_101 ;
V_99 . V_102 = V_2 -> V_81 ;
F_82 ( V_99 . V_103 , V_2 -> V_13 -> V_103 , V_89 ) ;
F_82 ( V_99 . V_88 , V_2 -> V_88 , V_89 ) ;
V_22 = F_36 ( V_32 ) ;
if ( V_22 )
V_99 . V_104 = V_22 -> V_52 ;
else
V_99 . V_104 = - 1 ;
V_22 = F_37 ( V_32 ) ;
if ( V_22 )
V_99 . V_105 = V_22 -> V_52 ;
else
V_99 . V_105 = - 1 ;
if ( F_80 ( V_84 , & V_99 , sizeof( V_99 ) ) )
return - V_87 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_106 T_3 * V_84 , void * V_32 )
{
int V_79 , V_15 ;
struct V_106 * V_107 , * V_108 ;
struct V_21 * V_22 ;
V_107 = F_84 ( V_2 -> V_81 , sizeof( * V_107 ) , V_74 ) ;
if ( ! V_107 )
return - V_109 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_81 ; V_15 ++ ) {
V_22 = & V_2 -> V_82 [ V_15 ] ;
V_108 = V_107 + V_15 ;
V_108 -> type = V_22 -> type ;
V_108 -> V_110 = V_22 -> V_110 ;
V_108 -> V_111 = V_22 -> V_27 ;
if ( F_61 ( V_22 ) )
V_108 -> V_111 |= V_112 ;
#define F_85 5
V_108 -> V_113 = F_85 ;
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
V_79 = F_80 ( V_84 , V_107 , V_2 -> V_81 * sizeof( * V_107 ) ) ;
F_10 ( V_107 ) ;
return V_79 ? - V_87 : 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_135 T_3 * V_84 )
{
struct V_21 * V_22 ;
struct V_135 V_85 ;
if ( F_76 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_87 ;
if ( V_85 . V_136 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_85 . V_136 ] ;
if ( V_85 . V_124 ) {
if ( V_22 -> V_115 || ! V_22 -> V_124 )
return - V_64 ;
if ( F_80 ( V_85 . V_124 , V_22 -> V_124 ,
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
if ( F_87 ( V_139 , V_85 . V_138 + V_15 ) )
return - V_87 ;
}
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_140 T_3 * V_84 , void * V_32 )
{
struct V_140 V_141 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_66 ;
int V_44 = 0 ;
bool V_142 = false ;
if ( F_76 ( & V_141 , V_84 , sizeof( V_141 ) ) )
return - V_87 ;
if ( V_141 . V_95 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_141 . V_95 ] ;
V_43 = V_22 -> V_43 ;
if ( ! V_43 || V_22 -> V_47 != V_32 )
return - V_64 ;
V_66 = F_58 ( V_22 ) ;
if ( ! ( V_43 -> V_76 . V_68 & V_143 ) ) {
if ( V_141 . V_144 ) {
F_89 ( V_22 , V_141 . V_144 ) ;
V_141 . V_144 = F_90 ( V_22 , V_141 . V_144 ) ;
}
if ( F_91 ( V_22 ) == 0 &&
! F_59 ( V_66 ) &&
( V_141 . V_144 == 0 ||
! F_60 ( V_66 ) ) ) {
V_142 = true ;
if ( F_60 ( V_66 ) )
V_44 = - V_145 ;
}
V_141 . V_146 = 0 ;
} else {
if ( ! F_59 ( V_66 ) ) {
V_141 . V_146 = 0 ;
V_142 = true ;
if ( F_60 ( V_66 ) )
V_44 = - V_145 ;
} else if ( V_141 . V_146 ) {
F_92 ( V_22 , V_141 . V_146 ) ;
V_141 . V_146 =
F_93 ( V_22 , V_141 . V_146 ) ;
}
V_141 . V_144 = 0 ;
}
V_141 . V_147 = V_43 -> V_147 ;
V_141 . V_148 = V_43 -> V_148 ;
V_141 . V_149 = V_43 -> V_149 ;
V_141 . V_150 = V_43 -> V_150 ;
if ( V_142 )
F_67 ( V_2 , V_22 ) ;
if ( V_44 )
return V_44 ;
if ( F_80 ( V_84 , & V_141 , sizeof( V_141 ) ) )
return - V_87 ;
return 0 ;
}
static int F_94 ( struct V_151 * V_152 ,
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
F_95 ( L_8 ,
V_153 [ 0 ] ) ;
F_95 ( L_9 , V_185 , __FILE__ ) ;
F_95 ( L_10 , V_152 -> V_154 ) ;
return 0 ;
}
return - V_64 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_151 * V_152 ,
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
F_97 ( & V_189 ) ;
V_153 [ 0 ] = V_189 . V_190 ;
V_153 [ 1 ] = V_189 . V_191 ;
V_79 = 2 ;
break;
}
case V_192 :
if ( V_152 -> V_154 != 1 || V_153 [ 0 ] >= 100000 ) {
V_79 = - V_64 ;
break;
}
F_98 ( V_153 [ 0 ] / 1000 ) ;
V_79 = 1 ;
break;
case V_193 :
if ( V_152 -> V_154 != 1 ) {
V_79 = - V_64 ;
break;
}
if ( V_152 -> V_136 >= V_2 -> V_81 ) {
F_39 ( V_2 -> V_9 ,
L_11 ,
V_152 -> V_136 ) ;
V_79 = - V_64 ;
break;
}
V_22 = & V_2 -> V_82 [ V_152 -> V_136 ] ;
if ( ! V_22 -> V_43 ) {
F_39 ( V_2 -> V_9 , L_12 ) ;
V_79 = - V_64 ;
break;
}
if ( ! V_22 -> V_43 -> V_75 ) {
F_39 ( V_2 -> V_9 , L_13 ) ;
V_79 = - V_194 ;
break;
}
V_79 = V_22 -> V_43 -> V_75 ( V_2 , V_22 , V_153 [ 0 ] ) ;
if ( V_79 >= 0 )
V_79 = 1 ;
break;
default:
F_39 ( V_2 -> V_9 , L_14 ) ;
V_79 = - V_64 ;
break;
}
} else {
unsigned int V_115 ;
if ( V_152 -> V_136 >= V_2 -> V_81 ) {
F_39 ( V_2 -> V_9 , L_15 ,
V_152 -> V_136 ) ;
V_79 = - V_64 ;
goto V_195;
}
V_22 = & V_2 -> V_82 [ V_152 -> V_136 ] ;
if ( V_22 -> type == V_196 ) {
F_39 ( V_2 -> V_9 , L_11 ,
V_152 -> V_136 ) ;
V_79 = - V_197 ;
goto V_195;
}
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 ) {
F_39 ( V_2 -> V_9 , L_16 ) ;
V_79 = - V_198 ;
goto V_195;
}
V_79 = F_99 ( V_22 , 1 , & V_152 -> V_199 ) ;
if ( V_79 < 0 ) {
V_79 = - V_64 ;
F_39 ( V_2 -> V_9 , L_17 ) ;
goto V_195;
}
if ( V_22 -> V_47 ) {
V_79 = - V_48 ;
goto V_195;
}
V_22 -> V_47 = F_96 ;
switch ( V_152 -> V_152 ) {
case V_200 :
V_79 = V_22 -> V_201 ( V_2 , V_22 , V_152 , V_153 ) ;
if ( V_79 == - V_202 ) {
F_39 ( V_2 -> V_9 ,
L_18 ,
V_22 -> V_52 ) ;
}
break;
case V_203 :
V_115 = V_22 -> V_124
? V_22 -> V_124 [ F_100 ( V_152 -> V_199 ) ]
: V_22 -> V_115 ;
for ( V_15 = 0 ; V_15 < V_152 -> V_154 ; ++ V_15 ) {
if ( V_153 [ V_15 ] > V_115 ) {
V_79 = - V_64 ;
F_39 ( V_2 -> V_9 ,
L_19 ) ;
break;
}
}
if ( V_79 == 0 ) {
V_79 = V_22 -> V_204 ( V_2 , V_22 , V_152 , V_153 ) ;
if ( V_79 == - V_202 ) {
F_39 ( V_2 -> V_9 ,
L_20 ,
V_22 -> V_52 ) ;
}
}
break;
case V_205 :
if ( V_152 -> V_154 != 2 ) {
V_79 = - V_64 ;
} else {
unsigned int V_206 = V_153 [ 0 ] ;
unsigned int V_207 = 0 ;
if ( V_22 -> V_110 <= 32 ) {
V_207 = F_100 ( V_152 -> V_199 ) ;
if ( V_207 > 0 ) {
V_152 -> V_199 = 0 ;
V_153 [ 0 ] <<= V_207 ;
V_153 [ 1 ] <<= V_207 ;
}
}
V_79 = V_22 -> V_130 ( V_2 , V_22 , V_152 , V_153 ) ;
V_153 [ 0 ] = V_206 ;
if ( V_207 > 0 )
V_153 [ 1 ] >>= V_207 ;
}
break;
case V_208 :
V_79 = F_94 ( V_152 , V_153 ) ;
if ( V_79 )
break;
V_79 = V_22 -> V_209 ( V_2 , V_22 , V_152 , V_153 ) ;
break;
default:
V_79 = - V_64 ;
break;
}
V_22 -> V_47 = NULL ;
}
V_195:
return V_79 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_210 T_3 * V_84 , void * V_32 )
{
struct V_210 V_211 ;
struct V_151 * V_212 = NULL ;
unsigned int * V_153 = NULL ;
int V_15 = 0 ;
int V_79 = 0 ;
if ( F_76 ( & V_211 , V_84 , sizeof( V_211 ) ) )
return - V_87 ;
V_153 = F_102 ( V_213 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_153 ) {
V_79 = - V_109 ;
goto error;
}
V_212 = F_84 ( V_211 . V_214 , sizeof( * V_212 ) , V_74 ) ;
if ( ! V_212 ) {
V_79 = - V_109 ;
goto error;
}
if ( F_76 ( V_212 , V_211 . V_212 ,
sizeof( * V_212 ) * V_211 . V_214 ) ) {
F_39 ( V_2 -> V_9 , L_21 ) ;
V_79 = - V_87 ;
goto error;
}
for ( V_15 = 0 ; V_15 < V_211 . V_214 ; V_15 ++ ) {
if ( V_212 [ V_15 ] . V_154 > V_213 ) {
F_39 ( V_2 -> V_9 ,
L_22 ) ;
V_79 = - V_64 ;
goto error;
}
if ( V_212 [ V_15 ] . V_152 & V_215 ) {
if ( F_76 ( V_153 , V_212 [ V_15 ] . V_153 ,
V_212 [ V_15 ] . V_154 * sizeof( unsigned int ) ) ) {
F_39 ( V_2 -> V_9 ,
L_21 ) ;
V_79 = - V_87 ;
goto error;
}
}
V_79 = F_96 ( V_2 , V_212 + V_15 , V_153 , V_32 ) ;
if ( V_79 < 0 )
goto error;
if ( V_212 [ V_15 ] . V_152 & V_216 ) {
if ( F_80 ( V_212 [ V_15 ] . V_153 , V_153 ,
V_212 [ V_15 ] . V_154 * sizeof( unsigned int ) ) ) {
F_39 ( V_2 -> V_9 ,
L_23 ) ;
V_79 = - V_87 ;
goto error;
}
}
if ( F_103 () )
F_104 () ;
}
error:
F_10 ( V_212 ) ;
F_10 ( V_153 ) ;
if ( V_79 < 0 )
return V_79 ;
return V_15 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_151 T_3 * V_84 , void * V_32 )
{
struct V_151 V_152 ;
unsigned int * V_153 = NULL ;
int V_79 = 0 ;
V_153 = F_102 ( V_213 , sizeof( unsigned int ) , V_74 ) ;
if ( ! V_153 ) {
V_79 = - V_109 ;
goto error;
}
if ( F_76 ( & V_152 , V_84 , sizeof( V_152 ) ) ) {
V_79 = - V_87 ;
goto error;
}
if ( V_152 . V_154 > V_213 )
V_152 . V_154 = V_213 ;
if ( V_152 . V_152 & V_215 ) {
if ( F_76 ( V_153 ,
V_152 . V_153 ,
V_152 . V_154 * sizeof( unsigned int ) ) ) {
V_79 = - V_87 ;
goto error;
}
}
V_79 = F_96 ( V_2 , & V_152 , V_153 , V_32 ) ;
if ( V_79 < 0 )
goto error;
if ( V_152 . V_152 & V_216 ) {
if ( F_80 ( V_152 . V_153 ,
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
static int F_106 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_84 ,
struct V_217 * V_76 )
{
struct V_21 * V_22 ;
if ( F_76 ( V_76 , V_84 , sizeof( * V_76 ) ) ) {
F_39 ( V_2 -> V_9 , L_24 ) ;
return - V_87 ;
}
if ( V_76 -> V_136 >= V_2 -> V_81 ) {
F_39 ( V_2 -> V_9 , L_25 , V_76 -> V_136 ) ;
return - V_60 ;
}
V_22 = & V_2 -> V_82 [ V_76 -> V_136 ] ;
if ( V_22 -> type == V_196 ) {
F_39 ( V_2 -> V_9 , L_26 ,
V_76 -> V_136 ) ;
return - V_197 ;
}
if ( ! V_22 -> V_128 || ! V_22 -> V_218 || ! V_22 -> V_43 ) {
F_39 ( V_2 -> V_9 ,
L_27 ,
V_76 -> V_136 ) ;
return - V_197 ;
}
if ( V_76 -> V_219 > V_22 -> V_114 ) {
F_39 ( V_2 -> V_9 , L_28 ,
V_76 -> V_219 , V_22 -> V_114 ) ;
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
static int F_107 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int T_3 * V_220 ,
struct V_217 * V_76 )
{
unsigned int * V_77 ;
int V_79 ;
V_76 -> V_77 = NULL ;
V_77 = F_108 ( V_220 ,
V_76 -> V_219 * sizeof( unsigned int ) ) ;
if ( F_109 ( V_77 ) )
return F_110 ( V_77 ) ;
V_79 = F_99 ( V_22 , V_76 -> V_219 , V_77 ) ;
if ( V_79 < 0 ) {
F_10 ( V_77 ) ;
return V_79 ;
}
V_76 -> V_77 = V_77 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_84 , void * V_32 )
{
struct V_217 V_76 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int T_3 * V_220 ;
int V_79 ;
V_79 = F_106 ( V_2 , V_84 , & V_76 ) ;
if ( V_79 )
return V_79 ;
V_220 = ( unsigned int T_3 * ) V_76 . V_77 ;
V_22 = & V_2 -> V_82 [ V_76 . V_136 ] ;
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 ) {
F_39 ( V_2 -> V_9 , L_29 ) ;
return - V_198 ;
}
if ( V_22 -> V_47 ) {
F_39 ( V_2 -> V_9 , L_30 ) ;
return - V_48 ;
}
if ( V_76 . V_219 < 1 ) {
F_39 ( V_2 -> V_9 , L_31 ,
V_76 . V_219 ) ;
return - V_64 ;
}
V_43 -> V_76 = V_76 ;
V_43 -> V_76 . V_153 = NULL ;
V_79 = F_107 ( V_2 , V_22 , V_220 , & V_43 -> V_76 ) ;
if ( V_79 )
goto V_221;
V_79 = V_22 -> V_218 ( V_2 , V_22 , & V_43 -> V_76 ) ;
if ( V_43 -> V_76 . V_68 & V_222 || V_79 ) {
F_39 ( V_2 -> V_9 , L_32 , V_79 ) ;
V_76 = V_43 -> V_76 ;
V_76 . V_77 = ( unsigned int V_223 * ) V_220 ;
V_76 . V_153 = NULL ;
if ( F_80 ( V_84 , & V_76 , sizeof( V_76 ) ) ) {
F_39 ( V_2 -> V_9 , L_33 ) ;
V_79 = - V_87 ;
goto V_221;
}
V_79 = - V_194 ;
goto V_221;
}
if ( ! V_43 -> V_53 ) {
V_79 = - V_109 ;
F_39 ( V_2 -> V_9 , L_34 ) ;
goto V_221;
}
F_68 ( V_22 ) ;
V_43 -> V_224 = V_225 | V_226 ;
if ( V_43 -> V_76 . V_68 & V_227 )
V_43 -> V_224 |= V_228 ;
F_54 ( V_22 , V_229 ,
V_70 ) ;
V_22 -> V_47 = V_32 ;
V_79 = V_22 -> V_128 ( V_2 , V_22 ) ;
if ( V_79 == 0 )
return 0 ;
V_221:
F_67 ( V_2 , V_22 ) ;
return V_79 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_217 T_3 * V_84 , void * V_32 )
{
struct V_217 V_76 ;
struct V_21 * V_22 ;
unsigned int T_3 * V_220 ;
int V_79 ;
V_79 = F_106 ( V_2 , V_84 , & V_76 ) ;
if ( V_79 )
return V_79 ;
V_220 = ( unsigned int T_3 * ) V_76 . V_77 ;
V_22 = & V_2 -> V_82 [ V_76 . V_136 ] ;
if ( V_220 ) {
V_79 = F_107 ( V_2 , V_22 , V_220 , & V_76 ) ;
if ( V_79 )
return V_79 ;
}
V_79 = V_22 -> V_218 ( V_2 , V_22 , & V_76 ) ;
F_10 ( V_76 . V_77 ) ;
V_76 . V_77 = ( unsigned int V_223 * ) V_220 ;
if ( F_80 ( V_84 , & V_76 , sizeof( V_76 ) ) ) {
F_39 ( V_2 -> V_9 , L_24 ) ;
V_79 = - V_87 ;
}
return V_79 ;
}
static int F_113 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
int V_79 = 0 ;
unsigned long V_68 ;
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
if ( V_22 -> V_47 || V_22 -> V_121 )
V_79 = - V_48 ;
else
V_22 -> V_121 = V_32 ;
F_56 ( & V_22 -> V_69 , V_68 ) ;
return V_79 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned long V_84 ,
void * V_32 )
{
struct V_21 * V_22 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_22 = & V_2 -> V_82 [ V_84 ] ;
if ( V_22 -> V_47 )
return - V_48 ;
if ( V_22 -> V_121 && V_22 -> V_121 != V_32 )
return - V_198 ;
if ( V_22 -> V_121 == V_32 )
V_22 -> V_121 = NULL ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned long V_84 ,
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
return F_71 ( V_2 , V_22 ) ;
}
static int F_116 ( struct V_1 * V_2 , unsigned long V_84 ,
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
if ( V_22 -> V_230 )
return V_22 -> V_230 ( V_2 , V_22 ) ;
return - V_64 ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_84 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_231 , * V_232 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_232 = & V_2 -> V_82 [ V_84 ] ;
V_231 = F_36 ( V_32 ) ;
if ( V_231 == V_232 )
return 0 ;
if ( ! ( V_232 -> V_27 & V_28 ) )
return - V_64 ;
if ( V_231 && V_231 -> V_47 == V_32 && V_231 -> V_43 &&
! ( V_231 -> V_43 -> V_76 . V_68 & V_143 ) )
return - V_48 ;
F_34 ( V_34 -> V_29 ) = V_232 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned long V_84 ,
struct V_32 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_21 * V_231 , * V_232 ;
if ( V_84 >= V_2 -> V_81 )
return - V_64 ;
V_232 = & V_2 -> V_82 [ V_84 ] ;
V_231 = F_37 ( V_32 ) ;
if ( V_231 == V_232 )
return 0 ;
if ( ! ( V_232 -> V_27 & V_30 ) )
return - V_64 ;
if ( V_231 && V_231 -> V_47 == V_32 && V_231 -> V_43 &&
( V_231 -> V_43 -> V_76 . V_68 & V_143 ) )
return - V_48 ;
F_34 ( V_34 -> V_31 ) = V_232 ;
return 0 ;
}
static long F_119 ( struct V_32 * V_32 , unsigned int V_76 ,
unsigned long V_84 )
{
unsigned int V_7 = F_32 ( F_33 ( V_32 ) ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_233 ;
F_16 ( & V_2 -> V_5 ) ;
if ( V_76 == V_234 ) {
if ( V_7 >= V_23 ) {
V_233 = - V_235 ;
goto V_236;
}
V_233 = F_74 ( V_2 ,
(struct V_83 T_3 * ) V_84 ) ;
if ( V_233 == 0 ) {
if ( V_84 == 0 &&
V_2 -> V_7 >= V_92 ) {
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
F_39 ( V_2 -> V_9 , L_35 ) ;
V_233 = - V_60 ;
goto V_236;
}
switch ( V_76 ) {
case V_237 :
V_233 = F_79 ( V_2 ,
(struct V_93 T_3 * ) V_84 ) ;
break;
case V_238 :
V_233 = F_81 ( V_2 , (struct V_98 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_239 :
V_233 = F_83 ( V_2 ,
(struct V_106 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_240 :
V_233 = F_86 ( V_2 , ( void T_3 * ) V_84 ) ;
break;
case V_241 :
V_233 = F_120 ( V_2 , ( void T_3 * ) V_84 ) ;
break;
case V_242 :
V_233 = F_88 ( V_2 ,
(struct V_140 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_243 :
V_233 = F_113 ( V_2 , V_84 , V_32 ) ;
break;
case V_244 :
V_233 = F_114 ( V_2 , V_84 , V_32 ) ;
break;
case V_245 :
V_233 = F_115 ( V_2 , V_84 , V_32 ) ;
break;
case V_246 :
V_233 = F_111 ( V_2 , (struct V_217 T_3 * ) V_84 , V_32 ) ;
break;
case V_247 :
V_233 = F_112 ( V_2 , (struct V_217 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_248 :
V_233 = F_101 ( V_2 ,
(struct V_210 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_249 :
V_233 = F_105 ( V_2 , (struct V_151 T_3 * ) V_84 ,
V_32 ) ;
break;
case V_250 :
V_233 = F_116 ( V_2 , V_84 , V_32 ) ;
break;
case V_251 :
V_233 = F_117 ( V_2 , V_84 , V_32 ) ;
break;
case V_252 :
V_233 = F_118 ( V_2 , V_84 , V_32 ) ;
break;
default:
V_233 = - V_235 ;
break;
}
V_236:
F_19 ( & V_2 -> V_5 ) ;
return V_233 ;
}
static void F_121 ( struct V_253 * V_254 )
{
struct V_255 * V_256 ;
V_256 = V_254 -> V_257 ;
F_122 ( V_256 ) ;
}
static void F_123 ( struct V_253 * V_254 )
{
struct V_255 * V_256 ;
V_256 = V_254 -> V_257 ;
F_124 ( V_256 ) ;
}
static int F_125 ( struct V_32 * V_32 , struct V_253 * V_258 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 ;
struct V_42 * V_43 ;
struct V_255 * V_256 = NULL ;
unsigned long V_259 = V_258 -> V_260 ;
unsigned long V_59 ;
int V_261 ;
int V_15 ;
int V_44 ;
if ( ! F_126 ( & V_2 -> V_6 ) )
return - V_194 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_236;
}
if ( V_258 -> V_262 & V_263 )
V_22 = F_37 ( V_32 ) ;
else
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 ) {
V_44 = - V_64 ;
goto V_236;
}
V_43 = V_22 -> V_43 ;
if ( ! V_43 ) {
V_44 = - V_64 ;
goto V_236;
}
if ( V_258 -> V_264 != 0 ) {
F_39 ( V_2 -> V_9 , L_36 ) ;
V_44 = - V_64 ;
goto V_236;
}
V_59 = V_258 -> V_265 - V_258 -> V_260 ;
if ( V_59 > V_43 -> V_53 ) {
V_44 = - V_87 ;
goto V_236;
}
if ( F_127 ( V_59 ) ) {
V_44 = - V_87 ;
goto V_236;
}
V_261 = V_59 >> V_266 ;
V_256 = F_128 ( V_22 ) ;
if ( ! V_256 || V_261 > V_256 -> V_261 ) {
V_44 = - V_64 ;
goto V_236;
}
for ( V_15 = 0 ; V_15 < V_261 ; ++ V_15 ) {
struct V_267 * V_57 = & V_256 -> V_268 [ V_15 ] ;
if ( F_129 ( V_258 , V_259 ,
F_130 ( F_131 ( V_57 -> V_269 ) ) ,
V_49 , V_270 ) ) {
V_44 = - V_194 ;
goto V_236;
}
V_259 += V_49 ;
}
V_258 -> V_271 = & V_272 ;
V_258 -> V_257 = V_256 ;
V_258 -> V_271 -> V_273 ( V_258 ) ;
V_44 = 0 ;
V_236:
F_132 ( & V_2 -> V_6 ) ;
F_124 ( V_256 ) ;
return V_44 ;
}
static unsigned int F_133 ( struct V_32 * V_32 , T_4 * V_274 )
{
unsigned int V_67 = 0 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_21 * V_22 , * V_275 ;
F_134 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
goto V_236;
}
V_22 = F_36 ( V_32 ) ;
V_275 = V_22 ;
if ( V_22 && V_22 -> V_43 ) {
F_135 ( V_32 , & V_22 -> V_43 -> V_78 , V_274 ) ;
if ( V_22 -> V_47 != V_32 || ! F_61 ( V_22 ) ||
( V_22 -> V_43 -> V_76 . V_68 & V_143 ) ||
F_91 ( V_22 ) > 0 )
V_67 |= V_276 | V_277 ;
}
V_22 = F_37 ( V_32 ) ;
if ( V_22 && V_22 -> V_43 ) {
unsigned int V_278 = F_136 ( V_22 ) ;
if ( V_22 != V_275 )
F_135 ( V_32 , & V_22 -> V_43 -> V_78 , V_274 ) ;
if ( V_22 -> V_47 != V_32 || ! F_61 ( V_22 ) ||
! ( V_22 -> V_43 -> V_76 . V_68 & V_143 ) ||
F_137 ( V_22 ) >= V_278 )
V_67 |= V_279 | V_280 ;
}
V_236:
F_132 ( & V_2 -> V_6 ) ;
return V_67 ;
}
static T_1 F_138 ( struct V_32 * V_32 , const char T_3 * V_57 ,
T_2 V_281 , T_5 * V_282 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_154 , V_283 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_139 ( V_274 , V_284 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
bool V_142 = false ;
bool V_285 ;
unsigned int V_286 ;
F_134 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_195;
}
V_22 = F_37 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_197 ;
goto V_195;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ! ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
goto V_195;
}
F_140 ( & V_43 -> V_78 , & V_274 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned int V_66 ;
unsigned int V_287 , V_288 , V_289 ;
F_141 ( V_290 ) ;
V_66 = F_58 ( V_22 ) ;
if ( ! F_59 ( V_66 ) ) {
if ( F_60 ( V_66 ) )
V_44 = - V_145 ;
if ( V_44 || V_281 )
V_142 = true ;
break;
}
if ( V_281 == 0 )
break;
F_92 ( V_22 , V_43 -> V_53 ) ;
V_283 = F_142 ( V_22 ) ;
V_154 = F_143 ( T_2 , V_283 , V_281 ) ;
if ( V_154 == 0 ) {
if ( V_32 -> V_291 & V_292 ) {
V_44 = - V_194 ;
break;
}
F_104 () ;
if ( F_144 ( V_284 ) ) {
V_44 = - V_293 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
! ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
V_287 = V_43 -> V_148 ;
V_288 = F_145 ( V_154 , V_43 -> V_53 - V_287 ) ;
V_289 = V_154 - V_288 ;
V_283 = F_76 ( V_43 -> V_294 + V_287 , V_57 , V_288 ) ;
if ( V_283 )
V_283 += V_289 ;
else if ( V_289 )
V_283 = F_76 ( V_43 -> V_294 , V_57 + V_288 , V_289 ) ;
if ( V_283 ) {
V_154 -= V_283 ;
V_44 = - V_87 ;
}
F_93 ( V_22 , V_154 ) ;
V_61 += V_154 ;
V_281 -= V_154 ;
V_57 += V_154 ;
}
F_146 ( & V_43 -> V_78 , & V_274 ) ;
F_141 ( V_295 ) ;
if ( V_142 && V_61 == 0 ) {
struct V_21 * V_296 ;
F_132 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_296 = F_37 ( V_32 ) ;
if ( V_2 -> V_12 && V_286 == V_2 -> V_40 &&
V_22 == V_296 && V_296 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
( V_43 -> V_76 . V_68 & V_143 ) &&
! F_61 ( V_22 ) )
F_67 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_195:
if ( V_285 )
F_132 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static T_1 F_147 ( struct V_32 * V_32 , char T_3 * V_57 , T_2 V_281 ,
T_5 * V_282 )
{
struct V_21 * V_22 ;
struct V_42 * V_43 ;
unsigned int V_154 , V_283 ;
T_1 V_61 = 0 ;
int V_44 = 0 ;
F_139 ( V_274 , V_284 ) ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned int V_286 ;
bool V_142 = false ;
bool V_285 ;
F_134 ( & V_2 -> V_6 ) ;
V_285 = true ;
V_286 = V_2 -> V_40 ;
if ( ! V_2 -> V_12 ) {
F_39 ( V_2 -> V_9 , L_35 ) ;
V_44 = - V_60 ;
goto V_195;
}
V_22 = F_36 ( V_32 ) ;
if ( ! V_22 || ! V_22 -> V_43 ) {
V_44 = - V_197 ;
goto V_195;
}
V_43 = V_22 -> V_43 ;
if ( V_22 -> V_47 != V_32 || ( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
goto V_195;
}
F_140 ( & V_43 -> V_78 , & V_274 ) ;
while ( V_61 == 0 && ! V_44 ) {
unsigned int V_297 , V_288 , V_289 ;
F_141 ( V_290 ) ;
V_283 = F_91 ( V_22 ) ;
V_154 = F_143 ( T_2 , V_283 , V_281 ) ;
if ( V_154 == 0 ) {
unsigned int V_66 =
F_58 ( V_22 ) ;
if ( ! F_59 ( V_66 ) ) {
if ( F_60 ( V_66 ) )
V_44 = - V_145 ;
if ( V_44 || V_281 )
V_142 = true ;
break;
}
if ( V_281 == 0 )
break;
if ( V_32 -> V_291 & V_292 ) {
V_44 = - V_194 ;
break;
}
F_104 () ;
if ( F_144 ( V_284 ) ) {
V_44 = - V_293 ;
break;
}
if ( V_22 -> V_47 != V_32 ||
( V_43 -> V_76 . V_68 & V_143 ) ) {
V_44 = - V_64 ;
break;
}
continue;
}
V_297 = V_43 -> V_150 ;
V_288 = F_145 ( V_154 , V_43 -> V_53 - V_297 ) ;
V_289 = V_154 - V_288 ;
V_283 = F_80 ( V_57 , V_43 -> V_294 + V_297 , V_288 ) ;
if ( V_283 )
V_283 += V_289 ;
else if ( V_289 )
V_283 = F_80 ( V_57 + V_288 , V_43 -> V_294 , V_289 ) ;
if ( V_283 ) {
V_154 -= V_283 ;
V_44 = - V_87 ;
}
F_89 ( V_22 , V_154 ) ;
F_90 ( V_22 , V_154 ) ;
V_61 += V_154 ;
V_281 -= V_154 ;
V_57 += V_154 ;
}
F_146 ( & V_43 -> V_78 , & V_274 ) ;
F_141 ( V_295 ) ;
if ( V_142 && V_61 == 0 ) {
struct V_21 * V_296 ;
F_132 ( & V_2 -> V_6 ) ;
V_285 = false ;
F_16 ( & V_2 -> V_5 ) ;
V_296 = F_36 ( V_32 ) ;
if ( V_2 -> V_12 && V_286 == V_2 -> V_40 &&
V_22 == V_296 && V_296 -> V_43 == V_43 && V_22 -> V_47 == V_32 &&
! ( V_43 -> V_76 . V_68 & V_143 ) &&
! F_61 ( V_22 ) &&
F_91 ( V_22 ) == 0 )
F_67 ( V_2 , V_22 ) ;
F_19 ( & V_2 -> V_5 ) ;
}
V_195:
if ( V_285 )
F_132 ( & V_2 -> V_6 ) ;
return V_61 ? V_61 : V_44 ;
}
static int F_148 ( struct V_298 * V_298 , struct V_32 * V_32 )
{
const unsigned int V_7 = F_32 ( V_298 ) ;
struct V_33 * V_34 ;
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_233 ;
if ( ! V_2 ) {
F_149 ( L_37 ) ;
return - V_60 ;
}
V_34 = F_66 ( sizeof( * V_34 ) , V_74 ) ;
if ( ! V_34 )
return - V_109 ;
V_34 -> V_2 = V_2 ;
F_16 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_12 && ! F_75 ( V_86 ) ) {
F_39 ( V_2 -> V_9 , L_38 ) ;
V_233 = - V_60 ;
goto V_195;
}
if ( V_2 -> V_12 && V_2 -> V_14 == 0 ) {
if ( ! F_150 ( V_2 -> V_13 -> V_10 ) ) {
V_233 = - V_299 ;
goto V_195;
}
if ( V_2 -> V_273 ) {
V_233 = V_2 -> V_273 ( V_2 ) ;
if ( V_233 < 0 ) {
F_18 ( V_2 -> V_13 -> V_10 ) ;
goto V_195;
}
}
}
V_2 -> V_14 ++ ;
V_32 -> V_35 = V_34 ;
F_31 ( V_32 ) ;
V_233 = 0 ;
V_195:
F_19 ( & V_2 -> V_5 ) ;
if ( V_233 ) {
F_11 ( V_2 ) ;
F_10 ( V_34 ) ;
}
return V_233 ;
}
static int F_151 ( int V_300 , struct V_32 * V_32 , int V_301 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
return F_152 ( V_300 , V_32 , V_301 , & V_2 -> V_302 ) ;
}
static int F_153 ( struct V_298 * V_298 , struct V_32 * V_32 )
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
F_71 ( V_2 , V_22 ) ;
if ( V_22 -> V_121 == V_32 )
V_22 -> V_121 = NULL ;
}
}
if ( V_2 -> V_12 && V_2 -> V_14 == 1 ) {
if ( V_2 -> V_303 )
V_2 -> V_303 ( V_2 ) ;
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
unsigned int V_304 ;
int V_305 = 0 ;
unsigned long V_68 ;
F_55 ( & V_22 -> V_69 , V_68 ) ;
V_304 = V_43 -> V_304 ;
V_43 -> V_304 = 0 ;
if ( ! F_62 ( V_22 ) ) {
F_56 ( & V_22 -> V_69 , V_68 ) ;
return;
}
if ( V_304 & V_226 )
F_52 ( V_22 , V_70 ) ;
if ( V_304 & V_306 )
F_53 ( V_22 , V_71 ) ;
if ( V_43 -> V_224 & V_304 ) {
F_155 ( & V_43 -> V_78 ) ;
V_305 = V_43 -> V_76 . V_68 & V_143 ? V_307 : V_308 ;
}
F_56 ( & V_22 -> V_69 , V_68 ) ;
if ( V_305 )
F_156 ( & V_2 -> V_302 , V_309 , V_305 ) ;
}
struct V_1 * F_157 ( struct V_26 * V_310 )
{
struct V_1 * V_2 ;
struct V_26 * V_54 ;
unsigned int V_15 ;
V_2 = F_66 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return F_158 ( - V_109 ) ;
F_1 ( V_2 ) ;
F_159 ( V_2 , V_310 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_16 ( & V_17 ) ;
for ( V_15 = V_310 ? V_92 : 0 ;
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
F_70 ( V_310 ,
L_39 ) ;
return F_158 ( - V_48 ) ;
}
V_2 -> V_7 = V_15 ;
V_54 = F_160 ( V_19 , V_310 ,
F_24 ( V_20 , V_15 ) , NULL , L_40 , V_15 ) ;
if ( ! F_109 ( V_54 ) )
V_2 -> V_9 = F_161 ( V_54 ) ;
return V_2 ;
}
void F_162 ( struct V_26 * V_310 )
{
int V_7 ;
struct V_1 * V_2 ;
for ( V_7 = V_92 ; V_7 < V_23 ;
V_7 ++ ) {
F_16 ( & V_17 ) ;
V_2 = V_18 [ V_7 ] ;
if ( V_2 && V_2 -> V_311 == V_310 ) {
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
unsigned int V_15 ;
F_16 ( & V_24 ) ;
for ( V_15 = 0 ; V_15 < V_312 ; ++ V_15 ) {
if ( ! V_25 [ V_15 ] ) {
V_25 [ V_15 ] = V_22 ;
break;
}
}
F_19 ( & V_24 ) ;
if ( V_15 == V_312 ) {
F_70 ( V_2 -> V_9 ,
L_41 ) ;
return - V_48 ;
}
V_15 += V_23 ;
V_22 -> V_7 = V_15 ;
V_54 = F_160 ( V_19 , V_2 -> V_9 ,
F_24 ( V_20 , V_15 ) , NULL , L_42 ,
V_2 -> V_7 , V_22 -> V_52 ) ;
if ( ! F_109 ( V_54 ) )
V_22 -> V_9 = V_54 ;
return 0 ;
}
void F_164 ( struct V_21 * V_22 )
{
unsigned int V_15 ;
if ( ! V_22 )
return;
if ( V_22 -> V_7 < V_23 ||
V_22 -> V_7 >= V_313 )
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
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_2 = F_21 ( V_15 ) ;
F_22 ( V_2 ) ;
}
}
static int T_6 F_166 ( void )
{
int V_15 ;
int V_44 ;
F_167 ( L_43 V_314 L_44 ) ;
if ( V_92 < 0 ||
V_92 > V_23 ) {
F_168 ( L_45 ,
V_23 ) ;
return - V_64 ;
}
V_44 = F_169 ( F_24 ( V_20 , 0 ) ,
V_313 , L_46 ) ;
if ( V_44 )
return - V_197 ;
F_170 ( & V_315 , & V_316 ) ;
V_315 . V_317 = V_318 ;
V_44 = F_171 ( & V_315 . V_319 , L_46 ) ;
if ( V_44 ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_313 ) ;
return V_44 ;
}
if ( F_173 ( & V_315 , F_24 ( V_20 , 0 ) , V_313 ) ) {
F_172 ( F_24 ( V_20 , 0 ) ,
V_313 ) ;
return - V_197 ;
}
V_19 = F_174 ( V_318 , L_46 ) ;
if ( F_109 ( V_19 ) ) {
F_168 ( L_47 ) ;
F_175 ( & V_315 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_313 ) ;
return F_110 ( V_19 ) ;
}
V_19 -> V_320 = V_321 ;
F_176 () ;
for ( V_15 = 0 ; V_15 < V_92 ; V_15 ++ ) {
struct V_1 * V_2 ;
V_2 = F_157 ( NULL ) ;
if ( F_109 ( V_2 ) ) {
F_165 () ;
F_175 ( & V_315 ) ;
F_172 ( F_24 ( V_20 , 0 ) ,
V_313 ) ;
return F_110 ( V_2 ) ;
}
F_19 ( & V_2 -> V_5 ) ;
}
return 0 ;
}
static void T_7 F_177 ( void )
{
F_165 () ;
F_178 ( V_19 ) ;
F_175 ( & V_315 ) ;
F_172 ( F_24 ( V_20 , 0 ) , V_313 ) ;
F_179 () ;
}
