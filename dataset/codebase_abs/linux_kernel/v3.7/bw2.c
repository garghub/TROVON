static int
F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_5 ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned long V_8 ;
T_2 V_9 ;
F_2 ( & V_5 -> V_10 , V_8 ) ;
switch ( V_1 ) {
case V_11 :
V_9 = F_3 ( & V_7 -> V_12 ) ;
V_9 |= V_13 ;
F_4 ( V_9 , & V_7 -> V_12 ) ;
V_5 -> V_8 &= ~ V_14 ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_9 = F_3 ( & V_7 -> V_12 ) ;
V_9 &= ~ V_13 ;
F_4 ( V_9 , & V_7 -> V_12 ) ;
V_5 -> V_8 |= V_14 ;
break;
}
F_5 ( & V_5 -> V_10 , V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_5 ;
return F_7 ( V_21 ,
V_3 -> V_22 . V_23 , V_3 -> V_22 . V_24 ,
V_5 -> V_25 ,
V_20 ) ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_26 , unsigned long V_27 )
{
return F_9 ( V_26 , V_27 , V_3 ,
V_28 , 1 , V_3 -> V_22 . V_24 ) ;
}
static void T_3 F_10 ( struct V_2 * V_3 , int V_29 )
{
F_11 ( V_3 -> V_22 . V_30 , L_1 , sizeof( V_3 -> V_22 . V_30 ) ) ;
V_3 -> V_22 . type = V_31 ;
V_3 -> V_22 . V_32 = V_33 ;
V_3 -> V_22 . V_34 = V_29 ;
V_3 -> V_22 . V_35 = V_36 ;
}
static int T_3 F_12 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
int * V_29 )
{
T_2 V_37 , V_38 ;
T_2 * V_39 ;
V_37 = F_3 ( & V_5 -> V_7 -> V_37 ) ;
V_38 = V_37 & V_40 ;
switch ( V_37 & V_41 ) {
case V_42 :
if ( V_38 == V_43 ) {
V_39 = V_44 ;
V_3 -> V_45 . V_46 = V_3 -> V_45 . V_47 = 1600 ;
V_3 -> V_45 . V_48 = V_3 -> V_45 . V_49 = 1280 ;
* V_29 = 1600 / 8 ;
} else
V_39 = V_50 ;
break;
case V_51 :
V_39 = V_52 ;
break;
case V_53 :
if ( V_38 == V_54 ||
V_38 == V_55 )
V_39 = V_56 ;
else
V_39 = V_57 ;
break;
case V_58 :
return 0 ;
default:
F_13 ( V_59 L_2 ,
V_37 ) ;
return - V_60 ;
}
for ( ; * V_39 ; V_39 += 2 ) {
T_2 T_1 * V_61 = & ( ( T_2 T_1 * ) V_5 -> V_7 ) [ V_39 [ 0 ] ] ;
F_4 ( V_39 [ 1 ] , V_61 ) ;
}
return 0 ;
}
static int T_3 F_14 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 . V_67 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_29 , V_68 ;
V_3 = F_15 ( sizeof( struct V_4 ) , & V_63 -> V_66 ) ;
V_68 = - V_69 ;
if ( ! V_3 )
goto V_70;
V_5 = V_3 -> V_5 ;
F_16 ( & V_5 -> V_10 ) ;
V_3 -> V_22 . V_23 = V_63 -> V_71 [ 0 ] . V_72 ;
V_5 -> V_25 = V_63 -> V_71 [ 0 ] . V_8 & V_73 ;
F_17 ( & V_3 -> V_45 , V_65 , 1 ) ;
V_29 = F_18 ( V_65 , L_3 ,
V_3 -> V_45 . V_46 ) ;
V_3 -> V_45 . V_74 . V_75 = V_3 -> V_45 . V_76 . V_75 =
V_3 -> V_45 . V_77 . V_75 = V_3 -> V_45 . V_78 ;
V_3 -> V_45 . V_74 . V_79 = V_3 -> V_45 . V_76 . V_79 =
V_3 -> V_45 . V_77 . V_79 = 0 ;
V_5 -> V_7 = F_19 ( & V_63 -> V_71 [ 0 ] , V_80 ,
sizeof( struct V_6 ) , L_4 ) ;
if ( ! V_5 -> V_7 )
goto V_81;
if ( ! F_20 ( V_65 , L_5 , NULL ) ) {
V_68 = F_12 ( V_5 , V_3 , & V_29 ) ;
if ( V_68 )
goto V_82;
}
V_3 -> V_22 . V_24 = F_21 ( V_29 * V_3 -> V_45 . V_48 ) ;
V_3 -> V_8 = V_83 ;
V_3 -> V_84 = & V_85 ;
V_3 -> V_86 = F_19 ( & V_63 -> V_71 [ 0 ] , 0 ,
V_3 -> V_22 . V_24 , L_6 ) ;
if ( ! V_3 -> V_86 ) {
V_68 = - V_69 ;
goto V_82;
}
F_1 ( V_11 , V_3 ) ;
F_10 ( V_3 , V_29 ) ;
V_68 = F_22 ( V_3 ) ;
if ( V_68 < 0 )
goto V_87;
F_23 ( & V_63 -> V_66 , V_3 ) ;
F_13 ( V_88 L_7 ,
V_65 -> V_89 , V_5 -> V_25 , V_3 -> V_22 . V_23 ) ;
return 0 ;
V_87:
F_24 ( & V_63 -> V_71 [ 0 ] , V_3 -> V_86 , V_3 -> V_22 . V_24 ) ;
V_82:
F_24 ( & V_63 -> V_71 [ 0 ] , V_5 -> V_7 , sizeof( struct V_6 ) ) ;
V_81:
F_25 ( V_3 ) ;
V_70:
return V_68 ;
}
static int T_4 F_26 ( struct V_62 * V_63 )
{
struct V_2 * V_3 = F_27 ( & V_63 -> V_66 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_28 ( V_3 ) ;
F_24 ( & V_63 -> V_71 [ 0 ] , V_5 -> V_7 , sizeof( struct V_6 ) ) ;
F_24 ( & V_63 -> V_71 [ 0 ] , V_3 -> V_86 , V_3 -> V_22 . V_24 ) ;
F_25 ( V_3 ) ;
F_23 ( & V_63 -> V_66 , NULL ) ;
return 0 ;
}
static int T_5 F_29 ( void )
{
if ( F_30 ( L_8 , NULL ) )
return - V_90 ;
return F_31 ( & V_91 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_91 ) ;
}
