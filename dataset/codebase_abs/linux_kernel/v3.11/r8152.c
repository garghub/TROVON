static
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
int V_7 ;
void * V_8 ;
V_8 = F_2 ( V_5 , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_7 = F_3 ( V_2 -> V_11 , F_4 ( V_2 -> V_11 , 0 ) ,
V_12 , V_13 ,
V_3 , V_4 , V_8 , V_5 , 500 ) ;
memcpy ( V_6 , V_8 , V_5 ) ;
F_5 ( V_8 ) ;
return V_7 ;
}
static
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
int V_7 ;
void * V_8 ;
V_8 = F_2 ( V_5 , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
memcpy ( V_8 , V_6 , V_5 ) ;
V_7 = F_3 ( V_2 -> V_11 , F_7 ( V_2 -> V_11 , 0 ) ,
V_14 , V_15 ,
V_3 , V_4 , V_8 , V_5 , 500 ) ;
F_5 ( V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
void * V_6 , T_1 type )
{
T_1 V_16 = 64 ;
int V_7 = 0 ;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_20 ;
if ( ( V_21 ) V_4 + ( V_21 ) V_5 > 0xffff )
return - V_20 ;
while ( V_5 ) {
if ( V_5 > V_16 ) {
V_7 = F_1 ( V_2 , V_4 , type , V_16 , V_6 ) ;
if ( V_7 < 0 )
break;
V_4 += V_16 ;
V_6 += V_16 ;
V_5 -= V_16 ;
} else {
V_7 = F_1 ( V_2 , V_4 , type , V_5 , V_6 ) ;
if ( V_7 < 0 )
break;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 ,
T_1 V_5 , void * V_6 , T_1 type )
{
int V_7 ;
T_1 V_23 , V_24 , V_25 ;
T_1 V_16 = 512 ;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_20 ;
if ( ( V_21 ) V_4 + ( V_21 ) V_5 > 0xffff )
return - V_20 ;
V_23 = V_22 & V_26 ;
V_24 = V_22 & V_27 ;
V_25 = V_23 | ( V_23 << 4 ) ;
V_7 = F_6 ( V_2 , V_4 , type | V_25 , 4 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += 4 ;
V_6 += 4 ;
V_5 -= 4 ;
if ( V_5 ) {
V_5 -= 4 ;
while ( V_5 ) {
if ( V_5 > V_16 ) {
V_7 = F_6 ( V_2 , V_4 ,
type | V_29 ,
V_16 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += V_16 ;
V_6 += V_16 ;
V_5 -= V_16 ;
} else {
V_7 = F_6 ( V_2 , V_4 ,
type | V_29 ,
V_5 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
V_25 = V_24 | ( V_24 >> 4 ) ;
V_7 = F_6 ( V_2 , V_4 , type | V_25 , 4 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
}
V_28:
return V_7 ;
}
static inline
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_10 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_5 , V_6 , V_31 ) ;
}
static inline
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_10 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_31 ) ;
}
static V_21 F_15 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
T_2 V_6 ;
F_8 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 , type ) ;
return F_16 ( V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
T_2 V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_29 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 2 ;
V_4 &= ~ 3 ;
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_16 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xffff ;
return ( T_1 ) V_6 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_33 = 0xffff ;
T_2 V_8 ;
T_1 V_25 = V_34 ;
T_3 V_32 = V_4 & 2 ;
V_6 &= V_33 ;
if ( V_4 & 2 ) {
V_25 <<= V_32 ;
V_33 <<= ( V_32 * 8 ) ;
V_6 <<= ( V_32 * 8 ) ;
V_4 &= ~ 3 ;
}
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 |= F_16 ( V_8 ) & ~ V_33 ;
V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_3 F_21 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 3 ;
V_4 &= ~ 3 ;
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_16 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xff ;
return ( T_3 ) V_6 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_33 = 0xff ;
T_2 V_8 ;
T_1 V_25 = V_35 ;
T_3 V_32 = V_4 & 3 ;
V_6 &= V_33 ;
if ( V_4 & 3 ) {
V_25 <<= V_32 ;
V_33 <<= ( V_32 * 8 ) ;
V_6 <<= ( V_32 * 8 ) ;
V_4 &= ~ 3 ;
}
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 |= F_16 ( V_8 ) & ~ V_33 ;
V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static void F_23 ( struct V_1 * V_2 , V_21 V_36 , V_21 V_3 )
{
V_21 V_37 ;
int V_38 ;
V_37 = V_39 | ( ( V_36 & 0x1f ) << 16 ) |
( V_3 & 0xffff ) ;
F_17 ( V_2 , V_30 , V_40 , V_37 ) ;
for ( V_38 = 20 ; V_38 > 0 ; V_38 -- ) {
F_24 ( 25 ) ;
V_37 = F_15 ( V_2 , V_30 , V_40 ) ;
if ( ! ( V_37 & V_39 ) )
break;
}
F_24 ( 20 ) ;
}
static int F_25 ( struct V_1 * V_2 , V_21 V_36 )
{
V_21 V_37 ;
int V_38 ;
V_37 = ( V_36 & 0x1f ) << 16 ;
F_17 ( V_2 , V_30 , V_40 , V_37 ) ;
for ( V_38 = 20 ; V_38 > 0 ; V_38 -- ) {
F_24 ( 25 ) ;
V_37 = F_15 ( V_2 , V_30 , V_40 ) ;
if ( V_37 & V_39 )
break;
}
F_24 ( 20 ) ;
if ( ! ( V_37 & V_39 ) )
return - V_41 ;
return ( T_1 ) ( V_37 & 0xffff ) ;
}
static int F_26 ( struct V_42 * V_43 , int V_44 , int V_45 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_44 != V_46 )
return - V_47 ;
return F_25 ( V_2 , V_45 ) ;
}
static
void F_28 ( struct V_42 * V_43 , int V_44 , int V_45 , int V_48 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_44 != V_46 )
return;
F_23 ( V_2 , V_45 , V_48 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_49 , T_1 V_6 )
{
T_1 V_50 , V_51 ;
V_50 = V_49 & 0xf000 ;
if ( V_50 != V_2 -> V_50 ) {
F_20 ( V_2 , V_30 , V_52 , V_50 ) ;
V_2 -> V_50 = V_50 ;
}
V_51 = ( V_49 & 0x0fff ) | 0xb000 ;
F_20 ( V_2 , V_30 , V_51 , V_6 ) ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_53 = V_2 -> V_43 ;
T_3 V_54 [ 8 ] = { 0 } ;
if ( F_11 ( V_2 , V_55 , sizeof( V_54 ) , V_54 ) < 0 )
F_31 ( V_2 , V_56 , V_53 , L_1 ) ;
else {
memcpy ( V_53 -> V_57 , V_54 , V_53 -> V_58 ) ;
memcpy ( V_53 -> V_59 , V_53 -> V_57 , V_53 -> V_58 ) ;
}
}
static int F_32 ( struct V_42 * V_43 , void * V_60 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_61 * V_49 = V_60 ;
if ( ! F_33 ( V_49 -> V_62 ) )
return - V_63 ;
memcpy ( V_43 -> V_57 , V_49 -> V_62 , V_43 -> V_58 ) ;
F_22 ( V_2 , V_30 , V_64 , V_65 ) ;
F_12 ( V_2 , V_55 , V_66 , 8 , V_49 -> V_62 ) ;
F_22 ( V_2 , V_30 , V_64 , V_67 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
V_2 -> V_68 = F_35 ( 0 , V_9 ) ;
if ( ! V_2 -> V_68 )
return 0 ;
V_2 -> V_69 = F_35 ( 0 , V_9 ) ;
if ( ! V_2 -> V_69 ) {
F_36 ( V_2 -> V_68 ) ;
return 0 ;
}
return 1 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_68 ) ;
F_36 ( V_2 -> V_69 ) ;
}
static struct V_70 * F_38 ( struct V_42 * V_53 )
{
return & V_53 -> V_71 ;
}
static void F_39 ( struct V_72 * V_72 )
{
struct V_1 * V_2 ;
unsigned V_73 ;
struct V_74 * V_75 ;
struct V_42 * V_43 ;
struct V_70 * V_71 ;
int V_76 = V_72 -> V_76 ;
int V_77 ;
struct V_78 * V_78 ;
V_2 = V_72 -> V_79 ;
if ( ! V_2 )
return;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return;
V_43 = V_2 -> V_43 ;
if ( ! F_40 ( V_43 ) )
return;
V_71 = F_38 ( V_43 ) ;
switch ( V_76 ) {
case 0 :
break;
case - V_80 :
F_41 ( V_17 , & V_2 -> V_18 ) ;
F_42 ( V_2 -> V_43 ) ;
case - V_81 :
return;
case - V_82 :
F_43 ( L_2 ) ;
goto V_83;
default:
F_43 ( L_3 , V_76 ) ;
goto V_83;
}
if ( V_72 -> V_84 < sizeof( * V_78 ) )
goto V_83;
V_78 = (struct V_78 * ) V_72 -> V_85 ;
V_73 = F_44 ( V_78 -> V_86 ) & V_87 ;
if ( V_72 -> V_84 < sizeof( struct V_78 ) + V_73 )
goto V_83;
V_75 = F_45 ( V_43 , V_73 ) ;
if ( ! V_75 )
goto V_83;
memcpy ( V_75 -> V_6 , V_2 -> V_88 -> V_6 + sizeof( struct V_78 ) , V_73 ) ;
F_46 ( V_75 , V_73 ) ;
V_75 -> V_89 = F_47 ( V_75 , V_43 ) ;
F_48 ( V_75 ) ;
V_71 -> V_90 ++ ;
V_71 -> V_91 += V_73 ;
V_83:
F_49 ( V_2 -> V_68 , V_2 -> V_11 , F_50 ( V_2 -> V_11 , 1 ) ,
V_2 -> V_88 -> V_6 , V_92 + sizeof( struct V_78 ) ,
( V_93 ) F_39 , V_2 ) ;
V_77 = F_51 ( V_2 -> V_68 , V_94 ) ;
if ( V_77 == - V_19 ) {
F_42 ( V_2 -> V_43 ) ;
} else if ( V_77 ) {
F_41 ( V_95 , & V_2 -> V_18 ) ;
goto V_96;
} else {
F_52 ( V_95 , & V_2 -> V_18 ) ;
}
return;
V_96:
F_53 ( & V_2 -> V_97 ) ;
}
static void F_54 ( unsigned long V_6 )
{
struct V_1 * V_2 ;
int V_76 ;
V_2 = (struct V_1 * ) V_6 ;
if ( ! F_9 ( V_98 , & V_2 -> V_18 ) )
return;
V_76 = F_51 ( V_2 -> V_68 , V_94 ) ;
if ( V_76 == - V_19 ) {
F_42 ( V_2 -> V_43 ) ;
} else if ( V_76 ) {
F_41 ( V_95 , & V_2 -> V_18 ) ;
goto V_99;
} else {
F_52 ( V_95 , & V_2 -> V_18 ) ;
}
return;
V_99:
F_53 ( & V_2 -> V_97 ) ;
}
static void F_55 ( struct V_72 * V_72 )
{
struct V_1 * V_2 ;
int V_76 = V_72 -> V_76 ;
V_2 = V_72 -> V_79 ;
if ( ! V_2 )
return;
F_56 ( V_2 -> V_100 ) ;
if ( ! F_40 ( V_2 -> V_43 ) )
return;
if ( V_76 )
F_57 ( & V_72 -> V_53 -> V_53 , L_4 ,
V_2 -> V_43 -> V_101 , V_76 ) ;
V_2 -> V_43 -> V_102 = V_103 ;
F_58 ( V_2 -> V_43 ) ;
}
static void F_59 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_70 * V_71 = F_38 ( V_43 ) ;
F_60 ( V_2 , V_104 , V_43 , L_5 ) ;
F_61 ( V_2 -> V_69 ) ;
V_71 -> V_105 ++ ;
}
static void F_62 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_2 -> V_106 & V_107 )
F_41 ( V_108 , & V_2 -> V_18 ) ;
}
static void F_63 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
V_21 V_109 [ 2 ] ;
T_2 V_8 [ 2 ] ;
V_21 V_37 ;
F_52 ( V_108 , & V_2 -> V_18 ) ;
F_64 ( V_43 ) ;
V_37 = F_15 ( V_2 , V_30 , V_110 ) ;
V_37 &= ~ V_111 ;
V_37 |= V_112 | V_113 ;
if ( V_43 -> V_18 & V_114 ) {
F_31 ( V_2 , V_115 , V_43 , L_6 ) ;
V_37 |= V_116 | V_117 ;
V_109 [ 1 ] = V_109 [ 0 ] = 0xffffffff ;
} else if ( ( F_65 ( V_43 ) > V_118 ) ||
( V_43 -> V_18 & V_119 ) ) {
V_37 |= V_116 ;
V_109 [ 1 ] = V_109 [ 0 ] = 0xffffffff ;
} else {
struct V_120 * V_121 ;
V_109 [ 1 ] = V_109 [ 0 ] = 0 ;
F_66 (ha, netdev) {
int V_122 = F_67 ( V_123 , V_121 -> V_49 ) >> 26 ;
V_109 [ V_122 >> 5 ] |= 1 << ( V_122 & 31 ) ;
V_37 |= V_116 ;
}
}
V_8 [ 0 ] = F_18 ( F_68 ( V_109 [ 1 ] ) ) ;
V_8 [ 1 ] = F_18 ( F_68 ( V_109 [ 0 ] ) ) ;
F_12 ( V_2 , V_124 , V_29 , sizeof( V_8 ) , V_8 ) ;
F_17 ( V_2 , V_30 , V_110 , V_37 ) ;
F_58 ( V_43 ) ;
}
static T_4 F_69 ( struct V_74 * V_75 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_70 * V_71 = F_38 ( V_43 ) ;
struct V_125 * V_125 ;
unsigned int V_126 ;
int V_127 ;
F_64 ( V_43 ) ;
V_126 = V_75 -> V_126 ;
if ( F_70 ( V_75 ) || F_71 ( V_75 ) < sizeof( * V_125 ) ) {
struct V_74 * V_100 ;
V_100 = F_72 ( V_75 , sizeof( * V_125 ) , 0 , V_94 ) ;
F_73 ( V_75 ) ;
if ( ! V_100 ) {
V_71 -> V_128 ++ ;
F_58 ( V_43 ) ;
return V_129 ;
}
V_75 = V_100 ;
}
V_125 = (struct V_125 * ) F_74 ( V_75 , sizeof( * V_125 ) ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_86 = F_75 ( ( V_126 & V_130 ) | V_131 | V_132 ) ;
V_2 -> V_100 = V_75 ;
F_76 ( V_75 ) ;
F_49 ( V_2 -> V_69 , V_2 -> V_11 , F_77 ( V_2 -> V_11 , 2 ) ,
V_75 -> V_6 , V_75 -> V_126 ,
( V_93 ) F_55 , V_2 ) ;
V_127 = F_51 ( V_2 -> V_69 , V_94 ) ;
if ( V_127 ) {
if ( V_127 == - V_19 ) {
F_42 ( V_2 -> V_43 ) ;
} else {
F_60 ( V_2 , V_104 , V_43 ,
L_7 , V_127 ) ;
V_71 -> V_105 ++ ;
F_78 ( V_43 ) ;
}
} else {
V_71 -> V_133 ++ ;
V_71 -> V_134 += V_75 -> V_126 ;
}
return V_129 ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_30 , V_135 ) ;
V_37 &= ~ V_136 ;
F_20 ( V_2 , V_30 , V_135 , V_37 ) ;
V_37 |= V_136 ;
F_20 ( V_2 , V_30 , V_135 , V_37 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
int V_38 ;
F_22 ( V_2 , V_30 , V_137 , V_138 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
if ( ! ( F_21 ( V_2 , V_30 , V_137 ) & V_138 ) )
break;
F_24 ( 100 ) ;
}
}
static inline T_3 F_81 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_30 , V_139 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
V_21 V_37 ;
T_3 V_106 ;
V_106 = F_81 ( V_2 ) ;
if ( V_106 & V_140 ) {
V_37 = F_19 ( V_2 , V_30 , V_141 ) ;
V_37 &= ~ V_142 ;
F_20 ( V_2 , V_30 , V_141 , V_37 ) ;
} else {
V_37 = F_19 ( V_2 , V_30 , V_141 ) ;
V_37 |= V_142 ;
F_20 ( V_2 , V_30 , V_141 , V_37 ) ;
}
F_79 ( V_2 ) ;
V_37 = F_21 ( V_2 , V_30 , V_137 ) ;
V_37 |= V_143 | V_144 ;
F_22 ( V_2 , V_30 , V_137 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_145 ) ;
V_37 &= ~ V_146 ;
F_20 ( V_2 , V_30 , V_145 , V_37 ) ;
F_49 ( V_2 -> V_68 , V_2 -> V_11 , F_50 ( V_2 -> V_11 , 1 ) ,
V_2 -> V_88 -> V_6 , V_92 + sizeof( struct V_78 ) ,
( V_93 ) F_39 , V_2 ) ;
return F_51 ( V_2 -> V_68 , V_9 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
V_37 = F_15 ( V_2 , V_30 , V_110 ) ;
V_37 &= ~ V_111 ;
F_17 ( V_2 , V_30 , V_110 , V_37 ) ;
F_84 ( V_2 -> V_69 ) ;
V_37 = F_19 ( V_2 , V_30 , V_145 ) ;
V_37 |= V_146 ;
F_20 ( V_2 , V_30 , V_145 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
if ( ( V_37 & V_148 ) == V_148 )
break;
F_85 ( 1 ) ;
}
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
if ( F_19 ( V_2 , V_30 , V_149 ) & V_150 )
break;
F_85 ( 1 ) ;
}
F_84 ( V_2 -> V_68 ) ;
F_80 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
V_37 = F_15 ( V_2 , V_30 , V_110 ) ;
V_37 &= ~ V_111 ;
F_17 ( V_2 , V_30 , V_110 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_145 ) ;
V_37 |= V_146 ;
F_20 ( V_2 , V_30 , V_145 , V_37 ) ;
F_22 ( V_2 , V_30 , V_64 , V_67 ) ;
F_22 ( V_2 , V_30 , V_137 , 0x00 ) ;
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
V_37 &= ~ V_151 ;
F_22 ( V_2 , V_30 , V_147 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_152 ) ;
V_37 &= ~ V_153 ;
F_20 ( V_2 , V_30 , V_152 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
if ( V_37 & V_154 )
break;
F_85 ( 1 ) ;
}
V_37 = F_19 ( V_2 , V_30 , V_152 ) ;
V_37 |= V_155 ;
F_20 ( V_2 , V_30 , V_152 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
if ( V_37 & V_154 )
break;
F_85 ( 1 ) ;
}
F_80 ( V_2 ) ;
F_17 ( V_2 , V_30 , V_156 , V_157 ) ;
V_37 = F_19 ( V_2 , V_31 , V_158 ) ;
V_37 &= V_159 ;
if ( V_37 == V_160 ) {
F_17 ( V_2 , V_30 , V_161 ,
V_162 ) ;
F_17 ( V_2 , V_30 , V_163 ,
V_164 ) ;
} else {
F_17 ( V_2 , V_30 , V_161 ,
V_165 ) ;
F_17 ( V_2 , V_30 , V_163 ,
V_166 ) ;
}
F_17 ( V_2 , V_30 , V_167 , V_168 ) ;
F_22 ( V_2 , V_31 , V_169 , V_170 ) ;
F_17 ( V_2 , V_31 , V_171 , V_172 ) ;
F_17 ( V_2 , V_31 , V_173 ,
V_174 | V_175 ) ;
V_37 = F_19 ( V_2 , V_30 , V_176 ) ;
V_37 &= ~ V_177 ;
F_20 ( V_2 , V_30 , V_176 , V_37 ) ;
F_20 ( V_2 , V_30 , V_178 , V_92 ) ;
V_37 = F_19 ( V_2 , V_30 , V_149 ) ;
V_37 |= V_179 ;
F_20 ( V_2 , V_30 , V_149 , V_37 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
V_37 &= ~ V_151 ;
F_22 ( V_2 , V_30 , V_147 , V_37 ) ;
F_17 ( V_2 , V_30 , V_156 , V_180 ) ;
F_17 ( V_2 , V_30 , V_161 , V_181 ) ;
F_17 ( V_2 , V_30 , V_163 , V_182 ) ;
F_83 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
if ( V_37 & V_154 )
break;
F_85 ( 1 ) ;
}
V_37 = F_19 ( V_2 , V_30 , V_152 ) ;
V_37 |= V_155 ;
F_20 ( V_2 , V_30 , V_152 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
if ( V_37 & V_154 )
break;
F_85 ( 1 ) ;
}
F_20 ( V_2 , V_30 , V_178 , V_92 ) ;
V_37 = F_19 ( V_2 , V_30 , V_183 ) ;
V_37 |= V_184 ;
F_20 ( V_2 , V_30 , V_183 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_176 ) ;
V_37 |= V_177 ;
F_20 ( V_2 , V_30 , V_176 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_185 ) ;
V_37 |= V_186 ;
F_20 ( V_2 , V_30 , V_185 , V_37 ) ;
V_37 = F_21 ( V_2 , V_30 , V_147 ) ;
V_37 |= V_151 | V_187 ;
F_22 ( V_2 , V_30 , V_147 , V_37 ) ;
F_22 ( V_2 , V_30 , V_188 , V_189 ) ;
V_37 = F_19 ( V_2 , V_30 , V_145 ) ;
V_37 &= ~ V_146 ;
F_20 ( V_2 , V_30 , V_145 , V_37 ) ;
V_37 = F_15 ( V_2 , V_30 , V_110 ) ;
V_37 |= V_113 | V_116 | V_112 ;
F_17 ( V_2 , V_30 , V_110 , V_37 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_190 , V_191 | V_192 | V_193 ) ;
F_89 ( 20 ) ;
}
static inline void F_90 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_190 , V_194 | V_191 |
V_192 | V_193 ) ;
}
static int F_91 ( struct V_1 * V_2 , T_3 V_195 , T_1 V_106 , T_3 V_196 )
{
T_1 V_197 , V_198 ;
int V_7 = 0 ;
F_92 ( & V_2 -> V_199 ) ;
V_198 = F_25 ( V_2 , V_200 ) ;
V_198 &= ~ ( V_201 | V_202 |
V_203 | V_204 ) ;
if ( V_195 == V_205 ) {
if ( V_106 == V_206 ) {
V_197 = 0 ;
V_198 |= V_201 | V_202 ;
} else if ( V_106 == V_207 ) {
V_197 = V_208 ;
V_198 |= V_203 | V_204 ;
} else {
V_7 = - V_47 ;
goto V_209;
}
if ( V_196 == V_210 )
V_197 |= V_211 ;
} else {
if ( V_106 == V_206 ) {
if ( V_196 == V_210 )
V_198 |= V_201 | V_202 ;
else
V_198 |= V_201 ;
} else if ( V_106 == V_207 ) {
if ( V_196 == V_210 ) {
V_198 |= V_201 | V_202 ;
V_198 |= V_203 | V_204 ;
} else {
V_198 |= V_201 ;
V_198 |= V_203 ;
}
} else {
V_7 = - V_47 ;
goto V_209;
}
V_197 = V_212 | V_213 ;
}
F_23 ( V_2 , V_200 , V_198 ) ;
F_23 ( V_2 , V_214 , V_197 ) ;
V_209:
F_93 ( & V_2 -> V_199 , 5 * V_215 ) ;
return V_7 ;
}
static void F_94 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_31 , V_216 ) ;
V_37 &= ~ V_217 ;
F_20 ( V_2 , V_31 , V_216 , V_37 ) ;
F_88 ( V_2 ) ;
F_87 ( V_2 ) ;
F_90 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
T_3 V_106 ;
V_106 = F_81 ( V_2 ) ;
if ( V_106 & V_107 ) {
if ( ! ( V_2 -> V_106 & V_107 ) ) {
F_82 ( V_2 ) ;
F_41 ( V_108 , & V_2 -> V_18 ) ;
F_96 ( V_43 ) ;
}
} else {
if ( V_2 -> V_106 & V_107 ) {
F_97 ( V_43 ) ;
F_83 ( V_2 ) ;
}
}
V_2 -> V_106 = V_106 ;
}
static void F_98 ( struct V_218 * V_219 )
{
struct V_1 * V_2 = F_99 ( V_219 , struct V_1 , V_199 . V_219 ) ;
if ( ! F_9 ( V_98 , & V_2 -> V_18 ) )
goto V_220;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
goto V_220;
F_95 ( V_2 ) ;
if ( F_9 ( V_108 , & V_2 -> V_18 ) )
F_63 ( V_2 -> V_43 ) ;
F_93 ( & V_2 -> V_199 , V_215 ) ;
V_220:
return;
}
static int F_100 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_127 = 0 ;
V_2 -> V_106 = F_81 ( V_2 ) ;
if ( V_2 -> V_106 & V_107 ) {
V_127 = F_82 ( V_2 ) ;
if ( V_127 ) {
if ( V_127 == - V_19 )
F_42 ( V_2 -> V_43 ) ;
F_101 ( V_2 , V_221 , V_43 ,
L_8 , V_127 ) ;
return V_127 ;
}
F_96 ( V_43 ) ;
} else {
F_64 ( V_43 ) ;
F_97 ( V_43 ) ;
}
F_91 ( V_2 , V_222 , V_207 , V_210 ) ;
F_78 ( V_43 ) ;
F_41 ( V_98 , & V_2 -> V_18 ) ;
F_93 ( & V_2 -> V_199 , 0 ) ;
return V_127 ;
}
static int F_102 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_127 = 0 ;
F_52 ( V_98 , & V_2 -> V_18 ) ;
F_92 ( & V_2 -> V_199 ) ;
F_64 ( V_43 ) ;
F_83 ( V_2 ) ;
return V_127 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_30 , V_223 , 0 ) ;
F_17 ( V_2 , V_30 , V_224 , 0 ) ;
F_17 ( V_2 , V_30 , V_225 , 0 ) ;
F_17 ( V_2 , V_30 , V_226 , 0 ) ;
F_17 ( V_2 , V_31 , V_227 , 0 ) ;
F_17 ( V_2 , V_31 , V_228 , 0 ) ;
F_17 ( V_2 , V_31 , V_229 , 0 ) ;
F_17 ( V_2 , V_31 , V_230 , 0 ) ;
F_85 ( 3 ) ;
F_20 ( V_2 , V_30 , V_231 , 0 ) ;
F_20 ( V_2 , V_31 , V_232 , 0 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_30 , V_233 ) ;
V_37 |= V_234 | V_235 ;
F_20 ( V_2 , V_30 , V_233 , V_37 ) ;
F_29 ( V_2 , V_236 , V_237 | V_238 |
V_239 | V_240 |
V_241 | V_242 |
V_243 | V_244 |
V_245 ) ;
F_29 ( V_2 , V_246 , V_247 | V_248 |
V_249 | V_250 |
V_251 ) ;
F_29 ( V_2 , V_252 , V_253 | V_254 | V_255 ) ;
F_29 ( V_2 , V_256 , V_257 | V_258 ) ;
F_29 ( V_2 , V_259 , V_260 ) ;
F_29 ( V_2 , V_256 , V_261 | V_258 ) ;
F_29 ( V_2 , V_259 , V_262 ) ;
F_29 ( V_2 , V_256 , 0x0000 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_198 ;
V_198 = F_25 ( V_2 , V_200 ) ;
V_198 |= V_263 | V_264 ;
F_23 ( V_2 , V_200 , V_198 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_214 , V_212 ) ;
F_88 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
F_103 ( V_2 ) ;
if ( V_2 -> V_265 == V_266 ) {
V_37 = F_19 ( V_2 , V_30 , V_267 ) ;
V_37 &= ~ V_268 ;
F_20 ( V_2 , V_30 , V_267 , V_37 ) ;
}
F_106 ( V_2 ) ;
V_37 = F_19 ( V_2 , V_31 , V_216 ) ;
V_37 &= ~ V_217 ;
F_20 ( V_2 , V_31 , V_216 , V_37 ) ;
V_37 = F_19 ( V_2 , V_31 , V_269 ) ;
V_37 &= ~ V_270 ;
F_20 ( V_2 , V_31 , V_269 , V_37 ) ;
F_86 ( V_2 ) ;
V_37 = F_19 ( V_2 , V_30 , V_271 ) ;
V_37 |= V_272 | V_273 ;
F_20 ( V_2 , V_30 , V_271 , V_37 ) ;
V_37 = F_15 ( V_2 , V_30 , V_274 ) ;
V_37 &= ~ V_275 ;
V_37 |= V_276 | V_277 ;
F_17 ( V_2 , V_30 , V_274 , V_37 ) ;
V_37 = V_278 | V_279 |
V_280 | V_281 ;
F_20 ( V_2 , V_30 , V_282 , V_37 ) ;
F_104 ( V_2 ) ;
F_90 ( V_2 ) ;
F_105 ( V_2 ) ;
F_23 ( V_2 , V_214 , V_283 | V_212 |
V_213 ) ;
for ( V_38 = 0 ; V_38 < 100 ; V_38 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_25 ( V_2 , V_214 ) & V_283 ) )
break;
}
V_37 = F_19 ( V_2 , V_31 , V_284 ) ;
V_37 |= V_285 ;
F_20 ( V_2 , V_31 , V_284 , V_37 ) ;
}
static int F_108 ( struct V_286 * V_287 , T_5 V_288 )
{
struct V_1 * V_2 = F_109 ( V_287 ) ;
F_42 ( V_2 -> V_43 ) ;
if ( F_110 ( V_2 -> V_43 ) ) {
F_52 ( V_98 , & V_2 -> V_18 ) ;
F_92 ( & V_2 -> V_199 ) ;
}
F_94 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_286 * V_287 )
{
struct V_1 * V_2 = F_109 ( V_287 ) ;
F_107 ( V_2 ) ;
F_112 ( V_2 -> V_43 ) ;
if ( F_110 ( V_2 -> V_43 ) ) {
F_82 ( V_2 ) ;
F_41 ( V_98 , & V_2 -> V_18 ) ;
F_41 ( V_108 , & V_2 -> V_18 ) ;
F_93 ( & V_2 -> V_199 , 0 ) ;
}
return 0 ;
}
static void F_113 ( struct V_42 * V_43 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
strncpy ( V_290 -> V_291 , V_292 , V_293 ) ;
strncpy ( V_290 -> V_265 , V_294 , V_293 ) ;
F_114 ( V_2 -> V_11 , V_290 -> V_295 , sizeof( V_290 -> V_295 ) ) ;
}
static
int F_115 ( struct V_42 * V_43 , struct V_296 * V_297 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( ! V_2 -> V_298 . V_299 )
return - V_300 ;
return F_116 ( & V_2 -> V_298 , V_297 ) ;
}
static int F_117 ( struct V_42 * V_53 , struct V_296 * V_297 )
{
struct V_1 * V_2 = F_27 ( V_53 ) ;
return F_91 ( V_2 , V_297 -> V_195 , V_297 -> V_106 , V_297 -> V_196 ) ;
}
static int F_118 ( struct V_42 * V_43 , struct V_301 * V_302 , int V_297 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_303 * V_6 = F_119 ( V_302 ) ;
int V_127 = 0 ;
switch ( V_297 ) {
case V_304 :
V_6 -> V_44 = V_46 ;
break;
case V_305 :
V_6 -> V_306 = F_25 ( V_2 , V_6 -> V_307 ) ;
break;
case V_308 :
if ( ! F_120 ( V_309 ) ) {
V_127 = - V_20 ;
break;
}
F_23 ( V_2 , V_6 -> V_307 , V_6 -> V_310 ) ;
break;
default:
V_127 = - V_300 ;
}
return V_127 ;
}
static void F_121 ( struct V_1 * V_2 )
{
V_21 V_37 ;
T_1 V_265 ;
V_37 = F_19 ( V_2 , V_30 , V_311 ) ;
V_265 = ( T_1 ) ( V_37 & V_312 ) ;
switch ( V_265 ) {
case 0x4c00 :
V_2 -> V_265 = V_266 ;
break;
case 0x4c10 :
V_2 -> V_265 = V_313 ;
break;
default:
F_122 ( V_2 , V_56 , V_2 -> V_43 ,
L_9 , V_265 ) ;
break;
}
}
static int F_123 ( struct V_286 * V_287 ,
const struct V_314 * V_315 )
{
struct V_316 * V_11 = F_124 ( V_287 ) ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
if ( V_11 -> V_317 -> V_318 . V_319 != 1 ) {
F_125 ( V_11 , 1 ) ;
return - V_19 ;
}
V_43 = F_126 ( sizeof( struct V_1 ) ) ;
if ( ! V_43 ) {
F_127 ( & V_287 -> V_53 , L_10 ) ;
return - V_10 ;
}
V_2 = F_27 ( V_43 ) ;
V_2 -> V_320 = 0x7FFF ;
F_128 ( & V_2 -> V_97 , F_54 , ( unsigned long ) V_2 ) ;
F_129 ( & V_2 -> V_199 , F_98 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_43 = V_43 ;
V_43 -> V_321 = & V_322 ;
V_43 -> V_323 = V_324 ;
V_43 -> V_325 &= ~ V_326 ;
F_130 ( V_43 , & V_327 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_298 . V_53 = V_43 ;
V_2 -> V_298 . V_299 = F_26 ;
V_2 -> V_298 . V_328 = F_28 ;
V_2 -> V_298 . V_329 = 0x3f ;
V_2 -> V_298 . V_330 = 0x1f ;
V_2 -> V_298 . V_44 = V_46 ;
V_2 -> V_298 . V_331 = 0 ;
F_121 ( V_2 ) ;
F_107 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( ! F_34 ( V_2 ) ) {
F_101 ( V_2 , V_56 , V_43 , L_11 ) ;
goto V_209;
}
V_2 -> V_88 = F_131 ( V_43 ,
V_92 + sizeof( struct V_78 ) ) ;
if ( ! V_2 -> V_88 )
goto V_220;
F_132 ( V_287 , V_2 ) ;
F_133 ( V_43 , & V_287 -> V_53 ) ;
if ( F_134 ( V_43 ) != 0 ) {
F_101 ( V_2 , V_56 , V_43 , L_12 ) ;
goto V_332;
}
F_122 ( V_2 , V_56 , V_43 , L_13 , V_294 ) ;
return 0 ;
V_332:
F_132 ( V_287 , NULL ) ;
F_135 ( V_2 -> V_88 ) ;
V_220:
F_37 ( V_2 ) ;
V_209:
F_136 ( V_43 ) ;
return - V_333 ;
}
static void F_137 ( struct V_1 * V_2 )
{
V_21 V_37 ;
if ( V_2 -> V_265 != V_266 ) {
V_37 = F_19 ( V_2 , V_31 , V_216 ) ;
V_37 |= V_217 ;
F_20 ( V_2 , V_31 , V_216 , V_37 ) ;
}
V_37 = F_19 ( V_2 , V_31 , V_269 ) ;
V_37 &= ~ V_270 ;
F_20 ( V_2 , V_31 , V_269 , V_37 ) ;
}
static void F_138 ( struct V_286 * V_287 )
{
struct V_1 * V_2 = F_109 ( V_287 ) ;
F_132 ( V_287 , NULL ) ;
if ( V_2 ) {
F_41 ( V_17 , & V_2 -> V_18 ) ;
F_139 ( & V_2 -> V_97 ) ;
F_140 ( V_2 -> V_43 ) ;
F_137 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_88 )
F_135 ( V_2 -> V_88 ) ;
F_136 ( V_2 -> V_43 ) ;
}
}
