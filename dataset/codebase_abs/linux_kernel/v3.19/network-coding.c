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
void * V_17 ,
T_3 V_18 )
{
if ( V_16 & V_19 )
V_15 -> V_20 &= ~ V_21 ;
else
V_15 -> V_20 |= V_21 ;
}
int F_13 ( struct V_4 * V_5 )
{
V_5 -> V_7 . V_22 = V_23 ;
V_5 -> V_7 . V_24 = V_23 ;
if ( V_5 -> V_7 . V_25 || V_5 -> V_7 . V_26 )
return 0 ;
V_5 -> V_7 . V_25 = F_14 ( 128 ) ;
if ( ! V_5 -> V_7 . V_25 )
goto V_27;
F_15 ( V_5 -> V_7 . V_25 ,
& V_28 ) ;
V_5 -> V_7 . V_26 = F_14 ( 128 ) ;
if ( ! V_5 -> V_7 . V_26 )
goto V_27;
F_15 ( V_5 -> V_7 . V_26 ,
& V_29 ) ;
F_16 ( & V_5 -> V_7 . V_8 , V_30 ) ;
F_3 ( V_5 ) ;
F_17 ( V_5 , F_12 ,
NULL , V_11 , 1 ,
V_19 ) ;
F_6 ( V_5 ) ;
return 0 ;
V_27:
return - V_31 ;
}
void F_18 ( struct V_4 * V_5 )
{
F_19 ( & V_5 -> V_10 , 1 ) ;
V_5 -> V_7 . V_32 = 200 ;
V_5 -> V_7 . V_33 = 10 ;
V_5 -> V_7 . V_34 = 200 ;
}
void F_20 ( struct V_14 * V_35 )
{
F_21 ( & V_35 -> V_36 ) ;
F_21 ( & V_35 -> V_37 ) ;
F_22 ( & V_35 -> V_38 ) ;
F_22 ( & V_35 -> V_39 ) ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
V_43 = F_24 ( V_41 , struct V_42 , V_41 ) ;
F_25 ( V_43 -> V_35 ) ;
F_26 ( V_43 ) ;
}
static void F_27 ( struct V_42 * V_43 )
{
if ( F_28 ( & V_43 -> V_44 ) )
F_29 ( & V_43 -> V_41 , F_23 ) ;
}
static void F_30 ( struct V_45 * V_46 )
{
if ( F_28 ( & V_46 -> V_44 ) )
F_31 ( V_46 , V_41 ) ;
}
static void F_32 ( struct V_47 * V_48 )
{
if ( V_48 -> V_49 )
F_33 ( V_48 -> V_49 ) ;
F_30 ( V_48 -> V_46 ) ;
F_26 ( V_48 ) ;
}
static bool F_34 ( struct V_4 * V_5 ,
struct V_42 * V_43 )
{
if ( F_7 ( & V_5 -> V_50 ) != V_51 )
return true ;
return F_35 ( V_43 -> V_52 , V_53 ) ;
}
static bool F_36 ( struct V_4 * V_5 ,
struct V_45 * V_46 )
{
if ( F_7 ( & V_5 -> V_50 ) != V_51 )
return true ;
return F_35 ( V_46 -> V_54 ,
V_5 -> V_7 . V_33 * 10 ) ;
}
static bool F_37 ( struct V_4 * V_5 ,
struct V_45 * V_46 )
{
if ( F_7 ( & V_5 -> V_50 ) != V_51 )
return true ;
return F_35 ( V_46 -> V_54 ,
V_5 -> V_7 . V_34 * 10 ) ;
}
static void
F_38 ( struct V_4 * V_5 ,
struct V_55 * V_56 ,
T_4 * V_57 ,
bool (* F_39)( struct V_4 * ,
struct V_42 * ) )
{
struct V_42 * V_43 , * V_58 ;
F_40 ( V_57 ) ;
F_41 (nc_node, nc_node_tmp, list, list) {
if ( F_39 && ! F_39 ( V_5 , V_43 ) )
continue;
F_42 ( V_59 , V_5 ,
L_1 ,
V_43 -> V_60 , V_43 -> V_35 -> V_15 ) ;
F_43 ( & V_43 -> V_56 ) ;
F_27 ( V_43 ) ;
}
F_44 ( V_57 ) ;
}
void F_45 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
bool (* F_39)( struct V_4 * ,
struct V_42 * ) )
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
struct V_61 * V_62 = V_5 -> V_63 ;
struct V_64 * V_65 ;
struct V_14 * V_35 ;
T_5 V_66 ;
if ( ! V_62 )
return;
for ( V_66 = 0 ; V_66 < V_62 -> V_67 ; V_66 ++ ) {
V_65 = & V_62 -> V_68 [ V_66 ] ;
F_47 () ;
F_48 (orig_node, head, hash_entry)
F_45 ( V_5 , V_35 ,
F_34 ) ;
F_49 () ;
}
}
static void F_50 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
bool (* F_39)( struct V_4 * ,
struct V_45 * ) )
{
struct V_64 * V_65 ;
struct V_69 * V_70 ;
struct V_45 * V_46 ;
T_4 * V_57 ;
T_5 V_66 ;
for ( V_66 = 0 ; V_66 < V_62 -> V_67 ; V_66 ++ ) {
V_65 = & V_62 -> V_68 [ V_66 ] ;
V_57 = & V_62 -> V_71 [ V_66 ] ;
F_40 ( V_57 ) ;
F_51 (nc_path, node_tmp, head, hash_entry) {
if ( F_39 && ! F_39 ( V_5 , V_46 ) )
continue;
if ( ! F_52 ( F_53 ( & V_46 -> V_72 ) ) ) {
F_54 ( V_73 ,
V_74
L_2 ,
V_46 -> V_75 ,
V_46 -> V_76 ) ;
continue;
}
F_42 ( V_59 , V_5 ,
L_3 ,
V_46 -> V_75 , V_46 -> V_76 ) ;
F_55 ( & V_46 -> V_77 ) ;
F_30 ( V_46 ) ;
}
F_44 ( V_57 ) ;
}
}
static void F_56 ( struct V_45 * V_78 , const char * V_79 ,
const char * V_80 )
{
memcpy ( V_78 -> V_75 , V_79 , sizeof( V_78 -> V_75 ) ) ;
memcpy ( V_78 -> V_76 , V_80 , sizeof( V_78 -> V_76 ) ) ;
}
static T_5 F_57 ( const void * V_81 , T_5 V_67 )
{
const struct V_45 * V_46 = V_81 ;
T_5 V_62 = 0 ;
V_62 = F_58 ( V_62 , & V_46 -> V_75 ,
sizeof( V_46 -> V_75 ) ) ;
V_62 = F_58 ( V_62 , & V_46 -> V_76 ,
sizeof( V_46 -> V_76 ) ) ;
V_62 += ( V_62 << 3 ) ;
V_62 ^= ( V_62 >> 11 ) ;
V_62 += ( V_62 << 15 ) ;
return V_62 % V_67 ;
}
static int F_59 ( const struct V_69 * V_82 ,
const void * V_83 )
{
const struct V_45 * V_84 , * V_85 ;
V_84 = F_24 ( V_82 , struct V_45 , V_77 ) ;
V_85 = V_83 ;
if ( memcmp ( V_84 -> V_75 , V_85 -> V_75 ,
sizeof( V_84 -> V_75 ) ) != 0 )
return 0 ;
if ( memcmp ( V_84 -> V_76 , V_85 -> V_76 ,
sizeof( V_84 -> V_76 ) ) != 0 )
return 0 ;
return 1 ;
}
static struct V_45 *
F_60 ( struct V_61 * V_62 ,
void * V_81 )
{
struct V_64 * V_65 ;
struct V_45 * V_46 , * V_86 = NULL ;
int V_87 ;
if ( ! V_62 )
return NULL ;
V_87 = F_57 ( V_81 , V_62 -> V_67 ) ;
V_65 = & V_62 -> V_68 [ V_87 ] ;
F_47 () ;
F_48 (nc_path, head, hash_entry) {
if ( ! F_59 ( & V_46 -> V_77 , V_81 ) )
continue;
if ( ! F_61 ( & V_46 -> V_44 ) )
continue;
V_86 = V_46 ;
break;
}
F_49 () ;
return V_86 ;
}
static void F_62 ( struct V_47 * V_48 )
{
F_63 ( V_48 -> V_49 ,
V_48 -> V_88 -> V_89 ,
V_48 -> V_46 -> V_76 ) ;
V_48 -> V_49 = NULL ;
F_32 ( V_48 ) ;
}
static bool F_64 ( struct V_4 * V_5 ,
struct V_45 * V_46 ,
struct V_47 * V_48 )
{
unsigned long V_90 = V_5 -> V_7 . V_34 ;
bool V_91 = false ;
if ( F_7 ( & V_5 -> V_50 ) == V_51 &&
! F_35 ( V_48 -> V_92 , V_90 ) )
goto V_93;
F_65 ( & V_48 -> V_56 ) ;
F_32 ( V_48 ) ;
V_91 = true ;
V_93:
return V_91 ;
}
static bool F_66 ( struct V_4 * V_5 ,
struct V_45 * V_46 ,
struct V_47 * V_48 )
{
unsigned long V_90 = V_5 -> V_7 . V_33 ;
if ( F_7 ( & V_5 -> V_50 ) == V_51 &&
! F_35 ( V_48 -> V_92 , V_90 ) )
return false ;
F_67 ( V_5 , V_94 ) ;
F_68 ( V_5 , V_95 ,
V_48 -> V_49 -> V_96 + V_97 ) ;
F_65 ( & V_48 -> V_56 ) ;
F_62 ( V_48 ) ;
return true ;
}
static void
F_69 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
bool (* F_70)( struct V_4 * ,
struct V_45 * ,
struct V_47 * ) )
{
struct V_64 * V_65 ;
struct V_47 * V_48 , * V_98 ;
struct V_45 * V_46 ;
bool V_1 ;
int V_66 ;
if ( ! V_62 )
return;
for ( V_66 = 0 ; V_66 < V_62 -> V_67 ; V_66 ++ ) {
V_65 = & V_62 -> V_68 [ V_66 ] ;
F_47 () ;
F_48 (nc_path, head, hash_entry) {
F_40 ( & V_46 -> V_99 ) ;
F_41 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_1 = F_70 ( V_5 , V_46 , V_48 ) ;
if ( ! V_1 )
break;
}
F_44 ( & V_46 -> V_99 ) ;
}
F_49 () ;
}
}
static void V_30 ( struct V_100 * V_8 )
{
struct V_101 * V_101 ;
struct V_102 * V_103 ;
struct V_4 * V_5 ;
unsigned long V_90 ;
V_101 = F_24 ( V_8 , struct V_101 , V_8 ) ;
V_103 = F_24 ( V_101 , struct V_102 , V_8 ) ;
V_5 = F_24 ( V_103 , struct V_4 , V_7 ) ;
F_46 ( V_5 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_25 ,
F_36 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_26 ,
F_37 ) ;
V_90 = V_5 -> V_7 . V_33 ;
if ( F_35 ( V_5 -> V_7 . V_22 , V_90 ) ) {
F_69 ( V_5 , V_5 -> V_7 . V_25 ,
F_66 ) ;
V_5 -> V_7 . V_22 = V_23 ;
}
if ( F_35 ( V_5 -> V_7 . V_24 ,
V_5 -> V_7 . V_34 ) ) {
F_69 ( V_5 , V_5 -> V_7 . V_26 ,
F_64 ) ;
V_5 -> V_7 . V_24 = V_23 ;
}
F_3 ( V_5 ) ;
}
static bool F_71 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 ;
T_5 V_108 ;
T_2 V_109 ;
V_107 = F_72 ( V_35 , V_110 ) ;
if ( ! V_107 )
return false ;
V_109 = V_107 -> V_109 ;
V_108 = V_107 -> V_108 ;
F_73 ( V_107 ) ;
if ( V_108 != F_74 ( V_105 -> V_111 ) )
return false ;
if ( V_109 != V_105 -> V_112 + 1 )
return false ;
if ( ! F_75 ( V_105 -> V_15 , V_105 -> V_113 ) )
return false ;
if ( V_105 -> V_114 < V_5 -> V_7 . V_32 )
return false ;
return true ;
}
static struct V_42
* F_76 ( struct V_14 * V_35 ,
struct V_14 * V_115 ,
bool V_116 )
{
struct V_42 * V_43 , * V_117 = NULL ;
struct V_55 * V_56 ;
if ( V_116 )
V_56 = & V_115 -> V_36 ;
else
V_56 = & V_115 -> V_37 ;
F_47 () ;
F_77 (nc_node, list, list) {
if ( ! F_75 ( V_43 -> V_60 , V_35 -> V_15 ) )
continue;
if ( ! F_61 ( & V_43 -> V_44 ) )
continue;
V_117 = V_43 ;
break;
}
F_49 () ;
return V_117 ;
}
static struct V_42
* F_78 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_115 ,
bool V_116 )
{
struct V_42 * V_43 ;
T_4 * V_57 ;
struct V_55 * V_56 ;
V_43 = F_76 ( V_35 , V_115 , V_116 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_79 ( sizeof( * V_43 ) , V_118 ) ;
if ( ! V_43 )
return NULL ;
if ( ! F_61 ( & V_115 -> V_44 ) )
goto free;
F_21 ( & V_43 -> V_56 ) ;
F_80 ( V_43 -> V_60 , V_35 -> V_15 ) ;
V_43 -> V_35 = V_115 ;
F_19 ( & V_43 -> V_44 , 2 ) ;
if ( V_116 ) {
V_57 = & V_115 -> V_38 ;
V_56 = & V_115 -> V_36 ;
} else {
V_57 = & V_115 -> V_39 ;
V_56 = & V_115 -> V_37 ;
}
F_42 ( V_59 , V_5 , L_4 ,
V_43 -> V_60 , V_43 -> V_35 -> V_15 ) ;
F_40 ( V_57 ) ;
F_81 ( & V_43 -> V_56 , V_56 ) ;
F_44 ( V_57 ) ;
return V_43 ;
free:
F_26 ( V_43 ) ;
return NULL ;
}
void F_82 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_115 ,
struct V_104 * V_105 ,
int V_119 )
{
struct V_42 * V_120 = NULL , * V_121 = NULL ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
if ( ! ( V_35 -> V_20 & V_21 ) )
goto V_93;
if ( ! F_71 ( V_5 , V_35 , V_105 ) &&
! V_119 )
goto V_93;
V_120 = F_78 ( V_5 , V_35 ,
V_115 , true ) ;
if ( ! V_120 )
goto V_93;
V_120 -> V_52 = V_23 ;
V_121 = F_78 ( V_5 , V_115 ,
V_35 , false ) ;
if ( ! V_121 )
goto V_93;
V_121 -> V_52 = V_23 ;
V_93:
if ( V_120 )
F_27 ( V_120 ) ;
if ( V_121 )
F_27 ( V_121 ) ;
}
static struct V_45 * F_83 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_2 * V_79 ,
T_2 * V_80 )
{
int V_122 ;
struct V_45 * V_46 , V_123 ;
F_56 ( & V_123 , V_79 , V_80 ) ;
V_46 = F_60 ( V_62 , ( void * ) & V_123 ) ;
if ( V_46 ) {
V_46 -> V_54 = V_23 ;
return V_46 ;
}
V_46 = F_79 ( sizeof( * V_46 ) , V_118 ) ;
if ( ! V_46 )
return NULL ;
F_21 ( & V_46 -> V_72 ) ;
F_22 ( & V_46 -> V_99 ) ;
F_19 ( & V_46 -> V_44 , 2 ) ;
V_46 -> V_54 = V_23 ;
F_80 ( V_46 -> V_76 , V_80 ) ;
F_80 ( V_46 -> V_75 , V_79 ) ;
F_42 ( V_59 , V_5 , L_5 ,
V_46 -> V_75 ,
V_46 -> V_76 ) ;
V_122 = F_84 ( V_62 , F_59 ,
F_57 , & V_123 ,
& V_46 -> V_77 ) ;
if ( V_122 < 0 ) {
F_26 ( V_46 ) ;
return NULL ;
}
return V_46 ;
}
static T_2 F_85 ( T_2 V_114 )
{
T_2 V_124 , V_125 ;
F_86 ( & V_124 , sizeof( V_124 ) ) ;
V_125 = V_124 * ( V_126 - V_114 ) ;
V_125 /= V_126 ;
return V_126 - V_125 ;
}
static void F_87 ( char * V_80 , const char * V_79 , unsigned int V_96 )
{
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_96 ; ++ V_66 )
V_80 [ V_66 ] ^= V_79 [ V_66 ] ;
}
static bool F_88 ( struct V_4 * V_5 ,
struct V_127 * V_49 ,
struct V_128 * V_128 ,
struct V_47 * V_48 ,
struct V_129 * V_88 )
{
T_2 V_130 , V_131 , V_132 ;
struct V_127 * V_133 , * V_134 ;
struct V_135 * V_136 ;
struct V_135 * V_137 ;
struct V_138 * V_139 ;
struct V_129 * V_140 , * V_141 ;
struct V_129 * V_142 = NULL ;
struct V_143 * V_144 = NULL ;
struct V_143 * V_145 = NULL ;
T_2 * V_146 , * V_147 , * V_148 , * V_149 ;
T_6 V_150 , V_151 ;
T_7 V_152 ;
bool V_91 = false ;
int V_153 ;
int V_154 = sizeof( * V_136 ) ;
int V_155 = sizeof( * V_139 ) ;
int V_156 = V_155 - V_154 ;
V_141 = F_89 ( V_88 -> V_35 ,
V_110 ) ;
if ( ! V_141 )
goto V_93;
V_144 = F_90 ( V_141 ,
V_110 ) ;
if ( ! V_144 )
goto V_93;
V_140 = V_48 -> V_88 ;
V_142 = F_89 ( V_140 -> V_35 ,
V_110 ) ;
if ( ! V_142 )
goto V_93;
V_145 = F_90 ( V_142 ,
V_110 ) ;
if ( ! V_145 )
goto V_93;
V_132 = V_144 -> V_157 . V_158 ;
V_130 = F_85 ( V_132 ) ;
V_132 = V_145 -> V_157 . V_158 ;
V_131 = F_85 ( V_132 ) ;
if ( V_130 >= V_131 ) {
V_147 = V_48 -> V_46 -> V_76 ;
V_146 = V_48 -> V_46 -> V_75 ;
V_149 = V_88 -> V_60 ;
V_148 = V_128 -> V_159 ;
V_136 = (struct V_135 * ) V_48 -> V_49 -> V_81 ;
V_137 = (struct V_135 * ) V_49 -> V_81 ;
V_150 = V_48 -> V_160 ;
V_151 = F_91 ( V_49 ,
V_49 -> V_81 + sizeof( * V_137 ) ) ;
} else {
V_147 = V_88 -> V_60 ;
V_146 = V_128 -> V_159 ;
V_149 = V_48 -> V_46 -> V_76 ;
V_148 = V_48 -> V_46 -> V_75 ;
V_136 = (struct V_135 * ) V_49 -> V_81 ;
V_137 = (struct V_135 * ) V_48 -> V_49 -> V_81 ;
V_150 = F_91 ( V_49 ,
V_49 -> V_81 + sizeof( * V_136 ) ) ;
V_151 = V_48 -> V_160 ;
}
if ( V_49 -> V_96 <= V_48 -> V_49 -> V_96 ) {
V_133 = V_48 -> V_49 ;
V_134 = V_49 ;
} else {
V_133 = V_49 ;
V_134 = V_48 -> V_49 ;
}
V_153 = V_134 -> V_96 - V_154 ;
if ( F_92 ( V_133 ) < 0 || F_92 ( V_134 ) < 0 )
goto V_93;
F_93 ( V_133 , V_156 ) ;
V_139 = (struct V_138 * ) V_133 -> V_81 ;
F_94 ( V_133 ) ;
V_139 -> V_161 = V_2 ;
V_139 -> V_162 = V_163 ;
V_139 -> V_112 = V_136 -> V_112 ;
F_80 ( V_139 -> V_146 , V_146 ) ;
F_80 ( V_139 -> V_164 , V_136 -> V_165 ) ;
V_139 -> V_166 = V_150 ;
V_139 -> V_167 = V_136 -> V_168 ;
F_80 ( V_139 -> V_149 , V_149 ) ;
F_80 ( V_139 -> V_148 , V_148 ) ;
F_80 ( V_139 -> V_169 , V_137 -> V_165 ) ;
V_139 -> V_170 = V_151 ;
V_139 -> V_171 = V_137 -> V_112 ;
V_139 -> V_172 = V_137 -> V_168 ;
V_139 -> V_173 = F_95 ( V_153 ) ;
F_87 ( V_133 -> V_81 + V_155 ,
V_134 -> V_81 + V_154 , V_153 ) ;
if ( F_96 ( V_134 ) -> V_174 &&
F_96 ( V_133 ) -> V_174 ) {
V_152 = V_134 -> V_96 + V_97 ;
V_152 += V_133 -> V_96 + V_97 ;
F_68 ( V_5 , V_175 , 2 ) ;
F_68 ( V_5 , V_176 , V_152 ) ;
} else if ( ! F_96 ( V_134 ) -> V_174 &&
! F_96 ( V_133 ) -> V_174 ) {
V_152 = V_134 -> V_96 + V_97 ;
V_152 += V_133 -> V_96 + V_97 ;
F_68 ( V_5 , V_177 , 2 ) ;
F_68 ( V_5 , V_178 , V_152 ) ;
} else if ( F_96 ( V_134 ) -> V_174 &&
! F_96 ( V_133 ) -> V_174 ) {
F_67 ( V_5 , V_175 ) ;
F_68 ( V_5 , V_176 ,
V_134 -> V_96 + V_97 ) ;
F_67 ( V_5 , V_177 ) ;
F_68 ( V_5 , V_178 ,
V_133 -> V_96 + V_97 ) ;
} else if ( ! F_96 ( V_134 ) -> V_174 &&
F_96 ( V_133 ) -> V_174 ) {
F_67 ( V_5 , V_177 ) ;
F_68 ( V_5 , V_178 ,
V_134 -> V_96 + V_97 ) ;
F_67 ( V_5 , V_175 ) ;
F_68 ( V_5 , V_176 ,
V_133 -> V_96 + V_97 ) ;
}
F_33 ( V_134 ) ;
V_48 -> V_49 = NULL ;
F_32 ( V_48 ) ;
F_63 ( V_133 , V_88 -> V_89 , V_147 ) ;
V_91 = true ;
V_93:
if ( V_141 )
F_97 ( V_141 ) ;
if ( V_142 )
F_97 ( V_142 ) ;
if ( V_144 )
F_98 ( V_144 ) ;
if ( V_145 )
F_98 ( V_145 ) ;
return V_91 ;
}
static bool F_99 ( struct V_127 * V_49 ,
T_2 * V_80 , T_2 * V_79 )
{
if ( F_96 ( V_49 ) -> V_174 && ! F_75 ( V_80 , V_79 ) )
return false ;
else
return true ;
}
static struct V_47 *
F_100 ( struct V_4 * V_5 ,
struct V_42 * V_120 ,
struct V_42 * V_121 ,
struct V_127 * V_49 ,
T_2 * V_179 )
{
struct V_45 * V_46 , V_123 ;
struct V_47 * V_180 = NULL ;
struct V_47 * V_48 , * V_98 ;
struct V_61 * V_62 = V_5 -> V_7 . V_25 ;
int V_181 ;
if ( ! V_62 )
return NULL ;
F_56 ( & V_123 , V_120 -> V_60 ,
V_121 -> V_60 ) ;
V_181 = F_57 ( & V_123 , V_62 -> V_67 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_75 ( V_46 -> V_75 , V_120 -> V_60 ) )
continue;
if ( ! F_75 ( V_46 -> V_76 , V_121 -> V_60 ) )
continue;
F_40 ( & V_46 -> V_99 ) ;
if ( F_53 ( & V_46 -> V_72 ) ) {
F_44 ( & V_46 -> V_99 ) ;
continue;
}
F_41 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_99 ( V_48 -> V_49 ,
V_179 ,
V_120 -> V_60 ) )
continue;
F_65 ( & V_48 -> V_56 ) ;
V_180 = V_48 ;
break;
}
F_44 ( & V_46 -> V_99 ) ;
break;
}
F_49 () ;
return V_180 ;
}
static struct V_47 *
F_101 ( struct V_4 * V_5 ,
struct V_127 * V_49 ,
T_2 * V_179 ,
T_2 * V_182 ,
struct V_42 * V_120 )
{
struct V_14 * V_35 ;
struct V_42 * V_121 ;
struct V_47 * V_48 = NULL ;
V_35 = F_102 ( V_5 , V_182 ) ;
if ( ! V_35 )
return NULL ;
F_47 () ;
F_77 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_99 ( V_49 ,
V_121 -> V_60 , V_182 ) )
continue;
V_48 = F_100 ( V_5 , V_120 ,
V_121 , V_49 , V_179 ) ;
if ( V_48 )
break;
}
F_49 () ;
F_25 ( V_35 ) ;
return V_48 ;
}
static void F_103 ( struct V_4 * V_5 ,
struct V_127 * V_49 ,
T_2 * V_183 )
{
struct V_128 * V_128 ;
V_49 = F_104 ( V_49 , V_118 ) ;
if ( ! V_49 )
return;
V_128 = F_105 ( V_49 ) ;
F_80 ( V_128 -> V_159 , V_128 -> V_184 ) ;
F_80 ( V_128 -> V_184 , V_183 ) ;
F_93 ( V_49 , V_97 ) ;
F_106 ( V_5 , V_49 ) ;
F_33 ( V_49 ) ;
}
static bool F_107 ( struct V_127 * V_49 ,
struct V_129 * V_88 ,
struct V_128 * V_128 )
{
struct V_12 * V_185 = V_88 -> V_89 -> V_186 ;
struct V_4 * V_5 = F_11 ( V_185 ) ;
struct V_14 * V_35 = V_88 -> V_35 ;
struct V_42 * V_43 ;
struct V_47 * V_48 = NULL ;
F_47 () ;
F_77 (nc_node, &orig_node->in_coding_list, list) {
V_48 = F_101 ( V_5 , V_49 ,
V_88 -> V_60 ,
V_128 -> V_159 , V_43 ) ;
if ( V_48 )
break;
}
F_49 () ;
if ( ! V_48 )
return false ;
F_103 ( V_5 , V_49 ,
V_88 -> V_60 ) ;
F_103 ( V_5 , V_48 -> V_49 ,
V_48 -> V_88 -> V_60 ) ;
if ( F_88 ( V_5 , V_49 , V_128 , V_48 ,
V_88 ) )
return true ;
F_62 ( V_48 ) ;
return false ;
}
static bool F_108 ( struct V_127 * V_49 ,
struct V_45 * V_46 ,
struct V_129 * V_88 ,
T_6 V_160 )
{
struct V_47 * V_48 ;
V_48 = F_79 ( sizeof( * V_48 ) , V_118 ) ;
if ( ! V_48 )
return false ;
V_48 -> V_92 = V_23 ;
V_48 -> V_160 = V_160 ;
V_48 -> V_49 = V_49 ;
V_48 -> V_88 = V_88 ;
V_48 -> V_46 = V_46 ;
F_40 ( & V_46 -> V_99 ) ;
F_109 ( & V_48 -> V_56 , & V_46 -> V_72 ) ;
F_44 ( & V_46 -> V_99 ) ;
return true ;
}
bool F_110 ( struct V_127 * V_49 ,
struct V_129 * V_88 )
{
const struct V_12 * V_185 = V_88 -> V_89 -> V_186 ;
struct V_4 * V_5 = F_11 ( V_185 ) ;
struct V_135 * V_187 ;
struct V_45 * V_46 ;
struct V_128 * V_128 = F_105 ( V_49 ) ;
T_6 V_160 ;
T_8 * V_188 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_188 = F_111 ( V_49 ) ;
V_187 = (struct V_135 * ) V_188 ;
if ( V_187 -> V_161 != V_189 )
goto V_93;
if ( F_107 ( V_49 , V_88 , V_128 ) )
return true ;
V_46 = F_83 ( V_5 ,
V_5 -> V_7 . V_25 ,
V_128 -> V_159 ,
V_88 -> V_60 ) ;
if ( ! V_46 )
goto V_93;
V_160 = F_91 ( V_49 , V_188 + sizeof( * V_187 ) ) ;
if ( ! F_108 ( V_49 , V_46 , V_88 , V_160 ) )
goto V_190;
return true ;
V_190:
F_30 ( V_46 ) ;
V_93:
return false ;
}
void F_106 ( struct V_4 * V_5 ,
struct V_127 * V_49 )
{
struct V_135 * V_187 ;
struct V_45 * V_46 ;
struct V_128 * V_128 = F_105 ( V_49 ) ;
T_6 V_160 ;
T_8 * V_188 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_188 = F_111 ( V_49 ) ;
V_187 = (struct V_135 * ) V_188 ;
if ( V_187 -> V_161 != V_189 )
goto V_93;
V_46 = F_83 ( V_5 ,
V_5 -> V_7 . V_26 ,
V_128 -> V_159 ,
V_128 -> V_184 ) ;
if ( ! V_46 )
goto V_93;
V_49 = F_112 ( V_49 , V_118 ) ;
if ( F_52 ( ! V_49 ) )
goto V_190;
if ( F_52 ( ! F_113 ( V_49 , V_97 ) ) )
goto V_191;
if ( F_52 ( ! F_114 ( V_49 , V_97 ) ) )
goto V_191;
V_160 = F_91 ( V_49 , V_188 + sizeof( * V_187 ) ) ;
if ( ! F_108 ( V_49 , V_46 , NULL , V_160 ) )
goto V_191;
F_67 ( V_5 , V_192 ) ;
return;
V_191:
F_33 ( V_49 ) ;
V_190:
F_30 ( V_46 ) ;
V_93:
return;
}
void F_115 ( struct V_4 * V_5 ,
struct V_127 * V_49 )
{
struct V_128 * V_128 = F_105 ( V_49 ) ;
if ( F_116 ( V_5 , V_128 -> V_184 ) )
return;
F_93 ( V_49 , V_97 ) ;
F_106 ( V_5 , V_49 ) ;
}
static struct V_135 *
F_117 ( struct V_4 * V_5 , struct V_127 * V_49 ,
struct V_47 * V_48 )
{
const int V_193 = sizeof( struct V_135 ) ;
const int V_194 = sizeof( struct V_138 ) - V_193 ;
struct V_135 * V_195 ;
struct V_138 V_196 ;
struct V_128 * V_128 , V_197 ;
T_2 * V_198 , V_112 , V_168 ;
unsigned int V_153 ;
int V_27 ;
memcpy ( & V_196 , V_49 -> V_81 , sizeof( V_196 ) ) ;
memcpy ( & V_197 , F_118 ( V_49 ) , sizeof( V_197 ) ) ;
if ( F_119 ( V_49 , 0 ) < 0 )
return NULL ;
if ( F_52 ( ! F_114 ( V_49 , V_194 ) ) )
return NULL ;
F_120 ( V_49 , - V_97 ) ;
F_121 ( V_49 ) ;
V_128 = F_105 ( V_49 ) ;
* V_128 = V_197 ;
if ( F_116 ( V_5 , V_196 . V_149 ) ) {
F_80 ( V_128 -> V_184 , V_196 . V_149 ) ;
V_49 -> V_199 = V_200 ;
V_198 = V_196 . V_169 ;
V_112 = V_196 . V_171 ;
V_168 = V_196 . V_172 ;
} else {
V_198 = V_196 . V_164 ;
V_112 = V_196 . V_112 ;
V_168 = V_196 . V_167 ;
}
V_153 = F_122 ( V_196 . V_173 ) ;
if ( V_153 > V_49 -> V_96 )
return NULL ;
F_87 ( V_49 -> V_81 + V_193 ,
V_48 -> V_49 -> V_81 + V_193 ,
V_153 ) ;
if ( V_48 -> V_49 -> V_96 > V_153 + V_193 ) {
V_27 = F_123 ( V_49 , V_153 + V_193 ) ;
if ( V_27 )
return NULL ;
}
V_195 = (struct V_135 * ) V_49 -> V_81 ;
V_195 -> V_161 = V_189 ;
V_195 -> V_162 = V_163 ;
V_195 -> V_112 = V_112 ;
F_80 ( V_195 -> V_165 , V_198 ) ;
V_195 -> V_168 = V_168 ;
F_32 ( V_48 ) ;
return V_195 ;
}
static struct V_47 *
F_124 ( struct V_4 * V_5 ,
struct V_128 * V_128 ,
struct V_138 * V_201 )
{
struct V_61 * V_62 = V_5 -> V_7 . V_26 ;
struct V_47 * V_202 , * V_48 = NULL ;
struct V_45 * V_46 , V_123 ;
T_2 * V_165 , * V_203 ;
T_6 V_160 ;
int V_87 ;
if ( ! V_62 )
return NULL ;
V_165 = V_128 -> V_159 ;
if ( ! F_116 ( V_5 , V_201 -> V_149 ) ) {
V_203 = V_201 -> V_148 ;
V_160 = V_201 -> V_170 ;
} else {
V_203 = V_201 -> V_146 ;
V_160 = V_201 -> V_166 ;
}
F_56 ( & V_123 , V_203 , V_165 ) ;
V_87 = F_57 ( & V_123 , V_62 -> V_67 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[index], hash_entry) {
F_40 ( & V_46 -> V_99 ) ;
F_125 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_160 == V_202 -> V_160 ) {
F_65 ( & V_202 -> V_56 ) ;
V_48 = V_202 ;
break;
}
}
F_44 ( & V_46 -> V_99 ) ;
if ( V_48 )
break;
}
F_49 () ;
if ( ! V_48 )
F_42 ( V_59 , V_5 ,
L_6 , V_160 ) ;
return V_48 ;
}
static int V_3 ( struct V_127 * V_49 ,
struct V_204 * V_205 )
{
struct V_4 * V_5 = F_11 ( V_205 -> V_186 ) ;
struct V_135 * V_195 ;
struct V_138 * V_139 ;
struct V_47 * V_48 ;
struct V_128 * V_128 ;
int V_206 = sizeof( * V_139 ) ;
if ( ! F_7 ( & V_5 -> V_10 ) )
return V_207 ;
if ( F_52 ( ! F_113 ( V_49 , V_206 ) ) )
return V_207 ;
V_139 = (struct V_138 * ) V_49 -> V_81 ;
V_128 = F_105 ( V_49 ) ;
if ( ! F_116 ( V_5 , V_128 -> V_184 ) &&
! F_116 ( V_5 , V_139 -> V_149 ) )
return V_207 ;
if ( F_116 ( V_5 , V_139 -> V_149 ) )
F_67 ( V_5 , V_208 ) ;
V_48 = F_124 ( V_5 , V_128 ,
V_139 ) ;
if ( ! V_48 ) {
F_67 ( V_5 , V_209 ) ;
return V_207 ;
}
if ( F_92 ( V_49 ) < 0 )
goto V_210;
if ( F_92 ( V_48 -> V_49 ) < 0 )
goto V_210;
V_195 = F_117 ( V_5 , V_49 , V_48 ) ;
if ( ! V_195 ) {
F_67 ( V_5 , V_209 ) ;
goto V_210;
}
F_96 ( V_49 ) -> V_174 = true ;
F_67 ( V_5 , V_211 ) ;
F_68 ( V_5 , V_212 ,
V_49 -> V_96 + V_97 ) ;
return F_126 ( V_49 , V_205 ) ;
V_210:
F_32 ( V_48 ) ;
return V_207 ;
}
void F_127 ( struct V_4 * V_5 )
{
F_8 ( V_5 , V_11 , 1 ) ;
F_128 ( V_5 , V_11 , 1 ) ;
F_129 ( & V_5 -> V_7 . V_8 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_25 , NULL ) ;
F_130 ( V_5 -> V_7 . V_25 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_26 , NULL ) ;
F_130 ( V_5 -> V_7 . V_26 ) ;
}
int F_131 ( struct V_213 * V_214 , void * V_215 )
{
struct V_12 * V_13 = (struct V_12 * ) V_214 -> V_216 ;
struct V_4 * V_5 = F_11 ( V_13 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
struct V_204 * V_217 ;
struct V_64 * V_65 ;
struct V_14 * V_35 ;
struct V_42 * V_43 ;
int V_66 ;
V_217 = F_132 ( V_214 ) ;
if ( ! V_217 )
goto V_93;
for ( V_66 = 0 ; V_66 < V_62 -> V_67 ; V_66 ++ ) {
V_65 = & V_62 -> V_68 [ V_66 ] ;
F_47 () ;
F_48 (orig_node, head, hash_entry) {
if ( F_53 ( & V_35 -> V_36 ) &&
F_53 ( & V_35 -> V_37 ) )
continue;
F_133 ( V_214 , L_7 , V_35 -> V_15 ) ;
F_134 ( V_214 , L_8 ) ;
F_77 (nc_node,
&orig_node->in_coding_list,
list)
F_133 ( V_214 , L_9 ,
V_43 -> V_60 ) ;
F_134 ( V_214 , L_10 ) ;
F_134 ( V_214 , L_11 ) ;
F_77 (nc_node,
&orig_node->out_coding_list,
list)
F_133 ( V_214 , L_9 ,
V_43 -> V_60 ) ;
F_134 ( V_214 , L_12 ) ;
}
F_49 () ;
}
V_93:
if ( V_217 )
F_135 ( V_217 ) ;
return 0 ;
}
int F_136 ( struct V_4 * V_5 )
{
struct V_218 * V_219 , * V_220 ;
V_219 = F_137 ( L_13 , V_5 -> V_221 ) ;
if ( ! V_219 )
goto V_93;
V_220 = F_138 ( L_14 , V_222 | V_223 , V_219 ,
& V_5 -> V_7 . V_32 ) ;
if ( ! V_220 )
goto V_93;
V_220 = F_139 ( L_15 , V_222 | V_223 , V_219 ,
& V_5 -> V_7 . V_33 ) ;
if ( ! V_220 )
goto V_93;
V_220 = F_139 ( L_16 , V_222 | V_223 , V_219 ,
& V_5 -> V_7 . V_34 ) ;
if ( ! V_220 )
goto V_93;
return 0 ;
V_93:
return - V_31 ;
}
