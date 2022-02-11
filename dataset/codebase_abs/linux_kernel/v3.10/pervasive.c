static void F_1 ( void )
{
unsigned long V_1 , V_2 ;
if ( ! F_2 () )
return;
V_1 = F_3 ( V_3 ) ;
V_2 = F_3 ( V_4 ) ;
V_2 |= V_5 | V_6 ;
switch ( V_1 & V_7 ) {
case V_8 :
V_2 |= V_9 ;
break;
case V_10 :
V_2 |= V_11 ;
break;
default:
F_4 ( V_12 L_1 ,
V_13 ) ;
break;
}
F_5 ( V_4 , V_2 ) ;
F_6 () ;
V_1 &= ~ ( V_14 | V_15 ) ;
F_5 ( V_16 , V_1 ) ;
F_7 () ;
}
static int F_8 ( struct V_17 * V_18 )
{
switch ( V_18 -> V_19 & V_20 ) {
case V_21 :
F_9 ( V_18 ) ;
break;
case V_22 :
F_10 ( V_18 ) ;
break;
case V_23 :
return F_11 () ;
#ifdef F_12
case V_24 :
F_13 ( V_18 ) ;
break;
case V_25 :
F_14 ( V_18 ) ;
break;
#endif
default:
return 0 ;
}
return 1 ;
}
void T_1 F_15 ( void )
{
int V_26 ;
if ( ! F_16 ( V_27 ) )
return;
F_17 (cpu) {
struct V_28 T_2 * V_18 = F_18 ( V_26 ) ;
if ( ! V_18 )
continue;
F_19 ( & V_18 -> V_29 , F_20 ( & V_18 -> V_29 ) |
V_30 ) ;
}
V_31 . V_32 = F_1 ;
V_31 . V_33 = F_8 ;
}
