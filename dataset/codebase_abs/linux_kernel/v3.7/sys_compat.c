T_1 int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , V_2 -> V_4 , V_2 , 0 , NULL , NULL ) ;
}
T_1 int F_3 ( unsigned long V_5 , unsigned long V_6 ,
int T_2 * V_7 , int V_8 ,
int T_2 * V_9 , struct V_1 * V_2 )
{
if ( ! V_6 )
V_6 = V_2 -> V_4 ;
return F_2 ( V_5 , V_6 , V_2 , 0 , V_7 , V_9 ) ;
}
T_1 int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_10 | V_11 | V_3 , V_2 -> V_4 ,
V_2 , 0 , NULL , NULL ) ;
}
T_1 int F_5 ( const char T_2 * V_12 ,
T_3 V_13 , T_3 V_14 ,
struct V_1 * V_2 )
{
int error ;
struct V_15 * V_15 ;
V_15 = F_6 ( V_12 ) ;
error = F_7 ( V_15 ) ;
if ( F_8 ( V_15 ) )
goto V_16;
error = F_9 ( V_15 -> V_17 , F_10 ( V_13 ) ,
F_10 ( V_14 ) , V_2 ) ;
F_11 ( V_15 ) ;
V_16:
return error ;
}
T_1 int F_12 ( T_4 V_18 ,
struct V_19 T_2 * V_20 )
{
struct V_21 V_22 ;
int V_23 ;
T_5 V_24 = F_13 () ;
F_14 ( V_25 ) ;
V_23 = F_15 ( V_18 , (struct V_21 T_2 * ) & V_22 ) ;
F_14 ( V_24 ) ;
if ( F_16 ( & V_22 , V_20 ) )
return - V_26 ;
return V_23 ;
}
static inline void
F_17 ( unsigned long V_27 , unsigned long V_28 , int V_29 )
{
struct V_30 * V_31 = V_32 -> V_33 ;
struct V_34 * V_35 ;
if ( V_28 < V_27 || V_29 )
return;
F_18 ( & V_31 -> V_36 ) ;
V_35 = F_19 ( V_31 , V_27 ) ;
if ( V_35 && V_35 -> V_37 < V_28 ) {
if ( V_27 < V_35 -> V_37 )
V_27 = V_35 -> V_37 ;
if ( V_28 > V_35 -> V_38 )
V_28 = V_35 -> V_38 ;
F_20 ( & V_31 -> V_36 ) ;
F_21 ( V_27 & V_39 , F_22 ( V_28 ) ) ;
return;
}
F_20 ( & V_31 -> V_36 ) ;
}
long F_23 ( struct V_1 * V_2 )
{
unsigned int V_40 = V_2 -> V_2 [ 7 ] ;
switch ( V_40 ) {
case V_41 :
F_17 ( V_2 -> V_2 [ 0 ] , V_2 -> V_2 [ 1 ] , V_2 -> V_2 [ 2 ] ) ;
return 0 ;
case V_42 :
V_32 -> V_43 . V_44 = V_2 -> V_2 [ 0 ] ;
asm ("msr tpidrro_el0, %0" : : "r" (regs->regs[0]));
return 0 ;
default:
return - V_45 ;
}
}
