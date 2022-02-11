static int F_1 ( void T_1 * V_1 ,
unsigned int V_2 , T_2 V_3 , T_2 * V_4 ,
T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
int V_8 ;
V_8 = F_2 ( V_1 , V_2 , V_3 , * V_4 ) ;
if ( V_8 )
return V_8 ;
do {
V_8 = F_3 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_8 )
return V_8 ;
F_4 () ;
} while ( ( ( * V_4 >> V_5 ) & V_6 ) != V_7 );
return V_8 ;
}
static int F_5 ( struct V_9 * V_10 ,
void T_1 * * V_11 ,
unsigned int * V_12 ,
unsigned int * V_2 )
{
struct V_13 args ;
int V_8 ;
V_8 = F_6 ( V_10 , L_1 , V_12 ) ;
if ( V_8 ) {
F_7 ( L_2 ) ;
return V_8 ;
}
V_8 = F_8 ( V_10 , L_3 , L_4 ,
0 , & args ) ;
if ( V_8 ) {
F_7 ( L_5 ) ;
return V_8 ;
}
if ( args . V_14 != 2 ) {
F_7 ( L_6 ) ;
return - V_15 ;
}
* V_11 = F_9 ( args . V_16 , 0 ) ;
if ( ! * V_11 ) {
F_7 ( L_7 ) ;
return - V_17 ;
}
* V_2 = args . args [ 0 ] ;
return 0 ;
}
int F_10 ( struct V_9 * V_10 )
{
void T_1 * V_11 ;
unsigned int V_12 , V_2 ;
unsigned long V_18 ;
T_2 V_4 , V_19 ;
int V_8 ;
V_8 = F_5 ( V_10 , & V_11 , & V_12 , & V_2 ) ;
if ( V_8 )
return V_8 ;
F_11 ( V_12 > 1 ) ;
F_12 ( & V_20 , V_18 ) ;
V_8 = F_3 ( V_11 , V_2 , V_21 , & V_19 ) ;
if ( V_8 )
goto V_22;
if ( V_19 & F_13 ( V_12 ) ) {
F_14 ( L_8 , V_12 ) ;
V_8 = 0 ;
goto V_22;
}
V_8 = F_3 ( V_11 , V_2 , F_15 ( V_12 ) , & V_4 ) ;
if ( V_8 )
goto V_22;
V_4 |= ( V_23 << V_24 ) ;
V_8 = F_1 ( V_11 , V_2 , F_15 ( V_12 ) , & V_4 ,
V_25 , V_23 , V_23 ) ;
if ( V_8 )
goto V_22;
V_4 |= ( V_23 << V_26 ) ;
V_8 = F_1 ( V_11 , V_2 , F_15 ( V_12 ) , & V_4 ,
V_27 , V_23 , V_23 ) ;
if ( V_8 )
goto V_22;
V_4 &= ~ V_28 ;
V_8 = F_2 ( V_11 , V_2 , F_15 ( V_12 ) , V_4 ) ;
if ( V_8 )
goto V_22;
V_4 &= ~ ( V_29 << V_30 ) ;
V_8 = F_2 ( V_11 , V_2 , F_15 ( V_12 ) , V_4 ) ;
if ( V_8 )
goto V_22;
V_4 |= V_31 ;
V_8 = F_1 ( V_11 , V_2 , F_15 ( V_12 ) , & V_4 ,
0 , V_32 , V_32 ) ;
if ( V_8 )
goto V_22;
V_4 |= V_33 ;
V_8 = F_1 ( V_11 , V_2 , F_15 ( V_12 ) , & V_4 ,
0 , V_34 , V_34 ) ;
if ( V_8 )
goto V_22;
V_4 &= ~ V_35 ;
V_8 = F_2 ( V_11 , V_2 , F_15 ( V_12 ) , V_4 ) ;
if ( V_8 )
goto V_22;
V_19 |= F_13 ( V_12 ) ;
V_8 = F_2 ( V_11 , V_2 , V_21 , V_19 ) ;
V_22:
F_16 ( & V_20 , V_18 ) ;
F_17 ( V_11 ) ;
return V_8 ;
}
