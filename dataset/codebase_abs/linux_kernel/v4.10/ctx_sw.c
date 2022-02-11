struct V_1 * T_1
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 = ( unsigned int ) V_2 ;
unsigned int V_6 = ( unsigned int ) V_3 ;
__asm__ __volatile__(
"st.a r13, [sp, -4] \n\t"
"st.a r14, [sp, -4] \n\t"
"st.a r15, [sp, -4] \n\t"
"st.a r16, [sp, -4] \n\t"
"st.a r17, [sp, -4] \n\t"
"st.a r18, [sp, -4] \n\t"
"st.a r19, [sp, -4] \n\t"
"st.a r20, [sp, -4] \n\t"
"st.a r21, [sp, -4] \n\t"
"st.a r22, [sp, -4] \n\t"
"st.a r23, [sp, -4] \n\t"
"st.a r24, [sp, -4] \n\t"
#ifndef F_2
"st.a r25, [sp, -4] \n\t"
#else
"sub sp, sp, 4 \n\t"
#endif
#if V_7 <= 255
"st.as sp, [%3, %1] \n\t"
#else
"add2 r24, %3, %1 \n\t"
"st sp, [r24] \n\t"
#endif
#ifndef F_3
"st %2, [@_current_task] \n\t"
#else
#ifdef F_4
"lr r24, [%4] \n\t"
#ifndef F_5
"lsr r24, r24, 4 \n\t"
#endif
#else
"lr r24, [identity] \n\t"
"lsr r24, r24, 8 \n\t"
"bmsk r24, r24, 7 \n\t"
#endif
"add2 r24, @_current_task, r24 \n\t"
"st %2, [r24] \n\t"
#endif
#ifdef F_2
"mov r25, %2 \n\t"
#endif
"ld.as sp, [%2, %1] \n\t"
#ifndef F_2
"ld.ab r25, [sp, 4] \n\t"
#else
"add sp, sp, 4 \n\t"
#endif
"ld.ab r24, [sp, 4] \n\t"
"ld.ab r23, [sp, 4] \n\t"
"ld.ab r22, [sp, 4] \n\t"
"ld.ab r21, [sp, 4] \n\t"
"ld.ab r20, [sp, 4] \n\t"
"ld.ab r19, [sp, 4] \n\t"
"ld.ab r18, [sp, 4] \n\t"
"ld.ab r17, [sp, 4] \n\t"
"ld.ab r16, [sp, 4] \n\t"
"ld.ab r15, [sp, 4] \n\t"
"ld.ab r14, [sp, 4] \n\t"
"ld.ab r13, [sp, 4] \n\t"
"mov %0, %3 \n\t"
: "=r"(tmp)
: "n"(KSP_WORD_OFF), "r"(next), "r"(prev)
#ifdef F_4
, "i"(CTOP_AUX_LOGIC_GLOBAL_ID)
#endif
: "blink"
);
return (struct V_1 * ) V_4 ;
}
