static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
& V_4 -> V_6 [ V_4 -> V_7 ] ;
if ( V_4 -> V_2 -> V_8 == V_9 ) {
V_6 -> V_10 = F_4 ( V_4 -> V_11 ) ;
#ifdef F_5
V_6 -> V_12 = F_4 ( V_13 |
F_6 ( V_4 -> V_11 ) ) ;
#endif
} else {
V_6 -> V_14 = F_4 ( V_4 -> V_11 ) ;
#ifdef F_5
V_6 -> V_15 = F_4 ( V_13 |
F_6 ( V_4 -> V_11 ) ) ;
#endif
}
V_4 -> V_11 += V_4 -> V_16 ;
if ( V_4 -> V_11 >= V_4 -> V_17 )
V_4 -> V_11 = V_4 -> V_18 ;
if ( ++ V_4 -> V_7 >= V_19 )
V_4 -> V_7 = 0 ;
}
static T_1 F_7 ( int V_20 , void * V_21 )
{
struct V_3 * V_4 = V_21 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 -> V_26 ;
struct V_28 T_2 * V_29 = V_4 -> V_29 ;
T_1 V_30 = V_31 ;
T_3 V_32 , V_33 = 0 ;
V_32 = F_8 ( & V_29 -> V_32 ) ;
if ( V_32 & V_34 ) {
F_9 ( V_26 , L_1 ) ;
F_1 ( V_2 ) ;
V_33 |= V_34 ;
V_30 = V_35 ;
}
if ( V_32 & V_36 )
V_30 = V_35 ;
if ( V_32 & V_37 ) {
F_9 ( V_26 , L_2 ) ;
F_1 ( V_2 ) ;
V_33 |= V_37 ;
V_30 = V_35 ;
}
if ( V_32 & V_38 ) {
V_33 |= V_38 ;
V_30 = V_35 ;
}
if ( V_32 & V_39 )
V_30 = V_35 ;
if ( V_32 & V_40 ) {
F_10 ( V_2 ) ;
if ( V_4 -> V_41 != V_19 )
F_3 ( V_4 ) ;
V_33 |= V_40 ;
V_30 = V_35 ;
}
if ( V_32 & V_42 ) {
V_33 |= V_42 ;
V_30 = V_35 ;
}
if ( V_33 )
F_11 ( & V_29 -> V_32 , V_33 ) ;
return V_30 ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_43 * V_44 = V_23 -> V_44 -> V_43 ;
struct V_45 * V_46 = V_23 -> V_46 ;
int V_30 ;
V_30 = F_13 ( V_44 -> V_26 , F_14 ( 36 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_46 -> V_47 [ V_9 ] . V_2 ) {
V_30 = F_15 ( V_48 , V_44 -> V_26 ,
V_49 . V_50 ,
& V_46 -> V_47 [ V_9 ] . V_2 -> V_51 ) ;
if ( V_30 ) {
F_9 ( V_44 -> V_26 , L_3 ) ;
return V_30 ;
}
}
if ( V_46 -> V_47 [ V_52 ] . V_2 ) {
V_30 = F_15 ( V_48 , V_44 -> V_26 ,
V_49 . V_50 ,
& V_46 -> V_47 [ V_52 ] . V_2 -> V_51 ) ;
if ( V_30 ) {
F_9 ( V_44 -> V_26 , L_4 ) ;
F_16 ( & V_46 -> V_47 [ V_9 ] . V_2 -> V_51 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 -> V_26 ;
struct V_55 * V_56 =
F_18 ( V_23 -> V_27 -> V_57 , struct V_55 , V_58 ) ;
struct V_3 * V_4 ;
struct V_28 T_2 * V_29 ;
T_4 V_59 ;
T_5 V_60 ;
T_3 V_61 ;
unsigned int V_62 ;
int V_30 = 0 ;
unsigned int V_63 ;
V_30 = F_19 ( V_54 ,
V_64 ) ;
if ( V_30 < 0 ) {
F_9 ( V_26 , L_5 ) ;
return V_30 ;
}
V_62 = V_2 -> V_8 == V_9 ? 0 : 1 ;
if ( V_56 -> V_65 ) {
F_9 ( V_26 , L_6 ) ;
return - V_66 ;
}
V_4 = F_20 ( V_26 , sizeof( struct V_3 ) ,
& V_59 , V_67 ) ;
if ( ! V_4 ) {
F_9 ( V_26 , L_7 ) ;
return - V_68 ;
}
if ( V_2 -> V_8 == V_9 )
V_4 -> V_69 = V_56 -> V_70 ;
else
V_4 -> V_69 = V_56 -> V_71 ;
V_4 -> V_72 = V_56 -> V_72 ;
V_4 -> V_29 = V_56 -> V_62 ;
V_4 -> V_20 = V_56 -> V_20 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_59 = V_59 ;
V_4 -> V_18 = V_2 -> V_51 . V_73 ;
V_30 = F_21 ( V_4 -> V_20 , F_7 , 0 , L_8 ,
V_4 ) ;
if ( V_30 ) {
F_9 ( V_26 , L_9 ,
V_4 -> V_20 , V_30 ) ;
F_22 ( V_26 , sizeof( struct V_3 ) ,
V_4 , V_4 -> V_59 ) ;
return V_30 ;
}
V_56 -> V_65 = 1 ;
F_23 ( V_2 , & V_2 -> V_51 ) ;
F_24 ( V_2 , & V_49 ) ;
V_54 -> V_24 = V_4 ;
V_29 = V_4 -> V_29 ;
V_60 = V_4 -> V_59 +
sizeof( struct V_5 ) ;
for ( V_63 = 0 ; V_63 < V_19 ; V_63 ++ ) {
V_4 -> V_6 [ V_63 ] . V_74 = F_25 ( V_60 ) ;
V_60 += sizeof( struct V_5 ) ;
}
V_4 -> V_6 [ V_63 - 1 ] . V_74 = F_25 ( V_4 -> V_59 ) ;
F_11 ( & V_29 -> V_75 ,
F_26 ( V_4 -> V_59 ) ) ;
F_11 ( & V_29 -> V_76 ,
F_27 ( V_4 -> V_59 ) ) ;
F_11 ( & V_29 -> V_77 , 0 ) ;
V_61 = F_8 ( & V_29 -> V_61 ) &
~ ( V_78 | V_79 | V_80 ) ;
V_61 |= V_81 | V_82 | V_83 |
V_84 ;
V_61 |= ( V_2 -> V_8 == V_9 ) ?
V_79 : V_80 ;
F_11 ( & V_29 -> V_61 , V_61 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_3 * V_4 = V_54 -> V_24 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 -> V_26 ;
unsigned int V_87 =
F_29 ( F_30 ( V_86 ) ) ;
unsigned int V_88 = V_87 / 8 ;
T_4 V_69 = V_4 -> V_69 ;
T_6 V_89 = F_31 ( V_86 ) ;
T_6 V_16 = F_32 ( V_86 ) ;
T_4 V_90 = V_2 -> V_51 . V_73 ;
struct V_28 T_2 * V_29 = V_4 -> V_29 ;
T_3 V_61 ;
unsigned int V_63 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_41 = F_33 ( V_86 ) ;
V_4 -> V_17 = V_4 -> V_18 + V_89 ;
V_4 -> V_11 = V_4 -> V_18 +
( V_19 * V_16 ) ;
if ( V_4 -> V_11 >= V_4 -> V_17 )
V_4 -> V_11 = V_4 -> V_18 ;
V_61 = F_8 ( & V_29 -> V_61 ) & ~ ( V_91 |
V_92 | V_93 ) ;
switch ( V_87 ) {
case 8 :
V_61 |= V_94 | V_95 ;
V_69 += 3 ;
break;
case 16 :
V_61 |= V_96 | V_97 ;
V_69 += 2 ;
break;
case 32 :
V_61 |= V_98 | V_99 ;
break;
default:
F_9 ( V_26 , L_10 , V_87 ) ;
return - V_100 ;
}
V_61 |= F_34 ( ( V_4 -> V_72 - 2 ) * V_88 ) ;
F_11 ( & V_29 -> V_61 , V_61 ) ;
for ( V_63 = 0 ; V_63 < V_19 ; V_63 ++ ) {
struct V_5 * V_6 = & V_4 -> V_6 [ V_63 ] ;
V_6 -> V_101 = F_4 ( V_16 ) ;
if ( V_2 -> V_8 == V_9 ) {
V_6 -> V_10 = F_4 ( V_90 ) ;
V_6 -> V_12 = F_4 ( V_13 |
F_6 ( V_90 ) ) ;
V_6 -> V_14 = F_4 ( V_69 ) ;
V_6 -> V_15 = F_4 ( V_102 |
F_6 ( V_69 ) ) ;
} else {
V_6 -> V_10 = F_4 ( V_69 ) ;
V_6 -> V_12 = F_4 ( V_102 |
F_6 ( V_69 ) ) ;
V_6 -> V_14 = F_4 ( V_90 ) ;
V_6 -> V_15 = F_4 ( V_13 |
F_6 ( V_90 ) ) ;
}
V_90 += V_16 ;
}
return 0 ;
}
static T_7 F_35 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_3 * V_4 = V_54 -> V_24 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 -> V_26 ;
struct V_28 T_2 * V_29 = V_4 -> V_29 ;
T_4 V_103 ;
T_7 V_104 ;
if ( V_2 -> V_8 == V_9 ) {
V_103 = F_8 ( & V_29 -> V_105 ) ;
#ifdef F_5
V_103 |= ( T_5 ) ( F_8 ( & V_29 -> V_106 ) &
V_107 ) << 32 ;
#endif
} else {
V_103 = F_8 ( & V_29 -> V_108 ) ;
#ifdef F_5
V_103 |= ( T_5 ) ( F_8 ( & V_29 -> V_109 ) &
V_107 ) << 32 ;
#endif
}
if ( ! V_103 )
return 0 ;
if ( ( V_103 < V_4 -> V_18 ) ||
( V_103 > V_4 -> V_17 ) ) {
F_9 ( V_26 , L_11 ) ;
return V_110 ;
}
V_104 = F_36 ( V_54 , V_103 - V_4 -> V_18 ) ;
if ( V_104 == V_54 -> V_89 )
V_104 = 0 ;
return V_104 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_3 * V_4 = V_54 -> V_24 ;
if ( V_4 ) {
struct V_28 T_2 * V_29 ;
V_29 = V_4 -> V_29 ;
F_11 ( & V_29 -> V_61 , V_78 ) ;
F_11 ( & V_29 -> V_61 , 0 ) ;
F_11 ( & V_29 -> V_32 , - 1 ) ;
F_11 ( & V_29 -> V_75 , 0 ) ;
F_11 ( & V_29 -> V_76 , 0 ) ;
F_11 ( & V_29 -> V_106 , 0 ) ;
F_11 ( & V_29 -> V_105 , 0 ) ;
F_11 ( & V_29 -> V_109 , 0 ) ;
F_11 ( & V_29 -> V_108 , 0 ) ;
F_11 ( & V_29 -> V_77 , 0 ) ;
F_11 ( & V_29 -> V_111 , 0 ) ;
F_11 ( & V_29 -> V_112 , 0 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_3 * V_4 = V_54 -> V_24 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 -> V_26 ;
struct V_55 * V_56 =
F_18 ( V_23 -> V_27 -> V_57 , struct V_55 , V_58 ) ;
if ( V_4 ) {
if ( V_4 -> V_20 )
F_39 ( V_4 -> V_20 , V_4 ) ;
F_22 ( V_26 , sizeof( struct V_3 ) ,
V_4 , V_4 -> V_59 ) ;
V_2 -> V_54 -> V_24 = NULL ;
}
V_56 -> V_65 = 0 ;
return 0 ;
}
static void F_40 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
unsigned int V_63 ;
for ( V_63 = 0 ; V_63 < F_41 ( V_46 -> V_47 ) ; V_63 ++ ) {
V_2 = V_46 -> V_47 [ V_63 ] . V_2 ;
if ( V_2 ) {
F_16 ( & V_2 -> V_51 ) ;
V_2 -> V_51 . V_113 = NULL ;
V_2 -> V_51 . V_73 = 0 ;
}
}
}
static struct V_114 * F_42 ( struct V_114 * V_115 )
{
struct V_114 * V_116 , * V_117 ;
F_43 (ssi_np, NULL, L_12 ) {
V_117 = F_44 ( V_116 , L_13 , 0 ) ;
F_45 ( V_117 ) ;
if ( V_117 == V_115 )
return V_116 ;
V_117 = F_44 ( V_116 , L_14 , 0 ) ;
F_45 ( V_117 ) ;
if ( V_117 == V_115 )
return V_116 ;
}
return NULL ;
}
static int F_46 ( struct V_118 * V_119 )
{
struct V_55 * V_56 ;
struct V_114 * V_117 = V_119 -> V_26 . V_120 ;
struct V_114 * V_116 ;
struct V_121 V_122 ;
const T_8 * V_123 ;
int V_30 ;
V_116 = F_42 ( V_117 ) ;
if ( ! V_116 ) {
F_9 ( & V_119 -> V_26 , L_15 ) ;
return - V_124 ;
}
V_30 = F_47 ( V_116 , 0 , & V_122 ) ;
if ( V_30 ) {
F_9 ( & V_119 -> V_26 , L_16 ,
V_116 -> V_125 ) ;
F_45 ( V_116 ) ;
return V_30 ;
}
V_56 = F_48 ( sizeof( * V_56 ) + strlen ( V_117 -> V_125 ) , V_67 ) ;
if ( ! V_56 ) {
F_9 ( & V_119 -> V_26 , L_17 ) ;
F_45 ( V_116 ) ;
return - V_68 ;
}
strcpy ( V_56 -> V_126 , V_117 -> V_125 ) ;
V_56 -> V_58 . V_127 = & V_128 ;
V_56 -> V_58 . V_129 = F_12 ;
V_56 -> V_58 . V_130 = F_40 ;
V_56 -> V_70 = V_122 . V_131 + V_132 ;
V_56 -> V_71 = V_122 . V_131 + V_133 ;
V_123 = F_49 ( V_116 , L_18 , NULL ) ;
if ( V_123 )
V_56 -> V_72 = F_50 ( V_123 ) ;
else
V_56 -> V_72 = 8 ;
F_45 ( V_116 ) ;
V_30 = F_51 ( & V_119 -> V_26 , & V_56 -> V_58 ) ;
if ( V_30 ) {
F_9 ( & V_119 -> V_26 , L_19 ) ;
F_52 ( V_56 ) ;
return V_30 ;
}
V_56 -> V_62 = F_53 ( V_117 , 0 ) ;
V_56 -> V_20 = F_54 ( V_117 , 0 ) ;
F_55 ( & V_119 -> V_26 , V_56 ) ;
return 0 ;
}
static int F_56 ( struct V_118 * V_119 )
{
struct V_55 * V_56 = F_57 ( & V_119 -> V_26 ) ;
F_58 ( & V_119 -> V_26 ) ;
F_59 ( V_56 -> V_62 ) ;
F_60 ( V_56 -> V_20 ) ;
F_52 ( V_56 ) ;
return 0 ;
}
