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
int F_29 ( struct V_1 * V_5 )
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
int F_33 ( struct V_1 * V_5 )
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
unsigned long V_100 = V_101 ;
if ( F_40 ( V_99 ) == - V_102 )
goto V_91;
if ( V_5 -> V_56 < V_5 -> V_17 -> V_88 ) {
F_19 ( V_5 , L_17 ,
F_40 ( V_99 ) , F_13 ( V_5 ) ) ;
V_5 -> V_56 ++ ;
if ( F_40 ( V_99 ) == - V_103 )
V_100 = 0 ;
F_42 ( & V_5 -> V_28 , V_100 ) ;
return;
}
V_91:
F_38 ( V_5 , V_99 ) ;
}
static int F_43 ( struct V_1 * V_5 ,
struct V_98 * V_99 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_104 ;
unsigned int V_24 ;
T_3 V_105 ;
V_104 = F_44 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
return - V_106 ;
V_105 = F_16 ( V_104 -> V_49 . V_107 ) ;
if ( F_45 ( V_99 ) == V_108 ) {
if ( V_105 & V_109 ) {
F_19 ( V_5 , L_18 ) ;
return - V_106 ;
}
} else {
V_24 = F_46 ( V_104 -> V_49 . V_110 ) ;
if ( V_105 & V_111 )
V_24 /= 1000000 ;
if ( V_24 > V_5 -> V_24 )
V_5 -> V_24 = V_24 ;
}
V_5 -> V_26 = F_15 ( V_104 , V_3 -> V_48 ) ;
return 0 ;
}
void F_47 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_114 )
{
struct V_1 * V_5 = V_114 ;
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_104 ;
unsigned int V_25 ;
F_19 ( V_5 , L_19 , F_48 ( V_99 ) ) ;
if ( V_99 == F_49 ( - V_102 ) )
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
if ( F_45 ( V_99 ) != V_117 )
goto V_118;
if ( F_43 ( V_5 , V_99 ) )
goto V_118;
V_104 = F_44 ( V_99 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
goto V_118;
V_25 = F_46 ( V_104 -> V_49 . V_119 ) ;
if ( V_25 > V_5 -> V_25 )
V_5 -> V_25 = V_25 ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 )
F_35 ( V_5 ) ;
else
F_17 ( V_5 , V_97 ) ;
V_91:
F_50 ( V_99 ) ;
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
V_99 = F_51 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_99 )
return F_41 ( V_5 , V_99 ) ;
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_108 ,
F_47 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_36 ;
struct V_45 * V_46 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_53 ( V_99 ) ;
F_54 ( V_3 , V_127 , L_24 ) ;
V_36 = & V_3 -> V_36 ;
F_18 ( & V_36 -> V_86 ) ;
if ( ! V_3 -> V_121 ) {
V_126 . V_128 = V_129 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_46 = F_44 ( V_99 , sizeof( * V_46 ) ) ;
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
if ( F_43 ( V_5 , V_99 ) ) {
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_133 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_99 = F_51 ( V_3 , sizeof( * V_46 ) ) ;
if ( ! V_99 )
goto V_91;
F_55 ( V_3 , V_99 ) ;
V_46 = F_44 ( V_99 , sizeof( * V_46 ) ) ;
V_46 -> V_138 = V_117 ;
F_56 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 )
F_35 ( V_5 ) ;
else
F_17 ( V_5 , V_97 ) ;
V_91:
F_21 ( & V_5 -> V_16 ) ;
F_21 ( & V_36 -> V_86 ) ;
F_50 ( V_123 ) ;
return;
V_132:
F_21 ( & V_36 -> V_86 ) ;
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
F_50 ( V_123 ) ;
}
static void F_57 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_45 * V_144 = NULL ;
T_3 V_145 ;
T_3 V_146 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_26 , F_48 ( V_99 ) ) ;
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
V_147 = F_45 ( V_99 ) ;
if ( V_147 == V_117 &&
( V_144 = F_44 ( V_99 , sizeof( * V_144 ) ) ) != NULL ) {
V_5 -> V_6 . V_12 = F_58 ( & V_144 -> V_148 ) ;
V_5 -> V_6 . V_11 = F_58 ( & V_144 -> V_149 ) ;
V_5 -> V_107 = F_16 ( V_144 -> V_49 . V_107 ) ;
if ( V_3 -> V_121 )
F_43 ( V_5 , V_99 ) ;
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
F_50 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_35 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
F_19 ( V_5 , L_28 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_93 ) ;
V_5 -> V_26 = V_27 ;
V_99 = F_51 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_99 ) {
F_19 ( V_5 , L_29 , V_153 ) ;
F_41 ( V_5 , V_99 ) ;
return;
}
V_5 -> V_24 = V_3 -> V_24 ;
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_154 ,
F_57 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_59 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct {
struct V_155 V_156 ;
struct V_157 V_158 ;
} * V_159 ;
struct V_157 V_160 ;
struct V_65 * V_66 ;
T_1 V_13 = V_14 ;
T_1 V_161 = 0 ;
T_2 V_147 ;
T_2 V_162 = 0 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_30 , F_48 ( V_99 ) ) ;
if ( V_5 -> V_18 != V_94 ) {
F_19 ( V_5 , L_31
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
V_147 = F_45 ( V_99 ) ;
if ( V_147 == V_117 ) {
V_159 = F_44 ( V_99 , sizeof( * V_159 ) ) ;
if ( ! V_159 )
goto V_91;
V_162 = ( V_159 -> V_158 . V_163 & V_164 ) ;
F_19 ( V_5 , L_32 ,
V_159 -> V_158 . V_163 ) ;
V_5 -> V_165 = V_159 -> V_158 . V_165 ;
if ( V_162 != V_166 ) {
if ( V_162 == V_167 )
F_38 ( V_5 , V_99 ) ;
else
F_41 ( V_5 , V_99 ) ;
goto V_91;
}
if ( V_159 -> V_156 . V_168 < sizeof( V_159 -> V_158 ) )
goto V_91;
V_161 = F_46 ( V_159 -> V_158 . V_169 ) ;
if ( V_161 & V_170 )
V_5 -> V_22 |= V_171 ;
if ( V_161 & V_172 )
V_5 -> V_22 |= V_173 ;
V_66 = V_82 [ V_174 ] ;
if ( V_66 ) {
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_66 -> V_156 ( V_5 , V_159 -> V_156 . V_168 ,
& V_159 -> V_158 , & V_160 ) ;
}
V_5 -> V_73 = V_175 ;
if ( V_161 & V_176 )
V_13 |= V_177 ;
if ( V_161 & V_178 )
V_13 |= V_179 ;
V_5 -> V_6 . V_13 = V_13 ;
F_37 ( V_5 ) ;
} else {
F_19 ( V_5 , L_33 ) ;
F_41 ( V_5 , V_99 ) ;
}
V_91:
F_50 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_36 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct {
struct V_155 V_156 ;
struct V_157 V_158 ;
} * V_159 ;
struct V_98 * V_99 ;
struct V_65 * V_66 ;
if ( V_5 -> V_6 . V_4 >= V_180 ) {
F_28 ( V_5 ) ;
return;
}
F_19 ( V_5 , L_34 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_94 ) ;
V_99 = F_51 ( V_3 , sizeof( * V_159 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
F_60 ( V_3 , V_99 ) ;
V_66 = V_82 [ V_174 ] ;
if ( V_66 ) {
V_159 = F_44 ( V_99 , sizeof( * V_159 ) ) ;
V_66 -> V_156 ( V_5 , sizeof( V_159 -> V_158 ) , NULL , & V_159 -> V_158 ) ;
}
F_61 ( V_99 , V_181 , V_5 -> V_6 . V_4 ,
F_62 ( V_3 -> V_70 ) , V_182 ,
V_183 | V_184 | V_185 , 0 ) ;
if ( ! V_3 -> V_7 . V_186 ( V_3 , V_99 , F_59 ,
NULL , V_5 , 2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_63 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_35 , F_48 ( V_99 ) ) ;
if ( V_5 -> V_18 != V_95 ) {
F_19 ( V_5 , L_36
L_21 , F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_38 ( V_5 , V_99 ) ;
goto V_116;
}
V_147 = F_45 ( V_99 ) ;
if ( V_147 == V_117 ) {
struct V_187 * V_188 ;
T_1 V_189 ;
T_1 V_190 ;
V_188 = F_44 ( V_99 , sizeof( * V_188 ) ) ;
if ( V_188 ) {
V_189 = F_46 ( V_188 -> V_191 ) ;
V_190 = F_46 ( V_188 -> V_192 ) ;
if ( V_190 == 0 )
V_190 = 1 ;
V_5 -> V_25 = V_190 ;
V_190 = F_46 ( V_188 -> V_193 ) ;
if ( V_189 & V_194 )
V_190 /= 1000000 ;
if ( V_190 == 0 )
V_190 = 1 ;
V_5 -> V_24 = V_190 ;
}
}
F_28 ( V_5 ) ;
V_91:
F_50 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_37 ( struct V_1 * V_5 )
{
struct V_98 * V_99 ;
struct V_2 * V_3 = V_5 -> V_17 ;
F_19 ( V_5 , L_37 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_95 ) ;
V_99 = F_51 ( V_3 , sizeof( struct V_195 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_196 ,
F_63 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_64 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_197 )
{
struct V_2 * V_3 = V_197 ;
F_54 ( V_3 , F_65 ( V_113 ) -> V_198 ,
L_38 , F_48 ( V_99 ) ) ;
if ( F_39 ( V_99 ) )
return;
F_50 ( V_99 ) ;
}
static void F_34 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
F_19 ( V_5 , L_39 ,
F_13 ( V_5 ) ) ;
V_99 = F_51 ( V_3 , sizeof( struct V_199 ) ) ;
if ( ! V_99 )
return;
( void ) V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_200 ,
F_64 , V_3 , 0 ) ;
}
static void F_66 ( struct V_112 * V_113 , struct V_98 * V_99 ,
void * V_143 )
{
struct V_1 * V_5 = V_143 ;
struct V_201 * V_202 ;
T_2 V_147 ;
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_40 ) ;
if ( V_5 -> V_18 != V_96 ) {
F_19 ( V_5 , L_41 ,
F_13 ( V_5 ) ) ;
if ( F_39 ( V_99 ) )
goto V_116;
goto V_91;
}
if ( F_39 ( V_99 ) ) {
F_38 ( V_5 , V_99 ) ;
goto V_116;
}
V_147 = F_45 ( V_99 ) ;
V_202 = F_44 ( V_99 , sizeof( * V_202 ) ) ;
if ( V_147 != V_117 || ! V_202 ||
F_67 ( V_202 -> V_203 ) != V_5 -> V_6 . V_4 ||
F_58 ( & V_202 -> V_204 ) != V_5 -> V_6 . V_12 ||
F_58 ( & V_202 -> V_205 ) != V_5 -> V_6 . V_11 ) {
F_19 ( V_5 , L_42 ) ;
F_26 ( V_5 ) ;
} else {
F_19 ( V_5 , L_43 ) ;
F_28 ( V_5 ) ;
}
V_91:
F_50 ( V_99 ) ;
V_116:
F_21 ( & V_5 -> V_16 ) ;
F_23 ( & V_5 -> V_15 , V_5 -> V_17 -> V_7 . V_72 ) ;
}
static void F_30 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
F_19 ( V_5 , L_44 ,
F_13 ( V_5 ) ) ;
F_17 ( V_5 , V_96 ) ;
V_99 = F_51 ( V_3 , sizeof( struct V_201 ) ) ;
if ( ! V_99 ) {
F_41 ( V_5 , V_99 ) ;
return;
}
if ( ! V_3 -> V_7 . V_122 ( V_3 , V_5 -> V_6 . V_4 , V_99 , V_206 ,
F_66 , V_5 ,
2 * V_3 -> V_25 ) )
F_41 ( V_5 , NULL ) ;
else
F_20 ( & V_5 -> V_15 ) ;
}
static void F_68 ( struct V_1 * V_5 ,
struct V_98 * V_207 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct V_201 * V_202 ;
struct V_125 V_126 ;
F_19 ( V_5 , L_45 ) ;
V_202 = F_44 ( V_207 , sizeof( * V_202 ) ) ;
if ( ! V_202 ) {
V_126 . V_128 = V_208 ;
V_126 . V_130 = V_134 ;
V_3 -> V_7 . V_141 ( V_207 , V_142 , & V_126 ) ;
goto V_209;
}
V_99 = F_51 ( V_3 , sizeof( * V_202 ) ) ;
if ( ! V_99 )
goto V_209;
F_69 ( V_3 , V_99 ) ;
V_202 = F_44 ( V_99 , sizeof( * V_202 ) ) ;
V_202 -> V_210 = V_117 ;
F_56 ( V_99 , V_207 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
V_209:
F_50 ( V_207 ) ;
}
static void F_70 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_125 V_126 ;
struct V_217 * V_218 ;
F_19 ( V_5 , L_46 ,
F_13 ( V_5 ) ) ;
V_212 = F_44 ( V_123 , sizeof( * V_212 ) ) ;
if ( ! V_212 ) {
V_126 . V_128 = V_208 ;
V_126 . V_130 = V_134 ;
goto V_219;
}
V_99 = F_51 ( V_3 , sizeof( * V_214 ) ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_220 ;
V_126 . V_130 = V_221 ;
goto V_219;
}
V_214 = F_44 ( V_99 , sizeof( * V_214 ) ) ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
V_214 -> V_222 = V_117 ;
V_216 = & V_214 -> V_223 ;
if ( V_3 -> V_7 . V_224 ) {
V_3 -> V_7 . V_224 ( V_3 , V_216 ) ;
} else {
F_71 ( V_3 -> V_70 ) ;
V_218 = & V_3 -> V_225 ;
V_216 -> V_226 = F_72 ( V_218 -> V_227 ) ;
V_216 -> V_228 = F_72 ( V_218 -> V_229 ) ;
V_216 -> V_230 = F_72 ( V_218 -> V_231 ) ;
V_216 -> V_232 = F_72 ( V_218 -> V_233 ) ;
V_216 -> V_234 = F_72 ( V_218 -> V_235 ) ;
V_216 -> V_236 = F_72 ( V_218 -> V_237 ) ;
}
F_56 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
goto V_91;
V_219:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_91:
F_50 ( V_123 ) ;
}
static void F_73 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
struct V_125 V_238 ;
F_18 ( & V_3 -> V_36 . V_86 ) ;
V_5 = V_3 -> V_7 . V_8 ( V_3 , F_53 ( V_99 ) ) ;
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
switch ( F_45 ( V_99 ) ) {
case V_239 :
F_74 ( V_5 , V_99 ) ;
break;
case V_240 :
F_75 ( V_5 , V_99 ) ;
break;
case V_206 :
F_68 ( V_5 , V_99 ) ;
break;
case V_241 :
V_3 -> V_7 . V_141 ( V_99 , V_241 , NULL ) ;
F_50 ( V_99 ) ;
break;
case V_242 :
V_3 -> V_7 . V_141 ( V_99 , V_242 , NULL ) ;
F_50 ( V_99 ) ;
break;
case V_243 :
F_70 ( V_5 , V_99 ) ;
break;
default:
F_50 ( V_99 ) ;
break;
}
F_21 ( & V_5 -> V_16 ) ;
return;
V_132:
V_238 . V_128 = V_220 ;
V_238 . V_130 = V_244 ;
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_238 ) ;
F_50 ( V_99 ) ;
}
void F_76 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_125 V_238 ;
switch ( F_45 ( V_99 ) ) {
case V_108 :
F_52 ( V_3 , V_99 ) ;
break;
case V_154 :
F_77 ( V_3 , V_99 ) ;
break;
case V_200 :
F_78 ( V_3 , V_99 ) ;
break;
case V_239 :
case V_240 :
case V_206 :
case V_241 :
case V_242 :
case V_243 :
F_73 ( V_3 , V_99 ) ;
break;
default:
V_238 . V_128 = V_129 ;
V_238 . V_130 = V_131 ;
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_238 ) ;
F_50 ( V_99 ) ;
break;
}
}
static void F_77 ( struct V_2 * V_3 ,
struct V_98 * V_123 )
{
struct V_124 * V_36 ;
struct V_1 * V_5 ;
struct V_98 * V_99 = V_123 ;
struct V_45 * V_245 ;
struct V_125 V_126 ;
T_1 V_127 ;
V_127 = F_53 ( V_99 ) ;
F_54 ( V_3 , V_127 , L_47 ) ;
V_245 = F_44 ( V_99 , sizeof( * V_245 ) ) ;
if ( ! V_245 ) {
F_54 ( V_3 , V_127 , L_48 ) ;
V_126 . V_128 = V_208 ;
V_126 . V_130 = V_134 ;
goto V_132;
}
V_36 = & V_3 -> V_36 ;
F_18 ( & V_36 -> V_86 ) ;
V_5 = V_3 -> V_7 . V_246 ( V_3 , V_127 ) ;
if ( ! V_5 ) {
F_21 ( & V_36 -> V_86 ) ;
V_126 . V_128 = V_220 ;
V_126 . V_130 = V_221 ;
goto V_132;
}
F_18 ( & V_5 -> V_16 ) ;
F_21 ( & V_36 -> V_86 ) ;
V_5 -> V_6 . V_12 = F_58 ( & V_245 -> V_148 ) ;
V_5 -> V_6 . V_11 = F_58 ( & V_245 -> V_149 ) ;
switch ( V_5 -> V_18 ) {
case V_19 :
F_19 ( V_5 , L_49 ) ;
break;
case V_97 :
F_19 ( V_5 , L_50 ) ;
break;
case V_93 :
F_19 ( V_5 , L_51 ) ;
if ( V_5 -> V_6 . V_12 < V_3 -> V_120 ) {
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_247 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
break;
case V_94 :
case V_95 :
case V_89 :
case V_96 :
F_19 ( V_5 , L_52
L_53 , V_5 -> V_18 ) ;
break;
case V_92 :
case V_85 :
F_19 ( V_5 , L_54 ,
F_13 ( V_5 ) ) ;
F_21 ( & V_5 -> V_16 ) ;
V_126 . V_128 = V_137 ;
V_126 . V_130 = V_131 ;
goto V_132;
}
V_5 -> V_26 = F_15 ( V_245 , V_3 -> V_48 ) ;
V_99 = F_51 ( V_3 , sizeof( * V_245 ) ) ;
if ( ! V_99 )
goto V_91;
F_79 ( V_3 , V_99 , V_117 ) ;
F_56 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
F_36 ( V_5 ) ;
V_91:
F_21 ( & V_5 -> V_16 ) ;
F_50 ( V_123 ) ;
return;
V_132:
V_3 -> V_7 . V_141 ( V_99 , V_142 , & V_126 ) ;
F_50 ( V_99 ) ;
}
static void F_74 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct {
struct V_155 V_156 ;
struct V_157 V_158 ;
} * V_159 ;
struct V_157 * V_248 ;
struct V_157 * V_158 ;
unsigned int V_249 ;
unsigned int V_250 ;
enum V_251 V_252 ;
enum V_251 V_253 ;
struct V_125 V_126 ;
struct V_65 * V_66 ;
F_19 ( V_5 , L_55 ,
F_13 ( V_5 ) ) ;
V_249 = F_80 ( V_123 ) - sizeof( struct V_254 ) ;
V_159 = F_44 ( V_123 , sizeof( * V_159 ) ) ;
if ( ! V_159 )
goto V_255;
V_250 = F_16 ( V_159 -> V_156 . V_256 ) ;
if ( ( V_250 % 4 ) != 0 || V_250 > V_249 || V_250 < 16 )
goto V_255;
if ( V_250 < V_249 )
V_249 = V_250 ;
V_250 = V_159 -> V_156 . V_168 ;
if ( ( V_250 % 4 ) != 0 || V_250 < sizeof( * V_158 ) ||
V_250 > V_249 || V_249 < sizeof( * V_159 ) || V_250 < 12 )
goto V_255;
V_248 = & V_159 -> V_158 ;
V_99 = F_51 ( V_3 , V_249 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_220 ;
V_126 . V_130 = V_221 ;
goto V_132;
}
V_159 = F_44 ( V_99 , V_249 ) ;
F_81 ( ! V_159 ) ;
memset ( V_159 , 0 , V_249 ) ;
V_159 -> V_156 . V_257 = V_117 ;
V_159 -> V_156 . V_168 = V_250 ;
V_159 -> V_156 . V_256 = F_82 ( V_249 ) ;
V_249 -= sizeof( struct V_155 ) ;
V_158 = & V_159 -> V_158 ;
F_18 ( & V_80 ) ;
while ( V_249 >= V_250 ) {
V_5 -> V_165 = V_248 -> V_165 ;
V_158 -> V_165 = V_248 -> V_165 ;
V_158 -> V_258 = V_248 -> V_258 ;
V_252 = 0 ;
if ( V_248 -> V_165 < V_81 ) {
V_66 = V_259 [ V_248 -> V_165 ] ;
if ( V_66 )
V_252 = V_66 -> V_156 ( V_5 , V_250 , V_248 , V_158 ) ;
V_66 = V_82 [ V_248 -> V_165 ] ;
if ( V_66 ) {
V_253 = V_66 -> V_156 ( V_5 , V_250 , V_248 , V_158 ) ;
if ( ! V_252 || V_253 == V_166 )
V_252 = V_253 ;
}
}
if ( ! V_252 ) {
if ( V_158 -> V_163 & V_260 )
V_252 |= V_167 ;
else
V_252 |= V_261 ;
}
V_158 -> V_163 |= V_252 ;
V_249 -= V_250 ;
V_248 = (struct V_157 * ) ( ( char * ) V_248 + V_250 ) ;
V_158 = (struct V_157 * ) ( ( char * ) V_158 + V_250 ) ;
}
F_21 ( & V_80 ) ;
F_56 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
switch ( V_5 -> V_18 ) {
case V_94 :
F_28 ( V_5 ) ;
break;
default:
break;
}
goto V_209;
V_255:
V_126 . V_128 = V_208 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_209:
F_50 ( V_123 ) ;
}
static void F_75 ( struct V_1 * V_5 ,
struct V_98 * V_123 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
struct V_98 * V_99 ;
struct {
struct V_262 V_83 ;
struct V_157 V_158 ;
} * V_159 ;
struct V_157 * V_248 ;
struct V_157 * V_158 ;
unsigned int V_249 ;
unsigned int V_250 ;
struct V_125 V_126 ;
F_19 ( V_5 , L_56 ,
F_13 ( V_5 ) ) ;
V_249 = F_80 ( V_123 ) - sizeof( struct V_254 ) ;
V_159 = F_44 ( V_123 , sizeof( * V_159 ) ) ;
if ( ! V_159 )
goto V_255;
V_250 = F_16 ( V_159 -> V_83 . V_263 ) ;
if ( V_250 != 20 )
goto V_255;
if ( V_250 < V_249 )
V_249 = V_250 ;
V_248 = & V_159 -> V_158 ;
V_99 = F_51 ( V_3 , V_249 ) ;
if ( ! V_99 ) {
V_126 . V_128 = V_220 ;
V_126 . V_130 = V_221 ;
goto V_132;
}
V_159 = F_44 ( V_99 , V_249 ) ;
F_81 ( ! V_159 ) ;
memset ( V_159 , 0 , V_249 ) ;
V_159 -> V_83 . V_264 = V_117 ;
V_159 -> V_83 . V_265 = 0x10 ;
V_159 -> V_83 . V_263 = F_82 ( V_249 ) ;
V_158 = & V_159 -> V_158 ;
V_158 -> V_165 = V_248 -> V_165 ;
V_158 -> V_258 = V_248 -> V_258 ;
V_158 -> V_163 = V_166 ;
F_31 ( V_5 , V_77 ) ;
F_56 ( V_99 , V_123 , V_139 , 0 ) ;
V_3 -> V_7 . V_140 ( V_3 , V_99 ) ;
goto V_209;
V_255:
V_126 . V_128 = V_208 ;
V_126 . V_130 = V_134 ;
V_132:
V_3 -> V_7 . V_141 ( V_123 , V_142 , & V_126 ) ;
V_209:
F_50 ( V_123 ) ;
}
static void F_78 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_1 * V_5 ;
T_1 V_127 ;
V_3 -> V_7 . V_141 ( V_99 , V_117 , NULL ) ;
V_127 = F_53 ( V_99 ) ;
F_18 ( & V_3 -> V_36 . V_86 ) ;
V_5 = V_3 -> V_7 . V_8 ( V_3 , V_127 ) ;
if ( V_5 ) {
F_18 ( & V_5 -> V_16 ) ;
F_19 ( V_5 , L_57 ,
F_13 ( V_5 ) ) ;
F_31 ( V_5 , V_77 ) ;
F_21 ( & V_5 -> V_16 ) ;
} else
F_54 ( V_3 , V_127 ,
L_58 ) ;
F_21 ( & V_3 -> V_36 . V_86 ) ;
F_50 ( V_99 ) ;
}
static void F_83 ( void )
{
F_84 ( V_90 ) ;
}
int F_85 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_7 . V_8 )
V_3 -> V_7 . V_8 = F_1 ;
if ( ! V_3 -> V_7 . V_246 )
V_3 -> V_7 . V_246 = F_3 ;
if ( ! V_3 -> V_7 . V_266 )
V_3 -> V_7 . V_266 = F_29 ;
if ( ! V_3 -> V_7 . V_71 )
V_3 -> V_7 . V_71 = F_33 ;
if ( ! V_3 -> V_7 . V_267 )
V_3 -> V_7 . V_267 = F_76 ;
if ( ! V_3 -> V_7 . V_268 )
V_3 -> V_7 . V_268 = F_83 ;
if ( ! V_3 -> V_7 . V_72 )
V_3 -> V_7 . V_72 = F_10 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_5 , T_1 V_269 ,
const struct V_157 * V_248 ,
struct V_157 * V_158 )
{
struct V_2 * V_3 = V_5 -> V_17 ;
T_1 V_161 ;
V_161 = F_46 ( V_248 -> V_169 ) ;
V_5 -> V_6 . V_13 = V_14 ;
if ( V_161 & V_176 )
V_5 -> V_6 . V_13 |= V_177 ;
if ( V_161 & V_178 )
V_5 -> V_6 . V_13 |= V_179 ;
if ( V_161 & V_170 )
V_5 -> V_22 |= V_171 ;
V_5 -> V_73 = V_175 ;
if ( ! ( V_3 -> V_270 & V_177 ) )
return 0 ;
V_158 -> V_163 |= V_248 -> V_163 & V_260 ;
V_161 = F_46 ( V_158 -> V_169 ) ;
V_158 -> V_169 = F_72 ( V_161 | V_3 -> V_270 ) ;
return V_166 ;
}
static int F_87 ( struct V_1 * V_5 , T_1 V_269 ,
const struct V_157 * V_248 ,
struct V_157 * V_158 )
{
if ( V_248 -> V_163 & V_260 )
return V_261 ;
return V_166 ;
}
int F_88 ( void )
{
V_90 = F_89 ( L_59 ) ;
if ( ! V_90 )
return - V_271 ;
return 0 ;
}
void F_90 ( void )
{
F_91 ( V_90 ) ;
}
void F_92 ( struct V_41 * V_42 )
{
struct V_59 * V_60 = V_42 -> V_74 ;
struct V_2 * V_3 = V_60 -> V_17 ;
V_3 -> V_7 . V_84 ( V_3 , 0 , V_42 -> V_4 ) ;
V_3 -> V_7 . V_84 ( V_3 , V_42 -> V_4 , 0 ) ;
}
