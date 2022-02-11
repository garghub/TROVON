static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 V_7 ;
int V_8 ;
if ( F_2 ( & V_7 , V_2 , V_9 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 1 ] = ( V_5 << 16 ) | 0x1 ;
V_7 . V_11 . V_12 [ 2 ] = V_4 -> V_13 ;
V_7 . V_11 . V_12 [ 2 ] |= V_4 -> V_14 << 16 ;
V_7 . V_11 . V_12 [ 3 ] = V_4 -> V_15 | ( V_4 -> V_16 << 16 ) ;
V_7 . V_11 . V_12 [ 4 ] = V_4 -> V_17 ;
V_7 . V_11 . V_12 [ 4 ] |= V_4 -> V_18 << 16 ;
V_7 . V_11 . V_12 [ 5 ] = V_4 -> V_19 |
( V_4 -> V_20 << 16 ) ;
V_7 . V_11 . V_12 [ 6 ] = V_4 -> V_21 |
( V_4 -> V_22 << 16 ) ;
V_7 . V_11 . V_12 [ 7 ] = V_4 -> V_23 |
( V_4 -> V_24 << 16 ) ;
V_7 . V_11 . V_12 [ 8 ] = V_4 -> V_25 ;
V_7 . V_11 . V_12 [ 8 ] |= V_4 -> V_26 << 16 ;
V_7 . V_11 . V_12 [ 9 ] = V_4 -> V_27 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_1 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_30 , T_1 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_35 * V_36 = & V_33 -> V_37 ;
T_2 V_38 , V_39 , V_40 , V_41 ;
int V_42 = - V_43 , V_44 , V_45 ;
struct V_46 * V_47 ;
V_44 = F_7 ( V_2 , V_31 ) ;
if ( V_44 < 0 )
return - V_48 ;
V_40 = V_33 -> V_40 ;
V_41 = V_40 + 1 ;
V_30 -> V_13 = 0xffff ;
V_30 -> V_16 = V_36 -> V_49 / V_41 ;
V_30 -> V_18 = V_36 -> V_50 ;
V_39 = V_51 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_38 = V_36 -> V_50 - ( V_40 * V_39 ) ;
V_30 -> V_19 = V_38 ;
V_38 = V_36 -> V_53 - ( V_40 * V_39 ) ;
V_30 -> V_17 = V_38 ;
V_30 -> V_14 = 0 ;
V_30 -> V_15 = V_54 ;
} else {
V_45 = F_8 ( V_2 , V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_47 = V_33 -> V_55 [ V_45 ] . V_47 ;
V_30 -> V_14 = V_47 -> V_14 ;
V_30 -> V_15 = V_47 -> V_15 ;
V_30 -> V_19 = V_39 ;
V_30 -> V_17 = V_39 ;
}
V_30 -> V_20 = V_36 -> V_56 / V_41 ;
V_30 -> V_22 = V_36 -> V_57 / V_41 ;
V_30 -> V_23 = V_36 -> V_58 / V_41 ;
V_30 -> V_24 = V_36 -> V_59 / V_41 ;
V_30 -> V_21 = V_36 -> V_60 / V_41 ;
V_30 -> V_25 = V_36 -> V_61 ;
V_30 -> V_26 = V_36 -> V_26 ;
V_30 -> V_27 = V_36 -> V_27 ;
V_42 = F_1 ( V_2 , V_30 , V_44 ) ;
if ( V_42 )
return V_42 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_30 )
{
struct V_35 * V_37 = & V_2 -> V_34 -> V_33 -> V_37 ;
V_37 -> V_53 = V_30 -> V_17 ;
V_37 -> V_62 = V_30 -> V_19 ;
V_37 -> V_50 = V_30 -> V_18 ;
V_37 -> V_61 = V_30 -> V_25 ;
V_37 -> V_59 = V_30 -> V_24 ;
V_37 -> V_49 = V_30 -> V_16 ;
V_37 -> V_60 = V_30 -> V_21 ;
V_37 -> V_56 = V_30 -> V_20 ;
V_37 -> V_58 = V_30 -> V_23 ;
V_37 -> V_57 = V_30 -> V_22 ;
V_37 -> V_27 = V_30 -> V_27 ;
V_37 -> V_26 = V_30 -> V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
struct V_6 V_7 ;
if ( F_2 ( & V_7 , V_2 , V_63 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 1 ] = 0x2 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_2 , V_8 ) ;
goto V_64;
}
V_4 -> V_65 = V_7 . V_66 . V_12 [ 2 ] & 0xff ;
V_4 -> V_67 = ( V_7 . V_66 . V_12 [ 2 ] >> 8 ) & 0xff ;
V_4 -> V_68 = F_11 ( V_7 . V_66 . V_12 [ 2 ] ) ;
V_4 -> V_16 = F_12 ( V_7 . V_66 . V_12 [ 3 ] ) ;
V_4 -> V_17 = F_11 ( V_7 . V_66 . V_12 [ 3 ] ) ;
V_4 -> V_18 = F_12 ( V_7 . V_66 . V_12 [ 4 ] ) ;
V_4 -> V_19 = F_11 ( V_7 . V_66 . V_12 [ 4 ] ) ;
V_4 -> V_20 = F_12 ( V_7 . V_66 . V_12 [ 5 ] ) ;
V_4 -> V_21 = F_11 ( V_7 . V_66 . V_12 [ 5 ] ) ;
V_4 -> V_22 = F_12 ( V_7 . V_66 . V_12 [ 6 ] ) ;
V_4 -> V_23 = F_11 ( V_7 . V_66 . V_12 [ 6 ] ) ;
V_4 -> V_24 = F_12 ( V_7 . V_66 . V_12 [ 7 ] ) ;
V_4 -> V_25 = F_11 ( V_7 . V_66 . V_12 [ 7 ] ) ;
V_4 -> V_26 = F_12 ( V_7 . V_66 . V_12 [ 8 ] ) ;
V_4 -> V_27 = F_11 ( V_7 . V_66 . V_12 [ 8 ] ) ;
F_9 ( V_2 , V_4 ) ;
F_13 ( & V_2 -> V_28 -> V_29 ,
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
V_4 -> V_65 , V_4 -> V_67 ,
V_4 -> V_68 , V_4 -> V_16 ,
V_4 -> V_17 ,
V_4 -> V_18 ,
V_4 -> V_19 , V_4 -> V_20 ,
V_4 -> V_21 , V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_24 ,
V_4 -> V_25 , V_4 -> V_26 ,
V_4 -> V_27 ) ;
V_64:
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
int V_69 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_33 -> V_70 = 0 ;
} else {
V_69 = F_8 ( V_2 , V_31 ) ;
if ( V_69 < 0 )
return;
V_47 = V_33 -> V_55 [ V_69 ] . V_47 ;
V_47 -> V_71 = 0 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_72 , T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
int V_69 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_33 -> V_70 = V_72 ;
} else {
V_69 = F_8 ( V_2 , V_31 ) ;
if ( V_69 < 0 )
return;
V_47 = V_33 -> V_55 [ V_69 ] . V_47 ;
V_47 -> V_71 = V_72 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_73 * V_55 ;
int V_69 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
return V_33 -> V_70 ;
} else {
V_69 = F_8 ( V_2 , V_31 ) ;
if ( V_69 >= 0 ) {
V_55 = & V_33 -> V_55 [ V_69 ] ;
return V_55 -> V_47 -> V_71 ;
}
}
return - V_48 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_74 , T_1 V_31 )
{
struct V_6 V_7 ;
int V_42 ;
int V_44 ;
if ( F_2 ( & V_7 , V_2 , V_75 ) )
return - V_10 ;
if ( V_74 ) {
V_7 . V_11 . V_12 [ 3 ] = V_31 << 8 ;
} else {
V_44 = F_7 ( V_2 , V_31 ) ;
if ( V_44 < 0 ) {
V_42 = - V_48 ;
goto V_64;
}
V_7 . V_11 . V_12 [ 3 ] = ( ( V_44 & 0xffff ) << 8 ) | 1 ;
}
V_42 = F_3 ( V_2 , & V_7 ) ;
if ( V_42 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_10 ,
( V_74 ? L_11 : L_12 ) , V_42 , V_31 ) ;
goto V_64;
}
if ( V_74 ) {
V_44 = V_7 . V_66 . V_12 [ 2 ] & 0xffff ;
F_15 ( V_2 , V_44 , V_31 ) ;
} else {
F_14 ( V_2 , V_31 ) ;
}
V_64:
F_5 ( & V_7 ) ;
return V_42 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_76 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x4 ;
if ( V_76 )
V_7 . V_11 . V_12 [ 1 ] |= V_77 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_13 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_31 , T_3 V_76 )
{
struct V_6 V_7 ;
int V_8 = - V_43 ;
if ( F_2 ( & V_7 , V_2 , V_78 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 0 ] |= ( 3 << 29 ) ;
V_7 . V_11 . V_12 [ 1 ] = ( ( V_31 & 0xf ) << 2 ) | V_79 | V_80 ;
if ( V_76 )
V_7 . V_11 . V_12 [ 1 ] |= V_81 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 != V_82 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_14 , V_8 ) ;
V_8 = - V_43 ;
}
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_83 * V_84 = & V_33 -> V_84 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_33 -> V_40 ; V_85 ++ )
F_20 ( & V_33 -> V_55 [ V_85 ] . V_86 ) ;
F_21 ( V_84 -> V_87 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_34 -> V_33 -> V_84 ;
struct V_88 * V_89 ;
V_89 = F_23 ( L_15 ) ;
if ( V_89 == NULL ) {
F_4 ( & V_2 -> V_28 -> V_29 , L_16 ) ;
return - V_10 ;
}
V_84 -> V_87 = V_89 ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
T_3 V_31 = V_2 -> V_34 -> V_52 ;
if ( ! F_25 ( V_2 ) )
return;
F_19 ( V_2 ) ;
F_26 ( V_2 , 0 ) ;
F_16 ( V_2 , 0 , V_31 ) ;
F_18 ( V_2 , V_31 , 0 ) ;
F_17 ( V_2 , 0 ) ;
F_27 ( V_2 ) ;
V_2 -> V_34 -> V_90 = V_91 ;
F_28 ( V_92 , & V_2 -> V_93 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( ! F_30 ( V_2 ) )
return;
if ( ! F_25 ( V_2 ) )
return;
F_31 ( V_2 -> V_28 ) ;
F_32 ( V_2 -> V_94 ,
L_17 ,
V_2 -> V_95 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_96 * V_94 = V_2 -> V_94 ;
if ( F_34 ( V_94 ) )
F_35 ( V_2 , V_94 ) ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( F_36 ( V_2 ) )
return - V_43 ;
if ( F_34 ( V_94 ) )
F_37 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_97 * V_34 = V_2 -> V_34 ;
struct V_3 V_98 , V_99 , V_100 ;
int V_8 ;
T_3 V_31 = V_34 -> V_52 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_8 = F_17 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 , V_31 , 1 ) ;
if ( V_8 )
goto V_101;
V_8 = F_16 ( V_2 , 1 , V_31 ) ;
if ( V_8 )
goto V_102;
V_8 = F_10 ( V_2 , & V_99 ) ;
if ( V_8 )
goto V_103;
V_8 = F_39 ( V_2 , & V_98 , V_31 ) ;
if ( V_8 )
goto V_103;
V_8 = F_6 ( V_2 , & V_100 , V_31 ) ;
if ( V_8 )
goto V_103;
V_8 = F_26 ( V_2 , 1 ) ;
if ( V_8 )
goto V_103;
V_34 -> V_104 = ( T_3 ) V_98 . V_105 ;
V_34 -> V_106 = V_98 . V_106 ;
V_34 -> V_107 = V_98 . V_107 ;
V_34 -> V_108 = V_98 . V_108 ;
V_34 -> V_109 = V_110 ;
return V_8 ;
V_103:
F_16 ( V_2 , 0 , V_31 ) ;
V_102:
F_18 ( V_2 , V_31 , 0 ) ;
V_101:
F_17 ( V_2 , 0 ) ;
return V_8 ;
}
static int F_40 ( struct V_1 * V_2 , int V_40 )
{
int V_8 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_8 = F_41 ( V_2 -> V_28 , V_40 ) ;
if ( V_8 )
F_24 ( V_2 ) ;
return V_8 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_40 )
{
int V_8 = 0 ;
F_43 ( V_92 , & V_2 -> V_93 ) ;
V_2 -> V_34 -> V_90 = V_111 ;
V_8 = F_44 ( V_2 , V_40 ) ;
if ( V_8 )
goto V_112;
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
goto V_113;
V_8 = F_38 ( V_2 ) ;
if ( V_8 )
goto V_114;
V_8 = F_40 ( V_2 , V_40 ) ;
return V_8 ;
V_114:
F_19 ( V_2 ) ;
V_113:
F_27 ( V_2 ) ;
V_112:
F_28 ( V_92 , & V_2 -> V_93 ) ;
V_2 -> V_34 -> V_90 = V_91 ;
return V_8 ;
}
static int F_45 ( struct V_1 * V_2 , int V_40 )
{
struct V_96 * V_94 = V_2 -> V_94 ;
int V_8 ;
if ( ! ( V_2 -> V_115 & V_116 ) ) {
F_46 ( V_94 ,
L_18 ) ;
return - V_43 ;
}
if ( F_34 ( V_94 ) )
F_35 ( V_2 , V_94 ) ;
V_8 = F_42 ( V_2 , V_40 ) ;
if ( V_8 ) {
F_32 ( V_94 , L_19 ,
V_2 -> V_95 ) ;
V_8 = - V_43 ;
if ( F_36 ( V_2 ) )
goto error;
} else {
F_32 ( V_94 ,
L_20 ,
V_2 -> V_95 ) ;
V_8 = V_40 ;
}
if ( F_34 ( V_94 ) )
F_37 ( V_2 , V_94 ) ;
error:
return V_8 ;
}
int F_47 ( struct V_117 * V_29 , int V_40 )
{
struct V_1 * V_2 = F_48 ( V_29 ) ;
int V_8 ;
if ( F_49 ( V_118 , & V_2 -> V_93 ) )
return - V_119 ;
if ( V_40 == 0 )
V_8 = F_33 ( V_2 ) ;
else
V_8 = F_45 ( V_2 , V_40 ) ;
F_28 ( V_118 , & V_2 -> V_93 ) ;
return V_8 ;
}
static int F_50 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_6 V_7 ;
struct V_46 * V_47 ;
int V_8 , V_45 ;
V_45 = F_8 ( V_2 , V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_47 = V_2 -> V_34 -> V_33 -> V_55 [ V_45 ] . V_47 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x3 | V_31 << 16 ;
if ( V_47 -> V_120 == V_121 ) {
V_7 . V_11 . V_12 [ 2 ] |= V_79 ;
V_7 . V_11 . V_12 [ 3 ] |= V_47 -> V_122 << 8 ;
}
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 , L_21 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_51 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_3 V_123 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_123 , V_31 ) ;
if ( V_8 )
return - V_43 ;
V_8 = F_50 ( V_2 , V_31 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_52 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
T_1 V_31 = V_126 -> V_52 ;
V_7 -> V_66 . V_12 [ 0 ] = V_125 -> V_127 -> V_128 ;
V_7 -> V_66 . V_12 [ 0 ] |= ( 1 << 16 ) ;
if ( V_125 -> V_127 -> V_128 == V_129 ) {
V_8 = F_16 ( V_2 , 1 , V_31 ) ;
if ( ! V_8 ) {
V_8 = F_51 ( V_2 , V_31 ) ;
if ( V_8 )
F_16 ( V_2 , 0 , V_31 ) ;
}
} else {
V_8 = F_16 ( V_2 , 0 , V_31 ) ;
}
if ( V_8 )
goto V_130;
V_7 -> V_66 . V_12 [ 0 ] |= ( 1 << 25 ) ;
if ( V_125 -> V_127 -> V_128 == V_129 )
F_43 ( V_131 , & V_126 -> V_93 ) ;
else
F_28 ( V_131 , & V_126 -> V_93 ) ;
return V_8 ;
V_130:
V_7 -> V_66 . V_12 [ 0 ] |= ( 2 << 25 ) ;
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_1 V_31 , T_1 V_122 , T_3 V_132 )
{
struct V_6 V_7 ;
struct V_133 V_134 ;
T_3 * V_135 ;
int V_8 ;
T_2 * V_136 ;
int V_44 ;
if ( F_2 ( & V_7 , V_2 , V_137 ) )
return - V_10 ;
V_44 = F_7 ( V_2 , V_31 ) ;
if ( V_44 < 0 ) {
V_8 = - V_48 ;
goto V_64;
}
if ( V_122 )
V_132 = ( ( V_132 == V_138 || V_132 == V_139 ) ?
V_139 : V_140 ) ;
V_7 . V_11 . V_12 [ 1 ] = V_132 | ( 1 << 8 ) | ( 3 << 6 ) ;
V_7 . V_11 . V_12 [ 1 ] |= ( ( V_44 & 0xffff ) << 16 ) | V_141 ;
V_135 = V_47 -> V_142 ;
V_134 . V_122 = V_122 ;
V_134 . V_143 = V_135 [ 0 ] ;
V_134 . V_144 = V_135 [ 1 ] ;
V_134 . V_145 = V_135 [ 2 ] ;
V_134 . V_146 = V_135 [ 3 ] ;
V_134 . V_147 = V_135 [ 4 ] ;
V_134 . V_148 = V_135 [ 5 ] ;
V_136 = & V_7 . V_11 . V_12 [ 2 ] ;
memcpy ( V_136 , & V_134 , sizeof( struct V_133 ) ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_22 ,
( ( V_132 == 1 ) ? L_23 : L_24 ) , V_8 ) ;
V_64:
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_54 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
return 0 ;
}
static int F_55 ( struct V_124 * V_149 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_149 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_150 * V_151 ;
int V_8 ;
T_1 V_122 ;
V_8 = F_54 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 6 ] = V_126 -> V_47 -> V_71 ;
V_8 = F_3 ( V_2 , V_7 ) ;
V_122 = V_126 -> V_47 -> V_122 ;
if ( ! V_8 ) {
V_151 = (struct V_150 * ) & V_7 -> V_66 . V_12 [ 1 ] ;
V_126 -> V_152 = V_151 -> V_153 ;
F_53 ( V_2 , V_126 -> V_47 , V_126 -> V_52 ,
V_122 , V_138 ) ;
} else {
V_126 -> V_152 = 0 ;
}
return V_8 ;
}
static int F_56 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
T_3 type , * V_142 ;
type = V_7 -> V_11 . V_12 [ 1 ] ;
switch ( type ) {
case V_154 :
case V_155 :
V_7 -> V_66 . V_12 [ 0 ] = ( 2 << 25 ) ;
break;
case V_156 :
V_7 -> V_66 . V_12 [ 0 ] = ( 1 << 25 ) ;
V_142 = V_126 -> V_47 -> V_142 ;
V_7 -> V_66 . V_12 [ 2 ] = V_142 [ 1 ] | ( ( V_142 [ 0 ] << 8 ) & 0xff00 ) ;
V_7 -> V_66 . V_12 [ 1 ] = V_142 [ 5 ] | ( ( V_142 [ 4 ] << 8 ) & 0xff00 ) |
( ( V_142 [ 3 ] ) << 16 & 0xff0000 ) |
( ( V_142 [ 2 ] ) << 24 & 0xff000000 ) ;
}
return 0 ;
}
static int F_57 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
return 0 ;
}
static int F_58 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_157 * V_151 ;
int V_8 ;
V_8 = F_57 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 5 ] |= V_126 -> V_47 -> V_71 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_151 = (struct V_157 * ) & V_7 -> V_66 . V_12 [ 2 ] ;
V_126 -> V_158 = V_151 -> V_153 ;
} else {
V_126 -> V_158 = 0 ;
}
return V_8 ;
}
static int F_59 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_126 -> V_152 )
return - V_48 ;
return 0 ;
}
static int F_60 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
T_1 V_122 ;
V_8 = F_59 ( V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_122 = V_126 -> V_47 -> V_122 ;
F_53 ( V_2 , V_126 -> V_47 , V_126 -> V_52 ,
V_122 , V_159 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_126 -> V_47 -> V_71 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_126 -> V_152 = 0 ;
return V_8 ;
}
static int F_61 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_126 -> V_158 )
return - V_48 ;
return 0 ;
}
static int F_62 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_61 ( V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 1 ] |= V_126 -> V_47 -> V_71 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_126 -> V_158 = 0 ;
return V_8 ;
}
static int F_63 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_126 -> V_152 )
return - V_48 ;
return 0 ;
}
static int F_64 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_63 ( V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_65 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 = - V_43 ;
T_3 V_132 ;
V_132 = V_7 -> V_11 . V_12 [ 1 ] & 0xff ;
V_7 -> V_11 . V_12 [ 1 ] |= V_126 -> V_47 -> V_71 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_141 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_66 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 8 ) & 0xff ) != V_126 -> V_52 )
return - V_48 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_77 ) )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xff ) != 0x1 )
return - V_48 ;
return 0 ;
}
static int F_67 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_66 ( V_126 , V_7 ) ;
if ( V_8 )
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_126 -> V_152 )
return - V_48 ;
if ( V_7 -> V_11 . V_12 [ 2 ] > V_2 -> V_34 -> V_107 )
return - V_48 ;
return 0 ;
}
static int F_69 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_68 ( V_2 , V_126 , V_7 ) ;
if ( V_8 )
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_70 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] & V_141 ) {
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) & 0x7fff ) != V_126 -> V_52 )
return - V_48 ;
} else {
V_7 -> V_11 . V_12 [ 1 ] |= V_126 -> V_47 -> V_71 << 16 ;
}
return 0 ;
}
static int F_71 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_70 ( V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_72 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_126 -> V_152 )
return - V_48 ;
return 0 ;
}
static int F_73 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_72 ( V_126 , V_7 ) ;
if ( V_8 )
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_73 * V_126 ,
struct V_6 * V_7 )
{
struct V_160 * V_161 = & V_2 -> V_34 -> V_161 ;
T_1 V_153 , V_162 , time ;
V_153 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_162 = V_7 -> V_11 . V_12 [ 2 ] & 0xffff ;
time = V_7 -> V_11 . V_12 [ 2 ] >> 16 ;
if ( V_153 != V_126 -> V_152 )
return - V_48 ;
if ( V_162 > V_161 -> V_163 )
return - V_48 ;
if ( time < V_161 -> V_164 )
return - V_48 ;
return 0 ;
}
static int F_75 ( struct V_124 * V_149 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_149 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_74 ( V_2 , V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_73 * V_126 ,
struct V_6 * V_7 )
{
struct V_133 * V_165 ;
struct V_46 * V_47 = V_126 -> V_47 ;
T_3 V_132 , V_166 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_167 ) )
return - V_48 ;
V_7 -> V_11 . V_12 [ 1 ] |= ( V_126 -> V_47 -> V_71 << 16 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_141 ;
V_165 = (struct V_133 * ) & V_7 -> V_11 . V_12 [ 2 ] ;
if ( ! ( V_165 -> V_143 & V_81 ) ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_25 ,
V_126 -> V_52 ) ;
return - V_48 ;
}
if ( V_47 -> V_120 == V_121 ) {
V_132 = V_7 -> V_11 . V_12 [ 1 ] & 0x7 ;
V_7 -> V_11 . V_12 [ 1 ] &= ~ 0x7 ;
V_166 = ( V_132 == V_138 || V_132 == V_139 ) ?
V_139 : V_140 ;
V_7 -> V_11 . V_12 [ 3 ] |= V_47 -> V_122 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_166 ;
}
return 0 ;
}
static int F_77 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_76 ( V_2 , V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_78 ( struct V_73 * V_126 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_126 -> V_152 )
return - V_48 ;
return 0 ;
}
static int F_79 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_8 = F_78 ( V_126 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_80 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
int V_8 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_126 -> V_47 -> V_71 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_141 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_81 ( struct V_124 * V_125 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_125 -> V_126 ;
struct V_46 * V_47 = V_126 -> V_47 ;
T_3 V_128 , V_168 = V_47 -> V_120 ;
V_128 = V_125 -> V_127 -> V_128 ;
V_7 -> V_66 . V_12 [ 0 ] = ( V_128 & 0xffff ) | 14 << 16 | 1 << 25 ;
switch ( V_168 ) {
case V_169 :
V_7 -> V_66 . V_12 [ 1 ] = V_168 | 1 << 8 ;
V_7 -> V_66 . V_12 [ 2 ] = 1 << 16 ;
break;
case V_121 :
V_7 -> V_66 . V_12 [ 1 ] = V_168 | 1 << 8 | V_47 -> V_122 << 16 ;
break;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_73 * V_126 )
{
struct V_46 * V_47 = V_126 -> V_47 ;
if ( ! V_47 -> V_122 )
return - V_48 ;
if ( ! V_126 -> V_152 ) {
V_47 -> V_122 = 0 ;
return 0 ;
}
F_53 ( V_2 , V_47 , V_126 -> V_52 ,
V_47 -> V_122 , V_159 ) ;
V_47 -> V_122 = 0 ;
F_53 ( V_2 , V_47 , V_126 -> V_52 ,
0 , V_138 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_73 * V_126 ,
struct V_6 * V_7 )
{
struct V_46 * V_47 = V_126 -> V_47 ;
int V_8 = - V_43 ;
if ( V_47 -> V_122 )
return V_8 ;
if ( ! V_126 -> V_152 ) {
V_47 -> V_122 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
return 0 ;
}
V_8 = F_53 ( V_2 , V_47 , V_126 -> V_52 ,
0 , V_159 ) ;
if ( V_8 )
return V_8 ;
V_47 -> V_122 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_8 = F_53 ( V_2 , V_47 , V_126 -> V_52 ,
V_47 -> V_122 , V_138 ) ;
if ( V_8 ) {
F_53 ( V_2 , V_47 , V_126 -> V_52 ,
0 , V_138 ) ;
V_47 -> V_122 = 0 ;
}
return V_8 ;
}
static int F_84 ( struct V_124 * V_149 ,
struct V_6 * V_7 )
{
struct V_73 * V_126 = V_149 -> V_126 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_46 * V_47 = V_126 -> V_47 ;
int V_8 = - V_43 ;
T_3 V_132 ;
if ( V_47 -> V_120 != V_169 ) {
V_7 -> V_66 . V_12 [ 0 ] |= 2 << 25 ;
return V_8 ;
}
V_132 = V_7 -> V_11 . V_12 [ 1 ] & 0xf ;
if ( V_132 )
V_8 = F_83 ( V_2 , V_126 , V_7 ) ;
else
V_8 = F_82 ( V_2 , V_126 ) ;
V_7 -> V_66 . V_12 [ 0 ] |= V_8 ? 2 << 25 : 1 << 25 ;
return V_8 ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_6 * V_7 )
{
T_3 V_170 , V_128 ;
V_128 = V_125 -> V_127 -> V_128 ;
if ( V_125 -> V_127 -> V_171 == V_172 ) {
V_170 = F_86 ( V_173 ) ;
if ( V_128 < V_170 ) {
V_173 [ V_128 ] . F_87 ( V_125 , V_7 ) ;
return;
}
} else {
int V_85 ;
V_170 = F_86 ( V_174 ) ;
for ( V_85 = 0 ; V_85 < V_170 ; V_85 ++ ) {
if ( V_128 == V_174 [ V_85 ] . V_7 ) {
V_174 [ V_85 ] . F_87 ( V_125 , V_7 ) ;
return;
}
}
V_170 = F_86 ( V_175 ) ;
for ( V_85 = 0 ; V_85 < V_170 ; V_85 ++ ) {
if ( V_128 == V_175 [ V_85 ] ) {
F_3 ( V_2 , V_7 ) ;
return;
}
}
}
V_7 -> V_66 . V_12 [ 0 ] |= ( 0x9 << 25 ) ;
}
void F_88 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= V_44 ;
}
void F_89 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= V_44 << 16 ;
}
void F_90 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
int V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= V_44 << 16 ;
}
void F_91 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= V_44 << 16 ;
}
void F_92 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= ( V_44 << 16 ) | V_141 ;
}
void F_93 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= ( V_44 << 16 ) | V_141 ;
}
void F_94 ( struct V_1 * V_2 ,
T_2 * V_176 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_176 |= ( V_44 << 16 ) | V_141 ;
}
static void F_95 ( struct V_1 * V_2 ,
struct V_73 * V_126 )
{
struct V_6 V_7 ;
int V_44 ;
if ( ! V_126 -> V_152 )
return;
if ( F_2 ( & V_7 , V_2 , V_177 ) )
return;
V_44 = F_7 ( V_2 , V_126 -> V_52 ) ;
if ( V_44 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] = V_126 -> V_152 | ( V_44 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_26 ,
V_126 -> V_52 ) ;
else
V_126 -> V_152 = 0 ;
}
F_5 ( & V_7 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_73 * V_126 )
{
struct V_6 V_7 ;
int V_44 ;
if ( ! V_126 -> V_158 )
return;
if ( F_2 ( & V_7 , V_2 , V_178 ) )
return;
V_44 = F_7 ( V_2 , V_126 -> V_52 ) ;
if ( V_44 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_126 -> V_158 | ( V_44 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_26 ,
V_126 -> V_52 ) ;
else
V_126 -> V_158 = 0 ;
}
F_5 ( & V_7 ) ;
}
static int F_97 ( struct V_32 * V_33 ,
struct V_73 * V_126 ,
struct V_124 * V_125 )
{
struct V_179 * V_180 = & V_126 -> V_181 ;
unsigned long V_74 ;
F_98 ( & V_180 -> V_182 , V_74 ) ;
F_99 ( V_33 , V_126 , V_125 ) ;
F_100 ( & V_180 -> V_182 , V_74 ) ;
return 0 ;
}
static void F_101 ( struct V_73 * V_126 )
{
struct V_1 * V_2 = V_126 -> V_2 ;
F_102 ( & V_126 -> V_183 ) ;
F_20 ( & V_126 -> V_184 ) ;
F_102 ( & V_126 -> V_181 ) ;
if ( F_103 ( V_185 , & V_126 -> V_93 ) ) {
F_96 ( V_2 , V_126 ) ;
F_95 ( V_2 , V_126 ) ;
}
F_16 ( V_2 , 0 , V_126 -> V_52 ) ;
F_28 ( V_186 , & V_126 -> V_93 ) ;
if ( F_103 ( V_185 , & V_126 -> V_93 ) ) {
F_97 ( V_2 -> V_34 -> V_33 , V_126 ,
V_126 -> V_187 ) ;
F_28 ( V_185 , & V_126 -> V_93 ) ;
V_126 -> V_187 = NULL ;
}
}
static void F_104 ( struct V_188 * V_189 )
{
struct V_73 * V_126 ;
V_126 = F_105 ( V_189 , struct V_73 , V_86 ) ;
F_101 ( V_126 ) ;
return;
}
static void F_106 ( struct V_32 * V_33 ,
struct V_73 * V_126 ,
T_4 V_31 )
{
if ( F_103 ( V_118 , & V_126 -> V_2 -> V_93 ) )
return;
F_107 ( & V_126 -> V_86 , V_31 ) ;
F_108 ( V_33 -> V_84 . V_87 , & V_126 -> V_86 ) ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_73 * V_126 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
F_43 ( V_186 , & V_126 -> V_93 ) ;
F_28 ( V_131 , & V_126 -> V_93 ) ;
F_43 ( V_185 , & V_126 -> V_93 ) ;
V_126 -> V_187 = V_125 ;
F_106 ( V_33 , V_126 , F_104 ) ;
F_32 ( V_2 -> V_94 , L_27 ,
V_126 -> V_52 ) ;
}
bool F_110 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_73 * V_126 )
{
struct V_190 * V_191 = V_125 -> V_127 ;
if ( ( V_191 -> V_128 == V_129 ) &&
( V_191 -> V_171 == V_172 ) &&
F_103 ( V_131 , & V_126 -> V_93 ) ) {
F_109 ( V_2 , V_125 , V_126 ) ;
return true ;
}
return false ;
}
void F_111 ( struct V_32 * V_33 ,
struct V_73 * V_126 )
{
struct V_96 * V_29 = V_126 -> V_2 -> V_94 ;
if ( ! F_112 ( V_131 , & V_126 -> V_93 ) ) {
F_28 ( V_186 , & V_126 -> V_93 ) ;
return;
}
if ( F_49 ( V_186 , & V_126 -> V_93 ) ) {
F_32 ( V_29 , L_28 ,
V_126 -> V_52 ) ;
return;
}
F_106 ( V_33 , V_126 , F_104 ) ;
F_32 ( V_29 , L_29 , V_126 -> V_52 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_97 * V_34 = V_2 -> V_34 ;
struct V_32 * V_33 = V_34 -> V_33 ;
struct V_73 * V_126 ;
T_1 V_40 = V_33 -> V_40 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_40 ; V_85 ++ ) {
V_126 = & V_33 -> V_55 [ V_85 ] ;
V_126 -> V_152 = 0 ;
V_126 -> V_158 = 0 ;
F_20 ( & V_126 -> V_86 ) ;
F_101 ( V_126 ) ;
F_28 ( V_131 , & V_126 -> V_93 ) ;
}
F_14 ( V_2 , V_34 -> V_52 ) ;
F_114 ( V_34 , V_192 , ( V_34 -> V_193 - 1 ) << 8 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_97 * V_34 = V_2 -> V_34 ;
int V_8 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_34 -> V_90 = V_111 ;
V_8 = F_38 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_13 ( & V_2 -> V_28 -> V_29 , L_30 ,
V_194 , V_34 -> V_90 ) ;
return V_8 ;
}
int F_116 ( struct V_96 * V_94 , int V_126 , T_3 * V_142 )
{
struct V_1 * V_2 = F_117 ( V_94 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_85 , V_40 = V_33 -> V_40 ;
struct V_73 * V_55 ;
T_3 * V_195 ;
if ( ! F_30 ( V_2 ) )
return - V_196 ;
if ( ! F_118 ( V_142 ) || V_126 >= V_40 )
return - V_48 ;
if ( ! F_119 ( V_2 -> V_197 , V_142 ) ) {
F_46 ( V_94 , L_31 ) ;
return - V_48 ;
}
for ( V_85 = 0 ; V_85 < V_40 ; V_85 ++ ) {
V_55 = & V_33 -> V_55 [ V_85 ] ;
if ( ! F_119 ( V_55 -> V_47 -> V_142 , V_142 ) ) {
F_46 ( V_94 ,
L_32 ,
V_85 ) ;
return - V_48 ;
}
}
V_55 = & V_33 -> V_55 [ V_126 ] ;
V_195 = V_55 -> V_47 -> V_142 ;
if ( F_103 ( V_131 , & V_55 -> V_93 ) ) {
F_46 ( V_94 ,
L_33 ,
V_126 ) ;
return - V_196 ;
}
memcpy ( V_195 , V_142 , V_94 -> V_198 ) ;
F_32 ( V_94 , L_34 ,
V_142 , V_126 ) ;
return 0 ;
}
int F_120 ( struct V_96 * V_94 , int V_126 , int V_199 )
{
struct V_1 * V_2 = F_117 ( V_94 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_73 * V_55 ;
struct V_3 V_98 ;
struct V_46 * V_47 ;
T_1 V_44 ;
if ( ! F_30 ( V_2 ) )
return - V_196 ;
if ( V_126 >= V_33 -> V_40 )
return - V_48 ;
if ( V_199 >= 10000 || V_199 < 100 ) {
F_46 ( V_94 ,
L_35 ,
V_200 , V_201 ) ;
return - V_48 ;
}
if ( V_199 == 0 )
V_199 = 10000 ;
V_55 = & V_33 -> V_55 [ V_126 ] ;
V_47 = V_55 -> V_47 ;
V_44 = V_47 -> V_71 ;
if ( F_103 ( V_131 , & V_55 -> V_93 ) ) {
if ( F_121 ( V_2 , & V_98 , V_44 ) )
return - V_43 ;
V_98 . V_15 = V_199 / 100 ;
V_98 . V_13 = V_81 ;
if ( F_1 ( V_2 , & V_98 , V_44 ) )
return - V_43 ;
}
V_47 -> V_15 = V_199 / 100 ;
F_32 ( V_94 ,
L_36 ,
V_199 , V_47 -> V_15 , V_126 ) ;
return 0 ;
}
int F_122 ( struct V_96 * V_94 , int V_126 ,
T_1 V_122 , T_3 V_202 )
{
struct V_1 * V_2 = F_117 ( V_94 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_73 * V_55 ;
struct V_46 * V_47 ;
if ( ! F_30 ( V_2 ) )
return - V_196 ;
if ( V_126 >= V_33 -> V_40 || V_202 > 7 )
return - V_48 ;
if ( V_122 > V_203 ) {
F_46 ( V_94 ,
L_37 ,
V_203 ) ;
return - V_48 ;
}
V_55 = & V_33 -> V_55 [ V_126 ] ;
V_47 = V_55 -> V_47 ;
if ( F_103 ( V_131 , & V_55 -> V_93 ) ) {
F_46 ( V_94 ,
L_38 ,
V_126 ) ;
return - V_196 ;
}
switch ( V_122 ) {
case 4095 :
V_47 -> V_120 = V_169 ;
break;
case 0 :
V_47 -> V_120 = V_204 ;
V_47 -> V_122 = 0 ;
V_47 -> V_202 = 0 ;
break;
default:
V_47 -> V_120 = V_121 ;
V_47 -> V_122 = V_122 ;
V_47 -> V_202 = V_202 ;
}
F_32 ( V_94 , L_39 ,
V_122 , V_202 , V_126 ) ;
return 0 ;
}
int F_123 ( struct V_96 * V_94 ,
int V_126 , struct V_205 * V_206 )
{
struct V_1 * V_2 = F_117 ( V_94 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
if ( ! F_30 ( V_2 ) )
return - V_196 ;
if ( V_126 >= V_33 -> V_40 )
return - V_48 ;
V_47 = V_33 -> V_55 [ V_126 ] . V_47 ;
memcpy ( & V_206 -> V_142 , V_47 -> V_142 , V_207 ) ;
V_206 -> V_122 = V_47 -> V_122 ;
V_206 -> V_202 = V_47 -> V_202 ;
if ( V_47 -> V_15 == V_54 )
V_206 -> V_199 = 0 ;
else
V_206 -> V_199 = V_47 -> V_15 * 100 ;
V_206 -> V_126 = V_126 ;
return 0 ;
}
