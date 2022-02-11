int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( V_2 ,
V_3 ) ;
return V_1 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_4 ( V_6 , & V_5 -> V_7 . V_8 ,
F_5 ( 10 ) ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
char V_9 ;
V_9 = F_7 ( & V_5 -> V_10 ) ;
switch ( V_9 ) {
case 0 :
F_8 ( V_5 , V_11 , 1 ) ;
break;
case 1 :
F_9 ( V_5 , V_11 , 1 ,
NULL , 0 ) ;
break;
}
}
void F_10 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_11 ( V_13 ) ;
F_6 ( V_5 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
T_2 V_16 ,
void * V_17 , T_3 V_18 )
{
if ( V_16 & V_19 )
F_13 ( V_20 , & V_15 -> V_21 ) ;
else
F_14 ( V_20 , & V_15 -> V_21 ) ;
}
int F_15 ( struct V_4 * V_5 )
{
V_5 -> V_7 . V_22 = V_23 ;
V_5 -> V_7 . V_24 = V_23 ;
if ( V_5 -> V_7 . V_25 || V_5 -> V_7 . V_26 )
return 0 ;
V_5 -> V_7 . V_25 = F_16 ( 128 ) ;
if ( ! V_5 -> V_7 . V_25 )
goto V_27;
F_17 ( V_5 -> V_7 . V_25 ,
& V_28 ) ;
V_5 -> V_7 . V_26 = F_16 ( 128 ) ;
if ( ! V_5 -> V_7 . V_26 )
goto V_27;
F_17 ( V_5 -> V_7 . V_26 ,
& V_29 ) ;
F_18 ( & V_5 -> V_7 . V_8 , V_30 ) ;
F_3 ( V_5 ) ;
F_19 ( V_5 , F_12 ,
NULL , V_11 , 1 ,
V_19 ) ;
F_6 ( V_5 ) ;
return 0 ;
V_27:
return - V_31 ;
}
void F_20 ( struct V_4 * V_5 )
{
F_21 ( & V_5 -> V_10 , 0 ) ;
V_5 -> V_7 . V_32 = 200 ;
V_5 -> V_7 . V_33 = 10 ;
V_5 -> V_7 . V_34 = 200 ;
}
void F_22 ( struct V_14 * V_35 )
{
F_23 ( & V_35 -> V_36 ) ;
F_23 ( & V_35 -> V_37 ) ;
F_24 ( & V_35 -> V_38 ) ;
F_24 ( & V_35 -> V_39 ) ;
}
static void F_25 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
V_43 = F_26 ( V_41 , struct V_42 , V_44 ) ;
F_27 ( V_43 -> V_35 ) ;
F_28 ( V_43 , V_45 ) ;
}
static void F_29 ( struct V_42 * V_43 )
{
F_30 ( & V_43 -> V_44 , F_25 ) ;
}
static void F_31 ( struct V_40 * V_41 )
{
struct V_46 * V_47 ;
V_47 = F_26 ( V_41 , struct V_46 , V_44 ) ;
F_28 ( V_47 , V_45 ) ;
}
static void F_32 ( struct V_46 * V_47 )
{
F_30 ( & V_47 -> V_44 , F_31 ) ;
}
static void F_33 ( struct V_48 * V_49 )
{
F_34 ( V_49 -> V_50 ) ;
F_32 ( V_49 -> V_47 ) ;
F_35 ( V_49 ) ;
}
static bool F_36 ( struct V_4 * V_5 ,
struct V_42 * V_43 )
{
if ( F_7 ( & V_5 -> V_51 ) != V_52 )
return true ;
return F_37 ( V_43 -> V_53 , V_54 ) ;
}
static bool F_38 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
if ( F_7 ( & V_5 -> V_51 ) != V_52 )
return true ;
return F_37 ( V_47 -> V_55 ,
V_5 -> V_7 . V_33 * 10 ) ;
}
static bool F_39 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
if ( F_7 ( & V_5 -> V_51 ) != V_52 )
return true ;
return F_37 ( V_47 -> V_55 ,
V_5 -> V_7 . V_34 * 10 ) ;
}
static void
F_40 ( struct V_4 * V_5 ,
struct V_56 * V_57 ,
T_4 * V_58 ,
bool (* F_41)( struct V_4 * ,
struct V_42 * ) )
{
struct V_42 * V_43 , * V_59 ;
F_42 ( V_58 ) ;
F_43 (nc_node, nc_node_tmp, list, list) {
if ( F_41 && ! F_41 ( V_5 , V_43 ) )
continue;
F_44 ( V_60 , V_5 ,
L_1 ,
V_43 -> V_61 , V_43 -> V_35 -> V_15 ) ;
F_45 ( & V_43 -> V_57 ) ;
F_29 ( V_43 ) ;
}
F_46 ( V_58 ) ;
}
void F_47 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
bool (* F_41)( struct V_4 * ,
struct V_42 * ) )
{
F_40 ( V_5 , & V_35 -> V_36 ,
& V_35 -> V_38 ,
F_41 ) ;
F_40 ( V_5 , & V_35 -> V_37 ,
& V_35 -> V_39 ,
F_41 ) ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_62 * V_63 = V_5 -> V_64 ;
struct V_65 * V_66 ;
struct V_14 * V_35 ;
T_5 V_67 ;
if ( ! V_63 )
return;
for ( V_67 = 0 ; V_67 < V_63 -> V_68 ; V_67 ++ ) {
V_66 = & V_63 -> V_69 [ V_67 ] ;
F_49 () ;
F_50 (orig_node, head, hash_entry)
F_47 ( V_5 , V_35 ,
F_36 ) ;
F_51 () ;
}
}
static void F_52 ( struct V_4 * V_5 ,
struct V_62 * V_63 ,
bool (* F_41)( struct V_4 * ,
struct V_46 * ) )
{
struct V_65 * V_66 ;
struct V_70 * V_71 ;
struct V_46 * V_47 ;
T_4 * V_58 ;
T_5 V_67 ;
for ( V_67 = 0 ; V_67 < V_63 -> V_68 ; V_67 ++ ) {
V_66 = & V_63 -> V_69 [ V_67 ] ;
V_58 = & V_63 -> V_72 [ V_67 ] ;
F_42 ( V_58 ) ;
F_53 (nc_path, node_tmp, head, hash_entry) {
if ( F_41 && ! F_41 ( V_5 , V_47 ) )
continue;
if ( ! F_54 ( F_55 ( & V_47 -> V_73 ) ) ) {
F_56 ( V_74 ,
V_75
L_2 ,
V_47 -> V_76 ,
V_47 -> V_77 ) ;
continue;
}
F_44 ( V_60 , V_5 ,
L_3 ,
V_47 -> V_76 , V_47 -> V_77 ) ;
F_57 ( & V_47 -> V_78 ) ;
F_32 ( V_47 ) ;
}
F_46 ( V_58 ) ;
}
}
static void F_58 ( struct V_46 * V_79 , const char * V_80 ,
const char * V_81 )
{
memcpy ( V_79 -> V_76 , V_80 , sizeof( V_79 -> V_76 ) ) ;
memcpy ( V_79 -> V_77 , V_81 , sizeof( V_79 -> V_77 ) ) ;
}
static T_5 F_59 ( const void * V_82 , T_5 V_68 )
{
const struct V_46 * V_47 = V_82 ;
T_5 V_63 = 0 ;
V_63 = F_60 ( & V_47 -> V_76 , sizeof( V_47 -> V_76 ) , V_63 ) ;
V_63 = F_60 ( & V_47 -> V_77 , sizeof( V_47 -> V_77 ) , V_63 ) ;
return V_63 % V_68 ;
}
static bool F_61 ( const struct V_70 * V_83 ,
const void * V_84 )
{
const struct V_46 * V_85 , * V_86 ;
V_85 = F_26 ( V_83 , struct V_46 , V_78 ) ;
V_86 = V_84 ;
if ( ! F_62 ( V_85 -> V_76 , V_86 -> V_76 ) )
return false ;
if ( ! F_62 ( V_85 -> V_77 , V_86 -> V_77 ) )
return false ;
return true ;
}
static struct V_46 *
F_63 ( struct V_62 * V_63 ,
void * V_82 )
{
struct V_65 * V_66 ;
struct V_46 * V_47 , * V_87 = NULL ;
int V_88 ;
if ( ! V_63 )
return NULL ;
V_88 = F_59 ( V_82 , V_63 -> V_68 ) ;
V_66 = & V_63 -> V_69 [ V_88 ] ;
F_49 () ;
F_50 (nc_path, head, hash_entry) {
if ( ! F_61 ( & V_47 -> V_78 , V_82 ) )
continue;
if ( ! F_64 ( & V_47 -> V_44 ) )
continue;
V_87 = V_47 ;
break;
}
F_51 () ;
return V_87 ;
}
static void F_65 ( struct V_48 * V_49 )
{
F_66 ( V_49 -> V_50 , V_49 -> V_89 ) ;
V_49 -> V_50 = NULL ;
F_33 ( V_49 ) ;
}
static bool F_67 ( struct V_4 * V_5 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
unsigned long V_90 = V_5 -> V_7 . V_34 ;
bool V_91 = false ;
F_68 ( & V_47 -> V_92 ) ;
if ( F_7 ( & V_5 -> V_51 ) == V_52 &&
! F_37 ( V_49 -> V_93 , V_90 ) )
goto V_94;
F_69 ( & V_49 -> V_57 ) ;
F_33 ( V_49 ) ;
V_91 = true ;
V_94:
return V_91 ;
}
static bool F_70 ( struct V_4 * V_5 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
unsigned long V_90 = V_5 -> V_7 . V_33 ;
F_68 ( & V_47 -> V_92 ) ;
if ( F_7 ( & V_5 -> V_51 ) == V_52 &&
! F_37 ( V_49 -> V_93 , V_90 ) )
return false ;
F_71 ( V_5 , V_95 ) ;
F_72 ( V_5 , V_96 ,
V_49 -> V_50 -> V_97 + V_98 ) ;
F_69 ( & V_49 -> V_57 ) ;
F_65 ( V_49 ) ;
return true ;
}
static void
F_73 ( struct V_4 * V_5 ,
struct V_62 * V_63 ,
bool (* F_74)( struct V_4 * ,
struct V_46 * ,
struct V_48 * ) )
{
struct V_65 * V_66 ;
struct V_48 * V_49 , * V_99 ;
struct V_46 * V_47 ;
bool V_1 ;
int V_67 ;
if ( ! V_63 )
return;
for ( V_67 = 0 ; V_67 < V_63 -> V_68 ; V_67 ++ ) {
V_66 = & V_63 -> V_69 [ V_67 ] ;
F_49 () ;
F_50 (nc_path, head, hash_entry) {
F_42 ( & V_47 -> V_92 ) ;
F_43 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_1 = F_74 ( V_5 , V_47 , V_49 ) ;
if ( ! V_1 )
break;
}
F_46 ( & V_47 -> V_92 ) ;
}
F_51 () ;
}
}
static void V_30 ( struct V_100 * V_8 )
{
struct V_101 * V_101 ;
struct V_102 * V_103 ;
struct V_4 * V_5 ;
unsigned long V_90 ;
V_101 = F_75 ( V_8 ) ;
V_103 = F_26 ( V_101 , struct V_102 , V_8 ) ;
V_5 = F_26 ( V_103 , struct V_4 , V_7 ) ;
F_48 ( V_5 ) ;
F_52 ( V_5 , V_5 -> V_7 . V_25 ,
F_38 ) ;
F_52 ( V_5 , V_5 -> V_7 . V_26 ,
F_39 ) ;
V_90 = V_5 -> V_7 . V_33 ;
if ( F_37 ( V_5 -> V_7 . V_22 , V_90 ) ) {
F_73 ( V_5 , V_5 -> V_7 . V_25 ,
F_70 ) ;
V_5 -> V_7 . V_22 = V_23 ;
}
if ( F_37 ( V_5 -> V_7 . V_24 ,
V_5 -> V_7 . V_34 ) ) {
F_73 ( V_5 , V_5 -> V_7 . V_26 ,
F_67 ) ;
V_5 -> V_7 . V_24 = V_23 ;
}
F_3 ( V_5 ) ;
}
static bool F_76 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 ;
T_5 V_108 ;
T_2 V_109 ;
V_107 = F_77 ( V_35 , V_110 ) ;
if ( ! V_107 )
return false ;
V_109 = V_107 -> V_109 ;
V_108 = V_107 -> V_108 ;
F_78 ( V_107 ) ;
if ( V_108 != F_79 ( V_105 -> V_111 ) )
return false ;
if ( V_109 != V_105 -> V_112 + 1 )
return false ;
if ( ! F_62 ( V_105 -> V_15 , V_105 -> V_113 ) )
return false ;
if ( V_105 -> V_114 < V_5 -> V_7 . V_32 )
return false ;
return true ;
}
static struct V_42 *
F_80 ( struct V_14 * V_35 ,
struct V_14 * V_115 ,
bool V_116 )
{
struct V_42 * V_43 , * V_117 = NULL ;
struct V_56 * V_57 ;
if ( V_116 )
V_57 = & V_115 -> V_36 ;
else
V_57 = & V_115 -> V_37 ;
F_49 () ;
F_81 (nc_node, list, list) {
if ( ! F_62 ( V_43 -> V_61 , V_35 -> V_15 ) )
continue;
if ( ! F_64 ( & V_43 -> V_44 ) )
continue;
V_117 = V_43 ;
break;
}
F_51 () ;
return V_117 ;
}
static struct V_42 *
F_82 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_115 ,
bool V_116 )
{
struct V_42 * V_43 ;
T_4 * V_58 ;
struct V_56 * V_57 ;
V_43 = F_80 ( V_35 , V_115 , V_116 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_83 ( sizeof( * V_43 ) , V_118 ) ;
if ( ! V_43 )
return NULL ;
F_23 ( & V_43 -> V_57 ) ;
F_84 ( & V_43 -> V_44 ) ;
F_85 ( V_43 -> V_61 , V_35 -> V_15 ) ;
F_86 ( & V_115 -> V_44 ) ;
V_43 -> V_35 = V_115 ;
if ( V_116 ) {
V_58 = & V_115 -> V_38 ;
V_57 = & V_115 -> V_36 ;
} else {
V_58 = & V_115 -> V_39 ;
V_57 = & V_115 -> V_37 ;
}
F_44 ( V_60 , V_5 , L_4 ,
V_43 -> V_61 , V_43 -> V_35 -> V_15 ) ;
F_42 ( V_58 ) ;
F_86 ( & V_43 -> V_44 ) ;
F_87 ( & V_43 -> V_57 , V_57 ) ;
F_46 ( V_58 ) ;
return V_43 ;
}
void F_88 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_115 ,
struct V_104 * V_105 ,
int V_119 )
{
struct V_42 * V_120 = NULL ;
struct V_42 * V_121 = NULL ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_94;
if ( ! F_89 ( V_20 , & V_35 -> V_21 ) )
goto V_94;
if ( ! F_76 ( V_5 , V_35 , V_105 ) &&
! V_119 )
goto V_94;
V_120 = F_82 ( V_5 , V_35 ,
V_115 , true ) ;
if ( ! V_120 )
goto V_94;
V_120 -> V_53 = V_23 ;
V_121 = F_82 ( V_5 , V_115 ,
V_35 , false ) ;
if ( ! V_121 )
goto V_94;
V_121 -> V_53 = V_23 ;
V_94:
if ( V_120 )
F_29 ( V_120 ) ;
if ( V_121 )
F_29 ( V_121 ) ;
}
static struct V_46 * F_90 ( struct V_4 * V_5 ,
struct V_62 * V_63 ,
T_2 * V_80 ,
T_2 * V_81 )
{
int V_122 ;
struct V_46 * V_47 , V_123 ;
F_58 ( & V_123 , V_80 , V_81 ) ;
V_47 = F_63 ( V_63 , ( void * ) & V_123 ) ;
if ( V_47 ) {
V_47 -> V_55 = V_23 ;
return V_47 ;
}
V_47 = F_83 ( sizeof( * V_47 ) , V_118 ) ;
if ( ! V_47 )
return NULL ;
F_23 ( & V_47 -> V_73 ) ;
F_24 ( & V_47 -> V_92 ) ;
F_84 ( & V_47 -> V_44 ) ;
V_47 -> V_55 = V_23 ;
F_85 ( V_47 -> V_77 , V_81 ) ;
F_85 ( V_47 -> V_76 , V_80 ) ;
F_44 ( V_60 , V_5 , L_5 ,
V_47 -> V_76 ,
V_47 -> V_77 ) ;
F_86 ( & V_47 -> V_44 ) ;
V_122 = F_91 ( V_63 , F_61 ,
F_59 , & V_123 ,
& V_47 -> V_78 ) ;
if ( V_122 < 0 ) {
F_35 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
static T_2 F_92 ( T_2 V_114 )
{
T_2 V_124 , V_125 ;
F_93 ( & V_124 , sizeof( V_124 ) ) ;
V_125 = V_124 * ( V_126 - V_114 ) ;
V_125 /= V_126 ;
return V_126 - V_125 ;
}
static void F_94 ( char * V_81 , const char * V_80 , unsigned int V_97 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_97 ; ++ V_67 )
V_81 [ V_67 ] ^= V_80 [ V_67 ] ;
}
static bool F_95 ( struct V_4 * V_5 ,
struct V_127 * V_50 ,
struct V_128 * V_128 ,
struct V_48 * V_49 ,
struct V_129 * V_89 )
{
T_2 V_130 , V_131 , V_132 ;
struct V_127 * V_133 , * V_134 ;
struct V_135 * V_136 ;
struct V_135 * V_137 ;
struct V_138 * V_139 ;
struct V_129 * V_140 , * V_141 , * V_142 ;
struct V_129 * V_143 = NULL , * V_144 ;
struct V_145 * V_146 = NULL ;
struct V_145 * V_147 = NULL ;
T_2 * V_148 , * V_149 ;
T_6 V_150 , V_151 ;
T_7 V_152 ;
bool V_91 = false ;
int V_153 ;
int V_154 = sizeof( * V_136 ) ;
int V_155 = sizeof( * V_139 ) ;
int V_156 = V_155 - V_154 ;
V_141 = F_96 ( V_89 -> V_35 ,
V_110 ) ;
if ( ! V_141 )
goto V_94;
V_146 = F_97 ( V_141 ,
V_110 ) ;
if ( ! V_146 )
goto V_94;
V_140 = V_49 -> V_89 ;
V_143 = F_96 ( V_140 -> V_35 ,
V_110 ) ;
if ( ! V_143 )
goto V_94;
V_147 = F_97 ( V_143 ,
V_110 ) ;
if ( ! V_147 )
goto V_94;
V_132 = V_146 -> V_157 . V_158 ;
V_130 = F_92 ( V_132 ) ;
V_132 = V_147 -> V_157 . V_158 ;
V_131 = F_92 ( V_132 ) ;
if ( V_130 >= V_131 ) {
V_142 = V_49 -> V_89 ;
V_148 = V_49 -> V_47 -> V_76 ;
V_144 = V_89 ;
V_149 = V_128 -> V_159 ;
V_136 = (struct V_135 * ) V_49 -> V_50 -> V_82 ;
V_137 = (struct V_135 * ) V_50 -> V_82 ;
V_150 = V_49 -> V_160 ;
V_151 = F_98 ( V_50 ,
V_50 -> V_82 + sizeof( * V_137 ) ) ;
} else {
V_142 = V_89 ;
V_148 = V_128 -> V_159 ;
V_144 = V_49 -> V_89 ;
V_149 = V_49 -> V_47 -> V_76 ;
V_136 = (struct V_135 * ) V_50 -> V_82 ;
V_137 = (struct V_135 * ) V_49 -> V_50 -> V_82 ;
V_150 = F_98 ( V_50 ,
V_50 -> V_82 + sizeof( * V_136 ) ) ;
V_151 = V_49 -> V_160 ;
}
if ( V_50 -> V_97 <= V_49 -> V_50 -> V_97 ) {
V_133 = V_49 -> V_50 ;
V_134 = V_50 ;
} else {
V_133 = V_50 ;
V_134 = V_49 -> V_50 ;
}
V_153 = V_134 -> V_97 - V_154 ;
if ( F_99 ( V_133 ) < 0 || F_99 ( V_134 ) < 0 )
goto V_94;
F_100 ( V_133 , V_156 ) ;
V_139 = (struct V_138 * ) V_133 -> V_82 ;
F_101 ( V_133 ) ;
V_139 -> V_161 = V_2 ;
V_139 -> V_162 = V_163 ;
V_139 -> V_112 = V_136 -> V_112 ;
F_85 ( V_139 -> V_148 , V_148 ) ;
F_85 ( V_139 -> V_164 , V_136 -> V_165 ) ;
V_139 -> V_166 = V_150 ;
V_139 -> V_167 = V_136 -> V_168 ;
F_85 ( V_139 -> V_144 , V_144 -> V_61 ) ;
F_85 ( V_139 -> V_149 , V_149 ) ;
F_85 ( V_139 -> V_169 , V_137 -> V_165 ) ;
V_139 -> V_170 = V_151 ;
V_139 -> V_171 = V_137 -> V_112 ;
V_139 -> V_172 = V_137 -> V_168 ;
V_139 -> V_173 = F_102 ( V_153 ) ;
F_94 ( V_133 -> V_82 + V_155 ,
V_134 -> V_82 + V_154 , V_153 ) ;
if ( F_103 ( V_134 ) -> V_174 &&
F_103 ( V_133 ) -> V_174 ) {
V_152 = V_134 -> V_97 + V_98 ;
V_152 += V_133 -> V_97 + V_98 ;
F_72 ( V_5 , V_175 , 2 ) ;
F_72 ( V_5 , V_176 , V_152 ) ;
} else if ( ! F_103 ( V_134 ) -> V_174 &&
! F_103 ( V_133 ) -> V_174 ) {
V_152 = V_134 -> V_97 + V_98 ;
V_152 += V_133 -> V_97 + V_98 ;
F_72 ( V_5 , V_177 , 2 ) ;
F_72 ( V_5 , V_178 , V_152 ) ;
} else if ( F_103 ( V_134 ) -> V_174 &&
! F_103 ( V_133 ) -> V_174 ) {
F_71 ( V_5 , V_175 ) ;
F_72 ( V_5 , V_176 ,
V_134 -> V_97 + V_98 ) ;
F_71 ( V_5 , V_177 ) ;
F_72 ( V_5 , V_178 ,
V_133 -> V_97 + V_98 ) ;
} else if ( ! F_103 ( V_134 ) -> V_174 &&
F_103 ( V_133 ) -> V_174 ) {
F_71 ( V_5 , V_177 ) ;
F_72 ( V_5 , V_178 ,
V_134 -> V_97 + V_98 ) ;
F_71 ( V_5 , V_175 ) ;
F_72 ( V_5 , V_176 ,
V_133 -> V_97 + V_98 ) ;
}
F_34 ( V_134 ) ;
V_49 -> V_50 = NULL ;
F_33 ( V_49 ) ;
F_66 ( V_133 , V_142 ) ;
V_91 = true ;
V_94:
if ( V_141 )
F_104 ( V_141 ) ;
if ( V_143 )
F_104 ( V_143 ) ;
if ( V_146 )
F_105 ( V_146 ) ;
if ( V_147 )
F_105 ( V_147 ) ;
return V_91 ;
}
static bool F_106 ( struct V_127 * V_50 , T_2 * V_81 , T_2 * V_80 )
{
if ( F_103 ( V_50 ) -> V_174 && ! F_62 ( V_81 , V_80 ) )
return false ;
return true ;
}
static struct V_48 *
F_107 ( struct V_4 * V_5 ,
struct V_42 * V_120 ,
struct V_42 * V_121 ,
struct V_127 * V_50 ,
T_2 * V_179 )
{
struct V_46 * V_47 , V_123 ;
struct V_48 * V_180 = NULL ;
struct V_48 * V_49 , * V_99 ;
struct V_62 * V_63 = V_5 -> V_7 . V_25 ;
int V_181 ;
if ( ! V_63 )
return NULL ;
F_58 ( & V_123 , V_120 -> V_61 ,
V_121 -> V_61 ) ;
V_181 = F_59 ( & V_123 , V_63 -> V_68 ) ;
F_49 () ;
F_50 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_62 ( V_47 -> V_76 , V_120 -> V_61 ) )
continue;
if ( ! F_62 ( V_47 -> V_77 , V_121 -> V_61 ) )
continue;
F_42 ( & V_47 -> V_92 ) ;
if ( F_55 ( & V_47 -> V_73 ) ) {
F_46 ( & V_47 -> V_92 ) ;
continue;
}
F_43 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_106 ( V_49 -> V_50 ,
V_179 ,
V_120 -> V_61 ) )
continue;
F_69 ( & V_49 -> V_57 ) ;
V_180 = V_49 ;
break;
}
F_46 ( & V_47 -> V_92 ) ;
break;
}
F_51 () ;
return V_180 ;
}
static struct V_48 *
F_108 ( struct V_4 * V_5 ,
struct V_127 * V_50 ,
T_2 * V_179 ,
T_2 * V_182 ,
struct V_42 * V_120 )
{
struct V_14 * V_35 ;
struct V_42 * V_121 ;
struct V_48 * V_49 = NULL ;
V_35 = F_109 ( V_5 , V_182 ) ;
if ( ! V_35 )
return NULL ;
F_49 () ;
F_81 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_106 ( V_50 ,
V_121 -> V_61 , V_182 ) )
continue;
V_49 = F_107 ( V_5 , V_120 ,
V_121 , V_50 , V_179 ) ;
if ( V_49 )
break;
}
F_51 () ;
F_27 ( V_35 ) ;
return V_49 ;
}
static void F_110 ( struct V_4 * V_5 ,
struct V_127 * V_50 ,
T_2 * V_183 )
{
struct V_128 * V_128 ;
V_50 = F_111 ( V_50 , V_118 ) ;
if ( ! V_50 )
return;
V_128 = F_112 ( V_50 ) ;
F_85 ( V_128 -> V_159 , V_128 -> V_184 ) ;
F_85 ( V_128 -> V_184 , V_183 ) ;
F_100 ( V_50 , V_98 ) ;
F_113 ( V_5 , V_50 ) ;
F_34 ( V_50 ) ;
}
static bool F_114 ( struct V_127 * V_50 ,
struct V_129 * V_89 ,
struct V_128 * V_128 )
{
struct V_12 * V_185 = V_89 -> V_186 -> V_187 ;
struct V_4 * V_5 = F_11 ( V_185 ) ;
struct V_14 * V_35 = V_89 -> V_35 ;
struct V_42 * V_43 ;
struct V_48 * V_49 = NULL ;
F_49 () ;
F_81 (nc_node, &orig_node->in_coding_list, list) {
V_49 = F_108 ( V_5 , V_50 ,
V_89 -> V_61 ,
V_128 -> V_159 , V_43 ) ;
if ( V_49 )
break;
}
F_51 () ;
if ( ! V_49 )
return false ;
F_110 ( V_5 , V_50 ,
V_89 -> V_61 ) ;
F_110 ( V_5 , V_49 -> V_50 ,
V_49 -> V_89 -> V_61 ) ;
if ( F_95 ( V_5 , V_50 , V_128 , V_49 ,
V_89 ) )
return true ;
F_65 ( V_49 ) ;
return false ;
}
static bool F_115 ( struct V_127 * V_50 ,
struct V_46 * V_47 ,
struct V_129 * V_89 ,
T_6 V_160 )
{
struct V_48 * V_49 ;
V_49 = F_83 ( sizeof( * V_49 ) , V_118 ) ;
if ( ! V_49 )
return false ;
V_49 -> V_93 = V_23 ;
V_49 -> V_160 = V_160 ;
V_49 -> V_50 = V_50 ;
V_49 -> V_89 = V_89 ;
V_49 -> V_47 = V_47 ;
F_42 ( & V_47 -> V_92 ) ;
F_116 ( & V_49 -> V_57 , & V_47 -> V_73 ) ;
F_46 ( & V_47 -> V_92 ) ;
return true ;
}
bool F_117 ( struct V_127 * V_50 ,
struct V_129 * V_89 )
{
const struct V_12 * V_185 = V_89 -> V_186 -> V_187 ;
struct V_4 * V_5 = F_11 ( V_185 ) ;
struct V_135 * V_188 ;
struct V_46 * V_47 ;
struct V_128 * V_128 = F_112 ( V_50 ) ;
T_6 V_160 ;
T_2 * V_189 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_94;
V_189 = F_118 ( V_50 ) ;
V_188 = (struct V_135 * ) V_189 ;
if ( V_188 -> V_161 != V_190 )
goto V_94;
if ( F_114 ( V_50 , V_89 , V_128 ) )
return true ;
V_47 = F_90 ( V_5 ,
V_5 -> V_7 . V_25 ,
V_128 -> V_159 ,
V_89 -> V_61 ) ;
if ( ! V_47 )
goto V_94;
V_160 = F_98 ( V_50 , V_189 + sizeof( * V_188 ) ) ;
if ( ! F_115 ( V_50 , V_47 , V_89 , V_160 ) )
goto V_191;
return true ;
V_191:
F_32 ( V_47 ) ;
V_94:
return false ;
}
void F_113 ( struct V_4 * V_5 ,
struct V_127 * V_50 )
{
struct V_135 * V_188 ;
struct V_46 * V_47 ;
struct V_128 * V_128 = F_112 ( V_50 ) ;
T_6 V_160 ;
T_2 * V_189 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_94;
V_189 = F_118 ( V_50 ) ;
V_188 = (struct V_135 * ) V_189 ;
if ( V_188 -> V_161 != V_190 )
goto V_94;
V_47 = F_90 ( V_5 ,
V_5 -> V_7 . V_26 ,
V_128 -> V_159 ,
V_128 -> V_184 ) ;
if ( ! V_47 )
goto V_94;
V_50 = F_119 ( V_50 , V_118 ) ;
if ( F_54 ( ! V_50 ) )
goto V_191;
if ( F_54 ( ! F_120 ( V_50 , V_98 ) ) )
goto V_192;
if ( F_54 ( ! F_121 ( V_50 , V_98 ) ) )
goto V_192;
V_160 = F_98 ( V_50 , V_189 + sizeof( * V_188 ) ) ;
if ( ! F_115 ( V_50 , V_47 , NULL , V_160 ) )
goto V_192;
F_71 ( V_5 , V_193 ) ;
return;
V_192:
F_34 ( V_50 ) ;
V_191:
F_32 ( V_47 ) ;
V_94:
return;
}
void F_122 ( struct V_4 * V_5 ,
struct V_127 * V_50 )
{
struct V_128 * V_128 = F_112 ( V_50 ) ;
if ( F_123 ( V_5 , V_128 -> V_184 ) )
return;
F_100 ( V_50 , V_98 ) ;
F_113 ( V_5 , V_50 ) ;
}
static struct V_135 *
F_124 ( struct V_4 * V_5 , struct V_127 * V_50 ,
struct V_48 * V_49 )
{
const int V_194 = sizeof( struct V_135 ) ;
const int V_195 = sizeof( struct V_138 ) - V_194 ;
struct V_135 * V_196 ;
struct V_138 V_197 ;
struct V_128 * V_128 , V_198 ;
T_2 * V_199 , V_112 , V_168 ;
unsigned int V_153 ;
int V_27 ;
memcpy ( & V_197 , V_50 -> V_82 , sizeof( V_197 ) ) ;
memcpy ( & V_198 , F_125 ( V_50 ) , sizeof( V_198 ) ) ;
if ( F_126 ( V_50 , 0 ) < 0 )
return NULL ;
if ( F_54 ( ! F_121 ( V_50 , V_195 ) ) )
return NULL ;
F_127 ( V_50 , - V_98 ) ;
F_128 ( V_50 ) ;
V_128 = F_112 ( V_50 ) ;
* V_128 = V_198 ;
if ( F_123 ( V_5 , V_197 . V_144 ) ) {
F_85 ( V_128 -> V_184 , V_197 . V_144 ) ;
V_50 -> V_200 = V_201 ;
V_199 = V_197 . V_169 ;
V_112 = V_197 . V_171 ;
V_168 = V_197 . V_172 ;
} else {
V_199 = V_197 . V_164 ;
V_112 = V_197 . V_112 ;
V_168 = V_197 . V_167 ;
}
V_153 = F_129 ( V_197 . V_173 ) ;
if ( V_153 > V_50 -> V_97 )
return NULL ;
F_94 ( V_50 -> V_82 + V_194 ,
V_49 -> V_50 -> V_82 + V_194 ,
V_153 ) ;
if ( V_49 -> V_50 -> V_97 > V_153 + V_194 ) {
V_27 = F_130 ( V_50 , V_153 + V_194 ) ;
if ( V_27 )
return NULL ;
}
V_196 = (struct V_135 * ) V_50 -> V_82 ;
V_196 -> V_161 = V_190 ;
V_196 -> V_162 = V_163 ;
V_196 -> V_112 = V_112 ;
F_85 ( V_196 -> V_165 , V_199 ) ;
V_196 -> V_168 = V_168 ;
F_33 ( V_49 ) ;
return V_196 ;
}
static struct V_48 *
F_131 ( struct V_4 * V_5 ,
struct V_128 * V_128 ,
struct V_138 * V_202 )
{
struct V_62 * V_63 = V_5 -> V_7 . V_26 ;
struct V_48 * V_203 , * V_49 = NULL ;
struct V_46 * V_47 , V_123 ;
T_2 * V_165 , * V_204 ;
T_6 V_160 ;
int V_88 ;
if ( ! V_63 )
return NULL ;
V_165 = V_128 -> V_159 ;
if ( ! F_123 ( V_5 , V_202 -> V_144 ) ) {
V_204 = V_202 -> V_149 ;
V_160 = V_202 -> V_170 ;
} else {
V_204 = V_202 -> V_148 ;
V_160 = V_202 -> V_166 ;
}
F_58 ( & V_123 , V_204 , V_165 ) ;
V_88 = F_59 ( & V_123 , V_63 -> V_68 ) ;
F_49 () ;
F_50 (nc_path, &hash->table[index], hash_entry) {
F_42 ( & V_47 -> V_92 ) ;
F_132 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_160 == V_203 -> V_160 ) {
F_69 ( & V_203 -> V_57 ) ;
V_49 = V_203 ;
break;
}
}
F_46 ( & V_47 -> V_92 ) ;
if ( V_49 )
break;
}
F_51 () ;
if ( ! V_49 )
F_44 ( V_60 , V_5 ,
L_6 , V_160 ) ;
return V_49 ;
}
static int V_3 ( struct V_127 * V_50 ,
struct V_205 * V_206 )
{
struct V_4 * V_5 = F_11 ( V_206 -> V_187 ) ;
struct V_135 * V_196 ;
struct V_138 * V_139 ;
struct V_48 * V_49 ;
struct V_128 * V_128 ;
int V_207 = sizeof( * V_139 ) ;
if ( ! F_7 ( & V_5 -> V_10 ) )
return V_208 ;
if ( F_54 ( ! F_120 ( V_50 , V_207 ) ) )
return V_208 ;
V_139 = (struct V_138 * ) V_50 -> V_82 ;
V_128 = F_112 ( V_50 ) ;
if ( ! F_123 ( V_5 , V_128 -> V_184 ) &&
! F_123 ( V_5 , V_139 -> V_144 ) )
return V_208 ;
if ( F_123 ( V_5 , V_139 -> V_144 ) )
F_71 ( V_5 , V_209 ) ;
V_49 = F_131 ( V_5 , V_128 ,
V_139 ) ;
if ( ! V_49 ) {
F_71 ( V_5 , V_210 ) ;
return V_208 ;
}
if ( F_99 ( V_50 ) < 0 )
goto V_211;
if ( F_99 ( V_49 -> V_50 ) < 0 )
goto V_211;
V_196 = F_124 ( V_5 , V_50 , V_49 ) ;
if ( ! V_196 ) {
F_71 ( V_5 , V_210 ) ;
goto V_211;
}
F_103 ( V_50 ) -> V_174 = true ;
F_71 ( V_5 , V_212 ) ;
F_72 ( V_5 , V_213 ,
V_50 -> V_97 + V_98 ) ;
return F_133 ( V_50 , V_206 ) ;
V_211:
F_33 ( V_49 ) ;
return V_208 ;
}
void F_134 ( struct V_4 * V_5 )
{
F_8 ( V_5 , V_11 , 1 ) ;
F_135 ( V_5 , V_11 , 1 ) ;
F_136 ( & V_5 -> V_7 . V_8 ) ;
F_52 ( V_5 , V_5 -> V_7 . V_25 , NULL ) ;
F_137 ( V_5 -> V_7 . V_25 ) ;
F_52 ( V_5 , V_5 -> V_7 . V_26 , NULL ) ;
F_137 ( V_5 -> V_7 . V_26 ) ;
}
int F_138 ( struct V_214 * V_215 , void * V_216 )
{
struct V_12 * V_13 = (struct V_12 * ) V_215 -> V_217 ;
struct V_4 * V_5 = F_11 ( V_13 ) ;
struct V_62 * V_63 = V_5 -> V_64 ;
struct V_205 * V_218 ;
struct V_65 * V_66 ;
struct V_14 * V_35 ;
struct V_42 * V_43 ;
int V_67 ;
V_218 = F_139 ( V_215 ) ;
if ( ! V_218 )
goto V_94;
for ( V_67 = 0 ; V_67 < V_63 -> V_68 ; V_67 ++ ) {
V_66 = & V_63 -> V_69 [ V_67 ] ;
F_49 () ;
F_50 (orig_node, head, hash_entry) {
if ( F_55 ( & V_35 -> V_36 ) &&
F_55 ( & V_35 -> V_37 ) )
continue;
F_140 ( V_215 , L_7 , V_35 -> V_15 ) ;
F_141 ( V_215 , L_8 ) ;
F_81 (nc_node,
&orig_node->in_coding_list,
list)
F_140 ( V_215 , L_9 ,
V_43 -> V_61 ) ;
F_141 ( V_215 , L_10 ) ;
F_141 ( V_215 , L_11 ) ;
F_81 (nc_node,
&orig_node->out_coding_list,
list)
F_140 ( V_215 , L_9 ,
V_43 -> V_61 ) ;
F_141 ( V_215 , L_12 ) ;
}
F_51 () ;
}
V_94:
if ( V_218 )
F_142 ( V_218 ) ;
return 0 ;
}
int F_143 ( struct V_4 * V_5 )
{
struct V_219 * V_220 , * V_221 ;
V_220 = F_144 ( L_13 , V_5 -> V_222 ) ;
if ( ! V_220 )
goto V_94;
V_221 = F_145 ( L_14 , V_223 | V_224 , V_220 ,
& V_5 -> V_7 . V_32 ) ;
if ( ! V_221 )
goto V_94;
V_221 = F_146 ( L_15 , V_223 | V_224 , V_220 ,
& V_5 -> V_7 . V_33 ) ;
if ( ! V_221 )
goto V_94;
V_221 = F_146 ( L_16 , V_223 | V_224 , V_220 ,
& V_5 -> V_7 . V_34 ) ;
if ( ! V_221 )
goto V_94;
return 0 ;
V_94:
return - V_31 ;
}
