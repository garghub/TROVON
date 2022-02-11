int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) -> V_4 ) ;
const struct V_5 * V_6 = F_4 ( V_2 ) ;
unsigned int V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ? V_2 -> V_13 -> V_14 : 0 ,
. V_15 = V_2 -> V_16 ,
. V_17 = V_6 -> V_17 ,
. V_18 = V_6 -> V_18 ,
} ;
V_9 = F_5 ( V_3 , V_2 -> V_13 , & V_11 ) ;
if ( V_9 -> error ) {
F_6 ( V_3 , F_7 ( V_9 ) , V_19 ) ;
F_8 ( V_20 L_1 ) ;
F_9 ( V_9 ) ;
return - V_21 ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 , V_9 ) ;
#ifdef F_12
if ( ! ( F_13 ( V_2 ) -> V_22 & V_23 ) &&
F_14 ( V_2 , F_15 ( & V_11 ) , V_24 ) == 0 ) {
F_11 ( V_2 , NULL ) ;
V_9 = F_16 ( V_3 , V_9 , F_15 ( & V_11 ) , V_2 -> V_13 , 0 ) ;
if ( F_17 ( V_9 ) )
return - 1 ;
F_11 ( V_2 , V_9 ) ;
}
#endif
V_7 = F_3 ( V_2 ) -> V_4 -> V_25 ;
if ( F_18 ( V_2 ) < V_7 &&
F_19 ( V_2 , F_20 ( V_7 - F_18 ( V_2 ) ) ,
0 , V_26 ) )
return - 1 ;
return 0 ;
}
static void F_21 ( const struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ) ;
if ( V_28 -> V_31 == V_32 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
V_30 -> V_17 = V_6 -> V_17 ;
V_30 -> V_18 = V_6 -> V_18 ;
V_30 -> V_16 = V_2 -> V_16 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ) ;
if ( V_28 -> V_31 == V_32 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( ! F_24 ( & V_6 -> V_17 , & V_30 -> V_17 ) ||
! F_24 ( & V_6 -> V_18 , & V_30 -> V_18 ) ||
V_2 -> V_16 != V_30 -> V_16 )
return F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_3 , struct V_8 * * V_9 ,
struct V_33 * V_34 , bool V_35 )
{
static const struct V_36 V_37 ;
static const struct V_38 V_39 = {
. V_13 . V_14 = 1 ,
. V_40 = (struct V_36 * ) & V_37 ,
} ;
const void * V_13 = V_35 ? & V_39 : NULL ;
struct V_8 * V_41 ;
int V_42 ;
V_41 = F_5 ( V_3 , V_13 , & V_34 -> V_43 . V_44 ) ;
V_42 = V_41 -> error ;
if ( V_42 )
F_9 ( V_41 ) ;
else
* V_9 = V_41 ;
return V_42 ;
}
T_1 F_26 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_45 , T_2 V_46 )
{
const struct V_5 * V_47 = F_4 ( V_2 ) ;
T_1 V_48 = 0 ;
switch ( V_2 -> V_49 ) {
case V_50 :
if ( V_31 != V_51 && V_31 != V_52 )
break;
if ( ! F_27 ( & V_47 -> V_18 , & V_47 -> V_17 ,
V_2 -> V_53 - V_45 , V_46 ,
F_28 ( V_2 -> V_48 ,
F_29 ( V_2 , 0 ,
V_45 , 0 ) ) ) ) {
V_2 -> V_49 = V_54 ;
break;
}
case V_55 :
V_2 -> V_48 = ~ F_30 (
F_27 ( & V_47 -> V_18 , & V_47 -> V_17 ,
V_2 -> V_53 - V_45 ,
V_46 ,
F_28 ( 0 ,
F_29 ( V_2 , 0 ,
V_45 , 0 ) ) ) ) ;
V_48 = F_31 ( V_2 ) ;
}
return V_48 ;
}
static T_1 F_32 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_45 , unsigned int V_53 ,
T_2 V_46 )
{
const struct V_5 * V_47 = F_4 ( V_2 ) ;
T_3 V_56 ;
T_1 V_48 = 0 ;
switch ( V_2 -> V_49 ) {
case V_50 :
if ( V_53 == V_2 -> V_53 - V_45 )
return F_26 ( V_2 , V_31 , V_45 , V_46 ) ;
case V_55 :
V_56 = F_29 ( V_2 , 0 , V_45 , 0 ) ;
V_2 -> V_48 = ~ F_30 ( F_27 ( & V_47 -> V_18 ,
& V_47 -> V_17 ,
V_2 -> V_53 - V_45 ,
V_46 ,
F_28 ( 0 , V_56 ) ) ) ;
V_2 -> V_49 = V_55 ;
return F_33 ( V_2 , V_45 + V_53 ) ;
}
return V_48 ;
}
int T_4 F_34 ( void )
{
return F_35 ( & V_57 ) ;
}
void F_36 ( void )
{
F_37 ( & V_57 ) ;
}
