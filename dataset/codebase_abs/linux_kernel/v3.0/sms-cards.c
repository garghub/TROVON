struct V_1 * F_1 ( unsigned V_2 )
{
F_2 ( V_2 >= F_3 ( V_3 ) ) ;
return & V_3 [ V_2 ] ;
}
static inline void F_4 (
struct V_4 * V_5 ) {
V_5 -> V_6 = V_7 ;
V_5 -> V_8 =
V_9 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = V_15 ;
}
int F_5 ( struct V_16 * V_17 ,
enum V_18 V_19 ) {
struct V_4 V_20 ;
F_4 ( & V_20 ) ;
switch ( V_19 ) {
case V_21 :
break;
case V_22 :
break;
case V_23 :
break;
case V_24 :
break;
case V_25 :
break;
case V_26 :
break;
case V_27 :
break;
case V_28 :
break;
case V_29 :
break;
case V_30 :
break;
case V_31 :
break;
case V_32 :
break;
case V_33 :
break;
case V_34 :
break;
case V_35 :
break;
case V_36 :
break;
case V_37 :
break;
case V_38 :
break;
default:
F_6 ( L_1 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_16 * V_17 , int V_39 , int V_40 )
{
int V_41 , V_42 ;
T_1 V_43 ;
struct V_44 V_45 = {
. V_46 = V_7 ,
. V_47 = V_48 ,
. V_49 = V_50 ,
. V_51 = V_52 ,
. V_53 = V_54 ,
} ;
if ( V_39 == 0 )
return - V_55 ;
if ( V_39 < 0 ) {
V_43 = V_39 * - 1 ;
V_41 = V_40 ? 0 : 1 ;
} else {
V_43 = V_39 ;
V_41 = V_40 ? 1 : 0 ;
}
V_42 = F_8 ( V_17 , V_43 , & V_45 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_9 ( V_17 , V_43 , V_41 ) ;
}
int F_10 ( struct V_16 * V_17 )
{
int V_56 = F_11 ( V_17 ) ;
struct V_1 * V_57 = F_1 ( V_56 ) ;
switch ( V_56 ) {
case V_58 :
F_7 ( V_17 , V_57 -> V_59 , 0 ) ;
F_7 ( V_17 , V_57 -> V_60 , 0 ) ;
F_7 ( V_17 , V_57 -> V_61 , 0 ) ;
break;
case V_62 :
case V_63 :
F_7 ( V_17 , V_57 -> V_64 , 0 ) ;
break;
}
return 0 ;
}
int F_12 ( struct V_16 * V_17 , int V_65 )
{
int V_56 = F_11 ( V_17 ) ;
struct V_1 * V_57 = F_1 ( V_56 ) ;
switch ( V_56 ) {
case V_58 :
F_7 ( V_17 ,
V_57 -> V_59 , V_65 ? 1 : 0 ) ;
break;
case V_62 :
case V_63 :
if ( ! V_65 )
F_7 ( V_17 , V_57 -> V_64 , 0 ) ;
break;
}
return 0 ;
}
int F_13 ( struct V_16 * V_17 , int V_66 )
{
int V_56 = F_11 ( V_17 ) ;
struct V_1 * V_57 = F_1 ( V_56 ) ;
if ( F_14 ( V_17 , - 1 ) == V_66 )
return 0 ;
switch ( V_56 ) {
case V_58 :
F_7 ( V_17 ,
V_57 -> V_61 , ( V_66 & V_67 ) ? 1 : 0 ) ;
F_7 ( V_17 ,
V_57 -> V_60 , ( V_66 & V_68 ) ? 1 : 0 ) ;
F_14 ( V_17 , V_66 ) ;
break;
}
return 0 ;
}
int F_15 ( struct V_16 * V_17 , int V_65 )
{
int V_56 = F_11 ( V_17 ) ;
struct V_1 * V_57 = F_1 ( V_56 ) ;
F_16 ( L_2 , V_69 , V_65 ? L_3 : L_4 ) ;
switch ( V_56 ) {
case V_62 :
case V_63 :
F_7 ( V_17 ,
V_57 -> V_70 , V_65 ? 1 : 0 ) ;
return F_7 ( V_17 ,
V_57 -> V_64 , V_65 ? 1 : 0 ) ;
}
return - V_55 ;
}
int F_17 ( int V_2 )
{
switch ( V_2 ) {
case V_71 :
case V_72 :
case V_73 :
case V_58 :
case V_63 :
case V_62 :
F_18 ( L_5 ) ;
break;
default:
break;
}
return 0 ;
}
