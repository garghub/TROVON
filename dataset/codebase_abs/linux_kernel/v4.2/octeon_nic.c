void *
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_7 = (struct V_6 * )
F_2 ( V_2 , 0 , V_5 , 0 ) ;
if ( ! V_7 )
return NULL ;
memcpy ( & V_7 -> V_4 , V_4 , sizeof( struct V_3 ) ) ;
V_9 = (struct V_8 * ) & V_7 -> V_4 . V_9 ;
V_9 -> V_14 = 40 ;
V_11 = (struct V_10 * ) & V_7 -> V_4 . V_11 ;
V_11 -> V_15 = 1 ;
V_11 -> V_16 = 4 ;
V_13 = (struct V_12 * ) & V_7 -> V_4 . V_13 ;
V_13 -> V_17 = V_2 -> V_17 ;
V_13 -> V_18 = V_5 ;
* V_7 -> V_19 = V_20 ;
V_7 -> V_21 = 1000 ;
V_7 -> V_22 = V_23 + V_7 -> V_21 ;
return V_7 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
T_2 V_26 )
{
int V_27 ;
V_27 = ! V_26 ;
return F_4 ( V_2 , V_25 -> V_28 , V_27 , & V_25 -> V_4 ,
V_25 -> V_29 , V_25 -> V_30 ,
V_25 -> V_31 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_2 V_32 ,
void * V_33 )
{
struct V_6 * V_7 = (struct V_6 * ) V_33 ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_7 -> V_36 ;
if ( ! V_32 && V_35 -> V_37 )
V_35 -> V_37 ( V_35 ) ;
F_6 ( V_2 , V_7 ) ;
}
static inline struct V_6
* F_7 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_38 V_39 )
{
struct V_6 * V_7 = NULL ;
T_3 * V_40 ;
T_1 V_5 ;
T_2 V_41 = 0 , V_30 = 0 ;
V_41 = ( T_2 ) ( V_35 -> V_42 . V_43 . V_44 * 8 ) ;
V_30 = V_45 + V_41 ;
V_5 = ( V_35 -> V_21 ) ? 16 : 0 ;
V_7 = (struct V_6 * )
F_2 ( V_2 , V_30 , V_5 ,
sizeof( struct V_34 ) ) ;
if ( ! V_7 )
return NULL ;
memcpy ( V_7 -> V_36 , V_35 , sizeof( struct V_34 ) ) ;
V_40 = ( T_3 * ) V_7 -> V_46 ;
memcpy ( V_40 , & V_35 -> V_42 , V_45 ) ;
F_8 ( ( V_47 * ) V_40 , ( V_45 >> 3 ) ) ;
if ( V_41 ) {
memcpy ( V_40 + V_45 , V_35 -> V_48 , V_41 ) ;
}
F_9 ( V_2 , V_7 , V_49 , V_50 ,
0 , 0 , 0 ) ;
V_7 -> V_51 = F_5 ;
V_7 -> V_52 = V_7 ;
V_7 -> V_21 = V_35 -> V_21 ;
return V_7 ;
}
int
F_10 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_38 V_39 )
{
int V_53 ;
struct V_6 * V_7 = NULL ;
V_7 = F_7 ( V_2 , V_35 , V_39 ) ;
if ( ! V_7 ) {
F_11 ( & V_2 -> V_54 -> V_55 , L_1 ,
V_56 ) ;
return - 1 ;
}
V_53 = F_12 ( V_2 , V_7 ) ;
if ( V_53 ) {
F_6 ( V_2 , V_7 ) ;
F_11 ( & V_2 -> V_54 -> V_55 , L_2 ,
V_56 , V_53 ) ;
return - 1 ;
}
return V_53 ;
}
