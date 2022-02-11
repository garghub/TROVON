void F_1 ( struct V_1 * V_2 )
{
if ( V_1 )
F_2 () ;
V_1 = V_2 ;
}
bool F_3 ( void )
{
return V_1 != NULL ;
}
struct V_3 * F_4 ( void )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_5 = V_1 -> V_7 ( V_4 ) ;
if ( V_5 )
goto V_8;
return V_4 ;
V_8:
F_6 ( V_4 ) ;
return NULL ;
}
void F_7 ( struct V_3 * V_4 )
{
V_1 -> V_9 ( V_4 ) ;
F_6 ( V_4 ) ;
}
int F_8 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
return V_1 -> V_12 ( V_4 , V_11 ) ;
}
void F_9 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
V_1 -> V_13 ( V_4 , V_11 ) ;
}
T_1 F_10 ( struct V_3 * V_4 ,
unsigned long V_14 )
{
return V_1 -> V_15 ( V_4 , V_14 ) ;
}
int F_11 ( struct V_3 * V_4 ,
unsigned long V_16 )
{
return V_1 -> V_17 ( V_4 , V_16 ) ;
}
int F_12 ( struct V_3 * V_4 , unsigned long V_14 ,
T_1 V_18 , int V_19 , int V_20 )
{
unsigned long V_21 ;
T_2 V_22 ;
V_22 = 0x1000UL << V_19 ;
V_21 = V_22 - 1 ;
F_13 ( ( V_14 | V_18 ) & V_21 ) ;
return V_1 -> V_23 ( V_4 , V_14 , V_18 , V_19 , V_20 ) ;
}
int F_14 ( struct V_3 * V_4 , unsigned long V_14 , int V_19 )
{
unsigned long V_21 ;
T_2 V_22 ;
V_22 = 0x1000UL << V_19 ;
V_21 = V_22 - 1 ;
F_13 ( V_14 & V_21 ) ;
return V_1 -> V_24 ( V_4 , V_14 , V_19 ) ;
}
