static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
switch ( V_3 ) {
case V_7 :
V_6 = F_2 ( V_5 , V_8 ) ;
break;
case V_9 :
V_6 = F_2 ( V_5 , V_10 ) ;
break;
case V_11 :
V_6 = F_2 ( V_5 , V_12 ) ;
break;
case V_13 :
V_6 = F_2 ( V_5 , V_14 ) ;
break;
default:
return 0 ;
}
if ( V_6 >= 0 )
V_6 = ( V_6 & V_15 )
>> V_16 ;
V_2 -> V_17 [ V_3 ] = V_6 ;
return V_6 ;
}
static unsigned long F_3 ( T_1 V_18 )
{
unsigned long V_19 ;
V_19 = ( ( V_18 * 12500 ) + 500000 ) ;
return V_19 ;
}
static unsigned long F_4 ( T_1 V_18 )
{
unsigned long V_19 ;
V_19 = ( ( V_18 * 12500 ) + 700000 ) ;
return V_19 ;
}
static unsigned long F_5 ( T_1 V_18 )
{
unsigned long V_19 ;
V_19 = ( ( V_18 * 25000 ) + 500000 ) ;
return V_19 ;
}
static unsigned long F_6 ( T_1 V_18 )
{
unsigned long V_19 ;
if ( V_18 == 0x3f )
V_19 = 3800000 ;
else
V_19 = ( ( V_18 * 50000 ) + 500000 ) ;
return V_19 ;
}
static int F_7 ( int V_3 )
{
if ( V_3 >= V_7 && V_3 <= V_20 )
return V_3 * 3 + V_21 ;
else if ( V_3 >= V_22 && V_3 <= V_23 )
return V_3 - V_22 + V_24 ;
else
return - V_25 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_26 ;
T_1 V_27 = 0 ;
if ( V_3 >= V_7 && V_3 <= V_20 ) {
V_26 = F_2 ( V_5 , V_3 * 3 + V_28 ) ;
if ( V_26 & V_29 )
V_27 = V_3 * 3 + V_21 ;
else
V_27 = V_3 * 3 + V_28 ;
} else if ( V_3 >= V_22 && V_3 <= V_23 ) {
V_27 = V_3 - V_22 + V_24 ;
} else {
return - V_25 ;
}
return V_27 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_7 :
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_21 ;
break;
case V_9 :
V_2 -> V_30 = V_33 ;
V_2 -> V_32 = V_34 ;
break;
case V_11 :
V_2 -> V_30 = V_35 ;
V_2 -> V_32 = V_36 ;
break;
case V_13 :
V_2 -> V_30 = V_37 ;
V_2 -> V_32 = V_38 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_10 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_27 , V_41 , V_3 = F_12 ( V_40 ) ;
if ( V_3 < V_7 || V_3 > V_23 )
return - V_25 ;
V_27 = V_2 -> V_42 ( V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
V_41 = F_2 ( V_5 , V_27 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_41 & V_43 ;
}
static int F_13 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_12 ( V_40 ) ;
int V_27 ;
if ( V_3 < V_7 || V_3 > V_23 )
return - V_25 ;
V_27 = V_2 -> V_42 ( V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_14 ( V_5 , V_27 , V_43 ) ;
}
static int F_15 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_12 ( V_40 ) , V_27 ;
V_27 = V_2 -> V_42 ( V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_16 ( V_5 , V_27 , V_43 ) ;
}
static int F_17 ( struct V_39 * V_40 , unsigned int V_44 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_45 , V_46 , V_3 = F_12 ( V_40 ) ;
F_9 ( V_2 , V_3 ) ;
V_45 = F_2 ( V_5 , V_2 -> V_30 ) ;
V_46 = F_2 ( V_5 , V_2 -> V_32 ) ;
V_45 &= V_47 ;
V_46 &= V_48 ;
switch ( V_44 ) {
case V_49 :
if ( V_45 && ! V_46 )
break;
F_14 ( V_5 , V_2 -> V_30 , V_47 ) ;
F_16 ( V_5 , V_2 -> V_32 , V_48 ) ;
break;
case V_50 :
case V_51 :
if ( ! V_45 && ! V_46 )
break;
F_16 ( V_5 , V_2 -> V_30 , V_47 ) ;
F_16 ( V_5 , V_2 -> V_32 , V_48 ) ;
break;
case V_52 :
if ( ! V_45 && V_46 )
break;
F_16 ( V_5 , V_2 -> V_30 , V_47 ) ;
F_14 ( V_5 , V_2 -> V_32 , V_48 ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static unsigned int F_18 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_45 , V_46 , V_44 = 0 , V_3 = F_12 ( V_40 ) ;
F_9 ( V_2 , V_3 ) ;
V_45 = F_2 ( V_5 , V_2 -> V_30 ) ;
V_46 = F_2 ( V_5 , V_2 -> V_32 ) ;
V_45 &= V_47 ;
V_46 &= V_48 ;
if ( V_45 && ! V_46 )
V_44 = V_49 ;
else if ( ! V_45 && ! V_46 )
V_44 = V_50 ;
else if ( ! V_45 && V_46 )
V_44 = V_52 ;
return V_44 ;
}
static int F_19 ( struct V_39 * V_40 , unsigned V_53 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
int V_6 , V_54 = 0 , V_3 = F_12 ( V_40 ) ;
if ( V_3 > V_13 )
return - V_25 ;
V_6 = V_2 -> V_17 [ V_3 ] ;
switch ( V_6 ) {
case 0 :
V_54 = F_3 ( V_53 ) ;
break;
case 1 :
V_54 = F_4 ( V_53 ) ;
break;
case 2 :
V_54 = F_5 ( V_53 ) ;
break;
case 3 :
V_54 = F_6 ( V_53 ) ;
break;
}
return V_54 ;
}
static int F_20 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_12 ( V_40 ) ;
int V_27 , V_18 ;
V_27 = F_8 ( V_2 , V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
V_18 = F_2 ( V_5 , V_27 ) ;
V_18 &= 0x3F ;
return V_18 ;
}
static int F_21 ( struct V_39 * V_40 ,
unsigned V_53 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_12 ( V_40 ) ;
int V_41 ;
T_1 V_27 ;
V_27 = F_8 ( V_2 , V_3 ) ;
V_41 = F_2 ( V_5 , V_27 ) ;
V_41 &= 0xC0 ;
return F_22 ( V_5 , V_27 , V_53 | V_41 ) ;
}
static int F_23 ( struct V_55 * V_56 )
{
struct V_4 * V_4 = F_24 ( V_56 -> V_40 . V_57 ) ;
struct V_58 V_59 = { } ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_39 * V_64 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
int V_67 ;
V_66 = F_25 ( V_4 -> V_40 ) ;
if ( ! V_66 )
return - V_25 ;
V_63 = V_66 -> V_68 ;
V_2 = F_26 ( & V_56 -> V_40 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
F_27 ( & V_2 -> V_71 ) ;
V_2 -> V_5 = V_4 ;
F_28 ( V_56 , V_2 ) ;
V_2 -> V_42 = & F_7 ;
V_61 = V_72 ;
for ( V_67 = 0 ; V_67 < V_73 ; V_67 ++ , V_61 ++ , V_63 ++ ) {
int V_6 = 0 ;
V_2 -> V_61 [ V_67 ] = V_61 ;
V_2 -> V_74 [ V_67 ] . V_75 = V_61 -> V_75 ;
V_2 -> V_74 [ V_67 ] . V_3 = V_67 ;
V_2 -> V_74 [ V_67 ] . V_76 = 64 ;
if ( V_67 > V_13 ) {
V_2 -> V_74 [ V_67 ] . V_77 = & V_78 ;
V_2 -> V_74 [ V_67 ] . V_79 = V_80 ;
V_2 -> V_74 [ V_67 ] . V_81 =
F_29 ( V_80 ) ;
} else {
V_2 -> V_74 [ V_67 ] . V_77 = & V_82 ;
}
V_2 -> V_74 [ V_67 ] . type = V_83 ;
V_2 -> V_74 [ V_67 ] . V_84 = V_85 ;
V_6 = F_1 ( V_2 , V_67 ) ;
V_59 . V_40 = V_4 -> V_40 ;
V_59 . V_86 = V_63 ;
V_59 . V_87 = V_2 ;
V_64 = F_30 ( & V_56 -> V_40 , & V_2 -> V_74 [ V_67 ] ,
& V_59 ) ;
if ( F_31 ( V_64 ) ) {
F_32 ( V_4 -> V_40 ,
L_1 ,
V_56 -> V_75 ) ;
return F_33 ( V_64 ) ;
}
V_2 -> V_64 [ V_67 ] = V_64 ;
}
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_88 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_88 ) ;
}
