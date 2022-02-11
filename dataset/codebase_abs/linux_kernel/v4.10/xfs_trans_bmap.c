struct V_1 *
F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_3 -> V_7 , V_5 ) ;
F_3 ( V_3 , & V_6 -> V_8 ) ;
return V_6 ;
}
int
F_4 (
struct V_2 * V_3 ,
struct V_1 * V_6 ,
struct V_9 * V_10 ,
enum V_11 type ,
struct V_12 * V_13 ,
int V_14 ,
T_1 V_15 ,
T_2 V_16 ,
T_3 V_17 ,
T_4 V_18 )
{
int error ;
error = F_5 ( V_3 , V_10 , V_13 , type , V_14 , V_15 ,
V_16 , V_17 , V_18 ) ;
V_3 -> V_19 |= V_20 ;
V_6 -> V_8 . V_21 -> V_22 |= V_23 ;
return error ;
}
static int
F_6 (
void * V_24 ,
struct V_25 * V_26 ,
struct V_25 * V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
V_29 = F_7 ( V_26 , struct V_28 , V_31 ) ;
V_30 = F_7 ( V_27 , struct V_28 , V_31 ) ;
return V_29 -> V_32 -> V_33 - V_30 -> V_32 -> V_33 ;
}
STATIC void *
F_8 (
struct V_2 * V_3 ,
unsigned int V_34 )
{
struct V_4 * V_5 ;
ASSERT ( V_34 == V_35 ) ;
ASSERT ( V_3 != NULL ) ;
V_5 = F_9 ( V_3 -> V_7 ) ;
ASSERT ( V_5 != NULL ) ;
F_3 ( V_3 , & V_5 -> V_36 ) ;
return V_5 ;
}
static void
F_10 (
struct V_37 * V_38 ,
enum V_11 type ,
int V_14 ,
T_4 V_18 )
{
V_38 -> V_39 = 0 ;
switch ( type ) {
case V_40 :
case V_41 :
V_38 -> V_39 = type ;
break;
default:
ASSERT ( 0 ) ;
}
if ( V_18 == V_42 )
V_38 -> V_39 |= V_43 ;
if ( V_14 == V_44 )
V_38 -> V_39 |= V_45 ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
void * V_46 ,
struct V_25 * V_47 )
{
struct V_4 * V_5 = V_46 ;
struct V_28 * V_38 ;
T_5 V_48 ;
struct V_37 * V_49 ;
V_38 = F_7 ( V_47 , struct V_28 , V_31 ) ;
V_3 -> V_19 |= V_20 ;
V_5 -> V_36 . V_21 -> V_22 |= V_23 ;
V_48 = F_12 ( & V_5 -> V_50 ) - 1 ;
ASSERT ( V_48 < V_5 -> V_51 . V_52 ) ;
V_49 = & V_5 -> V_51 . V_53 [ V_48 ] ;
V_49 -> V_54 = V_38 -> V_32 -> V_33 ;
V_49 -> V_55 = V_38 -> V_56 . V_57 ;
V_49 -> V_58 = V_38 -> V_56 . V_59 ;
V_49 -> V_60 = V_38 -> V_56 . V_61 ;
F_10 ( V_49 , V_38 -> V_62 , V_38 -> V_63 ,
V_38 -> V_56 . V_64 ) ;
}
STATIC void *
F_13 (
struct V_2 * V_3 ,
void * V_46 ,
unsigned int V_34 )
{
return F_1 ( V_3 , V_46 ) ;
}
STATIC int
F_14 (
struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_25 * V_47 ,
void * V_65 ,
void * * V_18 )
{
struct V_28 * V_38 ;
int error ;
V_38 = F_7 ( V_47 , struct V_28 , V_31 ) ;
error = F_4 ( V_3 , V_65 , V_10 ,
V_38 -> V_62 ,
V_38 -> V_32 , V_38 -> V_63 ,
V_38 -> V_56 . V_59 ,
V_38 -> V_56 . V_57 ,
V_38 -> V_56 . V_61 ,
V_38 -> V_56 . V_64 ) ;
F_15 ( V_38 ) ;
return error ;
}
STATIC void
F_16 (
void * V_46 )
{
F_17 ( V_46 ) ;
}
STATIC void
F_18 (
struct V_25 * V_47 )
{
struct V_28 * V_38 ;
V_38 = F_7 ( V_47 , struct V_28 , V_31 ) ;
F_15 ( V_38 ) ;
}
void
F_19 ( void )
{
F_20 ( & V_66 ) ;
}
