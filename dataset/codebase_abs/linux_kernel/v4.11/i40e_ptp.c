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
V_29 = F_3 ( V_27 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_1 ( V_2 , & V_28 ) ;
V_28 = F_16 ( V_28 , V_29 ) ;
F_4 ( V_2 , ( const struct V_3 * ) & V_28 ) ;
F_17 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_1 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
F_15 ( & V_2 -> V_30 ) ;
F_4 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_31 * V_32 , int V_33 )
{
return - V_34 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_35 , V_36 ;
int V_37 ;
V_35 = F_2 ( V_6 , V_38 ) ;
V_36 = V_35 & ~ V_2 -> V_39 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
if ( V_36 & F_22 ( V_37 ) )
V_2 -> V_40 [ V_37 ] = V_41 ;
}
V_2 -> V_39 = V_35 ;
return V_35 ;
}
void F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_37 , V_45 = 0 ;
if ( ! ( V_2 -> V_46 & V_47 ) || ! V_2 -> V_48 )
return;
F_24 ( & V_2 -> V_49 ) ;
F_21 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
if ( ( V_2 -> V_39 & F_22 ( V_37 ) ) &&
F_25 ( V_2 -> V_40 [ V_37 ] + V_50 ) ) {
F_2 ( V_6 , F_26 ( V_37 ) ) ;
V_2 -> V_39 &= ~ F_22 ( V_37 ) ;
V_45 ++ ;
}
}
F_27 ( & V_2 -> V_49 ) ;
if ( V_45 > 2 )
F_28 ( & V_2 -> V_51 -> V_52 ,
L_1 ,
V_45 ) ;
V_2 -> V_53 += V_45 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_12 V_54 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_46 & V_47 ) || ! V_2 -> V_55 )
return;
if ( ! V_2 -> V_56 )
return;
V_8 = F_2 ( V_6 , V_57 ) ;
V_7 = F_2 ( V_6 , V_58 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_54 , V_9 ) ;
F_30 ( V_2 -> V_56 , & V_54 ) ;
F_31 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
F_32 ( V_59 , & V_2 -> V_60 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_61 * V_62 , T_5 V_63 )
{
T_1 V_35 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_46 & V_47 ) || ! V_2 -> V_48 )
return;
V_6 = & V_2 -> V_6 ;
F_24 ( & V_2 -> V_49 ) ;
V_35 = F_21 ( V_2 ) ;
if ( ! ( V_35 & F_22 ( V_63 ) ) ) {
F_27 ( & V_2 -> V_49 ) ;
return;
}
V_2 -> V_39 &= ~ F_22 ( V_63 ) ;
V_8 = F_2 ( V_6 , F_34 ( V_63 ) ) ;
V_7 = F_2 ( V_6 , F_26 ( V_63 ) ) ;
F_27 ( & V_2 -> V_49 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_35 ( V_62 ) , V_9 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_66 ;
V_65 = & V_6 -> V_67 . V_68 ;
F_37 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_65 -> V_69 ) {
case V_70 :
V_66 = V_71 ;
break;
case V_72 :
V_66 = V_73 ;
break;
case V_74 :
{
static int V_75 ;
if ( ! V_75 ) {
F_38 ( & V_2 -> V_51 -> V_52 ,
L_2 ) ;
V_75 ++ ;
}
V_66 = 0 ;
break;
}
case V_76 :
default:
V_66 = V_77 ;
break;
}
F_6 ( V_6 , V_25 , V_66 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_66 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_66 ;
F_11 () ;
}
int F_39 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_80 * V_81 = & V_2 -> V_82 ;
if ( ! ( V_2 -> V_46 & V_47 ) )
return - V_34 ;
return F_40 ( V_79 -> V_83 , V_81 , sizeof( * V_81 ) ) ?
- V_84 : 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_85 , V_86 ;
if ( V_81 -> V_46 )
return - V_87 ;
switch ( V_81 -> V_88 ) {
case V_89 :
V_2 -> V_55 = false ;
break;
case V_90 :
V_2 -> V_55 = true ;
break;
default:
return - V_91 ;
}
switch ( V_81 -> V_92 ) {
case V_93 :
V_2 -> V_48 = false ;
V_85 = V_94 ;
break;
case V_95 :
case V_96 :
case V_97 :
if ( ! ( V_2 -> V_46 & V_98 ) )
return - V_91 ;
V_2 -> V_48 = true ;
V_85 = V_99 |
V_94 |
V_100 ;
V_81 -> V_92 = V_97 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
if ( ! ( V_2 -> V_46 & V_98 ) )
return - V_91 ;
case V_107 :
case V_108 :
case V_109 :
V_2 -> V_48 = true ;
V_85 = V_110 |
V_111 ;
if ( V_2 -> V_46 & V_98 ) {
V_85 |= V_100 ;
V_81 -> V_92 = V_101 ;
} else {
V_81 -> V_92 = V_107 ;
}
break;
case V_112 :
default:
return - V_91 ;
}
F_24 ( & V_2 -> V_49 ) ;
F_2 ( V_6 , V_113 ) ;
F_2 ( V_6 , V_58 ) ;
F_2 ( V_6 , F_26 ( 0 ) ) ;
F_2 ( V_6 , F_26 ( 1 ) ) ;
F_2 ( V_6 , F_26 ( 2 ) ) ;
F_2 ( V_6 , F_26 ( 3 ) ) ;
V_2 -> V_39 = 0 ;
F_27 ( & V_2 -> V_49 ) ;
V_86 = F_2 ( V_6 , V_114 ) ;
if ( V_2 -> V_55 )
V_86 |= V_115 ;
else
V_86 &= ~ V_115 ;
F_6 ( V_6 , V_114 , V_86 ) ;
V_86 = F_2 ( V_6 , V_116 ) ;
if ( V_2 -> V_55 )
V_86 |= V_117 ;
else
V_86 &= ~ V_117 ;
F_6 ( V_6 , V_116 , V_86 ) ;
V_86 = F_2 ( V_6 , V_118 ) ;
V_86 &= V_119 ;
V_86 |= V_85 ;
F_6 ( V_6 , V_118 , V_86 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_80 V_81 ;
int V_120 ;
if ( ! ( V_2 -> V_46 & V_47 ) )
return - V_34 ;
if ( F_43 ( & V_81 , V_79 -> V_83 , sizeof( V_81 ) ) )
return - V_84 ;
V_120 = F_41 ( V_2 , & V_81 ) ;
if ( V_120 )
return V_120 ;
V_2 -> V_82 = V_81 ;
return F_40 ( V_79 -> V_83 , & V_81 , sizeof( V_81 ) ) ?
- V_84 : 0 ;
}
static long F_44 ( struct V_1 * V_2 )
{
if ( ! F_45 ( V_2 -> V_121 ) )
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
V_2 -> V_121 = F_46 ( & V_2 -> V_19 , & V_2 -> V_51 -> V_52 ) ;
if ( F_47 ( V_2 -> V_121 ) )
return F_48 ( V_2 -> V_121 ) ;
V_2 -> V_82 . V_92 = V_93 ;
V_2 -> V_82 . V_88 = V_89 ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_134 * V_135 = V_2 -> V_43 [ V_2 -> V_136 ] -> V_135 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_137 ;
long V_120 ;
V_137 = ( F_2 ( V_6 , V_114 ) & V_138 ) >>
V_139 ;
if ( V_6 -> V_137 != V_137 ) {
V_2 -> V_46 &= ~ V_47 ;
F_50 ( & V_2 -> V_51 -> V_52 , L_3 ,
V_140 ,
V_135 -> V_122 ) ;
return;
}
F_51 ( & V_2 -> V_30 ) ;
F_52 ( & V_2 -> V_49 ) ;
V_120 = F_44 ( V_2 ) ;
if ( V_120 ) {
V_2 -> V_121 = NULL ;
F_53 ( & V_2 -> V_51 -> V_52 , L_4 ,
V_140 ) ;
} else if ( V_2 -> V_121 ) {
struct V_3 V_4 ;
T_1 V_86 ;
if ( V_2 -> V_6 . V_141 & V_142 )
F_50 ( & V_2 -> V_51 -> V_52 , L_5 ) ;
V_2 -> V_46 |= V_47 ;
V_86 = F_2 ( V_6 , V_114 ) ;
V_86 |= V_143 ;
F_6 ( V_6 , V_114 , V_86 ) ;
V_86 = F_2 ( V_6 , V_118 ) ;
V_86 |= V_119 ;
F_6 ( V_6 , V_118 , V_86 ) ;
F_36 ( V_2 ) ;
F_41 ( V_2 , & V_2 -> V_82 ) ;
V_4 = F_54 ( F_55 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_46 &= ~ V_47 ;
V_2 -> V_55 = false ;
V_2 -> V_48 = false ;
if ( V_2 -> V_56 ) {
F_31 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
F_32 ( V_59 , & V_2 -> V_60 ) ;
}
if ( V_2 -> V_121 ) {
F_57 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
F_50 ( & V_2 -> V_51 -> V_52 , L_6 , V_140 ,
V_2 -> V_43 [ V_2 -> V_136 ] -> V_135 -> V_122 ) ;
}
}
