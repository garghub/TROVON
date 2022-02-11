static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
int V_10 ;
if ( V_3 >= V_11 )
return V_12 ;
F_2 ( & V_6 -> V_13 ) ;
if ( V_6 -> V_14 [ V_3 ] == NULL )
V_10 = V_12 ;
else if ( ! ( F_3 ( V_6 -> V_14 [ V_3 ] -> V_15 )
& ( V_16 | V_17 ) ) )
V_10 = V_18 ;
else {
* V_4 &= 0xffffffff00000000UL ;
if ( F_3 ( V_6 -> V_14 [ V_3 ] -> V_15 )
& V_16 )
* V_4 |= V_19 ;
if ( F_3 ( V_6 -> V_14 [ V_3 ] -> V_15 )
& V_17 )
* V_4 |= V_20 ;
V_10 = V_21 ;
}
F_4 ( & V_6 -> V_13 ) ;
F_5 ( V_2 , 4 , L_1 , V_3 , V_10 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_10 ;
if ( V_3 >= V_11 )
return V_12 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> type = V_28 ;
V_25 -> V_29 . V_30 = V_2 -> V_31 ;
F_2 ( & V_6 -> V_13 ) ;
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
V_10 = V_12 ;
F_8 ( V_25 ) ;
goto V_32;
}
F_9 ( & V_23 -> V_13 ) ;
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
F_12 ( V_35 , V_23 -> V_15 ) ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
F_15 ( & V_23 -> V_13 ) ;
V_10 = V_18 ;
F_5 ( V_2 , 4 , L_2 , V_3 ) ;
V_32:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_10 ;
if ( V_3 >= V_11 )
return V_12 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> type = V_37 ;
V_25 -> V_38 . V_30 = V_2 -> V_31 ;
F_2 ( & V_6 -> V_13 ) ;
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
V_10 = V_12 ;
F_8 ( V_25 ) ;
goto V_32;
}
F_9 ( & V_23 -> V_13 ) ;
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
F_12 ( V_35 , V_23 -> V_15 ) ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
F_15 ( & V_23 -> V_13 ) ;
V_10 = V_18 ;
F_5 ( V_2 , 4 , L_3 , V_3 ) ;
V_32:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
static int F_17 ( struct V_22 * V_23 , int V_39 )
{
struct V_24 * V_25 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_40 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> type = V_41 ;
F_9 ( & V_23 -> V_13 ) ;
if ( ( F_3 ( V_23 -> V_15 ) & V_17 ) ) {
F_8 ( V_25 ) ;
goto V_42;
}
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
F_12 ( V_43 , V_23 -> V_15 ) ;
V_23 -> V_44 |= V_39 ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
V_42:
F_15 ( & V_23 -> V_13 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 , int V_39 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 ;
int V_10 ;
if ( V_3 >= V_11 )
return V_12 ;
F_2 ( & V_6 -> V_13 ) ;
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
V_10 = V_12 ;
goto V_32;
}
V_10 = F_17 ( V_23 , V_39 ) ;
V_32:
F_4 ( & V_6 -> V_13 ) ;
F_5 ( V_2 , 4 , L_4 , V_3 ) ;
return V_10 ;
}
int F_19 ( struct V_1 * V_2 , int V_39 )
{
struct V_22 * V_23 = & V_2 -> V_8 . V_14 ;
return F_17 ( V_23 , V_39 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_45 )
{
int V_10 ;
switch ( V_45 & 0xff ) {
case 0 :
V_10 = V_12 ;
break;
case 1 :
case 2 :
V_10 = V_18 ;
break;
default:
V_10 = - V_46 ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_47 ,
T_2 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 ;
int V_10 ;
T_4 V_48 ;
V_47 = V_47 & 0x7fffe000u ;
if ( F_22 ( V_2 , & V_48 , V_47 , 1 ) ||
F_22 ( V_2 , & V_48 , V_47 + V_49 , 1 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_50 ;
return V_21 ;
}
V_25 = F_7 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return V_51 ;
F_2 ( & V_6 -> V_13 ) ;
if ( V_3 < V_11 )
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
V_10 = V_21 ;
F_8 ( V_25 ) ;
goto V_53;
}
F_9 ( & V_23 -> V_13 ) ;
if ( ! ( F_3 ( V_23 -> V_15 ) & V_17 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
V_10 = V_21 ;
F_8 ( V_25 ) ;
goto V_54;
}
V_25 -> type = V_55 ;
V_25 -> V_56 . V_47 = V_47 ;
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
V_10 = V_18 ;
F_5 ( V_2 , 4 , L_5 , V_3 , V_47 ) ;
V_54:
F_15 ( & V_23 -> V_13 ) ;
V_53:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
int V_10 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
if ( V_3 >= V_11 )
return V_12 ;
F_2 ( & V_6 -> V_13 ) ;
if ( V_6 -> V_14 [ V_3 ] == NULL )
V_10 = V_12 ;
else {
if ( F_3 ( V_6 -> V_14 [ V_3 ] -> V_15 )
& V_57 ) {
V_10 = V_18 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_58 ;
V_10 = V_21 ;
}
}
F_4 ( & V_6 -> V_13 ) ;
F_5 ( V_2 , 4 , L_6 , V_3 ,
V_10 ) ;
return V_10 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 ;
int V_10 = V_18 ;
if ( V_3 >= V_11 )
return V_12 ;
F_2 ( & V_6 -> V_13 ) ;
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
V_10 = V_12 ;
goto V_42;
}
F_9 ( & V_23 -> V_13 ) ;
if ( V_23 -> V_44 & V_59 )
V_10 = V_51 ;
else
F_5 ( V_2 , 4 , L_7 ,
V_3 ) ;
F_15 ( & V_23 -> V_13 ) ;
V_42:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_60 = ( V_2 -> V_8 . V_61 -> V_62 & 0x00f0 ) >> 4 ;
int V_63 = V_2 -> V_8 . V_61 -> V_62 & 0x000f ;
T_3 V_45 ;
T_1 V_3 = V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_63 ] ;
T_4 V_68 ;
int V_10 ;
if ( V_2 -> V_8 . V_61 -> V_69 . V_70 & V_71 )
return F_26 ( V_2 , V_72 ) ;
V_68 = F_27 ( V_2 ) ;
if ( V_60 % 2 )
V_45 = V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_60 ] ;
else
V_45 = V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_60 + 1 ] ;
F_28 ( V_2 , V_68 , V_3 , V_45 ) ;
switch ( V_68 ) {
case V_73 :
V_2 -> V_74 . V_75 ++ ;
V_10 = F_1 ( V_2 , V_3 ,
& V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_60 ] ) ;
break;
case V_76 :
V_2 -> V_74 . V_77 ++ ;
V_10 = F_16 ( V_2 , V_3 ) ;
break;
case V_78 :
V_2 -> V_74 . V_79 ++ ;
V_10 = F_6 ( V_2 , V_3 ) ;
break;
case V_80 :
V_2 -> V_74 . V_81 ++ ;
V_10 = F_18 ( V_2 , V_3 , V_59 ) ;
break;
case V_82 :
V_2 -> V_74 . V_81 ++ ;
V_10 = F_18 ( V_2 , V_3 , V_83 |
V_59 ) ;
break;
case V_84 :
V_2 -> V_74 . V_85 ++ ;
V_10 = F_20 ( V_2 , V_45 ) ;
break;
case V_86 :
V_2 -> V_74 . V_87 ++ ;
V_10 = F_21 ( V_2 , V_3 , V_45 ,
& V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_60 ] ) ;
break;
case V_88 :
V_2 -> V_74 . V_89 ++ ;
V_10 = F_23 ( V_2 , V_3 ,
& V_2 -> V_64 -> V_65 . V_66 . V_67 [ V_60 ] ) ;
break;
case V_90 :
V_2 -> V_74 . V_91 ++ ;
V_10 = F_24 ( V_2 , V_3 ) ;
if ( V_10 == V_51 )
break;
default:
return - V_46 ;
}
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_8 . V_61 -> V_69 . V_70 &= ~ ( 3ul << 44 ) ;
V_2 -> V_8 . V_61 -> V_69 . V_70 |= ( V_10 & 3ul ) << 44 ;
return 0 ;
}
