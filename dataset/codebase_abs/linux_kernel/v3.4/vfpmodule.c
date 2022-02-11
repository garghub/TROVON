static bool F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
#ifdef F_2
if ( V_3 -> V_4 . V_5 . V_1 != V_1 )
return false ;
#endif
return V_6 [ V_1 ] == & V_3 -> V_4 ;
}
static void F_3 ( unsigned int V_1 , struct V_2 * V_3 )
{
if ( F_1 ( V_1 , V_3 ) ) {
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
V_6 [ V_1 ] = NULL ;
}
#ifdef F_2
V_3 -> V_4 . V_5 . V_1 = V_9 ;
#endif
}
static void F_6 ( struct V_2 * V_3 )
{
union V_10 * V_11 = & V_3 -> V_4 ;
unsigned int V_1 ;
V_1 = F_7 () ;
if ( V_6 [ V_1 ] == V_11 )
V_6 [ V_1 ] = NULL ;
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
F_8 () ;
memset ( V_11 , 0 , sizeof( union V_10 ) ) ;
V_11 -> V_5 . V_12 = V_8 ;
V_11 -> V_5 . V_13 = V_14 ;
#ifdef F_2
V_11 -> V_5 . V_1 = V_9 ;
#endif
}
static void F_9 ( struct V_2 * V_3 )
{
union V_10 * V_11 = & V_3 -> V_4 ;
unsigned int V_1 = F_7 () ;
if ( V_6 [ V_1 ] == V_11 )
V_6 [ V_1 ] = NULL ;
F_8 () ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_2 * V_15 = F_11 () ;
F_12 ( V_15 ) ;
V_3 -> V_4 = V_15 -> V_4 ;
#ifdef F_2
V_3 -> V_4 . V_5 . V_1 = V_9 ;
#endif
}
static int F_13 ( struct V_16 * V_17 , unsigned long V_18 , void * V_19 )
{
struct V_2 * V_3 = V_19 ;
T_1 V_12 ;
#ifdef F_2
unsigned int V_1 ;
#endif
switch ( V_18 ) {
case V_20 :
V_12 = F_5 ( V_7 ) ;
#ifdef F_2
V_1 = V_3 -> V_1 ;
if ( ( V_12 & V_8 ) && V_6 [ V_1 ] )
F_14 ( V_6 [ V_1 ] , V_12 ) ;
#endif
F_4 ( V_7 , V_12 & ~ V_8 ) ;
break;
case V_21 :
F_6 ( V_3 ) ;
break;
case V_22 :
F_9 ( V_3 ) ;
break;
case V_23 :
F_10 ( V_3 ) ;
break;
}
return V_24 ;
}
static void F_15 ( unsigned int V_25 , struct V_26 * V_27 )
{
T_2 V_28 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_29 = V_30 ;
V_28 . V_31 = V_25 ;
V_28 . V_32 = ( void V_33 * ) ( F_16 ( V_27 ) - 4 ) ;
V_34 -> V_3 . V_35 = 0 ;
V_34 -> V_3 . V_36 = 6 ;
F_17 ( V_30 , & V_28 , V_34 ) ;
}
static void F_18 ( char * V_37 , T_1 V_38 )
{
int V_39 ;
F_19 ( V_40 L_1 , V_37 ) ;
F_19 ( V_40 L_2 ,
F_5 ( V_7 ) , F_5 ( V_41 ) , V_38 ) ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 += 2 )
F_19 ( V_40 L_3 ,
V_39 , F_20 ( V_39 ) , V_39 + 1 , F_20 ( V_39 + 1 ) ) ;
}
static void F_21 ( T_1 V_42 , T_1 V_38 , T_1 V_13 , struct V_26 * V_27 )
{
int V_31 = 0 ;
F_22 ( L_4 , V_42 ) ;
if ( V_42 == V_43 ) {
F_18 ( L_5 , V_38 ) ;
F_15 ( 0 , V_27 ) ;
return;
}
if ( V_42 & ( V_44 | V_45 | V_46 | V_47 ) )
V_13 &= ~ ( V_44 | V_45 | V_46 | V_47 ) ;
V_13 |= V_42 ;
F_4 ( V_41 , V_13 ) ;
#define RAISE ( T_3 , T_4 , T_5 ) \
if (exceptions & stat && fpscr & en) \
si_code = sig;
RAISE ( V_48 , V_49 , V_50 ) ;
RAISE ( V_51 , V_52 , V_53 ) ;
RAISE ( V_54 , V_55 , V_56 ) ;
RAISE ( V_57 , V_58 , V_59 ) ;
RAISE ( V_60 , V_61 , V_62 ) ;
if ( V_31 )
F_15 ( V_31 , V_27 ) ;
}
static T_1 F_23 ( T_1 V_38 , T_1 V_13 , struct V_26 * V_27 )
{
T_1 V_42 = V_43 ;
F_22 ( L_6 , V_38 , V_13 ) ;
if ( F_24 ( V_38 ) ) {
if ( ! F_25 ( V_38 ) ) {
if ( F_26 ( V_38 ) ) {
V_42 = F_27 ( V_38 , V_13 ) ;
} else {
V_42 = F_28 ( V_38 , V_13 ) ;
}
} else {
}
} else {
}
return V_42 & ~ V_63 ;
}
void F_29 ( T_1 V_64 , T_1 V_12 , struct V_26 * V_27 )
{
T_1 V_13 , V_65 , V_66 , V_42 ;
F_22 ( L_7 , V_64 , V_12 ) ;
F_4 ( V_7 , V_12 & ~ ( V_67 | V_68 | V_69 | V_70 | V_71 ) ) ;
V_66 = F_5 ( V_72 ) ;
V_65 = V_13 = F_5 ( V_41 ) ;
if ( ( V_66 & V_73 ) == ( 1 << V_74 )
&& ( V_13 & V_52 ) ) {
goto V_75;
}
if ( V_12 & V_67 ) {
#ifndef F_30
V_64 = F_5 ( V_76 ) ;
V_27 -> V_77 -= 4 ;
#endif
} else if ( ! ( V_12 & V_68 ) ) {
F_21 ( V_43 , V_64 , V_13 , V_27 ) ;
goto exit;
}
if ( V_12 & ( V_67 | V_70 ) ) {
T_1 V_78 ;
V_78 = V_12 + ( 1 << V_79 ) ;
V_13 &= ~ V_80 ;
V_13 |= ( V_78 & V_81 ) << ( V_82 - V_79 ) ;
}
V_42 = F_23 ( V_64 , V_13 , V_27 ) ;
if ( V_42 )
F_21 ( V_42 , V_64 , V_65 , V_27 ) ;
if ( V_12 ^ ( V_67 | V_69 ) )
goto exit;
F_31 () ;
V_64 = F_5 ( V_83 ) ;
V_75:
V_42 = F_23 ( V_64 , V_65 , V_27 ) ;
if ( V_42 )
F_21 ( V_42 , V_64 , V_65 , V_27 ) ;
exit:
F_32 () ;
}
static void F_33 ( void * V_84 )
{
T_1 V_85 ;
F_34 ( F_35 () ) ;
V_85 = F_36 () ;
F_37 ( V_85 | F_38 ( 10 ) | F_38 ( 11 ) ) ;
}
static int F_39 ( void )
{
struct V_2 * V_86 = F_11 () ;
T_1 V_12 = F_5 ( V_7 ) ;
if ( V_12 & V_8 ) {
F_19 ( V_87 L_8 , V_88 ) ;
F_14 ( & V_86 -> V_4 , V_12 ) ;
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
}
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
return 0 ;
}
static void F_40 ( void )
{
F_33 ( NULL ) ;
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
}
static int F_41 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
switch ( V_18 ) {
case V_89 :
F_39 () ;
break;
case V_90 :
case V_91 :
F_40 () ;
break;
}
return V_92 ;
}
static void F_42 ( void )
{
F_43 ( & V_93 ) ;
}
static inline void F_42 ( void ) { }
void F_12 ( struct V_2 * V_3 )
{
unsigned int V_1 = F_7 () ;
if ( F_1 ( V_1 , V_3 ) ) {
T_1 V_12 = F_5 ( V_7 ) ;
F_4 ( V_7 , V_12 | V_8 ) ;
F_14 ( & V_3 -> V_4 , V_12 | V_8 ) ;
F_4 ( V_7 , V_12 ) ;
}
F_8 () ;
}
void F_44 ( struct V_2 * V_3 )
{
unsigned int V_1 = F_7 () ;
F_3 ( V_1 , V_3 ) ;
F_8 () ;
}
int F_45 ( struct V_94 V_33 * V_95 ,
struct V_96 V_33 * V_97 )
{
struct V_2 * V_3 = F_11 () ;
struct V_98 * V_99 = & V_3 -> V_4 . V_5 ;
int V_100 = 0 ;
F_12 ( V_3 ) ;
V_100 |= F_46 ( & V_95 -> V_101 , & V_99 -> V_101 ,
sizeof( V_99 -> V_101 ) ) ;
F_47 ( V_99 -> V_13 , & V_95 -> V_13 , V_100 ) ;
F_47 ( V_99 -> V_12 , & V_97 -> V_12 , V_100 ) ;
F_47 ( V_99 -> V_102 , & V_97 -> V_102 , V_100 ) ;
F_47 ( V_99 -> V_103 , & V_97 -> V_103 , V_100 ) ;
if ( V_100 )
return - V_104 ;
F_44 ( V_3 ) ;
V_99 -> V_13 &= ~ ( V_80 | V_105 ) ;
return 0 ;
}
int F_48 ( struct V_94 V_33 * V_95 ,
struct V_96 V_33 * V_97 )
{
struct V_2 * V_3 = F_11 () ;
struct V_98 * V_99 = & V_3 -> V_4 . V_5 ;
unsigned long V_12 ;
int V_100 = 0 ;
F_44 ( V_3 ) ;
V_100 |= F_49 ( & V_99 -> V_101 , & V_95 -> V_101 ,
sizeof( V_99 -> V_101 ) ) ;
F_50 ( V_99 -> V_13 , & V_95 -> V_13 , V_100 ) ;
F_50 ( V_12 , & V_97 -> V_12 , V_100 ) ;
V_12 |= V_8 ;
V_12 &= ~ ( V_67 | V_69 ) ;
V_99 -> V_12 = V_12 ;
F_50 ( V_99 -> V_102 , & V_97 -> V_102 , V_100 ) ;
F_50 ( V_99 -> V_103 , & V_97 -> V_103 , V_100 ) ;
return V_100 ? - V_104 : 0 ;
}
static int F_51 ( struct V_16 * V_106 , unsigned long V_107 ,
void * V_108 )
{
if ( V_107 == V_109 || V_107 == V_110 ) {
F_3 ( ( long ) V_108 , F_11 () ) ;
} else if ( V_107 == V_111 || V_107 == V_112 )
F_33 ( NULL ) ;
return V_92 ;
}
static int T_6 F_52 ( void )
{
unsigned int V_113 ;
unsigned int V_114 = F_53 () ;
if ( V_114 >= V_115 )
F_54 ( F_33 , NULL , 1 ) ;
V_116 = V_117 ;
F_31 () ;
V_113 = F_5 ( V_72 ) ;
F_31 () ;
V_116 = V_118 ;
F_19 ( V_119 L_9 ) ;
if ( V_120 )
F_19 ( L_10 ) ;
else if ( V_113 & V_121 ) {
F_19 ( L_11 ) ;
} else {
F_55 ( F_51 , 0 ) ;
V_120 = ( V_113 & V_73 ) >> V_74 ;
F_19 ( L_12 ,
( V_113 & V_122 ) >> V_123 ,
( V_113 & V_73 ) >> V_74 ,
( V_113 & V_124 ) >> V_125 ,
( V_113 & V_126 ) >> V_127 ,
( V_113 & V_128 ) >> V_129 ) ;
V_116 = V_130 ;
F_56 ( & V_131 ) ;
F_42 () ;
V_132 |= V_133 ;
#ifdef F_57
if ( V_120 >= 2 ) {
V_132 |= V_134 ;
if ( ( ( F_5 ( V_135 ) & V_136 ) ) == 1 )
V_132 |= V_137 ;
}
#endif
if ( ( F_58 () & 0x000f0000 ) == 0x000f0000 ) {
#ifdef F_59
if ( ( F_5 ( V_138 ) & 0x000fff00 ) == 0x00011100 )
V_132 |= V_139 ;
#endif
if ( ( F_5 ( V_138 ) & 0xf0000000 ) == 0x10000000 )
V_132 |= V_140 ;
}
}
return 0 ;
}
