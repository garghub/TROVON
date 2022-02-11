static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_5 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
int V_16 ;
if ( ! V_7 )
return 0 ;
if ( ! F_4 ( V_17 , V_6 , V_7 ) )
return - V_18 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
#define F_6 (!list_empty(&hidg->completed_out_req))
while ( ! F_6 ) {
F_7 ( & V_9 -> V_19 , V_15 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_8 ( V_9 -> V_23 , F_6 ) )
return - V_24 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
}
V_12 = F_9 ( & V_9 -> V_25 ,
struct V_11 , V_12 ) ;
F_10 ( & V_12 -> V_12 ) ;
V_14 = V_12 -> V_14 ;
V_7 = F_11 (unsigned int, count, req->actual - list->pos) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_7 -= F_12 ( V_6 , V_14 -> V_26 + V_12 -> V_27 , V_7 ) ;
V_12 -> V_27 += V_7 ;
if ( V_12 -> V_27 == V_14 -> V_28 ) {
F_13 ( V_12 ) ;
V_14 -> V_29 = V_9 -> V_30 ;
V_16 = F_14 ( V_9 -> V_31 , V_14 , V_32 ) ;
if ( V_16 < 0 ) {
F_15 ( V_9 -> V_31 , V_14 ) ;
return V_16 ;
}
} else {
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_16 ( & V_12 -> V_12 , & V_9 -> V_25 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_17 ( & V_9 -> V_23 ) ;
}
return V_7 ;
}
static void F_18 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_34 -> V_35 ;
unsigned long V_15 ;
if ( V_14 -> V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_1 , V_14 -> V_36 ) ;
}
F_5 ( & V_9 -> V_39 , V_15 ) ;
V_9 -> V_40 = 0 ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
F_17 ( & V_9 -> V_41 ) ;
}
static T_1 F_19 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_42 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
T_1 V_36 = - V_43 ;
if ( ! F_4 ( V_44 , V_6 , V_7 ) )
return - V_18 ;
F_5 ( & V_9 -> V_39 , V_15 ) ;
#define F_20 (!hidg->write_pending)
V_45:
while ( ! F_20 ) {
F_7 ( & V_9 -> V_39 , V_15 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_21 (
V_9 -> V_41 , F_20 ) )
return - V_24 ;
F_5 ( & V_9 -> V_39 , V_15 ) ;
}
V_9 -> V_40 = 1 ;
V_14 = V_9 -> V_14 ;
V_7 = F_11 ( unsigned , V_7 , V_9 -> V_30 ) ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
V_36 = F_22 ( V_14 -> V_26 , V_6 , V_7 ) ;
if ( V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_2 ) ;
V_36 = - V_46 ;
goto V_47;
}
F_5 ( & V_9 -> V_39 , V_15 ) ;
if ( ! V_9 -> V_14 ) {
F_15 ( V_9 -> V_48 , V_14 ) ;
goto V_45;
}
V_14 -> V_36 = 0 ;
V_14 -> V_49 = 0 ;
V_14 -> V_29 = V_7 ;
V_14 -> V_50 = F_18 ;
V_14 -> V_51 = V_9 ;
V_36 = F_14 ( V_9 -> V_48 , V_14 , V_52 ) ;
if ( V_36 < 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_3 , V_36 ) ;
goto V_53;
} else {
V_36 = V_7 ;
}
F_7 ( & V_9 -> V_39 , V_15 ) ;
return V_36 ;
V_47:
F_5 ( & V_9 -> V_39 , V_15 ) ;
V_53:
V_9 -> V_40 = 0 ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
F_17 ( & V_9 -> V_41 ) ;
return V_36 ;
}
static unsigned int F_23 ( struct V_5 * V_5 , T_5 * V_54 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
unsigned int V_16 = 0 ;
F_24 ( V_5 , & V_9 -> V_23 , V_54 ) ;
F_24 ( V_5 , & V_9 -> V_41 , V_54 ) ;
if ( F_20 )
V_16 |= V_55 | V_56 ;
if ( F_6 )
V_16 |= V_57 | V_58 ;
return V_16 ;
}
static int F_25 ( struct V_59 * V_59 , struct V_5 * V_60 )
{
V_60 -> V_10 = NULL ;
return 0 ;
}
static int F_26 ( struct V_59 * V_59 , struct V_5 * V_60 )
{
struct V_1 * V_9 =
F_2 ( V_59 -> V_61 , struct V_1 , V_38 ) ;
V_60 -> V_10 = V_9 ;
return 0 ;
}
static inline struct V_13 * F_27 ( struct V_33 * V_34 ,
unsigned V_29 )
{
return F_28 ( V_34 , V_29 ) ;
}
static void F_29 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_14 -> V_51 ;
struct V_62 * V_38 = V_9 -> V_4 . V_37 -> V_38 ;
struct V_11 * V_63 ;
unsigned long V_15 ;
switch ( V_14 -> V_36 ) {
case 0 :
V_63 = F_30 ( sizeof( * V_63 ) , V_52 ) ;
if ( ! V_63 ) {
ERROR ( V_38 , L_4 ) ;
goto V_64;
}
V_63 -> V_14 = V_14 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_31 ( & V_63 -> V_12 , & V_9 -> V_25 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_17 ( & V_9 -> V_23 ) ;
break;
default:
ERROR ( V_38 , L_5 , V_14 -> V_36 ) ;
case - V_65 :
case - V_66 :
case - V_67 :
V_64:
F_15 ( V_34 , V_14 ) ;
return;
}
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_68 * V_69 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_13 * V_14 = V_38 -> V_14 ;
int V_36 = 0 ;
T_6 V_70 , V_29 ;
V_70 = F_33 ( V_69 -> V_71 ) ;
V_29 = F_33 ( V_69 -> V_72 ) ;
F_34 ( V_38 ,
L_6 ,
V_73 , V_69 -> V_74 , V_69 -> V_75 , V_70 ) ;
switch ( ( V_69 -> V_74 << 8 ) | V_69 -> V_75 ) {
case ( ( V_76 | V_77 | V_78 ) << 8
| V_79 ) :
F_34 ( V_38 , L_7 ) ;
V_29 = F_11 ( unsigned , V_29 , V_9 -> V_30 ) ;
memset ( V_14 -> V_26 , 0x0 , V_29 ) ;
goto V_80;
break;
case ( ( V_76 | V_77 | V_78 ) << 8
| V_81 ) :
F_34 ( V_38 , L_8 ) ;
goto V_82;
break;
case ( ( V_83 | V_77 | V_78 ) << 8
| V_84 ) :
F_34 ( V_38 , L_9 , V_69 -> V_72 ) ;
goto V_82;
break;
case ( ( V_83 | V_77 | V_78 ) << 8
| V_85 ) :
F_34 ( V_38 , L_10 ) ;
goto V_82;
break;
case ( ( V_76 | V_86 | V_78 ) << 8
| V_87 ) :
switch ( V_70 >> 8 ) {
case V_88 :
{
struct V_89 V_90 = V_91 ;
F_34 ( V_38 , L_11 ) ;
V_90 . V_92 [ 0 ] . V_93 = V_94 ;
V_90 . V_92 [ 0 ] . V_95 =
F_35 ( V_9 -> V_96 ) ;
V_29 = F_11 (unsigned short, length,
hidg_desc_copy.bLength) ;
memcpy ( V_14 -> V_26 , & V_90 , V_29 ) ;
goto V_80;
break;
}
case V_94 :
F_34 ( V_38 , L_12 ) ;
V_29 = F_11 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_14 -> V_26 , V_9 -> V_97 , V_29 ) ;
goto V_80;
break;
default:
F_34 ( V_38 , L_13 ,
V_70 >> 8 ) ;
goto V_82;
break;
}
break;
default:
F_34 ( V_38 , L_14 ,
V_69 -> V_75 ) ;
goto V_82;
break;
}
V_82:
return - V_98 ;
V_80:
V_14 -> V_49 = 0 ;
V_14 -> V_29 = V_29 ;
V_36 = F_14 ( V_38 -> V_99 -> V_100 , V_14 , V_52 ) ;
if ( V_36 < 0 )
ERROR ( V_38 , L_15 , V_70 ) ;
return V_36 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_11 * V_12 , * V_101 ;
unsigned long V_15 ;
F_37 ( V_9 -> V_48 ) ;
F_37 ( V_9 -> V_31 ) ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_38 (list, next, &hidg->completed_out_req, list) {
F_15 ( V_9 -> V_31 , V_12 -> V_14 ) ;
F_10 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
}
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_5 ( & V_9 -> V_39 , V_15 ) ;
if ( ! V_9 -> V_40 ) {
F_15 ( V_9 -> V_48 , V_9 -> V_14 ) ;
V_9 -> V_40 = 1 ;
}
V_9 -> V_14 = NULL ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
}
static int F_39 ( struct V_2 * V_3 , unsigned V_102 , unsigned V_103 )
{
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_13 * V_104 = NULL ;
unsigned long V_15 ;
int V_105 , V_36 = 0 ;
F_34 ( V_38 , L_16 , V_102 , V_103 ) ;
if ( V_9 -> V_48 != NULL ) {
F_37 ( V_9 -> V_48 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_99 , V_3 ,
V_9 -> V_48 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_17 ) ;
goto V_106;
}
V_36 = F_41 ( V_9 -> V_48 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_18 ) ;
goto V_106;
}
V_9 -> V_48 -> V_35 = V_9 ;
V_104 = F_27 ( V_9 -> V_48 , V_9 -> V_30 ) ;
if ( ! V_104 ) {
V_36 = - V_43 ;
goto V_107;
}
}
if ( V_9 -> V_31 != NULL ) {
F_37 ( V_9 -> V_31 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_99 , V_3 ,
V_9 -> V_31 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_17 ) ;
goto V_108;
}
V_36 = F_41 ( V_9 -> V_31 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_19 ) ;
goto V_108;
}
V_9 -> V_31 -> V_35 = V_9 ;
for ( V_105 = 0 ; V_105 < V_9 -> V_109 && V_36 == 0 ; V_105 ++ ) {
struct V_13 * V_14 =
F_27 ( V_9 -> V_31 ,
V_9 -> V_30 ) ;
if ( V_14 ) {
V_14 -> V_50 = F_29 ;
V_14 -> V_51 = V_9 ;
V_36 = F_14 ( V_9 -> V_31 , V_14 ,
V_52 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_20 ,
V_9 -> V_31 -> V_110 , V_36 ) ;
F_15 ( V_9 -> V_31 , V_14 ) ;
}
} else {
V_36 = - V_43 ;
goto V_111;
}
}
}
if ( V_9 -> V_48 != NULL ) {
F_5 ( & V_9 -> V_39 , V_15 ) ;
V_9 -> V_14 = V_104 ;
V_9 -> V_40 = 0 ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
F_17 ( & V_9 -> V_41 ) ;
}
return 0 ;
V_111:
F_37 ( V_9 -> V_31 ) ;
V_108:
if ( V_104 )
F_15 ( V_9 -> V_48 , V_104 ) ;
V_107:
if ( V_9 -> V_48 )
F_37 ( V_9 -> V_48 ) ;
V_106:
return V_36 ;
}
static int F_42 ( struct V_112 * V_113 , struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_114 * V_115 ;
struct V_116 * V_116 ;
int V_36 ;
T_7 V_117 ;
V_115 = F_43 ( V_113 -> V_38 , V_118 ,
F_44 ( V_119 ) ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_120 . V_121 = V_115 [ V_122 ] . V_123 ;
V_36 = F_47 ( V_113 , V_3 ) ;
if ( V_36 < 0 )
goto V_106;
V_120 . V_124 = V_36 ;
V_36 = - V_125 ;
V_34 = F_48 ( V_113 -> V_38 -> V_99 , & V_126 ) ;
if ( ! V_34 )
goto V_106;
V_9 -> V_48 = V_34 ;
V_34 = F_48 ( V_113 -> V_38 -> V_99 , & V_127 ) ;
if ( ! V_34 )
goto V_106;
V_9 -> V_31 = V_34 ;
V_120 . V_128 = V_9 -> V_128 ;
V_120 . V_129 = V_9 -> V_129 ;
V_130 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_132 . V_133 =
F_35 ( V_9 -> V_30 ) ;
V_134 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_126 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_135 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_136 . V_133 =
F_35 ( V_9 -> V_30 ) ;
V_137 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_127 . V_131 = F_35 ( V_9 -> V_30 ) ;
V_91 . V_92 [ 0 ] . V_93 = V_94 ;
V_91 . V_92 [ 0 ] . V_95 =
F_35 ( V_9 -> V_96 ) ;
V_134 . V_138 =
V_126 . V_138 ;
V_137 . V_138 =
V_127 . V_138 ;
V_130 . V_138 =
V_126 . V_138 ;
V_135 . V_138 =
V_127 . V_138 ;
V_36 = F_49 ( V_3 , V_139 ,
V_140 , V_141 , NULL ) ;
if ( V_36 )
goto V_106;
F_50 ( & V_9 -> V_39 ) ;
V_9 -> V_40 = 1 ;
V_9 -> V_14 = NULL ;
F_50 ( & V_9 -> V_19 ) ;
F_51 ( & V_9 -> V_41 ) ;
F_51 ( & V_9 -> V_23 ) ;
F_52 ( & V_9 -> V_25 ) ;
F_53 ( & V_9 -> V_38 , & V_142 ) ;
V_117 = F_54 ( V_143 , V_9 -> V_144 ) ;
V_36 = F_55 ( & V_9 -> V_38 , V_117 , 1 ) ;
if ( V_36 )
goto V_145;
V_116 = F_56 ( V_146 , NULL , V_117 , NULL ,
L_21 , L_22 , V_9 -> V_144 ) ;
if ( F_45 ( V_116 ) ) {
V_36 = F_46 ( V_116 ) ;
goto V_147;
}
return 0 ;
V_147:
F_57 ( & V_9 -> V_38 ) ;
V_145:
F_58 ( V_3 ) ;
V_106:
ERROR ( V_3 -> V_37 -> V_38 , L_23 ) ;
if ( V_9 -> V_14 != NULL )
F_15 ( V_9 -> V_48 , V_9 -> V_14 ) ;
return V_36 ;
}
static inline int F_59 ( void )
{
int V_16 ;
V_16 = F_60 ( & V_148 , 0 , 0 , V_32 ) ;
if ( V_16 >= V_149 ) {
F_61 ( & V_148 , V_16 ) ;
V_16 = - V_125 ;
}
return V_16 ;
}
static inline struct V_150 * F_62 ( struct V_151 * V_152 )
{
return F_2 ( F_63 ( V_152 ) , struct V_150 ,
V_153 . V_154 ) ;
}
static void F_64 ( struct V_151 * V_152 )
{
struct V_150 * V_155 = F_62 ( V_152 ) ;
F_65 ( & V_155 -> V_153 ) ;
}
static T_1 F_66 ( struct V_151 * V_152 , char * V_156 )
{
struct V_150 * V_155 = F_62 ( V_152 ) ;
int V_157 ;
F_67 ( & V_155 -> V_158 ) ;
V_157 = V_155 -> V_96 ;
memcpy ( V_156 , V_155 -> V_97 , V_155 -> V_96 ) ;
F_68 ( & V_155 -> V_158 ) ;
return V_157 ;
}
static T_1 F_69 ( struct V_151 * V_152 ,
const char * V_156 , T_3 V_159 )
{
struct V_150 * V_155 = F_62 ( V_152 ) ;
int V_16 = - V_160 ;
char * V_161 ;
F_67 ( & V_155 -> V_158 ) ;
if ( V_155 -> V_162 )
goto V_163;
if ( V_159 > V_164 ) {
V_16 = - V_165 ;
goto V_163;
}
V_161 = F_70 ( V_156 , V_159 , V_32 ) ;
if ( ! V_161 ) {
V_16 = - V_43 ;
goto V_163;
}
F_13 ( V_155 -> V_97 ) ;
V_155 -> V_97 = V_161 ;
V_155 -> V_96 = V_159 ;
V_155 -> V_166 = true ;
V_16 = V_159 ;
V_163:
F_68 ( & V_155 -> V_158 ) ;
return V_16 ;
}
static T_1 F_71 ( struct V_151 * V_152 , char * V_156 )
{
struct V_150 * V_155 = F_62 ( V_152 ) ;
return sprintf ( V_156 , L_24 , V_143 , V_155 -> V_144 ) ;
}
static inline void F_72 ( int V_144 )
{
F_61 ( & V_148 , V_144 ) ;
}
static void F_73 ( struct V_167 * V_3 )
{
struct V_150 * V_155 ;
V_155 = F_2 ( V_3 , struct V_150 , V_153 ) ;
F_67 ( & V_168 ) ;
F_72 ( V_155 -> V_144 ) ;
if ( F_74 ( & V_148 ) )
F_75 () ;
F_68 ( & V_168 ) ;
if ( V_155 -> V_166 )
F_13 ( V_155 -> V_97 ) ;
F_13 ( V_155 ) ;
}
static struct V_167 * F_76 ( void )
{
struct V_150 * V_155 ;
struct V_167 * V_16 ;
int V_36 = 0 ;
V_155 = F_30 ( sizeof( * V_155 ) , V_32 ) ;
if ( ! V_155 )
return F_77 ( - V_43 ) ;
F_78 ( & V_155 -> V_158 ) ;
V_155 -> V_153 . V_169 = F_73 ;
V_16 = & V_155 -> V_153 ;
F_67 ( & V_168 ) ;
if ( F_74 ( & V_148 ) ) {
V_36 = F_79 ( NULL , V_149 ) ;
if ( V_36 ) {
V_16 = F_77 ( V_36 ) ;
F_13 ( V_155 ) ;
goto V_170;
}
}
V_155 -> V_144 = F_59 () ;
if ( V_155 -> V_144 < 0 ) {
V_16 = F_77 ( V_155 -> V_144 ) ;
F_13 ( V_155 ) ;
if ( F_74 ( & V_148 ) )
F_75 () ;
goto V_170;
}
F_80 ( & V_155 -> V_153 . V_154 , L_25 , & V_171 ) ;
V_170:
F_68 ( & V_168 ) ;
return V_16 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_150 * V_155 ;
V_9 = F_1 ( V_3 ) ;
V_155 = F_2 ( V_3 -> V_172 , struct V_150 , V_153 ) ;
F_13 ( V_9 -> V_97 ) ;
F_13 ( V_9 ) ;
F_67 ( & V_155 -> V_158 ) ;
-- V_155 -> V_162 ;
F_68 ( & V_155 -> V_158 ) ;
}
static void F_82 ( struct V_112 * V_113 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_83 ( V_146 , F_54 ( V_143 , V_9 -> V_144 ) ) ;
F_57 ( & V_9 -> V_38 ) ;
F_58 ( V_3 ) ;
}
static struct V_2 * F_84 ( struct V_167 * V_172 )
{
struct V_1 * V_9 ;
struct V_150 * V_155 ;
V_9 = F_30 ( sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return F_77 ( - V_43 ) ;
V_155 = F_2 ( V_172 , struct V_150 , V_153 ) ;
F_67 ( & V_155 -> V_158 ) ;
++ V_155 -> V_162 ;
V_9 -> V_144 = V_155 -> V_144 ;
V_9 -> V_128 = V_155 -> V_173 ;
V_9 -> V_129 = V_155 -> V_174 ;
V_9 -> V_30 = V_155 -> V_30 ;
V_9 -> V_96 = V_155 -> V_96 ;
if ( V_155 -> V_97 ) {
V_9 -> V_97 = F_70 ( V_155 -> V_97 ,
V_155 -> V_96 ,
V_32 ) ;
if ( ! V_9 -> V_97 ) {
F_13 ( V_9 ) ;
F_68 ( & V_155 -> V_158 ) ;
return F_77 ( - V_43 ) ;
}
}
F_68 ( & V_155 -> V_158 ) ;
V_9 -> V_4 . V_110 = L_26 ;
V_9 -> V_4 . V_175 = F_42 ;
V_9 -> V_4 . V_176 = F_82 ;
V_9 -> V_4 . V_177 = F_39 ;
V_9 -> V_4 . V_178 = F_36 ;
V_9 -> V_4 . V_179 = F_32 ;
V_9 -> V_4 . V_180 = F_81 ;
V_9 -> V_109 = 4 ;
return & V_9 -> V_4 ;
}
int F_79 ( struct V_181 * V_182 , int V_7 )
{
int V_36 ;
T_7 V_117 ;
V_146 = F_85 ( V_183 , L_22 ) ;
if ( F_45 ( V_146 ) ) {
V_36 = F_46 ( V_146 ) ;
V_146 = NULL ;
return V_36 ;
}
V_36 = F_86 ( & V_117 , 0 , V_7 , L_22 ) ;
if ( V_36 ) {
F_87 ( V_146 ) ;
V_146 = NULL ;
return V_36 ;
}
V_143 = F_88 ( V_117 ) ;
V_184 = V_7 ;
return 0 ;
}
void F_75 ( void )
{
if ( V_143 ) {
F_89 ( F_54 ( V_143 , 0 ) , V_184 ) ;
V_143 = V_184 = 0 ;
}
F_87 ( V_146 ) ;
V_146 = NULL ;
}
