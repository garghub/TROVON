static unsigned
F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 )
{
unsigned V_4 = V_1 * 1000 ;
unsigned V_5 , V_6 ;
if ( ( V_4 + V_3 ) < V_2 )
return V_2 / 1000 ;
V_5 = ( V_4 + V_3 - 1 ) / V_3 ;
V_6 = ( V_2 + V_3 - 1 ) / V_3 ;
if ( V_5 >= V_6 )
V_6 = V_5 + 1 ;
return ( V_6 * V_3 ) / 1000 ;
}
static int F_2 ( unsigned V_7 , unsigned V_3 )
{
struct V_8 V_9 ;
unsigned V_10 = V_7 + 3000 ;
unsigned V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = 8 ;
V_9 . V_13 = F_1 ( V_9 . V_12 , V_10 - 7000 , V_3 ) ;
V_9 . V_14 = F_1 ( V_9 . V_13 , V_10 , V_3 ) ;
V_9 . V_15 = F_1 ( V_9 . V_13 , V_10 + 1000 , V_3 ) ;
V_11 = V_9 . V_15 * 1000 + 300 ;
V_9 . V_16 = F_1 ( V_9 . V_15 , V_11 , V_3 ) ;
V_11 = V_9 . V_16 * 1000 ;
V_9 . V_17 = F_1 ( V_9 . V_16 , V_11 , V_3 ) ;
V_9 . V_18 = V_9 . V_17 ;
V_11 = V_9 . V_18 * 1000 + 7000 ;
V_9 . V_19 = F_1 ( V_9 . V_18 , V_11 , V_3 ) ;
V_9 . V_20 = V_9 . V_14 ;
V_9 . V_21 = F_1 ( V_9 . V_20 , V_10 + 1000 , V_3 ) ;
V_11 = V_9 . V_21 * 1000 + 300 ;
V_9 . V_22 = F_1 ( V_9 . V_21 , V_11 , V_3 ) ;
V_9 . V_23 = V_9 . V_22 ;
V_11 = V_9 . V_23 * 1000 + 7000 ;
V_9 . V_24 = F_1 ( V_9 . V_23 , V_11 , V_3 ) ;
return F_3 ( V_25 , & V_9 ) ;
}
static int F_4 ( unsigned V_7 , unsigned V_3 )
{
struct V_8 V_9 ;
unsigned V_26 = V_7 + 3000 ;
unsigned V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = 8 ;
V_9 . V_13 = F_1 ( V_9 . V_12 , V_26 - 7000 , V_3 ) ;
V_9 . V_27 = 11100 ;
V_11 = ( V_9 . V_27 + V_3 - 1 ) / V_3 ;
if ( V_11 > 4 )
return - V_28 ;
if ( V_11 <= 0 )
V_11 = 1 ;
V_9 . V_29 = ( V_3 * V_11 ) / 1000 ;
V_9 . V_14 = F_1 ( V_9 . V_13 , V_26 , V_3 ) ;
V_11 = ( V_9 . V_14 * 1000 ) + ( 3 * V_3 ) ;
V_9 . V_15 = F_1 ( V_9 . V_13 , V_11 , V_3 ) ;
V_11 = ( V_9 . V_15 * 1000 ) + ( 5 * V_3 ) ;
V_9 . V_16 = F_1 ( V_9 . V_15 , V_11 , V_3 ) ;
V_11 = ( V_9 . V_16 * 1000 ) + ( 1 * V_3 ) ;
V_9 . V_17 = F_1 ( V_9 . V_16 , V_11 , V_3 ) ;
V_9 . V_18 = V_9 . V_17 ;
V_11 = V_9 . V_18 * 1000 + 7000 ;
V_9 . V_19 = F_1 ( V_9 . V_18 , V_11 , V_3 ) ;
V_9 . V_20 = V_9 . V_14 ;
V_11 = ( V_9 . V_20 * 1000 ) + ( 3 * V_3 ) ;
V_9 . V_21 = F_1 ( V_9 . V_20 , V_11 , V_3 ) ;
V_11 = ( V_9 . V_21 * 1000 ) + ( 6 * V_3 ) ;
V_9 . V_22 = F_1 ( V_9 . V_21 , V_11 , V_3 ) ;
V_9 . V_23 = V_9 . V_22 ;
V_11 = V_9 . V_23 * 1000 + 7000 ;
V_9 . V_24 = F_1 ( V_9 . V_23 , V_11 , V_3 ) ;
return F_3 ( V_30 , & V_9 ) ;
}
int F_5 ( unsigned V_31 )
{
static const char error [] =
V_32 L_1 ;
unsigned V_3 = F_6 () ;
unsigned V_7 ;
int V_33 ;
if ( ! V_34 || V_3 == 0 )
return - V_35 ;
V_7 = V_31 ? V_34 : V_36 ;
V_33 = F_2 ( V_7 , V_3 ) ;
if ( V_33 < 0 ) {
F_7 ( error , L_2 , V_33 ) ;
goto V_37;
}
V_33 = F_4 ( V_7 , V_3 ) ;
if ( V_33 < 0 )
F_7 ( error , L_3 , V_33 ) ;
V_37:
return V_33 ;
}
int T_1
F_8 ( struct V_38 * V_39 ,
unsigned V_40 , unsigned V_41 ,
unsigned V_42 , unsigned V_43 ,
unsigned V_44 , unsigned V_45 )
{
int V_33 ;
static char error [] V_46 =
V_32 L_4 ;
V_33 = F_9 ( V_42 , V_47 , ( unsigned long * )
& V_48 [ 0 ] . V_49 ) ;
if ( V_33 < 0 ) {
F_7 ( error , 1 , V_33 ) ;
return V_33 ;
}
V_48 [ 0 ] . V_50 = V_48 [ 0 ] . V_49 + 0x9ff ;
V_25 = V_42 ;
F_10 ( V_42 , V_51 ,
F_11 ( 2 )
| V_52
| V_53
| F_12 ( V_41 )
| V_54
| V_55
| V_56
| V_57
| V_58 ) ;
V_33 = F_9 ( V_43 , V_47 , ( unsigned long * )
& V_48 [ 1 ] . V_49 ) ;
if ( V_33 < 0 ) {
F_7 ( error , 2 , V_33 ) ;
return V_33 ;
}
V_48 [ 1 ] . V_50 = V_48 [ 1 ] . V_49 + 0x9ff ;
V_30 = V_43 ;
F_10 ( V_43 , V_51 ,
V_59
| V_60
| V_61
| V_62
| F_13 ( 1 )
| F_11 ( 2 )
| V_52
| V_53
| F_12 ( V_41 )
| V_56
| V_57
| V_58
) ;
V_33 = F_14 ( V_44 , V_63 , L_5 ) ;
if ( V_33 < 0 ) {
F_7 ( error , 3 , V_33 ) ;
return V_33 ;
}
V_48 [ 2 ] . V_49 = V_44 + V_64 ;
if ( ! V_40 ) {
F_7 ( error , 4 , V_33 ) ;
return - V_35 ;
}
V_34 = V_40 ;
V_33 = F_5 ( 1 ) ;
if ( V_33 < 0 ) {
F_7 ( error , 5 , V_33 ) ;
return V_33 ;
}
if ( ! V_39 ) {
F_7 ( error , 6 , V_33 ) ;
return - V_35 ;
}
V_65 . V_66 . V_67 = V_39 ;
if ( ! V_45 )
V_65 . V_66 . V_68 = NULL ;
else {
if ( V_45 & ( 1 << 0 ) )
F_15 ( L_6 , 0 ) ;
if ( V_45 & ( 1 << 1 ) )
F_15 ( L_7 , 0 ) ;
if ( V_45 & ( 1 << 2 ) )
F_15 ( L_8 , 0 ) ;
if ( V_45 & ( 1 << 3 ) )
F_15 ( L_9 , 0 ) ;
if ( V_45 & ( 1 << 4 ) )
F_15 ( L_10 , 0 ) ;
if ( V_45 & ( 1 << 5 ) )
F_15 ( L_11 , 0 ) ;
}
V_33 = F_16 ( & V_65 ) ;
if ( V_33 < 0 ) {
F_7 ( error , 7 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
