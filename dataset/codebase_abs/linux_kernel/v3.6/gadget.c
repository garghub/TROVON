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
const struct V_96 * V_97 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_40 ( F_41 ( V_44 ) )
| F_42 ( F_43 ( V_44 ) )
| F_44 ( V_35 -> V_43 . V_98 - 1 ) ;
V_83 . V_85 = V_99
| V_100 ;
if ( F_45 ( V_97 ) && F_12 ( V_44 ) ) {
V_83 . V_85 |= V_101
| V_102 ;
V_35 -> V_103 = true ;
}
if ( F_13 ( V_44 ) )
V_83 . V_85 |= V_104 ;
V_83 . V_85 |= F_46 ( V_35 -> V_38 ) ;
if ( V_35 -> V_61 )
V_83 . V_84 |= F_47 ( V_35 -> V_38 >> 1 ) ;
if ( V_44 -> V_105 ) {
V_83 . V_85 |= F_48 ( V_44 -> V_105 - 1 ) ;
V_35 -> V_106 = 1 << ( V_44 -> V_105 - 1 ) ;
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
const struct V_96 * V_97 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
int V_107 = - V_93 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
V_107 = F_37 ( V_2 , V_35 ) ;
if ( V_107 )
return V_107 ;
}
V_107 = F_39 ( V_2 , V_35 , V_44 , V_97 ) ;
if ( V_107 )
return V_107 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
struct V_88 * V_108 ;
struct V_88 * V_109 ;
V_107 = F_49 ( V_2 , V_35 ) ;
if ( V_107 )
return V_107 ;
V_35 -> V_43 . V_44 = V_44 ;
V_35 -> V_97 = V_97 ;
V_35 -> type = F_41 ( V_44 ) ;
V_35 -> V_41 |= V_42 ;
V_4 = F_2 ( V_2 -> V_5 , V_110 ) ;
V_4 |= F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_110 , V_4 ) ;
if ( ! F_13 ( V_44 ) )
return 0 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_108 = & V_35 -> V_90 [ 0 ] ;
V_109 = & V_35 -> V_90 [ V_55 - 1 ] ;
V_109 -> V_111 = F_53 ( F_31 ( V_35 , V_108 ) ) ;
V_109 -> V_112 = F_54 ( F_31 ( V_35 , V_108 ) ) ;
V_109 -> V_113 |= V_114 ;
V_109 -> V_113 |= V_115 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_47 * V_48 ;
if ( ! F_56 ( & V_35 -> V_116 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
F_5 ( 100 ) ;
while ( ! F_56 ( & V_35 -> V_116 ) ) {
V_48 = F_58 ( & V_35 -> V_116 ) ;
F_16 ( V_35 , V_48 , - V_117 ) ;
}
}
while ( ! F_56 ( & V_35 -> V_118 ) ) {
V_48 = F_58 ( & V_35 -> V_118 ) ;
F_16 ( V_35 , V_48 , - V_117 ) ;
}
}
static int F_59 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_4 ;
F_55 ( V_2 , V_35 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_110 ) ;
V_4 &= ~ F_52 ( V_35 -> V_38 ) ;
F_3 ( V_2 -> V_5 , V_110 , V_4 ) ;
V_35 -> V_103 = false ;
V_35 -> V_43 . V_44 = NULL ;
V_35 -> V_97 = NULL ;
V_35 -> type = 0 ;
V_35 -> V_41 = 0 ;
return 0 ;
}
static int F_60 ( struct V_119 * V_81 ,
const struct V_95 * V_44 )
{
return - V_13 ;
}
static int F_61 ( struct V_119 * V_81 )
{
return - V_13 ;
}
static int F_62 ( struct V_119 * V_81 ,
const struct V_95 * V_44 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_107 ;
if ( ! V_81 || ! V_44 || V_44 -> V_120 != V_121 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
if ( ! V_44 -> V_122 ) {
F_63 ( L_18 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
switch ( F_41 ( V_44 ) ) {
case V_123 :
F_65 ( V_35 -> V_46 , L_19 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_124 :
F_65 ( V_35 -> V_46 , L_20 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_125 :
F_65 ( V_35 -> V_46 , L_21 , sizeof( V_35 -> V_46 ) ) ;
break;
case V_126 :
F_65 ( V_35 -> V_46 , L_22 , sizeof( V_35 -> V_46 ) ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_23 ) ;
}
if ( V_35 -> V_41 & V_42 ) {
F_66 ( V_2 -> V_23 , true , L_24 ,
V_35 -> V_46 ) ;
return 0 ;
}
F_8 ( V_2 -> V_23 , L_25 , V_35 -> V_46 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_107 = F_51 ( V_35 , V_44 , V_81 -> V_97 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_69 ( struct V_119 * V_81 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_107 ;
if ( ! V_81 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
V_35 = F_64 ( V_81 ) ;
V_2 = V_35 -> V_2 ;
if ( ! ( V_35 -> V_41 & V_42 ) ) {
F_66 ( V_2 -> V_23 , true , L_26 ,
V_35 -> V_46 ) ;
return 0 ;
}
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 ,
V_35 -> V_38 >> 1 ,
( V_35 -> V_38 & 1 ) ? L_28 : L_29 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_107 = F_59 ( V_35 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static struct V_127 * F_70 ( struct V_119 * V_81 ,
T_4 V_128 )
{
struct V_47 * V_48 ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
V_48 = F_71 ( sizeof( * V_48 ) , V_128 ) ;
if ( ! V_48 ) {
F_34 ( V_2 -> V_23 , L_30 ) ;
return NULL ;
}
V_48 -> V_129 = V_35 -> V_38 ;
V_48 -> V_35 = V_35 ;
return & V_48 -> V_51 ;
}
static void F_72 ( struct V_119 * V_81 ,
struct V_127 * V_51 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
F_74 ( V_48 ) ;
}
static void F_75 ( struct V_34 * V_35 ,
struct V_47 * V_48 , T_3 V_130 ,
unsigned V_63 , unsigned V_131 , unsigned V_132 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_88 * V_57 ;
unsigned int V_133 ;
F_8 ( V_2 -> V_23 , L_31 ,
V_35 -> V_46 , V_48 , ( unsigned long long ) V_130 ,
V_63 , V_131 ? L_32 : L_33 ,
V_132 ? L_34 : L_33 ) ;
V_57 = & V_35 -> V_90 [ V_35 -> V_134 & V_54 ] ;
V_133 = V_35 -> V_134 ;
V_35 -> V_134 ++ ;
if ( ( ( V_133 & V_54 ) == V_55 - 1 ) &&
F_13 ( V_35 -> V_43 . V_44 ) )
return;
if ( ! V_48 -> V_57 ) {
F_76 ( V_48 ) ;
V_48 -> V_57 = V_57 ;
V_48 -> V_135 = F_31 ( V_35 , V_57 ) ;
}
V_57 -> V_136 = F_77 ( V_63 ) ;
V_57 -> V_111 = F_53 ( V_130 ) ;
V_57 -> V_112 = F_54 ( V_130 ) ;
switch ( F_41 ( V_35 -> V_43 . V_44 ) ) {
case V_123 :
V_57 -> V_113 = V_137 ;
break;
case V_124 :
V_57 -> V_113 = V_138 ;
if ( ! V_48 -> V_51 . V_139 )
V_57 -> V_113 |= V_140 ;
break;
case V_125 :
case V_126 :
V_57 -> V_113 = V_141 ;
break;
default:
F_78 () ;
}
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_57 -> V_113 |= V_142 ;
V_57 -> V_113 |= V_143 ;
} else {
if ( V_132 )
V_57 -> V_113 |= V_144 ;
if ( V_131 )
V_57 -> V_113 |= V_145 ;
}
if ( F_12 ( V_35 -> V_43 . V_44 ) && V_35 -> V_103 )
V_57 -> V_113 |= F_79 ( V_48 -> V_51 . V_146 ) ;
V_57 -> V_113 |= V_115 ;
}
static void F_80 ( struct V_34 * V_35 , bool V_147 )
{
struct V_47 * V_48 , * V_148 ;
T_1 V_149 ;
T_1 V_150 ;
unsigned int V_151 = 0 ;
F_81 ( V_55 ) ;
V_149 = ( V_35 -> V_53 - V_35 -> V_134 ) & V_54 ;
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
V_150 = V_55 - ( V_35 -> V_134 & V_54 ) ;
if ( V_149 > V_150 )
V_149 = V_150 ;
}
if ( ! V_149 ) {
if ( ! V_147 )
return;
V_149 = V_55 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
V_35 -> V_53 = 1 ;
V_35 -> V_134 = 1 ;
} else {
V_35 -> V_53 = 0 ;
V_35 -> V_134 = 0 ;
}
}
if ( ( V_149 <= 1 ) && F_13 ( V_35 -> V_43 . V_44 ) )
return;
F_82 (req, n, &dep->request_list, list) {
unsigned V_63 ;
T_3 V_130 ;
if ( V_48 -> V_51 . V_52 > 0 ) {
struct V_127 * V_51 = & V_48 -> V_51 ;
struct V_152 * V_153 = V_51 -> V_153 ;
struct V_152 * V_154 ;
int V_155 ;
F_83 (sg, s, request->num_mapped_sgs, i) {
unsigned V_132 = true ;
V_63 = F_84 ( V_154 ) ;
V_130 = F_85 ( V_154 ) ;
if ( V_155 == ( V_51 -> V_52 - 1 ) ||
F_86 ( V_154 ) ) {
V_151 = true ;
V_132 = false ;
}
V_149 -- ;
if ( ! V_149 )
V_151 = true ;
if ( V_151 )
V_132 = false ;
F_75 ( V_35 , V_48 , V_130 , V_63 ,
V_151 , V_132 ) ;
if ( V_151 )
break;
}
} else {
V_130 = V_48 -> V_51 . V_130 ;
V_63 = V_48 -> V_51 . V_63 ;
V_149 -- ;
if ( ! V_149 )
V_151 = 1 ;
if ( F_87 ( & V_48 -> V_56 , & V_35 -> V_118 ) )
V_151 = 1 ;
F_75 ( V_35 , V_48 , V_130 , V_63 ,
V_151 , false ) ;
if ( V_151 )
break;
}
}
}
static int F_88 ( struct V_34 * V_35 , T_5 V_156 ,
int V_157 )
{
struct V_82 V_83 ;
struct V_47 * V_48 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_107 ;
T_1 V_66 ;
if ( V_157 && ( V_35 -> V_41 & V_158 ) ) {
F_8 ( V_2 -> V_23 , L_35 , V_35 -> V_46 ) ;
return - V_159 ;
}
V_35 -> V_41 &= ~ V_160 ;
if ( V_157 ) {
if ( F_56 ( & V_35 -> V_116 ) )
F_80 ( V_35 , V_157 ) ;
V_48 = F_58 ( & V_35 -> V_116 ) ;
} else {
F_80 ( V_35 , V_157 ) ;
V_48 = F_58 ( & V_35 -> V_116 ) ;
}
if ( ! V_48 ) {
V_35 -> V_41 |= V_160 ;
return 0 ;
}
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_54 ( V_48 -> V_135 ) ;
V_83 . V_85 = F_53 ( V_48 -> V_135 ) ;
if ( V_157 )
V_66 = V_70 ;
else
V_66 = V_69 ;
V_66 |= F_38 ( V_156 ) ;
V_107 = F_25 ( V_2 , V_35 -> V_38 , V_66 , & V_83 ) ;
if ( V_107 < 0 ) {
F_19 ( V_2 -> V_23 , L_36 ) ;
F_18 ( & V_2 -> V_60 , & V_48 -> V_51 ,
V_48 -> V_61 ) ;
F_17 ( & V_48 -> V_56 ) ;
return V_107 ;
}
V_35 -> V_41 |= V_158 ;
if ( V_157 ) {
V_35 -> V_161 = F_89 ( V_2 ,
V_35 -> V_38 ) ;
F_90 ( ! V_35 -> V_161 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_162 )
{
T_1 V_163 ;
if ( F_56 ( & V_35 -> V_118 ) ) {
F_8 ( V_2 -> V_23 , L_37 ,
V_35 -> V_46 ) ;
V_35 -> V_41 |= V_160 ;
return;
}
V_163 = V_162 + V_35 -> V_106 * 4 ;
F_88 ( V_35 , V_163 , 1 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_164 * V_165 )
{
T_1 V_162 , V_166 ;
V_166 = ~ ( V_35 -> V_106 - 1 ) ;
V_162 = V_165 -> V_167 & V_166 ;
F_91 ( V_2 , V_35 , V_162 ) ;
}
static int F_93 ( struct V_34 * V_35 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_107 ;
V_48 -> V_51 . V_62 = 0 ;
V_48 -> V_51 . V_49 = - V_58 ;
V_48 -> V_61 = V_35 -> V_61 ;
V_48 -> V_129 = V_35 -> V_38 ;
V_107 = F_94 ( & V_2 -> V_60 , & V_48 -> V_51 ,
V_35 -> V_61 ) ;
if ( V_107 )
return V_107 ;
F_95 ( & V_48 -> V_56 , & V_35 -> V_118 ) ;
if ( V_35 -> V_41 & V_160 ) {
int V_107 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
return 0 ;
}
V_107 = F_88 ( V_35 , 0 , true ) ;
if ( V_107 && V_107 != - V_159 ) {
struct V_1 * V_2 = V_35 -> V_2 ;
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
}
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
( V_35 -> V_41 & V_158 ) ) {
F_90 ( ! V_35 -> V_161 ) ;
V_107 = F_88 ( V_35 , V_35 -> V_161 ,
false ) ;
if ( V_107 && V_107 != - V_159 ) {
struct V_1 * V_2 = V_35 -> V_2 ;
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
}
if ( F_13 ( V_35 -> V_43 . V_44 ) &&
( V_35 -> V_41 & V_168 ) ) {
F_91 ( V_2 , V_35 , V_35 -> V_169 ) ;
V_35 -> V_41 &= ~ V_168 ;
}
return 0 ;
}
static int F_96 ( struct V_119 * V_81 , struct V_127 * V_51 ,
T_4 V_128 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_107 ;
if ( ! V_35 -> V_43 . V_44 ) {
F_19 ( V_2 -> V_23 , L_39 ,
V_51 , V_81 -> V_46 ) ;
return - V_117 ;
}
F_8 ( V_2 -> V_23 , L_40 ,
V_51 , V_81 -> V_46 , V_51 -> V_63 ) ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_107 = F_93 ( V_35 , V_48 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_97 ( struct V_119 * V_81 ,
struct V_127 * V_51 )
{
struct V_47 * V_48 = F_73 ( V_51 ) ;
struct V_47 * V_170 = NULL ;
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_107 = 0 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
F_98 (r, &dep->request_list, list) {
if ( V_170 == V_48 )
break;
}
if ( V_170 != V_48 ) {
F_98 (r, &dep->req_queued, list) {
if ( V_170 == V_48 )
break;
}
if ( V_170 == V_48 ) {
F_57 ( V_2 , V_35 -> V_38 ) ;
goto V_171;
}
F_34 ( V_2 -> V_23 , L_41 ,
V_51 , V_81 -> V_46 ) ;
V_107 = - V_13 ;
goto V_172;
}
V_171:
F_16 ( V_35 , V_48 , - V_173 ) ;
V_172:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
int F_99 ( struct V_34 * V_35 , int V_174 )
{
struct V_82 V_83 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_107 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
if ( V_174 ) {
V_107 = F_25 ( V_2 , V_35 -> V_38 ,
V_72 , & V_83 ) ;
if ( V_107 )
F_34 ( V_2 -> V_23 , L_42 ,
V_174 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 |= V_175 ;
} else {
if ( V_35 -> V_41 & V_176 )
return 0 ;
V_107 = F_25 ( V_2 , V_35 -> V_38 ,
V_71 , & V_83 ) ;
if ( V_107 )
F_34 ( V_2 -> V_23 , L_42 ,
V_174 ? L_43 : L_44 ,
V_35 -> V_46 ) ;
else
V_35 -> V_41 &= ~ V_175 ;
}
return V_107 ;
}
static int F_100 ( struct V_119 * V_81 , int V_174 )
{
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
int V_107 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_45 , V_35 -> V_46 ) ;
V_107 = - V_13 ;
goto V_177;
}
V_107 = F_99 ( V_35 , V_174 ) ;
V_177:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_101 ( struct V_119 * V_81 )
{
struct V_34 * V_35 = F_64 ( V_81 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_35 -> V_41 |= V_176 ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
if ( V_35 -> V_38 == 0 || V_35 -> V_38 == 1 )
return F_102 ( V_81 , 1 ) ;
else
return F_100 ( V_81 , 1 ) ;
}
static int F_103 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
return F_105 ( V_4 ) ;
}
static int F_106 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
unsigned long V_77 ;
unsigned long V_41 ;
T_1 V_4 ;
int V_107 = 0 ;
T_2 V_180 ;
T_2 V_181 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_181 = V_4 & V_182 ;
if ( V_181 == V_183 ) {
F_19 ( V_2 -> V_23 , L_46 ) ;
V_107 = - V_13 ;
goto V_177;
}
V_180 = F_7 ( V_4 ) ;
switch ( V_180 ) {
case V_184 :
case V_185 :
break;
default:
F_19 ( V_2 -> V_23 , L_47 ,
V_180 ) ;
V_107 = - V_13 ;
goto V_177;
}
V_107 = F_4 ( V_2 , V_186 ) ;
if ( V_107 < 0 ) {
F_34 ( V_2 -> V_23 , L_48 ) ;
goto V_177;
}
if ( V_2 -> V_17 < V_18 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_77 = V_187 + F_107 ( 100 ) ;
while ( ! F_108 ( V_187 , V_77 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( F_7 ( V_4 ) == V_188 )
break;
}
if ( F_7 ( V_4 ) != V_188 ) {
F_34 ( V_2 -> V_23 , L_49 ) ;
V_107 = - V_13 ;
}
V_177:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_109 ( struct V_178 * V_179 ,
int V_189 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_2 -> V_189 = ! ! V_189 ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , int V_190 )
{
T_1 V_4 ;
T_1 V_77 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_190 ) {
if ( V_2 -> V_17 <= V_191 ) {
V_4 &= ~ V_192 ;
V_4 |= V_193 ;
}
if ( V_2 -> V_17 >= V_18 )
V_4 &= ~ V_194 ;
V_4 |= V_195 ;
} else {
V_4 &= ~ V_195 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
if ( V_190 ) {
if ( ! ( V_4 & V_196 ) )
break;
} else {
if ( V_4 & V_196 )
break;
}
V_77 -- ;
if ( ! V_77 )
return - V_21 ;
F_5 ( 1 ) ;
} while ( 1 );
F_8 ( V_2 -> V_23 , L_50 ,
V_2 -> V_197
? V_2 -> V_197 -> V_198 : L_51 ,
V_190 ? L_52 : L_53 ) ;
return 0 ;
}
static int F_111 ( struct V_178 * V_179 , int V_190 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
unsigned long V_41 ;
int V_107 ;
V_190 = ! ! V_190 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
V_107 = F_110 ( V_2 , V_190 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_112 ( struct V_178 * V_179 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
struct V_34 * V_35 ;
unsigned long V_41 ;
int V_107 = 0 ;
T_1 V_4 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
if ( V_2 -> V_197 ) {
F_34 ( V_2 -> V_23 , L_54 ,
V_2 -> V_60 . V_46 ,
V_2 -> V_197 -> V_200 . V_46 ) ;
V_107 = - V_159 ;
goto V_201;
}
V_2 -> V_197 = V_200 ;
V_2 -> V_60 . V_23 . V_200 = & V_200 -> V_200 ;
V_4 = F_2 ( V_2 -> V_5 , V_202 ) ;
V_4 &= ~ ( V_203 ) ;
if ( V_2 -> V_17 < V_204 )
V_4 |= V_205 ;
else
V_4 |= V_2 -> V_206 ;
F_3 ( V_2 -> V_5 , V_202 , V_4 ) ;
V_2 -> V_94 = false ;
V_207 . V_122 = F_113 ( 512 ) ;
V_35 = V_2 -> V_36 [ 0 ] ;
V_107 = F_51 ( V_35 , & V_207 , NULL ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_201;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_107 = F_51 ( V_35 , & V_207 , NULL ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
goto V_208;
}
V_2 -> V_209 = V_210 ;
F_114 ( V_2 ) ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
V_208:
F_59 ( V_2 -> V_36 [ 0 ] ) ;
V_201:
F_68 ( & V_2 -> V_64 , V_41 ) ;
return V_107 ;
}
static int F_115 ( struct V_178 * V_179 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_104 ( V_179 ) ;
unsigned long V_41 ;
F_67 ( & V_2 -> V_64 , V_41 ) ;
F_59 ( V_2 -> V_36 [ 0 ] ) ;
F_59 ( V_2 -> V_36 [ 1 ] ) ;
V_2 -> V_197 = NULL ;
V_2 -> V_60 . V_23 . V_200 = NULL ;
F_68 ( & V_2 -> V_64 , V_41 ) ;
return 0 ;
}
static int T_6 F_116 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_129 ;
F_117 ( & V_2 -> V_60 . V_211 ) ;
for ( V_129 = 0 ; V_129 < V_33 ; V_129 ++ ) {
V_35 = F_71 ( sizeof( * V_35 ) , V_92 ) ;
if ( ! V_35 ) {
F_34 ( V_2 -> V_23 , L_56 ,
V_129 ) ;
return - V_93 ;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_38 = V_129 ;
V_2 -> V_36 [ V_129 ] = V_35 ;
snprintf ( V_35 -> V_46 , sizeof( V_35 -> V_46 ) , L_27 , V_129 >> 1 ,
( V_129 & 1 ) ? L_28 : L_29 ) ;
V_35 -> V_43 . V_46 = V_35 -> V_46 ;
V_35 -> V_61 = ( V_129 & 1 ) ;
if ( V_129 == 0 || V_129 == 1 ) {
V_35 -> V_43 . V_45 = 512 ;
V_35 -> V_43 . V_212 = & V_213 ;
if ( ! V_129 )
V_2 -> V_60 . V_214 = & V_35 -> V_43 ;
} else {
int V_107 ;
V_35 -> V_43 . V_45 = 1024 ;
V_35 -> V_43 . V_215 = 15 ;
V_35 -> V_43 . V_212 = & V_216 ;
F_95 ( & V_35 -> V_43 . V_211 ,
& V_2 -> V_60 . V_211 ) ;
V_107 = F_32 ( V_35 ) ;
if ( V_107 )
return V_107 ;
}
F_117 ( & V_35 -> V_118 ) ;
F_117 ( & V_35 -> V_116 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
T_2 V_129 ;
for ( V_129 = 0 ; V_129 < V_33 ; V_129 ++ ) {
V_35 = V_2 -> V_36 [ V_129 ] ;
F_35 ( V_35 ) ;
if ( V_129 != 0 && V_129 != 1 )
F_17 ( & V_35 -> V_43 . V_211 ) ;
F_74 ( V_35 ) ;
}
}
static void F_119 ( struct V_217 * V_23 )
{
F_19 ( V_23 , L_57 , V_218 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_164 * V_165 , int V_49 )
{
struct V_47 * V_48 ;
struct V_88 * V_57 ;
unsigned int V_219 ;
unsigned int V_220 = 0 ;
unsigned int V_221 ;
do {
V_48 = F_58 ( & V_35 -> V_116 ) ;
if ( ! V_48 ) {
F_90 ( 1 ) ;
return 1 ;
}
V_57 = V_48 -> V_57 ;
if ( ( V_57 -> V_113 & V_115 ) && V_49 != - V_117 )
F_34 ( V_2 -> V_23 , L_58 ,
V_35 -> V_46 , V_48 -> V_57 ) ;
V_219 = V_57 -> V_136 & V_222 ;
if ( V_35 -> V_61 ) {
if ( V_219 ) {
V_221 = F_121 ( V_57 -> V_136 ) ;
if ( V_221 == V_223 ) {
F_19 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_35 -> V_169 = V_165 -> V_167 &
~ ( V_35 -> V_106 - 1 ) ;
V_35 -> V_41 |= V_168 ;
} else {
F_34 ( V_2 -> V_23 , L_59 ,
V_35 -> V_46 ) ;
V_49 = - V_173 ;
}
}
} else {
if ( V_219 && ( V_165 -> V_49 & V_224 ) )
V_220 = 1 ;
}
V_48 -> V_51 . V_62 += V_48 -> V_51 . V_63 - V_219 ;
F_16 ( V_35 , V_48 , V_49 ) ;
if ( V_220 )
break;
if ( ( V_165 -> V_49 & V_225 ) &&
( V_57 -> V_113 & ( V_145 |
V_115 ) ) )
break;
if ( ( V_165 -> V_49 & V_226 ) &&
( V_57 -> V_113 & V_140 ) )
break;
} while ( 1 );
if ( ( V_165 -> V_49 & V_226 ) &&
( V_57 -> V_113 & V_140 ) )
return 0 ;
return 1 ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_164 * V_165 ,
int V_157 )
{
unsigned V_49 = 0 ;
int V_227 ;
if ( V_165 -> V_49 & V_228 )
V_49 = - V_173 ;
V_227 = F_120 ( V_2 , V_35 , V_165 , V_49 ) ;
if ( V_227 )
V_35 -> V_41 &= ~ V_158 ;
if ( V_2 -> V_17 < V_229 ) {
T_1 V_4 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < V_33 ; V_155 ++ ) {
struct V_34 * V_35 = V_2 -> V_36 [ V_155 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
if ( ! F_56 ( & V_35 -> V_116 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_230 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_230 = 0 ;
}
}
static void F_123 ( struct V_1 * V_2 ,
const struct V_164 * V_165 )
{
struct V_34 * V_35 ;
T_2 V_129 = V_165 -> V_231 ;
V_35 = V_2 -> V_36 [ V_129 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
return;
F_8 ( V_2 -> V_23 , L_60 , V_35 -> V_46 ,
F_124 ( V_165 -> V_232 ) ) ;
if ( V_129 == 0 || V_129 == 1 ) {
F_125 ( V_2 , V_165 ) ;
return;
}
switch ( V_165 -> V_232 ) {
case V_233 :
V_35 -> V_161 = 0 ;
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_61 ,
V_35 -> V_46 ) ;
return;
}
F_122 ( V_2 , V_35 , V_165 , 1 ) ;
break;
case V_234 :
if ( ! F_13 ( V_35 -> V_43 . V_44 ) ) {
F_19 ( V_2 -> V_23 , L_62 ,
V_35 -> V_46 ) ;
return;
}
F_122 ( V_2 , V_35 , V_165 , 0 ) ;
break;
case V_235 :
if ( F_13 ( V_35 -> V_43 . V_44 ) ) {
F_92 ( V_2 , V_35 , V_165 ) ;
} else {
int V_107 ;
F_8 ( V_2 -> V_23 , L_63 ,
V_35 -> V_46 , V_165 -> V_49 &
V_236
? L_64
: L_65 ) ;
V_107 = F_88 ( V_35 , 0 , 1 ) ;
if ( ! V_107 || V_107 == - V_159 )
return;
F_19 ( V_2 -> V_23 , L_38 ,
V_35 -> V_46 ) ;
}
break;
case V_237 :
if ( ! F_12 ( V_35 -> V_43 . V_44 ) ) {
F_34 ( V_2 -> V_23 , L_66 ,
V_35 -> V_46 ) ;
return;
}
switch ( V_165 -> V_49 ) {
case V_238 :
F_8 ( V_2 -> V_23 , L_67 ,
V_165 -> V_167 ) ;
break;
case V_239 :
default:
F_19 ( V_2 -> V_23 , L_68 ) ;
}
break;
case V_240 :
F_19 ( V_2 -> V_23 , L_69 , V_35 -> V_46 ) ;
break;
case V_241 :
F_8 ( V_2 -> V_23 , L_70 ) ;
break;
}
}
static void F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_197 && V_2 -> V_197 -> V_242 ) {
F_20 ( & V_2 -> V_64 ) ;
V_2 -> V_197 -> V_242 ( & V_2 -> V_60 ) ;
F_21 ( & V_2 -> V_64 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , T_1 V_129 )
{
struct V_34 * V_35 ;
struct V_82 V_83 ;
T_1 V_66 ;
int V_107 ;
V_35 = V_2 -> V_36 [ V_129 ] ;
if ( ! V_35 -> V_161 )
return;
V_66 = V_68 ;
V_66 |= V_243 | V_244 ;
V_66 |= F_38 ( V_35 -> V_161 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_107 = F_25 ( V_2 , V_35 -> V_38 , V_66 , & V_83 ) ;
F_90 ( V_107 ) ;
V_35 -> V_161 = 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
T_1 V_129 ;
for ( V_129 = 2 ; V_129 < V_33 ; V_129 ++ ) {
struct V_34 * V_35 ;
V_35 = V_2 -> V_36 [ V_129 ] ;
if ( ! ( V_35 -> V_41 & V_42 ) )
continue;
F_55 ( V_2 , V_35 ) ;
}
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_129 ;
for ( V_129 = 1 ; V_129 < V_33 ; V_129 ++ ) {
struct V_34 * V_35 ;
struct V_82 V_83 ;
int V_107 ;
V_35 = V_2 -> V_36 [ V_129 ] ;
if ( ! ( V_35 -> V_41 & V_175 ) )
continue;
V_35 -> V_41 &= ~ V_175 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_107 = F_25 ( V_2 , V_35 -> V_38 ,
V_71 , & V_83 ) ;
F_90 ( V_107 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
int V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_218 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_245 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 &= ~ V_246 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_126 ( V_2 ) ;
V_2 -> V_94 = false ;
V_2 -> V_60 . V_181 = V_247 ;
V_2 -> V_248 = false ;
}
static void F_130 ( struct V_1 * V_2 , int V_249 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_131 ( 0 ) ) ;
if ( V_249 )
V_4 |= V_250 ;
else
V_4 &= ~ V_250 ;
F_3 ( V_2 -> V_5 , F_131 ( 0 ) , V_4 ) ;
}
static void F_132 ( struct V_1 * V_2 , int V_249 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_133 ( 0 ) ) ;
if ( V_249 )
V_4 |= V_251 ;
else
V_4 &= ~ V_251 ;
F_3 ( V_2 -> V_5 , F_133 ( 0 ) , V_4 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_8 ( V_2 -> V_23 , L_57 , V_218 ) ;
if ( V_2 -> V_17 < V_252 ) {
if ( V_2 -> V_248 )
F_129 ( V_2 ) ;
}
V_2 -> V_253 = V_254 ;
if ( V_2 -> V_17 < V_18 ) {
F_132 ( V_2 , false ) ;
F_130 ( V_2 , false ) ;
}
if ( V_2 -> V_60 . V_181 != V_247 )
F_126 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_255 = false ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
V_2 -> V_94 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_202 ) ;
V_4 &= ~ ( V_256 ) ;
F_3 ( V_2 -> V_5 , V_202 , V_4 ) ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_181 )
{
T_1 V_4 ;
T_1 V_257 = V_258 ;
if ( V_181 != V_183 )
return;
if ( ! V_257 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_259 ) ;
V_4 |= F_136 ( V_257 ) ;
F_3 ( V_2 -> V_5 , V_259 , V_4 ) ;
}
static void F_137 ( struct V_1 * V_2 , T_2 V_181 )
{
switch ( V_181 ) {
case V_260 :
F_132 ( V_2 , true ) ;
break;
case V_261 :
case V_262 :
case V_263 :
F_130 ( V_2 , true ) ;
break;
}
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
struct V_34 * V_35 ;
int V_107 ;
T_1 V_4 ;
T_2 V_181 ;
F_8 ( V_2 -> V_23 , L_57 , V_218 ) ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_4 = F_2 ( V_2 -> V_5 , V_19 ) ;
V_181 = V_4 & V_182 ;
V_2 -> V_181 = V_181 ;
F_135 ( V_2 , V_181 ) ;
switch ( V_181 ) {
case V_205 :
if ( V_2 -> V_17 < V_264 )
F_134 ( V_2 ) ;
V_207 . V_122 = F_113 ( 512 ) ;
V_2 -> V_60 . V_214 -> V_45 = 512 ;
V_2 -> V_60 . V_181 = V_260 ;
break;
case V_265 :
V_207 . V_122 = F_113 ( 64 ) ;
V_2 -> V_60 . V_214 -> V_45 = 64 ;
V_2 -> V_60 . V_181 = V_261 ;
break;
case V_266 :
case V_267 :
V_207 . V_122 = F_113 ( 64 ) ;
V_2 -> V_60 . V_214 -> V_45 = 64 ;
V_2 -> V_60 . V_181 = V_262 ;
break;
case V_268 :
V_207 . V_122 = F_113 ( 8 ) ;
V_2 -> V_60 . V_214 -> V_45 = 8 ;
V_2 -> V_60 . V_181 = V_263 ;
break;
}
if ( V_2 -> V_17 < V_18 ) {
F_137 ( V_2 , V_2 -> V_60 . V_181 ) ;
}
V_35 = V_2 -> V_36 [ 0 ] ;
V_107 = F_51 ( V_35 , & V_207 , NULL ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
V_35 = V_2 -> V_36 [ 1 ] ;
V_107 = F_51 ( V_35 , & V_207 , NULL ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_55 , V_35 -> V_46 ) ;
return;
}
}
static void F_139 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_23 , L_57 , V_218 ) ;
V_2 -> V_197 -> V_269 ( & V_2 -> V_60 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
unsigned int V_270 )
{
enum V_14 V_271 = V_270 & V_272 ;
if ( V_2 -> V_17 < V_229 ) {
if ( V_271 == V_188 ) {
T_1 V_230 ;
T_1 V_4 ;
switch ( V_2 -> V_180 ) {
case V_273 :
case V_274 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_230 = V_4 & ( V_246
| V_275
| V_245
| V_276 ) ;
if ( ! V_2 -> V_230 )
V_2 -> V_230 = V_4 & V_230 ;
V_4 &= ~ V_230 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_180 = V_271 ;
F_8 ( V_2 -> V_23 , L_71 , V_218 , V_2 -> V_180 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
const struct V_277 * V_165 )
{
switch ( V_165 -> type ) {
case V_278 :
F_129 ( V_2 ) ;
break;
case V_279 :
F_134 ( V_2 ) ;
break;
case V_280 :
F_138 ( V_2 ) ;
break;
case V_281 :
F_139 ( V_2 ) ;
break;
case V_282 :
F_140 ( V_2 , V_165 -> V_283 ) ;
break;
case V_284 :
F_8 ( V_2 -> V_23 , L_72 ) ;
break;
case V_285 :
F_8 ( V_2 -> V_23 , L_73 ) ;
break;
case V_286 :
F_8 ( V_2 -> V_23 , L_74 ) ;
break;
case V_287 :
F_8 ( V_2 -> V_23 , L_75 ) ;
break;
case V_288 :
F_8 ( V_2 -> V_23 , L_76 ) ;
break;
default:
F_19 ( V_2 -> V_23 , L_77 , V_165 -> type ) ;
}
}
static void F_142 ( struct V_1 * V_2 ,
const union V_289 * V_165 )
{
if ( V_165 -> type . V_290 == 0 ) {
return F_123 ( V_2 , & V_165 -> V_291 ) ;
}
switch ( V_165 -> type . type ) {
case V_292 :
F_141 ( V_2 , & V_165 -> V_293 ) ;
break;
default:
F_34 ( V_2 -> V_23 , L_78 , V_165 -> V_294 ) ;
}
}
static T_7 F_143 ( struct V_1 * V_2 , T_1 V_295 )
{
struct V_296 * V_297 ;
int V_298 ;
T_1 V_219 ;
V_219 = F_2 ( V_2 -> V_5 , F_144 ( V_295 ) ) ;
V_219 &= V_299 ;
if ( ! V_219 )
return V_300 ;
V_297 = V_2 -> V_301 [ V_295 ] ;
V_298 = V_219 ;
while ( V_298 > 0 ) {
union V_289 V_165 ;
V_165 . V_294 = * ( T_1 * ) ( V_297 -> V_295 + V_297 -> V_302 ) ;
F_142 ( V_2 , & V_165 ) ;
V_297 -> V_302 = ( V_297 -> V_302 + 4 ) % V_303 ;
V_298 -= 4 ;
F_3 ( V_2 -> V_5 , F_144 ( V_295 ) , 4 ) ;
}
return V_304 ;
}
static T_7 F_145 ( int V_305 , void * V_306 )
{
struct V_1 * V_2 = V_306 ;
int V_155 ;
T_7 V_107 = V_300 ;
F_21 ( & V_2 -> V_64 ) ;
for ( V_155 = 0 ; V_155 < V_2 -> V_307 ; V_155 ++ ) {
T_7 V_49 ;
V_49 = F_143 ( V_2 , V_155 ) ;
if ( V_49 == V_304 )
V_107 = V_49 ;
}
F_20 ( & V_2 -> V_64 ) ;
return V_107 ;
}
int T_6 F_146 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_107 ;
int V_305 ;
V_2 -> V_308 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_308 ) ,
& V_2 -> V_309 , V_92 ) ;
if ( ! V_2 -> V_308 ) {
F_34 ( V_2 -> V_23 , L_79 ) ;
V_107 = - V_93 ;
goto V_201;
}
V_2 -> V_310 = F_33 ( V_2 -> V_23 , sizeof( * V_2 -> V_310 ) ,
& V_2 -> V_311 , V_92 ) ;
if ( ! V_2 -> V_310 ) {
F_34 ( V_2 -> V_23 , L_80 ) ;
V_107 = - V_93 ;
goto V_208;
}
V_2 -> V_312 = F_71 ( V_313 , V_92 ) ;
if ( ! V_2 -> V_312 ) {
F_34 ( V_2 -> V_23 , L_81 ) ;
V_107 = - V_93 ;
goto V_314;
}
V_2 -> V_315 = F_33 ( V_2 -> V_23 ,
V_313 , & V_2 -> V_316 ,
V_92 ) ;
if ( ! V_2 -> V_315 ) {
F_34 ( V_2 -> V_23 , L_82 ) ;
V_107 = - V_93 ;
goto V_317;
}
F_147 ( & V_2 -> V_60 . V_23 , L_83 ) ;
V_2 -> V_60 . V_212 = & V_318 ;
V_2 -> V_60 . V_319 = V_260 ;
V_2 -> V_60 . V_181 = V_247 ;
V_2 -> V_60 . V_23 . V_320 = V_2 -> V_23 ;
V_2 -> V_60 . V_321 = true ;
F_148 ( & V_2 -> V_60 . V_23 , V_2 -> V_23 -> V_322 ) ;
V_2 -> V_60 . V_23 . V_323 = V_2 -> V_23 -> V_323 ;
V_2 -> V_60 . V_23 . V_324 = V_2 -> V_23 -> V_324 ;
V_2 -> V_60 . V_23 . V_325 = F_119 ;
V_2 -> V_60 . V_46 = L_84 ;
V_107 = F_116 ( V_2 ) ;
if ( V_107 )
goto V_326;
V_305 = F_149 ( F_150 ( V_2 -> V_23 ) , 0 ) ;
V_107 = F_151 ( V_305 , F_145 , V_327 ,
L_85 , V_2 ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_86 ,
V_305 , V_107 ) ;
goto V_328;
}
V_4 = F_2 ( V_2 -> V_5 , V_202 ) ;
V_4 |= V_329 ;
F_3 ( V_2 -> V_5 , V_202 , V_4 ) ;
V_4 = ( V_330 |
V_331 |
V_332 |
V_333 |
V_334 |
V_335 |
V_336 |
V_337 |
V_338 ) ;
F_3 ( V_2 -> V_5 , V_339 , V_4 ) ;
if ( V_2 -> V_17 >= V_18 ) {
V_4 = F_2 ( V_2 -> V_5 , V_202 ) ;
V_4 |= V_329 ;
F_3 ( V_2 -> V_5 , V_202 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ ( V_340 | V_341 ) ;
V_4 |= F_152 ( 28 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_132 ( V_2 , false ) ;
F_130 ( V_2 , false ) ;
}
V_107 = F_153 ( & V_2 -> V_60 . V_23 ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_87 ) ;
F_154 ( & V_2 -> V_60 . V_23 ) ;
goto V_342;
}
V_107 = F_155 ( V_2 -> V_23 , & V_2 -> V_60 ) ;
if ( V_107 ) {
F_34 ( V_2 -> V_23 , L_88 ) ;
goto V_343;
}
return 0 ;
V_343:
F_156 ( & V_2 -> V_60 . V_23 ) ;
V_342:
F_3 ( V_2 -> V_5 , V_339 , 0x00 ) ;
F_157 ( V_305 , V_2 ) ;
V_328:
F_118 ( V_2 ) ;
V_326:
F_36 ( V_2 -> V_23 , V_313 ,
V_2 -> V_315 , V_2 -> V_316 ) ;
V_317:
F_74 ( V_2 -> V_312 ) ;
V_314:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_310 ) ,
V_2 -> V_310 , V_2 -> V_311 ) ;
V_208:
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_308 ) ,
V_2 -> V_308 , V_2 -> V_309 ) ;
V_201:
return V_107 ;
}
void F_158 ( struct V_1 * V_2 )
{
int V_305 ;
F_159 ( & V_2 -> V_60 ) ;
V_305 = F_149 ( F_150 ( V_2 -> V_23 ) , 0 ) ;
F_3 ( V_2 -> V_5 , V_339 , 0x00 ) ;
F_157 ( V_305 , V_2 ) ;
F_118 ( V_2 ) ;
F_36 ( V_2 -> V_23 , V_313 ,
V_2 -> V_315 , V_2 -> V_316 ) ;
F_74 ( V_2 -> V_312 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_310 ) ,
V_2 -> V_310 , V_2 -> V_311 ) ;
F_36 ( V_2 -> V_23 , sizeof( * V_2 -> V_308 ) ,
V_2 -> V_308 , V_2 -> V_309 ) ;
F_156 ( & V_2 -> V_60 . V_23 ) ;
}
