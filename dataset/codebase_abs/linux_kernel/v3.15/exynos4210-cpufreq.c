static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 ) ;
do {
V_2 = F_3 ( V_6 ) ;
} while ( V_2 & 0x1111111 );
V_2 = V_3 [ V_1 ] . V_7 ;
F_2 ( V_2 , V_8 ) ;
do {
V_2 = F_3 ( V_9 ) ;
} while ( V_2 & 0x11 );
}
static void F_4 ( unsigned int V_10 )
{
unsigned int V_2 , V_11 = V_3 [ V_10 ] . V_11 ;
F_5 ( V_12 , V_13 ) ;
do {
V_2 = ( F_3 ( V_14 )
>> V_15 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_6 ( V_16 , V_11 * 1000 ) ;
F_5 ( V_12 , V_16 ) ;
do {
V_2 = F_3 ( V_14 ) ;
V_2 &= V_17 ;
} while ( V_2 != ( 0x1 << V_15 ) );
}
static void F_7 ( unsigned int V_18 ,
unsigned int V_19 )
{
if ( V_18 > V_19 ) {
F_1 ( V_19 ) ;
F_4 ( V_19 ) ;
} else if ( V_18 < V_19 ) {
F_4 ( V_19 ) ;
F_1 ( V_19 ) ;
}
}
int F_8 ( struct V_20 * V_21 )
{
unsigned long V_22 ;
V_23 = F_9 ( NULL , L_1 ) ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
V_12 = F_9 ( NULL , L_2 ) ;
if ( F_10 ( V_12 ) )
goto V_24;
V_13 = F_9 ( NULL , L_3 ) ;
if ( F_10 ( V_13 ) )
goto V_25;
V_22 = F_12 ( V_13 ) / 1000 ;
V_16 = F_9 ( NULL , L_4 ) ;
if ( F_10 ( V_16 ) )
goto V_26;
V_21 -> V_27 = V_22 ;
V_21 -> V_28 = V_29 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_30 = V_31 ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = F_7 ;
return 0 ;
V_26:
F_13 ( V_13 ) ;
V_25:
F_13 ( V_12 ) ;
V_24:
F_13 ( V_23 ) ;
F_14 ( L_5 , V_35 ) ;
return - V_36 ;
}
