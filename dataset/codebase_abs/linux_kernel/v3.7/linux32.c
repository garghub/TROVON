T_1 int F_1 ( T_2 struct V_1 V_2 )
{
int error ;
struct V_3 * V_3 ;
V_3 = F_2 ( F_3 ( V_2 . V_2 [ 4 ] ) ) ;
error = F_4 ( V_3 ) ;
if ( F_5 ( V_3 ) )
goto V_4;
error = F_6 ( V_3 -> V_5 , F_3 ( V_2 . V_2 [ 5 ] ) ,
F_3 ( V_2 . V_2 [ 6 ] ) , & V_2 ) ;
F_7 ( V_3 ) ;
V_4:
return error ;
}
T_1 T_3 F_8 ( int V_6 , T_4 V_7 , T_5 V_8 , T_5 V_9 ,
T_6 V_10 )
{
return F_9 ( V_6 , F_10 ( V_8 , V_9 ) , V_10 ) ;
}
T_1 long F_11 ( int V_6 , int V_11 ,
unsigned long V_8 , unsigned long V_9 ,
unsigned long V_12 , unsigned long V_13 ,
int V_14 )
{
return F_12 ( V_6 ,
F_10 ( V_8 , V_9 ) , F_10 ( V_12 , V_13 ) ,
V_14 ) ;
}
T_1 long F_13 ( int V_6 , int V_11 ,
unsigned long V_8 , unsigned long V_9 ,
unsigned long V_12 , unsigned long V_13 ,
int V_14 )
{
return F_14 ( V_6 ,
F_10 ( V_8 , V_9 ) , F_10 ( V_12 , V_13 ) ,
V_14 ) ;
}
T_1 long F_15 ( int V_6 , int V_15 , unsigned V_16 ,
unsigned V_17 , unsigned V_18 , unsigned V_19 )
{
return F_16 ( V_6 , V_15 , F_10 ( V_16 , V_17 ) ,
F_10 ( V_18 , V_19 ) ) ;
}
static int T_7 T_8
F_17 ( T_2 struct V_1 V_2 )
{
unsigned long V_20 ;
unsigned long V_21 ;
int T_9 * V_22 , * V_23 ;
V_20 = V_2 . V_2 [ 4 ] ;
V_21 = V_2 . V_2 [ 5 ] ;
if ( ! V_21 )
V_21 = V_2 . V_2 [ 29 ] ;
V_22 = ( int T_9 * ) V_2 . V_2 [ 6 ] ;
V_23 = ( int T_9 * ) V_24 ;
return F_18 ( V_20 , V_21 , & V_2 , 0 ,
V_22 , V_23 ) ;
}
T_1 long F_19 ( T_4 V_25 , T_4 V_26 , char T_9 * V_27 ,
T_6 V_28 )
{
return F_20 ( F_10 ( V_25 , V_26 ) , V_27 , V_28 ) ;
}
