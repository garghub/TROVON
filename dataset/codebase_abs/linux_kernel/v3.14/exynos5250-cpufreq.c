static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 ) ;
while ( F_3 ( V_6 ) & 0x11111111 )
F_4 () ;
V_2 = V_3 [ V_1 ] . V_7 ;
F_2 ( V_2 , V_8 ) ;
while ( F_3 ( V_9 ) & 0x11 )
F_4 () ;
}
static void F_5 ( unsigned int V_10 )
{
unsigned int V_2 ;
unsigned int V_11 = V_3 [ V_10 ] . V_11 ;
F_6 ( V_12 , V_13 ) ;
do {
F_4 () ;
V_2 = ( F_3 ( V_14 ) >> 16 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_7 ( V_15 , V_11 * 1000 ) ;
F_6 ( V_12 , V_15 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_14 ) ;
V_2 &= ( 0x7 << 16 ) ;
} while ( V_2 != ( 0x1 << 16 ) );
}
static void F_8 ( unsigned int V_16 ,
unsigned int V_17 )
{
if ( V_16 > V_17 ) {
F_1 ( V_17 ) ;
F_5 ( V_17 ) ;
} else if ( V_16 < V_17 ) {
F_5 ( V_17 ) ;
F_1 ( V_17 ) ;
}
}
int F_9 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
V_21 = F_10 ( NULL , L_1 ) ;
if ( F_11 ( V_21 ) )
return F_12 ( V_21 ) ;
V_12 = F_10 ( NULL , L_2 ) ;
if ( F_11 ( V_12 ) )
goto V_22;
V_13 = F_10 ( NULL , L_3 ) ;
if ( F_11 ( V_13 ) )
goto V_23;
V_20 = F_13 ( V_13 ) / 1000 ;
V_15 = F_10 ( NULL , L_4 ) ;
if ( F_11 ( V_15 ) )
goto V_24;
V_19 -> V_25 = V_20 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_28 = V_29 ;
V_19 -> V_30 = V_31 ;
V_19 -> V_32 = F_8 ;
return 0 ;
V_24:
F_14 ( V_13 ) ;
V_23:
F_14 ( V_12 ) ;
V_22:
F_14 ( V_21 ) ;
F_15 ( L_5 , V_33 ) ;
return - V_34 ;
}
