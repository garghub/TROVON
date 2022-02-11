static T_1
F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 , unsigned int V_5 ,
unsigned int V_6 , const unsigned char * V_7 )
{
#ifdef F_2
T_2 V_8 = 0 ;
if ( V_7 )
V_8 = * ( T_2 * ) V_7 ;
if ( V_6 < 8 )
V_8 &= ( 1ull << ( V_6 * 8 ) ) - 1 ;
F_3 ( L_1 , V_2 , V_3 ,
V_4 , V_6 , V_8 ) ;
#endif
return V_6 ;
}
static int F_4 ( struct V_1 * V_9 , unsigned int V_2 ,
unsigned int V_3 )
{
if ( V_10 && ( V_3 & V_10 ) )
return - V_11 ;
return 0 ;
}
static int F_5 ( void )
{
int V_12 , V_13 = - V_14 ;
if ( V_15 < 0 || V_15 > V_16 )
return - V_11 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
V_17 [ V_12 ] . V_18 = F_6 ( V_19 , L_2 , V_12 ) ;
if ( ! V_17 [ V_12 ] . V_18 )
goto V_20;
V_17 [ V_12 ] . V_21 = 0x0000 ;
V_17 [ V_12 ] . V_22 = 0xffff ;
V_17 [ V_12 ] . V_23 = 0xffff ;
V_17 [ V_12 ] . V_4 = F_1 ;
V_17 [ V_12 ] . V_24 = F_4 ;
V_13 = F_7 ( NULL , & V_17 [ V_12 ] , V_25 ) ;
if ( V_13 )
goto V_26;
}
return 0 ;
V_20:
for ( V_12 -- ; V_12 >= 0 ; V_12 -- ) {
F_8 ( & V_17 [ V_12 ] ) ;
V_26:
F_9 ( V_17 [ V_12 ] . V_18 ) ;
}
return V_13 ;
}
static void F_10 ( void )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
F_8 ( & V_17 [ V_12 ] ) ;
F_9 ( V_17 [ V_12 ] . V_18 ) ;
}
}
