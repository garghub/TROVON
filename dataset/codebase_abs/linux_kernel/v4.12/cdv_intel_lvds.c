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
F_14 ( L_1 ) ;
return false ;
}
}
if ( V_32 != NULL ) {
V_42 -> V_38 = V_32 -> V_38 ;
V_42 -> V_46 = V_32 -> V_46 ;
V_42 -> V_47 = V_32 -> V_47 ;
V_42 -> V_48 = V_32 -> V_48 ;
V_42 -> V_40 = V_32 -> V_40 ;
V_42 -> V_49 = V_32 -> V_49 ;
V_42 -> V_50 = V_32 -> V_50 ;
V_42 -> V_51 = V_32 -> V_51 ;
V_42 -> clock = V_32 -> clock ;
F_15 ( V_42 ,
V_52 ) ;
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
struct V_53 * V_53 = F_19 ( V_17 -> V_45 ) ;
T_1 V_54 ;
if ( V_26 -> V_38 != V_42 -> V_38 ||
V_26 -> V_40 != V_42 -> V_40 )
V_54 = ( V_55 | V_56 |
V_57 | V_58 |
V_59 ) ;
else
V_54 = 0 ;
V_54 |= V_53 -> V_60 << V_61 ;
if ( V_4 -> V_62 )
V_54 |= V_63 ;
F_6 ( V_64 , V_54 ) ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_65 = F_21 ( V_29 ) ;
struct V_43 * V_24 = & V_4 -> V_24 ;
int V_66 ;
V_66 = F_22 ( V_29 , & V_65 -> V_67 -> V_68 ) ;
if ( V_66 )
return V_66 ;
if ( V_24 -> V_32 != NULL ) {
struct V_30 * V_26 =
F_23 ( V_2 , V_24 -> V_32 ) ;
F_24 ( V_29 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_65 * V_65 = F_21 ( V_29 ) ;
F_26 ( V_65 -> V_67 ) ;
F_27 ( V_29 ) ;
F_28 ( V_29 ) ;
F_29 ( V_29 ) ;
}
static int F_30 ( struct V_28 * V_29 ,
struct V_69 * V_70 ,
T_2 V_71 )
{
struct V_16 * V_17 = V_29 -> V_17 ;
if ( ! strcmp ( V_70 -> V_72 , L_2 ) && V_17 ) {
struct V_53 * V_45 = F_19 ( V_17 -> V_45 ) ;
T_2 V_73 ;
if ( ! V_45 )
return - 1 ;
switch ( V_71 ) {
case V_74 :
break;
case V_75 :
break;
case V_76 :
break;
default:
return - 1 ;
}
if ( F_31 ( & V_29 -> V_77 ,
V_70 ,
& V_73 ) )
return - 1 ;
if ( V_73 == V_71 )
return 0 ;
if ( F_32 ( & V_29 -> V_77 ,
V_70 ,
V_71 ) )
return - 1 ;
if ( V_45 -> V_78 . V_38 != 0 &&
V_45 -> V_78 . V_40 != 0 ) {
if ( ! F_33 ( V_17 -> V_45 ,
& V_45 -> V_78 ,
V_17 -> V_45 -> V_79 ,
V_17 -> V_45 -> V_80 ,
V_17 -> V_45 -> V_81 -> V_82 ) )
return - 1 ;
}
} else if ( ! strcmp ( V_70 -> V_72 , L_3 ) && V_17 ) {
if ( F_32 ( & V_29 -> V_77 ,
V_70 ,
V_71 ) )
return - 1 ;
else
F_34 ( V_17 -> V_2 , V_71 ) ;
} else if ( ! strcmp ( V_70 -> V_72 , L_4 ) && V_17 ) {
const struct V_83 * V_84 =
V_17 -> V_85 ;
V_84 -> V_86 ( V_17 , V_71 ) ;
}
return 0 ;
}
static void F_35 ( struct V_16 * V_17 )
{
F_36 ( V_17 ) ;
}
static bool F_37 ( struct V_1 * V_2 ,
T_3 * V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_88 ;
if ( ! V_4 -> V_89 )
return true ;
for ( V_88 = 0 ; V_88 < V_4 -> V_89 ; V_88 ++ ) {
struct V_90 * V_91 = V_4 -> V_92 + V_88 ;
if ( V_91 -> V_93 != V_94 &&
V_91 -> V_93 != V_95 )
continue;
if ( V_91 -> V_87 )
* V_87 = V_91 -> V_87 ;
if ( V_91 -> V_96 )
return true ;
if ( V_4 -> V_97 . V_98 )
return true ;
}
return false ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_43 * V_24 )
{
struct V_65 * V_65 ;
struct V_99 * V_99 ;
struct V_100 * V_101 ;
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_30 * V_102 ;
struct V_103 * V_45 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_104 ;
int V_60 ;
T_3 V_105 ;
V_105 = V_106 ;
if ( ! F_37 ( V_2 , & V_105 ) ) {
F_39 ( L_5 ) ;
return;
}
V_65 = F_40 ( sizeof( struct V_65 ) ,
V_107 ) ;
if ( ! V_65 )
return;
V_99 = F_40 ( sizeof( struct V_99 ) ,
V_107 ) ;
if ( ! V_99 )
goto V_108;
V_101 = F_40 ( sizeof( struct V_100 ) , V_107 ) ;
if ( ! V_101 )
goto V_109;
V_65 -> V_4 = V_101 ;
V_29 = & V_99 -> V_77 ;
V_99 -> V_110 = F_9 ;
V_99 -> V_111 = F_10 ;
V_17 = & V_65 -> V_77 ;
F_41 ( V_2 , V_29 ,
& V_112 ,
V_113 ) ;
F_42 ( V_2 , V_17 ,
& V_114 ,
V_115 , NULL ) ;
F_43 ( V_99 , V_65 ) ;
V_65 -> type = V_116 ;
F_44 ( V_17 , & V_117 ) ;
F_45 ( V_29 ,
& V_118 ) ;
V_29 -> V_119 . V_120 = V_121 ;
V_29 -> V_122 = false ;
V_29 -> V_123 = false ;
F_46 ( & V_29 -> V_77 ,
V_2 -> V_124 . V_125 ,
V_74 ) ;
F_46 ( & V_29 -> V_77 ,
V_4 -> V_126 ,
V_127 ) ;
V_65 -> V_67 = F_47 ( V_2 ,
V_128 ,
L_6 ) ;
if ( ! V_65 -> V_67 ) {
F_48 ( V_129 ,
& V_2 -> V_130 -> V_2 , L_7 ) ;
goto V_131;
}
V_65 -> V_67 -> V_132 = 0x2C ;
V_4 -> V_133 = V_65 -> V_67 ;
V_65 -> V_134 = F_47 ( V_2 ,
V_135 ,
L_8 ) ;
if ( ! V_65 -> V_134 ) {
F_48 ( V_129 , & V_2 -> V_130 -> V_2 ,
L_9 L_10 ) ;
goto V_136;
}
F_49 ( & V_2 -> V_124 . V_137 ) ;
F_22 ( V_29 ,
& V_65 -> V_134 -> V_68 ) ;
F_13 (scan, &connector->probed_modes, head) {
if ( V_102 -> type & V_138 ) {
V_24 -> V_32 =
F_23 ( V_2 , V_102 ) ;
goto V_139;
}
}
if ( V_4 -> V_140 ) {
V_24 -> V_32 =
F_23 ( V_2 , V_4 -> V_140 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_138 ;
goto V_139;
}
}
V_104 = F_3 ( V_141 ) ;
V_60 = ( V_104 & V_142 ) ? 1 : 0 ;
V_45 = F_50 ( V_2 , V_60 ) ;
if ( V_45 && ( V_104 & V_143 ) ) {
V_24 -> V_32 =
F_51 ( V_2 , V_45 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_138 ;
goto V_139;
}
}
if ( ! V_24 -> V_32 ) {
F_52
( L_11 ) ;
goto V_144;
}
{
T_1 V_145 ;
V_145 = F_3 ( V_146 ) ;
if ( V_60 == 1 )
V_145 |= V_147 ;
else
V_145 &= ~ V_147 ;
V_145 |= V_148 ;
F_6 ( V_146 , V_145 ) ;
}
V_139:
F_53 ( & V_2 -> V_124 . V_137 ) ;
F_54 ( V_29 ) ;
return;
V_144:
F_53 ( & V_2 -> V_124 . V_137 ) ;
F_14 ( L_12 ) ;
F_26 ( V_65 -> V_134 ) ;
V_136:
F_14 ( L_13 ) ;
F_26 ( V_65 -> V_67 ) ;
V_131:
F_14 ( L_14 ) ;
F_36 ( V_17 ) ;
F_28 ( V_29 ) ;
F_29 ( V_101 ) ;
V_109:
F_29 ( V_99 ) ;
V_108:
F_29 ( V_65 ) ;
}
