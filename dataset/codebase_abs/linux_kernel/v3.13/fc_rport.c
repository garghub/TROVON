static struct V_1 * F_1 ( const struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (rdata, &lport->disc.rports, peers)
if ( V_5 -> V_6 . V_4 == V_4 )
return V_5 ;
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = V_3 -> V_7 . V_8 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( sizeof( * V_5 ) + V_3 -> V_9 , V_10 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_6 . V_11 = - 1 ;
V_5 -> V_6 . V_12 = - 1 ;
V_5 -> V_6 . V_4 = V_4 ;
V_5 -> V_6 . V_13 = V_14 ;
F_5 ( & V_5 -> V_15 ) ;
F_6 ( & V_5 -> V_16 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_18 = V_19 ;
V_5 -> V_20 = V_21 ;
V_5 -> V_22 = V_23 ;
V_5 -> V_24 = V_3 -> V_24 ;
V_5 -> V_25 = V_3 -> V_25 ;
V_5 -> V_26 = V_27 ;
F_7 ( & V_5 -> V_28 , V_29 ) ;
F_8 ( & V_5 -> V_30 , V_31 ) ;
if ( V_4 != V_32 ) {
V_5 -> V_33 = V_3 -> V_7 . V_34 ;
F_9 ( & V_5 -> V_35 , & V_3 -> V_36 . V_37 ) ;
}
return V_5 ;
}
static void F_10 ( struct V_15 * V_15 )
{
struct V_1 * V_5 ;
V_5 = F_11 ( V_15 , struct V_1 , V_15 ) ;
F_12 ( V_5 , V_38 ) ;
}
static const char * F_13 ( struct V_1 * V_5 )
{
const char * V_39 ;
V_39 = V_40 [ V_5 -> V_18 ] ;
if ( ! V_39 )
V_39 = L_1 ;
return V_39 ;
}
void F_14 ( struct V_41 * V_42 , T_1 V_43 )
{
if ( V_43 )
V_42 -> V_44 = V_43 ;
else
V_42 -> V_44 = 1 ;
}
static unsigned int F_15 ( struct V_45 * V_46 ,
unsigned int V_47 )
{
unsigned int V_48 ;
V_48 = F_16 ( V_46 -> V_49 . V_50 ) & V_51 ;
if ( V_48 >= V_52 && V_48 < V_47 )
V_47 = V_48 ;
V_48 = F_16 ( V_46 -> V_53 [ 3 - 1 ] . V_54 ) ;
if ( V_48 >= V_52 && V_48 < V_47 )
V_47 = V_48 ;
return V_47 ;
}
static void F_17 ( struct V_1 * V_5 ,
enum F_13 V_55 )
{
if ( V_5 -> V_18 != V_55 )
V_5 -> V_56 = 0 ;
V_5 -> V_18 = V_55 ;
}
static void V_31 ( struct V_57 * V_58 )
{
T_1 V_4 ;
struct V_1 * V_5 =
F_11 ( V_58 , struct V_1 , V_30 ) ;
struct V_59 * V_60 ;
enum V_61 V_20 ;
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_62 * V_63 ;
struct V_64 V_6 ;
struct V_41 * V_42 ;
struct V_65 * V_66 ;
T_2 type ;
F_18 ( & V_5 -> V_16 ) ;
V_20 = V_5 -> V_20 ;
V_63 = V_5 -> V_67 ;
V_42 = V_5 -> V_42 ;
F_19 ( V_5 , L_2 , V_20 ) ;
switch ( V_20 ) {
case V_68 :
V_6 = V_5 -> V_6 ;
V_5 -> V_20 = V_21 ;
V_5 -> V_69 = 0 ;
F_20 ( & V_5 -> V_15 ) ;
F_21 ( & V_5 -> V_16 ) ;
if ( ! V_42 )
V_42 = F_22 ( V_3 -> V_70 , 0 , & V_6 ) ;
if ( ! V_42 ) {
F_19 ( V_5 , L_3 ) ;
V_3 -> V_7 . V_71 ( V_5 ) ;
F_23 ( & V_5 -> V_15 , V_3 -> V_7 . V_72 ) ;
return;
}
F_18 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_42 )
F_19 ( V_5 , L_4 ) ;
V_5 -> V_42 = V_42 ;
V_42 -> V_26 = V_5 -> V_26 ;
V_42 -> V_73 = V_5 -> V_73 ;
V_60 = V_42 -> V_74 ;
V_60 -> V_17 = V_3 ;
V_60 -> V_18 = V_5 -> V_18 ;
V_60 -> V_22 = V_5 -> V_22 ;
V_60 -> V_24 = V_5 -> V_24 ;
V_60 -> V_25 = V_5 -> V_25 ;
F_21 ( & V_5 -> V_16 ) ;
if ( V_63 && V_63 -> V_75 ) {
F_19 ( V_5 , L_5 , V_20 ) ;
V_63 -> V_75 ( V_3 , V_5 , V_20 ) ;
}
if ( V_5 -> V_33 ) {
F_19 ( V_5 , L_6 , V_20 ) ;
V_5 -> V_33 ( V_3 , V_5 , V_20 ) ;
}
F_23 ( & V_5 -> V_15 , V_3 -> V_7 . V_72 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
if ( V_5 -> V_79 ) {
F_18 ( & V_80 ) ;
for ( type = 1 ; type < V_81 ; type ++ ) {
V_66 = V_82 [ type ] ;
if ( V_66 && V_66 -> V_83 )
V_66 -> V_83 ( V_5 ) ;
}
F_21 ( & V_80 ) ;
}
V_4 = V_5 -> V_6 . V_4 ;
F_21 ( & V_5 -> V_16 ) ;
if ( V_63 && V_63 -> V_75 ) {
F_19 ( V_5 , L_5 , V_20 ) ;
V_63 -> V_75 ( V_3 , V_5 , V_20 ) ;
}
if ( V_5 -> V_33 ) {
F_19 ( V_5 , L_6 , V_20 ) ;
V_5 -> V_33 ( V_3 , V_5 , V_20 ) ;
}
F_24 ( & V_5 -> V_28 ) ;
V_3 -> V_7 . V_84 ( V_3 , 0 , V_4 ) ;
V_3 -> V_7 . V_84 ( V_3 , V_4 , 0 ) ;
if ( V_42 ) {
V_60 = V_42 -> V_74 ;
V_60 -> V_18 = V_85 ;
F_18 ( & V_5 -> V_16 ) ;
V_5 -> V_42 = NULL ;
F_21 ( & V_5 -> V_16 ) ;
F_25 ( V_42 ) ;
}
F_18 ( & V_3 -> V_36 . V_86 ) ;
F_18 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_18 == V_85 ) {
if ( V_4 == V_32 ) {
V_5 -> V_20 = V_21 ;
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_3 -> V_7 . V_72 ) ;
} else if ( ( V_5 -> V_22 & V_87 ) &&
V_5 -> V_69 <
V_3 -> V_88 ) {
V_5 -> V_69 ++ ;
V_5 -> V_20 = V_21 ;
F_19 ( V_5 , L_7 ) ;
F_26 ( V_5 ) ;
F_21 ( & V_5 -> V_16 ) ;
} else {
F_19 ( V_5 , L_8 ) ;
F_27 ( & V_5 -> V_35 ) ;
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_3 -> V_7 . V_72 ) ;
}
} else {
V_5 -> V_20 = V_21 ;
if ( V_5 -> V_18 == V_89 )
F_28 ( V_5 ) ;
F_21 ( & V_5 -> V_16 ) ;
}
F_21 ( & V_3 -> V_36 . V_86 ) ;
break;
default:
F_21 ( & V_5 -> V_16 ) ;
break;
}
}
static int F_29 ( struct V_1 * V_5 )
{
F_18 ( & V_5 -> V_16 ) ;
V_5 -> V_22 |= V_87 ;
switch ( V_5 -> V_18 ) {
case V_89 :
F_19 ( V_5 , L_9 ) ;
F_30 ( V_5 ) ;
break;
case V_85 :
F_19 ( V_5 , L_10 ) ;
break;
default:
F_19 ( V_5 , L_11 ) ;
F_26 ( V_5 ) ;
break;
}
F_21 ( & V_5 -> V_16 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_5 ,
enum V_61 V_20 )
{
if ( V_5 -> V_18 == V_85 )
return;
F_19 ( V_5 , L_12 ) ;
F_17 ( V_5 , V_85 ) ;
if ( V_5 -> V_20 == V_21 )
F_32 ( V_90 , & V_5 -> V_30 ) ;
V_5 -> V_20 = V_20 ;
}
static int F_33 ( struct V_1 * V_5 )
{
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_13 ) ;
V_5 -> V_22 &= ~ V_87 ;
if ( V_5 -> V_18 == V_85 ) {
F_19 ( V_5 , L_14 ) ;
goto V_91;
}
F_34 ( V_5 ) ;
F_31 ( V_5 , V_78 ) ;
V_91:
F_21 ( & V_5 -> V_16 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_5 )
{
F_17 ( V_5 , V_89 ) ;
F_19 ( V_5 , L_15 ) ;
if ( V_5 -> V_20 == V_21 )
F_32 ( V_90 , & V_5 -> V_30 ) ;
V_5 -> V_20 = V_68 ;
}
static void V_29 ( struct V_57 * V_58 )
{
struct V_1 * V_5 =
F_11 ( V_58 , struct V_1 , V_28 . V_58 ) ;
F_18 ( & V_5 -> V_16 ) ;
switch ( V_5 -> V_18 ) {
case V_92 :
F_26 ( V_5 ) ;
break;
case V_93 :
F_35 ( V_5 ) ;
break;
case V_94 :
F_36 ( V_5 ) ;
break;
case V_95 :
F_37 ( V_5 ) ;
break;
case V_96 :
F_30 ( V_5 ) ;
break;
case V_97 :
case V_89 :
case V_19 :
case V_85 :
break;
}
F_21 ( & V_5 -> V_16 ) ;
}
static void F_38 ( struct V_1 * V_5 , struct V_98 * V_99 )
{
F_19 ( V_5 , L_16 ,
F_39 ( V_99 ) ? - F_40 ( V_99 ) : 0 ,
F_13 ( V_5 ) , V_5 -> V_56 ) ;
switch ( V_5 -> V_18 ) {
case V_92 :
case V_93 :
V_5 -> V_22 &= ~ V_87 ;
F_31 ( V_5 , V_76 ) ;
break;
case V_95 :
F_28 ( V_5 ) ;
break;
case V_94 :
case V_96 :
F_34 ( V_5 ) ;
break;
case V_97 :
case V_85 :
case V_89 :
case V_19 :
break;
}
}
static void F_41 ( struct V_1 * V_5 ,
struct V_98 * V_99 )
{
unsigned long V_100 = F_42 ( V_101 ) ;
if ( F_40 ( V_99 ) == - V_102 )
goto V_91;
if ( V_5 -> V_56 < V_5 -> V_17 -> V_88 ) {
F_19 ( V_5 , L_17 ,
F_40 ( V_99 ) , F_13 ( V_5 ) ) ;
V_5 -> V_56 ++ ;
if ( F_40 ( V_99 ) == - V_103 )
V_100 = 0 ;
F_43 ( & V_5 -> V_28 , V_100 ) ;
return;
}
V_91:
F_38 ( V_5 , V_99 ) ;
}
static int F_44 ( struct V_1 * V_5 ,
struct V_98 * V_99 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_104 ;
unsigned int V_24 ;
T_3 V_105 ;
V_104 = F_45 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
return - V_106 ;
V_105 = F_16 ( V_104 -> V_49 . V_107 ) ;
if ( F_46 ( V_99 ) == V_108 ) {
if ( V_105 & V_109 ) {
F_19 ( V_5 , L_18 ) ;
return - V_106 ;
}
} else {
V_24 = F_47 ( V_104 -> V_49 . V_110 ) ;
if ( V_105 & V_111 )
V_24 /= 1000000 ;
if ( V_24 > V_5 -> V_24 )
V_5 -> V_24 = V_24 ;
}
V_5 -> V_26 = F_15 ( V_104 , V_3 -> V_48 ) ;
return 0 ;
}
static void F_48 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_114 )
{
struct V_1 * V_5 = V_114 ;
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_104 ;
unsigned int V_25 ;
F_19 ( V_5 , L_19 , F_49 ( V_99 ) ) ;
if ( V_99 == F_50 ( - V_102 ) )
goto V_115;
F_18 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_18 != V_92 ) {
F_19 ( V_5 , L_20
L_21 , F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_38 ( V_5 , V_99 ) ;
goto V_116;
}
if ( F_46 ( V_99 ) != V_117 )
goto V_118;
if ( F_44 ( V_5 , V_99 ) )
goto V_118;
V_104 = F_45 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
goto V_118;
V_25 = F_47 ( V_104 -> V_49 . V_119 ) ;
if ( V_25 > V_5 -> V_25 )
V_5 -> V_25 = V_25 ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 )
F_35 ( V_5 ) ;
else
F_17 ( V_5 , V_97 ) ;
V_91:
F_51 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
V_115:
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
return;
V_118:
F_19 ( V_5 , L_22 ) ;
F_41 ( V_5 , V_99 ) ;
goto V_91;
}
static void F_26 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
if ( ! V_3 -> V_121 )
return F_35 ( V_5 ) ;
F_19 ( V_5 , L_23 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_92 ) ;
V_99 = F_52 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_99 )
return F_41 ( V_5 , V_99 ) ;
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_108 ,
F_48 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_36 ;
struct V_45 * V_46 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_54 ( V_99 ) ;
F_55 ( V_3 , V_127 , L_24 ) ;
V_36 = & V_3 -> V_36 ;
F_18 ( & V_36 -> V_86 ) ;
if ( ! V_3 -> V_121 ) {
V_126 . V_128 = V_129 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_46 = F_45 ( V_99 , sizeof( * V_46 ) ) ;
if ( ! V_46 ) {
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_134 ;
goto V_132;
}
V_5 = V_3 -> V_7 . V_8 ( V_3 , V_127 ) ;
if ( ! V_5 ) {
V_126 . V_128 = V_135 ;
V_126 . V_130 = V_136 ;
goto V_132;
}
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_25 ,
F_13 ( V_5 ) ) ;
switch ( V_5 -> V_18 ) {
case V_19 :
if ( V_3 -> V_121 )
break;
case V_85 :
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_135 ;
V_126 . V_130 = V_136 ;
goto V_132;
case V_92 :
case V_97 :
case V_93 :
break;
case V_94 :
case V_95 :
case V_89 :
case V_96 :
F_31 ( V_5 , V_77 ) ;
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_137 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
if ( F_44 ( V_5 , V_99 ) ) {
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_99 = F_52 ( V_3 , sizeof( * V_46 ) ) ;
if ( ! V_99 )
goto V_91;
F_56 ( V_3 , V_99 ) ;
V_46 = F_45 ( V_99 , sizeof( * V_46 ) ) ;
V_46 -> V_138 = V_117 ;
F_57 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 )
F_35 ( V_5 ) ;
else
F_17 ( V_5 , V_97 ) ;
V_91:
F_21 ( & V_5 -> V_16 ) ;
F_21 ( & V_36 -> V_86 ) ;
F_51 ( V_123 ) ;
return;
V_132:
F_21 ( & V_36 -> V_86 ) ;
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
F_51 ( V_123 ) ;
}
static void F_58 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_144 = NULL ;
T_3 V_145 ;
T_3 V_146 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_26 , F_49 ( V_99 ) ) ;
if ( V_5 -> V_18 != V_93 ) {
F_19 ( V_5 , L_27
L_21 , F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_41 ( V_5 , V_99 ) ;
goto V_116;
}
V_147 = F_46 ( V_99 ) ;
if ( V_147 == V_117 &&
( V_144 = F_45 ( V_99 , sizeof( * V_144 ) ) ) != NULL ) {
V_5 -> V_6 . V_12 = F_59 ( & V_144 -> V_148 ) ;
V_5 -> V_6 . V_11 = F_59 ( & V_144 -> V_149 ) ;
V_5 -> V_107 = F_16 ( V_144 -> V_49 . V_107 ) ;
if ( V_3 -> V_121 )
F_44 ( V_5 , V_99 ) ;
V_145 = F_16 ( V_144 -> V_49 . V_150 ) ;
V_146 = F_16 ( V_144 -> V_53 [ 3 - 1 ] . V_151 ) ;
if ( V_146 < V_145 )
V_145 = V_146 ;
V_5 -> V_152 = V_145 ;
V_5 -> V_26 = F_15 ( V_144 , V_3 -> V_48 ) ;
F_36 ( V_5 ) ;
} else
F_41 ( V_5 , V_99 ) ;
V_91:
F_51 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static bool
F_60 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_6 . V_13 == V_153 )
return true ;
if ( ( V_5 -> V_6 . V_13 & V_154 ) &&
( V_3 -> V_155 & V_156 ) )
return true ;
if ( ( V_5 -> V_6 . V_13 & V_157 ) &&
( V_3 -> V_155 & V_158 ) )
return true ;
return false ;
}
static void F_35 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
if ( ! F_60 ( V_3 , V_5 ) ) {
F_19 ( V_5 , L_28 ) ;
F_17 ( V_5 , V_97 ) ;
return;
}
F_19 ( V_5 , L_29 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_93 ) ;
V_5 -> V_26 = V_27 ;
V_99 = F_52 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_99 ) {
F_19 ( V_5 , L_30 , V_159 ) ;
F_41 ( V_5 , V_99 ) ;
return;
}
V_5 -> V_24 = V_3 -> V_24 ;
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_160 ,
F_58 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_61 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct {
struct V_161 V_162 ;
struct V_163 V_164 ;
} * V_165 ;
struct V_163 V_166 ;
struct V_65 * V_66 ;
T_1 V_13 = V_14 ;
T_1 V_167 = 0 ;
T_2 V_147 ;
T_2 V_168 = 0 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_31 , F_49 ( V_99 ) ) ;
if ( V_5 -> V_18 != V_94 ) {
F_19 ( V_5 , L_32
L_21 , F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_41 ( V_5 , V_99 ) ;
goto V_116;
}
V_5 -> V_6 . V_13 = V_14 ;
V_147 = F_46 ( V_99 ) ;
if ( V_147 == V_117 ) {
V_165 = F_45 ( V_99 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
goto V_91;
V_168 = ( V_165 -> V_164 . V_169 & V_170 ) ;
F_19 ( V_5 , L_33 ,
V_165 -> V_164 . V_169 ) ;
V_5 -> V_171 = V_165 -> V_164 . V_171 ;
if ( V_168 != V_172 ) {
if ( V_168 == V_173 )
F_38 ( V_5 , V_99 ) ;
else
F_41 ( V_5 , V_99 ) ;
goto V_91;
}
if ( V_165 -> V_162 . V_174 < sizeof( V_165 -> V_164 ) )
goto V_91;
V_167 = F_47 ( V_165 -> V_164 . V_175 ) ;
if ( V_167 & V_176 )
V_5 -> V_22 |= V_177 ;
if ( V_167 & V_178 )
V_5 -> V_22 |= V_179 ;
V_66 = V_82 [ V_180 ] ;
if ( V_66 ) {
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_66 -> V_162 ( V_5 , V_165 -> V_162 . V_174 ,
& V_165 -> V_164 , & V_166 ) ;
}
V_5 -> V_73 = V_181 ;
if ( V_167 & V_156 )
V_13 |= V_182 ;
if ( V_167 & V_158 )
V_13 |= V_183 ;
V_5 -> V_6 . V_13 = V_13 ;
F_37 ( V_5 ) ;
} else {
F_19 ( V_5 , L_34 ) ;
F_41 ( V_5 , V_99 ) ;
}
V_91:
F_51 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_36 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct {
struct V_161 V_162 ;
struct V_163 V_164 ;
} * V_165 ;
struct V_98 * V_99 ;
struct V_65 * V_66 ;
if ( V_5 -> V_6 . V_4 >= V_184 ) {
F_28 ( V_5 ) ;
return;
}
F_19 ( V_5 , L_35 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_94 ) ;
V_99 = F_52 ( V_3 , sizeof( * V_165 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
F_62 ( V_3 , V_99 ) ;
V_66 = V_82 [ V_180 ] ;
if ( V_66 ) {
V_165 = F_45 ( V_99 , sizeof( * V_165 ) ) ;
V_66 -> V_162 ( V_5 , sizeof( V_165 -> V_164 ) , NULL , & V_165 -> V_164 ) ;
}
F_63 ( V_99 , V_185 , V_5 -> V_6 . V_4 ,
F_64 ( V_3 -> V_70 ) , V_186 ,
V_187 | V_188 | V_189 , 0 ) ;
if ( ! V_3 -> V_7 . V_190 ( V_3 , V_99 , F_61 ,
NULL , V_5 , 2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_65 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_36 , F_49 ( V_99 ) ) ;
if ( V_5 -> V_18 != V_95 ) {
F_19 ( V_5 , L_37
L_21 , F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_38 ( V_5 , V_99 ) ;
goto V_116;
}
V_147 = F_46 ( V_99 ) ;
if ( V_147 == V_117 ) {
struct V_191 * V_192 ;
T_1 V_193 ;
T_1 V_194 ;
V_192 = F_45 ( V_99 , sizeof( * V_192 ) ) ;
if ( V_192 ) {
V_193 = F_47 ( V_192 -> V_195 ) ;
V_194 = F_47 ( V_192 -> V_196 ) ;
if ( V_194 == 0 )
V_194 = 1 ;
V_5 -> V_25 = V_194 ;
V_194 = F_47 ( V_192 -> V_197 ) ;
if ( V_193 & V_198 )
V_194 /= 1000000 ;
if ( V_194 == 0 )
V_194 = 1 ;
V_5 -> V_24 = V_194 ;
}
}
F_28 ( V_5 ) ;
V_91:
F_51 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_37 ( struct V_1 * V_5 )
{
struct V_98 * V_99 ;
struct V_2 * V_3 = V_5 -> V_17 ;
F_19 ( V_5 , L_38 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_95 ) ;
V_99 = F_52 ( V_3 , sizeof( struct V_199 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_200 ,
F_65 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_66 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_201 )
{
struct V_2 * V_3 = V_201 ;
F_55 ( V_3 , F_67 ( V_113 ) -> V_202 ,
L_39 , F_49 ( V_99 ) ) ;
if ( F_39 ( V_99 ) )
return;
F_51 ( V_99 ) ;
}
static void F_34 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
F_19 ( V_5 , L_40 ,
F_13 ( V_5 ) ) ;
V_99 = F_52 ( V_3 , sizeof( struct V_203 ) ) ;
if ( ! V_99 )
return;
( void ) V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_204 ,
F_66 , V_3 , 0 ) ;
}
static void F_68 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct V_205 * V_206 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_41 ) ;
if ( V_5 -> V_18 != V_96 ) {
F_19 ( V_5 , L_42 ,
F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_38 ( V_5 , V_99 ) ;
goto V_116;
}
V_147 = F_46 ( V_99 ) ;
V_206 = F_45 ( V_99 , sizeof( * V_206 ) ) ;
if ( V_147 != V_117 || ! V_206 ||
F_69 ( V_206 -> V_207 ) != V_5 -> V_6 . V_4 ||
F_59 ( & V_206 -> V_208 ) != V_5 -> V_6 . V_12 ||
F_59 ( & V_206 -> V_209 ) != V_5 -> V_6 . V_11 ) {
F_19 ( V_5 , L_43 ) ;
F_26 ( V_5 ) ;
} else {
F_19 ( V_5 , L_44 ) ;
F_28 ( V_5 ) ;
}
V_91:
F_51 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_30 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
F_19 ( V_5 , L_45 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_96 ) ;
V_99 = F_52 ( V_3 , sizeof( struct V_205 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_210 ,
F_68 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_70 ( struct V_1 * V_5 ,
struct V_98 * V_211 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct V_205 * V_206 ;
struct V_125 V_126 ;
F_19 ( V_5 , L_46 ) ;
V_206 = F_45 ( V_211 , sizeof( * V_206 ) ) ;
if ( ! V_206 ) {
V_126 . V_128 = V_212 ;
V_126 . V_130 = V_134 ;
V_3 -> V_7 . V_141 ( V_211 , V_142 , & V_126 ) ;
goto V_213;
}
V_99 = F_52 ( V_3 , sizeof( * V_206 ) ) ;
if ( ! V_99 )
goto V_213;
F_71 ( V_3 , V_99 ) ;
V_206 = F_45 ( V_99 , sizeof( * V_206 ) ) ;
V_206 -> V_214 = V_117 ;
F_57 ( V_99 , V_211 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
V_213:
F_51 ( V_211 ) ;
}
static void F_72 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
struct V_125 V_126 ;
struct V_221 * V_222 ;
F_19 ( V_5 , L_47 ,
F_13 ( V_5 ) ) ;
V_216 = F_45 ( V_123 , sizeof( * V_216 ) ) ;
if ( ! V_216 ) {
V_126 . V_128 = V_212 ;
V_126 . V_130 = V_134 ;
goto V_223;
}
V_99 = F_52 ( V_3 , sizeof( * V_218 ) ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_224 ;
V_126 . V_130 = V_225 ;
goto V_223;
}
V_218 = F_45 ( V_99 , sizeof( * V_218 ) ) ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_218 -> V_226 = V_117 ;
V_220 = & V_218 -> V_227 ;
if ( V_3 -> V_7 . V_228 ) {
V_3 -> V_7 . V_228 ( V_3 , V_220 ) ;
} else {
F_73 ( V_3 -> V_70 ) ;
V_222 = & V_3 -> V_229 ;
V_220 -> V_230 = F_74 ( V_222 -> V_231 ) ;
V_220 -> V_232 = F_74 ( V_222 -> V_233 ) ;
V_220 -> V_234 = F_74 ( V_222 -> V_235 ) ;
V_220 -> V_236 = F_74 ( V_222 -> V_237 ) ;
V_220 -> V_238 = F_74 ( V_222 -> V_239 ) ;
V_220 -> V_240 = F_74 ( V_222 -> V_241 ) ;
}
F_57 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
goto V_91;
V_223:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_91:
F_51 ( V_123 ) ;
}
static void F_75 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
struct V_125 V_242 ;
F_18 ( & V_3 -> V_36 . V_86 ) ;
V_5 = V_3 -> V_7 . V_8 ( V_3 , F_54 ( V_99 ) ) ;
if ( ! V_5 ) {
F_21 ( & V_3 -> V_36 . V_86 ) ;
goto V_132;
}
F_18 ( & V_5 -> V_16 ) ;
F_21 ( & V_3 -> V_36 . V_86 ) ;
switch ( V_5 -> V_18 ) {
case V_94 :
case V_95 :
case V_89 :
case V_96 :
break;
default:
F_21 ( & V_5 -> V_16 ) ;
goto V_132;
}
switch ( F_46 ( V_99 ) ) {
case V_243 :
F_76 ( V_5 , V_99 ) ;
break;
case V_244 :
F_77 ( V_5 , V_99 ) ;
break;
case V_210 :
F_70 ( V_5 , V_99 ) ;
break;
case V_245 :
V_3 -> V_7 . V_141 ( V_99 , V_245 , NULL ) ;
F_51 ( V_99 ) ;
break;
case V_246 :
V_3 -> V_7 . V_141 ( V_99 , V_246 , NULL ) ;
F_51 ( V_99 ) ;
break;
case V_247 :
F_72 ( V_5 , V_99 ) ;
break;
default:
F_51 ( V_99 ) ;
break;
}
F_21 ( & V_5 -> V_16 ) ;
return;
V_132:
V_242 . V_128 = V_224 ;
V_242 . V_130 = V_248 ;
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_242 ) ;
F_51 ( V_99 ) ;
}
static void F_78 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_125 V_242 ;
switch ( F_46 ( V_99 ) ) {
case V_108 :
F_53 ( V_3 , V_99 ) ;
break;
case V_160 :
F_79 ( V_3 , V_99 ) ;
break;
case V_204 :
F_80 ( V_3 , V_99 ) ;
break;
case V_243 :
case V_244 :
case V_210 :
case V_245 :
case V_246 :
case V_247 :
F_75 ( V_3 , V_99 ) ;
break;
default:
V_242 . V_128 = V_129 ;
V_242 . V_130 = V_131 ;
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_242 ) ;
F_51 ( V_99 ) ;
break;
}
}
static void F_79 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_36 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_45 * V_249 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_54 ( V_99 ) ;
F_55 ( V_3 , V_127 , L_48 ) ;
V_249 = F_45 ( V_99 , sizeof( * V_249 ) ) ;
if ( ! V_249 ) {
F_55 ( V_3 , V_127 , L_49 ) ;
V_126 . V_128 = V_212 ;
V_126 . V_130 = V_134 ;
goto V_132;
}
V_36 = & V_3 -> V_36 ;
F_18 ( & V_36 -> V_86 ) ;
V_5 = V_3 -> V_7 . V_250 ( V_3 , V_127 ) ;
if ( ! V_5 ) {
F_21 ( & V_36 -> V_86 ) ;
V_126 . V_128 = V_224 ;
V_126 . V_130 = V_225 ;
goto V_132;
}
F_18 ( & V_5 -> V_16 ) ;
F_21 ( & V_36 -> V_86 ) ;
V_5 -> V_6 . V_12 = F_59 ( & V_249 -> V_148 ) ;
V_5 -> V_6 . V_11 = F_59 ( & V_249 -> V_149 ) ;
switch ( V_5 -> V_18 ) {
case V_19 :
F_19 ( V_5 , L_50 ) ;
break;
case V_97 :
F_19 ( V_5 , L_51 ) ;
break;
case V_93 :
F_19 ( V_5 , L_52 ) ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 ) {
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_251 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
break;
case V_94 :
case V_95 :
case V_89 :
case V_96 :
F_19 ( V_5 , L_53
L_54 , V_5 -> V_18 ) ;
break;
case V_92 :
case V_85 :
F_19 ( V_5 , L_55 ,
F_13 ( V_5 ) ) ;
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_137 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
if ( ! F_60 ( V_3 , V_5 ) ) {
F_19 ( V_5 , L_56 ) ;
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_5 -> V_26 = F_15 ( V_249 , V_3 -> V_48 ) ;
V_99 = F_52 ( V_3 , sizeof( * V_249 ) ) ;
if ( ! V_99 )
goto V_91;
F_81 ( V_3 , V_99 , V_117 ) ;
F_57 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
F_36 ( V_5 ) ;
V_91:
F_21 ( & V_5 -> V_16 ) ;
F_51 ( V_123 ) ;
return;
V_132:
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_126 ) ;
F_51 ( V_99 ) ;
}
static void F_76 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct {
struct V_161 V_162 ;
struct V_163 V_164 ;
} * V_165 ;
struct V_163 * V_252 ;
struct V_163 * V_164 ;
unsigned int V_253 ;
unsigned int V_254 ;
enum V_255 V_256 ;
enum V_255 V_257 ;
struct V_125 V_126 ;
struct V_65 * V_66 ;
F_19 ( V_5 , L_57 ,
F_13 ( V_5 ) ) ;
V_253 = F_82 ( V_123 ) - sizeof( struct V_258 ) ;
V_165 = F_45 ( V_123 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
goto V_259;
V_254 = F_16 ( V_165 -> V_162 . V_260 ) ;
if ( ( V_254 % 4 ) != 0 || V_254 > V_253 || V_254 < 16 )
goto V_259;
if ( V_254 < V_253 )
V_253 = V_254 ;
V_254 = V_165 -> V_162 . V_174 ;
if ( ( V_254 % 4 ) != 0 || V_254 < sizeof( * V_164 ) ||
V_254 > V_253 || V_253 < sizeof( * V_165 ) || V_254 < 12 )
goto V_259;
V_252 = & V_165 -> V_164 ;
V_99 = F_52 ( V_3 , V_253 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_224 ;
V_126 . V_130 = V_225 ;
goto V_132;
}
V_165 = F_45 ( V_99 , V_253 ) ;
F_83 ( ! V_165 ) ;
memset ( V_165 , 0 , V_253 ) ;
V_165 -> V_162 . V_261 = V_117 ;
V_165 -> V_162 . V_174 = V_254 ;
V_165 -> V_162 . V_260 = F_84 ( V_253 ) ;
V_253 -= sizeof( struct V_161 ) ;
V_164 = & V_165 -> V_164 ;
F_18 ( & V_80 ) ;
while ( V_253 >= V_254 ) {
V_5 -> V_171 = V_252 -> V_171 ;
V_164 -> V_171 = V_252 -> V_171 ;
V_164 -> V_262 = V_252 -> V_262 ;
V_256 = 0 ;
if ( V_252 -> V_171 < V_81 ) {
V_66 = V_263 [ V_252 -> V_171 ] ;
if ( V_66 )
V_256 = V_66 -> V_162 ( V_5 , V_254 , V_252 , V_164 ) ;
V_66 = V_82 [ V_252 -> V_171 ] ;
if ( V_66 ) {
V_257 = V_66 -> V_162 ( V_5 , V_254 , V_252 , V_164 ) ;
if ( ! V_256 || V_257 == V_172 )
V_256 = V_257 ;
}
}
if ( ! V_256 ) {
if ( V_164 -> V_169 & V_264 )
V_256 |= V_173 ;
else
V_256 |= V_265 ;
}
V_164 -> V_169 |= V_256 ;
V_253 -= V_254 ;
V_252 = (struct V_163 * ) ( ( char * ) V_252 + V_254 ) ;
V_164 = (struct V_163 * ) ( ( char * ) V_164 + V_254 ) ;
}
F_21 ( & V_80 ) ;
F_57 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
switch ( V_5 -> V_18 ) {
case V_94 :
F_28 ( V_5 ) ;
break;
default:
break;
}
goto V_213;
V_259:
V_126 . V_128 = V_212 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_213:
F_51 ( V_123 ) ;
}
static void F_77 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct {
struct V_266 V_83 ;
struct V_163 V_164 ;
} * V_165 ;
struct V_163 * V_252 ;
struct V_163 * V_164 ;
unsigned int V_253 ;
unsigned int V_254 ;
struct V_125 V_126 ;
F_19 ( V_5 , L_58 ,
F_13 ( V_5 ) ) ;
V_253 = F_82 ( V_123 ) - sizeof( struct V_258 ) ;
V_165 = F_45 ( V_123 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
goto V_259;
V_254 = F_16 ( V_165 -> V_83 . V_267 ) ;
if ( V_254 != 20 )
goto V_259;
if ( V_254 < V_253 )
V_253 = V_254 ;
V_252 = & V_165 -> V_164 ;
V_99 = F_52 ( V_3 , V_253 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_224 ;
V_126 . V_130 = V_225 ;
goto V_132;
}
V_165 = F_45 ( V_99 , V_253 ) ;
F_83 ( ! V_165 ) ;
memset ( V_165 , 0 , V_253 ) ;
V_165 -> V_83 . V_268 = V_117 ;
V_165 -> V_83 . V_269 = 0x10 ;
V_165 -> V_83 . V_267 = F_84 ( V_253 ) ;
V_164 = & V_165 -> V_164 ;
V_164 -> V_171 = V_252 -> V_171 ;
V_164 -> V_262 = V_252 -> V_262 ;
V_164 -> V_169 = V_172 ;
F_31 ( V_5 , V_77 ) ;
F_57 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
goto V_213;
V_259:
V_126 . V_128 = V_212 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_213:
F_51 ( V_123 ) ;
}
static void F_80 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
T_1 V_127 ;
V_3 -> V_7 . V_141 ( V_99 , V_117 , NULL ) ;
V_127 = F_54 ( V_99 ) ;
F_18 ( & V_3 -> V_36 . V_86 ) ;
V_5 = V_3 -> V_7 . V_8 ( V_3 , V_127 ) ;
if ( V_5 ) {
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_59 ,
F_13 ( V_5 ) ) ;
F_31 ( V_5 , V_77 ) ;
F_21 ( & V_5 -> V_16 ) ;
} else
F_55 ( V_3 , V_127 ,
L_60 ) ;
F_21 ( & V_3 -> V_36 . V_86 ) ;
F_51 ( V_99 ) ;
}
static void F_85 ( void )
{
F_86 ( V_90 ) ;
}
int F_87 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_7 . V_8 )
V_3 -> V_7 . V_8 = F_1 ;
if ( ! V_3 -> V_7 . V_250 )
V_3 -> V_7 . V_250 = F_3 ;
if ( ! V_3 -> V_7 . V_270 )
V_3 -> V_7 . V_270 = F_29 ;
if ( ! V_3 -> V_7 . V_71 )
V_3 -> V_7 . V_71 = F_33 ;
if ( ! V_3 -> V_7 . V_271 )
V_3 -> V_7 . V_271 = F_78 ;
if ( ! V_3 -> V_7 . V_272 )
V_3 -> V_7 . V_272 = F_85 ;
if ( ! V_3 -> V_7 . V_72 )
V_3 -> V_7 . V_72 = F_10 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_5 , T_1 V_273 ,
const struct V_163 * V_252 ,
struct V_163 * V_164 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
T_1 V_167 ;
V_167 = F_47 ( V_252 -> V_175 ) ;
V_5 -> V_6 . V_13 = V_14 ;
if ( V_167 & V_156 )
V_5 -> V_6 . V_13 |= V_182 ;
if ( V_167 & V_158 )
V_5 -> V_6 . V_13 |= V_183 ;
if ( V_167 & V_176 )
V_5 -> V_22 |= V_177 ;
V_5 -> V_73 = V_181 ;
if ( ! ( V_3 -> V_155 & V_156 ) )
return 0 ;
V_164 -> V_169 |= V_252 -> V_169 & V_264 ;
V_167 = F_47 ( V_164 -> V_175 ) ;
V_164 -> V_175 = F_74 ( V_167 | V_3 -> V_155 ) ;
return V_172 ;
}
static int F_89 ( struct V_1 * V_5 , T_1 V_273 ,
const struct V_163 * V_252 ,
struct V_163 * V_164 )
{
if ( V_252 -> V_169 & V_264 )
return V_265 ;
return V_172 ;
}
int F_90 ( void )
{
V_90 = F_91 ( L_61 ) ;
if ( ! V_90 )
return - V_274 ;
return 0 ;
}
void F_92 ( void )
{
F_93 ( V_90 ) ;
}
void F_94 ( struct V_41 * V_42 )
{
struct V_59 * V_60 = V_42 -> V_74 ;
struct V_2 * V_3 = V_60 -> V_17 ;
V_3 -> V_7 . V_84 ( V_3 , 0 , V_42 -> V_4 ) ;
V_3 -> V_7 . V_84 ( V_3 , V_42 -> V_4 , 0 ) ;
}
