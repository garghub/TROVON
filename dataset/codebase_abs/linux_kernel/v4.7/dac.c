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
struct V_14 * V_15 = & V_13 -> V_15 . V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
bool V_18 , V_19 , V_20 ;
int V_21 = 0 ;
if ( F_4 (&drm->device, 10 ,
if (!(nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_22 ;
if ( F_4 (&drm->device, 10 ,
if ( (nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_22 ;
if ( F_4 (&drm->device, 10 ,
if (!(nvif_rd32(device, NV_PRMCIO_INP0__COLOR) & 1))
break;
) < 0 )
return - V_22 ;
F_5 ( 100 ) ;
V_18 = F_6 ( V_15 , V_23 ) & 0x10 ;
do {
F_5 ( 100 ) ;
V_19 = F_6 ( V_15 , V_23 ) & 0x10 ;
if ( V_18 != V_19 ) {
V_20 =
F_6 ( V_15 , V_23 ) & 0x10 ;
if ( V_19 == V_20 ) {
V_18 = V_19 ;
V_19 = ! V_18 ;
}
}
} while ( ( V_18 != V_19 ) && ++ V_21 < V_24 );
if ( V_21 == V_24 )
V_11 [ V_17 ] = false ;
else
V_11 [ V_17 ] = V_18 ;
}
return 0 ;
}
static enum V_25 F_7 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_14 * V_15 = & V_12 ( V_10 ) -> V_15 . V_16 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
T_1 V_28 , V_29 , V_30 , V_31 ;
T_1 V_32 [ 3 ] , V_33 ;
T_2 V_34 , V_35 ;
int V_17 ;
T_1 V_36 ;
bool V_11 = true ;
if ( F_8 ( V_10 ) )
F_9 ( V_10 , 0 ) ;
V_31 = F_10 ( V_10 , 0 , V_37 ) ;
F_11 ( V_10 , 0 , V_37 , V_31 | 0x80 ) ;
V_28 = F_12 ( V_10 , 0 , V_38 ) ;
F_13 ( V_10 , 0 , V_38 , V_28 & ~ 0x20 ) ;
V_34 = F_14 ( V_10 , 0 , V_39 ) ;
F_15 ( V_10 , 0 , V_39 ,
V_34 & ~ V_40 ) ;
F_16 ( 10 ) ;
V_29 = F_10 ( V_10 , 0 , V_41 ) ;
F_11 ( V_10 , 0 , V_41 ,
V_29 & ~ ( 0x80 | F_17 ( V_42 ) ) ) ;
V_30 = F_10 ( V_10 , 0 , V_43 ) ;
F_11 ( V_10 , 0 , V_43 , V_30 & ~ 0xc0 ) ;
F_18 ( V_15 , V_44 , 0x0 ) ;
for ( V_17 = 0 ; V_17 < 3 ; V_17 ++ )
V_32 [ V_17 ] = F_6 ( V_15 , V_45 ) ;
V_33 = F_6 ( V_15 , V_46 ) ;
F_18 ( V_15 , V_46 , 0 ) ;
V_35 = F_14 ( V_10 , 0 , V_47 ) ;
F_15 ( V_10 , 0 , V_47 ,
( V_35 & ~ ( V_48 |
V_49 ) ) |
V_50 ) ;
V_36 = 8 ;
do {
bool V_51 [ 2 ] ;
F_18 ( V_15 , V_52 , 0 ) ;
F_18 ( V_15 , V_45 , 0 ) ;
F_18 ( V_15 , V_45 , 0 ) ;
F_18 ( V_15 , V_45 , V_36 ) ;
V_17 = 0 ;
do {
if ( F_3 ( V_10 , V_51 ) )
goto V_53;
} while ( ( V_51 [ 0 ] != V_51 [ 1 ] ) &&
++ V_17 < V_54 );
if ( V_17 == V_54 )
V_11 = false ;
else
V_11 = V_51 [ 0 ] ;
} while ( ++ V_36 < 0x18 && V_11 );
V_53:
F_18 ( V_15 , V_46 , V_33 ) ;
F_15 ( V_10 , 0 , V_47 , V_35 ) ;
F_18 ( V_15 , V_52 , 0 ) ;
for ( V_17 = 0 ; V_17 < 3 ; V_17 ++ )
F_18 ( V_15 , V_45 , V_32 [ V_17 ] ) ;
F_15 ( V_10 , 0 , V_39 , V_34 ) ;
F_11 ( V_10 , 0 , V_41 , V_29 ) ;
F_11 ( V_10 , 0 , V_43 , V_30 ) ;
F_13 ( V_10 , 0 , V_38 , V_28 ) ;
F_11 ( V_10 , 0 , V_37 , V_31 ) ;
if ( V_36 == 0x18 ) {
F_19 ( V_13 , L_1 ) ;
return V_55 ;
}
return V_56 ;
}
T_2 F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = & V_12 ( V_10 ) -> V_15 . V_16 ;
struct V_57 * V_58 = F_21 ( & V_13 -> V_15 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
T_2 V_59 , V_60 , V_61 = F_1 ( V_2 ) ;
T_2 V_62 = 0 , V_63 = 0 , V_64 ,
V_34 , V_65 = 0 , V_66 = 0 , V_67 , V_68 ;
int V_69 ;
#define F_22 ( T_3 , T_4 , T_5 ) (r << 0 | g << 10 | b << 20)
if ( V_4 -> type == V_70 ) {
V_60 = F_22 ( 0xa0 , 0xa0 , 0xa0 ) ;
if ( V_13 -> V_71 . V_72 )
V_60 = V_13 -> V_71 . V_72 ;
} else {
V_60 = F_22 ( 0x140 , 0x140 , 0x140 ) ;
if ( V_13 -> V_71 . V_73 )
V_60 = V_13 -> V_71 . V_73 ;
}
V_34 = F_14 ( V_10 , 0 , V_39 + V_61 ) ;
F_15 ( V_10 , 0 , V_39 + V_61 ,
V_34 & ~ V_40 ) ;
V_62 = F_23 ( V_15 , V_74 ) ;
F_24 ( V_15 , V_74 , V_62 & 0xd7ffffff ) ;
if ( V_61 == 0x68 ) {
V_63 = F_23 ( V_15 , V_75 ) ;
F_24 ( V_15 , V_75 , V_63 & 0xffffffcf ) ;
}
if ( V_58 ) {
V_66 = F_25 ( V_58 , 0 , V_76 , 0xff ) ;
V_65 = F_25 ( V_58 , 0 , V_77 , 0xff ) ;
F_26 ( V_58 , 0 , V_76 , 0xff , V_4 -> type == V_70 ) ;
F_26 ( V_58 , 0 , V_77 , 0xff , V_4 -> type == V_70 ) ;
}
F_16 ( 4 ) ;
V_64 = F_14 ( V_10 , 0 , V_78 + V_61 ) ;
V_69 = ( V_64 & 0x100 ) >> 8 ;
if ( ! ( F_10 ( V_10 , V_69 , V_43 ) & 0xC0 ) )
V_69 ^= 1 ;
V_68 = ( V_64 & 0xfffffece ) | V_69 << 8 ;
if ( V_13 -> V_15 . V_79 . V_80 >= V_81 ) {
if ( V_4 -> type == V_70 )
V_68 |= 0x1a << 16 ;
else
V_68 &= ~ ( 0x1a << 16 ) ;
}
F_15 ( V_10 , 0 , V_78 + V_61 , V_68 ) ;
F_16 ( 1 ) ;
V_67 = F_14 ( V_10 , 0 , V_78 + V_61 ) ;
F_15 ( V_10 , 0 , V_78 + V_61 , V_67 | 1 ) ;
F_15 ( V_10 , V_69 , V_82 ,
V_83 | V_60 ) ;
V_67 = F_14 ( V_10 , V_69 , V_39 ) ;
F_15 ( V_10 , V_69 , V_39 ,
V_67 | V_84 ) ;
F_16 ( 5 ) ;
V_59 = F_14 ( V_10 , 0 , V_39 + V_61 ) ;
V_59 &= F_14 ( V_10 , 0 , V_39 + V_61 ) ;
V_67 = F_14 ( V_10 , V_69 , V_39 ) ;
F_15 ( V_10 , V_69 , V_39 ,
V_67 & ~ V_84 ) ;
F_15 ( V_10 , V_69 , V_82 , 0 ) ;
F_15 ( V_10 , 0 , V_78 + V_61 , V_64 ) ;
F_15 ( V_10 , 0 , V_39 + V_61 , V_34 ) ;
if ( V_61 == 0x68 )
F_24 ( V_15 , V_75 , V_63 ) ;
F_24 ( V_15 , V_74 , V_62 ) ;
if ( V_58 ) {
F_26 ( V_58 , 0 , V_76 , 0xff , V_66 ) ;
F_26 ( V_58 , 0 , V_77 , 0xff , V_65 ) ;
}
return V_59 ;
}
static enum V_25
F_27 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_28 ( V_2 ) )
return V_56 ;
if ( F_20 ( V_2 ) &
V_85 ) {
F_19 ( V_13 , L_2 ,
'@' + F_29 ( V_4 -> V_6 ) ) ;
return V_55 ;
} else {
return V_56 ;
}
}
static bool F_30 ( struct V_1 * V_2 ,
const struct V_86 * V_87 ,
struct V_86 * V_88 )
{
if ( F_28 ( V_2 ) )
return false ;
return true ;
}
static void F_31 ( struct V_1 * V_2 )
{
const struct V_89 * V_90 = V_2 -> V_91 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_69 = F_32 ( V_2 -> V_92 ) -> V_93 ;
V_90 -> V_94 ( V_2 , V_95 ) ;
F_33 ( V_10 , V_69 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_86 * V_88 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
int V_69 = F_32 ( V_2 -> V_92 ) -> V_93 ;
if ( F_35 ( V_10 ) ) {
struct V_1 * V_96 ;
T_2 V_97 = F_1 ( V_2 ) ;
T_2 V_98 ;
F_15 ( V_10 , 0 , V_78 + V_97 ,
V_69 << 8 | V_99 ) ;
F_36 (rebind, &dev->mode_config.encoder_list, head) {
if ( V_96 == V_2
|| F_2 ( V_96 ) -> V_4 -> type != V_100 )
continue;
V_97 = F_1 ( V_96 ) ;
V_98 = F_14 ( V_10 , 0 , V_78 + V_97 ) ;
F_15 ( V_10 , 0 , V_78 + V_97 ,
( V_98 & ~ 0x0100 ) | ( V_69 ^ 1 ) << 8 ) ;
}
}
if ( V_13 -> V_15 . V_79 . V_101 < 0x44 )
F_15 ( V_10 , 0 , V_39 + F_1 ( V_2 ) , 0xf0000000 ) ;
else
F_15 ( V_10 , 0 , V_39 + F_1 ( V_2 ) , 0x00100000 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct F_2 * V_102 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
struct F_32 * V_103 = F_32 ( V_2 -> V_92 ) ;
const struct V_89 * V_90 = V_2 -> V_91 ;
V_90 -> V_94 ( V_2 , V_104 ) ;
F_19 ( V_13 , L_3 ,
F_38 ( V_102 ) -> V_105 . V_106 ,
V_103 -> V_93 , '@' + F_29 ( V_102 -> V_4 -> V_6 ) ) ;
}
void F_39 ( struct V_1 * V_2 , bool V_107 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
if ( F_35 ( V_10 ) ) {
T_2 * V_108 = & F_40 ( V_10 ) -> V_108 [ F_29 ( V_4 -> V_6 ) - 1 ] ;
int V_109 = V_78 + F_1 ( V_2 ) ;
T_2 V_110 = F_14 ( V_10 , 0 , V_109 ) ;
if ( V_107 ) {
* V_108 |= 1 << V_4 -> V_93 ;
F_15 ( V_10 , 0 , V_109 , V_110 | V_99 ) ;
} else {
* V_108 &= ~ ( 1 << V_4 -> V_93 ) ;
if ( ! * V_108 )
F_15 ( V_10 , 0 , V_109 ,
V_110 & ~ V_99 ) ;
}
}
}
bool F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_4 ;
return F_35 ( V_2 -> V_10 ) &&
( F_40 ( V_10 ) -> V_108 [ F_29 ( V_4 -> V_6 ) - 1 ] & ~ ( 1 << V_4 -> V_93 ) ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_87 )
{
struct F_2 * V_102 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_12 ( V_2 -> V_10 ) ;
if ( V_102 -> V_111 == V_87 )
return;
V_102 -> V_111 = V_87 ;
F_19 ( V_13 , L_4 ,
V_87 , V_102 -> V_4 -> V_93 ) ;
F_39 ( V_2 , V_87 == V_104 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct F_2 * V_102 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_35 ( V_10 ) )
V_102 -> V_112 . V_113 = F_14 ( V_10 , 0 , V_78 +
F_1 ( V_2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct F_2 * V_102 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_35 ( V_10 ) )
F_15 ( V_10 , 0 , V_78 + F_1 ( V_2 ) ,
V_102 -> V_112 . V_113 ) ;
V_102 -> V_111 = V_114 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct F_2 * V_102 = F_2 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_102 ) ;
}
int
F_47 ( struct V_26 * V_27 , struct V_3 * V_115 )
{
const struct V_89 * V_90 ;
struct F_2 * V_102 = NULL ;
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_1 * V_2 ;
V_102 = F_48 ( sizeof( * V_102 ) , V_116 ) ;
if ( ! V_102 )
return - V_117 ;
V_2 = F_49 ( V_102 ) ;
V_102 -> V_4 = V_115 ;
V_102 -> V_6 = F_29 ( V_115 -> V_6 ) - 1 ;
V_102 -> V_118 = F_42 ;
V_102 -> V_119 = F_43 ;
if ( F_35 ( V_10 ) )
V_90 = & V_120 ;
else
V_90 = & V_121 ;
F_50 ( V_10 , V_2 , & V_122 , V_123 ,
NULL ) ;
F_51 ( V_2 , V_90 ) ;
V_2 -> V_124 = V_115 -> V_125 ;
V_2 -> V_126 = 0 ;
F_52 ( V_27 , V_2 ) ;
return 0 ;
}
