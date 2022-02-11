static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 (
struct V_1 * V_5 )
{
if ( V_5 -> V_6 . V_7 > V_8 )
F_4 ( V_5 ) ;
else
F_5 ( V_9 , V_5 ) ;
}
STATIC void
F_6 (
struct V_2 * V_3 ,
int * V_10 ,
int * V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
* V_10 += 1 ;
* V_11 += F_7 ( V_5 -> V_6 . V_7 ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = NULL ;
ASSERT ( F_9 ( & V_5 -> V_16 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_17 = V_18 ;
V_5 -> V_6 . V_19 = 1 ;
F_10 ( V_13 , & V_15 , V_20 , & V_5 -> V_6 ,
F_7 ( V_5 -> V_6 . V_7 ) ) ;
}
STATIC void
F_11 (
struct V_2 * V_3 )
{
}
STATIC void
F_12 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_13 ( V_5 ) ;
}
STATIC T_1
F_14 (
struct V_2 * V_3 ,
struct V_21 * V_22 )
{
return V_23 ;
}
STATIC void
F_15 (
struct V_2 * V_3 )
{
if ( V_3 -> V_24 & V_25 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_16 (
struct V_2 * V_3 ,
T_2 V_26 )
{
return V_26 ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
T_2 V_26 )
{
}
struct V_1 *
F_18 (
struct V_27 * V_28 ,
T_1 V_29 )
{
struct V_1 * V_5 ;
ASSERT ( V_29 > 0 ) ;
if ( V_29 > V_8 )
V_5 = F_19 ( F_20 ( V_29 ) ,
V_30 ) ;
else
V_5 = F_21 ( V_9 , V_30 ) ;
F_22 ( V_28 , & V_5 -> V_4 , V_18 , & V_31 ) ;
V_5 -> V_6 . V_7 = V_29 ;
V_5 -> V_6 . V_32 = ( V_33 ) ( void * ) V_5 ;
F_23 ( & V_5 -> V_16 , 0 ) ;
F_23 ( & V_5 -> V_34 , 2 ) ;
return V_5 ;
}
void
F_13 (
struct V_1 * V_5 )
{
ASSERT ( F_9 ( & V_5 -> V_34 ) > 0 ) ;
if ( F_24 ( & V_5 -> V_34 ) ) {
F_25 ( & V_5 -> V_4 , V_35 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_36 * F_26 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_36 , V_37 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int * V_10 ,
int * V_11 )
{
* V_10 += 1 ;
* V_11 += sizeof( struct V_38 ) ;
}
STATIC void
F_28 (
struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_36 * V_39 = F_26 ( V_3 ) ;
struct V_14 * V_15 = NULL ;
V_39 -> V_40 . V_41 = V_42 ;
V_39 -> V_40 . V_43 = 1 ;
F_10 ( V_13 , & V_15 , V_44 , & V_39 -> V_40 ,
sizeof( struct V_38 ) ) ;
}
STATIC void
F_29 (
struct V_2 * V_3 )
{
}
STATIC void
F_30 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_31 (
struct V_2 * V_3 ,
struct V_21 * V_22 )
{
return V_23 ;
}
STATIC void
F_32 (
struct V_2 * V_3 )
{
struct V_36 * V_39 = F_26 ( V_3 ) ;
if ( V_3 -> V_24 & V_25 ) {
F_13 ( V_39 -> V_45 ) ;
F_5 ( V_46 , V_39 ) ;
}
}
STATIC T_2
F_33 (
struct V_2 * V_3 ,
T_2 V_26 )
{
struct V_36 * V_39 = F_26 ( V_3 ) ;
F_13 ( V_39 -> V_45 ) ;
F_5 ( V_46 , V_39 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_34 (
struct V_2 * V_3 ,
T_2 V_26 )
{
}
struct V_36 *
F_35 (
struct V_27 * V_28 ,
struct V_1 * V_5 )
{
struct V_36 * V_39 ;
V_39 = F_21 ( V_46 , V_30 ) ;
F_22 ( V_28 , & V_39 -> V_37 , V_42 , & V_47 ) ;
V_39 -> V_45 = V_5 ;
V_39 -> V_40 . V_48 = V_5 -> V_6 . V_32 ;
return V_39 ;
}
int
F_36 (
struct V_27 * V_28 ,
struct V_1 * V_5 )
{
int V_49 ;
int error = 0 ;
unsigned int V_50 ;
struct V_51 * V_52 ;
T_3 V_53 ;
bool V_54 ;
struct V_36 * V_39 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = NULL ;
enum V_59 type ;
T_3 V_60 ;
T_3 V_61 ;
T_4 V_62 ;
struct V_63 V_64 ;
struct V_65 V_66 ;
bool V_67 = false ;
ASSERT ( ! F_37 ( V_68 , & V_5 -> V_69 ) ) ;
for ( V_49 = 0 ; V_49 < V_5 -> V_6 . V_7 ; V_49 ++ ) {
V_52 = & V_5 -> V_6 . V_70 [ V_49 ] ;
V_53 = F_38 ( V_28 ,
F_39 ( V_28 , V_52 -> V_71 ) ) ;
switch ( V_52 -> V_72 & V_73 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_54 = true ;
break;
default:
V_54 = false ;
break;
}
if ( ! V_54 || V_53 == 0 ||
V_52 -> V_78 == 0 ||
V_53 >= V_28 -> V_79 . V_80 ||
V_52 -> V_78 >= V_28 -> V_79 . V_81 ||
( V_52 -> V_72 & ~ V_82 ) ) {
F_40 ( V_68 , & V_5 -> V_69 ) ;
F_13 ( V_5 ) ;
return - V_83 ;
}
}
error = F_41 ( V_28 , & F_42 ( V_28 ) -> V_84 , 0 , 0 , 0 , & V_56 ) ;
if ( error )
return error ;
V_39 = F_43 ( V_56 , V_5 ) ;
F_44 ( & V_66 , & V_60 ) ;
for ( V_49 = 0 ; V_49 < V_5 -> V_6 . V_7 ; V_49 ++ ) {
V_52 = & V_5 -> V_6 . V_70 [ V_49 ] ;
V_50 = V_52 -> V_72 & V_73 ;
switch ( V_50 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
type = V_50 ;
break;
default:
error = - V_85 ;
goto V_86;
}
if ( V_67 ) {
V_61 = V_52 -> V_71 ;
V_62 = V_52 -> V_78 ;
} else
error = F_45 ( V_56 , V_39 ,
& V_66 , type , V_52 -> V_71 , V_52 -> V_78 ,
& V_61 , & V_62 , & V_58 ) ;
if ( error )
goto V_86;
if ( V_62 > 0 ) {
V_64 . V_87 = V_61 ;
V_64 . V_88 = V_62 ;
switch ( type ) {
case V_74 :
error = F_46 (
V_56 -> V_89 , & V_66 , & V_64 ) ;
break;
case V_75 :
error = F_47 (
V_56 -> V_89 , & V_66 , & V_64 ) ;
break;
case V_76 :
error = F_48 (
V_56 -> V_89 , & V_66 ,
V_64 . V_87 ,
V_64 . V_88 ) ;
break;
case V_77 :
error = F_49 (
V_56 -> V_89 , & V_66 ,
V_64 . V_87 ,
V_64 . V_88 ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_86;
V_67 = true ;
}
}
F_50 ( V_56 , V_58 , error ) ;
error = F_51 ( & V_56 , & V_66 ) ;
if ( error )
goto V_90;
F_40 ( V_68 , & V_5 -> V_69 ) ;
error = F_52 ( V_56 ) ;
return error ;
V_86:
F_50 ( V_56 , V_58 , error ) ;
V_90:
F_53 ( & V_66 ) ;
F_54 ( V_56 ) ;
return error ;
}
