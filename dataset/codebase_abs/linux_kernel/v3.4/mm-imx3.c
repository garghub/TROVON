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
void T_1 * V_10 ;
void T_1 * V_11 ;
#define F_7 0x10
V_11 = F_8 ( V_12 , 4096 ) ;
if ( V_11 != NULL ) {
F_9 ( 0x00000515 , V_11 + F_7 ) ;
F_10 ( V_11 ) ;
} else {
F_11 ( L_1 ) ;
}
V_10 = F_8 ( V_13 , 4096 ) ;
if ( F_12 ( V_10 ) ) {
F_13 ( V_14 L_2 ,
F_14 ( V_10 ) ) ;
return;
}
F_15 ( V_10 , 0x00030024 , 0x00000000 ) ;
}
void T_3 F_16 ( void )
{
F_17 ( V_15 , F_18 ( V_15 ) ) ;
}
void T_3 F_19 ( void )
{
F_20 ( V_16 ) ;
F_21 ( F_22 ( V_17 ) ) ;
V_18 = F_3 ;
V_19 = F_1 ;
}
void T_3 F_23 ( void )
{
F_24 ( F_22 ( V_20 ) ) ;
}
void T_3 F_25 ( void )
{
int V_21 = F_26 () >> 4 ;
F_6 () ;
F_27 ( L_3 , 0 , V_22 , V_23 , V_24 , 0 ) ;
F_27 ( L_3 , 1 , V_25 , V_23 , V_26 , 0 ) ;
F_27 ( L_3 , 2 , V_27 , V_23 , V_28 , 0 ) ;
if ( V_21 == 1 ) {
strncpy ( V_29 . V_30 , L_4 ,
strlen ( V_29 . V_30 ) ) ;
V_29 . V_31 = & V_32 ;
}
F_28 ( L_5 , V_33 , V_34 , & V_29 ) ;
F_29 ( F_22 ( V_35 ) ) ;
F_29 ( F_22 ( V_36 ) ) ;
F_30 ( L_6 , 0 , V_37 ,
F_18 ( V_37 ) ) ;
}
void T_3 F_31 ( void )
{
F_17 ( V_38 , F_18 ( V_38 ) ) ;
}
void T_3 F_32 ( void )
{
F_20 ( V_39 ) ;
F_33 ( F_34 ( V_40 ) ) ;
F_21 ( F_34 ( V_41 ) ) ;
V_19 = F_1 ;
V_18 = F_3 ;
}
void T_3 F_35 ( void )
{
F_24 ( F_34 ( V_42 ) ) ;
}
void T_3 F_36 ( void )
{
int V_21 = F_37 () >> 4 ;
F_6 () ;
F_27 ( L_3 , 0 , V_43 , V_23 , V_44 , 0 ) ;
F_27 ( L_3 , 1 , V_45 , V_23 , V_46 , 0 ) ;
F_27 ( L_3 , 2 , V_47 , V_23 , V_48 , 0 ) ;
if ( V_21 == 1 ) {
strncpy ( V_49 . V_30 , L_7 ,
strlen ( V_49 . V_30 ) ) ;
V_49 . V_31 = & V_50 ;
}
F_28 ( L_8 , V_51 , V_52 , & V_49 ) ;
F_29 ( F_34 ( V_53 ) ) ;
F_29 ( F_34 ( V_54 ) ) ;
F_30 ( L_6 , 0 , V_55 ,
F_18 ( V_55 ) ) ;
}
