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
V_38 = 1 ;
V_30 -> V_18 = V_36 -> V_51 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_30 -> V_14 = 0 ;
V_30 -> V_15 = V_53 ;
V_48 = V_36 -> V_54 - V_38 * V_46 ;
V_30 -> V_19 = V_48 ;
V_48 = V_36 -> V_55 - V_38 * V_46 ;
V_30 -> V_17 = V_48 ;
V_48 = V_38 * V_46 * V_56 ;
V_48 = V_36 -> V_51 - V_48 ;
V_30 -> V_18 = V_48 ;
V_30 -> V_16 = V_36 -> V_50 - V_33 -> V_46 ;
} else {
V_43 = F_9 ( V_2 , V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_33 -> V_57 [ V_43 ] . V_45 ;
V_30 -> V_14 = V_45 -> V_14 ;
V_30 -> V_15 = V_45 -> V_15 ;
V_30 -> V_19 = V_38 ;
V_30 -> V_17 = V_38 ;
V_48 = V_38 * V_56 ;
V_30 -> V_18 = V_48 ;
V_30 -> V_16 = V_58 ;
}
V_30 -> V_20 = V_36 -> V_59 / V_47 ;
V_30 -> V_22 = V_36 -> V_60 / V_47 ;
V_30 -> V_23 = V_36 -> V_61 / V_47 ;
V_30 -> V_24 = V_36 -> V_62 / V_47 ;
V_30 -> V_21 = V_36 -> V_63 / V_47 ;
V_30 -> V_25 = V_36 -> V_64 ;
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
V_37 -> V_55 = V_30 -> V_17 ;
V_37 -> V_54 = V_30 -> V_19 ;
V_37 -> V_51 = V_30 -> V_18 ;
V_37 -> V_64 = V_30 -> V_25 ;
V_37 -> V_62 = V_30 -> V_24 ;
V_37 -> V_50 = V_30 -> V_16 ;
V_37 -> V_63 = V_30 -> V_21 ;
V_37 -> V_59 = V_30 -> V_20 ;
V_37 -> V_61 = V_30 -> V_23 ;
V_37 -> V_60 = V_30 -> V_22 ;
V_37 -> V_27 = V_30 -> V_27 ;
V_37 -> V_26 = V_30 -> V_26 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_48 , V_65 ;
V_48 = V_4 -> V_18 ;
V_65 = V_33 -> V_46 + 1 ;
V_48 = V_48 / ( V_56 * V_65 ) ;
V_33 -> V_39 = V_48 - 1 ;
if ( F_8 ( V_2 ) )
V_33 -> V_39 = 1 ;
F_12 ( V_2 -> V_66 , L_2 ,
V_33 -> V_39 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
struct V_6 V_7 ;
if ( F_2 ( & V_7 , V_2 , V_67 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 1 ] = 0x2 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_3 , V_8 ) ;
goto V_68;
}
V_4 -> V_69 = V_7 . V_70 . V_12 [ 2 ] & 0xff ;
V_4 -> V_71 = ( V_7 . V_70 . V_12 [ 2 ] >> 8 ) & 0xff ;
V_4 -> V_72 = F_14 ( V_7 . V_70 . V_12 [ 2 ] ) ;
V_4 -> V_16 = F_15 ( V_7 . V_70 . V_12 [ 3 ] ) ;
V_4 -> V_17 = F_14 ( V_7 . V_70 . V_12 [ 3 ] ) ;
V_4 -> V_18 = F_15 ( V_7 . V_70 . V_12 [ 4 ] ) ;
V_4 -> V_19 = F_14 ( V_7 . V_70 . V_12 [ 4 ] ) ;
V_4 -> V_20 = F_15 ( V_7 . V_70 . V_12 [ 5 ] ) ;
V_4 -> V_21 = F_14 ( V_7 . V_70 . V_12 [ 5 ] ) ;
V_4 -> V_22 = F_15 ( V_7 . V_70 . V_12 [ 6 ] ) ;
V_4 -> V_23 = F_14 ( V_7 . V_70 . V_12 [ 6 ] ) ;
V_4 -> V_24 = F_15 ( V_7 . V_70 . V_12 [ 7 ] ) ;
V_4 -> V_25 = F_14 ( V_7 . V_70 . V_12 [ 7 ] ) ;
V_4 -> V_26 = F_15 ( V_7 . V_70 . V_12 [ 8 ] ) ;
V_4 -> V_27 = F_14 ( V_7 . V_70 . V_12 [ 8 ] ) ;
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
V_4 -> V_69 , V_4 -> V_71 ,
V_4 -> V_72 , V_4 -> V_16 ,
V_4 -> V_17 ,
V_4 -> V_18 ,
V_4 -> V_19 , V_4 -> V_20 ,
V_4 -> V_21 , V_4 -> V_22 ,
V_4 -> V_23 , V_4 -> V_24 ,
V_4 -> V_25 , V_4 -> V_26 ,
V_4 -> V_27 ) ;
V_68:
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
int V_73 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_33 -> V_74 = 0 ;
} else {
V_73 = F_9 ( V_2 , V_31 ) ;
if ( V_73 < 0 )
return;
V_45 = V_33 -> V_57 [ V_73 ] . V_45 ;
V_45 -> V_75 = 0 ;
}
}
static void F_18 ( struct V_1 * V_2 ,
T_1 V_76 , T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
int V_73 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
V_33 -> V_74 = V_76 ;
} else {
V_73 = F_9 ( V_2 , V_31 ) ;
if ( V_73 < 0 )
return;
V_45 = V_33 -> V_57 [ V_73 ] . V_45 ;
V_45 -> V_75 = V_76 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
T_3 V_31 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
int V_73 ;
if ( V_2 -> V_34 -> V_52 == V_31 ) {
return V_33 -> V_74 ;
} else {
V_73 = F_9 ( V_2 , V_31 ) ;
if ( V_73 >= 0 ) {
V_57 = & V_33 -> V_57 [ V_73 ] ;
return V_57 -> V_45 -> V_75 ;
}
}
return - V_49 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_3 V_78 , T_1 V_31 )
{
struct V_6 V_7 ;
int V_40 ;
int V_42 ;
if ( F_2 ( & V_7 , V_2 , V_79 ) )
return - V_10 ;
if ( V_78 ) {
V_7 . V_11 . V_12 [ 3 ] = V_31 << 8 ;
} else {
V_42 = F_7 ( V_2 , V_31 ) ;
if ( V_42 < 0 ) {
V_40 = - V_49 ;
goto V_68;
}
V_7 . V_11 . V_12 [ 3 ] = ( ( V_42 & 0xffff ) << 8 ) | 1 ;
}
V_40 = F_3 ( V_2 , & V_7 ) ;
if ( V_40 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_11 ,
( V_78 ? L_12 : L_13 ) , V_40 , V_31 ) ;
goto V_68;
}
if ( V_78 ) {
V_42 = V_7 . V_70 . V_12 [ 2 ] & 0xffff ;
F_18 ( V_2 , V_42 , V_31 ) ;
} else {
F_17 ( V_2 , V_31 ) ;
}
V_68:
F_5 ( & V_7 ) ;
return V_40 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_80 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x4 ;
if ( V_80 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_81 ;
if ( F_21 ( V_2 ) )
V_7 . V_11 . V_12 [ 1 ] |= V_82 ;
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
V_7 . V_11 . V_12 [ 1 ] = V_83 | V_84 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_15 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_3 V_31 , T_3 V_80 )
{
struct V_6 V_7 ;
int V_8 = - V_41 ;
if ( F_2 ( & V_7 , V_2 , V_85 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 0 ] |= ( 3 << 29 ) ;
V_7 . V_11 . V_12 [ 1 ] = ( ( V_31 & 0xf ) << 2 ) | V_86 | V_87 ;
if ( V_80 )
V_7 . V_11 . V_12 [ 1 ] |= V_88 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 != V_89 ) {
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
struct V_90 * V_91 = & V_33 -> V_91 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_33 -> V_46 ; V_92 ++ )
F_25 ( & V_33 -> V_57 [ V_92 ] . V_93 ) ;
F_26 ( V_91 -> V_94 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = & V_2 -> V_34 -> V_33 -> V_91 ;
struct V_95 * V_96 ;
V_96 = F_28 ( L_17 ) ;
if ( V_96 == NULL ) {
F_4 ( & V_2 -> V_28 -> V_29 , L_18 ) ;
return - V_10 ;
}
V_91 -> V_94 = V_96 ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
T_3 V_31 = V_2 -> V_34 -> V_52 ;
if ( ! F_30 ( V_2 ) )
return;
F_24 ( V_2 ) ;
F_31 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 , V_31 ) ;
F_23 ( V_2 , V_31 , 0 ) ;
F_20 ( V_2 , 0 ) ;
F_32 ( V_2 ) ;
V_2 -> V_34 -> V_97 = V_98 ;
F_33 ( V_99 , & V_2 -> V_100 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! F_35 ( V_2 ) )
return;
if ( ! F_30 ( V_2 ) )
return;
F_36 ( V_2 -> V_28 ) ;
F_12 ( V_2 -> V_66 ,
L_19 ,
V_2 -> V_101 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_102 * V_66 = V_2 -> V_66 ;
if ( F_38 ( V_2 -> V_28 ) ) {
F_39 ( V_2 -> V_66 ,
L_20 ,
V_2 -> V_101 ) ;
F_12 ( V_2 -> V_66 ,
L_21 ,
V_2 -> V_101 ) ;
return - V_103 ;
}
F_40 () ;
if ( F_41 ( V_66 ) )
F_42 ( V_2 , V_66 ) ;
F_34 ( V_2 ) ;
F_43 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( F_44 ( V_2 ) ) {
F_45 () ;
return - V_41 ;
}
if ( F_41 ( V_66 ) )
F_46 ( V_2 , V_66 ) ;
F_45 () ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_104 * V_34 = V_2 -> V_34 ;
struct V_3 V_105 , V_106 , V_107 ;
int V_8 ;
T_3 V_31 = V_34 -> V_52 ;
if ( ! F_30 ( V_2 ) )
return 0 ;
V_8 = F_20 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( F_21 ( V_2 ) ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
goto V_108;
}
V_8 = F_23 ( V_2 , V_31 , 1 ) ;
if ( V_8 )
goto V_108;
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( V_8 )
goto V_109;
V_8 = F_13 ( V_2 , & V_106 ) ;
if ( V_8 )
goto V_110;
V_8 = F_48 ( V_2 , & V_105 , V_31 ) ;
if ( V_8 )
goto V_110;
V_8 = F_6 ( V_2 , & V_107 , V_31 ) ;
if ( V_8 )
goto V_110;
V_8 = F_31 ( V_2 , 1 ) ;
if ( V_8 )
goto V_110;
V_34 -> V_111 = ( T_3 ) V_105 . V_112 ;
V_34 -> V_113 = V_105 . V_113 ;
V_34 -> V_114 = V_105 . V_114 ;
V_34 -> V_115 = V_105 . V_115 ;
V_34 -> V_116 = V_117 ;
return V_8 ;
V_110:
F_19 ( V_2 , 0 , V_31 ) ;
V_109:
F_23 ( V_2 , V_31 , 0 ) ;
V_108:
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
F_52 ( V_99 , & V_2 -> V_100 ) ;
V_2 -> V_34 -> V_97 = V_118 ;
V_8 = F_53 ( V_2 , V_46 ) ;
if ( V_8 )
goto V_119;
V_8 = F_27 ( V_2 ) ;
if ( V_8 )
goto V_120;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
goto V_121;
F_54 ( V_2 ) ;
V_8 = F_49 ( V_2 , V_46 ) ;
return V_8 ;
V_121:
F_24 ( V_2 ) ;
V_120:
F_32 ( V_2 ) ;
V_119:
F_33 ( V_99 , & V_2 -> V_100 ) ;
V_2 -> V_34 -> V_97 = V_98 ;
return V_8 ;
}
static int F_55 ( struct V_1 * V_2 , int V_46 )
{
struct V_102 * V_66 = V_2 -> V_66 ;
int V_8 ;
if ( ! ( V_2 -> V_122 & V_123 ) ) {
F_39 ( V_66 ,
L_22 ) ;
return - V_41 ;
}
F_40 () ;
if ( F_41 ( V_66 ) )
F_42 ( V_2 , V_66 ) ;
V_8 = F_51 ( V_2 , V_46 ) ;
if ( V_8 ) {
F_12 ( V_66 , L_23 ,
V_2 -> V_101 ) ;
V_8 = - V_41 ;
if ( F_44 ( V_2 ) )
goto error;
} else {
F_12 ( V_66 ,
L_24 ,
V_2 -> V_101 ) ;
V_8 = V_46 ;
}
if ( F_41 ( V_66 ) )
F_46 ( V_2 , V_66 ) ;
error:
F_45 () ;
return V_8 ;
}
int F_56 ( struct V_124 * V_29 , int V_46 )
{
struct V_1 * V_2 = F_57 ( V_29 ) ;
int V_8 ;
if ( F_58 ( V_125 , & V_2 -> V_100 ) )
return - V_126 ;
if ( V_46 == 0 )
V_8 = F_37 ( V_2 ) ;
else
V_8 = F_55 ( V_2 , V_46 ) ;
F_33 ( V_125 , & V_2 -> V_100 ) ;
return V_8 ;
}
static int F_59 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_6 V_7 ;
struct V_44 * V_45 ;
int V_8 , V_43 ;
T_3 * V_127 ;
V_43 = F_9 ( V_2 , V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_2 -> V_34 -> V_33 -> V_57 [ V_43 ] . V_45 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x3 | V_31 << 16 ;
if ( V_45 -> V_128 == true ) {
V_127 = V_45 -> V_127 ;
V_7 . V_11 . V_12 [ 2 ] |= V_87 | V_129 | V_130 ;
V_7 . V_11 . V_12 [ 4 ] = V_127 [ 5 ] | V_127 [ 4 ] << 8 | V_127 [ 3 ] << 16 |
V_127 [ 2 ] << 24 ;
V_7 . V_11 . V_12 [ 5 ] = V_127 [ 1 ] | V_127 [ 0 ] << 8 ;
}
if ( V_45 -> V_131 == V_132 ) {
V_7 . V_11 . V_12 [ 2 ] |= V_86 ;
V_7 . V_11 . V_12 [ 3 ] |= V_45 -> V_133 << 8 ;
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
struct V_3 V_134 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_134 , V_31 ) ;
if ( V_8 )
return - V_41 ;
V_8 = F_59 ( V_2 , V_31 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_61 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_44 * V_45 = V_137 -> V_45 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
T_1 V_31 = V_137 -> V_52 ;
T_4 V_138 ;
int V_8 ;
V_2 = V_137 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
if ( V_136 -> V_139 -> V_140 == V_141 ) {
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( ! V_8 ) {
V_8 = F_60 ( V_2 , V_31 ) ;
if ( V_8 )
F_19 ( V_2 , 0 , V_31 ) ;
}
} else {
if ( V_45 -> V_131 == V_142 ) {
V_138 = sizeof( * V_137 -> V_143 ) ;
V_138 = V_138 * V_33 -> V_39 ;
memset ( V_137 -> V_143 , 0 , V_138 ) ;
}
V_8 = F_19 ( V_2 , 0 , V_31 ) ;
}
if ( V_8 )
goto V_144;
V_7 -> V_70 . V_12 [ 0 ] |= ( 1 << 25 ) ;
if ( V_136 -> V_139 -> V_140 == V_141 )
F_52 ( V_145 , & V_137 -> V_100 ) ;
else
F_33 ( V_145 , & V_137 -> V_100 ) ;
return V_8 ;
V_144:
V_7 -> V_70 . V_12 [ 0 ] |= ( 2 << 25 ) ;
return V_8 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
T_1 V_146 , T_3 V_147 )
{
struct V_6 V_7 ;
struct V_148 V_149 ;
struct V_44 * V_45 ;
T_3 * V_150 ;
int V_8 ;
T_2 * V_151 ;
int V_42 ;
V_45 = V_137 -> V_45 ;
if ( F_2 ( & V_7 , V_2 , V_152 ) )
return - V_10 ;
V_42 = F_7 ( V_2 , V_137 -> V_52 ) ;
if ( V_42 < 0 ) {
V_8 = - V_49 ;
goto V_68;
}
if ( V_146 )
V_147 = ( ( V_147 == V_153 || V_147 == V_154 ) ?
V_154 : V_155 ) ;
V_7 . V_11 . V_12 [ 1 ] = V_147 | ( 1 << 8 ) | ( 3 << 6 ) ;
V_7 . V_11 . V_12 [ 1 ] |= ( ( V_42 & 0xffff ) << 16 ) | V_156 ;
V_150 = V_45 -> V_127 ;
V_149 . V_146 = V_146 ;
V_149 . V_157 = V_150 [ 0 ] ;
V_149 . V_158 = V_150 [ 1 ] ;
V_149 . V_159 = V_150 [ 2 ] ;
V_149 . V_160 = V_150 [ 3 ] ;
V_149 . V_161 = V_150 [ 4 ] ;
V_149 . V_162 = V_150 [ 5 ] ;
V_151 = & V_7 . V_11 . V_12 [ 2 ] ;
memcpy ( V_151 , & V_149 , sizeof( struct V_148 ) ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_26 ,
( ( V_147 == 1 ) ? L_27 : L_28 ) , V_8 ) ;
V_68:
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_63 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
int V_163 )
{
struct V_32 * V_33 ;
T_1 V_146 ;
int V_92 ;
V_33 = V_2 -> V_34 -> V_33 ;
F_65 ( & V_137 -> V_164 ) ;
if ( V_137 -> V_165 ) {
for ( V_92 = 0 ; V_92 < V_33 -> V_39 ; V_92 ++ ) {
V_146 = V_137 -> V_143 [ V_92 ] ;
if ( V_146 )
F_62 ( V_2 , V_137 , V_146 ,
V_163 ) ;
}
}
F_66 ( & V_137 -> V_164 ) ;
if ( V_137 -> V_45 -> V_131 != V_132 ) {
if ( F_8 ( V_2 ) &&
F_67 ( V_137 ) )
return;
F_62 ( V_2 , V_137 , 0 , V_163 ) ;
}
}
static int F_68 ( struct V_135 * V_166 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_166 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_167 * V_168 ;
int V_8 ;
V_8 = F_63 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 6 ] = V_137 -> V_45 -> V_75 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_168 = (struct V_167 * ) & V_7 -> V_70 . V_12 [ 1 ] ;
V_137 -> V_169 = V_168 -> V_170 ;
F_64 ( V_2 , V_137 , V_153 ) ;
} else {
V_137 -> V_169 = 0 ;
}
return V_8 ;
}
static int F_69 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
T_3 type , * V_127 ;
type = V_7 -> V_11 . V_12 [ 1 ] ;
switch ( type ) {
case V_171 :
case V_172 :
V_7 -> V_70 . V_12 [ 0 ] = ( 2 << 25 ) ;
break;
case V_173 :
V_7 -> V_70 . V_12 [ 0 ] = ( 1 << 25 ) ;
V_127 = V_137 -> V_45 -> V_127 ;
V_7 -> V_70 . V_12 [ 2 ] = V_127 [ 1 ] | ( ( V_127 [ 0 ] << 8 ) & 0xff00 ) ;
V_7 -> V_70 . V_12 [ 1 ] = V_127 [ 5 ] | ( ( V_127 [ 4 ] << 8 ) & 0xff00 ) |
( ( V_127 [ 3 ] ) << 16 & 0xff0000 ) |
( ( V_127 [ 2 ] ) << 24 & 0xff000000 ) ;
}
return 0 ;
}
static int F_70 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static int F_71 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_174 * V_168 ;
int V_8 ;
V_8 = F_70 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 5 ] |= V_137 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_168 = (struct V_174 * ) & V_7 -> V_70 . V_12 [ 2 ] ;
V_137 -> V_175 = V_168 -> V_170 ;
} else {
V_137 -> V_175 = 0 ;
}
return V_8 ;
}
static int F_72 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_137 -> V_169 )
return - V_49 ;
return 0 ;
}
static int F_73 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_72 ( V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
F_64 ( V_2 , V_137 , V_176 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_137 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_137 -> V_169 = 0 ;
return V_8 ;
}
static int F_74 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_137 -> V_175 )
return - V_49 ;
return 0 ;
}
static int F_75 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_74 ( V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 1 ] |= V_137 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_137 -> V_175 = 0 ;
return V_8 ;
}
static int F_76 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_137 -> V_169 )
return - V_49 ;
return 0 ;
}
static int F_77 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_76 ( V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_78 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 = - V_41 ;
T_3 V_147 ;
V_147 = V_7 -> V_11 . V_12 [ 1 ] & 0xff ;
V_7 -> V_11 . V_12 [ 1 ] |= V_137 -> V_45 -> V_75 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_156 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_79 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 8 ) & 0xff ) != V_137 -> V_52 )
return - V_49 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_81 ) )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xff ) != 0x1 )
return - V_49 ;
return 0 ;
}
static int F_80 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_79 ( V_137 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_137 -> V_169 )
return - V_49 ;
if ( V_7 -> V_11 . V_12 [ 2 ] > V_2 -> V_34 -> V_114 )
return - V_49 ;
return 0 ;
}
static int F_82 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_81 ( V_2 , V_137 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_83 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] & V_156 ) {
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) & 0x7fff ) != V_137 -> V_52 )
return - V_49 ;
} else {
V_7 -> V_11 . V_12 [ 1 ] |= V_137 -> V_45 -> V_75 << 16 ;
}
return 0 ;
}
static int F_84 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_83 ( V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_85 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_137 -> V_169 )
return - V_49 ;
return 0 ;
}
static int F_86 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_85 ( V_137 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
struct V_6 * V_7 )
{
struct V_177 * V_178 = & V_2 -> V_34 -> V_178 ;
T_1 V_170 , V_179 , time ;
V_170 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_179 = V_7 -> V_11 . V_12 [ 2 ] & 0xffff ;
time = V_7 -> V_11 . V_12 [ 2 ] >> 16 ;
if ( V_170 != V_137 -> V_169 )
return - V_49 ;
if ( V_179 > V_178 -> V_180 )
return - V_49 ;
if ( time < V_178 -> V_181 )
return - V_49 ;
return 0 ;
}
static int F_88 ( struct V_135 * V_166 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_166 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_87 ( V_2 , V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
struct V_6 * V_7 )
{
struct V_148 * V_182 ;
struct V_44 * V_45 = V_137 -> V_45 ;
T_3 V_147 , V_183 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_130 ) )
return - V_49 ;
V_7 -> V_11 . V_12 [ 1 ] |= ( V_137 -> V_45 -> V_75 << 16 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_156 ;
V_182 = (struct V_148 * ) & V_7 -> V_11 . V_12 [ 2 ] ;
if ( ! ( V_182 -> V_157 & V_88 ) ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_29 ,
V_137 -> V_52 ) ;
return - V_49 ;
}
if ( V_45 -> V_131 == V_132 ) {
V_147 = V_7 -> V_11 . V_12 [ 1 ] & 0x7 ;
V_7 -> V_11 . V_12 [ 1 ] &= ~ 0x7 ;
V_183 = ( V_147 == V_153 || V_147 == V_154 ) ?
V_154 : V_155 ;
V_7 -> V_11 . V_12 [ 3 ] |= V_45 -> V_133 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_183 ;
}
return 0 ;
}
static int F_90 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_89 ( V_2 , V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_91 ( struct V_77 * V_137 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_137 -> V_169 )
return - V_49 ;
return 0 ;
}
static int F_92 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_8 = F_91 ( V_137 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_93 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
int V_8 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_137 -> V_45 -> V_75 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_156 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_94 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_136 -> V_137 ;
struct V_44 * V_45 = V_137 -> V_45 ;
T_3 V_140 , V_184 = V_45 -> V_131 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = V_137 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
V_140 = V_136 -> V_139 -> V_140 ;
V_7 -> V_70 . V_12 [ 0 ] |= 1 << 25 ;
if ( F_21 ( V_2 ) && V_184 == V_132 )
return 0 ;
switch ( V_184 ) {
case V_142 :
V_7 -> V_70 . V_12 [ 1 ] = V_184 | 1 << 8 ;
V_7 -> V_70 . V_12 [ 2 ] = V_33 -> V_39 << 16 ;
break;
case V_132 :
V_7 -> V_70 . V_12 [ 1 ] = V_184 | 1 << 8 | V_45 -> V_133 << 16 ;
break;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
T_1 V_146 ;
if ( ! F_67 ( V_137 ) )
return - V_49 ;
V_146 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_137 -> V_169 ) {
F_96 ( V_33 , V_137 , V_146 ) ;
return 0 ;
}
F_62 ( V_2 , V_137 , V_146 , V_176 ) ;
F_96 ( V_33 , V_137 , V_146 ) ;
if ( F_8 ( V_2 ) )
F_62 ( V_2 , V_137 ,
0 , V_153 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_77 * V_137 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_8 = - V_41 ;
T_1 V_146 ;
if ( F_8 ( V_2 ) && F_67 ( V_137 ) )
return V_8 ;
V_146 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_137 -> V_169 ) {
F_98 ( V_33 , V_137 , V_146 ) ;
return 0 ;
}
if ( F_8 ( V_2 ) ) {
V_8 = F_62 ( V_2 , V_137 , 0 ,
V_176 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_62 ( V_2 , V_137 , V_146 , V_153 ) ;
if ( V_8 ) {
if ( F_8 ( V_2 ) )
F_62 ( V_2 , V_137 , 0 ,
V_153 ) ;
return V_8 ;
}
F_98 ( V_33 , V_137 , V_146 ) ;
return V_8 ;
}
static int F_99 ( struct V_135 * V_166 ,
struct V_6 * V_7 )
{
struct V_77 * V_137 = V_166 -> V_137 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_44 * V_45 = V_137 -> V_45 ;
int V_8 = - V_41 ;
T_3 V_147 ;
if ( V_45 -> V_131 != V_142 ) {
V_7 -> V_70 . V_12 [ 0 ] |= 2 << 25 ;
return V_8 ;
}
V_147 = V_7 -> V_11 . V_12 [ 1 ] & 0xf ;
if ( V_147 )
V_8 = F_97 ( V_2 , V_137 , V_7 ) ;
else
V_8 = F_95 ( V_2 , V_137 , V_7 ) ;
V_7 -> V_70 . V_12 [ 0 ] |= V_8 ? 2 << 25 : 1 << 25 ;
return V_8 ;
}
void F_100 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_6 * V_7 )
{
T_3 V_138 , V_140 ;
V_140 = V_136 -> V_139 -> V_140 ;
if ( V_136 -> V_139 -> V_185 == V_186 ) {
V_138 = F_101 ( V_187 ) ;
if ( V_140 < V_138 ) {
V_187 [ V_140 ] . F_102 ( V_136 , V_7 ) ;
return;
}
} else {
int V_92 ;
V_138 = F_101 ( V_188 ) ;
for ( V_92 = 0 ; V_92 < V_138 ; V_92 ++ ) {
if ( V_140 == V_188 [ V_92 ] . V_7 ) {
V_188 [ V_92 ] . F_102 ( V_136 , V_7 ) ;
return;
}
}
V_138 = F_101 ( V_189 ) ;
for ( V_92 = 0 ; V_92 < V_138 ; V_92 ++ ) {
if ( V_140 == V_189 [ V_92 ] ) {
F_3 ( V_2 , V_7 ) ;
return;
}
}
}
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x9 << 25 ) ;
}
void F_103 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= V_42 ;
}
void F_104 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= V_42 << 16 ;
}
void F_105 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
int V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= V_42 << 16 ;
}
void F_106 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= V_42 << 16 ;
}
void F_107 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= ( V_42 << 16 ) | V_156 ;
}
void F_108 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= ( V_42 << 16 ) | V_156 ;
}
void F_109 ( struct V_1 * V_2 ,
T_2 * V_190 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_190 |= ( V_42 << 16 ) | V_156 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_77 * V_137 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_137 -> V_169 )
return;
if ( F_2 ( & V_7 , V_2 , V_191 ) )
return;
V_42 = F_7 ( V_2 , V_137 -> V_52 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] = V_137 -> V_169 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_30 ,
V_137 -> V_52 ) ;
else
V_137 -> V_169 = 0 ;
}
F_5 ( & V_7 ) ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_77 * V_137 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_137 -> V_175 )
return;
if ( F_2 ( & V_7 , V_2 , V_192 ) )
return;
V_42 = F_7 ( V_2 , V_137 -> V_52 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_137 -> V_175 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_30 ,
V_137 -> V_52 ) ;
else
V_137 -> V_175 = 0 ;
}
F_5 ( & V_7 ) ;
}
static int F_112 ( struct V_32 * V_33 ,
struct V_77 * V_137 ,
struct V_135 * V_136 )
{
struct V_193 * V_194 = & V_137 -> V_195 ;
unsigned long V_78 ;
F_113 ( & V_194 -> V_196 , V_78 ) ;
F_114 ( V_33 , V_137 , V_136 ) ;
F_115 ( & V_194 -> V_196 , V_78 ) ;
return 0 ;
}
static void F_116 ( struct V_77 * V_137 )
{
struct V_1 * V_2 = V_137 -> V_2 ;
F_117 ( & V_137 -> V_197 ) ;
F_25 ( & V_137 -> V_198 ) ;
F_117 ( & V_137 -> V_195 ) ;
if ( F_118 ( V_199 , & V_137 -> V_100 ) ) {
F_111 ( V_2 , V_137 ) ;
F_110 ( V_2 , V_137 ) ;
}
F_19 ( V_2 , 0 , V_137 -> V_52 ) ;
F_33 ( V_200 , & V_137 -> V_100 ) ;
if ( F_118 ( V_199 , & V_137 -> V_100 ) ) {
F_112 ( V_2 -> V_34 -> V_33 , V_137 ,
V_137 -> V_201 ) ;
F_33 ( V_199 , & V_137 -> V_100 ) ;
V_137 -> V_201 = NULL ;
}
}
static void F_119 ( struct V_202 * V_203 )
{
struct V_77 * V_137 ;
V_137 = F_120 ( V_203 , struct V_77 , V_93 ) ;
F_116 ( V_137 ) ;
return;
}
static void F_121 ( struct V_32 * V_33 ,
struct V_77 * V_137 ,
T_5 V_31 )
{
if ( F_118 ( V_125 , & V_137 -> V_2 -> V_100 ) )
return;
F_122 ( & V_137 -> V_93 , V_31 ) ;
F_123 ( V_33 -> V_91 . V_94 , & V_137 -> V_93 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_77 * V_137 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
F_52 ( V_200 , & V_137 -> V_100 ) ;
F_33 ( V_145 , & V_137 -> V_100 ) ;
F_52 ( V_199 , & V_137 -> V_100 ) ;
V_137 -> V_201 = V_136 ;
F_121 ( V_33 , V_137 , F_119 ) ;
F_12 ( V_2 -> V_66 , L_31 ,
V_137 -> V_52 ) ;
}
bool F_125 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_77 * V_137 )
{
struct V_204 * V_205 = V_136 -> V_139 ;
if ( ( V_205 -> V_140 == V_141 ) &&
( V_205 -> V_185 == V_186 ) &&
F_118 ( V_145 , & V_137 -> V_100 ) ) {
F_124 ( V_2 , V_136 , V_137 ) ;
return true ;
}
return false ;
}
void F_126 ( struct V_32 * V_33 ,
struct V_77 * V_137 )
{
struct V_102 * V_29 = V_137 -> V_2 -> V_66 ;
struct V_44 * V_45 = V_137 -> V_45 ;
if ( ! F_127 ( V_145 , & V_137 -> V_100 ) ) {
F_33 ( V_200 , & V_137 -> V_100 ) ;
return;
}
if ( F_58 ( V_200 , & V_137 -> V_100 ) ) {
F_12 ( V_29 , L_32 ,
V_137 -> V_52 ) ;
return;
}
if ( V_45 -> V_131 == V_142 )
memset ( V_137 -> V_143 , 0 ,
sizeof( * V_137 -> V_143 ) * V_33 -> V_39 ) ;
F_121 ( V_33 , V_137 , F_119 ) ;
F_12 ( V_29 , L_33 , V_137 -> V_52 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_104 * V_34 = V_2 -> V_34 ;
struct V_32 * V_33 = V_34 -> V_33 ;
struct V_77 * V_137 ;
T_1 V_46 = V_33 -> V_46 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_46 ; V_92 ++ ) {
V_137 = & V_33 -> V_57 [ V_92 ] ;
V_137 -> V_169 = 0 ;
V_137 -> V_175 = 0 ;
F_25 ( & V_137 -> V_93 ) ;
F_116 ( V_137 ) ;
F_33 ( V_145 , & V_137 -> V_100 ) ;
}
F_17 ( V_2 , V_34 -> V_52 ) ;
F_129 ( V_34 , V_206 , ( V_34 -> V_207 - 1 ) << 8 ) ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_104 * V_34 = V_2 -> V_34 ;
int V_8 ;
if ( ! F_30 ( V_2 ) )
return 0 ;
V_34 -> V_97 = V_118 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_16 ( & V_2 -> V_28 -> V_29 , L_34 ,
V_208 , V_34 -> V_97 ) ;
return V_8 ;
}
int F_131 ( struct V_102 * V_66 , int V_137 , T_3 * V_127 )
{
struct V_1 * V_2 = F_132 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_92 , V_46 ;
struct V_77 * V_57 ;
T_3 * V_209 ;
if ( ! F_35 ( V_2 ) )
return - V_210 ;
V_46 = V_33 -> V_46 ;
if ( ! F_133 ( V_127 ) || V_137 >= V_46 )
return - V_49 ;
if ( F_134 ( V_2 -> V_211 , V_127 ) ) {
F_39 ( V_66 , L_35 ) ;
return - V_49 ;
}
for ( V_92 = 0 ; V_92 < V_46 ; V_92 ++ ) {
V_57 = & V_33 -> V_57 [ V_92 ] ;
if ( F_134 ( V_57 -> V_45 -> V_127 , V_127 ) ) {
F_39 ( V_66 ,
L_36 ,
V_92 ) ;
return - V_49 ;
}
}
V_57 = & V_33 -> V_57 [ V_137 ] ;
V_209 = V_57 -> V_45 -> V_127 ;
if ( F_118 ( V_145 , & V_57 -> V_100 ) ) {
F_39 ( V_66 ,
L_37 ,
V_137 ) ;
return - V_210 ;
}
memcpy ( V_209 , V_127 , V_66 -> V_212 ) ;
F_12 ( V_66 , L_38 ,
V_127 , V_137 ) ;
return 0 ;
}
int F_135 ( struct V_102 * V_66 , int V_137 , int V_213 )
{
struct V_1 * V_2 = F_132 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_3 V_105 ;
struct V_44 * V_45 ;
T_1 V_42 ;
if ( ! F_35 ( V_2 ) )
return - V_210 ;
if ( V_137 >= V_33 -> V_46 )
return - V_49 ;
if ( V_213 >= 10000 || V_213 < 100 ) {
F_39 ( V_66 ,
L_39 ,
V_214 , V_215 ) ;
return - V_49 ;
}
if ( V_213 == 0 )
V_213 = 10000 ;
V_57 = & V_33 -> V_57 [ V_137 ] ;
V_45 = V_57 -> V_45 ;
V_42 = V_45 -> V_75 ;
if ( F_118 ( V_145 , & V_57 -> V_100 ) ) {
if ( F_136 ( V_2 , & V_105 , V_42 ) )
return - V_41 ;
V_105 . V_15 = V_213 / 100 ;
V_105 . V_13 = V_88 ;
if ( F_1 ( V_2 , & V_105 , V_42 ) )
return - V_41 ;
}
V_45 -> V_15 = V_213 / 100 ;
F_12 ( V_66 ,
L_40 ,
V_213 , V_45 -> V_15 , V_137 ) ;
return 0 ;
}
int F_137 ( struct V_102 * V_66 , int V_137 ,
T_1 V_146 , T_3 V_216 )
{
struct V_1 * V_2 = F_132 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_210 ;
if ( V_137 >= V_33 -> V_46 || V_216 > 7 )
return - V_49 ;
if ( V_146 > V_217 ) {
F_39 ( V_66 ,
L_41 ,
V_217 ) ;
return - V_49 ;
}
V_57 = & V_33 -> V_57 [ V_137 ] ;
V_45 = V_57 -> V_45 ;
if ( F_118 ( V_145 , & V_57 -> V_100 ) ) {
F_39 ( V_66 ,
L_42 ,
V_137 ) ;
return - V_210 ;
}
memset ( V_57 -> V_143 , 0 ,
sizeof( * V_57 -> V_143 ) * V_33 -> V_39 ) ;
switch ( V_146 ) {
case 4095 :
V_45 -> V_131 = V_142 ;
break;
case 0 :
V_45 -> V_131 = V_218 ;
V_45 -> V_216 = 0 ;
break;
default:
V_45 -> V_131 = V_132 ;
F_98 ( V_33 , V_57 , V_146 ) ;
V_45 -> V_216 = V_216 ;
V_45 -> V_133 = V_146 ;
}
F_12 ( V_66 , L_43 ,
V_146 , V_216 , V_137 ) ;
return 0 ;
}
static T_6 F_138 ( struct V_1 * V_2 ,
struct V_44 * V_45 , int V_137 )
{
T_6 V_146 = 0 ;
switch ( V_45 -> V_131 ) {
case V_132 :
V_146 = V_45 -> V_133 ;
break;
case V_142 :
V_146 = V_217 ;
break;
case V_218 :
V_146 = 0 ;
break;
default:
F_12 ( V_2 -> V_66 , L_44 ,
V_45 -> V_131 , V_137 ) ;
}
return V_146 ;
}
int F_139 ( struct V_102 * V_66 ,
int V_137 , struct V_219 * V_220 )
{
struct V_1 * V_2 = F_132 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_210 ;
if ( V_137 >= V_33 -> V_46 )
return - V_49 ;
V_45 = V_33 -> V_57 [ V_137 ] . V_45 ;
memcpy ( & V_220 -> V_127 , V_45 -> V_127 , V_221 ) ;
V_220 -> V_146 = F_138 ( V_2 , V_45 , V_137 ) ;
V_220 -> V_216 = V_45 -> V_216 ;
V_220 -> V_128 = V_45 -> V_128 ;
if ( V_45 -> V_15 == V_53 )
V_220 -> V_213 = 0 ;
else
V_220 -> V_213 = V_45 -> V_15 * 100 ;
V_220 -> V_137 = V_137 ;
return 0 ;
}
int F_140 ( struct V_102 * V_66 , int V_137 , bool V_222 )
{
struct V_1 * V_2 = F_132 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_44 * V_45 ;
if ( ! F_35 ( V_2 ) )
return - V_210 ;
if ( V_137 >= V_33 -> V_46 )
return - V_49 ;
V_57 = & V_33 -> V_57 [ V_137 ] ;
V_45 = V_57 -> V_45 ;
if ( F_118 ( V_145 , & V_57 -> V_100 ) ) {
F_39 ( V_66 ,
L_45 ,
V_137 ) ;
return - V_210 ;
}
V_45 -> V_128 = V_222 ;
return 0 ;
}
