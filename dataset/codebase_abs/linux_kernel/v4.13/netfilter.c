int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 = {
. V_11 = V_3 -> V_12 ? V_3 -> V_12 -> V_13 : 0 ,
. V_14 = V_3 -> V_15 ,
. V_16 = F_3 ( V_1 , V_3 -> V_12 ) ,
. V_17 = V_5 -> V_17 ,
. V_18 = V_5 -> V_18 ,
} ;
int V_19 ;
V_8 = F_4 ( V_1 , V_3 -> V_12 , & V_10 ) ;
V_19 = V_8 -> error ;
if ( V_19 ) {
F_5 ( V_1 , F_6 ( V_8 ) , V_20 ) ;
F_7 ( L_1 ) ;
F_8 ( V_8 ) ;
return V_19 ;
}
F_9 ( V_3 ) ;
F_10 ( V_3 , V_8 ) ;
#ifdef F_11
if ( ! ( F_12 ( V_3 ) -> V_21 & V_22 ) &&
F_13 ( V_3 , F_14 ( & V_10 ) , V_23 ) == 0 ) {
F_10 ( V_3 , NULL ) ;
V_8 = F_15 ( V_1 , V_8 , F_14 ( & V_10 ) , V_3 -> V_12 , 0 ) ;
if ( F_16 ( V_8 ) )
return F_17 ( V_8 ) ;
F_10 ( V_3 , V_8 ) ;
}
#endif
V_6 = F_18 ( V_3 ) -> V_24 -> V_25 ;
if ( F_19 ( V_3 ) < V_6 &&
F_20 ( V_3 , F_21 ( V_6 - F_19 ( V_3 ) ) ,
0 , V_26 ) )
return - V_27 ;
return 0 ;
}
static void F_22 ( const struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_23 ( V_29 ) ;
if ( V_29 -> V_32 . V_33 == V_34 ) {
const struct V_4 * V_5 = F_2 ( V_3 ) ;
V_31 -> V_17 = V_5 -> V_17 ;
V_31 -> V_18 = V_5 -> V_18 ;
V_31 -> V_15 = V_3 -> V_15 ;
}
}
static int F_24 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_28 * V_29 )
{
struct V_30 * V_31 = F_23 ( V_29 ) ;
if ( V_29 -> V_32 . V_33 == V_34 ) {
const struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( ! F_25 ( & V_5 -> V_17 , & V_31 -> V_17 ) ||
! F_25 ( & V_5 -> V_18 , & V_31 -> V_18 ) ||
V_3 -> V_15 != V_31 -> V_15 )
return F_1 ( V_1 , V_3 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_7 * * V_8 ,
struct V_35 * V_36 , bool V_37 )
{
static const struct V_38 V_39 ;
static const struct V_40 V_41 = {
. V_12 . V_13 = 1 ,
. V_42 = (struct V_38 * ) & V_39 ,
} ;
const void * V_12 = V_37 ? & V_41 : NULL ;
struct V_7 * V_43 ;
int V_19 ;
V_43 = F_4 ( V_1 , V_12 , & V_36 -> V_44 . V_45 ) ;
V_19 = V_43 -> error ;
if ( V_19 )
F_8 ( V_43 ) ;
else
* V_8 = V_43 ;
return V_19 ;
}
T_1 F_27 ( struct V_2 * V_3 , unsigned int V_33 ,
unsigned int V_46 , T_2 V_47 )
{
const struct V_4 * V_48 = F_2 ( V_3 ) ;
T_1 V_49 = 0 ;
switch ( V_3 -> V_50 ) {
case V_51 :
if ( V_33 != V_52 && V_33 != V_53 )
break;
if ( ! F_28 ( & V_48 -> V_18 , & V_48 -> V_17 ,
V_3 -> V_54 - V_46 , V_47 ,
F_29 ( V_3 -> V_49 ,
F_30 ( V_3 , 0 ,
V_46 , 0 ) ) ) ) {
V_3 -> V_50 = V_55 ;
break;
}
case V_56 :
V_3 -> V_49 = ~ F_31 (
F_28 ( & V_48 -> V_18 , & V_48 -> V_17 ,
V_3 -> V_54 - V_46 ,
V_47 ,
F_29 ( 0 ,
F_30 ( V_3 , 0 ,
V_46 , 0 ) ) ) ) ;
V_49 = F_32 ( V_3 ) ;
}
return V_49 ;
}
static T_1 F_33 ( struct V_2 * V_3 , unsigned int V_33 ,
unsigned int V_46 , unsigned int V_54 ,
T_2 V_47 )
{
const struct V_4 * V_48 = F_2 ( V_3 ) ;
T_3 V_57 ;
T_1 V_49 = 0 ;
switch ( V_3 -> V_50 ) {
case V_51 :
if ( V_54 == V_3 -> V_54 - V_46 )
return F_27 ( V_3 , V_33 , V_46 , V_47 ) ;
case V_56 :
V_57 = F_30 ( V_3 , 0 , V_46 , 0 ) ;
V_3 -> V_49 = ~ F_31 ( F_28 ( & V_48 -> V_18 ,
& V_48 -> V_17 ,
V_3 -> V_54 - V_46 ,
V_47 ,
F_29 ( 0 , V_57 ) ) ) ;
V_3 -> V_50 = V_56 ;
return F_34 ( V_3 , V_46 + V_54 ) ;
}
return V_49 ;
}
int T_4 F_35 ( void )
{
F_36 ( V_58 , & V_59 ) ;
return F_37 ( & V_60 ) ;
}
void F_38 ( void )
{
F_36 ( V_58 , NULL ) ;
F_39 ( & V_60 ) ;
}
