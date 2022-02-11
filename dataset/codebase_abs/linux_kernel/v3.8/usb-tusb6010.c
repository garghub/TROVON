static int F_1 ( unsigned V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 ;
unsigned V_6 = V_1 + 3000 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_7 = true ;
V_3 . V_8 = 8 * 1000 ;
V_3 . V_9 = V_6 - 7000 ;
V_3 . V_10 = 1000 ;
V_3 . V_11 = V_6 ;
V_3 . V_12 = V_6 + 1000 ;
V_3 . V_13 = 300 ;
V_3 . V_14 = 7000 ;
V_3 . V_15 = V_3 . V_14 ;
V_3 . V_16 = V_6 ;
V_3 . V_17 = V_6 + 1000 ;
V_3 . V_18 = 300 ;
V_3 . V_19 = 1 ;
F_2 ( & V_5 , & V_3 ) ;
return F_3 ( V_20 , & V_5 ) ;
}
static int F_4 ( unsigned V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 ;
unsigned V_21 = V_1 + 3000 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_7 = true ;
V_3 . V_22 = true ;
V_3 . V_23 = true ;
V_3 . V_24 = 11100 ;
V_3 . V_25 = 1000 ;
V_3 . V_26 = 1000 ;
V_3 . V_8 = 8 * 1000 ;
V_3 . V_9 = V_21 - 7000 ;
V_3 . V_10 = 1000 ;
V_3 . V_11 = V_21 ;
V_3 . V_27 = 3 ;
V_3 . V_28 = 5 ;
V_3 . V_29 = 7000 ;
V_3 . V_16 = V_21 ;
V_3 . V_19 = 3 ;
V_3 . V_30 = 6 ;
V_3 . V_29 = 7000 ;
F_2 ( & V_5 , & V_3 ) ;
return F_3 ( V_31 , & V_5 ) ;
}
int F_5 ( unsigned V_32 )
{
static const char error [] =
V_33 L_1 ;
unsigned V_1 ;
int V_34 ;
if ( ! V_35 )
return - V_36 ;
V_1 = V_32 ? V_35 : V_37 ;
V_34 = F_1 ( V_1 ) ;
if ( V_34 < 0 ) {
F_6 ( error , L_2 , V_34 ) ;
goto V_38;
}
V_34 = F_4 ( V_1 ) ;
if ( V_34 < 0 )
F_6 ( error , L_3 , V_34 ) ;
V_38:
return V_34 ;
}
int T_1
F_7 ( struct V_39 * V_40 ,
unsigned V_41 , unsigned V_42 ,
unsigned V_43 , unsigned V_44 ,
unsigned V_45 , unsigned V_46 )
{
int V_34 ;
static char error [] V_47 =
V_33 L_4 ;
V_34 = F_8 ( V_43 , V_48 , ( unsigned long * )
& V_49 [ 0 ] . V_50 ) ;
if ( V_34 < 0 ) {
F_6 ( error , 1 , V_34 ) ;
return V_34 ;
}
V_49 [ 0 ] . V_51 = V_49 [ 0 ] . V_50 + 0x9ff ;
V_20 = V_43 ;
F_9 ( V_43 , V_52 ,
F_10 ( 2 )
| V_53
| V_54
| F_11 ( V_42 )
| V_55
| V_56
| V_57
| V_58
| V_59 ) ;
V_34 = F_8 ( V_44 , V_48 , ( unsigned long * )
& V_49 [ 1 ] . V_50 ) ;
if ( V_34 < 0 ) {
F_6 ( error , 2 , V_34 ) ;
return V_34 ;
}
V_49 [ 1 ] . V_51 = V_49 [ 1 ] . V_50 + 0x9ff ;
V_31 = V_44 ;
F_9 ( V_44 , V_52 ,
V_60
| V_61
| V_62
| V_63
| F_10 ( 2 )
| V_53
| V_54
| F_11 ( V_42 )
| V_57
| V_58
| V_59
) ;
V_34 = F_12 ( V_45 , V_64 , L_5 ) ;
if ( V_34 < 0 ) {
F_6 ( error , 3 , V_34 ) ;
return V_34 ;
}
V_49 [ 2 ] . V_50 = F_13 ( V_45 ) ;
if ( ! V_41 ) {
F_6 ( error , 4 , V_34 ) ;
return - V_36 ;
}
V_35 = V_41 ;
V_34 = F_5 ( 1 ) ;
if ( V_34 < 0 ) {
F_6 ( error , 5 , V_34 ) ;
return V_34 ;
}
if ( ! V_40 ) {
F_6 ( error , 6 , V_34 ) ;
return - V_36 ;
}
V_65 . V_66 . V_67 = V_40 ;
if ( ! V_46 )
V_65 . V_66 . V_68 = NULL ;
else {
if ( V_46 & ( 1 << 0 ) )
F_14 ( L_6 , 0 ) ;
if ( V_46 & ( 1 << 1 ) )
F_14 ( L_7 , 0 ) ;
if ( V_46 & ( 1 << 2 ) )
F_14 ( L_8 , 0 ) ;
if ( V_46 & ( 1 << 3 ) )
F_14 ( L_9 , 0 ) ;
if ( V_46 & ( 1 << 4 ) )
F_14 ( L_10 , 0 ) ;
if ( V_46 & ( 1 << 5 ) )
F_14 ( L_11 , 0 ) ;
}
V_34 = F_15 ( & V_65 ) ;
if ( V_34 < 0 ) {
F_6 ( error , 7 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
