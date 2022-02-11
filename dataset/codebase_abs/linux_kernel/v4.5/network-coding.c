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
F_26 ( V_41 -> V_35 ) ;
F_27 ( V_41 , V_42 ) ;
}
static void F_28 ( struct V_40 * V_41 )
{
if ( F_29 ( & V_41 -> V_43 ) )
F_25 ( V_41 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
if ( F_29 ( & V_45 -> V_43 ) )
F_27 ( V_45 , V_42 ) ;
}
static void F_31 ( struct V_46 * V_47 )
{
F_32 ( V_47 -> V_48 ) ;
F_30 ( V_47 -> V_45 ) ;
F_33 ( V_47 ) ;
}
static bool F_34 ( struct V_4 * V_5 ,
struct V_40 * V_41 )
{
if ( F_7 ( & V_5 -> V_49 ) != V_50 )
return true ;
return F_35 ( V_41 -> V_51 , V_52 ) ;
}
static bool F_36 ( struct V_4 * V_5 ,
struct V_44 * V_45 )
{
if ( F_7 ( & V_5 -> V_49 ) != V_50 )
return true ;
return F_35 ( V_45 -> V_53 ,
V_5 -> V_7 . V_33 * 10 ) ;
}
static bool F_37 ( struct V_4 * V_5 ,
struct V_44 * V_45 )
{
if ( F_7 ( & V_5 -> V_49 ) != V_50 )
return true ;
return F_35 ( V_45 -> V_53 ,
V_5 -> V_7 . V_34 * 10 ) ;
}
static void
F_38 ( struct V_4 * V_5 ,
struct V_54 * V_55 ,
T_4 * V_56 ,
bool (* F_39)( struct V_4 * ,
struct V_40 * ) )
{
struct V_40 * V_41 , * V_57 ;
F_40 ( V_56 ) ;
F_41 (nc_node, nc_node_tmp, list, list) {
if ( F_39 && ! F_39 ( V_5 , V_41 ) )
continue;
F_42 ( V_58 , V_5 ,
L_1 ,
V_41 -> V_59 , V_41 -> V_35 -> V_15 ) ;
F_43 ( & V_41 -> V_55 ) ;
F_28 ( V_41 ) ;
}
F_44 ( V_56 ) ;
}
void F_45 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
bool (* F_39)( struct V_4 * ,
struct V_40 * ) )
{
F_38 ( V_5 , & V_35 -> V_36 ,
& V_35 -> V_38 ,
F_39 ) ;
F_38 ( V_5 , & V_35 -> V_37 ,
& V_35 -> V_39 ,
F_39 ) ;
}
static void F_46 ( struct V_4 * V_5 )
{
struct V_60 * V_61 = V_5 -> V_62 ;
struct V_63 * V_64 ;
struct V_14 * V_35 ;
T_5 V_65 ;
if ( ! V_61 )
return;
for ( V_65 = 0 ; V_65 < V_61 -> V_66 ; V_65 ++ ) {
V_64 = & V_61 -> V_67 [ V_65 ] ;
F_47 () ;
F_48 (orig_node, head, hash_entry)
F_45 ( V_5 , V_35 ,
F_34 ) ;
F_49 () ;
}
}
static void F_50 ( struct V_4 * V_5 ,
struct V_60 * V_61 ,
bool (* F_39)( struct V_4 * ,
struct V_44 * ) )
{
struct V_63 * V_64 ;
struct V_68 * V_69 ;
struct V_44 * V_45 ;
T_4 * V_56 ;
T_5 V_65 ;
for ( V_65 = 0 ; V_65 < V_61 -> V_66 ; V_65 ++ ) {
V_64 = & V_61 -> V_67 [ V_65 ] ;
V_56 = & V_61 -> V_70 [ V_65 ] ;
F_40 ( V_56 ) ;
F_51 (nc_path, node_tmp, head, hash_entry) {
if ( F_39 && ! F_39 ( V_5 , V_45 ) )
continue;
if ( ! F_52 ( F_53 ( & V_45 -> V_71 ) ) ) {
F_54 ( V_72 ,
V_73
L_2 ,
V_45 -> V_74 ,
V_45 -> V_75 ) ;
continue;
}
F_42 ( V_58 , V_5 ,
L_3 ,
V_45 -> V_74 , V_45 -> V_75 ) ;
F_55 ( & V_45 -> V_76 ) ;
F_30 ( V_45 ) ;
}
F_44 ( V_56 ) ;
}
}
static void F_56 ( struct V_44 * V_77 , const char * V_78 ,
const char * V_79 )
{
memcpy ( V_77 -> V_74 , V_78 , sizeof( V_77 -> V_74 ) ) ;
memcpy ( V_77 -> V_75 , V_79 , sizeof( V_77 -> V_75 ) ) ;
}
static T_5 F_57 ( const void * V_80 , T_5 V_66 )
{
const struct V_44 * V_45 = V_80 ;
T_5 V_61 = 0 ;
V_61 = F_58 ( & V_45 -> V_74 , sizeof( V_45 -> V_74 ) , V_61 ) ;
V_61 = F_58 ( & V_45 -> V_75 , sizeof( V_45 -> V_75 ) , V_61 ) ;
return V_61 % V_66 ;
}
static int F_59 ( const struct V_68 * V_81 ,
const void * V_82 )
{
const struct V_44 * V_83 , * V_84 ;
V_83 = F_60 ( V_81 , struct V_44 , V_76 ) ;
V_84 = V_82 ;
if ( memcmp ( V_83 -> V_74 , V_84 -> V_74 ,
sizeof( V_83 -> V_74 ) ) != 0 )
return 0 ;
if ( memcmp ( V_83 -> V_75 , V_84 -> V_75 ,
sizeof( V_83 -> V_75 ) ) != 0 )
return 0 ;
return 1 ;
}
static struct V_44 *
F_61 ( struct V_60 * V_61 ,
void * V_80 )
{
struct V_63 * V_64 ;
struct V_44 * V_45 , * V_85 = NULL ;
int V_86 ;
if ( ! V_61 )
return NULL ;
V_86 = F_57 ( V_80 , V_61 -> V_66 ) ;
V_64 = & V_61 -> V_67 [ V_86 ] ;
F_47 () ;
F_48 (nc_path, head, hash_entry) {
if ( ! F_59 ( & V_45 -> V_76 , V_80 ) )
continue;
if ( ! F_62 ( & V_45 -> V_43 ) )
continue;
V_85 = V_45 ;
break;
}
F_49 () ;
return V_85 ;
}
static void F_63 ( struct V_46 * V_47 )
{
F_64 ( V_47 -> V_48 ,
V_47 -> V_87 -> V_88 ,
V_47 -> V_45 -> V_75 ) ;
V_47 -> V_48 = NULL ;
F_31 ( V_47 ) ;
}
static bool F_65 ( struct V_4 * V_5 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
unsigned long V_89 = V_5 -> V_7 . V_34 ;
bool V_90 = false ;
F_66 ( & V_45 -> V_91 ) ;
if ( F_7 ( & V_5 -> V_49 ) == V_50 &&
! F_35 ( V_47 -> V_92 , V_89 ) )
goto V_93;
F_67 ( & V_47 -> V_55 ) ;
F_31 ( V_47 ) ;
V_90 = true ;
V_93:
return V_90 ;
}
static bool F_68 ( struct V_4 * V_5 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
unsigned long V_89 = V_5 -> V_7 . V_33 ;
F_66 ( & V_45 -> V_91 ) ;
if ( F_7 ( & V_5 -> V_49 ) == V_50 &&
! F_35 ( V_47 -> V_92 , V_89 ) )
return false ;
F_69 ( V_5 , V_94 ) ;
F_70 ( V_5 , V_95 ,
V_47 -> V_48 -> V_96 + V_97 ) ;
F_67 ( & V_47 -> V_55 ) ;
F_63 ( V_47 ) ;
return true ;
}
static void
F_71 ( struct V_4 * V_5 ,
struct V_60 * V_61 ,
bool (* F_72)( struct V_4 * ,
struct V_44 * ,
struct V_46 * ) )
{
struct V_63 * V_64 ;
struct V_46 * V_47 , * V_98 ;
struct V_44 * V_45 ;
bool V_1 ;
int V_65 ;
if ( ! V_61 )
return;
for ( V_65 = 0 ; V_65 < V_61 -> V_66 ; V_65 ++ ) {
V_64 = & V_61 -> V_67 [ V_65 ] ;
F_47 () ;
F_48 (nc_path, head, hash_entry) {
F_40 ( & V_45 -> V_91 ) ;
F_41 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_1 = F_72 ( V_5 , V_45 , V_47 ) ;
if ( ! V_1 )
break;
}
F_44 ( & V_45 -> V_91 ) ;
}
F_49 () ;
}
}
static void V_30 ( struct V_99 * V_8 )
{
struct V_100 * V_100 ;
struct V_101 * V_102 ;
struct V_4 * V_5 ;
unsigned long V_89 ;
V_100 = F_60 ( V_8 , struct V_100 , V_8 ) ;
V_102 = F_60 ( V_100 , struct V_101 , V_8 ) ;
V_5 = F_60 ( V_102 , struct V_4 , V_7 ) ;
F_46 ( V_5 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_25 ,
F_36 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_26 ,
F_37 ) ;
V_89 = V_5 -> V_7 . V_33 ;
if ( F_35 ( V_5 -> V_7 . V_22 , V_89 ) ) {
F_71 ( V_5 , V_5 -> V_7 . V_25 ,
F_68 ) ;
V_5 -> V_7 . V_22 = V_23 ;
}
if ( F_35 ( V_5 -> V_7 . V_24 ,
V_5 -> V_7 . V_34 ) ) {
F_71 ( V_5 , V_5 -> V_7 . V_26 ,
F_65 ) ;
V_5 -> V_7 . V_24 = V_23 ;
}
F_3 ( V_5 ) ;
}
static bool F_73 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 ;
T_5 V_107 ;
T_2 V_108 ;
V_106 = F_74 ( V_35 , V_109 ) ;
if ( ! V_106 )
return false ;
V_108 = V_106 -> V_108 ;
V_107 = V_106 -> V_107 ;
F_75 ( V_106 ) ;
if ( V_107 != F_76 ( V_104 -> V_110 ) )
return false ;
if ( V_108 != V_104 -> V_111 + 1 )
return false ;
if ( ! F_77 ( V_104 -> V_15 , V_104 -> V_112 ) )
return false ;
if ( V_104 -> V_113 < V_5 -> V_7 . V_32 )
return false ;
return true ;
}
static struct V_40
* F_78 ( struct V_14 * V_35 ,
struct V_14 * V_114 ,
bool V_115 )
{
struct V_40 * V_41 , * V_116 = NULL ;
struct V_54 * V_55 ;
if ( V_115 )
V_55 = & V_114 -> V_36 ;
else
V_55 = & V_114 -> V_37 ;
F_47 () ;
F_79 (nc_node, list, list) {
if ( ! F_77 ( V_41 -> V_59 , V_35 -> V_15 ) )
continue;
if ( ! F_62 ( & V_41 -> V_43 ) )
continue;
V_116 = V_41 ;
break;
}
F_49 () ;
return V_116 ;
}
static struct V_40
* F_80 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_114 ,
bool V_115 )
{
struct V_40 * V_41 ;
T_4 * V_56 ;
struct V_54 * V_55 ;
V_41 = F_78 ( V_35 , V_114 , V_115 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_81 ( sizeof( * V_41 ) , V_117 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_62 ( & V_114 -> V_43 ) )
goto free;
F_23 ( & V_41 -> V_55 ) ;
F_82 ( V_41 -> V_59 , V_35 -> V_15 ) ;
V_41 -> V_35 = V_114 ;
F_21 ( & V_41 -> V_43 , 2 ) ;
if ( V_115 ) {
V_56 = & V_114 -> V_38 ;
V_55 = & V_114 -> V_36 ;
} else {
V_56 = & V_114 -> V_39 ;
V_55 = & V_114 -> V_37 ;
}
F_42 ( V_58 , V_5 , L_4 ,
V_41 -> V_59 , V_41 -> V_35 -> V_15 ) ;
F_40 ( V_56 ) ;
F_83 ( & V_41 -> V_55 , V_55 ) ;
F_44 ( V_56 ) ;
return V_41 ;
free:
F_33 ( V_41 ) ;
return NULL ;
}
void F_84 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_114 ,
struct V_103 * V_104 ,
int V_118 )
{
struct V_40 * V_119 = NULL ;
struct V_40 * V_120 = NULL ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
if ( ! F_85 ( V_20 , & V_35 -> V_21 ) )
goto V_93;
if ( ! F_73 ( V_5 , V_35 , V_104 ) &&
! V_118 )
goto V_93;
V_119 = F_80 ( V_5 , V_35 ,
V_114 , true ) ;
if ( ! V_119 )
goto V_93;
V_119 -> V_51 = V_23 ;
V_120 = F_80 ( V_5 , V_114 ,
V_35 , false ) ;
if ( ! V_120 )
goto V_93;
V_120 -> V_51 = V_23 ;
V_93:
if ( V_119 )
F_28 ( V_119 ) ;
if ( V_120 )
F_28 ( V_120 ) ;
}
static struct V_44 * F_86 ( struct V_4 * V_5 ,
struct V_60 * V_61 ,
T_2 * V_78 ,
T_2 * V_79 )
{
int V_121 ;
struct V_44 * V_45 , V_122 ;
F_56 ( & V_122 , V_78 , V_79 ) ;
V_45 = F_61 ( V_61 , ( void * ) & V_122 ) ;
if ( V_45 ) {
V_45 -> V_53 = V_23 ;
return V_45 ;
}
V_45 = F_81 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return NULL ;
F_23 ( & V_45 -> V_71 ) ;
F_24 ( & V_45 -> V_91 ) ;
F_21 ( & V_45 -> V_43 , 2 ) ;
V_45 -> V_53 = V_23 ;
F_82 ( V_45 -> V_75 , V_79 ) ;
F_82 ( V_45 -> V_74 , V_78 ) ;
F_42 ( V_58 , V_5 , L_5 ,
V_45 -> V_74 ,
V_45 -> V_75 ) ;
V_121 = F_87 ( V_61 , F_59 ,
F_57 , & V_122 ,
& V_45 -> V_76 ) ;
if ( V_121 < 0 ) {
F_33 ( V_45 ) ;
return NULL ;
}
return V_45 ;
}
static T_2 F_88 ( T_2 V_113 )
{
T_2 V_123 , V_124 ;
F_89 ( & V_123 , sizeof( V_123 ) ) ;
V_124 = V_123 * ( V_125 - V_113 ) ;
V_124 /= V_125 ;
return V_125 - V_124 ;
}
static void F_90 ( char * V_79 , const char * V_78 , unsigned int V_96 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_96 ; ++ V_65 )
V_79 [ V_65 ] ^= V_78 [ V_65 ] ;
}
static bool F_91 ( struct V_4 * V_5 ,
struct V_126 * V_48 ,
struct V_127 * V_127 ,
struct V_46 * V_47 ,
struct V_128 * V_87 )
{
T_2 V_129 , V_130 , V_131 ;
struct V_126 * V_132 , * V_133 ;
struct V_134 * V_135 ;
struct V_134 * V_136 ;
struct V_137 * V_138 ;
struct V_128 * V_139 , * V_140 ;
struct V_128 * V_141 = NULL ;
struct V_142 * V_143 = NULL ;
struct V_142 * V_144 = NULL ;
T_2 * V_145 , * V_146 , * V_147 , * V_148 ;
T_6 V_149 , V_150 ;
T_7 V_151 ;
bool V_90 = false ;
int V_152 ;
int V_153 = sizeof( * V_135 ) ;
int V_154 = sizeof( * V_138 ) ;
int V_155 = V_154 - V_153 ;
V_140 = F_92 ( V_87 -> V_35 ,
V_109 ) ;
if ( ! V_140 )
goto V_93;
V_143 = F_93 ( V_140 ,
V_109 ) ;
if ( ! V_143 )
goto V_93;
V_139 = V_47 -> V_87 ;
V_141 = F_92 ( V_139 -> V_35 ,
V_109 ) ;
if ( ! V_141 )
goto V_93;
V_144 = F_93 ( V_141 ,
V_109 ) ;
if ( ! V_144 )
goto V_93;
V_131 = V_143 -> V_156 . V_157 ;
V_129 = F_88 ( V_131 ) ;
V_131 = V_144 -> V_156 . V_157 ;
V_130 = F_88 ( V_131 ) ;
if ( V_129 >= V_130 ) {
V_146 = V_47 -> V_45 -> V_75 ;
V_145 = V_47 -> V_45 -> V_74 ;
V_148 = V_87 -> V_59 ;
V_147 = V_127 -> V_158 ;
V_135 = (struct V_134 * ) V_47 -> V_48 -> V_80 ;
V_136 = (struct V_134 * ) V_48 -> V_80 ;
V_149 = V_47 -> V_159 ;
V_150 = F_94 ( V_48 ,
V_48 -> V_80 + sizeof( * V_136 ) ) ;
} else {
V_146 = V_87 -> V_59 ;
V_145 = V_127 -> V_158 ;
V_148 = V_47 -> V_45 -> V_75 ;
V_147 = V_47 -> V_45 -> V_74 ;
V_135 = (struct V_134 * ) V_48 -> V_80 ;
V_136 = (struct V_134 * ) V_47 -> V_48 -> V_80 ;
V_149 = F_94 ( V_48 ,
V_48 -> V_80 + sizeof( * V_135 ) ) ;
V_150 = V_47 -> V_159 ;
}
if ( V_48 -> V_96 <= V_47 -> V_48 -> V_96 ) {
V_132 = V_47 -> V_48 ;
V_133 = V_48 ;
} else {
V_132 = V_48 ;
V_133 = V_47 -> V_48 ;
}
V_152 = V_133 -> V_96 - V_153 ;
if ( F_95 ( V_132 ) < 0 || F_95 ( V_133 ) < 0 )
goto V_93;
F_96 ( V_132 , V_155 ) ;
V_138 = (struct V_137 * ) V_132 -> V_80 ;
F_97 ( V_132 ) ;
V_138 -> V_160 = V_2 ;
V_138 -> V_161 = V_162 ;
V_138 -> V_111 = V_135 -> V_111 ;
F_82 ( V_138 -> V_145 , V_145 ) ;
F_82 ( V_138 -> V_163 , V_135 -> V_164 ) ;
V_138 -> V_165 = V_149 ;
V_138 -> V_166 = V_135 -> V_167 ;
F_82 ( V_138 -> V_148 , V_148 ) ;
F_82 ( V_138 -> V_147 , V_147 ) ;
F_82 ( V_138 -> V_168 , V_136 -> V_164 ) ;
V_138 -> V_169 = V_150 ;
V_138 -> V_170 = V_136 -> V_111 ;
V_138 -> V_171 = V_136 -> V_167 ;
V_138 -> V_172 = F_98 ( V_152 ) ;
F_90 ( V_132 -> V_80 + V_154 ,
V_133 -> V_80 + V_153 , V_152 ) ;
if ( F_99 ( V_133 ) -> V_173 &&
F_99 ( V_132 ) -> V_173 ) {
V_151 = V_133 -> V_96 + V_97 ;
V_151 += V_132 -> V_96 + V_97 ;
F_70 ( V_5 , V_174 , 2 ) ;
F_70 ( V_5 , V_175 , V_151 ) ;
} else if ( ! F_99 ( V_133 ) -> V_173 &&
! F_99 ( V_132 ) -> V_173 ) {
V_151 = V_133 -> V_96 + V_97 ;
V_151 += V_132 -> V_96 + V_97 ;
F_70 ( V_5 , V_176 , 2 ) ;
F_70 ( V_5 , V_177 , V_151 ) ;
} else if ( F_99 ( V_133 ) -> V_173 &&
! F_99 ( V_132 ) -> V_173 ) {
F_69 ( V_5 , V_174 ) ;
F_70 ( V_5 , V_175 ,
V_133 -> V_96 + V_97 ) ;
F_69 ( V_5 , V_176 ) ;
F_70 ( V_5 , V_177 ,
V_132 -> V_96 + V_97 ) ;
} else if ( ! F_99 ( V_133 ) -> V_173 &&
F_99 ( V_132 ) -> V_173 ) {
F_69 ( V_5 , V_176 ) ;
F_70 ( V_5 , V_177 ,
V_133 -> V_96 + V_97 ) ;
F_69 ( V_5 , V_174 ) ;
F_70 ( V_5 , V_175 ,
V_132 -> V_96 + V_97 ) ;
}
F_32 ( V_133 ) ;
V_47 -> V_48 = NULL ;
F_31 ( V_47 ) ;
F_64 ( V_132 , V_87 -> V_88 , V_146 ) ;
V_90 = true ;
V_93:
if ( V_140 )
F_100 ( V_140 ) ;
if ( V_141 )
F_100 ( V_141 ) ;
if ( V_143 )
F_101 ( V_143 ) ;
if ( V_144 )
F_101 ( V_144 ) ;
return V_90 ;
}
static bool F_102 ( struct V_126 * V_48 , T_2 * V_79 , T_2 * V_78 )
{
if ( F_99 ( V_48 ) -> V_173 && ! F_77 ( V_79 , V_78 ) )
return false ;
return true ;
}
static struct V_46 *
F_103 ( struct V_4 * V_5 ,
struct V_40 * V_119 ,
struct V_40 * V_120 ,
struct V_126 * V_48 ,
T_2 * V_178 )
{
struct V_44 * V_45 , V_122 ;
struct V_46 * V_179 = NULL ;
struct V_46 * V_47 , * V_98 ;
struct V_60 * V_61 = V_5 -> V_7 . V_25 ;
int V_180 ;
if ( ! V_61 )
return NULL ;
F_56 ( & V_122 , V_119 -> V_59 ,
V_120 -> V_59 ) ;
V_180 = F_57 ( & V_122 , V_61 -> V_66 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_77 ( V_45 -> V_74 , V_119 -> V_59 ) )
continue;
if ( ! F_77 ( V_45 -> V_75 , V_120 -> V_59 ) )
continue;
F_40 ( & V_45 -> V_91 ) ;
if ( F_53 ( & V_45 -> V_71 ) ) {
F_44 ( & V_45 -> V_91 ) ;
continue;
}
F_41 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_102 ( V_47 -> V_48 ,
V_178 ,
V_119 -> V_59 ) )
continue;
F_67 ( & V_47 -> V_55 ) ;
V_179 = V_47 ;
break;
}
F_44 ( & V_45 -> V_91 ) ;
break;
}
F_49 () ;
return V_179 ;
}
static struct V_46 *
F_104 ( struct V_4 * V_5 ,
struct V_126 * V_48 ,
T_2 * V_178 ,
T_2 * V_181 ,
struct V_40 * V_119 )
{
struct V_14 * V_35 ;
struct V_40 * V_120 ;
struct V_46 * V_47 = NULL ;
V_35 = F_105 ( V_5 , V_181 ) ;
if ( ! V_35 )
return NULL ;
F_47 () ;
F_79 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_102 ( V_48 ,
V_120 -> V_59 , V_181 ) )
continue;
V_47 = F_103 ( V_5 , V_119 ,
V_120 , V_48 , V_178 ) ;
if ( V_47 )
break;
}
F_49 () ;
F_26 ( V_35 ) ;
return V_47 ;
}
static void F_106 ( struct V_4 * V_5 ,
struct V_126 * V_48 ,
T_2 * V_182 )
{
struct V_127 * V_127 ;
V_48 = F_107 ( V_48 , V_117 ) ;
if ( ! V_48 )
return;
V_127 = F_108 ( V_48 ) ;
F_82 ( V_127 -> V_158 , V_127 -> V_183 ) ;
F_82 ( V_127 -> V_183 , V_182 ) ;
F_96 ( V_48 , V_97 ) ;
F_109 ( V_5 , V_48 ) ;
F_32 ( V_48 ) ;
}
static bool F_110 ( struct V_126 * V_48 ,
struct V_128 * V_87 ,
struct V_127 * V_127 )
{
struct V_12 * V_184 = V_87 -> V_88 -> V_185 ;
struct V_4 * V_5 = F_11 ( V_184 ) ;
struct V_14 * V_35 = V_87 -> V_35 ;
struct V_40 * V_41 ;
struct V_46 * V_47 = NULL ;
F_47 () ;
F_79 (nc_node, &orig_node->in_coding_list, list) {
V_47 = F_104 ( V_5 , V_48 ,
V_87 -> V_59 ,
V_127 -> V_158 , V_41 ) ;
if ( V_47 )
break;
}
F_49 () ;
if ( ! V_47 )
return false ;
F_106 ( V_5 , V_48 ,
V_87 -> V_59 ) ;
F_106 ( V_5 , V_47 -> V_48 ,
V_47 -> V_87 -> V_59 ) ;
if ( F_91 ( V_5 , V_48 , V_127 , V_47 ,
V_87 ) )
return true ;
F_63 ( V_47 ) ;
return false ;
}
static bool F_111 ( struct V_126 * V_48 ,
struct V_44 * V_45 ,
struct V_128 * V_87 ,
T_6 V_159 )
{
struct V_46 * V_47 ;
V_47 = F_81 ( sizeof( * V_47 ) , V_117 ) ;
if ( ! V_47 )
return false ;
V_47 -> V_92 = V_23 ;
V_47 -> V_159 = V_159 ;
V_47 -> V_48 = V_48 ;
V_47 -> V_87 = V_87 ;
V_47 -> V_45 = V_45 ;
F_40 ( & V_45 -> V_91 ) ;
F_112 ( & V_47 -> V_55 , & V_45 -> V_71 ) ;
F_44 ( & V_45 -> V_91 ) ;
return true ;
}
bool F_113 ( struct V_126 * V_48 ,
struct V_128 * V_87 )
{
const struct V_12 * V_184 = V_87 -> V_88 -> V_185 ;
struct V_4 * V_5 = F_11 ( V_184 ) ;
struct V_134 * V_186 ;
struct V_44 * V_45 ;
struct V_127 * V_127 = F_108 ( V_48 ) ;
T_6 V_159 ;
T_2 * V_187 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_187 = F_114 ( V_48 ) ;
V_186 = (struct V_134 * ) V_187 ;
if ( V_186 -> V_160 != V_188 )
goto V_93;
if ( F_110 ( V_48 , V_87 , V_127 ) )
return true ;
V_45 = F_86 ( V_5 ,
V_5 -> V_7 . V_25 ,
V_127 -> V_158 ,
V_87 -> V_59 ) ;
if ( ! V_45 )
goto V_93;
V_159 = F_94 ( V_48 , V_187 + sizeof( * V_186 ) ) ;
if ( ! F_111 ( V_48 , V_45 , V_87 , V_159 ) )
goto V_189;
return true ;
V_189:
F_30 ( V_45 ) ;
V_93:
return false ;
}
void F_109 ( struct V_4 * V_5 ,
struct V_126 * V_48 )
{
struct V_134 * V_186 ;
struct V_44 * V_45 ;
struct V_127 * V_127 = F_108 ( V_48 ) ;
T_6 V_159 ;
T_2 * V_187 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_187 = F_114 ( V_48 ) ;
V_186 = (struct V_134 * ) V_187 ;
if ( V_186 -> V_160 != V_188 )
goto V_93;
V_45 = F_86 ( V_5 ,
V_5 -> V_7 . V_26 ,
V_127 -> V_158 ,
V_127 -> V_183 ) ;
if ( ! V_45 )
goto V_93;
V_48 = F_115 ( V_48 , V_117 ) ;
if ( F_52 ( ! V_48 ) )
goto V_189;
if ( F_52 ( ! F_116 ( V_48 , V_97 ) ) )
goto V_190;
if ( F_52 ( ! F_117 ( V_48 , V_97 ) ) )
goto V_190;
V_159 = F_94 ( V_48 , V_187 + sizeof( * V_186 ) ) ;
if ( ! F_111 ( V_48 , V_45 , NULL , V_159 ) )
goto V_190;
F_69 ( V_5 , V_191 ) ;
return;
V_190:
F_32 ( V_48 ) ;
V_189:
F_30 ( V_45 ) ;
V_93:
return;
}
void F_118 ( struct V_4 * V_5 ,
struct V_126 * V_48 )
{
struct V_127 * V_127 = F_108 ( V_48 ) ;
if ( F_119 ( V_5 , V_127 -> V_183 ) )
return;
F_96 ( V_48 , V_97 ) ;
F_109 ( V_5 , V_48 ) ;
}
static struct V_134 *
F_120 ( struct V_4 * V_5 , struct V_126 * V_48 ,
struct V_46 * V_47 )
{
const int V_192 = sizeof( struct V_134 ) ;
const int V_193 = sizeof( struct V_137 ) - V_192 ;
struct V_134 * V_194 ;
struct V_137 V_195 ;
struct V_127 * V_127 , V_196 ;
T_2 * V_197 , V_111 , V_167 ;
unsigned int V_152 ;
int V_27 ;
memcpy ( & V_195 , V_48 -> V_80 , sizeof( V_195 ) ) ;
memcpy ( & V_196 , F_121 ( V_48 ) , sizeof( V_196 ) ) ;
if ( F_122 ( V_48 , 0 ) < 0 )
return NULL ;
if ( F_52 ( ! F_117 ( V_48 , V_193 ) ) )
return NULL ;
F_123 ( V_48 , - V_97 ) ;
F_124 ( V_48 ) ;
V_127 = F_108 ( V_48 ) ;
* V_127 = V_196 ;
if ( F_119 ( V_5 , V_195 . V_148 ) ) {
F_82 ( V_127 -> V_183 , V_195 . V_148 ) ;
V_48 -> V_198 = V_199 ;
V_197 = V_195 . V_168 ;
V_111 = V_195 . V_170 ;
V_167 = V_195 . V_171 ;
} else {
V_197 = V_195 . V_163 ;
V_111 = V_195 . V_111 ;
V_167 = V_195 . V_166 ;
}
V_152 = F_125 ( V_195 . V_172 ) ;
if ( V_152 > V_48 -> V_96 )
return NULL ;
F_90 ( V_48 -> V_80 + V_192 ,
V_47 -> V_48 -> V_80 + V_192 ,
V_152 ) ;
if ( V_47 -> V_48 -> V_96 > V_152 + V_192 ) {
V_27 = F_126 ( V_48 , V_152 + V_192 ) ;
if ( V_27 )
return NULL ;
}
V_194 = (struct V_134 * ) V_48 -> V_80 ;
V_194 -> V_160 = V_188 ;
V_194 -> V_161 = V_162 ;
V_194 -> V_111 = V_111 ;
F_82 ( V_194 -> V_164 , V_197 ) ;
V_194 -> V_167 = V_167 ;
F_31 ( V_47 ) ;
return V_194 ;
}
static struct V_46 *
F_127 ( struct V_4 * V_5 ,
struct V_127 * V_127 ,
struct V_137 * V_200 )
{
struct V_60 * V_61 = V_5 -> V_7 . V_26 ;
struct V_46 * V_201 , * V_47 = NULL ;
struct V_44 * V_45 , V_122 ;
T_2 * V_164 , * V_202 ;
T_6 V_159 ;
int V_86 ;
if ( ! V_61 )
return NULL ;
V_164 = V_127 -> V_158 ;
if ( ! F_119 ( V_5 , V_200 -> V_148 ) ) {
V_202 = V_200 -> V_147 ;
V_159 = V_200 -> V_169 ;
} else {
V_202 = V_200 -> V_145 ;
V_159 = V_200 -> V_165 ;
}
F_56 ( & V_122 , V_202 , V_164 ) ;
V_86 = F_57 ( & V_122 , V_61 -> V_66 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[index], hash_entry) {
F_40 ( & V_45 -> V_91 ) ;
F_128 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_159 == V_201 -> V_159 ) {
F_67 ( & V_201 -> V_55 ) ;
V_47 = V_201 ;
break;
}
}
F_44 ( & V_45 -> V_91 ) ;
if ( V_47 )
break;
}
F_49 () ;
if ( ! V_47 )
F_42 ( V_58 , V_5 ,
L_6 , V_159 ) ;
return V_47 ;
}
static int V_3 ( struct V_126 * V_48 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = F_11 ( V_204 -> V_185 ) ;
struct V_134 * V_194 ;
struct V_137 * V_138 ;
struct V_46 * V_47 ;
struct V_127 * V_127 ;
int V_205 = sizeof( * V_138 ) ;
if ( ! F_7 ( & V_5 -> V_10 ) )
return V_206 ;
if ( F_52 ( ! F_116 ( V_48 , V_205 ) ) )
return V_206 ;
V_138 = (struct V_137 * ) V_48 -> V_80 ;
V_127 = F_108 ( V_48 ) ;
if ( ! F_119 ( V_5 , V_127 -> V_183 ) &&
! F_119 ( V_5 , V_138 -> V_148 ) )
return V_206 ;
if ( F_119 ( V_5 , V_138 -> V_148 ) )
F_69 ( V_5 , V_207 ) ;
V_47 = F_127 ( V_5 , V_127 ,
V_138 ) ;
if ( ! V_47 ) {
F_69 ( V_5 , V_208 ) ;
return V_206 ;
}
if ( F_95 ( V_48 ) < 0 )
goto V_209;
if ( F_95 ( V_47 -> V_48 ) < 0 )
goto V_209;
V_194 = F_120 ( V_5 , V_48 , V_47 ) ;
if ( ! V_194 ) {
F_69 ( V_5 , V_208 ) ;
goto V_209;
}
F_99 ( V_48 ) -> V_173 = true ;
F_69 ( V_5 , V_210 ) ;
F_70 ( V_5 , V_211 ,
V_48 -> V_96 + V_97 ) ;
return F_129 ( V_48 , V_204 ) ;
V_209:
F_31 ( V_47 ) ;
return V_206 ;
}
void F_130 ( struct V_4 * V_5 )
{
F_8 ( V_5 , V_11 , 1 ) ;
F_131 ( V_5 , V_11 , 1 ) ;
F_132 ( & V_5 -> V_7 . V_8 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_25 , NULL ) ;
F_133 ( V_5 -> V_7 . V_25 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_26 , NULL ) ;
F_133 ( V_5 -> V_7 . V_26 ) ;
}
int F_134 ( struct V_212 * V_213 , void * V_214 )
{
struct V_12 * V_13 = (struct V_12 * ) V_213 -> V_215 ;
struct V_4 * V_5 = F_11 ( V_13 ) ;
struct V_60 * V_61 = V_5 -> V_62 ;
struct V_203 * V_216 ;
struct V_63 * V_64 ;
struct V_14 * V_35 ;
struct V_40 * V_41 ;
int V_65 ;
V_216 = F_135 ( V_213 ) ;
if ( ! V_216 )
goto V_93;
for ( V_65 = 0 ; V_65 < V_61 -> V_66 ; V_65 ++ ) {
V_64 = & V_61 -> V_67 [ V_65 ] ;
F_47 () ;
F_48 (orig_node, head, hash_entry) {
if ( F_53 ( & V_35 -> V_36 ) &&
F_53 ( & V_35 -> V_37 ) )
continue;
F_136 ( V_213 , L_7 , V_35 -> V_15 ) ;
F_137 ( V_213 , L_8 ) ;
F_79 (nc_node,
&orig_node->in_coding_list,
list)
F_136 ( V_213 , L_9 ,
V_41 -> V_59 ) ;
F_137 ( V_213 , L_10 ) ;
F_137 ( V_213 , L_11 ) ;
F_79 (nc_node,
&orig_node->out_coding_list,
list)
F_136 ( V_213 , L_9 ,
V_41 -> V_59 ) ;
F_137 ( V_213 , L_12 ) ;
}
F_49 () ;
}
V_93:
if ( V_216 )
F_138 ( V_216 ) ;
return 0 ;
}
int F_139 ( struct V_4 * V_5 )
{
struct V_217 * V_218 , * V_219 ;
V_218 = F_140 ( L_13 , V_5 -> V_220 ) ;
if ( ! V_218 )
goto V_93;
V_219 = F_141 ( L_14 , V_221 | V_222 , V_218 ,
& V_5 -> V_7 . V_32 ) ;
if ( ! V_219 )
goto V_93;
V_219 = F_142 ( L_15 , V_221 | V_222 , V_218 ,
& V_5 -> V_7 . V_33 ) ;
if ( ! V_219 )
goto V_93;
V_219 = F_142 ( L_16 , V_221 | V_222 , V_218 ,
& V_5 -> V_7 . V_34 ) ;
if ( ! V_219 )
goto V_93;
return 0 ;
V_93:
return - V_31 ;
}
