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
int V_32 ;
V_32 = F_16 ( V_46 -> V_28 , F_17 ( 36 ) ) ;
if ( V_32 )
return V_32 ;
if ( V_48 -> V_49 [ V_11 ] . V_2 ) {
V_32 = F_18 ( V_50 , V_46 -> V_28 ,
V_51 . V_52 ,
& V_48 -> V_49 [ V_11 ] . V_2 -> V_53 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_3 ) ;
return V_32 ;
}
}
if ( V_48 -> V_49 [ V_54 ] . V_2 ) {
V_32 = F_18 ( V_50 , V_46 -> V_28 ,
V_51 . V_52 ,
& V_48 -> V_49 [ V_54 ] . V_2 -> V_53 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_4 ) ;
F_19 ( & V_48 -> V_49 [ V_11 ] . V_2 -> V_53 ) ;
return V_32 ;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_57 * V_58 =
F_21 ( V_25 -> V_29 -> V_59 , struct V_57 , V_60 ) ;
struct V_5 * V_6 ;
struct V_30 T_2 * V_31 ;
T_4 V_61 ;
T_5 V_62 ;
T_3 V_63 ;
unsigned int V_64 ;
int V_32 = 0 ;
unsigned int V_65 ;
V_32 = F_22 ( V_56 ,
V_66 ) ;
if ( V_32 < 0 ) {
F_12 ( V_28 , L_5 ) ;
return V_32 ;
}
V_64 = V_2 -> V_10 == V_11 ? 0 : 1 ;
if ( V_58 -> V_67 ) {
F_12 ( V_28 , L_6 ) ;
return - V_68 ;
}
V_6 = F_23 ( V_28 , sizeof( struct V_5 ) ,
& V_61 , V_69 ) ;
if ( ! V_6 ) {
F_12 ( V_28 , L_7 ) ;
return - V_70 ;
}
if ( V_2 -> V_10 == V_11 )
V_6 -> V_71 = V_58 -> V_72 ;
else
V_6 -> V_71 = V_58 -> V_73 ;
V_6 -> V_74 = V_58 -> V_74 ;
V_6 -> V_31 = V_58 -> V_64 ;
V_6 -> V_22 = V_58 -> V_22 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_61 = V_61 ;
V_6 -> V_20 = V_2 -> V_53 . V_75 ;
V_32 = F_24 ( V_6 -> V_22 , F_10 , 0 , L_8 ,
V_6 ) ;
if ( V_32 ) {
F_12 ( V_28 , L_9 ,
V_6 -> V_22 , V_32 ) ;
F_25 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_61 ) ;
return V_32 ;
}
V_58 -> V_67 = 1 ;
F_26 ( V_2 , & V_2 -> V_53 ) ;
F_27 ( V_2 , & V_51 ) ;
V_56 -> V_26 = V_6 ;
V_31 = V_6 -> V_31 ;
V_62 = V_6 -> V_61 +
sizeof( struct V_7 ) ;
for ( V_65 = 0 ; V_65 < V_21 ; V_65 ++ ) {
V_6 -> V_8 [ V_65 ] . V_76 = F_28 ( V_62 ) ;
V_62 += sizeof( struct V_7 ) ;
}
V_6 -> V_8 [ V_65 - 1 ] . V_76 = F_28 ( V_6 -> V_61 ) ;
F_14 ( & V_31 -> V_77 ,
F_29 ( V_6 -> V_61 ) ) ;
F_14 ( & V_31 -> V_78 ,
F_30 ( V_6 -> V_61 ) ) ;
F_14 ( & V_31 -> V_79 , 0 ) ;
V_63 = F_11 ( & V_31 -> V_63 ) &
~ ( V_80 | V_81 | V_82 ) ;
V_63 |= V_83 | V_84 | V_85 |
V_86 ;
V_63 |= ( V_2 -> V_10 == V_11 ) ?
V_81 : V_82 ;
F_14 ( & V_31 -> V_63 , V_63 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
unsigned int V_89 =
F_32 ( F_33 ( V_88 ) ) ;
unsigned int V_90 = V_89 / 8 ;
T_4 V_71 = V_6 -> V_71 ;
T_6 V_91 = F_34 ( V_88 ) ;
T_6 V_18 = F_35 ( V_88 ) ;
T_4 V_92 = V_2 -> V_53 . V_75 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_3 V_63 ;
unsigned int V_65 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_43 = F_36 ( V_88 ) ;
V_6 -> V_19 = V_6 -> V_20 + V_91 ;
V_6 -> V_13 = V_6 -> V_20 +
( V_21 * V_18 ) ;
if ( V_6 -> V_13 >= V_6 -> V_19 )
V_6 -> V_13 = V_6 -> V_20 ;
V_63 = F_11 ( & V_31 -> V_63 ) & ~ ( V_93 |
V_94 | V_95 ) ;
switch ( V_89 ) {
case 8 :
V_63 |= V_96 | V_97 ;
V_71 += 3 ;
break;
case 16 :
V_63 |= V_98 | V_99 ;
V_71 += 2 ;
break;
case 32 :
V_63 |= V_100 | V_101 ;
break;
default:
F_12 ( V_28 , L_10 , V_89 ) ;
return - V_102 ;
}
V_63 |= F_37 ( ( V_6 -> V_74 - 2 ) * V_90 ) ;
F_14 ( & V_31 -> V_63 , V_63 ) ;
for ( V_65 = 0 ; V_65 < V_21 ; V_65 ++ ) {
struct V_7 * V_8 = & V_6 -> V_8 [ V_65 ] ;
V_8 -> V_103 = F_7 ( V_18 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_8 -> V_12 = F_7 ( V_92 ) ;
V_8 -> V_14 = F_7 ( V_15 |
F_9 ( V_92 ) ) ;
V_8 -> V_16 = F_7 ( V_71 ) ;
V_8 -> V_17 = F_7 ( V_104 |
F_9 ( V_71 ) ) ;
} else {
V_8 -> V_12 = F_7 ( V_71 ) ;
V_8 -> V_14 = F_7 ( V_104 |
F_9 ( V_71 ) ) ;
V_8 -> V_16 = F_7 ( V_92 ) ;
V_8 -> V_17 = F_7 ( V_15 |
F_9 ( V_92 ) ) ;
}
V_92 += V_18 ;
}
return 0 ;
}
static T_7 F_38 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_4 V_105 ;
T_7 V_106 ;
if ( V_2 -> V_10 == V_11 ) {
V_105 = F_11 ( & V_31 -> V_107 ) ;
#ifdef F_8
V_105 |= ( T_5 ) ( F_11 ( & V_31 -> V_108 ) &
V_109 ) << 32 ;
#endif
} else {
V_105 = F_11 ( & V_31 -> V_110 ) ;
#ifdef F_8
V_105 |= ( T_5 ) ( F_11 ( & V_31 -> V_111 ) &
V_109 ) << 32 ;
#endif
}
if ( ! V_105 )
return 0 ;
if ( ( V_105 < V_6 -> V_20 ) ||
( V_105 > V_6 -> V_19 ) ) {
F_12 ( V_28 , L_11 ) ;
return V_112 ;
}
V_106 = F_39 ( V_56 , V_105 - V_6 -> V_20 ) ;
if ( V_106 == V_56 -> V_91 )
V_106 = 0 ;
return V_106 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_26 ;
if ( V_6 ) {
struct V_30 T_2 * V_31 ;
V_31 = V_6 -> V_31 ;
F_14 ( & V_31 -> V_63 , V_80 ) ;
F_14 ( & V_31 -> V_63 , 0 ) ;
F_14 ( & V_31 -> V_34 , - 1 ) ;
F_14 ( & V_31 -> V_77 , 0 ) ;
F_14 ( & V_31 -> V_78 , 0 ) ;
F_14 ( & V_31 -> V_108 , 0 ) ;
F_14 ( & V_31 -> V_107 , 0 ) ;
F_14 ( & V_31 -> V_111 , 0 ) ;
F_14 ( & V_31 -> V_110 , 0 ) ;
F_14 ( & V_31 -> V_79 , 0 ) ;
F_14 ( & V_31 -> V_113 , 0 ) ;
F_14 ( & V_31 -> V_114 , 0 ) ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_57 * V_58 =
F_21 ( V_25 -> V_29 -> V_59 , struct V_57 , V_60 ) ;
if ( V_6 ) {
if ( V_6 -> V_22 )
F_42 ( V_6 -> V_22 , V_6 ) ;
F_25 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_61 ) ;
V_2 -> V_56 -> V_26 = NULL ;
}
V_58 -> V_67 = 0 ;
return 0 ;
}
static void F_43 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < F_44 ( V_48 -> V_49 ) ; V_65 ++ ) {
V_2 = V_48 -> V_49 [ V_65 ] . V_2 ;
if ( V_2 ) {
F_19 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_115 = NULL ;
V_2 -> V_53 . V_75 = 0 ;
}
}
}
static struct V_116 * F_45 ( struct V_116 * V_117 )
{
struct V_116 * V_118 , * V_119 ;
F_46 (ssi_np, NULL, L_12 ) {
V_119 = F_47 ( V_118 , L_13 , 0 ) ;
F_48 ( V_119 ) ;
if ( V_119 == V_117 )
return V_118 ;
V_119 = F_47 ( V_118 , L_14 , 0 ) ;
F_48 ( V_119 ) ;
if ( V_119 == V_117 )
return V_118 ;
}
return NULL ;
}
static int F_49 ( struct V_120 * V_121 )
{
struct V_57 * V_58 ;
struct V_116 * V_119 = V_121 -> V_28 . V_122 ;
struct V_116 * V_118 ;
struct V_123 V_124 ;
const T_8 * V_125 ;
int V_32 ;
V_118 = F_45 ( V_119 ) ;
if ( ! V_118 ) {
F_12 ( & V_121 -> V_28 , L_15 ) ;
return - V_126 ;
}
V_32 = F_50 ( V_118 , 0 , & V_124 ) ;
if ( V_32 ) {
F_12 ( & V_121 -> V_28 , L_16 ,
V_118 -> V_127 ) ;
F_48 ( V_118 ) ;
return V_32 ;
}
V_58 = F_51 ( sizeof( * V_58 ) + strlen ( V_119 -> V_127 ) , V_69 ) ;
if ( ! V_58 ) {
F_12 ( & V_121 -> V_28 , L_17 ) ;
F_48 ( V_118 ) ;
return - V_70 ;
}
strcpy ( V_58 -> V_128 , V_119 -> V_127 ) ;
V_58 -> V_60 . V_129 = & V_130 ;
V_58 -> V_60 . V_131 = F_15 ;
V_58 -> V_60 . V_132 = F_43 ;
V_58 -> V_72 = V_124 . V_133 + V_134 ;
V_58 -> V_73 = V_124 . V_133 + V_135 ;
V_125 = F_52 ( V_118 , L_18 , NULL ) ;
if ( V_125 )
V_58 -> V_74 = F_53 ( V_125 ) ;
else
V_58 -> V_74 = 8 ;
F_48 ( V_118 ) ;
V_32 = F_54 ( & V_121 -> V_28 , & V_58 -> V_60 ) ;
if ( V_32 ) {
F_12 ( & V_121 -> V_28 , L_19 ) ;
F_55 ( V_58 ) ;
return V_32 ;
}
V_58 -> V_64 = F_56 ( V_119 , 0 ) ;
V_58 -> V_22 = F_57 ( V_119 , 0 ) ;
F_58 ( & V_121 -> V_28 , V_58 ) ;
return 0 ;
}
static int F_59 ( struct V_120 * V_121 )
{
struct V_57 * V_58 = F_60 ( & V_121 -> V_28 ) ;
F_61 ( & V_121 -> V_28 ) ;
F_62 ( V_58 -> V_64 ) ;
F_63 ( V_58 -> V_22 ) ;
F_55 ( V_58 ) ;
return 0 ;
}
