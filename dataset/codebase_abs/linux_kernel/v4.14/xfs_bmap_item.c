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
T_4 V_52 ;
bool V_53 ;
struct V_35 * V_38 ;
enum V_54 type ;
int V_55 ;
T_5 V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 = NULL ;
struct V_61 V_62 ;
struct V_63 V_64 ;
T_3 V_65 ;
ASSERT ( ! F_34 ( V_66 , & V_5 -> V_67 ) ) ;
if ( V_5 -> V_9 . V_10 != V_30 ) {
F_35 ( V_66 , & V_5 -> V_67 ) ;
F_12 ( V_5 ) ;
return - V_68 ;
}
V_49 = & V_5 -> V_9 . V_69 [ 0 ] ;
V_50 = F_36 ( V_27 ,
F_37 ( V_27 , V_49 -> V_70 ) ) ;
V_51 = F_36 ( V_27 , F_37 ( V_27 ,
F_38 ( V_27 , V_49 -> V_71 ) ) ) ;
switch ( V_49 -> V_72 & V_73 ) {
case V_74 :
case V_75 :
V_53 = true ;
break;
default:
V_53 = false ;
break;
}
if ( ! V_53 || V_50 == 0 ||
V_49 -> V_76 == 0 ||
V_51 == 0 ||
V_50 >= V_27 -> V_77 . V_78 ||
V_49 -> V_76 >= V_27 -> V_77 . V_79 ||
V_51 >= V_27 -> V_77 . V_78 ||
( V_49 -> V_72 & ~ V_80 ) ) {
F_35 ( V_66 , & V_5 -> V_67 ) ;
F_12 ( V_5 ) ;
return - V_68 ;
}
error = F_39 ( V_27 , & F_40 ( V_27 ) -> V_81 ,
F_41 ( V_27 , V_82 ) , 0 , 0 , & V_58 ) ;
if ( error )
return error ;
V_38 = F_42 ( V_58 , V_5 ) ;
error = F_43 ( V_27 , V_58 , V_49 -> V_71 , 0 , V_83 , & V_60 ) ;
if ( error )
goto V_84;
if ( F_44 ( V_60 ) -> V_85 == 0 )
F_45 ( V_60 , V_86 ) ;
F_46 ( & V_62 , & V_65 ) ;
V_56 = ( V_49 -> V_72 & V_87 ) ?
V_88 : V_89 ;
V_55 = ( V_49 -> V_72 & V_90 ) ?
V_91 : V_82 ;
V_16 = V_49 -> V_72 & V_73 ;
switch ( V_16 ) {
case V_74 :
case V_75 :
type = V_16 ;
break;
default:
error = - V_92 ;
goto V_93;
}
F_47 ( V_58 , V_60 , 0 ) ;
V_52 = V_49 -> V_76 ;
error = F_48 ( V_58 , V_38 , & V_62 , type ,
V_60 , V_55 , V_49 -> V_94 ,
V_49 -> V_70 , & V_52 , V_56 ) ;
if ( error )
goto V_93;
if ( V_52 > 0 ) {
ASSERT ( type == V_75 ) ;
V_64 . V_95 = V_49 -> V_70 ;
V_64 . V_96 = V_52 ;
V_64 . V_97 = V_49 -> V_94 ;
V_64 . V_98 = V_56 ;
error = F_49 ( V_58 -> V_99 , & V_62 , V_60 , & V_64 ) ;
if ( error )
goto V_93;
}
error = F_50 ( & V_58 , & V_62 ) ;
if ( error )
goto V_93;
F_35 ( V_66 , & V_5 -> V_67 ) ;
error = F_51 ( V_58 ) ;
F_52 ( V_60 , V_83 ) ;
F_53 ( V_60 ) ;
return error ;
V_93:
F_54 ( & V_62 ) ;
V_84:
F_55 ( V_58 ) ;
if ( V_60 ) {
F_52 ( V_60 , V_83 ) ;
F_53 ( V_60 ) ;
}
return error ;
}
