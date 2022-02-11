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
T_1 V_12 ,
T_2 V_13 ,
T_1 * V_14 ,
T_2 * V_15 ,
struct V_16 * * V_17 )
{
int error ;
error = F_5 ( V_3 , V_10 , type , V_12 ,
V_13 , V_14 , V_15 , V_17 ) ;
V_3 -> V_18 |= V_19 ;
V_6 -> V_8 . V_20 -> V_21 |= V_22 ;
return error ;
}
static int
F_6 (
void * V_23 ,
struct V_24 * V_25 ,
struct V_24 * V_26 )
{
struct V_27 * V_28 = V_23 ;
struct V_29 * V_30 ;
struct V_29 * V_31 ;
V_30 = F_7 ( V_25 , struct V_29 , V_32 ) ;
V_31 = F_7 ( V_26 , struct V_29 , V_32 ) ;
return F_8 ( V_28 , V_30 -> V_33 ) -
F_8 ( V_28 , V_31 -> V_33 ) ;
}
STATIC void *
F_9 (
struct V_2 * V_3 ,
unsigned int V_34 )
{
struct V_4 * V_5 ;
ASSERT ( V_3 != NULL ) ;
ASSERT ( V_34 > 0 ) ;
V_5 = F_10 ( V_3 -> V_7 , V_34 ) ;
ASSERT ( V_5 != NULL ) ;
F_3 ( V_3 , & V_5 -> V_35 ) ;
return V_5 ;
}
static void
F_11 (
struct V_36 * V_37 ,
enum V_11 type )
{
V_37 -> V_38 = 0 ;
switch ( type ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_37 -> V_38 |= type ;
break;
default:
ASSERT ( 0 ) ;
}
}
STATIC void
F_12 (
struct V_2 * V_3 ,
void * V_43 ,
struct V_24 * V_44 )
{
struct V_4 * V_5 = V_43 ;
struct V_29 * V_37 ;
T_3 V_45 ;
struct V_36 * V_46 ;
V_37 = F_7 ( V_44 , struct V_29 , V_32 ) ;
V_3 -> V_18 |= V_19 ;
V_5 -> V_35 . V_20 -> V_21 |= V_22 ;
V_45 = F_13 ( & V_5 -> V_47 ) - 1 ;
ASSERT ( V_45 < V_5 -> V_48 . V_49 ) ;
V_46 = & V_5 -> V_48 . V_50 [ V_45 ] ;
V_46 -> V_51 = V_37 -> V_33 ;
V_46 -> V_52 = V_37 -> V_53 ;
F_11 ( V_46 , V_37 -> V_54 ) ;
}
STATIC void *
F_14 (
struct V_2 * V_3 ,
void * V_43 ,
unsigned int V_34 )
{
return F_1 ( V_3 , V_43 ) ;
}
STATIC int
F_15 (
struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_24 * V_44 ,
void * V_55 ,
void * * V_56 )
{
struct V_29 * V_37 ;
T_1 V_14 ;
T_2 V_57 ;
int error ;
V_37 = F_7 ( V_44 , struct V_29 , V_32 ) ;
error = F_4 ( V_3 , V_55 , V_10 ,
V_37 -> V_54 ,
V_37 -> V_33 ,
V_37 -> V_53 ,
& V_14 , & V_57 ,
(struct V_16 * * ) V_56 ) ;
if ( ! error && V_57 > 0 ) {
ASSERT ( V_37 -> V_54 == V_39 ||
V_37 -> V_54 == V_40 ) ;
V_37 -> V_33 = V_14 ;
V_37 -> V_53 = V_57 ;
return - V_58 ;
}
F_16 ( V_37 ) ;
return error ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
void * V_56 ,
int error )
{
struct V_16 * V_59 = V_56 ;
F_18 ( V_3 , V_59 , error ) ;
}
STATIC void
F_19 (
void * V_43 )
{
F_20 ( V_43 ) ;
}
STATIC void
F_21 (
struct V_24 * V_44 )
{
struct V_29 * V_37 ;
V_37 = F_7 ( V_44 , struct V_29 , V_32 ) ;
F_16 ( V_37 ) ;
}
void
F_22 ( void )
{
F_23 ( & V_60 ) ;
}
