static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
static const T_1 V_6 [ 4 ] = {
0 , 1 , 2 , 4
} ;
struct V_7 * V_8 = V_2 -> V_9 ;
F_2 ( V_2 , V_10 |
V_11 |
V_12 |
( V_6 [ V_3 ] << V_13 ) |
V_14 ,
V_15 | ( V_4 << 8 ) | V_5 ) ;
V_8 -> V_16 [ V_3 ] [ V_4 ] = V_5 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_5 != V_8 -> V_16 [ V_3 ] [ V_4 ] )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_4 , unsigned int V_5 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_2 ( V_2 , V_10 |
V_11 |
V_12 |
( 3 << V_13 ) |
V_17 ,
( V_4 << 9 ) | V_5 ) ;
if ( V_4 < F_5 ( V_8 -> V_18 ) )
V_8 -> V_18 [ V_4 ] = V_5 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; ++ V_19 ) {
F_1 ( V_2 , V_19 , V_21 ,
V_22 | V_23 ) ;
F_1 ( V_2 , V_19 , V_24 ,
V_8 -> V_16 [ 0 ] [ V_24 ] ) ;
F_1 ( V_2 , V_19 , V_25 ,
V_26 ) ;
F_1 ( V_2 , V_19 , V_27 ,
V_2 -> V_28 [ V_19 * 2 ] ) ;
F_1 ( V_2 , V_19 , V_29 ,
V_2 -> V_28 [ V_19 * 2 + 1 ] ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_20 = V_2 -> V_30 . V_31 / 2 ;
V_8 -> V_16 [ 0 ] [ V_24 ] =
V_32 | V_33 | V_34 ;
F_6 ( V_2 ) ;
F_8 ( V_2 -> V_35 , L_1 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_36 , V_37 ) ;
F_11 ( V_2 , V_38 , V_37 ) ;
F_8 ( V_2 -> V_35 , L_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( V_2 , V_39 , 0 ) ;
F_4 ( V_2 , V_40 , V_8 -> V_18 [ 0 ] ) ;
F_4 ( V_2 , V_41 , V_8 -> V_18 [ 2 ] ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_18 [ 0 ] =
V_42 | V_43 | V_44 ;
V_8 -> V_18 [ 2 ] = V_45 | V_46 ;
F_12 ( V_2 ) ;
F_8 ( V_2 -> V_35 , L_3 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_36 ,
V_47 ) ;
F_16 ( V_2 , V_38 ,
V_48 , V_47 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( 300 ) ;
F_10 ( V_2 , V_36 , V_49 ) ;
F_10 ( V_2 , V_38 , V_49 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_36 , V_50 ) ;
F_11 ( V_2 , V_38 , V_50 ) ;
F_7 ( V_2 ) ;
F_13 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_36 , V_50 ) ;
F_11 ( V_2 , V_38 , V_50 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 -> V_35 , L_4 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static void F_24 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_38 , V_49 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
T_1 V_5 ;
V_5 = V_8 -> V_16 [ 0 ] [ V_24 ] & ~ V_53 ;
if ( F_32 ( V_52 ) <= 54000 )
V_5 |= V_34 ;
else if ( F_32 ( V_52 ) <= 108000 )
V_5 |= V_54 ;
else
V_5 |= V_55 ;
F_18 ( 1 ) ;
if ( V_5 != V_8 -> V_16 [ 0 ] [ V_24 ] ) {
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; ++ V_19 ) {
F_1 ( V_2 , V_19 , V_21 ,
V_22 ) ;
F_1 ( V_2 , V_19 , V_24 , V_5 ) ;
F_1 ( V_2 , V_19 , V_21 ,
V_22 | V_23 ) ;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; ++ V_19 ) {
F_3 ( V_2 , V_19 , V_27 ,
V_2 -> V_28 [ V_19 * 2 ] ) ;
F_3 ( V_2 , V_19 , V_29 ,
V_2 -> V_28 [ V_19 * 2 + 1 ] ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
T_1 V_5 ;
V_5 = V_8 -> V_16 [ 0 ] [ V_24 ] & ~ V_32 ;
if ( V_2 -> V_56 )
V_5 |= V_32 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; ++ V_19 )
F_3 ( V_2 , V_19 , V_24 , V_5 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_5 ;
V_5 = V_42 | V_44 ;
if ( F_32 ( V_52 ) <= 48000 )
V_5 |= V_43 ;
else if ( F_32 ( V_52 ) <= 96000 )
V_5 |= V_57 ;
else
V_5 |= V_58 ;
if ( V_5 != V_8 -> V_18 [ 0 ] ) {
F_4 ( V_2 , V_39 , 0 ) ;
F_4 ( V_2 , V_40 , V_5 ) ;
F_4 ( V_2 , V_41 , V_8 -> V_18 [ 2 ] ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
unsigned int V_5 ;
if ( F_32 ( V_52 ) <= 54000 )
V_5 = V_59 ;
else if ( F_32 ( V_52 ) <= 108000 )
V_5 = V_60 ;
else
V_5 = V_61 ;
F_16 ( V_2 , V_38 ,
V_5 , V_37 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
}
static int F_38 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
static const char * const V_66 [ 2 ] = {
L_5 , L_6
} ;
return F_39 ( V_65 , 1 , 2 , V_66 ) ;
}
static int F_40 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_5 -> V_5 . V_69 . V_70 [ 0 ] =
( V_8 -> V_16 [ 0 ] [ V_24 ] & V_71 ) != 0 ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
int V_72 ;
T_1 V_4 ;
F_42 ( & V_2 -> V_73 ) ;
V_4 = V_8 -> V_16 [ 0 ] [ V_24 ] ;
if ( V_5 -> V_5 . V_69 . V_70 [ 0 ] )
V_4 |= V_71 ;
else
V_4 &= ~ V_71 ;
V_72 = V_4 != V_8 -> V_16 [ 0 ] [ V_24 ] ;
if ( V_72 ) {
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; ++ V_19 )
F_1 ( V_2 , V_19 , V_24 , V_4 ) ;
}
F_43 ( & V_2 -> V_73 ) ;
return V_72 ;
}
static int F_44 ( struct V_62 * V_63 , struct V_64 * V_65 )
{
static const char * const V_66 [ 2 ] = {
L_7 , L_8
} ;
return F_39 ( V_65 , 1 , 2 , V_66 ) ;
}
static int F_45 ( struct V_62 * V_63 , struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_5 -> V_5 . V_69 . V_70 [ 0 ] =
( V_8 -> V_18 [ V_41 ] & V_45 ) != 0 ;
return 0 ;
}
static int F_46 ( struct V_62 * V_63 , struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_4 ;
int V_72 ;
F_42 ( & V_2 -> V_73 ) ;
V_4 = V_8 -> V_18 [ V_41 ] & ~ ( V_45 | V_46 ) ;
if ( V_5 -> V_5 . V_69 . V_70 [ 0 ] )
V_4 |= V_45 | V_46 ;
V_72 = V_4 != V_8 -> V_18 [ V_41 ] ;
if ( V_72 )
F_4 ( V_2 , V_41 , V_4 ) ;
F_43 ( & V_2 -> V_73 ) ;
return V_72 ;
}
static int F_47 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
static const char * const V_66 [ 2 ] = { L_9 , L_10 } ;
return F_39 ( V_65 , 1 , 2 , V_66 ) ;
}
static int F_48 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
static const char * const V_66 [ 2 ] = { L_11 , L_12 } ;
return F_39 ( V_65 , 1 , 2 , V_66 ) ;
}
static int F_49 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
V_5 -> V_5 . V_69 . V_70 [ 0 ] =
! ! ( F_50 ( V_2 , V_38 ) &
V_74 ) ;
return 0 ;
}
static int F_51 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
V_5 -> V_5 . V_69 . V_70 [ 0 ] =
! ! ( F_50 ( V_2 , V_38 ) &
V_50 ) ;
return 0 ;
}
static int F_52 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
T_2 V_75 , V_76 ;
int V_72 ;
F_42 ( & V_2 -> V_73 ) ;
V_75 = F_50 ( V_2 , V_38 ) ;
V_76 = V_75 & ~ V_47 ;
if ( V_5 -> V_5 . V_69 . V_70 [ 0 ] == 0 )
V_76 |= V_48 ;
else
V_76 |= V_74 ;
V_72 = V_76 != V_75 ;
if ( V_72 )
F_53 ( V_2 , V_38 , V_76 ) ;
F_43 ( & V_2 -> V_73 ) ;
return V_72 ;
}
static int F_54 ( struct V_62 * V_63 ,
struct V_67 * V_5 )
{
struct V_1 * V_2 = V_63 -> V_68 ;
T_2 V_75 , V_76 ;
int V_72 ;
F_42 ( & V_2 -> V_73 ) ;
V_75 = F_50 ( V_2 , V_38 ) ;
V_76 = V_75 & ~ V_50 ;
if ( V_5 -> V_5 . V_69 . V_70 [ 0 ] )
V_76 |= V_50 ;
V_72 = V_76 != V_75 ;
if ( V_72 )
F_53 ( V_2 , V_38 , V_76 ) ;
F_43 ( & V_2 -> V_73 ) ;
return V_72 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return F_56 ( V_2 -> V_35 , F_57 ( & V_77 , V_2 ) ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_78 ;
V_78 = F_55 ( V_2 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_56 ( V_2 -> V_35 , F_57 ( & V_79 , V_2 ) ) ;
if ( V_78 < 0 )
return V_78 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_78 ;
V_78 = F_55 ( V_2 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_56 ( V_2 -> V_35 ,
F_57 ( & V_80 , V_2 ) ) ;
if ( V_78 < 0 )
return V_78 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_78 ;
V_78 = F_58 ( V_2 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_56 ( V_2 -> V_35 ,
F_57 ( & V_81 , V_2 ) ) ;
if ( V_78 < 0 )
return V_78 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_78 ;
V_78 = F_55 ( V_2 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_56 ( V_2 -> V_35 ,
F_57 ( & V_81 , V_2 ) ) ;
if ( V_78 < 0 )
return V_78 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_84 , V_19 ;
for ( V_84 = 0 ; V_84 < V_8 -> V_20 ; ++ V_84 ) {
F_63 ( V_83 , L_13 , V_84 + 1 ) ;
for ( V_19 = 0 ; V_19 < 5 ; ++ V_19 )
F_63 ( V_83 , L_14 , V_8 -> V_16 [ V_84 ] [ V_19 ] ) ;
}
F_63 ( V_83 , L_15 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_19 ;
F_63 ( V_83 , L_16 ) ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 )
F_63 ( V_83 , L_17 , V_8 -> V_18 [ V_19 ] ) ;
F_63 ( V_83 , L_15 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
F_62 ( V_2 , V_83 ) ;
F_64 ( V_2 , V_83 ) ;
}
static int T_3 F_66 ( struct V_1 * V_2 ,
const struct V_85 * V_86 )
{
static const char * const V_66 [] = {
[ V_87 ] = L_18 ,
[ V_88 ] = L_19 ,
[ V_89 ] = L_20 ,
[ V_90 ] = L_21 ,
[ V_91 ] = L_22 ,
[ V_92 ] = L_23 ,
[ V_93 ] = L_24 ,
} ;
V_2 -> V_30 = V_94 ;
switch ( V_86 -> V_95 ) {
case V_87 :
case V_88 :
V_2 -> V_30 . V_96 = F_15 ;
V_2 -> V_30 . V_97 = F_59 ;
V_2 -> V_30 . V_98 = F_28 ;
V_2 -> V_30 . V_99 = F_36 ;
V_2 -> V_30 . V_100 = F_62 ;
V_2 -> V_30 . V_101 = V_102 |
V_103 |
V_104 |
V_105 ;
if ( V_86 -> V_95 == V_87 )
V_2 -> V_30 . V_101 |= V_106 ;
break;
case V_89 :
V_2 -> V_30 . V_96 = F_19 ;
V_2 -> V_30 . V_97 = F_60 ;
V_2 -> V_30 . V_107 = F_25 ;
V_2 -> V_30 . V_108 = F_26 ;
V_2 -> V_30 . V_98 = F_29 ;
break;
case V_90 :
V_2 -> V_30 . V_96 = F_20 ;
V_2 -> V_30 . V_97 = F_61 ;
V_2 -> V_30 . V_107 = F_25 ;
V_2 -> V_30 . V_108 = F_26 ;
V_2 -> V_30 . V_98 = F_29 ;
V_2 -> V_30 . V_99 = F_36 ;
V_2 -> V_30 . V_100 = F_62 ;
V_2 -> V_30 . V_101 = V_102 |
V_103 |
V_104 |
V_105 ;
break;
case V_91 :
case V_92 :
case V_109 :
case V_93 :
V_2 -> V_30 . V_110 = L_25 ;
V_2 -> V_30 . V_2 = L_26 ;
if ( V_86 -> V_95 == V_91 )
V_2 -> V_30 . V_96 = F_21 ;
else
V_2 -> V_30 . V_96 = F_22 ;
V_2 -> V_30 . V_98 = F_30 ;
V_2 -> V_30 . V_97 = F_55 ;
V_2 -> V_30 . V_99 = F_37 ;
V_2 -> V_30 . V_100 = F_62 ;
V_2 -> V_30 . V_101 = V_102 |
V_103 ;
if ( V_86 -> V_95 == V_91 ) {
V_2 -> V_30 . V_101 |= V_111 ;
V_2 -> V_30 . V_112 = F_67 ( 256 , 128 , 128 ) ;
}
V_2 -> V_30 . V_31 = 2 ;
V_2 -> V_30 . V_113 = 2 ;
break;
case V_114 :
V_2 -> V_30 = V_115 ;
V_2 -> V_30 . V_110 = L_27 ;
break;
case V_116 :
V_2 -> V_30 = V_115 ;
V_2 -> V_30 . V_110 = L_28 ;
break;
}
if ( V_86 -> V_95 == V_87 ||
V_86 -> V_95 == V_88 ||
V_86 -> V_95 == V_90 ) {
V_2 -> V_30 . V_117 = V_118 ;
V_2 -> V_30 . V_101 |= V_119 | V_120 ;
}
if ( V_86 -> V_95 < F_5 ( V_66 ) && V_66 [ V_86 -> V_95 ] )
V_2 -> V_30 . V_110 = V_66 [ V_86 -> V_95 ] ;
return 0 ;
}
static int T_3 F_68 ( struct V_121 * V_122 ,
const struct V_85 * V_123 )
{
static int V_124 ;
int V_78 ;
if ( V_124 >= V_125 )
return - V_126 ;
if ( ! V_127 [ V_124 ] ) {
++ V_124 ;
return - V_128 ;
}
V_78 = F_69 ( V_122 , V_129 [ V_124 ] , V_86 [ V_124 ] , V_130 ,
V_131 , F_66 ) ;
if ( V_78 >= 0 )
++ V_124 ;
return V_78 ;
}
