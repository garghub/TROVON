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
else if ( F_3 ( V_6 -> V_13 [ V_3 ] -> V_14 )
& V_15 ) {
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
F_2 ( & V_6 -> V_12 ) ;
V_18 = V_6 -> V_13 [ V_3 ] ;
if ( V_18 == NULL ) {
V_10 = 3 ;
F_8 ( V_20 ) ;
goto V_24;
}
F_9 ( & V_18 -> V_12 ) ;
F_10 ( & V_20 -> V_25 , & V_18 -> V_25 ) ;
F_11 ( & V_18 -> V_26 , 1 ) ;
F_12 ( V_27 , V_18 -> V_14 ) ;
if ( F_13 ( & V_18 -> V_28 ) )
F_14 ( & V_18 -> V_28 ) ;
F_15 ( & V_18 -> V_12 ) ;
V_10 = 0 ;
V_24:
F_4 ( & V_6 -> V_12 ) ;
F_5 ( V_2 , 4 , L_2 , V_3 ) ;
return V_10 ;
}
static int F_16 ( struct V_17 * V_18 , int V_29 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> type = V_31 ;
F_9 ( & V_18 -> V_12 ) ;
F_10 ( & V_20 -> V_25 , & V_18 -> V_25 ) ;
F_11 ( & V_18 -> V_26 , 1 ) ;
F_12 ( V_32 , V_18 -> V_14 ) ;
V_18 -> V_33 |= V_29 ;
if ( F_13 ( & V_18 -> V_28 ) )
F_14 ( & V_18 -> V_28 ) ;
F_15 ( & V_18 -> V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , int V_29 )
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
goto V_24;
}
V_10 = F_16 ( V_18 , V_29 ) ;
V_24:
F_4 ( & V_6 -> V_12 ) ;
F_5 ( V_2 , 4 , L_3 , V_3 ) ;
return V_10 ;
}
int F_18 ( struct V_1 * V_2 , int V_29 )
{
struct V_17 * V_18 = & V_2 -> V_8 . V_13 ;
return F_16 ( V_18 , V_29 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_34 )
{
int V_10 ;
switch ( V_34 & 0xff ) {
case 0 :
V_10 = 3 ;
break;
case 1 :
case 2 :
V_10 = 0 ;
break;
default:
V_10 = - V_35 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_36 ,
unsigned long * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 ;
int V_10 ;
T_3 V_37 ;
V_36 = V_36 & 0x7fffe000u ;
if ( F_21 ( V_2 , & V_37 , V_36 , 1 ) ||
F_21 ( V_2 , & V_37 , V_36 + V_38 , 1 ) ) {
* V_4 |= V_39 ;
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
* V_4 &= V_40 ;
F_8 ( V_20 ) ;
goto V_41;
}
F_9 ( & V_18 -> V_12 ) ;
if ( F_3 ( V_18 -> V_14 ) & V_15 ) {
V_10 = 1 ;
* V_4 &= V_40 ;
F_8 ( V_20 ) ;
goto V_42;
}
V_20 -> type = V_43 ;
V_20 -> V_44 . V_36 = V_36 ;
F_10 ( & V_20 -> V_25 , & V_18 -> V_25 ) ;
F_11 ( & V_18 -> V_26 , 1 ) ;
if ( F_13 ( & V_18 -> V_28 ) )
F_14 ( & V_18 -> V_28 ) ;
V_10 = 0 ;
F_5 ( V_2 , 4 , L_4 , V_3 , V_36 ) ;
V_42:
F_15 ( & V_18 -> V_12 ) ;
V_41:
F_4 ( & V_6 -> V_12 ) ;
return V_10 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_45 = ( V_2 -> V_8 . V_46 -> V_47 & 0x00f0 ) >> 4 ;
int V_48 = V_2 -> V_8 . V_46 -> V_47 & 0x000f ;
int V_49 = V_2 -> V_8 . V_46 -> V_50 >> 28 ;
int V_51 = ( ( V_2 -> V_8 . V_46 -> V_50 & 0x0fff0000 ) >> 16 ) ;
T_2 V_34 ;
T_1 V_3 = V_2 -> V_8 . V_52 [ V_48 ] ;
T_3 V_53 ;
int V_10 ;
if ( V_2 -> V_8 . V_46 -> V_54 . V_55 & V_56 )
return F_23 ( V_2 ,
V_57 ) ;
V_53 = V_51 ;
if ( V_49 )
V_53 += V_2 -> V_8 . V_52 [ V_49 ] ;
if ( V_45 % 2 )
V_34 = V_2 -> V_8 . V_52 [ V_45 ] ;
else
V_34 = V_2 -> V_8 . V_52 [ V_45 + 1 ] ;
switch ( V_53 ) {
case V_58 :
V_2 -> V_59 . V_60 ++ ;
V_10 = F_1 ( V_2 , V_3 ,
& V_2 -> V_8 . V_52 [ V_45 ] ) ;
break;
case V_61 :
V_2 -> V_59 . V_62 ++ ;
V_10 = F_6 ( V_2 , V_3 ) ;
break;
case V_63 :
V_2 -> V_59 . V_64 ++ ;
V_10 = F_17 ( V_2 , V_3 , V_65 ) ;
break;
case V_66 :
V_2 -> V_59 . V_64 ++ ;
V_10 = F_17 ( V_2 , V_3 , V_67 ) ;
break;
case V_68 :
V_2 -> V_59 . V_69 ++ ;
V_10 = F_19 ( V_2 , V_34 ) ;
break;
case V_70 :
V_2 -> V_59 . V_71 ++ ;
V_10 = F_20 ( V_2 , V_3 , V_34 ,
& V_2 -> V_8 . V_52 [ V_45 ] ) ;
break;
case V_72 :
V_2 -> V_59 . V_73 ++ ;
default:
return - V_35 ;
}
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_8 . V_46 -> V_54 . V_55 &= ~ ( 3ul << 44 ) ;
V_2 -> V_8 . V_46 -> V_54 . V_55 |= ( V_10 & 3ul ) << 44 ;
return 0 ;
}
