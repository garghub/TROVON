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
static void F_33 ( struct V_48 * V_49 ,
bool V_50 )
{
if ( V_50 )
F_34 ( V_49 -> V_51 ) ;
else
F_35 ( V_49 -> V_51 ) ;
F_32 ( V_49 -> V_47 ) ;
F_36 ( V_49 ) ;
}
static bool F_37 ( struct V_4 * V_5 ,
struct V_42 * V_43 )
{
if ( F_7 ( & V_5 -> V_52 ) != V_53 )
return true ;
return F_38 ( V_43 -> V_54 , V_55 ) ;
}
static bool F_39 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
if ( F_7 ( & V_5 -> V_52 ) != V_53 )
return true ;
return F_38 ( V_47 -> V_56 ,
V_5 -> V_7 . V_33 * 10 ) ;
}
static bool F_40 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
if ( F_7 ( & V_5 -> V_52 ) != V_53 )
return true ;
return F_38 ( V_47 -> V_56 ,
V_5 -> V_7 . V_34 * 10 ) ;
}
static void
F_41 ( struct V_4 * V_5 ,
struct V_57 * V_58 ,
T_4 * V_59 ,
bool (* F_42)( struct V_4 * ,
struct V_42 * ) )
{
struct V_42 * V_43 , * V_60 ;
F_43 ( V_59 ) ;
F_44 (nc_node, nc_node_tmp, list, list) {
if ( F_42 && ! F_42 ( V_5 , V_43 ) )
continue;
F_45 ( V_61 , V_5 ,
L_1 ,
V_43 -> V_62 , V_43 -> V_35 -> V_15 ) ;
F_46 ( & V_43 -> V_58 ) ;
F_29 ( V_43 ) ;
}
F_47 ( V_59 ) ;
}
void F_48 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
bool (* F_42)( struct V_4 * ,
struct V_42 * ) )
{
F_41 ( V_5 , & V_35 -> V_36 ,
& V_35 -> V_38 ,
F_42 ) ;
F_41 ( V_5 , & V_35 -> V_37 ,
& V_35 -> V_39 ,
F_42 ) ;
}
static void F_49 ( struct V_4 * V_5 )
{
struct V_63 * V_64 = V_5 -> V_65 ;
struct V_66 * V_67 ;
struct V_14 * V_35 ;
T_5 V_68 ;
if ( ! V_64 )
return;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_67 = & V_64 -> V_70 [ V_68 ] ;
F_50 () ;
F_51 (orig_node, head, hash_entry)
F_48 ( V_5 , V_35 ,
F_37 ) ;
F_52 () ;
}
}
static void F_53 ( struct V_4 * V_5 ,
struct V_63 * V_64 ,
bool (* F_42)( struct V_4 * ,
struct V_46 * ) )
{
struct V_66 * V_67 ;
struct V_71 * V_72 ;
struct V_46 * V_47 ;
T_4 * V_59 ;
T_5 V_68 ;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_67 = & V_64 -> V_70 [ V_68 ] ;
V_59 = & V_64 -> V_73 [ V_68 ] ;
F_43 ( V_59 ) ;
F_54 (nc_path, node_tmp, head, hash_entry) {
if ( F_42 && ! F_42 ( V_5 , V_47 ) )
continue;
if ( ! F_55 ( F_56 ( & V_47 -> V_74 ) ) ) {
F_57 ( V_75 ,
V_76
L_2 ,
V_47 -> V_77 ,
V_47 -> V_78 ) ;
continue;
}
F_45 ( V_61 , V_5 ,
L_3 ,
V_47 -> V_77 , V_47 -> V_78 ) ;
F_58 ( & V_47 -> V_79 ) ;
F_32 ( V_47 ) ;
}
F_47 ( V_59 ) ;
}
}
static void F_59 ( struct V_46 * V_80 , const char * V_81 ,
const char * V_82 )
{
memcpy ( V_80 -> V_77 , V_81 , sizeof( V_80 -> V_77 ) ) ;
memcpy ( V_80 -> V_78 , V_82 , sizeof( V_80 -> V_78 ) ) ;
}
static T_5 F_60 ( const void * V_83 , T_5 V_69 )
{
const struct V_46 * V_47 = V_83 ;
T_5 V_64 = 0 ;
V_64 = F_61 ( & V_47 -> V_77 , sizeof( V_47 -> V_77 ) , V_64 ) ;
V_64 = F_61 ( & V_47 -> V_78 , sizeof( V_47 -> V_78 ) , V_64 ) ;
return V_64 % V_69 ;
}
static bool F_62 ( const struct V_71 * V_84 ,
const void * V_85 )
{
const struct V_46 * V_86 , * V_87 ;
V_86 = F_26 ( V_84 , struct V_46 , V_79 ) ;
V_87 = V_85 ;
if ( ! F_63 ( V_86 -> V_77 , V_87 -> V_77 ) )
return false ;
if ( ! F_63 ( V_86 -> V_78 , V_87 -> V_78 ) )
return false ;
return true ;
}
static struct V_46 *
F_64 ( struct V_63 * V_64 ,
void * V_83 )
{
struct V_66 * V_67 ;
struct V_46 * V_47 , * V_88 = NULL ;
int V_89 ;
if ( ! V_64 )
return NULL ;
V_89 = F_60 ( V_83 , V_64 -> V_69 ) ;
V_67 = & V_64 -> V_70 [ V_89 ] ;
F_50 () ;
F_51 (nc_path, head, hash_entry) {
if ( ! F_62 ( & V_47 -> V_79 , V_83 ) )
continue;
if ( ! F_65 ( & V_47 -> V_44 ) )
continue;
V_88 = V_47 ;
break;
}
F_52 () ;
return V_88 ;
}
static void F_66 ( struct V_48 * V_49 )
{
F_67 ( V_49 -> V_51 , V_49 -> V_90 ) ;
V_49 -> V_51 = NULL ;
F_33 ( V_49 , false ) ;
}
static bool F_68 ( struct V_4 * V_5 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
unsigned long V_91 = V_5 -> V_7 . V_34 ;
bool V_92 = false ;
F_69 ( & V_47 -> V_93 ) ;
if ( F_7 ( & V_5 -> V_52 ) == V_53 &&
! F_38 ( V_49 -> V_94 , V_91 ) )
goto V_95;
F_70 ( & V_49 -> V_58 ) ;
F_33 ( V_49 , true ) ;
V_92 = true ;
V_95:
return V_92 ;
}
static bool F_71 ( struct V_4 * V_5 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
unsigned long V_91 = V_5 -> V_7 . V_33 ;
F_69 ( & V_47 -> V_93 ) ;
if ( F_7 ( & V_5 -> V_52 ) == V_53 &&
! F_38 ( V_49 -> V_94 , V_91 ) )
return false ;
F_72 ( V_5 , V_96 ) ;
F_73 ( V_5 , V_97 ,
V_49 -> V_51 -> V_98 + V_99 ) ;
F_70 ( & V_49 -> V_58 ) ;
F_66 ( V_49 ) ;
return true ;
}
static void
F_74 ( struct V_4 * V_5 ,
struct V_63 * V_64 ,
bool (* F_75)( struct V_4 * ,
struct V_46 * ,
struct V_48 * ) )
{
struct V_66 * V_67 ;
struct V_48 * V_49 , * V_100 ;
struct V_46 * V_47 ;
bool V_1 ;
int V_68 ;
if ( ! V_64 )
return;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_67 = & V_64 -> V_70 [ V_68 ] ;
F_50 () ;
F_51 (nc_path, head, hash_entry) {
F_43 ( & V_47 -> V_93 ) ;
F_44 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_1 = F_75 ( V_5 , V_47 , V_49 ) ;
if ( ! V_1 )
break;
}
F_47 ( & V_47 -> V_93 ) ;
}
F_52 () ;
}
}
static void V_30 ( struct V_101 * V_8 )
{
struct V_102 * V_102 ;
struct V_103 * V_104 ;
struct V_4 * V_5 ;
unsigned long V_91 ;
V_102 = F_76 ( V_8 ) ;
V_104 = F_26 ( V_102 , struct V_103 , V_8 ) ;
V_5 = F_26 ( V_104 , struct V_4 , V_7 ) ;
F_49 ( V_5 ) ;
F_53 ( V_5 , V_5 -> V_7 . V_25 ,
F_39 ) ;
F_53 ( V_5 , V_5 -> V_7 . V_26 ,
F_40 ) ;
V_91 = V_5 -> V_7 . V_33 ;
if ( F_38 ( V_5 -> V_7 . V_22 , V_91 ) ) {
F_74 ( V_5 , V_5 -> V_7 . V_25 ,
F_71 ) ;
V_5 -> V_7 . V_22 = V_23 ;
}
if ( F_38 ( V_5 -> V_7 . V_24 ,
V_5 -> V_7 . V_34 ) ) {
F_74 ( V_5 , V_5 -> V_7 . V_26 ,
F_68 ) ;
V_5 -> V_7 . V_24 = V_23 ;
}
F_3 ( V_5 ) ;
}
static bool F_77 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
T_5 V_109 ;
T_2 V_110 ;
V_108 = F_78 ( V_35 , V_111 ) ;
if ( ! V_108 )
return false ;
V_110 = V_108 -> V_110 ;
V_109 = V_108 -> V_109 ;
F_79 ( V_108 ) ;
if ( V_109 != F_80 ( V_106 -> V_112 ) )
return false ;
if ( V_110 != V_106 -> V_113 + 1 )
return false ;
if ( ! F_63 ( V_106 -> V_15 , V_106 -> V_114 ) )
return false ;
if ( V_106 -> V_115 < V_5 -> V_7 . V_32 )
return false ;
return true ;
}
static struct V_42 *
F_81 ( struct V_14 * V_35 ,
struct V_14 * V_116 ,
bool V_117 )
{
struct V_42 * V_43 , * V_118 = NULL ;
struct V_57 * V_58 ;
if ( V_117 )
V_58 = & V_116 -> V_36 ;
else
V_58 = & V_116 -> V_37 ;
F_50 () ;
F_82 (nc_node, list, list) {
if ( ! F_63 ( V_43 -> V_62 , V_35 -> V_15 ) )
continue;
if ( ! F_65 ( & V_43 -> V_44 ) )
continue;
V_118 = V_43 ;
break;
}
F_52 () ;
return V_118 ;
}
static struct V_42 *
F_83 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_116 ,
bool V_117 )
{
struct V_42 * V_43 ;
T_4 * V_59 ;
struct V_57 * V_58 ;
V_43 = F_81 ( V_35 , V_116 , V_117 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_84 ( sizeof( * V_43 ) , V_119 ) ;
if ( ! V_43 )
return NULL ;
F_23 ( & V_43 -> V_58 ) ;
F_85 ( & V_43 -> V_44 ) ;
F_86 ( V_43 -> V_62 , V_35 -> V_15 ) ;
F_87 ( & V_116 -> V_44 ) ;
V_43 -> V_35 = V_116 ;
if ( V_117 ) {
V_59 = & V_116 -> V_38 ;
V_58 = & V_116 -> V_36 ;
} else {
V_59 = & V_116 -> V_39 ;
V_58 = & V_116 -> V_37 ;
}
F_45 ( V_61 , V_5 , L_4 ,
V_43 -> V_62 , V_43 -> V_35 -> V_15 ) ;
F_43 ( V_59 ) ;
F_87 ( & V_43 -> V_44 ) ;
F_88 ( & V_43 -> V_58 , V_58 ) ;
F_47 ( V_59 ) ;
return V_43 ;
}
void F_89 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_116 ,
struct V_105 * V_106 ,
int V_120 )
{
struct V_42 * V_121 = NULL ;
struct V_42 * V_122 = NULL ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_95;
if ( ! F_90 ( V_20 , & V_35 -> V_21 ) )
goto V_95;
if ( ! F_77 ( V_5 , V_35 , V_106 ) &&
! V_120 )
goto V_95;
V_121 = F_83 ( V_5 , V_35 ,
V_116 , true ) ;
if ( ! V_121 )
goto V_95;
V_121 -> V_54 = V_23 ;
V_122 = F_83 ( V_5 , V_116 ,
V_35 , false ) ;
if ( ! V_122 )
goto V_95;
V_122 -> V_54 = V_23 ;
V_95:
if ( V_121 )
F_29 ( V_121 ) ;
if ( V_122 )
F_29 ( V_122 ) ;
}
static struct V_46 * F_91 ( struct V_4 * V_5 ,
struct V_63 * V_64 ,
T_2 * V_81 ,
T_2 * V_82 )
{
int V_123 ;
struct V_46 * V_47 , V_124 ;
F_59 ( & V_124 , V_81 , V_82 ) ;
V_47 = F_64 ( V_64 , ( void * ) & V_124 ) ;
if ( V_47 ) {
V_47 -> V_56 = V_23 ;
return V_47 ;
}
V_47 = F_84 ( sizeof( * V_47 ) , V_119 ) ;
if ( ! V_47 )
return NULL ;
F_23 ( & V_47 -> V_74 ) ;
F_24 ( & V_47 -> V_93 ) ;
F_85 ( & V_47 -> V_44 ) ;
V_47 -> V_56 = V_23 ;
F_86 ( V_47 -> V_78 , V_82 ) ;
F_86 ( V_47 -> V_77 , V_81 ) ;
F_45 ( V_61 , V_5 , L_5 ,
V_47 -> V_77 ,
V_47 -> V_78 ) ;
F_87 ( & V_47 -> V_44 ) ;
V_123 = F_92 ( V_64 , F_62 ,
F_60 , & V_124 ,
& V_47 -> V_79 ) ;
if ( V_123 < 0 ) {
F_36 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
static T_2 F_93 ( T_2 V_115 )
{
T_2 V_125 , V_126 ;
F_94 ( & V_125 , sizeof( V_125 ) ) ;
V_126 = V_125 * ( V_127 - V_115 ) ;
V_126 /= V_127 ;
return V_127 - V_126 ;
}
static void F_95 ( char * V_82 , const char * V_81 , unsigned int V_98 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_98 ; ++ V_68 )
V_82 [ V_68 ] ^= V_81 [ V_68 ] ;
}
static bool F_96 ( struct V_4 * V_5 ,
struct V_128 * V_51 ,
struct V_129 * V_129 ,
struct V_48 * V_49 ,
struct V_130 * V_90 )
{
T_2 V_131 , V_132 , V_133 ;
struct V_128 * V_134 , * V_135 ;
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_139 * V_140 ;
struct V_130 * V_141 , * V_142 , * V_143 ;
struct V_130 * V_144 = NULL , * V_145 ;
struct V_146 * V_147 = NULL ;
struct V_146 * V_148 = NULL ;
T_2 * V_149 , * V_150 ;
T_6 V_151 , V_152 ;
T_7 V_153 ;
bool V_92 = false ;
int V_154 ;
int V_155 = sizeof( * V_137 ) ;
int V_156 = sizeof( * V_140 ) ;
int V_157 = V_156 - V_155 ;
V_142 = F_97 ( V_90 -> V_35 ,
V_111 ) ;
if ( ! V_142 )
goto V_95;
V_147 = F_98 ( V_142 ,
V_111 ) ;
if ( ! V_147 )
goto V_95;
V_141 = V_49 -> V_90 ;
V_144 = F_97 ( V_141 -> V_35 ,
V_111 ) ;
if ( ! V_144 )
goto V_95;
V_148 = F_98 ( V_144 ,
V_111 ) ;
if ( ! V_148 )
goto V_95;
V_133 = V_147 -> V_158 . V_159 ;
V_131 = F_93 ( V_133 ) ;
V_133 = V_148 -> V_158 . V_159 ;
V_132 = F_93 ( V_133 ) ;
if ( V_131 >= V_132 ) {
V_143 = V_49 -> V_90 ;
V_149 = V_49 -> V_47 -> V_77 ;
V_145 = V_90 ;
V_150 = V_129 -> V_160 ;
V_137 = (struct V_136 * ) V_49 -> V_51 -> V_83 ;
V_138 = (struct V_136 * ) V_51 -> V_83 ;
V_151 = V_49 -> V_161 ;
V_152 = F_99 ( V_51 ,
V_51 -> V_83 + sizeof( * V_138 ) ) ;
} else {
V_143 = V_90 ;
V_149 = V_129 -> V_160 ;
V_145 = V_49 -> V_90 ;
V_150 = V_49 -> V_47 -> V_77 ;
V_137 = (struct V_136 * ) V_51 -> V_83 ;
V_138 = (struct V_136 * ) V_49 -> V_51 -> V_83 ;
V_151 = F_99 ( V_51 ,
V_51 -> V_83 + sizeof( * V_137 ) ) ;
V_152 = V_49 -> V_161 ;
}
if ( V_51 -> V_98 <= V_49 -> V_51 -> V_98 ) {
V_134 = V_49 -> V_51 ;
V_135 = V_51 ;
} else {
V_134 = V_51 ;
V_135 = V_49 -> V_51 ;
}
V_154 = V_135 -> V_98 - V_155 ;
if ( F_100 ( V_134 ) < 0 || F_100 ( V_135 ) < 0 )
goto V_95;
F_101 ( V_134 , V_157 ) ;
V_140 = (struct V_139 * ) V_134 -> V_83 ;
F_102 ( V_134 ) ;
V_140 -> V_162 = V_2 ;
V_140 -> V_163 = V_164 ;
V_140 -> V_113 = V_137 -> V_113 ;
F_86 ( V_140 -> V_149 , V_149 ) ;
F_86 ( V_140 -> V_165 , V_137 -> V_166 ) ;
V_140 -> V_167 = V_151 ;
V_140 -> V_168 = V_137 -> V_169 ;
F_86 ( V_140 -> V_145 , V_145 -> V_62 ) ;
F_86 ( V_140 -> V_150 , V_150 ) ;
F_86 ( V_140 -> V_170 , V_138 -> V_166 ) ;
V_140 -> V_171 = V_152 ;
V_140 -> V_172 = V_138 -> V_113 ;
V_140 -> V_173 = V_138 -> V_169 ;
V_140 -> V_174 = F_103 ( V_154 ) ;
F_95 ( V_134 -> V_83 + V_156 ,
V_135 -> V_83 + V_155 , V_154 ) ;
if ( F_104 ( V_135 ) -> V_175 &&
F_104 ( V_134 ) -> V_175 ) {
V_153 = V_135 -> V_98 + V_99 ;
V_153 += V_134 -> V_98 + V_99 ;
F_73 ( V_5 , V_176 , 2 ) ;
F_73 ( V_5 , V_177 , V_153 ) ;
} else if ( ! F_104 ( V_135 ) -> V_175 &&
! F_104 ( V_134 ) -> V_175 ) {
V_153 = V_135 -> V_98 + V_99 ;
V_153 += V_134 -> V_98 + V_99 ;
F_73 ( V_5 , V_178 , 2 ) ;
F_73 ( V_5 , V_179 , V_153 ) ;
} else if ( F_104 ( V_135 ) -> V_175 &&
! F_104 ( V_134 ) -> V_175 ) {
F_72 ( V_5 , V_176 ) ;
F_73 ( V_5 , V_177 ,
V_135 -> V_98 + V_99 ) ;
F_72 ( V_5 , V_178 ) ;
F_73 ( V_5 , V_179 ,
V_134 -> V_98 + V_99 ) ;
} else if ( ! F_104 ( V_135 ) -> V_175 &&
F_104 ( V_134 ) -> V_175 ) {
F_72 ( V_5 , V_178 ) ;
F_73 ( V_5 , V_179 ,
V_135 -> V_98 + V_99 ) ;
F_72 ( V_5 , V_176 ) ;
F_73 ( V_5 , V_177 ,
V_134 -> V_98 + V_99 ) ;
}
F_35 ( V_135 ) ;
V_49 -> V_51 = NULL ;
F_33 ( V_49 , false ) ;
F_67 ( V_134 , V_143 ) ;
V_92 = true ;
V_95:
if ( V_142 )
F_105 ( V_142 ) ;
if ( V_144 )
F_105 ( V_144 ) ;
if ( V_147 )
F_106 ( V_147 ) ;
if ( V_148 )
F_106 ( V_148 ) ;
return V_92 ;
}
static bool F_107 ( struct V_128 * V_51 , T_2 * V_82 , T_2 * V_81 )
{
if ( F_104 ( V_51 ) -> V_175 && ! F_63 ( V_82 , V_81 ) )
return false ;
return true ;
}
static struct V_48 *
F_108 ( struct V_4 * V_5 ,
struct V_42 * V_121 ,
struct V_42 * V_122 ,
struct V_128 * V_51 ,
T_2 * V_180 )
{
struct V_46 * V_47 , V_124 ;
struct V_48 * V_181 = NULL ;
struct V_48 * V_49 , * V_100 ;
struct V_63 * V_64 = V_5 -> V_7 . V_25 ;
int V_182 ;
if ( ! V_64 )
return NULL ;
F_59 ( & V_124 , V_121 -> V_62 ,
V_122 -> V_62 ) ;
V_182 = F_60 ( & V_124 , V_64 -> V_69 ) ;
F_50 () ;
F_51 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_63 ( V_47 -> V_77 , V_121 -> V_62 ) )
continue;
if ( ! F_63 ( V_47 -> V_78 , V_122 -> V_62 ) )
continue;
F_43 ( & V_47 -> V_93 ) ;
if ( F_56 ( & V_47 -> V_74 ) ) {
F_47 ( & V_47 -> V_93 ) ;
continue;
}
F_44 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_107 ( V_49 -> V_51 ,
V_180 ,
V_121 -> V_62 ) )
continue;
F_70 ( & V_49 -> V_58 ) ;
V_181 = V_49 ;
break;
}
F_47 ( & V_47 -> V_93 ) ;
break;
}
F_52 () ;
return V_181 ;
}
static struct V_48 *
F_109 ( struct V_4 * V_5 ,
struct V_128 * V_51 ,
T_2 * V_180 ,
T_2 * V_183 ,
struct V_42 * V_121 )
{
struct V_14 * V_35 ;
struct V_42 * V_122 ;
struct V_48 * V_49 = NULL ;
V_35 = F_110 ( V_5 , V_183 ) ;
if ( ! V_35 )
return NULL ;
F_50 () ;
F_82 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_107 ( V_51 ,
V_122 -> V_62 , V_183 ) )
continue;
V_49 = F_108 ( V_5 , V_121 ,
V_122 , V_51 , V_180 ) ;
if ( V_49 )
break;
}
F_52 () ;
F_27 ( V_35 ) ;
return V_49 ;
}
static void F_111 ( struct V_4 * V_5 ,
struct V_128 * V_51 ,
T_2 * V_184 )
{
struct V_129 * V_129 ;
V_51 = F_112 ( V_51 , V_119 ) ;
if ( ! V_51 )
return;
V_129 = F_113 ( V_51 ) ;
F_86 ( V_129 -> V_160 , V_129 -> V_185 ) ;
F_86 ( V_129 -> V_185 , V_184 ) ;
F_101 ( V_51 , V_99 ) ;
F_114 ( V_5 , V_51 ) ;
F_35 ( V_51 ) ;
}
static bool F_115 ( struct V_128 * V_51 ,
struct V_130 * V_90 ,
struct V_129 * V_129 )
{
struct V_12 * V_186 = V_90 -> V_187 -> V_188 ;
struct V_4 * V_5 = F_11 ( V_186 ) ;
struct V_14 * V_35 = V_90 -> V_35 ;
struct V_42 * V_43 ;
struct V_48 * V_49 = NULL ;
F_50 () ;
F_82 (nc_node, &orig_node->in_coding_list, list) {
V_49 = F_109 ( V_5 , V_51 ,
V_90 -> V_62 ,
V_129 -> V_160 , V_43 ) ;
if ( V_49 )
break;
}
F_52 () ;
if ( ! V_49 )
return false ;
F_111 ( V_5 , V_51 ,
V_90 -> V_62 ) ;
F_111 ( V_5 , V_49 -> V_51 ,
V_49 -> V_90 -> V_62 ) ;
if ( F_96 ( V_5 , V_51 , V_129 , V_49 ,
V_90 ) )
return true ;
F_66 ( V_49 ) ;
return false ;
}
static bool F_116 ( struct V_128 * V_51 ,
struct V_46 * V_47 ,
struct V_130 * V_90 ,
T_6 V_161 )
{
struct V_48 * V_49 ;
V_49 = F_84 ( sizeof( * V_49 ) , V_119 ) ;
if ( ! V_49 )
return false ;
V_49 -> V_94 = V_23 ;
V_49 -> V_161 = V_161 ;
V_49 -> V_51 = V_51 ;
V_49 -> V_90 = V_90 ;
V_49 -> V_47 = V_47 ;
F_43 ( & V_47 -> V_93 ) ;
F_117 ( & V_49 -> V_58 , & V_47 -> V_74 ) ;
F_47 ( & V_47 -> V_93 ) ;
return true ;
}
bool F_118 ( struct V_128 * V_51 ,
struct V_130 * V_90 )
{
const struct V_12 * V_186 = V_90 -> V_187 -> V_188 ;
struct V_4 * V_5 = F_11 ( V_186 ) ;
struct V_136 * V_189 ;
struct V_46 * V_47 ;
struct V_129 * V_129 = F_113 ( V_51 ) ;
T_6 V_161 ;
T_2 * V_190 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_95;
V_190 = F_119 ( V_51 ) ;
V_189 = (struct V_136 * ) V_190 ;
if ( V_189 -> V_162 != V_191 )
goto V_95;
if ( F_115 ( V_51 , V_90 , V_129 ) )
return true ;
V_47 = F_91 ( V_5 ,
V_5 -> V_7 . V_25 ,
V_129 -> V_160 ,
V_90 -> V_62 ) ;
if ( ! V_47 )
goto V_95;
V_161 = F_99 ( V_51 , V_190 + sizeof( * V_189 ) ) ;
if ( ! F_116 ( V_51 , V_47 , V_90 , V_161 ) )
goto V_192;
return true ;
V_192:
F_32 ( V_47 ) ;
V_95:
return false ;
}
void F_114 ( struct V_4 * V_5 ,
struct V_128 * V_51 )
{
struct V_136 * V_189 ;
struct V_46 * V_47 ;
struct V_129 * V_129 = F_113 ( V_51 ) ;
T_6 V_161 ;
T_2 * V_190 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_95;
V_190 = F_119 ( V_51 ) ;
V_189 = (struct V_136 * ) V_190 ;
if ( V_189 -> V_162 != V_191 )
goto V_95;
V_47 = F_91 ( V_5 ,
V_5 -> V_7 . V_26 ,
V_129 -> V_160 ,
V_129 -> V_185 ) ;
if ( ! V_47 )
goto V_95;
V_51 = F_120 ( V_51 , V_119 ) ;
if ( F_55 ( ! V_51 ) )
goto V_192;
if ( F_55 ( ! F_121 ( V_51 , V_99 ) ) )
goto V_193;
if ( F_55 ( ! F_122 ( V_51 , V_99 ) ) )
goto V_193;
V_161 = F_99 ( V_51 , V_190 + sizeof( * V_189 ) ) ;
if ( ! F_116 ( V_51 , V_47 , NULL , V_161 ) )
goto V_193;
F_72 ( V_5 , V_194 ) ;
return;
V_193:
F_34 ( V_51 ) ;
V_192:
F_32 ( V_47 ) ;
V_95:
return;
}
void F_123 ( struct V_4 * V_5 ,
struct V_128 * V_51 )
{
struct V_129 * V_129 = F_113 ( V_51 ) ;
if ( F_124 ( V_5 , V_129 -> V_185 ) )
return;
F_101 ( V_51 , V_99 ) ;
F_114 ( V_5 , V_51 ) ;
}
static struct V_136 *
F_125 ( struct V_4 * V_5 , struct V_128 * V_51 ,
struct V_48 * V_49 )
{
const int V_195 = sizeof( struct V_136 ) ;
const int V_196 = sizeof( struct V_139 ) - V_195 ;
struct V_136 * V_197 ;
struct V_139 V_198 ;
struct V_129 * V_129 , V_199 ;
T_2 * V_200 , V_113 , V_169 ;
unsigned int V_154 ;
int V_27 ;
memcpy ( & V_198 , V_51 -> V_83 , sizeof( V_198 ) ) ;
memcpy ( & V_199 , F_126 ( V_51 ) , sizeof( V_199 ) ) ;
if ( F_127 ( V_51 , 0 ) < 0 )
return NULL ;
if ( F_55 ( ! F_122 ( V_51 , V_196 ) ) )
return NULL ;
F_128 ( V_51 , - V_99 ) ;
F_129 ( V_51 ) ;
V_129 = F_113 ( V_51 ) ;
* V_129 = V_199 ;
if ( F_124 ( V_5 , V_198 . V_145 ) ) {
F_86 ( V_129 -> V_185 , V_198 . V_145 ) ;
V_51 -> V_201 = V_202 ;
V_200 = V_198 . V_170 ;
V_113 = V_198 . V_172 ;
V_169 = V_198 . V_173 ;
} else {
V_200 = V_198 . V_165 ;
V_113 = V_198 . V_113 ;
V_169 = V_198 . V_168 ;
}
V_154 = F_130 ( V_198 . V_174 ) ;
if ( V_154 > V_51 -> V_98 )
return NULL ;
F_95 ( V_51 -> V_83 + V_195 ,
V_49 -> V_51 -> V_83 + V_195 ,
V_154 ) ;
if ( V_49 -> V_51 -> V_98 > V_154 + V_195 ) {
V_27 = F_131 ( V_51 , V_154 + V_195 ) ;
if ( V_27 )
return NULL ;
}
V_197 = (struct V_136 * ) V_51 -> V_83 ;
V_197 -> V_162 = V_191 ;
V_197 -> V_163 = V_164 ;
V_197 -> V_113 = V_113 ;
F_86 ( V_197 -> V_166 , V_200 ) ;
V_197 -> V_169 = V_169 ;
F_33 ( V_49 , false ) ;
return V_197 ;
}
static struct V_48 *
F_132 ( struct V_4 * V_5 ,
struct V_129 * V_129 ,
struct V_139 * V_203 )
{
struct V_63 * V_64 = V_5 -> V_7 . V_26 ;
struct V_48 * V_204 , * V_49 = NULL ;
struct V_46 * V_47 , V_124 ;
T_2 * V_166 , * V_205 ;
T_6 V_161 ;
int V_89 ;
if ( ! V_64 )
return NULL ;
V_166 = V_129 -> V_160 ;
if ( ! F_124 ( V_5 , V_203 -> V_145 ) ) {
V_205 = V_203 -> V_150 ;
V_161 = V_203 -> V_171 ;
} else {
V_205 = V_203 -> V_149 ;
V_161 = V_203 -> V_167 ;
}
F_59 ( & V_124 , V_205 , V_166 ) ;
V_89 = F_60 ( & V_124 , V_64 -> V_69 ) ;
F_50 () ;
F_51 (nc_path, &hash->table[index], hash_entry) {
F_43 ( & V_47 -> V_93 ) ;
F_133 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_161 == V_204 -> V_161 ) {
F_70 ( & V_204 -> V_58 ) ;
V_49 = V_204 ;
break;
}
}
F_47 ( & V_47 -> V_93 ) ;
if ( V_49 )
break;
}
F_52 () ;
if ( ! V_49 )
F_45 ( V_61 , V_5 ,
L_6 , V_161 ) ;
return V_49 ;
}
static int V_3 ( struct V_128 * V_51 ,
struct V_206 * V_207 )
{
struct V_4 * V_5 = F_11 ( V_207 -> V_188 ) ;
struct V_136 * V_197 ;
struct V_139 * V_140 ;
struct V_48 * V_49 ;
struct V_129 * V_129 ;
int V_208 = sizeof( * V_140 ) ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_193;
if ( F_55 ( ! F_121 ( V_51 , V_208 ) ) )
goto V_193;
V_140 = (struct V_139 * ) V_51 -> V_83 ;
V_129 = F_113 ( V_51 ) ;
if ( ! F_124 ( V_5 , V_129 -> V_185 ) &&
! F_124 ( V_5 , V_140 -> V_145 ) )
goto V_193;
if ( F_124 ( V_5 , V_140 -> V_145 ) )
F_72 ( V_5 , V_209 ) ;
V_49 = F_132 ( V_5 , V_129 ,
V_140 ) ;
if ( ! V_49 ) {
F_72 ( V_5 , V_210 ) ;
goto V_193;
}
if ( F_100 ( V_51 ) < 0 )
goto V_211;
if ( F_100 ( V_49 -> V_51 ) < 0 )
goto V_211;
V_197 = F_125 ( V_5 , V_51 , V_49 ) ;
if ( ! V_197 ) {
F_72 ( V_5 , V_210 ) ;
goto V_211;
}
F_104 ( V_51 ) -> V_175 = true ;
F_72 ( V_5 , V_212 ) ;
F_73 ( V_5 , V_213 ,
V_51 -> V_98 + V_99 ) ;
return F_134 ( V_51 , V_207 ) ;
V_211:
F_33 ( V_49 , true ) ;
V_193:
F_34 ( V_51 ) ;
return V_214 ;
}
void F_135 ( struct V_4 * V_5 )
{
F_8 ( V_5 , V_11 , 1 ) ;
F_136 ( V_5 , V_11 , 1 ) ;
F_137 ( & V_5 -> V_7 . V_8 ) ;
F_53 ( V_5 , V_5 -> V_7 . V_25 , NULL ) ;
F_138 ( V_5 -> V_7 . V_25 ) ;
F_53 ( V_5 , V_5 -> V_7 . V_26 , NULL ) ;
F_138 ( V_5 -> V_7 . V_26 ) ;
}
int F_139 ( struct V_215 * V_216 , void * V_217 )
{
struct V_12 * V_13 = (struct V_12 * ) V_216 -> V_218 ;
struct V_4 * V_5 = F_11 ( V_13 ) ;
struct V_63 * V_64 = V_5 -> V_65 ;
struct V_206 * V_219 ;
struct V_66 * V_67 ;
struct V_14 * V_35 ;
struct V_42 * V_43 ;
int V_68 ;
V_219 = F_140 ( V_216 ) ;
if ( ! V_219 )
goto V_95;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_67 = & V_64 -> V_70 [ V_68 ] ;
F_50 () ;
F_51 (orig_node, head, hash_entry) {
if ( F_56 ( & V_35 -> V_36 ) &&
F_56 ( & V_35 -> V_37 ) )
continue;
F_141 ( V_216 , L_7 , V_35 -> V_15 ) ;
F_142 ( V_216 , L_8 ) ;
F_82 (nc_node,
&orig_node->in_coding_list,
list)
F_141 ( V_216 , L_9 ,
V_43 -> V_62 ) ;
F_142 ( V_216 , L_10 ) ;
F_142 ( V_216 , L_11 ) ;
F_82 (nc_node,
&orig_node->out_coding_list,
list)
F_141 ( V_216 , L_9 ,
V_43 -> V_62 ) ;
F_142 ( V_216 , L_12 ) ;
}
F_52 () ;
}
V_95:
if ( V_219 )
F_143 ( V_219 ) ;
return 0 ;
}
int F_144 ( struct V_4 * V_5 )
{
struct V_220 * V_221 , * V_222 ;
V_221 = F_145 ( L_13 , V_5 -> V_223 ) ;
if ( ! V_221 )
goto V_95;
V_222 = F_146 ( L_14 , 0644 , V_221 , & V_5 -> V_7 . V_32 ) ;
if ( ! V_222 )
goto V_95;
V_222 = F_147 ( L_15 , 0644 , V_221 ,
& V_5 -> V_7 . V_33 ) ;
if ( ! V_222 )
goto V_95;
V_222 = F_147 ( L_16 , 0644 , V_221 ,
& V_5 -> V_7 . V_34 ) ;
if ( ! V_222 )
goto V_95;
return 0 ;
V_95:
return - V_31 ;
}
