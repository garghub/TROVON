static unsigned int F_1 ( void )
{
if ( F_2 () > 1 )
return 1 ;
return 0 ;
}
static unsigned int F_3 ( unsigned int V_1 )
{
return V_1 >> F_1 () ;
}
static unsigned int F_4 ( unsigned int V_2 )
{
if ( F_5 () == 1 )
V_2 = ( V_2 + 2 ) & 3 ;
return V_2 ;
}
static T_1 F_6 ( unsigned int V_2 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return ( V_3 ) F_7 () ;
case 1 :
return ( V_3 ) F_8 () ;
case 2 :
return ( V_3 ) F_9 () ;
case 3 :
return ( V_3 ) F_10 () ;
default:
F_11 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static T_1 F_12 ( unsigned int V_2 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return F_13 () ;
case 1 :
return F_14 () ;
case 2 :
return F_15 () ;
case 3 :
return F_16 () ;
default:
F_11 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static void F_17 ( unsigned int V_2 , T_1 V_4 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_18 ( V_4 ) ;
return;
case 1 :
F_19 ( V_4 ) ;
return;
case 2 :
F_20 ( V_4 ) ;
return;
case 3 :
F_21 ( V_4 ) ;
return;
}
}
static void F_22 ( unsigned int V_2 , T_1 V_4 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_23 ( V_4 ) ;
return;
case 1 :
F_24 ( V_4 ) ;
return;
case 2 :
F_25 ( V_4 ) ;
return;
case 3 :
F_26 ( V_4 ) ;
return;
}
}
static unsigned int F_27 ( unsigned int V_2 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return F_28 () ;
case 1 :
return F_29 () ;
case 2 :
return F_30 () ;
case 3 :
return F_31 () ;
default:
F_11 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static void F_32 ( unsigned int V_2 , unsigned int V_4 )
{
V_2 = F_4 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_33 ( V_4 ) ;
return;
case 1 :
F_34 ( V_4 ) ;
return;
case 2 :
F_35 ( V_4 ) ;
return;
case 3 :
F_36 ( V_4 ) ;
return;
}
}
static int F_37 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
unsigned long V_10 = ( V_8 -> V_11 >> 8 ) & 0xffff ;
for ( V_9 = V_12 . V_13 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( F_38 ( V_9 , & V_10 ) &&
! F_39 ( V_9 , V_6 -> V_14 ) )
return V_9 ;
}
return - V_15 ;
}
static void F_40 ( struct V_7 * V_16 , int V_2 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
F_42 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
V_6 -> V_17 [ V_2 ] = F_43 ( V_16 -> V_11 & 0xff ) |
( V_16 -> V_18 & V_19 ) |
V_20 ;
if ( F_44 ( V_21 ) )
V_6 -> V_17 [ V_2 ] |=
( 1 << ( 12 + F_5 () ) ) | V_22 ;
}
static void F_45 ( int V_2 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
unsigned long V_23 ;
F_42 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_46 ( V_23 ) ;
V_6 -> V_17 [ V_2 ] = F_27 ( V_2 ) &
~ V_24 ;
F_32 ( V_2 , V_6 -> V_17 [ V_2 ] ) ;
F_47 ( V_23 ) ;
}
static int F_48 ( struct V_25 * V_26 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_27 = F_49 ( & V_8 -> V_28 ) ;
T_1 V_29 = V_8 -> V_30 ;
int V_31 = 0 ;
if ( F_50 ( ( V_27 + V_29 ) & ( 1ULL << 63 ) ) ) {
V_27 = V_29 ;
F_51 ( & V_8 -> V_28 , V_27 ) ;
V_8 -> V_32 = V_29 ;
V_31 = 1 ;
} else if ( F_50 ( ( V_27 + V_29 ) <= V_29 ) ) {
V_27 += V_29 ;
F_51 ( & V_8 -> V_28 , V_27 ) ;
V_8 -> V_32 = V_29 ;
V_31 = 1 ;
}
if ( V_27 > V_12 . V_33 ) {
V_27 = V_12 . V_33 ;
F_51 ( & V_8 -> V_28 , V_27 ) ;
}
F_51 ( & V_8 -> V_34 , V_12 . V_35 - V_27 ) ;
V_12 . V_36 ( V_2 , V_12 . V_35 - V_27 ) ;
F_52 ( V_26 ) ;
return V_31 ;
}
static void F_53 ( struct V_25 * V_26 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_37 , V_38 ;
T_1 V_39 ;
V_40:
V_37 = F_49 ( & V_8 -> V_34 ) ;
V_38 = V_12 . V_41 ( V_2 ) ;
if ( F_54 ( & V_8 -> V_34 , V_37 ,
V_38 ) != V_37 )
goto V_40;
V_39 = V_38 - V_37 ;
F_55 ( V_39 , & V_26 -> V_42 ) ;
F_56 ( V_39 , & V_8 -> V_28 ) ;
}
static void F_57 ( struct V_25 * V_26 , int V_23 )
{
struct V_7 * V_8 = & V_26 -> V_43 ;
if ( V_23 & V_44 )
F_58 ( ! ( V_8 -> V_45 & V_46 ) ) ;
V_8 -> V_45 = 0 ;
F_48 ( V_26 , V_8 , V_8 -> V_2 ) ;
F_40 ( V_8 , V_8 -> V_2 ) ;
}
static void F_59 ( struct V_25 * V_26 , int V_23 )
{
struct V_7 * V_8 = & V_26 -> V_43 ;
if ( ! ( V_8 -> V_45 & V_47 ) ) {
F_45 ( V_8 -> V_2 ) ;
F_60 () ;
F_53 ( V_26 , V_8 , V_8 -> V_2 ) ;
V_8 -> V_45 |= V_47 | V_46 ;
}
}
static int F_61 ( struct V_25 * V_26 , int V_23 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_7 * V_8 = & V_26 -> V_43 ;
int V_2 ;
int V_48 = 0 ;
F_62 ( V_26 -> V_49 ) ;
V_2 = F_37 ( V_6 , V_8 ) ;
if ( V_2 < 0 ) {
V_48 = V_2 ;
goto V_50;
}
V_26 -> V_43 . V_2 = V_2 ;
F_45 ( V_2 ) ;
V_6 -> V_51 [ V_2 ] = V_26 ;
V_8 -> V_45 = V_47 | V_46 ;
if ( V_23 & V_52 )
F_57 ( V_26 , V_44 ) ;
F_52 ( V_26 ) ;
V_50:
F_63 ( V_26 -> V_49 ) ;
return V_48 ;
}
static void F_64 ( struct V_25 * V_26 , int V_23 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_7 * V_8 = & V_26 -> V_43 ;
int V_2 = V_8 -> V_2 ;
F_42 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_59 ( V_26 , V_53 ) ;
V_6 -> V_51 [ V_2 ] = NULL ;
F_65 ( V_2 , V_6 -> V_14 ) ;
F_52 ( V_26 ) ;
}
static void F_66 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = & V_26 -> V_43 ;
if ( V_8 -> V_2 < 0 )
return;
F_53 ( V_26 , V_8 , V_8 -> V_2 ) ;
}
static void F_67 ( struct V_49 * V_49 )
{
#ifdef F_68
F_69 ( & V_54 ) ;
#endif
F_70 () ;
}
static void F_71 ( struct V_49 * V_49 )
{
F_72 () ;
#ifdef F_68
F_73 ( & V_54 ) ;
#endif
}
static int F_74 ( void )
{
int V_48 ;
if ( V_12 . V_55 >= 0 ) {
V_48 = F_75 ( V_12 . V_55 , V_56 ,
V_57 | V_58 ,
L_2 , NULL ) ;
if ( V_48 ) {
F_76 ( L_3
L_4 , V_12 . V_55 ) ;
}
} else if ( V_59 < 0 ) {
V_60 = V_61 ;
V_61 = V_62 ;
V_48 = 0 ;
} else {
F_76 ( L_5
L_6 ) ;
V_48 = - V_63 ;
}
return V_48 ;
}
static void F_77 ( void )
{
if ( V_12 . V_55 >= 0 )
F_78 ( V_12 . V_55 , NULL ) ;
else if ( V_59 < 0 )
V_61 = V_60 ;
}
static void F_79 ( struct V_25 * V_26 )
{
if ( F_80 ( & V_64 ,
& V_65 ) ) {
F_81 ( V_66 ,
( void * ) ( long ) V_12 . V_13 , 1 ) ;
F_77 () ;
F_82 ( & V_65 ) ;
}
}
static int F_83 ( struct V_25 * V_26 )
{
int V_48 = 0 ;
if ( F_84 ( V_26 ) )
return - V_67 ;
switch ( V_26 -> V_68 . type ) {
case V_69 :
case V_70 :
case V_71 :
break;
default:
return - V_63 ;
}
if ( V_26 -> V_72 >= V_73 ||
( V_26 -> V_72 >= 0 && ! F_85 ( V_26 -> V_72 ) ) )
return - V_74 ;
if ( ! F_86 ( & V_64 ) ) {
F_87 ( & V_65 ) ;
if ( F_88 ( & V_64 ) == 0 )
V_48 = F_74 () ;
if ( ! V_48 )
F_89 ( & V_64 ) ;
F_82 ( & V_65 ) ;
}
if ( V_48 )
return V_48 ;
return F_90 ( V_26 ) ;
}
static unsigned int F_91 ( const struct V_75 * V_76 )
{
#ifdef F_92
return ( ( unsigned int ) V_76 -> V_77 << 24 ) |
( V_76 -> V_10 & 0xffff00 ) |
( V_76 -> V_78 & 0xff ) ;
#else
return ( V_76 -> V_10 & 0xffff00 ) |
( V_76 -> V_78 & 0xff ) ;
#endif
}
static const struct V_75 * F_93 ( int V_2 )
{
if ( ( * V_12 . V_79 ) [ V_2 ] . V_10 == 0 )
return F_94 ( - V_67 ) ;
return & ( * V_12 . V_79 ) [ V_2 ] ;
}
static const struct V_75 * F_95 ( T_1 V_80 )
{
unsigned int V_81 , V_82 , V_83 ;
const struct V_75 * V_76 ;
V_81 = ( V_80 >> 0 ) & 0xff ;
if ( V_81 >= V_84 )
return F_94 ( - V_85 ) ;
V_82 = ( V_80 >> 8 ) & 0xff ;
if ( V_82 >= V_86 )
return F_94 ( - V_85 ) ;
V_83 = ( V_80 >> 16 ) & 0xff ;
if ( V_83 >= V_87 )
return F_94 ( - V_85 ) ;
V_76 = & ( ( * V_12 . V_88 )
[ V_81 ]
[ V_82 ]
[ V_83 ] ) ;
if ( V_76 -> V_10 == 0 )
return F_94 ( - V_67 ) ;
return V_76 ;
}
static int F_96 ( struct V_25 * V_26 )
{
struct V_25 * V_89 , * V_90 = V_26 -> V_91 ;
struct V_5 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
if ( F_37 ( & V_92 , & V_90 -> V_43 ) < 0 )
return - V_85 ;
F_97 (sibling, &leader->sibling_list, group_entry) {
if ( F_37 ( & V_92 , & V_89 -> V_43 ) < 0 )
return - V_85 ;
}
if ( F_37 ( & V_92 , & V_26 -> V_43 ) < 0 )
return - V_85 ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 ,
int V_2 , struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_25 * V_26 = V_6 -> V_51 [ V_2 ] ;
struct V_7 * V_8 = & V_26 -> V_43 ;
F_53 ( V_26 , V_8 , V_2 ) ;
V_94 -> V_29 = V_26 -> V_43 . V_32 ;
if ( ! F_48 ( V_26 , V_8 , V_2 ) )
return;
if ( F_99 ( V_26 , V_94 , V_96 ) )
F_45 ( V_2 ) ;
}
static int F_100 ( void )
{
if ( ! ( F_101 () & V_97 ) )
return 0 ;
if ( ! ( F_28 () & V_98 ) )
return 1 ;
if ( ! ( F_29 () & V_98 ) )
return 2 ;
if ( ! ( F_30 () & V_98 ) )
return 3 ;
return 4 ;
}
static int F_102 ( void )
{
int V_1 ;
switch ( F_103 () ) {
case V_99 :
V_1 = 2 ;
break;
case V_100 :
case V_101 :
V_1 = 4 ;
break;
default:
V_1 = F_100 () ;
}
return V_1 ;
}
static void V_66 ( void * V_102 )
{
int V_1 = ( int ) ( long ) V_102 ;
switch ( V_1 ) {
case 4 :
F_32 ( 3 , 0 ) ;
V_12 . V_36 ( 3 , 0 ) ;
case 3 :
F_32 ( 2 , 0 ) ;
V_12 . V_36 ( 2 , 0 ) ;
case 2 :
F_32 ( 1 , 0 ) ;
V_12 . V_36 ( 1 , 0 ) ;
case 1 :
F_32 ( 0 , 0 ) ;
V_12 . V_36 ( 0 , 0 ) ;
}
}
static void F_104 ( struct V_25 * V_26 ,
const struct V_75 * V_76 )
{
struct V_7 * V_8 = & V_26 -> V_43 ;
if ( V_26 -> V_72 >= 0 ) {
if ( V_76 -> V_77 > V_103 ) {
V_8 -> V_18 |= V_104 ;
} else {
V_8 -> V_18 |= F_105 ( V_26 -> V_72 ) ;
V_8 -> V_18 |= V_105 ;
}
} else
V_8 -> V_18 |= V_104 ;
}
static void F_104 ( struct V_25 * V_26 ,
const struct V_75 * V_76 )
{
}
static int F_90 ( struct V_25 * V_26 )
{
struct V_106 * V_68 = & V_26 -> V_68 ;
struct V_7 * V_8 = & V_26 -> V_43 ;
const struct V_75 * V_76 ;
int V_48 ;
if ( V_70 == V_26 -> V_68 . type ) {
if ( V_26 -> V_68 . V_80 >= V_107 )
return - V_85 ;
V_76 = F_93 ( V_26 -> V_68 . V_80 ) ;
} else if ( V_71 == V_26 -> V_68 . type ) {
V_76 = F_95 ( V_26 -> V_68 . V_80 ) ;
} else if ( V_69 == V_26 -> V_68 . type ) {
F_87 ( & V_108 ) ;
V_76 = V_12 . V_109 ( V_26 -> V_68 . V_80 ) ;
} else {
return - V_67 ;
}
if ( F_106 ( V_76 ) ) {
if ( V_69 == V_26 -> V_68 . type )
F_82 ( & V_108 ) ;
return F_107 ( V_76 ) ;
}
V_8 -> V_18 = V_20 ;
if ( F_2 () > 1 )
F_104 ( V_26 , V_76 ) ;
V_8 -> V_11 = F_91 ( V_76 ) ;
if ( V_69 == V_26 -> V_68 . type )
F_82 ( & V_108 ) ;
if ( ! V_68 -> V_110 )
V_8 -> V_18 |= V_111 ;
if ( ! V_68 -> V_112 ) {
V_8 -> V_18 |= V_113 ;
V_8 -> V_18 |= V_114 ;
}
if ( ! V_68 -> V_115 )
V_8 -> V_18 |= V_116 ;
V_8 -> V_18 &= V_19 ;
V_8 -> V_2 = - 1 ;
V_8 -> V_80 = 0 ;
if ( ! V_8 -> V_30 ) {
V_8 -> V_30 = V_12 . V_33 ;
V_8 -> V_32 = V_8 -> V_30 ;
F_51 ( & V_8 -> V_28 , V_8 -> V_30 ) ;
}
V_48 = 0 ;
if ( V_26 -> V_91 != V_26 )
V_48 = F_96 ( V_26 ) ;
V_26 -> V_117 = F_79 ;
if ( V_48 )
V_26 -> V_117 ( V_26 ) ;
return V_48 ;
}
static void F_72 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
int V_118 = V_12 . V_13 ;
unsigned long V_23 ;
F_46 ( V_23 ) ;
do {
V_118 -- ;
V_6 -> V_17 [ V_118 ] = F_27 ( V_118 ) ;
F_32 ( V_118 , V_6 -> V_17 [ V_118 ] &
~ V_24 ) ;
} while ( V_118 > 0 );
F_47 ( V_23 ) ;
}
static void F_70 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
int V_118 = V_12 . V_13 ;
do {
V_118 -- ;
F_32 ( V_118 , V_6 -> V_17 [ V_118 ] ) ;
} while ( V_118 > 0 );
}
static int V_62 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_93 V_94 ;
unsigned int V_1 = V_12 . V_13 ;
T_1 V_119 ;
int V_120 = V_121 ;
struct V_95 * V_96 ;
if ( V_122 && ! ( F_108 () & V_123 ) )
return V_120 ;
F_72 () ;
#ifdef F_68
F_109 ( & V_54 ) ;
#endif
V_96 = F_110 () ;
F_111 ( & V_94 , 0 , 0 ) ;
switch ( V_1 ) {
#define F_112 ( T_2 ) \
case n + 1: \
if (test_bit(n, cpuc->used_mask)) { \
counter = mipspmu.read_counter(n); \
if (counter & mipspmu.overflow) { \
handle_associated_event(cpuc, n, &data, regs); \
handled = IRQ_HANDLED; \
} \
}
F_112 ( 3 )
F_112 ( 2 )
F_112 ( 1 )
F_112 ( 0 )
}
if ( V_120 == V_124 )
F_113 () ;
#ifdef F_68
F_114 ( & V_54 ) ;
#endif
F_70 () ;
return V_120 ;
}
static T_3 V_56 ( int V_55 , void * V_125 )
{
return V_62 () ;
}
static const struct V_75 * F_115 ( T_1 V_80 )
{
unsigned int V_126 = V_80 & 0xff ;
unsigned int V_127 = V_126 & 0x7f ;
V_128 . V_78 = V_127 ;
switch ( F_103 () ) {
case V_129 :
if ( F_116 ( V_127 ) )
V_128 . V_10 = V_130 | V_131 ;
else
V_128 . V_10 =
V_126 > 127 ? V_131 : V_130 ;
#ifdef F_92
V_128 . V_77 = V_132 ;
#endif
break;
case V_133 :
if ( F_117 ( V_127 ) )
V_128 . V_10 = V_130 | V_131 ;
else
V_128 . V_10 =
V_126 > 127 ? V_131 : V_130 ;
#ifdef F_92
if ( F_118 ( V_126 , V_127 ) )
V_128 . V_77 = V_132 ;
else if ( F_50 ( F_119 ( V_126 ) ) )
V_128 . V_77 = V_103 ;
else
V_128 . V_77 = V_134 ;
#endif
break;
case V_135 :
if ( F_120 ( V_127 ) )
V_128 . V_10 = V_130 | V_131 ;
else
V_128 . V_10 =
V_126 > 127 ? V_131 : V_130 ;
#ifdef F_92
V_128 . V_77 = V_132 ;
#endif
break;
case V_136 :
if ( F_121 ( V_127 ) )
V_128 . V_10 = V_130 | V_131 ;
else
V_128 . V_10 =
V_126 > 127 ? V_131 : V_130 ;
#ifdef F_92
if ( F_122 ( V_126 , V_127 ) )
V_128 . V_77 = V_132 ;
else if ( F_50 ( F_123 ( V_126 ) ) )
V_128 . V_77 = V_103 ;
else
V_128 . V_77 = V_134 ;
#endif
break;
case V_137 :
if ( F_124 ( V_127 ) )
V_128 . V_10 = V_130 | V_131 ;
else
V_128 . V_10 =
V_126 > 127 ? V_131 : V_130 ;
}
return & V_128 ;
}
static const struct V_75 * F_125 ( T_1 V_80 )
{
unsigned int V_126 = V_80 & 0xff ;
unsigned int V_127 = V_126 & 0x7f ;
V_128 . V_10 = V_138 ;
V_128 . V_78 = V_127 ;
if ( F_103 () == V_139 ) {
if ( V_127 > 0x42 )
return F_94 ( - V_67 ) ;
} else {
if ( V_127 > 0x3a )
return F_94 ( - V_67 ) ;
}
switch ( V_127 ) {
case 0x00 :
case 0x0f :
case 0x1e :
case 0x1f :
case 0x2f :
case 0x34 :
case 0x3b ... 0x3f :
return F_94 ( - V_67 ) ;
default:
break;
}
return & V_128 ;
}
static const struct V_75 * F_126 ( T_1 V_80 )
{
unsigned int V_126 = V_80 & 0xff ;
if ( ( V_126 < 0x01 ) || ( V_126 > 0x3f ) )
return F_94 ( - V_67 ) ;
V_128 . V_10 = V_138 ;
V_128 . V_78 = V_126 ;
return & V_128 ;
}
static int T_4
F_127 ( void )
{
int V_1 , V_55 ;
int V_140 ;
F_128 ( L_7 ) ;
V_1 = F_102 () ;
if ( V_1 == 0 ) {
F_129 ( L_8 ) ;
return - V_74 ;
}
#ifdef F_68
V_141 = F_130 () & ( 1 << 19 ) ;
if ( ! V_141 )
V_1 = F_3 ( V_1 ) ;
#endif
#ifdef F_131
if ( V_142 ) {
V_55 = F_131 + V_143 ;
} else {
#endif
if ( ( V_59 >= 0 ) &&
( V_144 != V_59 ) )
V_55 = V_145 + V_59 ;
else
V_55 = - 1 ;
#ifdef F_131
}
#endif
V_12 . V_109 = F_115 ;
switch ( F_103 () ) {
case V_129 :
V_12 . V_146 = L_9 ;
V_12 . V_79 = & V_147 ;
V_12 . V_88 = & V_148 ;
break;
case V_133 :
V_12 . V_146 = L_10 ;
V_12 . V_79 = & V_147 ;
V_12 . V_88 = & V_148 ;
break;
case V_135 :
V_12 . V_146 = L_11 ;
V_12 . V_79 = & V_149 ;
V_12 . V_88 = & V_150 ;
break;
case V_136 :
V_12 . V_146 = L_12 ;
V_12 . V_79 = & V_147 ;
V_12 . V_88 = & V_148 ;
break;
case V_151 :
V_12 . V_146 = L_13 ;
V_12 . V_79 = & V_147 ;
V_12 . V_88 = & V_148 ;
break;
case V_152 :
case V_153 :
case V_139 :
V_12 . V_146 = L_14 ;
V_12 . V_79 = & V_154 ;
V_12 . V_88 = & V_155 ;
V_12 . V_109 = F_125 ;
break;
case V_137 :
V_12 . V_146 = L_15 ;
V_12 . V_79 = & V_156 ;
V_12 . V_88 = & V_157 ;
break;
case V_158 :
V_12 . V_146 = L_16 ;
V_12 . V_79 = & V_159 ;
V_12 . V_88 = & V_160 ;
V_12 . V_109 = F_126 ;
break;
default:
F_129 ( L_17
L_18 ) ;
return - V_74 ;
}
V_12 . V_13 = V_1 ;
V_12 . V_55 = V_55 ;
if ( F_28 () & V_161 ) {
V_12 . V_33 = ( 1ULL << 63 ) - 1 ;
V_12 . V_162 = ( 1ULL << 63 ) - 1 ;
V_12 . V_35 = 1ULL << 63 ;
V_12 . V_41 = F_12 ;
V_12 . V_36 = F_22 ;
V_140 = 64 ;
} else {
V_12 . V_33 = ( 1ULL << 31 ) - 1 ;
V_12 . V_162 = ( 1ULL << 31 ) - 1 ;
V_12 . V_35 = 1ULL << 31 ;
V_12 . V_41 = F_6 ;
V_12 . V_36 = F_17 ;
V_140 = 32 ;
}
F_81 ( V_66 , ( void * ) ( long ) V_1 , 1 ) ;
F_129 ( L_19
L_20 , V_12 . V_146 , V_1 , V_140 , V_55 ,
V_55 < 0 ? L_21 : L_22 ) ;
F_132 ( & V_49 , L_23 , V_69 ) ;
return 0 ;
}
