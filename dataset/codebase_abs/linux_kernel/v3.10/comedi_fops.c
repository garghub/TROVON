static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = - 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = NULL ;
if ( V_2 == NULL )
return;
F_5 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_8 )
V_7 = V_2 -> V_9 -> V_6 ;
F_6 ( V_2 ) ;
while ( V_2 -> V_10 > 0 ) {
if ( V_7 )
F_7 ( V_7 ) ;
F_7 ( V_11 ) ;
V_2 -> V_10 -- ;
}
F_8 ( & V_2 -> V_4 ) ;
F_9 ( & V_2 -> V_4 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
unsigned int V_12 = V_2 -> V_5 ;
bool V_13 = false ;
F_5 ( & V_14 ) ;
if ( V_2 == V_15 [ V_12 ] ) {
V_15 [ V_12 ] = NULL ;
V_13 = true ;
}
F_8 ( & V_14 ) ;
return V_13 ;
}
static struct V_1 * F_11 ( unsigned V_5 )
{
struct V_1 * V_2 ;
F_5 ( & V_14 ) ;
V_2 = V_15 [ V_5 ] ;
V_15 [ V_5 ] = NULL ;
F_8 ( & V_14 ) ;
return V_2 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_16 ) {
F_13 ( V_17 ,
F_14 ( V_18 , V_2 -> V_5 ) ) ;
}
F_4 ( V_2 ) ;
F_15 ( V_2 ) ;
}
}
static struct V_19
* F_16 ( unsigned V_5 )
{
struct V_19 * V_20 ;
unsigned int V_12 = V_5 - V_21 ;
F_17 ( V_12 >= V_22 ) ;
F_5 ( & V_23 ) ;
V_20 = V_24 [ V_12 ] ;
F_8 ( & V_23 ) ;
return V_20 ;
}
static struct V_1 * F_18 ( unsigned V_5 )
{
struct V_1 * V_2 ;
F_17 ( V_5 >= V_21 ) ;
F_5 ( & V_14 ) ;
V_2 = V_15 [ V_5 ] ;
F_8 ( & V_14 ) ;
return V_2 ;
}
static struct V_1 * F_19 ( unsigned V_5 )
{
struct V_19 * V_20 ;
V_20 = F_16 ( V_5 ) ;
return V_20 ? V_20 -> V_25 : NULL ;
}
struct V_1 * F_20 ( unsigned V_5 )
{
if ( V_5 < V_21 )
return F_18 ( V_5 ) ;
else
return F_19 ( V_5 ) ;
}
static struct V_19 *
F_21 ( const struct V_1 * V_2 , unsigned int V_5 )
{
struct V_19 * V_20 ;
if ( V_5 >= V_21 ) {
V_20 = F_16 ( V_5 ) ;
if ( ! V_20 || V_20 -> V_25 != V_2 )
return NULL ;
if ( V_20 -> V_26 & V_27 )
return V_20 ;
}
return V_2 -> V_28 ;
}
static struct V_19 *
F_22 ( const struct V_1 * V_2 , unsigned int V_5 )
{
struct V_19 * V_20 ;
if ( V_5 >= V_21 ) {
V_20 = F_16 ( V_5 ) ;
if ( ! V_20 || V_20 -> V_25 != V_2 )
return NULL ;
if ( V_20 -> V_26 & V_29 )
return V_20 ;
}
return V_2 -> V_30 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_31 * V_32 , unsigned V_33 )
{
int V_34 ;
if ( V_33 > V_32 -> V_35 )
return - V_36 ;
if ( V_20 -> V_37 ) {
F_24 ( L_1 ) ;
return - V_38 ;
}
if ( V_32 -> V_39 ) {
F_24 ( L_2 ) ;
return - V_38 ;
}
V_33 = ( V_33 + V_40 - 1 ) & V_41 ;
V_34 = F_25 ( V_2 , V_20 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_20 -> V_42 ) {
V_34 = V_20 -> V_42 ( V_2 , V_20 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
}
F_24 ( L_3 ,
V_2 -> V_5 , V_20 -> V_43 , V_32 -> V_44 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_25 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 = 0 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_27 ) && V_20 -> V_32 )
V_50 = V_20 -> V_32 -> V_35 / 1024 ;
F_8 ( & V_2 -> V_4 ) ;
return snprintf ( V_48 , V_40 , L_4 , V_50 ) ;
}
static T_1 F_28 ( struct V_25 * V_45 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_52 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 ;
int V_53 ;
V_53 = F_29 ( V_48 , 10 , & V_50 ) ;
if ( V_53 )
return V_53 ;
if ( V_50 > ( V_54 / 1024 ) )
return - V_55 ;
V_50 *= 1024 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_27 ) && V_20 -> V_32 )
V_20 -> V_32 -> V_35 = V_50 ;
else
V_53 = - V_55 ;
F_8 ( & V_2 -> V_4 ) ;
return V_53 ? V_53 : V_52 ;
}
static T_1 F_30 ( struct V_25 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 = 0 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_27 ) && V_20 -> V_32 )
V_50 = V_20 -> V_32 -> V_44 / 1024 ;
F_8 ( & V_2 -> V_4 ) ;
return snprintf ( V_48 , V_40 , L_4 , V_50 ) ;
}
static T_1 F_31 ( struct V_25 * V_45 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_52 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 ;
int V_53 ;
V_53 = F_29 ( V_48 , 10 , & V_50 ) ;
if ( V_53 )
return V_53 ;
if ( V_50 > ( V_54 / 1024 ) )
return - V_55 ;
V_50 *= 1024 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_27 ) && V_20 -> V_32 )
V_53 = F_23 ( V_2 , V_20 , V_20 -> V_32 , V_50 ) ;
else
V_53 = - V_55 ;
F_8 ( & V_2 -> V_4 ) ;
return V_53 ? V_53 : V_52 ;
}
static T_1 F_32 ( struct V_25 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 = 0 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_29 ) && V_20 -> V_32 )
V_50 = V_20 -> V_32 -> V_35 / 1024 ;
F_8 ( & V_2 -> V_4 ) ;
return snprintf ( V_48 , V_40 , L_4 , V_50 ) ;
}
static T_1 F_33 ( struct V_25 * V_45 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_52 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 ;
int V_53 ;
V_53 = F_29 ( V_48 , 10 , & V_50 ) ;
if ( V_53 )
return V_53 ;
if ( V_50 > ( V_54 / 1024 ) )
return - V_55 ;
V_50 *= 1024 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_29 ) && V_20 -> V_32 )
V_20 -> V_32 -> V_35 = V_50 ;
else
V_53 = - V_55 ;
F_8 ( & V_2 -> V_4 ) ;
return V_53 ? V_53 : V_52 ;
}
static T_1 F_34 ( struct V_25 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 = 0 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_29 ) && V_20 -> V_32 )
V_50 = V_20 -> V_32 -> V_44 / 1024 ;
F_8 ( & V_2 -> V_4 ) ;
return snprintf ( V_48 , V_40 , L_4 , V_50 ) ;
}
static T_1 F_35 ( struct V_25 * V_45 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_52 )
{
unsigned int V_5 = F_27 ( V_45 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned int V_50 ;
int V_53 ;
V_53 = F_29 ( V_48 , 10 , & V_50 ) ;
if ( V_53 )
return V_53 ;
if ( V_50 > ( V_54 / 1024 ) )
return - V_55 ;
V_50 *= 1024 ;
V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && ( V_20 -> V_26 & V_29 ) && V_20 -> V_32 )
V_53 = F_23 ( V_2 , V_20 , V_20 -> V_32 , V_50 ) ;
else
V_53 = - V_55 ;
F_8 ( & V_2 -> V_4 ) ;
return V_53 ? V_53 : V_52 ;
}
static void F_36 ( struct V_19 * V_20 ,
unsigned V_56 , unsigned V_57 )
{
unsigned long V_58 ;
F_37 ( & V_20 -> V_59 , V_58 ) ;
V_20 -> V_60 &= ~ V_56 ;
V_20 -> V_60 |= ( V_57 & V_56 ) ;
F_38 ( & V_20 -> V_59 , V_58 ) ;
}
static unsigned F_39 ( struct V_19 * V_20 )
{
unsigned long V_58 ;
unsigned V_60 ;
F_37 ( & V_20 -> V_59 , V_58 ) ;
V_60 = V_20 -> V_60 ;
F_38 ( & V_20 -> V_59 , V_58 ) ;
return V_60 ;
}
bool F_40 ( struct V_19 * V_20 )
{
unsigned V_60 = F_39 ( V_20 ) ;
return ( V_60 & V_61 ) ? true : false ;
}
static bool F_41 ( struct V_19 * V_20 )
{
unsigned V_60 = F_39 ( V_20 ) ;
return ( V_60 & V_62 ) ? true : false ;
}
static bool F_42 ( struct V_19 * V_20 )
{
unsigned V_60 = F_39 ( V_20 ) ;
return ( V_60 & ( V_62 | V_61 ) ) ? false : true ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_31 * V_32 = V_20 -> V_32 ;
F_36 ( V_20 , V_61 , 0 ) ;
if ( V_32 ) {
F_44 ( V_32 ) ;
V_32 -> V_63 = NULL ;
F_15 ( V_32 -> V_64 . V_65 ) ;
V_32 -> V_64 . V_65 = NULL ;
} else {
F_45 ( V_2 -> V_16 ,
L_5 ) ;
}
V_20 -> V_37 = NULL ;
}
static int F_46 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_66 = 0 ;
if ( F_40 ( V_20 ) && V_20 -> V_67 )
V_66 = V_20 -> V_67 ( V_2 , V_20 ) ;
F_43 ( V_2 , V_20 ) ;
return V_66 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
int V_12 ;
if ( ! V_2 -> V_8 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_68 ; V_12 ++ ) {
V_20 = & V_2 -> V_69 [ V_12 ] ;
if ( V_20 -> V_37 )
return 1 ;
if ( V_20 -> V_32 && V_20 -> V_32 -> V_39 )
return 1 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_70 T_3 * V_71 )
{
struct V_70 V_72 ;
if ( ! F_49 ( V_73 ) )
return - V_36 ;
if ( V_71 == NULL ) {
if ( F_47 ( V_2 ) )
return - V_38 ;
if ( V_2 -> V_8 ) {
struct V_6 * V_7 = V_2 -> V_9 -> V_6 ;
F_6 ( V_2 ) ;
F_7 ( V_7 ) ;
}
return 0 ;
}
if ( F_50 ( & V_72 , V_71 , sizeof( V_72 ) ) )
return - V_74 ;
V_72 . V_75 [ V_76 - 1 ] = 0 ;
if ( V_72 . V_77 [ V_78 ] ) {
F_51 ( V_2 -> V_16 ,
L_6 ) ;
return - V_55 ;
}
if ( V_2 -> V_5 >= V_79 )
return - V_38 ;
return F_52 ( V_2 , & V_72 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_80 T_3 * V_71 )
{
struct V_80 V_81 ;
struct V_31 * V_32 ;
struct V_19 * V_20 ;
int V_34 = 0 ;
if ( F_50 ( & V_81 , V_71 , sizeof( V_81 ) ) )
return - V_74 ;
if ( V_81 . V_82 >= V_2 -> V_68 || V_81 . V_82 < 0 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_81 . V_82 ] ;
V_32 = V_20 -> V_32 ;
if ( ! V_32 ) {
F_24 ( L_7 ) ;
V_81 . V_50 = 0 ;
V_81 . V_83 = 0 ;
goto V_84;
}
if ( V_81 . V_83 ) {
if ( ! F_49 ( V_73 ) )
return - V_36 ;
V_32 -> V_35 = V_81 . V_83 ;
}
if ( V_81 . V_50 ) {
V_34 = F_23 ( V_2 , V_20 , V_32 , V_81 . V_50 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_81 . V_50 = V_32 -> V_44 ;
V_81 . V_83 = V_32 -> V_35 ;
V_84:
if ( F_54 ( V_71 , & V_81 , sizeof( V_81 ) ) )
return - V_74 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_85 T_3 * V_71 ,
struct V_86 * V_86 )
{
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_19 * V_20 ;
struct V_85 V_87 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_88 = V_89 ;
V_87 . V_90 = V_2 -> V_68 ;
F_58 ( V_87 . V_91 , V_2 -> V_9 -> V_91 , V_76 ) ;
F_58 ( V_87 . V_75 , V_2 -> V_75 , V_76 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 )
V_87 . V_92 = V_20 -> V_43 ;
else
V_87 . V_92 = - 1 ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 )
V_87 . V_93 = V_20 -> V_43 ;
else
V_87 . V_93 = - 1 ;
if ( F_54 ( V_71 , & V_87 , sizeof( V_87 ) ) )
return - V_74 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_94 T_3 * V_71 , void * V_86 )
{
int V_66 , V_12 ;
struct V_94 * V_95 , * V_96 ;
struct V_19 * V_20 ;
V_95 = F_60 ( V_2 -> V_68 , sizeof( * V_95 ) , V_97 ) ;
if ( ! V_95 )
return - V_98 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_68 ; V_12 ++ ) {
V_20 = & V_2 -> V_69 [ V_12 ] ;
V_96 = V_95 + V_12 ;
V_96 -> type = V_20 -> type ;
V_96 -> V_99 = V_20 -> V_99 ;
V_96 -> V_100 = V_20 -> V_26 ;
if ( F_40 ( V_20 ) )
V_96 -> V_100 |= V_101 ;
#define F_61 5
V_96 -> V_102 = F_61 ;
V_96 -> V_103 = V_20 -> V_103 ;
V_96 -> V_104 = V_20 -> V_104 ;
if ( V_20 -> V_105 ) {
V_96 -> V_106 =
( V_12 << 24 ) | ( 0 << 16 ) | ( V_20 -> V_105 -> V_107 ) ;
} else {
V_96 -> V_106 = 0 ;
}
V_96 -> V_58 = V_20 -> V_58 ;
if ( V_20 -> V_37 )
V_96 -> V_100 |= V_108 ;
if ( V_20 -> V_37 == V_86 )
V_96 -> V_100 |= V_109 ;
if ( V_20 -> V_110 )
V_96 -> V_100 |= V_111 ;
if ( V_20 -> V_110 == V_86 )
V_96 -> V_100 |= V_112 ;
if ( ! V_20 -> V_104 && V_20 -> V_113 )
V_96 -> V_100 |= V_114 ;
if ( V_20 -> V_115 )
V_96 -> V_100 |= V_116 ;
if ( V_20 -> V_117 )
V_96 -> V_100 |= V_118 ;
if ( V_20 -> V_119 )
V_96 -> V_100 |= V_120 ;
if ( V_20 -> V_121 != & V_122 )
V_96 -> V_123 = V_124 ;
else
V_96 -> V_123 = V_125 ;
V_96 -> V_126 = V_20 -> V_126 ;
}
V_66 = F_54 ( V_71 , V_95 , V_2 -> V_68 * sizeof( * V_95 ) ) ;
F_15 ( V_95 ) ;
return V_66 ? - V_74 : 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_127 T_3 * V_71 )
{
struct V_19 * V_20 ;
struct V_127 V_72 ;
if ( F_50 ( & V_72 , V_71 , sizeof( V_72 ) ) )
return - V_74 ;
if ( V_72 . V_128 >= V_2 -> V_68 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_72 . V_128 ] ;
if ( V_72 . V_113 ) {
if ( V_20 -> V_104 || ! V_20 -> V_113 )
return - V_55 ;
if ( F_54 ( V_72 . V_113 , V_20 -> V_113 ,
V_20 -> V_99 * sizeof( unsigned int ) ) )
return - V_74 ;
}
if ( V_72 . V_115 ) {
if ( ! V_20 -> V_115 )
return - V_55 ;
if ( F_54 ( V_72 . V_115 , V_20 -> V_115 ,
V_20 -> V_99 * sizeof( unsigned int ) ) )
return - V_74 ;
}
if ( V_72 . V_129 ) {
int V_12 ;
if ( ! V_20 -> V_117 )
return - V_55 ;
for ( V_12 = 0 ; V_12 < V_20 -> V_99 ; V_12 ++ ) {
int V_130 ;
V_130 = ( V_2 -> V_5 << 28 ) | ( V_72 . V_128 << 24 ) | ( V_12 << 16 ) |
( V_20 -> V_117 [ V_12 ] -> V_107 ) ;
if ( F_63 ( V_130 , V_72 . V_129 + V_12 ) )
return - V_74 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_131 T_3 * V_71 , void * V_86 )
{
struct V_131 V_132 ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
if ( F_50 ( & V_132 , V_71 , sizeof( V_132 ) ) )
return - V_74 ;
if ( V_132 . V_82 >= V_2 -> V_68 || V_132 . V_82 < 0 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_132 . V_82 ] ;
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 )
return - V_133 ;
V_32 = V_20 -> V_32 ;
if ( ! V_32 ) {
F_24 ( L_7 ) ;
V_132 . V_134 = 0 ;
V_132 . V_135 = 0 ;
V_132 . V_136 = 0 ;
V_132 . V_137 = 0 ;
V_132 . V_138 = 0 ;
V_132 . V_139 = 0 ;
goto V_84;
}
if ( ! V_20 -> V_37 ) {
V_132 . V_138 = 0 ;
V_132 . V_139 = 0 ;
goto V_140;
}
if ( V_20 -> V_37 != V_86 )
return - V_133 ;
if ( V_132 . V_138 && ( V_20 -> V_26 & V_27 ) ) {
V_132 . V_138 = F_65 ( V_32 , V_132 . V_138 ) ;
F_66 ( V_32 , V_132 . V_138 ) ;
if ( F_42 ( V_20 ) &&
V_32 -> V_136 == V_32 -> V_137 ) {
F_43 ( V_2 , V_20 ) ;
}
}
if ( V_132 . V_139 && ( V_20 -> V_26 & V_29 ) ) {
V_132 . V_139 =
F_67 ( V_32 , V_132 . V_139 ) ;
F_68 ( V_32 , V_132 . V_139 ) ;
}
V_140:
V_132 . V_136 = V_32 -> V_136 ;
V_132 . V_134 = V_32 -> V_134 ;
V_132 . V_137 = V_32 -> V_137 ;
V_132 . V_135 = V_32 -> V_135 ;
V_84:
if ( F_54 ( V_71 , & V_132 , sizeof( V_132 ) ) )
return - V_74 ;
return 0 ;
}
static int F_69 ( struct V_141 * V_142 ,
unsigned int * V_143 )
{
if ( V_142 -> V_144 < 1 )
return - V_55 ;
switch ( V_143 [ 0 ] ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
if ( V_142 -> V_144 == 1 )
return 0 ;
break;
case V_149 :
case V_150 :
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
if ( V_142 -> V_144 == 2 )
return 0 ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
if ( V_142 -> V_144 == 3 )
return 0 ;
break;
case V_172 :
case V_173 :
if ( V_142 -> V_144 == 5 )
return 0 ;
break;
case V_174 :
if ( V_142 -> V_144 == 6 )
return 0 ;
break;
default:
F_70 ( L_8 ,
V_143 [ 0 ] ) ;
F_70 ( L_9 ,
V_175 , __FILE__ ) ;
F_70 ( L_10 , V_142 -> V_144 ) ;
return 0 ;
}
return - V_55 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_141 * V_142 ,
unsigned int * V_143 , void * V_86 )
{
struct V_19 * V_20 ;
int V_66 = 0 ;
int V_12 ;
if ( V_142 -> V_142 & V_176 ) {
switch ( V_142 -> V_142 ) {
case V_177 :
{
struct V_178 V_179 ;
if ( V_142 -> V_144 != 2 ) {
V_66 = - V_55 ;
break;
}
F_72 ( & V_179 ) ;
V_143 [ 0 ] = V_179 . V_180 ;
V_143 [ 1 ] = V_179 . V_181 ;
V_66 = 2 ;
break;
}
case V_182 :
if ( V_142 -> V_144 != 1 || V_143 [ 0 ] >= 100000 ) {
V_66 = - V_55 ;
break;
}
F_73 ( V_143 [ 0 ] / 1000 ) ;
V_66 = 1 ;
break;
case V_183 :
if ( V_142 -> V_144 != 1 ) {
V_66 = - V_55 ;
break;
}
if ( V_142 -> V_128 >= V_2 -> V_68 ) {
F_24 ( L_11 ,
V_142 -> V_128 ) ;
V_66 = - V_55 ;
break;
}
V_20 = & V_2 -> V_69 [ V_142 -> V_128 ] ;
if ( ! V_20 -> V_32 ) {
F_24 ( L_12 ) ;
V_66 = - V_55 ;
break;
}
if ( ! V_20 -> V_32 -> V_63 ) {
F_24 ( L_13 ) ;
V_66 = - V_184 ;
break;
}
V_66 = V_20 -> V_32 -> V_63 ( V_2 , V_20 , V_143 [ 0 ] ) ;
if ( V_66 >= 0 )
V_66 = 1 ;
break;
default:
F_24 ( L_14 ) ;
V_66 = - V_55 ;
break;
}
} else {
unsigned int V_104 ;
if ( V_142 -> V_128 >= V_2 -> V_68 ) {
F_24 ( L_15 , V_142 -> V_128 ) ;
V_66 = - V_55 ;
goto V_185;
}
V_20 = & V_2 -> V_69 [ V_142 -> V_128 ] ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_11 , V_142 -> V_128 ) ;
V_66 = - V_187 ;
goto V_185;
}
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 ) {
F_24 ( L_16 ) ;
V_66 = - V_133 ;
goto V_185;
}
V_66 = F_74 ( V_20 , 1 , & V_142 -> V_188 ) ;
if ( V_66 < 0 ) {
V_66 = - V_55 ;
F_24 ( L_17 ) ;
goto V_185;
}
if ( V_20 -> V_37 ) {
V_66 = - V_38 ;
goto V_185;
}
V_20 -> V_37 = & F_71 ;
switch ( V_142 -> V_142 ) {
case V_189 :
V_66 = V_20 -> V_190 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
case V_191 :
V_104 = V_20 -> V_113
? V_20 -> V_113 [ F_75 ( V_142 -> V_188 ) ]
: V_20 -> V_104 ;
for ( V_12 = 0 ; V_12 < V_142 -> V_144 ; ++ V_12 ) {
if ( V_143 [ V_12 ] > V_104 ) {
V_66 = - V_55 ;
F_24 ( L_18 ) ;
break;
}
}
if ( V_66 == 0 )
V_66 = V_20 -> V_192 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
case V_193 :
if ( V_142 -> V_144 != 2 ) {
V_66 = - V_55 ;
} else {
unsigned int V_194 ;
unsigned int V_195 ;
V_195 = V_143 [ 0 ] ;
if ( V_20 -> V_99 <= 32 ) {
V_194 = F_75 ( V_142 -> V_188 ) ;
if ( V_194 > 0 ) {
V_142 -> V_188 = 0 ;
V_143 [ 0 ] <<= V_194 ;
V_143 [ 1 ] <<= V_194 ;
}
} else
V_194 = 0 ;
V_66 = V_20 -> V_121 ( V_2 , V_20 , V_142 , V_143 ) ;
V_143 [ 0 ] = V_195 ;
if ( V_194 > 0 )
V_143 [ 1 ] >>= V_194 ;
}
break;
case V_196 :
V_66 = F_69 ( V_142 , V_143 ) ;
if ( V_66 )
break;
V_66 = V_20 -> V_197 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
default:
V_66 = - V_55 ;
break;
}
V_20 -> V_37 = NULL ;
}
V_185:
return V_66 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_198 T_3 * V_71 , void * V_86 )
{
struct V_198 V_199 ;
struct V_141 * V_200 = NULL ;
unsigned int * V_143 = NULL ;
int V_12 = 0 ;
int V_66 = 0 ;
if ( F_50 ( & V_199 , V_71 , sizeof( V_199 ) ) )
return - V_74 ;
V_143 = F_77 ( sizeof( unsigned int ) * V_201 , V_97 ) ;
if ( ! V_143 ) {
F_24 ( L_19 ) ;
V_66 = - V_98 ;
goto error;
}
V_200 = F_60 ( V_199 . V_202 , sizeof( * V_200 ) , V_97 ) ;
if ( ! V_200 ) {
F_24 ( L_19 ) ;
V_66 = - V_98 ;
goto error;
}
if ( F_50 ( V_200 , V_199 . V_200 ,
sizeof( * V_200 ) * V_199 . V_202 ) ) {
F_24 ( L_20 ) ;
V_66 = - V_74 ;
goto error;
}
for ( V_12 = 0 ; V_12 < V_199 . V_202 ; V_12 ++ ) {
if ( V_200 [ V_12 ] . V_144 > V_201 ) {
F_24 ( L_21 ) ;
V_66 = - V_55 ;
goto error;
}
if ( V_200 [ V_12 ] . V_142 & V_203 ) {
if ( F_50 ( V_143 , V_200 [ V_12 ] . V_143 ,
V_200 [ V_12 ] . V_144 * sizeof( unsigned int ) ) ) {
F_24 ( L_20 ) ;
V_66 = - V_74 ;
goto error;
}
}
V_66 = F_71 ( V_2 , V_200 + V_12 , V_143 , V_86 ) ;
if ( V_66 < 0 )
goto error;
if ( V_200 [ V_12 ] . V_142 & V_204 ) {
if ( F_54 ( V_200 [ V_12 ] . V_143 , V_143 ,
V_200 [ V_12 ] . V_144 * sizeof( unsigned int ) ) ) {
F_24 ( L_22 ) ;
V_66 = - V_74 ;
goto error;
}
}
if ( F_78 () )
F_79 () ;
}
error:
F_15 ( V_200 ) ;
F_15 ( V_143 ) ;
if ( V_66 < 0 )
return V_66 ;
return V_12 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_141 T_3 * V_71 , void * V_86 )
{
struct V_141 V_142 ;
unsigned int * V_143 = NULL ;
int V_66 = 0 ;
V_143 = F_77 ( sizeof( unsigned int ) * V_201 , V_97 ) ;
if ( ! V_143 ) {
V_66 = - V_98 ;
goto error;
}
if ( F_50 ( & V_142 , V_71 , sizeof( V_142 ) ) ) {
V_66 = - V_74 ;
goto error;
}
if ( V_142 . V_144 > V_201 )
V_142 . V_144 = V_201 ;
if ( V_142 . V_142 & V_203 ) {
if ( F_50 ( V_143 ,
V_142 . V_143 ,
V_142 . V_144 * sizeof( unsigned int ) ) ) {
V_66 = - V_74 ;
goto error;
}
}
V_66 = F_71 ( V_2 , & V_142 , V_143 , V_86 ) ;
if ( V_66 < 0 )
goto error;
if ( V_142 . V_142 & V_204 ) {
if ( F_54 ( V_142 . V_143 ,
V_143 ,
V_142 . V_144 * sizeof( unsigned int ) ) ) {
V_66 = - V_74 ;
goto error;
}
}
V_66 = V_142 . V_144 ;
error:
F_15 ( V_143 ) ;
return V_66 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_205 T_3 * V_71 , void * V_86 )
{
struct V_205 V_64 ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_66 = 0 ;
unsigned int T_3 * V_206 ;
if ( F_50 ( & V_64 , V_71 , sizeof( V_64 ) ) ) {
F_24 ( L_23 ) ;
return - V_74 ;
}
V_206 = ( unsigned int T_3 * ) V_64 . V_65 ;
if ( V_64 . V_128 >= V_2 -> V_68 ) {
F_24 ( L_24 , V_64 . V_128 ) ;
return - V_51 ;
}
V_20 = & V_2 -> V_69 [ V_64 . V_128 ] ;
V_32 = V_20 -> V_32 ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_25 , V_64 . V_128 ) ;
return - V_187 ;
}
if ( ! V_20 -> V_119 || ! V_20 -> V_207 || ! V_20 -> V_32 ) {
F_24 ( L_26 ,
V_64 . V_128 ) ;
return - V_187 ;
}
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 ) {
F_24 ( L_27 ) ;
return - V_133 ;
}
if ( V_20 -> V_37 ) {
F_24 ( L_28 ) ;
return - V_38 ;
}
V_20 -> V_37 = V_86 ;
if ( V_64 . V_208 > V_20 -> V_103 ) {
F_24 ( L_29 ,
V_64 . V_208 , V_20 -> V_103 ) ;
V_66 = - V_55 ;
goto V_209;
}
if ( V_64 . V_208 < 1 ) {
F_24 ( L_30 ,
V_64 . V_208 ) ;
V_66 = - V_55 ;
goto V_209;
}
V_32 -> V_64 = V_64 ;
V_32 -> V_64 . V_143 = NULL ;
V_32 -> V_64 . V_65 =
F_77 ( V_32 -> V_64 . V_208 * sizeof( int ) , V_97 ) ;
if ( ! V_32 -> V_64 . V_65 ) {
F_24 ( L_31 ) ;
V_66 = - V_98 ;
goto V_209;
}
if ( F_50 ( V_32 -> V_64 . V_65 , V_206 ,
V_32 -> V_64 . V_208 * sizeof( int ) ) ) {
F_24 ( L_32 ) ;
V_66 = - V_74 ;
goto V_209;
}
V_66 = F_74 ( V_20 ,
V_32 -> V_64 . V_208 ,
V_32 -> V_64 . V_65 ) ;
if ( V_66 < 0 ) {
F_24 ( L_33 ) ;
goto V_209;
}
V_66 = V_20 -> V_207 ( V_2 , V_20 , & V_32 -> V_64 ) ;
if ( V_32 -> V_64 . V_58 & V_210 || V_66 ) {
F_24 ( L_34 , V_66 ) ;
V_64 = V_32 -> V_64 ;
V_64 . V_65 = ( unsigned int V_211 * ) V_206 ;
V_64 . V_143 = NULL ;
if ( F_54 ( V_71 , & V_64 , sizeof( V_64 ) ) ) {
F_24 ( L_35 ) ;
V_66 = - V_74 ;
goto V_209;
}
V_66 = - V_184 ;
goto V_209;
}
if ( ! V_32 -> V_44 ) {
V_66 = - V_98 ;
F_24 ( L_36 ) ;
goto V_209;
}
F_44 ( V_32 ) ;
V_32 -> V_212 =
V_213 | V_214 | V_215 |
V_216 ;
if ( V_32 -> V_64 . V_58 & V_217 )
V_32 -> V_212 |= V_218 ;
F_36 ( V_20 , ~ 0 , V_219 | V_61 ) ;
V_66 = V_20 -> V_119 ( V_2 , V_20 ) ;
if ( V_66 == 0 )
return 0 ;
V_209:
F_43 ( V_2 , V_20 ) ;
return V_66 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_205 T_3 * V_71 , void * V_86 )
{
struct V_205 V_64 ;
struct V_19 * V_20 ;
int V_66 = 0 ;
unsigned int * V_65 = NULL ;
unsigned int T_3 * V_206 ;
if ( F_50 ( & V_64 , V_71 , sizeof( V_64 ) ) ) {
F_24 ( L_23 ) ;
return - V_74 ;
}
V_206 = ( unsigned int T_3 * ) V_64 . V_65 ;
if ( V_64 . V_128 >= V_2 -> V_68 ) {
F_24 ( L_24 , V_64 . V_128 ) ;
return - V_51 ;
}
V_20 = & V_2 -> V_69 [ V_64 . V_128 ] ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_25 , V_64 . V_128 ) ;
return - V_187 ;
}
if ( ! V_20 -> V_119 || ! V_20 -> V_207 ) {
F_24 ( L_26 ,
V_64 . V_128 ) ;
return - V_187 ;
}
if ( V_64 . V_208 > V_20 -> V_103 ) {
F_24 ( L_37 ,
V_64 . V_208 , V_20 -> V_103 ) ;
V_66 = - V_55 ;
goto V_209;
}
if ( V_64 . V_65 ) {
V_65 =
F_77 ( V_64 . V_208 * sizeof( int ) , V_97 ) ;
if ( ! V_65 ) {
F_24 ( L_31 ) ;
V_66 = - V_98 ;
goto V_209;
}
if ( F_50 ( V_65 , V_206 ,
V_64 . V_208 * sizeof( int ) ) ) {
F_24 ( L_32 ) ;
V_66 = - V_74 ;
goto V_209;
}
V_66 = F_74 ( V_20 , V_64 . V_208 , V_65 ) ;
if ( V_66 < 0 ) {
F_24 ( L_33 ) ;
goto V_209;
}
V_64 . V_65 = V_65 ;
}
V_66 = V_20 -> V_207 ( V_2 , V_20 , & V_64 ) ;
V_64 . V_65 = ( unsigned int V_211 * ) V_206 ;
if ( F_54 ( V_71 , & V_64 , sizeof( V_64 ) ) ) {
F_24 ( L_23 ) ;
V_66 = - V_74 ;
goto V_209;
}
V_209:
F_15 ( V_65 ) ;
return V_66 ;
}
static int F_83 ( struct V_1 * V_2 , unsigned int V_71 ,
void * V_86 )
{
int V_66 = 0 ;
unsigned long V_58 ;
struct V_19 * V_20 ;
if ( V_71 >= V_2 -> V_68 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_71 ] ;
F_37 ( & V_20 -> V_59 , V_58 ) ;
if ( V_20 -> V_37 || V_20 -> V_110 )
V_66 = - V_38 ;
else
V_20 -> V_110 = V_86 ;
F_38 ( & V_20 -> V_59 , V_58 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_66 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned int V_71 ,
void * V_86 )
{
struct V_19 * V_20 ;
if ( V_71 >= V_2 -> V_68 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_71 ] ;
if ( V_20 -> V_37 )
return - V_38 ;
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 )
return - V_133 ;
if ( V_20 -> V_110 == V_86 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_20 -> V_110 = NULL ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , unsigned int V_71 ,
void * V_86 )
{
struct V_19 * V_20 ;
if ( V_71 >= V_2 -> V_68 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_71 ] ;
if ( V_20 -> V_32 == NULL )
return - V_55 ;
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 )
return - V_133 ;
if ( ! V_20 -> V_37 )
return 0 ;
if ( V_20 -> V_37 != V_86 )
return - V_38 ;
return F_46 ( V_2 , V_20 ) ;
}
static int F_86 ( struct V_1 * V_2 , unsigned int V_71 ,
void * V_86 )
{
struct V_19 * V_20 ;
if ( V_71 >= V_2 -> V_68 )
return - V_55 ;
V_20 = & V_2 -> V_69 [ V_71 ] ;
if ( V_20 -> V_110 && V_20 -> V_110 != V_86 )
return - V_133 ;
if ( ! V_20 -> V_37 )
return 0 ;
if ( V_20 -> V_37 != V_86 )
return - V_38 ;
if ( V_20 -> V_220 )
return V_20 -> V_220 ( V_2 , V_20 ) ;
return - V_55 ;
}
static long F_87 ( struct V_86 * V_86 , unsigned int V_64 ,
unsigned long V_71 )
{
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
int V_221 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_64 == V_222 ) {
if ( V_5 >= V_21 ) {
V_221 = - V_223 ;
goto V_224;
}
V_221 = F_48 ( V_2 ,
(struct V_70 T_3 * ) V_71 ) ;
if ( V_221 == 0 ) {
if ( V_71 == 0 &&
V_2 -> V_5 >= V_79 ) {
if ( F_10 ( V_2 ) ) {
F_8 ( & V_2 -> V_4 ) ;
F_12 ( V_2 ) ;
return V_221 ;
}
}
}
goto V_224;
}
if ( ! V_2 -> V_8 ) {
F_24 ( L_38 , V_2 -> V_5 ) ;
V_221 = - V_51 ;
goto V_224;
}
switch ( V_64 ) {
case V_225 :
V_221 = F_53 ( V_2 ,
(struct V_80 T_3 * ) V_71 ) ;
break;
case V_226 :
V_221 = F_55 ( V_2 , (struct V_85 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_227 :
V_221 = F_59 ( V_2 ,
(struct V_94 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_228 :
V_221 = F_62 ( V_2 , ( void T_3 * ) V_71 ) ;
break;
case V_229 :
V_221 = F_88 ( V_2 , ( void T_3 * ) V_71 ) ;
break;
case V_230 :
V_221 = F_64 ( V_2 ,
(struct V_131 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_231 :
V_221 = F_83 ( V_2 , V_71 , V_86 ) ;
break;
case V_232 :
V_221 = F_84 ( V_2 , V_71 , V_86 ) ;
break;
case V_233 :
V_221 = F_85 ( V_2 , V_71 , V_86 ) ;
break;
case V_234 :
V_221 = F_81 ( V_2 , (struct V_205 T_3 * ) V_71 , V_86 ) ;
break;
case V_235 :
V_221 = F_82 ( V_2 , (struct V_205 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_236 :
V_221 = F_76 ( V_2 ,
(struct V_198 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_237 :
V_221 = F_80 ( V_2 , (struct V_141 T_3 * ) V_71 ,
V_86 ) ;
break;
case V_238 :
V_221 = F_86 ( V_2 , V_71 , V_86 ) ;
break;
default:
V_221 = - V_223 ;
break;
}
V_224:
F_8 ( & V_2 -> V_4 ) ;
return V_221 ;
}
static void F_89 ( struct V_239 * V_240 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
V_32 = V_240 -> V_241 ;
V_2 = V_32 -> V_82 -> V_25 ;
F_5 ( & V_2 -> V_4 ) ;
V_32 -> V_39 ++ ;
F_8 ( & V_2 -> V_4 ) ;
}
static void F_90 ( struct V_239 * V_240 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
V_32 = V_240 -> V_241 ;
V_2 = V_32 -> V_82 -> V_25 ;
F_5 ( & V_2 -> V_4 ) ;
V_32 -> V_39 -- ;
F_8 ( & V_2 -> V_4 ) ;
}
static int F_91 ( struct V_86 * V_86 , struct V_239 * V_242 )
{
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
unsigned long V_243 = V_242 -> V_244 ;
unsigned long V_50 ;
int V_245 ;
int V_12 ;
int V_34 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
V_34 = - V_51 ;
goto V_224;
}
if ( V_242 -> V_246 & V_247 )
V_20 = F_22 ( V_2 , V_5 ) ;
else
V_20 = F_21 ( V_2 , V_5 ) ;
if ( ! V_20 ) {
V_34 = - V_55 ;
goto V_224;
}
V_32 = V_20 -> V_32 ;
if ( ! V_32 ) {
V_34 = - V_55 ;
goto V_224;
}
if ( V_242 -> V_248 != 0 ) {
F_24 ( L_40 ) ;
V_34 = - V_55 ;
goto V_224;
}
V_50 = V_242 -> V_249 - V_242 -> V_244 ;
if ( V_50 > V_32 -> V_44 ) {
V_34 = - V_74 ;
goto V_224;
}
if ( V_50 & ( ~ V_41 ) ) {
V_34 = - V_74 ;
goto V_224;
}
V_245 = V_50 >> V_250 ;
for ( V_12 = 0 ; V_12 < V_245 ; ++ V_12 ) {
struct V_251 * V_48 = & V_32 -> V_252 [ V_12 ] ;
if ( F_92 ( V_242 , V_243 ,
F_93 ( F_94 ( V_48 -> V_253 ) ) ,
V_40 , V_254 ) ) {
V_34 = - V_184 ;
goto V_224;
}
V_243 += V_40 ;
}
V_242 -> V_255 = & V_256 ;
V_242 -> V_241 = V_32 ;
V_32 -> V_39 ++ ;
V_34 = 0 ;
V_224:
F_8 ( & V_2 -> V_4 ) ;
return V_34 ;
}
static unsigned int F_95 ( struct V_86 * V_86 , T_4 * V_257 )
{
unsigned int V_56 = 0 ;
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
goto V_224;
}
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && V_20 -> V_32 ) {
F_96 ( V_86 , & V_20 -> V_32 -> V_258 , V_257 ) ;
if ( ! V_20 -> V_37 || ! F_40 ( V_20 ) ||
F_97 ( V_20 -> V_32 ) > 0 )
V_56 |= V_259 | V_260 ;
}
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && V_20 -> V_32 ) {
unsigned int V_261 = F_98 ( V_20 -> V_32 -> V_82 ) ;
F_96 ( V_86 , & V_20 -> V_32 -> V_258 , V_257 ) ;
F_67 ( V_20 -> V_32 , V_20 -> V_32 -> V_44 ) ;
if ( ! V_20 -> V_37 || ! F_40 ( V_20 ) ||
F_99 ( V_20 -> V_32 ) >= V_261 )
V_56 |= V_262 | V_263 ;
}
V_224:
F_8 ( & V_2 -> V_4 ) ;
return V_56 ;
}
static T_1 F_100 ( struct V_86 * V_86 , const char T_3 * V_48 ,
T_2 V_264 , T_5 * V_265 )
{
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_144 , V_266 , V_52 = 0 , V_34 = 0 ;
F_101 ( V_257 , V_267 ) ;
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
return - V_51 ;
}
V_20 = F_22 ( V_2 , V_5 ) ;
if ( ! V_20 || ! V_20 -> V_32 )
return - V_187 ;
V_32 = V_20 -> V_32 ;
if ( ! V_20 -> V_37 || ! V_264 )
return 0 ;
if ( V_20 -> V_37 != V_86 )
return - V_133 ;
F_102 ( & V_32 -> V_258 , & V_257 ) ;
while ( V_264 > 0 && ! V_34 ) {
F_103 ( V_268 ) ;
if ( ! F_40 ( V_20 ) ) {
if ( V_52 == 0 ) {
if ( F_41 ( V_20 ) )
V_34 = - V_269 ;
else
V_34 = 0 ;
F_43 ( V_2 , V_20 ) ;
}
break;
}
V_144 = V_264 ;
V_266 = V_144 ;
if ( V_32 -> V_134 + V_266 > V_32 -> V_44 )
V_266 = V_32 -> V_44 - V_32 -> V_134 ;
F_67 ( V_32 , V_32 -> V_44 ) ;
if ( V_266 > F_99 ( V_32 ) )
V_266 = F_99 ( V_32 ) ;
if ( V_266 < V_144 )
V_144 = V_266 ;
if ( V_144 == 0 ) {
if ( V_86 -> V_270 & V_271 ) {
V_34 = - V_184 ;
break;
}
F_79 () ;
if ( F_104 ( V_267 ) ) {
V_34 = - V_272 ;
break;
}
if ( ! V_20 -> V_37 )
break;
if ( V_20 -> V_37 != V_86 ) {
V_34 = - V_133 ;
break;
}
continue;
}
V_266 = F_50 ( V_32 -> V_273 + V_32 -> V_134 ,
V_48 , V_144 ) ;
if ( V_266 ) {
V_144 -= V_266 ;
V_34 = - V_74 ;
}
F_68 ( V_32 , V_144 ) ;
V_52 += V_144 ;
V_264 -= V_144 ;
V_48 += V_144 ;
break;
}
F_103 ( V_274 ) ;
F_105 ( & V_32 -> V_258 , & V_257 ) ;
return V_52 ? V_52 : V_34 ;
}
static T_1 F_106 ( struct V_86 * V_86 , char T_3 * V_48 , T_2 V_264 ,
T_5 * V_265 )
{
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_144 , V_266 , V_52 = 0 , V_34 = 0 ;
F_101 ( V_257 , V_267 ) ;
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
return - V_51 ;
}
V_20 = F_21 ( V_2 , V_5 ) ;
if ( ! V_20 || ! V_20 -> V_32 )
return - V_187 ;
V_32 = V_20 -> V_32 ;
if ( ! V_20 -> V_37 || ! V_264 )
return 0 ;
if ( V_20 -> V_37 != V_86 )
return - V_133 ;
F_102 ( & V_32 -> V_258 , & V_257 ) ;
while ( V_264 > 0 && ! V_34 ) {
F_103 ( V_268 ) ;
V_144 = V_264 ;
V_266 = F_97 ( V_32 ) ;
if ( V_32 -> V_135 + V_266 > V_32 -> V_44 )
V_266 = V_32 -> V_44 - V_32 -> V_135 ;
if ( V_266 < V_144 )
V_144 = V_266 ;
if ( V_144 == 0 ) {
if ( ! F_40 ( V_20 ) ) {
F_43 ( V_2 , V_20 ) ;
if ( F_41 ( V_20 ) )
V_34 = - V_269 ;
else
V_34 = 0 ;
break;
}
if ( V_86 -> V_270 & V_271 ) {
V_34 = - V_184 ;
break;
}
F_79 () ;
if ( F_104 ( V_267 ) ) {
V_34 = - V_272 ;
break;
}
if ( ! V_20 -> V_37 ) {
V_34 = 0 ;
break;
}
if ( V_20 -> V_37 != V_86 ) {
V_34 = - V_133 ;
break;
}
continue;
}
V_266 = F_54 ( V_48 , V_32 -> V_273 +
V_32 -> V_135 , V_144 ) ;
if ( V_266 ) {
V_144 -= V_266 ;
V_34 = - V_74 ;
}
F_65 ( V_32 , V_144 ) ;
F_66 ( V_32 , V_144 ) ;
V_52 += V_144 ;
V_264 -= V_144 ;
V_48 += V_144 ;
break;
}
if ( F_42 ( V_20 ) &&
V_32 -> V_137 - V_32 -> V_136 == 0 ) {
F_43 ( V_2 , V_20 ) ;
}
F_103 ( V_274 ) ;
F_105 ( & V_32 -> V_258 , & V_257 ) ;
return V_52 ? V_52 : V_34 ;
}
static int F_107 ( struct V_275 * V_275 , struct V_86 * V_86 )
{
const unsigned V_5 = F_56 ( V_275 ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 ) {
F_24 ( L_41 ) ;
return - V_51 ;
}
F_5 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_8 )
goto V_276;
if ( ! F_49 ( V_277 ) && V_2 -> V_278 ) {
F_24 ( L_42 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_51 ;
}
if ( F_49 ( V_277 ) && V_2 -> V_278 )
goto V_276;
V_2 -> V_278 = true ;
#ifdef F_108
F_8 ( & V_2 -> V_4 ) ;
F_109 ( L_43 , V_18 , V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_4 ) ;
#endif
V_2 -> V_278 = false ;
if ( ! V_2 -> V_8 && ! F_49 ( V_277 ) ) {
F_24 ( L_44 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_51 ;
}
V_276:
F_110 ( V_11 ) ;
if ( V_2 -> V_8 ) {
if ( ! F_111 ( V_2 -> V_9 -> V_6 ) ) {
F_7 ( V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_279 ;
}
}
if ( V_2 -> V_8 && V_2 -> V_10 == 0 && V_2 -> V_280 ) {
int V_221 = V_2 -> V_280 ( V_2 ) ;
if ( V_221 < 0 ) {
F_7 ( V_2 -> V_9 -> V_6 ) ;
F_7 ( V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return V_221 ;
}
}
V_2 -> V_10 ++ ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_112 ( int V_281 , struct V_86 * V_86 , int V_282 )
{
const unsigned V_5 = F_56 ( F_57 ( V_86 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
return F_113 ( V_281 , V_86 , V_282 , & V_2 -> V_283 ) ;
}
static int F_114 ( struct V_275 * V_275 , struct V_86 * V_86 )
{
const unsigned V_5 = F_56 ( V_275 ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 = NULL ;
int V_12 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_69 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_68 ; V_12 ++ ) {
V_20 = & V_2 -> V_69 [ V_12 ] ;
if ( V_20 -> V_37 == V_86 )
F_46 ( V_2 , V_20 ) ;
if ( V_20 -> V_110 == V_86 )
V_20 -> V_110 = NULL ;
}
}
if ( V_2 -> V_8 && V_2 -> V_10 == 1 && V_2 -> V_284 )
V_2 -> V_284 ( V_2 ) ;
F_7 ( V_11 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_9 -> V_6 ) ;
V_2 -> V_10 -- ;
F_8 ( & V_2 -> V_4 ) ;
if ( V_86 -> V_270 & V_285 )
F_112 ( - 1 , V_86 , 0 ) ;
return 0 ;
}
void F_115 ( const struct V_1 * V_2 , const char * V_20 )
{
F_45 ( V_2 -> V_16 , L_45 , V_2 -> V_9 -> V_91 , V_20 ) ;
}
void F_116 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_31 * V_32 = V_20 -> V_32 ;
unsigned V_60 = 0 ;
unsigned V_286 = 0 ;
if ( ! F_40 ( V_20 ) )
return;
if ( V_20 ->
V_32 -> V_287 & ( V_213 | V_215 |
V_216 ) ) {
V_286 |= V_61 ;
}
if ( V_20 -> V_32 -> V_287 & ( V_215 | V_216 ) ) {
V_286 |= V_62 ;
V_60 |= V_62 ;
}
if ( V_286 ) {
F_36 ( V_20 , V_286 , V_60 ) ;
}
if ( V_32 -> V_212 & V_20 -> V_32 -> V_287 ) {
if ( F_39 ( V_20 ) & V_219 ) {
F_117 ( & V_32 -> V_258 ) ;
if ( V_20 -> V_26 & V_27 )
F_118 ( & V_2 -> V_283 , V_288 , V_289 ) ;
if ( V_20 -> V_26 & V_29 )
F_118 ( & V_2 -> V_283 , V_288 , V_290 ) ;
} else {
if ( V_32 -> V_291 )
V_32 -> V_291 ( V_20 -> V_32 -> V_287 , V_32 -> V_292 ) ;
}
}
V_20 -> V_32 -> V_287 = 0 ;
}
struct V_1 * F_119 ( struct V_25 * V_293 )
{
struct V_1 * V_2 ;
struct V_25 * V_45 ;
unsigned V_12 ;
V_2 = F_120 ( sizeof( struct V_1 ) , V_97 ) ;
if ( V_2 == NULL )
return F_121 ( - V_98 ) ;
F_1 ( V_2 ) ;
F_122 ( V_2 , V_293 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_5 ( & V_14 ) ;
for ( V_12 = V_293 ? V_79 : 0 ;
V_12 < V_21 ; ++ V_12 ) {
if ( V_15 [ V_12 ] == NULL ) {
V_15 [ V_12 ] = V_2 ;
break;
}
}
F_8 ( & V_14 ) ;
if ( V_12 == V_21 ) {
F_8 ( & V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
F_15 ( V_2 ) ;
F_123 ( L_46 ) ;
return F_121 ( - V_38 ) ;
}
V_2 -> V_5 = V_12 ;
V_45 = F_124 ( V_17 , V_293 ,
F_14 ( V_18 , V_12 ) , NULL , L_47 , V_12 ) ;
if ( ! F_125 ( V_45 ) )
V_2 -> V_16 = V_45 ;
return V_2 ;
}
static void F_126 ( unsigned V_5 )
{
F_17 ( V_5 >= V_21 ) ;
F_12 ( F_11 ( V_5 ) ) ;
}
void F_127 ( struct V_25 * V_293 )
{
int V_5 ;
struct V_1 * V_2 ;
for ( V_5 = V_79 ; V_5 < V_21 ;
V_5 ++ ) {
F_5 ( & V_14 ) ;
V_2 = V_15 [ V_5 ] ;
if ( V_2 && V_2 -> V_294 == V_293 ) {
V_15 [ V_5 ] = NULL ;
F_8 ( & V_14 ) ;
F_12 ( V_2 ) ;
break;
}
F_8 ( & V_14 ) ;
}
}
int F_128 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_25 ;
struct V_25 * V_45 ;
unsigned V_12 ;
F_5 ( & V_23 ) ;
for ( V_12 = 0 ; V_12 < V_22 ; ++ V_12 ) {
if ( V_24 [ V_12 ] == NULL ) {
V_24 [ V_12 ] = V_20 ;
break;
}
}
F_8 ( & V_23 ) ;
if ( V_12 == V_22 ) {
F_123 ( L_48 ) ;
return - V_38 ;
}
V_12 += V_21 ;
V_20 -> V_5 = V_12 ;
V_45 = F_124 ( V_17 , V_2 -> V_16 ,
F_14 ( V_18 , V_12 ) , NULL , L_49 ,
V_2 -> V_5 , V_20 -> V_43 ) ;
if ( ! F_125 ( V_45 ) )
V_20 -> V_16 = V_45 ;
return 0 ;
}
void F_129 ( struct V_19 * V_20 )
{
unsigned int V_12 ;
if ( V_20 == NULL )
return;
if ( V_20 -> V_5 < 0 )
return;
F_17 ( V_20 -> V_5 >= V_295 ) ;
F_17 ( V_20 -> V_5 < V_21 ) ;
V_12 = V_20 -> V_5 - V_21 ;
F_5 ( & V_23 ) ;
if ( V_20 == V_24 [ V_12 ] )
V_24 [ V_12 ] = NULL ;
F_8 ( & V_23 ) ;
if ( V_20 -> V_16 ) {
F_13 ( V_17 , F_14 ( V_18 , V_20 -> V_5 ) ) ;
V_20 -> V_16 = NULL ;
}
}
static void F_130 ( void )
{
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ )
F_126 ( V_12 ) ;
}
static int T_6 F_131 ( void )
{
int V_12 ;
int V_34 ;
F_132 ( L_50 V_296 L_51 ) ;
if ( V_79 < 0 ||
V_79 > V_21 ) {
F_123 ( L_52 ,
V_21 ) ;
return - V_55 ;
}
V_34 = F_133 ( F_14 ( V_18 , 0 ) ,
V_295 , L_53 ) ;
if ( V_34 )
return - V_187 ;
F_134 ( & V_297 , & V_298 ) ;
V_297 . V_299 = V_11 ;
F_135 ( & V_297 . V_300 , L_53 ) ;
if ( F_136 ( & V_297 , F_14 ( V_18 , 0 ) , V_295 ) ) {
F_137 ( F_14 ( V_18 , 0 ) ,
V_295 ) ;
return - V_187 ;
}
V_17 = F_138 ( V_11 , L_53 ) ;
if ( F_125 ( V_17 ) ) {
F_123 ( L_54 ) ;
F_139 ( & V_297 ) ;
F_137 ( F_14 ( V_18 , 0 ) ,
V_295 ) ;
return F_140 ( V_17 ) ;
}
V_17 -> V_301 = V_302 ;
F_141 () ;
for ( V_12 = 0 ; V_12 < V_79 ; V_12 ++ ) {
struct V_1 * V_2 ;
V_2 = F_119 ( NULL ) ;
if ( F_125 ( V_2 ) ) {
F_130 () ;
F_139 ( & V_297 ) ;
F_137 ( F_14 ( V_18 , 0 ) ,
V_295 ) ;
return F_140 ( V_2 ) ;
} else {
F_8 ( & V_2 -> V_4 ) ;
}
}
return 0 ;
}
static void T_7 F_142 ( void )
{
int V_12 ;
F_130 () ;
for ( V_12 = 0 ; V_12 < V_21 ; ++ V_12 )
F_17 ( V_15 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < V_22 ; ++ V_12 )
F_17 ( V_24 [ V_12 ] ) ;
F_143 ( V_17 ) ;
F_139 ( & V_297 ) ;
F_137 ( F_14 ( V_18 , 0 ) , V_295 ) ;
F_144 () ;
}
