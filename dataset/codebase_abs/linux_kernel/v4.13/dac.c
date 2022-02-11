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
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = & V_13 -> V_16 . V_15 . V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
bool V_19 , V_20 , V_21 ;
int V_22 = 0 ;
if ( F_4 (&drm->client.device, 10 ,
if (!(nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_23 ;
if ( F_4 (&drm->client.device, 10 ,
if ( (nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_23 ;
if ( F_4 (&drm->client.device, 10 ,
if (!(nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_23 ;
F_5 ( 100 ) ;
V_19 = F_6 ( V_15 , V_24 ) & 0x10 ;
do {
F_5 ( 100 ) ;
V_20 = F_6 ( V_15 , V_24 ) & 0x10 ;
if ( V_19 != V_20 ) {
V_21 =
F_6 ( V_15 , V_24 ) & 0x10 ;
if ( V_20 == V_21 ) {
V_19 = V_20 ;
V_20 = ! V_19 ;
}
}
} while ( ( V_19 != V_20 ) && ++ V_22 < V_25 );
if ( V_22 == V_25 )
V_11 [ V_18 ] = false ;
else
V_11 [ V_18 ] = V_19 ;
}
return 0 ;
}
static enum V_26 F_7 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_14 * V_15 = & V_12 ( V_10 ) -> V_16 . V_15 . V_17 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
T_1 V_29 , V_30 , V_31 , V_32 ;
T_1 V_33 [ 3 ] , V_34 ;
T_2 V_35 , V_36 ;
int V_18 ;
T_1 V_37 ;
bool V_11 = true ;
if ( F_8 ( V_10 ) )
F_9 ( V_10 , 0 ) ;
V_32 = F_10 ( V_10 , 0 , V_38 ) ;
F_11 ( V_10 , 0 , V_38 , V_32 | 0x80 ) ;
V_29 = F_12 ( V_10 , 0 , V_39 ) ;
F_13 ( V_10 , 0 , V_39 , V_29 & ~ 0x20 ) ;
V_35 = F_14 ( V_10 , 0 , V_40 ) ;
F_15 ( V_10 , 0 , V_40 ,
V_35 & ~ V_41 ) ;
F_16 ( 10 ) ;
V_30 = F_10 ( V_10 , 0 , V_42 ) ;
F_11 ( V_10 , 0 , V_42 ,
V_30 & ~ ( 0x80 | F_17 ( V_43 ) ) ) ;
V_31 = F_10 ( V_10 , 0 , V_44 ) ;
F_11 ( V_10 , 0 , V_44 , V_31 & ~ 0xc0 ) ;
F_18 ( V_15 , V_45 , 0x0 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ )
V_33 [ V_18 ] = F_6 ( V_15 , V_46 ) ;
V_34 = F_6 ( V_15 , V_47 ) ;
F_18 ( V_15 , V_47 , 0 ) ;
V_36 = F_14 ( V_10 , 0 , V_48 ) ;
F_15 ( V_10 , 0 , V_48 ,
( V_36 & ~ ( V_49 |
V_50 ) ) |
V_51 ) ;
V_37 = 8 ;
do {
bool V_52 [ 2 ] ;
F_18 ( V_15 , V_53 , 0 ) ;
F_18 ( V_15 , V_46 , 0 ) ;
F_18 ( V_15 , V_46 , 0 ) ;
F_18 ( V_15 , V_46 , V_37 ) ;
V_18 = 0 ;
do {
if ( F_3 ( V_10 , V_52 ) )
goto V_54;
} while ( ( V_52 [ 0 ] != V_52 [ 1 ] ) &&
++ V_18 < V_55 );
if ( V_18 == V_55 )
V_11 = false ;
else
V_11 = V_52 [ 0 ] ;
} while ( ++ V_37 < 0x18 && V_11 );
V_54:
F_18 ( V_15 , V_47 , V_34 ) ;
F_15 ( V_10 , 0 , V_48 , V_36 ) ;
F_18 ( V_15 , V_53 , 0 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ )
F_18 ( V_15 , V_46 , V_33 [ V_18 ] ) ;
F_15 ( V_10 , 0 , V_40 , V_35 ) ;
F_11 ( V_10 , 0 , V_42 , V_30 ) ;
F_11 ( V_10 , 0 , V_44 , V_31 ) ;
F_13 ( V_10 , 0 , V_39 , V_29 ) ;
F_11 ( V_10 , 0 , V_38 , V_32 ) ;
if ( V_37 == 0x18 ) {
F_19 ( V_13 , L_1 ) ;
return V_56 ;
}
return V_57 ;
}
T_2 F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = & V_12 ( V_10 ) -> V_16 . V_15 . V_17 ;
struct V_58 * V_59 = F_21 ( & V_13 -> V_16 . V_15 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
T_2 V_60 , V_61 , V_62 = F_1 ( V_2 ) ;
T_2 V_63 = 0 , V_64 = 0 , V_65 ,
V_35 , V_66 = 0 , V_67 = 0 , V_68 , V_69 ;
int V_70 ;
#define F_22 ( T_3 , T_4 , T_5 ) (r << 0 | g << 10 | b << 20)
if ( V_4 -> type == V_71 ) {
V_61 = F_22 ( 0xa0 , 0xa0 , 0xa0 ) ;
if ( V_13 -> V_72 . V_73 )
V_61 = V_13 -> V_72 . V_73 ;
} else {
V_61 = F_22 ( 0x140 , 0x140 , 0x140 ) ;
if ( V_13 -> V_72 . V_74 )
V_61 = V_13 -> V_72 . V_74 ;
}
V_35 = F_14 ( V_10 , 0 , V_40 + V_62 ) ;
F_15 ( V_10 , 0 , V_40 + V_62 ,
V_35 & ~ V_41 ) ;
V_63 = F_23 ( V_15 , V_75 ) ;
F_24 ( V_15 , V_75 , V_63 & 0xd7ffffff ) ;
if ( V_62 == 0x68 ) {
V_64 = F_23 ( V_15 , V_76 ) ;
F_24 ( V_15 , V_76 , V_64 & 0xffffffcf ) ;
}
if ( V_59 ) {
V_67 = F_25 ( V_59 , 0 , V_77 , 0xff ) ;
V_66 = F_25 ( V_59 , 0 , V_78 , 0xff ) ;
F_26 ( V_59 , 0 , V_77 , 0xff , V_4 -> type == V_71 ) ;
F_26 ( V_59 , 0 , V_78 , 0xff , V_4 -> type == V_71 ) ;
}
F_16 ( 4 ) ;
V_65 = F_14 ( V_10 , 0 , V_79 + V_62 ) ;
V_70 = ( V_65 & 0x100 ) >> 8 ;
if ( ! ( F_10 ( V_10 , V_70 , V_44 ) & 0xC0 ) )
V_70 ^= 1 ;
V_69 = ( V_65 & 0xfffffece ) | V_70 << 8 ;
if ( V_13 -> V_16 . V_15 . V_80 . V_81 >= V_82 ) {
if ( V_4 -> type == V_71 )
V_69 |= 0x1a << 16 ;
else
V_69 &= ~ ( 0x1a << 16 ) ;
}
F_15 ( V_10 , 0 , V_79 + V_62 , V_69 ) ;
F_16 ( 1 ) ;
V_68 = F_14 ( V_10 , 0 , V_79 + V_62 ) ;
F_15 ( V_10 , 0 , V_79 + V_62 , V_68 | 1 ) ;
F_15 ( V_10 , V_70 , V_83 ,
V_84 | V_61 ) ;
V_68 = F_14 ( V_10 , V_70 , V_40 ) ;
F_15 ( V_10 , V_70 , V_40 ,
V_68 | V_85 ) ;
F_16 ( 5 ) ;
V_60 = F_14 ( V_10 , 0 , V_40 + V_62 ) ;
V_60 &= F_14 ( V_10 , 0 , V_40 + V_62 ) ;
V_68 = F_14 ( V_10 , V_70 , V_40 ) ;
F_15 ( V_10 , V_70 , V_40 ,
V_68 & ~ V_85 ) ;
F_15 ( V_10 , V_70 , V_83 , 0 ) ;
F_15 ( V_10 , 0 , V_79 + V_62 , V_65 ) ;
F_15 ( V_10 , 0 , V_40 + V_62 , V_35 ) ;
if ( V_62 == 0x68 )
F_24 ( V_15 , V_76 , V_64 ) ;
F_24 ( V_15 , V_75 , V_63 ) ;
if ( V_59 ) {
F_26 ( V_59 , 0 , V_77 , 0xff , V_67 ) ;
F_26 ( V_59 , 0 , V_78 , 0xff , V_66 ) ;
}
return V_60 ;
}
static enum V_26
F_27 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_28 ( V_2 ) )
return V_57 ;
if ( F_20 ( V_2 ) &
V_86 ) {
F_19 ( V_13 , L_2 ,
'@' + F_29 ( V_4 -> V_6 ) ) ;
return V_56 ;
} else {
return V_57 ;
}
}
static bool F_30 ( struct V_1 * V_2 ,
const struct V_87 * V_88 ,
struct V_87 * V_89 )
{
if ( F_28 ( V_2 ) )
return false ;
return true ;
}
static void F_31 ( struct V_1 * V_2 )
{
const struct V_90 * V_91 = V_2 -> V_92 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_70 = F_32 ( V_2 -> V_93 ) -> V_94 ;
V_91 -> V_95 ( V_2 , V_96 ) ;
F_33 ( V_10 , V_70 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_87 * V_89 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
int V_70 = F_32 ( V_2 -> V_93 ) -> V_94 ;
if ( F_35 ( V_10 ) ) {
struct V_1 * V_97 ;
T_2 V_98 = F_1 ( V_2 ) ;
T_2 V_99 ;
F_15 ( V_10 , 0 , V_79 + V_98 ,
V_70 << 8 | V_100 ) ;
F_36 (rebind, &dev->mode_config.encoder_list, head) {
if ( V_97 == V_2
|| F_2 ( V_97 ) -> V_4 -> type != V_101 )
continue;
V_98 = F_1 ( V_97 ) ;
V_99 = F_14 ( V_10 , 0 , V_79 + V_98 ) ;
F_15 ( V_10 , 0 , V_79 + V_98 ,
( V_99 & ~ 0x0100 ) | ( V_70 ^ 1 ) << 8 ) ;
}
}
if ( V_13 -> V_16 . V_15 . V_80 . V_102 < 0x44 )
F_15 ( V_10 , 0 , V_40 + F_1 ( V_2 ) , 0xf0000000 ) ;
else
F_15 ( V_10 , 0 , V_40 + F_1 ( V_2 ) , 0x00100000 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct F_2 * V_103 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
struct F_32 * V_104 = F_32 ( V_2 -> V_93 ) ;
const struct V_90 * V_91 = V_2 -> V_92 ;
V_91 -> V_95 ( V_2 , V_105 ) ;
F_19 ( V_13 , L_3 ,
F_38 ( V_103 ) -> V_106 . V_107 ,
V_104 -> V_94 , '@' + F_29 ( V_103 -> V_4 -> V_6 ) ) ;
}
void F_39 ( struct V_1 * V_2 , bool V_108 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_35 ( V_10 ) ) {
T_2 * V_109 = & F_40 ( V_10 ) -> V_109 [ F_29 ( V_4 -> V_6 ) - 1 ] ;
int V_110 = V_79 + F_1 ( V_2 ) ;
T_2 V_111 = F_14 ( V_10 , 0 , V_110 ) ;
if ( V_108 ) {
* V_109 |= 1 << V_4 -> V_94 ;
F_15 ( V_10 , 0 , V_110 , V_111 | V_100 ) ;
} else {
* V_109 &= ~ ( 1 << V_4 -> V_94 ) ;
if ( ! * V_109 )
F_15 ( V_10 , 0 , V_110 ,
V_111 & ~ V_100 ) ;
}
}
}
bool F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
return F_35 ( V_2 -> V_10 ) &&
( F_40 ( V_10 ) -> V_109 [ F_29 ( V_4 -> V_6 ) - 1 ] & ~ ( 1 << V_4 -> V_94 ) ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_88 )
{
struct F_2 * V_103 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
if ( V_103 -> V_112 == V_88 )
return;
V_103 -> V_112 = V_88 ;
F_19 ( V_13 , L_4 ,
V_88 , V_103 -> V_4 -> V_94 ) ;
F_39 ( V_2 , V_88 == V_105 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct F_2 * V_103 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_35 ( V_10 ) )
V_103 -> V_113 . V_114 = F_14 ( V_10 , 0 , V_79 +
F_1 ( V_2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct F_2 * V_103 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_35 ( V_10 ) )
F_15 ( V_10 , 0 , V_79 + F_1 ( V_2 ) ,
V_103 -> V_113 . V_114 ) ;
V_103 -> V_112 = V_115 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct F_2 * V_103 = F_2 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_103 ) ;
}
int
F_47 ( struct V_27 * V_28 , struct V_3 * V_116 )
{
const struct V_90 * V_91 ;
struct F_2 * V_103 = NULL ;
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_1 * V_2 ;
V_103 = F_48 ( sizeof( * V_103 ) , V_117 ) ;
if ( ! V_103 )
return - V_118 ;
V_2 = F_49 ( V_103 ) ;
V_103 -> V_4 = V_116 ;
V_103 -> V_6 = F_29 ( V_116 -> V_6 ) - 1 ;
V_103 -> V_119 = F_42 ;
V_103 -> V_120 = F_43 ;
if ( F_35 ( V_10 ) )
V_91 = & V_121 ;
else
V_91 = & V_122 ;
F_50 ( V_10 , V_2 , & V_123 , V_124 ,
NULL ) ;
F_51 ( V_2 , V_91 ) ;
V_2 -> V_125 = V_116 -> V_126 ;
V_2 -> V_127 = 0 ;
F_52 ( V_28 , V_2 ) ;
return 0 ;
}
