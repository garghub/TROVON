static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( F_3 ( ! V_6 ) )
return - V_8 ;
F_4 ( & V_6 -> V_9 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_4 = V_4 ;
F_5 ( & V_10 ) ;
F_6 ( & V_6 -> V_9 , & V_11 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static inline
struct V_3 * F_8 ( struct V_1 * V_12 )
{
struct V_5 * V_13 ;
struct V_3 * V_4 = NULL ;
F_5 ( & V_10 ) ;
F_9 (curr, &iort_fwnode_list, list) {
if ( V_13 -> V_2 == V_12 ) {
V_4 = V_13 -> V_4 ;
break;
}
}
F_7 ( & V_10 ) ;
return V_4 ;
}
static inline void F_10 ( struct V_1 * V_12 )
{
struct V_5 * V_13 , * V_14 ;
F_5 ( & V_10 ) ;
F_11 (curr, tmp, &iort_fwnode_list, list) {
if ( V_13 -> V_2 == V_12 ) {
F_12 ( & V_13 -> V_9 ) ;
F_13 ( V_13 ) ;
break;
}
}
F_7 ( & V_10 ) ;
}
int F_14 ( int V_15 , struct V_3 * V_16 )
{
struct V_17 * V_18 ;
V_18 = F_2 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 )
return - V_8 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_20 = V_15 ;
F_5 ( & V_21 ) ;
F_15 ( & V_18 -> V_9 , & V_22 ) ;
F_7 ( & V_21 ) ;
return 0 ;
}
void F_16 ( int V_15 )
{
struct V_17 * V_18 , * V_23 ;
F_5 ( & V_21 ) ;
F_11 (its_msi_chip, t, &iort_msi_chip_list, list) {
if ( V_18 -> V_20 == V_15 ) {
F_12 ( & V_18 -> V_9 ) ;
F_13 ( V_18 ) ;
break;
}
}
F_7 ( & V_21 ) ;
}
struct V_3 * F_17 ( int V_15 )
{
struct V_3 * V_16 = NULL ;
struct V_17 * V_18 ;
F_5 ( & V_21 ) ;
F_9 (its_msi_chip, &iort_msi_chip_list, list) {
if ( V_18 -> V_20 == V_15 ) {
V_16 = V_18 -> V_16 ;
break;
}
}
F_7 ( & V_21 ) ;
return V_16 ;
}
static struct V_1 * F_18 ( enum V_24 type ,
T_1 V_25 ,
void * V_26 )
{
struct V_1 * V_2 , * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
if ( ! V_31 )
return NULL ;
V_29 = (struct V_28 * ) V_31 ;
V_2 = F_19 ( struct V_1 , V_29 ,
V_29 -> V_32 ) ;
V_27 = F_19 ( struct V_1 , V_31 ,
V_31 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_34 ; V_30 ++ ) {
if ( F_20 ( V_2 >= V_27 , V_35 ,
L_1 ) )
return NULL ;
if ( V_2 -> type == type &&
F_21 ( V_25 ( V_2 , V_26 ) ) )
return V_2 ;
V_2 = F_19 ( struct V_1 , V_2 ,
V_2 -> V_33 ) ;
}
return NULL ;
}
static T_2 F_22 ( struct V_1 * V_12 ,
void * V_26 )
{
struct V_36 * V_37 = V_26 ;
T_2 V_38 = V_39 ;
if ( V_12 -> type == V_40 ) {
struct V_41 V_42 = { V_43 , NULL } ;
struct V_44 * V_45 = F_23 ( V_37 -> V_4 ) ;
struct V_46 * V_47 ;
if ( ! V_45 )
goto V_48;
V_38 = F_24 ( V_45 -> V_49 , V_50 , & V_42 ) ;
if ( F_25 ( V_38 ) ) {
F_26 ( V_37 , L_2 ) ;
goto V_48;
}
V_47 = (struct V_46 * ) V_12 -> V_51 ;
V_38 = ! strcmp ( V_47 -> V_52 , V_42 . V_53 ) ?
V_54 : V_39 ;
F_27 ( V_42 . V_53 ) ;
} else if ( V_12 -> type == V_55 ) {
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_59 = F_28 ( V_37 ) ;
V_57 = (struct V_56 * ) V_12 -> V_51 ;
V_38 = V_57 -> V_60 == F_29 ( V_59 ) ?
V_54 : V_39 ;
}
V_48:
return V_38 ;
}
static int F_30 ( struct V_61 * V_62 , T_3 type , T_4 V_63 ,
T_4 * V_64 )
{
if ( V_62 -> V_65 & V_66 ) {
if ( type == V_40 ||
type == V_55 ) {
* V_64 = V_62 -> V_67 ;
return 0 ;
}
F_31 ( V_68 L_3 ,
V_62 , type ) ;
return - V_69 ;
}
if ( V_63 < V_62 -> V_70 ||
( V_63 >= V_62 -> V_70 + V_62 -> V_71 ) )
return - V_69 ;
* V_64 = V_62 -> V_67 + ( V_63 - V_62 -> V_70 ) ;
return 0 ;
}
static
struct V_1 * F_32 ( struct V_1 * V_12 ,
T_4 * V_72 , int V_73 )
{
struct V_1 * V_74 ;
struct V_61 * V_62 ;
if ( ! V_12 -> V_75 || ! V_12 -> V_76 ||
V_73 >= V_12 -> V_76 )
return NULL ;
V_62 = F_19 ( struct V_61 , V_12 ,
V_12 -> V_75 + V_73 * sizeof( * V_62 ) ) ;
if ( ! V_62 -> V_77 ) {
F_33 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
return NULL ;
}
V_74 = F_19 ( struct V_1 , V_31 ,
V_62 -> V_77 ) ;
if ( V_62 -> V_65 & V_66 ) {
if ( V_12 -> type == V_40 ||
V_12 -> type == V_55 ) {
* V_72 = V_62 -> V_67 ;
return V_74 ;
}
}
return NULL ;
}
static struct V_1 * F_34 ( struct V_1 * V_12 ,
T_4 V_78 , T_4 * V_72 ,
T_3 V_79 )
{
T_4 V_80 = V_78 ;
while ( V_12 ) {
struct V_61 * V_62 ;
int V_30 ;
if ( F_35 ( V_12 -> type ) & V_79 ) {
if ( V_72 )
* V_72 = V_80 ;
return V_12 ;
}
if ( ! V_12 -> V_75 || ! V_12 -> V_76 )
goto V_81;
V_62 = F_19 ( struct V_61 , V_12 ,
V_12 -> V_75 ) ;
if ( ! V_62 -> V_77 ) {
F_33 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
goto V_81;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ , V_62 ++ ) {
if ( ! F_30 ( V_62 , V_12 -> type , V_80 , & V_80 ) )
break;
}
if ( V_30 == V_12 -> V_76 )
goto V_81;
V_12 = F_19 ( struct V_1 , V_31 ,
V_62 -> V_77 ) ;
}
V_81:
if ( V_72 )
* V_72 = V_78 ;
return NULL ;
}
static
struct V_1 * F_36 ( struct V_1 * V_12 ,
T_4 * V_72 , T_3 V_79 ,
int V_73 )
{
struct V_1 * V_74 ;
T_4 V_80 ;
V_74 = F_32 ( V_12 , & V_80 , V_73 ) ;
if ( ! V_74 )
return NULL ;
if ( ! ( F_35 ( V_74 -> type ) & V_79 ) )
V_74 = F_34 ( V_74 , V_80 , V_72 , V_79 ) ;
else
if ( V_72 )
* V_72 = V_80 ;
return V_74 ;
}
static struct V_1 * F_37 ( struct V_36 * V_37 )
{
struct V_58 * V_82 ;
if ( ! F_38 ( V_37 ) )
return F_18 ( V_40 ,
F_22 , V_37 ) ;
V_82 = F_39 ( V_37 ) -> V_59 ;
while ( ! F_40 ( V_82 ) )
V_82 = V_82 -> V_74 ;
return F_18 ( V_55 ,
F_22 , & V_82 -> V_37 ) ;
}
T_4 F_41 ( struct V_36 * V_37 , T_4 V_83 )
{
struct V_1 * V_12 ;
T_4 V_84 ;
V_12 = F_37 ( V_37 ) ;
if ( ! V_12 )
return V_83 ;
F_34 ( V_12 , V_83 , & V_84 , V_85 ) ;
return V_84 ;
}
int F_42 ( struct V_36 * V_37 , T_4 * V_84 )
{
int V_30 ;
struct V_1 * V_12 ;
V_12 = F_37 ( V_37 ) ;
if ( ! V_12 )
return - V_86 ;
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ ) {
if ( F_36 ( V_12 , V_84 , V_85 , V_30 ) )
return 0 ;
}
return - V_86 ;
}
static int F_43 ( struct V_36 * V_37 , T_4 V_83 ,
unsigned int V_87 , int * V_88 )
{
struct V_89 * V_90 ;
struct V_1 * V_12 ;
V_12 = F_37 ( V_37 ) ;
if ( ! V_12 )
return - V_69 ;
V_12 = F_34 ( V_12 , V_83 , NULL , V_85 ) ;
if ( ! V_12 )
return - V_69 ;
V_90 = (struct V_89 * ) V_12 -> V_51 ;
if ( V_87 > V_90 -> V_91 ) {
F_44 ( V_37 , L_5 ,
V_87 , V_90 -> V_91 ) ;
return - V_69 ;
}
* V_88 = V_90 -> V_92 [ V_87 ] ;
return 0 ;
}
struct V_93 * F_45 ( struct V_36 * V_37 , T_4 V_83 )
{
struct V_3 * V_49 ;
int V_88 ;
if ( F_43 ( V_37 , V_83 , 0 , & V_88 ) )
return NULL ;
V_49 = F_17 ( V_88 ) ;
if ( ! V_49 )
return NULL ;
return F_46 ( V_49 , V_94 ) ;
}
static struct V_93 * F_47 ( struct V_36 * V_37 )
{
struct V_1 * V_12 , * V_95 ;
struct V_3 * V_5 ;
struct V_89 * V_90 ;
int V_30 ;
V_12 = F_18 ( V_40 ,
F_22 , V_37 ) ;
if ( ! V_12 )
return NULL ;
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ ) {
V_95 = F_36 ( V_12 , NULL ,
V_85 , V_30 ) ;
if ( V_95 )
break;
}
if ( ! V_95 )
return NULL ;
V_90 = (struct V_89 * ) V_95 -> V_51 ;
V_5 = F_17 ( V_90 -> V_92 [ 0 ] ) ;
if ( ! V_5 )
return NULL ;
return F_46 ( V_5 , V_96 ) ;
}
void F_48 ( struct V_36 * V_37 )
{
struct V_93 * V_97 ;
V_97 = F_47 ( V_37 ) ;
if ( V_97 )
F_49 ( V_37 , V_97 ) ;
}
static int T_5 F_50 ( struct V_98 * V_99 , T_6 V_100 ,
void * V_101 )
{
T_4 * V_102 = V_101 ;
* V_102 = V_100 ;
return 0 ;
}
static int F_51 ( struct V_36 * V_37 , T_4 V_103 ,
struct V_3 * V_4 ,
const struct V_104 * V_105 )
{
int V_106 = F_52 ( V_37 , V_4 , V_105 ) ;
if ( ! V_106 )
V_106 = F_53 ( V_37 , & V_103 , 1 ) ;
return V_106 ;
}
static inline bool F_54 ( T_3 type )
{
switch ( type ) {
case V_107 :
return F_55 ( V_108 ) ;
case V_109 :
return F_55 ( V_110 ) ;
default:
F_31 ( L_6 , type ) ;
return false ;
}
}
static inline
const struct V_104 * F_56 ( struct V_111 * V_112 )
{
return ( V_112 && V_112 -> V_105 ) ? V_112 -> V_105 : NULL ;
}
static inline
int F_57 ( const struct V_104 * V_105 , struct V_36 * V_37 )
{
int V_113 = 0 ;
if ( V_105 -> V_114 && V_37 -> V_59 && ! V_37 -> V_115 )
V_113 = V_105 -> V_114 ( V_37 ) ;
return V_113 ;
}
static inline
const struct V_104 * F_56 ( struct V_111 * V_112 )
{ return NULL ; }
static inline
int F_57 ( const struct V_104 * V_105 , struct V_36 * V_37 )
{ return 0 ; }
static int F_58 ( struct V_36 * V_37 , struct V_1 * V_12 ,
T_4 V_103 )
{
const struct V_104 * V_105 ;
struct V_3 * V_5 ;
if ( ! V_12 )
return - V_86 ;
V_5 = F_8 ( V_12 ) ;
if ( ! V_5 )
return - V_86 ;
V_105 = F_59 ( V_5 ) ;
if ( ! V_105 )
return F_54 ( V_12 -> type ) ?
- V_116 : - V_86 ;
return F_51 ( V_37 , V_103 , V_5 , V_105 ) ;
}
static int F_60 ( struct V_98 * V_99 , T_6 V_100 , void * V_101 )
{
struct V_117 * V_118 = V_101 ;
struct V_1 * V_74 ;
T_4 V_103 ;
V_74 = F_34 ( V_118 -> V_12 , V_100 , & V_103 ,
V_119 ) ;
return F_58 ( V_118 -> V_37 , V_74 , V_103 ) ;
}
static int F_61 ( struct V_36 * V_37 , T_7 * V_120 )
{
struct V_1 * V_12 ;
struct V_46 * V_47 ;
V_12 = F_18 ( V_40 ,
F_22 , V_37 ) ;
if ( ! V_12 )
return - V_86 ;
V_47 = (struct V_46 * ) V_12 -> V_51 ;
* V_120 = V_47 -> V_121 >= 64 ? V_122 :
1ULL << V_47 -> V_121 ;
return 0 ;
}
void F_62 ( struct V_36 * V_37 , T_7 * V_123 , T_7 * V_124 )
{
T_7 V_125 , V_126 = 0 , V_120 = 0 , V_127 = 0 ;
int V_106 , V_128 ;
if ( ! V_37 -> V_129 )
V_37 -> V_129 = F_63 ( 32 ) ;
if ( ! V_37 -> V_130 )
V_37 -> V_130 = & V_37 -> V_129 ;
V_120 = F_64 ( V_37 -> V_129 , V_37 -> V_129 + 1 ) ;
if ( F_38 ( V_37 ) )
V_106 = F_65 ( V_37 , & V_126 , & V_127 , & V_120 ) ;
else
V_106 = F_61 ( V_37 , & V_120 ) ;
if ( ! V_106 ) {
V_128 = F_66 ( V_126 + V_120 - 1 ) ;
V_125 = V_128 == 64 ? V_122 : ( 1ULL << V_128 ) - 1 ;
V_37 -> V_129 = V_125 ;
* V_37 -> V_130 = V_125 ;
}
* V_123 = V_126 ;
* V_124 = V_120 ;
V_37 -> V_131 = F_67 ( V_127 ) ;
F_68 ( V_37 , L_7 , V_127 ) ;
}
const struct V_104 * F_69 ( struct V_36 * V_37 )
{
struct V_1 * V_12 , * V_74 ;
const struct V_104 * V_105 ;
T_4 V_103 = 0 ;
int V_113 = - V_86 ;
V_105 = F_56 ( V_37 -> V_111 ) ;
if ( V_105 )
return V_105 ;
if ( F_38 ( V_37 ) ) {
struct V_58 * V_59 = F_39 ( V_37 ) -> V_59 ;
struct V_117 V_118 = { . V_37 = V_37 } ;
V_12 = F_18 ( V_55 ,
F_22 , & V_59 -> V_37 ) ;
if ( ! V_12 )
return NULL ;
V_118 . V_12 = V_12 ;
V_113 = F_70 ( F_39 ( V_37 ) ,
F_60 , & V_118 ) ;
} else {
int V_30 = 0 ;
V_12 = F_18 ( V_40 ,
F_22 , V_37 ) ;
if ( ! V_12 )
return NULL ;
do {
V_74 = F_36 ( V_12 , & V_103 ,
V_119 ,
V_30 ++ ) ;
if ( V_74 )
V_113 = F_58 ( V_37 , V_74 , V_103 ) ;
} while ( V_74 && ! V_113 );
}
if ( ! V_113 ) {
V_105 = F_56 ( V_37 -> V_111 ) ;
V_113 = F_57 ( V_105 , V_37 ) ;
}
if ( V_113 == - V_116 ) {
V_105 = F_71 ( V_113 ) ;
} else if ( V_113 ) {
F_68 ( V_37 , L_8 , V_113 ) ;
V_105 = NULL ;
}
return V_105 ;
}
static void T_8 F_72 ( int V_132 , const char * V_133 ,
int V_134 ,
struct V_135 * V_136 )
{
int V_137 = F_73 ( NULL , V_132 , V_134 ,
V_138 ) ;
if ( V_137 <= 0 ) {
F_33 ( L_9 , V_132 ,
V_133 ) ;
return;
}
V_136 -> V_139 = V_137 ;
V_136 -> V_140 = V_137 ;
V_136 -> V_65 = V_141 ;
V_136 -> V_133 = V_133 ;
}
static int T_8 F_74 ( struct V_1 * V_12 )
{
struct V_142 * V_143 ;
int V_144 = 1 ;
V_143 = (struct V_142 * ) V_12 -> V_51 ;
if ( V_143 -> V_145 )
V_144 ++ ;
if ( V_143 -> V_146 )
V_144 ++ ;
if ( V_143 -> V_147 )
V_144 ++ ;
if ( V_143 -> V_148 )
V_144 ++ ;
return V_144 ;
}
static bool F_75 ( struct V_142 * V_143 )
{
if ( V_143 -> V_149 != V_150 )
return false ;
return V_143 -> V_145 == V_143 -> V_146 &&
V_143 -> V_145 == V_143 -> V_147 &&
V_143 -> V_145 == V_143 -> V_148 ;
}
static unsigned long F_76 ( struct V_142 * V_143 )
{
if ( V_143 -> V_149 == V_150 )
return V_151 ;
return V_152 ;
}
static void T_8 F_77 ( struct V_135 * V_136 ,
struct V_1 * V_12 )
{
struct V_142 * V_143 ;
int V_144 = 0 ;
V_143 = (struct V_142 * ) V_12 -> V_51 ;
V_136 [ V_144 ] . V_139 = V_143 -> V_153 ;
V_136 [ V_144 ] . V_140 = V_143 -> V_153 +
F_76 ( V_143 ) - 1 ;
V_136 [ V_144 ] . V_65 = V_154 ;
V_144 ++ ;
if ( F_75 ( V_143 ) ) {
if ( V_143 -> V_145 )
F_72 ( V_143 -> V_145 , L_10 ,
V_155 ,
& V_136 [ V_144 ++ ] ) ;
} else {
if ( V_143 -> V_145 )
F_72 ( V_143 -> V_145 , L_11 ,
V_155 ,
& V_136 [ V_144 ++ ] ) ;
if ( V_143 -> V_146 )
F_72 ( V_143 -> V_146 , L_12 ,
V_155 ,
& V_136 [ V_144 ++ ] ) ;
if ( V_143 -> V_147 )
F_72 ( V_143 -> V_147 , L_13 ,
V_155 ,
& V_136 [ V_144 ++ ] ) ;
if ( V_143 -> V_148 )
F_72 ( V_143 -> V_148 , L_14 ,
V_155 ,
& V_136 [ V_144 ++ ] ) ;
}
}
static bool T_8 F_78 ( struct V_1 * V_12 )
{
struct V_142 * V_143 ;
V_143 = (struct V_142 * ) V_12 -> V_51 ;
return V_143 -> V_65 & V_156 ;
}
static void T_8 F_79 ( struct V_36 * V_37 ,
struct V_1 * V_12 )
{
struct V_142 * V_143 ;
V_143 = (struct V_142 * ) V_12 -> V_51 ;
if ( V_143 -> V_65 & V_157 ) {
F_80 ( V_37 , F_81 ( V_143 -> V_158 ) ) ;
F_82 ( L_15 ,
V_143 -> V_153 ,
V_143 -> V_158 ) ;
}
}
static int T_8 F_83 ( struct V_1 * V_12 )
{
struct V_159 * V_143 ;
V_143 = (struct V_159 * ) V_12 -> V_51 ;
return V_143 -> V_160 + 2 ;
}
static void T_8 F_84 ( struct V_135 * V_136 ,
struct V_1 * V_12 )
{
struct V_159 * V_143 ;
int V_30 , V_161 , V_134 , V_144 = 0 ;
T_7 * V_162 , * V_163 ;
V_143 = (struct V_159 * ) V_12 -> V_51 ;
V_136 [ V_144 ] . V_139 = V_143 -> V_153 ;
V_136 [ V_144 ] . V_140 = V_143 -> V_153 + V_143 -> V_164 - 1 ;
V_136 [ V_144 ] . V_65 = V_154 ;
V_144 ++ ;
V_163 = F_19 ( T_7 , V_12 , V_143 -> V_165 ) ;
V_161 = F_85 ( V_163 [ 0 ] ) ;
V_134 = F_86 ( V_163 [ 0 ] ) ;
F_72 ( V_161 , L_16 , V_134 ,
& V_136 [ V_144 ++ ] ) ;
V_162 = F_19 ( T_7 , V_12 , V_143 -> V_166 ) ;
for ( V_30 = 0 ; V_30 < V_143 -> V_160 ; V_30 ++ ) {
V_161 = F_85 ( V_162 [ V_30 ] ) ;
V_134 = F_86 ( V_162 [ V_30 ] ) ;
F_72 ( V_161 , L_17 , V_134 ,
& V_136 [ V_144 ++ ] ) ;
}
}
static bool T_8 F_87 ( struct V_1 * V_12 )
{
struct V_159 * V_143 ;
V_143 = (struct V_159 * ) V_12 -> V_51 ;
return V_143 -> V_65 & V_167 ;
}
int T_8 F_88 ( struct V_1 * V_12 )
{
struct V_3 * V_4 ;
struct V_168 * V_99 ;
struct V_135 * V_169 ;
enum V_170 V_171 ;
int V_106 , V_172 ;
const struct V_173 * V_105 = F_89 ( V_12 ) ;
if ( ! V_105 )
return - V_86 ;
V_99 = F_90 ( V_105 -> V_133 , V_174 ) ;
if ( ! V_99 )
return - V_8 ;
if ( V_105 -> V_175 )
V_105 -> V_175 ( & V_99 -> V_37 , V_12 ) ;
V_172 = V_105 -> V_176 ( V_12 ) ;
V_169 = F_91 ( V_172 , sizeof( * V_169 ) , V_19 ) ;
if ( ! V_169 ) {
V_106 = - V_8 ;
goto V_177;
}
V_105 -> V_178 ( V_169 , V_12 ) ;
V_106 = F_92 ( V_99 , V_169 , V_172 ) ;
F_13 ( V_169 ) ;
if ( V_106 )
goto V_177;
V_106 = F_93 ( V_99 , & V_12 , sizeof( V_12 ) ) ;
if ( V_106 )
goto V_177;
V_99 -> V_37 . V_130 = & V_99 -> V_37 . V_129 ;
V_4 = F_8 ( V_12 ) ;
if ( ! V_4 ) {
V_106 = - V_86 ;
goto V_177;
}
V_99 -> V_37 . V_4 = V_4 ;
V_171 = V_105 -> V_179 ( V_12 ) ?
V_180 : V_181 ;
F_94 ( & V_99 -> V_37 , V_171 ) ;
V_106 = F_95 ( V_99 ) ;
if ( V_106 )
goto V_182;
return 0 ;
V_182:
F_96 ( & V_99 -> V_37 ) ;
V_177:
F_97 ( V_99 ) ;
return V_106 ;
}
static bool T_8 F_98 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_55 ) {
struct V_1 * V_74 ;
struct V_61 * V_62 ;
int V_30 ;
V_62 = F_19 ( struct V_61 , V_2 ,
V_2 -> V_75 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_76 ; V_30 ++ , V_62 ++ ) {
if ( ! V_62 -> V_77 )
continue;
V_74 = F_19 ( struct V_1 ,
V_31 , V_62 -> V_77 ) ;
if ( ( V_74 -> type == V_109 ) ||
( V_74 -> type == V_107 ) ) {
F_99 () ;
return true ;
}
}
}
return false ;
}
static void T_8 F_100 ( void )
{
struct V_1 * V_2 , * V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_30 , V_106 ;
bool V_183 = false ;
V_29 = (struct V_28 * ) V_31 ;
V_2 = F_19 ( struct V_1 , V_29 ,
V_29 -> V_32 ) ;
V_27 = F_19 ( struct V_1 , V_29 ,
V_31 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_34 ; V_30 ++ ) {
if ( V_2 >= V_27 ) {
F_33 ( L_18 ) ;
return;
}
if ( ! V_183 )
V_183 = F_98 ( V_2 ) ;
if ( ( V_2 -> type == V_109 ) ||
( V_2 -> type == V_107 ) ) {
V_4 = F_101 () ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 ) ;
V_106 = F_88 ( V_2 ) ;
if ( V_106 ) {
F_10 ( V_2 ) ;
F_102 ( V_4 ) ;
return;
}
}
V_2 = F_19 ( struct V_1 , V_2 ,
V_2 -> V_33 ) ;
}
}
void T_8 F_103 ( void )
{
T_2 V_38 ;
V_38 = F_104 ( V_184 , 0 , & V_31 ) ;
if ( F_25 ( V_38 ) ) {
if ( V_38 != V_39 ) {
const char * V_185 = F_105 ( V_38 ) ;
F_33 ( L_19 , V_185 ) ;
}
return;
}
F_100 () ;
}
