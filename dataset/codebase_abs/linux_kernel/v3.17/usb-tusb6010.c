static int F_1 ( unsigned V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 ;
unsigned V_6 = V_1 + 3000 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_7 = 8 * 1000 ;
V_3 . V_8 = V_6 - 7000 ;
V_3 . V_9 = 1000 ;
V_3 . V_10 = V_6 ;
V_3 . V_11 = V_6 + 1000 ;
V_3 . V_12 = 300 ;
V_3 . V_13 = 7000 ;
V_3 . V_14 = V_3 . V_13 ;
V_3 . V_15 = V_6 ;
V_3 . V_16 = V_6 + 1000 ;
V_3 . V_17 = 300 ;
V_3 . V_18 = 1 ;
F_2 ( & V_5 , & V_19 , & V_3 ) ;
return F_3 ( V_20 , & V_5 ) ;
}
static int F_4 ( unsigned V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 ;
unsigned V_21 = V_1 + 3000 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_22 = 11100 ;
V_3 . V_23 = 1000 ;
V_3 . V_24 = 1000 ;
V_3 . V_7 = 8 * 1000 ;
V_3 . V_8 = V_21 - 7000 ;
V_3 . V_9 = 1000 ;
V_3 . V_10 = V_21 ;
V_3 . V_25 = 3 ;
V_3 . V_26 = 5 ;
V_3 . V_27 = 7000 ;
V_3 . V_15 = V_21 ;
V_3 . V_18 = 3 ;
V_3 . V_28 = 6 ;
F_2 ( & V_5 , & V_29 , & V_3 ) ;
return F_3 ( V_30 , & V_5 ) ;
}
int F_5 ( unsigned V_31 )
{
static const char error [] =
V_32 L_1 ;
unsigned V_1 ;
int V_33 ;
if ( ! V_34 )
return - V_35 ;
V_1 = V_31 ? V_34 : V_36 ;
V_33 = F_1 ( V_1 ) ;
if ( V_33 < 0 ) {
F_6 ( error , L_2 , V_33 ) ;
goto V_37;
}
V_33 = F_4 ( V_1 ) ;
if ( V_33 < 0 )
F_6 ( error , L_3 , V_33 ) ;
V_37:
return V_33 ;
}
int T_1
F_7 ( struct V_38 * V_39 ,
unsigned V_40 , unsigned V_41 ,
unsigned V_42 , unsigned V_43 ,
unsigned V_44 , unsigned V_45 )
{
int V_33 ;
static char error [] V_46 =
V_32 L_4 ;
V_33 = F_8 ( V_42 , V_47 , ( unsigned long * )
& V_48 [ 0 ] . V_49 ) ;
if ( V_33 < 0 ) {
F_6 ( error , 1 , V_33 ) ;
return V_33 ;
}
V_48 [ 0 ] . V_50 = V_48 [ 0 ] . V_49 + 0x9ff ;
V_19 . V_51 = V_41 ;
V_20 = V_42 ;
V_33 = F_9 ( V_20 , & V_19 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_8 ( V_43 , V_47 , ( unsigned long * )
& V_48 [ 1 ] . V_49 ) ;
if ( V_33 < 0 ) {
F_6 ( error , 2 , V_33 ) ;
return V_33 ;
}
V_48 [ 1 ] . V_50 = V_48 [ 1 ] . V_49 + 0x9ff ;
V_29 . V_51 = V_41 ;
V_30 = V_43 ;
V_33 = F_9 ( V_30 , & V_29 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_10 ( V_44 , V_52 , L_5 ) ;
if ( V_33 < 0 ) {
F_6 ( error , 3 , V_33 ) ;
return V_33 ;
}
V_48 [ 2 ] . V_49 = F_11 ( V_44 ) ;
if ( ! V_40 ) {
F_6 ( error , 4 , V_33 ) ;
return - V_35 ;
}
V_34 = V_40 ;
V_33 = F_5 ( 1 ) ;
if ( V_33 < 0 ) {
F_6 ( error , 5 , V_33 ) ;
return V_33 ;
}
if ( ! V_39 ) {
F_6 ( error , 6 , V_33 ) ;
return - V_35 ;
}
V_53 . V_54 . V_55 = V_39 ;
if ( ! V_45 )
V_53 . V_54 . V_56 = NULL ;
else {
if ( V_45 & ( 1 << 0 ) )
F_12 ( L_6 , 0 ) ;
if ( V_45 & ( 1 << 1 ) )
F_12 ( L_7 , 0 ) ;
if ( V_45 & ( 1 << 2 ) )
F_12 ( L_8 , 0 ) ;
if ( V_45 & ( 1 << 3 ) )
F_12 ( L_9 , 0 ) ;
if ( V_45 & ( 1 << 4 ) )
F_12 ( L_10 , 0 ) ;
if ( V_45 & ( 1 << 5 ) )
F_12 ( L_11 , 0 ) ;
}
V_33 = F_13 ( & V_53 ) ;
if ( V_33 < 0 ) {
F_6 ( error , 7 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
