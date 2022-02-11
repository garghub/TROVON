static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 != 1 ) {
F_2 ( L_1 ,
V_2 -> V_7 -> V_8 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_3 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
memset ( & V_11 -> V_14 , 0 , sizeof( V_11 -> V_14 ) ) ;
memset ( & V_11 -> V_15 , 0 , sizeof( V_11 -> V_15 ) ) ;
V_11 -> V_16 = V_13 -> V_16 ;
V_11 -> V_14 . V_17 = V_13 -> V_18 ;
V_11 -> V_15 . V_17 = V_13 -> V_19 ;
V_11 -> V_20 = V_13 -> V_21 ;
V_11 -> V_22 = V_13 -> V_23 ;
}
static unsigned int
F_4 ( struct V_24 * V_25 , const struct V_26 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 V_27 ;
enum V_28 V_29 ;
struct V_30 * V_31 ;
V_31 = F_5 ( V_25 , & V_29 ) ;
F_6 ( V_31 != NULL &&
( V_29 == V_32 || V_29 == V_33 ||
V_29 == V_34 ) ) ;
F_3 ( & V_27 , & V_4 -> V_27 [ 0 ] ) ;
return F_7 ( V_31 , & V_27 , V_35 ) ;
}
static unsigned int
F_8 ( struct V_24 * V_25 , const struct V_26 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 V_27 ;
enum V_28 V_29 ;
struct V_30 * V_31 ;
V_31 = F_5 ( V_25 , & V_29 ) ;
F_6 ( V_31 != NULL &&
( V_29 == V_32 || V_29 == V_33 ) ) ;
F_3 ( & V_27 , & V_4 -> V_27 [ 0 ] ) ;
return F_7 ( V_31 , & V_27 , V_36 ) ;
}
static unsigned int
F_9 ( struct V_24 * V_25 , const struct V_26 * V_2 )
{
const struct V_10 * V_27 = V_2 -> V_5 ;
enum V_28 V_29 ;
struct V_30 * V_31 ;
V_31 = F_5 ( V_25 , & V_29 ) ;
F_6 ( V_31 != NULL &&
( V_29 == V_32 || V_29 == V_33 ||
V_29 == V_34 ) ) ;
return F_7 ( V_31 , V_27 , V_35 ) ;
}
static unsigned int
F_10 ( struct V_24 * V_25 , const struct V_26 * V_2 )
{
const struct V_10 * V_27 = V_2 -> V_5 ;
enum V_28 V_29 ;
struct V_30 * V_31 ;
V_31 = F_5 ( V_25 , & V_29 ) ;
F_6 ( V_31 != NULL &&
( V_29 == V_32 || V_29 == V_33 ) ) ;
return F_7 ( V_31 , V_27 , V_36 ) ;
}
static int T_1 F_11 ( void )
{
return F_12 ( V_37 ,
F_13 ( V_37 ) ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_37 , F_13 ( V_37 ) ) ;
}
