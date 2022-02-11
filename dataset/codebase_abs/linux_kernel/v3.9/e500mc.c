void F_1 ( struct V_1 * V_2 , enum V_3 type )
{
enum V_4 V_5 ;
unsigned long V_6 ;
switch ( type ) {
case V_7 :
V_5 = V_8 ;
break;
case V_9 :
V_5 = V_10 ;
break;
case V_11 :
V_5 = V_12 ;
break;
default:
F_2 ( 1 , L_1 , V_13 , type ) ;
return;
}
V_6 = F_3 ( V_2 -> V_14 -> V_15 . V_16 ) | V_2 -> V_17 ;
F_4 () ;
F_5 ( V_5 , 0 , V_6 ) ;
}
void F_6 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned int V_22 , V_23 ;
T_1 V_24 ;
T_2 V_25 , V_16 ;
unsigned long V_26 ;
V_23 = F_7 ( V_21 ) ;
V_22 = F_8 ( V_21 ) ;
V_16 = V_19 -> V_2 . V_14 -> V_15 . V_16 ;
V_25 = ( V_22 << 16 ) | V_23 ;
V_24 = F_9 ( V_21 ) ;
F_10 ( V_26 ) ;
F_11 ( V_27 , V_25 ) ;
F_11 ( V_28 , V_29 | V_16 ) ;
asm volatile("tlbsx 0, %[eaddr]\n" : : [eaddr] "r" (eaddr));
V_25 = F_12 ( V_30 ) ;
if ( V_25 & V_31 ) {
F_11 ( V_30 , V_25 & ~ V_31 ) ;
asm volatile("tlbwe");
}
F_11 ( V_28 , 0 ) ;
F_11 ( V_32 , 0 ) ;
F_13 () ;
F_14 ( V_26 ) ;
}
void F_15 ( struct V_18 * V_19 )
{
unsigned long V_26 ;
F_10 ( V_26 ) ;
F_11 ( V_28 , V_29 | V_19 -> V_2 . V_14 -> V_15 . V_16 ) ;
asm volatile("tlbilxlpid");
F_11 ( V_28 , 0 ) ;
F_14 ( V_26 ) ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_15 . V_33 = V_33 ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_34 )
{
}
void F_18 ( struct V_1 * V_2 , int V_35 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
F_20 ( V_2 , V_35 ) ;
F_11 ( V_36 , V_2 -> V_14 -> V_15 . V_16 ) ;
F_11 ( V_37 , V_2 -> V_15 . V_38 ) ;
F_11 ( V_39 , V_2 -> V_17 ) ;
F_11 ( V_40 , V_2 -> V_15 . V_41 ) ;
F_11 ( V_42 , V_2 -> V_15 . V_43 ) ;
F_11 ( V_44 , V_2 -> V_15 . V_45 ) ;
F_11 ( V_46 , V_2 -> V_15 . V_47 ) ;
F_11 ( V_48 , V_2 -> V_15 . V_49 [ V_50 ] ) ;
F_11 ( V_51 , V_2 -> V_15 . V_49 [ V_52 ] ) ;
F_11 ( V_53 , ( unsigned long ) V_2 -> V_15 . V_54 -> V_55 ) ;
F_11 ( V_56 , ( unsigned long ) V_2 -> V_15 . V_54 -> V_57 ) ;
F_11 ( V_58 , ( unsigned long ) V_2 -> V_15 . V_54 -> V_59 ) ;
F_11 ( V_60 , ( unsigned long ) V_2 -> V_15 . V_54 -> V_61 ) ;
F_11 ( V_62 , V_2 -> V_15 . V_54 -> V_63 ) ;
F_11 ( V_64 , V_2 -> V_15 . V_54 -> V_65 ) ;
F_11 ( V_66 , V_2 -> V_15 . V_67 ) ;
F_11 ( V_68 , V_2 -> V_15 . V_54 -> V_69 ) ;
F_11 ( V_70 , V_2 -> V_15 . V_54 -> V_71 ) ;
if ( V_2 -> V_15 . V_72 != F_12 ( V_73 ) ||
F_21 ( V_74 ) != V_2 ) {
F_15 ( V_19 ) ;
F_21 ( V_74 ) = V_2 ;
}
F_22 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_43 = F_12 ( V_42 ) ;
V_2 -> V_15 . V_45 = F_12 ( V_44 ) ;
V_2 -> V_15 . V_54 -> V_55 = F_12 ( V_53 ) ;
V_2 -> V_15 . V_54 -> V_57 = F_12 ( V_56 ) ;
V_2 -> V_15 . V_54 -> V_59 = F_12 ( V_58 ) ;
V_2 -> V_15 . V_54 -> V_61 = F_12 ( V_60 ) ;
V_2 -> V_15 . V_54 -> V_63 = F_12 ( V_62 ) ;
V_2 -> V_15 . V_54 -> V_65 = F_12 ( V_64 ) ;
V_2 -> V_15 . V_67 = F_12 ( V_66 ) ;
V_2 -> V_15 . V_54 -> V_69 = F_12 ( V_68 ) ;
V_2 -> V_15 . V_54 -> V_71 = F_12 ( V_70 ) ;
V_2 -> V_15 . V_72 = F_12 ( V_73 ) ;
F_24 ( V_2 ) ;
}
int F_25 ( void )
{
int V_75 ;
if ( strcmp ( V_76 -> V_77 , L_2 ) == 0 )
V_75 = 0 ;
else if ( strcmp ( V_76 -> V_77 , L_3 ) == 0 )
V_75 = 0 ;
else
V_75 = - V_78 ;
return V_75 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
V_2 -> V_15 . V_38 = V_79 | V_80 | \
V_81 ;
#ifdef F_27
V_2 -> V_15 . V_38 |= V_82 ;
#endif
V_2 -> V_15 . V_41 = V_83 | V_84 | V_85 ;
V_2 -> V_15 . V_43 = V_86 | ( V_2 -> V_14 -> V_15 . V_16 << V_87 ) ;
V_2 -> V_15 . V_45 = V_2 -> V_15 . V_43 ;
V_2 -> V_15 . V_88 = F_12 ( V_89 ) ;
V_19 -> V_90 = F_12 ( V_91 ) ;
V_2 -> V_15 . V_92 = V_93 ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
V_95 -> V_96 . V_97 . V_98 |= V_99 | V_100 |
V_101 ;
V_95 -> V_96 . V_97 . V_102 = V_103 ;
V_95 -> V_96 . V_97 . V_104 . V_105 . V_98 = 0 ;
V_95 -> V_96 . V_97 . V_104 . V_105 . V_90 = V_19 -> V_90 ;
V_95 -> V_96 . V_97 . V_104 . V_105 . V_106 = V_19 -> V_106 ;
V_95 -> V_96 . V_97 . V_104 . V_105 . V_107 = V_19 -> V_107 ;
F_29 ( V_2 , V_95 ) ;
V_95 -> V_96 . V_97 . V_108 [ 3 ] =
V_2 -> V_15 . V_49 [ V_109 ] ;
V_95 -> V_96 . V_97 . V_108 [ 4 ] = V_2 -> V_15 . V_49 [ V_110 ] ;
V_95 -> V_96 . V_97 . V_108 [ 5 ] = V_2 -> V_15 . V_49 [ V_111 ] ;
F_30 ( V_2 , V_95 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
int V_112 ;
if ( V_95 -> V_96 . V_97 . V_102 == V_103 ) {
V_19 -> V_90 = V_95 -> V_96 . V_97 . V_104 . V_105 . V_90 ;
V_19 -> V_106 = V_95 -> V_96 . V_97 . V_104 . V_105 . V_106 ;
V_19 -> V_107 = V_95 -> V_96 . V_97 . V_104 . V_105 . V_107 ;
}
V_112 = F_32 ( V_2 , V_95 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( ! ( V_95 -> V_96 . V_97 . V_98 & V_113 ) )
return 0 ;
if ( V_95 -> V_96 . V_97 . V_98 & V_100 ) {
V_2 -> V_15 . V_49 [ V_109 ] =
V_95 -> V_96 . V_97 . V_108 [ 3 ] ;
}
if ( V_95 -> V_96 . V_97 . V_98 & V_101 ) {
V_2 -> V_15 . V_49 [ V_110 ] =
V_95 -> V_96 . V_97 . V_108 [ 4 ] ;
V_2 -> V_15 . V_49 [ V_111 ] =
V_95 -> V_96 . V_97 . V_108 [ 5 ] ;
}
return F_33 ( V_2 , V_95 ) ;
}
struct V_1 * F_34 ( struct V_14 * V_14 , unsigned int V_114 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_115 ;
V_19 = F_35 ( V_116 , V_117 ) ;
if ( ! V_19 ) {
V_115 = - V_118 ;
goto V_119;
}
V_2 = & V_19 -> V_2 ;
V_2 -> V_15 . V_72 = 0xffffffff ;
V_115 = F_36 ( V_2 , V_14 , V_114 ) ;
if ( V_115 )
goto V_120;
V_115 = F_37 ( V_19 ) ;
if ( V_115 )
goto V_121;
V_2 -> V_15 . V_54 = ( void * ) F_38 ( V_117 | V_122 ) ;
if ( ! V_2 -> V_15 . V_54 )
goto V_123;
return V_2 ;
V_123:
F_39 ( V_19 ) ;
V_121:
F_40 ( V_2 ) ;
V_120:
F_41 ( V_116 , V_19 ) ;
V_119:
return F_42 ( V_115 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
F_44 ( ( unsigned long ) V_2 -> V_15 . V_54 ) ;
F_39 ( V_19 ) ;
F_40 ( V_2 ) ;
F_41 ( V_116 , V_19 ) ;
}
int F_45 ( struct V_14 * V_14 )
{
int V_16 ;
V_16 = F_46 () ;
if ( V_16 < 0 )
return V_16 ;
V_14 -> V_15 . V_16 = V_16 ;
return 0 ;
}
void F_47 ( struct V_14 * V_14 )
{
F_48 ( V_14 -> V_15 . V_16 ) ;
}
static int T_3 F_49 ( void )
{
int V_75 ;
V_75 = F_50 () ;
if ( V_75 )
return V_75 ;
F_51 ( 64 ) ;
F_52 ( 0 ) ;
return F_53 ( NULL , sizeof( struct V_18 ) , 0 , V_124 ) ;
}
static void T_4 F_54 ( void )
{
F_55 () ;
}
