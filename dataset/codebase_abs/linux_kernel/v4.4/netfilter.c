int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 = {
. V_11 = V_3 -> V_12 ? V_3 -> V_12 -> V_13 : 0 ,
. V_14 = V_3 -> V_15 ,
. V_16 = V_5 -> V_16 ,
. V_17 = V_5 -> V_17 ,
} ;
int V_18 ;
V_8 = F_3 ( V_1 , V_3 -> V_12 , & V_10 ) ;
V_18 = V_8 -> error ;
if ( V_18 ) {
F_4 ( V_1 , F_5 ( V_8 ) , V_19 ) ;
F_6 ( L_1 ) ;
F_7 ( V_8 ) ;
return V_18 ;
}
F_8 ( V_3 ) ;
F_9 ( V_3 , V_8 ) ;
#ifdef F_10
if ( ! ( F_11 ( V_3 ) -> V_20 & V_21 ) &&
F_12 ( V_3 , F_13 ( & V_10 ) , V_22 ) == 0 ) {
F_9 ( V_3 , NULL ) ;
V_8 = F_14 ( V_1 , V_8 , F_13 ( & V_10 ) , V_3 -> V_12 , 0 ) ;
if ( F_15 ( V_8 ) )
return F_16 ( V_8 ) ;
F_9 ( V_3 , V_8 ) ;
}
#endif
V_6 = F_17 ( V_3 ) -> V_23 -> V_24 ;
if ( F_18 ( V_3 ) < V_6 &&
F_19 ( V_3 , F_20 ( V_6 - F_18 ( V_3 ) ) ,
0 , V_25 ) )
return - V_26 ;
return 0 ;
}
static void F_21 ( const struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ) ;
if ( V_28 -> V_31 . V_32 == V_33 ) {
const struct V_4 * V_5 = F_2 ( V_3 ) ;
V_30 -> V_16 = V_5 -> V_16 ;
V_30 -> V_17 = V_5 -> V_17 ;
V_30 -> V_15 = V_3 -> V_15 ;
}
}
static int F_23 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ) ;
if ( V_28 -> V_31 . V_32 == V_33 ) {
const struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( ! F_24 ( & V_5 -> V_16 , & V_30 -> V_16 ) ||
! F_24 ( & V_5 -> V_17 , & V_30 -> V_17 ) ||
V_3 -> V_15 != V_30 -> V_15 )
return F_1 ( V_1 , V_3 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 , struct V_7 * * V_8 ,
struct V_34 * V_35 , bool V_36 )
{
static const struct V_37 V_38 ;
static const struct V_39 V_40 = {
. V_12 . V_13 = 1 ,
. V_41 = (struct V_37 * ) & V_38 ,
} ;
const void * V_12 = V_36 ? & V_40 : NULL ;
struct V_7 * V_42 ;
int V_18 ;
V_42 = F_3 ( V_1 , V_12 , & V_35 -> V_43 . V_44 ) ;
V_18 = V_42 -> error ;
if ( V_18 )
F_7 ( V_42 ) ;
else
* V_8 = V_42 ;
return V_18 ;
}
T_1 F_26 ( struct V_2 * V_3 , unsigned int V_32 ,
unsigned int V_45 , T_2 V_46 )
{
const struct V_4 * V_47 = F_2 ( V_3 ) ;
T_1 V_48 = 0 ;
switch ( V_3 -> V_49 ) {
case V_50 :
if ( V_32 != V_51 && V_32 != V_52 )
break;
if ( ! F_27 ( & V_47 -> V_17 , & V_47 -> V_16 ,
V_3 -> V_53 - V_45 , V_46 ,
F_28 ( V_3 -> V_48 ,
F_29 ( V_3 , 0 ,
V_45 , 0 ) ) ) ) {
V_3 -> V_49 = V_54 ;
break;
}
case V_55 :
V_3 -> V_48 = ~ F_30 (
F_27 ( & V_47 -> V_17 , & V_47 -> V_16 ,
V_3 -> V_53 - V_45 ,
V_46 ,
F_28 ( 0 ,
F_29 ( V_3 , 0 ,
V_45 , 0 ) ) ) ) ;
V_48 = F_31 ( V_3 ) ;
}
return V_48 ;
}
static T_1 F_32 ( struct V_2 * V_3 , unsigned int V_32 ,
unsigned int V_45 , unsigned int V_53 ,
T_2 V_46 )
{
const struct V_4 * V_47 = F_2 ( V_3 ) ;
T_3 V_56 ;
T_1 V_48 = 0 ;
switch ( V_3 -> V_49 ) {
case V_50 :
if ( V_53 == V_3 -> V_53 - V_45 )
return F_26 ( V_3 , V_32 , V_45 , V_46 ) ;
case V_55 :
V_56 = F_29 ( V_3 , 0 , V_45 , 0 ) ;
V_3 -> V_48 = ~ F_30 ( F_27 ( & V_47 -> V_17 ,
& V_47 -> V_16 ,
V_3 -> V_53 - V_45 ,
V_46 ,
F_28 ( 0 , V_56 ) ) ) ;
V_3 -> V_49 = V_55 ;
return F_33 ( V_3 , V_45 + V_53 ) ;
}
return V_48 ;
}
int T_4 F_34 ( void )
{
F_35 ( V_57 , & V_58 ) ;
return F_36 ( & V_59 ) ;
}
void F_37 ( void )
{
F_35 ( V_57 , NULL ) ;
F_38 ( & V_59 ) ;
}
