static int F_1 ( int V_1 , unsigned V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
T_1 V_6 , V_7 ;
int V_8 = V_2 / 32 ;
int V_9 = V_2 & 0x1f ;
int V_10 = 0 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
V_6 = F_3 ( V_13 [ V_1 ] [ V_8 ] , V_11 . V_14 ) ;
if ( V_3 )
V_6 |= 1 << V_9 ;
else
V_6 &= ~ ( 1 << V_9 ) ;
F_4 ( V_6 , V_13 [ V_1 ] [ V_8 ] , V_11 . V_14 ) ;
V_7 = F_3 ( V_13 [ V_1 ] [ V_8 ] , V_11 . V_14 ) ;
if ( V_4 && V_6 != V_7 )
V_10 = - V_15 ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return V_10 ;
}
static int F_6 ( int V_1 , unsigned V_2 )
{
unsigned long V_5 ;
T_1 V_6 ;
int V_8 = V_2 / 32 ;
int V_9 = V_2 & 0x1f ;
F_2 ( & V_11 . V_12 , V_5 ) ;
V_6 = F_3 ( V_13 [ V_1 ] [ V_8 ] , V_11 . V_14 ) ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return V_6 & ( 1 << V_9 ) ? 1 : 0 ;
}
static int F_7 ( struct V_16 * V_17 , unsigned V_2 )
{
if ( F_1 ( V_18 , V_2 , 1 , 1 ) )
return - V_19 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , unsigned V_2 ,
int V_3 )
{
F_1 ( V_20 , V_2 , V_3 , 0 ) ;
if ( F_1 ( V_18 , V_2 , 0 , 1 ) )
return - V_19 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_21 , unsigned V_2 )
{
return F_6 ( V_20 , V_2 ) ;
}
static int F_10 ( struct V_16 * V_21 , unsigned V_2 )
{
unsigned long V_5 ;
T_1 V_6 ;
if ( V_2 < 16 ) {
if ( ! V_11 . V_22 )
return - V_23 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
F_4 ( 1 << ( 16 + V_2 ) , 0 , V_11 . V_22 ) ;
V_6 = F_3 ( 0 , V_11 . V_22 ) ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return ( V_6 >> 16 ) & ( 1 << V_2 ) ? 1 : 0 ;
} else {
return F_9 ( V_21 , V_2 ) ;
}
}
static int F_11 ( struct V_16 * V_21 , unsigned V_2 )
{
if ( V_11 . V_24 -> V_25 [ V_2 / 32 ] & ( 1 << ( V_2 & 0x1f ) ) )
return 1 ;
return F_6 ( V_26 , V_2 ) ? 0 : - V_27 ;
}
static int F_12 ( struct V_16 * V_21 , unsigned V_2 )
{
if ( V_2 == 16 || V_2 == 17 )
V_2 -= 16 ;
return F_11 ( V_21 , V_2 ) ;
}
static void F_13 ( struct V_16 * V_21 , unsigned V_2 , int V_3 )
{
F_1 ( V_20 , V_2 , V_3 , 0 ) ;
}
static void T_2 F_14 ( struct V_16 * V_21 )
{
V_21 -> V_28 = V_29 ;
V_21 -> V_30 = V_31 ;
V_21 -> V_32 = & V_11 . V_32 -> V_32 ;
V_21 -> V_33 = V_11 . V_24 -> V_33 ?
V_11 . V_24 -> V_33 : F_11 ;
V_21 -> V_34 = V_11 . V_24 -> V_34 ?
V_11 . V_24 -> V_34 : F_9 ;
V_21 -> V_35 = F_13 ;
V_21 -> V_36 = F_7 ;
V_21 -> V_37 = F_8 ;
V_21 -> V_38 = V_39 ;
V_21 -> V_40 = V_11 . V_24 -> V_40 ;
V_21 -> V_41 = 0 ;
V_21 -> V_42 = NULL ;
}
static int T_2 F_15 ( struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_47 ;
int V_48 ;
struct V_49 * V_50 = V_44 -> V_32 . V_51 ;
if ( ! V_50 )
return - V_27 ;
V_11 . V_32 = V_44 ;
switch ( V_50 -> V_52 ) {
case V_53 :
V_11 . V_24 = & V_54 ;
break;
case V_55 :
V_11 . V_24 = & V_56 ;
break;
case V_57 :
V_11 . V_24 = & V_58 ;
break;
case V_59 :
V_11 . V_24 = & V_60 ;
break;
case V_61 :
V_11 . V_24 = & V_62 ;
break;
case V_63 :
V_11 . V_24 = & V_64 ;
break;
case V_65 :
V_11 . V_24 = & V_66 ;
break;
default:
return - V_27 ;
}
V_46 = F_16 ( V_44 , V_67 , V_68 ) ;
if ( ! V_46 || ! V_46 -> V_69 || ! V_46 -> V_70 )
return - V_27 ;
if ( ! F_17 ( V_46 -> V_69 , F_18 ( V_46 ) ,
V_44 -> V_71 ) )
return - V_72 ;
V_11 . V_14 = V_46 ;
if ( ! V_11 . V_24 -> V_73 )
goto V_74;
V_47 = F_16 ( V_44 , V_67 , V_75 ) ;
if ( ! V_47 ) {
F_19 ( L_1 ) ;
goto V_74;
}
if ( ! F_17 ( V_47 -> V_69 , F_18 ( V_47 ) ,
V_44 -> V_71 ) ) {
F_19 ( L_2 ) ;
goto V_74;
}
V_11 . V_22 = V_47 ;
V_74:
F_14 ( & V_11 . V_21 ) ;
V_48 = F_20 ( & V_11 . V_21 ) ;
if ( V_48 ) {
F_21 ( L_3 ) ;
goto V_76;
}
F_22 ( L_4 , V_11 . V_21 . V_38 ,
V_11 . V_21 . V_38 + V_11 . V_21 . V_40 - 1 , V_31 ) ;
return 0 ;
V_76:
F_23 ( V_11 . V_14 -> V_69 ,
F_18 ( V_11 . V_14 ) ) ;
if ( V_11 . V_22 )
F_23 ( V_11 . V_22 -> V_69 ,
F_18 ( V_11 . V_22 ) ) ;
return V_48 ;
}
static int T_3 F_24 ( struct V_43 * V_44 )
{
int V_48 ;
V_48 = F_25 ( & V_11 . V_21 ) ;
if ( V_48 ) {
F_26 ( & V_44 -> V_32 , L_5 ,
L_6 , V_48 ) ;
return V_48 ;
}
F_23 ( V_11 . V_14 -> V_69 ,
F_18 ( V_11 . V_14 ) ) ;
if ( V_11 . V_22 )
F_23 ( V_11 . V_22 -> V_69 ,
F_18 ( V_11 . V_22 ) ) ;
return 0 ;
}
