static void F_1 ( int V_1 , struct V_2 * V_3 )
{
F_2 ( L_1 ) ;
if ( V_1 ) {
F_2 ( L_2 ) ;
F_3 ( V_4 , 1 ) ;
F_3 ( V_5 , 1 ) ;
F_4 ( 2000 ) ;
F_3 ( V_6 , 1 ) ;
F_4 ( 2000 ) ;
F_4 ( 2000 ) ;
F_3 ( V_7 , 1 ) ;
F_4 ( 2000 ) ;
F_3 ( V_8 , 1 ) ;
} else {
F_2 ( L_3 ) ;
F_5 ( 15 ) ;
F_3 ( V_8 , 0 ) ;
F_4 ( 500 ) ;
F_3 ( V_7 , 0 ) ;
F_4 ( 1000 ) ;
F_3 ( V_5 , 0 ) ;
F_3 ( V_6 , 0 ) ;
}
}
static void F_6 ( int V_1 , struct V_2 * V_3 )
{
F_2 ( L_4 ) ;
if ( V_1 ) {
F_2 ( L_2 ) ;
if ( V_9 < 3 )
F_3 ( V_10 , 1 ) ;
else
F_3 ( V_6 , 1 ) ;
F_7 ( 10 ) ;
F_3 ( V_5 , 1 ) ;
F_7 ( 10 ) ;
F_3 ( V_7 , 1 ) ;
F_7 ( 30 ) ;
F_3 ( V_8 , 1 ) ;
F_7 ( 10 ) ;
} else {
F_2 ( L_3 ) ;
F_7 ( 10 ) ;
F_3 ( V_8 , 0 ) ;
F_7 ( 30 ) ;
F_3 ( V_7 , 0 ) ;
F_7 ( 10 ) ;
F_3 ( V_5 , 0 ) ;
F_7 ( 10 ) ;
if ( V_9 < 3 )
F_3 ( V_10 , 0 ) ;
else
F_3 ( V_6 , 0 ) ;
}
}
static int F_8 ( struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_9 ( V_14 , L_5 ) ;
if ( V_13 )
goto V_15;
V_13 = F_9 ( V_16 , L_6 ) ;
if ( V_13 )
goto V_17;
return 0 ;
V_17:
F_10 ( V_14 ) ;
V_15:
return V_13 ;
}
static int F_11 ( struct V_11 * V_12 , int V_18 )
{
F_3 ( V_14 , V_18 ) ;
if ( V_18 >= 200 ) {
F_3 ( V_16 , 1 ) ;
return V_18 - 72 ;
} else {
F_3 ( V_16 , 0 ) ;
return V_18 ;
}
}
static void F_12 ( struct V_11 * V_12 )
{
F_10 ( V_14 ) ;
F_10 ( V_16 ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
return F_9 ( V_19 , L_7 ) ;
}
static int F_14 ( void )
{
return F_15 ( V_19 ) ;
}
static void F_16 ( struct V_11 * V_12 )
{
F_10 ( V_19 ) ;
}
static int F_17 ( struct V_11 * V_12 ,
T_1 V_20 , void * V_21 )
{
return F_18 ( V_22 , V_20 ,
V_23 | V_24 ,
L_8 , V_21 ) ;
}
static void F_19 ( struct V_11 * V_12 , void * V_21 )
{
F_20 ( V_22 , V_21 ) ;
}
static void F_21 ( struct V_25 * V_26 , int V_27 )
{
F_3 ( V_28 , V_27 ) ;
}
static void T_2 F_22 ( void )
{
void T_3 * V_29 ;
int V_30 ;
int V_15 ;
F_9 ( V_31 , L_9 ) ;
F_9 ( V_32 , L_10 ) ;
F_23 ( F_24 ( V_33 ) ) ;
F_25 ( NULL ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
F_28 ( F_24 ( V_34 ) ) ;
V_15 = F_9 ( V_35 , L_11 ) ;
if ( ! V_15 ) {
F_29 ( V_35 , 1 ) ;
F_30 ( & V_36 ) ;
}
F_31 ( NULL ) ;
F_32 ( & V_37 ) ;
F_33 ( & V_38 ) ;
F_34 ( & V_39 ) ;
V_29 = F_35 ( V_40 , 0x1000 ) ;
if ( V_29 ) {
T_4 V_41 = F_36 ( V_29 + 0x14 ) ;
F_37 ( V_29 ) ;
V_9 = V_41 & 0x7 ;
V_30 = V_41 & 0x8 ;
F_38 ( L_12 , V_30 ? L_13 : L_14 ) ;
if ( V_30 && ( V_9 < 3 ) ) {
F_9 ( V_10 , L_15 ) ;
F_29 ( V_10 , 0 ) ;
}
F_9 ( V_7 , L_16 ) ;
F_9 ( V_8 , L_17 ) ;
F_9 ( V_5 , L_18 ) ;
F_29 ( V_7 , 0 ) ;
F_29 ( V_8 , 0 ) ;
F_29 ( V_5 , 0 ) ;
F_39 ( NULL , V_30 ? & V_42 : & V_43 ) ;
} else
F_40 ( L_19 ) ;
}
