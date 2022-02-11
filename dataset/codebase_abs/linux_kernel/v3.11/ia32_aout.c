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
strncpy ( V_4 . V_55 , V_14 -> V_56 , sizeof( V_14 -> V_56 ) ) ;
V_4 . V_57 = F_10 ( struct V_3 , V_2 ) ;
V_4 . signal = V_48 ;
F_1 ( V_2 , & V_4 ) ;
if ( ( V_4 . V_18 + V_4 . V_20 + 1 ) * V_12 > V_50 )
V_4 . V_18 = 0 ;
if ( ( V_4 . V_20 + 1 ) * V_12 > V_50 )
V_4 . V_20 = 0 ;
F_9 ( V_58 ) ;
if ( ! F_11 ( V_59 , ( void * ) ( unsigned long ) F_12 ( V_4 ) ,
V_4 . V_18 << V_17 ) )
V_4 . V_18 = 0 ;
if ( ! F_11 ( V_59 , ( void * ) ( unsigned long ) F_13 ( V_4 ) ,
V_4 . V_20 << V_17 ) )
V_4 . V_20 = 0 ;
F_9 ( V_54 ) ;
F_14 ( & V_4 , sizeof( V_4 ) ) ;
F_15 ( V_12 - sizeof( V_4 ) ) ;
F_9 ( V_58 ) ;
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
V_60:
F_9 ( V_5 ) ;
return V_51 ;
}
static T_1 T_3 * F_16 ( char T_3 * V_61 , struct V_62 * V_63 )
{
T_1 T_3 * V_64 , * V_65 , * V_11 ;
int V_66 = V_63 -> V_66 , V_67 = V_63 -> V_67 ;
V_11 = ( T_1 T_3 * ) ( ( - ( unsigned long ) sizeof( T_1 ) ) & ( unsigned long ) V_61 ) ;
V_11 -= V_67 + 1 ;
V_65 = V_11 ;
V_11 -= V_66 + 1 ;
V_64 = V_11 ;
F_17 ( ( unsigned long ) V_65 , -- V_11 ) ;
F_17 ( ( unsigned long ) V_64 , -- V_11 ) ;
F_17 ( V_66 , -- V_11 ) ;
V_14 -> V_15 -> V_68 = ( unsigned long ) V_61 ;
while ( V_66 -- > 0 ) {
char V_69 ;
F_17 ( ( T_1 ) ( unsigned long ) V_61 , V_64 ++ ) ;
do {
F_18 ( V_69 , V_61 ++ ) ;
} while ( V_69 );
}
F_17 ( 0 , V_64 ) ;
V_14 -> V_15 -> V_70 = V_14 -> V_15 -> V_71 = ( unsigned long ) V_61 ;
while ( V_67 -- > 0 ) {
char V_69 ;
F_17 ( ( T_1 ) ( unsigned long ) V_61 , V_65 ++ ) ;
do {
F_18 ( V_69 , V_61 ++ ) ;
} while ( V_69 );
}
F_17 ( 0 , V_65 ) ;
V_14 -> V_15 -> V_72 = ( unsigned long ) V_61 ;
return V_11 ;
}
static int F_19 ( struct V_62 * V_63 )
{
unsigned long error , V_73 , V_74 ;
struct V_1 * V_2 = F_20 () ;
struct V_75 V_76 ;
int V_77 ;
V_76 = * ( (struct V_75 * ) V_63 -> V_78 ) ;
if ( ( F_21 ( V_76 ) != V_79 && F_21 ( V_76 ) != V_80 &&
F_21 ( V_76 ) != V_81 && F_21 ( V_76 ) != V_82 ) ||
F_22 ( V_76 ) || F_23 ( V_76 ) ||
F_24 ( F_25 ( V_63 -> V_49 ) ) <
V_76 . V_83 + V_76 . V_84 + F_26 ( V_76 ) + F_27 ( V_76 ) ) {
return - V_85 ;
}
V_73 = F_27 ( V_76 ) ;
V_74 = F_28 ( V_86 ) ;
if ( V_74 >= V_87 )
V_74 = ~ 0 ;
if ( V_76 . V_84 + V_76 . V_88 > V_74 )
return - V_89 ;
V_77 = F_29 ( V_63 ) ;
if ( V_77 )
return V_77 ;
F_30 ( V_90 ) ;
F_31 ( false ) ;
F_32 ( V_63 ) ;
V_2 -> V_41 = V_91 ;
V_2 -> V_92 = V_2 -> V_93 = V_2 -> V_94 = V_2 -> V_95 = V_2 -> V_96 =
V_2 -> V_97 = V_2 -> V_98 = V_2 -> V_99 = 0 ;
V_14 -> V_15 -> V_16 = V_76 . V_83 +
( V_14 -> V_15 -> V_9 = F_33 ( V_76 ) ) ;
V_14 -> V_15 -> V_100 = V_76 . V_84 +
( V_14 -> V_15 -> V_101 = F_34 ( V_76 ) ) ;
V_14 -> V_15 -> V_19 = V_76 . V_88 +
( V_14 -> V_15 -> V_102 = F_35 ( V_76 ) ) ;
V_77 = F_36 ( V_63 , V_103 , V_104 ) ;
if ( V_77 < 0 ) {
F_37 ( V_105 , V_14 , 0 ) ;
return V_77 ;
}
F_38 ( V_63 ) ;
if ( F_21 ( V_76 ) == V_80 ) {
unsigned long V_106 , V_107 ;
V_106 = F_33 ( V_76 ) ;
V_107 = V_76 . V_83 + V_76 . V_84 ;
error = F_6 ( V_106 & V_108 , V_107 ) ;
if ( error != ( V_106 & V_108 ) ) {
F_37 ( V_105 , V_14 , 0 ) ;
return error ;
}
error = F_39 ( V_63 -> V_49 , V_106 , 32 ,
V_76 . V_83 + V_76 . V_84 ) ;
if ( ( signed long ) error < 0 ) {
F_37 ( V_105 , V_14 , 0 ) ;
return error ;
}
} else {
#ifdef F_40
static unsigned long V_109 , V_110 ;
if ( ( V_76 . V_83 & 0xfff || V_76 . V_84 & 0xfff ) &&
( F_21 ( V_76 ) != V_82 ) &&
F_41 ( V_111 , V_110 + 5 * V_112 ) ) {
F_42 ( V_113 L_1 ) ;
V_110 = V_111 ;
}
if ( ( V_73 & ~ V_108 ) != 0 &&
F_41 ( V_111 , V_109 + 5 * V_112 ) ) {
F_42 ( V_114
L_2
L_3 ,
V_63 -> V_49 -> V_115 . V_116 -> V_117 . V_118 ) ;
V_109 = V_111 ;
}
#endif
if ( ! V_63 -> V_49 -> V_119 -> V_120 || ( V_73 & ~ V_108 ) != 0 ) {
F_6 ( F_33 ( V_76 ) , V_76 . V_83 + V_76 . V_84 ) ;
F_39 ( V_63 -> V_49 , F_33 ( V_76 ) , V_73 ,
V_76 . V_83 + V_76 . V_84 ) ;
goto V_121;
}
error = F_43 ( V_63 -> V_49 , F_33 ( V_76 ) , V_76 . V_83 ,
V_122 | V_123 ,
V_124 | V_125 | V_126 |
V_127 | V_128 ,
V_73 ) ;
if ( error != F_33 ( V_76 ) ) {
F_37 ( V_105 , V_14 , 0 ) ;
return error ;
}
error = F_43 ( V_63 -> V_49 , F_34 ( V_76 ) , V_76 . V_84 ,
V_122 | V_129 | V_123 ,
V_124 | V_125 | V_126 |
V_127 | V_128 ,
V_73 + V_76 . V_83 ) ;
if ( error != F_34 ( V_76 ) ) {
F_37 ( V_105 , V_14 , 0 ) ;
return error ;
}
}
V_121:
F_44 ( & V_130 ) ;
F_4 ( V_14 -> V_15 -> V_102 , V_14 -> V_15 -> V_19 ) ;
V_14 -> V_15 -> V_10 =
( unsigned long ) F_16 ( ( char T_3 * ) V_63 -> V_61 , V_63 ) ;
F_45 ( V_5 , 0 ) ;
F_45 ( V_37 , V_131 ) ;
F_45 ( V_38 , V_131 ) ;
F_46 ( 0 ) ;
( V_2 ) -> V_40 = V_76 . V_132 ;
( V_2 ) -> V_11 = V_14 -> V_15 -> V_10 ;
( V_2 ) -> V_42 = 0x200 ;
( V_2 ) -> V_41 = V_91 ;
( V_2 ) -> V_43 = V_131 ;
V_2 -> V_92 = V_2 -> V_93 = V_2 -> V_94 = V_2 -> V_95 =
V_2 -> V_96 = V_2 -> V_97 = V_2 -> V_98 = V_2 -> V_99 = 0 ;
F_9 ( V_58 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_49 )
{
unsigned long V_133 , V_134 , V_135 , error ;
int V_77 ;
struct V_75 V_76 ;
V_77 = - V_85 ;
error = F_48 ( V_49 , 0 , ( char * ) & V_76 , sizeof( V_76 ) ) ;
if ( error != sizeof( V_76 ) )
goto V_136;
if ( ( F_21 ( V_76 ) != V_79 && F_21 ( V_76 ) != V_81 ) || F_22 ( V_76 ) ||
F_23 ( V_76 ) || ( ( V_76 . V_132 & 0xfff ) && F_21 ( V_76 ) == V_79 ) ||
F_24 ( F_25 ( V_49 ) ) <
V_76 . V_83 + V_76 . V_84 + F_26 ( V_76 ) + F_27 ( V_76 ) ) {
goto V_136;
}
if ( F_49 ( V_76 ) )
goto V_136;
V_134 = V_76 . V_132 & 0xfffff000 ;
if ( ( F_27 ( V_76 ) & ~ V_108 ) != 0 ) {
#ifdef F_40
static unsigned long V_109 ;
if ( F_41 ( V_111 , V_109 + 5 * V_112 ) ) {
F_42 ( V_114
L_4
L_5 ,
V_49 -> V_115 . V_116 -> V_117 . V_118 ) ;
V_109 = V_111 ;
}
#endif
F_6 ( V_134 , V_76 . V_83 + V_76 . V_84 + V_76 . V_88 ) ;
F_39 ( V_49 , V_134 , F_27 ( V_76 ) ,
V_76 . V_83 + V_76 . V_84 ) ;
V_77 = 0 ;
goto V_136;
}
error = F_43 ( V_49 , V_134 , V_76 . V_83 + V_76 . V_84 ,
V_122 | V_129 | V_123 ,
V_124 | V_125 | V_126 | V_128 ,
F_27 ( V_76 ) ) ;
V_77 = error ;
if ( error != V_134 )
goto V_136;
V_135 = F_5 ( V_76 . V_83 + V_76 . V_84 ) ;
V_133 = V_76 . V_83 + V_76 . V_84 + V_76 . V_88 ;
if ( V_133 > V_135 ) {
error = F_6 ( V_134 + V_135 , V_133 - V_135 ) ;
V_77 = error ;
if ( error != V_134 + V_135 )
goto V_136;
}
V_77 = 0 ;
V_136:
return V_77 ;
}
static int T_4 F_50 ( void )
{
F_51 ( & V_130 ) ;
return 0 ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_130 ) ;
}
