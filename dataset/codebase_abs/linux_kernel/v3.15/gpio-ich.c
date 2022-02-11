static int F_1 ( int V_1 , unsigned V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
T_1 V_6 , V_7 ;
int V_8 = V_2 / 32 ;
int V_9 = V_2 & 0x1f ;
int V_10 = 0 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
if ( V_1 == V_13 && V_11 . V_14 -> V_15 )
V_6 = V_11 . V_16 [ V_8 ] ;
else
V_6 = F_3 ( V_11 . V_14 -> V_17 [ V_1 ] [ V_8 ] ,
V_11 . V_18 ) ;
if ( V_3 )
V_6 |= 1 << V_9 ;
else
V_6 &= ~ ( 1 << V_9 ) ;
F_4 ( V_6 , V_11 . V_14 -> V_17 [ V_1 ] [ V_8 ] ,
V_11 . V_18 ) ;
if ( V_1 == V_13 && V_11 . V_14 -> V_15 )
V_11 . V_16 [ V_8 ] = V_6 ;
V_7 = F_3 ( V_11 . V_14 -> V_17 [ V_1 ] [ V_8 ] ,
V_11 . V_18 ) ;
if ( V_4 && V_6 != V_7 )
V_10 = - V_19 ;
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
V_6 = F_3 ( V_11 . V_14 -> V_17 [ V_1 ] [ V_8 ] ,
V_11 . V_18 ) ;
if ( V_1 == V_13 && V_11 . V_14 -> V_15 )
V_6 = V_11 . V_16 [ V_8 ] | V_6 ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return V_6 & ( 1 << V_9 ) ? 1 : 0 ;
}
static bool F_7 ( struct V_20 * V_21 , unsigned V_2 )
{
return ! ! ( V_11 . V_22 & ( 1 << ( V_2 / 32 ) ) ) ;
}
static int F_8 ( struct V_20 * V_21 , unsigned V_2 )
{
if ( F_1 ( V_23 , V_2 , 1 , 1 ) )
return - V_24 ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , unsigned V_2 ,
int V_3 )
{
if ( V_2 < 32 && V_11 . V_14 -> V_25 )
F_1 ( V_26 , V_2 , 0 , 0 ) ;
F_1 ( V_13 , V_2 , V_3 , 0 ) ;
if ( F_1 ( V_23 , V_2 , 0 , 1 ) )
return - V_24 ;
return 0 ;
}
static int F_10 ( struct V_20 * V_27 , unsigned V_2 )
{
return F_6 ( V_13 , V_2 ) ;
}
static int F_11 ( struct V_20 * V_27 , unsigned V_2 )
{
unsigned long V_5 ;
T_1 V_6 ;
if ( V_2 < 16 ) {
if ( ! V_11 . V_28 )
return - V_29 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
F_4 ( 1 << ( 16 + V_2 ) , 0 , V_11 . V_28 ) ;
V_6 = F_3 ( 0 , V_11 . V_28 ) ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return ( V_6 >> 16 ) & ( 1 << V_2 ) ? 1 : 0 ;
} else {
return F_10 ( V_27 , V_2 ) ;
}
}
static int F_12 ( struct V_20 * V_27 , unsigned V_2 )
{
if ( ! F_7 ( V_27 , V_2 ) )
return - V_29 ;
if ( V_11 . V_14 -> V_30 [ V_2 / 32 ] & ( 1 << ( V_2 & 0x1f ) ) )
return 0 ;
return F_6 ( V_31 , V_2 ) ? 0 : - V_32 ;
}
static int F_13 ( struct V_20 * V_27 , unsigned V_2 )
{
if ( V_2 == 16 || V_2 == 17 )
V_2 -= 16 ;
return F_12 ( V_27 , V_2 ) ;
}
static void F_14 ( struct V_20 * V_27 , unsigned V_2 , int V_3 )
{
F_1 ( V_13 , V_2 , V_3 , 0 ) ;
}
static void F_15 ( struct V_20 * V_27 )
{
V_27 -> V_33 = V_34 ;
V_27 -> V_35 = V_36 ;
V_27 -> V_37 = & V_11 . V_37 -> V_37 ;
V_27 -> V_38 = V_11 . V_14 -> V_38 ?
V_11 . V_14 -> V_38 : F_12 ;
V_27 -> V_39 = V_11 . V_14 -> V_39 ?
V_11 . V_14 -> V_39 : F_10 ;
V_27 -> V_40 = F_14 ;
V_27 -> V_41 = F_8 ;
V_27 -> V_42 = F_9 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_11 . V_14 -> V_45 ;
V_27 -> V_46 = false ;
V_27 -> V_47 = NULL ;
}
static int F_16 ( struct V_48 * V_49 ,
const char * V_50 , T_2 V_22 )
{
int V_51 ;
if ( ! V_49 || ! V_49 -> V_52 || ! V_49 -> V_53 )
return - V_32 ;
for ( V_51 = 0 ; V_51 < F_17 ( V_11 . V_14 -> V_17 [ 0 ] ) ; V_51 ++ ) {
if ( ! ( V_22 & ( 1 << V_51 ) ) )
continue;
if ( ! F_18 (
V_49 -> V_52 + V_11 . V_14 -> V_17 [ 0 ] [ V_51 ] ,
V_11 . V_14 -> V_54 [ V_51 ] , V_50 ) )
goto V_55;
}
return 0 ;
V_55:
for ( V_51 -- ; V_51 >= 0 ; V_51 -- ) {
if ( ! ( V_22 & ( 1 << V_51 ) ) )
continue;
F_19 ( V_49 -> V_52 + V_11 . V_14 -> V_17 [ 0 ] [ V_51 ] ,
V_11 . V_14 -> V_54 [ V_51 ] ) ;
}
return - V_56 ;
}
static void F_20 ( struct V_48 * V_49 , T_2 V_22 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_17 ( V_11 . V_14 -> V_17 [ 0 ] ) ; V_51 ++ ) {
if ( ! ( V_22 & ( 1 << V_51 ) ) )
continue;
F_19 ( V_49 -> V_52 + V_11 . V_14 -> V_17 [ 0 ] [ V_51 ] ,
V_11 . V_14 -> V_54 [ V_51 ] ) ;
}
}
static int F_21 ( struct V_57 * V_58 )
{
struct V_48 * V_49 , * V_59 ;
int V_60 ;
struct V_61 * V_62 = F_22 ( & V_58 -> V_37 ) ;
if ( ! V_62 )
return - V_32 ;
V_11 . V_37 = V_58 ;
switch ( V_62 -> V_63 ) {
case V_64 :
V_11 . V_14 = & V_65 ;
break;
case V_66 :
V_11 . V_14 = & V_67 ;
break;
case V_68 :
V_11 . V_14 = & V_69 ;
break;
case V_70 :
V_11 . V_14 = & V_71 ;
break;
case V_72 :
V_11 . V_14 = & V_73 ;
break;
case V_74 :
V_11 . V_14 = & V_75 ;
break;
case V_76 :
V_11 . V_14 = & V_77 ;
break;
case V_78 :
V_11 . V_14 = & V_79 ;
break;
default:
return - V_32 ;
}
F_23 ( & V_11 . V_12 ) ;
V_49 = F_24 ( V_58 , V_80 , V_81 ) ;
V_11 . V_22 = V_62 -> V_22 ;
V_60 = F_16 ( V_49 , V_58 -> V_50 ,
V_11 . V_22 ) ;
if ( V_60 )
return V_60 ;
V_11 . V_18 = V_49 ;
if ( ! V_11 . V_14 -> V_82 )
goto V_83;
V_59 = F_24 ( V_58 , V_80 , V_84 ) ;
if ( ! V_59 ) {
F_25 ( L_1 ) ;
goto V_83;
}
if ( ! F_18 ( V_59 -> V_52 , F_26 ( V_59 ) ,
V_58 -> V_50 ) ) {
F_25 ( L_2 ) ;
goto V_83;
}
V_11 . V_28 = V_59 ;
V_83:
F_15 ( & V_11 . V_27 ) ;
V_60 = F_27 ( & V_11 . V_27 ) ;
if ( V_60 ) {
F_28 ( L_3 ) ;
goto V_85;
}
F_29 ( L_4 , V_11 . V_27 . V_43 ,
V_11 . V_27 . V_43 + V_11 . V_27 . V_45 - 1 , V_36 ) ;
return 0 ;
V_85:
F_20 ( V_11 . V_18 , V_11 . V_22 ) ;
if ( V_11 . V_28 )
F_19 ( V_11 . V_28 -> V_52 ,
F_26 ( V_11 . V_28 ) ) ;
return V_60 ;
}
static int F_30 ( struct V_57 * V_58 )
{
int V_60 ;
V_60 = F_31 ( & V_11 . V_27 ) ;
if ( V_60 ) {
F_32 ( & V_58 -> V_37 , L_5 ,
L_6 , V_60 ) ;
return V_60 ;
}
F_20 ( V_11 . V_18 , V_11 . V_22 ) ;
if ( V_11 . V_28 )
F_19 ( V_11 . V_28 -> V_52 ,
F_26 ( V_11 . V_28 ) ) ;
return 0 ;
}
