static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
unsigned long V_8 ;
V_4 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_2 -> V_9 , struct V_5 , V_9 ) ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
V_7 = F_5 ( V_2 ) ;
F_6 ( & V_4 -> V_11 , & V_6 -> V_12 ) ;
F_7 ( & V_6 -> V_10 , V_8 ) ;
return V_7 ;
}
static void F_8 ( struct V_13 * V_9 )
{
struct V_5 * V_6 ;
int V_14 ;
struct V_3 * V_4 , * V_15 ;
unsigned long V_8 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
V_14 = F_9 (
F_10 ( & V_6 -> V_16 -> V_17 ) ) ;
F_11 (desc, _desc, &re_chan->submit_q, node) {
if ( ! V_14 )
break;
F_12 ( & V_4 -> V_11 , & V_6 -> V_18 ) ;
memcpy ( & V_6 -> V_19 [ V_6 -> V_20 ] ,
& V_4 -> V_21 , sizeof( struct V_22 ) ) ;
V_6 -> V_20 = ( V_6 -> V_20 + 1 ) &
V_23 ;
F_13 ( & V_6 -> V_16 -> V_24 , F_14 ( 1 ) ) ;
V_14 -- ;
}
F_7 ( & V_6 -> V_10 , V_8 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_16 ( & V_4 -> V_25 ) ;
F_17 ( & V_4 -> V_25 ) ;
F_18 ( & V_4 -> V_25 , NULL ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_3 * V_4 , * V_15 ;
unsigned long V_8 ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
F_11 (desc, _desc, &re_chan->ack_q, node) {
if ( F_20 ( & V_4 -> V_25 ) )
F_12 ( & V_4 -> V_11 , & V_6 -> V_26 ) ;
}
F_7 ( & V_6 -> V_10 , V_8 ) ;
F_8 ( & V_6 -> V_9 ) ;
}
static void F_21 ( unsigned long V_27 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 , * V_15 ;
struct V_22 * V_21 ;
unsigned long V_8 ;
unsigned int V_28 , V_29 ;
int V_30 ;
V_6 = F_22 ( (struct V_31 * ) V_27 ) ;
F_19 ( V_6 ) ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
V_28 = F_23 ( F_10 ( & V_6 -> V_16 -> V_32 ) ) ;
while ( V_28 -- ) {
V_30 = 0 ;
V_21 = & V_6 -> V_33 [ V_6 -> V_29 ] ;
F_11 (desc, _desc, &re_chan->active_q,
node) {
if ( V_4 -> V_21 . V_34 == V_21 -> V_34 &&
V_4 -> V_21 . V_35 == V_21 -> V_35 ) {
V_30 = 1 ;
break;
}
}
if ( V_30 ) {
F_15 ( V_4 ) ;
F_12 ( & V_4 -> V_11 , & V_6 -> V_36 ) ;
} else {
F_24 ( V_6 -> V_37 ,
L_1 ) ;
}
V_29 = ( V_6 -> V_29 + 1 ) & V_23 ;
V_6 -> V_29 = V_29 ;
F_13 ( & V_6 -> V_16 -> V_38 ,
F_25 ( 1 ) ) ;
}
F_7 ( & V_6 -> V_10 , V_8 ) ;
}
static T_2 F_26 ( int V_39 , void * V_27 )
{
struct V_5 * V_6 ;
T_3 V_40 , V_41 ;
V_6 = F_22 ( (struct V_31 * ) V_27 ) ;
V_40 = F_10 ( & V_6 -> V_16 -> V_42 ) ;
if ( ! V_40 )
return V_43 ;
if ( V_40 & V_44 ) {
V_41 = F_10 ( & V_6 -> V_16 -> V_45 ) ;
F_24 ( V_6 -> V_37 , L_2 ,
V_40 , V_41 ) ;
}
F_13 ( & V_6 -> V_16 -> V_42 , V_46 ) ;
F_27 ( & V_6 -> V_47 ) ;
return V_48 ;
}
static enum V_49 F_28 ( struct V_13 * V_9 ,
T_1 V_7 ,
struct V_50 * V_51 )
{
return F_29 ( V_9 , V_7 , V_51 ) ;
}
static void F_30 ( struct V_52 * V_53 , T_4 V_54 ,
T_5 V_55 , T_6 V_56 , bool V_57 )
{
T_3 V_58 = V_55 & V_59 ;
V_58 |= V_57 << V_60 ;
V_53 [ V_54 ] . V_61 = V_58 ;
V_53 [ V_54 ] . V_62 = F_31 ( V_56 ) ;
V_53 [ V_54 ] . V_35 = F_32 ( V_56 ) ;
}
static struct V_3 * F_33 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
void * V_53 , T_6 V_63 )
{
V_4 -> V_6 = V_6 ;
V_4 -> V_25 . V_64 = F_1 ;
F_34 ( & V_4 -> V_25 , & V_6 -> V_9 ) ;
F_35 ( & V_4 -> V_11 ) ;
V_4 -> V_21 . V_65 = V_66 << V_67 ;
V_4 -> V_21 . V_34 = F_31 ( V_63 ) ;
V_4 -> V_21 . V_35 = F_32 ( V_63 ) ;
V_4 -> V_68 = V_53 ;
V_4 -> V_69 = V_63 ;
V_4 -> V_70 = ( void * ) ( V_53 + V_71 ) ;
V_4 -> V_72 = V_63 + V_71 ;
return V_4 ;
}
static struct V_3 * F_36 ( struct V_5 * V_6 ,
unsigned long V_8 )
{
struct V_3 * V_4 = NULL ;
void * V_53 ;
T_6 V_63 ;
unsigned long V_73 ;
F_19 ( V_6 ) ;
F_4 ( & V_6 -> V_10 , V_73 ) ;
if ( ! F_37 ( & V_6 -> V_26 ) ) {
V_4 = F_38 ( & V_6 -> V_26 ,
struct V_3 , V_11 ) ;
F_39 ( & V_4 -> V_11 ) ;
V_4 -> V_25 . V_8 = V_8 ;
}
F_7 ( & V_6 -> V_10 , V_73 ) ;
if ( ! V_4 ) {
V_4 = F_40 ( sizeof( * V_4 ) , V_74 ) ;
if ( ! V_4 )
return NULL ;
V_53 = F_41 ( V_6 -> V_75 -> V_76 , V_74 ,
& V_63 ) ;
if ( ! V_53 ) {
F_42 ( V_4 ) ;
return NULL ;
}
V_4 = F_33 ( V_6 , V_4 , V_53 , V_63 ) ;
V_4 -> V_25 . V_8 = V_8 ;
F_4 ( & V_6 -> V_10 , V_73 ) ;
V_6 -> V_77 ++ ;
F_7 ( & V_6 -> V_10 , V_73 ) ;
}
return V_4 ;
}
static struct V_1 * F_43 (
struct V_13 * V_9 , T_6 V_78 , T_6 * V_79 ,
unsigned int V_80 , const unsigned char * V_81 , T_5 V_82 ,
unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_83 * V_84 ;
struct V_52 * V_53 ;
T_3 V_85 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 = V_80 ;
int V_89 = 0 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_82 > V_90 ) {
F_24 ( V_6 -> V_37 , L_3 ,
V_82 , V_90 ) ;
return NULL ;
}
V_4 = F_36 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
if ( V_81 && ( V_8 & V_91 ) ) {
V_89 = 1 ;
V_80 += 1 ;
}
V_85 = V_92 << V_93 ;
V_85 |= ( V_80 - 1 ) << V_94 ;
V_85 |= V_95 << V_96 ;
V_85 |= V_97 << V_98 ;
V_85 |= V_99 << V_100 ;
V_84 = V_4 -> V_70 ;
V_84 -> V_101 = V_85 ;
if ( V_81 ) {
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ )
V_84 -> V_102 [ V_86 ] = V_81 [ V_86 ] ;
if ( V_89 )
V_84 -> V_102 [ V_86 ++ ] = 1 ;
} else {
for ( V_86 = 0 ; V_86 < V_80 ; V_86 ++ )
V_84 -> V_102 [ V_86 ] = 1 ;
}
V_53 = V_4 -> V_68 ;
F_30 ( V_53 , 0 , sizeof( * V_84 ) , V_4 -> V_72 , 0 ) ;
F_30 ( V_53 , 1 , V_82 , V_78 , 0 ) ;
for ( V_86 = 2 , V_87 = 0 ; V_87 < V_88 ; V_86 ++ , V_87 ++ )
F_30 ( V_53 , V_86 , V_82 , V_79 [ V_87 ] , 0 ) ;
if ( V_89 )
F_30 ( V_53 , V_86 ++ , V_82 , V_78 , 0 ) ;
V_53 [ V_86 - 1 ] . V_61 |= 1 << V_60 ;
return & V_4 -> V_25 ;
}
static struct V_1 * F_44 (
struct V_13 * V_9 , T_6 V_78 , T_6 * V_79 ,
unsigned int V_80 , T_5 V_82 , unsigned long V_8 )
{
return F_43 ( V_9 , V_78 , V_79 , V_80 , NULL , V_82 , V_8 ) ;
}
static struct V_1 * F_45 (
struct V_13 * V_9 , T_6 * V_78 , T_6 * V_79 ,
unsigned int V_80 , const unsigned char * V_81 , T_5 V_82 ,
unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_103 * V_104 ;
struct V_52 * V_53 ;
T_3 V_85 ;
T_4 * V_105 ;
int V_106 , V_86 , V_87 ;
unsigned int V_88 = V_80 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_82 > V_90 ) {
F_24 ( V_6 -> V_37 , L_4 ,
V_82 , V_90 ) ;
return NULL ;
}
if ( V_80 == 1 ) {
struct V_1 * V_2 ;
T_6 V_107 [ 2 ] ;
unsigned char V_108 [ 2 ] ;
V_107 [ 0 ] = * V_79 ;
V_108 [ 0 ] = * V_81 ;
V_107 [ 1 ] = * V_79 ;
V_108 [ 1 ] = 0 ;
V_2 = F_43 ( V_9 , V_78 [ 1 ] , V_107 , 2 , V_108 , V_82 ,
V_8 ) ;
if ( V_2 )
V_4 = F_2 ( V_2 ) ;
return V_2 ;
}
if ( V_8 & V_109 )
return F_43 ( V_9 , V_78 [ 1 ] , V_79 , V_80 ,
V_81 , V_82 , V_8 ) ;
if ( V_8 & V_91 )
V_80 += 3 ;
V_4 = F_36 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
V_85 = V_110 << V_93 ;
V_85 |= ( V_80 - 1 ) << V_94 ;
V_85 |= V_95 << V_96 ;
V_85 |= V_111 << V_112 ;
V_85 |= V_99 << V_100 ;
V_104 = V_4 -> V_70 ;
V_104 -> V_101 = V_85 ;
V_105 = V_104 -> V_113 ;
for ( V_86 = 0 ; V_86 < V_80 ; V_86 ++ )
V_105 [ V_86 ] = 1 ;
V_106 = F_46 ( V_80 , 4 ) ;
V_105 += V_106 ;
for ( V_86 = 0 ; V_86 < V_80 ; V_86 ++ )
V_105 [ V_86 ] = V_81 [ V_86 ] ;
V_53 = V_4 -> V_68 ;
F_30 ( V_53 , 0 , sizeof( struct V_103 ) , V_4 -> V_72 , 0 ) ;
for ( V_86 = 1 , V_87 = 0 ; V_86 < 3 ; V_86 ++ , V_87 ++ )
F_30 ( V_53 , V_86 , V_82 , V_78 [ V_87 ] , 0 ) ;
for ( V_86 = 3 , V_87 = 0 ; V_87 < V_88 ; V_86 ++ , V_87 ++ )
F_30 ( V_53 , V_86 , V_82 , V_79 [ V_87 ] , 0 ) ;
if ( V_8 & V_91 ) {
if ( V_80 - V_88 == 3 ) {
V_105 [ V_88 ] = 0 ;
V_105 [ V_88 + 1 ] = 0 ;
V_105 [ V_88 + 2 ] = 1 ;
F_30 ( V_53 , V_86 ++ , V_82 , V_78 [ 0 ] , 0 ) ;
F_30 ( V_53 , V_86 ++ , V_82 , V_78 [ 1 ] , 0 ) ;
F_30 ( V_53 , V_86 ++ , V_82 , V_78 [ 1 ] , 0 ) ;
} else {
F_24 ( V_6 -> V_37 , L_5 ) ;
return NULL ;
}
}
V_53 [ V_86 - 1 ] . V_61 |= 1 << V_60 ;
return & V_4 -> V_25 ;
}
static struct V_1 * F_47 (
struct V_13 * V_9 , T_6 V_78 , T_6 V_79 ,
T_5 V_82 , unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_5 V_55 ;
struct V_52 * V_53 ;
struct V_114 * V_115 ;
T_3 V_85 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_82 > V_90 ) {
F_24 ( V_6 -> V_37 , L_6 ,
V_82 , V_90 ) ;
return NULL ;
}
V_4 = F_36 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
V_85 = V_116 << V_93 ;
V_85 |= V_95 << V_96 ;
V_85 |= V_97 << V_98 ;
V_85 |= V_99 << V_100 ;
V_115 = V_4 -> V_70 ;
V_115 -> V_101 = V_85 ;
V_53 = V_4 -> V_68 ;
F_30 ( V_53 , 0 , sizeof( * V_115 ) , V_4 -> V_72 , 0 ) ;
V_55 = F_48 ( T_5 , V_82 , V_90 ) ;
F_30 ( V_53 , 1 , V_55 , V_78 , 0 ) ;
F_30 ( V_53 , 2 , V_55 , V_79 , 1 ) ;
return & V_4 -> V_25 ;
}
static int F_49 ( struct V_13 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
void * V_53 ;
T_6 V_63 ;
int V_86 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
for ( V_86 = 0 ; V_86 < V_117 ; V_86 ++ ) {
V_4 = F_40 ( sizeof( * V_4 ) , V_118 ) ;
if ( ! V_4 )
break;
V_53 = F_41 ( V_6 -> V_75 -> V_76 , V_118 ,
& V_63 ) ;
if ( ! V_53 ) {
F_42 ( V_4 ) ;
break;
}
F_35 ( & V_4 -> V_11 ) ;
F_33 ( V_6 , V_4 , V_53 , V_63 ) ;
F_6 ( & V_4 -> V_11 , & V_6 -> V_26 ) ;
V_6 -> V_77 ++ ;
}
return V_6 -> V_77 ;
}
static void F_50 ( struct V_13 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
while ( V_6 -> V_77 -- ) {
V_4 = F_38 ( & V_6 -> V_26 ,
struct V_3 ,
V_11 ) ;
F_39 ( & V_4 -> V_11 ) ;
F_51 ( V_6 -> V_75 -> V_76 , V_4 -> V_68 ,
V_4 -> V_69 ) ;
F_42 ( V_4 ) ;
}
if ( ! F_37 ( & V_6 -> V_26 ) )
F_24 ( V_6 -> V_37 , L_7 ) ;
}
static int F_52 ( struct V_119 * V_120 ,
struct V_121 * V_122 , T_4 V_123 , T_3 V_124 )
{
struct V_31 * V_37 , * V_125 ;
struct V_126 * V_127 ;
struct V_5 * V_9 ;
struct V_128 * V_129 ;
T_3 V_130 ;
T_3 V_41 ;
int V_131 = 0 , V_132 ;
struct V_119 * V_133 ;
V_37 = & V_120 -> V_37 ;
V_127 = F_22 ( V_37 ) ;
V_129 = & V_127 -> V_129 ;
V_9 = F_53 ( V_37 , sizeof( * V_9 ) , V_118 ) ;
if ( ! V_9 )
return - V_134 ;
V_133 = F_54 ( V_122 , NULL , V_37 ) ;
if ( ! V_133 ) {
F_24 ( V_37 , L_8 , V_123 ) ;
V_131 = - V_135 ;
goto V_136;
}
V_132 = F_55 ( V_122 , L_9 , & V_130 ) ;
if ( V_132 ) {
F_24 ( V_37 , L_10 , V_123 ) ;
V_131 = - V_137 ;
goto V_136;
}
V_9 -> V_16 = (struct V_138 * ) ( ( T_4 * ) V_127 -> V_139 +
V_124 + V_130 ) ;
V_9 -> V_39 = F_56 ( V_122 , 0 ) ;
if ( ! V_9 -> V_39 ) {
F_24 ( V_37 , L_11 , V_123 ) ;
V_131 = - V_137 ;
goto V_136;
}
snprintf ( V_9 -> V_140 , sizeof( V_9 -> V_140 ) , L_12 , V_123 ) ;
V_125 = & V_133 -> V_37 ;
F_57 ( & V_9 -> V_47 , F_21 , ( unsigned long ) V_125 ) ;
V_131 = F_58 ( V_9 -> V_39 , F_26 , 0 , V_9 -> V_140 , V_125 ) ;
if ( V_131 ) {
F_24 ( V_37 , L_13 , V_123 ) ;
V_131 = - V_135 ;
goto V_136;
}
V_127 -> V_141 [ V_123 ] = V_9 ;
V_9 -> V_9 . V_31 = V_129 ;
V_9 -> V_9 . V_142 = V_9 ;
V_9 -> V_37 = V_125 ;
V_9 -> V_75 = V_127 ;
F_59 ( & V_9 -> V_10 ) ;
F_35 ( & V_9 -> V_36 ) ;
F_35 ( & V_9 -> V_18 ) ;
F_35 ( & V_9 -> V_12 ) ;
F_35 ( & V_9 -> V_26 ) ;
V_9 -> V_19 = F_41 ( V_9 -> V_75 -> V_143 ,
V_118 , & V_9 -> V_144 ) ;
if ( ! V_9 -> V_19 ) {
F_24 ( V_37 , L_14 ) ;
V_131 = - V_134 ;
goto V_136;
}
V_9 -> V_33 = F_41 ( V_9 -> V_75 -> V_143 ,
V_118 , & V_9 -> V_145 ) ;
if ( ! V_9 -> V_33 ) {
F_24 ( V_37 , L_15 ) ;
V_131 = - V_134 ;
goto V_146;
}
F_13 ( & V_9 -> V_16 -> V_147 ,
V_9 -> V_144 & V_148 ) ;
F_13 ( & V_9 -> V_16 -> V_149 ,
V_9 -> V_145 & V_148 ) ;
F_13 ( & V_9 -> V_16 -> V_150 ,
V_9 -> V_144 >> V_151 ) ;
F_13 ( & V_9 -> V_16 -> V_152 ,
V_9 -> V_145 >> V_151 ) ;
F_13 ( & V_9 -> V_16 -> V_153 ,
V_154 << V_155 ) ;
F_13 ( & V_9 -> V_16 -> V_156 ,
V_154 << V_155 ) ;
V_41 = F_10 ( & V_9 -> V_16 -> V_157 ) & V_158 ;
F_13 ( & V_9 -> V_16 -> V_157 ,
V_159 | V_160 | V_41 ) ;
F_60 ( V_125 , V_9 ) ;
F_13 ( & V_9 -> V_16 -> V_161 , V_162 ) ;
return 0 ;
V_146:
F_51 ( V_9 -> V_75 -> V_143 , V_9 -> V_19 ,
V_9 -> V_144 ) ;
V_136:
return V_131 ;
}
static int F_61 ( struct V_119 * V_120 )
{
struct V_126 * V_127 ;
struct V_121 * V_122 ;
struct V_121 * V_163 ;
T_3 V_124 ;
T_4 V_164 = 0 ;
struct V_128 * V_129 ;
struct V_165 * V_166 ;
int V_132 ;
struct V_31 * V_37 = & V_120 -> V_37 ;
V_127 = F_53 ( V_37 , sizeof( * V_127 ) , V_118 ) ;
if ( ! V_127 )
return - V_134 ;
V_166 = F_62 ( V_120 , V_167 , 0 ) ;
if ( ! V_166 )
return - V_137 ;
V_127 -> V_139 = F_63 ( V_37 , V_166 -> V_168 , F_64 ( V_166 ) ) ;
if ( ! V_127 -> V_139 )
return - V_169 ;
F_13 ( & V_127 -> V_139 -> V_170 , V_171 ) ;
F_13 ( & V_127 -> V_139 -> V_172 , V_173 ) ;
F_65 ( V_37 , L_16 ,
F_10 ( & V_127 -> V_139 -> V_174 ) ,
F_10 ( & V_127 -> V_139 -> V_170 ) ,
F_10 ( & V_127 -> V_139 -> V_172 ) ) ;
V_129 = & V_127 -> V_129 ;
V_129 -> V_37 = V_37 ;
F_35 ( & V_129 -> V_175 ) ;
F_66 ( V_37 , F_67 ( 40 ) ) ;
V_129 -> V_176 = F_49 ;
V_129 -> V_177 = F_28 ;
V_129 -> V_178 = F_8 ;
V_129 -> V_179 = V_180 ;
V_129 -> V_181 = F_44 ;
F_68 ( V_182 , V_129 -> V_183 ) ;
V_129 -> V_184 = V_185 ;
V_129 -> V_186 = F_45 ;
F_68 ( V_187 , V_129 -> V_183 ) ;
V_129 -> V_188 = F_47 ;
F_68 ( V_189 , V_129 -> V_183 ) ;
V_129 -> V_190 = F_50 ;
V_127 -> V_191 = 0 ;
V_127 -> V_76 = F_69 ( L_17 , V_37 ,
V_192 ,
V_193 , 0 ) ;
if ( ! V_127 -> V_76 ) {
F_24 ( V_37 , L_18 ) ;
return - V_134 ;
}
V_127 -> V_143 = F_69 ( L_19 , V_37 ,
sizeof( struct V_22 ) * V_154 ,
V_194 , 0 ) ;
if ( ! V_127 -> V_143 ) {
F_24 ( V_37 , L_20 ) ;
return - V_134 ;
}
F_60 ( V_37 , V_127 ) ;
F_70 (np, NULL, L_21 ) {
V_132 = F_55 ( V_122 , L_9 , & V_124 ) ;
if ( V_132 ) {
F_24 ( V_37 , L_22 ) ;
F_71 ( V_122 ) ;
return - V_137 ;
}
F_72 (np, child) {
V_132 = F_73 ( V_163 ,
L_23 ) ;
if ( V_132 ) {
F_52 ( V_120 , V_163 , V_164 ++ , V_124 ) ;
V_127 -> V_191 ++ ;
}
}
}
F_74 ( V_129 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_9 )
{
F_76 ( & V_9 -> V_47 ) ;
F_51 ( V_9 -> V_75 -> V_143 , V_9 -> V_19 ,
V_9 -> V_144 ) ;
F_51 ( V_9 -> V_75 -> V_143 , V_9 -> V_33 ,
V_9 -> V_145 ) ;
}
static int F_77 ( struct V_119 * V_120 )
{
struct V_126 * V_127 ;
struct V_31 * V_37 ;
int V_86 ;
V_37 = & V_120 -> V_37 ;
V_127 = F_22 ( V_37 ) ;
for ( V_86 = 0 ; V_86 < V_127 -> V_191 ; V_86 ++ )
F_75 ( V_127 -> V_141 [ V_86 ] ) ;
F_78 ( & V_127 -> V_129 ) ;
return 0 ;
}
