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
T_2 V_25 ;
void * V_26 ;
F_16 ( & V_4 -> V_27 ) ;
V_25 = V_4 -> V_27 . V_25 ;
V_26 = V_4 -> V_27 . V_26 ;
if ( V_25 )
V_25 ( V_26 ) ;
F_17 ( & V_4 -> V_27 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_3 * V_4 , * V_15 ;
unsigned long V_8 ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
F_11 (desc, _desc, &re_chan->ack_q, node) {
if ( F_19 ( & V_4 -> V_27 ) )
F_12 ( & V_4 -> V_11 , & V_6 -> V_28 ) ;
}
F_7 ( & V_6 -> V_10 , V_8 ) ;
F_8 ( & V_6 -> V_9 ) ;
}
static void F_20 ( unsigned long V_29 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 , * V_15 ;
struct V_22 * V_21 ;
unsigned long V_8 ;
unsigned int V_30 , V_31 ;
int V_32 ;
V_6 = F_21 ( (struct V_33 * ) V_29 ) ;
F_18 ( V_6 ) ;
F_4 ( & V_6 -> V_10 , V_8 ) ;
V_30 = F_22 ( F_10 ( & V_6 -> V_16 -> V_34 ) ) ;
while ( V_30 -- ) {
V_32 = 0 ;
V_21 = & V_6 -> V_35 [ V_6 -> V_31 ] ;
F_11 (desc, _desc, &re_chan->active_q,
node) {
if ( V_4 -> V_21 . V_36 == V_21 -> V_36 &&
V_4 -> V_21 . V_37 == V_21 -> V_37 ) {
V_32 = 1 ;
break;
}
}
if ( V_32 ) {
F_15 ( V_4 ) ;
F_12 ( & V_4 -> V_11 , & V_6 -> V_38 ) ;
} else {
F_23 ( V_6 -> V_39 ,
L_1 ) ;
}
V_31 = ( V_6 -> V_31 + 1 ) & V_23 ;
V_6 -> V_31 = V_31 ;
F_13 ( & V_6 -> V_16 -> V_40 ,
F_24 ( 1 ) ) ;
}
F_7 ( & V_6 -> V_10 , V_8 ) ;
}
static T_3 F_25 ( int V_41 , void * V_29 )
{
struct V_5 * V_6 ;
T_4 V_42 , V_43 ;
V_6 = F_21 ( (struct V_33 * ) V_29 ) ;
V_42 = F_10 ( & V_6 -> V_16 -> V_44 ) ;
if ( ! V_42 )
return V_45 ;
if ( V_42 & V_46 ) {
V_43 = F_10 ( & V_6 -> V_16 -> V_47 ) ;
F_23 ( V_6 -> V_39 , L_2 ,
V_42 , V_43 ) ;
}
F_13 ( & V_6 -> V_16 -> V_44 , V_48 ) ;
F_26 ( & V_6 -> V_49 ) ;
return V_50 ;
}
static enum V_51 F_27 ( struct V_13 * V_9 ,
T_1 V_7 ,
struct V_52 * V_53 )
{
return F_28 ( V_9 , V_7 , V_53 ) ;
}
static void F_29 ( struct V_54 * V_55 , T_5 V_56 ,
T_6 V_57 , T_7 V_58 , bool V_59 )
{
T_4 V_60 = V_57 & V_61 ;
V_60 |= V_59 << V_62 ;
V_55 [ V_56 ] . V_63 = V_60 ;
V_55 [ V_56 ] . V_64 = F_30 ( V_58 ) ;
V_55 [ V_56 ] . V_37 = F_31 ( V_58 ) ;
}
static struct V_3 * F_32 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
void * V_55 , T_7 V_65 )
{
V_4 -> V_6 = V_6 ;
V_4 -> V_27 . V_66 = F_1 ;
F_33 ( & V_4 -> V_27 , & V_6 -> V_9 ) ;
F_34 ( & V_4 -> V_11 ) ;
V_4 -> V_21 . V_67 = V_68 << V_69 ;
V_4 -> V_21 . V_36 = F_30 ( V_65 ) ;
V_4 -> V_21 . V_37 = F_31 ( V_65 ) ;
V_4 -> V_70 = V_55 ;
V_4 -> V_71 = V_65 ;
V_4 -> V_72 = ( void * ) ( V_55 + V_73 ) ;
V_4 -> V_74 = V_65 + V_73 ;
return V_4 ;
}
static struct V_3 * F_35 ( struct V_5 * V_6 ,
unsigned long V_8 )
{
struct V_3 * V_4 = NULL ;
void * V_55 ;
T_7 V_65 ;
unsigned long V_75 ;
F_18 ( V_6 ) ;
F_4 ( & V_6 -> V_10 , V_75 ) ;
if ( ! F_36 ( & V_6 -> V_28 ) ) {
V_4 = F_37 ( & V_6 -> V_28 ,
struct V_3 , V_11 ) ;
F_38 ( & V_4 -> V_11 ) ;
V_4 -> V_27 . V_8 = V_8 ;
}
F_7 ( & V_6 -> V_10 , V_75 ) ;
if ( ! V_4 ) {
V_4 = F_39 ( sizeof( * V_4 ) , V_76 ) ;
if ( ! V_4 )
return NULL ;
V_55 = F_40 ( V_6 -> V_77 -> V_78 , V_76 ,
& V_65 ) ;
if ( ! V_55 ) {
F_41 ( V_4 ) ;
return NULL ;
}
V_4 = F_32 ( V_6 , V_4 , V_55 , V_65 ) ;
V_4 -> V_27 . V_8 = V_8 ;
F_4 ( & V_6 -> V_10 , V_75 ) ;
V_6 -> V_79 ++ ;
F_7 ( & V_6 -> V_10 , V_75 ) ;
}
return V_4 ;
}
static struct V_1 * F_42 (
struct V_13 * V_9 , T_7 V_80 , T_7 * V_81 ,
unsigned int V_82 , const unsigned char * V_83 , T_6 V_84 ,
unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_85 * V_86 ;
struct V_54 * V_55 ;
T_4 V_87 ;
unsigned int V_88 , V_89 ;
unsigned int V_90 = V_82 ;
int V_91 = 0 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_84 > V_92 ) {
F_23 ( V_6 -> V_39 , L_3 ,
V_84 , V_92 ) ;
return NULL ;
}
V_4 = F_35 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
if ( V_83 && ( V_8 & V_93 ) ) {
V_91 = 1 ;
V_82 += 1 ;
}
V_87 = V_94 << V_95 ;
V_87 |= ( V_82 - 1 ) << V_96 ;
V_87 |= V_97 << V_98 ;
V_87 |= V_99 << V_100 ;
V_87 |= V_101 << V_102 ;
V_86 = V_4 -> V_72 ;
V_86 -> V_103 = V_87 ;
if ( V_83 ) {
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ )
V_86 -> V_104 [ V_88 ] = V_83 [ V_88 ] ;
if ( V_91 )
V_86 -> V_104 [ V_88 ++ ] = 1 ;
} else {
for ( V_88 = 0 ; V_88 < V_82 ; V_88 ++ )
V_86 -> V_104 [ V_88 ] = 1 ;
}
V_55 = V_4 -> V_70 ;
F_29 ( V_55 , 0 , sizeof( * V_86 ) , V_4 -> V_74 , 0 ) ;
F_29 ( V_55 , 1 , V_84 , V_80 , 0 ) ;
for ( V_88 = 2 , V_89 = 0 ; V_89 < V_90 ; V_88 ++ , V_89 ++ )
F_29 ( V_55 , V_88 , V_84 , V_81 [ V_89 ] , 0 ) ;
if ( V_91 )
F_29 ( V_55 , V_88 ++ , V_84 , V_80 , 0 ) ;
V_55 [ V_88 - 1 ] . V_63 |= 1 << V_62 ;
return & V_4 -> V_27 ;
}
static struct V_1 * F_43 (
struct V_13 * V_9 , T_7 V_80 , T_7 * V_81 ,
unsigned int V_82 , T_6 V_84 , unsigned long V_8 )
{
return F_42 ( V_9 , V_80 , V_81 , V_82 , NULL , V_84 , V_8 ) ;
}
static struct V_1 * F_44 (
struct V_13 * V_9 , T_7 * V_80 , T_7 * V_81 ,
unsigned int V_82 , const unsigned char * V_83 , T_6 V_84 ,
unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_105 * V_106 ;
struct V_54 * V_55 ;
T_4 V_87 ;
T_5 * V_107 ;
int V_108 , V_88 , V_89 ;
unsigned int V_90 = V_82 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_84 > V_92 ) {
F_23 ( V_6 -> V_39 , L_4 ,
V_84 , V_92 ) ;
return NULL ;
}
if ( V_82 == 1 ) {
struct V_1 * V_2 ;
T_7 V_109 [ 2 ] ;
unsigned char V_110 [ 2 ] ;
V_109 [ 0 ] = * V_81 ;
V_110 [ 0 ] = * V_83 ;
V_109 [ 1 ] = * V_81 ;
V_110 [ 1 ] = 0 ;
V_2 = F_42 ( V_9 , V_80 [ 1 ] , V_109 , 2 , V_110 , V_84 ,
V_8 ) ;
if ( V_2 )
V_4 = F_2 ( V_2 ) ;
return V_2 ;
}
if ( V_8 & V_111 )
return F_42 ( V_9 , V_80 [ 1 ] , V_81 , V_82 ,
V_83 , V_84 , V_8 ) ;
if ( V_8 & V_93 )
V_82 += 3 ;
V_4 = F_35 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
V_87 = V_112 << V_95 ;
V_87 |= ( V_82 - 1 ) << V_96 ;
V_87 |= V_97 << V_98 ;
V_87 |= V_113 << V_114 ;
V_87 |= V_101 << V_102 ;
V_106 = V_4 -> V_72 ;
V_106 -> V_103 = V_87 ;
V_107 = V_106 -> V_115 ;
for ( V_88 = 0 ; V_88 < V_82 ; V_88 ++ )
V_107 [ V_88 ] = 1 ;
V_108 = F_45 ( V_82 , 4 ) ;
V_107 += V_108 ;
for ( V_88 = 0 ; V_88 < V_82 ; V_88 ++ )
V_107 [ V_88 ] = V_83 [ V_88 ] ;
V_55 = V_4 -> V_70 ;
F_29 ( V_55 , 0 , sizeof( struct V_105 ) , V_4 -> V_74 , 0 ) ;
for ( V_88 = 1 , V_89 = 0 ; V_88 < 3 ; V_88 ++ , V_89 ++ )
F_29 ( V_55 , V_88 , V_84 , V_80 [ V_89 ] , 0 ) ;
for ( V_88 = 3 , V_89 = 0 ; V_89 < V_90 ; V_88 ++ , V_89 ++ )
F_29 ( V_55 , V_88 , V_84 , V_81 [ V_89 ] , 0 ) ;
if ( V_8 & V_93 ) {
if ( V_82 - V_90 == 3 ) {
V_107 [ V_90 ] = 0 ;
V_107 [ V_90 + 1 ] = 0 ;
V_107 [ V_90 + 2 ] = 1 ;
F_29 ( V_55 , V_88 ++ , V_84 , V_80 [ 0 ] , 0 ) ;
F_29 ( V_55 , V_88 ++ , V_84 , V_80 [ 1 ] , 0 ) ;
F_29 ( V_55 , V_88 ++ , V_84 , V_80 [ 1 ] , 0 ) ;
} else {
F_23 ( V_6 -> V_39 , L_5 ) ;
return NULL ;
}
}
V_55 [ V_88 - 1 ] . V_63 |= 1 << V_62 ;
return & V_4 -> V_27 ;
}
static struct V_1 * F_46 (
struct V_13 * V_9 , T_7 V_80 , T_7 V_81 ,
T_6 V_84 , unsigned long V_8 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_6 V_57 ;
struct V_54 * V_55 ;
struct V_116 * V_117 ;
T_4 V_87 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
if ( V_84 > V_92 ) {
F_23 ( V_6 -> V_39 , L_6 ,
V_84 , V_92 ) ;
return NULL ;
}
V_4 = F_35 ( V_6 , V_8 ) ;
if ( V_4 <= 0 )
return NULL ;
V_87 = V_118 << V_95 ;
V_87 |= V_97 << V_98 ;
V_87 |= V_99 << V_100 ;
V_87 |= V_101 << V_102 ;
V_117 = V_4 -> V_72 ;
V_117 -> V_103 = V_87 ;
V_55 = V_4 -> V_70 ;
F_29 ( V_55 , 0 , sizeof( * V_117 ) , V_4 -> V_74 , 0 ) ;
V_57 = F_47 ( T_6 , V_84 , V_92 ) ;
F_29 ( V_55 , 1 , V_57 , V_80 , 0 ) ;
F_29 ( V_55 , 2 , V_57 , V_81 , 1 ) ;
return & V_4 -> V_27 ;
}
static int F_48 ( struct V_13 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
void * V_55 ;
T_7 V_65 ;
int V_88 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
for ( V_88 = 0 ; V_88 < V_119 ; V_88 ++ ) {
V_4 = F_39 ( sizeof( * V_4 ) , V_120 ) ;
if ( ! V_4 )
break;
V_55 = F_40 ( V_6 -> V_77 -> V_78 , V_120 ,
& V_65 ) ;
if ( ! V_55 ) {
F_41 ( V_4 ) ;
break;
}
F_34 ( & V_4 -> V_11 ) ;
F_32 ( V_6 , V_4 , V_55 , V_65 ) ;
F_6 ( & V_4 -> V_11 , & V_6 -> V_28 ) ;
V_6 -> V_79 ++ ;
}
return V_6 -> V_79 ;
}
static void F_49 ( struct V_13 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_6 = F_3 ( V_9 , struct V_5 , V_9 ) ;
while ( V_6 -> V_79 -- ) {
V_4 = F_37 ( & V_6 -> V_28 ,
struct V_3 ,
V_11 ) ;
F_38 ( & V_4 -> V_11 ) ;
F_50 ( V_6 -> V_77 -> V_78 , V_4 -> V_70 ,
V_4 -> V_71 ) ;
F_41 ( V_4 ) ;
}
if ( ! F_36 ( & V_6 -> V_28 ) )
F_23 ( V_6 -> V_39 , L_7 ) ;
}
static int F_51 ( struct V_121 * V_122 ,
struct V_123 * V_124 , T_5 V_125 , T_4 V_126 )
{
struct V_33 * V_39 , * V_127 ;
struct V_128 * V_129 ;
struct V_5 * V_9 ;
struct V_130 * V_131 ;
T_4 V_132 ;
T_4 V_43 ;
int V_133 = 0 , V_134 ;
struct V_121 * V_135 ;
V_39 = & V_122 -> V_39 ;
V_129 = F_21 ( V_39 ) ;
V_131 = & V_129 -> V_131 ;
V_9 = F_52 ( V_39 , sizeof( * V_9 ) , V_120 ) ;
if ( ! V_9 )
return - V_136 ;
V_135 = F_53 ( V_124 , NULL , V_39 ) ;
if ( ! V_135 ) {
F_23 ( V_39 , L_8 , V_125 ) ;
V_133 = - V_137 ;
goto V_138;
}
V_134 = F_54 ( V_124 , L_9 , & V_132 ) ;
if ( V_134 ) {
F_23 ( V_39 , L_10 , V_125 ) ;
V_133 = - V_139 ;
goto V_138;
}
V_9 -> V_16 = (struct V_140 * ) ( ( T_5 * ) V_129 -> V_141 +
V_126 + V_132 ) ;
V_9 -> V_41 = F_55 ( V_124 , 0 ) ;
if ( V_9 -> V_41 == V_142 ) {
F_23 ( V_39 , L_11 , V_125 ) ;
V_133 = - V_139 ;
goto V_138;
}
snprintf ( V_9 -> V_143 , sizeof( V_9 -> V_143 ) , L_12 , V_125 ) ;
V_127 = & V_135 -> V_39 ;
F_56 ( & V_9 -> V_49 , F_20 , ( unsigned long ) V_127 ) ;
V_133 = F_57 ( V_9 -> V_41 , F_25 , 0 , V_9 -> V_143 , V_127 ) ;
if ( V_133 ) {
F_23 ( V_39 , L_13 , V_125 ) ;
V_133 = - V_137 ;
goto V_138;
}
V_129 -> V_144 [ V_125 ] = V_9 ;
V_9 -> V_9 . V_33 = V_131 ;
V_9 -> V_9 . V_145 = V_9 ;
V_9 -> V_39 = V_127 ;
V_9 -> V_77 = V_129 ;
F_58 ( & V_9 -> V_10 ) ;
F_34 ( & V_9 -> V_38 ) ;
F_34 ( & V_9 -> V_18 ) ;
F_34 ( & V_9 -> V_12 ) ;
F_34 ( & V_9 -> V_28 ) ;
V_9 -> V_19 = F_40 ( V_9 -> V_77 -> V_146 ,
V_120 , & V_9 -> V_147 ) ;
if ( ! V_9 -> V_19 ) {
F_23 ( V_39 , L_14 ) ;
V_133 = - V_136 ;
goto V_138;
}
V_9 -> V_35 = F_40 ( V_9 -> V_77 -> V_146 ,
V_120 , & V_9 -> V_148 ) ;
if ( ! V_9 -> V_35 ) {
F_23 ( V_39 , L_15 ) ;
V_133 = - V_136 ;
goto V_149;
}
F_13 ( & V_9 -> V_16 -> V_150 ,
V_9 -> V_147 & V_151 ) ;
F_13 ( & V_9 -> V_16 -> V_152 ,
V_9 -> V_148 & V_151 ) ;
F_13 ( & V_9 -> V_16 -> V_153 ,
V_9 -> V_147 >> V_154 ) ;
F_13 ( & V_9 -> V_16 -> V_155 ,
V_9 -> V_148 >> V_154 ) ;
F_13 ( & V_9 -> V_16 -> V_156 ,
V_157 << V_158 ) ;
F_13 ( & V_9 -> V_16 -> V_159 ,
V_157 << V_158 ) ;
V_43 = F_10 ( & V_9 -> V_16 -> V_160 ) & V_161 ;
F_13 ( & V_9 -> V_16 -> V_160 ,
V_162 | V_163 | V_43 ) ;
F_59 ( V_127 , V_9 ) ;
F_13 ( & V_9 -> V_16 -> V_164 , V_165 ) ;
return 0 ;
V_149:
F_50 ( V_9 -> V_77 -> V_146 , V_9 -> V_19 ,
V_9 -> V_147 ) ;
V_138:
return V_133 ;
}
static int F_60 ( struct V_121 * V_122 )
{
struct V_128 * V_129 ;
struct V_123 * V_124 ;
struct V_123 * V_166 ;
T_4 V_126 ;
T_5 V_167 = 0 ;
struct V_130 * V_131 ;
struct V_168 * V_169 ;
int V_134 ;
struct V_33 * V_39 = & V_122 -> V_39 ;
V_129 = F_52 ( V_39 , sizeof( * V_129 ) , V_120 ) ;
if ( ! V_129 )
return - V_136 ;
V_169 = F_61 ( V_122 , V_170 , 0 ) ;
if ( ! V_169 )
return - V_139 ;
V_129 -> V_141 = F_62 ( V_39 , V_169 -> V_171 , F_63 ( V_169 ) ) ;
if ( ! V_129 -> V_141 )
return - V_172 ;
F_13 ( & V_129 -> V_141 -> V_173 , V_174 ) ;
F_13 ( & V_129 -> V_141 -> V_175 , V_176 ) ;
F_64 ( V_39 , L_16 ,
F_10 ( & V_129 -> V_141 -> V_177 ) ,
F_10 ( & V_129 -> V_141 -> V_173 ) ,
F_10 ( & V_129 -> V_141 -> V_175 ) ) ;
V_131 = & V_129 -> V_131 ;
V_131 -> V_39 = V_39 ;
F_34 ( & V_131 -> V_178 ) ;
F_65 ( V_39 , F_66 ( 40 ) ) ;
V_131 -> V_179 = F_48 ;
V_131 -> V_180 = F_27 ;
V_131 -> V_181 = F_8 ;
V_131 -> V_182 = V_183 ;
V_131 -> V_184 = F_43 ;
F_67 ( V_185 , V_131 -> V_186 ) ;
V_131 -> V_187 = V_188 ;
V_131 -> V_189 = F_44 ;
F_67 ( V_190 , V_131 -> V_186 ) ;
V_131 -> V_191 = F_46 ;
F_67 ( V_192 , V_131 -> V_186 ) ;
V_131 -> V_193 = F_49 ;
V_129 -> V_194 = 0 ;
V_129 -> V_78 = F_68 ( L_17 , V_39 ,
V_195 ,
V_196 , 0 ) ;
if ( ! V_129 -> V_78 ) {
F_23 ( V_39 , L_18 ) ;
return - V_136 ;
}
V_129 -> V_146 = F_68 ( L_19 , V_39 ,
sizeof( struct V_22 ) * V_157 ,
V_197 , 0 ) ;
if ( ! V_129 -> V_146 ) {
F_23 ( V_39 , L_20 ) ;
return - V_136 ;
}
F_59 ( V_39 , V_129 ) ;
F_69 (np, NULL, L_21 ) {
V_134 = F_54 ( V_124 , L_9 , & V_126 ) ;
if ( V_134 ) {
F_23 ( V_39 , L_22 ) ;
F_70 ( V_124 ) ;
return - V_139 ;
}
F_71 (np, child) {
V_134 = F_72 ( V_166 ,
L_23 ) ;
if ( V_134 ) {
F_51 ( V_122 , V_166 , V_167 ++ , V_126 ) ;
V_129 -> V_194 ++ ;
}
}
}
F_73 ( V_131 ) ;
return 0 ;
}
static void F_74 ( struct V_5 * V_9 )
{
F_75 ( & V_9 -> V_49 ) ;
F_50 ( V_9 -> V_77 -> V_146 , V_9 -> V_19 ,
V_9 -> V_147 ) ;
F_50 ( V_9 -> V_77 -> V_146 , V_9 -> V_35 ,
V_9 -> V_148 ) ;
}
static int F_76 ( struct V_121 * V_122 )
{
struct V_128 * V_129 ;
struct V_33 * V_39 ;
int V_88 ;
V_39 = & V_122 -> V_39 ;
V_129 = F_21 ( V_39 ) ;
for ( V_88 = 0 ; V_88 < V_129 -> V_194 ; V_88 ++ )
F_74 ( V_129 -> V_144 [ V_88 ] ) ;
F_77 ( & V_129 -> V_131 ) ;
return 0 ;
}
