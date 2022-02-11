void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
ASSERT ( F_2 ( V_4 , V_6 ) ) ;
if ( V_4 -> V_7 == NULL )
F_3 ( V_4 , V_4 -> V_8 ) ;
V_5 = V_4 -> V_7 ;
ASSERT ( V_5 -> V_9 == 0 ) ;
F_4 ( V_2 , & V_5 -> V_10 ) ;
F_5 ( V_4 ) ;
}
void
F_6 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_11 )
{
F_1 ( V_2 , V_4 ) ;
F_7 ( V_4 ) ;
V_4 -> V_7 -> V_9 = V_11 ;
}
void
F_8 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_13 * V_13 = F_9 ( V_4 ) ;
T_3 V_14 ;
ASSERT ( V_2 ) ;
ASSERT ( F_2 ( V_4 , V_6 ) ) ;
V_14 = F_10 ( V_13 -> V_15 ) ;
if ( ( V_12 & V_16 ) &&
! F_11 ( & V_13 -> V_17 , & V_14 ) ) {
V_13 -> V_17 = V_14 ;
}
if ( ( V_12 & V_18 ) &&
! F_11 ( & V_13 -> V_19 , & V_14 ) ) {
V_13 -> V_19 = V_14 ;
}
}
void
F_12 (
T_4 * V_2 ,
T_5 * V_4 ,
T_2 V_12 )
{
ASSERT ( V_4 -> V_7 != NULL ) ;
ASSERT ( F_2 ( V_4 , V_6 ) ) ;
V_2 -> V_20 |= V_21 ;
V_4 -> V_7 -> V_10 . V_22 -> V_23 |= V_24 ;
V_12 |= V_4 -> V_7 -> V_25 ;
V_4 -> V_7 -> V_26 . V_27 |= V_12 ;
}
STATIC void
F_5 (
T_5 * V_4 )
{
T_1 * V_5 ;
ASSERT ( V_4 -> V_7 != NULL ) ;
V_5 = V_4 -> V_7 ;
if ( V_5 -> V_28 != 0 ) {
ASSERT ( V_5 -> V_29 != NULL ) ;
F_13 ( V_5 -> V_29 ) ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 = NULL ;
}
if ( V_4 -> V_30 . V_31 == V_32 ) {
ASSERT ( ( V_4 -> V_33 . V_34 != NULL ) &&
( V_4 -> V_33 . V_35 > 0 ) ) ;
V_5 -> V_28 = V_4 -> V_33 . V_35 ;
V_5 -> V_29 =
( char * ) F_14 ( V_5 -> V_28 , V_36 ) ;
memcpy ( V_5 -> V_29 , ( char * ) ( V_4 -> V_33 . V_34 ) ,
V_5 -> V_28 ) ;
}
}
