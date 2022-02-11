static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( & V_4 -> V_5 ) & ( 1 << V_3 ) ;
}
static void F_3 ( unsigned int V_3 , int V_6 )
{
T_1 V_7 ;
V_7 = F_2 ( & V_4 -> V_8 ) ;
if ( V_6 )
V_7 |= 1 << V_3 ;
else
V_7 &= ~ ( 1 << V_3 ) ;
F_4 ( V_7 , & V_4 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_6 )
{
unsigned long V_9 ;
F_6 ( & V_10 , V_9 ) ;
F_3 ( V_3 , V_6 ) ;
F_7 () ;
F_8 ( & V_10 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_9 ;
F_6 ( & V_10 , V_9 ) ;
F_4 ( F_2 ( & V_4 -> V_11 ) & ~ ( 1 << V_3 ) ,
& V_4 -> V_11 ) ;
F_7 () ;
F_8 ( & V_10 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_6 )
{
unsigned long V_9 ;
F_6 ( & V_10 , V_9 ) ;
F_3 ( V_3 , V_6 ) ;
F_4 ( F_2 ( & V_4 -> V_11 ) | ( 1 << V_3 ) ,
& V_4 -> V_11 ) ;
F_7 () ;
F_8 ( & V_10 , V_9 ) ;
return 0 ;
}
int T_2 F_11 ( unsigned long V_12 ,
unsigned int V_13 , unsigned int V_14 )
{
V_4 = F_12 ( V_12 , sizeof( struct V_15 ) ) ;
if ( ! V_4 )
return - V_16 ;
V_17 . V_13 = V_13 ;
V_17 . V_18 = V_14 ;
return F_13 ( & V_17 ) ;
}
