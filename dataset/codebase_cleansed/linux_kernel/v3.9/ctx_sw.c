struct task_struct *__sched
__switch_to(struct task_struct *prev_task, struct task_struct *next_task)
{
unsigned int tmp;
unsigned int prev = (unsigned int)prev_task;
unsigned int next = (unsigned int)next_task;
int num_words_to_skip = 1;
#ifdef CONFIG_ARC_CURR_IN_REG
num_words_to_skip++;
#endif
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
#ifndef CONFIG_ARC_CURR_IN_REG
"st.a r25, [sp, -4] \n\t"
#endif
"sub sp, sp, %4 \n\t"
"st.as sp, [%3, %1] \n\t"
"sync \n\t"
#ifndef CONFIG_SMP
"st %2, [@_current_task] \n\t"
#else
"lr r24, [identity] \n\t"
"lsr r24, r24, 8 \n\t"
"bmsk r24, r24, 7 \n\t"
"add2 r24, @_current_task, r24 \n\t"
"st %2, [r24] \n\t"
#endif
#ifdef CONFIG_ARC_CURR_IN_REG
"mov r25, %2 \n\t"
#endif
"ld.as sp, [%2, %1] \n\t"
"add sp, sp, %4 \n\t"
#ifndef CONFIG_ARC_CURR_IN_REG
"ld.ab r25, [sp, 4] \n\t"
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
: "n"((TASK_THREAD + THREAD_KSP) / 4), "r"(next), "r"(prev),
"n"(num_words_to_skip * 4)
: "blink"
);
return (struct task_struct *)tmp;
}
