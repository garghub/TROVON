static int F_1 ( T_1 V_1 )
{
V_2 -> V_1 = F_2 ( V_1 ) ;
return 0 ;
}
static T_2 void * F_3 ( unsigned long V_3 )
{
void * V_4 ;
V_4 = F_4 ( F_5 ( V_3 , V_3 , V_5 ) ) ;
memset ( V_4 , 0 , V_3 ) ;
return V_4 ;
}
int F_6 ( unsigned long V_6 , unsigned long V_7 ,
T_3 V_8 ,
unsigned int V_9 )
{
T_4 * V_10 ;
T_5 * V_11 ;
T_6 * V_12 ;
T_7 * V_13 ;
F_7 ( V_14 > V_15 ) ;
if ( F_8 () ) {
V_10 = F_9 ( V_6 ) ;
V_11 = F_10 ( & V_16 , V_10 , V_6 ) ;
if ( ! V_11 )
return - V_17 ;
if ( V_9 == V_18 ) {
V_13 = ( T_7 * ) V_11 ;
goto V_19;
}
V_12 = F_11 ( & V_16 , V_11 , V_6 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_9 == V_20 ) {
V_13 = ( T_7 * ) V_11 ;
goto V_19;
}
V_13 = F_12 ( V_12 , V_6 ) ;
if ( ! V_13 )
return - V_17 ;
} else {
V_10 = F_9 ( V_6 ) ;
if ( F_13 ( * V_10 ) ) {
V_11 = F_3 ( V_21 ) ;
F_14 ( V_11 == NULL ) ;
F_15 ( & V_16 , V_10 , V_11 ) ;
}
V_11 = F_16 ( V_10 , V_6 ) ;
if ( V_9 == V_18 ) {
V_13 = ( T_7 * ) V_11 ;
goto V_19;
}
if ( F_17 ( * V_11 ) ) {
V_12 = F_3 ( V_22 ) ;
F_14 ( V_12 == NULL ) ;
F_18 ( & V_16 , V_11 , V_12 ) ;
}
V_12 = F_19 ( V_11 , V_6 ) ;
if ( V_9 == V_20 ) {
V_13 = ( T_7 * ) V_11 ;
goto V_19;
}
if ( ! F_20 ( * V_12 ) ) {
V_13 = F_3 ( V_23 ) ;
F_14 ( V_13 == NULL ) ;
F_21 ( & V_16 , V_12 , V_13 ) ;
}
V_13 = F_22 ( V_12 , V_6 ) ;
}
V_19:
F_23 ( & V_16 , V_6 , V_13 , F_24 ( V_7 >> V_24 , V_8 ) ) ;
F_25 () ;
return 0 ;
}
static void T_8 F_26 ( void )
{
int V_25 ;
T_1 V_26 , V_27 , V_28 ;
unsigned long V_29 ;
struct V_30 * V_31 ;
unsigned long V_32 ;
V_33 = 0 ;
V_25 = 0 ;
F_27 (memory, reg) {
V_28 = V_31 -> V_26 ;
V_34:
if ( V_25 < 1 && V_35 [ V_36 ] . V_37 )
V_32 = V_18 ;
else if ( V_25 < 2 && V_35 [ V_38 ] . V_37 )
V_32 = V_20 ;
else
V_32 = V_23 ;
V_26 = F_28 ( V_28 , V_32 ) ;
V_27 = F_29 ( V_31 -> V_26 + V_31 -> V_3 , V_32 ) ;
F_30 ( L_1 ,
( unsigned long ) V_26 , ( unsigned long ) V_27 ,
V_32 ) ;
while ( V_26 < V_27 ) {
F_6 ( ( unsigned long ) F_4 ( V_26 ) ,
V_26 , V_39 ,
V_32 ) ;
V_26 += V_32 ;
}
if ( V_27 < V_31 -> V_26 + V_31 -> V_3 ) {
V_28 = V_27 ;
V_25 ++ ;
goto V_34;
}
}
F_31 ( ( V_40 > 23 ) , L_2 ) ;
V_41 = F_3 ( 1UL << V_40 ) ;
V_29 = F_32 () ;
V_41 -> V_42 = F_2 ( V_29 | F_33 ( V_16 . V_43 ) | V_44 ) ;
V_45 . V_46 ( F_33 ( V_41 ) | ( V_40 - 12 ) | V_47 ) ;
F_30 ( L_3 , V_41 , V_16 . V_43 ) ;
}
static void T_8 F_34 ( void )
{
unsigned long V_29 ;
V_29 = F_32 () ;
F_31 ( ( V_48 > 24 ) , L_4 ) ;
V_2 = F_3 ( 1UL << V_48 ) ;
V_2 -> V_49 = F_2 ( V_29 | F_33 ( V_16 . V_43 ) |
V_44 | V_50 ) ;
F_35 ( L_5 , V_2 ) ;
F_36 ( V_5 ) ;
F_37 ( V_51 , F_33 ( V_2 ) | ( V_48 - 12 ) ) ;
}
void T_8 F_38 ( void )
{
V_45 . V_46 = F_1 ;
}
static int T_8 F_39 ( unsigned int V_37 )
{
int V_52 = - 1 ;
switch ( V_37 ) {
case 0xc :
V_52 = V_53 ;
break;
case 0x10 :
V_52 = V_54 ;
break;
case 0x15 :
V_52 = V_38 ;
break;
case 0x1e :
V_52 = V_36 ;
break;
}
return V_52 ;
}
static int T_8 F_40 ( unsigned long V_55 ,
const char * V_56 , int V_57 ,
void * V_58 )
{
int V_3 = 0 ;
int V_37 , V_52 ;
unsigned int V_59 ;
const T_9 * V_60 ;
const char * type = F_41 ( V_55 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_60 = F_41 ( V_55 , L_8 , & V_3 ) ;
if ( ! V_60 )
return 0 ;
F_30 ( L_9 ) ;
for (; V_3 >= 4 ; V_3 -= 4 , ++ V_60 ) {
struct V_61 * V_62 ;
V_37 = F_42 ( V_60 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_59 = F_42 ( V_60 [ 0 ] ) >> 29 ;
F_30 ( L_10 , V_37 , V_59 ) ;
V_52 = F_39 ( V_37 ) ;
if ( V_52 < 0 )
continue;
V_62 = & V_35 [ V_52 ] ;
V_62 -> V_37 = V_37 ;
V_62 -> V_59 = V_59 ;
}
V_63 -> V_64 &= ~ V_65 ;
return 1 ;
}
static void T_8 F_43 ( void )
{
int V_66 ;
V_66 = F_44 ( F_40 , NULL ) ;
if ( V_66 != 0 )
goto V_67;
V_35 [ V_53 ] . V_37 = 12 ;
V_35 [ V_53 ] . V_59 = 0x0 ;
V_35 [ V_54 ] . V_37 = 16 ;
V_35 [ V_54 ] . V_59 = 0x5 ;
V_67:
#ifdef F_45
if ( V_35 [ V_38 ] . V_37 ) {
V_68 = V_38 ;
}
#endif
return;
}
void T_8 F_46 ( void )
{
unsigned long V_69 ;
#ifdef F_47
V_70 = V_54 ;
#else
V_70 = V_53 ;
#endif
#ifdef F_45
V_68 = V_70 ;
#endif
V_71 = V_72 ;
V_73 = V_74 ;
V_75 = V_76 ;
V_77 = V_44 ;
V_78 = V_74 ;
V_79 = V_80 ;
V_81 = V_82 ;
V_83 = V_84 ;
V_85 = V_86 ;
V_87 = V_88 ;
V_89 = V_90 ;
V_91 = V_92 ;
V_93 = V_94 ;
V_95 = V_96 ;
V_97 = V_98 ;
V_99 = V_100 ;
V_101 = (struct V_102 * ) V_103 ;
V_104 = V_105 ;
#ifdef F_48
V_106 = V_107 ;
#endif
V_108 = V_109 ;
V_110 = V_111 ;
F_43 () ;
if ( ! F_49 ( V_112 ) ) {
V_69 = F_50 ( V_113 ) ;
F_37 ( V_113 , V_69 | V_114 ) ;
F_34 () ;
}
F_26 () ;
}
void F_51 ( void )
{
unsigned long V_69 ;
if ( ! F_49 ( V_112 ) ) {
V_69 = F_50 ( V_113 ) ;
F_37 ( V_113 , V_69 | V_114 ) ;
F_37 ( V_51 ,
F_33 ( V_2 ) | ( V_48 - 12 ) ) ;
}
}
void F_52 ( T_10 V_115 ,
T_10 V_116 )
{
F_14 ( V_115 != 0 ) ;
V_117 = F_53 ( T_1 , V_116 , 0x40000000 ) ;
F_36 ( V_115 + V_116 ) ;
}
int T_11 F_54 ( unsigned long V_118 ,
unsigned long V_119 ,
unsigned long V_120 )
{
unsigned long V_8 = V_121 | V_122 | V_123 ;
F_14 ( F_6 ( V_118 , V_120 , F_55 ( V_8 ) , V_119 ) ) ;
return 0 ;
}
void F_56 ( unsigned long V_118 , unsigned long V_119 )
{
}
unsigned long F_57 ( struct V_124 * V_125 , unsigned long V_126 ,
T_6 * V_12 , unsigned long V_127 ,
unsigned long V_128 )
{
unsigned long V_129 ;
#ifdef F_58
F_59 ( ! F_60 ( * V_12 ) ) ;
F_61 ( & V_125 -> V_130 ) ;
#endif
V_129 = F_62 ( V_125 , V_126 , ( T_7 * ) V_12 , V_127 , V_128 , 1 ) ;
F_63 ( V_126 , V_129 , V_127 , V_128 ) ;
return V_129 ;
}
T_6 F_64 ( struct V_131 * V_132 , unsigned long V_133 ,
T_6 * V_12 )
{
T_6 V_134 ;
F_65 ( V_133 & ~ V_135 ) ;
F_65 ( F_60 ( * V_12 ) ) ;
V_134 = * V_12 ;
F_66 ( V_12 ) ;
F_67 () ;
F_68 ( V_132 , V_133 , V_133 + V_136 ) ;
return V_134 ;
}
void F_69 ( struct V_124 * V_125 , T_6 * V_12 ,
T_12 V_137 )
{
struct V_138 * V_139 = (struct V_138 * ) V_137 ;
F_61 ( F_70 ( V_125 , V_12 ) ) ;
if ( ! F_71 ( V_125 , V_12 ) )
F_72 ( V_139 ) ;
else
F_73 ( V_139 , (struct V_138 * ) F_71 ( V_125 , V_12 ) ) ;
F_71 ( V_125 , V_12 ) = V_137 ;
}
T_12 F_74 ( struct V_124 * V_125 , T_6 * V_12 )
{
T_7 * V_13 ;
T_12 V_137 ;
struct V_138 * V_139 ;
F_61 ( F_70 ( V_125 , V_12 ) ) ;
V_137 = F_71 ( V_125 , V_12 ) ;
V_139 = (struct V_138 * ) V_137 ;
if ( F_75 ( V_139 ) )
F_71 ( V_125 , V_12 ) = NULL ;
else {
F_71 ( V_125 , V_12 ) = ( T_12 ) V_139 -> V_140 ;
F_76 ( V_139 ) ;
}
V_13 = ( T_7 * ) V_137 ;
* V_13 = F_77 ( 0 ) ;
V_13 ++ ;
* V_13 = F_77 ( 0 ) ;
return V_137 ;
}
T_6 F_78 ( struct V_124 * V_125 ,
unsigned long V_126 , T_6 * V_12 )
{
T_6 V_141 ;
unsigned long V_129 ;
V_129 = F_57 ( V_125 , V_126 , V_12 , ~ 0UL , 0 ) ;
V_141 = F_79 ( V_129 ) ;
F_67 () ;
return V_141 ;
}
int F_80 ( void )
{
if ( V_35 [ V_38 ] . V_37 == V_142 )
return 1 ;
return 0 ;
}
