static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 ;
V_6 = V_2 -> V_9 ;
F_2 ( V_6 , 0 , & V_8 ) ;
if ( ( V_8 . V_10 & 0xfffff ) == 0x8000 ) {
return F_3 ( V_2 , V_3 , V_4 ) ;
}
return V_11 ;
}
static void T_2
F_4 ( void )
{
#ifdef F_5
struct V_5 * V_12 ;
struct V_1 * V_2 ;
#endif
T_3 V_13 = 0xffffffff ;
if ( V_14 . V_15 )
V_14 . V_15 ( L_1 , 0 ) ;
#ifdef F_5
F_6 (np, L_2 , L_3 ) {
struct V_7 V_8 ;
F_2 ( V_12 , 0 , & V_8 ) ;
if ( ( V_8 . V_10 & 0xfffff ) == 0x8000 )
F_7 ( V_12 , 1 ) ;
else
F_7 ( V_12 , 0 ) ;
V_2 = F_8 ( V_12 ) ;
V_13 = F_9 ( V_13 , V_2 -> V_16 +
V_2 -> V_17 ) ;
}
V_14 . V_18 = F_1 ;
#endif
F_10 ( L_4 ) ;
#ifdef F_11
F_12 () ;
#endif
#ifdef F_13
if ( ( F_14 () - 1 ) > V_13 ) {
V_19 = 1 ;
F_15 ( & V_20 ) ;
V_14 . V_21 = V_22 ;
}
#endif
}
static void
F_16 ( struct V_23 * V_24 )
{
T_4 V_25 = F_17 ( V_26 ) ;
F_18 ( V_24 , L_5 ) ;
F_18 ( V_24 , L_6 , V_25 ) ;
}
static int T_2 F_19 ( void )
{
unsigned long V_27 = F_20 () ;
if ( F_21 ( V_27 , L_7 ) )
return 1 ;
if ( F_21 ( V_27 , L_8 ) ) {
F_22 ( L_9 ) ;
return 1 ;
}
return 0 ;
}
static long T_2
F_23 ( void )
{
unsigned int V_28 ;
F_24 ( V_29 , 0 ) ;
F_24 ( V_30 , 0 ) ;
V_28 = F_17 ( V_31 ) ;
V_28 |= V_32 ;
F_24 ( V_31 , V_28 ) ;
asm volatile("isync");
return 0 ;
}
static int T_2 F_25 ( void )
{
F_26 ( NULL , V_33 , NULL ) ;
return 0 ;
}
