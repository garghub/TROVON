static void F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{ if ( V_2 == 1 ) return;
switch ( V_1 -> V_5 ) {
case 0 :
case 1 : F_2 ( 0xc ) ; F_3 ( V_3 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_3 ( V_4 ) ; F_2 ( 0xd ) ;
F_3 ( 0 ) ; F_2 ( 0xc ) ;
break;
case 2 : F_2 ( 0xc ) ; F_3 ( V_3 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_4 ( V_4 ) ; F_4 ( 0 ) ;
F_2 ( 0xc ) ;
break;
}
}
static int F_5 ( T_1 * V_1 , int V_2 , int V_3 )
{ int V_6 , V_7 ;
if ( V_2 ) {
if ( V_3 != 6 ) return 0xff ;
V_3 = 7 ;
}
switch ( V_1 -> V_5 ) {
case 0 : F_2 ( 0xc ) ; F_3 ( V_3 + 0x10 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_2 ( 0xd ) ; V_6 = F_6 () ;
F_2 ( 0xf ) ; V_7 = F_6 () ;
F_2 ( 0xc ) ;
return F_7 ( V_6 , V_7 ) ;
case 1 : F_2 ( 0xc ) ; F_3 ( V_3 + 0x90 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_2 ( 0xec ) ; F_2 ( 0xee ) ; F_2 ( 0xef ) ; V_6 = F_8 () ;
F_2 ( 0xc ) ;
return V_6 ;
case 2 : F_2 ( 0xc ) ; F_3 ( V_3 + 0x90 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_2 ( 0xec ) ;
V_6 = F_9 () ; V_7 = F_9 () ;
F_2 ( 0xc ) ;
return V_6 ;
}
return - 1 ;
}
static void F_10 ( T_1 * V_1 , char * V_8 , int V_9 )
{ int V_10 , V_6 , V_7 , V_11 , V_12 ;
switch ( V_1 -> V_5 ) {
case 0 : F_2 ( 0xc ) ; F_3 ( 0x10 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
for ( V_10 = 0 ; V_10 < V_9 / 2 ; V_10 ++ ) {
F_2 ( 0xd ) ; V_6 = F_6 () ;
F_2 ( 0xf ) ; V_7 = F_6 () ;
F_2 ( 0xc ) ; V_11 = F_6 () ;
F_2 ( 0xe ) ; V_12 = F_6 () ;
V_8 [ 2 * V_10 ] = F_7 ( V_6 , V_7 ) ;
V_8 [ 2 * V_10 + 1 ] = F_7 ( V_11 , V_12 ) ;
}
F_2 ( 0xc ) ;
break;
case 1 : F_2 ( 0xc ) ; F_3 ( 0x90 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_2 ( 0xec ) ; F_2 ( 0xee ) ;
for ( V_10 = 0 ; V_10 < V_9 / 2 ; V_10 ++ ) {
F_2 ( 0xef ) ; V_6 = F_8 () ;
F_2 ( 0xee ) ; V_7 = F_8 () ;
V_8 [ 2 * V_10 ] = V_6 ;
V_8 [ 2 * V_10 + 1 ] = V_7 ;
}
F_2 ( 0xec ) ;
F_2 ( 0xc ) ;
break;
case 2 : F_2 ( 0xc ) ; F_3 ( 0x90 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_2 ( 0xec ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) V_8 [ V_10 ] = F_9 () ;
F_2 ( 0xc ) ;
break;
}
}
static void F_11 ( T_1 * V_1 , char * V_8 , int V_9 )
{ int V_10 ;
switch ( V_1 -> V_5 ) {
case 0 :
case 1 : F_2 ( 0xc ) ; F_3 ( 0 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
for ( V_10 = 0 ; V_10 < V_9 / 2 ; V_10 ++ ) {
F_3 ( V_8 [ 2 * V_10 ] ) ; F_2 ( 0xd ) ;
F_3 ( V_8 [ 2 * V_10 + 1 ] ) ; F_2 ( 0xc ) ;
}
break;
case 2 : F_2 ( 0xc ) ; F_3 ( 0 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) F_4 ( V_8 [ V_10 ] ) ;
F_2 ( 0xc ) ;
break;
}
}
static void F_12 ( T_1 * V_1 )
{ V_1 -> V_13 = F_8 () ;
V_1 -> V_14 = F_13 () ;
F_2 ( 0xc ) ; F_3 ( 0 ) ; F_2 ( 0xa ) ;
if ( V_1 -> V_5 == 2 ) {
F_2 ( 0xc ) ; F_3 ( 0x9 ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
}
}
static void F_14 ( T_1 * V_1 )
{ F_2 ( 0xc ) ; F_3 ( 0xa ) ; F_2 ( 0x8 ) ; F_2 ( 0xc ) ;
F_3 ( V_1 -> V_13 ) ;
F_2 ( V_1 -> V_14 ) ;
}
static void F_15 ( T_1 * V_1 , char * V_15 , int V_16 )
{ char * V_17 [ 3 ] = { L_1 , L_2 , L_3 } ;
F_16 ( L_4
L_5 ,
V_1 -> V_18 , V_19 , V_1 -> V_20 ,
V_1 -> V_5 , V_17 [ V_1 -> V_5 ] , V_1 -> V_21 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_22 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_22 ) ;
}
