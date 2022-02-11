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
F_5 ( V_11 -> V_16 ) == V_7 )
return V_11 -> V_16 ;
}
return NULL ;
}
STATIC void
F_6 (
struct V_2 * V_3 ,
struct V_1 * V_18 ,
int V_19 )
{
struct V_10 * V_20 ;
ASSERT ( V_18 -> V_21 == NULL ) ;
F_7 ( V_18 , V_3 -> V_22 ) ;
V_20 = V_18 -> V_23 ;
ASSERT ( ! ( V_20 -> V_24 & V_25 ) ) ;
ASSERT ( ! ( V_20 -> V_26 . V_27 & V_28 ) ) ;
ASSERT ( ! ( V_20 -> V_24 & V_29 ) ) ;
if ( V_19 )
V_20 -> V_30 = 0 ;
F_8 ( & V_20 -> V_31 ) ;
F_9 ( V_3 , & V_20 -> V_13 ) ;
V_18 -> V_21 = V_3 ;
}
void
F_10 (
struct V_2 * V_3 ,
struct V_1 * V_18 )
{
F_6 ( V_3 , V_18 , 0 ) ;
F_11 ( V_18 -> V_23 ) ;
}
T_2 *
F_12 ( T_3 * V_3 ,
T_4 * V_32 ,
T_1 V_6 ,
int V_7 ,
T_5 V_33 )
{
T_2 * V_18 ;
T_6 * V_20 ;
if ( V_33 == 0 )
V_33 = V_34 | V_35 ;
if ( V_3 == NULL )
return F_13 ( V_32 , V_6 , V_7 ,
V_33 | V_36 ) ;
V_18 = F_1 ( V_3 , V_32 , V_6 , V_7 ) ;
if ( V_18 != NULL ) {
ASSERT ( F_14 ( V_18 ) ) ;
if ( F_15 ( V_3 -> V_22 ) )
F_16 ( V_18 ) ;
else if ( F_17 ( V_18 ) )
ASSERT ( ! F_18 ( V_18 ) ) ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
V_20 = V_18 -> V_23 ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_30 ++ ;
F_20 ( V_20 ) ;
return ( V_18 ) ;
}
V_18 = F_13 ( V_32 , V_6 , V_7 , V_33 | V_36 ) ;
if ( V_18 == NULL ) {
return NULL ;
}
ASSERT ( ! V_18 -> V_37 ) ;
F_6 ( V_3 , V_18 , 1 ) ;
F_21 ( V_18 -> V_23 ) ;
return ( V_18 ) ;
}
T_2 *
F_22 ( T_3 * V_3 ,
struct V_38 * V_39 ,
int V_33 )
{
T_2 * V_18 ;
T_6 * V_20 ;
if ( V_3 == NULL ) {
return ( F_23 ( V_39 , V_33 ) ) ;
}
V_18 = V_39 -> V_40 ;
if ( V_18 -> V_21 == V_3 ) {
V_20 = V_18 -> V_23 ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_30 ++ ;
F_24 ( V_20 ) ;
return ( V_18 ) ;
}
V_18 = F_23 ( V_39 , V_33 ) ;
if ( V_18 == NULL )
return NULL ;
F_6 ( V_3 , V_18 , 1 ) ;
F_25 ( V_18 -> V_23 ) ;
return ( V_18 ) ;
}
int
F_26 (
T_7 * V_39 ,
T_3 * V_3 ,
T_4 * V_5 ,
T_1 V_6 ,
int V_7 ,
T_5 V_33 ,
T_2 * * V_41 )
{
T_2 * V_18 ;
T_6 * V_20 ;
int error ;
if ( V_33 == 0 )
V_33 = V_34 | V_35 ;
if ( V_3 == NULL ) {
V_18 = F_27 ( V_5 , V_6 , V_7 , V_33 | V_36 ) ;
if ( ! V_18 )
return ( V_33 & V_42 ) ?
V_43 : F_28 ( V_44 ) ;
if ( V_18 -> V_37 ) {
error = V_18 -> V_37 ;
F_29 ( L_1 , V_39 ,
V_18 , V_6 ) ;
F_30 ( V_18 ) ;
return error ;
}
#ifdef F_31
if ( V_45 ) {
if ( V_46 == V_5 ) {
if ( ( ( V_47 ++ ) % V_48 ) == 0 ) {
F_30 ( V_18 ) ;
F_32 ( V_39 , L_2 ) ;
return F_28 ( V_49 ) ;
}
}
}
#endif
if ( F_15 ( V_39 ) )
goto V_50;
* V_41 = V_18 ;
return 0 ;
}
V_18 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
if ( V_18 != NULL ) {
ASSERT ( F_14 ( V_18 ) ) ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_18 -> V_23 != NULL ) ;
ASSERT ( ! V_18 -> V_37 ) ;
if ( ! ( F_33 ( V_18 ) ) ) {
F_34 ( V_18 , V_51 ) ;
ASSERT ( ! F_35 ( V_18 ) ) ;
F_36 ( V_18 ) ;
F_37 ( V_3 -> V_22 , V_18 ) ;
error = F_38 ( V_18 ) ;
if ( error ) {
F_29 ( L_1 , V_39 ,
V_18 , V_6 ) ;
F_30 ( V_18 ) ;
if ( V_3 -> V_52 & V_53 )
F_39 ( V_3 -> V_22 ,
V_54 ) ;
return error ;
}
}
if ( F_15 ( V_39 ) ) {
F_40 ( V_18 , V_51 ) ;
* V_41 = NULL ;
return F_28 ( V_49 ) ;
}
V_20 = V_18 -> V_23 ;
V_20 -> V_30 ++ ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
F_41 ( V_20 ) ;
* V_41 = V_18 ;
return 0 ;
}
V_18 = F_27 ( V_5 , V_6 , V_7 , V_33 | V_36 ) ;
if ( V_18 == NULL ) {
* V_41 = NULL ;
return ( V_33 & V_42 ) ?
0 : F_28 ( V_44 ) ;
}
if ( V_18 -> V_37 ) {
error = V_18 -> V_37 ;
F_16 ( V_18 ) ;
F_29 ( L_1 , V_39 ,
V_18 , V_6 ) ;
if ( V_3 -> V_52 & V_53 )
F_39 ( V_3 -> V_22 , V_54 ) ;
F_30 ( V_18 ) ;
return error ;
}
#ifdef F_31
if ( V_45 && ! ( V_3 -> V_52 & V_53 ) ) {
if ( V_46 == V_5 ) {
if ( ( ( V_47 ++ ) % V_48 ) == 0 ) {
F_39 ( V_3 -> V_22 ,
V_54 ) ;
F_30 ( V_18 ) ;
F_32 ( V_39 , L_3 ) ;
return F_28 ( V_49 ) ;
}
}
}
#endif
if ( F_15 ( V_39 ) )
goto V_50;
F_6 ( V_3 , V_18 , 1 ) ;
F_42 ( V_18 -> V_23 ) ;
* V_41 = V_18 ;
return 0 ;
V_50:
#if F_43 ( F_31 )
if ( F_17 ( V_18 ) && F_18 ( V_18 ) )
F_44 ( V_39 , L_4 , V_18 ) ;
#endif
ASSERT ( ( V_18 -> V_55 & ( V_56 | V_57 ) ) !=
( V_56 | V_57 ) ) ;
F_40 ( V_18 , V_51 ) ;
F_30 ( V_18 ) ;
* V_41 = NULL ;
return F_28 ( V_49 ) ;
}
void
F_45 ( T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 ;
if ( V_3 == NULL ) {
struct V_58 * V_59 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == NULL ) ;
if ( V_59 != NULL && V_59 -> V_14 == V_15 ) {
V_20 = V_18 -> V_23 ;
F_46 ( V_20 -> V_13 . V_60 , V_59 ) ;
}
F_30 ( V_18 ) ;
return;
}
ASSERT ( V_18 -> V_21 == V_3 ) ;
V_20 = V_18 -> V_23 ;
ASSERT ( V_20 -> V_13 . V_14 == V_15 ) ;
ASSERT ( ! ( V_20 -> V_24 & V_25 ) ) ;
ASSERT ( ! ( V_20 -> V_26 . V_27 & V_28 ) ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
F_47 ( V_20 ) ;
if ( V_20 -> V_30 > 0 ) {
V_20 -> V_30 -- ;
return;
}
if ( V_20 -> V_13 . V_61 -> V_62 & V_63 )
return;
if ( V_20 -> V_24 & V_25 )
return;
ASSERT ( ! ( V_20 -> V_24 & V_29 ) ) ;
F_48 ( & V_20 -> V_13 ) ;
if ( V_20 -> V_24 & V_64 ) {
V_20 -> V_24 &= ~ V_64 ;
}
F_49 ( & V_20 -> V_31 ) ;
if ( ! F_50 ( V_20 ) ) {
ASSERT ( F_19 ( & V_20 -> V_31 ) == 0 ) ;
ASSERT ( ! ( V_20 -> V_13 . V_65 & V_66 ) ) ;
ASSERT ( ! ( V_20 -> V_24 & V_67 ) ) ;
F_51 ( V_18 ) ;
V_20 = NULL ;
}
V_18 -> V_21 = NULL ;
if ( V_20 != NULL ) {
F_46 ( V_20 -> V_13 . V_60 ,
( V_68 * ) V_20 ) ;
}
F_30 ( V_18 ) ;
return;
}
void
F_52 ( T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( ! ( V_20 -> V_24 & V_25 ) ) ;
ASSERT ( ! ( V_20 -> V_26 . V_27 & V_28 ) ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_24 |= V_64 ;
F_53 ( V_20 ) ;
}
void
F_54 ( T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( ! ( V_20 -> V_24 & V_25 ) ) ;
ASSERT ( ! ( V_20 -> V_26 . V_27 & V_28 ) ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
ASSERT ( V_20 -> V_24 & V_64 ) ;
V_20 -> V_24 &= ~ V_64 ;
F_55 ( V_20 ) ;
}
void
F_56 ( T_3 * V_3 ,
T_2 * V_18 ,
T_5 V_69 ,
T_5 V_70 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( ( V_69 <= V_70 ) && ( V_70 < F_5 ( V_18 ) ) ) ;
ASSERT ( V_18 -> V_71 == NULL ||
V_18 -> V_71 == V_72 ) ;
F_57 ( V_18 ) ;
F_58 ( V_18 ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_18 -> V_71 = V_72 ;
V_20 -> V_13 . V_73 = V_74 ;
F_59 ( V_20 ) ;
if ( V_20 -> V_24 & V_25 ) {
V_20 -> V_24 &= ~ V_25 ;
ASSERT ( F_17 ( V_18 ) ) ;
F_60 ( V_18 ) ;
V_20 -> V_26 . V_27 &= ~ V_28 ;
}
V_3 -> V_52 |= V_53 ;
V_20 -> V_13 . V_61 -> V_62 |= V_63 ;
V_20 -> V_24 |= V_29 ;
F_61 ( V_20 , V_69 , V_70 ) ;
}
void
F_62 (
T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
F_63 ( V_20 ) ;
if ( V_20 -> V_24 & V_25 ) {
ASSERT ( ! ( F_18 ( V_18 ) ) ) ;
ASSERT ( F_17 ( V_18 ) ) ;
ASSERT ( ! ( V_20 -> V_24 & ( V_29 | V_75 ) ) ) ;
ASSERT ( ! ( V_20 -> V_26 . V_27 & V_76 ) ) ;
ASSERT ( V_20 -> V_26 . V_27 & V_28 ) ;
ASSERT ( V_20 -> V_13 . V_61 -> V_62 & V_63 ) ;
ASSERT ( V_3 -> V_52 & V_53 ) ;
return;
}
F_64 ( V_18 ) ;
F_65 ( V_18 ) ;
V_20 -> V_24 |= V_25 ;
V_20 -> V_24 &= ~ ( V_77 | V_29 | V_75 ) ;
V_20 -> V_26 . V_27 &= ~ V_76 ;
V_20 -> V_26 . V_27 |= V_28 ;
memset ( ( char * ) ( V_20 -> V_26 . V_78 ) , 0 ,
( V_20 -> V_26 . V_79 * sizeof( T_5 ) ) ) ;
V_20 -> V_13 . V_61 -> V_62 |= V_63 ;
V_3 -> V_52 |= V_53 ;
}
void
F_66 (
T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_24 |= V_77 ;
}
void
F_67 (
T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_24 |= V_80 ;
V_20 -> V_13 . V_73 = V_74 ;
}
void
F_68 (
T_3 * V_3 ,
T_2 * V_18 )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_24 |= V_67 ;
}
void
F_69 (
T_3 * V_3 ,
T_2 * V_18 ,
T_5 type )
{
T_6 * V_20 = V_18 -> V_23 ;
ASSERT ( V_18 -> V_21 == V_3 ) ;
ASSERT ( V_20 != NULL ) ;
ASSERT ( type == V_81 ||
type == V_82 ||
type == V_83 ) ;
ASSERT ( F_19 ( & V_20 -> V_31 ) > 0 ) ;
V_20 -> V_26 . V_27 |= type ;
}
