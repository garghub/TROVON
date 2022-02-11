static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_3 -> V_9 ;
struct V_1 * V_10 = NULL ;
V_7 = F_2 ( V_5 -> V_11 ) ;
if ( ! V_7 )
return F_3 ( - V_12 ) ;
V_10 = F_4 ( & V_9 -> V_13 , V_7 ,
V_5 -> V_14 , NULL ) ;
if ( ! V_10 ) {
F_5 ( & V_9 -> V_13 , L_1 ) ;
return NULL ;
}
F_6 ( & V_9 -> V_13 , L_2 ,
V_5 -> V_14 -> type ) ;
return V_10 ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = & V_3 -> V_9 ;
struct V_15 * V_16 ;
if ( V_9 -> V_17 < 0 )
return;
if ( V_9 -> V_10 ) {
F_8 ( V_9 -> V_10 ) ;
V_16 = F_9 ( V_9 -> V_10 ) ;
F_10 ( V_16 ) ;
F_11 ( V_16 -> V_18 ) ;
V_9 -> V_10 = NULL ;
}
V_9 -> V_17 = - 1 ;
}
static int F_12 ( struct V_2 * V_3 , int V_19 )
{
struct V_8 * V_9 = & V_3 -> V_9 ;
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_1 * V_10 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; ++ V_22 ) {
V_5 = & V_21 -> V_5 [ V_22 ] ;
if ( V_19 >= 0 && V_22 != V_19 )
continue;
V_10 = F_1 ( V_3 , V_5 ) ;
if ( ! F_13 ( V_10 ) ) {
V_9 -> V_10 = V_10 ;
V_9 -> V_17 = V_22 ;
return 0 ;
}
}
V_9 -> V_17 = - 1 ;
V_9 -> V_10 = NULL ;
F_5 ( & V_9 -> V_13 , L_3 ,
V_3 -> V_24 ) ;
return - V_25 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned int V_19 )
{
struct V_4 * V_5 ;
struct V_20 * V_21 = V_3 -> V_21 ;
int V_26 ;
if ( V_19 >= V_21 -> V_23 )
return - V_27 ;
V_5 = & V_21 -> V_5 [ V_19 ] ;
if ( V_5 -> V_28 )
F_15 ( V_3 -> clock [ V_29 ] , V_5 -> V_28 ) ;
V_26 = F_16 ( V_3 -> clock [ V_29 ] ) ;
if ( V_26 )
return V_26 ;
V_26 = F_12 ( V_3 , V_19 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_17 ( V_3 , V_5 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_18 ( V_3 -> V_9 . V_10 , V_30 , V_31 , 1 ) ;
if ( ! V_26 )
return V_26 ;
F_7 ( V_3 ) ;
F_5 ( & V_3 -> V_9 . V_13 , L_4 ,
V_26 ) ;
return V_26 ;
}
static int F_19 ( struct V_2 * V_3 )
{
unsigned long V_32 ;
struct V_8 * V_33 ;
struct V_34 * V_35 ;
V_33 = & V_3 -> V_9 ;
if ( ! F_20 ( V_3 ) )
return 0 ;
F_21 ( & V_3 -> V_36 , V_32 ) ;
F_22 ( V_37 , & V_3 -> V_38 ) ;
F_23 ( V_3 ) ;
F_24 ( & V_3 -> V_36 , V_32 ) ;
F_25 ( V_3 -> V_39 ,
! F_26 ( V_37 , & V_3 -> V_38 ) ,
V_40 ) ;
F_18 ( V_33 -> V_10 , V_41 , V_42 , 0 ) ;
F_21 ( & V_3 -> V_36 , V_32 ) ;
V_3 -> V_38 &= ~ ( 1 << V_43 | 1 << V_44 |
1 << V_37 | 1 << V_45 ) ;
V_3 -> V_9 . V_46 = 0 ;
while ( ! F_27 ( & V_33 -> V_47 ) ) {
V_35 = F_28 ( V_33 ) ;
F_29 ( & V_35 -> V_48 , V_49 ) ;
}
while ( ! F_27 ( & V_33 -> V_50 ) ) {
V_35 = F_30 ( V_33 ) ;
F_29 ( & V_35 -> V_48 , V_49 ) ;
}
F_24 ( & V_3 -> V_36 , V_32 ) ;
F_31 ( L_5 , V_3 -> V_38 ) ;
return 0 ;
}
static int F_32 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_2 * V_3 = V_54 -> V_2 ;
struct V_4 * V_5 ;
int V_26 ;
F_33 ( V_3 ) ;
V_26 = F_18 ( V_3 -> V_9 . V_10 , V_41 , V_42 , 1 ) ;
if ( V_26 && V_26 != - V_56 )
return V_26 ;
V_26 = F_34 ( V_54 , V_54 -> V_38 ) ;
if ( V_26 )
return V_26 ;
V_5 = & V_3 -> V_21 -> V_5 [ V_3 -> V_9 . V_17 ] ;
F_35 ( V_3 , V_5 ) ;
F_36 ( V_3 , V_5 ) ;
F_37 ( V_3 , & V_54 -> V_57 ) ;
if ( V_54 -> V_38 & V_58 ) {
V_26 = F_38 ( V_54 ) ;
if ( V_26 ) {
F_39 ( L_6 ) ;
return V_26 ;
}
F_40 ( V_54 ) ;
F_41 ( V_54 ) ;
F_42 ( V_54 ) ;
F_43 ( V_54 ) ;
F_44 ( V_54 ) ;
F_45 ( V_54 ) ;
}
F_46 ( V_54 ) ;
F_47 ( V_54 ) ;
F_48 ( & V_3 -> V_9 . V_47 ) ;
F_48 ( & V_3 -> V_9 . V_50 ) ;
V_3 -> V_9 . V_46 = 0 ;
V_3 -> V_9 . V_59 = 0 ;
V_3 -> V_9 . V_60 = 0 ;
F_22 ( V_44 , & V_3 -> V_38 ) ;
return 0 ;
}
static int F_49 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_2 * V_3 = V_54 -> V_2 ;
if ( ! F_20 ( V_3 ) )
return - V_27 ;
return F_19 ( V_3 ) ;
}
static unsigned int F_50 ( struct V_61 * V_62 , unsigned int V_63 )
{
if ( ! V_62 || V_63 >= V_62 -> V_64 -> V_65 )
return 0 ;
return V_62 -> V_66 * V_62 -> V_67 * V_62 -> V_64 -> V_68 [ V_63 ] / 8 ;
}
static int F_51 ( struct V_51 * V_69 , unsigned int * V_70 ,
unsigned int * V_71 , unsigned long V_72 [] ,
void * V_73 [] )
{
struct V_53 * V_54 = V_69 -> V_55 ;
struct V_74 * V_64 = V_54 -> V_75 . V_64 ;
int V_22 ;
if ( ! V_64 )
return - V_27 ;
* V_71 = V_64 -> V_65 ;
for ( V_22 = 0 ; V_22 < V_64 -> V_65 ; V_22 ++ ) {
V_72 [ V_22 ] = F_50 ( & V_54 -> V_75 , V_22 ) ;
V_73 [ V_22 ] = V_54 -> V_2 -> V_76 ;
}
return 0 ;
}
static int F_52 ( struct V_77 * V_48 )
{
struct V_51 * V_69 = V_48 -> V_51 ;
struct V_53 * V_54 = V_69 -> V_55 ;
struct V_78 * V_13 = & V_54 -> V_2 -> V_79 . V_13 ;
int V_22 ;
if ( ! V_54 -> V_75 . V_64 || V_69 -> type != V_80 )
return - V_27 ;
for ( V_22 = 0 ; V_22 < V_54 -> V_75 . V_64 -> V_65 ; V_22 ++ ) {
unsigned long V_81 = F_50 ( & V_54 -> V_75 , V_22 ) ;
if ( F_53 ( V_48 , V_22 ) < V_81 ) {
F_5 ( V_13 , L_7 ,
F_53 ( V_48 , V_22 ) , V_81 ) ;
return - V_27 ;
}
F_54 ( V_48 , V_22 , V_81 ) ;
}
return 0 ;
}
static void F_55 ( struct V_77 * V_48 )
{
struct V_53 * V_54 = F_56 ( V_48 -> V_51 ) ;
struct V_2 * V_3 = V_54 -> V_2 ;
struct V_34 * V_35
= F_57 ( V_48 , struct V_34 , V_48 ) ;
struct V_8 * V_9 = & V_3 -> V_9 ;
unsigned long V_32 ;
int V_82 ;
F_21 ( & V_3 -> V_36 , V_32 ) ;
F_58 ( V_54 , & V_35 -> V_48 , & V_54 -> V_75 , & V_35 -> V_83 ) ;
if ( ! F_26 ( V_45 , & V_3 -> V_38 )
&& V_9 -> V_46 < V_84 ) {
int V_85 = ( V_9 -> V_86 == 1 ) ? - 1 :
V_9 -> V_60 ;
F_59 ( V_3 , & V_35 -> V_83 , V_85 ) ;
V_35 -> V_19 = V_9 -> V_60 ;
F_60 ( V_9 , V_35 ) ;
if ( ++ V_9 -> V_60 >= V_84 )
V_9 -> V_60 = 0 ;
} else {
F_61 ( V_9 , V_35 ) ;
}
V_82 = V_9 -> V_86 > 1 ? 2 : 1 ;
if ( V_9 -> V_46 >= V_82 &&
! F_62 ( V_45 , & V_3 -> V_38 ) )
F_63 ( V_54 ) ;
F_24 ( & V_3 -> V_36 , V_32 ) ;
}
static void F_64 ( struct V_51 * V_69 )
{
struct V_53 * V_54 = F_56 ( V_69 ) ;
F_65 ( & V_54 -> V_2 -> V_87 ) ;
}
static void F_66 ( struct V_51 * V_69 )
{
struct V_53 * V_54 = F_56 ( V_69 ) ;
F_67 ( & V_54 -> V_2 -> V_87 ) ;
}
static int F_68 ( struct V_88 * V_88 )
{
struct V_2 * V_3 = F_69 ( V_88 ) ;
int V_26 = 0 ;
F_31 ( L_8 , F_70 ( V_89 ) , V_3 -> V_38 ) ;
if ( F_71 ( V_3 ) )
return - V_90 ;
if ( ++ V_3 -> V_9 . V_91 == 1 ) {
V_26 = F_14 ( V_3 , 0 ) ;
if ( V_26 ) {
V_3 -> V_9 . V_91 -- ;
return - V_92 ;
}
}
V_88 -> V_93 = V_3 -> V_9 . V_54 ;
return 0 ;
}
static int F_72 ( struct V_88 * V_88 )
{
struct V_2 * V_3 = F_69 ( V_88 ) ;
F_31 ( L_8 , F_70 ( V_89 ) , V_3 -> V_38 ) ;
if ( -- V_3 -> V_9 . V_91 == 0 ) {
F_19 ( V_3 ) ;
F_73 ( & V_3 -> V_9 . V_94 ) ;
F_5 ( & V_3 -> V_9 . V_13 , L_9 ) ;
F_18 ( V_3 -> V_9 . V_10 , V_30 , V_31 , 0 ) ;
F_74 ( V_3 -> clock [ V_29 ] ) ;
F_7 ( V_3 ) ;
}
return 0 ;
}
static unsigned int F_75 ( struct V_88 * V_88 ,
struct V_95 * V_96 )
{
struct V_53 * V_54 = V_88 -> V_93 ;
struct V_2 * V_3 = V_54 -> V_2 ;
return F_76 ( & V_3 -> V_9 . V_94 , V_88 , V_96 ) ;
}
static int F_77 ( struct V_88 * V_88 , struct V_97 * V_98 )
{
struct V_53 * V_54 = V_88 -> V_93 ;
struct V_2 * V_3 = V_54 -> V_2 ;
return F_78 ( & V_3 -> V_9 . V_94 , V_98 ) ;
}
static int F_79 ( struct V_88 * V_88 , void * V_99 ,
struct V_100 * V_33 )
{
struct V_53 * V_54 = V_88 -> V_93 ;
struct V_2 * V_3 = V_54 -> V_2 ;
strncpy ( V_33 -> V_101 , V_3 -> V_102 -> V_103 , sizeof( V_33 -> V_101 ) - 1 ) ;
strncpy ( V_33 -> V_104 , V_3 -> V_102 -> V_103 , sizeof( V_33 -> V_104 ) - 1 ) ;
V_33 -> V_105 [ 0 ] = 0 ;
V_33 -> V_106 = F_80 ( 1 , 0 , 0 ) ;
V_33 -> V_107 = V_108 | V_109 |
V_110 ;
return 0 ;
}
static int F_81 ( struct V_53 * V_54 )
{
struct V_61 * V_111 = & V_54 -> V_57 ;
struct V_2 * V_3 = V_54 -> V_2 ;
struct V_112 * V_64 = & V_3 -> V_9 . V_64 ;
int V_26 ;
V_64 -> V_113 = V_54 -> V_75 . V_114 ;
V_64 -> V_115 = V_54 -> V_75 . V_116 ;
V_26 = F_18 ( V_3 -> V_9 . V_10 , V_41 , V_117 , V_64 ) ;
if ( V_26 == - V_56 ) {
F_39 ( L_10 ) ;
return V_26 ;
}
F_31 ( L_11 , V_64 -> V_113 , V_64 -> V_115 , V_64 -> V_118 ) ;
V_111 -> V_64 = F_82 ( V_64 , V_119 ) ;
if ( ! V_111 -> V_64 ) {
F_39 ( L_12 ) ;
return - V_27 ;
}
V_111 -> V_66 = V_64 -> V_113 ;
V_111 -> V_67 = V_64 -> V_115 ;
V_111 -> V_113 = V_64 -> V_113 ;
V_111 -> V_115 = V_64 -> V_115 ;
V_111 -> V_114 = V_64 -> V_113 ;
V_111 -> V_116 = V_64 -> V_115 ;
V_111 -> V_120 = 0 ;
V_111 -> V_121 = 0 ;
return 0 ;
}
static int F_83 ( struct V_88 * V_88 , void * V_99 ,
struct V_122 * V_123 )
{
struct V_53 * V_54 = V_99 ;
struct V_2 * V_3 = V_54 -> V_2 ;
struct V_61 * V_111 ;
struct V_124 * V_125 ;
int V_26 ;
int V_22 ;
if ( V_123 -> type != V_80 )
return - V_27 ;
V_26 = F_84 ( V_88 , V_99 , V_123 ) ;
if ( V_26 )
return V_26 ;
if ( F_85 ( & V_3 -> V_9 . V_94 ) || F_20 ( V_3 ) )
return - V_90 ;
V_111 = & V_54 -> V_75 ;
V_125 = & V_123 -> V_64 . V_126 ;
V_111 -> V_64 = F_86 ( V_123 , V_127 | V_119 ) ;
if ( ! V_111 -> V_64 ) {
F_39 ( L_13 ) ;
return - V_27 ;
}
for ( V_22 = 0 ; V_22 < V_111 -> V_64 -> V_128 ; V_22 ++ ) {
V_111 -> V_129 [ V_22 ] =
( V_125 -> V_113 * V_125 -> V_115 * V_111 -> V_64 -> V_68 [ V_22 ] ) >> 3 ;
}
V_111 -> V_66 = V_125 -> V_130 [ 0 ] . V_131 * 8
/ V_111 -> V_64 -> V_68 [ 0 ] ;
V_111 -> V_67 = V_125 -> V_115 ;
V_111 -> V_113 = V_125 -> V_113 ;
V_111 -> V_115 = V_125 -> V_115 ;
V_111 -> V_114 = V_125 -> V_113 ;
V_111 -> V_116 = V_125 -> V_115 ;
V_111 -> V_120 = 0 ;
V_111 -> V_121 = 0 ;
V_54 -> V_38 |= ( V_58 | V_132 ) ;
V_26 = F_81 ( V_54 ) ;
return V_26 ;
}
static int F_87 ( struct V_88 * V_88 , void * V_99 ,
struct V_133 * V_22 )
{
struct V_53 * V_54 = V_99 ;
struct V_20 * V_134 = V_54 -> V_2 -> V_21 ;
struct V_4 * V_5 ;
if ( V_22 -> V_19 >= V_134 -> V_23 )
return - V_27 ;
V_5 = & V_134 -> V_5 [ V_22 -> V_19 ] ;
V_22 -> type = V_135 ;
strncpy ( V_22 -> V_103 , V_5 -> V_14 -> type , 32 ) ;
return 0 ;
}
static int F_88 ( struct V_88 * V_88 , void * V_99 ,
unsigned int V_22 )
{
struct V_53 * V_54 = V_99 ;
struct V_2 * V_3 = V_54 -> V_2 ;
struct V_20 * V_21 = V_3 -> V_21 ;
if ( F_20 ( V_54 -> V_2 ) )
return - V_90 ;
if ( V_22 >= V_21 -> V_23 )
return - V_27 ;
if ( V_3 -> V_9 . V_10 ) {
int V_26 = F_18 ( V_3 -> V_9 . V_10 , V_30 , V_31 , 0 ) ;
if ( V_26 )
F_39 ( L_14 , V_26 ) ;
F_74 ( V_3 -> clock [ V_29 ] ) ;
}
F_7 ( V_3 ) ;
return F_14 ( V_3 , V_22 ) ;
}
static int F_89 ( struct V_88 * V_88 , void * V_99 ,
unsigned int * V_22 )
{
struct V_53 * V_54 = V_99 ;
struct V_8 * V_33 = & V_54 -> V_2 -> V_9 ;
* V_22 = V_33 -> V_17 ;
return 0 ;
}
static int F_90 ( struct V_88 * V_88 , void * V_99 ,
enum V_136 type )
{
struct V_53 * V_54 = V_99 ;
struct V_2 * V_3 = V_54 -> V_2 ;
if ( F_20 ( V_3 ) || ! V_3 -> V_9 . V_10 )
return - V_90 ;
if ( ! ( V_54 -> V_38 & V_132 ) ) {
F_5 ( & V_3 -> V_9 . V_13 , L_15 ) ;
return - V_27 ;
}
return F_91 ( & V_3 -> V_9 . V_94 , type ) ;
}
static int F_92 ( struct V_88 * V_88 , void * V_99 ,
enum V_136 type )
{
struct V_53 * V_54 = V_99 ;
struct V_2 * V_3 = V_54 -> V_2 ;
return F_93 ( & V_3 -> V_9 . V_94 , type ) ;
}
static int F_94 ( struct V_88 * V_88 , void * V_99 ,
struct V_137 * V_138 )
{
struct V_53 * V_54 = V_99 ;
struct V_8 * V_33 = & V_54 -> V_2 -> V_9 ;
int V_26 ;
V_26 = F_95 ( & V_33 -> V_94 , V_138 ) ;
if ( ! V_26 )
V_33 -> V_86 = V_138 -> V_139 ;
return V_26 ;
}
static int F_96 ( struct V_88 * V_88 , void * V_99 ,
struct V_140 * V_35 )
{
struct V_53 * V_54 = V_99 ;
struct V_8 * V_33 = & V_54 -> V_2 -> V_9 ;
return F_97 ( & V_33 -> V_94 , V_35 ) ;
}
static int F_98 ( struct V_88 * V_88 , void * V_99 ,
struct V_140 * V_35 )
{
struct V_53 * V_54 = V_99 ;
struct V_8 * V_33 = & V_54 -> V_2 -> V_9 ;
return F_99 ( & V_33 -> V_94 , V_35 ) ;
}
static int F_100 ( struct V_88 * V_88 , void * V_99 ,
struct V_140 * V_35 )
{
struct V_53 * V_54 = V_99 ;
return F_101 ( & V_54 -> V_2 -> V_9 . V_94 , V_35 ,
V_88 -> V_141 & V_142 ) ;
}
static int F_102 ( struct V_88 * V_88 , void * V_99 ,
struct V_143 * V_144 )
{
struct V_53 * V_54 = V_99 ;
int V_26 = - V_27 ;
if ( ! F_20 ( V_54 -> V_2 ) ||
V_144 -> V_24 != V_145 ||
( V_144 -> V_146 != 90 && V_144 -> V_146 != 270 ) ) {
V_26 = F_103 ( V_54 , V_144 ) ;
if ( ! V_26 ) {
V_26 = F_104 ( V_54 , V_144 ) ;
if ( ! V_26 )
V_54 -> V_38 |= V_58 ;
}
}
if ( V_26 == - V_27 )
V_26 = F_18 ( V_54 -> V_2 -> V_9 . V_10 ,
V_30 , V_147 , V_144 ) ;
return V_26 ;
}
static int F_105 ( struct V_88 * V_88 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_61 * V_123 ;
struct V_53 * V_54 = V_148 ;
if ( V_150 -> type != V_80 )
return - V_27 ;
V_123 = & V_54 -> V_57 ;
V_150 -> V_151 . V_152 = 0 ;
V_150 -> V_151 . V_153 = 0 ;
V_150 -> V_151 . V_113 = V_123 -> V_114 ;
V_150 -> V_151 . V_115 = V_123 -> V_116 ;
V_150 -> V_154 = V_150 -> V_151 ;
return 0 ;
}
static int F_106 ( struct V_88 * V_88 , void * V_148 , struct V_155 * V_150 )
{
struct V_61 * V_123 ;
struct V_53 * V_54 = V_88 -> V_93 ;
V_123 = & V_54 -> V_57 ;
V_150 -> V_156 . V_152 = V_123 -> V_120 ;
V_150 -> V_156 . V_153 = V_123 -> V_121 ;
V_150 -> V_156 . V_113 = V_123 -> V_113 ;
V_150 -> V_156 . V_115 = V_123 -> V_115 ;
return 0 ;
}
static int F_107 ( struct V_88 * V_88 , void * V_148 ,
struct V_155 * V_150 )
{
struct V_61 * V_123 ;
struct V_53 * V_54 = V_88 -> V_93 ;
struct V_2 * V_3 = V_54 -> V_2 ;
int V_26 = - V_27 ;
if ( F_20 ( V_3 ) )
return - V_90 ;
V_26 = F_108 ( V_54 , V_150 ) ;
if ( V_26 )
return V_26 ;
if ( ! ( V_54 -> V_38 & V_132 ) ) {
F_5 ( & V_3 -> V_9 . V_13 ,
L_16 ) ;
return - V_27 ;
}
V_123 = & V_54 -> V_57 ;
V_26 = F_109 ( V_150 -> V_156 . V_113 , V_150 -> V_156 . V_115 ,
V_54 -> V_75 . V_113 , V_54 -> V_75 . V_115 ,
V_54 -> V_157 ) ;
if ( V_26 ) {
F_5 ( & V_3 -> V_9 . V_13 , L_17 ) ;
return V_26 ;
}
V_123 -> V_120 = V_150 -> V_156 . V_152 ;
V_123 -> V_121 = V_150 -> V_156 . V_153 ;
V_123 -> V_113 = V_150 -> V_156 . V_113 ;
V_123 -> V_115 = V_150 -> V_156 . V_115 ;
return 0 ;
}
int F_110 ( struct V_2 * V_3 )
{
struct V_78 * V_13 = & V_3 -> V_9 . V_13 ;
struct V_158 * V_159 ;
struct V_8 * V_9 ;
struct V_53 * V_54 ;
struct V_122 V_123 ;
struct V_61 * V_62 ;
struct V_51 * V_52 ;
int V_26 ;
V_54 = F_111 ( sizeof *V_54 , V_160 ) ;
if ( ! V_54 )
return - V_12 ;
V_54 -> V_2 = V_3 ;
V_54 -> V_161 = V_162 ;
V_54 -> V_163 = V_164 ;
V_54 -> V_38 = V_165 ;
V_123 . V_64 . V_125 . V_166 = V_167 ;
V_62 = & V_54 -> V_75 ;
V_62 -> V_64 = F_86 ( & V_123 , V_127 ) ;
V_62 -> V_113 = V_62 -> V_66 = V_62 -> V_114 = 640 ;
V_62 -> V_115 = V_62 -> V_67 = V_62 -> V_116 = 480 ;
if ( ! V_13 -> V_103 [ 0 ] )
snprintf ( V_13 -> V_103 , sizeof( V_13 -> V_103 ) ,
L_18 , F_112 ( & V_3 -> V_102 -> V_168 ) ) ;
V_26 = F_113 ( NULL , V_13 ) ;
if ( V_26 )
goto V_169;
V_159 = F_114 () ;
if ( ! V_159 ) {
F_5 ( V_13 , L_19 ) ;
goto V_170;
}
snprintf ( V_159 -> V_103 , sizeof( V_159 -> V_103 ) , L_20 ,
F_112 ( & V_3 -> V_102 -> V_168 ) ) ;
V_159 -> V_171 = & V_172 ;
V_159 -> V_173 = & V_174 ;
V_159 -> V_175 = - 1 ;
V_159 -> V_176 = V_177 ;
V_159 -> V_87 = & V_3 -> V_87 ;
F_115 ( V_159 , V_3 ) ;
V_9 = & V_3 -> V_9 ;
V_9 -> V_159 = V_159 ;
V_9 -> V_46 = 0 ;
V_9 -> V_86 = 0 ;
V_9 -> V_91 = 0 ;
V_9 -> V_64 . V_118 = V_178 ;
F_48 ( & V_9 -> V_47 ) ;
F_48 ( & V_9 -> V_50 ) ;
F_116 ( & V_54 -> V_36 ) ;
V_9 -> V_54 = V_54 ;
V_52 = & V_3 -> V_9 . V_94 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> type = V_80 ;
V_52 -> V_179 = V_180 | V_181 ;
V_52 -> V_55 = V_3 -> V_9 . V_54 ;
V_52 -> V_182 = & V_183 ;
V_52 -> V_184 = & V_185 ;
V_52 -> V_186 = sizeof( struct V_34 ) ;
F_117 ( V_52 ) ;
V_26 = F_118 ( V_159 , V_187 , - 1 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_21 ) ;
goto V_188;
}
F_6 ( V_13 ,
L_22 ,
V_159 -> V_189 ) ;
return 0 ;
V_188:
V_177 ( V_159 ) ;
V_170:
F_119 ( V_13 ) ;
V_169:
F_120 ( V_54 ) ;
F_121 ( & V_3 -> V_102 -> V_168 , L_23 ) ;
return V_26 ;
}
void F_122 ( struct V_2 * V_3 )
{
struct V_8 * V_190 = & V_3 -> V_9 ;
if ( V_190 -> V_159 )
F_123 ( V_190 -> V_159 ) ;
F_120 ( V_190 -> V_54 ) ;
}
