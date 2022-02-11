static T_1 F_1 ( int V_1 )
{
if ( V_2 )
V_1 <<= V_3 ;
return F_2 ( V_4 + V_1 ) ;
}
static void F_3 ( int V_1 , T_1 V_5 )
{
if ( V_2 )
V_1 <<= V_3 ;
F_4 ( V_5 , V_4 + V_1 ) ;
}
static void F_5 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
else
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
}
static void V_9 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
else
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
}
static void F_6 ( unsigned long V_10 )
{
while ( V_10 > V_11 ) {
F_7 ( V_11 ) ;
V_10 -= V_11 ;
}
F_7 ( V_10 ) ;
}
static int F_8 ( unsigned int V_12 ,
unsigned int V_13 )
{
T_2 V_14 , V_15 ;
V_16 = V_12 ;
V_17 = V_13 ;
V_14 = F_9 ( V_18 . V_19 . V_20 ) ;
V_14 *= V_21 ;
V_15 = V_14 ;
V_15 *= 4295 ;
V_22 = V_14 >> 3 ;
V_22 /= ( V_17 >> 3 ) ;
V_23 = V_22 * V_16 / 100 ;
V_24 = V_22 - V_23 ;
F_10 ( L_1 ,
V_17 , V_16 , F_9 ( V_25 . V_20 ) ,
V_23 , V_24 , V_26 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_12 ,
unsigned int V_13 )
{
if ( 256 * 1000000L / V_13 * V_12 / 100 <=
V_27 )
return - V_28 ;
if ( 256 * 1000000L / V_13 * ( 100 - V_12 ) / 100 <=
V_27 )
return - V_28 ;
V_16 = V_12 ;
V_17 = V_13 ;
V_22 = 256 * 1000000L / V_17 ;
V_23 = V_22 * V_16 / 100 ;
V_24 = V_22 - V_23 ;
F_10 ( L_2 ,
V_17 , V_23 , V_24 ) ;
return 0 ;
}
static long F_11 ( unsigned long V_29 )
{
long V_30 , V_31 ;
int V_32 ;
unsigned char V_33 ;
unsigned char V_34 , V_35 ;
V_30 = V_29 * 1152 / 10000 ;
if ( V_16 > 50 )
V_34 = 3 ;
else
V_34 = 1 ;
for ( V_32 = 0 , V_33 = 0x7f ; V_30 > 0 ; V_30 -= 3 ) {
V_35 = V_34 << ( V_32 * 3 ) ;
V_35 >>= 1 ;
V_33 &= ( ~ V_35 ) ;
V_32 ++ ;
if ( V_32 == 3 ) {
F_3 ( V_36 , V_33 ) ;
while ( ! ( F_1 ( V_37 ) & V_38 ) )
;
V_33 = 0x7f ;
V_32 = 0 ;
}
}
if ( V_32 != 0 ) {
F_3 ( V_36 , V_33 ) ;
while ( ! ( F_1 ( V_37 ) & V_39 ) )
;
}
if ( V_32 == 0 )
V_31 = ( - V_30 ) * 10000 / 1152 ;
else
V_31 = ( 3 - V_32 ) * 3 * 10000 / 1152 + ( - V_30 ) * 10000 / 1152 ;
return V_31 ;
}
static long F_12 ( unsigned long V_29 )
{
int V_40 ;
unsigned long V_41 , V_42 , V_43 ;
V_29 <<= 8 ;
V_41 = 0 ; V_42 = 0 ; V_40 = 0 ;
while ( V_41 < V_29 ) {
if ( V_40 ) {
V_9 () ;
V_42 += V_24 ;
} else {
F_5 () ;
V_42 += V_23 ;
}
V_43 = ( V_42 - V_41 -
V_27 + 128 ) >> 8 ;
F_7 ( V_43 ) ;
V_41 += ( V_43 << 8 ) + V_27 ;
V_40 = ! V_40 ;
}
return ( V_41 - V_29 ) >> 8 ;
}
static long F_13 ( unsigned long V_29 )
{
if ( V_29 <= 0 )
return 0 ;
if ( V_44 )
return F_12 ( V_29 ) ;
F_5 () ;
F_6 ( V_29 ) ;
return 0 ;
}
static void F_14 ( long V_29 )
{
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_15 ( long V_29 )
{
V_9 () ;
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_16 ( int V_45 )
{
if ( F_17 ( & V_46 ) ) {
F_10 ( L_3 ) ;
return;
}
F_18 ( & V_46 , ( void * ) & V_45 ) ;
}
static void F_19 ( int V_45 )
{
static int V_47 , V_48 ;
static unsigned int V_49 ;
if ( V_49 > 0 && ( V_45 & V_50 ) ) {
V_47 += V_45 & V_51 ;
if ( V_47 > 250 ) {
F_16 ( V_48 ) ;
F_16 ( V_47 | V_50 ) ;
V_49 = 0 ;
V_47 = 0 ;
}
return;
}
if ( ! ( V_45 & V_50 ) ) {
if ( V_49 == 0 ) {
if ( V_45 > 20000 ) {
V_48 = V_45 ;
V_49 ++ ;
return;
}
} else {
if ( V_45 > 20000 ) {
V_48 += V_47 ;
if ( V_48 > V_51 )
V_48 = V_51 ;
V_48 += V_45 ;
if ( V_48 > V_51 )
V_48 = V_51 ;
V_47 = 0 ;
return;
}
F_16 ( V_48 ) ;
F_16 ( V_47 | V_50 ) ;
V_49 = 0 ;
V_47 = 0 ;
}
}
F_16 ( V_45 ) ;
}
static T_3 F_20 ( int V_32 , void * V_52 )
{
T_4 V_53 ;
int V_54 , V_55 ;
T_1 V_56 ;
T_4 V_57 ;
int V_58 ;
static int V_59 = - 1 ;
if ( ( F_1 ( V_60 ) & V_61 ) ) {
return V_62 ;
}
V_54 = 0 ;
do {
V_54 ++ ;
V_56 = F_1 ( V_63 ) ;
if ( V_54 > V_64 ) {
F_21 ( L_4 ) ;
break;
}
if ( ( V_56 & V_8 [ type ] . V_65 )
&& V_66 != - 1 ) {
V_53 = F_22 () ;
V_55 = ( V_56 & V_8 [ type ] . V_67 ) ? 1 : 0 ;
if ( V_55 == V_59 ) {
F_21 ( L_5 ,
V_55 , V_66 , F_23 ( V_53 ) ,
F_23 ( V_68 ) ) ;
continue;
}
V_57 = F_24 ( V_53 , V_68 ) ;
if ( F_25 ( V_57 , F_26 ( 15 , 0 ) ) > 0 ) {
V_58 = V_51 ;
if ( ! ( V_55 ^ V_66 ) ) {
F_21 ( L_6 ,
V_55 , V_66 , F_23 ( V_53 ) ,
F_23 ( V_68 ) ) ;
V_66 = V_66 ? 0 : 1 ;
}
} else
V_58 = ( int ) F_23 ( V_57 ) ;
F_19 ( V_55 ^ V_66 ? V_58 : ( V_58 | V_50 ) ) ;
V_68 = V_53 ;
V_59 = V_55 ;
F_27 ( & V_46 . V_69 ) ;
}
} while ( ! ( F_1 ( V_60 ) & V_61 ) );
return V_70 ;
}
static int F_28 ( void )
{
T_1 V_71 , V_72 , V_73 ;
V_71 = F_1 ( V_74 ) ;
F_3 ( V_74 , 0 ) ;
#ifdef F_29
F_4 ( 0xff , 0x080 ) ;
#endif
V_72 = F_1 ( V_74 ) & 0x0f ;
F_3 ( V_74 , 0x0f ) ;
#ifdef F_29
F_4 ( 0x00 , 0x080 ) ;
#endif
V_73 = F_1 ( V_74 ) & 0x0f ;
F_3 ( V_74 , V_71 ) ;
if ( V_72 != 0 || V_73 != 0x0f ) {
F_30 ( L_7 ) ;
return - V_75 ;
}
F_3 ( V_76 , F_1 ( V_76 ) & ( ~ V_77 ) ) ;
F_3 ( V_74 , F_1 ( V_74 ) &
( ~ ( V_78 | V_79 | V_80 | V_81 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_82 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
V_9 () ;
F_1 ( V_37 ) ;
F_1 ( V_82 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
switch ( type ) {
case V_83 :
case V_84 :
F_3 ( V_76 , F_1 ( V_76 ) | V_77 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 1 ) ;
F_3 ( V_76 , V_87 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_88 * V_89 )
{
int V_32 , V_90 , V_91 , V_92 ;
V_92 = F_32 ( & V_89 -> V_89 , V_93 , F_20 ,
( V_94 ? V_95 : 0 ) ,
V_96 , & V_8 ) ;
if ( V_92 < 0 ) {
if ( V_92 == - V_97 )
F_33 ( & V_89 -> V_89 , L_8 , V_93 ) ;
else if ( V_92 == - V_28 )
F_33 ( & V_89 -> V_89 , L_9 ) ;
return V_92 ;
}
if ( ( ( V_2 )
&& ( F_34 ( & V_89 -> V_89 , V_2 , 8 << V_3 ,
V_96 ) == NULL ) )
|| ( ( ! V_2 )
&& ( F_35 ( & V_89 -> V_89 , V_4 , 8 ,
V_96 ) == NULL ) ) ) {
F_33 ( & V_89 -> V_89 , L_10 , V_4 ) ;
F_36 ( & V_89 -> V_89 , L_11 ) ;
F_36 ( & V_89 -> V_89 ,
L_12 ) ;
F_36 ( & V_89 -> V_89 , L_13 ) ;
return - V_97 ;
}
V_92 = F_28 () ;
if ( V_92 < 0 )
return V_92 ;
F_8 ( V_16 , V_17 ) ;
if ( V_66 == - 1 ) {
F_37 ( 500 ) ;
V_90 = 0 ;
V_91 = 0 ;
for ( V_32 = 0 ; V_32 < 9 ; V_32 ++ ) {
if ( F_1 ( V_63 ) & V_8 [ type ] . V_67 )
V_90 ++ ;
else
V_91 ++ ;
F_37 ( 40 ) ;
}
V_66 = V_90 >= V_91 ? 1 : 0 ;
F_38 ( & V_89 -> V_89 , L_14 ,
V_66 ? L_15 : L_16 ) ;
} else
F_38 ( & V_89 -> V_89 , L_17 ,
V_66 ? L_15 : L_16 ) ;
F_39 ( & V_89 -> V_89 , L_18 , V_93 , V_4 ) ;
return 0 ;
}
static int F_40 ( void * V_58 )
{
unsigned long V_98 ;
V_68 = F_22 () ;
F_41 ( & V_8 [ type ] . V_99 , V_98 ) ;
F_3 ( V_76 , F_1 ( V_76 ) & ( ~ V_77 ) ) ;
F_3 ( V_74 , F_1 ( V_74 ) | V_78 ) ;
F_42 ( & V_8 [ type ] . V_99 , V_98 ) ;
return 0 ;
}
static void F_43 ( void * V_58 )
{ unsigned long V_98 ;
F_41 ( & V_8 [ type ] . V_99 , V_98 ) ;
F_3 ( V_76 , F_1 ( V_76 ) & ( ~ V_77 ) ) ;
F_3 ( V_74 , F_1 ( V_74 ) &
( ~ ( V_78 | V_79 | V_80 | V_81 ) ) ) ;
F_42 ( & V_8 [ type ] . V_99 , V_98 ) ;
}
static T_5 F_44 ( struct V_100 * V_100 , const char T_6 * V_101 ,
T_7 V_102 , T_8 * V_103 )
{
int V_32 , V_104 ;
unsigned long V_98 ;
long V_105 = 0 ;
int * V_106 ;
if ( ! ( V_8 [ type ] . V_107 & V_108 ) )
return - V_109 ;
V_104 = V_102 / sizeof( int ) ;
if ( V_102 % sizeof( int ) || V_104 % 2 == 0 )
return - V_28 ;
V_106 = F_45 ( V_101 , V_102 ) ;
if ( F_46 ( V_106 ) )
return F_47 ( V_106 ) ;
F_41 ( & V_8 [ type ] . V_99 , V_98 ) ;
if ( type == V_83 ) {
F_5 () ;
}
for ( V_32 = 0 ; V_32 < V_104 ; V_32 ++ ) {
if ( V_32 % 2 )
V_8 [ type ] . F_48 ( V_106 [ V_32 ] - V_105 ) ;
else
V_105 = V_8 [ type ] . F_49 ( V_106 [ V_32 ] ) ;
}
V_9 () ;
F_42 ( & V_8 [ type ] . V_99 , V_98 ) ;
F_50 ( V_106 ) ;
return V_102 ;
}
static long F_51 ( struct V_100 * V_110 , unsigned int V_111 , unsigned long V_112 )
{
int V_92 ;
T_9 T_6 * V_113 = ( T_9 T_6 * ) V_112 ;
T_9 V_5 ;
switch ( V_111 ) {
case V_114 :
if ( ! ( V_8 [ type ] . V_107 & V_115 ) )
return - V_116 ;
V_92 = F_52 ( F_53
( V_8 [ type ] . V_107 & V_115 ) ,
V_113 ) ;
if ( V_92 )
return V_92 ;
break;
case V_117 :
if ( ! ( V_8 [ type ] . V_107 & V_115 ) )
return - V_116 ;
V_92 = F_54 ( V_5 , V_113 ) ;
if ( V_92 )
return V_92 ;
if ( V_5 != V_118 )
return - V_28 ;
break;
case V_119 :
return - V_116 ;
case V_120 :
F_10 ( L_19 ) ;
if ( ! ( V_8 [ type ] . V_107 & V_121 ) )
return - V_116 ;
V_92 = F_54 ( V_5 , V_113 ) ;
if ( V_92 )
return V_92 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_28 ;
return F_8 ( V_5 , V_17 ) ;
case V_122 :
F_10 ( L_20 ) ;
if ( ! ( V_8 [ type ] . V_107 & V_123 ) )
return - V_116 ;
V_92 = F_54 ( V_5 , V_113 ) ;
if ( V_92 )
return V_92 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_28 ;
return F_8 ( V_16 , V_5 ) ;
default:
return F_55 ( V_110 , V_111 , V_112 ) ;
}
return 0 ;
}
static int F_56 ( struct V_88 * V_89 ,
T_10 V_124 )
{
F_3 ( V_76 , F_1 ( V_76 ) & ( ~ V_77 ) ) ;
F_3 ( V_74 , F_1 ( V_74 ) &
( ~ ( V_78 | V_79 | V_80 | V_81 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_82 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
return 0 ;
}
static int F_57 ( struct V_88 * V_89 )
{
unsigned long V_98 ;
int V_92 ;
V_92 = F_28 () ;
if ( V_92 < 0 )
return V_92 ;
F_41 ( & V_8 [ type ] . V_99 , V_98 ) ;
V_68 = F_22 () ;
F_3 ( V_74 , F_1 ( V_74 ) | V_78 ) ;
V_9 () ;
F_58 ( & V_46 ) ;
F_42 ( & V_8 [ type ] . V_99 , V_98 ) ;
return 0 ;
}
static int T_11 F_59 ( void )
{
int V_92 ;
V_92 = F_60 ( & V_46 , sizeof( int ) , V_125 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_61 ( & V_126 ) ;
if ( V_92 ) {
F_62 ( L_21 , V_92 ) ;
goto V_127;
}
V_128 = F_63 ( L_22 , 0 ) ;
if ( ! V_128 ) {
V_92 = - V_129 ;
goto V_130;
}
V_92 = F_64 ( V_128 ) ;
if ( V_92 )
goto V_131;
return 0 ;
V_131:
F_65 ( V_128 ) ;
V_130:
F_66 ( & V_126 ) ;
V_127:
F_67 ( & V_46 ) ;
return V_92 ;
}
static void F_68 ( void )
{
F_69 ( V_128 ) ;
F_66 ( & V_126 ) ;
F_67 ( & V_46 ) ;
}
static int T_11 F_70 ( void )
{
int V_92 ;
switch ( type ) {
case V_132 :
case V_83 :
case V_84 :
case V_133 :
case V_134 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_93 = V_93 ? V_93 : 4 ;
break;
default:
return - V_28 ;
}
if ( ! V_44 ) {
switch ( type ) {
case V_132 :
case V_134 :
V_8 [ type ] . V_107 &=
~ ( V_121 |
V_123 ) ;
break;
}
}
if ( V_66 != - 1 )
V_66 = ! ! V_66 ;
V_92 = F_59 () ;
if ( V_92 )
return V_92 ;
V_135 . V_107 = V_8 [ type ] . V_107 ;
V_135 . V_89 = & V_128 -> V_89 ;
V_135 . V_136 = F_71 ( & V_135 ) ;
if ( V_135 . V_136 < 0 ) {
F_30 ( L_23 ) ;
F_68 () ;
return V_135 . V_136 ;
}
return 0 ;
}
static void T_12 F_72 ( void )
{
F_73 ( V_135 . V_136 ) ;
F_68 () ;
F_10 ( L_24 ) ;
}
