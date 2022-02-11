void
F_1 (
struct V_1 * V_2 )
{
F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
T_1 *
F_4 (
T_2 * V_2 ,
T_3 type )
{
T_1 * V_3 ;
F_5 ( V_2 -> V_4 ) ;
V_3 = F_6 ( V_2 , type , V_5 ) ;
V_3 -> V_6 |= V_7 ;
return V_3 ;
}
T_1 *
F_6 (
T_2 * V_2 ,
T_3 type ,
T_4 V_8 )
{
T_1 * V_3 ;
F_7 ( V_2 -> V_4 -> V_9 . V_10 == V_11 ) ;
F_8 ( & V_2 -> V_12 ) ;
V_3 = F_9 ( V_13 , V_8 ) ;
V_3 -> V_14 = V_15 ;
V_3 -> V_16 = type ;
V_3 -> V_17 = V_2 ;
F_10 ( & V_3 -> V_18 ) ;
F_10 ( & V_3 -> V_19 ) ;
return V_3 ;
}
STATIC void
F_11 (
struct V_20 * V_3 )
{
F_12 ( & V_3 -> V_19 ) ;
F_13 ( V_3 -> V_17 , & V_3 -> V_19 , false ) ;
F_14 ( & V_3 -> V_17 -> V_12 ) ;
if ( V_3 -> V_6 & V_7 )
F_15 ( V_3 -> V_17 -> V_4 ) ;
F_16 ( V_3 ) ;
F_17 ( V_13 , V_3 ) ;
}
STATIC T_1 *
F_18 (
T_1 * V_3 )
{
T_1 * V_21 ;
V_21 = F_9 ( V_13 , V_5 ) ;
V_21 -> V_14 = V_15 ;
V_21 -> V_16 = V_3 -> V_16 ;
V_21 -> V_17 = V_3 -> V_17 ;
F_10 ( & V_21 -> V_18 ) ;
F_10 ( & V_21 -> V_19 ) ;
ASSERT ( V_3 -> V_6 & V_22 ) ;
ASSERT ( V_3 -> V_23 != NULL ) ;
V_21 -> V_6 = V_22 |
( V_3 -> V_6 & V_24 ) |
( V_3 -> V_6 & V_7 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_21 -> V_23 = F_19 ( V_3 -> V_23 ) ;
V_21 -> V_25 = V_3 -> V_25 - V_3 -> V_26 ;
V_3 -> V_25 = V_3 -> V_26 ;
V_21 -> V_27 = V_3 -> V_27 - V_3 -> V_28 ;
V_3 -> V_27 = V_3 -> V_28 ;
V_21 -> V_29 = V_3 -> V_29 ;
F_20 ( V_3 , V_21 ) ;
F_8 ( & V_3 -> V_17 -> V_12 ) ;
return V_21 ;
}
int
F_21 (
struct V_20 * V_3 ,
struct V_30 * V_31 ,
T_3 V_32 ,
T_3 V_33 )
{
int error = 0 ;
bool V_34 = ( V_3 -> V_6 & V_24 ) != 0 ;
F_22 ( & V_3 -> V_29 , V_35 ) ;
if ( V_32 > 0 ) {
error = F_23 ( V_3 -> V_17 , - ( ( V_36 ) V_32 ) , V_34 ) ;
if ( error != 0 ) {
F_24 ( & V_3 -> V_29 , V_35 ) ;
return - V_37 ;
}
V_3 -> V_25 += V_32 ;
}
if ( V_31 -> V_38 > 0 ) {
bool V_39 = false ;
ASSERT ( V_3 -> V_40 == 0 ||
V_3 -> V_40 == V_31 -> V_38 ) ;
ASSERT ( V_3 -> V_41 == 0 ||
V_3 -> V_41 == V_31 -> V_42 ) ;
if ( V_31 -> V_43 & V_22 ) {
V_3 -> V_6 |= V_22 ;
V_39 = true ;
} else {
ASSERT ( V_3 -> V_23 == NULL ) ;
ASSERT ( ! ( V_3 -> V_6 & V_22 ) ) ;
}
if ( V_3 -> V_23 != NULL ) {
ASSERT ( V_31 -> V_43 & V_22 ) ;
error = F_25 ( V_3 -> V_17 , V_3 -> V_23 ) ;
} else {
error = F_26 ( V_3 -> V_17 ,
V_31 -> V_38 ,
V_31 -> V_42 ,
& V_3 -> V_23 , V_44 ,
V_39 , V_3 -> V_16 ) ;
}
if ( error )
goto V_45;
V_3 -> V_40 = V_31 -> V_38 ;
V_3 -> V_41 = V_31 -> V_42 ;
}
if ( V_33 > 0 ) {
error = F_27 ( V_3 -> V_17 , - ( ( V_36 ) V_33 ) ) ;
if ( error ) {
error = - V_37 ;
goto V_46;
}
V_3 -> V_27 += V_33 ;
}
return 0 ;
V_46:
if ( V_31 -> V_38 > 0 ) {
F_28 ( V_3 -> V_17 , V_3 -> V_23 , NULL , false ) ;
V_3 -> V_23 = NULL ;
V_3 -> V_40 = 0 ;
V_3 -> V_6 &= ~ V_22 ;
}
V_45:
if ( V_32 > 0 ) {
F_23 ( V_3 -> V_17 , - ( ( V_36 ) V_32 ) , V_34 ) ;
V_3 -> V_25 = 0 ;
}
F_24 ( & V_3 -> V_29 , V_35 ) ;
return error ;
}
void
F_29 (
T_1 * V_3 ,
T_3 V_47 ,
V_36 V_48 )
{
T_5 V_49 = ( V_50 | V_51 ) ;
T_2 * V_2 = V_3 -> V_17 ;
switch ( V_47 ) {
case V_52 :
V_3 -> V_53 += V_48 ;
if ( F_30 ( & V_2 -> V_54 ) )
V_49 &= ~ V_51 ;
break;
case V_55 :
V_3 -> V_56 += V_48 ;
if ( F_30 ( & V_2 -> V_54 ) )
V_49 &= ~ V_51 ;
break;
case V_57 :
if ( V_48 < 0 ) {
V_3 -> V_26 += ( T_3 ) - V_48 ;
ASSERT ( V_3 -> V_26 <= V_3 -> V_25 ) ;
}
V_3 -> V_58 += V_48 ;
if ( F_30 ( & V_2 -> V_54 ) )
V_49 &= ~ V_51 ;
break;
case V_59 :
ASSERT ( V_48 < 0 ) ;
V_3 -> V_60 += V_48 ;
if ( F_30 ( & V_2 -> V_54 ) )
V_49 &= ~ V_51 ;
break;
case V_61 :
if ( V_48 < 0 ) {
V_3 -> V_28 += ( T_3 ) - V_48 ;
ASSERT ( V_3 -> V_28 <= V_3 -> V_27 ) ;
}
V_3 -> V_62 += V_48 ;
break;
case V_63 :
ASSERT ( V_48 < 0 ) ;
V_3 -> V_64 += V_48 ;
break;
case V_65 :
ASSERT ( V_48 > 0 ) ;
V_3 -> V_66 += V_48 ;
break;
case V_67 :
ASSERT ( V_48 > 0 ) ;
V_3 -> V_68 += V_48 ;
break;
case V_69 :
V_3 -> V_70 += V_48 ;
break;
case V_71 :
V_3 -> V_72 += V_48 ;
break;
case V_73 :
V_3 -> V_74 += V_48 ;
break;
case V_75 :
V_3 -> V_76 += V_48 ;
break;
case V_77 :
V_3 -> V_78 += V_48 ;
break;
case V_79 :
V_3 -> V_80 += V_48 ;
break;
default:
ASSERT ( 0 ) ;
return;
}
V_3 -> V_6 |= V_49 ;
}
STATIC void
F_31 (
T_1 * V_3 )
{
T_6 * V_81 ;
T_7 * V_82 ;
int V_83 = 0 ;
V_82 = F_32 ( V_3 , V_3 -> V_17 , 0 ) ;
V_81 = F_33 ( V_82 ) ;
ASSERT ( ( V_3 -> V_58 + V_3 -> V_60 ) ==
( V_3 -> V_84 + V_3 -> V_85 +
V_3 -> V_86 ) ) ;
if ( ! F_30 ( & ( V_3 -> V_17 -> V_54 ) ) ) {
if ( V_3 -> V_53 )
F_34 ( & V_81 -> V_87 , V_3 -> V_53 ) ;
if ( V_3 -> V_56 )
F_34 ( & V_81 -> V_88 , V_3 -> V_56 ) ;
if ( V_3 -> V_58 )
F_34 ( & V_81 -> V_89 , V_3 -> V_58 ) ;
if ( V_3 -> V_60 )
F_34 ( & V_81 -> V_89 , V_3 -> V_60 ) ;
}
if ( V_3 -> V_62 )
F_34 ( & V_81 -> V_90 , V_3 -> V_62 ) ;
if ( V_3 -> V_64 )
F_34 ( & V_81 -> V_90 , V_3 -> V_64 ) ;
if ( V_3 -> V_66 ) {
F_34 ( & V_81 -> V_91 , V_3 -> V_66 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_68 ) {
F_35 ( & V_81 -> V_92 , V_3 -> V_68 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_70 ) {
V_81 -> V_93 += V_3 -> V_70 ;
V_83 = 1 ;
}
if ( V_3 -> V_72 ) {
F_35 ( & V_81 -> V_94 , V_3 -> V_72 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_74 ) {
F_35 ( & V_81 -> V_95 , V_3 -> V_74 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_76 ) {
F_34 ( & V_81 -> V_96 , V_3 -> V_76 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_78 ) {
F_34 ( & V_81 -> V_97 , V_3 -> V_78 ) ;
V_83 = 1 ;
}
if ( V_3 -> V_80 ) {
V_81 -> V_98 += V_3 -> V_80 ;
V_83 = 1 ;
}
F_36 ( V_3 , V_82 , V_99 ) ;
if ( V_83 )
F_37 ( V_3 , V_82 , 0 , sizeof( T_6 ) - 1 ) ;
else
F_37 ( V_3 , V_82 , F_38 ( T_6 , V_87 ) ,
F_38 ( T_6 , V_90 ) +
sizeof( V_81 -> V_90 ) - 1 ) ;
}
STATIC int
F_39 (
T_8 * V_47 ,
T_9 V_48 )
{
T_9 V_100 = * V_47 ;
V_100 += V_48 ;
if ( V_100 < 0 ) {
ASSERT ( 0 ) ;
return - V_101 ;
}
* V_47 = V_100 ;
return 0 ;
}
STATIC int
F_40 (
T_5 * V_47 ,
T_10 V_48 )
{
T_10 V_100 = * V_47 ;
V_100 += V_48 ;
if ( V_100 < 0 ) {
ASSERT ( 0 ) ;
return - V_101 ;
}
* V_47 = V_100 ;
return 0 ;
}
STATIC int
F_41 (
T_11 * V_47 ,
V_36 V_48 )
{
V_36 V_100 = * V_47 ;
V_100 += V_48 ;
if ( V_100 < 0 ) {
ASSERT ( 0 ) ;
return - V_101 ;
}
* V_47 = V_100 ;
return 0 ;
}
void
F_42 (
struct V_20 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_17 ;
bool V_34 = ( V_3 -> V_6 & V_24 ) != 0 ;
V_36 V_102 = 0 ;
V_36 V_103 = 0 ;
V_36 V_104 = 0 ;
V_36 V_105 = 0 ;
int error ;
if ( V_3 -> V_25 > 0 )
V_102 = V_3 -> V_25 ;
if ( ( V_3 -> V_58 != 0 ) &&
( F_30 ( & V_2 -> V_54 ) ||
( V_3 -> V_6 & V_51 ) ) )
V_102 += V_3 -> V_58 ;
if ( V_3 -> V_27 > 0 )
V_103 = V_3 -> V_27 ;
if ( ( V_3 -> V_62 != 0 ) &&
( V_3 -> V_6 & V_51 ) )
V_103 += V_3 -> V_62 ;
if ( F_30 ( & V_2 -> V_54 ) ||
( V_3 -> V_6 & V_51 ) ) {
V_104 = V_3 -> V_53 ;
V_105 = V_3 -> V_56 ;
}
if ( V_102 ) {
error = F_23 ( V_2 , V_102 , V_34 ) ;
if ( error )
goto V_106;
}
if ( V_104 ) {
error = F_43 ( V_2 , V_104 ) ;
if ( error )
goto V_107;
}
if ( V_105 ) {
error = F_44 ( V_2 , V_105 ) ;
if ( error )
goto V_108;
}
if ( V_103 == 0 && ! ( V_3 -> V_6 & V_51 ) )
return;
F_45 ( & V_2 -> V_109 ) ;
if ( V_103 ) {
error = F_41 ( & V_2 -> V_54 . V_90 , V_103 ) ;
if ( error )
goto V_110;
}
if ( V_3 -> V_66 != 0 ) {
error = F_41 ( & V_2 -> V_54 . V_91 , V_3 -> V_66 ) ;
if ( error )
goto V_111;
}
if ( V_3 -> V_68 != 0 ) {
error = F_40 ( & V_2 -> V_54 . V_92 , V_3 -> V_68 ) ;
if ( error )
goto V_112;
}
if ( V_3 -> V_70 != 0 ) {
error = F_39 ( & V_2 -> V_54 . V_93 , V_3 -> V_70 ) ;
if ( error )
goto V_113;
}
if ( V_3 -> V_72 != 0 ) {
error = F_40 ( & V_2 -> V_54 . V_94 ,
V_3 -> V_72 ) ;
if ( error )
goto V_114;
}
if ( V_3 -> V_74 != 0 ) {
error = F_40 ( & V_2 -> V_54 . V_95 ,
V_3 -> V_74 ) ;
if ( error )
goto V_115;
}
if ( V_3 -> V_76 != 0 ) {
error = F_41 ( & V_2 -> V_54 . V_96 , V_3 -> V_76 ) ;
if ( error )
goto V_116;
}
if ( V_3 -> V_78 != 0 ) {
error = F_41 ( & V_2 -> V_54 . V_97 ,
V_3 -> V_78 ) ;
if ( error )
goto V_117;
}
if ( V_3 -> V_80 != 0 ) {
error = F_39 ( & V_2 -> V_54 . V_98 ,
V_3 -> V_80 ) ;
if ( error )
goto V_118;
}
F_46 ( & V_2 -> V_109 ) ;
return;
V_118:
if ( V_3 -> V_78 )
F_41 ( & V_2 -> V_54 . V_97 , - V_3 -> V_78 ) ;
V_117:
if ( V_3 -> V_76 )
F_41 ( & V_2 -> V_54 . V_96 , - V_3 -> V_76 ) ;
V_116:
if ( V_3 -> V_74 )
F_40 ( & V_2 -> V_54 . V_95 , - V_3 -> V_74 ) ;
V_115:
if ( V_3 -> V_72 )
F_40 ( & V_2 -> V_54 . V_94 , - V_3 -> V_72 ) ;
V_114:
if ( V_3 -> V_72 )
F_39 ( & V_2 -> V_54 . V_93 , - V_3 -> V_70 ) ;
V_113:
if ( V_3 -> V_68 )
F_40 ( & V_2 -> V_54 . V_92 , - V_3 -> V_68 ) ;
V_112:
if ( V_3 -> V_66 )
F_41 ( & V_2 -> V_54 . V_91 , - V_3 -> V_66 ) ;
V_111:
if ( V_103 )
F_41 ( & V_2 -> V_54 . V_90 , - V_103 ) ;
V_110:
F_46 ( & V_2 -> V_109 ) ;
if ( V_105 )
F_44 ( V_2 , - V_105 ) ;
V_108:
if ( V_104 )
F_43 ( V_2 , - V_104 ) ;
V_107:
if ( V_102 )
F_23 ( V_2 , - V_102 , V_34 ) ;
V_106:
ASSERT ( error == 0 ) ;
return;
}
void
F_47 (
struct V_20 * V_3 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 ;
ASSERT ( V_120 -> V_123 == V_3 -> V_17 ) ;
ASSERT ( V_120 -> V_124 == V_3 -> V_17 -> V_125 ) ;
V_122 = F_9 ( V_126 , V_5 | V_127 ) ;
V_122 -> V_128 = V_120 ;
V_122 -> V_129 = 0 ;
F_48 ( & V_122 -> V_130 , & V_3 -> V_18 ) ;
V_120 -> V_131 = V_122 ;
}
STATIC void
F_49 (
struct V_121 * V_122 )
{
F_50 ( & V_122 -> V_130 ) ;
F_17 ( V_126 , V_122 ) ;
}
void
F_51 (
struct V_119 * V_120 )
{
F_49 ( V_120 -> V_131 ) ;
V_120 -> V_131 = NULL ;
}
void
F_52 (
struct V_20 * V_3 ,
T_12 V_132 ,
bool abort )
{
struct V_121 * V_122 , * V_133 ;
F_53 (lidp, next, &tp->t_items, lid_trans) {
struct V_119 * V_120 = V_122 -> V_128 ;
V_120 -> V_131 = NULL ;
if ( V_132 != V_134 )
V_120 -> V_135 -> V_136 ( V_120 , V_132 ) ;
if ( abort )
V_120 -> V_137 |= V_138 ;
V_120 -> V_135 -> V_139 ( V_120 ) ;
F_49 ( V_122 ) ;
}
}
static inline void
F_54 (
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_119 * * V_144 ,
int V_145 ,
T_12 V_132 )
{
int V_146 ;
F_45 ( & V_141 -> V_147 ) ;
F_55 ( V_141 , V_143 , V_144 , V_145 , V_132 ) ;
for ( V_146 = 0 ; V_146 < V_145 ; V_146 ++ ) {
struct V_119 * V_120 = V_144 [ V_146 ] ;
V_120 -> V_135 -> V_148 ( V_120 , 0 ) ;
}
}
void
F_56 (
struct V_140 * V_141 ,
struct V_149 * V_150 ,
T_12 V_132 ,
int V_151 )
{
#define F_57 32
struct V_119 * V_144 [ F_57 ] ;
struct V_149 * V_152 ;
struct V_142 V_143 ;
int V_146 = 0 ;
F_45 ( & V_141 -> V_147 ) ;
F_58 ( V_141 , & V_143 , V_132 ) ;
F_46 ( & V_141 -> V_147 ) ;
for ( V_152 = V_150 ; V_152 ; V_152 = V_152 -> V_153 ) {
struct V_119 * V_120 = V_152 -> V_154 ;
T_12 V_155 ;
if ( V_151 )
V_120 -> V_137 |= V_138 ;
V_155 = V_120 -> V_135 -> V_156 ( V_120 , V_132 ) ;
if ( F_59 ( V_155 , ( T_12 ) - 1 ) == 0 )
continue;
if ( V_151 ) {
ASSERT ( F_60 ( V_141 -> V_157 ) ) ;
V_120 -> V_135 -> V_148 ( V_120 , 1 ) ;
continue;
}
if ( V_155 != V_132 ) {
F_45 ( & V_141 -> V_147 ) ;
if ( F_59 ( V_155 , V_120 -> V_158 ) > 0 )
F_61 ( V_141 , V_120 , V_155 ) ;
else
F_46 ( & V_141 -> V_147 ) ;
V_120 -> V_135 -> V_148 ( V_120 , 0 ) ;
continue;
}
V_144 [ V_146 ++ ] = V_152 -> V_154 ;
if ( V_146 >= F_57 ) {
F_54 ( V_141 , & V_143 , V_144 ,
F_57 , V_132 ) ;
V_146 = 0 ;
}
}
if ( V_146 )
F_54 ( V_141 , & V_143 , V_144 , V_146 , V_132 ) ;
F_45 ( & V_141 -> V_147 ) ;
F_62 ( & V_143 ) ;
F_46 ( & V_141 -> V_147 ) ;
}
static int
F_63 (
struct V_20 * V_3 ,
bool V_159 )
{
struct V_1 * V_2 = V_3 -> V_17 ;
T_12 V_132 = - 1 ;
int error = 0 ;
int V_160 = V_3 -> V_6 & V_161 ;
if ( ! ( V_3 -> V_6 & V_50 ) )
goto V_162;
if ( F_60 ( V_2 ) ) {
error = - V_163 ;
goto V_162;
}
ASSERT ( V_3 -> V_23 != NULL ) ;
if ( V_3 -> V_6 & V_51 )
F_31 ( V_3 ) ;
F_64 ( V_3 ) ;
F_65 ( V_2 , V_3 , & V_132 , V_159 ) ;
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_11 ( V_3 ) ;
if ( V_160 ) {
error = F_66 ( V_2 , V_132 , V_164 , NULL ) ;
F_67 ( V_165 ) ;
} else {
F_67 ( V_166 ) ;
}
return error ;
V_162:
F_42 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_23 ) {
V_132 = F_28 ( V_2 , V_3 -> V_23 , NULL , V_159 ) ;
if ( V_132 == - 1 && ! error )
error = - V_163 ;
}
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_52 ( V_3 , V_134 , ! ! error ) ;
F_11 ( V_3 ) ;
F_67 ( V_167 ) ;
return error ;
}
int
F_69 (
struct V_20 * V_3 )
{
return F_63 ( V_3 , false ) ;
}
void
F_70 (
struct V_20 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_17 ;
bool V_168 = ( V_3 -> V_6 & V_50 ) ;
if ( V_168 && ! F_60 ( V_2 ) ) {
F_71 ( L_1 , V_169 , V_2 ) ;
F_72 ( V_2 , V_170 ) ;
}
#ifdef F_73
if ( ! V_168 && ! F_60 ( V_2 ) ) {
struct V_121 * V_122 ;
F_74 (lidp, &tp->t_items, lid_trans)
ASSERT ( ! ( V_122 -> V_128 -> V_171 == V_172 ) ) ;
}
#endif
F_42 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_23 )
F_28 ( V_2 , V_3 -> V_23 , NULL , false ) ;
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_52 ( V_3 , V_134 , V_168 ) ;
F_11 ( V_3 ) ;
}
int
F_75 (
struct V_20 * * V_173 ,
struct V_174 * V_175 ,
int * V_176 )
{
struct V_20 * V_177 ;
struct V_30 V_178 ;
int error ;
V_177 = * V_173 ;
if ( V_175 )
F_76 ( V_177 , V_175 , V_179 ) ;
V_178 . V_38 = V_177 -> V_40 ;
V_178 . V_42 = V_177 -> V_41 ;
* V_173 = F_18 ( V_177 ) ;
error = F_63 ( V_177 , true ) ;
if ( error )
return error ;
* V_176 = 1 ;
V_177 = * V_173 ;
V_178 . V_43 = V_22 ;
error = F_21 ( V_177 , & V_178 , 0 , 0 ) ;
if ( error )
return error ;
if ( V_175 )
F_77 ( V_177 , V_175 , 0 ) ;
return 0 ;
}
int
F_78 (
struct V_20 * * V_173 ,
struct V_174 * V_175 )
{
int V_176 = 0 ;
return F_75 ( V_173 , V_175 , & V_176 ) ;
}
