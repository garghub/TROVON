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
struct V_3 V_28 ;
F_15 ( & V_2 -> V_29 ) ;
F_1 ( V_2 , & V_28 ) ;
F_16 ( & V_28 , V_27 ) ;
F_4 ( V_2 , ( const struct V_3 * ) & V_28 ) ;
F_17 ( & V_2 -> V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_1 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_29 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_4 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_29 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_30 * V_31 , int V_32 )
{
return - V_33 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_34 , V_35 ;
int V_36 ;
V_34 = F_2 ( V_6 , V_37 ) ;
V_35 = V_34 & ~ V_2 -> V_38 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
if ( V_35 & F_22 ( V_36 ) )
V_2 -> V_39 [ V_36 ] = V_40 ;
}
V_2 -> V_38 = V_34 ;
return V_34 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_36 , V_41 = 0 ;
if ( ! ( V_2 -> V_42 & V_43 ) || ! V_2 -> V_44 )
return;
F_24 ( & V_2 -> V_45 ) ;
F_21 ( V_2 ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
if ( ( V_2 -> V_38 & F_22 ( V_36 ) ) &&
F_25 ( V_2 -> V_39 [ V_36 ] + V_46 ) ) {
F_2 ( V_6 , F_26 ( V_36 ) ) ;
V_2 -> V_38 &= ~ F_22 ( V_36 ) ;
V_41 ++ ;
}
}
F_27 ( & V_2 -> V_45 ) ;
if ( V_41 > 2 )
F_28 ( & V_2 -> V_47 -> V_48 ,
L_1 ,
V_41 ) ;
V_2 -> V_49 += V_41 ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_42 & V_43 ) || ! V_2 -> V_50 )
return;
if ( ! F_30 ( V_51 , V_2 -> V_52 ) )
return;
if ( F_25 ( V_2 -> V_53 + V_46 ) ) {
F_31 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
F_32 ( V_51 , V_2 -> V_52 ) ;
V_2 -> V_55 ++ ;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_12 V_56 ;
struct V_57 * V_58 = V_2 -> V_54 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_42 & V_43 ) || ! V_2 -> V_50 )
return;
if ( ! V_2 -> V_54 )
return;
V_8 = F_2 ( V_6 , V_59 ) ;
V_7 = F_2 ( V_6 , V_60 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_56 , V_9 ) ;
V_2 -> V_54 = NULL ;
F_32 ( V_51 , V_2 -> V_52 ) ;
F_34 ( V_58 , & V_56 ) ;
F_31 ( V_58 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_57 * V_58 , T_5 V_61 )
{
T_1 V_34 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_42 & V_43 ) || ! V_2 -> V_44 )
return;
V_6 = & V_2 -> V_6 ;
F_24 ( & V_2 -> V_45 ) ;
V_34 = F_21 ( V_2 ) ;
if ( ! ( V_34 & F_22 ( V_61 ) ) ) {
F_27 ( & V_2 -> V_45 ) ;
return;
}
V_2 -> V_38 &= ~ F_22 ( V_61 ) ;
V_8 = F_2 ( V_6 , F_36 ( V_61 ) ) ;
V_7 = F_2 ( V_6 , F_26 ( V_61 ) ) ;
F_27 ( & V_2 -> V_45 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_37 ( V_58 ) , V_9 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_64 ;
V_63 = & V_6 -> V_65 . V_66 ;
F_39 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_63 -> V_67 ) {
case V_68 :
V_64 = V_69 ;
break;
case V_70 :
V_64 = V_71 ;
break;
case V_72 :
{
static int V_73 ;
if ( ! V_73 ) {
F_40 ( & V_2 -> V_47 -> V_48 ,
L_2 ) ;
V_73 ++ ;
}
V_64 = 0 ;
break;
}
case V_74 :
default:
V_64 = V_75 ;
break;
}
F_6 ( V_6 , V_25 , V_64 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_64 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_64 ;
F_11 () ;
}
int F_41 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_78 * V_79 = & V_2 -> V_80 ;
if ( ! ( V_2 -> V_42 & V_43 ) )
return - V_33 ;
return F_42 ( V_77 -> V_81 , V_79 , sizeof( * V_79 ) ) ?
- V_82 : 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_83 , V_84 ;
if ( V_79 -> V_42 )
return - V_85 ;
switch ( V_79 -> V_86 ) {
case V_87 :
V_2 -> V_50 = false ;
break;
case V_88 :
V_2 -> V_50 = true ;
break;
default:
return - V_89 ;
}
switch ( V_79 -> V_90 ) {
case V_91 :
V_2 -> V_44 = false ;
V_83 = V_92 ;
break;
case V_93 :
case V_94 :
case V_95 :
if ( ! ( V_2 -> V_96 & V_97 ) )
return - V_89 ;
V_2 -> V_44 = true ;
V_83 = V_98 |
V_92 |
V_99 ;
V_79 -> V_90 = V_95 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
if ( ! ( V_2 -> V_96 & V_97 ) )
return - V_89 ;
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_44 = true ;
V_83 = V_109 |
V_110 ;
if ( V_2 -> V_96 & V_97 ) {
V_83 |= V_99 ;
V_79 -> V_90 = V_100 ;
} else {
V_79 -> V_90 = V_106 ;
}
break;
case V_111 :
case V_112 :
default:
return - V_89 ;
}
F_24 ( & V_2 -> V_45 ) ;
F_2 ( V_6 , V_113 ) ;
F_2 ( V_6 , V_60 ) ;
F_2 ( V_6 , F_26 ( 0 ) ) ;
F_2 ( V_6 , F_26 ( 1 ) ) ;
F_2 ( V_6 , F_26 ( 2 ) ) ;
F_2 ( V_6 , F_26 ( 3 ) ) ;
V_2 -> V_38 = 0 ;
F_27 ( & V_2 -> V_45 ) ;
V_84 = F_2 ( V_6 , V_114 ) ;
if ( V_2 -> V_50 )
V_84 |= V_115 ;
else
V_84 &= ~ V_115 ;
F_6 ( V_6 , V_114 , V_84 ) ;
V_84 = F_2 ( V_6 , V_116 ) ;
if ( V_2 -> V_50 )
V_84 |= V_117 ;
else
V_84 &= ~ V_117 ;
F_6 ( V_6 , V_116 , V_84 ) ;
V_84 = F_2 ( V_6 , V_118 ) ;
V_84 &= V_119 ;
V_84 |= V_83 ;
F_6 ( V_6 , V_118 , V_84 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_78 V_79 ;
int V_120 ;
if ( ! ( V_2 -> V_42 & V_43 ) )
return - V_33 ;
if ( F_45 ( & V_79 , V_77 -> V_81 , sizeof( V_79 ) ) )
return - V_82 ;
V_120 = F_43 ( V_2 , & V_79 ) ;
if ( V_120 )
return V_120 ;
V_2 -> V_80 = V_79 ;
return F_42 ( V_77 -> V_81 , & V_79 , sizeof( V_79 ) ) ?
- V_82 : 0 ;
}
static long F_46 ( struct V_1 * V_2 )
{
if ( ! F_47 ( V_2 -> V_121 ) )
return 0 ;
strncpy ( V_2 -> V_19 . V_122 , V_123 , sizeof( V_2 -> V_19 . V_122 ) ) ;
V_2 -> V_19 . V_124 = V_125 ;
V_2 -> V_19 . V_126 = 999999999 ;
V_2 -> V_19 . V_127 = 0 ;
V_2 -> V_19 . V_128 = 0 ;
V_2 -> V_19 . V_129 = F_9 ;
V_2 -> V_19 . V_130 = F_14 ;
V_2 -> V_19 . V_131 = F_18 ;
V_2 -> V_19 . V_132 = F_19 ;
V_2 -> V_19 . V_133 = F_20 ;
V_2 -> V_121 = F_48 ( & V_2 -> V_19 , & V_2 -> V_47 -> V_48 ) ;
if ( F_49 ( V_2 -> V_121 ) )
return F_50 ( V_2 -> V_121 ) ;
V_2 -> V_80 . V_90 = V_91 ;
V_2 -> V_80 . V_86 = V_87 ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = V_2 -> V_136 [ V_2 -> V_137 ] -> V_135 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_138 ;
long V_120 ;
V_138 = ( F_2 ( V_6 , V_114 ) & V_139 ) >>
V_140 ;
if ( V_6 -> V_138 != V_138 ) {
V_2 -> V_42 &= ~ V_43 ;
F_52 ( & V_2 -> V_47 -> V_48 , L_3 ,
V_141 ,
V_135 -> V_122 ) ;
return;
}
F_53 ( & V_2 -> V_29 ) ;
F_54 ( & V_2 -> V_45 ) ;
V_120 = F_46 ( V_2 ) ;
if ( V_120 ) {
V_2 -> V_121 = NULL ;
F_55 ( & V_2 -> V_47 -> V_48 , L_4 ,
V_141 ) ;
} else if ( V_2 -> V_121 ) {
struct V_3 V_4 ;
T_1 V_84 ;
if ( V_2 -> V_6 . V_142 & V_143 )
F_52 ( & V_2 -> V_47 -> V_48 , L_5 ) ;
V_2 -> V_42 |= V_43 ;
V_84 = F_2 ( V_6 , V_114 ) ;
V_84 |= V_144 ;
F_6 ( V_6 , V_114 , V_84 ) ;
V_84 = F_2 ( V_6 , V_118 ) ;
V_84 |= V_119 ;
F_6 ( V_6 , V_118 , V_84 ) ;
F_38 ( V_2 ) ;
F_43 ( V_2 , & V_2 -> V_80 ) ;
V_4 = F_56 ( F_57 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_42 &= ~ V_43 ;
V_2 -> V_50 = false ;
V_2 -> V_44 = false ;
if ( V_2 -> V_54 ) {
F_31 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
F_32 ( V_51 , V_2 -> V_52 ) ;
}
if ( V_2 -> V_121 ) {
F_59 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
F_52 ( & V_2 -> V_47 -> V_48 , L_6 , V_141 ,
V_2 -> V_136 [ V_2 -> V_137 ] -> V_135 -> V_122 ) ;
}
}
