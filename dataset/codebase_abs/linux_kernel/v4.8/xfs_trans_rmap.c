static void
F_1 (
struct V_1 * V_2 ,
enum V_3 type ,
int V_4 ,
T_1 V_5 )
{
V_2 -> V_6 = 0 ;
if ( V_5 == V_7 )
V_2 -> V_6 |= V_8 ;
if ( V_4 == V_9 )
V_2 -> V_6 |= V_10 ;
switch ( type ) {
case V_11 :
V_2 -> V_6 |= V_12 ;
break;
case V_13 :
V_2 -> V_6 |= V_14 ;
break;
case V_15 :
V_2 -> V_6 |= V_16 ;
break;
case V_17 :
V_2 -> V_6 |= V_18 ;
break;
case V_19 :
V_2 -> V_6 |= V_20 ;
break;
default:
ASSERT ( 0 ) ;
}
}
struct V_21 *
F_2 (
struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_21 * V_26 ;
V_26 = F_3 ( V_23 -> V_27 , V_25 ) ;
F_4 ( V_23 , & V_26 -> V_28 ) ;
return V_26 ;
}
int
F_5 (
struct V_22 * V_23 ,
struct V_21 * V_26 ,
enum V_3 type ,
T_2 V_29 ,
int V_4 ,
T_3 V_30 ,
T_4 V_31 ,
T_5 V_32 ,
T_1 V_5 ,
struct V_33 * * V_34 )
{
int error ;
error = F_6 ( V_23 , type , V_29 , V_4 , V_30 ,
V_31 , V_32 , V_5 , V_34 ) ;
V_23 -> V_35 |= V_36 ;
V_26 -> V_28 . V_37 -> V_38 |= V_39 ;
return error ;
}
static int
F_7 (
void * V_40 ,
struct V_41 * V_42 ,
struct V_41 * V_43 )
{
struct V_44 * V_45 = V_40 ;
struct V_46 * V_47 ;
struct V_46 * V_48 ;
V_47 = F_8 ( V_42 , struct V_46 , V_49 ) ;
V_48 = F_8 ( V_43 , struct V_46 , V_49 ) ;
return F_9 ( V_45 , V_47 -> V_50 . V_51 ) -
F_9 ( V_45 , V_48 -> V_50 . V_51 ) ;
}
STATIC void *
F_10 (
struct V_22 * V_23 ,
unsigned int V_52 )
{
struct V_24 * V_25 ;
ASSERT ( V_23 != NULL ) ;
ASSERT ( V_52 > 0 ) ;
V_25 = F_11 ( V_23 -> V_27 , V_52 ) ;
ASSERT ( V_25 != NULL ) ;
F_4 ( V_23 , & V_25 -> V_53 ) ;
return V_25 ;
}
STATIC void
F_12 (
struct V_22 * V_23 ,
void * V_54 ,
struct V_41 * V_55 )
{
struct V_24 * V_25 = V_54 ;
struct V_46 * V_2 ;
T_6 V_56 ;
struct V_1 * V_57 ;
V_2 = F_8 ( V_55 , struct V_46 , V_49 ) ;
V_23 -> V_35 |= V_36 ;
V_25 -> V_53 . V_37 -> V_38 |= V_39 ;
V_56 = F_13 ( & V_25 -> V_58 ) - 1 ;
ASSERT ( V_56 < V_25 -> V_59 . V_60 ) ;
V_57 = & V_25 -> V_59 . V_61 [ V_56 ] ;
V_57 -> V_62 = V_2 -> V_63 ;
V_57 -> V_64 = V_2 -> V_50 . V_51 ;
V_57 -> V_65 = V_2 -> V_50 . V_66 ;
V_57 -> V_67 = V_2 -> V_50 . V_68 ;
F_1 ( V_57 , V_2 -> V_69 , V_2 -> V_70 ,
V_2 -> V_50 . V_71 ) ;
}
STATIC void *
F_14 (
struct V_22 * V_23 ,
void * V_54 ,
unsigned int V_52 )
{
return F_2 ( V_23 , V_54 ) ;
}
STATIC int
F_15 (
struct V_22 * V_23 ,
struct V_72 * V_73 ,
struct V_41 * V_55 ,
void * V_74 ,
void * * V_5 )
{
struct V_46 * V_2 ;
int error ;
V_2 = F_8 ( V_55 , struct V_46 , V_49 ) ;
error = F_5 ( V_23 , V_74 ,
V_2 -> V_69 ,
V_2 -> V_63 , V_2 -> V_70 ,
V_2 -> V_50 . V_66 ,
V_2 -> V_50 . V_51 ,
V_2 -> V_50 . V_68 ,
V_2 -> V_50 . V_71 ,
(struct V_33 * * ) V_5 ) ;
F_16 ( V_2 ) ;
return error ;
}
STATIC void
F_17 (
struct V_22 * V_23 ,
void * V_5 ,
int error )
{
struct V_33 * V_75 = V_5 ;
F_18 ( V_23 , V_75 , error ) ;
}
STATIC void
F_19 (
void * V_54 )
{
F_20 ( V_54 ) ;
}
STATIC void
F_21 (
struct V_41 * V_55 )
{
struct V_46 * V_2 ;
V_2 = F_8 ( V_55 , struct V_46 , V_49 ) ;
F_16 ( V_2 ) ;
}
void
F_22 ( void )
{
F_23 ( & V_76 ) ;
}
