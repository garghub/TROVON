unsigned long
F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
long V_7 = ( V_6 & V_8 ) ;
unsigned long V_9 , V_10 = V_11 - 1 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_15 * V_16 ;
if ( V_4 > V_17 )
return - V_18 ;
if ( V_6 & V_19 ) {
if ( F_2 ( V_13 , V_3 , V_4 ) )
return - V_20 ;
return V_3 ;
}
#ifdef F_3
if ( F_4 ( V_3 ) == V_21 )
V_3 = 0 ;
#endif
if ( ! V_3 )
V_3 = V_13 -> V_22 ;
if ( V_7 && ( V_23 > 0xfffffffful ) )
V_10 = V_24 - 1 ;
V_25:
V_9 = V_3 = ( V_3 + V_10 ) & ~ V_10 ;
for ( V_16 = F_5 ( V_13 , V_3 ) ; ; V_16 = V_16 -> V_26 ) {
if ( V_23 - V_4 < V_3 || V_17 - V_4 < F_6 ( V_3 ) ) {
if ( V_9 != V_27 ) {
V_3 = V_27 ;
goto V_25;
}
return - V_18 ;
}
if ( ! V_16 || V_3 + V_4 <= V_16 -> V_28 ) {
V_13 -> V_22 = V_3 + V_4 ;
return V_3 ;
}
V_3 = ( V_16 -> V_29 + V_10 ) & ~ V_10 ;
}
}
T_1 long
F_7 ( int V_30 , int V_31 )
{
long V_32 ;
V_32 = F_8 ( V_30 , V_31 ) ;
if ( V_32 >= 0 ) {
F_9 () ;
V_32 = 20 - V_32 ;
}
return V_32 ;
}
T_1 unsigned long
F_10 ( void )
{
return V_11 ;
}
T_1 unsigned long
F_11 ( unsigned long V_33 )
{
unsigned long V_34 = F_12 ( V_33 ) ;
F_9 () ;
return V_34 ;
}
T_1 long
F_13 ( void )
{
struct V_35 * V_36 = F_14 ( V_14 ) ;
int V_37 [ 2 ] ;
int V_34 ;
V_34 = F_15 ( V_37 , 0 ) ;
if ( V_34 )
goto V_38;
V_34 = V_37 [ 0 ] ;
V_36 -> V_39 = V_37 [ 1 ] ;
V_38:
return V_34 ;
}
int F_16 ( unsigned long V_3 , unsigned long V_4 ,
unsigned long V_6 )
{
unsigned long V_40 ;
V_40 = F_6 ( V_3 ) ;
if ( ( V_4 > V_17 ) || ( V_40 > ( V_17 - V_4 ) ) )
return - V_20 ;
return 0 ;
}
T_1 unsigned long
F_17 ( unsigned long V_3 , unsigned long V_4 , int V_41 , int V_6 , int V_37 , long V_5 )
{
V_3 = F_18 ( V_3 , V_4 , V_41 , V_6 , V_37 , V_5 ) ;
if ( ! F_19 ( ( void * ) V_3 ) )
F_9 () ;
return V_3 ;
}
T_1 unsigned long
F_20 ( unsigned long V_3 , unsigned long V_4 , int V_41 , int V_6 , int V_37 , long V_42 )
{
if ( F_21 ( V_42 ) != 0 )
return - V_20 ;
V_3 = F_18 ( V_3 , V_4 , V_41 , V_6 , V_37 , V_42 >> V_43 ) ;
if ( ! F_19 ( ( void * ) V_3 ) )
F_9 () ;
return V_3 ;
}
T_1 unsigned long
F_22 ( unsigned long V_3 , unsigned long V_44 , unsigned long V_45 , unsigned long V_6 ,
unsigned long V_46 )
{
extern unsigned long V_47 ( unsigned long V_3 ,
unsigned long V_44 ,
unsigned long V_45 ,
unsigned long V_6 ,
unsigned long V_46 ) ;
F_23 ( & V_14 -> V_13 -> V_48 ) ;
{
V_3 = V_47 ( V_3 , V_44 , V_45 , V_6 , V_46 ) ;
}
F_24 ( & V_14 -> V_13 -> V_48 ) ;
if ( F_19 ( ( void * ) V_3 ) )
return V_3 ;
F_9 () ;
return V_3 ;
}
T_1 long
F_25 ( unsigned long V_49 , unsigned long V_50 , unsigned long V_42 , unsigned long V_4 ,
void * V_51 )
{
return - V_52 ;
}
T_1 long
F_26 ( unsigned long V_49 , unsigned long V_50 , unsigned long V_42 , unsigned long V_4 ,
void * V_51 )
{
return - V_52 ;
}
