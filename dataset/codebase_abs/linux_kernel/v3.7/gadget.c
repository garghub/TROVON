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
int F_4 ( struct V_1 * V_2 , enum V_14 V_15 )
{
int V_16 = 10000 ;
T_1 V_4 ;
if ( V_2 -> V_17 >= V_18 ) {
while ( -- V_16 ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( V_4 & V_20 )
F_5 ( 5 ) ;
else
break;
}
if ( V_16 <= 0 )
return - V_21 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
V_4 |= F_6 ( V_15 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
if ( V_2 -> V_17 >= V_18 )
return 0 ;
V_16 = 10000 ;
while ( -- V_16 ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( F_7 ( V_4 ) == V_15 )
return 0 ;
F_5 ( 5 ) ;
}
F_8 ( V_2 -> V_23 , L_1 ) ;
return - V_21 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
if ( ! V_2 -> V_29 )
return 0 ;
V_25 = F_10 ( V_2 -> V_30 . V_31 ) ;
V_27 = F_11 ( V_2 -> V_30 . V_32 ) ;
V_27 >>= 3 ;
for ( V_28 = 0 ; V_28 < V_33 ; V_28 ++ ) {
struct V_34 * V_35 = V_2 -> V_36 [ V_28 ] ;
int V_37 = V_35 -> V_38 >> 1 ;
int V_39 = 1 ;
int V_40 ;
if ( ! ( V_35 -> V_38 & 1 ) )
continue;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
if ( F_12 ( V_35 -> V_43 . V_44 )
|| F_13 ( V_35 -> V_43 . V_44 ) )
V_39 = 3 ;
V_40 = V_39 * ( V_35 -> V_43 . V_45 + V_27 ) ;
V_40 += V_27 ;
V_26 = F_14 ( V_40 , V_27 ) ;
V_26 |= ( V_24 << 16 ) ;
F_8 ( V_2 -> V_23 , L_2 ,
V_35 -> V_46 , V_24 , V_26 & 0xffff ) ;
F_3 ( V_2 -> V_5 , F_15 ( V_37 ) ,
V_26 ) ;
V_24 += ( V_26 & 0xffff ) ;
}
return 0 ;
}
void F_16 ( struct V_34 * V_35 , struct V_47 * V_48 ,
int V_49 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_48 -> V_50 ) {
if ( V_48 -> V_51 . V_52 )
V_35 -> V_53 += V_48 -> V_51 . V_52 ;
else
V_35 -> V_53 ++ ;
if ( ( ( V_35 -> V_53 & V_54 ) == V_55 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
V_35 -> V_53 ++ ;
}
F_17 ( & V_48 -> V_56 ) ;
V_48 -> V_57 = NULL ;
if ( V_48 -> V_51 . V_49 == - V_58 )
V_48 -> V_51 . V_49 = V_49 ;
if ( V_2 -> V_59 && V_35 -> V_38 == 0 )
V_2 -> V_59 = false ;
else
F_18 ( & V_2 -> V_60 , & V_48 -> V_51 ,
V_48 -> V_61 ) ;
F_19 ( V_2 -> V_23 , L_3 ,
V_48 , V_35 -> V_46 , V_48 -> V_51 . V_62 ,
V_48 -> V_51 . V_63 , V_49 ) ;
F_20 ( & V_2 -> V_64 ) ;
V_48 -> V_51 . V_65 ( & V_35 -> V_43 , & V_48 -> V_51 ) ;
F_21 ( & V_2 -> V_64 ) ;
}
static const char * F_22 ( T_2 V_66 )
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
int F_23 ( struct V_1 * V_2 , int V_66 , T_1 V_76 )
{
T_1 V_77 = 500 ;
T_1 V_4 ;
F_3 ( V_2 -> V_5 , V_78 , V_76 ) ;
F_3 ( V_2 -> V_5 , V_79 , V_66 | V_80 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_79 ) ;
if ( ! ( V_4 & V_80 ) ) {
F_8 ( V_2 -> V_23 , L_14 ,
F_24 ( V_4 ) ) ;
return 0 ;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
}
int F_25 ( struct V_1 * V_2 , unsigned V_81 ,
unsigned V_66 , struct V_82 * V_83 )
{
struct V_34 * V_35 = V_2 -> V_36 [ V_81 ] ;
T_1 V_77 = 500 ;
T_1 V_4 ;
F_8 ( V_2 -> V_23 , L_15 ,
V_35 -> V_46 ,
F_22 ( V_66 ) , V_83 -> V_84 ,
V_83 -> V_85 , V_83 -> V_86 ) ;
F_3 ( V_2 -> V_5 , F_26 ( V_81 ) , V_83 -> V_84 ) ;
F_3 ( V_2 -> V_5 , F_27 ( V_81 ) , V_83 -> V_85 ) ;
F_3 ( V_2 -> V_5 , F_28 ( V_81 ) , V_83 -> V_86 ) ;
F_3 ( V_2 -> V_5 , F_29 ( V_81 ) , V_66 | V_87 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , F_29 ( V_81 ) ) ;
if ( ! ( V_4 & V_87 ) ) {
F_8 ( V_2 -> V_23 , L_14 ,
F_30 ( V_4 ) ) ;
return 0 ;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
}
static T_3 F_31 ( struct V_34 * V_35 ,
struct V_88 * V_57 )
{
T_1 V_89 = ( char * ) V_57 - ( char * ) V_35 -> V_90 ;
return V_35 -> V_91 + V_89 ;
}
static int F_32 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_35 -> V_90 )
return 0 ;
if ( V_35 -> V_38 == 0 || V_35 -> V_38 == 1 )
return 0 ;
V_35 -> V_90 = F_33 ( V_2 -> V_23 ,
sizeof( struct V_88 ) * V_55 ,
& V_35 -> V_91 , V_92 ) ;
if ( ! V_35 -> V_90 ) {
F_34 ( V_35 -> V_2 -> V_23 , L_16 ,
V_35 -> V_46 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_35 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_36 ( V_2 -> V_23 , sizeof( struct V_88 ) * V_55 ,
V_35 -> V_90 , V_35 -> V_91 ) ;
V_35 -> V_90 = NULL ;
V_35 -> V_91 = 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_82 V_83 ;
T_1 V_66 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
if ( V_35 -> V_38 != 1 ) {
V_66 = V_67 ;
if ( V_35 -> V_38 > 1 ) {
if ( V_2 -> V_94 )
return 0 ;
V_2 -> V_94 = true ;
V_66 |= F_38 ( 2 ) ;
}
return F_25 ( V_2 , 0 , V_66 , & V_83 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_95 * V_44 ,
const struct V_96 * V_97 ,
bool V_98 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_40 ( F_41 ( V_44 ) )
| F_42 ( F_43 ( V_44 ) ) ;
if ( V_2 -> V_60 . V_99 == V_100 ) {
T_1 V_101 = V_35 -> V_43 . V_102 - 1 ;
V_83 . V_84 |= F_44 ( V_101 ) ;
}
if ( V_98 )
V_83 . V_84 |= V_103 ;
V_83 . V_85 = V_104
| V_105 ;
if ( F_45 ( V_97 ) && F_12 ( V_44 ) ) {
V_83 . V_85 |= V_106
| V_107 ;
V_35 -> V_108 = true ;
}
if ( F_13 ( V_44 ) )
V_83 . V_85 |= V_109 ;
V_83 . V_85 |= F_46 ( V_35 -> V_38 ) ;
if ( V_35 -> V_61 )
V_83 . V_84 |= F_47 ( V_35 -> V_38 >> 1 ) ;
if ( V_44 -> V_110 ) {
V_83 . V_85 |= F_48 ( V_44 -> V_110 - 1 ) ;
V_35 -> V_111 = 1 << ( V_44 -> V_110 - 1 ) ;
}
return F_25 ( V_2 , V_35 -> V_38 ,
V_75 , & V_83 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_50 ( 1 ) ;
return F_25 ( V_2 , V_35 -> V_38 ,
V_74 , & V_83 ) ;
}
static int F_51 ( struct V_34 * V_35 ,
const struct V_95 * V_44 ,
const struct V_96 * V_97 ,
bool V_98 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
int V_112 = - V_93 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
V_112 = F_37 ( V_2 , V_35 ) ;
if ( V_112 )
return V_112 ;
}
V_112 = F_39 ( V_2 , V_35 , V_44 , V_97 , V_98 ) ;
if ( V_112 )
return V_112 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
struct V_88 * V_113 ;
struct V_88 * V_114 ;
V_112 = F_49 ( V_2 , V_35 ) ;
if ( V_112 )
return V_112 ;
V_35 -> V_43 . V_44 = V_44 ;
V_35 -> V_97 = V_97 ;
V_35 -> type = F_41 ( V_44 ) ;
V_35 -> V_41 |= V_42 ;
V_4 = F_2 ( V_2 -> V_5 , V_115 ) ;
V_4 |= F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_115 , V_4 ) ;
if ( ! F_13 ( V_44 ) )
return 0 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_113 = & V_35 -> V_90 [ 0 ] ;
V_114 = & V_35 -> V_90 [ V_55 - 1 ] ;
V_114 -> V_116 = F_53 ( F_31 ( V_35 , V_113 ) ) ;
V_114 -> V_117 = F_54 ( F_31 ( V_35 , V_113 ) ) ;
V_114 -> V_118 |= V_119 ;
V_114 -> V_118 |= V_120 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_47 * V_48 ;
if ( ! F_56 ( & V_35 -> V_121 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
while ( ! F_56 ( & V_35 -> V_121 ) ) {
V_48 = F_58 ( & V_35 -> V_121 ) ;
F_16 ( V_35 , V_48 , - V_122 ) ;
}
}
while ( ! F_56 ( & V_35 -> V_123 ) ) {
V_48 = F_58 ( & V_35 -> V_123 ) ;
F_16 ( V_35 , V_48 , - V_122 ) ;
}
}
static int F_59 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
F_55 ( V_2 , V_35 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_115 ) ;
V_4 &= ~ F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_115 , V_4 ) ;
V_35 -> V_108 = false ;
V_35 -> V_43 . V_44 = NULL ;
V_35 -> V_97 = NULL ;
V_35 -> type = 0 ;
V_35 -> V_41 = 0 ;
return 0 ;
}
static int F_60 ( struct V_124 * V_81 ,
const struct V_95 * V_44 )
{
return - V_13 ;
}
static int F_61 ( struct V_124 * V_81 )
{
return - V_13 ;
}
static int F_62 ( struct V_124 * V_81 ,
const struct V_95 * V_44 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_112 ;
if ( ! V_81 || ! V_44 || V_44 -> V_125 != V_126 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
if ( ! V_44 -> V_127 ) {
F_63 ( L_18 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
if ( V_35 -> V_41 & V_42 ) {
F_65 ( V_2 -> V_23 , true , L_19 ,
V_35 -> V_46 ) ;
return 0 ;
}
switch ( F_41 ( V_44 ) ) {
case V_128 :
F_66 ( V_35 -> V_46 , L_20 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_129 :
F_66 ( V_35 -> V_46 , L_21 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_130 :
F_66 ( V_35 -> V_46 , L_22 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_131 :
F_66 ( V_35 -> V_46 , L_23 , sizeof( V_35 -> V_46 ) ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_24 ) ;
}
F_8 ( V_2 -> V_23 , L_25 , V_35 -> V_46 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_112 = F_51 ( V_35 , V_44 , V_81 -> V_97 , false ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_69 ( struct V_124 * V_81 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_112 ;
if ( ! V_81 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
F_65 ( V_2 -> V_23 , true , L_26 ,
V_35 -> V_46 ) ;
return 0 ;
}
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 ,
V_35 -> V_38 >> 1 ,
( V_35 -> V_38 & 1 ) ? L_28 : L_29 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_112 = F_59 ( V_35 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static struct V_132 * F_70 ( struct V_124 * V_81 ,
T_4 V_133 )
{
struct V_47 * V_48 ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
V_48 = F_71 ( sizeof( * V_48 ) , V_133 ) ;
if ( ! V_48 ) {
F_34 ( V_2 -> V_23 , L_30 ) ;
return NULL ;
}
V_48 -> V_134 = V_35 -> V_38 ;
V_48 -> V_35 = V_35 ;
return & V_48 -> V_51 ;
}
static void F_72 ( struct V_124 * V_81 ,
struct V_132 * V_51 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
F_74 ( V_48 ) ;
}
static void F_75 ( struct V_34 * V_35 ,
struct V_47 * V_48 , T_3 V_135 ,
unsigned V_63 , unsigned V_136 , unsigned V_137 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_88 * V_57 ;
unsigned int V_138 ;
F_8 ( V_2 -> V_23 , L_31 ,
V_35 -> V_46 , V_48 , ( unsigned long long ) V_135 ,
V_63 , V_136 ? L_32 : L_33 ,
V_137 ? L_34 : L_33 ) ;
V_57 = & V_35 -> V_90 [ V_35 -> V_139 & V_54 ] ;
V_138 = V_35 -> V_139 ;
V_35 -> V_139 ++ ;
if ( ( ( V_138 & V_54 ) == V_55 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
return;
if ( ! V_48 -> V_57 ) {
F_76 ( V_48 ) ;
V_48 -> V_57 = V_57 ;
V_48 -> V_140 = F_31 ( V_35 , V_57 ) ;
}
V_57 -> V_141 = F_77 ( V_63 ) ;
V_57 -> V_116 = F_53 ( V_135 ) ;
V_57 -> V_117 = F_54 ( V_135 ) ;
switch ( F_41 ( V_35 -> V_43 . V_44 ) ) {
case V_128 :
V_57 -> V_118 = V_142 ;
break;
case V_129 :
V_57 -> V_118 = V_143 ;
if ( ! V_48 -> V_51 . V_144 )
V_57 -> V_118 |= V_145 ;
break;
case V_130 :
case V_131 :
V_57 -> V_118 = V_146 ;
break;
default:
F_78 () ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_57 -> V_118 |= V_147 ;
V_57 -> V_118 |= V_148 ;
} else {
if ( V_137 )
V_57 -> V_118 |= V_149 ;
if ( V_136 )
V_57 -> V_118 |= V_150 ;
}
if ( F_12 ( V_35 -> V_43 . V_44 ) && V_35 -> V_108 )
V_57 -> V_118 |= F_79 ( V_48 -> V_51 . V_151 ) ;
V_57 -> V_118 |= V_120 ;
}
static void F_80 ( struct V_34 * V_35 , bool V_152 )
{
struct V_47 * V_48 , * V_153 ;
T_1 V_154 ;
T_1 V_155 ;
unsigned int V_156 = 0 ;
F_81 ( V_55 ) ;
V_154 = ( V_35 -> V_53 - V_35 -> V_139 ) & V_54 ;
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
V_155 = V_55 - ( V_35 -> V_139 & V_54 ) ;
if ( V_154 > V_155 )
V_154 = V_155 ;
}
if ( ! V_154 ) {
if ( ! V_152 )
return;
V_154 = V_55 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_35 -> V_53 = 1 ;
V_35 -> V_139 = 1 ;
} else {
V_35 -> V_53 = 0 ;
V_35 -> V_139 = 0 ;
}
}
if ( ( V_154 <= 1 ) && F_13 ( V_35 -> V_43 . V_44 ) )
return;
F_82 (req, n, &dep->request_list, list) {
unsigned V_63 ;
T_3 V_135 ;
if ( V_48 -> V_51 . V_52 > 0 ) {
struct V_132 * V_51 = & V_48 -> V_51 ;
struct V_157 * V_158 = V_51 -> V_158 ;
struct V_157 * V_159 ;
int V_160 ;
F_83 (sg, s, request->num_mapped_sgs, i) {
unsigned V_137 = true ;
V_63 = F_84 ( V_159 ) ;
V_135 = F_85 ( V_159 ) ;
if ( V_160 == ( V_51 -> V_52 - 1 ) ||
F_86 ( V_159 ) ) {
V_156 = true ;
V_137 = false ;
}
V_154 -- ;
if ( ! V_154 )
V_156 = true ;
if ( V_156 )
V_137 = false ;
F_75 ( V_35 , V_48 , V_135 , V_63 ,
V_156 , V_137 ) ;
if ( V_156 )
break;
}
} else {
V_135 = V_48 -> V_51 . V_135 ;
V_63 = V_48 -> V_51 . V_63 ;
V_154 -- ;
if ( ! V_154 )
V_156 = 1 ;
if ( F_87 ( & V_48 -> V_56 , & V_35 -> V_123 ) )
V_156 = 1 ;
F_75 ( V_35 , V_48 , V_135 , V_63 ,
V_156 , false ) ;
if ( V_156 )
break;
}
}
}
static int F_88 ( struct V_34 * V_35 , T_5 V_161 ,
int V_162 )
{
struct V_82 V_83 ;
struct V_47 * V_48 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_112 ;
T_1 V_66 ;
if ( V_162 && ( V_35 -> V_41 & V_163 ) ) {
F_8 ( V_2 -> V_23 , L_35 , V_35 -> V_46 ) ;
return - V_164 ;
}
V_35 -> V_41 &= ~ V_165 ;
if ( V_162 ) {
if ( F_56 ( & V_35 -> V_121 ) )
F_80 ( V_35 , V_162 ) ;
V_48 = F_58 ( & V_35 -> V_121 ) ;
} else {
F_80 ( V_35 , V_162 ) ;
V_48 = F_58 ( & V_35 -> V_121 ) ;
}
if ( ! V_48 ) {
V_35 -> V_41 |= V_165 ;
return 0 ;
}
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_54 ( V_48 -> V_140 ) ;
V_83 . V_85 = F_53 ( V_48 -> V_140 ) ;
if ( V_162 )
V_66 = V_70 ;
else
V_66 = V_69 ;
V_66 |= F_38 ( V_161 ) ;
V_112 = F_25 ( V_2 , V_35 -> V_38 , V_66 , & V_83 ) ;
if ( V_112 < 0 ) {
F_19 ( V_2 -> V_23 , L_36 ) ;
F_18 ( & V_2 -> V_60 , & V_48 -> V_51 ,
V_48 -> V_61 ) ;
F_17 ( & V_48 -> V_56 ) ;
return V_112 ;
}
V_35 -> V_41 |= V_163 ;
if ( V_162 ) {
V_35 -> V_166 = F_89 ( V_2 ,
V_35 -> V_38 ) ;
F_90 ( ! V_35 -> V_166 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_167 )
{
T_1 V_168 ;
if ( F_56 ( & V_35 -> V_123 ) ) {
F_8 ( V_2 -> V_23 , L_37 ,
V_35 -> V_46 ) ;
V_35 -> V_41 |= V_165 ;
return;
}
V_168 = V_167 + V_35 -> V_111 * 4 ;
F_88 ( V_35 , V_168 , 1 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_169 * V_170 )
{
T_1 V_167 , V_171 ;
V_171 = ~ ( V_35 -> V_111 - 1 ) ;
V_167 = V_170 -> V_172 & V_171 ;
F_91 ( V_2 , V_35 , V_167 ) ;
}
static int F_93 ( struct V_34 * V_35 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_112 ;
V_48 -> V_51 . V_62 = 0 ;
V_48 -> V_51 . V_49 = - V_58 ;
V_48 -> V_61 = V_35 -> V_61 ;
V_48 -> V_134 = V_35 -> V_38 ;
V_112 = F_94 ( & V_2 -> V_60 , & V_48 -> V_51 ,
V_35 -> V_61 ) ;
if ( V_112 )
return V_112 ;
F_95 ( & V_48 -> V_56 , & V_35 -> V_123 ) ;
if ( V_35 -> V_41 & V_165 ) {
int V_112 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
return 0 ;
}
V_112 = F_88 ( V_35 , 0 , true ) ;
if ( V_112 && V_112 != - V_164 )
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
( V_35 -> V_41 & V_163 ) &&
! ( V_35 -> V_41 & V_173 ) ) {
F_90 ( ! V_35 -> V_166 ) ;
V_112 = F_88 ( V_35 , V_35 -> V_166 ,
false ) ;
if ( V_112 && V_112 != - V_164 )
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
( V_35 -> V_41 & V_173 ) ) {
F_91 ( V_2 , V_35 , V_35 -> V_174 ) ;
V_35 -> V_41 &= ~ V_173 ;
}
return 0 ;
}
static int F_96 ( struct V_124 * V_81 , struct V_132 * V_51 ,
T_4 V_133 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_112 ;
if ( ! V_35 -> V_43 . V_44 ) {
F_19 ( V_2 -> V_23 , L_39 ,
V_51 , V_81 -> V_46 ) ;
return - V_122 ;
}
F_8 ( V_2 -> V_23 , L_40 ,
V_51 , V_81 -> V_46 , V_51 -> V_63 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_112 = F_93 ( V_35 , V_48 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_97 ( struct V_124 * V_81 ,
struct V_132 * V_51 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
struct V_47 * V_175 = NULL ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_112 = 0 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
F_98 (r, &dep->request_list, list) {
if ( V_175 == V_48 )
break;
}
if ( V_175 != V_48 ) {
F_98 (r, &dep->req_queued, list) {
if ( V_175 == V_48 )
break;
}
if ( V_175 == V_48 ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
goto V_176;
}
F_34 ( V_2 -> V_23 , L_41 ,
V_51 , V_81 -> V_46 ) ;
V_112 = - V_13 ;
goto V_177;
}
V_176:
F_16 ( V_35 , V_48 , - V_178 ) ;
V_177:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
int F_99 ( struct V_34 * V_35 , int V_179 )
{
struct V_82 V_83 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_112 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
if ( V_179 ) {
V_112 = F_25 ( V_2 , V_35 -> V_38 ,
V_72 , & V_83 ) ;
if ( V_112 )
F_34 ( V_2 -> V_23 , L_42 ,
V_179 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 |= V_180 ;
} else {
if ( V_35 -> V_41 & V_181 )
return 0 ;
V_112 = F_25 ( V_2 , V_35 -> V_38 ,
V_71 , & V_83 ) ;
if ( V_112 )
F_34 ( V_2 -> V_23 , L_42 ,
V_179 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 &= ~ V_180 ;
}
return V_112 ;
}
static int F_100 ( struct V_124 * V_81 , int V_179 )
{
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_112 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_45 , V_35 -> V_46 ) ;
V_112 = - V_13 ;
goto V_182;
}
V_112 = F_99 ( V_35 , V_179 ) ;
V_182:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_101 ( struct V_124 * V_81 )
{
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_35 -> V_41 |= V_181 ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
if ( V_35 -> V_38 == 0 || V_35 -> V_38 == 1 )
return F_102 ( V_81 , 1 ) ;
else
return F_100 ( V_81 , 1 ) ;
}
static int F_103 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
return F_105 ( V_4 ) ;
}
static int F_106 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
unsigned long V_77 ;
unsigned long V_41 ;
T_1 V_4 ;
int V_112 = 0 ;
T_2 V_185 ;
T_2 V_99 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_99 = V_4 & V_186 ;
if ( V_99 == V_187 ) {
F_19 ( V_2 -> V_23 , L_46 ) ;
V_112 = - V_13 ;
goto V_182;
}
V_185 = F_7 ( V_4 ) ;
switch ( V_185 ) {
case V_188 :
case V_189 :
break;
default:
F_19 ( V_2 -> V_23 , L_47 ,
V_185 ) ;
V_112 = - V_13 ;
goto V_182;
}
V_112 = F_4 ( V_2 , V_190 ) ;
if ( V_112 < 0 ) {
F_34 ( V_2 -> V_23 , L_48 ) ;
goto V_182;
}
if ( V_2 -> V_17 < V_18 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_77 = V_191 + F_107 ( 100 ) ;
while ( ! F_108 ( V_191 , V_77 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( F_7 ( V_4 ) == V_192 )
break;
}
if ( F_7 ( V_4 ) != V_192 ) {
F_34 ( V_2 -> V_23 , L_49 ) ;
V_112 = - V_13 ;
}
V_182:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_109 ( struct V_183 * V_184 ,
int V_193 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_2 -> V_193 = ! ! V_193 ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , int V_194 )
{
T_1 V_4 ;
T_1 V_77 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_194 ) {
if ( V_2 -> V_17 <= V_195 ) {
V_4 &= ~ V_196 ;
V_4 |= V_197 ;
}
if ( V_2 -> V_17 >= V_18 )
V_4 &= ~ V_198 ;
V_4 |= V_199 ;
} else {
V_4 &= ~ V_199 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( V_194 ) {
if ( ! ( V_4 & V_200 ) )
break;
} else {
if ( V_4 & V_200 )
break;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
F_8 ( V_2 -> V_23 , L_50 ,
V_2 -> V_201
? V_2 -> V_201 -> V_202 : L_51 ,
V_194 ? L_52 : L_53 ) ;
return 0 ;
}
static int F_111 ( struct V_183 * V_184 , int V_194 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
unsigned long V_41 ;
int V_112 ;
V_194 = ! ! V_194 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_112 = F_110 ( V_2 , V_194 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_112 ( struct V_183 * V_184 ,
struct V_203 * V_204 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
struct V_34 * V_35 ;
unsigned long V_41 ;
int V_112 = 0 ;
T_1 V_4 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
if ( V_2 -> V_201 ) {
F_34 ( V_2 -> V_23 , L_54 ,
V_2 -> V_60 . V_46 ,
V_2 -> V_201 -> V_204 . V_46 ) ;
V_112 = - V_164 ;
goto V_205;
}
V_2 -> V_201 = V_204 ;
V_2 -> V_60 . V_23 . V_204 = & V_204 -> V_204 ;
V_4 = F_2 ( V_2 -> V_5 , V_206 ) ;
V_4 &= ~ ( V_207 ) ;
if ( V_2 -> V_17 < V_208 )
V_4 |= V_209 ;
else
V_4 |= V_2 -> V_210 ;
F_3 ( V_2 -> V_5 , V_206 , V_4 ) ;
V_2 -> V_94 = false ;
V_211 . V_127 = F_113 ( 512 ) ;
V_35 = V_2 -> V_36 [ 0 ] ;
V_112 = F_51 ( V_35 , & V_211 , NULL , false ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_205;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_112 = F_51 ( V_35 , & V_211 , NULL , false ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_212;
}
V_2 -> V_213 = V_214 ;
F_114 ( V_2 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
V_212:
F_59 ( V_2 -> V_36 [ 0 ] ) ;
V_205:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_112 ;
}
static int F_115 ( struct V_183 * V_184 ,
struct V_203 * V_204 )
{
struct V_1 * V_2 = F_104 ( V_184 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
F_59 ( V_2 -> V_36 [ 0 ] ) ;
F_59 ( V_2 -> V_36 [ 1 ] ) ;
V_2 -> V_201 = NULL ;
V_2 -> V_60 . V_23 . V_204 = NULL ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
}
static int T_6 F_116 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_134 ;
F_117 ( & V_2 -> V_60 . V_215 ) ;
for ( V_134 = 0 ; V_134 < V_33 ; V_134 ++ ) {
V_35 = F_71 ( sizeof( * V_35 ) , V_92 ) ;
if ( ! V_35 ) {
F_34 ( V_2 -> V_23 , L_56 ,
V_134 ) ;
return - V_93 ;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_38 = V_134 ;
V_2 -> V_36 [ V_134 ] = V_35 ;
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 , V_134 >> 1 ,
( V_134 & 1 ) ? L_28 : L_29 ) ;
V_35 -> V_43 . V_46 = V_35 -> V_46 ;
V_35 -> V_61 = ( V_134 & 1 ) ;
if ( V_134 == 0 || V_134 == 1 ) {
V_35 -> V_43 . V_45 = 512 ;
V_35 -> V_43 . V_216 = & V_217 ;
if ( ! V_134 )
V_2 -> V_60 . V_218 = & V_35 -> V_43 ;
} else {
int V_112 ;
V_35 -> V_43 . V_45 = 1024 ;
V_35 -> V_43 . V_219 = 15 ;
V_35 -> V_43 . V_216 = & V_220 ;
F_95 ( & V_35 -> V_43 . V_215 ,
& V_2 -> V_60 . V_215 ) ;
V_112 = F_32 ( V_35 ) ;
if ( V_112 )
return V_112 ;
}
F_117 ( & V_35 -> V_123 ) ;
F_117 ( & V_35 -> V_121 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_134 ;
for ( V_134 = 0 ; V_134 < V_33 ; V_134 ++ ) {
V_35 = V_2 -> V_36 [ V_134 ] ;
F_35 ( V_35 ) ;
if ( V_134 != 0 && V_134 != 1 )
F_17 ( & V_35 -> V_43 . V_215 ) ;
F_74 ( V_35 ) ;
}
}
static void F_119 ( struct V_221 * V_23 )
{
F_19 ( V_23 , L_57 , V_222 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_169 * V_170 , int V_49 )
{
struct V_47 * V_48 ;
struct V_88 * V_57 ;
unsigned int V_223 ;
unsigned int V_224 = 0 ;
unsigned int V_225 ;
do {
V_48 = F_58 ( & V_35 -> V_121 ) ;
if ( ! V_48 ) {
F_90 ( 1 ) ;
return 1 ;
}
V_57 = V_48 -> V_57 ;
if ( ( V_57 -> V_118 & V_120 ) && V_49 != - V_122 )
F_34 ( V_2 -> V_23 , L_58 ,
V_35 -> V_46 , V_48 -> V_57 ) ;
V_223 = V_57 -> V_141 & V_226 ;
if ( V_35 -> V_61 ) {
if ( V_223 ) {
V_225 = F_121 ( V_57 -> V_141 ) ;
if ( V_225 == V_227 ) {
F_19 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_35 -> V_174 = V_170 -> V_172 &
~ ( V_35 -> V_111 - 1 ) ;
V_35 -> V_41 |= V_173 ;
} else {
F_34 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_49 = - V_178 ;
}
}
} else {
if ( V_223 && ( V_170 -> V_49 & V_228 ) )
V_224 = 1 ;
}
V_48 -> V_51 . V_62 += V_48 -> V_51 . V_63 - V_223 ;
F_16 ( V_35 , V_48 , V_49 ) ;
if ( V_224 )
break;
if ( ( V_170 -> V_49 & V_229 ) &&
( V_57 -> V_118 & ( V_150 |
V_120 ) ) )
break;
if ( ( V_170 -> V_49 & V_230 ) &&
( V_57 -> V_118 & V_145 ) )
break;
} while ( 1 );
if ( ( V_170 -> V_49 & V_230 ) &&
( V_57 -> V_118 & V_145 ) )
return 0 ;
return 1 ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_169 * V_170 ,
int V_162 )
{
unsigned V_49 = 0 ;
int V_231 ;
if ( V_170 -> V_49 & V_232 )
V_49 = - V_178 ;
V_231 = F_120 ( V_2 , V_35 , V_170 , V_49 ) ;
if ( V_231 )
V_35 -> V_41 &= ~ V_163 ;
if ( V_2 -> V_17 < V_233 ) {
T_1 V_4 ;
int V_160 ;
for ( V_160 = 0 ; V_160 < V_33 ; V_160 ++ ) {
V_35 = V_2 -> V_36 [ V_160 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
if ( ! F_56 ( & V_35 -> V_121 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_234 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_234 = 0 ;
}
}
static void F_123 ( struct V_1 * V_2 ,
const struct V_169 * V_170 )
{
struct V_34 * V_35 ;
T_2 V_134 = V_170 -> V_235 ;
V_35 = V_2 -> V_36 [ V_134 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
return;
F_8 ( V_2 -> V_23 , L_60 , V_35 -> V_46 ,
F_124 ( V_170 -> V_236 ) ) ;
if ( V_134 == 0 || V_134 == 1 ) {
F_125 ( V_2 , V_170 ) ;
return;
}
switch ( V_170 -> V_236 ) {
case V_237 :
V_35 -> V_166 = 0 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_61 ,
V_35 -> V_46 ) ;
return;
}
F_122 ( V_2 , V_35 , V_170 , 1 ) ;
break;
case V_238 :
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_62 ,
V_35 -> V_46 ) ;
return;
}
F_122 ( V_2 , V_35 , V_170 , 0 ) ;
break;
case V_239 :
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_92 ( V_2 , V_35 , V_170 ) ;
} else {
int V_112 ;
F_8 ( V_2 -> V_23 , L_63 ,
V_35 -> V_46 , V_170 -> V_49 &
V_240
? L_64
: L_65 ) ;
V_112 = F_88 ( V_35 , 0 , 1 ) ;
if ( ! V_112 || V_112 == - V_164 )
return;
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
break;
case V_241 :
if ( ! F_12 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_66 ,
V_35 -> V_46 ) ;
return;
}
switch ( V_170 -> V_49 ) {
case V_242 :
F_8 ( V_2 -> V_23 , L_67 ,
V_170 -> V_172 ) ;
break;
case V_243 :
default:
F_19 ( V_2 -> V_23 , L_68 ) ;
}
break;
case V_244 :
F_19 ( V_2 -> V_23 , L_69 , V_35 -> V_46 ) ;
break;
case V_245 :
F_8 ( V_2 -> V_23 , L_70 ) ;
break;
}
}
static void F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_201 && V_2 -> V_201 -> V_246 ) {
F_20 ( & V_2 -> V_64 ) ;
V_2 -> V_201 -> V_246 ( & V_2 -> V_60 ) ;
F_21 ( & V_2 -> V_64 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , T_1 V_134 )
{
struct V_34 * V_35 ;
struct V_82 V_83 ;
T_1 V_66 ;
int V_112 ;
V_35 = V_2 -> V_36 [ V_134 ] ;
if ( ! V_35 -> V_166 )
return;
V_66 = V_68 ;
V_66 |= V_247 | V_248 ;
V_66 |= F_38 ( V_35 -> V_166 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_112 = F_25 ( V_2 , V_35 -> V_38 , V_66 , & V_83 ) ;
F_90 ( V_112 ) ;
V_35 -> V_166 = 0 ;
V_35 -> V_41 &= ~ V_163 ;
F_5 ( 100 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
T_1 V_134 ;
for ( V_134 = 2 ; V_134 < V_33 ; V_134 ++ ) {
struct V_34 * V_35 ;
V_35 = V_2 -> V_36 [ V_134 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
F_55 ( V_2 , V_35 ) ;
}
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_134 ;
for ( V_134 = 1 ; V_134 < V_33 ; V_134 ++ ) {
struct V_34 * V_35 ;
struct V_82 V_83 ;
int V_112 ;
V_35 = V_2 -> V_36 [ V_134 ] ;
if ( ! ( V_35 -> V_41 & V_180 ) )
continue;
V_35 -> V_41 &= ~ V_180 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_112 = F_25 ( V_2 , V_35 -> V_38 ,
V_71 , & V_83 ) ;
F_90 ( V_112 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
int V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_222 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_249 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 &= ~ V_250 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_126 ( V_2 ) ;
V_2 -> V_94 = false ;
V_2 -> V_60 . V_99 = V_251 ;
V_2 -> V_252 = false ;
}
static void F_130 ( struct V_1 * V_2 , int V_253 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_131 ( 0 ) ) ;
if ( V_253 )
V_4 |= V_254 ;
else
V_4 &= ~ V_254 ;
F_3 ( V_2 -> V_5 , F_131 ( 0 ) , V_4 ) ;
}
static void F_132 ( struct V_1 * V_2 , int V_253 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_133 ( 0 ) ) ;
if ( V_253 )
V_4 |= V_255 ;
else
V_4 &= ~ V_255 ;
F_3 ( V_2 -> V_5 , F_133 ( 0 ) , V_4 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_222 ) ;
if ( V_2 -> V_17 < V_256 ) {
if ( V_2 -> V_252 )
F_129 ( V_2 ) ;
}
V_2 -> V_257 = V_258 ;
if ( V_2 -> V_17 < V_18 ) {
F_132 ( V_2 , false ) ;
F_130 ( V_2 , false ) ;
}
if ( V_2 -> V_60 . V_99 != V_251 )
F_126 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_259 = false ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
V_2 -> V_94 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_206 ) ;
V_4 &= ~ ( V_260 ) ;
F_3 ( V_2 -> V_5 , V_206 , V_4 ) ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_99 )
{
T_1 V_4 ;
T_1 V_261 = V_262 ;
if ( V_99 != V_187 )
return;
if ( ! V_261 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_263 ) ;
V_4 |= F_136 ( V_261 ) ;
F_3 ( V_2 -> V_5 , V_263 , V_4 ) ;
}
static void F_137 ( struct V_1 * V_2 , T_2 V_99 )
{
switch ( V_99 ) {
case V_100 :
F_132 ( V_2 , true ) ;
break;
case V_264 :
case V_265 :
case V_266 :
F_130 ( V_2 , true ) ;
break;
}
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
struct V_34 * V_35 ;
int V_112 ;
T_1 V_4 ;
T_2 V_99 ;
F_8 ( V_2 -> V_23 , L_57 , V_222 ) ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_99 = V_4 & V_186 ;
V_2 -> V_99 = V_99 ;
F_135 ( V_2 , V_99 ) ;
switch ( V_99 ) {
case V_209 :
if ( V_2 -> V_17 < V_267 )
F_134 ( V_2 ) ;
V_211 . V_127 = F_113 ( 512 ) ;
V_2 -> V_60 . V_218 -> V_45 = 512 ;
V_2 -> V_60 . V_99 = V_100 ;
break;
case V_268 :
V_211 . V_127 = F_113 ( 64 ) ;
V_2 -> V_60 . V_218 -> V_45 = 64 ;
V_2 -> V_60 . V_99 = V_264 ;
break;
case V_269 :
case V_270 :
V_211 . V_127 = F_113 ( 64 ) ;
V_2 -> V_60 . V_218 -> V_45 = 64 ;
V_2 -> V_60 . V_99 = V_265 ;
break;
case V_271 :
V_211 . V_127 = F_113 ( 8 ) ;
V_2 -> V_60 . V_218 -> V_45 = 8 ;
V_2 -> V_60 . V_99 = V_266 ;
break;
}
if ( V_2 -> V_17 < V_18 ) {
F_137 ( V_2 , V_2 -> V_60 . V_99 ) ;
}
V_35 = V_2 -> V_36 [ 0 ] ;
V_112 = F_51 ( V_35 , & V_211 , NULL , true ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_112 = F_51 ( V_35 , & V_211 , NULL , true ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
}
static void F_139 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_23 , L_57 , V_222 ) ;
V_2 -> V_201 -> V_272 ( & V_2 -> V_60 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
unsigned int V_273 )
{
enum V_14 V_274 = V_273 & V_275 ;
if ( V_2 -> V_17 < V_233 ) {
if ( V_274 == V_192 ) {
T_1 V_234 ;
T_1 V_4 ;
switch ( V_2 -> V_185 ) {
case V_276 :
case V_277 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_234 = V_4 & ( V_250
| V_278
| V_249
| V_279 ) ;
if ( ! V_2 -> V_234 )
V_2 -> V_234 = V_4 & V_234 ;
V_4 &= ~ V_234 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_185 = V_274 ;
F_8 ( V_2 -> V_23 , L_71 , V_222 , V_2 -> V_185 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
const struct V_280 * V_170 )
{
switch ( V_170 -> type ) {
case V_281 :
F_129 ( V_2 ) ;
break;
case V_282 :
F_134 ( V_2 ) ;
break;
case V_283 :
F_138 ( V_2 ) ;
break;
case V_284 :
F_139 ( V_2 ) ;
break;
case V_285 :
F_140 ( V_2 , V_170 -> V_286 ) ;
break;
case V_287 :
F_8 ( V_2 -> V_23 , L_72 ) ;
break;
case V_288 :
F_8 ( V_2 -> V_23 , L_73 ) ;
break;
case V_289 :
F_8 ( V_2 -> V_23 , L_74 ) ;
break;
case V_290 :
F_8 ( V_2 -> V_23 , L_75 ) ;
break;
case V_291 :
F_8 ( V_2 -> V_23 , L_76 ) ;
break;
default:
F_19 ( V_2 -> V_23 , L_77 , V_170 -> type ) ;
}
}
static void F_142 ( struct V_1 * V_2 ,
const union V_292 * V_170 )
{
if ( V_170 -> type . V_293 == 0 ) {
return F_123 ( V_2 , & V_170 -> V_294 ) ;
}
switch ( V_170 -> type . type ) {
case V_295 :
F_141 ( V_2 , & V_170 -> V_296 ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_78 , V_170 -> V_297 ) ;
}
}
static T_7 F_143 ( struct V_1 * V_2 , T_1 V_298 )
{
struct V_299 * V_300 ;
int V_301 ;
T_1 V_223 ;
V_223 = F_2 ( V_2 -> V_5 , F_144 ( V_298 ) ) ;
V_223 &= V_302 ;
if ( ! V_223 )
return V_303 ;
V_300 = V_2 -> V_304 [ V_298 ] ;
V_301 = V_223 ;
while ( V_301 > 0 ) {
union V_292 V_170 ;
V_170 . V_297 = * ( T_1 * ) ( V_300 -> V_298 + V_300 -> V_305 ) ;
F_142 ( V_2 , & V_170 ) ;
V_300 -> V_305 = ( V_300 -> V_305 + 4 ) % V_306 ;
V_301 -= 4 ;
F_3 ( V_2 -> V_5 , F_144 ( V_298 ) , 4 ) ;
}
return V_307 ;
}
static T_7 F_145 ( int V_308 , void * V_309 )
{
struct V_1 * V_2 = V_309 ;
int V_160 ;
T_7 V_112 = V_303 ;
F_21 ( & V_2 -> V_64 ) ;
for ( V_160 = 0 ; V_160 < V_2 -> V_310 ; V_160 ++ ) {
T_7 V_49 ;
V_49 = F_143 ( V_2 , V_160 ) ;
if ( V_49 == V_307 )
V_112 = V_49 ;
}
F_20 ( & V_2 -> V_64 ) ;
return V_112 ;
}
int T_6 F_146 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_112 ;
int V_308 ;
V_2 -> V_311 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_311 ) ,
& V_2 -> V_312 , V_92 ) ;
if ( ! V_2 -> V_311 ) {
F_34 ( V_2 -> V_23 , L_79 ) ;
V_112 = - V_93 ;
goto V_205;
}
V_2 -> V_313 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_313 ) ,
& V_2 -> V_314 , V_92 ) ;
if ( ! V_2 -> V_313 ) {
F_34 ( V_2 -> V_23 , L_80 ) ;
V_112 = - V_93 ;
goto V_212;
}
V_2 -> V_315 = F_71 ( V_316 , V_92 ) ;
if ( ! V_2 -> V_315 ) {
F_34 ( V_2 -> V_23 , L_81 ) ;
V_112 = - V_93 ;
goto V_317;
}
V_2 -> V_318 = F_33 ( V_2 -> V_23 ,
V_316 , & V_2 -> V_319 ,
V_92 ) ;
if ( ! V_2 -> V_318 ) {
F_34 ( V_2 -> V_23 , L_82 ) ;
V_112 = - V_93 ;
goto V_320;
}
F_147 ( & V_2 -> V_60 . V_23 , L_83 ) ;
V_2 -> V_60 . V_216 = & V_321 ;
V_2 -> V_60 . V_322 = V_100 ;
V_2 -> V_60 . V_99 = V_251 ;
V_2 -> V_60 . V_23 . V_323 = V_2 -> V_23 ;
V_2 -> V_60 . V_324 = true ;
F_148 ( & V_2 -> V_60 . V_23 , V_2 -> V_23 -> V_325 ) ;
V_2 -> V_60 . V_23 . V_326 = V_2 -> V_23 -> V_326 ;
V_2 -> V_60 . V_23 . V_327 = V_2 -> V_23 -> V_327 ;
V_2 -> V_60 . V_23 . V_328 = F_119 ;
V_2 -> V_60 . V_46 = L_84 ;
V_112 = F_116 ( V_2 ) ;
if ( V_112 )
goto V_329;
V_308 = F_149 ( F_150 ( V_2 -> V_23 ) , 0 ) ;
V_112 = F_151 ( V_308 , F_145 , V_330 ,
L_85 , V_2 ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_86 ,
V_308 , V_112 ) ;
goto V_331;
}
V_4 = F_2 ( V_2 -> V_5 , V_206 ) ;
V_4 |= V_332 ;
F_3 ( V_2 -> V_5 , V_206 , V_4 ) ;
V_4 = ( V_333 |
V_334 |
V_335 |
V_336 |
V_337 |
V_338 |
V_339 |
V_340 |
V_341 ) ;
F_3 ( V_2 -> V_5 , V_342 , V_4 ) ;
if ( V_2 -> V_17 >= V_18 ) {
V_4 = F_2 ( V_2 -> V_5 , V_206 ) ;
V_4 |= V_332 ;
F_3 ( V_2 -> V_5 , V_206 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ ( V_343 | V_344 ) ;
V_4 |= F_152 ( 28 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_132 ( V_2 , false ) ;
F_130 ( V_2 , false ) ;
}
V_112 = F_153 ( & V_2 -> V_60 . V_23 ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_87 ) ;
F_154 ( & V_2 -> V_60 . V_23 ) ;
goto V_345;
}
V_112 = F_155 ( V_2 -> V_23 , & V_2 -> V_60 ) ;
if ( V_112 ) {
F_34 ( V_2 -> V_23 , L_88 ) ;
goto V_346;
}
return 0 ;
V_346:
F_156 ( & V_2 -> V_60 . V_23 ) ;
V_345:
F_3 ( V_2 -> V_5 , V_342 , 0x00 ) ;
F_157 ( V_308 , V_2 ) ;
V_331:
F_118 ( V_2 ) ;
V_329:
F_36 ( V_2 -> V_23 , V_316 ,
V_2 -> V_318 , V_2 -> V_319 ) ;
V_320:
F_74 ( V_2 -> V_315 ) ;
V_317:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_313 ) ,
V_2 -> V_313 , V_2 -> V_314 ) ;
V_212:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_311 ) ,
V_2 -> V_311 , V_2 -> V_312 ) ;
V_205:
return V_112 ;
}
void F_158 ( struct V_1 * V_2 )
{
int V_308 ;
F_159 ( & V_2 -> V_60 ) ;
V_308 = F_149 ( F_150 ( V_2 -> V_23 ) , 0 ) ;
F_3 ( V_2 -> V_5 , V_342 , 0x00 ) ;
F_157 ( V_308 , V_2 ) ;
F_118 ( V_2 ) ;
F_36 ( V_2 -> V_23 , V_316 ,
V_2 -> V_318 , V_2 -> V_319 ) ;
F_74 ( V_2 -> V_315 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_313 ) ,
V_2 -> V_313 , V_2 -> V_314 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_311 ) ,
V_2 -> V_311 , V_2 -> V_312 ) ;
F_156 ( & V_2 -> V_60 . V_23 ) ;
}
