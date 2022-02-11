T_1 * F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 =
V_4 . V_5 [ V_4 . V_6 ] ;
V_4 . V_6 ++ ;
if ( V_4 . V_6 >= V_7 )
V_4 . V_6 = 0 ;
if ( V_4 . V_6 == V_4 . V_8 ) {
V_4 . V_8 ++ ;
if ( V_4 . V_8 >= V_7 )
V_4 . V_8 = 0 ;
}
F_3 ( & V_3 , V_2 ) ;
return ( T_1 * ) V_1 ;
}
int F_4 ( T_2 * V_9 )
{
int V_8 ;
int V_6 ;
int V_10 = 0 ;
unsigned long V_2 ;
char V_11 [ V_12 ] ;
struct V_13 V_14 ;
T_1 * V_15 ;
F_2 ( & V_3 , V_2 ) ;
V_8 = V_4 . V_8 ;
V_6 = V_4 . V_6 ;
if ( V_6 < V_8 ) {
while ( 1 ) {
V_15 = ( T_1 * )
V_4 . V_5 [ V_8 ] ;
if ( ! V_15 ) {
F_3 ( & V_3 , V_2 ) ;
return 0 ;
}
if (sizeof( unsigned long ) < 8 ) {
F_5 ( V_11 , V_15 -> V_16 . V_17 ) ;
F_6 ( V_15 -> V_18 . V_17 , & V_14 ) ;
} else {
F_5 ( V_11 , V_15 -> V_16 . V_14 ) ;
F_6 ( V_15 -> V_18 . V_14 , & V_14 ) ;
}
V_10 += snprintf ( V_9 -> V_19 + V_10 ,
( V_20 * V_21 * 3 ) - V_10 ,
L_1
L_2 , V_14 . V_22 ,
V_14 . V_23 , V_11 , V_15 -> V_24 , V_15 -> V_25 ,
V_15 -> V_26 [ 0 ] , V_15 -> V_26 [ 1 ] , V_15 -> V_26 [ 2 ] ,
V_15 -> V_26 [ 3 ] , V_15 -> V_26 [ 4 ] ) ;
V_8 ++ ;
if ( V_8 > ( V_7 - 1 ) )
V_8 = 0 ;
if ( V_8 == V_6 )
break;
}
} else if ( V_6 > V_8 ) {
while ( 1 ) {
V_15 = ( T_1 * )
V_4 . V_5 [ V_8 ] ;
if ( ! V_15 ) {
F_3 ( & V_3 , V_2 ) ;
return 0 ;
}
if (sizeof( unsigned long ) < 8 ) {
F_5 ( V_11 , V_15 -> V_16 . V_17 ) ;
F_6 ( V_15 -> V_18 . V_17 , & V_14 ) ;
} else {
F_5 ( V_11 , V_15 -> V_16 . V_14 ) ;
F_6 ( V_15 -> V_18 . V_14 , & V_14 ) ;
}
V_10 += snprintf ( V_9 -> V_19 + V_10 ,
( V_20 * V_21 * 3 ) - V_10 ,
L_1
L_2 , V_14 . V_22 ,
V_14 . V_23 , V_11 , V_15 -> V_24 , V_15 -> V_25 ,
V_15 -> V_26 [ 0 ] , V_15 -> V_26 [ 1 ] , V_15 -> V_26 [ 2 ] ,
V_15 -> V_26 [ 3 ] , V_15 -> V_26 [ 4 ] ) ;
V_8 ++ ;
if ( V_8 == V_6 )
break;
}
}
F_3 ( & V_3 , V_2 ) ;
return V_10 ;
}
int F_7 ( void )
{
unsigned long V_1 ;
int V_27 ;
int V_28 = 0 ;
V_20 = V_29 ;
V_7 = ( V_20 * V_21 ) /
V_30 ;
V_31 = ( unsigned long ) F_8 ( ( V_20 * V_21 ) ) ;
if ( ! V_31 ) {
F_9 (KERN_ERR PFX L_3
L_4 ) ;
V_28 = - V_32 ;
goto V_33;
}
memset ( ( void * ) V_31 , 0 , ( V_20 * V_21 ) ) ;
V_4 . V_5 = F_8 ( V_7 *
sizeof( unsigned long ) ) ;
if ( ! V_4 . V_5 ) {
F_9 (KERN_ERR PFX L_5
L_6 ) ;
if ( V_31 ) {
F_10 ( ( void * ) V_31 ) ;
V_31 = 0 ;
}
V_28 = - V_32 ;
goto V_33;
}
memset ( ( void * ) V_4 . V_5 , 0 ,
( V_7 * sizeof( unsigned long ) ) ) ;
V_4 . V_6 = V_4 . V_8 = 0 ;
V_1 = V_31 ;
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ ) {
V_4 . V_5 [ V_27 ] = V_1 ;
V_1 += V_30 ;
}
V_28 = F_11 () ;
if ( V_28 < 0 ) {
F_9 (KERN_ERR PFX L_7 ) ;
goto V_34;
}
F_9 (KERN_INFO PFX L_8 ) ;
return V_28 ;
V_34:
F_12 () ;
V_33:
return V_28 ;
}
void F_12 ( void )
{
V_35 = 0 ;
F_13 () ;
if ( V_4 . V_5 ) {
F_10 ( ( void * ) V_4 . V_5 ) ;
V_4 . V_5 = NULL ;
}
if ( V_31 ) {
F_10 ( ( void * ) V_31 ) ;
V_31 = 0 ;
}
F_9 (KERN_INFO PFX L_9 ) ;
}
