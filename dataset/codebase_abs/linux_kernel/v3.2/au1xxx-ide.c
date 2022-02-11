static inline void F_1 ( unsigned long V_1 , void * V_2 , T_1 V_3 )
{
T_2 * V_4 = & V_5 ;
T_3 * V_6 ;
T_4 * V_7 ;
if ( ! F_2 ( V_4 -> V_8 , F_3 ( V_2 ) ,
V_3 << 1 , V_9 ) ) {
F_4 ( V_10 L_1 , V_11 , __LINE__ ) ;
return;
}
V_6 = * ( ( T_3 * * ) V_4 -> V_8 ) ;
V_7 = V_6 -> V_12 ;
while ( V_7 -> V_13 & V_14 )
;
V_6 -> V_12 = F_5 ( V_7 ) ;
}
static inline void F_6 ( unsigned long V_1 , void * V_2 , T_1 V_3 )
{
T_2 * V_4 = & V_5 ;
T_3 * V_6 ;
T_4 * V_7 ;
if ( ! F_7 ( V_4 -> V_15 , F_3 ( V_2 ) ,
V_3 << 1 , V_9 ) ) {
F_4 ( V_10 L_1 , V_11 , __LINE__ ) ;
return;
}
V_6 = * ( ( T_3 * * ) V_4 -> V_15 ) ;
V_7 = V_6 -> V_12 ;
while ( V_7 -> V_13 & V_14 )
;
V_6 -> V_12 = F_5 ( V_7 ) ;
}
static void F_8 ( T_5 * V_16 , struct V_17 * V_18 ,
void * V_19 , unsigned int V_20 )
{
F_1 ( V_16 -> V_21 -> V_22 . V_23 , V_19 , ( V_20 + 1 ) / 2 ) ;
}
static void F_9 ( T_5 * V_16 , struct V_17 * V_18 ,
void * V_19 , unsigned int V_20 )
{
F_6 ( V_16 -> V_21 -> V_22 . V_23 , V_19 , ( V_20 + 1 ) / 2 ) ;
}
static void F_10 ( T_6 * V_21 , T_5 * V_16 )
{
int V_24 = 0 , V_25 = F_11 ( V_26 ) ;
switch ( V_16 -> V_27 - V_28 ) {
case 0 :
V_24 = F_12 ( V_29 ) ;
V_25 |= V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_33 | V_34 ;
break;
case 1 :
V_24 = F_12 ( V_35 ) ;
V_25 |= V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_36 | V_37 ;
break;
case 2 :
V_24 = F_12 ( V_38 ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_39 | V_40 ;
break;
case 3 :
V_24 = F_12 ( V_41 ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_42 | V_43 ;
break;
case 4 :
V_24 = F_12 ( V_44 ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_45 | V_46 ;
break;
}
F_13 ( V_24 , V_47 ) ;
F_13 ( V_25 , V_26 ) ;
}
static void F_14 ( T_6 * V_21 , T_5 * V_16 )
{
int V_24 = 0 , V_25 = F_11 ( V_26 ) ;
switch ( V_16 -> V_48 ) {
#ifdef F_15
case V_49 :
V_24 = F_12 ( V_50 ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_51 | V_52 ;
break;
case V_53 :
V_24 = F_12 ( V_54 ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_55 | V_56 ;
break;
case V_57 :
V_24 = F_12 ( V_58 ) ;
V_25 |= V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
V_25 |= V_59 | V_60 ;
break;
#endif
}
F_13 ( V_24 , V_47 ) ;
F_13 ( V_25 , V_26 ) ;
}
static int F_16 ( T_5 * V_16 , struct V_17 * V_18 )
{
T_6 * V_21 = V_16 -> V_21 ;
T_2 * V_4 = & V_5 ;
struct V_61 * V_62 ;
int V_63 = V_18 -> V_64 , V_3 = 0 ;
int V_65 = ! ! ( V_18 -> V_66 & V_67 ) ;
V_4 -> V_16 = V_16 ;
V_62 = V_21 -> V_68 ;
while ( V_63 && F_17 ( V_62 ) ) {
T_1 V_69 ;
T_1 V_70 ;
V_69 = F_18 ( V_62 ) ;
V_70 = F_17 ( V_62 ) ;
while ( V_70 ) {
T_1 V_71 = V_9 ;
unsigned int V_72 = ( V_70 < 0xfe00 ) ? V_70 : 0xfe00 ;
if ( ++ V_3 >= V_73 ) {
F_4 ( V_74 L_2 ,
V_16 -> V_75 ) ;
return 0 ;
}
if ( 1 == V_63 )
V_71 = V_76 ;
else
V_71 = V_9 ;
if ( V_65 ) {
if ( ! F_7 ( V_4 -> V_15 ,
F_19 ( V_62 ) , V_72 , V_71 ) ) {
F_4 ( V_10 L_1 ,
V_11 , __LINE__ ) ;
}
} else {
if ( ! F_2 ( V_4 -> V_8 ,
F_19 ( V_62 ) , V_72 , V_71 ) ) {
F_4 ( V_10 L_1 ,
V_11 , __LINE__ ) ;
}
}
V_69 += V_72 ;
V_70 -= V_72 ;
}
V_62 = F_20 ( V_62 ) ;
V_63 -- ;
}
if ( V_3 )
return 1 ;
return 0 ;
}
static int F_21 ( T_5 * V_16 )
{
return 0 ;
}
static void F_22 ( T_5 * V_16 )
{
}
static int F_23 ( T_5 * V_16 , struct V_17 * V_18 )
{
if ( F_16 ( V_16 , V_18 ) == 0 )
return 1 ;
return 0 ;
}
static int F_24 ( T_5 * V_16 )
{
V_16 -> V_77 ++ ;
if ( V_16 -> V_77 >= V_78 ) {
F_4 ( V_74 L_3 ,
V_16 -> V_75 ) ;
return 1 ;
}
F_25 ( 10 ) ;
return 0 ;
}
static void F_26 ( T_5 * V_16 , int V_79 )
{
}
static void F_27 ( int V_80 , void * V_81 )
{
}
static void F_28 ( int V_80 , void * V_81 )
{
}
static void F_29 ( T_7 * V_82 , T_1 V_83 , T_1 V_84 ,
T_1 V_85 , T_1 V_71 , T_1 V_86 )
{
V_82 -> V_83 = V_83 ;
V_82 -> V_87 = F_30 ( V_86 ) ;
V_82 -> V_88 = 0 ;
V_82 -> V_89 = 0 ;
V_82 -> V_90 = V_84 ;
V_82 -> V_91 = V_85 ;
V_82 -> V_92 = V_71 ;
}
static int F_31 ( T_6 * V_21 , const struct V_93 * V_94 )
{
T_2 * V_95 = & V_5 ;
T_7 V_96 , V_97 ;
T_1 V_83 , V_84 , V_85 , V_71 ;
V_83 = V_21 -> V_98 ;
V_84 = 8 ;
V_85 = 32 ;
#ifdef F_32
V_71 = V_99 | V_100 ;
#else
V_71 = V_99 ;
#endif
F_29 ( & V_96 , V_83 , V_84 , V_85 ,
V_101 | V_71 , V_95 -> V_86 ) ;
V_95 -> V_102 = F_33 ( & V_96 ) ;
F_29 ( & V_96 , V_83 , V_84 , V_85 ,
V_103 | V_71 , V_95 -> V_86 ) ;
V_95 -> V_104 = F_33 ( & V_96 ) ;
F_29 ( & V_97 , ( T_1 ) V_105 , V_84 ,
V_85 , V_106 , V_95 -> V_86 ) ;
V_95 -> V_107 = F_33 ( & V_97 ) ;
V_95 -> V_15 = F_34 ( V_95 -> V_107 ,
V_95 -> V_102 ,
F_27 ,
( void * ) V_95 ) ;
V_95 -> V_8 = F_34 ( V_95 -> V_104 ,
V_95 -> V_107 ,
F_28 ,
( void * ) V_95 ) ;
V_95 -> V_108 = ( void * ) F_35 ( V_95 -> V_15 ,
V_109 ) ;
V_95 -> V_110 = ( void * ) F_35 ( V_95 -> V_8 ,
V_109 ) ;
( void ) F_36 ( V_21 ) ;
F_37 ( V_95 -> V_15 ) ;
F_37 ( V_95 -> V_8 ) ;
return 0 ;
}
static int F_31 ( T_6 * V_21 , const struct V_93 * V_94 )
{
T_2 * V_95 = & V_5 ;
T_7 V_96 ;
int V_71 ;
#ifdef F_32
V_71 = V_99 | V_100 ;
#else
V_71 = V_99 ;
#endif
F_29 ( & V_96 , ( T_1 ) V_105 , 8 , 32 ,
V_101 | V_71 , V_95 -> V_86 ) ;
V_95 -> V_102 = F_33 ( & V_96 ) ;
F_29 ( & V_96 , ( T_1 ) V_105 , 8 , 32 ,
V_103 | V_71 , V_95 -> V_86 ) ;
V_95 -> V_104 = F_33 ( & V_96 ) ;
V_95 -> V_15 = F_34 ( V_105 ,
V_95 -> V_102 ,
NULL ,
( void * ) V_95 ) ;
V_95 -> V_8 = F_34 ( V_95 -> V_104 ,
V_105 ,
NULL ,
( void * ) V_95 ) ;
V_95 -> V_108 = ( void * ) F_35 ( V_95 -> V_15 ,
V_109 ) ;
V_95 -> V_110 = ( void * ) F_35 ( V_95 -> V_8 ,
V_109 ) ;
F_37 ( V_95 -> V_15 ) ;
F_37 ( V_95 -> V_8 ) ;
return 0 ;
}
static void F_38 ( struct V_111 * V_112 , T_2 * V_4 )
{
int V_63 ;
unsigned long * V_113 = V_112 -> V_114 ;
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ )
* V_113 ++ = V_4 -> V_86 + ( V_63 << V_115 ) ;
* V_113 = V_4 -> V_86 + ( 14 << V_115 ) ;
}
static int F_39 ( struct V_116 * V_82 )
{
T_2 * V_4 = & V_5 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
int V_121 = 0 ;
struct V_111 V_112 , * V_122 [] = { & V_112 } ;
#if F_40 ( F_15 )
char * V_123 = L_4 ;
#elif F_40 ( V_124 )
char * V_123 = L_5 ;
#endif
memset ( & V_5 , 0 , sizeof( T_2 ) ) ;
V_4 -> V_80 = F_41 ( V_82 , 0 ) ;
V_118 = F_42 ( V_82 , V_125 , 0 ) ;
if ( V_118 == NULL ) {
F_43 ( L_6 , V_126 , V_82 -> V_127 ) ;
V_121 = - V_128 ;
goto V_129;
}
if ( V_4 -> V_80 < 0 ) {
F_43 ( L_7 , V_126 , V_82 -> V_127 ) ;
V_121 = - V_128 ;
goto V_129;
}
if ( ! F_44 ( V_118 -> V_130 , F_45 ( V_118 ) , V_82 -> V_75 ) ) {
F_43 ( L_8 , V_126 ) ;
V_121 = - V_131 ;
goto V_129;
}
V_4 -> V_86 = ( T_1 ) F_46 ( V_118 -> V_130 , F_45 ( V_118 ) ) ;
if ( V_4 -> V_86 == 0 ) {
V_121 = - V_132 ;
goto V_129;
}
V_118 = F_42 ( V_82 , V_133 , 0 ) ;
if ( ! V_118 ) {
F_43 ( L_9 , V_126 ) ;
V_121 = - V_128 ;
goto V_129;
}
V_4 -> V_98 = V_118 -> V_130 ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
F_38 ( & V_112 , V_4 ) ;
V_112 . V_80 = V_4 -> V_80 ;
V_112 . V_82 = & V_82 -> V_82 ;
V_121 = F_47 ( & V_134 , V_122 , 1 , & V_120 ) ;
if ( V_121 )
goto V_129;
V_5 . V_21 = V_120 -> V_135 [ 0 ] ;
F_48 ( V_82 , V_120 ) ;
F_4 ( V_136 L_10 , V_123 ) ;
V_129:
return V_121 ;
}
static int F_49 ( struct V_116 * V_82 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 = F_50 ( V_82 ) ;
T_2 * V_4 = & V_5 ;
F_51 ( V_120 ) ;
F_52 ( ( void * ) V_4 -> V_86 ) ;
V_118 = F_42 ( V_82 , V_125 , 0 ) ;
F_53 ( V_118 -> V_130 , F_45 ( V_118 ) ) ;
return 0 ;
}
static int T_8 F_54 ( void )
{
return F_55 ( & V_137 ) ;
}
static void T_9 F_56 ( void )
{
F_57 ( & V_137 ) ;
}
