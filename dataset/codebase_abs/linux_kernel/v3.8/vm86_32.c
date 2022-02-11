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
int F_33 ( struct V_43 T_1 * V_44 , struct V_10 * V_4 )
{
struct V_45 V_46 ;
struct V_47 * V_48 ;
int V_13 , V_5 = - V_49 ;
V_48 = V_14 ;
if ( V_48 -> V_15 . V_25 )
goto V_42;
V_13 = F_4 ( & V_46 . V_4 , & V_44 -> V_4 ,
F_3 ( struct V_45 , V_50 ) -
sizeof( V_46 . V_4 ) ) ;
V_5 = - V_51 ;
if ( V_13 )
goto V_42;
memset ( & V_46 . V_50 , 0 , ( int ) & V_46 . V_29 - ( int ) & V_46 . V_50 ) ;
V_46 . V_29 = V_4 ;
V_48 -> V_15 . V_16 = V_44 ;
F_34 ( & V_46 , V_48 ) ;
V_5 = 0 ;
V_42:
return V_5 ;
}
int F_35 ( unsigned long V_52 , unsigned long V_53 , struct V_10 * V_4 )
{
struct V_45 V_46 ;
struct V_47 * V_48 ;
int V_13 , V_5 ;
struct V_54 T_1 * V_44 ;
V_48 = V_14 ;
switch ( V_52 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_5 = F_36 ( V_52 , ( int ) V_53 ) ;
goto V_42;
case V_59 :
V_5 = 0 ;
goto V_42;
}
V_5 = - V_49 ;
if ( V_48 -> V_15 . V_25 )
goto V_42;
V_44 = (struct V_54 T_1 * ) V_53 ;
V_13 = F_4 ( & V_46 . V_4 , & V_44 -> V_4 ,
F_3 ( struct V_45 , V_29 ) -
sizeof( V_46 . V_4 ) ) ;
V_5 = - V_51 ;
if ( V_13 )
goto V_42;
V_46 . V_29 = V_4 ;
V_46 . V_50 . V_60 = 1 ;
V_48 -> V_15 . V_16 = (struct V_43 T_1 * ) V_44 ;
F_34 ( & V_46 , V_48 ) ;
V_5 = 0 ;
V_42:
return V_5 ;
}
static void F_34 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_11 * V_12 ;
V_46 -> V_4 . V_6 . V_61 = 0 ;
V_46 -> V_4 . V_6 . V_62 = 0 ;
V_46 -> V_4 . V_6 . V_30 = 0 ;
#ifndef F_37
V_46 -> V_4 . V_6 . V_63 = 0 ;
#endif
V_19 = V_46 -> V_4 . V_6 . V_18 ;
V_46 -> V_4 . V_6 . V_18 &= V_64 ;
V_46 -> V_4 . V_6 . V_18 |= V_46 -> V_29 -> V_18 & ~ V_64 ;
V_46 -> V_4 . V_6 . V_18 |= V_65 ;
switch ( V_46 -> V_66 ) {
case V_67 :
V_48 -> V_15 . V_21 = 0 ;
break;
case V_68 :
V_48 -> V_15 . V_21 = V_69 | V_70 ;
break;
case V_71 :
V_48 -> V_15 . V_21 = V_72 | V_69 | V_70 ;
break;
default:
V_48 -> V_15 . V_21 = V_73 | V_72 | V_69 | V_70 ;
break;
}
V_46 -> V_29 -> V_74 = V_75 ;
V_48 -> V_15 . V_25 = V_48 -> V_15 . V_24 ;
V_48 -> V_15 . V_31 = V_46 -> V_29 -> V_30 ;
V_48 -> V_15 . V_32 = F_38 ( V_46 -> V_29 ) ;
V_12 = & F_12 ( V_23 , F_13 () ) ;
V_48 -> V_15 . V_24 = ( unsigned long ) & V_46 -> V_76 ;
if ( V_77 )
V_48 -> V_15 . V_26 = 0 ;
F_14 ( V_12 , & V_48 -> V_15 ) ;
F_15 () ;
V_48 -> V_15 . V_22 = V_46 -> V_22 ;
if ( V_46 -> V_18 & V_78 )
F_17 ( V_48 -> V_34 ) ;
#ifdef F_39
if ( F_40 ( V_14 -> V_79 ) )
F_41 ( 1 , 0 ) ;
#endif
__asm__ __volatile__(
"movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
#ifdef F_37
"mov %2, %%gs\n\t"
#endif
"jmp resume_userspace"
:
:"r" (&info->regs), "r" (task_thread_info(tsk)), "r" (0));
}
static inline void F_42 ( struct V_3 * V_80 , int V_81 )
{
struct V_10 * V_29 ;
V_29 = F_6 ( V_80 ) ;
V_29 -> V_74 = V_81 ;
__asm__ __volatile__("movl %0,%%esp\n\t"
"movl %1,%%ebp\n\t"
"jmp resume_userspace"
: : "r" (regs32), "r" (current_thread_info()));
}
static inline void F_43 ( struct V_3 * V_4 )
{
V_19 |= V_20 ;
if ( V_19 & V_82 )
F_42 ( V_4 , V_83 ) ;
}
static inline void F_44 ( struct V_3 * V_4 )
{
V_19 &= ~ V_20 ;
}
static inline void F_45 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_84 ;
}
static inline void F_46 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_18 &= ~ V_72 ;
}
static inline void F_47 ( unsigned long V_18 , struct V_3 * V_4 )
{
F_10 ( V_19 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_64 ) ;
if ( V_18 & V_85 )
F_43 ( V_4 ) ;
else
F_44 ( V_4 ) ;
}
static inline void F_48 ( unsigned short V_18 , struct V_3 * V_4 )
{
F_10 ( V_86 , V_18 , V_14 -> V_15 . V_21 ) ;
F_10 ( V_4 -> V_6 . V_18 , V_18 , V_64 ) ;
if ( V_18 & V_85 )
F_43 ( V_4 ) ;
else
F_44 ( V_4 ) ;
}
static inline unsigned long F_49 ( struct V_3 * V_4 )
{
unsigned long V_18 = V_4 -> V_6 . V_18 & V_87 ;
if ( V_19 & V_20 )
V_18 |= V_85 ;
V_18 |= V_70 ;
return V_18 | ( V_19 & V_14 -> V_15 . V_21 ) ;
}
static inline int F_50 ( int V_88 , struct V_89 * V_90 )
{
__asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0"
:"=r" (nr)
:"m" (*bitmap), "r" (nr));
return V_88 ;
}
static void F_51 ( struct V_3 * V_4 , int V_40 ,
unsigned char T_1 * V_91 , unsigned short V_92 )
{
unsigned long T_1 * V_93 ;
unsigned long V_94 ;
if ( V_4 -> V_6 . V_95 == V_96 )
goto V_97;
if ( F_50 ( V_40 , & V_28 -> V_98 ) )
goto V_97;
if ( V_40 == 0x21 && F_50 ( F_52 ( V_4 ) , & V_28 -> V_99 ) )
goto V_97;
V_93 = ( unsigned long T_1 * ) ( V_40 << 2 ) ;
if ( F_53 ( V_94 , V_93 ) )
goto V_97;
if ( ( V_94 >> 16 ) == V_96 )
goto V_97;
F_54 ( V_91 , V_92 , F_49 ( V_4 ) , V_97 ) ;
F_54 ( V_91 , V_92 , V_4 -> V_6 . V_95 , V_97 ) ;
F_54 ( V_91 , V_92 , F_55 ( V_4 ) , V_97 ) ;
V_4 -> V_6 . V_95 = V_94 >> 16 ;
F_56 ( V_4 ) -= 6 ;
F_55 ( V_4 ) = V_94 & 0xffff ;
F_45 ( V_4 ) ;
F_44 ( V_4 ) ;
F_46 ( V_4 ) ;
return;
V_97:
F_42 ( V_4 , V_100 + ( V_40 << 8 ) ) ;
}
int F_57 ( struct V_3 * V_4 , long V_101 , int V_102 )
{
if ( V_103 . V_60 ) {
if ( ( V_102 == 3 ) || ( V_102 == 1 ) ) {
V_28 -> V_29 -> V_74 = V_104 + ( V_102 << 8 ) ;
F_58 ( V_105 ) ;
return 0 ;
}
F_51 ( V_4 , V_102 , ( unsigned char T_1 * ) ( V_4 -> V_6 . V_106 << 4 ) , F_56 ( V_4 ) ) ;
return 0 ;
}
if ( V_102 != 1 )
return 1 ;
V_14 -> V_15 . V_107 = V_102 ;
V_14 -> V_15 . V_101 = V_101 ;
F_59 ( V_108 , V_14 ) ;
return 0 ;
}
void F_60 ( struct V_3 * V_4 , long V_101 )
{
unsigned char V_109 ;
unsigned char T_1 * V_110 ;
unsigned char T_1 * V_91 ;
unsigned short V_111 , V_92 , V_112 ;
int V_113 , V_114 ;
#define F_61 \
if (VMPI.vm86dbg_active && VMPI.vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
#define F_62 do { \
if (VMPI.force_return_for_pic && (VEFLAGS & (X86_EFLAGS_IF | X86_EFLAGS_VIF))) \
return_to_32bit(regs, VM86_PICRETURN); \
if (orig_flags & X86_EFLAGS_TF) \
handle_vm86_trap(regs, 0, 1); \
return; } while (0)
V_112 = * ( unsigned short * ) & V_4 -> V_6 . V_18 ;
V_110 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_95 << 4 ) ;
V_91 = ( unsigned char T_1 * ) ( V_4 -> V_6 . V_106 << 4 ) ;
V_92 = F_56 ( V_4 ) ;
V_111 = F_55 ( V_4 ) ;
V_113 = 0 ;
V_114 = 0 ;
do {
switch ( V_109 = F_63 ( V_110 , V_111 , V_115 ) ) {
case 0x66 : V_113 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_114 = 1 ;
}
} while ( ! V_114 );
switch ( V_109 ) {
case 0x9c :
if ( V_113 ) {
F_64 ( V_91 , V_92 , F_49 ( V_4 ) , V_115 ) ;
F_56 ( V_4 ) -= 4 ;
} else {
F_54 ( V_91 , V_92 , F_49 ( V_4 ) , V_115 ) ;
F_56 ( V_4 ) -= 2 ;
}
F_55 ( V_4 ) = V_111 ;
F_62 ;
case 0x9d :
{
unsigned long V_116 ;
if ( V_113 ) {
V_116 = F_65 ( V_91 , V_92 , V_115 ) ;
F_56 ( V_4 ) += 4 ;
} else {
V_116 = F_66 ( V_91 , V_92 , V_115 ) ;
F_56 ( V_4 ) += 2 ;
}
F_55 ( V_4 ) = V_111 ;
F_61 ;
if ( V_113 )
F_47 ( V_116 , V_4 ) ;
else
F_48 ( V_116 , V_4 ) ;
F_62 ;
}
case 0xcd : {
int V_117 = F_63 ( V_110 , V_111 , V_115 ) ;
F_55 ( V_4 ) = V_111 ;
if ( V_103 . V_118 ) {
if ( ( 1 << ( V_117 & 7 ) ) & V_103 . V_119 [ V_117 >> 3 ] )
F_42 ( V_4 , V_100 + ( V_117 << 8 ) ) ;
}
F_51 ( V_4 , V_117 , V_91 , V_92 ) ;
return;
}
case 0xcf :
{
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_116 ;
if ( V_113 ) {
V_120 = F_65 ( V_91 , V_92 , V_115 ) ;
V_121 = F_65 ( V_91 , V_92 , V_115 ) ;
V_116 = F_65 ( V_91 , V_92 , V_115 ) ;
F_56 ( V_4 ) += 12 ;
} else {
V_120 = F_66 ( V_91 , V_92 , V_115 ) ;
V_121 = F_66 ( V_91 , V_92 , V_115 ) ;
V_116 = F_66 ( V_91 , V_92 , V_115 ) ;
F_56 ( V_4 ) += 6 ;
}
F_55 ( V_4 ) = V_120 ;
V_4 -> V_6 . V_95 = V_121 ;
F_61 ;
if ( V_113 ) {
F_47 ( V_116 , V_4 ) ;
} else {
F_48 ( V_116 , V_4 ) ;
}
F_62 ;
}
case 0xfa :
F_55 ( V_4 ) = V_111 ;
F_44 ( V_4 ) ;
F_62 ;
case 0xfb :
F_55 ( V_4 ) = V_111 ;
F_43 ( V_4 ) ;
F_62 ;
default:
F_42 ( V_4 , V_122 ) ;
}
return;
V_115:
F_42 ( V_4 , V_122 ) ;
}
static T_7 F_67 ( int V_117 , void * V_123 )
{
int V_124 ;
unsigned long V_18 ;
F_68 ( & V_125 , V_18 ) ;
V_124 = 1 << V_117 ;
if ( ( V_126 & V_124 ) || ! V_127 [ V_117 ] . V_48 )
goto V_42;
V_126 |= V_124 ;
if ( V_127 [ V_117 ] . V_128 )
F_69 ( V_127 [ V_117 ] . V_128 , V_127 [ V_117 ] . V_48 , 1 ) ;
F_70 ( V_117 ) ;
F_71 ( & V_125 , V_18 ) ;
return V_129 ;
V_42:
F_71 ( & V_125 , V_18 ) ;
return V_130 ;
}
static inline void F_72 ( int V_131 )
{
unsigned long V_18 ;
F_73 ( V_131 , NULL ) ;
V_127 [ V_131 ] . V_48 = NULL ;
F_68 ( & V_125 , V_18 ) ;
V_126 &= ~ ( 1 << V_131 ) ;
F_71 ( & V_125 , V_18 ) ;
}
void F_74 ( struct V_47 * V_132 )
{
int V_40 ;
for ( V_40 = V_133 ; V_40 <= V_134 ; V_40 ++ )
if ( V_127 [ V_40 ] . V_48 == V_132 )
F_72 ( V_40 ) ;
}
static inline int F_75 ( int V_131 )
{
int V_135 ;
unsigned long V_18 ;
int V_5 = 0 ;
if ( F_76 ( V_131 ) ) return 0 ;
if ( V_127 [ V_131 ] . V_48 != V_14 ) return 0 ;
F_68 ( & V_125 , V_18 ) ;
V_135 = V_126 & ( 1 << V_131 ) ;
V_126 &= ~ V_135 ;
if ( V_135 ) {
F_77 ( V_131 ) ;
V_5 = 1 ;
}
F_71 ( & V_125 , V_18 ) ;
return V_5 ;
}
static int F_36 ( int V_136 , int V_131 )
{
int V_5 ;
switch ( V_136 ) {
case V_58 : {
return F_75 ( V_131 ) ;
}
case V_57 : {
return V_126 ;
}
case V_55 : {
int V_128 = V_131 >> 8 ;
int V_137 = V_131 & 255 ;
if ( ! F_78 ( V_138 ) ) return - V_49 ;
if ( ! ( ( 1 << V_128 ) & V_139 ) ) return - V_49 ;
if ( F_76 ( V_137 ) ) return - V_49 ;
if ( V_127 [ V_137 ] . V_48 ) return - V_49 ;
V_5 = F_79 ( V_137 , & F_67 , 0 , V_140 , NULL ) ;
if ( V_5 ) return V_5 ;
V_127 [ V_137 ] . V_128 = V_128 ;
V_127 [ V_137 ] . V_48 = V_14 ;
return V_137 ;
}
case V_56 : {
if ( F_76 ( V_131 ) ) return - V_49 ;
if ( ! V_127 [ V_131 ] . V_48 ) return 0 ;
if ( V_127 [ V_131 ] . V_48 != V_14 ) return - V_49 ;
F_72 ( V_131 ) ;
return 0 ;
}
}
return - V_141 ;
}
