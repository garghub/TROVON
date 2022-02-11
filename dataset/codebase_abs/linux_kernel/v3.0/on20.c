static int F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{ int V_4 , V_5 , V_6 ;
V_6 = ( V_3 << 2 ) + 1 + V_2 ;
F_2 ( 1 ) ; F_3 ( V_6 ) ; F_2 ( 0 ) ;
switch ( V_1 -> V_7 ) {
case 0 : F_4 ( 4 ) ; F_4 ( 6 ) ; V_5 = F_5 () ;
F_4 ( 4 ) ; F_4 ( 6 ) ; V_4 = F_5 () ;
F_4 ( 4 ) ; F_4 ( 6 ) ; F_4 ( 4 ) ; F_4 ( 6 ) ; F_4 ( 4 ) ;
return F_6 ( V_5 , V_4 ) ;
case 1 : F_4 ( 4 ) ; F_4 ( 0x26 ) ; V_6 = F_7 () ;
F_4 ( 4 ) ; F_4 ( 0x26 ) ; F_4 ( 4 ) ;
return V_6 ;
}
return - 1 ;
}
static void F_8 ( T_1 * V_1 , int V_2 , int V_3 , int V_8 )
{ int V_6 ;
V_6 = ( V_3 << 2 ) + 1 + V_2 ;
F_2 ( 1 ) ; F_3 ( V_6 ) ;
F_2 ( 0 ) ; F_3 ( V_8 ) ;
F_2 ( 0 ) ; F_3 ( V_8 ) ;
}
static void F_9 ( T_1 * V_1 )
{ V_1 -> V_9 = F_7 () ;
V_1 -> V_10 = F_10 () ;
F_4 ( 4 ) ; F_11 ( 0 ) ; F_4 ( 0xc ) ; F_4 ( 4 ) ; F_4 ( 6 ) ; F_4 ( 4 ) ; F_4 ( 6 ) ; F_4 ( 4 ) ;
if ( V_1 -> V_7 ) { F_2 ( 2 ) ; F_3 ( 8 ) ; F_2 ( 2 ) ; F_3 ( 9 ) ; }
else { F_2 ( 2 ) ; F_3 ( 0 ) ; F_2 ( 2 ) ; F_3 ( 8 ) ; }
}
static void F_12 ( T_1 * V_1 )
{ F_4 ( 4 ) ; F_11 ( 7 ) ; F_4 ( 4 ) ; F_4 ( 0xc ) ; F_4 ( 4 ) ;
F_11 ( V_1 -> V_9 ) ;
F_4 ( V_1 -> V_10 ) ;
}
static void F_13 ( T_1 * V_1 , char * V_11 , int V_12 )
{ int V_13 , V_5 , V_4 ;
F_2 ( 1 ) ; F_3 ( 1 ) ; F_2 ( 0 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
if ( V_1 -> V_7 ) {
F_4 ( 4 ) ; F_4 ( 0x26 ) ; V_11 [ V_13 ] = F_7 () ;
} else {
F_4 ( 6 ) ; V_5 = F_5 () ; F_4 ( 4 ) ;
F_4 ( 6 ) ; V_4 = F_5 () ; F_4 ( 4 ) ;
V_11 [ V_13 ] = F_6 ( V_5 , V_4 ) ;
}
F_4 ( 4 ) ;
}
static void F_14 ( T_1 * V_1 , char * V_11 , int V_12 )
{ int V_13 ;
F_2 ( 1 ) ; F_3 ( 1 ) ; F_2 ( 0 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) { F_4 ( 5 ) ; F_11 ( V_11 [ V_13 ] ) ; F_4 ( 7 ) ; }
F_4 ( 4 ) ;
}
static void F_15 ( T_1 * V_1 , char * V_14 , int V_15 )
{ char * V_16 [ 2 ] = { L_1 , L_2 } ;
F_16 ( L_3 ,
V_1 -> V_17 , V_18 , V_1 -> V_19 ) ;
F_16 ( L_4 , V_1 -> V_7 ,
V_16 [ V_1 -> V_7 ] , V_1 -> V_20 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_21 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_21 ) ;
}
