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
return 255 ;
}
STATIC int
F_2 (
struct V_5 * V_5 ,
T_1 * V_6 ,
int * V_7 ,
struct V_5 * V_8 )
{
struct V_9 * V_9 = (struct V_9 * ) V_6 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 ;
int V_1 ;
int V_12 ;
if ( ! V_8 )
V_1 = V_2 ;
else
V_1 = V_3 ;
if ( ! ( F_3 ( V_5 -> V_13 ) -> V_14 & V_15 ) ||
( F_3 ( V_5 -> V_13 ) -> V_14 & V_16 ) )
V_1 |= V_4 ;
V_12 = F_1 ( V_1 ) ;
if ( * V_7 < V_12 ) {
* V_7 = V_12 ;
return 255 ;
}
* V_7 = V_12 ;
switch ( V_1 ) {
case V_3 :
V_9 -> V_17 . V_18 = F_4 ( V_8 ) -> V_19 ;
V_9 -> V_17 . V_20 = V_8 -> V_21 ;
case V_2 :
V_9 -> V_17 . V_22 = F_4 ( V_5 ) -> V_19 ;
V_9 -> V_17 . V_23 = V_5 -> V_21 ;
break;
case V_3 | V_4 :
V_11 -> V_18 = F_4 ( V_8 ) -> V_19 ;
V_11 -> V_20 = V_8 -> V_21 ;
case V_2 | V_4 :
V_11 -> V_22 = F_4 ( V_5 ) -> V_19 ;
V_11 -> V_23 = V_5 -> V_21 ;
break;
}
return V_1 ;
}
STATIC struct V_5 *
F_5 (
struct V_24 * V_25 ,
T_2 V_22 ,
T_3 V_26 )
{
T_4 * V_27 = F_3 ( V_25 ) ;
T_5 * V_28 ;
int error ;
if ( V_22 == 0 )
return F_6 ( - V_29 ) ;
error = F_7 ( V_27 , NULL , V_22 , V_30 , 0 , & V_28 ) ;
if ( error ) {
if ( error == V_31 || error == V_32 )
error = V_29 ;
return F_6 ( - error ) ;
}
if ( V_28 -> V_33 . V_34 != V_26 ) {
F_8 ( V_28 ) ;
return F_6 ( - V_29 ) ;
}
return F_9 ( V_28 ) ;
}
STATIC struct V_35 *
F_10 ( struct V_24 * V_25 , struct V_9 * V_9 ,
int V_36 , int V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
struct V_5 * V_5 = NULL ;
if ( V_36 < F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_3 :
case V_2 :
V_5 = F_5 ( V_25 , V_9 -> V_17 . V_22 , V_9 -> V_17 . V_23 ) ;
break;
case V_3 | V_4 :
case V_2 | V_4 :
V_5 = F_5 ( V_25 , V_11 -> V_22 , V_11 -> V_23 ) ;
break;
}
return F_11 ( V_5 ) ;
}
STATIC struct V_35 *
F_12 ( struct V_24 * V_25 , struct V_9 * V_9 ,
int V_36 , int V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
struct V_5 * V_5 = NULL ;
if ( V_36 < F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_3 :
V_5 = F_5 ( V_25 , V_9 -> V_17 . V_18 ,
V_9 -> V_17 . V_20 ) ;
break;
case V_3 | V_4 :
V_5 = F_5 ( V_25 , V_11 -> V_18 ,
V_11 -> V_20 ) ;
break;
}
return F_11 ( V_5 ) ;
}
STATIC struct V_35 *
F_13 (
struct V_35 * V_37 )
{
int error ;
struct V_38 * V_39 ;
error = F_14 ( F_4 ( V_37 -> V_40 ) , & V_41 , & V_39 , NULL ) ;
if ( F_15 ( error ) )
return F_6 ( - error ) ;
return F_11 ( F_9 ( V_39 ) ) ;
}
STATIC int
F_16 (
struct V_5 * V_5 )
{
struct V_38 * V_28 = F_4 ( V_5 ) ;
struct V_42 * V_27 = V_28 -> V_43 ;
T_6 V_44 = 0 ;
F_17 ( V_28 , V_45 ) ;
if ( F_18 ( V_28 ) )
V_44 = V_28 -> V_46 -> V_47 ;
F_19 ( V_28 , V_45 ) ;
if ( ! V_44 )
return 0 ;
return F_20 ( V_27 , V_44 , V_48 , NULL ) ;
}
