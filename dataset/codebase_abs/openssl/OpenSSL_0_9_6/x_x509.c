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
if ( V_12 -> V_16 != NULL ) F_13 ( V_12 -> V_16 ) ;
V_12 -> V_16 = F_14 ( V_12 -> V_4 -> V_17 , NULL , 0 ) ;
F_15 ( V_2 , V_18 , V_19 ) ;
}
T_2 * V_11 ( void )
{
T_2 * V_12 = NULL ;
T_3 V_20 ;
F_16 ( V_12 , T_2 ) ;
V_12 -> V_21 = 0 ;
V_12 -> V_22 = 1 ;
V_12 -> V_16 = NULL ;
V_12 -> V_23 = 0 ;
V_12 -> V_24 = - 1 ;
V_12 -> V_25 = NULL ;
V_12 -> V_26 = NULL ;
V_12 -> V_27 = NULL ;
F_17 ( V_12 -> V_4 , V_28 ) ;
F_17 ( V_12 -> V_6 , V_29 ) ;
F_17 ( V_12 -> V_8 , V_30 ) ;
F_18 ( V_31 , V_12 , & V_12 -> V_32 ) ;
return ( V_12 ) ;
F_19 ( V_33 ) ;
}
void V_18 ( T_2 * V_2 )
{
int V_34 ;
if ( V_2 == NULL ) return;
V_34 = F_20 ( & V_2 -> V_22 , - 1 , V_35 ) ;
#ifdef F_21
F_21 ( L_1 , V_2 ) ;
#endif
if ( V_34 > 0 ) return;
#ifdef F_22
if ( V_34 < 0 )
{
fprintf ( V_36 , L_2 ) ;
abort () ;
}
#endif
F_23 ( V_31 , V_2 , & V_2 -> V_32 ) ;
F_24 ( V_2 -> V_4 ) ;
F_25 ( V_2 -> V_6 ) ;
F_26 ( V_2 -> V_8 ) ;
F_27 ( V_2 -> V_27 ) ;
F_28 ( V_2 -> V_25 ) ;
F_29 ( V_2 -> V_26 ) ;
if ( V_2 -> V_16 != NULL ) F_13 ( V_2 -> V_16 ) ;
F_13 ( V_2 ) ;
}
int F_30 ( long V_37 , void * V_38 , T_4 * V_39 ,
T_5 * V_40 , T_6 * V_41 )
{
V_42 ++ ;
return ( F_31 ( V_42 - 1 ,
& V_31 , V_37 , V_38 , V_39 , V_40 , V_41 ) ) ;
}
int F_32 ( T_2 * V_43 , int V_44 , void * V_45 )
{
return ( F_33 ( & V_43 -> V_32 , V_44 , V_45 ) ) ;
}
void * F_34 ( T_2 * V_43 , int V_44 )
{
return ( F_35 ( & V_43 -> V_32 , V_44 ) ) ;
}
T_2 * F_36 ( T_2 * * V_2 , unsigned char * * V_3 , long V_10 )
{
unsigned char * V_46 ;
T_2 * V_12 ;
V_46 = * V_3 ;
V_12 = F_8 ( V_2 , V_3 , V_10 ) ;
if( ! V_12 ) return NULL ;
V_10 -= * V_3 - V_46 ;
if( ! V_10 ) return V_12 ;
if( ! F_37 ( & V_12 -> V_27 , V_3 , V_10 ) ) goto V_47;
return V_12 ;
V_47:
V_18 ( V_12 ) ;
return NULL ;
}
int F_38 ( T_2 * V_2 , unsigned char * * V_3 )
{
int V_10 ;
V_10 = F_2 ( V_2 , V_3 ) ;
if( V_2 ) V_10 += F_39 ( V_2 -> V_27 , V_3 ) ;
return V_10 ;
}
