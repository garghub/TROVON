static inline struct V_1 * F_1 (
const struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
void F_2 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_6 = V_6 ;
}
void * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_6 ;
}
struct V_8 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 ;
}
int F_5 ( const struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
enum V_13 V_14 ;
switch ( F_6 ( V_10 ) ) {
case V_15 :
V_14 = V_16 ;
break;
case V_17 :
V_14 = V_18 ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_14 = V_23 ;
break;
default:
return - V_24 ;
}
if ( V_3 -> V_25 == V_26 ) {
V_12 -> V_27 = V_28 ;
V_12 -> V_29 = V_14 ;
} else {
V_12 -> V_27 = V_30 ;
V_12 -> V_31 = V_14 ;
}
return 0 ;
}
static void F_7 ( void * V_32 )
{
struct V_2 * V_3 = V_32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_33 += F_8 ( V_3 ) ;
if ( V_7 -> V_33 >= F_9 ( V_3 ) )
V_7 -> V_33 = 0 ;
F_10 ( V_3 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_34 = V_7 -> V_8 ;
struct V_35 * V_36 ;
enum V_37 V_27 ;
V_27 = F_12 ( V_3 ) ;
V_7 -> V_33 = 0 ;
V_36 = F_13 ( V_34 ,
V_3 -> V_4 -> V_38 ,
F_9 ( V_3 ) ,
F_8 ( V_3 ) , V_27 ) ;
if ( ! V_36 )
return - V_39 ;
V_36 -> V_40 = F_7 ;
V_36 -> V_41 = V_3 ;
F_14 ( V_36 ) ;
return 0 ;
}
int F_15 ( struct V_2 * V_3 , int V_42 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_43 ;
switch ( V_42 ) {
case V_44 :
V_43 = F_11 ( V_3 ) ;
if ( V_43 )
return V_43 ;
F_16 ( V_7 -> V_8 ) ;
break;
case V_45 :
case V_46 :
F_17 ( V_7 -> V_8 ) ;
break;
case V_47 :
case V_48 :
F_18 ( V_7 -> V_8 ) ;
break;
case V_49 :
F_19 ( V_7 -> V_8 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
T_1 F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_21 ( V_3 -> V_4 , V_7 -> V_33 ) ;
}
static int F_22 ( struct V_1 * V_7 ,
T_2 V_50 , void * V_51 )
{
T_3 V_52 ;
F_23 ( V_52 ) ;
F_24 ( V_53 , V_52 ) ;
F_24 ( V_54 , V_52 ) ;
V_7 -> V_8 = F_25 ( V_52 , V_50 , V_51 ) ;
if ( ! V_7 -> V_8 )
return - V_55 ;
return 0 ;
}
int F_26 ( struct V_2 * V_3 ,
T_2 V_50 , void * V_51 )
{
struct V_1 * V_7 ;
int V_43 ;
V_43 = F_27 ( V_3 -> V_4 ,
V_56 ) ;
if ( V_43 < 0 )
return V_43 ;
V_7 = F_28 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 )
return - V_39 ;
V_43 = F_22 ( V_7 , V_50 , V_51 ) ;
if ( V_43 < 0 ) {
F_29 ( V_7 ) ;
return V_43 ;
}
V_3 -> V_4 -> V_5 = V_7 ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_31 ( V_7 -> V_8 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
