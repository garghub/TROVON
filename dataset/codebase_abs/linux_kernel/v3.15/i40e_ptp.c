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
static void F_20 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_10 ( V_33 , struct V_1 ,
V_34 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_35 ;
if ( ! V_2 -> V_36 )
return;
if ( F_21 ( V_2 -> V_37 +
V_38 ) ) {
F_22 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_39 ++ ;
F_23 ( & V_2 -> V_40 -> V_41 , L_1 ) ;
return;
}
V_35 = F_2 ( V_6 , V_42 ) ;
if ( V_35 & V_43 )
F_24 ( V_2 ) ;
else
F_25 ( & V_2 -> V_34 ) ;
}
static int F_26 ( struct V_16 * V_17 ,
struct V_44 * V_45 , int V_46 )
{
return - V_47 ;
}
void F_27 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_51 * V_52 ;
unsigned long V_53 ;
T_1 V_54 ;
int V_55 ;
if ( V_2 -> V_30 & V_56 )
return;
V_54 = F_2 ( V_6 , V_57 ) ;
if ( ! ( V_54 & ( ( V_58 <<
V_59 ) |
( V_60 <<
V_61 ) |
( V_62 <<
V_63 ) |
( V_64 <<
V_65 ) ) ) ) {
V_2 -> V_66 = V_67 ;
return;
}
V_53 = V_2 -> V_66 ;
for ( V_55 = 0 ; V_55 < V_49 -> V_68 ; V_55 ++ ) {
V_52 = V_49 -> V_69 [ V_55 ] ;
if ( F_28 ( V_52 -> V_70 , V_53 ) )
V_53 = V_52 -> V_70 ;
}
if ( F_21 ( V_53 + 5 * V_71 ) ) {
F_2 ( V_6 , F_29 ( 0 ) ) ;
F_2 ( V_6 , F_29 ( 1 ) ) ;
F_2 ( V_6 , F_29 ( 2 ) ) ;
F_2 ( V_6 , F_29 ( 3 ) ) ;
V_2 -> V_66 = V_67 ;
V_2 -> V_72 ++ ;
F_23 ( & V_49 -> V_50 -> V_40 -> V_41 ,
L_2 ,
V_73 ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_12 V_74 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
V_8 = F_2 ( V_6 , V_75 ) ;
V_7 = F_2 ( V_6 , V_76 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_74 , V_9 ) ;
F_30 ( V_2 -> V_36 , & V_74 ) ;
F_22 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
void F_31 ( struct V_1 * V_2 , struct V_77 * V_78 , T_5 V_79 )
{
T_1 V_54 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 -> V_80 )
return;
V_6 = & V_2 -> V_6 ;
V_54 = F_2 ( V_6 , V_57 ) ;
if ( ! ( V_54 & ( 1 << V_79 ) ) )
return;
V_8 = F_2 ( V_6 , F_32 ( V_79 ) ) ;
V_7 = F_2 ( V_6 , F_29 ( V_79 ) ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_33 ( V_78 ) , V_9 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_83 ;
V_82 = & V_6 -> V_84 . V_85 ;
F_35 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_82 -> V_86 ) {
case V_87 :
V_83 = V_88 ;
break;
case V_89 :
V_83 = V_90 ;
break;
case V_91 :
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 ,
V_73 ) ;
V_83 = 0 ;
break;
case V_92 :
default:
V_83 = V_93 ;
break;
}
F_6 ( V_6 , V_25 , V_83 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_83 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_83 ;
F_11 () ;
}
int F_36 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_2 -> V_98 ;
return F_37 ( V_95 -> V_99 , V_97 , sizeof( * V_97 ) ) ?
- V_100 : 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_96 * V_97 = & V_2 -> V_98 ;
T_1 V_101 , V_102 , V_103 ;
if ( F_39 ( V_97 , V_95 -> V_99 , sizeof( * V_97 ) ) )
return - V_100 ;
if ( V_97 -> V_30 )
return - V_104 ;
V_101 = ( F_2 ( V_6 , V_105 ) & V_106 ) >>
V_107 ;
if ( V_6 -> V_101 != V_101 )
return - V_104 ;
switch ( V_97 -> V_108 ) {
case V_109 :
V_2 -> V_110 = false ;
break;
case V_111 :
V_2 -> V_110 = true ;
break;
default:
return - V_112 ;
}
switch ( V_97 -> V_113 ) {
case V_114 :
V_2 -> V_80 = false ;
V_102 = 0 ;
break;
case V_115 :
case V_116 :
case V_117 :
V_2 -> V_80 = true ;
V_102 = V_118 |
V_119 |
V_120 ;
V_97 -> V_113 = V_117 ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_2 -> V_80 = true ;
V_102 = V_130 |
V_131 |
V_120 ;
V_97 -> V_113 = V_121 ;
break;
case V_132 :
default:
return - V_112 ;
}
F_2 ( V_6 , V_42 ) ;
F_2 ( V_6 , V_76 ) ;
F_2 ( V_6 , F_29 ( 0 ) ) ;
F_2 ( V_6 , F_29 ( 1 ) ) ;
F_2 ( V_6 , F_29 ( 2 ) ) ;
F_2 ( V_6 , F_29 ( 3 ) ) ;
V_103 = F_2 ( V_6 , V_105 ) ;
if ( V_2 -> V_110 )
V_103 |= V_133 ;
else
V_103 &= ~ V_133 ;
F_6 ( V_6 , V_105 , V_103 ) ;
V_103 = F_2 ( V_6 , V_134 ) ;
if ( V_2 -> V_110 )
V_103 |= V_135 ;
else
V_103 &= ~ V_135 ;
F_6 ( V_6 , V_134 , V_103 ) ;
if ( V_2 -> V_80 ) {
V_103 = F_2 ( V_6 , V_136 ) ;
V_103 &= V_137 ;
V_103 |= V_102 ;
F_6 ( V_6 , V_136 , V_103 ) ;
}
return F_37 ( V_95 -> V_99 , V_97 , sizeof( * V_97 ) ) ?
- V_100 : 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_138 * V_139 = V_2 -> V_49 [ V_2 -> V_140 ] -> V_139 ;
strncpy ( V_2 -> V_19 . V_141 , L_4 , sizeof( V_2 -> V_19 . V_141 ) ) ;
V_2 -> V_19 . V_142 = V_143 ;
V_2 -> V_19 . V_144 = 999999999 ;
V_2 -> V_19 . V_145 = 0 ;
V_2 -> V_19 . V_146 = 0 ;
V_2 -> V_19 . V_147 = F_9 ;
V_2 -> V_19 . V_148 = F_14 ;
V_2 -> V_19 . V_149 = F_18 ;
V_2 -> V_19 . V_150 = F_19 ;
V_2 -> V_19 . V_151 = F_26 ;
V_2 -> V_152 = F_41 ( & V_2 -> V_19 , & V_2 -> V_40 -> V_41 ) ;
if ( F_42 ( V_2 -> V_152 ) ) {
V_2 -> V_152 = NULL ;
F_43 ( & V_2 -> V_40 -> V_41 , L_5 ,
V_73 ) ;
} else {
struct V_3 V_4 ;
T_1 V_103 ;
F_44 ( & V_2 -> V_31 ) ;
F_45 ( & V_2 -> V_34 , F_20 ) ;
F_46 ( & V_2 -> V_40 -> V_41 , L_6 , V_73 ,
V_139 -> V_141 ) ;
V_2 -> V_30 |= V_56 ;
V_103 = F_2 ( V_6 , V_105 ) ;
V_103 |= V_153 ;
F_6 ( V_6 , V_105 , V_103 ) ;
V_103 = F_2 ( V_6 , V_136 ) ;
V_103 |= V_137 ;
F_6 ( V_6 , V_136 , V_103 ) ;
F_34 ( V_2 ) ;
memset ( & V_2 -> V_98 , 0 , sizeof( V_2 -> V_98 ) ) ;
V_4 = F_47 ( F_48 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_30 &= ~ V_56 ;
V_2 -> V_110 = false ;
V_2 -> V_80 = false ;
F_50 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_36 ) {
F_22 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
if ( V_2 -> V_152 ) {
F_51 ( V_2 -> V_152 ) ;
V_2 -> V_152 = NULL ;
F_46 ( & V_2 -> V_40 -> V_41 , L_7 , V_73 ,
V_2 -> V_49 [ V_2 -> V_140 ] -> V_139 -> V_141 ) ;
}
}
