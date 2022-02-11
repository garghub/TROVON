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
T_1 V_38 = V_33 -> V_39 + 1 ;
int V_40 = - V_41 , V_42 , V_43 ;
struct V_44 * V_45 ;
T_2 V_46 , V_47 , V_48 ;
V_42 = F_7 ( V_2 , V_31 ) ;
if ( V_42 < 0 )
return - V_49 ;
V_46 = V_33 -> V_46 ;
V_47 = V_46 + 1 ;
V_30 -> V_13 = 0xffff ;
V_30 -> V_16 = V_36 -> V_50 / V_47 ;
if ( F_8 ( V_2 ) )
V_38 = V_51 ;
V_30 -> V_18 = V_36 -> V_52 ;
if ( V_2 -> V_34 -> V_53 == V_31 ) {
V_30 -> V_14 = 0 ;
V_30 -> V_15 = V_54 ;
V_48 = V_36 -> V_55 - V_38 * V_46 ;
V_30 -> V_19 = V_48 ;
V_48 = V_36 -> V_56 - V_38 * V_46 ;
V_30 -> V_17 = V_48 ;
V_48 = V_38 * V_46 * V_57 ;
V_48 = V_36 -> V_52 - V_48 ;
V_30 -> V_18 = V_48 ;
V_30 -> V_16 = V_36 -> V_50 - V_33 -> V_46 ;
} else {
V_43 = F_9 ( V_2 , V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_33 -> V_58 [ V_43 ] . V_45 ;
V_30 -> V_14 = V_45 -> V_14 ;
V_30 -> V_15 = V_45 -> V_15 ;
V_30 -> V_19 = V_38 ;
V_30 -> V_17 = V_38 ;
V_48 = V_38 * V_57 ;
V_30 -> V_18 = V_48 ;
V_30 -> V_16 = V_59 ;
}
V_30 -> V_20 = V_36 -> V_60 / V_47 ;
V_30 -> V_22 = V_36 -> V_61 / V_47 ;
V_30 -> V_23 = V_36 -> V_62 / V_47 ;
V_30 -> V_24 = V_36 -> V_63 / V_47 ;
V_30 -> V_21 = V_36 -> V_64 / V_47 ;
V_30 -> V_25 = V_36 -> V_65 ;
V_30 -> V_26 = V_36 -> V_26 ;
V_30 -> V_27 = V_36 -> V_27 ;
V_40 = F_1 ( V_2 , V_30 , V_42 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_30 )
{
struct V_35 * V_37 = & V_2 -> V_34 -> V_33 -> V_37 ;
V_37 -> V_56 = V_30 -> V_17 ;
V_37 -> V_55 = V_30 -> V_19 ;
V_37 -> V_52 = V_30 -> V_18 ;
V_37 -> V_65 = V_30 -> V_25 ;
V_37 -> V_63 = V_30 -> V_24 ;
V_37 -> V_50 = V_30 -> V_16 ;
V_37 -> V_64 = V_30 -> V_21 ;
V_37 -> V_60 = V_30 -> V_20 ;
V_37 -> V_62 = V_30 -> V_23 ;
V_37 -> V_61 = V_30 -> V_22 ;
V_37 -> V_27 = V_30 -> V_27 ;
V_37 -> V_26 = V_30 -> V_26 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_48 , V_66 ;
V_48 = V_4 -> V_18 ;
V_66 = V_33 -> V_46 + 1 ;
V_48 = V_48 / ( V_57 * V_66 ) ;
V_33 -> V_39 = V_48 - 1 ;
if ( F_8 ( V_2 ) )
V_33 -> V_39 = 1 ;
F_12 ( V_2 -> V_67 , L_2 ,
V_33 -> V_39 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
struct V_6 V_7 ;
if ( F_2 ( & V_7 , V_2 , V_68 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 1 ] = 0x2 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_3 , V_8 ) ;
goto V_69;
}
V_4 -> V_70 = V_7 . V_71 . V_12 [ 2 ] & 0xff ;
V_4 -> V_72 = ( V_7 . V_71 . V_12 [ 2 ] >> 8 ) & 0xff ;
V_4 -> V_73 = F_14 ( V_7 . V_71 . V_12 [ 2 ] ) ;
V_4 -> V_16 = F_15 ( V_7 . V_71 . V_12 [ 3 ] ) ;
V_4 -> V_17 = F_14 ( V_7 . V_71 . V_12 [ 3 ] ) ;
V_4 -> V_18 = F_15 ( V_7 . V_71 . V_12 [ 4 ] ) ;
V_4 -> V_19 = F_14 ( V_7 . V_71 . V_12 [ 4 ] ) ;
V_4 -> V_20 = F_15 ( V_7 . V_71 . V_12 [ 5 ] ) ;
V_4 -> V_21 = F_14 ( V_7 . V_71 . V_12 [ 5 ] ) ;
V_4 -> V_22 = F_15 ( V_7 . V_71 . V_12 [ 6 ] ) ;
V_4 -> V_23 = F_14 ( V_7 . V_71 . V_12 [ 6 ] ) ;
V_4 -> V_24 = F_15 ( V_7 . V_71 . V_12 [ 7 ] ) ;
V_4 -> V_25 = F_14 ( V_7 . V_71 . V_12 [ 7 ] ) ;
V_4 -> V_26 = F_15 ( V_7 . V_71 . V_12 [ 8 ] ) ;
V_4 -> V_27 = F_14 ( V_7 . V_71 . V_12 [ 8 ] ) ;
F_11 ( V_2 , V_4 ) ;
F_10 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_28 -> V_29 ,
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
V_4 -> V_70 , V_4 -> V_72 ,
V_4 -> V_73 , V_4 -> V_16 ,
V_4 -> V_17 ,
V_4 -> V_18 ,
V_4 -> V_19 , V_4 -> V_20 ,
V_4 -> V_21 , V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_24 ,
V_4 -> V_25 , V_4 -> V_26 ,
V_4 -> V_27 ) ;
V_69:
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
int V_74 ;
if ( V_2 -> V_34 -> V_53 == V_31 ) {
V_33 -> V_75 = 0 ;
} else {
V_74 = F_9 ( V_2 , V_31 ) ;
if ( V_74 < 0 )
return;
V_45 = V_33 -> V_58 [ V_74 ] . V_45 ;
V_45 -> V_76 = 0 ;
}
}
static void F_18 ( struct V_1 * V_2 ,
T_1 V_77 , T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
int V_74 ;
if ( V_2 -> V_34 -> V_53 == V_31 ) {
V_33 -> V_75 = V_77 ;
} else {
V_74 = F_9 ( V_2 , V_31 ) ;
if ( V_74 < 0 )
return;
V_45 = V_33 -> V_58 [ V_74 ] . V_45 ;
V_45 -> V_76 = V_77 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_78 * V_58 ;
int V_74 ;
if ( V_2 -> V_34 -> V_53 == V_31 ) {
return V_33 -> V_75 ;
} else {
V_74 = F_9 ( V_2 , V_31 ) ;
if ( V_74 >= 0 ) {
V_58 = & V_33 -> V_58 [ V_74 ] ;
return V_58 -> V_45 -> V_76 ;
}
}
return - V_49 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_3 V_79 , T_1 V_31 )
{
struct V_6 V_7 ;
int V_40 ;
int V_42 ;
if ( F_2 ( & V_7 , V_2 , V_80 ) )
return - V_10 ;
if ( V_79 ) {
V_7 . V_11 . V_12 [ 3 ] = V_31 << 8 ;
} else {
V_42 = F_7 ( V_2 , V_31 ) ;
if ( V_42 < 0 ) {
V_40 = - V_49 ;
goto V_69;
}
V_7 . V_11 . V_12 [ 3 ] = ( ( V_42 & 0xffff ) << 8 ) | 1 ;
}
V_40 = F_3 ( V_2 , & V_7 ) ;
if ( V_40 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_11 ,
( V_79 ? L_12 : L_13 ) , V_40 , V_31 ) ;
goto V_69;
}
if ( V_79 ) {
V_42 = V_7 . V_71 . V_12 [ 2 ] & 0xffff ;
F_18 ( V_2 , V_42 , V_31 ) ;
} else {
F_17 ( V_2 , V_31 ) ;
}
V_69:
F_5 ( & V_7 ) ;
return V_40 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_81 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x4 ;
if ( V_81 ) {
V_2 -> V_82 |= V_83 ;
V_7 . V_11 . V_12 [ 1 ] |= V_84 ;
if ( F_21 ( V_2 ) )
V_7 . V_11 . V_12 [ 1 ] |= V_85 ;
} else {
V_2 -> V_82 &= ~ V_83 ;
}
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_14 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = V_86 | V_87 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_15 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_3 V_31 , T_3 V_81 )
{
struct V_6 V_7 ;
int V_8 = - V_41 ;
if ( F_2 ( & V_7 , V_2 , V_88 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 0 ] |= ( 3 << 29 ) ;
V_7 . V_11 . V_12 [ 1 ] = ( ( V_31 & 0xf ) << 2 ) | V_89 | V_90 ;
if ( V_81 )
V_7 . V_11 . V_12 [ 1 ] |= V_91 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 != V_92 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_16 , V_8 ) ;
V_8 = - V_41 ;
}
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_93 * V_94 = & V_33 -> V_94 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_33 -> V_46 ; V_95 ++ )
F_25 ( & V_33 -> V_58 [ V_95 ] . V_96 ) ;
F_26 ( V_94 -> V_97 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = & V_2 -> V_34 -> V_33 -> V_94 ;
struct V_98 * V_99 ;
V_99 = F_28 ( L_17 ) ;
if ( V_99 == NULL ) {
F_4 ( & V_2 -> V_28 -> V_29 , L_18 ) ;
return - V_10 ;
}
V_94 -> V_97 = V_99 ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
T_3 V_31 = V_2 -> V_34 -> V_53 ;
if ( ! F_30 ( V_2 ) )
return;
F_24 ( V_2 ) ;
F_31 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 , V_31 ) ;
F_23 ( V_2 , V_31 , 0 ) ;
F_20 ( V_2 , 0 ) ;
F_32 ( V_2 ) ;
V_2 -> V_34 -> V_100 = V_101 ;
F_33 ( V_102 , & V_2 -> V_103 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! F_35 ( V_2 ) )
return;
if ( ! F_30 ( V_2 ) )
return;
F_36 ( V_2 -> V_28 ) ;
F_12 ( V_2 -> V_67 ,
L_19 ,
V_2 -> V_104 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_105 * V_67 = V_2 -> V_67 ;
if ( F_38 ( V_2 -> V_28 ) ) {
F_39 ( V_2 -> V_67 ,
L_20 ,
V_2 -> V_104 ) ;
F_12 ( V_2 -> V_67 ,
L_21 ,
V_2 -> V_104 ) ;
return - V_106 ;
}
F_34 ( V_2 ) ;
F_40 () ;
if ( F_41 ( V_67 ) )
F_42 ( V_2 , V_67 ) ;
F_43 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( F_44 ( V_2 ) ) {
F_45 () ;
return - V_41 ;
}
if ( F_41 ( V_67 ) )
F_46 ( V_2 , V_67 ) ;
F_45 () ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_107 * V_34 = V_2 -> V_34 ;
struct V_3 V_108 , V_109 , V_110 ;
int V_8 ;
T_3 V_31 = V_34 -> V_53 ;
if ( ! F_30 ( V_2 ) )
return 0 ;
V_8 = F_20 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( F_21 ( V_2 ) ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
goto V_111;
}
V_8 = F_23 ( V_2 , V_31 , 1 ) ;
if ( V_8 )
goto V_111;
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( V_8 )
goto V_112;
V_8 = F_13 ( V_2 , & V_109 ) ;
if ( V_8 )
goto V_113;
V_8 = F_48 ( V_2 , & V_108 , V_31 ) ;
if ( V_8 )
goto V_113;
V_8 = F_6 ( V_2 , & V_110 , V_31 ) ;
if ( V_8 )
goto V_113;
V_8 = F_31 ( V_2 , 1 ) ;
if ( V_8 )
goto V_113;
V_34 -> V_114 = ( T_3 ) V_108 . V_115 ;
V_34 -> V_116 = V_108 . V_116 ;
V_34 -> V_117 = V_108 . V_117 ;
V_34 -> V_118 = V_108 . V_118 ;
V_34 -> V_119 = V_120 ;
return V_8 ;
V_113:
F_19 ( V_2 , 0 , V_31 ) ;
V_112:
F_23 ( V_2 , V_31 , 0 ) ;
V_111:
F_20 ( V_2 , 0 ) ;
return V_8 ;
}
static int F_49 ( struct V_1 * V_2 , int V_46 )
{
int V_8 ;
if ( ! F_30 ( V_2 ) )
return 0 ;
V_8 = F_50 ( V_2 -> V_28 , V_46 ) ;
if ( V_8 )
F_29 ( V_2 ) ;
return V_8 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_46 )
{
int V_8 = 0 ;
F_52 ( V_102 , & V_2 -> V_103 ) ;
V_2 -> V_34 -> V_100 = V_121 ;
V_8 = F_53 ( V_2 , V_46 ) ;
if ( V_8 )
goto V_122;
V_8 = F_27 ( V_2 ) ;
if ( V_8 )
goto V_123;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
goto V_124;
F_54 ( V_2 ) ;
return V_8 ;
V_124:
F_24 ( V_2 ) ;
V_123:
F_32 ( V_2 ) ;
V_122:
F_33 ( V_102 , & V_2 -> V_103 ) ;
V_2 -> V_34 -> V_100 = V_101 ;
return V_8 ;
}
static int F_55 ( struct V_1 * V_2 , int V_46 )
{
struct V_105 * V_67 = V_2 -> V_67 ;
int V_8 ;
if ( ! ( V_2 -> V_82 & V_125 ) ) {
F_39 ( V_67 ,
L_22 ) ;
return - V_41 ;
}
F_40 () ;
if ( F_41 ( V_67 ) )
F_42 ( V_2 , V_67 ) ;
V_8 = F_51 ( V_2 , V_46 ) ;
if ( V_8 )
goto error;
if ( F_41 ( V_67 ) )
F_46 ( V_2 , V_67 ) ;
F_45 () ;
V_8 = F_49 ( V_2 , V_46 ) ;
if ( ! V_8 ) {
F_12 ( V_67 ,
L_23 ,
V_2 -> V_104 ) ;
return V_46 ;
}
F_40 () ;
if ( F_41 ( V_67 ) )
F_42 ( V_2 , V_67 ) ;
error:
if ( ! F_44 ( V_2 ) ) {
if ( F_41 ( V_67 ) )
F_46 ( V_2 , V_67 ) ;
}
F_45 () ;
F_12 ( V_67 , L_24 ,
V_2 -> V_104 ) ;
return V_8 ;
}
int F_56 ( struct V_126 * V_29 , int V_46 )
{
struct V_1 * V_2 = F_57 ( V_29 ) ;
int V_8 ;
if ( F_58 ( V_127 , & V_2 -> V_103 ) )
return - V_128 ;
if ( V_46 == 0 )
V_8 = F_37 ( V_2 ) ;
else
V_8 = F_55 ( V_2 , V_46 ) ;
F_33 ( V_127 , & V_2 -> V_103 ) ;
return V_8 ;
}
static int F_59 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_6 V_7 ;
struct V_44 * V_45 ;
int V_8 , V_43 ;
T_3 * V_129 ;
V_43 = F_9 ( V_2 , V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_2 -> V_34 -> V_33 -> V_58 [ V_43 ] . V_45 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x3 | V_31 << 16 ;
if ( V_45 -> V_130 == true ) {
V_129 = V_45 -> V_129 ;
V_7 . V_11 . V_12 [ 2 ] |= V_90 | V_131 | V_132 ;
V_7 . V_11 . V_12 [ 4 ] = V_129 [ 5 ] | V_129 [ 4 ] << 8 | V_129 [ 3 ] << 16 |
V_129 [ 2 ] << 24 ;
V_7 . V_11 . V_12 [ 5 ] = V_129 [ 1 ] | V_129 [ 0 ] << 8 ;
}
if ( V_45 -> V_133 == V_134 ) {
V_7 . V_11 . V_12 [ 2 ] |= V_89 ;
V_7 . V_11 . V_12 [ 3 ] |= V_45 -> V_135 << 8 ;
}
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 , L_25 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_60 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_3 V_136 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_136 , V_31 ) ;
if ( V_8 )
return - V_41 ;
V_8 = F_59 ( V_2 , V_31 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_61 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_44 * V_45 = V_139 -> V_45 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
T_1 V_31 = V_139 -> V_53 ;
T_4 V_140 ;
int V_8 ;
V_2 = V_139 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
if ( V_138 -> V_141 -> V_142 == V_143 ) {
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( ! V_8 ) {
V_8 = F_60 ( V_2 , V_31 ) ;
if ( V_8 )
F_19 ( V_2 , 0 , V_31 ) ;
}
} else {
if ( V_45 -> V_133 == V_144 ) {
V_140 = sizeof( * V_139 -> V_145 ) ;
V_140 = V_140 * V_33 -> V_39 ;
memset ( V_139 -> V_145 , 0 , V_140 ) ;
}
V_8 = F_19 ( V_2 , 0 , V_31 ) ;
}
if ( V_8 )
goto V_146;
V_7 -> V_71 . V_12 [ 0 ] |= ( 1 << 25 ) ;
if ( V_138 -> V_141 -> V_142 == V_143 )
F_52 ( V_147 , & V_139 -> V_103 ) ;
else
F_33 ( V_147 , & V_139 -> V_103 ) ;
return V_8 ;
V_146:
V_7 -> V_71 . V_12 [ 0 ] |= ( 2 << 25 ) ;
return V_8 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
T_1 V_148 , T_3 V_149 )
{
struct V_6 * V_7 ;
struct V_150 V_151 ;
struct V_44 * V_45 ;
T_3 * V_152 ;
int V_8 ;
T_2 * V_153 ;
int V_42 ;
V_45 = V_139 -> V_45 ;
V_7 = F_63 ( sizeof( * V_7 ) , V_154 ) ;
if ( ! V_7 )
return - V_10 ;
V_8 = F_2 ( V_7 , V_2 , V_155 ) ;
if ( V_8 )
goto V_156;
V_7 -> type = V_157 ;
V_42 = F_7 ( V_2 , V_139 -> V_53 ) ;
if ( V_42 < 0 ) {
V_8 = - V_49 ;
goto V_158;
}
if ( V_148 )
V_149 = ( ( V_149 == V_159 || V_149 == V_160 ) ?
V_160 : V_161 ) ;
V_7 -> V_11 . V_12 [ 1 ] = V_149 | ( 1 << 8 ) | ( 3 << 6 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= ( ( V_42 & 0xffff ) << 16 ) | V_162 ;
V_152 = V_45 -> V_129 ;
V_151 . V_148 = V_148 ;
V_151 . V_163 = V_152 [ 0 ] ;
V_151 . V_164 = V_152 [ 1 ] ;
V_151 . V_165 = V_152 [ 2 ] ;
V_151 . V_166 = V_152 [ 3 ] ;
V_151 . V_167 = V_152 [ 4 ] ;
V_151 . V_168 = V_152 [ 5 ] ;
V_153 = & V_7 -> V_11 . V_12 [ 2 ] ;
memcpy ( V_153 , & V_151 , sizeof( struct V_150 ) ) ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
return V_8 ;
V_158:
F_5 ( V_7 ) ;
V_156:
F_64 ( V_7 ) ;
return V_8 ;
}
static int F_65 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
int V_169 )
{
struct V_32 * V_33 ;
T_1 V_148 ;
int V_95 ;
V_33 = V_2 -> V_34 -> V_33 ;
F_67 ( & V_139 -> V_170 ) ;
if ( V_139 -> V_171 ) {
for ( V_95 = 0 ; V_95 < V_33 -> V_39 ; V_95 ++ ) {
V_148 = V_139 -> V_145 [ V_95 ] ;
if ( V_148 )
F_62 ( V_2 , V_139 , V_148 ,
V_169 ) ;
}
}
F_68 ( & V_139 -> V_170 ) ;
if ( V_139 -> V_45 -> V_133 != V_134 ) {
if ( F_8 ( V_2 ) &&
F_69 ( V_139 ) )
return;
F_62 ( V_2 , V_139 , 0 , V_169 ) ;
}
}
static int F_70 ( struct V_137 * V_172 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_172 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
struct V_173 * V_174 ;
int V_8 ;
V_8 = F_65 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 6 ] = V_139 -> V_45 -> V_76 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_174 = (struct V_173 * ) & V_7 -> V_71 . V_12 [ 1 ] ;
V_139 -> V_175 = V_174 -> V_176 ;
F_66 ( V_2 , V_139 , V_159 ) ;
} else {
V_139 -> V_175 = 0 ;
}
return V_8 ;
}
static int F_71 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
T_3 type , * V_129 ;
type = V_7 -> V_11 . V_12 [ 1 ] ;
switch ( type ) {
case V_177 :
case V_178 :
V_7 -> V_71 . V_12 [ 0 ] = ( 2 << 25 ) ;
break;
case V_179 :
V_7 -> V_71 . V_12 [ 0 ] = ( 1 << 25 ) ;
V_129 = V_139 -> V_45 -> V_129 ;
V_7 -> V_71 . V_12 [ 2 ] = V_129 [ 1 ] | ( ( V_129 [ 0 ] << 8 ) & 0xff00 ) ;
V_7 -> V_71 . V_12 [ 1 ] = V_129 [ 5 ] | ( ( V_129 [ 4 ] << 8 ) & 0xff00 ) |
( ( V_129 [ 3 ] ) << 16 & 0xff0000 ) |
( ( V_129 [ 2 ] ) << 24 & 0xff000000 ) ;
}
return 0 ;
}
static int F_72 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static int F_73 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
struct V_180 * V_174 ;
int V_8 ;
V_8 = F_72 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 5 ] |= V_139 -> V_45 -> V_76 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_174 = (struct V_180 * ) & V_7 -> V_71 . V_12 [ 2 ] ;
V_139 -> V_181 = V_174 -> V_176 ;
} else {
V_139 -> V_181 = 0 ;
}
return V_8 ;
}
static int F_74 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_139 -> V_175 )
return - V_49 ;
return 0 ;
}
static int F_75 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_74 ( V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
F_66 ( V_2 , V_139 , V_182 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_139 -> V_45 -> V_76 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_139 -> V_175 = 0 ;
return V_8 ;
}
static int F_76 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_139 -> V_181 )
return - V_49 ;
return 0 ;
}
static int F_77 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_76 ( V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 1 ] |= V_139 -> V_45 -> V_76 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_139 -> V_181 = 0 ;
return V_8 ;
}
static int F_78 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_139 -> V_175 )
return - V_49 ;
return 0 ;
}
static int F_79 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_78 ( V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_80 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 = - V_41 ;
T_3 V_149 ;
V_149 = V_7 -> V_11 . V_12 [ 1 ] & 0xff ;
V_7 -> V_11 . V_12 [ 1 ] |= V_139 -> V_45 -> V_76 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_162 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_81 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 8 ) & 0xff ) != V_139 -> V_53 )
return - V_49 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_84 ) )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xff ) != 0x1 )
return - V_49 ;
return 0 ;
}
static int F_82 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_81 ( V_139 , V_7 ) ;
if ( V_8 )
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_139 -> V_175 )
return - V_49 ;
if ( V_7 -> V_11 . V_12 [ 2 ] > V_2 -> V_34 -> V_117 )
return - V_49 ;
return 0 ;
}
static int F_84 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_83 ( V_2 , V_139 , V_7 ) ;
if ( V_8 )
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_85 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] & V_162 ) {
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) & 0x7fff ) != V_139 -> V_53 )
return - V_49 ;
} else {
V_7 -> V_11 . V_12 [ 1 ] |= V_139 -> V_45 -> V_76 << 16 ;
}
return 0 ;
}
static int F_86 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_85 ( V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_87 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_139 -> V_175 )
return - V_49 ;
return 0 ;
}
static int F_88 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_87 ( V_139 , V_7 ) ;
if ( V_8 )
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
struct V_6 * V_7 )
{
struct V_183 * V_184 = & V_2 -> V_34 -> V_184 ;
T_1 V_176 , V_185 , time ;
int V_8 = - V_49 ;
T_3 type ;
type = V_7 -> V_11 . V_12 [ 1 ] & V_186 ;
V_176 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_185 = V_7 -> V_11 . V_12 [ 2 ] & 0xffff ;
time = V_7 -> V_11 . V_12 [ 2 ] >> 16 ;
switch ( type ) {
case V_187 :
if ( V_176 != V_139 -> V_175 || V_185 > V_184 -> V_188 ||
time < V_184 -> V_189 )
goto V_190;
break;
case V_191 :
if ( V_176 != V_139 -> V_181 || V_185 > V_184 -> V_192 ||
time < V_184 -> V_193 )
goto V_190;
break;
default:
F_39 ( V_2 -> V_67 , L_26 ,
type ) ;
return V_8 ;
}
return 0 ;
V_190:
F_39 ( V_2 -> V_67 , L_27 ,
V_139 -> V_175 , V_184 -> V_188 , V_184 -> V_189 ,
V_139 -> V_181 , V_184 -> V_192 , V_184 -> V_193 ) ;
F_39 ( V_2 -> V_67 , L_28 ,
V_176 , V_185 , time , type ) ;
return V_8 ;
}
static int F_90 ( struct V_137 * V_172 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_172 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_89 ( V_2 , V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
struct V_6 * V_7 )
{
struct V_44 * V_45 = V_139 -> V_45 ;
T_3 V_149 , V_194 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_132 ) )
return - V_49 ;
V_7 -> V_11 . V_12 [ 1 ] |= ( V_139 -> V_45 -> V_76 << 16 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_162 ;
if ( V_45 -> V_133 == V_134 ) {
V_149 = V_7 -> V_11 . V_12 [ 1 ] & 0x7 ;
V_7 -> V_11 . V_12 [ 1 ] &= ~ 0x7 ;
V_194 = ( V_149 == V_159 || V_149 == V_160 ) ?
V_160 : V_161 ;
V_7 -> V_11 . V_12 [ 3 ] |= V_45 -> V_135 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_194 ;
}
return 0 ;
}
static int F_92 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_91 ( V_2 , V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_93 ( struct V_78 * V_139 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_139 -> V_175 )
return - V_49 ;
return 0 ;
}
static int F_94 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_8 = F_93 ( V_139 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_95 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
int V_8 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_139 -> V_45 -> V_76 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_162 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_96 ( struct V_137 * V_138 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_138 -> V_139 ;
struct V_44 * V_45 = V_139 -> V_45 ;
T_3 V_142 , V_195 = V_45 -> V_133 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = V_139 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
V_142 = V_138 -> V_141 -> V_142 ;
V_7 -> V_71 . V_12 [ 0 ] |= 1 << 25 ;
if ( F_21 ( V_2 ) && V_195 == V_134 )
return 0 ;
switch ( V_195 ) {
case V_144 :
V_7 -> V_71 . V_12 [ 1 ] = V_195 | 1 << 8 ;
V_7 -> V_71 . V_12 [ 2 ] = V_33 -> V_39 << 16 ;
break;
case V_134 :
V_7 -> V_71 . V_12 [ 1 ] = V_195 | 1 << 8 | V_45 -> V_135 << 16 ;
break;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
T_1 V_148 ;
if ( ! F_69 ( V_139 ) )
return - V_49 ;
V_148 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_139 -> V_175 ) {
F_98 ( V_33 , V_139 , V_148 ) ;
return 0 ;
}
F_62 ( V_2 , V_139 , V_148 , V_182 ) ;
F_98 ( V_33 , V_139 , V_148 ) ;
if ( F_8 ( V_2 ) )
F_62 ( V_2 , V_139 ,
0 , V_159 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_78 * V_139 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_8 = - V_41 ;
T_1 V_148 ;
if ( F_8 ( V_2 ) && F_69 ( V_139 ) )
return V_8 ;
V_148 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_139 -> V_175 ) {
F_100 ( V_33 , V_139 , V_148 ) ;
return 0 ;
}
if ( F_8 ( V_2 ) ) {
V_8 = F_62 ( V_2 , V_139 , 0 ,
V_182 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_62 ( V_2 , V_139 , V_148 , V_159 ) ;
if ( V_8 ) {
if ( F_8 ( V_2 ) )
F_62 ( V_2 , V_139 , 0 ,
V_159 ) ;
return V_8 ;
}
F_100 ( V_33 , V_139 , V_148 ) ;
return V_8 ;
}
static int F_101 ( struct V_137 * V_172 ,
struct V_6 * V_7 )
{
struct V_78 * V_139 = V_172 -> V_139 ;
struct V_1 * V_2 = V_139 -> V_2 ;
struct V_44 * V_45 = V_139 -> V_45 ;
int V_8 = - V_41 ;
T_3 V_149 ;
if ( V_45 -> V_133 != V_144 ) {
V_7 -> V_71 . V_12 [ 0 ] |= 2 << 25 ;
return V_8 ;
}
V_149 = V_7 -> V_11 . V_12 [ 1 ] & 0xf ;
if ( V_149 )
V_8 = F_99 ( V_2 , V_139 , V_7 ) ;
else
V_8 = F_97 ( V_2 , V_139 , V_7 ) ;
V_7 -> V_71 . V_12 [ 0 ] |= V_8 ? 2 << 25 : 1 << 25 ;
return V_8 ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
struct V_6 * V_7 )
{
T_3 V_140 , V_142 ;
V_142 = V_138 -> V_141 -> V_142 ;
if ( V_138 -> V_141 -> V_196 == V_197 ) {
V_140 = F_103 ( V_198 ) ;
if ( V_142 < V_140 ) {
V_198 [ V_142 ] . F_104 ( V_138 , V_7 ) ;
return;
}
} else {
int V_95 ;
V_140 = F_103 ( V_199 ) ;
for ( V_95 = 0 ; V_95 < V_140 ; V_95 ++ ) {
if ( V_142 == V_199 [ V_95 ] . V_7 ) {
V_199 [ V_95 ] . F_104 ( V_138 , V_7 ) ;
return;
}
}
V_140 = F_103 ( V_200 ) ;
for ( V_95 = 0 ; V_95 < V_140 ; V_95 ++ ) {
if ( V_142 == V_200 [ V_95 ] ) {
F_3 ( V_2 , V_7 ) ;
return;
}
}
}
V_7 -> V_71 . V_12 [ 0 ] |= ( 0x9 << 25 ) ;
}
void F_105 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= V_42 ;
}
void F_106 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= V_42 << 16 ;
}
void F_107 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
int V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= V_42 << 16 ;
}
void F_108 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= V_42 << 16 ;
}
void F_109 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= ( V_42 << 16 ) | V_162 ;
}
void F_110 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= ( V_42 << 16 ) | V_162 ;
}
void F_111 ( struct V_1 * V_2 ,
T_2 * V_201 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_53 ) ;
* V_201 |= ( V_42 << 16 ) | V_162 ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_78 * V_139 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_139 -> V_175 )
return;
if ( F_2 ( & V_7 , V_2 , V_202 ) )
return;
V_42 = F_7 ( V_2 , V_139 -> V_53 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] = V_139 -> V_175 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_29 ,
V_139 -> V_53 ) ;
else
V_139 -> V_175 = 0 ;
}
F_5 ( & V_7 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_78 * V_139 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_139 -> V_181 )
return;
if ( F_2 ( & V_7 , V_2 , V_203 ) )
return;
V_42 = F_7 ( V_2 , V_139 -> V_53 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_139 -> V_181 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_29 ,
V_139 -> V_53 ) ;
else
V_139 -> V_181 = 0 ;
}
F_5 ( & V_7 ) ;
}
static int F_114 ( struct V_32 * V_33 ,
struct V_78 * V_139 ,
struct V_137 * V_138 )
{
struct V_204 * V_205 = & V_139 -> V_206 ;
unsigned long V_79 ;
F_115 ( & V_205 -> V_207 , V_79 ) ;
F_116 ( V_33 , V_139 , V_138 ) ;
F_117 ( & V_205 -> V_207 , V_79 ) ;
return 0 ;
}
static void F_118 ( struct V_78 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_2 ;
F_119 ( & V_139 -> V_208 ) ;
F_25 ( & V_139 -> V_209 ) ;
F_119 ( & V_139 -> V_206 ) ;
if ( F_120 ( V_210 , & V_139 -> V_103 ) ) {
F_113 ( V_2 , V_139 ) ;
F_112 ( V_2 , V_139 ) ;
}
F_19 ( V_2 , 0 , V_139 -> V_53 ) ;
F_33 ( V_211 , & V_139 -> V_103 ) ;
if ( F_120 ( V_210 , & V_139 -> V_103 ) ) {
F_114 ( V_2 -> V_34 -> V_33 , V_139 ,
V_139 -> V_212 ) ;
F_33 ( V_210 , & V_139 -> V_103 ) ;
V_139 -> V_212 = NULL ;
}
}
static void F_121 ( struct V_213 * V_214 )
{
struct V_78 * V_139 ;
V_139 = F_122 ( V_214 , struct V_78 , V_96 ) ;
F_118 ( V_139 ) ;
return;
}
static void F_123 ( struct V_32 * V_33 ,
struct V_78 * V_139 ,
T_5 V_31 )
{
if ( F_120 ( V_127 , & V_139 -> V_2 -> V_103 ) )
return;
F_124 ( & V_139 -> V_96 , V_31 ) ;
F_125 ( V_33 -> V_94 . V_97 , & V_139 -> V_96 ) ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
struct V_78 * V_139 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
F_52 ( V_211 , & V_139 -> V_103 ) ;
F_33 ( V_147 , & V_139 -> V_103 ) ;
F_52 ( V_210 , & V_139 -> V_103 ) ;
V_139 -> V_212 = V_138 ;
F_123 ( V_33 , V_139 , F_121 ) ;
F_12 ( V_2 -> V_67 , L_30 ,
V_139 -> V_53 ) ;
}
bool F_127 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
struct V_78 * V_139 )
{
struct V_215 * V_216 = V_138 -> V_141 ;
if ( ( V_216 -> V_142 == V_143 ) &&
( V_216 -> V_196 == V_197 ) &&
F_120 ( V_147 , & V_139 -> V_103 ) ) {
F_126 ( V_2 , V_138 , V_139 ) ;
return true ;
}
return false ;
}
void F_128 ( struct V_32 * V_33 ,
struct V_78 * V_139 )
{
struct V_105 * V_29 = V_139 -> V_2 -> V_67 ;
struct V_44 * V_45 = V_139 -> V_45 ;
if ( ! F_129 ( V_147 , & V_139 -> V_103 ) ) {
F_33 ( V_211 , & V_139 -> V_103 ) ;
return;
}
if ( F_58 ( V_211 , & V_139 -> V_103 ) ) {
F_12 ( V_29 , L_31 ,
V_139 -> V_53 ) ;
return;
}
if ( V_45 -> V_133 == V_144 )
memset ( V_139 -> V_145 , 0 ,
sizeof( * V_139 -> V_145 ) * V_33 -> V_39 ) ;
F_123 ( V_33 , V_139 , F_121 ) ;
F_12 ( V_29 , L_32 , V_139 -> V_53 ) ;
}
void F_130 ( struct V_1 * V_2 )
{
struct V_107 * V_34 = V_2 -> V_34 ;
struct V_32 * V_33 = V_34 -> V_33 ;
struct V_78 * V_139 ;
T_1 V_46 = V_33 -> V_46 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_46 ; V_95 ++ ) {
V_139 = & V_33 -> V_58 [ V_95 ] ;
V_139 -> V_175 = 0 ;
V_139 -> V_181 = 0 ;
F_25 ( & V_139 -> V_96 ) ;
F_118 ( V_139 ) ;
F_33 ( V_147 , & V_139 -> V_103 ) ;
}
F_17 ( V_2 , V_34 -> V_53 ) ;
F_131 ( V_34 , V_217 , ( V_34 -> V_218 - 1 ) << 8 ) ;
}
int F_132 ( struct V_1 * V_2 )
{
struct V_107 * V_34 = V_2 -> V_34 ;
int V_8 ;
if ( ! F_30 ( V_2 ) )
return 0 ;
V_34 -> V_100 = V_121 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_16 ( & V_2 -> V_28 -> V_29 , L_33 ,
V_219 , V_34 -> V_100 ) ;
return V_8 ;
}
int F_133 ( struct V_105 * V_67 , int V_139 , T_3 * V_129 )
{
struct V_1 * V_2 = F_134 ( V_67 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_95 , V_46 ;
struct V_78 * V_58 ;
T_3 * V_220 ;
if ( ! F_35 ( V_2 ) )
return - V_221 ;
V_46 = V_33 -> V_46 ;
if ( ! F_135 ( V_129 ) || V_139 >= V_46 )
return - V_49 ;
if ( F_136 ( V_2 -> V_222 , V_129 ) ) {
F_39 ( V_67 , L_34 ) ;
return - V_49 ;
}
for ( V_95 = 0 ; V_95 < V_46 ; V_95 ++ ) {
V_58 = & V_33 -> V_58 [ V_95 ] ;
if ( F_136 ( V_58 -> V_45 -> V_129 , V_129 ) ) {
F_39 ( V_67 ,
L_35 ,
V_95 ) ;
return - V_49 ;
}
}
V_58 = & V_33 -> V_58 [ V_139 ] ;
V_220 = V_58 -> V_45 -> V_129 ;
if ( F_120 ( V_147 , & V_58 -> V_103 ) ) {
F_39 ( V_67 ,
L_36 ,
V_139 ) ;
return - V_221 ;
}
memcpy ( V_220 , V_129 , V_67 -> V_223 ) ;
F_12 ( V_67 , L_37 ,
V_129 , V_139 ) ;
return 0 ;
}
int F_137 ( struct V_105 * V_67 , int V_139 ,
int V_224 , int V_225 )
{
struct V_1 * V_2 = F_134 ( V_67 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_78 * V_58 ;
struct V_3 V_108 ;
struct V_44 * V_45 ;
T_1 V_42 ;
if ( ! F_35 ( V_2 ) )
return - V_221 ;
if ( V_139 >= V_33 -> V_46 )
return - V_49 ;
V_58 = & V_33 -> V_58 [ V_139 ] ;
V_45 = V_58 -> V_45 ;
V_42 = V_45 -> V_76 ;
if ( ! V_224 )
V_224 = V_226 ;
if ( V_225 &&
( V_225 >= 10000 || V_225 < V_224 ) ) {
F_39 ( V_67 ,
L_38 ,
V_224 , V_227 ) ;
return - V_49 ;
}
if ( ! V_225 )
V_225 = 10000 ;
if ( V_224 &&
( V_224 > V_225 || V_224 < V_226 ) ) {
F_39 ( V_67 ,
L_39 ,
V_226 , V_225 ) ;
return - V_49 ;
}
if ( F_120 ( V_147 , & V_58 -> V_103 ) ) {
if ( F_138 ( V_2 , & V_108 , V_42 ) )
return - V_41 ;
V_108 . V_15 = V_225 / 100 ;
V_108 . V_14 = V_224 / 100 ;
V_108 . V_13 = V_91 ;
if ( F_1 ( V_2 , & V_108 , V_42 ) )
return - V_41 ;
}
V_45 -> V_15 = V_225 / 100 ;
F_12 ( V_67 ,
L_40 ,
V_225 , V_45 -> V_15 , V_139 ) ;
V_45 -> V_14 = V_224 / 100 ;
F_12 ( V_67 ,
L_41 ,
V_224 , V_45 -> V_14 , V_139 ) ;
return 0 ;
}
int F_139 ( struct V_105 * V_67 , int V_139 ,
T_1 V_148 , T_3 V_228 )
{
struct V_1 * V_2 = F_134 ( V_67 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_78 * V_58 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_221 ;
if ( V_139 >= V_33 -> V_46 || V_228 > 7 )
return - V_49 ;
if ( V_148 > V_229 ) {
F_39 ( V_67 ,
L_42 ,
V_229 ) ;
return - V_49 ;
}
V_58 = & V_33 -> V_58 [ V_139 ] ;
V_45 = V_58 -> V_45 ;
if ( F_120 ( V_147 , & V_58 -> V_103 ) ) {
F_39 ( V_67 ,
L_43 ,
V_139 ) ;
return - V_221 ;
}
memset ( V_58 -> V_145 , 0 ,
sizeof( * V_58 -> V_145 ) * V_33 -> V_39 ) ;
switch ( V_148 ) {
case 4095 :
V_45 -> V_133 = V_144 ;
break;
case 0 :
V_45 -> V_133 = V_230 ;
V_45 -> V_228 = 0 ;
break;
default:
V_45 -> V_133 = V_134 ;
F_100 ( V_33 , V_58 , V_148 ) ;
V_45 -> V_228 = V_228 ;
V_45 -> V_135 = V_148 ;
}
F_12 ( V_67 , L_44 ,
V_148 , V_228 , V_139 ) ;
return 0 ;
}
static T_6 F_140 ( struct V_1 * V_2 ,
struct V_44 * V_45 , int V_139 )
{
T_6 V_148 = 0 ;
switch ( V_45 -> V_133 ) {
case V_134 :
V_148 = V_45 -> V_135 ;
break;
case V_144 :
V_148 = V_229 ;
break;
case V_230 :
V_148 = 0 ;
break;
default:
F_12 ( V_2 -> V_67 , L_45 ,
V_45 -> V_133 , V_139 ) ;
}
return V_148 ;
}
int F_141 ( struct V_105 * V_67 ,
int V_139 , struct V_231 * V_232 )
{
struct V_1 * V_2 = F_134 ( V_67 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_221 ;
if ( V_139 >= V_33 -> V_46 )
return - V_49 ;
V_45 = V_33 -> V_58 [ V_139 ] . V_45 ;
memcpy ( & V_232 -> V_129 , V_45 -> V_129 , V_233 ) ;
V_232 -> V_148 = F_140 ( V_2 , V_45 , V_139 ) ;
V_232 -> V_228 = V_45 -> V_228 ;
V_232 -> V_130 = V_45 -> V_130 ;
if ( V_45 -> V_15 == V_54 )
V_232 -> V_225 = 0 ;
else
V_232 -> V_225 = V_45 -> V_15 * 100 ;
if ( V_45 -> V_14 == V_234 )
V_232 -> V_224 = 0 ;
else
V_232 -> V_224 = V_45 -> V_14 * 100 ;
V_232 -> V_139 = V_139 ;
return 0 ;
}
int F_142 ( struct V_105 * V_67 , int V_139 , bool V_235 )
{
struct V_1 * V_2 = F_134 ( V_67 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_78 * V_58 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_221 ;
if ( V_139 >= V_33 -> V_46 )
return - V_49 ;
V_58 = & V_33 -> V_58 [ V_139 ] ;
V_45 = V_58 -> V_45 ;
if ( F_120 ( V_147 , & V_58 -> V_103 ) ) {
F_39 ( V_67 ,
L_46 ,
V_139 ) ;
return - V_221 ;
}
V_45 -> V_130 = V_235 ;
return 0 ;
}
