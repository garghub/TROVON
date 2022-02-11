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
struct V_26 * V_27 = F_7 ( V_4 -> V_24 ) ;
struct V_28 * V_29 = NULL ;
struct V_28 * V_30 = V_27 -> V_31 +
V_27 -> V_30 ;
int V_32 ;
F_5 ( V_4 -> V_24 , L_2 , V_13 , V_2 ) ;
if ( V_13 -> V_33 == V_30 -> V_33 &&
V_13 -> V_14 == V_30 -> V_14 &&
V_13 -> V_34 == V_30 -> V_35 )
V_29 = V_30 ;
else
for ( V_32 = 0 ; V_32 < V_27 -> V_36 ; V_32 ++ )
if ( V_13 -> V_33 == V_27 -> V_31 [ V_32 ] . V_33 &&
V_13 -> V_14 == V_27 -> V_31 [ V_32 ] . V_14 &&
V_13 -> V_34 == V_27 -> V_31 [ V_32 ] . V_35 ) {
V_29 = V_27 -> V_31 + V_32 ;
break;
}
if ( V_29 == NULL ) {
F_8 ( V_37 L_3 ,
V_13 -> V_33 , V_13 -> V_14 , V_13 -> V_34 ) ;
return - V_38 ;
}
V_13 -> V_39 = V_29 -> V_33 ;
V_13 -> V_40 = V_29 -> V_14 ;
V_13 -> V_41 = V_29 -> V_41 ;
V_13 -> V_42 = V_29 -> V_42 ;
V_13 -> V_43 = V_29 -> V_43 ;
V_13 -> V_44 = V_29 -> V_44 ;
V_13 -> V_45 = V_29 -> V_45 ;
V_13 -> V_46 = V_29 -> V_46 ;
V_13 -> V_47 = V_29 -> V_47 ;
V_13 -> V_48 = V_29 -> V_48 ;
V_13 -> V_49 = V_29 -> V_49 ;
V_13 -> V_50 . V_51 = 0 ;
V_13 -> V_50 . V_52 = 0 ;
V_4 -> V_6 . V_53 = V_29 -> V_54 ;
V_4 -> V_6 . V_55 = V_29 -> V_56 ;
V_4 -> V_6 . V_17 = V_29 -> V_57 ;
V_4 -> V_6 . V_19 = V_29 -> V_58 ;
switch ( V_13 -> V_34 ) {
case 1 :
case 2 :
case 4 :
case 8 :
default:
V_13 -> V_59 . V_51 = 0 ;
V_13 -> V_59 . V_52 = V_13 -> V_34 ;
V_13 -> V_60 = V_13 -> V_59 ;
V_13 -> V_61 = V_13 -> V_59 ;
break;
case 12 :
V_13 -> V_59 . V_52 = 4 ;
V_13 -> V_60 . V_52 = 4 ;
V_13 -> V_61 . V_52 = 4 ;
V_13 -> V_59 . V_51 = 8 ;
V_13 -> V_60 . V_51 = 4 ;
V_13 -> V_61 . V_51 = 0 ;
break;
case 16 :
V_13 -> V_59 . V_52 = 5 ;
V_13 -> V_60 . V_52 = 6 ;
V_13 -> V_61 . V_52 = 5 ;
V_13 -> V_59 . V_51 = 11 ;
V_13 -> V_60 . V_51 = 5 ;
V_13 -> V_61 . V_51 = 0 ;
break;
case 18 :
V_13 -> V_59 . V_52 = 6 ;
V_13 -> V_60 . V_52 = 6 ;
V_13 -> V_61 . V_52 = 6 ;
V_13 -> V_59 . V_51 = 12 ;
V_13 -> V_60 . V_51 = 6 ;
V_13 -> V_61 . V_51 = 0 ;
break;
case 32 :
V_13 -> V_59 . V_52 = 8 ;
V_13 -> V_60 . V_52 = 8 ;
V_13 -> V_61 . V_52 = 8 ;
V_13 -> V_59 . V_51 = 16 ;
V_13 -> V_60 . V_51 = 8 ;
V_13 -> V_61 . V_51 = 0 ;
break;
}
return 0 ;
}
static void F_9 ( const struct V_1 * V_2 ,
struct V_62 * V_6 )
{
const struct V_25 * V_13 = & V_2 -> V_13 ;
int V_63 = V_13 -> V_41 + V_13 -> V_46 + V_13 -> V_47 ;
int V_64 = V_13 -> V_42 + V_13 -> V_44 + V_13 -> V_45 ;
int V_65 = V_13 -> V_42 + V_13 -> V_45 ;
int V_66 = V_13 -> V_41 + V_13 -> V_47 ;
V_6 -> V_67 = F_10 ( V_63 ) |
F_11 ( V_64 ) ;
V_6 -> V_68 = F_12 ( V_13 -> V_41 ) |
F_13 ( V_13 -> V_42 ) ;
V_6 -> V_69 = F_14 ( V_13 -> V_42 + 5 ) |
F_15 ( V_13 -> V_42 + 1 ) ;
V_6 -> V_70 = F_16 ( V_65 + V_13 -> V_49 ) |
F_17 ( V_65 ) ;
V_6 -> V_71 = F_18 ( V_66 + V_13 -> V_48 ) |
F_19 ( V_66 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 ;
struct V_25 * V_13 = & V_2 -> V_13 ;
int V_72 ;
V_72 = F_3 ( V_4 , V_13 -> V_43 ) - 1 ;
if ( V_72 < 0 )
V_72 = 0 ;
F_9 ( V_2 , & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_24 , L_4 ) ;
F_5 ( V_4 -> V_24 , L_5 , V_4 -> V_6 . V_53 ) ;
F_5 ( V_4 -> V_24 , L_6 , V_4 -> V_6 . V_55 ) ;
F_5 ( V_4 -> V_24 , L_7 , V_4 -> V_6 . V_67 ) ;
F_5 ( V_4 -> V_24 , L_8 , V_4 -> V_6 . V_68 ) ;
F_5 ( V_4 -> V_24 , L_9 , V_4 -> V_6 . V_69 ) ;
F_5 ( V_4 -> V_24 , L_10 , V_4 -> V_6 . V_70 ) ;
F_5 ( V_4 -> V_24 , L_11 , V_4 -> V_6 . V_71 ) ;
F_2 ( V_4 -> V_6 . V_55 , V_6 + V_73 ) ;
F_2 ( V_4 -> V_6 . V_67 , V_6 + V_74 ) ;
F_2 ( V_4 -> V_6 . V_68 , V_6 + V_75 ) ;
F_2 ( V_4 -> V_6 . V_69 , V_6 + V_76 ) ;
F_2 ( V_4 -> V_6 . V_70 , V_6 + V_77 ) ;
F_2 ( V_4 -> V_6 . V_71 , V_6 + V_78 ) ;
F_1 ( V_2 ) ;
F_2 ( V_4 -> V_6 . V_53 , V_6 + V_79 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_25 * V_13 = & V_2 -> V_13 ;
switch ( V_13 -> V_34 ) {
case 32 :
case 24 :
case 18 :
case 16 :
case 12 :
V_2 -> V_10 . V_80 = V_81 ;
break;
case 1 :
V_2 -> V_10 . V_80 = V_82 ;
break;
default:
V_2 -> V_10 . V_80 = V_83 ;
break;
}
V_2 -> V_10 . V_12 = ( V_13 -> V_39 * V_13 -> V_34 ) / 8 ;
F_20 ( V_2 ) ;
return 0 ;
}
static inline unsigned int F_22 ( unsigned int V_84 ,
struct V_85 * V_86 )
{
V_84 &= 0xffff ;
V_84 >>= 16 - V_86 -> V_52 ;
return V_84 << V_86 -> V_51 ;
}
static int F_23 ( unsigned V_87 ,
unsigned V_59 , unsigned V_60 , unsigned V_61 ,
unsigned V_50 , struct V_1 * V_2 )
{
unsigned int V_88 ;
switch ( V_2 -> V_10 . V_80 ) {
case V_81 :
if ( V_87 < 16 ) {
T_2 * V_89 = V_2 -> V_90 ;
V_88 = F_22 ( V_59 , & V_2 -> V_13 . V_59 ) ;
V_88 |= F_22 ( V_60 , & V_2 -> V_13 . V_60 ) ;
V_88 |= F_22 ( V_61 , & V_2 -> V_13 . V_61 ) ;
V_89 [ V_87 ] = V_88 ;
}
break;
default:
return 1 ;
}
return 0 ;
}
static int F_24 ( int V_91 , struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_25 ( void T_1 * V_92 ,
unsigned long V_93 , unsigned long V_94 )
{
unsigned long V_95 ;
V_95 = F_26 ( V_92 ) & ~ V_94 ;
F_2 ( V_95 | V_93 , V_92 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 = F_7 ( V_4 -> V_24 ) ;
void T_1 * V_6 = V_4 -> V_7 ;
F_2 ( 0 , V_6 + V_79 ) ;
F_2 ( F_26 ( V_6 + V_79 ) | V_96 ,
V_6 + V_79 ) ;
F_28 ( 100 ) ;
F_2 ( F_26 ( V_6 + V_79 ) & ( ~ V_96 ) ,
V_6 + V_79 ) ;
F_28 ( 100 ) ;
F_2 ( 0 , V_6 + V_73 ) ;
F_25 ( V_97 + 0x54 , V_27 -> V_98 ,
V_27 -> V_99 ) ;
F_25 ( V_97 + 0x58 , V_27 -> V_100 ,
V_27 -> V_101 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_102 ;
unsigned long V_103 = F_30 ( V_2 -> V_10 . V_104 ) ;
F_5 ( V_4 -> V_24 , L_12 ,
V_4 , V_103 ) ;
V_2 -> V_105 = F_31 ( V_4 -> V_24 , V_103 , & V_102 ,
V_106 ) ;
if ( ! V_2 -> V_105 )
return - V_107 ;
memset ( V_2 -> V_105 , 0x00 , V_103 ) ;
V_2 -> V_10 . V_11 = V_102 ;
return 0 ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_33 ( V_4 -> V_24 , F_30 ( V_2 -> V_10 . V_104 ) ,
V_2 -> V_105 , V_2 -> V_10 . V_11 ) ;
}
static T_4 F_34 ( int V_108 , void * V_109 )
{
struct V_3 * V_4 = V_109 ;
void T_1 * V_6 = V_4 -> V_7 ;
void T_1 * V_110 = V_4 -> V_110 ;
unsigned long V_111 = F_26 ( V_6 + V_112 ) ;
if ( V_111 & V_113 ) {
F_2 ( F_26 ( V_110 ) | 1 << 30 , V_110 ) ;
if ( ( F_26 ( V_6 + V_79 ) &
V_114 ) == V_114 )
while ( ( F_26 ( V_6 + V_79 ) &
V_115 ) == V_115 )
;
F_2 ( F_26 ( V_6 + V_79 ) | V_116 ,
V_6 + V_79 ) ;
F_2 ( F_26 ( V_6 + V_79 ) | V_115 ,
V_6 + V_79 ) ;
} else if ( V_111 & V_117 ) {
F_2 ( F_26 ( V_110 ) | V_117 , V_110 ) ;
} else if ( V_111 & V_118 ) {
F_2 ( F_26 ( V_110 ) | V_118 , V_110 ) ;
}
return V_119 ;
}
static int F_35 ( struct V_120 * V_121 ,
unsigned long V_88 , void * V_122 )
{
struct V_3 * V_2 ;
struct V_1 * V_123 ;
long V_124 ;
V_2 = F_36 ( V_121 , struct V_3 , V_125 ) ;
V_123 = F_37 ( F_38 ( V_2 -> V_24 ) ) ;
V_124 = V_2 -> V_23 - F_39 ( V_2 -> V_22 ) ;
if ( ( V_88 == V_126 && V_124 > 0 ) ||
( V_88 == V_127 && V_124 < 0 ) ) {
V_2 -> V_23 = F_39 ( V_2 -> V_22 ) ;
F_20 ( V_123 ) ;
}
return 0 ;
}
static inline int F_40 ( struct V_3 * V_4 )
{
V_4 -> V_125 . V_128 = F_35 ;
return F_41 ( & V_4 -> V_125 ,
V_129 ) ;
}
static inline void F_42 ( struct V_3 * V_4 )
{
F_43 ( & V_4 -> V_125 ,
V_129 ) ;
}
static inline int F_35 ( struct V_120 * V_121 ,
unsigned long V_88 , void * V_122 )
{
return 0 ;
}
static inline int F_40 ( struct V_3 * V_4 )
{
return 0 ;
}
static inline void F_42 ( struct V_3 * V_2 )
{
}
static int F_44 ( struct V_130 * V_131 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_123 ;
struct V_26 * V_27 ;
struct V_132 * V_133 ;
int V_134 ;
int V_108 ;
int V_32 ;
int V_135 ;
F_5 ( & V_131 -> V_24 , L_13 ) ;
V_27 = F_7 ( & V_131 -> V_24 ) ;
if ( V_27 == NULL ) {
F_45 ( & V_131 -> V_24 ,
L_14 ) ;
return - V_38 ;
}
if ( V_27 -> V_30 > V_27 -> V_36 ) {
F_45 ( & V_131 -> V_24 ,
L_15 ,
V_27 -> V_30 , V_27 -> V_36 ) ;
return - V_38 ;
}
V_29 = V_27 -> V_31 + V_27 -> V_30 ;
V_108 = F_46 ( V_131 , 0 ) ;
if ( V_108 < 0 ) {
F_45 ( & V_131 -> V_24 , L_16 ) ;
return - V_136 ;
}
V_123 = F_47 ( sizeof( struct V_3 ) , & V_131 -> V_24 ) ;
if ( ! V_123 )
return - V_107 ;
F_48 ( V_131 , V_123 ) ;
V_4 = V_123 -> V_5 ;
V_4 -> V_24 = & V_131 -> V_24 ;
#ifdef F_49
V_4 -> V_137 = V_138 ;
#endif
V_133 = F_50 ( V_131 , V_139 , 0 ) ;
V_135 = F_51 ( V_133 ) ;
V_4 -> V_140 = F_52 ( V_133 -> V_141 , V_135 , V_131 -> V_142 ) ;
if ( V_4 -> V_140 == NULL ) {
F_45 ( & V_131 -> V_24 , L_17 ) ;
V_134 = - V_136 ;
goto V_143;
}
V_4 -> V_7 = F_53 ( V_133 -> V_141 , V_135 ) ;
if ( V_4 -> V_7 == NULL ) {
F_45 ( & V_131 -> V_24 , L_18 ) ;
V_134 = - V_144 ;
goto V_145;
}
V_4 -> V_110 = V_4 -> V_7 + V_112 ;
F_2 ( 0 , V_4 -> V_7 + V_79 ) ;
strcpy ( V_123 -> V_10 . V_146 , V_147 ) ;
V_123 -> V_10 . type = V_148 ;
V_123 -> V_10 . V_149 = 0 ;
V_123 -> V_10 . V_150 = 0 ;
V_123 -> V_10 . V_151 = 0 ;
V_123 -> V_10 . V_152 = 0 ;
V_123 -> V_10 . V_153 = V_154 ;
V_123 -> V_13 . V_155 = 0 ;
V_123 -> V_13 . V_156 = V_157 ;
V_123 -> V_13 . V_158 = 0 ;
V_123 -> V_13 . V_159 = V_160 ;
V_123 -> V_161 = & V_162 ;
V_123 -> V_163 = V_164 ;
V_123 -> V_90 = & V_4 -> V_165 ;
V_134 = F_54 ( V_108 , F_34 , 0 , V_131 -> V_142 , V_4 ) ;
if ( V_134 ) {
F_45 ( & V_131 -> V_24 , L_19 ,
V_108 , V_134 ) ;
V_134 = - V_166 ;
goto V_167;
}
V_4 -> V_22 = F_55 ( & V_131 -> V_24 , NULL ) ;
if ( F_56 ( V_4 -> V_22 ) ) {
F_8 ( V_37 L_20 ) ;
V_134 = F_57 ( V_4 -> V_22 ) ;
goto V_168;
}
F_58 ( V_4 -> V_22 ) ;
F_5 ( & V_131 -> V_24 , L_21 ) ;
V_4 -> V_23 = F_39 ( V_4 -> V_22 ) ;
for ( V_32 = 0 ; V_32 < V_27 -> V_36 ; V_32 ++ ) {
unsigned long V_104 = V_27 -> V_31 [ V_32 ] . V_33 ;
V_104 *= V_27 -> V_31 [ V_32 ] . V_14 ;
V_104 *= V_27 -> V_31 [ V_32 ] . V_35 ;
V_104 >>= 3 ;
if ( V_123 -> V_10 . V_104 < V_104 )
V_123 -> V_10 . V_104 = V_104 ;
}
V_134 = F_29 ( V_123 ) ;
if ( V_134 ) {
F_8 ( V_37 L_22 , V_134 ) ;
goto V_169;
}
F_5 ( & V_131 -> V_24 , L_23 ) ;
V_123 -> V_13 . V_33 = V_29 -> V_33 ;
V_123 -> V_13 . V_14 = V_29 -> V_14 ;
V_123 -> V_13 . V_34 = V_29 -> V_35 ;
F_27 ( V_123 ) ;
F_6 ( & V_123 -> V_13 , V_123 ) ;
V_134 = F_40 ( V_4 ) ;
if ( V_134 < 0 ) {
F_45 ( & V_131 -> V_24 , L_24 ) ;
goto V_170;
}
V_134 = F_59 ( V_123 ) ;
if ( V_134 ) {
F_8 ( V_37 L_25 ,
V_134 ) ;
goto V_171;
}
V_1 ( V_123 , L_26 , V_123 -> V_10 . V_146 ) ;
return 0 ;
V_171:
F_42 ( V_4 ) ;
V_170:
F_32 ( V_123 ) ;
V_169:
F_60 ( V_4 -> V_22 ) ;
F_61 ( V_4 -> V_22 ) ;
V_168:
F_62 ( V_108 , V_4 ) ;
V_167:
F_63 ( V_4 -> V_7 ) ;
V_145:
V_145 ( V_133 -> V_141 , V_135 ) ;
V_143:
F_64 ( V_123 ) ;
return V_134 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 ;
F_2 ( ( ~ V_172 ) | ( ~ V_115 ) | ( ~ V_173 ) ,
V_6 + V_79 ) ;
}
static int F_66 ( struct V_130 * V_131 )
{
struct V_1 * V_123 = F_37 ( V_131 ) ;
struct V_3 * V_4 = V_123 -> V_5 ;
int V_108 ;
F_65 ( V_123 ) ;
F_67 ( 1 ) ;
F_68 ( V_123 ) ;
F_42 ( V_4 ) ;
F_32 ( V_123 ) ;
F_63 ( V_4 -> V_7 ) ;
V_108 = F_46 ( V_131 , 0 ) ;
F_62 ( V_108 , V_4 ) ;
F_69 ( V_4 -> V_140 ) ;
F_70 ( V_4 -> V_140 ) ;
F_64 ( V_123 ) ;
return 0 ;
}
static int F_71 ( struct V_130 * V_24 , T_5 V_174 )
{
struct V_1 * V_123 = F_37 ( V_24 ) ;
struct V_3 * V_2 = V_123 -> V_5 ;
F_65 ( V_123 ) ;
F_67 ( 1 ) ;
F_60 ( V_2 -> V_22 ) ;
return 0 ;
}
static int F_72 ( struct V_130 * V_24 )
{
struct V_1 * V_123 = F_37 ( V_24 ) ;
struct V_3 * V_4 = V_123 -> V_5 ;
F_8 ( V_175 L_27 ) ;
F_58 ( V_4 -> V_22 ) ;
F_67 ( 1 ) ;
F_27 ( V_123 ) ;
F_20 ( V_123 ) ;
return 0 ;
}
