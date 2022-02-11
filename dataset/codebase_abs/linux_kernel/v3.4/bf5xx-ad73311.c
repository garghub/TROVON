static int F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_3 ( V_2 , 1 ) ;
return 0 ;
}
static int F_4 ( void )
{
unsigned short V_3 [ 6 ] ;
unsigned short V_4 = 0 ;
int V_5 = 0 ;
V_3 [ 0 ] = V_6 | V_7 | V_8 | F_5 ( 0 ) | \
F_6 ( 0 ) | F_7 ( 0 ) ;
V_3 [ 1 ] = V_6 | V_7 | V_9 | V_10 | \
V_11 | V_12 | V_13 | V_14 ;
V_3 [ 2 ] = V_6 | V_7 | V_15 | F_8 ( 2 ) | \
F_9 ( 2 ) ;
V_3 [ 3 ] = V_6 | V_7 | V_16 | F_10 ( 0x1f ) ;
V_3 [ 4 ] = V_6 | V_7 | V_17 | V_18 ;
V_3 [ 5 ] = V_6 | V_7 | V_19 | V_20 ;
F_11 () ;
F_1 () ;
F_12 ( 1 ) ;
F_13 ( V_21 ) ;
F_14 ( 0xF ) ;
F_15 () ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ )
F_16 ( V_3 [ V_5 ] ) ;
F_15 () ;
F_13 ( F_17 () | V_22 ) ;
F_15 () ;
while ( ! ( V_4 & V_23 ) && ++ V_5 < 10000 ) {
F_12 ( 1 ) ;
V_4 = F_18 () ;
F_15 () ;
}
F_13 ( F_17 () & ~ V_22 ) ;
F_15 () ;
F_19 () ;
if ( V_5 >= 10000 ) {
F_20 ( V_24 L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_21 ( struct V_25 * V_26 )
{
int V_27 ;
if ( F_22 ( V_2 , L_3 ) ) {
F_20 ( V_24 L_4 , V_1 , V_2 ) ;
return - V_28 ;
}
F_23 ( V_2 , 0 ) ;
V_27 = F_4 () ;
if ( V_27 < 0 )
return - V_29 ;
return 0 ;
}
static int T_1 F_24 ( void )
{
int V_30 ;
F_2 ( L_1 , V_1 ) ;
V_31 = F_25 ( L_5 , - 1 ) ;
if ( ! V_31 )
return - V_32 ;
F_26 ( V_31 , & V_33 ) ;
V_30 = F_27 ( V_31 ) ;
if ( V_30 )
F_28 ( V_31 ) ;
return V_30 ;
}
static void T_2 F_29 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_30 ( V_31 ) ;
}
