static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline void F_5 ( T_1 V_1 , T_1 V_4 , T_1 V_3 )
{
T_1 V_5 = F_1 ( V_1 ) ;
V_5 &= ~ V_4 ;
V_5 |= V_3 ;
F_3 ( V_1 , V_5 ) ;
}
static T_2 F_6 ( int V_6 , void * V_7 )
{
T_1 V_8 = F_1 ( V_9 ) ;
T_1 V_10 = F_1 ( V_11 ) ;
T_1 V_12 = F_1 ( V_13 ) ;
T_1 V_14 = F_1 ( V_15 ) ;
F_7 ( L_1 ,
V_10 , V_8 , V_14 , V_12 ) ;
F_8 ( L_2 ) ;
return V_16 ;
}
static void F_9 ( unsigned V_17 , struct V_18 * V_19 )
{
T_1 V_20 = F_1 ( V_21 ) &
F_1 ( V_22 ) ;
unsigned V_23 , V_24 = 0 ;
if ( V_20 ) {
struct V_25 * V_26 = F_10 ( V_19 ) ;
V_23 = F_11 ( V_20 ) ;
V_24 = F_12 ( V_26 , V_23 ) ;
}
if ( V_24 ) {
F_13 ( V_24 ) ;
if ( V_23 == V_27 )
F_1 ( V_28 ) ;
} else {
F_14 () ;
}
}
static void F_15 ( struct V_29 * V_30 )
{
F_5 ( V_22 , 0 , F_16 ( V_30 -> V_31 ) ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
F_5 ( V_22 , F_16 ( V_30 -> V_31 ) , 0 ) ;
F_1 ( V_22 ) ;
}
static int F_18 ( struct V_25 * V_30 , unsigned V_17 ,
T_3 V_32 )
{
F_19 ( V_17 , & V_33 , V_34 ) ;
return 0 ;
}
static void F_20 ( void )
{
T_1 V_20 = F_21 () & F_22 () ;
if ( V_20 & V_35 )
F_23 ( V_36 ) ;
else if ( V_20 & V_37 )
F_23 ( V_38 ) ;
else if ( V_20 & V_39 )
F_23 ( V_40 ) ;
else if ( V_20 & V_41 )
F_23 ( V_42 ) ;
else
F_14 () ;
}
void T_4 F_24 ( void )
{
struct V_25 * V_26 ;
unsigned V_17 ;
V_43 = F_20 ;
V_26 = F_25 ( NULL , V_44 ,
& V_45 , NULL ) ;
if ( ! V_26 )
F_26 ( L_3 ) ;
V_17 = F_27 ( V_26 , V_46 ) ;
F_28 ( V_17 , & V_47 ) ;
F_29 ( V_40 ,
F_9 , V_26 ) ;
V_48 = V_26 ;
}
static void T_4 F_30 ( void )
{
void T_5 * V_49 ;
T_1 V_50 ;
V_49 = F_31 ( V_51 ,
V_52 ) ;
V_50 = F_2 ( V_49 + V_53 ) ;
V_50 &= V_54 ;
switch ( V_50 ) {
case V_55 :
V_56 . V_57 = 2 ;
break;
case V_58 :
default:
V_56 . V_57 = 1 ;
break;
}
V_50 |= V_59 | V_60 | V_61 ;
V_50 |= 0x01 << V_62 ;
V_50 |= 0x07 << V_63 ;
V_50 |= 0x07 << V_64 ;
F_4 ( V_50 , V_49 + V_53 ) ;
V_50 = F_2 ( V_49 + V_65 ) ;
V_50 &= ~ ( V_59 | V_66 ) ;
F_4 ( V_50 , V_49 + V_65 ) ;
V_50 = F_2 ( V_49 + V_67 ) ;
V_50 &= ~ ( V_59 | V_66 ) ;
F_4 ( V_50 , V_49 + V_67 ) ;
F_32 ( V_49 ) ;
}
void T_4 F_33 ( void )
{
struct V_68 * V_69 ;
F_30 () ;
F_34 ( V_70 , V_71 ) ;
V_69 = V_72 . V_69 ;
if ( ( V_73 . V_74 & 0xff ) == 0x0a )
V_75 = V_76 ;
else if ( V_69 -> V_77 & V_78 )
V_75 = V_79 ;
else
V_75 = V_80 ;
F_35 ( & V_81 ) ;
switch ( V_75 ) {
case V_80 :
if ( ! V_72 . V_82 )
return;
if ( ! ( V_69 -> V_77 & V_83 ) )
break;
F_36 ( 0 , V_84 , V_36 ) ;
break;
case V_79 :
case V_76 :
if ( ! V_72 . V_82 )
return;
break;
default:
break;
}
if ( V_69 -> V_77 & V_85 )
F_36 ( 1 , V_86 , V_38 ) ;
}
static void F_37 ( char * V_87 )
{
F_38 () ;
while ( 1 )
F_3 ( V_88 , V_89 ) ;
}
static unsigned T_4 F_39 ( void )
{
T_1 V_90 , V_91 , V_92 ;
T_1 V_93 , V_94 , V_95 ;
unsigned V_96 , V_97 ;
unsigned V_98 , V_99 , V_100 ;
V_90 = F_1 ( V_101 ) ;
if ( V_90 )
return V_90 ;
V_91 = F_1 ( V_102 ) ;
V_91 = ( V_91 & V_103 ) >> V_104 ;
if ( V_91 == V_105 ) {
V_93 = V_106 ;
V_96 = V_107 ;
V_94 = V_108 ;
V_97 = V_109 ;
V_95 = V_110 ;
} else {
V_93 = V_111 ;
V_96 = V_112 ;
V_94 = V_113 ;
V_97 = V_114 ;
V_95 = V_115 ;
}
V_92 = F_1 ( V_116 ) ;
V_98 = ( V_92 & V_93 ) >> V_96 ;
V_99 = V_117 [ V_98 ] ;
V_100 = ( V_92 & V_94 ) >> V_97 ;
if ( V_92 & V_95 )
V_100 <<= 1 ;
return ( 40000000 / V_99 ) * V_100 ;
}
static inline unsigned F_40 ( void )
{
return F_39 () / 4 ;
}
void T_4 F_41 ( void )
{
V_118 = F_39 () / 2 ;
}
void T_4 F_42 ( void )
{
void T_5 * V_119 ;
T_1 V_120 , V_121 , V_122 , V_123 ;
T_1 V_91 ;
V_119 = F_31 ( V_124 ,
V_125 ) ;
V_121 = F_2 ( V_119 + V_126 ) ;
V_122 = F_43 ( V_121 , V_127 ) ;
V_123 = F_43 ( V_121 , V_128 ) ;
V_120 = ( V_122 ? ( 1 << ( V_122 + 1 ) ) : 0 ) +
( V_123 ? ( 1 << ( V_123 + 1 ) ) : 0 ) ;
V_120 <<= 20 ;
F_44 ( 0 , V_120 , V_129 ) ;
F_32 ( V_119 ) ;
V_2 = F_31 ( V_130 , V_131 ) ;
V_91 = F_1 ( V_102 ) ;
V_91 >>= V_132 ;
V_91 &= V_133 ;
V_72 . V_91 = ( V_134 ) V_91 ;
F_1 ( V_11 ) ;
F_1 ( V_15 ) ;
F_3 ( V_135 , V_136 ) ;
V_137 = F_37 ;
}
void T_4 F_45 ( void )
{
unsigned V_17 = F_27 ( V_48 ,
V_138 ) ;
F_46 ( V_139 , V_17 , F_40 () ) ;
}
