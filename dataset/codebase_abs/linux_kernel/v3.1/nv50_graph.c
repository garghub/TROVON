static void
F_1 ( struct V_1 * V_2 , bool V_3 )
{
const T_1 V_4 = 0x00010001 ;
if ( V_3 )
F_2 ( V_2 , 0x400500 , F_3 ( V_2 , 0x400500 ) | V_4 ) ;
else
F_2 ( V_2 , 0x400500 , F_3 ( V_2 , 0x400500 ) & ~ V_4 ) ;
}
static struct V_5 *
F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 ;
int V_10 ;
if ( ! F_5 ( V_2 , 0x400300 , 0x00000001 , 0x00000000 ) )
F_6 ( V_2 , L_1 ) ;
V_9 = F_3 ( V_2 , V_11 ) ;
if ( ! ( V_9 & V_12 ) )
return NULL ;
V_9 = ( V_9 & V_13 ) << 12 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_14 . V_15 . V_16 ; V_10 ++ ) {
struct V_5 * V_17 = V_7 -> V_16 . V_18 [ V_10 ] ;
if ( V_17 && V_17 -> V_19 && V_17 -> V_19 -> V_20 == V_9 )
return V_17 ;
}
return NULL ;
}
static int
F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_15 = F_3 ( V_2 , 0x400500 ) ;
F_2 ( V_2 , 0x400500 , V_15 & ~ 1 ) ;
F_2 ( V_2 , 0x400784 , V_9 ) ;
F_2 ( V_2 , 0x400824 , F_3 ( V_2 , 0x400824 ) | 0x40 ) ;
F_2 ( V_2 , 0x400320 , F_3 ( V_2 , 0x400320 ) | 0x11 ) ;
F_2 ( V_2 , 0x400040 , 0xffffffff ) ;
( void ) F_3 ( V_2 , 0x400040 ) ;
F_2 ( V_2 , 0x400040 , 0x00000000 ) ;
F_2 ( V_2 , 0x400304 , F_3 ( V_2 , 0x400304 ) | 1 ) ;
if ( F_8 ( V_2 ) )
F_2 ( V_2 , 0x40032c , V_9 | ( 1 << 31 ) ) ;
F_2 ( V_2 , 0x400500 , V_15 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
T_1 V_9 ;
V_9 = F_3 ( V_2 , V_11 ) ;
if ( ! ( V_9 & V_12 ) )
return 0 ;
V_9 &= V_13 ;
F_8 ( V_2 ) ;
F_2 ( V_2 , 0x400784 , V_9 ) ;
F_2 ( V_2 , 0x400824 , F_3 ( V_2 , 0x400824 ) | 0x20 ) ;
F_2 ( V_2 , 0x400304 , F_3 ( V_2 , 0x400304 ) | 0x01 ) ;
F_8 ( V_2 ) ;
F_2 ( V_2 , V_11 , V_9 ) ;
return 0 ;
}
static void
F_10 ( struct V_1 * V_2 )
{
T_1 V_21 = V_22 | ( 1 << 21 ) ;
F_11 ( V_2 , L_2 ) ;
F_2 ( V_2 , V_23 , F_3 ( V_2 , V_23 ) & ~ V_21 ) ;
F_2 ( V_2 , V_23 , F_3 ( V_2 , V_23 ) | V_21 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 , L_2 ) ;
F_2 ( V_2 , V_24 , 0xffffffff ) ;
F_2 ( V_2 , 0x400138 , 0xffffffff ) ;
F_2 ( V_2 , V_25 , 0xffffffff ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_26 = F_3 ( V_2 , 0x1540 ) ;
int V_10 ;
F_11 ( V_2 , L_2 ) ;
F_2 ( V_2 , 0x400804 , 0xc0000000 ) ;
F_2 ( V_2 , 0x406800 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400c04 , 0xc0000000 ) ;
F_2 ( V_2 , 0x401800 , 0xc0000000 ) ;
F_2 ( V_2 , 0x405018 , 0xc0000000 ) ;
F_2 ( V_2 , 0x402000 , 0xc0000000 ) ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
if ( V_26 & 1 << V_10 ) {
if ( V_7 -> V_27 < 0xa0 ) {
F_2 ( V_2 , 0x408900 + ( V_10 << 12 ) , 0xc0000000 ) ;
F_2 ( V_2 , 0x408e08 + ( V_10 << 12 ) , 0xc0000000 ) ;
F_2 ( V_2 , 0x408314 + ( V_10 << 12 ) , 0xc0000000 ) ;
} else {
F_2 ( V_2 , 0x408600 + ( V_10 << 11 ) , 0xc0000000 ) ;
F_2 ( V_2 , 0x408708 + ( V_10 << 11 ) , 0xc0000000 ) ;
F_2 ( V_2 , 0x40831c + ( V_10 << 11 ) , 0xc0000000 ) ;
}
}
}
F_2 ( V_2 , 0x400108 , 0xffffffff ) ;
F_2 ( V_2 , 0x400824 , 0x00004000 ) ;
F_2 ( V_2 , 0x400500 , 0x00010001 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
F_11 ( V_2 , L_2 ) ;
switch ( V_7 -> V_27 & 0xf0 ) {
case 0x50 :
case 0x80 :
case 0x90 :
F_2 ( V_2 , 0x402ca8 , 0x00000800 ) ;
break;
case 0xa0 :
default:
F_2 ( V_2 , 0x402cc0 , 0x00000000 ) ;
if ( V_7 -> V_27 == 0xa0 ||
V_7 -> V_27 == 0xaa ||
V_7 -> V_27 == 0xac ) {
F_2 ( V_2 , 0x402ca8 , 0x00000802 ) ;
} else {
F_2 ( V_2 , 0x402cc0 , 0x00000000 ) ;
F_2 ( V_2 , 0x402ca8 , 0x00000002 ) ;
}
break;
}
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
F_2 ( V_2 , 0x402c20 + ( V_10 * 8 ) , 0x00000000 ) ;
F_2 ( V_2 , 0x402c24 + ( V_10 * 8 ) , 0x00000000 ) ;
F_2 ( V_2 , 0x402c28 + ( V_10 * 8 ) , 0x00000000 ) ;
F_2 ( V_2 , 0x402c2c + ( V_10 * 8 ) , 0x00000000 ) ;
}
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_16 ( V_2 , V_30 ) ;
int V_10 ;
F_11 ( V_2 , L_2 ) ;
F_2 ( V_2 , V_31 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_29 -> V_32 ; V_10 ++ )
F_2 ( V_2 , V_33 , V_29 -> V_34 [ V_10 ] ) ;
F_2 ( V_2 , 0x40008c , 0x00000004 ) ;
F_2 ( V_2 , 0x400320 , 4 ) ;
F_2 ( V_2 , V_35 , 0 ) ;
F_2 ( V_2 , V_36 , 0 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , int V_14 )
{
int V_37 ;
F_11 ( V_2 , L_2 ) ;
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_37 = F_15 ( V_2 ) ;
if ( V_37 )
return V_37 ;
F_12 ( V_2 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , int V_14 , bool V_38 )
{
F_19 ( V_2 , 0x400500 , 0x00010001 , 0x00000000 ) ;
if ( ! F_5 ( V_2 , 0x400700 , ~ 0 , 0 ) && V_38 ) {
F_19 ( V_2 , 0x400500 , 0x00010001 , 0x00010001 ) ;
return - V_39 ;
}
F_9 ( V_2 ) ;
F_2 ( V_2 , 0x40013c , 0x00000000 ) ;
return 0 ;
}
static int
F_20 ( struct V_5 * V_17 , int V_14 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_40 * V_19 = V_17 -> V_19 ;
struct V_40 * V_41 = NULL ;
struct V_28 * V_29 = F_16 ( V_2 , V_14 ) ;
struct V_42 V_43 = {} ;
int V_44 , V_37 ;
F_11 ( V_2 , L_3 , V_17 -> V_45 ) ;
V_37 = F_21 ( V_2 , NULL , V_29 -> V_46 , 0 ,
V_47 |
V_48 , & V_41 ) ;
if ( V_37 )
return V_37 ;
V_44 = ( V_7 -> V_27 == 0x50 ) ? 0x200 : 0x20 ;
F_22 ( V_19 , V_44 + 0x00 , 0x00190002 ) ;
F_22 ( V_19 , V_44 + 0x04 , V_41 -> V_20 + V_41 -> V_49 - 1 ) ;
F_22 ( V_19 , V_44 + 0x08 , V_41 -> V_20 ) ;
F_22 ( V_19 , V_44 + 0x0c , 0 ) ;
F_22 ( V_19 , V_44 + 0x10 , 0 ) ;
F_22 ( V_19 , V_44 + 0x14 , 0x00010000 ) ;
V_43 . V_2 = V_17 -> V_2 ;
V_43 . V_50 = V_51 ;
V_43 . V_52 = V_41 ;
F_23 ( & V_43 ) ;
F_22 ( V_41 , 0x00000 , V_17 -> V_19 -> V_20 >> 12 ) ;
V_7 -> V_14 . V_53 . V_54 ( V_2 ) ;
F_24 ( & V_17 -> V_55 -> V_56 [ V_30 ] ) ;
V_17 -> V_57 [ V_30 ] = V_41 ;
return 0 ;
}
static void
F_25 ( struct V_5 * V_17 , int V_14 )
{
struct V_40 * V_41 = V_17 -> V_57 [ V_14 ] ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_58 * V_59 = & V_7 -> V_14 . V_15 ;
int V_10 , V_44 = ( V_7 -> V_27 == 0x50 ) ? 0x200 : 0x20 ;
unsigned long V_60 ;
F_11 ( V_2 , L_3 , V_17 -> V_45 ) ;
if ( ! V_17 -> V_19 )
return;
F_26 ( & V_7 -> V_61 , V_60 ) ;
V_59 -> V_62 ( V_2 , false ) ;
F_1 ( V_2 , false ) ;
if ( F_4 ( V_2 ) == V_17 )
F_9 ( V_2 ) ;
for ( V_10 = V_44 ; V_10 < V_44 + 24 ; V_10 += 4 )
F_22 ( V_17 -> V_19 , V_10 , 0 ) ;
V_7 -> V_14 . V_53 . V_54 ( V_2 ) ;
F_1 ( V_2 , true ) ;
V_59 -> V_62 ( V_2 , true ) ;
F_27 ( & V_7 -> V_61 , V_60 ) ;
F_28 ( NULL , & V_41 ) ;
F_29 ( & V_17 -> V_55 -> V_56 [ V_14 ] ) ;
V_17 -> V_57 [ V_14 ] = NULL ;
}
static int
F_30 ( struct V_5 * V_17 , int V_14 ,
T_2 V_63 , T_3 V_64 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_40 * V_65 = NULL ;
int V_37 ;
V_37 = F_21 ( V_2 , V_17 , 16 , 16 , V_48 , & V_65 ) ;
if ( V_37 )
return V_37 ;
V_65 -> V_14 = 1 ;
V_65 -> V_64 = V_64 ;
F_22 ( V_65 , 0x00 , V_64 ) ;
F_22 ( V_65 , 0x04 , 0x00000000 ) ;
F_22 ( V_65 , 0x08 , 0x00000000 ) ;
F_22 ( V_65 , 0x0c , 0x00000000 ) ;
V_7 -> V_14 . V_53 . V_54 ( V_2 ) ;
V_37 = F_31 ( V_17 , V_63 , V_65 ) ;
F_28 ( NULL , & V_65 ) ;
return V_37 ;
}
static void
F_32 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_9 ( V_2 ) ;
V_9 = F_3 ( V_2 , V_66 ) ;
V_9 &= V_67 ;
F_7 ( V_2 , V_9 ) ;
F_2 ( V_2 , V_25 , F_3 ( V_2 ,
V_25 ) | V_68 ) ;
}
static int
F_33 ( struct V_5 * V_17 ,
T_2 V_64 , T_2 V_69 , T_2 V_52 )
{
struct V_40 * V_70 ;
V_70 = F_34 ( V_17 , V_52 ) ;
if ( ! V_70 )
return - V_71 ;
if ( F_35 ( V_70 , NULL ) )
return - V_72 ;
V_17 -> V_73 . V_74 = V_70 ;
V_17 -> V_73 . V_75 = ~ 0 ;
return 0 ;
}
static int
F_36 ( struct V_5 * V_17 ,
T_2 V_64 , T_2 V_69 , T_2 V_52 )
{
if ( F_35 ( V_17 -> V_73 . V_74 , & V_52 ) )
return - V_76 ;
V_17 -> V_73 . V_75 = V_52 >> 2 ;
return 0 ;
}
static int
F_37 ( struct V_5 * V_17 ,
T_2 V_64 , T_2 V_69 , T_2 V_52 )
{
V_17 -> V_73 . V_77 = V_52 ;
return 0 ;
}
static int
F_38 ( struct V_5 * V_17 ,
T_2 V_64 , T_2 V_69 , T_2 V_52 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_17 -> V_73 . V_74 || V_17 -> V_73 . V_75 == ~ 0 || V_52 > 1 )
return - V_72 ;
F_39 ( V_2 , V_52 ) ;
V_17 -> V_73 . V_78 = V_52 ;
F_40 ( & V_17 -> V_73 . V_79 , & V_7 -> V_80 ) ;
return 0 ;
}
static int
F_41 ( struct V_5 * V_17 ,
T_2 V_64 , T_2 V_69 , T_2 V_52 )
{
F_42 ( V_17 , NULL ) ;
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 , int V_14 )
{
F_44 ( V_2 , 0 ) ;
}
static void
F_45 ( struct V_1 * V_2 , int V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_81 * V_82 = & V_7 -> V_14 . V_83 ;
bool V_84 , V_85 = false ;
unsigned long V_60 ;
T_4 V_86 ;
T_2 V_87 ;
F_26 ( & V_7 -> V_61 , V_60 ) ;
F_19 ( V_2 , 0x400500 , 0x00000001 , 0x00000000 ) ;
V_86 = V_82 -> V_88 ( V_2 ) ;
do {
V_84 = true ;
for ( V_87 = F_3 ( V_2 , 0x400380 ) ; V_87 && V_84 ; V_87 >>= 3 ) {
if ( ( V_87 & 7 ) == 1 )
V_84 = false ;
}
for ( V_87 = F_3 ( V_2 , 0x400384 ) ; V_87 && V_84 ; V_87 >>= 3 ) {
if ( ( V_87 & 7 ) == 1 )
V_84 = false ;
}
for ( V_87 = F_3 ( V_2 , 0x400388 ) ; V_87 && V_84 ; V_87 >>= 3 ) {
if ( ( V_87 & 7 ) == 1 )
V_84 = false ;
}
} while ( ! V_84 && ! ( V_85 = V_82 -> V_88 ( V_2 ) - V_86 > 2000000000 ) );
if ( V_85 ) {
F_6 ( V_2 , L_4
L_5 ,
F_3 ( V_2 , 0x400700 ) , F_3 ( V_2 , 0x400380 ) ,
F_3 ( V_2 , 0x400384 ) , F_3 ( V_2 , 0x400388 ) ) ;
}
F_44 ( V_2 , 0 ) ;
F_19 ( V_2 , 0x400500 , 0x00000001 , 0x00000001 ) ;
F_27 ( & V_7 -> V_61 , V_60 ) ;
}
static void
F_46 ( struct V_1 * V_2 , int V_89 , int V_90 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_26 = F_3 ( V_2 , 0x1540 ) ;
T_1 V_91 , V_92 , V_93 , V_94 , V_95 , V_96 ;
int V_10 ;
int V_97 = 0 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
if ( ! ( V_26 & 1 << ( V_10 + 24 ) ) )
continue;
if ( V_7 -> V_27 < 0xa0 )
V_91 = 0x408200 + ( V_89 << 12 ) + ( V_10 << 7 ) ;
else
V_91 = 0x408100 + ( V_89 << 11 ) + ( V_10 << 7 ) ;
V_92 = F_3 ( V_2 , V_91 + 0x10 ) ;
V_93 = F_3 ( V_2 , V_91 + 0x14 ) ;
if ( ! V_93 )
continue;
if ( V_90 ) {
F_3 ( V_2 , V_91 + 0x20 ) ;
V_94 = F_3 ( V_2 , V_91 + 0x24 ) ;
V_95 = F_3 ( V_2 , V_91 + 0x70 ) ;
V_96 = F_3 ( V_2 , V_91 + 0x74 ) ;
F_47 ( V_2 , L_6
L_7 , V_89 , V_10 ) ;
F_48 ( V_98 , V_93 ) ;
F_49 ( L_8 ,
V_94 & 0xffffff , V_94 >> 24 ,
V_95 , V_96 ) ;
}
F_2 ( V_2 , V_91 + 0x10 , V_92 ) ;
F_2 ( V_2 , V_91 + 0x14 , 0 ) ;
V_97 ++ ;
}
if ( ! V_97 && V_90 )
F_47 ( V_2 , L_9
L_10 , V_89 ) ;
}
static void
F_50 ( struct V_1 * V_2 , int type , T_1 V_99 ,
T_1 V_100 , int V_90 , const char * V_101 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_102 = 0 ;
T_1 V_26 = F_3 ( V_2 , 0x1540 ) ;
int V_10 , V_103 ;
T_1 V_104 , V_105 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
if ( ! ( V_26 & ( 1 << V_10 ) ) )
continue;
if ( V_7 -> V_27 < 0xa0 )
V_104 = V_99 + ( V_10 << 12 ) ;
else
V_104 = V_100 + ( V_10 << 11 ) ;
V_105 = F_3 ( V_2 , V_104 ) & 0x7fffffff ;
if ( ! V_105 )
continue;
V_102 ++ ;
switch ( type ) {
case 6 :
if ( V_90 ) {
F_6 ( V_2 , L_11 , V_10 ) ;
for ( V_103 = V_104 + 4 ; V_103 <= V_104 + 0x10 ; V_103 += 4 )
F_6 ( V_2 , L_12 , V_103 ,
F_3 ( V_2 , V_103 ) ) ;
}
break;
case 7 :
if ( V_105 & 0x00010000 ) {
F_46 ( V_2 , V_10 , V_90 ) ;
V_105 &= ~ 0x00010000 ;
}
break;
case 8 :
{
T_1 V_106 = F_3 ( V_2 , V_104 + 4 ) ;
T_1 V_107 = F_3 ( V_2 , V_104 + 8 ) ;
T_1 V_108 = F_3 ( V_2 , V_104 + 0xc ) ;
T_1 V_109 = F_3 ( V_2 , V_104 + 0x10 ) ;
T_1 V_110 = F_3 ( V_2 , V_104 + 0x14 ) ;
T_1 V_111 = F_3 ( V_2 , V_104 + 0x18 ) ;
T_1 V_112 = F_3 ( V_2 , V_104 + 0x1c ) ;
if ( V_105 & 0x00000010 ) {
if ( V_90 ) {
F_47 ( V_2 , L_13 ,
V_10 , V_108 , V_107 ) ;
F_47 ( V_2 , L_14 ,
V_10 , V_106 , V_109 , V_110 , V_111 , V_112 ) ;
}
V_105 &= ~ 0x00000010 ;
}
if ( V_105 & 0x00000040 ) {
if ( V_90 ) {
F_47 ( V_2 , L_15 ,
V_10 , V_108 , V_107 ) ;
F_47 ( V_2 , L_16 ,
V_10 , V_106 , V_109 , V_110 , V_111 , V_112 ) ;
}
V_105 &= ~ 0x00000040 ;
}
if ( V_105 & 0x00000080 ) {
if ( V_90 ) {
if ( V_109 & 0x80000000 ) {
F_47 ( V_2 , L_17 ,
V_10 , V_108 , V_107 | ( ( V_109 >> 24 ) & 0x1f ) ) ;
V_109 &= ~ 0x1f000000 ;
} else if ( V_109 & 0xc ) {
F_47 ( V_2 , L_18 ,
V_10 , V_108 , V_107 | ( ( V_109 >> 7 ) & 0x1f ) ) ;
V_109 &= ~ 0x00000f80 ;
} else {
F_47 ( V_2 , L_19 ,
V_10 , V_108 , V_107 ) ;
}
F_47 ( V_2 , L_20 ,
V_10 , V_106 , V_109 , V_110 , V_111 , V_112 ) ;
}
V_105 &= ~ 0x00000080 ;
}
}
break;
}
if ( V_105 ) {
if ( V_90 )
F_47 ( V_2 , L_21 , V_101 , V_10 , V_105 ) ;
}
F_2 ( V_2 , V_104 , 0xc0000000 ) ;
}
if ( ! V_102 && V_90 )
F_47 ( V_2 , L_22 , V_101 ) ;
}
static int
F_51 ( struct V_1 * V_2 , T_2 V_90 , T_4 V_9 , T_2 V_113 )
{
T_2 V_93 = F_3 ( V_2 , 0x400108 ) ;
T_2 V_105 ;
if ( ! V_93 && V_90 ) {
F_47 ( V_2 , L_23 ) ;
return 1 ;
}
if ( V_93 & 0x001 ) {
V_105 = F_3 ( V_2 , 0x400804 ) & 0x7fffffff ;
if ( ! V_105 && V_90 ) {
F_47 ( V_2 , L_24 ) ;
}
F_2 ( V_2 , 0x400500 , 0x00000000 ) ;
if ( V_105 & 0x00000001 ) {
T_2 V_91 = F_3 ( V_2 , 0x400808 ) ;
T_2 V_114 = ( V_91 & 0x00070000 ) >> 16 ;
T_2 V_69 = ( V_91 & 0x00001ffc ) ;
T_2 V_115 = F_3 ( V_2 , 0x40080c ) ;
T_2 V_116 = F_3 ( V_2 , 0x400810 ) ;
T_2 V_64 = F_3 ( V_2 , 0x400814 ) ;
T_2 V_117 = F_3 ( V_2 , 0x400848 ) ;
F_47 ( V_2 , L_25 ) ;
if ( V_90 && ( V_91 & 0x80000000 ) ) {
F_47 ( V_2 , L_26
L_27
L_28
L_29 ,
V_113 , V_9 , V_114 , V_64 , V_69 , V_116 ,
V_115 , V_91 , V_117 ) ;
} else
if ( V_90 ) {
F_47 ( V_2 , L_30 ) ;
}
F_2 ( V_2 , 0x400808 , 0 ) ;
F_2 ( V_2 , 0x4008e8 , F_3 ( V_2 , 0x4008e8 ) & 3 ) ;
F_2 ( V_2 , 0x400848 , 0 ) ;
V_105 &= ~ 0x00000001 ;
}
if ( V_105 & 0x00000002 ) {
T_2 V_91 = F_3 ( V_2 , 0x40084c ) ;
T_2 V_114 = ( V_91 & 0x00070000 ) >> 16 ;
T_2 V_69 = ( V_91 & 0x00001ffc ) ;
T_2 V_52 = F_3 ( V_2 , 0x40085c ) ;
T_2 V_64 = F_3 ( V_2 , 0x400814 ) ;
F_47 ( V_2 , L_31 ) ;
if ( V_90 && ( V_91 & 0x80000000 ) ) {
F_47 ( V_2 , L_26
L_27
L_32 ,
V_113 , V_9 , V_114 , V_64 , V_69 ,
V_52 , V_91 ) ;
} else
if ( V_90 ) {
F_47 ( V_2 , L_30 ) ;
}
F_2 ( V_2 , 0x40084c , 0 ) ;
V_105 &= ~ 0x00000002 ;
}
if ( V_105 && V_90 ) {
F_47 ( V_2 , L_33
L_34 , V_105 ) ;
}
F_2 ( V_2 , 0x400804 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400108 , 0x001 ) ;
V_93 &= ~ 0x001 ;
if ( ! V_93 )
return 0 ;
}
if ( V_93 & 0x002 ) {
T_2 V_105 = F_3 ( V_2 , 0x406800 ) & 0x7fffffff ;
if ( V_90 ) {
F_47 ( V_2 , L_35 ) ;
F_52 ( V_118 , V_105 ) ;
F_49 ( L_2 ) ;
F_47 ( V_2 , L_36 ,
F_3 ( V_2 , 0x406804 ) , F_3 ( V_2 , 0x406808 ) ,
F_3 ( V_2 , 0x40680c ) , F_3 ( V_2 , 0x406810 ) ) ;
}
F_2 ( V_2 , 0x400040 , 2 ) ;
F_2 ( V_2 , 0x400040 , 0 ) ;
F_2 ( V_2 , 0x406800 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400108 , 0x002 ) ;
V_93 &= ~ 0x002 ;
}
if ( V_93 & 0x004 ) {
T_2 V_105 = F_3 ( V_2 , 0x400c04 ) & 0x7fffffff ;
if ( V_90 ) {
F_47 ( V_2 , L_37 ) ;
F_52 ( V_119 , V_105 ) ;
F_49 ( L_2 ) ;
F_47 ( V_2 , L_38 ,
F_3 ( V_2 , 0x400c00 ) , F_3 ( V_2 , 0x400c08 ) ,
F_3 ( V_2 , 0x400c0c ) , F_3 ( V_2 , 0x400c10 ) ) ;
}
F_2 ( V_2 , 0x400c04 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400108 , 0x004 ) ;
V_93 &= ~ 0x004 ;
}
if ( V_93 & 0x008 ) {
V_105 = F_3 ( V_2 , 0x401800 ) & 0x7fffffff ;
if ( V_90 ) {
F_47 ( V_2 , L_39 ) ;
F_52 ( V_120 , V_105 ) ;
F_49 ( L_2 ) ;
F_47 ( V_2 , L_40 ,
F_3 ( V_2 , 0x401804 ) , F_3 ( V_2 , 0x401808 ) ,
F_3 ( V_2 , 0x40180c ) , F_3 ( V_2 , 0x401810 ) ) ;
}
F_2 ( V_2 , 0x400040 , 0x80 ) ;
F_2 ( V_2 , 0x400040 , 0 ) ;
F_2 ( V_2 , 0x401800 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400108 , 0x008 ) ;
V_93 &= ~ 0x008 ;
}
if ( V_93 & 0x010 ) {
V_105 = F_3 ( V_2 , 0x405018 ) & 0x7fffffff ;
if ( V_90 ) {
F_47 ( V_2 , L_41 ) ;
F_52 ( V_121 , V_105 ) ;
F_49 ( L_2 ) ;
F_47 ( V_2 , L_42
L_43 ,
F_3 ( V_2 , 0x405000 ) , F_3 ( V_2 , 0x405004 ) ,
F_3 ( V_2 , 0x405008 ) , F_3 ( V_2 , 0x40500c ) ,
F_3 ( V_2 , 0x405010 ) , F_3 ( V_2 , 0x405014 ) ,
F_3 ( V_2 , 0x40501c ) ) ;
}
F_2 ( V_2 , 0x405018 , 0xc0000000 ) ;
F_2 ( V_2 , 0x400108 , 0x010 ) ;
V_93 &= ~ 0x010 ;
}
if ( V_93 & 0x20 ) {
V_105 = F_3 ( V_2 , 0x402000 ) & 0x7fffffff ;
if ( V_90 )
F_47 ( V_2 , L_44 , V_105 ) ;
F_2 ( V_2 , 0x402000 , 0xc0000000 ) ;
}
if ( V_93 & 0x040 ) {
F_50 ( V_2 , 6 , 0x408900 , 0x408600 , V_90 ,
L_45 ) ;
F_2 ( V_2 , 0x400108 , 0x040 ) ;
V_93 &= ~ 0x040 ;
}
if ( V_93 & 0x080 ) {
F_50 ( V_2 , 7 , 0x408314 , 0x40831c , V_90 ,
L_46 ) ;
F_2 ( V_2 , 0x400108 , 0x080 ) ;
V_93 &= ~ 0x080 ;
}
if ( V_93 & 0x100 ) {
F_50 ( V_2 , 8 , 0x408e08 , 0x408708 , V_90 ,
L_47 ) ;
F_2 ( V_2 , 0x400108 , 0x100 ) ;
V_93 &= ~ 0x100 ;
}
if ( V_93 ) {
if ( V_90 )
F_47 ( V_2 , L_48 , V_93 ) ;
F_2 ( V_2 , 0x400108 , V_93 ) ;
}
return 1 ;
}
int
F_53 ( struct V_1 * V_2 , T_4 V_9 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_5 * V_17 ;
unsigned long V_60 ;
int V_10 ;
F_26 ( & V_7 -> V_16 . V_122 , V_60 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_14 . V_15 . V_16 ; V_10 ++ ) {
V_17 = V_7 -> V_16 . V_18 [ V_10 ] ;
if ( ! V_17 || ! V_17 -> V_19 )
continue;
if ( V_9 == V_17 -> V_19 -> V_20 )
break;
}
F_27 ( & V_7 -> V_16 . V_122 , V_60 ) ;
return V_10 ;
}
static void
F_54 ( struct V_1 * V_2 )
{
T_2 V_123 ;
while ( ( V_123 = F_3 ( V_2 , 0x400100 ) ) ) {
T_4 V_9 = ( T_4 ) ( F_3 ( V_2 , 0x40032c ) & 0x0fffffff ) << 12 ;
T_2 V_113 = F_53 ( V_2 , V_9 ) ;
T_2 V_91 = F_3 ( V_2 , V_124 ) ;
T_2 V_114 = ( V_91 & 0x00070000 ) >> 16 ;
T_2 V_69 = ( V_91 & 0x00001ffc ) ;
T_2 V_52 = F_3 ( V_2 , V_125 ) ;
T_2 V_64 = F_3 ( V_2 , 0x400814 ) ;
T_2 V_126 = V_123 ;
if ( V_123 & 0x00000010 ) {
if ( ! F_55 ( V_2 , V_113 , V_64 ,
V_69 , V_52 ) )
V_126 &= ~ 0x00000010 ;
}
if ( V_123 & 0x00001000 ) {
F_2 ( V_2 , 0x400500 , 0x00000000 ) ;
F_2 ( V_2 , 0x400100 , 0x00001000 ) ;
F_19 ( V_2 , 0x40013c , 0x00001000 , 0x00000000 ) ;
F_32 ( V_2 ) ;
V_123 &= ~ 0x00001000 ;
V_126 &= ~ 0x00001000 ;
}
V_126 = ( V_126 && F_56 () ) ? V_126 : 0 ;
if ( V_126 & 0x00100000 ) {
T_2 V_127 = F_3 ( V_2 , 0x400110 ) ;
F_47 ( V_2 , L_49 ) ;
F_48 ( V_128 , V_127 ) ;
F_49 ( L_2 ) ;
}
if ( V_123 & 0x00200000 ) {
if ( ! F_51 ( V_2 , V_126 , V_9 , V_113 ) )
V_126 &= ~ 0x00200000 ;
}
F_2 ( V_2 , 0x400100 , V_123 ) ;
F_2 ( V_2 , 0x400500 , 0x00010001 ) ;
if ( V_126 ) {
F_47 ( V_2 , L_50 ) ;
F_52 ( V_129 , V_126 ) ;
F_49 ( L_2 ) ;
F_47 ( V_2 , L_51
L_52 ,
V_113 , V_9 , V_114 , V_64 , V_69 , V_52 ) ;
F_57 ( V_2 , 1 ) ;
}
}
if ( F_3 ( V_2 , 0x400824 ) & ( 1 << 31 ) )
F_2 ( V_2 , 0x400824 , F_3 ( V_2 , 0x400824 ) & ~ ( 1 << 31 ) ) ;
}
static void
F_58 ( struct V_1 * V_2 , int V_14 )
{
struct V_28 * V_29 = F_16 ( V_2 , V_14 ) ;
F_59 ( V_2 , V_130 ) ;
F_60 ( V_2 , 12 ) ;
F_61 ( V_29 ) ;
}
int
F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_28 * V_29 ;
struct V_42 V_43 = {} ;
int V_37 ;
V_29 = F_63 ( sizeof( * V_29 ) , V_131 ) ;
if ( ! V_29 )
return - V_132 ;
V_43 . V_2 = V_2 ;
V_43 . V_50 = V_133 ;
V_43 . V_52 = V_29 -> V_34 ;
V_43 . V_134 = F_64 ( V_29 -> V_34 ) ;
V_37 = F_23 ( & V_43 ) ;
if ( V_37 ) {
F_6 ( V_2 , L_53 ) ;
F_61 ( V_29 ) ;
return 0 ;
}
V_29 -> V_46 = V_43 . V_135 * 4 ;
V_29 -> V_32 = V_43 . V_136 ;
V_29 -> V_137 . V_138 = F_58 ;
V_29 -> V_137 . V_139 = F_17 ;
V_29 -> V_137 . V_140 = F_18 ;
V_29 -> V_137 . V_141 = F_20 ;
V_29 -> V_137 . V_142 = F_25 ;
V_29 -> V_137 . V_143 = F_30 ;
if ( V_7 -> V_27 == 0x50 || V_7 -> V_27 == 0xac )
V_29 -> V_137 . V_144 = F_43 ;
else
V_29 -> V_137 . V_144 = F_45 ;
F_65 ( V_2 , 12 , F_54 ) ;
F_66 ( V_2 , 0x506e , V_145 ) ;
F_67 ( V_2 , 0x506e , 0x018c , F_33 ) ;
F_67 ( V_2 , 0x506e , 0x0400 , F_36 ) ;
F_67 ( V_2 , 0x506e , 0x0404 , F_37 ) ;
F_67 ( V_2 , 0x506e , 0x0408 , F_38 ) ;
F_67 ( V_2 , 0x506e , 0x0500 , F_41 ) ;
F_68 ( V_2 , V_130 , & V_29 -> V_137 ) ;
F_66 ( V_2 , 0x0030 , V_130 ) ;
F_66 ( V_2 , 0x5039 , V_130 ) ;
F_66 ( V_2 , 0x502d , V_130 ) ;
if ( V_7 -> V_27 == 0x50 )
F_66 ( V_2 , 0x5097 , V_130 ) ;
else
if ( V_7 -> V_27 < 0xa0 )
F_66 ( V_2 , 0x8297 , V_130 ) ;
else {
switch ( V_7 -> V_27 ) {
case 0xa0 :
case 0xaa :
case 0xac :
F_66 ( V_2 , 0x8397 , V_130 ) ;
break;
case 0xa3 :
case 0xa5 :
case 0xa8 :
F_66 ( V_2 , 0x8597 , V_130 ) ;
break;
case 0xaf :
F_66 ( V_2 , 0x8697 , V_130 ) ;
break;
}
}
F_66 ( V_2 , 0x50c0 , V_130 ) ;
if ( V_7 -> V_27 > 0xa0 &&
V_7 -> V_27 != 0xaa &&
V_7 -> V_27 != 0xac )
F_66 ( V_2 , 0x85c0 , V_130 ) ;
return 0 ;
}
