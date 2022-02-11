static int F_1 ( T_1 V_1 )
{
int V_2 = 4 ;
if ( V_1 & V_3 )
V_2 += 4 ;
if ( V_1 & V_4 )
V_2 += 4 ;
if ( V_1 & V_5 )
V_2 += 4 ;
return V_2 ;
}
static T_1 F_2 ( T_1 V_6 )
{
T_1 V_7 = 0 ;
if ( V_6 & V_8 )
V_7 |= V_3 ;
if ( V_6 & V_9 )
V_7 |= V_10 ;
if ( V_6 & V_11 )
V_7 |= V_4 ;
if ( V_6 & V_12 )
V_7 |= V_5 ;
if ( V_6 & V_13 )
V_7 |= V_14 ;
if ( V_6 & V_15 )
V_7 |= V_16 ;
if ( V_6 & V_17 )
V_7 |= V_18 ;
return V_7 ;
}
static T_1 F_3 ( T_1 V_7 )
{
T_1 V_6 = 0 ;
if ( V_7 & V_3 )
V_6 |= V_8 ;
if ( V_7 & V_10 )
V_6 |= V_9 ;
if ( V_7 & V_4 )
V_6 |= V_11 ;
if ( V_7 & V_5 )
V_6 |= V_12 ;
if ( V_7 & V_14 )
V_6 |= V_13 ;
if ( V_7 & V_16 )
V_6 |= V_15 ;
if ( V_7 & V_18 )
V_6 |= V_17 ;
return V_6 ;
}
static int F_4 ( struct V_19 * V_20 , struct V_21 * V_22 ,
bool * V_23 )
{
const struct V_24 * V_25 ;
T_2 * V_26 ;
int V_27 ;
if ( F_5 ( ! F_6 ( V_20 , sizeof( struct V_24 ) ) ) )
return - V_28 ;
V_25 = (struct V_24 * ) F_7 ( V_20 ) ;
if ( F_5 ( V_25 -> V_6 & ( V_17 | V_9 ) ) )
return - V_28 ;
V_22 -> V_6 = F_2 ( V_25 -> V_6 ) ;
V_27 = F_1 ( V_22 -> V_6 ) ;
if ( ! F_6 ( V_20 , V_27 ) )
return - V_28 ;
V_25 = (struct V_24 * ) F_7 ( V_20 ) ;
V_22 -> V_29 = V_25 -> V_30 ;
V_26 = ( T_2 * ) ( V_25 + 1 ) ;
if ( V_25 -> V_6 & V_8 ) {
if ( F_8 ( V_20 ) ) {
* V_23 = true ;
return - V_28 ;
}
F_9 ( V_20 , V_31 , 0 ,
V_32 ) ;
V_26 ++ ;
}
if ( V_25 -> V_6 & V_11 ) {
V_22 -> V_33 = * V_26 ;
V_26 ++ ;
} else {
V_22 -> V_33 = 0 ;
}
if ( F_5 ( V_25 -> V_6 & V_12 ) ) {
V_22 -> V_34 = * V_26 ;
V_26 ++ ;
} else {
V_22 -> V_34 = 0 ;
}
if ( V_25 -> V_6 == 0 && V_22 -> V_29 == F_10 ( V_35 ) ) {
V_22 -> V_29 = F_10 ( V_36 ) ;
if ( ( * ( V_37 * ) V_26 & 0xF0 ) != 0x40 ) {
V_27 += 4 ;
if ( ! F_6 ( V_20 , V_27 ) )
return - V_28 ;
}
}
return V_27 ;
}
static void F_11 ( struct V_19 * V_20 , T_3 V_38 ,
const struct V_21 * V_22 )
{
struct V_39 * V_39 = F_12 ( V_20 -> V_40 ) ;
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
const int type = F_13 ( V_20 ) -> type ;
const int V_45 = F_13 ( V_20 ) -> V_45 ;
struct V_46 * V_47 ;
switch ( type ) {
default:
case V_48 :
return;
case V_49 :
switch ( V_45 ) {
case V_50 :
case V_51 :
return;
default:
break;
}
break;
case V_52 :
if ( V_45 != V_53 )
return;
break;
case V_54 :
break;
}
if ( V_22 -> V_29 == F_10 ( V_55 ) )
V_42 = F_14 ( V_39 , V_56 ) ;
else
V_42 = F_14 ( V_39 , V_57 ) ;
V_44 = ( const struct V_43 * ) ( F_13 ( V_20 ) + 1 ) ;
V_47 = F_15 ( V_42 , V_20 -> V_40 -> V_58 , V_22 -> V_6 ,
V_44 -> V_59 , V_44 -> V_60 , V_22 -> V_33 ) ;
if ( ! V_47 )
return;
if ( V_47 -> V_61 . V_44 . V_59 == 0 ||
F_16 ( V_47 -> V_61 . V_44 . V_59 ) )
return;
if ( V_47 -> V_61 . V_44 . V_62 == 0 && type == V_52 )
return;
if ( F_17 ( V_63 , V_47 -> V_64 + V_65 ) )
V_47 -> V_66 ++ ;
else
V_47 -> V_66 = 1 ;
V_47 -> V_64 = V_63 ;
}
static void F_18 ( struct V_19 * V_20 , T_3 V_38 )
{
const int type = F_13 ( V_20 ) -> type ;
const int V_45 = F_13 ( V_20 ) -> V_45 ;
struct V_21 V_22 ;
bool V_23 = false ;
if ( F_4 ( V_20 , & V_22 , & V_23 ) < 0 ) {
if ( ! V_23 )
return;
}
if ( type == V_49 && V_45 == V_67 ) {
F_19 ( V_20 , F_12 ( V_20 -> V_40 ) , V_38 ,
V_20 -> V_40 -> V_58 , 0 , V_31 , 0 ) ;
return;
}
if ( type == V_54 ) {
F_20 ( V_20 , F_12 ( V_20 -> V_40 ) , V_20 -> V_40 -> V_58 , 0 ,
V_31 , 0 ) ;
return;
}
F_11 ( V_20 , V_38 , & V_22 ) ;
}
static T_4 F_21 ( T_2 V_33 )
{
#ifdef F_22
return ( V_68 T_4 ) ( ( V_68 T_3 ) V_33 ) ;
#else
return ( V_68 T_4 ) ( ( V_68 V_69 ) V_33 << 32 ) ;
#endif
}
static T_2 F_23 ( T_4 V_70 )
{
#ifdef F_22
return ( V_68 T_2 ) V_70 ;
#else
return ( V_68 T_2 ) ( ( V_68 V_69 ) V_70 >> 32 ) ;
#endif
}
static int F_24 ( struct V_19 * V_20 , const struct V_21 * V_22 )
{
struct V_39 * V_39 = F_12 ( V_20 -> V_40 ) ;
struct V_71 * V_72 = NULL ;
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_46 * V_73 ;
if ( V_22 -> V_29 == F_10 ( V_55 ) )
V_42 = F_14 ( V_39 , V_56 ) ;
else
V_42 = F_14 ( V_39 , V_57 ) ;
V_44 = F_25 ( V_20 ) ;
V_73 = F_15 ( V_42 , V_20 -> V_40 -> V_58 , V_22 -> V_6 ,
V_44 -> V_60 , V_44 -> V_59 , V_22 -> V_33 ) ;
if ( V_73 ) {
if ( V_73 -> V_40 -> type != V_74 )
F_26 ( V_20 ) ;
else
F_27 ( V_20 ) ;
if ( V_73 -> V_75 ) {
T_1 V_6 ;
T_4 V_76 ;
V_6 = V_22 -> V_6 & ( V_3 | V_4 ) ;
V_76 = F_21 ( V_22 -> V_33 ) ;
V_72 = F_28 ( V_20 , V_6 , V_76 , 0 ) ;
if ( ! V_72 )
return V_77 ;
}
F_29 ( V_73 , V_20 , V_22 , V_72 , V_78 ) ;
return V_79 ;
}
return V_77 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_21 V_22 ;
bool V_23 = false ;
int V_27 ;
#ifdef F_31
if ( F_16 ( F_25 ( V_20 ) -> V_59 ) ) {
if ( F_32 ( F_33 ( V_20 ) ) )
goto V_80;
}
#endif
V_27 = F_4 ( V_20 , & V_22 , & V_23 ) ;
if ( V_27 < 0 )
goto V_80;
if ( F_34 ( V_20 , V_27 , V_22 . V_29 , false ) < 0 )
goto V_80;
if ( F_24 ( V_20 , & V_22 ) == V_79 )
return 0 ;
F_35 ( V_20 , V_49 , V_51 , 0 ) ;
V_80:
F_36 ( V_20 ) ;
return 0 ;
}
static T_5 F_37 ( struct V_19 * V_20 )
{
T_6 V_81 ;
if ( V_20 -> V_82 == V_83 )
V_81 = F_38 ( V_20 ) ;
else
V_81 = F_39 ( V_20 , 0 , V_20 -> V_84 , 0 ) ;
return F_40 ( V_81 ) ;
}
static void F_41 ( struct V_19 * V_20 , int V_27 , T_1 V_6 ,
T_1 V_29 , T_2 V_33 , T_2 V_34 )
{
struct V_24 * V_25 ;
F_42 ( V_20 , V_27 ) ;
F_43 ( V_20 ) ;
V_25 = (struct V_24 * ) V_20 -> V_85 ;
V_25 -> V_6 = F_3 ( V_6 ) ;
V_25 -> V_30 = V_29 ;
if ( V_6 & ( V_4 | V_3 | V_5 ) ) {
T_2 * V_86 = ( T_2 * ) ( ( ( V_37 * ) V_25 ) + V_27 - 4 ) ;
if ( V_6 & V_5 ) {
* V_86 = V_34 ;
V_86 -- ;
}
if ( V_6 & V_4 ) {
* V_86 = V_33 ;
V_86 -- ;
}
if ( V_6 & V_3 &&
! ( F_44 ( V_20 ) -> V_87 &
( V_88 | V_89 ) ) ) {
* V_86 = 0 ;
* ( T_5 * ) V_86 = F_37 ( V_20 ) ;
}
}
}
static void F_45 ( struct V_19 * V_20 , struct V_90 * V_40 ,
const struct V_43 * V_91 ,
T_1 V_29 )
{
struct V_46 * V_73 = F_46 ( V_40 ) ;
if ( V_73 -> V_61 . V_1 & V_5 )
V_73 -> V_92 ++ ;
F_41 ( V_20 , V_73 -> V_93 , V_73 -> V_61 . V_1 ,
V_29 , V_73 -> V_61 . V_94 , F_47 ( V_73 -> V_92 ) ) ;
F_48 ( V_20 , V_29 ) ;
F_49 ( V_20 , V_40 , V_91 , V_91 -> V_30 ) ;
}
static struct V_19 * F_50 ( struct V_19 * V_20 ,
bool V_81 )
{
return F_51 ( V_20 , V_81 ? V_89 : V_88 ) ;
}
static struct V_95 * F_52 ( struct V_19 * V_20 ,
struct V_90 * V_40 ,
struct V_96 * V_97 ,
const struct V_98 * V_33 )
{
struct V_39 * V_39 = F_12 ( V_40 ) ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_97 -> V_59 = V_33 -> V_99 . V_100 . V_101 ;
V_97 -> V_60 = V_33 -> V_99 . V_100 . V_102 ;
V_97 -> V_103 = F_53 ( V_33 -> V_104 ) ;
V_97 -> V_105 = V_20 -> V_106 ;
V_97 -> V_107 = V_31 ;
return F_54 ( V_39 , V_97 ) ;
}
static void F_55 ( struct V_19 * V_20 , struct V_90 * V_40 ,
T_1 V_29 )
{
struct V_108 * V_109 ;
const struct V_98 * V_33 ;
struct V_95 * V_110 = NULL ;
struct V_96 V_97 ;
int V_111 ;
int V_112 ;
T_1 V_113 , V_6 ;
bool V_114 ;
int V_115 ;
V_109 = F_56 ( V_20 ) ;
if ( F_5 ( ! V_109 || ! ( V_109 -> V_116 & V_117 ) ||
F_57 ( V_109 ) != V_118 ) )
goto V_119;
V_33 = & V_109 -> V_33 ;
V_114 = F_58 ( V_20 , V_109 ) ;
if ( V_114 )
V_110 = F_59 ( & V_109 -> V_120 , & V_97 . V_60 ) ;
if ( ! V_110 ) {
V_110 = F_52 ( V_20 , V_40 , & V_97 , V_33 ) ;
if ( F_60 ( V_110 ) )
goto V_119;
if ( V_114 )
F_61 ( & V_109 -> V_120 , & V_110 -> V_101 ,
V_97 . V_60 ) ;
}
V_112 = F_1 ( V_33 -> V_121 ) ;
V_111 = F_62 ( V_110 -> V_101 . V_40 ) + V_110 -> V_101 . V_122
+ V_112 + sizeof( struct V_43 ) ;
if ( F_63 ( V_20 ) < V_111 || F_64 ( V_20 ) ) {
int V_123 = F_65 ( V_111 -
F_63 ( V_20 ) +
16 ) ;
V_115 = F_66 ( V_20 , F_67 ( int , V_123 , 0 ) ,
0 , V_124 ) ;
if ( F_5 ( V_115 ) )
goto V_125;
}
V_20 = F_50 ( V_20 , ! ! ( V_109 -> V_33 . V_121 & V_3 ) ) ;
if ( F_60 ( V_20 ) ) {
V_20 = NULL ;
goto V_125;
}
V_6 = V_109 -> V_33 . V_121 & ( V_3 | V_4 ) ;
F_41 ( V_20 , V_112 , V_6 , V_29 ,
F_23 ( V_109 -> V_33 . V_76 ) , 0 ) ;
V_113 = V_33 -> V_121 & V_126 ? F_10 ( V_127 ) : 0 ;
F_68 ( V_20 -> V_128 , V_110 , V_20 , V_97 . V_60 , V_33 -> V_99 . V_100 . V_101 , V_31 ,
V_33 -> V_104 , V_33 -> V_62 , V_113 , false ) ;
return;
V_125:
F_69 ( V_110 ) ;
V_119:
F_36 ( V_20 ) ;
V_40 -> V_129 . V_130 ++ ;
}
static int F_70 ( struct V_90 * V_40 , struct V_19 * V_20 )
{
struct V_108 * V_38 = F_56 ( V_20 ) ;
struct V_95 * V_110 ;
struct V_96 V_131 ;
if ( F_57 ( V_38 ) != V_118 )
return - V_28 ;
V_110 = F_52 ( V_20 , V_40 , & V_131 , & V_38 -> V_33 ) ;
if ( F_60 ( V_110 ) )
return F_71 ( V_110 ) ;
F_69 ( V_110 ) ;
V_38 -> V_33 . V_99 . V_100 . V_102 = V_131 . V_60 ;
return 0 ;
}
static T_7 F_72 ( struct V_19 * V_20 ,
struct V_90 * V_40 )
{
struct V_46 * V_73 = F_46 ( V_40 ) ;
const struct V_43 * V_91 ;
if ( V_73 -> V_75 ) {
F_55 ( V_20 , V_40 , V_20 -> V_30 ) ;
return V_132 ;
}
if ( V_40 -> V_133 ) {
if ( F_73 ( V_20 , V_40 -> V_134 -
( V_73 -> V_135 + sizeof( struct V_43 ) ) ) )
goto V_136;
V_91 = ( const struct V_43 * ) V_20 -> V_85 ;
F_74 ( V_20 , V_73 -> V_135 + sizeof( struct V_43 ) ) ;
F_27 ( V_20 ) ;
} else {
if ( F_73 ( V_20 , V_40 -> V_134 ) )
goto V_136;
V_91 = & V_73 -> V_61 . V_44 ;
}
V_20 = F_50 ( V_20 , ! ! ( V_73 -> V_61 . V_1 & V_3 ) ) ;
if ( F_60 ( V_20 ) )
goto V_137;
F_45 ( V_20 , V_40 , V_91 , V_20 -> V_30 ) ;
return V_132 ;
V_136:
F_36 ( V_20 ) ;
V_137:
V_40 -> V_129 . V_130 ++ ;
return V_132 ;
}
static T_7 F_75 ( struct V_19 * V_20 ,
struct V_90 * V_40 )
{
struct V_46 * V_73 = F_46 ( V_40 ) ;
if ( V_73 -> V_75 ) {
F_55 ( V_20 , V_40 , F_10 ( V_55 ) ) ;
return V_132 ;
}
V_20 = F_50 ( V_20 , ! ! ( V_73 -> V_61 . V_1 & V_3 ) ) ;
if ( F_60 ( V_20 ) )
goto V_137;
if ( F_73 ( V_20 , V_40 -> V_134 ) )
goto V_136;
F_45 ( V_20 , V_40 , & V_73 -> V_61 . V_44 , F_10 ( V_55 ) ) ;
return V_132 ;
V_136:
F_36 ( V_20 ) ;
V_137:
V_40 -> V_129 . V_130 ++ ;
return V_132 ;
}
static int F_76 ( struct V_90 * V_40 ,
struct V_138 * V_139 , int V_140 )
{
int V_115 ;
struct V_141 V_142 ;
if ( F_77 ( & V_142 , V_139 -> V_143 . V_144 , sizeof( V_142 ) ) )
return - V_145 ;
if ( V_140 == V_146 || V_140 == V_147 ) {
if ( V_142 . V_44 . V_148 != 4 || V_142 . V_44 . V_30 != V_31 ||
V_142 . V_44 . V_149 != 5 || ( V_142 . V_44 . V_150 & F_10 ( ~ V_127 ) ) ||
( ( V_142 . V_151 | V_142 . V_1 ) & ( V_17 | V_9 ) ) )
return - V_28 ;
}
V_142 . V_151 = F_2 ( V_142 . V_151 ) ;
V_142 . V_1 = F_2 ( V_142 . V_1 ) ;
V_115 = F_78 ( V_40 , & V_142 , V_140 ) ;
if ( V_115 )
return V_115 ;
V_142 . V_151 = F_3 ( V_142 . V_151 ) ;
V_142 . V_1 = F_3 ( V_142 . V_1 ) ;
if ( F_79 ( V_139 -> V_143 . V_144 , & V_142 , sizeof( V_142 ) ) )
return - V_145 ;
return 0 ;
}
static int F_80 ( struct V_19 * V_20 , struct V_90 * V_40 ,
unsigned short type ,
const void * V_59 , const void * V_60 , unsigned int V_84 )
{
struct V_46 * V_47 = F_46 ( V_40 ) ;
struct V_43 * V_44 ;
struct V_24 * V_25 ;
V_44 = (struct V_43 * ) F_42 ( V_20 , V_47 -> V_135 + sizeof( * V_44 ) ) ;
V_25 = (struct V_24 * ) ( V_44 + 1 ) ;
V_25 -> V_6 = F_3 ( V_47 -> V_61 . V_1 ) ;
V_25 -> V_30 = F_10 ( type ) ;
memcpy ( V_44 , & V_47 -> V_61 . V_44 , sizeof( struct V_43 ) ) ;
if ( V_60 )
memcpy ( & V_44 -> V_60 , V_60 , 4 ) ;
if ( V_59 )
memcpy ( & V_44 -> V_59 , V_59 , 4 ) ;
if ( V_44 -> V_59 )
return V_47 -> V_135 + sizeof( * V_44 ) ;
return - ( V_47 -> V_135 + sizeof( * V_44 ) ) ;
}
static int F_81 ( const struct V_19 * V_20 , unsigned char * V_152 )
{
const struct V_43 * V_44 = ( const struct V_43 * ) F_82 ( V_20 ) ;
memcpy ( V_152 , & V_44 -> V_60 , 4 ) ;
return 4 ;
}
static int F_83 ( struct V_90 * V_40 )
{
struct V_46 * V_47 = F_46 ( V_40 ) ;
if ( F_16 ( V_47 -> V_61 . V_44 . V_59 ) ) {
struct V_96 V_131 ;
struct V_95 * V_110 ;
V_110 = F_84 ( V_47 -> V_39 , & V_131 ,
V_47 -> V_61 . V_44 . V_59 ,
V_47 -> V_61 . V_44 . V_60 ,
V_47 -> V_61 . V_94 ,
F_53 ( V_47 -> V_61 . V_44 . V_104 ) ,
V_47 -> V_61 . V_153 ) ;
if ( F_60 ( V_110 ) )
return - V_154 ;
V_40 = V_110 -> V_101 . V_40 ;
F_69 ( V_110 ) ;
if ( ! F_85 ( V_40 ) )
return - V_154 ;
V_47 -> V_155 = V_40 -> V_58 ;
F_86 ( F_85 ( V_40 ) , V_47 -> V_61 . V_44 . V_59 ) ;
}
return 0 ;
}
static int F_87 ( struct V_90 * V_40 )
{
struct V_46 * V_47 = F_46 ( V_40 ) ;
if ( F_16 ( V_47 -> V_61 . V_44 . V_59 ) && V_47 -> V_155 ) {
struct V_156 * V_157 ;
V_157 = F_88 ( V_47 -> V_39 , V_47 -> V_155 ) ;
if ( V_157 )
F_89 ( V_157 , V_47 -> V_61 . V_44 . V_59 ) ;
}
return 0 ;
}
static void F_90 ( struct V_90 * V_40 )
{
V_40 -> V_158 = & V_159 ;
V_40 -> type = V_160 ;
F_91 ( V_40 , V_57 ) ;
}
static void F_92 ( struct V_90 * V_40 )
{
struct V_46 * V_73 ;
int V_161 ;
V_73 = F_46 ( V_40 ) ;
V_73 -> V_93 = F_1 ( V_73 -> V_61 . V_1 ) ;
V_73 -> V_61 . V_44 . V_30 = V_31 ;
V_73 -> V_135 = V_73 -> V_93 + V_73 -> V_162 ;
V_161 = V_73 -> V_135 + sizeof( struct V_43 ) ;
V_40 -> V_134 = V_163 + V_161 + 4 ;
V_40 -> V_164 = V_165 - V_161 - 4 ;
V_40 -> V_166 |= V_167 ;
V_40 -> V_168 |= V_167 ;
if ( ! ( V_73 -> V_61 . V_1 & V_5 ) ) {
if ( ! ( V_73 -> V_61 . V_1 & V_3 ) ||
( V_73 -> V_169 . type == V_170 ) ) {
V_40 -> V_166 |= V_171 ;
V_40 -> V_168 |= V_171 ;
}
V_40 -> V_166 |= V_172 ;
}
}
static int F_93 ( struct V_90 * V_40 )
{
struct V_46 * V_73 = F_46 ( V_40 ) ;
struct V_43 * V_44 = & V_73 -> V_61 . V_44 ;
F_92 ( V_40 ) ;
memcpy ( V_40 -> V_173 , & V_44 -> V_60 , 4 ) ;
memcpy ( V_40 -> V_174 , & V_44 -> V_59 , 4 ) ;
V_40 -> V_6 = V_175 ;
F_94 ( V_40 ) ;
V_40 -> V_176 = 4 ;
if ( V_44 -> V_59 && ! V_73 -> V_75 ) {
#ifdef F_31
if ( F_16 ( V_44 -> V_59 ) ) {
if ( ! V_44 -> V_60 )
return - V_28 ;
V_40 -> V_6 = V_177 ;
V_40 -> V_133 = & V_178 ;
}
#endif
} else if ( ! V_73 -> V_75 ) {
V_40 -> V_133 = & V_178 ;
}
return F_95 ( V_40 ) ;
}
static int T_8 F_96 ( struct V_39 * V_39 )
{
return F_97 ( V_39 , V_57 , & V_179 , NULL ) ;
}
static void T_9 F_98 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = F_14 ( V_39 , V_57 ) ;
F_99 ( V_42 , & V_179 ) ;
}
static int F_100 ( struct V_180 * V_181 [] , struct V_180 * V_85 [] )
{
T_1 V_6 ;
if ( ! V_85 )
return 0 ;
V_6 = 0 ;
if ( V_85 [ V_182 ] )
V_6 |= F_101 ( V_85 [ V_182 ] ) ;
if ( V_85 [ V_183 ] )
V_6 |= F_101 ( V_85 [ V_183 ] ) ;
if ( V_6 & ( V_17 | V_9 ) )
return - V_28 ;
if ( V_85 [ V_184 ] &&
V_85 [ V_185 ] &&
F_102 ( V_85 [ V_185 ] ) != V_170 )
return - V_28 ;
return 0 ;
}
static int F_103 ( struct V_180 * V_181 [] , struct V_180 * V_85 [] )
{
T_2 V_59 ;
if ( V_181 [ V_186 ] ) {
if ( F_104 ( V_181 [ V_186 ] ) != V_187 )
return - V_28 ;
if ( ! F_105 ( F_106 ( V_181 [ V_186 ] ) ) )
return - V_154 ;
}
if ( ! V_85 )
goto V_137;
if ( V_85 [ V_188 ] ) {
memcpy ( & V_59 , F_106 ( V_85 [ V_188 ] ) , 4 ) ;
if ( ! V_59 )
return - V_28 ;
}
V_137:
return F_100 ( V_181 , V_85 ) ;
}
static void F_107 ( struct V_90 * V_40 ,
struct V_180 * V_85 [] ,
struct V_180 * V_181 [] ,
struct V_141 * V_61 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_44 . V_30 = V_31 ;
if ( ! V_85 )
return;
if ( V_85 [ V_189 ] )
V_61 -> V_153 = F_108 ( V_85 [ V_189 ] ) ;
if ( V_85 [ V_182 ] )
V_61 -> V_151 = F_2 ( F_101 ( V_85 [ V_182 ] ) ) ;
if ( V_85 [ V_183 ] )
V_61 -> V_1 = F_2 ( F_101 ( V_85 [ V_183 ] ) ) ;
if ( V_85 [ V_190 ] )
V_61 -> V_191 = F_109 ( V_85 [ V_190 ] ) ;
if ( V_85 [ V_192 ] )
V_61 -> V_94 = F_109 ( V_85 [ V_192 ] ) ;
if ( V_85 [ V_193 ] )
V_61 -> V_44 . V_60 = F_110 ( V_85 [ V_193 ] ) ;
if ( V_85 [ V_188 ] )
V_61 -> V_44 . V_59 = F_110 ( V_85 [ V_188 ] ) ;
if ( V_85 [ V_194 ] )
V_61 -> V_44 . V_62 = F_111 ( V_85 [ V_194 ] ) ;
if ( V_85 [ V_195 ] )
V_61 -> V_44 . V_104 = F_111 ( V_85 [ V_195 ] ) ;
if ( ! V_85 [ V_196 ] || F_111 ( V_85 [ V_196 ] ) )
V_61 -> V_44 . V_150 = F_10 ( V_127 ) ;
if ( V_85 [ V_184 ] ) {
struct V_46 * V_47 = F_46 ( V_40 ) ;
V_47 -> V_75 = true ;
if ( V_40 -> type == V_160 )
V_40 -> type = V_74 ;
}
}
static bool F_112 ( struct V_180 * V_85 [] ,
struct V_197 * V_198 )
{
bool V_199 = false ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
if ( ! V_85 )
return V_199 ;
if ( V_85 [ V_185 ] ) {
V_199 = true ;
V_198 -> type = F_102 ( V_85 [ V_185 ] ) ;
}
if ( V_85 [ V_200 ] ) {
V_199 = true ;
V_198 -> V_6 = F_102 ( V_85 [ V_200 ] ) ;
}
if ( V_85 [ V_201 ] ) {
V_199 = true ;
V_198 -> V_202 = F_101 ( V_85 [ V_201 ] ) ;
}
if ( V_85 [ V_203 ] ) {
V_199 = true ;
V_198 -> V_204 = F_101 ( V_85 [ V_203 ] ) ;
}
return V_199 ;
}
static int F_113 ( struct V_90 * V_40 )
{
F_92 ( V_40 ) ;
V_40 -> V_205 |= V_206 ;
return F_95 ( V_40 ) ;
}
static void F_114 ( struct V_90 * V_40 )
{
F_115 ( V_40 ) ;
V_40 -> V_158 = & V_207 ;
V_40 -> V_205 &= ~ V_208 ;
V_40 -> V_205 |= V_206 ;
F_91 ( V_40 , V_56 ) ;
}
static int F_116 ( struct V_39 * V_209 , struct V_90 * V_40 ,
struct V_180 * V_181 [] , struct V_180 * V_85 [] )
{
struct V_141 V_142 ;
struct V_197 V_198 ;
if ( F_112 ( V_85 , & V_198 ) ) {
struct V_46 * V_47 = F_46 ( V_40 ) ;
int V_115 = F_117 ( V_47 , & V_198 ) ;
if ( V_115 < 0 )
return V_115 ;
}
F_107 ( V_40 , V_85 , V_181 , & V_142 ) ;
return F_118 ( V_40 , V_181 , & V_142 ) ;
}
static int F_119 ( struct V_90 * V_40 , struct V_180 * V_181 [] ,
struct V_180 * V_85 [] )
{
struct V_141 V_142 ;
struct V_197 V_198 ;
if ( F_112 ( V_85 , & V_198 ) ) {
struct V_46 * V_47 = F_46 ( V_40 ) ;
int V_115 = F_117 ( V_47 , & V_198 ) ;
if ( V_115 < 0 )
return V_115 ;
}
F_107 ( V_40 , V_85 , V_181 , & V_142 ) ;
return F_120 ( V_40 , V_181 , & V_142 ) ;
}
static T_10 F_121 ( const struct V_90 * V_40 )
{
return
F_122 ( 4 ) +
F_122 ( 2 ) +
F_122 ( 2 ) +
F_122 ( 4 ) +
F_122 ( 4 ) +
F_122 ( 4 ) +
F_122 ( 4 ) +
F_122 ( 1 ) +
F_122 ( 1 ) +
F_122 ( 1 ) +
F_122 ( 2 ) +
F_122 ( 2 ) +
F_122 ( 2 ) +
F_122 ( 2 ) +
F_122 ( 0 ) +
0 ;
}
static int F_123 ( struct V_19 * V_20 , const struct V_90 * V_40 )
{
struct V_46 * V_47 = F_46 ( V_40 ) ;
struct V_141 * V_142 = & V_47 -> V_61 ;
if ( F_124 ( V_20 , V_189 , V_142 -> V_153 ) ||
F_125 ( V_20 , V_182 , F_3 ( V_142 -> V_151 ) ) ||
F_125 ( V_20 , V_183 , F_3 ( V_142 -> V_1 ) ) ||
F_126 ( V_20 , V_190 , V_142 -> V_191 ) ||
F_126 ( V_20 , V_192 , V_142 -> V_94 ) ||
F_127 ( V_20 , V_193 , V_142 -> V_44 . V_60 ) ||
F_127 ( V_20 , V_188 , V_142 -> V_44 . V_59 ) ||
F_128 ( V_20 , V_194 , V_142 -> V_44 . V_62 ) ||
F_128 ( V_20 , V_195 , V_142 -> V_44 . V_104 ) ||
F_128 ( V_20 , V_196 ,
! ! ( V_142 -> V_44 . V_150 & F_10 ( V_127 ) ) ) )
goto V_210;
if ( F_129 ( V_20 , V_185 ,
V_47 -> V_169 . type ) ||
F_125 ( V_20 , V_201 ,
V_47 -> V_169 . V_202 ) ||
F_125 ( V_20 , V_203 ,
V_47 -> V_169 . V_204 ) ||
F_129 ( V_20 , V_200 ,
V_47 -> V_169 . V_6 ) )
goto V_210;
if ( V_47 -> V_75 ) {
if ( F_130 ( V_20 , V_184 ) )
goto V_210;
}
return 0 ;
V_210:
return - V_211 ;
}
struct V_90 * F_131 ( struct V_39 * V_39 , const char * V_212 ,
V_37 V_213 )
{
struct V_180 * V_181 [ V_214 + 1 ] ;
struct V_90 * V_40 ;
struct V_46 * V_47 ;
int V_115 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_40 = F_132 ( V_39 , V_212 , V_213 ,
& V_215 , V_181 ) ;
if ( F_60 ( V_40 ) )
return V_40 ;
V_47 = F_46 ( V_40 ) ;
V_47 -> V_75 = true ;
V_115 = F_116 ( V_39 , V_40 , V_181 , NULL ) ;
if ( V_115 < 0 )
goto V_137;
V_115 = F_133 ( V_40 , V_216 , false ) ;
if ( V_115 )
goto V_137;
return V_40 ;
V_137:
F_134 ( V_40 ) ;
return F_135 ( V_115 ) ;
}
static int T_8 F_136 ( struct V_39 * V_39 )
{
return F_97 ( V_39 , V_56 , & V_215 , L_1 ) ;
}
static void T_9 F_137 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = F_14 ( V_39 , V_56 ) ;
F_99 ( V_42 , & V_215 ) ;
}
static int T_11 F_138 ( void )
{
int V_115 ;
F_139 ( L_2 ) ;
V_115 = F_140 ( & V_217 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_140 ( & V_218 ) ;
if ( V_115 < 0 )
goto V_219;
V_115 = F_141 ( & V_220 , V_221 ) ;
if ( V_115 < 0 ) {
F_139 ( L_3 , V_222 ) ;
goto V_223;
}
V_115 = F_142 ( & V_179 ) ;
if ( V_115 < 0 )
goto V_224;
V_115 = F_142 ( & V_215 ) ;
if ( V_115 < 0 )
goto V_225;
return 0 ;
V_225:
F_143 ( & V_179 ) ;
V_224:
F_144 ( & V_220 , V_221 ) ;
V_223:
F_145 ( & V_218 ) ;
V_219:
F_145 ( & V_217 ) ;
return V_115 ;
}
static void T_12 F_146 ( void )
{
F_143 ( & V_215 ) ;
F_143 ( & V_179 ) ;
F_144 ( & V_220 , V_221 ) ;
F_145 ( & V_218 ) ;
F_145 ( & V_217 ) ;
}
