static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = V_6 -> V_14 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_6 -> V_14 ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_17 = 1 ;
V_2 -> V_18 = V_19 + 2 * V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = V_22 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = 0 ;
}
static void F_5 ( struct V_3 * V_4 , T_1 V_28 , T_1 V_29 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
T_1 V_30 ;
if ( ! F_6 ( V_4 ) )
return;
if ( ! V_2 -> V_17 )
return;
if ( F_7 ( V_6 ) ) {
V_29 = F_8 ( V_6 , V_29 ) ;
if ( ! V_29 )
return;
}
if ( V_2 -> V_27 < 0 ) {
V_30 = V_6 -> V_31 << - V_2 -> V_27 ;
F_9 ( V_6 , V_30 , V_29 ) ;
} else {
V_30 = F_10 ( 4U , V_6 -> V_31 >> V_2 -> V_27 ) ;
F_9 ( V_6 , V_30 , V_29 ) ;
}
}
static T_1 F_11 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
V_2 -> V_8 = V_6 -> V_31 ;
return F_10 ( ( V_6 -> V_31 * V_32 ) >> 10 , 2U ) ;
}
static T_1 F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
return F_10 ( F_2 ( V_4 ) -> V_31 , V_2 -> V_8 ) ;
}
static void F_13 ( struct V_3 * V_4 , T_2 V_33 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_33 == V_34 && V_2 -> V_7 ) {
F_1 ( V_2 , V_4 ) ;
} else if ( V_33 == V_35 || V_33 == V_36 ||
V_33 == V_37 ) {
V_2 -> V_7 = 1 ;
V_2 -> V_17 = 0 ;
if ( V_33 == V_35 ) {
if ( V_2 -> V_27 > 0 )
V_2 -> V_27 = 0 ;
if ( V_38 > 0 &&
V_2 -> V_27 > - 8 )
V_2 -> V_27 -- ;
}
}
}
static void F_14 ( struct V_3 * V_4 , const struct V_39 * V_40 )
{
const struct V_41 * V_42 = F_15 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned long V_43 = V_19 ;
T_3 V_44 = 0 ;
T_1 V_45 , V_46 , V_47 ;
T_1 V_48 ;
T_1 V_49 = 0 ;
if ( V_40 -> V_50 < 0 )
return;
if ( V_42 -> V_51 != V_34 &&
V_42 -> V_51 != V_52 )
return;
if ( V_2 -> V_26 && V_6 -> V_31 >= V_24 ) {
V_2 -> V_26 = 0 ;
V_2 -> V_17 = 0 ;
}
V_49 = V_6 -> V_14 - V_2 -> V_16 ;
V_2 -> V_16 = V_6 -> V_14 ;
if ( V_40 -> V_53 == 0 )
return;
if ( V_54 > 0 ) {
if ( V_2 -> V_11 > 0 ) {
V_48 = ( ( ( V_55 ) V_40 -> V_50 ) * V_54 +
( ( V_55 ) V_2 -> V_11 )
* ( 256 - V_54 ) ) >> 8 ;
} else {
V_48 = V_40 -> V_50 ;
V_2 -> V_21 = V_48 << 1 ;
}
V_2 -> V_11 = V_48 ;
} else {
V_48 = V_40 -> V_50 ;
}
V_44 = ( ( V_55 ) V_40 -> V_53 ) * 8000000 ;
V_45 = ( T_1 ) F_16 ( V_44 , ( V_55 ) ( V_48 * 100 ) ) ;
if ( V_2 -> V_12 < V_45 )
V_2 -> V_12 = V_45 ;
if ( V_2 -> V_15 < 255 )
V_2 -> V_15 ++ ;
if ( V_48 < V_2 -> V_21 )
V_2 -> V_21 = V_48 ;
if ( V_48 < V_2 -> V_23 )
V_2 -> V_23 = V_48 ;
if ( F_17 ( V_43 , V_2 -> V_18 ) ) {
unsigned char rand ;
V_2 -> V_21 = V_2 -> V_23 ;
V_2 -> V_23 = V_22 ;
F_18 ( & rand , 1 ) ;
V_2 -> V_18 =
V_43 + ( ( V_56 * ( 384 + rand ) * V_20 ) >> 9 ) ;
V_2 -> V_24 = F_10 ( V_2 -> V_24 / 2 , V_25 ) ;
}
if ( F_19 ( V_2 -> V_13 , V_6 -> V_14 ) ) {
V_2 -> V_13 = V_6 -> V_57 ;
if ( V_2 -> V_10 < 0xff )
V_2 -> V_10 ++ ;
if ( V_2 -> V_15 == 1 &&
V_49 >= ( V_2 -> V_24 - 1 ) * V_6 -> V_58 &&
V_2 -> V_24 < ( V_59 + 1 ) ) {
V_2 -> V_24 = F_20 ( V_2 -> V_24
+ V_60 ,
V_59 + 1 ) ;
V_2 -> V_13 = V_6 -> V_57 +
V_2 -> V_24 * V_6 -> V_58 ;
V_2 -> V_15 = 0 ;
V_2 -> V_17 = 1 ;
return;
}
V_47 = ( T_1 )
F_16 ( ( ( V_55 ) V_2 -> V_12 ) * V_2 -> V_21 ,
( V_55 ) ( 80000 * V_6 -> V_58 ) ) ;
V_46 = V_47 + V_61 ;
if ( V_6 -> V_31 > V_46 ) {
if ( V_2 -> V_10 < V_62 ) {
return;
} else if ( V_6 -> V_63 == V_64 ) {
if ( V_2 -> V_15 <
V_65 )
return;
} else if ( V_2 -> V_15 <
V_66 ) {
if ( V_2 -> V_17 &&
V_2 -> V_10 > V_67 )
V_2 -> V_17 = 0 ;
return;
}
V_2 -> V_17 = 0 ;
V_6 -> V_63 =
( V_68 * V_46 ) >> 3 ;
if ( V_6 -> V_31 - V_46 > 2 ) {
int V_69 ;
V_69 = F_10 ( 2U , ( ( V_6 -> V_31 - V_46 ) *
V_70 ) >> 7 ) ;
V_6 -> V_31 -= V_69 ;
} else if ( V_70 > 0 ) {
V_6 -> V_31 = V_46 ;
}
if ( V_2 -> V_27 > 0 )
V_2 -> V_27 = 0 ;
V_2 -> V_9 = 0 ;
} else if ( V_6 -> V_31 <= V_46 - V_71 ) {
if ( V_2 -> V_15 < V_72 )
return;
V_2 -> V_17 = 1 ;
V_2 -> V_9 ++ ;
if ( V_2 -> V_27 < 0 &&
V_38 > 0 &&
V_2 -> V_9 > V_38 ) {
V_2 -> V_27 ++ ;
V_2 -> V_9 = 0 ;
} else if ( V_2 -> V_27 >= 0 &&
V_73 > 0 &&
V_2 -> V_9 >
V_73 ) {
V_2 -> V_27 ++ ;
V_2 -> V_9 = 0 ;
}
} else {
return;
}
V_2 -> V_15 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_12 = 0 ;
if ( V_6 -> V_31 < V_24 )
V_6 -> V_31 = V_24 ;
}
}
static T_4 F_21 ( struct V_3 * V_4 , T_1 V_74 , int * V_75 ,
union V_76 * V_77 )
{
const struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_74 & ( 1 << ( V_78 - 1 ) ) ) {
V_77 -> V_79 . V_80 = 1 ;
V_77 -> V_79 . V_81 = V_2 -> V_10 ;
V_77 -> V_79 . V_82 = V_2 -> V_11 ;
V_77 -> V_79 . V_83 = V_2 -> V_21 ;
* V_75 = V_78 ;
return sizeof( struct V_84 ) ;
}
return 0 ;
}
static int T_5 F_22 ( void )
{
F_23 ( sizeof( struct V_1 ) > V_85 ) ;
return F_24 ( & V_1 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_1 ) ;
}
