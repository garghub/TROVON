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
int V_19 ;
V_9 = F_5 ( V_3 , V_2 -> V_13 , & V_11 ) ;
V_19 = V_9 -> error ;
if ( V_19 ) {
F_6 ( V_3 , F_7 ( V_9 ) , V_20 ) ;
F_8 ( L_1 ) ;
F_9 ( V_9 ) ;
return V_19 ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 , V_9 ) ;
#ifdef F_12
if ( ! ( F_13 ( V_2 ) -> V_21 & V_22 ) &&
F_14 ( V_2 , F_15 ( & V_11 ) , V_23 ) == 0 ) {
F_11 ( V_2 , NULL ) ;
V_9 = F_16 ( V_3 , V_9 , F_15 ( & V_11 ) , V_2 -> V_13 , 0 ) ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
F_11 ( V_2 , V_9 ) ;
}
#endif
V_7 = F_3 ( V_2 ) -> V_4 -> V_24 ;
if ( F_19 ( V_2 ) < V_7 &&
F_20 ( V_2 , F_21 ( V_7 - F_19 ( V_2 ) ) ,
0 , V_25 ) )
return - V_26 ;
return 0 ;
}
static void F_22 ( const struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_23 ( V_28 ) ;
if ( V_28 -> V_31 == V_32 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
V_30 -> V_17 = V_6 -> V_17 ;
V_30 -> V_18 = V_6 -> V_18 ;
V_30 -> V_16 = V_2 -> V_16 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = F_23 ( V_28 ) ;
if ( V_28 -> V_31 == V_32 ) {
const struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( ! F_25 ( & V_6 -> V_17 , & V_30 -> V_17 ) ||
! F_25 ( & V_6 -> V_18 , & V_30 -> V_18 ) ||
V_2 -> V_16 != V_30 -> V_16 )
return F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_3 , struct V_8 * * V_9 ,
struct V_33 * V_34 , bool V_35 )
{
static const struct V_36 V_37 ;
static const struct V_38 V_39 = {
. V_13 . V_14 = 1 ,
. V_40 = (struct V_36 * ) & V_37 ,
} ;
const void * V_13 = V_35 ? & V_39 : NULL ;
struct V_8 * V_41 ;
int V_19 ;
V_41 = F_5 ( V_3 , V_13 , & V_34 -> V_42 . V_43 ) ;
V_19 = V_41 -> error ;
if ( V_19 )
F_9 ( V_41 ) ;
else
* V_9 = V_41 ;
return V_19 ;
}
T_1 F_27 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_44 , T_2 V_45 )
{
const struct V_5 * V_46 = F_4 ( V_2 ) ;
T_1 V_47 = 0 ;
switch ( V_2 -> V_48 ) {
case V_49 :
if ( V_31 != V_50 && V_31 != V_51 )
break;
if ( ! F_28 ( & V_46 -> V_18 , & V_46 -> V_17 ,
V_2 -> V_52 - V_44 , V_45 ,
F_29 ( V_2 -> V_47 ,
F_30 ( V_2 , 0 ,
V_44 , 0 ) ) ) ) {
V_2 -> V_48 = V_53 ;
break;
}
case V_54 :
V_2 -> V_47 = ~ F_31 (
F_28 ( & V_46 -> V_18 , & V_46 -> V_17 ,
V_2 -> V_52 - V_44 ,
V_45 ,
F_29 ( 0 ,
F_30 ( V_2 , 0 ,
V_44 , 0 ) ) ) ) ;
V_47 = F_32 ( V_2 ) ;
}
return V_47 ;
}
static T_1 F_33 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int V_44 , unsigned int V_52 ,
T_2 V_45 )
{
const struct V_5 * V_46 = F_4 ( V_2 ) ;
T_3 V_55 ;
T_1 V_47 = 0 ;
switch ( V_2 -> V_48 ) {
case V_49 :
if ( V_52 == V_2 -> V_52 - V_44 )
return F_27 ( V_2 , V_31 , V_44 , V_45 ) ;
case V_54 :
V_55 = F_30 ( V_2 , 0 , V_44 , 0 ) ;
V_2 -> V_47 = ~ F_31 ( F_28 ( & V_46 -> V_18 ,
& V_46 -> V_17 ,
V_2 -> V_52 - V_44 ,
V_45 ,
F_29 ( 0 , V_55 ) ) ) ;
V_2 -> V_48 = V_54 ;
return F_34 ( V_2 , V_44 + V_52 ) ;
}
return V_47 ;
}
int T_4 F_35 ( void )
{
F_36 ( V_56 , & V_57 ) ;
return F_37 ( & V_58 ) ;
}
void F_38 ( void )
{
F_36 ( V_56 , NULL ) ;
F_39 ( & V_58 ) ;
}
