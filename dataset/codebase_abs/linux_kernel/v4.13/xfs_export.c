static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return 2 ;
case V_3 :
return 4 ;
case V_2 | V_4 :
return 3 ;
case V_3 | V_4 :
return 6 ;
}
return V_5 ;
}
STATIC int
F_2 (
struct V_6 * V_6 ,
T_1 * V_7 ,
int * V_8 ,
struct V_6 * V_9 )
{
struct V_10 * V_10 = (struct V_10 * ) V_7 ;
struct V_11 * V_12 = (struct V_11 * ) V_7 ;
int V_1 ;
int V_13 ;
if ( ! V_9 )
V_1 = V_2 ;
else
V_1 = V_3 ;
if ( ! ( F_3 ( V_6 -> V_14 ) -> V_15 & V_16 ) ||
( F_3 ( V_6 -> V_14 ) -> V_15 & V_17 ) )
V_1 |= V_4 ;
V_13 = F_1 ( V_1 ) ;
if ( * V_8 < V_13 ) {
* V_8 = V_13 ;
return V_5 ;
}
* V_8 = V_13 ;
switch ( V_1 ) {
case V_3 :
V_10 -> V_18 . V_19 = F_4 ( V_9 ) -> V_20 ;
V_10 -> V_18 . V_21 = V_9 -> V_22 ;
case V_2 :
V_10 -> V_18 . V_23 = F_4 ( V_6 ) -> V_20 ;
V_10 -> V_18 . V_24 = V_6 -> V_22 ;
break;
case V_3 | V_4 :
V_12 -> V_19 = F_4 ( V_9 ) -> V_20 ;
V_12 -> V_21 = V_9 -> V_22 ;
case V_2 | V_4 :
V_12 -> V_23 = F_4 ( V_6 ) -> V_20 ;
V_12 -> V_24 = V_6 -> V_22 ;
break;
}
return V_1 ;
}
STATIC struct V_6 *
F_5 (
struct V_25 * V_26 ,
T_2 V_23 ,
T_3 V_27 )
{
T_4 * V_28 = F_3 ( V_26 ) ;
T_5 * V_29 ;
int error ;
if ( V_23 == 0 )
return F_6 ( - V_30 ) ;
error = F_7 ( V_28 , NULL , V_23 , V_31 , 0 , & V_29 ) ;
if ( error ) {
if ( error == - V_32 || error == - V_33 )
error = - V_30 ;
return F_6 ( error ) ;
}
if ( F_8 ( V_29 ) -> V_22 != V_27 ) {
F_9 ( V_29 ) ;
return F_6 ( - V_30 ) ;
}
return F_8 ( V_29 ) ;
}
STATIC struct V_34 *
F_10 ( struct V_25 * V_26 , struct V_10 * V_10 ,
int V_35 , int V_1 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
struct V_6 * V_6 = NULL ;
if ( V_35 < F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_3 :
case V_2 :
V_6 = F_5 ( V_26 , V_10 -> V_18 . V_23 , V_10 -> V_18 . V_24 ) ;
break;
case V_3 | V_4 :
case V_2 | V_4 :
V_6 = F_5 ( V_26 , V_12 -> V_23 , V_12 -> V_24 ) ;
break;
}
return F_11 ( V_6 ) ;
}
STATIC struct V_34 *
F_12 ( struct V_25 * V_26 , struct V_10 * V_10 ,
int V_35 , int V_1 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
struct V_6 * V_6 = NULL ;
if ( V_35 < F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_3 :
V_6 = F_5 ( V_26 , V_10 -> V_18 . V_19 ,
V_10 -> V_18 . V_21 ) ;
break;
case V_3 | V_4 :
V_6 = F_5 ( V_26 , V_12 -> V_19 ,
V_12 -> V_21 ) ;
break;
}
return F_11 ( V_6 ) ;
}
STATIC struct V_34 *
F_13 (
struct V_34 * V_36 )
{
int error ;
struct V_37 * V_38 ;
error = F_14 ( F_4 ( F_15 ( V_36 ) ) , & V_39 , & V_38 , NULL ) ;
if ( F_16 ( error ) )
return F_6 ( error ) ;
return F_11 ( F_8 ( V_38 ) ) ;
}
STATIC int
F_17 (
struct V_6 * V_6 )
{
struct V_37 * V_29 = F_4 ( V_6 ) ;
struct V_40 * V_28 = V_29 -> V_41 ;
T_6 V_42 = 0 ;
F_18 ( V_29 , V_43 ) ;
if ( F_19 ( V_29 ) )
V_42 = V_29 -> V_44 -> V_45 ;
F_20 ( V_29 , V_43 ) ;
if ( ! V_42 )
return 0 ;
return F_21 ( V_28 , V_42 , V_46 , NULL ) ;
}
