static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
unsigned int V_3 ;
V_2 = V_4 [ V_1 ] . V_5 ;
F_2 ( V_2 , V_6 ) ;
while ( F_3 ( V_7 ) & 0x11111111 )
F_4 () ;
V_2 = V_4 [ V_1 ] . V_8 ;
F_2 ( V_2 , V_9 ) ;
if ( F_5 () )
V_3 = 0x11 ;
else
V_3 = 0x111 ;
while ( F_3 ( V_10 ) & V_3 )
F_4 () ;
}
static void F_6 ( unsigned int V_11 )
{
unsigned int V_2 , V_12 = V_4 [ V_11 ] . V_12 ;
F_7 ( V_13 , V_14 ) ;
do {
F_4 () ;
V_2 = ( F_3 ( V_15 )
>> V_16 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_8 ( V_17 , V_12 * 1000 ) ;
F_7 ( V_13 , V_17 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_15 ) ;
V_2 &= V_18 ;
} while ( V_2 != ( 0x1 << V_16 ) );
}
static void F_9 ( unsigned int V_19 ,
unsigned int V_20 )
{
if ( V_19 > V_20 ) {
F_1 ( V_20 ) ;
F_6 ( V_20 ) ;
} else if ( V_19 < V_20 ) {
F_6 ( V_20 ) ;
F_1 ( V_20 ) ;
}
}
int F_10 ( struct V_21 * V_22 )
{
unsigned long V_23 ;
V_24 = F_11 ( NULL , L_1 ) ;
if ( F_12 ( V_24 ) )
return F_13 ( V_24 ) ;
V_13 = F_11 ( NULL , L_2 ) ;
if ( F_12 ( V_13 ) )
goto V_25;
V_14 = F_11 ( NULL , L_3 ) ;
if ( F_12 ( V_14 ) )
goto V_26;
V_23 = F_14 ( V_14 ) / 1000 ;
V_17 = F_11 ( NULL , L_4 ) ;
if ( F_12 ( V_17 ) )
goto V_27;
if ( F_5 () )
V_4 = V_28 ;
else
V_4 = V_29 ;
V_22 -> V_30 = V_23 ;
V_22 -> V_31 = V_32 ;
V_22 -> V_24 = V_24 ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = V_36 ;
V_22 -> V_37 = F_9 ;
return 0 ;
V_27:
F_15 ( V_14 ) ;
V_26:
F_15 ( V_13 ) ;
V_25:
F_15 ( V_24 ) ;
F_16 ( L_5 , V_38 ) ;
return - V_39 ;
}
