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
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_17 ;
V_4 |= F_5 ( V_15 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
while ( -- V_16 ) {
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( F_6 ( V_4 ) == V_15 )
return 0 ;
F_7 ( 5 ) ;
}
F_8 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
int V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
if ( ! V_2 -> V_26 )
return 0 ;
V_22 = F_10 ( V_2 -> V_27 . V_28 ) ;
V_24 = F_11 ( V_2 -> V_27 . V_29 ) ;
V_24 >>= 3 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
struct V_31 * V_32 = V_2 -> V_33 [ V_25 ] ;
int V_34 = V_32 -> V_35 >> 1 ;
int V_36 = 1 ;
int V_37 ;
if ( ! ( V_32 -> V_35 & 1 ) )
continue;
if ( ! ( V_32 -> V_38 & V_39 ) )
continue;
if ( F_12 ( V_32 -> V_40 )
|| F_13 ( V_32 -> V_40 ) )
V_36 = 3 ;
V_37 = V_36 * ( V_32 -> V_41 . V_42 + V_24 ) ;
V_37 += V_24 ;
V_23 = F_14 ( V_37 , V_24 ) ;
V_23 |= ( V_21 << 16 ) ;
F_8 ( V_2 -> V_19 , L_2 ,
V_32 -> V_43 , V_21 , V_23 & 0xffff ) ;
F_3 ( V_2 -> V_5 , F_15 ( V_34 ) ,
V_23 ) ;
V_21 += ( V_23 & 0xffff ) ;
}
return 0 ;
}
void F_16 ( struct V_31 * V_32 , struct V_44 * V_45 ,
int V_46 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
if ( V_45 -> V_47 ) {
if ( V_45 -> V_48 . V_49 )
V_32 -> V_50 += V_45 -> V_48 . V_49 ;
else
V_32 -> V_50 ++ ;
if ( ( ( V_32 -> V_50 & V_51 ) == V_52 - 1 ) &&
F_13 ( V_32 -> V_40 ) )
V_32 -> V_50 ++ ;
}
F_17 ( & V_45 -> V_53 ) ;
V_45 -> V_54 = NULL ;
if ( V_45 -> V_48 . V_46 == - V_55 )
V_45 -> V_48 . V_46 = V_46 ;
F_18 ( & V_2 -> V_56 , & V_45 -> V_48 ,
V_45 -> V_57 ) ;
F_19 ( V_2 -> V_19 , L_3 ,
V_45 , V_32 -> V_43 , V_45 -> V_48 . V_58 ,
V_45 -> V_48 . V_59 , V_46 ) ;
F_20 ( & V_2 -> V_60 ) ;
V_45 -> V_48 . V_61 ( & V_32 -> V_41 , & V_45 -> V_48 ) ;
F_21 ( & V_2 -> V_60 ) ;
}
static const char * F_22 ( T_2 V_62 )
{
switch ( V_62 ) {
case V_63 :
return L_4 ;
case V_64 :
return L_5 ;
case V_65 :
return L_6 ;
case V_66 :
return L_7 ;
case V_67 :
return L_8 ;
case V_68 :
return L_9 ;
case V_69 :
return L_10 ;
case V_70 :
return L_11 ;
case V_71 :
return L_12 ;
default:
return L_13 ;
}
}
int F_23 ( struct V_1 * V_2 , unsigned V_72 ,
unsigned V_62 , struct V_73 * V_74 )
{
struct V_31 * V_32 = V_2 -> V_33 [ V_72 ] ;
T_1 V_75 = 500 ;
T_1 V_4 ;
F_8 ( V_2 -> V_19 , L_14 ,
V_32 -> V_43 ,
F_22 ( V_62 ) , V_74 -> V_76 ,
V_74 -> V_77 , V_74 -> V_78 ) ;
F_3 ( V_2 -> V_5 , F_24 ( V_72 ) , V_74 -> V_76 ) ;
F_3 ( V_2 -> V_5 , F_25 ( V_72 ) , V_74 -> V_77 ) ;
F_3 ( V_2 -> V_5 , F_26 ( V_72 ) , V_74 -> V_78 ) ;
F_3 ( V_2 -> V_5 , F_27 ( V_72 ) , V_62 | V_79 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , F_27 ( V_72 ) ) ;
if ( ! ( V_4 & V_79 ) ) {
F_8 ( V_2 -> V_19 , L_15 ,
F_28 ( V_4 ) ) ;
return 0 ;
}
V_75 -- ;
if ( ! V_75 )
return - V_20 ;
F_7 ( 1 ) ;
} while ( 1 );
}
static T_3 F_29 ( struct V_31 * V_32 ,
struct V_80 * V_54 )
{
T_1 V_81 = ( char * ) V_54 - ( char * ) V_32 -> V_82 ;
return V_32 -> V_83 + V_81 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
if ( V_32 -> V_82 )
return 0 ;
if ( V_32 -> V_35 == 0 || V_32 -> V_35 == 1 )
return 0 ;
V_32 -> V_82 = F_31 ( V_2 -> V_19 ,
sizeof( struct V_80 ) * V_52 ,
& V_32 -> V_83 , V_84 ) ;
if ( ! V_32 -> V_82 ) {
F_32 ( V_32 -> V_2 -> V_19 , L_16 ,
V_32 -> V_43 ) ;
return - V_85 ;
}
return 0 ;
}
static void F_33 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
F_34 ( V_2 -> V_19 , sizeof( struct V_80 ) * V_52 ,
V_32 -> V_82 , V_32 -> V_83 ) ;
V_32 -> V_82 = NULL ;
V_32 -> V_83 = 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_73 V_74 ;
T_1 V_62 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
if ( V_32 -> V_35 != 1 ) {
V_62 = V_63 ;
if ( V_32 -> V_35 > 1 ) {
if ( V_2 -> V_86 )
return 0 ;
V_2 -> V_86 = true ;
V_62 |= F_36 ( 2 ) ;
}
return F_23 ( V_2 , 0 , V_62 , & V_74 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_31 * V_32 ,
const struct V_87 * V_40 ,
const struct V_88 * V_89 )
{
struct V_73 V_74 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
V_74 . V_76 = F_38 ( F_39 ( V_40 ) )
| F_40 ( F_41 ( V_40 ) )
| F_42 ( V_32 -> V_41 . V_90 ) ;
V_74 . V_77 = V_91
| V_92 ;
if ( F_43 ( V_89 ) && F_12 ( V_40 ) ) {
V_74 . V_77 |= V_93
| V_94 ;
V_32 -> V_95 = true ;
}
if ( F_13 ( V_40 ) )
V_74 . V_77 |= V_96 ;
V_74 . V_77 |= F_44 ( V_32 -> V_35 ) ;
if ( V_32 -> V_57 )
V_74 . V_76 |= F_45 ( V_32 -> V_35 >> 1 ) ;
if ( V_40 -> V_97 ) {
V_74 . V_77 |= F_46 ( V_40 -> V_97 - 1 ) ;
V_32 -> V_98 = 1 << ( V_40 -> V_97 - 1 ) ;
}
return F_23 ( V_2 , V_32 -> V_35 ,
V_71 , & V_74 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_73 V_74 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
V_74 . V_76 = F_48 ( 1 ) ;
return F_23 ( V_2 , V_32 -> V_35 ,
V_70 , & V_74 ) ;
}
static int F_49 ( struct V_31 * V_32 ,
const struct V_87 * V_40 ,
const struct V_88 * V_89 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_4 ;
int V_99 = - V_85 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
V_99 = F_35 ( V_2 , V_32 ) ;
if ( V_99 )
return V_99 ;
}
V_99 = F_37 ( V_2 , V_32 , V_40 , V_89 ) ;
if ( V_99 )
return V_99 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
struct V_80 * V_100 ;
struct V_80 * V_101 ;
V_99 = F_47 ( V_2 , V_32 ) ;
if ( V_99 )
return V_99 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_89 = V_89 ;
V_32 -> type = F_39 ( V_40 ) ;
V_32 -> V_38 |= V_39 ;
V_4 = F_2 ( V_2 -> V_5 , V_102 ) ;
V_4 |= F_50 ( V_32 -> V_35 ) ;
F_3 ( V_2 -> V_5 , V_102 , V_4 ) ;
if ( ! F_13 ( V_40 ) )
return 0 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_100 = & V_32 -> V_82 [ 0 ] ;
V_101 = & V_32 -> V_82 [ V_52 - 1 ] ;
V_101 -> V_103 = F_51 ( F_29 ( V_32 , V_100 ) ) ;
V_101 -> V_104 = F_52 ( F_29 ( V_32 , V_100 ) ) ;
V_101 -> V_105 |= V_106 ;
V_101 -> V_105 |= V_107 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_44 * V_45 ;
if ( ! F_54 ( & V_32 -> V_108 ) )
F_55 ( V_2 , V_32 -> V_35 ) ;
while ( ! F_54 ( & V_32 -> V_109 ) ) {
V_45 = F_56 ( & V_32 -> V_109 ) ;
F_16 ( V_32 , V_45 , - V_110 ) ;
}
}
static int F_57 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_4 ;
F_53 ( V_2 , V_32 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_102 ) ;
V_4 &= ~ F_50 ( V_32 -> V_35 ) ;
F_3 ( V_2 -> V_5 , V_102 , V_4 ) ;
V_32 -> V_95 = false ;
V_32 -> V_40 = NULL ;
V_32 -> V_41 . V_40 = NULL ;
V_32 -> V_89 = NULL ;
V_32 -> type = 0 ;
V_32 -> V_38 = 0 ;
return 0 ;
}
static int F_58 ( struct V_111 * V_72 ,
const struct V_87 * V_40 )
{
return - V_13 ;
}
static int F_59 ( struct V_111 * V_72 )
{
return - V_13 ;
}
static int F_60 ( struct V_111 * V_72 ,
const struct V_87 * V_40 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
unsigned long V_38 ;
int V_99 ;
if ( ! V_72 || ! V_40 || V_40 -> V_112 != V_113 ) {
F_61 ( L_17 ) ;
return - V_13 ;
}
if ( ! V_40 -> V_114 ) {
F_61 ( L_18 ) ;
return - V_13 ;
}
V_32 = F_62 ( V_72 ) ;
V_2 = V_32 -> V_2 ;
switch ( F_39 ( V_40 ) ) {
case V_115 :
F_63 ( V_32 -> V_43 , L_19 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_116 :
F_63 ( V_32 -> V_43 , L_20 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_117 :
F_63 ( V_32 -> V_43 , L_21 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_118 :
F_63 ( V_32 -> V_43 , L_22 , sizeof( V_32 -> V_43 ) ) ;
break;
default:
F_32 ( V_2 -> V_19 , L_23 ) ;
}
if ( V_32 -> V_38 & V_39 ) {
F_64 ( V_2 -> V_19 , true , L_24 ,
V_32 -> V_43 ) ;
return 0 ;
}
F_8 ( V_2 -> V_19 , L_25 , V_32 -> V_43 ) ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_99 = F_49 ( V_32 , V_40 , V_72 -> V_89 ) ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static int F_67 ( struct V_111 * V_72 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
unsigned long V_38 ;
int V_99 ;
if ( ! V_72 ) {
F_61 ( L_17 ) ;
return - V_13 ;
}
V_32 = F_62 ( V_72 ) ;
V_2 = V_32 -> V_2 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
F_64 ( V_2 -> V_19 , true , L_26 ,
V_32 -> V_43 ) ;
return 0 ;
}
snprintf ( V_32 -> V_43 , sizeof( V_32 -> V_43 ) , L_27 ,
V_32 -> V_35 >> 1 ,
( V_32 -> V_35 & 1 ) ? L_28 : L_29 ) ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_99 = F_57 ( V_32 ) ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static struct V_119 * F_68 ( struct V_111 * V_72 ,
T_4 V_120 )
{
struct V_44 * V_45 ;
struct V_31 * V_32 = F_62 ( V_72 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
V_45 = F_69 ( sizeof( * V_45 ) , V_120 ) ;
if ( ! V_45 ) {
F_32 ( V_2 -> V_19 , L_30 ) ;
return NULL ;
}
V_45 -> V_121 = V_32 -> V_35 ;
V_45 -> V_32 = V_32 ;
return & V_45 -> V_48 ;
}
static void F_70 ( struct V_111 * V_72 ,
struct V_119 * V_48 )
{
struct V_44 * V_45 = F_71 ( V_48 ) ;
F_72 ( V_45 ) ;
}
static void F_73 ( struct V_31 * V_32 ,
struct V_44 * V_45 , T_3 V_122 ,
unsigned V_59 , unsigned V_123 , unsigned V_124 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_80 * V_54 ;
unsigned int V_125 ;
F_8 ( V_2 -> V_19 , L_31 ,
V_32 -> V_43 , V_45 , ( unsigned long long ) V_122 ,
V_59 , V_123 ? L_32 : L_33 ,
V_124 ? L_34 : L_33 ) ;
V_54 = & V_32 -> V_82 [ V_32 -> V_126 & V_51 ] ;
V_125 = V_32 -> V_126 ;
V_32 -> V_126 ++ ;
if ( ( ( V_125 & V_51 ) == V_52 - 1 ) &&
F_13 ( V_32 -> V_40 ) )
return;
if ( ! V_45 -> V_54 ) {
F_74 ( V_45 ) ;
V_45 -> V_54 = V_54 ;
V_45 -> V_127 = F_29 ( V_32 , V_54 ) ;
}
V_54 -> V_128 = F_75 ( V_59 ) ;
V_54 -> V_103 = F_51 ( V_122 ) ;
V_54 -> V_104 = F_52 ( V_122 ) ;
switch ( F_39 ( V_32 -> V_40 ) ) {
case V_115 :
V_54 -> V_105 = V_129 ;
break;
case V_116 :
V_54 -> V_105 = V_130 ;
if ( ! ( V_125 % ( V_52 / 4 ) ) )
V_54 -> V_105 |= V_131 ;
break;
case V_117 :
case V_118 :
V_54 -> V_105 = V_132 ;
break;
default:
F_76 () ;
}
if ( F_13 ( V_32 -> V_40 ) ) {
V_54 -> V_105 |= V_133 ;
V_54 -> V_105 |= V_134 ;
} else {
if ( V_124 )
V_54 -> V_105 |= V_135 ;
if ( V_123 )
V_54 -> V_105 |= V_136 ;
}
if ( F_12 ( V_32 -> V_40 ) && V_32 -> V_95 )
V_54 -> V_105 |= F_77 ( V_45 -> V_48 . V_137 ) ;
V_54 -> V_105 |= V_107 ;
}
static void F_78 ( struct V_31 * V_32 , bool V_138 )
{
struct V_44 * V_45 , * V_139 ;
T_1 V_140 ;
T_1 V_141 ;
unsigned int V_142 = 0 ;
F_79 ( V_52 ) ;
V_140 = ( V_32 -> V_50 - V_32 -> V_126 ) & V_51 ;
if ( ! F_13 ( V_32 -> V_40 ) ) {
V_141 = V_52 - ( V_32 -> V_126 & V_51 ) ;
if ( V_140 > V_141 )
V_140 = V_141 ;
}
if ( ! V_140 ) {
if ( ! V_138 )
return;
V_140 = V_52 ;
if ( F_13 ( V_32 -> V_40 ) ) {
V_32 -> V_50 = 1 ;
V_32 -> V_126 = 1 ;
} else {
V_32 -> V_50 = 0 ;
V_32 -> V_126 = 0 ;
}
}
if ( ( V_140 <= 1 ) && F_13 ( V_32 -> V_40 ) )
return;
F_80 (req, n, &dep->request_list, list) {
unsigned V_59 ;
T_3 V_122 ;
if ( V_45 -> V_48 . V_49 > 0 ) {
struct V_119 * V_48 = & V_45 -> V_48 ;
struct V_143 * V_144 = V_48 -> V_144 ;
struct V_143 * V_145 ;
int V_146 ;
F_81 (sg, s, request->num_mapped_sgs, i) {
unsigned V_124 = true ;
V_59 = F_82 ( V_145 ) ;
V_122 = F_83 ( V_145 ) ;
if ( V_146 == ( V_48 -> V_49 - 1 ) ||
F_84 ( V_145 ) ) {
V_142 = true ;
V_124 = false ;
}
V_140 -- ;
if ( ! V_140 )
V_142 = true ;
if ( V_142 )
V_124 = false ;
F_73 ( V_32 , V_45 , V_122 , V_59 ,
V_142 , V_124 ) ;
if ( V_142 )
break;
}
} else {
V_122 = V_45 -> V_48 . V_122 ;
V_59 = V_45 -> V_48 . V_59 ;
V_140 -- ;
if ( ! V_140 )
V_142 = 1 ;
if ( F_85 ( & V_45 -> V_53 , & V_32 -> V_109 ) )
V_142 = 1 ;
F_73 ( V_32 , V_45 , V_122 , V_59 ,
V_142 , false ) ;
if ( V_142 )
break;
}
}
}
static int F_86 ( struct V_31 * V_32 , T_5 V_147 ,
int V_148 )
{
struct V_73 V_74 ;
struct V_44 * V_45 ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_99 ;
T_1 V_62 ;
if ( V_148 && ( V_32 -> V_38 & V_149 ) ) {
F_8 ( V_2 -> V_19 , L_35 , V_32 -> V_43 ) ;
return - V_150 ;
}
V_32 -> V_38 &= ~ V_151 ;
if ( V_148 ) {
if ( F_54 ( & V_32 -> V_108 ) )
F_78 ( V_32 , V_148 ) ;
V_45 = F_56 ( & V_32 -> V_108 ) ;
} else {
F_78 ( V_32 , V_148 ) ;
V_45 = F_56 ( & V_32 -> V_108 ) ;
}
if ( ! V_45 ) {
V_32 -> V_38 |= V_151 ;
return 0 ;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_76 = F_52 ( V_45 -> V_127 ) ;
V_74 . V_77 = F_51 ( V_45 -> V_127 ) ;
if ( V_148 )
V_62 = V_66 ;
else
V_62 = V_65 ;
V_62 |= F_36 ( V_147 ) ;
V_99 = F_23 ( V_2 , V_32 -> V_35 , V_62 , & V_74 ) ;
if ( V_99 < 0 ) {
F_19 ( V_2 -> V_19 , L_36 ) ;
F_18 ( & V_2 -> V_56 , & V_45 -> V_48 ,
V_45 -> V_57 ) ;
F_17 ( & V_45 -> V_53 ) ;
return V_99 ;
}
V_32 -> V_38 |= V_149 ;
V_32 -> V_152 = F_87 ( V_2 ,
V_32 -> V_35 ) ;
F_88 ( ! V_32 -> V_152 ) ;
return 0 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
int V_99 ;
V_45 -> V_48 . V_58 = 0 ;
V_45 -> V_48 . V_46 = - V_55 ;
V_45 -> V_57 = V_32 -> V_57 ;
V_45 -> V_121 = V_32 -> V_35 ;
V_99 = F_90 ( & V_2 -> V_56 , & V_45 -> V_48 ,
V_32 -> V_57 ) ;
if ( V_99 )
return V_99 ;
F_91 ( & V_45 -> V_53 , & V_32 -> V_109 ) ;
if ( V_32 -> V_38 & V_151 ) {
int V_99 ;
int V_153 ;
V_153 = 1 ;
if ( F_13 ( V_32 -> V_40 ) &&
( V_32 -> V_38 & V_149 ) )
V_153 = 0 ;
V_99 = F_86 ( V_32 , 0 , V_153 ) ;
if ( V_99 && V_99 != - V_150 ) {
struct V_1 * V_2 = V_32 -> V_2 ;
F_19 ( V_2 -> V_19 , L_37 ,
V_32 -> V_43 ) ;
}
} ;
return 0 ;
}
static int F_92 ( struct V_111 * V_72 , struct V_119 * V_48 ,
T_4 V_120 )
{
struct V_44 * V_45 = F_71 ( V_48 ) ;
struct V_31 * V_32 = F_62 ( V_72 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_99 ;
if ( ! V_32 -> V_40 ) {
F_19 ( V_2 -> V_19 , L_38 ,
V_48 , V_72 -> V_43 ) ;
return - V_110 ;
}
F_8 ( V_2 -> V_19 , L_39 ,
V_48 , V_72 -> V_43 , V_48 -> V_59 ) ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_99 = F_89 ( V_32 , V_45 ) ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static int F_93 ( struct V_111 * V_72 ,
struct V_119 * V_48 )
{
struct V_44 * V_45 = F_71 ( V_48 ) ;
struct V_44 * V_154 = NULL ;
struct V_31 * V_32 = F_62 ( V_72 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_99 = 0 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
F_94 (r, &dep->request_list, list) {
if ( V_154 == V_45 )
break;
}
if ( V_154 != V_45 ) {
F_94 (r, &dep->req_queued, list) {
if ( V_154 == V_45 )
break;
}
if ( V_154 == V_45 ) {
F_55 ( V_2 , V_32 -> V_35 ) ;
goto V_155;
}
F_32 ( V_2 -> V_19 , L_40 ,
V_48 , V_72 -> V_43 ) ;
V_99 = - V_13 ;
goto V_155;
}
F_16 ( V_32 , V_45 , - V_156 ) ;
V_155:
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
int F_95 ( struct V_31 * V_32 , int V_157 )
{
struct V_73 V_74 ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_99 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
if ( V_157 ) {
if ( V_32 -> V_35 == 0 || V_32 -> V_35 == 1 ) {
V_2 -> V_158 = V_159 ;
}
V_99 = F_23 ( V_2 , V_32 -> V_35 ,
V_68 , & V_74 ) ;
if ( V_99 )
F_32 ( V_2 -> V_19 , L_41 ,
V_157 ? L_42 : L_43 ,
V_32 -> V_43 ) ;
else
V_32 -> V_38 |= V_160 ;
} else {
if ( V_32 -> V_38 & V_161 )
return 0 ;
V_99 = F_23 ( V_2 , V_32 -> V_35 ,
V_67 , & V_74 ) ;
if ( V_99 )
F_32 ( V_2 -> V_19 , L_41 ,
V_157 ? L_42 : L_43 ,
V_32 -> V_43 ) ;
else
V_32 -> V_38 &= ~ V_160 ;
}
return V_99 ;
}
static int F_96 ( struct V_111 * V_72 , int V_157 )
{
struct V_31 * V_32 = F_62 ( V_72 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_99 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
if ( F_13 ( V_32 -> V_40 ) ) {
F_32 ( V_2 -> V_19 , L_44 , V_32 -> V_43 ) ;
V_99 = - V_13 ;
goto V_162;
}
V_99 = F_95 ( V_32 , V_157 ) ;
V_162:
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static int F_97 ( struct V_111 * V_72 )
{
struct V_31 * V_32 = F_62 ( V_72 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_32 -> V_38 |= V_161 ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return F_96 ( V_72 , 1 ) ;
}
static int F_98 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
return F_100 ( V_4 ) ;
}
static int F_101 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
unsigned long V_75 ;
unsigned long V_38 ;
T_1 V_4 ;
int V_99 = 0 ;
T_2 V_165 ;
T_2 V_166 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
V_166 = V_4 & V_167 ;
if ( V_166 == V_168 ) {
F_19 ( V_2 -> V_19 , L_45 ) ;
V_99 = - V_13 ;
goto V_162;
}
V_165 = F_6 ( V_4 ) ;
switch ( V_165 ) {
case V_169 :
case V_170 :
break;
default:
F_19 ( V_2 -> V_19 , L_46 ,
V_165 ) ;
V_99 = - V_13 ;
goto V_162;
}
V_99 = F_4 ( V_2 , V_171 ) ;
if ( V_99 < 0 ) {
F_32 ( V_2 -> V_19 , L_47 ) ;
goto V_162;
}
V_4 &= ~ V_17 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_75 = V_172 + F_102 ( 100 ) ;
while ( ! F_103 ( V_172 , V_75 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( F_6 ( V_4 ) == V_173 )
break;
}
if ( F_6 ( V_4 ) != V_173 ) {
F_32 ( V_2 -> V_19 , L_48 ) ;
V_99 = - V_13 ;
}
V_162:
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static int F_104 ( struct V_163 * V_164 ,
int V_174 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
unsigned long V_38 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
V_2 -> V_174 = ! ! V_174 ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 , int V_175 )
{
T_1 V_4 ;
T_1 V_75 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_175 ) {
V_4 &= ~ V_176 ;
V_4 |= ( V_177
| V_178 ) ;
} else {
V_4 &= ~ V_177 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( V_175 ) {
if ( ! ( V_4 & V_179 ) )
break;
} else {
if ( V_4 & V_179 )
break;
}
V_75 -- ;
if ( ! V_75 )
break;
F_7 ( 1 ) ;
} while ( 1 );
F_8 ( V_2 -> V_19 , L_49 ,
V_2 -> V_180
? V_2 -> V_180 -> V_181 : L_50 ,
V_175 ? L_51 : L_52 ) ;
}
static int F_106 ( struct V_163 * V_164 , int V_175 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
unsigned long V_38 ;
V_175 = ! ! V_175 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
F_105 ( V_2 , V_175 ) ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static int F_107 ( struct V_163 * V_164 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
struct V_31 * V_32 ;
unsigned long V_38 ;
int V_99 = 0 ;
T_1 V_4 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
if ( V_2 -> V_180 ) {
F_32 ( V_2 -> V_19 , L_53 ,
V_2 -> V_56 . V_43 ,
V_2 -> V_180 -> V_183 . V_43 ) ;
V_99 = - V_150 ;
goto V_184;
}
V_2 -> V_180 = V_183 ;
V_2 -> V_56 . V_19 . V_183 = & V_183 -> V_183 ;
V_4 = F_2 ( V_2 -> V_5 , V_185 ) ;
V_4 &= ~ ( V_186 ) ;
V_4 |= V_2 -> V_187 ;
F_3 ( V_2 -> V_5 , V_185 , V_4 ) ;
V_2 -> V_86 = false ;
V_188 . V_114 = F_108 ( 512 ) ;
V_32 = V_2 -> V_33 [ 0 ] ;
V_99 = F_49 ( V_32 , & V_188 , NULL ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
goto V_184;
}
V_32 = V_2 -> V_33 [ 1 ] ;
V_99 = F_49 ( V_32 , & V_188 , NULL ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
goto V_189;
}
V_2 -> V_158 = V_159 ;
F_109 ( V_2 ) ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
V_189:
F_57 ( V_2 -> V_33 [ 0 ] ) ;
V_184:
F_66 ( & V_2 -> V_60 , V_38 ) ;
return V_99 ;
}
static int F_110 ( struct V_163 * V_164 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_99 ( V_164 ) ;
unsigned long V_38 ;
F_65 ( & V_2 -> V_60 , V_38 ) ;
F_57 ( V_2 -> V_33 [ 0 ] ) ;
F_57 ( V_2 -> V_33 [ 1 ] ) ;
V_2 -> V_180 = NULL ;
V_2 -> V_56 . V_19 . V_183 = NULL ;
F_66 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static int T_6 F_111 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_2 V_121 ;
F_112 ( & V_2 -> V_56 . V_190 ) ;
for ( V_121 = 0 ; V_121 < V_30 ; V_121 ++ ) {
V_32 = F_69 ( sizeof( * V_32 ) , V_84 ) ;
if ( ! V_32 ) {
F_32 ( V_2 -> V_19 , L_55 ,
V_121 ) ;
return - V_85 ;
}
V_32 -> V_2 = V_2 ;
V_32 -> V_35 = V_121 ;
V_2 -> V_33 [ V_121 ] = V_32 ;
snprintf ( V_32 -> V_43 , sizeof( V_32 -> V_43 ) , L_27 , V_121 >> 1 ,
( V_121 & 1 ) ? L_28 : L_29 ) ;
V_32 -> V_41 . V_43 = V_32 -> V_43 ;
V_32 -> V_57 = ( V_121 & 1 ) ;
if ( V_121 == 0 || V_121 == 1 ) {
V_32 -> V_41 . V_42 = 512 ;
V_32 -> V_41 . V_191 = & V_192 ;
if ( ! V_121 )
V_2 -> V_56 . V_193 = & V_32 -> V_41 ;
} else {
int V_99 ;
V_32 -> V_41 . V_42 = 1024 ;
V_32 -> V_41 . V_194 = 15 ;
V_32 -> V_41 . V_191 = & V_195 ;
F_91 ( & V_32 -> V_41 . V_190 ,
& V_2 -> V_56 . V_190 ) ;
V_99 = F_30 ( V_32 ) ;
if ( V_99 )
return V_99 ;
}
F_112 ( & V_32 -> V_109 ) ;
F_112 ( & V_32 -> V_108 ) ;
}
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_2 V_121 ;
for ( V_121 = 0 ; V_121 < V_30 ; V_121 ++ ) {
V_32 = V_2 -> V_33 [ V_121 ] ;
F_33 ( V_32 ) ;
if ( V_121 != 0 && V_121 != 1 )
F_17 ( & V_32 -> V_41 . V_190 ) ;
F_72 ( V_32 ) ;
}
}
static void F_114 ( struct V_196 * V_19 )
{
F_19 ( V_19 , L_56 , V_197 ) ;
}
static int F_115 ( struct V_1 * V_2 , struct V_31 * V_32 ,
const struct V_198 * V_199 , int V_46 )
{
struct V_44 * V_45 ;
struct V_80 * V_54 ;
unsigned int V_200 ;
unsigned int V_201 = 0 ;
do {
V_45 = F_56 ( & V_32 -> V_108 ) ;
if ( ! V_45 ) {
F_88 ( 1 ) ;
return 1 ;
}
V_54 = V_45 -> V_54 ;
if ( ( V_54 -> V_105 & V_107 ) && V_46 != - V_110 )
F_32 ( V_2 -> V_19 , L_57 ,
V_32 -> V_43 , V_45 -> V_54 ) ;
V_200 = V_54 -> V_128 & V_202 ;
if ( V_32 -> V_57 ) {
if ( V_200 ) {
F_32 ( V_2 -> V_19 , L_58 ,
V_32 -> V_43 ) ;
V_46 = - V_156 ;
}
} else {
if ( V_200 && ( V_199 -> V_46 & V_203 ) )
V_201 = 1 ;
}
V_45 -> V_48 . V_58 += V_45 -> V_48 . V_59 - V_200 ;
F_16 ( V_32 , V_45 , V_46 ) ;
if ( V_201 )
break;
if ( ( V_199 -> V_46 & V_204 ) &&
( V_54 -> V_105 & V_136 ) )
break;
if ( ( V_199 -> V_46 & V_205 ) &&
( V_54 -> V_105 & V_131 ) )
break;
} while ( 1 );
if ( ( V_199 -> V_46 & V_205 ) &&
( V_54 -> V_105 & V_131 ) )
return 0 ;
return 1 ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_31 * V_32 , const struct V_198 * V_199 ,
int V_148 )
{
unsigned V_46 = 0 ;
int V_206 ;
if ( V_199 -> V_46 & V_207 )
V_46 = - V_156 ;
V_206 = F_115 ( V_2 , V_32 , V_199 , V_46 ) ;
if ( V_206 )
V_32 -> V_38 &= ~ V_149 ;
if ( V_2 -> V_208 < V_209 ) {
T_1 V_4 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_30 ; V_146 ++ ) {
struct V_31 * V_32 = V_2 -> V_33 [ V_146 ] ;
if ( ! ( V_32 -> V_38 & V_39 ) )
continue;
if ( ! F_54 ( & V_32 -> V_108 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_210 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_210 = 0 ;
}
}
static void F_117 ( struct V_1 * V_2 ,
struct V_31 * V_32 , const struct V_198 * V_199 )
{
T_1 V_211 , V_212 ;
if ( F_54 ( & V_32 -> V_109 ) ) {
F_8 ( V_2 -> V_19 , L_59 ,
V_32 -> V_43 ) ;
return;
}
V_212 = ~ ( V_32 -> V_98 - 1 ) ;
V_211 = V_199 -> V_213 & V_212 ;
V_211 += V_32 -> V_98 * 4 ;
F_86 ( V_32 , V_211 , 1 ) ;
}
static void F_118 ( struct V_31 * V_32 ,
const struct V_198 * V_199 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_198 V_214 = * V_199 ;
V_214 . V_46 = V_204 ;
F_115 ( V_2 , V_32 , & V_214 , - V_110 ) ;
V_32 -> V_38 &= ~ V_149 ;
}
static void F_119 ( struct V_31 * V_32 ,
const struct V_198 * V_199 )
{
T_1 V_215 = V_199 -> V_213 ;
T_1 V_216 = ( V_215 >> 8 ) & ( ( 1 << 5 ) - 1 ) ;
switch ( V_216 ) {
case V_64 :
F_118 ( V_32 , V_199 ) ;
break;
case V_66 :
V_32 -> V_152 = V_215 & 0x7f ;
break;
default:
F_120 ( V_217 L_60 ,
V_197 , V_216 ) ;
break;
} ;
}
static void F_121 ( struct V_1 * V_2 ,
const struct V_198 * V_199 )
{
struct V_31 * V_32 ;
T_2 V_121 = V_199 -> V_218 ;
V_32 = V_2 -> V_33 [ V_121 ] ;
F_8 ( V_2 -> V_19 , L_61 , V_32 -> V_43 ,
F_122 ( V_199 -> V_219 ) ) ;
if ( V_121 == 0 || V_121 == 1 ) {
F_123 ( V_2 , V_199 ) ;
return;
}
switch ( V_199 -> V_219 ) {
case V_220 :
V_32 -> V_152 = 0 ;
if ( F_13 ( V_32 -> V_40 ) ) {
F_19 ( V_2 -> V_19 , L_62 ,
V_32 -> V_43 ) ;
return;
}
F_116 ( V_2 , V_32 , V_199 , 1 ) ;
break;
case V_221 :
if ( ! F_13 ( V_32 -> V_40 ) ) {
F_19 ( V_2 -> V_19 , L_63 ,
V_32 -> V_43 ) ;
return;
}
F_116 ( V_2 , V_32 , V_199 , 0 ) ;
break;
case V_222 :
if ( F_13 ( V_32 -> V_40 ) ) {
F_117 ( V_2 , V_32 , V_199 ) ;
} else {
int V_99 ;
F_8 ( V_2 -> V_19 , L_64 ,
V_32 -> V_43 , V_199 -> V_46 &
V_223
? L_65
: L_66 ) ;
V_99 = F_86 ( V_32 , 0 , 1 ) ;
if ( ! V_99 || V_99 == - V_150 )
return;
F_19 ( V_2 -> V_19 , L_37 ,
V_32 -> V_43 ) ;
}
break;
case V_224 :
if ( ! F_12 ( V_32 -> V_40 ) ) {
F_32 ( V_2 -> V_19 , L_67 ,
V_32 -> V_43 ) ;
return;
}
switch ( V_199 -> V_46 ) {
case V_225 :
F_8 ( V_2 -> V_19 , L_68 ,
V_199 -> V_213 ) ;
break;
case V_226 :
default:
F_19 ( V_2 -> V_19 , L_69 ) ;
}
break;
case V_227 :
F_19 ( V_2 -> V_19 , L_70 , V_32 -> V_43 ) ;
break;
case V_228 :
F_119 ( V_32 , V_199 ) ;
break;
}
}
static void F_124 ( struct V_1 * V_2 )
{
if ( V_2 -> V_180 && V_2 -> V_180 -> V_229 ) {
F_20 ( & V_2 -> V_60 ) ;
V_2 -> V_180 -> V_229 ( & V_2 -> V_56 ) ;
F_21 ( & V_2 -> V_60 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , T_1 V_121 )
{
struct V_31 * V_32 ;
struct V_73 V_74 ;
T_1 V_62 ;
int V_99 ;
V_32 = V_2 -> V_33 [ V_121 ] ;
F_125 ( ! V_32 -> V_152 ) ;
if ( V_32 -> V_152 ) {
V_62 = V_64 ;
V_62 |= V_230 | V_231 ;
V_62 |= F_36 ( V_32 -> V_152 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_99 = F_23 ( V_2 , V_32 -> V_35 , V_62 , & V_74 ) ;
F_88 ( V_99 ) ;
V_32 -> V_152 = 0 ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
T_1 V_121 ;
for ( V_121 = 2 ; V_121 < V_30 ; V_121 ++ ) {
struct V_31 * V_32 ;
V_32 = V_2 -> V_33 [ V_121 ] ;
if ( ! ( V_32 -> V_38 & V_39 ) )
continue;
F_53 ( V_2 , V_32 ) ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
T_1 V_121 ;
for ( V_121 = 1 ; V_121 < V_30 ; V_121 ++ ) {
struct V_31 * V_32 ;
struct V_73 V_74 ;
int V_99 ;
V_32 = V_2 -> V_33 [ V_121 ] ;
if ( ! ( V_32 -> V_38 & V_160 ) )
continue;
V_32 -> V_38 &= ~ V_160 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_99 = F_23 ( V_2 , V_32 -> V_35 ,
V_67 , & V_74 ) ;
F_88 ( V_99 ) ;
}
}
static void F_128 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_19 , L_56 , V_197 ) ;
#if 0
XXX
U1/U2 is powersave optimization. Skip it for now. Anyway we need to
enable it before we can disable it.
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
#endif
F_126 ( V_2 ) ;
F_124 ( V_2 ) ;
V_2 -> V_86 = false ;
V_2 -> V_56 . V_166 = V_232 ;
V_2 -> V_233 = false ;
}
static void F_129 ( struct V_1 * V_2 , int V_234 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_130 ( 0 ) ) ;
if ( V_234 )
V_4 &= ~ V_235 ;
else
V_4 |= V_235 ;
F_3 ( V_2 -> V_5 , F_130 ( 0 ) , V_4 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_234 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_132 ( 0 ) ) ;
if ( V_234 )
V_4 &= ~ V_236 ;
else
V_4 |= V_236 ;
F_3 ( V_2 -> V_5 , F_132 ( 0 ) , V_4 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_8 ( V_2 -> V_19 , L_56 , V_197 ) ;
if ( V_2 -> V_208 < V_237 ) {
if ( V_2 -> V_233 )
F_128 ( V_2 ) ;
}
V_2 -> V_238 = V_239 ;
F_131 ( V_2 , true ) ;
F_129 ( V_2 , true ) ;
if ( V_2 -> V_56 . V_166 != V_232 )
F_124 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_240 = false ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
V_2 -> V_86 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_185 ) ;
V_4 &= ~ ( V_241 ) ;
F_3 ( V_2 -> V_5 , V_185 , V_4 ) ;
}
static void F_134 ( struct V_1 * V_2 , T_1 V_166 )
{
T_1 V_4 ;
T_1 V_242 = V_243 ;
if ( V_166 != V_168 )
return;
if ( ! V_242 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_244 ) ;
V_4 |= F_135 ( V_242 ) ;
F_3 ( V_2 -> V_5 , V_244 , V_4 ) ;
}
static void F_136 ( struct V_1 * V_2 , T_2 V_166 )
{
switch ( V_166 ) {
case V_245 :
F_131 ( V_2 , false ) ;
break;
case V_246 :
case V_247 :
case V_248 :
F_129 ( V_2 , false ) ;
break;
}
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_73 V_74 ;
struct V_31 * V_32 ;
int V_99 ;
T_1 V_4 ;
T_2 V_166 ;
F_8 ( V_2 -> V_19 , L_56 , V_197 ) ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
V_166 = V_4 & V_167 ;
V_2 -> V_166 = V_166 ;
F_134 ( V_2 , V_166 ) ;
switch ( V_166 ) {
case V_249 :
if ( V_2 -> V_208 < V_250 )
F_133 ( V_2 ) ;
V_188 . V_114 = F_108 ( 512 ) ;
V_2 -> V_56 . V_193 -> V_42 = 512 ;
V_2 -> V_56 . V_166 = V_245 ;
break;
case V_251 :
V_188 . V_114 = F_108 ( 64 ) ;
V_2 -> V_56 . V_193 -> V_42 = 64 ;
V_2 -> V_56 . V_166 = V_246 ;
break;
case V_252 :
case V_253 :
V_188 . V_114 = F_108 ( 64 ) ;
V_2 -> V_56 . V_193 -> V_42 = 64 ;
V_2 -> V_56 . V_166 = V_247 ;
break;
case V_254 :
V_188 . V_114 = F_108 ( 8 ) ;
V_2 -> V_56 . V_193 -> V_42 = 8 ;
V_2 -> V_56 . V_166 = V_248 ;
break;
}
F_136 ( V_2 , V_2 -> V_56 . V_166 ) ;
V_32 = V_2 -> V_33 [ 0 ] ;
V_99 = F_49 ( V_32 , & V_188 , NULL ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
return;
}
V_32 = V_2 -> V_33 [ 1 ] ;
V_99 = F_49 ( V_32 , & V_188 , NULL ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
return;
}
}
static void F_138 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_19 , L_56 , V_197 ) ;
V_2 -> V_180 -> V_255 ( & V_2 -> V_56 ) ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned int V_256 )
{
enum V_14 V_257 = V_256 & V_258 ;
if ( V_2 -> V_208 < V_209 ) {
if ( V_257 == V_173 ) {
T_1 V_210 ;
T_1 V_4 ;
switch ( V_2 -> V_165 ) {
case V_259 :
case V_260 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_210 = V_4 & ( V_261
| V_262
| V_263
| V_264 ) ;
if ( ! V_2 -> V_210 )
V_2 -> V_210 = V_4 & V_210 ;
V_4 &= ~ V_210 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_165 = V_257 ;
F_8 ( V_2 -> V_19 , L_71 , V_197 , V_2 -> V_165 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
const struct V_265 * V_199 )
{
switch ( V_199 -> type ) {
case V_266 :
F_128 ( V_2 ) ;
break;
case V_267 :
F_133 ( V_2 ) ;
break;
case V_268 :
F_137 ( V_2 ) ;
break;
case V_269 :
F_138 ( V_2 ) ;
break;
case V_270 :
F_139 ( V_2 , V_199 -> V_271 ) ;
break;
case V_272 :
F_8 ( V_2 -> V_19 , L_72 ) ;
break;
case V_273 :
F_8 ( V_2 -> V_19 , L_73 ) ;
break;
case V_274 :
F_8 ( V_2 -> V_19 , L_74 ) ;
break;
case V_275 :
F_8 ( V_2 -> V_19 , L_75 ) ;
break;
case V_276 :
F_8 ( V_2 -> V_19 , L_76 ) ;
break;
default:
F_19 ( V_2 -> V_19 , L_77 , V_199 -> type ) ;
}
}
static void F_141 ( struct V_1 * V_2 ,
const union V_277 * V_199 )
{
if ( V_199 -> type . V_278 == 0 ) {
return F_121 ( V_2 , & V_199 -> V_279 ) ;
}
switch ( V_199 -> type . type ) {
case V_280 :
F_140 ( V_2 , & V_199 -> V_281 ) ;
break;
default:
F_32 ( V_2 -> V_19 , L_78 , V_199 -> V_282 ) ;
}
}
static T_7 F_142 ( struct V_1 * V_2 , T_1 V_283 )
{
struct V_284 * V_285 ;
int V_286 ;
T_1 V_200 ;
V_200 = F_2 ( V_2 -> V_5 , F_143 ( V_283 ) ) ;
V_200 &= V_287 ;
if ( ! V_200 )
return V_288 ;
V_285 = V_2 -> V_289 [ V_283 ] ;
V_286 = V_200 ;
while ( V_286 > 0 ) {
union V_277 V_199 ;
V_199 . V_282 = * ( T_1 * ) ( V_285 -> V_283 + V_285 -> V_290 ) ;
F_141 ( V_2 , & V_199 ) ;
V_285 -> V_290 = ( V_285 -> V_290 + 4 ) % V_291 ;
V_286 -= 4 ;
F_3 ( V_2 -> V_5 , F_143 ( V_283 ) , 4 ) ;
}
return V_292 ;
}
static T_7 F_144 ( int V_293 , void * V_294 )
{
struct V_1 * V_2 = V_294 ;
int V_146 ;
T_7 V_99 = V_288 ;
F_21 ( & V_2 -> V_60 ) ;
for ( V_146 = 0 ; V_146 < V_2 -> V_295 ; V_146 ++ ) {
T_7 V_46 ;
V_46 = F_142 ( V_2 , V_146 ) ;
if ( V_46 == V_292 )
V_99 = V_46 ;
}
F_20 ( & V_2 -> V_60 ) ;
return V_99 ;
}
int T_6 F_145 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_99 ;
int V_293 ;
V_2 -> V_296 = F_31 ( V_2 -> V_19 , sizeof( * V_2 -> V_296 ) ,
& V_2 -> V_297 , V_84 ) ;
if ( ! V_2 -> V_296 ) {
F_32 ( V_2 -> V_19 , L_79 ) ;
V_99 = - V_85 ;
goto V_184;
}
V_2 -> V_298 = F_31 ( V_2 -> V_19 , sizeof( * V_2 -> V_298 ) ,
& V_2 -> V_299 , V_84 ) ;
if ( ! V_2 -> V_298 ) {
F_32 ( V_2 -> V_19 , L_80 ) ;
V_99 = - V_85 ;
goto V_189;
}
V_2 -> V_300 = F_69 ( sizeof( * V_2 -> V_300 ) * 2 ,
V_84 ) ;
if ( ! V_2 -> V_300 ) {
F_32 ( V_2 -> V_19 , L_81 ) ;
V_99 = - V_85 ;
goto V_301;
}
V_2 -> V_302 = F_31 ( V_2 -> V_19 ,
512 , & V_2 -> V_303 , V_84 ) ;
if ( ! V_2 -> V_302 ) {
F_32 ( V_2 -> V_19 , L_82 ) ;
V_99 = - V_85 ;
goto V_304;
}
F_146 ( & V_2 -> V_56 . V_19 , L_83 ) ;
V_2 -> V_56 . V_191 = & V_305 ;
V_2 -> V_56 . V_306 = V_245 ;
V_2 -> V_56 . V_166 = V_232 ;
V_2 -> V_56 . V_19 . V_307 = V_2 -> V_19 ;
V_2 -> V_56 . V_308 = true ;
F_147 ( & V_2 -> V_56 . V_19 , V_2 -> V_19 -> V_309 ) ;
V_2 -> V_56 . V_19 . V_310 = V_2 -> V_19 -> V_310 ;
V_2 -> V_56 . V_19 . V_311 = V_2 -> V_19 -> V_311 ;
V_2 -> V_56 . V_19 . V_312 = F_114 ;
V_2 -> V_56 . V_43 = L_84 ;
V_99 = F_111 ( V_2 ) ;
if ( V_99 )
goto V_313;
V_293 = F_148 ( F_149 ( V_2 -> V_19 ) , 0 ) ;
V_99 = F_150 ( V_293 , F_144 , V_314 ,
L_85 , V_2 ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_86 ,
V_293 , V_99 ) ;
goto V_315;
}
V_4 = ( V_316 |
V_317 |
V_318 |
V_319 |
V_320 |
V_321 |
V_322 |
V_323 |
V_324 ) ;
F_3 ( V_2 -> V_5 , V_325 , V_4 ) ;
V_99 = F_151 ( & V_2 -> V_56 . V_19 ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_87 ) ;
F_152 ( & V_2 -> V_56 . V_19 ) ;
goto V_326;
}
V_99 = F_153 ( V_2 -> V_19 , & V_2 -> V_56 ) ;
if ( V_99 ) {
F_32 ( V_2 -> V_19 , L_88 ) ;
goto V_327;
}
return 0 ;
V_327:
F_154 ( & V_2 -> V_56 . V_19 ) ;
V_326:
F_3 ( V_2 -> V_5 , V_325 , 0x00 ) ;
F_155 ( V_293 , V_2 ) ;
V_315:
F_113 ( V_2 ) ;
V_313:
F_34 ( V_2 -> V_19 , 512 , V_2 -> V_302 ,
V_2 -> V_303 ) ;
V_304:
F_72 ( V_2 -> V_300 ) ;
V_301:
F_34 ( V_2 -> V_19 , sizeof( * V_2 -> V_298 ) ,
V_2 -> V_298 , V_2 -> V_299 ) ;
V_189:
F_34 ( V_2 -> V_19 , sizeof( * V_2 -> V_296 ) ,
V_2 -> V_296 , V_2 -> V_297 ) ;
V_184:
return V_99 ;
}
void F_156 ( struct V_1 * V_2 )
{
int V_293 ;
F_157 ( & V_2 -> V_56 ) ;
V_293 = F_148 ( F_149 ( V_2 -> V_19 ) , 0 ) ;
F_3 ( V_2 -> V_5 , V_325 , 0x00 ) ;
F_155 ( V_293 , V_2 ) ;
F_113 ( V_2 ) ;
F_34 ( V_2 -> V_19 , 512 , V_2 -> V_302 ,
V_2 -> V_303 ) ;
F_72 ( V_2 -> V_300 ) ;
F_34 ( V_2 -> V_19 , sizeof( * V_2 -> V_298 ) ,
V_2 -> V_298 , V_2 -> V_299 ) ;
F_34 ( V_2 -> V_19 , sizeof( * V_2 -> V_296 ) ,
V_2 -> V_296 , V_2 -> V_297 ) ;
F_154 ( & V_2 -> V_56 . V_19 ) ;
}
