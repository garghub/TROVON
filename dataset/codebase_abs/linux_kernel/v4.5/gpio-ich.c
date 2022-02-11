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
return F_6 ( V_23 , V_2 ) ? V_24 : V_25 ;
}
static int F_9 ( struct V_20 * V_21 , unsigned V_2 )
{
if ( F_1 ( V_23 , V_2 , 1 , 1 ) )
return - V_26 ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 , unsigned V_2 ,
int V_3 )
{
if ( V_2 < 32 && V_11 . V_14 -> V_27 )
F_1 ( V_28 , V_2 , 0 , 0 ) ;
F_1 ( V_13 , V_2 , V_3 , 0 ) ;
if ( F_1 ( V_23 , V_2 , 0 , 1 ) )
return - V_26 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_29 , unsigned V_2 )
{
return F_6 ( V_13 , V_2 ) ;
}
static int F_12 ( struct V_20 * V_29 , unsigned V_2 )
{
unsigned long V_5 ;
T_1 V_6 ;
if ( V_2 < 16 ) {
if ( ! V_11 . V_30 )
return - V_31 ;
F_2 ( & V_11 . V_12 , V_5 ) ;
F_4 ( 1 << ( 16 + V_2 ) , 0 , V_11 . V_30 ) ;
V_6 = F_3 ( 0 , V_11 . V_30 ) ;
F_5 ( & V_11 . V_12 , V_5 ) ;
return ( V_6 >> 16 ) & ( 1 << V_2 ) ? 1 : 0 ;
} else {
return F_11 ( V_29 , V_2 ) ;
}
}
static int F_13 ( struct V_20 * V_29 , unsigned V_2 )
{
if ( ! F_7 ( V_29 , V_2 ) )
return - V_31 ;
if ( V_11 . V_14 -> V_32 [ V_2 / 32 ] & ( 1 << ( V_2 & 0x1f ) ) )
return 0 ;
return F_6 ( V_33 , V_2 ) ? 0 : - V_34 ;
}
static int F_14 ( struct V_20 * V_29 , unsigned V_2 )
{
if ( V_2 == 16 || V_2 == 17 )
V_2 -= 16 ;
return F_13 ( V_29 , V_2 ) ;
}
static void F_15 ( struct V_20 * V_29 , unsigned V_2 , int V_3 )
{
F_1 ( V_13 , V_2 , V_3 , 0 ) ;
}
static void F_16 ( struct V_20 * V_29 )
{
V_29 -> V_35 = V_36 ;
V_29 -> V_37 = V_38 ;
V_29 -> V_39 = & V_11 . V_40 -> V_40 ;
V_29 -> V_41 = V_11 . V_14 -> V_41 ?
V_11 . V_14 -> V_41 : F_13 ;
V_29 -> V_42 = V_11 . V_14 -> V_42 ?
V_11 . V_14 -> V_42 : F_11 ;
V_29 -> V_43 = F_15 ;
V_29 -> V_44 = F_8 ;
V_29 -> V_45 = F_9 ;
V_29 -> V_46 = F_10 ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = V_11 . V_14 -> V_49 ;
V_29 -> V_50 = false ;
V_29 -> V_51 = NULL ;
}
static int F_17 ( struct V_52 * V_53 ,
const char * V_54 , T_2 V_22 )
{
int V_55 ;
if ( ! V_53 || ! V_53 -> V_56 || ! V_53 -> V_57 )
return - V_34 ;
for ( V_55 = 0 ; V_55 < F_18 ( V_11 . V_14 -> V_17 [ 0 ] ) ; V_55 ++ ) {
if ( ! ( V_22 & ( 1 << V_55 ) ) )
continue;
if ( ! F_19 (
V_53 -> V_56 + V_11 . V_14 -> V_17 [ 0 ] [ V_55 ] ,
V_11 . V_14 -> V_58 [ V_55 ] , V_54 ) )
goto V_59;
}
return 0 ;
V_59:
for ( V_55 -- ; V_55 >= 0 ; V_55 -- ) {
if ( ! ( V_22 & ( 1 << V_55 ) ) )
continue;
F_20 ( V_53 -> V_56 + V_11 . V_14 -> V_17 [ 0 ] [ V_55 ] ,
V_11 . V_14 -> V_58 [ V_55 ] ) ;
}
return - V_60 ;
}
static void F_21 ( struct V_52 * V_53 , T_2 V_22 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_18 ( V_11 . V_14 -> V_17 [ 0 ] ) ; V_55 ++ ) {
if ( ! ( V_22 & ( 1 << V_55 ) ) )
continue;
F_20 ( V_53 -> V_56 + V_11 . V_14 -> V_17 [ 0 ] [ V_55 ] ,
V_11 . V_14 -> V_58 [ V_55 ] ) ;
}
}
static int F_22 ( struct V_61 * V_62 )
{
struct V_52 * V_53 , * V_63 ;
int V_64 ;
struct V_65 * V_66 = F_23 ( & V_62 -> V_40 ) ;
if ( ! V_66 )
return - V_34 ;
V_11 . V_40 = V_62 ;
switch ( V_66 -> V_67 ) {
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
case V_80 :
V_11 . V_14 = & V_81 ;
break;
case V_82 :
V_11 . V_14 = & V_83 ;
break;
default:
return - V_34 ;
}
F_24 ( & V_11 . V_12 ) ;
V_53 = F_25 ( V_62 , V_84 , V_85 ) ;
V_11 . V_22 = V_66 -> V_22 ;
V_64 = F_17 ( V_53 , V_62 -> V_54 ,
V_11 . V_22 ) ;
if ( V_64 )
return V_64 ;
V_11 . V_18 = V_53 ;
if ( ! V_11 . V_14 -> V_86 )
goto V_87;
V_63 = F_25 ( V_62 , V_84 , V_88 ) ;
if ( ! V_63 ) {
F_26 ( L_1 ) ;
goto V_87;
}
if ( ! F_19 ( V_63 -> V_56 , F_27 ( V_63 ) ,
V_62 -> V_54 ) ) {
F_26 ( L_2 ) ;
goto V_87;
}
V_11 . V_30 = V_63 ;
V_87:
F_16 ( & V_11 . V_29 ) ;
V_64 = F_28 ( & V_11 . V_29 , NULL ) ;
if ( V_64 ) {
F_29 ( L_3 ) ;
goto V_89;
}
F_30 ( L_4 , V_11 . V_29 . V_47 ,
V_11 . V_29 . V_47 + V_11 . V_29 . V_49 - 1 , V_38 ) ;
return 0 ;
V_89:
F_21 ( V_11 . V_18 , V_11 . V_22 ) ;
if ( V_11 . V_30 )
F_20 ( V_11 . V_30 -> V_56 ,
F_27 ( V_11 . V_30 ) ) ;
return V_64 ;
}
static int F_31 ( struct V_61 * V_62 )
{
F_32 ( & V_11 . V_29 ) ;
F_21 ( V_11 . V_18 , V_11 . V_22 ) ;
if ( V_11 . V_30 )
F_20 ( V_11 . V_30 -> V_56 ,
F_27 ( V_11 . V_30 ) ) ;
return 0 ;
}
