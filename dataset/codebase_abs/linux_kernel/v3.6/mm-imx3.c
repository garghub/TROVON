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
if ( F_13 ( V_10 ) ) {
F_14 ( V_14 L_2 ,
F_15 ( V_10 ) ) ;
return;
}
F_16 ( V_10 , 0x00030024 , 0x00000000 ) ;
#endif
}
void T_3 F_17 ( void )
{
F_18 ( V_15 , F_19 ( V_15 ) ) ;
}
void T_3 F_20 ( void )
{
F_21 ( V_16 ) ;
F_22 ( F_23 ( V_17 ) ) ;
V_18 = F_3 ;
V_19 = F_1 ;
V_20 = F_23 ( V_21 ) ;
}
void T_3 F_24 ( void )
{
F_25 ( F_23 ( V_22 ) ) ;
}
void T_3 F_26 ( void )
{
int V_23 = F_27 () >> 4 ;
F_6 () ;
F_28 ( L_3 , 0 , V_24 , V_25 , V_26 , 0 ) ;
F_28 ( L_3 , 1 , V_27 , V_25 , V_28 , 0 ) ;
F_28 ( L_3 , 2 , V_29 , V_25 , V_30 , 0 ) ;
F_29 () ;
if ( V_23 == 1 ) {
strncpy ( V_31 . V_32 , L_4 ,
strlen ( V_31 . V_32 ) ) ;
V_31 . V_33 = & V_34 ;
}
F_30 ( L_5 , V_35 , V_36 , & V_31 ) ;
F_31 ( F_23 ( V_37 ) ) ;
F_31 ( F_23 ( V_38 ) ) ;
F_32 ( L_6 , 0 , V_39 ,
F_19 ( V_39 ) ) ;
}
void T_3 F_33 ( void )
{
F_18 ( V_40 , F_19 ( V_40 ) ) ;
}
void T_3 F_34 ( void )
{
F_21 ( V_41 ) ;
F_35 ( F_36 ( V_42 ) ) ;
F_22 ( F_36 ( V_43 ) ) ;
V_19 = F_1 ;
V_18 = F_3 ;
V_20 = F_36 ( V_44 ) ;
}
void T_3 F_37 ( void )
{
F_25 ( F_36 ( V_45 ) ) ;
}
void T_3 F_38 ( void )
{
int V_23 = F_39 () >> 4 ;
F_6 () ;
F_28 ( L_7 , 0 , V_46 , V_25 , V_47 , 0 ) ;
F_28 ( L_7 , 1 , V_48 , V_25 , V_49 , 0 ) ;
F_28 ( L_7 , 2 , V_50 , V_25 , V_51 , 0 ) ;
F_29 () ;
if ( V_23 == 1 ) {
strncpy ( V_52 . V_32 , L_8 ,
strlen ( V_52 . V_32 ) ) ;
V_52 . V_33 = & V_53 ;
}
F_30 ( L_9 , V_54 , V_55 , & V_52 ) ;
F_31 ( F_36 ( V_56 ) ) ;
F_31 ( F_36 ( V_57 ) ) ;
F_32 ( L_6 , 0 , V_58 ,
F_19 ( V_58 ) ) ;
}
