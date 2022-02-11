static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_4 ( V_6 , V_4 -> V_7 + V_5 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_4 ,
T_1 V_5 )
{
return F_6 ( V_4 -> V_7 + V_5 ) ;
}
static void F_7 ( struct V_1 * V_4 ,
struct V_8 * V_9 ,
enum V_10 V_11 )
{
T_1 V_6 ;
F_8 ( & V_4 -> V_12 ) ;
V_6 = F_5 ( V_4 , V_13 ) ;
V_6 &= ~ F_9 ( V_9 -> V_14 ) ;
V_6 |= F_10 ( V_9 -> V_14 , V_11 ) ;
F_3 ( V_4 , V_13 , V_6 ) ;
F_11 ( & V_4 -> V_12 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_6 ;
V_6 = ( T_2 ) V_15 * V_4 -> V_16 ;
F_13 ( V_6 , V_17 ) ;
F_3 ( V_4 ,
F_14 ( V_4 -> V_18 ) ,
( T_1 ) V_6 - 1 ) ;
F_3 ( V_4 ,
F_15 ( V_4 -> V_18 ) ,
( T_1 ) V_6 - 1 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_8 * V_9 , int V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_17 ( V_9 ) ;
T_2 V_6 ;
V_6 = ( T_2 ) V_19 * V_4 -> V_16 ;
F_13 ( V_6 , V_17 ) ;
F_3 ( V_4 ,
F_14 ( V_21 -> V_22 ) ,
( T_1 ) V_6 ) ;
F_3 ( V_4 ,
F_15 ( V_21 -> V_22 ) ,
( T_1 ) V_6 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_19 , int V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_23 , V_24 ;
if ( V_15 < V_4 -> V_25 ||
V_15 > V_4 -> V_26 ) {
F_19 ( V_3 -> V_27 , L_1 , V_15 ) ;
return - V_28 ;
}
F_8 ( & V_4 -> V_29 ) ;
V_23 = F_20 ( & V_4 -> V_30 ,
V_31 ) ;
if ( V_23 > 2 && V_4 -> V_15 != V_15 &&
V_4 -> V_15 ) {
F_19 ( V_3 -> V_27 , L_2 ,
V_9 -> V_14 ) ;
F_11 ( & V_4 -> V_29 ) ;
return - V_32 ;
}
if ( ( V_23 <= 2 && V_4 -> V_15 != V_15 ) ||
! V_4 -> V_15 ) {
V_4 -> V_15 = V_15 ;
for ( V_24 = 0 ; V_24 < V_3 -> V_33 ; V_24 ++ )
F_21 ( & V_3 -> V_34 [ V_24 ] , V_15 ) ;
F_12 ( V_3 , V_15 ) ;
}
F_11 ( & V_4 -> V_29 ) ;
F_16 ( V_3 , V_9 , V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
enum V_35 V_36 )
{
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_17 ( V_9 ) ;
enum V_10 V_37 ;
unsigned int V_38 , V_39 ;
F_3 ( V_4 ,
F_24 ( V_21 -> V_22 ) ,
F_25 ( V_21 -> V_22 ) |
V_40 ) ;
F_3 ( V_4 ,
F_26 ( V_21 -> V_22 ) ,
V_41 ) ;
if ( F_27 ( V_9 ) == V_42 ) {
V_38 = V_4 -> V_18 ;
V_39 = V_21 -> V_22 ;
V_37 = V_43 ;
} else {
V_38 = V_21 -> V_22 ;
V_39 = V_4 -> V_18 ;
V_37 = V_44 ;
}
F_3 ( V_4 , F_28 ( V_9 -> V_14 ) ,
F_29 ( V_38 ) ) ;
F_3 ( V_4 , F_30 ( V_9 -> V_14 ) ,
F_29 ( V_39 ) ) ;
F_7 ( V_4 , V_9 , V_37 ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_17 ( V_9 ) ;
F_3 ( V_4 ,
F_24 ( V_21 -> V_22 ) , 0 ) ;
F_3 ( V_4 , F_28 ( V_9 -> V_14 ) , 0 ) ;
F_3 ( V_4 , F_30 ( V_9 -> V_14 ) , 0 ) ;
}
static int F_32 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_17 ( V_9 ) ;
unsigned long V_45 ;
V_45 = F_33 ( & V_4 -> V_30 ,
V_31 ) ;
if ( V_45 >= V_31 ) {
F_19 ( V_4 -> V_27 ,
L_3 ) ;
return - V_32 ;
} ;
F_34 ( V_45 , & V_4 -> V_30 ) ;
V_21 -> V_22 = V_45 ;
F_16 ( V_3 , V_9 , F_35 ( V_9 ) ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_17 ( V_9 ) ;
F_37 ( V_9 ) ;
F_38 ( V_9 , 0 ) ;
F_39 ( V_21 -> V_22 , & V_4 -> V_30 ) ;
}
static int F_40 ( struct V_46 * V_47 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
struct V_48 * V_49 ;
int V_50 , V_24 ;
T_2 V_6 ;
V_4 = F_41 ( & V_47 -> V_27 , sizeof( * V_4 ) ,
V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_27 = & V_47 -> V_27 ;
V_49 = F_42 ( V_47 , V_53 , 0 ) ;
V_4 -> V_7 = F_43 ( & V_47 -> V_27 , V_49 ) ;
if ( F_44 ( V_4 -> V_7 ) )
return F_45 ( V_4 -> V_7 ) ;
V_4 -> V_54 = F_46 ( & V_47 -> V_27 , L_4 ) ;
if ( F_44 ( V_4 -> V_54 ) ) {
F_19 ( & V_47 -> V_27 , L_5 ) ;
return F_45 ( V_4 -> V_54 ) ;
}
V_50 = F_47 ( V_4 -> V_54 ) ;
if ( V_50 < 0 ) {
F_19 ( & V_47 -> V_27 , L_6 ) ;
return V_50 ;
}
V_4 -> V_16 = F_48 ( V_4 -> V_54 ) ;
if ( ! V_4 -> V_16 ) {
F_19 ( & V_47 -> V_27 , L_7 ) ;
V_50 = - V_55 ;
goto V_56;
}
F_49 ( & V_4 -> V_12 ) ;
F_49 ( & V_4 -> V_29 ) ;
V_6 = ( T_2 ) V_17 * V_57 ;
F_13 ( V_6 , V_4 -> V_16 ) ;
V_4 -> V_26 = V_6 ;
V_4 -> V_25 = F_50 ( V_17 ,
V_4 -> V_16 ) ;
V_4 -> V_3 . V_27 = & V_47 -> V_27 ;
V_4 -> V_3 . V_58 = & V_59 ;
V_4 -> V_3 . V_7 = - 1 ;
V_4 -> V_3 . V_33 = 16 ;
V_4 -> V_3 . V_60 = V_61 ;
V_4 -> V_3 . V_62 = 3 ;
F_3 ( V_4 , V_63 ,
V_64 ) ;
F_34 ( V_65 , & V_4 -> V_30 ) ;
V_4 -> V_18 = V_65 ;
F_3 ( V_4 ,
F_26 ( V_4 -> V_18 ) ,
V_41 ) ;
V_6 = F_25 ( V_4 -> V_18 ) |
V_40 ;
F_3 ( V_4 ,
F_24 ( V_4 -> V_18 ) , V_6 ) ;
F_3 ( V_4 , V_66 ,
F_29 ( V_4 -> V_18 ) ) ;
V_50 = F_51 ( & V_4 -> V_3 ) ;
if ( V_50 < 0 ) {
F_19 ( & V_47 -> V_27 , L_8 , V_50 ) ;
goto V_56;
}
for ( V_24 = 0 ; V_24 < V_4 -> V_3 . V_33 ; V_24 ++ ) {
struct V_20 * V_67 ;
V_9 = & V_4 -> V_3 . V_34 [ V_24 ] ;
V_67 = F_41 ( V_4 -> V_27 , sizeof( * V_67 ) ,
V_51 ) ;
if ( ! V_67 ) {
V_50 = - V_52 ;
goto V_68;
}
F_52 ( V_9 , V_67 ) ;
}
F_53 ( V_47 , V_4 ) ;
V_6 = F_5 ( V_4 , V_69 ) ;
V_6 &= ~ V_70 ;
V_6 &= ~ V_71 ;
V_6 &= ~ V_72 ;
V_6 |= F_54 ( 0 ) ;
F_3 ( V_4 , V_69 , V_6 ) ;
return 0 ;
V_68:
F_55 ( & V_4 -> V_3 ) ;
V_56:
F_56 ( V_4 -> V_54 ) ;
return V_50 ;
}
static int F_57 ( struct V_46 * V_47 )
{
struct V_1 * V_4 = F_58 ( V_47 ) ;
T_1 V_6 ;
V_6 = F_5 ( V_4 , V_69 ) ;
F_3 ( V_4 , V_69 ,
V_6 | V_71 ) ;
F_56 ( V_4 -> V_54 ) ;
return F_55 ( & V_4 -> V_3 ) ;
}
