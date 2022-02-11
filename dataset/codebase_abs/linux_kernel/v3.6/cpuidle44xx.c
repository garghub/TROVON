static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 () ;
F_3 () ;
F_4 () ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
int V_9 = F_6 () ;
F_2 () ;
if ( V_2 -> V_10 == 0 && F_7 ( 1 , V_11 ) ) {
while ( F_8 ( V_12 [ 1 ] ) != V_13 ) {
F_9 () ;
if ( V_14 [ 1 ] )
goto V_15;
}
}
F_10 ( V_16 , & V_9 ) ;
F_11 () ;
if ( V_2 -> V_10 == 0 ) {
F_12 ( V_17 , V_7 -> V_18 ) ;
F_13 ( V_17 , V_7 -> V_19 ) ;
if ( ( V_7 -> V_19 == V_20 ) &&
( V_7 -> V_18 == V_13 ) )
F_14 () ;
}
F_15 ( V_2 -> V_10 , V_7 -> V_21 ) ;
V_14 [ V_2 -> V_10 ] = true ;
if ( V_2 -> V_10 == 0 && F_7 ( 1 , V_11 ) ) {
F_16 ( V_22 [ 1 ] ) ;
F_17 ( V_22 [ 1 ] ) ;
}
F_18 () ;
if ( F_19 () )
F_20 () ;
F_10 ( V_23 , & V_9 ) ;
V_15:
F_21 ( V_2 , & V_24 ) ;
V_14 [ V_2 -> V_10 ] = false ;
F_4 () ;
return V_5 ;
}
static void F_22 ( void * V_25 )
{
int V_10 = F_6 () ;
F_10 ( V_26 , & V_10 ) ;
}
int T_1 F_23 ( void )
{
struct V_1 * V_2 ;
unsigned int V_9 = 0 ;
V_17 = F_24 ( L_1 ) ;
V_12 [ 0 ] = F_24 ( L_2 ) ;
V_12 [ 1 ] = F_24 ( L_3 ) ;
if ( ( ! V_17 ) || ( ! V_12 [ 0 ] ) || ( ! V_12 [ 1 ] ) )
return - V_27 ;
V_22 [ 0 ] = F_25 ( L_4 ) ;
V_22 [ 1 ] = F_25 ( L_5 ) ;
if ( ! V_22 [ 0 ] || ! V_22 [ 1 ] )
return - V_27 ;
F_26 ( F_22 , NULL , 1 ) ;
F_27 (cpu_id, cpu_online_mask) {
V_2 = & F_28 ( V_28 , V_9 ) ;
V_2 -> V_10 = V_9 ;
#ifdef F_29
V_2 -> V_29 = * V_11 ;
#endif
F_30 ( & V_30 ) ;
if ( F_31 ( V_2 ) ) {
F_32 ( L_6 , V_31 ) ;
return - V_32 ;
}
}
return 0 ;
}
