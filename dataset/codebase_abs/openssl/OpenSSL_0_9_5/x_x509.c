T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
int F_2 ( T_2 * V_2 , unsigned char * * V_3 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_4 , V_5 ) ;
F_4 ( V_2 -> V_6 , V_7 ) ;
F_4 ( V_2 -> V_8 , V_9 ) ;
F_5 () ;
F_6 ( V_2 -> V_4 , V_5 ) ;
F_6 ( V_2 -> V_6 , V_7 ) ;
F_6 ( V_2 -> V_8 , V_9 ) ;
F_7 () ;
}
T_2 * F_8 ( T_2 * * V_2 , unsigned char * * V_3 , long V_10 )
{
F_9 ( V_2 , T_2 * , V_11 ) ;
F_10 () ;
F_11 () ;
F_12 ( V_12 -> V_4 , V_13 ) ;
F_12 ( V_12 -> V_6 , V_14 ) ;
F_12 ( V_12 -> V_8 , V_15 ) ;
if ( V_12 -> V_16 != NULL ) Free ( V_12 -> V_16 ) ;
V_12 -> V_16 = F_13 ( V_12 -> V_4 -> V_17 , NULL , 0 ) ;
F_14 ( V_2 , V_18 , V_19 ) ;
}
T_2 * V_11 ( void )
{
T_2 * V_12 = NULL ;
T_3 V_20 ;
F_15 ( V_12 , T_2 ) ;
V_12 -> V_21 = 1 ;
V_12 -> V_22 = 0 ;
V_12 -> V_23 = 0 ;
V_12 -> V_16 = NULL ;
V_12 -> V_24 = NULL ;
F_16 ( V_12 -> V_4 , V_25 ) ;
F_16 ( V_12 -> V_6 , V_26 ) ;
F_16 ( V_12 -> V_8 , V_27 ) ;
F_17 ( V_28 , V_12 , & V_12 -> V_29 ) ;
return ( V_12 ) ;
F_18 ( V_30 ) ;
}
void V_18 ( T_2 * V_2 )
{
int V_31 ;
if ( V_2 == NULL ) return;
V_31 = F_19 ( & V_2 -> V_21 , - 1 , V_32 ) ;
#ifdef F_20
F_20 ( L_1 , V_2 ) ;
#endif
if ( V_31 > 0 ) return;
#ifdef F_21
if ( V_31 < 0 )
{
fprintf ( V_33 , L_2 ) ;
abort () ;
}
#endif
F_22 ( V_28 , V_2 , & V_2 -> V_29 ) ;
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_8 ) ;
F_26 ( V_2 -> V_24 ) ;
if ( V_2 -> V_16 != NULL ) Free ( V_2 -> V_16 ) ;
Free ( V_2 ) ;
}
int F_27 ( long V_34 , void * V_35 , T_4 * V_36 ,
T_5 * V_37 , T_6 * V_38 )
{
V_39 ++ ;
return ( F_28 ( V_39 - 1 ,
& V_28 , V_34 , V_35 , V_36 , V_37 , V_38 ) ) ;
}
int F_29 ( T_2 * V_40 , int V_41 , void * V_42 )
{
return ( F_30 ( & V_40 -> V_29 , V_41 , V_42 ) ) ;
}
void * F_31 ( T_2 * V_40 , int V_41 )
{
return ( F_32 ( & V_40 -> V_29 , V_41 ) ) ;
}
T_2 * F_33 ( T_2 * * V_2 , unsigned char * * V_3 , long V_10 )
{
unsigned char * V_43 ;
T_2 * V_12 ;
V_43 = * V_3 ;
V_12 = F_8 ( V_2 , V_3 , V_10 ) ;
if( ! V_12 ) return NULL ;
V_10 -= * V_3 - V_43 ;
if( ! V_10 ) return V_12 ;
if( ! F_34 ( & V_12 -> V_24 , V_3 , V_10 ) ) goto V_44;
return V_12 ;
V_44:
V_18 ( V_12 ) ;
return NULL ;
}
int F_35 ( T_2 * V_2 , unsigned char * * V_3 )
{
int V_10 ;
V_10 = F_2 ( V_2 , V_3 ) ;
if( V_2 ) V_10 += F_36 ( V_2 -> V_24 , V_3 ) ;
return V_10 ;
}
