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
V_30 -> V_18 = V_36 -> V_49 ;
V_39 = V_50 ;
if ( V_2 -> V_34 -> V_51 == V_31 ) {
V_38 = V_36 -> V_49 - ( V_40 * V_39 ) ;
V_30 -> V_19 = V_38 ;
V_38 = V_36 -> V_52 - ( V_40 * V_39 ) ;
V_30 -> V_17 = V_38 ;
V_30 -> V_14 = 0 ;
V_30 -> V_15 = V_53 ;
V_30 -> V_16 = V_36 -> V_54 - V_33 -> V_40 ;
} else {
V_45 = F_8 ( V_2 , V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_47 = V_33 -> V_55 [ V_45 ] . V_47 ;
V_30 -> V_14 = V_47 -> V_14 ;
V_30 -> V_15 = V_47 -> V_15 ;
V_30 -> V_19 = V_39 ;
V_30 -> V_17 = V_39 ;
V_30 -> V_16 = V_56 ;
}
V_30 -> V_20 = V_36 -> V_57 / V_41 ;
V_30 -> V_22 = V_36 -> V_58 / V_41 ;
V_30 -> V_23 = V_36 -> V_59 / V_41 ;
V_30 -> V_24 = V_36 -> V_60 / V_41 ;
V_30 -> V_21 = V_36 -> V_61 / V_41 ;
V_30 -> V_25 = V_36 -> V_62 ;
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
V_37 -> V_52 = V_30 -> V_17 ;
V_37 -> V_63 = V_30 -> V_19 ;
V_37 -> V_49 = V_30 -> V_18 ;
V_37 -> V_62 = V_30 -> V_25 ;
V_37 -> V_60 = V_30 -> V_24 ;
V_37 -> V_54 = V_30 -> V_16 ;
V_37 -> V_61 = V_30 -> V_21 ;
V_37 -> V_57 = V_30 -> V_20 ;
V_37 -> V_59 = V_30 -> V_23 ;
V_37 -> V_58 = V_30 -> V_22 ;
V_37 -> V_27 = V_30 -> V_27 ;
V_37 -> V_26 = V_30 -> V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
struct V_6 V_7 ;
if ( F_2 ( & V_7 , V_2 , V_64 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 1 ] = 0x2 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_2 , V_8 ) ;
goto V_65;
}
V_4 -> V_66 = V_7 . V_67 . V_12 [ 2 ] & 0xff ;
V_4 -> V_68 = ( V_7 . V_67 . V_12 [ 2 ] >> 8 ) & 0xff ;
V_4 -> V_69 = F_11 ( V_7 . V_67 . V_12 [ 2 ] ) ;
V_4 -> V_16 = F_12 ( V_7 . V_67 . V_12 [ 3 ] ) ;
V_4 -> V_17 = F_11 ( V_7 . V_67 . V_12 [ 3 ] ) ;
V_4 -> V_18 = F_12 ( V_7 . V_67 . V_12 [ 4 ] ) ;
V_4 -> V_19 = F_11 ( V_7 . V_67 . V_12 [ 4 ] ) ;
V_4 -> V_20 = F_12 ( V_7 . V_67 . V_12 [ 5 ] ) ;
V_4 -> V_21 = F_11 ( V_7 . V_67 . V_12 [ 5 ] ) ;
V_4 -> V_22 = F_12 ( V_7 . V_67 . V_12 [ 6 ] ) ;
V_4 -> V_23 = F_11 ( V_7 . V_67 . V_12 [ 6 ] ) ;
V_4 -> V_24 = F_12 ( V_7 . V_67 . V_12 [ 7 ] ) ;
V_4 -> V_25 = F_11 ( V_7 . V_67 . V_12 [ 7 ] ) ;
V_4 -> V_26 = F_12 ( V_7 . V_67 . V_12 [ 8 ] ) ;
V_4 -> V_27 = F_11 ( V_7 . V_67 . V_12 [ 8 ] ) ;
F_9 ( V_2 , V_4 ) ;
F_13 ( & V_2 -> V_28 -> V_29 ,
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
V_4 -> V_66 , V_4 -> V_68 ,
V_4 -> V_69 , V_4 -> V_16 ,
V_4 -> V_17 ,
V_4 -> V_18 ,
V_4 -> V_19 , V_4 -> V_20 ,
V_4 -> V_21 , V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_24 ,
V_4 -> V_25 , V_4 -> V_26 ,
V_4 -> V_27 ) ;
V_65:
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
int V_70 ;
if ( V_2 -> V_34 -> V_51 == V_31 ) {
V_33 -> V_71 = 0 ;
} else {
V_70 = F_8 ( V_2 , V_31 ) ;
if ( V_70 < 0 )
return;
V_47 = V_33 -> V_55 [ V_70 ] . V_47 ;
V_47 -> V_72 = 0 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_73 , T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
int V_70 ;
if ( V_2 -> V_34 -> V_51 == V_31 ) {
V_33 -> V_71 = V_73 ;
} else {
V_70 = F_8 ( V_2 , V_31 ) ;
if ( V_70 < 0 )
return;
V_47 = V_33 -> V_55 [ V_70 ] . V_47 ;
V_47 -> V_72 = V_73 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_74 * V_55 ;
int V_70 ;
if ( V_2 -> V_34 -> V_51 == V_31 ) {
return V_33 -> V_71 ;
} else {
V_70 = F_8 ( V_2 , V_31 ) ;
if ( V_70 >= 0 ) {
V_55 = & V_33 -> V_55 [ V_70 ] ;
return V_55 -> V_47 -> V_72 ;
}
}
return - V_48 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_75 , T_1 V_31 )
{
struct V_6 V_7 ;
int V_42 ;
int V_44 ;
if ( F_2 ( & V_7 , V_2 , V_76 ) )
return - V_10 ;
if ( V_75 ) {
V_7 . V_11 . V_12 [ 3 ] = V_31 << 8 ;
} else {
V_44 = F_7 ( V_2 , V_31 ) ;
if ( V_44 < 0 ) {
V_42 = - V_48 ;
goto V_65;
}
V_7 . V_11 . V_12 [ 3 ] = ( ( V_44 & 0xffff ) << 8 ) | 1 ;
}
V_42 = F_3 ( V_2 , & V_7 ) ;
if ( V_42 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_10 ,
( V_75 ? L_11 : L_12 ) , V_42 , V_31 ) ;
goto V_65;
}
if ( V_75 ) {
V_44 = V_7 . V_67 . V_12 [ 2 ] & 0xffff ;
F_15 ( V_2 , V_44 , V_31 ) ;
} else {
F_14 ( V_2 , V_31 ) ;
}
V_65:
F_5 ( & V_7 ) ;
return V_42 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_77 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x4 ;
if ( V_77 )
V_7 . V_11 . V_12 [ 1 ] |= V_78 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_13 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_31 , T_3 V_77 )
{
struct V_6 V_7 ;
int V_8 = - V_43 ;
if ( F_2 ( & V_7 , V_2 , V_79 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 0 ] |= ( 3 << 29 ) ;
V_7 . V_11 . V_12 [ 1 ] = ( ( V_31 & 0xf ) << 2 ) | V_80 | V_81 ;
if ( V_77 )
V_7 . V_11 . V_12 [ 1 ] |= V_82 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 != V_83 ) {
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
struct V_84 * V_85 = & V_33 -> V_85 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_33 -> V_40 ; V_86 ++ )
F_20 ( & V_33 -> V_55 [ V_86 ] . V_87 ) ;
F_21 ( V_85 -> V_88 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = & V_2 -> V_34 -> V_33 -> V_85 ;
struct V_89 * V_90 ;
V_90 = F_23 ( L_15 ) ;
if ( V_90 == NULL ) {
F_4 ( & V_2 -> V_28 -> V_29 , L_16 ) ;
return - V_10 ;
}
V_85 -> V_88 = V_90 ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
T_3 V_31 = V_2 -> V_34 -> V_51 ;
if ( ! F_25 ( V_2 ) )
return;
F_19 ( V_2 ) ;
F_26 ( V_2 , 0 ) ;
F_16 ( V_2 , 0 , V_31 ) ;
F_18 ( V_2 , V_31 , 0 ) ;
F_17 ( V_2 , 0 ) ;
F_27 ( V_2 ) ;
V_2 -> V_34 -> V_91 = V_92 ;
F_28 ( V_93 , & V_2 -> V_94 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( ! F_30 ( V_2 ) )
return;
if ( ! F_25 ( V_2 ) )
return;
F_31 ( V_2 -> V_28 ) ;
F_32 ( V_2 -> V_95 ,
L_17 ,
V_2 -> V_96 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_97 * V_95 = V_2 -> V_95 ;
F_34 () ;
if ( F_35 ( V_95 ) )
F_36 ( V_2 , V_95 ) ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
F_38 () ;
return - V_43 ;
}
if ( F_35 ( V_95 ) )
F_39 ( V_2 , V_95 ) ;
F_38 () ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_98 * V_34 = V_2 -> V_34 ;
struct V_3 V_99 , V_100 , V_101 ;
int V_8 ;
T_3 V_31 = V_34 -> V_51 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_8 = F_17 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 , V_31 , 1 ) ;
if ( V_8 )
goto V_102;
V_8 = F_16 ( V_2 , 1 , V_31 ) ;
if ( V_8 )
goto V_103;
V_8 = F_10 ( V_2 , & V_100 ) ;
if ( V_8 )
goto V_104;
V_8 = F_41 ( V_2 , & V_99 , V_31 ) ;
if ( V_8 )
goto V_104;
V_8 = F_6 ( V_2 , & V_101 , V_31 ) ;
if ( V_8 )
goto V_104;
V_8 = F_26 ( V_2 , 1 ) ;
if ( V_8 )
goto V_104;
V_34 -> V_105 = ( T_3 ) V_99 . V_106 ;
V_34 -> V_107 = V_99 . V_107 ;
V_34 -> V_108 = V_99 . V_108 ;
V_34 -> V_109 = V_99 . V_109 ;
V_34 -> V_110 = V_111 ;
return V_8 ;
V_104:
F_16 ( V_2 , 0 , V_31 ) ;
V_103:
F_18 ( V_2 , V_31 , 0 ) ;
V_102:
F_17 ( V_2 , 0 ) ;
return V_8 ;
}
static int F_42 ( struct V_1 * V_2 , int V_40 )
{
int V_8 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_8 = F_43 ( V_2 -> V_28 , V_40 ) ;
if ( V_8 )
F_24 ( V_2 ) ;
return V_8 ;
}
static int F_44 ( struct V_1 * V_2 ,
int V_40 )
{
int V_8 = 0 ;
F_45 ( V_93 , & V_2 -> V_94 ) ;
V_2 -> V_34 -> V_91 = V_112 ;
V_8 = F_46 ( V_2 , V_40 ) ;
if ( V_8 )
goto V_113;
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
goto V_114;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
goto V_115;
V_8 = F_42 ( V_2 , V_40 ) ;
return V_8 ;
V_115:
F_19 ( V_2 ) ;
V_114:
F_27 ( V_2 ) ;
V_113:
F_28 ( V_93 , & V_2 -> V_94 ) ;
V_2 -> V_34 -> V_91 = V_92 ;
return V_8 ;
}
static int F_47 ( struct V_1 * V_2 , int V_40 )
{
struct V_97 * V_95 = V_2 -> V_95 ;
int V_8 ;
if ( ! ( V_2 -> V_116 & V_117 ) ) {
F_48 ( V_95 ,
L_18 ) ;
return - V_43 ;
}
F_34 () ;
if ( F_35 ( V_95 ) )
F_36 ( V_2 , V_95 ) ;
V_8 = F_44 ( V_2 , V_40 ) ;
if ( V_8 ) {
F_32 ( V_95 , L_19 ,
V_2 -> V_96 ) ;
V_8 = - V_43 ;
if ( F_37 ( V_2 ) )
goto error;
} else {
F_32 ( V_95 ,
L_20 ,
V_2 -> V_96 ) ;
V_8 = V_40 ;
}
if ( F_35 ( V_95 ) )
F_39 ( V_2 , V_95 ) ;
error:
F_38 () ;
return V_8 ;
}
int F_49 ( struct V_118 * V_29 , int V_40 )
{
struct V_1 * V_2 = F_50 ( V_29 ) ;
int V_8 ;
if ( F_51 ( V_119 , & V_2 -> V_94 ) )
return - V_120 ;
if ( V_40 == 0 )
V_8 = F_33 ( V_2 ) ;
else
V_8 = F_47 ( V_2 , V_40 ) ;
F_28 ( V_119 , & V_2 -> V_94 ) ;
return V_8 ;
}
static int F_52 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_6 V_7 ;
struct V_46 * V_47 ;
int V_8 , V_45 ;
T_3 * V_121 ;
V_45 = F_8 ( V_2 , V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_47 = V_2 -> V_34 -> V_33 -> V_55 [ V_45 ] . V_47 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x3 | V_31 << 16 ;
if ( V_47 -> V_122 == true ) {
V_121 = V_47 -> V_121 ;
V_7 . V_11 . V_12 [ 2 ] |= V_81 | V_123 | V_124 ;
V_7 . V_11 . V_12 [ 4 ] = V_121 [ 5 ] | V_121 [ 4 ] << 8 | V_121 [ 3 ] << 16 |
V_121 [ 2 ] << 24 ;
V_7 . V_11 . V_12 [ 5 ] = V_121 [ 1 ] | V_121 [ 0 ] << 8 ;
}
if ( V_47 -> V_125 == V_126 ) {
V_7 . V_11 . V_12 [ 2 ] |= V_80 ;
V_7 . V_11 . V_12 [ 3 ] |= V_47 -> V_127 << 8 ;
}
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 , L_21 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_3 V_128 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_128 , V_31 ) ;
if ( V_8 )
return - V_43 ;
V_8 = F_52 ( V_2 , V_31 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_54 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_46 * V_47 = V_131 -> V_47 ;
struct V_1 * V_2 ;
T_1 V_31 = V_131 -> V_51 ;
int V_8 ;
V_2 = V_131 -> V_2 ;
if ( V_130 -> V_132 -> V_133 == V_134 ) {
V_8 = F_16 ( V_2 , 1 , V_31 ) ;
if ( ! V_8 ) {
V_8 = F_53 ( V_2 , V_31 ) ;
if ( V_8 )
F_16 ( V_2 , 0 , V_31 ) ;
}
} else {
if ( V_47 -> V_125 == V_135 )
V_47 -> V_127 = 0 ;
V_8 = F_16 ( V_2 , 0 , V_31 ) ;
}
if ( V_8 )
goto V_136;
V_7 -> V_67 . V_12 [ 0 ] |= ( 1 << 25 ) ;
if ( V_130 -> V_132 -> V_133 == V_134 )
F_45 ( V_137 , & V_131 -> V_94 ) ;
else
F_28 ( V_137 , & V_131 -> V_94 ) ;
return V_8 ;
V_136:
V_7 -> V_67 . V_12 [ 0 ] |= ( 2 << 25 ) ;
return V_8 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_1 V_31 , T_1 V_127 , T_3 V_138 )
{
struct V_6 V_7 ;
struct V_139 V_140 ;
T_3 * V_141 ;
int V_8 ;
T_2 * V_142 ;
int V_44 ;
if ( F_2 ( & V_7 , V_2 , V_143 ) )
return - V_10 ;
V_44 = F_7 ( V_2 , V_31 ) ;
if ( V_44 < 0 ) {
V_8 = - V_48 ;
goto V_65;
}
if ( V_127 )
V_138 = ( ( V_138 == V_144 || V_138 == V_145 ) ?
V_145 : V_146 ) ;
V_7 . V_11 . V_12 [ 1 ] = V_138 | ( 1 << 8 ) | ( 3 << 6 ) ;
V_7 . V_11 . V_12 [ 1 ] |= ( ( V_44 & 0xffff ) << 16 ) | V_147 ;
V_141 = V_47 -> V_121 ;
V_140 . V_127 = V_127 ;
V_140 . V_148 = V_141 [ 0 ] ;
V_140 . V_149 = V_141 [ 1 ] ;
V_140 . V_150 = V_141 [ 2 ] ;
V_140 . V_151 = V_141 [ 3 ] ;
V_140 . V_152 = V_141 [ 4 ] ;
V_140 . V_153 = V_141 [ 5 ] ;
V_142 = & V_7 . V_11 . V_12 [ 2 ] ;
memcpy ( V_142 , & V_140 , sizeof( struct V_139 ) ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_22 ,
( ( V_138 == 1 ) ? L_23 : L_24 ) , V_8 ) ;
V_65:
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_56 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
return 0 ;
}
static int F_57 ( struct V_129 * V_154 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_154 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
struct V_155 * V_156 ;
int V_8 ;
T_1 V_127 ;
V_8 = F_56 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 6 ] = V_131 -> V_47 -> V_72 ;
V_8 = F_3 ( V_2 , V_7 ) ;
V_127 = V_131 -> V_47 -> V_127 ;
if ( ! V_8 ) {
V_156 = (struct V_155 * ) & V_7 -> V_67 . V_12 [ 1 ] ;
V_131 -> V_157 = V_156 -> V_158 ;
F_55 ( V_2 , V_131 -> V_47 , V_131 -> V_51 ,
V_127 , V_144 ) ;
} else {
V_131 -> V_157 = 0 ;
}
return V_8 ;
}
static int F_58 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
T_3 type , * V_121 ;
type = V_7 -> V_11 . V_12 [ 1 ] ;
switch ( type ) {
case V_159 :
case V_160 :
V_7 -> V_67 . V_12 [ 0 ] = ( 2 << 25 ) ;
break;
case V_161 :
V_7 -> V_67 . V_12 [ 0 ] = ( 1 << 25 ) ;
V_121 = V_131 -> V_47 -> V_121 ;
V_7 -> V_67 . V_12 [ 2 ] = V_121 [ 1 ] | ( ( V_121 [ 0 ] << 8 ) & 0xff00 ) ;
V_7 -> V_67 . V_12 [ 1 ] = V_121 [ 5 ] | ( ( V_121 [ 4 ] << 8 ) & 0xff00 ) |
( ( V_121 [ 3 ] ) << 16 & 0xff0000 ) |
( ( V_121 [ 2 ] ) << 24 & 0xff000000 ) ;
}
return 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
return 0 ;
}
static int F_60 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
struct V_162 * V_156 ;
int V_8 ;
V_8 = F_59 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 5 ] |= V_131 -> V_47 -> V_72 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_156 = (struct V_162 * ) & V_7 -> V_67 . V_12 [ 2 ] ;
V_131 -> V_163 = V_156 -> V_158 ;
} else {
V_131 -> V_163 = 0 ;
}
return V_8 ;
}
static int F_61 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_131 -> V_157 )
return - V_48 ;
return 0 ;
}
static int F_62 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
T_1 V_127 ;
V_8 = F_61 ( V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_127 = V_131 -> V_47 -> V_127 ;
F_55 ( V_2 , V_131 -> V_47 , V_131 -> V_51 ,
V_127 , V_164 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_131 -> V_47 -> V_72 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_131 -> V_157 = 0 ;
return V_8 ;
}
static int F_63 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_131 -> V_163 )
return - V_48 ;
return 0 ;
}
static int F_64 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_63 ( V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 1 ] |= V_131 -> V_47 -> V_72 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_131 -> V_163 = 0 ;
return V_8 ;
}
static int F_65 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_131 -> V_157 )
return - V_48 ;
return 0 ;
}
static int F_66 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_65 ( V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_67 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 = - V_43 ;
T_3 V_138 ;
V_138 = V_7 -> V_11 . V_12 [ 1 ] & 0xff ;
V_7 -> V_11 . V_12 [ 1 ] |= V_131 -> V_47 -> V_72 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_147 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_68 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 8 ) & 0xff ) != V_131 -> V_51 )
return - V_48 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_78 ) )
return - V_48 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xff ) != 0x1 )
return - V_48 ;
return 0 ;
}
static int F_69 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_68 ( V_131 , V_7 ) ;
if ( V_8 )
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_131 -> V_157 )
return - V_48 ;
if ( V_7 -> V_11 . V_12 [ 2 ] > V_2 -> V_34 -> V_108 )
return - V_48 ;
return 0 ;
}
static int F_71 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_70 ( V_2 , V_131 , V_7 ) ;
if ( V_8 )
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_72 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] & V_147 ) {
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) & 0x7fff ) != V_131 -> V_51 )
return - V_48 ;
} else {
V_7 -> V_11 . V_12 [ 1 ] |= V_131 -> V_47 -> V_72 << 16 ;
}
return 0 ;
}
static int F_73 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_72 ( V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_74 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_131 -> V_157 )
return - V_48 ;
return 0 ;
}
static int F_75 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_74 ( V_131 , V_7 ) ;
if ( V_8 )
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_74 * V_131 ,
struct V_6 * V_7 )
{
struct V_165 * V_166 = & V_2 -> V_34 -> V_166 ;
T_1 V_158 , V_167 , time ;
V_158 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_167 = V_7 -> V_11 . V_12 [ 2 ] & 0xffff ;
time = V_7 -> V_11 . V_12 [ 2 ] >> 16 ;
if ( V_158 != V_131 -> V_157 )
return - V_48 ;
if ( V_167 > V_166 -> V_168 )
return - V_48 ;
if ( time < V_166 -> V_169 )
return - V_48 ;
return 0 ;
}
static int F_77 ( struct V_129 * V_154 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_154 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_76 ( V_2 , V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_74 * V_131 ,
struct V_6 * V_7 )
{
struct V_139 * V_170 ;
struct V_46 * V_47 = V_131 -> V_47 ;
T_3 V_138 , V_171 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_124 ) )
return - V_48 ;
V_7 -> V_11 . V_12 [ 1 ] |= ( V_131 -> V_47 -> V_72 << 16 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_147 ;
V_170 = (struct V_139 * ) & V_7 -> V_11 . V_12 [ 2 ] ;
if ( ! ( V_170 -> V_148 & V_82 ) ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_25 ,
V_131 -> V_51 ) ;
return - V_48 ;
}
if ( V_47 -> V_125 == V_126 ) {
V_138 = V_7 -> V_11 . V_12 [ 1 ] & 0x7 ;
V_7 -> V_11 . V_12 [ 1 ] &= ~ 0x7 ;
V_171 = ( V_138 == V_144 || V_138 == V_145 ) ?
V_145 : V_146 ;
V_7 -> V_11 . V_12 [ 3 ] |= V_47 -> V_127 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_171 ;
}
return 0 ;
}
static int F_79 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_78 ( V_2 , V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_80 ( struct V_74 * V_131 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_131 -> V_157 )
return - V_48 ;
return 0 ;
}
static int F_81 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_8 = F_80 ( V_131 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_82 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
int V_8 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_131 -> V_47 -> V_72 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_147 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_83 ( struct V_129 * V_130 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_130 -> V_131 ;
struct V_46 * V_47 = V_131 -> V_47 ;
T_3 V_133 , V_172 = V_47 -> V_125 ;
struct V_1 * V_2 ;
V_2 = V_131 -> V_2 ;
V_133 = V_130 -> V_132 -> V_133 ;
V_7 -> V_67 . V_12 [ 0 ] |= 1 << 25 ;
if ( F_84 ( V_2 ) && V_172 == V_126 )
return 0 ;
switch ( V_172 ) {
case V_135 :
V_7 -> V_67 . V_12 [ 1 ] = V_172 | 1 << 8 ;
V_7 -> V_67 . V_12 [ 2 ] = 1 << 16 ;
break;
case V_126 :
V_7 -> V_67 . V_12 [ 1 ] = V_172 | 1 << 8 | V_47 -> V_127 << 16 ;
break;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_74 * V_131 )
{
struct V_46 * V_47 = V_131 -> V_47 ;
if ( ! V_47 -> V_127 )
return - V_48 ;
if ( ! V_131 -> V_157 ) {
V_47 -> V_127 = 0 ;
return 0 ;
}
F_55 ( V_2 , V_47 , V_131 -> V_51 ,
V_47 -> V_127 , V_164 ) ;
V_47 -> V_127 = 0 ;
F_55 ( V_2 , V_47 , V_131 -> V_51 ,
0 , V_144 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_74 * V_131 ,
struct V_6 * V_7 )
{
struct V_46 * V_47 = V_131 -> V_47 ;
int V_8 = - V_43 ;
if ( V_47 -> V_127 )
return V_8 ;
if ( ! V_131 -> V_157 ) {
V_47 -> V_127 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
return 0 ;
}
V_8 = F_55 ( V_2 , V_47 , V_131 -> V_51 ,
0 , V_164 ) ;
if ( V_8 )
return V_8 ;
V_47 -> V_127 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_8 = F_55 ( V_2 , V_47 , V_131 -> V_51 ,
V_47 -> V_127 , V_144 ) ;
if ( V_8 ) {
F_55 ( V_2 , V_47 , V_131 -> V_51 ,
0 , V_144 ) ;
V_47 -> V_127 = 0 ;
}
return V_8 ;
}
static int F_87 ( struct V_129 * V_154 ,
struct V_6 * V_7 )
{
struct V_74 * V_131 = V_154 -> V_131 ;
struct V_1 * V_2 = V_131 -> V_2 ;
struct V_46 * V_47 = V_131 -> V_47 ;
int V_8 = - V_43 ;
T_3 V_138 ;
if ( V_47 -> V_125 != V_135 ) {
V_7 -> V_67 . V_12 [ 0 ] |= 2 << 25 ;
return V_8 ;
}
V_138 = V_7 -> V_11 . V_12 [ 1 ] & 0xf ;
if ( V_138 )
V_8 = F_86 ( V_2 , V_131 , V_7 ) ;
else
V_8 = F_85 ( V_2 , V_131 ) ;
V_7 -> V_67 . V_12 [ 0 ] |= V_8 ? 2 << 25 : 1 << 25 ;
return V_8 ;
}
void F_88 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_6 * V_7 )
{
T_3 V_173 , V_133 ;
V_133 = V_130 -> V_132 -> V_133 ;
if ( V_130 -> V_132 -> V_174 == V_175 ) {
V_173 = F_89 ( V_176 ) ;
if ( V_133 < V_173 ) {
V_176 [ V_133 ] . F_90 ( V_130 , V_7 ) ;
return;
}
} else {
int V_86 ;
V_173 = F_89 ( V_177 ) ;
for ( V_86 = 0 ; V_86 < V_173 ; V_86 ++ ) {
if ( V_133 == V_177 [ V_86 ] . V_7 ) {
V_177 [ V_86 ] . F_90 ( V_130 , V_7 ) ;
return;
}
}
V_173 = F_89 ( V_178 ) ;
for ( V_86 = 0 ; V_86 < V_173 ; V_86 ++ ) {
if ( V_133 == V_178 [ V_86 ] ) {
F_3 ( V_2 , V_7 ) ;
return;
}
}
}
V_7 -> V_67 . V_12 [ 0 ] |= ( 0x9 << 25 ) ;
}
void F_91 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= V_44 ;
}
void F_92 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= V_44 << 16 ;
}
void F_93 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
int V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= V_44 << 16 ;
}
void F_94 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= V_44 << 16 ;
}
void F_95 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= ( V_44 << 16 ) | V_147 ;
}
void F_96 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= ( V_44 << 16 ) | V_147 ;
}
void F_97 ( struct V_1 * V_2 ,
T_2 * V_179 )
{
T_1 V_44 ;
V_44 = F_7 ( V_2 ,
V_2 -> V_34 -> V_51 ) ;
* V_179 |= ( V_44 << 16 ) | V_147 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_74 * V_131 )
{
struct V_6 V_7 ;
int V_44 ;
if ( ! V_131 -> V_157 )
return;
if ( F_2 ( & V_7 , V_2 , V_180 ) )
return;
V_44 = F_7 ( V_2 , V_131 -> V_51 ) ;
if ( V_44 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] = V_131 -> V_157 | ( V_44 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_26 ,
V_131 -> V_51 ) ;
else
V_131 -> V_157 = 0 ;
}
F_5 ( & V_7 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_74 * V_131 )
{
struct V_6 V_7 ;
int V_44 ;
if ( ! V_131 -> V_163 )
return;
if ( F_2 ( & V_7 , V_2 , V_181 ) )
return;
V_44 = F_7 ( V_2 , V_131 -> V_51 ) ;
if ( V_44 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_131 -> V_163 | ( V_44 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_26 ,
V_131 -> V_51 ) ;
else
V_131 -> V_163 = 0 ;
}
F_5 ( & V_7 ) ;
}
static int F_100 ( struct V_32 * V_33 ,
struct V_74 * V_131 ,
struct V_129 * V_130 )
{
struct V_182 * V_183 = & V_131 -> V_184 ;
unsigned long V_75 ;
F_101 ( & V_183 -> V_185 , V_75 ) ;
F_102 ( V_33 , V_131 , V_130 ) ;
F_103 ( & V_183 -> V_185 , V_75 ) ;
return 0 ;
}
static void F_104 ( struct V_74 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_2 ;
F_105 ( & V_131 -> V_186 ) ;
F_20 ( & V_131 -> V_187 ) ;
F_105 ( & V_131 -> V_184 ) ;
if ( F_106 ( V_188 , & V_131 -> V_94 ) ) {
F_99 ( V_2 , V_131 ) ;
F_98 ( V_2 , V_131 ) ;
}
F_16 ( V_2 , 0 , V_131 -> V_51 ) ;
F_28 ( V_189 , & V_131 -> V_94 ) ;
if ( F_106 ( V_188 , & V_131 -> V_94 ) ) {
F_100 ( V_2 -> V_34 -> V_33 , V_131 ,
V_131 -> V_190 ) ;
F_28 ( V_188 , & V_131 -> V_94 ) ;
V_131 -> V_190 = NULL ;
}
}
static void F_107 ( struct V_191 * V_192 )
{
struct V_74 * V_131 ;
V_131 = F_108 ( V_192 , struct V_74 , V_87 ) ;
F_104 ( V_131 ) ;
return;
}
static void F_109 ( struct V_32 * V_33 ,
struct V_74 * V_131 ,
T_4 V_31 )
{
if ( F_106 ( V_119 , & V_131 -> V_2 -> V_94 ) )
return;
F_110 ( & V_131 -> V_87 , V_31 ) ;
F_111 ( V_33 -> V_85 . V_88 , & V_131 -> V_87 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_74 * V_131 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
F_45 ( V_189 , & V_131 -> V_94 ) ;
F_28 ( V_137 , & V_131 -> V_94 ) ;
F_45 ( V_188 , & V_131 -> V_94 ) ;
V_131 -> V_190 = V_130 ;
F_109 ( V_33 , V_131 , F_107 ) ;
F_32 ( V_2 -> V_95 , L_27 ,
V_131 -> V_51 ) ;
}
bool F_113 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_74 * V_131 )
{
struct V_193 * V_194 = V_130 -> V_132 ;
if ( ( V_194 -> V_133 == V_134 ) &&
( V_194 -> V_174 == V_175 ) &&
F_106 ( V_137 , & V_131 -> V_94 ) ) {
F_112 ( V_2 , V_130 , V_131 ) ;
return true ;
}
return false ;
}
void F_114 ( struct V_32 * V_33 ,
struct V_74 * V_131 )
{
struct V_97 * V_29 = V_131 -> V_2 -> V_95 ;
struct V_46 * V_47 = V_131 -> V_47 ;
if ( ! F_115 ( V_137 , & V_131 -> V_94 ) ) {
F_28 ( V_189 , & V_131 -> V_94 ) ;
return;
}
if ( F_51 ( V_189 , & V_131 -> V_94 ) ) {
F_32 ( V_29 , L_28 ,
V_131 -> V_51 ) ;
return;
}
if ( V_47 -> V_125 == V_135 )
V_47 -> V_127 = 0 ;
F_109 ( V_33 , V_131 , F_107 ) ;
F_32 ( V_29 , L_29 , V_131 -> V_51 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
struct V_98 * V_34 = V_2 -> V_34 ;
struct V_32 * V_33 = V_34 -> V_33 ;
struct V_74 * V_131 ;
T_1 V_40 = V_33 -> V_40 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_40 ; V_86 ++ ) {
V_131 = & V_33 -> V_55 [ V_86 ] ;
V_131 -> V_157 = 0 ;
V_131 -> V_163 = 0 ;
F_20 ( & V_131 -> V_87 ) ;
F_104 ( V_131 ) ;
F_28 ( V_137 , & V_131 -> V_94 ) ;
}
F_14 ( V_2 , V_34 -> V_51 ) ;
F_117 ( V_34 , V_195 , ( V_34 -> V_196 - 1 ) << 8 ) ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_98 * V_34 = V_2 -> V_34 ;
int V_8 ;
if ( ! F_25 ( V_2 ) )
return 0 ;
V_34 -> V_91 = V_112 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_13 ( & V_2 -> V_28 -> V_29 , L_30 ,
V_197 , V_34 -> V_91 ) ;
return V_8 ;
}
int F_119 ( struct V_97 * V_95 , int V_131 , T_3 * V_121 )
{
struct V_1 * V_2 = F_120 ( V_95 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_86 , V_40 ;
struct V_74 * V_55 ;
T_3 * V_198 ;
if ( ! F_30 ( V_2 ) )
return - V_199 ;
V_40 = V_33 -> V_40 ;
if ( ! F_121 ( V_121 ) || V_131 >= V_40 )
return - V_48 ;
if ( F_122 ( V_2 -> V_200 , V_121 ) ) {
F_48 ( V_95 , L_31 ) ;
return - V_48 ;
}
for ( V_86 = 0 ; V_86 < V_40 ; V_86 ++ ) {
V_55 = & V_33 -> V_55 [ V_86 ] ;
if ( F_122 ( V_55 -> V_47 -> V_121 , V_121 ) ) {
F_48 ( V_95 ,
L_32 ,
V_86 ) ;
return - V_48 ;
}
}
V_55 = & V_33 -> V_55 [ V_131 ] ;
V_198 = V_55 -> V_47 -> V_121 ;
if ( F_106 ( V_137 , & V_55 -> V_94 ) ) {
F_48 ( V_95 ,
L_33 ,
V_131 ) ;
return - V_199 ;
}
memcpy ( V_198 , V_121 , V_95 -> V_201 ) ;
F_32 ( V_95 , L_34 ,
V_121 , V_131 ) ;
return 0 ;
}
int F_123 ( struct V_97 * V_95 , int V_131 , int V_202 )
{
struct V_1 * V_2 = F_120 ( V_95 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_74 * V_55 ;
struct V_3 V_99 ;
struct V_46 * V_47 ;
T_1 V_44 ;
if ( ! F_30 ( V_2 ) )
return - V_199 ;
if ( V_131 >= V_33 -> V_40 )
return - V_48 ;
if ( V_202 >= 10000 || V_202 < 100 ) {
F_48 ( V_95 ,
L_35 ,
V_203 , V_204 ) ;
return - V_48 ;
}
if ( V_202 == 0 )
V_202 = 10000 ;
V_55 = & V_33 -> V_55 [ V_131 ] ;
V_47 = V_55 -> V_47 ;
V_44 = V_47 -> V_72 ;
if ( F_106 ( V_137 , & V_55 -> V_94 ) ) {
if ( F_124 ( V_2 , & V_99 , V_44 ) )
return - V_43 ;
V_99 . V_15 = V_202 / 100 ;
V_99 . V_13 = V_82 ;
if ( F_1 ( V_2 , & V_99 , V_44 ) )
return - V_43 ;
}
V_47 -> V_15 = V_202 / 100 ;
F_32 ( V_95 ,
L_36 ,
V_202 , V_47 -> V_15 , V_131 ) ;
return 0 ;
}
int F_125 ( struct V_97 * V_95 , int V_131 ,
T_1 V_127 , T_3 V_205 )
{
struct V_1 * V_2 = F_120 ( V_95 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_74 * V_55 ;
struct V_46 * V_47 ;
if ( ! F_30 ( V_2 ) )
return - V_199 ;
if ( V_131 >= V_33 -> V_40 || V_205 > 7 )
return - V_48 ;
if ( V_127 > V_206 ) {
F_48 ( V_95 ,
L_37 ,
V_206 ) ;
return - V_48 ;
}
V_55 = & V_33 -> V_55 [ V_131 ] ;
V_47 = V_55 -> V_47 ;
if ( F_106 ( V_137 , & V_55 -> V_94 ) ) {
F_48 ( V_95 ,
L_38 ,
V_131 ) ;
return - V_199 ;
}
switch ( V_127 ) {
case 4095 :
V_47 -> V_127 = 0 ;
V_47 -> V_125 = V_135 ;
break;
case 0 :
V_47 -> V_125 = V_207 ;
V_47 -> V_127 = 0 ;
V_47 -> V_205 = 0 ;
break;
default:
V_47 -> V_125 = V_126 ;
V_47 -> V_127 = V_127 ;
V_47 -> V_205 = V_205 ;
}
F_32 ( V_95 , L_39 ,
V_127 , V_205 , V_131 ) ;
return 0 ;
}
static T_5 F_126 ( struct V_1 * V_2 ,
struct V_46 * V_47 , int V_131 )
{
T_5 V_127 = 0 ;
switch ( V_47 -> V_125 ) {
case V_126 :
V_127 = V_47 -> V_127 ;
break;
case V_135 :
V_127 = V_206 ;
break;
case V_207 :
V_127 = 0 ;
break;
default:
F_32 ( V_2 -> V_95 , L_40 ,
V_47 -> V_125 , V_131 ) ;
}
return V_127 ;
}
int F_127 ( struct V_97 * V_95 ,
int V_131 , struct V_208 * V_209 )
{
struct V_1 * V_2 = F_120 ( V_95 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_46 * V_47 ;
if ( ! F_30 ( V_2 ) )
return - V_199 ;
if ( V_131 >= V_33 -> V_40 )
return - V_48 ;
V_47 = V_33 -> V_55 [ V_131 ] . V_47 ;
memcpy ( & V_209 -> V_121 , V_47 -> V_121 , V_210 ) ;
V_209 -> V_127 = F_126 ( V_2 , V_47 , V_131 ) ;
V_209 -> V_205 = V_47 -> V_205 ;
V_209 -> V_122 = V_47 -> V_122 ;
if ( V_47 -> V_15 == V_53 )
V_209 -> V_202 = 0 ;
else
V_209 -> V_202 = V_47 -> V_15 * 100 ;
V_209 -> V_131 = V_131 ;
return 0 ;
}
int F_128 ( struct V_97 * V_95 , int V_131 , bool V_211 )
{
struct V_1 * V_2 = F_120 ( V_95 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_74 * V_55 ;
struct V_46 * V_47 ;
if ( ! F_30 ( V_2 ) )
return - V_199 ;
if ( V_131 >= V_33 -> V_40 )
return - V_48 ;
V_55 = & V_33 -> V_55 [ V_131 ] ;
V_47 = V_55 -> V_47 ;
if ( F_106 ( V_137 , & V_55 -> V_94 ) ) {
F_48 ( V_95 ,
L_41 ,
V_131 ) ;
return - V_199 ;
}
V_47 -> V_122 = V_211 ;
return 0 ;
}
