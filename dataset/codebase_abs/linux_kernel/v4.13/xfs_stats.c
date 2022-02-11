static int F_1 ( struct V_1 T_1 * V_2 , int V_3 )
{
int V_4 = 0 , V_5 ;
F_2 (cpu)
V_4 += * ( ( ( V_6 * ) F_3 ( V_2 , V_5 ) + V_3 ) ) ;
return V_4 ;
}
int F_4 ( struct V_1 T_1 * V_2 , char * V_7 )
{
int V_8 , V_9 ;
int V_10 = 0 ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
T_2 V_13 = 0 ;
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
{ L_21 , V_38 } ,
{ L_22 , V_39 } ,
{ L_23 , V_40 } ,
} ;
for ( V_8 = V_9 = 0 ; V_8 < F_5 ( V_17 ) ; V_8 ++ ) {
V_10 += snprintf ( V_7 + V_10 , V_41 - V_10 , L_24 ,
V_17 [ V_8 ] . V_15 ) ;
for (; V_9 < V_17 [ V_8 ] . V_16 ; V_9 ++ )
V_10 += snprintf ( V_7 + V_10 , V_41 - V_10 , L_25 ,
F_1 ( V_2 , V_9 ) ) ;
V_10 += snprintf ( V_7 + V_10 , V_41 - V_10 , L_26 ) ;
}
F_2 (i) {
V_11 += F_3 ( V_2 , V_8 ) -> V_42 . V_11 ;
V_12 += F_3 ( V_2 , V_8 ) -> V_42 . V_12 ;
V_13 += F_3 ( V_2 , V_8 ) -> V_42 . V_13 ;
}
V_10 += snprintf ( V_7 + V_10 , V_41 - V_10 , L_27 ,
V_11 , V_12 , V_13 ) ;
V_10 += snprintf ( V_7 + V_10 , V_41 - V_10 , L_28 ,
#if F_6 ( V_43 )
1 ) ;
#else
0 ) ;
static int F_7 ( struct V_44 * V_45 , void * V_46 )
{
F_8 ( V_45 , L_29 ,
0 , F_1 ( V_1 . V_47 , V_48 ) ,
0 , F_1 ( V_1 . V_47 , V_48 + 1 ) ) ;
return 0 ;
}
static int F_9 ( struct V_49 * V_49 , struct V_50 * V_50 )
{
return F_10 ( V_50 , F_7 , NULL ) ;
}
static int F_11 ( struct V_44 * V_45 , void * V_46 )
{
int V_9 ;
F_8 ( V_45 , L_23 ) ;
for ( V_9 = V_36 ; V_9 < V_48 ; V_9 ++ )
F_8 ( V_45 , L_25 , F_1 ( V_1 . V_47 , V_9 ) ) ;
F_12 ( V_45 , '\n' ) ;
return 0 ;
}
static int F_13 ( struct V_49 * V_49 , struct V_50 * V_50 )
{
return F_10 ( V_50 , F_11 , NULL ) ;
}
int
F_14 ( void )
{
if ( ! F_15 ( L_30 , NULL ) )
return - V_51 ;
if ( ! F_16 ( L_31 , NULL ,
L_32 ) )
goto V_52;
#ifdef F_17
if ( ! F_18 ( L_33 , 0 , NULL ,
& V_53 ) )
goto V_52;
if ( ! F_18 ( L_34 , 0 , NULL ,
& V_54 ) )
goto V_52;
#endif
return 0 ;
V_52:
F_19 ( L_30 , NULL ) ;
return - V_51 ;
}
void
F_20 ( void )
{
F_19 ( L_30 , NULL ) ;
}
