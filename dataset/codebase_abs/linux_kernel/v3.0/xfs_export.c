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
int V_8 )
{
struct V_9 * V_9 = (struct V_9 * ) V_6 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 ;
struct V_12 * V_12 = V_5 -> V_13 ;
int V_1 ;
int V_14 ;
if ( F_3 ( V_12 -> V_15 ) || ! V_8 )
V_1 = V_2 ;
else
V_1 = V_3 ;
if ( ! ( F_4 ( V_12 -> V_16 ) -> V_17 & V_18 ) ||
( F_4 ( V_12 -> V_16 ) -> V_17 & V_19 ) )
V_1 |= V_4 ;
V_14 = F_1 ( V_1 ) ;
if ( * V_7 < V_14 ) {
* V_7 = V_14 ;
return 255 ;
}
* V_7 = V_14 ;
switch ( V_1 ) {
case V_3 :
F_5 ( & V_5 -> V_20 ) ;
V_9 -> V_21 . V_22 = V_5 -> V_23 -> V_13 -> V_24 ;
V_9 -> V_21 . V_25 = V_5 -> V_23 -> V_13 -> V_26 ;
F_6 ( & V_5 -> V_20 ) ;
case V_2 :
V_9 -> V_21 . V_27 = V_12 -> V_24 ;
V_9 -> V_21 . V_28 = V_12 -> V_26 ;
break;
case V_3 | V_4 :
F_5 ( & V_5 -> V_20 ) ;
V_11 -> V_22 = V_5 -> V_23 -> V_13 -> V_24 ;
V_11 -> V_25 = V_5 -> V_23 -> V_13 -> V_26 ;
F_6 ( & V_5 -> V_20 ) ;
case V_2 | V_4 :
V_11 -> V_27 = V_12 -> V_24 ;
V_11 -> V_28 = V_12 -> V_26 ;
break;
}
return V_1 ;
}
STATIC struct V_12 *
F_7 (
struct V_29 * V_30 ,
T_2 V_27 ,
T_3 V_31 )
{
T_4 * V_32 = F_4 ( V_30 ) ;
T_5 * V_33 ;
int error ;
if ( V_27 == 0 )
return F_8 ( - V_34 ) ;
error = F_9 ( V_32 , NULL , V_27 , V_35 , 0 , & V_33 ) ;
if ( error ) {
if ( error == V_36 )
error = V_34 ;
return F_8 ( - error ) ;
}
if ( V_33 -> V_37 . V_38 != V_31 ) {
F_10 ( V_33 ) ;
return F_8 ( - V_39 ) ;
}
return F_11 ( V_33 ) ;
}
STATIC struct V_5 *
F_12 ( struct V_29 * V_30 , struct V_9 * V_9 ,
int V_40 , int V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
struct V_12 * V_12 = NULL ;
if ( V_40 < F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_3 :
case V_2 :
V_12 = F_7 ( V_30 , V_9 -> V_21 . V_27 , V_9 -> V_21 . V_28 ) ;
break;
case V_3 | V_4 :
case V_2 | V_4 :
V_12 = F_7 ( V_30 , V_11 -> V_27 , V_11 -> V_28 ) ;
break;
}
return F_13 ( V_12 ) ;
}
STATIC struct V_5 *
F_14 ( struct V_29 * V_30 , struct V_9 * V_9 ,
int V_40 , int V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
struct V_12 * V_12 = NULL ;
switch ( V_1 ) {
case V_3 :
V_12 = F_7 ( V_30 , V_9 -> V_21 . V_22 ,
V_9 -> V_21 . V_25 ) ;
break;
case V_3 | V_4 :
V_12 = F_7 ( V_30 , V_11 -> V_22 ,
V_11 -> V_25 ) ;
break;
}
return F_13 ( V_12 ) ;
}
STATIC struct V_5 *
F_15 (
struct V_5 * V_41 )
{
int error ;
struct V_42 * V_43 ;
error = F_16 ( F_17 ( V_41 -> V_13 ) , & V_44 , & V_43 , NULL ) ;
if ( F_18 ( error ) )
return F_8 ( - error ) ;
return F_13 ( F_11 ( V_43 ) ) ;
}
STATIC int
F_19 (
struct V_12 * V_12 )
{
struct V_42 * V_33 = F_17 ( V_12 ) ;
struct V_45 * V_32 = V_33 -> V_46 ;
int error = 0 ;
F_20 ( V_33 , V_47 ) ;
if ( F_21 ( V_33 ) ) {
error = F_22 ( V_32 , V_33 -> V_48 -> V_49 ,
V_50 , NULL ) ;
}
F_23 ( V_33 , V_47 ) ;
return error ;
}
