static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_9 * V_10 = & V_2 -> V_6 . V_11 -> V_10 ;
struct V_12 * V_13 = V_10 -> V_13 ;
T_1 V_14 , V_15 , V_16 , V_17 ;
T_2 V_18 ;
V_14 = F_2 ( V_13 , 0x100228 ) ;
V_15 = F_2 ( V_13 , 0x100230 ) ;
V_16 = F_2 ( V_13 , 0x10023c ) ;
V_17 = F_2 ( V_13 , 0x100240 ) ;
switch ( ( ! F_3 ( V_19 ) ) * V_2 -> V_6 . type ) {
case V_20 :
F_3 ( V_19 ) = F_3 ( V_21 ) - 1 ;
break;
case V_22 :
F_3 ( V_19 ) = ( ( V_14 & 0xff000000 ) >> 24 ) + 1 ;
break;
}
if ( V_13 -> V_23 == 0xa0 ) {
V_18 = 0x19 + V_2 -> V_6 . V_24 -> V_8 . V_25 ;
V_3 [ 6 ] = ( 0x2d + F_3 ( V_21 ) - F_3 ( V_19 ) +
V_2 -> V_6 . V_24 -> V_8 . V_25 ) << 16 |
F_3 ( V_19 ) << 8 |
( 0x2f + F_3 ( V_21 ) - F_3 ( V_19 ) ) ;
} else {
V_18 = 0x16 ;
V_3 [ 6 ] = ( 0x2b + F_3 ( V_21 ) - F_3 ( V_19 ) ) << 16 |
F_4 ( V_26 , F_3 ( V_19 ) - 2 , 1 ) << 8 |
( 0x2e + F_3 ( V_21 ) - F_3 ( V_19 ) ) ;
}
V_3 [ 0 ] = ( F_3 ( V_27 ) << 24 | F_3 ( V_28 ) << 16 | F_3 ( V_29 ) << 8 | F_3 ( V_30 ) ) ;
V_3 [ 1 ] = ( F_3 ( V_31 ) + 1 + F_3 ( V_19 ) ) << 24 |
F_4 ( T_2 , F_3 ( 18 ) , 1 ) << 16 |
( F_3 ( V_32 ) + 1 + F_3 ( V_19 ) ) << 8 |
( 3 + F_3 ( V_21 ) - F_3 ( V_19 ) ) ;
V_3 [ 2 ] = ( F_3 ( V_19 ) - 1 ) << 24 |
( F_3 ( V_33 ) << 16 ) |
( F_3 ( V_34 ) << 8 ) |
F_3 ( V_35 ) ;
V_3 [ 3 ] = ( V_18 - 2 + F_3 ( V_21 ) ) << 24 |
V_18 << 16 |
( F_3 ( V_21 ) - 1 ) << 8 |
( F_3 ( V_21 ) - 1 ) ;
V_3 [ 4 ] = ( V_15 & 0xffff0000 ) |
F_3 ( 13 ) << 8 |
F_3 ( 13 ) ;
V_3 [ 5 ] = F_3 ( V_29 ) << 24 |
F_4 ( T_2 , F_3 ( V_35 ) , F_3 ( V_34 ) ) << 16 |
F_3 ( V_27 ) ;
V_3 [ 7 ] = ( V_16 & 0xff00ffff ) | ( F_3 ( V_21 ) - 1 ) << 16 ;
V_3 [ 8 ] = ( V_17 & 0xffffff00 ) ;
if ( V_2 -> V_6 . type == V_20 ) {
V_3 [ 5 ] |= ( F_3 ( V_21 ) + 3 ) << 8 ;
V_3 [ 8 ] |= ( F_3 ( V_21 ) - 4 ) ;
} else
if ( V_2 -> V_6 . type == V_22 ) {
V_3 [ 5 ] |= ( F_3 ( V_21 ) + 2 ) << 8 ;
V_3 [ 8 ] |= ( F_3 ( V_21 ) - 2 ) ;
}
F_5 ( V_10 , L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
F_5 ( V_10 , L_2 ,
V_3 [ 4 ] , V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] ) ;
F_5 ( V_10 , L_3 , V_3 [ 8 ] ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned int V_36 ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_9 * V_10 = & V_2 -> V_6 . V_11 -> V_10 ;
struct V_12 * V_13 = V_10 -> V_13 ;
for ( V_36 = 0 ; V_36 <= 8 ; V_36 ++ )
V_3 [ V_36 ] = F_2 ( V_13 , 0x100220 + ( V_36 * 4 ) ) ;
V_5 -> V_37 = 0x10 ;
F_3 ( V_21 ) = ( V_3 [ 3 ] & 0xff ) + 1 ;
switch ( V_2 -> V_6 . type ) {
case V_20 :
F_3 ( V_19 ) = F_3 ( V_21 ) - 1 ;
break;
case V_22 :
F_3 ( V_19 ) = ( ( V_3 [ 2 ] & 0xff000000 ) >> 24 ) + 1 ;
break;
default:
return - V_38 ;
break;
}
F_3 ( V_31 ) = ( ( V_3 [ 1 ] >> 24 ) & 0xff ) - 1 - F_3 ( V_19 ) ;
return 0 ;
}
static void
F_7 ( struct V_39 * V_40 )
{
F_8 ( V_40 , V_41 [ 0 ] , 0x100 , 0x100 ) ;
F_8 ( V_40 , V_41 [ 0 ] , 0x100 , 0x000 ) ;
F_9 ( V_40 , 24000 ) ;
}
static void
F_10 ( struct V_39 * V_40 , T_2 V_42 , T_1 V_43 )
{
struct V_44 * V_45 = V_40 -> V_6 . V_10 -> V_13 -> V_45 ;
struct V_46 V_47 ;
T_1 V_48 , V_49 , V_50 ;
int V_51 ;
if ( F_11 ( V_45 , 0 , V_42 , V_52 ) != V_43 ) {
V_51 = F_12 ( V_45 , 0 , V_42 , V_52 , & V_47 ) ;
if ( V_51 )
return;
V_48 = V_47 . line >> 3 ;
V_49 = ( V_47 . line & 0x7 ) << 2 ;
V_50 = F_13 ( V_40 , V_45 [ V_48 ] ) ;
if ( V_50 & ( 8 << V_49 ) )
V_43 = ! V_43 ;
if ( ! ( V_47 . log [ 1 ] & 1 ) )
V_43 = ! V_43 ;
F_8 ( V_40 , V_45 [ V_48 ] , ( 0x3 << V_49 ) , ( ( V_43 | 0x2 ) << V_49 ) ) ;
F_9 ( V_40 , 20000 ) ;
}
}
static int
F_14 ( struct V_53 * V_6 , T_1 V_54 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
struct V_39 * V_40 = & V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_6 . V_11 -> V_10 ;
struct V_55 * V_8 = V_10 -> V_13 -> V_8 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_60 * V_24 ;
T_2 V_61 , V_62 , V_63 , V_64 , V_65 , V_66 ;
T_1 V_67 ;
T_1 V_68 , V_69 , V_70 , V_71 , V_72 , V_73 ;
int V_74 , V_75 , V_76 , V_77 , V_78 ;
int V_51 , V_36 ;
T_1 V_3 [ 9 ] ;
V_24 = & V_2 -> V_6 . V_7 ;
V_24 -> V_54 = V_54 ;
V_2 -> V_6 . V_24 = V_24 ;
V_36 = 0 ;
do {
V_67 = F_15 ( V_8 , V_36 ++ , & V_61 , & V_62 , & V_63 ,
& V_66 , & V_57 ) ;
if ( ! V_67 || ( V_61 < 0x25 || V_61 >= 0x40 ) ||
( V_66 < 2 ) ) {
F_16 ( V_10 , L_4 ) ;
return - V_79 ;
}
} while ( V_57 . V_80 < V_54 );
F_17 ( V_8 , V_67 , V_62 , & V_24 -> V_8 ) ;
V_65 = F_18 ( V_10 ) ;
if ( V_65 >= V_63 ) {
F_16 ( V_10 , L_5 ) ;
return - V_79 ;
}
V_67 = F_19 ( V_8 , V_67 + V_62 , V_66 , V_65 ,
& V_24 -> V_8 ) ;
if ( ! V_67 ) {
F_16 ( V_10 , L_6 ) ;
return - V_79 ;
}
if ( V_24 -> V_8 . V_81 != 0xff ) {
V_67 = F_20 ( V_8 , V_24 -> V_8 . V_81 ,
& V_61 , & V_62 , & V_63 , & V_64 , & V_24 -> V_8 ) ;
if ( ! V_67 || V_61 != 0x10 || V_62 < 0x12 ) {
F_16 ( V_10 , L_7
L_8 ,
V_65 , V_67 , V_61 , V_62 ) ;
return - V_79 ;
}
F_1 ( V_2 , V_3 ) ;
} else {
F_6 ( V_2 , V_3 ) ;
}
V_51 = F_21 ( V_40 , V_10 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_6 . V_41 [ 0 ] = F_13 ( V_40 , V_41 [ 0 ] ) ;
V_2 -> V_6 . V_41 [ 1 ] = F_13 ( V_40 , V_41 [ 1 ] ) ;
V_2 -> V_6 . V_41 [ 2 ] = F_13 ( V_40 , V_41 [ 2 ] ) ;
switch ( V_2 -> V_6 . type ) {
case V_22 :
V_51 = F_22 ( & V_2 -> V_6 ) ;
break;
default:
V_51 = - V_38 ;
break;
}
if ( V_51 ) {
F_16 ( V_10 , L_9 ) ;
return V_51 ;
}
if ( V_10 -> V_13 -> V_23 <= 0x96 && ! V_24 -> V_8 . V_82 )
F_8 ( V_40 , 0x100710 , 0x00000200 , 0x00000000 ) ;
F_8 ( V_40 , 0x100200 , 0x00000800 , 0x00000000 ) ;
F_23 ( V_40 ) ;
F_24 ( V_40 , 0x611200 , 0x00003300 ) ;
F_24 ( V_40 , 0x002504 , 0x00000001 ) ;
F_9 ( V_40 , 8000 ) ;
F_25 ( V_40 , 0x10 , 0x00 ) ;
F_26 ( V_40 , 0x00 , 0x01 ) ;
F_9 ( V_40 , 2000 ) ;
if ( V_24 -> V_8 . V_83 )
F_10 ( V_40 , 0x2e , 1 ) ;
F_24 ( V_40 , 0x1002d4 , 0x00000001 ) ;
F_24 ( V_40 , 0x1002d0 , 0x00000001 ) ;
F_24 ( V_40 , 0x1002d0 , 0x00000001 ) ;
F_24 ( V_40 , 0x100210 , 0x00000000 ) ;
F_24 ( V_40 , 0x1002dc , 0x00000001 ) ;
V_51 = F_27 ( V_8 , 0x004008 , & V_59 ) ;
V_59 . V_84 . V_85 = 0 ;
if ( V_51 >= 0 ) {
V_51 = F_28 ( V_10 , & V_59 , V_54 ,
& V_74 , & V_75 , & V_76 , & V_77 , & V_78 ) ;
if ( V_51 <= 0 )
V_51 = - V_79 ;
}
if ( V_51 < 0 )
return V_51 ;
if ( V_54 <= 750000 ) {
V_68 = 0x00000010 ;
V_69 = 0x90000000 ;
} else {
V_68 = 0x00000000 ;
V_69 = 0x80000000 ;
}
V_69 |= ( V_59 . V_86 << 19 ) | ( V_78 << 22 ) | ( V_78 << 16 ) ;
F_8 ( V_40 , 0x00c040 , 0xc000c000 , 0x0000c000 ) ;
F_8 ( V_40 , 0x004008 , 0x00004200 , 0x00000200 |
V_24 -> V_8 . V_25 << 14 ) ;
F_8 ( V_40 , 0x00400c , 0x0000ffff , ( V_74 << 8 ) | V_75 ) ;
F_8 ( V_40 , 0x004008 , 0x91ff0000 , V_69 ) ;
if ( V_10 -> V_13 -> V_23 >= 0x92 )
F_24 ( V_40 , 0x100da0 , V_68 ) ;
F_10 ( V_40 , 0x18 , ! V_24 -> V_8 . V_87 ) ;
F_9 ( V_40 , 64000 ) ;
F_9 ( V_40 , 32000 ) ;
F_8 ( V_40 , 0x004008 , 0x00002200 , 0x00002000 ) ;
F_24 ( V_40 , 0x1002dc , 0x00000000 ) ;
F_24 ( V_40 , 0x1002d4 , 0x00000001 ) ;
F_24 ( V_40 , 0x100210 , 0x80000000 ) ;
F_9 ( V_40 , 12000 ) ;
switch ( V_2 -> V_6 . type ) {
case V_20 :
F_29 ( V_40 , V_41 [ 0 ] ) ;
F_8 ( V_40 , V_41 [ 0 ] , 0x000 , 0x000 ) ;
break;
case V_22 :
F_29 ( V_40 , V_41 [ 1 ] ) ;
F_24 ( V_40 , V_41 [ 1 ] , V_2 -> V_6 . V_41 [ 1 ] ) ;
F_29 ( V_40 , V_41 [ 0 ] ) ;
F_24 ( V_40 , V_41 [ 0 ] , V_2 -> V_6 . V_41 [ 0 ] ) ;
break;
default:
break;
}
F_8 ( V_40 , V_3 [ 3 ] , 0xffffffff , V_3 [ 3 ] ) ;
F_8 ( V_40 , V_3 [ 1 ] , 0xffffffff , V_3 [ 1 ] ) ;
F_8 ( V_40 , V_3 [ 6 ] , 0xffffffff , V_3 [ 6 ] ) ;
F_8 ( V_40 , V_3 [ 7 ] , 0xffffffff , V_3 [ 7 ] ) ;
F_8 ( V_40 , V_3 [ 8 ] , 0xffffffff , V_3 [ 8 ] ) ;
F_8 ( V_40 , V_3 [ 0 ] , 0xffffffff , V_3 [ 0 ] ) ;
F_8 ( V_40 , V_3 [ 2 ] , 0xffffffff , V_3 [ 2 ] ) ;
F_8 ( V_40 , V_3 [ 4 ] , 0xffffffff , V_3 [ 4 ] ) ;
F_8 ( V_40 , V_3 [ 5 ] , 0xffffffff , V_3 [ 5 ] ) ;
if ( ! V_24 -> V_8 . V_82 )
F_8 ( V_40 , 0x10021c , 0x00010000 , 0x00000000 ) ;
F_8 ( V_40 , 0x100200 , 0x00001000 , ! V_24 -> V_8 . V_88 << 12 ) ;
V_70 = F_13 ( V_40 , 0x100710 ) & ~ 0x00000100 ;
V_71 = F_13 ( V_40 , 0x100714 ) & ~ 0xf0000020 ;
V_72 = F_13 ( V_40 , 0x100718 ) & ~ 0x00000100 ;
V_73 = F_13 ( V_40 , 0x10071c ) & ~ 0x00000100 ;
if ( V_10 -> V_13 -> V_23 <= 0x96 ) {
V_70 &= ~ 0x0000006e ;
V_71 &= ~ 0x00000100 ;
if ( ! V_24 -> V_8 . V_89 )
V_70 |= 0x00000060 ;
if ( ! V_24 -> V_8 . V_87 )
V_71 |= 0x00000100 ;
if ( V_24 -> V_8 . V_90 )
V_70 |= 0x0000000e ;
} else {
V_70 &= ~ 0x00000001 ;
if ( ! V_24 -> V_8 . V_89 )
V_70 |= 0x00000001 ;
}
if ( V_24 -> V_8 . V_91 )
V_73 |= 0x00000100 ;
if ( V_24 -> V_8 . V_82 )
V_70 |= 0x00000100 ;
if ( ! V_24 -> V_8 . V_89 )
V_71 |= 0x00000020 ;
if ( V_24 -> V_8 . V_90 )
V_71 |= 0x70000000 ;
if ( V_24 -> V_8 . V_92 )
V_72 |= 0x00000100 ;
F_8 ( V_40 , 0x100714 , 0xffffffff , V_71 ) ;
F_8 ( V_40 , 0x10071c , 0xffffffff , V_73 ) ;
F_8 ( V_40 , 0x100718 , 0xffffffff , V_72 ) ;
F_8 ( V_40 , 0x100710 , 0xffffffff , V_70 ) ;
if ( V_24 -> V_8 . V_93 ) {
F_24 ( V_40 , 0x1005a0 , V_24 -> V_8 . V_94 << 16 |
V_24 -> V_8 . V_95 << 8 |
V_24 -> V_8 . V_96 ) ;
F_24 ( V_40 , 0x1005a4 , V_24 -> V_8 . V_97 << 8 |
V_24 -> V_8 . V_98 ) ;
F_8 ( V_40 , 0x10053c , 0x00001000 , 0x00000000 ) ;
} else {
F_8 ( V_40 , 0x10053c , 0x00001000 , 0x00001000 ) ;
}
F_8 ( V_40 , V_41 [ 1 ] , 0xffffffff , V_2 -> V_6 . V_41 [ 1 ] ) ;
if ( ! V_24 -> V_8 . V_83 )
F_10 ( V_40 , 0x2e , 0 ) ;
if ( ! V_24 -> V_8 . V_99 )
F_7 ( V_40 ) ;
F_25 ( V_40 , 0x10 , 0x01 ) ;
F_26 ( V_40 , 0x00 , 0x00 ) ;
F_24 ( V_40 , 0x611200 , 0x00003330 ) ;
F_24 ( V_40 , 0x002504 , 0x00000000 ) ;
if ( V_24 -> V_8 . V_100 )
F_8 ( V_40 , 0x100200 , 0x00000800 , 0x00000800 ) ;
if ( ! V_24 -> V_8 . V_25 )
F_8 ( V_40 , 0x004008 , 0x00004000 , 0x00000000 ) ;
if ( V_24 -> V_8 . V_82 )
F_8 ( V_40 , 0x10021c , 0x00010000 , 0x00010000 ) ;
if ( V_10 -> V_13 -> V_23 <= 0x96 && V_24 -> V_8 . V_82 )
F_8 ( V_40 , 0x100710 , 0x00000200 , 0x00000200 ) ;
return 0 ;
}
static int
F_30 ( struct V_53 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
struct V_12 * V_13 = V_2 -> V_6 . V_11 -> V_10 . V_13 ;
F_31 ( & V_2 -> V_40 , F_32 ( V_13 -> V_101 , L_10 , true ) ) ;
return 0 ;
}
static void
F_33 ( struct V_53 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
F_31 ( & V_2 -> V_40 , false ) ;
}
void
F_34 ( struct V_53 * V_2 , struct V_102 * V_103 )
{
struct V_104 * V_24 = V_103 -> V_103 ;
struct V_104 * V_105 ;
while ( ( V_105 = V_24 ) ) {
V_24 = V_105 -> V_24 ;
F_35 ( & V_2 -> V_106 , & V_105 ) ;
}
F_35 ( & V_2 -> V_107 , & V_103 -> V_42 ) ;
}
void
F_36 ( struct V_53 * V_2 , struct V_102 * * V_108 )
{
struct V_102 * V_103 = * V_108 ;
* V_108 = NULL ;
if ( F_37 ( V_103 == NULL ) )
return;
F_38 ( & V_2 -> V_11 -> V_10 . V_109 ) ;
F_34 ( V_2 , V_103 ) ;
F_39 ( & V_2 -> V_11 -> V_10 . V_109 ) ;
F_40 ( V_103 ) ;
}
int
F_41 ( struct V_53 * V_2 , T_3 V_66 , T_1 V_110 , T_1 V_111 ,
T_1 V_112 , struct V_102 * * V_108 )
{
struct V_113 * V_114 = & V_2 -> V_106 ;
struct V_113 * V_107 = & V_2 -> V_107 ;
struct V_104 * * V_105 , * V_115 ;
struct V_102 * V_103 ;
int V_116 = ( V_112 & 0x300 ) >> 8 ;
int type = ( V_112 & 0x07f ) ;
int V_117 = ( V_112 & 0x800 ) ;
int V_118 , V_119 , V_51 ;
V_119 = ( V_66 >> V_120 ) ;
V_118 = V_111 ? ( V_111 >> V_120 ) : V_119 ;
V_110 >>= V_120 ;
V_103 = F_42 ( sizeof( * V_103 ) , V_121 ) ;
if ( ! V_103 )
return - V_122 ;
F_38 ( & V_2 -> V_11 -> V_10 . V_109 ) ;
if ( V_116 ) {
if ( V_110 == ( 1 << ( 16 - V_120 ) ) ) {
int V_123 = ( V_119 >> 4 ) * V_116 ;
V_51 = F_43 ( V_107 , 0 , 1 , V_123 , V_123 , 1 , & V_103 -> V_42 ) ;
if ( V_51 )
V_103 -> V_42 = NULL ;
}
if ( F_37 ( ! V_103 -> V_42 ) )
V_116 = 0 ;
}
V_103 -> V_112 = ( V_116 << 7 ) | type ;
V_103 -> V_66 = V_119 ;
type = V_124 [ type ] ;
V_105 = & V_103 -> V_103 ;
do {
if ( V_117 )
V_51 = F_44 ( V_114 , 0 , type , V_119 , V_118 , V_110 , & V_115 ) ;
else
V_51 = F_43 ( V_114 , 0 , type , V_119 , V_118 , V_110 , & V_115 ) ;
if ( V_51 ) {
F_39 ( & V_2 -> V_11 -> V_10 . V_109 ) ;
V_2 -> V_47 -> V_125 ( V_2 , & V_103 ) ;
return V_51 ;
}
* V_105 = V_115 ;
V_105 = & V_115 -> V_24 ;
V_119 -= V_115 -> V_126 ;
} while ( V_119 );
F_39 ( & V_2 -> V_11 -> V_10 . V_109 ) ;
V_103 -> V_127 = ( T_3 ) V_103 -> V_103 -> V_127 << V_120 ;
* V_108 = V_103 ;
return 0 ;
}
static T_1
F_45 ( struct V_53 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 -> V_10 ;
struct V_12 * V_13 = V_10 -> V_13 ;
int V_128 , V_129 , V_130 , V_131 ;
T_3 V_132 , V_133 ;
T_1 V_134 , V_135 , V_136 , V_137 ;
V_134 = F_2 ( V_13 , 0x100200 ) ;
V_135 = F_2 ( V_13 , 0x100204 ) ;
V_136 = F_2 ( V_13 , 0x100250 ) ;
F_5 ( V_10 , L_11 ,
V_134 , V_135 , V_136 , F_2 ( V_13 , 0x001540 ) ) ;
V_128 = ( V_135 & 0x0000f000 ) >> 12 ;
V_129 = ( ( V_135 & 0x000f0000 ) >> 16 ) + 8 ;
V_130 = ( ( V_135 & 0x00f00000 ) >> 20 ) + 8 ;
V_131 = 1 << ( ( ( V_135 & 0x03000000 ) >> 24 ) + 2 ) ;
V_132 = V_2 -> V_138 * V_131 * ( 1 << V_128 ) * 8 ;
V_133 = V_132 << V_129 ;
if ( V_134 & 0x00000004 )
V_133 += V_132 << V_130 ;
if ( V_133 != V_2 -> V_66 ) {
F_46 ( V_10 , L_12 ,
( T_1 ) ( V_2 -> V_66 >> 20 ) ) ;
}
V_137 = V_132 ;
if ( V_136 & 1 )
V_137 *= 3 ;
F_5 ( V_10 , L_13 , V_137 ) ;
return V_137 ;
}
int
F_47 ( const struct V_139 * V_47 ,
struct V_140 * V_11 , struct V_53 * V_2 )
{
struct V_12 * V_13 = V_11 -> V_10 . V_13 ;
struct V_55 * V_8 = V_13 -> V_8 ;
const T_1 V_141 = ( 256 * 1024 ) ;
const T_1 V_142 = ( 1024 * 1024 ) ;
T_3 V_66 = F_2 ( V_13 , 0x10020c ) ;
T_1 V_107 = F_2 ( V_13 , 0x100320 ) ;
enum V_143 type = V_144 ;
int V_51 ;
switch ( F_2 ( V_13 , 0x100714 ) & 0x00000007 ) {
case 0 : type = V_145 ; break;
case 1 :
if ( F_48 ( V_8 ) == V_146 )
type = V_146 ;
else
type = V_20 ;
break;
case 2 : type = V_22 ; break;
case 3 : type = V_147 ; break;
case 4 : type = V_148 ; break;
default:
break;
}
V_66 = ( V_66 & 0x000000ff ) << 32 | ( V_66 & 0xffffff00 ) ;
V_51 = F_49 ( V_47 , V_11 , type , V_66 , V_107 , V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_149 = ( F_2 ( V_13 , 0x001540 ) & 0x00ff0000 ) >> 16 ;
V_2 -> V_138 = F_50 ( V_2 -> V_149 ) ;
V_2 -> V_150 = ( F_2 ( V_13 , 0x100200 ) & 0x4 ) ? 2 : 1 ;
F_51 ( & V_2 -> V_106 ) ;
return F_52 ( & V_2 -> V_106 , V_141 >> V_120 ,
( V_66 - V_141 - V_142 ) >> V_120 ,
F_45 ( V_2 ) >> V_120 ) ;
}
int
F_53 ( struct V_140 * V_11 , struct V_53 * * V_151 )
{
struct V_1 * V_2 ;
int V_51 , V_36 ;
if ( ! ( V_2 = F_42 ( sizeof( * V_2 ) , V_121 ) ) )
return - V_122 ;
* V_151 = & V_2 -> V_6 ;
V_51 = F_47 ( & V_152 , V_11 , & V_2 -> V_6 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_40 . V_153 = F_54 ( 0x002504 ) ;
V_2 -> V_40 . V_154 = F_54 ( 0x00c040 ) ;
V_2 -> V_40 . V_155 = F_54 ( 0x004008 ) ;
V_2 -> V_40 . V_156 = F_54 ( 0x00400c ) ;
V_2 -> V_40 . V_157 = F_54 ( 0x100200 ) ;
V_2 -> V_40 . V_158 = F_54 ( 0x100210 ) ;
V_2 -> V_40 . V_159 = F_54 ( 0x10021c ) ;
V_2 -> V_40 . V_160 = F_54 ( 0x1002d0 ) ;
V_2 -> V_40 . V_161 = F_54 ( 0x1002d4 ) ;
V_2 -> V_40 . V_162 = F_54 ( 0x1002dc ) ;
V_2 -> V_40 . V_163 = F_54 ( 0x10053c ) ;
V_2 -> V_40 . V_164 = F_54 ( 0x1005a0 ) ;
V_2 -> V_40 . V_165 = F_54 ( 0x1005a4 ) ;
V_2 -> V_40 . V_166 = F_54 ( 0x100710 ) ;
V_2 -> V_40 . V_167 = F_54 ( 0x100714 ) ;
V_2 -> V_40 . V_168 = F_54 ( 0x100718 ) ;
V_2 -> V_40 . V_169 = F_54 ( 0x10071c ) ;
V_2 -> V_40 . V_170 = F_55 ( 0x100da0 , 4 , V_2 -> V_6 . V_149 ) ;
V_2 -> V_40 . V_171 = F_54 ( 0x100e20 ) ;
V_2 -> V_40 . V_172 = F_54 ( 0x100e24 ) ;
V_2 -> V_40 . V_173 = F_54 ( 0x611200 ) ;
for ( V_36 = 0 ; V_36 < 9 ; V_36 ++ )
V_2 -> V_40 . V_174 [ V_36 ] = F_54 ( 0x100220 + ( V_36 * 0x04 ) ) ;
if ( V_2 -> V_6 . V_150 > 1 ) {
V_2 -> V_40 . V_175 [ 0 ] = F_56 ( 0x1002c0 , 0x1002c8 ) ;
V_2 -> V_40 . V_175 [ 1 ] = F_56 ( 0x1002c4 , 0x1002cc ) ;
V_2 -> V_40 . V_175 [ 2 ] = F_56 ( 0x1002e0 , 0x1002e8 ) ;
V_2 -> V_40 . V_175 [ 3 ] = F_56 ( 0x1002e4 , 0x1002ec ) ;
} else {
V_2 -> V_40 . V_175 [ 0 ] = F_54 ( 0x1002c0 ) ;
V_2 -> V_40 . V_175 [ 1 ] = F_54 ( 0x1002c4 ) ;
V_2 -> V_40 . V_175 [ 2 ] = F_54 ( 0x1002e0 ) ;
V_2 -> V_40 . V_175 [ 3 ] = F_54 ( 0x1002e4 ) ;
}
V_2 -> V_40 . V_176 [ 0 ] = F_54 ( 0x00e104 ) ;
V_2 -> V_40 . V_176 [ 1 ] = F_54 ( 0x00e108 ) ;
V_2 -> V_40 . V_176 [ 2 ] = F_54 ( 0x00e120 ) ;
V_2 -> V_40 . V_176 [ 3 ] = F_54 ( 0x00e124 ) ;
return 0 ;
}
