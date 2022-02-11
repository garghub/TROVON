static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 ;
unsigned char V_5 ;
F_2 ( 2 , L_1 ) ;
for ( V_4 = 0 ; V_4 < 7 ; V_4 ++ ) {
V_5 = V_6 [ V_7 + V_4 ] ;
F_3 ( V_3 -> V_8 , V_5 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_3 ( V_3 -> V_8 , V_6 [ V_4 ] , 0 ) ;
}
static enum V_9 V_9 ( struct V_2 * V_1 )
{
switch ( V_1 -> V_10 & V_11 ) {
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
default:
return V_16 ;
}
}
static void F_4 ( struct V_17 * V_8 ,
T_1 V_18 )
{
T_2 V_19 = ( V_18 >> 8 ) & 0xff ;
T_2 V_20 = V_18 & 0xff ;
unsigned char V_21 , V_5 ;
int V_4 , V_22 ;
F_2 ( 1 , L_2 ,
V_19 , V_20 ) ;
for ( V_4 = 0 ; V_4 < 7 ; V_4 ++ ) {
V_5 = V_6 [ V_7 + V_4 ] ;
if ( V_20 & ( 1 << V_4 ) )
V_22 = 1 ;
else
V_22 = 0 ;
F_3 ( V_8 , V_5 , V_22 ) ;
}
if ( V_19 ) {
V_21 = V_6 [ V_19 ] ;
F_3 ( V_8 , V_21 , 1 ) ;
} else {
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_3 ( V_8 , V_6 [ V_4 ] , 0 ) ;
}
}
static void F_5 ( struct V_17 * V_8 , T_1 V_18 )
{
T_2 V_23 = ( V_18 >> 7 ) & 0x7f ;
T_2 V_24 = ( V_18 >> 14 ) & 0x7f ;
int V_25 , V_26 ;
bool V_27 = V_18 & 0x40 ;
bool V_28 = V_18 & 0x20 ;
if ( V_23 & 0x40 )
V_25 = - ( ( ~ V_23 & 0x7f ) + 1 ) ;
else
V_25 = V_23 ;
if ( V_24 & 0x40 )
V_26 = - ( ( ~ V_24 & 0x7f ) + 1 ) ;
else
V_26 = V_24 ;
F_2 ( 1 , L_3 ,
V_25 , V_26 , V_28 ? L_4 : L_5 , V_27 ? L_6 : L_5 ) ;
F_6 ( V_8 , V_29 , V_25 ) ;
F_6 ( V_8 , V_30 , V_26 ) ;
F_3 ( V_8 , V_31 , V_28 ) ;
F_3 ( V_8 , V_32 , V_27 ) ;
}
static int F_7 ( struct V_33 * V_34 , struct V_35 V_36 )
{
struct V_2 * V_1 = & V_34 -> V_37 -> V_3 ;
T_1 V_18 ;
unsigned long V_38 ;
if ( ! F_8 ( V_36 ) ) {
if ( V_36 . V_39 )
V_1 -> V_40 = V_41 ;
return 0 ;
}
if ( ! F_9 ( V_36 . V_42 , V_43 , V_43 / 2 ) )
goto V_44;
V_45:
F_2 ( 2 , L_7 ,
V_1 -> V_40 , F_10 ( V_36 . V_42 ) , F_11 ( V_36 . V_46 ) ) ;
if ( ! F_9 ( V_36 . V_42 , V_43 , V_43 / 2 ) )
return 0 ;
switch ( V_1 -> V_40 ) {
case V_41 :
if ( ! V_36 . V_46 )
break;
if ( ! F_12 ( V_36 . V_42 , V_47 , V_43 ) )
break;
V_1 -> V_40 = V_48 ;
V_1 -> V_49 = 0 ;
V_1 -> V_10 = 0 ;
return 0 ;
case V_48 :
if ( F_9 ( V_36 . V_42 , V_50 , V_43 / 2 ) )
break;
V_1 -> V_10 <<= 1 ;
if ( V_36 . V_46 )
V_1 -> V_10 |= 1 ;
V_1 -> V_49 ++ ;
V_1 -> V_40 = V_51 ;
return 0 ;
case V_51 :
if ( ! F_13 ( & V_36 , & V_34 -> V_37 -> V_52 ) )
break;
F_14 ( & V_36 , V_53 ) ;
if ( V_1 -> V_49 != V_54 ) {
V_1 -> V_40 = V_48 ;
goto V_45;
}
switch ( V_9 ( V_1 ) ) {
case V_13 :
V_1 -> V_55 = V_56 ;
break;
case V_15 :
V_1 -> V_55 = V_57 ;
break;
default:
F_2 ( 1 , L_8 ) ;
goto V_44;
}
V_1 -> V_49 = 0 ;
V_1 -> V_58 = 0 ;
V_1 -> V_40 = V_59 ;
goto V_45;
case V_59 :
if ( F_9 ( V_36 . V_42 , V_50 , V_43 / 2 ) )
break;
V_1 -> V_58 <<= 1 ;
if ( V_36 . V_46 )
V_1 -> V_58 |= 1 ;
V_1 -> V_49 ++ ;
V_1 -> V_40 = V_60 ;
return 0 ;
case V_60 :
if ( ! F_13 ( & V_36 , & V_34 -> V_37 -> V_52 ) )
break;
if ( V_1 -> V_49 == V_1 -> V_55 )
V_1 -> V_40 = V_61 ;
else
V_1 -> V_40 = V_59 ;
F_14 ( & V_36 , V_53 ) ;
goto V_45;
case V_61 :
if ( V_36 . V_46 )
break;
switch ( V_1 -> V_55 ) {
case V_56 :
V_18 = V_1 -> V_58 & 0xffff ;
F_2 ( 1 , L_9 , V_1 -> V_58 ) ;
if ( V_34 -> V_62 )
V_38 = F_15 ( V_34 -> V_62 / 1000 ) ;
else
V_38 = F_16 ( 100 ) ;
F_17 ( & V_1 -> V_63 , V_64 + V_38 ) ;
F_4 ( V_1 -> V_8 , V_18 ) ;
break;
case V_57 :
V_18 = V_1 -> V_58 & 0x1fffff ;
F_2 ( 1 , L_10 , V_18 ) ;
F_5 ( V_1 -> V_8 , V_18 ) ;
break;
default:
F_2 ( 1 , L_8 ) ;
goto V_44;
}
V_1 -> V_40 = V_41 ;
F_18 ( V_1 -> V_8 ) ;
return 0 ;
}
V_44:
F_2 ( 1 , L_11 ,
V_1 -> V_40 , F_10 ( V_36 . V_42 ) , F_11 ( V_36 . V_46 ) ) ;
V_1 -> V_40 = V_41 ;
F_18 ( V_1 -> V_8 ) ;
return - V_65 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = & V_34 -> V_37 -> V_3 ;
struct V_17 * V_8 ;
int V_4 , V_66 ;
V_8 = F_20 () ;
if ( ! V_8 )
return - V_67 ;
snprintf ( V_3 -> V_68 , sizeof( V_3 -> V_68 ) ,
L_12 , V_34 -> V_69 ) ;
F_21 ( V_3 -> V_70 , L_13 , sizeof( V_3 -> V_70 ) ) ;
V_8 -> V_68 = V_3 -> V_68 ;
V_8 -> V_70 = V_3 -> V_70 ;
F_22 ( V_71 , V_8 -> V_72 ) ;
F_22 ( V_73 , V_8 -> V_72 ) ;
for ( V_4 = 0 ; V_4 < sizeof( V_6 ) ; V_4 ++ )
F_22 ( V_6 [ V_4 ] , V_8 -> V_74 ) ;
F_22 ( V_75 , V_8 -> V_72 ) ;
F_22 ( V_29 , V_8 -> V_76 ) ;
F_22 ( V_30 , V_8 -> V_76 ) ;
F_22 ( V_31 , V_8 -> V_74 ) ;
F_22 ( V_32 , V_8 -> V_74 ) ;
F_22 ( V_77 , V_8 -> V_72 ) ;
F_22 ( V_78 , V_8 -> V_79 ) ;
F_23 ( & V_3 -> V_63 , F_1 ,
( unsigned long ) V_3 ) ;
F_24 ( V_8 , V_3 ) ;
#if 0
idev->dev.parent = &dev->dev;
#endif
V_66 = F_25 ( V_8 ) ;
if ( V_66 < 0 ) {
F_26 ( V_8 ) ;
return - V_80 ;
}
V_3 -> V_8 = V_8 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = & V_34 -> V_37 -> V_3 ;
struct V_17 * V_8 = V_3 -> V_8 ;
F_28 ( & V_3 -> V_63 ) ;
F_29 ( V_8 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
F_31 ( & V_81 ) ;
F_32 ( V_82 L_14 ) ;
return 0 ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_81 ) ;
}
