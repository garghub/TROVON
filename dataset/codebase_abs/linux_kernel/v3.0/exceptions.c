void F_1 ( const char * V_1 , struct V_2 * V_3 , long V_4 )
{
F_2 () ;
F_3 ( & V_5 ) ;
F_4 ( V_6 L_1 , V_1 , V_4 ) ;
F_5 ( V_3 ) ;
F_6 ( & V_5 ) ;
F_7 ( V_4 ) ;
}
T_1 void F_8 ( struct V_2 * V_7 )
{
F_9 ( V_8 , V_7 , V_9 , V_7 -> V_10 ) ;
F_10 ( V_7 -> V_10 , V_7 -> V_10 + 0x4 ) ;
F_11 ( V_7 -> V_10 , V_7 -> V_10 + 0x4 ) ;
}
void F_9 ( int V_11 , struct V_2 * V_7 , int V_12 , unsigned long V_13 )
{
T_2 V_14 ;
if ( F_12 ( V_7 ) ) {
F_1 ( L_2 , V_7 , V_11 ) ;
}
V_14 . V_15 = V_11 ;
V_14 . V_16 = 0 ;
V_14 . V_17 = V_12 ;
V_14 . V_18 = ( void V_19 * ) V_13 ;
F_13 ( V_11 , & V_14 , V_20 ) ;
}
T_1 void F_14 ( struct V_2 * V_7 , unsigned int type ,
int V_21 , int V_13 )
{
#ifdef F_15
V_13 = V_7 -> V_22 ;
#endif
#if 0
printk(KERN_WARNING "Exception %02x in %s mode, FSR=%08x PC=%08x " \
"ESR=%08x\n",
type, user_mode(regs) ? "user" : "kernel", fsr,
(unsigned int) regs->pc, (unsigned int) regs->esr);
#endif
switch ( type & 0x1F ) {
case V_23 :
if ( F_16 ( V_7 ) ) {
F_17 ( L_3 ) ;
F_9 ( V_24 , V_7 , V_25 , V_13 ) ;
return;
}
F_4 ( V_6 L_4 \
L_5 ) ;
F_1 ( L_6 , V_7 , V_26 ) ;
break;
case V_27 :
if ( F_16 ( V_7 ) ) {
F_17 ( L_7 ) ;
F_9 ( V_26 , V_7 , V_28 , V_13 ) ;
return;
}
F_4 ( V_6 L_8 \
L_5 ) ;
F_1 ( L_9 , V_7 , V_26 ) ;
break;
case V_29 :
if ( F_16 ( V_7 ) ) {
F_17 ( L_10 ) ;
F_9 ( V_26 , V_7 , V_28 , V_13 ) ;
return;
}
F_4 ( V_6 L_11 \
L_5 ) ;
F_1 ( L_9 , V_7 , V_26 ) ;
break;
case V_30 :
if ( F_16 ( V_7 ) ) {
F_17 ( L_12 ) ;
F_9 ( V_24 , V_7 , V_31 , V_13 ) ;
return;
}
F_4 ( V_6 L_13 \
L_5 ) ;
F_1 ( L_14 , V_7 , V_26 ) ;
break;
case V_32 :
F_17 ( L_15 ) ;
if ( V_21 & V_33 )
V_21 = V_34 ;
else if ( V_21 & V_35 )
V_21 = V_36 ;
else if ( V_21 & V_37 )
V_21 = V_38 ;
else if ( V_21 & V_39 )
V_21 = V_40 ;
else if ( V_21 & V_41 )
V_21 = V_42 ;
F_9 ( V_43 , V_7 , V_21 , V_13 ) ;
break;
#ifdef F_15
case V_44 :
F_17 ( L_16 ) ;
F_9 ( V_24 , V_7 , V_45 , V_13 ) ;
break;
#endif
default:
F_4 ( V_6 L_17
L_18 , type , ( unsigned int ) V_13 ,
F_12 ( V_7 ) ? L_19 : L_20 ) ;
}
return;
}
