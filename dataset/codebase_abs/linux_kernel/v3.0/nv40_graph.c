static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
int V_10 ;
V_9 = F_2 ( V_3 , V_11 ) ;
if ( ! ( V_9 & V_12 ) )
return NULL ;
V_9 = ( V_9 & V_13 ) << 4 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_14 . V_15 . V_16 ; V_10 ++ ) {
if ( ! V_5 -> V_16 . V_17 [ V_10 ] )
continue;
V_8 = V_5 -> V_16 . V_17 [ V_10 ] -> V_18 [ V_19 ] ;
if ( V_8 && V_8 -> V_20 == V_9 )
return V_5 -> V_16 . V_17 [ V_10 ] ;
}
return NULL ;
}
static int
F_3 ( struct V_2 * V_3 , T_1 V_9 , int V_21 )
{
T_1 V_22 , V_23 = 1000 , V_24 ;
int V_10 ;
V_22 = F_2 ( V_3 , V_25 ) ;
F_4 ( V_3 , V_25 , V_9 ) ;
V_24 = F_2 ( V_3 , V_26 ) ;
V_24 |= V_21 ? V_27 :
V_28 ;
F_4 ( V_3 , V_26 , V_24 ) ;
V_24 = F_2 ( V_3 , V_29 ) ;
V_24 |= V_30 ;
F_4 ( V_3 , V_29 , V_24 ) ;
F_5 ( V_3 ) ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
if ( F_2 ( V_3 , V_31 ) == 0 )
break;
}
F_4 ( V_3 , V_25 , V_22 ) ;
if ( V_10 == V_23 ) {
T_1 V_32 = F_2 ( V_3 , V_33 ) ;
F_6 ( V_3 , L_1 , V_9 , V_21 ) ;
F_6 ( V_3 , L_2 ,
V_32 >> V_34 ,
V_32 & V_35 ) ;
F_6 ( V_3 , L_3 ,
F_2 ( V_3 , V_31 ) ) ;
return - V_36 ;
}
return 0 ;
}
static int
F_7 ( struct V_2 * V_3 )
{
T_1 V_9 ;
int V_37 ;
V_9 = F_2 ( V_3 , V_11 ) ;
if ( ! ( V_9 & V_12 ) )
return 0 ;
V_9 &= V_13 ;
V_37 = F_3 ( V_3 , V_9 , 1 ) ;
F_4 ( V_3 , V_11 , V_9 ) ;
return V_37 ;
}
static int
F_8 ( struct V_1 * V_38 , int V_14 )
{
struct V_39 * V_40 = F_9 ( V_38 -> V_3 , V_14 ) ;
struct V_2 * V_3 = V_38 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = NULL ;
struct V_41 V_42 = {} ;
unsigned long V_43 ;
int V_37 ;
V_37 = F_10 ( V_3 , NULL , V_40 -> V_44 , 16 ,
V_45 , & V_8 ) ;
if ( V_37 )
return V_37 ;
V_42 . V_3 = V_38 -> V_3 ;
V_42 . V_46 = V_47 ;
V_42 . V_48 = V_8 ;
F_11 ( & V_42 ) ;
F_12 ( V_8 , 0 , V_8 -> V_49 ) ;
F_13 ( & V_5 -> V_50 , V_43 ) ;
F_12 ( V_38 -> V_51 , 0x38 , V_8 -> V_49 >> 4 ) ;
F_14 ( V_3 , 0x002500 , 0x00000001 , 0x00000000 ) ;
if ( ( F_2 ( V_3 , 0x003204 ) & 0x0000001f ) == V_38 -> V_52 )
F_4 ( V_3 , 0x0032e0 , V_8 -> V_49 >> 4 ) ;
F_14 ( V_3 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_15 ( & V_5 -> V_50 , V_43 ) ;
V_38 -> V_18 [ V_14 ] = V_8 ;
return 0 ;
}
static void
F_16 ( struct V_1 * V_38 , int V_14 )
{
struct V_7 * V_8 = V_38 -> V_18 [ V_14 ] ;
struct V_2 * V_3 = V_38 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_43 ;
F_13 ( & V_5 -> V_50 , V_43 ) ;
F_17 ( V_3 , false ) ;
if ( F_1 ( V_3 ) == V_38 )
F_7 ( V_3 ) ;
F_17 ( V_3 , true ) ;
F_15 ( & V_5 -> V_50 , V_43 ) ;
F_18 ( NULL , & V_8 ) ;
V_38 -> V_18 [ V_14 ] = NULL ;
}
int
F_19 ( struct V_1 * V_38 , int V_14 ,
T_2 V_53 , T_3 V_54 )
{
struct V_2 * V_3 = V_38 -> V_3 ;
struct V_7 * V_55 = NULL ;
int V_37 ;
V_37 = F_10 ( V_3 , V_38 , 20 , 16 , V_56 , & V_55 ) ;
if ( V_37 )
return V_37 ;
V_55 -> V_14 = 1 ;
V_55 -> V_54 = V_54 ;
F_12 ( V_55 , 0x00 , V_54 ) ;
F_12 ( V_55 , 0x04 , 0x00000000 ) ;
#ifndef F_20
F_12 ( V_55 , 0x08 , 0x00000000 ) ;
#else
F_12 ( V_55 , 0x08 , 0x01000000 ) ;
#endif
F_12 ( V_55 , 0x0c , 0x00000000 ) ;
F_12 ( V_55 , 0x10 , 0x00000000 ) ;
V_37 = F_21 ( V_38 , V_53 , V_55 ) ;
F_18 ( NULL , & V_55 ) ;
return V_37 ;
}
static void
F_22 ( struct V_2 * V_3 , int V_10 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_57 * V_58 = & V_5 -> V_58 . V_59 [ V_10 ] ;
switch ( V_5 -> V_60 ) {
case 0x40 :
case 0x41 :
case 0x42 :
case 0x43 :
case 0x45 :
case 0x4e :
F_4 ( V_3 , F_23 ( V_10 ) , V_58 -> V_61 ) ;
F_4 ( V_3 , F_24 ( V_10 ) , V_58 -> V_62 ) ;
F_4 ( V_3 , F_25 ( V_10 ) , V_58 -> V_63 ) ;
F_4 ( V_3 , F_26 ( V_10 ) , V_58 -> V_61 ) ;
F_4 ( V_3 , F_27 ( V_10 ) , V_58 -> V_62 ) ;
F_4 ( V_3 , F_28 ( V_10 ) , V_58 -> V_63 ) ;
break;
case 0x44 :
case 0x4a :
F_4 ( V_3 , F_23 ( V_10 ) , V_58 -> V_61 ) ;
F_4 ( V_3 , F_24 ( V_10 ) , V_58 -> V_62 ) ;
F_4 ( V_3 , F_25 ( V_10 ) , V_58 -> V_63 ) ;
break;
case 0x46 :
case 0x47 :
case 0x49 :
case 0x4b :
case 0x4c :
case 0x67 :
default:
F_4 ( V_3 , F_29 ( V_10 ) , V_58 -> V_61 ) ;
F_4 ( V_3 , F_30 ( V_10 ) , V_58 -> V_62 ) ;
F_4 ( V_3 , F_31 ( V_10 ) , V_58 -> V_63 ) ;
F_4 ( V_3 , F_26 ( V_10 ) , V_58 -> V_61 ) ;
F_4 ( V_3 , F_27 ( V_10 ) , V_58 -> V_62 ) ;
F_4 ( V_3 , F_28 ( V_10 ) , V_58 -> V_63 ) ;
break;
}
}
int
F_32 ( struct V_2 * V_3 , int V_14 )
{
struct V_39 * V_40 = F_9 ( V_3 , V_14 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_64 * V_65 = & V_5 -> V_14 . V_66 ;
struct V_41 V_42 = {} ;
T_1 V_67 , * V_68 ;
int V_10 , V_69 ;
F_4 ( V_3 , V_70 , F_2 ( V_3 , V_70 ) &
~ V_71 ) ;
F_4 ( V_3 , V_70 , F_2 ( V_3 , V_70 ) |
V_71 ) ;
V_68 = F_33 ( sizeof( * V_68 ) * 256 , V_72 ) ;
if ( ! V_68 )
return - V_73 ;
V_42 . V_3 = V_3 ;
V_42 . V_46 = V_74 ;
V_42 . V_48 = V_68 ;
V_42 . V_75 = 256 ;
F_11 ( & V_42 ) ;
V_40 -> V_44 = V_42 . V_76 * 4 ;
F_4 ( V_3 , V_77 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_42 . V_78 ; V_10 ++ )
F_4 ( V_3 , V_79 , V_68 [ V_10 ] ) ;
F_34 ( V_68 ) ;
F_4 ( V_3 , V_11 , 0x00000000 ) ;
F_4 ( V_3 , V_80 , 0xFFFFFFFF ) ;
F_4 ( V_3 , V_81 , 0xFFFFFFFF ) ;
F_4 ( V_3 , V_82 , 0xFFFFFFFF ) ;
F_4 ( V_3 , V_82 , 0x00000000 ) ;
F_4 ( V_3 , V_83 , 0x401287c0 ) ;
F_4 ( V_3 , V_84 , 0xe0de8055 ) ;
F_4 ( V_3 , V_85 , 0x00008000 ) ;
F_4 ( V_3 , V_86 , 0x00be3c5f ) ;
F_4 ( V_3 , V_87 , 0x10010100 ) ;
F_4 ( V_3 , V_88 , 0xFFFFFFFF ) ;
V_69 = F_2 ( V_3 , 0x1540 ) & 0xff ;
if ( V_69 ) {
for ( V_10 = 0 ; ! ( V_69 & 1 ) ; V_69 >>= 1 , V_10 ++ )
;
F_4 ( V_3 , 0x405000 , V_10 ) ;
}
if ( V_5 -> V_60 == 0x40 ) {
F_4 ( V_3 , 0x4009b0 , 0x83280fff ) ;
F_4 ( V_3 , 0x4009b4 , 0x000000a0 ) ;
} else {
F_4 ( V_3 , 0x400820 , 0x83280eff ) ;
F_4 ( V_3 , 0x400824 , 0x000000a0 ) ;
}
switch ( V_5 -> V_60 ) {
case 0x40 :
case 0x45 :
F_4 ( V_3 , 0x4009b8 , 0x0078e366 ) ;
F_4 ( V_3 , 0x4009bc , 0x0000014c ) ;
break;
case 0x41 :
case 0x42 :
F_4 ( V_3 , 0x400828 , 0x007596ff ) ;
F_4 ( V_3 , 0x40082c , 0x00000108 ) ;
break;
case 0x43 :
F_4 ( V_3 , 0x400828 , 0x0072cb77 ) ;
F_4 ( V_3 , 0x40082c , 0x00000108 ) ;
break;
case 0x44 :
case 0x46 :
case 0x4a :
case 0x4c :
case 0x4e :
F_4 ( V_3 , 0x400860 , 0 ) ;
F_4 ( V_3 , 0x400864 , 0 ) ;
break;
case 0x47 :
case 0x49 :
case 0x4b :
F_4 ( V_3 , 0x400828 , 0x07830610 ) ;
F_4 ( V_3 , 0x40082c , 0x0000016A ) ;
break;
default:
break;
}
F_4 ( V_3 , 0x400b38 , 0x2ffff800 ) ;
F_4 ( V_3 , 0x400b3c , 0x00006000 ) ;
switch ( V_5 -> V_60 ) {
case 0x44 :
case 0x4a :
F_4 ( V_3 , 0x400bc4 , 0x1003d888 ) ;
F_4 ( V_3 , 0x400bbc , 0xb7a7b500 ) ;
break;
case 0x46 :
F_4 ( V_3 , 0x400bc4 , 0x0000e024 ) ;
F_4 ( V_3 , 0x400bbc , 0xb7a7b520 ) ;
break;
case 0x4c :
case 0x4e :
case 0x67 :
F_4 ( V_3 , 0x400bc4 , 0x1003d888 ) ;
F_4 ( V_3 , 0x400bbc , 0xb7a7b540 ) ;
break;
default:
break;
}
for ( V_10 = 0 ; V_10 < V_65 -> V_89 ; V_10 ++ )
F_22 ( V_3 , V_10 ) ;
V_67 = F_35 ( V_3 -> V_90 , 0 ) - 1 ;
switch ( V_5 -> V_60 ) {
case 0x40 :
F_4 ( V_3 , 0x4009A4 , F_2 ( V_3 , V_91 ) ) ;
F_4 ( V_3 , 0x4009A8 , F_2 ( V_3 , V_92 ) ) ;
F_4 ( V_3 , 0x4069A4 , F_2 ( V_3 , V_91 ) ) ;
F_4 ( V_3 , 0x4069A8 , F_2 ( V_3 , V_92 ) ) ;
F_4 ( V_3 , 0x400820 , 0 ) ;
F_4 ( V_3 , 0x400824 , 0 ) ;
F_4 ( V_3 , 0x400864 , V_67 ) ;
F_4 ( V_3 , 0x400868 , V_67 ) ;
break;
default:
switch ( V_5 -> V_60 ) {
case 0x41 :
case 0x42 :
case 0x43 :
case 0x45 :
case 0x4e :
case 0x44 :
case 0x4a :
F_4 ( V_3 , 0x4009F0 , F_2 ( V_3 , V_91 ) ) ;
F_4 ( V_3 , 0x4009F4 , F_2 ( V_3 , V_92 ) ) ;
break;
default:
F_4 ( V_3 , 0x400DF0 , F_2 ( V_3 , V_91 ) ) ;
F_4 ( V_3 , 0x400DF4 , F_2 ( V_3 , V_92 ) ) ;
break;
}
F_4 ( V_3 , 0x4069F0 , F_2 ( V_3 , V_91 ) ) ;
F_4 ( V_3 , 0x4069F4 , F_2 ( V_3 , V_92 ) ) ;
F_4 ( V_3 , 0x400840 , 0 ) ;
F_4 ( V_3 , 0x400844 , 0 ) ;
F_4 ( V_3 , 0x4008A0 , V_67 ) ;
F_4 ( V_3 , 0x4008A4 , V_67 ) ;
break;
}
return 0 ;
}
static int
F_36 ( struct V_2 * V_3 , int V_14 )
{
F_7 ( V_3 ) ;
return 0 ;
}
static int
F_37 ( struct V_2 * V_3 , T_2 V_9 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
unsigned long V_43 ;
int V_10 ;
F_13 ( & V_5 -> V_16 . V_93 , V_43 ) ;
for ( V_10 = 0 ; V_10 < V_5 -> V_14 . V_15 . V_16 ; V_10 ++ ) {
if ( ! V_5 -> V_16 . V_17 [ V_10 ] )
continue;
V_8 = V_5 -> V_16 . V_17 [ V_10 ] -> V_18 [ V_19 ] ;
if ( V_8 && V_8 -> V_20 == V_9 )
break;
}
F_15 ( & V_5 -> V_16 . V_93 , V_43 ) ;
return V_10 ;
}
static void
F_38 ( struct V_2 * V_3 )
{
T_2 V_94 ;
while ( ( V_94 = F_2 ( V_3 , V_80 ) ) ) {
T_2 V_95 = F_2 ( V_3 , V_96 ) ;
T_2 V_97 = F_2 ( V_3 , V_98 ) ;
T_2 V_9 = ( F_2 ( V_3 , 0x40032c ) & 0x000fffff ) << 4 ;
T_2 V_99 = F_37 ( V_3 , V_9 ) ;
T_2 V_63 = F_2 ( V_3 , V_100 ) ;
T_2 V_101 = ( V_63 & 0x00070000 ) >> 16 ;
T_2 V_102 = ( V_63 & 0x00001ffc ) ;
T_2 V_48 = F_2 ( V_3 , V_103 ) ;
T_2 V_54 = F_2 ( V_3 , 0x400160 + V_101 * 4 ) & 0xffff ;
T_2 V_104 = V_94 ;
if ( V_94 & V_105 ) {
if ( V_95 & V_106 ) {
if ( ! F_39 ( V_3 , V_99 , V_54 , V_102 , V_48 ) )
V_104 &= ~ V_105 ;
} else
if ( V_95 & V_107 ) {
F_14 ( V_3 , 0x402000 , 0 , 0 ) ;
}
}
F_4 ( V_3 , V_80 , V_94 ) ;
F_4 ( V_3 , V_108 , 0x00000001 ) ;
if ( V_104 && F_40 () ) {
F_41 ( V_3 , L_4 ) ;
F_42 ( V_109 , V_104 ) ;
F_43 ( L_5 ) ;
F_42 ( V_110 , V_95 ) ;
F_43 ( L_6 ) ;
F_42 ( V_111 , V_97 ) ;
F_43 ( L_7 ) ;
F_41 ( V_3 , L_8
L_9 ,
V_99 , V_9 , V_101 , V_54 , V_102 , V_48 ) ;
}
}
}
static void
F_44 ( struct V_2 * V_3 , int V_14 )
{
struct V_39 * V_40 = F_9 ( V_3 , V_14 ) ;
F_45 ( V_3 , 12 ) ;
F_46 ( V_3 , V_112 ) ;
F_34 ( V_40 ) ;
}
int
F_47 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
V_40 = F_48 ( sizeof( * V_40 ) , V_72 ) ;
if ( ! V_40 )
return - V_73 ;
V_40 -> V_113 . V_114 = F_44 ;
V_40 -> V_113 . V_115 = F_32 ;
V_40 -> V_113 . V_116 = F_36 ;
V_40 -> V_113 . V_117 = F_8 ;
V_40 -> V_113 . V_118 = F_16 ;
V_40 -> V_113 . V_119 = F_19 ;
V_40 -> V_113 . V_120 = F_22 ;
F_49 ( V_3 , V_112 , & V_40 -> V_113 ) ;
F_50 ( V_3 , 12 , F_38 ) ;
F_51 ( V_3 , 0x506e , V_121 ) ;
F_51 ( V_3 , 0x0030 , V_112 ) ;
F_51 ( V_3 , 0x0039 , V_112 ) ;
F_51 ( V_3 , 0x004a , V_112 ) ;
F_51 ( V_3 , 0x009f , V_112 ) ;
F_51 ( V_3 , 0x008a , V_112 ) ;
F_51 ( V_3 , 0x0089 , V_112 ) ;
F_51 ( V_3 , 0x3089 , V_112 ) ;
F_51 ( V_3 , 0x0062 , V_112 ) ;
F_51 ( V_3 , 0x3062 , V_112 ) ;
F_51 ( V_3 , 0x0043 , V_112 ) ;
F_51 ( V_3 , 0x0012 , V_112 ) ;
F_51 ( V_3 , 0x0072 , V_112 ) ;
F_51 ( V_3 , 0x0019 , V_112 ) ;
F_51 ( V_3 , 0x0044 , V_112 ) ;
F_51 ( V_3 , 0x309e , V_112 ) ;
if ( F_52 ( V_3 ) )
F_51 ( V_3 , 0x4497 , V_112 ) ;
else
F_51 ( V_3 , 0x4097 , V_112 ) ;
F_51 ( V_3 , 0x506e , V_121 ) ;
F_53 ( V_3 , 0x506e , 0x0500 , V_122 ) ;
return 0 ;
}
