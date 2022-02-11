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
error = F_8 ( V_3 , V_10 , V_11 , V_13 ,
V_21 ) ;
V_3 -> V_22 |= V_23 ;
V_7 -> V_9 . V_24 -> V_25 |= V_26 ;
V_16 = V_7 -> V_27 ;
ASSERT ( V_16 < V_7 -> V_28 . V_29 ) ;
V_20 = & ( V_7 -> V_28 . V_30 [ V_16 ] ) ;
V_20 -> V_31 = V_10 ;
V_20 -> V_11 = V_11 ;
V_7 -> V_27 ++ ;
return error ;
}
static int
F_9 (
void * V_32 ,
struct V_33 * V_34 ,
struct V_33 * V_35 )
{
struct V_14 * V_15 = V_32 ;
struct V_36 * V_37 ;
struct V_36 * V_38 ;
V_37 = F_10 ( V_34 , struct V_36 , V_39 ) ;
V_38 = F_10 ( V_35 , struct V_36 , V_39 ) ;
return F_5 ( V_15 , V_37 -> V_40 ) -
F_5 ( V_15 , V_38 -> V_40 ) ;
}
STATIC void *
F_11 (
struct V_2 * V_3 ,
unsigned int V_41 )
{
struct V_4 * V_5 ;
ASSERT ( V_3 != NULL ) ;
ASSERT ( V_41 > 0 ) ;
V_5 = F_12 ( V_3 -> V_8 , V_41 ) ;
ASSERT ( V_5 != NULL ) ;
F_3 ( V_3 , & V_5 -> V_42 ) ;
return V_5 ;
}
STATIC void
F_13 (
struct V_2 * V_3 ,
void * V_43 ,
struct V_33 * V_44 )
{
struct V_4 * V_5 = V_43 ;
struct V_36 * free ;
T_1 V_16 ;
struct V_19 * V_20 ;
free = F_10 ( V_44 , struct V_36 , V_39 ) ;
V_3 -> V_22 |= V_23 ;
V_5 -> V_42 . V_24 -> V_25 |= V_26 ;
V_16 = F_14 ( & V_5 -> V_45 ) - 1 ;
ASSERT ( V_16 < V_5 -> V_46 . V_47 ) ;
V_20 = & V_5 -> V_46 . V_48 [ V_16 ] ;
V_20 -> V_31 = free -> V_40 ;
V_20 -> V_11 = free -> V_49 ;
}
STATIC void *
F_15 (
struct V_2 * V_3 ,
void * V_43 ,
unsigned int V_41 )
{
return F_1 ( V_3 , V_43 , V_41 ) ;
}
STATIC int
F_16 (
struct V_2 * V_3 ,
struct V_50 * V_51 ,
struct V_33 * V_44 ,
void * V_52 ,
void * * V_53 )
{
struct V_36 * free ;
int error ;
free = F_10 ( V_44 , struct V_36 , V_39 ) ;
error = F_4 ( V_3 , V_52 ,
free -> V_40 ,
free -> V_49 ,
& free -> V_54 ) ;
F_17 ( free ) ;
return error ;
}
STATIC void
F_18 (
void * V_43 )
{
F_19 ( V_43 ) ;
}
STATIC void
F_20 (
struct V_33 * V_44 )
{
struct V_36 * free ;
free = F_10 ( V_44 , struct V_36 , V_39 ) ;
F_17 ( free ) ;
}
void
F_21 ( void )
{
F_22 ( & V_55 ) ;
}
