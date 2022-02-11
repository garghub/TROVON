int F_1 ( int V_1 , T_1 V_2 )
{
int V_3 = 0 ;
if ( ( V_1 < 0 ) || ( V_1 >= V_4 ) )
return - V_5 ;
F_2 ( & V_6 ) ;
if ( V_7 [ V_1 ] )
V_3 = - V_8 ;
else
V_7 [ V_1 ] = V_2 ;
F_3 ( & V_6 ) ;
return V_3 ;
}
void F_4 ( int V_1 )
{
if ( ( V_1 < 0 ) || ( V_1 >= V_4 ) )
return;
F_2 ( & V_6 ) ;
V_7 [ V_1 ] = NULL ;
F_3 ( & V_6 ) ;
}
static int F_5 ( void * V_9 )
{
struct V_10 V_10 [ 2 ] ;
int V_11 , signal ;
unsigned int V_12 ;
V_13:
signal = F_6 ( V_14 ,
F_7 ( & V_15 ) > 0 ) ;
if ( F_8 ( signal ) )
F_9 ( & V_15 ) ;
V_12 = 0 ;
while ( 1 ) {
T_1 V_2 ;
if ( F_8 ( V_12 > 1 ) ) {
struct V_10 V_16 ;
F_10 ( V_17 L_1
L_2
L_3 , V_18 ) ;
V_11 = F_11 ( & V_16 ) ;
F_10 ( V_17 L_4
L_5 ,
V_18 , V_16 . V_19 , V_16 . V_20 ,
V_16 . V_21 , V_16 . V_1 , V_16 . V_22 ,
V_16 . V_23 , V_16 . V_24 ) ;
F_10 ( V_17 L_6
L_7 , V_18 , V_12 ) ;
if ( V_11 != 0 )
break;
V_12 = V_16 . V_21 ? V_12 + 1 : 0 ;
continue;
}
V_11 = F_11 ( & V_10 [ V_12 ] ) ;
if ( V_11 != 0 )
break;
F_10 ( V_25 L_8
L_5 ,
V_10 [ V_12 ] . V_19 , V_10 [ V_12 ] . V_20 , V_10 [ V_12 ] . V_21 ,
V_10 [ V_12 ] . V_1 , V_10 [ V_12 ] . V_22 , V_10 [ V_12 ] . V_23 ,
V_10 [ V_12 ] . V_24 ) ;
if ( V_10 [ V_12 ] . V_20 ) {
int V_26 ;
F_12 ( L_9 , V_18 ) ;
F_2 ( & V_6 ) ;
for ( V_26 = 0 ; V_26 < V_4 ; V_26 ++ ) {
if ( V_7 [ V_26 ] )
V_7 [ V_26 ] ( NULL , NULL , 1 ) ;
}
F_3 ( & V_6 ) ;
V_12 = 0 ;
continue;
}
if ( V_10 [ 0 ] . V_21 && ! V_12 ) {
V_12 ++ ;
continue;
}
F_2 ( & V_6 ) ;
V_2 = V_7 [ V_10 [ V_12 ] . V_1 ] ;
if ( V_2 )
V_2 ( & V_10 [ 0 ] , V_12 ? & V_10 [ 1 ] : NULL , 0 ) ;
F_3 ( & V_6 ) ;
V_12 = V_10 [ V_12 ] . V_21 ? V_12 + 1 : 0 ;
}
if ( F_13 ( & V_15 ) )
F_14 ( & V_14 ) ;
goto V_13;
return 0 ;
}
void F_15 ( void )
{
F_9 ( & V_15 ) ;
F_14 ( & V_14 ) ;
}
void F_16 ( void )
{
F_15 () ;
F_17 ( V_14 , F_7 ( & V_15 ) == 0 ) ;
}
static int T_2 F_18 ( void )
{
struct V_27 * V_28 ;
V_28 = F_19 ( F_5 , NULL , L_10 ) ;
if ( F_20 ( V_28 ) )
return F_21 ( V_28 ) ;
F_22 ( 14 , 28 ) ;
return 0 ;
}
