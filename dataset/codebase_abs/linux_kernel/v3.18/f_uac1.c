static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof *V_3 , V_4 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
V_3 -> V_6 = F_2 ( V_2 , V_4 ) ;
if ( ! V_3 -> V_6 ) {
F_4 ( V_3 ) ;
return F_3 ( - V_5 ) ;
}
return V_3 ;
}
static void F_5 ( struct V_1 * V_7 )
{
F_4 ( V_7 -> V_6 ) ;
F_4 ( V_7 ) ;
}
static inline struct V_8 * F_6 ( struct V_9 * V_10 )
{
return F_7 ( V_10 , struct V_8 , V_11 . V_12 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_8 * V_15 = F_7 ( V_14 , struct V_8 ,
V_16 ) ;
struct V_1 * V_17 ;
F_9 ( & V_15 -> V_18 ) ;
if ( F_10 ( & V_15 -> V_19 ) ) {
F_11 ( & V_15 -> V_18 ) ;
return;
}
V_17 = F_12 ( & V_15 -> V_19 ,
struct V_1 , V_20 ) ;
F_13 ( & V_17 -> V_20 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_14 ( & V_15 -> V_11 , V_17 -> V_6 , V_17 -> V_21 ) ;
F_5 ( V_17 ) ;
}
static int F_15 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_8 * V_15 = V_25 -> V_26 ;
struct V_27 * V_28 = V_15 -> V_11 . V_12 . V_29 -> V_28 ;
struct V_1 * V_3 = V_15 -> V_3 ;
struct V_30 * V_31 ;
int V_32 ;
int V_33 ;
V_31 = F_7 ( V_15 -> V_11 . V_12 . V_34 , struct V_30 ,
V_35 ) ;
V_32 = V_31 -> V_32 ;
if ( ! V_3 )
return - V_36 ;
if ( V_32 - V_3 -> V_21 < V_25 -> V_21 ) {
F_16 ( & V_3 -> V_20 , & V_15 -> V_19 ) ;
F_17 ( & V_15 -> V_16 ) ;
V_3 = F_1 ( V_32 ) ;
if ( F_18 ( V_3 ) )
return - V_5 ;
}
memcpy ( V_3 -> V_6 + V_3 -> V_21 , V_25 -> V_6 , V_25 -> V_21 ) ;
V_3 -> V_21 += V_25 -> V_21 ;
V_15 -> V_3 = V_3 ;
V_33 = F_19 ( V_23 , V_25 , V_4 ) ;
if ( V_33 )
ERROR ( V_28 , L_1 , V_23 -> V_37 , V_33 ) ;
return 0 ;
}
static void F_20 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_8 * V_15 = V_25 -> V_26 ;
int V_38 = V_25 -> V_38 ;
T_1 V_14 = 0 ;
struct V_22 * V_39 = V_15 -> V_39 ;
switch ( V_38 ) {
case 0 :
if ( V_23 == V_39 )
F_15 ( V_23 , V_25 ) ;
else if ( V_15 -> V_40 ) {
memcpy ( & V_14 , V_25 -> V_6 , V_25 -> V_41 ) ;
V_15 -> V_40 -> V_42 ( V_15 -> V_40 , V_15 -> V_43 ,
F_21 ( V_14 ) ) ;
V_15 -> V_40 = NULL ;
}
break;
default:
break;
}
}
static int F_22 ( struct V_9 * V_10 ,
const struct V_44 * V_45 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
T_2 V_46 = ( ( F_21 ( V_45 -> V_47 ) >> 8 ) & 0xFF ) ;
T_3 V_48 = F_21 ( V_45 -> V_49 ) ;
T_3 V_50 = F_21 ( V_45 -> V_51 ) ;
T_2 V_52 = ( V_50 >> 8 ) & 0xFF ;
T_2 V_53 = ( V_45 -> V_54 & 0x0F ) ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
F_23 ( V_28 , L_2 ,
V_45 -> V_54 , V_50 , V_48 , V_46 ) ;
F_24 (cs, &audio->cs, list) {
if ( V_56 -> V_46 == V_46 ) {
F_24 (con, &cs->control, list) {
if ( V_58 -> type == V_52 ) {
V_15 -> V_40 = V_58 ;
break;
}
}
break;
}
}
V_15 -> V_43 = V_53 ;
V_25 -> V_26 = V_15 ;
V_25 -> V_59 = F_20 ;
return V_48 ;
}
static int F_25 ( struct V_9 * V_10 ,
const struct V_44 * V_45 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
int V_60 = - V_61 ;
T_2 V_46 = ( ( F_21 ( V_45 -> V_47 ) >> 8 ) & 0xFF ) ;
T_3 V_48 = F_21 ( V_45 -> V_49 ) ;
T_3 V_50 = F_21 ( V_45 -> V_51 ) ;
T_2 V_52 = ( V_50 >> 8 ) & 0xFF ;
T_2 V_53 = ( V_45 -> V_54 & 0x0F ) ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
F_23 ( V_28 , L_2 ,
V_45 -> V_54 , V_50 , V_48 , V_46 ) ;
F_24 (cs, &audio->cs, list) {
if ( V_56 -> V_46 == V_46 ) {
F_24 (con, &cs->control, list) {
if ( V_58 -> type == V_52 && V_58 -> V_62 ) {
V_60 = V_58 -> V_62 ( V_58 , V_53 ) ;
break;
}
}
break;
}
}
V_25 -> V_26 = V_15 ;
V_25 -> V_59 = F_20 ;
V_48 = F_26 ( V_63 , sizeof( V_60 ) , V_48 ) ;
memcpy ( V_25 -> V_6 , & V_60 , V_48 ) ;
return V_48 ;
}
static int F_27 ( struct V_9 * V_10 ,
const struct V_44 * V_45 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
int V_60 = - V_61 ;
T_3 V_23 = F_21 ( V_45 -> V_47 ) ;
T_3 V_48 = F_21 ( V_45 -> V_49 ) ;
T_3 V_50 = F_21 ( V_45 -> V_51 ) ;
F_23 ( V_28 , L_3 ,
V_45 -> V_54 , V_50 , V_48 , V_23 ) ;
switch ( V_45 -> V_54 ) {
case V_64 :
V_60 = V_48 ;
break;
case V_65 :
break;
case V_66 :
break;
case V_67 :
break;
case V_68 :
break;
default:
break;
}
return V_60 ;
}
static int F_28 ( struct V_9 * V_10 ,
const struct V_44 * V_45 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
int V_60 = - V_61 ;
T_2 V_23 = ( ( F_21 ( V_45 -> V_47 ) >> 8 ) & 0xFF ) ;
T_3 V_48 = F_21 ( V_45 -> V_49 ) ;
T_3 V_50 = F_21 ( V_45 -> V_51 ) ;
F_23 ( V_28 , L_3 ,
V_45 -> V_54 , V_50 , V_48 , V_23 ) ;
switch ( V_45 -> V_54 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_60 = V_48 ;
break;
case V_73 :
break;
default:
break;
}
return V_60 ;
}
static int
F_29 ( struct V_9 * V_10 , const struct V_44 * V_45 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
int V_60 = - V_61 ;
T_3 V_74 = F_21 ( V_45 -> V_47 ) ;
T_3 V_50 = F_21 ( V_45 -> V_51 ) ;
T_3 V_75 = F_21 ( V_45 -> V_49 ) ;
switch ( V_45 -> V_76 ) {
case V_77 | V_78 | V_79 :
V_60 = F_22 ( V_10 , V_45 ) ;
break;
case V_80 | V_78 | V_79 :
V_60 = F_25 ( V_10 , V_45 ) ;
break;
case V_77 | V_78 | V_81 :
V_60 = F_27 ( V_10 , V_45 ) ;
break;
case V_80 | V_78 | V_81 :
V_60 = F_28 ( V_10 , V_45 ) ;
break;
default:
ERROR ( V_28 , L_4 ,
V_45 -> V_76 , V_45 -> V_54 ,
V_50 , V_74 , V_75 ) ;
}
if ( V_60 >= 0 ) {
F_23 ( V_28 , L_5 ,
V_45 -> V_76 , V_45 -> V_54 ,
V_50 , V_74 , V_75 ) ;
V_25 -> V_82 = 0 ;
V_25 -> V_41 = V_60 ;
V_60 = F_19 ( V_28 -> V_83 -> V_84 , V_25 , V_4 ) ;
if ( V_60 < 0 )
ERROR ( V_28 , L_6 , V_60 ) ;
}
return V_60 ;
}
static int F_30 ( struct V_9 * V_10 , unsigned V_85 , unsigned V_86 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_22 * V_39 = V_15 -> V_39 ;
struct V_24 * V_25 ;
struct V_30 * V_31 ;
int V_87 , V_88 , V_32 ;
int V_89 = 0 , V_33 = 0 ;
F_23 ( V_28 , L_7 , V_85 , V_86 ) ;
V_31 = F_7 ( V_10 -> V_34 , struct V_30 , V_35 ) ;
V_87 = V_31 -> V_87 ;
V_88 = V_31 -> V_88 ;
V_32 = V_31 -> V_32 ;
if ( V_85 == 1 ) {
if ( V_86 == 1 ) {
F_31 ( V_39 ) ;
V_39 -> V_90 = V_15 ;
V_15 -> V_3 = F_1 ( V_32 ) ;
if ( F_18 ( V_15 -> V_3 ) )
return - V_5 ;
for ( V_89 = 0 ; V_89 < V_88 && V_33 == 0 ; V_89 ++ ) {
V_25 = F_32 ( V_39 , V_4 ) ;
if ( V_25 ) {
V_25 -> V_6 = F_2 ( V_87 ,
V_4 ) ;
if ( V_25 -> V_6 ) {
V_25 -> V_41 = V_87 ;
V_25 -> V_26 = V_15 ;
V_25 -> V_59 =
F_20 ;
V_33 = F_19 ( V_39 ,
V_25 , V_4 ) ;
if ( V_33 )
ERROR ( V_28 ,
L_1 ,
V_39 -> V_37 , V_33 ) ;
} else
V_33 = - V_5 ;
} else
V_33 = - V_5 ;
}
} else {
struct V_1 * V_3 = V_15 -> V_3 ;
if ( V_3 ) {
F_16 ( & V_3 -> V_20 ,
& V_15 -> V_19 ) ;
F_17 ( & V_15 -> V_16 ) ;
}
}
}
return V_33 ;
}
static void F_33 ( struct V_9 * V_10 )
{
return;
}
static void F_34 ( struct V_8 * V_15 )
{
struct V_91 * V_11 = & V_15 -> V_11 ;
T_2 * V_92 ;
int V_93 ;
V_94 . V_95 = F_35 ( V_11 ) ;
V_96 . V_95 = F_35 ( V_11 ) ;
V_93 = F_36 ( V_11 ) ;
V_92 = V_96 . V_97 [ 0 ] ;
memcpy ( V_92 , & V_93 , 3 ) ;
return;
}
static int
F_37 ( struct V_98 * V_99 , struct V_9 * V_10 )
{
struct V_27 * V_28 = V_99 -> V_28 ;
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_100 * V_101 ;
int V_38 ;
struct V_22 * V_23 = NULL ;
struct V_30 * V_102 ;
V_102 = F_7 ( V_10 -> V_34 , struct V_30 , V_35 ) ;
V_15 -> V_11 . V_83 = V_99 -> V_28 -> V_83 ;
V_102 -> V_11 = & V_15 -> V_11 ;
if ( ! V_102 -> V_103 ) {
V_38 = F_38 ( & V_15 -> V_11 ) ;
if ( V_38 < 0 )
return V_38 ;
V_102 -> V_103 = true ;
}
V_101 = F_39 ( V_28 , V_104 , F_40 ( V_105 ) ) ;
if ( F_18 ( V_101 ) )
return F_41 ( V_101 ) ;
V_106 . V_107 = V_101 [ V_108 ] . V_46 ;
V_94 . V_109 = V_101 [ V_110 ] . V_46 ;
V_94 . V_111 = V_101 [ V_112 ] . V_46 ;
V_113 . V_114 = V_101 [ V_115 ] . V_46 ;
V_116 . V_109 = V_101 [ V_117 ] . V_46 ;
V_118 . V_107 = V_101 [ V_119 ] . V_46 ;
V_120 . V_107 = V_101 [ V_121 ] . V_46 ;
F_34 ( V_15 ) ;
V_38 = F_42 ( V_99 , V_10 ) ;
if ( V_38 < 0 )
goto V_122;
V_106 . V_123 = V_38 ;
V_38 = F_42 ( V_99 , V_10 ) ;
if ( V_38 < 0 )
goto V_122;
V_118 . V_123 = V_38 ;
V_120 . V_123 = V_38 ;
V_38 = - V_124 ;
V_23 = F_43 ( V_28 -> V_83 , & V_125 ) ;
if ( ! V_23 )
goto V_122;
V_15 -> V_39 = V_23 ;
V_15 -> V_39 -> V_126 = & V_125 ;
V_23 -> V_90 = V_28 ;
V_38 = - V_5 ;
V_38 = F_44 ( V_10 , V_127 , V_127 , NULL ) ;
if ( V_38 )
goto V_122;
return 0 ;
V_122:
F_45 ( & V_15 -> V_11 ) ;
if ( V_23 )
V_23 -> V_90 = NULL ;
return V_38 ;
}
static int F_46 ( struct V_57 * V_58 , T_2 V_53 , int V_60 )
{
V_58 -> V_14 [ V_53 ] = V_60 ;
return 0 ;
}
static int F_47 ( struct V_57 * V_58 , T_2 V_53 )
{
return V_58 -> V_14 [ V_53 ] ;
}
static int F_48 ( struct V_8 * V_15 )
{
F_49 ( & V_15 -> V_56 ) ;
F_50 ( & V_128 . V_20 , & V_15 -> V_56 ) ;
F_49 ( & V_128 . V_129 ) ;
F_50 ( & V_130 . V_20 , & V_128 . V_129 ) ;
F_50 ( & V_131 . V_20 , & V_128 . V_129 ) ;
V_131 . V_14 [ V_132 ] = 0xffc0 ;
V_131 . V_14 [ V_133 ] = 0xe3a0 ;
V_131 . V_14 [ V_134 ] = 0xfff0 ;
V_131 . V_14 [ V_135 ] = 0x0030 ;
return 0 ;
}
static inline struct V_30 * F_51 ( struct V_136 * V_137 )
{
return F_7 ( F_52 ( V_137 ) , struct V_30 ,
V_35 . V_138 ) ;
}
static void F_53 ( struct V_136 * V_137 )
{
struct V_30 * V_31 = F_51 ( V_137 ) ;
F_54 ( & V_31 -> V_35 ) ;
}
static void F_55 ( struct V_139 * V_10 )
{
struct V_30 * V_31 ;
V_31 = F_7 ( V_10 , struct V_30 , V_35 ) ;
F_45 ( V_31 -> V_11 ) ;
if ( V_31 -> V_140 )
F_4 ( V_31 -> V_141 ) ;
if ( V_31 -> V_142 )
F_4 ( V_31 -> V_143 ) ;
if ( V_31 -> V_144 )
F_4 ( V_31 -> V_145 ) ;
F_4 ( V_31 ) ;
}
static struct V_139 * F_56 ( void )
{
struct V_30 * V_31 ;
V_31 = F_2 ( sizeof( * V_31 ) , V_146 ) ;
if ( ! V_31 )
return F_3 ( - V_5 ) ;
F_57 ( & V_31 -> V_18 ) ;
V_31 -> V_35 . V_147 = F_55 ;
F_58 ( & V_31 -> V_35 . V_138 , L_8 ,
& V_148 ) ;
V_31 -> V_87 = V_149 ;
V_31 -> V_88 = V_150 ;
V_31 -> V_32 = V_151 ;
V_31 -> V_141 = V_152 ;
V_31 -> V_143 = V_153 ;
V_31 -> V_145 = V_154 ;
return & V_31 -> V_35 ;
}
static void F_59 ( struct V_9 * V_10 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_30 * V_31 ;
V_31 = F_7 ( V_10 -> V_34 , struct V_30 , V_35 ) ;
F_4 ( V_15 ) ;
F_60 ( & V_31 -> V_18 ) ;
-- V_31 -> V_155 ;
F_61 ( & V_31 -> V_18 ) ;
}
static void F_62 ( struct V_98 * V_99 , struct V_9 * V_10 )
{
F_63 ( V_10 ) ;
}
static struct V_9 * F_64 ( struct V_139 * V_34 )
{
struct V_8 * V_15 ;
struct V_30 * V_31 ;
V_15 = F_2 ( sizeof( * V_15 ) , V_146 ) ;
if ( ! V_15 )
return F_3 ( - V_5 ) ;
V_15 -> V_11 . V_12 . V_37 = L_9 ;
V_31 = F_7 ( V_34 , struct V_30 , V_35 ) ;
F_60 ( & V_31 -> V_18 ) ;
++ V_31 -> V_155 ;
F_61 ( & V_31 -> V_18 ) ;
F_49 ( & V_15 -> V_19 ) ;
F_65 ( & V_15 -> V_18 ) ;
V_15 -> V_11 . V_12 . V_156 = F_37 ;
V_15 -> V_11 . V_12 . V_157 = F_62 ;
V_15 -> V_11 . V_12 . V_158 = F_30 ;
V_15 -> V_11 . V_12 . V_159 = F_29 ;
V_15 -> V_11 . V_12 . V_160 = F_33 ;
V_15 -> V_11 . V_12 . V_161 = F_59 ;
F_48 ( V_15 ) ;
F_66 ( & V_15 -> V_16 , F_8 ) ;
return & V_15 -> V_11 . V_12 ;
}
