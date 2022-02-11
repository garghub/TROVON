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
static unsigned int F_4 ( unsigned int V_1 )
{
return V_1 << F_1 () ;
}
static unsigned int F_5 ( unsigned int V_2 )
{
if ( F_6 () == 1 )
V_2 = ( V_2 + 2 ) & 3 ;
return V_2 ;
}
static T_1 F_7 ( unsigned int V_2 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return ( V_3 ) F_8 () ;
case 1 :
return ( V_3 ) F_9 () ;
case 2 :
return ( V_3 ) F_10 () ;
case 3 :
return ( V_3 ) F_11 () ;
default:
F_12 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static T_1 F_13 ( unsigned int V_2 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return F_14 () ;
case 1 :
return F_15 () ;
case 2 :
return F_16 () ;
case 3 :
return F_17 () ;
default:
F_12 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static void F_18 ( unsigned int V_2 , T_1 V_4 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_19 ( V_4 ) ;
return;
case 1 :
F_20 ( V_4 ) ;
return;
case 2 :
F_21 ( V_4 ) ;
return;
case 3 :
F_22 ( V_4 ) ;
return;
}
}
static void F_23 ( unsigned int V_2 , T_1 V_4 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_24 ( V_4 ) ;
return;
case 1 :
F_25 ( V_4 ) ;
return;
case 2 :
F_26 ( V_4 ) ;
return;
case 3 :
F_27 ( V_4 ) ;
return;
}
}
static unsigned int F_28 ( unsigned int V_2 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
return F_29 () ;
case 1 :
return F_30 () ;
case 2 :
return F_31 () ;
case 3 :
return F_32 () ;
default:
F_12 ( 1 , L_1 , V_2 ) ;
return 0 ;
}
}
static void F_33 ( unsigned int V_2 , unsigned int V_4 )
{
V_2 = F_5 ( V_2 ) ;
switch ( V_2 ) {
case 0 :
F_34 ( V_4 ) ;
return;
case 1 :
F_35 ( V_4 ) ;
return;
case 2 :
F_36 ( V_4 ) ;
return;
case 3 :
F_37 ( V_4 ) ;
return;
}
}
static int F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
unsigned long V_10 = ( V_8 -> V_11 >> 8 ) & 0xffff ;
for ( V_9 = V_12 . V_13 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( F_39 ( V_9 , & V_10 ) &&
! F_40 ( V_9 , V_6 -> V_14 ) )
return V_9 ;
}
return - V_15 ;
}
static void F_41 ( struct V_7 * V_16 , int V_2 )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
F_43 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
V_6 -> V_17 [ V_2 ] = F_44 ( V_16 -> V_11 & 0xff ) |
( V_16 -> V_18 & V_19 ) |
V_20 ;
}
static void F_45 ( int V_2 )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
unsigned long V_21 ;
F_43 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_46 ( V_21 ) ;
V_6 -> V_17 [ V_2 ] = F_28 ( V_2 ) &
~ V_22 ;
F_33 ( V_2 , V_6 -> V_17 [ V_2 ] ) ;
F_47 ( V_21 ) ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_25 = F_49 ( & V_8 -> V_26 ) ;
T_1 V_27 = V_8 -> V_28 ;
int V_29 = 0 ;
if ( F_50 ( ( V_25 + V_27 ) & ( 1ULL << 63 ) ) ) {
V_25 = V_27 ;
F_51 ( & V_8 -> V_26 , V_25 ) ;
V_8 -> V_30 = V_27 ;
V_29 = 1 ;
} else if ( F_50 ( ( V_25 + V_27 ) <= V_27 ) ) {
V_25 += V_27 ;
F_51 ( & V_8 -> V_26 , V_25 ) ;
V_8 -> V_30 = V_27 ;
V_29 = 1 ;
}
if ( V_25 > V_12 . V_31 ) {
V_25 = V_12 . V_31 ;
F_51 ( & V_8 -> V_26 , V_25 ) ;
}
F_51 ( & V_8 -> V_32 , V_12 . V_33 - V_25 ) ;
V_12 . V_34 ( V_2 , V_12 . V_33 - V_25 ) ;
F_52 ( V_24 ) ;
return V_29 ;
}
static void F_53 ( struct V_23 * V_24 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_35 , V_36 ;
T_1 V_37 ;
V_38:
V_35 = F_49 ( & V_8 -> V_32 ) ;
V_36 = V_12 . V_39 ( V_2 ) ;
if ( F_54 ( & V_8 -> V_32 , V_35 ,
V_36 ) != V_35 )
goto V_38;
V_37 = V_36 - V_35 ;
F_55 ( V_37 , & V_24 -> V_40 ) ;
F_56 ( V_37 , & V_8 -> V_26 ) ;
}
static void F_57 ( struct V_23 * V_24 , int V_21 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_21 & V_42 )
F_58 ( ! ( V_8 -> V_43 & V_44 ) ) ;
V_8 -> V_43 = 0 ;
F_48 ( V_24 , V_8 , V_8 -> V_2 ) ;
F_41 ( V_8 , V_8 -> V_2 ) ;
}
static void F_59 ( struct V_23 * V_24 , int V_21 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( ! ( V_8 -> V_43 & V_45 ) ) {
F_45 ( V_8 -> V_2 ) ;
F_60 () ;
F_53 ( V_24 , V_8 , V_8 -> V_2 ) ;
V_8 -> V_43 |= V_45 | V_44 ;
}
}
static int F_61 ( struct V_23 * V_24 , int V_21 )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
struct V_7 * V_8 = & V_24 -> V_41 ;
int V_2 ;
int V_46 = 0 ;
F_62 ( V_24 -> V_47 ) ;
V_2 = F_38 ( V_6 , V_8 ) ;
if ( V_2 < 0 ) {
V_46 = V_2 ;
goto V_48;
}
V_24 -> V_41 . V_2 = V_2 ;
F_45 ( V_2 ) ;
V_6 -> V_49 [ V_2 ] = V_24 ;
V_8 -> V_43 = V_45 | V_44 ;
if ( V_21 & V_50 )
F_57 ( V_24 , V_42 ) ;
F_52 ( V_24 ) ;
V_48:
F_63 ( V_24 -> V_47 ) ;
return V_46 ;
}
static void F_64 ( struct V_23 * V_24 , int V_21 )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
struct V_7 * V_8 = & V_24 -> V_41 ;
int V_2 = V_8 -> V_2 ;
F_43 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_59 ( V_24 , V_51 ) ;
V_6 -> V_49 [ V_2 ] = NULL ;
F_65 ( V_2 , V_6 -> V_14 ) ;
F_52 ( V_24 ) ;
}
static void F_66 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_8 -> V_2 < 0 )
return;
F_53 ( V_24 , V_8 , V_8 -> V_2 ) ;
}
static void F_67 ( struct V_47 * V_47 )
{
#ifdef F_68
F_69 ( & V_52 ) ;
#endif
F_70 () ;
}
static void F_71 ( struct V_47 * V_47 )
{
F_72 () ;
#ifdef F_68
F_73 ( & V_52 ) ;
#endif
}
static int F_74 ( void )
{
int V_46 ;
if ( V_12 . V_53 >= 0 ) {
V_46 = F_75 ( V_12 . V_53 , V_54 ,
V_55 | V_56 ,
L_2 , NULL ) ;
if ( V_46 ) {
F_76 ( L_3
L_4 , V_12 . V_53 ) ;
}
} else if ( V_57 < 0 ) {
V_58 = V_59 ;
V_59 = V_60 ;
V_46 = 0 ;
} else {
F_76 ( L_5
L_6 ) ;
V_46 = - V_61 ;
}
return V_46 ;
}
static void F_77 ( void )
{
if ( V_12 . V_53 >= 0 )
F_78 ( V_12 . V_53 , NULL ) ;
else if ( V_57 < 0 )
V_59 = V_58 ;
}
static void F_79 ( struct V_23 * V_24 )
{
if ( F_80 ( & V_62 ,
& V_63 ) ) {
F_81 ( V_64 ,
( void * ) ( long ) V_12 . V_13 , 1 ) ;
F_77 () ;
F_82 ( & V_63 ) ;
}
}
static int F_83 ( struct V_23 * V_24 )
{
int V_46 = 0 ;
switch ( V_24 -> V_65 . type ) {
case V_66 :
case V_67 :
case V_68 :
break;
default:
return - V_61 ;
}
if ( V_24 -> V_69 >= V_70 ||
( V_24 -> V_69 >= 0 && ! F_84 ( V_24 -> V_69 ) ) )
return - V_71 ;
if ( ! F_85 ( & V_62 ) ) {
if ( F_86 ( & V_62 ) > V_72 ) {
F_87 ( & V_62 ) ;
return - V_73 ;
}
F_88 ( & V_63 ) ;
if ( F_86 ( & V_62 ) == 0 )
V_46 = F_74 () ;
if ( ! V_46 )
F_89 ( & V_62 ) ;
F_82 ( & V_63 ) ;
}
if ( V_46 )
return V_46 ;
V_46 = F_90 ( V_24 ) ;
if ( V_46 )
F_79 ( V_24 ) ;
return V_46 ;
}
static unsigned int F_91 ( const struct V_74 * V_75 )
{
#ifdef F_68
return ( ( unsigned int ) V_75 -> V_76 << 24 ) |
( V_75 -> V_10 & 0xffff00 ) |
( V_75 -> V_77 & 0xff ) ;
#else
return ( V_75 -> V_10 & 0xffff00 ) |
( V_75 -> V_77 & 0xff ) ;
#endif
}
static const struct V_74 * F_92 ( int V_2 )
{
const struct V_74 * V_75 ;
V_75 = ( ( * V_12 . V_78 ) [ V_2 ] . V_77 ==
V_79 ? F_93 ( - V_80 ) :
& ( * V_12 . V_78 ) [ V_2 ] ) ;
return V_75 ;
}
static const struct V_74 * F_94 ( T_1 V_81 )
{
unsigned int V_82 , V_83 , V_84 ;
const struct V_74 * V_75 ;
V_82 = ( V_81 >> 0 ) & 0xff ;
if ( V_82 >= V_85 )
return F_93 ( - V_73 ) ;
V_83 = ( V_81 >> 8 ) & 0xff ;
if ( V_83 >= V_86 )
return F_93 ( - V_73 ) ;
V_84 = ( V_81 >> 16 ) & 0xff ;
if ( V_84 >= V_87 )
return F_93 ( - V_73 ) ;
V_75 = & ( ( * V_12 . V_88 )
[ V_82 ]
[ V_83 ]
[ V_84 ] ) ;
if ( V_75 -> V_77 == V_79 )
return F_93 ( - V_80 ) ;
return V_75 ;
}
static int F_95 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_7 V_89 = V_24 -> V_41 ;
if ( V_24 -> V_47 != & V_47 || V_24 -> V_43 <= V_90 )
return 1 ;
return F_38 ( V_6 , & V_89 ) >= 0 ;
}
static int F_96 ( struct V_23 * V_24 )
{
struct V_23 * V_91 , * V_92 = V_24 -> V_93 ;
struct V_5 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
if ( ! F_95 ( & V_94 , V_92 ) )
return - V_73 ;
F_97 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_95 ( & V_94 , V_91 ) )
return - V_73 ;
}
if ( ! F_95 ( & V_94 , V_24 ) )
return - V_73 ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 ,
int V_2 , struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_23 * V_24 = V_6 -> V_49 [ V_2 ] ;
struct V_7 * V_8 = & V_24 -> V_41 ;
F_53 ( V_24 , V_8 , V_2 ) ;
V_96 -> V_27 = V_24 -> V_41 . V_30 ;
if ( ! F_48 ( V_24 , V_8 , V_2 ) )
return;
if ( F_99 ( V_24 , V_96 , V_98 ) )
F_45 ( V_2 ) ;
}
static int F_100 ( void )
{
if ( ! ( F_101 () & V_99 ) )
return 0 ;
if ( ! ( F_29 () & V_100 ) )
return 1 ;
if ( ! ( F_30 () & V_100 ) )
return 2 ;
if ( ! ( F_31 () & V_100 ) )
return 3 ;
return 4 ;
}
static int F_102 ( void )
{
int V_1 ;
switch ( F_103 () ) {
case V_101 :
V_1 = 2 ;
break;
case V_102 :
case V_103 :
V_1 = 4 ;
break;
default:
V_1 = F_100 () ;
}
return V_1 ;
}
static void V_64 ( void * V_104 )
{
int V_1 = ( int ) ( long ) V_104 ;
switch ( V_1 ) {
case 4 :
F_33 ( 3 , 0 ) ;
V_12 . V_34 ( 3 , 0 ) ;
case 3 :
F_33 ( 2 , 0 ) ;
V_12 . V_34 ( 2 , 0 ) ;
case 2 :
F_33 ( 1 , 0 ) ;
V_12 . V_34 ( 1 , 0 ) ;
case 1 :
F_33 ( 0 , 0 ) ;
V_12 . V_34 ( 0 , 0 ) ;
}
}
static void F_104 ( struct V_23 * V_24 ,
const struct V_74 * V_75 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_24 -> V_69 >= 0 ) {
if ( V_75 -> V_76 > V_105 ) {
V_8 -> V_18 |= V_106 ;
} else {
V_8 -> V_18 |= F_105 ( V_24 -> V_69 ) ;
V_8 -> V_18 |= V_107 ;
}
} else
V_8 -> V_18 |= V_106 ;
}
static void F_104 ( struct V_23 * V_24 ,
const struct V_74 * V_75 )
{
}
static int F_90 ( struct V_23 * V_24 )
{
struct V_108 * V_65 = & V_24 -> V_65 ;
struct V_7 * V_8 = & V_24 -> V_41 ;
const struct V_74 * V_75 ;
int V_46 ;
if ( V_67 == V_24 -> V_65 . type ) {
if ( V_24 -> V_65 . V_81 >= V_109 )
return - V_73 ;
V_75 = F_92 ( V_24 -> V_65 . V_81 ) ;
} else if ( V_68 == V_24 -> V_65 . type ) {
V_75 = F_94 ( V_24 -> V_65 . V_81 ) ;
} else if ( V_66 == V_24 -> V_65 . type ) {
F_88 ( & V_110 ) ;
V_75 = V_12 . V_111 ( V_24 -> V_65 . V_81 ) ;
} else {
return - V_80 ;
}
if ( F_106 ( V_75 ) ) {
if ( V_66 == V_24 -> V_65 . type )
F_82 ( & V_110 ) ;
return F_107 ( V_75 ) ;
}
V_8 -> V_18 = V_20 ;
if ( F_2 () > 1 )
F_104 ( V_24 , V_75 ) ;
V_8 -> V_11 = F_91 ( V_75 ) ;
if ( V_66 == V_24 -> V_65 . type )
F_82 ( & V_110 ) ;
if ( ! V_65 -> V_112 )
V_8 -> V_18 |= V_113 ;
if ( ! V_65 -> V_114 ) {
V_8 -> V_18 |= V_115 ;
V_8 -> V_18 |= V_116 ;
}
if ( ! V_65 -> V_117 )
V_8 -> V_18 |= V_118 ;
V_8 -> V_18 &= V_19 ;
V_8 -> V_2 = - 1 ;
V_8 -> V_81 = 0 ;
if ( ! V_8 -> V_28 ) {
V_8 -> V_28 = V_12 . V_31 ;
V_8 -> V_30 = V_8 -> V_28 ;
F_51 ( & V_8 -> V_26 , V_8 -> V_28 ) ;
}
V_46 = 0 ;
if ( V_24 -> V_93 != V_24 ) {
V_46 = F_96 ( V_24 ) ;
if ( V_46 )
return - V_73 ;
}
V_24 -> V_119 = F_79 ;
return V_46 ;
}
static void F_72 ( void )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
int V_120 = V_12 . V_13 ;
unsigned long V_21 ;
F_46 ( V_21 ) ;
do {
V_120 -- ;
V_6 -> V_17 [ V_120 ] = F_28 ( V_120 ) ;
F_33 ( V_120 , V_6 -> V_17 [ V_120 ] &
~ V_22 ) ;
} while ( V_120 > 0 );
F_47 ( V_21 ) ;
}
static void F_70 ( void )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
int V_120 = V_12 . V_13 ;
do {
V_120 -- ;
F_33 ( V_120 , V_6 -> V_17 [ V_120 ] ) ;
} while ( V_120 > 0 );
}
static int V_60 ( void )
{
struct V_5 * V_6 = & F_42 ( V_5 ) ;
struct V_95 V_96 ;
unsigned int V_1 = V_12 . V_13 ;
T_1 V_121 ;
int V_122 = V_123 ;
struct V_97 * V_98 ;
if ( V_124 && ! ( F_108 () & ( 1 << 26 ) ) )
return V_122 ;
F_72 () ;
#ifdef F_68
F_109 ( & V_52 ) ;
#endif
V_98 = F_110 () ;
F_111 ( & V_96 , 0 ) ;
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
if ( V_122 == V_125 )
F_113 () ;
#ifdef F_68
F_114 ( & V_52 ) ;
#endif
F_70 () ;
return V_122 ;
}
static T_3 V_54 ( int V_53 , void * V_126 )
{
return V_60 () ;
}
static const struct V_74 * F_115 ( T_1 V_81 )
{
unsigned int V_127 = V_81 & 0xff ;
unsigned int V_128 = V_127 & 0x7f ;
switch ( F_103 () ) {
case V_129 :
if ( F_116 ( V_127 , V_128 ) )
return F_93 ( - V_80 ) ;
V_130 . V_77 = V_128 ;
if ( F_117 ( V_128 ) )
V_130 . V_10 = V_131 | V_132 ;
else
V_130 . V_10 =
V_127 > 127 ? V_132 : V_131 ;
#ifdef F_68
V_130 . V_76 = V_133 ;
#endif
break;
case V_134 :
if ( F_118 ( V_127 , V_128 ) )
return F_93 ( - V_80 ) ;
V_130 . V_77 = V_128 ;
if ( F_119 ( V_128 ) )
V_130 . V_10 = V_131 | V_132 ;
else
V_130 . V_10 =
V_127 > 127 ? V_132 : V_131 ;
#ifdef F_68
if ( F_120 ( V_127 , V_128 ) )
V_130 . V_76 = V_133 ;
else if ( F_50 ( F_121 ( V_127 ) ) )
V_130 . V_76 = V_105 ;
else
V_130 . V_76 = V_135 ;
#endif
break;
case V_136 :
if ( F_122 ( V_127 , V_128 ) )
return F_93 ( - V_80 ) ;
V_130 . V_77 = V_128 ;
if ( F_123 ( V_128 ) )
V_130 . V_10 = V_131 | V_132 ;
else
V_130 . V_10 =
V_127 > 127 ? V_132 : V_131 ;
#ifdef F_68
V_130 . V_76 = V_133 ;
#endif
break;
case V_137 :
if ( F_124 ( V_127 , V_128 ) )
return F_93 ( - V_80 ) ;
V_130 . V_77 = V_128 ;
if ( F_125 ( V_128 ) )
V_130 . V_10 = V_131 | V_132 ;
else
V_130 . V_10 =
V_127 > 127 ? V_132 : V_131 ;
#ifdef F_68
if ( F_126 ( V_127 , V_128 ) )
V_130 . V_76 = V_133 ;
else if ( F_50 ( F_127 ( V_127 ) ) )
V_130 . V_76 = V_105 ;
else
V_130 . V_76 = V_135 ;
#endif
break;
}
return & V_130 ;
}
static const struct V_74 * F_128 ( T_1 V_81 )
{
unsigned int V_127 = V_81 & 0xff ;
unsigned int V_128 = V_127 & 0x7f ;
V_130 . V_10 = V_138 ;
V_130 . V_77 = V_128 ;
if ( F_103 () == V_139 ) {
if ( V_128 > 0x42 )
return F_93 ( - V_80 ) ;
} else {
if ( V_128 > 0x3a )
return F_93 ( - V_80 ) ;
}
switch ( V_128 ) {
case 0x00 :
case 0x0f :
case 0x1e :
case 0x1f :
case 0x2f :
case 0x34 :
case 0x3b ... 0x3f :
return F_93 ( - V_80 ) ;
default:
break;
}
return & V_130 ;
}
static int T_4
F_129 ( void )
{
int V_1 , V_53 ;
int V_140 ;
F_130 ( L_7 ) ;
V_1 = F_102 () ;
if ( V_1 == 0 ) {
F_131 ( L_8 ) ;
return - V_71 ;
}
#ifdef F_68
V_141 = F_132 () & ( 1 << 19 ) ;
if ( ! V_141 )
V_1 = F_3 ( V_1 ) ;
#endif
#ifdef F_133
if ( V_142 ) {
V_53 = F_133 + V_143 ;
} else {
#endif
if ( V_57 >= 0 )
V_53 = V_144 + V_57 ;
else
V_53 = - 1 ;
#ifdef F_133
}
#endif
V_12 . V_111 = F_115 ;
switch ( F_103 () ) {
case V_129 :
V_12 . V_145 = L_9 ;
V_12 . V_78 = & V_146 ;
V_12 . V_88 = & V_147 ;
break;
case V_134 :
V_12 . V_145 = L_10 ;
V_12 . V_78 = & V_146 ;
V_12 . V_88 = & V_147 ;
break;
case V_136 :
V_12 . V_145 = L_11 ;
V_12 . V_78 = & V_148 ;
V_12 . V_88 = & V_149 ;
break;
case V_137 :
V_12 . V_145 = L_12 ;
V_12 . V_78 = & V_146 ;
V_12 . V_88 = & V_147 ;
break;
case V_150 :
case V_151 :
case V_139 :
V_12 . V_145 = L_13 ;
V_12 . V_78 = & V_152 ;
V_12 . V_88 = & V_153 ;
V_12 . V_111 = F_128 ;
break;
default:
F_131 ( L_14
L_15 ) ;
return - V_71 ;
}
V_12 . V_13 = V_1 ;
V_12 . V_53 = V_53 ;
if ( F_29 () & V_154 ) {
V_12 . V_31 = ( 1ULL << 63 ) - 1 ;
V_12 . V_155 = ( 1ULL << 63 ) - 1 ;
V_12 . V_33 = 1ULL << 63 ;
V_12 . V_39 = F_13 ;
V_12 . V_34 = F_23 ;
V_140 = 64 ;
} else {
V_12 . V_31 = ( 1ULL << 31 ) - 1 ;
V_12 . V_155 = ( 1ULL << 31 ) - 1 ;
V_12 . V_33 = 1ULL << 31 ;
V_12 . V_39 = F_7 ;
V_12 . V_34 = F_18 ;
V_140 = 32 ;
}
F_81 ( V_64 , ( void * ) ( long ) V_1 , 1 ) ;
F_131 ( L_16
L_17 , V_12 . V_145 , V_1 , V_140 , V_53 ,
V_53 < 0 ? L_18 : L_19 ) ;
F_134 ( & V_47 , L_20 , V_66 ) ;
return 0 ;
}
