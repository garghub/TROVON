int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
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
if ( V_7 == 0 && F_3 ( V_11 ) != 0 )
V_11 += ( 0x8 * 6 ) ;
F_4 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_20 , ( F_6 ( V_6 -> V_19 -> V_20 ) & ~ ( 0xff << 16 ) ) |
( V_7 << 16 ) ) ;
F_7 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_21 , ( V_22 | V_23 ) ) ;
V_14 = ( unsigned int * ) ( V_6 -> V_14 |
( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
V_16 = F_8 ( V_14 ) ;
while ( ( F_6 ( V_6 -> V_19 -> V_21 ) & V_23 ) == 0 )
;
if ( F_6 ( V_6 -> V_19 -> V_21 ) & V_22 ) {
* V_13 = 0xffffffff ;
} else {
* V_13 = F_9 ( V_16 ) ;
}
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_24 ;
int V_25 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
* V_13 = 0xffff & ( V_24 >> ( 8 * ( V_12 & 0x3 ) ) ) ;
return V_25 ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_24 ;
int V_25 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
* V_13 = 0xff & ( V_24 >> ( 8 * ( V_12 & 3 ) ) ) ;
return V_25 ;
}
static int F_12 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
unsigned int * V_14 ;
unsigned long V_15 ;
if ( V_12 & 0x3 )
return - V_17 ;
if ( V_7 == 0 && F_3 ( V_11 ) != 0 )
V_11 += ( 0x8 * 6 ) ;
F_4 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_20 , ( F_6 ( V_6 -> V_19 -> V_20 ) & ~ ( 0xff << 16 ) ) |
( V_7 << 16 ) ) ;
F_7 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_21 , ( V_22 | V_23 ) ) ;
V_14 = ( unsigned int * ) ( V_6 -> V_14 |
( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
F_13 ( V_14 , F_9 ( V_13 ) ) ;
while ( ( F_6 ( V_6 -> V_19 -> V_21 ) & V_23 ) == 0 )
;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_25 ;
T_2 V_24 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 3 , & V_24 ) ;
if ( V_25 )
return V_25 ;
V_24 = ( V_24 & ~ ( 0xffff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xffff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_12 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_24 ) ;
}
static int F_15 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_25 ;
T_2 V_24 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
if ( V_25 != 0 )
return V_25 ;
V_24 = ( V_24 & ~ ( 0xff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_12 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_24 ) ;
}
static int F_16 ( struct V_26 * V_7 , unsigned int V_11 ,
int V_12 , int V_27 , T_2 * V_13 )
{
struct V_5 * V_6 = V_28 ;
unsigned int V_29 = V_7 -> V_30 ;
int V_25 ;
if ( F_3 ( V_11 ) > 15 || ( F_3 ( V_11 ) == 0 && V_29 == 0 ) ) {
* V_13 = ~ 0 ;
return 0 ;
}
switch ( V_27 ) {
case 1 :
V_25 = F_11 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
case 2 :
V_25 = F_10 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
case 4 :
V_25 = F_2 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
default:
V_25 = - V_17 ;
break;
}
#ifdef F_17
F_18 ( V_31 L_1
L_2 , V_29 , F_3 ( V_11 ) , F_19 ( V_11 ) , V_12 ,
* V_13 , V_27 ) ;
#endif
return V_25 ;
}
static int F_20 ( struct V_26 * V_7 , unsigned int V_11 ,
int V_12 , int V_27 , T_2 V_13 )
{
struct V_5 * V_6 = V_28 ;
unsigned int V_29 = V_7 -> V_30 ;
if ( F_3 ( V_11 ) > 15 || ( F_3 ( V_11 ) == 0 && V_29 == 0 ) )
return 0 ;
#ifdef F_17
F_18 ( V_31 L_3
L_4 , V_29 , F_3 ( V_11 ) , F_19 ( V_11 ) ,
V_12 , V_27 , V_13 ) ;
#endif
switch ( V_27 ) {
default:
return - V_17 ;
case 1 :
return F_15 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
case 2 :
return F_14 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
case 4 :
return F_12 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
}
}
static void F_21 ( struct V_32 * V_33 )
{
unsigned long V_15 ;
unsigned int V_34 ;
struct V_5 * V_6 = V_28 ;
V_34 = ( unsigned int ) V_33 -> V_35 - 1 ;
if ( V_34 > 3 )
return;
F_4 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_20 , F_6 ( V_6 -> V_19 -> V_20 ) & ~ ( 1 << V_34 ) ) ;
F_7 ( & V_18 , V_15 ) ;
}
static void F_22 ( struct V_32 * V_33 )
{
unsigned long V_15 ;
unsigned int V_34 ;
struct V_5 * V_6 = V_28 ;
V_34 = ( unsigned int ) V_33 -> V_35 - 1 ;
if ( V_34 > 3 )
return;
F_4 ( & V_18 , V_15 ) ;
F_5 ( V_6 -> V_19 -> V_20 , F_6 ( V_6 -> V_19 -> V_20 ) | ( 1 << V_34 ) ) ;
F_7 ( & V_18 , V_15 ) ;
}
static unsigned int F_23 ( struct V_32 * V_33 )
{
F_22 ( V_33 ) ;
return 0 ;
}
static void F_24 ( struct V_32 * V_33 )
{
F_21 ( V_33 ) ;
}
static void F_25 ( unsigned int V_36 , struct V_37 * V_38 )
{
struct V_5 * V_6 = V_28 ;
int V_39 , V_40 = 0 ;
unsigned int V_20 , V_21 , V_41 ;
V_20 = F_6 ( V_6 -> V_19 -> V_20 ) ;
V_21 = F_6 ( V_6 -> V_19 -> V_21 ) ;
if ( V_21 & V_42 ) {
F_26 ( V_6 -> V_43 ) ;
V_40 = 1 ;
}
V_41 = ( ( ~ V_21 ) >> V_44 ) & V_20 & V_45 ;
if ( V_41 ) {
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
if ( V_41 & ( 1 << V_39 ) )
F_26 ( V_6 -> V_10 [ V_39 ] ) ;
}
V_40 = 1 ;
}
if ( ( V_6 -> V_46 == 0 ) && ( V_21 & ( V_47 | V_48 ) ) ) {
F_26 ( V_6 -> V_49 ) ;
V_40 = 1 ;
}
if ( V_40 )
V_38 -> V_32 . V_50 -> V_51 ( & V_38 -> V_32 ) ;
}
static unsigned int F_27 ( unsigned int V_36 )
{
unsigned int V_52 = 0 , V_53 ;
V_53 = 1 << 8 ;
V_52 = F_28 ( V_36 , V_53 ) ;
if ( V_52 == 0 )
goto V_54;
F_29 ( V_52 , & V_55 , V_56 ,
L_5 ) ;
F_30 ( V_52 , ( void * ) V_36 ) ;
V_54:
return V_52 ;
}
void F_31 ( struct V_5 * V_6 )
{
T_2 V_57 , V_58 , V_59 , V_60 , V_61 , V_33 ;
struct V_62 * V_19 = V_6 -> V_19 ;
int V_39 ;
struct V_63 * V_64 = V_6 -> V_65 ;
if ( V_6 -> V_66 ) {
F_18 ( V_31 L_6 ) ;
F_5 ( V_19 -> V_20 , V_67 ) ;
F_32 ( 1 ) ;
}
F_5 ( V_19 -> V_20 , 0 ) ;
F_5 ( V_19 -> V_21 , ~ 0 ) ;
F_5 ( V_19 -> V_68 , 0 ) ;
F_5 ( V_19 -> V_69 , 0 ) ;
F_5 ( V_19 -> V_61 , F_6 ( V_19 -> V_61 ) & 0x0000ffff ) ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
F_5 ( V_19 -> V_70 [ V_39 ] , V_6 -> V_71 ) ;
F_2 ( V_6 , 0 , 0 , V_72 , & V_6 -> V_73 ) ;
F_11 ( V_6 , 0 , 0 , V_74 , & V_60 ) ;
F_2 ( V_6 , 0 , 0 , V_60 + V_75 , & V_61 ) ;
V_61 = ( V_61 & ~ 0x1 ) | ( V_6 -> V_76 ? 1 : 0 ) ;
F_12 ( V_6 , 0 , 0 , V_60 + V_75 , V_61 ) ;
for ( V_39 = 0 ; V_39 < 6 ; V_39 ++ ) {
if ( V_64 [ V_39 ] . V_58 != ~ 0 && V_64 [ V_39 ] . V_57 != ~ 0 ) {
V_57 = V_64 [ V_39 ] . V_57 ;
V_58 = V_64 [ V_39 ] . V_58 ;
V_59 = ( ( V_58 - 1 ) & ~ V_58 ) + 1 ;
} else {
if ( V_39 == 0 ) {
V_59 = 0xf0000008 ;
V_57 = 0xf0000000 & ( T_2 ) F_33 ( F_34 (
( unsigned long ) & V_77 ) ) ;
V_58 = V_57 ;
} else {
V_59 = 0 ;
V_57 = 0 ;
V_58 = 0 ;
}
}
F_12 ( V_6 , 0 , 0 , V_60 + V_78 + V_39 * 4 , V_59 ) ;
F_12 ( V_6 , 0 , 0 , V_79 + V_39 * 4 , V_58 ) ;
F_12 ( V_6 , 0 , 0 , V_60 + V_80 + V_39 * 4 , V_57 ) ;
F_18 ( V_31 L_7 ,
V_39 , V_58 , V_57 ) ;
}
F_2 ( V_6 , 0 , 0 , V_81 , & V_33 ) ;
V_33 |= ( V_82 | V_83 ) ;
F_12 ( V_6 , 0 , 0 , V_81 , V_33 ) ;
F_5 ( V_19 -> V_20 , V_84 | V_85 ) ;
}
static T_3 F_35 ( int V_36 , void * V_86 )
{
F_18 ( V_87 L_8 ) ;
return V_88 ;
}
static T_3 F_36 ( int V_36 , void * V_86 )
{
struct V_5 * V_6 = V_86 ;
struct V_62 * V_19 = V_6 -> V_19 ;
unsigned int V_89 ;
V_89 = F_6 ( V_19 -> V_21 ) ;
if ( ( V_89 & V_42 ) == 0 )
return V_88 ;
if ( V_89 & V_90 )
F_18 ( V_87 L_9 ) ;
if ( V_89 & V_91 )
F_18 ( V_87 L_10 ) ;
if ( V_89 & V_92 )
F_18 ( V_87 L_11 ) ;
if ( V_89 & V_93 )
F_18 ( V_87 L_12 ) ;
F_5 ( V_19 -> V_21 , V_89 & V_42 ) ;
return V_94 ;
}
static int T_4 F_37 ( struct V_95 * V_96 )
{
struct V_62 * V_19 ;
struct V_5 * V_6 ;
int V_97 , V_39 , V_98 ;
const int * V_16 ;
unsigned int V_99 ;
if ( V_28 ) {
F_18 ( V_87 L_13 ) ;
return - V_100 ;
}
if ( V_96 -> V_101 < 3 ) {
F_18 ( V_87 L_14 ) ;
return - V_102 ;
}
V_19 = F_38 ( & V_96 -> V_103 [ 0 ] , 0 ,
F_39 ( & V_96 -> V_103 [ 0 ] ) ,
L_15 ) ;
if ( V_19 == NULL ) {
F_18 ( V_87 L_16 ) ;
return - V_102 ;
}
V_99 = F_6 ( V_19 -> V_21 ) ;
if ( ( V_99 & V_104 ) || ! ( V_99 & V_105 ) ) {
F_18 ( V_31 L_17 ) ;
V_97 = - V_102 ;
goto V_106;
}
V_6 = V_28 = F_40 ( sizeof( struct V_5 ) , V_107 ) ;
if ( V_28 == NULL ) {
V_97 = - V_108 ;
goto V_106;
}
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_36 = V_96 -> V_109 . V_110 [ 0 ] ;
V_6 -> V_46 = ( V_99 & V_111 ) >> V_112 ;
F_18 ( V_31 L_18 , V_19 , V_6 -> V_36 ) ;
V_6 -> V_76 = 1 ;
V_16 = F_41 ( V_96 -> V_2 . V_113 , L_19 , & V_98 ) ;
if ( V_16 && ( V_98 == 2 * 4 * 6 ) )
memcpy ( V_6 -> V_65 , V_16 , 2 * 4 * 6 ) ;
else
memset ( V_6 -> V_65 , - 1 , 2 * 4 * 6 ) ;
V_16 = F_41 ( V_96 -> V_2 . V_113 , L_20 , & V_98 ) ;
if ( V_16 && ( V_98 == 4 ) )
V_6 -> V_66 = * V_16 ;
else
V_6 -> V_114 = 0xf ;
V_16 = F_41 ( V_96 -> V_2 . V_113 , L_21 , & V_98 ) ;
if ( V_16 && ( V_98 == 4 ) )
V_6 -> V_66 = * V_16 ;
else
V_6 -> V_66 = 0 ;
V_6 -> V_71 = V_96 -> V_103 [ 1 ] . V_115 ;
V_6 -> V_116 = V_96 -> V_103 [ 1 ] . V_117 + 1 ;
V_6 -> V_118 = V_96 -> V_103 [ 2 ] . V_115 ;
V_6 -> V_14 = V_96 -> V_103 [ 2 ] . V_115 + 0x10000 ;
V_6 -> V_119 = V_6 -> V_14 + 0x10000 ;
V_6 -> V_120 = ( unsigned long ) F_42 ( V_6 -> V_118 , 0x10000 ) ;
if ( ! V_6 -> V_120 ) {
V_97 = - V_102 ;
goto V_121;
}
F_18 ( V_31
L_22
L_23
L_24 ,
V_6 -> V_71 , V_6 -> V_116 - 1 ,
V_6 -> V_118 , V_6 -> V_14 - 1 ,
V_6 -> V_14 , V_6 -> V_119 - 1 ) ;
memset ( & V_6 -> V_122 . V_123 , 0 , sizeof( struct V_103 ) ) ;
V_6 -> V_122 . V_123 . V_124 = L_25 ;
V_6 -> V_122 . V_123 . V_115 = V_6 -> V_120 + 0x1000 ;
V_6 -> V_122 . V_123 . V_117 = V_6 -> V_120 + 0x10000 - 1 ;
V_6 -> V_122 . V_123 . V_15 = V_125 ;
memset ( & V_6 -> V_122 . V_126 , 0 , sizeof( struct V_103 ) ) ;
V_6 -> V_122 . V_126 . V_124 = L_26 ;
V_6 -> V_122 . V_126 . V_115 = V_6 -> V_71 ;
V_6 -> V_122 . V_126 . V_117 = V_6 -> V_116 - 1 ;
V_6 -> V_122 . V_126 . V_15 = V_127 ;
if ( F_43 ( & V_128 , & V_6 -> V_122 . V_126 ) < 0 )
goto V_129;
if ( F_43 ( & V_130 , & V_6 -> V_122 . V_123 ) < 0 )
goto V_131;
F_31 ( V_6 ) ;
if ( V_6 -> V_46 < 2 ) {
F_44 ( V_6 -> V_36 , F_25 ,
L_5 , 0 ) ;
V_6 -> V_10 [ 0 ] = F_27 ( 1 ) ;
V_6 -> V_10 [ 1 ] = F_27 ( 2 ) ;
V_6 -> V_10 [ 2 ] = F_27 ( 3 ) ;
V_6 -> V_10 [ 3 ] = F_27 ( 4 ) ;
V_6 -> V_43 = F_27 ( 5 ) ;
if ( V_6 -> V_46 & 1 )
V_6 -> V_49 = V_96 -> V_109 . V_110 [ 1 ] ;
else
V_6 -> V_49 = F_27 ( 6 ) ;
V_97 = F_45 ( V_6 -> V_36 , F_35 , 0 ,
L_27 , V_6 ) ;
if ( V_97 )
F_18 ( V_87 L_28 ) ;
} else {
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
F_44 ( V_96 -> V_109 . V_110 [ V_39 ] ,
V_132 , L_5 ,
1 ) ;
V_6 -> V_10 [ V_39 ] = V_96 -> V_109 . V_110 [ V_39 ] ;
}
V_6 -> V_43 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_46 & 1 )
V_6 -> V_49 = V_96 -> V_109 . V_110 [ 4 ] ;
else
V_6 -> V_49 = V_6 -> V_10 [ 0 ] ;
F_5 ( V_19 -> V_20 , F_6 ( V_19 -> V_20 ) | ( V_6 -> V_114 & 0xf ) ) ;
}
V_97 = F_45 ( V_6 -> V_43 , F_36 , V_133 ,
L_29 , V_6 ) ;
if ( V_97 ) {
F_18 ( V_134 L_30 , V_97 ) ;
goto V_135;
}
F_5 ( V_19 -> V_20 , F_6 ( V_19 -> V_20 ) | V_136 | V_137 ) ;
V_6 -> V_122 . V_138 = & V_139 ;
V_6 -> V_122 . V_140 = F_1 ;
F_46 ( V_96 , & V_6 -> V_122 ) ;
return 0 ;
V_135:
F_47 ( & V_6 -> V_122 . V_123 ) ;
V_131:
F_47 ( & V_6 -> V_122 . V_126 ) ;
V_129:
V_97 = - V_108 ;
F_48 ( ( void * ) V_6 -> V_120 ) ;
V_121:
F_49 ( V_6 ) ;
V_106:
F_50 ( & V_96 -> V_103 [ 0 ] , V_19 ,
F_39 ( & V_96 -> V_103 [ 0 ] ) ) ;
return V_97 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_141 ) ;
}
