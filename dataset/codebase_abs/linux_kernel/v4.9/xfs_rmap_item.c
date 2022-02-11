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
V_5 = F_19 ( F_20 ( V_29 ) , V_30 ) ;
else
V_5 = F_21 ( V_9 , V_30 ) ;
F_22 ( V_28 , & V_5 -> V_4 , V_18 , & V_31 ) ;
V_5 -> V_6 . V_7 = V_29 ;
V_5 -> V_6 . V_32 = ( V_33 ) ( void * ) V_5 ;
F_23 ( & V_5 -> V_16 , 0 ) ;
F_23 ( & V_5 -> V_34 , 2 ) ;
return V_5 ;
}
int
F_24 (
struct V_14 * V_35 ,
struct V_36 * V_37 )
{
struct V_36 * V_38 ;
T_1 V_39 ;
V_38 = V_35 -> V_40 ;
V_39 = F_7 ( V_38 -> V_7 ) ;
if ( V_35 -> V_41 != V_39 )
return - V_42 ;
memcpy ( V_37 , V_38 , V_39 ) ;
return 0 ;
}
void
F_13 (
struct V_1 * V_5 )
{
if ( F_25 ( & V_5 -> V_34 ) ) {
F_26 ( & V_5 -> V_4 , V_43 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_44 * F_27 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_44 , V_45 ) ;
}
STATIC void
F_28 (
struct V_2 * V_3 ,
int * V_10 ,
int * V_11 )
{
* V_10 += 1 ;
* V_11 += sizeof( struct V_46 ) ;
}
STATIC void
F_29 (
struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_44 * V_47 = F_27 ( V_3 ) ;
struct V_14 * V_15 = NULL ;
V_47 -> V_48 . V_49 = V_50 ;
V_47 -> V_48 . V_51 = 1 ;
F_10 ( V_13 , & V_15 , V_52 , & V_47 -> V_48 ,
sizeof( struct V_46 ) ) ;
}
STATIC void
F_30 (
struct V_2 * V_3 )
{
}
STATIC void
F_31 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_32 (
struct V_2 * V_3 ,
struct V_21 * V_22 )
{
return V_23 ;
}
STATIC void
F_33 (
struct V_2 * V_3 )
{
struct V_44 * V_47 = F_27 ( V_3 ) ;
if ( V_3 -> V_24 & V_25 ) {
F_13 ( V_47 -> V_53 ) ;
F_5 ( V_54 , V_47 ) ;
}
}
STATIC T_2
F_34 (
struct V_2 * V_3 ,
T_2 V_26 )
{
struct V_44 * V_47 = F_27 ( V_3 ) ;
F_13 ( V_47 -> V_53 ) ;
F_5 ( V_54 , V_47 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_35 (
struct V_2 * V_3 ,
T_2 V_26 )
{
}
struct V_44 *
F_36 (
struct V_27 * V_28 ,
struct V_1 * V_5 )
{
struct V_44 * V_47 ;
V_47 = F_21 ( V_54 , V_30 ) ;
F_22 ( V_28 , & V_47 -> V_45 , V_50 , & V_55 ) ;
V_47 -> V_53 = V_5 ;
V_47 -> V_48 . V_56 = V_5 -> V_6 . V_32 ;
return V_47 ;
}
int
F_37 (
struct V_27 * V_28 ,
struct V_1 * V_5 )
{
int V_57 ;
int error = 0 ;
struct V_58 * V_59 ;
T_3 V_60 ;
bool V_61 ;
struct V_44 * V_47 ;
enum V_62 type ;
int V_63 ;
T_4 V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = NULL ;
ASSERT ( ! F_38 ( V_69 , & V_5 -> V_70 ) ) ;
for ( V_57 = 0 ; V_57 < V_5 -> V_6 . V_7 ; V_57 ++ ) {
V_59 = & V_5 -> V_6 . V_71 [ V_57 ] ;
V_60 = F_39 ( V_28 ,
F_40 ( V_28 , V_59 -> V_72 ) ) ;
switch ( V_59 -> V_73 & V_74 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
V_61 = true ;
break;
default:
V_61 = false ;
break;
}
if ( ! V_61 || V_60 == 0 ||
V_59 -> V_83 == 0 ||
V_60 >= V_28 -> V_84 . V_85 ||
V_59 -> V_83 >= V_28 -> V_84 . V_86 ||
( V_59 -> V_73 & ~ V_87 ) ) {
F_41 ( V_69 , & V_5 -> V_70 ) ;
F_13 ( V_5 ) ;
return - V_88 ;
}
}
error = F_42 ( V_28 , & F_43 ( V_28 ) -> V_89 , 0 , 0 , 0 , & V_66 ) ;
if ( error )
return error ;
V_47 = F_44 ( V_66 , V_5 ) ;
for ( V_57 = 0 ; V_57 < V_5 -> V_6 . V_7 ; V_57 ++ ) {
V_59 = & V_5 -> V_6 . V_71 [ V_57 ] ;
V_64 = ( V_59 -> V_73 & V_90 ) ?
V_91 : V_92 ;
V_63 = ( V_59 -> V_73 & V_93 ) ?
V_94 : V_95 ;
switch ( V_59 -> V_73 & V_74 ) {
case V_75 :
type = V_96 ;
break;
case V_76 :
type = V_97 ;
break;
case V_77 :
type = V_98 ;
break;
case V_78 :
type = V_99 ;
break;
case V_79 :
type = V_100 ;
break;
case V_80 :
type = V_101 ;
break;
case V_81 :
type = V_102 ;
break;
case V_82 :
type = V_103 ;
break;
default:
error = - V_42 ;
goto V_104;
}
error = F_45 ( V_66 , V_47 , type ,
V_59 -> V_105 , V_63 ,
V_59 -> V_106 , V_59 -> V_72 ,
V_59 -> V_83 , V_64 , & V_68 ) ;
if ( error )
goto V_104;
}
F_46 ( V_66 , V_68 , error ) ;
F_41 ( V_69 , & V_5 -> V_70 ) ;
error = F_47 ( V_66 ) ;
return error ;
V_104:
F_46 ( V_66 , V_68 , error ) ;
F_48 ( V_66 ) ;
return error ;
}
