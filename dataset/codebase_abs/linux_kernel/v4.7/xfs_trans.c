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
F_19 ( V_4 -> V_6 , - ( ( V_31 ) V_27 ) , V_29 ) ;
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
void
F_29 (
T_1 * V_4 ,
T_2 V_49 ,
V_31 V_50 )
{
T_3 V_42 = ( V_51 | V_52 ) ;
T_4 * V_2 = V_4 -> V_6 ;
switch ( V_49 ) {
case V_53 :
V_4 -> V_54 += V_50 ;
if ( F_30 ( & V_2 -> V_55 ) )
V_42 &= ~ V_52 ;
break;
case V_56 :
V_4 -> V_57 += V_50 ;
if ( F_30 ( & V_2 -> V_55 ) )
V_42 &= ~ V_52 ;
break;
case V_58 :
if ( V_50 < 0 ) {
V_4 -> V_21 += ( T_2 ) - V_50 ;
ASSERT ( V_4 -> V_21 <= V_4 -> V_20 ) ;
}
V_4 -> V_59 += V_50 ;
if ( F_30 ( & V_2 -> V_55 ) )
V_42 &= ~ V_52 ;
break;
case V_60 :
ASSERT ( V_50 < 0 ) ;
V_4 -> V_61 += V_50 ;
if ( F_30 ( & V_2 -> V_55 ) )
V_42 &= ~ V_52 ;
break;
case V_62 :
if ( V_50 < 0 ) {
V_4 -> V_23 += ( T_2 ) - V_50 ;
ASSERT ( V_4 -> V_23 <= V_4 -> V_22 ) ;
}
V_4 -> V_63 += V_50 ;
break;
case V_64 :
ASSERT ( V_50 < 0 ) ;
V_4 -> V_65 += V_50 ;
break;
case V_66 :
ASSERT ( V_50 > 0 ) ;
V_4 -> V_67 += V_50 ;
break;
case V_68 :
ASSERT ( V_50 > 0 ) ;
V_4 -> V_69 += V_50 ;
break;
case V_70 :
V_4 -> V_71 += V_50 ;
break;
case V_72 :
V_4 -> V_73 += V_50 ;
break;
case V_74 :
V_4 -> V_75 += V_50 ;
break;
case V_76 :
V_4 -> V_77 += V_50 ;
break;
case V_78 :
V_4 -> V_79 += V_50 ;
break;
case V_80 :
V_4 -> V_81 += V_50 ;
break;
default:
ASSERT ( 0 ) ;
return;
}
V_4 -> V_8 |= V_42 ;
}
STATIC void
F_31 (
T_1 * V_4 )
{
T_5 * V_82 ;
T_6 * V_83 ;
int V_84 = 0 ;
V_83 = F_32 ( V_4 , V_4 -> V_6 , 0 ) ;
V_82 = F_33 ( V_83 ) ;
ASSERT ( ( V_4 -> V_59 + V_4 -> V_61 ) ==
( V_4 -> V_85 + V_4 -> V_86 +
V_4 -> V_87 ) ) ;
if ( ! F_30 ( & ( V_4 -> V_6 -> V_55 ) ) ) {
if ( V_4 -> V_54 )
F_34 ( & V_82 -> V_88 , V_4 -> V_54 ) ;
if ( V_4 -> V_57 )
F_34 ( & V_82 -> V_89 , V_4 -> V_57 ) ;
if ( V_4 -> V_59 )
F_34 ( & V_82 -> V_90 , V_4 -> V_59 ) ;
if ( V_4 -> V_61 )
F_34 ( & V_82 -> V_90 , V_4 -> V_61 ) ;
}
if ( V_4 -> V_63 )
F_34 ( & V_82 -> V_91 , V_4 -> V_63 ) ;
if ( V_4 -> V_65 )
F_34 ( & V_82 -> V_91 , V_4 -> V_65 ) ;
if ( V_4 -> V_67 ) {
F_34 ( & V_82 -> V_92 , V_4 -> V_67 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_69 ) {
F_35 ( & V_82 -> V_93 , V_4 -> V_69 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_71 ) {
V_82 -> V_94 += V_4 -> V_71 ;
V_84 = 1 ;
}
if ( V_4 -> V_73 ) {
F_35 ( & V_82 -> V_95 , V_4 -> V_73 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_75 ) {
F_35 ( & V_82 -> V_96 , V_4 -> V_75 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_77 ) {
F_34 ( & V_82 -> V_97 , V_4 -> V_77 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_79 ) {
F_34 ( & V_82 -> V_98 , V_4 -> V_79 ) ;
V_84 = 1 ;
}
if ( V_4 -> V_81 ) {
V_82 -> V_99 += V_4 -> V_81 ;
V_84 = 1 ;
}
F_36 ( V_4 , V_83 , V_100 ) ;
if ( V_84 )
F_37 ( V_4 , V_83 , 0 , sizeof( T_5 ) - 1 ) ;
else
F_37 ( V_4 , V_83 , F_38 ( T_5 , V_88 ) ,
F_38 ( T_5 , V_91 ) +
sizeof( V_82 -> V_91 ) - 1 ) ;
}
STATIC int
F_39 (
T_7 * V_49 ,
T_8 V_50 )
{
T_8 V_101 = * V_49 ;
V_101 += V_50 ;
if ( V_101 < 0 ) {
ASSERT ( 0 ) ;
return - V_102 ;
}
* V_49 = V_101 ;
return 0 ;
}
STATIC int
F_40 (
T_3 * V_49 ,
T_9 V_50 )
{
T_9 V_101 = * V_49 ;
V_101 += V_50 ;
if ( V_101 < 0 ) {
ASSERT ( 0 ) ;
return - V_102 ;
}
* V_49 = V_101 ;
return 0 ;
}
STATIC int
F_41 (
T_10 * V_49 ,
V_31 V_50 )
{
V_31 V_101 = * V_49 ;
V_101 += V_50 ;
if ( V_101 < 0 ) {
ASSERT ( 0 ) ;
return - V_102 ;
}
* V_49 = V_101 ;
return 0 ;
}
void
F_42 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
bool V_29 = ( V_4 -> V_8 & V_19 ) != 0 ;
V_31 V_103 = 0 ;
V_31 V_104 = 0 ;
V_31 V_105 = 0 ;
V_31 V_106 = 0 ;
int error ;
if ( V_4 -> V_20 > 0 )
V_103 = V_4 -> V_20 ;
if ( ( V_4 -> V_59 != 0 ) &&
( F_30 ( & V_2 -> V_55 ) ||
( V_4 -> V_8 & V_52 ) ) )
V_103 += V_4 -> V_59 ;
if ( V_4 -> V_22 > 0 )
V_104 = V_4 -> V_22 ;
if ( ( V_4 -> V_63 != 0 ) &&
( V_4 -> V_8 & V_52 ) )
V_104 += V_4 -> V_63 ;
if ( F_30 ( & V_2 -> V_55 ) ||
( V_4 -> V_8 & V_52 ) ) {
V_105 = V_4 -> V_54 ;
V_106 = V_4 -> V_57 ;
}
if ( V_103 ) {
error = F_19 ( V_2 , V_103 , V_29 ) ;
if ( error )
goto V_107;
}
if ( V_105 ) {
error = F_43 ( V_2 , V_105 ) ;
if ( error )
goto V_108;
}
if ( V_106 ) {
error = F_44 ( V_2 , V_106 ) ;
if ( error )
goto V_109;
}
if ( V_104 == 0 && ! ( V_4 -> V_8 & V_52 ) )
return;
F_45 ( & V_2 -> V_110 ) ;
if ( V_104 ) {
error = F_41 ( & V_2 -> V_55 . V_91 , V_104 ) ;
if ( error )
goto V_111;
}
if ( V_4 -> V_67 != 0 ) {
error = F_41 ( & V_2 -> V_55 . V_92 , V_4 -> V_67 ) ;
if ( error )
goto V_112;
}
if ( V_4 -> V_69 != 0 ) {
error = F_40 ( & V_2 -> V_55 . V_93 , V_4 -> V_69 ) ;
if ( error )
goto V_113;
}
if ( V_4 -> V_71 != 0 ) {
error = F_39 ( & V_2 -> V_55 . V_94 , V_4 -> V_71 ) ;
if ( error )
goto V_114;
}
if ( V_4 -> V_73 != 0 ) {
error = F_40 ( & V_2 -> V_55 . V_95 ,
V_4 -> V_73 ) ;
if ( error )
goto V_115;
}
if ( V_4 -> V_75 != 0 ) {
error = F_40 ( & V_2 -> V_55 . V_96 ,
V_4 -> V_75 ) ;
if ( error )
goto V_116;
}
if ( V_4 -> V_77 != 0 ) {
error = F_41 ( & V_2 -> V_55 . V_97 , V_4 -> V_77 ) ;
if ( error )
goto V_117;
}
if ( V_4 -> V_79 != 0 ) {
error = F_41 ( & V_2 -> V_55 . V_98 ,
V_4 -> V_79 ) ;
if ( error )
goto V_118;
}
if ( V_4 -> V_81 != 0 ) {
error = F_39 ( & V_2 -> V_55 . V_99 ,
V_4 -> V_81 ) ;
if ( error )
goto V_119;
}
F_46 ( & V_2 -> V_110 ) ;
return;
V_119:
if ( V_4 -> V_79 )
F_41 ( & V_2 -> V_55 . V_98 , - V_4 -> V_79 ) ;
V_118:
if ( V_4 -> V_77 )
F_41 ( & V_2 -> V_55 . V_97 , - V_4 -> V_77 ) ;
V_117:
if ( V_4 -> V_75 )
F_40 ( & V_2 -> V_55 . V_96 , - V_4 -> V_75 ) ;
V_116:
if ( V_4 -> V_73 )
F_40 ( & V_2 -> V_55 . V_95 , - V_4 -> V_73 ) ;
V_115:
if ( V_4 -> V_73 )
F_39 ( & V_2 -> V_55 . V_94 , - V_4 -> V_71 ) ;
V_114:
if ( V_4 -> V_69 )
F_40 ( & V_2 -> V_55 . V_93 , - V_4 -> V_69 ) ;
V_113:
if ( V_4 -> V_67 )
F_41 ( & V_2 -> V_55 . V_92 , - V_4 -> V_67 ) ;
V_112:
if ( V_104 )
F_41 ( & V_2 -> V_55 . V_91 , - V_104 ) ;
V_111:
F_46 ( & V_2 -> V_110 ) ;
if ( V_106 )
F_44 ( V_2 , - V_106 ) ;
V_109:
if ( V_105 )
F_43 ( V_2 , - V_105 ) ;
V_108:
if ( V_103 )
F_19 ( V_2 , - V_103 , V_29 ) ;
V_107:
ASSERT ( error == 0 ) ;
return;
}
void
F_47 (
struct V_3 * V_4 ,
struct V_120 * V_121 )
{
struct V_122 * V_123 ;
ASSERT ( V_121 -> V_124 == V_4 -> V_6 ) ;
ASSERT ( V_121 -> V_125 == V_4 -> V_6 -> V_126 ) ;
V_123 = F_12 ( V_127 , V_13 | V_48 ) ;
V_123 -> V_128 = V_121 ;
V_123 -> V_129 = 0 ;
F_48 ( & V_123 -> V_130 , & V_4 -> V_16 ) ;
V_121 -> V_131 = V_123 ;
}
STATIC void
F_49 (
struct V_122 * V_123 )
{
F_50 ( & V_123 -> V_130 ) ;
F_10 ( V_127 , V_123 ) ;
}
void
F_51 (
struct V_120 * V_121 )
{
F_49 ( V_121 -> V_131 ) ;
V_121 -> V_131 = NULL ;
}
void
F_52 (
struct V_3 * V_4 ,
T_11 V_132 ,
bool abort )
{
struct V_122 * V_123 , * V_133 ;
F_53 (lidp, next, &tp->t_items, lid_trans) {
struct V_120 * V_121 = V_123 -> V_128 ;
V_121 -> V_131 = NULL ;
if ( V_132 != V_134 )
V_121 -> V_135 -> V_136 ( V_121 , V_132 ) ;
if ( abort )
V_121 -> V_137 |= V_138 ;
V_121 -> V_135 -> V_139 ( V_121 ) ;
F_49 ( V_123 ) ;
}
}
static inline void
F_54 (
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_120 * * V_144 ,
int V_145 ,
T_11 V_132 )
{
int V_146 ;
F_45 ( & V_141 -> V_147 ) ;
F_55 ( V_141 , V_143 , V_144 , V_145 , V_132 ) ;
for ( V_146 = 0 ; V_146 < V_145 ; V_146 ++ ) {
struct V_120 * V_121 = V_144 [ V_146 ] ;
V_121 -> V_135 -> V_148 ( V_121 , 0 ) ;
}
}
void
F_56 (
struct V_140 * V_141 ,
struct V_149 * V_150 ,
T_11 V_132 ,
int V_151 )
{
#define F_57 32
struct V_120 * V_144 [ F_57 ] ;
struct V_149 * V_152 ;
struct V_142 V_143 ;
int V_146 = 0 ;
F_45 ( & V_141 -> V_147 ) ;
F_58 ( V_141 , & V_143 , V_132 ) ;
F_46 ( & V_141 -> V_147 ) ;
for ( V_152 = V_150 ; V_152 ; V_152 = V_152 -> V_153 ) {
struct V_120 * V_121 = V_152 -> V_154 ;
T_11 V_155 ;
if ( V_151 )
V_121 -> V_137 |= V_138 ;
V_155 = V_121 -> V_135 -> V_156 ( V_121 , V_132 ) ;
if ( F_59 ( V_155 , ( T_11 ) - 1 ) == 0 )
continue;
if ( V_151 ) {
ASSERT ( F_60 ( V_141 -> V_157 ) ) ;
V_121 -> V_135 -> V_148 ( V_121 , 1 ) ;
continue;
}
if ( V_155 != V_132 ) {
F_45 ( & V_141 -> V_147 ) ;
if ( F_59 ( V_155 , V_121 -> V_158 ) > 0 )
F_61 ( V_141 , V_121 , V_155 ) ;
else
F_46 ( & V_141 -> V_147 ) ;
V_121 -> V_135 -> V_148 ( V_121 , 0 ) ;
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
struct V_3 * V_4 ,
bool V_159 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
T_11 V_132 = - 1 ;
int error = 0 ;
int V_160 = V_4 -> V_8 & V_161 ;
if ( ! ( V_4 -> V_8 & V_51 ) )
goto V_162;
if ( F_60 ( V_2 ) ) {
error = - V_163 ;
goto V_162;
}
ASSERT ( V_4 -> V_18 != NULL ) ;
if ( V_4 -> V_8 & V_52 )
F_31 ( V_4 ) ;
F_64 ( V_4 ) ;
F_65 ( V_2 , V_4 , & V_132 , V_159 ) ;
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_4 ( V_4 ) ;
if ( V_160 ) {
error = F_66 ( V_2 , V_132 , V_164 , NULL ) ;
F_67 ( V_2 , V_165 ) ;
} else {
F_67 ( V_2 , V_166 ) ;
}
return error ;
V_162:
F_42 ( V_4 ) ;
F_68 ( V_4 ) ;
if ( V_4 -> V_18 ) {
V_132 = F_24 ( V_2 , V_4 -> V_18 , NULL , V_159 ) ;
if ( V_132 == - 1 && ! error )
error = - V_163 ;
}
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_52 ( V_4 , V_134 , ! ! error ) ;
F_4 ( V_4 ) ;
F_67 ( V_2 , V_167 ) ;
return error ;
}
int
F_69 (
struct V_3 * V_4 )
{
return F_63 ( V_4 , false ) ;
}
void
F_28 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_6 ;
bool V_168 = ( V_4 -> V_8 & V_51 ) ;
if ( V_168 && ! F_60 ( V_2 ) ) {
F_70 ( L_1 , V_169 , V_2 ) ;
F_71 ( V_2 , V_170 ) ;
}
#ifdef F_72
if ( ! V_168 && ! F_60 ( V_2 ) ) {
struct V_122 * V_123 ;
F_73 (lidp, &tp->t_items, lid_trans)
ASSERT ( ! ( V_123 -> V_128 -> V_171 == V_172 ) ) ;
}
#endif
F_42 ( V_4 ) ;
F_68 ( V_4 ) ;
if ( V_4 -> V_18 )
F_24 ( V_2 , V_4 -> V_18 , NULL , false ) ;
F_20 ( & V_4 -> V_24 , V_30 ) ;
F_52 ( V_4 , V_134 , V_168 ) ;
F_4 ( V_4 ) ;
}
int
F_74 (
struct V_3 * * V_43 ,
struct V_173 * V_174 ,
int * V_175 )
{
struct V_3 * V_176 ;
struct V_25 V_177 ;
int error ;
* V_175 = 0 ;
V_176 = * V_43 ;
if ( V_174 )
F_75 ( V_176 , V_174 , V_178 ) ;
V_177 . V_33 = V_176 -> V_35 ;
V_177 . V_37 = V_176 -> V_36 ;
* V_43 = F_11 ( V_176 ) ;
error = F_63 ( V_176 , true ) ;
if ( error )
return error ;
* V_175 = 1 ;
V_176 = * V_43 ;
V_177 . V_38 = V_17 ;
error = F_17 ( V_176 , & V_177 , 0 , 0 ) ;
if ( error )
return error ;
if ( V_174 )
F_76 ( V_176 , V_174 , 0 ) ;
return 0 ;
}
int
F_77 (
struct V_3 * * V_43 ,
struct V_173 * V_174 )
{
int V_175 ;
return F_74 ( V_43 , V_174 , & V_175 ) ;
}
