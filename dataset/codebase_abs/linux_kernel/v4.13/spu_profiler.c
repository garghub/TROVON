void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
if ( ! V_1 )
V_1 = V_4 / 1000 ;
V_3 = ( V_5 << V_6 ) / V_1 ;
V_7 = ( V_3 * V_2 ) >> V_6 ;
}
static void F_2 ( int V_8 , int V_9 )
{
T_1 V_10 [ 2 ] ;
T_1 V_11 ;
int V_12 ;
V_11 = V_13 ;
F_3 ( V_8 , V_10 ) ;
for ( V_12 = V_14 - 1 ; V_12 >= 0 ; V_12 -- ) {
V_15 [ V_12 * V_16 + V_9 ]
= ( V_11 & V_10 [ 0 ] ) << 2 ;
V_15 [ ( V_12 + V_14 ) * V_16 + V_9 ]
= ( V_11 & V_10 [ 1 ] ) << 2 ;
V_10 [ 0 ] = V_10 [ 0 ] >> V_17 ;
V_10 [ 1 ] = V_10 [ 1 ] >> V_17 ;
}
}
static int F_4 ( int V_8 )
{
T_2 V_18 ;
int V_9 ;
V_9 = 0 ;
V_18 = F_5 ( V_8 , V_19 ) ;
while ( ! ( V_18 & V_20 ) ) {
F_2 ( V_8 , V_9 ) ;
V_9 ++ ;
if ( V_9 >= V_16 )
break;
V_18 = F_5 ( V_8 , V_19 ) ;
}
return V_9 ;
}
static enum V_21 F_6 ( struct V_22 * V_23 )
{
T_3 V_24 ;
int V_8 , V_25 , V_26 , V_27 , V_28 ;
if ( ! V_29 )
goto V_30;
F_7 (cpu) {
if ( F_8 ( V_8 ) )
continue;
V_25 = F_9 ( V_8 ) ;
F_10 ( & V_31 ,
V_32 ) ;
V_27 = F_4 ( V_8 ) ;
if ( V_27 == 0 ) {
F_11 ( & V_31 ,
V_32 ) ;
continue;
}
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ ) {
V_28 = V_26 + ( V_25 * V_33 ) ;
F_12 ( V_28 ,
V_15 + ( V_26 * V_16 ) ,
V_27 ) ;
}
F_11 ( & V_31 ,
V_32 ) ;
}
F_13 () ;
V_24 = V_7 ;
if ( ! V_29 )
goto V_30;
F_14 ( V_23 , V_23 -> V_34 -> V_35 () , V_24 ) ;
return V_36 ;
V_30:
F_15 ( V_37 L_1 ) ;
return V_38 ;
}
int F_16 ( unsigned int V_2 )
{
T_3 V_24 ;
F_17 ( L_2 , V_39 ) ;
V_24 = V_7 ;
F_18 ( & V_23 , V_40 , V_41 ) ;
F_19 ( & V_23 , V_24 ) ;
V_23 . V_42 = F_6 ;
V_15 = F_20 ( V_33 *
V_16 * sizeof( T_2 ) , V_43 ) ;
if ( ! V_15 )
return - V_44 ;
V_29 = 1 ;
F_21 ( & V_23 , V_24 , V_41 ) ;
F_22 ( & V_45 , V_46 ) ;
return 0 ;
}
void F_23 ( void )
{
V_29 = 1 ;
F_22 ( & V_45 , V_46 ) ;
return;
}
void F_24 ( void )
{
V_29 = 0 ;
F_25 ( & V_23 ) ;
F_26 ( V_15 ) ;
F_17 ( L_3 ) ;
}
void F_27 ( void )
{
V_29 = 0 ;
}
