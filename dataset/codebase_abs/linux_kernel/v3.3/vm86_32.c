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
V_35 = F_18 ( V_34 , 0xA0000 ) ;
if ( F_19 ( V_35 ) )
goto V_41;
V_36 = F_20 ( V_35 , 0xA0000 ) ;
if ( F_21 ( V_36 ) )
goto V_41;
V_37 = F_22 ( V_36 , 0xA0000 ) ;
F_23 ( V_34 , V_37 ) ;
if ( F_24 ( V_37 ) )
goto V_41;
V_38 = F_25 ( V_34 , V_37 , 0xA0000 , & V_39 ) ;
for ( V_40 = 0 ; V_40 < 32 ; V_40 ++ ) {
if ( F_26 ( * V_38 ) )
F_27 ( V_38 , F_28 ( * V_38 ) ) ;
V_38 ++ ;
}
F_29 ( V_38 , V_39 ) ;
V_41:
F_30 () ;
}
int F_31 ( struct V_42 T_1 * V_43 , struct V_10 * V_4 )
{
struct V_44 V_45 ;
struct V_46 * V_47 ;
int V_13 , V_5 = - V_48 ;
V_47 = V_14 ;
if ( V_47 -> V_15 . V_25 )
goto V_41;
V_13 = F_4 ( & V_45 . V_4 , & V_43 -> V_4 ,
F_3 ( struct V_44 , V_49 ) -
sizeof( V_45 . V_4 ) ) ;
V_5 = - V_50 ;
if ( V_13 )
goto V_41;
memset ( & V_45 . V_49 , 0 , ( int ) & V_45 . V_29 - ( int ) & V_45 . V_49 ) ;
V_45 . V_29 = V_4 ;
V_47 -> V_15 . V_16 = V_43 ;
F_32 ( & V_45 , V_47 ) ;
V_5 = 0 ;
V_41:
return V_5 ;
}
int F_33 ( unsigned long V_51 , unsigned long V_52 , struct V_10 * V_4 )
{
struct V_44 V_45 ;
struct V_46 * V_47 ;
int V_13 , V_5 ;
struct V_53 T_1 * V_43 ;
V_47 = V_14 ;
switch ( V_51 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_5 = F_34 ( V_51 , ( int ) V_52 ) ;
goto V_41;
case V_58 :
V_5 = 0 ;
goto V_41;
}
V_5 = - V_48 ;
if ( V_47 -> V_15 . V_25 )
goto V_41;
V_43 = (struct V_53 T_1 * ) V_52 ;
V_13 = F_4 ( & V_45 . V_4 , & V_43 -> V_4 ,
F_3 ( struct V_44 , V_29 ) -
sizeof( V_45 . V_4 ) ) ;
V_5 = - V_50 ;
if ( V_13 )
goto V_41;
V_45 . V_29 = V_4 ;
V_45 . V_49 . V_59 = 1 ;
V_47 -> V_15 . V_16 = (struct V_42 T_1 * ) V_43 ;
F_32 ( & V_45 , V_47 ) ;
V_5 = 0 ;
V_41:
return V_5 ;
}
static void F_32 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_11 * V_12 ;
V_45 -> V_4 . V_6 . V_60 = 0 ;
V_45 -> V_4 . V_6 . V_61 = 0 ;
V_45 -> V_4 . V_6 . V_30 = 0 ;
#ifndef F_35
V_45 -> V_4 . V_6 . V_62 = 0 ;
#endif
V_19 = V_45 -> V_4 . V_6 . V_18 ;
V_45 -> V_4 . V_6 . V_18 &= V_63 ;
V_45 -> V_4 . V_6 . V_18 |= V_45 -> V_29 -> V_18 & ~ V_63 ;
V_45 -> V_4 . V_6 . V_18 |= V_64 ;
switch ( V_45 -> V_65 ) {
case V_66 :
V_47 -> V_15 . V_21 = 0 ;
break;
case V_67 :
V_47 -> V_15 . V_21 = V_68 | V_69 ;
break;
case V_70 :
V_47 -> V_15 . V_21 = V_71 | V_68 | V_69 ;
break;
default:
V_47 -> V_15 . V_21 = V_72 | V_71 | V_68 | V_69 ;
break;
}
V_45 -> V_29 -> V_73 = V_74 ;
V_47 -> V_15 . V_25 = V_47 -> V_15 . V_24 ;
V_47 -> V_15 . V_31 = V_45 -> V_29 -> V_30 ;
V_47 -> V_15 . V_32 = F_36 ( V_45 -> V_29 ) ;
V_12 = & F_12 ( V_23 , F_13 () ) ;
V_47 -> V_15 . V_24 = ( unsigned long ) & V_45 -> V_75 ;
if ( V_76 )
V_47 -> V_15 . V_26 = 0 ;
F_14 ( V_12 , & V_47 -> V_15 ) ;
F_15 () ;
V_47 -> V_15 . V_22 = V_45 -> V_22 ;
if ( V_45 -> V_18 & V_77 )
F_17 ( V_47 -> V_34 ) ;
#ifdef F_37
if ( F_38 ( V_14 -> V_78 ) )
F_39 ( 1 , 0 ) ;
#endif
__asm__ __volatile__(
"movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
#ifdef F_35
"mov %2, %%gs\n\t"
#endif
"jmp resume_userspace"
:
:"r" (&info->regs), "r" (task_thread_info(tsk)), "r" (0));
}
static inline void F_40 ( struct V_3 * V_79 , int V_80 )
{
struct V_10 * V_29 ;
V_29 = F_6 ( V_79 ) ;
V_29 -> V_73 = V_80 ;
__asm__ __volatile__("movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
"jmp resume_userspace"
: : "r" (regs32), "r" (current_thread_info()));
}
static inline void F_41 ( struct V_3 * V_4 )
{
V_19 |= V_20 ;
if ( V_19 & V_81 )
F_40 ( V_4 , V_82 ) ;
}
static inline void F_42 ( struct V_3 * V_4 )
{
V_19 &= ~ V_20 ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_83 ;
}
static inline void F_44 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_71 ;
}
static inline void F_45 ( unsigned long V_18 , struct V_3 * V_4 )
{
F_10 ( V_19 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_63 ) ;
if ( V_18 & V_84 )
F_41 ( V_4 ) ;
else
F_42 ( V_4 ) ;
}
static inline void F_46 ( unsigned short V_18 , struct V_3 * V_4 )
{
F_10 ( V_85 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_63 ) ;
if ( V_18 & V_84 )
F_41 ( V_4 ) ;
else
F_42 ( V_4 ) ;
}
static inline unsigned long F_47 ( struct V_3 * V_4 )
{
unsigned long V_18 = V_4 -> V_6 . V_18 & V_86 ;
if ( V_19 & V_20 )
V_18 |= V_84 ;
V_18 |= V_69 ;
return V_18 | ( V_19 & V_14 -> V_15 . V_21 ) ;
}
static inline int F_48 ( int V_87 , struct V_88 * V_89 )
{
__asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0"
:"=r" (nr)
:"m" (*bitmap), "r" (nr));
return V_87 ;
}
static void F_49 ( struct V_3 * V_4 , int V_40 ,
unsigned char T_1 * V_90 , unsigned short V_91 )
{
unsigned long T_1 * V_92 ;
unsigned long V_93 ;
if ( V_4 -> V_6 . V_94 == V_95 )
goto V_96;
if ( F_48 ( V_40 , & V_28 -> V_97 ) )
goto V_96;
if ( V_40 == 0x21 && F_48 ( F_50 ( V_4 ) , & V_28 -> V_98 ) )
goto V_96;
V_92 = ( unsigned long T_1 * ) ( V_40 << 2 ) ;
if ( F_51 ( V_93 , V_92 ) )
goto V_96;
if ( ( V_93 >> 16 ) == V_95 )
goto V_96;
F_52 ( V_90 , V_91 , F_47 ( V_4 ) , V_96 ) ;
F_52 ( V_90 , V_91 , V_4 -> V_6 . V_94 , V_96 ) ;
F_52 ( V_90 , V_91 , F_53 ( V_4 ) , V_96 ) ;
V_4 -> V_6 . V_94 = V_93 >> 16 ;
F_54 ( V_4 ) -= 6 ;
F_53 ( V_4 ) = V_93 & 0xffff ;
F_43 ( V_4 ) ;
F_42 ( V_4 ) ;
F_44 ( V_4 ) ;
return;
V_96:
F_40 ( V_4 , V_99 + ( V_40 << 8 ) ) ;
}
int F_55 ( struct V_3 * V_4 , long V_100 , int V_101 )
{
if ( V_102 . V_59 ) {
if ( ( V_101 == 3 ) || ( V_101 == 1 ) ) {
V_28 -> V_29 -> V_73 = V_103 + ( V_101 << 8 ) ;
F_56 ( V_104 ) ;
return 0 ;
}
F_49 ( V_4 , V_101 , ( unsigned char T_1 * ) ( V_4 -> V_6 . V_105 << 4 ) , F_54 ( V_4 ) ) ;
return 0 ;
}
if ( V_101 != 1 )
return 1 ;
V_14 -> V_15 . V_106 = V_101 ;
V_14 -> V_15 . V_100 = V_100 ;
F_57 ( V_107 , V_14 ) ;
return 0 ;
}
void F_58 ( struct V_3 * V_4 , long V_100 )
{
unsigned char V_108 ;
unsigned char T_1 * V_109 ;
unsigned char T_1 * V_90 ;
unsigned short V_110 , V_91 , V_111 ;
int V_112 , V_113 ;
#define F_59 \
if (VMPI.vm86dbg_active && VMPI.vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
#define F_60 do { \
if (VMPI.force_return_for_pic && (VEFLAGS & (X86_EFLAGS_IF | X86_EFLAGS_VIF))) \
return_to_32bit(regs, VM86_PICRETURN); \
if (orig_flags & X86_EFLAGS_TF) \
handle_vm86_trap(regs, 0, 1); \
return; } while (0)
V_111 = * ( unsigned short * ) & V_4 -> V_6 . V_18 ;
V_109 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_94 << 4 ) ;
V_90 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_105 << 4 ) ;
V_91 = F_54 ( V_4 ) ;
V_110 = F_53 ( V_4 ) ;
V_112 = 0 ;
V_113 = 0 ;
do {
switch ( V_108 = F_61 ( V_109 , V_110 , V_114 ) ) {
case 0x66 : V_112 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_113 = 1 ;
}
} while ( ! V_113 );
switch ( V_108 ) {
case 0x9c :
if ( V_112 ) {
F_62 ( V_90 , V_91 , F_47 ( V_4 ) , V_114 ) ;
F_54 ( V_4 ) -= 4 ;
} else {
F_52 ( V_90 , V_91 , F_47 ( V_4 ) , V_114 ) ;
F_54 ( V_4 ) -= 2 ;
}
F_53 ( V_4 ) = V_110 ;
F_60 ;
case 0x9d :
{
unsigned long V_115 ;
if ( V_112 ) {
V_115 = F_63 ( V_90 , V_91 , V_114 ) ;
F_54 ( V_4 ) += 4 ;
} else {
V_115 = F_64 ( V_90 , V_91 , V_114 ) ;
F_54 ( V_4 ) += 2 ;
}
F_53 ( V_4 ) = V_110 ;
F_59 ;
if ( V_112 )
F_45 ( V_115 , V_4 ) ;
else
F_46 ( V_115 , V_4 ) ;
F_60 ;
}
case 0xcd : {
int V_116 = F_61 ( V_109 , V_110 , V_114 ) ;
F_53 ( V_4 ) = V_110 ;
if ( V_102 . V_117 ) {
if ( ( 1 << ( V_116 & 7 ) ) & V_102 . V_118 [ V_116 >> 3 ] )
F_40 ( V_4 , V_99 + ( V_116 << 8 ) ) ;
}
F_49 ( V_4 , V_116 , V_90 , V_91 ) ;
return;
}
case 0xcf :
{
unsigned long V_119 ;
unsigned long V_120 ;
unsigned long V_115 ;
if ( V_112 ) {
V_119 = F_63 ( V_90 , V_91 , V_114 ) ;
V_120 = F_63 ( V_90 , V_91 , V_114 ) ;
V_115 = F_63 ( V_90 , V_91 , V_114 ) ;
F_54 ( V_4 ) += 12 ;
} else {
V_119 = F_64 ( V_90 , V_91 , V_114 ) ;
V_120 = F_64 ( V_90 , V_91 , V_114 ) ;
V_115 = F_64 ( V_90 , V_91 , V_114 ) ;
F_54 ( V_4 ) += 6 ;
}
F_53 ( V_4 ) = V_119 ;
V_4 -> V_6 . V_94 = V_120 ;
F_59 ;
if ( V_112 ) {
F_45 ( V_115 , V_4 ) ;
} else {
F_46 ( V_115 , V_4 ) ;
}
F_60 ;
}
case 0xfa :
F_53 ( V_4 ) = V_110 ;
F_42 ( V_4 ) ;
F_60 ;
case 0xfb :
F_53 ( V_4 ) = V_110 ;
F_41 ( V_4 ) ;
F_60 ;
default:
F_40 ( V_4 , V_121 ) ;
}
return;
V_114:
F_40 ( V_4 , V_121 ) ;
}
static T_7 F_65 ( int V_116 , void * V_122 )
{
int V_123 ;
unsigned long V_18 ;
F_66 ( & V_124 , V_18 ) ;
V_123 = 1 << V_116 ;
if ( ( V_125 & V_123 ) || ! V_126 [ V_116 ] . V_47 )
goto V_41;
V_125 |= V_123 ;
if ( V_126 [ V_116 ] . V_127 )
F_67 ( V_126 [ V_116 ] . V_127 , V_126 [ V_116 ] . V_47 , 1 ) ;
F_68 ( V_116 ) ;
F_69 ( & V_124 , V_18 ) ;
return V_128 ;
V_41:
F_69 ( & V_124 , V_18 ) ;
return V_129 ;
}
static inline void F_70 ( int V_130 )
{
unsigned long V_18 ;
F_71 ( V_130 , NULL ) ;
V_126 [ V_130 ] . V_47 = NULL ;
F_66 ( & V_124 , V_18 ) ;
V_125 &= ~ ( 1 << V_130 ) ;
F_69 ( & V_124 , V_18 ) ;
}
void F_72 ( struct V_46 * V_131 )
{
int V_40 ;
for ( V_40 = V_132 ; V_40 <= V_133 ; V_40 ++ )
if ( V_126 [ V_40 ] . V_47 == V_131 )
F_70 ( V_40 ) ;
}
static inline int F_73 ( int V_130 )
{
int V_134 ;
unsigned long V_18 ;
int V_5 = 0 ;
if ( F_74 ( V_130 ) ) return 0 ;
if ( V_126 [ V_130 ] . V_47 != V_14 ) return 0 ;
F_66 ( & V_124 , V_18 ) ;
V_134 = V_125 & ( 1 << V_130 ) ;
V_125 &= ~ V_134 ;
if ( V_134 ) {
F_75 ( V_130 ) ;
V_5 = 1 ;
}
F_69 ( & V_124 , V_18 ) ;
return V_5 ;
}
static int F_34 ( int V_135 , int V_130 )
{
int V_5 ;
switch ( V_135 ) {
case V_57 : {
return F_73 ( V_130 ) ;
}
case V_56 : {
return V_125 ;
}
case V_54 : {
int V_127 = V_130 >> 8 ;
int V_136 = V_130 & 255 ;
if ( ! F_76 ( V_137 ) ) return - V_48 ;
if ( ! ( ( 1 << V_127 ) & V_138 ) ) return - V_48 ;
if ( F_74 ( V_136 ) ) return - V_48 ;
if ( V_126 [ V_136 ] . V_47 ) return - V_48 ;
V_5 = F_77 ( V_136 , & F_65 , 0 , V_139 , NULL ) ;
if ( V_5 ) return V_5 ;
V_126 [ V_136 ] . V_127 = V_127 ;
V_126 [ V_136 ] . V_47 = V_14 ;
return V_136 ;
}
case V_55 : {
if ( F_74 ( V_130 ) ) return - V_48 ;
if ( ! V_126 [ V_130 ] . V_47 ) return 0 ;
if ( V_126 [ V_130 ] . V_47 != V_14 ) return - V_48 ;
F_70 ( V_130 ) ;
return 0 ;
}
}
return - V_140 ;
}
