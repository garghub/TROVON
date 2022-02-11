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
T_1 *
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
int V_47 ;
if ( V_31 -> V_43 & V_22 ) {
V_47 = V_48 ;
} else {
V_47 = 0 ;
}
F_28 ( V_3 -> V_17 , V_3 -> V_23 , NULL , V_47 ) ;
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
T_3 V_49 ,
V_36 V_50 )
{
T_5 V_51 = ( V_52 | V_53 ) ;
T_2 * V_2 = V_3 -> V_17 ;
switch ( V_49 ) {
case V_54 :
V_3 -> V_55 += V_50 ;
if ( F_30 ( & V_2 -> V_56 ) )
V_51 &= ~ V_53 ;
break;
case V_57 :
V_3 -> V_58 += V_50 ;
if ( F_30 ( & V_2 -> V_56 ) )
V_51 &= ~ V_53 ;
break;
case V_59 :
if ( V_50 < 0 ) {
V_3 -> V_26 += ( T_3 ) - V_50 ;
ASSERT ( V_3 -> V_26 <= V_3 -> V_25 ) ;
}
V_3 -> V_60 += V_50 ;
if ( F_30 ( & V_2 -> V_56 ) )
V_51 &= ~ V_53 ;
break;
case V_61 :
ASSERT ( V_50 < 0 ) ;
V_3 -> V_62 += V_50 ;
if ( F_30 ( & V_2 -> V_56 ) )
V_51 &= ~ V_53 ;
break;
case V_63 :
if ( V_50 < 0 ) {
V_3 -> V_28 += ( T_3 ) - V_50 ;
ASSERT ( V_3 -> V_28 <= V_3 -> V_27 ) ;
}
V_3 -> V_64 += V_50 ;
break;
case V_65 :
ASSERT ( V_50 < 0 ) ;
V_3 -> V_66 += V_50 ;
break;
case V_67 :
ASSERT ( V_50 > 0 ) ;
V_3 -> V_68 += V_50 ;
break;
case V_69 :
ASSERT ( V_50 > 0 ) ;
V_3 -> V_70 += V_50 ;
break;
case V_71 :
V_3 -> V_72 += V_50 ;
break;
case V_73 :
V_3 -> V_74 += V_50 ;
break;
case V_75 :
V_3 -> V_76 += V_50 ;
break;
case V_77 :
V_3 -> V_78 += V_50 ;
break;
case V_79 :
V_3 -> V_80 += V_50 ;
break;
case V_81 :
V_3 -> V_82 += V_50 ;
break;
default:
ASSERT ( 0 ) ;
return;
}
V_3 -> V_6 |= V_51 ;
}
STATIC void
F_31 (
T_1 * V_3 )
{
T_6 * V_83 ;
T_7 * V_84 ;
int V_85 = 0 ;
V_84 = F_32 ( V_3 , V_3 -> V_17 , 0 ) ;
V_83 = F_33 ( V_84 ) ;
ASSERT ( ( V_3 -> V_60 + V_3 -> V_62 ) ==
( V_3 -> V_86 + V_3 -> V_87 +
V_3 -> V_88 ) ) ;
if ( ! F_30 ( & ( V_3 -> V_17 -> V_56 ) ) ) {
if ( V_3 -> V_55 )
F_34 ( & V_83 -> V_89 , V_3 -> V_55 ) ;
if ( V_3 -> V_58 )
F_34 ( & V_83 -> V_90 , V_3 -> V_58 ) ;
if ( V_3 -> V_60 )
F_34 ( & V_83 -> V_91 , V_3 -> V_60 ) ;
if ( V_3 -> V_62 )
F_34 ( & V_83 -> V_91 , V_3 -> V_62 ) ;
}
if ( V_3 -> V_64 )
F_34 ( & V_83 -> V_92 , V_3 -> V_64 ) ;
if ( V_3 -> V_66 )
F_34 ( & V_83 -> V_92 , V_3 -> V_66 ) ;
if ( V_3 -> V_68 ) {
F_34 ( & V_83 -> V_93 , V_3 -> V_68 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_70 ) {
F_35 ( & V_83 -> V_94 , V_3 -> V_70 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_72 ) {
V_83 -> V_95 += V_3 -> V_72 ;
V_85 = 1 ;
}
if ( V_3 -> V_74 ) {
F_35 ( & V_83 -> V_96 , V_3 -> V_74 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_76 ) {
F_35 ( & V_83 -> V_97 , V_3 -> V_76 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_78 ) {
F_34 ( & V_83 -> V_98 , V_3 -> V_78 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_80 ) {
F_34 ( & V_83 -> V_99 , V_3 -> V_80 ) ;
V_85 = 1 ;
}
if ( V_3 -> V_82 ) {
V_83 -> V_100 += V_3 -> V_82 ;
V_85 = 1 ;
}
F_36 ( V_3 , V_84 , V_101 ) ;
if ( V_85 )
F_37 ( V_3 , V_84 , 0 , sizeof( T_6 ) - 1 ) ;
else
F_37 ( V_3 , V_84 , F_38 ( T_6 , V_89 ) ,
F_38 ( T_6 , V_92 ) +
sizeof( V_83 -> V_92 ) - 1 ) ;
}
STATIC int
F_39 (
T_8 * V_49 ,
T_9 V_50 )
{
T_9 V_102 = * V_49 ;
V_102 += V_50 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_49 = V_102 ;
return 0 ;
}
STATIC int
F_40 (
T_5 * V_49 ,
T_10 V_50 )
{
T_10 V_102 = * V_49 ;
V_102 += V_50 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_49 = V_102 ;
return 0 ;
}
STATIC int
F_41 (
T_11 * V_49 ,
V_36 V_50 )
{
V_36 V_102 = * V_49 ;
V_102 += V_50 ;
if ( V_102 < 0 ) {
ASSERT ( 0 ) ;
return - V_103 ;
}
* V_49 = V_102 ;
return 0 ;
}
void
F_42 (
struct V_20 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_17 ;
bool V_34 = ( V_3 -> V_6 & V_24 ) != 0 ;
V_36 V_104 = 0 ;
V_36 V_105 = 0 ;
V_36 V_106 = 0 ;
V_36 V_107 = 0 ;
int error ;
if ( V_3 -> V_25 > 0 )
V_104 = V_3 -> V_25 ;
if ( ( V_3 -> V_60 != 0 ) &&
( F_30 ( & V_2 -> V_56 ) ||
( V_3 -> V_6 & V_53 ) ) )
V_104 += V_3 -> V_60 ;
if ( V_3 -> V_27 > 0 )
V_105 = V_3 -> V_27 ;
if ( ( V_3 -> V_64 != 0 ) &&
( V_3 -> V_6 & V_53 ) )
V_105 += V_3 -> V_64 ;
if ( F_30 ( & V_2 -> V_56 ) ||
( V_3 -> V_6 & V_53 ) ) {
V_106 = V_3 -> V_55 ;
V_107 = V_3 -> V_58 ;
}
if ( V_104 ) {
error = F_23 ( V_2 , V_104 , V_34 ) ;
if ( error )
goto V_108;
}
if ( V_106 ) {
error = F_43 ( V_2 , V_106 ) ;
if ( error )
goto V_109;
}
if ( V_107 ) {
error = F_44 ( V_2 , V_107 ) ;
if ( error )
goto V_110;
}
if ( V_105 == 0 && ! ( V_3 -> V_6 & V_53 ) )
return;
F_45 ( & V_2 -> V_111 ) ;
if ( V_105 ) {
error = F_41 ( & V_2 -> V_56 . V_92 , V_105 ) ;
if ( error )
goto V_112;
}
if ( V_3 -> V_68 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_93 , V_3 -> V_68 ) ;
if ( error )
goto V_113;
}
if ( V_3 -> V_70 != 0 ) {
error = F_40 ( & V_2 -> V_56 . V_94 , V_3 -> V_70 ) ;
if ( error )
goto V_114;
}
if ( V_3 -> V_72 != 0 ) {
error = F_39 ( & V_2 -> V_56 . V_95 , V_3 -> V_72 ) ;
if ( error )
goto V_115;
}
if ( V_3 -> V_74 != 0 ) {
error = F_40 ( & V_2 -> V_56 . V_96 ,
V_3 -> V_74 ) ;
if ( error )
goto V_116;
}
if ( V_3 -> V_76 != 0 ) {
error = F_40 ( & V_2 -> V_56 . V_97 ,
V_3 -> V_76 ) ;
if ( error )
goto V_117;
}
if ( V_3 -> V_78 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_98 , V_3 -> V_78 ) ;
if ( error )
goto V_118;
}
if ( V_3 -> V_80 != 0 ) {
error = F_41 ( & V_2 -> V_56 . V_99 ,
V_3 -> V_80 ) ;
if ( error )
goto V_119;
}
if ( V_3 -> V_82 != 0 ) {
error = F_39 ( & V_2 -> V_56 . V_100 ,
V_3 -> V_82 ) ;
if ( error )
goto V_120;
}
F_46 ( & V_2 -> V_111 ) ;
return;
V_120:
if ( V_3 -> V_80 )
F_41 ( & V_2 -> V_56 . V_99 , - V_3 -> V_80 ) ;
V_119:
if ( V_3 -> V_78 )
F_41 ( & V_2 -> V_56 . V_98 , - V_3 -> V_78 ) ;
V_118:
if ( V_3 -> V_76 )
F_40 ( & V_2 -> V_56 . V_97 , - V_3 -> V_76 ) ;
V_117:
if ( V_3 -> V_74 )
F_40 ( & V_2 -> V_56 . V_96 , - V_3 -> V_74 ) ;
V_116:
if ( V_3 -> V_74 )
F_39 ( & V_2 -> V_56 . V_95 , - V_3 -> V_72 ) ;
V_115:
if ( V_3 -> V_70 )
F_40 ( & V_2 -> V_56 . V_94 , - V_3 -> V_70 ) ;
V_114:
if ( V_3 -> V_68 )
F_41 ( & V_2 -> V_56 . V_93 , - V_3 -> V_68 ) ;
V_113:
if ( V_105 )
F_41 ( & V_2 -> V_56 . V_92 , - V_105 ) ;
V_112:
F_46 ( & V_2 -> V_111 ) ;
if ( V_107 )
F_44 ( V_2 , - V_107 ) ;
V_110:
if ( V_106 )
F_43 ( V_2 , - V_106 ) ;
V_109:
if ( V_104 )
F_23 ( V_2 , - V_104 , V_34 ) ;
V_108:
ASSERT ( error == 0 ) ;
return;
}
void
F_47 (
struct V_20 * V_3 ,
struct V_121 * V_122 )
{
struct V_123 * V_124 ;
ASSERT ( V_122 -> V_125 == V_3 -> V_17 ) ;
ASSERT ( V_122 -> V_126 == V_3 -> V_17 -> V_127 ) ;
V_124 = F_9 ( V_128 , V_5 | V_129 ) ;
V_124 -> V_130 = V_122 ;
V_124 -> V_131 = 0 ;
F_48 ( & V_124 -> V_132 , & V_3 -> V_18 ) ;
V_122 -> V_133 = V_124 ;
}
STATIC void
F_49 (
struct V_123 * V_124 )
{
F_50 ( & V_124 -> V_132 ) ;
F_17 ( V_128 , V_124 ) ;
}
void
F_51 (
struct V_121 * V_122 )
{
F_49 ( V_122 -> V_133 ) ;
V_122 -> V_133 = NULL ;
}
void
F_52 (
struct V_20 * V_3 ,
T_12 V_134 ,
int V_51 )
{
struct V_123 * V_124 , * V_135 ;
F_53 (lidp, next, &tp->t_items, lid_trans) {
struct V_121 * V_122 = V_124 -> V_130 ;
V_122 -> V_133 = NULL ;
if ( V_134 != V_136 )
V_122 -> V_137 -> V_138 ( V_122 , V_134 ) ;
if ( V_51 & V_139 )
V_122 -> V_140 |= V_141 ;
V_122 -> V_137 -> V_142 ( V_122 ) ;
F_49 ( V_124 ) ;
}
}
static inline void
F_54 (
struct V_143 * V_144 ,
struct V_145 * V_146 ,
struct V_121 * * V_147 ,
int V_148 ,
T_12 V_134 )
{
int V_149 ;
F_45 ( & V_144 -> V_150 ) ;
F_55 ( V_144 , V_146 , V_147 , V_148 , V_134 ) ;
for ( V_149 = 0 ; V_149 < V_148 ; V_149 ++ ) {
struct V_121 * V_122 = V_147 [ V_149 ] ;
V_122 -> V_137 -> V_151 ( V_122 , 0 ) ;
}
}
void
F_56 (
struct V_143 * V_144 ,
struct V_152 * V_153 ,
T_12 V_134 ,
int V_154 )
{
#define F_57 32
struct V_121 * V_147 [ F_57 ] ;
struct V_152 * V_155 ;
struct V_145 V_146 ;
int V_149 = 0 ;
F_45 ( & V_144 -> V_150 ) ;
F_58 ( V_144 , & V_146 , V_134 ) ;
F_46 ( & V_144 -> V_150 ) ;
for ( V_155 = V_153 ; V_155 ; V_155 = V_155 -> V_156 ) {
struct V_121 * V_122 = V_155 -> V_157 ;
T_12 V_158 ;
if ( V_154 )
V_122 -> V_140 |= V_141 ;
V_158 = V_122 -> V_137 -> V_159 ( V_122 , V_134 ) ;
if ( F_59 ( V_158 , ( T_12 ) - 1 ) == 0 )
continue;
if ( V_154 ) {
ASSERT ( F_60 ( V_144 -> V_160 ) ) ;
V_122 -> V_137 -> V_151 ( V_122 , 1 ) ;
continue;
}
if ( V_158 != V_134 ) {
F_45 ( & V_144 -> V_150 ) ;
if ( F_59 ( V_158 , V_122 -> V_161 ) > 0 )
F_61 ( V_144 , V_122 , V_158 ) ;
else
F_46 ( & V_144 -> V_150 ) ;
V_122 -> V_137 -> V_151 ( V_122 , 0 ) ;
continue;
}
V_147 [ V_149 ++ ] = V_155 -> V_157 ;
if ( V_149 >= F_57 ) {
F_54 ( V_144 , & V_146 , V_147 ,
F_57 , V_134 ) ;
V_149 = 0 ;
}
}
if ( V_149 )
F_54 ( V_144 , & V_146 , V_147 , V_149 , V_134 ) ;
F_45 ( & V_144 -> V_150 ) ;
F_62 ( & V_146 ) ;
F_46 ( & V_144 -> V_150 ) ;
}
int
F_63 (
struct V_20 * V_3 ,
T_3 V_51 )
{
struct V_1 * V_2 = V_3 -> V_17 ;
T_12 V_134 = - 1 ;
int error = 0 ;
int V_47 = 0 ;
int V_162 = V_3 -> V_6 & V_163 ;
if ( V_51 & V_164 ) {
ASSERT ( V_3 -> V_6 & V_22 ) ;
V_47 = V_48 ;
}
if ( ! ( V_3 -> V_6 & V_52 ) )
goto V_165;
if ( F_60 ( V_2 ) ) {
error = - V_166 ;
goto V_165;
}
ASSERT ( V_3 -> V_23 != NULL ) ;
if ( V_3 -> V_6 & V_53 )
F_31 ( V_3 ) ;
F_64 ( V_3 ) ;
F_65 ( V_2 , V_3 , & V_134 , V_51 ) ;
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_11 ( V_3 ) ;
if ( V_162 ) {
error = F_66 ( V_2 , V_134 , V_167 , NULL ) ;
F_67 ( V_168 ) ;
} else {
F_67 ( V_169 ) ;
}
return error ;
V_165:
F_42 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_23 ) {
V_134 = F_28 ( V_2 , V_3 -> V_23 , NULL , V_47 ) ;
if ( V_134 == - 1 && ! error )
error = - V_166 ;
}
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_52 ( V_3 , V_136 , error ? V_139 : 0 ) ;
F_11 ( V_3 ) ;
F_67 ( V_170 ) ;
return error ;
}
void
F_69 (
T_1 * V_3 ,
int V_51 )
{
int V_47 ;
T_2 * V_2 = V_3 -> V_17 ;
if ( ( V_51 & V_139 ) && ! ( V_3 -> V_6 & V_52 ) )
V_51 &= ~ V_139 ;
if ( ( V_3 -> V_6 & V_52 ) && ! F_60 ( V_2 ) ) {
F_70 ( L_1 , V_171 , V_2 ) ;
F_71 ( V_2 , V_172 ) ;
}
#ifdef F_72
if ( ! ( V_51 & V_139 ) && ! F_60 ( V_2 ) ) {
struct V_123 * V_124 ;
F_73 (lidp, &tp->t_items, lid_trans)
ASSERT ( ! ( V_124 -> V_130 -> V_173 == V_174 ) ) ;
}
#endif
F_42 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_23 ) {
if ( V_51 & V_164 ) {
ASSERT ( V_3 -> V_6 & V_22 ) ;
V_47 = V_48 ;
} else {
V_47 = 0 ;
}
F_28 ( V_2 , V_3 -> V_23 , NULL , V_47 ) ;
}
F_24 ( & V_3 -> V_29 , V_35 ) ;
F_52 ( V_3 , V_136 , V_51 ) ;
F_11 ( V_3 ) ;
}
int
F_74 (
struct V_20 * * V_175 ,
struct V_176 * V_177 )
{
struct V_20 * V_178 ;
struct V_30 V_179 ;
int error ;
V_178 = * V_175 ;
F_75 ( V_178 , V_177 , V_180 ) ;
V_179 . V_38 = V_178 -> V_40 ;
V_179 . V_42 = V_178 -> V_41 ;
* V_175 = F_18 ( V_178 ) ;
error = F_63 ( V_178 , 0 ) ;
if ( error )
return error ;
V_178 = * V_175 ;
F_76 ( V_178 -> V_23 ) ;
V_179 . V_43 = V_22 ;
error = F_21 ( V_178 , & V_179 , 0 , 0 ) ;
if ( error )
return error ;
F_77 ( V_178 , V_177 , 0 ) ;
return 0 ;
}
