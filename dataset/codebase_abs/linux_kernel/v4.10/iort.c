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
T_2 V_39 ;
if ( V_12 -> type == V_40 ) {
struct V_41 V_42 = { V_43 , NULL } ;
struct V_44 * V_45 = F_25 ( V_38 -> V_4 ) ;
struct V_46 * V_47 ;
if ( ! V_45 ) {
V_39 = V_48 ;
goto V_49;
}
V_39 = F_26 ( V_45 -> V_50 , V_51 , & V_42 ) ;
if ( F_27 ( V_39 ) ) {
F_28 ( V_38 , L_2 ) ;
goto V_49;
}
V_47 = (struct V_46 * ) V_12 -> V_52 ;
V_39 = ! strcmp ( V_47 -> V_53 , V_42 . V_54 ) ?
V_36 : V_48 ;
F_29 ( V_42 . V_54 ) ;
} else if ( V_12 -> type == V_55 ) {
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_59 = F_30 ( V_38 ) ;
V_57 = (struct V_56 * ) V_12 -> V_52 ;
V_39 = V_57 -> V_60 == F_31 ( V_59 ) ?
V_36 : V_48 ;
} else {
V_39 = V_48 ;
}
V_49:
return V_39 ;
}
static int F_32 ( struct V_61 * V_62 , T_3 type , T_4 V_63 ,
T_4 * V_64 )
{
if ( V_62 -> V_65 & V_66 ) {
if ( type == V_40 ||
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
T_4 * V_72 , T_3 V_73 ,
int V_74 )
{
struct V_1 * V_75 ;
struct V_61 * V_62 ;
if ( ! V_12 -> V_76 || ! V_12 -> V_77 ||
V_74 >= V_12 -> V_77 )
return NULL ;
V_62 = F_19 ( struct V_61 , V_12 ,
V_12 -> V_76 ) ;
if ( ! V_62 -> V_78 ) {
F_35 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
return NULL ;
}
V_75 = F_19 ( struct V_1 , V_31 ,
V_62 -> V_78 ) ;
if ( ! ( F_36 ( V_75 -> type ) & V_73 ) )
return NULL ;
if ( V_62 [ V_74 ] . V_65 & V_66 ) {
if ( V_12 -> type == V_40 ||
V_12 -> type == V_55 ) {
* V_72 = V_62 [ V_74 ] . V_67 ;
return V_75 ;
}
}
return NULL ;
}
static struct V_1 * F_37 ( struct V_1 * V_12 ,
T_4 V_63 , T_4 * V_64 ,
T_3 V_73 )
{
T_4 V_79 = V_63 ;
while ( V_12 ) {
struct V_61 * V_62 ;
int V_30 ;
if ( F_36 ( V_12 -> type ) & V_73 ) {
if ( V_64 )
* V_64 = V_79 ;
return V_12 ;
}
if ( ! V_12 -> V_76 || ! V_12 -> V_77 )
goto V_80;
V_62 = F_19 ( struct V_61 , V_12 ,
V_12 -> V_76 ) ;
if ( ! V_62 -> V_78 ) {
F_35 ( V_68 L_4 ,
V_12 , V_12 -> type ) ;
goto V_80;
}
for ( V_30 = 0 ; V_30 < V_12 -> V_77 ; V_30 ++ , V_62 ++ ) {
if ( ! F_32 ( V_62 , V_12 -> type , V_79 , & V_79 ) )
break;
}
if ( V_30 == V_12 -> V_77 )
goto V_80;
V_12 = F_19 ( struct V_1 , V_31 ,
V_62 -> V_78 ) ;
}
V_80:
if ( V_64 )
* V_64 = V_63 ;
return NULL ;
}
static struct V_1 * F_38 ( struct V_37 * V_38 )
{
struct V_58 * V_81 ;
if ( ! F_39 ( V_38 ) )
return F_18 ( V_40 ,
F_24 , V_38 ) ;
V_81 = F_40 ( V_38 ) -> V_59 ;
while ( ! F_41 ( V_81 ) )
V_81 = V_81 -> V_75 ;
return F_18 ( V_55 ,
F_24 , & V_81 -> V_38 ) ;
}
T_4 F_42 ( struct V_37 * V_38 , T_4 V_82 )
{
struct V_1 * V_12 ;
T_4 V_83 ;
V_12 = F_38 ( V_38 ) ;
if ( ! V_12 )
return V_82 ;
F_37 ( V_12 , V_82 , & V_83 , V_84 ) ;
return V_83 ;
}
static int F_43 ( struct V_37 * V_38 , T_4 V_82 ,
unsigned int V_85 , int * V_86 )
{
struct V_87 * V_88 ;
struct V_1 * V_12 ;
V_12 = F_38 ( V_38 ) ;
if ( ! V_12 )
return - V_69 ;
V_12 = F_37 ( V_12 , V_82 , NULL , V_84 ) ;
if ( ! V_12 )
return - V_69 ;
V_88 = (struct V_87 * ) V_12 -> V_52 ;
if ( V_85 > V_88 -> V_89 ) {
F_44 ( V_38 , L_5 ,
V_85 , V_88 -> V_89 ) ;
return - V_69 ;
}
* V_86 = V_88 -> V_90 [ V_85 ] ;
return 0 ;
}
struct V_91 * F_45 ( struct V_37 * V_38 , T_4 V_82 )
{
struct V_3 * V_50 ;
int V_86 ;
if ( F_43 ( V_38 , V_82 , 0 , & V_86 ) )
return NULL ;
V_50 = F_17 ( V_86 ) ;
if ( ! V_50 )
return NULL ;
return F_46 ( V_50 , V_92 ) ;
}
static int F_47 ( struct V_93 * V_94 , T_5 V_95 , void * V_96 )
{
T_4 * V_79 = V_96 ;
* V_79 = V_95 ;
return 0 ;
}
static int F_48 ( struct V_37 * V_38 , T_4 V_97 ,
struct V_3 * V_4 ,
const struct V_98 * V_99 )
{
int V_100 = F_49 ( V_38 , V_4 , V_99 ) ;
if ( ! V_100 )
V_100 = F_50 ( V_38 , & V_97 , 1 ) ;
return V_100 ;
}
static const struct V_98 * F_51 ( struct V_37 * V_38 ,
struct V_1 * V_12 ,
T_4 V_97 )
{
const struct V_98 * V_99 = NULL ;
int V_100 = - V_101 ;
struct V_3 * V_5 ;
if ( V_12 ) {
V_5 = F_8 ( V_12 ) ;
if ( ! V_5 )
return NULL ;
V_99 = F_52 ( V_5 ) ;
if ( ! V_99 )
return NULL ;
V_100 = F_48 ( V_38 , V_97 , V_5 , V_99 ) ;
}
return V_100 ? NULL : V_99 ;
}
void F_53 ( struct V_37 * V_38 )
{
if ( ! V_38 -> V_102 )
V_38 -> V_102 = F_54 ( 32 ) ;
if ( ! V_38 -> V_103 )
V_38 -> V_103 = & V_38 -> V_102 ;
}
const struct V_98 * F_55 ( struct V_37 * V_38 )
{
struct V_1 * V_12 , * V_75 ;
const struct V_98 * V_99 = NULL ;
T_4 V_97 = 0 ;
if ( F_39 ( V_38 ) ) {
struct V_58 * V_59 = F_40 ( V_38 ) -> V_59 ;
T_4 V_79 ;
F_56 ( F_40 ( V_38 ) , F_47 ,
& V_79 ) ;
V_12 = F_18 ( V_55 ,
F_24 , & V_59 -> V_38 ) ;
if ( ! V_12 )
return NULL ;
V_75 = F_37 ( V_12 , V_79 , & V_97 ,
V_104 ) ;
V_99 = F_51 ( V_38 , V_75 , V_97 ) ;
} else {
int V_30 = 0 ;
V_12 = F_18 ( V_40 ,
F_24 , V_38 ) ;
if ( ! V_12 )
return NULL ;
V_75 = F_34 ( V_12 , & V_97 ,
V_104 , V_30 ++ ) ;
while ( V_75 ) {
V_99 = F_51 ( V_38 , V_75 , V_97 ) ;
V_75 = F_34 ( V_12 , & V_97 ,
V_104 , V_30 ++ ) ;
}
}
return V_99 ;
}
static void T_6 F_57 ( int V_105 , const char * V_106 ,
int V_107 ,
struct V_108 * V_109 )
{
int V_110 = F_58 ( NULL , V_105 , V_107 ,
V_111 ) ;
if ( V_110 <= 0 ) {
F_35 ( L_6 , V_105 ,
V_106 ) ;
return;
}
V_109 -> V_112 = V_110 ;
V_109 -> V_113 = V_110 ;
V_109 -> V_65 = V_114 ;
V_109 -> V_106 = V_106 ;
}
static int T_6 F_59 ( struct V_1 * V_12 )
{
struct V_115 * V_116 ;
int V_117 = 1 ;
V_116 = (struct V_115 * ) V_12 -> V_52 ;
if ( V_116 -> V_118 )
V_117 ++ ;
if ( V_116 -> V_119 )
V_117 ++ ;
if ( V_116 -> V_120 )
V_117 ++ ;
if ( V_116 -> V_121 )
V_117 ++ ;
return V_117 ;
}
static void T_6 F_60 ( struct V_108 * V_109 ,
struct V_1 * V_12 )
{
struct V_115 * V_116 ;
int V_117 = 0 ;
V_116 = (struct V_115 * ) V_12 -> V_52 ;
V_109 [ V_117 ] . V_112 = V_116 -> V_122 ;
V_109 [ V_117 ] . V_113 = V_116 -> V_122 + V_123 - 1 ;
V_109 [ V_117 ] . V_65 = V_124 ;
V_117 ++ ;
if ( V_116 -> V_118 )
F_57 ( V_116 -> V_118 , L_7 ,
V_125 ,
& V_109 [ V_117 ++ ] ) ;
if ( V_116 -> V_119 )
F_57 ( V_116 -> V_119 , L_8 ,
V_125 ,
& V_109 [ V_117 ++ ] ) ;
if ( V_116 -> V_120 )
F_57 ( V_116 -> V_120 , L_9 ,
V_125 ,
& V_109 [ V_117 ++ ] ) ;
if ( V_116 -> V_121 )
F_57 ( V_116 -> V_121 , L_10 ,
V_125 ,
& V_109 [ V_117 ++ ] ) ;
}
static bool T_6 F_61 ( struct V_1 * V_12 )
{
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) V_12 -> V_52 ;
return V_116 -> V_65 & V_126 ;
}
static int T_6 F_62 ( struct V_1 * V_12 )
{
struct V_127 * V_116 ;
V_116 = (struct V_127 * ) V_12 -> V_52 ;
return V_116 -> V_128 + 2 ;
}
static void T_6 F_63 ( struct V_108 * V_109 ,
struct V_1 * V_12 )
{
struct V_127 * V_116 ;
int V_30 , V_129 , V_107 , V_117 = 0 ;
T_7 * V_130 , * V_131 ;
V_116 = (struct V_127 * ) V_12 -> V_52 ;
V_109 [ V_117 ] . V_112 = V_116 -> V_122 ;
V_109 [ V_117 ] . V_113 = V_116 -> V_122 + V_116 -> V_132 - 1 ;
V_109 [ V_117 ] . V_65 = V_124 ;
V_117 ++ ;
V_131 = F_19 ( T_7 , V_12 , V_116 -> V_133 ) ;
V_129 = F_64 ( V_131 [ 0 ] ) ;
V_107 = F_65 ( V_131 [ 0 ] ) ;
F_57 ( V_129 , L_11 , V_107 ,
& V_109 [ V_117 ++ ] ) ;
V_130 = F_19 ( T_7 , V_12 , V_116 -> V_134 ) ;
for ( V_30 = 0 ; V_30 < V_116 -> V_128 ; V_30 ++ ) {
V_129 = F_64 ( V_130 [ V_30 ] ) ;
V_107 = F_65 ( V_130 [ V_30 ] ) ;
F_57 ( V_129 , L_12 , V_107 ,
& V_109 [ V_117 ++ ] ) ;
}
}
static bool T_6 F_66 ( struct V_1 * V_12 )
{
struct V_127 * V_116 ;
V_116 = (struct V_127 * ) V_12 -> V_52 ;
return V_116 -> V_65 & V_135 ;
}
int T_6 F_67 ( struct V_1 * V_12 )
{
struct V_3 * V_4 ;
struct V_136 * V_94 ;
struct V_108 * V_137 ;
enum V_138 V_139 ;
int V_100 , V_140 ;
const struct V_141 * V_99 = F_68 ( V_12 ) ;
if ( ! V_99 )
return - V_101 ;
V_94 = F_69 ( V_99 -> V_106 , V_142 ) ;
if ( ! V_94 )
return F_70 ( V_94 ) ;
V_140 = V_99 -> V_143 ( V_12 ) ;
V_137 = F_71 ( V_140 , sizeof( * V_137 ) , V_19 ) ;
if ( ! V_137 ) {
V_100 = - V_8 ;
goto V_144;
}
V_99 -> V_145 ( V_137 , V_12 ) ;
V_100 = F_72 ( V_94 , V_137 , V_140 ) ;
F_13 ( V_137 ) ;
if ( V_100 )
goto V_144;
V_100 = F_73 ( V_94 , & V_12 , sizeof( V_12 ) ) ;
if ( V_100 )
goto V_144;
V_94 -> V_38 . V_103 = & V_94 -> V_38 . V_102 ;
V_4 = F_8 ( V_12 ) ;
if ( ! V_4 ) {
V_100 = - V_101 ;
goto V_144;
}
V_94 -> V_38 . V_4 = V_4 ;
V_139 = V_99 -> V_146 ( V_12 ) ?
V_147 : V_148 ;
F_74 ( & V_94 -> V_38 , V_139 ) ;
V_100 = F_75 ( V_94 ) ;
if ( V_100 )
goto V_149;
return 0 ;
V_149:
F_76 ( & V_94 -> V_38 ) ;
V_144:
F_77 ( V_94 ) ;
return V_100 ;
}
static void T_6 F_78 ( void )
{
struct V_1 * V_2 , * V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_30 , V_100 ;
V_29 = (struct V_28 * ) V_31 ;
V_2 = F_19 ( struct V_1 , V_29 ,
V_29 -> V_32 ) ;
V_27 = F_19 ( struct V_1 , V_29 ,
V_31 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_34 ; V_30 ++ ) {
if ( V_2 >= V_27 ) {
F_35 ( L_13 ) ;
return;
}
if ( ( V_2 -> type == V_150 ) ||
( V_2 -> type == V_151 ) ) {
V_4 = F_79 () ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 ) ;
V_100 = F_67 ( V_2 ) ;
if ( V_100 ) {
F_10 ( V_2 ) ;
F_80 ( V_4 ) ;
return;
}
}
V_2 = F_19 ( struct V_1 , V_2 ,
V_2 -> V_33 ) ;
}
}
void T_6 F_81 ( void )
{
T_2 V_39 ;
V_39 = F_82 ( V_152 , 0 , & V_31 ) ;
if ( F_27 ( V_39 ) ) {
if ( V_39 != V_48 ) {
const char * V_153 = F_83 ( V_39 ) ;
F_35 ( L_14 , V_153 ) ;
}
return;
}
F_78 () ;
F_84 ( V_29 ) ;
}
