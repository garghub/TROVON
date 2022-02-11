static void F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{ int V_5 ;
V_5 = V_3 + V_6 [ V_2 ] + 0x80 ;
F_2 ( V_5 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ; F_2 ( V_4 ) ; F_3 ( 7 ) ; F_3 ( 6 ) ; F_3 ( 0xc ) ;
}
static int F_4 ( T_1 * V_1 , int V_2 , int V_3 )
{ int V_7 , V_8 , V_5 ;
V_5 = V_3 + V_6 [ V_2 ] + 0x40 ;
switch ( V_1 -> V_9 ) {
case 0 : F_2 ( V_5 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ;
F_3 ( 7 ) ; F_3 ( 6 ) ; F_3 ( 0 ) ;
V_7 = F_5 () ; F_2 ( 0x10 ) ; V_8 = F_5 () ; F_3 ( 0xc ) ;
return F_6 ( V_7 , V_8 ) ;
case 1 : V_5 |= 0x10 ;
F_2 ( V_5 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ; F_2 ( 0xff ) ;
F_3 ( 0x27 ) ; F_3 ( 0x26 ) ; F_3 ( 0x20 ) ;
V_7 = F_7 () ;
F_3 ( 0x26 ) ; F_3 ( 0xc ) ;
return V_7 ;
}
return - 1 ;
}
static void F_8 ( T_1 * V_1 , char * V_10 , int V_11 )
{ int V_12 , V_7 , V_8 , V_13 , V_14 ;
switch ( V_1 -> V_9 ) {
case 0 : F_2 ( 0x48 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ;
for ( V_12 = 0 ; V_12 < V_11 / 2 ; V_12 ++ ) {
F_3 ( 7 ) ; F_3 ( 6 ) ; F_3 ( 2 ) ;
V_7 = F_5 () ; F_2 ( 0x58 ) ; V_8 = F_5 () ;
F_3 ( 0 ) ; V_14 = F_5 () ; F_2 ( 0x48 ) ; V_13 = F_5 () ;
V_10 [ 2 * V_12 ] = F_6 ( V_13 , V_14 ) ;
V_10 [ 2 * V_12 + 1 ] = F_6 ( V_7 , V_8 ) ;
}
F_3 ( 0xc ) ;
break;
case 1 : F_2 ( 0x58 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ;
for ( V_12 = 0 ; V_12 < V_11 / 2 ; V_12 ++ ) {
F_3 ( 0x27 ) ; F_3 ( 0x26 ) ; F_3 ( 0x22 ) ;
V_7 = F_7 () ; F_3 ( 0x20 ) ; V_8 = F_7 () ;
V_10 [ 2 * V_12 ] = V_8 ; V_10 [ 2 * V_12 + 1 ] = V_7 ;
}
F_3 ( 0x26 ) ; F_3 ( 0xc ) ;
break;
}
}
static void F_9 ( T_1 * V_1 , char * V_10 , int V_11 )
{ int V_12 ;
F_2 ( 0x88 ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ;
for ( V_12 = 0 ; V_12 < V_11 / 2 ; V_12 ++ ) {
F_2 ( V_10 [ 2 * V_12 + 1 ] ) ; F_3 ( 0xe ) ; F_3 ( 6 ) ;
F_2 ( V_10 [ 2 * V_12 ] ) ; F_3 ( 7 ) ; F_3 ( 6 ) ;
}
F_3 ( 0xc ) ;
}
static void F_10 ( T_1 * V_1 )
{ V_1 -> V_15 = F_7 () ;
V_1 -> V_16 = F_11 () ;
F_3 ( 0xc ) ;
}
static void F_12 ( T_1 * V_1 )
{ F_2 ( V_1 -> V_15 ) ;
F_3 ( V_1 -> V_16 ) ;
}
static void F_13 ( T_1 * V_1 , char * V_17 , int V_18 )
{ char * V_19 [ 2 ] = { L_1 , L_2 } ;
F_14 ( L_3 ,
V_1 -> V_20 , V_21 , V_1 -> V_22 ) ;
F_14 ( L_4 , V_1 -> V_9 ,
V_19 [ V_1 -> V_9 ] , V_1 -> V_23 ) ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_24 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_24 ) ;
}
