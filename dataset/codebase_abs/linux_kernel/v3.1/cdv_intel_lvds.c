static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( F_2 ( V_2 , false ) ) {
V_6 = ( ( F_3 ( V_7 ) &
V_8 ) >>
V_9 ) * 2 ;
F_4 ( V_2 ) ;
} else
V_6 = ( ( V_4 -> V_10 &
V_8 ) >>
V_9 ) * 2 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 = V_4 -> V_13 ;
T_2 V_14 [ 2 ] ;
unsigned int V_15 ;
struct V_16 V_17 [] = {
{
. V_18 = V_13 -> V_19 ,
. V_20 = 0 ,
. V_21 = 2 ,
. V_22 = V_14 ,
}
} ;
V_15 = V_23 & ( ( unsigned int ) V_11 *
V_23 /
V_24 ) ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_15 = V_23 - V_15 ;
V_14 [ 0 ] = V_4 -> V_25 -> V_28 ;
V_14 [ 1 ] = ( T_2 ) V_15 ;
if ( F_6 ( & V_13 -> V_29 , V_17 , 1 ) == 1 )
return 0 ;
F_7 ( L_1 ) ;
return - 1 ;
}
static int F_8 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_30 ;
T_1 V_31 ;
V_30 = F_1 ( V_2 ) ;
F_9 ( ( V_30 & V_32 ) == 0 ) ;
V_31 = V_11 * V_30 / V_24 ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_31 = V_30 - V_31 ;
V_31 &= V_33 ;
F_10 ( V_7 ,
( V_30 << V_34 ) |
( V_31 ) ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_25 ) {
F_7 ( L_2 ) ;
return;
}
if ( V_4 -> V_25 -> type == V_35 )
F_5 ( V_2 , V_11 ) ;
else
F_8 ( V_2 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_36 ;
if ( F_2 ( V_2 , false ) ) {
V_36 =
F_3 ( V_7 ) & ~ V_37 ;
F_10 ( V_7 ,
( V_36 |
( V_11 << V_38 ) ) ) ;
F_4 ( V_2 ) ;
} else {
V_36 = V_4 -> V_10 &
~ V_37 ;
V_4 -> V_10 = ( V_36 |
( V_11 << V_38 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 , bool V_41 )
{
T_1 V_42 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_41 ) {
F_10 ( V_43 , F_3 ( V_43 ) |
V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( ( V_42 & V_46 ) == 0 );
F_12 ( V_2 ,
V_40 ->
V_47 -> V_48 ) ;
} else {
F_12 ( V_2 , 0 ) ;
F_10 ( V_43 , F_3 ( V_43 ) &
~ V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( V_42 & V_46 );
}
F_4 ( V_2 ) ;
}
static void F_14 ( struct V_49 * V_50 , int V_51 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_15 ( V_50 ) ;
if ( V_51 == V_52 )
F_13 ( V_2 , V_40 , true ) ;
else
F_13 ( V_2 , V_40 , false ) ;
}
static void F_16 ( struct V_53 * V_54 )
{
}
static void F_17 ( struct V_53 * V_54 )
{
}
int F_18 ( struct V_53 * V_54 ,
struct V_55 * V_51 )
{
struct V_39 * V_39 =
F_19 ( V_54 ) ;
struct V_55 * V_56 =
V_39 -> V_47 -> V_57 ;
if ( V_51 -> V_20 & V_58 )
return V_59 ;
if ( V_51 -> V_20 & V_60 )
return V_61 ;
if ( V_56 ) {
if ( V_51 -> V_62 > V_56 -> V_62 )
return V_63 ;
if ( V_51 -> V_64 > V_56 -> V_64 )
return V_63 ;
}
return V_65 ;
}
bool F_20 ( struct V_49 * V_50 ,
struct V_55 * V_51 ,
struct V_55 * V_66 )
{
struct V_67 * V_47 =
F_15 ( V_50 ) -> V_47 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_49 * V_68 ;
struct V_55 * V_57 = V_47 -> V_57 ;
F_21 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_68 != V_50
&& V_68 -> V_69 == V_50 -> V_69 ) {
F_22 ( V_70 L_3
L_4 ) ;
return false ;
}
}
if ( V_57 != NULL ) {
V_66 -> V_62 = V_57 -> V_62 ;
V_66 -> V_71 = V_57 -> V_71 ;
V_66 -> V_72 = V_57 -> V_72 ;
V_66 -> V_73 = V_57 -> V_73 ;
V_66 -> V_64 = V_57 -> V_64 ;
V_66 -> V_74 = V_57 -> V_74 ;
V_66 -> V_75 = V_57 -> V_75 ;
V_66 -> V_76 = V_57 -> V_76 ;
V_66 -> clock = V_57 -> clock ;
F_23 ( V_66 ,
V_77 ) ;
}
return true ;
}
static void F_24 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_15 ( V_50 ) ;
struct V_67 * V_47 = V_40 -> V_47 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_47 -> V_10 = F_3 ( V_7 ) ;
V_47 -> V_48 = ( V_47 -> V_10 &
V_37 ) ;
F_13 ( V_2 , V_40 , false ) ;
F_4 ( V_2 ) ;
}
static void F_25 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_15 ( V_50 ) ;
struct V_67 * V_47 = V_40 -> V_47 ;
if ( V_47 -> V_48 == 0 )
V_47 -> V_48 =
F_1 ( V_2 ) ;
F_13 ( V_2 , V_40 , true ) ;
}
static void F_26 ( struct V_49 * V_50 ,
struct V_55 * V_51 ,
struct V_55 * V_66 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_78 ;
if ( V_51 -> V_62 != V_66 -> V_62 ||
V_51 -> V_64 != V_66 -> V_64 )
V_78 = ( V_79 | V_80 |
V_81 | V_82 |
V_83 ) ;
else
V_78 = 0 ;
if ( V_4 -> V_84 )
V_78 |= V_85 ;
F_10 ( V_86 , V_78 ) ;
}
static enum V_87 F_27 (
struct V_53 * V_54 , bool V_88 )
{
return V_89 ;
}
static int F_28 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_39 * V_39 =
F_19 ( V_54 ) ;
struct V_67 * V_47 =
V_39 -> V_47 ;
int V_90 ;
V_90 = F_29 ( V_39 ) ;
if ( V_90 )
return V_90 ;
V_54 -> V_91 . V_92 = 0 ;
V_54 -> V_91 . V_93 = 200 ;
V_54 -> V_91 . V_94 = 0 ;
V_54 -> V_91 . V_95 = 200 ;
if ( V_47 -> V_57 != NULL ) {
struct V_55 * V_51 =
F_30 ( V_2 , V_47 -> V_57 ) ;
F_31 ( V_54 , V_51 ) ;
return 1 ;
}
return 0 ;
}
void F_32 ( struct V_53 * V_54 )
{
struct V_39 * V_39 =
F_19 ( V_54 ) ;
if ( V_39 -> V_96 )
F_33 ( V_39 -> V_96 ) ;
F_34 ( V_54 ) ;
F_35 ( V_54 ) ;
F_36 ( V_54 ) ;
}
int F_37 ( struct V_53 * V_54 ,
struct V_97 * V_98 ,
T_3 V_99 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
if ( ! strcmp ( V_98 -> V_100 , L_5 ) && V_50 ) {
struct V_101 * V_69 =
F_38 ( V_50 -> V_69 ) ;
T_3 V_102 ;
if ( ! V_69 )
return - 1 ;
switch ( V_99 ) {
case V_103 :
break;
case V_104 :
break;
case V_105 :
break;
default:
return - 1 ;
}
if ( F_39 ( V_54 ,
V_98 ,
& V_102 ) )
return - 1 ;
if ( V_102 == V_99 )
return 0 ;
if ( F_40 ( V_54 ,
V_98 ,
V_99 ) )
return - 1 ;
if ( V_69 -> V_106 . V_62 != 0 &&
V_69 -> V_106 . V_64 != 0 ) {
if ( ! F_41 ( V_50 -> V_69 ,
& V_69 -> V_106 ,
V_50 -> V_69 -> V_107 ,
V_50 -> V_69 -> V_108 ,
V_50 -> V_69 -> V_109 ) )
return - 1 ;
}
} else if ( ! strcmp ( V_98 -> V_100 , L_6 ) && V_50 ) {
if ( F_40 ( V_54 ,
V_98 ,
V_99 ) )
return - 1 ;
else {
#ifdef F_42
struct V_3 * V_4 =
V_50 -> V_2 -> V_5 ;
struct V_110 * V_111 =
V_4 -> V_110 ;
V_111 -> V_112 . V_113 = V_99 ;
F_43 ( V_111 ) ;
#endif
}
} else if ( ! strcmp ( V_98 -> V_100 , L_7 ) && V_50 ) {
struct V_114 * V_115 =
V_50 -> V_116 ;
V_115 -> V_117 ( V_50 , V_99 ) ;
}
return 0 ;
}
static void F_44 ( struct V_49 * V_50 )
{
F_45 ( V_50 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_67 * V_47 )
{
struct V_39 * V_39 ;
struct V_118 * V_119 ;
struct V_53 * V_54 ;
struct V_49 * V_50 ;
struct V_55 * V_120 ;
struct V_121 * V_69 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_122 ;
int V_123 ;
V_39 = F_47 ( sizeof( struct V_39 ) +
sizeof( struct V_118 ) , V_124 ) ;
if ( ! V_39 )
return;
V_119 = (struct V_118 * ) ( V_39 + 1 ) ;
V_39 -> V_4 = V_119 ;
V_39 -> V_47 = V_47 ;
V_54 = & V_39 -> V_125 ;
V_50 = & V_39 -> V_126 ;
F_48 ( V_2 , & V_39 -> V_125 ,
& V_127 ,
V_128 ) ;
F_49 ( V_2 , & V_39 -> V_126 ,
& V_129 ,
V_130 ) ;
F_50 ( & V_39 -> V_125 ,
& V_39 -> V_126 ) ;
V_39 -> type = V_131 ;
F_51 ( V_50 , & V_132 ) ;
F_52 ( V_54 ,
& V_133 ) ;
V_54 -> V_91 . V_134 = V_135 ;
V_54 -> V_136 = false ;
V_54 -> V_137 = false ;
F_53 ( V_54 ,
V_2 -> V_138 . V_139 ,
V_103 ) ;
F_53 ( V_54 ,
V_4 -> V_140 ,
V_24 ) ;
V_39 -> V_141 = F_54 ( V_2 ,
V_142 ,
L_8 ) ;
if ( ! V_39 -> V_141 ) {
F_55 ( V_70 ,
& V_2 -> V_143 -> V_2 , L_9 ) ;
goto V_144;
}
V_39 -> V_141 -> V_19 = 0x2C ;
V_4 -> V_13 = V_39 -> V_141 ;
V_39 -> V_96 = F_54 ( V_2 ,
V_145 ,
L_10 ) ;
if ( ! V_39 -> V_96 ) {
F_55 ( V_70 , & V_2 -> V_143 -> V_2 ,
L_11 L_12 ) ;
goto V_146;
}
F_29 ( V_39 ) ;
F_21 (scan, &connector->probed_modes, head) {
if ( V_120 -> type & V_147 ) {
V_47 -> V_57 =
F_30 ( V_2 , V_120 ) ;
goto V_148;
}
}
if ( V_4 -> V_149 ) {
V_47 -> V_57 =
F_30 ( V_2 , V_4 -> V_149 ) ;
if ( V_47 -> V_57 ) {
V_47 -> V_57 -> type |=
V_147 ;
goto V_148;
}
}
V_122 = F_3 ( V_150 ) ;
V_123 = ( V_122 & V_151 ) ? 1 : 0 ;
V_69 = F_56 ( V_2 , V_123 ) ;
if ( V_69 && ( V_122 & V_152 ) ) {
V_47 -> V_57 =
F_57 ( V_2 , V_69 ) ;
if ( V_47 -> V_57 ) {
V_47 -> V_57 -> type |=
V_147 ;
goto V_148;
}
}
if ( ! V_47 -> V_57 ) {
F_58
( L_13 ) ;
goto V_153;
}
V_148:
F_59 ( V_54 ) ;
return;
V_153:
F_22 ( V_70 L_14 ) ;
if ( V_39 -> V_96 )
F_33 ( V_39 -> V_96 ) ;
V_146:
F_22 ( V_70 L_15 ) ;
if ( V_39 -> V_141 )
F_33 ( V_39 -> V_141 ) ;
V_144:
F_22 ( V_70 L_16 ) ;
F_45 ( V_50 ) ;
F_35 ( V_54 ) ;
F_36 ( V_54 ) ;
}
