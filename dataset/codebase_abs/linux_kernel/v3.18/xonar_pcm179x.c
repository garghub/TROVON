static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
static const T_1 V_6 [ 4 ] = {
0 , 1 , 2 , 4
} ;
F_2 ( V_2 , V_7 |
V_8 |
V_9 |
( V_6 [ V_3 ] << V_10 ) |
V_11 ,
( V_4 << 8 ) | V_5 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
F_4 ( V_2 , F_5 ( V_3 ) , V_4 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( ( V_2 -> V_15 . V_16 & V_17 ) ==
V_18 )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
else
F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ( unsigned int ) ( V_4 - V_19 )
< F_7 ( V_13 -> V_20 [ V_3 ] ) )
V_13 -> V_20 [ V_3 ] [ V_4 - V_19 ] = V_5 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_5 != V_13 -> V_20 [ V_3 ] [ V_4 - V_19 ] )
F_6 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_4 ( V_2 , V_21 , V_4 , V_5 ) ;
V_13 -> V_22 [ V_4 ] = V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_5 != V_13 -> V_22 [ V_4 ] )
F_9 ( V_2 , V_4 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
T_2 V_24 ;
F_12 ( 1 ) ;
V_24 = V_13 -> V_25 ? V_13 -> V_26 : 0 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_27 ; ++ V_23 ) {
F_6 ( V_2 , V_23 , 18 ,
V_13 -> V_20 [ 0 ] [ 18 - V_19 ] ) ;
F_6 ( V_2 , V_23 , 16 , V_2 -> V_28 [ V_23 * 2 ]
+ V_24 ) ;
F_6 ( V_2 , V_23 , 17 , V_2 -> V_28 [ V_23 * 2 + 1 ]
+ V_24 ) ;
F_6 ( V_2 , V_23 , 19 ,
V_13 -> V_20 [ 0 ] [ 19 - V_19 ] ) ;
F_6 ( V_2 , V_23 , 20 ,
V_13 -> V_20 [ 0 ] [ 20 - V_19 ] ) ;
F_6 ( V_2 , V_23 , 21 , 0 ) ;
V_24 = 0 ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_20 [ 0 ] [ 18 - V_19 ] =
V_29 | V_30 | V_31 ;
if ( ! V_13 -> V_32 )
V_13 -> V_20 [ 0 ] [ 18 - V_19 ] |= V_33 ;
V_13 -> V_20 [ 0 ] [ 19 - V_19 ] =
V_34 | V_35 ;
V_13 -> V_20 [ 0 ] [ 20 - V_19 ] =
V_13 -> V_36 ? V_37 : V_38 ;
F_11 ( V_2 ) ;
V_13 -> V_39 = 48000 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_40 . V_41 = 300 ;
V_13 -> V_40 . V_42 = V_43 ;
V_13 -> V_27 = 4 ;
F_13 ( V_2 ) ;
F_15 ( V_2 , V_44 , V_45 ) ;
F_16 ( V_2 , V_46 , V_45 ) ;
F_17 ( V_2 , 0 , V_47 , V_48 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_49 , L_1 ) ;
F_20 ( V_2 -> V_49 , L_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_40 . V_50 = V_46 ;
V_13 -> V_40 . V_51 = V_52 ;
V_13 -> V_40 . V_53 = V_54 ;
F_16 ( V_2 , V_44 , V_54 ) ;
F_22 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_55 * V_13 = V_2 -> V_14 ;
F_24 ( V_2 , V_56 ,
V_57 |
V_58 |
V_59 ) ;
V_13 -> V_60 . V_40 . V_41 = 100 ;
V_13 -> V_60 . V_40 . V_42 = V_61 ;
V_13 -> V_60 . V_40 . V_50 = V_62 ;
V_13 -> V_60 . V_40 . V_51 = V_63 ;
V_13 -> V_60 . V_40 . V_53 = V_64 ;
V_13 -> V_60 . V_27 = V_2 -> V_15 . V_65 / 2 ;
V_13 -> V_60 . V_36 = V_2 -> V_15 . V_65 > 2 ;
F_13 ( V_2 ) ;
F_15 ( V_2 , V_44 ,
V_66 | V_67 ) ;
F_16 ( V_2 , V_46 , V_67 ) ;
F_18 ( V_2 ) ;
F_22 ( V_2 ) ;
F_25 ( V_2 , & V_13 -> V_68 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_49 , L_1 ) ;
F_20 ( V_2 -> V_49 , L_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_56 ,
V_57 |
V_58 |
V_59 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_40 . V_42 = V_69 ;
V_13 -> V_27 = V_2 -> V_15 . V_65 / 2 ;
V_13 -> V_36 = V_2 -> V_15 . V_65 > 2 ;
V_13 -> V_26 = 2 * - 18 ;
F_13 ( V_2 ) ;
F_15 ( V_2 , V_44 ,
V_67 | V_70 |
V_71 | V_72 ) ;
F_16 ( V_2 , V_46 ,
V_67 | V_70 | V_72 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_49 , L_3 ) ;
F_20 ( V_2 -> V_49 , L_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_9 ( V_2 , V_73 , V_74 ) ;
F_9 ( V_2 , V_75 , 0 ) ;
F_9 ( V_2 , V_76 ,
V_77 |
( 0 << V_78 ) |
V_79 |
V_80 ) ;
F_9 ( V_2 , V_81 ,
( 0 << V_82 ) |
V_83 ) ;
F_9 ( V_2 , V_84 + 0 , 0x00 ) ;
F_9 ( V_2 , V_84 + 1 , 0x10 ) ;
F_9 ( V_2 , V_84 + 2 , 0x00 ) ;
F_9 ( V_2 , V_84 + 3 , 0x00 ) ;
F_9 ( V_2 , V_85 ,
V_13 -> V_22 [ V_85 ] ) ;
F_9 ( V_2 , V_86 , 0 ) ;
F_9 ( V_2 , V_73 , V_87 ) ;
F_12 ( 3 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_40 . V_41 = 100 ;
V_13 -> V_36 = V_2 -> V_15 . V_65 > 2 ;
V_13 -> V_88 = 1 ;
V_13 -> V_22 [ V_85 ] = V_89 ;
V_13 -> V_32 = true ;
F_24 ( V_2 , V_90 ,
V_91 |
V_92 |
F_30 ( V_13 -> V_36 ? V_93 : V_94 ) |
V_95 |
V_96 |
V_97 ) ;
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
F_27 ( V_2 ) ;
F_20 ( V_2 -> V_49 , L_4 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_26 ( V_2 ) ;
V_13 -> V_40 . V_41 = 800 ;
V_13 -> V_40 . V_50 = V_62 ;
V_13 -> V_40 . V_51 = V_63 ;
V_13 -> V_40 . V_53 = V_64 ;
F_22 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_40 . V_50 = V_62 ;
V_13 -> V_40 . V_51 = V_63 ;
V_13 -> V_40 . V_53 = V_64 ;
F_22 ( V_2 ) ;
V_13 -> V_40 . V_41 = 100 ;
V_13 -> V_88 = 1 ;
V_13 -> V_22 [ V_85 ] = V_89 ;
F_24 ( V_2 , V_90 ,
V_91 |
V_92 |
F_30 ( V_94 ) |
V_95 |
V_96 |
V_97 ) ;
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
V_13 -> V_40 . V_42 = V_98 ;
V_13 -> V_27 = 1 ;
V_13 -> V_26 = 2 * - 18 ;
F_13 ( V_2 ) ;
F_15 ( V_2 , V_44 ,
V_67 | V_70 |
V_71 | V_99 ) ;
F_16 ( V_2 , V_46 ,
V_67 | V_70 |
V_99 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_49 , L_1 ) ;
F_20 ( V_2 -> V_49 , L_2 ) ;
F_20 ( V_2 -> V_49 , L_4 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
F_12 ( 2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_55 * V_13 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
F_43 ( V_2 , & V_13 -> V_68 ) ;
F_19 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
T_1 V_4 ;
if ( V_13 -> V_39 <= 48000 && ! V_13 -> V_36 )
V_4 = V_38 ;
else
V_4 = V_37 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_27 ; ++ V_23 )
F_8 ( V_2 , V_23 , 20 , V_4 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_12 ( 1 ) ;
V_13 -> V_39 = F_48 ( V_101 ) ;
F_46 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
T_2 V_24 ;
V_24 = V_13 -> V_25 ? V_13 -> V_26 : 0 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_27 ; ++ V_23 ) {
F_8 ( V_2 , V_23 , 16 , V_2 -> V_28 [ V_23 * 2 ]
+ V_24 ) ;
F_8 ( V_2 , V_23 , 17 , V_2 -> V_28 [ V_23 * 2 + 1 ]
+ V_24 ) ;
V_24 = 0 ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
T_1 V_5 ;
V_5 = V_29 | V_30 | V_31 ;
if ( V_2 -> V_102 )
V_5 |= V_33 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_27 ; ++ V_23 )
F_8 ( V_2 , V_23 , 18 , V_5 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_103 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
T_1 V_104 , V_4 ;
switch ( V_103 ) {
case 32000 :
case 64000 :
V_104 = V_105 ;
break;
case 44100 :
case 88200 :
case 176400 :
V_104 = V_106 ;
break;
default:
case 48000 :
case 96000 :
case 192000 :
V_104 = V_91 ;
break;
}
if ( V_103 <= 96000 && ( V_103 > 48000 || V_13 -> V_36 ) ) {
V_104 |= F_30 ( V_93 ) ;
V_4 = V_89 ;
} else {
V_104 |= F_30 ( V_94 ) ;
V_4 = V_107 ;
}
F_52 ( V_2 , V_90 , V_104 ,
V_108 | V_109 ) ;
F_10 ( V_2 , V_85 , V_4 ) ;
F_12 ( 3 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
F_51 ( V_2 , F_48 ( V_101 ) ) ;
F_47 ( V_2 , V_101 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_55 * V_13 = V_2 -> V_14 ;
F_47 ( V_2 , V_101 ) ;
F_55 ( V_2 , & V_13 -> V_68 , V_101 ) ;
}
static int F_56 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
static const char * const V_114 [ 2 ] = {
L_5 , L_6
} ;
return F_57 ( V_113 , 1 , 2 , V_114 ) ;
}
static int F_58 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
V_5 -> V_5 . V_117 . V_118 [ 0 ] =
( V_13 -> V_20 [ 0 ] [ 19 - V_19 ] &
V_119 ) != V_34 ;
return 0 ;
}
static int F_59 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
int V_120 ;
T_1 V_4 ;
F_60 ( & V_2 -> V_121 ) ;
V_4 = V_13 -> V_20 [ 0 ] [ 19 - V_19 ] ;
V_4 &= ~ V_119 ;
if ( ! V_5 -> V_5 . V_117 . V_118 [ 0 ] )
V_4 |= V_34 ;
else
V_4 |= V_122 ;
V_120 = V_4 != V_13 -> V_20 [ 0 ] [ 19 - V_19 ] ;
if ( V_120 ) {
for ( V_23 = 0 ; V_23 < V_13 -> V_27 ; ++ V_23 )
F_6 ( V_2 , V_23 , 19 , V_4 ) ;
}
F_61 ( & V_2 -> V_121 ) ;
return V_120 ;
}
static int F_62 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
static const char * const V_114 [ 3 ] = {
L_7 , L_8 , L_9
} ;
return F_57 ( V_113 , 1 , 3 , V_114 ) ;
}
static int F_63 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
T_3 V_123 ;
V_123 = F_64 ( V_2 , V_46 ) ;
if ( ! ( V_123 & V_72 ) )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 0 ;
else if ( V_123 & V_70 )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 1 ;
else
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 2 ;
return 0 ;
}
static int F_65 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
T_3 V_124 , V_123 ;
F_60 ( & V_2 -> V_121 ) ;
V_124 = F_64 ( V_2 , V_46 ) ;
V_123 = V_124 ;
switch ( V_5 -> V_5 . V_117 . V_118 [ 0 ] ) {
case 0 :
V_123 &= ~ ( V_72 | V_70 ) ;
break;
case 1 :
V_123 |= V_72 | V_70 ;
break;
case 2 :
V_123 = ( V_123 | V_72 ) & ~ V_70 ;
break;
}
F_24 ( V_2 , V_46 , V_123 ) ;
V_13 -> V_25 = V_123 & V_72 ;
F_49 ( V_2 ) ;
F_61 ( & V_2 -> V_121 ) ;
return V_123 != V_124 ;
}
static int F_66 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
static const char * const V_114 [ 4 ] = {
L_10 , L_11 , L_12 , L_13
} ;
return F_57 ( V_113 , 1 , 4 , V_114 ) ;
}
static int F_67 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
F_60 ( & V_2 -> V_121 ) ;
if ( V_13 -> V_26 < 2 * - 12 )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 0 ;
else if ( V_13 -> V_26 < 2 * - 6 )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 1 ;
else if ( V_13 -> V_26 < 0 )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 2 ;
else
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 3 ;
F_61 ( & V_2 -> V_121 ) ;
return 0 ;
}
static int F_68 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
static const T_2 V_125 [] = { 2 * - 18 , 2 * - 12 , 2 * - 6 , 0 } ;
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
T_2 V_126 ;
int V_120 ;
if ( V_5 -> V_5 . V_117 . V_118 [ 0 ] > 3 )
return - V_127 ;
V_126 = V_125 [ V_5 -> V_5 . V_117 . V_118 [ 0 ] ] ;
F_60 ( & V_2 -> V_121 ) ;
V_120 = V_126 != V_13 -> V_26 ;
if ( V_120 ) {
V_13 -> V_26 = V_126 ;
F_49 ( V_2 ) ;
}
F_61 ( & V_2 -> V_121 ) ;
return V_120 ;
}
static int F_69 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
T_3 V_123 ;
V_123 = F_64 ( V_2 , V_46 ) ;
if ( V_123 & V_99 )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 0 ;
else if ( ! ( V_123 & V_99 ) && ( V_123 & V_70 ) )
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 1 ;
else
V_5 -> V_5 . V_117 . V_118 [ 0 ] = 2 ;
return 0 ;
}
static int F_70 ( struct V_110 * V_111 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_12 * V_13 = V_2 -> V_14 ;
T_3 V_124 , V_123 ;
F_60 ( & V_2 -> V_121 ) ;
V_124 = F_64 ( V_2 , V_46 ) ;
V_123 = V_124 ;
switch ( V_5 -> V_5 . V_117 . V_118 [ 0 ] ) {
case 0 :
V_123 |= V_99 | V_70 ;
break;
case 1 :
V_123 = ( V_123 | V_70 ) & ~ V_99 ;
break;
case 2 :
V_123 &= ~ ( V_99 | V_70 ) ;
break;
}
F_24 ( V_2 , V_46 , V_123 ) ;
V_13 -> V_25 = ! ( V_123 & V_99 ) ;
F_49 ( V_2 ) ;
F_61 ( & V_2 -> V_121 ) ;
return V_123 != V_124 ;
}
static void F_71 ( struct V_1 * V_2 ,
unsigned int V_4 , unsigned int V_128 )
{
if ( V_4 == V_129 ) {
F_72 ( & V_2 -> V_130 ) ;
F_52 ( V_2 , V_46 ,
V_128 ? V_67 : 0 ,
V_67 ) ;
F_73 ( & V_2 -> V_130 ) ;
}
}
static int F_74 ( struct V_131 * V_132 )
{
if ( ! strncmp ( V_132 -> V_133 , L_14 , 11 ) )
V_132 -> V_134 ^= V_135 ^ V_136 ;
return 0 ;
}
static int F_75 ( struct V_131 * V_132 )
{
if ( ! strncmp ( V_132 -> V_133 , L_15 , 16 ) )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_137 ;
if ( ! V_13 -> V_32 ) {
V_137 = F_77 ( V_2 -> V_49 ,
F_78 ( & V_138 , V_2 ) ) ;
if ( V_137 < 0 )
return V_137 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_137 ;
V_137 = F_77 ( V_2 -> V_49 , F_78 ( & V_139 , V_2 ) ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_76 ( V_2 ) ;
if ( V_137 < 0 )
return V_137 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_137 ;
V_137 = F_77 ( V_2 -> V_49 , F_78 ( & V_140 , V_2 ) ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_76 ( V_2 ) ;
if ( V_137 < 0 )
return V_137 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
int V_137 ;
for ( V_23 = 0 ; V_23 < F_7 ( V_141 ) ; ++ V_23 ) {
V_137 = F_77 ( V_2 -> V_49 ,
F_78 ( & V_141 [ V_23 ] , V_2 ) ) ;
if ( V_137 < 0 )
return V_137 ;
}
V_137 = F_76 ( V_2 ) ;
if ( V_137 < 0 )
return V_137 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
int V_137 ;
for ( V_23 = 0 ; V_23 < F_7 ( V_142 ) ; ++ V_23 ) {
V_137 = F_77 ( V_2 -> V_49 ,
F_78 ( & V_142 [ V_23 ] , V_2 ) ) ;
if ( V_137 < 0 )
return V_137 ;
}
V_137 = F_76 ( V_2 ) ;
if ( V_137 < 0 )
return V_137 ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_145 , V_23 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_27 ; ++ V_145 ) {
F_84 ( V_144 , L_16 , V_145 + 1 ) ;
for ( V_23 = 0 ; V_23 < 5 ; ++ V_23 )
F_84 ( V_144 , L_17 ,
V_13 -> V_20 [ V_145 ] [ V_23 ] ) ;
}
F_84 ( V_144 , L_18 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_23 ;
if ( V_13 -> V_88 ) {
F_84 ( V_144 , L_19 ) ;
for ( V_23 = 1 ; V_23 < 0x10 ; ++ V_23 )
F_84 ( V_144 , L_17 , V_13 -> V_22 [ V_23 ] ) ;
F_84 ( V_144 , L_20 ) ;
for ( V_23 = 0x10 ; V_23 < 0x1f ; ++ V_23 )
F_84 ( V_144 , L_17 , V_13 -> V_22 [ V_23 ] ) ;
F_84 ( V_144 , L_18 ) ;
}
}
static void F_86 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
F_83 ( V_2 , V_144 ) ;
F_85 ( V_2 , V_144 ) ;
}
int F_87 ( struct V_1 * V_2 ,
const struct V_146 * V_147 )
{
switch ( V_147 -> V_148 ) {
case 0x8269 :
V_2 -> V_15 = V_149 ;
V_2 -> V_15 . V_150 = L_21 ;
break;
case 0x82b7 :
V_2 -> V_15 = V_149 ;
V_2 -> V_15 . V_150 = L_22 ;
V_2 -> V_15 . V_151 = F_21 ;
break;
case 0x8314 :
V_2 -> V_15 = V_152 ;
F_16 ( V_2 , V_44 , V_153 ) ;
switch ( F_64 ( V_2 , V_46 ) & V_153 ) {
default:
V_2 -> V_15 . V_150 = L_23 ;
break;
case V_154 :
V_2 -> V_15 . V_150 = L_24 ;
V_2 -> V_15 . V_65 = 8 ;
V_2 -> V_15 . V_155 = F_88 ( 256 , 128 , 128 ) ;
break;
}
break;
case 0x835d :
V_2 -> V_15 = V_156 ;
F_16 ( V_2 , V_44 , V_153 ) ;
switch ( F_64 ( V_2 , V_46 ) & V_153 ) {
default:
V_2 -> V_15 . V_150 = L_25 ;
break;
case V_154 :
V_2 -> V_15 . V_150 = L_26 ;
V_2 -> V_15 . V_157 = F_75 ;
V_2 -> V_15 . V_158 = 8 ;
V_2 -> V_15 . V_65 = 8 ;
V_2 -> V_15 . V_159 = 255 ;
V_2 -> V_15 . V_155 = F_88 ( 256 , 128 , 128 ) ;
break;
}
break;
case 0x835c :
V_2 -> V_15 = V_156 ;
V_2 -> V_15 . V_150 = L_27 ;
V_2 -> V_15 . V_151 = F_31 ;
V_2 -> V_15 . V_160 = F_44 ;
V_2 -> V_15 . V_161 = F_47 ;
break;
case 0x85f4 :
V_2 -> V_15 = V_156 ;
F_16 ( V_2 , V_44 , V_153 ) ;
switch ( F_64 ( V_2 , V_46 ) & V_153 ) {
default:
V_2 -> V_15 . V_150 = L_28 ;
break;
case V_154 :
V_2 -> V_15 . V_150 = L_29 ;
V_2 -> V_15 . V_158 = 8 ;
V_2 -> V_15 . V_65 = 8 ;
V_2 -> V_15 . V_155 = F_88 ( 256 , 128 , 128 ) ;
break;
}
V_2 -> V_15 . V_151 = F_31 ;
V_2 -> V_15 . V_160 = F_44 ;
V_2 -> V_15 . V_161 = F_47 ;
break;
case 0x8428 :
V_2 -> V_15 = V_156 ;
V_2 -> V_15 . V_150 = L_30 ;
V_2 -> V_15 . V_2 = L_31 ;
V_2 -> V_15 . V_151 = F_32 ;
V_2 -> V_15 . V_162 = F_82 ;
break;
default:
return - V_127 ;
}
return 0 ;
}
