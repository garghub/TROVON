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
static int
F_16 (
union V_20 * V_21 ,
struct V_18 * V_19 )
{
V_19 -> V_15 = 0 ;
V_19 -> V_11 = F_17 ( V_21 -> V_26 . V_11 ) ;
V_19 -> V_12 = F_17 ( V_21 -> V_26 . V_12 ) ;
V_19 -> V_13 = F_18 ( V_21 -> V_26 . V_13 ) ;
return F_19 ( F_18 ( V_21 -> V_26 . V_14 ) ,
V_19 ) ;
}
int
F_20 (
struct V_1 * V_2 ,
struct V_18 * V_19 ,
int * V_8 )
{
union V_20 * V_21 ;
int error ;
error = F_21 ( V_2 , & V_21 , V_8 ) ;
if ( error || ! * V_8 )
return error ;
return F_16 ( V_21 , V_19 ) ;
}
STATIC int
F_22 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_22 ;
struct V_18 V_37 ;
T_3 V_38 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 ;
bool V_39 ;
F_23 ( V_34 , & V_5 , & V_6 , & V_7 ) ;
V_39 = F_24 ( V_5 ) ||
( V_7 & V_40 ) ;
if ( V_32 )
V_7 |= V_41 ;
F_25 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 , & V_30 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_30 == 1 , V_42 ) ;
error = F_20 ( V_2 , & V_37 , & V_30 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_30 == 1 , V_42 ) ;
F_26 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_37 . V_11 ,
V_37 . V_12 , V_37 . V_13 ,
V_37 . V_14 , V_37 . V_15 ) ;
V_38 = V_37 . V_14 ;
if ( V_5 == V_43 ) {
F_13 ( V_36 , V_3 >= V_37 . V_11 +
V_37 . V_12 , V_42 ) ;
goto V_44;
}
F_13 ( V_36 , ( V_7 & V_41 ) ==
( V_37 . V_15 & V_41 ) , V_42 ) ;
F_13 ( V_36 , V_37 . V_11 <= V_3 &&
V_37 . V_11 + V_37 . V_12 >=
V_3 + V_4 , V_42 ) ;
F_13 ( V_36 , V_5 == V_37 . V_13 ||
F_24 ( V_5 ) , V_42 ) ;
if ( ! F_24 ( V_5 ) ) {
if ( V_7 & V_40 ) {
F_13 ( V_36 ,
V_37 . V_15 & V_40 ,
V_42 ) ;
} else {
F_13 ( V_36 ,
V_37 . V_14 <= V_6 , V_42 ) ;
F_13 ( V_36 ,
V_38 + V_37 . V_12 >= V_6 + V_4 ,
V_42 ) ;
}
}
if ( V_37 . V_11 == V_3 && V_37 . V_12 == V_4 ) {
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_37 . V_11 , V_37 . V_12 ,
V_37 . V_13 , V_37 . V_14 ,
V_37 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_30 == 1 , V_42 ) ;
} else if ( V_37 . V_11 == V_3 ) {
V_37 . V_11 += V_4 ;
V_37 . V_12 -= V_4 ;
if ( ! V_39 )
V_37 . V_14 += V_4 ;
error = F_4 ( V_2 , & V_37 ) ;
if ( error )
goto V_42;
} else if ( V_37 . V_11 + V_37 . V_12 == V_3 + V_4 ) {
V_37 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_37 ) ;
if ( error )
goto V_42;
} else {
T_2 V_45 = V_37 . V_12 ;
V_37 . V_12 = V_3 - V_37 . V_11 ;
error = F_4 ( V_2 , & V_37 ) ;
if ( error )
goto V_42;
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_42;
V_2 -> V_9 . V_10 . V_11 = V_3 + V_4 ;
V_2 -> V_9 . V_10 . V_12 = V_45 - V_4 -
V_37 . V_12 ;
V_2 -> V_9 . V_10 . V_13 = V_37 . V_13 ;
if ( V_39 )
V_2 -> V_9 . V_10 . V_14 = 0 ;
else
V_2 -> V_9 . V_10 . V_14 = V_6 + V_4 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_2 -> V_9 . V_10 . V_11 ,
V_2 -> V_9 . V_10 . V_12 ,
V_2 -> V_9 . V_10 . V_13 ,
V_2 -> V_9 . V_10 . V_14 ,
V_2 -> V_9 . V_10 . V_15 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_42;
}
V_44:
F_30 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
V_42:
if ( error )
F_31 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
error , V_27 ) ;
return error ;
}
int
F_32 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_47 -> V_50 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_33 ( & V_36 -> V_51 ) )
return 0 ;
V_2 = F_34 ( V_36 , V_47 , V_49 , V_25 ) ;
error = F_22 ( V_2 , V_3 , V_4 , false , V_34 ) ;
if ( error )
goto V_42;
F_35 ( V_2 , V_52 ) ;
return 0 ;
V_42:
F_35 ( V_2 , V_53 ) ;
return error ;
}
static bool
F_36 (
struct V_18 * V_19 ,
T_3 V_5 ,
unsigned int V_7 )
{
if ( V_19 -> V_13 == V_43 )
return false ;
if ( V_19 -> V_13 != V_5 )
return false ;
if ( ( V_7 & V_41 ) ^
( V_19 -> V_15 & V_41 ) )
return false ;
if ( ( V_7 & V_54 ) ^
( V_19 -> V_15 & V_54 ) )
return false ;
if ( ( V_7 & V_40 ) ^
( V_19 -> V_15 & V_40 ) )
return false ;
return true ;
}
STATIC int
F_37 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_22 ;
struct V_18 V_37 ;
struct V_18 V_55 ;
int V_56 ;
int V_57 ;
int error = 0 ;
int V_30 ;
T_3 V_5 ;
T_3 V_6 ;
unsigned int V_7 = 0 ;
bool V_39 ;
F_23 ( V_34 , & V_5 , & V_6 , & V_7 ) ;
ASSERT ( V_5 != 0 ) ;
V_39 = F_24 ( V_5 ) ||
( V_7 & V_40 ) ;
if ( V_32 )
V_7 |= V_41 ;
F_38 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_57 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_57 == 1 , V_42 ) ;
error = F_20 ( V_2 , & V_37 , & V_57 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_57 == 1 , V_42 ) ;
F_26 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_37 . V_11 ,
V_37 . V_12 , V_37 . V_13 ,
V_37 . V_14 , V_37 . V_15 ) ;
if ( ! F_36 ( & V_37 , V_5 , V_7 ) )
V_57 = 0 ;
F_13 ( V_36 ,
V_57 == 0 ||
V_37 . V_11 + V_37 . V_12 <= V_3 , V_42 ) ;
error = F_29 ( V_2 , 0 , & V_56 ) ;
if ( error )
goto V_42;
if ( V_56 ) {
error = F_20 ( V_2 , & V_55 , & V_56 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_56 == 1 , V_42 ) ;
F_13 ( V_36 , V_3 + V_4 <= V_55 . V_11 ,
V_42 ) ;
F_39 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_55 . V_11 ,
V_55 . V_12 , V_55 . V_13 ,
V_55 . V_14 , V_55 . V_15 ) ;
if ( ! F_36 ( & V_55 , V_5 , V_7 ) )
V_56 = 0 ;
}
if ( V_57 &&
V_37 . V_11 + V_37 . V_12 == V_3 &&
( V_39 || V_37 . V_14 + V_37 . V_12 == V_6 ) ) {
V_37 . V_12 += V_4 ;
if ( V_56 &&
V_3 + V_4 == V_55 . V_11 &&
( V_39 || V_6 + V_4 == V_55 . V_14 ) &&
( unsigned long ) V_37 . V_12 + V_4 +
V_55 . V_12 <= V_58 ) {
V_37 . V_12 += V_55 . V_12 ;
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_55 . V_11 ,
V_55 . V_12 ,
V_55 . V_13 ,
V_55 . V_14 ,
V_55 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_30 == 1 , V_42 ) ;
}
error = F_40 ( V_2 , 0 , & V_56 ) ;
if ( error )
goto V_42;
error = F_4 ( V_2 , & V_37 ) ;
if ( error )
goto V_42;
} else if ( V_56 &&
V_3 + V_4 == V_55 . V_11 &&
( V_39 || V_6 + V_4 == V_55 . V_14 ) ) {
V_55 . V_11 = V_3 ;
V_55 . V_12 += V_4 ;
if ( ! V_39 )
V_55 . V_14 = V_6 ;
error = F_4 ( V_2 , & V_55 ) ;
if ( error )
goto V_42;
} else {
V_2 -> V_9 . V_10 . V_11 = V_3 ;
V_2 -> V_9 . V_10 . V_12 = V_4 ;
V_2 -> V_9 . V_10 . V_13 = V_5 ;
V_2 -> V_9 . V_10 . V_14 = V_6 ;
V_2 -> V_9 . V_10 . V_15 = V_7 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_42;
F_13 ( V_36 , V_30 == 1 , V_42 ) ;
}
F_41 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
V_42:
if ( error )
F_42 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
error , V_27 ) ;
return error ;
}
int
F_43 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_47 -> V_50 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_33 ( & V_36 -> V_51 ) )
return 0 ;
V_2 = F_34 ( V_36 , V_47 , V_49 , V_25 ) ;
error = F_37 ( V_2 , V_3 , V_4 , false , V_34 ) ;
if ( error )
goto V_42;
F_35 ( V_2 , V_52 ) ;
return 0 ;
V_42:
F_35 ( V_2 , V_53 ) ;
return error ;
}
STATIC int
F_44 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
bool V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_22 ;
struct V_18 V_10 [ 4 ] ;
T_3 V_5 ;
T_3 V_6 ;
T_3 V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_7 = 0 ;
int V_30 ;
int V_62 = 0 ;
int error ;
F_23 ( V_34 , & V_5 , & V_6 , & V_7 ) ;
ASSERT ( ! ( F_24 ( V_5 ) ||
( V_7 & ( V_54 | V_40 ) ) ) ) ;
V_60 = V_32 ? V_41 : 0 ;
V_59 = V_6 + V_4 ;
F_45 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_60 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_20 ( V_2 , & V_63 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_26 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_63 . V_11 ,
V_63 . V_12 , V_63 . V_13 ,
V_63 . V_14 , V_63 . V_15 ) ;
ASSERT ( V_63 . V_14 <= V_6 ) ;
ASSERT ( V_63 . V_14 + V_63 . V_12 >= V_59 ) ;
ASSERT ( ( V_63 . V_15 & V_41 ) == V_60 ) ;
V_61 = ~ V_60 & V_41 ;
if ( V_63 . V_14 == V_6 )
V_62 |= V_64 ;
if ( V_63 . V_14 + V_63 . V_12 == V_59 )
V_62 |= V_65 ;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_62 |= V_66 ;
error = F_20 ( V_2 , & V_67 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_13 ( V_36 ,
V_67 . V_11 + V_67 . V_12 <= V_3 ,
V_31 ) ;
F_46 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_67 . V_11 ,
V_67 . V_12 , V_67 . V_13 ,
V_67 . V_14 , V_67 . V_15 ) ;
if ( V_67 . V_11 + V_67 . V_12 == V_3 &&
V_67 . V_14 + V_67 . V_12 == V_6 &&
F_36 ( & V_67 , V_5 , V_61 ) )
V_62 |= V_68 ;
}
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
if ( V_30 ) {
V_62 |= V_69 ;
error = F_20 ( V_2 , & V_70 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_13 ( V_36 , V_3 + V_4 <= V_70 . V_11 ,
V_31 ) ;
F_39 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , V_70 . V_11 ,
V_70 . V_12 , V_70 . V_13 ,
V_70 . V_14 , V_70 . V_15 ) ;
if ( V_3 + V_4 == V_70 . V_11 &&
V_6 + V_4 == V_70 . V_14 &&
F_36 ( & V_70 , V_5 , V_61 ) )
V_62 |= V_71 ;
}
if ( ( V_62 & ( V_64 | V_68 |
V_65 | V_71 ) ) ==
( V_64 | V_68 |
V_65 | V_71 ) &&
( unsigned long ) V_67 . V_12 + V_4 +
V_70 . V_12 > V_58 )
V_62 &= ~ V_71 ;
F_47 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_62 ,
V_27 ) ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_60 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
switch ( V_62 & ( V_64 | V_68 |
V_65 | V_71 ) ) {
case V_64 | V_68 |
V_65 | V_71 :
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_70 . V_11 , V_70 . V_12 ,
V_70 . V_13 , V_70 . V_14 ,
V_70 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_63 . V_11 , V_63 . V_12 ,
V_63 . V_13 , V_63 . V_14 ,
V_63 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
V_72 = V_67 ;
V_72 . V_12 += V_63 . V_12 + V_70 . V_12 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_64 | V_65 | V_68 :
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_63 . V_11 , V_63 . V_12 ,
V_63 . V_13 , V_63 . V_14 ,
V_63 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
V_72 = V_67 ;
V_72 . V_12 += V_63 . V_12 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_64 | V_65 | V_71 :
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
F_27 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_70 . V_11 , V_70 . V_12 ,
V_70 . V_13 , V_70 . V_14 ,
V_70 . V_15 ) ;
error = F_28 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
V_72 = V_63 ;
V_72 . V_12 = V_4 + V_70 . V_12 ;
V_72 . V_15 = V_61 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_64 | V_65 :
V_72 = V_63 ;
V_72 . V_15 = V_61 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_64 | V_68 :
V_72 = V_63 ;
V_72 . V_14 += V_4 ;
V_72 . V_11 += V_4 ;
V_72 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
error = F_40 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
V_72 = V_67 ;
V_72 . V_12 += V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_64 :
V_72 = V_63 ;
V_72 . V_11 += V_4 ;
V_72 . V_14 += V_4 ;
V_72 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
V_72 . V_11 = V_3 ;
V_72 . V_13 = V_5 ;
V_72 . V_14 = V_6 ;
V_72 . V_12 = V_4 ;
V_72 . V_15 = V_61 ;
V_2 -> V_9 . V_10 = V_72 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 ,
V_4 , V_5 , V_6 , V_61 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
break;
case V_65 | V_71 :
V_72 = V_63 ;
V_72 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
error = F_29 ( V_2 , 0 , & V_30 ) ;
if ( error )
goto V_31;
V_72 = V_70 ;
V_72 . V_14 = V_6 ;
V_72 . V_11 = V_3 ;
V_72 . V_12 += V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
break;
case V_65 :
V_72 = V_63 ;
V_72 . V_12 -= V_4 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
error = F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_60 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 0 , V_31 ) ;
V_72 . V_11 = V_3 ;
V_72 . V_13 = V_5 ;
V_72 . V_14 = V_6 ;
V_72 . V_12 = V_4 ;
V_72 . V_15 = V_61 ;
V_2 -> V_9 . V_10 = V_72 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 ,
V_4 , V_5 , V_6 , V_61 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
break;
case 0 :
V_72 . V_11 = V_3 + V_4 ;
V_72 . V_13 = V_5 ;
V_72 . V_14 = V_59 ;
V_72 . V_12 = V_63 . V_14 + V_63 . V_12 -
V_59 ;
V_72 . V_15 = V_63 . V_15 ;
error = F_4 ( V_2 , & V_72 ) ;
if ( error )
goto V_31;
V_72 = V_63 ;
V_72 . V_12 = V_6 - V_63 . V_14 ;
V_2 -> V_9 . V_10 = V_72 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 ,
V_72 . V_11 , V_72 . V_12 ,
V_72 . V_13 , V_72 . V_14 ,
V_72 . V_15 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
error = F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_60 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 0 , V_31 ) ;
V_2 -> V_9 . V_10 . V_15 &= ~ V_41 ;
V_2 -> V_9 . V_10 . V_15 |= V_61 ;
F_12 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_5 , V_6 , V_61 ) ;
error = F_14 ( V_2 , & V_30 ) ;
if ( error )
goto V_31;
F_13 ( V_36 , V_30 == 1 , V_31 ) ;
break;
case V_64 | V_68 | V_71 :
case V_65 | V_68 | V_71 :
case V_64 | V_71 :
case V_65 | V_68 :
case V_68 | V_71 :
case V_68 :
case V_71 :
ASSERT ( 0 ) ;
}
F_48 ( V_36 , V_2 -> V_23 . V_24 . V_25 , V_3 , V_4 ,
V_32 , V_34 ) ;
V_31:
if ( error )
F_49 ( V_2 -> V_22 ,
V_2 -> V_23 . V_24 . V_25 , error , V_27 ) ;
return error ;
}
STATIC int
F_50 (
struct V_1 * V_2 ,
union V_20 * V_21 ,
void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_18 V_19 ;
int error ;
error = F_16 ( V_21 , & V_19 ) ;
if ( error )
return error ;
return V_75 -> V_76 ( V_2 , & V_19 , V_75 -> V_73 ) ;
}
int
F_51 (
struct V_1 * V_2 ,
struct V_18 * V_77 ,
struct V_18 * V_78 ,
T_5 V_76 ,
void * V_73 )
{
union V_79 V_80 ;
union V_79 V_81 ;
struct V_74 V_75 ;
V_80 . V_10 = * V_77 ;
V_81 . V_10 = * V_78 ;
V_75 . V_73 = V_73 ;
V_75 . V_76 = V_76 ;
return F_52 ( V_2 , & V_80 , & V_81 ,
F_50 , & V_75 ) ;
}
void
F_53 (
struct V_46 * V_47 ,
struct V_1 * V_28 ,
int error )
{
struct V_48 * V_49 ;
if ( V_28 == NULL )
return;
V_49 = V_28 -> V_23 . V_24 . V_49 ;
F_35 ( V_28 , error ? V_53 : V_52 ) ;
if ( error )
F_54 ( V_47 , V_49 ) ;
}
int
F_55 (
struct V_46 * V_47 ,
enum V_82 type ,
T_6 V_5 ,
int V_83 ,
T_7 V_84 ,
T_8 V_85 ,
T_9 V_86 ,
T_10 V_62 ,
struct V_1 * * V_87 )
{
struct V_35 * V_36 = V_47 -> V_50 ;
struct V_1 * V_28 ;
struct V_48 * V_49 = NULL ;
int error = 0 ;
T_4 V_25 ;
struct V_33 V_34 ;
T_1 V_3 ;
bool V_32 ;
V_25 = F_56 ( V_36 , V_85 ) ;
ASSERT ( V_25 != V_88 ) ;
V_3 = F_57 ( V_36 , V_85 ) ;
F_58 ( V_36 , V_25 , type , V_3 , V_5 , V_83 ,
V_84 , V_86 , V_62 ) ;
if ( F_59 ( false , V_36 ,
V_89 ,
V_90 ) )
return - V_91 ;
V_28 = * V_87 ;
if ( V_28 != NULL && V_28 -> V_23 . V_24 . V_25 != V_25 ) {
F_53 ( V_47 , V_28 , 0 ) ;
V_28 = NULL ;
* V_87 = NULL ;
}
if ( V_28 == NULL ) {
error = F_60 ( V_47 , V_25 , & V_49 ) ;
if ( error )
return error ;
if ( ! V_49 )
return - V_92 ;
V_28 = F_34 ( V_36 , V_47 , V_49 , V_25 ) ;
if ( ! V_28 ) {
error = - V_93 ;
goto V_94;
}
}
* V_87 = V_28 ;
F_61 ( & V_34 , V_5 , V_83 , V_84 ) ;
V_32 = V_62 == V_95 ;
V_3 = F_57 ( V_28 -> V_22 , V_85 ) ;
switch ( type ) {
case V_96 :
case V_97 :
error = F_37 ( V_28 , V_3 , V_86 , V_32 , & V_34 ) ;
break;
case V_98 :
case V_99 :
error = F_22 ( V_28 , V_3 , V_86 , V_32 ,
& V_34 ) ;
break;
case V_100 :
error = F_44 ( V_28 , V_3 , V_86 , ! V_32 ,
& V_34 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_92 ;
}
return error ;
V_94:
F_54 ( V_47 , V_49 ) ;
return error ;
}
static bool
F_62 (
struct V_35 * V_36 )
{
return F_33 ( & V_36 -> V_51 ) ;
}
static int
F_63 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
enum V_82 type ,
T_6 V_5 ,
int V_83 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 ;
F_64 ( V_36 , F_56 ( V_36 , V_104 -> V_107 ) ,
type ,
F_57 ( V_36 , V_104 -> V_107 ) ,
V_5 , V_83 ,
V_104 -> V_108 ,
V_104 -> V_109 ,
V_104 -> V_110 ) ;
V_106 = F_65 ( sizeof( struct V_105 ) , V_111 | V_112 ) ;
F_66 ( & V_106 -> V_113 ) ;
V_106 -> V_114 = type ;
V_106 -> V_115 = V_5 ;
V_106 -> V_116 = V_83 ;
V_106 -> V_117 = * V_104 ;
F_67 ( V_102 , V_118 , & V_106 -> V_113 ) ;
return 0 ;
}
int
F_68 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
struct V_119 * V_120 ,
int V_83 ,
struct V_103 * V_63 )
{
if ( ! F_62 ( V_36 ) )
return 0 ;
return F_63 ( V_36 , V_102 , V_97 , V_120 -> V_121 ,
V_83 , V_63 ) ;
}
int
F_69 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
struct V_119 * V_120 ,
int V_83 ,
struct V_103 * V_63 )
{
if ( ! F_62 ( V_36 ) )
return 0 ;
return F_63 ( V_36 , V_102 , V_99 , V_120 -> V_121 ,
V_83 , V_63 ) ;
}
int
F_70 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
struct V_119 * V_120 ,
int V_83 ,
struct V_103 * V_63 )
{
if ( ! F_62 ( V_36 ) )
return 0 ;
return F_63 ( V_36 , V_102 , V_100 , V_120 -> V_121 ,
V_83 , V_63 ) ;
}
int
F_71 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_6 V_5 )
{
struct V_103 V_104 ;
if ( ! F_62 ( V_36 ) )
return 0 ;
V_104 . V_107 = F_72 ( V_36 , V_25 , V_3 ) ;
V_104 . V_109 = V_4 ;
V_104 . V_108 = 0 ;
V_104 . V_110 = V_122 ;
return F_63 ( V_36 , V_102 , V_96 , V_5 ,
V_123 , & V_104 ) ;
}
int
F_73 (
struct V_35 * V_36 ,
struct V_101 * V_102 ,
T_4 V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_6 V_5 )
{
struct V_103 V_104 ;
if ( ! F_62 ( V_36 ) )
return 0 ;
V_104 . V_107 = F_72 ( V_36 , V_25 , V_3 ) ;
V_104 . V_109 = V_4 ;
V_104 . V_108 = 0 ;
V_104 . V_110 = V_122 ;
return F_63 ( V_36 , V_102 , V_98 , V_5 ,
V_123 , & V_104 ) ;
}
