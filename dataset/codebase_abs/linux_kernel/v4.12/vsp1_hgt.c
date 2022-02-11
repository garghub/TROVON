static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 . V_6 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 ,
T_1 V_3 , T_1 V_9 )
{
F_4 ( V_8 , V_3 , V_9 ) ;
}
void F_5 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = F_6 ( & V_5 -> V_11 ) ;
struct V_12 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
T_1 * V_9 ;
V_13 = F_7 ( & V_2 -> V_4 ) ;
if ( ! V_13 )
return;
V_9 = V_13 -> V_16 ;
* V_9 ++ = F_1 ( V_2 , V_17 ) ;
* V_9 ++ = F_1 ( V_2 , V_18 ) ;
for ( V_14 = 0 ; V_14 < 6 ; ++ V_14 )
for ( V_15 = 0 ; V_15 < 32 ; ++ V_15 )
* V_9 ++ = F_1 ( V_2 , F_8 ( V_14 , V_15 ) ) ;
F_9 ( & V_2 -> V_4 , V_13 , V_19 ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
const T_2 * V_22 = V_21 -> V_23 . V_24 ;
unsigned int V_25 ;
for ( V_25 = 1 ; V_25 < ( V_26 * 2 ) - 1 ; ++ V_25 ) {
if ( V_22 [ V_25 ] > V_22 [ V_25 + 1 ] )
return - V_27 ;
}
if ( V_22 [ 0 ] > V_22 [ 1 ] && V_22 [ 11 ] > V_22 [ 0 ] )
return - V_27 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_21 -> V_28 , struct V_1 ,
V_29 ) ;
memcpy ( V_2 -> V_30 , V_21 -> V_23 . V_24 , sizeof( V_2 -> V_30 ) ) ;
return 0 ;
}
static void F_13 ( struct V_10 * V_5 ,
struct V_31 * V_32 ,
struct V_7 * V_8 ,
enum V_33 V_34 )
{
struct V_1 * V_2 = F_6 ( & V_5 -> V_11 ) ;
struct V_35 * V_36 ;
struct V_35 * V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
T_2 V_40 ;
T_2 V_41 ;
unsigned int V_25 ;
if ( V_34 != V_42 )
return;
V_37 = F_14 ( V_5 , V_5 -> V_43 ,
V_44 , V_45 ) ;
V_36 = F_14 ( V_5 , V_5 -> V_43 ,
V_44 ,
V_46 ) ;
F_3 ( V_2 , V_8 , V_47 , V_48 ) ;
F_3 ( V_2 , V_8 , V_49 ,
( V_37 -> V_50 << V_51 ) |
( V_37 -> V_52 << V_53 ) ) ;
F_3 ( V_2 , V_8 , V_54 ,
( V_37 -> V_55 << V_56 ) |
( V_37 -> V_57 << V_58 ) ) ;
F_15 ( V_2 -> V_29 . V_59 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
V_40 = V_2 -> V_30 [ V_25 * 2 + 0 ] ;
V_41 = V_2 -> V_30 [ V_25 * 2 + 1 ] ;
F_3 ( V_2 , V_8 , F_16 ( V_25 ) ,
( V_40 << V_60 ) |
( V_41 << V_61 ) ) ;
}
F_17 ( V_2 -> V_29 . V_59 ) ;
V_38 = V_37 -> V_55 * 2 / V_36 -> V_55 / 3 ;
V_39 = V_37 -> V_57 * 2 / V_36 -> V_57 / 3 ;
F_3 ( V_2 , V_8 , V_62 ,
( V_38 << V_63 ) |
( V_39 << V_64 ) ) ;
}
struct V_1 * F_18 ( struct V_65 * V_6 )
{
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_19 ( V_6 -> V_67 , sizeof( * V_2 ) , V_68 ) ;
if ( V_2 == NULL )
return F_20 ( - V_69 ) ;
F_21 ( & V_2 -> V_29 , 1 ) ;
F_22 ( & V_2 -> V_29 , & V_70 , NULL ) ;
V_2 -> V_4 . V_5 . V_11 . V_71 = & V_2 -> V_29 ;
V_66 = F_23 ( V_6 , & V_2 -> V_4 , V_72 , L_1 ,
& V_73 , V_74 ,
F_24 ( V_74 ) ,
V_19 , V_75 ) ;
if ( V_66 < 0 ) {
F_25 ( & V_2 -> V_4 . V_5 ) ;
return F_20 ( V_66 ) ;
}
F_26 ( & V_2 -> V_29 ) ;
return V_2 ;
}
