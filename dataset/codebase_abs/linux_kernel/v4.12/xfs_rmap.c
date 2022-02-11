int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 ,
int * V_8 )
{
V_2 -> V_9 . V_10 . V_11 = V_3 ;
V_2 -> V_9 . V_10 . V_12 = V_4 ;
V_2 -> V_9 . V_10 . V_13 = V_5 ;
V_2 -> V_9 . V_10 . V_14 = V_6 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
return F_2 ( V_2 , V_16 , V_8 ) ;
}
int
F_3 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 ,
int * V_8 )
{
V_2 -> V_9 . V_10 . V_11 = V_3 ;
V_2 -> V_9 . V_10 . V_12 = V_4 ;
V_2 -> V_9 . V_10 . V_13 = V_5 ;
V_2 -> V_9 . V_10 . V_14 = V_6 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
return F_2 ( V_2 , V_17 , V_8 ) ;
}
STATIC int
F_4 (
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
union V_20 V_21 ;
int error ;
F_5 ( V_2 -> V_22 , V_2 -> V_23 . V_24 . V_25 ,
V_19 -> V_11 , V_19 -> V_12 ,
V_19 -> V_13 , V_19 -> V_14 , V_19 -> V_15 ) ;
V_21 . V_26 . V_11 = F_6 ( V_19 -> V_11 ) ;
V_21 . V_26 . V_12 = F_6 ( V_19 -> V_12 ) ;
V_21 . V_26 . V_13 = F_7 ( V_19 -> V_13 ) ;
V_21 . V_26 . V_14 = F_7 (
F_8 ( V_19 ) ) ;
error = F_9 ( V_2 , & V_21 ) ;
if ( error )
F_10 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
int
F_11 (
struct V_1 * V_28 ,
T_1 V_29 ,
T_2 V_4 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 )
{
int V_30 ;
int error ;
F_12 ( V_28 -> V_22 , V_28 -> V_23 . V_24 . V_25 , V_29 ,
V_4 , V_5 , V_6 , V_7 ) ;
error = F_3 ( V_28 , V_29 , V_4 , V_5 , V_6 , V_7 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_28 -> V_22 , V_30 == 0 , V_31 ) ;
V_28 -> V_9 . V_10 . V_11 = V_29 ;
V_28 -> V_9 . V_10 . V_12 = V_4 ;
V_28 -> V_9 . V_10 . V_13 = V_5 ;
V_28 -> V_9 . V_10 . V_14 = V_6 ;
V_28 -> V_9 . V_10 . V_15 = V_7 ;
error = F_14 ( V_28 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_28 -> V_22 , V_30 == 1 , V_31 ) ;
V_31:
if ( error )
F_15 ( V_28 -> V_22 ,
V_28 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_16 (
struct V_1 * V_28 ,
T_1 V_29 ,
T_2 V_4 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 )
{
int V_30 ;
int error ;
F_17 ( V_28 -> V_22 , V_28 -> V_23 . V_24 . V_25 , V_29 ,
V_4 , V_5 , V_6 , V_7 ) ;
error = F_3 ( V_28 , V_29 , V_4 , V_5 , V_6 , V_7 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_28 -> V_22 , V_30 == 1 , V_31 ) ;
error = F_18 ( V_28 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_28 -> V_22 , V_30 == 1 , V_31 ) ;
V_31:
if ( error )
F_19 ( V_28 -> V_22 ,
V_28 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
static int
F_20 (
union V_20 * V_21 ,
struct V_18 * V_19 )
{
V_19 -> V_15 = 0 ;
V_19 -> V_11 = F_21 ( V_21 -> V_26 . V_11 ) ;
V_19 -> V_12 = F_21 ( V_21 -> V_26 . V_12 ) ;
V_19 -> V_13 = F_22 ( V_21 -> V_26 . V_13 ) ;
return F_23 ( F_22 ( V_21 -> V_26 . V_14 ) ,
V_19 ) ;
}
int
F_24 (
struct V_1 * V_2 ,
struct V_18 * V_19 ,
int * V_8 )
{
union V_20 * V_21 ;
int error ;
error = F_25 ( V_2 , & V_21 , V_8 ) ;
if ( error || ! * V_8 )
return error ;
return F_20 ( V_21 , V_19 ) ;
}
STATIC int
F_26 (
struct V_1 * V_2 ,
struct V_18 * V_21 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
F_27 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_21 -> V_11 ,
V_21 -> V_12 , V_21 -> V_13 , V_21 -> V_14 ,
V_21 -> V_15 ) ;
if ( V_21 -> V_13 != V_34 -> V_35 . V_13 )
return V_36 ;
if ( ! F_28 ( V_21 -> V_13 ) &&
! ( V_21 -> V_15 & V_37 ) &&
V_21 -> V_14 + V_21 -> V_12 - 1 != V_34 -> V_35 . V_14 )
return V_36 ;
* V_34 -> V_19 = * V_21 ;
* V_34 -> V_8 = 1 ;
return V_38 ;
}
int
F_29 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 ,
struct V_18 * V_19 ,
int * V_8 )
{
struct V_33 V_34 ;
int error ;
* V_8 = 0 ;
if ( V_3 == 0 )
return 0 ;
V_34 . V_35 . V_11 = V_3 - 1 ;
V_34 . V_35 . V_13 = V_5 ;
if ( ! F_28 ( V_5 ) &&
! ( V_7 & V_37 ) ) {
if ( V_6 == 0 )
return 0 ;
V_34 . V_35 . V_14 = V_6 - 1 ;
} else
V_34 . V_35 . V_14 = 0 ;
V_34 . V_35 . V_15 = V_7 ;
V_34 . V_35 . V_12 = 0 ;
V_34 . V_19 = V_19 ;
V_34 . V_8 = V_8 ;
F_30 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_3 , 0 , V_5 , V_6 , V_7 ) ;
error = F_31 ( V_2 , & V_34 . V_35 , & V_34 . V_35 ,
F_26 , & V_34 ) ;
if ( error == V_38 )
error = 0 ;
if ( * V_8 )
F_32 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_19 -> V_11 ,
V_19 -> V_12 , V_19 -> V_13 ,
V_19 -> V_14 , V_19 -> V_15 ) ;
return error ;
}
STATIC int
F_33 (
struct V_1 * V_2 ,
struct V_18 * V_21 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
F_34 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_21 -> V_11 ,
V_21 -> V_12 , V_21 -> V_13 , V_21 -> V_14 ,
V_21 -> V_15 ) ;
if ( V_21 -> V_13 != V_34 -> V_35 . V_13 )
return V_36 ;
if ( ! F_28 ( V_21 -> V_13 ) &&
! ( V_21 -> V_15 & V_37 ) &&
( V_21 -> V_14 > V_34 -> V_35 . V_14 ||
V_21 -> V_14 + V_21 -> V_12 <= V_34 -> V_35 . V_14 ) )
return V_36 ;
* V_34 -> V_19 = * V_21 ;
* V_34 -> V_8 = 1 ;
return V_38 ;
}
int
F_35 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_5 ,
T_3 V_6 ,
unsigned int V_7 ,
struct V_18 * V_19 ,
int * V_8 )
{
struct V_33 V_34 ;
int error ;
V_34 . V_35 . V_11 = V_3 ;
V_34 . V_35 . V_13 = V_5 ;
if ( ! F_28 ( V_5 ) && ! ( V_7 & V_37 ) )
V_34 . V_35 . V_14 = V_6 ;
else
V_34 . V_35 . V_14 = 0 ;
V_34 . V_35 . V_15 = V_7 ;
V_34 . V_35 . V_12 = 0 ;
* V_8 = 0 ;
V_34 . V_19 = V_19 ;
V_34 . V_8 = V_8 ;
F_36 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_3 , 0 , V_5 , V_6 , V_7 ) ;
error = F_31 ( V_2 , & V_34 . V_35 , & V_34 . V_35 ,
F_33 , & V_34 ) ;
if ( error == V_38 )
error = 0 ;
if ( * V_8 )
F_37 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_19 -> V_11 ,
V_19 -> V_12 , V_19 -> V_13 ,
V_19 -> V_14 , V_19 -> V_15 ) ;
return error ;
}
STATIC int
F_38 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_44 ;
T_3 V_45 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 ;
bool V_46 ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
V_46 = F_28 ( V_5 ) ||
( V_7 & V_37 ) ;
if ( V_39 )
V_7 |= V_47 ;
F_40 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
error = F_24 ( V_2 , & V_44 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
F_37 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 ) ;
V_45 = V_44 . V_14 ;
if ( V_5 == V_49 ) {
F_13 ( V_43 , V_3 >= V_44 . V_11 +
V_44 . V_12 , V_48 ) ;
goto V_50;
}
F_13 ( V_43 , ( V_7 & V_47 ) ==
( V_44 . V_15 & V_47 ) , V_48 ) ;
F_13 ( V_43 , V_44 . V_11 <= V_3 &&
V_44 . V_11 + V_44 . V_12 >=
V_3 + V_4 , V_48 ) ;
F_13 ( V_43 , V_5 == V_44 . V_13 ||
F_28 ( V_5 ) , V_48 ) ;
if ( ! F_28 ( V_5 ) ) {
if ( V_7 & V_37 ) {
F_13 ( V_43 ,
V_44 . V_15 & V_37 ,
V_48 ) ;
} else {
F_13 ( V_43 ,
V_44 . V_14 <= V_6 , V_48 ) ;
F_13 ( V_43 ,
V_45 + V_44 . V_12 >= V_6 + V_4 ,
V_48 ) ;
}
}
if ( V_44 . V_11 == V_3 && V_44 . V_12 == V_4 ) {
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_44 . V_11 , V_44 . V_12 ,
V_44 . V_13 , V_44 . V_14 ,
V_44 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
} else if ( V_44 . V_11 == V_3 ) {
V_44 . V_11 += V_4 ;
V_44 . V_12 -= V_4 ;
if ( ! V_46 )
V_44 . V_14 += V_4 ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
} else if ( V_44 . V_11 + V_44 . V_12 == V_3 + V_4 ) {
V_44 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
} else {
T_2 V_51 = V_44 . V_12 ;
V_44 . V_12 = V_3 - V_44 . V_11 ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_48;
V_2 -> V_9 . V_10 . V_11 = V_3 + V_4 ;
V_2 -> V_9 . V_10 . V_12 = V_51 - V_4 -
V_44 . V_12 ;
V_2 -> V_9 . V_10 . V_13 = V_44 . V_13 ;
if ( V_46 )
V_2 -> V_9 . V_10 . V_14 = 0 ;
else
V_2 -> V_9 . V_10 . V_14 = V_6 + V_4 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_2 -> V_9 . V_10 . V_11 ,
V_2 -> V_9 . V_10 . V_12 ,
V_2 -> V_9 . V_10 . V_13 ,
V_2 -> V_9 . V_10 . V_14 ,
V_2 -> V_9 . V_10 . V_15 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_48;
}
V_50:
F_42 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_48:
if ( error )
F_43 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
error , V_27 ) ;
return error ;
}
int
F_44 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_53 -> V_56 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_45 ( & V_43 -> V_57 ) )
return 0 ;
V_2 = F_46 ( V_43 , V_53 , V_55 , V_25 ) ;
error = F_38 ( V_2 , V_3 , V_4 , false , V_41 ) ;
if ( error )
goto V_48;
F_47 ( V_2 , V_58 ) ;
return 0 ;
V_48:
F_47 ( V_2 , V_59 ) ;
return error ;
}
static bool
F_48 (
struct V_18 * V_19 ,
T_3 V_5 ,
unsigned int V_7 )
{
if ( V_19 -> V_13 == V_49 )
return false ;
if ( V_19 -> V_13 != V_5 )
return false ;
if ( ( V_7 & V_47 ) ^
( V_19 -> V_15 & V_47 ) )
return false ;
if ( ( V_7 & V_60 ) ^
( V_19 -> V_15 & V_60 ) )
return false ;
if ( ( V_7 & V_37 ) ^
( V_19 -> V_15 & V_37 ) )
return false ;
return true ;
}
STATIC int
F_49 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_44 ;
struct V_18 V_61 ;
int V_62 ;
int V_63 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 = 0 ;
bool V_46 ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
ASSERT ( V_5 != 0 ) ;
V_46 = F_28 ( V_5 ) ||
( V_7 & V_37 ) ;
if ( V_39 )
V_7 |= V_47 ;
F_50 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_63 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_63 == 1 , V_48 ) ;
error = F_24 ( V_2 , & V_44 , & V_63 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_63 == 1 , V_48 ) ;
F_37 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 ) ;
if ( ! F_48 ( & V_44 , V_5 , V_7 ) )
V_63 = 0 ;
F_13 ( V_43 ,
V_63 == 0 ||
V_44 . V_11 + V_44 . V_12 <= V_3 , V_48 ) ;
error = F_41 ( V_2 , 0 , & V_62 ) ;
if ( error )
goto V_48;
if ( V_62 ) {
error = F_24 ( V_2 , & V_61 , & V_62 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_62 == 1 , V_48 ) ;
F_13 ( V_43 , V_3 + V_4 <= V_61 . V_11 ,
V_48 ) ;
F_51 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_61 . V_11 ,
V_61 . V_12 , V_61 . V_13 ,
V_61 . V_14 , V_61 . V_15 ) ;
if ( ! F_48 ( & V_61 , V_5 , V_7 ) )
V_62 = 0 ;
}
if ( V_63 &&
V_44 . V_11 + V_44 . V_12 == V_3 &&
( V_46 || V_44 . V_14 + V_44 . V_12 == V_6 ) ) {
V_44 . V_12 += V_4 ;
if ( V_62 &&
V_3 + V_4 == V_61 . V_11 &&
( V_46 || V_6 + V_4 == V_61 . V_14 ) &&
( unsigned long ) V_44 . V_12 + V_4 +
V_61 . V_12 <= V_64 ) {
V_44 . V_12 += V_61 . V_12 ;
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_61 . V_11 ,
V_61 . V_12 ,
V_61 . V_13 ,
V_61 . V_14 ,
V_61 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
}
error = F_52 ( V_2 , 0 , & V_62 ) ;
if ( error )
goto V_48;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
} else if ( V_62 &&
V_3 + V_4 == V_61 . V_11 &&
( V_46 || V_6 + V_4 == V_61 . V_14 ) ) {
V_61 . V_11 = V_3 ;
V_61 . V_12 += V_4 ;
if ( ! V_46 )
V_61 . V_14 = V_6 ;
error = F_4 ( V_2 , & V_61 ) ;
if ( error )
goto V_48;
} else {
V_2 -> V_9 . V_10 . V_11 = V_3 ;
V_2 -> V_9 . V_10 . V_12 = V_4 ;
V_2 -> V_9 . V_10 . V_13 = V_5 ;
V_2 -> V_9 . V_10 . V_14 = V_6 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
}
F_53 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_48:
if ( error )
F_54 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
error , V_27 ) ;
return error ;
}
int
F_55 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_53 -> V_56 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_45 ( & V_43 -> V_57 ) )
return 0 ;
V_2 = F_46 ( V_43 , V_53 , V_55 , V_25 ) ;
error = F_49 ( V_2 , V_3 , V_4 , false , V_41 ) ;
if ( error )
goto V_48;
F_47 ( V_2 , V_58 ) ;
return 0 ;
V_48:
F_47 ( V_2 , V_59 ) ;
return error ;
}
STATIC int
F_56 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_10 [ 4 ] ;
T_3 V_5 ;
T_3 V_6 ;
T_3 V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_7 = 0 ;
int V_30 ;
int V_68 = 0 ;
int error ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
ASSERT ( ! ( F_28 ( V_5 ) ||
( V_7 & ( V_60 | V_37 ) ) ) ) ;
V_66 = V_39 ? V_47 : 0 ;
V_65 = V_6 + V_4 ;
F_57 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_66 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_24 ( V_2 , & V_69 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_37 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_69 . V_11 ,
V_69 . V_12 , V_69 . V_13 ,
V_69 . V_14 , V_69 . V_15 ) ;
ASSERT ( V_69 . V_14 <= V_6 ) ;
ASSERT ( V_69 . V_14 + V_69 . V_12 >= V_65 ) ;
ASSERT ( ( V_69 . V_15 & V_47 ) == V_66 ) ;
V_67 = ~ V_66 & V_47 ;
if ( V_69 . V_14 == V_6 )
V_68 |= V_70 ;
if ( V_69 . V_14 + V_69 . V_12 == V_65 )
V_68 |= V_71 ;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_68 |= V_72 ;
error = F_24 ( V_2 , & V_73 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_13 ( V_43 ,
V_73 . V_11 + V_73 . V_12 <= V_3 ,
V_31 ) ;
F_32 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_73 . V_11 ,
V_73 . V_12 , V_73 . V_13 ,
V_73 . V_14 , V_73 . V_15 ) ;
if ( V_73 . V_11 + V_73 . V_12 == V_3 &&
V_73 . V_14 + V_73 . V_12 == V_6 &&
F_48 ( & V_73 , V_5 , V_67 ) )
V_68 |= V_74 ;
}
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_68 |= V_75 ;
error = F_24 ( V_2 , & V_76 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_13 ( V_43 , V_3 + V_4 <= V_76 . V_11 ,
V_31 ) ;
F_51 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_76 . V_11 ,
V_76 . V_12 , V_76 . V_13 ,
V_76 . V_14 , V_76 . V_15 ) ;
if ( V_3 + V_4 == V_76 . V_11 &&
V_6 + V_4 == V_76 . V_14 &&
F_48 ( & V_76 , V_5 , V_67 ) )
V_68 |= V_77 ;
}
if ( ( V_68 & ( V_70 | V_74 |
V_71 | V_77 ) ) ==
( V_70 | V_74 |
V_71 | V_77 ) &&
( unsigned long ) V_73 . V_12 + V_4 +
V_76 . V_12 > V_64 )
V_68 &= ~ V_77 ;
F_58 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_68 ,
V_27 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_66 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
switch ( V_68 & ( V_70 | V_74 |
V_71 | V_77 ) ) {
case V_70 | V_74 |
V_71 | V_77 :
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_76 . V_11 , V_76 . V_12 ,
V_76 . V_13 , V_76 . V_14 ,
V_76 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_69 . V_11 , V_69 . V_12 ,
V_69 . V_13 , V_69 . V_14 ,
V_69 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 = V_73 ;
V_78 . V_12 += V_69 . V_12 + V_76 . V_12 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 | V_74 :
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_69 . V_11 , V_69 . V_12 ,
V_69 . V_13 , V_69 . V_14 ,
V_69 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 = V_73 ;
V_78 . V_12 += V_69 . V_12 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 | V_77 :
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_17 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_76 . V_11 , V_76 . V_12 ,
V_76 . V_13 , V_76 . V_14 ,
V_76 . V_15 ) ;
error = F_18 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 = V_69 ;
V_78 . V_12 = V_4 + V_76 . V_12 ;
V_78 . V_15 = V_67 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 :
V_78 = V_69 ;
V_78 . V_15 = V_67 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_74 :
V_78 = V_69 ;
V_78 . V_14 += V_4 ;
V_78 . V_11 += V_4 ;
V_78 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
error = F_52 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
V_78 = V_73 ;
V_78 . V_12 += V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 :
V_78 = V_69 ;
V_78 . V_11 += V_4 ;
V_78 . V_14 += V_4 ;
V_78 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
V_78 . V_11 = V_3 ;
V_78 . V_13 = V_5 ;
V_78 . V_14 = V_6 ;
V_78 . V_12 = V_4 ;
V_78 . V_15 = V_67 ;
V_2 -> V_9 . V_10 = V_78 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 ,
V_4 , V_5 , V_6 , V_67 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
break;
case V_71 | V_77 :
V_78 = V_69 ;
V_78 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
error = F_41 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
V_78 = V_76 ;
V_78 . V_14 = V_6 ;
V_78 . V_11 = V_3 ;
V_78 . V_12 += V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_71 :
V_78 = V_69 ;
V_78 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
error = F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_66 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 0 , V_31 ) ;
V_78 . V_11 = V_3 ;
V_78 . V_13 = V_5 ;
V_78 . V_14 = V_6 ;
V_78 . V_12 = V_4 ;
V_78 . V_15 = V_67 ;
V_2 -> V_9 . V_10 = V_78 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 ,
V_4 , V_5 , V_6 , V_67 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
break;
case 0 :
V_78 . V_11 = V_3 + V_4 ;
V_78 . V_13 = V_5 ;
V_78 . V_14 = V_65 ;
V_78 . V_12 = V_69 . V_14 + V_69 . V_12 -
V_65 ;
V_78 . V_15 = V_69 . V_15 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
V_78 = V_69 ;
V_78 . V_12 = V_6 - V_69 . V_14 ;
V_2 -> V_9 . V_10 = V_78 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 ,
V_78 . V_11 , V_78 . V_12 ,
V_78 . V_13 , V_78 . V_14 ,
V_78 . V_15 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
error = F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_66 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 0 , V_31 ) ;
V_2 -> V_9 . V_10 . V_15 &= ~ V_47 ;
V_2 -> V_9 . V_10 . V_15 |= V_67 ;
F_12 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_5 , V_6 , V_67 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
break;
case V_70 | V_74 | V_77 :
case V_71 | V_74 | V_77 :
case V_70 | V_77 :
case V_71 | V_74 :
case V_74 | V_77 :
case V_74 :
case V_77 :
ASSERT ( 0 ) ;
}
F_59 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_31:
if ( error )
F_60 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_61 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_10 [ 4 ] ;
T_3 V_5 ;
T_3 V_6 ;
T_3 V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_7 = 0 ;
int V_30 ;
int V_68 = 0 ;
int error ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
ASSERT ( ! ( F_28 ( V_5 ) ||
( V_7 & ( V_60 | V_37 ) ) ) ) ;
V_66 = V_39 ? V_47 : 0 ;
V_65 = V_6 + V_4 ;
F_57 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_35 ( V_2 , V_3 , V_5 , V_6 , V_7 ,
& V_69 , & V_30 ) ;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
ASSERT ( V_69 . V_14 <= V_6 ) ;
ASSERT ( V_69 . V_14 + V_69 . V_12 >= V_65 ) ;
ASSERT ( ( V_69 . V_15 & V_47 ) == V_66 ) ;
V_67 = ~ V_66 & V_47 ;
if ( V_69 . V_14 == V_6 )
V_68 |= V_70 ;
if ( V_69 . V_14 + V_69 . V_12 == V_65 )
V_68 |= V_71 ;
error = F_29 ( V_2 , V_3 , V_5 , V_6 , V_67 ,
& V_73 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_68 |= V_72 ;
F_13 ( V_43 ,
V_73 . V_11 + V_73 . V_12 <= V_3 ,
V_31 ) ;
if ( F_48 ( & V_73 , V_5 , V_67 ) )
V_68 |= V_74 ;
}
error = F_3 ( V_2 , V_3 + V_4 , V_4 , V_5 , V_6 + V_4 ,
V_67 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_68 |= V_75 ;
error = F_24 ( V_2 , & V_76 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
F_13 ( V_43 , V_3 + V_4 <= V_76 . V_11 ,
V_31 ) ;
F_51 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_76 . V_11 ,
V_76 . V_12 , V_76 . V_13 ,
V_76 . V_14 , V_76 . V_15 ) ;
if ( F_48 ( & V_76 , V_5 , V_67 ) )
V_68 |= V_77 ;
}
if ( ( V_68 & ( V_70 | V_74 |
V_71 | V_77 ) ) ==
( V_70 | V_74 |
V_71 | V_77 ) &&
( unsigned long ) V_73 . V_12 + V_4 +
V_76 . V_12 > V_64 )
V_68 &= ~ V_77 ;
F_58 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_68 ,
V_27 ) ;
switch ( V_68 & ( V_70 | V_74 |
V_71 | V_77 ) ) {
case V_70 | V_74 |
V_71 | V_77 :
error = F_16 ( V_2 , V_76 . V_11 ,
V_76 . V_12 , V_76 . V_13 ,
V_76 . V_14 , V_76 . V_15 ) ;
if ( error )
goto V_31;
error = F_16 ( V_2 , V_69 . V_11 ,
V_69 . V_12 , V_69 . V_13 ,
V_69 . V_14 , V_69 . V_15 ) ;
if ( error )
goto V_31;
V_78 = V_73 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 += V_69 . V_12 + V_76 . V_12 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 | V_74 :
error = F_16 ( V_2 , V_69 . V_11 ,
V_69 . V_12 , V_69 . V_13 ,
V_69 . V_14 , V_69 . V_15 ) ;
if ( error )
goto V_31;
V_78 = V_73 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 += V_69 . V_12 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 | V_77 :
error = F_16 ( V_2 , V_76 . V_11 ,
V_76 . V_12 , V_76 . V_13 ,
V_76 . V_14 , V_76 . V_15 ) ;
if ( error )
goto V_31;
V_78 = V_69 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 += V_76 . V_12 ;
V_78 . V_15 = V_76 . V_15 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_71 :
V_78 = V_69 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_15 = V_67 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_74 :
V_78 = V_69 ;
error = F_16 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
V_78 . V_14 += V_4 ;
V_78 . V_11 += V_4 ;
V_78 . V_12 -= V_4 ;
error = F_11 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
V_78 = V_73 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 += V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
break;
case V_70 :
V_78 = V_69 ;
error = F_16 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
V_78 . V_14 += V_4 ;
V_78 . V_11 += V_4 ;
V_78 . V_12 -= V_4 ;
error = F_11 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
error = F_11 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_67 ) ;
if ( error )
goto V_31;
break;
case V_71 | V_77 :
V_78 = V_69 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 = V_6 - V_78 . V_14 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
V_78 = V_76 ;
error = F_16 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
V_78 . V_14 = V_6 ;
V_78 . V_11 = V_3 ;
V_78 . V_12 += V_4 ;
error = F_11 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 ) ;
if ( error )
goto V_31;
break;
case V_71 :
V_78 = V_69 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
error = F_11 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_67 ) ;
if ( error )
goto V_31;
break;
case 0 :
V_78 . V_11 = V_3 + V_4 ;
V_78 . V_13 = V_5 ;
V_78 . V_14 = V_65 ;
V_78 . V_12 = V_69 . V_14 + V_69 . V_12 -
V_65 ;
V_78 . V_15 = V_69 . V_15 ;
error = F_11 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 , V_78 . V_14 ,
V_78 . V_15 ) ;
if ( error )
goto V_31;
V_78 = V_69 ;
error = F_3 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 ,
V_78 . V_14 , V_78 . V_15 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_43 , V_30 == 1 , V_31 ) ;
V_78 . V_12 = V_6 - V_78 . V_14 ;
error = F_4 ( V_2 , & V_78 ) ;
if ( error )
goto V_31;
V_78 . V_11 = V_3 ;
V_78 . V_12 = V_4 ;
V_78 . V_13 = V_5 ;
V_78 . V_14 = V_6 ;
V_78 . V_15 = V_67 ;
error = F_11 ( V_2 , V_78 . V_11 ,
V_78 . V_12 , V_78 . V_13 , V_78 . V_14 ,
V_78 . V_15 ) ;
if ( error )
goto V_31;
break;
case V_70 | V_74 | V_77 :
case V_71 | V_74 | V_77 :
case V_70 | V_77 :
case V_71 | V_74 :
case V_74 | V_77 :
case V_74 :
case V_77 :
ASSERT ( 0 ) ;
}
F_59 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_31:
if ( error )
F_60 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_62 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_44 ;
T_3 V_45 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
if ( V_39 )
V_7 |= V_47 ;
F_40 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_35 ( V_2 , V_3 , V_5 , V_6 , V_7 ,
& V_44 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
V_45 = V_44 . V_14 ;
F_13 ( V_43 , V_44 . V_11 <= V_3 &&
V_44 . V_11 + V_44 . V_12 >=
V_3 + V_4 , V_48 ) ;
F_13 ( V_43 , V_5 == V_44 . V_13 , V_48 ) ;
F_13 ( V_43 , ( V_7 & V_47 ) ==
( V_44 . V_15 & V_47 ) , V_48 ) ;
F_13 ( V_43 , V_44 . V_14 <= V_6 , V_48 ) ;
F_13 ( V_43 , V_6 <= V_45 + V_44 . V_12 ,
V_48 ) ;
if ( V_44 . V_11 == V_3 && V_44 . V_12 == V_4 ) {
error = F_16 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 ) ;
if ( error )
goto V_48;
} else if ( V_44 . V_11 == V_3 ) {
error = F_16 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 ) ;
if ( error )
goto V_48;
V_44 . V_11 += V_4 ;
V_44 . V_12 -= V_4 ;
V_44 . V_14 += V_4 ;
error = F_11 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 ) ;
if ( error )
goto V_48;
} else if ( V_44 . V_11 + V_44 . V_12 == V_3 + V_4 ) {
error = F_3 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
V_44 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
} else {
T_2 V_51 = V_44 . V_12 ;
error = F_3 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
V_44 . V_12 = V_3 - V_44 . V_11 ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
error = F_11 ( V_2 , V_3 + V_4 ,
V_51 - V_4 - V_44 . V_12 ,
V_44 . V_13 , V_6 + V_4 ,
V_44 . V_15 ) ;
if ( error )
goto V_48;
}
F_42 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_48:
if ( error )
F_43 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_63 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_22 ;
struct V_18 V_44 ;
struct V_18 V_61 ;
int V_62 ;
int V_63 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 = 0 ;
F_39 ( V_41 , & V_5 , & V_6 , & V_7 ) ;
if ( V_39 )
V_7 |= V_47 ;
F_50 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
error = F_29 ( V_2 , V_3 , V_5 , V_6 , V_7 ,
& V_44 , & V_63 ) ;
if ( error )
goto V_48;
if ( V_63 &&
! F_48 ( & V_44 , V_5 , V_7 ) )
V_63 = 0 ;
error = F_3 ( V_2 , V_3 + V_4 , V_4 , V_5 , V_6 + V_4 ,
V_7 , & V_62 ) ;
if ( error )
goto V_48;
if ( V_62 ) {
error = F_24 ( V_2 , & V_61 , & V_62 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_62 == 1 , V_48 ) ;
F_51 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_61 . V_11 ,
V_61 . V_12 , V_61 . V_13 ,
V_61 . V_14 , V_61 . V_15 ) ;
if ( ! F_48 ( & V_61 , V_5 , V_7 ) )
V_62 = 0 ;
}
if ( V_63 &&
V_44 . V_11 + V_44 . V_12 == V_3 &&
V_44 . V_14 + V_44 . V_12 == V_6 ) {
V_44 . V_12 += V_4 ;
if ( V_62 &&
V_3 + V_4 == V_61 . V_11 &&
V_6 + V_4 == V_61 . V_14 ) {
V_44 . V_12 += V_61 . V_12 ;
error = F_16 ( V_2 , V_61 . V_11 ,
V_61 . V_12 , V_61 . V_13 ,
V_61 . V_14 , V_61 . V_15 ) ;
if ( error )
goto V_48;
}
error = F_3 ( V_2 , V_44 . V_11 ,
V_44 . V_12 , V_44 . V_13 ,
V_44 . V_14 , V_44 . V_15 , & V_30 ) ;
if ( error )
goto V_48;
F_13 ( V_43 , V_30 == 1 , V_48 ) ;
error = F_4 ( V_2 , & V_44 ) ;
if ( error )
goto V_48;
} else if ( V_62 &&
V_3 + V_4 == V_61 . V_11 &&
V_6 + V_4 == V_61 . V_14 ) {
error = F_16 ( V_2 , V_61 . V_11 ,
V_61 . V_12 , V_61 . V_13 ,
V_61 . V_14 , V_61 . V_15 ) ;
if ( error )
goto V_48;
V_61 . V_11 = V_3 ;
V_61 . V_12 += V_4 ;
V_61 . V_14 = V_6 ;
error = F_11 ( V_2 , V_61 . V_11 ,
V_61 . V_12 , V_61 . V_13 ,
V_61 . V_14 , V_61 . V_15 ) ;
if ( error )
goto V_48;
} else {
error = F_11 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( error )
goto V_48;
}
F_53 ( V_43 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_39 , V_41 ) ;
V_48:
if ( error )
F_54 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_64 (
struct V_1 * V_2 ,
union V_20 * V_21 ,
void * V_32 )
{
struct V_79 * V_80 = V_32 ;
struct V_18 V_19 ;
int error ;
error = F_20 ( V_21 , & V_19 ) ;
if ( error )
return error ;
return V_80 -> V_81 ( V_2 , & V_19 , V_80 -> V_32 ) ;
}
int
F_31 (
struct V_1 * V_2 ,
struct V_18 * V_82 ,
struct V_18 * V_83 ,
T_5 V_81 ,
void * V_32 )
{
union V_84 V_85 ;
union V_84 V_86 ;
struct V_79 V_80 ;
V_85 . V_10 = * V_82 ;
V_86 . V_10 = * V_83 ;
V_80 . V_32 = V_32 ;
V_80 . V_81 = V_81 ;
return F_65 ( V_2 , & V_85 , & V_86 ,
F_64 , & V_80 ) ;
}
int
F_66 (
struct V_1 * V_2 ,
T_5 V_81 ,
void * V_32 )
{
struct V_79 V_80 ;
V_80 . V_32 = V_32 ;
V_80 . V_81 = V_81 ;
return F_67 ( V_2 , F_64 , & V_80 ) ;
}
void
F_68 (
struct V_52 * V_53 ,
struct V_1 * V_28 ,
int error )
{
struct V_54 * V_55 ;
if ( V_28 == NULL )
return;
V_55 = V_28 -> V_23 . V_24 . V_55 ;
F_47 ( V_28 , error ? V_59 : V_58 ) ;
if ( error )
F_69 ( V_53 , V_55 ) ;
}
int
F_70 (
struct V_52 * V_53 ,
enum V_87 type ,
T_6 V_5 ,
int V_88 ,
T_7 V_89 ,
T_8 V_90 ,
T_9 V_91 ,
T_10 V_68 ,
struct V_1 * * V_92 )
{
struct V_42 * V_43 = V_53 -> V_56 ;
struct V_1 * V_28 ;
struct V_54 * V_55 = NULL ;
int error = 0 ;
T_4 V_25 ;
struct V_40 V_41 ;
T_1 V_3 ;
bool V_39 ;
V_25 = F_71 ( V_43 , V_90 ) ;
ASSERT ( V_25 != V_93 ) ;
V_3 = F_72 ( V_43 , V_90 ) ;
F_73 ( V_43 , V_25 , type , V_3 , V_5 , V_88 ,
V_89 , V_91 , V_68 ) ;
if ( F_74 ( false , V_43 ,
V_94 ,
V_95 ) )
return - V_96 ;
V_28 = * V_92 ;
if ( V_28 != NULL && V_28 -> V_23 . V_24 . V_25 != V_25 ) {
F_68 ( V_53 , V_28 , 0 ) ;
V_28 = NULL ;
* V_92 = NULL ;
}
if ( V_28 == NULL ) {
error = F_75 ( V_53 , V_25 , & V_55 ) ;
if ( error )
return error ;
if ( ! V_55 )
return - V_97 ;
V_28 = F_46 ( V_43 , V_53 , V_55 , V_25 ) ;
if ( ! V_28 ) {
error = - V_98 ;
goto V_99;
}
}
* V_92 = V_28 ;
F_76 ( & V_41 , V_5 , V_88 , V_89 ) ;
V_39 = V_68 == V_100 ;
V_3 = F_72 ( V_28 -> V_22 , V_90 ) ;
switch ( type ) {
case V_101 :
case V_102 :
error = F_49 ( V_28 , V_3 , V_91 , V_39 , & V_41 ) ;
break;
case V_103 :
error = F_63 ( V_28 , V_3 , V_91 , V_39 ,
& V_41 ) ;
break;
case V_104 :
case V_105 :
error = F_38 ( V_28 , V_3 , V_91 , V_39 ,
& V_41 ) ;
break;
case V_106 :
error = F_62 ( V_28 , V_3 , V_91 , V_39 ,
& V_41 ) ;
break;
case V_107 :
error = F_56 ( V_28 , V_3 , V_91 , ! V_39 ,
& V_41 ) ;
break;
case V_108 :
error = F_61 ( V_28 , V_3 , V_91 ,
! V_39 , & V_41 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_97 ;
}
return error ;
V_99:
F_69 ( V_53 , V_55 ) ;
return error ;
}
static bool
F_77 (
struct V_42 * V_43 ,
int V_88 )
{
return F_45 ( & V_43 -> V_57 ) && V_88 != V_109 ;
}
static int
F_78 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
enum V_87 type ,
T_6 V_5 ,
int V_88 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 ;
F_79 ( V_43 , F_71 ( V_43 , V_113 -> V_116 ) ,
type ,
F_72 ( V_43 , V_113 -> V_116 ) ,
V_5 , V_88 ,
V_113 -> V_117 ,
V_113 -> V_118 ,
V_113 -> V_119 ) ;
V_115 = F_80 ( sizeof( struct V_114 ) , V_120 | V_121 ) ;
F_81 ( & V_115 -> V_122 ) ;
V_115 -> V_123 = type ;
V_115 -> V_124 = V_5 ;
V_115 -> V_125 = V_88 ;
V_115 -> V_126 = * V_113 ;
F_82 ( V_111 , V_127 , & V_115 -> V_122 ) ;
return 0 ;
}
int
F_83 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
struct V_128 * V_129 ,
int V_88 ,
struct V_112 * V_69 )
{
if ( ! F_77 ( V_43 , V_88 ) )
return 0 ;
return F_78 ( V_43 , V_111 , F_84 ( V_129 ) ?
V_103 : V_102 , V_129 -> V_130 ,
V_88 , V_69 ) ;
}
int
F_85 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
struct V_128 * V_129 ,
int V_88 ,
struct V_112 * V_69 )
{
if ( ! F_77 ( V_43 , V_88 ) )
return 0 ;
return F_78 ( V_43 , V_111 , F_84 ( V_129 ) ?
V_106 : V_105 , V_129 -> V_130 ,
V_88 , V_69 ) ;
}
int
F_86 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
struct V_128 * V_129 ,
int V_88 ,
struct V_112 * V_69 )
{
if ( ! F_77 ( V_43 , V_88 ) )
return 0 ;
return F_78 ( V_43 , V_111 , F_84 ( V_129 ) ?
V_108 : V_107 , V_129 -> V_130 ,
V_88 , V_69 ) ;
}
int
F_87 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_6 V_5 )
{
struct V_112 V_113 ;
if ( ! F_77 ( V_43 , V_131 ) )
return 0 ;
V_113 . V_116 = F_88 ( V_43 , V_25 , V_3 ) ;
V_113 . V_118 = V_4 ;
V_113 . V_117 = 0 ;
V_113 . V_119 = V_132 ;
return F_78 ( V_43 , V_111 , V_101 , V_5 ,
V_131 , & V_113 ) ;
}
int
F_89 (
struct V_42 * V_43 ,
struct V_110 * V_111 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_6 V_5 )
{
struct V_112 V_113 ;
if ( ! F_77 ( V_43 , V_131 ) )
return 0 ;
V_113 . V_116 = F_88 ( V_43 , V_25 , V_3 ) ;
V_113 . V_118 = V_4 ;
V_113 . V_117 = 0 ;
V_113 . V_119 = V_132 ;
return F_78 ( V_43 , V_111 , V_104 , V_5 ,
V_131 , & V_113 ) ;
}
int
F_90 (
const struct V_18 * V_24 ,
const struct V_18 * V_133 )
{
T_11 V_134 ;
T_11 V_135 ;
V_134 = F_8 ( V_24 ) ;
V_135 = F_8 ( V_133 ) ;
if ( V_24 -> V_11 < V_133 -> V_11 )
return - 1 ;
else if ( V_24 -> V_11 > V_133 -> V_11 )
return 1 ;
else if ( V_24 -> V_13 < V_133 -> V_13 )
return - 1 ;
else if ( V_24 -> V_13 > V_133 -> V_13 )
return 1 ;
else if ( V_134 < V_135 )
return - 1 ;
else if ( V_134 > V_135 )
return 1 ;
else
return 0 ;
}
