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
V_29 = F_11 (unsigned int, length, 1 ) ;
( ( V_82 * ) V_14 -> V_26 ) [ 0 ] = V_9 -> V_83 ;
goto V_80;
break;
case ( ( V_84 | V_77 | V_78 ) << 8
| V_85 ) :
F_34 ( V_38 , L_9 , V_69 -> V_72 ) ;
goto V_86;
break;
case ( ( V_84 | V_77 | V_78 ) << 8
| V_87 ) :
F_34 ( V_38 , L_10 ) ;
if ( V_70 > V_88 )
goto V_86;
V_29 = 0 ;
if ( V_9 -> V_89 == V_90 ) {
V_9 -> V_83 = V_70 ;
goto V_80;
}
goto V_86;
break;
case ( ( V_76 | V_91 | V_78 ) << 8
| V_92 ) :
switch ( V_70 >> 8 ) {
case V_93 :
{
struct V_94 V_95 = V_96 ;
F_34 ( V_38 , L_11 ) ;
V_95 . V_97 [ 0 ] . V_98 = V_99 ;
V_95 . V_97 [ 0 ] . V_100 =
F_35 ( V_9 -> V_101 ) ;
V_29 = F_11 (unsigned short, length,
hidg_desc_copy.bLength) ;
memcpy ( V_14 -> V_26 , & V_95 , V_29 ) ;
goto V_80;
break;
}
case V_99 :
F_34 ( V_38 , L_12 ) ;
V_29 = F_11 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_14 -> V_26 , V_9 -> V_102 , V_29 ) ;
goto V_80;
break;
default:
F_34 ( V_38 , L_13 ,
V_70 >> 8 ) ;
goto V_86;
break;
}
break;
default:
F_34 ( V_38 , L_14 ,
V_69 -> V_75 ) ;
goto V_86;
break;
}
V_86:
return - V_103 ;
V_80:
V_14 -> V_49 = 0 ;
V_14 -> V_29 = V_29 ;
V_36 = F_14 ( V_38 -> V_104 -> V_105 , V_14 , V_52 ) ;
if ( V_36 < 0 )
ERROR ( V_38 , L_15 , V_70 ) ;
return V_36 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_11 * V_12 , * V_106 ;
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
static int F_39 ( struct V_2 * V_3 , unsigned V_107 , unsigned V_108 )
{
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_13 * V_109 = NULL ;
unsigned long V_15 ;
int V_110 , V_36 = 0 ;
F_34 ( V_38 , L_16 , V_107 , V_108 ) ;
if ( V_9 -> V_48 != NULL ) {
F_37 ( V_9 -> V_48 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_104 , V_3 ,
V_9 -> V_48 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_17 ) ;
goto V_111;
}
V_36 = F_41 ( V_9 -> V_48 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_18 ) ;
goto V_111;
}
V_9 -> V_48 -> V_35 = V_9 ;
V_109 = F_27 ( V_9 -> V_48 , V_9 -> V_30 ) ;
if ( ! V_109 ) {
V_36 = - V_43 ;
goto V_112;
}
}
if ( V_9 -> V_31 != NULL ) {
F_37 ( V_9 -> V_31 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_104 , V_3 ,
V_9 -> V_31 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_17 ) ;
goto V_113;
}
V_36 = F_41 ( V_9 -> V_31 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_19 ) ;
goto V_113;
}
V_9 -> V_31 -> V_35 = V_9 ;
for ( V_110 = 0 ; V_110 < V_9 -> V_114 && V_36 == 0 ; V_110 ++ ) {
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
V_9 -> V_31 -> V_115 , V_36 ) ;
F_15 ( V_9 -> V_31 , V_14 ) ;
}
} else {
V_36 = - V_43 ;
goto V_116;
}
}
}
if ( V_9 -> V_48 != NULL ) {
F_5 ( & V_9 -> V_39 , V_15 ) ;
V_9 -> V_14 = V_109 ;
V_9 -> V_40 = 0 ;
F_7 ( & V_9 -> V_39 , V_15 ) ;
F_17 ( & V_9 -> V_41 ) ;
}
return 0 ;
V_116:
F_37 ( V_9 -> V_31 ) ;
V_113:
if ( V_109 )
F_15 ( V_9 -> V_48 , V_109 ) ;
V_112:
if ( V_9 -> V_48 )
F_37 ( V_9 -> V_48 ) ;
V_111:
return V_36 ;
}
static int F_42 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_119 * V_120 ;
struct V_121 * V_121 ;
int V_36 ;
T_7 V_122 ;
V_120 = F_43 ( V_118 -> V_38 , V_123 ,
F_44 ( V_124 ) ) ;
if ( F_45 ( V_120 ) )
return F_46 ( V_120 ) ;
V_125 . V_126 = V_120 [ V_127 ] . V_128 ;
V_36 = F_47 ( V_118 , V_3 ) ;
if ( V_36 < 0 )
goto V_111;
V_125 . V_129 = V_36 ;
V_36 = - V_130 ;
V_34 = F_48 ( V_118 -> V_38 -> V_104 , & V_131 ) ;
if ( ! V_34 )
goto V_111;
V_9 -> V_48 = V_34 ;
V_34 = F_48 ( V_118 -> V_38 -> V_104 , & V_132 ) ;
if ( ! V_34 )
goto V_111;
V_9 -> V_31 = V_34 ;
V_125 . V_89 = V_9 -> V_89 ;
V_125 . V_133 = V_9 -> V_133 ;
V_9 -> V_83 = V_88 ;
V_134 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_136 . V_137 =
F_35 ( V_9 -> V_30 ) ;
V_138 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_131 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_139 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_140 . V_137 =
F_35 ( V_9 -> V_30 ) ;
V_141 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_132 . V_135 = F_35 ( V_9 -> V_30 ) ;
V_96 . V_97 [ 0 ] . V_98 = V_99 ;
V_96 . V_97 [ 0 ] . V_100 =
F_35 ( V_9 -> V_101 ) ;
V_138 . V_142 =
V_131 . V_142 ;
V_141 . V_142 =
V_132 . V_142 ;
V_134 . V_142 =
V_131 . V_142 ;
V_139 . V_142 =
V_132 . V_142 ;
V_36 = F_49 ( V_3 , V_143 ,
V_144 , V_145 , NULL ) ;
if ( V_36 )
goto V_111;
F_50 ( & V_9 -> V_39 ) ;
V_9 -> V_40 = 1 ;
V_9 -> V_14 = NULL ;
F_50 ( & V_9 -> V_19 ) ;
F_51 ( & V_9 -> V_41 ) ;
F_51 ( & V_9 -> V_23 ) ;
F_52 ( & V_9 -> V_25 ) ;
F_53 ( & V_9 -> V_38 , & V_146 ) ;
V_122 = F_54 ( V_147 , V_9 -> V_148 ) ;
V_36 = F_55 ( & V_9 -> V_38 , V_122 , 1 ) ;
if ( V_36 )
goto V_149;
V_121 = F_56 ( V_150 , NULL , V_122 , NULL ,
L_21 , L_22 , V_9 -> V_148 ) ;
if ( F_45 ( V_121 ) ) {
V_36 = F_46 ( V_121 ) ;
goto V_151;
}
return 0 ;
V_151:
F_57 ( & V_9 -> V_38 ) ;
V_149:
F_58 ( V_3 ) ;
V_111:
ERROR ( V_3 -> V_37 -> V_38 , L_23 ) ;
if ( V_9 -> V_14 != NULL )
F_15 ( V_9 -> V_48 , V_9 -> V_14 ) ;
return V_36 ;
}
static inline int F_59 ( void )
{
int V_16 ;
V_16 = F_60 ( & V_152 , 0 , 0 , V_32 ) ;
if ( V_16 >= V_153 ) {
F_61 ( & V_152 , V_16 ) ;
V_16 = - V_130 ;
}
return V_16 ;
}
static inline struct V_154 * F_62 ( struct V_155 * V_156 )
{
return F_2 ( F_63 ( V_156 ) , struct V_154 ,
V_157 . V_158 ) ;
}
static void F_64 ( struct V_155 * V_156 )
{
struct V_154 * V_159 = F_62 ( V_156 ) ;
F_65 ( & V_159 -> V_157 ) ;
}
static T_1 F_66 ( struct V_155 * V_156 , char * V_160 )
{
struct V_154 * V_159 = F_62 ( V_156 ) ;
int V_161 ;
F_67 ( & V_159 -> V_162 ) ;
V_161 = V_159 -> V_101 ;
memcpy ( V_160 , V_159 -> V_102 , V_159 -> V_101 ) ;
F_68 ( & V_159 -> V_162 ) ;
return V_161 ;
}
static T_1 F_69 ( struct V_155 * V_156 ,
const char * V_160 , T_3 V_163 )
{
struct V_154 * V_159 = F_62 ( V_156 ) ;
int V_16 = - V_164 ;
char * V_165 ;
F_67 ( & V_159 -> V_162 ) ;
if ( V_159 -> V_166 )
goto V_167;
if ( V_163 > V_168 ) {
V_16 = - V_169 ;
goto V_167;
}
V_165 = F_70 ( V_160 , V_163 , V_32 ) ;
if ( ! V_165 ) {
V_16 = - V_43 ;
goto V_167;
}
F_13 ( V_159 -> V_102 ) ;
V_159 -> V_102 = V_165 ;
V_159 -> V_101 = V_163 ;
V_159 -> V_170 = true ;
V_16 = V_163 ;
V_167:
F_68 ( & V_159 -> V_162 ) ;
return V_16 ;
}
static T_1 F_71 ( struct V_155 * V_156 , char * V_160 )
{
struct V_154 * V_159 = F_62 ( V_156 ) ;
return sprintf ( V_160 , L_24 , V_147 , V_159 -> V_148 ) ;
}
static inline void F_72 ( int V_148 )
{
F_61 ( & V_152 , V_148 ) ;
}
static void F_73 ( struct V_171 * V_3 )
{
struct V_154 * V_159 ;
V_159 = F_2 ( V_3 , struct V_154 , V_157 ) ;
F_67 ( & V_172 ) ;
F_72 ( V_159 -> V_148 ) ;
if ( F_74 ( & V_152 ) )
F_75 () ;
F_68 ( & V_172 ) ;
if ( V_159 -> V_170 )
F_13 ( V_159 -> V_102 ) ;
F_13 ( V_159 ) ;
}
static struct V_171 * F_76 ( void )
{
struct V_154 * V_159 ;
struct V_171 * V_16 ;
int V_36 = 0 ;
V_159 = F_30 ( sizeof( * V_159 ) , V_32 ) ;
if ( ! V_159 )
return F_77 ( - V_43 ) ;
F_78 ( & V_159 -> V_162 ) ;
V_159 -> V_157 . V_173 = F_73 ;
V_16 = & V_159 -> V_157 ;
F_67 ( & V_172 ) ;
if ( F_74 ( & V_152 ) ) {
V_36 = F_79 ( NULL , V_153 ) ;
if ( V_36 ) {
V_16 = F_77 ( V_36 ) ;
F_13 ( V_159 ) ;
goto V_174;
}
}
V_159 -> V_148 = F_59 () ;
if ( V_159 -> V_148 < 0 ) {
V_16 = F_77 ( V_159 -> V_148 ) ;
F_13 ( V_159 ) ;
if ( F_74 ( & V_152 ) )
F_75 () ;
goto V_174;
}
F_80 ( & V_159 -> V_157 . V_158 , L_25 , & V_175 ) ;
V_174:
F_68 ( & V_172 ) ;
return V_16 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_154 * V_159 ;
V_9 = F_1 ( V_3 ) ;
V_159 = F_2 ( V_3 -> V_176 , struct V_154 , V_157 ) ;
F_13 ( V_9 -> V_102 ) ;
F_13 ( V_9 ) ;
F_67 ( & V_159 -> V_162 ) ;
-- V_159 -> V_166 ;
F_68 ( & V_159 -> V_162 ) ;
}
static void F_82 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_83 ( V_150 , F_54 ( V_147 , V_9 -> V_148 ) ) ;
F_57 ( & V_9 -> V_38 ) ;
F_58 ( V_3 ) ;
}
static struct V_2 * F_84 ( struct V_171 * V_176 )
{
struct V_1 * V_9 ;
struct V_154 * V_159 ;
V_9 = F_30 ( sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return F_77 ( - V_43 ) ;
V_159 = F_2 ( V_176 , struct V_154 , V_157 ) ;
F_67 ( & V_159 -> V_162 ) ;
++ V_159 -> V_166 ;
V_9 -> V_148 = V_159 -> V_148 ;
V_9 -> V_89 = V_159 -> V_177 ;
V_9 -> V_133 = V_159 -> V_83 ;
V_9 -> V_30 = V_159 -> V_30 ;
V_9 -> V_101 = V_159 -> V_101 ;
if ( V_159 -> V_102 ) {
V_9 -> V_102 = F_70 ( V_159 -> V_102 ,
V_159 -> V_101 ,
V_32 ) ;
if ( ! V_9 -> V_102 ) {
F_13 ( V_9 ) ;
F_68 ( & V_159 -> V_162 ) ;
return F_77 ( - V_43 ) ;
}
}
F_68 ( & V_159 -> V_162 ) ;
V_9 -> V_4 . V_115 = L_26 ;
V_9 -> V_4 . V_178 = F_42 ;
V_9 -> V_4 . V_179 = F_82 ;
V_9 -> V_4 . V_180 = F_39 ;
V_9 -> V_4 . V_181 = F_36 ;
V_9 -> V_4 . V_182 = F_32 ;
V_9 -> V_4 . V_183 = F_81 ;
V_9 -> V_114 = 4 ;
return & V_9 -> V_4 ;
}
int F_79 ( struct V_184 * V_185 , int V_7 )
{
int V_36 ;
T_7 V_122 ;
V_150 = F_85 ( V_186 , L_22 ) ;
if ( F_45 ( V_150 ) ) {
V_36 = F_46 ( V_150 ) ;
V_150 = NULL ;
return V_36 ;
}
V_36 = F_86 ( & V_122 , 0 , V_7 , L_22 ) ;
if ( V_36 ) {
F_87 ( V_150 ) ;
V_150 = NULL ;
return V_36 ;
}
V_147 = F_88 ( V_122 ) ;
V_187 = V_7 ;
return 0 ;
}
void F_75 ( void )
{
if ( V_147 ) {
F_89 ( F_54 ( V_147 , 0 ) , V_187 ) ;
V_147 = V_187 = 0 ;
}
F_87 ( V_150 ) ;
V_150 = NULL ;
}
