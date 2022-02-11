static T_1
int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned long V_7 )
{
V_4 -> V_8 = ( unsigned long ) V_2 -> V_9 + V_10 ;
if ( F_2 ( V_2 -> V_11 ) ) {
V_6 -> V_12 = V_13 ;
V_2 -> V_11 ( V_2 , V_4 , 0 ) ;
}
F_3 ( V_14 , NULL ) ;
if ( V_7 )
V_4 -> V_8 = V_7 ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( F_5 ( V_2 ) )
return F_1 ( V_2 , V_4 , V_6 , 0 ) ;
else
return 0 ;
}
void F_6 ( unsigned long V_8 , unsigned long V_15 ,
struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_18 ;
F_7 ( V_18 ) ;
F_8 () ;
V_2 = F_9 ( ( V_19 * ) V_8 ) ;
if ( F_2 ( ! V_2 ) || F_10 ( V_2 ) )
goto V_20;
V_6 = F_11 () ;
if ( F_12 () ) {
F_13 ( V_2 ) ;
} else {
unsigned long V_7 = V_4 -> V_8 ;
V_4 -> V_8 -= V_10 ;
F_3 ( V_14 , V_2 ) ;
V_6 -> V_12 = V_21 ;
if ( ! V_2 -> V_22 || ! V_2 -> V_22 ( V_2 , V_4 ) )
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
}
V_20:
F_14 ( V_18 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_24 = NULL ;
V_2 -> V_23 . V_25 = - 1 ;
return 0 ;
}
