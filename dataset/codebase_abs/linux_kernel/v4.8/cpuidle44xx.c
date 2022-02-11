static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 () ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_8 + V_5 ;
T_1 V_9 = 0 ;
if ( V_2 -> V_10 == 0 && F_4 ( 1 , V_11 ) ) {
while ( F_5 ( V_12 [ 1 ] ) != V_13 ) {
F_6 () ;
if ( V_14 [ 1 ] )
goto V_15;
}
}
V_9 = ( V_7 -> V_16 == V_17 ) &&
( V_7 -> V_18 == V_13 ) ;
F_7 () ;
F_8 () ;
if ( V_2 -> V_10 == 0 ) {
F_9 ( V_19 , V_7 -> V_18 ) ;
F_10 ( V_19 , V_7 -> V_16 ) ;
if ( V_9 )
F_11 () ;
}
F_12 ( V_2 -> V_10 , V_7 -> V_20 ) ;
V_14 [ V_2 -> V_10 ] = true ;
if ( V_2 -> V_10 == 0 && F_4 ( 1 , V_11 ) ) {
if ( F_13 ( V_21 ) &&
V_9 )
F_14 () ;
F_15 ( V_22 [ 1 ] ) ;
F_10 ( V_12 [ 1 ] , V_23 ) ;
F_16 ( V_22 [ 1 ] ) ;
if ( F_13 ( V_21 ) &&
V_9 ) {
while ( F_17 () ) {
F_18 ( 1 ) ;
F_6 () ;
}
F_19 () ;
}
}
F_20 () ;
if ( V_2 -> V_10 == 0 && V_9 )
F_21 () ;
F_22 () ;
V_15:
F_23 ( V_2 , & V_24 ) ;
V_14 [ V_2 -> V_10 ] = false ;
return V_5 ;
}
static void F_24 ( void * V_25 )
{
F_25 () ;
}
int T_2 F_26 ( void )
{
V_19 = F_27 ( L_1 ) ;
V_12 [ 0 ] = F_27 ( L_2 ) ;
V_12 [ 1 ] = F_27 ( L_3 ) ;
if ( ( ! V_19 ) || ( ! V_12 [ 0 ] ) || ( ! V_12 [ 1 ] ) )
return - V_26 ;
V_22 [ 0 ] = F_28 ( L_4 ) ;
V_22 [ 1 ] = F_28 ( L_5 ) ;
if ( ! V_22 [ 0 ] || ! V_22 [ 1 ] )
return - V_26 ;
F_29 ( F_24 , NULL , 1 ) ;
return F_30 ( & V_27 , V_11 ) ;
}
