static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline unsigned F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static inline void F_5 ( T_1 * * V_10 , unsigned V_11 , unsigned V_12 )
{
switch ( V_11 ) {
case 1 :
F_6 ( ( V_13 ) V_12 , * V_10 ) ;
break;
case 2 :
F_7 ( ( V_14 ) V_12 , * V_10 ) ;
break;
default:
F_8 () ;
}
* V_10 += V_11 ;
}
static inline unsigned F_9 ( T_1 * * V_10 , unsigned V_11 )
{
unsigned V_15 ;
switch ( V_11 ) {
case 1 :
V_15 = F_10 ( * V_10 ) ;
break;
case 2 :
V_15 = F_11 ( * V_10 ) ;
break;
default:
F_8 () ;
}
* V_10 += V_11 ;
return V_15 ;
}
static inline void F_12 ( struct V_1 * V_16 )
{
V_16 -> V_17 = & V_18 ;
V_16 -> V_19 = false ;
V_16 -> V_4 . V_20 = V_21 ;
V_16 -> V_4 . V_22 = 0 ;
V_16 -> V_4 . V_23 = F_13 ( V_24 . V_25 ) ;
V_16 -> V_4 . V_26 = V_27 ;
}
static void F_14 ( struct V_1 * V_16 )
{
struct V_28 * V_29 = V_16 -> V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = V_16 -> V_4 . V_5 . V_35 -> V_34 ;
T_2 * V_36 ;
int V_37 ;
if ( ! V_29 )
return;
V_32 = V_29 -> V_38 ;
switch ( V_16 -> V_39 ) {
case V_40 :
return;
case V_41 :
V_32 -> V_42 = V_43 ;
if ( V_16 -> V_44 )
V_32 -> V_45 = F_15 ( 1 ) ;
else
V_32 -> V_45 = F_15 ( 0 ) ;
V_32 -> V_46 = 0 ;
V_29 -> V_47 = sizeof *V_32 ;
F_16 ( V_34 , L_1 ,
V_16 -> V_44 ? L_2 : L_3 ) ;
V_16 -> V_39 = V_40 ;
break;
case V_48 :
V_32 -> V_42 = V_49 ;
V_32 -> V_45 = F_15 ( 0 ) ;
V_32 -> V_46 = F_15 ( 8 ) ;
V_29 -> V_47 = V_50 ;
V_36 = V_29 -> V_38 + sizeof *V_32 ;
V_36 [ 0 ] = F_17 ( F_3 ( V_34 -> V_51 ) ) ;
V_36 [ 1 ] = V_36 [ 0 ] ;
F_16 ( V_34 , L_4 , F_3 ( V_34 -> V_51 ) ) ;
V_16 -> V_39 = V_41 ;
break;
}
V_32 -> V_52 = 0xA1 ;
V_32 -> V_53 = F_15 ( V_16 -> V_54 ) ;
V_16 -> V_30 = NULL ;
F_18 ( & V_16 -> V_55 ) ;
V_37 = F_19 ( V_16 -> V_56 , V_29 , V_57 ) ;
F_20 ( & V_16 -> V_55 ) ;
if ( V_37 < 0 ) {
V_16 -> V_30 = V_29 ;
F_16 ( V_34 , L_5 , V_37 ) ;
}
}
static void F_21 ( struct V_1 * V_16 )
{
V_16 -> V_39 = V_48 ;
F_14 ( V_16 ) ;
}
static void F_22 ( struct V_58 * V_59 , struct V_28 * V_29 )
{
struct V_1 * V_16 = V_29 -> V_60 ;
struct V_33 * V_34 = V_16 -> V_4 . V_5 . V_35 -> V_34 ;
struct V_31 * V_32 = V_29 -> V_38 ;
F_20 ( & V_16 -> V_55 ) ;
switch ( V_29 -> V_37 ) {
case 0 :
F_23 ( V_34 , L_6 ,
V_32 -> V_42 ) ;
break;
case - V_61 :
case - V_62 :
V_16 -> V_39 = V_40 ;
break;
default:
F_16 ( V_34 , L_7 ,
V_32 -> V_42 , V_29 -> V_37 ) ;
break;
}
V_16 -> V_30 = V_29 ;
F_14 ( V_16 ) ;
F_18 ( & V_16 -> V_55 ) ;
}
static void F_24 ( struct V_58 * V_59 , struct V_28 * V_29 )
{
unsigned V_63 ;
struct V_2 * V_3 = V_29 -> V_60 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_33 * V_34 = V_59 -> V_64 ;
V_29 -> V_60 = NULL ;
if ( V_29 -> V_37 || V_29 -> V_65 != V_29 -> V_47 ) {
F_16 ( V_34 , L_8 ) ;
goto V_66;
}
V_63 = F_11 ( V_29 -> V_38 ) ;
if ( V_63 < V_67 ||
V_63 > F_13 ( V_24 . V_68 ) ) {
F_16 ( V_34 , L_9 , V_63 ) ;
goto V_66;
}
V_16 -> V_4 . V_26 = V_63 ;
F_23 ( V_34 , L_10 , V_63 ) ;
return;
V_66:
F_25 ( V_59 ) ;
return;
}
static int F_26 ( struct V_2 * V_3 , const struct V_69 * V_70 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_33 * V_34 = V_3 -> V_35 -> V_34 ;
struct V_28 * V_29 = V_34 -> V_29 ;
int V_71 = - V_72 ;
V_13 V_73 = F_27 ( V_70 -> V_53 ) ;
V_13 V_74 = F_27 ( V_70 -> V_45 ) ;
V_13 V_75 = F_27 ( V_70 -> V_46 ) ;
switch ( ( V_70 -> V_76 << 8 ) | V_70 -> V_77 ) {
case ( ( V_78 | V_79 | V_80 ) << 8 )
| V_81 :
if ( V_75 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
F_16 ( V_34 , L_11 , V_74 ) ;
V_16 -> V_4 . V_20 = V_74 ;
V_71 = 0 ;
break;
case ( ( V_82 | V_79 | V_80 ) << 8 )
| V_83 :
if ( V_75 == 0 || V_74 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
V_71 = V_75 > sizeof V_24 ?
sizeof V_24 : V_75 ;
memcpy ( V_29 -> V_38 , & V_24 , V_71 ) ;
F_23 ( V_34 , L_12 ) ;
break;
case ( ( V_82 | V_79 | V_80 ) << 8 )
| V_84 :
if ( V_75 < 4 || V_74 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
F_7 ( V_16 -> V_4 . V_26 , V_29 -> V_38 ) ;
V_71 = 4 ;
F_23 ( V_34 , L_13 ,
V_16 -> V_4 . V_26 ) ;
break;
case ( ( V_78 | V_79 | V_80 ) << 8 )
| V_85 :
{
if ( V_75 != 4 || V_74 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
V_29 -> V_86 = F_24 ;
V_29 -> V_47 = V_75 ;
V_29 -> V_60 = V_3 ;
V_71 = V_29 -> V_47 ;
break;
}
case ( ( V_82 | V_79 | V_80 ) << 8 )
| V_87 :
{
T_3 V_88 ;
if ( V_75 < 2 || V_74 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
V_88 = ( V_16 -> V_17 == & V_18 ) ? 0x0000 : 0x0001 ;
F_6 ( V_88 , V_29 -> V_38 ) ;
V_71 = 2 ;
F_23 ( V_34 , L_14 , V_88 ) ;
break;
}
case ( ( V_78 | V_79 | V_80 ) << 8 )
| V_89 :
{
if ( V_75 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
switch ( V_74 ) {
case 0x0000 :
V_16 -> V_17 = & V_18 ;
F_16 ( V_34 , L_15 ) ;
break;
case 0x0001 :
V_16 -> V_17 = & V_90 ;
F_16 ( V_34 , L_16 ) ;
break;
default:
goto V_66;
}
V_71 = 0 ;
break;
}
case ( ( V_82 | V_79 | V_80 ) << 8 )
| V_91 :
{
T_3 V_19 ;
if ( V_75 < 2 || V_74 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
V_19 = V_16 -> V_19 ? 0x0001 : 0x0000 ;
F_6 ( V_19 , V_29 -> V_38 ) ;
V_71 = 2 ;
F_23 ( V_34 , L_17 , V_19 ) ;
break;
}
case ( ( V_78 | V_79 | V_80 ) << 8 )
| V_92 :
{
int V_93 = 0 ;
if ( V_75 != 0 || V_73 != V_16 -> V_54 )
goto V_66;
switch ( V_74 ) {
case 0x0000 :
V_16 -> V_19 = false ;
V_93 = V_94 ;
F_16 ( V_34 , L_18 ) ;
break;
case 0x0001 :
V_16 -> V_19 = true ;
V_93 = V_95 ;
F_16 ( V_34 , L_19 ) ;
break;
default:
goto V_66;
}
V_16 -> V_17 -> V_96 &= ~ V_97 ;
V_16 -> V_17 -> V_96 |= V_93 ;
V_71 = 0 ;
break;
}
default:
V_66:
F_16 ( V_34 , L_20 ,
V_70 -> V_76 , V_70 -> V_77 ,
V_74 , V_73 , V_75 ) ;
}
if ( V_71 >= 0 ) {
F_16 ( V_34 , L_21 ,
V_70 -> V_76 , V_70 -> V_77 ,
V_74 , V_73 , V_75 ) ;
V_29 -> V_98 = 0 ;
V_29 -> V_47 = V_71 ;
V_71 = F_19 ( V_34 -> V_51 -> V_99 , V_29 , V_57 ) ;
if ( V_71 < 0 )
ERROR ( V_34 , L_22 ,
V_70 -> V_76 , V_70 -> V_77 ,
V_71 ) ;
}
return V_71 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned V_100 , unsigned V_101 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_33 * V_34 = V_3 -> V_35 -> V_34 ;
if ( V_100 == V_16 -> V_54 ) {
if ( V_101 != 0 )
goto V_102;
if ( V_16 -> V_56 -> V_64 ) {
F_16 ( V_34 , L_23 , V_100 ) ;
F_29 ( V_16 -> V_56 ) ;
}
if ( ! ( V_16 -> V_56 -> V_103 ) ) {
F_16 ( V_34 , L_24 , V_100 ) ;
if ( F_30 ( V_34 -> V_51 , V_3 , V_16 -> V_56 ) )
goto V_102;
}
F_31 ( V_16 -> V_56 ) ;
V_16 -> V_56 -> V_64 = V_16 ;
} else if ( V_100 == V_16 -> V_104 ) {
if ( V_101 > 1 )
goto V_102;
if ( V_16 -> V_4 . V_105 -> V_64 ) {
F_16 ( V_34 , L_25 ) ;
F_32 ( & V_16 -> V_4 ) ;
F_12 ( V_16 ) ;
}
if ( V_101 == 1 ) {
struct V_106 * V_107 ;
if ( ! V_16 -> V_4 . V_105 -> V_103 ||
! V_16 -> V_4 . V_108 -> V_103 ) {
F_16 ( V_34 , L_26 ) ;
if ( F_30 ( V_34 -> V_51 , V_3 ,
V_16 -> V_4 . V_105 ) ||
F_30 ( V_34 -> V_51 , V_3 ,
V_16 -> V_4 . V_108 ) ) {
V_16 -> V_4 . V_105 -> V_103 = NULL ;
V_16 -> V_4 . V_108 -> V_103 = NULL ;
goto V_102;
}
}
V_16 -> V_4 . V_109 = ! (
F_33 ( V_34 -> V_51 )
) ;
V_16 -> V_4 . V_20 = V_21 ;
F_16 ( V_34 , L_27 ) ;
V_107 = F_34 ( & V_16 -> V_4 ) ;
if ( F_35 ( V_107 ) )
return F_36 ( V_107 ) ;
}
F_20 ( & V_16 -> V_55 ) ;
F_21 ( V_16 ) ;
F_18 ( & V_16 -> V_55 ) ;
} else
goto V_102;
return 0 ;
V_102:
return - V_110 ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_100 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_100 == V_16 -> V_54 )
return 0 ;
return V_16 -> V_4 . V_105 -> V_64 ? 1 : 0 ;
}
static struct V_111 * F_38 ( struct V_112 * V_4 ,
struct V_111 * V_113 )
{
struct V_1 * V_16 = F_1 ( & V_4 -> V_5 ) ;
struct V_111 * V_114 ;
int V_115 = 0 ;
T_1 * V_15 ;
int div = V_24 . V_116 ;
int V_117 = V_24 . V_118 ;
int V_119 ;
int V_120 = V_24 . V_121 ;
int V_122 ;
unsigned V_123 = V_16 -> V_4 . V_26 ;
struct V_124 * V_125 = V_16 -> V_17 ;
unsigned V_126 = V_16 -> V_19 ? sizeof( V_127 ) : 0 ;
V_115 += V_125 -> V_128 ;
V_122 = F_39 ( V_115 , V_120 ) - V_115 ;
V_115 += V_122 ;
V_115 += V_125 -> V_129 ;
V_115 += 2 * 2 * V_125 -> V_130 ;
V_115 += 2 * 2 * V_125 -> V_130 ;
V_119 = F_39 ( V_115 , div ) + V_117 - V_115 ;
V_115 += V_119 ;
if ( V_115 + V_113 -> V_131 + V_126 > V_123 ) {
F_40 ( V_113 ) ;
return NULL ;
}
V_114 = F_41 ( V_113 , V_115 ,
V_123 - V_113 -> V_131 - V_115 - V_126 ,
V_57 ) ;
F_40 ( V_113 ) ;
if ( ! V_114 )
return NULL ;
V_113 = V_114 ;
V_15 = ( void * ) F_42 ( V_113 , V_115 ) ;
memset ( V_15 , 0 , V_115 ) ;
F_7 ( V_125 -> V_132 , V_15 ) ;
V_15 += 2 ;
F_6 ( V_125 -> V_128 , V_15 ++ ) ;
V_15 ++ ;
F_5 ( & V_15 , V_125 -> V_133 , V_113 -> V_131 ) ;
F_5 ( & V_15 , V_125 -> V_134 , V_125 -> V_128 + V_122 ) ;
V_15 = ( void * ) V_15 + V_122 ;
F_7 ( V_125 -> V_96 , V_15 ) ;
V_15 += 2 ;
F_6 ( V_115 - V_125 -> V_128 - V_119 , V_15 ++ ) ;
V_15 += V_125 -> V_135 ;
V_15 += V_125 -> V_136 ;
V_15 += V_125 -> V_137 ;
if ( V_16 -> V_19 ) {
V_127 V_138 ;
V_138 = ~ F_43 ( ~ 0 ,
V_113 -> V_36 + V_115 ,
V_113 -> V_131 - V_115 ) ;
F_7 ( V_138 , V_113 -> V_36 + V_113 -> V_131 ) ;
F_44 ( V_113 , V_126 ) ;
}
F_5 ( & V_15 , V_125 -> V_130 , V_115 ) ;
F_5 ( & V_15 , V_125 -> V_130 , V_113 -> V_131 - V_115 ) ;
if ( V_113 -> V_131 > V_139 )
memset ( F_44 ( V_113 , V_123 - V_113 -> V_131 ) ,
0 , V_123 - V_113 -> V_131 ) ;
return V_113 ;
}
static int F_45 ( struct V_112 * V_4 ,
struct V_111 * V_113 ,
struct V_140 * V_141 )
{
struct V_1 * V_16 = F_1 ( & V_4 -> V_5 ) ;
T_1 * V_15 = ( void * ) V_113 -> V_36 ;
unsigned V_142 , V_143 ;
unsigned V_144 , V_145 ;
unsigned V_146 ;
struct V_111 * V_114 ;
int V_147 = - V_110 ;
unsigned V_123 = F_13 ( V_24 . V_25 ) ;
struct V_124 * V_125 = V_16 -> V_17 ;
unsigned V_126 = V_16 -> V_19 ? sizeof( V_127 ) : 0 ;
int V_148 ;
if ( F_11 ( V_15 ) != V_125 -> V_132 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_28 ,
V_113 -> V_131 ) ;
F_47 ( V_149 , L_29 , V_150 , 32 , 1 ,
V_113 -> V_36 , 32 , false ) ;
goto V_151;
}
V_15 += 2 ;
if ( F_10 ( V_15 ++ ) != V_125 -> V_128 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_30 ) ;
goto V_151;
}
V_15 ++ ;
if ( F_9 ( & V_15 , V_125 -> V_133 ) > V_123 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_31 ) ;
goto V_151;
}
V_142 = F_9 ( & V_15 , V_125 -> V_134 ) ;
if ( ( ( V_142 % 4 ) != 0 ) && ( V_142 < V_125 -> V_128 ) ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_32 ,
V_142 ) ;
goto V_151;
}
V_15 = ( ( void * ) V_113 -> V_36 ) + V_142 ;
if ( F_11 ( V_15 ) != V_125 -> V_96 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_33 ) ;
goto V_151;
}
V_15 += 2 ;
V_146 = F_10 ( V_15 ++ ) ;
if ( ( V_146 < V_125 -> V_129 + 2 * 2 * ( V_125 -> V_130 * 2 ) )
|| ( V_146 % V_125 -> V_152 != 0 ) ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_34 , V_146 ) ;
goto V_151;
}
V_15 += V_125 -> V_135 ;
V_15 += V_125 -> V_136 ;
V_15 += V_125 -> V_137 ;
V_146 -= V_125 -> V_129 ;
V_143 = F_9 ( & V_15 , V_125 -> V_130 ) ;
V_145 = F_9 ( & V_15 , V_125 -> V_130 ) ;
V_148 = 0 ;
do {
V_142 = V_143 ;
V_144 = V_145 ;
if ( V_144 < 14 + V_126 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_35 ,
V_144 ) ;
goto V_151;
}
if ( V_16 -> V_19 ) {
V_127 V_138 , V_153 ;
V_138 = F_11 ( V_113 -> V_36 +
V_142 + V_144 - V_126 ) ;
V_153 = ~ F_43 ( ~ 0 ,
V_113 -> V_36 + V_142 ,
V_144 - V_126 ) ;
if ( V_138 != V_153 ) {
F_46 ( V_4 -> V_5 . V_35 -> V_34 , L_36 ) ;
goto V_151;
}
}
V_143 = F_9 ( & V_15 , V_125 -> V_130 ) ;
V_145 = F_9 ( & V_15 , V_125 -> V_130 ) ;
if ( V_143 == 0 || V_145 == 0 ) {
V_114 = V_113 ;
} else {
V_114 = F_48 ( V_113 , V_57 ) ;
if ( V_114 == NULL )
goto V_151;
}
if ( ! F_49 ( V_114 , V_142 ) ) {
V_147 = - V_154 ;
goto V_151;
}
F_50 ( V_114 , V_144 - V_126 ) ;
F_51 ( V_141 , V_114 ) ;
V_146 -= 2 * ( V_125 -> V_130 * 2 ) ;
V_148 ++ ;
if ( V_143 == 0 || V_145 == 0 )
break;
} while ( V_146 > 2 * ( V_125 -> V_130 * 2 ) );
F_23 ( V_4 -> V_5 . V_35 -> V_34 ,
L_37 , V_148 ) ;
return 0 ;
V_151:
F_52 ( V_141 ) ;
F_40 ( V_113 ) ;
return V_147 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_33 * V_34 = V_3 -> V_35 -> V_34 ;
F_16 ( V_34 , L_38 ) ;
if ( V_16 -> V_4 . V_105 -> V_64 )
F_32 ( & V_16 -> V_4 ) ;
if ( V_16 -> V_56 -> V_64 ) {
F_29 ( V_16 -> V_56 ) ;
V_16 -> V_56 -> V_64 = NULL ;
V_16 -> V_56 -> V_103 = NULL ;
}
}
static void F_54 ( struct V_112 * V_155 )
{
struct V_1 * V_16 = F_1 ( & V_155 -> V_5 ) ;
F_16 ( V_16 -> V_4 . V_5 . V_35 -> V_34 , L_39 , V_156 ) ;
F_20 ( & V_16 -> V_55 ) ;
V_16 -> V_44 = true ;
F_21 ( V_16 ) ;
F_18 ( & V_16 -> V_55 ) ;
}
static void F_55 ( struct V_112 * V_155 )
{
struct V_1 * V_16 = F_1 ( & V_155 -> V_5 ) ;
F_16 ( V_16 -> V_4 . V_5 . V_35 -> V_34 , L_39 , V_156 ) ;
F_20 ( & V_16 -> V_55 ) ;
V_16 -> V_44 = false ;
F_21 ( V_16 ) ;
F_18 ( & V_16 -> V_55 ) ;
}
static int T_4
F_56 ( struct V_157 * V_158 , struct V_2 * V_3 )
{
struct V_33 * V_34 = V_158 -> V_34 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_37 ;
struct V_58 * V_59 ;
V_37 = F_57 ( V_158 , V_3 ) ;
if ( V_37 < 0 )
goto V_102;
V_16 -> V_54 = V_37 ;
V_159 . V_160 = V_37 ;
V_161 . V_162 = V_37 ;
V_163 . V_164 = V_37 ;
V_37 = F_57 ( V_158 , V_3 ) ;
if ( V_37 < 0 )
goto V_102;
V_16 -> V_104 = V_37 ;
V_165 . V_162 = V_37 ;
V_166 . V_162 = V_37 ;
V_163 . V_167 = V_37 ;
V_37 = - V_168 ;
V_59 = F_58 ( V_34 -> V_51 , & V_169 ) ;
if ( ! V_59 )
goto V_102;
V_16 -> V_4 . V_105 = V_59 ;
V_59 -> V_64 = V_34 ;
V_59 = F_58 ( V_34 -> V_51 , & V_170 ) ;
if ( ! V_59 )
goto V_102;
V_16 -> V_4 . V_108 = V_59 ;
V_59 -> V_64 = V_34 ;
V_59 = F_58 ( V_34 -> V_51 , & V_171 ) ;
if ( ! V_59 )
goto V_102;
V_16 -> V_56 = V_59 ;
V_59 -> V_64 = V_34 ;
V_37 = - V_172 ;
V_16 -> V_30 = F_59 ( V_59 , V_173 ) ;
if ( ! V_16 -> V_30 )
goto V_102;
V_16 -> V_30 -> V_38 = F_60 ( V_50 , V_173 ) ;
if ( ! V_16 -> V_30 -> V_38 )
goto V_102;
V_16 -> V_30 -> V_60 = V_16 ;
V_16 -> V_30 -> V_86 = F_22 ;
V_3 -> V_174 = F_61 ( V_175 ) ;
if ( ! V_3 -> V_174 )
goto V_102;
if ( F_4 ( V_158 -> V_34 -> V_51 ) ) {
V_176 . V_177 =
V_169 . V_177 ;
V_178 . V_177 =
V_170 . V_177 ;
V_179 . V_177 =
V_171 . V_177 ;
V_3 -> V_180 = F_61 ( V_181 ) ;
if ( ! V_3 -> V_180 )
goto V_102;
}
V_16 -> V_4 . V_182 = F_54 ;
V_16 -> V_4 . V_183 = F_55 ;
F_16 ( V_34 , L_40 ,
F_4 ( V_158 -> V_34 -> V_51 ) ? L_41 : L_42 ,
V_16 -> V_4 . V_105 -> V_184 , V_16 -> V_4 . V_108 -> V_184 ,
V_16 -> V_56 -> V_184 ) ;
return 0 ;
V_102:
if ( V_3 -> V_174 )
F_62 ( V_3 -> V_174 ) ;
if ( V_16 -> V_30 ) {
F_63 ( V_16 -> V_30 -> V_38 ) ;
F_64 ( V_16 -> V_56 , V_16 -> V_30 ) ;
}
if ( V_16 -> V_56 )
V_16 -> V_56 -> V_64 = NULL ;
if ( V_16 -> V_4 . V_108 -> V_103 )
V_16 -> V_4 . V_108 -> V_64 = NULL ;
if ( V_16 -> V_4 . V_105 -> V_103 )
V_16 -> V_4 . V_105 -> V_64 = NULL ;
ERROR ( V_34 , L_43 , V_3 -> V_184 , V_37 ) ;
return V_37 ;
}
static void
F_65 ( struct V_157 * V_158 , struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_16 ( V_158 -> V_34 , L_44 ) ;
if ( F_4 ( V_158 -> V_34 -> V_51 ) )
F_62 ( V_3 -> V_180 ) ;
F_62 ( V_3 -> V_174 ) ;
F_63 ( V_16 -> V_30 -> V_38 ) ;
F_64 ( V_16 -> V_56 , V_16 -> V_30 ) ;
V_185 [ 1 ] . V_186 = NULL ;
F_63 ( V_16 ) ;
}
int T_4 F_66 ( struct V_157 * V_158 , T_5 V_187 [ V_188 ] )
{
struct V_1 * V_16 ;
int V_37 ;
if ( ! F_67 ( V_158 -> V_34 -> V_51 ) || ! V_187 )
return - V_110 ;
if ( V_185 [ 0 ] . V_189 == 0 ) {
V_37 = F_68 ( V_158 -> V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
V_185 [ V_190 ] . V_189 = V_37 ;
V_161 . V_191 = V_37 ;
V_37 = F_68 ( V_158 -> V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
V_185 [ V_192 ] . V_189 = V_37 ;
V_165 . V_191 = V_37 ;
V_166 . V_191 = V_37 ;
V_37 = F_68 ( V_158 -> V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
V_185 [ V_193 ] . V_189 = V_37 ;
V_194 . V_195 = V_37 ;
V_37 = F_68 ( V_158 -> V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
V_185 [ V_196 ] . V_189 = V_37 ;
V_159 . V_197 = V_37 ;
}
V_16 = F_69 ( sizeof *V_16 , V_173 ) ;
if ( ! V_16 )
return - V_172 ;
snprintf ( V_16 -> V_187 , sizeof V_16 -> V_187 , L_45 , V_187 ) ;
V_185 [ 1 ] . V_186 = V_16 -> V_187 ;
F_70 ( & V_16 -> V_55 ) ;
F_12 ( V_16 ) ;
V_16 -> V_4 . V_198 = true ;
V_16 -> V_4 . V_5 . V_184 = L_46 ;
V_16 -> V_4 . V_5 . V_199 = V_200 ;
V_16 -> V_4 . V_5 . V_201 = F_56 ;
V_16 -> V_4 . V_5 . V_202 = F_65 ;
V_16 -> V_4 . V_5 . V_203 = F_28 ;
V_16 -> V_4 . V_5 . V_204 = F_37 ;
V_16 -> V_4 . V_5 . V_205 = F_26 ;
V_16 -> V_4 . V_5 . V_206 = F_53 ;
V_16 -> V_4 . V_207 = F_38 ;
V_16 -> V_4 . V_208 = F_45 ;
V_37 = F_71 ( V_158 , & V_16 -> V_4 . V_5 ) ;
if ( V_37 ) {
V_185 [ 1 ] . V_186 = NULL ;
F_63 ( V_16 ) ;
}
return V_37 ;
}
