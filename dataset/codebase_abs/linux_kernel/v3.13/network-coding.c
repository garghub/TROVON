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
F_15 ( V_5 -> V_7 . V_25 ,
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
if ( V_35 -> V_106 != F_72 ( V_105 -> V_107 ) )
return false ;
if ( V_35 -> V_108 != V_105 -> V_109 + 1 )
return false ;
if ( ! F_73 ( V_105 -> V_15 , V_105 -> V_110 ) )
return false ;
if ( V_105 -> V_111 < V_5 -> V_7 . V_32 )
return false ;
return true ;
}
static struct V_42
* F_74 ( struct V_14 * V_35 ,
struct V_14 * V_112 ,
bool V_113 )
{
struct V_42 * V_43 , * V_114 = NULL ;
struct V_55 * V_56 ;
if ( V_113 )
V_56 = & V_112 -> V_36 ;
else
V_56 = & V_112 -> V_37 ;
F_47 () ;
F_75 (nc_node, list, list) {
if ( ! F_73 ( V_43 -> V_60 , V_35 -> V_15 ) )
continue;
if ( ! F_61 ( & V_43 -> V_44 ) )
continue;
V_114 = V_43 ;
break;
}
F_49 () ;
return V_114 ;
}
static struct V_42
* F_76 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_112 ,
bool V_113 )
{
struct V_42 * V_43 ;
T_4 * V_57 ;
struct V_55 * V_56 ;
V_43 = F_74 ( V_35 , V_112 , V_113 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_77 ( sizeof( * V_43 ) , V_115 ) ;
if ( ! V_43 )
return NULL ;
if ( ! F_61 ( & V_112 -> V_44 ) )
goto free;
F_21 ( & V_43 -> V_56 ) ;
memcpy ( V_43 -> V_60 , V_35 -> V_15 , V_116 ) ;
V_43 -> V_35 = V_112 ;
F_19 ( & V_43 -> V_44 , 2 ) ;
if ( V_113 ) {
V_57 = & V_112 -> V_38 ;
V_56 = & V_112 -> V_36 ;
} else {
V_57 = & V_112 -> V_39 ;
V_56 = & V_112 -> V_37 ;
}
F_42 ( V_59 , V_5 , L_4 ,
V_43 -> V_60 , V_43 -> V_35 -> V_15 ) ;
F_40 ( V_57 ) ;
F_78 ( & V_43 -> V_56 , V_56 ) ;
F_44 ( V_57 ) ;
return V_43 ;
free:
F_26 ( V_43 ) ;
return NULL ;
}
void F_79 ( struct V_4 * V_5 ,
struct V_14 * V_35 ,
struct V_14 * V_112 ,
struct V_104 * V_105 ,
int V_117 )
{
struct V_42 * V_118 = NULL , * V_119 = NULL ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
if ( ! ( V_35 -> V_20 & V_21 ) )
goto V_93;
if ( ! F_71 ( V_5 , V_35 , V_105 ) &&
! V_117 )
goto V_93;
V_118 = F_76 ( V_5 , V_35 ,
V_112 , true ) ;
if ( ! V_118 )
goto V_93;
V_118 -> V_52 = V_23 ;
V_119 = F_76 ( V_5 , V_112 ,
V_35 , false ) ;
if ( ! V_119 )
goto V_93;
V_119 -> V_52 = V_23 ;
V_93:
if ( V_118 )
F_27 ( V_118 ) ;
if ( V_119 )
F_27 ( V_119 ) ;
}
static struct V_45 * F_80 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_2 * V_79 ,
T_2 * V_80 )
{
int V_120 ;
struct V_45 * V_46 , V_121 ;
F_56 ( & V_121 , V_79 , V_80 ) ;
V_46 = F_60 ( V_62 , ( void * ) & V_121 ) ;
if ( V_46 ) {
V_46 -> V_54 = V_23 ;
return V_46 ;
}
V_46 = F_77 ( sizeof( * V_46 ) , V_115 ) ;
if ( ! V_46 )
return NULL ;
F_21 ( & V_46 -> V_72 ) ;
F_22 ( & V_46 -> V_99 ) ;
F_19 ( & V_46 -> V_44 , 2 ) ;
V_46 -> V_54 = V_23 ;
memcpy ( V_46 -> V_76 , V_80 , V_116 ) ;
memcpy ( V_46 -> V_75 , V_79 , V_116 ) ;
F_42 ( V_59 , V_5 , L_5 ,
V_46 -> V_75 ,
V_46 -> V_76 ) ;
V_120 = F_81 ( V_62 , F_59 ,
F_57 , & V_121 ,
& V_46 -> V_77 ) ;
if ( V_120 < 0 ) {
F_26 ( V_46 ) ;
return NULL ;
}
return V_46 ;
}
static T_2 F_82 ( T_2 V_111 )
{
T_2 V_122 , V_123 ;
F_83 ( & V_122 , sizeof( V_122 ) ) ;
V_123 = V_122 * ( V_124 - V_111 ) ;
V_123 /= V_124 ;
return V_124 - V_123 ;
}
static void F_84 ( char * V_80 , const char * V_79 , unsigned int V_96 )
{
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_96 ; ++ V_66 )
V_80 [ V_66 ] ^= V_79 [ V_66 ] ;
}
static bool F_85 ( struct V_4 * V_5 ,
struct V_125 * V_49 ,
struct V_126 * V_126 ,
struct V_47 * V_48 ,
struct V_127 * V_88 )
{
T_2 V_128 , V_129 , V_130 ;
struct V_125 * V_131 , * V_132 ;
struct V_133 * V_134 ;
struct V_133 * V_135 ;
struct V_136 * V_137 ;
struct V_127 * V_138 , * V_139 ;
struct V_127 * V_140 = NULL ;
T_2 * V_141 , * V_142 , * V_143 , * V_144 ;
T_6 V_145 , V_146 ;
T_7 V_147 ;
bool V_91 = false ;
int V_148 ;
int V_149 = sizeof( * V_134 ) ;
int V_150 = sizeof( * V_137 ) ;
int V_151 = V_150 - V_149 ;
V_139 = F_86 ( V_88 -> V_35 ) ;
if ( ! V_139 )
goto V_93;
V_138 = V_48 -> V_88 ;
V_140 = F_86 ( V_138 -> V_35 ) ;
if ( ! V_140 )
goto V_93;
V_130 = F_82 ( V_139 -> V_152 . V_153 ) ;
V_128 = V_130 ;
V_130 = F_82 ( V_140 -> V_152 . V_153 ) ;
V_129 = V_130 ;
if ( V_128 >= V_129 ) {
V_142 = V_48 -> V_46 -> V_76 ;
V_141 = V_48 -> V_46 -> V_75 ;
V_144 = V_88 -> V_60 ;
V_143 = V_126 -> V_154 ;
V_134 = (struct V_133 * ) V_48 -> V_49 -> V_81 ;
V_135 = (struct V_133 * ) V_49 -> V_81 ;
V_145 = V_48 -> V_155 ;
V_146 = F_87 ( V_49 ,
V_49 -> V_81 + sizeof( * V_135 ) ) ;
} else {
V_142 = V_88 -> V_60 ;
V_141 = V_126 -> V_154 ;
V_144 = V_48 -> V_46 -> V_76 ;
V_143 = V_48 -> V_46 -> V_75 ;
V_134 = (struct V_133 * ) V_49 -> V_81 ;
V_135 = (struct V_133 * ) V_48 -> V_49 -> V_81 ;
V_145 = F_87 ( V_49 ,
V_49 -> V_81 + sizeof( * V_134 ) ) ;
V_146 = V_48 -> V_155 ;
}
if ( V_49 -> V_96 <= V_48 -> V_49 -> V_96 ) {
V_131 = V_48 -> V_49 ;
V_132 = V_49 ;
} else {
V_131 = V_49 ;
V_132 = V_48 -> V_49 ;
}
V_148 = V_132 -> V_96 - V_149 ;
if ( F_88 ( V_131 ) < 0 || F_88 ( V_132 ) < 0 )
goto V_93;
F_89 ( V_131 , V_151 ) ;
V_137 = (struct V_136 * ) V_131 -> V_81 ;
F_90 ( V_131 ) ;
V_137 -> V_156 = V_2 ;
V_137 -> V_157 = V_158 ;
V_137 -> V_109 = V_134 -> V_109 ;
memcpy ( V_137 -> V_141 , V_141 , V_116 ) ;
memcpy ( V_137 -> V_159 , V_134 -> V_160 , V_116 ) ;
V_137 -> V_161 = V_145 ;
V_137 -> V_162 = V_134 -> V_163 ;
memcpy ( V_137 -> V_144 , V_144 , V_116 ) ;
memcpy ( V_137 -> V_143 , V_143 , V_116 ) ;
memcpy ( V_137 -> V_164 , V_135 -> V_160 , V_116 ) ;
V_137 -> V_165 = V_146 ;
V_137 -> V_166 = V_135 -> V_109 ;
V_137 -> V_167 = V_135 -> V_163 ;
V_137 -> V_168 = F_91 ( V_148 ) ;
F_84 ( V_131 -> V_81 + V_150 ,
V_132 -> V_81 + V_149 , V_148 ) ;
if ( F_92 ( V_132 ) -> V_169 &&
F_92 ( V_131 ) -> V_169 ) {
V_147 = V_132 -> V_96 + V_97 ;
V_147 += V_131 -> V_96 + V_97 ;
F_68 ( V_5 , V_170 , 2 ) ;
F_68 ( V_5 , V_171 , V_147 ) ;
} else if ( ! F_92 ( V_132 ) -> V_169 &&
! F_92 ( V_131 ) -> V_169 ) {
V_147 = V_132 -> V_96 + V_97 ;
V_147 += V_131 -> V_96 + V_97 ;
F_68 ( V_5 , V_172 , 2 ) ;
F_68 ( V_5 , V_173 , V_147 ) ;
} else if ( F_92 ( V_132 ) -> V_169 &&
! F_92 ( V_131 ) -> V_169 ) {
F_67 ( V_5 , V_170 ) ;
F_68 ( V_5 , V_171 ,
V_132 -> V_96 + V_97 ) ;
F_67 ( V_5 , V_172 ) ;
F_68 ( V_5 , V_173 ,
V_131 -> V_96 + V_97 ) ;
} else if ( ! F_92 ( V_132 ) -> V_169 &&
F_92 ( V_131 ) -> V_169 ) {
F_67 ( V_5 , V_172 ) ;
F_68 ( V_5 , V_173 ,
V_132 -> V_96 + V_97 ) ;
F_67 ( V_5 , V_170 ) ;
F_68 ( V_5 , V_171 ,
V_131 -> V_96 + V_97 ) ;
}
F_33 ( V_132 ) ;
V_48 -> V_49 = NULL ;
F_32 ( V_48 ) ;
F_63 ( V_131 , V_88 -> V_89 , V_142 ) ;
V_91 = true ;
V_93:
if ( V_139 )
F_93 ( V_139 ) ;
if ( V_140 )
F_93 ( V_140 ) ;
return V_91 ;
}
static bool F_94 ( struct V_125 * V_49 ,
T_2 * V_80 , T_2 * V_79 )
{
if ( F_92 ( V_49 ) -> V_169 && ! F_73 ( V_80 , V_79 ) )
return false ;
else
return true ;
}
static struct V_47 *
F_95 ( struct V_4 * V_5 ,
struct V_42 * V_118 ,
struct V_42 * V_119 ,
struct V_125 * V_49 ,
T_2 * V_174 )
{
struct V_45 * V_46 , V_121 ;
struct V_47 * V_175 = NULL ;
struct V_47 * V_48 , * V_98 ;
struct V_61 * V_62 = V_5 -> V_7 . V_25 ;
int V_176 ;
if ( ! V_62 )
return NULL ;
F_56 ( & V_121 , V_118 -> V_60 ,
V_119 -> V_60 ) ;
V_176 = F_57 ( & V_121 , V_62 -> V_67 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_73 ( V_46 -> V_75 , V_118 -> V_60 ) )
continue;
if ( ! F_73 ( V_46 -> V_76 , V_119 -> V_60 ) )
continue;
F_40 ( & V_46 -> V_99 ) ;
if ( F_53 ( & V_46 -> V_72 ) ) {
F_44 ( & V_46 -> V_99 ) ;
continue;
}
F_41 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_94 ( V_48 -> V_49 ,
V_174 ,
V_118 -> V_60 ) )
continue;
F_65 ( & V_48 -> V_56 ) ;
V_175 = V_48 ;
break;
}
F_44 ( & V_46 -> V_99 ) ;
break;
}
F_49 () ;
return V_175 ;
}
static struct V_47 *
F_96 ( struct V_4 * V_5 ,
struct V_125 * V_49 ,
T_2 * V_174 ,
T_2 * V_177 ,
struct V_42 * V_118 )
{
struct V_14 * V_35 ;
struct V_42 * V_119 ;
struct V_47 * V_48 = NULL ;
V_35 = F_97 ( V_5 , V_177 ) ;
if ( ! V_35 )
return NULL ;
F_47 () ;
F_75 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_94 ( V_49 ,
V_119 -> V_60 , V_177 ) )
continue;
V_48 = F_95 ( V_5 , V_118 ,
V_119 , V_49 , V_174 ) ;
if ( V_48 )
break;
}
F_49 () ;
F_25 ( V_35 ) ;
return V_48 ;
}
static void F_98 ( struct V_4 * V_5 ,
struct V_125 * V_49 ,
T_2 * V_178 )
{
struct V_126 * V_126 ;
V_49 = F_99 ( V_49 , V_115 ) ;
if ( ! V_49 )
return;
V_126 = F_100 ( V_49 ) ;
memcpy ( V_126 -> V_154 , V_126 -> V_179 , V_116 ) ;
memcpy ( V_126 -> V_179 , V_178 , V_116 ) ;
F_89 ( V_49 , V_97 ) ;
F_101 ( V_5 , V_49 ) ;
F_33 ( V_49 ) ;
}
static bool F_102 ( struct V_125 * V_49 ,
struct V_127 * V_88 ,
struct V_126 * V_126 )
{
struct V_12 * V_180 = V_88 -> V_89 -> V_181 ;
struct V_4 * V_5 = F_11 ( V_180 ) ;
struct V_14 * V_35 = V_88 -> V_35 ;
struct V_42 * V_43 ;
struct V_47 * V_48 = NULL ;
F_47 () ;
F_75 (nc_node, &orig_node->in_coding_list, list) {
V_48 = F_96 ( V_5 , V_49 ,
V_88 -> V_60 ,
V_126 -> V_154 , V_43 ) ;
if ( V_48 )
break;
}
F_49 () ;
if ( ! V_48 )
return false ;
F_98 ( V_5 , V_49 ,
V_88 -> V_60 ) ;
F_98 ( V_5 , V_48 -> V_49 ,
V_48 -> V_88 -> V_60 ) ;
if ( F_85 ( V_5 , V_49 , V_126 , V_48 ,
V_88 ) )
return true ;
F_62 ( V_48 ) ;
return false ;
}
static bool F_103 ( struct V_125 * V_49 ,
struct V_45 * V_46 ,
struct V_127 * V_88 ,
T_6 V_155 )
{
struct V_47 * V_48 ;
V_48 = F_77 ( sizeof( * V_48 ) , V_115 ) ;
if ( ! V_48 )
return false ;
V_48 -> V_92 = V_23 ;
V_48 -> V_155 = V_155 ;
V_48 -> V_49 = V_49 ;
V_48 -> V_88 = V_88 ;
V_48 -> V_46 = V_46 ;
F_40 ( & V_46 -> V_99 ) ;
F_104 ( & V_48 -> V_56 , & V_46 -> V_72 ) ;
F_44 ( & V_46 -> V_99 ) ;
return true ;
}
bool F_105 ( struct V_125 * V_49 ,
struct V_127 * V_88 )
{
const struct V_12 * V_180 = V_88 -> V_89 -> V_181 ;
struct V_4 * V_5 = F_11 ( V_180 ) ;
struct V_133 * V_182 ;
struct V_45 * V_46 ;
struct V_126 * V_126 = F_100 ( V_49 ) ;
T_6 V_155 ;
T_8 * V_183 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_183 = F_106 ( V_49 ) ;
V_182 = (struct V_133 * ) V_183 ;
if ( V_182 -> V_156 != V_184 )
goto V_93;
if ( F_102 ( V_49 , V_88 , V_126 ) )
return true ;
V_46 = F_80 ( V_5 ,
V_5 -> V_7 . V_25 ,
V_126 -> V_154 ,
V_88 -> V_60 ) ;
if ( ! V_46 )
goto V_93;
V_155 = F_87 ( V_49 , V_183 + sizeof( * V_182 ) ) ;
if ( ! F_103 ( V_49 , V_46 , V_88 , V_155 ) )
goto V_185;
return true ;
V_185:
F_30 ( V_46 ) ;
V_93:
return false ;
}
void F_101 ( struct V_4 * V_5 ,
struct V_125 * V_49 )
{
struct V_133 * V_182 ;
struct V_45 * V_46 ;
struct V_126 * V_126 = F_100 ( V_49 ) ;
T_6 V_155 ;
T_8 * V_183 ;
if ( ! F_7 ( & V_5 -> V_10 ) )
goto V_93;
V_183 = F_106 ( V_49 ) ;
V_182 = (struct V_133 * ) V_183 ;
if ( V_182 -> V_156 != V_184 )
goto V_93;
V_46 = F_80 ( V_5 ,
V_5 -> V_7 . V_26 ,
V_126 -> V_154 ,
V_126 -> V_179 ) ;
if ( ! V_46 )
goto V_93;
V_49 = F_107 ( V_49 , V_115 ) ;
if ( F_52 ( ! V_49 ) )
goto V_185;
if ( F_52 ( ! F_108 ( V_49 , V_97 ) ) )
goto V_186;
if ( F_52 ( ! F_109 ( V_49 , V_97 ) ) )
goto V_186;
V_155 = F_87 ( V_49 , V_183 + sizeof( * V_182 ) ) ;
if ( ! F_103 ( V_49 , V_46 , NULL , V_155 ) )
goto V_186;
F_67 ( V_5 , V_187 ) ;
return;
V_186:
F_33 ( V_49 ) ;
V_185:
F_30 ( V_46 ) ;
V_93:
return;
}
void F_110 ( struct V_4 * V_5 ,
struct V_125 * V_49 )
{
struct V_126 * V_126 = F_100 ( V_49 ) ;
if ( F_111 ( V_5 , V_126 -> V_179 ) )
return;
F_89 ( V_49 , V_97 ) ;
F_101 ( V_5 , V_49 ) ;
}
static struct V_133 *
F_112 ( struct V_4 * V_5 , struct V_125 * V_49 ,
struct V_47 * V_48 )
{
const int V_188 = sizeof( struct V_133 ) ;
const int V_189 = sizeof( struct V_136 ) - V_188 ;
struct V_133 * V_190 ;
struct V_136 V_191 ;
struct V_126 * V_126 , V_192 ;
T_2 * V_193 , V_109 , V_163 ;
unsigned int V_148 ;
int V_27 ;
memcpy ( & V_191 , V_49 -> V_81 , sizeof( V_191 ) ) ;
memcpy ( & V_192 , F_113 ( V_49 ) , sizeof( V_192 ) ) ;
if ( F_114 ( V_49 , 0 ) < 0 )
return NULL ;
if ( F_52 ( ! F_109 ( V_49 , V_189 ) ) )
return NULL ;
F_115 ( V_49 , - V_97 ) ;
F_116 ( V_49 ) ;
V_126 = F_100 ( V_49 ) ;
memcpy ( V_126 , & V_192 , sizeof( * V_126 ) ) ;
if ( F_111 ( V_5 , V_191 . V_144 ) ) {
memcpy ( V_126 -> V_179 , V_191 . V_144 , V_116 ) ;
V_49 -> V_194 = V_195 ;
V_193 = V_191 . V_164 ;
V_109 = V_191 . V_166 ;
V_163 = V_191 . V_167 ;
} else {
V_193 = V_191 . V_159 ;
V_109 = V_191 . V_109 ;
V_163 = V_191 . V_162 ;
}
V_148 = F_117 ( V_191 . V_168 ) ;
if ( V_148 > V_49 -> V_96 )
return NULL ;
F_84 ( V_49 -> V_81 + V_188 ,
V_48 -> V_49 -> V_81 + V_188 ,
V_148 ) ;
if ( V_48 -> V_49 -> V_96 > V_148 + V_188 ) {
V_27 = F_118 ( V_49 , V_148 + V_188 ) ;
if ( V_27 )
return NULL ;
}
V_190 = (struct V_133 * ) V_49 -> V_81 ;
V_190 -> V_156 = V_184 ;
V_190 -> V_157 = V_158 ;
V_190 -> V_109 = V_109 ;
memcpy ( V_190 -> V_160 , V_193 , V_116 ) ;
V_190 -> V_163 = V_163 ;
F_32 ( V_48 ) ;
return V_190 ;
}
static struct V_47 *
F_119 ( struct V_4 * V_5 ,
struct V_126 * V_126 ,
struct V_136 * V_196 )
{
struct V_61 * V_62 = V_5 -> V_7 . V_26 ;
struct V_47 * V_197 , * V_48 = NULL ;
struct V_45 * V_46 , V_121 ;
T_2 * V_160 , * V_198 ;
T_6 V_155 ;
int V_87 ;
if ( ! V_62 )
return NULL ;
V_160 = V_126 -> V_154 ;
if ( ! F_111 ( V_5 , V_196 -> V_144 ) ) {
V_198 = V_196 -> V_143 ;
V_155 = V_196 -> V_165 ;
} else {
V_198 = V_196 -> V_141 ;
V_155 = V_196 -> V_161 ;
}
F_56 ( & V_121 , V_198 , V_160 ) ;
V_87 = F_57 ( & V_121 , V_62 -> V_67 ) ;
F_47 () ;
F_48 (nc_path, &hash->table[index], hash_entry) {
F_40 ( & V_46 -> V_99 ) ;
F_120 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_155 == V_197 -> V_155 ) {
F_65 ( & V_197 -> V_56 ) ;
V_48 = V_197 ;
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
L_6 , V_155 ) ;
return V_48 ;
}
static int V_3 ( struct V_125 * V_49 ,
struct V_199 * V_200 )
{
struct V_4 * V_5 = F_11 ( V_200 -> V_181 ) ;
struct V_133 * V_190 ;
struct V_136 * V_137 ;
struct V_47 * V_48 ;
struct V_126 * V_126 ;
int V_201 = sizeof( * V_137 ) ;
if ( ! F_7 ( & V_5 -> V_10 ) )
return V_202 ;
if ( F_52 ( ! F_108 ( V_49 , V_201 ) ) )
return V_202 ;
V_137 = (struct V_136 * ) V_49 -> V_81 ;
V_126 = F_100 ( V_49 ) ;
if ( ! F_111 ( V_5 , V_126 -> V_179 ) &&
! F_111 ( V_5 , V_137 -> V_144 ) )
return V_202 ;
if ( F_111 ( V_5 , V_137 -> V_144 ) )
F_67 ( V_5 , V_203 ) ;
V_48 = F_119 ( V_5 , V_126 ,
V_137 ) ;
if ( ! V_48 ) {
F_67 ( V_5 , V_204 ) ;
return V_202 ;
}
if ( F_88 ( V_49 ) < 0 )
goto V_205;
if ( F_88 ( V_48 -> V_49 ) < 0 )
goto V_205;
V_190 = F_112 ( V_5 , V_49 , V_48 ) ;
if ( ! V_190 ) {
F_67 ( V_5 , V_204 ) ;
goto V_205;
}
F_92 ( V_49 ) -> V_169 = true ;
F_67 ( V_5 , V_206 ) ;
F_68 ( V_5 , V_207 ,
V_49 -> V_96 + V_97 ) ;
return F_121 ( V_49 , V_200 ) ;
V_205:
F_32 ( V_48 ) ;
return V_202 ;
}
void F_122 ( struct V_4 * V_5 )
{
F_8 ( V_5 , V_11 , 1 ) ;
F_123 ( V_5 , V_11 , 1 ) ;
F_124 ( & V_5 -> V_7 . V_8 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_25 , NULL ) ;
F_125 ( V_5 -> V_7 . V_25 ) ;
F_50 ( V_5 , V_5 -> V_7 . V_26 , NULL ) ;
F_125 ( V_5 -> V_7 . V_26 ) ;
}
int F_126 ( struct V_208 * V_209 , void * V_210 )
{
struct V_12 * V_13 = (struct V_12 * ) V_209 -> V_211 ;
struct V_4 * V_5 = F_11 ( V_13 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
struct V_199 * V_212 ;
struct V_64 * V_65 ;
struct V_14 * V_35 ;
struct V_42 * V_43 ;
int V_66 ;
V_212 = F_127 ( V_209 ) ;
if ( ! V_212 )
goto V_93;
for ( V_66 = 0 ; V_66 < V_62 -> V_67 ; V_66 ++ ) {
V_65 = & V_62 -> V_68 [ V_66 ] ;
F_47 () ;
F_48 (orig_node, head, hash_entry) {
if ( F_53 ( & V_35 -> V_36 ) &&
F_53 ( & V_35 -> V_37 ) )
continue;
F_128 ( V_209 , L_7 , V_35 -> V_15 ) ;
F_129 ( V_209 , L_8 ) ;
F_75 (nc_node,
&orig_node->in_coding_list,
list)
F_128 ( V_209 , L_9 ,
V_43 -> V_60 ) ;
F_129 ( V_209 , L_10 ) ;
F_129 ( V_209 , L_11 ) ;
F_75 (nc_node,
&orig_node->out_coding_list,
list)
F_128 ( V_209 , L_9 ,
V_43 -> V_60 ) ;
F_129 ( V_209 , L_12 ) ;
}
F_49 () ;
}
V_93:
if ( V_212 )
F_130 ( V_212 ) ;
return 0 ;
}
int F_131 ( struct V_4 * V_5 )
{
struct V_213 * V_214 , * V_215 ;
V_214 = F_132 ( L_13 , V_5 -> V_216 ) ;
if ( ! V_214 )
goto V_93;
V_215 = F_133 ( L_14 , V_217 | V_218 , V_214 ,
& V_5 -> V_7 . V_32 ) ;
if ( ! V_215 )
goto V_93;
V_215 = F_134 ( L_15 , V_217 | V_218 , V_214 ,
& V_5 -> V_7 . V_33 ) ;
if ( ! V_215 )
goto V_93;
V_215 = F_134 ( L_16 , V_217 | V_218 , V_214 ,
& V_5 -> V_7 . V_34 ) ;
if ( ! V_215 )
goto V_93;
return 0 ;
V_93:
return - V_31 ;
}
