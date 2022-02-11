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
V_6 = ( ( V_4 -> V_10 . V_11 &
V_8 ) >>
V_9 ) * 2 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_13 ;
if ( F_2 ( V_2 , false ) ) {
V_13 =
F_3 ( V_7 ) & ~ V_14 ;
F_6 ( V_7 ,
( V_13 |
( V_12 << V_15 ) ) ) ;
F_4 ( V_2 ) ;
} else {
V_13 = V_4 -> V_10 . V_11 &
~ V_14 ;
V_4 -> V_10 . V_11 = ( V_13 |
( V_12 << V_15 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 , bool V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_19 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_18 ) {
F_6 ( V_20 , F_3 ( V_20 ) |
V_21 ) ;
do {
V_19 = F_3 ( V_22 ) ;
} while ( ( V_19 & V_23 ) == 0 );
F_5 ( V_2 ,
V_4 -> V_24 . V_25 ) ;
} else {
F_5 ( V_2 , 0 ) ;
F_6 ( V_20 , F_3 ( V_20 ) &
~ V_21 ) ;
do {
V_19 = F_3 ( V_22 ) ;
} while ( V_19 & V_23 );
}
F_4 ( V_2 ) ;
}
static void F_8 ( struct V_16 * V_17 , int V_26 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
if ( V_26 == V_27 )
F_7 ( V_2 , V_17 , true ) ;
else
F_7 ( V_2 , V_17 , false ) ;
}
static void F_9 ( struct V_28 * V_29 )
{
}
static void F_10 ( struct V_28 * V_29 )
{
}
static int F_11 ( struct V_28 * V_29 ,
struct V_30 * V_26 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 =
V_4 -> V_24 . V_32 ;
if ( V_26 -> V_33 & V_34 )
return V_35 ;
if ( V_26 -> V_33 & V_36 )
return V_37 ;
if ( V_31 ) {
if ( V_26 -> V_38 > V_31 -> V_38 )
return V_39 ;
if ( V_26 -> V_40 > V_31 -> V_40 )
return V_39 ;
}
return V_41 ;
}
static bool F_12 ( struct V_16 * V_17 ,
const struct V_30 * V_26 ,
struct V_30 * V_42 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
struct V_16 * V_44 ;
struct V_30 * V_32 = V_24 -> V_32 ;
F_13 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_44 != V_17
&& V_44 -> V_45 == V_17 -> V_45 ) {
F_14 ( V_46 L_1
L_2 ) ;
return false ;
}
}
if ( V_32 != NULL ) {
V_42 -> V_38 = V_32 -> V_38 ;
V_42 -> V_47 = V_32 -> V_47 ;
V_42 -> V_48 = V_32 -> V_48 ;
V_42 -> V_49 = V_32 -> V_49 ;
V_42 -> V_40 = V_32 -> V_40 ;
V_42 -> V_50 = V_32 -> V_50 ;
V_42 -> V_51 = V_32 -> V_51 ;
V_42 -> V_52 = V_32 -> V_52 ;
V_42 -> clock = V_32 -> clock ;
F_15 ( V_42 ,
V_53 ) ;
}
return true ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_24 -> V_11 = F_3 ( V_7 ) ;
V_24 -> V_25 = ( V_24 -> V_11 &
V_14 ) ;
F_7 ( V_2 , V_17 , false ) ;
F_4 ( V_2 ) ;
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
if ( V_24 -> V_25 == 0 )
V_24 -> V_25 =
F_1 ( V_2 ) ;
F_7 ( V_2 , V_17 , true ) ;
}
static void F_18 ( struct V_16 * V_17 ,
struct V_30 * V_26 ,
struct V_30 * V_42 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_54 * V_54 = F_19 ( V_17 -> V_45 ) ;
T_1 V_55 ;
if ( V_26 -> V_38 != V_42 -> V_38 ||
V_26 -> V_40 != V_42 -> V_40 )
V_55 = ( V_56 | V_57 |
V_58 | V_59 |
V_60 ) ;
else
V_55 = 0 ;
V_55 |= V_54 -> V_61 << V_62 ;
if ( V_4 -> V_63 )
V_55 |= V_64 ;
F_6 ( V_65 , V_55 ) ;
}
static enum V_66 F_20 (
struct V_28 * V_29 , bool V_67 )
{
return V_68 ;
}
static int F_21 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_69 * V_69 = F_22 ( V_29 ) ;
struct V_43 * V_24 = & V_4 -> V_24 ;
int V_70 ;
V_70 = F_23 ( V_29 , & V_69 -> V_71 -> V_72 ) ;
if ( V_70 )
return V_70 ;
V_29 -> V_73 . V_74 = 0 ;
V_29 -> V_73 . V_75 = 200 ;
V_29 -> V_73 . V_76 = 0 ;
V_29 -> V_73 . V_77 = 200 ;
if ( V_24 -> V_32 != NULL ) {
struct V_30 * V_26 =
F_24 ( V_2 , V_24 -> V_32 ) ;
F_25 ( V_29 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static void F_26 ( struct V_28 * V_29 )
{
struct V_69 * V_69 = F_22 ( V_29 ) ;
if ( V_69 -> V_71 )
F_27 ( V_69 -> V_71 ) ;
F_28 ( V_29 ) ;
F_29 ( V_29 ) ;
F_30 ( V_29 ) ;
}
static int F_31 ( struct V_28 * V_29 ,
struct V_78 * V_79 ,
T_2 V_80 )
{
struct V_16 * V_17 = V_29 -> V_17 ;
if ( ! strcmp ( V_79 -> V_81 , L_3 ) && V_17 ) {
struct V_54 * V_45 = F_19 ( V_17 -> V_45 ) ;
T_2 V_82 ;
if ( ! V_45 )
return - 1 ;
switch ( V_80 ) {
case V_83 :
break;
case V_84 :
break;
case V_85 :
break;
default:
return - 1 ;
}
if ( F_32 ( & V_29 -> V_86 ,
V_79 ,
& V_82 ) )
return - 1 ;
if ( V_82 == V_80 )
return 0 ;
if ( F_33 ( & V_29 -> V_86 ,
V_79 ,
V_80 ) )
return - 1 ;
if ( V_45 -> V_87 . V_38 != 0 &&
V_45 -> V_87 . V_40 != 0 ) {
if ( ! F_34 ( V_17 -> V_45 ,
& V_45 -> V_87 ,
V_17 -> V_45 -> V_88 ,
V_17 -> V_45 -> V_89 ,
V_17 -> V_45 -> V_90 -> V_91 ) )
return - 1 ;
}
} else if ( ! strcmp ( V_79 -> V_81 , L_4 ) && V_17 ) {
if ( F_33 ( & V_29 -> V_86 ,
V_79 ,
V_80 ) )
return - 1 ;
else
F_35 ( V_17 -> V_2 , V_80 ) ;
} else if ( ! strcmp ( V_79 -> V_81 , L_5 ) && V_17 ) {
const struct V_92 * V_93 =
V_17 -> V_94 ;
V_93 -> V_95 ( V_17 , V_80 ) ;
}
return 0 ;
}
static void F_36 ( struct V_16 * V_17 )
{
F_37 ( V_17 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
T_3 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_97 ;
if ( ! V_4 -> V_98 )
return true ;
for ( V_97 = 0 ; V_97 < V_4 -> V_98 ; V_97 ++ ) {
struct V_99 * V_100 = V_4 -> V_101 + V_97 ;
if ( V_100 -> V_102 != V_103 &&
V_100 -> V_102 != V_104 )
continue;
if ( V_100 -> V_96 )
* V_96 = V_100 -> V_96 ;
if ( V_100 -> V_105 )
return true ;
if ( V_4 -> V_106 . V_107 )
return true ;
}
return false ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_43 * V_24 )
{
struct V_69 * V_69 ;
struct V_108 * V_108 ;
struct V_109 * V_110 ;
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_30 * V_111 ;
struct V_112 * V_45 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_113 ;
int V_61 ;
T_3 V_114 ;
V_114 = V_115 ;
if ( ! F_38 ( V_2 , & V_114 ) ) {
F_40 ( L_6 ) ;
return;
}
V_69 = F_41 ( sizeof( struct V_69 ) ,
V_116 ) ;
if ( ! V_69 )
return;
V_108 = F_41 ( sizeof( struct V_108 ) ,
V_116 ) ;
if ( ! V_108 )
goto V_117;
V_110 = F_41 ( sizeof( struct V_109 ) , V_116 ) ;
if ( ! V_110 )
goto V_118;
V_69 -> V_4 = V_110 ;
V_29 = & V_108 -> V_86 ;
V_108 -> V_119 = F_9 ;
V_108 -> V_120 = F_10 ;
V_17 = & V_69 -> V_86 ;
F_42 ( V_2 , V_29 ,
& V_121 ,
V_122 ) ;
F_43 ( V_2 , V_17 ,
& V_123 ,
V_124 , NULL ) ;
F_44 ( V_108 , V_69 ) ;
V_69 -> type = V_125 ;
F_45 ( V_17 , & V_126 ) ;
F_46 ( V_29 ,
& V_127 ) ;
V_29 -> V_73 . V_128 = V_129 ;
V_29 -> V_130 = false ;
V_29 -> V_131 = false ;
F_47 ( & V_29 -> V_86 ,
V_2 -> V_132 . V_133 ,
V_83 ) ;
F_47 ( & V_29 -> V_86 ,
V_4 -> V_134 ,
V_135 ) ;
V_69 -> V_71 = F_48 ( V_2 ,
V_136 ,
L_7 ) ;
if ( ! V_69 -> V_71 ) {
F_49 ( V_46 ,
& V_2 -> V_137 -> V_2 , L_8 ) ;
goto V_138;
}
V_69 -> V_71 -> V_139 = 0x2C ;
V_4 -> V_140 = V_69 -> V_71 ;
V_69 -> V_141 = F_48 ( V_2 ,
V_142 ,
L_9 ) ;
if ( ! V_69 -> V_141 ) {
F_49 ( V_46 , & V_2 -> V_137 -> V_2 ,
L_10 L_11 ) ;
goto V_143;
}
F_50 ( & V_2 -> V_132 . V_144 ) ;
F_23 ( V_29 ,
& V_69 -> V_141 -> V_72 ) ;
F_13 (scan, &connector->probed_modes, head) {
if ( V_111 -> type & V_145 ) {
V_24 -> V_32 =
F_24 ( V_2 , V_111 ) ;
goto V_146;
}
}
if ( V_4 -> V_147 ) {
V_24 -> V_32 =
F_24 ( V_2 , V_4 -> V_147 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_145 ;
goto V_146;
}
}
V_113 = F_3 ( V_148 ) ;
V_61 = ( V_113 & V_149 ) ? 1 : 0 ;
V_45 = F_51 ( V_2 , V_61 ) ;
if ( V_45 && ( V_113 & V_150 ) ) {
V_24 -> V_32 =
F_52 ( V_2 , V_45 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_145 ;
goto V_146;
}
}
if ( ! V_24 -> V_32 ) {
F_53
( L_12 ) ;
goto V_151;
}
{
T_1 V_152 ;
V_152 = F_3 ( V_153 ) ;
if ( V_61 == 1 )
V_152 |= V_154 ;
else
V_152 &= ~ V_154 ;
V_152 |= V_155 ;
F_6 ( V_153 , V_152 ) ;
}
V_146:
F_54 ( & V_2 -> V_132 . V_144 ) ;
F_55 ( V_29 ) ;
return;
V_151:
F_54 ( & V_2 -> V_132 . V_144 ) ;
F_14 ( V_46 L_13 ) ;
if ( V_69 -> V_141 )
F_27 ( V_69 -> V_141 ) ;
V_143:
F_14 ( V_46 L_14 ) ;
if ( V_69 -> V_71 )
F_27 ( V_69 -> V_71 ) ;
V_138:
F_14 ( V_46 L_15 ) ;
F_37 ( V_17 ) ;
F_29 ( V_29 ) ;
F_30 ( V_110 ) ;
V_118:
F_30 ( V_108 ) ;
V_117:
F_30 ( V_69 ) ;
}
