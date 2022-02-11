bool
F_1 (
struct V_1 * V_2 ,
enum V_3 type )
{
T_1 V_4 ;
T_1 V_5 ;
switch ( type ) {
case V_6 :
V_4 = V_2 -> V_7 - V_2 -> V_8 . V_9 ;
V_5 = V_2 -> V_10 . V_11 ;
break;
case V_12 :
V_4 = V_2 -> V_7 + V_2 -> V_13 -
V_2 -> V_10 . V_9 ;
V_5 = V_2 -> V_8 . V_11 ;
break;
default:
ASSERT ( 0 ) ;
return false ;
}
F_2 ( V_2 , type , V_4 ) ;
return F_3 ( V_4 < V_5 / 10 || V_4 < V_14 ,
V_2 -> V_15 , V_16 ,
V_17 ) ;
}
T_1
F_4 (
struct V_1 * V_2 ,
enum V_3 type )
{
T_1 V_18 ;
V_18 = V_2 -> V_10 . V_9 + V_2 -> V_8 . V_9 ;
switch ( type ) {
case V_6 :
case V_12 :
V_18 -= F_5 ( V_2 , type ) -> V_9 ;
break;
case V_19 :
break;
default:
ASSERT ( 0 ) ;
}
F_6 ( V_2 , type , V_18 ) ;
return V_18 ;
}
static int
F_7 (
struct V_1 * V_2 ,
enum V_3 type )
{
struct V_20 * V_21 ;
T_1 V_22 ;
int error ;
F_8 ( V_2 , type , 0 ) ;
V_21 = F_5 ( V_2 , type ) ;
V_2 -> V_15 -> V_23 += V_21 -> V_11 ;
if ( type == V_12 )
V_22 = V_21 -> V_24 ;
else
V_22 = V_21 -> V_9 ;
error = F_9 ( V_2 -> V_15 , V_22 , true ) ;
V_21 -> V_9 = 0 ;
V_21 -> V_11 = 0 ;
if ( error )
F_10 ( V_2 -> V_15 , V_2 -> V_25 ,
error , V_26 ) ;
return error ;
}
int
F_11 (
struct V_1 * V_2 )
{
int error ;
int V_27 ;
error = F_7 ( V_2 , V_12 ) ;
V_27 = F_7 ( V_2 , V_6 ) ;
if ( V_27 && ! error )
error = V_27 ;
return error ;
}
static int
F_12 (
struct V_1 * V_2 ,
enum V_3 type ,
T_1 V_28 ,
T_1 V_29 )
{
struct V_30 * V_31 = V_2 -> V_15 ;
struct V_20 * V_21 ;
int error ;
T_1 V_32 ;
if ( V_29 > V_28 )
V_28 = V_29 ;
V_32 = V_28 - V_29 ;
error = F_9 ( V_31 , - ( V_33 ) V_32 , true ) ;
if ( error ) {
F_13 ( V_2 -> V_15 , V_2 -> V_25 ,
error , V_26 ) ;
F_14 ( V_31 ,
L_1 ,
V_2 -> V_25 ) ;
return error ;
}
V_31 -> V_23 -= V_28 ;
V_21 = F_5 ( V_2 , type ) ;
V_21 -> V_11 = V_28 ;
V_21 -> V_9 = V_21 -> V_24 = V_32 ;
F_15 ( V_2 , type , V_28 ) ;
return 0 ;
}
int
F_16 (
struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_15 ;
T_2 V_34 = V_2 -> V_25 ;
T_1 V_28 ;
T_1 V_29 ;
int error = 0 ;
if ( V_2 -> V_10 . V_11 == 0 ) {
V_28 = V_29 = 0 ;
error = F_17 ( V_31 , V_34 , & V_28 , & V_29 ) ;
if ( error )
goto V_35;
error = F_18 ( V_31 , V_34 , & V_28 , & V_29 ) ;
if ( error )
goto V_35;
error = F_12 ( V_2 , V_6 ,
V_28 , V_29 ) ;
if ( error ) {
V_28 = V_29 = 0 ;
V_31 -> V_36 = true ;
error = F_17 ( V_31 , V_34 , & V_28 ,
& V_29 ) ;
if ( error )
goto V_35;
error = F_12 ( V_2 , V_6 ,
V_28 , V_29 ) ;
if ( error )
goto V_35;
}
}
if ( V_2 -> V_8 . V_11 == 0 ) {
V_28 = V_29 = 0 ;
error = F_19 ( V_31 , V_34 , & V_28 , & V_29 ) ;
if ( error )
goto V_35;
error = F_12 ( V_2 , V_12 , V_28 , V_29 ) ;
if ( error )
goto V_35;
}
#ifdef F_20
error = F_21 ( V_2 -> V_15 , NULL , V_2 -> V_25 , 0 ) ;
if ( error )
return error ;
ASSERT ( F_5 ( V_2 , V_6 ) -> V_9 +
F_5 ( V_2 , V_12 ) -> V_9 <=
V_2 -> V_7 + V_2 -> V_13 ) ;
#endif
V_35:
return error ;
}
void
F_22 (
struct V_1 * V_2 ,
enum V_3 type ,
struct V_37 * args )
{
struct V_20 * V_21 ;
T_1 V_18 ;
T_3 V_38 ;
F_23 ( V_2 , type , args -> V_18 ) ;
switch ( type ) {
case V_6 :
case V_12 :
V_21 = F_5 ( V_2 , type ) ;
break;
default:
ASSERT ( 0 ) ;
case V_19 :
V_38 = args -> V_39 ? V_40 :
V_41 ;
F_24 ( args -> V_42 , V_38 , - ( V_33 ) args -> V_18 ) ;
return;
}
V_18 = F_25 ( T_1 , args -> V_18 , V_21 -> V_9 ) ;
V_21 -> V_9 -= V_18 ;
if ( type == V_12 )
return;
F_24 ( args -> V_42 , V_40 , - ( V_33 ) V_18 ) ;
if ( args -> V_18 > V_18 )
F_24 ( args -> V_42 , V_41 ,
- ( ( V_33 ) args -> V_18 - V_18 ) ) ;
}
void
F_26 (
struct V_1 * V_2 ,
enum V_3 type ,
struct V_43 * V_42 ,
T_1 V_18 )
{
T_1 V_44 ;
struct V_20 * V_21 ;
F_27 ( V_2 , type , V_18 ) ;
switch ( type ) {
case V_6 :
case V_12 :
V_21 = F_5 ( V_2 , type ) ;
break;
default:
ASSERT ( 0 ) ;
case V_19 :
F_24 ( V_42 , V_41 , ( V_33 ) V_18 ) ;
return;
}
V_44 = F_25 ( T_1 , V_18 , V_21 -> V_11 - V_21 -> V_9 ) ;
V_21 -> V_9 += V_44 ;
if ( type == V_12 )
return;
F_24 ( V_42 , V_40 , V_18 ) ;
if ( V_18 > V_44 )
F_24 ( V_42 , V_41 , V_18 - V_44 ) ;
}
