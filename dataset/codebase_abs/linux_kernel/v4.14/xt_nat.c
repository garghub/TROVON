static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 != 1 ) {
F_2 ( L_1 ,
V_2 -> V_7 -> V_8 ) ;
return - V_9 ;
}
return F_3 ( V_2 -> V_10 , V_2 -> V_11 ) ;
}
static int F_4 ( const struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_10 , V_2 -> V_11 ) ;
}
static void F_5 ( const struct V_12 * V_2 )
{
F_6 ( V_2 -> V_10 , V_2 -> V_11 ) ;
}
static void F_7 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
memset ( & V_14 -> V_17 , 0 , sizeof( V_14 -> V_17 ) ) ;
memset ( & V_14 -> V_18 , 0 , sizeof( V_14 -> V_18 ) ) ;
V_14 -> V_19 = V_16 -> V_19 ;
V_14 -> V_17 . V_20 = V_16 -> V_21 ;
V_14 -> V_18 . V_20 = V_16 -> V_22 ;
V_14 -> V_23 = V_16 -> V_24 ;
V_14 -> V_25 = V_16 -> V_26 ;
}
static unsigned int
F_8 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 V_30 ;
enum V_31 V_32 ;
struct V_33 * V_34 ;
V_34 = F_9 ( V_28 , & V_32 ) ;
F_10 ( ! ( V_34 != NULL &&
( V_32 == V_35 || V_32 == V_36 ||
V_32 == V_37 ) ) ) ;
F_7 ( & V_30 , & V_4 -> V_30 [ 0 ] ) ;
return F_11 ( V_34 , & V_30 , V_38 ) ;
}
static unsigned int
F_12 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 V_30 ;
enum V_31 V_32 ;
struct V_33 * V_34 ;
V_34 = F_9 ( V_28 , & V_32 ) ;
F_10 ( ! ( V_34 != NULL &&
( V_32 == V_35 || V_32 == V_36 ) ) ) ;
F_7 ( & V_30 , & V_4 -> V_30 [ 0 ] ) ;
return F_11 ( V_34 , & V_30 , V_39 ) ;
}
static unsigned int
F_13 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_13 * V_30 = V_2 -> V_5 ;
enum V_31 V_32 ;
struct V_33 * V_34 ;
V_34 = F_9 ( V_28 , & V_32 ) ;
F_10 ( ! ( V_34 != NULL &&
( V_32 == V_35 || V_32 == V_36 ||
V_32 == V_37 ) ) ) ;
return F_11 ( V_34 , V_30 , V_38 ) ;
}
static unsigned int
F_14 ( struct V_27 * V_28 , const struct V_29 * V_2 )
{
const struct V_13 * V_30 = V_2 -> V_5 ;
enum V_31 V_32 ;
struct V_33 * V_34 ;
V_34 = F_9 ( V_28 , & V_32 ) ;
F_10 ( ! ( V_34 != NULL &&
( V_32 == V_35 || V_32 == V_36 ) ) ) ;
return F_11 ( V_34 , V_30 , V_39 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( V_40 ,
F_17 ( V_40 ) ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_40 , F_17 ( V_40 ) ) ;
}
