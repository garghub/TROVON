static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_9 ;
V_9 = V_8 -> V_10 ;
switch ( V_4 ) {
case V_11 :
V_6 -> V_12 = ! ! ( V_9 & V_13 ) ;
break;
case V_14 :
V_6 -> V_12 = ! ! ( V_9 & V_15 ) ;
break;
case V_16 :
V_6 -> V_12 = V_17 ;
if ( ! ( V_9 & V_13 ) )
V_6 -> V_12 = V_18 ;
else if ( V_9 & V_15 &&
! ( V_9 & V_19 ) )
V_6 -> V_12 = V_20 ;
else
V_6 -> V_12 = V_21 ;
break;
case V_22 :
if ( V_9 & V_23 )
V_6 -> V_12 = V_24 ;
if ( V_9 & V_25 )
V_6 -> V_12 = V_26 ;
else
V_6 -> V_12 = V_27 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
int V_29 ;
V_29 = F_4 ( V_8 -> V_30 , V_31 , & V_9 ) ;
if ( ! V_29 && V_9 != V_8 -> V_10 ) {
V_8 -> V_10 = V_9 ;
F_5 ( V_8 -> V_1 ) ;
return 1 ;
}
return 0 ;
}
static void F_6 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_7 ( V_33 , struct V_7 , V_33 . V_33 ) ;
F_3 ( V_8 ) ;
F_8 ( & V_8 -> V_33 ,
F_9 ( V_34 ) ) ;
}
static T_1 F_10 ( int V_35 , void * V_36 )
{
struct V_7 * V_8 = V_36 ;
int V_29 ;
V_29 = F_3 ( V_8 ) ;
return V_29 ? V_37 : V_38 ;
}
static bool F_11 ( struct V_39 * V_40 , unsigned int V_9 )
{
if ( V_9 < V_41 )
return false ;
else
return true ;
}
static bool F_12 ( struct V_39 * V_40 , unsigned int V_9 )
{
switch ( V_9 ) {
case V_31 :
return true ;
}
return false ;
}
static int F_13 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_46 V_47 = {} ;
struct V_7 * V_8 ;
int V_29 , V_6 ;
V_8 = F_14 ( & V_43 -> V_40 , sizeof( struct V_7 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_8 -> V_43 = V_43 ;
V_47 . V_50 = V_43 -> V_40 . V_50 ;
V_47 . V_51 = V_8 ;
F_15 ( V_43 , V_8 ) ;
V_8 -> V_30 = F_16 ( V_43 , & V_52 ) ;
if ( F_17 ( V_8 -> V_30 ) )
return F_18 ( V_8 -> V_30 ) ;
V_29 = F_4 ( V_8 -> V_30 , V_31 , & V_6 ) ;
if ( V_29 ) {
F_19 ( & V_43 -> V_40 , L_1 ) ;
return V_29 ;
}
V_8 -> V_10 = V_6 ;
V_8 -> V_1 = F_20 ( & V_43 -> V_40 , & V_53 ,
& V_47 ) ;
if ( F_17 ( V_8 -> V_1 ) ) {
F_19 ( & V_43 -> V_40 , L_2 ) ;
return F_18 ( V_8 -> V_1 ) ;
}
if ( V_43 -> V_35 ) {
V_29 = F_21 ( & V_43 -> V_40 , V_43 -> V_35 ,
NULL , F_10 ,
V_54 | V_55 ,
F_22 ( & V_43 -> V_40 ) , V_8 ) ;
if ( V_29 ) {
F_19 ( & V_43 -> V_40 , L_3 , V_29 ) ;
return V_29 ;
}
} else {
F_23 ( & V_8 -> V_33 , F_6 ) ;
F_8 ( & V_8 -> V_33 ,
F_9 ( V_34 ) ) ;
}
F_24 ( & V_43 -> V_40 ,
L_4 , V_43 -> V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_7 * V_8 = F_26 ( V_43 ) ;
F_27 ( & V_8 -> V_33 ) ;
return 0 ;
}
