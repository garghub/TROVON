static void F_1 ( struct F_1 * V_1 )
{
T_1 V_2 = sizeof( struct F_1 ) ;
T_2 V_3 ;
V_3 =
F_2 ( V_4 , V_2 >> V_5 ) |
F_2 ( V_6 , V_7 ) ;
V_1 -> V_8 = F_3 ( V_3 ) ;
V_1 -> V_9 = 0 ;
}
static void
F_4 ( struct F_4 * V_10 ,
const struct V_11 * V_12 )
{
T_1 V_2 = sizeof( struct F_4 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
T_2 V_15 ;
T_2 V_16 ;
V_16 =
F_2 ( V_4 , V_2 >> V_5 ) |
F_2 ( V_6 , V_17 ) ;
V_10 -> V_8 = F_3 ( V_16 ) ;
V_10 -> V_9 = 0 ;
V_10 -> V_18 = F_6 ( V_12 ) ;
V_15 =
F_2 ( V_19 , V_14 -> V_20 ) |
F_2 ( V_21 , V_14 -> V_22 ) |
V_23 ;
V_10 -> V_24 = F_3 ( V_15 ) ;
}
static int
F_7 ( struct F_7 * V_25 , const struct V_11 * V_12 ,
struct V_26 * V_27 , bool V_28 ,
struct V_29 * V_30 )
{
T_1 V_2 = sizeof( struct F_7 ) ;
struct V_29 * V_31 ;
T_2 V_32 ;
int V_33 ;
V_32 =
F_2 ( V_4 , V_2 >> V_5 ) |
F_2 ( V_6 , V_34 ) ;
V_25 -> V_8 = F_3 ( V_32 ) ;
V_25 -> V_35 = F_3 ( V_28 ? V_36 : 0 ) ;
V_33 = F_8 ( V_12 ) ;
V_31 = F_9 ( F_10 ( V_30 ) , V_33 ) ;
if ( ! V_31 )
return - V_37 ;
if ( ! F_11 ( V_30 , V_31 ) )
return - V_37 ;
V_25 -> V_38 = F_12 ( F_13 ( V_31 ) ) ;
if ( ! V_25 -> V_38 )
return - V_37 ;
V_27 -> V_39 . V_40 = V_25 -> V_38 ;
return 0 ;
}
static int
F_14 ( const struct V_11 * V_41 ,
struct V_26 * V_42 , int * V_43 ,
struct V_29 * V_44 )
{
struct F_4 * V_45 ;
struct F_1 * V_46 ;
struct F_7 * V_25 ;
int V_47 ;
if ( F_15 ( V_41 ) ) {
V_42 -> V_39 . V_40 = F_12 ( V_48 ) ;
} else if ( F_16 ( V_41 ) ) {
if ( * V_43 + sizeof( struct F_7 ) > V_49 )
return - V_37 ;
V_25 = (struct F_7 * ) & V_42 -> V_50 [ * V_43 ] ;
V_47 = F_7 ( V_25 , V_41 , V_42 , true , V_44 ) ;
if ( V_47 )
return V_47 ;
* V_43 += sizeof( struct F_7 ) ;
} else if ( F_17 ( V_41 ) ) {
if ( * V_43 + sizeof( struct F_7 ) > V_49 )
return - V_37 ;
V_25 = (struct F_7 * ) & V_42 -> V_50 [ * V_43 ] ;
V_47 = F_7 ( V_25 , V_41 , V_42 , false , V_44 ) ;
if ( V_47 )
return V_47 ;
* V_43 += sizeof( struct F_7 ) ;
} else if ( F_18 ( V_41 ) && F_19 ( V_41 ) == V_51 ) {
if ( * V_43 + sizeof( struct F_1 ) > V_49 )
return - V_37 ;
V_46 = (struct F_1 * ) & V_42 -> V_50 [ * V_43 ] ;
V_42 -> V_39 . V_40 = F_12 ( V_52 ) ;
F_1 ( V_46 ) ;
* V_43 += sizeof( struct F_1 ) ;
} else if ( F_18 ( V_41 ) && F_19 ( V_41 ) == V_53 ) {
if ( * V_43 + sizeof( struct F_4 ) > V_49 )
return - V_37 ;
V_45 = (struct F_4 * ) & V_42 -> V_50 [ * V_43 ] ;
V_42 -> V_39 . V_40 = F_12 ( V_54 ) ;
F_4 ( V_45 , V_41 ) ;
* V_43 += sizeof( struct F_4 ) ;
} else {
return - V_37 ;
}
return 0 ;
}
int F_20 ( struct V_55 * V_56 ,
struct V_29 * V_44 ,
struct V_26 * V_27 )
{
int V_57 , V_58 , V_47 ;
const struct V_11 * V_41 ;
F_21 ( V_59 ) ;
memset ( V_27 -> V_50 , 0 , V_49 ) ;
V_27 -> V_39 . V_57 = 0 ;
V_57 = 0 ;
V_58 = 0 ;
F_22 ( V_56 -> V_60 , & V_59 ) ;
F_23 (a, &actions, list) {
V_47 = F_14 ( V_41 , V_27 , & V_57 , V_44 ) ;
if ( V_47 )
return V_47 ;
V_58 ++ ;
}
if ( V_58 > 1 )
V_27 -> V_39 . V_40 = F_12 ( V_54 ) ;
V_27 -> V_39 . V_57 = V_57 ;
return 0 ;
}
