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
F_19 ( L_1 , V_37 ) ;
F_19 ( L_2 ,
F_5 ( V_7 ) , F_5 ( V_40 ) , V_38 ) ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 += 2 )
F_19 ( L_3 ,
V_39 , F_20 ( V_39 ) , V_39 + 1 , F_20 ( V_39 + 1 ) ) ;
}
static void F_21 ( T_1 V_41 , T_1 V_38 , T_1 V_13 , struct V_26 * V_27 )
{
int V_31 = 0 ;
F_22 ( L_4 , V_41 ) ;
if ( V_41 == V_42 ) {
F_18 ( L_5 , V_38 ) ;
F_15 ( 0 , V_27 ) ;
return;
}
if ( V_41 & ( V_43 | V_44 | V_45 | V_46 ) )
V_13 &= ~ ( V_43 | V_44 | V_45 | V_46 ) ;
V_13 |= V_41 ;
F_4 ( V_40 , V_13 ) ;
#define RAISE ( T_3 , T_4 , T_5 ) \
if (exceptions & stat && fpscr & en) \
si_code = sig;
RAISE ( V_47 , V_48 , V_49 ) ;
RAISE ( V_50 , V_51 , V_52 ) ;
RAISE ( V_53 , V_54 , V_55 ) ;
RAISE ( V_56 , V_57 , V_58 ) ;
RAISE ( V_59 , V_60 , V_61 ) ;
if ( V_31 )
F_15 ( V_31 , V_27 ) ;
}
static T_1 F_23 ( T_1 V_38 , T_1 V_13 , struct V_26 * V_27 )
{
T_1 V_41 = V_42 ;
F_22 ( L_6 , V_38 , V_13 ) ;
if ( F_24 ( V_38 ) ) {
if ( ! F_25 ( V_38 ) ) {
if ( F_26 ( V_38 ) ) {
V_41 = F_27 ( V_38 , V_13 ) ;
} else {
V_41 = F_28 ( V_38 , V_13 ) ;
}
} else {
}
} else {
}
return V_41 & ~ V_62 ;
}
void F_29 ( T_1 V_63 , T_1 V_12 , struct V_26 * V_27 )
{
T_1 V_13 , V_64 , V_65 , V_41 ;
F_22 ( L_7 , V_63 , V_12 ) ;
F_4 ( V_7 , V_12 & ~ ( V_66 | V_67 | V_68 | V_69 | V_70 ) ) ;
V_65 = F_5 ( V_71 ) ;
V_64 = V_13 = F_5 ( V_40 ) ;
if ( ( V_65 & V_72 ) == ( 1 << V_73 )
&& ( V_13 & V_51 ) ) {
goto V_74;
}
if ( V_12 & V_66 ) {
#ifndef F_30
V_63 = F_5 ( V_75 ) ;
V_27 -> V_76 -= 4 ;
#endif
} else if ( ! ( V_12 & V_67 ) ) {
F_21 ( V_42 , V_63 , V_13 , V_27 ) ;
goto exit;
}
if ( V_12 & ( V_66 | V_69 ) ) {
T_1 V_77 ;
V_77 = V_12 + ( 1 << V_78 ) ;
V_13 &= ~ V_79 ;
V_13 |= ( V_77 & V_80 ) << ( V_81 - V_78 ) ;
}
V_41 = F_23 ( V_63 , V_13 , V_27 ) ;
if ( V_41 )
F_21 ( V_41 , V_63 , V_64 , V_27 ) ;
if ( ( V_12 & ( V_66 | V_68 ) ) != ( V_66 | V_68 ) )
goto exit;
F_31 () ;
V_63 = F_5 ( V_82 ) ;
V_74:
V_41 = F_23 ( V_63 , V_64 , V_27 ) ;
if ( V_41 )
F_21 ( V_41 , V_63 , V_64 , V_27 ) ;
exit:
F_32 () ;
}
static void F_33 ( void * V_83 )
{
T_1 V_84 ;
F_34 ( F_35 () ) ;
V_84 = F_36 () ;
F_37 ( V_84 | F_38 ( 10 ) | F_38 ( 11 ) ) ;
}
void F_39 ( void )
{
if ( V_85 ) {
F_22 ( L_8 , V_86 ) ;
return;
}
V_85 = 1 ;
}
static int F_40 ( void )
{
struct V_2 * V_87 = F_11 () ;
T_1 V_12 = F_5 ( V_7 ) ;
if ( V_12 & V_8 ) {
F_22 ( L_9 , V_86 ) ;
F_14 ( & V_87 -> V_4 , V_12 ) ;
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
} else if ( V_6 [ V_87 -> V_1 ] ) {
#ifndef F_2
F_4 ( V_7 , V_12 | V_8 ) ;
F_14 ( V_6 [ V_87 -> V_1 ] , V_12 ) ;
F_4 ( V_7 , V_12 ) ;
#endif
}
V_6 [ V_87 -> V_1 ] = NULL ;
return 0 ;
}
static void F_41 ( void )
{
F_33 ( NULL ) ;
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
}
static int F_42 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
switch ( V_18 ) {
case V_88 :
F_40 () ;
break;
case V_89 :
case V_90 :
F_41 () ;
break;
}
return V_91 ;
}
static void F_43 ( void )
{
F_44 ( & V_92 ) ;
}
static inline void F_43 ( void ) { }
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
void F_45 ( struct V_2 * V_3 )
{
unsigned int V_1 = F_7 () ;
F_3 ( V_1 , V_3 ) ;
F_8 () ;
}
int F_46 ( struct V_93 V_33 * V_94 ,
struct V_95 V_33 * V_96 )
{
struct V_2 * V_3 = F_11 () ;
struct V_97 * V_98 = & V_3 -> V_4 . V_5 ;
int V_99 = 0 ;
F_12 ( V_3 ) ;
V_99 |= F_47 ( & V_94 -> V_100 , & V_98 -> V_100 ,
sizeof( V_98 -> V_100 ) ) ;
F_48 ( V_98 -> V_13 , & V_94 -> V_13 , V_99 ) ;
F_48 ( V_98 -> V_12 , & V_96 -> V_12 , V_99 ) ;
F_48 ( V_98 -> V_101 , & V_96 -> V_101 , V_99 ) ;
F_48 ( V_98 -> V_102 , & V_96 -> V_102 , V_99 ) ;
if ( V_99 )
return - V_103 ;
F_45 ( V_3 ) ;
V_98 -> V_13 &= ~ ( V_79 | V_104 ) ;
return 0 ;
}
int F_49 ( struct V_93 V_33 * V_94 ,
struct V_95 V_33 * V_96 )
{
struct V_2 * V_3 = F_11 () ;
struct V_97 * V_98 = & V_3 -> V_4 . V_5 ;
unsigned long V_12 ;
int V_99 = 0 ;
F_45 ( V_3 ) ;
V_99 |= F_50 ( & V_98 -> V_100 , & V_94 -> V_100 ,
sizeof( V_98 -> V_100 ) ) ;
F_51 ( V_98 -> V_13 , & V_94 -> V_13 , V_99 ) ;
F_51 ( V_12 , & V_96 -> V_12 , V_99 ) ;
V_12 |= V_8 ;
V_12 &= ~ ( V_66 | V_68 ) ;
V_98 -> V_12 = V_12 ;
F_51 ( V_98 -> V_101 , & V_96 -> V_101 , V_99 ) ;
F_51 ( V_98 -> V_102 , & V_96 -> V_102 , V_99 ) ;
return V_99 ? - V_103 : 0 ;
}
static int F_52 ( unsigned int V_1 )
{
F_3 ( V_1 , F_11 () ) ;
return 0 ;
}
static int F_53 ( unsigned int V_83 )
{
F_33 ( NULL ) ;
return 0 ;
}
void F_54 ( void )
{
if ( F_5 ( V_7 ) & V_8 )
F_55 ( L_10 ) ;
else
F_55 ( L_11 ) ;
}
void F_56 ( void )
{
struct V_2 * V_3 = F_11 () ;
unsigned int V_1 ;
T_1 V_12 ;
F_34 ( F_57 () ) ;
V_1 = F_7 () ;
V_12 = F_5 ( V_7 ) | V_8 ;
F_4 ( V_7 , V_12 ) ;
if ( F_1 ( V_1 , V_3 ) )
F_14 ( & V_3 -> V_4 , V_12 ) ;
#ifndef F_2
else if ( V_6 [ V_1 ] != NULL )
F_14 ( V_6 [ V_1 ] , V_12 ) ;
#endif
V_6 [ V_1 ] = NULL ;
}
void F_58 ( void )
{
F_4 ( V_7 , F_5 ( V_7 ) & ~ V_8 ) ;
F_8 () ;
}
static int T_6 F_59 ( void )
{
unsigned int V_105 ;
unsigned int V_106 = F_60 () ;
if ( V_106 >= V_107 )
F_61 ( F_33 , NULL , 1 ) ;
V_108 = V_109 ;
F_31 () ;
V_105 = F_5 ( V_71 ) ;
F_31 () ;
V_108 = V_110 ;
F_62 ( L_12 ) ;
if ( V_85 ) {
F_63 ( L_13 ) ;
return 0 ;
} else if ( ( F_64 () & 0x000f0000 ) == 0x000f0000 ) {
V_85 = V_105 & V_111 ;
V_85 >>= V_73 ;
if ( F_65 ( V_112 ) &&
( F_5 ( V_113 ) & 0x000fff00 ) == 0x00011100 )
V_114 |= V_115 ;
if ( F_65 ( V_116 ) ) {
T_1 V_117 = F_5 ( V_118 ) ;
if ( ( ( V_117 & V_119 ) >> V_120 ) == 0x2 ||
( ( V_117 & V_121 ) >> V_122 ) == 0x2 ) {
V_114 |= V_123 ;
if ( ( V_117 & V_124 ) == 1 )
V_114 |= V_125 ;
else
V_114 |= V_126 ;
}
if ( ( F_5 ( V_113 ) & 0xf0000000 ) == 0x10000000 )
V_114 |= V_127 ;
}
} else {
if ( V_105 & V_128 ) {
F_63 ( L_14 ) ;
return 0 ;
}
V_85 = ( V_105 & V_72 ) >> V_73 ;
}
F_66 ( V_129 ,
L_15 , F_53 ,
F_52 ) ;
V_108 = V_130 ;
F_67 ( & V_131 ) ;
F_43 () ;
V_114 |= V_132 ;
F_63 ( L_16 ,
( V_105 & V_133 ) >> V_134 ,
V_85 ,
( V_105 & V_135 ) >> V_136 ,
( V_105 & V_137 ) >> V_138 ,
( V_105 & V_139 ) >> V_140 ) ;
return 0 ;
}
