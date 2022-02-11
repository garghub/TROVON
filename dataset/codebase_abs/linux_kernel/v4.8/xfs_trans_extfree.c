struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 ;
ASSERT ( V_3 != NULL ) ;
ASSERT ( V_6 > 0 ) ;
V_7 = F_2 ( V_3 -> V_8 , V_5 , V_6 ) ;
ASSERT ( V_7 != NULL ) ;
F_3 ( V_3 , & V_7 -> V_9 ) ;
return V_7 ;
}
int
F_4 (
struct V_2 * V_3 ,
struct V_1 * V_7 ,
T_2 V_10 ,
T_3 V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_3 -> V_8 ;
T_1 V_16 ;
T_4 V_17 = F_5 ( V_15 , V_10 ) ;
T_5 V_18 = F_6 ( V_15 , V_10 ) ;
struct V_19 * V_20 ;
int error ;
F_7 ( V_3 -> V_8 , V_17 , 0 , V_18 , V_11 ) ;
error = F_8 ( V_3 , V_10 , V_11 , V_13 ) ;
V_3 -> V_21 |= V_22 ;
V_7 -> V_9 . V_23 -> V_24 |= V_25 ;
V_16 = V_7 -> V_26 ;
ASSERT ( V_16 < V_7 -> V_27 . V_28 ) ;
V_20 = & ( V_7 -> V_27 . V_29 [ V_16 ] ) ;
V_20 -> V_30 = V_10 ;
V_20 -> V_11 = V_11 ;
V_7 -> V_26 ++ ;
return error ;
}
static int
F_9 (
void * V_31 ,
struct V_32 * V_33 ,
struct V_32 * V_34 )
{
struct V_14 * V_15 = V_31 ;
struct V_35 * V_36 ;
struct V_35 * V_37 ;
V_36 = F_10 ( V_33 , struct V_35 , V_38 ) ;
V_37 = F_10 ( V_34 , struct V_35 , V_38 ) ;
return F_5 ( V_15 , V_36 -> V_39 ) -
F_5 ( V_15 , V_37 -> V_39 ) ;
}
STATIC void *
F_11 (
struct V_2 * V_3 ,
unsigned int V_40 )
{
struct V_4 * V_5 ;
ASSERT ( V_3 != NULL ) ;
ASSERT ( V_40 > 0 ) ;
V_5 = F_12 ( V_3 -> V_8 , V_40 ) ;
ASSERT ( V_5 != NULL ) ;
F_3 ( V_3 , & V_5 -> V_41 ) ;
return V_5 ;
}
STATIC void
F_13 (
struct V_2 * V_3 ,
void * V_42 ,
struct V_32 * V_43 )
{
struct V_4 * V_5 = V_42 ;
struct V_35 * free ;
T_1 V_16 ;
struct V_19 * V_20 ;
free = F_10 ( V_43 , struct V_35 , V_38 ) ;
V_3 -> V_21 |= V_22 ;
V_5 -> V_41 . V_23 -> V_24 |= V_25 ;
V_16 = F_14 ( & V_5 -> V_44 ) - 1 ;
ASSERT ( V_16 < V_5 -> V_45 . V_46 ) ;
V_20 = & V_5 -> V_45 . V_47 [ V_16 ] ;
V_20 -> V_30 = free -> V_39 ;
V_20 -> V_11 = free -> V_48 ;
}
STATIC void *
F_15 (
struct V_2 * V_3 ,
void * V_42 ,
unsigned int V_40 )
{
return F_1 ( V_3 , V_42 , V_40 ) ;
}
STATIC int
F_16 (
struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_32 * V_43 ,
void * V_51 ,
void * * V_52 )
{
struct V_35 * free ;
int error ;
free = F_10 ( V_43 , struct V_35 , V_38 ) ;
error = F_4 ( V_3 , V_51 ,
free -> V_39 ,
free -> V_48 ,
& free -> V_53 ) ;
F_17 ( free ) ;
return error ;
}
STATIC void
F_18 (
void * V_42 )
{
F_19 ( V_42 ) ;
}
STATIC void
F_20 (
struct V_32 * V_43 )
{
struct V_35 * free ;
free = F_10 ( V_43 , struct V_35 , V_38 ) ;
F_17 ( free ) ;
}
void
F_21 ( void )
{
F_22 ( & V_54 ) ;
}
