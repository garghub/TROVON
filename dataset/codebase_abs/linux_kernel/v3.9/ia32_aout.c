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
F_24 ( F_25 ( V_64 -> V_49 ) ) <
V_77 . V_84 + V_77 . V_85 + F_26 ( V_77 ) + F_27 ( V_77 ) ) {
return - V_86 ;
}
V_74 = F_27 ( V_77 ) ;
V_75 = F_28 ( V_87 ) ;
if ( V_75 >= V_88 )
V_75 = ~ 0 ;
if ( V_77 . V_85 + V_77 . V_89 > V_75 )
return - V_90 ;
V_78 = F_29 ( V_64 ) ;
if ( V_78 )
return V_78 ;
F_30 ( V_91 ) ;
F_31 ( false ) ;
F_32 ( V_64 ) ;
V_2 -> V_41 = V_92 ;
V_2 -> V_93 = V_2 -> V_94 = V_2 -> V_95 = V_2 -> V_96 = V_2 -> V_97 =
V_2 -> V_98 = V_2 -> V_99 = V_2 -> V_100 = 0 ;
V_14 -> V_15 -> V_16 = V_77 . V_84 +
( V_14 -> V_15 -> V_9 = F_33 ( V_77 ) ) ;
V_14 -> V_15 -> V_101 = V_77 . V_85 +
( V_14 -> V_15 -> V_102 = F_34 ( V_77 ) ) ;
V_14 -> V_15 -> V_19 = V_77 . V_89 +
( V_14 -> V_15 -> V_103 = F_35 ( V_77 ) ) ;
V_14 -> V_15 -> V_104 = V_105 ;
V_14 -> V_15 -> V_106 = 0 ;
V_78 = F_36 ( V_64 , V_107 , V_108 ) ;
if ( V_78 < 0 ) {
F_37 ( V_109 , V_14 , 0 ) ;
return V_78 ;
}
F_38 ( V_64 ) ;
if ( F_21 ( V_77 ) == V_81 ) {
unsigned long V_110 , V_111 ;
T_4 V_112 ;
V_110 = F_33 ( V_77 ) ;
V_112 = 32 ;
V_111 = V_77 . V_84 + V_77 . V_85 ;
error = F_6 ( V_110 & V_113 , V_111 ) ;
if ( error != ( V_110 & V_113 ) ) {
F_37 ( V_109 , V_14 , 0 ) ;
return error ;
}
error = V_64 -> V_49 -> V_114 -> V_115 ( V_64 -> V_49 ,
( char T_3 * ) V_110 ,
V_77 . V_84 + V_77 . V_85 , & V_112 ) ;
if ( ( signed long ) error < 0 ) {
F_37 ( V_109 , V_14 , 0 ) ;
return error ;
}
F_39 ( V_110 , V_110 + V_77 . V_84 + V_77 . V_85 ) ;
} else {
#ifdef F_40
static unsigned long V_116 , V_117 ;
if ( ( V_77 . V_84 & 0xfff || V_77 . V_85 & 0xfff ) &&
( F_21 ( V_77 ) != V_83 ) &&
F_41 ( V_118 , V_117 + 5 * V_119 ) ) {
F_42 ( V_120 L_1 ) ;
V_117 = V_118 ;
}
if ( ( V_74 & ~ V_113 ) != 0 &&
F_41 ( V_118 , V_116 + 5 * V_119 ) ) {
F_42 ( V_121
L_2
L_3 ,
V_64 -> V_49 -> V_122 . V_123 -> V_124 . V_125 ) ;
V_116 = V_118 ;
}
#endif
if ( ! V_64 -> V_49 -> V_114 -> V_126 || ( V_74 & ~ V_113 ) != 0 ) {
T_4 V_112 = V_74 ;
F_6 ( F_33 ( V_77 ) , V_77 . V_84 + V_77 . V_85 ) ;
V_64 -> V_49 -> V_114 -> V_115 ( V_64 -> V_49 ,
( char T_3 * ) F_33 ( V_77 ) ,
V_77 . V_84 + V_77 . V_85 , & V_112 ) ;
F_39 ( ( unsigned long ) F_33 ( V_77 ) ,
( unsigned long ) F_33 ( V_77 ) +
V_77 . V_84 + V_77 . V_85 ) ;
goto V_127;
}
error = F_43 ( V_64 -> V_49 , F_33 ( V_77 ) , V_77 . V_84 ,
V_128 | V_129 ,
V_130 | V_131 | V_132 |
V_133 | V_134 ,
V_74 ) ;
if ( error != F_33 ( V_77 ) ) {
F_37 ( V_109 , V_14 , 0 ) ;
return error ;
}
error = F_43 ( V_64 -> V_49 , F_34 ( V_77 ) , V_77 . V_85 ,
V_128 | V_135 | V_129 ,
V_130 | V_131 | V_132 |
V_133 | V_134 ,
V_74 + V_77 . V_84 ) ;
if ( error != F_34 ( V_77 ) ) {
F_37 ( V_109 , V_14 , 0 ) ;
return error ;
}
}
V_127:
F_44 ( & V_136 ) ;
F_4 ( V_14 -> V_15 -> V_103 , V_14 -> V_15 -> V_19 ) ;
V_14 -> V_15 -> V_10 =
( unsigned long ) F_16 ( ( char T_3 * ) V_64 -> V_62 , V_64 ) ;
F_45 ( V_5 , 0 ) ;
F_45 ( V_37 , V_137 ) ;
F_45 ( V_38 , V_137 ) ;
F_46 ( 0 ) ;
( V_2 ) -> V_40 = V_77 . V_138 ;
( V_2 ) -> V_11 = V_14 -> V_15 -> V_10 ;
( V_2 ) -> V_42 = 0x200 ;
( V_2 ) -> V_41 = V_92 ;
( V_2 ) -> V_43 = V_137 ;
V_2 -> V_93 = V_2 -> V_94 = V_2 -> V_95 = V_2 -> V_96 =
V_2 -> V_97 = V_2 -> V_98 = V_2 -> V_99 = V_2 -> V_100 = 0 ;
F_9 ( V_59 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_49 )
{
unsigned long V_139 , V_140 , V_141 , error ;
int V_78 ;
struct V_76 V_77 ;
V_78 = - V_86 ;
error = F_48 ( V_49 , 0 , ( char * ) & V_77 , sizeof( V_77 ) ) ;
if ( error != sizeof( V_77 ) )
goto V_142;
if ( ( F_21 ( V_77 ) != V_80 && F_21 ( V_77 ) != V_82 ) || F_22 ( V_77 ) ||
F_23 ( V_77 ) || ( ( V_77 . V_138 & 0xfff ) && F_21 ( V_77 ) == V_80 ) ||
F_24 ( F_25 ( V_49 ) ) <
V_77 . V_84 + V_77 . V_85 + F_26 ( V_77 ) + F_27 ( V_77 ) ) {
goto V_142;
}
if ( F_49 ( V_77 ) )
goto V_142;
V_140 = V_77 . V_138 & 0xfffff000 ;
if ( ( F_27 ( V_77 ) & ~ V_113 ) != 0 ) {
T_4 V_112 = F_27 ( V_77 ) ;
#ifdef F_40
static unsigned long V_116 ;
if ( F_41 ( V_118 , V_116 + 5 * V_119 ) ) {
F_42 ( V_121
L_4
L_5 ,
V_49 -> V_122 . V_123 -> V_124 . V_125 ) ;
V_116 = V_118 ;
}
#endif
F_6 ( V_140 , V_77 . V_84 + V_77 . V_85 + V_77 . V_89 ) ;
V_49 -> V_114 -> V_115 ( V_49 , ( char T_3 * ) V_140 ,
V_77 . V_84 + V_77 . V_85 , & V_112 ) ;
F_39 ( ( unsigned long ) V_140 ,
( unsigned long ) V_140 + V_77 . V_84 +
V_77 . V_85 ) ;
V_78 = 0 ;
goto V_142;
}
error = F_43 ( V_49 , V_140 , V_77 . V_84 + V_77 . V_85 ,
V_128 | V_135 | V_129 ,
V_130 | V_131 | V_132 | V_134 ,
F_27 ( V_77 ) ) ;
V_78 = error ;
if ( error != V_140 )
goto V_142;
V_141 = F_5 ( V_77 . V_84 + V_77 . V_85 ) ;
V_139 = V_77 . V_84 + V_77 . V_85 + V_77 . V_89 ;
if ( V_139 > V_141 ) {
error = F_6 ( V_140 + V_141 , V_139 - V_141 ) ;
V_78 = error ;
if ( error != V_140 + V_141 )
goto V_142;
}
V_78 = 0 ;
V_142:
return V_78 ;
}
static int T_5 F_50 ( void )
{
F_51 ( & V_136 ) ;
return 0 ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_136 ) ;
}
