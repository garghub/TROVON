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
static int F_15 ( struct V_45 * V_46 , struct V_47 * V_48 ,
struct V_49 * V_50 )
{
static T_4 V_51 = F_16 ( 36 ) ;
int V_32 ;
if ( ! V_46 -> V_28 -> V_52 )
V_46 -> V_28 -> V_52 = & V_51 ;
if ( ! V_46 -> V_28 -> V_53 )
V_46 -> V_28 -> V_53 = V_51 ;
if ( V_50 -> V_54 [ 0 ] . V_2 ) {
V_32 = F_17 ( V_55 , V_46 -> V_28 ,
V_56 . V_57 ,
& V_50 -> V_54 [ 0 ] . V_2 -> V_58 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_3 ) ;
return V_32 ;
}
}
if ( V_50 -> V_54 [ 1 ] . V_2 ) {
V_32 = F_17 ( V_55 , V_46 -> V_28 ,
V_56 . V_57 ,
& V_50 -> V_54 [ 1 ] . V_2 -> V_58 ) ;
if ( V_32 ) {
F_12 ( V_46 -> V_28 , L_4 ) ;
F_18 ( & V_50 -> V_54 [ 0 ] . V_2 -> V_58 ) ;
return V_32 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_61 * V_62 =
F_20 ( V_25 -> V_29 -> V_63 , struct V_61 , V_48 ) ;
struct V_5 * V_6 ;
struct V_30 T_2 * V_31 ;
T_5 V_64 ;
T_4 V_65 ;
T_3 V_66 ;
unsigned int V_67 ;
int V_32 = 0 ;
unsigned int V_68 ;
V_32 = F_21 ( V_60 ,
V_69 ) ;
if ( V_32 < 0 ) {
F_12 ( V_28 , L_5 ) ;
return V_32 ;
}
V_67 = V_2 -> V_10 == V_11 ? 0 : 1 ;
if ( V_62 -> V_70 ) {
F_12 ( V_28 , L_6 ) ;
return - V_71 ;
}
V_6 = F_22 ( V_28 , sizeof( struct V_5 ) ,
& V_64 , V_72 ) ;
if ( ! V_6 ) {
F_12 ( V_28 , L_7 ) ;
return - V_73 ;
}
if ( V_2 -> V_10 == V_11 )
V_6 -> V_74 = V_62 -> V_75 ;
else
V_6 -> V_74 = V_62 -> V_76 ;
V_6 -> V_77 = V_62 -> V_77 ;
V_6 -> V_31 = V_62 -> V_67 ;
V_6 -> V_22 = V_62 -> V_22 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_64 = V_64 ;
V_6 -> V_20 = V_2 -> V_58 . V_78 ;
V_32 = F_23 ( V_6 -> V_22 , F_10 , 0 , L_8 ,
V_6 ) ;
if ( V_32 ) {
F_12 ( V_28 , L_9 ,
V_6 -> V_22 , V_32 ) ;
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_64 ) ;
return V_32 ;
}
V_62 -> V_70 = 1 ;
F_25 ( V_2 , & V_2 -> V_58 ) ;
F_26 ( V_2 , & V_56 ) ;
V_60 -> V_26 = V_6 ;
V_31 = V_6 -> V_31 ;
V_65 = V_6 -> V_64 +
sizeof( struct V_7 ) ;
for ( V_68 = 0 ; V_68 < V_21 ; V_68 ++ ) {
V_6 -> V_8 [ V_68 ] . V_79 = F_27 ( V_65 ) ;
V_65 += sizeof( struct V_7 ) ;
}
V_6 -> V_8 [ V_68 - 1 ] . V_79 = F_27 ( V_6 -> V_64 ) ;
F_14 ( & V_31 -> V_80 ,
F_28 ( V_6 -> V_64 ) ) ;
F_14 ( & V_31 -> V_81 ,
F_29 ( V_6 -> V_64 ) ) ;
F_14 ( & V_31 -> V_82 , 0 ) ;
V_66 = F_11 ( & V_31 -> V_66 ) &
~ ( V_83 | V_84 | V_85 ) ;
V_66 |= V_86 | V_87 | V_88 |
V_89 ;
V_66 |= ( V_2 -> V_10 == V_11 ) ?
V_84 : V_85 ;
F_14 ( & V_31 -> V_66 , V_66 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_5 * V_6 = V_60 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
unsigned int V_92 =
F_31 ( F_32 ( V_91 ) ) ;
unsigned int V_93 = V_92 / 8 ;
T_5 V_74 = V_6 -> V_74 ;
T_6 V_94 = F_33 ( V_91 ) ;
T_6 V_18 = F_34 ( V_91 ) ;
T_5 V_95 = V_2 -> V_58 . V_78 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_3 V_66 ;
unsigned int V_68 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_43 = F_35 ( V_91 ) ;
V_6 -> V_19 = V_6 -> V_20 + V_94 ;
V_6 -> V_13 = V_6 -> V_20 +
( V_21 * V_18 ) ;
if ( V_6 -> V_13 >= V_6 -> V_19 )
V_6 -> V_13 = V_6 -> V_20 ;
V_66 = F_11 ( & V_31 -> V_66 ) & ~ ( V_96 |
V_97 | V_98 ) ;
switch ( V_92 ) {
case 8 :
V_66 |= V_99 | V_100 ;
V_74 += 3 ;
break;
case 16 :
V_66 |= V_101 | V_102 ;
V_74 += 2 ;
break;
case 32 :
V_66 |= V_103 | V_104 ;
break;
default:
F_12 ( V_28 , L_10 , V_92 ) ;
return - V_105 ;
}
V_66 |= F_36 ( ( V_6 -> V_77 - 2 ) * V_93 ) ;
F_14 ( & V_31 -> V_66 , V_66 ) ;
for ( V_68 = 0 ; V_68 < V_21 ; V_68 ++ ) {
struct V_7 * V_8 = & V_6 -> V_8 [ V_68 ] ;
V_8 -> V_106 = F_7 ( V_18 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_8 -> V_12 = F_7 ( V_95 ) ;
V_8 -> V_14 = F_7 ( V_15 |
F_9 ( V_95 ) ) ;
V_8 -> V_16 = F_7 ( V_74 ) ;
V_8 -> V_17 = F_7 ( V_107 |
F_9 ( V_74 ) ) ;
} else {
V_8 -> V_12 = F_7 ( V_74 ) ;
V_8 -> V_14 = F_7 ( V_107 |
F_9 ( V_74 ) ) ;
V_8 -> V_16 = F_7 ( V_95 ) ;
V_8 -> V_17 = F_7 ( V_15 |
F_9 ( V_95 ) ) ;
}
V_95 += V_18 ;
}
return 0 ;
}
static T_7 F_37 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_5 * V_6 = V_60 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_30 T_2 * V_31 = V_6 -> V_31 ;
T_5 V_108 ;
T_7 V_109 ;
if ( V_2 -> V_10 == V_11 ) {
V_108 = F_11 ( & V_31 -> V_110 ) ;
#ifdef F_8
V_108 |= ( T_4 ) ( F_11 ( & V_31 -> V_111 ) &
V_112 ) << 32 ;
#endif
} else {
V_108 = F_11 ( & V_31 -> V_113 ) ;
#ifdef F_8
V_108 |= ( T_4 ) ( F_11 ( & V_31 -> V_114 ) &
V_112 ) << 32 ;
#endif
}
if ( ! V_108 )
return 0 ;
if ( ( V_108 < V_6 -> V_20 ) ||
( V_108 > V_6 -> V_19 ) ) {
F_12 ( V_28 , L_11 ) ;
return V_115 ;
}
V_109 = F_38 ( V_60 , V_108 - V_6 -> V_20 ) ;
if ( V_109 == V_60 -> V_94 )
V_109 = 0 ;
return V_109 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_5 * V_6 = V_60 -> V_26 ;
if ( V_6 ) {
struct V_30 T_2 * V_31 ;
V_31 = V_6 -> V_31 ;
F_14 ( & V_31 -> V_66 , V_83 ) ;
F_14 ( & V_31 -> V_66 , 0 ) ;
F_14 ( & V_31 -> V_34 , - 1 ) ;
F_14 ( & V_31 -> V_80 , 0 ) ;
F_14 ( & V_31 -> V_81 , 0 ) ;
F_14 ( & V_31 -> V_111 , 0 ) ;
F_14 ( & V_31 -> V_110 , 0 ) ;
F_14 ( & V_31 -> V_114 , 0 ) ;
F_14 ( & V_31 -> V_113 , 0 ) ;
F_14 ( & V_31 -> V_82 , 0 ) ;
F_14 ( & V_31 -> V_116 , 0 ) ;
F_14 ( & V_31 -> V_117 , 0 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_5 * V_6 = V_60 -> V_26 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 -> V_28 ;
struct V_61 * V_62 =
F_20 ( V_25 -> V_29 -> V_63 , struct V_61 , V_48 ) ;
if ( V_6 ) {
if ( V_6 -> V_22 )
F_41 ( V_6 -> V_22 , V_6 ) ;
if ( V_6 -> V_64 ) {
F_42 ( V_28 , V_6 -> V_64 ,
sizeof( V_6 -> V_8 ) ,
V_118 ) ;
}
F_24 ( V_28 , sizeof( struct V_5 ) ,
V_6 , V_6 -> V_64 ) ;
V_2 -> V_60 -> V_26 = NULL ;
}
V_62 -> V_70 = 0 ;
return 0 ;
}
static void F_43 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < F_44 ( V_50 -> V_54 ) ; V_68 ++ ) {
V_2 = V_50 -> V_54 [ V_68 ] . V_2 ;
if ( V_2 ) {
F_18 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_119 = NULL ;
V_2 -> V_58 . V_78 = 0 ;
}
}
}
static struct V_120 * F_45 ( struct V_120 * V_121 )
{
struct V_120 * V_122 , * V_123 ;
F_46 (ssi_np, NULL, L_12 ) {
V_123 = F_47 ( V_122 , L_13 , 0 ) ;
if ( V_123 == V_121 )
return V_122 ;
V_123 = F_47 ( V_122 , L_14 , 0 ) ;
if ( V_123 == V_121 )
return V_122 ;
}
return NULL ;
}
static int T_8 F_48 ( struct V_124 * V_125 )
{
struct V_61 * V_62 ;
struct V_120 * V_123 = V_125 -> V_28 . V_126 ;
struct V_120 * V_122 ;
struct V_127 V_128 ;
const T_9 * V_129 ;
int V_32 ;
V_122 = F_45 ( V_123 ) ;
if ( ! V_122 ) {
F_12 ( & V_125 -> V_28 , L_15 ) ;
return - V_130 ;
}
V_32 = F_49 ( V_122 , 0 , & V_128 ) ;
if ( V_32 ) {
F_12 ( & V_125 -> V_28 , L_16 ,
V_122 -> V_131 ) ;
F_50 ( V_122 ) ;
return V_32 ;
}
V_62 = F_51 ( sizeof( * V_62 ) + strlen ( V_123 -> V_131 ) , V_72 ) ;
if ( ! V_62 ) {
F_12 ( & V_125 -> V_28 , L_17 ) ;
F_50 ( V_122 ) ;
return - V_73 ;
}
strcpy ( V_62 -> V_132 , V_123 -> V_131 ) ;
V_62 -> V_48 . V_133 = & V_134 ;
V_62 -> V_48 . V_135 = F_15 ;
V_62 -> V_48 . V_136 = F_43 ;
V_62 -> V_75 = V_128 . V_137 + F_52 ( struct V_138 , V_139 ) ;
V_62 -> V_76 = V_128 . V_137 + F_52 ( struct V_138 , V_140 ) ;
V_129 = F_53 ( V_122 , L_18 , NULL ) ;
if ( V_129 )
V_62 -> V_77 = * V_129 ;
else
V_62 -> V_77 = 8 ;
F_50 ( V_122 ) ;
V_32 = F_54 ( & V_125 -> V_28 , & V_62 -> V_48 ) ;
if ( V_32 ) {
F_12 ( & V_125 -> V_28 , L_19 ) ;
F_55 ( V_62 ) ;
return V_32 ;
}
V_62 -> V_67 = F_56 ( V_123 , 0 ) ;
V_62 -> V_22 = F_57 ( V_123 , 0 ) ;
F_58 ( & V_125 -> V_28 , V_62 ) ;
return 0 ;
}
static int T_10 F_59 ( struct V_124 * V_125 )
{
struct V_61 * V_62 = F_60 ( & V_125 -> V_28 ) ;
F_61 ( & V_125 -> V_28 ) ;
F_62 ( V_62 -> V_67 ) ;
F_63 ( V_62 -> V_22 ) ;
F_55 ( V_62 ) ;
return 0 ;
}
static int T_11 F_64 ( void )
{
F_65 ( L_20 ) ;
return F_66 ( & V_141 ) ;
}
static void T_12 F_67 ( void )
{
F_68 ( & V_141 ) ;
}
