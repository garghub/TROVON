static void F_1 ( unsigned long * V_1 )
{
int V_2 ;
if( ( ( ( unsigned long ) V_1 ) & 3 ) )
return;
for( V_2 = - 3 ; V_2 < 6 ; V_2 ++ )
F_2 ( L_1 , V_2 ? ' ' : '<' , V_1 [ V_2 ] , V_2 ? ' ' : '>' ) ;
F_2 ( L_2 ) ;
}
void T_1 F_3 ( char * V_3 , struct V_4 * V_5 )
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
F_6 ( V_10 , V_11 ) ;
V_12 ; V_12 ; V_12 ; V_12 ;
V_12 ; V_12 ; V_12 ; V_12 ;
V_13 ; V_13 ; V_13 ; V_13 ;
V_13 ; V_13 ; V_13 ; V_13 ;
{
struct V_14 * V_15 = (struct V_14 * ) V_5 -> V_16 [ V_17 ] ;
while( V_15 &&
V_7 ++ < 30 &&
( ( ( unsigned long ) V_15 ) >= V_18 ) &&
! ( ( ( unsigned long ) V_15 ) & 0x7 ) ) {
F_2 ( L_8 , V_15 -> V_19 [ 7 ] ,
( void * ) V_15 -> V_19 [ 7 ] ) ;
V_15 = (struct V_14 * ) V_15 -> V_19 [ 6 ] ;
}
}
F_2 ( L_9 ) ;
F_1 ( ( unsigned long * ) V_5 -> V_1 ) ;
if( V_5 -> V_20 & V_21 )
F_7 ( V_22 ) ;
F_7 ( V_23 ) ;
}
void F_8 ( struct V_4 * V_5 , unsigned long type )
{
T_2 V_24 ;
if( type < 0x80 ) {
F_2 ( L_10 , type ) ;
F_3 ( L_11 , V_5 ) ;
}
if( V_5 -> V_20 & V_21 )
F_3 ( L_12 , V_5 ) ;
V_24 . V_25 = V_26 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_29 ;
V_24 . V_30 = ( void V_31 * ) V_5 -> V_1 ;
V_24 . V_32 = type - 0x80 ;
F_9 ( V_26 , & V_24 , V_8 ) ;
}
void F_10 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
if( V_20 & V_21 )
F_3 ( L_13 , V_5 ) ;
#ifdef F_11
F_2 ( L_14 ,
V_5 -> V_1 , * ( unsigned long * ) V_5 -> V_1 ) ;
#endif
V_24 . V_25 = V_26 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_34 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_26 , & V_24 , V_8 ) ;
}
void F_13 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
if( V_20 & V_21 )
F_3 ( L_15 , V_5 ) ;
V_24 . V_25 = V_26 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_35 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_26 , & V_24 , V_8 ) ;
}
void F_14 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
if( V_5 -> V_20 & V_21 ) {
F_2 ( L_16 , V_1 , V_33 ,
V_5 -> V_16 [ V_36 ] ) ;
F_3 ( L_17 , V_5 ) ;
}
#if 0
show_regs (regs);
instruction_dump ((unsigned long *) regs->pc);
printk ("do_MNA!\n");
#endif
V_24 . V_25 = V_37 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_38 ;
V_24 . V_30 = ( void * ) 0 ;
V_24 . V_32 = 0 ;
F_12 ( V_37 , & V_24 , V_8 ) ;
}
void F_15 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
if( V_20 & V_21 )
F_3 ( L_18 , V_5 ) ;
F_16 ( F_17 () | V_39 ) ;
V_5 -> V_20 |= V_39 ;
#ifndef F_18
if( V_40 == V_8 )
return;
if( V_40 ) {
struct V_41 * V_42 = V_40 ;
F_19 ( & V_42 -> V_43 . V_44 [ 0 ] , & V_42 -> V_43 . V_45 ,
& V_42 -> V_43 . V_46 [ 0 ] , & V_42 -> V_43 . V_47 ) ;
}
V_40 = V_8 ;
if( F_20 () ) {
F_21 ( & V_8 -> V_43 . V_44 [ 0 ] , & V_8 -> V_43 . V_45 ) ;
} else {
F_21 ( & V_48 [ 0 ] , & V_49 ) ;
F_22 () ;
}
#else
if( ! F_20 () ) {
F_21 ( & V_48 [ 0 ] , & V_49 ) ;
F_22 () ;
} else {
F_21 ( & V_8 -> V_43 . V_44 [ 0 ] , & V_8 -> V_43 . V_45 ) ;
}
F_23 ( V_50 ) ;
#endif
}
void F_24 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
if( V_20 & V_21 )
F_3 ( L_19 , V_5 ) ;
V_24 . V_25 = V_51 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_52 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_51 , & V_24 , V_8 ) ;
}
void F_25 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
#ifdef F_11
F_2 ( L_20 ,
V_1 , V_33 , V_20 ) ;
#endif
if( V_20 & V_21 )
F_26 ( L_21
L_22 ) ;
}
void F_27 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
#ifdef F_11
F_2 ( L_23 ,
V_1 , V_33 , V_20 ) ;
#endif
V_24 . V_25 = V_37 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_53 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_9 ( V_37 , & V_24 , V_8 ) ;
}
void F_28 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
V_24 . V_25 = V_26 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_54 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_26 , & V_24 , V_8 ) ;
}
void F_29 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
#ifdef F_11
F_2 ( L_24 ,
V_1 , V_33 , V_20 ) ;
#endif
V_24 . V_25 = V_26 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_54 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_26 , & V_24 , V_8 ) ;
}
void F_30 ( struct V_4 * V_5 , unsigned long V_1 , unsigned long V_33 ,
unsigned long V_20 )
{
T_2 V_24 ;
V_24 . V_25 = V_55 ;
V_24 . V_27 = 0 ;
V_24 . V_28 = V_56 ;
V_24 . V_30 = ( void V_31 * ) V_1 ;
V_24 . V_32 = 0 ;
F_12 ( V_55 , & V_24 , V_8 ) ;
}
void F_31 ( const char * V_57 , int line )
{
F_2 ( L_25 , V_57 , line ) ;
}
void F_32 ( void )
{
extern void V_58 ( void ) ;
if ( V_59 != F_33 ( struct V_60 , V_61 ) ||
V_62 != F_33 ( struct V_60 , V_63 ) ||
V_64 != F_33 ( struct V_60 , V_65 ) ||
V_66 != F_33 ( struct V_60 , V_67 ) ||
V_68 != F_33 ( struct V_60 , V_69 ) ||
V_70 != F_33 ( struct V_60 , V_71 ) ||
V_72 != F_33 ( struct V_60 , V_73 ) ||
V_74 != F_33 ( struct V_60 , V_75 ) ||
V_76 != F_33 ( struct V_60 , V_77 ) ||
V_78 != F_33 ( struct V_60 , V_79 ) ||
V_80 != F_33 ( struct V_60 , V_81 ) ||
V_82 != F_33 ( struct V_60 , V_83 ) ||
V_84 != F_33 ( struct V_60 , V_85 ) ||
V_86 != F_33 ( struct V_60 , V_87 ) ||
V_88 != F_33 ( struct V_60 , V_89 ) )
V_58 () ;
F_34 ( & V_90 . V_91 ) ;
V_8 -> V_92 = & V_90 ;
}
