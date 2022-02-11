static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( F_3 ( V_2 -> V_5 + V_3 ) | V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( F_3 ( V_2 -> V_5 + V_3 ) & ~ V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
return ( F_3 ( V_2 -> V_5 + V_3 ) & V_4 ) == V_4 ;
}
static inline void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 , unsigned int V_7 ,
unsigned int V_4 )
{
unsigned int V_8 ;
V_8 = F_3 ( V_2 -> V_5 + V_3 ) ;
V_8 &= ~ V_6 ;
V_8 |= ( V_4 << V_7 ) & V_6 ;
F_2 ( V_8 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_6 ,
unsigned int V_7 )
{
return ( F_3 ( V_2 -> V_5 + V_3 ) & V_6 ) >> V_7 ;
}
static void F_8 ( struct V_1 * V_2 , int V_9 )
{
T_1 V_4 ;
F_6 ( V_2 , V_10 , V_11 ,
V_12 , V_9 ) ;
F_1 ( V_2 , V_10 , V_13 ) ;
F_9 ( V_2 -> V_5 + V_10 , V_4 ,
( V_4 & V_13 ) != V_13 , 4 , 20000 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 . V_17 . V_19 ;
T_1 V_20 , V_21 , V_22 , V_23 , V_24 ;
T_1 V_25 = 0 ;
T_1 V_26 ;
int V_27 ;
F_8 ( V_2 , V_28 ) ;
F_6 ( V_2 , V_29 , 0xff , 0 , ( V_15 -> V_30 << 1 ) | 0x01 ) ;
F_6 ( V_2 , V_10 , V_31 , V_32 ,
0x00 ) ;
F_8 ( V_2 , V_33 ) ;
V_26 = F_7 ( V_2 , V_10 , V_34 , V_35 ) ;
F_11 ( V_17 , L_1 , V_26 ) ;
if ( V_26 != 0x01 ) {
F_12 ( V_17 , L_2 ) ;
return - V_36 ;
}
V_20 = V_15 -> V_37 ;
V_21 = ( V_15 -> V_37 - 1 ) / 8 ;
V_22 = 0 ;
while ( V_20 > 0 ) {
if ( V_21 > 0 ) {
V_23 = 8 ;
V_22 = 0 ;
V_21 -- ;
} else {
V_23 = V_20 ;
V_22 = 1 ;
}
F_6 ( V_2 , V_10 , V_31 ,
V_32 , V_23 - 1 ) ;
F_8 ( V_2 , ( V_22 == 1 ) ?
V_38 :
V_39 ) ;
V_26 = F_7 ( V_2 , V_10 , V_34 ,
V_35 ) ;
V_24 = 0 ;
while ( ( ( V_26 & ( 1 << V_24 ) ) != 0 ) && ( V_24 < 8 ) )
V_24 ++ ;
if ( ( ( V_22 == 1 ) && ( V_24 != ( V_23 - 1 ) ) ) ||
( ( V_22 == 0 ) && ( V_24 != V_23 ) ) ) {
F_12 ( V_17 , L_3 , V_26 ) ;
break;
}
for ( V_27 = V_23 ; V_27 >= 1 ; V_27 -- ) {
int V_7 ;
int V_3 ;
if ( V_27 > 4 ) {
V_3 = V_40 ;
V_7 = ( V_27 - 5 ) * 8 ;
} else {
V_3 = V_29 ;
V_7 = ( V_27 - 1 ) * 8 ;
}
V_15 -> V_41 [ V_25 + V_27 - 1 ] = F_7 ( V_2 , V_3 ,
0xff << V_7 ,
V_7 ) ;
}
V_20 -= V_23 ;
V_25 += V_23 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 . V_17 . V_19 ;
T_1 V_26 ;
F_8 ( V_2 , V_28 ) ;
F_6 ( V_2 , V_29 , V_42 , 0 , V_15 -> V_30 << 1 ) ;
F_6 ( V_2 , V_29 , V_43 , 8 , V_15 -> V_41 [ 0 ] ) ;
F_6 ( V_2 , V_10 , V_31 , V_32 ,
0x1 ) ;
F_8 ( V_2 , V_33 ) ;
V_26 = F_7 ( V_2 , V_10 , V_34 , V_35 ) ;
F_11 ( V_17 , L_4 , V_26 ) ;
if ( V_26 != 0x03 ) {
F_12 ( V_17 , L_2 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_14 ( struct V_45 * V_46 ,
struct V_14 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_46 -> V_49 ;
struct V_16 * V_17 = V_46 -> V_17 . V_19 ;
int V_50 ;
int V_27 ;
if ( ! V_2 ) {
F_12 ( V_17 , L_5 ) ;
return - V_51 ;
}
F_1 ( V_2 , V_52 , V_53 ) ;
F_1 ( V_2 , V_52 , V_54 ) ;
F_4 ( V_2 , V_52 , V_55 ) ;
if ( F_5 ( V_2 , V_10 , V_13 ) ) {
F_12 ( V_17 , L_6 ) ;
return - V_56 ;
}
F_6 ( V_2 , V_52 , V_57 ,
V_58 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_48 ; V_27 ++ ) {
struct V_14 * V_15 = & V_47 [ V_27 ] ;
F_11 ( V_17 , L_7 ,
V_15 -> V_30 , V_15 -> V_60 , V_15 -> V_37 ) ;
if ( V_15 -> V_60 & V_61 )
V_50 = F_10 ( V_2 , V_15 ) ;
else
V_50 = F_13 ( V_2 , V_15 ) ;
if ( V_50 < 0 )
goto V_62;
}
F_8 ( V_2 , V_63 ) ;
return V_27 ;
V_62:
F_8 ( V_2 , V_63 ) ;
F_12 ( V_17 , L_8 ) ;
return V_50 ;
}
static T_1 F_15 ( struct V_45 * V_46 )
{
return V_64 | V_65 ;
}
static int F_16 ( struct V_66 * V_67 )
{
struct V_16 * V_17 = & V_67 -> V_17 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
int V_50 ;
V_2 = F_17 ( V_17 , sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_72 = F_18 ( V_17 , L_9 ) ;
if ( F_19 ( V_2 -> V_72 ) ) {
F_12 ( V_17 , L_10 , V_2 -> V_72 ) ;
return F_20 ( V_2 -> V_72 ) ;
}
V_69 = F_21 ( V_67 , V_73 , 0 ) ;
V_2 -> V_5 = F_22 ( & V_67 -> V_17 , V_69 ) ;
if ( F_19 ( V_2 -> V_5 ) )
return F_20 ( V_2 -> V_5 ) ;
V_50 = F_23 ( V_2 -> V_72 ) ;
if ( V_50 ) {
F_12 ( V_17 , L_11 ) ;
return V_50 ;
}
F_24 ( V_2 -> V_18 . V_74 , L_12 , sizeof( V_2 -> V_18 . V_74 ) ) ;
V_2 -> V_18 . V_75 = V_76 ;
V_2 -> V_18 . V_77 = V_78 ;
V_2 -> V_18 . V_79 = & V_80 ;
V_2 -> V_18 . V_81 = 3 ;
V_2 -> V_18 . V_17 . V_82 = V_17 -> V_82 ;
V_2 -> V_18 . V_49 = V_2 ;
V_2 -> V_18 . V_17 . V_19 = & V_67 -> V_17 ;
V_50 = F_25 ( & V_2 -> V_18 ) ;
if ( V_50 < 0 ) {
F_12 ( V_17 , L_13 ) ;
goto V_83;
}
F_26 ( V_67 , V_2 ) ;
F_11 ( V_17 , L_14 , & V_2 -> V_18 ) ;
F_11 ( V_17 , L_15 , V_2 -> V_72 ) ;
F_11 ( V_17 , L_16 , & V_69 -> V_84 ,
& V_69 -> V_85 ) ;
return 0 ;
V_83:
F_27 ( V_2 -> V_72 ) ;
return V_50 ;
}
static int F_28 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_29 ( V_67 ) ;
F_30 ( & V_2 -> V_18 ) ;
F_27 ( V_2 -> V_72 ) ;
return 0 ;
}
