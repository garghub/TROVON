void F_1 ( int V_1 , unsigned long V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
F_2 ( V_5 L_1 ,
V_1 , V_2 , V_3 ) ;
F_2 ( V_6 L_2 , V_1 ) ;
F_2 ( V_6 L_3 ) ;
for ( V_4 = V_2 ; V_4 < V_3 ; V_4 += V_7 ) {
V_8 [ V_4 / V_7 ] = V_1 ;
F_2 ( V_9 L_4 , V_4 ) ;
}
F_2 ( V_9 L_5 ) ;
}
unsigned long F_3 ( int V_1 , unsigned long V_10 ,
unsigned long V_11 )
{
unsigned long V_12 = V_11 - V_10 ;
if ( ! V_12 )
return 0 ;
return ( V_12 + 1 ) * sizeof( struct V_13 ) ;
}
void * F_4 ( int V_1 , unsigned long V_14 )
{
void * V_15 = V_16 [ V_1 ] ;
V_14 = F_5 ( V_14 , V_17 ) ;
if ( ! V_15 || ( V_15 + V_14 ) > V_18 [ V_1 ] )
return NULL ;
V_16 [ V_1 ] += V_14 ;
memset ( V_15 , 0 , V_14 ) ;
return V_15 ;
}
void F_6 ( T_1 * V_19 )
{
int V_20 ;
F_7 (node) {
unsigned long V_21 , V_10 , V_12 , V_4 ;
V_21 = ( unsigned long ) V_22 [ V_20 ] ;
V_10 = V_23 [ V_20 ] ;
V_12 = ( V_18 [ V_20 ] -
V_22 [ V_20 ] ) >> V_24 ;
F_2 ( V_6 L_6 , V_25 , V_20 ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 += V_26 ) {
unsigned long V_27 = V_21 + ( V_4 << V_24 ) ;
T_1 * V_28 = V_19 + F_8 ( V_27 ) ;
T_2 * V_29 = F_9 ( V_28 , V_27 ) ;
T_3 * V_30 = F_10 ( V_29 , V_27 ) ;
F_11 ( V_30 , F_12 ( V_10 + V_4 ,
V_31 ) ) ;
F_2 ( V_6 L_7 ,
V_25 , V_27 , V_10 + V_4 ) ;
}
}
}
void T_4 F_13 ( int V_1 , T_5 V_2 , T_5 V_3 )
{
unsigned long V_10 = V_2 >> V_24 ;
unsigned long V_11 = V_3 >> V_24 ;
unsigned long V_14 , V_4 ;
T_5 V_32 , V_33 ;
void * V_34 ;
F_2 ( V_6 L_8 ,
V_1 , V_10 , V_11 ) ;
V_14 = F_3 ( V_1 , V_10 , V_11 ) ;
V_14 += F_5 ( sizeof( V_35 ) , V_36 ) ;
V_14 = F_5 ( V_14 , V_37 ) ;
V_32 = F_14 ( V_2 , V_3 , V_14 , V_37 ) ;
if ( ! V_32 ) {
F_15 ( L_9 ,
V_14 , V_1 ) ;
return;
}
F_16 ( V_32 , V_14 ) ;
V_33 = F_14 ( V_38 << V_24 ,
V_39 << V_24 ,
V_14 , V_37 ) ;
if ( ! V_33 ) {
F_15 ( L_10 ,
V_14 , V_1 ) ;
F_17 ( V_32 , V_14 ) ;
return;
}
F_16 ( V_33 , V_14 ) ;
V_34 = F_18 ( V_33 ) ;
for ( V_4 = 0 ; V_4 < V_14 > > V_24 ; V_4 += V_26 )
F_19 ( ( unsigned long ) V_34 + ( V_4 << V_24 ) ,
( V_32 >> V_24 ) + V_4 ,
V_40 ) ;
V_23 [ V_1 ] = V_32 >> V_24 ;
V_22 [ V_1 ] = V_34 ;
V_18 [ V_1 ] = V_34 + V_14 ;
V_16 [ V_1 ] = V_34 ;
F_2 ( V_6 L_11 ,
V_1 , V_32 , V_32 + V_14 , V_34 , V_34 + V_14 ) ;
}
void T_4 F_20 ( void )
{
F_21 () ;
#ifdef F_22
V_41 = V_42 = V_43 ;
if ( V_43 > V_39 )
V_41 = V_39 ;
F_2 ( V_44 L_12 ,
F_23 ( V_42 - V_41 ) ) ;
V_45 = V_42 ;
V_46 = ( void * ) F_24 ( V_41 * V_36 - 1 ) + 1 ;
#else
V_45 = V_39 ;
V_46 = ( void * ) F_24 ( V_39 * V_36 - 1 ) + 1 ;
#endif
F_2 ( V_44 L_13 ,
F_23 ( V_39 ) ) ;
F_2 ( V_6 L_14 ,
V_39 , V_41 ) ;
F_2 ( V_6 L_15 ,
( V_47 ) F_25 ( V_39 ) ) ;
F_2 ( V_6 L_16 ,
( V_47 ) F_25 ( V_41 ) ) ;
F_26 () ;
}
