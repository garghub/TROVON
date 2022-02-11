static inline T_1 F_1 ( T_1 V_1 ,
T_2 V_2 )
{
T_1 V_3 ;
T_1 V_4 = F_2 ( - 1 ) ;
V_3 = V_1 & ( ~ V_4 ) ;
V_3 |= F_2 ( V_2 ) ;
return V_3 ;
}
static inline T_1 F_3 ( T_1 V_1 , int V_5 ,
int V_6 )
{
T_1 V_3 ;
T_1 V_7 ;
V_3 = V_1 & ( ~ V_8 ) ;
V_7 = F_4 ( V_9 ) |
F_5 ( V_10 ) |
F_6 ( V_5 ) |
F_7 ( V_11 ) |
F_8 ( V_6 ) ;
V_3 |= V_7 ;
return V_3 ;
}
static inline T_1 F_9 ( T_1 V_1 )
{
return F_3 ( V_1 , V_11 , V_11 ) ;
}
static inline T_1 F_10 (
T_1 V_1 , int V_5 , int V_6 , int V_12 )
{
V_1 &= ~ V_8 ;
V_1 |= ( F_8 ( V_6 ) |
F_6 ( V_5 ) |
F_11 ( V_12 ) |
F_12 ( 0 ) |
F_4 ( V_13 ) |
F_13 ( V_14 ) ) ;
return V_1 ;
}
static T_1 F_14 (
struct V_15 * V_16 ,
T_1 V_17 ,
struct V_18 * V_19 ,
enum V_20 V_20 ,
int V_21 , int V_22 )
{
unsigned char T_3 * V_23 ;
int V_24 , V_25 , V_26 , V_27 ;
int V_28 ;
V_28 = V_29 ;
switch ( F_15 ( V_30 ) -> V_28 ) {
case V_31 :
V_28 = 1 ;
break;
case V_32 :
V_28 = 0 ;
break;
}
if ( V_17 & V_33 ) {
V_25 = F_16 ( V_17 ) ;
V_24 = F_17 ( V_17 ) ;
} else if ( V_20 == V_34 || V_20 == V_35 ) {
V_25 = F_18 ( V_17 ) ;
V_24 = F_19 ( V_17 ) ;
} else {
V_25 = F_18 ( V_17 ) ;
V_24 = F_20 ( V_17 ) ;
}
if ( ( V_24 >= V_36 &&
( V_24 != V_11 ||
V_20 == V_34 ||
V_20 == V_35 ) ) ||
V_25 >= V_36 )
return V_17 ;
V_23 = ( void T_3 * ) V_19 -> V_19 [ V_25 ] ;
if ( ( ( unsigned long ) V_23 % V_21 ) == 0 )
return V_17 ;
if ( V_28 == 0 ) {
T_4 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_23
} ;
F_21 ( L_1 , V_19 ,
( unsigned long ) V_23 , V_39 ) ;
F_22 ( V_37 . V_38 , & V_37 , V_30 ) ;
return ( T_1 ) 0 ;
}
if ( V_20 == V_34 || V_20 == V_35 ) {
unsigned short V_43 ;
switch ( V_21 ) {
case 2 :
V_26 = F_23 ( & V_43 , V_23 , sizeof( V_43 ) ) ;
V_27 = V_22 ? ( ( short ) V_43 ) : V_43 ;
break;
case 4 :
V_26 = F_23 ( & V_27 , V_23 , sizeof( V_27 ) ) ;
break;
default:
F_24 () ;
}
if ( V_26 == 0 ) {
V_16 -> V_44 = V_24 ;
V_16 -> V_45 = V_27 ;
V_16 -> V_46 = 1 ;
}
} else {
unsigned short V_43 ;
V_27 = ( V_24 == V_11 ) ? 0 : V_19 -> V_19 [ V_24 ] ;
switch ( V_21 ) {
case 2 :
V_43 = V_27 ;
V_26 = F_25 ( V_23 , & V_43 , sizeof( V_43 ) ) ;
break;
case 4 :
V_26 = F_25 ( V_23 , & V_27 , sizeof( V_27 ) ) ;
break;
default:
F_24 () ;
}
}
if ( V_26 ) {
T_4 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_23
} ;
F_21 ( L_2 , V_19 ,
( unsigned long ) V_23 , V_39 ) ;
F_22 ( V_37 . V_38 , & V_37 , V_30 ) ;
return ( T_1 ) 0 ;
}
if ( V_47 || V_48 == 0 ) {
F_26 ( L_3
L_4 ,
V_30 -> V_49 , V_30 -> V_50 , V_19 -> V_51 ,
( V_20 == V_34 ||
V_20 == V_35 ) ?
L_5 : L_6 ,
( unsigned long ) V_23 ) ;
if ( ! V_47 ) {
#define F_27 pr_info
F_27 ( L_7 ) ;
F_27 ( L_8 ) ;
F_27 ( L_9 ) ;
F_27 ( L_10 ) ;
F_27 ( L_11 ) ;
F_27 ( L_12 ) ;
F_27 ( L_13 ) ;
F_27 ( L_14 ) ;
F_27 ( L_15 ) ;
F_27 ( L_7 ) ;
#undef F_27
}
}
++ V_48 ;
if ( V_17 & V_33 ) {
V_17 &= ~ ( F_28 ( - 1 ) |
F_29 ( - 1 ) ) ;
V_17 |= ( F_28 ( V_11 ) |
F_29 ( V_52 ) ) ;
} else if ( V_20 == V_35 ) {
V_17 = F_10 ( V_17 , V_25 , V_25 ,
F_30 ( V_17 ) ) ;
} else if ( V_20 == V_53 ) {
V_17 = F_10 ( V_17 , V_25 , V_25 ,
F_31 ( V_17 ) ) ;
} else {
V_17 &= ~ ( F_4 ( - 1 ) |
F_32 ( - 1 ) |
F_33 ( - 1 ) ) ;
V_17 |= ( F_4 ( V_54 ) |
F_32 (
V_55 ) |
F_33 (
V_56 ) ) ;
}
return V_17 ;
}
void F_34 ( void )
{
struct V_57 * V_58 = F_35 () ;
F_36 ( V_58 -> V_59 ) ;
V_58 -> V_59 = NULL ;
}
void F_37 ( struct V_18 * V_19 )
{
extern T_1 V_60 ;
extern T_1 V_61 ;
extern T_1 V_62 ;
extern T_1 V_63 ;
struct V_57 * V_37 = ( void * ) F_35 () ;
struct V_15 * V_16 = V_37 -> V_59 ;
int V_64 = F_38 ( V_37 , V_65 ) ;
T_1 T_3 * V_66 , * V_51 ;
T_1 V_17 ;
int V_67 ;
int V_68 = V_69 ;
int V_26 ;
enum V_20 V_20 = V_70 ;
int V_21 = 0 , V_22 = 0 ;
int V_28 ;
V_28 = V_29 ;
switch ( F_15 ( V_30 ) -> V_28 ) {
case V_31 :
V_28 = 1 ;
break;
case V_32 :
V_28 = 0 ;
break;
}
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
F_39 () ;
if ( V_16 == NULL ) {
V_16 = F_40 ( sizeof( struct V_15 ) , V_71 ) ;
if ( V_16 == NULL ) {
F_41 ( L_16 ) ;
return;
}
V_66 = ( void T_3 * ) F_42 ( NULL , 0 , 64 ,
V_72 | V_73 | V_74 ,
V_75 | V_76 ,
0 ) ;
if ( F_43 ( ( void V_77 * ) V_66 ) ) {
F_36 ( V_16 ) ;
F_41 ( L_17 ) ;
return;
}
V_16 -> V_66 = V_66 ;
V_16 -> V_78 = 0 ;
V_37 -> V_59 = V_16 ;
F_44 ( F_45 ( V_62 ) !=
V_79 ) ;
F_44 ( F_45 ( V_63 ) !=
V_80 ) ;
F_44 ( F_18 ( V_62 ) != V_11 ) ;
F_44 ( F_19 ( V_62 ) != 0 ) ;
F_44 ( F_46 ( V_61 ) != 0 ) ;
}
if ( V_19 -> V_81 == V_82 )
V_19 -> V_51 -= 8 ;
V_51 = ( T_1 T_3 * ) ( V_19 -> V_51 ) ;
if ( F_47 ( V_17 , V_51 ) != 0 ) {
F_41 ( L_18 , V_51 ) ;
return;
}
V_16 -> V_83 = ( unsigned long ) V_51 ;
V_16 -> V_84 = ( unsigned long ) ( V_51 + 1 ) ;
V_16 -> V_85 = 0 ;
V_16 -> V_46 = 0 ;
if ( ! ( V_17 & V_33 ) ) {
int V_86 = F_45 ( V_17 ) ;
switch ( V_86 ) {
case V_87 :
{
T_2 V_2 = F_48 ( F_49 ( V_17 ) ) ;
V_16 -> V_85 = ( unsigned long ) ( V_51 + V_2 ) ;
V_17 = F_1 ( V_17 , 2 ) ;
}
break;
case V_88 :
case V_89 :
V_16 -> V_46 = 1 ;
V_16 -> V_84 =
( unsigned long ) ( V_51 + F_46 ( V_17 ) ) ;
break;
case V_90 :
case V_91 :
V_16 -> V_84 =
( unsigned long ) ( V_51 + F_46 ( V_17 ) ) ;
V_17 = F_9 ( V_17 ) ;
break;
case V_9 :
switch ( F_50 ( V_17 ) ) {
case V_92 :
case V_93 :
V_16 -> V_46 = 1 ;
V_16 -> V_84 =
V_19 -> V_19 [ F_18 ( V_17 ) ] ;
break;
case V_94 :
case V_95 :
V_16 -> V_84 =
V_19 -> V_19 [ F_18 ( V_17 ) ] ;
V_17 = F_9 ( V_17 ) ;
break;
case V_96 :
V_16 -> V_46 = 1 ;
V_68 = F_19 ( V_17 ) ;
break;
case V_97 :
V_20 = V_98 ;
V_21 = 2 ;
break;
case V_99 :
V_20 = V_98 ;
V_21 = 4 ;
break;
}
break;
case V_54 :
if ( F_51 ( V_17 ) ==
V_55 ) {
switch ( F_52 ( V_17 ) ) {
case V_100 :
V_20 = V_34 ;
V_21 = 2 ;
V_22 = 1 ;
break;
case V_101 :
V_20 = V_34 ;
V_21 = 2 ;
V_22 = 0 ;
break;
case V_102 :
V_20 = V_34 ;
V_21 = 4 ;
break;
case V_103 :
{
unsigned long V_104 = F_53 (
V_105 ) ;
unsigned long V_106 = F_53 (
V_107 ) ;
if ( F_54 ( V_106 ) == V_108 ) {
V_16 -> V_84 = V_104 ;
V_19 -> V_109 = V_106 ;
V_17 = F_9 ( V_17 ) ;
}
}
}
}
break;
case V_13 :
switch ( F_55 ( V_17 ) ) {
case V_110 :
V_20 = V_35 ;
V_21 = 4 ;
break;
case V_111 :
V_20 = V_35 ;
V_21 = 2 ;
V_22 = 1 ;
break;
case V_112 :
V_20 = V_35 ;
V_21 = 2 ;
V_22 = 0 ;
break;
case V_113 :
V_20 = V_53 ;
V_21 = 4 ;
break;
case V_114 :
V_20 = V_53 ;
V_21 = 2 ;
break;
default:
break;
}
break;
}
if ( V_16 -> V_46 ) {
T_5 V_4 = ( T_5 ) ~ ( ( 1ULL << F_56 ( V_17 ) ) |
( 1ULL << F_57 ( V_17 ) ) |
( 1ULL << F_58 ( V_17 ) ) |
( 1ULL << V_68 ) ) ;
V_67 = F_59 ( V_4 ) ;
V_16 -> V_44 = V_67 ;
V_16 -> V_45 = V_19 -> V_19 [ V_67 ] ;
V_19 -> V_19 [ V_67 ] = ( unsigned long ) ( V_51 + 1 ) ;
V_19 -> V_115 |= V_116 ;
V_17 = F_3 ( V_17 , V_68 , V_67 ) ;
}
} else {
int V_86 = F_60 ( V_17 ) ;
switch ( V_86 ) {
case V_117 :
V_20 = V_34 ;
V_21 = 2 ;
V_22 = 1 ;
break;
case V_118 :
V_20 = V_34 ;
V_21 = 2 ;
V_22 = 0 ;
break;
case V_52 :
V_20 = V_34 ;
V_21 = 4 ;
break;
case V_119 :
V_20 = V_98 ;
V_21 = 2 ;
break;
case V_120 :
V_20 = V_98 ;
V_21 = 4 ;
break;
}
}
if ( V_20 != V_70 && V_28 >= 0 ) {
V_17 = F_14 ( V_16 , V_17 , V_19 ,
V_20 , V_21 , V_22 ) ;
if ( V_17 == 0 )
return;
}
V_66 = V_16 -> V_66 ;
V_26 = F_61 ( V_17 , V_66 ++ ) ;
if ( V_64 ) {
V_26 |= F_61 ( V_60 , V_66 ++ ) ;
V_26 |= F_61 ( V_60 , V_66 ++ ) ;
} else {
long V_121 ;
if ( V_16 -> V_46 ) {
int V_122 ;
V_17 = V_62 ;
V_17 |= F_6 ( V_16 -> V_44 ) ;
V_17 |= F_62 ( V_16 -> V_45 ) ;
V_26 |= F_61 ( V_17 , V_66 ++ ) ;
V_17 = V_63 ;
V_17 |= F_6 ( V_16 -> V_44 ) ;
V_17 |= F_8 ( V_16 -> V_44 ) ;
V_122 = ( V_16 -> V_45 + 0x8000 ) >> 16 ;
V_17 |= F_62 ( V_122 ) ;
V_26 |= F_61 ( V_17 , V_66 ++ ) ;
V_16 -> V_46 = 0 ;
}
V_121 = ( ( V_19 -> V_51 + V_123 ) -
( unsigned long ) V_66 ) >>
V_124 ;
V_17 = V_61 ;
V_17 |= F_63 ( V_121 ) ;
V_26 |= F_61 ( V_17 , V_66 ++ ) ;
}
if ( V_26 ) {
F_41 ( L_19 ) ;
return;
}
F_64 ( ( unsigned long ) V_16 -> V_66 ,
( unsigned long ) V_66 ) ;
V_16 -> V_78 = V_64 ;
V_19 -> V_51 = ( unsigned long ) V_16 -> V_66 ;
if ( V_19 -> V_81 == V_82 )
V_19 -> V_51 += 8 ;
}
void F_65 ( struct V_18 * V_19 , int V_125 )
{
unsigned long * V_126 = F_66 ( & V_127 ) ;
struct V_57 * V_37 = ( void * ) F_35 () ;
int V_64 = F_38 ( V_37 , V_65 ) ;
unsigned long V_128 = F_53 ( V_129 ) ;
if ( V_64 == 0 ) {
F_67 ( V_130 , 0 ) ;
} else if ( ( * V_126 != V_19 -> V_51 ) ||
( ! ( V_128 & V_131 ) ) ) {
V_128 |= V_131 ;
V_128 |= V_132 ;
F_67 ( V_129 , V_128 ) ;
F_68 ( V_30 , V_19 ) ;
}
}
void F_37 ( struct V_18 * V_19 )
{
unsigned long * V_126 = F_66 ( & V_127 ) ;
unsigned long V_128 = F_53 ( V_129 ) ;
* V_126 = V_19 -> V_51 ;
V_128 |= V_131 ;
V_128 |= V_132 ;
F_67 ( V_129 , V_128 ) ;
F_67 ( V_130 , 1 << V_108 ) ;
}
void F_34 ( void )
{
}
