T_1 unsigned long F_1 ( void )
{
return V_1 ;
}
unsigned long F_2 ( struct V_2 * V_3 , unsigned long V_4 , unsigned long V_5 , unsigned long V_6 , unsigned long V_7 )
{
struct V_8 V_9 ;
if ( V_7 & V_10 ) {
if ( ( V_7 & V_11 ) &&
( ( V_4 - ( V_6 << V_12 ) ) & ( V_13 - 1 ) ) )
return - V_14 ;
return V_4 ;
}
if ( V_5 > V_15 - V_1 )
return - V_16 ;
if ( ! V_4 )
V_4 = V_17 ;
V_9 . V_7 = 0 ;
V_9 . V_18 = V_5 ;
V_9 . V_19 = V_4 ;
V_9 . V_20 = V_15 ;
V_9 . V_21 = ( V_7 & V_11 ) ?
( V_22 & ( V_13 - 1 ) ) : 0 ;
V_9 . V_23 = V_6 << V_12 ;
return F_3 ( & V_9 ) ;
}
T_1 long F_4 ( struct V_24 * V_25 )
{
int V_26 [ 2 ] ;
int error ;
error = F_5 ( V_26 , 0 ) ;
if ( error )
goto V_27;
V_25 -> V_28 [ V_29 ] = V_26 [ 1 ] ;
error = V_26 [ 0 ] ;
V_27:
return error ;
}
int F_6 ( unsigned long V_4 , unsigned long V_5 )
{
if ( V_5 > V_15 - V_1 || V_4 + V_5 > V_15 - V_1 )
return - V_14 ;
return 0 ;
}
T_1 long F_7 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_30 , unsigned long V_7 , unsigned long V_26 ,
unsigned long V_6 )
{
return F_8 ( V_4 , V_5 , V_30 , V_7 , V_26 ,
V_6 >> ( V_12 - 12 ) ) ;
}
T_1 long F_9 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_30 , unsigned long V_7 , unsigned long V_26 ,
unsigned long V_31 )
{
return F_8 ( V_4 , V_5 , V_30 , V_7 , V_26 , V_31 >> V_12 ) ;
}
long F_10 ( unsigned long V_32 , unsigned long V_33 ,
unsigned long V_30 , unsigned long V_6 ,
unsigned long V_7 )
{
return F_11 ( V_32 , V_33 , V_30 ,
( V_6 >> ( V_12 - 12 ) ) , V_7 ) ;
}
T_1 unsigned long
F_12 ( struct V_24 * V_25 )
{
static int V_34 = 0 ;
if ( V_34 ++ > 5 )
return - V_35 ;
F_13 ( L_1 ,
V_36 -> V_37 , F_14 ( V_36 ) , ( int ) V_25 -> V_28 [ 1 ] ) ;
#ifdef F_15
F_16 ( V_25 ) ;
#endif
return - V_35 ;
}
T_1 void
F_17 ( struct V_24 * V_25 )
{
T_2 V_9 ;
#ifdef F_18
F_13 ( L_2 , V_25 -> V_38 , V_25 -> V_39 ) ;
#endif
V_9 . V_40 = V_41 ;
V_9 . V_42 = 0 ;
V_9 . V_43 = V_44 ;
V_9 . V_45 = ( void V_46 * ) V_25 -> V_38 ;
V_9 . V_47 = 0 ;
F_19 ( V_41 , & V_9 , V_36 ) ;
#ifdef F_18
F_13 ( L_3 , V_25 -> V_38 , V_25 -> V_39 ) ;
#endif
}
T_1 long F_20 ( char V_46 * V_48 , int V_5 )
{
int V_49 , V_50 ;
if ( V_5 < 0 )
return - V_14 ;
F_21 ( & V_51 ) ;
V_49 = strlen ( F_22 () -> V_52 ) + 1 ;
V_50 = - V_14 ;
if ( V_49 > V_5 )
goto V_27;
V_50 = - V_53 ;
if ( ! F_23 ( V_48 , F_22 () -> V_52 , V_49 ) )
V_50 = 0 ;
V_27:
F_24 ( & V_51 ) ;
return V_50 ;
}
