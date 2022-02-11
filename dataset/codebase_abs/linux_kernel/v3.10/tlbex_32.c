T_1 int T_2
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_3 * V_5 ;
T_4 * V_6 ;
T_5 * V_7 ;
T_6 * V_8 ;
T_6 V_9 ;
if ( V_4 >= V_10 && V_4 < V_11 ) {
V_5 = F_2 ( V_4 ) ;
} else {
if ( F_3 ( V_4 >= V_12 || ! V_13 -> V_14 ) )
return 1 ;
V_5 = F_4 ( V_13 -> V_14 , V_4 ) ;
}
V_6 = F_5 ( V_5 , V_4 ) ;
if ( F_6 ( V_6 ) )
return 1 ;
V_7 = F_7 ( V_6 , V_4 ) ;
if ( F_8 ( V_7 ) )
return 1 ;
V_8 = F_9 ( V_7 , V_4 ) ;
V_9 = * V_8 ;
if ( F_3 ( F_10 ( V_9 ) || F_11 ( V_9 ) ) )
return 1 ;
if ( F_3 ( V_3 && ! F_12 ( V_9 ) ) )
return 1 ;
if ( V_3 )
V_9 = F_13 ( V_9 ) ;
V_9 = F_14 ( V_9 ) ;
F_15 ( V_8 , V_9 ) ;
#if F_16 ( V_15 ) && ! F_16 ( V_16 )
if ( V_3 == V_17 )
F_17 ( F_18 () , V_4 & V_18 ) ;
#endif
F_19 ( V_3 ) ;
F_20 ( NULL , V_4 , V_8 ) ;
return 0 ;
}
