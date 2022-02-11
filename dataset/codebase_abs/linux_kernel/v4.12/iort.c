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
static T_2
F_22 ( struct V_1 * V_12 , void * V_26 )
{
return V_36 ;
}
bool F_23 ( T_3 type )
{
struct V_1 * V_12 ;
V_12 = F_18 ( type , F_22 , NULL ) ;
return V_12 != NULL ;
}
static T_2 F_24 ( struct V_1 * V_12 ,
void * V_26 )
{
struct V_37 * V_38 = V_26 ;
T_2 V_39 = V_40 ;
if ( V_12 -> type == V_41 ) {
struct V_42 V_43 = { V_44 , NULL } ;
struct V_45 * V_46 = F_25 ( V_38 -> V_4 ) ;
struct V_47 * V_48 ;
if ( ! V_46 )
goto V_49;
V_39 = F_26 ( V_46 -> V_50 , V_51 , & V_43 ) ;
if ( F_27 ( V_39 ) ) {
F_28 ( V_38 , L_2 ) ;
goto V_49;
}
V_48 = (struct V_47 * ) V_12 -> V_52 ;
V_39 = ! strcmp ( V_48 -> V_53 , V_43 . V_54 ) ?
V_36 : V_40 ;
F_29 ( V_43 . V_54 ) ;
} else if ( V_12 -> type == V_55 ) {
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_59 = F_30 ( V_38 ) ;
V_57 = (struct V_56 * ) V_12 -> V_52 ;
V_39 = V_57 -> V_60 == F_31 ( V_59 ) ?
V_36 : V_40 ;
}
V_49:
return V_39 ;
}
static int F_32 ( struct V_61 * V_62 , T_3 type , T_4 V_63 ,
T_4 * V_64 )
{
if ( V_62 -> V_65 & V_66 ) {
if ( type == V_41 ||
type == V_55 ) {
* V_64 = V_62 -> V_67 ;
return 0 ;
}
F_33 ( V_68 L_3 ,
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
struct V_1 * F_34 ( struct V_1 * V_12 ,
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
F_35 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
return NULL ;
}
V_74 = F_19 ( struct V_1 , V_31 ,
V_62 -> V_77 ) ;
if ( V_62 -> V_65 & V_66 ) {
if ( V_12 -> type == V_41 ||
V_12 -> type == V_55 ) {
* V_72 = V_62 -> V_67 ;
return V_74 ;
}
}
return NULL ;
}
static struct V_1 * F_36 ( struct V_1 * V_12 ,
T_4 V_78 , T_4 * V_72 ,
T_3 V_79 )
{
T_4 V_80 = V_78 ;
while ( V_12 ) {
struct V_61 * V_62 ;
int V_30 ;
if ( F_37 ( V_12 -> type ) & V_79 ) {
if ( V_72 )
* V_72 = V_80 ;
return V_12 ;
}
if ( ! V_12 -> V_75 || ! V_12 -> V_76 )
goto V_81;
V_62 = F_19 ( struct V_61 , V_12 ,
V_12 -> V_75 ) ;
if ( ! V_62 -> V_77 ) {
F_35 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
goto V_81;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ , V_62 ++ ) {
if ( ! F_32 ( V_62 , V_12 -> type , V_80 , & V_80 ) )
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
struct V_1 * F_38 ( struct V_1 * V_12 ,
T_4 * V_72 , T_3 V_79 ,
int V_73 )
{
struct V_1 * V_74 ;
T_4 V_80 ;
V_74 = F_34 ( V_12 , & V_80 , V_73 ) ;
if ( ! V_74 )
return NULL ;
if ( ! ( F_37 ( V_74 -> type ) & V_79 ) )
V_74 = F_36 ( V_74 , V_80 , V_72 , V_79 ) ;
else
if ( V_72 )
* V_72 = V_80 ;
return V_74 ;
}
static struct V_1 * F_39 ( struct V_37 * V_38 )
{
struct V_58 * V_82 ;
if ( ! F_40 ( V_38 ) )
return F_18 ( V_41 ,
F_24 , V_38 ) ;
V_82 = F_41 ( V_38 ) -> V_59 ;
while ( ! F_42 ( V_82 ) )
V_82 = V_82 -> V_74 ;
return F_18 ( V_55 ,
F_24 , & V_82 -> V_38 ) ;
}
T_4 F_43 ( struct V_37 * V_38 , T_4 V_83 )
{
struct V_1 * V_12 ;
T_4 V_84 ;
V_12 = F_39 ( V_38 ) ;
if ( ! V_12 )
return V_83 ;
F_36 ( V_12 , V_83 , & V_84 , V_85 ) ;
return V_84 ;
}
int F_44 ( struct V_37 * V_38 , T_4 * V_84 )
{
int V_30 ;
struct V_1 * V_12 ;
V_12 = F_39 ( V_38 ) ;
if ( ! V_12 )
return - V_86 ;
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ ) {
if ( F_38 ( V_12 , V_84 , V_85 , V_30 ) )
return 0 ;
}
return - V_86 ;
}
static int F_45 ( struct V_37 * V_38 , T_4 V_83 ,
unsigned int V_87 , int * V_88 )
{
struct V_89 * V_90 ;
struct V_1 * V_12 ;
V_12 = F_39 ( V_38 ) ;
if ( ! V_12 )
return - V_69 ;
V_12 = F_36 ( V_12 , V_83 , NULL , V_85 ) ;
if ( ! V_12 )
return - V_69 ;
V_90 = (struct V_89 * ) V_12 -> V_52 ;
if ( V_87 > V_90 -> V_91 ) {
F_46 ( V_38 , L_5 ,
V_87 , V_90 -> V_91 ) ;
return - V_69 ;
}
* V_88 = V_90 -> V_92 [ V_87 ] ;
return 0 ;
}
struct V_93 * F_47 ( struct V_37 * V_38 , T_4 V_83 )
{
struct V_3 * V_50 ;
int V_88 ;
if ( F_45 ( V_38 , V_83 , 0 , & V_88 ) )
return NULL ;
V_50 = F_17 ( V_88 ) ;
if ( ! V_50 )
return NULL ;
return F_48 ( V_50 , V_94 ) ;
}
static struct V_93 * F_49 ( struct V_37 * V_38 )
{
struct V_1 * V_12 , * V_95 ;
struct V_3 * V_5 ;
struct V_89 * V_90 ;
int V_30 ;
V_12 = F_18 ( V_41 ,
F_24 , V_38 ) ;
if ( ! V_12 )
return NULL ;
for ( V_30 = 0 ; V_30 < V_12 -> V_76 ; V_30 ++ ) {
V_95 = F_38 ( V_12 , NULL ,
V_85 , V_30 ) ;
if ( V_95 )
break;
}
if ( ! V_95 )
return NULL ;
V_90 = (struct V_89 * ) V_95 -> V_52 ;
V_5 = F_17 ( V_90 -> V_92 [ 0 ] ) ;
if ( ! V_5 )
return NULL ;
return F_48 ( V_5 , V_96 ) ;
}
void F_50 ( struct V_37 * V_38 )
{
struct V_93 * V_97 ;
V_97 = F_49 ( V_38 ) ;
if ( V_97 )
F_51 ( V_38 , V_97 ) ;
}
static int F_52 ( struct V_98 * V_99 , T_5 V_100 , void * V_101 )
{
T_4 * V_102 = V_101 ;
* V_102 = V_100 ;
return 0 ;
}
static int F_53 ( struct V_37 * V_38 , T_4 V_103 ,
struct V_3 * V_4 ,
const struct V_104 * V_105 )
{
int V_106 = F_54 ( V_38 , V_4 , V_105 ) ;
if ( ! V_106 )
V_106 = F_55 ( V_38 , & V_103 , 1 ) ;
return V_106 ;
}
static inline bool F_56 ( T_3 type )
{
switch ( type ) {
case V_107 :
return F_57 ( V_108 ) ;
case V_109 :
return F_57 ( V_110 ) ;
default:
F_33 ( L_6 , type ) ;
return false ;
}
}
static inline
const struct V_104 * F_58 ( struct V_111 * V_112 )
{
return ( V_112 && V_112 -> V_105 ) ? V_112 -> V_105 : NULL ;
}
static inline
int F_59 ( const struct V_104 * V_105 , struct V_37 * V_38 )
{
int V_113 = 0 ;
if ( ! F_60 ( V_105 ) && V_105 -> V_114 && V_38 -> V_59 &&
! V_38 -> V_115 )
V_113 = V_105 -> V_114 ( V_38 ) ;
return V_113 ;
}
static inline
const struct V_104 * F_58 ( struct V_111 * V_112 )
{ return NULL ; }
static inline
int F_59 ( const struct V_104 * V_105 , struct V_37 * V_38 )
{ return 0 ; }
static const struct V_104 * F_61 ( struct V_37 * V_38 ,
struct V_1 * V_12 ,
T_4 V_103 )
{
const struct V_104 * V_105 = NULL ;
int V_106 = - V_86 ;
struct V_3 * V_5 ;
if ( V_12 ) {
V_5 = F_8 ( V_12 ) ;
if ( ! V_5 )
return NULL ;
V_105 = F_62 ( V_5 ) ;
if ( ! V_105 )
return F_56 ( V_12 -> type ) ?
F_63 ( - V_116 ) : NULL ;
V_106 = F_53 ( V_38 , V_103 , V_5 , V_105 ) ;
}
return V_106 ? NULL : V_105 ;
}
void F_64 ( struct V_37 * V_38 )
{
if ( ! V_38 -> V_117 )
V_38 -> V_117 = F_65 ( 32 ) ;
if ( ! V_38 -> V_118 )
V_38 -> V_118 = & V_38 -> V_117 ;
}
const struct V_104 * F_66 ( struct V_37 * V_38 )
{
struct V_1 * V_12 , * V_74 ;
const struct V_104 * V_105 = NULL ;
T_4 V_103 = 0 ;
int V_113 ;
V_105 = F_58 ( V_38 -> V_111 ) ;
if ( V_105 )
return V_105 ;
if ( F_40 ( V_38 ) ) {
struct V_58 * V_59 = F_41 ( V_38 ) -> V_59 ;
T_4 V_102 ;
F_67 ( F_41 ( V_38 ) , F_52 ,
& V_102 ) ;
V_12 = F_18 ( V_55 ,
F_24 , & V_59 -> V_38 ) ;
if ( ! V_12 )
return NULL ;
V_74 = F_36 ( V_12 , V_102 , & V_103 ,
V_119 ) ;
V_105 = F_61 ( V_38 , V_74 , V_103 ) ;
} else {
int V_30 = 0 ;
V_12 = F_18 ( V_41 ,
F_24 , V_38 ) ;
if ( ! V_12 )
return NULL ;
V_74 = F_38 ( V_12 , & V_103 ,
V_119 , V_30 ++ ) ;
while ( V_74 ) {
V_105 = F_61 ( V_38 , V_74 , V_103 ) ;
if ( F_60 ( V_105 ) )
return V_105 ;
V_74 = F_38 ( V_12 , & V_103 ,
V_119 ,
V_30 ++ ) ;
}
}
V_113 = F_59 ( V_105 , V_38 ) ;
if ( V_113 )
V_105 = F_63 ( V_113 ) ;
if ( F_68 ( V_105 ) && ( F_69 ( V_105 ) != - V_116 ) ) {
F_70 ( V_38 , L_7 , F_69 ( V_105 ) ) ;
V_105 = NULL ;
}
return V_105 ;
}
static void T_6 F_71 ( int V_120 , const char * V_121 ,
int V_122 ,
struct V_123 * V_124 )
{
int V_125 = F_72 ( NULL , V_120 , V_122 ,
V_126 ) ;
if ( V_125 <= 0 ) {
F_35 ( L_8 , V_120 ,
V_121 ) ;
return;
}
V_124 -> V_127 = V_125 ;
V_124 -> V_128 = V_125 ;
V_124 -> V_65 = V_129 ;
V_124 -> V_121 = V_121 ;
}
static int T_6 F_73 ( struct V_1 * V_12 )
{
struct V_130 * V_131 ;
int V_132 = 1 ;
V_131 = (struct V_130 * ) V_12 -> V_52 ;
if ( V_131 -> V_133 )
V_132 ++ ;
if ( V_131 -> V_134 )
V_132 ++ ;
if ( V_131 -> V_135 )
V_132 ++ ;
if ( V_131 -> V_136 )
V_132 ++ ;
return V_132 ;
}
static void T_6 F_74 ( struct V_123 * V_124 ,
struct V_1 * V_12 )
{
struct V_130 * V_131 ;
int V_132 = 0 ;
V_131 = (struct V_130 * ) V_12 -> V_52 ;
V_124 [ V_132 ] . V_127 = V_131 -> V_137 ;
V_124 [ V_132 ] . V_128 = V_131 -> V_137 + V_138 - 1 ;
V_124 [ V_132 ] . V_65 = V_139 ;
V_132 ++ ;
if ( V_131 -> V_133 )
F_71 ( V_131 -> V_133 , L_9 ,
V_140 ,
& V_124 [ V_132 ++ ] ) ;
if ( V_131 -> V_134 )
F_71 ( V_131 -> V_134 , L_10 ,
V_140 ,
& V_124 [ V_132 ++ ] ) ;
if ( V_131 -> V_135 )
F_71 ( V_131 -> V_135 , L_11 ,
V_140 ,
& V_124 [ V_132 ++ ] ) ;
if ( V_131 -> V_136 )
F_71 ( V_131 -> V_136 , L_12 ,
V_140 ,
& V_124 [ V_132 ++ ] ) ;
}
static bool T_6 F_75 ( struct V_1 * V_12 )
{
struct V_130 * V_131 ;
V_131 = (struct V_130 * ) V_12 -> V_52 ;
return V_131 -> V_65 & V_141 ;
}
static int T_6 F_76 ( struct V_1 * V_12 )
{
struct V_142 * V_131 ;
V_131 = (struct V_142 * ) V_12 -> V_52 ;
return V_131 -> V_143 + 2 ;
}
static void T_6 F_77 ( struct V_123 * V_124 ,
struct V_1 * V_12 )
{
struct V_142 * V_131 ;
int V_30 , V_144 , V_122 , V_132 = 0 ;
T_7 * V_145 , * V_146 ;
V_131 = (struct V_142 * ) V_12 -> V_52 ;
V_124 [ V_132 ] . V_127 = V_131 -> V_137 ;
V_124 [ V_132 ] . V_128 = V_131 -> V_137 + V_131 -> V_147 - 1 ;
V_124 [ V_132 ] . V_65 = V_139 ;
V_132 ++ ;
V_146 = F_19 ( T_7 , V_12 , V_131 -> V_148 ) ;
V_144 = F_78 ( V_146 [ 0 ] ) ;
V_122 = F_79 ( V_146 [ 0 ] ) ;
F_71 ( V_144 , L_13 , V_122 ,
& V_124 [ V_132 ++ ] ) ;
V_145 = F_19 ( T_7 , V_12 , V_131 -> V_149 ) ;
for ( V_30 = 0 ; V_30 < V_131 -> V_143 ; V_30 ++ ) {
V_144 = F_78 ( V_145 [ V_30 ] ) ;
V_122 = F_79 ( V_145 [ V_30 ] ) ;
F_71 ( V_144 , L_14 , V_122 ,
& V_124 [ V_132 ++ ] ) ;
}
}
static bool T_6 F_80 ( struct V_1 * V_12 )
{
struct V_142 * V_131 ;
V_131 = (struct V_142 * ) V_12 -> V_52 ;
return V_131 -> V_65 & V_150 ;
}
int T_6 F_81 ( struct V_1 * V_12 )
{
struct V_3 * V_4 ;
struct V_151 * V_99 ;
struct V_123 * V_152 ;
enum V_153 V_154 ;
int V_106 , V_155 ;
const struct V_156 * V_105 = F_82 ( V_12 ) ;
if ( ! V_105 )
return - V_86 ;
V_99 = F_83 ( V_105 -> V_121 , V_157 ) ;
if ( ! V_99 )
return - V_8 ;
V_155 = V_105 -> V_158 ( V_12 ) ;
V_152 = F_84 ( V_155 , sizeof( * V_152 ) , V_19 ) ;
if ( ! V_152 ) {
V_106 = - V_8 ;
goto V_159;
}
V_105 -> V_160 ( V_152 , V_12 ) ;
V_106 = F_85 ( V_99 , V_152 , V_155 ) ;
F_13 ( V_152 ) ;
if ( V_106 )
goto V_159;
V_106 = F_86 ( V_99 , & V_12 , sizeof( V_12 ) ) ;
if ( V_106 )
goto V_159;
V_99 -> V_38 . V_118 = & V_99 -> V_38 . V_117 ;
V_4 = F_8 ( V_12 ) ;
if ( ! V_4 ) {
V_106 = - V_86 ;
goto V_159;
}
V_99 -> V_38 . V_4 = V_4 ;
V_154 = V_105 -> V_161 ( V_12 ) ?
V_162 : V_163 ;
F_87 ( & V_99 -> V_38 , V_154 ) ;
V_106 = F_88 ( V_99 ) ;
if ( V_106 )
goto V_164;
return 0 ;
V_164:
F_89 ( & V_99 -> V_38 ) ;
V_159:
F_90 ( V_99 ) ;
return V_106 ;
}
static void T_6 F_91 ( void )
{
struct V_1 * V_2 , * V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_30 , V_106 ;
V_29 = (struct V_28 * ) V_31 ;
V_2 = F_19 ( struct V_1 , V_29 ,
V_29 -> V_32 ) ;
V_27 = F_19 ( struct V_1 , V_29 ,
V_31 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_34 ; V_30 ++ ) {
if ( V_2 >= V_27 ) {
F_35 ( L_15 ) ;
return;
}
if ( ( V_2 -> type == V_109 ) ||
( V_2 -> type == V_107 ) ) {
V_4 = F_92 () ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 ) ;
V_106 = F_81 ( V_2 ) ;
if ( V_106 ) {
F_10 ( V_2 ) ;
F_93 ( V_4 ) ;
return;
}
}
V_2 = F_19 ( struct V_1 , V_2 ,
V_2 -> V_33 ) ;
}
}
void T_6 F_94 ( void )
{
T_2 V_39 ;
V_39 = F_95 ( V_165 , 0 , & V_31 ) ;
if ( F_27 ( V_39 ) ) {
if ( V_39 != V_40 ) {
const char * V_166 = F_96 ( V_39 ) ;
F_35 ( L_16 , V_166 ) ;
}
return;
}
F_91 () ;
}
