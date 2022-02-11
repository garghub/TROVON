int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_4 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
return F_6 ( V_2 -> V_3 ,
V_8 , 1 ) ;
} else {
return F_6 ( V_2 -> V_3 ,
V_8 , 0 ) ;
}
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_9 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
return F_3 ( V_2 -> V_3 ,
V_10 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , enum V_11 V_12 , enum V_13 V_14 )
{
int V_15 = 0 ;
switch ( V_12 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
if ( V_14 == V_20 )
V_15 = F_1 ( V_2 ) ;
else
V_15 = F_4 ( V_2 ) ;
break;
case V_21 :
default:
break;
}
return V_15 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = (struct V_22 * ) ( V_2 -> V_24 ) ;
V_23 -> V_25 = false ;
V_23 -> V_26 = false ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , bool V_27 )
{
struct V_22 * V_23 = (struct V_22 * ) ( V_2 -> V_24 ) ;
if ( V_23 -> V_25 == V_27 )
return 0 ;
V_23 -> V_25 = V_27 ;
if ( V_27 ) {
F_13 ( V_2 -> V_28 ,
V_29 ,
V_30 ) ;
F_14 ( V_2 -> V_28 ,
V_29 ,
V_31 ) ;
F_15 ( V_2 , true ) ;
F_1 ( V_2 ) ;
} else {
F_4 ( V_2 ) ;
F_14 ( V_2 -> V_28 ,
V_29 ,
V_32 ) ;
F_13 ( V_2 -> V_28 ,
V_29 ,
V_31 ) ;
F_15 ( V_2 , false ) ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_27 )
{
struct V_22 * V_23 = (struct V_22 * ) ( V_2 -> V_24 ) ;
struct V_33 V_34 ;
const struct V_35 * V_36 ;
struct V_35 * V_37 ;
V_36 = V_2 -> V_38 ;
V_37 = V_2 -> V_39 ;
V_34 . V_40 = & ( V_36 -> V_41 ) ;
V_34 . V_42 = & ( V_37 -> V_41 ) ;
if ( F_8 ( V_2 ) ) {
if ( V_23 -> V_26 != V_27 ) {
if ( V_27 ) {
F_13 (
V_2 -> V_28 ,
V_43 ,
V_30 ) ;
F_14 (
V_2 -> V_28 ,
V_43 ,
V_31 ) ;
F_17 ( V_2 , false ) ;
V_23 -> V_26 = true ;
} else {
F_9 ( V_2 ) ;
V_23 -> V_26 = false ;
F_14 (
V_2 -> V_28 ,
V_43 ,
V_32 ) ;
F_13 (
V_2 -> V_28 ,
V_43 ,
V_31 ) ;
F_18 ( V_2 , & V_34 ) ;
F_17 ( V_2 , true ) ;
return 0 ;
}
}
} else {
F_18 ( V_2 , & V_34 ) ;
F_17 ( V_2 , true ) ;
return 0 ;
}
if ( ! V_23 -> V_26 )
F_18 ( V_2 , & V_34 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
const T_1 * V_44 )
{
T_2 V_45 ;
T_1 V_46 ;
switch ( ( * V_44 & V_47 ) >> V_48 ) {
case V_49 :
switch ( ( * V_44 & V_50 ) >> V_51 ) {
case V_52 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = V_58 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
if ( V_59 & * V_44 ) {
V_45 = ( * V_44 & V_54 ) & V_60
? V_56
: V_57 ;
V_46 = V_61 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
case V_62 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = ( V_63 | V_64 ) ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
case V_65 :
switch ( ( * V_44 & V_50 ) >> V_51 ) {
case V_66 :
if ( V_59 & * V_44 ) {
V_45 = ( * V_44 & V_54 ) & V_60
? V_56
: V_57 ;
V_46 = V_67 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
case V_68 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = V_69 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
if ( V_59 & * V_44 ) {
V_45 = ( * V_44 & V_54 ) & V_60
? V_56
: V_57 ;
V_46 = V_70 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
case V_71 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = V_72 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
if ( V_59 & * V_44 ) {
V_45 = ( * V_44 & V_54 ) & V_60
? V_56
: V_57 ;
V_46 = V_73 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
case V_74 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = V_75 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
if ( V_59 & * V_44 ) {
V_45 = ( * V_44 & V_54 ) & V_60
? V_56
: V_57 ;
V_46 = V_76 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
case V_77 :
if ( V_53 & * V_44 ) {
V_45 = ( ( * V_44 & V_54 ) & V_55 )
? V_56
: V_57 ;
V_46 = V_78 ;
if ( 0 != F_6 ( V_2 -> V_3 , V_45 , V_46 ) )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
default:
return - 1 ;
}
return 0 ;
}
