int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( struct V_5 ) ;
if ( ! V_2 -> V_4 )
return - V_6 ;
F_3 (cpu) {
struct V_5 * V_7 = F_4 ( V_2 -> V_4 , V_3 ) ;
F_5 ( & V_7 -> V_8 ) ;
V_7 -> V_9 = NULL ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_4 ) ;
}
static inline void F_8 ( struct V_5 * V_7 ,
struct V_10 * V_11 )
{
F_9 ( & V_7 -> V_8 ) ;
V_11 -> V_12 = V_7 -> V_9 ;
V_7 -> V_9 = V_11 ;
F_10 ( & V_7 -> V_8 ) ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_7 = F_12 ( V_2 -> V_4 ) ;
F_8 ( V_7 , V_11 ) ;
}
void F_13 ( struct V_1 * V_2 , void * V_13 , T_1 V_14 ,
T_1 V_15 )
{
struct V_5 * V_7 ;
unsigned long V_16 ;
int V_17 , V_3 , V_18 ;
V_18 = V_15 / F_14 () + 1 ;
V_17 = 0 ;
F_15 ( V_16 ) ;
F_3 (cpu) {
V_19:
V_7 = F_4 ( V_2 -> V_4 , V_3 ) ;
F_8 ( V_7 , V_13 ) ;
V_17 ++ ;
V_13 += V_14 ;
if ( V_17 == V_15 )
break;
if ( V_17 % V_18 )
goto V_19;
}
F_16 ( V_16 ) ;
}
struct V_10 * F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_7 ;
struct V_10 * V_11 ;
int V_20 , V_3 ;
V_20 = V_3 = F_18 () ;
while ( 1 ) {
V_7 = F_4 ( V_2 -> V_4 , V_3 ) ;
F_9 ( & V_7 -> V_8 ) ;
V_11 = V_7 -> V_9 ;
if ( V_11 ) {
V_7 -> V_9 = V_11 -> V_12 ;
F_10 ( & V_7 -> V_8 ) ;
return V_11 ;
}
F_10 ( & V_7 -> V_8 ) ;
V_3 = F_19 ( V_3 , V_21 ) ;
if ( V_3 >= V_22 )
V_3 = 0 ;
if ( V_3 == V_20 )
return NULL ;
}
}
