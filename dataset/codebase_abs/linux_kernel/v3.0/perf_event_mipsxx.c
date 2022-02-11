static inline unsigned int F_1 ( void )
{
if ( F_2 () > 1 )
return 1 ;
return 0 ;
}
static inline unsigned int F_1 ( void )
{
return 0 ;
}
static inline unsigned int
F_3 ( unsigned int V_1 )
{
return V_1 >> F_1 () ;
}
static inline unsigned int
F_4 ( unsigned int V_1 )
{
return V_1 << F_1 () ;
}
static inline int F_5 ( void )
{
if ( ! ( F_6 () & V_2 ) )
return 0 ;
if ( ! ( F_7 () & V_3 ) )
return 1 ;
if ( ! ( F_8 () & V_3 ) )
return 2 ;
if ( ! ( F_9 () & V_3 ) )
return 3 ;
return 4 ;
}
static inline int F_10 ( void )
{
int V_1 ;
switch ( F_11 () ) {
case V_4 :
V_1 = 2 ;
break;
case V_5 :
case V_6 :
V_1 = 4 ;
break;
default:
V_1 = F_5 () ;
}
return V_1 ;
}
static void F_12 ( void * V_7 )
{
int V_1 = ( int ) ( long ) V_7 ;
switch ( V_1 ) {
case 4 :
F_13 ( 0 ) ;
F_14 ( 0 ) ;
case 3 :
F_15 ( 0 ) ;
F_16 ( 0 ) ;
case 2 :
F_17 ( 0 ) ;
F_18 ( 0 ) ;
case 1 :
F_19 ( 0 ) ;
F_20 ( 0 ) ;
}
}
static inline T_1
F_21 ( unsigned int V_8 )
{
switch ( V_8 ) {
case 0 :
return F_22 () ;
case 1 :
return F_23 () ;
case 2 :
return F_24 () ;
case 3 :
return F_25 () ;
default:
F_26 ( 1 , L_1 , V_8 ) ;
return 0 ;
}
}
static inline void
F_27 ( unsigned int V_8 , T_1 V_9 )
{
switch ( V_8 ) {
case 0 :
F_20 ( V_9 ) ;
return;
case 1 :
F_18 ( V_9 ) ;
return;
case 2 :
F_16 ( V_9 ) ;
return;
case 3 :
F_14 ( V_9 ) ;
return;
}
}
static inline unsigned int
F_28 ( unsigned int V_8 )
{
switch ( V_8 ) {
case 0 :
return F_29 () ;
case 1 :
return F_30 () ;
case 2 :
return F_31 () ;
case 3 :
return F_32 () ;
default:
F_26 ( 1 , L_1 , V_8 ) ;
return 0 ;
}
}
static inline void
F_33 ( unsigned int V_8 , unsigned int V_9 )
{
switch ( V_8 ) {
case 0 :
F_19 ( V_9 ) ;
return;
case 1 :
F_17 ( V_9 ) ;
return;
case 2 :
F_15 ( V_9 ) ;
return;
case 3 :
F_13 ( V_9 ) ;
return;
}
}
static void
F_34 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_11 -> V_16 ;
if ( V_11 -> V_17 >= 0 ) {
if ( V_13 -> V_18 > V_19 ) {
V_15 -> V_20 |= V_21 ;
} else {
V_15 -> V_20 |= F_35 ( V_11 -> V_17 ) ;
V_15 -> V_20 |= V_22 ;
}
} else
V_15 -> V_20 |= V_21 ;
}
static void
F_34 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = & V_11 -> V_24 ;
struct V_14 * V_15 = & V_11 -> V_16 ;
const struct V_12 * V_13 ;
int V_25 ;
if ( V_26 == V_11 -> V_24 . type ) {
if ( V_11 -> V_24 . V_27 >= V_28 )
return - V_29 ;
V_13 = F_37 ( V_11 -> V_24 . V_27 ) ;
} else if ( V_30 == V_11 -> V_24 . type ) {
V_13 = F_38 ( V_11 -> V_24 . V_27 ) ;
} else if ( V_31 == V_11 -> V_24 . type ) {
F_39 ( & V_32 ) ;
V_13 = V_33 -> V_34 ( V_11 -> V_24 . V_27 ) ;
} else {
return - V_35 ;
}
if ( F_40 ( V_13 ) ) {
if ( V_31 == V_11 -> V_24 . type )
F_41 ( & V_32 ) ;
return F_42 ( V_13 ) ;
}
V_15 -> V_20 = V_36 ;
if ( F_2 () > 1 )
F_34 ( V_11 , V_13 ) ;
V_15 -> V_37 = F_43 ( V_13 ) ;
if ( V_31 == V_11 -> V_24 . type )
F_41 ( & V_32 ) ;
if ( ! V_24 -> V_38 )
V_15 -> V_20 |= V_39 ;
if ( ! V_24 -> V_40 ) {
V_15 -> V_20 |= V_41 ;
V_15 -> V_20 |= V_42 ;
}
if ( ! V_24 -> V_43 )
V_15 -> V_20 |= V_44 ;
V_15 -> V_20 &= V_45 ;
V_15 -> V_8 = - 1 ;
V_15 -> V_27 = 0 ;
if ( ! V_15 -> V_46 ) {
V_15 -> V_46 = V_47 ;
V_15 -> V_48 = V_15 -> V_46 ;
F_44 ( & V_15 -> V_49 , V_15 -> V_46 ) ;
}
V_25 = 0 ;
if ( V_11 -> V_50 != V_11 ) {
V_25 = F_45 ( V_11 ) ;
if ( V_25 )
return - V_29 ;
}
V_11 -> V_51 = V_52 ;
return V_25 ;
}
static void F_46 ( void )
{
struct V_53 * V_54 = & F_47 ( V_53 ) ;
int V_1 = V_33 -> V_55 ;
unsigned long V_56 ;
F_48 ( V_56 ) ;
switch ( V_1 ) {
case 4 :
V_54 -> V_57 [ 3 ] = F_32 () ;
F_13 ( V_54 -> V_57 [ 3 ] &
~ V_58 ) ;
case 3 :
V_54 -> V_57 [ 2 ] = F_31 () ;
F_15 ( V_54 -> V_57 [ 2 ] &
~ V_58 ) ;
case 2 :
V_54 -> V_57 [ 1 ] = F_30 () ;
F_17 ( V_54 -> V_57 [ 1 ] &
~ V_58 ) ;
case 1 :
V_54 -> V_57 [ 0 ] = F_29 () ;
F_19 ( V_54 -> V_57 [ 0 ] &
~ V_58 ) ;
}
F_49 ( V_56 ) ;
}
static void F_50 ( void )
{
struct V_53 * V_54 = & F_47 ( V_53 ) ;
int V_1 = V_33 -> V_55 ;
unsigned long V_56 ;
F_48 ( V_56 ) ;
switch ( V_1 ) {
case 4 :
F_13 ( V_54 -> V_57 [ 3 ] ) ;
case 3 :
F_15 ( V_54 -> V_57 [ 2 ] ) ;
case 2 :
F_17 ( V_54 -> V_57 [ 1 ] ) ;
case 1 :
F_19 ( V_54 -> V_57 [ 0 ] ) ;
}
F_49 ( V_56 ) ;
}
static int F_51 ( void )
{
struct V_53 * V_54 = & F_47 ( V_53 ) ;
struct V_59 V_60 ;
unsigned int V_1 = V_33 -> V_55 ;
unsigned int V_61 ;
int V_62 = V_63 ;
struct V_64 * V_65 ;
if ( V_66 && ! ( F_52 () & ( 1 << 26 ) ) )
return V_62 ;
F_46 () ;
#ifdef F_53
F_54 ( & V_67 ) ;
#endif
V_65 = F_55 () ;
F_56 ( & V_60 , 0 ) ;
switch ( V_1 ) {
#define F_57 ( T_2 ) \
case n + 1: \
if (test_bit(n, cpuc->used_mask)) { \
counter = r_c0_perfcntr ## n(); \
if (counter & M_COUNTER_OVERFLOW) { \
w_c0_perfcntr ## n(counter & \
VALID_COUNT); \
if (test_and_change_bit(n, cpuc->msbs)) \
handle_associated_event(cpuc, \
n, &data, regs); \
handled = IRQ_HANDLED; \
} \
}
F_57 ( 3 )
F_57 ( 2 )
F_57 ( 1 )
F_57 ( 0 )
}
if ( V_62 == V_68 )
F_58 () ;
#ifdef F_53
F_59 ( & V_67 ) ;
#endif
F_50 () ;
return V_62 ;
}
static T_3
F_60 ( int V_69 , void * V_70 )
{
return F_51 () ;
}
static void F_61 ( void )
{
#ifdef F_53
F_62 ( & V_67 ) ;
#endif
F_50 () ;
}
static void F_63 ( void )
{
F_46 () ;
#ifdef F_53
F_64 ( & V_67 ) ;
#endif
}
static int
F_65 ( struct V_53 * V_54 ,
struct V_14 * V_15 )
{
int V_71 ;
unsigned long V_72 = ( V_15 -> V_37 >> 8 ) & 0xffff ;
for ( V_71 = V_33 -> V_55 - 1 ; V_71 >= 0 ; V_71 -- ) {
if ( F_66 ( V_71 , & V_72 ) &&
! F_67 ( V_71 , V_54 -> V_73 ) )
return V_71 ;
}
return - V_74 ;
}
static void
F_68 ( struct V_14 * V_75 , int V_8 )
{
struct V_53 * V_54 = & F_47 ( V_53 ) ;
unsigned long V_56 ;
F_69 ( V_8 < 0 || V_8 >= V_33 -> V_55 ) ;
F_48 ( V_56 ) ;
V_54 -> V_57 [ V_8 ] = F_70 ( V_75 -> V_37 & 0xff ) |
( V_75 -> V_20 & V_45 ) |
V_36 ;
F_49 ( V_56 ) ;
}
static void
F_71 ( int V_8 )
{
struct V_53 * V_54 = & F_47 ( V_53 ) ;
unsigned long V_56 ;
F_69 ( V_8 < 0 || V_8 >= V_33 -> V_55 ) ;
F_48 ( V_56 ) ;
V_54 -> V_57 [ V_8 ] = F_28 ( V_8 ) &
~ V_58 ;
F_33 ( V_8 , V_54 -> V_57 [ V_8 ] ) ;
F_49 ( V_56 ) ;
}
static const struct V_12 *
F_72 ( T_1 V_27 )
{
unsigned int V_76 = V_27 & 0xff ;
unsigned int V_77 = V_76 & 0x7f ;
switch ( F_11 () ) {
case V_78 :
if ( F_73 ( V_76 , V_77 ) )
return F_74 ( - V_35 ) ;
V_79 . V_80 = V_77 ;
if ( F_75 ( V_77 ) )
V_79 . V_72 = V_81 | V_82 ;
else
V_79 . V_72 =
V_76 > 127 ? V_82 : V_81 ;
#ifdef F_53
V_79 . V_18 = V_83 ;
#endif
break;
case V_84 :
if ( F_76 ( V_76 , V_77 ) )
return F_74 ( - V_35 ) ;
V_79 . V_80 = V_77 ;
if ( F_77 ( V_77 ) )
V_79 . V_72 = V_81 | V_82 ;
else
V_79 . V_72 =
V_76 > 127 ? V_82 : V_81 ;
#ifdef F_53
if ( F_78 ( V_76 , V_77 ) )
V_79 . V_18 = V_83 ;
else if ( F_79 ( F_80 ( V_76 ) ) )
V_79 . V_18 = V_19 ;
else
V_79 . V_18 = V_85 ;
#endif
break;
case V_86 :
if ( F_81 ( V_76 , V_77 ) )
return F_74 ( - V_35 ) ;
V_79 . V_80 = V_77 ;
if ( F_82 ( V_77 ) )
V_79 . V_72 = V_81 | V_82 ;
else
V_79 . V_72 =
V_76 > 127 ? V_82 : V_81 ;
#ifdef F_53
V_79 . V_18 = V_83 ;
#endif
break;
case V_87 :
if ( F_83 ( V_76 , V_77 ) )
return F_74 ( - V_35 ) ;
V_79 . V_80 = V_77 ;
if ( F_84 ( V_77 ) )
V_79 . V_72 = V_81 | V_82 ;
else
V_79 . V_72 =
V_76 > 127 ? V_82 : V_81 ;
#ifdef F_53
if ( F_85 ( V_76 , V_77 ) )
V_79 . V_18 = V_83 ;
else if ( F_79 ( F_86 ( V_76 ) ) )
V_79 . V_18 = V_19 ;
else
V_79 . V_18 = V_85 ;
#endif
break;
}
return & V_79 ;
}
static int T_4
F_87 ( void )
{
int V_1 , V_69 ;
F_88 ( L_2 ) ;
V_1 = F_10 () ;
if ( V_1 == 0 ) {
F_89 ( L_3 ) ;
return - V_88 ;
}
#ifdef F_53
V_89 = F_90 () & ( 1 << 19 ) ;
if ( ! V_89 )
V_1 = F_3 ( V_1 ) ;
#endif
#ifdef F_91
if ( V_90 ) {
V_69 = F_91 + V_91 ;
} else {
#endif
if ( V_92 >= 0 )
V_69 = V_93 + V_92 ;
else
V_69 = - 1 ;
#ifdef F_91
}
#endif
F_92 ( F_12 , ( void * ) ( long ) V_1 , 1 ) ;
switch ( F_11 () ) {
case V_78 :
V_94 . V_95 = L_4 ;
V_94 . V_55 = V_1 ;
V_94 . V_69 = V_69 ;
V_33 = & V_94 ;
break;
case V_84 :
V_94 . V_95 = L_5 ;
V_94 . V_55 = V_1 ;
V_94 . V_69 = V_69 ;
V_33 = & V_94 ;
break;
case V_86 :
V_96 . V_95 = L_6 ;
V_96 . V_55 = V_1 ;
V_96 . V_69 = V_69 ;
V_33 = & V_96 ;
break;
case V_87 :
V_94 . V_95 = L_7 ;
V_94 . V_55 = V_1 ;
V_94 . V_69 = V_69 ;
V_33 = & V_94 ;
break;
default:
F_89 ( L_8
L_9 ) ;
return - V_88 ;
}
if ( V_33 )
F_89 ( L_10
L_11 , V_33 -> V_95 , V_1 , V_69 ,
V_69 < 0 ? L_12 : L_13 ) ;
F_93 ( & V_97 , L_14 , V_31 ) ;
return 0 ;
}
