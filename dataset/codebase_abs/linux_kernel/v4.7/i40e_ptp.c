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
struct V_3 V_28 , V_29 ;
unsigned long V_30 ;
V_29 = F_3 ( V_27 ) ;
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
F_25 ( 1 , L_1 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_12 V_62 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_30 & V_44 ) || ! V_2 -> V_63 )
return;
if ( ! V_2 -> V_64 )
return;
V_8 = F_2 ( V_6 , V_65 ) ;
V_7 = F_2 ( V_6 , V_66 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_62 , V_9 ) ;
F_27 ( V_2 -> V_64 , & V_62 ) ;
F_28 ( V_2 -> V_64 ) ;
V_2 -> V_64 = NULL ;
F_29 ( V_67 , & V_2 -> V_68 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_69 * V_70 , T_5 V_71 )
{
T_1 V_42 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_30 & V_44 ) || ! V_2 -> V_45 )
return;
V_6 = & V_2 -> V_6 ;
V_42 = F_2 ( V_6 , V_46 ) ;
if ( ! ( V_42 & F_31 ( V_71 ) ) )
return;
V_8 = F_2 ( V_6 , F_32 ( V_71 ) ) ;
V_7 = F_2 ( V_6 , F_24 ( V_71 ) ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_33 ( V_70 ) , V_9 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_74 ;
V_73 = & V_6 -> V_75 . V_76 ;
F_35 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_73 -> V_77 ) {
case V_78 :
V_74 = V_79 ;
break;
case V_80 :
V_74 = V_81 ;
break;
case V_82 :
{
static int V_83 ;
if ( ! V_83 ) {
F_36 ( & V_2 -> V_84 -> V_85 ,
L_2 ) ;
V_83 ++ ;
}
V_74 = 0 ;
break;
}
case V_86 :
default:
V_74 = V_87 ;
break;
}
F_6 ( V_6 , V_25 , V_74 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_74 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_74 ;
F_11 () ;
}
int F_37 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_90 * V_91 = & V_2 -> V_92 ;
if ( ! ( V_2 -> V_30 & V_44 ) )
return - V_35 ;
return F_38 ( V_89 -> V_93 , V_91 , sizeof( * V_91 ) ) ?
- V_94 : 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_95 , V_96 ;
if ( V_91 -> V_30 )
return - V_97 ;
switch ( V_91 -> V_98 ) {
case V_99 :
V_2 -> V_63 = false ;
break;
case V_100 :
V_2 -> V_63 = true ;
break;
default:
return - V_101 ;
}
switch ( V_91 -> V_102 ) {
case V_103 :
V_2 -> V_45 = false ;
V_95 = V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
V_2 -> V_45 = true ;
V_95 = V_108 |
V_104 |
V_109 ;
V_91 -> V_102 = V_107 ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_2 -> V_45 = true ;
V_95 = V_119 |
V_120 |
V_109 ;
V_91 -> V_102 = V_110 ;
break;
case V_121 :
default:
return - V_101 ;
}
F_2 ( V_6 , V_122 ) ;
F_2 ( V_6 , V_66 ) ;
F_2 ( V_6 , F_24 ( 0 ) ) ;
F_2 ( V_6 , F_24 ( 1 ) ) ;
F_2 ( V_6 , F_24 ( 2 ) ) ;
F_2 ( V_6 , F_24 ( 3 ) ) ;
V_96 = F_2 ( V_6 , V_123 ) ;
if ( V_2 -> V_63 )
V_96 |= V_124 ;
else
V_96 &= ~ V_124 ;
F_6 ( V_6 , V_123 , V_96 ) ;
V_96 = F_2 ( V_6 , V_125 ) ;
if ( V_2 -> V_63 )
V_96 |= V_126 ;
else
V_96 &= ~ V_126 ;
F_6 ( V_6 , V_125 , V_96 ) ;
V_96 = F_2 ( V_6 , V_127 ) ;
V_96 &= V_128 ;
V_96 |= V_95 ;
F_6 ( V_6 , V_127 , V_96 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_90 V_91 ;
int V_129 ;
if ( ! ( V_2 -> V_30 & V_44 ) )
return - V_35 ;
if ( F_41 ( & V_91 , V_89 -> V_93 , sizeof( V_91 ) ) )
return - V_94 ;
V_129 = F_39 ( V_2 , & V_91 ) ;
if ( V_129 )
return V_129 ;
V_2 -> V_92 = V_91 ;
return F_38 ( V_89 -> V_93 , & V_91 , sizeof( V_91 ) ) ?
- V_94 : 0 ;
}
static long F_42 ( struct V_1 * V_2 )
{
if ( ! F_43 ( V_2 -> V_130 ) )
return 0 ;
strncpy ( V_2 -> V_19 . V_131 , V_132 , sizeof( V_2 -> V_19 . V_131 ) ) ;
V_2 -> V_19 . V_133 = V_134 ;
V_2 -> V_19 . V_135 = 999999999 ;
V_2 -> V_19 . V_136 = 0 ;
V_2 -> V_19 . V_137 = 0 ;
V_2 -> V_19 . V_138 = F_9 ;
V_2 -> V_19 . V_139 = F_14 ;
V_2 -> V_19 . V_140 = F_18 ;
V_2 -> V_19 . V_141 = F_19 ;
V_2 -> V_19 . V_142 = F_20 ;
V_2 -> V_130 = F_44 ( & V_2 -> V_19 , & V_2 -> V_84 -> V_85 ) ;
if ( F_45 ( V_2 -> V_130 ) )
return F_46 ( V_2 -> V_130 ) ;
V_2 -> V_92 . V_102 = V_103 ;
V_2 -> V_92 . V_98 = V_99 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_143 * V_144 = V_2 -> V_37 [ V_2 -> V_145 ] -> V_144 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_146 ;
long V_129 ;
V_146 = ( F_2 ( V_6 , V_123 ) & V_147 ) >>
V_148 ;
if ( V_6 -> V_146 != V_146 ) {
V_2 -> V_30 &= ~ V_44 ;
F_48 ( & V_2 -> V_84 -> V_85 , L_3 ,
V_149 ,
V_144 -> V_131 ) ;
return;
}
F_49 ( & V_2 -> V_31 ) ;
V_129 = F_42 ( V_2 ) ;
if ( V_129 ) {
V_2 -> V_130 = NULL ;
F_50 ( & V_2 -> V_84 -> V_85 , L_4 ,
V_149 ) ;
} else {
struct V_3 V_4 ;
T_1 V_96 ;
if ( V_2 -> V_6 . V_150 & V_151 )
F_48 ( & V_2 -> V_84 -> V_85 , L_5 ) ;
V_2 -> V_30 |= V_44 ;
V_96 = F_2 ( V_6 , V_123 ) ;
V_96 |= V_152 ;
F_6 ( V_6 , V_123 , V_96 ) ;
V_96 = F_2 ( V_6 , V_127 ) ;
V_96 |= V_128 ;
F_6 ( V_6 , V_127 , V_96 ) ;
F_34 ( V_2 ) ;
F_39 ( V_2 , & V_2 -> V_92 ) ;
V_4 = F_51 ( F_52 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
V_2 -> V_30 &= ~ V_44 ;
V_2 -> V_63 = false ;
V_2 -> V_45 = false ;
if ( V_2 -> V_64 ) {
F_28 ( V_2 -> V_64 ) ;
V_2 -> V_64 = NULL ;
F_29 ( V_67 , & V_2 -> V_68 ) ;
}
if ( V_2 -> V_130 ) {
F_54 ( V_2 -> V_130 ) ;
V_2 -> V_130 = NULL ;
F_48 ( & V_2 -> V_84 -> V_85 , L_6 , V_149 ,
V_2 -> V_37 [ V_2 -> V_145 ] -> V_144 -> V_131 ) ;
}
}
