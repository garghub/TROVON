static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 . V_5 ,
F_3 ( 10 ) ) ;
}
int F_4 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 = V_7 ;
V_2 -> V_4 . V_8 = V_7 ;
if ( V_2 -> V_4 . V_9 || V_2 -> V_4 . V_10 )
return 0 ;
V_2 -> V_4 . V_9 = F_5 ( 128 ) ;
if ( ! V_2 -> V_4 . V_9 )
goto V_11;
F_6 ( V_2 -> V_4 . V_9 ,
& V_12 ) ;
V_2 -> V_4 . V_10 = F_5 ( 128 ) ;
if ( ! V_2 -> V_4 . V_10 )
goto V_11;
F_6 ( V_2 -> V_4 . V_9 ,
& V_13 ) ;
if ( F_7 ( V_14 ,
V_15 ) < 0 )
goto V_11;
F_8 ( & V_2 -> V_4 . V_5 , V_16 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_11:
return - V_17 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_18 , 1 ) ;
V_2 -> V_4 . V_19 = 200 ;
V_2 -> V_4 . V_20 = 10 ;
V_2 -> V_4 . V_21 = 200 ;
}
void F_11 ( struct V_22 * V_23 )
{
F_12 ( & V_23 -> V_24 ) ;
F_12 ( & V_23 -> V_25 ) ;
F_13 ( & V_23 -> V_26 ) ;
F_13 ( & V_23 -> V_27 ) ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_29 , struct V_30 , V_29 ) ;
F_16 ( V_31 -> V_23 ) ;
F_17 ( V_31 ) ;
}
static void F_18 ( struct V_30 * V_31 )
{
if ( F_19 ( & V_31 -> V_32 ) )
F_20 ( & V_31 -> V_29 , F_14 ) ;
}
static void F_21 ( struct V_33 * V_34 )
{
if ( F_19 ( & V_34 -> V_32 ) )
F_22 ( V_34 , V_29 ) ;
}
static void F_23 ( struct V_35 * V_36 )
{
if ( V_36 -> V_37 )
F_24 ( V_36 -> V_37 ) ;
F_21 ( V_36 -> V_34 ) ;
F_17 ( V_36 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
if ( F_26 ( & V_2 -> V_38 ) != V_39 )
return true ;
return F_27 ( V_31 -> V_40 , V_41 ) ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( F_26 ( & V_2 -> V_38 ) != V_39 )
return true ;
return F_27 ( V_34 -> V_42 ,
V_2 -> V_4 . V_20 * 10 ) ;
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( F_26 ( & V_2 -> V_38 ) != V_39 )
return true ;
return F_27 ( V_34 -> V_42 ,
V_2 -> V_4 . V_21 * 10 ) ;
}
static void
F_30 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
T_1 * V_45 ,
bool (* F_31)( struct V_1 * ,
struct V_30 * ) )
{
struct V_30 * V_31 , * V_46 ;
F_32 ( V_45 ) ;
F_33 (nc_node, nc_node_tmp, list, list) {
if ( F_31 && ! F_31 ( V_2 , V_31 ) )
continue;
F_34 ( V_47 , V_2 ,
L_1 ,
V_31 -> V_48 , V_31 -> V_23 -> V_49 ) ;
F_35 ( & V_31 -> V_44 ) ;
F_18 ( V_31 ) ;
}
F_36 ( V_45 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
bool (* F_31)( struct V_1 * ,
struct V_30 * ) )
{
F_30 ( V_2 , & V_23 -> V_24 ,
& V_23 -> V_26 ,
F_31 ) ;
F_30 ( V_2 , & V_23 -> V_25 ,
& V_23 -> V_27 ,
F_31 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_53 * V_54 ;
struct V_22 * V_23 ;
T_2 V_55 ;
if ( ! V_51 )
return;
for ( V_55 = 0 ; V_55 < V_51 -> V_56 ; V_55 ++ ) {
V_54 = & V_51 -> V_57 [ V_55 ] ;
F_39 () ;
F_40 (orig_node, head, hash_entry)
F_37 ( V_2 , V_23 ,
F_25 ) ;
F_41 () ;
}
}
static void F_42 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
bool (* F_31)( struct V_1 * ,
struct V_33 * ) )
{
struct V_53 * V_54 ;
struct V_58 * V_59 ;
struct V_33 * V_34 ;
T_1 * V_45 ;
T_2 V_55 ;
for ( V_55 = 0 ; V_55 < V_51 -> V_56 ; V_55 ++ ) {
V_54 = & V_51 -> V_57 [ V_55 ] ;
V_45 = & V_51 -> V_60 [ V_55 ] ;
F_32 ( V_45 ) ;
F_43 (nc_path, node_tmp, head, hash_entry) {
if ( F_31 && ! F_31 ( V_2 , V_34 ) )
continue;
if ( ! F_44 ( F_45 ( & V_34 -> V_61 ) ) ) {
F_46 ( V_62 ,
V_63
L_2 ,
V_34 -> V_64 ,
V_34 -> V_65 ) ;
continue;
}
F_34 ( V_47 , V_2 ,
L_3 ,
V_34 -> V_64 , V_34 -> V_65 ) ;
F_47 ( & V_34 -> V_66 ) ;
F_21 ( V_34 ) ;
}
F_36 ( V_45 ) ;
}
}
static void F_48 ( struct V_33 * V_67 , const char * V_68 ,
const char * V_69 )
{
memcpy ( V_67 -> V_64 , V_68 , sizeof( V_67 -> V_64 ) ) ;
memcpy ( V_67 -> V_65 , V_69 , sizeof( V_67 -> V_65 ) ) ;
}
static T_2 F_49 ( const void * V_70 , T_2 V_56 )
{
const struct V_33 * V_34 = V_70 ;
T_2 V_51 = 0 ;
V_51 = F_50 ( V_51 , & V_34 -> V_64 ,
sizeof( V_34 -> V_64 ) ) ;
V_51 = F_50 ( V_51 , & V_34 -> V_65 ,
sizeof( V_34 -> V_65 ) ) ;
V_51 += ( V_51 << 3 ) ;
V_51 ^= ( V_51 >> 11 ) ;
V_51 += ( V_51 << 15 ) ;
return V_51 % V_56 ;
}
static int F_51 ( const struct V_58 * V_71 ,
const void * V_72 )
{
const struct V_33 * V_73 , * V_74 ;
V_73 = F_15 ( V_71 , struct V_33 , V_66 ) ;
V_74 = V_72 ;
if ( memcmp ( V_73 -> V_64 , V_74 -> V_64 ,
sizeof( V_73 -> V_64 ) ) != 0 )
return 0 ;
if ( memcmp ( V_73 -> V_65 , V_74 -> V_65 ,
sizeof( V_73 -> V_65 ) ) != 0 )
return 0 ;
return 1 ;
}
static struct V_33 *
F_52 ( struct V_50 * V_51 ,
void * V_70 )
{
struct V_53 * V_54 ;
struct V_33 * V_34 , * V_75 = NULL ;
int V_76 ;
if ( ! V_51 )
return NULL ;
V_76 = F_49 ( V_70 , V_51 -> V_56 ) ;
V_54 = & V_51 -> V_57 [ V_76 ] ;
F_39 () ;
F_40 (nc_path, head, hash_entry) {
if ( ! F_51 ( & V_34 -> V_66 , V_70 ) )
continue;
if ( ! F_53 ( & V_34 -> V_32 ) )
continue;
V_75 = V_34 ;
break;
}
F_41 () ;
return V_75 ;
}
static void F_54 ( struct V_35 * V_36 )
{
F_55 ( V_36 -> V_37 ,
V_36 -> V_77 -> V_78 ,
V_36 -> V_34 -> V_65 ) ;
V_36 -> V_37 = NULL ;
F_23 ( V_36 ) ;
}
static bool F_56 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
unsigned long V_79 = V_2 -> V_4 . V_21 ;
bool V_80 = false ;
if ( F_26 ( & V_2 -> V_38 ) == V_39 &&
! F_27 ( V_36 -> V_81 , V_79 ) )
goto V_82;
F_57 ( & V_36 -> V_44 ) ;
F_23 ( V_36 ) ;
V_80 = true ;
V_82:
return V_80 ;
}
static bool F_58 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
unsigned long V_79 = V_2 -> V_4 . V_20 ;
if ( F_26 ( & V_2 -> V_38 ) == V_39 &&
! F_27 ( V_36 -> V_81 , V_79 ) )
return false ;
F_59 ( V_2 , V_83 ) ;
F_60 ( V_2 , V_84 ,
V_36 -> V_37 -> V_85 + V_86 ) ;
F_57 ( & V_36 -> V_44 ) ;
F_54 ( V_36 ) ;
return true ;
}
static void
F_61 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
bool (* F_62)( struct V_1 * ,
struct V_33 * ,
struct V_35 * ) )
{
struct V_53 * V_54 ;
struct V_35 * V_36 , * V_87 ;
struct V_33 * V_34 ;
bool V_88 ;
int V_55 ;
if ( ! V_51 )
return;
for ( V_55 = 0 ; V_55 < V_51 -> V_56 ; V_55 ++ ) {
V_54 = & V_51 -> V_57 [ V_55 ] ;
F_39 () ;
F_40 (nc_path, head, hash_entry) {
F_32 ( & V_34 -> V_89 ) ;
F_33 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_88 = F_62 ( V_2 , V_34 , V_36 ) ;
if ( ! V_88 )
break;
}
F_36 ( & V_34 -> V_89 ) ;
}
F_41 () ;
}
}
static void V_16 ( struct V_90 * V_5 )
{
struct V_91 * V_91 ;
struct V_92 * V_93 ;
struct V_1 * V_2 ;
unsigned long V_79 ;
V_91 = F_15 ( V_5 , struct V_91 , V_5 ) ;
V_93 = F_15 ( V_91 , struct V_92 , V_5 ) ;
V_2 = F_15 ( V_93 , struct V_1 , V_4 ) ;
F_38 ( V_2 ) ;
F_42 ( V_2 , V_2 -> V_4 . V_9 ,
F_28 ) ;
F_42 ( V_2 , V_2 -> V_4 . V_10 ,
F_29 ) ;
V_79 = V_2 -> V_4 . V_20 ;
if ( F_27 ( V_2 -> V_4 . V_6 , V_79 ) ) {
F_61 ( V_2 , V_2 -> V_4 . V_9 ,
F_58 ) ;
V_2 -> V_4 . V_6 = V_7 ;
}
if ( F_27 ( V_2 -> V_4 . V_8 ,
V_2 -> V_4 . V_21 ) ) {
F_61 ( V_2 , V_2 -> V_4 . V_10 ,
F_56 ) ;
V_2 -> V_4 . V_8 = V_7 ;
}
F_1 ( V_2 ) ;
}
static bool F_63 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_94 * V_95 )
{
if ( V_23 -> V_96 != F_64 ( V_95 -> V_97 ) )
return false ;
if ( V_23 -> V_98 != V_95 -> V_99 . V_100 + 1 )
return false ;
if ( ! F_65 ( V_95 -> V_49 , V_95 -> V_101 ) )
return false ;
if ( V_95 -> V_102 < V_2 -> V_4 . V_19 )
return false ;
return true ;
}
static struct V_30
* F_66 ( struct V_22 * V_23 ,
struct V_22 * V_103 ,
bool V_104 )
{
struct V_30 * V_31 , * V_105 = NULL ;
struct V_43 * V_44 ;
if ( V_104 )
V_44 = & V_103 -> V_24 ;
else
V_44 = & V_103 -> V_25 ;
F_39 () ;
F_67 (nc_node, list, list) {
if ( ! F_65 ( V_31 -> V_48 , V_23 -> V_49 ) )
continue;
if ( ! F_53 ( & V_31 -> V_32 ) )
continue;
V_105 = V_31 ;
break;
}
F_41 () ;
return V_105 ;
}
static struct V_30
* F_68 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_103 ,
bool V_104 )
{
struct V_30 * V_31 ;
T_1 * V_45 ;
struct V_43 * V_44 ;
V_31 = F_66 ( V_23 , V_103 , V_104 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_69 ( sizeof( * V_31 ) , V_106 ) ;
if ( ! V_31 )
return NULL ;
if ( ! F_53 ( & V_103 -> V_32 ) )
goto free;
F_12 ( & V_31 -> V_44 ) ;
memcpy ( V_31 -> V_48 , V_23 -> V_49 , V_107 ) ;
V_31 -> V_23 = V_103 ;
F_10 ( & V_31 -> V_32 , 2 ) ;
if ( V_104 ) {
V_45 = & V_103 -> V_26 ;
V_44 = & V_103 -> V_24 ;
} else {
V_45 = & V_103 -> V_27 ;
V_44 = & V_103 -> V_25 ;
}
F_34 ( V_47 , V_2 , L_4 ,
V_31 -> V_48 , V_31 -> V_23 -> V_49 ) ;
F_32 ( V_45 ) ;
F_70 ( & V_31 -> V_44 , V_44 ) ;
F_36 ( V_45 ) ;
return V_31 ;
free:
F_17 ( V_31 ) ;
return NULL ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_103 ,
struct V_94 * V_95 ,
int V_108 )
{
struct V_30 * V_109 = NULL , * V_110 = NULL ;
if ( ! F_26 ( & V_2 -> V_18 ) )
goto V_82;
if ( ! F_63 ( V_2 , V_23 , V_95 ) &&
! V_108 )
goto V_82;
V_109 = F_68 ( V_2 , V_23 ,
V_103 , true ) ;
if ( ! V_109 )
goto V_82;
V_109 -> V_40 = V_7 ;
V_110 = F_68 ( V_2 , V_103 ,
V_23 , false ) ;
if ( ! V_110 )
goto V_82;
V_110 -> V_40 = V_7 ;
V_82:
if ( V_109 )
F_18 ( V_109 ) ;
if ( V_110 )
F_18 ( V_110 ) ;
}
static struct V_33 * F_72 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_3 * V_68 ,
T_3 * V_69 )
{
int V_111 ;
struct V_33 * V_34 , V_112 ;
F_48 ( & V_112 , V_68 , V_69 ) ;
V_34 = F_52 ( V_51 , ( void * ) & V_112 ) ;
if ( V_34 ) {
V_34 -> V_42 = V_7 ;
return V_34 ;
}
V_34 = F_69 ( sizeof( * V_34 ) , V_106 ) ;
if ( ! V_34 )
return NULL ;
F_12 ( & V_34 -> V_61 ) ;
F_13 ( & V_34 -> V_89 ) ;
F_10 ( & V_34 -> V_32 , 2 ) ;
V_34 -> V_42 = V_7 ;
memcpy ( V_34 -> V_65 , V_69 , V_107 ) ;
memcpy ( V_34 -> V_64 , V_68 , V_107 ) ;
F_34 ( V_47 , V_2 , L_5 ,
V_34 -> V_64 ,
V_34 -> V_65 ) ;
V_111 = F_73 ( V_51 , F_51 ,
F_49 , & V_112 ,
& V_34 -> V_66 ) ;
if ( V_111 < 0 ) {
F_17 ( V_34 ) ;
return NULL ;
}
return V_34 ;
}
static T_3 F_74 ( T_3 V_102 )
{
T_3 V_113 , V_114 ;
F_75 ( & V_113 , sizeof( V_113 ) ) ;
V_114 = V_113 * ( V_115 - V_102 ) ;
V_114 /= V_115 ;
return V_115 - V_114 ;
}
static void F_76 ( char * V_69 , const char * V_68 , unsigned int V_85 )
{
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_85 ; ++ V_55 )
V_69 [ V_55 ] ^= V_68 [ V_55 ] ;
}
static bool F_77 ( struct V_1 * V_2 ,
struct V_116 * V_37 ,
struct V_117 * V_117 ,
struct V_35 * V_36 ,
struct V_118 * V_77 )
{
T_3 V_119 , V_120 ;
struct V_116 * V_121 , * V_122 ;
struct V_123 * V_124 ;
struct V_123 * V_125 ;
struct V_126 * V_127 ;
struct V_118 * V_128 , * V_129 ;
struct V_118 * V_130 = NULL ;
T_3 * V_131 , * V_132 , * V_133 , * V_134 ;
T_4 V_135 , V_136 ;
T_5 V_137 ;
bool V_80 = false ;
int V_138 ;
int V_139 = sizeof( * V_124 ) ;
int V_140 = sizeof( * V_127 ) ;
int V_141 = V_140 - V_139 ;
V_129 = F_78 ( V_77 -> V_23 ) ;
if ( ! V_129 )
goto V_82;
V_128 = V_36 -> V_77 ;
V_130 = F_78 ( V_128 -> V_23 ) ;
if ( ! V_130 )
goto V_82;
V_119 = F_74 ( V_129 -> V_142 ) ;
V_120 = F_74 ( V_130 -> V_142 ) ;
if ( V_119 >= V_120 ) {
V_132 = V_36 -> V_34 -> V_65 ;
V_131 = V_36 -> V_34 -> V_64 ;
V_134 = V_77 -> V_48 ;
V_133 = V_117 -> V_143 ;
V_124 = (struct V_123 * ) V_36 -> V_37 -> V_70 ;
V_125 = (struct V_123 * ) V_37 -> V_70 ;
V_135 = V_36 -> V_144 ;
V_136 = F_79 ( V_37 ,
V_37 -> V_70 + sizeof( * V_125 ) ) ;
} else {
V_132 = V_77 -> V_48 ;
V_131 = V_117 -> V_143 ;
V_134 = V_36 -> V_34 -> V_65 ;
V_133 = V_36 -> V_34 -> V_64 ;
V_124 = (struct V_123 * ) V_37 -> V_70 ;
V_125 = (struct V_123 * ) V_36 -> V_37 -> V_70 ;
V_135 = F_79 ( V_37 ,
V_37 -> V_70 + sizeof( * V_124 ) ) ;
V_136 = V_36 -> V_144 ;
}
if ( V_37 -> V_85 <= V_36 -> V_37 -> V_85 ) {
V_121 = V_36 -> V_37 ;
V_122 = V_37 ;
} else {
V_121 = V_37 ;
V_122 = V_36 -> V_37 ;
}
V_138 = V_122 -> V_85 - V_139 ;
if ( F_80 ( V_121 ) < 0 || F_80 ( V_122 ) < 0 )
goto V_82;
F_81 ( V_121 , V_141 ) ;
V_127 = (struct V_126 * ) V_121 -> V_70 ;
F_82 ( V_121 ) ;
V_127 -> V_99 . V_145 = V_14 ;
V_127 -> V_99 . V_146 = V_147 ;
V_127 -> V_99 . V_100 = V_124 -> V_99 . V_100 ;
memcpy ( V_127 -> V_131 , V_131 , V_107 ) ;
memcpy ( V_127 -> V_148 , V_124 -> V_149 , V_107 ) ;
V_127 -> V_150 = V_135 ;
V_127 -> V_151 = V_124 -> V_152 ;
memcpy ( V_127 -> V_134 , V_134 , V_107 ) ;
memcpy ( V_127 -> V_133 , V_133 , V_107 ) ;
memcpy ( V_127 -> V_153 , V_125 -> V_149 , V_107 ) ;
V_127 -> V_154 = V_136 ;
V_127 -> V_155 = V_125 -> V_99 . V_100 ;
V_127 -> V_156 = V_125 -> V_152 ;
V_127 -> V_157 = F_83 ( V_138 ) ;
F_76 ( V_121 -> V_70 + V_140 ,
V_122 -> V_70 + V_139 , V_138 ) ;
if ( F_84 ( V_122 ) -> V_158 &&
F_84 ( V_121 ) -> V_158 ) {
V_137 = V_122 -> V_85 + V_86 ;
V_137 += V_121 -> V_85 + V_86 ;
F_60 ( V_2 , V_159 , 2 ) ;
F_60 ( V_2 , V_160 , V_137 ) ;
} else if ( ! F_84 ( V_122 ) -> V_158 &&
! F_84 ( V_121 ) -> V_158 ) {
V_137 = V_122 -> V_85 + V_86 ;
V_137 += V_121 -> V_85 + V_86 ;
F_60 ( V_2 , V_161 , 2 ) ;
F_60 ( V_2 , V_162 , V_137 ) ;
} else if ( F_84 ( V_122 ) -> V_158 &&
! F_84 ( V_121 ) -> V_158 ) {
F_59 ( V_2 , V_159 ) ;
F_60 ( V_2 , V_160 ,
V_122 -> V_85 + V_86 ) ;
F_59 ( V_2 , V_161 ) ;
F_60 ( V_2 , V_162 ,
V_121 -> V_85 + V_86 ) ;
} else if ( ! F_84 ( V_122 ) -> V_158 &&
F_84 ( V_121 ) -> V_158 ) {
F_59 ( V_2 , V_161 ) ;
F_60 ( V_2 , V_162 ,
V_122 -> V_85 + V_86 ) ;
F_59 ( V_2 , V_159 ) ;
F_60 ( V_2 , V_160 ,
V_121 -> V_85 + V_86 ) ;
}
F_24 ( V_122 ) ;
V_36 -> V_37 = NULL ;
F_23 ( V_36 ) ;
F_55 ( V_121 , V_77 -> V_78 , V_132 ) ;
V_80 = true ;
V_82:
if ( V_129 )
F_85 ( V_129 ) ;
if ( V_130 )
F_85 ( V_130 ) ;
return V_80 ;
}
static bool F_86 ( struct V_116 * V_37 ,
T_3 * V_69 , T_3 * V_68 )
{
if ( F_84 ( V_37 ) -> V_158 && ! F_65 ( V_69 , V_68 ) )
return false ;
else
return true ;
}
static struct V_35 *
F_87 ( struct V_1 * V_2 ,
struct V_30 * V_109 ,
struct V_30 * V_110 ,
struct V_116 * V_37 ,
T_3 * V_163 )
{
struct V_33 * V_34 , V_112 ;
struct V_35 * V_164 = NULL ;
struct V_35 * V_36 , * V_87 ;
struct V_50 * V_51 = V_2 -> V_4 . V_9 ;
int V_165 ;
if ( ! V_51 )
return NULL ;
F_48 ( & V_112 , V_109 -> V_48 ,
V_110 -> V_48 ) ;
V_165 = F_49 ( & V_112 , V_51 -> V_56 ) ;
F_39 () ;
F_40 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_65 ( V_34 -> V_64 , V_109 -> V_48 ) )
continue;
if ( ! F_65 ( V_34 -> V_65 , V_110 -> V_48 ) )
continue;
F_32 ( & V_34 -> V_89 ) ;
if ( F_45 ( & V_34 -> V_61 ) ) {
F_36 ( & V_34 -> V_89 ) ;
continue;
}
F_33 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_86 ( V_36 -> V_37 ,
V_163 ,
V_109 -> V_48 ) )
continue;
F_57 ( & V_36 -> V_44 ) ;
V_164 = V_36 ;
break;
}
F_36 ( & V_34 -> V_89 ) ;
break;
}
F_41 () ;
return V_164 ;
}
static struct V_35 *
F_88 ( struct V_1 * V_2 ,
struct V_116 * V_37 ,
T_3 * V_163 ,
T_3 * V_166 ,
struct V_30 * V_109 )
{
struct V_22 * V_23 ;
struct V_30 * V_110 ;
struct V_35 * V_36 = NULL ;
V_23 = F_89 ( V_2 , V_166 ) ;
if ( ! V_23 )
return NULL ;
F_39 () ;
F_67 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_86 ( V_37 ,
V_110 -> V_48 , V_166 ) )
continue;
V_36 = F_87 ( V_2 , V_109 ,
V_110 , V_37 , V_163 ) ;
if ( V_36 )
break;
}
F_41 () ;
F_16 ( V_23 ) ;
return V_36 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_116 * V_37 ,
T_3 * V_167 )
{
struct V_117 * V_117 ;
V_37 = F_91 ( V_37 , V_106 ) ;
if ( ! V_37 )
return;
V_117 = (struct V_117 * ) F_92 ( V_37 ) ;
memcpy ( V_117 -> V_143 , V_117 -> V_168 , V_107 ) ;
memcpy ( V_117 -> V_168 , V_167 , V_107 ) ;
F_81 ( V_37 , V_86 ) ;
F_93 ( V_2 , V_37 ) ;
F_24 ( V_37 ) ;
}
static bool F_94 ( struct V_116 * V_37 ,
struct V_118 * V_77 ,
struct V_117 * V_117 )
{
struct V_169 * V_170 = V_77 -> V_78 -> V_171 ;
struct V_1 * V_2 = F_95 ( V_170 ) ;
struct V_22 * V_23 = V_77 -> V_23 ;
struct V_30 * V_31 ;
struct V_35 * V_36 = NULL ;
F_39 () ;
F_67 (nc_node, &orig_node->in_coding_list, list) {
V_36 = F_88 ( V_2 , V_37 ,
V_77 -> V_48 ,
V_117 -> V_143 , V_31 ) ;
if ( V_36 )
break;
}
F_41 () ;
if ( ! V_36 )
return false ;
F_90 ( V_2 , V_37 ,
V_77 -> V_48 ) ;
F_90 ( V_2 , V_36 -> V_37 ,
V_36 -> V_77 -> V_48 ) ;
if ( F_77 ( V_2 , V_37 , V_117 , V_36 ,
V_77 ) )
return true ;
F_54 ( V_36 ) ;
return false ;
}
static bool F_96 ( struct V_116 * V_37 ,
struct V_33 * V_34 ,
struct V_118 * V_77 ,
T_4 V_144 )
{
struct V_35 * V_36 ;
V_36 = F_69 ( sizeof( * V_36 ) , V_106 ) ;
if ( ! V_36 )
return false ;
V_36 -> V_81 = V_7 ;
V_36 -> V_144 = V_144 ;
V_36 -> V_37 = V_37 ;
V_36 -> V_77 = V_77 ;
V_36 -> V_34 = V_34 ;
F_32 ( & V_34 -> V_89 ) ;
F_97 ( & V_36 -> V_44 , & V_34 -> V_61 ) ;
F_36 ( & V_34 -> V_89 ) ;
return true ;
}
bool F_98 ( struct V_116 * V_37 ,
struct V_118 * V_77 ,
struct V_117 * V_117 )
{
const struct V_169 * V_170 = V_77 -> V_78 -> V_171 ;
struct V_1 * V_2 = F_95 ( V_170 ) ;
struct V_123 * V_172 ;
struct V_33 * V_34 ;
T_4 V_144 ;
T_6 * V_173 ;
if ( ! F_26 ( & V_2 -> V_18 ) )
goto V_82;
V_173 = F_99 ( V_37 ) ;
V_172 = (struct V_123 * ) V_173 ;
if ( V_172 -> V_99 . V_145 != V_174 )
goto V_82;
if ( F_94 ( V_37 , V_77 , V_117 ) )
return true ;
V_34 = F_72 ( V_2 ,
V_2 -> V_4 . V_9 ,
V_117 -> V_143 ,
V_77 -> V_48 ) ;
if ( ! V_34 )
goto V_82;
V_144 = F_79 ( V_37 , V_173 + sizeof( * V_172 ) ) ;
if ( ! F_96 ( V_37 , V_34 , V_77 , V_144 ) )
goto V_175;
return true ;
V_175:
F_21 ( V_34 ) ;
V_82:
return false ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_116 * V_37 )
{
struct V_123 * V_172 ;
struct V_33 * V_34 ;
struct V_117 * V_117 = (struct V_117 * ) F_92 ( V_37 ) ;
T_4 V_144 ;
T_6 * V_173 ;
if ( ! F_26 ( & V_2 -> V_18 ) )
goto V_82;
V_173 = F_99 ( V_37 ) ;
V_172 = (struct V_123 * ) V_173 ;
if ( V_172 -> V_99 . V_145 != V_174 )
goto V_82;
V_34 = F_72 ( V_2 ,
V_2 -> V_4 . V_10 ,
V_117 -> V_143 ,
V_117 -> V_168 ) ;
if ( ! V_34 )
goto V_82;
V_37 = F_100 ( V_37 , V_106 ) ;
if ( F_44 ( ! V_37 ) )
goto V_175;
if ( F_44 ( ! F_101 ( V_37 , V_86 ) ) )
goto V_176;
if ( F_44 ( ! F_102 ( V_37 , V_86 ) ) )
goto V_176;
V_144 = F_79 ( V_37 , V_173 + sizeof( * V_172 ) ) ;
if ( ! F_96 ( V_37 , V_34 , NULL , V_144 ) )
goto V_176;
F_59 ( V_2 , V_177 ) ;
return;
V_176:
F_24 ( V_37 ) ;
V_175:
F_21 ( V_34 ) ;
V_82:
return;
}
void F_103 ( struct V_1 * V_2 ,
struct V_116 * V_37 )
{
struct V_117 * V_117 = (struct V_117 * ) F_92 ( V_37 ) ;
if ( F_104 ( V_2 , V_117 -> V_168 ) )
return;
F_81 ( V_37 , V_86 ) ;
F_93 ( V_2 , V_37 ) ;
}
static struct V_123 *
F_105 ( struct V_1 * V_2 , struct V_116 * V_37 ,
struct V_35 * V_36 )
{
const int V_178 = sizeof( struct V_123 ) ;
const int V_179 = sizeof( struct V_126 ) - V_178 ;
struct V_123 * V_180 ;
struct V_126 V_181 ;
struct V_117 * V_117 , V_182 ;
T_3 * V_183 , V_100 , V_152 ;
unsigned int V_138 ;
int V_11 ;
memcpy ( & V_181 , V_37 -> V_70 , sizeof( V_181 ) ) ;
memcpy ( & V_182 , F_92 ( V_37 ) , sizeof( V_182 ) ) ;
if ( F_106 ( V_37 , 0 ) < 0 )
return NULL ;
if ( F_44 ( ! F_102 ( V_37 , V_179 ) ) )
return NULL ;
F_107 ( V_37 , - V_86 ) ;
F_108 ( V_37 ) ;
V_117 = (struct V_117 * ) F_92 ( V_37 ) ;
memcpy ( V_117 , & V_182 , sizeof( * V_117 ) ) ;
if ( F_104 ( V_2 , V_181 . V_134 ) ) {
memcpy ( V_117 -> V_168 , V_181 . V_134 , V_107 ) ;
V_37 -> V_184 = V_185 ;
V_183 = V_181 . V_153 ;
V_100 = V_181 . V_155 ;
V_152 = V_181 . V_156 ;
} else {
V_183 = V_181 . V_148 ;
V_100 = V_181 . V_99 . V_100 ;
V_152 = V_181 . V_151 ;
}
V_138 = F_109 ( V_181 . V_157 ) ;
if ( V_138 > V_37 -> V_85 )
return NULL ;
F_76 ( V_37 -> V_70 + V_178 ,
V_36 -> V_37 -> V_70 + V_178 ,
V_138 ) ;
if ( V_36 -> V_37 -> V_85 > V_138 + V_178 ) {
V_11 = F_110 ( V_37 , V_138 + V_178 ) ;
if ( V_11 )
return NULL ;
}
V_180 = (struct V_123 * ) V_37 -> V_70 ;
V_180 -> V_99 . V_145 = V_174 ;
V_180 -> V_99 . V_146 = V_147 ;
V_180 -> V_99 . V_100 = V_100 ;
memcpy ( V_180 -> V_149 , V_183 , V_107 ) ;
V_180 -> V_152 = V_152 ;
F_23 ( V_36 ) ;
return V_180 ;
}
static struct V_35 *
F_111 ( struct V_1 * V_2 ,
struct V_117 * V_117 ,
struct V_126 * V_186 )
{
struct V_50 * V_51 = V_2 -> V_4 . V_10 ;
struct V_35 * V_187 , * V_36 = NULL ;
struct V_33 * V_34 , V_112 ;
T_3 * V_149 , * V_188 ;
T_4 V_144 ;
int V_76 ;
if ( ! V_51 )
return NULL ;
V_149 = V_117 -> V_143 ;
if ( ! F_104 ( V_2 , V_186 -> V_134 ) ) {
V_188 = V_186 -> V_133 ;
V_144 = V_186 -> V_154 ;
} else {
V_188 = V_186 -> V_131 ;
V_144 = V_186 -> V_150 ;
}
F_48 ( & V_112 , V_188 , V_149 ) ;
V_76 = F_49 ( & V_112 , V_51 -> V_56 ) ;
F_39 () ;
F_40 (nc_path, &hash->table[index], hash_entry) {
F_32 ( & V_34 -> V_89 ) ;
F_112 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_144 == V_187 -> V_144 ) {
F_57 ( & V_187 -> V_44 ) ;
V_36 = V_187 ;
break;
}
}
F_36 ( & V_34 -> V_89 ) ;
if ( V_36 )
break;
}
F_41 () ;
if ( ! V_36 )
F_34 ( V_47 , V_2 ,
L_6 , V_144 ) ;
return V_36 ;
}
static int V_15 ( struct V_116 * V_37 ,
struct V_189 * V_190 )
{
struct V_1 * V_2 = F_95 ( V_190 -> V_171 ) ;
struct V_123 * V_180 ;
struct V_126 * V_127 ;
struct V_35 * V_36 ;
struct V_117 * V_117 ;
int V_191 = sizeof( * V_127 ) ;
if ( ! F_26 ( & V_2 -> V_18 ) )
return V_192 ;
if ( F_44 ( ! F_101 ( V_37 , V_191 ) ) )
return V_192 ;
V_127 = (struct V_126 * ) V_37 -> V_70 ;
V_117 = (struct V_117 * ) F_92 ( V_37 ) ;
if ( ! F_104 ( V_2 , V_117 -> V_168 ) &&
! F_104 ( V_2 , V_127 -> V_134 ) )
return V_192 ;
if ( F_104 ( V_2 , V_127 -> V_134 ) )
F_59 ( V_2 , V_193 ) ;
V_36 = F_111 ( V_2 , V_117 ,
V_127 ) ;
if ( ! V_36 ) {
F_59 ( V_2 , V_194 ) ;
return V_192 ;
}
if ( F_80 ( V_37 ) < 0 )
goto V_195;
if ( F_80 ( V_36 -> V_37 ) < 0 )
goto V_195;
V_180 = F_105 ( V_2 , V_37 , V_36 ) ;
if ( ! V_180 ) {
F_59 ( V_2 , V_194 ) ;
goto V_195;
}
F_84 ( V_37 ) -> V_158 = true ;
F_59 ( V_2 , V_196 ) ;
F_60 ( V_2 , V_197 ,
V_37 -> V_85 + V_86 ) ;
return F_113 ( V_37 , V_190 ) ;
V_195:
F_23 ( V_36 ) ;
return V_192 ;
}
void F_114 ( struct V_1 * V_2 )
{
F_115 ( V_14 ) ;
F_116 ( & V_2 -> V_4 . V_5 ) ;
F_42 ( V_2 , V_2 -> V_4 . V_9 , NULL ) ;
F_117 ( V_2 -> V_4 . V_9 ) ;
F_42 ( V_2 , V_2 -> V_4 . V_10 , NULL ) ;
F_117 ( V_2 -> V_4 . V_10 ) ;
}
int F_118 ( struct V_198 * V_199 , void * V_200 )
{
struct V_169 * V_201 = (struct V_169 * ) V_199 -> V_202 ;
struct V_1 * V_2 = F_95 ( V_201 ) ;
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_189 * V_203 ;
struct V_53 * V_54 ;
struct V_22 * V_23 ;
struct V_30 * V_31 ;
int V_55 ;
V_203 = F_119 ( V_199 ) ;
if ( ! V_203 )
goto V_82;
for ( V_55 = 0 ; V_55 < V_51 -> V_56 ; V_55 ++ ) {
V_54 = & V_51 -> V_57 [ V_55 ] ;
F_39 () ;
F_40 (orig_node, head, hash_entry) {
F_120 ( V_199 , L_7 , V_23 -> V_49 ) ;
F_121 ( V_199 , L_8 ) ;
F_67 (nc_node,
&orig_node->in_coding_list,
list)
F_120 ( V_199 , L_9 ,
V_31 -> V_48 ) ;
F_121 ( V_199 , L_10 ) ;
F_121 ( V_199 , L_11 ) ;
F_67 (nc_node,
&orig_node->out_coding_list,
list)
F_120 ( V_199 , L_9 ,
V_31 -> V_48 ) ;
F_121 ( V_199 , L_12 ) ;
}
F_41 () ;
}
V_82:
if ( V_203 )
F_122 ( V_203 ) ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_204 * V_205 , * V_206 ;
V_205 = F_124 ( L_13 , V_2 -> V_207 ) ;
if ( ! V_205 )
goto V_82;
V_206 = F_125 ( L_14 , V_208 | V_209 , V_205 ,
& V_2 -> V_4 . V_19 ) ;
if ( ! V_206 )
goto V_82;
V_206 = F_126 ( L_15 , V_208 | V_209 , V_205 ,
& V_2 -> V_4 . V_20 ) ;
if ( ! V_206 )
goto V_82;
V_206 = F_126 ( L_16 , V_208 | V_209 , V_205 ,
& V_2 -> V_4 . V_21 ) ;
if ( ! V_206 )
goto V_82;
return 0 ;
V_82:
return - V_17 ;
}
