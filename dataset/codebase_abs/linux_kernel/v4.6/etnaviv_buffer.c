static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_4 ;
F_2 ( V_2 -> V_5 >= V_2 -> V_6 ) ;
V_4 [ V_2 -> V_5 / 4 ] = V_3 ;
V_2 -> V_5 += 4 ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = V_7 >> V_10 ;
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 8 ) ;
F_1 ( V_2 , V_11 |
F_5 ( 1 ) |
F_6 ( V_9 ) ) ;
F_1 ( V_2 , V_8 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 8 ) ;
F_1 ( V_2 , V_12 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 8 ) ;
F_1 ( V_2 , V_13 | 200 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_14 , T_1 V_15 )
{
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 8 ) ;
F_1 ( V_2 , V_16 |
F_10 ( V_14 ) ) ;
F_1 ( V_2 , V_15 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_18 )
{
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 8 ) ;
F_1 ( V_2 , V_19 ) ;
F_1 ( V_2 , F_12 ( V_17 ) | F_13 ( V_18 ) ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
F_3 ( V_2 , V_20 ,
F_15 ( V_17 ) |
F_16 ( V_18 ) ) ;
}
static void F_17 ( struct V_21 * V_22 ,
struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_24 = 0 ;
if ( V_22 -> V_25 == V_26 )
V_24 = V_27 ;
else if ( V_22 -> V_25 == V_28 )
V_24 = V_29 | V_30 ;
F_3 ( V_2 , V_31 , V_24 ) ;
F_14 ( V_2 , V_32 , V_33 ) ;
F_11 ( V_2 , V_32 , V_33 ) ;
F_3 ( V_2 , V_34 ,
F_18 ( V_23 ) ) ;
}
static T_1 F_19 ( struct V_21 * V_22 , struct V_1 * V_35 )
{
return V_35 -> V_36 - V_22 -> V_37 ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_1 * V_35 , T_1 V_38 , T_1 V_39 )
{
T_1 V_6 = V_35 -> V_6 ;
T_1 * V_40 = V_35 -> V_4 + V_38 ;
F_21 ( V_22 -> V_41 , L_1 ,
V_40 , F_19 ( V_22 , V_35 ) + V_38 , V_6 - V_39 * 4 - V_38 ) ;
F_22 ( V_42 , L_2 , V_43 , 16 , 4 ,
V_40 , V_39 * 4 , 0 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_44 , T_1 V_45 , T_1 V_46 )
{
T_1 * V_47 = V_2 -> V_4 + V_44 ;
V_47 [ 1 ] = V_46 ;
F_24 () ;
V_47 [ 0 ] = V_45 ;
F_24 () ;
}
static T_1 F_25 ( struct V_21 * V_22 ,
struct V_1 * V_2 , unsigned int V_48 )
{
if ( V_2 -> V_5 + V_48 * sizeof( V_49 ) > V_2 -> V_6 )
V_2 -> V_5 = 0 ;
return F_19 ( V_22 , V_2 ) + V_2 -> V_5 ;
}
T_2 F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
V_2 -> V_5 = 0 ;
F_8 ( V_2 ) ;
F_9 ( V_2 , 2 , F_19 ( V_22 , V_2 ) + V_2 -> V_5 - 4 ) ;
return V_2 -> V_5 / 8 ;
}
void F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_50 = V_2 -> V_5 - 16 ;
T_1 V_51 , V_24 = 0 ;
if ( V_22 -> V_25 == V_26 )
V_24 = V_27 ;
else if ( V_22 -> V_25 == V_28 )
V_24 = V_29 |
V_30 |
V_52 |
V_53 |
V_54 ;
if ( V_24 ) {
unsigned int V_55 = 7 ;
V_51 = F_25 ( V_22 , V_2 , V_55 ) ;
F_14 ( V_2 , V_32 , V_33 ) ;
F_11 ( V_2 , V_32 , V_33 ) ;
F_3 ( V_2 , V_31 , V_24 ) ;
if ( V_22 -> V_25 == V_28 )
F_3 ( V_2 , V_56 ,
V_57 ) ;
F_14 ( V_2 , V_32 , V_33 ) ;
F_11 ( V_2 , V_32 , V_33 ) ;
F_7 ( V_2 ) ;
F_23 ( V_2 , V_50 ,
V_16 |
F_10 ( V_55 ) ,
V_51 ) ;
} else {
F_23 ( V_2 , V_50 ,
V_12 , 0 ) ;
}
}
void F_28 ( struct V_21 * V_22 , unsigned int V_58 ,
struct V_1 * V_59 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_50 = V_2 -> V_5 - 16 ;
T_1 V_60 , V_61 ;
T_1 V_51 , V_62 ;
if ( V_63 & V_64 )
F_20 ( V_22 , V_2 , 0 , 0x50 ) ;
V_51 = F_19 ( V_22 , V_59 ) ;
V_62 = V_59 -> V_6 / 8 ;
if ( V_22 -> V_65 -> V_66 || V_22 -> V_67 ) {
T_1 V_68 , V_69 ;
V_69 = 1 ;
if ( V_22 -> V_65 -> V_66 )
V_69 += 1 ;
if ( V_22 -> V_67 )
V_69 += 4 ;
V_68 = F_25 ( V_22 , V_2 , V_69 ) ;
if ( V_22 -> V_65 -> V_66 ) {
F_3 ( V_2 , V_70 ,
V_71 |
V_72 |
V_73 |
V_74 |
V_75 ) ;
V_22 -> V_65 -> V_66 = false ;
}
if ( V_22 -> V_67 ) {
F_17 ( V_22 , V_2 , V_59 -> V_25 ) ;
V_22 -> V_25 = V_59 -> V_25 ;
V_22 -> V_67 = false ;
}
F_9 ( V_2 , V_62 , V_51 ) ;
V_51 = V_68 ;
V_62 = V_69 ;
}
V_61 = 3 ;
V_60 = F_25 ( V_22 , V_2 , V_61 ) ;
F_9 ( V_59 , V_61 , V_60 ) ;
F_3 ( V_2 , V_76 , F_29 ( V_58 ) |
V_77 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 , 2 , V_60 + 8 ) ;
if ( V_63 & V_64 )
F_30 ( L_3 ,
V_60 , F_19 ( V_22 , V_59 ) , V_59 -> V_4 ) ;
if ( V_63 & V_64 ) {
F_22 ( V_42 , L_2 , V_43 , 16 , 4 ,
V_59 -> V_4 , V_59 -> V_6 , 0 ) ;
F_30 ( L_4 , V_2 -> V_4 + V_50 ) ;
F_30 ( L_5 , V_51 ) ;
F_30 ( L_6 , V_60 ) ;
F_30 ( L_7 , V_58 ) ;
}
F_23 ( V_2 , V_50 ,
V_16 |
F_10 ( V_62 ) ,
V_51 ) ;
if ( V_63 & V_64 )
F_20 ( V_22 , V_2 , 0 , 0x50 ) ;
}
