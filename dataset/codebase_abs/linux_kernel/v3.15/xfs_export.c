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
if ( error == V_32 || error == V_33 )
error = V_30 ;
return F_6 ( - error ) ;
}
if ( V_29 -> V_34 . V_35 != V_27 ) {
F_8 ( V_29 ) ;
return F_6 ( - V_30 ) ;
}
return F_9 ( V_29 ) ;
}
STATIC struct V_36 *
F_10 ( struct V_25 * V_26 , struct V_10 * V_10 ,
int V_37 , int V_1 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
struct V_6 * V_6 = NULL ;
if ( V_37 < F_1 ( V_1 ) )
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
STATIC struct V_36 *
F_12 ( struct V_25 * V_26 , struct V_10 * V_10 ,
int V_37 , int V_1 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
struct V_6 * V_6 = NULL ;
if ( V_37 < F_1 ( V_1 ) )
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
STATIC struct V_36 *
F_13 (
struct V_36 * V_38 )
{
int error ;
struct V_39 * V_40 ;
error = F_14 ( F_4 ( V_38 -> V_41 ) , & V_42 , & V_40 , NULL ) ;
if ( F_15 ( error ) )
return F_6 ( - error ) ;
return F_11 ( F_9 ( V_40 ) ) ;
}
STATIC int
F_16 (
struct V_6 * V_6 )
{
struct V_39 * V_29 = F_4 ( V_6 ) ;
struct V_43 * V_28 = V_29 -> V_44 ;
T_6 V_45 = 0 ;
F_17 ( V_29 , V_46 ) ;
if ( F_18 ( V_29 ) )
V_45 = V_29 -> V_47 -> V_48 ;
F_19 ( V_29 , V_46 ) ;
if ( ! V_45 )
return 0 ;
return - F_20 ( V_28 , V_45 , V_49 , NULL ) ;
}
