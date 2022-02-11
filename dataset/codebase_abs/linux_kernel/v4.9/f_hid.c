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
V_14 = V_12 -> V_14 ;
V_7 = F_10 (unsigned int, count, req->actual - list->pos) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_7 -= F_11 ( V_6 , V_14 -> V_26 + V_12 -> V_27 , V_7 ) ;
V_12 -> V_27 += V_7 ;
if ( V_12 -> V_27 == V_14 -> V_28 ) {
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_14 -> V_29 = V_9 -> V_30 ;
V_16 = F_14 ( V_9 -> V_31 , V_14 , V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return V_7 ;
}
static void F_15 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_34 -> V_35 ;
if ( V_14 -> V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_1 , V_14 -> V_36 ) ;
}
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
}
static T_1 F_17 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_41 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
T_1 V_36 = - V_42 ;
if ( ! F_4 ( V_43 , V_6 , V_7 ) )
return - V_18 ;
F_18 ( & V_9 -> V_44 ) ;
#define F_19 (!hidg->write_pending)
while ( ! F_19 ) {
F_20 ( & V_9 -> V_44 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_21 (
V_9 -> V_40 , F_19 ) )
return - V_24 ;
F_18 ( & V_9 -> V_44 ) ;
}
V_7 = F_10 ( unsigned , V_7 , V_9 -> V_30 ) ;
V_36 = F_22 ( V_9 -> V_14 -> V_26 , V_6 , V_7 ) ;
if ( V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_2 ) ;
F_20 ( & V_9 -> V_44 ) ;
return - V_45 ;
}
V_9 -> V_14 -> V_36 = 0 ;
V_9 -> V_14 -> V_46 = 0 ;
V_9 -> V_14 -> V_29 = V_7 ;
V_9 -> V_14 -> V_47 = F_15 ;
V_9 -> V_14 -> V_48 = V_9 ;
V_9 -> V_39 = 1 ;
V_36 = F_14 ( V_9 -> V_49 , V_9 -> V_14 , V_50 ) ;
if ( V_36 < 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_3 , V_36 ) ;
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
} else {
V_36 = V_7 ;
}
F_20 ( & V_9 -> V_44 ) ;
return V_36 ;
}
static unsigned int F_23 ( struct V_5 * V_5 , T_5 * V_51 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
unsigned int V_16 = 0 ;
F_24 ( V_5 , & V_9 -> V_23 , V_51 ) ;
F_24 ( V_5 , & V_9 -> V_40 , V_51 ) ;
if ( F_19 )
V_16 |= V_52 | V_53 ;
if ( F_6 )
V_16 |= V_54 | V_55 ;
return V_16 ;
}
static int F_25 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
V_57 -> V_10 = NULL ;
return 0 ;
}
static int F_26 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
struct V_1 * V_9 =
F_2 ( V_56 -> V_58 , struct V_1 , V_38 ) ;
V_57 -> V_10 = V_9 ;
return 0 ;
}
static inline struct V_13 * F_27 ( struct V_33 * V_34 ,
unsigned V_29 )
{
return F_28 ( V_34 , V_29 ) ;
}
static void F_29 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_14 -> V_48 ;
struct V_11 * V_59 ;
unsigned long V_15 ;
V_59 = F_30 ( sizeof( * V_59 ) , V_50 ) ;
if ( ! V_59 )
return;
V_59 -> V_14 = V_14 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_31 ( & V_59 -> V_12 , & V_9 -> V_25 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_16 ( & V_9 -> V_23 ) ;
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_60 * V_61 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_13 * V_14 = V_38 -> V_14 ;
int V_36 = 0 ;
T_6 V_63 , V_29 ;
V_63 = F_33 ( V_61 -> V_64 ) ;
V_29 = F_33 ( V_61 -> V_65 ) ;
F_34 ( V_38 ,
L_4 ,
V_66 , V_61 -> V_67 , V_61 -> V_68 , V_63 ) ;
switch ( ( V_61 -> V_67 << 8 ) | V_61 -> V_68 ) {
case ( ( V_69 | V_70 | V_71 ) << 8
| V_72 ) :
F_34 ( V_38 , L_5 ) ;
V_29 = F_10 ( unsigned , V_29 , V_9 -> V_30 ) ;
memset ( V_14 -> V_26 , 0x0 , V_29 ) ;
goto V_73;
break;
case ( ( V_69 | V_70 | V_71 ) << 8
| V_74 ) :
F_34 ( V_38 , L_6 ) ;
goto V_75;
break;
case ( ( V_76 | V_70 | V_71 ) << 8
| V_77 ) :
F_34 ( V_38 , L_7 , V_61 -> V_65 ) ;
goto V_75;
break;
case ( ( V_76 | V_70 | V_71 ) << 8
| V_78 ) :
F_34 ( V_38 , L_8 ) ;
goto V_75;
break;
case ( ( V_69 | V_79 | V_71 ) << 8
| V_80 ) :
switch ( V_63 >> 8 ) {
case V_81 :
{
struct V_82 V_83 = V_84 ;
F_34 ( V_38 , L_9 ) ;
V_83 . V_85 [ 0 ] . V_86 = V_87 ;
V_83 . V_85 [ 0 ] . V_88 =
F_35 ( V_9 -> V_89 ) ;
V_29 = F_10 (unsigned short, length,
hidg_desc_copy.bLength) ;
memcpy ( V_14 -> V_26 , & V_83 , V_29 ) ;
goto V_73;
break;
}
case V_87 :
F_34 ( V_38 , L_10 ) ;
V_29 = F_10 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_14 -> V_26 , V_9 -> V_90 , V_29 ) ;
goto V_73;
break;
default:
F_34 ( V_38 , L_11 ,
V_63 >> 8 ) ;
goto V_75;
break;
}
break;
default:
F_34 ( V_38 , L_12 ,
V_61 -> V_68 ) ;
goto V_75;
break;
}
V_75:
return - V_91 ;
V_73:
V_14 -> V_46 = 0 ;
V_14 -> V_29 = V_29 ;
V_36 = F_14 ( V_38 -> V_92 -> V_93 , V_14 , V_50 ) ;
if ( V_36 < 0 )
ERROR ( V_38 , L_13 , V_63 ) ;
return V_36 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_11 * V_12 , * V_94 ;
F_37 ( V_9 -> V_49 ) ;
F_37 ( V_9 -> V_31 ) ;
F_38 (list, next, &hidg->completed_out_req, list) {
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
}
}
static int F_39 ( struct V_2 * V_3 , unsigned V_95 , unsigned V_96 )
{
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_97 , V_36 = 0 ;
F_34 ( V_38 , L_14 , V_95 , V_96 ) ;
if ( V_9 -> V_49 != NULL ) {
F_37 ( V_9 -> V_49 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_92 , V_3 ,
V_9 -> V_49 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_15 ) ;
goto V_98;
}
V_36 = F_41 ( V_9 -> V_49 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_16 ) ;
goto V_98;
}
V_9 -> V_49 -> V_35 = V_9 ;
}
if ( V_9 -> V_31 != NULL ) {
F_37 ( V_9 -> V_31 ) ;
V_36 = F_40 ( V_3 -> V_37 -> V_38 -> V_92 , V_3 ,
V_9 -> V_31 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_15 ) ;
goto V_98;
}
V_36 = F_41 ( V_9 -> V_31 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_16 ) ;
goto V_98;
}
V_9 -> V_31 -> V_35 = V_9 ;
for ( V_97 = 0 ; V_97 < V_9 -> V_99 && V_36 == 0 ; V_97 ++ ) {
struct V_13 * V_14 =
F_27 ( V_9 -> V_31 ,
V_9 -> V_30 ) ;
if ( V_14 ) {
V_14 -> V_47 = F_29 ;
V_14 -> V_48 = V_9 ;
V_36 = F_14 ( V_9 -> V_31 , V_14 ,
V_50 ) ;
if ( V_36 )
ERROR ( V_38 , L_17 ,
V_9 -> V_31 -> V_100 , V_36 ) ;
} else {
F_37 ( V_9 -> V_31 ) ;
V_36 = - V_42 ;
goto V_98;
}
}
}
V_98:
return V_36 ;
}
static int F_42 ( struct V_101 * V_102 , struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_103 * V_104 ;
struct V_105 * V_105 ;
int V_36 ;
T_7 V_106 ;
V_104 = F_43 ( V_102 -> V_38 , V_107 ,
F_44 ( V_108 ) ) ;
if ( F_45 ( V_104 ) )
return F_46 ( V_104 ) ;
V_109 . V_110 = V_104 [ V_111 ] . V_112 ;
V_36 = F_47 ( V_102 , V_3 ) ;
if ( V_36 < 0 )
goto V_98;
V_109 . V_113 = V_36 ;
V_36 = - V_114 ;
V_34 = F_48 ( V_102 -> V_38 -> V_92 , & V_115 ) ;
if ( ! V_34 )
goto V_98;
V_9 -> V_49 = V_34 ;
V_34 = F_48 ( V_102 -> V_38 -> V_92 , & V_116 ) ;
if ( ! V_34 )
goto V_98;
V_9 -> V_31 = V_34 ;
V_36 = - V_42 ;
V_9 -> V_14 = F_28 ( V_9 -> V_49 , V_9 -> V_30 ) ;
if ( ! V_9 -> V_14 )
goto V_98;
V_109 . V_117 = V_9 -> V_117 ;
V_109 . V_118 = V_9 -> V_118 ;
V_119 . V_120 = F_35 ( V_9 -> V_30 ) ;
V_115 . V_120 = F_35 ( V_9 -> V_30 ) ;
V_121 . V_120 = F_35 ( V_9 -> V_30 ) ;
V_116 . V_120 = F_35 ( V_9 -> V_30 ) ;
V_84 . V_85 [ 0 ] . V_86 = V_87 ;
V_84 . V_85 [ 0 ] . V_88 =
F_35 ( V_9 -> V_89 ) ;
V_119 . V_122 =
V_115 . V_122 ;
V_121 . V_122 =
V_116 . V_122 ;
V_36 = F_49 ( V_3 , V_123 ,
V_124 , NULL , NULL ) ;
if ( V_36 )
goto V_98;
F_50 ( & V_9 -> V_44 ) ;
F_51 ( & V_9 -> V_19 ) ;
F_52 ( & V_9 -> V_40 ) ;
F_52 ( & V_9 -> V_23 ) ;
F_53 ( & V_9 -> V_25 ) ;
F_54 ( & V_9 -> V_38 , & V_125 ) ;
V_106 = F_55 ( V_126 , V_9 -> V_127 ) ;
V_36 = F_56 ( & V_9 -> V_38 , V_106 , 1 ) ;
if ( V_36 )
goto V_128;
V_105 = F_57 ( V_129 , NULL , V_106 , NULL ,
L_18 , L_19 , V_9 -> V_127 ) ;
if ( F_45 ( V_105 ) ) {
V_36 = F_46 ( V_105 ) ;
goto V_130;
}
return 0 ;
V_130:
F_58 ( & V_9 -> V_38 ) ;
V_128:
F_59 ( V_3 ) ;
V_98:
ERROR ( V_3 -> V_37 -> V_38 , L_20 ) ;
if ( V_9 -> V_14 != NULL )
F_60 ( V_9 -> V_49 , V_9 -> V_14 ) ;
return V_36 ;
}
static inline int F_61 ( void )
{
int V_16 ;
V_16 = F_62 ( & V_131 , 0 , 0 , V_32 ) ;
if ( V_16 >= V_132 ) {
F_63 ( & V_131 , V_16 ) ;
V_16 = - V_114 ;
}
return V_16 ;
}
static inline struct V_133 * F_64 ( struct V_134 * V_135 )
{
return F_2 ( F_65 ( V_135 ) , struct V_133 ,
V_136 . V_137 ) ;
}
static void F_66 ( struct V_134 * V_135 )
{
struct V_133 * V_138 = F_64 ( V_135 ) ;
F_67 ( & V_138 -> V_136 ) ;
}
static T_1 F_68 ( struct V_134 * V_135 , char * V_139 )
{
struct V_133 * V_138 = F_64 ( V_135 ) ;
int V_140 ;
F_18 ( & V_138 -> V_44 ) ;
V_140 = V_138 -> V_89 ;
memcpy ( V_139 , V_138 -> V_90 , V_138 -> V_89 ) ;
F_20 ( & V_138 -> V_44 ) ;
return V_140 ;
}
static T_1 F_69 ( struct V_134 * V_135 ,
const char * V_139 , T_3 V_141 )
{
struct V_133 * V_138 = F_64 ( V_135 ) ;
int V_16 = - V_142 ;
char * V_143 ;
F_18 ( & V_138 -> V_44 ) ;
if ( V_138 -> V_144 )
goto V_145;
if ( V_141 > V_146 ) {
V_16 = - V_147 ;
goto V_145;
}
V_143 = F_70 ( V_139 , V_141 , V_32 ) ;
if ( ! V_143 ) {
V_16 = - V_42 ;
goto V_145;
}
F_13 ( V_138 -> V_90 ) ;
V_138 -> V_90 = V_143 ;
V_138 -> V_89 = V_141 ;
V_138 -> V_148 = true ;
V_16 = V_141 ;
V_145:
F_20 ( & V_138 -> V_44 ) ;
return V_16 ;
}
static T_1 F_71 ( struct V_134 * V_135 , char * V_139 )
{
struct V_133 * V_138 = F_64 ( V_135 ) ;
return sprintf ( V_139 , L_21 , V_126 , V_138 -> V_127 ) ;
}
static inline void F_72 ( int V_127 )
{
F_63 ( & V_131 , V_127 ) ;
}
static void F_73 ( struct V_149 * V_3 )
{
struct V_133 * V_138 ;
V_138 = F_2 ( V_3 , struct V_133 , V_136 ) ;
F_18 ( & V_150 ) ;
F_72 ( V_138 -> V_127 ) ;
if ( F_74 ( & V_131 . V_151 ) )
F_75 () ;
F_20 ( & V_150 ) ;
if ( V_138 -> V_148 )
F_13 ( V_138 -> V_90 ) ;
F_13 ( V_138 ) ;
}
static struct V_149 * F_76 ( void )
{
struct V_133 * V_138 ;
struct V_149 * V_16 ;
int V_36 = 0 ;
V_138 = F_30 ( sizeof( * V_138 ) , V_32 ) ;
if ( ! V_138 )
return F_77 ( - V_42 ) ;
F_50 ( & V_138 -> V_44 ) ;
V_138 -> V_136 . V_152 = F_73 ;
V_16 = & V_138 -> V_136 ;
F_18 ( & V_150 ) ;
if ( F_74 ( & V_131 . V_151 ) ) {
V_36 = F_78 ( NULL , V_132 ) ;
if ( V_36 ) {
V_16 = F_77 ( V_36 ) ;
F_13 ( V_138 ) ;
goto V_153;
}
}
V_138 -> V_127 = F_61 () ;
if ( V_138 -> V_127 < 0 ) {
V_16 = F_77 ( V_138 -> V_127 ) ;
F_13 ( V_138 ) ;
if ( F_74 ( & V_131 . V_151 ) )
F_75 () ;
goto V_153;
}
F_79 ( & V_138 -> V_136 . V_137 , L_22 , & V_154 ) ;
V_153:
F_20 ( & V_150 ) ;
return V_16 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_133 * V_138 ;
V_9 = F_1 ( V_3 ) ;
V_138 = F_2 ( V_3 -> V_155 , struct V_133 , V_136 ) ;
F_13 ( V_9 -> V_90 ) ;
F_13 ( V_9 ) ;
F_18 ( & V_138 -> V_44 ) ;
-- V_138 -> V_144 ;
F_20 ( & V_138 -> V_44 ) ;
}
static void F_81 ( struct V_101 * V_102 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_82 ( V_129 , F_55 ( V_126 , V_9 -> V_127 ) ) ;
F_58 ( & V_9 -> V_38 ) ;
F_37 ( V_9 -> V_49 ) ;
F_60 ( V_9 -> V_49 , V_9 -> V_14 ) ;
F_59 ( V_3 ) ;
}
static struct V_2 * F_83 ( struct V_149 * V_155 )
{
struct V_1 * V_9 ;
struct V_133 * V_138 ;
V_9 = F_30 ( sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return F_77 ( - V_42 ) ;
V_138 = F_2 ( V_155 , struct V_133 , V_136 ) ;
F_18 ( & V_138 -> V_44 ) ;
++ V_138 -> V_144 ;
V_9 -> V_127 = V_138 -> V_127 ;
V_9 -> V_117 = V_138 -> V_156 ;
V_9 -> V_118 = V_138 -> V_157 ;
V_9 -> V_30 = V_138 -> V_30 ;
V_9 -> V_89 = V_138 -> V_89 ;
if ( V_138 -> V_90 ) {
V_9 -> V_90 = F_70 ( V_138 -> V_90 ,
V_138 -> V_89 ,
V_32 ) ;
if ( ! V_9 -> V_90 ) {
F_13 ( V_9 ) ;
F_20 ( & V_138 -> V_44 ) ;
return F_77 ( - V_42 ) ;
}
}
F_20 ( & V_138 -> V_44 ) ;
V_9 -> V_4 . V_100 = L_23 ;
V_9 -> V_4 . V_158 = F_42 ;
V_9 -> V_4 . V_159 = F_81 ;
V_9 -> V_4 . V_160 = F_39 ;
V_9 -> V_4 . V_161 = F_36 ;
V_9 -> V_4 . V_162 = F_32 ;
V_9 -> V_4 . V_163 = F_80 ;
V_9 -> V_99 = 4 ;
return & V_9 -> V_4 ;
}
int F_78 ( struct V_164 * V_165 , int V_7 )
{
int V_36 ;
T_7 V_106 ;
V_129 = F_84 ( V_166 , L_19 ) ;
if ( F_45 ( V_129 ) ) {
V_36 = F_46 ( V_129 ) ;
V_129 = NULL ;
return V_36 ;
}
V_36 = F_85 ( & V_106 , 0 , V_7 , L_19 ) ;
if ( V_36 ) {
F_86 ( V_129 ) ;
V_129 = NULL ;
return V_36 ;
}
V_126 = F_87 ( V_106 ) ;
V_167 = V_7 ;
return 0 ;
}
void F_75 ( void )
{
if ( V_126 ) {
F_88 ( F_55 ( V_126 , 0 ) , V_167 ) ;
V_126 = V_167 = 0 ;
}
F_86 ( V_129 ) ;
V_129 = NULL ;
}
