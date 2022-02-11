static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
signed char * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_8 = V_1 -> V_8 ;
int V_9 ;
switch ( V_8 ) {
case 0 :
break;
case - V_10 :
case - V_11 :
case - V_12 :
return;
default:
goto V_13;
}
F_2 ( V_7 , V_14 , V_5 [ 0 ] & 0x02 ) ;
F_3 ( V_7 ) ;
V_13:
V_9 = F_4 ( V_1 , V_15 ) ;
if ( V_9 )
F_5 ( & V_7 -> V_7 , L_1
L_2 , V_3 -> V_16 -> V_17 -> V_18 ,
V_3 -> V_16 -> V_19 , V_9 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_7 ( V_7 ) ;
V_3 -> V_20 = 1 ;
V_3 -> V_21 -> V_7 = V_3 -> V_16 ;
if ( F_4 ( V_3 -> V_21 , V_22 ) ) {
F_5 ( & V_7 -> V_7 , L_3 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_7 ( V_7 ) ;
F_9 ( V_3 -> V_21 ) ;
V_3 -> V_20 = 0 ;
}
static void F_10 ( struct V_24 * V_25 , int V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_25 -> V_27 ;
if ( V_3 -> V_20 ) {
switch ( V_26 ) {
case V_28 :
F_9 ( V_3 -> V_21 ) ;
break;
case V_29 :
if ( F_4 ( V_3 -> V_21 , V_30 ) != 0 )
F_5 ( & V_3 -> V_21 -> V_7 -> V_7 ,
L_3 ) ;
break;
default:
break;
}
}
}
static int F_11 ( struct V_24 * V_31 )
{
struct V_32 * V_16 = V_31 -> V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_6 * V_6 ;
int V_38 , V_39 ;
int error = - V_40 ;
V_35 = V_31 -> V_41 -> V_42 ;
if ( V_35 -> V_43 . V_44 != 3 )
return - V_45 ;
V_37 = & V_35 -> V_37 [ 2 ] . V_43 ;
if ( ! F_12 ( V_37 ) )
return - V_45 ;
V_38 = F_13 ( V_16 , V_37 -> V_46 ) ;
V_39 = F_14 ( V_16 , V_38 , F_15 ( V_38 ) ) ;
V_39 = F_16 ( V_39 , V_47 ) ;
V_3 = F_17 ( sizeof( struct V_2 ) , V_22 ) ;
V_6 = F_18 () ;
if ( ! V_3 || ! V_6 )
goto V_48;
V_3 -> V_5 = F_19 ( V_16 , V_47 ,
V_22 , & V_3 -> V_49 ) ;
if ( ! V_3 -> V_5 )
goto V_48;
V_3 -> V_21 = F_20 ( 0 , V_22 ) ;
if ( ! V_3 -> V_21 )
goto V_50;
V_3 -> V_16 = V_16 ;
V_3 -> V_7 = V_6 ;
if ( V_16 -> V_51 )
F_21 ( V_3 -> V_52 , V_16 -> V_51 ,
sizeof( V_3 -> V_52 ) ) ;
if ( V_16 -> V_53 ) {
if ( V_16 -> V_51 )
F_22 ( V_3 -> V_52 , L_4 , sizeof( V_3 -> V_52 ) ) ;
F_22 ( V_3 -> V_52 , V_16 -> V_53 , sizeof( V_3 -> V_52 ) ) ;
}
if ( ! strlen ( V_3 -> V_52 ) )
snprintf ( V_3 -> V_52 , sizeof( V_3 -> V_52 ) ,
L_5 ,
F_23 ( V_16 -> V_54 . V_55 ) ,
F_23 ( V_16 -> V_54 . V_56 ) ) ;
F_24 ( V_16 , V_3 -> V_57 , sizeof( V_3 -> V_57 ) ) ;
F_22 ( V_3 -> V_57 , L_6 , sizeof( V_3 -> V_57 ) ) ;
V_6 -> V_52 = V_3 -> V_52 ;
V_6 -> V_57 = V_3 -> V_57 ;
F_25 ( V_16 , & V_6 -> V_58 ) ;
V_6 -> V_7 . V_59 = & V_16 -> V_7 ;
F_26 ( V_60 , V_6 -> V_61 ) ;
F_26 ( V_14 , V_6 -> V_62 ) ;
F_27 ( 0 , V_6 -> V_62 ) ;
F_28 ( V_6 , V_3 ) ;
V_6 -> V_63 = F_6 ;
V_6 -> V_64 = F_8 ;
F_29 ( V_3 -> V_21 , V_16 , V_38 , V_3 -> V_5 , V_39 ,
F_1 , V_3 , V_37 -> V_65 ) ;
V_3 -> V_21 -> V_66 = V_3 -> V_49 ;
V_3 -> V_21 -> V_67 |= V_68 ;
V_31 -> V_69 = V_70 ;
V_31 -> V_27 = V_3 ;
#ifdef F_30
V_31 -> V_71 = F_10 ;
#endif
error = F_31 ( V_3 -> V_7 ) ;
if ( error )
goto V_72;
return 0 ;
V_72: F_32 ( V_3 -> V_21 ) ;
V_50: F_33 ( V_16 , V_47 ,
V_3 -> V_5 , V_3 -> V_49 ) ;
V_48: F_34 ( V_3 ) ;
F_35 ( V_6 ) ;
return error ;
}
static void V_70 ( void * V_73 )
{
struct V_2 * V_3 = (struct V_2 * ) V_73 ;
if ( V_3 ) {
F_9 ( V_3 -> V_21 ) ;
F_36 ( V_3 -> V_7 ) ;
F_32 ( V_3 -> V_21 ) ;
F_33 ( V_3 -> V_16 , V_47 ,
V_3 -> V_5 , V_3 -> V_49 ) ;
}
}
static int F_37 ( struct V_74 * V_75 ,
const struct V_76 * V_58 )
{
struct V_24 * V_25 ;
int V_77 ;
V_77 = F_38 ( & V_25 , V_75 , V_58 ,
( V_58 - V_78 ) + V_79 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_39 ( V_25 ) ;
return V_77 ;
}
