int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 , 0 , NULL ) ;
if ( ! V_1 )
goto V_3;
V_4 = F_2 ( L_2 ,
sizeof( struct V_5 ) ,
0 , V_6 , NULL ) ;
if ( ! V_4 )
goto V_3;
V_7 = F_2 ( L_3 ,
sizeof( struct V_8 ) ,
0 , V_6 , NULL ) ;
if ( ! V_7 )
goto V_3;
V_9 = F_2 ( L_4 ,
sizeof( struct V_10 ) ,
0 , 0 , NULL ) ;
if ( ! V_9 )
goto V_3;
V_11 = F_2 ( L_5 ,
sizeof( struct V_12 ) * ( V_13 + 1 ) ,
0 , 0 , NULL ) ;
if ( ! V_11 )
goto V_3;
V_14 = F_2 ( L_6 ,
sizeof( struct V_15 ) ,
0 , 0 , NULL ) ;
if ( ! V_14 )
goto V_3;
V_16 = F_2 ( L_7 ,
sizeof( struct V_17 ) ,
0 , 0 , NULL ) ;
if ( ! V_16 )
goto V_3;
#ifdef F_3
V_18 = F_2 ( L_8 ,
sizeof( struct V_19 ) ,
0 , 0 , NULL ) ;
if ( ! V_18 )
goto V_3;
V_20 = F_2 ( L_9 ,
sizeof( struct V_21 ) ,
0 , 0 , NULL ) ;
if ( ! V_20 )
goto V_3;
#endif
return 0 ;
V_3:
F_4 () ;
return - V_22 ;
}
void F_4 ( void )
{
if( V_1 )
F_5 ( V_1 ) ;
if( V_4 )
F_5 ( V_4 ) ;
if( V_7 )
F_5 ( V_7 ) ;
if( V_9 )
F_5 ( V_9 ) ;
if( V_11 )
F_5 ( V_11 ) ;
if( V_14 )
F_5 ( V_14 ) ;
if( V_16 )
F_5 ( V_16 ) ;
#ifdef F_3
if ( V_18 )
F_5 ( V_18 ) ;
if ( V_20 )
F_5 ( V_20 ) ;
#endif
}
struct V_23 * F_6 ( int V_24 )
{
struct V_23 * V_25 ;
V_25 = F_7 ( sizeof( struct V_23 ) + V_24 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_9 ( struct V_23 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_10 ( V_27 ) ;
}
struct V_2 * F_11 ( void )
{
struct V_2 * V_25 ;
V_25 = F_12 ( V_1 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_13 ( struct V_2 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_1 , V_27 ) ;
}
struct V_5 * F_15 ( void )
{
struct V_5 * V_25 ;
V_25 = F_12 ( V_4 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_16 ( struct V_5 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_4 , V_27 ) ;
}
struct V_8 * F_17 ( void )
{
struct V_8 * V_25 ;
V_25 = F_12 ( V_7 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_18 ( struct V_8 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_7 , V_27 ) ;
}
struct V_10 * F_19 ( void )
{
struct V_10 * V_25 ;
V_25 = F_12 ( V_9 , V_26 ) ;
F_8 ( L_10 ,
V_25 ) ;
return V_25 ;
}
void F_20 ( struct V_10 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_9 , V_27 ) ;
}
static struct V_12 * F_21 ( void )
{
struct V_12 * V_25 ;
V_25 = F_12 ( V_11 , V_26 ) ;
if ( V_25 ) {
int V_28 = 0 ;
for ( V_28 = 0 ; V_28 < V_13 ; V_28 ++ ) {
V_25 [ V_28 ] . V_29 = V_30 ;
V_25 [ V_28 ] . V_31 = NULL ;
}
V_25 [ V_28 ] . V_29 = V_32 ;
V_25 [ V_28 ] . V_31 = NULL ;
}
return V_25 ;
}
int F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 , int V_37 )
{
struct V_12 * * V_38 , * V_39 ;
int V_28 = V_37 ;
F_8 ( L_11 , V_37 ) ;
V_38 = & V_36 -> V_40 ;
V_39 = * V_38 ;
F_8 ( L_12 , V_37 , V_36 -> V_41 ) ;
if ( V_39 && V_39 -> V_29 != V_30 )
V_39 ++ ;
while ( V_28 ) {
if ( ! V_39 ) {
F_8 ( L_13 , V_38 ) ;
V_39 = * V_38 = F_21 () ;
if ( ! V_39 )
return - V_22 ;
}
if ( V_39 -> V_29 == V_32 ) {
V_38 = & V_39 -> V_31 ;
V_39 = * V_38 ;
continue;
}
V_28 -- ;
V_39 ++ ;
}
V_36 -> V_42 = V_37 ;
F_8 ( L_14 ,
V_37 , V_36 -> V_41 , V_36 -> V_40 , V_36 -> V_40 -> V_29 ,
V_36 -> V_40 -> V_31 ) ;
return 0 ;
}
void F_23 ( struct V_12 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_11 , V_27 ) ;
}
struct V_15 * F_24 ( void )
{
struct V_15 * V_25 ;
V_25 = F_12 ( V_14 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_25 ( struct V_15 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_14 , V_27 ) ;
}
struct V_17 * F_26 ( void )
{
struct V_17 * V_25 ;
V_25 = F_12 ( V_16 , V_26 ) ;
F_8 ( L_10 , V_25 ) ;
return V_25 ;
}
void F_27 ( struct V_17 * V_27 )
{
F_8 ( L_10 , V_27 ) ;
F_14 ( V_16 , V_27 ) ;
}
struct V_19 * F_28 ( void )
{
struct V_19 * V_43 ;
V_43 = F_29 ( V_18 , V_26 ) ;
F_8 ( L_10 , V_43 ) ;
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = ( void * ) V_43 ;
F_30 ( & V_43 -> V_47 ) ;
return V_43 ;
}
void F_31 ( struct V_19 * V_43 )
{
F_8 ( L_10 , V_43 ) ;
F_14 ( V_18 , V_43 ) ;
}
struct V_21 * F_32 ( void )
{
struct V_21 * V_39 ;
V_39 = F_29 ( V_20 , V_26 ) ;
F_8 ( L_10 , V_39 ) ;
V_39 -> V_44 = V_48 ;
V_39 -> V_46 = ( void * ) V_39 ;
return V_39 ;
}
void F_33 ( struct V_21 * V_39 )
{
F_8 ( L_10 , V_39 ) ;
F_14 ( V_20 , V_39 ) ;
}
