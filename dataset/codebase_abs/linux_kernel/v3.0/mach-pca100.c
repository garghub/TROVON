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
V_12 = F_8 ( F_9 ( 29 ) , V_10 ,
V_13 | V_14 ,
L_1 , V_11 ) ;
if ( V_12 )
F_10 ( V_15
L_2 ) ;
return V_12 ;
}
static void F_11 ( struct V_8 * V_9 , void * V_11 )
{
F_12 ( F_9 ( 29 ) , V_11 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
F_3 ( V_18 , 0 ) ;
F_14 ( 10 ) ;
return F_15 ( V_17 -> V_19 , V_20 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
F_3 ( V_21 , 0 ) ;
F_14 ( 10 ) ;
return F_15 ( V_17 -> V_19 , V_20 ) ;
}
static int T_2 F_17 ( char * V_22 )
{
if ( ! strcmp ( V_22 , L_3 ) )
V_23 = 1 ;
else if ( ! strcmp ( V_22 , L_4 ) )
V_23 = 0 ;
else
F_18 ( L_5
L_6 ) ;
return 0 ;
}
static void T_2 F_19 ( void )
{
int V_12 ;
F_20 ( V_24 ,
V_25 |
F_21 ( 3 ) |
V_26 |
F_22 ( 3 ) ) ;
F_20 ( 3 ,
V_25 |
F_21 ( 0 ) |
V_27 |
F_22 ( 0 ) ) ;
V_12 = F_23 ( V_28 ,
F_24 ( V_28 ) , L_7 ) ;
if ( V_12 )
F_10 ( V_15 L_8 , V_12 ) ;
F_25 ( 0 , & V_29 ) ;
F_26 ( & V_30 ) ;
F_27 ( 1 , & V_31 ) ;
F_28 ( & V_32 ) ;
F_29 ( 1 , V_33 ,
F_24 ( V_33 ) ) ;
F_30 ( 1 , & V_34 ) ;
F_2 ( V_35 | 28 | V_4 | V_36 ) ;
F_2 ( V_35 | 27 | V_4 | V_36 ) ;
F_31 ( V_37 ,
F_24 ( V_37 ) ) ;
F_32 ( & V_38 ) ;
F_33 ( V_18 , L_9 ) ;
F_34 ( V_18 , 1 ) ;
F_33 ( V_21 , L_10 ) ;
F_34 ( V_21 , 1 ) ;
if ( V_23 ) {
V_39 . V_40 = F_35 ( V_41 |
V_42 ) ;
if ( V_39 . V_40 )
F_36 ( & V_39 ) ;
} else {
F_3 ( V_18 , 0 ) ;
F_37 ( & V_43 ) ;
}
V_44 . V_40 = F_38 ( & V_45 ,
V_41 | V_42 ) ;
if ( V_44 . V_40 )
F_39 ( 2 , & V_44 ) ;
F_40 ( & V_46 ) ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
F_43 ( NULL ) ;
}
static void T_2 F_44 ( void )
{
F_45 ( 26000000 ) ;
}
