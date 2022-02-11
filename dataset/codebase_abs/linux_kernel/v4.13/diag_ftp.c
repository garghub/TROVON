static void F_1 ( struct V_1 V_2 ,
unsigned int V_3 ,
unsigned long V_4 )
{
if ( ( V_2 . V_5 >> 8 ) != 8 )
return;
F_2 ( V_6 ) ;
V_7 = V_2 . V_5 & 0xffU ;
F_3 ( & V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
int V_13 ;
F_5 ( V_14 ) ;
asm volatile(
" diag %[addr],%[cmd],0x2c4\n"
"0: j 2f\n"
"1: la %[rc],%[err]\n"
"2:\n"
EX_TABLE(0b, 1b)
: [rc] "=d" (rc), "+m" (*fpl)
: [cmd] "0" (cmd), [addr] "d" (virt_to_phys(fpl)),
[err] "i" (DIAG_FTP_RET_EPERM)
: "cc");
switch ( V_13 ) {
case V_15 :
return 0 ;
case V_16 :
return - V_17 ;
case V_18 :
return - V_19 ;
case V_20 :
default:
return - V_21 ;
}
}
T_1 F_6 ( const struct V_22 * V_23 , T_2 * V_24 )
{
struct V_9 * V_25 ;
T_1 V_26 ;
#ifdef F_7
unsigned long V_27 ;
F_8 ( L_1 ,
V_23 -> V_28 , V_23 -> V_26 ) ;
V_27 = V_29 ;
#endif
F_9 ( & V_8 ) ;
V_25 = ( void * ) F_10 ( V_30 | V_31 ) ;
if ( ! V_25 ) {
V_26 = - V_32 ;
goto V_33;
}
V_26 = F_11 ( V_25 -> V_34 , V_23 -> V_28 , sizeof( V_25 -> V_34 ) ) ;
if ( V_26 >= V_35 ) {
V_26 = - V_36 ;
goto V_37;
}
V_25 -> V_38 = 0 ;
V_25 -> V_24 = 0 ;
V_25 -> V_39 = V_23 -> V_40 ;
V_25 -> V_41 = V_23 -> V_26 ;
V_25 -> V_42 = F_12 ( V_23 -> V_43 ) ;
V_26 = F_4 ( V_25 , V_23 -> V_44 ) ;
if ( V_26 )
goto V_37;
F_13 ( & V_8 ) ;
#ifdef F_7
F_8 ( L_2 ,
( V_29 - V_27 ) * 1000 / V_45 ) ;
F_8 ( L_3 ,
V_7 , V_25 -> V_38 , V_25 -> V_24 ) ;
#endif
switch ( V_7 ) {
case V_46 :
V_26 = V_25 -> V_38 ;
if ( V_24 )
* V_24 = V_25 -> V_24 ;
break;
case V_47 :
V_26 = - V_19 ;
break;
case V_48 :
V_26 = - V_17 ;
break;
case V_49 :
V_26 = - V_50 ;
break;
default:
V_26 = - V_21 ;
break;
}
V_37:
F_14 ( ( unsigned long ) V_25 ) ;
V_33:
return V_26 ;
}
int F_15 ( void )
{
int V_13 ;
V_13 = F_16 ( V_51 , F_1 ) ;
if ( V_13 )
return V_13 ;
F_17 ( V_52 ) ;
return 0 ;
}
void F_18 ( void )
{
F_19 ( V_52 ) ;
F_20 ( V_51 , F_1 ) ;
}
