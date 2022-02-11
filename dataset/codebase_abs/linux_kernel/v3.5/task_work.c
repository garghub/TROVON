int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
unsigned long V_6 ;
int V_7 = - V_8 ;
#ifndef F_2
if ( V_5 )
return - V_9 ;
#endif
F_3 ( & V_2 -> V_10 , V_6 ) ;
if ( F_4 ( ! ( V_2 -> V_6 & V_11 ) ) ) {
F_5 ( & V_4 -> V_12 , & V_2 -> V_13 ) ;
V_7 = 0 ;
}
F_6 ( & V_2 -> V_10 , V_6 ) ;
if ( F_4 ( ! V_7 ) && V_5 )
F_7 ( V_2 ) ;
return V_7 ;
}
struct V_3 *
F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
unsigned long V_6 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
F_3 ( & V_2 -> V_10 , V_6 ) ;
F_9 (twork, pos, &task->task_works, hlist) {
if ( V_4 -> V_14 == V_14 ) {
F_10 ( & V_4 -> V_12 ) ;
goto V_17;
}
}
V_4 = NULL ;
V_17:
F_6 ( & V_2 -> V_10 , V_6 ) ;
return V_4 ;
}
void F_11 ( void )
{
struct V_1 * V_2 = V_18 ;
struct V_19 V_13 ;
struct V_15 * V_16 ;
F_12 ( & V_2 -> V_10 ) ;
F_13 ( & V_2 -> V_13 , & V_13 ) ;
F_14 ( & V_2 -> V_10 ) ;
if ( F_15 ( F_16 ( & V_13 ) ) )
return;
for ( V_16 = V_13 . V_20 ; V_16 -> V_21 ; V_16 = V_16 -> V_21 )
;
for (; ; ) {
struct V_15 * * V_22 = V_16 -> V_22 ;
struct V_3 * V_4 = F_17 ( V_16 , struct V_3 ,
V_12 ) ;
V_4 -> V_14 ( V_4 ) ;
if ( V_22 == & V_13 . V_20 )
break;
V_16 = F_17 ( V_22 , struct V_15 , V_21 ) ;
}
}
