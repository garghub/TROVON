void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
unsigned long V_10 ;
int V_11 ;
T_1 V_12 ;
V_9 = F_3 ( V_7 -> V_2 . V_13 , L_1 , NULL ) ;
if ( ! V_9 ) {
F_4 ( V_14 L_2 ,
V_7 -> V_2 . V_13 -> V_15 ) ;
return;
}
V_11 = V_9 -> V_16 ;
V_10 = V_4 -> V_17 ;
switch ( V_11 ) {
case 0 :
V_10 += 0x20UL ;
break;
case 1 :
V_10 += 0x28UL ;
break;
case 2 :
V_10 += 0x30UL ;
break;
case 3 :
V_10 += 0x38UL ;
break;
case 13 :
V_10 += 0x40UL ;
break;
case 14 :
V_10 += 0x48UL ;
break;
case 15 :
V_10 += 0x50UL ;
break;
default:
return;
}
V_12 = F_5 ( V_10 ) ;
if ( V_12 & ( 1UL << 14UL ) ) {
return;
}
V_12 |= ( 1UL << 14UL ) ;
if ( V_3 & V_18 )
V_12 |= ( 1UL << 1UL ) ;
if ( V_3 & V_19 )
V_12 |= ( 1UL << 2UL ) ;
if ( V_3 & V_20 )
V_12 |= ( 1UL << 3UL ) ;
if ( V_3 & V_21 )
V_12 |= ( 1UL << 4UL ) ;
F_6 ( V_12 , V_10 ) ;
}
static unsigned long F_7 ( unsigned long V_22 )
{
unsigned long V_23 = V_24 - V_25 ;
return V_22 + V_23 ;
}
static unsigned int F_8 ( struct V_6 * V_7 , unsigned int V_26 )
{
struct V_4 * V_4 = V_7 -> V_2 . V_5 . V_4 ;
unsigned long V_27 = V_4 -> V_17 - 0x2000UL ;
unsigned long V_22 , V_28 ;
int V_29 = 0 ;
V_22 = V_30 [ V_26 ] ;
if ( V_22 == ( ( unsigned long ) - 1 ) ) {
F_9 ( L_3 ,
V_26 ) ;
F_10 () ;
}
V_22 += V_27 ;
if ( V_26 >= 0x20 ) {
V_28 = F_7 ( V_22 ) ;
} else {
int V_31 = ( V_26 & 0x18 ) >> 3 ;
V_29 = V_26 & 0x7 ;
switch( V_31 ) {
case 0 :
V_28 = V_27 + V_32 ;
break;
case 1 :
V_28 = V_27 + V_33 ;
break;
case 2 :
V_28 = V_27 + V_34 ;
break;
default:
case 3 :
V_28 = V_27 + V_35 ;
break;
}
V_28 += ( ( unsigned long ) V_29 - 1UL ) * 8UL ;
}
return F_11 ( V_29 , V_28 , V_22 ) ;
}
static T_2 F_12 ( int V_36 , void * V_37 )
{
struct V_6 * V_7 = V_37 ;
struct V_4 * V_4 = V_7 -> V_2 . V_5 . V_4 ;
unsigned long V_27 = V_4 -> V_17 - 0x2000UL ;
unsigned long V_38 , V_39 ;
unsigned long V_40 , V_41 , V_42 ;
int V_43 , V_44 ;
V_38 = V_27 + V_45 ;
V_39 = V_27 + V_46 ;
V_40 = F_5 ( V_38 ) ;
V_41 = F_5 ( V_39 ) ;
V_42 = V_40 &
( V_47 | V_48 | V_49 |
V_50 | V_51 | V_52 ) ;
F_6 ( V_42 , V_38 ) ;
V_44 = F_13 ( V_7 -> V_2 . V_13 , L_4 , - 1 ) ;
F_4 ( L_5 ,
V_44 ,
( ( ( V_42 & V_47 ) ?
L_6 :
( ( V_42 & V_48 ) ?
L_7 :
( ( V_42 & V_49 ) ?
L_8 : L_9 ) ) ) ) ) ;
F_4 ( L_10 ,
V_44 ,
( V_40 & V_53 ) >> 45UL ,
( V_40 & V_54 ) >> 42UL ,
( V_40 & V_55 ) >> 37UL ) ;
F_4 ( L_11 , V_44 , V_41 ) ;
F_4 ( L_12 , V_44 ) ;
V_43 = 0 ;
if ( V_40 & V_50 ) {
V_43 ++ ;
F_4 ( L_13 ) ;
}
if ( V_40 & V_51 ) {
V_43 ++ ;
F_4 ( L_14 ) ;
}
if ( V_40 & V_52 ) {
V_43 ++ ;
F_4 ( L_15 ) ;
}
if ( ! V_43 )
F_4 ( L_16 ) ;
F_4 ( L_17 ) ;
return V_56 ;
}
static T_2 F_14 ( int V_36 , void * V_37 )
{
struct V_6 * V_7 = V_37 ;
struct V_4 * V_4 = V_7 -> V_2 . V_5 . V_4 ;
unsigned long V_27 = V_4 -> V_17 - 0x2000UL ;
unsigned long V_38 , V_39 ;
unsigned long V_40 , V_41 , V_42 ;
int V_43 , V_44 ;
V_38 = V_27 + V_57 ;
V_39 = V_27 + V_58 ;
V_40 = F_5 ( V_38 ) ;
V_41 = F_5 ( V_39 ) ;
V_42 = V_40 &
( V_59 | V_60 | V_61 |
V_62 | V_63 | V_64 ) ;
F_6 ( V_42 , V_38 ) ;
V_44 = F_13 ( V_7 -> V_2 . V_13 , L_4 , - 1 ) ;
F_4 ( L_18 ,
V_44 ,
( ( ( V_42 & V_59 ) ?
L_6 :
( ( V_42 & V_60 ) ?
L_7 :
( ( V_42 & V_61 ) ?
L_8 : L_9 ) ) ) ) ) ;
F_4 ( L_19 ,
V_44 ,
( V_40 & V_65 ) >> 45UL ,
( V_40 & V_66 ) >> 48UL ,
( V_40 & V_67 ) >> 42UL ,
( V_40 & V_68 ) >> 37UL ) ;
F_4 ( L_11 , V_44 , V_41 ) ;
F_4 ( L_20 , V_44 ) ;
V_43 = 0 ;
if ( V_40 & V_62 ) {
V_43 ++ ;
F_4 ( L_13 ) ;
}
if ( V_40 & V_63 ) {
V_43 ++ ;
F_4 ( L_14 ) ;
}
if ( V_40 & V_64 ) {
V_43 ++ ;
F_4 ( L_15 ) ;
}
if ( ! V_43 )
F_4 ( L_16 ) ;
F_4 ( L_17 ) ;
return V_56 ;
}
static T_2 F_15 ( int V_36 , void * V_37 )
{
struct V_6 * V_7 = V_37 ;
struct V_4 * V_4 = V_7 -> V_2 . V_5 . V_4 ;
unsigned long V_38 , V_39 , V_27 ;
unsigned long V_40 , V_41 , V_42 ;
int V_43 , V_44 ;
V_27 = V_4 -> V_17 - 0x2000UL ;
V_38 = V_27 + V_69 ;
V_39 = V_27 + V_70 ;
V_40 = F_5 ( V_38 ) ;
V_41 = F_5 ( V_39 ) ;
V_42 = V_40 &
( V_71 | V_72 | V_73 |
V_74 | V_75 | V_76 ) ;
F_6 ( V_42 , V_38 ) ;
V_44 = F_13 ( V_7 -> V_2 . V_13 , L_4 , - 1 ) ;
F_4 ( L_21 ,
V_44 ,
( ( ( V_42 & V_71 ) ?
L_22 :
( ( V_42 & V_72 ) ?
L_23 :
( ( V_42 & V_73 ) ?
L_24 : L_9 ) ) ) ) ,
( V_40 & V_77 ) ? 1 : 0 ) ;
F_4 ( L_25 ,
V_44 ,
( V_40 & V_78 ) >> 42UL ,
( V_40 & V_79 ) >> 37UL ) ;
F_4 ( L_11 , V_44 , V_41 ) ;
F_4 ( L_26 , V_44 ) ;
V_43 = 0 ;
if ( V_40 & V_74 ) {
V_43 ++ ;
F_4 ( L_27 ) ;
}
if ( V_40 & V_75 ) {
V_43 ++ ;
F_4 ( L_28 ) ;
}
if ( V_40 & V_76 ) {
V_43 ++ ;
F_4 ( L_29 ) ;
}
if ( ! V_43 )
F_4 ( L_16 ) ;
F_4 ( L_17 ) ;
return V_56 ;
}
static void T_3 F_16 ( struct V_6 * V_7 )
{
struct V_4 * V_4 = V_7 -> V_2 . V_5 . V_4 ;
unsigned long V_27 = V_4 -> V_17 - 0x2000UL ;
unsigned int V_36 ;
T_1 V_80 ;
int V_44 ;
V_44 = F_13 ( V_7 -> V_2 . V_13 , L_4 , - 1 ) ;
V_36 = F_8 ( V_7 , V_81 ) ;
if ( F_17 ( V_36 , F_12 , 0 ,
L_30 , V_7 ) < 0 ) {
F_9 ( L_31 ,
V_44 ) ;
F_10 () ;
}
V_36 = F_8 ( V_7 , V_82 ) ;
if ( F_17 ( V_36 , F_14 , 0 ,
L_32 , V_7 ) < 0 ) {
F_9 ( L_33 ,
V_44 ) ;
F_10 () ;
}
V_36 = F_8 ( V_7 , V_83 ) ;
if ( F_17 ( V_36 , F_15 , 0 ,
L_34 , V_7 ) < 0 ) {
F_9 ( L_35 ,
V_44 ) ;
F_10 () ;
}
F_6 ( ( V_84 |
V_85 |
V_86 ) ,
V_27 + V_87 ) ;
V_80 = F_5 ( V_4 -> V_17 ) ;
V_80 |= 0x100UL ;
F_6 ( V_80 , V_4 -> V_17 ) ;
}
static void T_3 F_18 ( struct V_6 * V_7 )
{
const struct V_88 * V_89 ;
struct V_90 * V_91 = V_7 -> V_2 . V_13 ;
struct V_4 * V_4 ;
struct V_92 * V_92 ;
unsigned long V_9 , V_27 ;
int V_93 , V_44 ;
T_1 V_80 ;
V_89 = F_3 ( V_91 , L_1 , NULL ) ;
if ( ! V_89 ) {
F_9 ( L_36
L_37 ) ;
F_10 () ;
}
V_9 = V_89 -> V_94 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_95 ) ;
if ( ! V_4 )
goto V_96;
V_92 = F_19 ( sizeof( * V_92 ) , V_95 ) ;
if ( ! V_92 )
goto V_96;
V_7 -> V_2 . V_5 . V_4 = V_4 ;
V_7 -> V_2 . V_5 . V_97 = V_92 ;
V_7 -> V_2 . V_5 . V_98 = - 1 ;
V_27 = V_9 + V_99 ;
V_4 -> V_100 = V_27 + V_101 ;
V_4 -> V_102 = V_27 + V_103 ;
V_4 -> V_104 = V_27 + V_105 ;
V_4 -> V_106 = V_4 -> V_100 +
( V_107 - V_101 ) ;
V_27 = V_9 + V_108 ;
V_92 -> V_109 = V_27 + V_110 ;
V_92 -> V_111 = V_27 + V_112 ;
V_92 -> V_113 = V_27 + V_114 ;
V_92 -> V_115 = 1 ;
V_92 -> V_116 = ( volatile unsigned long * )
( ( ( ( unsigned long ) & V_92 -> V_117 [ 0 ] )
+ 63UL )
& ~ 63UL ) ;
V_92 -> V_118 = ( unsigned long )
F_20 ( V_92 -> V_116 ) ;
V_4 -> V_17 = V_9 + 0x2000UL ;
V_44 = F_13 ( V_7 -> V_2 . V_13 , L_4 , - 1 ) ;
F_4 ( V_119 L_38 ,
V_44 , V_9 ) ;
if ( F_21 ( V_4 , V_120 , V_121 , 0xffffffff , - 1 ) )
goto V_96;
V_80 = F_5 ( V_4 -> V_100 ) ;
V_80 = ( ( 7UL << 16UL ) |
( 0UL << 2UL ) |
( 1UL << 1UL ) |
( 1UL << 0UL ) ) ;
F_6 ( V_80 , V_4 -> V_100 ) ;
for ( V_93 = 0 ; V_93 < 16 ; V_93 ++ ) {
unsigned long V_122 , V_123 ;
V_122 = V_4 -> V_100 + ( V_124 - V_101 ) ;
V_123 = V_4 -> V_100 + ( V_107 - V_101 ) ;
V_122 += ( unsigned long ) V_93 * 8UL ;
V_123 += ( unsigned long ) V_93 * 8UL ;
F_6 ( 0 , V_122 ) ;
F_6 ( 0 , V_123 ) ;
}
F_5 ( V_4 -> V_17 ) ;
F_6 ( F_20 ( V_4 -> V_125 ) , V_4 -> V_102 ) ;
V_80 = ( 1UL << 1UL ) | ( 1UL << 0UL ) ;
F_6 ( V_80 , V_92 -> V_109 ) ;
for ( V_93 = 0 ; V_93 < 16 ; V_93 ++ ) {
unsigned long V_126 , V_127 ;
V_126 = V_92 -> V_109 +
( V_128 - V_110 ) ;
V_127 = V_92 -> V_109 +
( V_129 - V_110 ) ;
V_126 += ( unsigned long ) V_93 * 8UL ;
V_127 += ( unsigned long ) V_93 * 8UL ;
F_6 ( 0UL , V_126 ) ;
F_6 ( 0UL , V_127 ) ;
}
V_80 = F_5 ( V_4 -> V_17 ) ;
V_80 |= 0x3fUL ;
F_6 ( V_80 , V_4 -> V_17 ) ;
if ( V_130 )
F_22 ( V_44 ) ;
F_16 ( V_7 ) ;
return;
V_96:
F_9 ( L_39 ) ;
}
static int T_3 F_23 ( void )
{
struct V_90 * V_91 ;
F_24 (dp, L_40 ) {
struct V_6 * V_7 = F_25 ( V_91 ) ;
F_18 ( V_7 ) ;
F_26 ( V_7 ) ;
}
return 0 ;
}
