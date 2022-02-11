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
int F_6 ( struct V_4 * V_5 )
{
V_5 -> V_7 . V_9 = V_10 ;
V_5 -> V_7 . V_11 = V_10 ;
if ( V_5 -> V_7 . V_12 || V_5 -> V_7 . V_13 )
return 0 ;
V_5 -> V_7 . V_12 = F_7 ( 128 ) ;
if ( ! V_5 -> V_7 . V_12 )
goto V_14;
F_8 ( V_5 -> V_7 . V_12 ,
& V_15 ) ;
V_5 -> V_7 . V_13 = F_7 ( 128 ) ;
if ( ! V_5 -> V_7 . V_13 )
goto V_14;
F_8 ( V_5 -> V_7 . V_12 ,
& V_16 ) ;
F_9 ( & V_5 -> V_7 . V_8 , V_17 ) ;
F_3 ( V_5 ) ;
return 0 ;
V_14:
return - V_18 ;
}
void F_10 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_19 , 1 ) ;
V_5 -> V_7 . V_20 = 200 ;
V_5 -> V_7 . V_21 = 10 ;
V_5 -> V_7 . V_22 = 200 ;
}
void F_12 ( struct V_23 * V_24 )
{
F_13 ( & V_24 -> V_25 ) ;
F_13 ( & V_24 -> V_26 ) ;
F_14 ( & V_24 -> V_27 ) ;
F_14 ( & V_24 -> V_28 ) ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
V_32 = F_16 ( V_30 , struct V_31 , V_30 ) ;
F_17 ( V_32 -> V_24 ) ;
F_18 ( V_32 ) ;
}
static void F_19 ( struct V_31 * V_32 )
{
if ( F_20 ( & V_32 -> V_33 ) )
F_21 ( & V_32 -> V_30 , F_15 ) ;
}
static void F_22 ( struct V_34 * V_35 )
{
if ( F_20 ( & V_35 -> V_33 ) )
F_23 ( V_35 , V_30 ) ;
}
static void F_24 ( struct V_36 * V_37 )
{
if ( V_37 -> V_38 )
F_25 ( V_37 -> V_38 ) ;
F_22 ( V_37 -> V_35 ) ;
F_18 ( V_37 ) ;
}
static bool F_26 ( struct V_4 * V_5 ,
struct V_31 * V_32 )
{
if ( F_27 ( & V_5 -> V_39 ) != V_40 )
return true ;
return F_28 ( V_32 -> V_41 , V_42 ) ;
}
static bool F_29 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
if ( F_27 ( & V_5 -> V_39 ) != V_40 )
return true ;
return F_28 ( V_35 -> V_43 ,
V_5 -> V_7 . V_21 * 10 ) ;
}
static bool F_30 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
if ( F_27 ( & V_5 -> V_39 ) != V_40 )
return true ;
return F_28 ( V_35 -> V_43 ,
V_5 -> V_7 . V_22 * 10 ) ;
}
static void
F_31 ( struct V_4 * V_5 ,
struct V_44 * V_45 ,
T_2 * V_46 ,
bool (* F_32)( struct V_4 * ,
struct V_31 * ) )
{
struct V_31 * V_32 , * V_47 ;
F_33 ( V_46 ) ;
F_34 (nc_node, nc_node_tmp, list, list) {
if ( F_32 && ! F_32 ( V_5 , V_32 ) )
continue;
F_35 ( V_48 , V_5 ,
L_1 ,
V_32 -> V_49 , V_32 -> V_24 -> V_50 ) ;
F_36 ( & V_32 -> V_45 ) ;
F_19 ( V_32 ) ;
}
F_37 ( V_46 ) ;
}
void F_38 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
bool (* F_32)( struct V_4 * ,
struct V_31 * ) )
{
F_31 ( V_5 , & V_24 -> V_25 ,
& V_24 -> V_27 ,
F_32 ) ;
F_31 ( V_5 , & V_24 -> V_26 ,
& V_24 -> V_28 ,
F_32 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = V_5 -> V_53 ;
struct V_54 * V_55 ;
struct V_23 * V_24 ;
T_3 V_56 ;
if ( ! V_52 )
return;
for ( V_56 = 0 ; V_56 < V_52 -> V_57 ; V_56 ++ ) {
V_55 = & V_52 -> V_58 [ V_56 ] ;
F_40 () ;
F_41 (orig_node, head, hash_entry)
F_38 ( V_5 , V_24 ,
F_26 ) ;
F_42 () ;
}
}
static void F_43 ( struct V_4 * V_5 ,
struct V_51 * V_52 ,
bool (* F_32)( struct V_4 * ,
struct V_34 * ) )
{
struct V_54 * V_55 ;
struct V_59 * V_60 ;
struct V_34 * V_35 ;
T_2 * V_46 ;
T_3 V_56 ;
for ( V_56 = 0 ; V_56 < V_52 -> V_57 ; V_56 ++ ) {
V_55 = & V_52 -> V_58 [ V_56 ] ;
V_46 = & V_52 -> V_61 [ V_56 ] ;
F_33 ( V_46 ) ;
F_44 (nc_path, node_tmp, head, hash_entry) {
if ( F_32 && ! F_32 ( V_5 , V_35 ) )
continue;
if ( ! F_45 ( F_46 ( & V_35 -> V_62 ) ) ) {
F_47 ( V_63 ,
V_64
L_2 ,
V_35 -> V_65 ,
V_35 -> V_66 ) ;
continue;
}
F_35 ( V_48 , V_5 ,
L_3 ,
V_35 -> V_65 , V_35 -> V_66 ) ;
F_48 ( & V_35 -> V_67 ) ;
F_22 ( V_35 ) ;
}
F_37 ( V_46 ) ;
}
}
static void F_49 ( struct V_34 * V_68 , const char * V_69 ,
const char * V_70 )
{
memcpy ( V_68 -> V_65 , V_69 , sizeof( V_68 -> V_65 ) ) ;
memcpy ( V_68 -> V_66 , V_70 , sizeof( V_68 -> V_66 ) ) ;
}
static T_3 F_50 ( const void * V_71 , T_3 V_57 )
{
const struct V_34 * V_35 = V_71 ;
T_3 V_52 = 0 ;
V_52 = F_51 ( V_52 , & V_35 -> V_65 ,
sizeof( V_35 -> V_65 ) ) ;
V_52 = F_51 ( V_52 , & V_35 -> V_66 ,
sizeof( V_35 -> V_66 ) ) ;
V_52 += ( V_52 << 3 ) ;
V_52 ^= ( V_52 >> 11 ) ;
V_52 += ( V_52 << 15 ) ;
return V_52 % V_57 ;
}
static int F_52 ( const struct V_59 * V_72 ,
const void * V_73 )
{
const struct V_34 * V_74 , * V_75 ;
V_74 = F_16 ( V_72 , struct V_34 , V_67 ) ;
V_75 = V_73 ;
if ( memcmp ( V_74 -> V_65 , V_75 -> V_65 ,
sizeof( V_74 -> V_65 ) ) != 0 )
return 0 ;
if ( memcmp ( V_74 -> V_66 , V_75 -> V_66 ,
sizeof( V_74 -> V_66 ) ) != 0 )
return 0 ;
return 1 ;
}
static struct V_34 *
F_53 ( struct V_51 * V_52 ,
void * V_71 )
{
struct V_54 * V_55 ;
struct V_34 * V_35 , * V_76 = NULL ;
int V_77 ;
if ( ! V_52 )
return NULL ;
V_77 = F_50 ( V_71 , V_52 -> V_57 ) ;
V_55 = & V_52 -> V_58 [ V_77 ] ;
F_40 () ;
F_41 (nc_path, head, hash_entry) {
if ( ! F_52 ( & V_35 -> V_67 , V_71 ) )
continue;
if ( ! F_54 ( & V_35 -> V_33 ) )
continue;
V_76 = V_35 ;
break;
}
F_42 () ;
return V_76 ;
}
static void F_55 ( struct V_36 * V_37 )
{
F_56 ( V_37 -> V_38 ,
V_37 -> V_78 -> V_79 ,
V_37 -> V_35 -> V_66 ) ;
V_37 -> V_38 = NULL ;
F_24 ( V_37 ) ;
}
static bool F_57 ( struct V_4 * V_5 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
unsigned long V_80 = V_5 -> V_7 . V_22 ;
bool V_81 = false ;
if ( F_27 ( & V_5 -> V_39 ) == V_40 &&
! F_28 ( V_37 -> V_82 , V_80 ) )
goto V_83;
F_58 ( & V_37 -> V_45 ) ;
F_24 ( V_37 ) ;
V_81 = true ;
V_83:
return V_81 ;
}
static bool F_59 ( struct V_4 * V_5 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
unsigned long V_80 = V_5 -> V_7 . V_21 ;
if ( F_27 ( & V_5 -> V_39 ) == V_40 &&
! F_28 ( V_37 -> V_82 , V_80 ) )
return false ;
F_60 ( V_5 , V_84 ) ;
F_61 ( V_5 , V_85 ,
V_37 -> V_38 -> V_86 + V_87 ) ;
F_58 ( & V_37 -> V_45 ) ;
F_55 ( V_37 ) ;
return true ;
}
static void
F_62 ( struct V_4 * V_5 ,
struct V_51 * V_52 ,
bool (* F_63)( struct V_4 * ,
struct V_34 * ,
struct V_36 * ) )
{
struct V_54 * V_55 ;
struct V_36 * V_37 , * V_88 ;
struct V_34 * V_35 ;
bool V_1 ;
int V_56 ;
if ( ! V_52 )
return;
for ( V_56 = 0 ; V_56 < V_52 -> V_57 ; V_56 ++ ) {
V_55 = & V_52 -> V_58 [ V_56 ] ;
F_40 () ;
F_41 (nc_path, head, hash_entry) {
F_33 ( & V_35 -> V_89 ) ;
F_34 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
V_1 = F_63 ( V_5 , V_35 , V_37 ) ;
if ( ! V_1 )
break;
}
F_37 ( & V_35 -> V_89 ) ;
}
F_42 () ;
}
}
static void V_17 ( struct V_90 * V_8 )
{
struct V_91 * V_91 ;
struct V_92 * V_93 ;
struct V_4 * V_5 ;
unsigned long V_80 ;
V_91 = F_16 ( V_8 , struct V_91 , V_8 ) ;
V_93 = F_16 ( V_91 , struct V_92 , V_8 ) ;
V_5 = F_16 ( V_93 , struct V_4 , V_7 ) ;
F_39 ( V_5 ) ;
F_43 ( V_5 , V_5 -> V_7 . V_12 ,
F_29 ) ;
F_43 ( V_5 , V_5 -> V_7 . V_13 ,
F_30 ) ;
V_80 = V_5 -> V_7 . V_21 ;
if ( F_28 ( V_5 -> V_7 . V_9 , V_80 ) ) {
F_62 ( V_5 , V_5 -> V_7 . V_12 ,
F_59 ) ;
V_5 -> V_7 . V_9 = V_10 ;
}
if ( F_28 ( V_5 -> V_7 . V_11 ,
V_5 -> V_7 . V_22 ) ) {
F_62 ( V_5 , V_5 -> V_7 . V_13 ,
F_57 ) ;
V_5 -> V_7 . V_11 = V_10 ;
}
F_3 ( V_5 ) ;
}
static bool F_64 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
struct V_94 * V_95 )
{
if ( V_24 -> V_96 != F_65 ( V_95 -> V_97 ) )
return false ;
if ( V_24 -> V_98 != V_95 -> V_99 . V_100 + 1 )
return false ;
if ( ! F_66 ( V_95 -> V_50 , V_95 -> V_101 ) )
return false ;
if ( V_95 -> V_102 < V_5 -> V_7 . V_20 )
return false ;
return true ;
}
static struct V_31
* F_67 ( struct V_23 * V_24 ,
struct V_23 * V_103 ,
bool V_104 )
{
struct V_31 * V_32 , * V_105 = NULL ;
struct V_44 * V_45 ;
if ( V_104 )
V_45 = & V_103 -> V_25 ;
else
V_45 = & V_103 -> V_26 ;
F_40 () ;
F_68 (nc_node, list, list) {
if ( ! F_66 ( V_32 -> V_49 , V_24 -> V_50 ) )
continue;
if ( ! F_54 ( & V_32 -> V_33 ) )
continue;
V_105 = V_32 ;
break;
}
F_42 () ;
return V_105 ;
}
static struct V_31
* F_69 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
struct V_23 * V_103 ,
bool V_104 )
{
struct V_31 * V_32 ;
T_2 * V_46 ;
struct V_44 * V_45 ;
V_32 = F_67 ( V_24 , V_103 , V_104 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_70 ( sizeof( * V_32 ) , V_106 ) ;
if ( ! V_32 )
return NULL ;
if ( ! F_54 ( & V_103 -> V_33 ) )
goto free;
F_13 ( & V_32 -> V_45 ) ;
memcpy ( V_32 -> V_49 , V_24 -> V_50 , V_107 ) ;
V_32 -> V_24 = V_103 ;
F_11 ( & V_32 -> V_33 , 2 ) ;
if ( V_104 ) {
V_46 = & V_103 -> V_27 ;
V_45 = & V_103 -> V_25 ;
} else {
V_46 = & V_103 -> V_28 ;
V_45 = & V_103 -> V_26 ;
}
F_35 ( V_48 , V_5 , L_4 ,
V_32 -> V_49 , V_32 -> V_24 -> V_50 ) ;
F_33 ( V_46 ) ;
F_71 ( & V_32 -> V_45 , V_45 ) ;
F_37 ( V_46 ) ;
return V_32 ;
free:
F_18 ( V_32 ) ;
return NULL ;
}
void F_72 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
struct V_23 * V_103 ,
struct V_94 * V_95 ,
int V_108 )
{
struct V_31 * V_109 = NULL , * V_110 = NULL ;
if ( ! F_27 ( & V_5 -> V_19 ) )
goto V_83;
if ( ! F_64 ( V_5 , V_24 , V_95 ) &&
! V_108 )
goto V_83;
V_109 = F_69 ( V_5 , V_24 ,
V_103 , true ) ;
if ( ! V_109 )
goto V_83;
V_109 -> V_41 = V_10 ;
V_110 = F_69 ( V_5 , V_103 ,
V_24 , false ) ;
if ( ! V_110 )
goto V_83;
V_110 -> V_41 = V_10 ;
V_83:
if ( V_109 )
F_19 ( V_109 ) ;
if ( V_110 )
F_19 ( V_110 ) ;
}
static struct V_34 * F_73 ( struct V_4 * V_5 ,
struct V_51 * V_52 ,
T_4 * V_69 ,
T_4 * V_70 )
{
int V_111 ;
struct V_34 * V_35 , V_112 ;
F_49 ( & V_112 , V_69 , V_70 ) ;
V_35 = F_53 ( V_52 , ( void * ) & V_112 ) ;
if ( V_35 ) {
V_35 -> V_43 = V_10 ;
return V_35 ;
}
V_35 = F_70 ( sizeof( * V_35 ) , V_106 ) ;
if ( ! V_35 )
return NULL ;
F_13 ( & V_35 -> V_62 ) ;
F_14 ( & V_35 -> V_89 ) ;
F_11 ( & V_35 -> V_33 , 2 ) ;
V_35 -> V_43 = V_10 ;
memcpy ( V_35 -> V_66 , V_70 , V_107 ) ;
memcpy ( V_35 -> V_65 , V_69 , V_107 ) ;
F_35 ( V_48 , V_5 , L_5 ,
V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_111 = F_74 ( V_52 , F_52 ,
F_50 , & V_112 ,
& V_35 -> V_67 ) ;
if ( V_111 < 0 ) {
F_18 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
static T_4 F_75 ( T_4 V_102 )
{
T_4 V_113 , V_114 ;
F_76 ( & V_113 , sizeof( V_113 ) ) ;
V_114 = V_113 * ( V_115 - V_102 ) ;
V_114 /= V_115 ;
return V_115 - V_114 ;
}
static void F_77 ( char * V_70 , const char * V_69 , unsigned int V_86 )
{
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_86 ; ++ V_56 )
V_70 [ V_56 ] ^= V_69 [ V_56 ] ;
}
static bool F_78 ( struct V_4 * V_5 ,
struct V_116 * V_38 ,
struct V_117 * V_117 ,
struct V_36 * V_37 ,
struct V_118 * V_78 )
{
T_4 V_119 , V_120 ;
struct V_116 * V_121 , * V_122 ;
struct V_123 * V_124 ;
struct V_123 * V_125 ;
struct V_126 * V_127 ;
struct V_118 * V_128 , * V_129 ;
struct V_118 * V_130 = NULL ;
T_4 * V_131 , * V_132 , * V_133 , * V_134 ;
T_5 V_135 , V_136 ;
T_6 V_137 ;
bool V_81 = false ;
int V_138 ;
int V_139 = sizeof( * V_124 ) ;
int V_140 = sizeof( * V_127 ) ;
int V_141 = V_140 - V_139 ;
V_129 = F_79 ( V_78 -> V_24 ) ;
if ( ! V_129 )
goto V_83;
V_128 = V_37 -> V_78 ;
V_130 = F_79 ( V_128 -> V_24 ) ;
if ( ! V_130 )
goto V_83;
V_119 = F_75 ( V_129 -> V_142 ) ;
V_120 = F_75 ( V_130 -> V_142 ) ;
if ( V_119 >= V_120 ) {
V_132 = V_37 -> V_35 -> V_66 ;
V_131 = V_37 -> V_35 -> V_65 ;
V_134 = V_78 -> V_49 ;
V_133 = V_117 -> V_143 ;
V_124 = (struct V_123 * ) V_37 -> V_38 -> V_71 ;
V_125 = (struct V_123 * ) V_38 -> V_71 ;
V_135 = V_37 -> V_144 ;
V_136 = F_80 ( V_38 ,
V_38 -> V_71 + sizeof( * V_125 ) ) ;
} else {
V_132 = V_78 -> V_49 ;
V_131 = V_117 -> V_143 ;
V_134 = V_37 -> V_35 -> V_66 ;
V_133 = V_37 -> V_35 -> V_65 ;
V_124 = (struct V_123 * ) V_38 -> V_71 ;
V_125 = (struct V_123 * ) V_37 -> V_38 -> V_71 ;
V_135 = F_80 ( V_38 ,
V_38 -> V_71 + sizeof( * V_124 ) ) ;
V_136 = V_37 -> V_144 ;
}
if ( V_38 -> V_86 <= V_37 -> V_38 -> V_86 ) {
V_121 = V_37 -> V_38 ;
V_122 = V_38 ;
} else {
V_121 = V_38 ;
V_122 = V_37 -> V_38 ;
}
V_138 = V_122 -> V_86 - V_139 ;
if ( F_81 ( V_121 ) < 0 || F_81 ( V_122 ) < 0 )
goto V_83;
F_82 ( V_121 , V_141 ) ;
V_127 = (struct V_126 * ) V_121 -> V_71 ;
F_83 ( V_121 ) ;
V_127 -> V_99 . V_145 = V_2 ;
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
V_127 -> V_157 = F_84 ( V_138 ) ;
F_77 ( V_121 -> V_71 + V_140 ,
V_122 -> V_71 + V_139 , V_138 ) ;
if ( F_85 ( V_122 ) -> V_158 &&
F_85 ( V_121 ) -> V_158 ) {
V_137 = V_122 -> V_86 + V_87 ;
V_137 += V_121 -> V_86 + V_87 ;
F_61 ( V_5 , V_159 , 2 ) ;
F_61 ( V_5 , V_160 , V_137 ) ;
} else if ( ! F_85 ( V_122 ) -> V_158 &&
! F_85 ( V_121 ) -> V_158 ) {
V_137 = V_122 -> V_86 + V_87 ;
V_137 += V_121 -> V_86 + V_87 ;
F_61 ( V_5 , V_161 , 2 ) ;
F_61 ( V_5 , V_162 , V_137 ) ;
} else if ( F_85 ( V_122 ) -> V_158 &&
! F_85 ( V_121 ) -> V_158 ) {
F_60 ( V_5 , V_159 ) ;
F_61 ( V_5 , V_160 ,
V_122 -> V_86 + V_87 ) ;
F_60 ( V_5 , V_161 ) ;
F_61 ( V_5 , V_162 ,
V_121 -> V_86 + V_87 ) ;
} else if ( ! F_85 ( V_122 ) -> V_158 &&
F_85 ( V_121 ) -> V_158 ) {
F_60 ( V_5 , V_161 ) ;
F_61 ( V_5 , V_162 ,
V_122 -> V_86 + V_87 ) ;
F_60 ( V_5 , V_159 ) ;
F_61 ( V_5 , V_160 ,
V_121 -> V_86 + V_87 ) ;
}
F_25 ( V_122 ) ;
V_37 -> V_38 = NULL ;
F_24 ( V_37 ) ;
F_56 ( V_121 , V_78 -> V_79 , V_132 ) ;
V_81 = true ;
V_83:
if ( V_129 )
F_86 ( V_129 ) ;
if ( V_130 )
F_86 ( V_130 ) ;
return V_81 ;
}
static bool F_87 ( struct V_116 * V_38 ,
T_4 * V_70 , T_4 * V_69 )
{
if ( F_85 ( V_38 ) -> V_158 && ! F_66 ( V_70 , V_69 ) )
return false ;
else
return true ;
}
static struct V_36 *
F_88 ( struct V_4 * V_5 ,
struct V_31 * V_109 ,
struct V_31 * V_110 ,
struct V_116 * V_38 ,
T_4 * V_163 )
{
struct V_34 * V_35 , V_112 ;
struct V_36 * V_164 = NULL ;
struct V_36 * V_37 , * V_88 ;
struct V_51 * V_52 = V_5 -> V_7 . V_12 ;
int V_165 ;
if ( ! V_52 )
return NULL ;
F_49 ( & V_112 , V_109 -> V_49 ,
V_110 -> V_49 ) ;
V_165 = F_50 ( & V_112 , V_52 -> V_57 ) ;
F_40 () ;
F_41 (nc_path, &hash->table[idx], hash_entry) {
if ( ! F_66 ( V_35 -> V_65 , V_109 -> V_49 ) )
continue;
if ( ! F_66 ( V_35 -> V_66 , V_110 -> V_49 ) )
continue;
F_33 ( & V_35 -> V_89 ) ;
if ( F_46 ( & V_35 -> V_62 ) ) {
F_37 ( & V_35 -> V_89 ) ;
continue;
}
F_34 (nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if ( ! F_87 ( V_37 -> V_38 ,
V_163 ,
V_109 -> V_49 ) )
continue;
F_58 ( & V_37 -> V_45 ) ;
V_164 = V_37 ;
break;
}
F_37 ( & V_35 -> V_89 ) ;
break;
}
F_42 () ;
return V_164 ;
}
static struct V_36 *
F_89 ( struct V_4 * V_5 ,
struct V_116 * V_38 ,
T_4 * V_163 ,
T_4 * V_166 ,
struct V_31 * V_109 )
{
struct V_23 * V_24 ;
struct V_31 * V_110 ;
struct V_36 * V_37 = NULL ;
V_24 = F_90 ( V_5 , V_166 ) ;
if ( ! V_24 )
return NULL ;
F_40 () ;
F_68 (out_nc_node,
&orig_node->out_coding_list, list) {
if ( ! F_87 ( V_38 ,
V_110 -> V_49 , V_166 ) )
continue;
V_37 = F_88 ( V_5 , V_109 ,
V_110 , V_38 , V_163 ) ;
if ( V_37 )
break;
}
F_42 () ;
F_17 ( V_24 ) ;
return V_37 ;
}
static void F_91 ( struct V_4 * V_5 ,
struct V_116 * V_38 ,
T_4 * V_167 )
{
struct V_117 * V_117 ;
V_38 = F_92 ( V_38 , V_106 ) ;
if ( ! V_38 )
return;
V_117 = F_93 ( V_38 ) ;
memcpy ( V_117 -> V_143 , V_117 -> V_168 , V_107 ) ;
memcpy ( V_117 -> V_168 , V_167 , V_107 ) ;
F_82 ( V_38 , V_87 ) ;
F_94 ( V_5 , V_38 ) ;
F_25 ( V_38 ) ;
}
static bool F_95 ( struct V_116 * V_38 ,
struct V_118 * V_78 ,
struct V_117 * V_117 )
{
struct V_169 * V_170 = V_78 -> V_79 -> V_171 ;
struct V_4 * V_5 = F_96 ( V_170 ) ;
struct V_23 * V_24 = V_78 -> V_24 ;
struct V_31 * V_32 ;
struct V_36 * V_37 = NULL ;
F_40 () ;
F_68 (nc_node, &orig_node->in_coding_list, list) {
V_37 = F_89 ( V_5 , V_38 ,
V_78 -> V_49 ,
V_117 -> V_143 , V_32 ) ;
if ( V_37 )
break;
}
F_42 () ;
if ( ! V_37 )
return false ;
F_91 ( V_5 , V_38 ,
V_78 -> V_49 ) ;
F_91 ( V_5 , V_37 -> V_38 ,
V_37 -> V_78 -> V_49 ) ;
if ( F_78 ( V_5 , V_38 , V_117 , V_37 ,
V_78 ) )
return true ;
F_55 ( V_37 ) ;
return false ;
}
static bool F_97 ( struct V_116 * V_38 ,
struct V_34 * V_35 ,
struct V_118 * V_78 ,
T_5 V_144 )
{
struct V_36 * V_37 ;
V_37 = F_70 ( sizeof( * V_37 ) , V_106 ) ;
if ( ! V_37 )
return false ;
V_37 -> V_82 = V_10 ;
V_37 -> V_144 = V_144 ;
V_37 -> V_38 = V_38 ;
V_37 -> V_78 = V_78 ;
V_37 -> V_35 = V_35 ;
F_33 ( & V_35 -> V_89 ) ;
F_98 ( & V_37 -> V_45 , & V_35 -> V_62 ) ;
F_37 ( & V_35 -> V_89 ) ;
return true ;
}
bool F_99 ( struct V_116 * V_38 ,
struct V_118 * V_78 )
{
const struct V_169 * V_170 = V_78 -> V_79 -> V_171 ;
struct V_4 * V_5 = F_96 ( V_170 ) ;
struct V_123 * V_172 ;
struct V_34 * V_35 ;
struct V_117 * V_117 = F_93 ( V_38 ) ;
T_5 V_144 ;
T_7 * V_173 ;
if ( ! F_27 ( & V_5 -> V_19 ) )
goto V_83;
V_173 = F_100 ( V_38 ) ;
V_172 = (struct V_123 * ) V_173 ;
if ( V_172 -> V_99 . V_145 != V_174 )
goto V_83;
if ( F_95 ( V_38 , V_78 , V_117 ) )
return true ;
V_35 = F_73 ( V_5 ,
V_5 -> V_7 . V_12 ,
V_117 -> V_143 ,
V_78 -> V_49 ) ;
if ( ! V_35 )
goto V_83;
V_144 = F_80 ( V_38 , V_173 + sizeof( * V_172 ) ) ;
if ( ! F_97 ( V_38 , V_35 , V_78 , V_144 ) )
goto V_175;
return true ;
V_175:
F_22 ( V_35 ) ;
V_83:
return false ;
}
void F_94 ( struct V_4 * V_5 ,
struct V_116 * V_38 )
{
struct V_123 * V_172 ;
struct V_34 * V_35 ;
struct V_117 * V_117 = F_93 ( V_38 ) ;
T_5 V_144 ;
T_7 * V_173 ;
if ( ! F_27 ( & V_5 -> V_19 ) )
goto V_83;
V_173 = F_100 ( V_38 ) ;
V_172 = (struct V_123 * ) V_173 ;
if ( V_172 -> V_99 . V_145 != V_174 )
goto V_83;
V_35 = F_73 ( V_5 ,
V_5 -> V_7 . V_13 ,
V_117 -> V_143 ,
V_117 -> V_168 ) ;
if ( ! V_35 )
goto V_83;
V_38 = F_101 ( V_38 , V_106 ) ;
if ( F_45 ( ! V_38 ) )
goto V_175;
if ( F_45 ( ! F_102 ( V_38 , V_87 ) ) )
goto V_176;
if ( F_45 ( ! F_103 ( V_38 , V_87 ) ) )
goto V_176;
V_144 = F_80 ( V_38 , V_173 + sizeof( * V_172 ) ) ;
if ( ! F_97 ( V_38 , V_35 , NULL , V_144 ) )
goto V_176;
F_60 ( V_5 , V_177 ) ;
return;
V_176:
F_25 ( V_38 ) ;
V_175:
F_22 ( V_35 ) ;
V_83:
return;
}
void F_104 ( struct V_4 * V_5 ,
struct V_116 * V_38 )
{
struct V_117 * V_117 = F_93 ( V_38 ) ;
if ( F_105 ( V_5 , V_117 -> V_168 ) )
return;
F_82 ( V_38 , V_87 ) ;
F_94 ( V_5 , V_38 ) ;
}
static struct V_123 *
F_106 ( struct V_4 * V_5 , struct V_116 * V_38 ,
struct V_36 * V_37 )
{
const int V_178 = sizeof( struct V_123 ) ;
const int V_179 = sizeof( struct V_126 ) - V_178 ;
struct V_123 * V_180 ;
struct V_126 V_181 ;
struct V_117 * V_117 , V_182 ;
T_4 * V_183 , V_100 , V_152 ;
unsigned int V_138 ;
int V_14 ;
memcpy ( & V_181 , V_38 -> V_71 , sizeof( V_181 ) ) ;
memcpy ( & V_182 , F_107 ( V_38 ) , sizeof( V_182 ) ) ;
if ( F_108 ( V_38 , 0 ) < 0 )
return NULL ;
if ( F_45 ( ! F_103 ( V_38 , V_179 ) ) )
return NULL ;
F_109 ( V_38 , - V_87 ) ;
F_110 ( V_38 ) ;
V_117 = F_93 ( V_38 ) ;
memcpy ( V_117 , & V_182 , sizeof( * V_117 ) ) ;
if ( F_105 ( V_5 , V_181 . V_134 ) ) {
memcpy ( V_117 -> V_168 , V_181 . V_134 , V_107 ) ;
V_38 -> V_184 = V_185 ;
V_183 = V_181 . V_153 ;
V_100 = V_181 . V_155 ;
V_152 = V_181 . V_156 ;
} else {
V_183 = V_181 . V_148 ;
V_100 = V_181 . V_99 . V_100 ;
V_152 = V_181 . V_151 ;
}
V_138 = F_111 ( V_181 . V_157 ) ;
if ( V_138 > V_38 -> V_86 )
return NULL ;
F_77 ( V_38 -> V_71 + V_178 ,
V_37 -> V_38 -> V_71 + V_178 ,
V_138 ) ;
if ( V_37 -> V_38 -> V_86 > V_138 + V_178 ) {
V_14 = F_112 ( V_38 , V_138 + V_178 ) ;
if ( V_14 )
return NULL ;
}
V_180 = (struct V_123 * ) V_38 -> V_71 ;
V_180 -> V_99 . V_145 = V_174 ;
V_180 -> V_99 . V_146 = V_147 ;
V_180 -> V_99 . V_100 = V_100 ;
memcpy ( V_180 -> V_149 , V_183 , V_107 ) ;
V_180 -> V_152 = V_152 ;
F_24 ( V_37 ) ;
return V_180 ;
}
static struct V_36 *
F_113 ( struct V_4 * V_5 ,
struct V_117 * V_117 ,
struct V_126 * V_186 )
{
struct V_51 * V_52 = V_5 -> V_7 . V_13 ;
struct V_36 * V_187 , * V_37 = NULL ;
struct V_34 * V_35 , V_112 ;
T_4 * V_149 , * V_188 ;
T_5 V_144 ;
int V_77 ;
if ( ! V_52 )
return NULL ;
V_149 = V_117 -> V_143 ;
if ( ! F_105 ( V_5 , V_186 -> V_134 ) ) {
V_188 = V_186 -> V_133 ;
V_144 = V_186 -> V_154 ;
} else {
V_188 = V_186 -> V_131 ;
V_144 = V_186 -> V_150 ;
}
F_49 ( & V_112 , V_188 , V_149 ) ;
V_77 = F_50 ( & V_112 , V_52 -> V_57 ) ;
F_40 () ;
F_41 (nc_path, &hash->table[index], hash_entry) {
F_33 ( & V_35 -> V_89 ) ;
F_114 (tmp_nc_packet,
&nc_path->packet_list, list) {
if ( V_144 == V_187 -> V_144 ) {
F_58 ( & V_187 -> V_45 ) ;
V_37 = V_187 ;
break;
}
}
F_37 ( & V_35 -> V_89 ) ;
if ( V_37 )
break;
}
F_42 () ;
if ( ! V_37 )
F_35 ( V_48 , V_5 ,
L_6 , V_144 ) ;
return V_37 ;
}
static int V_3 ( struct V_116 * V_38 ,
struct V_189 * V_190 )
{
struct V_4 * V_5 = F_96 ( V_190 -> V_171 ) ;
struct V_123 * V_180 ;
struct V_126 * V_127 ;
struct V_36 * V_37 ;
struct V_117 * V_117 ;
int V_191 = sizeof( * V_127 ) ;
if ( ! F_27 ( & V_5 -> V_19 ) )
return V_192 ;
if ( F_45 ( ! F_102 ( V_38 , V_191 ) ) )
return V_192 ;
V_127 = (struct V_126 * ) V_38 -> V_71 ;
V_117 = F_93 ( V_38 ) ;
if ( ! F_105 ( V_5 , V_117 -> V_168 ) &&
! F_105 ( V_5 , V_127 -> V_134 ) )
return V_192 ;
if ( F_105 ( V_5 , V_127 -> V_134 ) )
F_60 ( V_5 , V_193 ) ;
V_37 = F_113 ( V_5 , V_117 ,
V_127 ) ;
if ( ! V_37 ) {
F_60 ( V_5 , V_194 ) ;
return V_192 ;
}
if ( F_81 ( V_38 ) < 0 )
goto V_195;
if ( F_81 ( V_37 -> V_38 ) < 0 )
goto V_195;
V_180 = F_106 ( V_5 , V_38 , V_37 ) ;
if ( ! V_180 ) {
F_60 ( V_5 , V_194 ) ;
goto V_195;
}
F_85 ( V_38 ) -> V_158 = true ;
F_60 ( V_5 , V_196 ) ;
F_61 ( V_5 , V_197 ,
V_38 -> V_86 + V_87 ) ;
return F_115 ( V_38 , V_190 ) ;
V_195:
F_24 ( V_37 ) ;
return V_192 ;
}
void F_116 ( struct V_4 * V_5 )
{
F_117 ( & V_5 -> V_7 . V_8 ) ;
F_43 ( V_5 , V_5 -> V_7 . V_12 , NULL ) ;
F_118 ( V_5 -> V_7 . V_12 ) ;
F_43 ( V_5 , V_5 -> V_7 . V_13 , NULL ) ;
F_118 ( V_5 -> V_7 . V_13 ) ;
}
int F_119 ( struct V_198 * V_199 , void * V_200 )
{
struct V_169 * V_201 = (struct V_169 * ) V_199 -> V_202 ;
struct V_4 * V_5 = F_96 ( V_201 ) ;
struct V_51 * V_52 = V_5 -> V_53 ;
struct V_189 * V_203 ;
struct V_54 * V_55 ;
struct V_23 * V_24 ;
struct V_31 * V_32 ;
int V_56 ;
V_203 = F_120 ( V_199 ) ;
if ( ! V_203 )
goto V_83;
for ( V_56 = 0 ; V_56 < V_52 -> V_57 ; V_56 ++ ) {
V_55 = & V_52 -> V_58 [ V_56 ] ;
F_40 () ;
F_41 (orig_node, head, hash_entry) {
if ( F_46 ( & V_24 -> V_25 ) &&
F_46 ( & V_24 -> V_26 ) )
continue;
F_121 ( V_199 , L_7 , V_24 -> V_50 ) ;
F_122 ( V_199 , L_8 ) ;
F_68 (nc_node,
&orig_node->in_coding_list,
list)
F_121 ( V_199 , L_9 ,
V_32 -> V_49 ) ;
F_122 ( V_199 , L_10 ) ;
F_122 ( V_199 , L_11 ) ;
F_68 (nc_node,
&orig_node->out_coding_list,
list)
F_121 ( V_199 , L_9 ,
V_32 -> V_49 ) ;
F_122 ( V_199 , L_12 ) ;
}
F_42 () ;
}
V_83:
if ( V_203 )
F_123 ( V_203 ) ;
return 0 ;
}
int F_124 ( struct V_4 * V_5 )
{
struct V_204 * V_205 , * V_206 ;
V_205 = F_125 ( L_13 , V_5 -> V_207 ) ;
if ( ! V_205 )
goto V_83;
V_206 = F_126 ( L_14 , V_208 | V_209 , V_205 ,
& V_5 -> V_7 . V_20 ) ;
if ( ! V_206 )
goto V_83;
V_206 = F_127 ( L_15 , V_208 | V_209 , V_205 ,
& V_5 -> V_7 . V_21 ) ;
if ( ! V_206 )
goto V_83;
V_206 = F_127 ( L_16 , V_208 | V_209 , V_205 ,
& V_5 -> V_7 . V_22 ) ;
if ( ! V_206 )
goto V_83;
return 0 ;
V_83:
return - V_18 ;
}
