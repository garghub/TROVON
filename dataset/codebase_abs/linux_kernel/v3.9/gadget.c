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
int V_50 ;
if ( V_48 -> V_51 ) {
V_50 = 0 ;
do {
V_35 -> V_52 ++ ;
if ( ( ( V_35 -> V_52 & V_53 ) ==
V_54 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
V_35 -> V_52 ++ ;
} while( ++ V_50 < V_48 -> V_55 . V_56 );
V_48 -> V_51 = false ;
}
F_17 ( & V_48 -> V_57 ) ;
V_48 -> V_58 = NULL ;
if ( V_48 -> V_55 . V_49 == - V_59 )
V_48 -> V_55 . V_49 = V_49 ;
if ( V_2 -> V_60 && V_35 -> V_38 == 0 )
V_2 -> V_60 = false ;
else
F_18 ( & V_2 -> V_61 , & V_48 -> V_55 ,
V_48 -> V_62 ) ;
F_19 ( V_2 -> V_23 , L_3 ,
V_48 , V_35 -> V_46 , V_48 -> V_55 . V_63 ,
V_48 -> V_55 . V_64 , V_49 ) ;
F_20 ( & V_2 -> V_65 ) ;
V_48 -> V_55 . V_66 ( & V_35 -> V_43 , & V_48 -> V_55 ) ;
F_21 ( & V_2 -> V_65 ) ;
}
static const char * F_22 ( T_2 V_67 )
{
switch ( V_67 ) {
case V_68 :
return L_4 ;
case V_69 :
return L_5 ;
case V_70 :
return L_6 ;
case V_71 :
return L_7 ;
case V_72 :
return L_8 ;
case V_73 :
return L_9 ;
case V_74 :
return L_10 ;
case V_75 :
return L_11 ;
case V_76 :
return L_12 ;
default:
return L_13 ;
}
}
int F_23 ( struct V_1 * V_2 , int V_67 , T_1 V_77 )
{
T_1 V_78 = 500 ;
T_1 V_4 ;
F_3 ( V_2 -> V_5 , V_79 , V_77 ) ;
F_3 ( V_2 -> V_5 , V_80 , V_67 | V_81 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_80 ) ;
if ( ! ( V_4 & V_81 ) ) {
F_8 ( V_2 -> V_23 , L_14 ,
F_24 ( V_4 ) ) ;
return 0 ;
}
V_78 -- ;
if ( ! V_78 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
}
int F_25 ( struct V_1 * V_2 , unsigned V_82 ,
unsigned V_67 , struct V_83 * V_84 )
{
struct V_34 * V_35 = V_2 -> V_36 [ V_82 ] ;
T_1 V_78 = 500 ;
T_1 V_4 ;
F_8 ( V_2 -> V_23 , L_15 ,
V_35 -> V_46 ,
F_22 ( V_67 ) , V_84 -> V_85 ,
V_84 -> V_86 , V_84 -> V_87 ) ;
F_3 ( V_2 -> V_5 , F_26 ( V_82 ) , V_84 -> V_85 ) ;
F_3 ( V_2 -> V_5 , F_27 ( V_82 ) , V_84 -> V_86 ) ;
F_3 ( V_2 -> V_5 , F_28 ( V_82 ) , V_84 -> V_87 ) ;
F_3 ( V_2 -> V_5 , F_29 ( V_82 ) , V_67 | V_88 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , F_29 ( V_82 ) ) ;
if ( ! ( V_4 & V_88 ) ) {
F_8 ( V_2 -> V_23 , L_14 ,
F_30 ( V_4 ) ) ;
return 0 ;
}
V_78 -- ;
if ( ! V_78 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
}
static T_3 F_31 ( struct V_34 * V_35 ,
struct V_89 * V_58 )
{
T_1 V_90 = ( char * ) V_58 - ( char * ) V_35 -> V_91 ;
return V_35 -> V_92 + V_90 ;
}
static int F_32 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_35 -> V_91 )
return 0 ;
if ( V_35 -> V_38 == 0 || V_35 -> V_38 == 1 )
return 0 ;
V_35 -> V_91 = F_33 ( V_2 -> V_23 ,
sizeof( struct V_89 ) * V_54 ,
& V_35 -> V_92 , V_93 ) ;
if ( ! V_35 -> V_91 ) {
F_34 ( V_35 -> V_2 -> V_23 , L_16 ,
V_35 -> V_46 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_35 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_36 ( V_2 -> V_23 , sizeof( struct V_89 ) * V_54 ,
V_35 -> V_91 , V_35 -> V_92 ) ;
V_35 -> V_91 = NULL ;
V_35 -> V_92 = 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_83 V_84 ;
T_1 V_67 ;
memset ( & V_84 , 0x00 , sizeof( V_84 ) ) ;
if ( V_35 -> V_38 != 1 ) {
V_67 = V_68 ;
if ( V_35 -> V_38 > 1 ) {
if ( V_2 -> V_95 )
return 0 ;
V_2 -> V_95 = true ;
V_67 |= F_38 ( 2 ) ;
}
return F_25 ( V_2 , 0 , V_67 , & V_84 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_96 * V_44 ,
const struct V_97 * V_98 ,
bool V_99 )
{
struct V_83 V_84 ;
memset ( & V_84 , 0x00 , sizeof( V_84 ) ) ;
V_84 . V_85 = F_40 ( F_41 ( V_44 ) )
| F_42 ( F_43 ( V_44 ) ) ;
if ( V_2 -> V_61 . V_100 == V_101 ) {
T_1 V_102 = V_35 -> V_43 . V_103 - 1 ;
V_84 . V_85 |= F_44 ( V_102 ) ;
}
if ( V_99 )
V_84 . V_85 |= V_104 ;
V_84 . V_86 = V_105
| V_106 ;
if ( F_45 ( V_98 ) && F_12 ( V_44 ) ) {
V_84 . V_86 |= V_107
| V_108 ;
V_35 -> V_109 = true ;
}
if ( F_13 ( V_44 ) )
V_84 . V_86 |= V_110 ;
V_84 . V_86 |= F_46 ( V_35 -> V_38 ) ;
if ( V_35 -> V_62 )
V_84 . V_85 |= F_47 ( V_35 -> V_38 >> 1 ) ;
if ( V_44 -> V_111 ) {
V_84 . V_86 |= F_48 ( V_44 -> V_111 - 1 ) ;
V_35 -> V_112 = 1 << ( V_44 -> V_111 - 1 ) ;
}
return F_25 ( V_2 , V_35 -> V_38 ,
V_76 , & V_84 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_83 V_84 ;
memset ( & V_84 , 0x00 , sizeof( V_84 ) ) ;
V_84 . V_85 = F_50 ( 1 ) ;
return F_25 ( V_2 , V_35 -> V_38 ,
V_75 , & V_84 ) ;
}
static int F_51 ( struct V_34 * V_35 ,
const struct V_96 * V_44 ,
const struct V_97 * V_98 ,
bool V_99 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
int V_113 = - V_94 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
V_113 = F_37 ( V_2 , V_35 ) ;
if ( V_113 )
return V_113 ;
}
V_113 = F_39 ( V_2 , V_35 , V_44 , V_98 , V_99 ) ;
if ( V_113 )
return V_113 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
struct V_89 * V_114 ;
struct V_89 * V_115 ;
V_113 = F_49 ( V_2 , V_35 ) ;
if ( V_113 )
return V_113 ;
V_35 -> V_43 . V_44 = V_44 ;
V_35 -> V_98 = V_98 ;
V_35 -> type = F_41 ( V_44 ) ;
V_35 -> V_41 |= V_42 ;
V_4 = F_2 ( V_2 -> V_5 , V_116 ) ;
V_4 |= F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_116 , V_4 ) ;
if ( ! F_13 ( V_44 ) )
return 0 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_114 = & V_35 -> V_91 [ 0 ] ;
V_115 = & V_35 -> V_91 [ V_54 - 1 ] ;
V_115 -> V_117 = F_53 ( F_31 ( V_35 , V_114 ) ) ;
V_115 -> V_118 = F_54 ( F_31 ( V_35 , V_114 ) ) ;
V_115 -> V_119 |= V_120 ;
V_115 -> V_119 |= V_121 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_47 * V_48 ;
if ( ! F_56 ( & V_35 -> V_122 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
while ( ! F_56 ( & V_35 -> V_122 ) ) {
V_48 = F_58 ( & V_35 -> V_122 ) ;
F_16 ( V_35 , V_48 , - V_123 ) ;
}
}
while ( ! F_56 ( & V_35 -> V_124 ) ) {
V_48 = F_58 ( & V_35 -> V_124 ) ;
F_16 ( V_35 , V_48 , - V_123 ) ;
}
}
static int F_59 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
F_55 ( V_2 , V_35 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_116 ) ;
V_4 &= ~ F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_116 , V_4 ) ;
V_35 -> V_109 = false ;
V_35 -> V_43 . V_44 = NULL ;
V_35 -> V_98 = NULL ;
V_35 -> type = 0 ;
V_35 -> V_41 = 0 ;
return 0 ;
}
static int F_60 ( struct V_125 * V_82 ,
const struct V_96 * V_44 )
{
return - V_13 ;
}
static int F_61 ( struct V_125 * V_82 )
{
return - V_13 ;
}
static int F_62 ( struct V_125 * V_82 ,
const struct V_96 * V_44 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_113 ;
if ( ! V_82 || ! V_44 || V_44 -> V_126 != V_127 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
if ( ! V_44 -> V_128 ) {
F_63 ( L_18 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_82 ) ;
V_2 = V_35 -> V_2 ;
if ( V_35 -> V_41 & V_42 ) {
F_65 ( V_2 -> V_23 , true , L_19 ,
V_35 -> V_46 ) ;
return 0 ;
}
switch ( F_41 ( V_44 ) ) {
case V_129 :
F_66 ( V_35 -> V_46 , L_20 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_130 :
F_66 ( V_35 -> V_46 , L_21 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_131 :
F_66 ( V_35 -> V_46 , L_22 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_132 :
F_66 ( V_35 -> V_46 , L_23 , sizeof( V_35 -> V_46 ) ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_24 ) ;
}
F_8 ( V_2 -> V_23 , L_25 , V_35 -> V_46 ) ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_113 = F_51 ( V_35 , V_44 , V_82 -> V_98 , false ) ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_69 ( struct V_125 * V_82 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_113 ;
if ( ! V_82 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_82 ) ;
V_2 = V_35 -> V_2 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
F_65 ( V_2 -> V_23 , true , L_26 ,
V_35 -> V_46 ) ;
return 0 ;
}
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 ,
V_35 -> V_38 >> 1 ,
( V_35 -> V_38 & 1 ) ? L_28 : L_29 ) ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_113 = F_59 ( V_35 ) ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static struct V_133 * F_70 ( struct V_125 * V_82 ,
T_4 V_134 )
{
struct V_47 * V_48 ;
struct V_34 * V_35 = F_64 ( V_82 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
V_48 = F_71 ( sizeof( * V_48 ) , V_134 ) ;
if ( ! V_48 ) {
F_34 ( V_2 -> V_23 , L_30 ) ;
return NULL ;
}
V_48 -> V_135 = V_35 -> V_38 ;
V_48 -> V_35 = V_35 ;
return & V_48 -> V_55 ;
}
static void F_72 ( struct V_125 * V_82 ,
struct V_133 * V_55 )
{
struct V_47 * V_48 = F_73 ( V_55 ) ;
F_74 ( V_48 ) ;
}
static void F_75 ( struct V_34 * V_35 ,
struct V_47 * V_48 , T_3 V_136 ,
unsigned V_64 , unsigned V_137 , unsigned V_138 , unsigned V_139 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_89 * V_58 ;
F_8 ( V_2 -> V_23 , L_31 ,
V_35 -> V_46 , V_48 , ( unsigned long long ) V_136 ,
V_64 , V_137 ? L_32 : L_33 ,
V_138 ? L_34 : L_33 ) ;
if ( ( ( V_35 -> V_140 & V_53 ) == V_54 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
V_35 -> V_140 ++ ;
V_58 = & V_35 -> V_91 [ V_35 -> V_140 & V_53 ] ;
if ( ! V_48 -> V_58 ) {
F_76 ( V_48 ) ;
V_48 -> V_58 = V_58 ;
V_48 -> V_141 = F_31 ( V_35 , V_58 ) ;
V_48 -> V_142 = V_35 -> V_140 & V_53 ;
}
V_35 -> V_140 ++ ;
V_58 -> V_143 = F_77 ( V_64 ) ;
V_58 -> V_117 = F_53 ( V_136 ) ;
V_58 -> V_118 = F_54 ( V_136 ) ;
switch ( F_41 ( V_35 -> V_43 . V_44 ) ) {
case V_129 :
V_58 -> V_119 = V_144 ;
break;
case V_130 :
if ( ! V_139 )
V_58 -> V_119 = V_145 ;
else
V_58 -> V_119 = V_146 ;
if ( ! V_48 -> V_55 . V_147 && ! V_138 )
V_58 -> V_119 |= V_148 ;
break;
case V_131 :
case V_132 :
V_58 -> V_119 = V_149 ;
break;
default:
F_78 () ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_58 -> V_119 |= V_150 ;
V_58 -> V_119 |= V_151 ;
} else if ( V_137 ) {
V_58 -> V_119 |= V_152 ;
}
if ( V_138 )
V_58 -> V_119 |= V_153 ;
if ( F_12 ( V_35 -> V_43 . V_44 ) && V_35 -> V_109 )
V_58 -> V_119 |= F_79 ( V_48 -> V_55 . V_154 ) ;
V_58 -> V_119 |= V_121 ;
}
static void F_80 ( struct V_34 * V_35 , bool V_155 )
{
struct V_47 * V_48 , * V_156 ;
T_1 V_157 ;
T_1 V_158 ;
unsigned int V_159 = 0 ;
F_81 ( V_54 ) ;
V_157 = ( V_35 -> V_52 - V_35 -> V_140 ) & V_53 ;
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
V_158 = V_54 - ( V_35 -> V_140 & V_53 ) ;
if ( V_157 > V_158 )
V_157 = V_158 ;
}
if ( ! V_157 ) {
if ( ! V_155 )
return;
V_157 = V_54 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_35 -> V_52 = 1 ;
V_35 -> V_140 = 1 ;
} else {
V_35 -> V_52 = 0 ;
V_35 -> V_140 = 0 ;
}
}
if ( ( V_157 <= 1 ) && F_13 ( V_35 -> V_43 . V_44 ) )
return;
F_82 (req, n, &dep->request_list, list) {
unsigned V_64 ;
T_3 V_136 ;
V_159 = false ;
if ( V_48 -> V_55 . V_56 > 0 ) {
struct V_133 * V_55 = & V_48 -> V_55 ;
struct V_160 * V_161 = V_55 -> V_161 ;
struct V_160 * V_162 ;
int V_50 ;
F_83 (sg, s, request->num_mapped_sgs, i) {
unsigned V_138 = true ;
V_64 = F_84 ( V_162 ) ;
V_136 = F_85 ( V_162 ) ;
if ( V_50 == ( V_55 -> V_56 - 1 ) ||
F_86 ( V_162 ) ) {
if ( F_87 ( & V_48 -> V_57 ,
& V_35 -> V_124 ) )
V_159 = true ;
V_138 = false ;
}
V_157 -- ;
if ( ! V_157 )
V_159 = true ;
if ( V_159 )
V_138 = false ;
F_75 ( V_35 , V_48 , V_136 , V_64 ,
V_159 , V_138 , V_50 ) ;
if ( V_159 )
break;
}
} else {
V_136 = V_48 -> V_55 . V_136 ;
V_64 = V_48 -> V_55 . V_64 ;
V_157 -- ;
if ( ! V_157 )
V_159 = 1 ;
if ( F_87 ( & V_48 -> V_57 , & V_35 -> V_124 ) )
V_159 = 1 ;
F_75 ( V_35 , V_48 , V_136 , V_64 ,
V_159 , false , 0 ) ;
if ( V_159 )
break;
}
}
}
static int F_88 ( struct V_34 * V_35 , T_5 V_163 ,
int V_164 )
{
struct V_83 V_84 ;
struct V_47 * V_48 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_113 ;
T_1 V_67 ;
if ( V_164 && ( V_35 -> V_41 & V_165 ) ) {
F_8 ( V_2 -> V_23 , L_35 , V_35 -> V_46 ) ;
return - V_166 ;
}
V_35 -> V_41 &= ~ V_167 ;
if ( V_164 ) {
if ( F_56 ( & V_35 -> V_122 ) )
F_80 ( V_35 , V_164 ) ;
V_48 = F_58 ( & V_35 -> V_122 ) ;
} else {
F_80 ( V_35 , V_164 ) ;
V_48 = F_58 ( & V_35 -> V_122 ) ;
}
if ( ! V_48 ) {
V_35 -> V_41 |= V_167 ;
return 0 ;
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_164 ) {
V_84 . V_85 = F_54 ( V_48 -> V_141 ) ;
V_84 . V_86 = F_53 ( V_48 -> V_141 ) ;
V_67 = V_71 ;
} else {
V_67 = V_70 ;
}
V_67 |= F_38 ( V_163 ) ;
V_113 = F_25 ( V_2 , V_35 -> V_38 , V_67 , & V_84 ) ;
if ( V_113 < 0 ) {
F_19 ( V_2 -> V_23 , L_36 ) ;
F_18 ( & V_2 -> V_61 , & V_48 -> V_55 ,
V_48 -> V_62 ) ;
F_17 ( & V_48 -> V_57 ) ;
return V_113 ;
}
V_35 -> V_41 |= V_165 ;
if ( V_164 ) {
V_35 -> V_168 = F_89 ( V_2 ,
V_35 -> V_38 ) ;
F_90 ( ! V_35 -> V_168 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_169 )
{
T_1 V_170 ;
if ( F_56 ( & V_35 -> V_124 ) ) {
F_8 ( V_2 -> V_23 , L_37 ,
V_35 -> V_46 ) ;
V_35 -> V_41 |= V_167 ;
return;
}
V_170 = V_169 + V_35 -> V_112 * 4 ;
F_88 ( V_35 , V_170 , 1 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_171 * V_172 )
{
T_1 V_169 , V_173 ;
V_173 = ~ ( V_35 -> V_112 - 1 ) ;
V_169 = V_172 -> V_174 & V_173 ;
F_91 ( V_2 , V_35 , V_169 ) ;
}
static int F_93 ( struct V_34 * V_35 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_113 ;
V_48 -> V_55 . V_63 = 0 ;
V_48 -> V_55 . V_49 = - V_59 ;
V_48 -> V_62 = V_35 -> V_62 ;
V_48 -> V_135 = V_35 -> V_38 ;
V_113 = F_94 ( & V_2 -> V_61 , & V_48 -> V_55 ,
V_35 -> V_62 ) ;
if ( V_113 )
return V_113 ;
F_95 ( & V_48 -> V_57 , & V_35 -> V_124 ) ;
if ( V_35 -> V_41 & V_167 ) {
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
if ( F_56 ( & V_35 -> V_122 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
V_35 -> V_41 = V_42 ;
}
return 0 ;
}
V_113 = F_88 ( V_35 , 0 , true ) ;
if ( V_113 && V_113 != - V_166 )
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
return V_113 ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
( V_35 -> V_41 & V_165 ) &&
! ( V_35 -> V_41 & V_175 ) ) {
F_90 ( ! V_35 -> V_168 ) ;
V_113 = F_88 ( V_35 , V_35 -> V_168 ,
false ) ;
if ( V_113 && V_113 != - V_166 )
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
return V_113 ;
}
return 0 ;
}
static int F_96 ( struct V_125 * V_82 , struct V_133 * V_55 ,
T_4 V_134 )
{
struct V_47 * V_48 = F_73 ( V_55 ) ;
struct V_34 * V_35 = F_64 ( V_82 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_113 ;
if ( ! V_35 -> V_43 . V_44 ) {
F_19 ( V_2 -> V_23 , L_39 ,
V_55 , V_82 -> V_46 ) ;
return - V_123 ;
}
F_8 ( V_2 -> V_23 , L_40 ,
V_55 , V_82 -> V_46 , V_55 -> V_64 ) ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_113 = F_93 ( V_35 , V_48 ) ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_97 ( struct V_125 * V_82 ,
struct V_133 * V_55 )
{
struct V_47 * V_48 = F_73 ( V_55 ) ;
struct V_47 * V_176 = NULL ;
struct V_34 * V_35 = F_64 ( V_82 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_113 = 0 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
F_98 (r, &dep->request_list, list) {
if ( V_176 == V_48 )
break;
}
if ( V_176 != V_48 ) {
F_98 (r, &dep->req_queued, list) {
if ( V_176 == V_48 )
break;
}
if ( V_176 == V_48 ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
goto V_177;
}
F_34 ( V_2 -> V_23 , L_41 ,
V_55 , V_82 -> V_46 ) ;
V_113 = - V_13 ;
goto V_178;
}
V_177:
F_16 ( V_35 , V_48 , - V_179 ) ;
V_178:
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
int F_99 ( struct V_34 * V_35 , int V_180 )
{
struct V_83 V_84 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_113 ;
memset ( & V_84 , 0x00 , sizeof( V_84 ) ) ;
if ( V_180 ) {
V_113 = F_25 ( V_2 , V_35 -> V_38 ,
V_73 , & V_84 ) ;
if ( V_113 )
F_34 ( V_2 -> V_23 , L_42 ,
V_180 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 |= V_181 ;
} else {
if ( V_35 -> V_41 & V_182 )
return 0 ;
V_113 = F_25 ( V_2 , V_35 -> V_38 ,
V_72 , & V_84 ) ;
if ( V_113 )
F_34 ( V_2 -> V_23 , L_42 ,
V_180 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 &= ~ V_181 ;
}
return V_113 ;
}
static int F_100 ( struct V_125 * V_82 , int V_180 )
{
struct V_34 * V_35 = F_64 ( V_82 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_113 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_45 , V_35 -> V_46 ) ;
V_113 = - V_13 ;
goto V_183;
}
V_113 = F_99 ( V_35 , V_180 ) ;
V_183:
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_101 ( struct V_125 * V_82 )
{
struct V_34 * V_35 = F_64 ( V_82 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_35 -> V_41 |= V_182 ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
if ( V_35 -> V_38 == 0 || V_35 -> V_38 == 1 )
return F_102 ( V_82 , 1 ) ;
else
return F_100 ( V_82 , 1 ) ;
}
static int F_103 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
return F_105 ( V_4 ) ;
}
static int F_106 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
unsigned long V_78 ;
unsigned long V_41 ;
T_1 V_4 ;
int V_113 = 0 ;
T_2 V_186 ;
T_2 V_100 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_100 = V_4 & V_187 ;
if ( V_100 == V_188 ) {
F_19 ( V_2 -> V_23 , L_46 ) ;
V_113 = - V_13 ;
goto V_183;
}
V_186 = F_7 ( V_4 ) ;
switch ( V_186 ) {
case V_189 :
case V_190 :
break;
default:
F_19 ( V_2 -> V_23 , L_47 ,
V_186 ) ;
V_113 = - V_13 ;
goto V_183;
}
V_113 = F_4 ( V_2 , V_191 ) ;
if ( V_113 < 0 ) {
F_34 ( V_2 -> V_23 , L_48 ) ;
goto V_183;
}
if ( V_2 -> V_17 < V_18 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_78 = V_192 + F_107 ( 100 ) ;
while ( ! F_108 ( V_192 , V_78 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( F_7 ( V_4 ) == V_193 )
break;
}
if ( F_7 ( V_4 ) != V_193 ) {
F_34 ( V_2 -> V_23 , L_49 ) ;
V_113 = - V_13 ;
}
V_183:
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_109 ( struct V_184 * V_185 ,
int V_194 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_2 -> V_194 = ! ! V_194 ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , int V_195 )
{
T_1 V_4 ;
T_1 V_78 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_195 ) {
if ( V_2 -> V_17 <= V_196 ) {
V_4 &= ~ V_197 ;
V_4 |= V_198 ;
}
if ( V_2 -> V_17 >= V_18 )
V_4 &= ~ V_199 ;
V_4 |= V_200 ;
} else {
V_4 &= ~ V_200 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( V_195 ) {
if ( ! ( V_4 & V_201 ) )
break;
} else {
if ( V_4 & V_201 )
break;
}
V_78 -- ;
if ( ! V_78 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
F_8 ( V_2 -> V_23 , L_50 ,
V_2 -> V_202
? V_2 -> V_202 -> V_203 : L_51 ,
V_195 ? L_52 : L_53 ) ;
return 0 ;
}
static int F_111 ( struct V_184 * V_185 , int V_195 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
unsigned long V_41 ;
int V_113 ;
V_195 = ! ! V_195 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
V_113 = F_110 ( V_2 , V_195 ) ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_112 ( struct V_184 * V_185 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
struct V_34 * V_35 ;
unsigned long V_41 ;
int V_113 = 0 ;
T_1 V_4 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
if ( V_2 -> V_202 ) {
F_34 ( V_2 -> V_23 , L_54 ,
V_2 -> V_61 . V_46 ,
V_2 -> V_202 -> V_205 . V_46 ) ;
V_113 = - V_166 ;
goto V_206;
}
V_2 -> V_202 = V_205 ;
V_2 -> V_61 . V_23 . V_205 = & V_205 -> V_205 ;
V_4 = F_2 ( V_2 -> V_5 , V_207 ) ;
V_4 &= ~ ( V_208 ) ;
if ( V_2 -> V_17 < V_209 )
V_4 |= V_210 ;
else
V_4 |= V_2 -> V_211 ;
F_3 ( V_2 -> V_5 , V_207 , V_4 ) ;
V_2 -> V_95 = false ;
V_212 . V_128 = F_113 ( 512 ) ;
V_35 = V_2 -> V_36 [ 0 ] ;
V_113 = F_51 ( V_35 , & V_212 , NULL , false ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_206;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_113 = F_51 ( V_35 , & V_212 , NULL , false ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_213;
}
V_2 -> V_214 = V_215 ;
F_114 ( V_2 ) ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return 0 ;
V_213:
F_59 ( V_2 -> V_36 [ 0 ] ) ;
V_206:
F_68 ( & V_2 -> V_65 , V_41 ) ;
return V_113 ;
}
static int F_115 ( struct V_184 * V_185 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_104 ( V_185 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_65 , V_41 ) ;
F_59 ( V_2 -> V_36 [ 0 ] ) ;
F_59 ( V_2 -> V_36 [ 1 ] ) ;
V_2 -> V_202 = NULL ;
V_2 -> V_61 . V_23 . V_205 = NULL ;
F_68 ( & V_2 -> V_65 , V_41 ) ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_135 ;
F_117 ( & V_2 -> V_61 . V_216 ) ;
for ( V_135 = 0 ; V_135 < V_33 ; V_135 ++ ) {
V_35 = F_71 ( sizeof( * V_35 ) , V_93 ) ;
if ( ! V_35 ) {
F_34 ( V_2 -> V_23 , L_56 ,
V_135 ) ;
return - V_94 ;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_38 = V_135 ;
V_2 -> V_36 [ V_135 ] = V_35 ;
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 , V_135 >> 1 ,
( V_135 & 1 ) ? L_28 : L_29 ) ;
V_35 -> V_43 . V_46 = V_35 -> V_46 ;
V_35 -> V_62 = ( V_135 & 1 ) ;
if ( V_135 == 0 || V_135 == 1 ) {
V_35 -> V_43 . V_45 = 512 ;
V_35 -> V_43 . V_103 = 1 ;
V_35 -> V_43 . V_217 = & V_218 ;
if ( ! V_135 )
V_2 -> V_61 . V_219 = & V_35 -> V_43 ;
} else {
int V_113 ;
V_35 -> V_43 . V_45 = 1024 ;
V_35 -> V_43 . V_220 = 15 ;
V_35 -> V_43 . V_217 = & V_221 ;
F_95 ( & V_35 -> V_43 . V_216 ,
& V_2 -> V_61 . V_216 ) ;
V_113 = F_32 ( V_35 ) ;
if ( V_113 )
return V_113 ;
}
F_117 ( & V_35 -> V_124 ) ;
F_117 ( & V_35 -> V_122 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_135 ;
for ( V_135 = 0 ; V_135 < V_33 ; V_135 ++ ) {
V_35 = V_2 -> V_36 [ V_135 ] ;
F_35 ( V_35 ) ;
if ( V_135 != 0 && V_135 != 1 )
F_17 ( & V_35 -> V_43 . V_216 ) ;
F_74 ( V_35 ) ;
}
}
static void F_119 ( struct V_222 * V_23 )
{
F_19 ( V_23 , L_57 , V_223 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_47 * V_48 , struct V_89 * V_58 ,
const struct V_171 * V_172 , int V_49 )
{
unsigned int V_224 ;
unsigned int V_225 = 0 ;
unsigned int V_226 ;
if ( ( V_58 -> V_119 & V_121 ) && V_49 != - V_123 )
F_34 ( V_2 -> V_23 , L_58 ,
V_35 -> V_46 , V_58 ) ;
V_224 = V_58 -> V_143 & V_227 ;
if ( V_35 -> V_62 ) {
if ( V_224 ) {
V_226 = F_121 ( V_58 -> V_143 ) ;
if ( V_226 == V_228 ) {
F_19 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_35 -> V_41 |= V_175 ;
} else {
F_34 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_49 = - V_179 ;
}
} else {
V_35 -> V_41 &= ~ V_175 ;
}
} else {
if ( V_224 && ( V_172 -> V_49 & V_229 ) )
V_225 = 1 ;
}
V_48 -> V_55 . V_63 += V_48 -> V_55 . V_64 - V_224 ;
if ( V_225 )
return 1 ;
if ( ( V_172 -> V_49 & V_230 ) &&
( V_58 -> V_119 & ( V_152 |
V_121 ) ) )
return 1 ;
if ( ( V_172 -> V_49 & V_231 ) &&
( V_58 -> V_119 & V_148 ) )
return 1 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_171 * V_172 , int V_49 )
{
struct V_47 * V_48 ;
struct V_89 * V_58 ;
unsigned int V_232 ;
unsigned int V_50 ;
int V_113 ;
do {
V_48 = F_58 ( & V_35 -> V_122 ) ;
if ( ! V_48 ) {
F_90 ( 1 ) ;
return 1 ;
}
V_50 = 0 ;
do {
V_232 = V_48 -> V_142 + V_50 ;
if ( ( V_232 == V_54 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
V_232 ++ ;
V_232 %= V_54 ;
V_58 = & V_35 -> V_91 [ V_232 ] ;
V_113 = F_120 ( V_2 , V_35 , V_48 , V_58 ,
V_172 , V_49 ) ;
if ( V_113 )
break;
}while ( ++ V_50 < V_48 -> V_55 . V_56 );
F_16 ( V_35 , V_48 , V_49 ) ;
if ( V_113 )
break;
} while ( 1 );
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
F_56 ( & V_35 -> V_122 ) ) {
if ( F_56 ( & V_35 -> V_124 ) ) {
V_35 -> V_41 = V_167 ;
} else {
F_57 ( V_2 , V_35 -> V_38 ) ;
V_35 -> V_41 = V_42 ;
}
return 1 ;
}
if ( ( V_172 -> V_49 & V_231 ) &&
( V_58 -> V_119 & V_148 ) )
return 0 ;
return 1 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_171 * V_172 ,
int V_164 )
{
unsigned V_49 = 0 ;
int V_233 ;
if ( V_172 -> V_49 & V_234 )
V_49 = - V_179 ;
V_233 = F_122 ( V_2 , V_35 , V_172 , V_49 ) ;
if ( V_233 )
V_35 -> V_41 &= ~ V_165 ;
if ( V_2 -> V_17 < V_235 ) {
T_1 V_4 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_33 ; V_50 ++ ) {
V_35 = V_2 -> V_36 [ V_50 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
if ( ! F_56 ( & V_35 -> V_122 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_236 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_236 = 0 ;
}
}
static void F_124 ( struct V_1 * V_2 ,
const struct V_171 * V_172 )
{
struct V_34 * V_35 ;
T_2 V_135 = V_172 -> V_237 ;
V_35 = V_2 -> V_36 [ V_135 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
return;
F_8 ( V_2 -> V_23 , L_60 , V_35 -> V_46 ,
F_125 ( V_172 -> V_238 ) ) ;
if ( V_135 == 0 || V_135 == 1 ) {
F_126 ( V_2 , V_172 ) ;
return;
}
switch ( V_172 -> V_238 ) {
case V_239 :
V_35 -> V_168 = 0 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_61 ,
V_35 -> V_46 ) ;
return;
}
F_123 ( V_2 , V_35 , V_172 , 1 ) ;
break;
case V_240 :
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_62 ,
V_35 -> V_46 ) ;
return;
}
F_123 ( V_2 , V_35 , V_172 , 0 ) ;
break;
case V_241 :
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_92 ( V_2 , V_35 , V_172 ) ;
} else {
int V_113 ;
F_8 ( V_2 -> V_23 , L_63 ,
V_35 -> V_46 , V_172 -> V_49 &
V_242
? L_64
: L_65 ) ;
V_113 = F_88 ( V_35 , 0 , 1 ) ;
if ( ! V_113 || V_113 == - V_166 )
return;
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
break;
case V_243 :
if ( ! F_12 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_66 ,
V_35 -> V_46 ) ;
return;
}
switch ( V_172 -> V_49 ) {
case V_244 :
F_8 ( V_2 -> V_23 , L_67 ,
V_172 -> V_174 ) ;
break;
case V_245 :
default:
F_19 ( V_2 -> V_23 , L_68 ) ;
}
break;
case V_246 :
F_19 ( V_2 -> V_23 , L_69 , V_35 -> V_46 ) ;
break;
case V_247 :
F_8 ( V_2 -> V_23 , L_70 ) ;
break;
}
}
static void F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_202 && V_2 -> V_202 -> V_248 ) {
F_20 ( & V_2 -> V_65 ) ;
V_2 -> V_202 -> V_248 ( & V_2 -> V_61 ) ;
F_21 ( & V_2 -> V_65 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , T_1 V_135 )
{
struct V_34 * V_35 ;
struct V_83 V_84 ;
T_1 V_67 ;
int V_113 ;
V_35 = V_2 -> V_36 [ V_135 ] ;
if ( ! V_35 -> V_168 )
return;
V_67 = V_69 ;
V_67 |= V_249 | V_250 ;
V_67 |= F_38 ( V_35 -> V_168 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_113 = F_25 ( V_2 , V_35 -> V_38 , V_67 , & V_84 ) ;
F_90 ( V_113 ) ;
V_35 -> V_168 = 0 ;
V_35 -> V_41 &= ~ V_165 ;
F_5 ( 100 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_135 ;
for ( V_135 = 2 ; V_135 < V_33 ; V_135 ++ ) {
struct V_34 * V_35 ;
V_35 = V_2 -> V_36 [ V_135 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
F_55 ( V_2 , V_35 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
T_1 V_135 ;
for ( V_135 = 1 ; V_135 < V_33 ; V_135 ++ ) {
struct V_34 * V_35 ;
struct V_83 V_84 ;
int V_113 ;
V_35 = V_2 -> V_36 [ V_135 ] ;
if ( ! ( V_35 -> V_41 & V_181 ) )
continue;
V_35 -> V_41 &= ~ V_181 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_113 = F_25 ( V_2 , V_35 -> V_38 ,
V_72 , & V_84 ) ;
F_90 ( V_113 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
int V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_223 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_251 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 &= ~ V_252 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_127 ( V_2 ) ;
V_2 -> V_95 = false ;
V_2 -> V_61 . V_100 = V_253 ;
V_2 -> V_254 = false ;
}
static void F_131 ( struct V_1 * V_2 , int V_255 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_132 ( 0 ) ) ;
if ( V_255 )
V_4 |= V_256 ;
else
V_4 &= ~ V_256 ;
F_3 ( V_2 -> V_5 , F_132 ( 0 ) , V_4 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_255 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_134 ( 0 ) ) ;
if ( V_255 )
V_4 |= V_257 ;
else
V_4 &= ~ V_257 ;
F_3 ( V_2 -> V_5 , F_134 ( 0 ) , V_4 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_223 ) ;
if ( V_2 -> V_17 < V_258 ) {
if ( V_2 -> V_254 )
F_130 ( V_2 ) ;
}
V_2 -> V_259 = V_260 ;
if ( V_2 -> V_17 < V_18 ) {
F_133 ( V_2 , false ) ;
F_131 ( V_2 , false ) ;
}
if ( V_2 -> V_61 . V_100 != V_253 )
F_127 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_261 = false ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_95 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_207 ) ;
V_4 &= ~ ( V_262 ) ;
F_3 ( V_2 -> V_5 , V_207 , V_4 ) ;
}
static void F_136 ( struct V_1 * V_2 , T_1 V_100 )
{
T_1 V_4 ;
T_1 V_263 = V_264 ;
if ( V_100 != V_188 )
return;
if ( ! V_263 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_265 ) ;
V_4 |= F_137 ( V_263 ) ;
F_3 ( V_2 -> V_5 , V_265 , V_4 ) ;
}
static void F_138 ( struct V_1 * V_2 , T_2 V_100 )
{
switch ( V_100 ) {
case V_101 :
F_133 ( V_2 , true ) ;
break;
case V_266 :
case V_267 :
case V_268 :
F_131 ( V_2 , true ) ;
break;
}
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_113 ;
T_1 V_4 ;
T_2 V_100 ;
F_8 ( V_2 -> V_23 , L_57 , V_223 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_100 = V_4 & V_187 ;
V_2 -> V_100 = V_100 ;
F_136 ( V_2 , V_100 ) ;
switch ( V_100 ) {
case V_210 :
if ( V_2 -> V_17 < V_269 )
F_135 ( V_2 ) ;
V_212 . V_128 = F_113 ( 512 ) ;
V_2 -> V_61 . V_219 -> V_45 = 512 ;
V_2 -> V_61 . V_100 = V_101 ;
break;
case V_270 :
V_212 . V_128 = F_113 ( 64 ) ;
V_2 -> V_61 . V_219 -> V_45 = 64 ;
V_2 -> V_61 . V_100 = V_266 ;
break;
case V_271 :
case V_272 :
V_212 . V_128 = F_113 ( 64 ) ;
V_2 -> V_61 . V_219 -> V_45 = 64 ;
V_2 -> V_61 . V_100 = V_267 ;
break;
case V_273 :
V_212 . V_128 = F_113 ( 8 ) ;
V_2 -> V_61 . V_219 -> V_45 = 8 ;
V_2 -> V_61 . V_100 = V_268 ;
break;
}
if ( ( V_2 -> V_17 > V_18 )
&& ( V_100 != V_210 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_207 ) ;
V_4 |= V_274 ;
F_3 ( V_2 -> V_5 , V_207 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ ( V_275 | V_276 ) ;
V_4 |= F_140 ( 12 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
if ( V_2 -> V_17 < V_18 ) {
F_138 ( V_2 , V_2 -> V_61 . V_100 ) ;
}
V_35 = V_2 -> V_36 [ 0 ] ;
V_113 = F_51 ( V_35 , & V_212 , NULL , true ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_113 = F_51 ( V_35 , & V_212 , NULL , true ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
}
static void F_141 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_23 , L_57 , V_223 ) ;
V_2 -> V_202 -> V_277 ( & V_2 -> V_61 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
unsigned int V_278 )
{
enum V_14 V_279 = V_278 & V_280 ;
if ( V_2 -> V_17 < V_235 ) {
if ( V_279 == V_193 ) {
T_1 V_236 ;
T_1 V_4 ;
switch ( V_2 -> V_186 ) {
case V_281 :
case V_282 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_236 = V_4 & ( V_252
| V_283
| V_251
| V_284 ) ;
if ( ! V_2 -> V_236 )
V_2 -> V_236 = V_4 & V_236 ;
V_4 &= ~ V_236 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_186 = V_279 ;
F_8 ( V_2 -> V_23 , L_71 , V_223 , V_2 -> V_186 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
const struct V_285 * V_172 )
{
switch ( V_172 -> type ) {
case V_286 :
F_130 ( V_2 ) ;
break;
case V_287 :
F_135 ( V_2 ) ;
break;
case V_288 :
F_139 ( V_2 ) ;
break;
case V_289 :
F_141 ( V_2 ) ;
break;
case V_290 :
F_142 ( V_2 , V_172 -> V_291 ) ;
break;
case V_292 :
F_8 ( V_2 -> V_23 , L_72 ) ;
break;
case V_293 :
F_8 ( V_2 -> V_23 , L_73 ) ;
break;
case V_294 :
F_8 ( V_2 -> V_23 , L_74 ) ;
break;
case V_295 :
F_8 ( V_2 -> V_23 , L_75 ) ;
break;
case V_296 :
F_8 ( V_2 -> V_23 , L_76 ) ;
break;
default:
F_19 ( V_2 -> V_23 , L_77 , V_172 -> type ) ;
}
}
static void F_144 ( struct V_1 * V_2 ,
const union V_297 * V_172 )
{
if ( V_172 -> type . V_298 == 0 ) {
return F_124 ( V_2 , & V_172 -> V_299 ) ;
}
switch ( V_172 -> type . type ) {
case V_300 :
F_143 ( V_2 , & V_172 -> V_301 ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_78 , V_172 -> V_302 ) ;
}
}
static T_6 F_145 ( struct V_1 * V_2 , T_1 V_303 )
{
struct V_304 * V_305 ;
int V_306 ;
T_1 V_224 ;
V_224 = F_2 ( V_2 -> V_5 , F_146 ( V_303 ) ) ;
V_224 &= V_307 ;
if ( ! V_224 )
return V_308 ;
V_305 = V_2 -> V_309 [ V_303 ] ;
V_306 = V_224 ;
while ( V_306 > 0 ) {
union V_297 V_172 ;
V_172 . V_302 = * ( T_1 * ) ( V_305 -> V_303 + V_305 -> V_310 ) ;
F_144 ( V_2 , & V_172 ) ;
V_305 -> V_310 = ( V_305 -> V_310 + 4 ) % V_311 ;
V_306 -= 4 ;
F_3 ( V_2 -> V_5 , F_146 ( V_303 ) , 4 ) ;
}
return V_312 ;
}
static T_6 F_147 ( int V_313 , void * V_314 )
{
struct V_1 * V_2 = V_314 ;
int V_50 ;
T_6 V_113 = V_308 ;
F_21 ( & V_2 -> V_65 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_315 ; V_50 ++ ) {
T_6 V_49 ;
V_49 = F_145 ( V_2 , V_50 ) ;
if ( V_49 == V_312 )
V_113 = V_49 ;
}
F_20 ( & V_2 -> V_65 ) ;
return V_113 ;
}
int F_148 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_113 ;
int V_313 ;
V_2 -> V_316 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_316 ) ,
& V_2 -> V_317 , V_93 ) ;
if ( ! V_2 -> V_316 ) {
F_34 ( V_2 -> V_23 , L_79 ) ;
V_113 = - V_94 ;
goto V_206;
}
V_2 -> V_318 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_318 ) ,
& V_2 -> V_319 , V_93 ) ;
if ( ! V_2 -> V_318 ) {
F_34 ( V_2 -> V_23 , L_80 ) ;
V_113 = - V_94 ;
goto V_213;
}
V_2 -> V_320 = F_71 ( V_321 , V_93 ) ;
if ( ! V_2 -> V_320 ) {
F_34 ( V_2 -> V_23 , L_81 ) ;
V_113 = - V_94 ;
goto V_322;
}
V_2 -> V_323 = F_33 ( V_2 -> V_23 ,
V_321 , & V_2 -> V_324 ,
V_93 ) ;
if ( ! V_2 -> V_323 ) {
F_34 ( V_2 -> V_23 , L_82 ) ;
V_113 = - V_94 ;
goto V_325;
}
F_149 ( & V_2 -> V_61 . V_23 , L_83 ) ;
V_2 -> V_61 . V_217 = & V_326 ;
V_2 -> V_61 . V_327 = V_101 ;
V_2 -> V_61 . V_100 = V_253 ;
V_2 -> V_61 . V_23 . V_328 = V_2 -> V_23 ;
V_2 -> V_61 . V_329 = true ;
F_150 ( & V_2 -> V_61 . V_23 , V_2 -> V_23 -> V_330 ) ;
V_2 -> V_61 . V_23 . V_331 = V_2 -> V_23 -> V_331 ;
V_2 -> V_61 . V_23 . V_332 = V_2 -> V_23 -> V_332 ;
V_2 -> V_61 . V_23 . V_333 = F_119 ;
V_2 -> V_61 . V_46 = L_84 ;
V_113 = F_116 ( V_2 ) ;
if ( V_113 )
goto V_334;
V_313 = F_151 ( F_152 ( V_2 -> V_23 ) , 0 ) ;
V_113 = F_153 ( V_313 , F_147 , V_335 ,
L_85 , V_2 ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_86 ,
V_313 , V_113 ) ;
goto V_336;
}
V_4 = F_2 ( V_2 -> V_5 , V_207 ) ;
V_4 |= V_274 ;
F_3 ( V_2 -> V_5 , V_207 , V_4 ) ;
V_4 = ( V_337 |
V_338 |
V_339 |
V_340 |
V_341 |
V_342 |
V_343 |
V_344 |
V_345 ) ;
F_3 ( V_2 -> V_5 , V_346 , V_4 ) ;
if ( V_2 -> V_17 >= V_18 ) {
F_133 ( V_2 , false ) ;
F_131 ( V_2 , false ) ;
}
V_113 = F_154 ( & V_2 -> V_61 . V_23 ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_87 ) ;
F_155 ( & V_2 -> V_61 . V_23 ) ;
goto V_347;
}
V_113 = F_156 ( V_2 -> V_23 , & V_2 -> V_61 ) ;
if ( V_113 ) {
F_34 ( V_2 -> V_23 , L_88 ) ;
goto V_348;
}
return 0 ;
V_348:
F_157 ( & V_2 -> V_61 . V_23 ) ;
V_347:
F_3 ( V_2 -> V_5 , V_346 , 0x00 ) ;
F_158 ( V_313 , V_2 ) ;
V_336:
F_118 ( V_2 ) ;
V_334:
F_36 ( V_2 -> V_23 , V_321 ,
V_2 -> V_323 , V_2 -> V_324 ) ;
V_325:
F_74 ( V_2 -> V_320 ) ;
V_322:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_318 ) ,
V_2 -> V_318 , V_2 -> V_319 ) ;
V_213:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_316 ) ,
V_2 -> V_316 , V_2 -> V_317 ) ;
V_206:
return V_113 ;
}
void F_159 ( struct V_1 * V_2 )
{
int V_313 ;
F_160 ( & V_2 -> V_61 ) ;
V_313 = F_151 ( F_152 ( V_2 -> V_23 ) , 0 ) ;
F_3 ( V_2 -> V_5 , V_346 , 0x00 ) ;
F_158 ( V_313 , V_2 ) ;
F_118 ( V_2 ) ;
F_36 ( V_2 -> V_23 , V_321 ,
V_2 -> V_323 , V_2 -> V_324 ) ;
F_74 ( V_2 -> V_320 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_318 ) ,
V_2 -> V_318 , V_2 -> V_319 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_316 ) ,
V_2 -> V_316 , V_2 -> V_317 ) ;
F_157 ( & V_2 -> V_61 . V_23 ) ;
}
