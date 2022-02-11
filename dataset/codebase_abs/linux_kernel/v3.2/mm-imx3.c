static void F_1 ( void )
{
unsigned long V_1 = 0 ;
if ( ! F_2 () )
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
F_3 () ;
}
static void T_1 * F_4 ( unsigned long V_2 , T_2 V_3 ,
unsigned int V_4 )
{
if ( V_4 == V_5 ) {
if ( V_2 < 0x80000000 &&
! F_5 ( V_2 , V_6 ) )
V_4 = V_7 ;
}
return F_6 ( V_2 , V_3 , V_4 ) ;
}
void F_7 ( void )
{
void T_1 * V_8 ;
void T_1 * V_9 ;
#define F_8 0x10
V_9 = F_9 ( V_10 , 4096 ) ;
if ( V_9 != NULL ) {
F_10 ( 0x00000515 , V_9 + F_8 ) ;
F_11 ( V_9 ) ;
} else {
F_12 ( L_1 ) ;
}
V_8 = F_9 ( V_11 , 4096 ) ;
if ( F_13 ( V_8 ) ) {
F_14 ( V_12 L_2 ,
F_15 ( V_8 ) ) ;
return;
}
F_16 ( V_8 , 0x00030024 , 0x00000000 ) ;
}
void T_3 F_17 ( void )
{
F_18 ( V_13 , F_19 ( V_13 ) ) ;
}
void T_3 F_20 ( void )
{
F_21 ( V_14 ) ;
F_22 ( F_23 ( V_15 ) ) ;
V_16 = F_1 ;
V_17 = F_4 ;
}
void T_3 F_24 ( void )
{
F_25 ( F_23 ( V_18 ) ) ;
}
void T_3 F_26 ( void )
{
int V_19 = F_27 () >> 4 ;
F_7 () ;
F_28 ( L_3 , 0 , V_20 , V_21 , V_22 , 0 ) ;
F_28 ( L_3 , 1 , V_23 , V_21 , V_24 , 0 ) ;
F_28 ( L_3 , 2 , V_25 , V_21 , V_26 , 0 ) ;
if ( V_19 == 1 ) {
strncpy ( V_27 . V_28 , L_4 ,
strlen ( V_27 . V_28 ) ) ;
V_27 . V_29 = & V_30 ;
}
F_29 ( L_5 , V_31 , V_32 , & V_27 ) ;
}
void T_3 F_30 ( void )
{
F_18 ( V_33 , F_19 ( V_33 ) ) ;
}
void T_3 F_31 ( void )
{
F_21 ( V_34 ) ;
F_32 ( F_33 ( V_35 ) ) ;
F_22 ( F_33 ( V_36 ) ) ;
V_16 = F_1 ;
V_17 = F_4 ;
}
void T_3 F_34 ( void )
{
F_25 ( F_33 ( V_37 ) ) ;
}
void T_3 F_35 ( void )
{
int V_19 = F_36 () >> 4 ;
F_7 () ;
F_28 ( L_3 , 0 , V_38 , V_21 , V_39 , 0 ) ;
F_28 ( L_3 , 1 , V_40 , V_21 , V_41 , 0 ) ;
F_28 ( L_3 , 2 , V_42 , V_21 , V_43 , 0 ) ;
if ( V_19 == 1 ) {
strncpy ( V_44 . V_28 , L_6 ,
strlen ( V_44 . V_28 ) ) ;
V_44 . V_29 = & V_45 ;
}
F_29 ( L_7 , V_46 , V_47 , & V_44 ) ;
}
