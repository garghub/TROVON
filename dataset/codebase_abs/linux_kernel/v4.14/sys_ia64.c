unsigned long
F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
long V_7 = ( V_6 & V_8 ) ;
unsigned long V_9 = 0 ;
struct V_10 * V_11 = V_12 -> V_11 ;
struct V_13 V_14 ;
if ( V_4 > V_15 )
return - V_16 ;
if ( V_6 & V_17 ) {
if ( F_2 ( V_11 , V_3 , V_4 ) )
return - V_18 ;
return V_3 ;
}
#ifdef F_3
if ( F_4 ( V_3 ) == V_19 )
V_3 = 0 ;
#endif
if ( ! V_3 )
V_3 = V_20 ;
if ( V_7 && ( V_21 > 0xfffffffful ) )
V_9 = V_22 & ( V_23 - 1 ) ;
V_14 . V_6 = 0 ;
V_14 . V_24 = V_4 ;
V_14 . V_25 = V_3 ;
V_14 . V_26 = V_21 ;
V_14 . V_9 = V_9 ;
V_14 . V_27 = 0 ;
return F_5 ( & V_14 ) ;
}
T_1 long
F_6 ( int V_28 , int V_29 )
{
long V_30 ;
V_30 = F_7 ( V_28 , V_29 ) ;
if ( V_30 >= 0 ) {
F_8 () ;
V_30 = 20 - V_30 ;
}
return V_30 ;
}
T_1 unsigned long
F_9 ( void )
{
return V_31 ;
}
T_1 unsigned long
F_10 ( unsigned long V_32 )
{
unsigned long V_33 = F_11 ( V_32 ) ;
F_8 () ;
return V_33 ;
}
T_1 long
F_12 ( void )
{
struct V_34 * V_35 = F_13 ( V_12 ) ;
int V_36 [ 2 ] ;
int V_33 ;
V_33 = F_14 ( V_36 , 0 ) ;
if ( V_33 )
goto V_37;
V_33 = V_36 [ 0 ] ;
V_35 -> V_38 = V_36 [ 1 ] ;
V_37:
return V_33 ;
}
int F_15 ( unsigned long V_3 , unsigned long V_4 ,
unsigned long V_6 )
{
unsigned long V_39 ;
V_39 = F_16 ( V_3 ) ;
if ( ( V_4 > V_15 ) || ( V_39 > ( V_15 - V_4 ) ) )
return - V_18 ;
return 0 ;
}
T_1 unsigned long
F_17 ( unsigned long V_3 , unsigned long V_4 , int V_40 , int V_6 , int V_36 , long V_5 )
{
V_3 = F_18 ( V_3 , V_4 , V_40 , V_6 , V_36 , V_5 ) ;
if ( ! F_19 ( ( void * ) V_3 ) )
F_8 () ;
return V_3 ;
}
T_1 unsigned long
F_20 ( unsigned long V_3 , unsigned long V_4 , int V_40 , int V_6 , int V_36 , long V_41 )
{
if ( F_21 ( V_41 ) != 0 )
return - V_18 ;
V_3 = F_18 ( V_3 , V_4 , V_40 , V_6 , V_36 , V_41 >> V_42 ) ;
if ( ! F_19 ( ( void * ) V_3 ) )
F_8 () ;
return V_3 ;
}
T_1 unsigned long
F_22 ( unsigned long V_3 , unsigned long V_43 , unsigned long V_44 , unsigned long V_6 ,
unsigned long V_45 )
{
V_3 = F_23 ( V_3 , V_43 , V_44 , V_6 , V_45 ) ;
if ( ! F_19 ( ( void * ) V_3 ) )
F_8 () ;
return V_3 ;
}
T_1 long
F_24 ( unsigned long V_46 , unsigned long V_47 , unsigned long V_41 , unsigned long V_4 ,
void * V_48 )
{
return - V_49 ;
}
T_1 long
F_25 ( unsigned long V_46 , unsigned long V_47 , unsigned long V_41 , unsigned long V_4 ,
void * V_48 )
{
return - V_49 ;
}
