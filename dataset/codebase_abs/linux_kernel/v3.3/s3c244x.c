void T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( L_1 , V_4 , V_2 , V_3 ) ;
}
void T_1 F_3 ( void )
{
F_4 ( V_5 , F_5 ( V_5 ) ) ;
V_6 . V_7 = L_2 ;
V_8 . V_7 = L_3 ;
F_6 ( L_4 ) ;
V_9 . V_7 = L_5 ;
V_10 . V_7 = L_6 ;
}
void T_2 F_7 ( void )
{
struct V_11 * V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
unsigned long V_16 , V_17 , V_18 ;
int V_19 = 1 ;
V_12 = F_8 ( NULL , L_7 ) ;
V_15 = F_9 ( V_12 ) ;
F_10 ( V_12 ) ;
V_17 = F_11 ( F_12 ( V_20 ) , V_15 ) * 2 ;
V_13 = F_12 ( V_21 ) ;
V_14 = F_12 ( V_22 ) ;
switch ( V_13 & V_23 ) {
case V_24 :
V_19 = 1 ;
break;
case V_25 :
V_19 = 2 ;
break;
case V_26 :
V_19 = ( V_14 & V_27 ) ? 8 : 4 ;
break;
case V_28 :
V_19 = ( V_14 & V_29 ) ? 6 : 3 ;
break;
}
V_16 = V_17 / V_19 ;
V_18 = V_16 / ( ( V_13 & V_30 ) ? 2 : 1 ) ;
F_13 ( L_8 ,
F_14 ( V_17 ) , F_14 ( V_16 ) , F_14 ( V_18 ) ) ;
F_15 ( V_17 , V_16 , V_18 ) ;
}
void T_1 F_16 ( int V_15 )
{
F_17 ( V_15 ) ;
F_7 () ;
F_18 () ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_31 , NULL ) ;
}
static int T_1 F_21 ( void )
{
return F_20 ( & V_32 , NULL ) ;
}
static int F_22 ( void )
{
F_23 ( V_33 , F_5 ( V_33 ) ) ;
return 0 ;
}
static void F_24 ( void )
{
F_25 ( V_33 , F_5 ( V_33 ) ) ;
}
void F_26 ( char V_34 , const char * V_35 )
{
if ( V_34 == 's' )
F_27 ( 0 ) ;
F_28 () ;
F_27 ( 0 ) ;
}
