struct V_1 * F_1 ( void * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_3 ) ;
if ( V_4 )
V_4 -> V_2 = V_2 ;
return V_4 ;
}
void F_3 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
unsigned long V_3 ;
F_4 ( & V_6 -> V_7 , V_3 ) ;
F_5 ( & V_4 -> V_8 , & V_6 -> V_9 ) ;
F_6 ( & V_6 -> V_7 , V_3 ) ;
}
void F_7 ( struct V_5 * V_6 , void * V_10 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_10 ,
F_8 () ? V_11 : V_12 ) ;
if ( V_4 ) {
F_3 ( V_6 , V_4 ) ;
} else {
F_9 ( L_1 , V_6 -> V_13 ) ;
V_6 -> V_14 ( V_6 , V_10 ) ;
}
}
void F_10 ( struct V_5 * V_6 ,
struct V_15 * V_16 )
{
unsigned long V_3 ;
F_4 ( & V_6 -> V_7 , V_3 ) ;
F_11 ( & V_6 -> V_9 , & V_6 -> V_17 ) ;
F_12 ( & V_6 -> V_9 ) ;
F_6 ( & V_6 -> V_7 , V_3 ) ;
F_13 ( V_16 , & V_6 -> V_18 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = F_15 ( V_20 , struct V_5 , V_18 ) ;
struct V_21 V_22 ;
unsigned long V_3 ;
while ( 1 ) {
struct V_1 * V_4 , * V_23 ;
F_12 ( & V_22 ) ;
F_4 ( & V_6 -> V_7 , V_3 ) ;
F_11 ( & V_6 -> V_17 , & V_22 ) ;
F_12 ( & V_6 -> V_17 ) ;
F_6 ( & V_6 -> V_7 , V_3 ) ;
if ( F_16 ( & V_22 ) )
break;
F_17 (task, tmp, &tasks, node) {
V_6 -> V_14 ( V_6 , V_4 -> V_2 ) ;
F_18 ( V_4 ) ;
}
}
}
void F_19 ( struct V_5 * V_6 ,
const char * V_13 , T_2 V_14 )
{
V_6 -> V_13 = V_13 ;
F_12 ( & V_6 -> V_9 ) ;
F_12 ( & V_6 -> V_17 ) ;
F_20 ( & V_6 -> V_7 ) ;
V_6 -> V_14 = V_14 ;
F_21 ( & V_6 -> V_18 , F_14 ) ;
}
void F_22 ( struct V_5 * V_6 )
{
F_23 ( ! F_16 ( & V_6 -> V_9 ) || ! F_16 ( & V_6 -> V_17 ) ) ;
}
