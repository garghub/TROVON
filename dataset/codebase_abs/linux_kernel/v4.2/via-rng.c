static inline T_1 F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_2 () ;
asm(".byte 0x0F,0xA7,0xC0 /* xstore %%edi (addr=%0) */"
: "=m" (*addr), "=a" (eax_out), "+d" (edx_in), "+D" (addr));
F_3 ( V_4 ) ;
return V_3 ;
}
static int F_4 ( struct V_5 * V_6 , int V_7 )
{
char V_8 [ 16 + V_9 - V_10 ] V_11
( ( F_5 ( V_10 ) ) ) ;
T_1 * V_12 = ( T_1 * ) F_6 ( & V_8 [ 0 ] , V_9 ) ;
T_1 V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 20 ; V_14 ++ ) {
* V_12 = 0 ;
V_13 = F_1 ( V_12 , V_15 ) ;
V_13 &= V_16 ;
if ( V_13 || ! V_7 )
break;
F_7 ( 10 ) ;
}
V_6 -> V_17 = * V_12 ;
return V_13 ? 1 : 0 ;
}
static int F_8 ( struct V_5 * V_6 , T_1 * V_18 )
{
T_1 V_12 = ( T_1 ) V_6 -> V_17 ;
* V_18 = V_12 ;
return 1 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & F_10 ( 0 ) ;
T_1 V_21 , V_22 , V_23 ;
if ( ( V_20 -> V_24 == 6 ) && ( V_20 -> V_25 >= 0x0f ) ) {
if ( ! V_26 ) {
F_11 ( V_27 L_1
L_2 ) ;
return - V_28 ;
}
return 0 ;
}
F_12 ( V_29 , V_21 , V_22 ) ;
V_23 = V_21 ;
V_21 &= ~ ( 0x7f << V_30 ) ;
V_21 &= ~ V_16 ;
V_21 &= ~ ( V_31 | V_32 | V_33 ) ;
V_21 |= V_34 ;
V_21 |= V_35 ;
if ( ( V_20 -> V_25 == 9 ) && ( V_20 -> V_36 > 7 ) )
V_21 |= V_37 ;
if ( V_20 -> V_25 >= 10 )
V_21 |= V_37 ;
if ( V_21 != V_23 )
F_13 ( V_29 , V_21 , V_22 ) ;
F_12 ( V_29 , V_21 , V_22 ) ;
if ( ( V_21 & V_34 ) == 0 ) {
F_11 ( V_27 L_3 ) ;
return - V_28 ;
}
return 0 ;
}
static int T_2 F_14 ( void )
{
int V_38 ;
if ( ! V_39 )
return - V_28 ;
F_15 ( L_4 ) ;
V_38 = F_16 ( & V_40 ) ;
if ( V_38 ) {
F_11 ( V_27 L_5 ,
V_38 ) ;
goto V_41;
}
V_41:
return V_38 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_40 ) ;
}
