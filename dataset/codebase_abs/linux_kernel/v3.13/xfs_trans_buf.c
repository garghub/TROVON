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
F_15 ( V_25 ) ;
}
ASSERT ( V_25 -> V_28 == V_3 ) ;
V_27 = V_25 -> V_30 ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_37 ++ ;
F_17 ( V_27 ) ;
return ( V_25 ) ;
}
V_25 = F_11 ( V_5 , V_7 , V_8 , V_39 ) ;
if ( V_25 == NULL ) {
return NULL ;
}
ASSERT ( ! V_25 -> V_40 ) ;
F_4 ( V_3 , V_25 , 1 ) ;
F_18 ( V_25 -> V_30 ) ;
return ( V_25 ) ;
}
T_2 *
F_19 ( T_4 * V_3 ,
struct V_41 * V_42 ,
int V_39 )
{
T_2 * V_25 ;
T_3 * V_27 ;
if ( V_3 == NULL ) {
return ( F_20 ( V_42 , V_39 ) ) ;
}
V_25 = V_42 -> V_43 ;
if ( V_25 -> V_28 == V_3 ) {
V_27 = V_25 -> V_30 ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_37 ++ ;
F_21 ( V_27 ) ;
return ( V_25 ) ;
}
V_25 = F_20 ( V_42 , V_39 ) ;
if ( V_25 == NULL )
return NULL ;
F_4 ( V_3 , V_25 , 1 ) ;
F_22 ( V_25 -> V_30 ) ;
return ( V_25 ) ;
}
int
F_23 (
struct V_41 * V_42 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_8 ,
T_1 V_39 ,
struct V_1 * * V_44 ,
const struct V_45 * V_46 )
{
T_2 * V_25 ;
T_3 * V_27 ;
int error ;
* V_44 = NULL ;
if ( ! V_3 ) {
V_25 = F_24 ( V_5 , V_7 , V_8 , V_39 , V_46 ) ;
if ( ! V_25 )
return ( V_39 & V_47 ) ?
V_48 : F_25 ( V_49 ) ;
if ( V_25 -> V_40 ) {
error = V_25 -> V_40 ;
F_26 ( V_25 , V_50 ) ;
F_27 ( V_25 ) ;
F_14 ( V_25 ) ;
F_28 ( V_25 ) ;
return error ;
}
#ifdef F_29
if ( V_51 ) {
if ( V_52 == V_5 ) {
if ( ( ( V_53 ++ ) % V_54 ) == 0 ) {
F_28 ( V_25 ) ;
F_30 ( V_42 , L_1 ) ;
return F_25 ( V_55 ) ;
}
}
}
#endif
if ( F_13 ( V_42 ) )
goto V_56;
* V_44 = V_25 ;
return 0 ;
}
V_25 = F_1 ( V_3 , V_5 , V_7 , V_8 ) ;
if ( V_25 != NULL ) {
ASSERT ( F_12 ( V_25 ) ) ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_25 -> V_30 != NULL ) ;
ASSERT ( ! V_25 -> V_40 ) ;
if ( ! ( F_31 ( V_25 ) ) ) {
F_32 ( V_25 , V_57 ) ;
ASSERT ( ! F_33 ( V_25 ) ) ;
ASSERT ( V_25 -> V_58 == NULL ) ;
F_34 ( V_25 ) ;
V_25 -> V_59 = V_46 ;
if ( F_13 ( V_42 ) ) {
F_35 ( V_25 , V_57 ) ;
F_36 ( V_25 ) ;
} else {
F_37 ( V_25 ) ;
}
error = F_38 ( V_25 ) ;
if ( error ) {
F_26 ( V_25 , V_50 ) ;
F_28 ( V_25 ) ;
if ( V_3 -> V_60 & V_61 )
F_39 ( V_3 -> V_29 ,
V_62 ) ;
return error ;
}
}
if ( F_13 ( V_42 ) ) {
F_40 ( V_25 , V_57 ) ;
* V_44 = NULL ;
return F_25 ( V_55 ) ;
}
V_27 = V_25 -> V_30 ;
V_27 -> V_37 ++ ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_41 ( V_27 ) ;
* V_44 = V_25 ;
return 0 ;
}
V_25 = F_24 ( V_5 , V_7 , V_8 , V_39 , V_46 ) ;
if ( V_25 == NULL ) {
* V_44 = NULL ;
return ( V_39 & V_47 ) ?
0 : F_25 ( V_49 ) ;
}
if ( V_25 -> V_40 ) {
error = V_25 -> V_40 ;
F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
F_26 ( V_25 , V_50 ) ;
if ( V_3 -> V_60 & V_61 )
F_39 ( V_3 -> V_29 , V_62 ) ;
F_28 ( V_25 ) ;
return error ;
}
#ifdef F_29
if ( V_51 && ! ( V_3 -> V_60 & V_61 ) ) {
if ( V_52 == V_5 ) {
if ( ( ( V_53 ++ ) % V_54 ) == 0 ) {
F_39 ( V_3 -> V_29 ,
V_62 ) ;
F_28 ( V_25 ) ;
F_30 ( V_42 , L_2 ) ;
return F_25 ( V_55 ) ;
}
}
}
#endif
if ( F_13 ( V_42 ) )
goto V_56;
F_4 ( V_3 , V_25 , 1 ) ;
F_42 ( V_25 -> V_30 ) ;
* V_44 = V_25 ;
return 0 ;
V_56:
F_40 ( V_25 , V_57 ) ;
F_28 ( V_25 ) ;
* V_44 = NULL ;
return F_25 ( V_55 ) ;
}
void
F_43 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 ;
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
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_44 ( V_27 ) ;
if ( V_27 -> V_37 > 0 ) {
V_27 -> V_37 -- ;
return;
}
if ( V_27 -> V_17 . V_63 -> V_64 & V_65 )
return;
if ( V_27 -> V_31 & V_32 )
return;
ASSERT ( ! ( V_27 -> V_31 & V_36 ) ) ;
F_45 ( & V_27 -> V_17 ) ;
if ( V_27 -> V_31 & V_66 ) {
V_27 -> V_31 &= ~ V_66 ;
}
F_46 ( & V_27 -> V_38 ) ;
if ( ! F_47 ( V_27 ) ) {
ASSERT ( F_16 ( & V_27 -> V_38 ) == 0 ) ;
ASSERT ( ! ( V_27 -> V_17 . V_67 & V_68 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & V_69 ) ) ;
F_48 ( V_25 ) ;
}
V_25 -> V_28 = NULL ;
F_28 ( V_25 ) ;
}
void
F_49 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_66 ;
F_50 ( V_27 ) ;
}
void
F_51 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
ASSERT ( V_27 -> V_31 & V_66 ) ;
V_27 -> V_31 &= ~ V_66 ;
F_52 ( V_27 ) ;
}
void
F_53 ( T_4 * V_3 ,
T_2 * V_25 ,
T_5 V_70 ,
T_5 V_71 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( V_70 <= V_71 && V_71 < F_54 ( V_25 -> V_23 ) ) ;
ASSERT ( V_25 -> V_58 == NULL ||
V_25 -> V_58 == V_72 ) ;
F_15 ( V_25 ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_25 -> V_58 = V_72 ;
V_27 -> V_17 . V_73 = V_74 ;
F_55 ( V_27 ) ;
if ( V_27 -> V_31 & V_32 ) {
V_27 -> V_31 &= ~ V_32 ;
ASSERT ( F_56 ( V_25 ) ) ;
F_57 ( V_25 ) ;
V_27 -> V_33 . V_34 &= ~ V_35 ;
}
V_3 -> V_60 |= V_61 ;
V_27 -> V_17 . V_63 -> V_64 |= V_65 ;
V_27 -> V_31 |= V_75 | V_36 ;
if ( ! ( V_27 -> V_31 & V_76 ) )
F_58 ( V_27 , V_70 , V_71 ) ;
}
void
F_59 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
int V_14 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_60 ( V_27 ) ;
if ( V_27 -> V_31 & V_32 ) {
ASSERT ( F_56 ( V_25 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & ( V_36 | V_75 ) ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_77 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_78 ) ) ;
ASSERT ( V_27 -> V_33 . V_34 & V_35 ) ;
ASSERT ( V_27 -> V_17 . V_63 -> V_64 & V_65 ) ;
ASSERT ( V_3 -> V_60 & V_61 ) ;
return;
}
F_14 ( V_25 ) ;
V_27 -> V_31 |= V_32 ;
V_27 -> V_31 &= ~ ( V_79 | V_36 | V_75 ) ;
V_27 -> V_33 . V_34 &= ~ V_77 ;
V_27 -> V_33 . V_34 |= V_35 ;
V_27 -> V_33 . V_34 &= ~ V_78 ;
for ( V_14 = 0 ; V_14 < V_27 -> V_80 ; V_14 ++ ) {
memset ( V_27 -> V_81 [ V_14 ] . V_82 , 0 ,
( V_27 -> V_81 [ V_14 ] . V_83 * sizeof( T_5 ) ) ) ;
}
V_27 -> V_17 . V_63 -> V_64 |= V_65 ;
V_3 -> V_60 |= V_61 ;
}
void
F_61 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_79 ;
F_62 ( V_3 , V_25 , V_84 ) ;
}
void
F_63 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_85 ;
V_27 -> V_17 . V_73 = V_74 ;
F_62 ( V_3 , V_25 , V_84 ) ;
}
void
F_64 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_69 ;
F_62 ( V_3 , V_25 , V_84 ) ;
}
void
F_65 (
struct V_2 * V_3 ,
struct V_1 * V_25 )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_76 ;
F_66 ( V_27 ) ;
}
void
F_62 (
struct V_2 * V_3 ,
struct V_1 * V_25 ,
enum V_86 type )
{
struct V_11 * V_27 = V_25 -> V_30 ;
if ( ! V_3 )
return;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_67 ( & V_27 -> V_33 , type ) ;
}
void
F_68 (
struct V_1 * V_87 ,
struct V_1 * V_88 )
{
struct V_11 * V_89 = V_88 -> V_30 ;
struct V_11 * V_90 = V_87 -> V_30 ;
enum V_86 type ;
type = F_69 ( & V_89 -> V_33 ) ;
F_67 ( & V_90 -> V_33 , type ) ;
}
void
F_70 (
T_4 * V_3 ,
T_2 * V_25 ,
T_5 type )
{
struct V_11 * V_27 = V_25 -> V_30 ;
ASSERT ( type == V_91 ||
type == V_92 ||
type == V_93 ) ;
V_27 -> V_33 . V_34 |= type ;
switch ( type ) {
case V_91 :
type = V_94 ;
break;
case V_92 :
type = V_95 ;
break;
case V_93 :
type = V_96 ;
break;
default:
type = V_97 ;
break;
}
F_62 ( V_3 , V_25 , type ) ;
}
