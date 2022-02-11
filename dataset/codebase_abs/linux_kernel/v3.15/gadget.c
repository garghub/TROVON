int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_4 |= V_3 << 1 ;
break;
default:
return - V_13 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
return F_5 ( V_4 ) ;
}
int F_6 ( struct V_1 * V_2 , enum V_15 V_16 )
{
int V_17 = 10000 ;
T_1 V_4 ;
if ( V_2 -> V_18 >= V_19 ) {
while ( -- V_17 ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( V_4 & V_20 )
F_7 ( 5 ) ;
else
break;
}
if ( V_17 <= 0 )
return - V_21 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
V_4 |= F_8 ( V_16 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
if ( V_2 -> V_18 >= V_19 )
return 0 ;
V_17 = 10000 ;
while ( -- V_17 ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( F_5 ( V_4 ) == V_16 )
return 0 ;
F_7 ( 5 ) ;
}
F_9 ( V_2 -> V_23 , L_1 ) ;
return - V_21 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
if ( ! V_2 -> V_29 )
return 0 ;
V_25 = F_11 ( V_2 -> V_30 . V_31 ) ;
V_27 = F_12 ( V_2 -> V_30 . V_32 ) ;
V_27 >>= 3 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_33 ; V_28 ++ ) {
struct V_34 * V_35 = V_2 -> V_36 [ ( V_28 << 1 ) | 1 ] ;
int V_37 = 1 ;
int V_38 ;
if ( ! ( V_35 -> V_39 & V_40 ) )
continue;
if ( F_13 ( V_35 -> V_41 . V_42 )
|| F_14 ( V_35 -> V_41 . V_42 ) )
V_37 = 3 ;
V_38 = V_37 * ( V_35 -> V_41 . V_43 + V_27 ) ;
V_38 += V_27 ;
V_26 = F_15 ( V_38 , V_27 ) ;
V_26 |= ( V_24 << 16 ) ;
F_9 ( V_2 -> V_23 , L_2 ,
V_35 -> V_44 , V_24 , V_26 & 0xffff ) ;
F_3 ( V_2 -> V_5 , F_16 ( V_28 ) , V_26 ) ;
V_24 += ( V_26 & 0xffff ) ;
}
return 0 ;
}
void F_17 ( struct V_34 * V_35 , struct V_45 * V_46 ,
int V_47 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_48 ;
if ( V_46 -> V_49 ) {
V_48 = 0 ;
do {
V_35 -> V_50 ++ ;
if ( ( ( V_35 -> V_50 & V_51 ) ==
V_52 - 1 ) &&
F_14 ( V_35 -> V_41 . V_42 ) )
V_35 -> V_50 ++ ;
} while( ++ V_48 < V_46 -> V_53 . V_54 );
V_46 -> V_49 = false ;
}
F_18 ( & V_46 -> V_55 ) ;
V_46 -> V_56 = NULL ;
if ( V_46 -> V_53 . V_47 == - V_57 )
V_46 -> V_53 . V_47 = V_47 ;
if ( V_2 -> V_58 && V_35 -> V_59 == 0 )
V_2 -> V_58 = false ;
else
F_19 ( & V_2 -> V_60 , & V_46 -> V_53 ,
V_46 -> V_61 ) ;
F_20 ( V_2 -> V_23 , L_3 ,
V_46 , V_35 -> V_44 , V_46 -> V_53 . V_62 ,
V_46 -> V_53 . V_63 , V_47 ) ;
F_21 ( & V_2 -> V_64 ) ;
V_46 -> V_53 . V_65 ( & V_35 -> V_41 , & V_46 -> V_53 ) ;
F_22 ( & V_2 -> V_64 ) ;
}
static const char * F_23 ( T_2 V_66 )
{
switch ( V_66 ) {
case V_67 :
return L_4 ;
case V_68 :
return L_5 ;
case V_69 :
return L_6 ;
case V_70 :
return L_7 ;
case V_71 :
return L_8 ;
case V_72 :
return L_9 ;
case V_73 :
return L_10 ;
case V_74 :
return L_11 ;
case V_75 :
return L_12 ;
default:
return L_13 ;
}
}
int F_24 ( struct V_1 * V_2 , int V_66 , T_1 V_76 )
{
T_1 V_77 = 500 ;
T_1 V_4 ;
F_3 ( V_2 -> V_5 , V_78 , V_76 ) ;
F_3 ( V_2 -> V_5 , V_79 , V_66 | V_80 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_79 ) ;
if ( ! ( V_4 & V_80 ) ) {
F_9 ( V_2 -> V_23 , L_14 ,
F_25 ( V_4 ) ) ;
return 0 ;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_7 ( 1 ) ;
} while ( 1 );
}
int F_26 ( struct V_1 * V_2 , unsigned V_81 ,
unsigned V_66 , struct V_82 * V_83 )
{
struct V_34 * V_35 = V_2 -> V_36 [ V_81 ] ;
T_1 V_77 = 500 ;
T_1 V_4 ;
F_9 ( V_2 -> V_23 , L_15 ,
V_35 -> V_44 ,
F_23 ( V_66 ) , V_83 -> V_84 ,
V_83 -> V_85 , V_83 -> V_86 ) ;
F_3 ( V_2 -> V_5 , F_27 ( V_81 ) , V_83 -> V_84 ) ;
F_3 ( V_2 -> V_5 , F_28 ( V_81 ) , V_83 -> V_85 ) ;
F_3 ( V_2 -> V_5 , F_29 ( V_81 ) , V_83 -> V_86 ) ;
F_3 ( V_2 -> V_5 , F_30 ( V_81 ) , V_66 | V_87 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , F_30 ( V_81 ) ) ;
if ( ! ( V_4 & V_87 ) ) {
F_9 ( V_2 -> V_23 , L_14 ,
F_31 ( V_4 ) ) ;
return 0 ;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_7 ( 1 ) ;
} while ( 1 );
}
static T_3 F_32 ( struct V_34 * V_35 ,
struct V_88 * V_56 )
{
T_1 V_89 = ( char * ) V_56 - ( char * ) V_35 -> V_90 ;
return V_35 -> V_91 + V_89 ;
}
static int F_33 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_35 -> V_90 )
return 0 ;
if ( V_35 -> V_59 == 0 || V_35 -> V_59 == 1 )
return 0 ;
V_35 -> V_90 = F_34 ( V_2 -> V_23 ,
sizeof( struct V_88 ) * V_52 ,
& V_35 -> V_91 , V_92 ) ;
if ( ! V_35 -> V_90 ) {
F_35 ( V_35 -> V_2 -> V_23 , L_16 ,
V_35 -> V_44 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_36 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_37 ( V_2 -> V_23 , sizeof( struct V_88 ) * V_52 ,
V_35 -> V_90 , V_35 -> V_91 ) ;
V_35 -> V_90 = NULL ;
V_35 -> V_91 = 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_82 V_83 ;
T_1 V_66 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
if ( V_35 -> V_59 != 1 ) {
V_66 = V_67 ;
if ( V_35 -> V_59 > 1 ) {
if ( V_2 -> V_94 )
return 0 ;
V_2 -> V_94 = true ;
V_66 |= F_39 ( 2 ) ;
}
return F_26 ( V_2 , 0 , V_66 , & V_83 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_95 * V_42 ,
const struct V_96 * V_97 ,
bool V_98 , bool V_99 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_41 ( F_42 ( V_42 ) )
| F_43 ( F_44 ( V_42 ) ) ;
if ( V_2 -> V_60 . V_100 == V_101 ) {
T_1 V_102 = V_35 -> V_41 . V_103 - 1 ;
V_83 . V_84 |= F_45 ( V_102 ) ;
}
if ( V_98 )
V_83 . V_84 |= V_104 ;
if ( V_99 ) {
V_83 . V_84 |= V_105 ;
V_83 . V_86 |= V_35 -> V_106 ;
}
V_83 . V_85 = V_107
| V_108 ;
if ( F_46 ( V_97 ) && F_13 ( V_42 ) ) {
V_83 . V_85 |= V_109
| V_110 ;
V_35 -> V_111 = true ;
}
if ( F_14 ( V_42 ) )
V_83 . V_85 |= V_112 ;
V_83 . V_85 |= F_47 ( V_35 -> V_59 ) ;
if ( V_35 -> V_61 )
V_83 . V_84 |= F_48 ( V_35 -> V_59 >> 1 ) ;
if ( V_42 -> V_113 ) {
V_83 . V_85 |= F_49 ( V_42 -> V_113 - 1 ) ;
V_35 -> V_114 = 1 << ( V_42 -> V_113 - 1 ) ;
}
return F_26 ( V_2 , V_35 -> V_59 ,
V_75 , & V_83 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_51 ( 1 ) ;
return F_26 ( V_2 , V_35 -> V_59 ,
V_74 , & V_83 ) ;
}
static int F_52 ( struct V_34 * V_35 ,
const struct V_95 * V_42 ,
const struct V_96 * V_97 ,
bool V_98 , bool V_99 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
int V_115 = - V_93 ;
F_9 ( V_2 -> V_23 , L_17 , V_35 -> V_44 ) ;
if ( ! ( V_35 -> V_39 & V_40 ) ) {
V_115 = F_38 ( V_2 , V_35 ) ;
if ( V_115 )
return V_115 ;
}
V_115 = F_40 ( V_2 , V_35 , V_42 , V_97 , V_98 ,
V_99 ) ;
if ( V_115 )
return V_115 ;
if ( ! ( V_35 -> V_39 & V_40 ) ) {
struct V_88 * V_116 ;
struct V_88 * V_117 ;
V_115 = F_50 ( V_2 , V_35 ) ;
if ( V_115 )
return V_115 ;
V_35 -> V_41 . V_42 = V_42 ;
V_35 -> V_97 = V_97 ;
V_35 -> type = F_42 ( V_42 ) ;
V_35 -> V_39 |= V_40 ;
V_4 = F_2 ( V_2 -> V_5 , V_118 ) ;
V_4 |= F_53 ( V_35 -> V_59 ) ;
F_3 ( V_2 -> V_5 , V_118 , V_4 ) ;
if ( ! F_14 ( V_42 ) )
return 0 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_116 = & V_35 -> V_90 [ 0 ] ;
V_117 = & V_35 -> V_90 [ V_52 - 1 ] ;
V_117 -> V_119 = F_54 ( F_32 ( V_35 , V_116 ) ) ;
V_117 -> V_120 = F_55 ( F_32 ( V_35 , V_116 ) ) ;
V_117 -> V_121 |= V_122 ;
V_117 -> V_121 |= V_123 ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_45 * V_46 ;
if ( ! F_57 ( & V_35 -> V_124 ) ) {
F_58 ( V_2 , V_35 -> V_59 , true ) ;
while ( ! F_57 ( & V_35 -> V_124 ) ) {
V_46 = F_59 ( & V_35 -> V_124 ) ;
F_17 ( V_35 , V_46 , - V_125 ) ;
}
}
while ( ! F_57 ( & V_35 -> V_126 ) ) {
V_46 = F_59 ( & V_35 -> V_126 ) ;
F_17 ( V_35 , V_46 , - V_125 ) ;
}
}
static int F_60 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
F_56 ( V_2 , V_35 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_118 ) ;
V_4 &= ~ F_53 ( V_35 -> V_59 ) ;
F_3 ( V_2 -> V_5 , V_118 , V_4 ) ;
V_35 -> V_111 = false ;
V_35 -> V_41 . V_42 = NULL ;
V_35 -> V_97 = NULL ;
V_35 -> type = 0 ;
V_35 -> V_39 = 0 ;
return 0 ;
}
static int F_61 ( struct V_127 * V_81 ,
const struct V_95 * V_42 )
{
return - V_13 ;
}
static int F_62 ( struct V_127 * V_81 )
{
return - V_13 ;
}
static int F_63 ( struct V_127 * V_81 ,
const struct V_95 * V_42 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_39 ;
int V_115 ;
if ( ! V_81 || ! V_42 || V_42 -> V_128 != V_129 ) {
F_64 ( L_18 ) ;
return - V_13 ;
}
if ( ! V_42 -> V_130 ) {
F_64 ( L_19 ) ;
return - V_13 ;
}
V_35 = F_65 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
if ( V_35 -> V_39 & V_40 ) {
F_66 ( V_2 -> V_23 , true , L_20 ,
V_35 -> V_44 ) ;
return 0 ;
}
switch ( F_42 ( V_42 ) ) {
case V_131 :
F_67 ( V_35 -> V_44 , L_21 , sizeof( V_35 -> V_44 ) ) ;
break;
case V_132 :
F_67 ( V_35 -> V_44 , L_22 , sizeof( V_35 -> V_44 ) ) ;
break;
case V_133 :
F_67 ( V_35 -> V_44 , L_23 , sizeof( V_35 -> V_44 ) ) ;
break;
case V_134 :
F_67 ( V_35 -> V_44 , L_24 , sizeof( V_35 -> V_44 ) ) ;
break;
default:
F_35 ( V_2 -> V_23 , L_25 ) ;
}
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_115 = F_52 ( V_35 , V_42 , V_81 -> V_97 , false , false ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static int F_70 ( struct V_127 * V_81 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_39 ;
int V_115 ;
if ( ! V_81 ) {
F_64 ( L_18 ) ;
return - V_13 ;
}
V_35 = F_65 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
if ( ! ( V_35 -> V_39 & V_40 ) ) {
F_66 ( V_2 -> V_23 , true , L_26 ,
V_35 -> V_44 ) ;
return 0 ;
}
snprintf ( V_35 -> V_44 , sizeof( V_35 -> V_44 ) , L_27 ,
V_35 -> V_59 >> 1 ,
( V_35 -> V_59 & 1 ) ? L_28 : L_29 ) ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_115 = F_60 ( V_35 ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static struct V_135 * F_71 ( struct V_127 * V_81 ,
T_4 V_136 )
{
struct V_45 * V_46 ;
struct V_34 * V_35 = F_65 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
V_46 = F_72 ( sizeof( * V_46 ) , V_136 ) ;
if ( ! V_46 ) {
F_35 ( V_2 -> V_23 , L_30 ) ;
return NULL ;
}
V_46 -> V_137 = V_35 -> V_59 ;
V_46 -> V_35 = V_35 ;
return & V_46 -> V_53 ;
}
static void F_73 ( struct V_127 * V_81 ,
struct V_135 * V_53 )
{
struct V_45 * V_46 = F_74 ( V_53 ) ;
F_75 ( V_46 ) ;
}
static void F_76 ( struct V_34 * V_35 ,
struct V_45 * V_46 , T_3 V_138 ,
unsigned V_63 , unsigned V_139 , unsigned V_140 , unsigned V_141 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_88 * V_56 ;
F_9 ( V_2 -> V_23 , L_31 ,
V_35 -> V_44 , V_46 , ( unsigned long long ) V_138 ,
V_63 , V_139 ? L_32 : L_33 ,
V_140 ? L_34 : L_33 ) ;
if ( ( ( V_35 -> V_142 & V_51 ) == V_52 - 1 ) &&
F_14 ( V_35 -> V_41 . V_42 ) )
V_35 -> V_142 ++ ;
V_56 = & V_35 -> V_90 [ V_35 -> V_142 & V_51 ] ;
if ( ! V_46 -> V_56 ) {
F_77 ( V_46 ) ;
V_46 -> V_56 = V_56 ;
V_46 -> V_143 = F_32 ( V_35 , V_56 ) ;
V_46 -> V_144 = V_35 -> V_142 & V_51 ;
}
V_35 -> V_142 ++ ;
V_56 -> V_145 = F_78 ( V_63 ) ;
V_56 -> V_119 = F_54 ( V_138 ) ;
V_56 -> V_120 = F_55 ( V_138 ) ;
switch ( F_42 ( V_35 -> V_41 . V_42 ) ) {
case V_131 :
V_56 -> V_121 = V_146 ;
break;
case V_132 :
if ( ! V_141 )
V_56 -> V_121 = V_147 ;
else
V_56 -> V_121 = V_148 ;
break;
case V_133 :
case V_134 :
V_56 -> V_121 = V_149 ;
break;
default:
F_79 () ;
}
if ( ! V_46 -> V_53 . V_150 && ! V_140 )
V_56 -> V_121 |= V_151 ;
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
V_56 -> V_121 |= V_152 ;
V_56 -> V_121 |= V_153 ;
} else if ( V_139 ) {
V_56 -> V_121 |= V_154 ;
}
if ( V_140 )
V_56 -> V_121 |= V_155 ;
if ( F_13 ( V_35 -> V_41 . V_42 ) && V_35 -> V_111 )
V_56 -> V_121 |= F_80 ( V_46 -> V_53 . V_156 ) ;
V_56 -> V_121 |= V_123 ;
}
static void F_81 ( struct V_34 * V_35 , bool V_157 )
{
struct V_45 * V_46 , * V_158 ;
T_1 V_159 ;
T_1 V_160 ;
unsigned int V_161 = 0 ;
F_82 ( V_52 ) ;
V_159 = ( V_35 -> V_50 - V_35 -> V_142 ) & V_51 ;
if ( ! F_14 ( V_35 -> V_41 . V_42 ) ) {
V_160 = V_52 - ( V_35 -> V_142 & V_51 ) ;
if ( V_159 > V_160 )
V_159 = V_160 ;
}
if ( ! V_159 ) {
if ( ! V_157 )
return;
V_159 = V_52 ;
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
V_35 -> V_50 = 1 ;
V_35 -> V_142 = 1 ;
} else {
V_35 -> V_50 = 0 ;
V_35 -> V_142 = 0 ;
}
}
if ( ( V_159 <= 1 ) && F_14 ( V_35 -> V_41 . V_42 ) )
return;
F_83 (req, n, &dep->request_list, list) {
unsigned V_63 ;
T_3 V_138 ;
V_161 = false ;
if ( V_46 -> V_53 . V_54 > 0 ) {
struct V_135 * V_53 = & V_46 -> V_53 ;
struct V_162 * V_163 = V_53 -> V_163 ;
struct V_162 * V_164 ;
int V_48 ;
F_84 (sg, s, request->num_mapped_sgs, i) {
unsigned V_140 = true ;
V_63 = F_85 ( V_164 ) ;
V_138 = F_86 ( V_164 ) ;
if ( V_48 == ( V_53 -> V_54 - 1 ) ||
F_87 ( V_164 ) ) {
if ( F_88 ( & V_46 -> V_55 ,
& V_35 -> V_126 ) )
V_161 = true ;
V_140 = false ;
}
V_159 -- ;
if ( ! V_159 )
V_161 = true ;
if ( V_161 )
V_140 = false ;
F_76 ( V_35 , V_46 , V_138 , V_63 ,
V_161 , V_140 , V_48 ) ;
if ( V_161 )
break;
}
} else {
V_138 = V_46 -> V_53 . V_138 ;
V_63 = V_46 -> V_53 . V_63 ;
V_159 -- ;
if ( ! V_159 )
V_161 = 1 ;
if ( F_88 ( & V_46 -> V_55 , & V_35 -> V_126 ) )
V_161 = 1 ;
F_76 ( V_35 , V_46 , V_138 , V_63 ,
V_161 , false , 0 ) ;
if ( V_161 )
break;
}
}
}
static int F_89 ( struct V_34 * V_35 , T_5 V_165 ,
int V_166 )
{
struct V_82 V_83 ;
struct V_45 * V_46 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_115 ;
T_1 V_66 ;
if ( V_166 && ( V_35 -> V_39 & V_167 ) ) {
F_9 ( V_2 -> V_23 , L_35 , V_35 -> V_44 ) ;
return - V_168 ;
}
V_35 -> V_39 &= ~ V_169 ;
if ( V_166 ) {
if ( F_57 ( & V_35 -> V_124 ) )
F_81 ( V_35 , V_166 ) ;
V_46 = F_59 ( & V_35 -> V_124 ) ;
} else {
F_81 ( V_35 , V_166 ) ;
V_46 = F_59 ( & V_35 -> V_124 ) ;
}
if ( ! V_46 ) {
V_35 -> V_39 |= V_169 ;
return 0 ;
}
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
if ( V_166 ) {
V_83 . V_84 = F_55 ( V_46 -> V_143 ) ;
V_83 . V_85 = F_54 ( V_46 -> V_143 ) ;
V_66 = V_70 ;
} else {
V_66 = V_69 ;
}
V_66 |= F_39 ( V_165 ) ;
V_115 = F_26 ( V_2 , V_35 -> V_59 , V_66 , & V_83 ) ;
if ( V_115 < 0 ) {
F_20 ( V_2 -> V_23 , L_36 ) ;
F_19 ( & V_2 -> V_60 , & V_46 -> V_53 ,
V_46 -> V_61 ) ;
F_18 ( & V_46 -> V_55 ) ;
return V_115 ;
}
V_35 -> V_39 |= V_167 ;
if ( V_166 ) {
V_35 -> V_170 = F_90 ( V_2 ,
V_35 -> V_59 ) ;
F_91 ( ! V_35 -> V_170 ) ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_171 )
{
T_1 V_172 ;
if ( F_57 ( & V_35 -> V_126 ) ) {
F_9 ( V_2 -> V_23 , L_37 ,
V_35 -> V_44 ) ;
V_35 -> V_39 |= V_169 ;
return;
}
V_172 = V_171 + V_35 -> V_114 * 4 ;
F_89 ( V_35 , V_172 , 1 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_173 * V_174 )
{
T_1 V_171 , V_175 ;
V_175 = ~ ( V_35 -> V_114 - 1 ) ;
V_171 = V_174 -> V_176 & V_175 ;
F_92 ( V_2 , V_35 , V_171 ) ;
}
static int F_94 ( struct V_34 * V_35 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_115 ;
V_46 -> V_53 . V_62 = 0 ;
V_46 -> V_53 . V_47 = - V_57 ;
V_46 -> V_61 = V_35 -> V_61 ;
V_46 -> V_137 = V_35 -> V_59 ;
V_115 = F_95 ( & V_2 -> V_60 , & V_46 -> V_53 ,
V_35 -> V_61 ) ;
if ( V_115 )
return V_115 ;
F_96 ( & V_46 -> V_55 , & V_35 -> V_126 ) ;
if ( V_35 -> V_39 & V_169 ) {
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
if ( F_57 ( & V_35 -> V_124 ) ) {
F_58 ( V_2 , V_35 -> V_59 , true ) ;
V_35 -> V_39 = V_40 ;
}
return 0 ;
}
V_115 = F_89 ( V_35 , 0 , true ) ;
if ( V_115 && V_115 != - V_168 )
F_20 ( V_2 -> V_23 , L_38 ,
V_35 -> V_44 ) ;
return V_115 ;
}
if ( F_14 ( V_35 -> V_41 . V_42 ) &&
( V_35 -> V_39 & V_167 ) &&
! ( V_35 -> V_39 & V_177 ) ) {
F_91 ( ! V_35 -> V_170 ) ;
V_115 = F_89 ( V_35 , V_35 -> V_170 ,
false ) ;
if ( V_115 && V_115 != - V_168 )
F_20 ( V_2 -> V_23 , L_38 ,
V_35 -> V_44 ) ;
return V_115 ;
}
if ( V_35 -> V_111 ) {
int V_115 ;
V_115 = F_89 ( V_35 , 0 , true ) ;
if ( V_115 && V_115 != - V_168 ) {
struct V_1 * V_2 = V_35 -> V_2 ;
F_20 ( V_2 -> V_23 , L_38 ,
V_35 -> V_44 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_127 * V_81 , struct V_135 * V_53 ,
T_4 V_136 )
{
struct V_45 * V_46 = F_74 ( V_53 ) ;
struct V_34 * V_35 = F_65 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_39 ;
int V_115 ;
if ( ! V_35 -> V_41 . V_42 ) {
F_20 ( V_2 -> V_23 , L_39 ,
V_53 , V_81 -> V_44 ) ;
return - V_125 ;
}
F_9 ( V_2 -> V_23 , L_40 ,
V_53 , V_81 -> V_44 , V_53 -> V_63 ) ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_115 = F_94 ( V_35 , V_46 ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static int F_98 ( struct V_127 * V_81 ,
struct V_135 * V_53 )
{
struct V_45 * V_46 = F_74 ( V_53 ) ;
struct V_45 * V_178 = NULL ;
struct V_34 * V_35 = F_65 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_39 ;
int V_115 = 0 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
F_99 (r, &dep->request_list, list) {
if ( V_178 == V_46 )
break;
}
if ( V_178 != V_46 ) {
F_99 (r, &dep->req_queued, list) {
if ( V_178 == V_46 )
break;
}
if ( V_178 == V_46 ) {
F_58 ( V_2 , V_35 -> V_59 , true ) ;
goto V_179;
}
F_35 ( V_2 -> V_23 , L_41 ,
V_53 , V_81 -> V_44 ) ;
V_115 = - V_13 ;
goto V_180;
}
V_179:
F_17 ( V_35 , V_46 , - V_181 ) ;
V_180:
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
int F_100 ( struct V_34 * V_35 , int V_182 )
{
struct V_82 V_83 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_115 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
if ( V_182 ) {
V_115 = F_26 ( V_2 , V_35 -> V_59 ,
V_72 , & V_83 ) ;
if ( V_115 )
F_35 ( V_2 -> V_23 , L_42 ,
V_35 -> V_44 ) ;
else
V_35 -> V_39 |= V_183 ;
} else {
V_115 = F_26 ( V_2 , V_35 -> V_59 ,
V_71 , & V_83 ) ;
if ( V_115 )
F_35 ( V_2 -> V_23 , L_43 ,
V_35 -> V_44 ) ;
else
V_35 -> V_39 &= ~ ( V_183 | V_184 ) ;
}
return V_115 ;
}
static int F_101 ( struct V_127 * V_81 , int V_182 )
{
struct V_34 * V_35 = F_65 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_39 ;
int V_115 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
F_35 ( V_2 -> V_23 , L_44 , V_35 -> V_44 ) ;
V_115 = - V_13 ;
goto V_185;
}
V_115 = F_100 ( V_35 , V_182 ) ;
V_185:
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static int F_102 ( struct V_127 * V_81 )
{
struct V_34 * V_35 = F_65 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_39 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_35 -> V_39 |= V_184 ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
if ( V_35 -> V_59 == 0 || V_35 -> V_59 == 1 )
return F_103 ( V_81 , 1 ) ;
else
return F_101 ( V_81 , 1 ) ;
}
static int F_104 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
return F_106 ( V_4 ) ;
}
static int F_107 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
unsigned long V_77 ;
unsigned long V_39 ;
T_1 V_4 ;
int V_115 = 0 ;
T_2 V_188 ;
T_2 V_100 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_100 = V_4 & V_189 ;
if ( V_100 == V_190 ) {
F_20 ( V_2 -> V_23 , L_45 ) ;
V_115 = - V_13 ;
goto V_185;
}
V_188 = F_5 ( V_4 ) ;
switch ( V_188 ) {
case V_191 :
case V_192 :
break;
default:
F_20 ( V_2 -> V_23 , L_46 ,
V_188 ) ;
V_115 = - V_13 ;
goto V_185;
}
V_115 = F_6 ( V_2 , V_193 ) ;
if ( V_115 < 0 ) {
F_35 ( V_2 -> V_23 , L_47 ) ;
goto V_185;
}
if ( V_2 -> V_18 < V_19 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_77 = V_194 + F_108 ( 100 ) ;
while ( ! F_109 ( V_194 , V_77 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( F_5 ( V_4 ) == V_195 )
break;
}
if ( F_5 ( V_4 ) != V_195 ) {
F_35 ( V_2 -> V_23 , L_48 ) ;
V_115 = - V_13 ;
}
V_185:
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static int F_110 ( struct V_186 * V_187 ,
int V_196 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
unsigned long V_39 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_2 -> V_196 = ! ! V_196 ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , int V_197 , int V_198 )
{
T_1 V_4 ;
T_1 V_77 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_197 ) {
if ( V_2 -> V_18 <= V_199 ) {
V_4 &= ~ V_200 ;
V_4 |= V_201 ;
}
if ( V_2 -> V_18 >= V_19 )
V_4 &= ~ V_202 ;
V_4 |= V_203 ;
if ( V_2 -> V_204 )
V_4 |= V_202 ;
V_2 -> V_205 = true ;
} else {
V_4 &= ~ V_203 ;
if ( V_2 -> V_204 && ! V_198 )
V_4 &= ~ V_202 ;
V_2 -> V_205 = false ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( V_197 ) {
if ( ! ( V_4 & V_206 ) )
break;
} else {
if ( V_4 & V_206 )
break;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_7 ( 1 ) ;
} while ( 1 );
F_9 ( V_2 -> V_23 , L_49 ,
V_2 -> V_207
? V_2 -> V_207 -> V_208 : L_50 ,
V_197 ? L_51 : L_52 ) ;
return 0 ;
}
static int F_112 ( struct V_186 * V_187 , int V_197 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
unsigned long V_39 ;
int V_115 ;
V_197 = ! ! V_197 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
V_115 = F_111 ( V_2 , V_197 , false ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static void F_113 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_209 |
V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 |
V_216 |
V_217 ) ;
F_3 ( V_2 -> V_5 , V_218 , V_4 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 , V_218 , 0x00 ) ;
}
static int F_115 ( struct V_186 * V_187 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
struct V_34 * V_35 ;
unsigned long V_39 ;
int V_115 = 0 ;
int V_221 ;
T_1 V_4 ;
V_221 = F_116 ( F_117 ( V_2 -> V_23 ) , 0 ) ;
V_115 = F_118 ( V_221 , V_222 , V_223 ,
V_224 , L_53 , V_2 ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_54 ,
V_221 , V_115 ) ;
goto V_225;
}
F_68 ( & V_2 -> V_64 , V_39 ) ;
if ( V_2 -> V_207 ) {
F_35 ( V_2 -> V_23 , L_55 ,
V_2 -> V_60 . V_44 ,
V_2 -> V_207 -> V_220 . V_44 ) ;
V_115 = - V_168 ;
goto V_226;
}
V_2 -> V_207 = V_220 ;
V_4 = F_2 ( V_2 -> V_5 , V_227 ) ;
V_4 &= ~ ( V_228 ) ;
if ( V_2 -> V_18 < V_229 ) {
V_4 |= V_230 ;
} else {
switch ( V_2 -> V_231 ) {
case V_232 :
V_4 |= V_233 ;
break;
case V_234 :
V_4 |= V_235 ;
break;
case V_236 :
V_4 |= V_237 ;
break;
case V_101 :
case V_238 :
default:
V_4 |= V_190 ;
}
}
F_3 ( V_2 -> V_5 , V_227 , V_4 ) ;
V_2 -> V_94 = false ;
V_239 . V_130 = F_119 ( 512 ) ;
V_35 = V_2 -> V_36 [ 0 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , false ,
false ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_56 , V_35 -> V_44 ) ;
goto V_240;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , false ,
false ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_56 , V_35 -> V_44 ) ;
goto V_241;
}
V_2 -> V_242 = V_243 ;
F_120 ( V_2 ) ;
F_113 ( V_2 ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return 0 ;
V_241:
F_60 ( V_2 -> V_36 [ 0 ] ) ;
V_240:
V_2 -> V_207 = NULL ;
V_226:
F_69 ( & V_2 -> V_64 , V_39 ) ;
F_121 ( V_221 , V_2 ) ;
V_225:
return V_115 ;
}
static int F_122 ( struct V_186 * V_187 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = F_105 ( V_187 ) ;
unsigned long V_39 ;
int V_221 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
F_114 ( V_2 ) ;
F_60 ( V_2 -> V_36 [ 0 ] ) ;
F_60 ( V_2 -> V_36 [ 1 ] ) ;
V_2 -> V_207 = NULL ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
V_221 = F_116 ( F_117 ( V_2 -> V_23 ) , 0 ) ;
F_121 ( V_221 , V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_2 V_28 , T_1 V_61 )
{
struct V_34 * V_35 ;
T_2 V_48 ;
for ( V_48 = 0 ; V_48 < V_28 ; V_48 ++ ) {
T_2 V_137 = ( V_48 << 1 ) | ( ! ! V_61 ) ;
V_35 = F_72 ( sizeof( * V_35 ) , V_92 ) ;
if ( ! V_35 ) {
F_35 ( V_2 -> V_23 , L_57 ,
V_137 ) ;
return - V_93 ;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_59 = V_137 ;
V_35 -> V_61 = ! ! V_61 ;
V_2 -> V_36 [ V_137 ] = V_35 ;
snprintf ( V_35 -> V_44 , sizeof( V_35 -> V_44 ) , L_27 , V_137 >> 1 ,
( V_137 & 1 ) ? L_28 : L_29 ) ;
V_35 -> V_41 . V_44 = V_35 -> V_44 ;
F_9 ( V_2 -> V_23 , L_58 , V_35 -> V_44 ) ;
if ( V_137 == 0 || V_137 == 1 ) {
F_124 ( & V_35 -> V_41 , 512 ) ;
V_35 -> V_41 . V_103 = 1 ;
V_35 -> V_41 . V_244 = & V_245 ;
if ( ! V_137 )
V_2 -> V_60 . V_246 = & V_35 -> V_41 ;
} else {
int V_115 ;
F_124 ( & V_35 -> V_41 , 1024 ) ;
V_35 -> V_41 . V_247 = 15 ;
V_35 -> V_41 . V_244 = & V_248 ;
F_96 ( & V_35 -> V_41 . V_249 ,
& V_2 -> V_60 . V_249 ) ;
V_115 = F_33 ( V_35 ) ;
if ( V_115 )
return V_115 ;
}
F_125 ( & V_35 -> V_126 ) ;
F_125 ( & V_35 -> V_124 ) ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_115 ;
F_125 ( & V_2 -> V_60 . V_249 ) ;
V_115 = F_123 ( V_2 , V_2 -> V_250 , 0 ) ;
if ( V_115 < 0 ) {
F_9 ( V_2 -> V_23 , L_59 ) ;
return V_115 ;
}
V_115 = F_123 ( V_2 , V_2 -> V_33 , 1 ) ;
if ( V_115 < 0 ) {
F_9 ( V_2 -> V_23 , L_60 ) ;
return V_115 ;
}
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_137 ;
for ( V_137 = 0 ; V_137 < V_251 ; V_137 ++ ) {
V_35 = V_2 -> V_36 [ V_137 ] ;
if ( ! V_35 )
continue;
if ( V_137 != 0 && V_137 != 1 ) {
F_36 ( V_35 ) ;
F_18 ( & V_35 -> V_41 . V_249 ) ;
}
F_75 ( V_35 ) ;
}
}
static int F_128 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_45 * V_46 , struct V_88 * V_56 ,
const struct V_173 * V_174 , int V_47 )
{
unsigned int V_252 ;
unsigned int V_253 = 0 ;
unsigned int V_254 ;
if ( ( V_56 -> V_121 & V_123 ) && V_47 != - V_125 )
F_35 ( V_2 -> V_23 , L_61 ,
V_35 -> V_44 , V_56 ) ;
V_252 = V_56 -> V_145 & V_255 ;
if ( V_35 -> V_61 ) {
if ( V_252 ) {
V_254 = F_129 ( V_56 -> V_145 ) ;
if ( V_254 == V_256 ) {
F_20 ( V_2 -> V_23 , L_62 ,
V_35 -> V_44 ) ;
V_35 -> V_39 |= V_177 ;
} else {
F_35 ( V_2 -> V_23 , L_62 ,
V_35 -> V_44 ) ;
V_47 = - V_181 ;
}
} else {
V_35 -> V_39 &= ~ V_177 ;
}
} else {
if ( V_252 && ( V_174 -> V_47 & V_257 ) )
V_253 = 1 ;
}
V_46 -> V_53 . V_62 += V_46 -> V_53 . V_63 - V_252 ;
if ( V_253 )
return 1 ;
if ( ( V_174 -> V_47 & V_258 ) &&
( V_56 -> V_121 & ( V_154 |
V_123 ) ) )
return 1 ;
if ( ( V_174 -> V_47 & V_259 ) &&
( V_56 -> V_121 & V_151 ) )
return 1 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_173 * V_174 , int V_47 )
{
struct V_45 * V_46 ;
struct V_88 * V_56 ;
unsigned int V_260 ;
unsigned int V_48 ;
int V_115 ;
do {
V_46 = F_59 ( & V_35 -> V_124 ) ;
if ( ! V_46 ) {
F_91 ( 1 ) ;
return 1 ;
}
V_48 = 0 ;
do {
V_260 = V_46 -> V_144 + V_48 ;
if ( ( V_260 == V_52 - 1 ) &&
F_14 ( V_35 -> V_41 . V_42 ) )
V_260 ++ ;
V_260 %= V_52 ;
V_56 = & V_35 -> V_90 [ V_260 ] ;
V_115 = F_128 ( V_2 , V_35 , V_46 , V_56 ,
V_174 , V_47 ) ;
if ( V_115 )
break;
}while ( ++ V_48 < V_46 -> V_53 . V_54 );
F_17 ( V_35 , V_46 , V_47 ) ;
if ( V_115 )
break;
} while ( 1 );
if ( F_14 ( V_35 -> V_41 . V_42 ) &&
F_57 ( & V_35 -> V_124 ) ) {
if ( F_57 ( & V_35 -> V_126 ) ) {
V_35 -> V_39 = V_169 ;
} else {
F_58 ( V_2 , V_35 -> V_59 , true ) ;
V_35 -> V_39 = V_40 ;
}
return 1 ;
}
return 1 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_173 * V_174 ,
int V_166 )
{
unsigned V_47 = 0 ;
int V_261 ;
if ( V_174 -> V_47 & V_262 )
V_47 = - V_181 ;
V_261 = F_130 ( V_2 , V_35 , V_174 , V_47 ) ;
if ( V_261 )
V_35 -> V_39 &= ~ V_167 ;
if ( V_2 -> V_18 < V_263 ) {
T_1 V_4 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_251 ; V_48 ++ ) {
V_35 = V_2 -> V_36 [ V_48 ] ;
if ( ! ( V_35 -> V_39 & V_40 ) )
continue;
if ( ! F_57 ( & V_35 -> V_124 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_264 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_264 = 0 ;
}
}
static void F_132 ( struct V_1 * V_2 ,
const struct V_173 * V_174 )
{
struct V_34 * V_35 ;
T_2 V_137 = V_174 -> V_265 ;
V_35 = V_2 -> V_36 [ V_137 ] ;
if ( ! ( V_35 -> V_39 & V_40 ) )
return;
F_9 ( V_2 -> V_23 , L_63 , V_35 -> V_44 ,
F_133 ( V_174 -> V_266 ) ) ;
if ( V_137 == 0 || V_137 == 1 ) {
F_134 ( V_2 , V_174 ) ;
return;
}
switch ( V_174 -> V_266 ) {
case V_267 :
V_35 -> V_170 = 0 ;
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
F_20 ( V_2 -> V_23 , L_64 ,
V_35 -> V_44 ) ;
return;
}
F_131 ( V_2 , V_35 , V_174 , 1 ) ;
break;
case V_268 :
if ( ! F_14 ( V_35 -> V_41 . V_42 ) ) {
F_20 ( V_2 -> V_23 , L_65 ,
V_35 -> V_44 ) ;
return;
}
F_131 ( V_2 , V_35 , V_174 , 0 ) ;
break;
case V_269 :
if ( F_14 ( V_35 -> V_41 . V_42 ) ) {
F_93 ( V_2 , V_35 , V_174 ) ;
} else {
int V_115 ;
F_9 ( V_2 -> V_23 , L_66 ,
V_35 -> V_44 , V_174 -> V_47 &
V_270
? L_67
: L_68 ) ;
V_115 = F_89 ( V_35 , 0 , 1 ) ;
if ( ! V_115 || V_115 == - V_168 )
return;
F_20 ( V_2 -> V_23 , L_38 ,
V_35 -> V_44 ) ;
}
break;
case V_271 :
if ( ! F_13 ( V_35 -> V_41 . V_42 ) ) {
F_35 ( V_2 -> V_23 , L_69 ,
V_35 -> V_44 ) ;
return;
}
switch ( V_174 -> V_47 ) {
case V_272 :
F_9 ( V_2 -> V_23 , L_70 ,
V_174 -> V_176 ) ;
break;
case V_273 :
default:
F_20 ( V_2 -> V_23 , L_71 ) ;
}
break;
case V_274 :
F_20 ( V_2 -> V_23 , L_72 , V_35 -> V_44 ) ;
break;
case V_275 :
F_9 ( V_2 -> V_23 , L_73 ) ;
break;
}
}
static void F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_207 && V_2 -> V_207 -> V_276 ) {
F_21 ( & V_2 -> V_64 ) ;
V_2 -> V_207 -> V_276 ( & V_2 -> V_60 ) ;
F_22 ( & V_2 -> V_64 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
if ( V_2 -> V_207 && V_2 -> V_207 -> V_198 ) {
F_21 ( & V_2 -> V_64 ) ;
V_2 -> V_207 -> V_198 ( & V_2 -> V_60 ) ;
F_22 ( & V_2 -> V_64 ) ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
if ( V_2 -> V_207 && V_2 -> V_207 -> V_277 ) {
F_21 ( & V_2 -> V_64 ) ;
V_2 -> V_207 -> V_277 ( & V_2 -> V_60 ) ;
F_22 ( & V_2 -> V_64 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , T_1 V_137 , bool V_278 )
{
struct V_34 * V_35 ;
struct V_82 V_83 ;
T_1 V_66 ;
int V_115 ;
V_35 = V_2 -> V_36 [ V_137 ] ;
if ( ! V_35 -> V_170 )
return;
V_66 = V_68 ;
V_66 |= V_278 ? V_279 : 0 ;
V_66 |= V_280 ;
V_66 |= F_39 ( V_35 -> V_170 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_115 = F_26 ( V_2 , V_35 -> V_59 , V_66 , & V_83 ) ;
F_91 ( V_115 ) ;
V_35 -> V_170 = 0 ;
V_35 -> V_39 &= ~ V_167 ;
F_7 ( 100 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
T_1 V_137 ;
for ( V_137 = 2 ; V_137 < V_251 ; V_137 ++ ) {
struct V_34 * V_35 ;
V_35 = V_2 -> V_36 [ V_137 ] ;
if ( ! V_35 )
continue;
if ( ! ( V_35 -> V_39 & V_40 ) )
continue;
F_56 ( V_2 , V_35 ) ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
T_1 V_137 ;
for ( V_137 = 1 ; V_137 < V_251 ; V_137 ++ ) {
struct V_34 * V_35 ;
struct V_82 V_83 ;
int V_115 ;
V_35 = V_2 -> V_36 [ V_137 ] ;
if ( ! V_35 )
continue;
if ( ! ( V_35 -> V_39 & V_183 ) )
continue;
V_35 -> V_39 &= ~ V_183 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_115 = F_26 ( V_2 , V_35 -> V_59 ,
V_71 , & V_83 ) ;
F_91 ( V_115 ) ;
}
}
static void F_140 ( struct V_1 * V_2 )
{
int V_4 ;
F_9 ( V_2 -> V_23 , L_74 , V_281 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_282 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 &= ~ V_283 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_135 ( V_2 ) ;
V_2 -> V_94 = false ;
V_2 -> V_60 . V_100 = V_238 ;
V_2 -> V_284 = false ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_9 ( V_2 -> V_23 , L_74 , V_281 ) ;
if ( V_2 -> V_18 < V_285 ) {
if ( V_2 -> V_284 )
F_140 ( V_2 ) ;
}
F_142 ( & V_2 -> V_60 , V_286 ) ;
if ( V_2 -> V_60 . V_100 != V_238 )
F_135 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_287 = false ;
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
V_2 -> V_94 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_227 ) ;
V_4 &= ~ ( V_288 ) ;
F_3 ( V_2 -> V_5 , V_227 , V_4 ) ;
}
static void F_143 ( struct V_1 * V_2 , T_1 V_100 )
{
T_1 V_4 ;
T_1 V_289 = V_290 ;
if ( V_100 != V_190 )
return;
if ( ! V_289 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_291 ) ;
V_4 |= F_144 ( V_289 ) ;
F_3 ( V_2 -> V_5 , V_291 , V_4 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_115 ;
T_1 V_4 ;
T_2 V_100 ;
F_9 ( V_2 -> V_23 , L_74 , V_281 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_100 = V_4 & V_189 ;
V_2 -> V_100 = V_100 ;
F_143 ( V_2 , V_100 ) ;
switch ( V_100 ) {
case V_230 :
if ( V_2 -> V_18 < V_292 )
F_141 ( V_2 ) ;
V_239 . V_130 = F_119 ( 512 ) ;
V_2 -> V_60 . V_246 -> V_43 = 512 ;
V_2 -> V_60 . V_100 = V_101 ;
break;
case V_293 :
V_239 . V_130 = F_119 ( 64 ) ;
V_2 -> V_60 . V_246 -> V_43 = 64 ;
V_2 -> V_60 . V_100 = V_236 ;
break;
case V_294 :
case V_295 :
V_239 . V_130 = F_119 ( 64 ) ;
V_2 -> V_60 . V_246 -> V_43 = 64 ;
V_2 -> V_60 . V_100 = V_234 ;
break;
case V_296 :
V_239 . V_130 = F_119 ( 8 ) ;
V_2 -> V_60 . V_246 -> V_43 = 8 ;
V_2 -> V_60 . V_100 = V_232 ;
break;
}
if ( ( V_2 -> V_18 > V_19 )
&& ( V_100 != V_230 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_227 ) ;
V_4 |= V_297 ;
F_3 ( V_2 -> V_5 , V_227 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ ( V_298 | V_299 ) ;
V_4 |= F_146 ( 12 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_298 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_35 = V_2 -> V_36 [ 0 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , true ,
false ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_56 , V_35 -> V_44 ) ;
return;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , true ,
false ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_56 , V_35 -> V_44 ) ;
return;
}
}
static void F_147 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_23 , L_74 , V_281 ) ;
V_2 -> V_207 -> V_277 ( & V_2 -> V_60 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
unsigned int V_300 )
{
enum V_15 V_301 = V_300 & V_302 ;
unsigned int V_303 ;
V_303 = F_149 ( V_2 -> V_30 . V_304 ) ;
if ( ( V_2 -> V_18 < V_305 ) &&
( V_303 != V_306 ) ) {
if ( ( V_2 -> V_188 == V_192 ) &&
( V_301 == V_307 ) ) {
F_9 ( V_2 -> V_23 , L_75 ) ;
return;
}
}
if ( V_2 -> V_18 < V_263 ) {
if ( V_301 == V_195 ) {
T_1 V_264 ;
T_1 V_4 ;
switch ( V_2 -> V_188 ) {
case V_308 :
case V_309 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_264 = V_4 & ( V_283
| V_310
| V_282
| V_311 ) ;
if ( ! V_2 -> V_264 )
V_2 -> V_264 = V_4 & V_264 ;
V_4 &= ~ V_264 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_188 = V_301 ;
switch ( V_301 ) {
case V_308 :
if ( V_2 -> V_100 == V_101 )
F_136 ( V_2 ) ;
break;
case V_309 :
case V_192 :
F_136 ( V_2 ) ;
break;
case V_307 :
F_137 ( V_2 ) ;
break;
default:
break;
}
F_9 ( V_2 -> V_23 , L_76 , V_281 , V_2 -> V_188 ) ;
}
static void F_150 ( struct V_1 * V_2 ,
unsigned int V_300 )
{
unsigned int V_312 = V_300 & F_151 ( 4 ) ;
if ( V_312 ^ ( V_2 -> V_100 == V_101 ) )
return;
}
static void F_152 ( struct V_1 * V_2 ,
const struct V_313 * V_174 )
{
switch ( V_174 -> type ) {
case V_314 :
F_140 ( V_2 ) ;
break;
case V_315 :
F_141 ( V_2 ) ;
break;
case V_316 :
F_145 ( V_2 ) ;
break;
case V_317 :
F_147 ( V_2 ) ;
break;
case V_318 :
if ( F_66 ( V_2 -> V_23 , ! V_2 -> V_204 ,
L_77 ) )
break;
F_150 ( V_2 , V_174 -> V_319 ) ;
break;
case V_320 :
F_148 ( V_2 , V_174 -> V_319 ) ;
break;
case V_321 :
F_9 ( V_2 -> V_23 , L_78 ) ;
break;
case V_322 :
F_9 ( V_2 -> V_23 , L_79 ) ;
break;
case V_323 :
F_9 ( V_2 -> V_23 , L_80 ) ;
break;
case V_324 :
F_9 ( V_2 -> V_23 , L_81 ) ;
break;
case V_325 :
F_9 ( V_2 -> V_23 , L_82 ) ;
break;
default:
F_20 ( V_2 -> V_23 , L_83 , V_174 -> type ) ;
}
}
static void F_153 ( struct V_1 * V_2 ,
const union V_326 * V_174 )
{
if ( V_174 -> type . V_327 == 0 ) {
return F_132 ( V_2 , & V_174 -> V_328 ) ;
}
switch ( V_174 -> type . type ) {
case V_329 :
F_152 ( V_2 , & V_174 -> V_330 ) ;
break;
default:
F_35 ( V_2 -> V_23 , L_84 , V_174 -> V_331 ) ;
}
}
static T_6 F_154 ( struct V_1 * V_2 , T_1 V_332 )
{
struct V_333 * V_334 ;
T_6 V_115 = V_335 ;
int V_336 ;
T_1 V_4 ;
V_334 = V_2 -> V_337 [ V_332 ] ;
V_336 = V_334 -> V_252 ;
if ( ! ( V_334 -> V_39 & V_338 ) )
return V_335 ;
while ( V_336 > 0 ) {
union V_326 V_174 ;
V_174 . V_331 = * ( T_1 * ) ( V_334 -> V_332 + V_334 -> V_339 ) ;
F_153 ( V_2 , & V_174 ) ;
V_334 -> V_339 = ( V_334 -> V_339 + 4 ) % V_340 ;
V_336 -= 4 ;
F_3 ( V_2 -> V_5 , F_155 ( V_332 ) , 4 ) ;
}
V_334 -> V_252 = 0 ;
V_334 -> V_39 &= ~ V_338 ;
V_115 = V_341 ;
V_4 = F_2 ( V_2 -> V_5 , F_156 ( V_332 ) ) ;
V_4 &= ~ V_342 ;
F_3 ( V_2 -> V_5 , F_156 ( V_332 ) , V_4 ) ;
return V_115 ;
}
static T_6 V_223 ( int V_221 , void * V_343 )
{
struct V_1 * V_2 = V_343 ;
unsigned long V_39 ;
T_6 V_115 = V_335 ;
int V_48 ;
F_68 ( & V_2 -> V_64 , V_39 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_344 ; V_48 ++ )
V_115 |= F_154 ( V_2 , V_48 ) ;
F_69 ( & V_2 -> V_64 , V_39 ) ;
return V_115 ;
}
static T_6 F_157 ( struct V_1 * V_2 , T_1 V_332 )
{
struct V_333 * V_334 ;
T_1 V_252 ;
T_1 V_4 ;
V_334 = V_2 -> V_337 [ V_332 ] ;
V_252 = F_2 ( V_2 -> V_5 , F_155 ( V_332 ) ) ;
V_252 &= V_345 ;
if ( ! V_252 )
return V_335 ;
V_334 -> V_252 = V_252 ;
V_334 -> V_39 |= V_338 ;
V_4 = F_2 ( V_2 -> V_5 , F_156 ( V_332 ) ) ;
V_4 |= V_342 ;
F_3 ( V_2 -> V_5 , F_156 ( V_332 ) , V_4 ) ;
return V_346 ;
}
static T_6 V_222 ( int V_221 , void * V_343 )
{
struct V_1 * V_2 = V_343 ;
int V_48 ;
T_6 V_115 = V_335 ;
F_22 ( & V_2 -> V_64 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_344 ; V_48 ++ ) {
T_6 V_47 ;
V_47 = F_157 ( V_2 , V_48 ) ;
if ( V_47 == V_346 )
V_115 = V_47 ;
}
F_21 ( & V_2 -> V_64 ) ;
return V_115 ;
}
int F_158 ( struct V_1 * V_2 )
{
int V_115 ;
V_2 -> V_347 = F_34 ( V_2 -> V_23 , sizeof( * V_2 -> V_347 ) ,
& V_2 -> V_348 , V_92 ) ;
if ( ! V_2 -> V_347 ) {
F_35 ( V_2 -> V_23 , L_85 ) ;
V_115 = - V_93 ;
goto V_225;
}
V_2 -> V_349 = F_34 ( V_2 -> V_23 , sizeof( * V_2 -> V_349 ) ,
& V_2 -> V_350 , V_92 ) ;
if ( ! V_2 -> V_349 ) {
F_35 ( V_2 -> V_23 , L_86 ) ;
V_115 = - V_93 ;
goto V_226;
}
V_2 -> V_351 = F_72 ( V_352 , V_92 ) ;
if ( ! V_2 -> V_351 ) {
F_35 ( V_2 -> V_23 , L_87 ) ;
V_115 = - V_93 ;
goto V_240;
}
V_2 -> V_353 = F_34 ( V_2 -> V_23 ,
V_352 , & V_2 -> V_354 ,
V_92 ) ;
if ( ! V_2 -> V_353 ) {
F_35 ( V_2 -> V_23 , L_88 ) ;
V_115 = - V_93 ;
goto V_241;
}
V_2 -> V_60 . V_244 = & V_355 ;
V_2 -> V_60 . V_356 = V_101 ;
V_2 -> V_60 . V_100 = V_238 ;
V_2 -> V_60 . V_357 = true ;
V_2 -> V_60 . V_44 = L_89 ;
V_2 -> V_60 . V_358 = true ;
V_115 = F_126 ( V_2 ) ;
if ( V_115 )
goto V_359;
V_115 = F_159 ( V_2 -> V_23 , & V_2 -> V_60 ) ;
if ( V_115 ) {
F_35 ( V_2 -> V_23 , L_90 ) ;
goto V_359;
}
return 0 ;
V_359:
F_127 ( V_2 ) ;
F_37 ( V_2 -> V_23 , V_352 ,
V_2 -> V_353 , V_2 -> V_354 ) ;
V_241:
F_75 ( V_2 -> V_351 ) ;
V_240:
F_37 ( V_2 -> V_23 , sizeof( * V_2 -> V_349 ) ,
V_2 -> V_349 , V_2 -> V_350 ) ;
V_226:
F_37 ( V_2 -> V_23 , sizeof( * V_2 -> V_347 ) ,
V_2 -> V_347 , V_2 -> V_348 ) ;
V_225:
return V_115 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_161 ( & V_2 -> V_60 ) ;
F_127 ( V_2 ) ;
F_37 ( V_2 -> V_23 , V_352 ,
V_2 -> V_353 , V_2 -> V_354 ) ;
F_75 ( V_2 -> V_351 ) ;
F_37 ( V_2 -> V_23 , sizeof( * V_2 -> V_349 ) ,
V_2 -> V_349 , V_2 -> V_350 ) ;
F_37 ( V_2 -> V_23 , sizeof( * V_2 -> V_347 ) ,
V_2 -> V_347 , V_2 -> V_348 ) ;
}
int F_162 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 ) {
F_114 ( V_2 ) ;
F_111 ( V_2 , true , true ) ;
}
return 0 ;
}
void F_163 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 ) {
F_113 ( V_2 ) ;
F_111 ( V_2 , true , false ) ;
}
}
int F_164 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_36 [ 0 ] ) ;
F_60 ( V_2 -> V_36 [ 1 ] ) ;
V_2 -> V_360 = F_2 ( V_2 -> V_5 , V_227 ) ;
return 0 ;
}
int F_165 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_115 ;
V_239 . V_130 = F_119 ( 512 ) ;
V_35 = V_2 -> V_36 [ 0 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , false ,
false ) ;
if ( V_115 )
goto V_225;
V_35 = V_2 -> V_36 [ 1 ] ;
V_115 = F_52 ( V_35 , & V_239 , NULL , false ,
false ) ;
if ( V_115 )
goto V_226;
V_2 -> V_242 = V_243 ;
F_120 ( V_2 ) ;
F_3 ( V_2 -> V_5 , V_227 , V_2 -> V_360 ) ;
return 0 ;
V_226:
F_60 ( V_2 -> V_36 [ 0 ] ) ;
V_225:
return V_115 ;
}
