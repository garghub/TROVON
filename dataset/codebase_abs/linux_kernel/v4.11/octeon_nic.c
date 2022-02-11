void *
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_7 = (struct V_6 * )
F_2 ( V_2 , 0 , V_5 , 0 ) ;
if ( ! V_7 )
return NULL ;
memcpy ( & V_7 -> V_4 , V_4 , sizeof( union V_3 ) ) ;
if ( F_3 ( V_2 ) || F_4 ( V_2 ) ) {
V_9 = (struct V_8 * ) & V_7 -> V_4 . V_16 . V_9 ;
V_15 = (struct V_14 * ) & V_7 -> V_4 . V_16 . V_15 ;
V_13 = (struct V_12 * ) & V_7 -> V_4 . V_16 . V_13 ;
V_9 -> V_17 = V_18 ;
} else {
V_11 = (struct V_10 * ) & V_7 -> V_4 . V_19 . V_11 ;
V_15 = (struct V_14 * ) & V_7 -> V_4 . V_19 . V_15 ;
V_13 = (struct V_12 * ) & V_7 -> V_4 . V_19 . V_13 ;
V_11 -> V_17 = V_20 ;
}
V_13 -> V_21 = 1 ;
V_15 -> V_22 = V_2 -> V_22 ;
V_15 -> V_23 = V_5 ;
* V_7 -> V_24 = V_25 ;
if ( F_3 ( V_2 ) || F_4 ( V_2 ) )
V_7 -> V_4 . V_16 . V_26 = V_7 -> V_27 ;
else
V_7 -> V_4 . V_19 . V_26 = V_7 -> V_27 ;
V_7 -> V_28 = 1000 ;
V_7 -> V_29 = V_30 + V_7 -> V_28 ;
return V_7 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_33 = 1 ;
return F_6 ( V_2 , V_32 -> V_34 , V_33 , & V_32 -> V_4 ,
V_32 -> V_35 , V_32 -> V_36 ,
V_32 -> V_37 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_38 ,
void * V_39 )
{
struct V_6 * V_7 = (struct V_6 * ) V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_7 -> V_42 ;
if ( ! V_38 && V_41 -> V_43 )
V_41 -> V_43 ( V_41 ) ;
F_8 ( V_2 , V_7 ) ;
}
static inline struct V_6
* F_9 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_6 * V_7 = NULL ;
T_2 * V_44 ;
T_1 V_5 ;
T_1 V_45 = 0 , V_36 = 0 ;
V_45 = ( T_1 ) ( V_41 -> V_46 . V_47 . V_48 * 8 ) ;
V_36 = V_49 + V_45 ;
V_5 = ( V_41 -> V_28 ) ? 16 : 0 ;
V_7 = (struct V_6 * )
F_2 ( V_2 , V_36 , V_5 ,
sizeof( struct V_40 ) ) ;
if ( ! V_7 )
return NULL ;
memcpy ( V_7 -> V_42 , V_41 , sizeof( struct V_40 ) ) ;
V_44 = ( T_2 * ) V_7 -> V_50 ;
memcpy ( V_44 , & V_41 -> V_46 , V_49 ) ;
F_10 ( ( V_51 * ) V_44 , ( V_49 >> 3 ) ) ;
if ( V_45 ) {
memcpy ( V_44 + V_49 , V_41 -> V_52 , V_45 ) ;
}
V_7 -> V_53 = ( T_1 ) V_41 -> V_53 ;
F_11 ( V_2 , V_7 , V_54 , V_55 ,
0 , 0 , 0 ) ;
V_7 -> V_56 = F_7 ;
V_7 -> V_57 = V_7 ;
V_7 -> V_28 = V_41 -> V_28 ;
return V_7 ;
}
int
F_12 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
int V_58 ;
struct V_6 * V_7 = NULL ;
F_13 ( & V_2 -> V_59 ) ;
if ( ( V_2 -> V_60 == V_61 ) &&
( V_41 -> V_46 . V_47 . V_4 != V_62 ) ) {
F_14 ( & V_2 -> V_59 ) ;
F_15 ( & V_2 -> V_63 -> V_64 ,
L_1 ,
V_65 , V_41 -> V_46 . V_47 . V_4 ) ;
return - 1 ;
}
V_7 = F_9 ( V_2 , V_41 ) ;
if ( ! V_7 ) {
F_15 ( & V_2 -> V_63 -> V_64 , L_2 ,
V_65 ) ;
F_14 ( & V_2 -> V_59 ) ;
return - 1 ;
}
V_58 = F_16 ( V_2 , V_7 ) ;
if ( V_58 == V_66 ) {
F_8 ( V_2 , V_7 ) ;
F_15 ( & V_2 -> V_63 -> V_64 , L_3 ,
V_65 , V_2 -> V_67 , V_41 -> V_46 . V_47 . V_4 , V_58 ) ;
F_14 ( & V_2 -> V_59 ) ;
return - 1 ;
}
F_14 ( & V_2 -> V_59 ) ;
return V_58 ;
}
