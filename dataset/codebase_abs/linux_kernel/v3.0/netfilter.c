int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) -> V_4 ) ;
const struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 V_10 = {
. V_11 = V_2 -> V_12 ? V_2 -> V_12 -> V_13 : 0 ,
. V_14 = V_2 -> V_15 ,
. V_16 = V_6 -> V_16 ,
. V_17 = V_6 -> V_17 ,
} ;
V_8 = F_5 ( V_3 , V_2 -> V_12 , & V_10 ) ;
if ( V_8 -> error ) {
F_6 ( V_3 , F_7 ( V_8 ) , V_18 ) ;
F_8 ( V_19 L_1 ) ;
F_9 ( V_8 ) ;
return - V_20 ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 , V_8 ) ;
#ifdef F_12
if ( ! ( F_13 ( V_2 ) -> V_21 & V_22 ) &&
F_14 ( V_2 , F_15 ( & V_10 ) , V_23 ) == 0 ) {
F_11 ( V_2 , NULL ) ;
V_8 = F_16 ( V_3 , V_8 , F_15 ( & V_10 ) , V_2 -> V_12 , 0 ) ;
if ( F_17 ( V_8 ) )
return - 1 ;
F_11 ( V_2 , V_8 ) ;
}
#endif
return 0 ;
}
static void F_18 ( const struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
if ( V_25 -> V_28 == V_29 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
V_27 -> V_16 = V_6 -> V_16 ;
V_27 -> V_17 = V_6 -> V_17 ;
V_27 -> V_15 = V_2 -> V_15 ;
}
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
if ( V_25 -> V_28 == V_29 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( ! F_21 ( & V_6 -> V_16 , & V_27 -> V_16 ) ||
! F_21 ( & V_6 -> V_17 , & V_27 -> V_17 ) ||
V_2 -> V_15 != V_27 -> V_15 )
return F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , struct V_7 * * V_8 ,
struct V_30 * V_31 , bool V_32 )
{
static const struct V_33 V_34 ;
static const struct V_35 V_36 = {
. V_12 . V_13 = 1 ,
. V_37 = (struct V_33 * ) & V_34 ,
} ;
const void * V_12 = V_32 ? & V_36 : NULL ;
* V_8 = F_5 ( V_3 , V_12 , & V_31 -> V_38 . V_39 ) ;
return ( * V_8 ) -> error ;
}
T_1 F_23 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int V_40 , T_2 V_41 )
{
const struct V_5 * V_42 = F_4 ( V_2 ) ;
T_1 V_43 = 0 ;
switch ( V_2 -> V_44 ) {
case V_45 :
if ( V_28 != V_46 && V_28 != V_47 )
break;
if ( ! F_24 ( & V_42 -> V_17 , & V_42 -> V_16 ,
V_2 -> V_48 - V_40 , V_41 ,
F_25 ( V_2 -> V_43 ,
F_26 ( V_2 , 0 ,
V_40 , 0 ) ) ) ) {
V_2 -> V_44 = V_49 ;
break;
}
case V_50 :
V_2 -> V_43 = ~ F_27 (
F_24 ( & V_42 -> V_17 , & V_42 -> V_16 ,
V_2 -> V_48 - V_40 ,
V_41 ,
F_25 ( 0 ,
F_26 ( V_2 , 0 ,
V_40 , 0 ) ) ) ) ;
V_43 = F_28 ( V_2 ) ;
}
return V_43 ;
}
static T_1 F_29 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int V_40 , unsigned int V_48 ,
T_2 V_41 )
{
const struct V_5 * V_42 = F_4 ( V_2 ) ;
T_3 V_51 ;
T_1 V_43 = 0 ;
switch ( V_2 -> V_44 ) {
case V_45 :
if ( V_48 == V_2 -> V_48 - V_40 )
return F_23 ( V_2 , V_28 , V_40 , V_41 ) ;
case V_50 :
V_51 = F_26 ( V_2 , 0 , V_40 , 0 ) ;
V_2 -> V_43 = ~ F_27 ( F_24 ( & V_42 -> V_17 ,
& V_42 -> V_16 ,
V_2 -> V_48 - V_40 ,
V_41 ,
F_25 ( 0 , V_51 ) ) ) ;
V_2 -> V_44 = V_50 ;
return F_30 ( V_2 , V_40 + V_48 ) ;
}
return V_43 ;
}
int T_4 F_31 ( void )
{
return F_32 ( & V_52 ) ;
}
void F_33 ( void )
{
F_34 ( & V_52 ) ;
}
