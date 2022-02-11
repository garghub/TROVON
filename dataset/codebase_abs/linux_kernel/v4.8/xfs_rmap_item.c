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
static inline int
F_6 (
struct V_1 * V_5 )
{
return sizeof( struct V_10 ) +
( V_5 -> V_6 . V_7 - 1 ) *
sizeof( struct V_11 ) ;
}
STATIC void
F_7 (
struct V_2 * V_3 ,
int * V_12 ,
int * V_13 )
{
* V_12 += 1 ;
* V_13 += F_6 ( F_1 ( V_3 ) ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = NULL ;
ASSERT ( F_9 ( & V_5 -> V_18 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_19 = V_20 ;
V_5 -> V_6 . V_21 = 1 ;
F_10 ( V_15 , & V_17 , V_22 , & V_5 -> V_6 ,
F_6 ( V_5 ) ) ;
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
struct V_23 * V_24 )
{
return V_25 ;
}
STATIC void
F_15 (
struct V_2 * V_3 )
{
if ( V_3 -> V_26 & V_27 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_16 (
struct V_2 * V_3 ,
T_2 V_28 )
{
return V_28 ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
T_2 V_28 )
{
}
struct V_1 *
F_18 (
struct V_29 * V_30 ,
T_1 V_31 )
{
struct V_1 * V_5 ;
T_1 V_32 ;
ASSERT ( V_31 > 0 ) ;
if ( V_31 > V_8 ) {
V_32 = ( T_1 ) ( sizeof( struct V_1 ) +
( ( V_31 - 1 ) * sizeof( struct V_11 ) ) ) ;
V_5 = F_19 ( V_32 , V_33 ) ;
} else {
V_5 = F_20 ( V_9 , V_33 ) ;
}
F_21 ( V_30 , & V_5 -> V_4 , V_20 , & V_34 ) ;
V_5 -> V_6 . V_7 = V_31 ;
V_5 -> V_6 . V_35 = ( V_36 ) ( void * ) V_5 ;
F_22 ( & V_5 -> V_18 , 0 ) ;
F_22 ( & V_5 -> V_37 , 2 ) ;
return V_5 ;
}
int
F_23 (
struct V_16 * V_38 ,
struct V_10 * V_39 )
{
struct V_10 * V_40 ;
T_1 V_41 ;
V_40 = V_38 -> V_42 ;
V_41 = sizeof( struct V_10 ) +
( V_40 -> V_7 - 1 ) *
sizeof( struct V_11 ) ;
if ( V_38 -> V_43 != V_41 )
return - V_44 ;
memcpy ( ( char * ) V_39 , ( char * ) V_40 , V_41 ) ;
return 0 ;
}
void
F_13 (
struct V_1 * V_5 )
{
if ( F_24 ( & V_5 -> V_37 ) ) {
F_25 ( & V_5 -> V_4 , V_45 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_46 * F_26 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_46 , V_47 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int * V_12 ,
int * V_13 )
{
* V_12 += 1 ;
* V_13 += sizeof( struct V_48 ) ;
}
STATIC void
F_28 (
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_46 * V_49 = F_26 ( V_3 ) ;
struct V_16 * V_17 = NULL ;
V_49 -> V_50 . V_51 = V_52 ;
V_49 -> V_50 . V_53 = 1 ;
F_10 ( V_15 , & V_17 , V_54 , & V_49 -> V_50 ,
sizeof( struct V_48 ) ) ;
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
struct V_23 * V_24 )
{
return V_25 ;
}
STATIC void
F_32 (
struct V_2 * V_3 )
{
struct V_46 * V_49 = F_26 ( V_3 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_13 ( V_49 -> V_55 ) ;
F_5 ( V_56 , V_49 ) ;
}
}
STATIC T_2
F_33 (
struct V_2 * V_3 ,
T_2 V_28 )
{
struct V_46 * V_49 = F_26 ( V_3 ) ;
F_13 ( V_49 -> V_55 ) ;
F_5 ( V_56 , V_49 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_34 (
struct V_2 * V_3 ,
T_2 V_28 )
{
}
struct V_46 *
F_35 (
struct V_29 * V_30 ,
struct V_1 * V_5 )
{
struct V_46 * V_49 ;
V_49 = F_20 ( V_56 , V_33 ) ;
F_21 ( V_30 , & V_49 -> V_47 , V_52 , & V_57 ) ;
V_49 -> V_55 = V_5 ;
V_49 -> V_50 . V_58 = V_5 -> V_6 . V_35 ;
return V_49 ;
}
int
F_36 (
struct V_29 * V_30 ,
struct V_1 * V_5 )
{
int V_59 ;
int error = 0 ;
struct V_11 * V_60 ;
T_3 V_61 ;
bool V_62 ;
struct V_46 * V_49 ;
enum V_63 type ;
int V_64 ;
T_4 V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 = NULL ;
ASSERT ( ! F_37 ( V_70 , & V_5 -> V_71 ) ) ;
for ( V_59 = 0 ; V_59 < V_5 -> V_6 . V_7 ; V_59 ++ ) {
V_60 = & V_5 -> V_6 . V_72 [ V_59 ] ;
V_61 = F_38 ( V_30 ,
F_39 ( V_30 , V_60 -> V_73 ) ) ;
switch ( V_60 -> V_74 & V_75 ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_62 = true ;
break;
default:
V_62 = false ;
break;
}
if ( ! V_62 || V_61 == 0 ||
V_60 -> V_81 == 0 ||
V_61 >= V_30 -> V_82 . V_83 ||
V_60 -> V_81 >= V_30 -> V_82 . V_84 ||
( V_60 -> V_74 & ~ V_85 ) ) {
F_40 ( V_70 , & V_5 -> V_71 ) ;
F_13 ( V_5 ) ;
return - V_86 ;
}
}
error = F_41 ( V_30 , & F_42 ( V_30 ) -> V_87 , 0 , 0 , 0 , & V_67 ) ;
if ( error )
return error ;
V_49 = F_43 ( V_67 , V_5 ) ;
for ( V_59 = 0 ; V_59 < V_5 -> V_6 . V_7 ; V_59 ++ ) {
V_60 = & V_5 -> V_6 . V_72 [ V_59 ] ;
V_65 = ( V_60 -> V_74 & V_88 ) ?
V_89 : V_90 ;
V_64 = ( V_60 -> V_74 & V_91 ) ?
V_92 : V_93 ;
switch ( V_60 -> V_74 & V_75 ) {
case V_76 :
type = V_94 ;
break;
case V_77 :
type = V_95 ;
break;
case V_78 :
type = V_96 ;
break;
case V_79 :
type = V_97 ;
break;
case V_80 :
type = V_98 ;
break;
default:
error = - V_44 ;
goto V_99;
}
error = F_44 ( V_67 , V_49 , type ,
V_60 -> V_100 , V_64 ,
V_60 -> V_101 , V_60 -> V_73 ,
V_60 -> V_81 , V_65 , & V_69 ) ;
if ( error )
goto V_99;
}
F_45 ( V_67 , V_69 , error ) ;
F_40 ( V_70 , & V_5 -> V_71 ) ;
error = F_46 ( V_67 ) ;
return error ;
V_99:
F_45 ( V_67 , V_69 , error ) ;
F_47 ( V_67 ) ;
return error ;
}
