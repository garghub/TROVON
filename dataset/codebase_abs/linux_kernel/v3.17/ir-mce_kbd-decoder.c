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
if ( ! ( V_34 -> V_39 & V_40 ) )
return 0 ;
if ( ! F_8 ( V_36 ) ) {
if ( V_36 . V_41 )
V_1 -> V_42 = V_43 ;
return 0 ;
}
if ( ! F_9 ( V_36 . V_44 , V_45 , V_45 / 2 ) )
goto V_46;
V_47:
F_2 ( 2 , L_7 ,
V_1 -> V_42 , F_10 ( V_36 . V_44 ) , F_11 ( V_36 . V_48 ) ) ;
if ( ! F_9 ( V_36 . V_44 , V_45 , V_45 / 2 ) )
return 0 ;
switch ( V_1 -> V_42 ) {
case V_43 :
if ( ! V_36 . V_48 )
break;
if ( ! F_12 ( V_36 . V_44 , V_49 , V_45 ) )
break;
V_1 -> V_42 = V_50 ;
V_1 -> V_51 = 0 ;
V_1 -> V_10 = 0 ;
return 0 ;
case V_50 :
if ( F_9 ( V_36 . V_44 , V_52 , V_45 / 2 ) )
break;
V_1 -> V_10 <<= 1 ;
if ( V_36 . V_48 )
V_1 -> V_10 |= 1 ;
V_1 -> V_51 ++ ;
V_1 -> V_42 = V_53 ;
return 0 ;
case V_53 :
if ( ! F_13 ( & V_36 , & V_34 -> V_37 -> V_54 ) )
break;
F_14 ( & V_36 , V_55 ) ;
if ( V_1 -> V_51 != V_56 ) {
V_1 -> V_42 = V_50 ;
goto V_47;
}
switch ( V_9 ( V_1 ) ) {
case V_13 :
V_1 -> V_57 = V_58 ;
break;
case V_15 :
V_1 -> V_57 = V_59 ;
break;
default:
F_2 ( 1 , L_8 ) ;
goto V_46;
}
V_1 -> V_51 = 0 ;
V_1 -> V_60 = 0 ;
V_1 -> V_42 = V_61 ;
goto V_47;
case V_61 :
if ( F_9 ( V_36 . V_44 , V_52 , V_45 / 2 ) )
break;
V_1 -> V_60 <<= 1 ;
if ( V_36 . V_48 )
V_1 -> V_60 |= 1 ;
V_1 -> V_51 ++ ;
V_1 -> V_42 = V_62 ;
return 0 ;
case V_62 :
if ( ! F_13 ( & V_36 , & V_34 -> V_37 -> V_54 ) )
break;
if ( V_1 -> V_51 == V_1 -> V_57 )
V_1 -> V_42 = V_63 ;
else
V_1 -> V_42 = V_61 ;
F_14 ( & V_36 , V_55 ) ;
goto V_47;
case V_63 :
if ( V_36 . V_48 )
break;
switch ( V_1 -> V_57 ) {
case V_58 :
V_18 = V_1 -> V_60 & 0xffff ;
F_2 ( 1 , L_9 , V_1 -> V_60 ) ;
if ( V_34 -> V_64 )
V_38 = F_15 ( V_34 -> V_64 / 1000 ) ;
else
V_38 = F_16 ( 100 ) ;
F_17 ( & V_1 -> V_65 , V_66 + V_38 ) ;
F_4 ( V_1 -> V_8 , V_18 ) ;
break;
case V_59 :
V_18 = V_1 -> V_60 & 0x1fffff ;
F_2 ( 1 , L_10 , V_18 ) ;
F_5 ( V_1 -> V_8 , V_18 ) ;
break;
default:
F_2 ( 1 , L_8 ) ;
goto V_46;
}
V_1 -> V_42 = V_43 ;
F_18 ( V_1 -> V_8 ) ;
return 0 ;
}
V_46:
F_2 ( 1 , L_11 ,
V_1 -> V_42 , F_10 ( V_36 . V_44 ) , F_11 ( V_36 . V_48 ) ) ;
V_1 -> V_42 = V_43 ;
F_18 ( V_1 -> V_8 ) ;
return - V_67 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = & V_34 -> V_37 -> V_3 ;
struct V_17 * V_8 ;
int V_4 , V_68 ;
V_8 = F_20 () ;
if ( ! V_8 )
return - V_69 ;
snprintf ( V_3 -> V_70 , sizeof( V_3 -> V_70 ) ,
L_12 , V_34 -> V_71 ) ;
F_21 ( V_3 -> V_72 , L_13 , sizeof( V_3 -> V_72 ) ) ;
V_8 -> V_70 = V_3 -> V_70 ;
V_8 -> V_72 = V_3 -> V_72 ;
F_22 ( V_73 , V_8 -> V_74 ) ;
F_22 ( V_75 , V_8 -> V_74 ) ;
for ( V_4 = 0 ; V_4 < sizeof( V_6 ) ; V_4 ++ )
F_22 ( V_6 [ V_4 ] , V_8 -> V_76 ) ;
F_22 ( V_77 , V_8 -> V_74 ) ;
F_22 ( V_29 , V_8 -> V_78 ) ;
F_22 ( V_30 , V_8 -> V_78 ) ;
F_22 ( V_31 , V_8 -> V_76 ) ;
F_22 ( V_32 , V_8 -> V_76 ) ;
F_22 ( V_79 , V_8 -> V_74 ) ;
F_22 ( V_80 , V_8 -> V_81 ) ;
F_23 ( & V_3 -> V_65 , F_1 ,
( unsigned long ) V_3 ) ;
F_24 ( V_8 , V_3 ) ;
#if 0
idev->dev.parent = &dev->dev;
#endif
V_68 = F_25 ( V_8 ) ;
if ( V_68 < 0 ) {
F_26 ( V_8 ) ;
return - V_82 ;
}
V_3 -> V_8 = V_8 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = & V_34 -> V_37 -> V_3 ;
struct V_17 * V_8 = V_3 -> V_8 ;
F_28 ( & V_3 -> V_65 ) ;
F_29 ( V_8 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
F_31 ( & V_83 ) ;
F_32 ( V_84 L_14 ) ;
return 0 ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_83 ) ;
}
