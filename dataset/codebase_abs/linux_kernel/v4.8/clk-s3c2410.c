static int F_1 ( void )
{
F_2 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
return 0 ;
}
static void F_4 ( void )
{
F_5 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
}
static void F_6 ( void )
{
V_2 = F_7 ( V_3 ,
F_3 ( V_3 ) ) ;
if ( ! V_2 ) {
F_8 ( L_1 ,
V_4 ) ;
return;
}
F_9 ( & V_5 ) ;
return;
}
static void F_6 ( void ) {}
static void T_1 F_10 (
struct V_6 * V_7 ,
unsigned long V_8 )
{
struct V_9 V_10 = F_11 ( V_11 , NULL , L_2 ) ;
V_12 [ 0 ] . V_13 = V_8 ;
F_12 ( V_7 , V_12 ,
F_3 ( V_12 ) ) ;
F_13 ( V_7 , & V_10 , 1 ) ;
}
void T_1 F_14 ( struct V_14 * V_15 , unsigned long V_8 ,
int V_16 ,
void T_2 * V_17 )
{
struct V_6 * V_7 ;
V_1 = V_17 ;
if ( V_15 ) {
V_1 = F_15 ( V_15 , 0 ) ;
if ( ! V_1 )
F_16 ( L_3 , V_4 ) ;
}
V_7 = F_17 ( V_15 , V_1 , V_18 ) ;
if ( ! V_15 )
F_10 ( V_7 , V_8 ) ;
if ( V_16 == V_19 ) {
if ( F_18 ( L_4 ) == 12 * V_20 ) {
V_21 [ V_22 ] . V_23 = V_24 ;
V_21 [ V_25 ] . V_23 = V_24 ;
}
F_19 ( V_7 , V_21 ,
F_3 ( V_21 ) , V_1 ) ;
} else {
if ( F_18 ( L_4 ) == 12 * V_20 ) {
V_26 [ V_22 ] . V_23 =
V_27 ;
V_26 [ V_25 ] . V_23 =
V_24 ;
}
F_19 ( V_7 , V_26 ,
F_3 ( V_26 ) , V_1 ) ;
}
F_20 ( V_7 , V_28 ,
F_3 ( V_28 ) ) ;
F_21 ( V_7 , V_29 ,
F_3 ( V_29 ) ) ;
F_22 ( V_7 , V_30 ,
F_3 ( V_30 ) ) ;
if ( V_16 == V_31 || V_16 == V_32 ) {
F_21 ( V_7 , V_33 ,
F_3 ( V_33 ) ) ;
F_22 ( V_7 , V_34 ,
F_3 ( V_34 ) ) ;
F_20 ( V_7 , V_35 ,
F_3 ( V_35 ) ) ;
F_23 ( V_7 , V_36 ,
F_3 ( V_36 ) ) ;
}
switch ( V_16 ) {
case V_19 :
F_21 ( V_7 , V_37 ,
F_3 ( V_37 ) ) ;
F_23 ( V_7 , V_38 ,
F_3 ( V_38 ) ) ;
F_13 ( V_7 , V_39 ,
F_3 ( V_39 ) ) ;
break;
case V_31 :
F_20 ( V_7 , V_40 ,
F_3 ( V_40 ) ) ;
F_22 ( V_7 , V_41 ,
F_3 ( V_41 ) ) ;
break;
case V_32 :
F_20 ( V_7 , V_42 ,
F_3 ( V_42 ) ) ;
F_23 ( V_7 , V_43 ,
F_3 ( V_43 ) ) ;
break;
}
F_13 ( V_7 , V_44 ,
F_3 ( V_44 ) ) ;
if ( V_16 == V_31 || V_16 == V_32 ) {
F_13 ( V_7 , V_45 ,
F_3 ( V_45 ) ) ;
}
F_6 () ;
F_24 ( V_15 , V_7 ) ;
}
static void T_1 F_25 ( struct V_14 * V_15 )
{
F_14 ( V_15 , 0 , V_19 , 0 ) ;
}
static void T_1 F_26 ( struct V_14 * V_15 )
{
F_14 ( V_15 , 0 , V_31 , 0 ) ;
}
static void T_1 F_27 ( struct V_14 * V_15 )
{
F_14 ( V_15 , 0 , V_32 , 0 ) ;
}
