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
case V_14 :
return 0 ;
case V_15 :
return - V_16 ;
case V_17 :
return - V_18 ;
case V_19 :
default:
return - V_20 ;
}
}
T_1 F_5 ( const struct V_21 * V_22 , T_2 * V_23 )
{
struct V_9 * V_24 ;
T_1 V_25 ;
#ifdef F_6
unsigned long V_26 ;
F_7 ( L_1 ,
V_22 -> V_27 , V_22 -> V_25 ) ;
V_26 = V_28 ;
#endif
F_8 ( & V_8 ) ;
V_24 = ( void * ) F_9 ( V_29 | V_30 ) ;
if ( ! V_24 ) {
V_25 = - V_31 ;
goto V_32;
}
V_25 = F_10 ( V_24 -> V_33 , V_22 -> V_27 , sizeof( V_24 -> V_33 ) ) ;
if ( V_25 >= V_34 ) {
V_25 = - V_35 ;
goto V_36;
}
V_24 -> V_37 = 0 ;
V_24 -> V_23 = 0 ;
V_24 -> V_38 = V_22 -> V_39 ;
V_24 -> V_40 = V_22 -> V_25 ;
V_24 -> V_41 = F_11 ( V_22 -> V_42 ) ;
V_25 = F_4 ( V_24 , V_22 -> V_43 ) ;
if ( V_25 )
goto V_36;
F_12 ( & V_8 ) ;
#ifdef F_6
F_7 ( L_2 ,
( V_28 - V_26 ) * 1000 / V_44 ) ;
F_7 ( L_3 ,
V_7 , V_24 -> V_37 , V_24 -> V_23 ) ;
#endif
switch ( V_7 ) {
case V_45 :
V_25 = V_24 -> V_37 ;
if ( V_23 )
* V_23 = V_24 -> V_23 ;
break;
case V_46 :
V_25 = - V_18 ;
break;
case V_47 :
V_25 = - V_16 ;
break;
case V_48 :
V_25 = - V_49 ;
break;
default:
V_25 = - V_20 ;
break;
}
V_36:
F_13 ( ( unsigned long ) V_24 ) ;
V_32:
return V_25 ;
}
int F_14 ( void )
{
int V_13 ;
V_13 = F_15 ( V_50 , F_1 ) ;
if ( V_13 )
return V_13 ;
F_16 ( 0 , 63 - 22 ) ;
return 0 ;
}
void F_17 ( void )
{
F_18 ( 0 , 63 - 22 ) ;
F_19 ( V_50 , F_1 ) ;
}
