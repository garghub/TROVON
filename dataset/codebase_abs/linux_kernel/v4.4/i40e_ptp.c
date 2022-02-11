static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
V_8 = F_2 ( V_6 , V_10 ) ;
V_7 = F_2 ( V_6 , V_11 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
* V_4 = F_3 ( V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_9 = F_5 ( V_4 ) ;
F_6 ( V_6 , V_10 , V_9 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_11 , V_9 >> 32 ) ;
}
static void F_7 ( struct V_12 * V_13 ,
T_2 V_14 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_15 = F_8 ( V_14 ) ;
}
static int F_9 ( struct V_16 * V_17 , T_3 V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_20 , V_21 , V_22 ;
int V_23 = 0 ;
if ( V_18 < 0 ) {
V_23 = 1 ;
V_18 = - V_18 ;
}
F_11 () ;
V_20 = F_12 ( V_2 -> V_24 ) ;
V_21 = V_20 ;
V_21 *= V_18 ;
V_22 = F_13 ( V_21 , 1000000000ULL ) ;
if ( V_23 )
V_20 -= V_22 ;
else
V_20 += V_22 ;
F_6 ( V_6 , V_25 , V_20 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_20 >> 32 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 , T_4 V_27 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
struct V_3 V_28 , V_29 = F_3 ( V_27 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_1 ( V_2 , & V_28 ) ;
V_28 = F_16 ( V_28 , V_29 ) ;
F_4 ( V_2 , ( const struct V_3 * ) & V_28 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_1 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_4 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_32 * V_33 , int V_34 )
{
return - V_35 ;
}
void F_21 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_39 * V_40 ;
unsigned long V_41 ;
T_1 V_42 ;
int V_43 ;
if ( ! ( V_2 -> V_30 & V_44 ) || ! V_2 -> V_45 )
return;
V_42 = F_2 ( V_6 , V_46 ) ;
if ( ! ( V_42 & ( ( V_47 <<
V_48 ) |
( V_49 <<
V_50 ) |
( V_51 <<
V_52 ) |
( V_53 <<
V_54 ) ) ) ) {
V_2 -> V_55 = V_56 ;
return;
}
V_41 = V_2 -> V_55 ;
for ( V_43 = 0 ; V_43 < V_37 -> V_57 ; V_43 ++ ) {
V_40 = V_37 -> V_58 [ V_43 ] ;
if ( F_22 ( V_40 -> V_59 , V_41 ) )
V_41 = V_40 -> V_59 ;
}
if ( F_23 ( V_41 + 5 * V_60 ) ) {
F_2 ( V_6 , F_24 ( 0 ) ) ;
F_2 ( V_6 , F_24 ( 1 ) ) ;
F_2 ( V_6 , F_24 ( 2 ) ) ;
F_2 ( V_6 , F_24 ( 3 ) ) ;
V_2 -> V_55 = V_56 ;
V_2 -> V_61 ++ ;
F_25 ( & V_37 -> V_38 -> V_62 -> V_63 ,
L_1 ,
V_64 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_12 V_65 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_30 & V_44 ) || ! V_2 -> V_66 )
return;
if ( ! V_2 -> V_67 )
return;
V_8 = F_2 ( V_6 , V_68 ) ;
V_7 = F_2 ( V_6 , V_69 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_65 , V_9 ) ;
F_27 ( V_2 -> V_67 , & V_65 ) ;
F_28 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_29 ( V_70 , & V_2 -> V_71 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_72 * V_73 , T_5 V_74 )
{
T_1 V_42 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_30 & V_44 ) || ! V_2 -> V_45 )
return;
V_6 = & V_2 -> V_6 ;
V_42 = F_2 ( V_6 , V_46 ) ;
if ( ! ( V_42 & F_31 ( V_74 ) ) )
return;
V_8 = F_2 ( V_6 , F_32 ( V_74 ) ) ;
V_7 = F_2 ( V_6 , F_24 ( V_74 ) ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_33 ( V_73 ) , V_9 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_77 ;
V_76 = & V_6 -> V_78 . V_79 ;
F_35 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_76 -> V_80 ) {
case V_81 :
V_77 = V_82 ;
break;
case V_83 :
V_77 = V_84 ;
break;
case V_85 :
{
static int V_86 ;
if ( ! V_86 ) {
F_25 ( & V_2 -> V_62 -> V_63 ,
L_2 ) ;
V_86 ++ ;
}
V_77 = 0 ;
break;
}
case V_87 :
default:
V_77 = V_88 ;
break;
}
F_6 ( V_6 , V_25 , V_77 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_77 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_77 ;
F_11 () ;
}
int F_36 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_91 * V_92 = & V_2 -> V_93 ;
if ( ! ( V_2 -> V_30 & V_44 ) )
return - V_35 ;
return F_37 ( V_90 -> V_94 , V_92 , sizeof( * V_92 ) ) ?
- V_95 : 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_96 , V_97 ;
if ( V_92 -> V_30 )
return - V_98 ;
switch ( V_92 -> V_99 ) {
case V_100 :
V_2 -> V_66 = false ;
break;
case V_101 :
V_2 -> V_66 = true ;
break;
default:
return - V_102 ;
}
switch ( V_92 -> V_103 ) {
case V_104 :
V_2 -> V_45 = false ;
V_96 = V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_45 = true ;
V_96 = V_109 |
V_105 |
V_110 ;
V_92 -> V_103 = V_108 ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_2 -> V_45 = true ;
V_96 = V_120 |
V_121 |
V_110 ;
V_92 -> V_103 = V_111 ;
break;
case V_122 :
default:
return - V_102 ;
}
F_2 ( V_6 , V_123 ) ;
F_2 ( V_6 , V_69 ) ;
F_2 ( V_6 , F_24 ( 0 ) ) ;
F_2 ( V_6 , F_24 ( 1 ) ) ;
F_2 ( V_6 , F_24 ( 2 ) ) ;
F_2 ( V_6 , F_24 ( 3 ) ) ;
V_97 = F_2 ( V_6 , V_124 ) ;
if ( V_2 -> V_66 )
V_97 |= V_125 ;
else
V_97 &= ~ V_125 ;
F_6 ( V_6 , V_124 , V_97 ) ;
V_97 = F_2 ( V_6 , V_126 ) ;
if ( V_2 -> V_66 )
V_97 |= V_127 ;
else
V_97 &= ~ V_127 ;
F_6 ( V_6 , V_126 , V_97 ) ;
V_97 = F_2 ( V_6 , V_128 ) ;
V_97 &= V_129 ;
V_97 |= V_96 ;
F_6 ( V_6 , V_128 , V_97 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_91 V_92 ;
int V_130 ;
if ( ! ( V_2 -> V_30 & V_44 ) )
return - V_35 ;
if ( F_40 ( & V_92 , V_90 -> V_94 , sizeof( V_92 ) ) )
return - V_95 ;
V_130 = F_38 ( V_2 , & V_92 ) ;
if ( V_130 )
return V_130 ;
V_2 -> V_93 = V_92 ;
return F_37 ( V_90 -> V_94 , & V_92 , sizeof( V_92 ) ) ?
- V_95 : 0 ;
}
static long F_41 ( struct V_1 * V_2 )
{
if ( ! F_42 ( V_2 -> V_131 ) )
return 0 ;
strncpy ( V_2 -> V_19 . V_132 , V_133 , sizeof( V_2 -> V_19 . V_132 ) ) ;
V_2 -> V_19 . V_134 = V_135 ;
V_2 -> V_19 . V_136 = 999999999 ;
V_2 -> V_19 . V_137 = 0 ;
V_2 -> V_19 . V_138 = 0 ;
V_2 -> V_19 . V_139 = F_9 ;
V_2 -> V_19 . V_140 = F_14 ;
V_2 -> V_19 . V_141 = F_18 ;
V_2 -> V_19 . V_142 = F_19 ;
V_2 -> V_19 . V_143 = F_20 ;
V_2 -> V_131 = F_43 ( & V_2 -> V_19 , & V_2 -> V_62 -> V_63 ) ;
if ( F_44 ( V_2 -> V_131 ) )
return F_45 ( V_2 -> V_131 ) ;
V_2 -> V_93 . V_103 = V_104 ;
V_2 -> V_93 . V_99 = V_100 ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_37 [ V_2 -> V_146 ] -> V_145 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_147 ;
long V_130 ;
V_147 = ( F_2 ( V_6 , V_124 ) & V_148 ) >>
V_149 ;
if ( V_6 -> V_147 != V_147 ) {
V_2 -> V_30 &= ~ V_44 ;
F_47 ( & V_2 -> V_62 -> V_63 , L_3 ,
V_64 ,
V_145 -> V_132 ) ;
return;
}
F_48 ( & V_2 -> V_31 ) ;
V_130 = F_41 ( V_2 ) ;
if ( V_130 ) {
V_2 -> V_131 = NULL ;
F_49 ( & V_2 -> V_62 -> V_63 , L_4 ,
V_64 ) ;
} else {
struct V_3 V_4 ;
T_1 V_97 ;
if ( V_2 -> V_6 . V_150 & V_151 )
F_47 ( & V_2 -> V_62 -> V_63 , L_5 ) ;
V_2 -> V_30 |= V_44 ;
V_97 = F_2 ( V_6 , V_124 ) ;
V_97 |= V_152 ;
F_6 ( V_6 , V_124 , V_97 ) ;
V_97 = F_2 ( V_6 , V_128 ) ;
V_97 |= V_129 ;
F_6 ( V_6 , V_128 , V_97 ) ;
F_34 ( V_2 ) ;
F_38 ( V_2 , & V_2 -> V_93 ) ;
V_4 = F_50 ( F_51 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_30 &= ~ V_44 ;
V_2 -> V_66 = false ;
V_2 -> V_45 = false ;
if ( V_2 -> V_67 ) {
F_28 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_29 ( V_70 , & V_2 -> V_71 ) ;
}
if ( V_2 -> V_131 ) {
F_53 ( V_2 -> V_131 ) ;
V_2 -> V_131 = NULL ;
F_47 ( & V_2 -> V_62 -> V_63 , L_6 , V_64 ,
V_2 -> V_37 [ V_2 -> V_146 ] -> V_145 -> V_132 ) ;
}
}
