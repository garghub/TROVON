static
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_2 ( V_2 -> V_7 , F_3 ( V_2 -> V_7 , 0 ) ,
V_8 , V_9 ,
V_3 , V_4 , V_6 , V_5 , 500 ) ;
}
static
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_2 ( V_2 -> V_7 , F_5 ( V_2 -> V_7 , 0 ) ,
V_10 , V_11 ,
V_3 , V_4 , V_6 , V_5 , 500 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
void * V_6 , T_1 type )
{
T_1 V_12 = 64 ;
int V_13 = 0 ;
if ( F_7 ( V_14 , & V_2 -> V_15 ) )
return - V_16 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_17 ;
if ( ( V_18 ) V_4 + ( V_18 ) V_5 > 0xffff )
return - V_17 ;
while ( V_5 ) {
if ( V_5 > V_12 ) {
V_13 = F_1 ( V_2 , V_4 , type , V_12 , V_6 ) ;
if ( V_13 < 0 )
break;
V_4 += V_12 ;
V_6 += V_12 ;
V_5 -= V_12 ;
} else {
V_13 = F_1 ( V_2 , V_4 , type , V_5 , V_6 ) ;
if ( V_13 < 0 )
break;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_19 ,
T_1 V_5 , void * V_6 , T_1 type )
{
int V_13 ;
T_1 V_20 , V_21 , V_22 ;
T_1 V_12 = 512 ;
if ( F_7 ( V_14 , & V_2 -> V_15 ) )
return - V_16 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_17 ;
if ( ( V_18 ) V_4 + ( V_18 ) V_5 > 0xffff )
return - V_17 ;
V_20 = V_19 & V_23 ;
V_21 = V_19 & V_24 ;
V_22 = V_20 | ( V_20 << 4 ) ;
V_13 = F_4 ( V_2 , V_4 , type | V_22 , 4 , V_6 ) ;
if ( V_13 < 0 )
goto V_25;
V_4 += 4 ;
V_6 += 4 ;
V_5 -= 4 ;
if ( V_5 ) {
V_5 -= 4 ;
while ( V_5 ) {
if ( V_5 > V_12 ) {
V_13 = F_4 ( V_2 , V_4 ,
type | V_26 ,
V_12 , V_6 ) ;
if ( V_13 < 0 )
goto V_25;
V_4 += V_12 ;
V_6 += V_12 ;
V_5 -= V_12 ;
} else {
V_13 = F_4 ( V_2 , V_4 ,
type | V_26 ,
V_5 , V_6 ) ;
if ( V_13 < 0 )
goto V_25;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
V_22 = V_21 | ( V_21 >> 4 ) ;
V_13 = F_4 ( V_2 , V_4 , type | V_22 , 4 , V_6 ) ;
if ( V_13 < 0 )
goto V_25;
}
V_25:
return V_13 ;
}
static inline
int F_9 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_6 ( V_2 , V_4 , V_5 , V_6 , V_27 ) ;
}
static inline
int F_10 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_19 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_19 , V_5 , V_6 , V_27 ) ;
}
static inline
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_6 ( V_2 , V_4 , V_5 , V_6 , V_28 ) ;
}
static inline
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_19 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_19 , V_5 , V_6 , V_28 ) ;
}
static V_18 F_13 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_18 V_6 ;
if ( type == V_27 )
F_9 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
else
F_11 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
return F_14 ( V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_18 V_6 )
{
if ( type == V_27 )
F_10 ( V_2 , V_4 , V_26 , sizeof( V_6 ) , & V_6 ) ;
else
F_12 ( V_2 , V_4 , V_26 , sizeof( V_6 ) , & V_6 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_18 V_6 ;
T_2 V_29 = V_4 & 2 ;
V_4 &= ~ 3 ;
if ( type == V_27 )
F_9 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
else
F_11 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
V_6 = F_14 ( V_6 ) ;
V_6 >>= ( V_29 * 8 ) ;
V_6 &= 0xffff ;
return ( T_1 ) V_6 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_18 V_6 )
{
V_18 V_30 , V_31 = 0xffff ;
T_1 V_22 = V_32 ;
T_2 V_29 = V_4 & 2 ;
V_6 &= V_31 ;
if ( V_4 & 2 ) {
V_22 <<= V_29 ;
V_31 <<= ( V_29 * 8 ) ;
V_6 <<= ( V_29 * 8 ) ;
V_4 &= ~ 3 ;
}
if ( type == V_27 )
F_9 ( V_2 , V_4 , sizeof( V_30 ) , & V_30 ) ;
else
F_11 ( V_2 , V_4 , sizeof( V_30 ) , & V_30 ) ;
V_30 = F_14 ( V_30 ) & ~ V_31 ;
V_30 |= V_6 ;
V_30 = F_18 ( V_30 ) ;
if ( type == V_27 )
F_10 ( V_2 , V_4 , V_22 , sizeof( V_30 ) , & V_30 ) ;
else
F_12 ( V_2 , V_4 , V_22 , sizeof( V_30 ) , & V_30 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_18 V_6 ;
T_2 V_29 = V_4 & 3 ;
V_4 &= ~ 3 ;
if ( type == V_27 )
F_9 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
else
F_11 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 ) ;
V_6 = F_14 ( V_6 ) ;
V_6 >>= ( V_29 * 8 ) ;
V_6 &= 0xff ;
return ( T_2 ) V_6 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_18 V_6 )
{
V_18 V_30 , V_31 = 0xff ;
T_1 V_22 = V_33 ;
T_2 V_29 = V_4 & 3 ;
V_6 &= V_31 ;
if ( V_4 & 3 ) {
V_22 <<= V_29 ;
V_31 <<= ( V_29 * 8 ) ;
V_6 <<= ( V_29 * 8 ) ;
V_4 &= ~ 3 ;
}
if ( type == V_27 )
F_9 ( V_2 , V_4 , sizeof( V_30 ) , & V_30 ) ;
else
F_11 ( V_2 , V_4 , sizeof( V_30 ) , & V_30 ) ;
V_30 = F_14 ( V_30 ) & ~ V_31 ;
V_30 |= V_6 ;
V_30 = F_18 ( V_30 ) ;
if ( type == V_27 )
F_10 ( V_2 , V_4 , V_22 , sizeof( V_30 ) , & V_30 ) ;
else
F_12 ( V_2 , V_4 , V_22 , sizeof( V_30 ) , & V_30 ) ;
}
static void F_21 ( struct V_1 * V_2 , V_18 V_34 , V_18 V_3 )
{
V_18 V_35 ;
int V_36 ;
V_35 = V_37 | ( ( V_34 & 0x1f ) << 16 ) |
( V_3 & 0xffff ) ;
F_15 ( V_2 , V_27 , V_38 , V_35 ) ;
for ( V_36 = 20 ; V_36 > 0 ; V_36 -- ) {
F_22 ( 25 ) ;
V_35 = F_13 ( V_2 , V_27 , V_38 ) ;
if ( ! ( V_35 & V_37 ) )
break;
}
F_22 ( 20 ) ;
}
static int F_23 ( struct V_1 * V_2 , V_18 V_34 )
{
V_18 V_35 ;
int V_36 ;
V_35 = ( V_34 & 0x1f ) << 16 ;
F_15 ( V_2 , V_27 , V_38 , V_35 ) ;
for ( V_36 = 20 ; V_36 > 0 ; V_36 -- ) {
F_22 ( 25 ) ;
V_35 = F_13 ( V_2 , V_27 , V_38 ) ;
if ( V_35 & V_37 )
break;
}
F_22 ( 20 ) ;
if ( ! ( V_35 & V_37 ) )
return - V_39 ;
return ( T_1 ) ( V_35 & 0xffff ) ;
}
static int F_24 ( struct V_40 * V_41 , int V_42 , int V_43 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
if ( V_42 != V_44 )
return - V_45 ;
return F_23 ( V_2 , V_43 ) ;
}
static
void F_26 ( struct V_40 * V_41 , int V_42 , int V_43 , int V_46 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
if ( V_42 != V_44 )
return;
F_21 ( V_2 , V_43 , V_46 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_47 , T_1 V_6 )
{
T_1 V_48 , V_49 ;
V_48 = V_47 & 0xf000 ;
if ( V_48 != V_2 -> V_48 ) {
F_17 ( V_2 , V_27 , V_50 , V_48 ) ;
V_2 -> V_48 = V_48 ;
}
V_49 = ( V_47 & 0x0fff ) | 0xb000 ;
F_17 ( V_2 , V_27 , V_49 , V_6 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
struct V_40 * V_51 = V_2 -> V_41 ;
T_2 * V_52 ;
V_52 = F_29 ( sizeof( T_2 ) * 8 , V_53 ) ;
if ( ! V_52 ) {
F_30 ( V_2 , V_54 , V_51 , L_1 ) ;
return;
}
if ( F_9 ( V_2 , V_55 , sizeof( T_2 ) * 8 , V_52 ) < 0 )
F_31 ( V_2 , V_54 , V_51 , L_2 ) ;
else {
memcpy ( V_51 -> V_56 , V_52 , V_51 -> V_57 ) ;
memcpy ( V_51 -> V_58 , V_51 -> V_56 , V_51 -> V_57 ) ;
}
F_32 ( V_52 ) ;
}
static int F_33 ( struct V_40 * V_41 , void * V_59 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_60 * V_47 = V_59 ;
if ( ! F_34 ( V_47 -> V_61 ) )
return - V_62 ;
memcpy ( V_41 -> V_56 , V_47 -> V_61 , V_41 -> V_57 ) ;
F_20 ( V_2 , V_27 , V_63 , V_64 ) ;
F_10 ( V_2 , V_55 , V_65 , 8 , V_47 -> V_61 ) ;
F_20 ( V_2 , V_27 , V_63 , V_66 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
V_2 -> V_67 = F_36 ( 0 , V_53 ) ;
if ( ! V_2 -> V_67 )
return 0 ;
V_2 -> V_68 = F_36 ( 0 , V_53 ) ;
if ( ! V_2 -> V_68 ) {
F_37 ( V_2 -> V_67 ) ;
return 0 ;
}
return 1 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_67 ) ;
F_37 ( V_2 -> V_68 ) ;
}
static struct V_69 * F_39 ( struct V_40 * V_51 )
{
return & V_51 -> V_70 ;
}
static void F_40 ( struct V_71 * V_71 )
{
struct V_1 * V_2 ;
unsigned V_72 ;
struct V_73 * V_74 ;
struct V_40 * V_41 ;
struct V_69 * V_70 ;
int V_75 = V_71 -> V_75 ;
int V_76 ;
struct V_77 * V_77 ;
V_2 = V_71 -> V_78 ;
if ( ! V_2 )
return;
if ( F_7 ( V_14 , & V_2 -> V_15 ) )
return;
V_41 = V_2 -> V_41 ;
if ( ! F_41 ( V_41 ) )
return;
V_70 = F_39 ( V_41 ) ;
switch ( V_75 ) {
case 0 :
break;
case - V_79 :
F_42 ( V_14 , & V_2 -> V_15 ) ;
F_43 ( V_2 -> V_41 ) ;
case - V_80 :
return;
case - V_81 :
F_44 ( L_3 ) ;
goto V_82;
default:
F_44 ( L_4 , V_75 ) ;
goto V_82;
}
if ( V_71 -> V_83 < sizeof( * V_77 ) )
goto V_82;
V_77 = (struct V_77 * ) V_71 -> V_84 ;
V_72 = F_45 ( V_77 -> V_85 ) & V_86 ;
if ( V_71 -> V_83 < sizeof( struct V_77 ) + V_72 )
goto V_82;
V_74 = F_46 ( V_41 , V_72 ) ;
if ( ! V_74 )
goto V_82;
memcpy ( V_74 -> V_6 , V_2 -> V_87 -> V_6 + sizeof( struct V_77 ) , V_72 ) ;
F_47 ( V_74 , V_72 ) ;
V_74 -> V_88 = F_48 ( V_74 , V_41 ) ;
F_49 ( V_74 ) ;
V_70 -> V_89 ++ ;
V_70 -> V_90 += V_72 ;
V_82:
F_50 ( V_2 -> V_67 , V_2 -> V_7 , F_51 ( V_2 -> V_7 , 1 ) ,
V_2 -> V_87 -> V_6 , V_91 + sizeof( struct V_77 ) ,
( V_92 ) F_40 , V_2 ) ;
V_76 = F_52 ( V_2 -> V_67 , V_93 ) ;
if ( V_76 == - V_16 ) {
F_43 ( V_2 -> V_41 ) ;
} else if ( V_76 ) {
F_42 ( V_94 , & V_2 -> V_15 ) ;
goto V_95;
} else {
F_53 ( V_94 , & V_2 -> V_15 ) ;
}
return;
V_95:
F_54 ( & V_2 -> V_96 ) ;
}
static void F_55 ( unsigned long V_6 )
{
struct V_1 * V_2 ;
int V_75 ;
V_2 = (struct V_1 * ) V_6 ;
if ( ! F_7 ( V_97 , & V_2 -> V_15 ) )
return;
V_75 = F_52 ( V_2 -> V_67 , V_93 ) ;
if ( V_75 == - V_16 ) {
F_43 ( V_2 -> V_41 ) ;
} else if ( V_75 ) {
F_42 ( V_94 , & V_2 -> V_15 ) ;
goto V_98;
} else {
F_53 ( V_94 , & V_2 -> V_15 ) ;
}
return;
V_98:
F_54 ( & V_2 -> V_96 ) ;
}
static void F_56 ( struct V_71 * V_71 )
{
struct V_1 * V_2 ;
int V_75 = V_71 -> V_75 ;
V_2 = V_71 -> V_78 ;
if ( ! V_2 )
return;
F_57 ( V_2 -> V_99 ) ;
if ( ! F_41 ( V_2 -> V_41 ) )
return;
if ( V_75 )
F_58 ( & V_71 -> V_51 -> V_51 , L_5 ,
V_2 -> V_41 -> V_100 , V_75 ) ;
V_2 -> V_41 -> V_101 = V_102 ;
F_59 ( V_2 -> V_41 ) ;
}
static void F_60 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_69 * V_70 = F_39 ( V_41 ) ;
F_61 ( V_2 , V_103 , V_41 , L_6 ) ;
F_62 ( V_2 -> V_68 ) ;
V_70 -> V_104 ++ ;
}
static void F_63 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
if ( V_2 -> V_105 & V_106 )
F_42 ( V_107 , & V_2 -> V_15 ) ;
}
static void F_64 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
V_18 V_30 , * V_108 ;
V_18 V_35 ;
V_108 = F_29 ( sizeof( V_18 ) * 2 , V_53 ) ;
if ( ! V_108 ) {
F_30 ( V_2 , V_109 , V_41 , L_1 ) ;
return;
}
F_53 ( V_107 , & V_2 -> V_15 ) ;
F_65 ( V_41 ) ;
V_35 = F_13 ( V_2 , V_27 , V_110 ) ;
V_35 &= ~ V_111 ;
V_35 |= V_112 | V_113 ;
if ( V_41 -> V_15 & V_114 ) {
F_31 ( V_2 , V_109 , V_41 , L_7 ) ;
V_35 |= V_115 | V_116 ;
V_108 [ 1 ] = V_108 [ 0 ] = 0xffffffff ;
} else if ( ( F_66 ( V_41 ) > V_117 ) ||
( V_41 -> V_15 & V_118 ) ) {
V_35 |= V_115 ;
V_108 [ 1 ] = V_108 [ 0 ] = 0xffffffff ;
} else {
struct V_119 * V_120 ;
V_108 [ 1 ] = V_108 [ 0 ] = 0 ;
F_67 (ha, netdev) {
int V_121 = F_68 ( V_122 , V_120 -> V_47 ) >> 26 ;
V_108 [ V_121 >> 5 ] |= 1 << ( V_121 & 31 ) ;
V_35 |= V_115 ;
}
}
V_30 = V_108 [ 0 ] ;
V_108 [ 0 ] = F_18 ( F_69 ( V_108 [ 1 ] ) ) ;
V_108 [ 1 ] = F_18 ( F_69 ( V_30 ) ) ;
F_10 ( V_2 , V_123 , V_26 , sizeof( V_18 ) * 2 , V_108 ) ;
F_15 ( V_2 , V_27 , V_110 , V_35 ) ;
F_59 ( V_41 ) ;
F_32 ( V_108 ) ;
}
static T_3 F_70 ( struct V_73 * V_74 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_69 * V_70 = F_39 ( V_41 ) ;
struct V_124 * V_124 ;
int V_125 , V_126 ;
F_65 ( V_41 ) ;
V_125 = V_74 -> V_125 ;
if ( F_71 ( V_74 ) || F_72 ( V_74 ) < sizeof( * V_124 ) ) {
struct V_73 * V_99 ;
V_99 = F_73 ( V_74 , sizeof( * V_124 ) , 0 , V_93 ) ;
F_74 ( V_74 ) ;
if ( ! V_99 ) {
V_70 -> V_127 ++ ;
F_59 ( V_41 ) ;
return V_128 ;
}
V_74 = V_99 ;
}
V_124 = (struct V_124 * ) F_75 ( V_74 , sizeof( * V_124 ) ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_85 = F_76 ( ( V_125 & V_129 ) | V_130 | V_131 ) ;
V_2 -> V_99 = V_74 ;
F_77 ( V_74 ) ;
F_50 ( V_2 -> V_68 , V_2 -> V_7 , F_78 ( V_2 -> V_7 , 2 ) ,
V_74 -> V_6 , V_74 -> V_125 ,
( V_92 ) F_56 , V_2 ) ;
V_126 = F_52 ( V_2 -> V_68 , V_93 ) ;
if ( V_126 ) {
if ( V_126 == - V_16 ) {
F_43 ( V_2 -> V_41 ) ;
} else {
F_61 ( V_2 , V_103 , V_41 ,
L_8 , V_126 ) ;
V_70 -> V_104 ++ ;
F_79 ( V_41 ) ;
}
} else {
V_70 -> V_132 ++ ;
V_70 -> V_133 += V_74 -> V_125 ;
}
return V_128 ;
}
static void F_80 ( struct V_1 * V_2 )
{
V_18 V_35 ;
V_35 = F_16 ( V_2 , V_27 , V_134 ) ;
V_35 &= ~ V_135 ;
F_17 ( V_2 , V_27 , V_134 , V_35 ) ;
V_35 |= V_135 ;
F_17 ( V_2 , V_27 , V_134 , V_35 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_36 ;
F_20 ( V_2 , V_27 , V_136 , V_137 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
if ( ! ( F_19 ( V_2 , V_27 , V_136 ) & V_137 ) )
break;
F_22 ( 100 ) ;
}
}
static inline T_2 F_82 ( struct V_1 * V_2 )
{
return F_19 ( V_2 , V_27 , V_138 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
V_18 V_35 ;
T_2 V_105 ;
V_105 = F_82 ( V_2 ) ;
if ( V_105 & V_139 ) {
V_35 = F_16 ( V_2 , V_27 , V_140 ) ;
V_35 &= ~ V_141 ;
F_17 ( V_2 , V_27 , V_140 , V_35 ) ;
} else {
V_35 = F_16 ( V_2 , V_27 , V_140 ) ;
V_35 |= V_141 ;
F_17 ( V_2 , V_27 , V_140 , V_35 ) ;
}
F_80 ( V_2 ) ;
V_35 = F_19 ( V_2 , V_27 , V_136 ) ;
V_35 |= V_142 | V_143 ;
F_20 ( V_2 , V_27 , V_136 , V_35 ) ;
V_35 = F_16 ( V_2 , V_27 , V_144 ) ;
V_35 &= ~ V_145 ;
F_17 ( V_2 , V_27 , V_144 , V_35 ) ;
F_50 ( V_2 -> V_67 , V_2 -> V_7 , F_51 ( V_2 -> V_7 , 1 ) ,
V_2 -> V_87 -> V_6 , V_91 + sizeof( struct V_77 ) ,
( V_92 ) F_40 , V_2 ) ;
return F_52 ( V_2 -> V_67 , V_53 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
V_18 V_35 ;
int V_36 ;
V_35 = F_13 ( V_2 , V_27 , V_110 ) ;
V_35 &= ~ V_111 ;
F_15 ( V_2 , V_27 , V_110 , V_35 ) ;
F_85 ( V_2 -> V_68 ) ;
V_35 = F_16 ( V_2 , V_27 , V_144 ) ;
V_35 |= V_145 ;
F_17 ( V_2 , V_27 , V_144 , V_35 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
if ( ( V_35 & V_147 ) == V_147 )
break;
F_86 ( 1 ) ;
}
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
if ( F_16 ( V_2 , V_27 , V_148 ) & V_149 )
break;
F_86 ( 1 ) ;
}
F_85 ( V_2 -> V_67 ) ;
F_81 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
V_18 V_35 ;
int V_36 ;
V_35 = F_13 ( V_2 , V_27 , V_110 ) ;
V_35 &= ~ V_111 ;
F_15 ( V_2 , V_27 , V_110 , V_35 ) ;
V_35 = F_16 ( V_2 , V_27 , V_144 ) ;
V_35 |= V_145 ;
F_17 ( V_2 , V_27 , V_144 , V_35 ) ;
F_20 ( V_2 , V_27 , V_63 , V_66 ) ;
F_20 ( V_2 , V_27 , V_136 , 0x00 ) ;
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
V_35 &= ~ V_150 ;
F_20 ( V_2 , V_27 , V_146 , V_35 ) ;
V_35 = F_16 ( V_2 , V_27 , V_151 ) ;
V_35 &= ~ V_152 ;
F_17 ( V_2 , V_27 , V_151 , V_35 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
if ( V_35 & V_153 )
break;
F_86 ( 1 ) ;
}
V_35 = F_16 ( V_2 , V_27 , V_151 ) ;
V_35 |= V_154 ;
F_17 ( V_2 , V_27 , V_151 , V_35 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
if ( V_35 & V_153 )
break;
F_86 ( 1 ) ;
}
F_81 ( V_2 ) ;
F_15 ( V_2 , V_27 , V_155 , V_156 ) ;
V_35 = F_16 ( V_2 , V_28 , V_157 ) ;
V_35 &= V_158 ;
if ( V_35 == V_159 ) {
F_15 ( V_2 , V_27 , V_160 ,
V_161 ) ;
F_15 ( V_2 , V_27 , V_162 ,
V_163 ) ;
} else {
F_15 ( V_2 , V_27 , V_160 ,
V_164 ) ;
F_15 ( V_2 , V_27 , V_162 ,
V_165 ) ;
}
F_15 ( V_2 , V_27 , V_166 , V_167 ) ;
F_20 ( V_2 , V_28 , V_168 , V_169 ) ;
F_15 ( V_2 , V_28 , V_170 , V_171 ) ;
F_15 ( V_2 , V_28 , V_172 ,
V_173 | V_174 ) ;
V_35 = F_16 ( V_2 , V_27 , V_175 ) ;
V_35 &= ~ V_176 ;
F_17 ( V_2 , V_27 , V_175 , V_35 ) ;
F_17 ( V_2 , V_27 , V_177 , V_91 ) ;
V_35 = F_16 ( V_2 , V_27 , V_148 ) ;
V_35 |= V_178 ;
F_17 ( V_2 , V_27 , V_148 , V_35 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_18 V_35 ;
int V_36 ;
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
V_35 &= ~ V_150 ;
F_20 ( V_2 , V_27 , V_146 , V_35 ) ;
F_15 ( V_2 , V_27 , V_155 , V_179 ) ;
F_15 ( V_2 , V_27 , V_160 , V_180 ) ;
F_15 ( V_2 , V_27 , V_162 , V_181 ) ;
F_84 ( V_2 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
if ( V_35 & V_153 )
break;
F_86 ( 1 ) ;
}
V_35 = F_16 ( V_2 , V_27 , V_151 ) ;
V_35 |= V_154 ;
F_17 ( V_2 , V_27 , V_151 , V_35 ) ;
for ( V_36 = 0 ; V_36 < 1000 ; V_36 ++ ) {
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
if ( V_35 & V_153 )
break;
F_86 ( 1 ) ;
}
F_17 ( V_2 , V_27 , V_177 , V_91 ) ;
V_35 = F_16 ( V_2 , V_27 , V_182 ) ;
V_35 |= V_183 ;
F_17 ( V_2 , V_27 , V_182 , V_35 ) ;
V_35 = F_16 ( V_2 , V_27 , V_175 ) ;
V_35 |= V_176 ;
F_17 ( V_2 , V_27 , V_175 , V_35 ) ;
V_35 = F_16 ( V_2 , V_27 , V_184 ) ;
V_35 |= V_185 ;
F_17 ( V_2 , V_27 , V_184 , V_35 ) ;
V_35 = F_19 ( V_2 , V_27 , V_146 ) ;
V_35 |= V_150 | V_186 ;
F_20 ( V_2 , V_27 , V_146 , V_35 ) ;
F_20 ( V_2 , V_27 , V_187 , V_188 ) ;
V_35 = F_16 ( V_2 , V_27 , V_144 ) ;
V_35 &= ~ V_145 ;
F_17 ( V_2 , V_27 , V_144 , V_35 ) ;
V_35 = F_13 ( V_2 , V_27 , V_110 ) ;
V_35 |= V_113 | V_115 | V_112 ;
F_15 ( V_2 , V_27 , V_110 , V_35 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_189 , V_190 | V_191 | V_192 ) ;
F_90 ( 20 ) ;
}
static inline void F_91 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_189 , V_193 | V_190 |
V_191 | V_192 ) ;
}
static int F_92 ( struct V_1 * V_2 , T_2 V_194 , T_1 V_105 , T_2 V_195 )
{
T_1 V_196 , V_197 ;
int V_13 = 0 ;
F_93 ( & V_2 -> V_198 ) ;
V_197 = F_23 ( V_2 , V_199 ) ;
V_197 &= ~ ( V_200 | V_201 |
V_202 | V_203 ) ;
if ( V_194 == V_204 ) {
if ( V_105 == V_205 ) {
V_196 = 0 ;
V_197 |= V_200 | V_201 ;
} else if ( V_105 == V_206 ) {
V_196 = V_207 ;
V_197 |= V_202 | V_203 ;
} else {
V_13 = - V_45 ;
goto V_208;
}
if ( V_195 == V_209 )
V_196 |= V_210 ;
} else {
if ( V_105 == V_205 ) {
if ( V_195 == V_209 )
V_197 |= V_200 | V_201 ;
else
V_197 |= V_200 ;
} else if ( V_105 == V_206 ) {
if ( V_195 == V_209 ) {
V_197 |= V_200 | V_201 ;
V_197 |= V_202 | V_203 ;
} else {
V_197 |= V_200 ;
V_197 |= V_202 ;
}
} else {
V_13 = - V_45 ;
goto V_208;
}
V_196 = V_211 | V_212 ;
}
F_21 ( V_2 , V_199 , V_197 ) ;
F_21 ( V_2 , V_213 , V_196 ) ;
V_208:
F_94 ( & V_2 -> V_198 , 5 * V_214 ) ;
return V_13 ;
}
static void F_95 ( struct V_1 * V_2 )
{
V_18 V_35 ;
V_35 = F_16 ( V_2 , V_28 , V_215 ) ;
V_35 &= ~ V_216 ;
F_17 ( V_2 , V_28 , V_215 , V_35 ) ;
F_89 ( V_2 ) ;
F_88 ( V_2 ) ;
F_91 ( V_2 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
T_2 V_105 ;
V_105 = F_82 ( V_2 ) ;
if ( V_105 & V_106 ) {
if ( ! ( V_2 -> V_105 & V_106 ) ) {
F_83 ( V_2 ) ;
F_42 ( V_107 , & V_2 -> V_15 ) ;
F_97 ( V_41 ) ;
}
} else {
if ( V_2 -> V_105 & V_106 ) {
F_98 ( V_41 ) ;
F_84 ( V_2 ) ;
}
}
V_2 -> V_105 = V_105 ;
}
static void F_99 ( struct V_217 * V_218 )
{
struct V_1 * V_2 = F_100 ( V_218 , struct V_1 , V_198 . V_218 ) ;
if ( ! F_7 ( V_97 , & V_2 -> V_15 ) )
goto V_219;
if ( F_7 ( V_14 , & V_2 -> V_15 ) )
goto V_219;
F_96 ( V_2 ) ;
if ( F_7 ( V_107 , & V_2 -> V_15 ) )
F_64 ( V_2 -> V_41 ) ;
F_94 ( & V_2 -> V_198 , V_214 ) ;
V_219:
return;
}
static int F_101 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
int V_126 = 0 ;
V_2 -> V_105 = F_82 ( V_2 ) ;
if ( V_2 -> V_105 & V_106 ) {
V_126 = F_83 ( V_2 ) ;
if ( V_126 ) {
if ( V_126 == - V_16 )
F_43 ( V_2 -> V_41 ) ;
F_30 ( V_2 , V_220 , V_41 ,
L_9 , V_126 ) ;
return V_126 ;
}
F_97 ( V_41 ) ;
} else {
F_65 ( V_41 ) ;
F_98 ( V_41 ) ;
}
F_92 ( V_2 , V_221 , V_206 , V_209 ) ;
F_79 ( V_41 ) ;
F_42 ( V_97 , & V_2 -> V_15 ) ;
F_94 ( & V_2 -> V_198 , 0 ) ;
return V_126 ;
}
static int F_102 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
int V_126 = 0 ;
F_53 ( V_97 , & V_2 -> V_15 ) ;
F_93 ( & V_2 -> V_198 ) ;
F_65 ( V_41 ) ;
F_84 ( V_2 ) ;
return V_126 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_27 , V_222 , 0 ) ;
F_15 ( V_2 , V_27 , V_223 , 0 ) ;
F_15 ( V_2 , V_27 , V_224 , 0 ) ;
F_15 ( V_2 , V_27 , V_225 , 0 ) ;
F_15 ( V_2 , V_28 , V_226 , 0 ) ;
F_15 ( V_2 , V_28 , V_227 , 0 ) ;
F_15 ( V_2 , V_28 , V_228 , 0 ) ;
F_15 ( V_2 , V_28 , V_229 , 0 ) ;
F_86 ( 3 ) ;
F_17 ( V_2 , V_27 , V_230 , 0 ) ;
F_17 ( V_2 , V_28 , V_231 , 0 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
V_18 V_35 ;
V_35 = F_16 ( V_2 , V_27 , V_232 ) ;
V_35 |= V_233 | V_234 ;
F_17 ( V_2 , V_27 , V_232 , V_35 ) ;
F_27 ( V_2 , V_235 , V_236 | V_237 |
V_238 | V_239 |
V_240 | V_241 |
V_242 | V_243 |
V_244 ) ;
F_27 ( V_2 , V_245 , V_246 | V_247 |
V_248 | V_249 |
V_250 ) ;
F_27 ( V_2 , V_251 , V_252 | V_253 | V_254 ) ;
F_27 ( V_2 , V_255 , V_256 | V_257 ) ;
F_27 ( V_2 , V_258 , V_259 ) ;
F_27 ( V_2 , V_255 , V_260 | V_257 ) ;
F_27 ( V_2 , V_258 , V_261 ) ;
F_27 ( V_2 , V_255 , 0x0000 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_197 ;
V_197 = F_23 ( V_2 , V_199 ) ;
V_197 |= V_262 | V_263 ;
F_21 ( V_2 , V_199 , V_197 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_213 , V_211 ) ;
F_89 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
V_18 V_35 ;
int V_36 ;
F_103 ( V_2 ) ;
if ( V_2 -> V_264 == V_265 ) {
V_35 = F_16 ( V_2 , V_27 , V_266 ) ;
V_35 &= ~ V_267 ;
F_17 ( V_2 , V_27 , V_266 , V_35 ) ;
}
F_106 ( V_2 ) ;
V_35 = F_16 ( V_2 , V_28 , V_215 ) ;
V_35 &= ~ V_216 ;
F_17 ( V_2 , V_28 , V_215 , V_35 ) ;
V_35 = F_16 ( V_2 , V_28 , V_268 ) ;
V_35 &= ~ V_269 ;
F_17 ( V_2 , V_28 , V_268 , V_35 ) ;
F_87 ( V_2 ) ;
V_35 = F_16 ( V_2 , V_27 , V_270 ) ;
V_35 |= V_271 | V_272 ;
F_17 ( V_2 , V_27 , V_270 , V_35 ) ;
V_35 = F_13 ( V_2 , V_27 , V_273 ) ;
V_35 &= ~ V_274 ;
V_35 |= V_275 | V_276 ;
F_15 ( V_2 , V_27 , V_273 , V_35 ) ;
V_35 = V_277 | V_278 |
V_279 | V_280 ;
F_17 ( V_2 , V_27 , V_281 , V_35 ) ;
F_104 ( V_2 ) ;
F_91 ( V_2 ) ;
F_105 ( V_2 ) ;
F_21 ( V_2 , V_213 , V_282 | V_211 |
V_212 ) ;
for ( V_36 = 0 ; V_36 < 100 ; V_36 ++ ) {
F_22 ( 100 ) ;
if ( ! ( F_23 ( V_2 , V_213 ) & V_282 ) )
break;
}
V_35 = F_16 ( V_2 , V_28 , V_283 ) ;
V_35 |= V_284 ;
F_17 ( V_2 , V_28 , V_283 , V_35 ) ;
}
static int F_108 ( struct V_285 * V_286 , T_4 V_287 )
{
struct V_1 * V_2 = F_109 ( V_286 ) ;
F_43 ( V_2 -> V_41 ) ;
if ( F_110 ( V_2 -> V_41 ) ) {
F_53 ( V_97 , & V_2 -> V_15 ) ;
F_93 ( & V_2 -> V_198 ) ;
}
F_95 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_285 * V_286 )
{
struct V_1 * V_2 = F_109 ( V_286 ) ;
F_107 ( V_2 ) ;
F_112 ( V_2 -> V_41 ) ;
if ( F_110 ( V_2 -> V_41 ) ) {
F_83 ( V_2 ) ;
F_42 ( V_97 , & V_2 -> V_15 ) ;
F_42 ( V_107 , & V_2 -> V_15 ) ;
F_94 ( & V_2 -> V_198 , 0 ) ;
}
return 0 ;
}
static void F_113 ( struct V_40 * V_41 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
strncpy ( V_289 -> V_290 , V_291 , V_292 ) ;
strncpy ( V_289 -> V_264 , V_293 , V_292 ) ;
F_114 ( V_2 -> V_7 , V_289 -> V_294 , sizeof( V_289 -> V_294 ) ) ;
}
static
int F_115 ( struct V_40 * V_41 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
if ( ! V_2 -> V_297 . V_298 )
return - V_299 ;
return F_116 ( & V_2 -> V_297 , V_296 ) ;
}
static int F_117 ( struct V_40 * V_51 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
return F_92 ( V_2 , V_296 -> V_194 , V_296 -> V_105 , V_296 -> V_195 ) ;
}
static int F_118 ( struct V_40 * V_41 , struct V_300 * V_301 , int V_296 )
{
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_302 * V_6 = F_119 ( V_301 ) ;
int V_126 = 0 ;
switch ( V_296 ) {
case V_303 :
V_6 -> V_42 = V_44 ;
break;
case V_304 :
V_6 -> V_305 = F_23 ( V_2 , V_6 -> V_306 ) ;
break;
case V_307 :
if ( ! F_120 ( V_308 ) ) {
V_126 = - V_17 ;
break;
}
F_21 ( V_2 , V_6 -> V_306 , V_6 -> V_309 ) ;
break;
default:
V_126 = - V_299 ;
}
return V_126 ;
}
static void F_121 ( struct V_1 * V_2 )
{
V_18 V_35 ;
T_1 V_264 ;
V_35 = F_16 ( V_2 , V_27 , V_310 ) ;
V_264 = ( T_1 ) ( V_35 & V_311 ) ;
switch ( V_264 ) {
case 0x4c00 :
V_2 -> V_264 = V_265 ;
break;
case 0x4c10 :
V_2 -> V_264 = V_312 ;
break;
default:
F_122 ( V_2 , V_54 , V_2 -> V_41 ,
L_10 , V_264 ) ;
break;
}
}
static int F_123 ( struct V_285 * V_286 ,
const struct V_313 * V_314 )
{
struct V_315 * V_7 = F_124 ( V_286 ) ;
struct V_1 * V_2 ;
struct V_40 * V_41 ;
if ( V_7 -> V_316 -> V_317 . V_318 != 1 ) {
F_125 ( V_7 , 1 ) ;
return - V_16 ;
}
V_41 = F_126 ( sizeof( struct V_1 ) ) ;
if ( ! V_41 ) {
F_127 ( & V_286 -> V_51 , L_11 ) ;
return - V_319 ;
}
V_2 = F_25 ( V_41 ) ;
V_2 -> V_320 = 0x7FFF ;
F_128 ( & V_2 -> V_96 , F_55 , ( unsigned long ) V_2 ) ;
F_129 ( & V_2 -> V_198 , F_99 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_41 = V_41 ;
V_41 -> V_321 = & V_322 ;
V_41 -> V_323 = V_324 ;
V_41 -> V_325 &= ~ V_326 ;
F_130 ( V_41 , & V_327 ) ;
V_2 -> V_105 = 0 ;
V_2 -> V_297 . V_51 = V_41 ;
V_2 -> V_297 . V_298 = F_24 ;
V_2 -> V_297 . V_328 = F_26 ;
V_2 -> V_297 . V_329 = 0x3f ;
V_2 -> V_297 . V_330 = 0x1f ;
V_2 -> V_297 . V_42 = V_44 ;
V_2 -> V_297 . V_331 = 0 ;
F_121 ( V_2 ) ;
F_107 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( ! F_35 ( V_2 ) ) {
F_30 ( V_2 , V_54 , V_41 , L_1 ) ;
goto V_208;
}
V_2 -> V_87 = F_131 ( V_41 ,
V_91 + sizeof( struct V_77 ) ) ;
if ( ! V_2 -> V_87 )
goto V_219;
F_132 ( V_286 , V_2 ) ;
F_133 ( V_41 , & V_286 -> V_51 ) ;
if ( F_134 ( V_41 ) != 0 ) {
F_30 ( V_2 , V_54 , V_41 , L_12 ) ;
goto V_332;
}
F_122 ( V_2 , V_54 , V_41 , L_13 , V_293 ) ;
return 0 ;
V_332:
F_132 ( V_286 , NULL ) ;
F_135 ( V_2 -> V_87 ) ;
V_219:
F_38 ( V_2 ) ;
V_208:
F_136 ( V_41 ) ;
return - V_333 ;
}
static void F_137 ( struct V_1 * V_2 )
{
V_18 V_35 ;
if ( V_2 -> V_264 != V_265 ) {
V_35 = F_16 ( V_2 , V_28 , V_215 ) ;
V_35 |= V_216 ;
F_17 ( V_2 , V_28 , V_215 , V_35 ) ;
}
V_35 = F_16 ( V_2 , V_28 , V_268 ) ;
V_35 &= ~ V_269 ;
F_17 ( V_2 , V_28 , V_268 , V_35 ) ;
}
static void F_138 ( struct V_285 * V_286 )
{
struct V_1 * V_2 = F_109 ( V_286 ) ;
F_132 ( V_286 , NULL ) ;
if ( V_2 ) {
F_42 ( V_14 , & V_2 -> V_15 ) ;
F_139 ( & V_2 -> V_96 ) ;
F_140 ( V_2 -> V_41 ) ;
F_137 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( V_2 -> V_87 )
F_135 ( V_2 -> V_87 ) ;
F_136 ( V_2 -> V_41 ) ;
}
}
static int T_5 F_141 ( void )
{
return F_142 ( & V_334 ) ;
}
static void T_6 F_143 ( void )
{
F_144 ( & V_334 ) ;
}
