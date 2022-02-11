static bool
F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ! ( V_4 -> V_5 . V_6 & V_7 ) ;
}
static bool
F_3 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ! ( V_4 -> V_5 . V_8 & V_7 ) ;
}
static T_1 F_4 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_1 ( V_2 ) ?
F_5 ( V_4 -> V_5 . V_9 ) : 0 ;
}
static T_1 F_6 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_2 ) ?
F_5 ( V_4 -> V_5 . V_10 ) : 0 ;
}
static int
F_7 ( struct V_11 * V_11 , T_1 V_12 ,
struct V_13 * V_14 )
{
T_2 V_15 = F_8 ( V_14 -> V_16 ) ;
T_3 V_17 = F_9 ( V_14 -> V_2 ) ;
char V_18 [ V_19 ] ;
F_10 ( V_18 , V_20 ,
true , V_21 ,
V_12 , V_15 ) ;
F_11 ( V_18 , F_5 ( V_17 ) ) ;
return F_12 ( V_11 -> V_22 , F_13 ( V_23 ) , V_18 ) ;
}
static int
F_14 ( struct V_11 * V_11 ,
T_1 V_24 ,
struct V_13 * V_14 )
{
bool V_25 = F_1 ( V_14 -> V_2 ) ;
T_2 V_15 = F_8 ( V_14 -> V_16 ) ;
T_1 V_26 = F_4 ( V_14 -> V_2 ) ;
char V_27 [ V_28 ] ;
unsigned int V_29 ;
T_1 V_17 ;
F_15 ( V_27 , V_30 , V_24 ) ;
V_29 = V_25 ?
V_31 :
V_32 ;
V_17 = F_5 ( F_9 ( V_14 -> V_2 ) ) ;
F_16 ( V_27 , V_15 ,
V_33 ,
V_29 , V_25 , V_17 , V_26 ) ;
return F_12 ( V_11 -> V_22 , F_13 ( V_34 ) , V_27 ) ;
}
static int
F_17 ( struct V_11 * V_11 ,
T_1 V_35 , T_4 V_36 , T_2 V_37 ,
enum V_38 V_39 ,
T_1 V_24 )
{
char V_40 [ V_41 ] ;
F_18 ( V_40 , V_42 , V_39 ,
V_37 , V_36 , V_35 ) ;
F_19 ( V_40 , V_24 ) ;
return F_12 ( V_11 -> V_22 , F_13 ( V_43 ) , V_40 ) ;
}
static int F_20 ( struct V_11 * V_11 ,
struct V_13 * V_14 ,
enum V_38 V_39 ,
T_1 V_24 )
{
T_2 V_37 = F_21 ( V_14 -> V_16 ) ;
T_3 V_35 ;
int V_44 ;
V_44 = F_14 ( V_11 , V_24 ,
V_14 ) ;
if ( V_44 )
return V_44 ;
V_35 = F_22 ( V_45 ,
V_14 -> V_2 ) . V_46 ;
return F_17 ( V_11 , F_5 ( V_35 ) ,
32 , V_37 , V_39 ,
V_24 ) ;
}
static bool F_23 ( enum V_47 V_48 ,
const struct V_1 * V_2 )
{
union V_49 V_50 = F_22 ( V_48 , V_2 ) ;
union V_49 V_51 = F_24 ( V_48 , V_2 ) ;
union V_49 V_52 = { 0 } ;
return memcmp ( & V_50 , & V_52 , sizeof( V_52 ) ) &&
memcmp ( & V_51 , & V_52 , sizeof( V_52 ) ) ;
}
static bool F_25 ( const struct V_11 * V_11 ,
const struct V_1 * V_2 ,
enum V_47 V_53 )
{
struct V_3 * V_54 = F_2 ( V_2 ) ;
T_5 V_55 = V_7 ;
bool V_56 = V_54 -> V_5 . V_57 . V_58 == 0 ;
bool V_59 = V_54 -> V_5 . V_57 . V_60 & 0x1 ;
return ( V_54 -> V_5 . V_6 & ~ V_55 ) == 0 &&
( V_54 -> V_5 . V_8 & ~ V_55 ) == 0 &&
V_56 && V_59 &&
F_23 ( V_45 , V_2 ) ;
}
static struct V_61
F_26 ( struct V_11 * V_11 ,
const struct V_1 * V_2 )
{
enum V_62 V_63 ;
V_63 = F_3 ( V_2 ) ?
V_64 :
V_65 ;
return (struct V_61 ) {
. V_63 = V_63 ,
. V_66 = F_6 ( V_2 ) ,
. V_67 = V_45 ,
. V_50 = F_22 ( V_45 ,
V_2 ) ,
} ;
}
