struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 V_8 = {
. V_9 = V_6 ,
. V_5 = V_10 ,
} ;
F_2 ( V_2 -> V_11 . V_12 ,
F_3 ( V_4 ) , V_5 , & V_8 ) ;
if ( V_8 . V_13 )
return V_8 . V_13 ;
F_4 ( & V_2 -> V_11 . V_14 -> V_15 ) ;
return & V_2 -> V_11 . V_14 -> V_15 ;
}
static int F_5 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_5 , struct V_7 * V_8 )
{
struct V_3 * V_20 = & V_19 -> V_21 . V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 ;
struct V_2 * V_2 = V_17 -> V_27 ;
T_1 V_6 = V_8 -> V_9 ;
switch ( V_17 -> V_28 ) {
case V_29 :
break;
case V_30 :
V_24 = V_2 -> V_11 . V_14 ;
goto V_31;
default:
case V_32 :
V_24 = V_2 -> V_11 . V_33 ;
goto V_31;
case V_34 :
V_24 = V_2 -> V_11 . V_35 ;
goto V_31;
}
V_26 = F_6 ( V_2 , V_17 -> V_26 ) ;
if ( V_26 )
V_24 = V_6 ( V_2 , V_26 , V_20 , V_5 ) ;
if ( V_24 != V_2 -> V_11 . V_14 ) {
struct V_36 * V_37 = (struct V_36 * ) V_17 ;
if ( ( V_17 -> V_5 & V_38 ) &&
V_37 -> V_39 . V_40 && ! ( V_5 & V_41 ) ) {
struct V_42 V_43 ;
if ( F_7 ( V_2 ,
F_8 ( & V_24 -> V_15 ) -> V_44 ,
& V_20 -> V_45 ,
F_9 ( V_5 ) ,
& V_43 ) )
goto V_46;
if ( ! F_10 ( & V_43 , & V_37 -> V_39 . V_47 ,
V_37 -> V_39 . V_40 ) )
goto V_46;
V_20 -> V_43 = V_43 ;
}
goto V_48;
}
V_46:
F_11 ( V_24 ) ;
V_24 = NULL ;
goto V_48;
V_31:
F_4 ( & V_24 -> V_15 ) ;
V_48:
V_8 -> V_13 = V_24 ;
return V_24 == NULL ? - V_49 : 0 ;
}
static int F_12 ( struct V_16 * V_17 , struct V_18 * V_50 , int V_5 )
{
struct V_36 * V_37 = (struct V_36 * ) V_17 ;
struct V_3 * V_4 = & V_50 -> V_21 . V_22 ;
if ( V_37 -> V_15 . V_40 &&
! F_10 ( & V_4 -> V_45 , & V_37 -> V_15 . V_47 , V_37 -> V_15 . V_40 ) )
return 0 ;
if ( V_37 -> V_39 . V_40 ) {
if ( V_5 & V_41 ) {
if ( ! F_10 ( & V_4 -> V_43 , & V_37 -> V_39 . V_47 ,
V_37 -> V_39 . V_40 ) )
return 0 ;
} else if ( ! ( V_37 -> V_51 . V_5 & V_38 ) )
return 0 ;
}
if ( V_37 -> V_52 && V_37 -> V_52 != ( ( F_13 ( V_4 -> V_53 ) >> 20 ) & 0xff ) )
return 0 ;
return 1 ;
}
static int F_14 ( struct V_16 * V_17 , struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * * V_59 )
{
int V_60 = - V_61 ;
struct V_2 * V_2 = F_15 ( V_55 -> V_62 ) ;
struct V_36 * V_63 = (struct V_36 * ) V_17 ;
if ( V_17 -> V_28 == V_29 ) {
if ( V_17 -> V_26 == V_64 )
goto V_65;
if ( F_16 ( V_2 , V_17 -> V_26 ) == NULL ) {
V_60 = - V_66 ;
goto V_65;
}
}
if ( V_57 -> V_67 )
F_17 ( & V_63 -> V_39 . V_47 , V_59 [ V_68 ] ,
sizeof( struct V_42 ) ) ;
if ( V_57 -> V_69 )
F_17 ( & V_63 -> V_15 . V_47 , V_59 [ V_70 ] ,
sizeof( struct V_42 ) ) ;
V_63 -> V_39 . V_40 = V_57 -> V_67 ;
V_63 -> V_15 . V_40 = V_57 -> V_69 ;
V_63 -> V_52 = V_57 -> V_71 ;
V_60 = 0 ;
V_65:
return V_60 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_56 * V_57 ,
struct V_58 * * V_59 )
{
struct V_36 * V_63 = (struct V_36 * ) V_17 ;
if ( V_57 -> V_67 && ( V_63 -> V_39 . V_40 != V_57 -> V_67 ) )
return 0 ;
if ( V_57 -> V_69 && ( V_63 -> V_15 . V_40 != V_57 -> V_69 ) )
return 0 ;
if ( V_57 -> V_71 && ( V_63 -> V_52 != V_57 -> V_71 ) )
return 0 ;
if ( V_57 -> V_67 &&
F_19 ( V_59 [ V_68 ] , & V_63 -> V_39 . V_47 , sizeof( struct V_42 ) ) )
return 0 ;
if ( V_57 -> V_69 &&
F_19 ( V_59 [ V_70 ] , & V_63 -> V_15 . V_47 , sizeof( struct V_42 ) ) )
return 0 ;
return 1 ;
}
static int F_20 ( struct V_16 * V_17 , struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_36 * V_63 = (struct V_36 * ) V_17 ;
V_57 -> V_69 = V_63 -> V_15 . V_40 ;
V_57 -> V_67 = V_63 -> V_39 . V_40 ;
V_57 -> V_71 = V_63 -> V_52 ;
if ( ( V_63 -> V_15 . V_40 &&
F_21 ( V_55 , V_70 , sizeof( struct V_42 ) ,
& V_63 -> V_15 . V_47 ) ) ||
( V_63 -> V_39 . V_40 &&
F_21 ( V_55 , V_68 , sizeof( struct V_42 ) ,
& V_63 -> V_39 . V_47 ) ) )
goto V_72;
return 0 ;
V_72:
return - V_66 ;
}
static T_2 F_22 ( struct V_73 * V_74 )
{
return 0x3FFF ;
}
static T_3 F_23 ( struct V_16 * V_17 )
{
return F_24 ( 16 )
+ F_24 ( 16 ) ;
}
static int T_4 F_25 ( struct V_2 * V_2 )
{
struct V_73 * V_74 ;
int V_60 = - V_75 ;
V_74 = F_26 ( & V_76 , V_2 ) ;
if ( F_27 ( V_74 ) )
return F_28 ( V_74 ) ;
V_2 -> V_11 . V_12 = V_74 ;
V_60 = F_29 ( V_2 -> V_11 . V_12 , 0 ,
V_77 , 0 ) ;
if ( V_60 )
goto V_78;
V_60 = F_29 ( V_2 -> V_11 . V_12 ,
0x7FFE , V_79 , 0 ) ;
if ( V_60 )
goto V_78;
V_48:
return V_60 ;
V_78:
F_30 ( V_74 ) ;
goto V_48;
}
static void T_5 F_31 ( struct V_2 * V_2 )
{
F_30 ( V_2 -> V_11 . V_12 ) ;
}
int T_6 F_32 ( void )
{
return F_33 ( & V_80 ) ;
}
void F_34 ( void )
{
F_35 ( & V_80 ) ;
}
