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
if ( V_34 == 0 ) {
T_5 V_35 = {
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_26
} ;
F_23 ( L_4 , V_22 ,
( unsigned long ) V_26 , V_37 ) ;
F_24 ( V_35 . V_36 , & V_35 , V_41 ) ;
return ( V_42 ) 0 ;
}
if ( V_23 == V_31 || V_23 == V_32 ) {
unsigned short V_43 ;
switch ( V_24 ) {
case 2 :
V_29 = F_25 ( & V_43 , V_26 , sizeof( V_43 ) ) ;
V_2 = V_25 ? ( ( short ) V_43 ) : V_43 ;
break;
case 4 :
V_29 = F_25 ( & V_2 , V_26 , sizeof( V_2 ) ) ;
break;
default:
F_26 () ;
}
if ( V_29 == 0 ) {
V_19 -> V_44 = V_27 ;
V_19 -> V_45 = V_2 ;
V_19 -> V_46 = 1 ;
}
} else {
unsigned short V_43 ;
V_2 = ( V_27 == V_14 ) ? 0 : V_22 -> V_22 [ V_27 ] ;
switch ( V_24 ) {
case 2 :
V_43 = V_2 ;
V_29 = F_27 ( V_26 , & V_43 , sizeof( V_43 ) ) ;
break;
case 4 :
V_29 = F_27 ( V_26 , & V_2 , sizeof( V_2 ) ) ;
break;
default:
F_26 () ;
}
}
if ( V_29 ) {
T_5 V_35 = {
. V_36 = V_47 ,
. V_38 = V_48 ,
. V_40 = V_26
} ;
F_23 ( L_5 , V_22 ,
( unsigned long ) V_26 , V_47 ) ;
F_24 ( V_35 . V_36 , & V_35 , V_41 ) ;
return ( T_2 ) 0 ;
}
if ( V_3 || V_49 == 0 ) {
F_3 ( L_6
L_7 ,
V_41 -> V_50 , V_41 -> V_51 , V_22 -> V_52 ,
( V_23 == V_31 ||
V_23 == V_32 ) ?
L_8 : L_9 ,
( unsigned long ) V_26 ) ;
if ( ! V_3 ) {
#define F_28 pr_info
F_28 ( L_10 ) ;
F_28 ( L_11 ) ;
F_28 ( L_12 ) ;
F_28 ( L_13 ) ;
F_28 ( L_14 ) ;
F_28 ( L_15 ) ;
F_28 ( L_16 ) ;
F_28 ( L_17 ) ;
F_28 ( L_18 ) ;
F_28 ( L_10 ) ;
#undef F_28
}
}
++ V_49 ;
if ( V_20 & V_30 ) {
V_20 &= ~ ( F_29 ( - 1 ) |
F_30 ( - 1 ) ) ;
V_20 |= ( F_29 ( V_14 ) |
F_30 ( V_53 ) ) ;
} else if ( V_23 == V_32 ) {
V_20 = F_13 ( V_20 , V_28 , V_28 ,
F_31 ( V_20 ) ) ;
} else if ( V_23 == V_54 ) {
V_20 = F_13 ( V_20 , V_28 , V_28 ,
F_32 ( V_20 ) ) ;
} else {
V_20 &= ~ ( F_7 ( - 1 ) |
F_33 ( - 1 ) |
F_34 ( - 1 ) ) ;
V_20 |= ( F_7 ( V_55 ) |
F_33 (
V_56 ) |
F_34 (
V_57 ) ) ;
}
return V_20 ;
}
void F_35 ( void )
{
struct V_58 * V_59 = F_36 () ;
F_37 ( V_59 -> V_60 ) ;
V_59 -> V_60 = NULL ;
}
void F_38 ( struct V_21 * V_22 )
{
extern T_2 V_61 ;
extern T_2 V_62 ;
extern T_2 V_63 ;
extern T_2 V_64 ;
struct V_58 * V_35 = ( void * ) F_36 () ;
struct V_18 * V_19 = V_35 -> V_60 ;
int V_65 = F_39 ( V_35 , V_66 ) ;
T_2 T_4 * V_67 , * V_52 ;
T_2 V_20 ;
int V_68 ;
int V_69 = V_70 ;
int V_29 ;
enum V_23 V_23 = V_71 ;
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
F_40 () ;
if ( V_19 == NULL ) {
V_19 = F_41 ( sizeof( struct V_18 ) , V_72 ) ;
if ( V_19 == NULL ) {
F_42 ( L_19 ) ;
return;
}
V_67 = ( void T_4 * ) F_43 ( NULL , 0 , 64 ,
V_73 | V_74 | V_75 ,
V_76 | V_77 ,
0 ) ;
if ( F_44 ( ( void V_78 * ) V_67 ) ) {
F_37 ( V_19 ) ;
F_42 ( L_20 ) ;
return;
}
V_19 -> V_67 = V_67 ;
V_19 -> V_79 = 0 ;
V_35 -> V_60 = V_19 ;
F_45 ( F_46 ( V_63 ) !=
V_80 ) ;
F_45 ( F_46 ( V_64 ) !=
V_81 ) ;
F_45 ( F_20 ( V_63 ) != V_14 ) ;
F_45 ( F_21 ( V_63 ) != 0 ) ;
F_45 ( F_47 ( V_62 ) != 0 ) ;
}
if ( V_22 -> V_82 == V_83 )
V_22 -> V_52 -= 8 ;
V_52 = ( T_2 T_4 * ) ( V_22 -> V_52 ) ;
if ( F_48 ( V_20 , V_52 ) != 0 ) {
F_42 ( L_21 , V_52 ) ;
return;
}
V_19 -> V_84 = ( unsigned long ) V_52 ;
V_19 -> V_85 = ( unsigned long ) ( V_52 + 1 ) ;
V_19 -> V_86 = 0 ;
V_19 -> V_46 = 0 ;
if ( ! ( V_20 & V_30 ) ) {
int V_87 = F_46 ( V_20 ) ;
switch ( V_87 ) {
case V_88 :
{
T_3 V_5 = F_49 ( F_50 ( V_20 ) ) ;
V_19 -> V_86 = ( unsigned long ) ( V_52 + V_5 ) ;
V_20 = F_4 ( V_20 , 2 ) ;
}
break;
case V_89 :
case V_90 :
V_19 -> V_46 = 1 ;
V_19 -> V_85 =
( unsigned long ) ( V_52 + F_47 ( V_20 ) ) ;
break;
case V_91 :
case V_92 :
V_19 -> V_85 =
( unsigned long ) ( V_52 + F_47 ( V_20 ) ) ;
V_20 = F_12 ( V_20 ) ;
break;
case V_12 :
switch ( F_51 ( V_20 ) ) {
case V_93 :
case V_94 :
V_19 -> V_46 = 1 ;
V_19 -> V_85 =
V_22 -> V_22 [ F_20 ( V_20 ) ] ;
break;
case V_95 :
case V_96 :
V_19 -> V_85 =
V_22 -> V_22 [ F_20 ( V_20 ) ] ;
V_20 = F_12 ( V_20 ) ;
break;
case V_97 :
V_19 -> V_46 = 1 ;
V_69 = F_21 ( V_20 ) ;
break;
case V_98 :
V_23 = V_99 ;
V_24 = 2 ;
break;
case V_100 :
V_23 = V_99 ;
V_24 = 4 ;
break;
}
break;
case V_55 :
if ( F_52 ( V_20 ) ==
V_56 ) {
switch ( F_53 ( V_20 ) ) {
case V_101 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_102 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_103 :
V_23 = V_31 ;
V_24 = 4 ;
break;
case V_104 :
{
unsigned long V_105 = F_54 (
V_106 ) ;
unsigned long V_107 = F_54 (
V_108 ) ;
if ( F_55 ( V_107 ) == V_109 ) {
V_19 -> V_85 = V_105 ;
V_22 -> V_110 = V_107 ;
V_20 = F_12 ( V_20 ) ;
}
}
}
}
break;
#if F_56 ()
case V_16 :
switch ( F_57 ( V_20 ) ) {
case V_111 :
V_23 = V_32 ;
V_24 = 4 ;
break;
case V_112 :
V_23 = V_32 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_113 :
V_23 = V_32 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_114 :
V_23 = V_54 ;
V_24 = 4 ;
break;
case V_115 :
V_23 = V_54 ;
V_24 = 2 ;
break;
default:
break;
}
break;
#endif
}
if ( V_19 -> V_46 ) {
T_6 V_7 = ( T_6 ) ~ ( ( 1ULL << F_58 ( V_20 ) ) |
( 1ULL << F_59 ( V_20 ) ) |
( 1ULL << F_60 ( V_20 ) ) |
( 1ULL << V_69 ) ) ;
V_68 = F_61 ( V_7 ) ;
V_19 -> V_44 = V_68 ;
V_19 -> V_45 = V_22 -> V_22 [ V_68 ] ;
V_22 -> V_22 [ V_68 ] = ( unsigned long ) ( V_52 + 1 ) ;
V_22 -> V_116 |= V_117 ;
V_20 = F_6 ( V_20 , V_69 , V_68 ) ;
}
} else {
int V_87 = F_62 ( V_20 ) ;
switch ( V_87 ) {
case V_118 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 1 ;
break;
case V_119 :
V_23 = V_31 ;
V_24 = 2 ;
V_25 = 0 ;
break;
case V_53 :
V_23 = V_31 ;
V_24 = 4 ;
break;
case V_120 :
V_23 = V_99 ;
V_24 = 2 ;
break;
case V_121 :
V_23 = V_99 ;
V_24 = 4 ;
break;
}
}
if ( V_23 != V_71 && V_34 >= 0 ) {
V_20 = F_17 ( V_19 , V_20 , V_22 ,
V_23 , V_24 , V_25 ) ;
if ( V_20 == 0 )
return;
}
V_67 = V_19 -> V_67 ;
V_29 = F_63 ( V_20 , V_67 ++ ) ;
if ( V_65 ) {
V_29 |= F_63 ( V_61 , V_67 ++ ) ;
V_29 |= F_63 ( V_61 , V_67 ++ ) ;
} else {
long V_122 ;
if ( V_19 -> V_46 ) {
int V_123 ;
V_20 = V_63 ;
V_20 |= F_9 ( V_19 -> V_44 ) ;
V_20 |= F_64 ( V_19 -> V_45 ) ;
V_29 |= F_63 ( V_20 , V_67 ++ ) ;
V_20 = V_64 ;
V_20 |= F_9 ( V_19 -> V_44 ) ;
V_20 |= F_11 ( V_19 -> V_44 ) ;
V_123 = ( V_19 -> V_45 + 0x8000 ) >> 16 ;
V_20 |= F_64 ( V_123 ) ;
V_29 |= F_63 ( V_20 , V_67 ++ ) ;
V_19 -> V_46 = 0 ;
}
V_122 = ( ( V_22 -> V_52 + V_124 ) -
( unsigned long ) V_67 ) >>
V_125 ;
V_20 = V_62 ;
V_20 |= F_65 ( V_122 ) ;
V_29 |= F_63 ( V_20 , V_67 ++ ) ;
}
if ( V_29 ) {
F_42 ( L_22 ) ;
return;
}
F_66 ( ( unsigned long ) V_19 -> V_67 ,
( unsigned long ) V_67 ) ;
V_19 -> V_79 = V_65 ;
V_22 -> V_52 = ( unsigned long ) V_19 -> V_67 ;
if ( V_22 -> V_82 == V_83 )
V_22 -> V_52 += 8 ;
}
void F_67 ( struct V_21 * V_22 , int V_126 )
{
unsigned long * V_127 = & F_68 ( V_128 ) ;
struct V_58 * V_35 = ( void * ) F_36 () ;
int V_65 = F_39 ( V_35 , V_66 ) ;
unsigned long V_129 = F_54 ( V_130 ) ;
if ( V_65 == 0 ) {
F_69 ( V_131 , 0 ) ;
} else if ( ( * V_127 != V_22 -> V_52 ) ||
( ! ( V_129 & V_132 ) ) ) {
F_70 ( V_133 ) ;
V_129 |= V_132 ;
V_129 |= V_134 ;
F_69 ( V_130 , V_129 ) ;
}
}
void F_38 ( struct V_21 * V_22 )
{
unsigned long * V_127 = & F_68 ( V_128 ) ;
unsigned long V_129 = F_54 ( V_130 ) ;
* V_127 = V_22 -> V_52 ;
V_129 |= V_132 ;
V_129 |= V_134 ;
F_69 ( V_130 , V_129 ) ;
F_69 ( V_131 , 1 << V_109 ) ;
}
void F_35 ( void )
{
}
