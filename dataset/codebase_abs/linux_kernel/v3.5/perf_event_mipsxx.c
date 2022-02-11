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
}
static void F_44 ( int V_2 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
unsigned long V_21 ;
F_42 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_45 ( V_21 ) ;
V_6 -> V_17 [ V_2 ] = F_27 ( V_2 ) &
~ V_22 ;
F_32 ( V_2 , V_6 -> V_17 [ V_2 ] ) ;
F_46 ( V_21 ) ;
}
static int F_47 ( struct V_23 * V_24 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_25 = F_48 ( & V_8 -> V_26 ) ;
T_1 V_27 = V_8 -> V_28 ;
int V_29 = 0 ;
if ( F_49 ( ( V_25 + V_27 ) & ( 1ULL << 63 ) ) ) {
V_25 = V_27 ;
F_50 ( & V_8 -> V_26 , V_25 ) ;
V_8 -> V_30 = V_27 ;
V_29 = 1 ;
} else if ( F_49 ( ( V_25 + V_27 ) <= V_27 ) ) {
V_25 += V_27 ;
F_50 ( & V_8 -> V_26 , V_25 ) ;
V_8 -> V_30 = V_27 ;
V_29 = 1 ;
}
if ( V_25 > V_12 . V_31 ) {
V_25 = V_12 . V_31 ;
F_50 ( & V_8 -> V_26 , V_25 ) ;
}
F_50 ( & V_8 -> V_32 , V_12 . V_33 - V_25 ) ;
V_12 . V_34 ( V_2 , V_12 . V_33 - V_25 ) ;
F_51 ( V_24 ) ;
return V_29 ;
}
static void F_52 ( struct V_23 * V_24 ,
struct V_7 * V_8 ,
int V_2 )
{
T_1 V_35 , V_36 ;
T_1 V_37 ;
V_38:
V_35 = F_48 ( & V_8 -> V_32 ) ;
V_36 = V_12 . V_39 ( V_2 ) ;
if ( F_53 ( & V_8 -> V_32 , V_35 ,
V_36 ) != V_35 )
goto V_38;
V_37 = V_36 - V_35 ;
F_54 ( V_37 , & V_24 -> V_40 ) ;
F_55 ( V_37 , & V_8 -> V_26 ) ;
}
static void F_56 ( struct V_23 * V_24 , int V_21 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_21 & V_42 )
F_57 ( ! ( V_8 -> V_43 & V_44 ) ) ;
V_8 -> V_43 = 0 ;
F_47 ( V_24 , V_8 , V_8 -> V_2 ) ;
F_40 ( V_8 , V_8 -> V_2 ) ;
}
static void F_58 ( struct V_23 * V_24 , int V_21 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( ! ( V_8 -> V_43 & V_45 ) ) {
F_44 ( V_8 -> V_2 ) ;
F_59 () ;
F_52 ( V_24 , V_8 , V_8 -> V_2 ) ;
V_8 -> V_43 |= V_45 | V_44 ;
}
}
static int F_60 ( struct V_23 * V_24 , int V_21 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_7 * V_8 = & V_24 -> V_41 ;
int V_2 ;
int V_46 = 0 ;
F_61 ( V_24 -> V_47 ) ;
V_2 = F_37 ( V_6 , V_8 ) ;
if ( V_2 < 0 ) {
V_46 = V_2 ;
goto V_48;
}
V_24 -> V_41 . V_2 = V_2 ;
F_44 ( V_2 ) ;
V_6 -> V_49 [ V_2 ] = V_24 ;
V_8 -> V_43 = V_45 | V_44 ;
if ( V_21 & V_50 )
F_56 ( V_24 , V_42 ) ;
F_51 ( V_24 ) ;
V_48:
F_62 ( V_24 -> V_47 ) ;
return V_46 ;
}
static void F_63 ( struct V_23 * V_24 , int V_21 )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_7 * V_8 = & V_24 -> V_41 ;
int V_2 = V_8 -> V_2 ;
F_42 ( V_2 < 0 || V_2 >= V_12 . V_13 ) ;
F_58 ( V_24 , V_51 ) ;
V_6 -> V_49 [ V_2 ] = NULL ;
F_64 ( V_2 , V_6 -> V_14 ) ;
F_51 ( V_24 ) ;
}
static void F_65 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_8 -> V_2 < 0 )
return;
F_52 ( V_24 , V_8 , V_8 -> V_2 ) ;
}
static void F_66 ( struct V_47 * V_47 )
{
#ifdef F_67
F_68 ( & V_52 ) ;
#endif
F_69 () ;
}
static void F_70 ( struct V_47 * V_47 )
{
F_71 () ;
#ifdef F_67
F_72 ( & V_52 ) ;
#endif
}
static int F_73 ( void )
{
int V_46 ;
if ( V_12 . V_53 >= 0 ) {
V_46 = F_74 ( V_12 . V_53 , V_54 ,
V_55 | V_56 ,
L_2 , NULL ) ;
if ( V_46 ) {
F_75 ( L_3
L_4 , V_12 . V_53 ) ;
}
} else if ( V_57 < 0 ) {
V_58 = V_59 ;
V_59 = V_60 ;
V_46 = 0 ;
} else {
F_75 ( L_5
L_6 ) ;
V_46 = - V_61 ;
}
return V_46 ;
}
static void F_76 ( void )
{
if ( V_12 . V_53 >= 0 )
F_77 ( V_12 . V_53 , NULL ) ;
else if ( V_57 < 0 )
V_59 = V_58 ;
}
static void F_78 ( struct V_23 * V_24 )
{
if ( F_79 ( & V_62 ,
& V_63 ) ) {
F_80 ( V_64 ,
( void * ) ( long ) V_12 . V_13 , 1 ) ;
F_76 () ;
F_81 ( & V_63 ) ;
}
}
static int F_82 ( struct V_23 * V_24 )
{
int V_46 = 0 ;
if ( F_83 ( V_24 ) )
return - V_65 ;
switch ( V_24 -> V_66 . type ) {
case V_67 :
case V_68 :
case V_69 :
break;
default:
return - V_61 ;
}
if ( V_24 -> V_70 >= V_71 ||
( V_24 -> V_70 >= 0 && ! F_84 ( V_24 -> V_70 ) ) )
return - V_72 ;
if ( ! F_85 ( & V_62 ) ) {
F_86 ( & V_63 ) ;
if ( F_87 ( & V_62 ) == 0 )
V_46 = F_73 () ;
if ( ! V_46 )
F_88 ( & V_62 ) ;
F_81 ( & V_63 ) ;
}
if ( V_46 )
return V_46 ;
return F_89 ( V_24 ) ;
}
static unsigned int F_90 ( const struct V_73 * V_74 )
{
#ifdef F_67
return ( ( unsigned int ) V_74 -> V_75 << 24 ) |
( V_74 -> V_10 & 0xffff00 ) |
( V_74 -> V_76 & 0xff ) ;
#else
return ( V_74 -> V_10 & 0xffff00 ) |
( V_74 -> V_76 & 0xff ) ;
#endif
}
static const struct V_73 * F_91 ( int V_2 )
{
const struct V_73 * V_74 ;
V_74 = ( ( * V_12 . V_77 ) [ V_2 ] . V_76 ==
V_78 ? F_92 ( - V_65 ) :
& ( * V_12 . V_77 ) [ V_2 ] ) ;
return V_74 ;
}
static const struct V_73 * F_93 ( T_1 V_79 )
{
unsigned int V_80 , V_81 , V_82 ;
const struct V_73 * V_74 ;
V_80 = ( V_79 >> 0 ) & 0xff ;
if ( V_80 >= V_83 )
return F_92 ( - V_84 ) ;
V_81 = ( V_79 >> 8 ) & 0xff ;
if ( V_81 >= V_85 )
return F_92 ( - V_84 ) ;
V_82 = ( V_79 >> 16 ) & 0xff ;
if ( V_82 >= V_86 )
return F_92 ( - V_84 ) ;
V_74 = & ( ( * V_12 . V_87 )
[ V_80 ]
[ V_81 ]
[ V_82 ] ) ;
if ( V_74 -> V_76 == V_78 )
return F_92 ( - V_65 ) ;
return V_74 ;
}
static int F_94 ( struct V_23 * V_24 )
{
struct V_23 * V_88 , * V_89 = V_24 -> V_90 ;
struct V_5 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
if ( F_37 ( & V_91 , & V_89 -> V_41 ) < 0 )
return - V_84 ;
F_95 (sibling, &leader->sibling_list, group_entry) {
if ( F_37 ( & V_91 , & V_88 -> V_41 ) < 0 )
return - V_84 ;
}
if ( F_37 ( & V_91 , & V_24 -> V_41 ) < 0 )
return - V_84 ;
return 0 ;
}
static void F_96 ( struct V_5 * V_6 ,
int V_2 , struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_23 * V_24 = V_6 -> V_49 [ V_2 ] ;
struct V_7 * V_8 = & V_24 -> V_41 ;
F_52 ( V_24 , V_8 , V_2 ) ;
V_93 -> V_27 = V_24 -> V_41 . V_30 ;
if ( ! F_47 ( V_24 , V_8 , V_2 ) )
return;
if ( F_97 ( V_24 , V_93 , V_95 ) )
F_44 ( V_2 ) ;
}
static int F_98 ( void )
{
if ( ! ( F_99 () & V_96 ) )
return 0 ;
if ( ! ( F_28 () & V_97 ) )
return 1 ;
if ( ! ( F_29 () & V_97 ) )
return 2 ;
if ( ! ( F_30 () & V_97 ) )
return 3 ;
return 4 ;
}
static int F_100 ( void )
{
int V_1 ;
switch ( F_101 () ) {
case V_98 :
V_1 = 2 ;
break;
case V_99 :
case V_100 :
V_1 = 4 ;
break;
default:
V_1 = F_98 () ;
}
return V_1 ;
}
static void V_64 ( void * V_101 )
{
int V_1 = ( int ) ( long ) V_101 ;
switch ( V_1 ) {
case 4 :
F_32 ( 3 , 0 ) ;
V_12 . V_34 ( 3 , 0 ) ;
case 3 :
F_32 ( 2 , 0 ) ;
V_12 . V_34 ( 2 , 0 ) ;
case 2 :
F_32 ( 1 , 0 ) ;
V_12 . V_34 ( 1 , 0 ) ;
case 1 :
F_32 ( 0 , 0 ) ;
V_12 . V_34 ( 0 , 0 ) ;
}
}
static void F_102 ( struct V_23 * V_24 ,
const struct V_73 * V_74 )
{
struct V_7 * V_8 = & V_24 -> V_41 ;
if ( V_24 -> V_70 >= 0 ) {
if ( V_74 -> V_75 > V_102 ) {
V_8 -> V_18 |= V_103 ;
} else {
V_8 -> V_18 |= F_103 ( V_24 -> V_70 ) ;
V_8 -> V_18 |= V_104 ;
}
} else
V_8 -> V_18 |= V_103 ;
}
static void F_102 ( struct V_23 * V_24 ,
const struct V_73 * V_74 )
{
}
static int F_89 ( struct V_23 * V_24 )
{
struct V_105 * V_66 = & V_24 -> V_66 ;
struct V_7 * V_8 = & V_24 -> V_41 ;
const struct V_73 * V_74 ;
int V_46 ;
if ( V_68 == V_24 -> V_66 . type ) {
if ( V_24 -> V_66 . V_79 >= V_106 )
return - V_84 ;
V_74 = F_91 ( V_24 -> V_66 . V_79 ) ;
} else if ( V_69 == V_24 -> V_66 . type ) {
V_74 = F_93 ( V_24 -> V_66 . V_79 ) ;
} else if ( V_67 == V_24 -> V_66 . type ) {
F_86 ( & V_107 ) ;
V_74 = V_12 . V_108 ( V_24 -> V_66 . V_79 ) ;
} else {
return - V_65 ;
}
if ( F_104 ( V_74 ) ) {
if ( V_67 == V_24 -> V_66 . type )
F_81 ( & V_107 ) ;
return F_105 ( V_74 ) ;
}
V_8 -> V_18 = V_20 ;
if ( F_2 () > 1 )
F_102 ( V_24 , V_74 ) ;
V_8 -> V_11 = F_90 ( V_74 ) ;
if ( V_67 == V_24 -> V_66 . type )
F_81 ( & V_107 ) ;
if ( ! V_66 -> V_109 )
V_8 -> V_18 |= V_110 ;
if ( ! V_66 -> V_111 ) {
V_8 -> V_18 |= V_112 ;
V_8 -> V_18 |= V_113 ;
}
if ( ! V_66 -> V_114 )
V_8 -> V_18 |= V_115 ;
V_8 -> V_18 &= V_19 ;
V_8 -> V_2 = - 1 ;
V_8 -> V_79 = 0 ;
if ( ! V_8 -> V_28 ) {
V_8 -> V_28 = V_12 . V_31 ;
V_8 -> V_30 = V_8 -> V_28 ;
F_50 ( & V_8 -> V_26 , V_8 -> V_28 ) ;
}
V_46 = 0 ;
if ( V_24 -> V_90 != V_24 )
V_46 = F_94 ( V_24 ) ;
V_24 -> V_116 = F_78 ;
if ( V_46 )
V_24 -> V_116 ( V_24 ) ;
return V_46 ;
}
static void F_71 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
int V_117 = V_12 . V_13 ;
unsigned long V_21 ;
F_45 ( V_21 ) ;
do {
V_117 -- ;
V_6 -> V_17 [ V_117 ] = F_27 ( V_117 ) ;
F_32 ( V_117 , V_6 -> V_17 [ V_117 ] &
~ V_22 ) ;
} while ( V_117 > 0 );
F_46 ( V_21 ) ;
}
static void F_69 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
int V_117 = V_12 . V_13 ;
do {
V_117 -- ;
F_32 ( V_117 , V_6 -> V_17 [ V_117 ] ) ;
} while ( V_117 > 0 );
}
static int V_60 ( void )
{
struct V_5 * V_6 = & F_41 ( V_5 ) ;
struct V_92 V_93 ;
unsigned int V_1 = V_12 . V_13 ;
T_1 V_118 ;
int V_119 = V_120 ;
struct V_94 * V_95 ;
if ( V_121 && ! ( F_106 () & ( 1 << 26 ) ) )
return V_119 ;
F_71 () ;
#ifdef F_67
F_107 ( & V_52 ) ;
#endif
V_95 = F_108 () ;
F_109 ( & V_93 , 0 , 0 ) ;
switch ( V_1 ) {
#define F_110 ( T_2 ) \
case n + 1: \
if (test_bit(n, cpuc->used_mask)) { \
counter = mipspmu.read_counter(n); \
if (counter & mipspmu.overflow) { \
handle_associated_event(cpuc, n, &data, regs); \
handled = IRQ_HANDLED; \
} \
}
F_110 ( 3 )
F_110 ( 2 )
F_110 ( 1 )
F_110 ( 0 )
}
if ( V_119 == V_122 )
F_111 () ;
#ifdef F_67
F_112 ( & V_52 ) ;
#endif
F_69 () ;
return V_119 ;
}
static T_3 V_54 ( int V_53 , void * V_123 )
{
return V_60 () ;
}
static const struct V_73 * F_113 ( T_1 V_79 )
{
unsigned int V_124 = V_79 & 0xff ;
unsigned int V_125 = V_124 & 0x7f ;
V_126 . V_76 = V_125 ;
switch ( F_101 () ) {
case V_127 :
if ( F_114 ( V_125 ) )
V_126 . V_10 = V_128 | V_129 ;
else
V_126 . V_10 =
V_124 > 127 ? V_129 : V_128 ;
#ifdef F_67
V_126 . V_75 = V_130 ;
#endif
break;
case V_131 :
if ( F_115 ( V_125 ) )
V_126 . V_10 = V_128 | V_129 ;
else
V_126 . V_10 =
V_124 > 127 ? V_129 : V_128 ;
#ifdef F_67
if ( F_116 ( V_124 , V_125 ) )
V_126 . V_75 = V_130 ;
else if ( F_49 ( F_117 ( V_124 ) ) )
V_126 . V_75 = V_102 ;
else
V_126 . V_75 = V_132 ;
#endif
break;
case V_133 :
if ( F_118 ( V_125 ) )
V_126 . V_10 = V_128 | V_129 ;
else
V_126 . V_10 =
V_124 > 127 ? V_129 : V_128 ;
#ifdef F_67
V_126 . V_75 = V_130 ;
#endif
break;
case V_134 :
if ( F_119 ( V_125 ) )
V_126 . V_10 = V_128 | V_129 ;
else
V_126 . V_10 =
V_124 > 127 ? V_129 : V_128 ;
#ifdef F_67
if ( F_120 ( V_124 , V_125 ) )
V_126 . V_75 = V_130 ;
else if ( F_49 ( F_121 ( V_124 ) ) )
V_126 . V_75 = V_102 ;
else
V_126 . V_75 = V_132 ;
#endif
break;
}
return & V_126 ;
}
static const struct V_73 * F_122 ( T_1 V_79 )
{
unsigned int V_124 = V_79 & 0xff ;
unsigned int V_125 = V_124 & 0x7f ;
V_126 . V_10 = V_135 ;
V_126 . V_76 = V_125 ;
if ( F_101 () == V_136 ) {
if ( V_125 > 0x42 )
return F_92 ( - V_65 ) ;
} else {
if ( V_125 > 0x3a )
return F_92 ( - V_65 ) ;
}
switch ( V_125 ) {
case 0x00 :
case 0x0f :
case 0x1e :
case 0x1f :
case 0x2f :
case 0x34 :
case 0x3b ... 0x3f :
return F_92 ( - V_65 ) ;
default:
break;
}
return & V_126 ;
}
static int T_4
F_123 ( void )
{
int V_1 , V_53 ;
int V_137 ;
F_124 ( L_7 ) ;
V_1 = F_100 () ;
if ( V_1 == 0 ) {
F_125 ( L_8 ) ;
return - V_72 ;
}
#ifdef F_67
V_138 = F_126 () & ( 1 << 19 ) ;
if ( ! V_138 )
V_1 = F_3 ( V_1 ) ;
#endif
#ifdef F_127
if ( V_139 ) {
V_53 = F_127 + V_140 ;
} else {
#endif
if ( ( V_57 >= 0 ) &&
( V_141 != V_57 ) )
V_53 = V_142 + V_57 ;
else
V_53 = - 1 ;
#ifdef F_127
}
#endif
V_12 . V_108 = F_113 ;
switch ( F_101 () ) {
case V_127 :
V_12 . V_143 = L_9 ;
V_12 . V_77 = & V_144 ;
V_12 . V_87 = & V_145 ;
break;
case V_131 :
V_12 . V_143 = L_10 ;
V_12 . V_77 = & V_144 ;
V_12 . V_87 = & V_145 ;
break;
case V_133 :
V_12 . V_143 = L_11 ;
V_12 . V_77 = & V_146 ;
V_12 . V_87 = & V_147 ;
break;
case V_134 :
V_12 . V_143 = L_12 ;
V_12 . V_77 = & V_144 ;
V_12 . V_87 = & V_145 ;
break;
case V_148 :
case V_149 :
case V_136 :
V_12 . V_143 = L_13 ;
V_12 . V_77 = & V_150 ;
V_12 . V_87 = & V_151 ;
V_12 . V_108 = F_122 ;
break;
default:
F_125 ( L_14
L_15 ) ;
return - V_72 ;
}
V_12 . V_13 = V_1 ;
V_12 . V_53 = V_53 ;
if ( F_28 () & V_152 ) {
V_12 . V_31 = ( 1ULL << 63 ) - 1 ;
V_12 . V_153 = ( 1ULL << 63 ) - 1 ;
V_12 . V_33 = 1ULL << 63 ;
V_12 . V_39 = F_12 ;
V_12 . V_34 = F_22 ;
V_137 = 64 ;
} else {
V_12 . V_31 = ( 1ULL << 31 ) - 1 ;
V_12 . V_153 = ( 1ULL << 31 ) - 1 ;
V_12 . V_33 = 1ULL << 31 ;
V_12 . V_39 = F_6 ;
V_12 . V_34 = F_17 ;
V_137 = 32 ;
}
F_80 ( V_64 , ( void * ) ( long ) V_1 , 1 ) ;
F_125 ( L_16
L_17 , V_12 . V_143 , V_1 , V_137 , V_53 ,
V_53 < 0 ? L_18 : L_19 ) ;
F_128 ( & V_47 , L_20 , V_67 ) ;
return 0 ;
}
