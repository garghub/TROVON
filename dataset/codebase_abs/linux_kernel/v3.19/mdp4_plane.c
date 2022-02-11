static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_9 ) ;
}
void F_9 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
}
int F_10 ( struct V_2 * V_3 ,
struct V_12 * V_13 , T_1 V_14 )
{
return - V_15 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_1 , V_9 -> V_18 , V_17 -> V_19 . V_20 ) ;
return F_13 ( V_17 , V_1 -> V_20 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_2 , V_9 -> V_18 , V_17 -> V_19 . V_20 ) ;
F_15 ( V_17 , V_1 -> V_20 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
return 0 ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_21 * V_23 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
int V_24 ;
V_24 = F_18 ( V_3 ,
V_22 -> V_25 , V_22 -> V_17 ,
V_22 -> V_26 , V_22 -> V_27 ,
V_22 -> V_28 , V_22 -> V_29 ,
V_22 -> V_30 , V_22 -> V_31 ,
V_22 -> V_32 , V_22 -> V_33 ) ;
F_19 ( V_24 < 0 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_34 V_35 = V_9 -> V_35 ;
T_2 V_36 = F_21 ( V_17 , V_1 -> V_20 , 0 ) ;
F_12 ( L_3 , V_9 -> V_18 ,
V_36 , V_17 -> V_37 [ 0 ] ) ;
F_22 ( V_1 , F_23 ( V_35 ) ,
F_24 ( V_17 -> V_37 [ 0 ] ) |
F_25 ( V_17 -> V_37 [ 1 ] ) ) ;
F_22 ( V_1 , F_26 ( V_35 ) ,
F_27 ( V_17 -> V_37 [ 2 ] ) |
F_28 ( V_17 -> V_37 [ 3 ] ) ) ;
F_22 ( V_1 , F_29 ( V_35 ) , V_36 ) ;
V_3 -> V_17 = V_17 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_38 * V_25 , struct V_16 * V_17 ,
int V_26 , int V_27 ,
unsigned int V_28 , unsigned int V_29 ,
T_2 V_30 , T_2 V_31 ,
T_2 V_32 , T_2 V_33 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_34 V_35 = V_9 -> V_35 ;
const struct V_39 * V_40 ;
T_2 V_41 = 0 ;
T_2 V_42 = V_43 ;
T_2 V_44 = V_43 ;
if ( ! ( V_25 && V_17 ) ) {
F_12 ( L_4 , V_9 -> V_18 ) ;
return 0 ;
}
V_30 = V_30 >> 16 ;
V_31 = V_31 >> 16 ;
V_32 = V_32 >> 16 ;
V_33 = V_33 >> 16 ;
F_12 ( L_5 , V_9 -> V_18 ,
V_17 -> V_19 . V_20 , V_30 , V_31 , V_32 , V_33 ,
V_25 -> V_19 . V_20 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_32 != V_28 ) {
V_41 |= V_45 ;
}
if ( V_33 != V_29 ) {
V_41 |= V_46 ;
}
F_22 ( V_1 , F_30 ( V_35 ) ,
F_31 ( V_32 ) |
F_32 ( V_33 ) ) ;
F_22 ( V_1 , F_33 ( V_35 ) ,
F_34 ( V_30 ) |
F_35 ( V_31 ) ) ;
F_22 ( V_1 , F_36 ( V_35 ) ,
F_37 ( V_28 ) |
F_38 ( V_29 ) ) ;
F_22 ( V_1 , F_39 ( V_35 ) ,
F_40 ( V_26 ) |
F_41 ( V_27 ) ) ;
F_20 ( V_3 , V_17 ) ;
V_40 = F_42 ( F_43 ( V_17 ) ) ;
F_22 ( V_1 , F_44 ( V_35 ) ,
F_45 ( V_40 -> V_47 ) |
F_46 ( V_40 -> V_48 ) |
F_47 ( V_40 -> V_49 ) |
F_48 ( V_40 -> V_50 ) |
F_49 ( V_40 -> V_51 , V_52 ) |
F_50 ( V_40 -> V_53 - 1 ) |
F_51 ( V_40 -> V_54 - 1 ) |
F_49 ( V_40 -> V_55 , V_56 ) ) ;
F_22 ( V_1 , F_52 ( V_35 ) ,
F_53 ( V_40 -> V_57 [ 0 ] ) |
F_54 ( V_40 -> V_57 [ 1 ] ) |
F_55 ( V_40 -> V_57 [ 2 ] ) |
F_56 ( V_40 -> V_57 [ 3 ] ) ) ;
F_22 ( V_1 , F_57 ( V_35 ) , V_41 ) ;
F_22 ( V_1 , F_58 ( V_35 ) , V_42 ) ;
F_22 ( V_1 , F_59 ( V_35 ) , V_44 ) ;
return 0 ;
}
enum V_34 F_60 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
return V_9 -> V_35 ;
}
struct V_2 * F_61 ( struct V_58 * V_6 ,
enum V_34 V_59 , bool V_60 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_24 ;
enum V_61 type ;
V_9 = F_62 ( sizeof( * V_9 ) , V_62 ) ;
if ( ! V_9 ) {
V_24 = - V_63 ;
goto V_64;
}
V_3 = & V_9 -> V_19 ;
V_9 -> V_35 = V_59 ;
V_9 -> V_18 = V_65 [ V_59 ] ;
V_9 -> V_66 = F_63 ( V_59 , V_9 -> V_67 ,
F_64 ( V_9 -> V_67 ) ) ;
type = V_60 ? V_68 : V_69 ;
V_24 = F_65 ( V_6 , V_3 , 0xff , & V_70 ,
V_9 -> V_67 , V_9 -> V_66 , type ) ;
if ( V_24 )
goto V_64;
F_66 ( V_3 , & V_71 ) ;
F_9 ( V_3 , & V_3 -> V_19 ) ;
return V_3 ;
V_64:
if ( V_3 )
F_4 ( V_3 ) ;
return F_67 ( V_24 ) ;
}
