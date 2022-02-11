void *
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
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
memcpy ( & V_7 -> V_4 , V_4 , sizeof( union V_3 ) ) ;
V_9 = (struct V_8 * ) & V_7 -> V_4 . V_14 . V_9 ;
V_13 = (struct V_12 * ) & V_7 -> V_4 . V_14 . V_13 ;
V_11 = (struct V_10 * ) & V_7 -> V_4 . V_14 . V_11 ;
V_9 -> V_15 = 40 ;
V_11 -> V_16 = 1 ;
V_13 -> V_17 = V_2 -> V_17 ;
V_13 -> V_18 = V_5 ;
* V_7 -> V_19 = V_20 ;
V_7 -> V_4 . V_14 . V_21 = V_7 -> V_22 ;
V_7 -> V_23 = 1000 ;
V_7 -> V_24 = V_25 + V_7 -> V_23 ;
return V_7 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
T_1 V_28 )
{
int V_29 ;
V_29 = ! V_28 ;
return F_4 ( V_2 , V_27 -> V_30 , V_29 , & V_27 -> V_4 ,
V_27 -> V_31 , V_27 -> V_32 ,
V_27 -> V_33 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_34 ,
void * V_35 )
{
struct V_6 * V_7 = (struct V_6 * ) V_35 ;
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) V_7 -> V_38 ;
if ( ! V_34 && V_37 -> V_39 )
V_37 -> V_39 ( V_37 ) ;
F_6 ( V_2 , V_7 ) ;
}
static inline struct V_6
* F_7 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_6 * V_7 = NULL ;
T_2 * V_40 ;
T_1 V_5 ;
T_1 V_41 = 0 , V_32 = 0 ;
V_41 = ( T_1 ) ( V_37 -> V_42 . V_43 . V_44 * 8 ) ;
V_32 = V_45 + V_41 ;
V_5 = ( V_37 -> V_23 ) ? 16 : 0 ;
V_7 = (struct V_6 * )
F_2 ( V_2 , V_32 , V_5 ,
sizeof( struct V_36 ) ) ;
if ( ! V_7 )
return NULL ;
memcpy ( V_7 -> V_38 , V_37 , sizeof( struct V_36 ) ) ;
V_40 = ( T_2 * ) V_7 -> V_46 ;
memcpy ( V_40 , & V_37 -> V_42 , V_45 ) ;
F_8 ( ( V_47 * ) V_40 , ( V_45 >> 3 ) ) ;
if ( V_41 ) {
memcpy ( V_40 + V_45 , V_37 -> V_48 , V_41 ) ;
}
V_7 -> V_49 = ( T_1 ) V_37 -> V_49 ;
F_9 ( V_2 , V_7 , V_50 , V_51 ,
0 , 0 , 0 ) ;
V_7 -> V_52 = F_5 ;
V_7 -> V_53 = V_7 ;
V_7 -> V_23 = V_37 -> V_23 ;
return V_7 ;
}
int
F_10 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_54 ;
struct V_6 * V_7 = NULL ;
F_11 ( & V_2 -> V_55 ) ;
if ( ( V_2 -> V_56 == V_57 ) &&
( V_37 -> V_42 . V_43 . V_4 != V_58 ) ) {
F_12 ( & V_2 -> V_55 ) ;
F_13 ( & V_2 -> V_59 -> V_60 ,
L_1 ,
V_61 , V_37 -> V_42 . V_43 . V_4 ) ;
return - 1 ;
}
V_7 = F_7 ( V_2 , V_37 ) ;
if ( ! V_7 ) {
F_13 ( & V_2 -> V_59 -> V_60 , L_2 ,
V_61 ) ;
F_12 ( & V_2 -> V_55 ) ;
return - 1 ;
}
V_54 = F_14 ( V_2 , V_7 ) ;
if ( V_54 == V_62 ) {
F_6 ( V_2 , V_7 ) ;
F_13 ( & V_2 -> V_59 -> V_60 , L_3 ,
V_61 , V_37 -> V_42 . V_43 . V_4 , V_54 ) ;
F_12 ( & V_2 -> V_55 ) ;
return - 1 ;
}
F_12 ( & V_2 -> V_55 ) ;
return V_54 ;
}
