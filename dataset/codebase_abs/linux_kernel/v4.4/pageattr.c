static int F_1 ( T_1 * V_1 , T_2 V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
T_1 V_7 = * V_1 ;
V_7 = F_2 ( V_7 , V_6 -> V_8 ) ;
V_7 = F_3 ( V_7 , V_6 -> V_9 ) ;
F_4 ( V_1 , V_7 ) ;
return 0 ;
}
static int F_5 ( unsigned long V_3 , int V_10 ,
T_3 V_9 , T_3 V_8 )
{
unsigned long V_11 = V_3 ;
unsigned long V_12 = V_13 * V_10 ;
unsigned long V_14 = V_11 + V_12 ;
int V_15 ;
struct V_5 V_4 ;
if ( ! F_6 ( V_3 ) ) {
V_11 &= V_16 ;
V_14 = V_11 + V_12 ;
F_7 ( 1 ) ;
}
if ( V_11 < V_17 || V_11 >= V_18 )
return - V_19 ;
if ( V_14 < V_17 || V_14 >= V_18 )
return - V_19 ;
V_4 . V_9 = V_9 ;
V_4 . V_8 = V_8 ;
V_15 = F_8 ( & V_20 , V_11 , V_12 , F_1 ,
& V_4 ) ;
F_9 ( V_11 , V_14 ) ;
return V_15 ;
}
int F_10 ( unsigned long V_3 , int V_10 )
{
return F_5 ( V_3 , V_10 ,
F_11 ( V_21 ) ,
F_11 ( V_22 ) ) ;
}
int F_12 ( unsigned long V_3 , int V_10 )
{
return F_5 ( V_3 , V_10 ,
F_11 ( V_22 ) ,
F_11 ( V_21 ) ) ;
}
int F_13 ( unsigned long V_3 , int V_10 )
{
return F_5 ( V_3 , V_10 ,
F_11 ( V_23 ) ,
F_11 ( 0 ) ) ;
}
int F_14 ( unsigned long V_3 , int V_10 )
{
return F_5 ( V_3 , V_10 ,
F_11 ( 0 ) ,
F_11 ( V_23 ) ) ;
}
