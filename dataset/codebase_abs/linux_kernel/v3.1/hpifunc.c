T_1 F_1 ( const char V_1 , const T_2 V_2 ,
const T_2 V_3 )
{
union V_4 V_5 ;
V_5 . V_6 . V_2 = V_2 ;
V_5 . V_6 . V_7 = 0 ;
V_5 . V_6 . V_8 = 0 ;
V_5 . V_6 . V_9 = V_1 ;
V_5 . V_6 . V_10 = V_3 ;
return V_5 . V_11 ;
}
static T_2 F_2 ( const T_1 V_6 , T_2 * V_12 , T_2 * V_13 )
{
union V_4 V_14 ;
if ( ! V_6 )
return V_15 ;
V_14 . V_11 = V_6 ;
* V_12 = ( T_2 ) V_14 . V_6 . V_2 ;
if ( V_13 )
* V_13 = ( T_2 ) V_14 . V_6 . V_10 ;
return 0 ;
}
void F_3 ( const T_1 V_5 , T_2 * V_16 ,
T_2 * V_17 )
{
F_2 ( V_5 , V_16 , V_17 ) ;
}
char F_4 ( const T_1 V_5 )
{
union V_4 V_14 ;
V_14 . V_11 = V_5 ;
return ( char ) V_14 . V_6 . V_9 ;
}
void F_5 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
V_19 -> V_22 = V_21 -> V_22 ;
V_19 -> V_23 = V_21 -> V_23 ;
V_19 -> V_24 = V_21 -> V_24 ;
V_19 -> V_25 = V_21 -> V_25 ;
V_19 -> V_26 = V_21 -> V_26 ;
}
static void F_6 ( struct V_20 * V_21 ,
struct V_18 * V_19 )
{
V_21 -> V_22 = V_19 -> V_22 ;
V_21 -> V_23 = V_19 -> V_23 ;
V_21 -> V_24 = V_19 -> V_24 ;
V_21 -> V_25 = V_19 -> V_25 ;
V_21 -> V_26 = V_19 -> V_26 ;
V_21 -> V_27 = 0 ;
V_21 -> V_28 = 0 ;
}
void F_7 ( struct V_29 * V_30 )
{
V_30 -> V_31 . V_32 . V_33 =
V_30 -> V_31 . V_34 . V_33 ;
V_30 -> V_31 . V_32 . V_35 = V_30 -> V_31 . V_34 . V_35 ;
}
static inline void F_8 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
F_9 ( (struct V_40 * ) V_37 , (struct V_41 * ) V_39 ) ;
}
T_2 F_10 ( T_1 * V_42 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_45 ,
V_46 ) ;
F_9 ( & V_43 , & V_44 ) ;
* V_42 = V_44 . V_31 . V_47 . V_48 ;
return V_44 . error ;
}
T_2 F_12 ( int * V_49 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_45 ,
V_50 ) ;
F_9 ( & V_43 , & V_44 ) ;
* V_49 = ( int ) V_44 . V_31 . V_47 . V_51 ;
return V_44 . error ;
}
T_2 F_13 ( int V_52 , T_1 * V_53 ,
T_2 * V_54 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_45 ,
V_55 ) ;
V_43 . V_10 = ( T_2 ) V_52 ;
F_9 ( & V_43 , & V_44 ) ;
* V_53 = ( int ) V_44 . V_31 . V_47 . V_2 ;
* V_54 = V_44 . V_31 . V_47 . V_56 ;
return V_44 . error ;
}
T_2 F_14 ( T_2 V_2 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_58 ) ;
V_43 . V_2 = V_2 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_15 ( T_2 V_2 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_59 ) ;
V_43 . V_2 = V_2 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_16 ( T_2 V_2 , T_1 V_60 )
{
return F_17 ( V_2 , V_60 ,
V_61 ) ;
}
T_2 F_17 ( T_2 V_2 , T_1 V_60 ,
T_2 V_62 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_63 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_31 . V_64 . V_65 . V_60 = V_60 ;
V_43 . V_31 . V_64 . V_65 . V_62 = V_62 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_18 ( T_2 V_2 , T_1 * V_66 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_67 ) ;
V_43 . V_2 = V_2 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_66 )
* V_66 = V_44 . V_31 . V_64 . V_65 . V_60 ;
return V_44 . error ;
}
T_2 F_19 ( T_2 V_2 , T_2 * V_68 ,
T_2 * V_69 , T_2 * V_70 , T_1 * V_71 ,
T_2 * V_54 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_72 ) ;
V_43 . V_2 = V_2 ;
F_9 ( & V_43 , & V_44 ) ;
* V_54 = V_44 . V_31 . V_64 . V_73 . V_56 ;
* V_68 = V_44 . V_31 . V_64 . V_73 . V_74 ;
* V_69 = V_44 . V_31 . V_64 . V_73 . V_75 ;
* V_70 = V_44 . V_31 . V_64 . V_73 . V_76 ;
* V_71 = V_44 . V_31 . V_64 . V_73 . V_77 ;
return V_44 . error ;
}
T_2 F_20 ( T_2 V_2 , T_2 V_78 ,
T_2 * V_79 , T_2 * V_80 , T_2 * V_70 ,
T_1 * V_71 , T_2 * V_81 , T_1 * V_82 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_83 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_31 . V_64 . V_84 . V_85 = V_78 ;
F_9 ( & V_43 , & V_44 ) ;
* V_81 = V_44 . V_31 . V_64 . V_73 . V_56 ;
* V_79 = V_44 . V_31 . V_64 . V_73 . V_74 ;
* V_80 = V_44 . V_31 . V_64 . V_73 . V_75 ;
* V_70 = V_44 . V_31 . V_64 . V_73 . V_76 ;
* V_71 = V_44 . V_31 . V_64 . V_73 . V_77 ;
* V_82 = 0 ;
return V_44 . error ;
}
T_2 F_21 ( T_2 V_2 , T_2 V_86 , T_2 V_87 ,
T_2 V_88 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_89 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_31 . V_64 . V_90 . V_86 = V_86 ;
V_43 . V_31 . V_64 . V_90 . V_87 = V_87 ;
V_43 . V_31 . V_64 . V_90 . V_88 = V_88 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_22 ( T_2 V_2 , T_2 V_86 ,
T_2 * V_91 , T_2 * V_92 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_57 ,
V_93 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_31 . V_64 . V_90 . V_86 = V_86 ;
F_9 ( & V_43 , & V_44 ) ;
if ( ! V_44 . error ) {
if ( V_91 )
* V_91 = V_44 . V_31 . V_64 . V_94 . V_87 ;
if ( V_92 )
* V_92 = V_44 . V_31 . V_64 . V_94 . V_88 ;
}
return V_44 . error ;
}
T_2 F_23 ( T_2 V_2 , T_2 V_85 ,
T_2 V_95 , T_2 V_96 , T_1 * V_97 )
{
return 0 ;
}
T_2 F_24 ( struct V_20 * V_98 , T_2 V_25 , T_2 V_26 ,
T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
T_2 V_99 = 0 ;
struct V_18 V_100 ;
switch ( V_25 ) {
case 1 :
case 2 :
case 4 :
case 6 :
case 8 :
case 16 :
break;
default:
V_99 = V_101 ;
return V_99 ;
}
V_100 . V_25 = V_25 ;
switch ( V_26 ) {
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
break;
default:
V_99 = V_118 ;
return V_99 ;
}
V_100 . V_26 = V_26 ;
if ( V_22 < 8000L ) {
V_99 = V_119 ;
V_22 = 8000L ;
}
if ( V_22 > 200000L ) {
V_99 = V_119 ;
V_22 = 200000L ;
}
V_100 . V_22 = V_22 ;
switch ( V_26 ) {
case V_108 :
case V_109 :
case V_110 :
V_100 . V_23 = V_23 ;
break;
case V_102 :
case V_106 :
V_100 . V_23 = V_25 * V_22 * 2 ;
break;
case V_104 :
case V_105 :
V_100 . V_23 = V_25 * V_22 * 4 ;
break;
case V_107 :
V_100 . V_23 = V_25 * V_22 ;
break;
default:
V_100 . V_23 = 0 ;
}
switch ( V_26 ) {
case V_109 :
if ( ( V_25 == 1 )
&& ( V_24 != V_120 ) ) {
V_24 = V_120 ;
V_99 = V_118 ;
} else if ( V_24 > V_121 ) {
V_24 = V_120 ;
V_99 = V_118 ;
}
V_100 . V_24 = V_24 ;
break;
default:
V_100 . V_24 = V_24 ;
}
F_6 ( V_98 , & V_100 ) ;
return V_99 ;
}
T_2 F_25 ( struct V_20 * V_98 ,
T_1 V_122 , T_1 * V_123 )
{
T_1 V_124 ;
T_1 V_125 ;
T_2 V_25 ;
struct V_20 * V_21 = V_98 ;
V_25 = V_21 -> V_25 ;
switch ( V_21 -> V_26 ) {
case V_106 :
case V_102 :
V_124 = V_21 -> V_22 * 2L * V_25 ;
break;
case V_103 :
V_124 = V_21 -> V_22 * 3L * V_25 ;
break;
case V_104 :
case V_105 :
V_124 = V_21 -> V_22 * 4L * V_25 ;
break;
case V_107 :
V_124 = V_21 -> V_22 * 1L * V_25 ;
break;
case V_108 :
case V_109 :
case V_110 :
V_124 = V_21 -> V_23 / 8L ;
break;
case V_111 :
V_124 = 256000L / 8L ;
break;
default:
return V_118 ;
}
V_125 = ( V_124 * V_122 * 2 ) /
1000L ;
* V_123 =
F_26 ( ( ( V_125 + 4095L ) & ~ 4095L ) ) ;
return 0 ;
}
T_2 F_27 ( T_2 V_2 , T_2 V_126 ,
T_1 * V_127 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_129 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_10 = V_126 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 )
* V_127 =
F_1 ( V_128 , V_2 ,
V_126 ) ;
else
* V_127 = 0 ;
return V_44 . error ;
}
T_2 F_28 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_131 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_132 ) ;
F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) ;
F_9 ( & V_43 , & V_44 ) ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_133 ) ;
F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_29 ( T_1 V_130 , T_2 * V_134 ,
T_1 * V_135 , T_1 * V_136 , T_1 * V_137 ,
T_1 * V_138 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_139 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_134 )
* V_134 = V_44 . V_31 . V_140 . V_31 . V_34 . V_35 ;
if ( V_135 )
* V_135 = V_44 . V_31 . V_140 . V_31 . V_34 . V_141 ;
if ( V_136 )
* V_136 = V_44 . V_31 . V_140 . V_31 . V_34 . V_142 ;
if ( V_137 )
* V_137 = V_44 . V_31 . V_140 . V_31 . V_34 . V_143 ;
if ( V_138 )
* V_138 =
V_44 . V_31 . V_140 . V_31 . V_34 . V_33 ;
return V_44 . error ;
}
T_2 F_30 ( T_1 V_130 , const T_3 * V_144 ,
T_1 V_145 , const struct V_20 * V_98 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_146 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_144 = ( T_3 * ) V_144 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 = V_145 ;
F_5 ( & V_43 . V_31 . V_140 . V_31 . V_48 . V_26 , V_98 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_31 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_148 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_32 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_149 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_33 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_150 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_34 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_151 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_35 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_152 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_36 ( T_1 V_130 , struct V_20 * V_98 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_153 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_5 ( & V_43 . V_31 . V_140 . V_31 . V_48 . V_26 , V_98 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_37 ( T_1 V_130 , struct V_20 * V_98 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_154 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_5 ( & V_43 . V_31 . V_140 . V_31 . V_48 . V_26 , V_98 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_38 ( T_1 V_130 , short V_155 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_156 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_155 = V_155 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_39 ( T_1 V_130 , T_1 V_157 ,
T_1 V_158 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_159 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_160 . V_157 = V_157 ;
V_43 . V_31 . V_140 . V_31 . V_160 . V_158 = V_158 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_40 ( T_1 V_130 , T_2 V_65 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_161 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_26 . V_25 = V_65 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_41 ( T_1 V_130 , T_1 * V_162 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_163 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 ) {
if ( V_162 )
* V_162 =
V_44 . V_31 . V_140 . V_31 . V_34 . V_142 /
sizeof( struct V_164 ) ;
}
return V_44 . error ;
}
T_2 F_42 ( T_1 V_130 ,
struct V_164 * V_165 ,
T_1 V_166 ,
T_1 V_167 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_168 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_144 = ( T_3 * ) V_165 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 =
V_167 *
sizeof( struct V_164 ) ;
if ( V_43 . V_31 . V_140 . V_31 . V_48 . V_147 <= V_166 )
F_9 ( & V_43 , & V_44 ) ;
else
V_44 . error = V_169 ;
return V_44 . error ;
}
T_2 F_43 ( T_1 V_130 , T_1 V_170 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_171 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_170 = V_170 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_44 ( T_1 V_130 , T_1 V_172 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_173 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 = V_172 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_45 ( T_1 V_130 , T_3 * * V_174 ,
struct V_175 * * V_176 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_177 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 ) {
if ( V_174 )
* V_174 = V_44 . V_31 . V_140 . V_31 . V_178 . V_179 ;
if ( V_176 )
* V_176 = V_44 . V_31 . V_140 . V_31 . V_178 . V_180 ;
}
return V_44 . error ;
}
T_2 F_46 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_131 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_47 ( T_1 V_130 , T_1 V_181 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
T_2 V_182 ;
char V_183 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_184 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
if ( F_2 ( V_181 , & V_182 ,
& V_43 . V_31 . V_140 . V_31 . V_185 . V_186 ) )
return V_15 ;
V_183 = F_4 ( V_181 ) ;
switch ( V_183 ) {
case V_128 :
case V_187 :
V_43 . V_31 . V_140 . V_31 . V_185 . V_188 = V_183 ;
break;
default:
return V_189 ;
}
if ( V_182 != V_43 . V_2 )
return V_190 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_48 ( T_1 V_130 , T_1 * V_191 ,
T_1 * V_192 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_193 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_191 )
* V_191 = V_44 . V_31 . V_140 . V_31 . V_194 . V_195 ;
if ( V_192 )
* V_192 = V_44 . V_31 . V_140 . V_31 . V_194 . V_196 ;
return V_44 . error ;
}
T_2 F_49 ( T_1 V_130 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_128 ,
V_132 ) ;
if ( F_2 ( V_130 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_50 ( T_2 V_2 , T_2 V_197 , T_1 * V_198 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_199 ) ;
V_43 . V_2 = V_2 ;
V_43 . V_10 = V_197 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 )
* V_198 =
F_1 ( V_187 , V_2 ,
V_197 ) ;
else
* V_198 = 0 ;
return V_44 . error ;
}
T_2 F_51 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_201 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_202 ) ;
F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) ;
F_9 ( & V_43 , & V_44 ) ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_203 ) ;
F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_52 ( T_1 V_200 ,
const struct V_20 * V_98 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_204 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_5 ( & V_43 . V_31 . V_140 . V_31 . V_48 . V_26 , V_98 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_53 ( T_1 V_200 , const struct V_20 * V_98 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_205 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_5 ( & V_43 . V_31 . V_140 . V_31 . V_48 . V_26 , V_98 ) ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_54 ( T_1 V_200 , T_3 * V_144 , T_1 V_206 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_207 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 = V_206 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_144 = V_144 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_55 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_208 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_56 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_209 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_57 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_210 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_58 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_211 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_59 ( T_1 V_200 , T_2 * V_134 , T_1 * V_135 ,
T_1 * V_212 , T_1 * V_213 ,
T_1 * V_214 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_215 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_134 )
* V_134 = V_44 . V_31 . V_140 . V_31 . V_34 . V_35 ;
if ( V_135 )
* V_135 = V_44 . V_31 . V_140 . V_31 . V_34 . V_141 ;
if ( V_212 )
* V_212 = V_44 . V_31 . V_140 . V_31 . V_34 . V_142 ;
if ( V_213 )
* V_213 = V_44 . V_31 . V_140 . V_31 . V_34 . V_143 ;
if ( V_214 )
* V_214 =
V_44 . V_31 . V_140 . V_31 . V_34 . V_33 ;
return V_44 . error ;
}
T_2 F_60 ( T_1 V_200 , T_2 V_216 ,
T_2 V_65 , T_2 V_217 , T_2 V_218 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_219 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_26 . V_24 = V_216 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_26 . V_26 = ( V_65 << 8 ) | ( V_217 & 0xff ) ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_26 . V_25 = V_218 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_61 ( T_1 V_200 , T_1 * V_220 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_221 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_220 )
* V_220 =
( V_44 . V_31 . V_140 . V_31 . V_34 . V_141 -
V_44 . V_31 . V_140 . V_31 . V_34 . V_142 ) /
sizeof( struct V_164 ) ;
return V_44 . error ;
}
T_2 F_62 ( T_1 V_200 ,
const struct V_164 * V_165 ,
T_1 V_166 ,
T_1 V_222 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_223 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_144 = ( T_3 * ) V_165 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 =
V_222 *
sizeof( struct V_164 ) ;
if ( V_43 . V_31 . V_140 . V_31 . V_48 . V_147 <= V_166 )
F_9 ( & V_43 , & V_44 ) ;
else
V_44 . error = V_169 ;
return V_44 . error ;
}
T_2 F_63 ( T_1 V_200 , T_1 V_172 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_224 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_140 . V_31 . V_48 . V_147 = V_172 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_64 ( T_1 V_200 , T_3 * * V_174 ,
struct V_175 * * V_176 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_225 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 ) {
if ( V_174 )
* V_174 = V_44 . V_31 . V_140 . V_31 . V_178 . V_179 ;
if ( V_176 )
* V_176 = V_44 . V_31 . V_140 . V_31 . V_178 . V_180 ;
}
return V_44 . error ;
}
T_2 F_65 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_201 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_66 ( T_1 V_200 , T_1 V_181 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
T_2 V_182 ;
char V_183 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_226 ) ;
V_44 . error = 0 ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
if ( F_2 ( V_181 , & V_182 ,
& V_43 . V_31 . V_140 . V_31 . V_185 . V_186 ) )
return V_15 ;
V_183 = F_4 ( V_181 ) ;
switch ( V_183 ) {
case V_128 :
case V_187 :
V_43 . V_31 . V_140 . V_31 . V_185 . V_188 = V_183 ;
break;
default:
return V_189 ;
}
if ( V_182 != V_43 . V_2 )
return V_190 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_67 ( T_1 V_200 , T_1 * V_191 ,
T_1 * V_192 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_201 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_191 )
* V_191 = V_44 . V_31 . V_140 . V_31 . V_194 . V_195 ;
if ( V_192 )
* V_192 = V_44 . V_31 . V_140 . V_31 . V_194 . V_196 ;
return V_44 . error ;
}
T_2 F_68 ( T_1 V_200 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_187 ,
V_202 ) ;
if ( F_2 ( V_200 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_69 ( T_2 V_2 , T_1 * V_227 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_228 , V_229 ) ;
V_43 . V_2 = V_2 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 )
* V_227 =
F_1 ( V_228 , V_2 ,
0 ) ;
else
* V_227 = 0 ;
return V_44 . error ;
}
T_2 F_70 ( T_1 V_230 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_228 , V_231 ) ;
if ( F_2 ( V_230 , & V_43 . V_2 , NULL ) )
return V_15 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_71 ( T_1 V_230 , T_2 V_232 ,
T_2 V_233 , T_2 V_234 , T_2 V_235 ,
T_2 V_236 , T_1 * V_237 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_228 ,
V_238 ) ;
if ( F_2 ( V_230 , & V_43 . V_2 , NULL ) )
return V_15 ;
V_43 . V_31 . V_37 . V_239 = V_232 ;
V_43 . V_31 . V_37 . V_240 = V_233 ;
V_43 . V_31 . V_37 . V_241 = V_234 ;
V_43 . V_31 . V_37 . V_242 = V_235 ;
V_43 . V_31 . V_37 . V_236 = V_236 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error == 0 )
* V_237 =
F_1 ( V_243 ,
V_43 . V_2 , V_44 . V_31 . V_37 . V_244 ) ;
else
* V_237 = 0 ;
return V_44 . error ;
}
T_2 F_72 ( T_1 V_230 , T_2 V_244 ,
T_2 * V_245 , T_2 * V_246 , T_2 * V_247 ,
T_2 * V_248 , T_2 * V_249 , T_1 * V_237 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_228 ,
V_250 ) ;
if ( F_2 ( V_230 , & V_43 . V_2 , NULL ) )
return V_15 ;
V_43 . V_31 . V_37 . V_244 = V_244 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_245 ) {
* V_245 =
V_44 . V_31 . V_37 . V_232 + V_251 ;
* V_246 = V_44 . V_31 . V_37 . V_252 ;
* V_247 = V_44 . V_31 . V_37 . V_234 + V_253 ;
* V_248 = V_44 . V_31 . V_37 . V_254 ;
}
if ( V_249 )
* V_249 = V_44 . V_31 . V_37 . V_244 ;
if ( V_237 ) {
if ( V_44 . error == 0 )
* V_237 =
F_1 ( V_243 ,
V_43 . V_2 , V_244 ) ;
else
* V_237 = 0 ;
}
return V_44 . error ;
}
T_2 F_73 ( T_1 V_230 , enum V_255 V_256 ,
T_2 V_85 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_228 , V_257 ) ;
if ( F_2 ( V_230 , & V_43 . V_2 , NULL ) )
return V_15 ;
V_43 . V_31 . V_258 . V_259 . V_256 = V_256 ;
V_43 . V_31 . V_258 . V_259 . V_85 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
static
T_2 F_74 ( const T_1 V_260 , const T_2 V_261 ,
const T_1 V_262 , const T_1 V_263 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_261 ;
V_43 . V_31 . V_265 . V_262 = V_262 ;
V_43 . V_31 . V_265 . V_263 = V_263 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
static T_2 F_75 ( T_1 V_260 , T_2 V_261 , short V_267 ,
short V_268 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_261 ;
V_43 . V_31 . V_265 . V_269 [ 0 ] = V_267 ;
V_43 . V_31 . V_265 . V_269 [ 1 ] = V_268 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
static
T_2 F_76 ( const T_1 V_260 , const T_2 V_261 , T_1 V_262 ,
T_1 V_263 , T_1 * V_270 , T_1 * V_271 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_261 ;
V_43 . V_31 . V_265 . V_262 = V_262 ;
V_43 . V_31 . V_265 . V_263 = V_263 ;
F_9 ( & V_43 , & V_44 ) ;
* V_270 = V_44 . V_31 . V_265 . V_262 ;
if ( V_271 )
* V_271 = V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
static T_2 F_77 ( T_1 V_260 , T_2 V_261 , short * V_267 ,
short * V_268 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_261 ;
F_9 ( & V_43 , & V_44 ) ;
* V_267 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
if ( V_268 )
* V_268 = V_44 . V_31 . V_265 . V_269 [ 1 ] ;
return V_44 . error ;
}
static
T_2 F_78 ( const T_1 V_260 , const T_2 V_261 , const T_1 V_85 ,
const T_1 V_273 , T_1 * V_97 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_274 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_261 ;
V_43 . V_31 . V_265 . V_262 = V_85 ;
V_43 . V_31 . V_265 . V_263 = V_273 ;
F_9 ( & V_43 , & V_44 ) ;
* V_97 = V_44 . V_31 . V_265 . V_262 ;
return V_44 . error ;
}
static T_2 F_79 ( const T_1 V_260 , const T_2 V_266 ,
char * V_275 , const T_1 V_276 )
{
unsigned int V_277 = 0 , V_278 = 0 ;
char V_265 = 0 ;
unsigned int V_279 = 0 ;
T_2 V_99 = 0 ;
if ( ( V_276 < 1 ) || ( V_276 > 256 ) )
return V_280 ;
for ( V_277 = 0 ; V_277 < V_276 ;
V_277 += 8 ) {
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 ,
& V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_266 ;
V_43 . V_31 . V_265 . V_262 = V_277 ;
V_43 . V_31 . V_265 . V_263 = 0 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_277 == 0
&& ( V_44 . V_31 . V_281 . V_282 . V_283 + 8 ) >
V_276 )
return V_280 ;
if ( V_44 . error ) {
V_99 = V_44 . error ;
break;
}
for ( V_278 = 0 ; V_278 < 8 ; V_278 ++ ) {
V_265 = V_44 . V_31 . V_281 . V_282 . V_284 [ V_278 ] ;
V_275 [ V_277 + V_278 ] = V_265 ;
V_279 ++ ;
if ( V_279 >= V_276 ) {
V_275 [ V_276 - 1 ] = 0 ;
V_99 = V_280 ;
break;
}
if ( V_265 == 0 )
break;
}
if ( ( V_44 . V_31 . V_281 . V_282 . V_283 == 0 )
&& ( ( V_277 + V_278 ) < V_276 )
&& ( V_265 != 0 ) ) {
V_265 = 0 ;
V_275 [ V_277 + V_278 ] = V_265 ;
}
if ( V_265 == 0 )
break;
}
return V_99 ;
}
T_2 F_80 ( const T_1 V_285 , const T_1 V_85 ,
T_2 * V_286 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_285 , V_288 , V_85 , 0 , & V_287 ) ;
* V_286 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_81 ( T_1 V_260 , T_2 V_26 )
{
return F_74 ( V_260 , V_288 , V_26 ,
0 ) ;
}
T_2 F_82 ( T_1 V_260 , T_2 * V_286 )
{
T_2 V_99 ;
T_1 V_273 ;
V_99 = F_83 ( V_260 , V_288 , & V_273 ) ;
if ( ! V_99 && V_286 )
* V_286 = ( T_2 ) V_273 ;
return V_99 ;
}
T_2 F_84 ( T_1 V_260 , T_1 * V_289 )
{
return F_83 ( V_260 , V_290 ,
V_289 ) ;
}
T_2 F_85 ( T_1 V_260 , T_2 V_85 , T_2 * V_291 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_292 ;
V_43 . V_31 . V_265 . V_262 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_291 )
* V_291 = ( T_2 ) V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
T_2 F_86 ( T_1 V_260 , T_2 V_85 ,
T_2 * V_291 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_293 ;
V_43 . V_31 . V_265 . V_262 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_291 )
* V_291 = ( T_2 ) V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
T_2 F_87 ( T_1 V_260 , T_2 * V_294 )
{
T_1 V_295 = 0 ;
T_2 V_99 = 0 ;
V_99 = F_83 ( V_260 , V_296 ,
& V_295 ) ;
if ( V_294 )
* V_294 = ( T_2 ) V_295 ;
return V_99 ;
}
T_2 F_88 ( T_1 V_260 , T_1 V_22 )
{
return F_74 ( V_260 , V_297 ,
V_22 , 0 ) ;
}
T_2 F_89 ( T_1 V_260 , T_2 V_85 , T_2 V_48 )
{
return F_74 ( V_260 , V_298 , V_85 ,
V_48 ) ;
}
T_2 F_90 ( T_1 V_260 , T_2 V_85 ,
T_2 V_48 )
{
return F_74 ( V_260 , V_299 ,
V_85 , V_48 ) ;
}
T_2 F_91 ( T_1 V_260 , T_2 V_85 ,
T_2 * V_291 )
{
return V_300 ;
}
T_2 F_92 ( const T_1 V_301 , const T_1 V_85 ,
T_2 * V_286 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_301 , V_302 , V_85 , 0 , & V_287 ) ;
* V_286 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_93 ( T_1 V_260 , T_2 V_303 )
{
return F_74 ( V_260 , V_302 ,
V_303 , 0 ) ;
}
T_2 F_94 ( T_1 V_260 , T_2 * V_304 )
{
T_2 V_99 ;
T_1 V_273 ;
V_99 = F_83 ( V_260 , V_302 , & V_273 ) ;
if ( ! V_99 && V_304 )
* V_304 = ( T_2 ) V_273 ;
return V_99 ;
}
T_2 F_95 ( T_1 V_260 , T_2 V_305 )
{
return F_74 ( V_260 , V_306 ,
V_305 , 0 ) ;
}
T_2 F_96 ( T_1 V_260 , T_2 V_307 )
{
return F_74 ( V_260 , V_308 ,
V_307 , 0 ) ;
}
T_2 F_97 ( T_1 V_260 , T_2 * V_309 ,
T_2 * V_310 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_311 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_309 )
* V_309 = ( T_2 ) V_44 . V_31 . V_265 . V_262 ;
if ( V_310 )
* V_310 = ( T_2 ) V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
T_2 F_98 ( const T_1 V_312 , const T_1 V_85 ,
T_2 * V_313 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_312 , V_314 , V_85 , 0 , & V_287 ) ;
* V_313 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_99 ( T_1 V_260 , T_2 V_65 )
{
return F_74 ( V_260 , V_314 , V_65 ,
0 ) ;
}
T_2 F_100 ( T_1 V_260 , T_2 * V_65 )
{
T_1 V_315 = 0 ;
T_2 V_99 = F_83 ( V_260 ,
V_314 , & V_315 ) ;
if ( V_65 )
* V_65 = ( T_2 ) V_315 ;
return V_99 ;
}
T_2 F_101 ( T_1 V_260 , T_1 V_316 , T_1 V_317 ,
T_3 * V_144 )
{
struct V_318 V_43 ;
struct V_38 V_44 ;
F_102 ( & V_43 . V_6 , sizeof( V_43 ) , & V_44 , sizeof( V_44 ) ,
V_243 , V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_6 . V_2 ,
& V_43 . V_6 . V_10 ) )
return V_15 ;
if ( V_317 > sizeof( V_43 . V_319 ) )
return V_320 ;
V_43 . V_321 . V_266 = V_322 ;
V_43 . V_321 . V_317 = V_317 ;
V_43 . V_321 . V_316 = V_316 ;
memcpy ( V_43 . V_319 , V_144 , V_317 ) ;
V_43 . V_6 . V_125 = ( T_2 ) ( sizeof( V_43 . V_6 ) + sizeof( V_43 . V_321 ) + V_317 ) ;
F_8 ( & V_43 . V_6 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_103 ( T_1 V_260 , T_1 V_316 , T_1 V_323 ,
T_1 * V_324 , T_3 * V_144 )
{
struct V_325 V_43 ;
struct V_326 V_44 ;
F_102 ( & V_43 . V_6 , sizeof( V_43 ) , & V_44 . V_6 , sizeof( V_44 ) ,
V_243 , V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_6 . V_2 ,
& V_43 . V_6 . V_10 ) )
return V_15 ;
if ( V_323 > sizeof( V_44 . V_319 ) )
return V_327 ;
V_43 . V_321 . V_266 = V_328 ;
V_43 . V_321 . V_317 = V_323 ;
V_43 . V_321 . V_316 = V_316 ;
F_8 ( & V_43 . V_6 , & V_44 . V_6 ) ;
if ( ! V_44 . V_6 . error && V_144 ) {
if ( V_44 . V_317 > sizeof( V_44 . V_319 ) )
return V_327 ;
* V_324 = V_44 . V_317 ;
if ( V_44 . V_317 < V_323 )
V_323 = * V_324 ;
memcpy ( V_144 , V_44 . V_319 , V_323 ) ;
}
return V_44 . V_6 . error ;
}
T_2 F_104 ( T_1 V_260 , T_1 * V_329 ,
T_1 * V_330 , T_1 * V_331 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_332 ;
F_9 ( & V_43 , & V_44 ) ;
if ( ! V_44 . error ) {
if ( V_329 )
* V_329 = V_44 . V_31 . V_281 . V_333 . V_334 . V_334 ;
if ( V_330 )
* V_330 =
V_44 . V_31 . V_281 . V_333 . V_334 . V_335 ;
if ( V_331 )
* V_331 =
V_44 . V_31 . V_281 . V_333 . V_334 . V_336 ;
}
return V_44 . error ;
}
T_2 F_105 ( T_1 V_260 , T_1 * V_337 )
{
T_1 V_317 ;
T_1 V_338 ;
T_2 V_99 ;
V_99 = F_103 ( V_260 ,
V_339 , 4 , & V_317 ,
( T_3 * ) & V_338 ) ;
* V_337 =
( ( V_338 & 0xff000000 ) >> 8 ) | ( ( V_338 & 0x00ff0000 ) << 8 ) | ( ( V_338 &
0x0000ff00 ) >> 8 ) | ( ( V_338 & 0x000000ff ) << 8 ) ;
if ( V_99 )
* V_337 = 0 ;
return V_99 ;
}
T_2 F_106 ( T_1 V_260 , T_1 V_340 )
{
T_1 V_338 ;
T_2 V_99 ;
V_338 = ( ( V_340 & 0xff000000 ) >> 8 ) | ( ( V_340 &
0x00ff0000 ) << 8 ) | ( ( V_340 & 0x0000ff00 ) >>
8 ) | ( ( V_340 & 0x000000ff ) << 8 ) ;
V_99 = F_101 ( V_260 ,
V_339 , 4 , ( T_3 * ) & V_338 ) ;
return V_99 ;
}
T_2 F_107 ( T_1 V_260 , T_1 * V_337 )
{
T_1 V_317 ;
T_1 V_338 ;
T_2 V_99 ;
V_99 = F_103 ( V_260 ,
V_341 , 4 , & V_317 ,
( T_3 * ) & V_338 ) ;
* V_337 =
( ( V_338 & 0xff000000 ) >> 8 ) | ( ( V_338 & 0x00ff0000 ) << 8 ) | ( ( V_338 &
0x0000ff00 ) >> 8 ) | ( ( V_338 & 0x000000ff ) << 8 ) ;
if ( V_99 )
* V_337 = 0 ;
return V_99 ;
}
T_2 F_108 ( T_1 V_260 , T_1 V_340 )
{
T_1 V_338 ;
T_2 V_99 ;
V_338 = ( ( V_340 & 0xff000000 ) >> 8 ) | ( ( V_340 &
0x00ff0000 ) << 8 ) | ( ( V_340 & 0x0000ff00 ) >>
8 ) | ( ( V_340 & 0x000000ff ) << 8 ) ;
V_99 = F_101 ( V_260 ,
V_341 , 4 , ( T_3 * ) & V_338 ) ;
return V_99 ;
}
T_2 F_109 ( T_1 V_260 , T_1 * V_342 ,
T_1 * V_343 )
{
T_1 V_317 ;
T_2 V_99 ;
T_1 V_344 ;
V_99 = F_103 ( V_260 ,
V_345 , 4 , & V_317 ,
( T_3 * ) & V_344 ) ;
if ( ! V_99 ) {
* V_342 =
( ( V_344 & 0xff000000 ) >> 8 ) | ( ( V_344 & 0x00ff0000 ) << 8 )
| ( ( V_344 & 0x0000ff00 ) >> 8 ) | ( ( V_344 & 0x000000ff ) <<
8 ) ;
V_99 = F_103 ( V_260 ,
V_345 + 1 , 4 ,
& V_317 , ( T_3 * ) & V_344 ) ;
}
if ( ! V_99 ) {
* V_343 =
( ( V_344 & 0xff000000 ) >> 8 ) | ( ( V_344 & 0x00ff0000 ) << 8 )
| ( ( V_344 & 0x0000ff00 ) >> 8 ) | ( ( V_344 & 0x000000ff ) <<
8 ) ;
} else {
* V_342 = 0 ;
* V_343 = 0 ;
}
return V_99 ;
}
T_2 F_110 ( T_1 V_260 , T_1 V_346 )
{
return F_74 ( V_260 , V_347 , V_346 ,
0 ) ;
}
T_2 F_111 ( T_1 V_260 , T_1 * V_346 )
{
return F_83 ( V_260 , V_347 , V_346 ) ;
}
T_2 F_112 ( T_1 V_260 , short V_348 )
{
return F_75 ( V_260 , V_349 ,
V_348 , 0 ) ;
}
T_2 F_113 ( T_1 V_260 , short * V_348 )
{
return F_77 ( V_260 , V_349 ,
V_348 , NULL ) ;
}
T_2 F_114 ( T_1 V_260 , unsigned int V_85 ,
T_1 V_350 )
{
return F_74 ( V_260 , V_351 , V_350 ,
V_85 ) ;
}
T_2 F_115 ( T_1 V_260 , unsigned int V_85 ,
T_1 * V_350 )
{
return F_76 ( V_260 , V_351 , 0 ,
V_85 , V_350 , NULL ) ;
}
T_2 F_116 ( T_1 V_260 , unsigned int V_85 ,
T_1 V_352 )
{
return F_74 ( V_260 , V_353 , V_352 ,
V_85 ) ;
}
T_2 F_117 ( T_1 V_260 , unsigned int V_85 ,
T_1 * V_352 )
{
return F_76 ( V_260 , V_353 , 0 , V_85 ,
V_352 , NULL ) ;
}
T_2 F_118 ( T_1 V_260 , unsigned int V_85 ,
short V_354 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_355 ;
V_43 . V_31 . V_265 . V_263 = V_85 ;
V_43 . V_31 . V_265 . V_269 [ 0 ] = V_354 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_119 ( T_1 V_260 , unsigned int V_85 ,
short * V_354 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_355 ;
V_43 . V_31 . V_265 . V_263 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
* V_354 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
return V_44 . error ;
}
T_2 F_120 ( T_1 V_260 , T_1 V_85 , T_1 V_356 )
{
return F_74 ( V_260 , V_357 , V_356 ,
V_85 ) ;
}
T_2 F_121 ( T_1 V_260 , T_1 V_85 , T_1 * V_356 )
{
return F_76 ( V_260 , V_357 , 0 , V_85 ,
V_356 , NULL ) ;
}
T_2 F_122 ( T_1 V_260 , short * V_358 ,
short * V_359 , short * V_360 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_361 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error ) {
V_44 . V_31 . V_265 . V_269 [ 0 ] = 0 ;
V_44 . V_31 . V_265 . V_269 [ 1 ] = 0 ;
V_44 . V_31 . V_265 . V_262 = 0 ;
}
if ( V_358 )
* V_358 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
if ( V_359 )
* V_359 = V_44 . V_31 . V_265 . V_269 [ 1 ] ;
if ( V_360 )
* V_360 = ( short ) V_44 . V_31 . V_265 . V_262 ;
return V_44 . error ;
}
T_2 F_123 ( T_1 V_260 , short V_362 [ V_363 ]
)
{
return F_75 ( V_260 , V_364 ,
V_362 [ 0 ] , V_362 [ 1 ] ) ;
}
T_2 F_124 ( T_1 V_260 , short V_362 [ V_363 ]
)
{
return F_77 ( V_260 , V_364 ,
& V_362 [ 0 ] , & V_362 [ 1 ] ) ;
}
T_2 F_125 ( const T_1 V_365 , T_1 * V_366 )
{
return F_78 ( V_365 , V_367 , 0 , 0 ,
V_366 ) ;
}
T_2 F_126 ( T_1 V_260 , short V_368 [ V_363 ]
)
{
short V_369 = 0 ;
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_10 = V_43 . V_10 ;
V_43 . V_31 . V_265 . V_266 = V_370 ;
F_9 ( & V_43 , & V_44 ) ;
if ( ! V_44 . error )
memcpy ( V_368 , V_44 . V_31 . V_265 . V_269 ,
sizeof( short ) * V_363 ) ;
else
for ( V_369 = 0 ; V_369 < V_363 ; V_369 ++ )
V_368 [ V_369 ] = V_371 ;
return V_44 . error ;
}
T_2 F_127 ( T_1 V_260 , short V_372 [ V_363 ]
)
{
short V_369 = 0 ;
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_373 ;
F_9 ( & V_43 , & V_44 ) ;
if ( ! V_44 . error )
memcpy ( V_372 , V_44 . V_31 . V_265 . V_269 ,
sizeof( short ) * V_363 ) ;
else
for ( V_369 = 0 ; V_369 < V_363 ; V_369 ++ )
V_372 [ V_369 ] = V_371 ;
return V_44 . error ;
}
T_2 F_128 ( T_1 V_260 , T_2 V_350 , T_2 V_352 )
{
return F_74 ( V_260 , V_374 ,
V_350 , V_352 ) ;
}
T_2 F_129 ( T_1 V_260 , T_2 * V_375 , T_2 * V_376 )
{
T_1 V_350 ;
T_1 V_352 ;
T_2 error ;
error = F_130 ( V_260 , V_374 ,
& V_350 , & V_352 ) ;
if ( V_375 )
* V_375 = ( unsigned short ) V_350 ;
if ( V_376 )
* V_376 = ( unsigned short ) V_352 ;
return error ;
}
T_2 F_131 ( T_1 V_260 , T_2 V_350 , T_2 V_352 )
{
return F_74 ( V_260 , V_377 ,
V_350 , V_352 ) ;
}
T_2 F_132 ( T_1 V_260 , T_2 * V_375 ,
T_2 * V_376 )
{
T_1 V_350 ;
T_1 V_352 ;
T_2 error ;
error = F_130 ( V_260 , V_377 ,
& V_350 , & V_352 ) ;
if ( V_375 )
* V_375 = ( short ) V_350 ;
if ( V_376 )
* V_376 = ( short ) V_352 ;
return error ;
}
T_2 F_133 ( T_1 V_260 , T_2 V_378 )
{
return F_74 ( V_260 , V_379 ,
( T_1 ) V_378 , 0 ) ;
}
T_2 F_134 ( T_1 V_260 , T_2 * V_380 )
{
T_2 error = 0 ;
T_1 V_378 = 0 ;
error = F_83 ( V_260 ,
V_379 , & V_378 ) ;
if ( V_380 )
* V_380 = ( T_2 ) V_378 ;
return error ;
}
T_2 F_135 ( T_1 V_260 , T_2 V_381 ,
T_2 V_382 )
{
return F_74 ( V_260 , V_383 ,
V_381 , V_382 ) ;
}
T_2 F_136 ( T_1 V_260 , T_2 * V_381 ,
T_2 * V_382 )
{
T_1 V_384 , V_85 ;
T_2 V_99 = F_130 ( V_260 ,
V_383 , & V_384 ,
& V_85 ) ;
if ( V_381 )
* V_381 = ( T_2 ) V_384 ;
if ( V_382 )
* V_382 = ( T_2 ) V_85 ;
return V_99 ;
}
T_2 F_137 ( T_1 V_260 , T_2 V_85 ,
T_2 * V_381 , T_2 * V_382 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_385 ;
V_43 . V_31 . V_265 . V_262 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_381 )
* V_381 = ( T_2 ) V_44 . V_31 . V_265 . V_262 ;
if ( V_382 )
* V_382 = ( T_2 ) V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
T_2 F_138 ( T_1 V_260 , T_2 * V_386 ,
T_2 * V_380 )
{
T_1 V_387 = 0 ;
T_1 V_388 = 0 ;
T_2 error = 0 ;
error = F_130 ( V_260 , V_389 ,
& V_388 , & V_387 ) ;
if ( V_386 )
* V_386 = ( T_2 ) V_387 ;
if ( V_380 )
* V_380 = ( T_2 ) V_388 ;
return error ;
}
T_2 F_139 ( T_1 V_260 , T_2 V_378 )
{
return F_74 ( V_260 , V_389 ,
V_378 , 0 ) ;
}
T_2 F_140 ( T_1 V_260 , T_2 V_85 , T_2 * V_390 ,
T_1 * V_391 , short * V_392 , short * V_393 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_394 ;
V_43 . V_31 . V_265 . V_263 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_391 )
* V_391 = V_44 . V_31 . V_265 . V_262 ;
if ( V_390 )
* V_390 = ( T_2 ) ( V_44 . V_31 . V_265 . V_263 >> 16 ) ;
if ( V_392 )
* V_392 = V_44 . V_31 . V_265 . V_269 [ 1 ] ;
if ( V_393 )
* V_393 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
return V_44 . error ;
}
T_2 F_141 ( T_1 V_260 , T_2 V_85 , T_2 type ,
T_1 V_395 , short V_396 , short V_397 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_262 = V_395 ;
V_43 . V_31 . V_265 . V_263 = ( V_85 & 0xFFFFL ) + ( ( T_1 ) type << 16 ) ;
V_43 . V_31 . V_265 . V_269 [ 0 ] = V_397 ;
V_43 . V_31 . V_265 . V_269 [ 1 ] = V_396 ;
V_43 . V_31 . V_265 . V_266 = V_394 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_142 ( T_1 V_260 , T_2 V_85 , short V_398 [ 5 ]
)
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_399 ;
V_43 . V_31 . V_265 . V_263 = V_85 ;
F_9 ( & V_43 , & V_44 ) ;
V_398 [ 0 ] = ( short ) V_44 . V_31 . V_265 . V_269 [ 0 ] ;
V_398 [ 1 ] = ( short ) V_44 . V_31 . V_265 . V_269 [ 1 ] ;
V_398 [ 2 ] = ( short ) V_44 . V_31 . V_265 . V_262 ;
V_398 [ 3 ] = ( short ) ( V_44 . V_31 . V_265 . V_262 >> 16 ) ;
V_398 [ 4 ] = ( short ) V_44 . V_31 . V_265 . V_263 ;
return V_44 . error ;
}
T_2 F_143 ( const T_1 V_400 , const T_1 V_85 ,
T_2 * V_401 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_400 , V_402 , V_85 , 0 ,
& V_287 ) ;
* V_401 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_144 ( T_1 V_260 , T_2 V_403 )
{
return F_74 ( V_260 , V_402 ,
V_403 , 0 ) ;
}
T_2 F_145 ( T_1 V_260 , T_2 * V_401 )
{
T_2 V_99 = 0 ;
T_1 V_403 = 0 ;
V_99 = F_83 ( V_260 , V_402 ,
& V_403 ) ;
if ( ! V_99 )
if ( V_401 )
* V_401 = ( T_2 ) V_403 ;
return V_99 ;
}
T_2 F_146 ( const T_1 V_400 , const T_1 V_85 ,
const T_1 V_403 , T_2 * V_404 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_400 , V_405 , V_85 ,
V_403 , & V_287 ) ;
* V_404 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_147 ( T_1 V_260 , T_2 V_406 )
{
return F_74 ( V_260 , V_405 ,
V_406 , 0 ) ;
}
T_2 F_148 ( T_1 V_260 , T_2 * V_404 )
{
T_2 V_99 = 0 ;
T_1 V_406 = 0 ;
V_99 = F_83 ( V_260 , V_405 ,
& V_406 ) ;
if ( ! V_99 )
if ( V_404 )
* V_404 = ( T_2 ) V_406 ;
return V_99 ;
}
T_2 F_149 ( const T_1 V_400 , const T_1 V_85 ,
T_1 * V_407 )
{
T_2 V_99 ;
V_99 = F_78 ( V_400 , V_408 ,
V_85 , 0 , V_407 ) ;
return V_99 ;
}
T_2 F_150 ( T_1 V_260 , T_1 V_22 )
{
return F_74 ( V_260 ,
V_408 , V_22 , 0 ) ;
}
T_2 F_151 ( T_1 V_260 , T_1 * V_289 )
{
T_2 V_99 = 0 ;
T_1 V_22 = 0 ;
V_99 = F_83 ( V_260 ,
V_408 , & V_22 ) ;
if ( ! V_99 )
if ( V_289 )
* V_289 = V_22 ;
return V_99 ;
}
T_2 F_152 ( T_1 V_260 , T_1 * V_289 )
{
T_2 V_99 = 0 ;
T_1 V_22 = 0 ;
V_99 = F_83 ( V_260 , V_409 ,
& V_22 ) ;
if ( ! V_99 )
if ( V_289 )
* V_289 = V_22 ;
return V_99 ;
}
T_2 F_153 ( T_1 V_260 , T_1 V_346 )
{
return F_74 ( V_260 , V_410 , V_346 ,
0 ) ;
}
T_2 F_154 ( T_1 V_260 , T_1 * V_411 )
{
return F_83 ( V_260 , V_410 ,
V_411 ) ;
}
T_2 F_155 ( T_1 V_260 , T_1 V_412 )
{
return F_74 ( V_260 , V_413 ,
V_412 , 0 ) ;
}
T_2 F_156 ( T_1 V_260 , T_1 * V_414 )
{
return F_83 ( V_260 , V_413 ,
V_414 ) ;
}
T_2 F_157 ( T_1 V_260 , T_1 V_85 , T_1 * V_415 )
{
return F_76 ( V_260 , V_416 ,
V_85 , 0 , V_415 , NULL ) ;
}
T_2 F_158 ( T_1 V_260 , T_1 * V_35 )
{
return F_83 ( V_260 , V_417 ,
V_35 ) ;
}
T_2 F_159 ( T_1 V_260 , T_1 V_346 )
{
return F_74 ( V_260 , V_347 , V_346 ,
0 ) ;
}
T_2 F_160 ( T_1 V_260 , T_1 * V_346 )
{
return F_83 ( V_260 , V_347 , V_346 ) ;
}
T_2 F_161 ( T_1 V_260 , T_1 V_418 )
{
return F_74 ( V_260 , V_419 ,
( T_1 ) V_418 , 0 ) ;
}
T_2 F_162 ( T_1 V_260 , T_1 * V_418 )
{
return F_83 ( V_260 , V_419 ,
V_418 ) ;
}
T_2 F_163 ( T_1 V_260 , int V_420 )
{
return F_74 ( V_260 , V_421 ,
( T_1 ) V_420 , 0 ) ;
}
T_2 F_164 ( T_1 V_260 , int * V_420 )
{
return F_83 ( V_260 , V_421 ,
( T_1 * ) V_420 ) ;
}
T_2 F_165 ( T_1 V_260 , T_1 * V_35 )
{
return F_83 ( V_260 , V_422 ,
V_35 ) ;
}
T_2 F_166 ( T_1 V_260 , T_1 V_346 )
{
return F_74 ( V_260 , V_347 , V_346 ,
0 ) ;
}
T_2 F_167 ( T_1 V_260 , T_1 * V_346 )
{
return F_83 ( V_260 , V_347 , V_346 ) ;
}
T_2 F_168 ( T_1 V_260 , T_1 V_418 )
{
return F_74 ( V_260 , V_419 ,
V_418 , 0 ) ;
}
T_2 F_169 ( T_1 V_260 , T_1 * V_418 )
{
return F_83 ( V_260 , V_419 ,
V_418 ) ;
}
T_2 F_170 ( T_1 V_260 , T_1 V_423 )
{
return F_74 ( V_260 , V_424 ,
V_423 , 0 ) ;
}
T_2 F_171 ( T_1 V_260 , T_1 * V_423 )
{
return F_83 ( V_260 , V_424 ,
V_423 ) ;
}
T_2 F_172 ( T_1 V_260 , int V_420 )
{
return F_74 ( V_260 , V_425 ,
V_420 , 0 ) ;
}
T_2 F_173 ( T_1 V_260 , int * V_420 )
{
return F_83 ( V_260 ,
V_425 , ( T_1 * ) V_420 ) ;
}
T_2 F_174 ( const T_1 V_426 , const T_1 V_85 , T_2 * V_427 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_426 , V_428 , V_85 , 0 , & V_287 ) ;
* V_427 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_175 ( T_1 V_260 , T_2 V_429 )
{
return F_74 ( V_260 , V_428 , V_429 , 0 ) ;
}
T_2 F_176 ( T_1 V_260 , T_2 * V_427 )
{
T_1 V_429 = 0 ;
T_2 error = 0 ;
error = F_83 ( V_260 , V_428 , & V_429 ) ;
if ( V_427 )
* V_427 = ( T_2 ) V_429 ;
return error ;
}
T_2 F_177 ( const T_1 V_426 , const T_1 V_85 ,
const T_2 V_429 , T_1 * V_430 )
{
return F_78 ( V_426 , V_431 , V_85 , V_429 , V_430 ) ;
}
T_2 F_178 ( T_1 V_260 , T_1 V_432 )
{
return F_74 ( V_260 , V_431 , V_432 ,
0 ) ;
}
T_2 F_179 ( T_1 V_260 , T_1 * V_433 )
{
return F_83 ( V_260 , V_431 ,
V_433 ) ;
}
T_2 F_180 ( const T_1 V_426 , const T_1 V_85 , T_2 * V_434 )
{
T_1 V_287 ;
T_2 V_99 ;
V_99 = F_78 ( V_426 , V_428 , V_85 , 0 , & V_287 ) ;
* V_434 = ( T_2 ) V_287 ;
return V_99 ;
}
T_2 F_181 ( T_1 V_260 , short V_435 )
{
return F_74 ( V_260 , V_436 , V_435 , 0 ) ;
}
T_2 F_182 ( T_1 V_260 , short * V_437 )
{
T_1 V_435 = 0 ;
T_2 error = 0 ;
error = F_83 ( V_260 , V_436 , & V_435 ) ;
if ( V_437 )
* V_437 = ( T_2 ) V_435 ;
return error ;
}
T_2 F_183 ( T_1 V_260 , short * V_438 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_281 . V_266 = V_439 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_438 )
* V_438 = V_44 . V_31 . V_281 . V_440 . V_441 ;
return V_44 . error ;
}
T_2 F_184 ( T_1 V_260 , short * V_438 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_281 . V_266 = V_442 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_438 )
* V_438 = V_44 . V_31 . V_281 . V_440 . V_441 ;
return V_44 . error ;
}
T_2 F_185 ( const T_1 V_426 , const T_1 V_85 ,
const T_2 V_429 , T_1 * V_443 )
{
return F_78 ( V_426 , V_444 , V_85 , V_429 ,
V_443 ) ;
}
T_2 F_186 ( T_1 V_260 , T_1 V_445 )
{
return F_74 ( V_260 , V_444 ,
V_445 , 0 ) ;
}
T_2 F_187 ( T_1 V_260 , T_1 * V_443 )
{
return F_83 ( V_260 , V_444 ,
V_443 ) ;
}
T_2 F_188 ( const T_1 V_426 , T_1 * V_446 )
{
return F_78 ( V_426 , V_447 , 0 , 0 ,
V_446 ) ;
}
T_2 F_189 ( T_1 V_260 , T_1 V_448 )
{
return F_74 ( V_260 , V_447 , V_448 ,
0 ) ;
}
T_2 F_190 ( T_1 V_260 , T_1 * V_449 )
{
return F_83 ( V_260 , V_447 , V_449 ) ;
}
T_2 F_191 ( T_1 V_260 , char * V_450 ,
const T_1 V_451 )
{
return F_79 ( V_260 ,
V_452 , V_450 , V_451 ) ;
}
T_2 F_192 ( T_1 V_260 , char * V_453 ,
const T_1 V_451 )
{
return F_79 ( V_260 ,
V_454 , V_453 , V_451 ) ;
}
T_2 F_193 ( T_1 V_260 , T_2 * V_455 , T_2 * V_456 )
{
T_1 V_334 = 0 ;
T_2 error = 0 ;
error = F_83 ( V_260 , V_457 , & V_334 ) ;
if ( V_456 ) {
if ( ! error ) {
* V_455 = ( T_2 ) ( V_334 >> 16 ) ;
* V_456 = ( T_2 ) ( V_334 & 0xFFFF ) ;
} else {
* V_455 = 0 ;
* V_456 = 0 ;
}
}
return error ;
}
T_2 F_194 ( T_1 V_260 , T_1 V_65 , T_1 V_458 )
{
return F_74 ( V_260 , V_459 , V_65 , V_458 ) ;
}
T_2 F_195 ( T_1 V_260 , T_1 V_65 , T_1 * V_460 )
{
return F_76 ( V_260 , V_459 , V_65 , 0 ,
V_460 , NULL ) ;
}
T_2 F_196 ( T_1 V_260 , T_1 * V_461 )
{
return F_83 ( V_260 ,
V_462 , V_461 ) ;
}
T_2 F_197 ( T_1 V_260 , T_1 * V_463 )
{
return F_83 ( V_260 , V_464 ,
V_463 ) ;
}
T_2 F_198 ( T_1 V_260 , const T_1 V_465 )
{
return F_74 ( V_260 , V_464 ,
V_465 , 0 ) ;
}
T_2 F_199 ( T_1 V_260 , char * V_466 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_467 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_466 ) {
* ( T_1 * ) & V_466 [ 0 ] = V_44 . V_31 . V_281 . V_440 . V_468 . V_48 [ 0 ] ;
* ( T_1 * ) & V_466 [ 4 ] = V_44 . V_31 . V_281 . V_440 . V_468 . V_48 [ 1 ] ;
* ( T_1 * ) & V_466 [ 8 ] = V_44 . V_31 . V_281 . V_440 . V_468 . V_469 ;
}
return V_44 . error ;
}
T_2 F_200 ( T_1 V_260 , char * V_275 ,
const T_1 V_470 )
{
return F_79 ( V_260 , V_471 ,
V_275 , V_470 ) ;
}
T_2 F_201 ( T_1 V_260 , char * V_275 , const T_1 V_470 )
{
return F_79 ( V_260 , V_472 , V_275 ,
V_470 ) ;
}
T_2 F_202 ( T_1 V_260 , char * V_275 , const T_1 V_470 )
{
return F_79 ( V_260 , V_473 , V_275 ,
V_470 ) ;
}
T_2 F_203 ( T_1 V_260 , char * V_275 ,
const T_1 V_470 )
{
return F_79 ( V_260 , V_474 , V_275 ,
V_470 ) ;
}
T_2 F_204 ( T_1 V_260 , T_1 * V_475 )
{
return F_83 ( V_260 , V_476 , V_475 ) ;
}
T_2 F_205 ( T_1 V_260 , T_1 * V_477 )
{
return F_83 ( V_260 , V_478 , V_477 ) ;
}
T_2 F_206 ( const T_1 V_479 , T_1 * V_366 )
{
return F_78 ( V_479 , V_480 , 0 , 0 ,
V_366 ) ;
}
T_2 F_207 ( T_1 V_260 , short V_481 [ V_363 ]
)
{
return F_75 ( V_260 , V_482 ,
V_481 [ 0 ] , V_481 [ 1 ] ) ;
}
T_2 F_208 ( T_1 V_260 , short V_481 [ V_363 ]
)
{
return F_77 ( V_260 , V_482 ,
& V_481 [ 0 ] , & V_481 [ 1 ] ) ;
}
T_2 F_209 ( T_1 V_260 , T_1 V_483 )
{
return F_74 ( V_260 , V_484 , V_483 , 0 ) ;
}
T_2 F_210 ( T_1 V_260 , T_1 * V_483 )
{
return F_83 ( V_260 , V_484 , V_483 ) ;
}
T_2 F_211 ( T_1 V_260 , short * V_358 ,
short * V_359 , short * V_360 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_485 ;
F_9 ( & V_43 , & V_44 ) ;
if ( V_44 . error ) {
V_44 . V_31 . V_265 . V_269 [ 0 ] = 0 ;
V_44 . V_31 . V_265 . V_269 [ 1 ] = 0 ;
V_44 . V_31 . V_265 . V_262 = 0 ;
}
if ( V_358 )
* V_358 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
if ( V_359 )
* V_359 = V_44 . V_31 . V_265 . V_269 [ 1 ] ;
if ( V_360 )
* V_360 = ( short ) V_44 . V_31 . V_265 . V_262 ;
return V_44 . error ;
}
T_2 F_212 ( T_1 V_260 ,
short V_486 [ V_363 ] , T_1 V_487 ,
T_2 V_488 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
memcpy ( V_43 . V_31 . V_265 . V_269 , V_486 ,
sizeof( short ) * V_363 ) ;
V_43 . V_31 . V_265 . V_266 = V_489 ;
V_43 . V_31 . V_265 . V_262 = V_487 ;
V_43 . V_31 . V_265 . V_263 = V_488 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_213 ( T_1 V_260 ,
short V_486 [ V_363 ] , T_1 V_487 )
{
return F_212 ( V_260 , V_486 ,
V_487 , V_490 ) ;
}
T_2 F_214 ( T_1 V_260 , short V_362 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_264 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_491 ;
V_43 . V_31 . V_265 . V_269 [ 0 ] = V_362 ;
F_9 ( & V_43 , & V_44 ) ;
return V_44 . error ;
}
T_2 F_215 ( T_1 V_260 , short * V_362 )
{
struct V_40 V_43 ;
struct V_41 V_44 ;
F_11 ( & V_43 , & V_44 , V_243 ,
V_272 ) ;
if ( F_2 ( V_260 , & V_43 . V_2 , & V_43 . V_10 ) )
return V_15 ;
V_43 . V_31 . V_265 . V_266 = V_491 ;
F_9 ( & V_43 , & V_44 ) ;
* V_362 = V_44 . V_31 . V_265 . V_269 [ 0 ] ;
return V_44 . error ;
}
