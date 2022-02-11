void
F_1 (
struct V_1 * V_2 )
{
F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
STATIC void
F_4 (
struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
F_6 ( V_4 -> V_6 , & V_4 -> V_5 , false ) ;
F_7 ( & V_4 -> V_6 -> V_7 ) ;
if ( ! ( V_4 -> V_8 & V_9 ) )
F_8 ( V_4 -> V_6 -> V_10 ) ;
F_9 ( V_4 ) ;
F_10 ( V_11 , V_4 ) ;
}
STATIC T_1 *
F_11 (
T_1 * V_4 )
{
T_1 * V_12 ;
V_12 = F_12 ( V_11 , V_13 ) ;
V_12 -> V_14 = V_15 ;
V_12 -> V_6 = V_4 -> V_6 ;
F_13 ( & V_12 -> V_16 ) ;
F_13 ( & V_12 -> V_5 ) ;
ASSERT ( V_4 -> V_8 & V_17 ) ;
ASSERT ( V_4 -> V_18 != NULL ) ;
V_12 -> V_8 = V_17 |
( V_4 -> V_8 & V_19 ) |
( V_4 -> V_8 & V_9 ) ;
V_4 -> V_8 |= V_9 ;
V_12 -> V_18 = F_14 ( V_4 -> V_18 ) ;
V_12 -> V_20 = V_4 -> V_20 - V_4 -> V_21 ;
V_4 -> V_20 = V_4 -> V_21 ;
V_12 -> V_22 = V_4 -> V_22 - V_4 -> V_23 ;
V_4 -> V_22 = V_4 -> V_23 ;
V_12 -> V_24 = V_4 -> V_24 ;
F_15 ( V_4 , V_12 ) ;
F_16 ( & V_4 -> V_6 -> V_7 ) ;
return V_12 ;
}
static int
F_17 (
struct V_3 * V_4 ,
struct V_25 * V_26 ,
T_2 V_27 ,
T_2 V_28 )
{
int error = 0 ;
bool V_29 = ( V_4 -> V_8 & V_19 ) != 0 ;
F_18 ( & V_4 -> V_24 , V_30 ) ;
if ( V_27 > 0 ) {
error = F_19 ( V_4 -> V_6 , - ( ( V_31 ) V_27 ) , V_29 ) ;
if ( error != 0 ) {
F_20 ( & V_4 -> V_24 , V_30 ) ;
return - V_32 ;
}
V_4 -> V_20 += V_27 ;
}
if ( V_26 -> V_33 > 0 ) {
bool V_34 = false ;
ASSERT ( V_4 -> V_35 == 0 ||
V_4 -> V_35 == V_26 -> V_33 ) ;
ASSERT ( V_4 -> V_36 == 0 ||
V_4 -> V_36 == V_26 -> V_37 ) ;
if ( V_26 -> V_38 & V_17 ) {
V_4 -> V_8 |= V_17 ;
V_34 = true ;
} else {
ASSERT ( V_4 -> V_18 == NULL ) ;
ASSERT ( ! ( V_4 -> V_8 & V_17 ) ) ;
}
if ( V_4 -> V_18 != NULL ) {
ASSERT ( V_26 -> V_38 & V_17 ) ;
error = F_21 ( V_4 -> V_6 , V_4 -> V_18 ) ;
} else {
error = F_22 ( V_4 -> V_6 ,
V_26 -> V_33 ,
V_26 -> V_37 ,
& V_4 -> V_18 , V_39 ,
V_34 ) ;
}
if ( error )
goto V_40;
V_4 -> V_35 = V_26 -> V_33 ;
V_4 -> V_36 = V_26 -> V_37 ;
}
if ( V_28 > 0 ) {
error = F_23 ( V_4 -> V_6 , - ( ( V_31 ) V_28 ) ) ;
if ( error ) {
error = - V_32 ;
goto V_41;
}
V_4 -> V_22 += V_28 ;
}
return 0 ;
V_41:
if ( V_26 -> V_33 > 0 ) {
F_24 ( V_4 -> V_6 , V_4 -> V_18 , NULL , false ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_35 = 0 ;
V_4 -> V_8 &= ~ V_17 ;
}
V_40:
if ( V_27 > 0 ) {
F_19 ( V_4 -> V_6 , ( V_31 ) V_27 , V_29 ) ;
V_4 -> V_20 = 0 ;
}
F_20 ( & V_4 -> V_24 , V_30 ) ;
return error ;
}
int
F_25 (
struct V_1 * V_2 ,
struct V_25 * V_26 ,
T_2 V_27 ,
T_2 V_28 ,
T_2 V_42 ,
struct V_3 * * V_43 )
{
struct V_3 * V_4 ;
int error ;
if ( ! ( V_42 & V_9 ) )
F_26 ( V_2 -> V_10 ) ;
F_27 ( V_2 -> V_10 -> V_44 . V_45 == V_46 ) ;
F_16 ( & V_2 -> V_7 ) ;
V_4 = F_12 ( V_11 ,
( V_42 & V_47 ) ? V_48 : V_13 ) ;
V_4 -> V_14 = V_15 ;
V_4 -> V_8 = V_42 ;
V_4 -> V_6 = V_2 ;
F_13 ( & V_4 -> V_16 ) ;
F_13 ( & V_4 -> V_5 ) ;
error = F_17 ( V_4 , V_26 , V_27 , V_28 ) ;
if ( error ) {
F_28 ( V_4 ) ;
return error ;
}
* V_43 = V_4 ;
return 0 ;
}
int
F_29 (
struct V_1 * V_2 ,
struct V_3 * * V_43 )
{
struct V_25 V_49 = { 0 } ;
return F_25 ( V_2 , & V_49 , 0 , 0 , V_9 , V_43 ) ;
}
void
F_30 (
T_1 * V_4 ,
T_2 V_50 ,
V_31 V_51 )
{
T_3 V_42 = ( V_52 | V_53 ) ;
T_4 * V_2 = V_4 -> V_6 ;
switch ( V_50 ) {
case V_54 :
V_4 -> V_55 += V_51 ;
if ( F_31 ( & V_2 -> V_56 ) )
V_42 &= ~ V_53 ;
break;
case V_57 :
V_4 -> V_58 += V_51 ;
if ( F_31 ( & V_2 -> V_56 ) )
V_42 &= ~ V_53 ;
break;
case V_59 :
if ( V_51 < 0 ) {
V_4 -> V_21 += ( T_2 ) - V_51 ;
ASSERT ( V_4 -> V_21 <= V_4 -> V_20 ) ;
}
V_4 -> V_60 += V_51 ;
if ( F_31 ( & V_2 -> V_56 ) )
V_42 &= ~ V_53 ;
break;
case V_61 :
V_4 -> V_62 += V_51 ;
if ( F_31 ( & V_2 -> V_56 ) )
V_42 &= ~ V_53 ;
break;
case V_63 :
if ( V_51 < 0 ) {
V_4 -> V_23 += ( T_2 ) - V_51 ;
ASSERT ( V_4 -> V_23 <= V_4 -> V_22 ) ;
}
V_4 -> V_64 += V_51 ;
break;
case V_65 :
ASSERT ( V_51 < 0 ) ;
V_4 -> V_66 += V_51 ;
break;
case V_67 :
ASSERT ( V_51 > 0 ) ;
V_4 -> V_68 += V_51 ;
break;
case V_69 :
ASSERT ( V_51 > 0 ) ;
V_4 -> V_70 += V_51 ;
break;
case V_71 :
V_4 -> V_72 += V_51 ;
break;
case V_73 :
V_4 -> V_74 += V_51 ;
break;
case V_75 :
V_4 -> V_76 += V_51 ;
break;
case V_77 :
V_4 -> V_78 += V_51 ;
break;
case V_79 :
V_4 -> V_80 += V_51 ;
break;
case V_81 :
V_4 -> V_82 += V_51 ;
break;
default:
ASSERT ( 0 ) ;
return;
}
V_4 -> V_8 |= V_42 ;
}
STATIC void
F_32 (
T_1 * V_4 )
{
T_5 * V_83 ;
T_6 * V_84 ;
int V_85 = 0 ;
V_84 = F_33 ( V_4 , V_4 -> V_6 , 0 ) ;
V_83 = F_34 ( V_84 ) ;
ASSERT ( ( V_4 -> V_60 + V_4 -> V_62 ) ==
( V_4 -> V_86 + V_4 -> V_87 +
V_4 -> V_88 ) ) ;
if ( ! F_31 ( & ( V_4 -> V_6 -> V_56 ) ) ) {
if ( V_4 -> V_55 )
F_35 ( & V_83 -> V_89 , V_4 -> V_55 ) ;
if ( V_4 -> V_58 )
F_35 ( & V_83 -> V_90 , V_4 -> V_58 ) ;
if ( V_4 -> V_60 )
F_35 ( & V_83 -> V_91 , V_4 -> V_60 ) ;
if ( V_4 -> V_62 )
F_35 ( & V_83 -> V_91 , V_4 -> V_62 ) ;
}
if ( V_4 -> V_64 )
F_35 ( & V_83 -> V_92 , V_4 -> V_64 ) ;
if ( V_4 -> V_66 )
F_35 ( & V_83 -> V_92 , V_4 -> V_66 ) ;
if ( V_4 -> V_68 ) {
F_35 ( & V_83 -> V_93 , V_4 -> V_68 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_70 ) {
F_36 ( & V_83 -> V_94 , V_4 -> V_70 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_72 ) {
V_83 -> V_95 += V_4 -> V_72 ;
V_85 = 1 ;
}
if ( V_4 -> V_74 ) {
F_36 ( & V_83 -> V_96 , V_4 -> V_74 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_76 ) {
F_36 ( & V_83 -> V_97 , V_4 -> V_76 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_78 ) {
F_35 ( & V_83 -> V_98 , V_4 -> V_78 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_80 ) {
F_35 ( & V_83 -> V_99 , V_4 -> V_80 ) ;
V_85 = 1 ;
}
if ( V_4 -> V_82 ) {
V_83 -> V_100 += V_4 -> V_82 ;
V_85 = 1 ;
}
F_37 ( V_4 , V_84 , V_101 ) ;
if ( V_85 )
F_38 ( V_4 , V_84 , 0 , sizeof( T_5 ) - 1 ) ;
else
F_38 ( V_4 , V_84 , F_39 ( T_5 , V_89 ) ,
F_39 ( T_5 , V_92 ) +
sizeof( V_83 -> V_92 ) - 1 ) ;
}
STATIC int
F_40 (
T_7 * V_50 ,
T_8 V_51 )
{
T_8 V_102 = * V_50 ;
V_102 += V_51 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_50 = V_102 ;
return 0 ;
}
STATIC int
F_41 (
T_3 * V_50 ,
T_9 V_51 )
{
T_9 V_102 = * V_50 ;
V_102 += V_51 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_50 = V_102 ;
return 0 ;
}
STATIC int
F_42 (
T_10 * V_50 ,
V_31 V_51 )
{
V_31 V_102 = * V_50 ;
V_102 += V_51 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_50 = V_102 ;
return 0 ;
}
void
F_43 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
bool V_29 = ( V_4 -> V_8 & V_19 ) != 0 ;
V_31 V_104 = 0 ;
V_31 V_105 = 0 ;
V_31 V_106 = 0 ;
V_31 V_107 = 0 ;
int error ;
if ( V_4 -> V_20 > 0 )
V_104 = V_4 -> V_20 ;
if ( ( V_4 -> V_60 != 0 ) &&
( F_31 ( & V_2 -> V_56 ) ||
( V_4 -> V_8 & V_53 ) ) )
V_104 += V_4 -> V_60 ;
if ( V_4 -> V_22 > 0 )
V_105 = V_4 -> V_22 ;
if ( ( V_4 -> V_64 != 0 ) &&
( V_4 -> V_8 & V_53 ) )
V_105 += V_4 -> V_64 ;
if ( F_31 ( & V_2 -> V_56 ) ||
( V_4 -> V_8 & V_53 ) ) {
V_106 = V_4 -> V_55 ;
V_107 = V_4 -> V_58 ;
}
if ( V_104 ) {
error = F_19 ( V_2 , V_104 , V_29 ) ;
if ( error )
goto V_108;
}
if ( V_106 ) {
error = F_44 ( V_2 , V_106 ) ;
if ( error )
goto V_109;
}
if ( V_107 ) {
error = F_45 ( V_2 , V_107 ) ;
if ( error )
goto V_110;
}
if ( V_105 == 0 && ! ( V_4 -> V_8 & V_53 ) )
return;
F_46 ( & V_2 -> V_111 ) ;
if ( V_105 ) {
error = F_42 ( & V_2 -> V_56 . V_92 , V_105 ) ;
if ( error )
goto V_112;
}
if ( V_4 -> V_68 != 0 ) {
error = F_42 ( & V_2 -> V_56 . V_93 , V_4 -> V_68 ) ;
if ( error )
goto V_113;
}
if ( V_4 -> V_70 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_94 , V_4 -> V_70 ) ;
if ( error )
goto V_114;
}
if ( V_4 -> V_72 != 0 ) {
error = F_40 ( & V_2 -> V_56 . V_95 , V_4 -> V_72 ) ;
if ( error )
goto V_115;
}
if ( V_4 -> V_74 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_96 ,
V_4 -> V_74 ) ;
if ( error )
goto V_116;
}
if ( V_4 -> V_76 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_97 ,
V_4 -> V_76 ) ;
if ( error )
goto V_117;
}
if ( V_4 -> V_78 != 0 ) {
error = F_42 ( & V_2 -> V_56 . V_98 , V_4 -> V_78 ) ;
if ( error )
goto V_118;
}
if ( V_4 -> V_80 != 0 ) {
error = F_42 ( & V_2 -> V_56 . V_99 ,
V_4 -> V_80 ) ;
if ( error )
goto V_119;
}
if ( V_4 -> V_82 != 0 ) {
error = F_40 ( & V_2 -> V_56 . V_100 ,
V_4 -> V_82 ) ;
if ( error )
goto V_120;
}
F_47 ( & V_2 -> V_111 ) ;
return;
V_120:
if ( V_4 -> V_80 )
F_42 ( & V_2 -> V_56 . V_99 , - V_4 -> V_80 ) ;
V_119:
if ( V_4 -> V_78 )
F_42 ( & V_2 -> V_56 . V_98 , - V_4 -> V_78 ) ;
V_118:
if ( V_4 -> V_76 )
F_41 ( & V_2 -> V_56 . V_97 , - V_4 -> V_76 ) ;
V_117:
if ( V_4 -> V_74 )
F_41 ( & V_2 -> V_56 . V_96 , - V_4 -> V_74 ) ;
V_116:
if ( V_4 -> V_74 )
F_40 ( & V_2 -> V_56 . V_95 , - V_4 -> V_72 ) ;
V_115:
if ( V_4 -> V_70 )
F_41 ( & V_2 -> V_56 . V_94 , - V_4 -> V_70 ) ;
V_114:
if ( V_4 -> V_68 )
F_42 ( & V_2 -> V_56 . V_93 , - V_4 -> V_68 ) ;
V_113:
if ( V_105 )
F_42 ( & V_2 -> V_56 . V_92 , - V_105 ) ;
V_112:
F_47 ( & V_2 -> V_111 ) ;
if ( V_107 )
F_45 ( V_2 , - V_107 ) ;
V_110:
if ( V_106 )
F_44 ( V_2 , - V_106 ) ;
V_109:
if ( V_104 )
F_19 ( V_2 , - V_104 , V_29 ) ;
V_108:
ASSERT ( error == 0 ) ;
return;
}
void
F_48 (
struct V_3 * V_4 ,
struct V_121 * V_122 )
{
struct V_123 * V_124 ;
ASSERT ( V_122 -> V_125 == V_4 -> V_6 ) ;
ASSERT ( V_122 -> V_126 == V_4 -> V_6 -> V_127 ) ;
V_124 = F_12 ( V_128 , V_13 | V_48 ) ;
V_124 -> V_129 = V_122 ;
V_124 -> V_130 = 0 ;
F_49 ( & V_124 -> V_131 , & V_4 -> V_16 ) ;
V_122 -> V_132 = V_124 ;
}
STATIC void
F_50 (
struct V_123 * V_124 )
{
F_51 ( & V_124 -> V_131 ) ;
F_10 ( V_128 , V_124 ) ;
}
void
F_52 (
struct V_121 * V_122 )
{
F_50 ( V_122 -> V_132 ) ;
V_122 -> V_132 = NULL ;
}
void
F_53 (
struct V_3 * V_4 ,
T_11 V_133 ,
bool abort )
{
struct V_123 * V_124 , * V_134 ;
F_54 (lidp, next, &tp->t_items, lid_trans) {
struct V_121 * V_122 = V_124 -> V_129 ;
V_122 -> V_132 = NULL ;
if ( V_133 != V_135 )
V_122 -> V_136 -> V_137 ( V_122 , V_133 ) ;
if ( abort )
V_122 -> V_138 |= V_139 ;
V_122 -> V_136 -> V_140 ( V_122 ) ;
F_50 ( V_124 ) ;
}
}
static inline void
F_55 (
struct V_141 * V_142 ,
struct V_143 * V_144 ,
struct V_121 * * V_145 ,
int V_146 ,
T_11 V_133 )
{
int V_147 ;
F_46 ( & V_142 -> V_148 ) ;
F_56 ( V_142 , V_144 , V_145 , V_146 , V_133 ) ;
for ( V_147 = 0 ; V_147 < V_146 ; V_147 ++ ) {
struct V_121 * V_122 = V_145 [ V_147 ] ;
V_122 -> V_136 -> V_149 ( V_122 , 0 ) ;
}
}
void
F_57 (
struct V_141 * V_142 ,
struct V_150 * V_151 ,
T_11 V_133 ,
int V_152 )
{
#define F_58 32
struct V_121 * V_145 [ F_58 ] ;
struct V_150 * V_153 ;
struct V_143 V_144 ;
int V_147 = 0 ;
F_46 ( & V_142 -> V_148 ) ;
F_59 ( V_142 , & V_144 , V_133 ) ;
F_47 ( & V_142 -> V_148 ) ;
for ( V_153 = V_151 ; V_153 ; V_153 = V_153 -> V_154 ) {
struct V_121 * V_122 = V_153 -> V_155 ;
T_11 V_156 ;
if ( V_152 )
V_122 -> V_138 |= V_139 ;
V_156 = V_122 -> V_136 -> V_157 ( V_122 , V_133 ) ;
if ( F_60 ( V_156 , ( T_11 ) - 1 ) == 0 )
continue;
if ( V_152 ) {
ASSERT ( F_61 ( V_142 -> V_158 ) ) ;
V_122 -> V_136 -> V_149 ( V_122 , 1 ) ;
continue;
}
if ( V_156 != V_133 ) {
F_46 ( & V_142 -> V_148 ) ;
if ( F_60 ( V_156 , V_122 -> V_159 ) > 0 )
F_62 ( V_142 , V_122 , V_156 ) ;
else
F_47 ( & V_142 -> V_148 ) ;
V_122 -> V_136 -> V_149 ( V_122 , 0 ) ;
continue;
}
V_145 [ V_147 ++ ] = V_153 -> V_155 ;
if ( V_147 >= F_58 ) {
F_55 ( V_142 , & V_144 , V_145 ,
F_58 , V_133 ) ;
V_147 = 0 ;
}
}
if ( V_147 )
F_55 ( V_142 , & V_144 , V_145 , V_147 , V_133 ) ;
F_46 ( & V_142 -> V_148 ) ;
F_63 ( & V_144 ) ;
F_47 ( & V_142 -> V_148 ) ;
}
static int
F_64 (
struct V_3 * V_4 ,
bool V_160 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
T_11 V_133 = - 1 ;
int error = 0 ;
int V_161 = V_4 -> V_8 & V_162 ;
if ( ! ( V_4 -> V_8 & V_52 ) )
goto V_163;
if ( F_61 ( V_2 ) ) {
error = - V_164 ;
goto V_163;
}
ASSERT ( V_4 -> V_18 != NULL ) ;
if ( V_4 -> V_8 & V_53 )
F_32 ( V_4 ) ;
F_65 ( V_4 ) ;
F_66 ( V_2 , V_4 , & V_133 , V_160 ) ;
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_4 ( V_4 ) ;
if ( V_161 ) {
error = F_67 ( V_2 , V_133 , V_165 , NULL ) ;
F_68 ( V_2 , V_166 ) ;
} else {
F_68 ( V_2 , V_167 ) ;
}
return error ;
V_163:
F_43 ( V_4 ) ;
F_69 ( V_4 ) ;
if ( V_4 -> V_18 ) {
V_133 = F_24 ( V_2 , V_4 -> V_18 , NULL , V_160 ) ;
if ( V_133 == - 1 && ! error )
error = - V_164 ;
}
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_53 ( V_4 , V_135 , ! ! error ) ;
F_4 ( V_4 ) ;
F_68 ( V_2 , V_168 ) ;
return error ;
}
int
F_70 (
struct V_3 * V_4 )
{
return F_64 ( V_4 , false ) ;
}
void
F_28 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
bool V_169 = ( V_4 -> V_8 & V_52 ) ;
if ( V_169 && ! F_61 ( V_2 ) ) {
F_71 ( L_1 , V_170 , V_2 ) ;
F_72 ( V_2 , V_171 ) ;
}
#ifdef F_73
if ( ! V_169 && ! F_61 ( V_2 ) ) {
struct V_123 * V_124 ;
F_74 (lidp, &tp->t_items, lid_trans)
ASSERT ( ! ( V_124 -> V_129 -> V_172 == V_173 ) ) ;
}
#endif
F_43 ( V_4 ) ;
F_69 ( V_4 ) ;
if ( V_4 -> V_18 )
F_24 ( V_2 , V_4 -> V_18 , NULL , false ) ;
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_53 ( V_4 , V_135 , V_169 ) ;
F_4 ( V_4 ) ;
}
int
F_75 (
struct V_3 * * V_43 )
{
struct V_3 * V_174 = * V_43 ;
struct V_25 V_175 ;
int error ;
V_175 . V_33 = V_174 -> V_35 ;
V_175 . V_37 = V_174 -> V_36 ;
* V_43 = F_11 ( V_174 ) ;
error = F_64 ( V_174 , true ) ;
if ( error )
return error ;
V_175 . V_38 = V_17 ;
return F_17 ( * V_43 , & V_175 , 0 , 0 ) ;
}
