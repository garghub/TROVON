void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 * V_6 ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
if ( V_4 -> V_8 == NULL )
F_3 ( V_4 , V_4 -> V_9 ) ;
V_6 = V_4 -> V_8 ;
ASSERT ( V_6 -> V_10 == 0 ) ;
V_6 -> V_10 = V_5 ;
F_4 ( V_2 , & V_6 -> V_11 ) ;
F_5 ( V_4 ) ;
}
void
F_6 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_13 * V_13 = F_7 ( V_4 ) ;
T_3 V_14 ;
ASSERT ( V_2 ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
V_14 = F_8 ( V_13 -> V_15 ) ;
if ( ( V_12 & V_16 ) &&
! F_9 ( & V_13 -> V_17 , & V_14 ) ) {
V_13 -> V_17 = V_14 ;
V_4 -> V_18 . V_19 . V_20 = V_14 . V_21 ;
V_4 -> V_18 . V_19 . V_22 = V_14 . V_23 ;
}
if ( ( V_12 & V_24 ) &&
! F_9 ( & V_13 -> V_25 , & V_14 ) ) {
V_13 -> V_25 = V_14 ;
V_4 -> V_18 . V_26 . V_20 = V_14 . V_21 ;
V_4 -> V_18 . V_26 . V_22 = V_14 . V_23 ;
}
}
void
F_10 (
T_4 * V_2 ,
T_5 * V_4 ,
T_1 V_12 )
{
ASSERT ( V_4 -> V_8 != NULL ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
V_2 -> V_27 |= V_28 ;
V_4 -> V_8 -> V_11 . V_29 -> V_30 |= V_31 ;
V_12 |= V_4 -> V_8 -> V_32 ;
V_4 -> V_8 -> V_33 |= V_12 ;
}
STATIC void
F_5 (
T_5 * V_4 )
{
T_2 * V_6 ;
ASSERT ( V_4 -> V_8 != NULL ) ;
V_6 = V_4 -> V_8 ;
if ( V_6 -> V_34 != 0 ) {
ASSERT ( V_6 -> V_35 != NULL ) ;
F_11 ( V_6 -> V_35 ) ;
V_6 -> V_34 = 0 ;
V_6 -> V_35 = NULL ;
}
if ( V_4 -> V_18 . V_36 == V_37 ) {
ASSERT ( ( V_4 -> V_38 . V_39 != NULL ) &&
( V_4 -> V_38 . V_40 > 0 ) ) ;
V_6 -> V_34 = V_4 -> V_38 . V_40 ;
V_6 -> V_35 =
( char * ) F_12 ( V_6 -> V_34 , V_41 ) ;
memcpy ( V_6 -> V_35 , ( char * ) ( V_4 -> V_38 . V_39 ) ,
V_6 -> V_34 ) ;
}
}
