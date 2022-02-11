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
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_37 , T_2 * V_4 )
{
struct V_1 * V_38 = NULL ;
const T_2 V_39 = V_40 | V_41 ;
T_1 V_42 , V_43 ;
T_3 * V_44 ;
T_4 V_45 ;
if ( V_3 < V_11 )
V_38 = F_17 ( V_2 -> V_7 , V_3 ) ;
if ( ! V_38 )
return V_12 ;
V_45 = F_3 ( & V_38 -> V_8 . V_46 -> V_15 ) ;
V_44 = & V_38 -> V_8 . V_46 -> V_47 ;
V_42 = V_38 -> V_8 . V_46 -> V_48 [ 4 ] & 0xffff ;
V_43 = V_38 -> V_8 . V_46 -> V_48 [ 3 ] & 0xffff ;
if ( ! ( V_45 & V_17 )
|| ( V_44 -> V_49 & V_39 ) != V_39
|| ( ( V_45 & V_50 ) && V_44 -> V_51 != 0 )
|| ( ! ( V_45 & V_50 ) && ( V_37 == V_42 || V_37 == V_43 ) ) ) {
return F_6 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
return V_21 ;
}
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 )
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
V_25 -> type = V_53 ;
V_25 -> V_54 . V_30 = V_2 -> V_31 ;
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
static int F_19 ( struct V_22 * V_23 , int V_55 )
{
struct V_24 * V_25 ;
int V_10 = V_18 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_56 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> type = V_57 ;
F_9 ( & V_23 -> V_13 ) ;
if ( ( F_3 ( V_23 -> V_15 ) & V_17 ) ) {
F_8 ( V_25 ) ;
if ( ( V_55 & V_58 ) != 0 )
V_10 = - V_59 ;
goto V_60;
}
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
F_12 ( V_61 , V_23 -> V_15 ) ;
V_23 -> V_62 |= V_55 ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
V_60:
F_15 ( & V_23 -> V_13 ) ;
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_3 , int V_55 )
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
V_10 = F_19 ( V_23 , V_55 ) ;
V_32:
F_4 ( & V_6 -> V_13 ) ;
F_5 ( V_2 , 4 , L_4 , V_3 ) ;
if ( ( V_55 & V_58 ) != 0 && V_10 == - V_59 ) {
struct V_1 * V_38 = F_17 ( V_2 -> V_7 , V_3 ) ;
V_10 = F_21 ( V_38 ,
V_63 ) ;
}
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_64 )
{
int V_10 ;
switch ( V_64 & 0xff ) {
case 0 :
V_10 = V_12 ;
break;
case 1 :
case 2 :
V_10 = V_18 ;
break;
default:
V_10 = - V_65 ;
}
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_66 ,
T_2 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_9 ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 ;
int V_10 ;
T_5 V_67 ;
V_66 = V_66 & 0x7fffe000u ;
if ( F_24 ( V_2 , & V_67 , V_66 , 1 ) ||
F_24 ( V_2 , & V_67 , V_66 + V_68 , 1 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_69 ;
return V_21 ;
}
V_25 = F_7 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return V_70 ;
F_2 ( & V_6 -> V_13 ) ;
if ( V_3 < V_11 )
V_23 = V_6 -> V_14 [ V_3 ] ;
if ( V_23 == NULL ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
V_10 = V_21 ;
F_8 ( V_25 ) ;
goto V_71;
}
F_9 ( & V_23 -> V_13 ) ;
if ( ! ( F_3 ( V_23 -> V_15 ) & V_17 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
V_10 = V_21 ;
F_8 ( V_25 ) ;
goto V_72;
}
V_25 -> type = V_73 ;
V_25 -> V_74 . V_66 = V_66 ;
F_10 ( & V_25 -> V_33 , & V_23 -> V_33 ) ;
F_11 ( & V_23 -> V_34 , 1 ) ;
if ( F_13 ( V_23 -> V_36 ) )
F_14 ( V_23 -> V_36 ) ;
V_10 = V_18 ;
F_5 ( V_2 , 4 , L_5 , V_3 , V_66 ) ;
V_72:
F_15 ( & V_23 -> V_13 ) ;
V_71:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_75 ,
T_4 V_51 , T_2 * V_4 )
{
struct V_1 * V_38 = NULL ;
int V_45 ;
int V_10 ;
if ( V_75 < V_11 )
V_38 = F_17 ( V_2 -> V_7 , V_75 ) ;
if ( ! V_38 )
return V_12 ;
F_9 ( & V_38 -> V_8 . V_14 . V_13 ) ;
V_45 = F_3 ( V_38 -> V_8 . V_14 . V_15 ) ;
F_15 ( & V_38 -> V_8 . V_14 . V_13 ) ;
if ( ! ( V_45 & V_17 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_52 ;
return V_21 ;
}
V_51 &= 0x7ffffe00 ;
V_10 = F_21 ( V_38 , V_51 ) ;
if ( V_10 == - V_76 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_69 ;
V_10 = V_21 ;
}
return V_10 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 ,
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
& V_77 ) {
V_10 = V_18 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_78 ;
V_10 = V_21 ;
}
}
F_4 ( & V_6 -> V_13 ) ;
F_5 ( V_2 , 4 , L_6 , V_3 ,
V_10 ) ;
return V_10 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
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
goto V_60;
}
F_9 ( & V_23 -> V_13 ) ;
if ( V_23 -> V_62 & V_79 )
V_10 = V_70 ;
F_15 ( & V_23 -> V_13 ) ;
V_60:
F_4 ( & V_6 -> V_13 ) ;
return V_10 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_80 = ( V_2 -> V_8 . V_46 -> V_81 & 0x00f0 ) >> 4 ;
int V_82 = V_2 -> V_8 . V_46 -> V_81 & 0x000f ;
T_4 V_64 ;
T_1 V_3 = V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_82 ] ;
T_5 V_87 ;
int V_10 ;
if ( V_2 -> V_8 . V_46 -> V_47 . V_49 & V_88 )
return F_29 ( V_2 , V_89 ) ;
V_87 = F_30 ( V_2 ) ;
if ( V_80 % 2 )
V_64 = V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ;
else
V_64 = V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 + 1 ] ;
F_31 ( V_2 , V_87 , V_3 , V_64 ) ;
switch ( V_87 ) {
case V_90 :
V_2 -> V_91 . V_92 ++ ;
V_10 = F_1 ( V_2 , V_3 ,
& V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ) ;
break;
case V_93 :
V_2 -> V_91 . V_94 ++ ;
V_10 = F_18 ( V_2 , V_3 ) ;
break;
case V_95 :
V_2 -> V_91 . V_96 ++ ;
V_10 = F_6 ( V_2 , V_3 ) ;
break;
case V_97 :
V_2 -> V_91 . V_98 ++ ;
V_10 = F_20 ( V_2 , V_3 , V_79 ) ;
break;
case V_99 :
V_2 -> V_91 . V_98 ++ ;
V_10 = F_20 ( V_2 , V_3 , V_58 |
V_79 ) ;
break;
case V_100 :
V_10 = F_25 ( V_2 , V_3 , V_64 ,
& V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ) ;
break;
case V_101 :
V_2 -> V_91 . V_102 ++ ;
V_10 = F_22 ( V_2 , V_64 ) ;
break;
case V_103 :
V_2 -> V_91 . V_104 ++ ;
V_10 = F_23 ( V_2 , V_3 , V_64 ,
& V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ) ;
break;
case V_105 :
V_10 = F_16 ( V_2 , V_3 , V_64 ,
& V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ) ;
break;
case V_106 :
V_2 -> V_91 . V_107 ++ ;
V_10 = F_26 ( V_2 , V_3 ,
& V_2 -> V_83 -> V_84 . V_85 . V_86 [ V_80 ] ) ;
break;
case V_108 :
V_10 = F_27 ( V_2 , V_3 ) ;
if ( V_10 == V_18 )
V_10 = - V_65 ;
break;
case V_109 :
V_2 -> V_91 . V_110 ++ ;
V_10 = F_27 ( V_2 , V_3 ) ;
if ( V_10 == V_18 ) {
F_5 ( V_2 , 4 ,
L_7 ,
V_3 ) ;
V_10 = - V_65 ;
}
break;
default:
return - V_65 ;
}
if ( V_10 < 0 )
return V_10 ;
F_32 ( V_2 , V_10 ) ;
return 0 ;
}
