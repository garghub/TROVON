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
enum V_18 V_19 )
{
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
struct V_4 V_44 = {
. V_6 = V_7 ,
. V_14 = V_15 ,
. V_8 = V_9 ,
. V_12 = V_45 ,
. V_10 = V_46 ,
} ;
if ( V_39 == 0 )
return - V_47 ;
if ( V_39 < 0 ) {
V_43 = V_39 * - 1 ;
V_41 = V_40 ? 0 : 1 ;
} else {
V_43 = V_39 ;
V_41 = V_40 ? 1 : 0 ;
}
V_42 = F_8 ( V_17 , V_43 , & V_44 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_9 ( V_17 , V_43 , V_41 ) ;
}
int F_10 ( struct V_16 * V_17 )
{
int V_48 = F_11 ( V_17 ) ;
struct V_1 * V_49 = F_1 ( V_48 ) ;
switch ( V_48 ) {
case V_50 :
F_7 ( V_17 , V_49 -> V_51 , 0 ) ;
F_7 ( V_17 , V_49 -> V_52 , 0 ) ;
F_7 ( V_17 , V_49 -> V_53 , 0 ) ;
break;
case V_54 :
case V_55 :
F_7 ( V_17 , V_49 -> V_56 , 0 ) ;
break;
}
return 0 ;
}
int F_12 ( struct V_16 * V_17 , int V_57 )
{
int V_48 = F_11 ( V_17 ) ;
struct V_1 * V_49 = F_1 ( V_48 ) ;
switch ( V_48 ) {
case V_50 :
F_7 ( V_17 ,
V_49 -> V_51 , V_57 ? 1 : 0 ) ;
break;
case V_54 :
case V_55 :
if ( ! V_57 )
F_7 ( V_17 , V_49 -> V_56 , 0 ) ;
break;
}
return 0 ;
}
int F_13 ( struct V_16 * V_17 , int V_58 )
{
int V_48 = F_11 ( V_17 ) ;
struct V_1 * V_49 = F_1 ( V_48 ) ;
if ( F_14 ( V_17 , - 1 ) == V_58 )
return 0 ;
switch ( V_48 ) {
case V_50 :
F_7 ( V_17 ,
V_49 -> V_53 , ( V_58 & V_59 ) ? 1 : 0 ) ;
F_7 ( V_17 ,
V_49 -> V_52 , ( V_58 & V_60 ) ? 1 : 0 ) ;
F_14 ( V_17 , V_58 ) ;
break;
}
return 0 ;
}
int F_15 ( struct V_16 * V_17 , int V_57 )
{
int V_48 = F_11 ( V_17 ) ;
struct V_1 * V_49 = F_1 ( V_48 ) ;
F_16 ( L_2 , V_61 , V_57 ? L_3 : L_4 ) ;
switch ( V_48 ) {
case V_54 :
case V_55 :
F_7 ( V_17 ,
V_49 -> V_62 , V_57 ? 1 : 0 ) ;
return F_7 ( V_17 ,
V_49 -> V_56 , V_57 ? 1 : 0 ) ;
}
return - V_47 ;
}
int F_17 ( int V_2 )
{
F_18 ( L_5 ) ;
return 0 ;
}
