int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 , V_5 = 0 ;
unsigned char * * V_6 = NULL ;
if ( V_1 == NULL ) return ( 0 ) ;
V_6 = NULL ;
for (; ; )
{
if ( V_3 )
{
V_4 = F_2 ( 1 , V_5 , V_7 ) ;
if ( V_2 == NULL ) return ( V_4 ) ;
V_6 = V_2 ;
F_3 ( V_6 , 1 , V_5 , V_7 ,
V_8 ) ;
}
V_5 += F_4 ( V_1 -> V_9 , V_6 ) ;
if ( ( V_1 -> V_10 ) || V_1 -> V_11 )
V_5 += F_5 ( V_1 -> V_10 , V_6 ) ;
V_5 += F_6 ( V_1 -> V_12 , V_6 ) ;
if ( V_3 ++ ) return ( V_4 ) ;
}
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_13 )
{
int V_14 ;
F_8 ( V_1 , T_1 * , V_15 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_5 -> V_9 , V_16 ) ;
V_5 -> V_11 = 0 ;
if ( ( V_17 . V_18 != 0 ) &&
( V_19 == ( V_8 | V_20 ) ) )
{
V_17 . V_21 = V_17 . V_6 ;
if ( F_12 ( & V_14 , & V_17 . V_6 , V_17 . V_18 ) < 0 ) goto V_22;
V_5 -> V_10 = V_14 ;
V_17 . V_18 -= ( V_17 . V_6 - V_17 . V_21 ) ;
if ( V_5 -> V_10 == 0 ) V_5 -> V_11 = 1 ;
}
F_11 ( V_5 -> V_12 , V_23 ) ;
F_13 ( V_1 , V_24 , V_25 ) ;
}
T_1 * V_15 ( void )
{
T_1 * V_5 = NULL ;
T_2 V_17 ;
F_14 ( V_5 , T_1 ) ;
V_5 -> V_9 = F_15 ( V_26 ) ;
F_16 ( V_5 -> V_12 , V_27 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
return ( V_5 ) ;
F_17 ( V_28 ) ;
}
void V_24 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_18 ( V_1 -> V_9 ) ;
F_19 ( V_1 -> V_12 ) ;
Free ( V_1 ) ;
}
