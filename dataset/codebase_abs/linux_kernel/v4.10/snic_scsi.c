const char *
F_1 ( unsigned int V_1 )
{
if ( V_1 >= F_2 ( V_2 ) || ! V_2 [ V_1 ] )
return L_1 ;
return V_2 [ V_1 ] ;
}
static const char *
F_3 ( unsigned int V_1 )
{
if ( ( V_1 >= F_2 ( V_3 ) ) ||
( ! V_3 [ V_1 ] ) )
return L_1 ;
return V_3 [ V_1 ] ;
}
static const char *
F_4 ( unsigned int V_1 )
{
if ( V_1 >= F_2 ( V_4 ) ||
! V_4 [ V_1 ] )
return L_1 ;
return V_4 [ V_1 ] ;
}
static inline T_1 *
F_5 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
T_2 V_8 = F_6 ( V_7 ) & ( V_9 - 1 ) ;
return & V_5 -> V_10 [ V_8 ] ;
}
static inline T_1 *
F_7 ( struct V_5 * V_5 , int V_11 )
{
return & V_5 -> V_10 [ V_11 & ( V_9 - 1 ) ] ;
}
static void
F_8 ( struct V_5 * V_5 ,
struct V_12 * V_13 ,
struct V_6 * V_7 )
{
struct V_14 * V_15 = F_9 ( V_13 ) ;
F_10 ( ! ( ( F_11 ( V_7 ) == V_16 ) ||
( F_11 ( V_7 ) == V_17 ) ||
( F_12 ( V_7 ) & V_18 ) ||
( F_12 ( V_7 ) & V_19 ) ||
( F_12 ( V_7 ) & V_20 ) ||
( F_12 ( V_7 ) & V_21 ) ||
( F_11 ( V_7 ) == V_22 ) ) ) ;
F_13 ( V_5 -> V_23 ,
L_2 ,
V_7 , F_6 ( V_7 ) , V_13 , V_13 -> V_15 , V_13 -> V_24 ,
V_13 -> V_25 , F_4 ( F_11 ( V_7 ) ) ,
F_12 ( V_7 ) ) ;
if ( V_15 -> V_26 . V_27 . V_28 )
F_14 ( V_5 -> V_29 ,
F_15 ( V_15 -> V_26 . V_27 . V_28 ) ,
V_30 ,
V_31 ) ;
F_16 ( V_7 ) ;
F_17 ( V_5 , V_13 ) ;
}
static int
F_18 ( struct V_5 * V_5 ,
struct V_12 * V_13 ,
struct V_6 * V_7 ,
int V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_3 V_37 = 0 ;
struct V_38 V_39 ;
T_4 V_40 = 0 ;
int V_41 = 0 ;
unsigned int V_42 ;
if ( V_32 ) {
V_40 = V_43 ;
V_36 = (struct V_35 * ) F_19 ( V_13 -> V_15 ) ;
F_20 (scsi_sglist(sc), sg, sg_cnt, i) {
V_36 -> V_44 = F_21 ( F_22 ( V_34 ) ) ;
V_36 -> V_45 = F_23 ( F_24 ( V_34 ) ) ;
V_36 -> V_46 = 0 ;
V_36 ++ ;
}
}
V_37 = F_25 ( V_5 -> V_29 ,
V_7 -> V_47 ,
V_30 ,
V_31 ) ;
if ( F_26 ( V_5 -> V_29 , V_37 ) ) {
F_27 ( V_5 -> V_23 ,
L_3 ,
V_7 -> V_47 , F_6 ( V_7 ) ) ;
V_41 = - V_48 ;
return V_41 ;
}
F_28 ( V_7 -> V_49 -> V_39 , & V_39 ) ;
if ( V_7 -> V_50 == V_51 )
V_40 |= V_52 ;
if ( V_7 -> V_50 == V_53 )
V_40 |= V_54 ;
F_29 ( V_13 -> V_15 ,
F_6 ( V_7 ) ,
V_5 -> V_55 . V_56 ,
( V_57 ) V_13 ,
V_40 ,
V_13 -> V_58 ,
V_39 . V_38 ,
V_7 -> V_59 ,
V_7 -> V_60 ,
F_30 ( V_7 ) ,
V_32 ,
( V_57 ) F_19 ( V_13 -> V_15 ) ,
V_37 ,
V_30 ) ;
F_31 ( & V_5 -> V_61 . V_62 . V_63 ) ;
V_41 = F_32 ( V_5 , V_13 -> V_15 , V_13 -> V_64 ) ;
if ( V_41 ) {
F_33 ( & V_5 -> V_61 . V_62 . V_63 ) ;
F_27 ( V_5 -> V_23 ,
L_4 ,
V_41 ) ;
} else
F_34 ( & V_5 -> V_61 ) ;
return V_41 ;
}
static int
F_35 ( struct V_5 * V_5 ,
struct V_65 * V_66 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
int V_32 = 0 ;
int V_41 = 0 ;
T_2 V_11 = F_6 ( V_7 ) ;
T_5 V_67 = 0 , V_68 = 0 ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
F_11 ( V_7 ) = V_70 ;
F_12 ( V_7 ) = V_71 ;
V_32 = F_36 ( V_7 ) ;
if ( V_32 < 0 ) {
F_37 ( ( T_4 ) V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 , 0 ,
V_7 -> V_59 [ 0 ] , V_32 , F_11 ( V_7 ) ) ;
F_27 ( V_5 -> V_23 , L_5 ) ;
V_41 = - V_48 ;
goto V_73;
}
V_13 = F_38 ( V_5 , V_32 ) ;
if ( ! V_13 ) {
F_16 ( V_7 ) ;
V_41 = - V_48 ;
goto V_73;
}
V_13 -> V_58 = V_66 -> V_74 ;
V_13 -> V_7 = V_7 ;
F_11 ( V_7 ) = V_75 ;
F_39 ( V_7 ) = ( char * ) V_13 ;
V_67 = F_40 ( V_7 ) ;
F_12 ( V_7 ) |= ( V_76 | V_77 ) ;
V_68 = F_41 ( V_7 ) ;
V_69 = F_5 ( V_5 , V_7 ) ;
V_41 = F_18 ( V_5 , V_13 , V_7 , V_32 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_6 ,
V_7 , V_41 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_39 ( V_7 ) = NULL ;
F_11 ( V_7 ) = V_16 ;
F_12 ( V_7 ) &= ~ V_77 ;
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_8 ( V_5 , V_13 , V_7 ) ;
F_37 ( V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 , 0 , 0 , 0 ,
F_41 ( V_7 ) ) ;
} else {
T_2 V_78 = F_30 ( V_7 ) >> 9 ;
T_2 V_79 = V_80 - V_13 -> V_81 ;
struct V_82 * V_83 = & V_5 -> V_61 . V_62 ;
if ( V_78 > F_44 ( & V_83 -> V_84 ) )
F_45 ( & V_83 -> V_84 , V_78 ) ;
if ( V_79 > F_44 ( & V_83 -> V_85 ) )
F_45 ( & V_83 -> V_85 , V_79 ) ;
F_13 ( V_5 -> V_23 ,
L_7 ,
V_7 , V_11 ) ;
F_37 ( V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 , ( V_57 ) V_13 ,
V_32 , V_67 , V_68 ) ;
}
V_73:
return V_41 ;
}
int
F_46 ( struct V_86 * V_23 , struct V_6 * V_7 )
{
struct V_65 * V_66 = NULL ;
struct V_5 * V_5 = F_47 ( V_23 ) ;
int V_41 ;
V_66 = F_48 ( F_49 ( V_7 -> V_49 ) ) ;
V_41 = F_50 ( V_66 ) ;
if ( V_41 ) {
F_27 ( V_23 , L_8 , V_66 , V_66 -> V_74 ) ;
F_31 ( & V_5 -> V_61 . V_87 . V_88 ) ;
V_7 -> V_89 = V_41 ;
V_7 -> V_90 ( V_7 ) ;
return 0 ;
}
if ( F_51 ( V_5 ) != V_91 ) {
F_27 ( V_23 , L_9 ,
V_2 [ F_51 ( V_5 ) ] ) ;
return V_92 ;
}
F_52 ( & V_5 -> V_93 ) ;
F_13 ( V_23 , L_10 ,
V_7 , F_6 ( V_7 ) , V_7 -> V_59 [ 0 ] , V_7 -> V_49 -> V_39 ) ;
memset ( F_53 ( V_7 ) , 0 , sizeof( struct V_94 ) ) ;
V_41 = F_35 ( V_5 , V_66 , V_7 ) ;
if ( V_41 ) {
F_27 ( V_23 , L_11 , V_41 ) ;
V_41 = V_92 ;
}
F_54 ( & V_5 -> V_93 ) ;
return V_41 ;
}
static void
F_55 ( struct V_5 * V_5 ,
struct V_6 * V_7 ,
T_6 V_95 )
{
int V_1 = F_11 ( V_7 ) ;
if ( V_1 == V_96 )
F_12 ( V_7 ) |= V_97 ;
else if ( V_1 == V_98 )
F_12 ( V_7 ) |= V_99 ;
else
F_10 ( 1 ) ;
switch ( V_95 ) {
case V_100 :
F_12 ( V_7 ) |= V_101 ;
break;
case V_102 :
F_12 ( V_7 ) |= V_103 ;
break;
default:
F_10 ( 1 ) ;
}
}
static void
F_56 ( struct V_5 * V_5 ,
struct V_104 * V_105 ,
struct V_6 * V_7 ,
T_6 V_106 )
{
int V_107 = 0 ;
switch ( V_106 ) {
case V_108 :
F_31 ( & V_5 -> V_61 . V_87 . V_109 ) ;
V_107 = V_110 ;
break;
case V_102 :
F_31 ( & V_5 -> V_61 . V_87 . V_111 ) ;
V_107 = V_112 ;
break;
case V_113 :
F_31 ( & V_5 -> V_61 . V_87 . V_114 ) ;
F_57 ( V_7 , F_58 ( V_105 -> V_115 ) ) ;
V_107 = V_116 ;
break;
case V_117 :
F_31 ( & V_5 -> V_61 . V_118 . V_119 ) ;
V_107 = V_120 ;
break;
case V_121 :
F_31 ( & V_5 -> V_61 . V_62 . V_122 ) ;
V_107 = V_116 ;
break;
case V_123 :
F_31 ( & V_5 -> V_61 . V_87 . V_124 ) ;
V_107 = V_116 ;
break;
case V_125 :
F_31 ( & V_5 -> V_61 . V_118 . V_126 ) ;
V_107 = V_116 ;
break;
case V_127 :
F_31 ( & V_5 -> V_61 . V_118 . V_128 ) ;
break;
case V_129 :
case V_130 :
V_107 = V_131 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
default:
F_13 ( V_5 -> V_23 ,
L_12 ) ;
V_107 = V_116 ;
break;
}
F_27 ( V_5 -> V_23 , L_13 ,
F_3 ( V_106 ) , F_12 ( V_7 ) ) ;
V_7 -> V_89 = ( V_107 << 16 ) | V_105 -> V_137 ;
}
static int
F_59 ( struct V_6 * V_7 )
{
int V_1 = F_11 ( V_7 ) ;
return ( ( V_1 == V_96 ) ||
( V_1 == V_98 ) ) ;
}
static int
F_60 ( struct V_5 * V_5 ,
struct V_104 * V_105 ,
T_6 V_106 ,
struct V_6 * V_7 )
{
T_6 V_138 = V_105 -> V_137 ;
T_5 V_139 = 0 ;
int V_41 = 0 ;
F_11 ( V_7 ) = V_16 ;
if ( F_61 ( V_106 == V_100 ) ) {
V_7 -> V_89 = ( V_140 << 16 ) | V_138 ;
V_139 = F_30 ( V_7 ) ;
F_57 ( V_7 , F_58 ( V_105 -> V_115 ) ) ;
if ( V_105 -> V_40 & V_141 ) {
V_139 -= F_58 ( V_105 -> V_115 ) ;
F_31 ( & V_5 -> V_61 . V_87 . V_142 ) ;
}
if ( V_105 -> V_137 == V_143 )
F_31 ( & V_5 -> V_61 . V_87 . V_144 ) ;
V_41 = 0 ;
} else {
F_56 ( V_5 , V_105 , V_7 , V_106 ) ;
F_31 ( & V_5 -> V_61 . V_62 . V_145 ) ;
F_27 ( V_5 -> V_23 ,
L_14 ,
F_3 ( V_106 ) , F_12 ( V_7 ) ) ;
V_41 = 1 ;
}
return V_41 ;
}
static void
F_62 ( struct V_5 * V_5 , struct V_146 * V_147 )
{
T_6 V_148 , V_149 ;
T_2 V_150 , V_56 ;
V_57 V_151 ;
struct V_6 * V_7 = NULL ;
struct V_104 * V_105 = NULL ;
struct V_14 * V_15 = NULL ;
struct V_12 * V_13 = NULL ;
unsigned long V_40 , V_81 ;
T_1 * V_69 ;
T_6 V_152 = 0 ;
F_63 ( & V_147 -> V_153 , & V_148 , & V_149 , & V_150 , & V_56 , & V_151 ) ;
V_105 = & V_147 -> V_26 . V_105 ;
V_152 = V_105 -> V_137 ;
F_13 ( V_5 -> V_23 ,
L_15 ,
V_148 , V_149 , V_150 , V_56 , V_151 ) ;
if ( V_150 >= V_5 -> V_154 ) {
F_27 ( V_5 -> V_23 ,
L_16 ,
V_150 , F_3 ( V_149 ) ) ;
return;
}
V_7 = F_64 ( V_5 -> V_23 , V_150 ) ;
F_65 ( ! V_7 ) ;
if ( ! V_7 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_155 ) ;
F_27 ( V_5 -> V_23 ,
L_17 ,
F_3 ( V_149 ) ,
V_150 ,
V_147 ) ;
F_37 ( V_5 -> V_23 -> V_72 , V_150 , 0 ,
( ( T_5 ) V_149 << 16 |
( T_5 ) V_152 << 8 | ( T_5 ) V_105 -> V_40 ) ,
( V_57 ) V_147 , F_58 ( V_105 -> V_115 ) , V_151 ) ;
return;
}
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_13 ( V_5 -> V_23 ,
L_18 ,
V_7 -> V_49 -> V_39 , V_7 , V_7 -> V_59 [ 0 ] , F_6 ( V_7 ) ,
F_12 ( V_7 ) , V_13 ) ;
if ( F_12 ( V_7 ) & V_156 ) {
F_43 ( V_69 , V_40 ) ;
return;
}
F_10 ( V_13 != (struct V_12 * ) V_151 ) ;
F_65 ( V_15 ) ;
if ( ! V_13 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_157 ) ;
F_12 ( V_7 ) |= V_158 ;
F_43 ( V_69 , V_40 ) ;
F_27 ( V_5 -> V_23 ,
L_19 ,
F_3 ( V_149 ) ,
V_150 , V_7 , F_12 ( V_7 ) ) ;
return;
}
V_13 = (struct V_12 * ) V_151 ;
V_81 = V_13 -> V_81 ;
V_13 -> V_159 = 1 ;
if ( F_66 ( F_59 ( V_7 ) ) ) {
F_55 ( V_5 , V_7 , V_149 ) ;
F_43 ( V_69 , V_40 ) ;
F_67 ( & V_5 -> V_61 ) ;
if ( F_61 ( V_149 == V_102 ) )
return;
F_13 ( V_5 -> V_23 ,
L_20 ,
F_4 ( F_11 ( V_7 ) ) ,
F_3 ( V_149 ) ,
V_7 , V_152 , F_58 ( V_105 -> V_115 ) ,
F_12 ( V_7 ) ) ;
F_37 ( V_5 -> V_23 -> V_72 , V_150 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) , ( V_57 ) V_147 ,
F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
return;
}
if ( F_60 ( V_5 , V_105 , V_149 , V_7 ) ) {
F_69 ( V_7 ) ;
F_27 ( V_5 -> V_23 ,
L_21 ,
V_7 , V_7 -> V_59 [ 0 ] , V_150 ,
F_3 ( V_149 ) , F_12 ( V_7 ) ) ;
}
F_39 ( V_7 ) = NULL ;
F_12 ( V_7 ) |= V_101 ;
F_43 ( V_69 , V_40 ) ;
F_70 ( V_5 , V_13 ) ;
F_8 ( V_5 , V_13 , V_7 ) ;
F_37 ( V_5 -> V_23 -> V_72 , V_150 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) , ( V_57 ) V_147 ,
F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
if ( V_7 -> V_90 )
V_7 -> V_90 ( V_7 ) ;
F_67 ( & V_5 -> V_61 ) ;
}
static void
F_71 ( struct V_5 * V_5 ,
struct V_146 * V_147 ,
T_6 V_106 ,
T_2 V_150 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
T_2 V_81 = V_13 -> V_81 ;
F_72 ( V_7 ) = V_106 ;
F_13 ( V_5 -> V_23 , L_22 ,
F_4 ( F_11 ( V_7 ) ) ) ;
if ( F_11 ( V_7 ) == V_96 ) {
F_12 ( V_7 ) |= V_160 ;
F_37 ( V_5 -> V_23 -> V_72 , V_150 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) ,
( V_57 ) V_147 , 0 , F_41 ( V_7 ) ) ;
F_13 ( V_5 -> V_23 ,
L_23 ,
( int ) ( V_150 & V_161 ) ,
F_3 ( V_106 ) ,
F_12 ( V_7 ) ) ;
return;
}
if ( F_12 ( V_7 ) & V_162 ) {
F_37 ( V_5 -> V_23 -> V_72 , V_150 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) ,
( V_57 ) V_147 , 0 , F_41 ( V_7 ) ) ;
F_13 ( V_5 -> V_23 ,
L_24 ,
( int ) ( V_150 & V_161 ) ,
F_3 ( V_106 ) ,
F_12 ( V_7 ) ) ;
return;
}
F_11 ( V_7 ) = V_22 ;
F_12 ( V_7 ) |= V_163 ;
F_13 ( V_5 -> V_23 ,
L_25 ,
( int ) ( V_150 & V_161 ) ,
F_3 ( V_106 ) ,
F_12 ( V_7 ) ) ;
if ( V_13 -> V_164 )
F_73 ( V_13 -> V_164 ) ;
}
static void
F_74 ( struct V_5 * V_5 , T_6 V_106 )
{
struct V_165 * V_166 = & V_5 -> V_61 . V_167 ;
F_13 ( V_5 -> V_23 , L_26 ) ;
switch ( V_106 ) {
case V_100 :
break;
case V_108 :
F_31 ( & V_166 -> V_168 ) ;
break;
case V_121 :
F_31 ( & V_166 -> V_122 ) ;
break;
default:
F_31 ( & V_166 -> V_145 ) ;
break;
}
}
static int
F_75 ( struct V_5 * V_5 ,
struct V_146 * V_147 ,
T_2 V_150 ,
T_6 V_106 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
T_2 V_169 = 0 ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
T_2 V_81 = 0 ;
int V_41 = 0 ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
if ( F_12 ( V_7 ) & V_156 ) {
F_43 ( V_69 , V_40 ) ;
return V_41 ;
}
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_65 ( ! V_13 ) ;
if ( ! V_13 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_157 ) ;
F_43 ( V_69 , V_40 ) ;
F_12 ( V_7 ) |= V_170 ;
F_27 ( V_5 -> V_23 ,
L_27 ,
F_3 ( V_106 ) , V_150 , V_7 ,
F_12 ( V_7 ) ) ;
return V_41 ;
}
V_169 = V_150 & ~ ( V_161 ) ;
V_81 = V_13 -> V_81 ;
V_150 &= ( V_161 ) ;
switch ( V_169 ) {
case V_171 :
F_74 ( V_5 , V_106 ) ;
if ( F_11 ( V_7 ) != V_96 ) {
V_41 = - 1 ;
F_43 ( V_69 , V_40 ) ;
break;
}
F_11 ( V_7 ) = V_17 ;
F_76 ( V_7 ) = V_106 ;
F_12 ( V_7 ) |= V_172 ;
F_13 ( V_5 -> V_23 ,
L_28 ,
V_150 ,
F_3 ( V_106 ) ,
F_12 ( V_7 ) ) ;
if ( V_13 -> V_173 ) {
F_73 ( V_13 -> V_173 ) ;
F_43 ( V_69 , V_40 ) ;
break;
}
F_39 ( V_7 ) = NULL ;
V_7 -> V_89 = ( V_116 << 16 ) ;
F_13 ( V_5 -> V_23 ,
L_29 ,
V_7 , F_12 ( V_7 ) ) ;
F_43 ( V_69 , V_40 ) ;
F_8 ( V_5 , V_13 , V_7 ) ;
if ( V_7 -> V_90 ) {
F_37 ( V_5 -> V_23 -> V_72 , V_150 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) ,
( V_57 ) V_147 , F_40 ( V_7 ) ,
F_41 ( V_7 ) ) ;
V_7 -> V_90 ( V_7 ) ;
}
break;
case V_174 :
case V_174 | V_175 :
F_71 ( V_5 , V_147 , V_106 , V_150 , V_7 ) ;
F_43 ( V_69 , V_40 ) ;
V_41 = 0 ;
break;
case V_171 | V_174 :
F_11 ( V_7 ) = V_17 ;
F_76 ( V_7 ) = V_106 ;
F_12 ( V_7 ) |= V_163 ;
F_13 ( V_5 -> V_23 ,
L_30 ,
V_150 , F_3 ( V_106 ) ,
F_12 ( V_7 ) ) ;
if ( V_13 -> V_173 )
F_73 ( V_13 -> V_173 ) ;
F_43 ( V_69 , V_40 ) ;
break;
default:
F_43 ( V_69 , V_40 ) ;
F_27 ( V_5 -> V_23 ,
L_31 , V_169 ) ;
F_27 ( V_5 -> V_23 ,
L_32 ,
F_4 ( F_11 ( V_7 ) ) ,
V_150 ,
F_12 ( V_7 ) ) ;
V_41 = - 1 ;
F_10 ( 1 ) ;
break;
}
return V_41 ;
}
static void
F_77 ( struct V_5 * V_5 , struct V_146 * V_147 )
{
struct V_6 * V_7 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_176 * V_177 = NULL ;
V_57 V_151 ;
T_2 V_150 ;
T_2 V_56 ;
T_6 V_148 ;
T_6 V_149 ;
F_63 ( & V_147 -> V_153 , & V_148 , & V_149 , & V_150 , & V_56 , & V_151 ) ;
F_13 ( V_5 -> V_23 ,
L_33 ,
V_178 , V_148 , V_149 , V_150 , V_56 , V_151 ) ;
V_177 = & V_147 -> V_26 . V_177 ;
F_13 ( V_5 -> V_23 ,
L_34 ,
F_58 ( V_177 -> V_179 ) , V_177 -> V_40 ) ;
if ( V_150 & V_175 ) {
V_13 = (struct V_12 * ) V_151 ;
V_7 = V_13 -> V_7 ;
goto V_180;
}
if ( ( V_150 & V_161 ) >= V_5 -> V_154 ) {
F_27 ( V_5 -> V_23 ,
L_35 ,
V_150 , F_3 ( V_149 ) ) ;
F_10 ( 1 ) ;
return;
}
V_7 = F_64 ( V_5 -> V_23 , V_150 & V_161 ) ;
F_65 ( ! V_7 ) ;
V_180:
if ( ! V_7 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_155 ) ;
F_27 ( V_5 -> V_23 ,
L_36 ,
F_3 ( V_149 ) , V_150 ) ;
return;
}
F_75 ( V_5 , V_147 , V_150 , V_149 , V_7 ) ;
}
static void
F_78 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_181 * V_182 = & V_5 -> V_61 ;
long V_183 = 0 , V_184 = 0 ;
F_13 ( V_5 -> V_23 , L_37 ) ;
F_79 ( V_5 , F_6 ( V_7 ) ) ;
V_183 = F_44 ( & V_182 -> V_62 . V_63 ) ;
F_80 ( V_183 , & V_182 -> V_62 . V_185 ) ;
F_81 ( V_183 , & V_182 -> V_62 . V_63 ) ;
V_184 = F_44 ( & V_182 -> V_118 . V_186 ) ;
F_81 ( V_184 , & V_182 -> V_118 . V_186 ) ;
}
static int
F_82 ( struct V_5 * V_5 , struct V_146 * V_147 )
{
V_57 V_151 ;
T_2 V_150 ;
T_2 V_56 ;
T_6 V_148 ;
T_6 V_149 ;
struct V_6 * V_7 = NULL ;
struct V_12 * V_13 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 , V_187 ;
int V_41 = 0 ;
F_63 ( & V_147 -> V_153 , & V_148 , & V_149 , & V_150 , & V_56 , & V_151 ) ;
F_83 ( V_5 -> V_23 ,
L_38 ,
V_150 , V_151 , F_3 ( V_149 ) ) ;
F_13 ( V_5 -> V_23 ,
L_39 ,
V_148 , V_149 , V_150 , V_56 , V_151 ) ;
if ( V_150 == V_188 ) {
V_13 = (struct V_12 * ) V_151 ;
F_83 ( V_5 -> V_23 ,
L_40 ,
V_150 , V_151 , F_3 ( V_149 ) ) ;
V_7 = V_13 -> V_7 ;
goto V_189;
}
if ( V_150 >= V_5 -> V_154 ) {
F_27 ( V_5 -> V_23 ,
L_41 ,
V_150 , F_3 ( V_149 ) ) ;
F_10 ( 1 ) ;
return 1 ;
}
V_7 = F_64 ( V_5 -> V_23 , V_150 ) ;
V_189:
if ( ! V_7 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_155 ) ;
F_27 ( V_5 -> V_23 ,
L_42 ,
F_3 ( V_149 ) , V_150 ) ;
V_41 = 1 ;
return V_41 ;
}
F_83 ( V_5 -> V_23 ,
L_43 ,
V_7 , V_13 , V_150 , F_12 ( V_7 ) ) ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
if ( ! V_5 -> V_190 ) {
F_43 ( V_69 , V_40 ) ;
F_27 ( V_5 -> V_23 ,
L_44 ) ;
V_41 = 1 ;
return V_41 ;
}
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_65 ( ! V_13 ) ;
if ( ! V_13 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_157 ) ;
F_43 ( V_69 , V_40 ) ;
F_12 ( V_7 ) |= V_170 ;
F_27 ( V_5 -> V_23 ,
L_45 ,
F_3 ( V_149 ) , V_150 , V_7 ,
F_12 ( V_7 ) ) ;
V_41 = 1 ;
return V_41 ;
}
F_43 ( V_69 , V_40 ) ;
F_78 ( V_5 , V_7 ) ;
F_10 ( F_51 ( V_5 ) != V_191 &&
F_51 ( V_5 ) != V_192 ) ;
F_42 ( V_69 , V_40 ) ;
F_42 ( & V_5 -> V_193 , V_187 ) ;
if ( F_51 ( V_5 ) == V_192 )
F_84 ( V_5 , V_91 ) ;
F_43 ( & V_5 -> V_193 , V_187 ) ;
if ( V_5 -> V_190 )
F_73 ( V_5 -> V_190 ) ;
F_43 ( V_69 , V_40 ) ;
F_31 ( & V_5 -> V_61 . V_194 . V_195 ) ;
V_41 = 0 ;
if ( V_5 -> V_55 . V_196 == V_197 )
return V_41 ;
F_13 ( V_5 -> V_23 , L_46 ) ;
F_85 ( V_198 -> V_199 , & V_5 -> V_200 ) ;
return V_41 ;
}
static void
F_86 ( struct V_5 * V_5 , struct V_146 * V_147 )
{
F_83 ( V_5 -> V_23 , L_47 ) ;
F_87 ( 1 ) ;
}
static void
F_88 ( struct V_5 * V_5 , struct V_146 * V_147 )
{
T_6 V_148 , V_149 ;
T_2 V_150 , V_56 ;
V_57 V_151 ;
struct V_201 * V_202 = & V_147 -> V_26 . V_203 ;
T_2 V_204 = 0 ;
F_63 ( & V_147 -> V_153 , & V_148 , & V_149 , & V_150 , & V_56 , & V_151 ) ;
F_13 ( V_5 -> V_23 ,
L_48 ,
V_148 , V_149 , V_150 , V_56 , V_151 ) ;
V_204 = F_58 ( V_202 -> V_205 ) ;
switch ( V_204 ) {
case V_206 :
F_83 ( V_5 -> V_23 , L_49 ) ;
break;
case V_207 :
F_83 ( V_5 -> V_23 , L_50 ) ;
break;
case V_208 :
F_83 ( V_5 -> V_23 , L_51 ) ;
break;
case V_209 :
F_83 ( V_5 -> V_23 , L_52 ) ;
break;
case V_210 :
F_83 ( V_5 -> V_23 , L_53 ) ;
break;
case V_211 :
F_83 ( V_5 -> V_23 , L_54 ) ;
break;
case V_212 :
F_83 ( V_5 -> V_23 , L_55 ) ;
break;
case V_213 :
F_83 ( V_5 -> V_23 , L_56 ) ;
break;
case V_214 :
F_83 ( V_5 -> V_23 , L_57 ) ;
break;
case V_215 :
F_83 ( V_5 -> V_23 , L_58 ) ;
break;
default:
F_83 ( V_5 -> V_23 , L_59 ) ;
F_10 ( 1 ) ;
break;
}
F_87 ( 1 ) ;
}
static int
F_89 ( struct V_216 * V_217 ,
unsigned int V_218 ,
struct V_146 * V_147 )
{
struct V_5 * V_5 = F_90 ( V_217 ) ;
T_5 V_219 = V_80 , V_220 ;
F_91 ( V_178 , ( char * ) V_147 , sizeof( * V_147 ) ) ;
if ( ( V_147 -> V_153 . type >= V_221 ) &&
( V_147 -> V_153 . type <= V_222 ) )
F_33 ( & V_5 -> V_61 . V_118 . V_186 ) ;
F_10 ( ( V_147 -> V_153 . type > V_222 ) &&
( V_147 -> V_153 . type < V_223 ) ) ;
switch ( V_147 -> V_153 . V_224 ) {
case V_129 :
F_27 ( V_5 -> V_23 ,
L_60 ) ;
break;
case V_136 :
F_27 ( V_5 -> V_23 ,
L_61 ) ;
break;
}
switch ( V_147 -> V_153 . type ) {
case V_225 :
F_92 ( V_5 , V_147 ) ;
break;
case V_221 :
F_93 ( V_5 , V_147 ) ;
break;
case V_226 :
F_62 ( V_5 , V_147 ) ;
break;
case V_227 :
F_77 ( V_5 , V_147 ) ;
break;
case V_228 :
F_82 ( V_5 , V_147 ) ;
break;
case V_229 :
F_86 ( V_5 , V_147 ) ;
break;
case V_223 :
F_88 ( V_5 , V_147 ) ;
break;
default:
F_10 ( 1 ) ;
F_13 ( V_5 -> V_23 ,
L_62 ,
V_147 -> V_153 . type ) ;
break;
}
V_220 = V_80 - V_219 ;
if ( V_220 > F_44 ( & V_5 -> V_61 . V_62 . V_230 ) )
F_45 ( & V_5 -> V_61 . V_62 . V_230 , V_220 ) ;
return 0 ;
}
int
F_94 ( struct V_5 * V_5 , int V_231 )
{
unsigned int V_232 = 0 ;
unsigned int V_218 ;
unsigned int V_233 ;
struct V_234 * V_235 = & V_5 -> V_61 . V_87 ;
for ( V_218 = V_5 -> V_236 ; V_218 < V_5 -> V_237 ; V_218 ++ ) {
V_233 = F_95 ( & V_5 -> V_238 [ V_218 ] ,
F_89 ,
V_231 ) ;
V_232 += V_233 ;
if ( V_233 > F_44 ( & V_235 -> V_239 ) )
F_45 ( & V_235 -> V_239 , V_233 ) ;
}
return V_232 ;
}
static int
F_96 ( struct V_5 * V_5 ,
struct V_14 * V_240 ,
struct V_6 * V_7 ,
T_2 V_241 ,
T_2 V_242 )
{
struct V_12 * V_13 = F_97 ( V_240 ) ;
struct V_38 V_39 ;
int V_243 = F_6 ( V_7 ) | V_13 -> V_243 ;
int V_41 = 0 ;
F_10 ( ! V_13 ) ;
F_10 ( ! V_13 -> V_243 ) ;
F_28 ( V_7 -> V_49 -> V_39 , & V_39 ) ;
F_98 ( V_240 ,
V_243 ,
V_5 -> V_55 . V_56 ,
( V_57 ) V_13 ,
0 ,
V_242 ,
V_13 -> V_58 ,
V_39 . V_38 ,
V_241 ) ;
V_41 = F_32 ( V_5 , V_240 , sizeof( * V_240 ) ) ;
if ( V_41 )
F_27 ( V_5 -> V_23 ,
L_63 ,
V_241 , V_7 , V_13 , V_242 , F_6 ( V_7 ) , V_41 ) ;
else
F_13 ( V_5 -> V_23 ,
L_64 ,
V_241 , V_7 , V_13 , V_242 , F_6 ( V_7 ) ) ;
return V_41 ;
}
static int
F_99 ( struct V_5 * V_5 ,
struct V_12 * V_13 ,
struct V_6 * V_7 ,
int V_241 )
{
struct V_14 * V_240 = NULL ;
int V_242 = 0 , V_11 = F_6 ( V_7 ) ;
int V_41 = 0 ;
if ( F_51 ( V_5 ) == V_192 )
return - V_244 ;
F_52 ( & V_5 -> V_93 ) ;
F_13 ( V_5 -> V_23 ,
L_65 ,
V_241 , V_13 , V_11 ) ;
if ( V_241 == V_245 ) {
V_240 = F_100 ( V_5 , V_13 ) ;
V_242 = V_188 ;
} else {
V_240 = F_101 ( V_5 , V_13 ) ;
V_242 = V_11 ;
}
if ( ! V_240 ) {
V_41 = - V_48 ;
goto V_246;
}
V_41 = F_96 ( V_5 , V_240 , V_7 , V_241 , V_242 ) ;
if ( V_41 )
goto V_246;
V_41 = 0 ;
V_246:
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_66 ,
V_241 , V_7 , V_13 , V_242 , V_11 , V_41 ) ;
} else {
F_13 ( V_5 -> V_23 ,
L_67 ,
V_241 , V_7 , V_13 , V_242 , V_11 ) ;
}
F_54 ( & V_5 -> V_93 ) ;
return V_41 ;
}
static int
F_102 ( struct V_5 * V_5 ,
struct V_12 * V_13 ,
struct V_6 * V_7 ,
int V_241 )
{
F_13 ( V_5 -> V_23 , L_68 ,
V_7 , V_13 , F_6 ( V_7 ) , V_241 ) ;
V_13 -> V_243 |= V_171 ;
return F_99 ( V_5 , V_13 , V_7 , V_241 ) ;
}
static int
F_103 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
int V_41 = 0 , V_11 = F_6 ( V_7 ) ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_31 ( & V_5 -> V_61 . V_62 . V_157 ) ;
F_12 ( V_7 ) |= V_170 ;
F_13 ( V_5 -> V_23 ,
L_69 ,
V_11 , V_7 , F_12 ( V_7 ) ) ;
V_41 = V_247 ;
goto V_248;
}
V_13 -> V_173 = NULL ;
V_41 = V_247 ;
switch ( F_76 ( V_7 ) ) {
case V_249 :
F_12 ( V_7 ) |= V_250 ;
F_31 ( & V_5 -> V_61 . V_167 . V_251 ) ;
F_13 ( V_5 -> V_23 ,
L_70 ,
V_7 , F_6 ( V_7 ) , F_12 ( V_7 ) ) ;
V_13 = NULL ;
goto V_248;
case V_100 :
case V_121 :
V_41 = V_252 ;
V_7 -> V_89 = ( V_116 << 16 ) ;
V_7 -> V_90 ( V_7 ) ;
break;
default:
V_41 = V_247 ;
V_13 = NULL ;
break;
}
F_39 ( V_7 ) = NULL ;
F_83 ( V_5 -> V_23 ,
L_71 ,
V_11 , F_3 ( F_76 ( V_7 ) ) ,
F_12 ( V_7 ) ) ;
V_248:
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_8 ( V_5 , V_13 , V_7 ) ;
return V_41 ;
}
static int
F_104 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
enum V_253 V_254 ;
struct V_65 * V_66 = NULL ;
T_1 * V_69 = NULL ;
F_105 ( V_255 ) ;
unsigned long V_40 ;
int V_41 = 0 , V_241 = 0 , V_11 = F_6 ( V_7 ) ;
V_66 = F_48 ( F_49 ( V_7 -> V_49 ) ) ;
if ( ( F_50 ( V_66 ) != 0 ) && ( V_66 -> V_256 . V_148 == V_257 ) )
V_241 = V_258 ;
else
V_241 = V_259 ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_43 ( V_69 , V_40 ) ;
F_27 ( V_5 -> V_23 ,
L_72 ,
V_11 , F_12 ( V_7 ) ) ;
V_41 = V_252 ;
goto V_260;
}
V_13 -> V_173 = & V_255 ;
if ( F_11 ( V_7 ) == V_96 ) {
F_43 ( V_69 , V_40 ) ;
V_41 = 0 ;
goto V_261;
}
F_10 ( ! V_13 -> V_173 ) ;
V_254 = F_11 ( V_7 ) ;
F_11 ( V_7 ) = V_96 ;
F_76 ( V_7 ) = V_249 ;
F_13 ( V_5 -> V_23 , L_73 , V_11 ) ;
F_43 ( V_69 , V_40 ) ;
V_41 = F_102 ( V_5 , V_13 , V_7 , V_241 ) ;
if ( V_41 ) {
F_31 ( & V_5 -> V_61 . V_167 . V_262 ) ;
F_27 ( V_5 -> V_23 ,
L_74 ,
V_11 , V_41 , F_12 ( V_7 ) ) ;
F_42 ( V_69 , V_40 ) ;
F_11 ( V_7 ) = V_254 ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( V_13 )
V_13 -> V_173 = NULL ;
F_43 ( V_69 , V_40 ) ;
V_41 = V_247 ;
goto V_260;
}
F_42 ( V_69 , V_40 ) ;
if ( V_241 == V_259 ) {
F_12 ( V_7 ) |= V_263 ;
F_31 ( & V_5 -> V_61 . V_167 . V_264 ) ;
} else {
F_12 ( V_7 ) |= V_265 ;
}
F_43 ( V_69 , V_40 ) ;
F_13 ( V_5 -> V_23 ,
L_75 ,
V_7 , V_11 , F_12 ( V_7 ) ) ;
V_41 = 0 ;
V_261:
F_106 ( & V_255 , V_266 ) ;
V_260:
return V_41 ;
}
int
F_107 ( struct V_6 * V_7 )
{
struct V_5 * V_5 = F_47 ( V_7 -> V_49 -> V_267 ) ;
int V_41 = V_252 , V_11 = F_6 ( V_7 ) ;
T_2 V_81 = V_80 ;
F_13 ( V_5 -> V_23 , L_76 ,
V_7 , V_7 -> V_59 [ 0 ] , V_7 -> V_268 , V_11 ) ;
if ( F_66 ( F_51 ( V_5 ) != V_91 ) ) {
F_27 ( V_5 -> V_23 ,
L_77 ,
V_11 ) ;
V_41 = V_269 ;
goto V_270;
}
V_41 = F_104 ( V_5 , V_7 ) ;
if ( V_41 )
goto V_270;
V_41 = F_103 ( V_5 , V_7 ) ;
V_270:
F_37 ( V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) , 0 ,
F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
F_13 ( V_5 -> V_23 ,
L_78 ,
( V_41 == V_252 ) ? L_79 :
( ( V_41 == V_269 ) ? L_80 : L_81 ) ) ;
return V_41 ;
}
static int
F_108 ( struct V_5 * V_5 , struct V_6 * V_271 )
{
struct V_12 * V_13 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_272 * V_273 = NULL ;
T_1 * V_69 = NULL ;
T_2 V_11 ;
unsigned long V_40 ;
if ( V_271 )
V_273 = V_271 -> V_49 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_154 ; V_11 ++ ) {
V_69 = F_7 ( V_5 , V_11 ) ;
F_42 ( V_69 , V_40 ) ;
V_7 = F_64 ( V_5 -> V_23 , V_11 ) ;
if ( ! V_7 || ( V_271 && ( V_7 -> V_49 != V_273 || V_7 == V_271 ) ) ) {
F_43 ( V_69 , V_40 ) ;
continue;
}
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_43 ( V_69 , V_40 ) ;
continue;
}
F_13 ( V_5 -> V_23 , L_82 ,
F_4 ( F_11 ( V_7 ) ) ) ;
if ( F_11 ( V_7 ) == V_96 ) {
F_43 ( V_69 , V_40 ) ;
return 1 ;
}
F_43 ( V_69 , V_40 ) ;
}
return 0 ;
}
static int
F_109 ( struct V_5 * V_5 ,
T_2 V_11 ,
struct V_272 * V_273 )
{
struct V_12 * V_13 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_6 * V_7 = NULL ;
T_1 * V_69 = NULL ;
T_2 V_254 = 0 , V_241 = 0 ;
F_105 ( V_255 ) ;
unsigned long V_40 ;
int V_41 = 0 ;
V_69 = F_7 ( V_5 , V_11 ) ;
F_42 ( V_69 , V_40 ) ;
V_7 = F_64 ( V_5 -> V_23 , V_11 ) ;
if ( ! V_7 || V_7 -> V_49 != V_273 )
goto V_274;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 )
goto V_274;
if ( F_11 ( V_7 ) == V_96 )
goto V_274;
if ( ( F_12 ( V_7 ) & V_275 ) &&
( ! ( F_12 ( V_7 ) & V_276 ) ) ) {
F_13 ( V_5 -> V_23 ,
L_83 ,
V_7 ) ;
goto V_274;
}
F_13 ( V_5 -> V_23 ,
L_84 ,
F_4 ( F_11 ( V_7 ) ) ) ;
V_254 = F_11 ( V_7 ) ;
F_11 ( V_7 ) = V_96 ;
F_10 ( V_13 -> V_173 ) ;
if ( F_12 ( V_7 ) & V_275 ) {
V_13 -> V_243 = V_174 ;
F_13 ( V_5 -> V_23 ,
L_85 , V_7 ) ;
}
F_76 ( V_7 ) = V_249 ;
V_13 -> V_173 = & V_255 ;
F_43 ( V_69 , V_40 ) ;
V_66 = F_48 ( F_49 ( V_7 -> V_49 ) ) ;
if ( ( F_50 ( V_66 ) != 0 ) && ( V_66 -> V_256 . V_148 == V_257 ) )
V_241 = V_258 ;
else
V_241 = V_259 ;
V_41 = F_102 ( V_5 , V_13 , V_7 , V_241 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_86 ,
V_7 , V_11 , V_13 -> V_243 , F_12 ( V_7 ) ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( V_13 )
V_13 -> V_173 = NULL ;
if ( F_11 ( V_7 ) == V_96 )
F_11 ( V_7 ) = V_254 ;
V_41 = 1 ;
goto V_274;
}
F_42 ( V_69 , V_40 ) ;
if ( F_12 ( V_7 ) & V_275 )
F_12 ( V_7 ) |= V_20 ;
F_12 ( V_7 ) |= V_19 ;
F_43 ( V_69 , V_40 ) ;
F_106 ( & V_255 , V_266 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_12 ( V_7 ) |= V_170 ;
goto V_274;
}
V_13 -> V_173 = NULL ;
if ( F_76 ( V_7 ) == V_249 ) {
F_27 ( V_5 -> V_23 ,
L_87 ,
V_7 , V_11 , V_13 -> V_243 , F_12 ( V_7 ) ) ;
F_12 ( V_7 ) |= V_172 ;
V_41 = 1 ;
goto V_274;
}
F_11 ( V_7 ) = V_17 ;
F_39 ( V_7 ) = NULL ;
F_43 ( V_69 , V_40 ) ;
F_8 ( V_5 , V_13 , V_7 ) ;
V_7 -> V_89 = ( V_116 << 16 ) ;
V_7 -> V_90 ( V_7 ) ;
V_41 = 0 ;
return V_41 ;
V_274:
F_43 ( V_69 , V_40 ) ;
return V_41 ;
}
static int
F_110 ( struct V_5 * V_5 , struct V_6 * V_271 )
{
struct V_272 * V_273 = V_271 -> V_49 ;
T_2 V_11 = 0 ;
int V_41 = V_247 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_154 ; V_11 ++ ) {
if ( V_11 == F_6 ( V_271 ) )
continue;
V_41 = F_109 ( V_5 , V_11 , V_273 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 , L_88 , V_11 ) ;
goto V_277;
}
}
F_111 ( F_112 ( 100 ) ) ;
if ( F_108 ( V_5 , V_271 ) ) {
V_41 = V_247 ;
goto V_277;
}
V_41 = 0 ;
F_13 ( V_5 -> V_23 , L_89 ) ;
return V_41 ;
V_277:
V_41 = V_247 ;
F_27 ( V_5 -> V_23 ,
L_90 ,
F_113 ( & V_273 -> V_278 ) ) ;
return V_41 ;
}
static int
F_114 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
int V_279 = 0 ;
int V_41 = V_247 ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_43 ( V_69 , V_40 ) ;
F_13 ( V_5 -> V_23 ,
L_91 ,
F_6 ( V_7 ) , V_7 , F_12 ( V_7 ) ) ;
V_41 = V_247 ;
goto V_280;
}
V_13 -> V_164 = NULL ;
V_279 = F_72 ( V_7 ) ;
switch ( V_279 ) {
case V_249 :
F_13 ( V_5 -> V_23 ,
L_92 ,
F_6 ( V_7 ) , F_12 ( V_7 ) ) ;
F_12 ( V_7 ) |= V_162 ;
V_41 = V_247 ;
goto V_281;
case V_100 :
F_13 ( V_5 -> V_23 ,
L_93 ,
F_6 ( V_7 ) ) ;
V_41 = 0 ;
break;
default:
F_27 ( V_5 -> V_23 ,
L_94 ,
F_6 ( V_7 ) ,
F_3 ( V_279 ) , F_12 ( V_7 ) ) ;
V_41 = V_247 ;
goto V_281;
}
F_43 ( V_69 , V_40 ) ;
V_41 = F_110 ( V_5 , V_7 ) ;
if ( V_41 ) {
F_42 ( V_69 , V_40 ) ;
F_13 ( V_5 -> V_23 ,
L_95 ,
F_6 ( V_7 ) ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
goto V_281;
} else {
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( V_13 )
V_41 = V_252 ;
else
V_41 = V_247 ;
}
V_281:
F_10 ( ! F_115 ( V_69 ) ) ;
if ( V_13 )
F_39 ( V_7 ) = NULL ;
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_8 ( V_5 , V_13 , V_7 ) ;
V_280:
return V_41 ;
}
static int
F_116 ( struct V_5 * V_5 ,
struct V_12 * V_13 ,
struct V_6 * V_7 )
{
V_13 -> V_243 |= V_174 ;
return F_99 ( V_5 , V_13 , V_7 , V_245 ) ;
}
static int
F_117 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
enum V_253 V_254 ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
F_105 ( V_255 ) ;
int V_41 = V_247 , V_11 = F_6 ( V_7 ) ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
F_12 ( V_7 ) |= V_275 ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_27 ( V_5 -> V_23 ,
L_96 ,
V_11 , F_12 ( V_7 ) ) ;
F_43 ( V_69 , V_40 ) ;
V_41 = V_247 ;
goto V_282;
}
V_254 = F_11 ( V_7 ) ;
F_11 ( V_7 ) = V_98 ;
F_72 ( V_7 ) = V_249 ;
F_13 ( V_5 -> V_23 , L_97 , V_11 ) ;
V_13 -> V_164 = & V_255 ;
F_10 ( ! V_13 -> V_164 ) ;
F_43 ( V_69 , V_40 ) ;
V_41 = F_116 ( V_5 , V_13 , V_7 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_98 ,
V_11 , V_41 , F_12 ( V_7 ) ) ;
F_42 ( V_69 , V_40 ) ;
F_11 ( V_7 ) = V_254 ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( V_13 )
V_13 -> V_164 = NULL ;
F_43 ( V_69 , V_40 ) ;
V_41 = V_247 ;
goto V_282;
}
F_42 ( V_69 , V_40 ) ;
F_12 ( V_7 ) |= V_276 ;
F_43 ( V_69 , V_40 ) ;
V_41 = 0 ;
F_106 ( & V_255 , V_283 ) ;
V_282:
return V_41 ;
}
static int
F_118 ( struct V_272 * V_284 )
{
struct V_65 * V_66 = F_48 ( F_49 ( V_284 ) ) ;
if ( V_66 -> V_256 . V_148 == V_285 )
return 0 ;
return 1 ;
}
static void
F_119 ( struct V_5 * V_5 , struct V_6 * V_7 , int V_286 )
{
struct V_12 * V_13 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
T_2 V_81 = V_80 ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( V_13 ) {
V_81 = V_13 -> V_81 ;
F_39 ( V_7 ) = NULL ;
}
F_12 ( V_7 ) |= V_286 ;
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_8 ( V_5 , V_13 , V_7 ) ;
F_37 ( V_5 -> V_23 -> V_72 , F_6 ( V_7 ) , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) , ( V_57 ) V_13 ,
F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
}
int
F_120 ( struct V_6 * V_7 )
{
struct V_86 * V_23 = V_7 -> V_49 -> V_267 ;
struct V_5 * V_5 = F_47 ( V_23 ) ;
struct V_12 * V_13 = NULL ;
int V_11 = F_6 ( V_7 ) ;
int V_81 = V_80 ;
int V_41 = V_247 ;
int V_287 = 0 ;
F_13 ( V_23 , L_99 ,
V_7 , V_7 -> V_59 [ 0 ] , V_7 -> V_268 ,
F_6 ( V_7 ) ) ;
V_287 = F_118 ( V_7 -> V_49 ) ;
if ( ! V_287 ) {
F_83 ( V_23 , L_100 ) ;
F_119 ( V_5 , V_7 , V_18 ) ;
goto V_288;
}
if ( F_66 ( F_51 ( V_5 ) != V_91 ) ) {
F_119 ( V_5 , V_7 , 0 ) ;
F_27 ( V_23 , L_101 ) ;
goto V_288;
}
if ( F_66 ( V_11 <= V_289 ) ) {
F_83 ( V_5 -> V_23 ,
L_102 ) ;
V_13 = F_38 ( V_5 , 0 ) ;
if ( ! V_13 )
goto V_288;
memset ( F_53 ( V_7 ) , 0 ,
sizeof( struct V_94 ) ) ;
F_39 ( V_7 ) = ( char * ) V_13 ;
F_12 ( V_7 ) = V_71 ;
V_13 -> V_243 = V_175 ;
V_13 -> V_7 = V_7 ;
}
V_41 = F_117 ( V_5 , V_7 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_103 ,
V_11 , V_41 ) ;
F_119 ( V_5 , V_7 , 0 ) ;
goto V_288;
}
V_41 = F_114 ( V_5 , V_7 ) ;
V_288:
F_37 ( V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) ,
0 , F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
F_13 ( V_5 -> V_23 ,
L_104 ,
( V_41 == V_252 ) ? L_79 : L_81 ) ;
return V_41 ;
}
static int
F_121 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 = NULL ;
T_1 * V_69 = NULL ;
F_105 ( V_290 ) ;
unsigned long V_40 ;
int V_41 = - V_48 ;
V_13 = F_38 ( V_5 , 0 ) ;
if ( ! V_13 ) {
V_41 = - V_48 ;
goto V_291;
}
if ( F_6 ( V_7 ) == V_188 ) {
memset ( F_53 ( V_7 ) , 0 ,
sizeof( struct V_94 ) ) ;
F_83 ( V_5 -> V_23 , L_105 ) ;
V_13 -> V_7 = V_7 ;
}
V_15 = F_9 ( V_13 ) ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
F_10 ( F_39 ( V_7 ) != NULL ) ;
F_11 ( V_7 ) = V_75 ;
F_39 ( V_7 ) = ( char * ) V_13 ;
F_12 ( V_7 ) |= V_76 ;
V_5 -> V_190 = & V_290 ;
F_43 ( V_69 , V_40 ) ;
F_122 ( & V_15 -> V_153 , V_292 , 0 , F_6 ( V_7 ) ,
V_5 -> V_55 . V_56 , 0 , ( V_57 ) V_13 ) ;
V_15 -> V_26 . V_194 . V_40 = 0 ;
V_41 = F_32 ( V_5 , V_15 , sizeof( * V_15 ) ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_106 ,
V_41 ) ;
goto V_293;
}
F_42 ( V_69 , V_40 ) ;
F_12 ( V_7 ) |= V_294 ;
F_43 ( V_69 , V_40 ) ;
F_31 ( & V_5 -> V_61 . V_194 . V_295 ) ;
F_83 ( V_5 -> V_23 , L_107 ) ;
F_106 ( V_5 -> V_190 ,
V_296 ) ;
if ( F_51 ( V_5 ) == V_192 ) {
F_27 ( V_5 -> V_23 , L_108 ) ;
V_41 = - V_297 ;
goto V_293;
}
F_42 ( V_69 , V_40 ) ;
V_5 -> V_190 = NULL ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_39 ( V_7 ) = NULL ;
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_17 ( V_5 , V_13 ) ;
V_41 = 0 ;
return V_41 ;
V_293:
F_42 ( V_69 , V_40 ) ;
V_5 -> V_190 = NULL ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
F_39 ( V_7 ) = NULL ;
F_43 ( V_69 , V_40 ) ;
if ( V_13 )
F_17 ( V_5 , V_13 ) ;
V_291:
F_27 ( V_5 -> V_23 ,
L_109 ,
V_41 ) ;
return V_41 ;
}
int
F_123 ( struct V_86 * V_23 , struct V_6 * V_7 )
{
struct V_5 * V_5 = F_47 ( V_23 ) ;
enum V_298 V_254 ;
unsigned long V_40 ;
int V_41 = V_247 ;
V_254 = F_51 ( V_5 ) ;
F_42 ( & V_5 -> V_193 , V_40 ) ;
if ( F_51 ( V_5 ) == V_192 ) {
F_43 ( & V_5 -> V_193 , V_40 ) ;
F_83 ( V_23 , L_110 ) ;
F_124 ( V_296 ) ;
V_41 = V_252 ;
goto V_299;
}
F_84 ( V_5 , V_192 ) ;
F_43 ( & V_5 -> V_193 , V_40 ) ;
while ( F_125 ( & V_5 -> V_93 ) )
F_111 ( F_112 ( 1 ) ) ;
V_41 = F_121 ( V_5 , V_7 ) ;
if ( V_41 ) {
F_27 ( V_23 ,
L_111 ,
V_41 ) ;
F_42 ( & V_5 -> V_193 , V_40 ) ;
F_84 ( V_5 , V_254 ) ;
F_43 ( & V_5 -> V_193 , V_40 ) ;
F_31 ( & V_5 -> V_61 . V_194 . V_300 ) ;
V_41 = V_247 ;
goto V_299;
}
V_41 = V_252 ;
V_299:
return V_41 ;
}
int
F_126 ( struct V_6 * V_7 )
{
struct V_86 * V_23 = V_7 -> V_49 -> V_267 ;
T_2 V_81 = V_80 ;
int V_41 = V_247 ;
F_13 ( V_23 ,
L_112 ,
V_7 , V_7 -> V_59 [ 0 ] , V_7 -> V_268 ,
F_6 ( V_7 ) , F_12 ( V_7 ) ) ;
V_41 = F_123 ( V_23 , V_7 ) ;
F_37 ( V_23 -> V_72 , F_6 ( V_7 ) , ( V_57 ) V_7 ,
F_68 ( V_80 - V_81 ) ,
0 , F_40 ( V_7 ) , F_41 ( V_7 ) ) ;
return V_41 ;
}
static void
F_127 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
F_13 ( V_5 -> V_23 ,
L_113 ,
V_7 , F_3 ( F_11 ( V_7 ) ) , F_12 ( V_7 ) ) ;
F_76 ( V_7 ) = V_100 ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 )
return;
if ( V_13 -> V_164 )
F_73 ( V_13 -> V_164 ) ;
else if ( V_13 -> V_173 )
F_73 ( V_13 -> V_173 ) ;
}
static void
F_79 ( struct V_5 * V_5 , int V_301 )
{
struct V_12 * V_13 = NULL ;
struct V_6 * V_7 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
int V_11 ;
T_5 V_302 = 0 ;
F_13 ( V_5 -> V_23 , L_114 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_154 ; V_11 ++ ) {
if ( V_11 == V_301 )
continue;
V_69 = F_7 ( V_5 , V_11 ) ;
F_42 ( V_69 , V_40 ) ;
V_7 = F_64 ( V_5 -> V_23 , V_11 ) ;
if ( ! V_7 ) {
F_43 ( V_69 , V_40 ) ;
continue;
}
if ( F_66 ( F_59 ( V_7 ) ) ) {
F_127 ( V_5 , V_7 ) ;
F_43 ( V_69 , V_40 ) ;
continue;
}
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 ) {
F_43 ( V_69 , V_40 ) ;
goto V_303;
}
F_13 ( V_5 -> V_23 ,
L_115 ,
V_7 , V_13 , V_11 , F_12 ( V_7 ) ) ;
F_39 ( V_7 ) = NULL ;
F_12 ( V_7 ) |= V_21 ;
F_43 ( V_69 , V_40 ) ;
V_302 = V_13 -> V_81 ;
F_83 ( V_5 -> V_23 ,
L_116 ,
V_13 , F_12 ( V_7 ) ) ;
F_8 ( V_5 , V_13 , V_7 ) ;
V_303:
V_7 -> V_89 = V_304 << 16 ;
F_83 ( V_5 -> V_23 ,
L_117 ,
V_7 , V_7 -> V_268 -> V_11 , F_12 ( V_7 ) , V_13 ,
F_68 ( V_80 - V_302 ) ) ;
F_67 ( & V_5 -> V_61 ) ;
if ( V_7 -> V_90 ) {
F_37 ( V_5 -> V_23 -> V_72 , V_11 , ( V_57 ) V_7 ,
F_68 ( V_80 - V_302 ) , 0 ,
F_40 ( V_7 ) ,
F_41 ( V_7 ) ) ;
V_7 -> V_90 ( V_7 ) ;
}
}
}
void
F_128 ( struct V_5 * V_5 )
{
F_83 ( V_5 -> V_23 , L_118 ) ;
F_79 ( V_5 , V_188 ) ;
}
static int
F_129 ( struct V_5 * V_5 , struct V_6 * V_7 , int V_241 )
{
struct V_12 * V_13 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
T_2 V_254 = 0 ;
int V_41 = 0 ;
V_69 = F_5 ( V_5 , V_7 ) ;
F_42 ( V_69 , V_40 ) ;
V_13 = (struct V_12 * ) F_39 ( V_7 ) ;
if ( ! V_13 )
goto V_305;
if ( F_11 ( V_7 ) == V_96 )
goto V_305;
if ( ( F_12 ( V_7 ) & V_275 ) &&
( ! ( F_12 ( V_7 ) & V_276 ) ) ) {
F_13 ( V_5 -> V_23 ,
L_119 ,
V_7 ) ;
goto V_305;
}
if ( ! ( F_12 ( V_7 ) & V_77 ) ) {
F_13 ( V_5 -> V_23 ,
L_120 ,
V_7 , F_6 ( V_7 ) , F_12 ( V_7 ) , F_11 ( V_7 ) ) ;
goto V_305;
}
V_254 = F_11 ( V_7 ) ;
F_11 ( V_7 ) = V_96 ;
F_76 ( V_7 ) = V_249 ;
F_12 ( V_7 ) |= V_306 ;
if ( F_12 ( V_7 ) & V_275 ) {
V_13 -> V_243 = V_174 ;
F_13 ( V_5 -> V_23 , L_121 , V_7 ) ;
}
F_13 ( V_5 -> V_23 , L_122 ,
F_6 ( V_7 ) ) ;
F_10 ( V_13 -> V_173 ) ;
F_43 ( V_69 , V_40 ) ;
V_41 = F_102 ( V_5 , V_13 , V_7 , V_241 ) ;
if ( V_41 ) {
F_27 ( V_5 -> V_23 ,
L_123 ,
F_6 ( V_7 ) , V_41 ) ;
F_42 ( V_69 , V_40 ) ;
if ( F_11 ( V_7 ) == V_96 )
F_11 ( V_7 ) = V_254 ;
goto V_305;
}
F_42 ( V_69 , V_40 ) ;
if ( F_12 ( V_7 ) & V_275 )
F_12 ( V_7 ) |= V_20 ;
else
F_12 ( V_7 ) |= V_19 ;
V_41 = V_252 ;
V_305:
F_10 ( ! F_115 ( V_69 ) ) ;
F_43 ( V_69 , V_40 ) ;
return V_41 ;
}
int
F_130 ( struct V_65 * V_66 )
{
struct V_5 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_65 * V_307 = NULL ;
T_1 * V_69 = NULL ;
unsigned long V_40 ;
int V_41 = 0 , V_11 , V_308 = 0 , V_241 = 0 ;
if ( ! V_66 )
return - 1 ;
V_5 = F_47 ( F_131 ( V_66 ) ) ;
F_13 ( V_5 -> V_23 , L_124 ) ;
if ( V_66 -> V_256 . V_148 == V_285 )
V_241 = V_259 ;
else
V_241 = V_258 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_154 ; V_11 ++ ) {
V_69 = F_7 ( V_5 , V_11 ) ;
F_42 ( V_69 , V_40 ) ;
V_7 = F_64 ( V_5 -> V_23 , V_11 ) ;
if ( ! V_7 ) {
F_43 ( V_69 , V_40 ) ;
continue;
}
V_307 = F_48 ( F_49 ( V_7 -> V_49 ) ) ;
if ( V_307 != V_66 ) {
F_43 ( V_69 , V_40 ) ;
continue;
}
F_43 ( V_69 , V_40 ) ;
V_41 = F_129 ( V_5 , V_7 , V_241 ) ;
if ( V_41 < 0 ) {
F_27 ( V_5 -> V_23 ,
L_125 ,
V_11 , V_41 ) ;
continue;
}
if ( V_41 == V_252 )
V_308 ++ ;
}
F_13 ( V_5 -> V_23 , L_126 , V_308 ) ;
return 0 ;
}
