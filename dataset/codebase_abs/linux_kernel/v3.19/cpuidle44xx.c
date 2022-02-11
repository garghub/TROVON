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
int V_10 = F_4 () ;
if ( V_2 -> V_11 == 0 && F_5 ( 1 , V_12 ) ) {
while ( F_6 ( V_13 [ 1 ] ) != V_14 ) {
F_7 () ;
if ( V_15 [ 1 ] )
goto V_16;
}
}
V_9 = ( V_7 -> V_17 == V_18 ) &&
( V_7 -> V_19 == V_14 ) ;
F_8 ( V_20 , & V_10 ) ;
F_9 () ;
if ( V_2 -> V_11 == 0 ) {
F_10 ( V_21 , V_7 -> V_19 ) ;
F_11 ( V_21 , V_7 -> V_17 ) ;
if ( V_9 )
F_12 () ;
}
F_13 ( V_2 -> V_11 , V_7 -> V_22 ) ;
V_15 [ V_2 -> V_11 ] = true ;
if ( V_2 -> V_11 == 0 && F_5 ( 1 , V_12 ) ) {
if ( F_14 ( V_23 ) &&
V_9 )
F_15 () ;
F_16 ( V_24 [ 1 ] ) ;
F_11 ( V_13 [ 1 ] , V_25 ) ;
F_17 ( V_24 [ 1 ] ) ;
if ( F_14 ( V_23 ) &&
V_9 ) {
while ( F_18 () ) {
F_19 ( 1 ) ;
F_7 () ;
}
F_20 () ;
}
}
F_21 () ;
if ( V_2 -> V_11 == 0 && V_9 )
F_22 () ;
F_8 ( V_26 , & V_10 ) ;
V_16:
F_23 ( V_2 , & V_27 ) ;
V_15 [ V_2 -> V_11 ] = false ;
return V_5 ;
}
static void F_24 ( void * V_28 )
{
int V_11 = F_4 () ;
F_8 ( V_29 , & V_11 ) ;
}
int T_2 F_25 ( void )
{
V_21 = F_26 ( L_1 ) ;
V_13 [ 0 ] = F_26 ( L_2 ) ;
V_13 [ 1 ] = F_26 ( L_3 ) ;
if ( ( ! V_21 ) || ( ! V_13 [ 0 ] ) || ( ! V_13 [ 1 ] ) )
return - V_30 ;
V_24 [ 0 ] = F_27 ( L_4 ) ;
V_24 [ 1 ] = F_27 ( L_5 ) ;
if ( ! V_24 [ 0 ] || ! V_24 [ 1 ] )
return - V_30 ;
F_28 ( F_24 , NULL , 1 ) ;
return F_29 ( & V_31 , V_12 ) ;
}
