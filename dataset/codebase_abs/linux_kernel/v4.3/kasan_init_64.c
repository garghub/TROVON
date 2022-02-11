static int T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_2 ) ) ;
V_3 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_3 ) ) ;
return F_4 ( V_2 , V_3 + 1 , V_4 ) ;
}
static void T_1 F_5 ( unsigned long V_2 ,
unsigned long V_3 )
{
for (; V_2 < V_3 ; V_2 += V_5 )
F_6 ( F_7 ( V_2 ) ) ;
}
static void T_1 F_8 ( T_2 * V_6 )
{
int V_7 ;
unsigned long V_2 = V_8 ;
unsigned long V_3 = V_9 ;
for ( V_7 = F_9 ( V_2 ) ; V_2 < V_3 ; V_7 ++ ) {
V_6 [ V_7 ] = F_10 ( F_11 ( V_10 )
| V_11 ) ;
V_2 += V_5 ;
}
}
static int F_12 ( struct V_12 * V_13 ,
unsigned long V_14 ,
void * V_15 )
{
if ( V_14 == V_16 ) {
F_13 ( L_1 ) ;
F_13 ( L_2 ) ;
}
return V_17 ;
}
void T_1 F_14 ( void )
{
int V_7 ;
T_3 V_18 = F_11 ( V_19 ) | V_20 ;
T_4 V_21 = F_11 ( V_22 ) | V_11 ;
T_5 V_23 = F_11 ( V_24 ) | V_11 ;
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ )
V_22 [ V_7 ] = F_15 ( V_18 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ )
V_24 [ V_7 ] = F_16 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_27 ; V_7 ++ )
V_10 [ V_7 ] = F_17 ( V_23 ) ;
F_8 ( V_28 ) ;
F_8 ( V_29 ) ;
}
void T_1 F_18 ( void )
{
int V_7 ;
#ifdef F_19
F_20 ( & V_30 ) ;
#endif
memcpy ( V_28 , V_29 , sizeof( V_28 ) ) ;
F_21 ( V_28 ) ;
F_22 () ;
F_5 ( V_8 , V_9 ) ;
F_23 ( ( void * ) V_8 ,
F_2 ( ( void * ) V_31 ) ) ;
for ( V_7 = 0 ; V_7 < V_32 ; V_7 ++ ) {
if ( V_33 [ V_7 ] . V_3 == 0 )
break;
if ( F_1 ( & V_33 [ V_7 ] ) )
F_24 ( L_3 ) ;
}
F_23 (
F_2 ( ( void * ) V_31 + V_34 ) ,
F_2 ( ( void * ) V_35 ) ) ;
F_4 ( ( unsigned long ) F_2 ( V_36 ) ,
( unsigned long ) F_2 ( V_37 ) ,
V_4 ) ;
F_23 ( F_2 ( ( void * ) V_38 ) ,
( void * ) V_9 ) ;
memset ( V_19 , 0 , V_39 ) ;
F_21 ( V_29 ) ;
F_22 () ;
V_40 . V_41 = 0 ;
F_25 ( L_4 ) ;
}
