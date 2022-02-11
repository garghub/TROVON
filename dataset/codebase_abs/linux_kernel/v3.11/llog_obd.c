static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( V_4 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_3 ;
F_3 ( & V_4 -> V_6 , 1 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 ) {
F_5 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
if ( V_4 -> V_8 ) {
F_6 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
F_7 ( V_4 ) ;
}
int F_8 ( const struct V_9 * V_10 , struct V_1 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
struct V_2 * V_3 ;
int V_14 = 0 ;
F_9 ( & V_12 -> V_15 ) ;
if ( ! F_10 ( & V_4 -> V_6 ) ) {
F_11 ( & V_12 -> V_15 ) ;
return V_14 ;
}
V_12 -> V_16 [ V_4 -> V_17 ] = NULL ;
F_11 ( & V_12 -> V_15 ) ;
V_3 = V_4 -> V_5 ;
F_9 ( & V_3 -> V_18 ) ;
F_11 ( & V_3 -> V_18 ) ;
F_12 ( V_3 -> V_19 == 1 ||
V_3 -> V_20 == 1 || V_3 -> V_21 == 0 ,
L_1 , ! ! V_3 -> V_19 ,
! ! V_3 -> V_20 , ! ! V_3 -> V_21 ) ;
if ( F_13 ( V_4 , V_22 ) )
V_14 = F_13 ( V_4 , V_22 ) ( V_10 , V_4 ) ;
F_4 ( V_4 ) ;
F_14 ( & V_12 -> V_23 ) ;
return V_14 ;
}
int F_15 ( const struct V_9 * V_10 , struct V_1 * V_4 )
{
struct V_24 V_25 = F_16 ( V_26 , NULL ) ;
struct V_11 * V_12 ;
int V_14 , V_27 ;
V_28 ;
F_17 ( V_4 != NULL ) ;
F_17 ( V_4 != V_29 ) ;
V_12 = V_4 -> V_13 ;
F_17 ( V_12 != NULL ) ;
F_17 ( V_12 != V_29 ) ;
V_27 = V_4 -> V_17 ;
F_17 ( F_18 ( & V_4 -> V_6 ) < V_30 ) ;
F_17 ( F_18 ( & V_4 -> V_6 ) > 1 ) ;
F_19 ( V_4 ) ;
V_14 = F_8 ( V_10 , V_4 ) ;
if ( V_14 )
F_20 ( L_2 ,
V_14 , V_4 ) ;
F_21 ( V_12 -> V_23 ,
F_22 ( V_12 , V_27 ) , & V_25 ) ;
RETURN ( V_14 ) ;
}
int F_23 ( const struct V_9 * V_10 , struct V_2 * V_3 ,
struct V_11 * V_12 , int V_31 ,
struct V_2 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_4 ;
int V_14 = 0 ;
V_28 ;
if ( V_31 < 0 || V_31 >= V_35 )
RETURN ( - V_36 ) ;
F_17 ( V_12 != NULL ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
RETURN ( - V_37 ) ;
V_4 -> V_5 = V_3 ;
V_4 -> V_13 = V_12 ;
V_4 -> V_17 = V_31 ;
V_4 -> V_38 = V_34 ;
F_24 ( & V_4 -> V_39 ) ;
V_4 -> V_7 = F_25 ( V_32 -> V_40 ) ;
V_4 -> V_41 = V_42 ;
V_14 = F_26 ( V_12 , V_4 , V_31 ) ;
if ( V_14 ) {
F_4 ( V_4 ) ;
if ( V_14 == - V_43 ) {
V_4 = F_27 ( V_12 , V_31 ) ;
if ( V_4 ) {
F_28 ( V_44 , L_3 ,
V_3 -> V_45 , V_31 ) ;
F_17 ( V_4 -> V_13 == V_12 ) ;
F_17 ( V_4 -> V_5 == V_3 ) ;
F_17 ( V_4 -> V_7 == V_32 -> V_40 ) ;
F_17 ( V_4 -> V_38 == V_34 ) ;
F_19 ( V_4 ) ;
}
V_14 = 0 ;
}
RETURN ( V_14 ) ;
}
if ( V_34 -> V_46 ) {
if ( F_29 ( V_47 ) )
V_14 = - V_48 ;
else
V_14 = V_34 -> V_46 ( V_10 , V_3 , V_12 , V_31 , V_32 ) ;
}
if ( V_14 ) {
F_20 ( L_4 ,
V_3 -> V_45 , V_31 , V_34 -> V_46 , V_14 ) ;
F_30 ( V_12 , V_31 ) ;
F_4 ( V_4 ) ;
} else {
F_28 ( V_44 , L_5 ,
V_3 -> V_45 , V_31 ) ;
V_4 -> V_41 &= ~ V_42 ;
}
RETURN ( V_14 ) ;
}
int F_31 ( struct V_1 * V_4 , struct V_49 * exp , int V_50 )
{
int V_14 = 0 ;
V_28 ;
if ( ! V_4 )
RETURN ( 0 ) ;
if ( F_13 ( V_4 , V_51 ) )
V_14 = F_13 ( V_4 , V_51 ) ( V_4 , exp , V_50 ) ;
RETURN ( V_14 ) ;
}
int F_32 ( const struct V_9 * V_10 , struct V_1 * V_4 ,
struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_57 , int V_58 )
{
int V_59 , V_14 ;
V_28 ;
if ( ! V_4 ) {
F_20 ( L_6 ) ;
RETURN ( - V_60 ) ;
}
if ( V_4 -> V_41 & V_42 )
RETURN ( - V_61 ) ;
F_33 ( V_4 , V_62 , - V_48 ) ;
V_59 = F_34 ( V_63 ) ;
if ( ! V_59 )
F_35 ( V_63 ) ;
V_14 = F_13 ( V_4 , V_62 ) ( V_10 , V_4 , V_53 , V_55 , V_57 ,
V_58 ) ;
if ( ! V_59 )
F_36 ( V_63 ) ;
RETURN ( V_14 ) ;
}
int F_37 ( const struct V_9 * V_10 , struct V_1 * V_4 ,
struct V_54 * V_55 , int V_64 ,
struct V_56 * V_65 , int V_50 )
{
int V_14 ;
V_28 ;
if ( ! V_4 ) {
F_20 ( L_6 ) ;
RETURN ( - V_60 ) ;
}
F_33 ( V_4 , V_66 , - V_48 ) ;
V_14 = F_13 ( V_4 , V_66 ) ( V_10 , V_4 , V_55 , V_64 , V_65 , V_50 ) ;
RETURN ( V_14 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_11 * V_12 ,
struct V_2 * V_32 , int * V_31 )
{
int V_14 ;
V_28 ;
F_39 ( V_3 , V_67 , 0 ) ;
F_40 ( V_3 , V_67 ) ;
V_14 = F_41 ( V_3 , V_67 ) ( V_3 , V_12 , V_32 , V_31 ) ;
RETURN ( V_14 ) ;
}
int F_42 ( struct V_2 * V_3 , int V_64 )
{
int V_14 ;
V_28 ;
F_39 ( V_3 , V_68 , 0 ) ;
F_40 ( V_3 , V_68 ) ;
V_14 = F_41 ( V_3 , V_68 ) ( V_3 , V_64 ) ;
RETURN ( V_14 ) ;
}
int F_43 ( void )
{
F_44 ( & V_69 , NULL ) ;
F_45 ( & V_69 ) ;
return 0 ;
}
void F_46 ( void )
{
F_47 ( & V_69 ) ;
}
