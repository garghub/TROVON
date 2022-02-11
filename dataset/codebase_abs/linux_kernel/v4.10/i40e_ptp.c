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
int V_37 ;
if ( ! ( V_2 -> V_45 & V_46 ) || ! V_2 -> V_47 )
return;
F_24 ( & V_2 -> V_48 ) ;
F_21 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
if ( ( V_2 -> V_39 & F_22 ( V_37 ) ) &&
F_25 ( V_2 -> V_40 [ V_37 ] + V_49 ) ) {
F_2 ( V_6 , F_26 ( V_37 ) ) ;
V_2 -> V_39 &= ~ F_22 ( V_37 ) ;
V_2 -> V_50 ++ ;
F_27 ( & V_2 -> V_51 -> V_52 ,
L_1 ,
V_37 ) ;
}
}
F_28 ( & V_2 -> V_48 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_12 V_53 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_45 & V_46 ) || ! V_2 -> V_54 )
return;
if ( ! V_2 -> V_55 )
return;
V_8 = F_2 ( V_6 , V_56 ) ;
V_7 = F_2 ( V_6 , V_57 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_53 , V_9 ) ;
F_30 ( V_2 -> V_55 , & V_53 ) ;
F_31 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
F_32 ( V_58 , & V_2 -> V_59 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_60 * V_61 , T_5 V_62 )
{
T_1 V_35 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! ( V_2 -> V_45 & V_46 ) || ! V_2 -> V_47 )
return;
V_6 = & V_2 -> V_6 ;
F_24 ( & V_2 -> V_48 ) ;
V_35 = F_21 ( V_2 ) ;
if ( ! ( V_35 & F_22 ( V_62 ) ) ) {
F_28 ( & V_2 -> V_48 ) ;
return;
}
V_2 -> V_39 &= ~ F_22 ( V_62 ) ;
V_8 = F_2 ( V_6 , F_34 ( V_62 ) ) ;
V_7 = F_2 ( V_6 , F_26 ( V_62 ) ) ;
F_28 ( & V_2 -> V_48 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_35 ( V_61 ) , V_9 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_65 ;
V_64 = & V_6 -> V_66 . V_67 ;
F_37 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_64 -> V_68 ) {
case V_69 :
V_65 = V_70 ;
break;
case V_71 :
V_65 = V_72 ;
break;
case V_73 :
{
static int V_74 ;
if ( ! V_74 ) {
F_27 ( & V_2 -> V_51 -> V_52 ,
L_2 ) ;
V_74 ++ ;
}
V_65 = 0 ;
break;
}
case V_75 :
default:
V_65 = V_76 ;
break;
}
F_6 ( V_6 , V_25 , V_65 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_65 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_65 ;
F_11 () ;
}
int F_38 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_79 * V_80 = & V_2 -> V_81 ;
if ( ! ( V_2 -> V_45 & V_46 ) )
return - V_34 ;
return F_39 ( V_78 -> V_82 , V_80 , sizeof( * V_80 ) ) ?
- V_83 : 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_84 , V_85 ;
if ( V_80 -> V_45 )
return - V_86 ;
switch ( V_80 -> V_87 ) {
case V_88 :
V_2 -> V_54 = false ;
break;
case V_89 :
V_2 -> V_54 = true ;
break;
default:
return - V_90 ;
}
switch ( V_80 -> V_91 ) {
case V_92 :
V_2 -> V_47 = false ;
V_84 = V_93 ;
break;
case V_94 :
case V_95 :
case V_96 :
if ( ! ( V_2 -> V_45 & V_97 ) )
return - V_90 ;
V_2 -> V_47 = true ;
V_84 = V_98 |
V_93 |
V_99 ;
V_80 -> V_91 = V_96 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
if ( ! ( V_2 -> V_45 & V_97 ) )
return - V_90 ;
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_47 = true ;
V_84 = V_109 |
V_110 ;
if ( V_2 -> V_45 & V_97 ) {
V_84 |= V_99 ;
V_80 -> V_91 = V_100 ;
} else {
V_80 -> V_91 = V_106 ;
}
break;
case V_111 :
default:
return - V_90 ;
}
F_24 ( & V_2 -> V_48 ) ;
F_2 ( V_6 , V_112 ) ;
F_2 ( V_6 , V_57 ) ;
F_2 ( V_6 , F_26 ( 0 ) ) ;
F_2 ( V_6 , F_26 ( 1 ) ) ;
F_2 ( V_6 , F_26 ( 2 ) ) ;
F_2 ( V_6 , F_26 ( 3 ) ) ;
V_2 -> V_39 = 0 ;
F_28 ( & V_2 -> V_48 ) ;
V_85 = F_2 ( V_6 , V_113 ) ;
if ( V_2 -> V_54 )
V_85 |= V_114 ;
else
V_85 &= ~ V_114 ;
F_6 ( V_6 , V_113 , V_85 ) ;
V_85 = F_2 ( V_6 , V_115 ) ;
if ( V_2 -> V_54 )
V_85 |= V_116 ;
else
V_85 &= ~ V_116 ;
F_6 ( V_6 , V_115 , V_85 ) ;
V_85 = F_2 ( V_6 , V_117 ) ;
V_85 &= V_118 ;
V_85 |= V_84 ;
F_6 ( V_6 , V_117 , V_85 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_79 V_80 ;
int V_119 ;
if ( ! ( V_2 -> V_45 & V_46 ) )
return - V_34 ;
if ( F_42 ( & V_80 , V_78 -> V_82 , sizeof( V_80 ) ) )
return - V_83 ;
V_119 = F_40 ( V_2 , & V_80 ) ;
if ( V_119 )
return V_119 ;
V_2 -> V_81 = V_80 ;
return F_39 ( V_78 -> V_82 , & V_80 , sizeof( V_80 ) ) ?
- V_83 : 0 ;
}
static long F_43 ( struct V_1 * V_2 )
{
if ( ! F_44 ( V_2 -> V_120 ) )
return 0 ;
strncpy ( V_2 -> V_19 . V_121 , V_122 , sizeof( V_2 -> V_19 . V_121 ) ) ;
V_2 -> V_19 . V_123 = V_124 ;
V_2 -> V_19 . V_125 = 999999999 ;
V_2 -> V_19 . V_126 = 0 ;
V_2 -> V_19 . V_127 = 0 ;
V_2 -> V_19 . V_128 = F_9 ;
V_2 -> V_19 . V_129 = F_14 ;
V_2 -> V_19 . V_130 = F_18 ;
V_2 -> V_19 . V_131 = F_19 ;
V_2 -> V_19 . V_132 = F_20 ;
V_2 -> V_120 = F_45 ( & V_2 -> V_19 , & V_2 -> V_51 -> V_52 ) ;
if ( F_46 ( V_2 -> V_120 ) )
return F_47 ( V_2 -> V_120 ) ;
V_2 -> V_81 . V_91 = V_92 ;
V_2 -> V_81 . V_87 = V_88 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_43 [ V_2 -> V_135 ] -> V_134 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_136 ;
long V_119 ;
V_136 = ( F_2 ( V_6 , V_113 ) & V_137 ) >>
V_138 ;
if ( V_6 -> V_136 != V_136 ) {
V_2 -> V_45 &= ~ V_46 ;
F_49 ( & V_2 -> V_51 -> V_52 , L_3 ,
V_139 ,
V_134 -> V_121 ) ;
return;
}
F_50 ( & V_2 -> V_30 ) ;
F_51 ( & V_2 -> V_48 ) ;
V_119 = F_43 ( V_2 ) ;
if ( V_119 ) {
V_2 -> V_120 = NULL ;
F_52 ( & V_2 -> V_51 -> V_52 , L_4 ,
V_139 ) ;
} else if ( V_2 -> V_120 ) {
struct V_3 V_4 ;
T_1 V_85 ;
if ( V_2 -> V_6 . V_140 & V_141 )
F_49 ( & V_2 -> V_51 -> V_52 , L_5 ) ;
V_2 -> V_45 |= V_46 ;
V_85 = F_2 ( V_6 , V_113 ) ;
V_85 |= V_142 ;
F_6 ( V_6 , V_113 , V_85 ) ;
V_85 = F_2 ( V_6 , V_117 ) ;
V_85 |= V_118 ;
F_6 ( V_6 , V_117 , V_85 ) ;
F_36 ( V_2 ) ;
F_40 ( V_2 , & V_2 -> V_81 ) ;
V_4 = F_53 ( F_54 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_45 &= ~ V_46 ;
V_2 -> V_54 = false ;
V_2 -> V_47 = false ;
if ( V_2 -> V_55 ) {
F_31 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
F_32 ( V_58 , & V_2 -> V_59 ) ;
}
if ( V_2 -> V_120 ) {
F_56 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_49 ( & V_2 -> V_51 -> V_52 , L_6 , V_139 ,
V_2 -> V_43 [ V_2 -> V_135 ] -> V_134 -> V_121 ) ;
}
}
