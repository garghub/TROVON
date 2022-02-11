static void F_1 ( void )
{
unsigned long V_1 = 0 ;
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
static void T_1 * F_2 ( T_2 V_2 , T_3 V_3 ,
unsigned int V_4 , void * V_5 )
{
if ( V_4 == V_6 ) {
if ( V_2 < 0x80000000 &&
! F_3 ( V_2 , V_7 ) )
V_4 = V_8 ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void T_4 F_5 ( void )
{
#ifdef F_6
void T_1 * V_9 ;
void T_1 * V_10 ;
#define F_7 0x10
V_10 = F_8 ( V_11 , 4096 ) ;
if ( V_10 != NULL ) {
F_9 ( 0x00000515 , V_10 + F_7 ) ;
F_10 ( V_10 ) ;
} else {
F_11 ( L_1 ) ;
}
V_9 = F_8 ( V_12 , 4096 ) ;
if ( ! V_9 ) {
F_12 ( V_13 L_2 ) ;
return;
}
F_13 ( V_9 , 0x00030024 , 0x00000000 ) ;
#endif
}
void T_4 F_14 ( void )
{
F_15 ( V_14 , F_16 ( V_14 ) ) ;
}
static void F_17 ( void )
{
int V_1 = F_18 ( V_15 + V_16 ) ;
V_1 &= ~ V_17 ;
F_19 ( V_1 , V_15 + V_16 ) ;
F_1 () ;
}
void T_4 F_20 ( void )
{
F_21 ( V_18 ) ;
V_19 = F_2 ;
V_20 = F_17 ;
V_15 = F_22 ( V_21 ) ;
}
void T_4 F_23 ( void )
{
F_24 ( F_22 ( V_22 ) ) ;
}
void T_4 F_25 ( void )
{
int V_23 = F_26 () >> 4 ;
F_5 () ;
F_27 ( F_22 ( V_24 ) ) ;
F_28 () ;
F_29 ( L_3 , 0 , V_25 , V_26 , V_27 , 0 ) ;
F_29 ( L_3 , 1 , V_28 , V_26 , V_29 , 0 ) ;
F_29 ( L_3 , 2 , V_30 , V_26 , V_31 , 0 ) ;
F_30 () ;
if ( V_23 == 1 ) {
strncpy ( V_32 . V_33 , L_4 ,
strlen ( V_32 . V_33 ) ) ;
V_32 . V_34 = & V_35 ;
}
F_31 ( L_5 , V_36 , V_37 , & V_32 ) ;
F_32 ( F_22 ( V_38 ) ) ;
F_32 ( F_22 ( V_39 ) ) ;
F_33 ( L_6 , 0 , V_40 ,
F_16 ( V_40 ) ) ;
F_33 ( L_7 , - 1 , V_41 ,
F_16 ( V_41 ) ) ;
}
void T_4 F_34 ( void )
{
F_15 ( V_42 , F_16 ( V_42 ) ) ;
}
static void F_35 ( void )
{
int V_1 = F_18 ( V_15 + V_16 ) ;
V_1 &= ~ V_17 ;
V_1 |= V_43 ;
F_19 ( V_1 , V_15 + V_16 ) ;
F_1 () ;
}
void T_4 F_36 ( void )
{
F_21 ( V_44 ) ;
F_37 ( F_38 ( V_45 ) ) ;
V_20 = F_35 ;
V_19 = F_2 ;
V_15 = F_38 ( V_46 ) ;
}
void T_4 F_39 ( void )
{
F_24 ( F_38 ( V_47 ) ) ;
}
void T_4 F_40 ( void )
{
int V_23 = F_41 () >> 4 ;
F_5 () ;
F_27 ( F_38 ( V_48 ) ) ;
F_28 () ;
F_29 ( L_8 , 0 , V_49 , V_26 , V_50 , 0 ) ;
F_29 ( L_8 , 1 , V_51 , V_26 , V_52 , 0 ) ;
F_29 ( L_8 , 2 , V_53 , V_26 , V_54 , 0 ) ;
F_30 () ;
if ( V_23 == 1 ) {
strncpy ( V_55 . V_33 , L_9 ,
strlen ( V_55 . V_33 ) ) ;
V_55 . V_34 = & V_56 ;
}
F_31 ( L_10 , V_57 , V_58 , & V_55 ) ;
F_32 ( F_38 ( V_59 ) ) ;
F_32 ( F_38 ( V_60 ) ) ;
F_33 ( L_6 , 0 , V_61 ,
F_16 ( V_61 ) ) ;
}
