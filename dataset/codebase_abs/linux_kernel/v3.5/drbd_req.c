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
F_51 ( V_2 , false ) ;
F_42 ( V_4 , V_58 ) ;
break;
case V_89 :
V_4 -> V_18 |= V_85 ;
V_4 -> V_18 &= ~ V_63 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_90 :
F_14 ( V_2 , V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_85 ;
V_4 -> V_18 &= ~ V_63 ;
if ( V_4 -> V_18 & V_64 ) {
F_37 ( V_4 , V_58 ) ;
break;
}
F_51 ( V_2 , false ) ;
V_87:
F_41 ( ! ( V_4 -> V_18 & V_68 ) ) ;
if ( V_2 -> V_48 . V_91 != V_92 ) {
F_42 ( V_4 , V_58 ) ;
break;
}
V_4 -> V_18 |= V_62 ;
F_24 ( V_2 ) ;
case V_93 :
F_52 ( & V_4 -> V_67 , F_53 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_94 , & V_2 -> V_34 ) ;
F_41 ( V_4 -> V_18 & V_62 ) ;
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = ( V_4 -> V_18 & V_26 )
? V_95
: V_96 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_97 :
F_52 ( & V_4 -> V_67 , F_29 ( V_2 , V_4 -> V_23 ) ) ;
F_26 ( V_94 , & V_2 -> V_34 ) ;
F_41 ( F_23 ( V_33 , & V_2 -> V_34 ) == 0 ) ;
V_4 -> V_52 = V_2 -> V_35 -> V_53 ;
V_2 -> V_35 -> V_98 ++ ;
F_41 ( V_4 -> V_18 & V_62 ) ;
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = V_99 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
if ( V_2 -> V_35 -> V_98 >= V_2 -> V_100 -> V_101 )
F_22 ( V_2 ) ;
break;
case V_102 :
V_4 -> V_18 |= V_61 ;
V_4 -> V_36 . V_37 = V_103 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
V_4 -> V_18 &= ~ V_61 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_107 :
if ( F_2 ( V_4 -> V_12 ) == V_20 )
F_54 ( V_4 -> V_24 >> 9 , & V_2 -> V_108 ) ;
if ( F_2 ( V_4 -> V_12 ) == V_20 &&
V_2 -> V_100 -> V_109 == V_110 ) {
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
case V_111 :
V_4 -> V_18 &= ~ V_61 ;
V_4 -> V_18 |= V_54 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_112 :
if ( V_4 -> V_18 & V_62 )
F_55 ( V_2 ) ;
V_4 -> V_18 &= ~ ( V_21 | V_62 ) ;
V_4 -> V_18 |= V_54 ;
if ( V_4 -> V_18 & V_51 && V_4 -> V_18 & V_59 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_108 ) ;
if ( ! ( V_4 -> V_18 & V_61 ) )
F_37 ( V_4 , V_58 ) ;
break;
case V_113 :
if ( V_78 == V_113 )
F_31 ( V_30 , L_11
L_12 ,
( unsigned long long ) V_4 -> V_23 , V_4 -> V_24 ) ;
V_4 -> V_18 |= V_54 ;
case V_114 :
case V_115 :
if ( V_78 == V_114 )
V_4 -> V_18 |= V_25 ;
case V_116 :
V_4 -> V_18 |= V_21 ;
F_41 ( V_4 -> V_18 & V_62 ) ;
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_108 ) ;
V_4 -> V_18 &= ~ V_62 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_117 :
if ( V_4 -> V_18 & V_62 ) {
F_55 ( V_2 ) ;
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_108 ) ;
}
V_4 -> V_18 &= ~ ( V_21 | V_62 ) ;
V_4 -> V_18 |= V_54 ;
F_42 ( V_4 , V_58 ) ;
break;
case V_118 :
if ( ! ( V_4 -> V_18 & V_85 ) )
break;
F_37 ( V_4 , V_58 ) ;
break;
case V_119 :
if ( ! ( V_4 -> V_18 & V_85 ) )
break;
V_4 -> V_18 &= ~ V_85 ;
V_79 = V_120 ;
if ( F_2 ( V_4 -> V_12 ) == V_20 )
V_79 = V_121 ;
F_57 ( V_2 ) ;
V_4 -> V_36 . V_37 = V_122 ;
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
break;
case V_123 :
if ( ! ( V_4 -> V_18 & V_21 ) ) {
if ( V_4 -> V_36 . V_37 ) {
F_25 ( & V_2 -> V_39 . V_40 , & V_4 -> V_36 ) ;
V_79 = V_4 -> V_18 & V_59 ? V_121 : V_120 ;
}
break;
}
case V_124 :
if ( ! ( V_4 -> V_18 & V_59 ) )
break;
if ( V_4 -> V_18 & V_62 ) {
F_50 ( V_30 , L_13 ) ;
F_58 ( & V_4 -> V_19 , & V_2 -> V_125 ) ;
}
if ( ( V_4 -> V_18 & V_68 ) != 0 ) {
V_4 -> V_18 |= V_54 ;
if ( V_2 -> V_100 -> V_109 == V_110 )
F_56 ( V_4 -> V_24 >> 9 , & V_2 -> V_108 ) ;
}
F_37 ( V_4 , V_58 ) ;
break;
case V_126 :
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
unsigned long V_127 , V_128 ;
T_1 V_129 , V_130 ;
if ( V_2 -> V_48 . V_131 == V_92 )
return 1 ;
if ( V_2 -> V_48 . V_131 >= V_132 )
return 0 ;
if ( V_2 -> V_48 . V_131 < V_133 )
return 0 ;
V_130 = F_60 ( V_2 -> V_134 ) ;
V_129 = V_23 + ( V_24 >> 9 ) - 1 ;
F_41 ( V_23 < V_130 ) ;
F_41 ( V_129 < V_130 ) ;
V_127 = F_61 ( V_23 ) ;
V_128 = F_61 ( V_129 ) ;
return 0 == F_62 ( V_2 , V_127 , V_128 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_135 = 0 ;
if ( ! F_16 ( V_2 , V_92 ) )
return;
if ( V_2 -> V_100 -> V_136 &&
F_64 ( & V_2 -> V_108 ) >= V_2 -> V_100 -> V_136 ) {
F_65 ( V_30 , L_14 ) ;
V_135 = 1 ;
}
if ( V_2 -> V_137 -> V_138 >= V_2 -> V_100 -> V_139 ) {
F_65 ( V_30 , L_15 ) ;
V_135 = 1 ;
}
if ( V_135 ) {
F_22 ( V_2 ) ;
if ( V_2 -> V_100 -> V_140 == V_141 )
F_66 ( F_67 ( V_2 , V_49 , V_142 ) , 0 , NULL ) ;
else
F_66 ( F_67 ( V_2 , V_49 , V_143 ) , 0 , NULL ) ;
}
F_18 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_5 * V_5 , unsigned long V_15 )
{
const int V_6 = F_69 ( V_5 ) ;
const int V_24 = V_5 -> V_144 ;
const T_1 V_23 = V_5 -> V_145 ;
struct V_31 * V_32 = NULL ;
struct V_3 * V_4 ;
int V_146 , V_147 , V_148 = 0 ;
int V_149 = - V_69 ;
int V_150 = 0 ;
union V_151 V_17 ;
V_4 = F_70 ( V_2 , V_5 ) ;
if ( ! V_4 ) {
F_36 ( V_2 ) ;
F_50 ( V_30 , L_16 ) ;
F_35 ( V_5 , - V_152 ) ;
return 0 ;
}
V_4 -> V_15 = V_15 ;
V_146 = F_57 ( V_2 ) ;
if ( ! V_146 ) {
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
if ( V_6 == V_20 ) {
V_147 = 1 ;
} else {
if ( V_146 ) {
if ( ! F_59 ( V_2 , V_23 , V_24 ) ) {
V_146 = 0 ;
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_18 ( V_2 ) ;
}
}
V_147 = ! V_146 && V_2 -> V_48 . V_91 >= V_92 ;
}
if ( V_6 == V_153 && V_2 -> V_48 . V_131 >= V_133 && ! V_146 ) {
V_149 = - V_154 ;
goto V_155;
}
if ( V_6 == V_20 && V_146 && ! F_23 ( V_156 , & V_2 -> V_34 ) ) {
V_4 -> V_18 |= V_28 ;
F_72 ( V_2 , V_23 ) ;
}
V_17 = V_2 -> V_48 ;
V_147 = V_147 && F_73 ( V_17 ) ;
V_148 = V_6 == V_20 && F_74 ( V_17 ) ;
F_41 ( ! ( V_147 && V_148 ) ) ;
if ( ! ( V_146 || V_147 ) && ! F_43 ( V_2 -> V_48 ) ) {
if ( F_19 ( & V_29 ) )
F_50 ( V_30 , L_17 ) ;
goto V_157;
}
if ( V_6 == V_20 && ( V_147 || V_148 ) &&
V_2 -> V_158 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
V_159:
V_32 = F_75 ( sizeof( struct V_31 ) , V_160 ) ;
if ( ! V_32 ) {
F_50 ( V_30 , L_18 ) ;
V_149 = - V_152 ;
goto V_157;
}
}
F_76 ( & V_2 -> V_161 ) ;
if ( F_43 ( V_2 -> V_48 ) ) {
V_150 = 1 ;
F_77 ( & V_2 -> V_161 ) ;
goto V_157;
}
if ( V_147 || V_148 ) {
V_147 = F_73 ( V_2 -> V_48 ) ;
V_148 = V_6 == V_20 && F_74 ( V_2 -> V_48 ) ;
F_41 ( ! ( V_147 && V_148 ) ) ;
if ( ! ( V_147 || V_148 ) )
F_20 ( V_30 , L_19 ) ;
if ( ! ( V_146 || V_147 ) ) {
F_50 ( V_30 , L_17 ) ;
F_77 ( & V_2 -> V_161 ) ;
goto V_157;
}
}
if ( V_32 && V_2 -> V_158 == NULL ) {
V_2 -> V_158 = V_32 ;
V_32 = NULL ;
}
if ( V_6 == V_20 && ( V_147 || V_148 ) &&
V_2 -> V_158 == NULL &&
F_23 ( V_33 , & V_2 -> V_34 ) ) {
F_77 ( & V_2 -> V_161 ) ;
goto V_159;
}
F_1 ( V_2 , V_4 , V_5 ) ;
if ( ( V_147 || V_148 ) && V_2 -> V_158 &&
F_78 ( V_33 , & V_2 -> V_34 ) ) {
F_79 ( V_2 , V_2 -> V_158 ) ;
V_2 -> V_158 = NULL ;
} else {
F_41 ( ! ( V_147 && V_6 == V_20 &&
F_23 ( V_33 , & V_2 -> V_34 ) ) ) ;
}
if ( V_147 )
F_80 ( V_4 , V_80 ) ;
if ( V_146 )
F_80 ( V_4 , V_81 ) ;
if ( V_6 == V_20 && F_44 ( V_4 ) )
goto V_162;
F_81 ( & V_4 -> V_19 , & V_2 -> V_35 -> V_163 ) ;
if ( V_147 ) {
F_80 ( V_4 , ( V_6 == V_20 )
? V_97
: V_93 ) ;
}
if ( V_148 && F_14 ( V_2 , V_23 , V_24 ) )
F_80 ( V_4 , V_102 ) ;
if ( V_147 &&
V_2 -> V_100 -> V_140 != V_164 && V_2 -> V_165 >= 96 )
F_63 ( V_2 ) ;
F_77 ( & V_2 -> V_161 ) ;
F_82 ( V_32 ) ;
if ( V_146 ) {
V_4 -> V_66 -> V_166 = V_2 -> V_167 -> V_168 ;
if ( F_57 ( V_2 ) ) {
if ( F_83 ( V_2 , V_6 == V_20 ? V_169
: V_6 == V_60 ? V_170
: V_171 ) )
F_35 ( V_4 -> V_66 , - V_69 ) ;
else
F_84 ( V_4 -> V_66 ) ;
F_18 ( V_2 ) ;
} else
F_35 ( V_4 -> V_66 , - V_69 ) ;
}
return 0 ;
V_162:
F_10 ( V_2 , V_4 ) ;
F_77 ( & V_2 -> V_161 ) ;
if ( V_147 )
F_55 ( V_2 ) ;
V_149 = 0 ;
V_157:
if ( V_4 -> V_18 & V_28 )
F_17 ( V_2 , V_23 ) ;
V_155:
if ( V_146 ) {
F_71 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_18 ( V_2 ) ;
}
if ( ! V_150 )
F_35 ( V_5 , V_149 ) ;
F_21 ( V_4 ) ;
F_36 ( V_2 ) ;
F_82 ( V_32 ) ;
return V_150 ;
}
static int F_85 ( struct V_1 * V_2 , int V_172 )
{
if ( V_2 -> V_48 . V_173 != V_174 &&
( ! V_175 || V_172 ) ) {
if ( F_19 ( & V_29 ) ) {
F_50 ( V_30 , L_20
L_21
L_22 ,
V_72 -> V_73 , V_72 -> V_74 ,
V_172 ? L_23 : L_24 ) ;
}
return 1 ;
}
return 0 ;
}
void F_86 ( struct V_176 * V_177 , struct V_5 * V_5 )
{
unsigned int V_178 , V_179 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 -> V_180 ;
unsigned long V_15 ;
if ( F_85 ( V_2 , F_2 ( V_5 ) & V_20 ) ) {
F_35 ( V_5 , - V_181 ) ;
return;
}
V_15 = V_14 ;
F_41 ( V_5 -> V_144 > 0 ) ;
F_41 ( ( V_5 -> V_144 & 0x1ff ) == 0 ) ;
V_178 = V_5 -> V_145 >> V_182 ;
V_179 = ( V_5 -> V_145 + ( V_5 -> V_144 >> 9 ) - 1 ) >> V_182 ;
if ( F_87 ( V_178 == V_179 ) ) {
do {
F_88 ( V_2 , 1 ) ;
} while ( F_68 ( V_2 , V_5 , V_15 ) );
return;
}
if ( V_5 -> V_183 != 1 || V_5 -> V_184 != 0 || V_5 -> V_144 > V_185 ) {
F_50 ( V_30 , L_25
L_26 ,
V_5 -> V_183 , V_5 -> V_184 , V_5 -> V_144 ,
( unsigned long long ) V_5 -> V_145 ) ;
F_35 ( V_5 , - V_186 ) ;
} else {
struct V_187 * V_188 ;
const T_1 V_189 = V_5 -> V_145 ;
const int V_190 = 1 << V_182 ;
const int V_191 = V_190 - 1 ;
const T_1 V_192 = V_190 - ( V_189 & V_191 ) ;
V_188 = F_89 ( V_5 , V_192 ) ;
F_88 ( V_2 , 3 ) ;
F_41 ( V_179 == V_178 + 1 ) ;
while ( F_68 ( V_2 , & V_188 -> V_193 , V_15 ) )
F_88 ( V_2 , 1 ) ;
while ( F_68 ( V_2 , & V_188 -> V_194 , V_15 ) )
F_88 ( V_2 , 1 ) ;
F_36 ( V_2 ) ;
F_90 ( V_188 ) ;
}
}
int F_91 ( struct V_176 * V_177 , struct V_195 * V_196 , struct V_197 * V_198 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 -> V_180 ;
unsigned int V_199 =
( unsigned int ) V_196 -> V_145 << 9 ;
unsigned int V_200 = V_196 -> V_144 ;
int V_201 , V_202 ;
V_201 = V_185
- ( ( V_199 & ( V_185 - 1 ) ) + V_200 ) ;
if ( V_201 < 0 )
V_201 = 0 ;
if ( V_200 == 0 ) {
if ( V_201 <= V_198 -> V_203 )
V_201 = V_198 -> V_203 ;
} else if ( V_201 && F_57 ( V_2 ) ) {
struct V_176 * const V_32 =
V_2 -> V_167 -> V_168 -> V_204 -> V_205 ;
if ( V_32 -> V_206 ) {
V_202 = V_32 -> V_206 ( V_32 , V_196 , V_198 ) ;
V_201 = F_92 ( V_201 , V_202 ) ;
}
F_18 ( V_2 ) ;
}
return V_201 ;
}
void F_93 ( unsigned long V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_39 ;
struct V_3 * V_4 ;
struct V_207 * V_208 ;
unsigned long V_209 = 0 , V_210 = 0 , V_211 , V_212 ;
unsigned long V_213 ;
if ( F_45 ( V_2 ) ) {
if ( V_2 -> V_48 . V_49 >= V_214 )
V_209 = V_2 -> V_100 -> V_215 * V_216 / 10
* V_2 -> V_100 -> V_217 ;
F_48 ( V_2 ) ;
}
if ( F_57 ( V_2 ) ) {
V_210 = V_2 -> V_167 -> V_218 . V_219 * V_216 / 10 ;
F_18 ( V_2 ) ;
}
V_211 = F_94 ( V_210 , V_209 ) ;
if ( ! V_211 )
return;
V_213 = V_14 ;
F_76 ( & V_2 -> V_161 ) ;
V_208 = & V_2 -> V_220 -> V_163 ;
if ( F_95 ( V_208 ) ) {
F_77 ( & V_2 -> V_161 ) ;
F_96 ( & V_2 -> V_221 , V_213 + V_211 ) ;
return;
}
V_208 = V_208 -> V_222 ;
V_4 = F_97 ( V_208 , struct V_3 , V_19 ) ;
if ( V_209 && V_4 -> V_18 & V_62 &&
F_98 ( V_213 , V_4 -> V_15 + V_209 ) &&
! F_99 ( V_213 , V_2 -> V_223 , V_2 -> V_223 + V_209 ) ) {
F_20 ( V_30 , L_27 ) ;
F_66 ( F_67 ( V_2 , V_49 , V_224 ) , V_225 | V_226 , NULL ) ;
}
if ( V_210 && V_4 -> V_18 & V_63 &&
F_98 ( V_213 , V_4 -> V_15 + V_210 ) &&
! F_99 ( V_213 , V_2 -> V_227 , V_2 -> V_227 + V_210 ) ) {
F_20 ( V_30 , L_28 ) ;
F_51 ( V_2 , 1 ) ;
}
V_212 = ( F_98 ( V_213 , V_4 -> V_15 + V_211 ) ? V_213 : V_4 -> V_15 ) + V_211 ;
F_77 ( & V_2 -> V_161 ) ;
F_96 ( & V_2 -> V_221 , V_212 ) ;
}
