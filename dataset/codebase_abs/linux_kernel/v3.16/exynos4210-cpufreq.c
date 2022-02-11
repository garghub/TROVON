static void F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 [ V_1 ] . V_4 ;
F_2 ( V_2 , V_5 -> V_6 + V_7 ) ;
do {
V_2 = F_3 ( V_5 -> V_6 + V_8 ) ;
} while ( V_2 & 0x1111111 );
V_2 = V_3 [ V_1 ] . V_9 ;
F_2 ( V_2 , V_5 -> V_6 + V_10 ) ;
do {
V_2 = F_3 ( V_5 -> V_6 + V_11 ) ;
} while ( V_2 & 0x11 );
}
static void F_4 ( unsigned int V_12 )
{
unsigned int V_2 , V_13 = V_3 [ V_12 ] . V_13 ;
F_5 ( V_14 , V_15 ) ;
do {
V_2 = ( F_3 ( V_5 -> V_6 + V_16 )
>> V_17 ) ;
V_2 &= 0x7 ;
} while ( V_2 != 0x2 );
F_6 ( V_18 , V_13 * 1000 ) ;
F_5 ( V_14 , V_18 ) ;
do {
V_2 = F_3 ( V_5 -> V_6 + V_16 ) ;
V_2 &= V_19 ;
} while ( V_2 != ( 0x1 << V_17 ) );
}
static void F_7 ( unsigned int V_20 ,
unsigned int V_21 )
{
if ( V_20 > V_21 ) {
F_1 ( V_21 ) ;
F_4 ( V_21 ) ;
} else if ( V_20 < V_21 ) {
F_4 ( V_21 ) ;
F_1 ( V_21 ) ;
}
}
int F_8 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
unsigned long V_26 ;
V_25 = F_9 ( NULL , NULL , L_1 ) ;
if ( ! V_25 ) {
F_10 ( L_2 ,
V_27 ) ;
return - V_28 ;
}
V_23 -> V_6 = F_11 ( V_25 , 0 ) ;
if ( ! V_23 -> V_6 ) {
F_10 ( L_3 , V_27 ) ;
return - V_29 ;
}
V_30 = F_12 ( NULL , L_4 ) ;
if ( F_13 ( V_30 ) )
return F_14 ( V_30 ) ;
V_14 = F_12 ( NULL , L_5 ) ;
if ( F_13 ( V_14 ) )
goto V_31;
V_15 = F_12 ( NULL , L_6 ) ;
if ( F_13 ( V_15 ) )
goto V_32;
V_26 = F_15 ( V_15 ) / 1000 ;
V_18 = F_12 ( NULL , L_7 ) ;
if ( F_13 ( V_18 ) )
goto V_33;
V_23 -> V_34 = V_26 ;
V_23 -> V_35 = V_36 ;
V_23 -> V_30 = V_30 ;
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = F_7 ;
V_5 = V_23 ;
return 0 ;
V_33:
F_16 ( V_15 ) ;
V_32:
F_16 ( V_14 ) ;
V_31:
F_16 ( V_30 ) ;
F_17 ( L_8 , V_27 ) ;
return - V_42 ;
}
