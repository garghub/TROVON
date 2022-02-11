static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 -> V_6 + V_7 ) ;
while ( F_3 ( V_5 -> V_6 + V_8 )
& 0x11111111 )
F_4 () ;
V_2 = V_3 [ V_1 ] . V_9 ;
F_2 ( V_2 , V_5 -> V_6 + V_10 ) ;
while ( F_3 ( V_5 -> V_6 + V_11 ) & 0x11 )
F_4 () ;
}
static void F_5 ( unsigned int V_12 )
{
unsigned int V_2 ;
unsigned int V_13 = V_3 [ V_12 ] . V_13 ;
F_6 ( V_14 , V_15 ) ;
do {
F_4 () ;
V_2 = ( F_3 ( V_5 -> V_6 + V_16 )
>> 16 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_7 ( V_17 , V_13 * 1000 ) ;
F_6 ( V_14 , V_17 ) ;
do {
F_4 () ;
V_2 = F_3 ( V_5 -> V_6 + V_16 ) ;
V_2 &= ( 0x7 << 16 ) ;
} while ( V_2 != ( 0x1 << 16 ) );
}
static void F_8 ( unsigned int V_18 ,
unsigned int V_19 )
{
if ( V_18 > V_19 ) {
F_1 ( V_19 ) ;
F_5 ( V_19 ) ;
} else if ( V_18 < V_19 ) {
F_5 ( V_19 ) ;
F_1 ( V_19 ) ;
}
}
int F_9 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
unsigned long V_24 ;
V_23 = F_10 ( NULL , NULL , L_1 ) ;
if ( ! V_23 ) {
F_11 ( L_2 ,
V_25 ) ;
return - V_26 ;
}
V_21 -> V_6 = F_12 ( V_23 , 0 ) ;
if ( ! V_21 -> V_6 ) {
F_11 ( L_3 , V_25 ) ;
return - V_27 ;
}
V_28 = F_13 ( NULL , L_4 ) ;
if ( F_14 ( V_28 ) )
return F_15 ( V_28 ) ;
V_14 = F_13 ( NULL , L_5 ) ;
if ( F_14 ( V_14 ) )
goto V_29;
V_15 = F_13 ( NULL , L_6 ) ;
if ( F_14 ( V_15 ) )
goto V_30;
V_24 = F_16 ( V_15 ) / 1000 ;
V_17 = F_13 ( NULL , L_7 ) ;
if ( F_14 ( V_17 ) )
goto V_31;
V_21 -> V_32 = V_24 ;
V_21 -> V_33 = V_34 ;
V_21 -> V_28 = V_28 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_37 = V_38 ;
V_21 -> V_39 = F_8 ;
V_5 = V_21 ;
return 0 ;
V_31:
F_17 ( V_15 ) ;
V_30:
F_17 ( V_14 ) ;
V_29:
F_17 ( V_28 ) ;
F_11 ( L_8 , V_25 ) ;
return - V_40 ;
}
