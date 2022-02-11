struct V_1 * F_1 ( const struct V_2 * V_3 ,
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
struct V_1 * F_6 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( sizeof( * V_5 ) + V_3 -> V_9 , V_10 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_7 . V_11 = - 1 ;
V_5 -> V_7 . V_12 = - 1 ;
V_5 -> V_7 . V_4 = V_4 ;
V_5 -> V_7 . V_13 = V_14 ;
F_8 ( & V_5 -> V_8 ) ;
F_9 ( & V_5 -> V_15 ) ;
V_5 -> V_16 = V_3 ;
V_5 -> V_17 = V_18 ;
V_5 -> V_19 = V_20 ;
V_5 -> V_21 = V_22 ;
V_5 -> V_23 = V_3 -> V_23 ;
V_5 -> V_24 = V_3 -> V_24 ;
V_5 -> V_25 = V_26 ;
F_10 ( & V_5 -> V_27 , V_28 ) ;
F_11 ( & V_5 -> V_29 , V_30 ) ;
if ( V_4 != V_31 ) {
V_5 -> V_32 = V_3 -> V_33 . V_34 ;
F_12 ( & V_5 -> V_35 , & V_3 -> V_36 . V_37 ) ;
}
return V_5 ;
}
void F_13 ( struct V_8 * V_8 )
{
struct V_1 * V_5 ;
V_5 = F_14 ( V_8 , struct V_1 , V_8 ) ;
F_15 ( V_5 , V_38 ) ;
}
static const char * F_16 ( struct V_1 * V_5 )
{
const char * V_39 ;
V_39 = V_40 [ V_5 -> V_17 ] ;
if ( ! V_39 )
V_39 = L_1 ;
return V_39 ;
}
void F_17 ( struct V_41 * V_42 , T_1 V_43 )
{
if ( V_43 )
V_42 -> V_44 = V_43 ;
else
V_42 -> V_44 = 1 ;
}
static unsigned int F_18 ( struct V_45 * V_46 ,
unsigned int V_47 )
{
unsigned int V_48 ;
V_48 = F_19 ( V_46 -> V_49 . V_50 ) & V_51 ;
if ( V_48 >= V_52 && V_48 < V_47 )
V_47 = V_48 ;
V_48 = F_19 ( V_46 -> V_53 [ 3 - 1 ] . V_54 ) ;
if ( V_48 >= V_52 && V_48 < V_47 )
V_47 = V_48 ;
return V_47 ;
}
static void F_20 ( struct V_1 * V_5 ,
enum F_16 V_55 )
{
if ( V_5 -> V_17 != V_55 )
V_5 -> V_56 = 0 ;
V_5 -> V_17 = V_55 ;
}
static void V_30 ( struct V_57 * V_58 )
{
T_1 V_4 ;
struct V_1 * V_5 =
F_14 ( V_58 , struct V_1 , V_29 ) ;
struct V_59 * V_60 ;
enum V_61 V_19 ;
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_62 * V_63 ;
struct V_64 V_7 ;
struct V_41 * V_42 ;
struct V_65 * V_66 ;
T_2 type ;
F_21 ( & V_5 -> V_15 ) ;
V_19 = V_5 -> V_19 ;
V_63 = V_5 -> V_67 ;
V_42 = V_5 -> V_42 ;
F_22 ( V_5 , L_2 , V_19 ) ;
switch ( V_19 ) {
case V_68 :
V_7 = V_5 -> V_7 ;
V_5 -> V_19 = V_20 ;
V_5 -> V_69 = 0 ;
F_23 ( & V_5 -> V_8 ) ;
F_24 ( & V_5 -> V_15 ) ;
if ( ! V_42 ) {
F_22 ( V_5 , L_3 ) ;
V_42 = F_25 ( V_3 -> V_70 , 0 , & V_7 ) ;
}
if ( ! V_42 ) {
F_22 ( V_5 , L_4 ) ;
F_26 ( V_5 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
return;
}
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_42 )
F_22 ( V_5 , L_5 ) ;
V_5 -> V_42 = V_42 ;
V_42 -> V_25 = V_5 -> V_25 ;
V_42 -> V_71 = V_5 -> V_71 ;
V_60 = V_42 -> V_72 ;
V_60 -> V_16 = V_3 ;
V_60 -> V_17 = V_5 -> V_17 ;
V_60 -> V_21 = V_5 -> V_21 ;
V_60 -> V_23 = V_5 -> V_23 ;
V_60 -> V_24 = V_5 -> V_24 ;
F_24 ( & V_5 -> V_15 ) ;
if ( V_63 && V_63 -> V_73 ) {
F_22 ( V_5 , L_6 , V_19 ) ;
V_63 -> V_73 ( V_3 , V_5 , V_19 ) ;
}
if ( V_5 -> V_32 ) {
F_22 ( V_5 , L_7 , V_19 ) ;
V_5 -> V_32 ( V_3 , V_5 , V_19 ) ;
}
F_27 ( & V_5 -> V_8 , F_13 ) ;
break;
case V_74 :
case V_75 :
case V_76 :
if ( V_5 -> V_77 ) {
F_21 ( & V_78 ) ;
for ( type = 1 ; type < V_79 ; type ++ ) {
V_66 = V_80 [ type ] ;
if ( V_66 && V_66 -> V_81 )
V_66 -> V_81 ( V_5 ) ;
}
F_24 ( & V_78 ) ;
}
V_4 = V_5 -> V_7 . V_4 ;
F_24 ( & V_5 -> V_15 ) ;
if ( V_63 && V_63 -> V_73 ) {
F_22 ( V_5 , L_6 , V_19 ) ;
V_63 -> V_73 ( V_3 , V_5 , V_19 ) ;
}
if ( V_5 -> V_32 ) {
F_22 ( V_5 , L_7 , V_19 ) ;
V_5 -> V_32 ( V_3 , V_5 , V_19 ) ;
}
if ( F_28 ( & V_5 -> V_27 ) )
F_27 ( & V_5 -> V_8 , F_13 ) ;
V_3 -> V_33 . V_82 ( V_3 , 0 , V_4 ) ;
V_3 -> V_33 . V_82 ( V_3 , V_4 , 0 ) ;
if ( V_42 ) {
V_60 = V_42 -> V_72 ;
V_60 -> V_17 = V_83 ;
F_21 ( & V_5 -> V_15 ) ;
V_5 -> V_42 = NULL ;
F_24 ( & V_5 -> V_15 ) ;
F_29 ( V_42 ) ;
}
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 == V_83 ) {
if ( V_4 == V_31 ) {
V_5 -> V_19 = V_20 ;
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
} else if ( ( V_5 -> V_21 & V_84 ) &&
V_5 -> V_69 <
V_3 -> V_85 ) {
V_5 -> V_69 ++ ;
V_5 -> V_19 = V_20 ;
F_22 ( V_5 , L_8 ) ;
F_30 ( V_5 ) ;
F_24 ( & V_5 -> V_15 ) ;
} else {
F_22 ( V_5 , L_9 ) ;
F_21 ( & V_3 -> V_36 . V_86 ) ;
F_31 ( & V_5 -> V_35 ) ;
F_24 ( & V_3 -> V_36 . V_86 ) ;
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
} else {
V_5 -> V_19 = V_20 ;
if ( V_5 -> V_17 == V_87 ) {
F_22 ( V_5 , L_10 ) ;
F_32 ( V_5 ) ;
}
F_24 ( & V_5 -> V_15 ) ;
}
break;
default:
F_24 ( & V_5 -> V_15 ) ;
break;
}
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
int F_33 ( struct V_1 * V_5 )
{
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_21 & V_84 ) {
F_22 ( V_5 , L_11 ) ;
F_24 ( & V_5 -> V_15 ) ;
return 0 ;
}
V_5 -> V_21 |= V_84 ;
switch ( V_5 -> V_17 ) {
case V_87 :
F_22 ( V_5 , L_12 ) ;
F_34 ( V_5 ) ;
break;
case V_83 :
F_22 ( V_5 , L_13 ) ;
break;
case V_18 :
F_22 ( V_5 , L_14 ) ;
F_30 ( V_5 ) ;
break;
default:
F_22 ( V_5 , L_15 ,
F_16 ( V_5 ) ) ;
break;
}
F_24 ( & V_5 -> V_15 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_5 ,
enum V_61 V_19 )
{
if ( V_5 -> V_17 == V_83 )
return;
F_22 ( V_5 , L_16 ) ;
F_20 ( V_5 , V_83 ) ;
F_23 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_19 == V_20 &&
! F_36 ( V_88 , & V_5 -> V_29 ) )
F_27 ( & V_5 -> V_8 , F_13 ) ;
V_5 -> V_19 = V_19 ;
}
int F_26 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
T_1 V_4 = V_5 -> V_7 . V_4 ;
F_21 ( & V_5 -> V_15 ) ;
F_22 ( V_5 , L_17 ) ;
V_5 -> V_21 &= ~ V_84 ;
if ( V_5 -> V_17 == V_83 ) {
F_22 ( V_5 , L_18 ) ;
goto V_89;
}
V_3 -> V_33 . V_82 ( V_3 , 0 , V_4 ) ;
V_3 -> V_33 . V_82 ( V_3 , V_4 , 0 ) ;
F_37 ( V_5 ) ;
F_35 ( V_5 , V_76 ) ;
V_89:
F_24 ( & V_5 -> V_15 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_5 )
{
F_20 ( V_5 , V_87 ) ;
F_22 ( V_5 , L_19 ) ;
F_23 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_19 == V_20 &&
! F_36 ( V_88 , & V_5 -> V_29 ) )
F_27 ( & V_5 -> V_8 , F_13 ) ;
V_5 -> V_19 = V_68 ;
}
static void V_28 ( struct V_57 * V_58 )
{
struct V_1 * V_5 =
F_14 ( V_58 , struct V_1 , V_27 . V_58 ) ;
F_21 ( & V_5 -> V_15 ) ;
F_22 ( V_5 , L_20 , F_16 ( V_5 ) ) ;
switch ( V_5 -> V_17 ) {
case V_90 :
F_30 ( V_5 ) ;
break;
case V_91 :
F_38 ( V_5 ) ;
break;
case V_92 :
F_39 ( V_5 ) ;
break;
case V_93 :
F_40 ( V_5 ) ;
break;
case V_94 :
F_34 ( V_5 ) ;
break;
case V_95 :
case V_87 :
case V_18 :
case V_83 :
break;
}
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_41 ( struct V_1 * V_5 , int V_96 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
F_22 ( V_5 , L_21 ,
- V_96 , F_16 ( V_5 ) , V_5 -> V_56 ) ;
switch ( V_5 -> V_17 ) {
case V_90 :
V_5 -> V_21 &= ~ V_84 ;
F_35 ( V_5 , V_74 ) ;
break;
case V_91 :
if ( V_3 -> V_97 ) {
V_5 -> V_21 &= ~ V_84 ;
F_35 ( V_5 , V_74 ) ;
} else
F_37 ( V_5 ) ;
break;
case V_93 :
F_32 ( V_5 ) ;
break;
case V_92 :
case V_94 :
F_37 ( V_5 ) ;
break;
case V_95 :
case V_83 :
case V_87 :
case V_18 :
break;
}
}
static void F_42 ( struct V_1 * V_5 , int V_96 )
{
unsigned long V_98 = F_43 ( V_5 -> V_23 ) ;
if ( V_96 == - V_99 )
goto V_89;
if ( V_5 -> V_56 < V_5 -> V_16 -> V_85 ) {
F_22 ( V_5 , L_22 ,
V_96 , F_16 ( V_5 ) ) ;
V_5 -> V_56 ++ ;
if ( V_96 == - V_100 )
V_98 = 0 ;
F_23 ( & V_5 -> V_8 ) ;
if ( ! F_44 ( & V_5 -> V_27 , V_98 ) )
F_27 ( & V_5 -> V_8 , F_13 ) ;
return;
}
V_89:
F_41 ( V_5 , V_96 ) ;
}
static int F_45 ( struct V_1 * V_5 ,
struct V_101 * V_102 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_45 * V_103 ;
unsigned int V_23 ;
T_3 V_104 ;
V_103 = F_46 ( V_102 , sizeof( * V_103 ) ) ;
if ( ! V_103 )
return - V_105 ;
V_104 = F_19 ( V_103 -> V_49 . V_106 ) ;
if ( F_47 ( V_102 ) == V_107 ) {
if ( V_104 & V_108 ) {
F_22 ( V_5 , L_23 ) ;
return - V_105 ;
}
} else {
V_23 = F_48 ( V_103 -> V_49 . V_109 ) ;
if ( V_104 & V_110 )
V_23 /= 1000000 ;
if ( V_23 > V_5 -> V_23 )
V_5 -> V_23 = V_23 ;
}
V_5 -> V_25 = F_18 ( V_103 , V_3 -> V_48 ) ;
return 0 ;
}
static void F_49 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_113 )
{
struct V_1 * V_5 = V_113 ;
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_45 * V_103 ;
unsigned int V_24 ;
T_2 V_114 ;
int V_96 = 0 ;
F_22 ( V_5 , L_24 ,
F_50 ( V_102 ) ? L_25 : F_51 ( V_102 ) ) ;
if ( V_102 == F_52 ( - V_99 ) )
goto V_115;
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 != V_90 ) {
F_22 ( V_5 , L_26
L_27 , F_16 ( V_5 ) ) ;
if ( F_50 ( V_102 ) )
goto V_96;
goto V_89;
}
if ( F_50 ( V_102 ) ) {
F_41 ( V_5 , F_53 ( V_102 ) ) ;
goto V_96;
}
V_114 = F_47 ( V_102 ) ;
if ( V_114 == V_116 ) {
struct V_117 * V_118 ;
V_118 = F_46 ( V_102 , sizeof( * V_118 ) ) ;
F_22 ( V_5 , L_28 ,
V_118 -> V_119 , V_118 -> V_120 ) ;
V_96 = - V_121 ;
goto V_122;
} else if ( V_114 != V_123 ) {
F_22 ( V_5 , L_29 , V_114 ) ;
V_96 = - V_121 ;
goto V_122;
}
if ( F_45 ( V_5 , V_102 ) ) {
F_22 ( V_5 , L_30 ) ;
V_96 = - V_124 ;
goto V_122;
}
V_103 = F_46 ( V_102 , sizeof( * V_103 ) ) ;
if ( ! V_103 ) {
V_96 = - V_125 ;
goto V_122;
}
V_24 = F_48 ( V_103 -> V_49 . V_126 ) ;
if ( V_24 > V_5 -> V_24 )
V_5 -> V_24 = V_24 ;
if ( V_5 -> V_7 . V_12 < V_3 -> V_127 )
F_38 ( V_5 ) ;
else
F_20 ( V_5 , V_95 ) ;
V_89:
F_54 ( V_102 ) ;
V_96:
F_24 ( & V_5 -> V_15 ) ;
V_115:
F_27 ( & V_5 -> V_8 , F_13 ) ;
return;
V_122:
F_22 ( V_5 , L_31 ) ;
F_42 ( V_5 , V_96 ) ;
goto V_89;
}
static void F_30 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
if ( ! V_3 -> V_97 )
return F_38 ( V_5 ) ;
F_22 ( V_5 , L_32 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_90 ) ;
V_102 = F_55 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_102 )
return F_42 ( V_5 , - V_125 ) ;
F_23 ( & V_5 -> V_8 ) ;
if ( ! V_3 -> V_33 . V_128 ( V_3 , V_5 -> V_7 . V_4 , V_102 , V_107 ,
F_49 , V_5 ,
2 * V_3 -> V_24 ) ) {
F_42 ( V_5 , - V_129 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
}
static void F_56 ( struct V_2 * V_3 ,
struct V_101 * V_130 )
{
struct V_131 * V_36 ;
struct V_45 * V_46 ;
struct V_1 * V_5 ;
struct V_101 * V_102 = V_130 ;
struct V_132 V_133 ;
T_1 V_134 ;
V_134 = F_57 ( V_102 ) ;
F_58 ( V_3 , V_134 , L_33 ) ;
V_36 = & V_3 -> V_36 ;
if ( ! V_3 -> V_97 ) {
V_133 . V_135 = V_136 ;
V_133 . V_137 = V_138 ;
goto V_139;
}
V_46 = F_46 ( V_102 , sizeof( * V_46 ) ) ;
if ( ! V_46 ) {
V_133 . V_135 = V_140 ;
V_133 . V_137 = V_141 ;
goto V_139;
}
V_5 = F_1 ( V_3 , V_134 ) ;
if ( ! V_5 ) {
V_133 . V_135 = V_142 ;
V_133 . V_137 = V_143 ;
goto V_139;
}
F_21 ( & V_5 -> V_15 ) ;
F_22 ( V_5 , L_34 ,
F_16 ( V_5 ) ) ;
switch ( V_5 -> V_17 ) {
case V_18 :
break;
case V_83 :
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_142 ;
V_133 . V_137 = V_143 ;
goto V_144;
case V_90 :
case V_95 :
case V_91 :
break;
case V_92 :
case V_93 :
case V_87 :
case V_94 :
F_35 ( V_5 , V_75 ) ;
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_145 ;
V_133 . V_137 = V_138 ;
goto V_144;
}
if ( F_45 ( V_5 , V_102 ) ) {
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_140 ;
V_133 . V_137 = V_138 ;
goto V_144;
}
V_102 = F_55 ( V_3 , sizeof( * V_46 ) ) ;
if ( ! V_102 )
goto V_89;
F_59 ( V_3 , V_102 ) ;
V_46 = F_46 ( V_102 , sizeof( * V_46 ) ) ;
V_46 -> V_146 = V_123 ;
F_60 ( V_102 , V_130 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
if ( V_5 -> V_17 != V_90 ) {
if ( V_5 -> V_7 . V_12 < V_3 -> V_127 )
F_38 ( V_5 ) ;
else
F_20 ( V_5 , V_95 ) ;
}
V_89:
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
F_54 ( V_130 ) ;
return;
V_144:
F_27 ( & V_5 -> V_8 , F_13 ) ;
V_139:
F_61 ( V_130 , V_116 , & V_133 ) ;
F_54 ( V_130 ) ;
}
static void F_62 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_149 )
{
struct V_1 * V_5 = V_149 ;
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_45 * V_150 = NULL ;
T_3 V_151 ;
T_3 V_152 ;
T_2 V_153 ;
F_22 ( V_5 , L_35 , F_51 ( V_102 ) ) ;
if ( V_102 == F_52 ( - V_99 ) )
goto V_115;
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 != V_91 ) {
F_22 ( V_5 , L_36
L_27 , F_16 ( V_5 ) ) ;
if ( F_50 ( V_102 ) )
goto V_96;
goto V_89;
}
if ( F_50 ( V_102 ) ) {
F_42 ( V_5 , F_53 ( V_102 ) ) ;
goto V_96;
}
V_153 = F_47 ( V_102 ) ;
if ( V_153 == V_123 &&
( V_150 = F_46 ( V_102 , sizeof( * V_150 ) ) ) != NULL ) {
V_5 -> V_7 . V_12 = F_63 ( & V_150 -> V_154 ) ;
V_5 -> V_7 . V_11 = F_63 ( & V_150 -> V_155 ) ;
V_5 -> V_106 = F_19 ( V_150 -> V_49 . V_106 ) ;
if ( V_3 -> V_97 )
F_45 ( V_5 , V_102 ) ;
V_151 = F_19 ( V_150 -> V_49 . V_156 ) ;
V_152 = F_19 ( V_150 -> V_53 [ 3 - 1 ] . V_157 ) ;
if ( V_152 < V_151 )
V_151 = V_152 ;
V_5 -> V_158 = V_151 ;
V_5 -> V_25 = F_18 ( V_150 , V_3 -> V_48 ) ;
F_39 ( V_5 ) ;
} else {
struct V_117 * V_118 ;
V_118 = F_46 ( V_102 , sizeof( * V_118 ) ) ;
F_22 ( V_5 , L_37 ,
V_118 -> V_119 , V_118 -> V_120 ) ;
F_42 ( V_5 , - V_121 ) ;
}
V_89:
F_54 ( V_102 ) ;
V_96:
F_24 ( & V_5 -> V_15 ) ;
V_115:
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static bool
F_64 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_13 == V_159 )
return true ;
if ( ( V_5 -> V_7 . V_13 & V_160 ) &&
( V_3 -> V_161 & V_162 ) )
return true ;
if ( ( V_5 -> V_7 . V_13 & V_163 ) &&
( V_3 -> V_161 & V_164 ) )
return true ;
return false ;
}
static void F_38 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
if ( ! F_64 ( V_3 , V_5 ) ) {
F_22 ( V_5 , L_38 ) ;
F_20 ( V_5 , V_95 ) ;
return;
}
F_22 ( V_5 , L_39 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_91 ) ;
V_5 -> V_25 = V_26 ;
V_102 = F_55 ( V_3 , sizeof( struct V_45 ) ) ;
if ( ! V_102 ) {
F_22 ( V_5 , L_40 , V_165 ) ;
F_42 ( V_5 , - V_125 ) ;
return;
}
V_5 -> V_23 = V_3 -> V_23 ;
F_23 ( & V_5 -> V_8 ) ;
if ( ! V_3 -> V_33 . V_128 ( V_3 , V_5 -> V_7 . V_4 , V_102 , V_166 ,
F_62 , V_5 ,
2 * V_3 -> V_24 ) ) {
F_42 ( V_5 , - V_129 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
}
static void F_65 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_149 )
{
struct V_1 * V_5 = V_149 ;
struct {
struct V_167 V_168 ;
struct V_169 V_170 ;
} * V_171 ;
struct V_169 V_172 ;
struct V_117 * V_118 ;
struct V_65 * V_66 ;
T_1 V_13 = V_14 ;
T_1 V_173 = 0 ;
T_2 V_153 ;
enum V_174 V_175 ;
F_22 ( V_5 , L_41 , F_51 ( V_102 ) ) ;
if ( V_102 == F_52 ( - V_99 ) )
goto V_115;
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 != V_92 ) {
F_22 ( V_5 , L_42
L_27 , F_16 ( V_5 ) ) ;
if ( F_50 ( V_102 ) )
goto V_96;
goto V_89;
}
if ( F_50 ( V_102 ) ) {
F_42 ( V_5 , F_53 ( V_102 ) ) ;
goto V_96;
}
V_5 -> V_7 . V_13 = V_14 ;
V_153 = F_47 ( V_102 ) ;
if ( V_153 == V_123 ) {
V_171 = F_46 ( V_102 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
goto V_89;
V_175 = ( V_171 -> V_170 . V_176 & V_177 ) ;
F_22 ( V_5 , L_43 ,
V_171 -> V_170 . V_176 , V_171 -> V_170 . V_178 ) ;
V_5 -> V_178 = V_171 -> V_170 . V_178 ;
if ( V_175 != V_179 ) {
if ( V_175 == V_180 )
F_41 ( V_5 , - V_181 ) ;
else
F_42 ( V_5 , - V_181 ) ;
goto V_89;
}
if ( V_171 -> V_168 . V_182 < sizeof( V_171 -> V_170 ) )
goto V_89;
V_173 = F_48 ( V_171 -> V_170 . V_183 ) ;
if ( V_173 & V_184 )
V_5 -> V_21 |= V_185 ;
if ( V_173 & V_186 )
V_5 -> V_21 |= V_187 ;
V_66 = V_80 [ V_5 -> V_178 ] ;
if ( V_66 ) {
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_66 -> V_168 ( V_5 , V_171 -> V_168 . V_182 ,
& V_171 -> V_170 , & V_172 ) ;
}
if ( V_5 -> V_178 != V_188 ||
! ( V_171 -> V_170 . V_176 & V_189 ) ) {
V_173 &= ~ V_164 ;
}
V_5 -> V_71 = V_190 ;
if ( V_173 & V_162 )
V_13 |= V_191 ;
if ( V_173 & V_164 )
V_13 |= V_192 ;
V_5 -> V_7 . V_13 = V_13 ;
F_40 ( V_5 ) ;
} else {
V_118 = F_46 ( V_102 , sizeof( * V_118 ) ) ;
F_22 ( V_5 , L_44 ,
V_118 -> V_119 , V_118 -> V_120 ) ;
F_42 ( V_5 , V_121 ) ;
}
V_89:
F_54 ( V_102 ) ;
V_96:
F_24 ( & V_5 -> V_15 ) ;
V_115:
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_39 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct {
struct V_167 V_168 ;
struct V_169 V_170 ;
} * V_171 ;
struct V_101 * V_102 ;
struct V_65 * V_66 ;
if ( V_5 -> V_7 . V_4 >= V_193 ) {
F_32 ( V_5 ) ;
return;
}
if ( ! ( V_3 -> V_161 & V_162 ) ) {
F_32 ( V_5 ) ;
return;
}
F_22 ( V_5 , L_45 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_92 ) ;
V_102 = F_55 ( V_3 , sizeof( * V_171 ) ) ;
if ( ! V_102 ) {
F_42 ( V_5 , - V_125 ) ;
return;
}
F_66 ( V_3 , V_102 ) ;
V_66 = V_80 [ V_188 ] ;
if ( V_66 ) {
V_171 = F_46 ( V_102 , sizeof( * V_171 ) ) ;
V_66 -> V_168 ( V_5 , sizeof( V_171 -> V_170 ) , NULL , & V_171 -> V_170 ) ;
}
F_67 ( V_102 , V_194 , V_5 -> V_7 . V_4 ,
F_68 ( V_3 -> V_70 ) , V_195 ,
V_196 | V_197 | V_198 , 0 ) ;
F_23 ( & V_5 -> V_8 ) ;
if ( ! F_69 ( V_3 , V_102 , F_65 ,
NULL , V_5 , 2 * V_3 -> V_24 ) ) {
F_42 ( V_5 , - V_129 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
}
static void F_70 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_149 )
{
struct V_1 * V_5 = V_149 ;
T_2 V_153 ;
F_22 ( V_5 , L_46 , F_51 ( V_102 ) ) ;
if ( V_102 == F_52 ( - V_99 ) )
goto V_115;
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 != V_93 ) {
F_22 ( V_5 , L_47
L_27 , F_16 ( V_5 ) ) ;
if ( F_50 ( V_102 ) )
goto V_96;
goto V_89;
}
if ( F_50 ( V_102 ) ) {
F_41 ( V_5 , F_53 ( V_102 ) ) ;
goto V_96;
}
V_153 = F_47 ( V_102 ) ;
if ( V_153 == V_123 ) {
struct V_199 * V_200 ;
T_1 V_201 ;
T_1 V_202 ;
V_200 = F_46 ( V_102 , sizeof( * V_200 ) ) ;
if ( V_200 ) {
V_201 = F_48 ( V_200 -> V_203 ) ;
V_202 = F_48 ( V_200 -> V_204 ) ;
if ( V_202 == 0 )
V_202 = 1 ;
if ( V_202 > V_5 -> V_24 )
V_5 -> V_24 = V_202 ;
V_202 = F_48 ( V_200 -> V_205 ) ;
if ( V_201 & V_206 )
V_202 /= 1000000 ;
if ( V_202 == 0 )
V_202 = 1 ;
if ( V_202 > V_5 -> V_23 )
V_5 -> V_23 = V_202 ;
}
}
F_32 ( V_5 ) ;
V_89:
F_54 ( V_102 ) ;
V_96:
F_24 ( & V_5 -> V_15 ) ;
V_115:
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_40 ( struct V_1 * V_5 )
{
struct V_101 * V_102 ;
struct V_2 * V_3 = V_5 -> V_16 ;
F_22 ( V_5 , L_48 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_93 ) ;
V_102 = F_55 ( V_3 , sizeof( struct V_207 ) ) ;
if ( ! V_102 ) {
F_42 ( V_5 , - V_125 ) ;
return;
}
F_23 ( & V_5 -> V_8 ) ;
if ( ! V_3 -> V_33 . V_128 ( V_3 , V_5 -> V_7 . V_4 , V_102 , V_208 ,
F_70 , V_5 ,
2 * V_3 -> V_24 ) ) {
F_42 ( V_5 , - V_129 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
}
static void F_71 ( struct V_1 * V_5 ,
struct V_101 * V_209 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
struct V_199 * V_200 ;
struct V_132 V_133 ;
F_22 ( V_5 , L_49 ) ;
V_102 = F_55 ( V_3 , sizeof( * V_200 ) ) ;
if ( ! V_102 ) {
V_133 . V_135 = V_210 ;
V_133 . V_137 = V_211 ;
F_61 ( V_209 , V_116 , & V_133 ) ;
goto V_212;
}
V_200 = F_46 ( V_102 , sizeof( * V_200 ) ) ;
V_200 -> V_213 = V_123 ;
V_200 -> V_204 = F_72 ( V_3 -> V_24 ) ;
V_200 -> V_205 = F_72 ( V_3 -> V_23 ) ;
V_200 -> V_203 = 0 ;
F_60 ( V_102 , V_209 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
V_212:
F_54 ( V_209 ) ;
}
static void F_73 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_149 )
{
struct V_1 * V_5 = V_149 ;
struct V_2 * V_3 = V_5 -> V_16 ;
F_58 ( V_3 , F_74 ( V_112 ) -> V_214 ,
L_50 , F_51 ( V_102 ) ) ;
if ( ! F_50 ( V_102 ) )
F_54 ( V_102 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_37 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
F_22 ( V_5 , L_51 ,
F_16 ( V_5 ) ) ;
V_102 = F_55 ( V_3 , sizeof( struct V_215 ) ) ;
if ( ! V_102 )
return;
F_23 ( & V_5 -> V_8 ) ;
if ( ! V_3 -> V_33 . V_128 ( V_3 , V_5 -> V_7 . V_4 , V_102 , V_216 ,
F_73 , V_5 , 0 ) )
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_75 ( struct V_111 * V_112 , struct V_101 * V_102 ,
void * V_149 )
{
struct V_1 * V_5 = V_149 ;
struct V_217 * V_218 ;
T_2 V_153 ;
F_22 ( V_5 , L_52 ) ;
if ( V_102 == F_52 ( - V_99 ) )
goto V_115;
F_21 ( & V_5 -> V_15 ) ;
if ( V_5 -> V_17 != V_94 ) {
F_22 ( V_5 , L_53 ,
F_16 ( V_5 ) ) ;
if ( F_50 ( V_102 ) )
goto V_96;
goto V_89;
}
if ( F_50 ( V_102 ) ) {
F_41 ( V_5 , F_53 ( V_102 ) ) ;
goto V_96;
}
V_153 = F_47 ( V_102 ) ;
V_218 = F_46 ( V_102 , sizeof( * V_218 ) ) ;
if ( V_153 != V_123 || ! V_218 ||
F_76 ( V_218 -> V_219 ) != V_5 -> V_7 . V_4 ||
F_63 ( & V_218 -> V_220 ) != V_5 -> V_7 . V_12 ||
F_63 ( & V_218 -> V_221 ) != V_5 -> V_7 . V_11 ) {
F_22 ( V_5 , L_54 ) ;
F_30 ( V_5 ) ;
} else {
F_22 ( V_5 , L_55 ) ;
F_32 ( V_5 ) ;
}
V_89:
F_54 ( V_102 ) ;
V_96:
F_24 ( & V_5 -> V_15 ) ;
V_115:
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
static void F_34 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
F_22 ( V_5 , L_56 ,
F_16 ( V_5 ) ) ;
F_20 ( V_5 , V_94 ) ;
V_102 = F_55 ( V_3 , sizeof( struct V_217 ) ) ;
if ( ! V_102 ) {
F_42 ( V_5 , - V_125 ) ;
return;
}
F_23 ( & V_5 -> V_8 ) ;
if ( ! V_3 -> V_33 . V_128 ( V_3 , V_5 -> V_7 . V_4 , V_102 , V_222 ,
F_75 , V_5 ,
2 * V_3 -> V_24 ) ) {
F_42 ( V_5 , - V_129 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
}
}
static void F_77 ( struct V_1 * V_5 ,
struct V_101 * V_209 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
struct V_217 * V_218 ;
struct V_132 V_133 ;
F_22 ( V_5 , L_57 ) ;
V_218 = F_46 ( V_209 , sizeof( * V_218 ) ) ;
if ( ! V_218 ) {
V_133 . V_135 = V_223 ;
V_133 . V_137 = V_141 ;
F_61 ( V_209 , V_116 , & V_133 ) ;
goto V_212;
}
V_102 = F_55 ( V_3 , sizeof( * V_218 ) ) ;
if ( ! V_102 )
goto V_212;
F_78 ( V_3 , V_102 ) ;
V_218 = F_46 ( V_102 , sizeof( * V_218 ) ) ;
V_218 -> V_224 = V_123 ;
F_60 ( V_102 , V_209 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
V_212:
F_54 ( V_209 ) ;
}
static void F_79 ( struct V_1 * V_5 ,
struct V_101 * V_130 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_132 V_133 ;
struct V_231 * V_232 ;
F_22 ( V_5 , L_58 ,
F_16 ( V_5 ) ) ;
V_226 = F_46 ( V_130 , sizeof( * V_226 ) ) ;
if ( ! V_226 ) {
V_133 . V_135 = V_223 ;
V_133 . V_137 = V_141 ;
goto V_233;
}
V_102 = F_55 ( V_3 , sizeof( * V_228 ) ) ;
if ( ! V_102 ) {
V_133 . V_135 = V_210 ;
V_133 . V_137 = V_211 ;
goto V_233;
}
V_228 = F_46 ( V_102 , sizeof( * V_228 ) ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_234 = V_123 ;
V_230 = & V_228 -> V_235 ;
if ( V_3 -> V_33 . V_236 ) {
V_3 -> V_33 . V_236 ( V_3 , V_230 ) ;
} else {
F_80 ( V_3 -> V_70 ) ;
V_232 = & V_3 -> V_237 ;
V_230 -> V_238 = F_72 ( V_232 -> V_239 ) ;
V_230 -> V_240 = F_72 ( V_232 -> V_241 ) ;
V_230 -> V_242 = F_72 ( V_232 -> V_243 ) ;
V_230 -> V_244 = F_72 ( V_232 -> V_245 ) ;
V_230 -> V_246 = F_72 ( V_232 -> V_247 ) ;
V_230 -> V_248 = F_72 ( V_232 -> V_249 ) ;
}
F_60 ( V_102 , V_130 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
goto V_89;
V_233:
F_61 ( V_130 , V_116 , & V_133 ) ;
V_89:
F_54 ( V_130 ) ;
}
static void F_81 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
struct V_1 * V_5 ;
struct V_132 V_250 ;
V_5 = F_1 ( V_3 , F_57 ( V_102 ) ) ;
if ( ! V_5 ) {
F_58 ( V_3 , F_57 ( V_102 ) ,
L_59 ,
F_47 ( V_102 ) ) ;
goto V_139;
}
F_21 ( & V_5 -> V_15 ) ;
switch ( V_5 -> V_17 ) {
case V_92 :
case V_93 :
case V_87 :
case V_94 :
break;
case V_91 :
if ( F_47 ( V_102 ) == V_251 ) {
F_22 ( V_5 , L_60
L_61 ,
F_16 ( V_5 ) ) ;
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
goto V_252;
}
default:
F_22 ( V_5 ,
L_62 ,
F_47 ( V_102 ) , F_16 ( V_5 ) ) ;
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
goto V_139;
}
switch ( F_47 ( V_102 ) ) {
case V_251 :
F_82 ( V_5 , V_102 ) ;
break;
case V_253 :
F_83 ( V_5 , V_102 ) ;
break;
case V_222 :
F_77 ( V_5 , V_102 ) ;
break;
case V_254 :
F_61 ( V_102 , V_254 , NULL ) ;
F_54 ( V_102 ) ;
break;
case V_255 :
F_61 ( V_102 , V_255 , NULL ) ;
F_54 ( V_102 ) ;
break;
case V_256 :
F_79 ( V_5 , V_102 ) ;
break;
case V_208 :
F_71 ( V_5 , V_102 ) ;
break;
default:
F_54 ( V_102 ) ;
break;
}
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
return;
V_139:
V_250 . V_135 = V_210 ;
V_250 . V_137 = V_257 ;
F_61 ( V_102 , V_116 , & V_250 ) ;
F_54 ( V_102 ) ;
return;
V_252:
V_250 . V_135 = V_145 ;
V_250 . V_137 = V_138 ;
F_61 ( V_102 , V_116 , & V_250 ) ;
F_54 ( V_102 ) ;
return;
}
void F_84 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
struct V_132 V_250 ;
switch ( F_47 ( V_102 ) ) {
case V_107 :
F_56 ( V_3 , V_102 ) ;
break;
case V_166 :
F_85 ( V_3 , V_102 ) ;
break;
case V_216 :
F_86 ( V_3 , V_102 ) ;
break;
case V_251 :
case V_253 :
case V_222 :
case V_254 :
case V_255 :
case V_256 :
case V_208 :
F_81 ( V_3 , V_102 ) ;
break;
default:
V_250 . V_135 = V_136 ;
V_250 . V_137 = V_138 ;
F_61 ( V_102 , V_116 , & V_250 ) ;
F_54 ( V_102 ) ;
break;
}
}
static void F_85 ( struct V_2 * V_3 ,
struct V_101 * V_130 )
{
struct V_131 * V_36 ;
struct V_1 * V_5 ;
struct V_101 * V_102 = V_130 ;
struct V_45 * V_258 ;
struct V_132 V_133 ;
T_1 V_134 ;
V_134 = F_57 ( V_102 ) ;
F_58 ( V_3 , V_134 , L_63 ) ;
V_258 = F_46 ( V_102 , sizeof( * V_258 ) ) ;
if ( ! V_258 ) {
F_58 ( V_3 , V_134 , L_64 ) ;
V_133 . V_135 = V_223 ;
V_133 . V_137 = V_141 ;
goto V_139;
}
V_36 = & V_3 -> V_36 ;
F_21 ( & V_36 -> V_86 ) ;
V_5 = F_6 ( V_3 , V_134 ) ;
if ( ! V_5 ) {
F_24 ( & V_36 -> V_86 ) ;
V_133 . V_135 = V_210 ;
V_133 . V_137 = V_211 ;
goto V_139;
}
F_21 ( & V_5 -> V_15 ) ;
F_24 ( & V_36 -> V_86 ) ;
V_5 -> V_7 . V_12 = F_63 ( & V_258 -> V_154 ) ;
V_5 -> V_7 . V_11 = F_63 ( & V_258 -> V_155 ) ;
switch ( V_5 -> V_17 ) {
case V_18 :
F_22 ( V_5 , L_65 ) ;
break;
case V_95 :
F_22 ( V_5 , L_66 ) ;
break;
case V_91 :
F_22 ( V_5 , L_67 ) ;
if ( V_5 -> V_7 . V_12 < V_3 -> V_127 ) {
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_259 ;
V_133 . V_137 = V_138 ;
goto V_139;
}
break;
case V_92 :
case V_93 :
case V_87 :
case V_94 :
F_22 ( V_5 , L_68
L_69 , V_5 -> V_17 ) ;
break;
case V_90 :
case V_83 :
F_22 ( V_5 , L_70 ,
F_16 ( V_5 ) ) ;
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_145 ;
V_133 . V_137 = V_138 ;
goto V_139;
}
if ( ! F_64 ( V_3 , V_5 ) ) {
F_22 ( V_5 , L_71 ) ;
F_24 ( & V_5 -> V_15 ) ;
V_133 . V_135 = V_140 ;
V_133 . V_137 = V_138 ;
goto V_139;
}
V_5 -> V_25 = F_18 ( V_258 , V_3 -> V_48 ) ;
V_102 = F_55 ( V_3 , sizeof( * V_258 ) ) ;
if ( ! V_102 )
goto V_89;
F_87 ( V_3 , V_102 , V_123 ) ;
F_60 ( V_102 , V_130 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
F_39 ( V_5 ) ;
V_89:
F_24 ( & V_5 -> V_15 ) ;
F_54 ( V_130 ) ;
return;
V_139:
F_61 ( V_102 , V_116 , & V_133 ) ;
F_54 ( V_102 ) ;
}
static void F_82 ( struct V_1 * V_5 ,
struct V_101 * V_130 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
struct {
struct V_167 V_168 ;
struct V_169 V_170 ;
} * V_171 ;
struct V_169 * V_260 ;
struct V_169 * V_170 ;
unsigned int V_261 ;
unsigned int V_262 ;
enum V_174 V_263 ;
struct V_132 V_133 ;
struct V_65 * V_66 ;
F_22 ( V_5 , L_72 ,
F_16 ( V_5 ) ) ;
V_261 = F_88 ( V_130 ) - sizeof( struct V_264 ) ;
V_171 = F_46 ( V_130 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
goto V_265;
V_262 = F_19 ( V_171 -> V_168 . V_266 ) ;
if ( ( V_262 % 4 ) != 0 || V_262 > V_261 || V_262 < 16 )
goto V_265;
if ( V_262 < V_261 )
V_261 = V_262 ;
V_262 = V_171 -> V_168 . V_182 ;
if ( ( V_262 % 4 ) != 0 || V_262 < sizeof( * V_170 ) ||
V_262 > V_261 || V_261 < sizeof( * V_171 ) || V_262 < 12 )
goto V_265;
V_260 = & V_171 -> V_170 ;
V_102 = F_55 ( V_3 , V_261 ) ;
if ( ! V_102 ) {
V_133 . V_135 = V_210 ;
V_133 . V_137 = V_211 ;
goto V_139;
}
V_171 = F_46 ( V_102 , V_261 ) ;
F_89 ( ! V_171 ) ;
memset ( V_171 , 0 , V_261 ) ;
V_171 -> V_168 . V_267 = V_123 ;
V_171 -> V_168 . V_182 = V_262 ;
V_171 -> V_168 . V_266 = F_90 ( V_261 ) ;
V_261 -= sizeof( struct V_167 ) ;
V_170 = & V_171 -> V_170 ;
F_21 ( & V_78 ) ;
while ( V_261 >= V_262 ) {
V_5 -> V_178 = V_260 -> V_178 ;
V_170 -> V_178 = V_260 -> V_178 ;
V_170 -> V_268 = V_260 -> V_268 ;
V_263 = 0 ;
if ( V_260 -> V_178 < V_79 ) {
enum V_174 V_269 = 0 , V_270 = 0 ;
V_66 = V_271 [ V_260 -> V_178 ] ;
if ( V_66 )
V_269 = V_66 -> V_168 ( V_5 , V_262 , V_260 , V_170 ) ;
V_66 = V_80 [ V_260 -> V_178 ] ;
if ( V_66 )
V_270 = V_66 -> V_168 ( V_5 , V_262 , V_260 , V_170 ) ;
if ( ! V_269 || V_270 == V_179 )
V_263 = V_270 ;
else
V_263 = V_269 ;
F_22 ( V_5 , L_73
L_74 ,
V_260 -> V_178 , V_269 , V_270 ) ;
}
if ( ! V_263 ) {
if ( V_170 -> V_176 & V_189 )
V_263 |= V_180 ;
else
V_263 |= V_272 ;
}
V_170 -> V_176 |= V_263 ;
V_261 -= V_262 ;
V_260 = (struct V_169 * ) ( ( char * ) V_260 + V_262 ) ;
V_170 = (struct V_169 * ) ( ( char * ) V_170 + V_262 ) ;
}
F_24 ( & V_78 ) ;
F_60 ( V_102 , V_130 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
goto V_212;
V_265:
V_133 . V_135 = V_223 ;
V_133 . V_137 = V_141 ;
V_139:
F_61 ( V_130 , V_116 , & V_133 ) ;
V_212:
F_54 ( V_130 ) ;
}
static void F_83 ( struct V_1 * V_5 ,
struct V_101 * V_130 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_101 * V_102 ;
struct {
struct V_273 V_81 ;
struct V_169 V_170 ;
} * V_171 ;
struct V_169 * V_260 ;
struct V_169 * V_170 ;
unsigned int V_261 ;
unsigned int V_262 ;
struct V_132 V_133 ;
F_22 ( V_5 , L_75 ,
F_16 ( V_5 ) ) ;
V_261 = F_88 ( V_130 ) - sizeof( struct V_264 ) ;
V_171 = F_46 ( V_130 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
goto V_265;
V_262 = F_19 ( V_171 -> V_81 . V_274 ) ;
if ( V_262 != 20 )
goto V_265;
if ( V_262 < V_261 )
V_261 = V_262 ;
V_260 = & V_171 -> V_170 ;
V_102 = F_55 ( V_3 , V_261 ) ;
if ( ! V_102 ) {
V_133 . V_135 = V_210 ;
V_133 . V_137 = V_211 ;
goto V_139;
}
V_171 = F_46 ( V_102 , V_261 ) ;
F_89 ( ! V_171 ) ;
memset ( V_171 , 0 , V_261 ) ;
V_171 -> V_81 . V_275 = V_123 ;
V_171 -> V_81 . V_276 = 0x10 ;
V_171 -> V_81 . V_274 = F_90 ( V_261 ) ;
V_170 = & V_171 -> V_170 ;
V_170 -> V_178 = V_260 -> V_178 ;
V_170 -> V_268 = V_260 -> V_268 ;
V_170 -> V_176 = V_179 ;
F_39 ( V_5 ) ;
F_60 ( V_102 , V_130 , V_147 , 0 ) ;
V_3 -> V_33 . V_148 ( V_3 , V_102 ) ;
goto V_212;
V_265:
V_133 . V_135 = V_223 ;
V_133 . V_137 = V_141 ;
V_139:
F_61 ( V_130 , V_116 , & V_133 ) ;
V_212:
F_54 ( V_130 ) ;
}
static void F_86 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
struct V_1 * V_5 ;
T_1 V_134 ;
F_61 ( V_102 , V_123 , NULL ) ;
V_134 = F_57 ( V_102 ) ;
V_5 = F_1 ( V_3 , V_134 ) ;
if ( V_5 ) {
F_21 ( & V_5 -> V_15 ) ;
F_22 ( V_5 , L_76 ,
F_16 ( V_5 ) ) ;
F_35 ( V_5 , V_76 ) ;
F_24 ( & V_5 -> V_15 ) ;
F_27 ( & V_5 -> V_8 , F_13 ) ;
} else
F_58 ( V_3 , V_134 ,
L_77 ) ;
F_54 ( V_102 ) ;
}
void F_91 ( void )
{
F_92 ( V_88 ) ;
}
static int F_93 ( struct V_1 * V_5 , T_1 V_277 ,
const struct V_169 * V_260 ,
struct V_169 * V_170 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
T_1 V_173 ;
V_173 = F_48 ( V_260 -> V_183 ) ;
V_5 -> V_7 . V_13 = V_14 ;
if ( V_173 & V_162 )
V_5 -> V_7 . V_13 |= V_191 ;
if ( V_173 & V_164 )
V_5 -> V_7 . V_13 |= V_192 ;
if ( V_173 & V_184 )
V_5 -> V_21 |= V_185 ;
V_5 -> V_71 = V_190 ;
if ( ! ( V_3 -> V_161 & V_162 ) )
return 0 ;
V_170 -> V_176 |= V_260 -> V_176 & V_189 ;
V_173 = F_48 ( V_170 -> V_183 ) ;
V_170 -> V_183 = F_72 ( V_173 | V_3 -> V_161 ) ;
return V_179 ;
}
static int F_94 ( struct V_1 * V_5 , T_1 V_277 ,
const struct V_169 * V_260 ,
struct V_169 * V_170 )
{
if ( V_260 -> V_176 & V_189 )
return V_272 ;
return V_179 ;
}
int F_95 ( void )
{
V_88 = F_96 ( L_78 ) ;
if ( ! V_88 )
return - V_278 ;
return 0 ;
}
void F_97 ( void )
{
F_98 ( V_88 ) ;
}
void F_99 ( struct V_41 * V_42 )
{
struct V_59 * V_60 = V_42 -> V_72 ;
struct V_2 * V_3 = V_60 -> V_16 ;
V_3 -> V_33 . V_82 ( V_3 , 0 , V_42 -> V_4 ) ;
V_3 -> V_33 . V_82 ( V_3 , V_42 -> V_4 , 0 ) ;
}
