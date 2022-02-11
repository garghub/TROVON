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
case V_21 :
V_2 -> V_6 |= V_22 ;
break;
case V_23 :
V_2 -> V_6 |= V_24 ;
break;
case V_25 :
V_2 -> V_6 |= V_26 ;
break;
default:
ASSERT ( 0 ) ;
}
}
struct V_27 *
F_2 (
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_27 * V_32 ;
V_32 = F_3 ( V_29 -> V_33 , V_31 ) ;
F_4 ( V_29 , & V_32 -> V_34 ) ;
return V_32 ;
}
int
F_5 (
struct V_28 * V_29 ,
struct V_27 * V_32 ,
enum V_3 type ,
T_2 V_35 ,
int V_4 ,
T_3 V_36 ,
T_4 V_37 ,
T_5 V_38 ,
T_1 V_5 ,
struct V_39 * * V_40 )
{
int error ;
error = F_6 ( V_29 , type , V_35 , V_4 , V_36 ,
V_37 , V_38 , V_5 , V_40 ) ;
V_29 -> V_41 |= V_42 ;
V_32 -> V_34 . V_43 -> V_44 |= V_45 ;
return error ;
}
static int
F_7 (
void * V_46 ,
struct V_47 * V_48 ,
struct V_47 * V_49 )
{
struct V_50 * V_51 = V_46 ;
struct V_52 * V_53 ;
struct V_52 * V_54 ;
V_53 = F_8 ( V_48 , struct V_52 , V_55 ) ;
V_54 = F_8 ( V_49 , struct V_52 , V_55 ) ;
return F_9 ( V_51 , V_53 -> V_56 . V_57 ) -
F_9 ( V_51 , V_54 -> V_56 . V_57 ) ;
}
STATIC void *
F_10 (
struct V_28 * V_29 ,
unsigned int V_58 )
{
struct V_30 * V_31 ;
ASSERT ( V_29 != NULL ) ;
ASSERT ( V_58 > 0 ) ;
V_31 = F_11 ( V_29 -> V_33 , V_58 ) ;
ASSERT ( V_31 != NULL ) ;
F_4 ( V_29 , & V_31 -> V_59 ) ;
return V_31 ;
}
STATIC void
F_12 (
struct V_28 * V_29 ,
void * V_60 ,
struct V_47 * V_61 )
{
struct V_30 * V_31 = V_60 ;
struct V_52 * V_2 ;
T_6 V_62 ;
struct V_1 * V_63 ;
V_2 = F_8 ( V_61 , struct V_52 , V_55 ) ;
V_29 -> V_41 |= V_42 ;
V_31 -> V_59 . V_43 -> V_44 |= V_45 ;
V_62 = F_13 ( & V_31 -> V_64 ) - 1 ;
ASSERT ( V_62 < V_31 -> V_65 . V_66 ) ;
V_63 = & V_31 -> V_65 . V_67 [ V_62 ] ;
V_63 -> V_68 = V_2 -> V_69 ;
V_63 -> V_70 = V_2 -> V_56 . V_57 ;
V_63 -> V_71 = V_2 -> V_56 . V_72 ;
V_63 -> V_73 = V_2 -> V_56 . V_74 ;
F_1 ( V_63 , V_2 -> V_75 , V_2 -> V_76 ,
V_2 -> V_56 . V_77 ) ;
}
STATIC void *
F_14 (
struct V_28 * V_29 ,
void * V_60 ,
unsigned int V_58 )
{
return F_2 ( V_29 , V_60 ) ;
}
STATIC int
F_15 (
struct V_28 * V_29 ,
struct V_78 * V_79 ,
struct V_47 * V_61 ,
void * V_80 ,
void * * V_5 )
{
struct V_52 * V_2 ;
int error ;
V_2 = F_8 ( V_61 , struct V_52 , V_55 ) ;
error = F_5 ( V_29 , V_80 ,
V_2 -> V_75 ,
V_2 -> V_69 , V_2 -> V_76 ,
V_2 -> V_56 . V_72 ,
V_2 -> V_56 . V_57 ,
V_2 -> V_56 . V_74 ,
V_2 -> V_56 . V_77 ,
(struct V_39 * * ) V_5 ) ;
F_16 ( V_2 ) ;
return error ;
}
STATIC void
F_17 (
struct V_28 * V_29 ,
void * V_5 ,
int error )
{
struct V_39 * V_81 = V_5 ;
F_18 ( V_29 , V_81 , error ) ;
}
STATIC void
F_19 (
void * V_60 )
{
F_20 ( V_60 ) ;
}
STATIC void
F_21 (
struct V_47 * V_61 )
{
struct V_52 * V_2 ;
V_2 = F_8 ( V_61 , struct V_52 , V_55 ) ;
F_16 ( V_2 ) ;
}
void
F_22 ( void )
{
F_23 ( & V_82 ) ;
}
