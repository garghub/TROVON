static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
struct {
T_1 V_14 ;
T_2 V_15 ;
} V_16 , V_17 ;
T_2 V_18 , V_19 , V_20 , V_21 , V_22 ;
int V_23 , V_24 , V_25 , V_26 , V_27 ;
int V_28 , V_29 ;
V_29 = 0 ;
do {
V_16 . V_14 = F_2 ( V_5 , V_29 ++ , & V_18 , & V_19 , & V_20 ,
& V_16 . V_15 , & V_11 ) ;
if ( ! V_16 . V_14 || ( V_18 < 0x25 || V_18 >= 0x40 ) ||
( V_16 . V_15 < 2 ) ) {
F_3 ( V_2 , L_1 ) ;
return - V_30 ;
}
} while ( V_11 . V_31 < V_3 );
V_22 = F_4 ( V_5 ) ;
if ( V_22 >= V_20 ) {
F_3 ( V_2 , L_2 ) ;
return - V_30 ;
}
V_16 . V_14 += V_19 + ( V_22 * V_16 . V_15 ) ;
V_22 = F_5 ( V_5 , V_16 . V_14 + 0x01 ) ;
if ( V_22 != 0xff ) {
V_17 . V_14 = F_6 ( V_5 , V_22 , & V_18 , & V_19 ,
& V_20 , & V_21 ) ;
if ( ! V_17 . V_14 || V_18 != 0x10 || V_19 < 0x12 ) {
F_3 ( V_2 , L_3
L_4 ,
V_22 , V_17 . V_14 , V_18 , V_19 ) ;
return - V_30 ;
}
} else {
V_17 . V_14 = 0 ;
}
V_28 = F_7 ( V_9 , F_8 ( V_2 ) ) ;
if ( V_28 )
return V_28 ;
F_9 ( V_9 , 0x01 , 0x00 ) ;
F_9 ( V_9 , 0x01 , 0x01 ) ;
F_10 ( V_9 , 0x611200 , 0x00003300 ) ;
F_10 ( V_9 , 0x002504 , 0x00000001 ) ;
F_11 ( V_9 , 8000 ) ;
F_12 ( V_9 , 0x10 , 0x00 ) ;
F_9 ( V_9 , 0x00 , 0x01 ) ;
F_10 ( V_9 , 0x1002d4 , 0x00000001 ) ;
F_10 ( V_9 , 0x1002d0 , 0x00000001 ) ;
F_10 ( V_9 , 0x1002d0 , 0x00000001 ) ;
F_10 ( V_9 , 0x100210 , 0x00000000 ) ;
F_10 ( V_9 , 0x1002dc , 0x00000001 ) ;
V_28 = F_13 ( V_5 , 0x004008 , & V_13 ) ;
V_13 . V_32 . V_33 = 0 ;
if ( V_28 == 0 ) {
V_28 = F_14 ( F_8 ( V_2 ) , & V_13 , V_3 ,
& V_23 , & V_24 , & V_25 , & V_26 , & V_27 ) ;
if ( V_28 == 0 )
V_28 = - V_30 ;
}
if ( V_28 < 0 )
return V_28 ;
F_15 ( V_9 , 0x00c040 , 0xc000c000 , 0x0000c000 ) ;
F_15 ( V_9 , 0x004008 , 0x00000200 , 0x00000200 ) ;
F_15 ( V_9 , 0x00400c , 0x0000ffff , ( V_23 << 8 ) | V_24 ) ;
F_15 ( V_9 , 0x004008 , 0x81ff0000 , 0x80000000 | ( V_13 . V_34 << 19 ) |
( V_27 << 22 ) | ( V_27 << 16 ) ) ;
#if V_35
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
F_15 ( V_9 , 0x100da0 [ V_29 ] , 0x00000000 , 0x00000000 ) ;
#endif
F_11 ( V_9 , 96000 ) ;
F_15 ( V_9 , 0x004008 , 0x00002200 , 0x00002000 ) ;
F_10 ( V_9 , 0x1002dc , 0x00000000 ) ;
F_10 ( V_9 , 0x100210 , 0x80000000 ) ;
F_11 ( V_9 , 12000 ) ;
switch ( V_7 -> V_36 . type ) {
case V_37 :
F_16 ( V_9 , V_38 [ 0 ] ) ;
F_15 ( V_9 , V_38 [ 0 ] , 0x000 , 0x000 ) ;
break;
case V_39 :
F_15 ( V_9 , V_38 [ 2 ] , 0x000 , 0x000 ) ;
F_16 ( V_9 , V_38 [ 0 ] ) ;
F_15 ( V_9 , V_38 [ 0 ] , 0x000 , 0x000 ) ;
break;
default:
break;
}
F_15 ( V_9 , V_17 [ 3 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 1 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 6 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 7 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 8 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 0 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 2 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 4 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 5 ] , 0x00000000 , 0x00000000 ) ;
F_15 ( V_9 , V_17 [ 0 ] , 0x00000000 , 0x00000000 ) ;
#if V_35
F_16 ( V_9 , 0x100e24 ) ;
F_15 ( V_9 , 0x100e24 , 0x00000000 , 0x00000000 ) ;
F_16 ( V_9 , 0x100e20 ) ;
F_15 ( V_9 , 0x100e20 , 0x00000000 , 0x00000000 ) ;
#endif
F_15 ( V_9 , V_38 [ 0 ] , 0x100 , 0x100 ) ;
F_15 ( V_9 , V_38 [ 0 ] , 0x100 , 0x000 ) ;
F_12 ( V_9 , 0x10 , 0x01 ) ;
F_9 ( V_9 , 0x00 , 0x00 ) ;
F_10 ( V_9 , 0x611200 , 0x00003330 ) ;
F_10 ( V_9 , 0x002504 , 0x00000000 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_18 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
F_19 ( V_9 , F_20 ( V_41 -> V_42 , L_5 , false ) ) ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
F_19 ( V_9 , false ) ;
}
void
F_22 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 ;
while ( ! F_23 ( & V_44 -> V_47 ) ) {
V_46 = F_24 ( & V_44 -> V_47 , F_25 ( * V_46 ) , V_48 ) ;
F_26 ( & V_46 -> V_48 ) ;
F_27 ( & V_2 -> V_49 , & V_46 ) ;
}
F_27 ( & V_2 -> V_50 , & V_44 -> V_51 ) ;
}
void
F_28 ( struct V_1 * V_2 , struct V_43 * * V_52 )
{
struct V_43 * V_44 = * V_52 ;
* V_52 = NULL ;
if ( F_29 ( V_44 == NULL ) )
return;
F_30 ( & V_2 -> V_36 . V_53 ) ;
F_22 ( V_2 , V_44 ) ;
F_31 ( & V_2 -> V_36 . V_53 ) ;
F_32 ( V_44 ) ;
}
int
F_33 ( struct V_1 * V_2 , T_3 V_15 , T_1 V_54 , T_1 V_55 ,
T_1 V_56 , struct V_43 * * V_52 )
{
struct V_57 * V_58 = & V_2 -> V_49 ;
struct V_57 * V_50 = & V_2 -> V_50 ;
struct V_45 * V_59 ;
struct V_43 * V_44 ;
int V_60 = ( V_56 & 0x300 ) >> 8 ;
int type = ( V_56 & 0x07f ) ;
int V_61 = ( V_56 & 0x800 ) ;
int V_62 , V_63 , V_28 ;
V_63 = ( V_15 >> 12 ) ;
V_62 = V_55 ? ( V_55 >> 12 ) : V_63 ;
V_54 >>= 12 ;
V_44 = F_34 ( sizeof( * V_44 ) , V_64 ) ;
if ( ! V_44 )
return - V_65 ;
F_30 ( & V_2 -> V_36 . V_53 ) ;
if ( V_60 ) {
if ( V_54 == 16 ) {
int V_66 = ( V_63 >> 4 ) * V_60 ;
V_28 = F_35 ( V_50 , 1 , V_66 , V_66 , 1 , & V_44 -> V_51 ) ;
if ( V_28 )
V_44 -> V_51 = NULL ;
}
if ( F_29 ( ! V_44 -> V_51 ) )
V_60 = 0 ;
}
F_36 ( & V_44 -> V_47 ) ;
V_44 -> V_56 = ( V_60 << 7 ) | type ;
V_44 -> V_15 = V_63 ;
type = V_67 [ type ] ;
do {
if ( V_61 )
V_28 = F_37 ( V_58 , type , V_63 , V_62 , V_54 , & V_59 ) ;
else
V_28 = F_35 ( V_58 , type , V_63 , V_62 , V_54 , & V_59 ) ;
if ( V_28 ) {
F_31 ( & V_2 -> V_36 . V_53 ) ;
V_2 -> V_7 -> V_68 ( V_2 , & V_44 ) ;
return V_28 ;
}
F_38 ( & V_59 -> V_48 , & V_44 -> V_47 ) ;
V_63 -= V_59 -> V_69 ;
} while ( V_63 );
F_31 ( & V_2 -> V_36 . V_53 ) ;
V_59 = F_24 ( & V_44 -> V_47 , struct V_45 , V_48 ) ;
V_44 -> V_70 = ( T_3 ) V_59 -> V_70 << 12 ;
* V_52 = V_44 ;
return 0 ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_71 * V_7 )
{
int V_29 , V_72 , V_73 , V_74 , V_75 , V_76 ;
T_3 V_77 , V_78 ;
T_1 V_79 , V_80 , V_81 , V_82 , V_83 ;
V_79 = F_40 ( V_2 , 0x100200 ) ;
V_80 = F_40 ( V_2 , 0x100204 ) ;
V_81 = F_40 ( V_2 , 0x100250 ) ;
V_82 = F_40 ( V_2 , 0x001540 ) ;
F_41 ( V_2 , L_6 , V_79 , V_80 , V_81 , V_82 ) ;
for ( V_29 = 0 , V_72 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( V_82 & ( 0x00010000 << V_29 ) )
V_72 ++ ;
}
V_73 = ( V_80 & 0x0000f000 ) >> 12 ;
V_74 = ( ( V_80 & 0x000f0000 ) >> 16 ) + 8 ;
V_75 = ( ( V_80 & 0x00f00000 ) >> 20 ) + 8 ;
V_76 = 1 << ( ( ( V_80 & 0x03000000 ) >> 24 ) + 2 ) ;
V_77 = V_72 * V_76 * ( 1 << V_73 ) * 8 ;
V_78 = V_77 << V_74 ;
if ( V_79 & 0x00000004 )
V_78 += V_77 << V_75 ;
if ( V_78 != V_7 -> V_15 ) {
F_42 ( V_2 , L_7 ,
( T_1 ) ( V_7 -> V_15 >> 20 ) ) ;
}
V_83 = V_77 ;
if ( V_81 & 1 )
V_83 *= 3 ;
F_41 ( V_2 , L_8 , V_83 ) ;
return V_83 ;
}
int
F_43 ( struct V_84 * V_85 , struct V_84 * V_86 ,
struct V_87 * V_88 , int V_69 , void * * V_89 )
{
const T_1 V_90 = ( 256 * 1024 ) >> 12 ;
const T_1 V_91 = ( 1024 * 1024 ) >> 12 ;
struct V_4 * V_5 = V_4 ( V_85 ) ;
struct V_1 * V_2 = V_1 ( V_85 ) ;
struct V_71 * V_7 ;
int V_28 ;
V_28 = F_44 ( V_85 , V_86 , V_88 , V_69 , V_89 ) ;
V_7 = * V_89 ;
if ( V_28 )
return V_28 ;
V_7 -> V_15 = F_40 ( V_2 , 0x10020c ) ;
V_7 -> V_15 = ( V_7 -> V_15 & 0xffffff00 ) | ( ( V_7 -> V_15 & 0x000000ff ) << 32 ) ;
switch ( F_40 ( V_2 , 0x100714 ) & 0x00000007 ) {
case 0 : V_7 -> type = V_92 ; break;
case 1 :
if ( F_45 ( V_5 ) == V_93 )
V_7 -> type = V_93 ;
else
V_7 -> type = V_37 ;
break;
case 2 : V_7 -> type = V_39 ; break;
case 3 : V_7 -> type = V_94 ; break;
case 4 : V_7 -> type = V_95 ; break;
default:
break;
}
V_28 = F_46 ( & V_2 -> V_49 , V_90 , ( V_7 -> V_15 >> 12 ) -
( V_90 + V_91 ) ,
F_39 ( V_2 , V_7 ) >> 12 ) ;
if ( V_28 )
return V_28 ;
V_7 -> V_96 = ( F_40 ( V_2 , 0x100200 ) & 0x4 ) ? 2 : 1 ;
V_7 -> V_50 = F_40 ( V_2 , 0x100320 ) ;
V_7 -> V_97 = F_33 ;
V_7 -> V_68 = F_28 ;
return 0 ;
}
static int
F_47 ( struct V_84 * V_85 , struct V_84 * V_86 ,
struct V_87 * V_88 , void * V_14 , T_1 V_98 ,
struct V_84 * * V_89 )
{
struct V_6 * V_7 ;
int V_28 , V_29 ;
V_28 = F_48 ( V_85 , V_86 , V_88 , & V_7 ) ;
* V_89 = F_49 ( V_7 ) ;
if ( V_28 )
return V_28 ;
switch ( V_7 -> V_36 . type ) {
case V_37 :
case V_39 :
V_7 -> V_36 . V_99 = F_1 ;
V_7 -> V_36 . V_100 = F_17 ;
V_7 -> V_36 . V_101 = F_21 ;
break;
default:
F_42 ( V_7 , L_9 ) ;
return 0 ;
}
V_7 -> V_9 . V_102 = F_50 ( 0x002504 ) ;
V_7 -> V_9 . V_103 = F_50 ( 0x00c040 ) ;
V_7 -> V_9 . V_104 = F_50 ( 0x004008 ) ;
V_7 -> V_9 . V_105 = F_50 ( 0x00400c ) ;
V_7 -> V_9 . V_106 = F_50 ( 0x100210 ) ;
V_7 -> V_9 . V_107 = F_50 ( 0x1002d0 ) ;
V_7 -> V_9 . V_108 = F_50 ( 0x1002d4 ) ;
V_7 -> V_9 . V_109 = F_50 ( 0x1002dc ) ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_7 -> V_9 . V_110 [ V_29 ] = F_50 ( 0x100da0 + ( V_29 * 0x04 ) ) ;
V_7 -> V_9 . V_111 = F_50 ( 0x100e20 ) ;
V_7 -> V_9 . V_112 = F_50 ( 0x100e24 ) ;
V_7 -> V_9 . V_113 = F_50 ( 0x611200 ) ;
for ( V_29 = 0 ; V_29 < 9 ; V_29 ++ )
V_7 -> V_9 . V_114 [ V_29 ] = F_50 ( 0x100220 + ( V_29 * 0x04 ) ) ;
if ( V_7 -> V_36 . V_96 > 1 ) {
V_7 -> V_9 . V_115 [ 0 ] = F_51 ( 0x1002c0 , 0x1002c8 ) ;
V_7 -> V_9 . V_115 [ 1 ] = F_51 ( 0x1002c4 , 0x1002cc ) ;
V_7 -> V_9 . V_115 [ 2 ] = F_51 ( 0x1002e0 , 0x1002e8 ) ;
V_7 -> V_9 . V_115 [ 3 ] = F_51 ( 0x1002e4 , 0x1002ec ) ;
} else {
V_7 -> V_9 . V_115 [ 0 ] = F_50 ( 0x1002c0 ) ;
V_7 -> V_9 . V_115 [ 1 ] = F_50 ( 0x1002c4 ) ;
V_7 -> V_9 . V_115 [ 2 ] = F_50 ( 0x1002e0 ) ;
V_7 -> V_9 . V_115 [ 3 ] = F_50 ( 0x1002e4 ) ;
}
return 0 ;
}
