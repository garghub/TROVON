static struct V_1 * F_1 ( const struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 = NULL , * V_6 ;
F_2 () ;
F_3 (tmp_rdata, &lport->disc.rports, peers)
if ( V_6 -> V_7 . V_4 == V_4 &&
F_4 ( & V_6 -> V_8 ) ) {
V_5 = V_6 ;
break;
}
F_5 () ;
return V_5 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = V_3 -> V_9 . V_10 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( sizeof( * V_5 ) + V_3 -> V_11 , V_12 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_7 . V_13 = - 1 ;
V_5 -> V_7 . V_14 = - 1 ;
V_5 -> V_7 . V_4 = V_4 ;
V_5 -> V_7 . V_15 = V_16 ;
F_8 ( & V_5 -> V_8 ) ;
F_9 ( & V_5 -> V_17 ) ;
V_5 -> V_18 = V_3 ;
V_5 -> V_19 = V_20 ;
V_5 -> V_21 = V_22 ;
V_5 -> V_23 = V_24 ;
V_5 -> V_25 = V_3 -> V_25 ;
V_5 -> V_26 = V_3 -> V_26 ;
V_5 -> V_27 = V_28 ;
F_10 ( & V_5 -> V_29 , V_30 ) ;
F_11 ( & V_5 -> V_31 , V_32 ) ;
if ( V_4 != V_33 ) {
V_5 -> V_34 = V_3 -> V_9 . V_35 ;
F_12 ( & V_5 -> V_36 , & V_3 -> V_37 . V_38 ) ;
}
return V_5 ;
}
static void F_13 ( struct V_8 * V_8 )
{
struct V_1 * V_5 ;
V_5 = F_14 ( V_8 , struct V_1 , V_8 ) ;
F_15 ( V_5 , V_39 ) ;
}
static const char * F_16 ( struct V_1 * V_5 )
{
const char * V_40 ;
V_40 = V_41 [ V_5 -> V_19 ] ;
if ( ! V_40 )
V_40 = L_1 ;
return V_40 ;
}
void F_17 ( struct V_42 * V_43 , T_1 V_44 )
{
if ( V_44 )
V_43 -> V_45 = V_44 ;
else
V_43 -> V_45 = 1 ;
}
static unsigned int F_18 ( struct V_46 * V_47 ,
unsigned int V_48 )
{
unsigned int V_49 ;
V_49 = F_19 ( V_47 -> V_50 . V_51 ) & V_52 ;
if ( V_49 >= V_53 && V_49 < V_48 )
V_48 = V_49 ;
V_49 = F_19 ( V_47 -> V_54 [ 3 - 1 ] . V_55 ) ;
if ( V_49 >= V_53 && V_49 < V_48 )
V_48 = V_49 ;
return V_48 ;
}
static void F_20 ( struct V_1 * V_5 ,
enum F_16 V_56 )
{
if ( V_5 -> V_19 != V_56 )
V_5 -> V_57 = 0 ;
V_5 -> V_19 = V_56 ;
}
static void V_32 ( struct V_58 * V_59 )
{
T_1 V_4 ;
struct V_1 * V_5 =
F_14 ( V_59 , struct V_1 , V_31 ) ;
struct V_60 * V_61 ;
enum V_62 V_21 ;
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_63 * V_64 ;
struct V_65 V_7 ;
struct V_42 * V_43 ;
struct V_66 * V_67 ;
T_2 type ;
F_21 ( & V_5 -> V_17 ) ;
V_21 = V_5 -> V_21 ;
V_64 = V_5 -> V_68 ;
V_43 = V_5 -> V_43 ;
F_22 ( V_5 , L_2 , V_21 ) ;
switch ( V_21 ) {
case V_69 :
V_7 = V_5 -> V_7 ;
V_5 -> V_21 = V_22 ;
V_5 -> V_70 = 0 ;
F_23 ( & V_5 -> V_8 ) ;
F_24 ( & V_5 -> V_17 ) ;
if ( ! V_43 )
V_43 = F_25 ( V_3 -> V_71 , 0 , & V_7 ) ;
if ( ! V_43 ) {
F_22 ( V_5 , L_3 ) ;
V_3 -> V_9 . V_72 ( V_5 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
return;
}
F_21 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_43 )
F_22 ( V_5 , L_4 ) ;
V_5 -> V_43 = V_43 ;
V_43 -> V_27 = V_5 -> V_27 ;
V_43 -> V_74 = V_5 -> V_74 ;
V_61 = V_43 -> V_75 ;
V_61 -> V_18 = V_3 ;
V_61 -> V_19 = V_5 -> V_19 ;
V_61 -> V_23 = V_5 -> V_23 ;
V_61 -> V_25 = V_5 -> V_25 ;
V_61 -> V_26 = V_5 -> V_26 ;
F_24 ( & V_5 -> V_17 ) ;
if ( V_64 && V_64 -> V_76 ) {
F_22 ( V_5 , L_5 , V_21 ) ;
V_64 -> V_76 ( V_3 , V_5 , V_21 ) ;
}
if ( V_5 -> V_34 ) {
F_22 ( V_5 , L_6 , V_21 ) ;
V_5 -> V_34 ( V_3 , V_5 , V_21 ) ;
}
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
break;
case V_77 :
case V_78 :
case V_79 :
if ( V_5 -> V_80 ) {
F_21 ( & V_81 ) ;
for ( type = 1 ; type < V_82 ; type ++ ) {
V_67 = V_83 [ type ] ;
if ( V_67 && V_67 -> V_84 )
V_67 -> V_84 ( V_5 ) ;
}
F_24 ( & V_81 ) ;
}
V_4 = V_5 -> V_7 . V_4 ;
F_24 ( & V_5 -> V_17 ) ;
if ( V_64 && V_64 -> V_76 ) {
F_22 ( V_5 , L_5 , V_21 ) ;
V_64 -> V_76 ( V_3 , V_5 , V_21 ) ;
}
if ( V_5 -> V_34 ) {
F_22 ( V_5 , L_6 , V_21 ) ;
V_5 -> V_34 ( V_3 , V_5 , V_21 ) ;
}
F_27 ( & V_5 -> V_29 ) ;
V_3 -> V_9 . V_85 ( V_3 , 0 , V_4 ) ;
V_3 -> V_9 . V_85 ( V_3 , V_4 , 0 ) ;
if ( V_43 ) {
V_61 = V_43 -> V_75 ;
V_61 -> V_19 = V_86 ;
F_21 ( & V_5 -> V_17 ) ;
V_5 -> V_43 = NULL ;
F_24 ( & V_5 -> V_17 ) ;
F_28 ( V_43 ) ;
}
F_21 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_19 == V_86 ) {
if ( V_4 == V_33 ) {
V_5 -> V_21 = V_22 ;
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
} else if ( ( V_5 -> V_23 & V_87 ) &&
V_5 -> V_70 <
V_3 -> V_88 ) {
V_5 -> V_70 ++ ;
V_5 -> V_21 = V_22 ;
F_22 ( V_5 , L_7 ) ;
F_29 ( V_5 ) ;
F_24 ( & V_5 -> V_17 ) ;
} else {
F_22 ( V_5 , L_8 ) ;
F_30 ( & V_5 -> V_36 ) ;
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
}
} else {
V_5 -> V_21 = V_22 ;
if ( V_5 -> V_19 == V_89 )
F_31 ( V_5 ) ;
F_24 ( & V_5 -> V_17 ) ;
}
break;
default:
F_24 ( & V_5 -> V_17 ) ;
break;
}
}
static int F_32 ( struct V_1 * V_5 )
{
F_21 ( & V_5 -> V_17 ) ;
V_5 -> V_23 |= V_87 ;
switch ( V_5 -> V_19 ) {
case V_89 :
F_22 ( V_5 , L_9 ) ;
F_33 ( V_5 ) ;
break;
case V_86 :
F_22 ( V_5 , L_10 ) ;
break;
default:
F_22 ( V_5 , L_11 ) ;
F_29 ( V_5 ) ;
break;
}
F_24 ( & V_5 -> V_17 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_5 ,
enum V_62 V_21 )
{
if ( V_5 -> V_19 == V_86 )
return;
F_22 ( V_5 , L_12 ) ;
F_20 ( V_5 , V_86 ) ;
if ( V_5 -> V_21 == V_22 )
F_35 ( V_90 , & V_5 -> V_31 ) ;
V_5 -> V_21 = V_21 ;
}
static int F_36 ( struct V_1 * V_5 )
{
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_13 ) ;
V_5 -> V_23 &= ~ V_87 ;
if ( V_5 -> V_19 == V_86 ) {
F_22 ( V_5 , L_14 ) ;
goto V_91;
}
F_37 ( V_5 ) ;
F_34 ( V_5 , V_79 ) ;
V_91:
F_24 ( & V_5 -> V_17 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_5 )
{
F_20 ( V_5 , V_89 ) ;
F_22 ( V_5 , L_15 ) ;
if ( V_5 -> V_21 == V_22 )
F_35 ( V_90 , & V_5 -> V_31 ) ;
V_5 -> V_21 = V_69 ;
}
static void V_30 ( struct V_58 * V_59 )
{
struct V_1 * V_5 =
F_14 ( V_59 , struct V_1 , V_29 . V_59 ) ;
F_21 ( & V_5 -> V_17 ) ;
switch ( V_5 -> V_19 ) {
case V_92 :
F_29 ( V_5 ) ;
break;
case V_93 :
F_38 ( V_5 ) ;
break;
case V_94 :
F_39 ( V_5 ) ;
break;
case V_95 :
F_40 ( V_5 ) ;
break;
case V_96 :
F_33 ( V_5 ) ;
break;
case V_97 :
case V_89 :
case V_20 :
case V_86 :
break;
}
F_24 ( & V_5 -> V_17 ) ;
}
static void F_41 ( struct V_1 * V_5 , struct V_98 * V_99 )
{
F_22 ( V_5 , L_16 ,
F_42 ( V_99 ) ? - F_43 ( V_99 ) : 0 ,
F_16 ( V_5 ) , V_5 -> V_57 ) ;
switch ( V_5 -> V_19 ) {
case V_92 :
case V_93 :
V_5 -> V_23 &= ~ V_87 ;
F_34 ( V_5 , V_77 ) ;
break;
case V_95 :
F_31 ( V_5 ) ;
break;
case V_94 :
case V_96 :
F_37 ( V_5 ) ;
break;
case V_97 :
case V_86 :
case V_89 :
case V_20 :
break;
}
}
static void F_44 ( struct V_1 * V_5 ,
struct V_98 * V_99 )
{
unsigned long V_100 = F_45 ( V_101 ) ;
if ( F_43 ( V_99 ) == - V_102 )
goto V_91;
if ( V_5 -> V_57 < V_5 -> V_18 -> V_88 ) {
F_22 ( V_5 , L_17 ,
F_43 ( V_99 ) , F_16 ( V_5 ) ) ;
V_5 -> V_57 ++ ;
if ( F_43 ( V_99 ) == - V_103 )
V_100 = 0 ;
F_46 ( & V_5 -> V_29 , V_100 ) ;
return;
}
V_91:
F_41 ( V_5 , V_99 ) ;
}
static int F_47 ( struct V_1 * V_5 ,
struct V_98 * V_99 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_46 * V_104 ;
unsigned int V_25 ;
T_3 V_105 ;
V_104 = F_48 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
return - V_106 ;
V_105 = F_19 ( V_104 -> V_50 . V_107 ) ;
if ( F_49 ( V_99 ) == V_108 ) {
if ( V_105 & V_109 ) {
F_22 ( V_5 , L_18 ) ;
return - V_106 ;
}
} else {
V_25 = F_50 ( V_104 -> V_50 . V_110 ) ;
if ( V_105 & V_111 )
V_25 /= 1000000 ;
if ( V_25 > V_5 -> V_25 )
V_5 -> V_25 = V_25 ;
}
V_5 -> V_27 = F_18 ( V_104 , V_3 -> V_49 ) ;
return 0 ;
}
static void F_51 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_114 )
{
struct V_1 * V_5 = V_114 ;
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_46 * V_104 ;
unsigned int V_26 ;
F_22 ( V_5 , L_19 , F_52 ( V_99 ) ) ;
if ( V_99 == F_53 ( - V_102 ) )
goto V_115;
F_21 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_19 != V_92 ) {
F_22 ( V_5 , L_20
L_21 , F_16 ( V_5 ) ) ;
if ( F_42 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_42 ( V_99 ) ) {
F_41 ( V_5 , V_99 ) ;
goto V_116;
}
if ( F_49 ( V_99 ) != V_117 )
goto V_118;
if ( F_47 ( V_5 , V_99 ) )
goto V_118;
V_104 = F_48 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
goto V_118;
V_26 = F_50 ( V_104 -> V_50 . V_119 ) ;
if ( V_26 > V_5 -> V_26 )
V_5 -> V_26 = V_26 ;
if ( V_5 -> V_7 . V_14 < V_3 -> V_120 )
F_38 ( V_5 ) ;
else
F_20 ( V_5 , V_97 ) ;
V_91:
F_54 ( V_99 ) ;
V_116:
F_24 ( & V_5 -> V_17 ) ;
V_115:
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
return;
V_118:
F_22 ( V_5 , L_22 ) ;
F_44 ( V_5 , V_99 ) ;
goto V_91;
}
static void F_29 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
if ( ! V_3 -> V_121 )
return F_38 ( V_5 ) ;
F_22 ( V_5 , L_23 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_92 ) ;
V_99 = F_55 ( V_3 , sizeof( struct V_46 ) ) ;
if ( ! V_99 )
return F_44 ( V_5 , V_99 ) ;
if ( ! V_3 -> V_9 . V_122 ( V_3 , V_5 -> V_7 . V_4 , V_99 , V_108 ,
F_51 , V_5 ,
2 * V_3 -> V_26 ) )
F_44 ( V_5 , NULL ) ;
else
F_23 ( & V_5 -> V_8 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_37 ;
struct V_46 * V_47 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_57 ( V_99 ) ;
F_58 ( V_3 , V_127 , L_24 ) ;
V_37 = & V_3 -> V_37 ;
if ( ! V_3 -> V_121 ) {
V_126 . V_128 = V_129 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_47 = F_48 ( V_99 , sizeof( * V_47 ) ) ;
if ( ! V_47 ) {
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_134 ;
goto V_132;
}
V_5 = V_3 -> V_9 . V_10 ( V_3 , V_127 ) ;
if ( ! V_5 ) {
V_126 . V_128 = V_135 ;
V_126 . V_130 = V_136 ;
goto V_132;
}
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_25 ,
F_16 ( V_5 ) ) ;
switch ( V_5 -> V_19 ) {
case V_20 :
if ( V_3 -> V_121 )
break;
case V_86 :
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_135 ;
V_126 . V_130 = V_136 ;
goto V_137;
case V_92 :
case V_97 :
case V_93 :
break;
case V_94 :
case V_95 :
case V_89 :
case V_96 :
F_34 ( V_5 , V_78 ) ;
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_138 ;
V_126 . V_130 = V_131 ;
goto V_137;
}
if ( F_47 ( V_5 , V_99 ) ) {
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_131 ;
goto V_137;
}
V_99 = F_55 ( V_3 , sizeof( * V_47 ) ) ;
if ( ! V_99 )
goto V_91;
F_59 ( V_3 , V_99 ) ;
V_47 = F_48 ( V_99 , sizeof( * V_47 ) ) ;
V_47 -> V_139 = V_117 ;
F_60 ( V_99 , V_123 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
if ( V_5 -> V_7 . V_14 < V_3 -> V_120 )
F_38 ( V_5 ) ;
else
F_20 ( V_5 , V_97 ) ;
V_91:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
F_54 ( V_123 ) ;
return;
V_137:
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
V_132:
V_3 -> V_9 . V_142 ( V_123 , V_143 , & V_126 ) ;
F_54 ( V_123 ) ;
}
static void F_61 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_144 )
{
struct V_1 * V_5 = V_144 ;
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_46 * V_145 = NULL ;
T_3 V_146 ;
T_3 V_147 ;
T_2 V_148 ;
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_26 , F_52 ( V_99 ) ) ;
if ( V_5 -> V_19 != V_93 ) {
F_22 ( V_5 , L_27
L_21 , F_16 ( V_5 ) ) ;
if ( F_42 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_42 ( V_99 ) ) {
F_44 ( V_5 , V_99 ) ;
goto V_116;
}
V_148 = F_49 ( V_99 ) ;
if ( V_148 == V_117 &&
( V_145 = F_48 ( V_99 , sizeof( * V_145 ) ) ) != NULL ) {
V_5 -> V_7 . V_14 = F_62 ( & V_145 -> V_149 ) ;
V_5 -> V_7 . V_13 = F_62 ( & V_145 -> V_150 ) ;
V_5 -> V_107 = F_19 ( V_145 -> V_50 . V_107 ) ;
if ( V_3 -> V_121 )
F_47 ( V_5 , V_99 ) ;
V_146 = F_19 ( V_145 -> V_50 . V_151 ) ;
V_147 = F_19 ( V_145 -> V_54 [ 3 - 1 ] . V_152 ) ;
if ( V_147 < V_146 )
V_146 = V_147 ;
V_5 -> V_153 = V_146 ;
V_5 -> V_27 = F_18 ( V_145 , V_3 -> V_49 ) ;
F_39 ( V_5 ) ;
} else
F_44 ( V_5 , V_99 ) ;
V_91:
F_54 ( V_99 ) ;
V_116:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
}
static bool
F_63 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_15 == V_154 )
return true ;
if ( ( V_5 -> V_7 . V_15 & V_155 ) &&
( V_3 -> V_156 & V_157 ) )
return true ;
if ( ( V_5 -> V_7 . V_15 & V_158 ) &&
( V_3 -> V_156 & V_159 ) )
return true ;
return false ;
}
static void F_38 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
if ( ! F_63 ( V_3 , V_5 ) ) {
F_22 ( V_5 , L_28 ) ;
F_20 ( V_5 , V_97 ) ;
return;
}
F_22 ( V_5 , L_29 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_93 ) ;
V_5 -> V_27 = V_28 ;
V_99 = F_55 ( V_3 , sizeof( struct V_46 ) ) ;
if ( ! V_99 ) {
F_22 ( V_5 , L_30 , V_160 ) ;
F_44 ( V_5 , V_99 ) ;
return;
}
V_5 -> V_25 = V_3 -> V_25 ;
if ( ! V_3 -> V_9 . V_122 ( V_3 , V_5 -> V_7 . V_4 , V_99 , V_161 ,
F_61 , V_5 ,
2 * V_3 -> V_26 ) )
F_44 ( V_5 , NULL ) ;
else
F_23 ( & V_5 -> V_8 ) ;
}
static void F_64 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_144 )
{
struct V_1 * V_5 = V_144 ;
struct {
struct V_162 V_163 ;
struct V_164 V_165 ;
} * V_166 ;
struct V_164 V_167 ;
struct V_66 * V_67 ;
T_1 V_15 = V_16 ;
T_1 V_168 = 0 ;
T_2 V_148 ;
T_2 V_169 = 0 ;
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_31 , F_52 ( V_99 ) ) ;
if ( V_5 -> V_19 != V_94 ) {
F_22 ( V_5 , L_32
L_21 , F_16 ( V_5 ) ) ;
if ( F_42 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_42 ( V_99 ) ) {
F_44 ( V_5 , V_99 ) ;
goto V_116;
}
V_5 -> V_7 . V_15 = V_16 ;
V_148 = F_49 ( V_99 ) ;
if ( V_148 == V_117 ) {
V_166 = F_48 ( V_99 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
goto V_91;
V_169 = ( V_166 -> V_165 . V_170 & V_171 ) ;
F_22 ( V_5 , L_33 ,
V_166 -> V_165 . V_170 ) ;
V_5 -> V_172 = V_166 -> V_165 . V_172 ;
if ( V_169 != V_173 ) {
if ( V_169 == V_174 )
F_41 ( V_5 , V_99 ) ;
else
F_44 ( V_5 , V_99 ) ;
goto V_91;
}
if ( V_166 -> V_163 . V_175 < sizeof( V_166 -> V_165 ) )
goto V_91;
V_168 = F_50 ( V_166 -> V_165 . V_176 ) ;
if ( V_168 & V_177 )
V_5 -> V_23 |= V_178 ;
if ( V_168 & V_179 )
V_5 -> V_23 |= V_180 ;
V_67 = V_83 [ V_181 ] ;
if ( V_67 ) {
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_67 -> V_163 ( V_5 , V_166 -> V_163 . V_175 ,
& V_166 -> V_165 , & V_167 ) ;
}
V_5 -> V_74 = V_182 ;
if ( V_168 & V_157 )
V_15 |= V_183 ;
if ( V_168 & V_159 )
V_15 |= V_184 ;
V_5 -> V_7 . V_15 = V_15 ;
F_40 ( V_5 ) ;
} else {
F_22 ( V_5 , L_34 ) ;
F_44 ( V_5 , V_99 ) ;
}
V_91:
F_54 ( V_99 ) ;
V_116:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_5 -> V_18 -> V_9 . V_73 ) ;
}
static void F_39 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct {
struct V_162 V_163 ;
struct V_164 V_165 ;
} * V_166 ;
struct V_98 * V_99 ;
struct V_66 * V_67 ;
if ( V_5 -> V_7 . V_4 >= V_185 ) {
F_31 ( V_5 ) ;
return;
}
F_22 ( V_5 , L_35 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_94 ) ;
V_99 = F_55 ( V_3 , sizeof( * V_166 ) ) ;
if ( ! V_99 ) {
F_44 ( V_5 , V_99 ) ;
return;
}
F_65 ( V_3 , V_99 ) ;
V_67 = V_83 [ V_181 ] ;
if ( V_67 ) {
V_166 = F_48 ( V_99 , sizeof( * V_166 ) ) ;
V_67 -> V_163 ( V_5 , sizeof( V_166 -> V_165 ) , NULL , & V_166 -> V_165 ) ;
}
F_66 ( V_99 , V_186 , V_5 -> V_7 . V_4 ,
F_67 ( V_3 -> V_71 ) , V_187 ,
V_188 | V_189 | V_190 , 0 ) ;
if ( ! V_3 -> V_9 . V_191 ( V_3 , V_99 , F_64 ,
NULL , V_5 , 2 * V_3 -> V_26 ) )
F_44 ( V_5 , NULL ) ;
else
F_23 ( & V_5 -> V_8 ) ;
}
static void F_68 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_144 )
{
struct V_1 * V_5 = V_144 ;
T_2 V_148 ;
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_36 , F_52 ( V_99 ) ) ;
if ( V_5 -> V_19 != V_95 ) {
F_22 ( V_5 , L_37
L_21 , F_16 ( V_5 ) ) ;
if ( F_42 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_42 ( V_99 ) ) {
F_41 ( V_5 , V_99 ) ;
goto V_116;
}
V_148 = F_49 ( V_99 ) ;
if ( V_148 == V_117 ) {
struct V_192 * V_193 ;
T_1 V_194 ;
T_1 V_195 ;
V_193 = F_48 ( V_99 , sizeof( * V_193 ) ) ;
if ( V_193 ) {
V_194 = F_50 ( V_193 -> V_196 ) ;
V_195 = F_50 ( V_193 -> V_197 ) ;
if ( V_195 == 0 )
V_195 = 1 ;
V_5 -> V_26 = V_195 ;
V_195 = F_50 ( V_193 -> V_198 ) ;
if ( V_194 & V_199 )
V_195 /= 1000000 ;
if ( V_195 == 0 )
V_195 = 1 ;
V_5 -> V_25 = V_195 ;
}
}
F_31 ( V_5 ) ;
V_91:
F_54 ( V_99 ) ;
V_116:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_5 -> V_18 -> V_9 . V_73 ) ;
}
static void F_40 ( struct V_1 * V_5 )
{
struct V_98 * V_99 ;
struct V_2 * V_3 = V_5 -> V_18 ;
F_22 ( V_5 , L_38 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_95 ) ;
V_99 = F_55 ( V_3 , sizeof( struct V_200 ) ) ;
if ( ! V_99 ) {
F_44 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_9 . V_122 ( V_3 , V_5 -> V_7 . V_4 , V_99 , V_201 ,
F_68 , V_5 ,
2 * V_3 -> V_26 ) )
F_44 ( V_5 , NULL ) ;
else
F_23 ( & V_5 -> V_8 ) ;
}
static void F_69 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_202 )
{
struct V_2 * V_3 = V_202 ;
F_58 ( V_3 , F_70 ( V_113 ) -> V_203 ,
L_39 , F_52 ( V_99 ) ) ;
if ( F_42 ( V_99 ) )
return;
F_54 ( V_99 ) ;
}
static void F_37 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
F_22 ( V_5 , L_40 ,
F_16 ( V_5 ) ) ;
V_99 = F_55 ( V_3 , sizeof( struct V_204 ) ) ;
if ( ! V_99 )
return;
( void ) V_3 -> V_9 . V_122 ( V_3 , V_5 -> V_7 . V_4 , V_99 , V_205 ,
F_69 , V_3 , 0 ) ;
}
static void F_71 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_144 )
{
struct V_1 * V_5 = V_144 ;
struct V_206 * V_207 ;
T_2 V_148 ;
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_41 ) ;
if ( V_5 -> V_19 != V_96 ) {
F_22 ( V_5 , L_42 ,
F_16 ( V_5 ) ) ;
if ( F_42 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_42 ( V_99 ) ) {
F_41 ( V_5 , V_99 ) ;
goto V_116;
}
V_148 = F_49 ( V_99 ) ;
V_207 = F_48 ( V_99 , sizeof( * V_207 ) ) ;
if ( V_148 != V_117 || ! V_207 ||
F_72 ( V_207 -> V_208 ) != V_5 -> V_7 . V_4 ||
F_62 ( & V_207 -> V_209 ) != V_5 -> V_7 . V_14 ||
F_62 ( & V_207 -> V_210 ) != V_5 -> V_7 . V_13 ) {
F_22 ( V_5 , L_43 ) ;
F_29 ( V_5 ) ;
} else {
F_22 ( V_5 , L_44 ) ;
F_31 ( V_5 ) ;
}
V_91:
F_54 ( V_99 ) ;
V_116:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_5 -> V_18 -> V_9 . V_73 ) ;
}
static void F_33 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
F_22 ( V_5 , L_45 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_96 ) ;
V_99 = F_55 ( V_3 , sizeof( struct V_206 ) ) ;
if ( ! V_99 ) {
F_44 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_9 . V_122 ( V_3 , V_5 -> V_7 . V_4 , V_99 , V_211 ,
F_71 , V_5 ,
2 * V_3 -> V_26 ) )
F_44 ( V_5 , NULL ) ;
else
F_23 ( & V_5 -> V_8 ) ;
}
static void F_73 ( struct V_1 * V_5 ,
struct V_98 * V_212 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
struct V_206 * V_207 ;
struct V_125 V_126 ;
F_22 ( V_5 , L_46 ) ;
V_207 = F_48 ( V_212 , sizeof( * V_207 ) ) ;
if ( ! V_207 ) {
V_126 . V_128 = V_213 ;
V_126 . V_130 = V_134 ;
V_3 -> V_9 . V_142 ( V_212 , V_143 , & V_126 ) ;
goto V_214;
}
V_99 = F_55 ( V_3 , sizeof( * V_207 ) ) ;
if ( ! V_99 )
goto V_214;
F_74 ( V_3 , V_99 ) ;
V_207 = F_48 ( V_99 , sizeof( * V_207 ) ) ;
V_207 -> V_215 = V_117 ;
F_60 ( V_99 , V_212 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
V_214:
F_54 ( V_212 ) ;
}
static void F_75 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
struct V_125 V_126 ;
struct V_222 * V_223 ;
F_22 ( V_5 , L_47 ,
F_16 ( V_5 ) ) ;
V_217 = F_48 ( V_123 , sizeof( * V_217 ) ) ;
if ( ! V_217 ) {
V_126 . V_128 = V_213 ;
V_126 . V_130 = V_134 ;
goto V_224;
}
V_99 = F_55 ( V_3 , sizeof( * V_219 ) ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_225 ;
V_126 . V_130 = V_226 ;
goto V_224;
}
V_219 = F_48 ( V_99 , sizeof( * V_219 ) ) ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_219 -> V_227 = V_117 ;
V_221 = & V_219 -> V_228 ;
if ( V_3 -> V_9 . V_229 ) {
V_3 -> V_9 . V_229 ( V_3 , V_221 ) ;
} else {
F_76 ( V_3 -> V_71 ) ;
V_223 = & V_3 -> V_230 ;
V_221 -> V_231 = F_77 ( V_223 -> V_232 ) ;
V_221 -> V_233 = F_77 ( V_223 -> V_234 ) ;
V_221 -> V_235 = F_77 ( V_223 -> V_236 ) ;
V_221 -> V_237 = F_77 ( V_223 -> V_238 ) ;
V_221 -> V_239 = F_77 ( V_223 -> V_240 ) ;
V_221 -> V_241 = F_77 ( V_223 -> V_242 ) ;
}
F_60 ( V_99 , V_123 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
goto V_91;
V_224:
V_3 -> V_9 . V_142 ( V_123 , V_143 , & V_126 ) ;
V_91:
F_54 ( V_123 ) ;
}
static void F_78 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
struct V_125 V_243 ;
V_5 = V_3 -> V_9 . V_10 ( V_3 , F_57 ( V_99 ) ) ;
if ( ! V_5 )
goto V_132;
F_21 ( & V_5 -> V_17 ) ;
switch ( V_5 -> V_19 ) {
case V_94 :
case V_95 :
case V_89 :
case V_96 :
break;
default:
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_3 -> V_9 . V_73 ) ;
goto V_132;
}
switch ( F_49 ( V_99 ) ) {
case V_244 :
F_79 ( V_5 , V_99 ) ;
break;
case V_245 :
F_80 ( V_5 , V_99 ) ;
break;
case V_211 :
F_73 ( V_5 , V_99 ) ;
break;
case V_246 :
V_3 -> V_9 . V_142 ( V_99 , V_246 , NULL ) ;
F_54 ( V_99 ) ;
break;
case V_247 :
V_3 -> V_9 . V_142 ( V_99 , V_247 , NULL ) ;
F_54 ( V_99 ) ;
break;
case V_248 :
F_75 ( V_5 , V_99 ) ;
break;
default:
F_54 ( V_99 ) ;
break;
}
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_5 -> V_18 -> V_9 . V_73 ) ;
return;
V_132:
V_243 . V_128 = V_225 ;
V_243 . V_130 = V_249 ;
V_3 -> V_9 . V_142 ( V_99 , V_143 , & V_243 ) ;
F_54 ( V_99 ) ;
}
static void F_81 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_125 V_243 ;
switch ( F_49 ( V_99 ) ) {
case V_108 :
F_56 ( V_3 , V_99 ) ;
break;
case V_161 :
F_82 ( V_3 , V_99 ) ;
break;
case V_205 :
F_83 ( V_3 , V_99 ) ;
break;
case V_244 :
case V_245 :
case V_211 :
case V_246 :
case V_247 :
case V_248 :
F_78 ( V_3 , V_99 ) ;
break;
default:
V_243 . V_128 = V_129 ;
V_243 . V_130 = V_131 ;
V_3 -> V_9 . V_142 ( V_99 , V_143 , & V_243 ) ;
F_54 ( V_99 ) ;
break;
}
}
static void F_82 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_37 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_46 * V_250 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_57 ( V_99 ) ;
F_58 ( V_3 , V_127 , L_48 ) ;
V_250 = F_48 ( V_99 , sizeof( * V_250 ) ) ;
if ( ! V_250 ) {
F_58 ( V_3 , V_127 , L_49 ) ;
V_126 . V_128 = V_213 ;
V_126 . V_130 = V_134 ;
goto V_132;
}
V_37 = & V_3 -> V_37 ;
F_21 ( & V_37 -> V_251 ) ;
V_5 = V_3 -> V_9 . V_252 ( V_3 , V_127 ) ;
if ( ! V_5 ) {
F_24 ( & V_37 -> V_251 ) ;
V_126 . V_128 = V_225 ;
V_126 . V_130 = V_226 ;
goto V_132;
}
F_21 ( & V_5 -> V_17 ) ;
F_24 ( & V_37 -> V_251 ) ;
V_5 -> V_7 . V_14 = F_62 ( & V_250 -> V_149 ) ;
V_5 -> V_7 . V_13 = F_62 ( & V_250 -> V_150 ) ;
switch ( V_5 -> V_19 ) {
case V_20 :
F_22 ( V_5 , L_50 ) ;
break;
case V_97 :
F_22 ( V_5 , L_51 ) ;
break;
case V_93 :
F_22 ( V_5 , L_52 ) ;
if ( V_5 -> V_7 . V_14 < V_3 -> V_120 ) {
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_253 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
break;
case V_94 :
case V_95 :
case V_89 :
case V_96 :
F_22 ( V_5 , L_53
L_54 , V_5 -> V_19 ) ;
break;
case V_92 :
case V_86 :
F_22 ( V_5 , L_55 ,
F_16 ( V_5 ) ) ;
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_138 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
if ( ! F_63 ( V_3 , V_5 ) ) {
F_22 ( V_5 , L_56 ) ;
F_24 ( & V_5 -> V_17 ) ;
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_5 -> V_27 = F_18 ( V_250 , V_3 -> V_49 ) ;
V_99 = F_55 ( V_3 , sizeof( * V_250 ) ) ;
if ( ! V_99 )
goto V_91;
F_84 ( V_3 , V_99 , V_117 ) ;
F_60 ( V_99 , V_123 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
F_39 ( V_5 ) ;
V_91:
F_24 ( & V_5 -> V_17 ) ;
F_54 ( V_123 ) ;
return;
V_132:
V_3 -> V_9 . V_142 ( V_99 , V_143 , & V_126 ) ;
F_54 ( V_99 ) ;
}
static void F_79 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
struct {
struct V_162 V_163 ;
struct V_164 V_165 ;
} * V_166 ;
struct V_164 * V_254 ;
struct V_164 * V_165 ;
unsigned int V_255 ;
unsigned int V_256 ;
enum V_257 V_258 ;
enum V_257 V_259 ;
struct V_125 V_126 ;
struct V_66 * V_67 ;
F_22 ( V_5 , L_57 ,
F_16 ( V_5 ) ) ;
V_255 = F_85 ( V_123 ) - sizeof( struct V_260 ) ;
V_166 = F_48 ( V_123 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
goto V_261;
V_256 = F_19 ( V_166 -> V_163 . V_262 ) ;
if ( ( V_256 % 4 ) != 0 || V_256 > V_255 || V_256 < 16 )
goto V_261;
if ( V_256 < V_255 )
V_255 = V_256 ;
V_256 = V_166 -> V_163 . V_175 ;
if ( ( V_256 % 4 ) != 0 || V_256 < sizeof( * V_165 ) ||
V_256 > V_255 || V_255 < sizeof( * V_166 ) || V_256 < 12 )
goto V_261;
V_254 = & V_166 -> V_165 ;
V_99 = F_55 ( V_3 , V_255 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_225 ;
V_126 . V_130 = V_226 ;
goto V_132;
}
V_166 = F_48 ( V_99 , V_255 ) ;
F_86 ( ! V_166 ) ;
memset ( V_166 , 0 , V_255 ) ;
V_166 -> V_163 . V_263 = V_117 ;
V_166 -> V_163 . V_175 = V_256 ;
V_166 -> V_163 . V_262 = F_87 ( V_255 ) ;
V_255 -= sizeof( struct V_162 ) ;
V_165 = & V_166 -> V_165 ;
F_21 ( & V_81 ) ;
while ( V_255 >= V_256 ) {
V_5 -> V_172 = V_254 -> V_172 ;
V_165 -> V_172 = V_254 -> V_172 ;
V_165 -> V_264 = V_254 -> V_264 ;
V_258 = 0 ;
if ( V_254 -> V_172 < V_82 ) {
V_67 = V_265 [ V_254 -> V_172 ] ;
if ( V_67 )
V_258 = V_67 -> V_163 ( V_5 , V_256 , V_254 , V_165 ) ;
V_67 = V_83 [ V_254 -> V_172 ] ;
if ( V_67 ) {
V_259 = V_67 -> V_163 ( V_5 , V_256 , V_254 , V_165 ) ;
if ( ! V_258 || V_259 == V_173 )
V_258 = V_259 ;
}
}
if ( ! V_258 ) {
if ( V_165 -> V_170 & V_266 )
V_258 |= V_174 ;
else
V_258 |= V_267 ;
}
V_165 -> V_170 |= V_258 ;
V_255 -= V_256 ;
V_254 = (struct V_164 * ) ( ( char * ) V_254 + V_256 ) ;
V_165 = (struct V_164 * ) ( ( char * ) V_165 + V_256 ) ;
}
F_24 ( & V_81 ) ;
F_60 ( V_99 , V_123 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
switch ( V_5 -> V_19 ) {
case V_94 :
F_31 ( V_5 ) ;
break;
default:
break;
}
goto V_214;
V_261:
V_126 . V_128 = V_213 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_9 . V_142 ( V_123 , V_143 , & V_126 ) ;
V_214:
F_54 ( V_123 ) ;
}
static void F_80 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
struct V_98 * V_99 ;
struct {
struct V_268 V_84 ;
struct V_164 V_165 ;
} * V_166 ;
struct V_164 * V_254 ;
struct V_164 * V_165 ;
unsigned int V_255 ;
unsigned int V_256 ;
struct V_125 V_126 ;
F_22 ( V_5 , L_58 ,
F_16 ( V_5 ) ) ;
V_255 = F_85 ( V_123 ) - sizeof( struct V_260 ) ;
V_166 = F_48 ( V_123 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
goto V_261;
V_256 = F_19 ( V_166 -> V_84 . V_269 ) ;
if ( V_256 != 20 )
goto V_261;
if ( V_256 < V_255 )
V_255 = V_256 ;
V_254 = & V_166 -> V_165 ;
V_99 = F_55 ( V_3 , V_255 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_225 ;
V_126 . V_130 = V_226 ;
goto V_132;
}
V_166 = F_48 ( V_99 , V_255 ) ;
F_86 ( ! V_166 ) ;
memset ( V_166 , 0 , V_255 ) ;
V_166 -> V_84 . V_270 = V_117 ;
V_166 -> V_84 . V_271 = 0x10 ;
V_166 -> V_84 . V_269 = F_87 ( V_255 ) ;
V_165 = & V_166 -> V_165 ;
V_165 -> V_172 = V_254 -> V_172 ;
V_165 -> V_264 = V_254 -> V_264 ;
V_165 -> V_170 = V_173 ;
F_34 ( V_5 , V_78 ) ;
F_60 ( V_99 , V_123 , V_140 , 0 ) ;
V_3 -> V_9 . V_141 ( V_3 , V_99 ) ;
goto V_214;
V_261:
V_126 . V_128 = V_213 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_9 . V_142 ( V_123 , V_143 , & V_126 ) ;
V_214:
F_54 ( V_123 ) ;
}
static void F_83 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
T_1 V_127 ;
V_3 -> V_9 . V_142 ( V_99 , V_117 , NULL ) ;
V_127 = F_57 ( V_99 ) ;
V_5 = V_3 -> V_9 . V_10 ( V_3 , V_127 ) ;
if ( V_5 ) {
F_21 ( & V_5 -> V_17 ) ;
F_22 ( V_5 , L_59 ,
F_16 ( V_5 ) ) ;
F_34 ( V_5 , V_78 ) ;
F_24 ( & V_5 -> V_17 ) ;
F_26 ( & V_5 -> V_8 , V_5 -> V_18 -> V_9 . V_73 ) ;
} else
F_58 ( V_3 , V_127 ,
L_60 ) ;
F_54 ( V_99 ) ;
}
static void F_88 ( void )
{
F_89 ( V_90 ) ;
}
int F_90 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_9 . V_10 )
V_3 -> V_9 . V_10 = F_1 ;
if ( ! V_3 -> V_9 . V_252 )
V_3 -> V_9 . V_252 = F_6 ;
if ( ! V_3 -> V_9 . V_272 )
V_3 -> V_9 . V_272 = F_32 ;
if ( ! V_3 -> V_9 . V_72 )
V_3 -> V_9 . V_72 = F_36 ;
if ( ! V_3 -> V_9 . V_273 )
V_3 -> V_9 . V_273 = F_81 ;
if ( ! V_3 -> V_9 . V_274 )
V_3 -> V_9 . V_274 = F_88 ;
if ( ! V_3 -> V_9 . V_73 )
V_3 -> V_9 . V_73 = F_13 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_5 , T_1 V_275 ,
const struct V_164 * V_254 ,
struct V_164 * V_165 )
{
struct V_2 * V_3 = V_5 -> V_18 ;
T_1 V_168 ;
V_168 = F_50 ( V_254 -> V_176 ) ;
V_5 -> V_7 . V_15 = V_16 ;
if ( V_168 & V_157 )
V_5 -> V_7 . V_15 |= V_183 ;
if ( V_168 & V_159 )
V_5 -> V_7 . V_15 |= V_184 ;
if ( V_168 & V_177 )
V_5 -> V_23 |= V_178 ;
V_5 -> V_74 = V_182 ;
if ( ! ( V_3 -> V_156 & V_157 ) )
return 0 ;
V_165 -> V_170 |= V_254 -> V_170 & V_266 ;
V_168 = F_50 ( V_165 -> V_176 ) ;
V_165 -> V_176 = F_77 ( V_168 | V_3 -> V_156 ) ;
return V_173 ;
}
static int F_92 ( struct V_1 * V_5 , T_1 V_275 ,
const struct V_164 * V_254 ,
struct V_164 * V_165 )
{
if ( V_254 -> V_170 & V_266 )
return V_267 ;
return V_173 ;
}
int F_93 ( void )
{
V_90 = F_94 ( L_61 ) ;
if ( ! V_90 )
return - V_276 ;
return 0 ;
}
void F_95 ( void )
{
F_96 ( V_90 ) ;
}
void F_97 ( struct V_42 * V_43 )
{
struct V_60 * V_61 = V_43 -> V_75 ;
struct V_2 * V_3 = V_61 -> V_18 ;
V_3 -> V_9 . V_85 ( V_3 , 0 , V_43 -> V_4 ) ;
V_3 -> V_9 . V_85 ( V_3 , V_43 -> V_4 , 0 ) ;
}
