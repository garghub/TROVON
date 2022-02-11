static inline T_1 F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
asm(".byte 0x0F,0xA7,0xC0 /* xstore %%edi (addr=%0) */"
: "=m" (*addr), "=a" (eax_out), "+d" (edx_in), "+D" (addr));
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 , int V_6 )
{
char V_7 [ 16 + V_8 - V_9 ] V_10
( ( F_3 ( V_9 ) ) ) ;
T_1 * V_11 = ( T_1 * ) F_4 ( & V_7 [ 0 ] , V_8 ) ;
T_1 V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 20 ; V_13 ++ ) {
* V_11 = 0 ;
V_12 = F_1 ( V_11 , V_14 ) ;
V_12 &= V_15 ;
if ( V_12 || ! V_6 )
break;
F_5 ( 10 ) ;
}
V_5 -> V_16 = * V_11 ;
return V_12 ? 1 : 0 ;
}
static int F_6 ( struct V_4 * V_5 , T_1 * V_17 )
{
T_1 V_11 = ( T_1 ) V_5 -> V_16 ;
* V_17 = V_11 ;
return 1 ;
}
static int F_7 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = & F_8 ( 0 ) ;
T_1 V_20 , V_21 , V_22 ;
if ( ( V_19 -> V_23 == 6 ) && ( V_19 -> V_24 >= 0x0f ) ) {
if ( ! F_9 ( V_25 ) ) {
F_10 ( V_26 L_1
L_2 ) ;
return - V_27 ;
}
return 0 ;
}
F_11 ( V_28 , V_20 , V_21 ) ;
V_22 = V_20 ;
V_20 &= ~ ( 0x7f << V_29 ) ;
V_20 &= ~ V_15 ;
V_20 &= ~ ( V_30 | V_31 | V_32 ) ;
V_20 |= V_33 ;
V_20 |= V_34 ;
if ( ( V_19 -> V_24 == 9 ) && ( V_19 -> V_35 > 7 ) )
V_20 |= V_36 ;
if ( V_19 -> V_24 >= 10 )
V_20 |= V_36 ;
if ( V_20 != V_22 )
F_12 ( V_28 , V_20 , V_21 ) ;
F_11 ( V_28 , V_20 , V_21 ) ;
if ( ( V_20 & V_33 ) == 0 ) {
F_10 ( V_26 L_3 ) ;
return - V_27 ;
}
return 0 ;
}
static int T_2 F_13 ( void )
{
int V_37 ;
if ( ! F_9 ( V_38 ) )
return - V_27 ;
F_14 ( L_4 ) ;
V_37 = F_15 ( & V_39 ) ;
if ( V_37 ) {
F_10 ( V_26 L_5 ,
V_37 ) ;
goto V_40;
}
V_40:
return V_37 ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_39 ) ;
}
