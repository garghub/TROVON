static int T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_2 ) ) ;
V_3 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_3 ) ) ;
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static void T_1 F_5 ( unsigned long V_2 ,
unsigned long V_3 )
{
T_2 * V_5 ;
for (; V_2 < V_3 ; V_2 += V_6 ) {
V_5 = F_6 ( V_2 ) ;
if ( V_7 < 5 )
F_7 ( F_8 ( V_5 , V_2 ) ) ;
else
F_9 ( V_5 ) ;
}
}
static void T_1 F_10 ( T_2 * V_5 )
{
int V_8 ;
unsigned long V_2 = V_9 ;
unsigned long V_3 = V_10 ;
for ( V_8 = F_11 ( V_2 ) ; V_2 < V_3 ; V_8 ++ ) {
switch ( V_7 ) {
case 4 :
V_5 [ V_8 ] = F_12 ( F_13 ( V_11 ) |
V_12 ) ;
break;
case 5 :
V_5 [ V_8 ] = F_12 ( F_13 ( V_13 ) |
V_12 ) ;
break;
default:
F_14 () ;
}
V_2 += V_6 ;
}
}
static int F_15 ( struct V_14 * V_15 ,
unsigned long V_16 ,
void * V_17 )
{
if ( V_16 == V_18 ) {
F_16 ( L_1 ) ;
F_16 ( L_2 ) ;
}
return V_19 ;
}
void T_1 F_17 ( void )
{
int V_8 ;
T_3 V_20 = F_13 ( V_21 ) | V_22 | V_23 ;
T_4 V_24 = F_13 ( V_25 ) | V_12 ;
T_5 V_26 = F_13 ( V_27 ) | V_12 ;
T_6 V_28 = F_13 ( V_11 ) | V_12 ;
for ( V_8 = 0 ; V_8 < V_29 ; V_8 ++ )
V_25 [ V_8 ] = F_18 ( V_20 ) ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ )
V_27 [ V_8 ] = F_19 ( V_24 ) ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_11 [ V_8 ] = F_20 ( V_26 ) ;
for ( V_8 = 0 ; V_7 >= 5 && V_8 < V_32 ; V_8 ++ )
V_13 [ V_8 ] = F_21 ( V_28 ) ;
F_10 ( V_33 ) ;
F_10 ( V_34 ) ;
}
void T_1 F_22 ( void )
{
int V_8 ;
#ifdef F_23
F_24 ( & V_35 ) ;
#endif
memcpy ( V_33 , V_34 , sizeof( V_33 ) ) ;
F_25 ( V_33 ) ;
F_26 () ;
F_5 ( V_9 , V_10 ) ;
F_27 ( ( void * ) V_9 ,
F_2 ( ( void * ) V_36 ) ) ;
for ( V_8 = 0 ; V_8 < V_37 ; V_8 ++ ) {
if ( V_38 [ V_8 ] . V_3 == 0 )
break;
if ( F_1 ( & V_38 [ V_8 ] ) )
F_28 ( L_3 ) ;
}
F_27 (
F_2 ( ( void * ) V_36 + V_39 ) ,
F_2 ( ( void * ) V_40 ) ) ;
F_4 ( ( unsigned long ) F_2 ( V_41 ) ,
( unsigned long ) F_2 ( V_42 ) ,
V_4 ) ;
F_27 ( F_2 ( ( void * ) V_43 ) ,
( void * ) V_10 ) ;
F_25 ( V_34 ) ;
F_26 () ;
memset ( V_21 , 0 , V_44 ) ;
for ( V_8 = 0 ; V_8 < V_29 ; V_8 ++ ) {
T_7 V_45 = F_18 ( F_29 ( V_21 ) | V_46 | V_23 ) ;
F_30 ( & V_25 [ V_8 ] , V_45 ) ;
}
F_26 () ;
V_47 . V_48 = 0 ;
F_31 ( L_4 ) ;
}
