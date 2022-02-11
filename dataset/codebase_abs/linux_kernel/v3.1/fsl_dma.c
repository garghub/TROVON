static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_2 ) )
F_4 ( V_2 , V_4 ) ;
F_5 ( V_2 , V_3 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
& V_6 -> V_8 [ V_6 -> V_9 ] ;
if ( V_6 -> V_2 -> V_10 == V_11 ) {
V_8 -> V_12 = F_7 ( V_6 -> V_13 ) ;
#ifdef F_8
V_8 -> V_14 = F_7 ( V_15 |
F_9 ( V_6 -> V_13 ) ) ;
#endif
} else {
V_8 -> V_16 = F_7 ( V_6 -> V_13 ) ;
#ifdef F_8
V_8 -> V_17 = F_7 ( V_15 |
F_9 ( V_6 -> V_13 ) ) ;
#endif
}
V_6 -> V_13 += V_6 -> V_18 ;
if ( V_6 -> V_13 >= V_6 -> V_19 )
V_6 -> V_13 = V_6 -> V_20 ;
if ( ++ V_6 -> V_9 >= V_21 )
V_6 -> V_9 = 0 ;
}
static T_1 F_10 ( int V_22 , void * V_23 )
{
struct V_5 * V_6 = V_23 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_1 V_32 = V_33 ;
T_3 V_34 , V_35 = 0 ;
V_34 = F_11 ( & V_31 -> V_34 ) ;
if ( V_34 & V_36 ) {
F_12 ( V_28 , L_1 ) ;
F_1 ( V_2 ) ;
V_35 |= V_36 ;
V_32 = V_37 ;
}
if ( V_34 & V_38 )
V_32 = V_37 ;
if ( V_34 & V_39 ) {
F_12 ( V_28 , L_2 ) ;
F_1 ( V_2 ) ;
V_35 |= V_39 ;
V_32 = V_37 ;
}
if ( V_34 & V_40 ) {
V_35 |= V_40 ;
V_32 = V_37 ;
}
if ( V_34 & V_41 )
V_32 = V_37 ;
if ( V_34 & V_42 ) {
F_13 ( V_2 ) ;
if ( V_6 -> V_43 != V_21 )
F_6 ( V_6 ) ;
V_35 |= V_42 ;
V_32 = V_37 ;
}
if ( V_34 & V_44 ) {
V_35 |= V_44 ;
V_32 = V_37 ;
}
if ( V_35 )
F_14 ( & V_31 -> V_34 , V_35 ) ;
return V_32 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_45 * V_46 = V_25 -> V_46 -> V_45 ;
struct V_47 * V_48 = V_25 -> V_49 ;
struct V_50 * V_51 = V_25 -> V_51 ;
static T_4 V_52 = F_16 ( 36 ) ;
int V_32 ;
if ( ! V_46 -> V_28 -> V_53 )
V_46 -> V_28 -> V_53 = & V_52 ;
if ( ! V_46 -> V_28 -> V_54 )
V_46 -> V_28 -> V_54 = V_52 ;
if ( V_51 -> V_55 [ 0 ] . V_2 ) {
V_32 = F_17 ( V_56 , V_46 -> V_28 ,
V_57 . V_58 ,
& V_51 -> V_55 [ 0 ] . V_2 -> V_59 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_3 ) ;
return V_32 ;
}
}
if ( V_51 -> V_55 [ 1 ] . V_2 ) {
V_32 = F_17 ( V_56 , V_46 -> V_28 ,
V_57 . V_58 ,
& V_51 -> V_55 [ 1 ] . V_2 -> V_59 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_4 ) ;
F_18 ( & V_51 -> V_55 [ 0 ] . V_2 -> V_59 ) ;
return V_32 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_62 * V_63 =
F_20 ( V_25 -> V_29 -> V_64 , struct V_62 , V_48 ) ;
struct V_5 * V_6 ;
struct V_30 T_2 * V_31 ;
T_5 V_65 ;
T_4 V_66 ;
T_3 V_67 ;
unsigned int V_68 ;
int V_32 = 0 ;
unsigned int V_69 ;
V_32 = F_21 ( V_61 ,
V_70 ) ;
if ( V_32 < 0 ) {
F_12 ( V_28 , L_5 ) ;
return V_32 ;
}
V_68 = V_2 -> V_10 == V_11 ? 0 : 1 ;
if ( V_63 -> V_71 ) {
F_12 ( V_28 , L_6 ) ;
return - V_72 ;
}
V_6 = F_22 ( V_28 , sizeof( struct V_5 ) ,
& V_65 , V_73 ) ;
if ( ! V_6 ) {
F_12 ( V_28 , L_7 ) ;
return - V_74 ;
}
if ( V_2 -> V_10 == V_11 )
V_6 -> V_75 = V_63 -> V_76 ;
else
V_6 -> V_75 = V_63 -> V_77 ;
V_6 -> V_78 = V_63 -> V_78 ;
V_6 -> V_31 = V_63 -> V_68 ;
V_6 -> V_22 = V_63 -> V_22 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_65 = V_65 ;
V_6 -> V_20 = V_2 -> V_59 . V_79 ;
V_32 = F_23 ( V_6 -> V_22 , F_10 , 0 , L_8 ,
V_6 ) ;
if ( V_32 ) {
F_12 ( V_28 , L_9 ,
V_6 -> V_22 , V_32 ) ;
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_65 ) ;
return V_32 ;
}
V_63 -> V_71 = 1 ;
F_25 ( V_2 , & V_2 -> V_59 ) ;
F_26 ( V_2 , & V_57 ) ;
V_61 -> V_26 = V_6 ;
V_31 = V_6 -> V_31 ;
V_66 = V_6 -> V_65 +
sizeof( struct V_7 ) ;
for ( V_69 = 0 ; V_69 < V_21 ; V_69 ++ ) {
V_6 -> V_8 [ V_69 ] . V_80 = F_27 ( V_66 ) ;
V_66 += sizeof( struct V_7 ) ;
}
V_6 -> V_8 [ V_69 - 1 ] . V_80 = F_27 ( V_6 -> V_65 ) ;
F_14 ( & V_31 -> V_81 ,
F_28 ( V_6 -> V_65 ) ) ;
F_14 ( & V_31 -> V_82 ,
F_29 ( V_6 -> V_65 ) ) ;
F_14 ( & V_31 -> V_83 , 0 ) ;
V_67 = F_11 ( & V_31 -> V_67 ) &
~ ( V_84 | V_85 | V_86 ) ;
V_67 |= V_87 | V_88 | V_89 |
V_90 ;
V_67 |= ( V_2 -> V_10 == V_11 ) ?
V_85 : V_86 ;
F_14 ( & V_31 -> V_67 , V_67 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_5 * V_6 = V_61 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
unsigned int V_93 =
F_31 ( F_32 ( V_92 ) ) ;
unsigned int V_94 = V_93 / 8 ;
T_5 V_75 = V_6 -> V_75 ;
T_6 V_95 = F_33 ( V_92 ) ;
T_6 V_18 = F_34 ( V_92 ) ;
T_5 V_96 = V_2 -> V_59 . V_79 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_3 V_67 ;
unsigned int V_69 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_43 = F_35 ( V_92 ) ;
V_6 -> V_19 = V_6 -> V_20 + V_95 ;
V_6 -> V_13 = V_6 -> V_20 +
( V_21 * V_18 ) ;
if ( V_6 -> V_13 >= V_6 -> V_19 )
V_6 -> V_13 = V_6 -> V_20 ;
V_67 = F_11 ( & V_31 -> V_67 ) & ~ ( V_97 |
V_98 | V_99 ) ;
switch ( V_93 ) {
case 8 :
V_67 |= V_100 | V_101 ;
V_75 += 3 ;
break;
case 16 :
V_67 |= V_102 | V_103 ;
V_75 += 2 ;
break;
case 32 :
V_67 |= V_104 | V_105 ;
break;
default:
F_12 ( V_28 , L_10 , V_93 ) ;
return - V_106 ;
}
V_67 |= F_36 ( ( V_6 -> V_78 - 2 ) * V_94 ) ;
F_14 ( & V_31 -> V_67 , V_67 ) ;
for ( V_69 = 0 ; V_69 < V_21 ; V_69 ++ ) {
struct V_7 * V_8 = & V_6 -> V_8 [ V_69 ] ;
V_8 -> V_107 = F_7 ( V_18 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_8 -> V_12 = F_7 ( V_96 ) ;
V_8 -> V_14 = F_7 ( V_15 |
F_9 ( V_96 ) ) ;
V_8 -> V_16 = F_7 ( V_75 ) ;
V_8 -> V_17 = F_7 ( V_108 |
F_9 ( V_75 ) ) ;
} else {
V_8 -> V_12 = F_7 ( V_75 ) ;
V_8 -> V_14 = F_7 ( V_108 |
F_9 ( V_75 ) ) ;
V_8 -> V_16 = F_7 ( V_96 ) ;
V_8 -> V_17 = F_7 ( V_15 |
F_9 ( V_96 ) ) ;
}
V_96 += V_18 ;
}
return 0 ;
}
static T_7 F_37 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_5 * V_6 = V_61 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_5 V_109 ;
T_7 V_110 ;
if ( V_2 -> V_10 == V_11 ) {
V_109 = F_11 ( & V_31 -> V_111 ) ;
#ifdef F_8
V_109 |= ( T_4 ) ( F_11 ( & V_31 -> V_112 ) &
V_113 ) << 32 ;
#endif
} else {
V_109 = F_11 ( & V_31 -> V_114 ) ;
#ifdef F_8
V_109 |= ( T_4 ) ( F_11 ( & V_31 -> V_115 ) &
V_113 ) << 32 ;
#endif
}
if ( ! V_109 )
return 0 ;
if ( ( V_109 < V_6 -> V_20 ) ||
( V_109 > V_6 -> V_19 ) ) {
F_12 ( V_28 , L_11 ) ;
return V_116 ;
}
V_110 = F_38 ( V_61 , V_109 - V_6 -> V_20 ) ;
if ( V_110 == V_61 -> V_95 )
V_110 = 0 ;
return V_110 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_5 * V_6 = V_61 -> V_26 ;
if ( V_6 ) {
struct V_30 T_2 * V_31 ;
V_31 = V_6 -> V_31 ;
F_14 ( & V_31 -> V_67 , V_84 ) ;
F_14 ( & V_31 -> V_67 , 0 ) ;
F_14 ( & V_31 -> V_34 , - 1 ) ;
F_14 ( & V_31 -> V_81 , 0 ) ;
F_14 ( & V_31 -> V_82 , 0 ) ;
F_14 ( & V_31 -> V_112 , 0 ) ;
F_14 ( & V_31 -> V_111 , 0 ) ;
F_14 ( & V_31 -> V_115 , 0 ) ;
F_14 ( & V_31 -> V_114 , 0 ) ;
F_14 ( & V_31 -> V_83 , 0 ) ;
F_14 ( & V_31 -> V_117 , 0 ) ;
F_14 ( & V_31 -> V_118 , 0 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_5 * V_6 = V_61 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_62 * V_63 =
F_20 ( V_25 -> V_29 -> V_64 , struct V_62 , V_48 ) ;
if ( V_6 ) {
if ( V_6 -> V_22 )
F_41 ( V_6 -> V_22 , V_6 ) ;
if ( V_6 -> V_65 ) {
F_42 ( V_28 , V_6 -> V_65 ,
sizeof( V_6 -> V_8 ) ,
V_119 ) ;
}
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_65 ) ;
V_2 -> V_61 -> V_26 = NULL ;
}
V_63 -> V_71 = 0 ;
return 0 ;
}
static void F_43 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < F_44 ( V_51 -> V_55 ) ; V_69 ++ ) {
V_2 = V_51 -> V_55 [ V_69 ] . V_2 ;
if ( V_2 ) {
F_18 ( & V_2 -> V_59 ) ;
V_2 -> V_59 . V_120 = NULL ;
V_2 -> V_59 . V_79 = 0 ;
}
}
}
static struct V_121 * F_45 ( struct V_121 * V_122 )
{
struct V_121 * V_123 , * V_124 ;
F_46 (ssi_np, NULL, L_12 ) {
V_124 = F_47 ( V_123 , L_13 , 0 ) ;
F_48 ( V_124 ) ;
if ( V_124 == V_122 )
return V_123 ;
V_124 = F_47 ( V_123 , L_14 , 0 ) ;
F_48 ( V_124 ) ;
if ( V_124 == V_122 )
return V_123 ;
}
return NULL ;
}
static int T_8 F_49 ( struct V_125 * V_126 )
{
struct V_62 * V_63 ;
struct V_121 * V_124 = V_126 -> V_28 . V_127 ;
struct V_121 * V_123 ;
struct V_128 V_129 ;
const T_9 * V_130 ;
int V_32 ;
V_123 = F_45 ( V_124 ) ;
if ( ! V_123 ) {
F_12 ( & V_126 -> V_28 , L_15 ) ;
return - V_131 ;
}
V_32 = F_50 ( V_123 , 0 , & V_129 ) ;
if ( V_32 ) {
F_12 ( & V_126 -> V_28 , L_16 ,
V_123 -> V_132 ) ;
F_48 ( V_123 ) ;
return V_32 ;
}
V_63 = F_51 ( sizeof( * V_63 ) + strlen ( V_124 -> V_132 ) , V_73 ) ;
if ( ! V_63 ) {
F_12 ( & V_126 -> V_28 , L_17 ) ;
F_48 ( V_123 ) ;
return - V_74 ;
}
strcpy ( V_63 -> V_133 , V_124 -> V_132 ) ;
V_63 -> V_48 . V_134 = & V_135 ;
V_63 -> V_48 . V_136 = F_15 ;
V_63 -> V_48 . V_137 = F_43 ;
V_63 -> V_76 = V_129 . V_138 + F_52 ( struct V_139 , V_140 ) ;
V_63 -> V_77 = V_129 . V_138 + F_52 ( struct V_139 , V_141 ) ;
V_130 = F_53 ( V_123 , L_18 , NULL ) ;
if ( V_130 )
V_63 -> V_78 = F_54 ( V_130 ) ;
else
V_63 -> V_78 = 8 ;
F_48 ( V_123 ) ;
V_32 = F_55 ( & V_126 -> V_28 , & V_63 -> V_48 ) ;
if ( V_32 ) {
F_12 ( & V_126 -> V_28 , L_19 ) ;
F_56 ( V_63 ) ;
return V_32 ;
}
V_63 -> V_68 = F_57 ( V_124 , 0 ) ;
V_63 -> V_22 = F_58 ( V_124 , 0 ) ;
F_59 ( & V_126 -> V_28 , V_63 ) ;
return 0 ;
}
static int T_10 F_60 ( struct V_125 * V_126 )
{
struct V_62 * V_63 = F_61 ( & V_126 -> V_28 ) ;
F_62 ( & V_126 -> V_28 ) ;
F_63 ( V_63 -> V_68 ) ;
F_64 ( V_63 -> V_22 ) ;
F_56 ( V_63 ) ;
return 0 ;
}
static int T_11 F_65 ( void )
{
F_66 ( L_20 ) ;
return F_67 ( & V_142 ) ;
}
static void T_12 F_68 ( void )
{
F_69 ( & V_142 ) ;
}
