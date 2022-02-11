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
return F_9 ( F_10 ( V_13 ) ) ;
}
static int F_11 ( struct V_11 * V_12 , int V_14 )
{
F_3 ( V_15 , V_14 ) ;
if ( V_14 >= 200 ) {
F_3 ( V_16 , 1 ) ;
return V_14 - 72 ;
} else {
F_3 ( V_16 , 0 ) ;
return V_14 ;
}
}
static void F_12 ( struct V_11 * V_12 )
{
F_13 ( F_10 ( V_13 ) ) ;
}
static int F_14 ( struct V_11 * V_12 )
{
return F_15 ( V_17 , L_5 ) ;
}
static int F_16 ( void )
{
return F_17 ( V_17 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
F_19 ( V_17 ) ;
}
static int F_20 ( struct V_11 * V_12 ,
T_1 V_18 , void * V_19 )
{
return F_21 ( V_20 , V_18 , 0 ,
L_6 , V_19 ) ;
}
static void F_22 ( struct V_11 * V_12 , void * V_19 )
{
F_23 ( V_20 , V_19 ) ;
}
static void F_24 ( struct V_21 * V_22 , int V_23 )
{
F_3 ( V_24 , V_23 ) ;
}
static void T_2 F_25 ( void )
{
void T_3 * V_25 ;
int V_26 ;
int V_27 ;
F_26 ( F_10 ( V_28 ) ) ;
V_27 = F_9 ( F_10 ( V_29 ) ) ;
if ( V_27 )
F_27 ( L_7 , V_27 ) ;
F_28 ( NULL ) ;
F_29 ( NULL ) ;
F_30 ( NULL ) ;
F_31 ( F_10 ( V_30 ) ) ;
F_32 ( & V_31 ) ;
F_33 ( NULL ) ;
F_34 ( & V_32 ) ;
F_35 ( & V_33 ) ;
F_36 ( & V_34 ) ;
V_25 = F_37 ( V_35 , 0x1000 ) ;
if ( V_25 ) {
T_4 V_36 = F_38 ( V_25 + 0x14 ) ;
F_39 ( V_25 ) ;
V_9 = V_36 & 0x7 ;
V_26 = V_36 & 0x8 ;
F_40 ( L_8 , V_26 ? L_9 : L_10 ) ;
if ( V_26 && ( V_9 < 3 ) )
F_41 ( V_10 ,
V_37 , L_11 ) ;
F_42 ( NULL , V_26 ? & V_38 : & V_39 ) ;
} else
F_27 ( L_12 ) ;
}
