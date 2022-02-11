static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_10 ;
V_2 -> V_18 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 0 ;
F_2 ( L_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_24 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_6 ( & V_2 -> V_26 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
T_1 V_29 ;
int V_30 ;
V_30 = F_8 ( V_28 , V_31 , & V_29 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_3 ,
V_31 ) ;
return V_30 ;
}
V_2 -> V_32 = V_29 ;
V_30 = F_8 ( V_28 , V_33 , & V_29 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_3 ,
V_33 ) ;
return V_30 ;
}
V_2 -> V_34 = V_29 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return - V_35 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
V_2 -> V_36 = F_11 ( V_28 , V_37 ) ;
if ( F_12 ( V_2 -> V_36 ) ) {
F_9 ( V_28 , L_4 ) ;
return F_13 ( V_2 -> V_36 ) ;
}
V_2 -> V_32 = F_14 ( V_2 -> V_36 ) ;
V_2 -> V_38 = F_11 ( V_28 , V_39 ) ;
if ( F_12 ( V_2 -> V_38 ) ) {
F_9 ( V_28 , L_5 ) ;
return F_13 ( V_2 -> V_38 ) ;
}
V_2 -> V_34 = F_14 ( V_2 -> V_38 ) ;
return 0 ;
}
static struct V_40 * F_15 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_41 * V_42 ;
struct V_40 * V_43 ;
V_42 = F_16 ( V_28 -> V_44 , L_6 , 0 ) ;
if ( V_42 ) {
V_43 = F_17 ( V_42 ) ;
F_18 ( V_42 ) ;
} else {
F_19 ( V_28 ) ;
V_43 = V_2 -> V_45 ;
}
return V_43 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return - V_35 ;
}
static struct V_40 * F_15 ( struct V_1 * V_2 )
{
return NULL ;
}
static unsigned int F_20 ( struct V_40 * V_45 ,
unsigned int type )
{
unsigned int V_46 ;
int V_47 ;
for ( V_47 = 0 , V_46 = 0 ; V_47 < V_45 -> V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_45 -> V_49 [ V_47 ] ;
if ( type == F_21 ( V_50 ) )
V_46 ++ ;
}
return V_46 ;
}
static struct V_40 * F_22 ( struct V_1 * V_2 )
{
struct V_40 * V_43 ;
if ( V_2 -> V_51 ) {
F_19 ( V_2 -> V_28 ) ;
V_43 = V_2 -> V_45 ;
} else {
V_43 = F_15 ( V_2 ) ;
}
return V_43 ;
}
static int F_23 ( struct V_40 * V_45 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_54 ;
struct V_40 * V_43 ;
struct V_49 * V_50 ;
const char * V_55 ;
unsigned int V_47 , V_56 , V_57 ;
int V_30 ;
F_2 ( L_7 ) ;
V_53 = F_24 ( sizeof( struct V_1 ) ,
V_58 ) ;
if ( ! V_53 ) {
F_9 ( V_28 , L_8 ) ;
V_30 = - V_59 ;
goto V_60;
}
F_25 ( V_53 , V_28 ) ;
V_2 = F_26 ( V_53 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_61 = F_27 ( V_28 ) ;
V_2 -> V_28 = V_28 ;
F_28 ( V_45 , V_53 ) ;
F_29 ( & V_2 -> V_62 ) ;
F_30 ( & V_2 -> V_63 ) ;
F_30 ( & V_2 -> V_64 ) ;
F_29 ( & V_2 -> V_65 ) ;
V_2 -> V_66 = F_31 ( V_67 , V_68 ) ;
F_32 ( V_69 , & V_2 -> V_70 ) ;
V_2 -> V_51 = ( ! V_2 -> V_61 || V_71 ) ? 0 : 1 ;
V_43 = F_22 ( V_2 ) ;
if ( ! V_43 ) {
F_9 ( V_28 , L_9 ) ;
V_30 = - V_35 ;
goto V_72;
}
V_54 = & V_43 -> V_28 ;
if ( V_45 == V_43 ) {
V_56 = F_20 ( V_45 , V_73 ) - 3 ;
V_57 = F_20 ( V_45 , V_74 ) - 1 ;
} else {
V_56 = 0 ;
V_57 = 0 ;
}
F_33 ( V_75 ) ;
V_2 -> V_76 = V_75 ;
if ( V_2 -> V_76 & ( V_2 -> V_76 - 1 ) ) {
F_9 ( V_28 , L_10 ,
V_2 -> V_76 ) ;
V_30 = - V_35 ;
goto V_77;
}
F_33 ( V_78 ) ;
V_2 -> V_79 = V_78 ;
if ( V_2 -> V_79 & ( V_2 -> V_79 - 1 ) ) {
F_9 ( V_28 , L_11 ,
V_2 -> V_79 ) ;
V_30 = - V_35 ;
goto V_77;
}
V_50 = F_34 ( V_45 , V_73 , 0 ) ;
V_2 -> V_80 = F_35 ( V_28 , V_50 ) ;
if ( F_12 ( V_2 -> V_80 ) ) {
F_9 ( V_28 , L_12 ) ;
V_30 = F_13 ( V_2 -> V_80 ) ;
goto V_77;
}
if ( F_36 ( V_2 ) )
F_37 ( V_28 , L_13 , V_2 -> V_80 ) ;
V_50 = F_34 ( V_45 , V_73 , 1 ) ;
V_2 -> V_81 = F_35 ( V_28 , V_50 ) ;
if ( F_12 ( V_2 -> V_81 ) ) {
F_9 ( V_28 , L_14 ) ;
V_30 = F_13 ( V_2 -> V_81 ) ;
goto V_77;
}
if ( F_36 ( V_2 ) )
F_37 ( V_28 , L_15 , V_2 -> V_81 ) ;
V_50 = F_34 ( V_43 , V_73 , V_56 ++ ) ;
V_2 -> V_82 = F_35 ( V_28 , V_50 ) ;
if ( F_12 ( V_2 -> V_82 ) ) {
F_9 ( V_28 , L_16 ) ;
V_30 = F_13 ( V_2 -> V_82 ) ;
goto V_77;
}
if ( F_36 ( V_2 ) )
F_37 ( V_28 , L_17 , V_2 -> V_82 ) ;
V_50 = F_34 ( V_43 , V_73 , V_56 ++ ) ;
V_2 -> V_83 = F_35 ( V_28 , V_50 ) ;
if ( F_12 ( V_2 -> V_83 ) ) {
F_9 ( V_28 , L_18 ) ;
V_30 = F_13 ( V_2 -> V_83 ) ;
goto V_77;
}
if ( F_36 ( V_2 ) )
F_37 ( V_28 , L_19 , V_2 -> V_83 ) ;
V_50 = F_34 ( V_43 , V_73 , V_56 ++ ) ;
V_2 -> V_84 = F_35 ( V_28 , V_50 ) ;
if ( F_12 ( V_2 -> V_84 ) ) {
F_9 ( V_28 , L_20 ) ;
V_30 = F_13 ( V_2 -> V_84 ) ;
goto V_77;
}
if ( F_36 ( V_2 ) )
F_37 ( V_28 , L_21 , V_2 -> V_84 ) ;
V_30 = F_38 ( V_28 , V_85 ,
V_2 -> V_86 ,
sizeof( V_2 -> V_86 ) ) ;
if ( V_30 || ! F_39 ( V_2 -> V_86 ) ) {
F_9 ( V_28 , L_22 , V_85 ) ;
if ( ! V_30 )
V_30 = - V_35 ;
goto V_77;
}
V_30 = F_40 ( V_28 , V_87 ,
& V_55 ) ;
if ( V_30 || strcmp ( V_55 , F_41 ( V_88 ) ) ) {
F_9 ( V_28 , L_22 , V_87 ) ;
if ( ! V_30 )
V_30 = - V_35 ;
goto V_77;
}
V_2 -> V_55 = V_88 ;
if ( F_42 ( V_28 , V_89 ) )
V_2 -> V_90 = 1 ;
V_30 = F_8 ( V_54 , V_91 ,
& V_2 -> V_92 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 , V_91 ) ;
goto V_77;
}
switch ( V_2 -> V_92 ) {
case V_93 :
case V_94 :
break;
default:
F_9 ( V_28 , L_22 , V_91 ) ;
V_30 = - V_35 ;
goto V_77;
}
if ( F_42 ( V_54 , V_95 ) ) {
V_30 = F_43 ( V_54 ,
V_95 ,
V_2 -> V_96 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_95 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_96 , V_98 ,
sizeof( V_2 -> V_96 ) ) ;
}
if ( F_42 ( V_54 , V_99 ) ) {
V_30 = F_43 ( V_54 ,
V_99 ,
V_2 -> V_100 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_99 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_100 , V_101 ,
sizeof( V_2 -> V_100 ) ) ;
}
if ( F_42 ( V_54 , V_102 ) ) {
V_30 = F_43 ( V_54 ,
V_102 ,
V_2 -> V_103 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_102 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_103 , V_104 ,
sizeof( V_2 -> V_103 ) ) ;
}
if ( F_42 ( V_54 , V_105 ) ) {
V_30 = F_43 ( V_54 ,
V_105 ,
V_2 -> V_106 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_105 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_106 , V_107 ,
sizeof( V_2 -> V_106 ) ) ;
}
if ( F_42 ( V_54 , V_108 ) ) {
V_30 = F_43 ( V_54 ,
V_108 ,
V_2 -> V_109 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_108 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_109 , V_110 ,
sizeof( V_2 -> V_109 ) ) ;
}
if ( F_42 ( V_54 , V_111 ) ) {
V_30 = F_43 ( V_54 ,
V_111 ,
V_2 -> V_112 ,
V_97 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_22 ,
V_111 ) ;
goto V_77;
}
} else {
memcpy ( V_2 -> V_112 , V_113 ,
sizeof( V_2 -> V_112 ) ) ;
}
if ( V_2 -> V_51 )
V_30 = F_7 ( V_2 ) ;
else
V_30 = F_10 ( V_2 ) ;
if ( V_30 )
goto V_77;
V_2 -> V_114 = F_44 ( V_2 -> V_28 ) ;
if ( V_2 -> V_114 ) {
V_2 -> V_115 = V_116 ;
V_2 -> V_117 = V_118 ;
V_2 -> V_119 = V_120 ;
} else {
V_2 -> V_115 = V_121 ;
V_2 -> V_117 = V_122 ;
V_2 -> V_119 = V_123 ;
}
V_30 = F_45 ( V_45 , 0 ) ;
if ( V_30 < 0 ) {
F_9 ( V_28 , L_23 ) ;
goto V_77;
}
V_2 -> V_124 = V_30 ;
V_30 = F_45 ( V_43 , V_57 ++ ) ;
if ( V_30 < 0 ) {
F_9 ( V_28 , L_24 ) ;
goto V_77;
}
V_2 -> V_125 = V_30 ;
V_53 -> V_126 = V_2 -> V_124 ;
V_53 -> V_127 = ( unsigned long ) V_2 -> V_80 ;
memcpy ( V_53 -> V_128 , V_2 -> V_86 , V_53 -> V_129 ) ;
F_3 ( V_2 ) ;
V_2 -> V_24 . exit ( V_2 ) ;
F_46 ( V_2 ) ;
F_1 ( V_2 ) ;
V_30 = F_47 ( V_28 ,
F_48 ( V_2 -> V_130 . V_131 ) ) ;
if ( V_30 ) {
F_9 ( V_28 , L_25 ) ;
goto V_77;
}
V_2 -> V_132 = F_49 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_133 = V_2 -> V_132 ;
V_30 = F_50 ( V_53 , V_2 -> V_132 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_26 ) ;
goto V_77;
}
V_2 -> V_134 = F_49 (unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_135 = V_2 -> V_130 . V_136 ;
V_30 = F_51 ( V_53 , V_2 -> V_134 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_27 ) ;
goto V_77;
}
F_52 ( V_2 -> V_137 , sizeof( V_2 -> V_137 ) ) ;
for ( V_47 = 0 ; V_47 < V_138 ; V_47 ++ )
F_53 ( V_2 -> V_139 [ V_47 ] , V_140 , V_141 ,
V_47 % V_2 -> V_134 ) ;
F_53 ( V_2 -> V_142 , V_143 , V_144 , 1 ) ;
F_53 ( V_2 -> V_142 , V_143 , V_145 , 1 ) ;
F_53 ( V_2 -> V_142 , V_143 , V_146 , 1 ) ;
V_2 -> V_25 . V_147 ( V_2 ) ;
V_53 -> V_148 = F_54 () ;
V_53 -> V_149 = F_55 () ;
#ifdef F_56
V_53 -> V_150 = F_57 () ;
#endif
V_53 -> V_151 = V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 |
V_161 ;
if ( V_2 -> V_130 . V_162 )
V_53 -> V_151 |= V_163 ;
V_53 -> V_164 |= V_152 |
V_153 |
V_154 |
V_156 |
V_157 ;
V_53 -> V_165 |= V_53 -> V_151 ;
V_2 -> V_166 = V_53 -> V_165 ;
V_53 -> V_167 |= V_168 ;
V_53 -> V_169 = 0 ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_53 ) ;
V_30 = F_61 ( V_53 ) ;
if ( V_30 ) {
F_9 ( V_28 , L_28 ) ;
goto V_77;
}
snprintf ( V_2 -> V_170 , sizeof( V_2 -> V_170 ) - 1 , L_29 ,
F_62 ( V_53 ) ) ;
V_2 -> V_171 =
F_63 ( F_62 ( V_53 ) ) ;
if ( ! V_2 -> V_171 ) {
F_64 ( V_53 , L_30 ) ;
V_30 = - V_59 ;
goto V_172;
}
V_2 -> V_173 =
F_63 ( V_2 -> V_170 ) ;
if ( ! V_2 -> V_173 ) {
F_64 ( V_53 , L_31 ) ;
V_30 = - V_59 ;
goto V_174;
}
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_43 ) ;
F_68 ( V_53 , L_32 ) ;
F_2 ( L_33 ) ;
return 0 ;
V_174:
F_69 ( V_2 -> V_171 ) ;
V_172:
F_70 ( V_53 ) ;
V_77:
F_67 ( V_43 ) ;
V_72:
F_71 ( V_53 ) ;
V_60:
F_72 ( V_28 , L_34 ) ;
return V_30 ;
}
static int F_73 ( struct V_40 * V_45 )
{
struct V_52 * V_53 = F_74 ( V_45 ) ;
struct V_1 * V_2 = F_26 ( V_53 ) ;
F_2 ( L_35 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 -> V_173 ) ;
F_69 ( V_2 -> V_173 ) ;
F_77 ( V_2 -> V_171 ) ;
F_69 ( V_2 -> V_171 ) ;
F_70 ( V_53 ) ;
F_71 ( V_53 ) ;
F_2 ( L_36 ) ;
return 0 ;
}
static int F_78 ( struct V_27 * V_28 )
{
struct V_52 * V_53 = F_79 ( V_28 ) ;
struct V_1 * V_2 = F_26 ( V_53 ) ;
int V_30 = 0 ;
F_2 ( L_37 ) ;
if ( F_80 ( V_53 ) )
V_30 = F_81 ( V_53 , V_175 ) ;
V_2 -> V_176 = F_82 ( V_2 , V_177 , V_178 ) ;
V_2 -> V_176 |= V_179 ;
F_83 ( V_2 , V_177 , V_178 , V_2 -> V_176 ) ;
F_2 ( L_38 ) ;
return V_30 ;
}
static int F_84 ( struct V_27 * V_28 )
{
struct V_52 * V_53 = F_79 ( V_28 ) ;
struct V_1 * V_2 = F_26 ( V_53 ) ;
int V_30 = 0 ;
F_2 ( L_39 ) ;
V_2 -> V_176 &= ~ V_179 ;
F_83 ( V_2 , V_177 , V_178 , V_2 -> V_176 ) ;
if ( F_80 ( V_53 ) )
V_30 = F_85 ( V_53 , V_175 ) ;
F_2 ( L_40 ) ;
return V_30 ;
}
