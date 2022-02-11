static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline
struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline
struct V_5 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_5 , V_10 ) ;
}
static inline
struct V_5 * F_5 ( struct V_11 * V_12 )
{
struct V_5 * V_7 = F_2 ( V_12 ,
struct V_5 , V_13 ) ;
if ( & V_7 -> V_13 != V_12 )
V_7 = F_2 ( V_12 , struct V_5 , V_14 ) ;
return V_7 ;
}
static inline
T_1 F_6 ( T_1 V_15 )
{
T_1 V_16 = 0 ;
while ( V_15 ) {
V_16 += ( V_15 & 1 ) ;
V_15 >>= 1 ;
}
return V_16 ;
}
static void
F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
unsigned V_21 ;
unsigned long V_22 ;
bool V_23 = false ;
unsigned char * V_24 , * V_25 ;
int V_26 = V_20 -> V_26 ;
struct V_27 * V_28 = V_20 -> V_29 ;
struct V_30 * V_31 ;
struct V_11 * V_32 = V_28 -> V_33 ;
struct V_5 * V_7 = F_5 ( V_32 ) ;
if ( ! V_32 -> V_34 )
return;
if ( V_26 )
F_8 ( L_1 ,
V_35 , V_26 , V_20 -> V_36 , V_20 -> V_37 ) ;
V_31 = V_32 -> V_38 ;
if ( ! V_31 )
goto exit;
F_9 ( & V_32 -> V_39 , V_22 ) ;
if ( V_31 -> V_40 == V_41 ) {
V_24 = V_32 -> V_42 + V_32 -> V_43 ;
V_20 -> V_36 = V_20 -> V_37 ;
V_25 = V_20 -> V_44 ;
} else {
V_25 = V_32 -> V_42 + V_32 -> V_43 ;
V_24 = V_20 -> V_44 ;
}
V_21 = V_32 -> V_43 % V_32 -> V_45 ;
V_21 += V_20 -> V_36 ;
if ( V_21 >= V_32 -> V_45 )
V_23 = true ;
V_32 -> V_43 = ( V_32 -> V_43 + V_20 -> V_36 ) % V_32 -> V_46 ;
F_10 ( & V_32 -> V_39 , V_22 ) ;
memcpy ( V_25 , V_24 , V_20 -> V_36 ) ;
exit:
if ( F_11 ( V_18 , V_20 , V_47 ) )
F_12 ( & V_7 -> V_10 . V_48 , L_2 , __LINE__ ) ;
if ( V_23 )
F_13 ( V_31 ) ;
return;
}
static int
F_14 ( struct V_30 * V_31 , int V_49 )
{
struct V_5 * V_7 = F_15 ( V_31 ) ;
struct V_1 * V_50 = F_3 ( V_7 ) ;
struct V_11 * V_32 ;
unsigned long V_22 ;
struct V_17 * V_18 ;
int V_51 = 0 ;
if ( V_31 -> V_40 == V_41 ) {
V_18 = V_50 -> V_52 ;
V_32 = & V_7 -> V_14 ;
} else {
V_18 = V_50 -> V_53 ;
V_32 = & V_7 -> V_13 ;
}
F_9 ( & V_32 -> V_39 , V_22 ) ;
V_32 -> V_43 = 0 ;
switch ( V_49 ) {
case V_54 :
case V_55 :
V_32 -> V_38 = V_31 ;
break;
case V_56 :
case V_57 :
V_32 -> V_38 = NULL ;
break;
default:
V_51 = - V_58 ;
}
F_10 ( & V_32 -> V_39 , V_22 ) ;
if ( V_31 -> V_40 == V_41 && ! V_32 -> V_38 )
memset ( V_32 -> V_59 , 0 , V_32 -> V_60 * V_61 ) ;
return V_51 ;
}
static T_2 F_16 ( struct V_30 * V_31 )
{
struct V_5 * V_7 = F_15 ( V_31 ) ;
struct V_11 * V_32 ;
if ( V_31 -> V_40 == V_41 )
V_32 = & V_7 -> V_14 ;
else
V_32 = & V_7 -> V_13 ;
return F_17 ( V_31 -> V_62 , V_32 -> V_43 ) ;
}
static int F_18 ( struct V_30 * V_31 ,
struct V_63 * V_64 )
{
struct V_5 * V_7 = F_15 ( V_31 ) ;
struct V_11 * V_32 ;
int V_51 ;
if ( V_31 -> V_40 == V_41 )
V_32 = & V_7 -> V_14 ;
else
V_32 = & V_7 -> V_13 ;
V_51 = F_19 ( V_31 ,
F_20 ( V_64 ) ) ;
if ( V_51 >= 0 ) {
V_32 -> V_46 = V_31 -> V_62 -> V_46 ;
V_32 -> V_42 = V_31 -> V_62 -> V_42 ;
V_32 -> V_45 = F_21 ( V_64 ) ;
}
return V_51 ;
}
static int F_22 ( struct V_30 * V_31 )
{
struct V_5 * V_7 = F_15 ( V_31 ) ;
struct V_11 * V_32 ;
if ( V_31 -> V_40 == V_41 )
V_32 = & V_7 -> V_14 ;
else
V_32 = & V_7 -> V_13 ;
V_32 -> V_42 = NULL ;
V_32 -> V_46 = 0 ;
V_32 -> V_45 = 0 ;
return F_23 ( V_31 ) ;
}
static int F_24 ( struct V_30 * V_31 )
{
struct V_5 * V_7 = F_15 ( V_31 ) ;
struct V_65 * V_62 = V_31 -> V_62 ;
V_62 -> V_66 = V_67 ;
if ( V_31 -> V_40 == V_41 ) {
F_25 ( & V_7 -> V_14 . V_39 ) ;
V_62 -> V_66 . V_68 = V_69 ;
V_62 -> V_66 . V_70 = V_71 ;
V_62 -> V_66 . V_72 = F_6 ( V_73 ) ;
V_62 -> V_66 . V_74 = 2 * V_7 -> V_14 . V_60
/ V_62 -> V_66 . V_75 ;
} else {
F_25 ( & V_7 -> V_13 . V_39 ) ;
V_62 -> V_66 . V_68 = V_76 ;
V_62 -> V_66 . V_70 = V_71 ;
V_62 -> V_66 . V_72 = F_6 ( V_77 ) ;
V_62 -> V_66 . V_74 = 2 * V_7 -> V_13 . V_60
/ V_62 -> V_66 . V_75 ;
}
V_62 -> V_66 . V_78 = V_62 -> V_66 . V_68 ;
V_62 -> V_66 . V_79 = V_62 -> V_66 . V_72 ;
F_26 ( V_62 , V_80 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_31 )
{
return 0 ;
}
static int T_3 F_28 ( struct V_8 * V_10 )
{
struct V_5 * V_7 = F_4 ( V_10 ) ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_51 ;
V_51 = F_29 ( - 1 , NULL , V_85 , 0 , & V_82 ) ;
if ( V_51 < 0 )
return V_51 ;
V_7 -> V_82 = V_82 ;
V_51 = F_30 ( V_7 -> V_82 , L_3 , 0 ,
V_73 ? 1 : 0 , V_77 ? 1 : 0 , & V_84 ) ;
if ( V_51 < 0 )
goto V_86;
strcpy ( V_84 -> V_87 , L_3 ) ;
V_84 -> V_88 = V_7 ;
V_7 -> V_84 = V_84 ;
F_31 ( V_84 , V_41 , & V_89 ) ;
F_31 ( V_84 , V_90 , & V_89 ) ;
strcpy ( V_82 -> V_91 , L_4 ) ;
strcpy ( V_82 -> V_92 , L_4 ) ;
sprintf ( V_82 -> V_93 , L_5 , V_10 -> V_94 ) ;
F_32 ( V_82 , & V_10 -> V_48 ) ;
F_33 ( V_84 , V_95 ,
F_34 ( V_96 ) , 0 , V_97 ) ;
V_51 = F_35 ( V_82 ) ;
if ( ! V_51 ) {
F_36 ( V_10 , V_82 ) ;
return 0 ;
}
V_86:
F_37 ( V_82 ) ;
V_7 -> V_84 = NULL ;
V_7 -> V_82 = NULL ;
return V_51 ;
}
static int T_4 F_38 ( struct V_8 * V_10 )
{
struct V_81 * V_82 = F_39 ( V_10 ) ;
F_36 ( V_10 , NULL ) ;
if ( V_82 )
return F_37 ( V_82 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_50 )
{
struct V_5 * V_7 = & V_50 -> V_7 ;
int V_51 ;
V_7 -> V_98 . V_99 = F_28 ;
V_7 -> V_98 . remove = F_38 ;
V_7 -> V_98 . V_91 . V_87 = V_100 ;
V_7 -> V_10 . V_94 = 0 ;
V_7 -> V_10 . V_87 = V_100 ;
V_51 = F_41 ( & V_7 -> V_98 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_42 ( & V_7 -> V_10 ) ;
if ( V_51 )
F_43 ( & V_7 -> V_98 ) ;
return V_51 ;
}
static void F_44 ( struct V_1 * V_50 )
{
struct V_5 * V_7 = & V_50 -> V_7 ;
F_43 ( & V_7 -> V_98 ) ;
F_45 ( & V_7 -> V_10 ) ;
}
static inline void
F_46 ( struct V_11 * V_32 , struct V_17 * V_18 )
{
struct V_5 * V_7 = F_5 ( V_32 ) ;
int V_101 ;
V_32 -> V_34 = false ;
for ( V_101 = 0 ; V_101 < V_61 ; V_101 ++ ) {
if ( V_32 -> V_102 [ V_101 ] . V_20 ) {
F_47 ( V_18 , V_32 -> V_102 [ V_101 ] . V_20 ) ;
F_48 ( V_18 , V_32 -> V_102 [ V_101 ] . V_20 ) ;
V_32 -> V_102 [ V_101 ] . V_20 = NULL ;
}
}
if ( F_49 ( V_18 ) )
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
}
static int T_5
F_50 ( struct V_103 * V_104 , struct V_2 * V_105 )
{
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
struct V_106 * V_107 = V_104 -> V_107 ;
struct V_108 * V_109 = V_107 -> V_109 ;
struct V_11 * V_32 ;
int V_110 ;
V_110 = F_51 ( V_104 , V_105 ) ;
if ( V_110 < 0 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return V_110 ;
}
V_111 . V_112 = V_110 ;
F_52 ( V_50 -> V_113 , 0 ) ;
F_53 ( V_50 -> V_113 , V_110 ) ;
V_110 = F_51 ( V_104 , V_105 ) ;
if ( V_110 < 0 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return V_110 ;
}
V_114 . V_112 = V_110 ;
V_115 . V_112 = V_110 ;
F_52 ( V_50 -> V_116 , 0 ) ;
F_53 ( V_50 -> V_116 , V_110 ) ;
V_110 = F_51 ( V_104 , V_105 ) ;
if ( V_110 < 0 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return V_110 ;
}
V_117 . V_112 = V_110 ;
V_118 . V_112 = V_110 ;
F_52 ( V_50 -> V_119 , 0 ) ;
F_53 ( V_50 -> V_119 , V_110 ) ;
V_50 -> V_53 = F_54 ( V_109 , & V_120 ) ;
if ( ! V_50 -> V_53 )
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
V_50 -> V_53 -> V_121 = V_50 ;
V_50 -> V_52 = F_54 ( V_109 , & V_122 ) ;
if ( ! V_50 -> V_52 )
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
V_50 -> V_52 -> V_121 = V_50 ;
V_123 . V_124 = V_120 . V_124 ;
V_123 . V_125 = V_120 . V_125 ;
V_126 . V_124 = V_122 . V_124 ;
V_126 . V_125 = V_122 . V_125 ;
V_105 -> V_127 = F_55 ( V_128 ) ;
if ( F_56 ( V_109 ) )
V_105 -> V_129 = F_55 ( V_130 ) ;
V_32 = & V_50 -> V_7 . V_13 ;
V_32 -> V_60 = V_123 . V_125 ;
V_32 -> V_59 = F_57 ( V_32 -> V_60 * V_61 , V_96 ) ;
if ( ! V_32 -> V_59 ) {
V_32 -> V_60 = 0 ;
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
}
V_32 = & V_50 -> V_7 . V_14 ;
V_32 -> V_60 = V_126 . V_125 ;
V_32 -> V_59 = F_57 ( V_32 -> V_60 * V_61 , V_96 ) ;
if ( ! V_32 -> V_59 ) {
V_32 -> V_60 = 0 ;
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
}
return F_40 ( V_50 ) ;
}
static void
F_58 ( struct V_103 * V_104 , struct V_2 * V_105 )
{
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_106 * V_107 = V_104 -> V_107 ;
struct V_108 * V_109 = V_107 -> V_109 ;
struct V_11 * V_32 ;
F_44 ( V_50 ) ;
V_32 = & V_50 -> V_7 . V_14 ;
F_59 ( V_32 -> V_59 ) ;
V_32 = & V_50 -> V_7 . V_13 ;
F_59 ( V_32 -> V_59 ) ;
if ( F_56 ( V_109 ) )
F_60 ( V_105 -> V_129 ) ;
F_60 ( V_105 -> V_127 ) ;
if ( V_50 -> V_52 )
V_50 -> V_52 -> V_121 = NULL ;
if ( V_50 -> V_53 )
V_50 -> V_53 -> V_121 = NULL ;
}
static int
F_61 ( struct V_2 * V_105 , unsigned V_131 , unsigned V_132 )
{
struct V_106 * V_107 = V_105 -> V_133 -> V_107 ;
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
struct V_108 * V_109 = V_107 -> V_109 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_11 * V_32 ;
int V_101 ;
if ( V_132 > 1 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return - V_58 ;
}
if ( V_131 == F_62 ( V_50 -> V_113 ) ) {
if ( V_132 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return - V_58 ;
}
return 0 ;
}
if ( V_131 == F_62 ( V_50 -> V_116 ) ) {
V_18 = V_50 -> V_53 ;
V_32 = & V_7 -> V_13 ;
F_63 ( V_109 , V_105 , V_18 ) ;
F_52 ( V_50 -> V_116 , V_132 ) ;
} else if ( V_131 == F_62 ( V_50 -> V_119 ) ) {
V_18 = V_50 -> V_52 ;
V_32 = & V_7 -> V_14 ;
F_63 ( V_109 , V_105 , V_18 ) ;
F_52 ( V_50 -> V_119 , V_132 ) ;
} else {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return - V_58 ;
}
if ( V_132 == 0 ) {
F_46 ( V_32 , V_18 ) ;
return 0 ;
}
V_32 -> V_34 = true ;
F_64 ( V_18 ) ;
for ( V_101 = 0 ; V_101 < V_61 ; V_101 ++ ) {
if ( V_32 -> V_102 [ V_101 ] . V_20 ) {
if ( F_11 ( V_18 , V_32 -> V_102 [ V_101 ] . V_20 , V_47 ) )
F_12 ( & V_7 -> V_10 . V_48 , L_2 ,
__LINE__ ) ;
continue;
}
V_20 = F_65 ( V_18 , V_47 ) ;
if ( V_20 == NULL ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return - V_58 ;
}
V_32 -> V_102 [ V_101 ] . V_20 = V_20 ;
V_32 -> V_102 [ V_101 ] . V_33 = V_32 ;
V_20 -> V_134 = 0 ;
V_20 -> V_135 = V_136 ;
V_20 -> V_29 = & V_32 -> V_102 [ V_101 ] ;
V_20 -> V_37 = V_32 -> V_60 ;
V_20 -> V_137 = F_7 ;
V_20 -> V_44 = V_32 -> V_59 + V_101 * V_20 -> V_37 ;
if ( F_11 ( V_18 , V_20 , V_47 ) )
F_12 ( & V_7 -> V_10 . V_48 , L_2 , __LINE__ ) ;
}
return 0 ;
}
static int
F_66 ( struct V_2 * V_105 , unsigned V_131 )
{
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
if ( V_131 == F_62 ( V_50 -> V_113 ) )
return F_67 ( V_50 -> V_113 ) ;
else if ( V_131 == F_62 ( V_50 -> V_116 ) )
return F_67 ( V_50 -> V_116 ) ;
else if ( V_131 == F_62 ( V_50 -> V_119 ) )
return F_67 ( V_50 -> V_119 ) ;
else
F_12 ( & V_7 -> V_10 . V_48 ,
L_7 ,
V_35 , __LINE__ , V_131 ) ;
return - V_58 ;
}
static void
F_68 ( struct V_2 * V_105 )
{
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
F_46 ( & V_7 -> V_14 , V_50 -> V_52 ) ;
F_52 ( V_50 -> V_119 , 0 ) ;
F_46 ( & V_7 -> V_13 , V_50 -> V_53 ) ;
F_52 ( V_50 -> V_116 , 0 ) ;
}
static int
F_69 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
struct V_19 * V_20 = V_105 -> V_133 -> V_107 -> V_20 ;
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
T_6 V_140 = F_70 ( V_139 -> V_141 ) ;
T_6 V_142 = F_70 ( V_139 -> V_143 ) ;
T_6 V_144 = F_70 ( V_139 -> V_145 ) ;
T_7 V_146 = ( V_142 >> 8 ) & 0xff ;
T_7 V_147 = V_144 >> 8 ;
int V_148 = - V_149 ;
if ( V_147 == V_150 ) {
struct V_151 V_152 ;
if ( V_146 == V_153 )
V_152 . V_154 = V_69 ;
else if ( V_146 == V_155 )
V_152 . V_154 = V_76 ;
V_148 = F_71 ( unsigned , V_140 , sizeof V_152 ) ;
memcpy ( V_20 -> V_44 , & V_152 , V_148 ) ;
} else if ( V_147 == V_156 ) {
* ( T_7 * ) V_20 -> V_44 = 1 ;
V_148 = F_71 ( unsigned , V_140 , 1 ) ;
} else {
F_12 ( & V_7 -> V_10 . V_48 ,
L_8 ,
V_35 , __LINE__ , V_147 ) ;
}
return V_148 ;
}
static int
F_72 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
struct V_19 * V_20 = V_105 -> V_133 -> V_107 -> V_20 ;
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
T_6 V_140 = F_70 ( V_139 -> V_141 ) ;
T_6 V_142 = F_70 ( V_139 -> V_143 ) ;
T_6 V_144 = F_70 ( V_139 -> V_145 ) ;
T_7 V_146 = ( V_142 >> 8 ) & 0xff ;
T_7 V_147 = V_144 >> 8 ;
struct V_157 V_12 ;
int V_148 = - V_149 ;
if ( V_147 == V_150 ) {
if ( V_146 == V_153 )
V_12 . V_158 = V_69 ;
else if ( V_146 == V_155 )
V_12 . V_158 = V_76 ;
else
return - V_149 ;
V_12 . V_159 = V_12 . V_158 ;
V_12 . V_160 = 0 ;
V_12 . V_161 = 1 ;
V_148 = F_71 ( unsigned , V_140 , sizeof V_12 ) ;
memcpy ( V_20 -> V_44 , & V_12 , V_148 ) ;
} else {
F_12 ( & V_7 -> V_10 . V_48 ,
L_8 ,
V_35 , __LINE__ , V_147 ) ;
}
return V_148 ;
}
static int
F_73 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
if ( V_139 -> V_162 == V_163 )
return F_69 ( V_105 , V_139 ) ;
else if ( V_139 -> V_162 == V_164 )
return F_72 ( V_105 , V_139 ) ;
else
return - V_149 ;
}
static int
F_74 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
T_6 V_140 = F_70 ( V_139 -> V_141 ) ;
T_6 V_144 = F_70 ( V_139 -> V_145 ) ;
T_7 V_147 = V_144 >> 8 ;
if ( V_147 == V_150 )
return V_140 ;
return - V_149 ;
}
static int
F_75 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
T_6 V_142 = F_70 ( V_139 -> V_143 ) ;
T_7 V_131 = V_142 & 0xff ;
if ( V_131 != F_62 ( V_50 -> V_113 ) ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
return - V_149 ;
}
if ( V_139 -> V_165 & V_166 )
return F_73 ( V_105 , V_139 ) ;
else if ( V_139 -> V_162 == V_163 )
return F_74 ( V_105 , V_139 ) ;
return - V_149 ;
}
static int
F_76 ( struct V_2 * V_105 , const struct V_138 * V_139 )
{
struct V_106 * V_107 = V_105 -> V_133 -> V_107 ;
struct V_1 * V_50 = F_1 ( V_105 ) ;
struct V_5 * V_7 = & V_50 -> V_7 ;
struct V_19 * V_20 = V_107 -> V_20 ;
T_6 V_140 = F_70 ( V_139 -> V_141 ) ;
int V_148 = - V_149 ;
if ( ( V_139 -> V_165 & V_167 ) != V_168 )
return - V_149 ;
if ( ( V_139 -> V_165 & V_169 ) == V_170 )
V_148 = F_75 ( V_105 , V_139 ) ;
else
F_12 ( & V_7 -> V_10 . V_48 , L_6 , V_35 , __LINE__ ) ;
if ( V_148 >= 0 ) {
V_20 -> V_37 = V_148 ;
V_20 -> V_134 = V_148 < V_140 ;
V_148 = F_11 ( V_107 -> V_109 -> V_171 , V_20 , V_47 ) ;
if ( V_148 < 0 ) {
F_12 ( & V_7 -> V_10 . V_48 ,
L_6 , V_35 , __LINE__ ) ;
V_20 -> V_26 = 0 ;
}
}
return V_148 ;
}
static int F_77 ( struct V_103 * V_104 )
{
int V_94 , V_172 ;
V_173 = F_57 ( sizeof *V_173 , V_96 ) ;
if ( V_173 == NULL ) {
F_78 ( V_174 L_9 ) ;
return - V_175 ;
}
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_177 ] . V_94 = V_94 ;
V_178 . V_179 = V_94 ,
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_180 ] . V_94 = V_94 ;
V_111 . V_181 = V_94 ,
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_182 ] . V_94 = V_94 ;
V_183 . V_184 = V_94 ,
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_185 ] . V_94 = V_94 ;
V_186 . V_184 = V_94 ,
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_187 ] . V_94 = V_94 ;
V_188 . V_189 = V_94 ,
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_190 ] . V_94 = V_94 ;
V_191 . V_189 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_192 ] . V_94 = V_94 ;
V_193 . V_189 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_194 ] . V_94 = V_94 ;
V_195 . V_189 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_196 ] . V_94 = V_94 ;
V_114 . V_181 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_197 ] . V_94 = V_94 ;
V_115 . V_181 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_198 ] . V_94 = V_94 ;
V_117 . V_181 = V_94 ;
V_94 = F_79 ( V_104 -> V_107 ) ;
if ( V_94 < 0 )
return V_94 ;
V_176 [ V_199 ] . V_94 = V_94 ;
V_118 . V_181 = V_94 ;
V_173 -> V_4 . V_87 = L_10 ;
V_173 -> V_4 . V_200 = V_201 ;
V_173 -> V_4 . V_202 = F_50 ;
V_173 -> V_4 . V_203 = F_58 ;
V_173 -> V_4 . V_204 = F_61 ;
V_173 -> V_4 . V_205 = F_66 ;
V_173 -> V_4 . V_206 = F_68 ;
V_173 -> V_4 . V_207 = F_76 ;
V_188 . V_208 = F_6 ( V_77 ) ;
V_188 . V_209 = F_80 ( V_77 ) ;
V_191 . V_208 = F_6 ( V_73 ) ;
V_191 . V_209 = F_80 ( V_73 ) ;
V_210 . V_208 = F_6 ( V_77 ) ;
V_210 . V_209 = F_80 ( V_77 ) ;
V_211 . V_208 = F_6 ( V_73 ) ;
V_211 . V_209 = F_80 ( V_73 ) ;
V_212 . V_213 = V_214 ;
V_212 . V_215 = V_214 * 8 ;
V_216 . V_213 = V_217 ;
V_216 . V_215 = V_217 * 8 ;
snprintf ( V_218 , sizeof( V_218 ) , L_11 , V_69 ) ;
snprintf ( V_219 , sizeof( V_219 ) , L_11 , V_76 ) ;
V_172 = F_81 ( V_104 , & V_173 -> V_4 ) ;
if ( V_172 < 0 )
F_59 ( V_173 ) ;
return V_172 ;
}
static void
F_82 ( struct V_103 * V_104 )
{
F_59 ( V_173 ) ;
V_173 = NULL ;
}
