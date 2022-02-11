int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
int * V_4 )
{
F_2 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 , V_3 ,
V_9 ) ;
V_2 -> V_10 . V_11 . V_12 = V_3 ;
V_2 -> V_10 . V_11 . V_13 = 0 ;
return F_3 ( V_2 , V_9 , V_4 ) ;
}
int
F_4 (
struct V_1 * V_2 ,
T_1 V_3 ,
int * V_4 )
{
F_2 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 , V_3 ,
V_14 ) ;
V_2 -> V_10 . V_11 . V_12 = V_3 ;
V_2 -> V_10 . V_11 . V_13 = 0 ;
return F_3 ( V_2 , V_14 , V_4 ) ;
}
static inline void
F_5 (
union V_15 * V_16 ,
struct V_17 * V_18 )
{
V_18 -> V_12 = F_6 ( V_16 -> V_19 . V_12 ) ;
V_18 -> V_13 = F_6 ( V_16 -> V_19 . V_13 ) ;
V_18 -> V_20 = F_6 ( V_16 -> V_19 . V_20 ) ;
}
int
F_7 (
struct V_1 * V_2 ,
struct V_17 * V_18 ,
int * V_4 )
{
union V_15 * V_16 ;
int error ;
error = F_8 ( V_2 , & V_16 , V_4 ) ;
if ( ! error && * V_4 == 1 ) {
F_5 ( V_16 , V_18 ) ;
F_9 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_18 ) ;
}
return error ;
}
STATIC int
F_10 (
struct V_1 * V_2 ,
struct V_17 * V_18 )
{
union V_15 V_16 ;
int error ;
F_11 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 , V_18 ) ;
V_16 . V_19 . V_12 = F_12 ( V_18 -> V_12 ) ;
V_16 . V_19 . V_13 = F_12 ( V_18 -> V_13 ) ;
V_16 . V_19 . V_20 = F_12 ( V_18 -> V_20 ) ;
error = F_13 ( V_2 , & V_16 ) ;
if ( error )
F_14 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_15 (
struct V_1 * V_2 ,
struct V_17 * V_18 ,
int * V_22 )
{
int error ;
F_16 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 , V_18 ) ;
V_2 -> V_10 . V_11 . V_12 = V_18 -> V_12 ;
V_2 -> V_10 . V_11 . V_13 = V_18 -> V_13 ;
V_2 -> V_10 . V_11 . V_20 = V_18 -> V_20 ;
error = F_17 ( V_2 , V_22 ) ;
F_18 ( V_2 -> V_5 , * V_22 == 1 , V_23 ) ;
V_23:
if ( error )
F_19 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
int * V_22 )
{
struct V_17 V_18 ;
int V_24 ;
int error ;
error = F_7 ( V_2 , & V_18 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
F_21 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 , & V_18 ) ;
error = F_22 ( V_2 , V_22 ) ;
F_18 ( V_2 -> V_5 , * V_22 == 1 , V_23 ) ;
if ( error )
goto V_23;
error = F_4 ( V_2 , V_18 . V_12 , & V_24 ) ;
V_23:
if ( error )
F_23 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
static inline T_1
F_24 (
struct V_17 * V_11 )
{
return V_11 -> V_12 + V_11 -> V_13 ;
}
STATIC int
F_25 (
struct V_1 * V_2 ,
T_1 V_25 ,
bool * V_26 )
{
struct V_17 V_27 , V_28 ;
int V_24 ;
int error ;
* V_26 = false ;
error = F_1 ( V_2 , V_25 , & V_24 ) ;
if ( error )
goto V_23;
if ( ! V_24 )
return 0 ;
error = F_7 ( V_2 , & V_27 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
if ( V_27 . V_12 == V_25 || F_24 ( & V_27 ) <= V_25 )
return 0 ;
* V_26 = true ;
F_26 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
& V_27 , V_25 ) ;
V_28 = V_27 ;
V_28 . V_12 = V_25 ;
V_28 . V_13 -= ( V_25 - V_27 . V_12 ) ;
error = F_10 ( V_2 , & V_28 ) ;
if ( error )
goto V_23;
V_28 = V_27 ;
V_28 . V_13 = V_25 - V_27 . V_12 ;
error = F_15 ( V_2 , & V_28 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
return error ;
V_23:
F_27 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_28 (
struct V_1 * V_2 ,
struct V_17 * V_29 ,
struct V_17 * V_30 ,
struct V_17 * V_31 ,
unsigned long long V_32 ,
T_1 * V_25 ,
T_2 * V_33 )
{
int error ;
int V_24 ;
F_29 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , V_29 , V_30 , V_31 ) ;
error = F_4 ( V_2 , V_30 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
if ( V_30 -> V_20 > 1 ) {
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
}
error = F_1 ( V_2 , V_29 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
V_29 -> V_13 = V_32 ;
error = F_10 ( V_2 , V_29 ) ;
if ( error )
goto V_23;
* V_33 = 0 ;
return error ;
V_23:
F_30 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_31 (
struct V_1 * V_2 ,
struct V_17 * V_29 ,
struct V_17 * V_34 ,
T_1 * V_25 ,
T_2 * V_33 )
{
int error ;
int V_24 ;
F_32 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , V_29 , V_34 ) ;
if ( V_34 -> V_20 > 1 ) {
error = F_1 ( V_2 , V_34 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
}
error = F_1 ( V_2 , V_29 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
V_29 -> V_13 += V_34 -> V_13 ;
error = F_10 ( V_2 , V_29 ) ;
if ( error )
goto V_23;
* V_25 += V_34 -> V_13 ;
* V_33 -= V_34 -> V_13 ;
return error ;
V_23:
F_33 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_34 (
struct V_1 * V_2 ,
struct V_17 * V_31 ,
struct V_17 * V_35 ,
T_1 * V_25 ,
T_2 * V_33 )
{
int error ;
int V_24 ;
F_35 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , V_35 , V_31 ) ;
if ( V_35 -> V_20 > 1 ) {
error = F_1 ( V_2 , V_35 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
}
error = F_1 ( V_2 , V_31 -> V_12 ,
& V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
V_31 -> V_12 -= V_35 -> V_13 ;
V_31 -> V_13 += V_35 -> V_13 ;
error = F_10 ( V_2 , V_31 ) ;
if ( error )
goto V_23;
* V_33 -= V_35 -> V_13 ;
return error ;
V_23:
F_36 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_37 (
struct V_1 * V_2 ,
struct V_17 * V_29 ,
struct V_17 * V_34 ,
T_1 V_25 ,
T_2 V_33 ,
int V_36 )
{
struct V_17 V_28 ;
int error ;
int V_24 ;
V_29 -> V_12 = V_34 -> V_12 = V_37 ;
error = F_1 ( V_2 , V_25 - 1 , & V_24 ) ;
if ( error )
goto V_23;
if ( ! V_24 )
return 0 ;
error = F_7 ( V_2 , & V_28 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
if ( F_24 ( & V_28 ) != V_25 )
return 0 ;
if ( ( V_36 & V_38 ) && V_28 . V_20 < 2 )
return 0 ;
if ( ( V_36 & V_39 ) && V_28 . V_20 > 1 )
return 0 ;
* V_29 = V_28 ;
error = F_38 ( V_2 , 0 , & V_24 ) ;
if ( error )
goto V_23;
if ( V_24 ) {
error = F_7 ( V_2 , & V_28 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
if ( V_28 . V_12 == V_25 )
* V_34 = V_28 ;
else {
V_34 -> V_12 = V_25 ;
V_34 -> V_13 = F_39 ( V_33 ,
V_28 . V_12 - V_25 ) ;
V_34 -> V_20 = 1 ;
}
} else {
V_34 -> V_12 = V_25 ;
V_34 -> V_13 = V_33 ;
V_34 -> V_20 = 1 ;
}
F_40 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_29 , V_34 , V_25 ) ;
return error ;
V_23:
F_41 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_42 (
struct V_1 * V_2 ,
struct V_17 * V_31 ,
struct V_17 * V_35 ,
T_1 V_25 ,
T_2 V_33 ,
int V_36 )
{
struct V_17 V_28 ;
int error ;
int V_24 ;
V_31 -> V_12 = V_35 -> V_12 = V_37 ;
error = F_4 ( V_2 , V_25 + V_33 , & V_24 ) ;
if ( error )
goto V_23;
if ( ! V_24 )
return 0 ;
error = F_7 ( V_2 , & V_28 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 , V_23 ) ;
if ( V_28 . V_12 != V_25 + V_33 )
return 0 ;
if ( ( V_36 & V_38 ) && V_28 . V_20 < 2 )
return 0 ;
if ( ( V_36 & V_39 ) && V_28 . V_20 > 1 )
return 0 ;
* V_31 = V_28 ;
error = F_43 ( V_2 , 0 , & V_24 ) ;
if ( error )
goto V_23;
if ( V_24 ) {
error = F_7 ( V_2 , & V_28 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_24 == 1 ,
V_23 ) ;
if ( F_24 ( & V_28 ) == V_25 + V_33 )
* V_35 = V_28 ;
else {
V_35 -> V_12 = F_44 ( V_25 , F_24 ( & V_28 ) ) ;
V_35 -> V_13 = V_31 -> V_12 -
V_35 -> V_12 ;
V_35 -> V_20 = 1 ;
}
} else {
V_35 -> V_12 = V_25 ;
V_35 -> V_13 = V_33 ;
V_35 -> V_20 = 1 ;
}
F_45 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_35 , V_31 , V_25 + V_33 ) ;
return error ;
V_23:
F_46 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
static inline bool
F_47 (
struct V_17 * V_11 )
{
return V_11 -> V_12 != V_37 ;
}
STATIC int
F_48 (
struct V_1 * V_2 ,
T_1 * V_25 ,
T_2 * V_33 ,
enum V_40 V_41 ,
int V_36 ,
bool * V_26 )
{
struct V_17 V_29 = { 0 } , V_34 = { 0 } ;
struct V_17 V_35 = { 0 } , V_31 = { 0 } ;
int error ;
unsigned long long V_42 ;
bool V_43 ;
* V_26 = false ;
error = F_37 ( V_2 , & V_29 , & V_34 , * V_25 ,
* V_33 , V_36 ) ;
if ( error )
return error ;
error = F_42 ( V_2 , & V_31 , & V_35 , * V_25 ,
* V_33 , V_36 ) ;
if ( error )
return error ;
if ( ! F_47 ( & V_29 ) && ! F_47 ( & V_31 ) )
return 0 ;
V_43 = ( V_34 . V_12 == V_35 . V_12 ) &&
( V_34 . V_13 == V_35 . V_13 ) ;
V_42 = ( unsigned long long ) V_29 . V_13 + V_34 . V_13 +
V_31 . V_13 ;
if ( F_47 ( & V_29 ) && F_47 ( & V_31 ) &&
F_47 ( & V_34 ) && F_47 ( & V_35 ) && V_43 &&
V_29 . V_20 == V_34 . V_20 + V_41 &&
V_31 . V_20 == V_34 . V_20 + V_41 &&
V_42 < V_44 ) {
* V_26 = true ;
return F_28 ( V_2 , & V_29 , & V_34 ,
& V_31 , V_42 , V_25 , V_33 ) ;
}
V_42 = ( unsigned long long ) V_29 . V_13 + V_34 . V_13 ;
if ( F_47 ( & V_29 ) && F_47 ( & V_34 ) &&
V_29 . V_20 == V_34 . V_20 + V_41 &&
V_42 < V_44 ) {
* V_26 = true ;
error = F_31 ( V_2 , & V_29 , & V_34 ,
V_25 , V_33 ) ;
if ( error )
return error ;
if ( V_43 )
return 0 ;
}
V_42 = ( unsigned long long ) V_31 . V_13 + V_35 . V_13 ;
if ( F_47 ( & V_31 ) && F_47 ( & V_35 ) &&
V_31 . V_20 == V_35 . V_20 + V_41 &&
V_42 < V_44 ) {
* V_26 = true ;
return F_34 ( V_2 , & V_31 , & V_35 ,
V_25 , V_33 ) ;
}
return error ;
}
static bool
F_49 (
struct V_1 * V_2 )
{
unsigned long V_45 ;
V_45 = V_2 -> V_6 . V_7 . V_46 . V_19 . V_47 *
F_50 ( V_2 -> V_5 , 1 ) ;
V_45 *= V_2 -> V_5 -> V_48 . V_49 ;
if ( V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 > 2 &&
F_51 ( false , V_2 -> V_5 ,
V_51 ,
V_52 ) )
return false ;
if ( V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 == 0 )
return true ;
else if ( V_45 > V_2 -> V_53 -> V_54 )
return false ;
return V_2 -> V_53 -> V_54 - V_45 >
V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 * 32 ;
}
STATIC int
F_52 (
struct V_1 * V_2 ,
T_1 * V_25 ,
T_2 * V_33 ,
enum V_40 V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_17 V_60 , V_28 ;
int error ;
int V_24 , V_61 ;
T_3 V_62 ;
if ( * V_33 == 0 )
return 0 ;
error = F_4 ( V_2 , * V_25 , & V_24 ) ;
if ( error )
goto V_23;
while ( * V_33 > 0 && F_49 ( V_2 ) ) {
error = F_7 ( V_2 , & V_60 , & V_24 ) ;
if ( error )
goto V_23;
if ( ! V_24 ) {
V_60 . V_12 = V_2 -> V_5 -> V_48 . V_63 ;
V_60 . V_13 = 0 ;
V_60 . V_20 = 0 ;
}
if ( V_60 . V_12 != * V_25 ) {
V_28 . V_12 = * V_25 ;
V_28 . V_13 = F_39 ( * V_33 ,
V_60 . V_12 - * V_25 ) ;
V_28 . V_20 = 1 + V_55 ;
F_53 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , & V_28 ) ;
if ( V_28 . V_20 ) {
error = F_15 ( V_2 , & V_28 ,
& V_61 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 ,
V_61 == 1 , V_23 ) ;
V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 ++ ;
} else {
V_62 = F_54 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 ,
V_28 . V_12 ) ;
F_55 ( V_2 -> V_5 , V_57 , V_62 ,
V_28 . V_13 , V_59 ) ;
}
( * V_25 ) += V_28 . V_13 ;
( * V_33 ) -= V_28 . V_13 ;
error = F_4 ( V_2 , * V_25 ,
& V_24 ) ;
if ( error )
goto V_23;
}
if ( * V_33 == 0 || ! F_49 ( V_2 ) )
break;
if ( V_60 . V_20 == V_64 )
goto V_65;
V_60 . V_20 += V_55 ;
F_53 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , & V_60 ) ;
if ( V_60 . V_20 > 1 ) {
error = F_10 ( V_2 , & V_60 ) ;
if ( error )
goto V_23;
V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 ++ ;
} else if ( V_60 . V_20 == 1 ) {
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 ,
V_24 == 1 , V_23 ) ;
V_2 -> V_6 . V_7 . V_46 . V_19 . V_50 ++ ;
goto V_66;
} else {
V_62 = F_54 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 ,
V_60 . V_12 ) ;
F_55 ( V_2 -> V_5 , V_57 , V_62 ,
V_60 . V_13 , V_59 ) ;
}
V_65:
error = F_38 ( V_2 , 0 , & V_24 ) ;
if ( error )
goto V_23;
V_66:
( * V_25 ) += V_60 . V_13 ;
( * V_33 ) -= V_60 . V_13 ;
}
return error ;
V_23:
F_56 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_57 (
struct V_1 * V_2 ,
T_1 V_25 ,
T_2 V_33 ,
T_1 * V_67 ,
T_2 * V_68 ,
enum V_40 V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_59 )
{
bool V_26 ;
int V_47 = 0 ;
int error ;
* V_67 = V_25 ;
* V_68 = V_33 ;
if ( V_55 == V_69 )
F_58 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_25 , V_33 ) ;
else
F_59 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_25 , V_33 ) ;
error = F_25 ( V_2 , V_25 , & V_26 ) ;
if ( error )
goto V_23;
if ( V_26 )
V_47 ++ ;
error = F_25 ( V_2 , V_25 + V_33 , & V_26 ) ;
if ( error )
goto V_23;
if ( V_26 )
V_47 ++ ;
error = F_48 ( V_2 , V_67 , V_68 , V_55 ,
V_38 , & V_26 ) ;
if ( error )
goto V_23;
if ( V_26 )
V_47 ++ ;
if ( V_47 )
V_2 -> V_6 . V_7 . V_46 . V_19 . V_47 ++ ;
error = F_52 ( V_2 , V_67 , V_68 ,
V_55 , V_57 , V_59 ) ;
if ( error )
goto V_23;
return 0 ;
V_23:
F_60 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
error , V_21 ) ;
return error ;
}
void
F_61 (
struct V_70 * V_71 ,
struct V_1 * V_72 ,
int error )
{
struct V_73 * V_74 ;
if ( V_72 == NULL )
return;
V_74 = V_72 -> V_6 . V_7 . V_74 ;
F_62 ( V_72 , error ? V_75 : V_76 ) ;
if ( error )
F_63 ( V_71 , V_74 ) ;
}
int
F_64 (
struct V_70 * V_71 ,
struct V_56 * V_57 ,
enum V_77 type ,
T_3 V_78 ,
T_2 V_79 ,
T_3 * V_80 ,
T_2 * V_81 ,
struct V_1 * * V_82 )
{
struct V_83 * V_84 = V_71 -> V_85 ;
struct V_1 * V_72 ;
struct V_73 * V_74 = NULL ;
int error = 0 ;
T_4 V_8 ;
T_1 V_3 ;
T_1 V_67 ;
unsigned long V_50 = 0 ;
int V_47 = 0 ;
V_8 = F_65 ( V_84 , V_78 ) ;
ASSERT ( V_8 != V_86 ) ;
V_3 = F_66 ( V_84 , V_78 ) ;
F_67 ( V_84 , F_65 ( V_84 , V_78 ) ,
type , F_66 ( V_84 , V_78 ) ,
V_79 ) ;
if ( F_51 ( false , V_84 ,
V_87 ,
V_88 ) )
return - V_89 ;
V_72 = * V_82 ;
if ( V_72 != NULL && V_72 -> V_6 . V_7 . V_8 != V_8 ) {
V_50 = V_72 -> V_6 . V_7 . V_46 . V_19 . V_50 ;
V_47 = V_72 -> V_6 . V_7 . V_46 . V_19 . V_47 ;
F_61 ( V_71 , V_72 , 0 ) ;
V_72 = NULL ;
* V_82 = NULL ;
}
if ( V_72 == NULL ) {
error = F_68 ( V_71 -> V_85 , V_71 , V_8 ,
V_90 , & V_74 ) ;
if ( error )
return error ;
if ( ! V_74 )
return - V_91 ;
V_72 = F_69 ( V_84 , V_71 , V_74 , V_8 , V_57 ) ;
if ( ! V_72 ) {
error = - V_92 ;
goto V_93;
}
V_72 -> V_6 . V_7 . V_46 . V_19 . V_50 = V_50 ;
V_72 -> V_6 . V_7 . V_46 . V_19 . V_47 = V_47 ;
}
* V_82 = V_72 ;
switch ( type ) {
case V_94 :
error = F_57 ( V_72 , V_3 , V_79 , & V_67 ,
V_81 , V_69 , V_57 , NULL ) ;
* V_80 = F_54 ( V_84 , V_8 , V_67 ) ;
break;
case V_95 :
error = F_57 ( V_72 , V_3 , V_79 , & V_67 ,
V_81 , V_96 , V_57 , NULL ) ;
* V_80 = F_54 ( V_84 , V_8 , V_67 ) ;
break;
case V_97 :
* V_80 = V_78 + V_79 ;
* V_81 = 0 ;
error = F_70 ( V_72 , V_3 , V_79 , V_57 ) ;
break;
case V_98 :
* V_80 = V_78 + V_79 ;
* V_81 = 0 ;
error = F_71 ( V_72 , V_3 , V_79 , V_57 ) ;
break;
default:
ASSERT ( 0 ) ;
error = - V_91 ;
}
if ( ! error && * V_81 > 0 )
F_72 ( V_84 , V_8 , type ,
V_3 , V_79 , V_67 , * V_81 ) ;
return error ;
V_93:
F_63 ( V_71 , V_74 ) ;
return error ;
}
static int
F_73 (
struct V_83 * V_84 ,
struct V_56 * V_57 ,
enum V_77 type ,
T_3 V_78 ,
T_2 V_79 )
{
struct V_99 * V_100 ;
F_74 ( V_84 , F_65 ( V_84 , V_78 ) ,
type , F_66 ( V_84 , V_78 ) ,
V_79 ) ;
V_100 = F_75 ( sizeof( struct V_99 ) ,
V_101 | V_102 ) ;
F_76 ( & V_100 -> V_103 ) ;
V_100 -> V_104 = type ;
V_100 -> V_105 = V_78 ;
V_100 -> V_106 = V_79 ;
F_77 ( V_57 , V_107 , & V_100 -> V_103 ) ;
return 0 ;
}
int
F_78 (
struct V_83 * V_84 ,
struct V_56 * V_57 ,
struct V_108 * V_109 )
{
if ( ! F_79 ( & V_84 -> V_48 ) )
return 0 ;
return F_73 ( V_84 , V_57 , V_94 ,
V_109 -> V_110 , V_109 -> V_111 ) ;
}
int
F_80 (
struct V_83 * V_84 ,
struct V_56 * V_57 ,
struct V_108 * V_109 )
{
if ( ! F_79 ( & V_84 -> V_48 ) )
return 0 ;
return F_73 ( V_84 , V_57 , V_95 ,
V_109 -> V_110 , V_109 -> V_111 ) ;
}
int
F_81 (
struct V_1 * V_2 ,
T_1 V_25 ,
T_2 V_33 ,
T_1 * V_112 ,
T_2 * V_113 ,
bool V_114 )
{
struct V_17 V_28 ;
int V_22 ;
int V_115 ;
int error ;
F_82 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
V_25 , V_33 ) ;
* V_112 = V_37 ;
* V_113 = 0 ;
error = F_1 ( V_2 , V_25 , & V_115 ) ;
if ( error )
goto V_23;
if ( ! V_115 ) {
error = F_38 ( V_2 , 0 , & V_115 ) ;
if ( error )
goto V_23;
if ( ! V_115 )
goto V_116;
}
error = F_7 ( V_2 , & V_28 , & V_22 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_22 == 1 , V_23 ) ;
if ( V_28 . V_12 + V_28 . V_13 <= V_25 ) {
error = F_38 ( V_2 , 0 , & V_115 ) ;
if ( error )
goto V_23;
if ( ! V_115 )
goto V_116;
error = F_7 ( V_2 , & V_28 , & V_22 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_22 == 1 , V_23 ) ;
}
if ( V_28 . V_12 >= V_25 + V_33 )
goto V_116;
if ( V_28 . V_12 < V_25 ) {
V_28 . V_13 -= ( V_25 - V_28 . V_12 ) ;
V_28 . V_12 = V_25 ;
}
* V_112 = V_28 . V_12 ;
* V_113 = F_39 ( V_28 . V_13 , V_25 + V_33 - * V_112 ) ;
if ( ! V_114 )
goto V_116;
while ( * V_112 + * V_113 < V_25 + V_33 ) {
error = F_38 ( V_2 , 0 , & V_115 ) ;
if ( error )
goto V_23;
if ( ! V_115 )
break;
error = F_7 ( V_2 , & V_28 , & V_22 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 , V_22 == 1 , V_23 ) ;
if ( V_28 . V_12 >= V_25 + V_33 ||
V_28 . V_12 != * V_112 + * V_113 )
break;
* V_113 = F_39 ( * V_113 + V_28 . V_13 , V_25 + V_33 - * V_112 ) ;
}
V_116:
F_83 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , * V_112 , * V_113 ) ;
V_23:
if ( error )
F_84 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_85 (
struct V_1 * V_2 ,
T_1 V_25 ,
T_2 V_33 ,
enum V_40 V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_17 V_60 , V_28 ;
int error ;
int V_24 , V_61 ;
if ( V_33 == 0 )
return 0 ;
error = F_4 ( V_2 , V_25 , & V_24 ) ;
if ( error )
goto V_23;
error = F_7 ( V_2 , & V_60 , & V_24 ) ;
if ( error )
goto V_23;
if ( ! V_24 ) {
V_60 . V_12 = V_2 -> V_5 -> V_48 . V_63 +
V_117 ;
V_60 . V_13 = 0 ;
V_60 . V_20 = 0 ;
}
switch ( V_55 ) {
case V_118 :
F_18 ( V_2 -> V_5 ,
V_60 . V_12 >= V_25 + V_33 , V_23 ) ;
V_28 . V_12 = V_25 ;
V_28 . V_13 = V_33 ;
V_28 . V_20 = 1 ;
F_53 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , & V_28 ) ;
error = F_15 ( V_2 , & V_28 ,
& V_61 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 ,
V_61 == 1 , V_23 ) ;
break;
case V_119 :
F_18 ( V_2 -> V_5 ,
V_60 . V_12 == V_25 , V_23 ) ;
F_18 ( V_2 -> V_5 ,
V_60 . V_13 == V_33 , V_23 ) ;
F_18 ( V_2 -> V_5 ,
V_60 . V_20 == 1 , V_23 ) ;
V_60 . V_20 = 0 ;
F_53 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , & V_60 ) ;
error = F_20 ( V_2 , & V_24 ) ;
if ( error )
goto V_23;
F_18 ( V_2 -> V_5 ,
V_24 == 1 , V_23 ) ;
break;
default:
ASSERT ( 0 ) ;
}
return error ;
V_23:
F_56 ( V_2 -> V_5 ,
V_2 -> V_6 . V_7 . V_8 , error , V_21 ) ;
return error ;
}
STATIC int
F_86 (
struct V_1 * V_2 ,
T_1 V_25 ,
T_2 V_33 ,
enum V_40 V_55 ,
struct V_56 * V_57 )
{
bool V_26 ;
int error ;
V_25 += V_117 ;
error = F_25 ( V_2 , V_25 , & V_26 ) ;
if ( error )
goto V_23;
error = F_25 ( V_2 , V_25 + V_33 , & V_26 ) ;
if ( error )
goto V_23;
error = F_48 ( V_2 , & V_25 , & V_33 , V_55 ,
V_39 , & V_26 ) ;
if ( error )
goto V_23;
error = F_85 ( V_2 , V_25 , V_33 , V_55 ,
V_57 , NULL ) ;
if ( error )
goto V_23;
return 0 ;
V_23:
F_87 ( V_2 -> V_5 , V_2 -> V_6 . V_7 . V_8 ,
error , V_21 ) ;
return error ;
}
STATIC int
F_70 (
struct V_1 * V_72 ,
T_1 V_25 ,
T_2 V_33 ,
struct V_56 * V_57 )
{
int error ;
F_88 ( V_72 -> V_5 , V_72 -> V_6 . V_7 . V_8 ,
V_25 , V_33 ) ;
error = F_86 ( V_72 , V_25 , V_33 ,
V_118 , V_57 ) ;
if ( error )
return error ;
if ( F_89 ( & V_72 -> V_5 -> V_48 ) ) {
error = F_90 ( V_72 -> V_5 , V_57 ,
V_72 -> V_6 . V_7 . V_8 ,
V_25 , V_33 , V_120 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_71 (
struct V_1 * V_72 ,
T_1 V_25 ,
T_2 V_33 ,
struct V_56 * V_57 )
{
int error ;
F_91 ( V_72 -> V_5 , V_72 -> V_6 . V_7 . V_8 ,
V_25 , V_33 ) ;
error = F_86 ( V_72 , V_25 , V_33 ,
V_119 , V_57 ) ;
if ( error )
return error ;
if ( F_89 ( & V_72 -> V_5 -> V_48 ) ) {
error = F_92 ( V_72 -> V_5 , V_57 ,
V_72 -> V_6 . V_7 . V_8 ,
V_25 , V_33 , V_120 ) ;
if ( error )
return error ;
}
return error ;
}
int
F_93 (
struct V_83 * V_84 ,
struct V_56 * V_57 ,
T_3 V_121 ,
T_2 V_122 )
{
if ( ! F_79 ( & V_84 -> V_48 ) )
return 0 ;
return F_73 ( V_84 , V_57 , V_97 ,
V_121 , V_122 ) ;
}
int
F_94 (
struct V_83 * V_84 ,
struct V_56 * V_57 ,
T_3 V_121 ,
T_2 V_122 )
{
if ( ! F_79 ( & V_84 -> V_48 ) )
return 0 ;
return F_73 ( V_84 , V_57 , V_98 ,
V_121 , V_122 ) ;
}
STATIC int
F_95 (
struct V_1 * V_2 ,
union V_15 * V_16 ,
void * V_46 )
{
struct V_123 * V_124 = V_46 ;
struct V_125 * V_126 ;
if ( F_6 ( V_16 -> V_19 . V_20 ) != 1 )
return - V_91 ;
V_126 = F_75 ( sizeof( struct V_125 ) , V_101 ) ;
F_5 ( V_16 , & V_126 -> V_127 ) ;
F_96 ( & V_126 -> V_128 , V_124 ) ;
return 0 ;
}
int
F_97 (
struct V_83 * V_84 ,
T_4 V_8 )
{
struct V_70 * V_71 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
struct V_125 * V_126 , * V_129 ;
struct V_123 V_124 ;
union V_130 V_131 ;
union V_130 V_132 ;
struct V_56 V_57 ;
T_3 V_121 ;
T_1 V_25 ;
int error ;
if ( V_84 -> V_48 . V_63 >= V_117 )
return - V_133 ;
F_76 ( & V_124 ) ;
error = F_98 ( V_84 , & V_71 ) ;
if ( error )
return error ;
error = F_68 ( V_84 , V_71 , V_8 , 0 , & V_74 ) ;
if ( error )
goto V_134;
V_2 = F_69 ( V_84 , V_71 , V_74 , V_8 , NULL ) ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_131 . V_11 . V_12 = V_117 ;
V_132 . V_11 . V_12 = - 1U ;
error = F_99 ( V_2 , & V_131 , & V_132 ,
F_95 , & V_124 ) ;
if ( error )
goto V_135;
F_62 ( V_2 , V_76 ) ;
F_63 ( V_71 , V_74 ) ;
F_100 ( V_71 ) ;
F_101 (rr, n, &debris, rr_list) {
error = F_102 ( V_84 , & F_103 ( V_84 ) -> V_136 , 0 , 0 , 0 , & V_71 ) ;
if ( error )
goto V_137;
F_104 ( V_84 , V_8 , & V_126 -> V_127 ) ;
F_105 ( & V_57 , & V_121 ) ;
V_25 = V_126 -> V_127 . V_12 - V_117 ;
V_121 = F_54 ( V_84 , V_8 , V_25 ) ;
error = F_94 ( V_84 , & V_57 , V_121 ,
V_126 -> V_127 . V_13 ) ;
if ( error )
goto V_138;
F_55 ( V_84 , & V_57 , V_121 ,
V_126 -> V_127 . V_13 , NULL ) ;
error = F_106 ( & V_71 , & V_57 , NULL ) ;
if ( error )
goto V_138;
error = F_107 ( V_71 ) ;
if ( error )
goto V_137;
F_108 ( & V_126 -> V_128 ) ;
F_109 ( V_126 ) ;
}
return error ;
V_138:
F_110 ( & V_57 ) ;
V_134:
F_100 ( V_71 ) ;
V_137:
F_101 (rr, n, &debris, rr_list) {
F_108 ( & V_126 -> V_128 ) ;
F_109 ( V_126 ) ;
}
return error ;
V_135:
F_62 ( V_2 , V_75 ) ;
F_63 ( V_71 , V_74 ) ;
goto V_134;
}
