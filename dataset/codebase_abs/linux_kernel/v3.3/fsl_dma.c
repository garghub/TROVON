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
struct V_47 * V_48 = V_25 -> V_48 ;
static T_4 V_49 = F_16 ( 36 ) ;
int V_32 ;
if ( ! V_46 -> V_28 -> V_50 )
V_46 -> V_28 -> V_50 = & V_49 ;
if ( ! V_46 -> V_28 -> V_51 )
V_46 -> V_28 -> V_51 = V_49 ;
if ( V_48 -> V_52 [ 0 ] . V_2 ) {
V_32 = F_17 ( V_53 , V_46 -> V_28 ,
V_54 . V_55 ,
& V_48 -> V_52 [ 0 ] . V_2 -> V_56 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_3 ) ;
return V_32 ;
}
}
if ( V_48 -> V_52 [ 1 ] . V_2 ) {
V_32 = F_17 ( V_53 , V_46 -> V_28 ,
V_54 . V_55 ,
& V_48 -> V_52 [ 1 ] . V_2 -> V_56 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_4 ) ;
F_18 ( & V_48 -> V_52 [ 0 ] . V_2 -> V_56 ) ;
return V_32 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_59 * V_60 =
F_20 ( V_25 -> V_29 -> V_61 , struct V_59 , V_62 ) ;
struct V_5 * V_6 ;
struct V_30 T_2 * V_31 ;
T_5 V_63 ;
T_4 V_64 ;
T_3 V_65 ;
unsigned int V_66 ;
int V_32 = 0 ;
unsigned int V_67 ;
V_32 = F_21 ( V_58 ,
V_68 ) ;
if ( V_32 < 0 ) {
F_12 ( V_28 , L_5 ) ;
return V_32 ;
}
V_66 = V_2 -> V_10 == V_11 ? 0 : 1 ;
if ( V_60 -> V_69 ) {
F_12 ( V_28 , L_6 ) ;
return - V_70 ;
}
V_6 = F_22 ( V_28 , sizeof( struct V_5 ) ,
& V_63 , V_71 ) ;
if ( ! V_6 ) {
F_12 ( V_28 , L_7 ) ;
return - V_72 ;
}
if ( V_2 -> V_10 == V_11 )
V_6 -> V_73 = V_60 -> V_74 ;
else
V_6 -> V_73 = V_60 -> V_75 ;
V_6 -> V_76 = V_60 -> V_76 ;
V_6 -> V_31 = V_60 -> V_66 ;
V_6 -> V_22 = V_60 -> V_22 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_63 = V_63 ;
V_6 -> V_20 = V_2 -> V_56 . V_77 ;
V_32 = F_23 ( V_6 -> V_22 , F_10 , 0 , L_8 ,
V_6 ) ;
if ( V_32 ) {
F_12 ( V_28 , L_9 ,
V_6 -> V_22 , V_32 ) ;
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_63 ) ;
return V_32 ;
}
V_60 -> V_69 = 1 ;
F_25 ( V_2 , & V_2 -> V_56 ) ;
F_26 ( V_2 , & V_54 ) ;
V_58 -> V_26 = V_6 ;
V_31 = V_6 -> V_31 ;
V_64 = V_6 -> V_63 +
sizeof( struct V_7 ) ;
for ( V_67 = 0 ; V_67 < V_21 ; V_67 ++ ) {
V_6 -> V_8 [ V_67 ] . V_78 = F_27 ( V_64 ) ;
V_64 += sizeof( struct V_7 ) ;
}
V_6 -> V_8 [ V_67 - 1 ] . V_78 = F_27 ( V_6 -> V_63 ) ;
F_14 ( & V_31 -> V_79 ,
F_28 ( V_6 -> V_63 ) ) ;
F_14 ( & V_31 -> V_80 ,
F_29 ( V_6 -> V_63 ) ) ;
F_14 ( & V_31 -> V_81 , 0 ) ;
V_65 = F_11 ( & V_31 -> V_65 ) &
~ ( V_82 | V_83 | V_84 ) ;
V_65 |= V_85 | V_86 | V_87 |
V_88 ;
V_65 |= ( V_2 -> V_10 == V_11 ) ?
V_83 : V_84 ;
F_14 ( & V_31 -> V_65 , V_65 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_5 * V_6 = V_58 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
unsigned int V_91 =
F_31 ( F_32 ( V_90 ) ) ;
unsigned int V_92 = V_91 / 8 ;
T_5 V_73 = V_6 -> V_73 ;
T_6 V_93 = F_33 ( V_90 ) ;
T_6 V_18 = F_34 ( V_90 ) ;
T_5 V_94 = V_2 -> V_56 . V_77 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_3 V_65 ;
unsigned int V_67 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_43 = F_35 ( V_90 ) ;
V_6 -> V_19 = V_6 -> V_20 + V_93 ;
V_6 -> V_13 = V_6 -> V_20 +
( V_21 * V_18 ) ;
if ( V_6 -> V_13 >= V_6 -> V_19 )
V_6 -> V_13 = V_6 -> V_20 ;
V_65 = F_11 ( & V_31 -> V_65 ) & ~ ( V_95 |
V_96 | V_97 ) ;
switch ( V_91 ) {
case 8 :
V_65 |= V_98 | V_99 ;
V_73 += 3 ;
break;
case 16 :
V_65 |= V_100 | V_101 ;
V_73 += 2 ;
break;
case 32 :
V_65 |= V_102 | V_103 ;
break;
default:
F_12 ( V_28 , L_10 , V_91 ) ;
return - V_104 ;
}
V_65 |= F_36 ( ( V_6 -> V_76 - 2 ) * V_92 ) ;
F_14 ( & V_31 -> V_65 , V_65 ) ;
for ( V_67 = 0 ; V_67 < V_21 ; V_67 ++ ) {
struct V_7 * V_8 = & V_6 -> V_8 [ V_67 ] ;
V_8 -> V_105 = F_7 ( V_18 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_8 -> V_12 = F_7 ( V_94 ) ;
V_8 -> V_14 = F_7 ( V_15 |
F_9 ( V_94 ) ) ;
V_8 -> V_16 = F_7 ( V_73 ) ;
V_8 -> V_17 = F_7 ( V_106 |
F_9 ( V_73 ) ) ;
} else {
V_8 -> V_12 = F_7 ( V_73 ) ;
V_8 -> V_14 = F_7 ( V_106 |
F_9 ( V_73 ) ) ;
V_8 -> V_16 = F_7 ( V_94 ) ;
V_8 -> V_17 = F_7 ( V_15 |
F_9 ( V_94 ) ) ;
}
V_94 += V_18 ;
}
return 0 ;
}
static T_7 F_37 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_5 * V_6 = V_58 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_5 V_107 ;
T_7 V_108 ;
if ( V_2 -> V_10 == V_11 ) {
V_107 = F_11 ( & V_31 -> V_109 ) ;
#ifdef F_8
V_107 |= ( T_4 ) ( F_11 ( & V_31 -> V_110 ) &
V_111 ) << 32 ;
#endif
} else {
V_107 = F_11 ( & V_31 -> V_112 ) ;
#ifdef F_8
V_107 |= ( T_4 ) ( F_11 ( & V_31 -> V_113 ) &
V_111 ) << 32 ;
#endif
}
if ( ! V_107 )
return 0 ;
if ( ( V_107 < V_6 -> V_20 ) ||
( V_107 > V_6 -> V_19 ) ) {
F_12 ( V_28 , L_11 ) ;
return V_114 ;
}
V_108 = F_38 ( V_58 , V_107 - V_6 -> V_20 ) ;
if ( V_108 == V_58 -> V_93 )
V_108 = 0 ;
return V_108 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_5 * V_6 = V_58 -> V_26 ;
if ( V_6 ) {
struct V_30 T_2 * V_31 ;
V_31 = V_6 -> V_31 ;
F_14 ( & V_31 -> V_65 , V_82 ) ;
F_14 ( & V_31 -> V_65 , 0 ) ;
F_14 ( & V_31 -> V_34 , - 1 ) ;
F_14 ( & V_31 -> V_79 , 0 ) ;
F_14 ( & V_31 -> V_80 , 0 ) ;
F_14 ( & V_31 -> V_110 , 0 ) ;
F_14 ( & V_31 -> V_109 , 0 ) ;
F_14 ( & V_31 -> V_113 , 0 ) ;
F_14 ( & V_31 -> V_112 , 0 ) ;
F_14 ( & V_31 -> V_81 , 0 ) ;
F_14 ( & V_31 -> V_115 , 0 ) ;
F_14 ( & V_31 -> V_116 , 0 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_5 * V_6 = V_58 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_59 * V_60 =
F_20 ( V_25 -> V_29 -> V_61 , struct V_59 , V_62 ) ;
if ( V_6 ) {
if ( V_6 -> V_22 )
F_41 ( V_6 -> V_22 , V_6 ) ;
if ( V_6 -> V_63 ) {
F_42 ( V_28 , V_6 -> V_63 ,
sizeof( V_6 -> V_8 ) ,
V_117 ) ;
}
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_63 ) ;
V_2 -> V_58 -> V_26 = NULL ;
}
V_60 -> V_69 = 0 ;
return 0 ;
}
static void F_43 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < F_44 ( V_48 -> V_52 ) ; V_67 ++ ) {
V_2 = V_48 -> V_52 [ V_67 ] . V_2 ;
if ( V_2 ) {
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_56 . V_118 = NULL ;
V_2 -> V_56 . V_77 = 0 ;
}
}
}
static struct V_119 * F_45 ( struct V_119 * V_120 )
{
struct V_119 * V_121 , * V_122 ;
F_46 (ssi_np, NULL, L_12 ) {
V_122 = F_47 ( V_121 , L_13 , 0 ) ;
F_48 ( V_122 ) ;
if ( V_122 == V_120 )
return V_121 ;
V_122 = F_47 ( V_121 , L_14 , 0 ) ;
F_48 ( V_122 ) ;
if ( V_122 == V_120 )
return V_121 ;
}
return NULL ;
}
static int T_8 F_49 ( struct V_123 * V_124 )
{
struct V_59 * V_60 ;
struct V_119 * V_122 = V_124 -> V_28 . V_125 ;
struct V_119 * V_121 ;
struct V_126 V_127 ;
const T_9 * V_128 ;
int V_32 ;
V_121 = F_45 ( V_122 ) ;
if ( ! V_121 ) {
F_12 ( & V_124 -> V_28 , L_15 ) ;
return - V_129 ;
}
V_32 = F_50 ( V_121 , 0 , & V_127 ) ;
if ( V_32 ) {
F_12 ( & V_124 -> V_28 , L_16 ,
V_121 -> V_130 ) ;
F_48 ( V_121 ) ;
return V_32 ;
}
V_60 = F_51 ( sizeof( * V_60 ) + strlen ( V_122 -> V_130 ) , V_71 ) ;
if ( ! V_60 ) {
F_12 ( & V_124 -> V_28 , L_17 ) ;
F_48 ( V_121 ) ;
return - V_72 ;
}
strcpy ( V_60 -> V_131 , V_122 -> V_130 ) ;
V_60 -> V_62 . V_132 = & V_133 ;
V_60 -> V_62 . V_134 = F_15 ;
V_60 -> V_62 . V_135 = F_43 ;
V_60 -> V_74 = V_127 . V_136 + F_52 ( struct V_137 , V_138 ) ;
V_60 -> V_75 = V_127 . V_136 + F_52 ( struct V_137 , V_139 ) ;
V_128 = F_53 ( V_121 , L_18 , NULL ) ;
if ( V_128 )
V_60 -> V_76 = F_54 ( V_128 ) ;
else
V_60 -> V_76 = 8 ;
F_48 ( V_121 ) ;
V_32 = F_55 ( & V_124 -> V_28 , & V_60 -> V_62 ) ;
if ( V_32 ) {
F_12 ( & V_124 -> V_28 , L_19 ) ;
F_56 ( V_60 ) ;
return V_32 ;
}
V_60 -> V_66 = F_57 ( V_122 , 0 ) ;
V_60 -> V_22 = F_58 ( V_122 , 0 ) ;
F_59 ( & V_124 -> V_28 , V_60 ) ;
return 0 ;
}
static int T_10 F_60 ( struct V_123 * V_124 )
{
struct V_59 * V_60 = F_61 ( & V_124 -> V_28 ) ;
F_62 ( & V_124 -> V_28 ) ;
F_63 ( V_60 -> V_66 ) ;
F_64 ( V_60 -> V_22 ) ;
F_56 ( V_60 ) ;
return 0 ;
}
