unsigned long F_1 ( T_1 * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
long V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_6 = F_2 ( ( void * ) V_2 - V_8 ) ;
if ( V_6 && F_3 ( V_6 ) ) {
V_4 = F_4 ( V_6 , struct V_3 , V_6 ) ;
if ( F_5 ( & V_4 -> V_10 ) )
goto V_11;
}
}
return V_2 ;
V_11:
memcpy ( V_1 , ( void * ) V_2 , V_12 * sizeof( T_1 ) ) ;
if ( V_2 == ( unsigned long ) V_6 -> V_2 ) {
V_1 [ 0 ] = V_6 -> V_13 ;
memcpy ( V_1 + 1 , V_4 -> V_14 . V_15 , V_16 ) ;
} else {
V_7 = V_2 - ( unsigned long ) V_6 -> V_2 - 1 ;
memcpy ( V_1 , V_4 -> V_14 . V_15 + V_7 , V_16 - V_7 ) ;
}
return ( unsigned long ) V_1 ;
}
static void T_2 F_6 ( T_1 * V_2 , unsigned long V_17 )
{
#ifdef F_7
* V_2 ++ = 0x48 ;
* V_2 ++ = 0xbf ;
#else
* V_2 ++ = 0xb8 ;
#endif
* ( unsigned long * ) V_2 = V_17 ;
}
static void T_3 T_2 F_8 ( void )
{
asm volatile (
".global optprobe_template_entry\n"
"optprobe_template_entry:\n"
#ifdef F_7
" pushq %rsp\n"
" pushfq\n"
SAVE_REGS_STRING
" movq %rsp, %rsi\n"
".global optprobe_template_val\n"
"optprobe_template_val:\n"
ASM_NOP5
ASM_NOP5
".global optprobe_template_call\n"
"optprobe_template_call:\n"
ASM_NOP5
" movq 144(%rsp), %rdx\n"
" movq %rdx, 152(%rsp)\n"
RESTORE_REGS_STRING
" addq $8, %rsp\n"
" popfq\n"
#else
" pushf\n"
SAVE_REGS_STRING
" movl %esp, %edx\n"
".global optprobe_template_val\n"
"optprobe_template_val:\n"
ASM_NOP5
".global optprobe_template_call\n"
"optprobe_template_call:\n"
ASM_NOP5
RESTORE_REGS_STRING
" addl $4, %esp\n"
" popf\n"
#endif
".global optprobe_template_end\n"
"optprobe_template_end:\n");
}
static void T_2 F_9 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_10 () ;
unsigned long V_22 ;
if ( F_11 ( & V_4 -> V_6 ) )
return;
F_12 ( V_22 ) ;
if ( F_13 () ) {
F_14 ( & V_4 -> V_6 ) ;
} else {
#ifdef F_7
V_19 -> V_23 = V_24 ;
#else
V_19 -> V_23 = V_24 | F_15 () ;
V_19 -> V_25 = 0 ;
#endif
V_19 -> V_26 = ( unsigned long ) V_4 -> V_6 . V_2 + V_27 ;
V_19 -> V_28 = ~ 0UL ;
F_16 ( V_29 , & V_4 -> V_6 ) ;
V_21 -> V_30 = V_31 ;
F_17 ( & V_4 -> V_6 , V_19 ) ;
F_16 ( V_29 , NULL ) ;
}
F_18 ( V_22 ) ;
}
static int T_2 F_19 ( T_4 * V_32 , T_4 * V_33 )
{
int V_34 = 0 , V_35 ;
while ( V_34 < V_9 ) {
V_35 = F_20 ( V_32 + V_34 , V_33 + V_34 ) ;
if ( ! V_35 || ! F_21 ( V_32 + V_34 ) )
return - V_36 ;
V_34 += V_35 ;
}
if ( F_22 ( V_33 , V_33 + V_34 - 1 ) ||
F_23 ( V_33 , V_33 + V_34 - 1 ) ||
F_24 ( V_33 , V_33 + V_34 - 1 ) )
return - V_37 ;
return V_34 ;
}
static int T_2 F_25 ( struct V_38 * V_38 )
{
return ( ( V_38 -> V_13 . V_39 [ 0 ] == 0xff &&
( F_26 ( V_38 -> V_40 . V_41 ) & 6 ) == 4 ) ||
V_38 -> V_13 . V_39 [ 0 ] == 0xea ) ;
}
static int F_27 ( struct V_38 * V_38 , unsigned long V_42 , int V_34 )
{
unsigned long V_43 = 0 ;
switch ( V_38 -> V_13 . V_39 [ 0 ] ) {
case 0xe0 :
case 0xe1 :
case 0xe2 :
case 0xe3 :
case 0xe9 :
case 0xeb :
break;
case 0x0f :
if ( ( V_38 -> V_13 . V_39 [ 1 ] & 0xf0 ) == 0x80 )
break;
return 0 ;
default:
if ( ( V_38 -> V_13 . V_39 [ 0 ] & 0xf0 ) == 0x70 )
break;
return 0 ;
}
V_43 = ( unsigned long ) V_38 -> V_44 + V_38 -> V_45 . V_41 ;
return ( V_42 <= V_43 && V_43 <= V_42 + V_34 ) ;
}
static int T_2 F_28 ( unsigned long V_46 )
{
unsigned long V_2 , V_47 = 0 , V_48 = 0 ;
struct V_38 V_38 ;
T_1 V_1 [ V_12 ] ;
if ( ! F_29 ( V_46 , & V_47 , & V_48 ) )
return 0 ;
if ( ( V_46 >= ( unsigned long ) V_49 ) &&
( V_46 < ( unsigned long ) V_50 ) )
return 0 ;
if ( V_47 - V_48 < V_9 )
return 0 ;
V_2 = V_46 - V_48 ;
while ( V_2 < V_46 - V_48 + V_47 ) {
if ( F_30 ( V_2 ) )
return 0 ;
F_31 ( & V_38 , ( void * ) F_32 ( V_1 , V_2 ) ) ;
F_33 ( & V_38 ) ;
if ( V_38 . V_13 . V_39 [ 0 ] == V_51 )
return 0 ;
V_38 . V_52 = ( void * ) V_2 ;
V_38 . V_44 = ( void * ) ( V_2 + V_38 . V_53 ) ;
if ( F_25 ( & V_38 ) ||
F_27 ( & V_38 , V_46 + V_27 ,
V_16 ) )
return 0 ;
V_2 += V_38 . V_53 ;
}
return 1 ;
}
int T_2 F_34 ( struct V_3 * V_4 )
{
int V_8 ;
struct V_5 * V_54 ;
for ( V_8 = 1 ; V_8 < V_4 -> V_14 . V_47 ; V_8 ++ ) {
V_54 = F_2 ( V_4 -> V_6 . V_2 + V_8 ) ;
if ( V_54 && ! F_11 ( V_54 ) )
return - V_55 ;
}
return 0 ;
}
int T_2
F_35 ( struct V_3 * V_4 , unsigned long V_2 )
{
return ( ( unsigned long ) V_4 -> V_6 . V_2 <= V_2 &&
( unsigned long ) V_4 -> V_6 . V_2 + V_4 -> V_14 . V_47 > V_2 ) ;
}
static T_2
void F_36 ( struct V_3 * V_4 , int V_56 )
{
if ( V_4 -> V_14 . V_38 ) {
F_37 ( V_4 -> V_14 . V_38 , V_56 ) ;
V_4 -> V_14 . V_38 = NULL ;
V_4 -> V_14 . V_47 = 0 ;
}
}
void T_2 F_38 ( struct V_3 * V_4 )
{
F_36 ( V_4 , 1 ) ;
}
int T_2 F_39 ( struct V_3 * V_4 )
{
T_4 * V_1 ;
int V_35 ;
long V_57 ;
if ( ! F_28 ( ( unsigned long ) V_4 -> V_6 . V_2 ) )
return - V_58 ;
V_4 -> V_14 . V_38 = F_40 () ;
if ( ! V_4 -> V_14 . V_38 )
return - V_59 ;
V_57 = ( long ) V_4 -> V_14 . V_38 - ( long ) V_4 -> V_6 . V_2 + V_9 ;
if ( abs ( V_57 ) > 0x7fffffff )
return - V_60 ;
V_1 = ( T_4 * ) V_4 -> V_14 . V_38 ;
V_35 = F_19 ( V_1 + V_61 , V_4 -> V_6 . V_2 ) ;
if ( V_35 < 0 ) {
F_36 ( V_4 , 0 ) ;
return V_35 ;
}
V_4 -> V_14 . V_47 = V_35 ;
memcpy ( V_1 , & V_62 , V_61 ) ;
F_6 ( V_1 + V_63 , ( unsigned long ) V_4 ) ;
F_41 ( V_1 + V_64 , F_9 ) ;
F_42 ( V_1 + V_61 + V_4 -> V_14 . V_47 ,
( T_4 * ) V_4 -> V_6 . V_2 + V_4 -> V_14 . V_47 ) ;
F_43 ( ( unsigned long ) V_1 ,
( unsigned long ) V_1 + V_61 +
V_4 -> V_14 . V_47 + V_9 ) ;
return 0 ;
}
static void T_2 F_44 ( struct V_65 * V_66 ,
T_4 * V_67 ,
struct V_3 * V_4 )
{
T_5 V_57 = ( T_5 ) ( ( long ) V_4 -> V_14 . V_38 -
( ( long ) V_4 -> V_6 . V_2 + V_9 ) ) ;
memcpy ( V_4 -> V_14 . V_15 , V_4 -> V_6 . V_2 + V_27 ,
V_16 ) ;
V_67 [ 0 ] = V_68 ;
* ( T_5 * ) ( & V_67 [ 1 ] ) = V_57 ;
V_66 -> V_2 = V_4 -> V_6 . V_2 ;
V_66 -> V_13 = V_67 ;
V_66 -> V_34 = V_9 ;
}
void T_2 F_45 ( struct V_69 * V_70 )
{
struct V_3 * V_4 , * V_71 ;
int V_72 = 0 ;
F_46 (op, tmp, oplist, list) {
F_47 ( F_11 ( & V_4 -> V_6 ) ) ;
F_44 ( & V_73 [ V_72 ] ,
V_74 [ V_72 ] . V_1 , V_4 ) ;
F_48 ( & V_4 -> V_10 ) ;
if ( ++ V_72 >= V_75 )
break;
}
F_49 ( V_73 , V_72 ) ;
}
static void T_2 F_50 ( struct V_65 * V_66 ,
T_4 * V_67 ,
struct V_3 * V_4 )
{
V_67 [ 0 ] = V_51 ;
memcpy ( V_67 + 1 , V_4 -> V_14 . V_15 , V_16 ) ;
V_66 -> V_2 = V_4 -> V_6 . V_2 ;
V_66 -> V_13 = V_67 ;
V_66 -> V_34 = V_9 ;
}
extern void F_51 ( struct V_69 * V_70 ,
struct V_69 * V_76 )
{
struct V_3 * V_4 , * V_71 ;
int V_72 = 0 ;
F_46 (op, tmp, oplist, list) {
F_50 ( & V_73 [ V_72 ] ,
V_74 [ V_72 ] . V_1 , V_4 ) ;
F_52 ( & V_4 -> V_10 , V_76 ) ;
if ( ++ V_72 >= V_75 )
break;
}
F_49 ( V_73 , V_72 ) ;
}
void T_2 F_53 ( struct V_3 * V_4 )
{
T_4 V_1 [ V_9 ] ;
V_1 [ 0 ] = V_51 ;
memcpy ( V_1 + 1 , V_4 -> V_14 . V_15 , V_16 ) ;
F_54 ( V_4 -> V_6 . V_2 , V_1 , V_9 ) ;
}
int T_2
F_55 ( struct V_5 * V_54 , struct V_18 * V_19 , int V_77 )
{
struct V_3 * V_4 ;
if ( V_54 -> V_22 & V_78 ) {
V_4 = F_4 ( V_54 , struct V_3 , V_6 ) ;
V_19 -> V_26 = ( unsigned long ) V_4 -> V_14 . V_38 + V_61 ;
if ( ! V_77 )
F_56 () ;
F_57 () ;
return 1 ;
}
return 0 ;
}
int T_2 F_58 ( void )
{
V_74 = F_59 ( sizeof( struct V_79 ) *
V_75 , V_80 ) ;
if ( ! V_74 )
return - V_59 ;
V_73 = F_59 ( sizeof( struct V_65 ) *
V_75 , V_80 ) ;
if ( ! V_73 ) {
F_60 ( V_74 ) ;
V_74 = NULL ;
return - V_59 ;
}
return 0 ;
}
