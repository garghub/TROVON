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
if ( V_2 -> V_9 == 0 && F_4 ( 1 , V_10 ) ) {
while ( F_5 ( V_11 [ 1 ] ) != V_12 ) {
F_6 () ;
if ( V_13 [ 1 ] )
goto V_14;
}
}
F_7 () ;
if ( V_2 -> V_9 == 0 ) {
F_8 ( V_15 , V_7 -> V_16 ) ;
F_9 ( V_15 , V_7 -> V_17 ) ;
if ( ( V_7 -> V_17 == V_18 ) &&
( V_7 -> V_16 == V_12 ) )
F_10 () ;
}
F_11 ( V_2 -> V_9 , V_7 -> V_19 ) ;
V_13 [ V_2 -> V_9 ] = true ;
if ( V_2 -> V_9 == 0 && F_4 ( 1 , V_10 ) ) {
F_12 ( V_20 [ 1 ] ) ;
F_9 ( V_11 [ 1 ] , V_21 ) ;
F_13 ( V_20 [ 1 ] ) ;
}
F_14 () ;
if ( V_2 -> V_9 == 0 && ( V_7 -> V_17 == V_18 ) &&
( V_7 -> V_16 == V_12 ) )
F_15 () ;
V_14:
F_16 ( V_2 , & V_22 ) ;
V_13 [ V_2 -> V_9 ] = false ;
return V_5 ;
}
int T_1 F_17 ( void )
{
V_15 = F_18 ( L_1 ) ;
V_11 [ 0 ] = F_18 ( L_2 ) ;
V_11 [ 1 ] = F_18 ( L_3 ) ;
if ( ( ! V_15 ) || ( ! V_11 [ 0 ] ) || ( ! V_11 [ 1 ] ) )
return - V_23 ;
V_20 [ 0 ] = F_19 ( L_4 ) ;
V_20 [ 1 ] = F_19 ( L_5 ) ;
if ( ! V_20 [ 0 ] || ! V_20 [ 1 ] )
return - V_23 ;
return F_20 ( & V_24 , V_10 ) ;
}
