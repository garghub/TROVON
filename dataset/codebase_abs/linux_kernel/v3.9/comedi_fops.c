static struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_3 ;
F_2 ( V_2 >= V_4 ) ;
F_3 ( & V_5 ) ;
V_3 = V_6 [ V_2 ] ;
F_4 ( & V_5 ) ;
return V_3 ;
}
static struct V_7 *
F_5 ( struct V_1 * V_3 )
{
return V_3 ? V_3 -> V_8 : NULL ;
}
struct V_7 * F_6 ( unsigned V_2 )
{
return F_5 ( F_1 ( V_2 ) ) ;
}
static struct V_9 *
F_7 ( const struct V_1 * V_3 )
{
if ( V_3 -> V_10 )
return V_3 -> V_10 ;
if ( V_3 -> V_8 )
return V_3 -> V_8 -> V_11 ;
return NULL ;
}
static struct V_9 *
F_8 ( const struct V_1 * V_3 )
{
if ( V_3 -> V_12 )
return V_3 -> V_12 ;
if ( V_3 -> V_8 )
return V_3 -> V_8 -> V_13 ;
return NULL ;
}
static int F_9 ( struct V_7 * V_14 ,
struct V_9 * V_15 ,
struct V_16 * V_17 , unsigned V_18 )
{
int V_19 ;
if ( V_18 > V_17 -> V_20 )
return - V_21 ;
if ( V_15 -> V_22 ) {
F_10 ( L_1 ) ;
return - V_23 ;
}
if ( V_17 -> V_24 ) {
F_10 ( L_2 ) ;
return - V_23 ;
}
if ( ! V_17 -> V_25 )
return - V_26 ;
V_18 = ( V_18 + V_27 - 1 ) & V_28 ;
V_19 = F_11 ( V_14 , V_15 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_15 -> V_29 ) {
V_19 = V_15 -> V_29 ( V_14 , V_15 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_10 ( L_3 ,
V_14 -> V_2 , V_15 -> V_30 , V_17 -> V_31 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_8 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_7 ( V_3 ) ;
unsigned int V_35 = 0 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_38 ) && V_15 -> V_17 )
V_35 = V_15 -> V_17 -> V_20 / 1024 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return snprintf ( V_34 , V_27 , L_4 , V_35 ) ;
}
static T_1 F_16 ( struct V_8 * V_14 ,
struct V_32 * V_33 ,
const char * V_34 , T_2 V_39 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_7 ( V_3 ) ;
unsigned int V_35 ;
int V_40 ;
V_40 = F_17 ( V_34 , 10 , & V_35 ) ;
if ( V_40 )
return V_40 ;
if ( V_35 > ( V_41 / 1024 ) )
return - V_26 ;
V_35 *= 1024 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_38 ) && V_15 -> V_17 )
V_15 -> V_17 -> V_20 = V_35 ;
else
V_40 = - V_26 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return V_40 ? V_40 : V_39 ;
}
static T_1 F_18 ( struct V_8 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_7 ( V_3 ) ;
unsigned int V_35 = 0 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_38 ) && V_15 -> V_17 )
V_35 = V_15 -> V_17 -> V_31 / 1024 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return snprintf ( V_34 , V_27 , L_4 , V_35 ) ;
}
static T_1 F_19 ( struct V_8 * V_14 ,
struct V_32 * V_33 ,
const char * V_34 , T_2 V_39 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_7 ( V_3 ) ;
unsigned int V_35 ;
int V_40 ;
V_40 = F_17 ( V_34 , 10 , & V_35 ) ;
if ( V_40 )
return V_40 ;
if ( V_35 > ( V_41 / 1024 ) )
return - V_26 ;
V_35 *= 1024 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_38 ) && V_15 -> V_17 )
V_40 = F_9 ( V_3 -> V_8 , V_15 , V_15 -> V_17 , V_35 ) ;
else
V_40 = - V_26 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return V_40 ? V_40 : V_39 ;
}
static T_1 F_20 ( struct V_8 * V_14 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_8 ( V_3 ) ;
unsigned int V_35 = 0 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_42 ) && V_15 -> V_17 )
V_35 = V_15 -> V_17 -> V_20 / 1024 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return snprintf ( V_34 , V_27 , L_4 , V_35 ) ;
}
static T_1 F_21 ( struct V_8 * V_14 ,
struct V_32 * V_33 ,
const char * V_34 , T_2 V_39 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_8 ( V_3 ) ;
unsigned int V_35 ;
int V_40 ;
V_40 = F_17 ( V_34 , 10 , & V_35 ) ;
if ( V_40 )
return V_40 ;
if ( V_35 > ( V_41 / 1024 ) )
return - V_26 ;
V_35 *= 1024 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_42 ) && V_15 -> V_17 )
V_15 -> V_17 -> V_20 = V_35 ;
else
V_40 = - V_26 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return V_40 ? V_40 : V_39 ;
}
static T_1 F_22 ( struct V_8 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_8 ( V_3 ) ;
unsigned int V_35 = 0 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_42 ) && V_15 -> V_17 )
V_35 = V_15 -> V_17 -> V_31 / 1024 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return snprintf ( V_34 , V_27 , L_4 , V_35 ) ;
}
static T_1 F_23 ( struct V_8 * V_14 ,
struct V_32 * V_33 ,
const char * V_34 , T_2 V_39 )
{
struct V_1 * V_3 = F_13 ( V_14 ) ;
struct V_9 * V_15 = F_8 ( V_3 ) ;
unsigned int V_35 ;
int V_40 ;
V_40 = F_17 ( V_34 , 10 , & V_35 ) ;
if ( V_40 )
return V_40 ;
if ( V_35 > ( V_41 / 1024 ) )
return - V_26 ;
V_35 *= 1024 ;
F_14 ( & V_3 -> V_8 -> V_36 ) ;
if ( V_15 && ( V_15 -> V_37 & V_42 ) && V_15 -> V_17 )
V_40 = F_9 ( V_3 -> V_8 , V_15 , V_15 -> V_17 , V_35 ) ;
else
V_40 = - V_26 ;
F_15 ( & V_3 -> V_8 -> V_36 ) ;
return V_40 ? V_40 : V_39 ;
}
static void F_24 ( struct V_9 * V_15 ,
unsigned V_43 , unsigned V_44 )
{
unsigned long V_45 ;
F_25 ( & V_15 -> F_3 , V_45 ) ;
V_15 -> V_46 &= ~ V_43 ;
V_15 -> V_46 |= ( V_44 & V_43 ) ;
F_26 ( & V_15 -> F_3 , V_45 ) ;
}
static unsigned F_27 ( struct V_9 * V_15 )
{
unsigned long V_45 ;
unsigned V_46 ;
F_25 ( & V_15 -> F_3 , V_45 ) ;
V_46 = V_15 -> V_46 ;
F_26 ( & V_15 -> F_3 , V_45 ) ;
return V_46 ;
}
bool F_28 ( struct V_9 * V_15 )
{
unsigned V_46 = F_27 ( V_15 ) ;
return ( V_46 & V_47 ) ? true : false ;
}
static bool F_29 ( struct V_9 * V_15 )
{
unsigned V_46 = F_27 ( V_15 ) ;
return ( V_46 & V_48 ) ? true : false ;
}
static bool F_30 ( struct V_9 * V_15 )
{
unsigned V_46 = F_27 ( V_15 ) ;
return ( V_46 & ( V_48 | V_47 ) ) ? false : true ;
}
static void F_31 ( struct V_7 * V_14 ,
struct V_9 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
F_24 ( V_15 , V_47 , 0 ) ;
if ( V_17 ) {
F_32 ( V_17 ) ;
V_17 -> V_49 = NULL ;
F_33 ( V_17 -> V_50 . V_51 ) ;
V_17 -> V_50 . V_51 = NULL ;
} else {
F_34 ( V_14 -> V_52 ,
L_5 ) ;
}
V_15 -> V_22 = NULL ;
}
static int F_35 ( struct V_7 * V_14 , struct V_9 * V_15 )
{
int V_53 = 0 ;
if ( F_28 ( V_15 ) && V_15 -> V_54 )
V_53 = V_15 -> V_54 ( V_14 , V_15 ) ;
F_31 ( V_14 , V_15 ) ;
return V_53 ;
}
static int F_36 ( struct V_7 * V_14 )
{
struct V_9 * V_15 ;
int V_55 ;
if ( ! V_14 -> V_56 )
return 0 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_57 ; V_55 ++ ) {
V_15 = & V_14 -> V_58 [ V_55 ] ;
if ( V_15 -> V_22 )
return 1 ;
if ( V_15 -> V_17 && V_15 -> V_17 -> V_24 )
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_14 ,
struct V_59 T_3 * V_60 )
{
struct V_59 V_61 ;
int V_53 ;
if ( ! F_38 ( V_62 ) )
return - V_21 ;
if ( V_60 == NULL ) {
if ( F_36 ( V_14 ) )
return - V_23 ;
if ( V_14 -> V_56 ) {
struct V_63 * V_64 = V_14 -> V_65 -> V_63 ;
F_39 ( V_14 ) ;
F_40 ( V_64 ) ;
}
return 0 ;
}
if ( F_41 ( & V_61 , V_60 , sizeof( V_61 ) ) )
return - V_66 ;
V_61 . V_67 [ V_68 - 1 ] = 0 ;
if ( V_61 . V_69 [ V_70 ] ) {
F_42 ( V_14 -> V_52 ,
L_6 ) ;
return - V_26 ;
}
V_53 = F_43 ( V_14 , & V_61 ) ;
if ( V_53 == 0 ) {
if ( ! F_44 ( V_14 -> V_65 -> V_63 ) ) {
F_39 ( V_14 ) ;
V_53 = - V_71 ;
}
}
return V_53 ;
}
static int F_45 ( struct V_7 * V_14 ,
struct V_72 T_3 * V_60 )
{
struct V_72 V_73 ;
struct V_16 * V_17 ;
struct V_9 * V_15 ;
int V_19 = 0 ;
if ( F_41 ( & V_73 , V_60 , sizeof( V_73 ) ) )
return - V_66 ;
if ( V_73 . V_74 >= V_14 -> V_57 || V_73 . V_74 < 0 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_73 . V_74 ] ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
F_10 ( L_7 ) ;
V_73 . V_35 = 0 ;
V_73 . V_75 = 0 ;
goto V_76;
}
if ( V_73 . V_75 ) {
if ( ! F_38 ( V_62 ) )
return - V_21 ;
V_17 -> V_20 = V_73 . V_75 ;
}
if ( V_73 . V_35 ) {
V_19 = F_9 ( V_14 , V_15 , V_17 , V_73 . V_35 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_73 . V_35 = V_17 -> V_31 ;
V_73 . V_75 = V_17 -> V_20 ;
V_76:
if ( F_46 ( V_60 , & V_73 , sizeof( V_73 ) ) )
return - V_66 ;
return 0 ;
}
static int F_47 ( struct V_7 * V_14 ,
struct V_77 T_3 * V_60 ,
struct V_78 * V_78 )
{
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_9 * V_15 ;
struct V_77 V_79 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_80 = V_81 ;
V_79 . V_82 = V_14 -> V_57 ;
F_50 ( V_79 . V_83 , V_14 -> V_65 -> V_83 , V_68 ) ;
F_50 ( V_79 . V_67 , V_14 -> V_67 , V_68 ) ;
V_15 = F_7 ( V_3 ) ;
if ( V_15 )
V_79 . V_10 = V_15 -> V_30 ;
else
V_79 . V_10 = - 1 ;
V_15 = F_8 ( V_3 ) ;
if ( V_15 )
V_79 . V_12 = V_15 -> V_30 ;
else
V_79 . V_12 = - 1 ;
if ( F_46 ( V_60 , & V_79 , sizeof( V_79 ) ) )
return - V_66 ;
return 0 ;
}
static int F_51 ( struct V_7 * V_14 ,
struct V_84 T_3 * V_60 , void * V_78 )
{
int V_53 , V_55 ;
struct V_84 * V_85 , * V_86 ;
struct V_9 * V_15 ;
V_85 = F_52 ( V_14 -> V_57 , sizeof( * V_85 ) , V_87 ) ;
if ( ! V_85 )
return - V_88 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_57 ; V_55 ++ ) {
V_15 = & V_14 -> V_58 [ V_55 ] ;
V_86 = V_85 + V_55 ;
V_86 -> type = V_15 -> type ;
V_86 -> V_89 = V_15 -> V_89 ;
V_86 -> V_90 = V_15 -> V_37 ;
if ( F_28 ( V_15 ) )
V_86 -> V_90 |= V_91 ;
#define F_53 5
V_86 -> V_92 = F_53 ;
V_86 -> V_93 = V_15 -> V_93 ;
V_86 -> V_94 = V_15 -> V_94 ;
if ( V_15 -> V_95 ) {
V_86 -> V_96 =
( V_55 << 24 ) | ( 0 << 16 ) | ( V_15 -> V_95 -> V_97 ) ;
} else {
V_86 -> V_96 = 0 ;
}
V_86 -> V_45 = V_15 -> V_45 ;
if ( V_15 -> V_22 )
V_86 -> V_90 |= V_98 ;
if ( V_15 -> V_22 == V_78 )
V_86 -> V_90 |= V_99 ;
if ( V_15 -> V_100 )
V_86 -> V_90 |= V_101 ;
if ( V_15 -> V_100 == V_78 )
V_86 -> V_90 |= V_102 ;
if ( ! V_15 -> V_94 && V_15 -> V_103 )
V_86 -> V_90 |= V_104 ;
if ( V_15 -> V_105 )
V_86 -> V_90 |= V_106 ;
if ( V_15 -> V_107 )
V_86 -> V_90 |= V_108 ;
if ( V_15 -> V_109 )
V_86 -> V_90 |= V_110 ;
if ( V_15 -> V_111 != & V_112 )
V_86 -> V_113 = V_114 ;
else
V_86 -> V_113 = V_115 ;
V_86 -> V_116 = V_15 -> V_116 ;
}
V_53 = F_46 ( V_60 , V_85 , V_14 -> V_57 * sizeof( * V_85 ) ) ;
F_33 ( V_85 ) ;
return V_53 ? - V_66 : 0 ;
}
static int F_54 ( struct V_7 * V_14 ,
struct V_117 T_3 * V_60 )
{
struct V_9 * V_15 ;
struct V_117 V_61 ;
if ( F_41 ( & V_61 , V_60 , sizeof( V_61 ) ) )
return - V_66 ;
if ( V_61 . V_118 >= V_14 -> V_57 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_61 . V_118 ] ;
if ( V_61 . V_103 ) {
if ( V_15 -> V_94 || ! V_15 -> V_103 )
return - V_26 ;
if ( F_46 ( V_61 . V_103 , V_15 -> V_103 ,
V_15 -> V_89 * sizeof( unsigned int ) ) )
return - V_66 ;
}
if ( V_61 . V_105 ) {
if ( ! V_15 -> V_105 )
return - V_26 ;
if ( F_46 ( V_61 . V_105 , V_15 -> V_105 ,
V_15 -> V_89 * sizeof( unsigned int ) ) )
return - V_66 ;
}
if ( V_61 . V_119 ) {
int V_55 ;
if ( ! V_15 -> V_107 )
return - V_26 ;
for ( V_55 = 0 ; V_55 < V_15 -> V_89 ; V_55 ++ ) {
int V_120 ;
V_120 = ( V_14 -> V_2 << 28 ) | ( V_61 . V_118 << 24 ) | ( V_55 << 16 ) |
( V_15 -> V_107 [ V_55 ] -> V_97 ) ;
if ( F_55 ( V_120 , V_61 . V_119 + V_55 ) )
return - V_66 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_56 ( struct V_7 * V_14 ,
struct V_121 T_3 * V_60 , void * V_78 )
{
struct V_121 V_122 ;
struct V_9 * V_15 ;
struct V_16 * V_17 ;
if ( F_41 ( & V_122 , V_60 , sizeof( V_122 ) ) )
return - V_66 ;
if ( V_122 . V_74 >= V_14 -> V_57 || V_122 . V_74 < 0 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_122 . V_74 ] ;
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 )
return - V_123 ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
F_10 ( L_7 ) ;
V_122 . V_124 = 0 ;
V_122 . V_125 = 0 ;
V_122 . V_126 = 0 ;
V_122 . V_127 = 0 ;
V_122 . V_128 = 0 ;
V_122 . V_129 = 0 ;
goto V_76;
}
if ( ! V_15 -> V_22 ) {
V_122 . V_128 = 0 ;
V_122 . V_129 = 0 ;
goto V_130;
}
if ( V_15 -> V_22 != V_78 )
return - V_123 ;
if ( V_122 . V_128 && ( V_15 -> V_37 & V_38 ) ) {
V_122 . V_128 = F_57 ( V_17 , V_122 . V_128 ) ;
F_58 ( V_17 , V_122 . V_128 ) ;
if ( F_30 ( V_15 ) &&
V_17 -> V_126 == V_17 -> V_127 ) {
F_31 ( V_14 , V_15 ) ;
}
}
if ( V_122 . V_129 && ( V_15 -> V_37 & V_42 ) ) {
V_122 . V_129 =
F_59 ( V_17 , V_122 . V_129 ) ;
F_60 ( V_17 , V_122 . V_129 ) ;
}
V_130:
V_122 . V_126 = V_17 -> V_126 ;
V_122 . V_124 = V_17 -> V_124 ;
V_122 . V_127 = V_17 -> V_127 ;
V_122 . V_125 = V_17 -> V_125 ;
V_76:
if ( F_46 ( V_60 , & V_122 , sizeof( V_122 ) ) )
return - V_66 ;
return 0 ;
}
static int F_61 ( struct V_131 * V_132 ,
unsigned int * V_133 )
{
if ( V_132 -> V_134 < 1 )
return - V_26 ;
switch ( V_133 [ 0 ] ) {
case V_135 :
case V_136 :
case V_137 :
case V_138 :
if ( V_132 -> V_134 == 1 )
return 0 ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
if ( V_132 -> V_134 == 2 )
return 0 ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
if ( V_132 -> V_134 == 3 )
return 0 ;
break;
case V_162 :
case V_163 :
if ( V_132 -> V_134 == 5 )
return 0 ;
break;
case V_164 :
if ( V_132 -> V_134 == 6 )
return 0 ;
break;
default:
F_62 ( L_8 ,
V_133 [ 0 ] ) ;
F_62 ( L_9 ,
V_165 , __FILE__ ) ;
F_62 ( L_10 , V_132 -> V_134 ) ;
return 0 ;
}
return - V_26 ;
}
static int F_63 ( struct V_7 * V_14 , struct V_131 * V_132 ,
unsigned int * V_133 , void * V_78 )
{
struct V_9 * V_15 ;
int V_53 = 0 ;
int V_55 ;
if ( V_132 -> V_132 & V_166 ) {
switch ( V_132 -> V_132 ) {
case V_167 :
{
struct V_168 V_169 ;
if ( V_132 -> V_134 != 2 ) {
V_53 = - V_26 ;
break;
}
F_64 ( & V_169 ) ;
V_133 [ 0 ] = V_169 . V_170 ;
V_133 [ 1 ] = V_169 . V_171 ;
V_53 = 2 ;
break;
}
case V_172 :
if ( V_132 -> V_134 != 1 || V_133 [ 0 ] >= 100000 ) {
V_53 = - V_26 ;
break;
}
F_65 ( V_133 [ 0 ] / 1000 ) ;
V_53 = 1 ;
break;
case V_173 :
if ( V_132 -> V_134 != 1 ) {
V_53 = - V_26 ;
break;
}
if ( V_132 -> V_118 >= V_14 -> V_57 ) {
F_10 ( L_11 ,
V_132 -> V_118 ) ;
V_53 = - V_26 ;
break;
}
V_15 = & V_14 -> V_58 [ V_132 -> V_118 ] ;
if ( ! V_15 -> V_17 ) {
F_10 ( L_12 ) ;
V_53 = - V_26 ;
break;
}
if ( ! V_15 -> V_17 -> V_49 ) {
F_10 ( L_13 ) ;
V_53 = - V_174 ;
break;
}
V_53 = V_15 -> V_17 -> V_49 ( V_14 , V_15 , V_133 [ 0 ] ) ;
if ( V_53 >= 0 )
V_53 = 1 ;
break;
default:
F_10 ( L_14 ) ;
V_53 = - V_26 ;
break;
}
} else {
unsigned int V_94 ;
if ( V_132 -> V_118 >= V_14 -> V_57 ) {
F_10 ( L_15 , V_132 -> V_118 ) ;
V_53 = - V_26 ;
goto V_175;
}
V_15 = & V_14 -> V_58 [ V_132 -> V_118 ] ;
if ( V_15 -> type == V_176 ) {
F_10 ( L_11 , V_132 -> V_118 ) ;
V_53 = - V_177 ;
goto V_175;
}
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 ) {
F_10 ( L_16 ) ;
V_53 = - V_123 ;
goto V_175;
}
V_53 = F_66 ( V_15 , 1 , & V_132 -> V_178 ) ;
if ( V_53 < 0 ) {
V_53 = - V_26 ;
F_10 ( L_17 ) ;
goto V_175;
}
if ( V_15 -> V_22 ) {
V_53 = - V_23 ;
goto V_175;
}
V_15 -> V_22 = & F_63 ;
switch ( V_132 -> V_132 ) {
case V_179 :
V_53 = V_15 -> V_180 ( V_14 , V_15 , V_132 , V_133 ) ;
break;
case V_181 :
V_94 = V_15 -> V_103
? V_15 -> V_103 [ F_67 ( V_132 -> V_178 ) ]
: V_15 -> V_94 ;
for ( V_55 = 0 ; V_55 < V_132 -> V_134 ; ++ V_55 ) {
if ( V_133 [ V_55 ] > V_94 ) {
V_53 = - V_26 ;
F_10 ( L_18 ) ;
break;
}
}
if ( V_53 == 0 )
V_53 = V_15 -> V_182 ( V_14 , V_15 , V_132 , V_133 ) ;
break;
case V_183 :
if ( V_132 -> V_134 != 2 ) {
V_53 = - V_26 ;
} else {
unsigned int V_184 ;
unsigned int V_185 ;
V_185 = V_133 [ 0 ] ;
if ( V_15 -> V_89 <= 32 ) {
V_184 = F_67 ( V_132 -> V_178 ) ;
if ( V_184 > 0 ) {
V_132 -> V_178 = 0 ;
V_133 [ 0 ] <<= V_184 ;
V_133 [ 1 ] <<= V_184 ;
}
} else
V_184 = 0 ;
V_53 = V_15 -> V_111 ( V_14 , V_15 , V_132 , V_133 ) ;
V_133 [ 0 ] = V_185 ;
if ( V_184 > 0 )
V_133 [ 1 ] >>= V_184 ;
}
break;
case V_186 :
V_53 = F_61 ( V_132 , V_133 ) ;
if ( V_53 )
break;
V_53 = V_15 -> V_187 ( V_14 , V_15 , V_132 , V_133 ) ;
break;
default:
V_53 = - V_26 ;
break;
}
V_15 -> V_22 = NULL ;
}
V_175:
return V_53 ;
}
static int F_68 ( struct V_7 * V_14 ,
struct V_188 T_3 * V_60 , void * V_78 )
{
struct V_188 V_189 ;
struct V_131 * V_190 = NULL ;
unsigned int * V_133 = NULL ;
int V_55 = 0 ;
int V_53 = 0 ;
if ( F_41 ( & V_189 , V_60 , sizeof( V_189 ) ) )
return - V_66 ;
V_133 = F_69 ( sizeof( unsigned int ) * V_191 , V_87 ) ;
if ( ! V_133 ) {
F_10 ( L_19 ) ;
V_53 = - V_88 ;
goto error;
}
V_190 = F_52 ( V_189 . V_192 , sizeof( * V_190 ) , V_87 ) ;
if ( ! V_190 ) {
F_10 ( L_19 ) ;
V_53 = - V_88 ;
goto error;
}
if ( F_41 ( V_190 , V_189 . V_190 ,
sizeof( * V_190 ) * V_189 . V_192 ) ) {
F_10 ( L_20 ) ;
V_53 = - V_66 ;
goto error;
}
for ( V_55 = 0 ; V_55 < V_189 . V_192 ; V_55 ++ ) {
if ( V_190 [ V_55 ] . V_134 > V_191 ) {
F_10 ( L_21 ) ;
V_53 = - V_26 ;
goto error;
}
if ( V_190 [ V_55 ] . V_132 & V_193 ) {
if ( F_41 ( V_133 , V_190 [ V_55 ] . V_133 ,
V_190 [ V_55 ] . V_134 * sizeof( unsigned int ) ) ) {
F_10 ( L_20 ) ;
V_53 = - V_66 ;
goto error;
}
}
V_53 = F_63 ( V_14 , V_190 + V_55 , V_133 , V_78 ) ;
if ( V_53 < 0 )
goto error;
if ( V_190 [ V_55 ] . V_132 & V_194 ) {
if ( F_46 ( V_190 [ V_55 ] . V_133 , V_133 ,
V_190 [ V_55 ] . V_134 * sizeof( unsigned int ) ) ) {
F_10 ( L_22 ) ;
V_53 = - V_66 ;
goto error;
}
}
if ( F_70 () )
F_71 () ;
}
error:
F_33 ( V_190 ) ;
F_33 ( V_133 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_55 ;
}
static int F_72 ( struct V_7 * V_14 ,
struct V_131 T_3 * V_60 , void * V_78 )
{
struct V_131 V_132 ;
unsigned int * V_133 = NULL ;
int V_53 = 0 ;
V_133 = F_69 ( sizeof( unsigned int ) * V_191 , V_87 ) ;
if ( ! V_133 ) {
V_53 = - V_88 ;
goto error;
}
if ( F_41 ( & V_132 , V_60 , sizeof( V_132 ) ) ) {
V_53 = - V_66 ;
goto error;
}
if ( V_132 . V_134 > V_191 )
V_132 . V_134 = V_191 ;
if ( V_132 . V_132 & V_193 ) {
if ( F_41 ( V_133 ,
V_132 . V_133 ,
V_132 . V_134 * sizeof( unsigned int ) ) ) {
V_53 = - V_66 ;
goto error;
}
}
V_53 = F_63 ( V_14 , & V_132 , V_133 , V_78 ) ;
if ( V_53 < 0 )
goto error;
if ( V_132 . V_132 & V_194 ) {
if ( F_46 ( V_132 . V_133 ,
V_133 ,
V_132 . V_134 * sizeof( unsigned int ) ) ) {
V_53 = - V_66 ;
goto error;
}
}
V_53 = V_132 . V_134 ;
error:
F_33 ( V_133 ) ;
return V_53 ;
}
static int F_73 ( struct V_7 * V_14 ,
struct V_195 T_3 * V_60 , void * V_78 )
{
struct V_195 V_50 ;
struct V_9 * V_15 ;
struct V_16 * V_17 ;
int V_53 = 0 ;
unsigned int T_3 * V_196 ;
if ( F_41 ( & V_50 , V_60 , sizeof( V_50 ) ) ) {
F_10 ( L_23 ) ;
return - V_66 ;
}
V_196 = ( unsigned int T_3 * ) V_50 . V_51 ;
if ( V_50 . V_118 >= V_14 -> V_57 ) {
F_10 ( L_24 , V_50 . V_118 ) ;
return - V_197 ;
}
V_15 = & V_14 -> V_58 [ V_50 . V_118 ] ;
V_17 = V_15 -> V_17 ;
if ( V_15 -> type == V_176 ) {
F_10 ( L_25 , V_50 . V_118 ) ;
return - V_177 ;
}
if ( ! V_15 -> V_109 || ! V_15 -> V_198 || ! V_15 -> V_17 ) {
F_10 ( L_26 ,
V_50 . V_118 ) ;
return - V_177 ;
}
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 ) {
F_10 ( L_27 ) ;
return - V_123 ;
}
if ( V_15 -> V_22 ) {
F_10 ( L_28 ) ;
return - V_23 ;
}
V_15 -> V_22 = V_78 ;
if ( V_50 . V_199 > V_15 -> V_93 ) {
F_10 ( L_29 ,
V_50 . V_199 , V_15 -> V_93 ) ;
V_53 = - V_26 ;
goto V_200;
}
if ( V_50 . V_199 < 1 ) {
F_10 ( L_30 ,
V_50 . V_199 ) ;
V_53 = - V_26 ;
goto V_200;
}
V_17 -> V_50 = V_50 ;
V_17 -> V_50 . V_133 = NULL ;
V_17 -> V_50 . V_51 =
F_69 ( V_17 -> V_50 . V_199 * sizeof( int ) , V_87 ) ;
if ( ! V_17 -> V_50 . V_51 ) {
F_10 ( L_31 ) ;
V_53 = - V_88 ;
goto V_200;
}
if ( F_41 ( V_17 -> V_50 . V_51 , V_196 ,
V_17 -> V_50 . V_199 * sizeof( int ) ) ) {
F_10 ( L_32 ) ;
V_53 = - V_66 ;
goto V_200;
}
V_53 = F_66 ( V_15 ,
V_17 -> V_50 . V_199 ,
V_17 -> V_50 . V_51 ) ;
if ( V_53 < 0 ) {
F_10 ( L_33 ) ;
goto V_200;
}
V_53 = V_15 -> V_198 ( V_14 , V_15 , & V_17 -> V_50 ) ;
if ( V_17 -> V_50 . V_45 & V_201 || V_53 ) {
F_10 ( L_34 , V_53 ) ;
V_50 = V_17 -> V_50 ;
V_50 . V_51 = ( unsigned int V_202 * ) V_196 ;
V_50 . V_133 = NULL ;
if ( F_46 ( V_60 , & V_50 , sizeof( V_50 ) ) ) {
F_10 ( L_35 ) ;
V_53 = - V_66 ;
goto V_200;
}
V_53 = - V_174 ;
goto V_200;
}
if ( ! V_17 -> V_31 ) {
V_53 = - V_88 ;
F_10 ( L_36 ) ;
goto V_200;
}
F_32 ( V_17 ) ;
V_17 -> V_203 =
V_204 | V_205 | V_206 |
V_207 ;
if ( V_17 -> V_50 . V_45 & V_208 )
V_17 -> V_203 |= V_209 ;
F_24 ( V_15 , ~ 0 , V_210 | V_47 ) ;
V_53 = V_15 -> V_109 ( V_14 , V_15 ) ;
if ( V_53 == 0 )
return 0 ;
V_200:
F_31 ( V_14 , V_15 ) ;
return V_53 ;
}
static int F_74 ( struct V_7 * V_14 ,
struct V_195 T_3 * V_60 , void * V_78 )
{
struct V_195 V_50 ;
struct V_9 * V_15 ;
int V_53 = 0 ;
unsigned int * V_51 = NULL ;
unsigned int T_3 * V_196 ;
if ( F_41 ( & V_50 , V_60 , sizeof( V_50 ) ) ) {
F_10 ( L_23 ) ;
return - V_66 ;
}
V_196 = ( unsigned int T_3 * ) V_50 . V_51 ;
if ( V_50 . V_118 >= V_14 -> V_57 ) {
F_10 ( L_24 , V_50 . V_118 ) ;
return - V_197 ;
}
V_15 = & V_14 -> V_58 [ V_50 . V_118 ] ;
if ( V_15 -> type == V_176 ) {
F_10 ( L_25 , V_50 . V_118 ) ;
return - V_177 ;
}
if ( ! V_15 -> V_109 || ! V_15 -> V_198 ) {
F_10 ( L_26 ,
V_50 . V_118 ) ;
return - V_177 ;
}
if ( V_50 . V_199 > V_15 -> V_93 ) {
F_10 ( L_37 ,
V_50 . V_199 , V_15 -> V_93 ) ;
V_53 = - V_26 ;
goto V_200;
}
if ( V_50 . V_51 ) {
V_51 =
F_69 ( V_50 . V_199 * sizeof( int ) , V_87 ) ;
if ( ! V_51 ) {
F_10 ( L_31 ) ;
V_53 = - V_88 ;
goto V_200;
}
if ( F_41 ( V_51 , V_196 ,
V_50 . V_199 * sizeof( int ) ) ) {
F_10 ( L_32 ) ;
V_53 = - V_66 ;
goto V_200;
}
V_53 = F_66 ( V_15 , V_50 . V_199 , V_51 ) ;
if ( V_53 < 0 ) {
F_10 ( L_33 ) ;
goto V_200;
}
V_50 . V_51 = V_51 ;
}
V_53 = V_15 -> V_198 ( V_14 , V_15 , & V_50 ) ;
V_50 . V_51 = ( unsigned int V_202 * ) V_196 ;
if ( F_46 ( V_60 , & V_50 , sizeof( V_50 ) ) ) {
F_10 ( L_23 ) ;
V_53 = - V_66 ;
goto V_200;
}
V_200:
F_33 ( V_51 ) ;
return V_53 ;
}
static int F_75 ( struct V_7 * V_14 , unsigned int V_60 ,
void * V_78 )
{
int V_53 = 0 ;
unsigned long V_45 ;
struct V_9 * V_15 ;
if ( V_60 >= V_14 -> V_57 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_60 ] ;
F_25 ( & V_15 -> F_3 , V_45 ) ;
if ( V_15 -> V_22 || V_15 -> V_100 )
V_53 = - V_23 ;
else
V_15 -> V_100 = V_78 ;
F_26 ( & V_15 -> F_3 , V_45 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_53 ;
}
static int F_76 ( struct V_7 * V_14 , unsigned int V_60 ,
void * V_78 )
{
struct V_9 * V_15 ;
if ( V_60 >= V_14 -> V_57 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_60 ] ;
if ( V_15 -> V_22 )
return - V_23 ;
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 )
return - V_123 ;
if ( V_15 -> V_100 == V_78 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_15 -> V_100 = NULL ;
}
return 0 ;
}
static int F_77 ( struct V_7 * V_14 , unsigned int V_60 ,
void * V_78 )
{
struct V_9 * V_15 ;
if ( V_60 >= V_14 -> V_57 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_60 ] ;
if ( V_15 -> V_17 == NULL )
return - V_26 ;
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 )
return - V_123 ;
if ( ! V_15 -> V_22 )
return 0 ;
if ( V_15 -> V_22 != V_78 )
return - V_23 ;
return F_35 ( V_14 , V_15 ) ;
}
static int F_78 ( struct V_7 * V_14 , unsigned int V_60 ,
void * V_78 )
{
struct V_9 * V_15 ;
if ( V_60 >= V_14 -> V_57 )
return - V_26 ;
V_15 = & V_14 -> V_58 [ V_60 ] ;
if ( V_15 -> V_100 && V_15 -> V_100 != V_78 )
return - V_123 ;
if ( ! V_15 -> V_22 )
return 0 ;
if ( V_15 -> V_22 != V_78 )
return - V_23 ;
if ( V_15 -> V_211 )
return V_15 -> V_211 ( V_14 , V_15 ) ;
return - V_26 ;
}
static long F_79 ( struct V_78 * V_78 , unsigned int V_50 ,
unsigned long V_60 )
{
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_7 * V_14 = F_5 ( V_3 ) ;
int V_212 ;
if ( ! V_14 )
return - V_197 ;
F_14 ( & V_14 -> V_36 ) ;
if ( V_50 == V_213 ) {
if ( V_2 >= V_214 ) {
V_212 = - V_215 ;
goto V_216;
}
V_212 = F_37 ( V_14 ,
(struct V_59 T_3 * ) V_60 ) ;
if ( V_212 == 0 )
V_3 -> V_217 = NULL ;
goto V_216;
}
if ( ! V_14 -> V_56 ) {
F_10 ( L_38 , V_14 -> V_2 ) ;
V_212 = - V_197 ;
goto V_216;
}
switch ( V_50 ) {
case V_218 :
V_212 = F_45 ( V_14 ,
(struct V_72 T_3 * ) V_60 ) ;
break;
case V_219 :
V_212 = F_47 ( V_14 , (struct V_77 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_220 :
V_212 = F_51 ( V_14 ,
(struct V_84 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_221 :
V_212 = F_54 ( V_14 , ( void T_3 * ) V_60 ) ;
break;
case V_222 :
V_212 = F_80 ( V_14 , ( void T_3 * ) V_60 ) ;
break;
case V_223 :
V_212 = F_56 ( V_14 ,
(struct V_121 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_224 :
V_212 = F_75 ( V_14 , V_60 , V_78 ) ;
break;
case V_225 :
V_212 = F_76 ( V_14 , V_60 , V_78 ) ;
break;
case V_226 :
V_212 = F_77 ( V_14 , V_60 , V_78 ) ;
break;
case V_227 :
V_212 = F_73 ( V_14 , (struct V_195 T_3 * ) V_60 , V_78 ) ;
break;
case V_228 :
V_212 = F_74 ( V_14 , (struct V_195 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_229 :
V_212 = F_68 ( V_14 ,
(struct V_188 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_230 :
V_212 = F_72 ( V_14 , (struct V_131 T_3 * ) V_60 ,
V_78 ) ;
break;
case V_231 :
V_212 = F_78 ( V_14 , V_60 , V_78 ) ;
break;
default:
V_212 = - V_215 ;
break;
}
V_216:
F_15 ( & V_14 -> V_36 ) ;
return V_212 ;
}
static void F_81 ( struct V_232 * V_233 )
{
struct V_16 * V_17 ;
struct V_7 * V_14 ;
V_17 = V_233 -> V_234 ;
V_14 = V_17 -> V_74 -> V_8 ;
F_14 ( & V_14 -> V_36 ) ;
V_17 -> V_24 ++ ;
F_15 ( & V_14 -> V_36 ) ;
}
static void F_82 ( struct V_232 * V_233 )
{
struct V_16 * V_17 ;
struct V_7 * V_14 ;
V_17 = V_233 -> V_234 ;
V_14 = V_17 -> V_74 -> V_8 ;
F_14 ( & V_14 -> V_36 ) ;
V_17 -> V_24 -- ;
F_15 ( & V_14 -> V_36 ) ;
}
static int F_83 ( struct V_78 * V_78 , struct V_232 * V_235 )
{
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_7 * V_14 = F_5 ( V_3 ) ;
struct V_9 * V_15 ;
struct V_16 * V_17 ;
unsigned long V_236 = V_235 -> V_237 ;
unsigned long V_35 ;
int V_238 ;
int V_55 ;
int V_19 ;
if ( ! V_14 )
return - V_197 ;
F_14 ( & V_14 -> V_36 ) ;
if ( ! V_14 -> V_56 ) {
F_10 ( L_39 , V_14 -> V_2 ) ;
V_19 = - V_197 ;
goto V_216;
}
if ( V_235 -> V_239 & V_240 )
V_15 = F_8 ( V_3 ) ;
else
V_15 = F_7 ( V_3 ) ;
if ( ! V_15 ) {
V_19 = - V_26 ;
goto V_216;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_19 = - V_26 ;
goto V_216;
}
if ( V_235 -> V_241 != 0 ) {
F_10 ( L_40 ) ;
V_19 = - V_26 ;
goto V_216;
}
V_35 = V_235 -> V_242 - V_235 -> V_237 ;
if ( V_35 > V_17 -> V_31 ) {
V_19 = - V_66 ;
goto V_216;
}
if ( V_35 & ( ~ V_28 ) ) {
V_19 = - V_66 ;
goto V_216;
}
V_238 = V_35 >> V_243 ;
for ( V_55 = 0 ; V_55 < V_238 ; ++ V_55 ) {
struct V_244 * V_34 = & V_17 -> V_245 [ V_55 ] ;
if ( F_84 ( V_235 , V_236 ,
F_85 ( F_86 ( V_34 -> V_246 ) ) ,
V_27 , V_247 ) ) {
V_19 = - V_174 ;
goto V_216;
}
V_236 += V_27 ;
}
V_235 -> V_248 = & V_249 ;
V_235 -> V_234 = V_17 ;
V_17 -> V_24 ++ ;
V_19 = 0 ;
V_216:
F_15 ( & V_14 -> V_36 ) ;
return V_19 ;
}
static unsigned int F_87 ( struct V_78 * V_78 , T_4 * V_250 )
{
unsigned int V_43 = 0 ;
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_7 * V_14 = F_5 ( V_3 ) ;
struct V_9 * V_15 ;
if ( ! V_14 )
return - V_197 ;
F_14 ( & V_14 -> V_36 ) ;
if ( ! V_14 -> V_56 ) {
F_10 ( L_39 , V_14 -> V_2 ) ;
goto V_216;
}
V_15 = F_7 ( V_3 ) ;
if ( V_15 && V_15 -> V_17 ) {
F_88 ( V_78 , & V_15 -> V_17 -> V_251 , V_250 ) ;
if ( ! V_15 -> V_22 || ! F_28 ( V_15 ) ||
F_89 ( V_15 -> V_17 ) > 0 )
V_43 |= V_252 | V_253 ;
}
V_15 = F_8 ( V_3 ) ;
if ( V_15 && V_15 -> V_17 ) {
unsigned int V_254 = F_90 ( V_15 -> V_17 -> V_74 ) ;
F_88 ( V_78 , & V_15 -> V_17 -> V_251 , V_250 ) ;
F_59 ( V_15 -> V_17 , V_15 -> V_17 -> V_31 ) ;
if ( ! V_15 -> V_22 || ! F_28 ( V_15 ) ||
F_91 ( V_15 -> V_17 ) >= V_254 )
V_43 |= V_255 | V_256 ;
}
V_216:
F_15 ( & V_14 -> V_36 ) ;
return V_43 ;
}
static T_1 F_92 ( struct V_78 * V_78 , const char T_3 * V_34 ,
T_2 V_257 , T_5 * V_258 )
{
struct V_9 * V_15 ;
struct V_16 * V_17 ;
int V_134 , V_259 , V_39 = 0 , V_19 = 0 ;
F_93 ( V_250 , V_260 ) ;
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_7 * V_14 = F_5 ( V_3 ) ;
if ( ! V_14 )
return - V_197 ;
if ( ! V_14 -> V_56 ) {
F_10 ( L_39 , V_14 -> V_2 ) ;
return - V_197 ;
}
V_15 = F_8 ( V_3 ) ;
if ( ! V_15 || ! V_15 -> V_17 )
return - V_177 ;
V_17 = V_15 -> V_17 ;
if ( ! V_15 -> V_22 || ! V_257 )
return 0 ;
if ( V_15 -> V_22 != V_78 )
return - V_123 ;
F_94 ( & V_17 -> V_251 , & V_250 ) ;
while ( V_257 > 0 && ! V_19 ) {
F_95 ( V_261 ) ;
if ( ! F_28 ( V_15 ) ) {
if ( V_39 == 0 ) {
if ( F_29 ( V_15 ) )
V_19 = - V_262 ;
else
V_19 = 0 ;
F_31 ( V_14 , V_15 ) ;
}
break;
}
V_134 = V_257 ;
V_259 = V_134 ;
if ( V_17 -> V_124 + V_259 > V_17 -> V_31 )
V_259 = V_17 -> V_31 - V_17 -> V_124 ;
F_59 ( V_17 , V_17 -> V_31 ) ;
if ( V_259 > F_91 ( V_17 ) )
V_259 = F_91 ( V_17 ) ;
if ( V_259 < V_134 )
V_134 = V_259 ;
if ( V_134 == 0 ) {
if ( V_78 -> V_263 & V_264 ) {
V_19 = - V_174 ;
break;
}
F_71 () ;
if ( F_96 ( V_260 ) ) {
V_19 = - V_265 ;
break;
}
if ( ! V_15 -> V_22 )
break;
if ( V_15 -> V_22 != V_78 ) {
V_19 = - V_123 ;
break;
}
continue;
}
V_259 = F_41 ( V_17 -> V_25 + V_17 -> V_124 ,
V_34 , V_134 ) ;
if ( V_259 ) {
V_134 -= V_259 ;
V_19 = - V_66 ;
}
F_60 ( V_17 , V_134 ) ;
V_39 += V_134 ;
V_257 -= V_134 ;
V_34 += V_134 ;
break;
}
F_95 ( V_266 ) ;
F_97 ( & V_17 -> V_251 , & V_250 ) ;
return V_39 ? V_39 : V_19 ;
}
static T_1 F_98 ( struct V_78 * V_78 , char T_3 * V_34 , T_2 V_257 ,
T_5 * V_258 )
{
struct V_9 * V_15 ;
struct V_16 * V_17 ;
int V_134 , V_259 , V_39 = 0 , V_19 = 0 ;
F_93 ( V_250 , V_260 ) ;
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_7 * V_14 = F_5 ( V_3 ) ;
if ( ! V_14 )
return - V_197 ;
if ( ! V_14 -> V_56 ) {
F_10 ( L_39 , V_14 -> V_2 ) ;
return - V_197 ;
}
V_15 = F_7 ( V_3 ) ;
if ( ! V_15 || ! V_15 -> V_17 )
return - V_177 ;
V_17 = V_15 -> V_17 ;
if ( ! V_15 -> V_22 || ! V_257 )
return 0 ;
if ( V_15 -> V_22 != V_78 )
return - V_123 ;
F_94 ( & V_17 -> V_251 , & V_250 ) ;
while ( V_257 > 0 && ! V_19 ) {
F_95 ( V_261 ) ;
V_134 = V_257 ;
V_259 = F_89 ( V_17 ) ;
if ( V_17 -> V_125 + V_259 > V_17 -> V_31 )
V_259 = V_17 -> V_31 - V_17 -> V_125 ;
if ( V_259 < V_134 )
V_134 = V_259 ;
if ( V_134 == 0 ) {
if ( ! F_28 ( V_15 ) ) {
F_31 ( V_14 , V_15 ) ;
if ( F_29 ( V_15 ) )
V_19 = - V_262 ;
else
V_19 = 0 ;
break;
}
if ( V_78 -> V_263 & V_264 ) {
V_19 = - V_174 ;
break;
}
F_71 () ;
if ( F_96 ( V_260 ) ) {
V_19 = - V_265 ;
break;
}
if ( ! V_15 -> V_22 ) {
V_19 = 0 ;
break;
}
if ( V_15 -> V_22 != V_78 ) {
V_19 = - V_123 ;
break;
}
continue;
}
V_259 = F_46 ( V_34 , V_17 -> V_25 +
V_17 -> V_125 , V_134 ) ;
if ( V_259 ) {
V_134 -= V_259 ;
V_19 = - V_66 ;
}
F_57 ( V_17 , V_134 ) ;
F_58 ( V_17 , V_134 ) ;
V_39 += V_134 ;
V_257 -= V_134 ;
V_34 += V_134 ;
break;
}
if ( F_30 ( V_15 ) &&
V_17 -> V_127 - V_17 -> V_126 == 0 ) {
F_31 ( V_14 , V_15 ) ;
}
F_95 ( V_266 ) ;
F_97 ( & V_17 -> V_251 , & V_250 ) ;
return V_39 ? V_39 : V_19 ;
}
static int F_99 ( struct V_267 * V_267 , struct V_78 * V_78 )
{
const unsigned V_2 = F_48 ( V_267 ) ;
struct V_7 * V_14 = F_6 ( V_2 ) ;
if ( ! V_14 ) {
F_10 ( L_41 ) ;
return - V_197 ;
}
F_14 ( & V_14 -> V_36 ) ;
if ( V_14 -> V_56 )
goto V_268;
if ( ! F_38 ( V_269 ) && V_14 -> V_270 ) {
F_10 ( L_42 ) ;
F_15 ( & V_14 -> V_36 ) ;
return - V_197 ;
}
if ( F_38 ( V_269 ) && V_14 -> V_270 )
goto V_268;
V_14 -> V_270 = 1 ;
#ifdef F_100
F_15 ( & V_14 -> V_36 ) ;
F_101 ( L_43 , V_271 , V_14 -> V_2 ) ;
F_14 ( & V_14 -> V_36 ) ;
#endif
V_14 -> V_270 = 0 ;
if ( ! V_14 -> V_56 && ! F_38 ( V_269 ) ) {
F_10 ( L_44 ) ;
F_15 ( & V_14 -> V_36 ) ;
return - V_197 ;
}
V_268:
F_102 ( V_272 ) ;
if ( V_14 -> V_56 ) {
if ( ! F_44 ( V_14 -> V_65 -> V_63 ) ) {
F_40 ( V_272 ) ;
F_15 ( & V_14 -> V_36 ) ;
return - V_71 ;
}
}
if ( V_14 -> V_56 && V_14 -> V_273 == 0 && V_14 -> V_274 ) {
int V_212 = V_14 -> V_274 ( V_14 ) ;
if ( V_212 < 0 ) {
F_40 ( V_14 -> V_65 -> V_63 ) ;
F_40 ( V_272 ) ;
F_15 ( & V_14 -> V_36 ) ;
return V_212 ;
}
}
V_14 -> V_273 ++ ;
F_15 ( & V_14 -> V_36 ) ;
return 0 ;
}
static int F_103 ( int V_275 , struct V_78 * V_78 , int V_276 )
{
const unsigned V_2 = F_48 ( F_49 ( V_78 ) ) ;
struct V_7 * V_14 = F_6 ( V_2 ) ;
if ( ! V_14 )
return - V_197 ;
return F_104 ( V_275 , V_78 , V_276 , & V_14 -> V_277 ) ;
}
static int F_105 ( struct V_267 * V_267 , struct V_78 * V_78 )
{
const unsigned V_2 = F_48 ( V_267 ) ;
struct V_7 * V_14 = F_6 ( V_2 ) ;
struct V_9 * V_15 = NULL ;
int V_55 ;
if ( ! V_14 )
return - V_197 ;
F_14 ( & V_14 -> V_36 ) ;
if ( V_14 -> V_58 ) {
for ( V_55 = 0 ; V_55 < V_14 -> V_57 ; V_55 ++ ) {
V_15 = & V_14 -> V_58 [ V_55 ] ;
if ( V_15 -> V_22 == V_78 )
F_35 ( V_14 , V_15 ) ;
if ( V_15 -> V_100 == V_78 )
V_15 -> V_100 = NULL ;
}
}
if ( V_14 -> V_56 && V_14 -> V_273 == 1 && V_14 -> V_278 )
V_14 -> V_278 ( V_14 ) ;
F_40 ( V_272 ) ;
if ( V_14 -> V_56 )
F_40 ( V_14 -> V_65 -> V_63 ) ;
V_14 -> V_273 -- ;
F_15 ( & V_14 -> V_36 ) ;
if ( V_78 -> V_263 & V_279 )
F_103 ( - 1 , V_78 , 0 ) ;
return 0 ;
}
void F_106 ( const struct V_7 * V_14 , const char * V_15 )
{
F_34 ( V_14 -> V_52 , L_45 , V_14 -> V_65 -> V_83 , V_15 ) ;
}
void F_107 ( struct V_7 * V_14 , struct V_9 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
unsigned V_46 = 0 ;
unsigned V_280 = 0 ;
if ( ! F_28 ( V_15 ) )
return;
if ( V_15 ->
V_17 -> V_281 & ( V_204 | V_206 |
V_207 ) ) {
V_280 |= V_47 ;
}
if ( V_15 -> V_17 -> V_281 & ( V_206 | V_207 ) ) {
V_280 |= V_48 ;
V_46 |= V_48 ;
}
if ( V_280 ) {
F_24 ( V_15 , V_280 , V_46 ) ;
}
if ( V_17 -> V_203 & V_15 -> V_17 -> V_281 ) {
if ( F_27 ( V_15 ) & V_210 ) {
F_108 ( & V_17 -> V_251 ) ;
if ( V_15 -> V_37 & V_38 )
F_109 ( & V_14 -> V_277 , V_282 , V_283 ) ;
if ( V_15 -> V_37 & V_42 )
F_109 ( & V_14 -> V_277 , V_282 , V_284 ) ;
} else {
if ( V_17 -> V_285 )
V_17 -> V_285 ( V_15 -> V_17 -> V_281 , V_17 -> V_286 ) ;
}
}
V_15 -> V_17 -> V_281 = 0 ;
}
static void F_110 ( struct V_7 * V_14 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_111 ( & V_14 -> V_287 ) ;
F_112 ( & V_14 -> V_36 ) ;
V_14 -> V_2 = - 1 ;
}
static void F_113 ( struct V_7 * V_14 )
{
if ( V_14 == NULL )
return;
F_14 ( & V_14 -> V_36 ) ;
F_39 ( V_14 ) ;
F_15 ( & V_14 -> V_36 ) ;
F_114 ( & V_14 -> V_36 ) ;
}
int F_115 ( struct V_8 * V_217 )
{
struct V_1 * V_3 ;
struct V_8 * V_288 ;
unsigned V_55 ;
V_3 = F_116 ( sizeof( * V_3 ) , V_87 ) ;
if ( V_3 == NULL )
return - V_88 ;
V_3 -> V_8 = F_116 ( sizeof( struct V_7 ) , V_87 ) ;
if ( V_3 -> V_8 == NULL ) {
F_33 ( V_3 ) ;
return - V_88 ;
}
V_3 -> V_217 = V_217 ;
F_110 ( V_3 -> V_8 ) ;
F_3 ( & V_5 ) ;
for ( V_55 = 0 ; V_55 < V_214 ; ++ V_55 ) {
if ( V_6 [ V_55 ] == NULL ) {
V_6 [ V_55 ] = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( V_55 == V_214 ) {
F_113 ( V_3 -> V_8 ) ;
F_33 ( V_3 -> V_8 ) ;
F_33 ( V_3 ) ;
F_117 ( L_46 ) ;
return - V_23 ;
}
V_3 -> V_8 -> V_2 = V_55 ;
V_288 = F_118 ( V_289 , V_217 ,
F_119 ( V_271 , V_55 ) , NULL , L_47 , V_55 ) ;
if ( ! F_120 ( V_288 ) )
V_3 -> V_8 -> V_52 = V_288 ;
F_121 ( V_288 , V_3 ) ;
return V_55 ;
}
void F_122 ( unsigned V_2 )
{
struct V_1 * V_3 ;
F_2 ( V_2 >= V_214 ) ;
F_3 ( & V_5 ) ;
V_3 = V_6 [ V_2 ] ;
V_6 [ V_2 ] = NULL ;
F_4 ( & V_5 ) ;
if ( V_3 ) {
struct V_7 * V_14 = V_3 -> V_8 ;
if ( V_14 ) {
if ( V_14 -> V_52 ) {
F_123 ( V_289 ,
F_119 ( V_271 , V_14 -> V_2 ) ) ;
}
F_113 ( V_14 ) ;
F_33 ( V_14 ) ;
}
F_33 ( V_3 ) ;
}
}
int F_124 ( struct V_8 * V_217 )
{
int V_2 ;
struct V_1 * V_3 ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ ) {
F_3 ( & V_5 ) ;
V_3 = V_6 [ V_2 ] ;
if ( V_3 && V_3 -> V_217 == V_217 ) {
F_4 ( & V_5 ) ;
return V_2 ;
}
F_4 ( & V_5 ) ;
}
return - V_197 ;
}
int F_125 ( struct V_9 * V_15 )
{
struct V_7 * V_14 = V_15 -> V_8 ;
struct V_1 * V_3 ;
struct V_8 * V_288 ;
unsigned V_55 ;
V_3 = F_116 ( sizeof( * V_3 ) , V_87 ) ;
if ( ! V_3 )
return - V_88 ;
V_3 -> V_8 = V_14 ;
if ( V_15 -> V_37 & V_38 )
V_3 -> V_10 = V_15 ;
if ( V_15 -> V_37 & V_42 )
V_3 -> V_12 = V_15 ;
F_3 ( & V_5 ) ;
for ( V_55 = V_290 ; V_55 < V_4 ; ++ V_55 ) {
if ( V_6 [ V_55 ] == NULL ) {
V_6 [ V_55 ] = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( V_55 == V_4 ) {
F_33 ( V_3 ) ;
F_117 ( L_48 ) ;
return - V_23 ;
}
V_15 -> V_2 = V_55 ;
V_288 = F_118 ( V_289 , V_14 -> V_52 ,
F_119 ( V_271 , V_55 ) , NULL , L_49 ,
V_14 -> V_2 , V_15 -> V_30 ) ;
if ( ! F_120 ( V_288 ) )
V_15 -> V_52 = V_288 ;
F_121 ( V_288 , V_3 ) ;
return 0 ;
}
void F_126 ( struct V_9 * V_15 )
{
struct V_1 * V_3 ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_2 < 0 )
return;
F_2 ( V_15 -> V_2 >= V_4 ) ;
F_2 ( V_15 -> V_2 < V_290 ) ;
F_3 ( & V_5 ) ;
V_3 = V_6 [ V_15 -> V_2 ] ;
V_6 [ V_15 -> V_2 ] = NULL ;
F_4 ( & V_5 ) ;
if ( V_15 -> V_52 ) {
F_123 ( V_289 , F_119 ( V_271 , V_15 -> V_2 ) ) ;
V_15 -> V_52 = NULL ;
}
F_33 ( V_3 ) ;
}
static void F_127 ( void )
{
unsigned V_55 ;
for ( V_55 = 0 ; V_55 < V_214 ; V_55 ++ )
F_122 ( V_55 ) ;
}
static int T_6 F_128 ( void )
{
int V_55 ;
int V_19 ;
F_129 ( L_50 V_291 L_51 ) ;
if ( V_292 < 0 ||
V_292 > V_214 ) {
F_117 ( L_52 ,
V_214 ) ;
return - V_26 ;
}
memset ( V_6 , 0 ,
sizeof( struct V_1 * ) * V_4 ) ;
V_19 = F_130 ( F_119 ( V_271 , 0 ) ,
V_4 , L_53 ) ;
if ( V_19 )
return - V_177 ;
F_131 ( & V_293 , & V_294 ) ;
V_293 . V_295 = V_272 ;
F_132 ( & V_293 . V_296 , L_53 ) ;
if ( F_133 ( & V_293 , F_119 ( V_271 , 0 ) , V_4 ) ) {
F_134 ( F_119 ( V_271 , 0 ) ,
V_4 ) ;
return - V_177 ;
}
V_289 = F_135 ( V_272 , L_53 ) ;
if ( F_120 ( V_289 ) ) {
F_117 ( L_54 ) ;
F_136 ( & V_293 ) ;
F_134 ( F_119 ( V_271 , 0 ) ,
V_4 ) ;
return F_137 ( V_289 ) ;
}
V_289 -> V_297 = V_298 ;
F_138 () ;
for ( V_55 = 0 ; V_55 < V_292 ; V_55 ++ ) {
int V_2 ;
V_2 = F_115 ( NULL ) ;
if ( V_2 < 0 ) {
F_127 () ;
F_136 ( & V_293 ) ;
F_134 ( F_119 ( V_271 , 0 ) ,
V_4 ) ;
return V_2 ;
}
}
return 0 ;
}
static void T_7 F_139 ( void )
{
int V_55 ;
F_127 () ;
for ( V_55 = 0 ; V_55 < V_4 ; ++ V_55 )
F_2 ( V_6 [ V_55 ] ) ;
F_140 ( V_289 ) ;
F_136 ( & V_293 ) ;
F_134 ( F_119 ( V_271 , 0 ) , V_4 ) ;
F_141 () ;
}
