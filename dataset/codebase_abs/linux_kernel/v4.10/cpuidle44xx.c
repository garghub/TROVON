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
unsigned long V_9 ;
F_4 ( & V_10 , V_9 ) ;
V_7 -> V_11 ++ ;
if ( V_7 -> V_11 == F_5 () ) {
F_6 ( V_12 , V_7 -> V_13 ) ;
F_7 ( V_12 , V_7 -> V_14 ) ;
}
F_8 ( & V_10 , V_9 ) ;
F_9 ( V_2 -> V_15 , V_7 -> V_16 ) ;
F_4 ( & V_10 , V_9 ) ;
if ( V_7 -> V_11 == F_5 () )
F_7 ( V_12 , V_17 ) ;
V_7 -> V_11 -- ;
F_8 ( & V_10 , V_9 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_8 + V_5 ;
T_1 V_18 = 0 ;
if ( V_2 -> V_15 == 0 && F_11 ( 1 , V_19 ) ) {
while ( F_12 ( V_20 [ 1 ] ) != V_21 ) {
F_13 () ;
if ( V_22 [ 1 ] )
goto V_23;
}
}
V_18 = ( V_7 -> V_14 == V_24 ) &&
( V_7 -> V_13 == V_21 ) ;
F_14 () ;
F_15 () ;
if ( V_2 -> V_15 == 0 ) {
F_6 ( V_12 , V_7 -> V_13 ) ;
F_7 ( V_12 , V_7 -> V_14 ) ;
if ( V_18 )
F_16 () ;
}
F_9 ( V_2 -> V_15 , V_7 -> V_16 ) ;
V_22 [ V_2 -> V_15 ] = true ;
if ( V_2 -> V_15 == 0 && F_11 ( 1 , V_19 ) ) {
if ( F_17 ( V_25 ) &&
V_18 )
F_18 () ;
F_19 ( V_26 [ 1 ] ) ;
F_7 ( V_20 [ 1 ] , V_17 ) ;
F_20 ( V_26 [ 1 ] ) ;
if ( F_17 ( V_25 ) &&
V_18 ) {
while ( F_21 () ) {
F_22 ( 1 ) ;
F_13 () ;
}
F_23 () ;
}
}
F_24 () ;
if ( V_2 -> V_15 == 0 && V_18 )
F_25 () ;
F_26 () ;
V_23:
F_27 ( V_2 , & V_27 ) ;
V_22 [ V_2 -> V_15 ] = false ;
return V_5 ;
}
static void F_28 ( void * V_28 )
{
F_29 () ;
}
int T_2 F_30 ( void )
{
struct V_3 * V_29 ;
if ( F_31 () ) {
V_8 = & V_30 [ 0 ] ;
V_29 = & V_31 ;
} else {
V_8 = & V_32 [ 0 ] ;
V_29 = & V_33 ;
}
V_12 = F_32 ( L_1 ) ;
V_20 [ 0 ] = F_32 ( L_2 ) ;
V_20 [ 1 ] = F_32 ( L_3 ) ;
if ( ( ! V_12 ) || ( ! V_20 [ 0 ] ) || ( ! V_20 [ 1 ] ) )
return - V_34 ;
V_26 [ 0 ] = F_33 ( L_4 ) ;
V_26 [ 1 ] = F_33 ( L_5 ) ;
if ( ! V_26 [ 0 ] || ! V_26 [ 1 ] )
return - V_34 ;
F_34 ( F_28 , NULL , 1 ) ;
return F_35 ( V_29 , V_19 ) ;
}
