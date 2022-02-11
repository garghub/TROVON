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
struct V_1 * * V_44 )
{
T_2 * V_25 ;
T_3 * V_27 ;
int error ;
* V_44 = NULL ;
if ( ! V_3 ) {
V_25 = F_24 ( V_5 , V_7 , V_8 , V_39 ) ;
if ( ! V_25 )
return ( V_39 & V_45 ) ?
V_46 : F_25 ( V_47 ) ;
if ( V_25 -> V_40 ) {
error = V_25 -> V_40 ;
F_26 ( V_25 , V_48 ) ;
F_27 ( V_25 ) ;
F_14 ( V_25 ) ;
F_28 ( V_25 ) ;
return error ;
}
#ifdef F_29
if ( V_49 ) {
if ( V_50 == V_5 ) {
if ( ( ( V_51 ++ ) % V_52 ) == 0 ) {
F_28 ( V_25 ) ;
F_30 ( V_42 , L_1 ) ;
return F_25 ( V_53 ) ;
}
}
}
#endif
if ( F_13 ( V_42 ) )
goto V_54;
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
F_32 ( V_25 , V_55 ) ;
ASSERT ( ! F_33 ( V_25 ) ) ;
F_34 ( V_25 ) ;
F_35 ( V_3 -> V_29 , V_25 ) ;
error = F_36 ( V_25 ) ;
if ( error ) {
F_26 ( V_25 , V_48 ) ;
F_28 ( V_25 ) ;
if ( V_3 -> V_56 & V_57 )
F_37 ( V_3 -> V_29 ,
V_58 ) ;
return error ;
}
}
if ( F_13 ( V_42 ) ) {
F_38 ( V_25 , V_55 ) ;
* V_44 = NULL ;
return F_25 ( V_53 ) ;
}
V_27 = V_25 -> V_30 ;
V_27 -> V_37 ++ ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_39 ( V_27 ) ;
* V_44 = V_25 ;
return 0 ;
}
V_25 = F_24 ( V_5 , V_7 , V_8 , V_39 ) ;
if ( V_25 == NULL ) {
* V_44 = NULL ;
return ( V_39 & V_45 ) ?
0 : F_25 ( V_47 ) ;
}
if ( V_25 -> V_40 ) {
error = V_25 -> V_40 ;
F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
F_26 ( V_25 , V_48 ) ;
if ( V_3 -> V_56 & V_57 )
F_37 ( V_3 -> V_29 , V_58 ) ;
F_28 ( V_25 ) ;
return error ;
}
#ifdef F_29
if ( V_49 && ! ( V_3 -> V_56 & V_57 ) ) {
if ( V_50 == V_5 ) {
if ( ( ( V_51 ++ ) % V_52 ) == 0 ) {
F_37 ( V_3 -> V_29 ,
V_58 ) ;
F_28 ( V_25 ) ;
F_30 ( V_42 , L_2 ) ;
return F_25 ( V_53 ) ;
}
}
}
#endif
if ( F_13 ( V_42 ) )
goto V_54;
F_4 ( V_3 , V_25 , 1 ) ;
F_40 ( V_25 -> V_30 ) ;
* V_44 = V_25 ;
return 0 ;
V_54:
F_38 ( V_25 , V_55 ) ;
F_28 ( V_25 ) ;
* V_44 = NULL ;
return F_25 ( V_53 ) ;
}
void
F_41 ( T_4 * V_3 ,
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
F_42 ( V_27 ) ;
if ( V_27 -> V_37 > 0 ) {
V_27 -> V_37 -- ;
return;
}
if ( V_27 -> V_17 . V_59 -> V_60 & V_61 )
return;
if ( V_27 -> V_31 & V_32 )
return;
ASSERT ( ! ( V_27 -> V_31 & V_36 ) ) ;
F_43 ( & V_27 -> V_17 ) ;
if ( V_27 -> V_31 & V_62 ) {
V_27 -> V_31 &= ~ V_62 ;
}
F_44 ( & V_27 -> V_38 ) ;
if ( ! F_45 ( V_27 ) ) {
ASSERT ( F_16 ( & V_27 -> V_38 ) == 0 ) ;
ASSERT ( ! ( V_27 -> V_17 . V_63 & V_64 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & V_65 ) ) ;
F_46 ( V_25 ) ;
}
V_25 -> V_28 = NULL ;
F_28 ( V_25 ) ;
}
void
F_47 ( T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ! ( V_27 -> V_31 & V_32 ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_35 ) ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_62 ;
F_48 ( V_27 ) ;
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
ASSERT ( V_27 -> V_31 & V_62 ) ;
V_27 -> V_31 &= ~ V_62 ;
F_50 ( V_27 ) ;
}
void
F_51 ( T_4 * V_3 ,
T_2 * V_25 ,
T_5 V_66 ,
T_5 V_67 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( V_66 <= V_67 && V_67 < F_52 ( V_25 -> V_23 ) ) ;
ASSERT ( V_25 -> V_68 == NULL ||
V_25 -> V_68 == V_69 ) ;
F_15 ( V_25 ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_25 -> V_68 = V_69 ;
V_27 -> V_17 . V_70 = V_71 ;
F_53 ( V_27 ) ;
if ( V_27 -> V_31 & V_32 ) {
V_27 -> V_31 &= ~ V_32 ;
ASSERT ( F_54 ( V_25 ) ) ;
F_55 ( V_25 ) ;
V_27 -> V_33 . V_34 &= ~ V_35 ;
}
V_3 -> V_56 |= V_57 ;
V_27 -> V_17 . V_59 -> V_60 |= V_61 ;
V_27 -> V_31 |= V_36 ;
F_56 ( V_27 , V_66 , V_67 ) ;
}
void
F_57 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
F_58 ( V_27 ) ;
if ( V_27 -> V_31 & V_32 ) {
ASSERT ( F_54 ( V_25 ) ) ;
ASSERT ( ! ( V_27 -> V_31 & ( V_36 | V_72 ) ) ) ;
ASSERT ( ! ( V_27 -> V_33 . V_34 & V_73 ) ) ;
ASSERT ( V_27 -> V_33 . V_34 & V_35 ) ;
ASSERT ( V_27 -> V_17 . V_59 -> V_60 & V_61 ) ;
ASSERT ( V_3 -> V_56 & V_57 ) ;
return;
}
F_14 ( V_25 ) ;
V_27 -> V_31 |= V_32 ;
V_27 -> V_31 &= ~ ( V_74 | V_36 | V_72 ) ;
V_27 -> V_33 . V_34 &= ~ V_73 ;
V_27 -> V_33 . V_34 |= V_35 ;
memset ( ( char * ) ( V_27 -> V_33 . V_75 ) , 0 ,
( V_27 -> V_33 . V_76 * sizeof( T_5 ) ) ) ;
V_27 -> V_17 . V_59 -> V_60 |= V_61 ;
V_3 -> V_56 |= V_57 ;
}
void
F_59 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_74 ;
}
void
F_60 (
T_4 * V_3 ,
T_2 * V_25 )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_31 |= V_77 ;
V_27 -> V_17 . V_70 = V_71 ;
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
V_27 -> V_31 |= V_65 ;
}
void
F_62 (
T_4 * V_3 ,
T_2 * V_25 ,
T_5 type )
{
T_3 * V_27 = V_25 -> V_30 ;
ASSERT ( V_25 -> V_28 == V_3 ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( type == V_78 ||
type == V_79 ||
type == V_80 ) ;
ASSERT ( F_16 ( & V_27 -> V_38 ) > 0 ) ;
V_27 -> V_33 . V_34 |= type ;
}
