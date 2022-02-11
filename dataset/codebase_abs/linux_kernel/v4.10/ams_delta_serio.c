static int F_1 ( int V_1 )
{
int V_2 , V_3 = 0 ;
if ( ! ( V_1 & 0x400 ) ) {
F_2 ( & V_4 -> V_5 ,
L_1 ,
V_1 ) ;
return V_6 ;
}
for ( V_2 = 1 ; V_2 < 10 ; V_2 ++ ) {
if ( V_1 & ( 1 << V_2 ) )
V_3 ++ ;
}
if ( ! ( V_3 & 0x01 ) ) {
F_2 ( & V_4 -> V_5 ,
L_2 ,
V_1 , V_3 ) ;
return V_7 ;
}
return 0 ;
}
static T_1 F_3 ( int V_8 , void * V_9 )
{
int * V_10 = & V_11 [ V_12 ] ;
int V_1 , V_13 ;
T_2 V_14 ;
V_11 [ V_15 ] = 0 ;
while ( V_11 [ V_16 ] > 0 ) {
V_1 = V_10 [ V_11 [ V_17 ] ++ ] ;
V_11 [ V_16 ] -- ;
if ( V_11 [ V_17 ] == V_11 [ V_18 ] )
V_11 [ V_17 ] = 0 ;
V_13 = F_1 ( V_1 ) ;
V_14 = ( T_2 ) ( V_1 >> 1 ) & 0xFF ;
F_4 ( V_4 , V_14 , V_13 ) ;
}
return V_19 ;
}
static int F_5 ( struct V_20 * V_20 )
{
F_6 ( V_21 , 1 ) ;
return 0 ;
}
static void F_7 ( struct V_20 * V_20 )
{
F_6 ( V_21 , 0 ) ;
}
static int T_3 F_8 ( void )
{
int V_22 ;
if ( ! F_9 () )
return - V_23 ;
V_4 = F_10 ( sizeof( struct V_20 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_26 . type = V_27 ;
V_4 -> V_28 = F_5 ;
V_4 -> V_29 = F_7 ;
F_11 ( V_4 -> V_30 , L_3 ,
sizeof( V_4 -> V_30 ) ) ;
F_11 ( V_4 -> V_31 , L_4 ,
sizeof( V_4 -> V_31 ) ) ;
V_22 = F_12 ( V_32 ,
F_13 ( V_32 ) ) ;
if ( V_22 ) {
F_14 ( L_5 ) ;
goto V_20;
}
V_22 = F_15 ( F_16 ( V_33 ) ,
F_3 , V_34 ,
L_6 , 0 ) ;
if ( V_22 < 0 ) {
F_14 ( L_7 ,
F_16 ( V_33 ) ) ;
goto V_35;
}
F_17 ( F_16 ( V_33 ) ,
V_36 ) ;
F_18 ( V_4 ) ;
F_19 ( & V_4 -> V_5 , L_8 , V_4 -> V_30 ) ;
return 0 ;
V_35:
F_20 ( V_32 ,
F_13 ( V_32 ) ) ;
V_20:
F_21 ( V_4 ) ;
return V_22 ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_4 ) ;
F_24 ( F_16 ( V_33 ) , 0 ) ;
F_20 ( V_32 ,
F_13 ( V_32 ) ) ;
}
