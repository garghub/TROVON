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
F_4 ( V_11 -> V_16 ) == V_5 &&
F_5 ( V_11 -> V_16 ) == V_6 &&
F_6 ( V_11 -> V_16 ) == V_7 )
return V_11 -> V_16 ;
}
return NULL ;
}
STATIC void
F_7 (
struct V_2 * V_3 ,
struct V_1 * V_17 ,
int V_18 )
{
struct V_10 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , void * ) == NULL ) ;
F_10 ( V_17 , V_3 -> V_20 ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( ! ( V_19 -> V_22 & V_23 ) ) ;
ASSERT ( ! ( V_19 -> V_24 . V_25 & V_26 ) ) ;
ASSERT ( ! ( V_19 -> V_22 & V_27 ) ) ;
if ( V_18 )
V_19 -> V_28 = 0 ;
F_12 ( & V_19 -> V_29 ) ;
F_13 ( V_3 , & V_19 -> V_13 ) ;
F_14 ( V_17 , V_3 ) ;
}
void
F_15 (
struct V_2 * V_3 ,
struct V_1 * V_17 )
{
F_7 ( V_3 , V_17 , 0 ) ;
F_16 ( V_17 -> V_30 ) ;
}
T_2 *
F_17 ( T_3 * V_3 ,
T_4 * V_31 ,
T_1 V_6 ,
int V_7 ,
T_5 V_32 )
{
T_2 * V_17 ;
V_21 * V_19 ;
if ( V_32 == 0 )
V_32 = V_33 | V_34 ;
if ( V_3 == NULL )
return F_18 ( V_31 , V_6 , V_7 ,
V_32 | V_35 ) ;
V_17 = F_1 ( V_3 , V_31 , V_6 , V_7 ) ;
if ( V_17 != NULL ) {
ASSERT ( F_19 ( V_17 ) <= 0 ) ;
if ( F_20 ( V_3 -> V_20 ) )
F_21 ( V_17 ) ;
else if ( F_22 ( V_17 ) )
ASSERT ( ! F_23 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( V_19 != NULL ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_28 ++ ;
F_25 ( V_19 ) ;
return ( V_17 ) ;
}
V_17 = F_18 ( V_31 , V_6 , V_7 , V_32 | V_35 ) ;
if ( V_17 == NULL ) {
return NULL ;
}
ASSERT ( ! F_26 ( V_17 ) ) ;
F_7 ( V_3 , V_17 , 1 ) ;
F_27 ( V_17 -> V_30 ) ;
return ( V_17 ) ;
}
T_2 *
F_28 ( T_3 * V_3 ,
struct V_36 * V_37 ,
int V_32 )
{
T_2 * V_17 ;
V_21 * V_19 ;
if ( V_3 == NULL ) {
return ( F_29 ( V_37 , V_32 ) ) ;
}
V_17 = V_37 -> V_38 ;
if ( F_9 ( V_17 , T_3 * ) == V_3 ) {
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( V_19 != NULL ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_28 ++ ;
F_30 ( V_19 ) ;
return ( V_17 ) ;
}
V_17 = F_29 ( V_37 , V_32 ) ;
if ( V_17 == NULL )
return NULL ;
F_7 ( V_3 , V_17 , 1 ) ;
F_31 ( V_17 -> V_30 ) ;
return ( V_17 ) ;
}
int
F_32 (
T_6 * V_37 ,
T_3 * V_3 ,
T_4 * V_5 ,
T_1 V_6 ,
int V_7 ,
T_5 V_32 ,
T_2 * * V_39 )
{
T_2 * V_17 ;
V_21 * V_19 ;
int error ;
if ( V_32 == 0 )
V_32 = V_33 | V_34 ;
if ( V_3 == NULL ) {
V_17 = F_33 ( V_5 , V_6 , V_7 , V_32 | V_35 ) ;
if ( ! V_17 )
return ( V_32 & V_40 ) ?
V_41 : F_34 ( V_42 ) ;
if ( F_26 ( V_17 ) != 0 ) {
F_35 ( L_1 , V_37 ,
V_17 , V_6 ) ;
error = F_26 ( V_17 ) ;
F_36 ( V_17 ) ;
return error ;
}
#ifdef F_37
if ( V_43 ) {
if ( V_44 == V_5 ) {
if ( ( ( V_45 ++ ) % V_46 ) == 0 ) {
F_36 ( V_17 ) ;
F_38 ( V_37 , L_2 ) ;
return F_34 ( V_47 ) ;
}
}
}
#endif
if ( F_20 ( V_37 ) )
goto V_48;
* V_39 = V_17 ;
return 0 ;
}
V_17 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
if ( V_17 != NULL ) {
ASSERT ( F_19 ( V_17 ) <= 0 ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
ASSERT ( ( F_39 ( V_17 ) ) == 0 ) ;
if ( ! ( F_40 ( V_17 ) ) ) {
F_41 ( V_17 , V_49 ) ;
ASSERT ( ! F_42 ( V_17 ) ) ;
F_43 ( V_17 ) ;
F_44 ( V_3 -> V_20 , V_17 ) ;
error = F_45 ( V_17 ) ;
if ( error ) {
F_35 ( L_1 , V_37 ,
V_17 , V_6 ) ;
F_36 ( V_17 ) ;
if ( V_3 -> V_50 & V_51 )
F_46 ( V_3 -> V_20 ,
V_52 ) ;
return error ;
}
}
if ( F_20 ( V_37 ) ) {
F_47 ( V_17 , V_49 ) ;
* V_39 = NULL ;
return F_34 ( V_47 ) ;
}
V_19 = F_11 ( V_17 , V_21 * ) ;
V_19 -> V_28 ++ ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
F_48 ( V_19 ) ;
* V_39 = V_17 ;
return 0 ;
}
V_17 = F_33 ( V_5 , V_6 , V_7 , V_32 | V_35 ) ;
if ( V_17 == NULL ) {
* V_39 = NULL ;
return ( V_32 & V_40 ) ?
0 : F_34 ( V_42 ) ;
}
if ( F_26 ( V_17 ) != 0 ) {
F_21 ( V_17 ) ;
error = F_26 ( V_17 ) ;
F_35 ( L_1 , V_37 ,
V_17 , V_6 ) ;
if ( V_3 -> V_50 & V_51 )
F_46 ( V_3 -> V_20 , V_52 ) ;
F_36 ( V_17 ) ;
return error ;
}
#ifdef F_37
if ( V_43 && ! ( V_3 -> V_50 & V_51 ) ) {
if ( V_44 == V_5 ) {
if ( ( ( V_45 ++ ) % V_46 ) == 0 ) {
F_46 ( V_3 -> V_20 ,
V_52 ) ;
F_36 ( V_17 ) ;
F_38 ( V_37 , L_3 ) ;
return F_34 ( V_47 ) ;
}
}
}
#endif
if ( F_20 ( V_37 ) )
goto V_48;
F_7 ( V_3 , V_17 , 1 ) ;
F_49 ( V_17 -> V_30 ) ;
* V_39 = V_17 ;
return 0 ;
V_48:
#if F_50 ( F_37 )
if ( F_22 ( V_17 ) && F_23 ( V_17 ) )
F_51 ( V_37 , L_4 , V_17 ) ;
#endif
ASSERT ( ( F_52 ( V_17 ) & ( V_53 | V_54 ) ) !=
( V_53 | V_54 ) ) ;
F_47 ( V_17 , V_49 ) ;
F_36 ( V_17 ) ;
* V_39 = NULL ;
return F_34 ( V_47 ) ;
}
void
F_53 ( T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
T_7 * V_55 ;
if ( V_3 == NULL ) {
ASSERT ( F_9 ( V_17 , void * ) == NULL ) ;
if ( F_11 ( V_17 , void * ) != NULL ) {
V_55 = F_11 ( V_17 , T_7 * ) ;
if ( V_55 -> V_14 == V_15 ) {
V_19 = F_11 ( V_17 , V_21 * ) ;
F_54 ( V_19 -> V_13 . V_56 ,
V_55 ) ;
}
}
F_36 ( V_17 ) ;
return;
}
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( V_19 -> V_13 . V_14 == V_15 ) ;
ASSERT ( ! ( V_19 -> V_22 & V_23 ) ) ;
ASSERT ( ! ( V_19 -> V_24 . V_25 & V_26 ) ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
F_55 ( V_19 ) ;
if ( V_19 -> V_28 > 0 ) {
V_19 -> V_28 -- ;
return;
}
if ( V_19 -> V_13 . V_57 -> V_58 & V_59 )
return;
if ( V_19 -> V_22 & V_23 )
return;
ASSERT ( ! ( V_19 -> V_22 & V_27 ) ) ;
F_56 ( & V_19 -> V_13 ) ;
if ( V_19 -> V_22 & V_60 ) {
V_19 -> V_22 &= ~ V_60 ;
}
F_57 ( & V_19 -> V_29 ) ;
if ( ! F_58 ( V_19 ) ) {
ASSERT ( F_24 ( & V_19 -> V_29 ) == 0 ) ;
ASSERT ( ! ( V_19 -> V_13 . V_61 & V_62 ) ) ;
ASSERT ( ! ( V_19 -> V_22 & V_63 ) ) ;
F_59 ( V_17 ) ;
V_19 = NULL ;
}
F_14 ( V_17 , NULL ) ;
if ( V_19 != NULL ) {
F_54 ( V_19 -> V_13 . V_56 ,
( T_7 * ) V_19 ) ;
}
F_36 ( V_17 ) ;
return;
}
void
F_60 ( T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( ! ( V_19 -> V_22 & V_23 ) ) ;
ASSERT ( ! ( V_19 -> V_24 . V_25 & V_26 ) ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_22 |= V_60 ;
F_61 ( V_19 ) ;
}
void
F_62 ( T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( ! ( V_19 -> V_22 & V_23 ) ) ;
ASSERT ( ! ( V_19 -> V_24 . V_25 & V_26 ) ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
ASSERT ( V_19 -> V_22 & V_60 ) ;
V_19 -> V_22 &= ~ V_60 ;
F_63 ( V_19 ) ;
}
void
F_64 ( T_3 * V_3 ,
T_2 * V_17 ,
T_5 V_64 ,
T_5 V_65 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
ASSERT ( ( V_64 <= V_65 ) && ( V_65 < F_6 ( V_17 ) ) ) ;
ASSERT ( ( F_65 ( V_17 ) == NULL ) ||
( F_65 ( V_17 ) == V_66 ) ) ;
F_66 ( V_17 ) ;
F_67 ( V_17 ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
F_68 ( V_17 , V_66 ) ;
V_19 -> V_13 . V_67 = V_68 ;
F_69 ( V_19 ) ;
if ( V_19 -> V_22 & V_23 ) {
V_19 -> V_22 &= ~ V_23 ;
ASSERT ( F_22 ( V_17 ) ) ;
F_70 ( V_17 ) ;
V_19 -> V_24 . V_25 &= ~ V_26 ;
}
V_3 -> V_50 |= V_51 ;
V_19 -> V_13 . V_57 -> V_58 |= V_59 ;
V_19 -> V_22 |= V_27 ;
F_71 ( V_19 , V_64 , V_65 ) ;
}
void
F_72 (
T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
F_73 ( V_19 ) ;
if ( V_19 -> V_22 & V_23 ) {
ASSERT ( ! ( F_23 ( V_17 ) ) ) ;
ASSERT ( F_22 ( V_17 ) ) ;
ASSERT ( ! ( V_19 -> V_22 & ( V_27 | V_69 ) ) ) ;
ASSERT ( ! ( V_19 -> V_24 . V_25 & V_70 ) ) ;
ASSERT ( V_19 -> V_24 . V_25 & V_26 ) ;
ASSERT ( V_19 -> V_13 . V_57 -> V_58 & V_59 ) ;
ASSERT ( V_3 -> V_50 & V_51 ) ;
return;
}
F_74 ( V_17 ) ;
F_75 ( V_17 ) ;
V_19 -> V_22 |= V_23 ;
V_19 -> V_22 &= ~ ( V_71 | V_27 | V_69 ) ;
V_19 -> V_24 . V_25 &= ~ V_70 ;
V_19 -> V_24 . V_25 |= V_26 ;
memset ( ( char * ) ( V_19 -> V_24 . V_72 ) , 0 ,
( V_19 -> V_24 . V_73 * sizeof( T_5 ) ) ) ;
V_19 -> V_13 . V_57 -> V_58 |= V_59 ;
V_3 -> V_50 |= V_51 ;
}
void
F_76 (
T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_22 |= V_71 ;
}
void
F_77 (
T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_22 |= V_74 ;
V_19 -> V_13 . V_67 = V_68 ;
}
void
F_78 (
T_3 * V_3 ,
T_2 * V_17 )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_22 |= V_63 ;
}
void
F_79 (
T_3 * V_3 ,
T_2 * V_17 ,
T_5 type )
{
V_21 * V_19 ;
ASSERT ( F_8 ( V_17 ) ) ;
ASSERT ( F_9 ( V_17 , T_3 * ) == V_3 ) ;
ASSERT ( F_11 ( V_17 , void * ) != NULL ) ;
ASSERT ( type == V_75 ||
type == V_76 ||
type == V_77 ) ;
V_19 = F_11 ( V_17 , V_21 * ) ;
ASSERT ( F_24 ( & V_19 -> V_29 ) > 0 ) ;
V_19 -> V_24 . V_25 |= type ;
}
