static void F_1 ( unsigned long * V_1 )
{
int V_2 ;
if( ( ( ( unsigned long ) V_1 ) & 3 ) )
return;
for( V_2 = - 3 ; V_2 < 6 ; V_2 ++ )
F_2 ( L_1 , V_2 ? ' ' : '<' , V_1 [ V_2 ] , V_2 ? ' ' : '>' ) ;
F_2 ( L_2 ) ;
}
void F_3 ( char * V_3 , struct V_4 * V_5 )
{
static int V_6 ;
int V_7 = 0 ;
F_2 (
L_3
L_4
L_5
L_6 ) ;
F_2 ( L_7 , V_8 -> V_9 , F_4 ( V_8 ) , V_3 , ++ V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_10 ) ;
V_11 ; V_11 ; V_11 ; V_11 ;
V_11 ; V_11 ; V_11 ; V_11 ;
V_12 ; V_12 ; V_12 ; V_12 ;
V_12 ; V_12 ; V_12 ; V_12 ;
{
struct V_13 * V_14 = (struct V_13 * ) V_5 -> V_15 [ V_16 ] ;
while( V_14 &&
V_7 ++ < 30 &&
( ( ( unsigned long ) V_14 ) >= V_17 ) &&
! ( ( ( unsigned long ) V_14 ) & 0x7 ) ) {
F_2 ( L_8 , V_14 -> V_18 [ 7 ] ,
( void * ) V_14 -> V_18 [ 7 ] ) ;
V_14 = (struct V_13 * ) V_14 -> V_18 [ 6 ] ;
}
}
F_2 ( L_9 ) ;
F_1 ( ( unsigned long * ) V_5 -> V_1 ) ;
if( V_5 -> V_19 & V_20 )
F_7 ( V_21 ) ;
F_7 ( V_22 ) ;
}
void F_8 ( struct V_4 * V_5 , unsigned long type )
{
T_1 V_23 ;
if( type < 0x80 ) {
F_2 ( L_10 , type ) ;
F_3 ( L_11 , V_5 ) ;
}
if( V_5 -> V_19 & V_20 )
F_3 ( L_12 , V_5 ) ;
V_23 . V_24 = V_25 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_28 ;
V_23 . V_29 = ( void V_30 * ) V_5 -> V_1 ;
V_23 . V_31 = type - 0x80 ;
F_9 ( V_25 , & V_23 , V_8 ) ;
}
void F_10 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
if( V_19 & V_20 )
F_3 ( L_13 , V_5 ) ;
#ifdef F_11
F_2 ( L_14 ,
V_5 -> V_1 , * ( unsigned long * ) V_5 -> V_1 ) ;
#endif
V_23 . V_24 = V_25 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_33 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_25 , & V_23 , V_8 ) ;
}
void F_13 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
if( V_19 & V_20 )
F_3 ( L_15 , V_5 ) ;
V_23 . V_24 = V_25 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_34 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_25 , & V_23 , V_8 ) ;
}
void F_14 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
if( V_5 -> V_19 & V_20 ) {
F_2 ( L_16 , V_1 , V_32 ,
V_5 -> V_15 [ V_35 ] ) ;
F_3 ( L_17 , V_5 ) ;
}
#if 0
show_regs (regs);
instruction_dump ((unsigned long *) regs->pc);
printk ("do_MNA!\n");
#endif
V_23 . V_24 = V_36 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_37 ;
V_23 . V_29 = ( void * ) 0 ;
V_23 . V_31 = 0 ;
F_12 ( V_36 , & V_23 , V_8 ) ;
}
void F_15 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
if( V_19 & V_20 )
F_3 ( L_18 , V_5 ) ;
F_16 ( F_17 () | V_38 ) ;
V_5 -> V_19 |= V_38 ;
#ifndef F_18
if( V_39 == V_8 )
return;
if( V_39 ) {
struct V_40 * V_41 = V_39 ;
F_19 ( & V_41 -> V_42 . V_43 [ 0 ] , & V_41 -> V_42 . V_44 ,
& V_41 -> V_42 . V_45 [ 0 ] , & V_41 -> V_42 . V_46 ) ;
}
V_39 = V_8 ;
if( F_20 () ) {
F_21 ( & V_8 -> V_42 . V_43 [ 0 ] , & V_8 -> V_42 . V_44 ) ;
} else {
F_21 ( & V_47 [ 0 ] , & V_48 ) ;
F_22 () ;
}
#else
if( ! F_20 () ) {
F_21 ( & V_47 [ 0 ] , & V_48 ) ;
F_22 () ;
} else {
F_21 ( & V_8 -> V_42 . V_43 [ 0 ] , & V_8 -> V_42 . V_44 ) ;
}
F_23 ( V_49 ) ;
#endif
}
void F_24 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
if( V_19 & V_20 )
F_3 ( L_19 , V_5 ) ;
V_23 . V_24 = V_50 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_51 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_50 , & V_23 , V_8 ) ;
}
void F_25 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
#ifdef F_11
F_2 ( L_20 ,
V_1 , V_32 , V_19 ) ;
#endif
if( V_19 & V_20 )
F_26 ( L_21
L_22 ) ;
}
void F_27 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
#ifdef F_11
F_2 ( L_23 ,
V_1 , V_32 , V_19 ) ;
#endif
V_23 . V_24 = V_36 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_52 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_9 ( V_36 , & V_23 , V_8 ) ;
}
void F_28 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
V_23 . V_24 = V_25 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_53 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_25 , & V_23 , V_8 ) ;
}
void F_29 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
#ifdef F_11
F_2 ( L_24 ,
V_1 , V_32 , V_19 ) ;
#endif
V_23 . V_24 = V_25 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_53 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_25 , & V_23 , V_8 ) ;
}
void F_30 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_32 ,
unsigned long V_19 )
{
T_1 V_23 ;
V_23 . V_24 = V_54 ;
V_23 . V_26 = 0 ;
V_23 . V_27 = V_55 ;
V_23 . V_29 = ( void V_30 * ) V_1 ;
V_23 . V_31 = 0 ;
F_12 ( V_54 , & V_23 , V_8 ) ;
}
void F_31 ( const char * V_56 , int line )
{
F_2 ( L_25 , V_56 , line ) ;
}
void F_32 ( void )
{
extern void V_57 ( void ) ;
if ( V_58 != F_33 ( struct V_59 , V_60 ) ||
V_61 != F_33 ( struct V_59 , V_62 ) ||
V_63 != F_33 ( struct V_59 , V_64 ) ||
V_65 != F_33 ( struct V_59 , V_66 ) ||
V_67 != F_33 ( struct V_59 , V_68 ) ||
V_69 != F_33 ( struct V_59 , V_70 ) ||
V_71 != F_33 ( struct V_59 , V_72 ) ||
V_73 != F_33 ( struct V_59 , V_74 ) ||
V_75 != F_33 ( struct V_59 , V_76 ) ||
V_77 != F_33 ( struct V_59 , V_78 ) ||
V_79 != F_33 ( struct V_59 , V_80 ) ||
V_81 != F_33 ( struct V_59 , V_82 ) ||
V_83 != F_33 ( struct V_59 , V_84 ) ||
V_85 != F_33 ( struct V_59 , V_86 ) ||
V_87 != F_33 ( struct V_59 , V_88 ) )
V_57 () ;
F_34 ( & V_89 . V_90 ) ;
V_8 -> V_91 = & V_89 ;
}
