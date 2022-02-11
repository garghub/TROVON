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
static bool F_7 ( struct V_16 * V_17 , unsigned V_2 )
{
return V_11 . V_18 & ( 1 << ( V_2 / 32 ) ) ;
}
static int F_8 ( struct V_16 * V_17 , unsigned V_2 )
{
if ( ! F_7 ( V_17 , V_2 ) )
return - V_19 ;
if ( F_1 ( V_20 , V_2 , 1 , 1 ) )
return - V_21 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 , unsigned V_2 ,
int V_3 )
{
if ( ! F_7 ( V_17 , V_2 ) )
return - V_19 ;
F_1 ( V_22 , V_2 , V_3 , 0 ) ;
if ( F_1 ( V_20 , V_2 , 0 , 1 ) )
return - V_21 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_23 , unsigned V_2 )
{
if ( ! F_7 ( V_23 , V_2 ) )
return - V_19 ;
return F_6 ( V_22 , V_2 ) ;
}
static int F_11 ( struct V_16 * V_23 , unsigned V_2 )
{
unsigned long V_5 ;
T_1 V_6 ;
if ( ! F_7 ( V_23 , V_2 ) )
return - V_19 ;
if ( V_2 < 16 ) {
if ( ! V_11 . V_24 )
return - V_19 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
F_4 ( 1 << ( 16 + V_2 ) , 0 , V_11 . V_24 ) ;
V_6 = F_3 ( 0 , V_11 . V_24 ) ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return ( V_6 >> 16 ) & ( 1 << V_2 ) ? 1 : 0 ;
} else {
return F_10 ( V_23 , V_2 ) ;
}
}
static int F_12 ( struct V_16 * V_23 , unsigned V_2 )
{
if ( V_11 . V_25 -> V_26 [ V_2 / 32 ] & ( 1 << ( V_2 & 0x1f ) ) )
return 0 ;
return F_6 ( V_27 , V_2 ) ? 0 : - V_28 ;
}
static int F_13 ( struct V_16 * V_23 , unsigned V_2 )
{
if ( V_2 == 16 || V_2 == 17 )
V_2 -= 16 ;
return F_12 ( V_23 , V_2 ) ;
}
static void F_14 ( struct V_16 * V_23 , unsigned V_2 , int V_3 )
{
F_1 ( V_22 , V_2 , V_3 , 0 ) ;
}
static void F_15 ( struct V_16 * V_23 )
{
V_23 -> V_29 = V_30 ;
V_23 -> V_31 = V_32 ;
V_23 -> V_33 = & V_11 . V_33 -> V_33 ;
V_23 -> V_34 = V_11 . V_25 -> V_34 ?
V_11 . V_25 -> V_34 : F_12 ;
V_23 -> V_35 = V_11 . V_25 -> V_35 ?
V_11 . V_25 -> V_35 : F_10 ;
V_23 -> V_36 = F_14 ;
V_23 -> V_37 = F_8 ;
V_23 -> V_38 = F_9 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_11 . V_25 -> V_41 ;
V_23 -> V_42 = 0 ;
V_23 -> V_43 = NULL ;
}
static int F_16 ( struct V_44 * V_45 ,
const char * V_46 , T_2 V_18 )
{
int V_47 ;
if ( ! V_45 || ! V_45 -> V_48 || ! V_45 -> V_49 )
return - V_28 ;
for ( V_47 = 0 ; V_47 < F_17 ( V_13 [ 0 ] ) ; V_47 ++ ) {
if ( ! ( V_18 & ( 1 << V_47 ) ) )
continue;
if ( ! F_18 ( V_45 -> V_48 + V_13 [ 0 ] [ V_47 ] ,
V_50 [ V_47 ] , V_46 ) )
goto V_51;
}
return 0 ;
V_51:
for ( V_47 -- ; V_47 >= 0 ; V_47 -- ) {
if ( ! ( V_18 & ( 1 << V_47 ) ) )
continue;
F_19 ( V_45 -> V_48 + V_13 [ 0 ] [ V_47 ] ,
V_50 [ V_47 ] ) ;
}
return - V_52 ;
}
static void F_20 ( struct V_44 * V_45 , T_2 V_18 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_17 ( V_13 [ 0 ] ) ; V_47 ++ ) {
if ( ! ( V_18 & ( 1 << V_47 ) ) )
continue;
F_19 ( V_45 -> V_48 + V_13 [ 0 ] [ V_47 ] ,
V_50 [ V_47 ] ) ;
}
}
static int F_21 ( struct V_53 * V_54 )
{
struct V_44 * V_45 , * V_55 ;
int V_56 ;
struct V_57 * V_58 = V_54 -> V_33 . V_59 ;
if ( ! V_58 )
return - V_28 ;
V_11 . V_33 = V_54 ;
switch ( V_58 -> V_60 ) {
case V_61 :
V_11 . V_25 = & V_62 ;
break;
case V_63 :
V_11 . V_25 = & V_64 ;
break;
case V_65 :
V_11 . V_25 = & V_66 ;
break;
case V_67 :
V_11 . V_25 = & V_68 ;
break;
case V_69 :
V_11 . V_25 = & V_70 ;
break;
case V_71 :
V_11 . V_25 = & V_72 ;
break;
case V_73 :
V_11 . V_25 = & V_74 ;
break;
default:
return - V_28 ;
}
F_22 ( & V_11 . V_12 ) ;
V_45 = F_23 ( V_54 , V_75 , V_76 ) ;
V_11 . V_18 = V_58 -> V_18 ;
V_56 = F_16 ( V_45 , V_54 -> V_46 ,
V_11 . V_18 ) ;
if ( V_56 )
return V_56 ;
V_11 . V_14 = V_45 ;
if ( ! V_11 . V_25 -> V_77 )
goto V_78;
V_55 = F_23 ( V_54 , V_75 , V_79 ) ;
if ( ! V_55 ) {
F_24 ( L_1 ) ;
goto V_78;
}
if ( ! F_18 ( V_55 -> V_48 , F_25 ( V_55 ) ,
V_54 -> V_46 ) ) {
F_24 ( L_2 ) ;
goto V_78;
}
V_11 . V_24 = V_55 ;
V_78:
F_15 ( & V_11 . V_23 ) ;
V_56 = F_26 ( & V_11 . V_23 ) ;
if ( V_56 ) {
F_27 ( L_3 ) ;
goto V_80;
}
F_28 ( L_4 , V_11 . V_23 . V_39 ,
V_11 . V_23 . V_39 + V_11 . V_23 . V_41 - 1 , V_32 ) ;
return 0 ;
V_80:
F_20 ( V_11 . V_14 , V_11 . V_18 ) ;
if ( V_11 . V_24 )
F_19 ( V_11 . V_24 -> V_48 ,
F_25 ( V_11 . V_24 ) ) ;
return V_56 ;
}
static int F_29 ( struct V_53 * V_54 )
{
int V_56 ;
V_56 = F_30 ( & V_11 . V_23 ) ;
if ( V_56 ) {
F_31 ( & V_54 -> V_33 , L_5 ,
L_6 , V_56 ) ;
return V_56 ;
}
F_20 ( V_11 . V_14 , V_11 . V_18 ) ;
if ( V_11 . V_24 )
F_19 ( V_11 . V_24 -> V_48 ,
F_25 ( V_11 . V_24 ) ) ;
return 0 ;
}
