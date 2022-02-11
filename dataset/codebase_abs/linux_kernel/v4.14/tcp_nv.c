static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_6 -> V_13 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = V_6 -> V_13 ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_16 = 1 ;
V_2 -> V_17 = V_18 + 2 * V_19 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_21 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = 0 ;
V_2 -> V_26 = 0 ;
}
static void F_5 ( struct V_3 * V_4 , T_1 V_27 , T_1 V_28 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
T_1 V_29 ;
if ( ! F_6 ( V_4 ) )
return;
if ( ! V_2 -> V_16 )
return;
if ( F_7 ( V_6 ) ) {
V_28 = F_8 ( V_6 , V_28 ) ;
if ( ! V_28 )
return;
}
if ( V_2 -> V_26 < 0 ) {
V_29 = V_6 -> V_30 << - V_2 -> V_26 ;
F_9 ( V_6 , V_29 , V_28 ) ;
} else {
V_29 = F_10 ( 4U , V_6 -> V_30 >> V_2 -> V_26 ) ;
F_9 ( V_6 , V_29 , V_28 ) ;
}
}
static T_1 F_11 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_10 ( ( V_6 -> V_30 * V_31 ) >> 10 , 2U ) ;
}
static void F_12 ( struct V_3 * V_4 , T_2 V_32 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_32 == V_33 && V_2 -> V_7 ) {
F_1 ( V_2 , V_4 ) ;
} else if ( V_32 == V_34 || V_32 == V_35 ||
V_32 == V_36 ) {
V_2 -> V_7 = 1 ;
V_2 -> V_16 = 0 ;
if ( V_32 == V_34 ) {
if ( V_2 -> V_26 > 0 )
V_2 -> V_26 = 0 ;
if ( V_37 > 0 &&
V_2 -> V_26 > - 8 )
V_2 -> V_26 -- ;
}
}
}
static void F_13 ( struct V_3 * V_4 , const struct V_38 * V_39 )
{
const struct V_40 * V_41 = F_14 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned long V_42 = V_18 ;
T_3 V_43 = 0 ;
T_1 V_44 , V_45 , V_46 ;
T_1 V_47 ;
T_1 V_48 = 0 ;
if ( V_39 -> V_49 < 0 )
return;
if ( V_41 -> V_50 != V_33 &&
V_41 -> V_50 != V_51 )
return;
if ( V_2 -> V_25 && V_6 -> V_30 >= V_23 ) {
V_2 -> V_25 = 0 ;
V_2 -> V_16 = 0 ;
}
V_48 = V_6 -> V_13 - V_2 -> V_15 ;
V_2 -> V_15 = V_6 -> V_13 ;
if ( V_39 -> V_52 == 0 )
return;
if ( V_53 > 0 ) {
if ( V_2 -> V_10 > 0 ) {
V_47 = ( ( ( V_54 ) V_39 -> V_49 ) * V_53 +
( ( V_54 ) V_2 -> V_10 )
* ( 256 - V_53 ) ) >> 8 ;
} else {
V_47 = V_39 -> V_49 ;
V_2 -> V_20 = V_47 << 1 ;
}
V_2 -> V_10 = V_47 ;
} else {
V_47 = V_39 -> V_49 ;
}
V_43 = ( ( V_54 ) V_39 -> V_52 ) * 8000000 ;
V_44 = ( T_1 ) F_15 ( V_43 , ( V_54 ) ( V_47 ? : 1 ) * 100 ) ;
if ( V_2 -> V_11 < V_44 )
V_2 -> V_11 = V_44 ;
if ( V_2 -> V_14 < 255 )
V_2 -> V_14 ++ ;
if ( V_47 < V_2 -> V_20 )
V_2 -> V_20 = V_47 ;
if ( V_47 < V_2 -> V_22 )
V_2 -> V_22 = V_47 ;
if ( F_16 ( V_42 , V_2 -> V_17 ) ) {
unsigned char rand ;
V_2 -> V_20 = V_2 -> V_22 ;
V_2 -> V_22 = V_21 ;
F_17 ( & rand , 1 ) ;
V_2 -> V_17 =
V_42 + ( ( V_55 * ( 384 + rand ) * V_19 ) >> 9 ) ;
V_2 -> V_23 = F_10 ( V_2 -> V_23 / 2 , V_24 ) ;
}
if ( F_18 ( V_2 -> V_12 , V_6 -> V_13 ) ) {
V_2 -> V_12 = V_6 -> V_56 ;
if ( V_2 -> V_9 < 0xff )
V_2 -> V_9 ++ ;
if ( V_2 -> V_14 == 1 &&
V_48 >= ( V_2 -> V_23 - 1 ) * V_6 -> V_57 &&
V_2 -> V_23 < ( V_58 + 1 ) ) {
V_2 -> V_23 = F_19 ( V_2 -> V_23
+ V_59 ,
V_58 + 1 ) ;
V_2 -> V_12 = V_6 -> V_56 +
V_2 -> V_23 * V_6 -> V_57 ;
V_2 -> V_14 = 0 ;
V_2 -> V_16 = 1 ;
return;
}
V_46 = ( T_1 )
F_15 ( ( ( V_54 ) V_2 -> V_11 ) * V_2 -> V_20 ,
( V_54 ) ( 80000 * V_6 -> V_57 ) ) ;
V_45 = V_46 + V_60 ;
if ( V_6 -> V_30 > V_45 ) {
if ( V_2 -> V_9 < V_61 ) {
return;
} else if ( V_6 -> V_62 == V_63 ) {
if ( V_2 -> V_14 <
V_64 )
return;
} else if ( V_2 -> V_14 <
V_65 ) {
if ( V_2 -> V_16 &&
V_2 -> V_9 > V_66 )
V_2 -> V_16 = 0 ;
return;
}
V_2 -> V_16 = 0 ;
V_6 -> V_62 =
( V_67 * V_45 ) >> 3 ;
if ( V_6 -> V_30 - V_45 > 2 ) {
int V_68 ;
V_68 = F_10 ( 2U , ( ( V_6 -> V_30 - V_45 ) *
V_69 ) >> 7 ) ;
V_6 -> V_30 -= V_68 ;
} else if ( V_69 > 0 ) {
V_6 -> V_30 = V_45 ;
}
if ( V_2 -> V_26 > 0 )
V_2 -> V_26 = 0 ;
V_2 -> V_8 = 0 ;
} else if ( V_6 -> V_30 <= V_45 - V_70 ) {
if ( V_2 -> V_14 < V_71 )
return;
V_2 -> V_16 = 1 ;
V_2 -> V_8 ++ ;
if ( V_2 -> V_26 < 0 &&
V_37 > 0 &&
V_2 -> V_8 > V_37 ) {
V_2 -> V_26 ++ ;
V_2 -> V_8 = 0 ;
} else if ( V_2 -> V_26 >= 0 &&
V_72 > 0 &&
V_2 -> V_8 >
V_72 ) {
V_2 -> V_26 ++ ;
V_2 -> V_8 = 0 ;
}
} else {
return;
}
V_2 -> V_14 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_11 = 0 ;
if ( V_6 -> V_30 < V_23 )
V_6 -> V_30 = V_23 ;
}
}
static T_4 F_20 ( struct V_3 * V_4 , T_1 V_73 , int * V_74 ,
union V_75 * V_76 )
{
const struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_73 & ( 1 << ( V_77 - 1 ) ) ) {
V_76 -> V_78 . V_79 = 1 ;
V_76 -> V_78 . V_80 = V_2 -> V_9 ;
V_76 -> V_78 . V_81 = V_2 -> V_10 ;
V_76 -> V_78 . V_82 = V_2 -> V_20 ;
* V_74 = V_77 ;
return sizeof( struct V_83 ) ;
}
return 0 ;
}
static int T_5 F_21 ( void )
{
F_22 ( sizeof( struct V_1 ) > V_84 ) ;
return F_23 ( & V_1 ) ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_1 ) ;
}
