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
return F_11 ( V_20 , V_27 , V_22 -> V_29 ) ;
}
static void F_12 ( struct V_19 * V_20 , T_3 V_38 ,
const struct V_21 * V_22 )
{
struct V_39 * V_39 = F_13 ( V_20 -> V_40 ) ;
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
const int type = F_14 ( V_20 ) -> type ;
const int V_45 = F_14 ( V_20 ) -> V_45 ;
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
V_42 = F_15 ( V_39 , V_56 ) ;
else
V_42 = F_15 ( V_39 , V_57 ) ;
V_44 = ( const struct V_43 * ) ( F_14 ( V_20 ) + 1 ) ;
V_47 = F_16 ( V_42 , V_20 -> V_40 -> V_58 , V_22 -> V_6 ,
V_44 -> V_59 , V_44 -> V_60 , V_22 -> V_33 ) ;
if ( ! V_47 )
return;
if ( V_47 -> V_61 . V_44 . V_59 == 0 ||
F_17 ( V_47 -> V_61 . V_44 . V_59 ) )
return;
if ( V_47 -> V_61 . V_44 . V_62 == 0 && type == V_52 )
return;
if ( F_18 ( V_63 , V_47 -> V_64 + V_65 ) )
V_47 -> V_66 ++ ;
else
V_47 -> V_66 = 1 ;
V_47 -> V_64 = V_63 ;
}
static void F_19 ( struct V_19 * V_20 , T_3 V_38 )
{
const int type = F_14 ( V_20 ) -> type ;
const int V_45 = F_14 ( V_20 ) -> V_45 ;
struct V_21 V_22 ;
bool V_23 = false ;
if ( F_4 ( V_20 , & V_22 , & V_23 ) ) {
if ( ! V_23 )
return;
}
if ( type == V_49 && V_45 == V_67 ) {
F_20 ( V_20 , F_13 ( V_20 -> V_40 ) , V_38 ,
V_20 -> V_40 -> V_58 , 0 , V_31 , 0 ) ;
return;
}
if ( type == V_54 ) {
F_21 ( V_20 , F_13 ( V_20 -> V_40 ) , V_20 -> V_40 -> V_58 , 0 ,
V_31 , 0 ) ;
return;
}
F_12 ( V_20 , V_38 , & V_22 ) ;
}
static T_4 F_22 ( T_2 V_33 )
{
#ifdef F_23
return ( V_68 T_4 ) ( ( V_68 T_3 ) V_33 ) ;
#else
return ( V_68 T_4 ) ( ( V_68 V_69 ) V_33 << 32 ) ;
#endif
}
static T_2 F_24 ( T_4 V_70 )
{
#ifdef F_23
return ( V_68 T_2 ) V_70 ;
#else
return ( V_68 T_2 ) ( ( V_68 V_69 ) V_70 >> 32 ) ;
#endif
}
static int F_25 ( struct V_19 * V_20 , const struct V_21 * V_22 )
{
struct V_39 * V_39 = F_13 ( V_20 -> V_40 ) ;
struct V_71 * V_72 = NULL ;
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_46 * V_73 ;
if ( V_22 -> V_29 == F_10 ( V_55 ) )
V_42 = F_15 ( V_39 , V_56 ) ;
else
V_42 = F_15 ( V_39 , V_57 ) ;
V_44 = F_26 ( V_20 ) ;
V_73 = F_16 ( V_42 , V_20 -> V_40 -> V_58 , V_22 -> V_6 ,
V_44 -> V_60 , V_44 -> V_59 , V_22 -> V_33 ) ;
if ( V_73 ) {
F_27 ( V_20 ) ;
if ( V_73 -> V_74 ) {
T_1 V_6 ;
T_4 V_75 ;
V_6 = V_22 -> V_6 & ( V_3 | V_4 ) ;
V_75 = F_22 ( V_22 -> V_33 ) ;
V_72 = F_28 ( V_20 , V_6 , V_75 , 0 ) ;
if ( ! V_72 )
return V_76 ;
}
F_29 ( V_73 , V_20 , V_22 , V_72 , V_77 ) ;
return V_78 ;
}
return V_76 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_21 V_22 ;
bool V_23 = false ;
#ifdef F_31
if ( F_17 ( F_26 ( V_20 ) -> V_59 ) ) {
if ( F_32 ( F_33 ( V_20 ) ) )
goto V_79;
}
#endif
if ( F_4 ( V_20 , & V_22 , & V_23 ) < 0 )
goto V_79;
if ( F_25 ( V_20 , & V_22 ) == V_78 )
return 0 ;
F_34 ( V_20 , V_49 , V_51 , 0 ) ;
V_79:
F_35 ( V_20 ) ;
return 0 ;
}
static void F_36 ( struct V_19 * V_20 , int V_27 , T_1 V_6 ,
T_1 V_29 , T_2 V_33 , T_2 V_34 )
{
struct V_24 * V_25 ;
F_37 ( V_20 , V_27 ) ;
F_38 ( V_20 ) ;
V_25 = (struct V_24 * ) V_20 -> V_80 ;
V_25 -> V_6 = F_3 ( V_6 ) ;
V_25 -> V_30 = V_29 ;
if ( V_6 & ( V_4 | V_3 | V_5 ) ) {
T_2 * V_81 = ( T_2 * ) ( ( ( V_37 * ) V_25 ) + V_27 - 4 ) ;
if ( V_6 & V_5 ) {
* V_81 = V_34 ;
V_81 -- ;
}
if ( V_6 & V_4 ) {
* V_81 = V_33 ;
V_81 -- ;
}
if ( V_6 & V_3 &&
! ( F_39 ( V_20 ) -> V_82 &
( V_83 | V_84 ) ) ) {
* V_81 = 0 ;
* ( V_85 * ) V_81 = F_40 ( F_41 ( V_20 , 0 ,
V_20 -> V_86 , 0 ) ) ;
}
}
}
static void F_42 ( struct V_19 * V_20 , struct V_87 * V_40 ,
const struct V_43 * V_88 ,
T_1 V_29 )
{
struct V_46 * V_73 = F_43 ( V_40 ) ;
if ( V_73 -> V_61 . V_1 & V_5 )
V_73 -> V_89 ++ ;
F_36 ( V_20 , V_73 -> V_90 , V_73 -> V_61 . V_1 ,
V_29 , V_73 -> V_61 . V_91 , F_44 ( V_73 -> V_89 ) ) ;
F_45 ( V_20 , V_29 ) ;
F_46 ( V_20 , V_40 , V_88 , V_88 -> V_30 ) ;
}
static struct V_19 * F_47 ( struct V_19 * V_20 ,
bool V_92 )
{
return F_48 ( V_20 , V_92 ,
V_92 ? V_84 : V_83 ) ;
}
static struct V_93 * F_49 ( struct V_19 * V_20 ,
struct V_87 * V_40 ,
struct V_94 * V_95 ,
const struct V_96 * V_33 )
{
struct V_39 * V_39 = F_13 ( V_40 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_59 = V_33 -> V_97 . V_98 . V_99 ;
V_95 -> V_60 = V_33 -> V_97 . V_98 . V_100 ;
V_95 -> V_101 = F_50 ( V_33 -> V_102 ) ;
V_95 -> V_103 = V_20 -> V_104 ;
V_95 -> V_105 = V_31 ;
return F_51 ( V_39 , V_95 ) ;
}
static void F_52 ( struct V_19 * V_20 , struct V_87 * V_40 )
{
struct V_106 * V_107 ;
const struct V_96 * V_33 ;
struct V_94 V_95 ;
struct V_93 * V_108 ;
int V_109 ;
int V_110 ;
T_1 V_111 , V_6 ;
int V_112 ;
V_107 = F_53 ( V_20 ) ;
if ( F_5 ( ! V_107 || ! ( V_107 -> V_113 & V_114 ) ||
F_54 ( V_107 ) != V_115 ) )
goto V_116;
V_33 = & V_107 -> V_33 ;
V_108 = F_49 ( V_20 , V_40 , & V_95 , V_33 ) ;
if ( F_55 ( V_108 ) )
goto V_116;
V_110 = F_1 ( V_33 -> V_117 ) ;
V_109 = F_56 ( V_108 -> V_99 . V_40 ) + V_108 -> V_99 . V_118
+ V_110 + sizeof( struct V_43 ) ;
if ( F_57 ( V_20 ) < V_109 || F_58 ( V_20 ) ) {
int V_119 = F_59 ( V_109 -
F_57 ( V_20 ) +
16 ) ;
V_112 = F_60 ( V_20 , F_61 ( int , V_119 , 0 ) ,
0 , V_120 ) ;
if ( F_5 ( V_112 ) )
goto V_121;
}
V_20 = F_47 ( V_20 , ! ! ( V_107 -> V_33 . V_117 & V_3 ) ) ;
if ( F_55 ( V_20 ) ) {
V_20 = NULL ;
goto V_121;
}
V_6 = V_107 -> V_33 . V_117 & ( V_3 | V_4 ) ;
F_36 ( V_20 , V_110 , V_6 , F_10 ( V_55 ) ,
F_24 ( V_107 -> V_33 . V_75 ) , 0 ) ;
V_111 = V_33 -> V_117 & V_122 ? F_10 ( V_123 ) : 0 ;
V_112 = F_62 ( V_20 -> V_124 , V_108 , V_20 , V_95 . V_60 ,
V_33 -> V_97 . V_98 . V_99 , V_31 ,
V_33 -> V_102 , V_33 -> V_62 , V_111 , false ) ;
F_63 ( V_112 , & V_40 -> V_125 , V_40 -> V_126 ) ;
return;
V_121:
F_64 ( V_108 ) ;
V_116:
F_35 ( V_20 ) ;
V_40 -> V_125 . V_127 ++ ;
}
static int F_65 ( struct V_87 * V_40 , struct V_19 * V_20 )
{
struct V_106 * V_38 = F_53 ( V_20 ) ;
struct V_93 * V_108 ;
struct V_94 V_128 ;
if ( F_54 ( V_38 ) != V_115 )
return - V_28 ;
V_108 = F_49 ( V_20 , V_40 , & V_128 , & V_38 -> V_33 ) ;
if ( F_55 ( V_108 ) )
return F_66 ( V_108 ) ;
F_64 ( V_108 ) ;
V_38 -> V_33 . V_97 . V_98 . V_100 = V_128 . V_60 ;
return 0 ;
}
static T_5 F_67 ( struct V_19 * V_20 ,
struct V_87 * V_40 )
{
struct V_46 * V_73 = F_43 ( V_40 ) ;
const struct V_43 * V_88 ;
if ( V_73 -> V_74 ) {
F_52 ( V_20 , V_40 ) ;
return V_129 ;
}
if ( V_40 -> V_130 ) {
if ( F_68 ( V_20 , V_40 -> V_131 -
( V_73 -> V_132 + sizeof( struct V_43 ) ) ) )
goto V_133;
V_88 = ( const struct V_43 * ) V_20 -> V_80 ;
F_69 ( V_20 , V_73 -> V_132 + sizeof( struct V_43 ) ) ;
F_70 ( V_20 ) ;
} else {
if ( F_68 ( V_20 , V_40 -> V_131 ) )
goto V_133;
V_88 = & V_73 -> V_61 . V_44 ;
}
V_20 = F_47 ( V_20 , ! ! ( V_73 -> V_61 . V_1 & V_3 ) ) ;
if ( F_55 ( V_20 ) )
goto V_134;
F_42 ( V_20 , V_40 , V_88 , V_20 -> V_30 ) ;
return V_129 ;
V_133:
F_35 ( V_20 ) ;
V_134:
V_40 -> V_125 . V_127 ++ ;
return V_129 ;
}
static T_5 F_71 ( struct V_19 * V_20 ,
struct V_87 * V_40 )
{
struct V_46 * V_73 = F_43 ( V_40 ) ;
if ( V_73 -> V_74 ) {
F_52 ( V_20 , V_40 ) ;
return V_129 ;
}
V_20 = F_47 ( V_20 , ! ! ( V_73 -> V_61 . V_1 & V_3 ) ) ;
if ( F_55 ( V_20 ) )
goto V_134;
if ( F_68 ( V_20 , V_40 -> V_131 ) )
goto V_133;
F_42 ( V_20 , V_40 , & V_73 -> V_61 . V_44 , F_10 ( V_55 ) ) ;
return V_129 ;
V_133:
F_35 ( V_20 ) ;
V_134:
V_40 -> V_125 . V_127 ++ ;
return V_129 ;
}
static int F_72 ( struct V_87 * V_40 ,
struct V_135 * V_136 , int V_137 )
{
int V_112 ;
struct V_138 V_139 ;
if ( F_73 ( & V_139 , V_136 -> V_140 . V_141 , sizeof( V_139 ) ) )
return - V_142 ;
if ( V_137 == V_143 || V_137 == V_144 ) {
if ( V_139 . V_44 . V_145 != 4 || V_139 . V_44 . V_30 != V_31 ||
V_139 . V_44 . V_146 != 5 || ( V_139 . V_44 . V_147 & F_10 ( ~ V_123 ) ) ||
( ( V_139 . V_148 | V_139 . V_1 ) & ( V_17 | V_9 ) ) )
return - V_28 ;
}
V_139 . V_148 = F_2 ( V_139 . V_148 ) ;
V_139 . V_1 = F_2 ( V_139 . V_1 ) ;
V_112 = F_74 ( V_40 , & V_139 , V_137 ) ;
if ( V_112 )
return V_112 ;
V_139 . V_148 = F_3 ( V_139 . V_148 ) ;
V_139 . V_1 = F_3 ( V_139 . V_1 ) ;
if ( F_75 ( V_136 -> V_140 . V_141 , & V_139 , sizeof( V_139 ) ) )
return - V_142 ;
return 0 ;
}
static int F_76 ( struct V_19 * V_20 , struct V_87 * V_40 ,
unsigned short type ,
const void * V_59 , const void * V_60 , unsigned int V_86 )
{
struct V_46 * V_47 = F_43 ( V_40 ) ;
struct V_43 * V_44 ;
struct V_24 * V_25 ;
V_44 = (struct V_43 * ) F_37 ( V_20 , V_47 -> V_132 + sizeof( * V_44 ) ) ;
V_25 = (struct V_24 * ) ( V_44 + 1 ) ;
V_25 -> V_6 = F_3 ( V_47 -> V_61 . V_1 ) ;
V_25 -> V_30 = F_10 ( type ) ;
memcpy ( V_44 , & V_47 -> V_61 . V_44 , sizeof( struct V_43 ) ) ;
if ( V_60 )
memcpy ( & V_44 -> V_60 , V_60 , 4 ) ;
if ( V_59 )
memcpy ( & V_44 -> V_59 , V_59 , 4 ) ;
if ( V_44 -> V_59 )
return V_47 -> V_132 + sizeof( * V_44 ) ;
return - ( V_47 -> V_132 + sizeof( * V_44 ) ) ;
}
static int F_77 ( const struct V_19 * V_20 , unsigned char * V_149 )
{
const struct V_43 * V_44 = ( const struct V_43 * ) F_78 ( V_20 ) ;
memcpy ( V_149 , & V_44 -> V_60 , 4 ) ;
return 4 ;
}
static int F_79 ( struct V_87 * V_40 )
{
struct V_46 * V_47 = F_43 ( V_40 ) ;
if ( F_17 ( V_47 -> V_61 . V_44 . V_59 ) ) {
struct V_94 V_128 ;
struct V_93 * V_108 ;
V_108 = F_80 ( V_47 -> V_39 , & V_128 ,
V_47 -> V_61 . V_44 . V_59 ,
V_47 -> V_61 . V_44 . V_60 ,
V_47 -> V_61 . V_91 ,
F_50 ( V_47 -> V_61 . V_44 . V_102 ) ,
V_47 -> V_61 . V_150 ) ;
if ( F_55 ( V_108 ) )
return - V_151 ;
V_40 = V_108 -> V_99 . V_40 ;
F_64 ( V_108 ) ;
if ( ! F_81 ( V_40 ) )
return - V_151 ;
V_47 -> V_152 = V_40 -> V_58 ;
F_82 ( F_81 ( V_40 ) , V_47 -> V_61 . V_44 . V_59 ) ;
}
return 0 ;
}
static int F_83 ( struct V_87 * V_40 )
{
struct V_46 * V_47 = F_43 ( V_40 ) ;
if ( F_17 ( V_47 -> V_61 . V_44 . V_59 ) && V_47 -> V_152 ) {
struct V_153 * V_154 ;
V_154 = F_84 ( V_47 -> V_39 , V_47 -> V_152 ) ;
if ( V_154 )
F_85 ( V_154 , V_47 -> V_61 . V_44 . V_59 ) ;
}
return 0 ;
}
static void F_86 ( struct V_87 * V_40 )
{
V_40 -> V_155 = & V_156 ;
V_40 -> type = V_157 ;
F_87 ( V_40 , V_57 ) ;
}
static void F_88 ( struct V_87 * V_40 )
{
struct V_46 * V_73 ;
int V_158 ;
V_73 = F_43 ( V_40 ) ;
V_73 -> V_90 = F_1 ( V_73 -> V_61 . V_1 ) ;
V_73 -> V_61 . V_44 . V_30 = V_31 ;
V_73 -> V_132 = V_73 -> V_90 + V_73 -> V_159 ;
V_158 = V_73 -> V_132 + sizeof( struct V_43 ) ;
V_40 -> V_131 = V_160 + V_158 + 4 ;
V_40 -> V_161 = V_162 - V_158 - 4 ;
V_40 -> V_163 |= V_164 ;
V_40 -> V_165 |= V_164 ;
if ( ! ( V_73 -> V_61 . V_1 & V_5 ) ) {
V_40 -> V_163 |= V_166 ;
V_40 -> V_165 |= V_166 ;
V_40 -> V_163 |= V_167 ;
}
}
static int F_89 ( struct V_87 * V_40 )
{
struct V_46 * V_73 = F_43 ( V_40 ) ;
struct V_43 * V_44 = & V_73 -> V_61 . V_44 ;
F_88 ( V_40 ) ;
memcpy ( V_40 -> V_168 , & V_44 -> V_60 , 4 ) ;
memcpy ( V_40 -> V_169 , & V_44 -> V_59 , 4 ) ;
V_40 -> V_6 = V_170 ;
F_90 ( V_40 ) ;
V_40 -> V_171 = 4 ;
if ( V_44 -> V_59 ) {
#ifdef F_31
if ( F_17 ( V_44 -> V_59 ) ) {
if ( ! V_44 -> V_60 )
return - V_28 ;
V_40 -> V_6 = V_172 ;
V_40 -> V_130 = & V_173 ;
}
#endif
} else
V_40 -> V_130 = & V_173 ;
return F_91 ( V_40 ) ;
}
static int T_6 F_92 ( struct V_39 * V_39 )
{
return F_93 ( V_39 , V_57 , & V_174 , NULL ) ;
}
static void T_7 F_94 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = F_15 ( V_39 , V_57 ) ;
F_95 ( V_42 , & V_174 ) ;
}
static int F_96 ( struct V_175 * V_176 [] , struct V_175 * V_80 [] )
{
T_1 V_6 ;
if ( ! V_80 )
return 0 ;
V_6 = 0 ;
if ( V_80 [ V_177 ] )
V_6 |= F_97 ( V_80 [ V_177 ] ) ;
if ( V_80 [ V_178 ] )
V_6 |= F_97 ( V_80 [ V_178 ] ) ;
if ( V_6 & ( V_17 | V_9 ) )
return - V_28 ;
return 0 ;
}
static int F_98 ( struct V_175 * V_176 [] , struct V_175 * V_80 [] )
{
T_2 V_59 ;
if ( V_176 [ V_179 ] ) {
if ( F_99 ( V_176 [ V_179 ] ) != V_180 )
return - V_28 ;
if ( ! F_100 ( F_101 ( V_176 [ V_179 ] ) ) )
return - V_151 ;
}
if ( ! V_80 )
goto V_134;
if ( V_80 [ V_181 ] ) {
memcpy ( & V_59 , F_101 ( V_80 [ V_181 ] ) , 4 ) ;
if ( ! V_59 )
return - V_28 ;
}
V_134:
return F_96 ( V_176 , V_80 ) ;
}
static void F_102 ( struct V_87 * V_40 ,
struct V_175 * V_80 [] ,
struct V_175 * V_176 [] ,
struct V_138 * V_61 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_44 . V_30 = V_31 ;
if ( ! V_80 )
return;
if ( V_80 [ V_182 ] )
V_61 -> V_150 = F_103 ( V_80 [ V_182 ] ) ;
if ( V_80 [ V_177 ] )
V_61 -> V_148 = F_2 ( F_97 ( V_80 [ V_177 ] ) ) ;
if ( V_80 [ V_178 ] )
V_61 -> V_1 = F_2 ( F_97 ( V_80 [ V_178 ] ) ) ;
if ( V_80 [ V_183 ] )
V_61 -> V_184 = F_104 ( V_80 [ V_183 ] ) ;
if ( V_80 [ V_185 ] )
V_61 -> V_91 = F_104 ( V_80 [ V_185 ] ) ;
if ( V_80 [ V_186 ] )
V_61 -> V_44 . V_60 = F_105 ( V_80 [ V_186 ] ) ;
if ( V_80 [ V_181 ] )
V_61 -> V_44 . V_59 = F_105 ( V_80 [ V_181 ] ) ;
if ( V_80 [ V_187 ] )
V_61 -> V_44 . V_62 = F_106 ( V_80 [ V_187 ] ) ;
if ( V_80 [ V_188 ] )
V_61 -> V_44 . V_102 = F_106 ( V_80 [ V_188 ] ) ;
if ( ! V_80 [ V_189 ] || F_106 ( V_80 [ V_189 ] ) )
V_61 -> V_44 . V_147 = F_10 ( V_123 ) ;
if ( V_80 [ V_190 ] ) {
struct V_46 * V_47 = F_43 ( V_40 ) ;
V_47 -> V_74 = true ;
}
}
static bool F_107 ( struct V_175 * V_80 [] ,
struct V_191 * V_192 )
{
bool V_193 = false ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
if ( ! V_80 )
return V_193 ;
if ( V_80 [ V_194 ] ) {
V_193 = true ;
V_192 -> type = F_108 ( V_80 [ V_194 ] ) ;
}
if ( V_80 [ V_195 ] ) {
V_193 = true ;
V_192 -> V_6 = F_108 ( V_80 [ V_195 ] ) ;
}
if ( V_80 [ V_196 ] ) {
V_193 = true ;
V_192 -> V_197 = F_97 ( V_80 [ V_196 ] ) ;
}
if ( V_80 [ V_198 ] ) {
V_193 = true ;
V_192 -> V_199 = F_97 ( V_80 [ V_198 ] ) ;
}
return V_193 ;
}
static int F_109 ( struct V_87 * V_40 )
{
F_88 ( V_40 ) ;
V_40 -> V_200 |= V_201 ;
return F_91 ( V_40 ) ;
}
static void F_110 ( struct V_87 * V_40 )
{
F_111 ( V_40 ) ;
V_40 -> V_155 = & V_202 ;
V_40 -> V_200 |= V_201 ;
F_87 ( V_40 , V_56 ) ;
}
static int F_112 ( struct V_39 * V_203 , struct V_87 * V_40 ,
struct V_175 * V_176 [] , struct V_175 * V_80 [] )
{
struct V_138 V_139 ;
struct V_191 V_192 ;
if ( F_107 ( V_80 , & V_192 ) ) {
struct V_46 * V_47 = F_43 ( V_40 ) ;
int V_112 = F_113 ( V_47 , & V_192 ) ;
if ( V_112 < 0 )
return V_112 ;
}
F_102 ( V_40 , V_80 , V_176 , & V_139 ) ;
return F_114 ( V_40 , V_176 , & V_139 ) ;
}
static int F_115 ( struct V_87 * V_40 , struct V_175 * V_176 [] ,
struct V_175 * V_80 [] )
{
struct V_138 V_139 ;
struct V_191 V_192 ;
if ( F_107 ( V_80 , & V_192 ) ) {
struct V_46 * V_47 = F_43 ( V_40 ) ;
int V_112 = F_113 ( V_47 , & V_192 ) ;
if ( V_112 < 0 )
return V_112 ;
}
F_102 ( V_40 , V_80 , V_176 , & V_139 ) ;
return F_116 ( V_40 , V_176 , & V_139 ) ;
}
static T_8 F_117 ( const struct V_87 * V_40 )
{
return
F_118 ( 4 ) +
F_118 ( 2 ) +
F_118 ( 2 ) +
F_118 ( 4 ) +
F_118 ( 4 ) +
F_118 ( 4 ) +
F_118 ( 4 ) +
F_118 ( 1 ) +
F_118 ( 1 ) +
F_118 ( 1 ) +
F_118 ( 2 ) +
F_118 ( 2 ) +
F_118 ( 2 ) +
F_118 ( 2 ) +
F_118 ( 0 ) +
0 ;
}
static int F_119 ( struct V_19 * V_20 , const struct V_87 * V_40 )
{
struct V_46 * V_47 = F_43 ( V_40 ) ;
struct V_138 * V_139 = & V_47 -> V_61 ;
if ( F_120 ( V_20 , V_182 , V_139 -> V_150 ) ||
F_121 ( V_20 , V_177 , F_3 ( V_139 -> V_148 ) ) ||
F_121 ( V_20 , V_178 , F_3 ( V_139 -> V_1 ) ) ||
F_122 ( V_20 , V_183 , V_139 -> V_184 ) ||
F_122 ( V_20 , V_185 , V_139 -> V_91 ) ||
F_123 ( V_20 , V_186 , V_139 -> V_44 . V_60 ) ||
F_123 ( V_20 , V_181 , V_139 -> V_44 . V_59 ) ||
F_124 ( V_20 , V_187 , V_139 -> V_44 . V_62 ) ||
F_124 ( V_20 , V_188 , V_139 -> V_44 . V_102 ) ||
F_124 ( V_20 , V_189 ,
! ! ( V_139 -> V_44 . V_147 & F_10 ( V_123 ) ) ) )
goto V_204;
if ( F_125 ( V_20 , V_194 ,
V_47 -> V_205 . type ) ||
F_121 ( V_20 , V_196 ,
V_47 -> V_205 . V_197 ) ||
F_121 ( V_20 , V_198 ,
V_47 -> V_205 . V_199 ) ||
F_125 ( V_20 , V_195 ,
V_47 -> V_205 . V_6 ) )
goto V_204;
if ( V_47 -> V_74 ) {
if ( F_126 ( V_20 , V_190 ) )
goto V_204;
}
return 0 ;
V_204:
return - V_206 ;
}
struct V_87 * F_127 ( struct V_39 * V_39 , const char * V_207 ,
V_37 V_208 )
{
struct V_175 * V_176 [ V_209 + 1 ] ;
struct V_87 * V_40 ;
struct V_46 * V_47 ;
int V_112 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_40 = F_128 ( V_39 , V_207 , V_208 ,
& V_210 , V_176 ) ;
if ( F_55 ( V_40 ) )
return V_40 ;
V_47 = F_43 ( V_40 ) ;
V_47 -> V_74 = true ;
V_112 = F_112 ( V_39 , V_40 , V_176 , NULL ) ;
if ( V_112 < 0 )
goto V_134;
return V_40 ;
V_134:
F_129 ( V_40 ) ;
return F_130 ( V_112 ) ;
}
static int T_6 F_131 ( struct V_39 * V_39 )
{
return F_93 ( V_39 , V_56 , & V_210 , L_1 ) ;
}
static void T_7 F_132 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = F_15 ( V_39 , V_56 ) ;
F_95 ( V_42 , & V_210 ) ;
}
static int T_9 F_133 ( void )
{
int V_112 ;
F_134 ( L_2 ) ;
V_112 = F_135 ( & V_211 ) ;
if ( V_112 < 0 )
return V_112 ;
V_112 = F_135 ( & V_212 ) ;
if ( V_112 < 0 )
goto V_213;
V_112 = F_136 ( & V_214 , V_215 ) ;
if ( V_112 < 0 ) {
F_134 ( L_3 , V_216 ) ;
goto V_217;
}
V_112 = F_137 ( & V_174 ) ;
if ( V_112 < 0 )
goto V_218;
V_112 = F_137 ( & V_210 ) ;
if ( V_112 < 0 )
goto V_219;
return 0 ;
V_219:
F_138 ( & V_174 ) ;
V_218:
F_139 ( & V_214 , V_215 ) ;
V_217:
F_140 ( & V_212 ) ;
V_213:
F_140 ( & V_211 ) ;
return V_112 ;
}
static void T_10 F_141 ( void )
{
F_138 ( & V_210 ) ;
F_138 ( & V_174 ) ;
F_139 ( & V_214 , V_215 ) ;
F_140 ( & V_212 ) ;
F_140 ( & V_211 ) ;
}
