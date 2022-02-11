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
void * F_43 ( struct V_19 * V_20 , T_2 V_50 )
{
V_20 -> V_63 = F_44 ( V_50 , V_64 ) ;
if ( V_20 -> V_63 )
V_20 -> V_60 |= V_65 ;
return V_20 -> V_63 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_31 * V_32 = V_20 -> V_32 ;
F_36 ( V_20 , V_61 , 0 ) ;
if ( V_32 ) {
F_46 ( V_32 ) ;
V_32 -> V_66 = NULL ;
F_15 ( V_32 -> V_67 . V_68 ) ;
V_32 -> V_67 . V_68 = NULL ;
} else {
F_47 ( V_2 -> V_16 ,
L_5 ) ;
}
V_20 -> V_37 = NULL ;
}
static int F_48 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_69 = 0 ;
if ( F_40 ( V_20 ) && V_20 -> V_70 )
V_69 = V_20 -> V_70 ( V_2 , V_20 ) ;
F_45 ( V_2 , V_20 ) ;
return V_69 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
int V_12 ;
if ( ! V_2 -> V_8 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_71 ; V_12 ++ ) {
V_20 = & V_2 -> V_72 [ V_12 ] ;
if ( V_20 -> V_37 )
return 1 ;
if ( V_20 -> V_32 && V_20 -> V_32 -> V_39 )
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_73 T_3 * V_74 )
{
struct V_73 V_75 ;
if ( ! F_51 ( V_76 ) )
return - V_36 ;
if ( V_74 == NULL ) {
if ( F_49 ( V_2 ) )
return - V_38 ;
if ( V_2 -> V_8 ) {
struct V_6 * V_7 = V_2 -> V_9 -> V_6 ;
F_6 ( V_2 ) ;
F_7 ( V_7 ) ;
}
return 0 ;
}
if ( F_52 ( & V_75 , V_74 , sizeof( V_75 ) ) )
return - V_77 ;
V_75 . V_78 [ V_79 - 1 ] = 0 ;
if ( V_75 . V_80 [ V_81 ] ) {
F_53 ( V_2 -> V_16 ,
L_6 ) ;
return - V_55 ;
}
if ( V_2 -> V_5 >= V_82 )
return - V_38 ;
return F_54 ( V_2 , & V_75 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_83 T_3 * V_74 )
{
struct V_83 V_84 ;
struct V_31 * V_32 ;
struct V_19 * V_20 ;
int V_34 = 0 ;
if ( F_52 ( & V_84 , V_74 , sizeof( V_84 ) ) )
return - V_77 ;
if ( V_84 . V_85 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_84 . V_85 ] ;
V_32 = V_20 -> V_32 ;
if ( ! V_32 ) {
F_24 ( L_7 ) ;
V_84 . V_50 = 0 ;
V_84 . V_86 = 0 ;
goto V_87;
}
if ( V_84 . V_86 ) {
if ( ! F_51 ( V_76 ) )
return - V_36 ;
V_32 -> V_35 = V_84 . V_86 ;
}
if ( V_84 . V_50 ) {
V_34 = F_23 ( V_2 , V_20 , V_32 , V_84 . V_50 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_84 . V_50 = V_32 -> V_44 ;
V_84 . V_86 = V_32 -> V_35 ;
V_87:
if ( F_56 ( V_74 , & V_84 , sizeof( V_84 ) ) )
return - V_77 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_88 T_3 * V_74 ,
struct V_89 * V_89 )
{
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
struct V_19 * V_20 ;
struct V_88 V_90 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_91 = V_92 ;
V_90 . V_93 = V_2 -> V_71 ;
F_60 ( V_90 . V_94 , V_2 -> V_9 -> V_94 , V_79 ) ;
F_60 ( V_90 . V_78 , V_2 -> V_78 , V_79 ) ;
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 )
V_90 . V_95 = V_20 -> V_43 ;
else
V_90 . V_95 = - 1 ;
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 )
V_90 . V_96 = V_20 -> V_43 ;
else
V_90 . V_96 = - 1 ;
if ( F_56 ( V_74 , & V_90 , sizeof( V_90 ) ) )
return - V_77 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_97 T_3 * V_74 , void * V_89 )
{
int V_69 , V_12 ;
struct V_97 * V_98 , * V_99 ;
struct V_19 * V_20 ;
V_98 = F_62 ( V_2 -> V_71 , sizeof( * V_98 ) , V_64 ) ;
if ( ! V_98 )
return - V_100 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_71 ; V_12 ++ ) {
V_20 = & V_2 -> V_72 [ V_12 ] ;
V_99 = V_98 + V_12 ;
V_99 -> type = V_20 -> type ;
V_99 -> V_101 = V_20 -> V_101 ;
V_99 -> V_102 = V_20 -> V_26 ;
if ( F_40 ( V_20 ) )
V_99 -> V_102 |= V_103 ;
#define F_63 5
V_99 -> V_104 = F_63 ;
V_99 -> V_105 = V_20 -> V_105 ;
V_99 -> V_106 = V_20 -> V_106 ;
if ( V_20 -> V_107 ) {
V_99 -> V_108 =
( V_12 << 24 ) | ( 0 << 16 ) | ( V_20 -> V_107 -> V_109 ) ;
} else {
V_99 -> V_108 = 0 ;
}
if ( V_20 -> V_37 )
V_99 -> V_102 |= V_110 ;
if ( V_20 -> V_37 == V_89 )
V_99 -> V_102 |= V_111 ;
if ( V_20 -> V_112 )
V_99 -> V_102 |= V_113 ;
if ( V_20 -> V_112 == V_89 )
V_99 -> V_102 |= V_114 ;
if ( ! V_20 -> V_106 && V_20 -> V_115 )
V_99 -> V_102 |= V_116 ;
if ( V_20 -> V_117 )
V_99 -> V_102 |= V_118 ;
if ( V_20 -> V_119 )
V_99 -> V_102 |= V_120 ;
if ( V_20 -> V_121 != & V_122 )
V_99 -> V_123 = V_124 ;
else
V_99 -> V_123 = V_125 ;
}
V_69 = F_56 ( V_74 , V_98 , V_2 -> V_71 * sizeof( * V_98 ) ) ;
F_15 ( V_98 ) ;
return V_69 ? - V_77 : 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_126 T_3 * V_74 )
{
struct V_19 * V_20 ;
struct V_126 V_75 ;
if ( F_52 ( & V_75 , V_74 , sizeof( V_75 ) ) )
return - V_77 ;
if ( V_75 . V_127 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_75 . V_127 ] ;
if ( V_75 . V_115 ) {
if ( V_20 -> V_106 || ! V_20 -> V_115 )
return - V_55 ;
if ( F_56 ( V_75 . V_115 , V_20 -> V_115 ,
V_20 -> V_101 * sizeof( unsigned int ) ) )
return - V_77 ;
}
if ( V_75 . V_128 )
return - V_55 ;
if ( V_75 . V_129 ) {
int V_12 ;
if ( ! V_20 -> V_117 )
return - V_55 ;
for ( V_12 = 0 ; V_12 < V_20 -> V_101 ; V_12 ++ ) {
int V_130 ;
V_130 = ( V_2 -> V_5 << 28 ) | ( V_75 . V_127 << 24 ) | ( V_12 << 16 ) |
( V_20 -> V_117 [ V_12 ] -> V_109 ) ;
if ( F_65 ( V_130 , V_75 . V_129 + V_12 ) )
return - V_77 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_131 T_3 * V_74 , void * V_89 )
{
struct V_131 V_132 ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
if ( F_52 ( & V_132 , V_74 , sizeof( V_132 ) ) )
return - V_77 ;
if ( V_132 . V_85 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_132 . V_85 ] ;
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 )
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
goto V_87;
}
if ( ! V_20 -> V_37 ) {
V_132 . V_138 = 0 ;
V_132 . V_139 = 0 ;
goto V_140;
}
if ( V_20 -> V_37 != V_89 )
return - V_133 ;
if ( V_132 . V_138 && ( V_20 -> V_26 & V_27 ) ) {
V_132 . V_138 = F_67 ( V_32 , V_132 . V_138 ) ;
F_68 ( V_32 , V_132 . V_138 ) ;
if ( F_42 ( V_20 ) &&
V_32 -> V_136 == V_32 -> V_137 ) {
F_45 ( V_2 , V_20 ) ;
}
}
if ( V_132 . V_139 && ( V_20 -> V_26 & V_29 ) ) {
V_132 . V_139 =
F_69 ( V_32 , V_132 . V_139 ) ;
F_70 ( V_32 , V_132 . V_139 ) ;
}
V_140:
V_132 . V_136 = V_32 -> V_136 ;
V_132 . V_134 = V_32 -> V_134 ;
V_132 . V_137 = V_32 -> V_137 ;
V_132 . V_135 = V_32 -> V_135 ;
V_87:
if ( F_56 ( V_74 , & V_132 , sizeof( V_132 ) ) )
return - V_77 ;
return 0 ;
}
static int F_71 ( struct V_141 * V_142 ,
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
F_72 ( L_8 ,
V_143 [ 0 ] ) ;
F_72 ( L_9 ,
V_175 , __FILE__ ) ;
F_72 ( L_10 , V_142 -> V_144 ) ;
return 0 ;
}
return - V_55 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_141 * V_142 ,
unsigned int * V_143 , void * V_89 )
{
struct V_19 * V_20 ;
int V_69 = 0 ;
int V_12 ;
if ( V_142 -> V_142 & V_176 ) {
switch ( V_142 -> V_142 ) {
case V_177 :
{
struct V_178 V_179 ;
if ( V_142 -> V_144 != 2 ) {
V_69 = - V_55 ;
break;
}
F_74 ( & V_179 ) ;
V_143 [ 0 ] = V_179 . V_180 ;
V_143 [ 1 ] = V_179 . V_181 ;
V_69 = 2 ;
break;
}
case V_182 :
if ( V_142 -> V_144 != 1 || V_143 [ 0 ] >= 100000 ) {
V_69 = - V_55 ;
break;
}
F_75 ( V_143 [ 0 ] / 1000 ) ;
V_69 = 1 ;
break;
case V_183 :
if ( V_142 -> V_144 != 1 ) {
V_69 = - V_55 ;
break;
}
if ( V_142 -> V_127 >= V_2 -> V_71 ) {
F_24 ( L_11 ,
V_142 -> V_127 ) ;
V_69 = - V_55 ;
break;
}
V_20 = & V_2 -> V_72 [ V_142 -> V_127 ] ;
if ( ! V_20 -> V_32 ) {
F_24 ( L_12 ) ;
V_69 = - V_55 ;
break;
}
if ( ! V_20 -> V_32 -> V_66 ) {
F_24 ( L_13 ) ;
V_69 = - V_184 ;
break;
}
V_69 = V_20 -> V_32 -> V_66 ( V_2 , V_20 , V_143 [ 0 ] ) ;
if ( V_69 >= 0 )
V_69 = 1 ;
break;
default:
F_24 ( L_14 ) ;
V_69 = - V_55 ;
break;
}
} else {
unsigned int V_106 ;
if ( V_142 -> V_127 >= V_2 -> V_71 ) {
F_24 ( L_15 , V_142 -> V_127 ) ;
V_69 = - V_55 ;
goto V_185;
}
V_20 = & V_2 -> V_72 [ V_142 -> V_127 ] ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_11 , V_142 -> V_127 ) ;
V_69 = - V_187 ;
goto V_185;
}
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 ) {
F_24 ( L_16 ) ;
V_69 = - V_133 ;
goto V_185;
}
V_69 = F_76 ( V_20 , 1 , & V_142 -> V_188 ) ;
if ( V_69 < 0 ) {
V_69 = - V_55 ;
F_24 ( L_17 ) ;
goto V_185;
}
if ( V_20 -> V_37 ) {
V_69 = - V_38 ;
goto V_185;
}
V_20 -> V_37 = & F_73 ;
switch ( V_142 -> V_142 ) {
case V_189 :
V_69 = V_20 -> V_190 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
case V_191 :
V_106 = V_20 -> V_115
? V_20 -> V_115 [ F_77 ( V_142 -> V_188 ) ]
: V_20 -> V_106 ;
for ( V_12 = 0 ; V_12 < V_142 -> V_144 ; ++ V_12 ) {
if ( V_143 [ V_12 ] > V_106 ) {
V_69 = - V_55 ;
F_24 ( L_18 ) ;
break;
}
}
if ( V_69 == 0 )
V_69 = V_20 -> V_192 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
case V_193 :
if ( V_142 -> V_144 != 2 ) {
V_69 = - V_55 ;
} else {
unsigned int V_194 ;
unsigned int V_195 ;
V_195 = V_143 [ 0 ] ;
if ( V_20 -> V_101 <= 32 ) {
V_194 = F_77 ( V_142 -> V_188 ) ;
if ( V_194 > 0 ) {
V_142 -> V_188 = 0 ;
V_143 [ 0 ] <<= V_194 ;
V_143 [ 1 ] <<= V_194 ;
}
} else
V_194 = 0 ;
V_69 = V_20 -> V_121 ( V_2 , V_20 , V_142 , V_143 ) ;
V_143 [ 0 ] = V_195 ;
if ( V_194 > 0 )
V_143 [ 1 ] >>= V_194 ;
}
break;
case V_196 :
V_69 = F_71 ( V_142 , V_143 ) ;
if ( V_69 )
break;
V_69 = V_20 -> V_197 ( V_2 , V_20 , V_142 , V_143 ) ;
break;
default:
V_69 = - V_55 ;
break;
}
V_20 -> V_37 = NULL ;
}
V_185:
return V_69 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_198 T_3 * V_74 , void * V_89 )
{
struct V_198 V_199 ;
struct V_141 * V_200 = NULL ;
unsigned int * V_143 = NULL ;
int V_12 = 0 ;
int V_69 = 0 ;
if ( F_52 ( & V_199 , V_74 , sizeof( V_199 ) ) )
return - V_77 ;
V_143 = F_79 ( sizeof( unsigned int ) * V_201 , V_64 ) ;
if ( ! V_143 ) {
F_24 ( L_19 ) ;
V_69 = - V_100 ;
goto error;
}
V_200 = F_62 ( V_199 . V_202 , sizeof( * V_200 ) , V_64 ) ;
if ( ! V_200 ) {
F_24 ( L_19 ) ;
V_69 = - V_100 ;
goto error;
}
if ( F_52 ( V_200 , V_199 . V_200 ,
sizeof( * V_200 ) * V_199 . V_202 ) ) {
F_24 ( L_20 ) ;
V_69 = - V_77 ;
goto error;
}
for ( V_12 = 0 ; V_12 < V_199 . V_202 ; V_12 ++ ) {
if ( V_200 [ V_12 ] . V_144 > V_201 ) {
F_24 ( L_21 ) ;
V_69 = - V_55 ;
goto error;
}
if ( V_200 [ V_12 ] . V_142 & V_203 ) {
if ( F_52 ( V_143 , V_200 [ V_12 ] . V_143 ,
V_200 [ V_12 ] . V_144 * sizeof( unsigned int ) ) ) {
F_24 ( L_20 ) ;
V_69 = - V_77 ;
goto error;
}
}
V_69 = F_73 ( V_2 , V_200 + V_12 , V_143 , V_89 ) ;
if ( V_69 < 0 )
goto error;
if ( V_200 [ V_12 ] . V_142 & V_204 ) {
if ( F_56 ( V_200 [ V_12 ] . V_143 , V_143 ,
V_200 [ V_12 ] . V_144 * sizeof( unsigned int ) ) ) {
F_24 ( L_22 ) ;
V_69 = - V_77 ;
goto error;
}
}
if ( F_80 () )
F_81 () ;
}
error:
F_15 ( V_200 ) ;
F_15 ( V_143 ) ;
if ( V_69 < 0 )
return V_69 ;
return V_12 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_141 T_3 * V_74 , void * V_89 )
{
struct V_141 V_142 ;
unsigned int * V_143 = NULL ;
int V_69 = 0 ;
V_143 = F_79 ( sizeof( unsigned int ) * V_201 , V_64 ) ;
if ( ! V_143 ) {
V_69 = - V_100 ;
goto error;
}
if ( F_52 ( & V_142 , V_74 , sizeof( V_142 ) ) ) {
V_69 = - V_77 ;
goto error;
}
if ( V_142 . V_144 > V_201 )
V_142 . V_144 = V_201 ;
if ( V_142 . V_142 & V_203 ) {
if ( F_52 ( V_143 ,
V_142 . V_143 ,
V_142 . V_144 * sizeof( unsigned int ) ) ) {
V_69 = - V_77 ;
goto error;
}
}
V_69 = F_73 ( V_2 , & V_142 , V_143 , V_89 ) ;
if ( V_69 < 0 )
goto error;
if ( V_142 . V_142 & V_204 ) {
if ( F_56 ( V_142 . V_143 ,
V_143 ,
V_142 . V_144 * sizeof( unsigned int ) ) ) {
V_69 = - V_77 ;
goto error;
}
}
V_69 = V_142 . V_144 ;
error:
F_15 ( V_143 ) ;
return V_69 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_205 T_3 * V_74 , void * V_89 )
{
struct V_205 V_67 ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_69 = 0 ;
unsigned int T_3 * V_206 ;
if ( F_52 ( & V_67 , V_74 , sizeof( V_67 ) ) ) {
F_24 ( L_23 ) ;
return - V_77 ;
}
V_206 = ( unsigned int T_3 * ) V_67 . V_68 ;
if ( V_67 . V_127 >= V_2 -> V_71 ) {
F_24 ( L_24 , V_67 . V_127 ) ;
return - V_51 ;
}
V_20 = & V_2 -> V_72 [ V_67 . V_127 ] ;
V_32 = V_20 -> V_32 ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_25 , V_67 . V_127 ) ;
return - V_187 ;
}
if ( ! V_20 -> V_119 || ! V_20 -> V_207 || ! V_20 -> V_32 ) {
F_24 ( L_26 ,
V_67 . V_127 ) ;
return - V_187 ;
}
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 ) {
F_24 ( L_27 ) ;
return - V_133 ;
}
if ( V_20 -> V_37 ) {
F_24 ( L_28 ) ;
return - V_38 ;
}
if ( V_67 . V_208 > V_20 -> V_105 ) {
F_24 ( L_29 ,
V_67 . V_208 , V_20 -> V_105 ) ;
return - V_55 ;
}
if ( V_67 . V_208 < 1 ) {
F_24 ( L_30 ,
V_67 . V_208 ) ;
return - V_55 ;
}
V_32 -> V_67 = V_67 ;
V_32 -> V_67 . V_143 = NULL ;
V_32 -> V_67 . V_68 = F_84 ( V_206 ,
V_32 -> V_67 . V_208 * sizeof( int ) ) ;
if ( F_85 ( V_32 -> V_67 . V_68 ) ) {
V_69 = F_86 ( V_32 -> V_67 . V_68 ) ;
F_24 ( L_31 , V_69 ) ;
goto V_209;
}
V_69 = F_76 ( V_20 ,
V_32 -> V_67 . V_208 ,
V_32 -> V_67 . V_68 ) ;
if ( V_69 < 0 ) {
F_24 ( L_32 ) ;
goto V_209;
}
V_69 = V_20 -> V_207 ( V_2 , V_20 , & V_32 -> V_67 ) ;
if ( V_32 -> V_67 . V_58 & V_210 || V_69 ) {
F_24 ( L_33 , V_69 ) ;
V_67 = V_32 -> V_67 ;
V_67 . V_68 = ( unsigned int V_211 * ) V_206 ;
V_67 . V_143 = NULL ;
if ( F_56 ( V_74 , & V_67 , sizeof( V_67 ) ) ) {
F_24 ( L_34 ) ;
V_69 = - V_77 ;
goto V_209;
}
V_69 = - V_184 ;
goto V_209;
}
if ( ! V_32 -> V_44 ) {
V_69 = - V_100 ;
F_24 ( L_35 ) ;
goto V_209;
}
F_46 ( V_32 ) ;
V_32 -> V_212 =
V_213 | V_214 | V_215 |
V_216 ;
if ( V_32 -> V_67 . V_58 & V_217 )
V_32 -> V_212 |= V_218 ;
F_36 ( V_20 , V_219 | V_62 | V_61 ,
V_219 | V_61 ) ;
V_20 -> V_37 = V_89 ;
V_69 = V_20 -> V_119 ( V_2 , V_20 ) ;
if ( V_69 == 0 )
return 0 ;
V_209:
F_45 ( V_2 , V_20 ) ;
return V_69 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_205 T_3 * V_74 , void * V_89 )
{
struct V_205 V_67 ;
struct V_19 * V_20 ;
int V_69 = 0 ;
unsigned int * V_68 = NULL ;
unsigned int T_3 * V_206 ;
if ( F_52 ( & V_67 , V_74 , sizeof( V_67 ) ) ) {
F_24 ( L_23 ) ;
return - V_77 ;
}
V_206 = ( unsigned int T_3 * ) V_67 . V_68 ;
if ( V_67 . V_127 >= V_2 -> V_71 ) {
F_24 ( L_24 , V_67 . V_127 ) ;
return - V_51 ;
}
V_20 = & V_2 -> V_72 [ V_67 . V_127 ] ;
if ( V_20 -> type == V_186 ) {
F_24 ( L_25 , V_67 . V_127 ) ;
return - V_187 ;
}
if ( ! V_20 -> V_119 || ! V_20 -> V_207 ) {
F_24 ( L_26 ,
V_67 . V_127 ) ;
return - V_187 ;
}
if ( V_67 . V_208 > V_20 -> V_105 ) {
F_24 ( L_36 ,
V_67 . V_208 , V_20 -> V_105 ) ;
V_69 = - V_55 ;
goto V_209;
}
if ( V_67 . V_68 ) {
V_68 = F_84 ( V_206 ,
V_67 . V_208 * sizeof( int ) ) ;
if ( F_85 ( V_68 ) ) {
V_69 = F_86 ( V_68 ) ;
F_24 ( L_37 , V_69 ) ;
goto V_209;
}
V_69 = F_76 ( V_20 , V_67 . V_208 , V_68 ) ;
if ( V_69 < 0 ) {
F_24 ( L_32 ) ;
goto V_209;
}
V_67 . V_68 = V_68 ;
}
V_69 = V_20 -> V_207 ( V_2 , V_20 , & V_67 ) ;
V_67 . V_68 = ( unsigned int V_211 * ) V_206 ;
if ( F_56 ( V_74 , & V_67 , sizeof( V_67 ) ) ) {
F_24 ( L_23 ) ;
V_69 = - V_77 ;
goto V_209;
}
V_209:
F_15 ( V_68 ) ;
return V_69 ;
}
static int F_88 ( struct V_1 * V_2 , unsigned int V_74 ,
void * V_89 )
{
int V_69 = 0 ;
unsigned long V_58 ;
struct V_19 * V_20 ;
if ( V_74 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_74 ] ;
F_37 ( & V_20 -> V_59 , V_58 ) ;
if ( V_20 -> V_37 || V_20 -> V_112 )
V_69 = - V_38 ;
else
V_20 -> V_112 = V_89 ;
F_38 ( & V_20 -> V_59 , V_58 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_69 ;
}
static int F_89 ( struct V_1 * V_2 , unsigned int V_74 ,
void * V_89 )
{
struct V_19 * V_20 ;
if ( V_74 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_74 ] ;
if ( V_20 -> V_37 )
return - V_38 ;
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 )
return - V_133 ;
if ( V_20 -> V_112 == V_89 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_20 -> V_112 = NULL ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , unsigned int V_74 ,
void * V_89 )
{
struct V_19 * V_20 ;
int V_69 ;
if ( V_74 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_74 ] ;
if ( V_20 -> V_32 == NULL )
return - V_55 ;
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 )
return - V_133 ;
if ( ! V_20 -> V_37 )
return 0 ;
if ( V_20 -> V_37 != V_89 )
return - V_38 ;
V_69 = F_48 ( V_2 , V_20 ) ;
if ( F_39 ( V_20 ) & V_219 )
F_91 ( & V_20 -> V_32 -> V_220 ) ;
return V_69 ;
}
static int F_92 ( struct V_1 * V_2 , unsigned int V_74 ,
void * V_89 )
{
struct V_19 * V_20 ;
if ( V_74 >= V_2 -> V_71 )
return - V_55 ;
V_20 = & V_2 -> V_72 [ V_74 ] ;
if ( V_20 -> V_112 && V_20 -> V_112 != V_89 )
return - V_133 ;
if ( ! V_20 -> V_37 )
return 0 ;
if ( V_20 -> V_37 != V_89 )
return - V_38 ;
if ( V_20 -> V_221 )
return V_20 -> V_221 ( V_2 , V_20 ) ;
return - V_55 ;
}
static long F_93 ( struct V_89 * V_89 , unsigned int V_67 ,
unsigned long V_74 )
{
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
int V_222 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_67 == V_223 ) {
if ( V_5 >= V_21 ) {
V_222 = - V_224 ;
goto V_225;
}
V_222 = F_50 ( V_2 ,
(struct V_73 T_3 * ) V_74 ) ;
if ( V_222 == 0 ) {
if ( V_74 == 0 &&
V_2 -> V_5 >= V_82 ) {
if ( F_10 ( V_2 ) ) {
F_8 ( & V_2 -> V_4 ) ;
F_12 ( V_2 ) ;
return V_222 ;
}
}
}
goto V_225;
}
if ( ! V_2 -> V_8 ) {
F_24 ( L_38 , V_2 -> V_5 ) ;
V_222 = - V_51 ;
goto V_225;
}
switch ( V_67 ) {
case V_226 :
V_222 = F_55 ( V_2 ,
(struct V_83 T_3 * ) V_74 ) ;
break;
case V_227 :
V_222 = F_57 ( V_2 , (struct V_88 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_228 :
V_222 = F_61 ( V_2 ,
(struct V_97 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_229 :
V_222 = F_64 ( V_2 , ( void T_3 * ) V_74 ) ;
break;
case V_230 :
V_222 = F_94 ( V_2 , ( void T_3 * ) V_74 ) ;
break;
case V_231 :
V_222 = F_66 ( V_2 ,
(struct V_131 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_232 :
V_222 = F_88 ( V_2 , V_74 , V_89 ) ;
break;
case V_233 :
V_222 = F_89 ( V_2 , V_74 , V_89 ) ;
break;
case V_234 :
V_222 = F_90 ( V_2 , V_74 , V_89 ) ;
break;
case V_235 :
V_222 = F_83 ( V_2 , (struct V_205 T_3 * ) V_74 , V_89 ) ;
break;
case V_236 :
V_222 = F_87 ( V_2 , (struct V_205 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_237 :
V_222 = F_78 ( V_2 ,
(struct V_198 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_238 :
V_222 = F_82 ( V_2 , (struct V_141 T_3 * ) V_74 ,
V_89 ) ;
break;
case V_239 :
V_222 = F_92 ( V_2 , V_74 , V_89 ) ;
break;
default:
V_222 = - V_224 ;
break;
}
V_225:
F_8 ( & V_2 -> V_4 ) ;
return V_222 ;
}
static void F_95 ( struct V_240 * V_241 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
V_32 = V_241 -> V_242 ;
V_2 = V_32 -> V_85 -> V_25 ;
F_5 ( & V_2 -> V_4 ) ;
V_32 -> V_39 ++ ;
F_8 ( & V_2 -> V_4 ) ;
}
static void F_96 ( struct V_240 * V_241 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
V_32 = V_241 -> V_242 ;
V_2 = V_32 -> V_85 -> V_25 ;
F_5 ( & V_2 -> V_4 ) ;
V_32 -> V_39 -- ;
F_8 ( & V_2 -> V_4 ) ;
}
static int F_97 ( struct V_89 * V_89 , struct V_240 * V_243 )
{
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
unsigned long V_244 = V_243 -> V_245 ;
unsigned long V_50 ;
int V_246 ;
int V_12 ;
int V_34 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
V_34 = - V_51 ;
goto V_225;
}
if ( V_243 -> V_247 & V_248 )
V_20 = F_22 ( V_2 , V_5 ) ;
else
V_20 = F_21 ( V_2 , V_5 ) ;
if ( ! V_20 ) {
V_34 = - V_55 ;
goto V_225;
}
V_32 = V_20 -> V_32 ;
if ( ! V_32 ) {
V_34 = - V_55 ;
goto V_225;
}
if ( V_243 -> V_249 != 0 ) {
F_24 ( L_40 ) ;
V_34 = - V_55 ;
goto V_225;
}
V_50 = V_243 -> V_250 - V_243 -> V_245 ;
if ( V_50 > V_32 -> V_44 ) {
V_34 = - V_77 ;
goto V_225;
}
if ( V_50 & ( ~ V_41 ) ) {
V_34 = - V_77 ;
goto V_225;
}
V_246 = V_50 >> V_251 ;
for ( V_12 = 0 ; V_12 < V_246 ; ++ V_12 ) {
struct V_252 * V_48 = & V_32 -> V_253 [ V_12 ] ;
if ( F_98 ( V_243 , V_244 ,
F_99 ( F_100 ( V_48 -> V_254 ) ) ,
V_40 , V_255 ) ) {
V_34 = - V_184 ;
goto V_225;
}
V_244 += V_40 ;
}
V_243 -> V_256 = & V_257 ;
V_243 -> V_242 = V_32 ;
V_32 -> V_39 ++ ;
V_34 = 0 ;
V_225:
F_8 ( & V_2 -> V_4 ) ;
return V_34 ;
}
static unsigned int F_101 ( struct V_89 * V_89 , T_4 * V_258 )
{
unsigned int V_56 = 0 ;
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_8 ) {
F_24 ( L_39 , V_2 -> V_5 ) ;
goto V_225;
}
V_20 = F_21 ( V_2 , V_5 ) ;
if ( V_20 && V_20 -> V_32 ) {
F_102 ( V_89 , & V_20 -> V_32 -> V_220 , V_258 ) ;
if ( ! V_20 -> V_37 || ! F_40 ( V_20 ) ||
F_103 ( V_20 -> V_32 ) > 0 )
V_56 |= V_259 | V_260 ;
}
V_20 = F_22 ( V_2 , V_5 ) ;
if ( V_20 && V_20 -> V_32 ) {
unsigned int V_261 = F_104 ( V_20 -> V_32 -> V_85 ) ;
F_102 ( V_89 , & V_20 -> V_32 -> V_220 , V_258 ) ;
F_69 ( V_20 -> V_32 , V_20 -> V_32 -> V_44 ) ;
if ( ! V_20 -> V_37 || ! F_40 ( V_20 ) ||
F_105 ( V_20 -> V_32 ) >= V_261 )
V_56 |= V_262 | V_263 ;
}
V_225:
F_8 ( & V_2 -> V_4 ) ;
return V_56 ;
}
static T_1 F_106 ( struct V_89 * V_89 , const char T_3 * V_48 ,
T_2 V_264 , T_5 * V_265 )
{
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_144 , V_266 , V_52 = 0 , V_34 = 0 ;
F_107 ( V_258 , V_267 ) ;
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
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
if ( V_20 -> V_37 != V_89 )
return - V_133 ;
F_108 ( & V_32 -> V_220 , & V_258 ) ;
while ( V_264 > 0 && ! V_34 ) {
F_109 ( V_268 ) ;
if ( ! F_40 ( V_20 ) ) {
if ( V_52 == 0 ) {
F_5 ( & V_2 -> V_4 ) ;
if ( F_41 ( V_20 ) )
V_34 = - V_269 ;
else
V_34 = 0 ;
F_45 ( V_2 , V_20 ) ;
F_8 ( & V_2 -> V_4 ) ;
}
break;
}
V_144 = V_264 ;
V_266 = V_144 ;
if ( V_32 -> V_134 + V_266 > V_32 -> V_44 )
V_266 = V_32 -> V_44 - V_32 -> V_134 ;
F_69 ( V_32 , V_32 -> V_44 ) ;
if ( V_266 > F_105 ( V_32 ) )
V_266 = F_105 ( V_32 ) ;
if ( V_266 < V_144 )
V_144 = V_266 ;
if ( V_144 == 0 ) {
if ( V_89 -> V_270 & V_271 ) {
V_34 = - V_184 ;
break;
}
F_81 () ;
if ( F_110 ( V_267 ) ) {
V_34 = - V_272 ;
break;
}
if ( ! V_20 -> V_37 )
break;
if ( V_20 -> V_37 != V_89 ) {
V_34 = - V_133 ;
break;
}
continue;
}
V_266 = F_52 ( V_32 -> V_273 + V_32 -> V_134 ,
V_48 , V_144 ) ;
if ( V_266 ) {
V_144 -= V_266 ;
V_34 = - V_77 ;
}
F_70 ( V_32 , V_144 ) ;
V_52 += V_144 ;
V_264 -= V_144 ;
V_48 += V_144 ;
break;
}
F_109 ( V_274 ) ;
F_111 ( & V_32 -> V_220 , & V_258 ) ;
return V_52 ? V_52 : V_34 ;
}
static T_1 F_112 ( struct V_89 * V_89 , char T_3 * V_48 , T_2 V_264 ,
T_5 * V_265 )
{
struct V_19 * V_20 ;
struct V_31 * V_32 ;
int V_144 , V_266 , V_52 = 0 , V_34 = 0 ;
F_107 ( V_258 , V_267 ) ;
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
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
if ( V_20 -> V_37 != V_89 )
return - V_133 ;
F_108 ( & V_32 -> V_220 , & V_258 ) ;
while ( V_264 > 0 && ! V_34 ) {
F_109 ( V_268 ) ;
V_144 = V_264 ;
V_266 = F_103 ( V_32 ) ;
if ( V_32 -> V_135 + V_266 > V_32 -> V_44 )
V_266 = V_32 -> V_44 - V_32 -> V_135 ;
if ( V_266 < V_144 )
V_144 = V_266 ;
if ( V_144 == 0 ) {
if ( ! F_40 ( V_20 ) ) {
F_5 ( & V_2 -> V_4 ) ;
F_45 ( V_2 , V_20 ) ;
if ( F_41 ( V_20 ) )
V_34 = - V_269 ;
else
V_34 = 0 ;
F_8 ( & V_2 -> V_4 ) ;
break;
}
if ( V_89 -> V_270 & V_271 ) {
V_34 = - V_184 ;
break;
}
F_81 () ;
if ( F_110 ( V_267 ) ) {
V_34 = - V_272 ;
break;
}
if ( ! V_20 -> V_37 ) {
V_34 = 0 ;
break;
}
if ( V_20 -> V_37 != V_89 ) {
V_34 = - V_133 ;
break;
}
continue;
}
V_266 = F_56 ( V_48 , V_32 -> V_273 +
V_32 -> V_135 , V_144 ) ;
if ( V_266 ) {
V_144 -= V_266 ;
V_34 = - V_77 ;
}
F_67 ( V_32 , V_144 ) ;
F_68 ( V_32 , V_144 ) ;
V_52 += V_144 ;
V_264 -= V_144 ;
V_48 += V_144 ;
break;
}
if ( F_42 ( V_20 ) ) {
F_5 ( & V_2 -> V_4 ) ;
if ( V_32 -> V_137 - V_32 -> V_136 == 0 )
F_45 ( V_2 , V_20 ) ;
F_8 ( & V_2 -> V_4 ) ;
}
F_109 ( V_274 ) ;
F_111 ( & V_32 -> V_220 , & V_258 ) ;
return V_52 ? V_52 : V_34 ;
}
static int F_113 ( struct V_275 * V_275 , struct V_89 * V_89 )
{
const unsigned V_5 = F_58 ( V_275 ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 ) {
F_24 ( L_41 ) ;
return - V_51 ;
}
F_5 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_8 )
goto V_276;
if ( ! F_51 ( V_277 ) && V_2 -> V_278 ) {
F_24 ( L_42 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_51 ;
}
if ( F_51 ( V_277 ) && V_2 -> V_278 )
goto V_276;
V_2 -> V_278 = true ;
#ifdef F_114
F_8 ( & V_2 -> V_4 ) ;
F_115 ( L_43 , V_18 , V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_4 ) ;
#endif
V_2 -> V_278 = false ;
if ( ! V_2 -> V_8 && ! F_51 ( V_277 ) ) {
F_24 ( L_44 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_51 ;
}
V_276:
F_116 ( V_11 ) ;
if ( V_2 -> V_8 ) {
if ( ! F_117 ( V_2 -> V_9 -> V_6 ) ) {
F_7 ( V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_279 ;
}
}
if ( V_2 -> V_8 && V_2 -> V_10 == 0 && V_2 -> V_280 ) {
int V_222 = V_2 -> V_280 ( V_2 ) ;
if ( V_222 < 0 ) {
F_7 ( V_2 -> V_9 -> V_6 ) ;
F_7 ( V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return V_222 ;
}
}
V_2 -> V_10 ++ ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_118 ( int V_281 , struct V_89 * V_89 , int V_282 )
{
const unsigned V_5 = F_58 ( F_59 ( V_89 ) ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
if ( ! V_2 )
return - V_51 ;
return F_119 ( V_281 , V_89 , V_282 , & V_2 -> V_283 ) ;
}
static int F_120 ( struct V_275 * V_275 , struct V_89 * V_89 )
{
const unsigned V_5 = F_58 ( V_275 ) ;
struct V_1 * V_2 = F_20 ( V_5 ) ;
struct V_19 * V_20 = NULL ;
int V_12 ;
if ( ! V_2 )
return - V_51 ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_72 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_71 ; V_12 ++ ) {
V_20 = & V_2 -> V_72 [ V_12 ] ;
if ( V_20 -> V_37 == V_89 )
F_48 ( V_2 , V_20 ) ;
if ( V_20 -> V_112 == V_89 )
V_20 -> V_112 = NULL ;
}
}
if ( V_2 -> V_8 && V_2 -> V_10 == 1 && V_2 -> V_284 )
V_2 -> V_284 ( V_2 ) ;
F_7 ( V_11 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_9 -> V_6 ) ;
V_2 -> V_10 -- ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
void F_121 ( const struct V_1 * V_2 , const char * V_20 )
{
F_47 ( V_2 -> V_16 , L_45 , V_2 -> V_9 -> V_94 , V_20 ) ;
}
void F_122 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_31 * V_32 = V_20 -> V_32 ;
unsigned V_60 = 0 ;
unsigned V_285 = 0 ;
if ( ! F_40 ( V_20 ) )
return;
if ( V_20 ->
V_32 -> V_286 & ( V_213 | V_215 |
V_216 ) ) {
V_285 |= V_61 ;
}
if ( V_20 -> V_32 -> V_286 & ( V_215 | V_216 ) ) {
V_285 |= V_62 ;
V_60 |= V_62 ;
}
if ( V_285 ) {
F_36 ( V_20 , V_285 , V_60 ) ;
}
if ( V_32 -> V_212 & V_20 -> V_32 -> V_286 ) {
if ( F_39 ( V_20 ) & V_219 ) {
F_91 ( & V_32 -> V_220 ) ;
if ( V_20 -> V_26 & V_27 )
F_123 ( & V_2 -> V_283 , V_287 , V_288 ) ;
if ( V_20 -> V_26 & V_29 )
F_123 ( & V_2 -> V_283 , V_287 , V_289 ) ;
} else {
if ( V_32 -> V_290 )
V_32 -> V_290 ( V_20 -> V_32 -> V_286 , V_32 -> V_291 ) ;
}
}
V_20 -> V_32 -> V_286 = 0 ;
}
struct V_1 * F_124 ( struct V_25 * V_292 )
{
struct V_1 * V_2 ;
struct V_25 * V_45 ;
unsigned V_12 ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_2 == NULL )
return F_125 ( - V_100 ) ;
F_1 ( V_2 ) ;
F_126 ( V_2 , V_292 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_5 ( & V_14 ) ;
for ( V_12 = V_292 ? V_82 : 0 ;
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
F_127 ( L_46 ) ;
return F_125 ( - V_38 ) ;
}
V_2 -> V_5 = V_12 ;
V_45 = F_128 ( V_17 , V_292 ,
F_14 ( V_18 , V_12 ) , NULL , L_47 , V_12 ) ;
if ( ! F_85 ( V_45 ) )
V_2 -> V_16 = V_45 ;
return V_2 ;
}
static void F_129 ( unsigned V_5 )
{
F_17 ( V_5 >= V_21 ) ;
F_12 ( F_11 ( V_5 ) ) ;
}
void F_130 ( struct V_25 * V_292 )
{
int V_5 ;
struct V_1 * V_2 ;
for ( V_5 = V_82 ; V_5 < V_21 ;
V_5 ++ ) {
F_5 ( & V_14 ) ;
V_2 = V_15 [ V_5 ] ;
if ( V_2 && V_2 -> V_293 == V_292 ) {
V_15 [ V_5 ] = NULL ;
F_8 ( & V_14 ) ;
F_12 ( V_2 ) ;
break;
}
F_8 ( & V_14 ) ;
}
}
int F_131 ( struct V_19 * V_20 )
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
F_127 ( L_48 ) ;
return - V_38 ;
}
V_12 += V_21 ;
V_20 -> V_5 = V_12 ;
V_45 = F_128 ( V_17 , V_2 -> V_16 ,
F_14 ( V_18 , V_12 ) , NULL , L_49 ,
V_2 -> V_5 , V_20 -> V_43 ) ;
if ( ! F_85 ( V_45 ) )
V_20 -> V_16 = V_45 ;
return 0 ;
}
void F_132 ( struct V_19 * V_20 )
{
unsigned int V_12 ;
if ( V_20 == NULL )
return;
if ( V_20 -> V_5 < 0 )
return;
F_17 ( V_20 -> V_5 >= V_294 ) ;
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
static void F_133 ( void )
{
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ )
F_129 ( V_12 ) ;
}
static int T_6 F_134 ( void )
{
int V_12 ;
int V_34 ;
F_135 ( L_50 V_295 L_51 ) ;
if ( V_82 < 0 ||
V_82 > V_21 ) {
F_127 ( L_52 ,
V_21 ) ;
return - V_55 ;
}
V_34 = F_136 ( F_14 ( V_18 , 0 ) ,
V_294 , L_53 ) ;
if ( V_34 )
return - V_187 ;
F_137 ( & V_296 , & V_297 ) ;
V_296 . V_298 = V_11 ;
F_138 ( & V_296 . V_299 , L_53 ) ;
if ( F_139 ( & V_296 , F_14 ( V_18 , 0 ) , V_294 ) ) {
F_140 ( F_14 ( V_18 , 0 ) ,
V_294 ) ;
return - V_187 ;
}
V_17 = F_141 ( V_11 , L_53 ) ;
if ( F_85 ( V_17 ) ) {
F_127 ( L_54 ) ;
F_142 ( & V_296 ) ;
F_140 ( F_14 ( V_18 , 0 ) ,
V_294 ) ;
return F_86 ( V_17 ) ;
}
V_17 -> V_300 = V_301 ;
F_143 () ;
for ( V_12 = 0 ; V_12 < V_82 ; V_12 ++ ) {
struct V_1 * V_2 ;
V_2 = F_124 ( NULL ) ;
if ( F_85 ( V_2 ) ) {
F_133 () ;
F_142 ( & V_296 ) ;
F_140 ( F_14 ( V_18 , 0 ) ,
V_294 ) ;
return F_86 ( V_2 ) ;
} else {
F_8 ( & V_2 -> V_4 ) ;
}
}
return 0 ;
}
static void T_7 F_144 ( void )
{
int V_12 ;
F_133 () ;
for ( V_12 = 0 ; V_12 < V_21 ; ++ V_12 )
F_17 ( V_15 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < V_22 ; ++ V_12 )
F_17 ( V_24 [ V_12 ] ) ;
F_145 ( V_17 ) ;
F_142 ( & V_296 ) ;
F_140 ( F_14 ( V_18 , 0 ) , V_294 ) ;
F_146 () ;
}
