static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
T_1 V_17 , T_1 V_18 ,
T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
V_21 -> V_22 = true ;
if ( V_3 -> V_12 )
F_6 ( V_3 -> V_12 ) ;
F_7 ( V_12 ) ;
return F_8 ( V_3 , V_10 , V_12 ,
V_13 , V_14 , V_15 , V_16 ,
V_17 , V_18 , V_19 , V_20 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
F_10 ( L_1 , V_21 -> V_23 ) ;
if ( V_3 -> V_10 )
F_11 ( V_3 -> V_10 , V_3 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
F_9 ( V_3 ) ;
F_13 ( V_3 ) ;
F_14 ( V_21 ) ;
}
void F_15 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
}
int F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 , T_2 V_28 )
{
return - V_29 ;
}
void F_17 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_30 V_31 = V_21 -> V_31 ;
T_1 V_32 ;
F_18 ( V_1 , F_19 ( V_31 ) ,
F_20 ( V_12 -> V_33 [ 0 ] ) |
F_21 ( V_12 -> V_33 [ 1 ] ) ) ;
F_18 ( V_1 , F_22 ( V_31 ) ,
F_23 ( V_12 -> V_33 [ 2 ] ) |
F_24 ( V_12 -> V_33 [ 3 ] ) ) ;
F_25 ( F_26 ( V_12 , 0 ) , V_1 -> V_34 , & V_32 ) ;
F_18 ( V_1 , F_27 ( V_31 ) , V_32 ) ;
V_3 -> V_12 = V_12 ;
}
int F_8 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
T_1 V_17 , T_1 V_18 ,
T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_30 V_31 = V_21 -> V_31 ;
const struct V_35 * V_36 ;
T_1 V_37 = 0 ;
T_1 V_38 = V_39 ;
T_1 V_40 = V_39 ;
V_17 = V_17 >> 16 ;
V_18 = V_18 >> 16 ;
V_19 = V_19 >> 16 ;
V_20 = V_20 >> 16 ;
F_10 ( L_2 , V_21 -> V_23 ,
V_12 -> V_41 . V_34 , V_17 , V_18 , V_19 , V_20 ,
V_10 -> V_41 . V_34 , V_13 , V_14 , V_15 , V_16 ) ;
if ( V_19 != V_15 ) {
V_37 |= V_42 ;
}
if ( V_20 != V_16 ) {
V_37 |= V_43 ;
}
F_18 ( V_1 , F_28 ( V_31 ) ,
F_29 ( V_19 ) |
F_30 ( V_20 ) ) ;
F_18 ( V_1 , F_31 ( V_31 ) ,
F_32 ( V_17 ) |
F_33 ( V_18 ) ) ;
F_18 ( V_1 , F_34 ( V_31 ) ,
F_35 ( V_15 ) |
F_36 ( V_16 ) ) ;
F_18 ( V_1 , F_37 ( V_31 ) ,
F_38 ( V_13 ) |
F_39 ( V_14 ) ) ;
F_17 ( V_3 , V_12 ) ;
V_36 = F_40 ( F_41 ( V_12 ) ) ;
F_18 ( V_1 , F_42 ( V_31 ) ,
F_43 ( V_36 -> V_44 ) |
F_44 ( V_36 -> V_45 ) |
F_45 ( V_36 -> V_46 ) |
F_46 ( V_36 -> V_47 ) |
F_47 ( V_36 -> V_48 , V_49 ) |
F_48 ( V_36 -> V_50 - 1 ) |
F_49 ( V_36 -> V_51 - 1 ) |
F_47 ( V_36 -> V_52 , V_53 ) ) ;
F_18 ( V_1 , F_50 ( V_31 ) ,
F_51 ( V_36 -> V_54 [ 0 ] ) |
F_52 ( V_36 -> V_54 [ 1 ] ) |
F_53 ( V_36 -> V_54 [ 2 ] ) |
F_54 ( V_36 -> V_54 [ 3 ] ) ) ;
F_18 ( V_1 , F_55 ( V_31 ) , V_37 ) ;
F_18 ( V_1 , F_56 ( V_31 ) , V_38 ) ;
F_18 ( V_1 , F_57 ( V_31 ) , V_40 ) ;
F_58 ( V_10 , V_3 ) ;
return 0 ;
}
enum V_30 F_59 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
return V_21 -> V_31 ;
}
struct V_2 * F_60 ( struct V_55 * V_6 ,
enum V_30 V_56 , bool V_57 )
{
struct V_2 * V_3 = NULL ;
struct V_21 * V_21 ;
int V_58 ;
V_21 = F_61 ( sizeof( * V_21 ) , V_59 ) ;
if ( ! V_21 ) {
V_58 = - V_60 ;
goto V_61;
}
V_3 = & V_21 -> V_41 ;
V_21 -> V_31 = V_56 ;
V_21 -> V_23 = V_62 [ V_56 ] ;
V_21 -> V_63 = F_62 ( V_56 , V_21 -> V_64 ,
F_63 ( V_21 -> V_64 ) ) ;
F_64 ( V_6 , V_3 , 0xff , & V_65 ,
V_21 -> V_64 , V_21 -> V_63 ,
V_57 ) ;
F_15 ( V_3 , & V_3 -> V_41 ) ;
return V_3 ;
V_61:
if ( V_3 )
F_12 ( V_3 ) ;
return F_65 ( V_58 ) ;
}
