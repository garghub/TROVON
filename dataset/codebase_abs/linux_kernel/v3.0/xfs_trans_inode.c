void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
ASSERT ( V_4 -> V_6 == NULL ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
if ( V_4 -> V_8 == NULL )
F_3 ( V_4 , V_4 -> V_9 ) ;
V_5 = V_4 -> V_8 ;
ASSERT ( V_5 -> V_10 == 0 ) ;
F_4 ( V_2 , & V_5 -> V_11 ) ;
F_5 ( V_4 ) ;
V_4 -> V_6 = V_2 ;
}
void
F_6 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_12 )
{
F_1 ( V_2 , V_4 ) ;
F_7 ( V_4 ) ;
V_4 -> V_8 -> V_10 = V_12 ;
}
void
F_8 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_13 )
{
struct V_14 * V_14 = F_9 ( V_4 ) ;
T_3 V_15 ;
ASSERT ( V_2 ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
ASSERT ( V_4 -> V_6 == V_2 ) ;
V_15 = F_10 ( V_14 -> V_16 ) ;
if ( ( V_13 & V_17 ) &&
! F_11 ( & V_14 -> V_18 , & V_15 ) ) {
V_14 -> V_18 = V_15 ;
}
if ( ( V_13 & V_19 ) &&
! F_11 ( & V_14 -> V_20 , & V_15 ) ) {
V_14 -> V_20 = V_15 ;
}
}
void
F_12 (
T_4 * V_2 ,
T_5 * V_4 ,
T_2 V_13 )
{
ASSERT ( V_4 -> V_6 == V_2 ) ;
ASSERT ( V_4 -> V_8 != NULL ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
V_2 -> V_21 |= V_22 ;
V_4 -> V_8 -> V_11 . V_23 -> V_24 |= V_25 ;
V_13 |= V_4 -> V_8 -> V_26 ;
V_4 -> V_8 -> V_27 . V_28 |= V_13 ;
}
STATIC void
F_5 (
T_5 * V_4 )
{
T_1 * V_5 ;
ASSERT ( V_4 -> V_8 != NULL ) ;
V_5 = V_4 -> V_8 ;
if ( V_5 -> V_29 != 0 ) {
ASSERT ( V_5 -> V_30 != NULL ) ;
F_13 ( V_5 -> V_30 ) ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = NULL ;
}
if ( V_4 -> V_31 . V_32 == V_33 ) {
ASSERT ( ( V_4 -> V_34 . V_35 != NULL ) &&
( V_4 -> V_34 . V_36 > 0 ) ) ;
V_5 -> V_29 = V_4 -> V_34 . V_36 ;
V_5 -> V_30 =
( char * ) F_14 ( V_5 -> V_29 , V_37 ) ;
memcpy ( V_5 -> V_30 , ( char * ) ( V_4 -> V_34 . V_35 ) ,
V_5 -> V_29 ) ;
}
}
