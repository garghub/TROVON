static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_9 , V_10 ;
V_9 = ( V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
if ( V_8 -> V_17 == V_18 )
V_9 |= V_19 ;
V_10 = V_20 ;
V_10 |= V_21 ;
V_10 |= V_8 -> V_22 ;
V_4 -> V_23 . V_24 = V_25 ;
V_4 -> V_23 . V_26 = 0 ;
if ( V_6 -> V_27 != V_28 ) {
V_4 -> V_23 . V_29 = V_6 -> V_27 ;
if ( V_6 -> V_30 == V_31 )
V_4 -> V_23 . V_32 = V_33 ;
else
V_4 -> V_23 . V_32 = V_34 ;
} else {
V_4 -> V_23 . V_29 = V_35 ;
V_4 -> V_23 . V_32 = V_36 ;
}
V_4 -> V_23 . V_37 = V_38 ;
F_3 ( V_4 -> V_39 . V_9 ,
V_9 ) ;
F_3 ( V_4 -> V_39 . V_10 ,
V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_10 ;
F_5 ( & V_10 ,
V_4 -> V_39 . V_10 ) ;
while ( F_6 ( V_40 , & V_6 -> V_41 ) )
F_7 ( 1 ) ;
if ( V_4 -> V_23 . V_37 == V_38 ) {
T_2 V_42 , V_43 ;
if ( V_10 & V_44 ) {
if ( V_8 -> V_17 == V_18 ) {
V_8 -> V_22 =
V_10 & V_45 ;
} else {
F_8 ( V_40 , & V_6 -> V_41 ) ;
return - V_46 ;
}
} else if ( V_10 & V_47 ) {
F_8 ( V_40 , & V_6 -> V_41 ) ;
return - V_46 ;
} else {
V_8 -> V_22 =
V_10 & V_45 ;
}
V_10 = V_8 -> V_22 |
V_20 | V_21 ;
V_42 = V_8 -> V_48 & ~ V_49 ;
V_43 = V_8 -> V_50 & ~ V_51 ;
if ( V_8 -> V_22 & V_52 )
V_42 |= V_53 ;
if ( V_8 -> V_22 & V_54 )
V_42 |= V_55 ;
if ( V_8 -> V_22 & V_56 )
V_42 |= V_57 ;
if ( V_8 -> V_22 & V_58 )
V_42 |= V_59 ;
if ( V_8 -> V_22 & V_44 )
V_43 |= V_60 ;
if ( V_42 != V_8 -> V_48 ||
V_43 != V_8 -> V_50 ) {
V_8 -> V_48 = V_42 ;
V_8 -> V_50 = V_43 ;
V_8 -> V_61 = true ;
}
} else {
F_8 ( V_40 , & V_6 -> V_41 ) ;
return - V_46 ;
}
if ( F_9 ( V_6 -> V_2 ) ) {
F_10 ( V_6 ) ;
F_11 ( V_6 ) ;
} else
F_12 ( & V_6 -> V_8 ) ;
F_8 ( V_40 , & V_6 -> V_41 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
return 1 ;
#else
return 0 ;
#endif
}
static int F_15 ( struct V_1 * V_2 )
{
return V_62 * sizeof( T_1 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_63 * V_64 , void * V_65 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_66 = V_65 ;
T_2 V_67 ;
memset ( V_65 , 0 , V_62 * sizeof( T_1 ) ) ;
V_64 -> V_68 = ( 1 << 24 ) | ( V_8 -> V_69 << 16 ) | V_8 -> V_70 ;
V_66 [ 0 ] = F_17 ( V_8 , V_71 ) ;
V_66 [ 1 ] = F_17 ( V_8 , V_72 ) ;
V_66 [ 2 ] = F_17 ( V_8 , V_73 ) ;
V_66 [ 3 ] = F_17 ( V_8 , V_74 ) ;
V_66 [ 4 ] = F_17 ( V_8 , V_75 ) ;
V_66 [ 5 ] = F_17 ( V_8 , V_76 ) ;
V_66 [ 6 ] = F_17 ( V_8 , V_77 ) ;
V_66 [ 7 ] = F_17 ( V_8 , V_78 ) ;
V_66 [ 8 ] = F_17 ( V_8 , V_79 ) ;
V_66 [ 9 ] = F_17 ( V_8 , V_80 ) ;
V_66 [ 10 ] = F_17 ( V_8 , V_81 ) ;
V_66 [ 11 ] = F_17 ( V_8 , V_82 ) ;
V_66 [ 12 ] = F_17 ( V_8 , V_83 ) ;
V_66 [ 13 ] = F_17 ( V_8 , V_84 ) ;
V_66 [ 14 ] = F_17 ( V_8 , V_85 ) ;
V_66 [ 15 ] = F_17 ( V_8 , V_86 ) ;
V_66 [ 16 ] = F_17 ( V_8 , V_86 + 4 ) ;
V_66 [ 17 ] = F_17 ( V_8 , V_87 ) ;
V_66 [ 18 ] = F_17 ( V_8 , V_87 + 4 ) ;
V_66 [ 19 ] = F_17 ( V_8 , V_88 ) ;
V_66 [ 20 ] = F_17 ( V_8 , V_89 ) ;
V_66 [ 21 ] = F_17 ( V_8 , V_90 ) ;
V_66 [ 22 ] = F_17 ( V_8 , V_91 ) ;
V_66 [ 23 ] = F_17 ( V_8 , V_92 ) ;
V_66 [ 24 ] = F_17 ( V_8 , V_93 ) ;
V_66 [ 25 ] = F_17 ( V_8 , V_94 ) ;
V_66 [ 26 ] = F_17 ( V_8 , V_95 ) ;
V_66 [ 27 ] = F_17 ( V_8 , V_96 ) ;
V_66 [ 28 ] = F_17 ( V_8 , V_97 ) ;
V_66 [ 29 ] = F_17 ( V_8 , V_98 ) ;
F_18 ( V_8 , V_99 , & V_67 ) ;
V_66 [ 73 ] = ( T_1 ) V_67 ;
F_18 ( V_8 , V_100 , & V_67 ) ;
V_66 [ 74 ] = ( T_1 ) V_67 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_20 ( & V_6 -> V_8 ) )
return V_101 ;
else
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_102 * V_103 , T_3 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_105 ;
int V_106 , V_107 ;
int V_108 = 0 ;
int V_109 ;
if ( V_103 -> V_110 == 0 )
return - V_46 ;
if ( F_20 ( V_8 ) )
return - V_46 ;
V_103 -> V_111 = V_8 -> V_112 | ( V_8 -> V_70 << 16 ) ;
V_106 = V_103 -> V_113 >> 2 ;
V_107 = ( V_103 -> V_113 + V_103 -> V_110 - 1 ) >> 2 ;
V_105 = F_22 ( sizeof( T_1 ) *
( V_107 - V_106 + 1 ) , V_114 ) ;
if ( V_105 == NULL )
return - V_115 ;
for ( V_109 = V_106 ; V_109 < V_107 ; V_109 ++ ) {
if ( ! F_23 ( V_8 , V_109 * 4 , & ( V_105 [ V_109 - V_106 ] ) ) ) {
F_24 ( V_105 ) ;
return - V_116 ;
}
}
memcpy ( V_104 , ( T_3 * ) V_105 + ( V_103 -> V_113 & 3 ) ,
V_103 -> V_110 ) ;
F_24 ( V_105 ) ;
return V_108 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_102 * V_103 , T_3 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_105 ;
T_1 * V_117 ;
int V_106 , V_107 ;
int V_108 = 0 ;
int V_109 ;
if ( V_103 -> V_110 == 0 )
return - V_118 ;
if ( V_103 -> V_111 != ( V_8 -> V_112 | ( V_8 -> V_70 << 16 ) ) )
return - V_46 ;
V_106 = V_103 -> V_113 >> 2 ;
V_107 = ( V_103 -> V_113 + V_103 -> V_110 - 1 ) >> 2 ;
V_105 = F_22 ( V_101 , V_114 ) ;
if ( V_105 == NULL )
return - V_115 ;
V_117 = V_105 ;
if ( V_103 -> V_113 & 3 ) {
if ( ! F_23 ( V_8 , V_106 * 4 , & ( V_105 [ 0 ] ) ) ) {
V_108 = - V_116 ;
goto V_119;
}
V_117 ++ ;
}
if ( ( ( V_103 -> V_113 + V_103 -> V_110 ) & 3 ) ) {
if ( ! F_23 ( V_8 , V_107 * 4 ,
& ( V_105 [ V_107 - V_106 ] ) ) ) {
V_108 = - V_116 ;
goto V_119;
}
}
memcpy ( V_117 , V_104 , V_103 -> V_110 ) ;
for ( V_109 = 0 ; V_109 < V_107 - V_106 + 1 ; V_109 ++ ) {
if ( ! F_26 ( V_8 , ( ( V_106 + V_109 ) * 4 ) ,
V_105 [ V_109 ] ) ) {
V_108 = - V_116 ;
goto V_119;
}
}
V_119:
F_24 ( V_105 ) ;
return V_108 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_28 ( V_121 -> V_122 , V_123 , sizeof( V_121 -> V_122 ) ) ;
F_28 ( V_121 -> V_68 , V_124 ,
sizeof( V_121 -> V_68 ) ) ;
F_28 ( V_121 -> V_125 , L_1 , sizeof( V_121 -> V_125 ) ) ;
F_28 ( V_121 -> V_126 , F_29 ( V_6 -> V_127 ) ,
sizeof( V_121 -> V_126 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_129 -> V_9 = V_130 | V_131 ;
V_129 -> V_132 = 0 ;
if ( V_6 -> V_129 & V_133 )
V_129 -> V_132 |= V_134 ;
if ( V_6 -> V_129 & V_135 )
V_129 -> V_132 |= V_136 ;
if ( V_6 -> V_129 & V_137 )
V_129 -> V_132 |= V_138 ;
if ( V_6 -> V_129 & V_139 )
V_129 -> V_132 |= V_130 ;
if ( V_6 -> V_129 & V_140 )
V_129 -> V_132 |= V_131 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_129 -> V_132 & ( V_141 | V_142 |
V_134 | V_136 | V_138 ) )
return - V_118 ;
V_6 -> V_129 = 0 ;
if ( V_129 -> V_132 & V_130 )
V_6 -> V_129 |= V_139 ;
if ( V_129 -> V_132 & V_131 )
V_6 -> V_129 |= V_140 ;
F_32 ( & V_6 -> V_127 -> V_143 , V_6 -> V_129 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_9 ( V_2 ) )
F_34 ( V_6 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_144 = & V_145 ;
}
