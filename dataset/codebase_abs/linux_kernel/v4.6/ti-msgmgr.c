static inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) & V_5 ;
V_3 >>= F_3 ( V_5 ) ;
return V_3 ;
}
static T_2 F_4 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_9 -> V_15 ;
const struct V_16 * V_17 ;
int V_18 , V_19 ;
struct V_20 V_21 ;
void T_3 * V_22 ;
T_1 * V_23 ;
if ( F_6 ( ! V_14 ) ) {
F_7 ( V_11 , L_1 ) ;
return - V_24 ;
}
if ( V_2 -> V_25 ) {
F_7 ( V_11 , L_2 ,
V_2 -> V_26 ) ;
return V_27 ;
}
V_18 = F_1 ( V_2 ) ;
if ( ! V_18 ) {
F_8 ( V_11 , L_3 ) ;
return V_27 ;
}
V_17 = V_14 -> V_17 ;
V_21 . V_28 = V_17 -> V_29 ;
V_21 . V_30 = ( V_31 * ) V_2 -> V_32 ;
for ( V_22 = V_2 -> V_33 , V_23 = V_2 -> V_32 ,
V_19 = ( V_17 -> V_29 / sizeof( T_1 ) ) ;
V_19 ; V_19 -- , V_22 += sizeof( T_1 ) , V_23 ++ )
* V_23 = F_2 ( V_22 ) ;
F_9 ( V_9 , ( void * ) & V_21 ) ;
return V_34 ;
}
static bool F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_15 ;
int V_18 ;
if ( V_2 -> V_25 )
return false ;
V_18 = F_1 ( V_2 ) ;
return V_18 ? true : false ;
}
static bool F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_15 ;
int V_18 ;
if ( ! V_2 -> V_25 )
return false ;
V_18 = F_1 ( V_2 ) ;
return V_18 ? false : true ;
}
static int F_12 ( struct V_8 * V_9 , void * V_35 )
{
struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
struct V_13 * V_14 = F_5 ( V_11 ) ;
const struct V_16 * V_17 ;
struct V_1 * V_2 = V_9 -> V_15 ;
int V_19 , V_36 ;
struct V_20 * V_21 = V_35 ;
void T_3 * V_22 ;
T_1 * V_23 ;
if ( F_6 ( ! V_14 ) ) {
F_7 ( V_11 , L_1 ) ;
return - V_24 ;
}
V_17 = V_14 -> V_17 ;
if ( V_17 -> V_29 < V_21 -> V_28 ) {
F_7 ( V_11 , L_4 ,
V_2 -> V_26 , V_21 -> V_28 , V_17 -> V_29 ) ;
return - V_24 ;
}
for ( V_22 = V_2 -> V_33 ,
V_19 = V_21 -> V_28 / sizeof( T_1 ) ,
V_23 = ( T_1 * ) V_21 -> V_30 ;
V_19 ; V_19 -- , V_22 += sizeof( T_1 ) , V_23 ++ )
F_13 ( * V_23 , V_22 ) ;
V_36 = V_21 -> V_28 % sizeof( T_1 ) ;
if ( V_36 ) {
T_1 V_37 = * V_23 ;
V_37 &= 0xFFFFFFFF >> ( 8 * ( sizeof( T_1 ) - V_36 ) ) ;
F_13 ( V_37 , V_22 ) ;
V_22 ++ ;
}
if ( V_22 <= V_2 -> V_38 )
F_13 ( 0 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_15 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
int V_39 ;
if ( ! V_2 -> V_25 ) {
V_39 = F_15 ( V_2 -> V_6 , F_4 ,
V_40 , V_2 -> V_26 , V_9 ) ;
if ( V_39 ) {
F_7 ( V_11 , L_5 ,
V_2 -> V_6 , V_2 -> V_26 , V_39 ) ;
return V_39 ;
}
}
return 0 ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_15 ;
if ( ! V_2 -> V_25 )
F_17 ( V_2 -> V_6 , V_9 ) ;
}
static struct V_8 * F_18 ( struct V_41 * V_12 ,
const struct V_42 * V_7 )
{
struct V_13 * V_14 ;
int V_43 , V_44 ;
struct V_1 * V_2 ;
int V_45 ;
V_14 = F_19 ( V_12 , struct V_13 , V_12 ) ;
if ( F_6 ( ! V_14 ) )
return F_20 ( - V_24 ) ;
if ( V_7 -> V_46 != 2 ) {
F_7 ( V_14 -> V_11 , L_6 ,
V_7 -> V_46 ) ;
return F_20 ( - V_24 ) ;
}
V_43 = V_7 -> args [ 0 ] ;
V_44 = V_7 -> args [ 1 ] ;
for ( V_2 = V_14 -> V_47 , V_45 = 0 ; V_45 < V_14 -> V_48 ;
V_45 ++ , V_2 ++ ) {
if ( V_43 == V_2 -> V_49 && V_44 == V_2 -> V_50 )
return V_2 -> V_9 ;
}
F_7 ( V_14 -> V_11 , L_7 ,
V_43 , V_44 , V_7 -> V_51 -> V_26 ) ;
return F_20 ( - V_52 ) ;
}
static int F_21 ( int V_53 , struct V_10 * V_11 ,
struct V_54 * V_51 ,
struct V_13 * V_14 ,
const struct V_16 * V_55 ,
const struct V_56 * V_57 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_2 -> V_50 = V_57 -> V_50 ;
V_2 -> V_49 = V_57 -> V_49 ;
if ( V_2 -> V_49 > V_55 -> V_58 ) {
F_7 ( V_11 , L_8 ,
V_53 , V_2 -> V_49 , V_55 -> V_58 ) ;
return - V_59 ;
}
V_2 -> V_25 = V_57 -> V_25 ;
snprintf ( V_2 -> V_26 , sizeof( V_2 -> V_26 ) , L_9 ,
F_22 ( V_11 ) , V_2 -> V_25 ? L_10 : L_11 , V_2 -> V_49 ,
V_2 -> V_50 ) ;
if ( ! V_2 -> V_25 ) {
char V_60 [ 7 ] ;
snprintf ( V_60 , sizeof( V_60 ) ,
L_12 , V_2 -> V_49 ) ;
V_2 -> V_6 = F_23 ( V_51 , V_60 ) ;
if ( V_2 -> V_6 < 0 ) {
F_24 ( V_11 ,
L_13 ,
V_53 , V_2 -> V_49 , V_2 -> V_50 ,
V_60 , V_2 -> V_6 ) ;
return V_2 -> V_6 ;
}
V_2 -> V_32 = F_25 ( V_11 ,
V_55 -> V_29 , V_61 ) ;
if ( ! V_2 -> V_32 )
return - V_62 ;
}
V_2 -> V_33 = V_14 -> V_63 +
F_26 ( V_2 -> V_50 , V_2 -> V_49 , V_55 -> V_64 ) ;
V_2 -> V_38 = V_14 -> V_63 +
F_26 ( V_2 -> V_50 , V_2 -> V_49 , V_55 -> V_65 ) ;
V_2 -> V_4 = V_14 -> V_66 +
F_27 ( V_2 -> V_49 ) ;
V_2 -> V_9 = V_9 ;
V_9 -> V_15 = V_2 ;
F_8 ( V_11 , L_14 ,
V_53 , V_2 -> V_49 , V_2 -> V_50 , V_2 -> V_6 ,
V_2 -> V_33 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 )
{
struct V_10 * V_11 = & V_68 -> V_11 ;
const struct V_69 * V_70 ;
struct V_54 * V_51 ;
struct V_71 * V_72 ;
const struct V_16 * V_17 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_41 * V_12 ;
struct V_8 * V_73 ;
int V_58 ;
int V_45 ;
int V_39 = - V_24 ;
const struct V_56 * V_74 ;
if ( ! V_11 -> V_75 ) {
F_7 ( V_11 , L_15 ) ;
return - V_24 ;
}
V_51 = V_11 -> V_75 ;
V_70 = F_29 ( V_76 , V_11 ) ;
if ( ! V_70 ) {
F_7 ( V_11 , L_16 ) ;
return - V_24 ;
}
V_17 = V_70 -> V_35 ;
V_14 = F_25 ( V_11 , sizeof( * V_14 ) , V_61 ) ;
if ( ! V_14 )
return - V_62 ;
V_14 -> V_11 = V_11 ;
V_14 -> V_17 = V_17 ;
V_72 = F_30 ( V_68 , V_77 ,
L_17 ) ;
V_14 -> V_63 = F_31 ( V_11 , V_72 ) ;
if ( F_32 ( V_14 -> V_63 ) )
return F_33 ( V_14 -> V_63 ) ;
V_72 = F_30 ( V_68 , V_77 ,
L_18 ) ;
V_14 -> V_66 = F_31 ( V_11 , V_72 ) ;
if ( F_32 ( V_14 -> V_66 ) )
return F_33 ( V_14 -> V_66 ) ;
F_8 ( V_11 , L_19 ,
V_14 -> V_63 , V_14 -> V_66 ) ;
V_58 = V_17 -> V_48 ;
if ( ! V_58 || V_58 > V_17 -> V_58 ) {
F_24 ( V_11 , L_20 ,
V_58 , V_17 -> V_58 ) ;
return - V_59 ;
}
V_14 -> V_48 = V_58 ;
V_2 = F_25 ( V_11 , sizeof( * V_2 ) * V_58 , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_14 -> V_47 = V_2 ;
V_73 = F_25 ( V_11 , sizeof( * V_73 ) * V_58 , V_61 ) ;
if ( ! V_73 )
return - V_62 ;
V_14 -> V_73 = V_73 ;
for ( V_45 = 0 , V_74 = V_17 -> V_78 ;
V_45 < V_58 ; V_45 ++ , V_2 ++ , V_73 ++ , V_74 ++ ) {
V_39 = F_21 ( V_45 , V_11 , V_51 , V_14 ,
V_17 , V_74 , V_2 , V_73 ) ;
if ( V_39 )
return V_39 ;
}
V_12 = & V_14 -> V_12 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_79 = & V_80 ;
V_12 -> V_73 = V_14 -> V_73 ;
V_12 -> V_81 = V_14 -> V_48 ;
V_12 -> V_82 = false ;
V_12 -> V_83 = V_17 -> V_84 ;
if ( V_17 -> V_84 )
V_12 -> V_85 = V_17 -> V_86 ;
V_12 -> V_87 = F_18 ;
F_34 ( V_68 , V_14 ) ;
V_39 = F_35 ( V_12 ) ;
if ( V_39 )
F_7 ( V_11 , L_21 , V_39 ) ;
return V_39 ;
}
static int F_36 ( struct V_67 * V_68 )
{
struct V_13 * V_14 ;
V_14 = F_37 ( V_68 ) ;
F_38 ( & V_14 -> V_12 ) ;
return 0 ;
}
