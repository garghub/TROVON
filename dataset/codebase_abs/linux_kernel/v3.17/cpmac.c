static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 += 4 ) {
if ( V_3 % 16 == 0 ) {
if ( V_3 )
F_3 ( L_1 ) ;
F_3 ( L_2 , V_2 -> V_7 , V_5 -> V_8 + V_3 ) ;
}
F_3 ( L_3 , F_4 ( V_5 -> V_8 , V_3 ) ) ;
}
F_3 ( L_1 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_3 ;
F_3 ( L_4 , V_2 -> V_7 , V_10 ) ;
for ( V_3 = 0 ; V_3 < sizeof( * V_10 ) / 4 ; V_3 ++ )
F_3 ( L_3 , ( ( V_11 * ) V_10 ) [ V_3 ] ) ;
F_3 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_12 = V_5 -> V_13 ;
do {
F_5 ( V_2 , V_12 ) ;
V_12 = V_12 -> V_14 ;
} while ( V_12 != V_5 -> V_13 );
}
static void F_7 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_3 ;
F_3 ( L_5 , V_2 -> V_7 , V_16 , V_16 -> V_17 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_17 ; V_3 ++ ) {
if ( V_3 % 16 == 0 ) {
if ( V_3 )
F_3 ( L_1 ) ;
F_3 ( L_6 , V_2 -> V_7 , V_16 -> V_18 + V_3 ) ;
}
F_3 ( L_7 , ( ( V_19 * ) V_16 -> V_18 ) [ V_3 ] ) ;
}
F_3 ( L_1 ) ;
}
static int F_8 ( struct V_20 * V_21 , int V_22 , int V_23 )
{
V_11 V_24 ;
while ( F_4 ( V_21 -> V_5 , F_9 ( 0 ) ) & V_25 )
F_10 () ;
F_11 ( V_21 -> V_5 , F_9 ( 0 ) , V_25 | F_12 ( V_23 ) |
F_13 ( V_22 ) ) ;
while ( ( V_24 = F_4 ( V_21 -> V_5 , F_9 ( 0 ) ) ) & V_25 )
F_10 () ;
return F_14 ( V_24 ) ;
}
static int F_15 ( struct V_20 * V_21 , int V_22 ,
int V_23 , T_1 V_24 )
{
while ( F_4 ( V_21 -> V_5 , F_9 ( 0 ) ) & V_25 )
F_10 () ;
F_11 ( V_21 -> V_5 , F_9 ( 0 ) , V_25 | V_26 |
F_12 ( V_23 ) | F_13 ( V_22 ) | F_14 ( V_24 ) ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_27 * V_28 ;
V_28 = F_17 ( & V_21 -> V_2 , L_8 ) ;
if ( F_18 ( V_28 ) ) {
F_19 ( L_9 ) ;
return - 1 ;
}
F_20 ( V_29 ) ;
F_11 ( V_21 -> V_5 , V_30 , V_31 |
F_21 ( F_22 ( V_28 ) / 2200000 - 1 ) ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_19 V_34 ;
V_11 V_35 , V_36 , V_37 [ 2 ] = { 0 , } ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_35 = F_4 ( V_5 -> V_8 , V_38 ) ;
if ( V_2 -> V_39 & V_40 ) {
F_11 ( V_5 -> V_8 , V_38 , ( V_35 & ~ F_24 ( 0 ) ) |
V_41 ) ;
} else {
F_11 ( V_5 -> V_8 , V_38 , V_35 & ~ V_41 ) ;
if ( V_2 -> V_39 & V_42 ) {
F_11 ( V_5 -> V_8 , V_43 , 0xffffffff ) ;
F_11 ( V_5 -> V_8 , V_44 , 0xffffffff ) ;
} else {
F_25 (ha, dev) {
V_36 = 0 ;
V_34 = V_33 -> V_45 [ 0 ] ;
V_36 ^= ( V_34 >> 2 ) ^ ( V_34 << 4 ) ;
V_34 = V_33 -> V_45 [ 1 ] ;
V_36 ^= ( V_34 >> 4 ) ^ ( V_34 << 2 ) ;
V_34 = V_33 -> V_45 [ 2 ] ;
V_36 ^= ( V_34 >> 6 ) ^ V_34 ;
V_34 = V_33 -> V_45 [ 3 ] ;
V_36 ^= ( V_34 >> 2 ) ^ ( V_34 << 4 ) ;
V_34 = V_33 -> V_45 [ 4 ] ;
V_36 ^= ( V_34 >> 4 ) ^ ( V_34 << 2 ) ;
V_34 = V_33 -> V_45 [ 5 ] ;
V_36 ^= ( V_34 >> 6 ) ^ V_34 ;
V_36 &= 0x3f ;
V_37 [ V_36 / 32 ] |= 1 << ( V_36 % 32 ) ;
}
F_11 ( V_5 -> V_8 , V_43 , V_37 [ 0 ] ) ;
F_11 ( V_5 -> V_8 , V_44 , V_37 [ 1 ] ) ;
}
}
}
static struct V_15 * F_26 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
struct V_15 * V_16 , * V_46 = NULL ;
if ( F_27 ( F_28 ( V_5 ) ) )
F_5 ( V_5 -> V_2 , V_10 ) ;
F_11 ( V_5 -> V_8 , F_29 ( 0 ) , ( V_11 ) V_10 -> V_47 ) ;
if ( F_27 ( ! V_10 -> V_48 ) ) {
if ( F_30 ( V_5 ) && F_31 () )
F_32 ( V_5 -> V_2 , L_10 ) ;
return NULL ;
}
V_16 = F_33 ( V_5 -> V_2 , V_49 ) ;
if ( F_34 ( V_16 ) ) {
F_35 ( V_10 -> V_16 , V_10 -> V_48 ) ;
V_10 -> V_16 -> V_50 = F_36 ( V_10 -> V_16 , V_5 -> V_2 ) ;
F_37 ( V_10 -> V_16 ) ;
V_5 -> V_2 -> V_51 . V_52 ++ ;
V_5 -> V_2 -> V_51 . V_53 += V_10 -> V_48 ;
V_46 = V_10 -> V_16 ;
F_38 ( & V_5 -> V_2 -> V_2 , V_10 -> V_54 ,
V_49 , V_55 ) ;
V_10 -> V_16 = V_16 ;
V_10 -> V_54 = F_39 ( & V_5 -> V_2 -> V_2 , V_16 -> V_18 ,
V_49 ,
V_55 ) ;
V_10 -> V_56 = ( V_11 ) V_10 -> V_54 ;
if ( F_27 ( F_40 ( V_5 ) ) ) {
F_41 ( V_5 -> V_2 , L_11 ) ;
F_7 ( V_5 -> V_2 , V_46 ) ;
}
} else {
if ( F_30 ( V_5 ) && F_31 () )
F_32 ( V_5 -> V_2 ,
L_12 ) ;
V_5 -> V_2 -> V_51 . V_57 ++ ;
}
V_10 -> V_58 = V_49 ;
V_10 -> V_59 = V_60 ;
return V_46 ;
}
static int F_42 ( struct V_61 * V_62 , int V_63 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 , * V_64 ;
struct V_4 * V_5 = F_43 ( V_62 , struct V_4 , V_62 ) ;
int V_65 = 0 , V_66 = 0 ;
F_44 ( & V_5 -> V_67 ) ;
if ( F_27 ( ! V_5 -> V_13 ) ) {
if ( F_30 ( V_5 ) && F_31 () )
F_32 ( V_5 -> V_2 , L_13 ) ;
F_45 ( & V_5 -> V_67 ) ;
F_46 ( V_62 ) ;
return 0 ;
}
V_10 = V_5 -> V_13 ;
V_64 = NULL ;
while ( ( ( V_10 -> V_59 & V_60 ) == 0 ) && ( V_65 < V_63 ) ) {
V_66 ++ ;
if ( ( V_10 -> V_59 & V_68 ) != 0 ) {
if ( F_27 ( V_64 ) ) {
if ( F_30 ( V_5 ) )
F_47 ( V_5 -> V_2 , L_14
L_15 ,
V_64 , V_10 ) ;
goto V_69;
}
V_64 = V_10 -> V_14 ;
}
V_16 = F_26 ( V_5 , V_10 ) ;
if ( F_34 ( V_16 ) ) {
F_48 ( V_16 ) ;
V_65 ++ ;
}
V_10 = V_10 -> V_14 ;
}
if ( V_10 != V_5 -> V_13 ) {
V_10 -> V_70 -> V_71 = ( V_11 ) 0 ;
V_5 -> V_13 -> V_70 -> V_71 = V_5 -> V_13 -> V_47 ;
}
if ( ! V_64 &&
( V_5 -> V_13 -> V_70 -> V_59 & ( V_60 | V_68 ) )
== V_68 &&
( V_5 -> V_13 -> V_59 & V_60 ) != 0 ) {
V_5 -> V_13 -> V_70 -> V_59 &= ~ V_68 ;
V_64 = V_5 -> V_13 ;
}
if ( V_64 ) {
V_5 -> V_2 -> V_51 . V_72 ++ ;
V_5 -> V_2 -> V_51 . V_73 ++ ;
if ( F_30 ( V_5 ) && F_31 () )
F_32 ( V_5 -> V_2 , L_16 ) ;
if ( F_27 ( ( V_64 -> V_59 & V_60 ) == 0 ) ) {
if ( F_49 ( V_5 ) )
F_47 ( V_5 -> V_2 , L_17
L_18
L_19 , V_64 ) ;
goto V_69;
}
F_11 ( V_5 -> V_8 , F_50 ( 0 ) , V_64 -> V_47 ) ;
}
V_5 -> V_13 = V_10 ;
F_45 ( & V_5 -> V_67 ) ;
if ( F_27 ( F_51 ( V_5 ) ) )
F_41 ( V_5 -> V_2 , L_20 , V_65 ) ;
if ( V_66 == 0 ) {
F_46 ( V_62 ) ;
F_11 ( V_5 -> V_8 , V_74 , 1 ) ;
return 0 ;
}
return 1 ;
V_69:
if ( F_49 ( V_5 ) ) {
F_47 ( V_5 -> V_2 , L_21
L_22 ) ;
F_6 ( V_5 -> V_2 ) ;
F_41 ( V_5 -> V_2 , L_23 ,
F_4 ( V_5 -> V_8 , F_50 ( 0 ) ) ,
F_4 ( V_5 -> V_8 , F_29 ( 0 ) ) ) ;
}
F_45 ( & V_5 -> V_67 ) ;
F_46 ( V_62 ) ;
F_52 ( V_5 -> V_2 ) ;
F_53 ( & V_5 -> V_62 ) ;
F_54 ( & V_5 -> V_75 ) ;
F_55 ( V_5 -> V_2 ) ;
if ( ! F_56 ( & V_5 -> V_76 ) )
F_57 ( & V_5 -> V_75 ) ;
return 0 ;
}
static int F_58 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
int V_77 , V_17 ;
struct V_9 * V_10 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_27 ( F_59 ( & V_5 -> V_75 ) ) )
return V_78 ;
if ( F_27 ( F_60 ( V_16 , V_79 ) ) )
return V_80 ;
V_17 = F_61 ( V_16 -> V_17 , V_79 ) ;
V_77 = F_62 ( V_16 ) ;
F_63 ( V_2 , V_77 ) ;
V_10 = & V_5 -> V_81 [ V_77 ] ;
if ( F_27 ( V_10 -> V_59 & V_60 ) ) {
if ( F_64 ( V_5 ) && F_31 () )
F_32 ( V_2 , L_24 ) ;
return V_78 ;
}
F_44 ( & V_5 -> V_82 ) ;
F_45 ( & V_5 -> V_82 ) ;
V_10 -> V_59 = V_83 | V_84 | V_60 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_54 = F_39 ( & V_2 -> V_2 , V_16 -> V_18 , V_17 ,
V_85 ) ;
V_10 -> V_56 = ( V_11 ) V_10 -> V_54 ;
V_10 -> V_48 = V_17 ;
V_10 -> V_58 = V_17 ;
if ( F_27 ( F_65 ( V_5 ) ) )
F_41 ( V_2 , L_25 , V_16 , V_16 -> V_17 ) ;
if ( F_27 ( F_28 ( V_5 ) ) )
F_5 ( V_2 , V_10 ) ;
if ( F_27 ( F_40 ( V_5 ) ) )
F_7 ( V_2 , V_16 ) ;
F_11 ( V_5 -> V_8 , F_66 ( V_77 ) , ( V_11 ) V_10 -> V_47 ) ;
return V_80 ;
}
static void F_67 ( struct V_1 * V_2 , int V_77 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_10 = & V_5 -> V_81 [ V_77 ] ;
F_11 ( V_5 -> V_8 , F_68 ( V_77 ) , ( V_11 ) V_10 -> V_47 ) ;
if ( F_34 ( V_10 -> V_16 ) ) {
F_44 ( & V_5 -> V_82 ) ;
V_2 -> V_51 . V_86 ++ ;
V_2 -> V_51 . V_87 += V_10 -> V_16 -> V_17 ;
F_45 ( & V_5 -> V_82 ) ;
F_38 ( & V_2 -> V_2 , V_10 -> V_54 , V_10 -> V_16 -> V_17 ,
V_85 ) ;
if ( F_27 ( F_69 ( V_5 ) ) )
F_41 ( V_2 , L_26 ,
V_10 -> V_16 , V_10 -> V_16 -> V_17 ) ;
F_70 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
if ( F_71 ( V_2 , V_77 ) )
F_72 ( V_2 , V_77 ) ;
} else {
if ( F_64 ( V_5 ) && F_31 () )
F_32 ( V_2 , L_27 ) ;
if ( F_71 ( V_2 , V_77 ) )
F_72 ( V_2 , V_77 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_88 * V_89 = F_73 ( & V_5 -> V_90 -> V_2 ) ;
F_20 ( V_89 -> V_91 ) ;
F_11 ( V_5 -> V_8 , V_92 ,
F_4 ( V_5 -> V_8 , V_92 ) & ~ 1 ) ;
F_11 ( V_5 -> V_8 , V_93 ,
F_4 ( V_5 -> V_8 , V_93 ) & ~ 1 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_11 ( V_5 -> V_8 , F_66 ( V_3 ) , 0 ) ;
F_11 ( V_5 -> V_8 , F_50 ( V_3 ) , 0 ) ;
}
F_11 ( V_5 -> V_8 , V_94 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_95 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_96 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_97 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_98 ,
F_4 ( V_5 -> V_8 , V_98 ) & ~ V_99 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_88 * V_89 = F_73 ( & V_5 -> V_90 -> V_2 ) ;
F_20 ( V_89 -> V_91 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_11 ( V_5 -> V_8 , F_66 ( V_3 ) , 0 ) ;
F_11 ( V_5 -> V_8 , F_50 ( V_3 ) , 0 ) ;
}
F_11 ( V_5 -> V_8 , F_50 ( 0 ) , V_5 -> V_13 -> V_47 ) ;
F_11 ( V_5 -> V_8 , V_38 , V_100 | V_101 |
V_102 ) ;
F_11 ( V_5 -> V_8 , V_103 , 0 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_11 ( V_5 -> V_8 , F_75 ( V_3 ) , V_2 -> V_104 [ 5 ] ) ;
F_11 ( V_5 -> V_8 , V_105 , V_2 -> V_104 [ 4 ] ) ;
F_11 ( V_5 -> V_8 , V_106 , V_2 -> V_104 [ 0 ] |
( V_2 -> V_104 [ 1 ] << 8 ) | ( V_2 -> V_104 [ 2 ] << 16 ) |
( V_2 -> V_104 [ 3 ] << 24 ) ) ;
F_11 ( V_5 -> V_8 , V_107 , V_49 ) ;
F_11 ( V_5 -> V_8 , V_94 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_95 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_96 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_97 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_108 , 1 ) ;
F_11 ( V_5 -> V_8 , V_74 , 1 ) ;
F_11 ( V_5 -> V_8 , V_109 , 0xff ) ;
F_11 ( V_5 -> V_8 , V_110 , 3 ) ;
F_11 ( V_5 -> V_8 , V_92 ,
F_4 ( V_5 -> V_8 , V_92 ) | 1 ) ;
F_11 ( V_5 -> V_8 , V_93 ,
F_4 ( V_5 -> V_8 , V_93 ) | 1 ) ;
F_11 ( V_5 -> V_8 , V_98 ,
F_4 ( V_5 -> V_8 , V_98 ) | V_99 |
V_111 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
int V_3 ;
if ( F_27 ( ! V_5 -> V_13 ) )
return;
V_10 = V_5 -> V_13 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_112 ; V_3 ++ ) {
if ( ( V_10 -> V_59 & V_60 ) == 0 ) {
if ( F_30 ( V_5 ) && F_31 () )
F_32 ( V_2 , L_28 ) ;
if ( F_27 ( F_28 ( V_5 ) ) )
F_5 ( V_2 , V_10 ) ;
V_10 -> V_59 = V_60 ;
V_2 -> V_51 . V_57 ++ ;
}
V_10 -> V_71 = V_10 -> V_14 -> V_47 ;
V_10 = V_10 -> V_14 ;
}
V_5 -> V_13 -> V_70 -> V_71 = 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
if ( F_27 ( ! V_5 -> V_81 ) )
return;
for ( V_3 = 0 ; V_3 < V_113 ; V_3 ++ ) {
V_5 -> V_81 [ V_3 ] . V_59 = 0 ;
if ( V_5 -> V_81 [ V_3 ] . V_16 ) {
F_78 ( V_5 -> V_81 [ V_3 ] . V_16 ) ;
V_5 -> V_81 [ V_3 ] . V_16 = NULL ;
}
}
}
static void F_79 ( struct V_114 * V_115 )
{
struct V_4 * V_5 =
F_43 ( V_115 , struct V_4 , V_76 ) ;
F_44 ( & V_5 -> V_67 ) ;
F_76 ( V_5 -> V_2 ) ;
F_45 ( & V_5 -> V_67 ) ;
F_77 ( V_5 -> V_2 ) ;
F_74 ( V_5 -> V_2 ) ;
F_80 () ;
F_57 ( & V_5 -> V_75 ) ;
F_81 ( V_5 -> V_2 ) ;
F_11 ( V_5 -> V_8 , V_110 , 3 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_11 V_116 = F_4 ( V_5 -> V_8 , V_117 ) ;
int V_118 = ( V_116 >> 8 ) & 7 ;
int V_119 = ( V_116 >> 12 ) & 15 ;
int V_120 = ( V_116 >> 16 ) & 7 ;
int V_121 = ( V_116 >> 20 ) & 15 ;
if ( V_119 || V_121 ) {
if ( F_49 ( V_5 ) && F_31 () ) {
if ( V_119 )
F_32 ( V_2 , L_29
L_30 ,
V_119 , V_118 , V_116 ) ;
if ( V_121 )
F_32 ( V_2 , L_31
L_30 ,
V_121 , V_120 , V_116 ) ;
}
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( F_56 ( & V_5 -> V_76 ) )
F_54 ( & V_5 -> V_75 ) ;
if ( F_27 ( F_28 ( V_5 ) ) )
F_1 ( V_2 ) ;
}
F_11 ( V_5 -> V_8 , V_97 , 0xff ) ;
}
static T_2 F_83 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_4 * V_5 ;
int V_77 ;
V_11 V_124 ;
V_5 = F_2 ( V_2 ) ;
V_124 = F_4 ( V_5 -> V_8 , V_125 ) ;
if ( F_27 ( F_84 ( V_5 ) ) )
F_41 ( V_2 , L_32 , V_124 ) ;
if ( V_124 & V_126 )
F_67 ( V_2 , ( V_124 & 7 ) ) ;
if ( V_124 & V_127 ) {
V_77 = ( V_124 >> 8 ) & 7 ;
if ( F_85 ( & V_5 -> V_62 ) ) {
F_11 ( V_5 -> V_8 , V_95 , 1 << V_77 ) ;
F_86 ( & V_5 -> V_62 ) ;
}
}
F_11 ( V_5 -> V_8 , V_128 , 0 ) ;
if ( F_27 ( V_124 & ( V_129 | V_130 ) ) )
F_82 ( V_2 ) ;
return V_131 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_44 ( & V_5 -> V_82 ) ;
V_2 -> V_51 . V_132 ++ ;
F_45 ( & V_5 -> V_82 ) ;
if ( F_64 ( V_5 ) && F_31 () )
F_32 ( V_2 , L_33 ) ;
F_54 ( & V_5 -> V_75 ) ;
F_80 () ;
F_77 ( V_2 ) ;
F_80 () ;
F_57 ( & V_5 -> V_75 ) ;
F_81 ( V_5 -> V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_133 * V_134 , int V_135 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! ( F_89 ( V_2 ) ) )
return - V_136 ;
if ( ! V_5 -> V_137 )
return - V_136 ;
return F_90 ( V_5 -> V_137 , V_134 , V_135 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_138 * V_135 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_137 )
return F_92 ( V_5 -> V_137 , V_135 ) ;
return - V_136 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_138 * V_135 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! F_94 ( V_139 ) )
return - V_140 ;
if ( V_5 -> V_137 )
return F_95 ( V_5 -> V_137 , V_135 ) ;
return - V_136 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_142 -> V_143 = 1024 ;
V_142 -> V_144 = 1 ;
V_142 -> V_145 = 1 ;
V_142 -> V_146 = 1 ;
V_142 -> V_147 = V_5 -> V_112 ;
V_142 -> V_148 = 1 ;
V_142 -> V_149 = 1 ;
V_142 -> V_150 = 1 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_89 ( V_2 ) )
return - V_151 ;
V_5 -> V_112 = V_142 -> V_147 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
F_99 ( V_153 -> V_154 , L_8 , sizeof( V_153 -> V_154 ) ) ;
F_99 ( V_153 -> V_155 , V_156 , sizeof( V_153 -> V_155 ) ) ;
snprintf ( V_153 -> V_157 , sizeof( V_153 -> V_157 ) , L_34 , L_8 ) ;
V_153 -> V_158 = 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_159 = 0 ;
F_44 ( & V_5 -> V_82 ) ;
if ( V_5 -> V_137 -> V_160 ) {
F_101 ( V_2 ) ;
if ( V_5 -> V_137 -> V_161 != V_5 -> V_162 ) {
V_159 = 1 ;
V_5 -> V_162 = V_5 -> V_137 -> V_161 ;
}
if ( V_5 -> V_137 -> V_163 != V_5 -> V_164 ) {
V_159 = 1 ;
V_5 -> V_164 = V_5 -> V_137 -> V_163 ;
}
if ( ! V_5 -> V_165 ) {
V_159 = 1 ;
V_5 -> V_165 = 1 ;
}
} else if ( V_5 -> V_165 ) {
V_159 = 1 ;
V_5 -> V_165 = 0 ;
V_5 -> V_164 = 0 ;
V_5 -> V_162 = - 1 ;
}
if ( V_159 && F_102 ( V_5 ) && F_31 () )
F_103 ( V_5 -> V_137 ) ;
F_45 ( & V_5 -> V_82 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_3 , V_166 , V_167 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_168 * V_169 ;
struct V_9 * V_10 ;
struct V_15 * V_16 ;
V_169 = F_105 ( V_5 -> V_90 , V_170 , L_35 ) ;
if ( ! F_106 ( V_169 -> V_171 , F_107 ( V_169 ) , V_2 -> V_7 ) ) {
if ( F_49 ( V_5 ) )
F_47 ( V_2 , L_36 ) ;
V_167 = - V_172 ;
goto V_173;
}
V_5 -> V_8 = F_108 ( V_169 -> V_171 , F_107 ( V_169 ) ) ;
if ( ! V_5 -> V_8 ) {
if ( F_49 ( V_5 ) )
F_47 ( V_2 , L_37 ) ;
V_167 = - V_172 ;
goto V_174;
}
V_166 = V_5 -> V_112 + V_113 ;
V_5 -> V_81 = F_109 ( & V_2 -> V_2 ,
sizeof( struct V_9 ) * V_166 ,
& V_5 -> V_175 ,
V_176 ) ;
if ( ! V_5 -> V_81 ) {
V_167 = - V_177 ;
goto V_178;
}
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ )
V_5 -> V_81 [ V_3 ] . V_47 = V_5 -> V_175 + sizeof( * V_10 ) * V_3 ;
V_5 -> V_13 = & V_5 -> V_81 [ V_113 ] ;
for ( V_3 = 0 , V_10 = V_5 -> V_13 ; V_3 < V_5 -> V_112 ; V_3 ++ , V_10 ++ ) {
V_16 = F_33 ( V_2 , V_49 ) ;
if ( F_27 ( ! V_16 ) ) {
V_167 = - V_177 ;
goto V_179;
}
V_10 -> V_16 = V_16 ;
V_10 -> V_54 = F_39 ( & V_2 -> V_2 , V_16 -> V_18 ,
V_49 ,
V_55 ) ;
V_10 -> V_56 = ( V_11 ) V_10 -> V_54 ;
V_10 -> V_58 = V_49 ;
V_10 -> V_59 = V_60 ;
V_10 -> V_14 = & V_5 -> V_13 [ ( V_3 + 1 ) % V_5 -> V_112 ] ;
V_10 -> V_14 -> V_70 = V_10 ;
V_10 -> V_71 = ( V_11 ) V_10 -> V_14 -> V_47 ;
}
V_5 -> V_13 -> V_70 -> V_71 = ( V_11 ) 0 ;
V_167 = F_110 ( V_2 -> V_122 , F_83 , V_180 , V_2 -> V_7 , V_2 ) ;
if ( V_167 ) {
if ( F_49 ( V_5 ) )
F_47 ( V_2 , L_38 ) ;
goto V_181;
}
F_111 ( & V_5 -> V_75 , 0 ) ;
F_112 ( & V_5 -> V_76 , F_79 ) ;
F_74 ( V_2 ) ;
F_113 ( & V_5 -> V_62 ) ;
V_5 -> V_137 -> V_182 = V_183 ;
F_114 ( V_5 -> V_137 ) ;
return 0 ;
V_181:
V_179:
for ( V_3 = 0 ; V_3 < V_5 -> V_112 ; V_3 ++ ) {
if ( V_5 -> V_13 [ V_3 ] . V_16 ) {
F_38 ( & V_2 -> V_2 ,
V_5 -> V_13 [ V_3 ] . V_54 ,
V_49 ,
V_55 ) ;
F_115 ( V_5 -> V_13 [ V_3 ] . V_16 ) ;
}
}
V_178:
F_116 ( V_5 -> V_81 ) ;
F_117 ( V_5 -> V_8 ) ;
V_174:
F_118 ( V_169 -> V_171 , F_107 ( V_169 ) ) ;
V_173:
return V_167 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_168 * V_169 ;
F_52 ( V_2 ) ;
F_120 ( & V_5 -> V_76 ) ;
F_53 ( & V_5 -> V_62 ) ;
F_121 ( V_5 -> V_137 ) ;
F_55 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_11 ( V_5 -> V_8 , F_66 ( V_3 ) , 0 ) ;
F_11 ( V_5 -> V_8 , F_50 ( 0 ) , 0 ) ;
F_11 ( V_5 -> V_8 , V_38 , 0 ) ;
F_122 ( V_2 -> V_122 , V_2 ) ;
F_117 ( V_5 -> V_8 ) ;
V_169 = F_105 ( V_5 -> V_90 , V_170 , L_35 ) ;
F_118 ( V_169 -> V_171 , F_107 ( V_169 ) ) ;
V_5 -> V_13 = & V_5 -> V_81 [ V_113 ] ;
for ( V_3 = 0 ; V_3 < V_5 -> V_112 ; V_3 ++ ) {
if ( V_5 -> V_13 [ V_3 ] . V_16 ) {
F_38 ( & V_2 -> V_2 ,
V_5 -> V_13 [ V_3 ] . V_54 ,
V_49 ,
V_55 ) ;
F_115 ( V_5 -> V_13 [ V_3 ] . V_16 ) ;
}
}
F_123 ( & V_2 -> V_2 , sizeof( struct V_9 ) *
( V_113 + V_5 -> V_112 ) ,
V_5 -> V_81 , V_5 -> V_175 ) ;
return 0 ;
}
static int F_124 ( struct V_184 * V_90 )
{
int V_185 , V_22 ;
char V_186 [ V_187 ] ;
struct V_168 * V_169 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_88 * V_89 ;
V_89 = F_73 ( & V_90 -> V_2 ) ;
if ( V_188 || V_189 ) {
strncpy ( V_186 , L_39 , V_187 ) ;
V_22 = V_90 -> V_190 ;
} else {
for ( V_22 = 0 ; V_22 < V_191 ; V_22 ++ ) {
if ( ! ( V_89 -> V_192 & ( 1 << V_22 ) ) )
continue;
if ( ! V_193 -> V_194 [ V_22 ] )
continue;
strncpy ( V_186 , V_193 -> V_190 , V_187 ) ;
break;
}
}
if ( V_22 == V_191 ) {
F_125 ( & V_90 -> V_2 , L_40
L_41 ) ;
strncpy ( V_186 , L_39 , V_187 ) ;
V_22 = V_90 -> V_190 ;
}
V_186 [ sizeof( V_186 ) - 1 ] = '\0' ;
V_2 = F_126 ( sizeof( * V_5 ) , V_113 ) ;
if ( ! V_2 )
return - V_177 ;
F_127 ( V_90 , V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_90 = V_90 ;
V_169 = F_105 ( V_90 , V_170 , L_35 ) ;
if ( ! V_169 ) {
V_185 = - V_195 ;
goto V_196;
}
V_2 -> V_122 = F_128 ( V_90 , L_42 ) ;
V_2 -> V_197 = & V_198 ;
V_2 -> V_199 = & V_200 ;
F_129 ( V_2 , & V_5 -> V_62 , F_42 , 64 ) ;
F_130 ( & V_5 -> V_82 ) ;
F_130 ( & V_5 -> V_67 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_112 = 64 ;
V_5 -> V_201 = F_131 ( V_202 , 0xff ) ;
memcpy ( V_2 -> V_104 , V_89 -> V_104 , sizeof( V_89 -> V_104 ) ) ;
snprintf ( V_5 -> V_203 , V_187 , V_204 ,
V_186 , V_22 ) ;
V_5 -> V_137 = F_132 ( V_2 , V_5 -> V_203 , F_100 ,
V_205 ) ;
if ( F_18 ( V_5 -> V_137 ) ) {
if ( F_49 ( V_5 ) )
F_125 ( & V_90 -> V_2 , L_43 ) ;
V_185 = F_133 ( V_5 -> V_137 ) ;
goto V_196;
}
V_185 = F_134 ( V_2 ) ;
if ( V_185 ) {
F_125 ( & V_90 -> V_2 , L_44 ) ;
goto V_206;
}
if ( F_135 ( V_5 ) ) {
F_136 ( & V_90 -> V_2 , L_45
L_46 , ( void * ) V_169 -> V_171 , V_2 -> V_122 ,
V_5 -> V_203 , V_2 -> V_104 ) ;
}
return 0 ;
V_206:
F_137 ( V_2 ) ;
V_196:
return V_185 ;
}
static int F_138 ( struct V_184 * V_90 )
{
struct V_1 * V_2 = F_139 ( V_90 ) ;
F_140 ( V_2 ) ;
F_137 ( V_2 ) ;
return 0 ;
}
int F_141 ( void )
{
V_11 V_207 ;
int V_3 , V_167 ;
V_193 = F_142 () ;
if ( V_193 == NULL )
return - V_177 ;
V_193 -> V_7 = L_47 ;
V_193 -> V_208 = F_8 ;
V_193 -> V_209 = F_15 ;
V_193 -> V_210 = F_16 ;
V_193 -> V_122 = V_211 ;
V_193 -> V_5 = F_108 ( V_212 , 256 ) ;
if ( ! V_193 -> V_5 ) {
F_19 ( L_48 ) ;
V_167 = - V_172 ;
goto V_178;
}
#warning FIXME: unhardcode gpio&reset bits
F_143 ( 26 ) ;
F_143 ( 27 ) ;
F_20 ( V_213 ) ;
F_20 ( V_214 ) ;
F_20 ( V_215 ) ;
V_193 -> V_210 ( V_193 ) ;
for ( V_3 = 0 ; V_3 < 300 ; V_3 ++ ) {
V_207 = F_4 ( V_193 -> V_5 , V_216 ) ;
if ( V_207 )
break;
else
F_144 ( 10 ) ;
}
V_207 &= 0x7fffffff ;
if ( V_207 & ( V_207 - 1 ) ) {
V_188 = 1 ;
V_207 = 0 ;
}
V_193 -> V_192 = ~ ( V_207 | 0x80000000 ) ;
snprintf ( V_193 -> V_190 , V_187 , L_49 ) ;
V_167 = F_145 ( V_193 ) ;
if ( V_167 )
goto V_217;
V_167 = F_146 ( & V_218 ) ;
if ( V_167 )
goto V_219;
return 0 ;
V_219:
F_147 ( V_193 ) ;
V_217:
F_117 ( V_193 -> V_5 ) ;
V_178:
F_148 ( V_193 ) ;
return V_167 ;
}
void F_149 ( void )
{
F_150 ( & V_218 ) ;
F_147 ( V_193 ) ;
F_117 ( V_193 -> V_5 ) ;
F_148 ( V_193 ) ;
}
