STATIC struct V_1 *
F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_8 ; V_14 ++ )
V_13 += V_7 [ V_14 ] . V_15 ;
F_2 (lidp, &tp->t_items, lid_trans) {
V_12 = (struct V_11 * ) V_10 -> V_16 ;
if ( V_12 -> V_17 . V_18 == V_19 &&
V_12 -> V_20 -> V_21 == V_5 &&
F_3 ( V_12 -> V_20 ) == V_7 [ 0 ] . V_22 &&
V_12 -> V_20 -> V_23 == V_13 ) {
ASSERT ( V_12 -> V_20 -> V_24 == V_8 ) ;
return V_12 -> V_20 ;
}
}
return NULL ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_1 * V_25 ,
int V_26 )
{
struct V_11 * V_27 ;
ASSERT ( V_25 -> V_28 == NULL ) ;
F_5 ( V_25 , V_3 -> V_29 ) ;
V_27 = V_25 -> V_30 ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & V_36 ) ) ;
if ( V_26 )
V_27 -> V_37 = 0 ;
F_6 ( & V_27 -> V_38 ) ;
F_7 ( V_3 , & V_27 -> V_17 ) ;
V_25 -> V_28 = V_3 ;
}
void
F_8 (
struct V_2 * V_3 ,
struct V_1 * V_25 )
{
F_4 ( V_3 , V_25 , 0 ) ;
F_9 ( V_25 -> V_30 ) ;
}
struct V_1 *
F_10 (
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_8 ,
T_1 V_39 )
{
T_2 * V_25 ;
T_3 * V_27 ;
if ( ! V_3 )
return F_11 ( V_5 , V_7 , V_8 , V_39 ) ;
V_25 = F_1 ( V_3 , V_5 , V_7 , V_8 ) ;
if ( V_25 != NULL ) {
ASSERT ( F_12 ( V_25 ) ) ;
if ( F_13 ( V_3 -> V_29 ) ) {
F_14 ( V_25 ) ;
V_25 -> V_40 |= V_41 ;
}
ASSERT ( V_25 -> V_28 == V_3 ) ;
V_27 = V_25 -> V_30 ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_37 ++ ;
F_16 ( V_27 ) ;
return V_25 ;
}
V_25 = F_11 ( V_5 , V_7 , V_8 , V_39 ) ;
if ( V_25 == NULL ) {
return NULL ;
}
ASSERT ( ! V_25 -> V_42 ) ;
F_4 ( V_3 , V_25 , 1 ) ;
F_17 ( V_25 -> V_30 ) ;
return V_25 ;
}
T_2 *
F_18 ( T_4 * V_3 ,
struct V_43 * V_44 ,
int V_39 )
{
T_2 * V_25 ;
T_3 * V_27 ;
if ( V_3 == NULL )
return F_19 ( V_44 , V_39 ) ;
V_25 = V_44 -> V_45 ;
if ( V_25 -> V_28 == V_3 ) {
V_27 = V_25 -> V_30 ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_37 ++ ;
F_20 ( V_27 ) ;
return V_25 ;
}
V_25 = F_19 ( V_44 , V_39 ) ;
if ( V_25 == NULL )
return NULL ;
F_4 ( V_3 , V_25 , 1 ) ;
F_21 ( V_25 -> V_30 ) ;
return V_25 ;
}
int
F_22 (
struct V_43 * V_44 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_8 ,
T_1 V_39 ,
struct V_1 * * V_46 ,
const struct V_47 * V_48 )
{
struct V_1 * V_25 = NULL ;
struct V_11 * V_27 ;
int error ;
* V_46 = NULL ;
if ( V_3 )
V_25 = F_1 ( V_3 , V_5 , V_7 , V_8 ) ;
if ( V_25 ) {
ASSERT ( F_12 ( V_25 ) ) ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_25 -> V_30 != NULL ) ;
ASSERT ( ! V_25 -> V_42 ) ;
ASSERT ( V_25 -> V_40 & V_41 ) ;
if ( F_13 ( V_44 ) ) {
F_23 ( V_25 , V_49 ) ;
return - V_50 ;
}
V_27 = V_25 -> V_30 ;
V_27 -> V_37 ++ ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
F_24 ( V_27 ) ;
* V_46 = V_25 ;
return 0 ;
}
V_25 = F_25 ( V_5 , V_7 , V_8 , V_39 , V_48 ) ;
if ( ! V_25 ) {
if ( ! ( V_39 & V_51 ) )
return - V_52 ;
return V_3 ? 0 : - V_53 ;
}
if ( V_25 -> V_42 ) {
error = V_25 -> V_42 ;
if ( ! F_13 ( V_44 ) )
F_26 ( V_25 , V_54 ) ;
V_25 -> V_40 &= ~ V_41 ;
F_14 ( V_25 ) ;
if ( V_3 && ( V_3 -> V_55 & V_56 ) )
F_27 ( V_3 -> V_29 , V_57 ) ;
F_28 ( V_25 ) ;
if ( error == - V_58 )
error = - V_59 ;
return error ;
}
if ( F_13 ( V_44 ) ) {
F_28 ( V_25 ) ;
F_23 ( V_25 , V_49 ) ;
return - V_50 ;
}
if ( V_3 ) {
F_4 ( V_3 , V_25 , 1 ) ;
F_29 ( V_25 -> V_30 ) ;
}
* V_46 = V_25 ;
return 0 ;
}
void
F_30 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 ;
int V_60 ;
if ( V_3 == NULL ) {
ASSERT ( V_25 -> V_28 == NULL ) ;
F_28 ( V_25 ) ;
return;
}
ASSERT ( V_25 -> V_28 == V_3 ) ;
V_27 = V_25 -> V_30 ;
ASSERT ( V_27 -> V_17 . V_18 == V_19 ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
F_31 ( V_27 ) ;
if ( V_27 -> V_37 > 0 ) {
V_27 -> V_37 -- ;
return;
}
if ( V_27 -> V_17 . V_61 -> V_62 & V_63 )
return;
if ( V_27 -> V_31 & V_32 )
return;
ASSERT ( ! ( V_27 -> V_31 & V_36 ) ) ;
F_32 ( & V_27 -> V_17 ) ;
if ( V_27 -> V_31 & V_64 ) {
V_27 -> V_31 &= ~ V_64 ;
}
V_60 = F_33 ( & V_27 -> V_38 ) ;
if ( F_13 ( V_3 -> V_29 ) && V_60 ) {
F_34 ( & V_27 -> V_17 , V_65 ) ;
F_35 ( V_25 ) ;
} else if ( ! ( V_27 -> V_31 & V_66 ) ) {
ASSERT ( F_15 ( & V_27 -> V_38 ) == 0 ) ;
ASSERT ( ! ( V_27 -> V_17 . V_67 & V_68 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & V_69 ) ) ;
F_35 ( V_25 ) ;
}
V_25 -> V_28 = NULL ;
F_28 ( V_25 ) ;
}
void
F_36 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_64 ;
F_37 ( V_27 ) ;
}
void
F_38 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
ASSERT ( V_27 -> V_31 & V_64 ) ;
V_27 -> V_31 &= ~ V_64 ;
F_39 ( V_27 ) ;
}
void
F_40 (
struct V_2 * V_3 ,
struct V_1 * V_25 )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( V_25 -> V_70 == NULL ||
V_25 -> V_70 == V_71 ) ;
V_25 -> V_40 |= V_41 ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_25 -> V_70 = V_71 ;
V_27 -> V_17 . V_72 = V_73 ;
if ( V_27 -> V_31 & V_32 ) {
V_27 -> V_31 &= ~ V_32 ;
ASSERT ( V_25 -> V_40 & V_74 ) ;
V_25 -> V_40 &= ~ V_74 ;
V_27 -> V_33 . V_34 &= ~ V_35 ;
}
V_27 -> V_31 |= V_66 | V_36 ;
V_3 -> V_55 |= V_56 ;
V_27 -> V_17 . V_61 -> V_62 |= V_63 ;
}
void
F_41 (
struct V_2 * V_3 ,
struct V_1 * V_25 ,
T_5 V_75 ,
T_5 V_76 )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( V_75 <= V_76 && V_76 < F_42 ( V_25 -> V_23 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & V_77 ) ) ;
F_40 ( V_3 , V_25 ) ;
F_43 ( V_27 ) ;
F_44 ( V_27 , V_75 , V_76 ) ;
}
void
F_45 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
int V_14 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
F_46 ( V_27 ) ;
if ( V_27 -> V_31 & V_32 ) {
ASSERT ( V_25 -> V_40 & V_74 ) ;
ASSERT ( ! ( V_27 -> V_31 & ( V_36 | V_66 ) ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_78 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_79 ) ) ;
ASSERT ( V_27 -> V_33 . V_34 & V_35 ) ;
ASSERT ( V_27 -> V_17 . V_61 -> V_62 & V_63 ) ;
ASSERT ( V_3 -> V_55 & V_56 ) ;
return;
}
F_14 ( V_25 ) ;
V_27 -> V_31 |= V_32 ;
V_27 -> V_31 &= ~ ( V_80 | V_36 | V_66 ) ;
V_27 -> V_33 . V_34 &= ~ V_78 ;
V_27 -> V_33 . V_34 |= V_35 ;
V_27 -> V_33 . V_34 &= ~ V_79 ;
for ( V_14 = 0 ; V_14 < V_27 -> V_81 ; V_14 ++ ) {
memset ( V_27 -> V_82 [ V_14 ] . V_83 , 0 ,
( V_27 -> V_82 [ V_14 ] . V_84 * sizeof( T_5 ) ) ) ;
}
V_27 -> V_17 . V_61 -> V_62 |= V_63 ;
V_3 -> V_55 |= V_56 ;
}
void
F_47 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_80 ;
F_48 ( V_3 , V_25 , V_85 ) ;
}
void
F_49 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_86 ;
V_27 -> V_17 . V_72 = V_73 ;
F_48 ( V_3 , V_25 , V_85 ) ;
}
void
F_50 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_69 ;
F_48 ( V_3 , V_25 , V_85 ) ;
}
bool
F_51 (
struct V_2 * V_3 ,
struct V_1 * V_25 )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
if ( F_52 ( V_27 ) )
return false ;
V_27 -> V_31 |= V_77 ;
F_53 ( V_27 ) ;
F_40 ( V_3 , V_25 ) ;
return true ;
}
void
F_48 (
struct V_2 * V_3 ,
struct V_1 * V_25 ,
enum V_87 type )
{
struct V_11 * V_27 = V_25 -> V_30 ;
if ( ! V_3 )
return;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_15 ( & V_27 -> V_38 ) > 0 ) ;
F_54 ( & V_27 -> V_33 , type ) ;
}
void
F_55 (
struct V_1 * V_88 ,
struct V_1 * V_89 )
{
struct V_11 * V_90 = V_89 -> V_30 ;
struct V_11 * V_91 = V_88 -> V_30 ;
enum V_87 type ;
type = F_56 ( & V_90 -> V_33 ) ;
F_54 ( & V_91 -> V_33 , type ) ;
}
void
F_57 (
T_4 * V_3 ,
T_2 * V_25 ,
T_5 type )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( type == V_92 ||
type == V_93 ||
type == V_94 ) ;
V_27 -> V_33 . V_34 |= type ;
switch ( type ) {
case V_92 :
type = V_95 ;
break;
case V_93 :
type = V_96 ;
break;
case V_94 :
type = V_97 ;
break;
default:
type = V_98 ;
break;
}
F_48 ( V_3 , V_25 , type ) ;
}
