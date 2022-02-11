static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 (
struct V_1 * V_5 )
{
F_4 ( V_6 , V_5 ) ;
}
STATIC void
F_5 (
struct V_2 * V_3 ,
int * V_7 ,
int * V_8 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
* V_7 += 1 ;
* V_8 += F_6 ( V_5 -> V_9 . V_10 ) ;
}
STATIC void
F_7 (
struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_14 = NULL ;
ASSERT ( F_8 ( & V_5 -> V_15 ) ==
V_5 -> V_9 . V_10 ) ;
V_5 -> V_9 . V_16 = V_17 ;
V_5 -> V_9 . V_18 = 1 ;
F_9 ( V_12 , & V_14 , V_19 , & V_5 -> V_9 ,
F_6 ( V_5 -> V_9 . V_10 ) ) ;
}
STATIC void
F_10 (
struct V_2 * V_3 )
{
}
STATIC void
F_11 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_12 ( V_5 ) ;
}
STATIC T_1
F_13 (
struct V_2 * V_3 ,
struct V_20 * V_21 )
{
return V_22 ;
}
STATIC void
F_14 (
struct V_2 * V_3 )
{
if ( V_3 -> V_23 & V_24 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_15 (
struct V_2 * V_3 ,
T_2 V_25 )
{
return V_25 ;
}
STATIC void
F_16 (
struct V_2 * V_3 ,
T_2 V_25 )
{
}
struct V_1 *
F_17 (
struct V_26 * V_27 )
{
struct V_1 * V_5 ;
V_5 = F_18 ( V_6 , V_28 ) ;
F_19 ( V_27 , & V_5 -> V_4 , V_17 , & V_29 ) ;
V_5 -> V_9 . V_10 = V_30 ;
V_5 -> V_9 . V_31 = ( V_32 ) ( void * ) V_5 ;
F_20 ( & V_5 -> V_15 , 0 ) ;
F_20 ( & V_5 -> V_33 , 2 ) ;
return V_5 ;
}
void
F_12 (
struct V_1 * V_5 )
{
ASSERT ( F_8 ( & V_5 -> V_33 ) > 0 ) ;
if ( F_21 ( & V_5 -> V_33 ) ) {
F_22 ( & V_5 -> V_4 , V_34 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_35 * F_23 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_35 , V_36 ) ;
}
STATIC void
F_24 (
struct V_2 * V_3 ,
int * V_7 ,
int * V_8 )
{
* V_7 += 1 ;
* V_8 += sizeof( struct V_37 ) ;
}
STATIC void
F_25 (
struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_35 * V_38 = F_23 ( V_3 ) ;
struct V_13 * V_14 = NULL ;
V_38 -> V_39 . V_40 = V_41 ;
V_38 -> V_39 . V_42 = 1 ;
F_9 ( V_12 , & V_14 , V_43 , & V_38 -> V_39 ,
sizeof( struct V_37 ) ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 )
{
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_28 (
struct V_2 * V_3 ,
struct V_20 * V_21 )
{
return V_22 ;
}
STATIC void
F_29 (
struct V_2 * V_3 )
{
struct V_35 * V_38 = F_23 ( V_3 ) ;
if ( V_3 -> V_23 & V_24 ) {
F_12 ( V_38 -> V_44 ) ;
F_4 ( V_45 , V_38 ) ;
}
}
STATIC T_2
F_30 (
struct V_2 * V_3 ,
T_2 V_25 )
{
struct V_35 * V_38 = F_23 ( V_3 ) ;
F_12 ( V_38 -> V_44 ) ;
F_4 ( V_45 , V_38 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_31 (
struct V_2 * V_3 ,
T_2 V_25 )
{
}
struct V_35 *
F_32 (
struct V_26 * V_27 ,
struct V_1 * V_5 )
{
struct V_35 * V_38 ;
V_38 = F_18 ( V_45 , V_28 ) ;
F_19 ( V_27 , & V_38 -> V_36 , V_41 , & V_46 ) ;
V_38 -> V_44 = V_5 ;
V_38 -> V_39 . V_47 = V_5 -> V_9 . V_31 ;
return V_38 ;
}
int
F_33 (
struct V_26 * V_27 ,
struct V_1 * V_5 )
{
int error = 0 ;
unsigned int V_16 ;
struct V_48 * V_49 ;
T_3 V_50 ;
T_3 V_51 ;
bool V_52 ;
struct V_35 * V_38 ;
enum V_53 type ;
int V_54 ;
T_4 V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = NULL ;
struct V_60 V_61 ;
T_3 V_62 ;
ASSERT ( ! F_34 ( V_63 , & V_5 -> V_64 ) ) ;
if ( V_5 -> V_9 . V_10 != V_30 ) {
F_35 ( V_63 , & V_5 -> V_64 ) ;
F_12 ( V_5 ) ;
return - V_65 ;
}
V_49 = & V_5 -> V_9 . V_66 [ 0 ] ;
V_50 = F_36 ( V_27 ,
F_37 ( V_27 , V_49 -> V_67 ) ) ;
V_51 = F_36 ( V_27 , F_37 ( V_27 ,
F_38 ( V_27 , V_49 -> V_68 ) ) ) ;
switch ( V_49 -> V_69 & V_70 ) {
case V_71 :
case V_72 :
V_52 = true ;
break;
default:
V_52 = false ;
break;
}
if ( ! V_52 || V_50 == 0 ||
V_49 -> V_73 == 0 ||
V_51 == 0 ||
V_50 >= V_27 -> V_74 . V_75 ||
V_49 -> V_73 >= V_27 -> V_74 . V_76 ||
V_51 >= V_27 -> V_74 . V_75 ||
( V_49 -> V_69 & ~ V_77 ) ) {
F_35 ( V_63 , & V_5 -> V_64 ) ;
F_12 ( V_5 ) ;
return - V_65 ;
}
error = F_39 ( V_27 , & F_40 ( V_27 ) -> V_78 ,
F_41 ( V_27 , V_79 ) , 0 , 0 , & V_57 ) ;
if ( error )
return error ;
V_38 = F_42 ( V_57 , V_5 ) ;
error = F_43 ( V_27 , V_57 , V_49 -> V_68 , 0 , V_80 , & V_59 ) ;
if ( error )
goto V_81;
if ( F_44 ( V_59 ) -> V_82 == 0 )
F_45 ( V_59 , V_83 ) ;
F_46 ( & V_61 , & V_62 ) ;
V_55 = ( V_49 -> V_69 & V_84 ) ?
V_85 : V_86 ;
V_54 = ( V_49 -> V_69 & V_87 ) ?
V_88 : V_79 ;
V_16 = V_49 -> V_69 & V_70 ;
switch ( V_16 ) {
case V_71 :
case V_72 :
type = V_16 ;
break;
default:
error = - V_89 ;
goto V_90;
}
F_47 ( V_57 , V_59 , 0 ) ;
error = F_48 ( V_57 , V_38 , & V_61 , type ,
V_59 , V_54 , V_49 -> V_91 ,
V_49 -> V_67 , V_49 -> V_73 ,
V_55 ) ;
if ( error )
goto V_90;
error = F_49 ( & V_57 , & V_61 , NULL ) ;
if ( error )
goto V_90;
F_35 ( V_63 , & V_5 -> V_64 ) ;
error = F_50 ( V_57 ) ;
F_51 ( V_59 , V_80 ) ;
F_52 ( V_59 ) ;
return error ;
V_90:
F_53 ( & V_61 ) ;
V_81:
F_54 ( V_57 ) ;
if ( V_59 ) {
F_51 ( V_59 , V_80 ) ;
F_52 ( V_59 ) ;
}
return error ;
}
