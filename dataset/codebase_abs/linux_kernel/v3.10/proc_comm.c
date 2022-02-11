static inline void F_1 ( T_1 V_1 )
{
#if F_2 ( V_2 )
F_3 ( 1 << V_1 , V_3 + 0x8 ) ;
#else
F_3 ( 1 , V_4 + 0x400 + ( V_1 * 4 ) ) ;
#endif
}
static inline void F_4 ( void )
{
F_1 ( 6 ) ;
}
static int F_5 ( void T_2 * V_5 , unsigned V_6 )
{
for (; ; ) {
if ( F_6 ( V_5 ) == V_6 )
return 0 ;
if ( V_7 )
if ( V_7 () )
return - V_8 ;
}
}
int F_7 ( unsigned V_9 , unsigned * V_10 , unsigned * V_11 )
{
void T_2 * V_12 = V_13 ;
unsigned long V_14 ;
int V_15 ;
F_8 ( & V_16 , V_14 ) ;
for (; ; ) {
if ( F_5 ( V_12 + V_17 , V_18 ) )
continue;
F_3 ( V_9 , V_12 + V_19 ) ;
F_3 ( V_10 ? * V_10 : 0 , V_12 + V_20 ) ;
F_3 ( V_11 ? * V_11 : 0 , V_12 + V_21 ) ;
F_4 () ;
if ( F_5 ( V_12 + V_19 , V_22 ) )
continue;
if ( F_6 ( V_12 + V_23 ) != V_24 ) {
if ( V_10 )
* V_10 = F_6 ( V_12 + V_20 ) ;
if ( V_11 )
* V_11 = F_6 ( V_12 + V_21 ) ;
V_15 = 0 ;
} else {
V_15 = - V_25 ;
}
break;
}
F_3 ( V_26 , V_12 + V_19 ) ;
F_9 ( & V_16 , V_14 ) ;
return V_15 ;
}
void F_10 ( void )
{
void T_2 * V_12 = V_13 ;
F_5 ( V_12 + V_17 , V_18 ) ;
}
