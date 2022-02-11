static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | 20 | V_4 | V_5 ) ;
F_3 ( V_3 + 20 , 1 ) ;
F_4 ( 2 ) ;
F_3 ( V_3 + 20 , 0 ) ;
F_2 ( V_6 ) ;
F_5 ( 2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_3 | 20 | V_4 | V_5 ) ;
F_3 ( V_3 + 20 , 0 ) ;
F_2 ( V_3 | 22 | V_4 | V_5 ) ;
F_3 ( V_3 + 22 , 0 ) ;
F_2 ( V_3 | 28 | V_4 | V_5 ) ;
F_3 ( V_3 + 28 , 0 ) ;
F_4 ( 10 ) ;
F_3 ( V_3 + 28 , 1 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_5 ( 2 ) ;
}
static int F_7 ( struct V_8 * V_9 , T_1 V_10 ,
void * V_11 )
{
int V_12 ;
V_12 = F_8 ( F_9 ( F_10 ( 3 , 29 ) ) , V_10 ,
V_13 | V_14 ,
L_1 , V_11 ) ;
if ( V_12 )
F_11 ( V_15
L_2 ) ;
return V_12 ;
}
static void F_12 ( struct V_8 * V_9 , void * V_11 )
{
F_13 ( F_9 ( F_10 ( 3 , 29 ) ) , V_11 ) ;
}
static int F_14 ( struct V_16 * V_17 )
{
F_3 ( V_18 , 0 ) ;
F_15 ( 10 ) ;
return F_16 ( V_17 -> V_19 , V_20 ) ;
}
static int F_17 ( struct V_16 * V_17 )
{
F_3 ( V_21 , 0 ) ;
F_15 ( 10 ) ;
return F_16 ( V_17 -> V_19 , V_20 ) ;
}
static int T_2 F_18 ( char * V_22 )
{
if ( ! strcmp ( V_22 , L_3 ) )
V_23 = true ;
else if ( ! strcmp ( V_22 , L_4 ) )
V_23 = false ;
else
F_19 ( L_5
L_6 ) ;
return 1 ;
}
static void T_2 F_20 ( void )
{
int V_12 ;
F_21 () ;
V_12 = F_22 ( V_24 ,
F_23 ( V_24 ) , L_7 ) ;
if ( V_12 )
F_11 ( V_15 L_8 , V_12 ) ;
F_24 ( 0 , & V_25 ) ;
F_25 ( & V_26 ) ;
F_26 ( 1 , & V_27 ) ;
F_27 ( & V_28 ) ;
F_28 ( 1 , V_29 ,
F_23 ( V_29 ) ) ;
F_29 ( 1 , & V_30 ) ;
F_2 ( V_31 | 28 | V_4 | V_32 ) ;
F_2 ( V_31 | 27 | V_4 | V_32 ) ;
F_30 ( V_33 ,
F_23 ( V_33 ) ) ;
F_31 ( & V_34 ) ;
F_32 ( V_18 , L_9 ) ;
F_33 ( V_18 , 1 ) ;
F_32 ( V_21 , L_10 ) ;
F_33 ( V_21 , 1 ) ;
if ( V_23 ) {
V_35 . V_36 = F_34 ( V_37 |
V_38 ) ;
if ( V_35 . V_36 )
F_35 ( & V_35 ) ;
} else {
F_3 ( V_18 , 0 ) ;
F_36 ( & V_39 ) ;
}
V_40 . V_36 = F_34 (
V_37 | V_38 ) ;
if ( V_40 . V_36 )
F_37 ( 2 , & V_40 ) ;
F_38 ( & V_41 ) ;
F_39 ( NULL ) ;
F_40 () ;
F_41 () ;
}
static void T_2 F_42 ( void )
{
F_43 ( 26000000 ) ;
}
