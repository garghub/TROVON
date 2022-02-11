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
if ( V_80 )
V_7 . V_11 . V_12 [ 1 ] |= V_81 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_14 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_8 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = V_82 | V_83 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_15 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
T_3 V_31 , T_3 V_80 )
{
struct V_6 V_7 ;
int V_8 = - V_41 ;
if ( F_2 ( & V_7 , V_2 , V_84 ) )
return - V_10 ;
V_7 . V_11 . V_12 [ 0 ] |= ( 3 << 29 ) ;
V_7 . V_11 . V_12 [ 1 ] = ( ( V_31 & 0xf ) << 2 ) | V_85 | V_86 ;
if ( V_80 )
V_7 . V_11 . V_12 [ 1 ] |= V_87 ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 != V_88 ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_16 , V_8 ) ;
V_8 = - V_41 ;
}
F_5 ( & V_7 ) ;
return V_8 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_89 * V_90 = & V_33 -> V_90 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_33 -> V_46 ; V_91 ++ )
F_24 ( & V_33 -> V_57 [ V_91 ] . V_92 ) ;
F_25 ( V_90 -> V_93 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = & V_2 -> V_34 -> V_33 -> V_90 ;
struct V_94 * V_95 ;
V_95 = F_27 ( L_17 ) ;
if ( V_95 == NULL ) {
F_4 ( & V_2 -> V_28 -> V_29 , L_18 ) ;
return - V_10 ;
}
V_90 -> V_93 = V_95 ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
T_3 V_31 = V_2 -> V_34 -> V_52 ;
if ( ! F_29 ( V_2 ) )
return;
F_23 ( V_2 ) ;
F_30 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 , V_31 ) ;
F_22 ( V_2 , V_31 , 0 ) ;
F_20 ( V_2 , 0 ) ;
F_31 ( V_2 ) ;
V_2 -> V_34 -> V_96 = V_97 ;
F_32 ( V_98 , & V_2 -> V_99 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( ! F_34 ( V_2 ) )
return;
if ( ! F_29 ( V_2 ) )
return;
F_35 ( V_2 -> V_28 ) ;
F_12 ( V_2 -> V_66 ,
L_19 ,
V_2 -> V_100 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_101 * V_66 = V_2 -> V_66 ;
F_37 () ;
if ( F_38 ( V_66 ) )
F_39 ( V_2 , V_66 ) ;
F_33 ( V_2 ) ;
F_40 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( F_41 ( V_2 ) ) {
F_42 () ;
return - V_41 ;
}
if ( F_38 ( V_66 ) )
F_43 ( V_2 , V_66 ) ;
F_42 () ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_102 * V_34 = V_2 -> V_34 ;
struct V_3 V_103 , V_104 , V_105 ;
int V_8 ;
T_3 V_31 = V_34 -> V_52 ;
if ( ! F_29 ( V_2 ) )
return 0 ;
V_8 = F_20 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( F_45 ( V_2 ) ) {
V_8 = F_21 ( V_2 ) ;
if ( V_8 )
goto V_106;
}
V_8 = F_22 ( V_2 , V_31 , 1 ) ;
if ( V_8 )
goto V_106;
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( V_8 )
goto V_107;
V_8 = F_13 ( V_2 , & V_104 ) ;
if ( V_8 )
goto V_108;
V_8 = F_46 ( V_2 , & V_103 , V_31 ) ;
if ( V_8 )
goto V_108;
V_8 = F_6 ( V_2 , & V_105 , V_31 ) ;
if ( V_8 )
goto V_108;
V_8 = F_30 ( V_2 , 1 ) ;
if ( V_8 )
goto V_108;
V_34 -> V_109 = ( T_3 ) V_103 . V_110 ;
V_34 -> V_111 = V_103 . V_111 ;
V_34 -> V_112 = V_103 . V_112 ;
V_34 -> V_113 = V_103 . V_113 ;
V_34 -> V_114 = V_115 ;
return V_8 ;
V_108:
F_19 ( V_2 , 0 , V_31 ) ;
V_107:
F_22 ( V_2 , V_31 , 0 ) ;
V_106:
F_20 ( V_2 , 0 ) ;
return V_8 ;
}
static int F_47 ( struct V_1 * V_2 , int V_46 )
{
int V_8 ;
if ( ! F_29 ( V_2 ) )
return 0 ;
V_8 = F_48 ( V_2 -> V_28 , V_46 ) ;
if ( V_8 )
F_28 ( V_2 ) ;
return V_8 ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_46 )
{
int V_8 = 0 ;
F_50 ( V_98 , & V_2 -> V_99 ) ;
V_2 -> V_34 -> V_96 = V_116 ;
V_8 = F_51 ( V_2 , V_46 ) ;
if ( V_8 )
goto V_117;
V_8 = F_26 ( V_2 ) ;
if ( V_8 )
goto V_118;
V_8 = F_44 ( V_2 ) ;
if ( V_8 )
goto V_119;
F_52 ( V_2 ) ;
V_8 = F_47 ( V_2 , V_46 ) ;
return V_8 ;
V_119:
F_23 ( V_2 ) ;
V_118:
F_31 ( V_2 ) ;
V_117:
F_32 ( V_98 , & V_2 -> V_99 ) ;
V_2 -> V_34 -> V_96 = V_97 ;
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 , int V_46 )
{
struct V_101 * V_66 = V_2 -> V_66 ;
int V_8 ;
if ( ! ( V_2 -> V_120 & V_121 ) ) {
F_54 ( V_66 ,
L_20 ) ;
return - V_41 ;
}
F_37 () ;
if ( F_38 ( V_66 ) )
F_39 ( V_2 , V_66 ) ;
V_8 = F_49 ( V_2 , V_46 ) ;
if ( V_8 ) {
F_12 ( V_66 , L_21 ,
V_2 -> V_100 ) ;
V_8 = - V_41 ;
if ( F_41 ( V_2 ) )
goto error;
} else {
F_12 ( V_66 ,
L_22 ,
V_2 -> V_100 ) ;
V_8 = V_46 ;
}
if ( F_38 ( V_66 ) )
F_43 ( V_2 , V_66 ) ;
error:
F_42 () ;
return V_8 ;
}
int F_55 ( struct V_122 * V_29 , int V_46 )
{
struct V_1 * V_2 = F_56 ( V_29 ) ;
int V_8 ;
if ( F_57 ( V_123 , & V_2 -> V_99 ) )
return - V_124 ;
if ( V_46 == 0 )
V_8 = F_36 ( V_2 ) ;
else
V_8 = F_53 ( V_2 , V_46 ) ;
F_32 ( V_123 , & V_2 -> V_99 ) ;
return V_8 ;
}
static int F_58 ( struct V_1 * V_2 , T_3 V_31 )
{
struct V_6 V_7 ;
struct V_44 * V_45 ;
int V_8 , V_43 ;
T_3 * V_125 ;
V_43 = F_9 ( V_2 , V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_2 -> V_34 -> V_33 -> V_57 [ V_43 ] . V_45 ;
V_8 = F_2 ( & V_7 , V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 . V_11 . V_12 [ 1 ] = 0x3 | V_31 << 16 ;
if ( V_45 -> V_126 == true ) {
V_125 = V_45 -> V_125 ;
V_7 . V_11 . V_12 [ 2 ] |= V_86 | V_127 | V_128 ;
V_7 . V_11 . V_12 [ 4 ] = V_125 [ 5 ] | V_125 [ 4 ] << 8 | V_125 [ 3 ] << 16 |
V_125 [ 2 ] << 24 ;
V_7 . V_11 . V_12 [ 5 ] = V_125 [ 1 ] | V_125 [ 0 ] << 8 ;
}
if ( V_45 -> V_129 == V_130 ) {
V_7 . V_11 . V_12 [ 2 ] |= V_85 ;
V_7 . V_11 . V_12 [ 3 ] |= V_45 -> V_131 << 8 ;
}
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 , L_23 ,
V_8 ) ;
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_3 V_132 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_132 , V_31 ) ;
if ( V_8 )
return - V_41 ;
V_8 = F_58 ( V_2 , V_31 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_60 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_44 * V_45 = V_135 -> V_45 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
T_1 V_31 = V_135 -> V_52 ;
T_4 V_136 ;
int V_8 ;
V_2 = V_135 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
if ( V_134 -> V_137 -> V_138 == V_139 ) {
V_8 = F_19 ( V_2 , 1 , V_31 ) ;
if ( ! V_8 ) {
V_8 = F_59 ( V_2 , V_31 ) ;
if ( V_8 )
F_19 ( V_2 , 0 , V_31 ) ;
}
} else {
if ( V_45 -> V_129 == V_140 ) {
V_136 = sizeof( * V_135 -> V_141 ) ;
V_136 = V_136 * V_33 -> V_39 ;
memset ( V_135 -> V_141 , 0 , V_136 ) ;
}
V_8 = F_19 ( V_2 , 0 , V_31 ) ;
}
if ( V_8 )
goto V_142;
V_7 -> V_70 . V_12 [ 0 ] |= ( 1 << 25 ) ;
if ( V_134 -> V_137 -> V_138 == V_139 )
F_50 ( V_143 , & V_135 -> V_99 ) ;
else
F_32 ( V_143 , & V_135 -> V_99 ) ;
return V_8 ;
V_142:
V_7 -> V_70 . V_12 [ 0 ] |= ( 2 << 25 ) ;
return V_8 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
T_1 V_144 , T_3 V_145 )
{
struct V_6 V_7 ;
struct V_146 V_147 ;
struct V_44 * V_45 ;
T_3 * V_148 ;
int V_8 ;
T_2 * V_149 ;
int V_42 ;
V_45 = V_135 -> V_45 ;
if ( F_2 ( & V_7 , V_2 , V_150 ) )
return - V_10 ;
V_42 = F_7 ( V_2 , V_135 -> V_52 ) ;
if ( V_42 < 0 ) {
V_8 = - V_49 ;
goto V_68;
}
if ( V_144 )
V_145 = ( ( V_145 == V_151 || V_145 == V_152 ) ?
V_152 : V_153 ) ;
V_7 . V_11 . V_12 [ 1 ] = V_145 | ( 1 << 8 ) | ( 3 << 6 ) ;
V_7 . V_11 . V_12 [ 1 ] |= ( ( V_42 & 0xffff ) << 16 ) | V_154 ;
V_148 = V_45 -> V_125 ;
V_147 . V_144 = V_144 ;
V_147 . V_155 = V_148 [ 0 ] ;
V_147 . V_156 = V_148 [ 1 ] ;
V_147 . V_157 = V_148 [ 2 ] ;
V_147 . V_158 = V_148 [ 3 ] ;
V_147 . V_159 = V_148 [ 4 ] ;
V_147 . V_160 = V_148 [ 5 ] ;
V_149 = & V_7 . V_11 . V_12 [ 2 ] ;
memcpy ( V_149 , & V_147 , sizeof( struct V_146 ) ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_24 ,
( ( V_145 == 1 ) ? L_25 : L_26 ) , V_8 ) ;
V_68:
F_5 ( & V_7 ) ;
return V_8 ;
}
static int F_62 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
int V_161 )
{
struct V_32 * V_33 ;
T_1 V_144 ;
int V_91 ;
V_33 = V_2 -> V_34 -> V_33 ;
F_64 ( & V_135 -> V_162 ) ;
if ( V_135 -> V_163 ) {
for ( V_91 = 0 ; V_91 < V_33 -> V_39 ; V_91 ++ ) {
V_144 = V_135 -> V_141 [ V_91 ] ;
if ( V_144 )
F_61 ( V_2 , V_135 , V_144 ,
V_161 ) ;
}
}
F_65 ( & V_135 -> V_162 ) ;
if ( V_135 -> V_45 -> V_129 != V_130 ) {
if ( F_8 ( V_2 ) &&
F_66 ( V_135 ) )
return;
F_61 ( V_2 , V_135 , 0 , V_161 ) ;
}
}
static int F_67 ( struct V_133 * V_164 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_164 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_165 * V_166 ;
int V_8 ;
V_8 = F_62 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 6 ] = V_135 -> V_45 -> V_75 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_166 = (struct V_165 * ) & V_7 -> V_70 . V_12 [ 1 ] ;
V_135 -> V_167 = V_166 -> V_168 ;
F_63 ( V_2 , V_135 , V_151 ) ;
} else {
V_135 -> V_167 = 0 ;
}
return V_8 ;
}
static int F_68 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
T_3 type , * V_125 ;
type = V_7 -> V_11 . V_12 [ 1 ] ;
switch ( type ) {
case V_169 :
case V_170 :
V_7 -> V_70 . V_12 [ 0 ] = ( 2 << 25 ) ;
break;
case V_171 :
V_7 -> V_70 . V_12 [ 0 ] = ( 1 << 25 ) ;
V_125 = V_135 -> V_45 -> V_125 ;
V_7 -> V_70 . V_12 [ 2 ] = V_125 [ 1 ] | ( ( V_125 [ 0 ] << 8 ) & 0xff00 ) ;
V_7 -> V_70 . V_12 [ 1 ] = V_125 [ 5 ] | ( ( V_125 [ 4 ] << 8 ) & 0xff00 ) |
( ( V_125 [ 3 ] ) << 16 & 0xff0000 ) |
( ( V_125 [ 2 ] ) << 24 & 0xff000000 ) ;
}
return 0 ;
}
static int F_69 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
return 0 ;
}
static int F_70 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_172 * V_166 ;
int V_8 ;
V_8 = F_69 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 5 ] |= V_135 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
V_166 = (struct V_172 * ) & V_7 -> V_70 . V_12 [ 2 ] ;
V_135 -> V_173 = V_166 -> V_168 ;
} else {
V_135 -> V_173 = 0 ;
}
return V_8 ;
}
static int F_71 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_135 -> V_167 )
return - V_49 ;
return 0 ;
}
static int F_72 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_71 ( V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
F_63 ( V_2 , V_135 , V_174 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_135 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_135 -> V_167 = 0 ;
return V_8 ;
}
static int F_73 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 0 ] >> 29 ) != 0x3 )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xffff ) != V_135 -> V_173 )
return - V_49 ;
return 0 ;
}
static int F_74 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_73 ( V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_7 -> V_11 . V_12 [ 1 ] |= V_135 -> V_45 -> V_75 << 16 ;
V_8 = F_3 ( V_2 , V_7 ) ;
if ( ! V_8 )
V_135 -> V_173 = 0 ;
return V_8 ;
}
static int F_75 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_135 -> V_167 )
return - V_49 ;
return 0 ;
}
static int F_76 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_75 ( V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_77 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 = - V_41 ;
T_3 V_145 ;
V_145 = V_7 -> V_11 . V_12 [ 1 ] & 0xff ;
V_7 -> V_11 . V_12 [ 1 ] |= V_135 -> V_45 -> V_75 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_154 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_78 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 8 ) & 0xff ) != V_135 -> V_52 )
return - V_49 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_81 ) )
return - V_49 ;
if ( ( V_7 -> V_11 . V_12 [ 1 ] & 0xff ) != 0x1 )
return - V_49 ;
return 0 ;
}
static int F_79 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_78 ( V_135 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_135 -> V_167 )
return - V_49 ;
if ( V_7 -> V_11 . V_12 [ 2 ] > V_2 -> V_34 -> V_112 )
return - V_49 ;
return 0 ;
}
static int F_81 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_80 ( V_2 , V_135 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_82 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] & V_154 ) {
if ( ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) & 0x7fff ) != V_135 -> V_52 )
return - V_49 ;
} else {
V_7 -> V_11 . V_12 [ 1 ] |= V_135 -> V_45 -> V_75 << 16 ;
}
return 0 ;
}
static int F_83 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_82 ( V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_84 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 [ 1 ] != V_135 -> V_167 )
return - V_49 ;
return 0 ;
}
static int F_85 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_84 ( V_135 , V_7 ) ;
if ( V_8 )
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
else
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
struct V_6 * V_7 )
{
struct V_175 * V_176 = & V_2 -> V_34 -> V_176 ;
T_1 V_168 , V_177 , time ;
V_168 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
V_177 = V_7 -> V_11 . V_12 [ 2 ] & 0xffff ;
time = V_7 -> V_11 . V_12 [ 2 ] >> 16 ;
if ( V_168 != V_135 -> V_167 )
return - V_49 ;
if ( V_177 > V_176 -> V_178 )
return - V_49 ;
if ( time < V_176 -> V_179 )
return - V_49 ;
return 0 ;
}
static int F_87 ( struct V_133 * V_164 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_164 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_86 ( V_2 , V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
struct V_6 * V_7 )
{
struct V_146 * V_180 ;
struct V_44 * V_45 = V_135 -> V_45 ;
T_3 V_145 , V_181 ;
if ( ! ( V_7 -> V_11 . V_12 [ 1 ] & V_128 ) )
return - V_49 ;
V_7 -> V_11 . V_12 [ 1 ] |= ( V_135 -> V_45 -> V_75 << 16 ) ;
V_7 -> V_11 . V_12 [ 1 ] |= V_154 ;
V_180 = (struct V_146 * ) & V_7 -> V_11 . V_12 [ 2 ] ;
if ( ! ( V_180 -> V_155 & V_87 ) ) {
F_4 ( & V_2 -> V_28 -> V_29 ,
L_27 ,
V_135 -> V_52 ) ;
return - V_49 ;
}
if ( V_45 -> V_129 == V_130 ) {
V_145 = V_7 -> V_11 . V_12 [ 1 ] & 0x7 ;
V_7 -> V_11 . V_12 [ 1 ] &= ~ 0x7 ;
V_181 = ( V_145 == V_151 || V_145 == V_152 ) ?
V_152 : V_153 ;
V_7 -> V_11 . V_12 [ 3 ] |= V_45 -> V_131 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_181 ;
}
return 0 ;
}
static int F_89 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_88 ( V_2 , V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_90 ( struct V_77 * V_135 ,
struct V_6 * V_7 )
{
if ( ( V_7 -> V_11 . V_12 [ 1 ] >> 16 ) != V_135 -> V_167 )
return - V_49 ;
return 0 ;
}
static int F_91 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_8 = F_90 ( V_135 , V_7 ) ;
if ( V_8 ) {
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x6 << 25 ) ;
return V_8 ;
}
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_92 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
int V_8 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_135 -> V_45 -> V_75 << 16 ;
V_7 -> V_11 . V_12 [ 1 ] |= V_154 ;
V_8 = F_3 ( V_2 , V_7 ) ;
return V_8 ;
}
static int F_93 ( struct V_133 * V_134 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_134 -> V_135 ;
struct V_44 * V_45 = V_135 -> V_45 ;
T_3 V_138 , V_182 = V_45 -> V_129 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = V_135 -> V_2 ;
V_33 = V_2 -> V_34 -> V_33 ;
V_138 = V_134 -> V_137 -> V_138 ;
V_7 -> V_70 . V_12 [ 0 ] |= 1 << 25 ;
if ( F_45 ( V_2 ) && V_182 == V_130 )
return 0 ;
switch ( V_182 ) {
case V_140 :
V_7 -> V_70 . V_12 [ 1 ] = V_182 | 1 << 8 ;
V_7 -> V_70 . V_12 [ 2 ] = V_33 -> V_39 << 16 ;
break;
case V_130 :
V_7 -> V_70 . V_12 [ 1 ] = V_182 | 1 << 8 | V_45 -> V_131 << 16 ;
break;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
T_1 V_144 ;
if ( ! F_66 ( V_135 ) )
return - V_49 ;
V_144 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_135 -> V_167 ) {
F_95 ( V_33 , V_135 , V_144 ) ;
return 0 ;
}
F_61 ( V_2 , V_135 , V_144 , V_174 ) ;
F_95 ( V_33 , V_135 , V_144 ) ;
if ( F_8 ( V_2 ) )
F_61 ( V_2 , V_135 ,
0 , V_151 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_77 * V_135 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_8 = - V_41 ;
T_1 V_144 ;
if ( F_8 ( V_2 ) && F_66 ( V_135 ) )
return V_8 ;
V_144 = V_7 -> V_11 . V_12 [ 1 ] >> 16 ;
if ( ! V_135 -> V_167 ) {
F_97 ( V_33 , V_135 , V_144 ) ;
return 0 ;
}
if ( F_8 ( V_2 ) ) {
V_8 = F_61 ( V_2 , V_135 , 0 ,
V_174 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_61 ( V_2 , V_135 , V_144 , V_151 ) ;
if ( V_8 ) {
if ( F_8 ( V_2 ) )
F_61 ( V_2 , V_135 , 0 ,
V_151 ) ;
return V_8 ;
}
F_97 ( V_33 , V_135 , V_144 ) ;
return V_8 ;
}
static int F_98 ( struct V_133 * V_164 ,
struct V_6 * V_7 )
{
struct V_77 * V_135 = V_164 -> V_135 ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_44 * V_45 = V_135 -> V_45 ;
int V_8 = - V_41 ;
T_3 V_145 ;
if ( V_45 -> V_129 != V_140 ) {
V_7 -> V_70 . V_12 [ 0 ] |= 2 << 25 ;
return V_8 ;
}
V_145 = V_7 -> V_11 . V_12 [ 1 ] & 0xf ;
if ( V_145 )
V_8 = F_96 ( V_2 , V_135 , V_7 ) ;
else
V_8 = F_94 ( V_2 , V_135 , V_7 ) ;
V_7 -> V_70 . V_12 [ 0 ] |= V_8 ? 2 << 25 : 1 << 25 ;
return V_8 ;
}
void F_99 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
struct V_6 * V_7 )
{
T_3 V_136 , V_138 ;
V_138 = V_134 -> V_137 -> V_138 ;
if ( V_134 -> V_137 -> V_183 == V_184 ) {
V_136 = F_100 ( V_185 ) ;
if ( V_138 < V_136 ) {
V_185 [ V_138 ] . F_101 ( V_134 , V_7 ) ;
return;
}
} else {
int V_91 ;
V_136 = F_100 ( V_186 ) ;
for ( V_91 = 0 ; V_91 < V_136 ; V_91 ++ ) {
if ( V_138 == V_186 [ V_91 ] . V_7 ) {
V_186 [ V_91 ] . F_101 ( V_134 , V_7 ) ;
return;
}
}
V_136 = F_100 ( V_187 ) ;
for ( V_91 = 0 ; V_91 < V_136 ; V_91 ++ ) {
if ( V_138 == V_187 [ V_91 ] ) {
F_3 ( V_2 , V_7 ) ;
return;
}
}
}
V_7 -> V_70 . V_12 [ 0 ] |= ( 0x9 << 25 ) ;
}
void F_102 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= V_42 ;
}
void F_103 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= V_42 << 16 ;
}
void F_104 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
int V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= V_42 << 16 ;
}
void F_105 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= V_42 << 16 ;
}
void F_106 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= ( V_42 << 16 ) | V_154 ;
}
void F_107 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= ( V_42 << 16 ) | V_154 ;
}
void F_108 ( struct V_1 * V_2 ,
T_2 * V_188 )
{
T_1 V_42 ;
V_42 = F_7 ( V_2 ,
V_2 -> V_34 -> V_52 ) ;
* V_188 |= ( V_42 << 16 ) | V_154 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_77 * V_135 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_135 -> V_167 )
return;
if ( F_2 ( & V_7 , V_2 , V_189 ) )
return;
V_42 = F_7 ( V_2 , V_135 -> V_52 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] = V_135 -> V_167 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_28 ,
V_135 -> V_52 ) ;
else
V_135 -> V_167 = 0 ;
}
F_5 ( & V_7 ) ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_77 * V_135 )
{
struct V_6 V_7 ;
int V_42 ;
if ( ! V_135 -> V_173 )
return;
if ( F_2 ( & V_7 , V_2 , V_190 ) )
return;
V_42 = F_7 ( V_2 , V_135 -> V_52 ) ;
if ( V_42 >= 0 ) {
V_7 . V_11 . V_12 [ 1 ] |= V_135 -> V_173 | ( V_42 & 0xffff ) << 16 ;
if ( F_3 ( V_2 , & V_7 ) )
F_4 ( & V_2 -> V_28 -> V_29 ,
L_28 ,
V_135 -> V_52 ) ;
else
V_135 -> V_173 = 0 ;
}
F_5 ( & V_7 ) ;
}
static int F_111 ( struct V_32 * V_33 ,
struct V_77 * V_135 ,
struct V_133 * V_134 )
{
struct V_191 * V_192 = & V_135 -> V_193 ;
unsigned long V_78 ;
F_112 ( & V_192 -> V_194 , V_78 ) ;
F_113 ( V_33 , V_135 , V_134 ) ;
F_114 ( & V_192 -> V_194 , V_78 ) ;
return 0 ;
}
static void F_115 ( struct V_77 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
F_116 ( & V_135 -> V_195 ) ;
F_24 ( & V_135 -> V_196 ) ;
F_116 ( & V_135 -> V_193 ) ;
if ( F_117 ( V_197 , & V_135 -> V_99 ) ) {
F_110 ( V_2 , V_135 ) ;
F_109 ( V_2 , V_135 ) ;
}
F_19 ( V_2 , 0 , V_135 -> V_52 ) ;
F_32 ( V_198 , & V_135 -> V_99 ) ;
if ( F_117 ( V_197 , & V_135 -> V_99 ) ) {
F_111 ( V_2 -> V_34 -> V_33 , V_135 ,
V_135 -> V_199 ) ;
F_32 ( V_197 , & V_135 -> V_99 ) ;
V_135 -> V_199 = NULL ;
}
}
static void F_118 ( struct V_200 * V_201 )
{
struct V_77 * V_135 ;
V_135 = F_119 ( V_201 , struct V_77 , V_92 ) ;
F_115 ( V_135 ) ;
return;
}
static void F_120 ( struct V_32 * V_33 ,
struct V_77 * V_135 ,
T_5 V_31 )
{
if ( F_117 ( V_123 , & V_135 -> V_2 -> V_99 ) )
return;
F_121 ( & V_135 -> V_92 , V_31 ) ;
F_122 ( V_33 -> V_90 . V_93 , & V_135 -> V_92 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
struct V_77 * V_135 )
{
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
F_50 ( V_198 , & V_135 -> V_99 ) ;
F_32 ( V_143 , & V_135 -> V_99 ) ;
F_50 ( V_197 , & V_135 -> V_99 ) ;
V_135 -> V_199 = V_134 ;
F_120 ( V_33 , V_135 , F_118 ) ;
F_12 ( V_2 -> V_66 , L_29 ,
V_135 -> V_52 ) ;
}
bool F_124 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
struct V_77 * V_135 )
{
struct V_202 * V_203 = V_134 -> V_137 ;
if ( ( V_203 -> V_138 == V_139 ) &&
( V_203 -> V_183 == V_184 ) &&
F_117 ( V_143 , & V_135 -> V_99 ) ) {
F_123 ( V_2 , V_134 , V_135 ) ;
return true ;
}
return false ;
}
void F_125 ( struct V_32 * V_33 ,
struct V_77 * V_135 )
{
struct V_101 * V_29 = V_135 -> V_2 -> V_66 ;
struct V_44 * V_45 = V_135 -> V_45 ;
if ( ! F_126 ( V_143 , & V_135 -> V_99 ) ) {
F_32 ( V_198 , & V_135 -> V_99 ) ;
return;
}
if ( F_57 ( V_198 , & V_135 -> V_99 ) ) {
F_12 ( V_29 , L_30 ,
V_135 -> V_52 ) ;
return;
}
if ( V_45 -> V_129 == V_140 )
memset ( V_135 -> V_141 , 0 ,
sizeof( * V_135 -> V_141 ) * V_33 -> V_39 ) ;
F_120 ( V_33 , V_135 , F_118 ) ;
F_12 ( V_29 , L_31 , V_135 -> V_52 ) ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_102 * V_34 = V_2 -> V_34 ;
struct V_32 * V_33 = V_34 -> V_33 ;
struct V_77 * V_135 ;
T_1 V_46 = V_33 -> V_46 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_46 ; V_91 ++ ) {
V_135 = & V_33 -> V_57 [ V_91 ] ;
V_135 -> V_167 = 0 ;
V_135 -> V_173 = 0 ;
F_24 ( & V_135 -> V_92 ) ;
F_115 ( V_135 ) ;
F_32 ( V_143 , & V_135 -> V_99 ) ;
}
F_17 ( V_2 , V_34 -> V_52 ) ;
F_128 ( V_34 , V_204 , ( V_34 -> V_205 - 1 ) << 8 ) ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_102 * V_34 = V_2 -> V_34 ;
int V_8 ;
if ( ! F_29 ( V_2 ) )
return 0 ;
V_34 -> V_96 = V_116 ;
V_8 = F_44 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_16 ( & V_2 -> V_28 -> V_29 , L_32 ,
V_206 , V_34 -> V_96 ) ;
return V_8 ;
}
int F_130 ( struct V_101 * V_66 , int V_135 , T_3 * V_125 )
{
struct V_1 * V_2 = F_131 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
int V_91 , V_46 ;
struct V_77 * V_57 ;
T_3 * V_207 ;
if ( ! F_34 ( V_2 ) )
return - V_208 ;
V_46 = V_33 -> V_46 ;
if ( ! F_132 ( V_125 ) || V_135 >= V_46 )
return - V_49 ;
if ( F_133 ( V_2 -> V_209 , V_125 ) ) {
F_54 ( V_66 , L_33 ) ;
return - V_49 ;
}
for ( V_91 = 0 ; V_91 < V_46 ; V_91 ++ ) {
V_57 = & V_33 -> V_57 [ V_91 ] ;
if ( F_133 ( V_57 -> V_45 -> V_125 , V_125 ) ) {
F_54 ( V_66 ,
L_34 ,
V_91 ) ;
return - V_49 ;
}
}
V_57 = & V_33 -> V_57 [ V_135 ] ;
V_207 = V_57 -> V_45 -> V_125 ;
if ( F_117 ( V_143 , & V_57 -> V_99 ) ) {
F_54 ( V_66 ,
L_35 ,
V_135 ) ;
return - V_208 ;
}
memcpy ( V_207 , V_125 , V_66 -> V_210 ) ;
F_12 ( V_66 , L_36 ,
V_125 , V_135 ) ;
return 0 ;
}
int F_134 ( struct V_101 * V_66 , int V_135 , int V_211 )
{
struct V_1 * V_2 = F_131 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_3 V_103 ;
struct V_44 * V_45 ;
T_1 V_42 ;
if ( ! F_34 ( V_2 ) )
return - V_208 ;
if ( V_135 >= V_33 -> V_46 )
return - V_49 ;
if ( V_211 >= 10000 || V_211 < 100 ) {
F_54 ( V_66 ,
L_37 ,
V_212 , V_213 ) ;
return - V_49 ;
}
if ( V_211 == 0 )
V_211 = 10000 ;
V_57 = & V_33 -> V_57 [ V_135 ] ;
V_45 = V_57 -> V_45 ;
V_42 = V_45 -> V_75 ;
if ( F_117 ( V_143 , & V_57 -> V_99 ) ) {
if ( F_135 ( V_2 , & V_103 , V_42 ) )
return - V_41 ;
V_103 . V_15 = V_211 / 100 ;
V_103 . V_13 = V_87 ;
if ( F_1 ( V_2 , & V_103 , V_42 ) )
return - V_41 ;
}
V_45 -> V_15 = V_211 / 100 ;
F_12 ( V_66 ,
L_38 ,
V_211 , V_45 -> V_15 , V_135 ) ;
return 0 ;
}
int F_136 ( struct V_101 * V_66 , int V_135 ,
T_1 V_144 , T_3 V_214 )
{
struct V_1 * V_2 = F_131 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_44 * V_45 ;
if ( ! F_34 ( V_2 ) )
return - V_208 ;
if ( V_135 >= V_33 -> V_46 || V_214 > 7 )
return - V_49 ;
if ( V_144 > V_215 ) {
F_54 ( V_66 ,
L_39 ,
V_215 ) ;
return - V_49 ;
}
V_57 = & V_33 -> V_57 [ V_135 ] ;
V_45 = V_57 -> V_45 ;
if ( F_117 ( V_143 , & V_57 -> V_99 ) ) {
F_54 ( V_66 ,
L_40 ,
V_135 ) ;
return - V_208 ;
}
memset ( V_57 -> V_141 , 0 ,
sizeof( * V_57 -> V_141 ) * V_33 -> V_39 ) ;
switch ( V_144 ) {
case 4095 :
V_45 -> V_129 = V_140 ;
break;
case 0 :
V_45 -> V_129 = V_216 ;
V_45 -> V_214 = 0 ;
break;
default:
V_45 -> V_129 = V_130 ;
F_97 ( V_33 , V_57 , V_144 ) ;
V_45 -> V_214 = V_214 ;
V_45 -> V_131 = V_144 ;
}
F_12 ( V_66 , L_41 ,
V_144 , V_214 , V_135 ) ;
return 0 ;
}
static T_6 F_137 ( struct V_1 * V_2 ,
struct V_44 * V_45 , int V_135 )
{
T_6 V_144 = 0 ;
switch ( V_45 -> V_129 ) {
case V_130 :
V_144 = V_45 -> V_131 ;
break;
case V_140 :
V_144 = V_215 ;
break;
case V_216 :
V_144 = 0 ;
break;
default:
F_12 ( V_2 -> V_66 , L_42 ,
V_45 -> V_129 , V_135 ) ;
}
return V_144 ;
}
int F_138 ( struct V_101 * V_66 ,
int V_135 , struct V_217 * V_218 )
{
struct V_1 * V_2 = F_131 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_44 * V_45 ;
if ( ! F_34 ( V_2 ) )
return - V_208 ;
if ( V_135 >= V_33 -> V_46 )
return - V_49 ;
V_45 = V_33 -> V_57 [ V_135 ] . V_45 ;
memcpy ( & V_218 -> V_125 , V_45 -> V_125 , V_219 ) ;
V_218 -> V_144 = F_137 ( V_2 , V_45 , V_135 ) ;
V_218 -> V_214 = V_45 -> V_214 ;
V_218 -> V_126 = V_45 -> V_126 ;
if ( V_45 -> V_15 == V_53 )
V_218 -> V_211 = 0 ;
else
V_218 -> V_211 = V_45 -> V_15 * 100 ;
V_218 -> V_135 = V_135 ;
return 0 ;
}
int F_139 ( struct V_101 * V_66 , int V_135 , bool V_220 )
{
struct V_1 * V_2 = F_131 ( V_66 ) ;
struct V_32 * V_33 = V_2 -> V_34 -> V_33 ;
struct V_77 * V_57 ;
struct V_44 * V_45 ;
if ( ! F_34 ( V_2 ) )
return - V_208 ;
if ( V_135 >= V_33 -> V_46 )
return - V_49 ;
V_57 = & V_33 -> V_57 [ V_135 ] ;
V_45 = V_57 -> V_45 ;
if ( F_117 ( V_143 , & V_57 -> V_99 ) ) {
F_54 ( V_66 ,
L_43 ,
V_135 ) ;
return - V_208 ;
}
V_45 -> V_126 = V_220 ;
return 0 ;
}
