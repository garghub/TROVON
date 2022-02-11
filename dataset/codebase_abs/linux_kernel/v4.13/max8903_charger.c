static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_9 :
V_6 -> V_10 = V_11 ;
if ( F_3 ( V_8 -> V_12 -> V_13 ) ) {
if ( F_4 ( V_8 -> V_12 -> V_13 ) == 0 )
V_6 -> V_10 = V_14 ;
else if ( V_8 -> V_15 || V_8 -> V_16 )
V_6 -> V_10 = V_17 ;
else
V_6 -> V_10 = V_18 ;
}
break;
case V_19 :
V_6 -> V_10 = 0 ;
if ( V_8 -> V_15 || V_8 -> V_16 )
V_6 -> V_10 = 1 ;
break;
case V_20 :
V_6 -> V_10 = V_21 ;
if ( V_8 -> V_22 )
V_6 -> V_10 = V_23 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static T_1 F_5 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_16 ;
enum V_28 V_29 ;
V_16 = F_4 ( V_12 -> V_30 ) ? false : true ;
if ( V_16 == V_8 -> V_16 )
return V_31 ;
V_8 -> V_16 = V_16 ;
if ( F_3 ( V_12 -> V_32 ) )
F_6 ( V_12 -> V_32 , V_16 ? 1 : 0 ) ;
if ( F_3 ( V_12 -> V_33 ) )
F_6 ( V_12 -> V_33 , V_16 ? 0 :
( V_8 -> V_15 ? 0 : 1 ) ) ;
F_7 ( V_8 -> V_34 , L_1 , V_16 ?
L_2 : L_3 ) ;
V_29 = V_8 -> V_35 . type ;
if ( V_8 -> V_16 )
V_8 -> V_35 . type = V_36 ;
else if ( V_8 -> V_15 )
V_8 -> V_35 . type = V_37 ;
else
V_8 -> V_35 . type = V_38 ;
if ( V_29 != V_8 -> V_35 . type )
F_8 ( V_8 -> V_2 ) ;
return V_31 ;
}
static T_1 F_9 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_15 ;
enum V_28 V_29 ;
V_15 = F_4 ( V_12 -> V_39 ) ? false : true ;
if ( V_15 == V_8 -> V_15 )
return V_31 ;
V_8 -> V_15 = V_15 ;
if ( F_3 ( V_12 -> V_33 ) )
F_6 ( V_12 -> V_33 , V_15 ? 0 :
( V_8 -> V_16 ? 0 : 1 ) ) ;
F_7 ( V_8 -> V_34 , L_4 , V_15 ?
L_2 : L_3 ) ;
V_29 = V_8 -> V_35 . type ;
if ( V_8 -> V_16 )
V_8 -> V_35 . type = V_36 ;
else if ( V_8 -> V_15 )
V_8 -> V_35 . type = V_37 ;
else
V_8 -> V_35 . type = V_38 ;
if ( V_29 != V_8 -> V_35 . type )
F_8 ( V_8 -> V_2 ) ;
return V_31 ;
}
static T_1 F_10 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_22 ;
V_22 = F_4 ( V_12 -> V_40 ) ? false : true ;
if ( V_22 == V_8 -> V_22 )
return V_31 ;
V_8 -> V_22 = V_22 ;
if ( V_22 )
F_11 ( V_8 -> V_34 , L_5 ) ;
else
F_11 ( V_8 -> V_34 , L_6 ) ;
return V_31 ;
}
static struct V_27 * F_12 ( struct V_41 * V_34 )
{
struct V_42 * V_43 = V_34 -> V_44 ;
struct V_27 * V_12 = NULL ;
if ( ! V_43 )
return NULL ;
V_12 = F_13 ( V_34 , sizeof( * V_12 ) , V_45 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_46 = false ;
V_12 -> V_47 = false ;
V_12 -> V_33 = F_14 ( V_43 , L_7 , 0 ) ;
if ( ! F_3 ( V_12 -> V_33 ) )
V_12 -> V_33 = - V_24 ;
V_12 -> V_13 = F_14 ( V_43 , L_8 , 0 ) ;
if ( ! F_3 ( V_12 -> V_13 ) )
V_12 -> V_13 = - V_24 ;
V_12 -> V_40 = F_14 ( V_43 , L_9 , 0 ) ;
if ( ! F_3 ( V_12 -> V_40 ) )
V_12 -> V_40 = - V_24 ;
V_12 -> V_48 = F_14 ( V_43 , L_10 , 0 ) ;
if ( ! F_3 ( V_12 -> V_48 ) )
V_12 -> V_48 = - V_24 ;
V_12 -> V_32 = F_14 ( V_43 , L_11 , 0 ) ;
if ( ! F_3 ( V_12 -> V_32 ) )
V_12 -> V_32 = - V_24 ;
V_12 -> V_30 = F_14 ( V_43 , L_12 , 0 ) ;
if ( ! F_3 ( V_12 -> V_30 ) )
V_12 -> V_30 = - V_24 ;
else
V_12 -> V_46 = true ;
V_12 -> V_39 = F_14 ( V_43 , L_13 , 0 ) ;
if ( ! F_3 ( V_12 -> V_39 ) )
V_12 -> V_39 = - V_24 ;
else
V_12 -> V_47 = true ;
return V_12 ;
}
static int F_15 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = F_16 ( V_50 ) ;
struct V_41 * V_34 = & V_50 -> V_34 ;
struct V_27 * V_12 = V_50 -> V_34 . V_51 ;
int V_52 = 0 ;
int V_53 ;
int V_16 = 0 ;
int V_15 = 0 ;
if ( V_12 -> V_46 ) {
if ( F_3 ( V_12 -> V_30 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_30 ,
V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_14 ,
V_12 -> V_30 , V_52 ) ;
return V_52 ;
}
V_53 = V_12 -> V_30 ;
V_16 = F_4 ( V_53 ) ? 0 : 1 ;
} else {
F_11 ( V_34 , L_15 ) ;
return - V_24 ;
}
}
if ( F_3 ( V_12 -> V_32 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_32 , V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_16 ,
V_12 -> V_32 , V_52 ) ;
return V_52 ;
}
V_53 = V_12 -> V_32 ;
F_6 ( V_53 , V_16 ) ;
}
if ( V_12 -> V_47 ) {
if ( F_3 ( V_12 -> V_39 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_39 ,
V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_17 ,
V_12 -> V_39 , V_52 ) ;
return V_52 ;
}
V_53 = V_12 -> V_39 ;
V_15 = F_4 ( V_53 ) ? 0 : 1 ;
} else {
F_11 ( V_34 , L_18
L_19 ) ;
return - V_24 ;
}
}
if ( F_3 ( V_12 -> V_33 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_33 , V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_20 ,
V_12 -> V_33 , V_52 ) ;
return V_52 ;
}
F_6 ( V_12 -> V_33 , ( V_16 || V_15 ) ? 0 : 1 ) ;
}
if ( F_3 ( V_12 -> V_13 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_13 , V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_21 ,
V_12 -> V_13 , V_52 ) ;
return V_52 ;
}
}
if ( F_3 ( V_12 -> V_40 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_40 , V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_22 ,
V_12 -> V_40 , V_52 ) ;
return V_52 ;
}
}
if ( F_3 ( V_12 -> V_48 ) ) {
V_52 = F_17 ( V_34 , V_12 -> V_48 , V_8 -> V_35 . V_54 ) ;
if ( V_52 ) {
F_11 ( V_34 ,
L_23 ,
V_12 -> V_48 , V_52 ) ;
return V_52 ;
}
}
V_8 -> V_22 = false ;
V_8 -> V_16 = V_16 ;
V_8 -> V_15 = V_15 ;
return 0 ;
}
static int F_18 ( struct V_49 * V_50 )
{
struct V_7 * V_8 ;
struct V_41 * V_34 = & V_50 -> V_34 ;
struct V_27 * V_12 = V_50 -> V_34 . V_51 ;
struct V_55 V_56 = {} ;
int V_52 = 0 ;
V_8 = F_13 ( V_34 , sizeof( struct V_7 ) , V_45 ) ;
if ( ! V_8 )
return - V_57 ;
if ( F_19 ( V_58 ) && ! V_12 && V_34 -> V_44 )
V_12 = F_12 ( V_34 ) ;
if ( ! V_12 ) {
F_11 ( V_34 , L_24 ) ;
return - V_24 ;
}
V_50 -> V_34 . V_51 = V_12 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_34 = V_34 ;
F_20 ( V_50 , V_8 ) ;
if ( V_12 -> V_46 == false && V_12 -> V_47 == false ) {
F_11 ( V_34 , L_25 ) ;
return - V_24 ;
}
V_52 = F_15 ( V_50 ) ;
if ( V_52 )
return V_52 ;
V_8 -> V_35 . V_54 = L_26 ;
V_8 -> V_35 . type = ( V_8 -> V_16 ) ? V_36 :
( ( V_8 -> V_15 ) ? V_37 :
V_38 ) ;
V_8 -> V_35 . V_59 = F_1 ;
V_8 -> V_35 . V_60 = V_61 ;
V_8 -> V_35 . V_62 = F_21 ( V_61 ) ;
V_56 . V_44 = V_34 -> V_44 ;
V_56 . V_63 = V_8 ;
V_8 -> V_2 = F_22 ( V_34 , & V_8 -> V_35 , & V_56 ) ;
if ( F_23 ( V_8 -> V_2 ) ) {
F_11 ( V_34 , L_27 ) ;
return F_24 ( V_8 -> V_2 ) ;
}
if ( V_12 -> V_46 ) {
V_52 = F_25 ( V_34 , F_26 ( V_12 -> V_30 ) ,
NULL , F_5 ,
V_64 |
V_65 | V_66 ,
L_28 , V_8 ) ;
if ( V_52 ) {
F_11 ( V_34 , L_29 ,
F_26 ( V_12 -> V_30 ) , V_52 ) ;
return V_52 ;
}
}
if ( V_12 -> V_47 ) {
V_52 = F_25 ( V_34 , F_26 ( V_12 -> V_39 ) ,
NULL , F_9 ,
V_64 |
V_65 | V_66 ,
L_30 , V_8 ) ;
if ( V_52 ) {
F_11 ( V_34 , L_31 ,
F_26 ( V_12 -> V_39 ) , V_52 ) ;
return V_52 ;
}
}
if ( F_3 ( V_12 -> V_40 ) ) {
V_52 = F_25 ( V_34 , F_26 ( V_12 -> V_40 ) ,
NULL , F_10 ,
V_64 |
V_65 | V_66 ,
L_32 , V_8 ) ;
if ( V_52 ) {
F_11 ( V_34 , L_33 ,
F_26 ( V_12 -> V_40 ) , V_52 ) ;
return V_52 ;
}
}
return 0 ;
}
