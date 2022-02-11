int T_1 F_1 ( struct V_1 * V_2 )
{
if ( ( unsigned long ) V_2 -> V_3 & 0x3UL )
return - V_4 ;
V_2 -> V_5 . V_6 [ 0 ] = * V_2 -> V_3 ;
F_2 ( & V_2 -> V_5 . V_6 [ 0 ] ) ;
V_2 -> V_5 . V_6 [ 1 ] = V_7 ;
F_2 ( & V_2 -> V_5 . V_6 [ 1 ] ) ;
V_2 -> V_8 = * V_2 -> V_3 ;
return 0 ;
}
void T_1 F_3 ( struct V_1 * V_2 )
{
* V_2 -> V_3 = V_9 ;
F_2 ( V_2 -> V_3 ) ;
}
void T_1 F_4 ( struct V_1 * V_2 )
{
* V_2 -> V_3 = V_2 -> V_8 ;
F_2 ( V_2 -> V_3 ) ;
}
static void T_1 F_5 ( struct V_10 * V_11 )
{
V_11 -> V_12 . V_13 = F_6 () ;
V_11 -> V_12 . V_14 = V_11 -> V_15 ;
V_11 -> V_12 . V_16 = V_11 -> V_17 ;
V_11 -> V_12 . V_18 = V_11 -> V_19 ;
}
static void T_1 F_7 ( struct V_10 * V_11 )
{
F_8 ( V_20 , V_11 -> V_12 . V_13 ) ;
V_11 -> V_15 = V_11 -> V_12 . V_14 ;
V_11 -> V_17 = V_11 -> V_12 . V_16 ;
V_11 -> V_19 = V_11 -> V_12 . V_18 ;
}
static void T_1 F_9 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_10 * V_11 )
{
F_8 ( V_20 , V_2 ) ;
V_11 -> V_17 = V_22 -> V_23 ;
V_11 -> V_19 = ( V_22 -> V_24 & V_25 ) ;
}
static void T_1 F_10 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_10 * V_11 )
{
V_22 -> V_24 |= V_25 ;
if ( V_2 -> V_8 == V_9 ) {
V_22 -> V_26 = ( unsigned long ) V_2 -> V_3 ;
V_22 -> V_23 = V_11 -> V_17 ;
} else {
V_22 -> V_26 = ( unsigned long ) & V_2 -> V_5 . V_6 [ 0 ] ;
V_22 -> V_23 = ( unsigned long ) & V_2 -> V_5 . V_6 [ 1 ] ;
}
}
static int T_1 F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
void * V_3 = ( void * ) V_22 -> V_26 ;
int V_27 = 0 ;
struct V_10 * V_11 ;
F_12 () ;
V_11 = F_13 () ;
if ( F_6 () ) {
V_2 = F_14 ( V_3 ) ;
if ( V_2 ) {
if ( V_11 -> V_15 == V_28 ) {
V_22 -> V_24 = ( ( V_22 -> V_24 & ~ V_25 ) |
V_11 -> V_19 ) ;
goto V_29;
}
F_5 ( V_11 ) ;
F_9 ( V_2 , V_22 , V_11 ) ;
F_15 ( V_2 ) ;
V_11 -> V_15 = V_30 ;
F_10 ( V_2 , V_22 , V_11 ) ;
return 1 ;
} else {
if ( * ( V_31 * ) V_3 != V_9 ) {
V_27 = 1 ;
goto V_29;
}
V_2 = F_16 ( V_20 ) ;
if ( V_2 -> V_32 && V_2 -> V_32 ( V_2 , V_22 ) )
goto V_33;
}
goto V_29;
}
V_2 = F_14 ( V_3 ) ;
if ( ! V_2 ) {
if ( * ( V_31 * ) V_3 != V_9 ) {
V_27 = 1 ;
}
goto V_29;
}
F_9 ( V_2 , V_22 , V_11 ) ;
V_11 -> V_15 = V_34 ;
if ( V_2 -> V_35 && V_2 -> V_35 ( V_2 , V_22 ) )
return 1 ;
V_33:
F_10 ( V_2 , V_22 , V_11 ) ;
V_11 -> V_15 = V_28 ;
return 1 ;
V_29:
F_17 () ;
return V_27 ;
}
static unsigned long T_1 F_18 ( V_31 V_6 , struct V_1 * V_2 ,
struct V_21 * V_22 )
{
unsigned long V_36 = ( unsigned long ) V_2 -> V_3 ;
if ( V_22 -> V_23 == V_22 -> V_26 + 0x4UL )
return V_36 + 0x8UL ;
if ( ( V_6 & 0xc0000000 ) == 0x40000000 ||
( V_6 & 0xc1c00000 ) == 0x00400000 ||
( V_6 & 0xc1c00000 ) == 0x00800000 ) {
unsigned long V_37 ;
V_37 = ( unsigned long ) & V_2 -> V_5 . V_6 [ 0 ] ;
return ( V_36 + ( V_22 -> V_23 - V_37 ) ) ;
}
return V_22 -> V_23 ;
}
static void T_1 F_19 ( struct V_21 * V_22 , V_31 V_6 ,
unsigned long V_36 )
{
unsigned long * V_38 = NULL ;
if ( ( V_6 & 0xc0000000 ) == 0x40000000 ) {
V_38 = & V_22 -> V_39 [ V_40 ] ;
}
if ( ( V_6 & 0xc1f80000 ) == 0x81c00000 ) {
unsigned long V_41 = ( ( V_6 >> 25 ) & 0x1f ) ;
if ( V_41 <= 15 ) {
V_38 = & V_22 -> V_39 [ V_41 ] ;
} else {
F_20 () ;
V_41 -= 16 ;
V_38 = ( unsigned long * )
( V_22 -> V_39 [ V_42 ] + V_43 ) ;
V_38 += V_41 ;
}
}
if ( V_38 != NULL )
* V_38 = V_36 ;
}
static void T_1 F_21 ( struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_10 * V_11 )
{
V_31 V_6 = V_2 -> V_5 . V_6 [ 0 ] ;
V_22 -> V_23 = F_18 ( V_6 , V_2 , V_22 ) ;
V_22 -> V_26 = V_11 -> V_17 ;
F_19 ( V_22 , V_6 , ( unsigned long ) V_2 -> V_3 ) ;
V_22 -> V_24 = ( ( V_22 -> V_24 & ~ V_25 ) |
V_11 -> V_19 ) ;
}
static int T_1 F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_44 = F_6 () ;
struct V_10 * V_11 = F_13 () ;
if ( ! V_44 )
return 0 ;
if ( ( V_11 -> V_15 != V_30 ) && V_44 -> V_45 ) {
V_11 -> V_15 = V_46 ;
V_44 -> V_45 ( V_44 , V_22 , 0 ) ;
}
F_21 ( V_44 , V_22 , V_11 ) ;
if ( V_11 -> V_15 == V_30 ) {
F_7 ( V_11 ) ;
goto V_47;
}
F_23 () ;
V_47:
F_17 () ;
return 1 ;
}
int T_1 F_24 ( struct V_21 * V_22 , int V_48 )
{
struct V_1 * V_44 = F_6 () ;
struct V_10 * V_11 = F_13 () ;
const struct V_49 * V_50 ;
switch( V_11 -> V_15 ) {
case V_28 :
case V_30 :
V_22 -> V_26 = ( unsigned long ) V_44 -> V_3 ;
V_22 -> V_23 = V_11 -> V_17 ;
V_22 -> V_24 = ( ( V_22 -> V_24 & ~ V_25 ) |
V_11 -> V_19 ) ;
if ( V_11 -> V_15 == V_30 )
F_7 ( V_11 ) ;
else
F_23 () ;
F_17 () ;
break;
case V_34 :
case V_46 :
F_15 ( V_44 ) ;
if ( V_44 -> V_51 && V_44 -> V_51 ( V_44 , V_22 , V_48 ) )
return 1 ;
V_50 = F_25 ( V_22 -> V_26 ) ;
if ( V_50 ) {
V_22 -> V_26 = V_50 -> V_52 ;
V_22 -> V_23 = V_22 -> V_26 + 4 ;
return 1 ;
}
break;
default:
break;
}
return 0 ;
}
int T_1 F_26 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_57 * args = (struct V_57 * ) V_56 ;
int V_27 = V_58 ;
if ( args -> V_22 && F_27 ( args -> V_22 ) )
return V_27 ;
switch ( V_55 ) {
case V_59 :
if ( F_11 ( args -> V_22 ) )
V_27 = V_60 ;
break;
case V_61 :
if ( F_22 ( args -> V_22 ) )
V_27 = V_60 ;
break;
default:
break;
}
return V_27 ;
}
T_2 void T_1 F_28 ( unsigned long V_62 ,
struct V_21 * V_22 )
{
enum V_63 V_64 = F_29 () ;
F_30 ( V_62 != 0x170 && V_62 != 0x171 ) ;
if ( F_27 ( V_22 ) ) {
F_31 () ;
F_32 ( V_22 , V_62 ) ;
goto V_47;
}
if ( F_33 ( ( V_62 == 0x170 ) ? V_59 : V_61 ,
( V_62 == 0x170 ) ? L_1 : L_2 ,
V_22 , 0 , V_62 , V_65 ) != V_60 )
F_32 ( V_22 , V_62 ) ;
V_47:
F_34 ( V_64 ) ;
}
int T_1 F_35 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_66 * V_67 = F_36 ( V_2 , struct V_66 , V_13 ) ;
struct V_10 * V_11 = F_13 () ;
memcpy ( & ( V_11 -> V_68 ) , V_22 , sizeof( * V_22 ) ) ;
V_22 -> V_26 = ( unsigned long ) V_67 -> V_50 ;
V_22 -> V_23 = ( ( unsigned long ) V_67 -> V_50 ) + 0x4UL ;
V_22 -> V_24 |= V_25 ;
return 1 ;
}
void T_1 F_37 ( void )
{
struct V_10 * V_11 = F_13 () ;
register unsigned long T_3 V_69 ( L_3 ) ;
T_3 = V_11 -> V_68 . V_39 [ V_42 ] ;
__asm__ __volatile__("\n"
"1: cmp %%sp, %0\n\t"
"blu,a,pt %%xcc, 1b\n\t"
" restore\n\t"
".globl jprobe_return_trap_instruction\n"
"jprobe_return_trap_instruction:\n\t"
"ta 0x70"
:
: "r" (orig_fp));
}
int T_1 F_38 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
V_31 * V_3 = ( V_31 * ) V_22 -> V_26 ;
struct V_10 * V_11 = F_13 () ;
if ( V_3 == ( V_31 * ) V_70 ) {
memcpy ( V_22 , & ( V_11 -> V_68 ) , sizeof( * V_22 ) ) ;
F_17 () ;
return 1 ;
}
return 0 ;
}
void T_1 F_39 ( struct V_71 * V_72 ,
struct V_21 * V_22 )
{
V_72 -> V_73 = ( V_74 * ) ( V_22 -> V_39 [ V_75 ] + 8 ) ;
V_22 -> V_39 [ V_75 ] =
( ( unsigned long ) V_76 ) - 8 ;
}
static int T_1 F_40 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_71 * V_72 = NULL ;
struct V_77 * V_78 , V_79 ;
struct V_80 * V_81 ;
unsigned long V_82 , V_83 = 0 ;
unsigned long V_84 = ( unsigned long ) & V_76 ;
F_41 ( & V_79 ) ;
F_42 ( V_85 , & V_78 , & V_82 ) ;
F_43 (ri, tmp, head, hlist) {
if ( V_72 -> V_86 != V_85 )
continue;
if ( V_72 -> V_87 && V_72 -> V_87 -> V_88 )
V_72 -> V_87 -> V_88 ( V_72 , V_22 ) ;
V_83 = ( unsigned long ) V_72 -> V_73 ;
F_44 ( V_72 , & V_79 ) ;
if ( V_83 != V_84 )
break;
}
F_45 ( V_72 , V_83 , V_84 ) ;
V_22 -> V_26 = V_83 ;
V_22 -> V_23 = V_83 + 4 ;
F_23 () ;
F_46 ( V_85 , & V_82 ) ;
F_17 () ;
F_43 (ri, tmp, &empty_rp, hlist) {
F_47 ( & V_72 -> V_89 ) ;
F_48 ( V_72 ) ;
}
return 1 ;
}
static void T_4 F_49 ( void )
{
asm volatile(".global kretprobe_trampoline\n"
"kretprobe_trampoline:\n"
"\tnop\n"
"\tnop\n");
}
int T_5 F_50 ( void )
{
return F_51 ( & V_90 ) ;
}
int T_1 F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == ( V_74 * ) & V_76 )
return 1 ;
return 0 ;
}
