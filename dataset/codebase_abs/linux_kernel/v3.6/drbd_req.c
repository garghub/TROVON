static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
const int V_6 = F_2 ( V_5 ) ;
int V_7 ;
V_7 = F_3 () ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_10 [ V_6 ] ) ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_11 [ V_6 ] , F_7 ( V_5 ) ) ;
F_8 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_12 ) ;
unsigned long V_13 = V_14 - V_4 -> V_15 ;
int V_7 ;
V_7 = F_3 () ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_16 [ V_6 ] , V_13 ) ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_11 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_9 () ;
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
int V_6 = V_4 -> V_18 & V_59 ? V_20 : V_60 ;
if ( V_17 & V_61 )
return;
if ( V_17 & V_62 )
return;
if ( V_17 & V_63 && ! ( V_17 & V_64 ) )
return;
if ( V_4 -> V_12 ) {
int V_65 = ( V_17 & V_22 ) || ( V_17 & V_21 ) ;
int error = F_38 ( V_4 -> V_66 ) ;
if ( ! F_39 ( & V_4 -> V_67 ) )
F_40 ( & V_4 -> V_67 ) ;
else
F_41 ( ( V_17 & ( V_68 & ~ V_54 ) ) == 0 ) ;
if ( V_6 == V_20 )
F_27 ( V_2 , V_4 ) ;
F_10 ( V_2 , V_4 ) ;
V_58 -> error = V_65 ? 0 : ( error ? : - V_69 ) ;
V_58 -> V_5 = V_4 -> V_12 ;
V_4 -> V_12 = NULL ;
}
if ( V_17 & V_63 )
return;
if ( ( V_17 & V_68 ) == 0 || ( V_17 & V_54 ) ) {
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
F_41 ( F_39 ( & V_4 -> V_67 ) ) ;
if ( ! F_45 ( V_2 ) )
return 0 ;
F_46 (mdev->tl_hash_s == 0 )
goto V_70;
F_47 ( V_2 -> V_71 == NULL ) ;
#define F_28 overlaps(i->sector, i->size, sector, size)
V_47 = F_29 ( V_2 , V_23 ) ;
F_30 (i, n, slot, collision) {
if ( F_28 ) {
F_31 ( V_30 , L_5
L_6
L_7 ,
V_72 -> V_73 , V_72 -> V_74 ,
( unsigned long long ) V_23 , V_24 ,
( unsigned long long ) V_41 -> V_23 , V_41 -> V_24 ) ;
goto V_75;
}
}
if ( V_2 -> V_76 ) {
F_47 ( V_2 -> V_55 == NULL ) ;
#undef F_28
#define F_28 overlaps(e->sector, e->size, sector, size)
V_47 = F_32 ( V_2 , V_23 ) ;
F_30 (e, n, slot, collision) {
if ( F_28 ) {
F_31 ( V_30 , L_8
L_9
L_7 ,
V_72 -> V_73 , V_72 -> V_74 ,
( unsigned long long ) V_23 , V_24 ,
( unsigned long long ) V_43 -> V_23 , V_43 -> V_24 ) ;
goto V_75;
}
}
}
#undef F_28
V_70:
F_48 ( V_2 ) ;
return 0 ;
V_75:
F_48 ( V_2 ) ;
return 1 ;
}
int F_49 ( struct V_3 * V_4 , enum V_77 V_78 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 = 0 ;
V_58 -> V_5 = NULL ;
switch ( V_78 ) {
default:
F_50 ( V_30 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_80 :
F_41 ( ! ( V_4 -> V_18 & V_68 ) ) ;
V_4 -> V_18 |= V_62 ;
F_24 ( V_2 ) ;
break;
case V_81 :
F_41 ( ! ( V_4 -> V_18 & V_26 ) ) ;
V_4 -> V_18 |= V_63 ;
break;
case V_82 :
if ( V_4 -> V_18 & V_59 )
V_2 -> V_83 += V_4 -> V_24 >> 9 ;
else
V_2 -> V_84 += V_4 -> V_24 >> 9 ;
V_4 -> V_18 |= ( V_85 | V_22 ) ;
V_4 -> V_18 &= ~ V_63 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_86 :
V_4 -> V_18 |= V_64 ;
if ( V_4 -> V_18 & V_59 )
F_42 ( V_4 , V_58 ) ;
else
goto V_87;
break;
case V_88 :
V_4 -> V_18 |= V_85 ;
V_4 -> V_18 &= ~ V_63 ;
F_51 ( V_2 , V_89 ) ;
F_42 ( V_4 , V_58 ) ;
break;
case V_90 :
V_4 -> V_18 |= V_85 ;
V_4 -> V_18 &= ~ V_63 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_91 :
F_14 ( V_2 , V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_85 ;
V_4 -> V_18 &= ~ V_63 ;
if ( V_4 -> V_18 & V_64 ) {
F_37 ( V_4 , V_58 ) ;
break;
}
F_51 ( V_2 , V_89 ) ;
V_87:
F_41 ( ! ( V_4 -> V_18 & V_68 ) ) ;
if ( V_2 -> V_48 . V_92 != V_93 ) {
F_42 ( V_4 , V_58 ) ;
break;
}
V_4 -> V_18 |= V_62 ;
F_24 ( V_2 ) ;
case V_94 :
F_52 ( & V_4 -> V_67 , F_53 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_95 , & V_2 -> V_34 ) ;
F_41 ( V_4 -> V_18 & V_62 ) ;
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = ( V_4 -> V_18 & V_26 )
? V_96
: V_97 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_98 :
F_52 ( & V_4 -> V_67 , F_29 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_95 , & V_2 -> V_34 ) ;
F_41 ( F_23 ( V_33 , & V_2 -> V_34 ) == 0 ) ;
V_4 -> V_52 = V_2 -> V_35 -> V_53 ;
V_2 -> V_35 -> V_99 ++ ;
F_41 ( V_4 -> V_18 & V_62 ) ;
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = V_100 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
if ( V_2 -> V_35 -> V_99 >= V_2 -> V_101 -> V_102 )
F_22 ( V_2 ) ;
break;
case V_103 :
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = V_104 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_105 :
case V_106 :
case V_107 :
V_4 -> V_18 &= ~ V_61 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_108 :
if ( F_2 ( V_4 -> V_12 ) == V_20 )
F_54 ( V_4 -> V_24 >> 9 , & V_2 -> V_109 ) ;
if ( F_2 ( V_4 -> V_12 ) == V_20 &&
V_2 -> V_101 -> V_110 == V_111 ) {
if ( V_4 -> V_18 & V_62 ) {
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ V_62 ;
V_4 -> V_18 |= V_21 ;
}
}
V_4 -> V_18 &= ~ V_61 ;
V_4 -> V_18 |= V_51 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_112 :
V_4 -> V_18 &= ~ V_61 ;
V_4 -> V_18 |= V_54 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_113 :
if ( V_4 -> V_18 & V_62 )
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ ( V_21 | V_62 ) ;
V_4 -> V_18 |= V_54 ;
if ( V_4 -> V_18 & V_51 && V_4 -> V_18 & V_59 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_109 ) ;
if ( ! ( V_4 -> V_18 & V_61 ) )
F_37 ( V_4 , V_58 ) ;
break;
case V_114 :
if ( V_78 == V_114 )
F_31 ( V_30 , L_11
L_12 ,
( unsigned long long ) V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_54 ;
case V_115 :
case V_116 :
if ( V_78 == V_115 )
V_4 -> V_18 |= V_25 ;
case V_117 :
V_4 -> V_18 |= V_21 ;
F_41 ( V_4 -> V_18 & V_62 ) ;
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_109 ) ;
V_4 -> V_18 &= ~ V_62 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_118 :
if ( V_4 -> V_18 & V_62 ) {
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_109 ) ;
}
V_4 -> V_18 &= ~ ( V_21 | V_62 ) ;
V_4 -> V_18 |= V_54 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_119 :
if ( ! ( V_4 -> V_18 & V_85 ) )
break;
F_37 ( V_4 , V_58 ) ;
break;
case V_120 :
if ( ! ( V_4 -> V_18 & V_85 ) )
break;
V_4 -> V_18 &= ~ V_85 ;
V_79 = V_121 ;
if ( F_2 ( V_4 -> V_12 ) == V_20 )
V_79 = V_122 ;
F_57 ( V_2 ) ;
V_4 -> V_36 . V_37 = V_123 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_124 :
if ( ! ( V_4 -> V_18 & V_59 ) && ! V_4 -> V_36 . V_37 ) {
F_37 ( V_4 , V_58 ) ;
break;
}
if ( ! ( V_4 -> V_18 & V_21 ) ) {
if ( V_4 -> V_36 . V_37 ) {
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
V_79 = V_4 -> V_18 & V_59 ? V_122 : V_121 ;
}
break;
}
case V_125 :
if ( ! ( V_4 -> V_18 & V_59 ) )
break;
if ( V_4 -> V_18 & V_62 ) {
F_50 ( V_30 , L_13 ) ;
F_58 ( & V_4 -> V_19 , & V_2 -> V_126 ) ;
}
if ( ( V_4 -> V_18 & V_68 ) != 0 ) {
V_4 -> V_18 |= V_54 ;
if ( V_2 -> V_101 -> V_110 == V_111 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_109 ) ;
}
F_37 ( V_4 , V_58 ) ;
break;
case V_127 :
F_41 ( V_4 -> V_18 & V_62 ) ;
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ V_62 ;
V_4 -> V_18 |= ( V_21 | V_54 ) ;
F_42 ( V_4 , V_58 ) ;
break;
} ;
return V_79 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_23 , int V_24 )
{
unsigned long V_128 , V_129 ;
T_1 V_130 , V_131 ;
if ( V_2 -> V_48 . V_132 == V_93 )
return 1 ;
if ( V_2 -> V_48 . V_132 >= V_133 )
return 0 ;
if ( V_2 -> V_48 . V_132 < V_134 )
return 0 ;
V_131 = F_60 ( V_2 -> V_135 ) ;
V_130 = V_23 + ( V_24 >> 9 ) - 1 ;
F_41 ( V_23 < V_131 ) ;
F_41 ( V_130 < V_131 ) ;
V_128 = F_61 ( V_23 ) ;
V_129 = F_61 ( V_130 ) ;
return 0 == F_62 ( V_2 , V_128 , V_129 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! F_16 ( V_2 , V_93 ) )
return;
if ( V_2 -> V_101 -> V_137 &&
F_64 ( & V_2 -> V_109 ) >= V_2 -> V_101 -> V_137 ) {
F_65 ( V_30 , L_14 ) ;
V_136 = 1 ;
}
if ( V_2 -> V_138 -> V_139 >= V_2 -> V_101 -> V_140 ) {
F_65 ( V_30 , L_15 ) ;
V_136 = 1 ;
}
if ( V_136 ) {
F_22 ( V_2 ) ;
if ( V_2 -> V_101 -> V_141 == V_142 )
F_66 ( F_67 ( V_2 , V_49 , V_143 ) , 0 , NULL ) ;
else
F_66 ( F_67 ( V_2 , V_49 , V_144 ) , 0 , NULL ) ;
}
F_18 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_5 * V_5 , unsigned long V_15 )
{
const int V_6 = F_69 ( V_5 ) ;
const int V_24 = V_5 -> V_145 ;
const T_1 V_23 = V_5 -> V_146 ;
struct V_31 * V_32 = NULL ;
struct V_3 * V_4 ;
int V_147 , V_148 , V_149 = 0 ;
int V_150 = - V_69 ;
int V_151 = 0 ;
union V_152 V_17 ;
V_4 = F_70 ( V_2 , V_5 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_50 ( V_30 , L_16 ) ;
F_35 ( V_5 , - V_153 ) ;
return 0 ;
}
V_4 -> V_15 = V_15 ;
V_147 = F_57 ( V_2 ) ;
if ( ! V_147 ) {
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
if ( V_6 == V_20 ) {
if ( F_72 ( V_24 == 0 ) ) {
F_41 ( V_5 -> V_154 & V_155 ) ;
V_148 = 0 ;
} else
V_148 = 1 ;
} else {
if ( V_147 ) {
if ( ! F_59 ( V_2 , V_23 , V_24 ) ) {
V_147 = 0 ;
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_18 ( V_2 ) ;
}
}
V_148 = ! V_147 && V_2 -> V_48 . V_92 >= V_93 ;
}
if ( V_6 == V_156 && V_2 -> V_48 . V_132 >= V_134 && ! V_147 ) {
V_150 = - V_157 ;
goto V_158;
}
if ( V_6 == V_20 && V_147 && V_24
&& ! F_23 ( V_159 , & V_2 -> V_34 ) ) {
V_4 -> V_18 |= V_28 ;
F_73 ( V_2 , V_23 ) ;
}
V_17 = V_2 -> V_48 ;
V_148 = V_148 && F_74 ( V_17 ) ;
V_149 = V_6 == V_20 && F_75 ( V_17 ) ;
F_41 ( ! ( V_148 && V_149 ) ) ;
if ( ! ( V_147 || V_148 ) && ! F_43 ( V_2 -> V_48 ) ) {
if ( F_19 ( & V_29 ) )
F_50 ( V_30 , L_17 ) ;
goto V_160;
}
if ( V_6 == V_20 && ( V_148 || V_149 ) &&
V_2 -> V_161 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
V_162:
V_32 = F_76 ( sizeof( struct V_31 ) , V_163 ) ;
if ( ! V_32 ) {
F_50 ( V_30 , L_18 ) ;
V_150 = - V_153 ;
goto V_160;
}
}
F_77 ( & V_2 -> V_164 ) ;
if ( F_43 ( V_2 -> V_48 ) ) {
V_151 = 1 ;
F_78 ( & V_2 -> V_164 ) ;
goto V_160;
}
if ( V_148 || V_149 ) {
V_148 = F_74 ( V_2 -> V_48 ) ;
V_149 = V_6 == V_20 && F_75 ( V_2 -> V_48 ) ;
F_41 ( ! ( V_148 && V_149 ) ) ;
if ( ! ( V_148 || V_149 ) )
F_20 ( V_30 , L_19 ) ;
if ( ! ( V_147 || V_148 ) ) {
F_50 ( V_30 , L_17 ) ;
F_78 ( & V_2 -> V_164 ) ;
goto V_160;
}
}
if ( V_32 && V_2 -> V_161 == NULL ) {
V_2 -> V_161 = V_32 ;
V_32 = NULL ;
}
if ( V_6 == V_20 && ( V_148 || V_149 ) &&
V_2 -> V_161 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
F_78 ( & V_2 -> V_164 ) ;
goto V_162;
}
F_1 ( V_2 , V_4 , V_5 ) ;
if ( ( V_148 || V_149 ) && V_2 -> V_161 &&
F_79 ( V_33 , & V_2 -> V_34 ) ) {
F_80 ( V_2 , V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
} else {
F_41 ( ! ( V_148 && V_6 == V_20 &&
F_23 ( V_33 , & V_2 -> V_34 ) ) ) ;
}
if ( V_148 )
F_81 ( V_4 , V_80 ) ;
if ( V_147 )
F_81 ( V_4 , V_81 ) ;
if ( V_6 == V_20 && F_44 ( V_4 ) )
goto V_165;
if ( F_82 ( V_24 != 0 ) )
F_83 ( & V_4 -> V_19 , & V_2 -> V_35 -> V_166 ) ;
if ( V_148 ) {
F_81 ( V_4 , ( V_6 == V_20 )
? V_98
: V_94 ) ;
}
if ( V_149 && F_14 ( V_2 , V_23 , V_24 ) )
F_81 ( V_4 , V_103 ) ;
if ( V_148 &&
V_2 -> V_101 -> V_141 != V_167 && V_2 -> V_168 >= 96 )
F_63 ( V_2 ) ;
if ( F_72 ( V_5 -> V_154 & V_155 )
&& V_2 -> V_35 -> V_99
&& F_74 ( V_2 -> V_48 ) )
F_22 ( V_2 ) ;
F_78 ( & V_2 -> V_164 ) ;
F_84 ( V_32 ) ;
if ( V_147 ) {
V_4 -> V_66 -> V_169 = V_2 -> V_170 -> V_171 ;
if ( F_57 ( V_2 ) ) {
if ( F_85 ( V_2 , V_6 == V_20 ? V_172
: V_6 == V_60 ? V_173
: V_174 ) )
F_35 ( V_4 -> V_66 , - V_69 ) ;
else
F_86 ( V_4 -> V_66 ) ;
F_18 ( V_2 ) ;
} else
F_35 ( V_4 -> V_66 , - V_69 ) ;
}
return 0 ;
V_165:
F_10 ( V_2 , V_4 ) ;
F_78 ( & V_2 -> V_164 ) ;
if ( V_148 )
F_55 ( V_2 ) ;
V_150 = 0 ;
V_160:
if ( V_4 -> V_18 & V_28 )
F_17 ( V_2 , V_23 ) ;
V_158:
if ( V_147 ) {
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_18 ( V_2 ) ;
}
if ( ! V_151 )
F_35 ( V_5 , V_150 ) ;
F_21 ( V_4 ) ;
F_36 ( V_2 ) ;
F_84 ( V_32 ) ;
return V_151 ;
}
static int F_87 ( struct V_1 * V_2 , int V_175 )
{
if ( V_2 -> V_48 . V_176 != V_177 &&
( ! V_178 || V_175 ) ) {
if ( F_19 ( & V_29 ) ) {
F_50 ( V_30 , L_20
L_21
L_22 ,
V_72 -> V_73 , V_72 -> V_74 ,
V_175 ? L_23 : L_24 ) ;
}
return 1 ;
}
return 0 ;
}
void F_88 ( struct V_179 * V_180 , struct V_5 * V_5 )
{
unsigned int V_181 , V_182 ;
struct V_1 * V_2 = (struct V_1 * ) V_180 -> V_183 ;
unsigned long V_15 ;
if ( F_87 ( V_2 , F_2 ( V_5 ) & V_20 ) ) {
F_35 ( V_5 , - V_184 ) ;
return;
}
V_15 = V_14 ;
F_41 ( ( V_5 -> V_145 & 0x1ff ) == 0 ) ;
V_181 = V_5 -> V_146 >> V_185 ;
V_182 = V_5 -> V_145 ? ( V_5 -> V_146 + ( V_5 -> V_145 >> 9 ) - 1 ) >> V_185 : V_181 ;
if ( F_82 ( V_181 == V_182 ) ) {
do {
F_89 ( V_2 , 1 ) ;
} while ( F_68 ( V_2 , V_5 , V_15 ) );
return;
}
if ( V_5 -> V_186 != 1 || V_5 -> V_187 != 0 || V_5 -> V_145 > V_188 ) {
F_50 ( V_30 , L_25
L_26 ,
V_5 -> V_186 , V_5 -> V_187 , V_5 -> V_145 ,
( unsigned long long ) V_5 -> V_146 ) ;
F_35 ( V_5 , - V_189 ) ;
} else {
struct V_190 * V_191 ;
const T_1 V_192 = V_5 -> V_146 ;
const int V_193 = 1 << V_185 ;
const int V_194 = V_193 - 1 ;
const T_1 V_195 = V_193 - ( V_192 & V_194 ) ;
V_191 = F_90 ( V_5 , V_195 ) ;
F_89 ( V_2 , 3 ) ;
F_41 ( V_182 == V_181 + 1 ) ;
while ( F_68 ( V_2 , & V_191 -> V_196 , V_15 ) )
F_89 ( V_2 , 1 ) ;
while ( F_68 ( V_2 , & V_191 -> V_197 , V_15 ) )
F_89 ( V_2 , 1 ) ;
F_36 ( V_2 ) ;
F_91 ( V_191 ) ;
}
}
int F_92 ( struct V_179 * V_180 , struct V_198 * V_199 , struct V_200 * V_201 )
{
struct V_1 * V_2 = (struct V_1 * ) V_180 -> V_183 ;
unsigned int V_202 =
( unsigned int ) V_199 -> V_146 << 9 ;
unsigned int V_203 = V_199 -> V_145 ;
int V_204 , V_205 ;
V_204 = V_188
- ( ( V_202 & ( V_188 - 1 ) ) + V_203 ) ;
if ( V_204 < 0 )
V_204 = 0 ;
if ( V_203 == 0 ) {
if ( V_204 <= V_201 -> V_206 )
V_204 = V_201 -> V_206 ;
} else if ( V_204 && F_57 ( V_2 ) ) {
struct V_179 * const V_32 =
V_2 -> V_170 -> V_171 -> V_207 -> V_208 ;
if ( V_32 -> V_209 ) {
V_205 = V_32 -> V_209 ( V_32 , V_199 , V_201 ) ;
V_204 = F_93 ( V_204 , V_205 ) ;
}
F_18 ( V_2 ) ;
}
return V_204 ;
}
void F_94 ( unsigned long V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_39 ;
struct V_3 * V_4 ;
struct V_210 * V_211 ;
unsigned long V_212 = 0 , V_213 = 0 , V_214 , V_215 ;
unsigned long V_216 ;
if ( F_45 ( V_2 ) ) {
if ( V_2 -> V_48 . V_49 >= V_217 )
V_212 = V_2 -> V_101 -> V_218 * V_219 / 10
* V_2 -> V_101 -> V_220 ;
F_48 ( V_2 ) ;
}
if ( F_57 ( V_2 ) ) {
V_213 = V_2 -> V_170 -> V_221 . V_222 * V_219 / 10 ;
F_18 ( V_2 ) ;
}
V_214 = F_95 ( V_213 , V_212 ) ;
if ( ! V_214 )
return;
V_216 = V_14 ;
F_77 ( & V_2 -> V_164 ) ;
V_211 = & V_2 -> V_223 -> V_166 ;
if ( F_96 ( V_211 ) ) {
F_78 ( & V_2 -> V_164 ) ;
F_97 ( & V_2 -> V_224 , V_216 + V_214 ) ;
return;
}
V_211 = V_211 -> V_225 ;
V_4 = F_98 ( V_211 , struct V_3 , V_19 ) ;
if ( V_212 && V_4 -> V_18 & V_62 &&
F_99 ( V_216 , V_4 -> V_15 + V_212 ) &&
! F_100 ( V_216 , V_2 -> V_226 , V_2 -> V_226 + V_212 ) ) {
F_20 ( V_30 , L_27 ) ;
F_66 ( F_67 ( V_2 , V_49 , V_227 ) , V_228 | V_229 , NULL ) ;
}
if ( V_213 && V_4 -> V_18 & V_63 &&
F_99 ( V_216 , V_4 -> V_15 + V_213 ) &&
! F_100 ( V_216 , V_2 -> V_230 , V_2 -> V_230 + V_213 ) ) {
F_20 ( V_30 , L_28 ) ;
F_51 ( V_2 , V_231 ) ;
}
V_215 = ( F_99 ( V_216 , V_4 -> V_15 + V_214 ) ? V_216 : V_4 -> V_15 ) + V_214 ;
F_78 ( & V_2 -> V_164 ) ;
F_97 ( & V_2 -> V_224 , V_215 ) ;
}
