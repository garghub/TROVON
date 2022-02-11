static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
strncpy ( V_4 -> V_7 , L_1 , sizeof( V_4 -> V_7 ) - 1 ) ;
strncpy ( V_4 -> V_8 , L_1 , sizeof( V_4 -> V_8 ) - 1 ) ;
snprintf ( V_4 -> V_9 , sizeof( V_4 -> V_9 ) ,
L_2 , V_6 -> V_10 -> V_11 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , void * V_2 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
const struct V_14 * V_15 ;
struct V_16 V_17 = {
. V_18 = V_13 -> V_18 ,
. V_19 = V_6 -> V_20 ,
. V_21 = V_22 ,
} ;
int V_23 ;
V_15 = F_4 ( V_13 -> V_24 , V_25 , true ) ;
if ( ! V_15 )
return - V_26 ;
V_17 . V_27 = V_15 -> V_28 [ 0 ] ;
V_23 = F_5 ( V_6 -> V_10 , V_19 , V_29 , NULL , & V_17 ) ;
if ( V_23 )
return V_23 ;
if ( V_17 . V_30 == V_17 . V_31 &&
V_17 . V_32 == V_17 . V_33 ) {
V_13 -> type = V_34 ;
V_13 -> V_35 . V_36 = V_17 . V_30 ;
V_13 -> V_35 . V_37 = V_17 . V_32 ;
} else {
V_13 -> type = V_38 ;
V_13 -> V_39 . V_30 = V_17 . V_30 ;
V_13 -> V_39 . V_31 = V_17 . V_31 ;
V_13 -> V_39 . V_32 = V_17 . V_32 ;
V_13 -> V_39 . V_33 = V_17 . V_33 ;
V_13 -> V_39 . V_40 = 1 ;
V_13 -> V_39 . V_41 = 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , void * V_2 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
const struct V_14 * V_15 ;
struct V_44 V_45 = {
. V_18 = V_43 -> V_18 ,
. V_19 = V_6 -> V_20 ,
. V_36 = V_43 -> V_36 ,
. V_37 = V_43 -> V_37 ,
. V_21 = V_22 ,
} ;
int V_23 ;
V_15 = F_4 ( V_43 -> V_24 , V_25 , true ) ;
if ( ! V_15 )
return - V_26 ;
V_45 . V_27 = V_15 -> V_28 [ 0 ] ;
V_23 = F_5 ( V_6 -> V_10 , V_19 , V_46 , NULL , & V_45 ) ;
if ( V_23 )
return V_23 ;
V_43 -> type = V_47 ;
V_43 -> V_35 = V_45 . V_48 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 ,
struct V_49 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
const struct V_14 * V_51 ;
struct V_52 V_53 ;
T_1 V_54 ;
int V_23 ;
V_53 . V_19 = V_6 -> V_20 ;
V_53 . V_21 = V_22 ;
V_23 = F_5 ( V_6 -> V_10 , V_19 , V_55 , NULL , & V_53 ) ;
if ( V_23 ) {
F_8 ( V_6 -> V_10 , L_3 ) ;
return V_23 ;
}
V_51 = F_9 ( V_53 . V_56 . V_27 , V_25 ) ;
if ( ! V_51 )
V_51 = F_10 ( V_53 . V_56 . V_27 ,
V_25 , true ) ;
if ( ! V_51 )
return - V_26 ;
if ( V_51 -> V_57 ) {
if ( V_50 -> V_18 != 0 )
return - V_26 ;
V_54 = V_51 -> V_54 ;
} else {
T_1 V_58 = ( V_51 -> V_59 == V_60 ) ?
V_61 : V_62 ;
V_23 = F_11 ( & V_54 , V_50 -> V_18 , V_58 ) ;
if ( V_23 )
return V_23 ;
}
V_50 -> V_63 = V_54 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , void * V_2 ,
struct V_64 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
* V_50 = V_6 -> V_65 . V_66 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , void * V_2 ,
struct V_64 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_52 V_53 ;
const struct V_14 * V_15 , * V_51 ;
int V_23 ;
V_53 . V_19 = V_6 -> V_20 ;
V_53 . V_21 = V_22 ;
V_23 = F_5 ( V_6 -> V_10 , V_19 , V_55 , NULL , & V_53 ) ;
if ( V_23 )
return V_23 ;
V_51 = F_9 ( V_53 . V_56 . V_27 , V_25 ) ;
if ( ! V_51 )
V_51 = F_10 ( V_53 . V_56 . V_27 ,
V_25 , true ) ;
if ( ! V_51 )
return - V_26 ;
if ( V_51 -> V_57 ) {
V_15 = V_51 ;
} else {
T_1 V_54 , V_58 ;
V_58 = ( V_51 -> V_59 == V_60 ) ?
V_61 : V_62 ;
V_54 = V_50 -> V_66 . V_67 . V_63 ;
V_15 = F_4 ( V_54 , V_58 , false ) ;
if ( ! V_15 ) {
F_11 ( & V_54 , 0 , V_58 ) ;
V_15 = F_4 ( V_54 , V_58 , false ) ;
}
}
F_14 ( & V_50 -> V_66 . V_67 , & V_53 . V_56 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 ,
struct V_64 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_23 ;
if ( F_16 ( & V_6 -> V_68 ) ) {
F_8 ( V_6 -> V_10 , L_4 , V_69 ) ;
return - V_70 ;
}
V_23 = F_13 ( V_1 , V_6 , V_50 ) ;
if ( V_23 )
return V_23 ;
V_6 -> V_65 . V_66 . V_66 . V_67 = V_50 -> V_66 . V_67 ;
V_6 -> V_65 . V_15 = F_4 ( V_50 -> V_66 . V_67 . V_63 ,
V_25 , true ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , void * V_2 , T_2 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
return F_5 ( V_6 -> V_10 , V_72 , V_73 , V_71 ) ;
}
static int F_18 ( struct V_1 * V_1 , void * V_2 , T_2 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
return F_5 ( V_6 -> V_10 , V_72 , V_74 , V_71 ) ;
}
static int F_19 ( struct V_1 * V_1 , void * V_2 , T_2 V_71 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( F_16 ( & V_6 -> V_68 ) )
return - V_70 ;
return F_5 ( V_6 -> V_10 , V_72 , V_75 , V_71 ) ;
}
static int F_20 ( struct V_1 * V_1 , void * V_2 ,
struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_78 V_79 ;
int V_23 ;
if ( V_77 -> type != V_80 )
return - V_26 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_19 = V_6 -> V_20 ;
V_23 = F_5 ( V_6 -> V_10 , V_72 , V_81 , & V_79 ) ;
if ( V_23 < 0 )
return V_23 ;
V_77 -> V_82 . V_83 . V_84 = V_85 ;
V_77 -> V_82 . V_83 . V_86 = V_79 . V_48 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , void * V_2 ,
struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_78 V_79 ;
int V_23 ;
if ( V_77 -> type != V_80 )
return - V_26 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_19 = V_6 -> V_20 ;
V_79 . V_48 = V_77 -> V_82 . V_83 . V_86 ;
V_23 = F_5 ( V_6 -> V_10 , V_72 , V_87 , & V_79 ) ;
if ( V_23 < 0 )
return V_23 ;
V_77 -> V_82 . V_83 . V_84 = V_85 ;
V_77 -> V_82 . V_83 . V_86 = V_79 . V_48 ;
return 0 ;
}
static int F_22 ( struct V_88 * V_89 ,
unsigned int * V_90 ,
unsigned int * V_91 ,
unsigned int V_92 [] ,
struct V_93 * V_94 [] )
{
struct V_5 * V_6 = F_23 ( V_89 ) ;
struct V_95 * V_67 = & V_6 -> V_65 . V_66 . V_66 . V_67 ;
unsigned int V_96 = * V_90 ;
if ( V_89 -> type != V_80 )
return - V_26 ;
if ( * V_91 ) {
if ( * V_91 != 1 || V_92 [ 0 ] < V_67 -> V_97 )
return - V_26 ;
V_96 += V_89 -> V_98 ;
}
V_96 = F_24 ( V_99 , V_100 / V_67 -> V_97 , V_96 ) ;
if ( * V_91 )
* V_90 = ( V_96 < V_89 -> V_98 ) ? 0 :
V_96 - V_89 -> V_98 ;
else
* V_90 = V_96 ;
* V_91 = 1 ;
V_92 [ 0 ] = V_67 -> V_97 ;
return 0 ;
}
static int F_25 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = F_26 ( V_102 ) ;
F_27 ( & V_104 -> V_105 ) ;
return 0 ;
}
static int F_28 ( struct V_101 * V_102 )
{
struct V_88 * V_89 = V_102 -> V_88 ;
struct V_5 * V_6 = F_23 ( V_89 ) ;
struct V_95 * V_67 = & V_6 -> V_65 . V_66 . V_66 . V_67 ;
if ( F_29 ( V_102 , 0 ) < V_67 -> V_97 ) {
F_8 ( V_6 -> V_10 ,
L_5 ,
F_29 ( V_102 , 0 ) , ( long ) V_67 -> V_97 ) ;
return - V_26 ;
}
F_30 ( V_102 , 0 , V_67 -> V_97 ) ;
return 0 ;
}
static void F_31 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_23 ( V_102 -> V_88 ) ;
struct V_103 * V_104 = F_26 ( V_102 ) ;
unsigned long V_106 ;
F_32 ( & V_6 -> V_107 , V_106 ) ;
F_33 ( & V_104 -> V_105 , & V_6 -> V_108 ) ;
F_34 ( & V_6 -> V_107 , V_106 ) ;
}
static int F_35 ( struct V_88 * V_89 , unsigned int V_96 )
{
struct V_5 * V_6 = F_23 ( V_89 ) ;
struct V_103 * V_104 , * V_109 ;
unsigned long V_106 ;
int V_23 ;
if ( F_36 ( V_89 ) )
return 0 ;
V_23 = F_37 ( V_6 -> V_110 , & V_6 -> V_10 -> V_111 ,
true ) ;
if ( V_23 ) {
F_8 ( V_6 -> V_10 , L_6 , V_23 ) ;
goto V_112;
}
V_6 -> V_113 = false ;
return 0 ;
V_112:
F_32 ( & V_6 -> V_107 , V_106 ) ;
F_38 (buf, tmp, &priv->ready_q, list) {
F_39 ( & V_104 -> V_105 ) ;
F_40 ( & V_104 -> V_114 . V_115 , V_116 ) ;
}
F_34 ( & V_6 -> V_107 , V_106 ) ;
return V_23 ;
}
static void F_41 ( struct V_88 * V_89 )
{
struct V_5 * V_6 = F_23 ( V_89 ) ;
struct V_103 * V_117 ;
unsigned long V_106 ;
int V_23 ;
if ( ! F_36 ( V_89 ) )
return;
F_32 ( & V_6 -> V_107 , V_106 ) ;
V_6 -> V_113 = true ;
F_34 ( & V_6 -> V_107 , V_106 ) ;
V_23 = F_37 ( V_6 -> V_110 , & V_6 -> V_10 -> V_111 ,
false ) ;
if ( V_23 )
F_42 ( V_6 -> V_10 , L_7 , V_23 ) ;
F_32 ( & V_6 -> V_107 , V_106 ) ;
while ( ! F_43 ( & V_6 -> V_108 ) ) {
V_117 = F_44 ( V_6 -> V_108 . V_118 ,
struct V_103 , V_105 ) ;
F_39 ( & V_117 -> V_105 ) ;
F_40 ( & V_117 -> V_114 . V_115 , V_119 ) ;
}
F_34 ( & V_6 -> V_107 , V_106 ) ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_120 * V_121 = V_6 -> V_65 . V_121 ;
int V_23 ;
if ( F_46 ( & V_6 -> V_122 ) )
return - V_123 ;
V_23 = F_47 ( V_1 ) ;
if ( V_23 )
F_8 ( V_6 -> V_10 , L_8 ) ;
V_23 = F_48 ( & V_121 -> V_111 , 1 ) ;
if ( V_23 )
F_49 ( V_1 ) ;
F_50 ( & V_6 -> V_122 ) ;
return V_23 ;
}
static int F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_120 * V_121 = V_6 -> V_65 . V_121 ;
struct V_88 * V_89 = & V_6 -> V_68 ;
int V_23 = 0 ;
F_52 ( & V_6 -> V_122 ) ;
if ( V_1 -> V_124 == V_89 -> V_125 ) {
F_53 ( V_89 ) ;
V_89 -> V_125 = NULL ;
}
F_48 ( & V_121 -> V_111 , 0 ) ;
F_49 ( V_1 ) ;
F_50 ( & V_6 -> V_122 ) ;
return V_23 ;
}
void F_54 ( struct V_126 * V_65 ,
struct V_95 * V_67 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
F_52 ( & V_6 -> V_122 ) ;
V_6 -> V_65 . V_66 . V_66 . V_67 = * V_67 ;
V_6 -> V_65 . V_15 = F_4 ( V_67 -> V_63 , V_25 ,
true ) ;
F_50 ( & V_6 -> V_122 ) ;
}
struct V_103 *
F_56 ( struct V_126 * V_65 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
struct V_103 * V_104 = NULL ;
unsigned long V_106 ;
F_32 ( & V_6 -> V_107 , V_106 ) ;
if ( ! F_43 ( & V_6 -> V_108 ) ) {
V_104 = F_44 ( V_6 -> V_108 . V_118 , struct V_103 ,
V_105 ) ;
F_39 ( & V_104 -> V_105 ) ;
}
F_34 ( & V_6 -> V_107 , V_106 ) ;
return V_104 ;
}
void F_57 ( struct V_126 * V_65 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
struct V_88 * V_89 = & V_6 -> V_68 ;
unsigned long V_106 ;
if ( ! F_36 ( V_89 ) )
return;
F_32 ( & V_6 -> V_107 , V_106 ) ;
F_58 ( V_89 ) ;
F_34 ( & V_6 -> V_107 , V_106 ) ;
}
int F_59 ( struct V_126 * V_65 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
struct V_127 * V_128 = V_6 -> V_10 ;
struct V_120 * V_121 = V_65 -> V_121 ;
struct V_88 * V_89 = & V_6 -> V_68 ;
struct V_52 V_53 ;
int V_23 ;
V_6 -> V_110 = F_60 ( V_128 -> V_129 -> V_130 ) ;
V_121 -> V_129 = V_128 -> V_129 ;
V_23 = F_61 ( V_121 , V_131 , - 1 ) ;
if ( V_23 ) {
F_8 ( V_128 , L_9 ) ;
return V_23 ;
}
V_89 -> type = V_80 ;
V_89 -> V_132 = V_133 | V_134 ;
V_89 -> V_135 = V_6 ;
V_89 -> V_136 = sizeof( struct V_103 ) ;
V_89 -> V_137 = & V_138 ;
V_89 -> V_139 = & V_140 ;
V_89 -> V_141 = V_142 ;
V_89 -> V_143 = & V_6 -> V_122 ;
V_89 -> V_144 = 2 ;
V_89 -> V_130 = V_6 -> V_130 ;
V_23 = F_62 ( V_89 ) ;
if ( V_23 ) {
F_8 ( V_128 , L_10 ) ;
goto V_145;
}
F_27 ( & V_6 -> V_108 ) ;
V_6 -> V_146 . V_106 = V_147 ;
V_23 = F_63 ( & V_121 -> V_111 , 1 , & V_6 -> V_146 ) ;
if ( V_23 ) {
F_8 ( V_128 , L_11 ) ;
goto V_145;
}
V_23 = F_64 ( & V_128 -> V_111 , V_6 -> V_20 ,
& V_121 -> V_111 , 0 , 0 ) ;
if ( V_23 ) {
F_8 ( V_128 , L_12 ) ;
goto V_145;
}
V_53 . V_19 = V_6 -> V_20 ;
V_53 . V_21 = V_22 ;
F_5 ( V_128 , V_19 , V_55 , NULL , & V_53 ) ;
if ( V_23 ) {
F_8 ( V_128 , L_3 ) ;
goto V_145;
}
V_65 -> V_66 . type = V_80 ;
F_14 ( & V_65 -> V_66 . V_66 . V_67 ,
& V_53 . V_56 , NULL ) ;
V_65 -> V_15 = F_4 ( V_65 -> V_66 . V_66 . V_67 . V_63 ,
V_25 , false ) ;
F_65 ( V_128 , L_13 , V_121 -> V_11 ,
F_66 ( V_121 ) ) ;
V_121 -> V_148 = & V_6 -> V_149 ;
return 0 ;
V_145:
F_67 ( V_121 ) ;
return V_23 ;
}
void F_68 ( struct V_126 * V_65 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
struct V_120 * V_121 = V_6 -> V_65 . V_121 ;
F_52 ( & V_6 -> V_122 ) ;
if ( F_69 ( V_121 ) ) {
F_67 ( V_121 ) ;
F_70 ( & V_121 -> V_111 ) ;
}
F_50 ( & V_6 -> V_122 ) ;
}
struct V_126 *
F_71 ( struct V_127 * V_10 , int V_19 )
{
struct V_5 * V_6 ;
struct V_120 * V_121 ;
V_6 = F_72 ( V_10 -> V_130 , sizeof( * V_6 ) , V_150 ) ;
if ( ! V_6 )
return F_73 ( - V_151 ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_20 = V_19 ;
V_6 -> V_130 = V_10 -> V_130 ;
F_74 ( & V_6 -> V_122 ) ;
F_75 ( & V_6 -> V_107 ) ;
snprintf ( V_152 . V_11 , sizeof( V_152 . V_11 ) ,
L_14 , V_10 -> V_11 ) ;
V_121 = F_76 () ;
if ( ! V_121 )
return F_73 ( - V_151 ) ;
* V_121 = V_152 ;
V_121 -> V_143 = & V_6 -> V_122 ;
V_121 -> V_153 = & V_6 -> V_68 ;
V_6 -> V_65 . V_121 = V_121 ;
F_77 ( V_121 , V_6 ) ;
F_78 ( & V_6 -> V_149 , 0 ) ;
return & V_6 -> V_65 ;
}
void F_79 ( struct V_126 * V_65 )
{
struct V_5 * V_6 = F_55 ( V_65 ) ;
F_80 ( & V_6 -> V_149 ) ;
}
