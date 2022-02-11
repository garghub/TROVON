static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
int V_9 ;
V_9 = V_3 & 0x3 ;
V_4 = ( ( V_4 - 1 ) + V_9 ) & 0x3 ;
return V_6 -> V_10 [ V_4 ] ;
}
static int F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
unsigned int * V_14 ;
unsigned long V_15 ;
T_2 V_16 ;
if ( V_12 & 0x3 )
return - V_17 ;
if ( V_7 == 0 ) {
V_11 += ( 0x8 * 6 ) ;
} else if ( V_7 == V_18 ) {
V_7 = 0 ;
V_11 = 0 ;
}
F_3 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_21 , ( F_5 ( V_6 -> V_20 -> V_21 ) & ~ ( 0xff << 16 ) ) |
( V_7 << 16 ) ) ;
F_6 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_22 , ( V_23 | V_24 ) ) ;
V_14 = ( unsigned int * ) ( V_6 -> V_14 |
( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
V_16 = F_7 ( V_14 ) ;
while ( ( F_5 ( V_6 -> V_20 -> V_22 ) & V_24 ) == 0 )
;
if ( F_5 ( V_6 -> V_20 -> V_22 ) & V_23 ) {
* V_13 = 0xffffffff ;
} else {
* V_13 = F_8 ( V_16 ) ;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_25 ;
int V_26 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_26 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_25 ) ;
* V_13 = 0xffff & ( V_25 >> ( 8 * ( V_12 & 0x3 ) ) ) ;
return V_26 ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_25 ;
int V_26 ;
V_26 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_25 ) ;
* V_13 = 0xff & ( V_25 >> ( 8 * ( V_12 & 3 ) ) ) ;
return V_26 ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
unsigned int * V_14 ;
unsigned long V_15 ;
if ( V_12 & 0x3 )
return - V_17 ;
if ( V_7 == 0 ) {
V_11 += ( 0x8 * 6 ) ;
} else if ( V_7 == V_18 ) {
V_7 = 0 ;
V_11 = 0 ;
}
F_3 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_21 , ( F_5 ( V_6 -> V_20 -> V_21 ) & ~ ( 0xff << 16 ) ) |
( V_7 << 16 ) ) ;
F_6 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_22 , ( V_23 | V_24 ) ) ;
V_14 = ( unsigned int * ) ( V_6 -> V_14 |
( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
F_12 ( V_14 , F_8 ( V_13 ) ) ;
while ( ( F_5 ( V_6 -> V_20 -> V_22 ) & V_24 ) == 0 )
;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_26 ;
T_2 V_25 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_26 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 3 , & V_25 ) ;
if ( V_26 )
return V_26 ;
V_25 = ( V_25 & ~ ( 0xffff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xffff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_11 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_25 ) ;
}
static int F_14 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_26 ;
T_2 V_25 ;
V_26 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_25 ) ;
if ( V_26 != 0 )
return V_26 ;
V_25 = ( V_25 & ~ ( 0xff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_11 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_25 ) ;
}
static int F_15 ( struct V_27 * V_7 , unsigned int V_11 ,
int V_12 , int V_28 , T_2 * V_13 )
{
struct V_5 * V_6 = V_29 ;
unsigned int V_30 = V_7 -> V_31 ;
int V_26 ;
if ( F_16 ( V_11 ) > 15 || V_30 > 255 ) {
* V_13 = ~ 0 ;
return 0 ;
}
switch ( V_28 ) {
case 1 :
V_26 = F_10 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
break;
case 2 :
V_26 = F_9 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
break;
case 4 :
V_26 = F_2 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
break;
default:
V_26 = - V_17 ;
break;
}
#ifdef F_17
F_18 ( V_32 L_1
L_2 , V_30 , F_16 ( V_11 ) , F_19 ( V_11 ) , V_12 ,
* V_13 , V_28 ) ;
#endif
return V_26 ;
}
static int F_20 ( struct V_27 * V_7 , unsigned int V_11 ,
int V_12 , int V_28 , T_2 V_13 )
{
struct V_5 * V_6 = V_29 ;
unsigned int V_30 = V_7 -> V_31 ;
if ( F_16 ( V_11 ) > 15 || V_30 > 255 )
return 0 ;
#ifdef F_17
F_18 ( V_32 L_3
L_4 , V_30 , F_16 ( V_11 ) , F_19 ( V_11 ) ,
V_12 , V_28 , V_13 ) ;
#endif
switch ( V_28 ) {
default:
return - V_17 ;
case 1 :
return F_14 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
case 2 :
return F_13 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
case 4 :
return F_11 ( V_6 , V_30 , V_11 , V_12 , V_13 ) ;
}
}
static void F_21 ( struct V_33 * V_34 )
{
unsigned long V_15 ;
unsigned int V_35 ;
struct V_5 * V_6 = V_29 ;
V_35 = ( unsigned int ) V_34 -> V_36 - 1 ;
if ( V_35 > 3 )
return;
F_3 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_21 , F_5 ( V_6 -> V_20 -> V_21 ) & ~ ( 1 << V_35 ) ) ;
F_6 ( & V_19 , V_15 ) ;
}
static void F_22 ( struct V_33 * V_34 )
{
unsigned long V_15 ;
unsigned int V_35 ;
struct V_5 * V_6 = V_29 ;
V_35 = ( unsigned int ) V_34 -> V_36 - 1 ;
if ( V_35 > 3 )
return;
F_3 ( & V_19 , V_15 ) ;
F_4 ( V_6 -> V_20 -> V_21 , F_5 ( V_6 -> V_20 -> V_21 ) | ( 1 << V_35 ) ) ;
F_6 ( & V_19 , V_15 ) ;
}
static unsigned int F_23 ( struct V_33 * V_34 )
{
F_22 ( V_34 ) ;
return 0 ;
}
static void F_24 ( struct V_33 * V_34 )
{
F_21 ( V_34 ) ;
}
static void F_25 ( struct V_37 * V_38 )
{
struct V_5 * V_6 = V_29 ;
int V_39 , V_40 = 0 ;
unsigned int V_21 , V_22 , V_41 ;
V_21 = F_5 ( V_6 -> V_20 -> V_21 ) ;
V_22 = F_5 ( V_6 -> V_20 -> V_22 ) ;
if ( V_22 & V_42 ) {
F_26 ( V_6 -> V_43 ) ;
V_40 = 1 ;
}
V_41 = ( ( ~ V_22 ) >> V_44 ) & V_21 & V_45 ;
if ( V_41 ) {
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
if ( V_41 & ( 1 << V_39 ) )
F_26 ( V_6 -> V_10 [ V_39 ] ) ;
}
V_40 = 1 ;
}
if ( ( V_6 -> V_46 == 0 ) && ( V_22 & ( V_47 | V_48 ) ) ) {
F_26 ( V_6 -> V_49 ) ;
V_40 = 1 ;
}
if ( V_40 )
V_38 -> V_33 . V_50 -> V_51 ( & V_38 -> V_33 ) ;
}
static unsigned int F_27 ( unsigned int V_52 )
{
unsigned int V_53 = 0 , V_54 ;
V_54 = 1 << 8 ;
V_53 = F_28 ( V_52 , V_54 ) ;
if ( V_53 == 0 )
goto V_55;
F_29 ( V_53 , & V_56 , V_57 ,
L_5 ) ;
F_30 ( V_53 , ( void * ) V_52 ) ;
V_55:
return V_53 ;
}
static void F_31 ( struct V_5 * V_6 )
{
T_2 V_58 , V_59 , V_60 , V_61 , V_62 , V_34 ;
struct V_63 T_3 * V_20 = V_6 -> V_20 ;
int V_39 ;
struct V_64 * V_65 = V_6 -> V_66 ;
if ( V_6 -> V_67 ) {
F_18 ( V_32 L_6 ) ;
F_4 ( V_20 -> V_21 , V_68 ) ;
F_32 ( 1 ) ;
}
F_4 ( V_20 -> V_21 , 0 ) ;
F_4 ( V_20 -> V_22 , ~ 0 ) ;
F_4 ( V_20 -> V_69 , 0 ) ;
F_4 ( V_20 -> V_70 , 0 ) ;
F_4 ( V_20 -> V_62 , F_5 ( V_20 -> V_62 ) & 0x0000ffff ) ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
F_4 ( V_20 -> V_71 [ V_39 ] , V_6 -> V_72 ) ;
F_2 ( V_6 , V_18 , 0 , V_73 , & V_6 -> V_74 ) ;
F_10 ( V_6 , V_18 , 0 , V_75 , & V_61 ) ;
F_2 ( V_6 , V_18 , 0 , V_61 + V_76 , & V_62 ) ;
V_62 = ( V_62 & ~ 0x1 ) | ( V_6 -> V_77 ? 1 : 0 ) ;
F_11 ( V_6 , V_18 , 0 , V_61 + V_76 , V_62 ) ;
for ( V_39 = 0 ; V_39 < 6 ; V_39 ++ ) {
if ( V_65 [ V_39 ] . V_59 != ~ 0 && V_65 [ V_39 ] . V_58 != ~ 0 ) {
V_58 = V_65 [ V_39 ] . V_58 ;
V_59 = V_65 [ V_39 ] . V_59 ;
V_60 = ( ( V_59 - 1 ) & ~ V_59 ) + 1 ;
} else {
if ( V_39 == 0 ) {
V_60 = 0xf0000008 ;
V_58 = 0xf0000000 & ( T_2 ) F_33 ( F_34 (
( unsigned long ) & V_78 ) ) ;
V_59 = V_58 ;
} else {
V_60 = 0 ;
V_58 = 0 ;
V_59 = 0 ;
}
}
F_11 ( V_6 , V_18 , 0 , V_61 + V_79 + V_39 * 4 ,
V_60 ) ;
F_11 ( V_6 , V_18 , 0 , V_80 + V_39 * 4 , V_59 ) ;
F_11 ( V_6 , V_18 , 0 , V_61 + V_81 + V_39 * 4 , V_58 ) ;
F_18 ( V_32 L_7 ,
V_39 , V_59 , V_58 ) ;
}
F_2 ( V_6 , V_18 , 0 , V_82 , & V_34 ) ;
V_34 |= ( V_83 | V_84 ) ;
F_11 ( V_6 , V_18 , 0 , V_82 , V_34 ) ;
F_4 ( V_20 -> V_21 , V_85 | V_86 ) ;
}
static T_4 F_35 ( int V_52 , void * V_87 )
{
F_18 ( V_88 L_8 ) ;
return V_89 ;
}
static T_4 F_36 ( int V_52 , void * V_87 )
{
struct V_5 * V_6 = V_87 ;
struct V_63 T_3 * V_20 = V_6 -> V_20 ;
unsigned int V_90 ;
V_90 = F_5 ( V_20 -> V_22 ) ;
if ( ( V_90 & V_42 ) == 0 )
return V_89 ;
if ( V_90 & V_91 )
F_18 ( V_88 L_9 ) ;
if ( V_90 & V_92 )
F_18 ( V_88 L_10 ) ;
if ( V_90 & V_93 )
F_18 ( V_88 L_11 ) ;
if ( V_90 & V_94 )
F_18 ( V_88 L_12 ) ;
F_4 ( V_20 -> V_22 , V_90 & V_42 ) ;
return V_95 ;
}
static int F_37 ( struct V_96 * V_97 )
{
struct V_63 T_3 * V_20 ;
struct V_5 * V_6 ;
int V_98 , V_39 , V_99 ;
const int * V_16 ;
unsigned int V_100 ;
if ( V_29 ) {
F_18 ( V_88 L_13 ) ;
return - V_101 ;
}
if ( V_97 -> V_102 < 3 ) {
F_18 ( V_88 L_14 ) ;
return - V_103 ;
}
V_20 = F_38 ( & V_97 -> V_104 [ 0 ] , 0 ,
F_39 ( & V_97 -> V_104 [ 0 ] ) ,
L_15 ) ;
if ( V_20 == NULL ) {
F_18 ( V_88 L_16 ) ;
return - V_103 ;
}
V_100 = F_5 ( V_20 -> V_22 ) ;
if ( ( V_100 & V_105 ) || ! ( V_100 & V_106 ) ) {
F_18 ( V_32 L_17 ) ;
V_98 = - V_103 ;
goto V_107;
}
V_6 = V_29 = F_40 ( sizeof( struct V_5 ) , V_108 ) ;
if ( V_29 == NULL ) {
V_98 = - V_109 ;
goto V_107;
}
V_6 -> V_20 = V_20 ;
V_6 -> V_52 = V_97 -> V_110 . V_111 [ 0 ] ;
V_6 -> V_46 = ( V_100 & V_112 ) >> V_113 ;
F_18 ( V_32 L_18 , V_20 , V_6 -> V_52 ) ;
V_6 -> V_77 = 1 ;
V_16 = F_41 ( V_97 -> V_2 . V_114 , L_19 , & V_99 ) ;
if ( V_16 && ( V_99 == 2 * 4 * 6 ) )
memcpy ( V_6 -> V_66 , V_16 , 2 * 4 * 6 ) ;
else
memset ( V_6 -> V_66 , - 1 , 2 * 4 * 6 ) ;
V_16 = F_41 ( V_97 -> V_2 . V_114 , L_20 , & V_99 ) ;
if ( V_16 && ( V_99 == 4 ) )
V_6 -> V_67 = * V_16 ;
else
V_6 -> V_115 = 0xf ;
V_16 = F_41 ( V_97 -> V_2 . V_114 , L_21 , & V_99 ) ;
if ( V_16 && ( V_99 == 4 ) )
V_6 -> V_67 = * V_16 ;
else
V_6 -> V_67 = 0 ;
V_6 -> V_72 = V_97 -> V_104 [ 1 ] . V_116 ;
V_6 -> V_117 = V_97 -> V_104 [ 1 ] . V_118 + 1 ;
V_6 -> V_119 = V_97 -> V_104 [ 2 ] . V_116 ;
V_6 -> V_14 = V_97 -> V_104 [ 2 ] . V_116 + 0x10000 ;
V_6 -> V_120 = V_6 -> V_14 + 0x10000 ;
V_6 -> V_121 = ( unsigned long ) F_42 ( V_6 -> V_119 , 0x10000 ) ;
if ( ! V_6 -> V_121 ) {
V_98 = - V_103 ;
goto V_122;
}
F_18 ( V_32
L_22
L_23
L_24 ,
V_6 -> V_72 , V_6 -> V_117 - 1 ,
V_6 -> V_119 , V_6 -> V_14 - 1 ,
V_6 -> V_14 , V_6 -> V_120 - 1 ) ;
memset ( & V_6 -> V_123 . V_124 , 0 , sizeof( struct V_104 ) ) ;
V_6 -> V_123 . V_124 . V_125 = L_25 ;
V_6 -> V_123 . V_124 . V_116 = V_6 -> V_121 + 0x1000 ;
V_6 -> V_123 . V_124 . V_118 = V_6 -> V_121 + 0x10000 - 1 ;
V_6 -> V_123 . V_124 . V_15 = V_126 ;
memset ( & V_6 -> V_123 . V_127 , 0 , sizeof( struct V_104 ) ) ;
V_6 -> V_123 . V_127 . V_125 = L_26 ;
V_6 -> V_123 . V_127 . V_116 = V_6 -> V_72 ;
V_6 -> V_123 . V_127 . V_118 = V_6 -> V_117 - 1 ;
V_6 -> V_123 . V_127 . V_15 = V_128 ;
if ( F_43 ( & V_129 , & V_6 -> V_123 . V_127 ) < 0 )
goto V_130;
if ( F_43 ( & V_131 , & V_6 -> V_123 . V_124 ) < 0 )
goto V_132;
V_6 -> V_123 . V_133 . V_125 = L_27 ;
V_6 -> V_123 . V_133 . V_116 = 0 ;
V_6 -> V_123 . V_133 . V_118 = 255 ;
F_31 ( V_6 ) ;
if ( V_6 -> V_46 < 2 ) {
F_44 ( V_6 -> V_52 , F_25 ,
L_5 , 0 ) ;
V_6 -> V_10 [ 0 ] = F_27 ( 1 ) ;
V_6 -> V_10 [ 1 ] = F_27 ( 2 ) ;
V_6 -> V_10 [ 2 ] = F_27 ( 3 ) ;
V_6 -> V_10 [ 3 ] = F_27 ( 4 ) ;
V_6 -> V_43 = F_27 ( 5 ) ;
if ( V_6 -> V_46 & 1 )
V_6 -> V_49 = V_97 -> V_110 . V_111 [ 1 ] ;
else
V_6 -> V_49 = F_27 ( 6 ) ;
V_98 = F_45 ( V_6 -> V_52 , F_35 , 0 ,
L_28 , V_6 ) ;
if ( V_98 )
F_18 ( V_88 L_29 ) ;
} else {
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
F_44 ( V_97 -> V_110 . V_111 [ V_39 ] ,
V_134 , L_5 ,
1 ) ;
V_6 -> V_10 [ V_39 ] = V_97 -> V_110 . V_111 [ V_39 ] ;
}
V_6 -> V_43 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_46 & 1 )
V_6 -> V_49 = V_97 -> V_110 . V_111 [ 4 ] ;
else
V_6 -> V_49 = V_6 -> V_10 [ 0 ] ;
F_4 ( V_20 -> V_21 , F_5 ( V_20 -> V_21 ) | ( V_6 -> V_115 & 0xf ) ) ;
}
V_98 = F_45 ( V_6 -> V_43 , F_36 , V_135 ,
L_30 , V_6 ) ;
if ( V_98 ) {
F_18 ( V_136 L_31 , V_98 ) ;
goto V_137;
}
F_4 ( V_20 -> V_21 , F_5 ( V_20 -> V_21 ) | V_138 | V_139 ) ;
V_6 -> V_123 . V_140 = & V_141 ;
V_6 -> V_123 . V_142 = F_1 ;
F_46 ( V_97 , & V_6 -> V_123 ) ;
return 0 ;
V_137:
F_47 ( & V_6 -> V_123 . V_124 ) ;
V_132:
F_47 ( & V_6 -> V_123 . V_127 ) ;
V_130:
V_98 = - V_109 ;
F_48 ( ( void T_3 * ) V_6 -> V_121 ) ;
V_122:
F_49 ( V_6 ) ;
V_107:
F_50 ( & V_97 -> V_104 [ 0 ] , V_20 ,
F_39 ( & V_97 -> V_104 [ 0 ] ) ) ;
return V_98 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_143 ) ;
}
