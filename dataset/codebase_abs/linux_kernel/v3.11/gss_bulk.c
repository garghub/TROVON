int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_1 V_13 ;
T_2 V_14 ;
int V_15 ;
int V_16 ;
V_17 ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_19 || V_4 -> V_20 ) ;
V_8 = F_3 ( V_2 , struct V_7 , V_21 ) ;
F_2 ( V_8 -> V_22 ) ;
switch ( F_4 ( V_4 -> V_23 . V_24 ) ) {
case V_25 :
F_2 ( V_4 -> V_26 -> V_27 >= 3 ) ;
V_10 = V_4 -> V_26 ;
V_15 = V_10 -> V_27 - 1 ;
break;
case V_28 :
case V_29 :
F_2 ( V_4 -> V_26 -> V_27 >= 4 ) ;
V_10 = V_4 -> V_26 ;
V_15 = V_10 -> V_27 - 2 ;
break;
case V_30 :
F_2 ( V_4 -> V_31 -> V_27 >= 2 ) ;
V_10 = V_4 -> V_31 ;
V_15 = V_10 -> V_27 - 1 ;
break;
default:
F_5 () ;
}
V_12 = F_6 ( V_10 , V_15 , sizeof( * V_12 ) ) ;
V_12 -> V_32 = 0 ;
V_12 -> V_33 = 0 ;
V_12 -> V_34 = V_35 ;
V_12 -> V_36 = F_7 ( V_4 -> V_23 . V_24 ) ;
if ( V_12 -> V_36 == V_37 )
RETURN ( 0 ) ;
F_2 ( V_12 -> V_36 == V_38 ||
V_12 -> V_36 == V_39 ) ;
if ( V_4 -> V_19 ) {
if ( V_12 -> V_36 == V_39 )
return F_8 ( V_4 , V_6 ) ;
} else {
V_12 -> V_40 = V_6 -> V_41 ;
if ( V_12 -> V_36 == V_38 ) {
V_13 . V_42 = V_12 -> V_43 ;
V_13 . V_44 = F_9 ( V_10 , V_15 ) -
sizeof( * V_12 ) ;
V_14 = F_10 ( V_8 -> V_22 , 0 , NULL ,
V_6 -> V_45 , V_6 -> V_46 ,
& V_13 ) ;
if ( V_14 != V_47 ) {
F_11 ( L_1 , V_14 ) ;
RETURN ( - V_48 ) ;
}
} else {
if ( V_6 -> V_45 == 0 )
RETURN ( 0 ) ;
V_16 = F_12 ( V_6 ) ;
if ( V_16 ) {
F_13 ( L_2
L_3 , V_16 ) ;
RETURN ( V_16 ) ;
}
V_13 . V_42 = V_12 -> V_43 ;
V_13 . V_44 = F_9 ( V_10 , V_15 ) -
sizeof( * V_12 ) ;
V_14 = F_14 ( V_8 -> V_22 , V_6 , & V_13 , 0 ) ;
if ( V_14 != V_47 ) {
F_11 ( L_4 , V_14 ) ;
RETURN ( - V_48 ) ;
}
}
}
RETURN ( 0 ) ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_49 , * V_50 ;
struct V_11 * V_51 , * V_52 ;
T_1 V_13 ;
T_2 V_14 ;
int V_53 , V_54 ;
V_17 ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_19 || V_4 -> V_20 ) ;
switch ( F_4 ( V_4 -> V_23 . V_24 ) ) {
case V_25 :
V_50 = V_4 -> V_55 ;
V_54 = V_50 -> V_27 - 1 ;
F_2 ( V_50 && V_50 -> V_27 >= 3 ) ;
V_49 = V_4 -> V_26 ;
V_53 = V_49 -> V_27 - 1 ;
F_2 ( V_49 && V_49 -> V_27 >= 3 ) ;
break;
case V_28 :
case V_29 :
V_50 = V_4 -> V_55 ;
V_54 = V_50 -> V_27 - 2 ;
F_2 ( V_50 && V_50 -> V_27 >= 4 ) ;
V_49 = V_4 -> V_26 ;
V_53 = V_49 -> V_27 - 2 ;
F_2 ( V_49 && V_49 -> V_27 >= 4 ) ;
break;
case V_30 :
V_50 = V_4 -> V_55 ;
V_54 = V_50 -> V_27 - 1 ;
F_2 ( V_50 && V_50 -> V_27 >= 2 ) ;
V_49 = V_4 -> V_31 ;
V_53 = V_49 -> V_27 - 1 ;
F_2 ( V_49 && V_49 -> V_27 >= 2 ) ;
break;
default:
F_5 () ;
}
V_51 = F_6 ( V_49 , V_53 , sizeof( * V_51 ) ) ;
V_52 = F_6 ( V_50 , V_54 , sizeof( * V_52 ) ) ;
F_2 ( V_51 && V_52 ) ;
if ( V_51 -> V_32 != V_52 -> V_32 ||
V_51 -> V_34 != V_52 -> V_34 ||
V_51 -> V_36 != V_52 -> V_36 ) {
F_13 ( L_5
L_6 ,
V_51 -> V_32 , V_51 -> V_34 , V_51 -> V_36 ,
V_52 -> V_32 , V_52 -> V_34 , V_52 -> V_36 ) ;
RETURN ( - V_56 ) ;
}
F_2 ( V_52 -> V_36 == V_37 ||
V_52 -> V_36 == V_38 ||
V_52 -> V_36 == V_39 ) ;
if ( V_4 -> V_20 ) {
if ( V_52 -> V_33 & V_57 ) {
F_13 ( L_7 ) ;
RETURN ( - V_58 ) ;
}
if ( V_52 -> V_36 == V_39 )
V_6 -> V_59 = V_6 -> V_41 ;
} else {
V_8 = F_3 ( V_2 , struct V_7 , V_21 ) ;
F_2 ( V_8 -> V_22 ) ;
if ( V_52 -> V_36 == V_38 ) {
int V_60 , V_61 ;
for ( V_60 = 0 , V_61 = 0 ; V_60 < V_6 -> V_45 ; V_60 ++ ) {
if ( V_6 -> V_46 [ V_60 ] . V_62 + V_61 >
V_6 -> V_59 ) {
V_6 -> V_46 [ V_60 ] . V_62 =
V_6 -> V_59 - V_61 ;
}
V_61 += V_6 -> V_46 [ V_60 ] . V_62 ;
}
V_13 . V_42 = V_52 -> V_43 ;
V_13 . V_44 = F_9 ( V_50 , V_54 ) -
sizeof( * V_52 ) ;
V_14 = F_16 ( V_8 -> V_22 , 0 , NULL ,
V_6 -> V_45 , V_6 -> V_46 ,
& V_13 ) ;
if ( V_14 != V_47 ) {
F_13 ( L_8 , V_14 ) ;
RETURN ( - V_48 ) ;
}
} else if ( V_52 -> V_36 == V_39 ) {
V_6 -> V_41 = V_52 -> V_40 ;
if ( V_6 -> V_41 == 0 )
RETURN ( 0 ) ;
V_13 . V_42 = V_52 -> V_43 ;
V_13 . V_44 = F_9 ( V_50 , V_54 ) -
sizeof( * V_51 ) ;
V_14 = F_17 ( V_8 -> V_22 , V_6 ,
& V_13 , 1 ) ;
if ( V_14 != V_47 ) {
F_13 ( L_9 ,
V_14 ) ;
RETURN ( - V_48 ) ;
}
V_6 -> V_59 = V_6 -> V_41 ;
}
}
RETURN ( 0 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_63 * V_64 )
{
int V_16 ;
if ( V_6 -> V_45 == 0 )
return 0 ;
V_16 = F_12 ( V_6 ) ;
if ( V_16 )
return V_16 ;
if ( F_19 ( V_64 , V_6 ) != V_47 )
return - V_48 ;
return 0 ;
}
int F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_16 ;
V_17 ;
F_2 ( V_4 -> V_65 ) ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_19 ) ;
if ( F_7 ( V_4 -> V_23 . V_24 ) != V_39 )
RETURN ( 0 ) ;
V_16 = F_18 ( V_6 , F_20 ( V_4 -> V_65 ) -> V_22 ) ;
if ( V_16 )
F_13 ( L_10
L_11 , V_16 ) ;
RETURN ( V_16 ) ;
}
int F_21 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_66 * V_67 ;
struct V_11 * V_12 ;
int V_16 ;
V_17 ;
F_2 ( V_4 -> V_68 ) ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_20 ) ;
V_67 = F_22 ( V_4 -> V_68 ) ;
F_2 ( V_67 -> V_69 ) ;
F_2 ( V_67 -> V_70 ) ;
F_2 ( V_67 -> V_71 ) ;
F_2 ( V_67 -> V_71 -> V_72 ) ;
V_12 = V_67 -> V_69 ;
if ( V_12 -> V_36 != V_39 )
RETURN ( 0 ) ;
V_16 = F_18 ( V_6 , V_67 -> V_71 -> V_72 ) ;
if ( V_16 )
F_13 ( L_12
L_11 , V_16 ) ;
RETURN ( V_16 ) ;
}
int F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_66 * V_67 ;
struct V_11 * V_51 , * V_52 ;
T_1 V_13 ;
T_2 V_14 ;
V_17 ;
F_2 ( V_4 -> V_68 ) ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_20 ) ;
V_67 = F_22 ( V_4 -> V_68 ) ;
F_2 ( V_67 -> V_69 ) ;
F_2 ( V_67 -> V_70 ) ;
F_2 ( V_67 -> V_71 ) ;
F_2 ( V_67 -> V_71 -> V_72 ) ;
V_51 = V_67 -> V_69 ;
V_52 = V_67 -> V_70 ;
V_52 -> V_32 = 0 ;
V_52 -> V_34 = V_35 ;
V_52 -> V_36 = V_51 -> V_36 ;
V_52 -> V_33 = 0 ;
switch ( V_52 -> V_36 ) {
case V_38 :
V_13 . V_42 = V_51 -> V_43 ;
V_13 . V_44 = V_67 -> V_73 - sizeof( * V_51 ) ;
V_14 = F_16 ( V_67 -> V_71 -> V_72 , 0 , NULL ,
V_6 -> V_45 , V_6 -> V_46 , & V_13 ) ;
if ( V_14 != V_47 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_13 , V_14 ) ;
RETURN ( - V_48 ) ;
}
break;
case V_39 :
if ( V_51 -> V_40 != V_6 -> V_41 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_14
L_15 , V_6 -> V_41 , V_51 -> V_40 ) ;
RETURN ( - V_56 ) ;
}
if ( V_6 -> V_45 == 0 ) {
F_2 ( V_6 -> V_41 == 0 ) ;
break;
}
V_13 . V_42 = V_51 -> V_43 ;
V_13 . V_44 = V_67 -> V_73 - sizeof( * V_51 ) ;
V_14 = F_17 ( V_67 -> V_71 -> V_72 ,
V_6 , & V_13 , 0 ) ;
if ( V_14 != V_47 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_16 , V_14 ) ;
RETURN ( - V_48 ) ;
}
break;
}
RETURN ( 0 ) ;
}
int F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_66 * V_67 ;
struct V_11 * V_51 , * V_52 ;
T_1 V_13 ;
T_2 V_14 ;
int V_16 ;
V_17 ;
F_2 ( V_4 -> V_68 ) ;
F_2 ( V_4 -> V_18 ) ;
F_2 ( V_4 -> V_19 ) ;
V_67 = F_22 ( V_4 -> V_68 ) ;
F_2 ( V_67 -> V_69 ) ;
F_2 ( V_67 -> V_70 ) ;
F_2 ( V_67 -> V_71 ) ;
F_2 ( V_67 -> V_71 -> V_72 ) ;
V_51 = V_67 -> V_69 ;
V_52 = V_67 -> V_70 ;
V_52 -> V_32 = 0 ;
V_52 -> V_34 = V_35 ;
V_52 -> V_36 = V_51 -> V_36 ;
V_52 -> V_33 = 0 ;
switch ( V_52 -> V_36 ) {
case V_38 :
V_13 . V_42 = V_52 -> V_43 ;
V_13 . V_44 = V_67 -> V_74 - sizeof( * V_52 ) ;
V_14 = F_10 ( V_67 -> V_71 -> V_72 , 0 , NULL ,
V_6 -> V_45 , V_6 -> V_46 , & V_13 ) ;
if ( V_14 != V_47 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_1 , V_14 ) ;
RETURN ( - V_48 ) ;
}
break;
case V_39 :
V_52 -> V_40 = V_6 -> V_41 ;
if ( V_6 -> V_45 == 0 ) {
F_2 ( V_6 -> V_41 == 0 ) ;
break;
}
V_16 = F_12 ( V_6 ) ;
if ( V_16 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_17
L_11 , V_16 ) ;
RETURN ( V_16 ) ;
}
V_13 . V_42 = V_52 -> V_43 ;
V_13 . V_44 = V_67 -> V_74 - sizeof( * V_52 ) ;
V_14 = F_14 ( V_67 -> V_71 -> V_72 ,
V_6 , & V_13 , 1 ) ;
if ( V_14 != V_47 ) {
V_52 -> V_33 |= V_57 ;
F_13 ( L_18 , V_14 ) ;
RETURN ( - V_48 ) ;
}
break;
}
RETURN ( 0 ) ;
}
