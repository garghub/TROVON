static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
const int V_6 = F_2 ( V_5 ) ;
int V_7 ;
V_7 = F_3 () ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 , V_10 [ V_6 ] ) ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_11 [ V_6 ] , F_6 ( V_5 ) ) ;
F_7 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_12 ) ;
unsigned long V_13 = V_14 - V_4 -> V_15 ;
int V_7 ;
V_7 = F_3 () ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_16 [ V_6 ] , V_13 ) ;
F_10 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_11 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_8 () ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 , const int V_6 )
{
const unsigned long V_17 = V_4 -> V_18 ;
F_13 ( & V_4 -> V_19 ) ;
if ( V_6 == V_20 ) {
if ( ! ( V_17 & V_21 ) || ! ( V_17 & V_22 ) )
F_14 ( V_2 , V_4 -> V_23 , V_4 -> V_24 ) ;
if ( ( V_17 & V_21 ) && ( V_17 & V_22 ) && ( V_17 & V_25 ) )
F_15 ( V_2 , V_4 -> V_23 , V_4 -> V_24 ) ;
if ( V_17 & V_26 ) {
if ( F_16 ( V_2 , V_27 ) ) {
if ( V_17 & V_28 )
F_17 ( V_2 , V_4 -> V_23 ) ;
F_18 ( V_2 ) ;
} else if ( F_19 ( & V_29 ) ) {
F_20 ( V_30 , L_1
L_2 ,
( unsigned long long ) V_4 -> V_23 ) ;
}
}
}
F_21 ( V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( F_23 ( V_33 , & V_2 -> V_34 ) )
return;
V_32 = V_2 -> V_35 ;
V_32 -> V_36 . V_37 = V_38 ;
F_24 ( V_2 ) ;
F_25 ( & V_2 -> V_39 . V_40 , & V_32 -> V_36 ) ;
F_26 ( V_33 , & V_2 -> V_34 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const unsigned long V_17 = V_4 -> V_18 ;
struct V_3 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
if ( V_2 -> V_48 . V_49 >= V_50 &&
( V_17 & V_51 ) != 0 &&
V_4 -> V_52 == V_2 -> V_35 -> V_53 )
F_22 ( V_2 ) ;
if ( ( V_17 & V_54 ) && V_2 -> V_55 != NULL ) {
const T_1 V_23 = V_4 -> V_23 ;
const int V_24 = V_4 -> V_24 ;
#define F_28 overlaps(sector, size, i->sector, i->size)
V_47 = F_29 ( V_2 , V_23 ) ;
F_30 (i, n, slot, collision) {
if ( F_28 ) {
F_31 ( V_30 , L_3
L_4 ,
V_4 , ( unsigned long long ) V_23 , V_24 ,
V_41 , ( unsigned long long ) V_41 -> V_23 , V_41 -> V_24 ) ;
}
}
#undef F_28
#define F_28 overlaps(sector, size, e->sector, e->size)
V_47 = F_32 ( V_2 , V_4 -> V_23 ) ;
F_30 (e, n, slot, collision) {
if ( F_28 ) {
F_33 ( & V_2 -> V_56 ) ;
break;
}
}
}
#undef F_28
}
void F_34 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_35 ( V_58 -> V_5 , V_58 -> error ) ;
F_36 ( V_2 ) ;
}
void F_37 ( struct V_3 * V_4 , struct V_57 * V_58 )
{
const unsigned long V_17 = V_4 -> V_18 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_6 = V_4 -> V_12 ? F_2 ( V_4 -> V_12 ) : V_20 ;
if ( V_17 & V_59 )
return;
if ( V_17 & V_60 )
return;
if ( V_17 & V_61 )
return;
if ( V_4 -> V_12 ) {
int V_62 = ( V_17 & V_22 ) || ( V_17 & V_21 ) ;
int error = F_38 ( V_4 -> V_63 ) ;
if ( ! F_39 ( & V_4 -> V_64 ) )
F_40 ( & V_4 -> V_64 ) ;
else
F_41 ( ( V_17 & ( V_65 & ~ V_54 ) ) == 0 ) ;
if ( V_6 == V_20 )
F_27 ( V_2 , V_4 ) ;
F_9 ( V_2 , V_4 ) ;
V_58 -> error = V_62 ? 0 : ( error ? : - V_66 ) ;
V_58 -> V_5 = V_4 -> V_12 ;
V_4 -> V_12 = NULL ;
}
if ( ( V_17 & V_65 ) == 0 || ( V_17 & V_54 ) ) {
F_12 ( V_2 , V_4 , V_6 ) ;
}
}
static void F_42 ( struct V_3 * V_4 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! F_43 ( V_2 -> V_48 ) )
F_37 ( V_4 , V_58 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
const T_1 V_23 = V_4 -> V_23 ;
const int V_24 = V_4 -> V_24 ;
struct V_3 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
F_41 ( F_39 ( & V_4 -> V_64 ) ) ;
if ( ! F_45 ( V_2 ) )
return 0 ;
F_46 (mdev->tl_hash_s == 0 )
goto V_67;
F_47 ( V_2 -> V_68 == NULL ) ;
#define F_28 overlaps(i->sector, i->size, sector, size)
V_47 = F_29 ( V_2 , V_23 ) ;
F_30 (i, n, slot, collision) {
if ( F_28 ) {
F_31 ( V_30 , L_5
L_6
L_7 ,
V_69 -> V_70 , V_69 -> V_71 ,
( unsigned long long ) V_23 , V_24 ,
( unsigned long long ) V_41 -> V_23 , V_41 -> V_24 ) ;
goto V_72;
}
}
if ( V_2 -> V_73 ) {
F_47 ( V_2 -> V_55 == NULL ) ;
#undef F_28
#define F_28 overlaps(e->sector, e->size, sector, size)
V_47 = F_32 ( V_2 , V_23 ) ;
F_30 (e, n, slot, collision) {
if ( F_28 ) {
F_31 ( V_30 , L_8
L_9
L_7 ,
V_69 -> V_70 , V_69 -> V_71 ,
( unsigned long long ) V_23 , V_24 ,
( unsigned long long ) V_43 -> V_23 , V_43 -> V_24 ) ;
goto V_72;
}
}
}
#undef F_28
V_67:
F_48 ( V_2 ) ;
return 0 ;
V_72:
F_48 ( V_2 ) ;
return 1 ;
}
int F_49 ( struct V_3 * V_4 , enum V_74 V_75 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_76 = 0 ;
V_58 -> V_5 = NULL ;
switch ( V_75 ) {
default:
F_50 ( V_30 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_77 :
F_41 ( ! ( V_4 -> V_18 & V_65 ) ) ;
V_4 -> V_18 |= V_60 ;
F_24 ( V_2 ) ;
break;
case V_78 :
F_41 ( ! ( V_4 -> V_18 & V_26 ) ) ;
V_4 -> V_18 |= V_61 ;
break;
case V_79 :
if ( F_2 ( V_4 -> V_12 ) == V_20 )
V_2 -> V_80 += V_4 -> V_24 >> 9 ;
else
V_2 -> V_81 += V_4 -> V_24 >> 9 ;
V_4 -> V_18 |= ( V_82 | V_22 ) ;
V_4 -> V_18 &= ~ V_61 ;
F_42 ( V_4 , V_58 ) ;
F_18 ( V_2 ) ;
break;
case V_83 :
V_4 -> V_18 |= V_82 ;
V_4 -> V_18 &= ~ V_61 ;
F_51 ( V_2 , false ) ;
F_42 ( V_4 , V_58 ) ;
F_18 ( V_2 ) ;
break;
case V_84 :
V_4 -> V_18 |= V_82 ;
V_4 -> V_18 &= ~ V_61 ;
F_42 ( V_4 , V_58 ) ;
F_18 ( V_2 ) ;
break;
case V_85 :
F_14 ( V_2 , V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_82 ;
V_4 -> V_18 &= ~ V_61 ;
F_41 ( ! ( V_4 -> V_18 & V_65 ) ) ;
F_51 ( V_2 , false ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_48 . V_86 != V_87 ) {
F_42 ( V_4 , V_58 ) ;
break;
}
V_4 -> V_18 |= V_60 ;
F_24 ( V_2 ) ;
case V_88 :
F_52 ( & V_4 -> V_64 , F_53 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_89 , & V_2 -> V_34 ) ;
F_41 ( V_4 -> V_18 & V_60 ) ;
V_4 -> V_18 |= V_59 ;
V_4 -> V_36 . V_37 = ( V_4 -> V_18 & V_26 )
? V_90
: V_91 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_92 :
F_52 ( & V_4 -> V_64 , F_29 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_89 , & V_2 -> V_34 ) ;
F_41 ( F_23 ( V_33 , & V_2 -> V_34 ) == 0 ) ;
V_4 -> V_52 = V_2 -> V_35 -> V_53 ;
V_2 -> V_35 -> V_93 ++ ;
F_41 ( V_4 -> V_18 & V_60 ) ;
V_4 -> V_18 |= V_59 ;
V_4 -> V_36 . V_37 = V_94 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
if ( V_2 -> V_35 -> V_93 >= V_2 -> V_95 -> V_96 )
F_22 ( V_2 ) ;
break;
case V_97 :
V_4 -> V_18 |= V_59 ;
V_4 -> V_36 . V_37 = V_98 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
V_4 -> V_18 &= ~ V_59 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_102 :
if ( F_2 ( V_4 -> V_12 ) == V_20 )
F_54 ( V_4 -> V_24 >> 9 , & V_2 -> V_103 ) ;
if ( F_2 ( V_4 -> V_12 ) == V_20 &&
V_2 -> V_95 -> V_104 == V_105 ) {
if ( V_4 -> V_18 & V_60 ) {
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ V_60 ;
V_4 -> V_18 |= V_21 ;
}
}
V_4 -> V_18 &= ~ V_59 ;
V_4 -> V_18 |= V_51 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_106 :
V_4 -> V_18 &= ~ V_59 ;
case V_107 :
if ( V_4 -> V_18 & V_60 )
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ ( V_21 | V_60 ) ;
V_4 -> V_18 |= V_54 ;
if ( V_4 -> V_18 & V_51 && V_4 -> V_18 & V_108 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_103 ) ;
if ( ! ( V_4 -> V_18 & V_59 ) )
F_37 ( V_4 , V_58 ) ;
break;
case V_109 :
V_4 -> V_18 |= V_25 ;
case V_110 :
if ( V_75 == V_110 )
F_31 ( V_30 , L_11
L_12 ,
( unsigned long long ) V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_54 ;
case V_111 :
case V_112 :
V_4 -> V_18 |= V_21 ;
F_41 ( V_4 -> V_18 & V_60 ) ;
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_103 ) ;
V_4 -> V_18 &= ~ V_60 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_113 :
if ( V_4 -> V_18 & V_60 ) {
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_103 ) ;
}
V_4 -> V_18 &= ~ ( V_21 | V_60 ) ;
V_4 -> V_18 |= V_54 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_114 :
if ( ! ( V_4 -> V_18 & V_82 ) )
break;
F_37 ( V_4 , V_58 ) ;
break;
case V_115 :
if ( ! ( V_4 -> V_18 & V_82 ) )
break;
V_4 -> V_18 &= ~ V_82 ;
V_76 = V_116 ;
if ( F_2 ( V_4 -> V_12 ) == V_20 )
V_76 = V_117 ;
F_57 ( V_2 ) ;
V_4 -> V_36 . V_37 = V_118 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_119 :
if ( ! ( V_4 -> V_18 & V_21 ) ) {
if ( V_4 -> V_36 . V_37 ) {
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
V_76 = V_4 -> V_18 & V_108 ? V_117 : V_116 ;
}
break;
}
case V_120 :
if ( ! ( V_4 -> V_18 & V_108 ) )
break;
if ( V_4 -> V_18 & V_60 ) {
F_50 ( V_30 , L_13 ) ;
F_58 ( & V_4 -> V_19 , & V_2 -> V_121 ) ;
}
if ( ( V_4 -> V_18 & V_65 ) != 0 ) {
V_4 -> V_18 |= V_54 ;
if ( V_2 -> V_95 -> V_104 == V_105 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_103 ) ;
}
F_37 ( V_4 , V_58 ) ;
break;
case V_122 :
F_41 ( V_4 -> V_18 & V_60 ) ;
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ V_60 ;
V_4 -> V_18 |= ( V_21 | V_54 ) ;
F_42 ( V_4 , V_58 ) ;
break;
} ;
return V_76 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_23 , int V_24 )
{
unsigned long V_123 , V_124 ;
T_1 V_125 , V_126 ;
if ( V_2 -> V_48 . V_127 == V_87 )
return 1 ;
if ( V_2 -> V_48 . V_127 >= V_128 )
return 0 ;
if ( V_2 -> V_48 . V_127 < V_129 )
return 0 ;
V_126 = F_60 ( V_2 -> V_130 ) ;
V_125 = V_23 + ( V_24 >> 9 ) - 1 ;
F_41 ( V_23 < V_126 ) ;
F_41 ( V_125 < V_126 ) ;
V_123 = F_61 ( V_23 ) ;
V_124 = F_61 ( V_125 ) ;
return 0 == F_62 ( V_2 , V_123 , V_124 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_5 * V_5 , unsigned long V_15 )
{
const int V_6 = F_64 ( V_5 ) ;
const int V_24 = V_5 -> V_131 ;
const T_1 V_23 = V_5 -> V_132 ;
struct V_31 * V_32 = NULL ;
struct V_3 * V_4 ;
int V_133 , V_134 , V_135 = 0 ;
int V_136 = - V_66 ;
int V_137 = 0 ;
V_4 = F_65 ( V_2 , V_5 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_50 ( V_30 , L_14 ) ;
F_35 ( V_5 , - V_138 ) ;
return 0 ;
}
V_4 -> V_15 = V_15 ;
V_133 = F_57 ( V_2 ) ;
if ( ! V_133 ) {
F_66 ( V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
}
if ( V_6 == V_20 ) {
V_134 = 1 ;
} else {
if ( V_133 ) {
if ( ! F_59 ( V_2 , V_23 , V_24 ) ) {
V_133 = 0 ;
F_66 ( V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
F_18 ( V_2 ) ;
}
}
V_134 = ! V_133 && V_2 -> V_48 . V_86 >= V_87 ;
}
if ( V_6 == V_139 && V_2 -> V_48 . V_127 >= V_129 && ! V_133 ) {
V_136 = - V_140 ;
goto V_141;
}
if ( V_6 == V_20 && V_133 && ! F_23 ( V_142 , & V_2 -> V_34 ) ) {
V_4 -> V_18 |= V_28 ;
F_67 ( V_2 , V_23 ) ;
}
V_134 = V_134 && F_68 ( V_2 -> V_48 ) ;
V_135 = V_6 == V_20 && F_69 ( V_2 -> V_48 ) ;
F_41 ( ! ( V_134 && V_135 ) ) ;
if ( ! ( V_133 || V_134 ) && ! F_43 ( V_2 -> V_48 ) ) {
if ( F_19 ( & V_29 ) )
F_50 ( V_30 , L_15 ) ;
goto V_143;
}
if ( V_6 == V_20 && ( V_134 || V_135 ) &&
V_2 -> V_144 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
V_145:
V_32 = F_70 ( sizeof( struct V_31 ) , V_146 ) ;
if ( ! V_32 ) {
F_50 ( V_30 , L_16 ) ;
V_136 = - V_138 ;
goto V_143;
}
}
F_71 ( & V_2 -> V_147 ) ;
if ( F_43 ( V_2 -> V_48 ) ) {
V_137 = 1 ;
F_72 ( & V_2 -> V_147 ) ;
goto V_143;
}
if ( V_134 || V_135 ) {
V_134 = F_68 ( V_2 -> V_48 ) ;
V_135 = V_6 == V_20 && F_69 ( V_2 -> V_48 ) ;
F_41 ( ! ( V_134 && V_135 ) ) ;
if ( ! ( V_134 || V_135 ) )
F_20 ( V_30 , L_17 ) ;
if ( ! ( V_133 || V_134 ) ) {
F_50 ( V_30 , L_15 ) ;
F_72 ( & V_2 -> V_147 ) ;
goto V_143;
}
}
if ( V_32 && V_2 -> V_144 == NULL ) {
V_2 -> V_144 = V_32 ;
V_32 = NULL ;
}
if ( V_6 == V_20 && ( V_134 || V_135 ) &&
V_2 -> V_144 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
F_72 ( & V_2 -> V_147 ) ;
goto V_145;
}
F_1 ( V_2 , V_4 , V_5 ) ;
if ( ( V_134 || V_135 ) && V_2 -> V_144 &&
F_73 ( V_33 , & V_2 -> V_34 ) ) {
F_74 ( V_2 , V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
} else {
F_41 ( ! ( V_134 && V_6 == V_20 &&
F_23 ( V_33 , & V_2 -> V_34 ) ) ) ;
}
if ( V_134 )
F_75 ( V_4 , V_77 ) ;
if ( V_133 )
F_75 ( V_4 , V_78 ) ;
if ( V_6 == V_20 && F_44 ( V_4 ) )
goto V_148;
F_76 ( & V_4 -> V_19 , & V_2 -> V_35 -> V_149 ) ;
if ( V_134 ) {
F_75 ( V_4 , ( V_6 == V_20 )
? V_92
: V_88 ) ;
}
if ( V_135 && F_14 ( V_2 , V_23 , V_24 ) )
F_75 ( V_4 , V_97 ) ;
if ( V_134 &&
V_2 -> V_95 -> V_150 != V_151 && V_2 -> V_152 >= 96 ) {
int V_153 = 0 ;
if ( V_2 -> V_95 -> V_154 &&
F_77 ( & V_2 -> V_103 ) >= V_2 -> V_95 -> V_154 ) {
F_78 ( V_30 , L_18 ) ;
V_153 = 1 ;
}
if ( V_2 -> V_155 -> V_156 >= V_2 -> V_95 -> V_157 ) {
F_78 ( V_30 , L_19 ) ;
V_153 = 1 ;
}
if ( V_153 ) {
F_22 ( V_2 ) ;
if ( V_2 -> V_95 -> V_150 == V_158 )
F_79 ( F_80 ( V_2 , V_49 , V_159 ) , 0 , NULL ) ;
else
F_79 ( F_80 ( V_2 , V_49 , V_160 ) , 0 , NULL ) ;
}
}
F_72 ( & V_2 -> V_147 ) ;
F_81 ( V_32 ) ;
if ( V_133 ) {
V_4 -> V_63 -> V_161 = V_2 -> V_162 -> V_163 ;
if ( F_57 ( V_2 ) ) {
if ( F_82 ( V_2 , V_6 == V_20 ? V_164
: V_6 == V_165 ? V_166
: V_167 ) )
F_35 ( V_4 -> V_63 , - V_66 ) ;
else
F_83 ( V_4 -> V_63 ) ;
F_18 ( V_2 ) ;
} else
F_35 ( V_4 -> V_63 , - V_66 ) ;
}
return 0 ;
V_148:
F_9 ( V_2 , V_4 ) ;
F_72 ( & V_2 -> V_147 ) ;
if ( V_134 )
F_55 ( V_2 ) ;
V_136 = 0 ;
V_143:
if ( V_4 -> V_18 & V_28 )
F_17 ( V_2 , V_23 ) ;
V_141:
if ( V_133 ) {
F_66 ( V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
F_18 ( V_2 ) ;
}
if ( ! V_137 )
F_35 ( V_5 , V_136 ) ;
F_21 ( V_4 ) ;
F_36 ( V_2 ) ;
F_81 ( V_32 ) ;
return V_137 ;
}
static int F_84 ( struct V_1 * V_2 , int V_168 )
{
if ( V_2 -> V_48 . V_169 != V_170 &&
( ! V_171 || V_168 ) ) {
if ( F_19 ( & V_29 ) ) {
F_50 ( V_30 , L_20
L_21
L_22 ,
V_69 -> V_70 , V_69 -> V_71 ,
V_168 ? L_23 : L_24 ) ;
}
return 1 ;
}
return 0 ;
}
int F_85 ( struct V_172 * V_173 , struct V_5 * V_5 )
{
unsigned int V_174 , V_175 ;
struct V_1 * V_2 = (struct V_1 * ) V_173 -> V_176 ;
unsigned long V_15 ;
if ( F_84 ( V_2 , F_2 ( V_5 ) & V_20 ) ) {
F_35 ( V_5 , - V_177 ) ;
return 0 ;
}
V_15 = V_14 ;
F_41 ( V_5 -> V_131 > 0 ) ;
F_41 ( ( V_5 -> V_131 & 0x1ff ) == 0 ) ;
F_41 ( V_5 -> V_178 == 0 ) ;
V_174 = V_5 -> V_132 >> V_179 ;
V_175 = ( V_5 -> V_132 + ( V_5 -> V_131 >> 9 ) - 1 ) >> V_179 ;
if ( F_86 ( V_174 == V_175 ) ) {
F_87 ( V_2 , 1 ) ;
return F_63 ( V_2 , V_5 , V_15 ) ;
}
if ( V_5 -> V_180 != 1 || V_5 -> V_178 != 0 || V_5 -> V_131 > V_181 ) {
F_50 ( V_30 , L_25
L_26 ,
V_5 -> V_180 , V_5 -> V_178 , V_5 -> V_131 ,
( unsigned long long ) V_5 -> V_132 ) ;
F_35 ( V_5 , - V_182 ) ;
} else {
struct V_183 * V_184 ;
const T_1 V_185 = V_5 -> V_132 ;
const int V_186 = 1 << V_179 ;
const int V_187 = V_186 - 1 ;
const T_1 V_188 = V_186 - ( V_185 & V_187 ) ;
V_184 = F_88 ( V_5 , V_188 ) ;
F_87 ( V_2 , 3 ) ;
F_41 ( V_175 == V_174 + 1 ) ;
while ( F_63 ( V_2 , & V_184 -> V_189 , V_15 ) )
F_87 ( V_2 , 1 ) ;
while ( F_63 ( V_2 , & V_184 -> V_190 , V_15 ) )
F_87 ( V_2 , 1 ) ;
F_36 ( V_2 ) ;
F_89 ( V_184 ) ;
}
return 0 ;
}
int F_90 ( struct V_172 * V_173 , struct V_191 * V_192 , struct V_193 * V_194 )
{
struct V_1 * V_2 = (struct V_1 * ) V_173 -> V_176 ;
unsigned int V_195 =
( unsigned int ) V_192 -> V_132 << 9 ;
unsigned int V_196 = V_192 -> V_131 ;
int V_197 , V_198 ;
V_197 = V_181
- ( ( V_195 & ( V_181 - 1 ) ) + V_196 ) ;
if ( V_197 < 0 )
V_197 = 0 ;
if ( V_196 == 0 ) {
if ( V_197 <= V_194 -> V_199 )
V_197 = V_194 -> V_199 ;
} else if ( V_197 && F_57 ( V_2 ) ) {
struct V_172 * const V_32 =
V_2 -> V_162 -> V_163 -> V_200 -> V_201 ;
if ( V_32 -> V_202 ) {
V_198 = V_32 -> V_202 ( V_32 , V_192 , V_194 ) ;
V_197 = F_91 ( V_197 , V_198 ) ;
}
F_18 ( V_2 ) ;
}
return V_197 ;
}
void F_92 ( unsigned long V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_39 ;
struct V_3 * V_4 ;
struct V_203 * V_204 ;
unsigned long V_205 = 0 ;
if ( F_45 ( V_2 ) ) {
V_205 = V_2 -> V_95 -> V_206 * V_207 / 10 * V_2 -> V_95 -> V_208 ;
F_48 ( V_2 ) ;
}
if ( ! V_205 || V_2 -> V_48 . V_49 < V_209 )
return;
F_71 ( & V_2 -> V_147 ) ;
V_204 = & V_2 -> V_210 -> V_149 ;
if ( F_93 ( V_204 ) ) {
F_72 ( & V_2 -> V_147 ) ;
F_94 ( & V_2 -> V_211 , V_14 + V_205 ) ;
return;
}
V_204 = V_204 -> V_212 ;
V_4 = F_95 ( V_204 , struct V_3 , V_19 ) ;
if ( F_96 ( V_4 -> V_15 + V_205 ) ) {
if ( V_4 -> V_18 & V_60 ) {
F_20 ( V_30 , L_27 ) ;
F_79 ( F_80 ( V_2 , V_49 , V_213 ) , V_214 , NULL ) ;
} else {
F_20 ( V_30 , L_28 ) ;
F_94 ( & V_2 -> V_211 , V_14 + V_205 ) ;
}
} else {
F_94 ( & V_2 -> V_211 , V_4 -> V_15 + V_205 ) ;
}
F_72 ( & V_2 -> V_147 ) ;
}
