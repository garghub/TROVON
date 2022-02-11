static int F_1 ( struct V_1 T_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = 0 ;
V_5 += F_2 ( V_2 , V_4 , F_3 ( struct V_3 , V_6 . V_7 ) ) ;
V_5 += F_2 ( & V_2 -> V_8 , & V_4 -> V_6 . V_7 ,
sizeof( struct V_3 ) -
F_3 ( struct V_3 , V_6 . V_7 ) ) ;
return V_5 ;
}
static int F_4 ( struct V_3 * V_4 ,
const struct V_1 T_1 * V_2 ,
unsigned V_9 )
{
int V_5 = 0 ;
V_5 += F_5 ( V_4 , V_2 , F_3 ( struct V_3 , V_6 . V_7 ) ) ;
V_5 += F_5 ( & V_4 -> V_6 . V_7 , & V_2 -> V_8 ,
sizeof( struct V_3 ) -
F_3 ( struct V_3 , V_6 . V_7 ) +
V_9 ) ;
return V_5 ;
}
struct V_10 * F_6 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_10 * V_5 ;
unsigned long V_13 ;
F_7 () ;
if ( ! V_14 -> V_15 . V_16 ) {
F_8 ( L_1 ) ;
F_9 ( V_17 ) ;
}
F_10 ( V_4 -> V_6 . V_18 , V_19 , V_20 | V_14 -> V_15 . V_21 ) ;
V_13 = F_1 ( & V_14 -> V_15 . V_16 -> V_4 , V_4 ) ;
V_13 += F_11 ( V_14 -> V_15 . V_22 , & V_14 -> V_15 . V_16 -> V_22 ) ;
if ( V_13 ) {
F_8 ( L_2 ) ;
F_9 ( V_17 ) ;
}
V_12 = & F_12 ( V_23 , F_13 () ) ;
V_14 -> V_15 . V_24 = V_14 -> V_15 . V_25 ;
V_14 -> V_15 . V_26 = V_27 ;
F_14 ( V_12 , & V_14 -> V_15 ) ;
V_14 -> V_15 . V_25 = 0 ;
F_15 () ;
V_5 = V_28 -> V_29 ;
V_5 -> V_30 = V_14 -> V_15 . V_31 ;
F_16 ( V_5 , V_14 -> V_15 . V_32 ) ;
return V_5 ;
}
static void F_17 ( struct V_33 * V_34 )
{
T_2 * V_35 ;
T_3 * V_36 ;
T_4 * V_37 ;
T_5 * V_38 ;
T_6 * V_39 ;
int V_40 ;
F_18 ( & V_34 -> V_41 ) ;
V_35 = F_19 ( V_34 , 0xA0000 ) ;
if ( F_20 ( V_35 ) )
goto V_42;
V_36 = F_21 ( V_35 , 0xA0000 ) ;
if ( F_22 ( V_36 ) )
goto V_42;
V_37 = F_23 ( V_36 , 0xA0000 ) ;
F_24 ( V_34 , 0xA0000 , V_37 ) ;
if ( F_25 ( V_37 ) )
goto V_42;
V_38 = F_26 ( V_34 , V_37 , 0xA0000 , & V_39 ) ;
for ( V_40 = 0 ; V_40 < 32 ; V_40 ++ ) {
if ( F_27 ( * V_38 ) )
F_28 ( V_38 , F_29 ( * V_38 ) ) ;
V_38 ++ ;
}
F_30 ( V_38 , V_39 ) ;
V_42:
F_31 ( & V_34 -> V_41 ) ;
F_32 () ;
}
static void F_33 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
struct V_11 * V_12 ;
V_44 -> V_4 . V_6 . V_47 = 0 ;
V_44 -> V_4 . V_6 . V_48 = 0 ;
V_44 -> V_4 . V_6 . V_30 = 0 ;
#ifndef F_34
V_44 -> V_4 . V_6 . V_49 = 0 ;
#endif
V_19 = V_44 -> V_4 . V_6 . V_18 ;
V_44 -> V_4 . V_6 . V_18 &= V_50 ;
V_44 -> V_4 . V_6 . V_18 |= V_44 -> V_29 -> V_18 & ~ V_50 ;
V_44 -> V_4 . V_6 . V_18 |= V_51 ;
switch ( V_44 -> V_52 ) {
case V_53 :
V_46 -> V_15 . V_21 = 0 ;
break;
case V_54 :
V_46 -> V_15 . V_21 = V_55 | V_56 ;
break;
case V_57 :
V_46 -> V_15 . V_21 = V_58 | V_55 | V_56 ;
break;
default:
V_46 -> V_15 . V_21 = V_59 | V_58 | V_55 | V_56 ;
break;
}
V_44 -> V_29 -> V_60 = V_61 ;
V_46 -> V_15 . V_25 = V_46 -> V_15 . V_24 ;
V_46 -> V_15 . V_31 = V_44 -> V_29 -> V_30 ;
V_46 -> V_15 . V_32 = F_35 ( V_44 -> V_29 ) ;
V_12 = & F_12 ( V_23 , F_13 () ) ;
V_46 -> V_15 . V_24 = ( unsigned long ) & V_44 -> V_62 ;
if ( V_63 )
V_46 -> V_15 . V_26 = 0 ;
F_14 ( V_12 , & V_46 -> V_15 ) ;
F_15 () ;
V_46 -> V_15 . V_22 = V_44 -> V_22 ;
if ( V_44 -> V_18 & V_64 )
F_17 ( V_46 -> V_34 ) ;
#ifdef F_36
if ( F_37 ( V_14 -> V_65 ) )
F_38 ( 1 , 0 ) ;
#endif
__asm__ __volatile__(
"movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
#ifdef F_34
"mov %2, %%gs\n\t"
#endif
"jmp resume_userspace"
:
:"r" (&info->regs), "r" (task_thread_info(tsk)), "r" (0));
}
static inline void F_39 ( struct V_3 * V_66 , int V_67 )
{
struct V_10 * V_29 ;
V_29 = F_6 ( V_66 ) ;
V_29 -> V_60 = V_67 ;
__asm__ __volatile__("movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
"jmp resume_userspace"
: : "r" (regs32), "r" (current_thread_info()));
}
static inline void F_40 ( struct V_3 * V_4 )
{
V_19 |= V_20 ;
if ( V_19 & V_68 )
F_39 ( V_4 , V_69 ) ;
}
static inline void F_41 ( struct V_3 * V_4 )
{
V_19 &= ~ V_20 ;
}
static inline void F_42 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_70 ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_58 ;
}
static inline void F_44 ( unsigned long V_18 , struct V_3 * V_4 )
{
F_10 ( V_19 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_50 ) ;
if ( V_18 & V_71 )
F_40 ( V_4 ) ;
else
F_41 ( V_4 ) ;
}
static inline void F_45 ( unsigned short V_18 , struct V_3 * V_4 )
{
F_10 ( V_72 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_50 ) ;
if ( V_18 & V_71 )
F_40 ( V_4 ) ;
else
F_41 ( V_4 ) ;
}
static inline unsigned long F_46 ( struct V_3 * V_4 )
{
unsigned long V_18 = V_4 -> V_6 . V_18 & V_73 ;
if ( V_19 & V_20 )
V_18 |= V_71 ;
V_18 |= V_56 ;
return V_18 | ( V_19 & V_14 -> V_15 . V_21 ) ;
}
static inline int F_47 ( int V_74 , struct V_75 * V_76 )
{
__asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0"
:"=r" (nr)
:"m" (*bitmap), "r" (nr));
return V_74 ;
}
static void F_48 ( struct V_3 * V_4 , int V_40 ,
unsigned char T_1 * V_77 , unsigned short V_78 )
{
unsigned long T_1 * V_79 ;
unsigned long V_80 ;
if ( V_4 -> V_6 . V_81 == V_82 )
goto V_83;
if ( F_47 ( V_40 , & V_28 -> V_84 ) )
goto V_83;
if ( V_40 == 0x21 && F_47 ( F_49 ( V_4 ) , & V_28 -> V_85 ) )
goto V_83;
V_79 = ( unsigned long T_1 * ) ( V_40 << 2 ) ;
if ( F_50 ( V_80 , V_79 ) )
goto V_83;
if ( ( V_80 >> 16 ) == V_82 )
goto V_83;
F_51 ( V_77 , V_78 , F_46 ( V_4 ) , V_83 ) ;
F_51 ( V_77 , V_78 , V_4 -> V_6 . V_81 , V_83 ) ;
F_51 ( V_77 , V_78 , F_52 ( V_4 ) , V_83 ) ;
V_4 -> V_6 . V_81 = V_80 >> 16 ;
F_53 ( V_4 ) -= 6 ;
F_52 ( V_4 ) = V_80 & 0xffff ;
F_42 ( V_4 ) ;
F_41 ( V_4 ) ;
F_43 ( V_4 ) ;
return;
V_83:
F_39 ( V_4 , V_86 + ( V_40 << 8 ) ) ;
}
int F_54 ( struct V_3 * V_4 , long V_87 , int V_88 )
{
if ( V_89 . V_90 ) {
if ( ( V_88 == 3 ) || ( V_88 == 1 ) ) {
V_28 -> V_29 -> V_60 = V_91 + ( V_88 << 8 ) ;
F_55 ( V_92 ) ;
return 0 ;
}
F_48 ( V_4 , V_88 , ( unsigned char T_1 * ) ( V_4 -> V_6 . V_93 << 4 ) , F_53 ( V_4 ) ) ;
return 0 ;
}
if ( V_88 != 1 )
return 1 ;
V_14 -> V_15 . V_94 = V_88 ;
V_14 -> V_15 . V_87 = V_87 ;
F_56 ( V_95 , V_14 ) ;
return 0 ;
}
void F_57 ( struct V_3 * V_4 , long V_87 )
{
unsigned char V_96 ;
unsigned char T_1 * V_97 ;
unsigned char T_1 * V_77 ;
unsigned short V_98 , V_78 , V_99 ;
int V_100 , V_101 ;
#define F_58 \
if (VMPI.vm86dbg_active && VMPI.vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
#define F_59 do { \
if (VMPI.force_return_for_pic && (VEFLAGS & (X86_EFLAGS_IF | X86_EFLAGS_VIF))) \
return_to_32bit(regs, VM86_PICRETURN); \
if (orig_flags & X86_EFLAGS_TF) \
handle_vm86_trap(regs, 0, 1); \
return; } while (0)
V_99 = * ( unsigned short * ) & V_4 -> V_6 . V_18 ;
V_97 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_81 << 4 ) ;
V_77 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_93 << 4 ) ;
V_78 = F_53 ( V_4 ) ;
V_98 = F_52 ( V_4 ) ;
V_100 = 0 ;
V_101 = 0 ;
do {
switch ( V_96 = F_60 ( V_97 , V_98 , V_102 ) ) {
case 0x66 : V_100 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_101 = 1 ;
}
} while ( ! V_101 );
switch ( V_96 ) {
case 0x9c :
if ( V_100 ) {
F_61 ( V_77 , V_78 , F_46 ( V_4 ) , V_102 ) ;
F_53 ( V_4 ) -= 4 ;
} else {
F_51 ( V_77 , V_78 , F_46 ( V_4 ) , V_102 ) ;
F_53 ( V_4 ) -= 2 ;
}
F_52 ( V_4 ) = V_98 ;
F_59 ;
case 0x9d :
{
unsigned long V_103 ;
if ( V_100 ) {
V_103 = F_62 ( V_77 , V_78 , V_102 ) ;
F_53 ( V_4 ) += 4 ;
} else {
V_103 = F_63 ( V_77 , V_78 , V_102 ) ;
F_53 ( V_4 ) += 2 ;
}
F_52 ( V_4 ) = V_98 ;
F_58 ;
if ( V_100 )
F_44 ( V_103 , V_4 ) ;
else
F_45 ( V_103 , V_4 ) ;
F_59 ;
}
case 0xcd : {
int V_104 = F_60 ( V_97 , V_98 , V_102 ) ;
F_52 ( V_4 ) = V_98 ;
if ( V_89 . V_105 ) {
if ( ( 1 << ( V_104 & 7 ) ) & V_89 . V_106 [ V_104 >> 3 ] )
F_39 ( V_4 , V_86 + ( V_104 << 8 ) ) ;
}
F_48 ( V_4 , V_104 , V_77 , V_78 ) ;
return;
}
case 0xcf :
{
unsigned long V_107 ;
unsigned long V_108 ;
unsigned long V_103 ;
if ( V_100 ) {
V_107 = F_62 ( V_77 , V_78 , V_102 ) ;
V_108 = F_62 ( V_77 , V_78 , V_102 ) ;
V_103 = F_62 ( V_77 , V_78 , V_102 ) ;
F_53 ( V_4 ) += 12 ;
} else {
V_107 = F_63 ( V_77 , V_78 , V_102 ) ;
V_108 = F_63 ( V_77 , V_78 , V_102 ) ;
V_103 = F_63 ( V_77 , V_78 , V_102 ) ;
F_53 ( V_4 ) += 6 ;
}
F_52 ( V_4 ) = V_107 ;
V_4 -> V_6 . V_81 = V_108 ;
F_58 ;
if ( V_100 ) {
F_44 ( V_103 , V_4 ) ;
} else {
F_45 ( V_103 , V_4 ) ;
}
F_59 ;
}
case 0xfa :
F_52 ( V_4 ) = V_98 ;
F_41 ( V_4 ) ;
F_59 ;
case 0xfb :
F_52 ( V_4 ) = V_98 ;
F_40 ( V_4 ) ;
F_59 ;
default:
F_39 ( V_4 , V_109 ) ;
}
return;
V_102:
F_39 ( V_4 , V_109 ) ;
}
static T_7 F_64 ( int V_104 , void * V_110 )
{
int V_111 ;
unsigned long V_18 ;
F_65 ( & V_112 , V_18 ) ;
V_111 = 1 << V_104 ;
if ( ( V_113 & V_111 ) || ! V_114 [ V_104 ] . V_46 )
goto V_42;
V_113 |= V_111 ;
if ( V_114 [ V_104 ] . V_115 )
F_66 ( V_114 [ V_104 ] . V_115 , V_114 [ V_104 ] . V_46 , 1 ) ;
F_67 ( V_104 ) ;
F_68 ( & V_112 , V_18 ) ;
return V_116 ;
V_42:
F_68 ( & V_112 , V_18 ) ;
return V_117 ;
}
static inline void F_69 ( int V_118 )
{
unsigned long V_18 ;
F_70 ( V_118 , NULL ) ;
V_114 [ V_118 ] . V_46 = NULL ;
F_65 ( & V_112 , V_18 ) ;
V_113 &= ~ ( 1 << V_118 ) ;
F_68 ( & V_112 , V_18 ) ;
}
void F_71 ( struct V_45 * V_119 )
{
int V_40 ;
for ( V_40 = V_120 ; V_40 <= V_121 ; V_40 ++ )
if ( V_114 [ V_40 ] . V_46 == V_119 )
F_69 ( V_40 ) ;
}
static inline int F_72 ( int V_118 )
{
int V_122 ;
unsigned long V_18 ;
int V_5 = 0 ;
if ( F_73 ( V_118 ) ) return 0 ;
if ( V_114 [ V_118 ] . V_46 != V_14 ) return 0 ;
F_65 ( & V_112 , V_18 ) ;
V_122 = V_113 & ( 1 << V_118 ) ;
V_113 &= ~ V_122 ;
if ( V_122 ) {
F_74 ( V_118 ) ;
V_5 = 1 ;
}
F_68 ( & V_112 , V_18 ) ;
return V_5 ;
}
static int F_75 ( int V_123 , int V_118 )
{
int V_5 ;
switch ( V_123 ) {
case V_124 : {
return F_72 ( V_118 ) ;
}
case V_125 : {
return V_113 ;
}
case V_126 : {
int V_115 = V_118 >> 8 ;
int V_127 = V_118 & 255 ;
if ( ! F_76 ( V_128 ) ) return - V_129 ;
if ( ! ( ( 1 << V_115 ) & V_130 ) ) return - V_129 ;
if ( F_73 ( V_127 ) ) return - V_129 ;
if ( V_114 [ V_127 ] . V_46 ) return - V_129 ;
V_5 = F_77 ( V_127 , & F_64 , 0 , V_131 , NULL ) ;
if ( V_5 ) return V_5 ;
V_114 [ V_127 ] . V_115 = V_115 ;
V_114 [ V_127 ] . V_46 = V_14 ;
return V_127 ;
}
case V_132 : {
if ( F_73 ( V_118 ) ) return - V_129 ;
if ( ! V_114 [ V_118 ] . V_46 ) return 0 ;
if ( V_114 [ V_118 ] . V_46 != V_14 ) return - V_129 ;
F_69 ( V_118 ) ;
return 0 ;
}
}
return - V_133 ;
}
