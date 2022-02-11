static int T_1 F_1 ( char * V_1 )
{
long V_2 ;
if ( F_2 ( V_1 , 0 , & V_2 ) != 0 )
return 0 ;
V_3 = V_2 ;
F_3 ( L_1 ,
V_3 ? L_2 : L_3 ) ;
return 1 ;
}
static inline T_2 F_4 ( T_2 V_4 , T_3 V_5 )
{
T_2 V_6 ;
T_2 V_7 = F_5 ( - 1 ) ;
V_6 = V_4 & ( ~ V_7 ) ;
V_6 |= F_5 ( V_5 ) ;
return V_6 ;
}
static inline T_2 F_6 ( T_2 V_4 , int V_8 , int V_9 )
{
T_2 V_6 ;
T_2 V_10 ;
V_6 = V_4 & ( ~ V_11 ) ;
V_10 = F_7 ( V_12 ) |
F_8 ( V_13 ) |
F_9 ( V_8 ) |
F_10 ( V_14 ) |
F_11 ( V_9 ) ;
V_6 |= V_10 ;
return V_6 ;
}
static inline T_2 F_12 ( T_2 V_4 )
{
return F_6 ( V_4 , V_14 , V_14 ) ;
}
static inline T_2 F_13 (
T_2 V_4 , int V_8 , int V_9 , int V_15 )
{
V_4 &= ~ V_11 ;
V_4 |= ( F_11 ( V_9 ) |
F_9 ( V_8 ) |
F_14 ( V_15 ) |
F_15 ( 0 ) |
F_7 ( V_16 ) |
F_16 ( V_17 ) ) ;
return V_4 ;
}
static T_2 F_17 (
struct V_18 * V_19 ,
T_2 V_20 ,
struct V_21 * V_22 ,
enum V_23 V_23 ,
int V_24 , int V_25 )
{
unsigned char T_4 * V_26 ;
int V_27 , V_28 , V_29 , V_2 ;
if ( V_20 & V_30 ) {
V_28 = F_18 ( V_20 ) ;
V_27 = F_19 ( V_20 ) ;
} else if ( V_23 == V_31 || V_23 == V_32 ) {
V_28 = F_20 ( V_20 ) ;
V_27 = F_21 ( V_20 ) ;
} else {
V_28 = F_20 ( V_20 ) ;
V_27 = F_22 ( V_20 ) ;
}
if ( ( V_27 >= V_33 &&
( V_27 != V_14 ||
V_23 == V_31 ||
V_23 == V_32 ) ) ||
V_28 >= V_33 )
return V_20 ;
V_26 = ( void T_4 * ) V_22 -> V_22 [ V_28 ] ;
if ( ( ( unsigned long ) V_26 % V_24 ) == 0 )
return V_20 ;
#ifndef F_23
# error We assume little-endian representation with copy_xx_user size 2 here
#endif
if ( V_23 == V_31 || V_23 == V_32 ) {
unsigned short V_34 ;
switch ( V_24 ) {
case 2 :
V_29 = F_24 ( & V_34 , V_26 , sizeof( V_34 ) ) ;
V_2 = V_25 ? ( ( short ) V_34 ) : V_34 ;
break;
case 4 :
V_29 = F_24 ( & V_2 , V_26 , sizeof( V_2 ) ) ;
break;
default:
F_25 () ;
}
if ( V_29 == 0 ) {
V_19 -> V_35 = V_27 ;
V_19 -> V_36 = V_2 ;
V_19 -> V_37 = 1 ;
}
} else {
V_2 = ( V_27 == V_14 ) ? 0 : V_22 -> V_22 [ V_27 ] ;
V_29 = F_26 ( V_26 , & V_2 , V_24 ) ;
}
if ( V_29 ) {
T_5 V_38 = {
. V_39 = V_40 ,
. V_41 = V_42 ,
. V_43 = V_26
} ;
F_27 ( L_4 , V_22 ,
( unsigned long ) V_26 , V_40 ) ;
F_28 ( V_38 . V_39 , & V_38 , V_44 ) ;
return ( T_2 ) 0 ;
}
if ( V_45 == 0 ) {
T_5 V_38 = {
. V_39 = V_46 ,
. V_41 = V_47 ,
. V_43 = V_26
} ;
F_27 ( L_5 , V_22 ,
( unsigned long ) V_26 , V_46 ) ;
F_28 ( V_38 . V_39 , & V_38 , V_44 ) ;
return ( T_2 ) 0 ;
}
if ( V_3 || V_48 == 0 ) {
F_3 ( L_6
L_7 ,
V_44 -> V_49 , V_44 -> V_50 , V_22 -> V_51 ,
( V_23 == V_31 ||
V_23 == V_32 ) ?
L_8 : L_9 ,
( unsigned long ) V_26 ) ;
if ( ! V_3 ) {
#define F_29 pr_info
F_29 ( L_10 ) ;
F_29 ( L_11 ) ;
F_29 ( L_12 ) ;
F_29 ( L_13 ) ;
F_29 ( L_14 ) ;
F_29 ( L_15 ) ;
F_29 ( L_16 ) ;
F_29 ( L_17 ) ;
F_29 ( L_18 ) ;
F_29 ( L_10 ) ;
#undef F_29
}
}
++ V_48 ;
if ( V_20 & V_30 ) {
V_20 &= ~ ( F_30 ( - 1 ) |
F_31 ( - 1 ) ) ;
V_20 |= ( F_30 ( V_14 ) |
F_31 ( V_52 ) ) ;
} else if ( V_23 == V_32 ) {
V_20 = F_13 ( V_20 , V_28 , V_28 ,
F_32 ( V_20 ) ) ;
} else if ( V_23 == V_53 ) {
V_20 = F_13 ( V_20 , V_28 , V_28 ,
F_33 ( V_20 ) ) ;
} else {
V_20 &= ~ ( F_7 ( - 1 ) |
F_34 ( - 1 ) |
F_35 ( - 1 ) ) ;
V_20 |= ( F_7 ( V_54 ) |
F_34 (
V_55 ) |
F_35 (
V_56 ) ) ;
}
return V_20 ;
}
void F_36 ( void )
{
struct V_57 * V_58 = F_37 () ;
F_38 ( V_58 -> V_59 ) ;
V_58 -> V_59 = NULL ;
}
void F_39 ( struct V_21 * V_22 )
{
extern T_2 V_60 ;
extern T_2 V_61 ;
extern T_2 V_62 ;
extern T_2 V_63 ;
struct V_57 * V_38 = ( void * ) F_37 () ;
struct V_18 * V_19 = V_38 -> V_59 ;
int V_64 = F_40 ( V_38 , V_65 ) ;
T_2 T_4 * V_66 , * V_51 ;
T_2 V_20 ;
int V_67 ;
int V_68 = V_69 ;
int V_29 ;
enum V_23 V_23 = V_70 ;
int V_24 = 0 , V_25 = 0 ;
asm(
" .pushsection .rodata.single_step\n"
" .align 8\n"
" .globl __single_step_ill_insn\n"
"__single_step_ill_insn:\n"
" ill\n"
" .globl __single_step_addli_insn\n"
"__single_step_addli_insn:\n"
" { nop; addli r0, zero, 0 }\n"
" .globl __single_step_auli_insn\n"
"__single_step_auli_insn:\n"
" { nop; auli r0, r0, 0 }\n"
" .globl __single_step_j_insn\n"
"__single_step_j_insn:\n"
" j .\n"
" .popsection\n"
);
F_41 () ;
if ( V_19 == NULL ) {
V_19 = F_42 ( sizeof( struct V_18 ) , V_71 ) ;
if ( V_19 == NULL ) {
F_43 ( L_19 ) ;
return;
}
F_44 ( & V_44 -> V_72 -> V_73 ) ;
V_66 = ( void T_4 * ) F_45 ( NULL , 0 , 64 ,
V_74 | V_75 | V_76 ,
V_77 | V_78 ,
0 ) ;
F_46 ( & V_44 -> V_72 -> V_73 ) ;
if ( F_47 ( ( void V_79 * ) V_66 ) ) {
F_38 ( V_19 ) ;
F_43 ( L_20 ) ;
return;
}
V_19 -> V_66 = V_66 ;
V_19 -> V_80 = 0 ;
V_38 -> V_59 = V_19 ;
F_48 ( F_49 ( V_62 ) !=
V_81 ) ;
F_48 ( F_49 ( V_63 ) !=
V_82 ) ;
F_48 ( F_20 ( V_62 ) != V_14 ) ;
F_48 ( F_21 ( V_62 ) != 0 ) ;
F_48 ( F_50 ( V_61 ) != 0 ) ;
}
if ( V_22 -> V_83 == V_84 )
V_22 -> V_51 -= 8 ;
V_51 = ( T_2 T_4 * ) ( V_22 -> V_51 ) ;
if ( F_51 ( V_20 , V_51 ) != 0 ) {
F_43 ( L_21 , V_51 ) ;
return;
}
V_19 -> V_85 = ( unsigned long ) V_51 ;
V_19 -> V_86 = ( unsigned long ) ( V_51 + 1 ) ;
V_19 -> V_87 = 0 ;
V_19 -> V_37 = 0 ;
if ( ! ( V_20 & V_30 ) ) {
int V_88 = F_49 ( V_20 ) ;
switch ( V_88 ) {
case V_89 :
{
T_3 V_5 = F_52 ( F_53 ( V_20 ) ) ;
V_19 -> V_87 = ( unsigned long ) ( V_51 + V_5 ) ;
V_20 = F_4 ( V_20 , 2 ) ;
}
break;
case V_90 :
case V_91 :
V_19 -> V_37 = 1 ;
V_19 -> V_86 =
( unsigned long ) ( V_51 + F_50 ( V_20 ) ) ;
break;
case V_92 :
case V_93 :
V_19 -> V_86 =
( unsigned long ) ( V_51 + F_50 ( V_20 ) ) ;
V_20 = F_12 ( V_20 ) ;
break;
case V_12 :
switch ( F_54 ( V_20 ) ) {
case V_94 :
case V_95 :
V_19 -> V_37 = 1 ;
V_19 -> V_86 =
V_22 -> V_22 [ F_20 ( V_20 ) ] ;
break;
case V_96 :
case V_97 :
V_19 -> V_86 =
V_22 -> V_22 [ F_20 ( V_20 ) ] ;
V_20 = F_12 ( V_20 ) ;
break;
case V_98 :
V_19 -> V_37 = 1 ;
V_68 = F_21 ( V_20 ) ;
break;
case V_99 :
V_23 = V_100 ;
V_24 = 2 ;
break;
case V_101 :
V_23 = V_100 ;
V_24 = 4 ;
break;
}
break;
case V_54 :
if ( F_55 ( V_20 ) ==
V_55 ) {
switch ( F_56 ( V_20 ) ) {
case V_102 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_103 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_104 :
V_23 = V_31 ;
V_24 = 4 ;
break;
case V_105 :
{
unsigned long V_106 = F_57 (
V_107 ) ;
unsigned long V_108 = F_57 (
V_109 ) ;
if ( F_58 ( V_108 ) == V_110 ) {
V_19 -> V_86 = V_106 ;
V_22 -> V_111 = V_108 ;
V_20 = F_12 ( V_20 ) ;
}
}
}
}
break;
#if F_59 ()
case V_16 :
switch ( F_60 ( V_20 ) ) {
case V_112 :
V_23 = V_32 ;
V_24 = 4 ;
break;
case V_113 :
V_23 = V_32 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_114 :
V_23 = V_32 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_115 :
V_23 = V_53 ;
V_24 = 4 ;
break;
case V_116 :
V_23 = V_53 ;
V_24 = 2 ;
break;
default:
break;
}
break;
#endif
}
if ( V_19 -> V_37 ) {
T_6 V_7 = ( T_6 ) ~ ( ( 1ULL << F_61 ( V_20 ) ) |
( 1ULL << F_62 ( V_20 ) ) |
( 1ULL << F_63 ( V_20 ) ) |
( 1ULL << V_68 ) ) ;
V_67 = F_64 ( V_7 ) ;
V_19 -> V_35 = V_67 ;
V_19 -> V_36 = V_22 -> V_22 [ V_67 ] ;
V_22 -> V_22 [ V_67 ] = ( unsigned long ) ( V_51 + 1 ) ;
V_22 -> V_117 |= V_118 ;
V_20 = F_6 ( V_20 , V_68 , V_67 ) ;
}
} else {
int V_88 = F_65 ( V_20 ) ;
switch ( V_88 ) {
case V_119 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_120 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_52 :
V_23 = V_31 ;
V_24 = 4 ;
break;
case V_121 :
V_23 = V_100 ;
V_24 = 2 ;
break;
case V_122 :
V_23 = V_100 ;
V_24 = 4 ;
break;
}
}
if ( V_23 != V_70 && V_45 >= 0 ) {
V_20 = F_17 ( V_19 , V_20 , V_22 ,
V_23 , V_24 , V_25 ) ;
if ( V_20 == 0 )
return;
}
V_66 = V_19 -> V_66 ;
V_29 = F_66 ( V_20 , V_66 ++ ) ;
if ( V_64 ) {
V_29 |= F_66 ( V_60 , V_66 ++ ) ;
V_29 |= F_66 ( V_60 , V_66 ++ ) ;
} else {
long V_123 ;
if ( V_19 -> V_37 ) {
int V_124 ;
V_20 = V_62 ;
V_20 |= F_9 ( V_19 -> V_35 ) ;
V_20 |= F_67 ( V_19 -> V_36 ) ;
V_29 |= F_66 ( V_20 , V_66 ++ ) ;
V_20 = V_63 ;
V_20 |= F_9 ( V_19 -> V_35 ) ;
V_20 |= F_11 ( V_19 -> V_35 ) ;
V_124 = ( V_19 -> V_36 + 0x8000 ) >> 16 ;
V_20 |= F_67 ( V_124 ) ;
V_29 |= F_66 ( V_20 , V_66 ++ ) ;
V_19 -> V_37 = 0 ;
}
V_123 = ( ( V_22 -> V_51 + V_125 ) -
( unsigned long ) V_66 ) >>
V_126 ;
V_20 = V_61 ;
V_20 |= F_68 ( V_123 ) ;
V_29 |= F_66 ( V_20 , V_66 ++ ) ;
}
if ( V_29 ) {
F_43 ( L_22 ) ;
return;
}
F_69 ( ( unsigned long ) V_19 -> V_66 ,
( unsigned long ) V_66 ) ;
V_19 -> V_80 = V_64 ;
V_22 -> V_51 = ( unsigned long ) V_19 -> V_66 ;
if ( V_22 -> V_83 == V_84 )
V_22 -> V_51 += 8 ;
}
void F_70 ( struct V_21 * V_22 , int V_127 )
{
unsigned long * V_128 = & F_71 ( V_129 ) ;
struct V_57 * V_38 = ( void * ) F_37 () ;
int V_64 = F_40 ( V_38 , V_65 ) ;
unsigned long V_130 = F_57 ( V_131 ) ;
if ( V_64 == 0 ) {
F_72 ( V_132 , 0 ) ;
} else if ( ( * V_128 != V_22 -> V_51 ) ||
( ! ( V_130 & V_133 ) ) ) {
F_73 ( V_134 ) ;
V_130 |= V_133 ;
V_130 |= V_135 ;
F_72 ( V_131 , V_130 ) ;
}
}
void F_39 ( struct V_21 * V_22 )
{
unsigned long * V_128 = & F_71 ( V_129 ) ;
unsigned long V_130 = F_57 ( V_131 ) ;
* V_128 = V_22 -> V_51 ;
V_130 |= V_133 ;
V_130 |= V_135 ;
F_72 ( V_131 , V_130 ) ;
F_72 ( V_132 , 1 << V_110 ) ;
}
void F_36 ( void )
{
}
