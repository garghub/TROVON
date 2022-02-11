static int F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{ int V_4 , V_5 , V_6 ;
V_6 = V_3 + V_7 [ V_2 ] ;
switch ( V_1 -> V_8 ) {
case 0 : F_2 ( V_6 ) ; V_9 ; F_2 ( 0 ) ;
F_3 ( 6 ) ; V_4 = F_4 () ; F_2 ( 0x80 ) ; V_5 = F_4 () ; F_3 ( 4 ) ;
return F_5 ( V_4 , V_5 ) ;
case 1 : F_2 ( V_6 + 0x20 ) ; V_9 ;
F_2 ( 0 ) ; F_3 ( 0x26 ) ; V_5 = F_6 () ; F_3 ( 4 ) ;
return V_5 ;
case 2 :
case 3 :
case 4 : F_7 ( V_6 + 0x20 ) ; ( void ) F_4 () ;
F_3 ( 0x24 ) ; V_5 = F_8 () ; F_3 ( 4 ) ;
return V_5 ;
}
return - 1 ;
}
static void F_9 ( T_1 * V_1 , int V_2 , int V_3 , int V_10 )
{ int V_6 ;
V_6 = V_3 + V_7 [ V_2 ] ;
switch ( V_1 -> V_8 ) {
case 0 :
case 1 : F_2 ( V_6 ) ; V_9 ; F_2 ( V_10 ) ; V_11 ;
break;
case 2 :
case 3 :
case 4 : F_7 ( V_6 ) ; ( void ) F_4 () ; F_10 ( V_10 ) ;
break;
}
}
static void F_11 ( T_1 * V_1 )
{ V_1 -> V_12 = F_6 () ;
V_1 -> V_13 = F_12 () ;
F_3 ( 4 ) ; F_2 ( 0xff ) ; F_3 ( 6 ) ;
F_3 ( 4 ) ; F_2 ( 0xaa ) ; F_3 ( 6 ) ;
F_3 ( 4 ) ; F_2 ( 0x00 ) ; F_3 ( 6 ) ;
F_3 ( 4 ) ; F_2 ( 0x87 ) ; F_3 ( 6 ) ;
F_3 ( 4 ) ; F_2 ( 0xe0 ) ; F_3 ( 0xc ) ; F_3 ( 0xc ) ; F_3 ( 4 ) ;
}
static void F_13 ( T_1 * V_1 )
{ F_3 ( 0 ) ; F_3 ( 0 ) ; F_3 ( 0 ) ; F_3 ( 4 ) ;
F_2 ( V_1 -> V_12 ) ;
F_3 ( V_1 -> V_13 ) ;
}
static void F_14 ( T_1 * V_1 , char * V_14 , int V_15 )
{ int V_16 , V_4 , V_5 ;
switch ( V_1 -> V_8 ) {
case 0 : F_2 ( 0x48 ) ; V_9 ;
for( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
F_2 ( 0 ) ; F_3 ( 6 ) ; V_4 = F_4 () ;
F_2 ( 0x80 ) ; V_5 = F_4 () ; F_3 ( 4 ) ;
V_14 [ V_16 ] = F_5 ( V_4 , V_5 ) ;
}
break;
case 1 : F_2 ( 0x68 ) ; V_9 ; F_2 ( 0 ) ;
for( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
F_3 ( 0x26 ) ; V_14 [ V_16 ] = F_6 () ; F_3 ( 0x24 ) ;
}
F_3 ( 4 ) ;
break;
case 2 : F_7 ( 0x68 ) ; ( void ) F_4 () ; F_3 ( 0x24 ) ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) V_14 [ V_16 ] = F_8 () ;
F_3 ( 4 ) ;
break;
case 3 : F_7 ( 0x68 ) ; ( void ) F_4 () ; F_3 ( 0x24 ) ;
for ( V_16 = 0 ; V_16 < V_15 / 2 ; V_16 ++ ) ( ( V_17 * ) V_14 ) [ V_16 ] = F_15 () ;
F_3 ( 4 ) ;
break;
case 4 : F_7 ( 0x68 ) ; ( void ) F_4 () ; F_3 ( 0x24 ) ;
for ( V_16 = 0 ; V_16 < V_15 / 4 ; V_16 ++ ) ( ( V_18 * ) V_14 ) [ V_16 ] = F_16 () ;
F_3 ( 4 ) ;
break;
}
}
static void F_17 ( T_1 * V_1 , char * V_14 , int V_15 )
{ int V_19 ;
switch ( V_1 -> V_8 ) {
case 0 :
case 1 : F_2 ( 0x68 ) ; V_9 ;
for ( V_19 = 0 ; V_19 < V_15 ; V_19 ++ ) {
F_3 ( 5 ) ; F_2 ( V_14 [ V_19 ^ 1 ] ) ; F_3 ( 7 ) ;
}
F_3 ( 5 ) ; F_3 ( 4 ) ;
break;
case 2 : F_7 ( 0x48 ) ; ( void ) F_4 () ;
for ( V_19 = 0 ; V_19 < V_15 ; V_19 ++ ) F_10 ( V_14 [ V_19 ^ 1 ] ) ;
break;
case 3 : F_7 ( 0x48 ) ; ( void ) F_4 () ;
for ( V_19 = 0 ; V_19 < V_15 / 2 ; V_19 ++ ) F_18 ( F_19 ( V_14 , V_19 ) ) ;
break;
case 4 : F_7 ( 0x48 ) ; ( void ) F_4 () ;
for ( V_19 = 0 ; V_19 < V_15 / 4 ; V_19 ++ ) F_20 ( F_21 ( V_14 , V_19 ) ) ;
break;
}
}
static void F_22 ( T_1 * V_1 , char * V_20 , int V_21 )
{ char * V_22 [ 5 ] = { L_1 , L_2 , L_3 , L_4 , L_5 } ;
F_23 ( L_6 ,
V_1 -> V_23 , V_24 , V_1 -> V_25 ) ;
F_23 ( L_7 , V_1 -> V_8 ,
V_22 [ V_1 -> V_8 ] , V_1 -> V_26 ) ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_27 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_27 ) ;
}
