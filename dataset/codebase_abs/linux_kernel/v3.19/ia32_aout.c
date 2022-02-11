static unsigned long F_1 ( int V_1 )
{
struct V_2 * V_3 = V_4 -> V_5 . V_6 [ V_1 ] ;
return V_3 ? V_3 -> V_7 . V_8 . V_9 : 0 ;
}
static void F_2 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
T_1 V_14 , V_15 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_16 = V_17 ;
V_13 -> V_18 = 0 ;
V_13 -> V_19 = V_11 -> V_20 & ~ ( V_21 - 1 ) ;
V_13 -> V_22 = ( ( unsigned long ) V_4 -> V_23 -> V_24 ) >> V_25 ;
V_13 -> V_26 = ( ( unsigned long )
( V_4 -> V_23 -> V_27 + ( V_21 - 1 ) ) ) >> V_25 ;
V_13 -> V_26 -= V_13 -> V_22 ;
V_13 -> V_28 [ 0 ] = F_1 ( 0 ) ;
V_13 -> V_28 [ 1 ] = F_1 ( 1 ) ;
V_13 -> V_28 [ 2 ] = F_1 ( 2 ) ;
V_13 -> V_28 [ 3 ] = F_1 ( 3 ) ;
V_13 -> V_28 [ 6 ] = V_4 -> V_5 . V_29 ;
V_13 -> V_28 [ 7 ] = V_4 -> V_5 . V_30 ;
if ( V_13 -> V_19 < 0xc0000000 ) {
unsigned long V_31 ;
V_31 = ( unsigned long ) ( 0xc0000000 - V_13 -> V_19 ) ;
V_13 -> V_32 = V_31 >> V_25 ;
}
V_13 -> V_11 . V_33 = V_11 -> V_34 ;
V_13 -> V_11 . V_35 = V_11 -> V_36 ;
V_13 -> V_11 . V_37 = V_11 -> V_38 ;
V_13 -> V_11 . V_39 = V_11 -> V_40 ;
V_13 -> V_11 . V_41 = V_11 -> V_42 ;
V_13 -> V_11 . V_43 = V_11 -> V_3 ;
V_13 -> V_11 . V_44 = V_11 -> V_45 ;
V_13 -> V_11 . V_46 = V_4 -> V_5 . V_46 ;
V_13 -> V_11 . V_47 = V_4 -> V_5 . V_47 ;
F_3 ( V_14 , V_14 ) ;
V_13 -> V_11 . V_14 = V_14 ;
F_3 ( V_15 , V_15 ) ;
V_13 -> V_11 . V_15 = V_15 ;
V_13 -> V_11 . V_48 = V_11 -> V_49 ;
V_13 -> V_11 . V_50 = V_11 -> V_51 ;
V_13 -> V_11 . V_52 = V_11 -> V_52 ;
V_13 -> V_11 . V_53 = V_11 -> V_54 ;
V_13 -> V_11 . V_55 = V_11 -> V_20 ;
V_13 -> V_11 . V_56 = V_11 -> V_56 ;
#if 1
V_13 -> V_57 = 0 ;
#else
V_13 -> V_57 = F_4 ( V_11 , & V_13 -> V_58 ) ;
#endif
}
static void F_5 ( unsigned long V_59 , unsigned long V_60 )
{
V_59 = F_6 ( V_59 ) ;
V_60 = F_6 ( V_60 ) ;
if ( V_60 <= V_59 )
return;
F_7 ( V_59 , V_60 - V_59 ) ;
}
static int F_8 ( struct V_61 * V_62 )
{
T_2 V_14 ;
int V_63 = 0 ;
unsigned long V_64 , V_65 ;
struct V_12 V_13 ;
V_14 = F_9 () ;
F_10 ( V_66 ) ;
V_63 = 1 ;
strncpy ( V_13 . V_67 , V_4 -> V_68 , sizeof( V_4 -> V_68 ) ) ;
V_13 . V_69 = F_11 ( struct V_12 , V_11 ) ;
V_13 . signal = V_62 -> V_70 -> V_71 ;
F_2 ( V_62 -> V_11 , & V_13 ) ;
if ( ( V_13 . V_26 + V_13 . V_32 + 1 ) * V_21 > V_62 -> V_72 )
V_13 . V_26 = 0 ;
if ( ( V_13 . V_32 + 1 ) * V_21 > V_62 -> V_72 )
V_13 . V_32 = 0 ;
F_10 ( V_73 ) ;
if ( ! F_12 ( V_74 , ( void * ) ( unsigned long ) F_13 ( V_13 ) ,
V_13 . V_26 << V_25 ) )
V_13 . V_26 = 0 ;
if ( ! F_12 ( V_74 , ( void * ) ( unsigned long ) F_14 ( V_13 ) ,
V_13 . V_32 << V_25 ) )
V_13 . V_32 = 0 ;
F_10 ( V_66 ) ;
if ( ! F_15 ( V_62 , & V_13 , sizeof( V_13 ) ) )
goto V_75;
if ( ! F_16 ( V_62 , V_21 - sizeof( V_13 ) ) )
goto V_75;
F_10 ( V_73 ) ;
if ( V_13 . V_26 != 0 ) {
V_64 = F_13 ( V_13 ) ;
V_65 = V_13 . V_26 << V_25 ;
if ( ! F_15 ( V_62 , ( void * ) V_64 , V_65 ) )
goto V_75;
}
if ( V_13 . V_32 != 0 ) {
V_64 = F_14 ( V_13 ) ;
V_65 = V_13 . V_32 << V_25 ;
if ( ! F_15 ( V_62 , ( void * ) V_64 , V_65 ) )
goto V_75;
}
V_75:
F_10 ( V_14 ) ;
return V_63 ;
}
static T_1 T_3 * F_17 ( char T_3 * V_76 , struct V_77 * V_78 )
{
T_1 T_3 * V_79 , * V_80 , * V_20 ;
int V_81 = V_78 -> V_81 , V_82 = V_78 -> V_82 ;
V_20 = ( T_1 T_3 * ) ( ( - ( unsigned long ) sizeof( T_1 ) ) & ( unsigned long ) V_76 ) ;
V_20 -= V_82 + 1 ;
V_80 = V_20 ;
V_20 -= V_81 + 1 ;
V_79 = V_20 ;
F_18 ( ( unsigned long ) V_80 , -- V_20 ) ;
F_18 ( ( unsigned long ) V_79 , -- V_20 ) ;
F_18 ( V_81 , -- V_20 ) ;
V_4 -> V_23 -> V_83 = ( unsigned long ) V_76 ;
while ( V_81 -- > 0 ) {
char V_84 ;
F_18 ( ( T_1 ) ( unsigned long ) V_76 , V_79 ++ ) ;
do {
F_19 ( V_84 , V_76 ++ ) ;
} while ( V_84 );
}
F_18 ( 0 , V_79 ) ;
V_4 -> V_23 -> V_85 = V_4 -> V_23 -> V_86 = ( unsigned long ) V_76 ;
while ( V_82 -- > 0 ) {
char V_84 ;
F_18 ( ( T_1 ) ( unsigned long ) V_76 , V_80 ++ ) ;
do {
F_19 ( V_84 , V_76 ++ ) ;
} while ( V_84 );
}
F_18 ( 0 , V_80 ) ;
V_4 -> V_23 -> V_87 = ( unsigned long ) V_76 ;
return V_20 ;
}
static int F_20 ( struct V_77 * V_78 )
{
unsigned long error , V_88 , V_89 ;
struct V_10 * V_11 = F_21 () ;
struct V_90 V_91 ;
int V_92 ;
V_91 = * ( (struct V_90 * ) V_78 -> V_93 ) ;
if ( ( F_22 ( V_91 ) != V_94 && F_22 ( V_91 ) != V_95 &&
F_22 ( V_91 ) != V_96 && F_22 ( V_91 ) != V_97 ) ||
F_23 ( V_91 ) || F_24 ( V_91 ) ||
F_25 ( F_26 ( V_78 -> V_98 ) ) <
V_91 . V_99 + V_91 . V_100 + F_27 ( V_91 ) + F_28 ( V_91 ) ) {
return - V_101 ;
}
V_88 = F_28 ( V_91 ) ;
V_89 = F_29 ( V_102 ) ;
if ( V_89 >= V_103 )
V_89 = ~ 0 ;
if ( V_91 . V_100 + V_91 . V_104 > V_89 )
return - V_105 ;
V_92 = F_30 ( V_78 ) ;
if ( V_92 )
return V_92 ;
F_31 ( V_106 ) ;
F_32 ( false ) ;
F_33 ( V_78 ) ;
V_11 -> V_52 = V_107 ;
V_11 -> V_108 = V_11 -> V_109 = V_11 -> V_110 = V_11 -> V_111 = V_11 -> V_112 =
V_11 -> V_113 = V_11 -> V_114 = V_11 -> V_115 = 0 ;
V_4 -> V_23 -> V_24 = V_91 . V_99 +
( V_4 -> V_23 -> V_18 = F_34 ( V_91 ) ) ;
V_4 -> V_23 -> V_116 = V_91 . V_100 +
( V_4 -> V_23 -> V_117 = F_35 ( V_91 ) ) ;
V_4 -> V_23 -> V_27 = V_91 . V_104 +
( V_4 -> V_23 -> V_118 = F_36 ( V_91 ) ) ;
V_92 = F_37 ( V_78 , V_119 , V_120 ) ;
if ( V_92 < 0 )
return V_92 ;
F_38 ( V_78 ) ;
if ( F_22 ( V_91 ) == V_95 ) {
unsigned long V_121 , V_122 ;
V_121 = F_34 ( V_91 ) ;
V_122 = V_91 . V_99 + V_91 . V_100 ;
error = F_7 ( V_121 & V_123 , V_122 ) ;
if ( error != ( V_121 & V_123 ) )
return error ;
error = F_39 ( V_78 -> V_98 , V_121 , 32 ,
V_91 . V_99 + V_91 . V_100 ) ;
if ( ( signed long ) error < 0 )
return error ;
} else {
#ifdef F_40
static unsigned long V_124 , V_125 ;
if ( ( V_91 . V_99 & 0xfff || V_91 . V_100 & 0xfff ) &&
( F_22 ( V_91 ) != V_97 ) &&
F_41 ( V_126 , V_125 + 5 * V_127 ) ) {
F_42 ( V_128 L_1 ) ;
V_125 = V_126 ;
}
if ( ( V_88 & ~ V_123 ) != 0 &&
F_41 ( V_126 , V_124 + 5 * V_127 ) ) {
F_42 ( V_129
L_2
L_3 ,
V_78 -> V_98 ) ;
V_124 = V_126 ;
}
#endif
if ( ! V_78 -> V_98 -> V_130 -> V_131 || ( V_88 & ~ V_123 ) != 0 ) {
F_7 ( F_34 ( V_91 ) , V_91 . V_99 + V_91 . V_100 ) ;
F_39 ( V_78 -> V_98 , F_34 ( V_91 ) , V_88 ,
V_91 . V_99 + V_91 . V_100 ) ;
goto V_132;
}
error = F_43 ( V_78 -> V_98 , F_34 ( V_91 ) , V_91 . V_99 ,
V_133 | V_134 ,
V_135 | V_136 | V_137 |
V_138 | V_139 ,
V_88 ) ;
if ( error != F_34 ( V_91 ) )
return error ;
error = F_43 ( V_78 -> V_98 , F_35 ( V_91 ) , V_91 . V_100 ,
V_133 | V_140 | V_134 ,
V_135 | V_136 | V_137 |
V_138 | V_139 ,
V_88 + V_91 . V_99 ) ;
if ( error != F_35 ( V_91 ) )
return error ;
}
V_132:
F_44 ( & V_141 ) ;
F_5 ( V_4 -> V_23 -> V_118 , V_4 -> V_23 -> V_27 ) ;
V_4 -> V_23 -> V_19 =
( unsigned long ) F_17 ( ( char T_3 * ) V_78 -> V_76 , V_78 ) ;
F_45 ( V_14 , 0 ) ;
F_45 ( V_46 , V_142 ) ;
F_45 ( V_47 , V_142 ) ;
F_46 ( 0 ) ;
( V_11 ) -> V_51 = V_91 . V_143 ;
( V_11 ) -> V_20 = V_4 -> V_23 -> V_19 ;
( V_11 ) -> V_54 = 0x200 ;
( V_11 ) -> V_52 = V_107 ;
( V_11 ) -> V_56 = V_142 ;
V_11 -> V_108 = V_11 -> V_109 = V_11 -> V_110 = V_11 -> V_111 =
V_11 -> V_112 = V_11 -> V_113 = V_11 -> V_114 = V_11 -> V_115 = 0 ;
F_10 ( V_73 ) ;
return 0 ;
}
static int F_47 ( struct V_98 * V_98 )
{
unsigned long V_144 , V_145 , V_146 , error ;
int V_92 ;
struct V_90 V_91 ;
V_92 = - V_101 ;
error = F_48 ( V_98 , 0 , ( char * ) & V_91 , sizeof( V_91 ) ) ;
if ( error != sizeof( V_91 ) )
goto V_147;
if ( ( F_22 ( V_91 ) != V_94 && F_22 ( V_91 ) != V_96 ) || F_23 ( V_91 ) ||
F_24 ( V_91 ) || ( ( V_91 . V_143 & 0xfff ) && F_22 ( V_91 ) == V_94 ) ||
F_25 ( F_26 ( V_98 ) ) <
V_91 . V_99 + V_91 . V_100 + F_27 ( V_91 ) + F_28 ( V_91 ) ) {
goto V_147;
}
if ( F_49 ( V_91 ) )
goto V_147;
V_145 = V_91 . V_143 & 0xfffff000 ;
if ( ( F_28 ( V_91 ) & ~ V_123 ) != 0 ) {
#ifdef F_40
static unsigned long V_124 ;
if ( F_41 ( V_126 , V_124 + 5 * V_127 ) ) {
F_42 ( V_129
L_4
L_5 ,
V_98 ) ;
V_124 = V_126 ;
}
#endif
F_7 ( V_145 , V_91 . V_99 + V_91 . V_100 + V_91 . V_104 ) ;
F_39 ( V_98 , V_145 , F_28 ( V_91 ) ,
V_91 . V_99 + V_91 . V_100 ) ;
V_92 = 0 ;
goto V_147;
}
error = F_43 ( V_98 , V_145 , V_91 . V_99 + V_91 . V_100 ,
V_133 | V_140 | V_134 ,
V_135 | V_136 | V_137 | V_139 ,
F_28 ( V_91 ) ) ;
V_92 = error ;
if ( error != V_145 )
goto V_147;
V_146 = F_6 ( V_91 . V_99 + V_91 . V_100 ) ;
V_144 = V_91 . V_99 + V_91 . V_100 + V_91 . V_104 ;
if ( V_144 > V_146 ) {
error = F_7 ( V_145 + V_146 , V_144 - V_146 ) ;
V_92 = error ;
if ( error != V_145 + V_146 )
goto V_147;
}
V_92 = 0 ;
V_147:
return V_92 ;
}
static int T_4 F_50 ( void )
{
F_51 ( & V_141 ) ;
return 0 ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_141 ) ;
}
