void F_1 ( const char * V_1 , struct V_2 * V_3 , long V_4 )
{
F_2 () ;
F_3 ( & V_5 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
F_5 ( V_3 ) ;
F_6 ( & V_5 ) ;
F_7 ( V_4 ) ;
}
T_1 void F_8 ( struct V_2 * V_6 )
{
F_9 ( V_7 , V_6 , V_8 , V_6 -> V_9 ) ;
F_10 ( V_6 -> V_9 , V_6 -> V_9 + 0x4 ) ;
F_11 ( V_6 -> V_9 , V_6 -> V_9 + 0x4 ) ;
}
void F_9 ( int V_10 , struct V_2 * V_6 , int V_11 , unsigned long V_12 )
{
T_2 V_13 ;
if ( F_12 ( V_6 ) )
F_1 ( L_2 , V_6 , V_10 ) ;
V_13 . V_14 = V_10 ;
V_13 . V_15 = 0 ;
V_13 . V_16 = V_11 ;
V_13 . V_17 = ( void V_18 * ) V_12 ;
F_13 ( V_10 , & V_13 , V_19 ) ;
}
T_1 void F_14 ( struct V_2 * V_6 , unsigned int type ,
int V_20 , int V_12 )
{
#ifdef F_15
V_12 = V_6 -> V_21 ;
#endif
#if 0
pr_warn("Exception %02x in %s mode, FSR=%08x PC=%08x ESR=%08x\n",
type, user_mode(regs) ? "user" : "kernel", fsr,
(unsigned int) regs->pc, (unsigned int) regs->esr);
#endif
switch ( type & 0x1F ) {
case V_22 :
if ( F_16 ( V_6 ) ) {
F_17 ( L_3 ) ;
F_9 ( V_23 , V_6 , V_24 , V_12 ) ;
return;
}
F_4 ( L_4 ) ;
F_1 ( L_5 , V_6 , V_25 ) ;
break;
case V_26 :
if ( F_16 ( V_6 ) ) {
F_17 ( L_6 ) ;
F_9 ( V_25 , V_6 , V_27 , V_12 ) ;
return;
}
F_4 ( L_7 ) ;
F_1 ( L_8 , V_6 , V_25 ) ;
break;
case V_28 :
if ( F_16 ( V_6 ) ) {
F_17 ( L_9 ) ;
F_9 ( V_25 , V_6 , V_27 , V_12 ) ;
return;
}
F_4 ( L_10 ) ;
F_1 ( L_8 , V_6 , V_25 ) ;
break;
case V_29 :
if ( F_16 ( V_6 ) ) {
F_17 ( L_11 ) ;
F_9 ( V_30 , V_6 , V_31 , V_12 ) ;
return;
}
F_4 ( L_12 ) ;
F_1 ( L_13 , V_6 , V_25 ) ;
break;
case V_32 :
F_17 ( L_14 ) ;
if ( V_20 & V_33 )
V_20 = V_34 ;
else if ( V_20 & V_35 )
V_20 = V_36 ;
else if ( V_20 & V_37 )
V_20 = V_38 ;
else if ( V_20 & V_39 )
V_20 = V_40 ;
else if ( V_20 & V_41 )
V_20 = V_42 ;
F_9 ( V_30 , V_6 , V_20 , V_12 ) ;
break;
#ifdef F_15
case V_43 :
F_17 ( L_15 ) ;
F_9 ( V_23 , V_6 , V_44 , V_12 ) ;
break;
#endif
default:
F_4 ( L_16 ,
type , ( unsigned int ) V_12 ,
F_12 ( V_6 ) ? L_17 : L_18 ) ;
}
return;
}
