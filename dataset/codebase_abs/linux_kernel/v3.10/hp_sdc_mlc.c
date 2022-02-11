static void F_1 ( int V_1 , void * V_2 ,
T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_2 * V_6 = & V_7 ;
F_2 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 < 0 ) {
F_3 (KERN_WARNING PREFIX L_1 ) ;
F_4 ( & V_6 -> V_10 ) ;
goto V_11;
}
V_5 = 15 - V_6 -> V_9 ;
if ( ( V_3 & V_12 ) == V_13 ) {
V_6 -> V_14 [ V_5 ] |= V_4 | V_15 ;
V_6 -> V_9 -- ;
if ( V_16 . V_17 || ! V_5 )
goto V_18;
if ( ( V_6 -> V_14 [ V_5 - 1 ] & V_19 ) !=
( V_6 -> V_14 [ V_5 ] & V_19 ) ) {
V_6 -> V_14 [ V_5 ] &= ~ V_19 ;
V_6 -> V_14 [ V_5 ] |= ( V_6 -> V_14 [ V_5 - 1 ]
& V_19 ) ;
}
goto V_18;
}
if ( V_4 & V_20 )
goto V_21;
V_6 -> V_14 [ V_5 ] =
( V_4 & V_22 ) << V_23 ;
V_16 . V_17 = 1 ;
goto V_11;
V_18:
V_16 . V_17 = 0 ;
if ( V_6 -> V_24 == 0 )
goto V_25;
if ( ( V_6 -> V_24 == ( V_15 | V_26 | V_27 ) )
&& ( V_6 -> V_14 [ V_5 ] == ( V_6 -> V_24 | V_5 ) ) )
goto V_25;
if ( V_6 -> V_14 [ V_5 ] == V_6 -> V_24 )
goto V_25;
goto V_11;
V_21:
F_3 (KERN_DEBUG PREFIX L_2 , data) ;
switch ( V_4 ) {
case V_28 :
F_3 (KERN_WARNING PREFIX L_3 ) ;
break;
case V_29 :
V_6 -> V_14 [ V_5 ] |= V_15 | V_30 |
V_31 | V_32 ;
break;
case V_33 :
V_6 -> V_14 [ V_5 ] |= V_15 | V_34 ;
break;
case V_35 :
F_3 (KERN_WARNING PREFIX L_4 ) ;
break;
default:
F_3 (KERN_WARNING PREFIX L_5 , data) ;
break;
}
V_25:
F_5 ( V_6 -> V_36 ) ;
F_4 ( & V_6 -> V_10 ) ;
V_11:
F_6 ( & V_6 -> V_8 ) ;
}
static int F_7 ( T_2 * V_6 , T_3 V_37 )
{
struct V_38 * V_39 ;
int V_40 = 2 ;
V_39 = V_6 -> V_39 ;
if ( F_8 ( & V_6 -> V_10 ) ) {
struct V_41 V_42 ;
if ( V_39 -> V_43 ) {
V_6 -> V_14 [ 0 ] =
V_15 | ( V_6 -> V_44 &
( V_26 |
V_19 |
V_45 ) ) ;
V_6 -> V_9 = 14 ;
goto V_46;
}
F_9 ( & V_42 ) ;
V_42 . V_47 += V_48 * ( V_42 . V_49 - V_6 -> V_50 . V_49 ) ;
if ( V_42 . V_47 - V_6 -> V_50 . V_47 > V_6 -> V_51 ) {
V_40 = 1 ;
F_4 ( & V_6 -> V_10 ) ;
}
goto V_25;
}
V_46:
F_4 ( & V_6 -> V_10 ) ;
V_40 = 0 ;
V_25:
return V_40 ;
}
static int F_10 ( T_2 * V_6 )
{
struct V_38 * V_39 ;
V_39 = V_6 -> V_39 ;
F_11 ( F_8 ( & V_6 -> V_10 ) ) ;
F_11 ( F_8 ( & V_6 -> V_52 ) ) ;
F_4 ( & V_6 -> V_10 ) ;
F_4 ( & V_6 -> V_52 ) ;
if ( F_8 ( & V_6 -> V_53 ) ) {
if ( V_39 -> V_54 . V_55 . V_56 != & V_6 -> V_53 )
goto V_57;
else
goto V_58;
}
if ( ! ( V_39 -> V_59 [ 4 ] & V_60 ) )
goto V_25;
V_57:
V_39 -> V_54 . V_55 . V_56 = & V_6 -> V_53 ;
V_39 -> V_54 . V_61 = 0 ;
V_39 -> V_54 . V_5 = 1 ;
V_39 -> V_54 . V_62 = 5 ;
V_39 -> V_59 [ 0 ] =
V_63 | V_64 | V_65 ;
V_39 -> V_59 [ 1 ] = V_66 ;
V_39 -> V_59 [ 2 ] = 1 ;
V_39 -> V_59 [ 3 ] = 0 ;
V_39 -> V_59 [ 4 ] = 0 ;
F_12 ( & V_39 -> V_54 ) ;
V_58:
return 1 ;
V_25:
V_39 -> V_54 . V_55 . V_56 = & V_6 -> V_52 ;
F_4 ( & V_6 -> V_53 ) ;
return 0 ;
}
static void F_13 ( T_2 * V_6 )
{
struct V_38 * V_39 ;
V_39 = V_6 -> V_39 ;
F_11 ( F_8 ( & V_6 -> V_52 ) ) ;
if ( V_6 -> V_44 & V_67 )
goto V_68;
V_69:
if ( V_39 -> V_43 ) {
F_4 ( & V_6 -> V_52 ) ;
return;
}
F_11 ( F_8 ( & V_6 -> V_53 ) ) ;
F_4 ( & V_6 -> V_53 ) ;
V_39 -> V_54 . V_61 = 0 ;
V_39 -> V_54 . V_5 = 1 ;
V_39 -> V_54 . V_55 . V_56 = & V_6 -> V_52 ;
V_39 -> V_54 . V_62 = 6 ;
V_39 -> V_59 [ 0 ] =
V_70 | V_63 | V_65 ;
V_39 -> V_59 [ 1 ] = 0x7 ;
V_39 -> V_59 [ 2 ] =
( V_6 -> V_44 &
( V_19 | V_26 ) )
>> V_23 ;
V_39 -> V_59 [ 3 ] =
( V_6 -> V_44 & V_45 )
>> V_71 ;
V_39 -> V_59 [ 4 ] = 0 ;
if ( V_39 -> V_59 [ 3 ] == V_72 )
V_39 -> V_59 [ 4 ] = 1 ;
V_39 -> V_59 [ 5 ] = V_73 ;
goto V_74;
V_68:
V_39 -> V_43 = V_6 -> V_44 & V_75 ;
F_11 ( ( V_6 -> V_44 & ( V_76 | V_77 ) ) == V_76 ) ;
if ( ( V_6 -> V_44 & V_78 ) == V_78 )
goto V_79;
F_11 ( V_6 -> V_44 & V_76 ) ;
goto V_69;
V_79:
V_39 -> V_54 . V_61 = 0 ;
V_39 -> V_54 . V_5 = 1 ;
V_39 -> V_54 . V_55 . V_56 = & V_6 -> V_52 ;
V_39 -> V_54 . V_62 = 4 ;
V_39 -> V_59 [ 0 ] =
V_80 | V_81 | V_65 ;
V_39 -> V_59 [ 1 ] = V_82 ;
V_39 -> V_59 [ 2 ] = 1 ;
V_39 -> V_59 [ 3 ] = 0 ;
if ( V_6 -> V_44 & V_76 ) {
V_39 -> V_59 [ 3 ] |= V_83 ;
F_11 ( F_8 ( & V_6 -> V_53 ) ) ;
}
V_74:
F_14 ( & V_39 -> V_54 ) ;
}
static int T_4 F_15 ( void )
{
T_2 * V_6 = & V_7 ;
int V_21 ;
#ifdef F_16
if ( ! V_84 )
return - V_85 ;
#endif
F_3 (KERN_INFO PREFIX L_6 ) ;
V_16 . V_43 = 0 ;
V_16 . V_54 . V_86 = V_16 . V_59 ;
V_16 . V_54 . V_55 . V_56 = & V_6 -> V_52 ;
V_16 . V_17 = 0 ;
V_6 -> V_87 = & F_10 ;
V_6 -> V_88 = & F_7 ;
V_6 -> V_11 = & F_13 ;
V_6 -> V_39 = & V_16 ;
V_21 = F_17 ( V_6 ) ;
if ( V_21 ) {
F_3 (KERN_WARNING PREFIX L_7 ) ;
return V_21 ;
}
if ( F_18 ( & F_1 ) ) {
F_3 (KERN_WARNING PREFIX L_8 ) ;
if ( F_19 ( V_6 ) )
F_3 (KERN_ERR PREFIX L_9
L_10 ) ;
return - V_89 ;
}
return 0 ;
}
static void T_5 F_20 ( void )
{
T_2 * V_6 = & V_7 ;
if ( F_21 ( & F_1 ) )
F_3 (KERN_ERR PREFIX L_11
L_10 ) ;
if ( F_19 ( V_6 ) )
F_3 (KERN_ERR PREFIX L_9
L_10 ) ;
}
