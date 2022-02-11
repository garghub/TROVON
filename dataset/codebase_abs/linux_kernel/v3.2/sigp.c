static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
int V_10 ;
if ( V_3 >= V_11 )
return 3 ;
F_2 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_13 [ V_3 ] == NULL )
V_10 = 3 ;
else if ( ! ( F_3 ( V_6 -> V_13 [ V_3 ] -> V_14 )
& V_15 ) ) {
* V_4 &= 0xffffffff00000000UL ;
V_10 = 1 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_16 ;
V_10 = 1 ;
}
F_4 ( & V_6 -> V_12 ) ;
F_5 ( V_2 , 4 , L_1 , V_3 , V_10 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_10 ;
if ( V_3 >= V_11 )
return 3 ;
V_20 = F_7 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> type = V_23 ;
V_20 -> V_24 . V_25 = V_2 -> V_26 ;
F_2 ( & V_6 -> V_12 ) ;
V_18 = V_6 -> V_13 [ V_3 ] ;
if ( V_18 == NULL ) {
V_10 = 3 ;
F_8 ( V_20 ) ;
goto V_27;
}
F_9 ( & V_18 -> V_12 ) ;
F_10 ( & V_20 -> V_28 , & V_18 -> V_28 ) ;
F_11 ( & V_18 -> V_29 , 1 ) ;
F_12 ( V_30 , V_18 -> V_14 ) ;
if ( F_13 ( & V_18 -> V_31 ) )
F_14 ( & V_18 -> V_31 ) ;
F_15 ( & V_18 -> V_12 ) ;
V_10 = 0 ;
F_5 ( V_2 , 4 , L_2 , V_3 ) ;
V_27:
F_4 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_10 ;
if ( V_3 >= V_11 )
return 3 ;
V_20 = F_7 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> type = V_32 ;
V_20 -> V_33 . V_25 = V_2 -> V_26 ;
F_2 ( & V_6 -> V_12 ) ;
V_18 = V_6 -> V_13 [ V_3 ] ;
if ( V_18 == NULL ) {
V_10 = 3 ;
F_8 ( V_20 ) ;
goto V_27;
}
F_9 ( & V_18 -> V_12 ) ;
F_10 ( & V_20 -> V_28 , & V_18 -> V_28 ) ;
F_11 ( & V_18 -> V_29 , 1 ) ;
F_12 ( V_30 , V_18 -> V_14 ) ;
if ( F_13 ( & V_18 -> V_31 ) )
F_14 ( & V_18 -> V_31 ) ;
F_15 ( & V_18 -> V_12 ) ;
V_10 = 0 ;
F_5 ( V_2 , 4 , L_3 , V_3 ) ;
V_27:
F_4 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_17 ( struct V_17 * V_18 , int V_34 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( sizeof( * V_20 ) , V_35 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> type = V_36 ;
F_9 ( & V_18 -> V_12 ) ;
F_10 ( & V_20 -> V_28 , & V_18 -> V_28 ) ;
F_11 ( & V_18 -> V_29 , 1 ) ;
F_12 ( V_37 , V_18 -> V_14 ) ;
V_18 -> V_38 |= V_34 ;
if ( F_13 ( & V_18 -> V_31 ) )
F_14 ( & V_18 -> V_31 ) ;
F_15 ( & V_18 -> V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 , int V_34 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_17 * V_18 ;
int V_10 ;
if ( V_3 >= V_11 )
return 3 ;
F_2 ( & V_6 -> V_12 ) ;
V_18 = V_6 -> V_13 [ V_3 ] ;
if ( V_18 == NULL ) {
V_10 = 3 ;
goto V_27;
}
V_10 = F_17 ( V_18 , V_34 ) ;
V_27:
F_4 ( & V_6 -> V_12 ) ;
F_5 ( V_2 , 4 , L_4 , V_3 ) ;
return V_10 ;
}
int F_19 ( struct V_1 * V_2 , int V_34 )
{
struct V_17 * V_18 = & V_2 -> V_8 . V_13 ;
return F_17 ( V_18 , V_34 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_39 )
{
int V_10 ;
switch ( V_39 & 0xff ) {
case 0 :
V_10 = 3 ;
break;
case 1 :
case 2 :
V_10 = 0 ;
break;
default:
V_10 = - V_40 ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_41 ,
unsigned long * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 ;
int V_10 ;
T_3 V_42 ;
V_41 = V_41 & 0x7fffe000u ;
if ( F_22 ( V_2 , & V_42 , V_41 , 1 ) ||
F_22 ( V_2 , & V_42 , V_41 + V_43 , 1 ) ) {
* V_4 |= V_44 ;
return 1 ;
}
V_20 = F_7 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return 2 ;
F_2 ( & V_6 -> V_12 ) ;
if ( V_3 < V_11 )
V_18 = V_6 -> V_13 [ V_3 ] ;
if ( V_18 == NULL ) {
V_10 = 1 ;
* V_4 &= V_45 ;
F_8 ( V_20 ) ;
goto V_46;
}
F_9 ( & V_18 -> V_12 ) ;
if ( ! ( F_3 ( V_18 -> V_14 ) & V_15 ) ) {
V_10 = 1 ;
* V_4 &= V_45 ;
F_8 ( V_20 ) ;
goto V_47;
}
V_20 -> type = V_48 ;
V_20 -> V_49 . V_41 = V_41 ;
F_10 ( & V_20 -> V_28 , & V_18 -> V_28 ) ;
F_11 ( & V_18 -> V_29 , 1 ) ;
if ( F_13 ( & V_18 -> V_31 ) )
F_14 ( & V_18 -> V_31 ) ;
V_10 = 0 ;
F_5 ( V_2 , 4 , L_5 , V_3 , V_41 ) ;
V_47:
F_15 ( & V_18 -> V_12 ) ;
V_46:
F_4 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long * V_4 )
{
int V_10 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
if ( V_3 >= V_11 )
return 3 ;
F_2 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_13 [ V_3 ] == NULL )
V_10 = 3 ;
else {
if ( F_3 ( V_6 -> V_13 [ V_3 ] -> V_14 )
& V_50 ) {
V_10 = 1 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_51 ;
V_10 = 0 ;
}
}
F_4 ( & V_6 -> V_12 ) ;
F_5 ( V_2 , 4 , L_6 , V_3 ,
V_10 ) ;
return V_10 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_52 = ( V_2 -> V_8 . V_53 -> V_54 & 0x00f0 ) >> 4 ;
int V_55 = V_2 -> V_8 . V_53 -> V_54 & 0x000f ;
int V_56 = V_2 -> V_8 . V_53 -> V_57 >> 28 ;
int V_58 = ( ( V_2 -> V_8 . V_53 -> V_57 & 0x0fff0000 ) >> 16 ) ;
T_2 V_39 ;
T_1 V_3 = V_2 -> V_8 . V_59 [ V_55 ] ;
T_3 V_60 ;
int V_10 ;
if ( V_2 -> V_8 . V_53 -> V_61 . V_62 & V_63 )
return F_25 ( V_2 ,
V_64 ) ;
V_60 = V_58 ;
if ( V_56 )
V_60 += V_2 -> V_8 . V_59 [ V_56 ] ;
if ( V_52 % 2 )
V_39 = V_2 -> V_8 . V_59 [ V_52 ] ;
else
V_39 = V_2 -> V_8 . V_59 [ V_52 + 1 ] ;
switch ( V_60 ) {
case V_65 :
V_2 -> V_66 . V_67 ++ ;
V_10 = F_1 ( V_2 , V_3 ,
& V_2 -> V_8 . V_59 [ V_52 ] ) ;
break;
case V_68 :
V_2 -> V_66 . V_69 ++ ;
V_10 = F_16 ( V_2 , V_3 ) ;
break;
case V_70 :
V_2 -> V_66 . V_71 ++ ;
V_10 = F_6 ( V_2 , V_3 ) ;
break;
case V_72 :
V_2 -> V_66 . V_73 ++ ;
V_10 = F_18 ( V_2 , V_3 , V_74 ) ;
break;
case V_75 :
V_2 -> V_66 . V_73 ++ ;
V_10 = F_18 ( V_2 , V_3 , V_76 ) ;
break;
case V_77 :
V_2 -> V_66 . V_78 ++ ;
V_10 = F_20 ( V_2 , V_39 ) ;
break;
case V_79 :
V_2 -> V_66 . V_80 ++ ;
V_10 = F_21 ( V_2 , V_3 , V_39 ,
& V_2 -> V_8 . V_59 [ V_52 ] ) ;
break;
case V_81 :
V_2 -> V_66 . V_82 ++ ;
V_10 = F_23 ( V_2 , V_3 ,
& V_2 -> V_8 . V_59 [ V_52 ] ) ;
break;
case V_83 :
V_2 -> V_66 . V_84 ++ ;
default:
return - V_40 ;
}
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_8 . V_53 -> V_61 . V_62 &= ~ ( 3ul << 44 ) ;
V_2 -> V_8 . V_53 -> V_61 . V_62 |= ( V_10 & 3ul ) << 44 ;
return 0 ;
}
