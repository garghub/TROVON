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
V_2 -> V_15 , V_16 ) ;
}
T_1
F_4 (
struct V_1 * V_2 ,
enum V_3 type )
{
T_1 V_17 ;
V_17 = V_2 -> V_10 . V_9 + V_2 -> V_8 . V_9 ;
switch ( type ) {
case V_6 :
case V_12 :
V_17 -= F_5 ( V_2 , type ) -> V_9 ;
break;
case V_18 :
break;
default:
ASSERT ( 0 ) ;
}
F_6 ( V_2 , type , V_17 ) ;
return V_17 ;
}
static int
F_7 (
struct V_1 * V_2 ,
enum V_3 type )
{
struct V_19 * V_20 ;
T_1 V_21 ;
int error ;
F_8 ( V_2 , type , 0 ) ;
V_20 = F_5 ( V_2 , type ) ;
V_2 -> V_15 -> V_22 += V_20 -> V_11 ;
if ( type == V_12 )
V_21 = V_20 -> V_23 ;
else
V_21 = V_20 -> V_9 ;
error = F_9 ( V_2 -> V_15 , V_21 , true ) ;
V_20 -> V_9 = 0 ;
V_20 -> V_11 = 0 ;
if ( error )
F_10 ( V_2 -> V_15 , V_2 -> V_24 ,
error , V_25 ) ;
return error ;
}
int
F_11 (
struct V_1 * V_2 )
{
int error ;
int V_26 ;
error = F_7 ( V_2 , V_12 ) ;
V_26 = F_7 ( V_2 , V_6 ) ;
if ( V_26 && ! error )
error = V_26 ;
return error ;
}
static int
F_12 (
struct V_1 * V_2 ,
enum V_3 type ,
T_1 V_27 ,
T_1 V_28 )
{
struct V_29 * V_30 = V_2 -> V_15 ;
struct V_19 * V_20 ;
int error ;
T_1 V_31 ;
if ( V_28 > V_27 )
V_27 = V_28 ;
V_31 = V_27 - V_28 ;
error = F_9 ( V_30 , - ( V_32 ) V_31 , true ) ;
if ( error ) {
F_13 ( V_2 -> V_15 , V_2 -> V_24 ,
error , V_25 ) ;
F_14 ( V_30 ,
L_1 ,
V_2 -> V_24 ) ;
return error ;
}
V_30 -> V_22 -= V_27 ;
V_20 = F_5 ( V_2 , type ) ;
V_20 -> V_11 = V_27 ;
V_20 -> V_9 = V_20 -> V_23 = V_31 ;
F_15 ( V_2 , type , V_27 ) ;
return 0 ;
}
int
F_16 (
struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_15 ;
T_2 V_33 = V_2 -> V_24 ;
T_1 V_27 ;
T_1 V_28 ;
int error = 0 ;
if ( V_2 -> V_10 . V_11 == 0 ) {
V_27 = V_28 = 0 ;
error = F_17 ( V_30 , V_33 , & V_27 , & V_28 ) ;
if ( error )
goto V_34;
error = F_18 ( V_30 , V_33 , & V_27 , & V_28 ) ;
if ( error )
goto V_34;
error = F_12 ( V_2 , V_6 ,
V_27 , V_28 ) ;
if ( error ) {
V_27 = V_28 = 0 ;
V_30 -> V_35 = true ;
error = F_17 ( V_30 , V_33 , & V_27 ,
& V_28 ) ;
if ( error )
goto V_34;
error = F_12 ( V_2 , V_6 ,
V_27 , V_28 ) ;
if ( error )
goto V_34;
}
}
if ( V_2 -> V_8 . V_11 == 0 ) {
V_27 = V_28 = 0 ;
error = F_19 ( V_30 , V_33 , & V_27 , & V_28 ) ;
if ( error )
goto V_34;
error = F_12 ( V_2 , V_12 , V_27 , V_28 ) ;
if ( error )
goto V_34;
}
#ifdef F_20
error = F_21 ( V_2 -> V_15 , NULL , V_2 -> V_24 , 0 ) ;
if ( error )
return error ;
ASSERT ( F_5 ( V_2 , V_6 ) -> V_9 +
F_5 ( V_2 , V_12 ) -> V_9 <=
V_2 -> V_7 + V_2 -> V_13 ) ;
#endif
V_34:
return error ;
}
void
F_22 (
struct V_1 * V_2 ,
enum V_3 type ,
struct V_36 * args )
{
struct V_19 * V_20 ;
T_1 V_17 ;
T_3 V_37 ;
F_23 ( V_2 , type , args -> V_17 ) ;
switch ( type ) {
case V_6 :
case V_12 :
V_20 = F_5 ( V_2 , type ) ;
break;
default:
ASSERT ( 0 ) ;
case V_18 :
V_37 = args -> V_38 ? V_39 :
V_40 ;
F_24 ( args -> V_41 , V_37 , - ( V_32 ) args -> V_17 ) ;
return;
}
V_17 = F_25 ( T_1 , args -> V_17 , V_20 -> V_9 ) ;
V_20 -> V_9 -= V_17 ;
if ( type == V_12 )
return;
F_24 ( args -> V_41 , V_39 , - ( V_32 ) V_17 ) ;
if ( args -> V_17 > V_17 )
F_24 ( args -> V_41 , V_40 ,
- ( ( V_32 ) args -> V_17 - V_17 ) ) ;
}
void
F_26 (
struct V_1 * V_2 ,
enum V_3 type ,
struct V_42 * V_41 ,
T_1 V_17 )
{
T_1 V_43 ;
struct V_19 * V_20 ;
F_27 ( V_2 , type , V_17 ) ;
switch ( type ) {
case V_6 :
case V_12 :
V_20 = F_5 ( V_2 , type ) ;
break;
default:
ASSERT ( 0 ) ;
case V_18 :
F_24 ( V_41 , V_40 , ( V_32 ) V_17 ) ;
return;
}
V_43 = F_25 ( T_1 , V_17 , V_20 -> V_11 - V_20 -> V_9 ) ;
V_20 -> V_9 += V_43 ;
if ( type == V_12 )
return;
F_24 ( V_41 , V_39 , V_17 ) ;
if ( V_17 > V_43 )
F_24 ( V_41 , V_40 , V_17 - V_43 ) ;
}
