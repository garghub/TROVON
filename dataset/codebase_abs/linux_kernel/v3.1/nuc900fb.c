static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 ;
unsigned long V_8 , V_9 ;
V_8 = V_2 -> V_10 . V_11 ;
V_9 = V_2 -> V_10 . V_11 ;
V_9 += V_2 -> V_10 . V_12 * V_2 -> V_13 . V_14 ;
F_2 ( V_8 , V_6 + V_15 ) ;
F_2 ( V_9 , V_6 + V_16 ) ;
F_2 ( V_4 -> V_6 . V_17 , V_6 + V_18 ) ;
F_2 ( V_4 -> V_6 . V_19 , V_6 + V_20 ) ;
}
static unsigned int F_3 ( struct V_3 * V_4 ,
unsigned long V_21 )
{
unsigned long V_22 = V_4 -> V_23 ;
unsigned long long div ;
div = ( unsigned long long ) V_22 * V_21 ;
div >>= 12 ;
F_4 ( div , 625 * 625UL * 625 ) ;
F_5 ( V_4 -> V_24 , L_1 , V_21 , div ) ;
return div ;
}
static int F_6 ( struct V_25 * V_13 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 = V_4 -> V_24 -> V_28 ;
struct V_29 * V_30 = NULL ;
struct V_29 * V_31 = V_27 -> V_32 +
V_27 -> V_31 ;
int V_33 ;
F_5 ( V_4 -> V_24 , L_2 , V_13 , V_2 ) ;
if ( V_13 -> V_34 == V_31 -> V_34 &&
V_13 -> V_14 == V_31 -> V_14 &&
V_13 -> V_35 == V_31 -> V_36 )
V_30 = V_31 ;
else
for ( V_33 = 0 ; V_33 < V_27 -> V_37 ; V_33 ++ )
if ( V_13 -> V_34 == V_27 -> V_32 [ V_33 ] . V_34 &&
V_13 -> V_14 == V_27 -> V_32 [ V_33 ] . V_14 &&
V_13 -> V_35 == V_27 -> V_32 [ V_33 ] . V_36 ) {
V_30 = V_27 -> V_32 + V_33 ;
break;
}
if ( V_30 == NULL ) {
F_7 ( V_38 L_3 ,
V_13 -> V_34 , V_13 -> V_14 , V_13 -> V_35 ) ;
return - V_39 ;
}
V_13 -> V_40 = V_30 -> V_34 ;
V_13 -> V_41 = V_30 -> V_14 ;
V_13 -> V_42 = V_30 -> V_42 ;
V_13 -> V_43 = V_30 -> V_43 ;
V_13 -> V_44 = V_30 -> V_44 ;
V_13 -> V_45 = V_30 -> V_45 ;
V_13 -> V_46 = V_30 -> V_46 ;
V_13 -> V_47 = V_30 -> V_47 ;
V_13 -> V_48 = V_30 -> V_48 ;
V_13 -> V_49 = V_30 -> V_49 ;
V_13 -> V_50 = V_30 -> V_50 ;
V_13 -> V_51 . V_52 = 0 ;
V_13 -> V_51 . V_53 = 0 ;
V_4 -> V_6 . V_54 = V_30 -> V_55 ;
V_4 -> V_6 . V_56 = V_30 -> V_57 ;
V_4 -> V_6 . V_17 = V_30 -> V_58 ;
V_4 -> V_6 . V_19 = V_30 -> V_59 ;
switch ( V_13 -> V_35 ) {
case 1 :
case 2 :
case 4 :
case 8 :
default:
V_13 -> V_60 . V_52 = 0 ;
V_13 -> V_60 . V_53 = V_13 -> V_35 ;
V_13 -> V_61 = V_13 -> V_60 ;
V_13 -> V_62 = V_13 -> V_60 ;
break;
case 12 :
V_13 -> V_60 . V_53 = 4 ;
V_13 -> V_61 . V_53 = 4 ;
V_13 -> V_62 . V_53 = 4 ;
V_13 -> V_60 . V_52 = 8 ;
V_13 -> V_61 . V_52 = 4 ;
V_13 -> V_62 . V_52 = 0 ;
break;
case 16 :
V_13 -> V_60 . V_53 = 5 ;
V_13 -> V_61 . V_53 = 6 ;
V_13 -> V_62 . V_53 = 5 ;
V_13 -> V_60 . V_52 = 11 ;
V_13 -> V_61 . V_52 = 5 ;
V_13 -> V_62 . V_52 = 0 ;
break;
case 18 :
V_13 -> V_60 . V_53 = 6 ;
V_13 -> V_61 . V_53 = 6 ;
V_13 -> V_62 . V_53 = 6 ;
V_13 -> V_60 . V_52 = 12 ;
V_13 -> V_61 . V_52 = 6 ;
V_13 -> V_62 . V_52 = 0 ;
break;
case 32 :
V_13 -> V_60 . V_53 = 8 ;
V_13 -> V_61 . V_53 = 8 ;
V_13 -> V_62 . V_53 = 8 ;
V_13 -> V_60 . V_52 = 16 ;
V_13 -> V_61 . V_52 = 8 ;
V_13 -> V_62 . V_52 = 0 ;
break;
}
return 0 ;
}
static void F_8 ( const struct V_1 * V_2 ,
struct V_63 * V_6 )
{
const struct V_25 * V_13 = & V_2 -> V_13 ;
int V_64 = V_13 -> V_42 + V_13 -> V_47 + V_13 -> V_48 ;
int V_65 = V_13 -> V_43 + V_13 -> V_45 + V_13 -> V_46 ;
int V_66 = V_13 -> V_43 + V_13 -> V_46 ;
int V_67 = V_13 -> V_42 + V_13 -> V_48 ;
V_6 -> V_68 = F_9 ( V_64 ) |
F_10 ( V_65 ) ;
V_6 -> V_69 = F_11 ( V_13 -> V_42 ) |
F_12 ( V_13 -> V_43 ) ;
V_6 -> V_70 = F_13 ( V_13 -> V_43 + 5 ) |
F_14 ( V_13 -> V_43 + 1 ) ;
V_6 -> V_71 = F_15 ( V_66 + V_13 -> V_50 ) |
F_16 ( V_66 ) ;
V_6 -> V_72 = F_17 ( V_67 + V_13 -> V_49 ) |
F_18 ( V_67 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 ;
struct V_25 * V_13 = & V_2 -> V_13 ;
int V_73 ;
V_73 = F_3 ( V_4 , V_13 -> V_44 ) - 1 ;
if ( V_73 < 0 )
V_73 = 0 ;
F_8 ( V_2 , & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_24 , L_4 ) ;
F_5 ( V_4 -> V_24 , L_5 , V_4 -> V_6 . V_54 ) ;
F_5 ( V_4 -> V_24 , L_6 , V_4 -> V_6 . V_56 ) ;
F_5 ( V_4 -> V_24 , L_7 , V_4 -> V_6 . V_68 ) ;
F_5 ( V_4 -> V_24 , L_8 , V_4 -> V_6 . V_69 ) ;
F_5 ( V_4 -> V_24 , L_9 , V_4 -> V_6 . V_70 ) ;
F_5 ( V_4 -> V_24 , L_10 , V_4 -> V_6 . V_71 ) ;
F_5 ( V_4 -> V_24 , L_11 , V_4 -> V_6 . V_72 ) ;
F_2 ( V_4 -> V_6 . V_56 , V_6 + V_74 ) ;
F_2 ( V_4 -> V_6 . V_68 , V_6 + V_75 ) ;
F_2 ( V_4 -> V_6 . V_69 , V_6 + V_76 ) ;
F_2 ( V_4 -> V_6 . V_70 , V_6 + V_77 ) ;
F_2 ( V_4 -> V_6 . V_71 , V_6 + V_78 ) ;
F_2 ( V_4 -> V_6 . V_72 , V_6 + V_79 ) ;
F_1 ( V_2 ) ;
F_2 ( V_4 -> V_6 . V_54 , V_6 + V_80 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_25 * V_13 = & V_2 -> V_13 ;
switch ( V_13 -> V_35 ) {
case 32 :
case 24 :
case 18 :
case 16 :
case 12 :
V_2 -> V_10 . V_81 = V_82 ;
break;
case 1 :
V_2 -> V_10 . V_81 = V_83 ;
break;
default:
V_2 -> V_10 . V_81 = V_84 ;
break;
}
V_2 -> V_10 . V_12 = ( V_13 -> V_40 * V_13 -> V_35 ) / 8 ;
F_19 ( V_2 ) ;
return 0 ;
}
static inline unsigned int F_21 ( unsigned int V_85 ,
struct V_86 * V_87 )
{
V_85 &= 0xffff ;
V_85 >>= 16 - V_87 -> V_53 ;
return V_85 << V_87 -> V_52 ;
}
static int F_22 ( unsigned V_88 ,
unsigned V_60 , unsigned V_61 , unsigned V_62 ,
unsigned V_51 , struct V_1 * V_2 )
{
unsigned int V_89 ;
switch ( V_2 -> V_10 . V_81 ) {
case V_82 :
if ( V_88 < 16 ) {
T_2 * V_90 = V_2 -> V_91 ;
V_89 = F_21 ( V_60 , & V_2 -> V_13 . V_60 ) ;
V_89 |= F_21 ( V_61 , & V_2 -> V_13 . V_61 ) ;
V_89 |= F_21 ( V_62 , & V_2 -> V_13 . V_62 ) ;
V_90 [ V_88 ] = V_89 ;
}
break;
default:
return 1 ;
}
return 0 ;
}
static int F_23 ( int V_92 , struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_24 ( void T_1 * V_93 ,
unsigned long V_94 , unsigned long V_95 )
{
unsigned long V_96 ;
V_96 = F_25 ( V_93 ) & ~ V_95 ;
F_2 ( V_96 | V_94 , V_93 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 = V_4 -> V_24 -> V_28 ;
void T_1 * V_6 = V_4 -> V_7 ;
F_2 ( 0 , V_6 + V_80 ) ;
F_2 ( F_25 ( V_6 + V_80 ) | V_97 ,
V_6 + V_80 ) ;
F_27 ( 100 ) ;
F_2 ( F_25 ( V_6 + V_80 ) & ( ~ V_97 ) ,
V_6 + V_80 ) ;
F_27 ( 100 ) ;
F_2 ( 0 , V_6 + V_74 ) ;
F_24 ( V_98 + 0x54 , V_27 -> V_99 ,
V_27 -> V_100 ) ;
F_24 ( V_98 + 0x58 , V_27 -> V_101 ,
V_27 -> V_102 ) ;
return 0 ;
}
static int T_3 F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_103 ;
unsigned long V_104 = F_29 ( V_2 -> V_10 . V_105 ) ;
F_5 ( V_4 -> V_24 , L_12 ,
V_4 , V_104 ) ;
V_2 -> V_106 = F_30 ( V_4 -> V_24 , V_104 ,
& V_103 , V_107 ) ;
if ( ! V_2 -> V_106 )
return - V_108 ;
memset ( V_2 -> V_106 , 0x00 , V_104 ) ;
V_2 -> V_10 . V_11 = V_103 ;
return 0 ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_32 ( V_4 -> V_24 , F_29 ( V_2 -> V_10 . V_105 ) ,
V_2 -> V_106 , V_2 -> V_10 . V_11 ) ;
}
static T_5 F_33 ( int V_109 , void * V_110 )
{
struct V_3 * V_4 = V_110 ;
void T_1 * V_6 = V_4 -> V_7 ;
void T_1 * V_111 = V_4 -> V_111 ;
unsigned long V_112 = F_25 ( V_6 + V_113 ) ;
if ( V_112 & V_114 ) {
F_2 ( F_25 ( V_111 ) | 1 << 30 , V_111 ) ;
if ( ( F_25 ( V_6 + V_80 ) &
V_115 ) == V_115 )
while ( ( F_25 ( V_6 + V_80 ) &
V_116 ) == V_116 )
;
F_2 ( F_25 ( V_6 + V_80 ) | V_117 ,
V_6 + V_80 ) ;
F_2 ( F_25 ( V_6 + V_80 ) | V_116 ,
V_6 + V_80 ) ;
} else if ( V_112 & V_118 ) {
F_2 ( F_25 ( V_111 ) | V_118 , V_111 ) ;
} else if ( V_112 & V_119 ) {
F_2 ( F_25 ( V_111 ) | V_119 , V_111 ) ;
}
return V_120 ;
}
static int F_34 ( struct V_121 * V_122 ,
unsigned long V_89 , void * V_123 )
{
struct V_3 * V_2 ;
struct V_1 * V_124 ;
long V_125 ;
V_2 = F_35 ( V_122 , struct V_3 , V_126 ) ;
V_124 = F_36 ( F_37 ( V_2 -> V_24 ) ) ;
V_125 = V_2 -> V_23 - F_38 ( V_2 -> V_22 ) ;
if ( ( V_89 == V_127 && V_125 > 0 ) ||
( V_89 == V_128 && V_125 < 0 ) ) {
V_2 -> V_23 = F_38 ( V_2 -> V_22 ) ;
F_19 ( V_124 ) ;
}
return 0 ;
}
static inline int F_39 ( struct V_3 * V_4 )
{
V_4 -> V_126 . V_129 = F_34 ;
return F_40 ( & V_4 -> V_126 ,
V_130 ) ;
}
static inline void F_41 ( struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_126 ,
V_130 ) ;
}
static inline int F_34 ( struct V_121 * V_122 ,
unsigned long V_89 , void * V_123 )
{
return 0 ;
}
static inline int F_39 ( struct V_3 * V_4 )
{
return 0 ;
}
static inline void F_41 ( struct V_3 * V_2 )
{
}
static int T_6 F_43 ( struct V_131 * V_132 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
struct V_1 * V_124 ;
struct V_26 * V_27 ;
struct V_133 * V_134 ;
int V_135 ;
int V_109 ;
int V_33 ;
int V_136 ;
F_5 ( & V_132 -> V_24 , L_13 ) ;
V_27 = V_132 -> V_24 . V_28 ;
if ( V_27 == NULL ) {
F_44 ( & V_132 -> V_24 ,
L_14 ) ;
return - V_39 ;
}
if ( V_27 -> V_31 > V_27 -> V_37 ) {
F_44 ( & V_132 -> V_24 ,
L_15 ,
V_27 -> V_31 , V_27 -> V_37 ) ;
return - V_39 ;
}
V_30 = V_27 -> V_32 + V_27 -> V_31 ;
V_109 = F_45 ( V_132 , 0 ) ;
if ( V_109 < 0 ) {
F_44 ( & V_132 -> V_24 , L_16 ) ;
return - V_137 ;
}
V_124 = F_46 ( sizeof( struct V_3 ) , & V_132 -> V_24 ) ;
if ( ! V_124 )
return - V_108 ;
F_47 ( V_132 , V_124 ) ;
V_4 = V_124 -> V_5 ;
V_4 -> V_24 = & V_132 -> V_24 ;
#ifdef F_48
V_4 -> V_138 = V_139 ;
#endif
V_134 = F_49 ( V_132 , V_140 , 0 ) ;
V_136 = F_50 ( V_134 ) ;
V_4 -> V_141 = F_51 ( V_134 -> V_142 , V_136 , V_132 -> V_143 ) ;
if ( V_4 -> V_141 == NULL ) {
F_44 ( & V_132 -> V_24 , L_17 ) ;
V_135 = - V_137 ;
goto V_144;
}
V_4 -> V_7 = F_52 ( V_134 -> V_142 , V_136 ) ;
if ( V_4 -> V_7 == NULL ) {
F_44 ( & V_132 -> V_24 , L_18 ) ;
V_135 = - V_145 ;
goto V_146;
}
V_4 -> V_111 = V_4 -> V_7 + V_113 ;
F_2 ( 0 , V_4 -> V_7 + V_80 ) ;
strcpy ( V_124 -> V_10 . V_147 , V_148 ) ;
V_124 -> V_10 . type = V_149 ;
V_124 -> V_10 . V_150 = 0 ;
V_124 -> V_10 . V_151 = 0 ;
V_124 -> V_10 . V_152 = 0 ;
V_124 -> V_10 . V_153 = 0 ;
V_124 -> V_10 . V_154 = V_155 ;
V_124 -> V_13 . V_156 = 0 ;
V_124 -> V_13 . V_157 = V_158 ;
V_124 -> V_13 . V_159 = 0 ;
V_124 -> V_13 . V_160 = V_161 ;
V_124 -> V_162 = & V_163 ;
V_124 -> V_164 = V_165 ;
V_124 -> V_91 = & V_4 -> V_166 ;
V_135 = F_53 ( V_109 , F_33 , V_167 ,
V_132 -> V_143 , V_124 ) ;
if ( V_135 ) {
F_44 ( & V_132 -> V_24 , L_19 ,
V_109 , V_135 ) ;
V_135 = - V_168 ;
goto V_169;
}
V_4 -> V_22 = F_54 ( & V_132 -> V_24 , NULL ) ;
if ( F_55 ( V_4 -> V_22 ) ) {
F_7 ( V_38 L_20 ) ;
V_135 = F_56 ( V_4 -> V_22 ) ;
goto V_170;
}
F_57 ( V_4 -> V_22 ) ;
F_5 ( & V_132 -> V_24 , L_21 ) ;
V_4 -> V_23 = F_38 ( V_4 -> V_22 ) ;
for ( V_33 = 0 ; V_33 < V_27 -> V_37 ; V_33 ++ ) {
unsigned long V_105 = V_27 -> V_32 [ V_33 ] . V_34 ;
V_105 *= V_27 -> V_32 [ V_33 ] . V_14 ;
V_105 *= V_27 -> V_32 [ V_33 ] . V_36 ;
V_105 >>= 3 ;
if ( V_124 -> V_10 . V_105 < V_105 )
V_124 -> V_10 . V_105 = V_105 ;
}
V_135 = F_28 ( V_124 ) ;
if ( V_135 ) {
F_7 ( V_38 L_22 , V_135 ) ;
goto V_171;
}
F_5 ( & V_132 -> V_24 , L_23 ) ;
V_124 -> V_13 . V_34 = V_30 -> V_34 ;
V_124 -> V_13 . V_14 = V_30 -> V_14 ;
V_124 -> V_13 . V_35 = V_30 -> V_36 ;
F_26 ( V_124 ) ;
F_6 ( & V_124 -> V_13 , V_124 ) ;
V_135 = F_39 ( V_4 ) ;
if ( V_135 < 0 ) {
F_44 ( & V_132 -> V_24 , L_24 ) ;
goto V_172;
}
V_135 = F_58 ( V_124 ) ;
if ( V_135 ) {
F_7 ( V_38 L_25 ,
V_135 ) ;
goto V_173;
}
F_7 ( V_174 L_26 ,
V_124 -> V_175 , V_124 -> V_10 . V_147 ) ;
return 0 ;
V_173:
F_41 ( V_4 ) ;
V_172:
F_31 ( V_124 ) ;
V_171:
F_59 ( V_4 -> V_22 ) ;
F_60 ( V_4 -> V_22 ) ;
V_170:
F_61 ( V_109 , V_4 ) ;
V_169:
F_62 ( V_4 -> V_7 ) ;
V_146:
V_146 ( V_134 -> V_142 , V_136 ) ;
V_144:
F_63 ( V_124 ) ;
return V_135 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 ;
F_2 ( ( ~ V_176 ) | ( ~ V_116 ) | ( ~ V_177 ) ,
V_6 + V_80 ) ;
}
static int F_65 ( struct V_131 * V_132 )
{
struct V_1 * V_124 = F_36 ( V_132 ) ;
struct V_3 * V_4 = V_124 -> V_5 ;
int V_109 ;
F_64 ( V_124 ) ;
F_66 ( 1 ) ;
F_67 ( V_124 ) ;
F_41 ( V_4 ) ;
F_31 ( V_124 ) ;
F_62 ( V_4 -> V_7 ) ;
V_109 = F_45 ( V_132 , 0 ) ;
F_61 ( V_109 , V_4 ) ;
F_68 ( V_4 -> V_141 ) ;
F_69 ( V_4 -> V_141 ) ;
F_47 ( V_132 , NULL ) ;
F_63 ( V_124 ) ;
return 0 ;
}
static int F_70 ( struct V_131 * V_24 , T_7 V_178 )
{
struct V_1 * V_124 = F_36 ( V_24 ) ;
struct V_3 * V_2 = V_124 -> V_5 ;
F_64 ( V_124 ) ;
F_66 ( 1 ) ;
F_59 ( V_2 -> V_22 ) ;
return 0 ;
}
static int F_71 ( struct V_131 * V_24 )
{
struct V_1 * V_124 = F_36 ( V_24 ) ;
struct V_3 * V_4 = V_124 -> V_5 ;
F_7 ( V_174 L_27 ) ;
F_57 ( V_4 -> V_22 ) ;
F_66 ( 1 ) ;
F_26 ( V_124 ) ;
F_19 ( V_124 ) ;
return 0 ;
}
int T_6 F_72 ( void )
{
return F_73 ( & V_179 ) ;
}
static void T_8 F_74 ( void )
{
F_75 ( & V_179 ) ;
}
