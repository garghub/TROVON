static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
int V_13 , V_14 ;
switch ( V_1 -> V_14 ) {
case 0 :
break;
case - V_15 :
case - V_16 :
case - V_17 :
F_3 ( & V_10 -> V_7 , L_1 ,
V_18 , V_1 -> V_14 ) ;
return;
default:
F_3 ( & V_10 -> V_7 , L_2 ,
V_18 , V_1 -> V_14 ) ;
goto V_19;
}
V_13 = ( V_5 [ 0 ] & 0x04 ) >> 2 ;
F_4 ( V_7 , V_20 , V_13 ) ;
if ( V_13 ) {
int V_21 = V_5 [ 1 ] | ( V_5 [ 2 ] << 8 ) ;
int V_22 = V_5 [ 3 ] | ( V_5 [ 4 ] << 8 ) ;
int V_23 = V_5 [ 5 ] | ( V_5 [ 6 ] << 8 ) ;
int V_24 = V_5 [ 0 ] & 0x01 ;
int V_25 = ( V_5 [ 0 ] & 0x10 ) >> 4 ;
int V_26 = ( V_5 [ 0 ] & 0x20 ) >> 5 ;
F_5 ( V_7 , V_27 , V_21 ) ;
F_5 ( V_7 , V_28 , V_22 ) ;
F_5 ( V_7 , V_29 , V_23 ) ;
F_4 ( V_7 , V_30 , V_24 ) ;
F_4 ( V_7 , V_31 , V_25 ) ;
F_4 ( V_7 , V_32 , V_26 ) ;
}
F_6 ( V_7 ) ;
V_19:
V_14 = F_7 ( V_1 , V_33 ) ;
if ( V_14 )
F_8 ( & V_10 -> V_7 ,
L_3 ,
V_12 -> V_34 -> V_35 ,
V_12 -> V_36 , V_14 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_10 ( V_7 ) ;
V_3 -> V_37 -> V_7 = F_2 ( V_3 -> V_10 ) ;
if ( F_7 ( V_3 -> V_37 , V_38 ) )
return - V_39 ;
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_10 ( V_7 ) ;
F_12 ( V_3 -> V_37 ) ;
}
static int F_13 ( struct V_9 * V_10 , const struct V_40 * V_41 )
{
struct V_11 * V_7 = F_2 ( V_10 ) ;
struct V_42 * V_43 = V_10 -> V_44 ;
struct V_45 * V_46 ;
struct V_2 * V_3 ;
struct V_6 * V_6 ;
int V_47 , V_48 ;
int V_49 ;
if ( V_43 -> V_50 . V_51 != 1 )
return - V_52 ;
V_46 = & V_43 -> V_46 [ 0 ] . V_50 ;
if ( ! F_14 ( V_46 ) )
return - V_52 ;
V_47 = F_15 ( V_7 , V_46 -> V_53 ) ;
V_48 = F_16 ( V_7 , V_47 , F_17 ( V_47 ) ) ;
V_3 = F_18 ( sizeof( struct V_2 ) , V_38 ) ;
V_6 = F_19 () ;
if ( ! V_3 || ! V_6 ) {
V_49 = - V_54 ;
goto V_55;
}
V_3 -> V_5 = F_20 ( V_7 , 8 , V_38 , & V_3 -> V_56 ) ;
if ( ! V_3 -> V_5 ) {
V_49 = - V_54 ;
goto V_55;
}
V_3 -> V_37 = F_21 ( 0 , V_38 ) ;
if ( ! V_3 -> V_37 ) {
V_49 = - V_54 ;
goto V_57;
}
V_3 -> V_10 = V_10 ;
V_3 -> V_8 = V_6 ;
if ( V_7 -> V_58 )
F_22 ( V_3 -> V_59 , V_7 -> V_58 , sizeof( V_3 -> V_59 ) ) ;
if ( V_7 -> V_60 ) {
if ( V_7 -> V_58 )
F_23 ( V_3 -> V_59 , L_4 , sizeof( V_3 -> V_59 ) ) ;
F_23 ( V_3 -> V_59 , V_7 -> V_60 , sizeof( V_3 -> V_59 ) ) ;
}
F_24 ( V_7 , V_3 -> V_61 , sizeof( V_3 -> V_61 ) ) ;
F_23 ( V_3 -> V_61 , L_5 , sizeof( V_3 -> V_61 ) ) ;
V_6 -> V_59 = V_3 -> V_59 ;
V_6 -> V_61 = V_3 -> V_61 ;
F_25 ( V_7 , & V_6 -> V_41 ) ;
V_6 -> V_7 . V_62 = & V_10 -> V_7 ;
F_26 ( V_6 , V_3 ) ;
V_6 -> V_63 = F_9 ;
V_6 -> V_64 = F_11 ;
V_6 -> V_65 [ 0 ] = F_27 ( V_66 ) | F_27 ( V_67 ) ;
V_6 -> V_68 [ F_28 ( V_69 ) ] = F_27 ( V_20 ) |
F_27 ( V_30 ) | F_27 ( V_31 ) |
F_27 ( V_32 ) ;
switch ( V_41 -> V_70 ) {
case 0 :
F_29 ( V_6 , V_27 , 0 , 5000 , 4 , 0 ) ;
F_29 ( V_6 , V_28 , 0 , 3750 , 4 , 0 ) ;
F_29 ( V_6 , V_29 , 0 , 512 , 0 , 0 ) ;
if ( ! strlen ( V_3 -> V_59 ) )
snprintf ( V_3 -> V_59 , sizeof( V_3 -> V_59 ) ,
L_6 ,
F_30 ( V_7 -> V_71 . V_72 ) ,
F_30 ( V_7 -> V_71 . V_73 ) ) ;
break;
case 1 :
F_29 ( V_6 , V_27 , 0 , 53000 , 4 , 0 ) ;
F_29 ( V_6 , V_28 , 0 , 2250 , 4 , 0 ) ;
F_29 ( V_6 , V_29 , 0 , 1024 , 0 , 0 ) ;
if ( ! strlen ( V_3 -> V_59 ) )
snprintf ( V_3 -> V_59 , sizeof( V_3 -> V_59 ) ,
L_7 ,
F_30 ( V_7 -> V_71 . V_72 ) ,
F_30 ( V_7 -> V_71 . V_73 ) ) ;
break;
}
F_31 ( V_3 -> V_37 , V_7 , V_47 ,
V_3 -> V_5 , V_48 > 8 ? 8 : V_48 ,
F_1 , V_3 , V_46 -> V_74 ) ;
V_3 -> V_37 -> V_75 = V_3 -> V_56 ;
V_3 -> V_37 -> V_76 |= V_77 ;
V_49 = F_32 ( V_3 -> V_8 ) ;
if ( V_49 )
goto V_78;
F_33 ( V_10 , V_3 ) ;
return 0 ;
V_78: F_34 ( V_3 -> V_37 ) ;
V_57: F_35 ( V_7 , 8 , V_3 -> V_5 , V_3 -> V_56 ) ;
V_55: F_36 ( V_6 ) ;
F_37 ( V_3 ) ;
return V_49 ;
}
static void F_38 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_39 ( V_10 ) ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
F_33 ( V_10 , NULL ) ;
F_40 ( V_3 -> V_8 ) ;
F_34 ( V_3 -> V_37 ) ;
F_35 ( V_12 , 8 , V_3 -> V_5 , V_3 -> V_56 ) ;
F_37 ( V_3 ) ;
}
