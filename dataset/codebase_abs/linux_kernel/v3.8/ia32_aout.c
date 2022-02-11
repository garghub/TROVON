static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_2 -> V_11 & ~ ( V_12 - 1 ) ;
V_4 -> V_13 = ( ( unsigned long ) V_14 -> V_15 -> V_16 ) >> V_17 ;
V_4 -> V_18 = ( ( unsigned long )
( V_14 -> V_15 -> V_19 + ( V_12 - 1 ) ) ) >> V_17 ;
V_4 -> V_18 -= V_4 -> V_13 ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 [ 0 ] = V_14 -> V_22 . V_23 ;
V_4 -> V_21 [ 1 ] = V_14 -> V_22 . V_24 ;
V_4 -> V_21 [ 2 ] = V_14 -> V_22 . V_25 ;
V_4 -> V_21 [ 3 ] = V_14 -> V_22 . V_26 ;
V_4 -> V_21 [ 4 ] = 0 ;
V_4 -> V_21 [ 5 ] = 0 ;
V_4 -> V_21 [ 6 ] = V_14 -> V_22 . V_27 ;
V_4 -> V_21 [ 7 ] = V_14 -> V_22 . V_28 ;
if ( V_4 -> V_10 < 0xc0000000 ) {
unsigned long V_29 ;
V_29 = ( unsigned long ) ( 0xc0000000 - V_4 -> V_10 ) ;
V_4 -> V_20 = V_29 >> V_17 ;
}
V_4 -> V_2 . V_30 = V_2 -> V_30 ;
V_4 -> V_2 . V_31 = V_2 -> V_31 ;
V_4 -> V_2 . V_32 = V_2 -> V_32 ;
V_4 -> V_2 . V_33 = V_2 -> V_33 ;
V_4 -> V_2 . V_34 = V_2 -> V_34 ;
V_4 -> V_2 . V_35 = V_2 -> V_35 ;
V_4 -> V_2 . V_36 = V_2 -> V_36 ;
V_4 -> V_2 . V_37 = V_14 -> V_22 . V_37 ;
V_4 -> V_2 . V_38 = V_14 -> V_22 . V_38 ;
F_2 ( V_5 , V_5 ) ;
V_4 -> V_2 . V_5 = V_5 ;
F_2 ( V_6 , V_6 ) ;
V_4 -> V_2 . V_6 = V_6 ;
V_4 -> V_2 . V_39 = V_2 -> V_39 ;
V_4 -> V_2 . V_40 = V_2 -> V_40 ;
V_4 -> V_2 . V_41 = V_2 -> V_41 ;
V_4 -> V_2 . V_42 = V_2 -> V_42 ;
V_4 -> V_2 . V_11 = V_2 -> V_11 ;
V_4 -> V_2 . V_43 = V_2 -> V_43 ;
#if 1
V_4 -> V_44 = 0 ;
#else
V_4 -> V_44 = F_3 ( V_2 , & V_4 -> V_45 ) ;
#endif
}
static void F_4 ( unsigned long V_46 , unsigned long V_47 )
{
V_46 = F_5 ( V_46 ) ;
V_47 = F_5 ( V_47 ) ;
if ( V_47 <= V_46 )
return;
F_6 ( V_46 , V_47 - V_46 ) ;
}
static int F_7 ( long V_48 , struct V_1 * V_2 , struct V_49 * V_49 ,
unsigned long V_50 )
{
T_2 V_5 ;
int V_51 = 0 ;
unsigned long V_52 , V_53 ;
struct V_3 V_4 ;
V_5 = F_8 () ;
F_9 ( V_54 ) ;
V_51 = 1 ;
V_14 -> V_42 |= V_55 ;
strncpy ( V_4 . V_56 , V_14 -> V_57 , sizeof( V_14 -> V_57 ) ) ;
V_4 . V_58 = F_10 ( struct V_3 , V_2 ) ;
V_4 . signal = V_48 ;
F_1 ( V_2 , & V_4 ) ;
if ( ( V_4 . V_18 + V_4 . V_20 + 1 ) * V_12 > V_50 )
V_4 . V_18 = 0 ;
if ( ( V_4 . V_20 + 1 ) * V_12 > V_50 )
V_4 . V_20 = 0 ;
F_9 ( V_59 ) ;
if ( ! F_11 ( V_60 , ( void * ) ( unsigned long ) F_12 ( V_4 ) ,
V_4 . V_18 << V_17 ) )
V_4 . V_18 = 0 ;
if ( ! F_11 ( V_60 , ( void * ) ( unsigned long ) F_13 ( V_4 ) ,
V_4 . V_20 << V_17 ) )
V_4 . V_20 = 0 ;
F_9 ( V_54 ) ;
F_14 ( & V_4 , sizeof( V_4 ) ) ;
F_15 ( V_12 ) ;
F_9 ( V_59 ) ;
if ( V_4 . V_18 != 0 ) {
V_52 = F_12 ( V_4 ) ;
V_53 = V_4 . V_18 << V_17 ;
F_14 ( V_52 , V_53 ) ;
}
if ( V_4 . V_20 != 0 ) {
V_52 = F_13 ( V_4 ) ;
V_53 = V_4 . V_20 << V_17 ;
F_14 ( V_52 , V_53 ) ;
}
V_61:
F_9 ( V_5 ) ;
return V_51 ;
}
static T_1 T_3 * F_16 ( char T_3 * V_62 , struct V_63 * V_64 )
{
T_1 T_3 * V_65 , * V_66 , * V_11 ;
int V_67 = V_64 -> V_67 , V_68 = V_64 -> V_68 ;
V_11 = ( T_1 T_3 * ) ( ( - ( unsigned long ) sizeof( T_1 ) ) & ( unsigned long ) V_62 ) ;
V_11 -= V_68 + 1 ;
V_66 = V_11 ;
V_11 -= V_67 + 1 ;
V_65 = V_11 ;
F_17 ( ( unsigned long ) V_66 , -- V_11 ) ;
F_17 ( ( unsigned long ) V_65 , -- V_11 ) ;
F_17 ( V_67 , -- V_11 ) ;
V_14 -> V_15 -> V_69 = ( unsigned long ) V_62 ;
while ( V_67 -- > 0 ) {
char V_70 ;
F_17 ( ( T_1 ) ( unsigned long ) V_62 , V_65 ++ ) ;
do {
F_18 ( V_70 , V_62 ++ ) ;
} while ( V_70 );
}
F_17 ( 0 , V_65 ) ;
V_14 -> V_15 -> V_71 = V_14 -> V_15 -> V_72 = ( unsigned long ) V_62 ;
while ( V_68 -- > 0 ) {
char V_70 ;
F_17 ( ( T_1 ) ( unsigned long ) V_62 , V_66 ++ ) ;
do {
F_18 ( V_70 , V_62 ++ ) ;
} while ( V_70 );
}
F_17 ( 0 , V_66 ) ;
V_14 -> V_15 -> V_73 = ( unsigned long ) V_62 ;
return V_11 ;
}
static int F_19 ( struct V_63 * V_64 )
{
unsigned long error , V_74 , V_75 ;
struct V_1 * V_2 = F_20 () ;
struct V_76 V_77 ;
int V_78 ;
V_77 = * ( (struct V_76 * ) V_64 -> V_79 ) ;
if ( ( F_21 ( V_77 ) != V_80 && F_21 ( V_77 ) != V_81 &&
F_21 ( V_77 ) != V_82 && F_21 ( V_77 ) != V_83 ) ||
F_22 ( V_77 ) || F_23 ( V_77 ) ||
F_24 ( V_64 -> V_49 -> V_84 . V_85 -> V_86 ) <
V_77 . V_87 + V_77 . V_88 + F_25 ( V_77 ) + F_26 ( V_77 ) ) {
return - V_89 ;
}
V_74 = F_26 ( V_77 ) ;
V_75 = F_27 ( V_90 ) ;
if ( V_75 >= V_91 )
V_75 = ~ 0 ;
if ( V_77 . V_88 + V_77 . V_92 > V_75 )
return - V_93 ;
V_78 = F_28 ( V_64 ) ;
if ( V_78 )
return V_78 ;
F_29 ( V_94 ) ;
F_30 ( false ) ;
F_31 ( V_64 ) ;
V_2 -> V_41 = V_95 ;
V_2 -> V_96 = V_2 -> V_97 = V_2 -> V_98 = V_2 -> V_99 = V_2 -> V_100 =
V_2 -> V_101 = V_2 -> V_102 = V_2 -> V_103 = 0 ;
V_14 -> V_15 -> V_16 = V_77 . V_87 +
( V_14 -> V_15 -> V_9 = F_32 ( V_77 ) ) ;
V_14 -> V_15 -> V_104 = V_77 . V_88 +
( V_14 -> V_15 -> V_105 = F_33 ( V_77 ) ) ;
V_14 -> V_15 -> V_19 = V_77 . V_92 +
( V_14 -> V_15 -> V_106 = F_34 ( V_77 ) ) ;
V_14 -> V_15 -> V_107 = V_108 ;
V_14 -> V_15 -> V_109 = 0 ;
V_78 = F_35 ( V_64 , V_110 , V_111 ) ;
if ( V_78 < 0 ) {
F_36 ( V_112 , V_14 , 0 ) ;
return V_78 ;
}
F_37 ( V_64 ) ;
if ( F_21 ( V_77 ) == V_81 ) {
unsigned long V_113 , V_114 ;
T_4 V_115 ;
V_113 = F_32 ( V_77 ) ;
V_115 = 32 ;
V_114 = V_77 . V_87 + V_77 . V_88 ;
error = F_6 ( V_113 & V_116 , V_114 ) ;
if ( error != ( V_113 & V_116 ) ) {
F_36 ( V_112 , V_14 , 0 ) ;
return error ;
}
error = V_64 -> V_49 -> V_117 -> V_118 ( V_64 -> V_49 ,
( char T_3 * ) V_113 ,
V_77 . V_87 + V_77 . V_88 , & V_115 ) ;
if ( ( signed long ) error < 0 ) {
F_36 ( V_112 , V_14 , 0 ) ;
return error ;
}
F_38 ( V_113 , V_113 + V_77 . V_87 + V_77 . V_88 ) ;
} else {
#ifdef F_39
static unsigned long V_119 , V_120 ;
if ( ( V_77 . V_87 & 0xfff || V_77 . V_88 & 0xfff ) &&
( F_21 ( V_77 ) != V_83 ) &&
F_40 ( V_121 , V_120 + 5 * V_122 ) ) {
F_41 ( V_123 L_1 ) ;
V_120 = V_121 ;
}
if ( ( V_74 & ~ V_116 ) != 0 &&
F_40 ( V_121 , V_119 + 5 * V_122 ) ) {
F_41 ( V_124
L_2
L_3 ,
V_64 -> V_49 -> V_84 . V_85 -> V_125 . V_126 ) ;
V_119 = V_121 ;
}
#endif
if ( ! V_64 -> V_49 -> V_117 -> V_127 || ( V_74 & ~ V_116 ) != 0 ) {
T_4 V_115 = V_74 ;
F_6 ( F_32 ( V_77 ) , V_77 . V_87 + V_77 . V_88 ) ;
V_64 -> V_49 -> V_117 -> V_118 ( V_64 -> V_49 ,
( char T_3 * ) F_32 ( V_77 ) ,
V_77 . V_87 + V_77 . V_88 , & V_115 ) ;
F_38 ( ( unsigned long ) F_32 ( V_77 ) ,
( unsigned long ) F_32 ( V_77 ) +
V_77 . V_87 + V_77 . V_88 ) ;
goto V_128;
}
error = F_42 ( V_64 -> V_49 , F_32 ( V_77 ) , V_77 . V_87 ,
V_129 | V_130 ,
V_131 | V_132 | V_133 |
V_134 | V_135 ,
V_74 ) ;
if ( error != F_32 ( V_77 ) ) {
F_36 ( V_112 , V_14 , 0 ) ;
return error ;
}
error = F_42 ( V_64 -> V_49 , F_33 ( V_77 ) , V_77 . V_88 ,
V_129 | V_136 | V_130 ,
V_131 | V_132 | V_133 |
V_134 | V_135 ,
V_74 + V_77 . V_87 ) ;
if ( error != F_33 ( V_77 ) ) {
F_36 ( V_112 , V_14 , 0 ) ;
return error ;
}
}
V_128:
F_43 ( & V_137 ) ;
F_4 ( V_14 -> V_15 -> V_106 , V_14 -> V_15 -> V_19 ) ;
V_14 -> V_15 -> V_10 =
( unsigned long ) F_16 ( ( char T_3 * ) V_64 -> V_62 , V_64 ) ;
F_44 ( V_5 , 0 ) ;
F_44 ( V_37 , V_138 ) ;
F_44 ( V_38 , V_138 ) ;
F_45 ( 0 ) ;
( V_2 ) -> V_40 = V_77 . V_139 ;
( V_2 ) -> V_11 = V_14 -> V_15 -> V_10 ;
( V_2 ) -> V_42 = 0x200 ;
( V_2 ) -> V_41 = V_95 ;
( V_2 ) -> V_43 = V_138 ;
V_2 -> V_96 = V_2 -> V_97 = V_2 -> V_98 = V_2 -> V_99 =
V_2 -> V_100 = V_2 -> V_101 = V_2 -> V_102 = V_2 -> V_103 = 0 ;
F_9 ( V_59 ) ;
return 0 ;
}
static int F_46 ( struct V_49 * V_49 )
{
struct V_140 * V_140 ;
unsigned long V_141 , V_142 , V_143 , error ;
int V_78 ;
struct V_76 V_77 ;
V_140 = V_49 -> V_84 . V_85 -> V_86 ;
V_78 = - V_89 ;
error = F_47 ( V_49 , 0 , ( char * ) & V_77 , sizeof( V_77 ) ) ;
if ( error != sizeof( V_77 ) )
goto V_144;
if ( ( F_21 ( V_77 ) != V_80 && F_21 ( V_77 ) != V_82 ) || F_22 ( V_77 ) ||
F_23 ( V_77 ) || ( ( V_77 . V_139 & 0xfff ) && F_21 ( V_77 ) == V_80 ) ||
F_24 ( V_140 ) <
V_77 . V_87 + V_77 . V_88 + F_25 ( V_77 ) + F_26 ( V_77 ) ) {
goto V_144;
}
if ( F_48 ( V_77 ) )
goto V_144;
V_142 = V_77 . V_139 & 0xfffff000 ;
if ( ( F_26 ( V_77 ) & ~ V_116 ) != 0 ) {
T_4 V_115 = F_26 ( V_77 ) ;
#ifdef F_39
static unsigned long V_119 ;
if ( F_40 ( V_121 , V_119 + 5 * V_122 ) ) {
F_41 ( V_124
L_4
L_5 ,
V_49 -> V_84 . V_85 -> V_125 . V_126 ) ;
V_119 = V_121 ;
}
#endif
F_6 ( V_142 , V_77 . V_87 + V_77 . V_88 + V_77 . V_92 ) ;
V_49 -> V_117 -> V_118 ( V_49 , ( char T_3 * ) V_142 ,
V_77 . V_87 + V_77 . V_88 , & V_115 ) ;
F_38 ( ( unsigned long ) V_142 ,
( unsigned long ) V_142 + V_77 . V_87 +
V_77 . V_88 ) ;
V_78 = 0 ;
goto V_144;
}
error = F_42 ( V_49 , V_142 , V_77 . V_87 + V_77 . V_88 ,
V_129 | V_136 | V_130 ,
V_131 | V_132 | V_133 | V_135 ,
F_26 ( V_77 ) ) ;
V_78 = error ;
if ( error != V_142 )
goto V_144;
V_143 = F_5 ( V_77 . V_87 + V_77 . V_88 ) ;
V_141 = V_77 . V_87 + V_77 . V_88 + V_77 . V_92 ;
if ( V_141 > V_143 ) {
error = F_6 ( V_142 + V_143 , V_141 - V_143 ) ;
V_78 = error ;
if ( error != V_142 + V_143 )
goto V_144;
}
V_78 = 0 ;
V_144:
return V_78 ;
}
static int T_5 F_49 ( void )
{
F_50 ( & V_137 ) ;
return 0 ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_137 ) ;
}
