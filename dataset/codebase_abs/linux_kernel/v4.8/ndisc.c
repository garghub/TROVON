static int F_1 ( T_1 V_1 )
{
return V_1 == V_2 ;
}
static int F_2 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
switch ( V_6 -> V_9 ) {
case V_10 :
if ( V_8 -> V_11 [ V_6 -> V_1 ] )
F_3 ( 2 , V_12 ,
L_1 ,
V_13 , V_6 -> V_1 ) ;
else
V_8 -> V_11 [ V_6 -> V_1 ] = V_6 ;
return 1 ;
default:
return 0 ;
}
}
static int F_4 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( ! F_5 ( V_4 , V_14 ) )
return 0 ;
switch ( V_6 -> V_1 ) {
case V_15 :
case V_16 :
return F_2 ( V_4 , V_6 , V_8 ) ;
default:
return 0 ;
}
}
static void F_6 ( struct V_17 * V_18 , T_2 V_19 ,
T_1 V_20 ,
const struct V_7 * V_8 )
{
struct V_21 * V_22 = V_21 ( F_7 ( V_18 ) ) ;
T_1 * V_23 = NULL ;
switch ( V_20 ) {
case V_24 :
case V_25 :
case V_26 :
if ( V_8 -> V_27 ) {
V_23 = F_8 ( V_8 -> V_27 ,
V_28 , 0 ) ;
if ( ! V_23 ) {
F_3 ( 2 , V_12 ,
L_2 ) ;
return;
}
}
break;
case V_29 :
case V_30 :
if ( V_8 -> V_31 ) {
V_23 = F_8 ( V_8 -> V_31 ,
V_28 , 0 ) ;
if ( ! V_23 ) {
F_3 ( 2 , V_12 ,
L_2 ) ;
return;
}
}
break;
default:
break;
}
F_9 ( & V_18 -> V_32 ) ;
if ( V_23 ) {
F_10 ( & V_22 -> V_33 , V_23 ) ;
if ( ! F_11 ( V_22 -> V_33 ) )
V_22 -> V_33 = F_12 ( V_34 ) ;
} else {
V_22 -> V_33 = F_12 ( V_34 ) ;
}
F_13 ( & V_18 -> V_32 ) ;
}
static void F_14 ( const struct V_3 * V_4 ,
struct V_17 * V_18 , T_2 V_19 , T_1 V_20 ,
const struct V_7 * V_8 )
{
if ( ! F_5 ( V_4 , V_14 ) )
return;
if ( V_19 & V_35 )
F_6 ( V_18 , V_19 , V_20 , V_8 ) ;
}
static int F_15 ( const struct V_3 * V_4 ,
T_1 V_20 , struct V_17 * V_22 ,
T_1 * V_36 , T_1 * * V_37 )
{
struct V_21 * V_18 ;
struct V_38 * V_38 ;
int V_39 = 0 ;
if ( ! F_5 ( V_4 , V_14 ) )
return 0 ;
switch ( V_20 ) {
case V_29 :
V_18 = V_21 ( F_7 ( V_22 ) ) ;
F_16 ( & V_22 -> V_32 ) ;
if ( F_11 ( V_18 -> V_33 ) ) {
memcpy ( V_36 , & V_18 -> V_33 ,
V_28 ) ;
F_17 ( & V_22 -> V_32 ) ;
V_39 += F_18 ( V_28 , 0 ) ;
* V_37 = V_36 ;
} else {
F_17 ( & V_22 -> V_32 ) ;
}
break;
case V_30 :
case V_26 :
case V_24 :
V_38 = F_19 ( V_4 ) -> V_40 -> V_41 ;
if ( F_11 ( V_38 -> V_33 ) )
V_39 = F_18 ( V_28 , 0 ) ;
break;
default:
break;
}
return V_39 ;
}
static void F_20 ( const struct V_3 * V_4 ,
struct V_42 * V_43 , T_1 V_20 ,
const T_1 * V_37 )
{
struct V_38 * V_38 ;
T_3 V_33 ;
T_1 V_44 ;
if ( ! F_5 ( V_4 , V_14 ) )
return;
switch ( V_20 ) {
case V_29 :
if ( V_37 ) {
F_21 ( & V_33 , V_37 ) ;
F_22 ( V_43 , V_16 ,
& V_33 ,
V_28 , 0 ) ;
}
return;
case V_30 :
V_44 = V_16 ;
break;
case V_24 :
case V_26 :
V_44 = V_15 ;
break;
default:
return;
}
V_38 = F_19 ( V_4 ) -> V_40 -> V_41 ;
if ( F_11 ( V_38 -> V_33 ) ) {
F_21 ( & V_33 ,
& V_38 -> V_33 ) ;
F_22 ( V_43 , V_44 , & V_33 ,
V_28 , 0 ) ;
}
}
static void F_23 ( struct V_45 * V_45 ,
struct V_3 * V_4 ,
const struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
int V_52 , T_2 V_53 ,
bool V_54 , bool V_55 ,
T_4 V_56 ,
T_2 V_57 ,
bool V_58 )
{
int V_59 ;
if ( F_5 ( V_4 , V_14 ) && V_58 &&
! F_24 ( V_51 -> V_60 + 8 , V_4 ) ) {
V_59 = F_25 ( V_45 , V_4 , V_47 , V_49 ,
V_51 , V_52 , V_53 ,
V_54 , V_55 , V_56 ,
V_57 ) ;
if ( V_59 )
F_3 ( 2 , V_12 ,
L_3 ,
& V_47 -> V_61 ) ;
}
}
