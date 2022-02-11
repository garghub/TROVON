static void F_1 ( void )
{
unsigned long V_1 = 0 ;
F_2 ( V_2 ) ;
__asm__ __volatile__(
"mrc p15, 0, %0, c1, c0, 0\n"
"bic %0, %0, #0x00001000\n"
"bic %0, %0, #0x00000004\n"
"mcr p15, 0, %0, c1, c0, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c5, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c14, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c0, 4\n"
"nop\n" "nop\n" "nop\n" "nop\n"
"nop\n" "nop\n" "nop\n"
"mrc p15, 0, %0, c1, c0, 0\n"
"orr %0, %0, #0x00001000\n"
"orr %0, %0, #0x00000004\n"
"mcr p15, 0, %0, c1, c0, 0\n"
: "=r" (reg));
}
static void T_1 * F_3 ( unsigned long V_3 , T_2 V_4 ,
unsigned int V_5 , void * V_6 )
{
if ( V_5 == V_7 ) {
if ( V_3 < 0x80000000 &&
! F_4 ( V_3 , V_8 ) )
V_5 = V_9 ;
}
return F_5 ( V_3 , V_4 , V_5 , V_6 ) ;
}
void T_3 F_6 ( void )
{
#ifdef F_7
void T_1 * V_10 ;
void T_1 * V_11 ;
#define F_8 0x10
V_11 = F_9 ( V_12 , 4096 ) ;
if ( V_11 != NULL ) {
F_10 ( 0x00000515 , V_11 + F_8 ) ;
F_11 ( V_11 ) ;
} else {
F_12 ( L_1 ) ;
}
V_10 = F_9 ( V_13 , 4096 ) ;
if ( ! V_10 ) {
F_13 ( V_14 L_2 ) ;
return;
}
F_14 ( V_10 , 0x00030024 , 0x00000000 ) ;
#endif
}
void T_3 F_15 ( void )
{
F_16 ( V_15 , F_17 ( V_15 ) ) ;
}
void T_3 F_18 ( void )
{
F_19 ( V_16 ) ;
F_20 ( F_21 ( V_17 ) ) ;
V_18 = F_3 ;
V_19 = F_1 ;
V_20 = F_21 ( V_21 ) ;
}
void T_3 F_22 ( void )
{
F_23 ( F_21 ( V_22 ) ) ;
}
void T_3 F_24 ( void )
{
int V_23 = F_25 () >> 4 ;
F_6 () ;
F_26 () ;
F_27 ( L_3 , 0 , V_24 , V_25 , V_26 , 0 ) ;
F_27 ( L_3 , 1 , V_27 , V_25 , V_28 , 0 ) ;
F_27 ( L_3 , 2 , V_29 , V_25 , V_30 , 0 ) ;
F_28 () ;
if ( V_23 == 1 ) {
strncpy ( V_31 . V_32 , L_4 ,
strlen ( V_31 . V_32 ) ) ;
V_31 . V_33 = & V_34 ;
}
F_29 ( L_5 , V_35 , V_36 , & V_31 ) ;
F_30 ( F_21 ( V_37 ) ) ;
F_30 ( F_21 ( V_38 ) ) ;
F_31 ( L_6 , 0 , V_39 ,
F_17 ( V_39 ) ) ;
}
void T_3 F_32 ( void )
{
F_16 ( V_40 , F_17 ( V_40 ) ) ;
}
void T_3 F_33 ( void )
{
F_19 ( V_41 ) ;
F_34 ( F_35 ( V_42 ) ) ;
F_20 ( F_35 ( V_43 ) ) ;
V_19 = F_1 ;
V_18 = F_3 ;
V_20 = F_35 ( V_44 ) ;
}
void T_3 F_36 ( void )
{
F_23 ( F_35 ( V_45 ) ) ;
}
void T_3 F_37 ( void )
{
int V_23 = F_38 () >> 4 ;
F_6 () ;
F_26 () ;
F_27 ( L_7 , 0 , V_46 , V_25 , V_47 , 0 ) ;
F_27 ( L_7 , 1 , V_48 , V_25 , V_49 , 0 ) ;
F_27 ( L_7 , 2 , V_50 , V_25 , V_51 , 0 ) ;
F_28 () ;
if ( V_23 == 1 ) {
strncpy ( V_52 . V_32 , L_8 ,
strlen ( V_52 . V_32 ) ) ;
V_52 . V_33 = & V_53 ;
}
F_29 ( L_9 , V_54 , V_55 , & V_52 ) ;
F_30 ( F_35 ( V_56 ) ) ;
F_30 ( F_35 ( V_57 ) ) ;
F_31 ( L_6 , 0 , V_58 ,
F_17 ( V_58 ) ) ;
}
