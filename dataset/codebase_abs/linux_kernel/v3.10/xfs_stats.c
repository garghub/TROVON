static int F_1 ( int V_1 )
{
int V_2 = 0 , V_3 ;
F_2 (cpu)
V_2 += * ( ( ( V_4 * ) & F_3 ( V_5 , V_3 ) + V_1 ) ) ;
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 , void * V_8 )
{
int V_9 , V_10 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
static const struct V_14 {
char * V_15 ;
int V_16 ;
} V_17 [] = {
{ L_1 , V_18 } ,
{ L_2 , V_19 } ,
{ L_3 , V_20 } ,
{ L_4 , V_21 } ,
{ L_5 , V_22 } ,
{ L_6 , V_23 } ,
{ L_7 , V_24 } ,
{ L_8 , V_25 } ,
{ L_9 , V_26 } ,
{ L_10 , V_27 } ,
{ L_11 , V_28 } ,
{ L_12 , V_29 } ,
{ L_13 , V_30 } ,
{ L_14 , V_31 } ,
{ L_15 , V_32 } ,
{ L_16 , V_33 } ,
{ L_17 , V_34 } ,
{ L_18 , V_35 } ,
{ L_19 , V_36 } ,
{ L_20 , V_37 } ,
} ;
for ( V_9 = V_10 = 0 ; V_9 < F_5 ( V_17 ) ; V_9 ++ ) {
F_6 ( V_7 , L_21 , V_17 [ V_9 ] . V_15 ) ;
for (; V_10 < V_17 [ V_9 ] . V_16 ; V_10 ++ )
F_6 ( V_7 , L_22 , F_1 ( V_10 ) ) ;
F_7 ( V_7 , '\n' ) ;
}
F_2 (i) {
V_11 += F_3 ( V_5 , V_9 ) . V_11 ;
V_12 += F_3 ( V_5 , V_9 ) . V_12 ;
V_13 += F_3 ( V_5 , V_9 ) . V_13 ;
}
F_6 ( V_7 , L_23 ,
V_11 , V_12 , V_13 ) ;
F_6 ( V_7 , L_24 ,
#if F_8 ( V_38 )
1 ) ;
#else
0 ) ;
int F_9 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_10 ( V_40 , F_4 , NULL ) ;
}
static int F_11 ( struct V_6 * V_7 , void * V_8 )
{
F_6 ( V_7 , L_25 ,
0 ,
F_1 ( V_41 ) ,
0 ,
F_1 ( V_41 + 1 ) ) ;
return 0 ;
}
static int F_12 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_10 ( V_40 , F_11 , NULL ) ;
}
static int F_13 ( struct V_6 * V_7 , void * V_8 )
{
int V_10 ;
F_6 ( V_7 , L_20 ) ;
for ( V_10 = V_36 ; V_10 < V_41 ; V_10 ++ )
F_6 ( V_7 , L_22 , F_1 ( V_10 ) ) ;
F_7 ( V_7 , '\n' ) ;
return 0 ;
}
static int F_14 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_10 ( V_40 , F_13 , NULL ) ;
}
int
F_15 ( void )
{
if ( ! F_16 ( L_26 , NULL ) )
goto V_42;
if ( ! F_17 ( L_27 , 0 , NULL ,
& V_43 ) )
goto V_44;
#ifdef F_18
if ( ! F_17 ( L_28 , 0 , NULL ,
& V_45 ) )
goto V_46;
if ( ! F_17 ( L_29 , 0 , NULL ,
& V_47 ) )
goto V_48;
#endif
return 0 ;
#ifdef F_18
V_48:
F_19 ( L_28 , NULL ) ;
V_46:
F_19 ( L_27 , NULL ) ;
#endif
V_44:
F_19 ( L_26 , NULL ) ;
V_42:
return - V_49 ;
}
void
F_20 ( void )
{
#ifdef F_18
F_19 ( L_29 , NULL ) ;
F_19 ( L_28 , NULL ) ;
#endif
F_19 ( L_27 , NULL ) ;
F_19 ( L_26 , NULL ) ;
}
