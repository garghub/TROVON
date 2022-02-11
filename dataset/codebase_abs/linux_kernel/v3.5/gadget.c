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
if ( F_12 ( V_32 -> V_40 . V_41 )
|| F_13 ( V_32 -> V_40 . V_41 ) )
V_36 = 3 ;
V_37 = V_36 * ( V_32 -> V_40 . V_42 + V_24 ) ;
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
F_13 ( V_32 -> V_40 . V_41 ) )
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
V_45 -> V_48 . V_61 ( & V_32 -> V_40 , & V_45 -> V_48 ) ;
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
int F_23 ( struct V_1 * V_2 , int V_62 , T_1 V_72 )
{
T_1 V_73 = 500 ;
T_1 V_4 ;
F_3 ( V_2 -> V_5 , V_74 , V_72 ) ;
F_3 ( V_2 -> V_5 , V_75 , V_62 | V_76 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_75 ) ;
if ( ! ( V_4 & V_76 ) ) {
F_8 ( V_2 -> V_19 , L_14 ,
F_24 ( V_4 ) ) ;
return 0 ;
}
V_73 -- ;
if ( ! V_73 )
return - V_20 ;
F_7 ( 1 ) ;
} while ( 1 );
}
int F_25 ( struct V_1 * V_2 , unsigned V_77 ,
unsigned V_62 , struct V_78 * V_79 )
{
struct V_31 * V_32 = V_2 -> V_33 [ V_77 ] ;
T_1 V_73 = 500 ;
T_1 V_4 ;
F_8 ( V_2 -> V_19 , L_15 ,
V_32 -> V_43 ,
F_22 ( V_62 ) , V_79 -> V_80 ,
V_79 -> V_81 , V_79 -> V_82 ) ;
F_3 ( V_2 -> V_5 , F_26 ( V_77 ) , V_79 -> V_80 ) ;
F_3 ( V_2 -> V_5 , F_27 ( V_77 ) , V_79 -> V_81 ) ;
F_3 ( V_2 -> V_5 , F_28 ( V_77 ) , V_79 -> V_82 ) ;
F_3 ( V_2 -> V_5 , F_29 ( V_77 ) , V_62 | V_83 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , F_29 ( V_77 ) ) ;
if ( ! ( V_4 & V_83 ) ) {
F_8 ( V_2 -> V_19 , L_14 ,
F_30 ( V_4 ) ) ;
return 0 ;
}
V_73 -- ;
if ( ! V_73 )
return - V_20 ;
F_7 ( 1 ) ;
} while ( 1 );
}
static T_3 F_31 ( struct V_31 * V_32 ,
struct V_84 * V_54 )
{
T_1 V_85 = ( char * ) V_54 - ( char * ) V_32 -> V_86 ;
return V_32 -> V_87 + V_85 ;
}
static int F_32 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
if ( V_32 -> V_86 )
return 0 ;
if ( V_32 -> V_35 == 0 || V_32 -> V_35 == 1 )
return 0 ;
V_32 -> V_86 = F_33 ( V_2 -> V_19 ,
sizeof( struct V_84 ) * V_52 ,
& V_32 -> V_87 , V_88 ) ;
if ( ! V_32 -> V_86 ) {
F_34 ( V_32 -> V_2 -> V_19 , L_16 ,
V_32 -> V_43 ) ;
return - V_89 ;
}
return 0 ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
F_36 ( V_2 -> V_19 , sizeof( struct V_84 ) * V_52 ,
V_32 -> V_86 , V_32 -> V_87 ) ;
V_32 -> V_86 = NULL ;
V_32 -> V_87 = 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_78 V_79 ;
T_1 V_62 ;
memset ( & V_79 , 0x00 , sizeof( V_79 ) ) ;
if ( V_32 -> V_35 != 1 ) {
V_62 = V_63 ;
if ( V_32 -> V_35 > 1 ) {
if ( V_2 -> V_90 )
return 0 ;
V_2 -> V_90 = true ;
V_62 |= F_38 ( 2 ) ;
}
return F_25 ( V_2 , 0 , V_62 , & V_79 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_31 * V_32 ,
const struct V_91 * V_41 ,
const struct V_92 * V_93 )
{
struct V_78 V_79 ;
memset ( & V_79 , 0x00 , sizeof( V_79 ) ) ;
V_79 . V_80 = F_40 ( F_41 ( V_41 ) )
| F_42 ( F_43 ( V_41 ) )
| F_44 ( V_32 -> V_40 . V_94 ) ;
V_79 . V_81 = V_95
| V_96 ;
if ( F_45 ( V_93 ) && F_12 ( V_41 ) ) {
V_79 . V_81 |= V_97
| V_98 ;
V_32 -> V_99 = true ;
}
if ( F_13 ( V_41 ) )
V_79 . V_81 |= V_100 ;
V_79 . V_81 |= F_46 ( V_32 -> V_35 ) ;
if ( V_32 -> V_57 )
V_79 . V_80 |= F_47 ( V_32 -> V_35 >> 1 ) ;
if ( V_41 -> V_101 ) {
V_79 . V_81 |= F_48 ( V_41 -> V_101 - 1 ) ;
V_32 -> V_102 = 1 << ( V_41 -> V_101 - 1 ) ;
}
return F_25 ( V_2 , V_32 -> V_35 ,
V_71 , & V_79 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_78 V_79 ;
memset ( & V_79 , 0x00 , sizeof( V_79 ) ) ;
V_79 . V_80 = F_50 ( 1 ) ;
return F_25 ( V_2 , V_32 -> V_35 ,
V_70 , & V_79 ) ;
}
static int F_51 ( struct V_31 * V_32 ,
const struct V_91 * V_41 ,
const struct V_92 * V_93 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_4 ;
int V_103 = - V_89 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
V_103 = F_37 ( V_2 , V_32 ) ;
if ( V_103 )
return V_103 ;
}
V_103 = F_39 ( V_2 , V_32 , V_41 , V_93 ) ;
if ( V_103 )
return V_103 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
struct V_84 * V_104 ;
struct V_84 * V_105 ;
V_103 = F_49 ( V_2 , V_32 ) ;
if ( V_103 )
return V_103 ;
V_32 -> V_40 . V_41 = V_41 ;
V_32 -> V_93 = V_93 ;
V_32 -> type = F_41 ( V_41 ) ;
V_32 -> V_38 |= V_39 ;
V_4 = F_2 ( V_2 -> V_5 , V_106 ) ;
V_4 |= F_52 ( V_32 -> V_35 ) ;
F_3 ( V_2 -> V_5 , V_106 , V_4 ) ;
if ( ! F_13 ( V_41 ) )
return 0 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_104 = & V_32 -> V_86 [ 0 ] ;
V_105 = & V_32 -> V_86 [ V_52 - 1 ] ;
V_105 -> V_107 = F_53 ( F_31 ( V_32 , V_104 ) ) ;
V_105 -> V_108 = F_54 ( F_31 ( V_32 , V_104 ) ) ;
V_105 -> V_109 |= V_110 ;
V_105 -> V_109 |= V_111 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_44 * V_45 ;
if ( ! F_56 ( & V_32 -> V_112 ) )
F_57 ( V_2 , V_32 -> V_35 ) ;
while ( ! F_56 ( & V_32 -> V_113 ) ) {
V_45 = F_58 ( & V_32 -> V_113 ) ;
F_16 ( V_32 , V_45 , - V_114 ) ;
}
}
static int F_59 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_4 ;
F_55 ( V_2 , V_32 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_106 ) ;
V_4 &= ~ F_52 ( V_32 -> V_35 ) ;
F_3 ( V_2 -> V_5 , V_106 , V_4 ) ;
V_32 -> V_99 = false ;
V_32 -> V_40 . V_41 = NULL ;
V_32 -> V_93 = NULL ;
V_32 -> type = 0 ;
V_32 -> V_38 = 0 ;
return 0 ;
}
static int F_60 ( struct V_115 * V_77 ,
const struct V_91 * V_41 )
{
return - V_13 ;
}
static int F_61 ( struct V_115 * V_77 )
{
return - V_13 ;
}
static int F_62 ( struct V_115 * V_77 ,
const struct V_91 * V_41 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
unsigned long V_38 ;
int V_103 ;
if ( ! V_77 || ! V_41 || V_41 -> V_116 != V_117 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
if ( ! V_41 -> V_118 ) {
F_63 ( L_18 ) ;
return - V_13 ;
}
V_32 = F_64 ( V_77 ) ;
V_2 = V_32 -> V_2 ;
switch ( F_41 ( V_41 ) ) {
case V_119 :
F_65 ( V_32 -> V_43 , L_19 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_120 :
F_65 ( V_32 -> V_43 , L_20 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_121 :
F_65 ( V_32 -> V_43 , L_21 , sizeof( V_32 -> V_43 ) ) ;
break;
case V_122 :
F_65 ( V_32 -> V_43 , L_22 , sizeof( V_32 -> V_43 ) ) ;
break;
default:
F_34 ( V_2 -> V_19 , L_23 ) ;
}
if ( V_32 -> V_38 & V_39 ) {
F_66 ( V_2 -> V_19 , true , L_24 ,
V_32 -> V_43 ) ;
return 0 ;
}
F_8 ( V_2 -> V_19 , L_25 , V_32 -> V_43 ) ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_103 = F_51 ( V_32 , V_41 , V_77 -> V_93 ) ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static int F_69 ( struct V_115 * V_77 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
unsigned long V_38 ;
int V_103 ;
if ( ! V_77 ) {
F_63 ( L_17 ) ;
return - V_13 ;
}
V_32 = F_64 ( V_77 ) ;
V_2 = V_32 -> V_2 ;
if ( ! ( V_32 -> V_38 & V_39 ) ) {
F_66 ( V_2 -> V_19 , true , L_26 ,
V_32 -> V_43 ) ;
return 0 ;
}
snprintf ( V_32 -> V_43 , sizeof( V_32 -> V_43 ) , L_27 ,
V_32 -> V_35 >> 1 ,
( V_32 -> V_35 & 1 ) ? L_28 : L_29 ) ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_103 = F_59 ( V_32 ) ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static struct V_123 * F_70 ( struct V_115 * V_77 ,
T_4 V_124 )
{
struct V_44 * V_45 ;
struct V_31 * V_32 = F_64 ( V_77 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
V_45 = F_71 ( sizeof( * V_45 ) , V_124 ) ;
if ( ! V_45 ) {
F_34 ( V_2 -> V_19 , L_30 ) ;
return NULL ;
}
V_45 -> V_125 = V_32 -> V_35 ;
V_45 -> V_32 = V_32 ;
return & V_45 -> V_48 ;
}
static void F_72 ( struct V_115 * V_77 ,
struct V_123 * V_48 )
{
struct V_44 * V_45 = F_73 ( V_48 ) ;
F_74 ( V_45 ) ;
}
static void F_75 ( struct V_31 * V_32 ,
struct V_44 * V_45 , T_3 V_126 ,
unsigned V_59 , unsigned V_127 , unsigned V_128 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_84 * V_54 ;
unsigned int V_129 ;
F_8 ( V_2 -> V_19 , L_31 ,
V_32 -> V_43 , V_45 , ( unsigned long long ) V_126 ,
V_59 , V_127 ? L_32 : L_33 ,
V_128 ? L_34 : L_33 ) ;
V_54 = & V_32 -> V_86 [ V_32 -> V_130 & V_51 ] ;
V_129 = V_32 -> V_130 ;
V_32 -> V_130 ++ ;
if ( ( ( V_129 & V_51 ) == V_52 - 1 ) &&
F_13 ( V_32 -> V_40 . V_41 ) )
return;
if ( ! V_45 -> V_54 ) {
F_76 ( V_45 ) ;
V_45 -> V_54 = V_54 ;
V_45 -> V_131 = F_31 ( V_32 , V_54 ) ;
}
V_54 -> V_132 = F_77 ( V_59 ) ;
V_54 -> V_107 = F_53 ( V_126 ) ;
V_54 -> V_108 = F_54 ( V_126 ) ;
switch ( F_41 ( V_32 -> V_40 . V_41 ) ) {
case V_119 :
V_54 -> V_109 = V_133 ;
break;
case V_120 :
V_54 -> V_109 = V_134 ;
if ( ! ( V_129 % ( V_52 / 4 ) ) )
V_54 -> V_109 |= V_135 ;
break;
case V_121 :
case V_122 :
V_54 -> V_109 = V_136 ;
break;
default:
F_78 () ;
}
if ( F_13 ( V_32 -> V_40 . V_41 ) ) {
V_54 -> V_109 |= V_137 ;
V_54 -> V_109 |= V_138 ;
} else {
if ( V_128 )
V_54 -> V_109 |= V_139 ;
if ( V_127 )
V_54 -> V_109 |= V_140 ;
}
if ( F_12 ( V_32 -> V_40 . V_41 ) && V_32 -> V_99 )
V_54 -> V_109 |= F_79 ( V_45 -> V_48 . V_141 ) ;
V_54 -> V_109 |= V_111 ;
}
static void F_80 ( struct V_31 * V_32 , bool V_142 )
{
struct V_44 * V_45 , * V_143 ;
T_1 V_144 ;
T_1 V_145 ;
unsigned int V_146 = 0 ;
F_81 ( V_52 ) ;
V_144 = ( V_32 -> V_50 - V_32 -> V_130 ) & V_51 ;
if ( ! F_13 ( V_32 -> V_40 . V_41 ) ) {
V_145 = V_52 - ( V_32 -> V_130 & V_51 ) ;
if ( V_144 > V_145 )
V_144 = V_145 ;
}
if ( ! V_144 ) {
if ( ! V_142 )
return;
V_144 = V_52 ;
if ( F_13 ( V_32 -> V_40 . V_41 ) ) {
V_32 -> V_50 = 1 ;
V_32 -> V_130 = 1 ;
} else {
V_32 -> V_50 = 0 ;
V_32 -> V_130 = 0 ;
}
}
if ( ( V_144 <= 1 ) && F_13 ( V_32 -> V_40 . V_41 ) )
return;
F_82 (req, n, &dep->request_list, list) {
unsigned V_59 ;
T_3 V_126 ;
if ( V_45 -> V_48 . V_49 > 0 ) {
struct V_123 * V_48 = & V_45 -> V_48 ;
struct V_147 * V_148 = V_48 -> V_148 ;
struct V_147 * V_149 ;
int V_150 ;
F_83 (sg, s, request->num_mapped_sgs, i) {
unsigned V_128 = true ;
V_59 = F_84 ( V_149 ) ;
V_126 = F_85 ( V_149 ) ;
if ( V_150 == ( V_48 -> V_49 - 1 ) ||
F_86 ( V_149 ) ) {
V_146 = true ;
V_128 = false ;
}
V_144 -- ;
if ( ! V_144 )
V_146 = true ;
if ( V_146 )
V_128 = false ;
F_75 ( V_32 , V_45 , V_126 , V_59 ,
V_146 , V_128 ) ;
if ( V_146 )
break;
}
} else {
V_126 = V_45 -> V_48 . V_126 ;
V_59 = V_45 -> V_48 . V_59 ;
V_144 -- ;
if ( ! V_144 )
V_146 = 1 ;
if ( F_87 ( & V_45 -> V_53 , & V_32 -> V_113 ) )
V_146 = 1 ;
F_75 ( V_32 , V_45 , V_126 , V_59 ,
V_146 , false ) ;
if ( V_146 )
break;
}
}
}
static int F_88 ( struct V_31 * V_32 , T_5 V_151 ,
int V_152 )
{
struct V_78 V_79 ;
struct V_44 * V_45 ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_103 ;
T_1 V_62 ;
if ( V_152 && ( V_32 -> V_38 & V_153 ) ) {
F_8 ( V_2 -> V_19 , L_35 , V_32 -> V_43 ) ;
return - V_154 ;
}
V_32 -> V_38 &= ~ V_155 ;
if ( V_152 ) {
if ( F_56 ( & V_32 -> V_112 ) )
F_80 ( V_32 , V_152 ) ;
V_45 = F_58 ( & V_32 -> V_112 ) ;
} else {
F_80 ( V_32 , V_152 ) ;
V_45 = F_58 ( & V_32 -> V_112 ) ;
}
if ( ! V_45 ) {
V_32 -> V_38 |= V_155 ;
return 0 ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_80 = F_54 ( V_45 -> V_131 ) ;
V_79 . V_81 = F_53 ( V_45 -> V_131 ) ;
if ( V_152 )
V_62 = V_66 ;
else
V_62 = V_65 ;
V_62 |= F_38 ( V_151 ) ;
V_103 = F_25 ( V_2 , V_32 -> V_35 , V_62 , & V_79 ) ;
if ( V_103 < 0 ) {
F_19 ( V_2 -> V_19 , L_36 ) ;
F_18 ( & V_2 -> V_56 , & V_45 -> V_48 ,
V_45 -> V_57 ) ;
F_17 ( & V_45 -> V_53 ) ;
return V_103 ;
}
V_32 -> V_38 |= V_153 ;
if ( V_152 ) {
V_32 -> V_156 = F_89 ( V_2 ,
V_32 -> V_35 ) ;
F_90 ( ! V_32 -> V_156 ) ;
}
return 0 ;
}
static int F_91 ( struct V_31 * V_32 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
int V_103 ;
V_45 -> V_48 . V_58 = 0 ;
V_45 -> V_48 . V_46 = - V_55 ;
V_45 -> V_57 = V_32 -> V_57 ;
V_45 -> V_125 = V_32 -> V_35 ;
V_103 = F_92 ( & V_2 -> V_56 , & V_45 -> V_48 ,
V_32 -> V_57 ) ;
if ( V_103 )
return V_103 ;
F_93 ( & V_45 -> V_53 , & V_32 -> V_113 ) ;
if ( F_13 ( V_32 -> V_40 . V_41 ) && ( V_32 -> V_38 & V_153 ) )
V_32 -> V_38 |= V_155 ;
if ( V_32 -> V_38 & V_155 ) {
int V_103 ;
int V_157 = 1 ;
T_2 V_158 = V_32 -> V_156 ;
if ( F_13 ( V_32 -> V_40 . V_41 ) &&
( V_32 -> V_38 & V_153 ) ) {
V_157 = 0 ;
F_90 ( ! V_158 ) ;
} else {
V_158 = 0 ;
}
V_103 = F_88 ( V_32 , V_158 , V_157 ) ;
if ( V_103 && V_103 != - V_154 ) {
struct V_1 * V_2 = V_32 -> V_2 ;
F_19 ( V_2 -> V_19 , L_37 ,
V_32 -> V_43 ) ;
}
} ;
return 0 ;
}
static int F_94 ( struct V_115 * V_77 , struct V_123 * V_48 ,
T_4 V_124 )
{
struct V_44 * V_45 = F_73 ( V_48 ) ;
struct V_31 * V_32 = F_64 ( V_77 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_103 ;
if ( ! V_32 -> V_40 . V_41 ) {
F_19 ( V_2 -> V_19 , L_38 ,
V_48 , V_77 -> V_43 ) ;
return - V_114 ;
}
F_8 ( V_2 -> V_19 , L_39 ,
V_48 , V_77 -> V_43 , V_48 -> V_59 ) ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_103 = F_91 ( V_32 , V_45 ) ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static int F_95 ( struct V_115 * V_77 ,
struct V_123 * V_48 )
{
struct V_44 * V_45 = F_73 ( V_48 ) ;
struct V_44 * V_159 = NULL ;
struct V_31 * V_32 = F_64 ( V_77 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_103 = 0 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
F_96 (r, &dep->request_list, list) {
if ( V_159 == V_45 )
break;
}
if ( V_159 != V_45 ) {
F_96 (r, &dep->req_queued, list) {
if ( V_159 == V_45 )
break;
}
if ( V_159 == V_45 ) {
F_57 ( V_2 , V_32 -> V_35 ) ;
goto V_160;
}
F_34 ( V_2 -> V_19 , L_40 ,
V_48 , V_77 -> V_43 ) ;
V_103 = - V_13 ;
goto V_161;
}
V_160:
F_16 ( V_32 , V_45 , - V_162 ) ;
V_161:
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
int F_97 ( struct V_31 * V_32 , int V_163 )
{
struct V_78 V_79 ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_103 ;
memset ( & V_79 , 0x00 , sizeof( V_79 ) ) ;
if ( V_163 ) {
if ( V_32 -> V_35 == 0 || V_32 -> V_35 == 1 ) {
V_2 -> V_164 = V_165 ;
}
V_103 = F_25 ( V_2 , V_32 -> V_35 ,
V_68 , & V_79 ) ;
if ( V_103 )
F_34 ( V_2 -> V_19 , L_41 ,
V_163 ? L_42 : L_43 ,
V_32 -> V_43 ) ;
else
V_32 -> V_38 |= V_166 ;
} else {
if ( V_32 -> V_38 & V_167 )
return 0 ;
V_103 = F_25 ( V_2 , V_32 -> V_35 ,
V_67 , & V_79 ) ;
if ( V_103 )
F_34 ( V_2 -> V_19 , L_41 ,
V_163 ? L_42 : L_43 ,
V_32 -> V_43 ) ;
else
V_32 -> V_38 &= ~ V_166 ;
}
return V_103 ;
}
static int F_98 ( struct V_115 * V_77 , int V_163 )
{
struct V_31 * V_32 = F_64 ( V_77 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
int V_103 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
if ( F_13 ( V_32 -> V_40 . V_41 ) ) {
F_34 ( V_2 -> V_19 , L_44 , V_32 -> V_43 ) ;
V_103 = - V_13 ;
goto V_168;
}
V_103 = F_97 ( V_32 , V_163 ) ;
V_168:
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static int F_99 ( struct V_115 * V_77 )
{
struct V_31 * V_32 = F_64 ( V_77 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
unsigned long V_38 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_32 -> V_38 |= V_167 ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return F_98 ( V_77 , 1 ) ;
}
static int F_100 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
return F_102 ( V_4 ) ;
}
static int F_103 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
unsigned long V_73 ;
unsigned long V_38 ;
T_1 V_4 ;
int V_103 = 0 ;
T_2 V_171 ;
T_2 V_172 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
V_172 = V_4 & V_173 ;
if ( V_172 == V_174 ) {
F_19 ( V_2 -> V_19 , L_45 ) ;
V_103 = - V_13 ;
goto V_168;
}
V_171 = F_6 ( V_4 ) ;
switch ( V_171 ) {
case V_175 :
case V_176 :
break;
default:
F_19 ( V_2 -> V_19 , L_46 ,
V_171 ) ;
V_103 = - V_13 ;
goto V_168;
}
V_103 = F_4 ( V_2 , V_177 ) ;
if ( V_103 < 0 ) {
F_34 ( V_2 -> V_19 , L_47 ) ;
goto V_168;
}
V_4 &= ~ V_17 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_73 = V_178 + F_104 ( 100 ) ;
while ( ! F_105 ( V_178 , V_73 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( F_6 ( V_4 ) == V_179 )
break;
}
if ( F_6 ( V_4 ) != V_179 ) {
F_34 ( V_2 -> V_19 , L_48 ) ;
V_103 = - V_13 ;
}
V_168:
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static int F_106 ( struct V_169 * V_170 ,
int V_180 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
unsigned long V_38 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
V_2 -> V_180 = ! ! V_180 ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 , int V_181 )
{
T_1 V_4 ;
T_1 V_73 = 500 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_181 ) {
V_4 &= ~ V_182 ;
V_4 |= ( V_183
| V_184 ) ;
} else {
V_4 &= ~ V_183 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( V_181 ) {
if ( ! ( V_4 & V_185 ) )
break;
} else {
if ( V_4 & V_185 )
break;
}
V_73 -- ;
if ( ! V_73 )
break;
F_7 ( 1 ) ;
} while ( 1 );
F_8 ( V_2 -> V_19 , L_49 ,
V_2 -> V_186
? V_2 -> V_186 -> V_187 : L_50 ,
V_181 ? L_51 : L_52 ) ;
}
static int F_108 ( struct V_169 * V_170 , int V_181 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
unsigned long V_38 ;
V_181 = ! ! V_181 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
F_107 ( V_2 , V_181 ) ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static int F_109 ( struct V_169 * V_170 ,
struct V_188 * V_189 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
struct V_31 * V_32 ;
unsigned long V_38 ;
int V_103 = 0 ;
T_1 V_4 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
if ( V_2 -> V_186 ) {
F_34 ( V_2 -> V_19 , L_53 ,
V_2 -> V_56 . V_43 ,
V_2 -> V_186 -> V_189 . V_43 ) ;
V_103 = - V_154 ;
goto V_190;
}
V_2 -> V_186 = V_189 ;
V_2 -> V_56 . V_19 . V_189 = & V_189 -> V_189 ;
V_4 = F_2 ( V_2 -> V_5 , V_191 ) ;
V_4 &= ~ ( V_192 ) ;
if ( V_2 -> V_193 < V_194 )
V_4 |= V_195 ;
else
V_4 |= V_2 -> V_196 ;
F_3 ( V_2 -> V_5 , V_191 , V_4 ) ;
V_2 -> V_90 = false ;
V_197 . V_118 = F_110 ( 512 ) ;
V_32 = V_2 -> V_33 [ 0 ] ;
V_103 = F_51 ( V_32 , & V_197 , NULL ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
goto V_190;
}
V_32 = V_2 -> V_33 [ 1 ] ;
V_103 = F_51 ( V_32 , & V_197 , NULL ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
goto V_198;
}
V_2 -> V_164 = V_165 ;
F_111 ( V_2 ) ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
V_198:
F_59 ( V_2 -> V_33 [ 0 ] ) ;
V_190:
F_68 ( & V_2 -> V_60 , V_38 ) ;
return V_103 ;
}
static int F_112 ( struct V_169 * V_170 ,
struct V_188 * V_189 )
{
struct V_1 * V_2 = F_101 ( V_170 ) ;
unsigned long V_38 ;
F_67 ( & V_2 -> V_60 , V_38 ) ;
F_59 ( V_2 -> V_33 [ 0 ] ) ;
F_59 ( V_2 -> V_33 [ 1 ] ) ;
V_2 -> V_186 = NULL ;
V_2 -> V_56 . V_19 . V_189 = NULL ;
F_68 ( & V_2 -> V_60 , V_38 ) ;
return 0 ;
}
static int T_6 F_113 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_2 V_125 ;
F_114 ( & V_2 -> V_56 . V_199 ) ;
for ( V_125 = 0 ; V_125 < V_30 ; V_125 ++ ) {
V_32 = F_71 ( sizeof( * V_32 ) , V_88 ) ;
if ( ! V_32 ) {
F_34 ( V_2 -> V_19 , L_55 ,
V_125 ) ;
return - V_89 ;
}
V_32 -> V_2 = V_2 ;
V_32 -> V_35 = V_125 ;
V_2 -> V_33 [ V_125 ] = V_32 ;
snprintf ( V_32 -> V_43 , sizeof( V_32 -> V_43 ) , L_27 , V_125 >> 1 ,
( V_125 & 1 ) ? L_28 : L_29 ) ;
V_32 -> V_40 . V_43 = V_32 -> V_43 ;
V_32 -> V_57 = ( V_125 & 1 ) ;
if ( V_125 == 0 || V_125 == 1 ) {
V_32 -> V_40 . V_42 = 512 ;
V_32 -> V_40 . V_200 = & V_201 ;
if ( ! V_125 )
V_2 -> V_56 . V_202 = & V_32 -> V_40 ;
} else {
int V_103 ;
V_32 -> V_40 . V_42 = 1024 ;
V_32 -> V_40 . V_203 = 15 ;
V_32 -> V_40 . V_200 = & V_204 ;
F_93 ( & V_32 -> V_40 . V_199 ,
& V_2 -> V_56 . V_199 ) ;
V_103 = F_32 ( V_32 ) ;
if ( V_103 )
return V_103 ;
}
F_114 ( & V_32 -> V_113 ) ;
F_114 ( & V_32 -> V_112 ) ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_2 V_125 ;
for ( V_125 = 0 ; V_125 < V_30 ; V_125 ++ ) {
V_32 = V_2 -> V_33 [ V_125 ] ;
F_35 ( V_32 ) ;
if ( V_125 != 0 && V_125 != 1 )
F_17 ( & V_32 -> V_40 . V_199 ) ;
F_74 ( V_32 ) ;
}
}
static void F_116 ( struct V_205 * V_19 )
{
F_19 ( V_19 , L_56 , V_206 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_31 * V_32 ,
const struct V_207 * V_208 , int V_46 )
{
struct V_44 * V_45 ;
struct V_84 * V_54 ;
unsigned int V_209 ;
unsigned int V_210 = 0 ;
do {
V_45 = F_58 ( & V_32 -> V_112 ) ;
if ( ! V_45 ) {
F_90 ( 1 ) ;
return 1 ;
}
V_54 = V_45 -> V_54 ;
if ( ( V_54 -> V_109 & V_111 ) && V_46 != - V_114 )
F_34 ( V_2 -> V_19 , L_57 ,
V_32 -> V_43 , V_45 -> V_54 ) ;
V_209 = V_54 -> V_132 & V_211 ;
if ( V_32 -> V_57 ) {
if ( V_209 ) {
F_34 ( V_2 -> V_19 , L_58 ,
V_32 -> V_43 ) ;
V_46 = - V_162 ;
}
} else {
if ( V_209 && ( V_208 -> V_46 & V_212 ) )
V_210 = 1 ;
}
V_45 -> V_48 . V_58 += V_45 -> V_48 . V_59 - V_209 ;
F_16 ( V_32 , V_45 , V_46 ) ;
if ( V_210 )
break;
if ( ( V_208 -> V_46 & V_213 ) &&
( V_54 -> V_109 & V_140 ) )
break;
if ( ( V_208 -> V_46 & V_214 ) &&
( V_54 -> V_109 & V_135 ) )
break;
} while ( 1 );
if ( ( V_208 -> V_46 & V_214 ) &&
( V_54 -> V_109 & V_135 ) )
return 0 ;
return 1 ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_31 * V_32 , const struct V_207 * V_208 ,
int V_152 )
{
unsigned V_46 = 0 ;
int V_215 ;
if ( V_208 -> V_46 & V_216 )
V_46 = - V_162 ;
V_215 = F_117 ( V_2 , V_32 , V_208 , V_46 ) ;
if ( V_215 )
V_32 -> V_38 &= ~ V_153 ;
if ( V_2 -> V_193 < V_217 ) {
T_1 V_4 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_30 ; V_150 ++ ) {
struct V_31 * V_32 = V_2 -> V_33 [ V_150 ] ;
if ( ! ( V_32 -> V_38 & V_39 ) )
continue;
if ( ! F_56 ( & V_32 -> V_112 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_218 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_218 = 0 ;
}
}
static void F_119 ( struct V_1 * V_2 ,
struct V_31 * V_32 , const struct V_207 * V_208 )
{
T_1 V_219 , V_220 ;
if ( F_56 ( & V_32 -> V_113 ) ) {
F_8 ( V_2 -> V_19 , L_59 ,
V_32 -> V_43 ) ;
return;
}
V_220 = ~ ( V_32 -> V_102 - 1 ) ;
V_219 = V_208 -> V_221 & V_220 ;
V_219 += V_32 -> V_102 * 4 ;
F_88 ( V_32 , V_219 , 1 ) ;
}
static void F_120 ( struct V_31 * V_32 ,
const struct V_207 * V_208 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_207 V_222 = * V_208 ;
V_222 . V_46 = V_213 ;
F_117 ( V_2 , V_32 , & V_222 , - V_114 ) ;
V_32 -> V_38 &= ~ V_153 ;
}
static void F_121 ( struct V_31 * V_32 ,
const struct V_207 * V_208 )
{
T_1 V_72 = V_208 -> V_221 ;
T_1 V_223 = ( V_72 >> 8 ) & ( ( 1 << 5 ) - 1 ) ;
switch ( V_223 ) {
case V_64 :
F_120 ( V_32 , V_208 ) ;
break;
case V_66 :
V_32 -> V_156 = V_72 & 0x7f ;
break;
default:
F_122 ( V_224 L_60 ,
V_206 , V_223 ) ;
break;
} ;
}
static void F_123 ( struct V_1 * V_2 ,
const struct V_207 * V_208 )
{
struct V_31 * V_32 ;
T_2 V_125 = V_208 -> V_225 ;
V_32 = V_2 -> V_33 [ V_125 ] ;
F_8 ( V_2 -> V_19 , L_61 , V_32 -> V_43 ,
F_124 ( V_208 -> V_226 ) ) ;
if ( V_125 == 0 || V_125 == 1 ) {
F_125 ( V_2 , V_208 ) ;
return;
}
switch ( V_208 -> V_226 ) {
case V_227 :
V_32 -> V_156 = 0 ;
if ( F_13 ( V_32 -> V_40 . V_41 ) ) {
F_19 ( V_2 -> V_19 , L_62 ,
V_32 -> V_43 ) ;
return;
}
F_118 ( V_2 , V_32 , V_208 , 1 ) ;
break;
case V_228 :
if ( ! F_13 ( V_32 -> V_40 . V_41 ) ) {
F_19 ( V_2 -> V_19 , L_63 ,
V_32 -> V_43 ) ;
return;
}
F_118 ( V_2 , V_32 , V_208 , 0 ) ;
break;
case V_229 :
if ( F_13 ( V_32 -> V_40 . V_41 ) ) {
F_119 ( V_2 , V_32 , V_208 ) ;
} else {
int V_103 ;
F_8 ( V_2 -> V_19 , L_64 ,
V_32 -> V_43 , V_208 -> V_46 &
V_230
? L_65
: L_66 ) ;
V_103 = F_88 ( V_32 , 0 , 1 ) ;
if ( ! V_103 || V_103 == - V_154 )
return;
F_19 ( V_2 -> V_19 , L_37 ,
V_32 -> V_43 ) ;
}
break;
case V_231 :
if ( ! F_12 ( V_32 -> V_40 . V_41 ) ) {
F_34 ( V_2 -> V_19 , L_67 ,
V_32 -> V_43 ) ;
return;
}
switch ( V_208 -> V_46 ) {
case V_232 :
F_8 ( V_2 -> V_19 , L_68 ,
V_208 -> V_221 ) ;
break;
case V_233 :
default:
F_19 ( V_2 -> V_19 , L_69 ) ;
}
break;
case V_234 :
F_19 ( V_2 -> V_19 , L_70 , V_32 -> V_43 ) ;
break;
case V_235 :
F_121 ( V_32 , V_208 ) ;
break;
}
}
static void F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_186 && V_2 -> V_186 -> V_236 ) {
F_20 ( & V_2 -> V_60 ) ;
V_2 -> V_186 -> V_236 ( & V_2 -> V_56 ) ;
F_21 ( & V_2 -> V_60 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , T_1 V_125 )
{
struct V_31 * V_32 ;
struct V_78 V_79 ;
T_1 V_62 ;
int V_103 ;
V_32 = V_2 -> V_33 [ V_125 ] ;
F_127 ( ! V_32 -> V_156 ) ;
if ( V_32 -> V_156 ) {
V_62 = V_64 ;
V_62 |= V_237 | V_238 ;
V_62 |= F_38 ( V_32 -> V_156 ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_103 = F_25 ( V_2 , V_32 -> V_35 , V_62 , & V_79 ) ;
F_90 ( V_103 ) ;
V_32 -> V_156 = 0 ;
}
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_125 ;
for ( V_125 = 2 ; V_125 < V_30 ; V_125 ++ ) {
struct V_31 * V_32 ;
V_32 = V_2 -> V_33 [ V_125 ] ;
if ( ! ( V_32 -> V_38 & V_39 ) )
continue;
F_55 ( V_2 , V_32 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
T_1 V_125 ;
for ( V_125 = 1 ; V_125 < V_30 ; V_125 ++ ) {
struct V_31 * V_32 ;
struct V_78 V_79 ;
int V_103 ;
V_32 = V_2 -> V_33 [ V_125 ] ;
if ( ! ( V_32 -> V_38 & V_166 ) )
continue;
V_32 -> V_38 &= ~ V_166 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_103 = F_25 ( V_2 , V_32 -> V_35 ,
V_67 , & V_79 ) ;
F_90 ( V_103 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_19 , L_56 , V_206 ) ;
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
F_128 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_90 = false ;
V_2 -> V_56 . V_172 = V_239 ;
V_2 -> V_240 = false ;
}
static void F_131 ( struct V_1 * V_2 , int V_241 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_132 ( 0 ) ) ;
if ( V_241 )
V_4 &= ~ V_242 ;
else
V_4 |= V_242 ;
F_3 ( V_2 -> V_5 , F_132 ( 0 ) , V_4 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_241 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_134 ( 0 ) ) ;
if ( V_241 )
V_4 &= ~ V_243 ;
else
V_4 |= V_243 ;
F_3 ( V_2 -> V_5 , F_134 ( 0 ) , V_4 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_8 ( V_2 -> V_19 , L_56 , V_206 ) ;
if ( V_2 -> V_193 < V_244 ) {
if ( V_2 -> V_240 )
F_130 ( V_2 ) ;
}
V_2 -> V_245 = V_246 ;
F_133 ( V_2 , true ) ;
F_131 ( V_2 , true ) ;
if ( V_2 -> V_56 . V_172 != V_239 )
F_126 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
V_4 &= ~ ( V_247 | V_248 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_249 = false ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_90 = false ;
V_4 = F_2 ( V_2 -> V_5 , V_191 ) ;
V_4 &= ~ ( V_250 ) ;
F_3 ( V_2 -> V_5 , V_191 , V_4 ) ;
}
static void F_136 ( struct V_1 * V_2 , T_1 V_172 )
{
T_1 V_4 ;
T_1 V_251 = V_252 ;
if ( V_172 != V_174 )
return;
if ( ! V_251 )
return;
V_4 = F_2 ( V_2 -> V_5 , V_253 ) ;
V_4 |= F_137 ( V_251 ) ;
F_3 ( V_2 -> V_5 , V_253 , V_4 ) ;
}
static void F_138 ( struct V_1 * V_2 , T_2 V_172 )
{
switch ( V_172 ) {
case V_254 :
F_133 ( V_2 , false ) ;
break;
case V_255 :
case V_256 :
case V_257 :
F_131 ( V_2 , false ) ;
break;
}
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_78 V_79 ;
struct V_31 * V_32 ;
int V_103 ;
T_1 V_4 ;
T_2 V_172 ;
F_8 ( V_2 -> V_19 , L_56 , V_206 ) ;
memset ( & V_79 , 0x00 , sizeof( V_79 ) ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
V_172 = V_4 & V_173 ;
V_2 -> V_172 = V_172 ;
F_136 ( V_2 , V_172 ) ;
switch ( V_172 ) {
case V_195 :
if ( V_2 -> V_193 < V_258 )
F_135 ( V_2 ) ;
V_197 . V_118 = F_110 ( 512 ) ;
V_2 -> V_56 . V_202 -> V_42 = 512 ;
V_2 -> V_56 . V_172 = V_254 ;
break;
case V_259 :
V_197 . V_118 = F_110 ( 64 ) ;
V_2 -> V_56 . V_202 -> V_42 = 64 ;
V_2 -> V_56 . V_172 = V_255 ;
break;
case V_260 :
case V_261 :
V_197 . V_118 = F_110 ( 64 ) ;
V_2 -> V_56 . V_202 -> V_42 = 64 ;
V_2 -> V_56 . V_172 = V_256 ;
break;
case V_262 :
V_197 . V_118 = F_110 ( 8 ) ;
V_2 -> V_56 . V_202 -> V_42 = 8 ;
V_2 -> V_56 . V_172 = V_257 ;
break;
}
F_138 ( V_2 , V_2 -> V_56 . V_172 ) ;
V_32 = V_2 -> V_33 [ 0 ] ;
V_103 = F_51 ( V_32 , & V_197 , NULL ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
return;
}
V_32 = V_2 -> V_33 [ 1 ] ;
V_103 = F_51 ( V_32 , & V_197 , NULL ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_54 , V_32 -> V_43 ) ;
return;
}
}
static void F_140 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_19 , L_56 , V_206 ) ;
V_2 -> V_186 -> V_263 ( & V_2 -> V_56 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
unsigned int V_264 )
{
enum V_14 V_265 = V_264 & V_266 ;
if ( V_2 -> V_193 < V_217 ) {
if ( V_265 == V_179 ) {
T_1 V_218 ;
T_1 V_4 ;
switch ( V_2 -> V_171 ) {
case V_267 :
case V_268 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_218 = V_4 & ( V_248
| V_269
| V_247
| V_270 ) ;
if ( ! V_2 -> V_218 )
V_2 -> V_218 = V_4 & V_218 ;
V_4 &= ~ V_218 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
V_2 -> V_171 = V_265 ;
F_8 ( V_2 -> V_19 , L_71 , V_206 , V_2 -> V_171 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
const struct V_271 * V_208 )
{
switch ( V_208 -> type ) {
case V_272 :
F_130 ( V_2 ) ;
break;
case V_273 :
F_135 ( V_2 ) ;
break;
case V_274 :
F_139 ( V_2 ) ;
break;
case V_275 :
F_140 ( V_2 ) ;
break;
case V_276 :
F_141 ( V_2 , V_208 -> V_277 ) ;
break;
case V_278 :
F_8 ( V_2 -> V_19 , L_72 ) ;
break;
case V_279 :
F_8 ( V_2 -> V_19 , L_73 ) ;
break;
case V_280 :
F_8 ( V_2 -> V_19 , L_74 ) ;
break;
case V_281 :
F_8 ( V_2 -> V_19 , L_75 ) ;
break;
case V_282 :
F_8 ( V_2 -> V_19 , L_76 ) ;
break;
default:
F_19 ( V_2 -> V_19 , L_77 , V_208 -> type ) ;
}
}
static void F_143 ( struct V_1 * V_2 ,
const union V_283 * V_208 )
{
if ( V_208 -> type . V_284 == 0 ) {
return F_123 ( V_2 , & V_208 -> V_285 ) ;
}
switch ( V_208 -> type . type ) {
case V_286 :
F_142 ( V_2 , & V_208 -> V_287 ) ;
break;
default:
F_34 ( V_2 -> V_19 , L_78 , V_208 -> V_288 ) ;
}
}
static T_7 F_144 ( struct V_1 * V_2 , T_1 V_289 )
{
struct V_290 * V_291 ;
int V_292 ;
T_1 V_209 ;
V_209 = F_2 ( V_2 -> V_5 , F_145 ( V_289 ) ) ;
V_209 &= V_293 ;
if ( ! V_209 )
return V_294 ;
V_291 = V_2 -> V_295 [ V_289 ] ;
V_292 = V_209 ;
while ( V_292 > 0 ) {
union V_283 V_208 ;
V_208 . V_288 = * ( T_1 * ) ( V_291 -> V_289 + V_291 -> V_296 ) ;
F_143 ( V_2 , & V_208 ) ;
V_291 -> V_296 = ( V_291 -> V_296 + 4 ) % V_297 ;
V_292 -= 4 ;
F_3 ( V_2 -> V_5 , F_145 ( V_289 ) , 4 ) ;
}
return V_298 ;
}
static T_7 F_146 ( int V_299 , void * V_300 )
{
struct V_1 * V_2 = V_300 ;
int V_150 ;
T_7 V_103 = V_294 ;
F_21 ( & V_2 -> V_60 ) ;
for ( V_150 = 0 ; V_150 < V_2 -> V_301 ; V_150 ++ ) {
T_7 V_46 ;
V_46 = F_144 ( V_2 , V_150 ) ;
if ( V_46 == V_298 )
V_103 = V_46 ;
}
F_20 ( & V_2 -> V_60 ) ;
return V_103 ;
}
int T_6 F_147 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_103 ;
int V_299 ;
V_2 -> V_302 = F_33 ( V_2 -> V_19 , sizeof( * V_2 -> V_302 ) ,
& V_2 -> V_303 , V_88 ) ;
if ( ! V_2 -> V_302 ) {
F_34 ( V_2 -> V_19 , L_79 ) ;
V_103 = - V_89 ;
goto V_190;
}
V_2 -> V_304 = F_33 ( V_2 -> V_19 , sizeof( * V_2 -> V_304 ) ,
& V_2 -> V_305 , V_88 ) ;
if ( ! V_2 -> V_304 ) {
F_34 ( V_2 -> V_19 , L_80 ) ;
V_103 = - V_89 ;
goto V_198;
}
V_2 -> V_306 = F_71 ( V_307 , V_88 ) ;
if ( ! V_2 -> V_306 ) {
F_34 ( V_2 -> V_19 , L_81 ) ;
V_103 = - V_89 ;
goto V_308;
}
V_2 -> V_309 = F_33 ( V_2 -> V_19 ,
V_307 , & V_2 -> V_310 ,
V_88 ) ;
if ( ! V_2 -> V_309 ) {
F_34 ( V_2 -> V_19 , L_82 ) ;
V_103 = - V_89 ;
goto V_311;
}
F_148 ( & V_2 -> V_56 . V_19 , L_83 ) ;
V_2 -> V_56 . V_200 = & V_312 ;
V_2 -> V_56 . V_313 = V_254 ;
V_2 -> V_56 . V_172 = V_239 ;
V_2 -> V_56 . V_19 . V_314 = V_2 -> V_19 ;
V_2 -> V_56 . V_315 = true ;
F_149 ( & V_2 -> V_56 . V_19 , V_2 -> V_19 -> V_316 ) ;
V_2 -> V_56 . V_19 . V_317 = V_2 -> V_19 -> V_317 ;
V_2 -> V_56 . V_19 . V_318 = V_2 -> V_19 -> V_318 ;
V_2 -> V_56 . V_19 . V_319 = F_116 ;
V_2 -> V_56 . V_43 = L_84 ;
V_103 = F_113 ( V_2 ) ;
if ( V_103 )
goto V_320;
V_299 = F_150 ( F_151 ( V_2 -> V_19 ) , 0 ) ;
V_103 = F_152 ( V_299 , F_146 , V_321 ,
L_85 , V_2 ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_86 ,
V_299 , V_103 ) ;
goto V_322;
}
V_4 = F_2 ( V_2 -> V_5 , V_191 ) ;
V_4 |= V_323 ;
F_3 ( V_2 -> V_5 , V_191 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_270 | V_269 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 = ( V_324 |
V_325 |
V_326 |
V_327 |
V_328 |
V_329 |
V_330 |
V_331 |
V_332 ) ;
F_3 ( V_2 -> V_5 , V_333 , V_4 ) ;
V_103 = F_153 ( & V_2 -> V_56 . V_19 ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_87 ) ;
F_154 ( & V_2 -> V_56 . V_19 ) ;
goto V_334;
}
V_103 = F_155 ( V_2 -> V_19 , & V_2 -> V_56 ) ;
if ( V_103 ) {
F_34 ( V_2 -> V_19 , L_88 ) ;
goto V_335;
}
return 0 ;
V_335:
F_156 ( & V_2 -> V_56 . V_19 ) ;
V_334:
F_3 ( V_2 -> V_5 , V_333 , 0x00 ) ;
F_157 ( V_299 , V_2 ) ;
V_322:
F_115 ( V_2 ) ;
V_320:
F_36 ( V_2 -> V_19 , V_307 ,
V_2 -> V_309 , V_2 -> V_310 ) ;
V_311:
F_74 ( V_2 -> V_306 ) ;
V_308:
F_36 ( V_2 -> V_19 , sizeof( * V_2 -> V_304 ) ,
V_2 -> V_304 , V_2 -> V_305 ) ;
V_198:
F_36 ( V_2 -> V_19 , sizeof( * V_2 -> V_302 ) ,
V_2 -> V_302 , V_2 -> V_303 ) ;
V_190:
return V_103 ;
}
void F_158 ( struct V_1 * V_2 )
{
int V_299 ;
F_159 ( & V_2 -> V_56 ) ;
V_299 = F_150 ( F_151 ( V_2 -> V_19 ) , 0 ) ;
F_3 ( V_2 -> V_5 , V_333 , 0x00 ) ;
F_157 ( V_299 , V_2 ) ;
F_115 ( V_2 ) ;
F_36 ( V_2 -> V_19 , V_307 ,
V_2 -> V_309 , V_2 -> V_310 ) ;
F_74 ( V_2 -> V_306 ) ;
F_36 ( V_2 -> V_19 , sizeof( * V_2 -> V_304 ) ,
V_2 -> V_304 , V_2 -> V_305 ) ;
F_36 ( V_2 -> V_19 , sizeof( * V_2 -> V_302 ) ,
V_2 -> V_302 , V_2 -> V_303 ) ;
F_156 ( & V_2 -> V_56 . V_19 ) ;
}
