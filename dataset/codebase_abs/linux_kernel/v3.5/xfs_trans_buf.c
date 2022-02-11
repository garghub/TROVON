STATIC struct V_1 *
F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 ,
int V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_7 = F_2 ( V_7 ) ;
F_3 (lidp, &tp->t_items, lid_trans) {
V_11 = (struct V_10 * ) V_9 -> V_12 ;
if ( V_11 -> V_13 . V_14 == V_15 &&
V_11 -> V_16 -> V_17 == V_5 &&
F_4 ( V_11 -> V_16 ) == V_6 &&
F_2 ( V_11 -> V_16 -> V_18 ) == V_7 )
return V_11 -> V_16 ;
}
return NULL ;
}
STATIC void
F_5 (
struct V_2 * V_3 ,
struct V_1 * V_19 ,
int V_20 )
{
struct V_10 * V_21 ;
ASSERT ( V_19 -> V_22 == NULL ) ;
F_6 ( V_19 , V_3 -> V_23 ) ;
V_21 = V_19 -> V_24 ;
ASSERT ( ! ( V_21 -> V_25 & V_26 ) ) ;
ASSERT ( ! ( V_21 -> V_27 . V_28 & V_29 ) ) ;
ASSERT ( ! ( V_21 -> V_25 & V_30 ) ) ;
if ( V_20 )
V_21 -> V_31 = 0 ;
F_7 ( & V_21 -> V_32 ) ;
F_8 ( V_3 , & V_21 -> V_13 ) ;
V_19 -> V_22 = V_3 ;
}
void
F_9 (
struct V_2 * V_3 ,
struct V_1 * V_19 )
{
F_5 ( V_3 , V_19 , 0 ) ;
F_10 ( V_19 -> V_24 ) ;
}
T_2 *
F_11 ( T_3 * V_3 ,
T_4 * V_33 ,
T_1 V_6 ,
int V_7 ,
T_5 V_34 )
{
T_2 * V_19 ;
T_6 * V_21 ;
if ( V_3 == NULL )
return F_12 ( V_33 , V_6 , V_7 , V_34 ) ;
V_19 = F_1 ( V_3 , V_33 , V_6 , V_7 ) ;
if ( V_19 != NULL ) {
ASSERT ( F_13 ( V_19 ) ) ;
if ( F_14 ( V_3 -> V_23 ) ) {
F_15 ( V_19 ) ;
F_16 ( V_19 ) ;
}
ASSERT ( V_19 -> V_22 == V_3 ) ;
V_21 = V_19 -> V_24 ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_31 ++ ;
F_18 ( V_21 ) ;
return ( V_19 ) ;
}
V_19 = F_12 ( V_33 , V_6 , V_7 , V_34 ) ;
if ( V_19 == NULL ) {
return NULL ;
}
ASSERT ( ! V_19 -> V_35 ) ;
F_5 ( V_3 , V_19 , 1 ) ;
F_19 ( V_19 -> V_24 ) ;
return ( V_19 ) ;
}
T_2 *
F_20 ( T_3 * V_3 ,
struct V_36 * V_37 ,
int V_34 )
{
T_2 * V_19 ;
T_6 * V_21 ;
if ( V_3 == NULL ) {
return ( F_21 ( V_37 , V_34 ) ) ;
}
V_19 = V_37 -> V_38 ;
if ( V_19 -> V_22 == V_3 ) {
V_21 = V_19 -> V_24 ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_31 ++ ;
F_22 ( V_21 ) ;
return ( V_19 ) ;
}
V_19 = F_21 ( V_37 , V_34 ) ;
if ( V_19 == NULL )
return NULL ;
F_5 ( V_3 , V_19 , 1 ) ;
F_23 ( V_19 -> V_24 ) ;
return ( V_19 ) ;
}
int
F_24 (
T_7 * V_37 ,
T_3 * V_3 ,
T_4 * V_5 ,
T_1 V_6 ,
int V_7 ,
T_5 V_34 ,
T_2 * * V_39 )
{
T_2 * V_19 ;
T_6 * V_21 ;
int error ;
* V_39 = NULL ;
if ( V_3 == NULL ) {
V_19 = F_25 ( V_5 , V_6 , V_7 , V_34 ) ;
if ( ! V_19 )
return ( V_34 & V_40 ) ?
V_41 : F_26 ( V_42 ) ;
if ( V_19 -> V_35 ) {
error = V_19 -> V_35 ;
F_27 ( V_19 , V_43 ) ;
F_28 ( V_19 ) ;
F_15 ( V_19 ) ;
F_29 ( V_19 ) ;
return error ;
}
#ifdef F_30
if ( V_44 ) {
if ( V_45 == V_5 ) {
if ( ( ( V_46 ++ ) % V_47 ) == 0 ) {
F_29 ( V_19 ) ;
F_31 ( V_37 , L_1 ) ;
return F_26 ( V_48 ) ;
}
}
}
#endif
if ( F_14 ( V_37 ) )
goto V_49;
* V_39 = V_19 ;
return 0 ;
}
V_19 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
if ( V_19 != NULL ) {
ASSERT ( F_13 ( V_19 ) ) ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_19 -> V_24 != NULL ) ;
ASSERT ( ! V_19 -> V_35 ) ;
if ( ! ( F_32 ( V_19 ) ) ) {
F_33 ( V_19 , V_50 ) ;
ASSERT ( ! F_34 ( V_19 ) ) ;
F_35 ( V_19 ) ;
F_36 ( V_3 -> V_23 , V_19 ) ;
error = F_37 ( V_19 ) ;
if ( error ) {
F_27 ( V_19 , V_43 ) ;
F_29 ( V_19 ) ;
if ( V_3 -> V_51 & V_52 )
F_38 ( V_3 -> V_23 ,
V_53 ) ;
return error ;
}
}
if ( F_14 ( V_37 ) ) {
F_39 ( V_19 , V_50 ) ;
* V_39 = NULL ;
return F_26 ( V_48 ) ;
}
V_21 = V_19 -> V_24 ;
V_21 -> V_31 ++ ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
F_40 ( V_21 ) ;
* V_39 = V_19 ;
return 0 ;
}
V_19 = F_25 ( V_5 , V_6 , V_7 , V_34 ) ;
if ( V_19 == NULL ) {
* V_39 = NULL ;
return ( V_34 & V_40 ) ?
0 : F_26 ( V_42 ) ;
}
if ( V_19 -> V_35 ) {
error = V_19 -> V_35 ;
F_15 ( V_19 ) ;
F_16 ( V_19 ) ;
F_27 ( V_19 , V_43 ) ;
if ( V_3 -> V_51 & V_52 )
F_38 ( V_3 -> V_23 , V_53 ) ;
F_29 ( V_19 ) ;
return error ;
}
#ifdef F_30
if ( V_44 && ! ( V_3 -> V_51 & V_52 ) ) {
if ( V_45 == V_5 ) {
if ( ( ( V_46 ++ ) % V_47 ) == 0 ) {
F_38 ( V_3 -> V_23 ,
V_53 ) ;
F_29 ( V_19 ) ;
F_31 ( V_37 , L_2 ) ;
return F_26 ( V_48 ) ;
}
}
}
#endif
if ( F_14 ( V_37 ) )
goto V_49;
F_5 ( V_3 , V_19 , 1 ) ;
F_41 ( V_19 -> V_24 ) ;
* V_39 = V_19 ;
return 0 ;
V_49:
F_39 ( V_19 , V_50 ) ;
F_29 ( V_19 ) ;
* V_39 = NULL ;
return F_26 ( V_48 ) ;
}
void
F_42 ( T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 ;
if ( V_3 == NULL ) {
ASSERT ( V_19 -> V_22 == NULL ) ;
F_29 ( V_19 ) ;
return;
}
ASSERT ( V_19 -> V_22 == V_3 ) ;
V_21 = V_19 -> V_24 ;
ASSERT ( V_21 -> V_13 . V_14 == V_15 ) ;
ASSERT ( ! ( V_21 -> V_25 & V_26 ) ) ;
ASSERT ( ! ( V_21 -> V_27 . V_28 & V_29 ) ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
F_43 ( V_21 ) ;
if ( V_21 -> V_31 > 0 ) {
V_21 -> V_31 -- ;
return;
}
if ( V_21 -> V_13 . V_54 -> V_55 & V_56 )
return;
if ( V_21 -> V_25 & V_26 )
return;
ASSERT ( ! ( V_21 -> V_25 & V_30 ) ) ;
F_44 ( & V_21 -> V_13 ) ;
if ( V_21 -> V_25 & V_57 ) {
V_21 -> V_25 &= ~ V_57 ;
}
F_45 ( & V_21 -> V_32 ) ;
if ( ! F_46 ( V_21 ) ) {
ASSERT ( F_17 ( & V_21 -> V_32 ) == 0 ) ;
ASSERT ( ! ( V_21 -> V_13 . V_58 & V_59 ) ) ;
ASSERT ( ! ( V_21 -> V_25 & V_60 ) ) ;
F_47 ( V_19 ) ;
}
V_19 -> V_22 = NULL ;
F_29 ( V_19 ) ;
}
void
F_48 ( T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( ! ( V_21 -> V_25 & V_26 ) ) ;
ASSERT ( ! ( V_21 -> V_27 . V_28 & V_29 ) ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_25 |= V_57 ;
F_49 ( V_21 ) ;
}
void
F_50 ( T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( ! ( V_21 -> V_25 & V_26 ) ) ;
ASSERT ( ! ( V_21 -> V_27 . V_28 & V_29 ) ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
ASSERT ( V_21 -> V_25 & V_57 ) ;
V_21 -> V_25 &= ~ V_57 ;
F_51 ( V_21 ) ;
}
void
F_52 ( T_3 * V_3 ,
T_2 * V_19 ,
T_5 V_61 ,
T_5 V_62 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( V_61 <= V_62 && V_62 < F_2 ( V_19 -> V_18 ) ) ;
ASSERT ( V_19 -> V_63 == NULL ||
V_19 -> V_63 == V_64 ) ;
F_16 ( V_19 ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_19 -> V_63 = V_64 ;
V_21 -> V_13 . V_65 = V_66 ;
F_53 ( V_21 ) ;
if ( V_21 -> V_25 & V_26 ) {
V_21 -> V_25 &= ~ V_26 ;
ASSERT ( F_54 ( V_19 ) ) ;
F_55 ( V_19 ) ;
V_21 -> V_27 . V_28 &= ~ V_29 ;
}
V_3 -> V_51 |= V_52 ;
V_21 -> V_13 . V_54 -> V_55 |= V_56 ;
V_21 -> V_25 |= V_30 ;
F_56 ( V_21 , V_61 , V_62 ) ;
}
void
F_57 (
T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
F_58 ( V_21 ) ;
if ( V_21 -> V_25 & V_26 ) {
ASSERT ( F_54 ( V_19 ) ) ;
ASSERT ( ! ( V_21 -> V_25 & ( V_30 | V_67 ) ) ) ;
ASSERT ( ! ( V_21 -> V_27 . V_28 & V_68 ) ) ;
ASSERT ( V_21 -> V_27 . V_28 & V_29 ) ;
ASSERT ( V_21 -> V_13 . V_54 -> V_55 & V_56 ) ;
ASSERT ( V_3 -> V_51 & V_52 ) ;
return;
}
F_15 ( V_19 ) ;
V_21 -> V_25 |= V_26 ;
V_21 -> V_25 &= ~ ( V_69 | V_30 | V_67 ) ;
V_21 -> V_27 . V_28 &= ~ V_68 ;
V_21 -> V_27 . V_28 |= V_29 ;
memset ( ( char * ) ( V_21 -> V_27 . V_70 ) , 0 ,
( V_21 -> V_27 . V_71 * sizeof( T_5 ) ) ) ;
V_21 -> V_13 . V_54 -> V_55 |= V_56 ;
V_3 -> V_51 |= V_52 ;
}
void
F_59 (
T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_25 |= V_69 ;
}
void
F_60 (
T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_25 |= V_72 ;
V_21 -> V_13 . V_65 = V_66 ;
}
void
F_61 (
T_3 * V_3 ,
T_2 * V_19 )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_25 |= V_60 ;
}
void
F_62 (
T_3 * V_3 ,
T_2 * V_19 ,
T_5 type )
{
T_6 * V_21 = V_19 -> V_24 ;
ASSERT ( V_19 -> V_22 == V_3 ) ;
ASSERT ( V_21 != NULL ) ;
ASSERT ( type == V_73 ||
type == V_74 ||
type == V_75 ) ;
ASSERT ( F_17 ( & V_21 -> V_32 ) > 0 ) ;
V_21 -> V_27 . V_28 |= type ;
}
