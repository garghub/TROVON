int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
int V_5 = 0 ;
if ( V_4 -> V_6 & ( 8 | V_7 ) )
V_5 += 0x68 ;
if ( V_4 -> V_6 & ( 8 | V_8 ) )
V_5 += 0x2000 ;
return V_5 ;
}
static int F_3 ( struct V_9 * V_10 , bool V_11 [ 2 ] )
{
struct V_12 * V_13 = F_4 ( V_10 ) ;
struct V_14 * V_15 = V_14 ( V_13 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
bool V_17 , V_18 , V_19 ;
int V_20 = 0 ;
if ( ! F_5 ( V_15 , 10000000 ,
V_21 ,
0x00000001 , 0x00000000 ) )
return - V_22 ;
if ( ! F_5 ( V_15 , 10000000 ,
V_21 ,
0x00000001 , 0x00000001 ) )
return - V_22 ;
if ( ! F_5 ( V_15 , 10000000 ,
V_21 ,
0x00000001 , 0x00000000 ) )
return - V_22 ;
F_6 ( 100 ) ;
V_17 = F_7 ( V_13 , V_23 ) & 0x10 ;
do {
F_6 ( 100 ) ;
V_18 = F_7 ( V_13 , V_23 ) & 0x10 ;
if ( V_17 != V_18 ) {
V_19 =
F_7 ( V_13 , V_23 ) & 0x10 ;
if ( V_18 == V_19 ) {
V_17 = V_18 ;
V_18 = ! V_17 ;
}
}
} while ( ( V_17 != V_18 ) && ++ V_20 < V_24 );
if ( V_20 == V_24 )
V_11 [ V_16 ] = false ;
else
V_11 [ V_16 ] = V_17 ;
}
return 0 ;
}
static enum V_25 F_8 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_12 * V_13 = F_4 ( V_10 ) ;
struct V_28 * V_29 = V_28 ( V_10 ) ;
T_1 V_30 , V_31 , V_32 , V_33 ;
T_1 V_34 [ 3 ] , V_35 ;
T_2 V_36 , V_37 ;
int V_16 ;
T_1 V_38 ;
bool V_11 = true ;
if ( F_9 ( V_10 ) )
F_10 ( V_10 , 0 ) ;
V_33 = F_11 ( V_10 , 0 , V_39 ) ;
F_12 ( V_10 , 0 , V_39 , V_33 | 0x80 ) ;
V_30 = F_13 ( V_10 , 0 , V_40 ) ;
F_14 ( V_10 , 0 , V_40 , V_30 & ~ 0x20 ) ;
V_36 = F_15 ( V_10 , 0 , V_41 ) ;
F_16 ( V_10 , 0 , V_41 ,
V_36 & ~ V_42 ) ;
F_17 ( 10 ) ;
V_31 = F_11 ( V_10 , 0 , V_43 ) ;
F_12 ( V_10 , 0 , V_43 ,
V_31 & ~ ( 0x80 | F_18 ( V_44 ) ) ) ;
V_32 = F_11 ( V_10 , 0 , V_45 ) ;
F_12 ( V_10 , 0 , V_45 , V_32 & ~ 0xc0 ) ;
F_19 ( V_13 , V_46 , 0x0 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
V_34 [ V_16 ] = F_7 ( V_13 , V_47 ) ;
V_35 = F_7 ( V_13 , V_48 ) ;
F_19 ( V_13 , V_48 , 0 ) ;
V_37 = F_15 ( V_10 , 0 , V_49 ) ;
F_16 ( V_10 , 0 , V_49 ,
( V_37 & ~ ( V_50 |
V_51 ) ) |
V_52 ) ;
V_38 = 8 ;
do {
bool V_53 [ 2 ] ;
F_19 ( V_13 , V_54 , 0 ) ;
F_19 ( V_13 , V_47 , 0 ) ;
F_19 ( V_13 , V_47 , 0 ) ;
F_19 ( V_13 , V_47 , V_38 ) ;
V_16 = 0 ;
do {
if ( F_3 ( V_10 , V_53 ) )
goto V_55;
} while ( ( V_53 [ 0 ] != V_53 [ 1 ] ) &&
++ V_16 < V_56 );
if ( V_16 == V_56 )
V_11 = false ;
else
V_11 = V_53 [ 0 ] ;
} while ( ++ V_38 < 0x18 && V_11 );
V_55:
F_19 ( V_13 , V_48 , V_35 ) ;
F_16 ( V_10 , 0 , V_49 , V_37 ) ;
F_19 ( V_13 , V_54 , 0 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_19 ( V_13 , V_47 , V_34 [ V_16 ] ) ;
F_16 ( V_10 , 0 , V_41 , V_36 ) ;
F_12 ( V_10 , 0 , V_43 , V_31 ) ;
F_12 ( V_10 , 0 , V_45 , V_32 ) ;
F_14 ( V_10 , 0 , V_40 , V_30 ) ;
F_12 ( V_10 , 0 , V_39 , V_33 ) ;
if ( V_38 == 0x18 ) {
F_20 ( V_29 , L_1 ) ;
return V_57 ;
}
return V_58 ;
}
T_2 F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_28 * V_29 = V_28 ( V_10 ) ;
struct V_12 * V_13 = F_4 ( V_10 ) ;
struct V_59 * V_60 = V_59 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
T_2 V_61 , V_62 , V_63 = F_1 ( V_2 ) ;
T_2 V_64 = 0 , V_65 = 0 , V_66 ,
V_36 , V_67 = 0 , V_68 = 0 , V_69 , V_70 ;
int V_71 ;
#define F_22 ( T_3 , T_4 , T_5 ) (r << 0 | g << 10 | b << 20)
if ( V_4 -> type == V_72 ) {
V_62 = F_22 ( 0xa0 , 0xa0 , 0xa0 ) ;
if ( V_29 -> V_73 . V_74 )
V_62 = V_29 -> V_73 . V_74 ;
} else {
V_62 = F_22 ( 0x140 , 0x140 , 0x140 ) ;
if ( V_29 -> V_73 . V_75 )
V_62 = V_29 -> V_73 . V_75 ;
}
V_36 = F_15 ( V_10 , 0 , V_41 + V_63 ) ;
F_16 ( V_10 , 0 , V_41 + V_63 ,
V_36 & ~ V_42 ) ;
V_64 = F_23 ( V_13 , V_76 ) ;
F_24 ( V_13 , V_76 , V_64 & 0xd7ffffff ) ;
if ( V_63 == 0x68 ) {
V_65 = F_23 ( V_13 , V_77 ) ;
F_24 ( V_13 , V_77 , V_65 & 0xffffffcf ) ;
}
if ( V_60 ) {
V_68 = V_60 -> V_78 ( V_60 , 0 , V_79 , 0xff ) ;
V_67 = V_60 -> V_78 ( V_60 , 0 , V_80 , 0xff ) ;
V_60 -> V_81 ( V_60 , 0 , V_79 , 0xff , V_4 -> type == V_72 ) ;
V_60 -> V_81 ( V_60 , 0 , V_80 , 0xff , V_4 -> type == V_72 ) ;
}
F_17 ( 4 ) ;
V_66 = F_15 ( V_10 , 0 , V_82 + V_63 ) ;
V_71 = ( V_66 & 0x100 ) >> 8 ;
if ( ! ( F_11 ( V_10 , V_71 , V_45 ) & 0xC0 ) )
V_71 ^= 1 ;
V_70 = ( V_66 & 0xfffffece ) | V_71 << 8 ;
if ( F_25 ( V_29 -> V_13 ) -> V_83 >= V_84 ) {
if ( V_4 -> type == V_72 )
V_70 |= 0x1a << 16 ;
else
V_70 &= ~ ( 0x1a << 16 ) ;
}
F_16 ( V_10 , 0 , V_82 + V_63 , V_70 ) ;
F_17 ( 1 ) ;
V_69 = F_15 ( V_10 , 0 , V_82 + V_63 ) ;
F_16 ( V_10 , 0 , V_82 + V_63 , V_69 | 1 ) ;
F_16 ( V_10 , V_71 , V_85 ,
V_86 | V_62 ) ;
V_69 = F_15 ( V_10 , V_71 , V_41 ) ;
F_16 ( V_10 , V_71 , V_41 ,
V_69 | V_87 ) ;
F_17 ( 5 ) ;
V_61 = F_15 ( V_10 , 0 , V_41 + V_63 ) ;
V_61 &= F_15 ( V_10 , 0 , V_41 + V_63 ) ;
V_69 = F_15 ( V_10 , V_71 , V_41 ) ;
F_16 ( V_10 , V_71 , V_41 ,
V_69 & ~ V_87 ) ;
F_16 ( V_10 , V_71 , V_85 , 0 ) ;
F_16 ( V_10 , 0 , V_82 + V_63 , V_66 ) ;
F_16 ( V_10 , 0 , V_41 + V_63 , V_36 ) ;
if ( V_63 == 0x68 )
F_24 ( V_13 , V_77 , V_65 ) ;
F_24 ( V_13 , V_76 , V_64 ) ;
if ( V_60 ) {
V_60 -> V_81 ( V_60 , 0 , V_79 , 0xff , V_68 ) ;
V_60 -> V_81 ( V_60 , 0 , V_80 , 0xff , V_67 ) ;
}
return V_61 ;
}
static enum V_25
F_26 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_28 ( V_2 -> V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_27 ( V_2 ) )
return V_58 ;
if ( F_21 ( V_2 ) &
V_88 ) {
F_20 ( V_29 , L_2 ,
'@' + F_28 ( V_4 -> V_6 ) ) ;
return V_57 ;
} else {
return V_58 ;
}
}
static bool F_29 ( struct V_1 * V_2 ,
const struct V_89 * V_90 ,
struct V_89 * V_91 )
{
if ( F_27 ( V_2 ) )
return false ;
return true ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = V_2 -> V_94 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_71 = F_31 ( V_2 -> V_95 ) -> V_96 ;
V_93 -> V_97 ( V_2 , V_98 ) ;
F_32 ( V_10 , V_71 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_89 * V_91 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_28 * V_29 = V_28 ( V_10 ) ;
int V_71 = F_31 ( V_2 -> V_95 ) -> V_96 ;
if ( F_34 ( V_10 ) ) {
struct V_1 * V_99 ;
T_2 V_100 = F_1 ( V_2 ) ;
T_2 V_101 ;
F_16 ( V_10 , 0 , V_82 + V_100 ,
V_71 << 8 | V_102 ) ;
F_35 (rebind, &dev->mode_config.encoder_list, head) {
if ( V_99 == V_2
|| F_2 ( V_99 ) -> V_4 -> type != V_103 )
continue;
V_100 = F_1 ( V_99 ) ;
V_101 = F_15 ( V_10 , 0 , V_82 + V_100 ) ;
F_16 ( V_10 , 0 , V_82 + V_100 ,
( V_101 & ~ 0x0100 ) | ( V_71 ^ 1 ) << 8 ) ;
}
}
if ( F_25 ( V_29 -> V_13 ) -> V_104 < 0x44 )
F_16 ( V_10 , 0 , V_41 + F_1 ( V_2 ) , 0xf0000000 ) ;
else
F_16 ( V_10 , 0 , V_41 + F_1 ( V_2 ) , 0x00100000 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct F_2 * V_105 = F_2 ( V_2 ) ;
struct V_28 * V_29 = V_28 ( V_2 -> V_10 ) ;
struct F_31 * V_106 = F_31 ( V_2 -> V_95 ) ;
struct V_92 * V_93 = V_2 -> V_94 ;
V_93 -> V_97 ( V_2 , V_107 ) ;
F_20 ( V_29 , L_3 ,
F_37 ( V_105 ) -> V_108 . V_109 ,
V_106 -> V_96 , '@' + F_28 ( V_105 -> V_4 -> V_6 ) ) ;
}
void F_38 ( struct V_1 * V_2 , bool V_110 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_34 ( V_10 ) ) {
T_2 * V_111 = & F_39 ( V_10 ) -> V_111 [ F_28 ( V_4 -> V_6 ) - 1 ] ;
int V_112 = V_82 + F_1 ( V_2 ) ;
T_2 V_113 = F_15 ( V_10 , 0 , V_112 ) ;
if ( V_110 ) {
* V_111 |= 1 << V_4 -> V_96 ;
F_16 ( V_10 , 0 , V_112 , V_113 | V_102 ) ;
} else {
* V_111 &= ~ ( 1 << V_4 -> V_96 ) ;
if ( ! * V_111 )
F_16 ( V_10 , 0 , V_112 ,
V_113 & ~ V_102 ) ;
}
}
}
bool F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
return F_34 ( V_2 -> V_10 ) &&
( F_39 ( V_10 ) -> V_111 [ F_28 ( V_4 -> V_6 ) - 1 ] & ~ ( 1 << V_4 -> V_96 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_90 )
{
struct F_2 * V_105 = F_2 ( V_2 ) ;
struct V_28 * V_29 = V_28 ( V_2 -> V_10 ) ;
if ( V_105 -> V_114 == V_90 )
return;
V_105 -> V_114 = V_90 ;
F_20 ( V_29 , L_4 ,
V_90 , V_105 -> V_4 -> V_96 ) ;
F_38 ( V_2 , V_90 == V_107 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct F_2 * V_105 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_34 ( V_10 ) )
V_105 -> V_115 . V_116 = F_15 ( V_10 , 0 , V_82 +
F_1 ( V_2 ) ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct F_2 * V_105 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_34 ( V_10 ) )
F_16 ( V_10 , 0 , V_82 + F_1 ( V_2 ) ,
V_105 -> V_115 . V_116 ) ;
V_105 -> V_114 = V_117 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct F_2 * V_105 = F_2 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_105 ) ;
}
int
F_46 ( struct V_26 * V_27 , struct V_3 * V_118 )
{
const struct V_92 * V_93 ;
struct F_2 * V_105 = NULL ;
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_1 * V_2 ;
V_105 = F_47 ( sizeof( * V_105 ) , V_119 ) ;
if ( ! V_105 )
return - V_120 ;
V_2 = F_48 ( V_105 ) ;
V_105 -> V_4 = V_118 ;
V_105 -> V_6 = F_28 ( V_118 -> V_6 ) - 1 ;
if ( F_34 ( V_10 ) )
V_93 = & V_121 ;
else
V_93 = & V_122 ;
F_49 ( V_10 , V_2 , & V_123 , V_124 ) ;
F_50 ( V_2 , V_93 ) ;
V_2 -> V_125 = V_118 -> V_126 ;
V_2 -> V_127 = 0 ;
F_51 ( V_27 , V_2 ) ;
return 0 ;
}
