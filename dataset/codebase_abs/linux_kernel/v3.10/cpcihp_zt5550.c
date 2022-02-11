static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if( V_4 ) {
F_2 ( L_1 ) ;
return - V_5 ;
}
V_3 = F_3 ( V_2 ) ;
if( V_3 ) {
F_2 ( L_2 , F_4 ( V_2 ) ) ;
return V_3 ;
}
V_4 = V_2 ;
F_5 ( L_3 , V_4 ) ;
F_5 ( L_4 , ( unsigned long long ) F_6 ( V_4 , 1 ) ) ;
F_5 ( L_5 , ( unsigned long long ) F_7 ( V_4 , 1 ) ) ;
if( ! F_8 ( F_6 ( V_4 , 1 ) ,
F_7 ( V_4 , 1 ) , V_6 ) ) {
F_2 ( L_6 ) ;
V_3 = - V_7 ;
goto V_8;
}
V_9 =
F_9 ( F_6 ( V_4 , 1 ) , F_7 ( V_4 , 1 ) ) ;
if( ! V_9 ) {
F_2 ( L_7 ,
( unsigned long long ) F_7 ( V_4 , 1 ) ,
( unsigned long long ) F_6 ( V_4 , 1 ) ) ;
V_3 = - V_10 ;
goto V_11;
}
V_12 = V_9 + V_13 ;
V_14 = V_9 + V_15 ;
V_16 = V_9 + V_17 ;
V_18 = V_9 + V_19 ;
F_5 ( L_8 ) ;
F_10 ( ( V_20 ) V_21 , V_12 ) ;
F_10 ( ( V_20 ) V_22 , V_14 ) ;
F_5 ( L_9 ) ;
F_5 ( L_10 ) ;
F_10 ( ( V_20 ) V_23 , V_18 ) ;
F_5 ( L_11 ) ;
return 0 ;
V_11:
F_11 ( F_6 ( V_4 , 1 ) ,
F_7 ( V_4 , 1 ) ) ;
V_8:
F_12 ( V_4 ) ;
return V_3 ;
}
static int F_13 ( void )
{
if( ! V_4 )
return - V_10 ;
F_14 ( V_9 ) ;
F_11 ( F_6 ( V_4 , 1 ) ,
F_7 ( V_4 , 1 ) ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_15 ( void )
{
V_20 V_24 ;
V_24 = F_16 ( V_25 ) ;
return ( ( V_24 & V_26 ) == V_26 ) ;
}
static int F_17 ( void * V_27 )
{
int V_3 ;
V_20 V_28 ;
V_3 = 0 ;
if( V_27 == V_29 . V_27 ) {
V_28 = F_18 ( V_16 ) ;
if( V_28 )
V_3 = 1 ;
}
return V_3 ;
}
static int F_19 ( void )
{
V_20 V_28 ;
if( V_4 == NULL ) {
return - V_10 ;
}
V_28 = F_18 ( V_18 ) ;
V_28 = V_28 & ~ V_30 ;
F_10 ( V_28 , V_18 ) ;
return 0 ;
}
static int F_20 ( void )
{
V_20 V_28 ;
if( V_4 == NULL ) {
return - V_10 ;
}
V_28 = F_18 ( V_18 ) ;
V_28 = V_28 | V_30 ;
F_10 ( V_28 , V_18 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_31 * V_32 )
{
int V_33 ;
V_33 = F_1 ( V_2 ) ;
if( V_33 != 0 ) {
return V_33 ;
}
F_5 ( L_12 ) ;
memset ( & V_29 , 0 , sizeof ( struct V_34 ) ) ;
V_35 . V_36 = F_15 ;
V_29 . V_37 = & V_35 ;
if( ! V_38 ) {
V_29 . V_39 = V_4 -> V_39 ;
V_29 . V_40 = V_41 ;
V_29 . V_27 = V_4 ;
V_35 . V_42 = F_19 ;
V_35 . V_43 = F_20 ;
V_35 . V_44 = F_17 ;
} else {
F_22 ( L_13 ) ;
}
V_33 = F_23 ( & V_29 ) ;
if( V_33 != 0 ) {
F_2 ( L_14 ) ;
goto V_45;
}
F_5 ( L_15 ) ;
if( ! ( V_46 = F_24 ( V_47 ,
V_48 , NULL ) ) ) {
V_33 = - V_10 ;
goto V_49;
}
V_50 = V_46 -> V_51 ;
F_25 ( V_46 ) ;
V_33 = F_26 ( V_50 , 0x0a , 0x0f ) ;
if( V_33 != 0 ) {
F_2 ( L_16 ) ;
goto V_49;
}
F_5 ( L_17 ) ;
V_33 = F_27 () ;
if( V_33 != 0 ) {
F_2 ( L_18 ) ;
F_28 ( V_50 ) ;
goto V_49;
}
F_5 ( L_19 ) ;
return 0 ;
V_49:
F_29 ( & V_29 ) ;
V_45:
F_2 ( L_20 , V_33 ) ;
F_13 () ;
return V_33 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 () ;
F_28 ( V_50 ) ;
F_29 ( & V_29 ) ;
F_13 () ;
}
static int T_1 F_32 ( void )
{
struct V_52 * V_53 ;
int V_54 ;
F_22 ( V_55 L_21 V_56 ) ;
V_53 = F_33 ( V_25 , 1 , L_22 ) ;
if( ! V_53 )
return - V_5 ;
V_54 = F_34 ( & V_57 ) ;
if( V_54 < 0 )
F_35 ( V_25 , 1 ) ;
return V_54 ;
}
static void T_2
F_36 ( void )
{
F_37 ( & V_57 ) ;
F_35 ( V_25 , 1 ) ;
}
