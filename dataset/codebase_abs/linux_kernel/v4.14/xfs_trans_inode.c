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
}
void
F_5 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_13 * V_13 = F_6 ( V_4 ) ;
struct V_14 V_15 ;
ASSERT ( V_2 ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
V_15 = F_7 ( V_13 ) ;
if ( V_12 & V_16 )
V_13 -> V_17 = V_15 ;
if ( V_12 & V_18 )
V_13 -> V_19 = V_15 ;
}
void
F_8 (
T_3 * V_2 ,
T_4 * V_4 ,
T_1 V_12 )
{
ASSERT ( V_4 -> V_8 != NULL ) ;
ASSERT ( F_2 ( V_4 , V_7 ) ) ;
V_4 -> V_8 -> V_20 |= V_12 ;
if ( ! ( V_4 -> V_8 -> V_11 . V_21 -> V_22 & V_23 ) &&
F_9 ( F_6 ( V_4 ) ) ) {
F_6 ( V_4 ) -> V_24 ++ ;
V_12 |= V_25 ;
}
V_2 -> V_26 |= V_27 ;
V_4 -> V_8 -> V_11 . V_21 -> V_22 |= V_23 ;
V_12 |= V_4 -> V_8 -> V_28 ;
V_4 -> V_8 -> V_29 |= V_12 ;
}
int
F_10 (
struct V_1 * * V_30 ,
struct V_3 * V_4 )
{
int error ;
F_8 ( * V_30 , V_4 , V_25 ) ;
error = F_11 ( V_30 ) ;
if ( ! error )
F_1 ( * V_30 , V_4 , 0 ) ;
return error ;
}
