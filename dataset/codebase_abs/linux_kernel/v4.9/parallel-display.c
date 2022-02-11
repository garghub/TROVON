static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static enum V_8 F_4 (
struct V_2 * V_4 , bool V_9 )
{
return V_10 ;
}
static int F_5 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
int V_16 = 0 ;
if ( V_11 -> V_17 && V_11 -> V_17 -> V_18 &&
V_11 -> V_17 -> V_18 -> V_19 ) {
V_16 = V_11 -> V_17 -> V_18 -> V_19 ( V_11 -> V_17 ) ;
if ( V_16 > 0 )
return V_16 ;
}
if ( V_11 -> V_20 ) {
F_6 ( V_4 , V_11 -> V_20 ) ;
V_16 = F_7 ( V_4 , V_11 -> V_20 ) ;
}
if ( V_13 ) {
struct V_21 * V_22 = F_8 ( V_4 -> V_14 ) ;
int V_23 ;
if ( ! V_22 )
return - V_24 ;
V_23 = F_9 ( V_13 , & V_11 -> V_22 ,
& V_11 -> V_25 ,
V_26 ) ;
if ( V_23 )
return V_23 ;
F_10 ( V_22 , & V_11 -> V_22 ) ;
V_22 -> type |= V_27 | V_28 ,
F_11 ( V_4 , V_22 ) ;
V_16 ++ ;
}
return V_16 ;
}
static struct V_5 * F_12 (
struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
return & V_11 -> V_7 ;
}
static void F_13 ( struct V_5 * V_7 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
F_14 ( V_11 -> V_17 ) ;
F_15 ( V_11 -> V_17 ) ;
}
static void F_16 ( struct V_5 * V_7 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
F_17 ( V_11 -> V_17 ) ;
F_18 ( V_11 -> V_17 ) ;
}
static int F_19 ( struct V_5 * V_7 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_33 = F_20 ( V_30 ) ;
struct V_34 * V_35 = & V_32 -> V_4 -> V_36 ;
struct V_1 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_37 && V_35 -> V_38 ) {
V_33 -> V_25 = V_35 -> V_25 ;
V_33 -> V_37 = V_35 -> V_39 [ 0 ] ;
} else {
V_33 -> V_25 = V_11 -> V_25 ;
V_33 -> V_37 = V_11 -> V_37 ;
}
V_33 -> V_40 = 2 ;
V_33 -> V_41 = 3 ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 ,
struct V_1 * V_11 )
{
struct V_5 * V_7 = & V_11 -> V_7 ;
int V_23 ;
V_23 = F_22 ( V_43 , V_7 , V_11 -> V_14 -> V_15 ) ;
if ( V_23 )
return V_23 ;
V_11 -> V_4 . V_44 = V_45 ;
F_23 ( V_7 , & V_46 ) ;
F_24 ( V_43 , V_7 , & V_47 ,
V_48 , NULL ) ;
if ( ! V_11 -> V_49 ) {
F_25 ( & V_11 -> V_4 ,
& V_50 ) ;
F_26 ( V_43 , & V_11 -> V_4 ,
& V_51 ,
V_52 ) ;
}
if ( V_11 -> V_17 )
F_27 ( V_11 -> V_17 , & V_11 -> V_4 ) ;
if ( V_11 -> V_49 ) {
V_11 -> V_49 -> V_7 = V_7 ;
V_7 -> V_49 = V_11 -> V_49 ;
V_23 = F_28 ( V_43 , V_11 -> V_49 ) ;
if ( V_23 < 0 ) {
F_29 ( V_11 -> V_14 , L_1 ,
V_23 ) ;
return V_23 ;
}
} else {
F_30 ( & V_11 -> V_4 , V_7 ) ;
}
return 0 ;
}
static int F_31 ( struct V_53 * V_14 , struct V_53 * V_54 , void * V_55 )
{
struct V_42 * V_43 = V_55 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_12 * V_56 ;
const T_1 * V_57 ;
struct V_1 * V_11 ;
int V_23 ;
T_2 V_37 = 0 ;
const char * V_58 ;
V_11 = F_32 ( V_14 , sizeof( * V_11 ) , V_59 ) ;
if ( ! V_11 )
return - V_60 ;
V_57 = F_33 ( V_13 , L_2 , & V_11 -> V_61 ) ;
if ( V_57 )
V_11 -> V_20 = F_34 ( V_57 , V_11 -> V_61 , V_59 ) ;
V_23 = F_35 ( V_13 , L_3 , & V_58 ) ;
if ( ! V_23 ) {
if ( ! strcmp ( V_58 , L_4 ) )
V_37 = V_62 ;
else if ( ! strcmp ( V_58 , L_5 ) )
V_37 = V_63 ;
else if ( ! strcmp ( V_58 , L_6 ) )
V_37 = V_64 ;
else if ( ! strcmp ( V_58 , L_7 ) )
V_37 = V_65 ;
}
V_11 -> V_37 = V_37 ;
V_56 = F_36 ( V_13 , 1 , - 1 ) ;
if ( V_56 ) {
struct V_12 * V_66 ;
V_66 = F_37 ( V_56 ) ;
if ( ! V_66 ) {
F_38 ( V_14 , L_8 ,
V_56 -> V_67 ) ;
F_39 ( V_56 ) ;
return - V_68 ;
}
F_39 ( V_56 ) ;
V_11 -> V_17 = F_40 ( V_66 ) ;
if ( V_11 -> V_17 ) {
F_41 ( V_14 , L_9 , V_66 -> V_67 ) ;
} else {
V_11 -> V_49 = F_42 ( V_66 ) ;
if ( V_11 -> V_49 )
F_41 ( V_14 , L_10 ,
V_66 -> V_67 ) ;
}
if ( ! V_11 -> V_17 && ! V_11 -> V_49 ) {
F_41 ( V_14 , L_11 ,
V_66 -> V_67 ) ;
F_39 ( V_66 ) ;
return - V_69 ;
}
F_39 ( V_66 ) ;
}
V_11 -> V_14 = V_14 ;
V_23 = F_21 ( V_43 , V_11 ) ;
if ( V_23 )
return V_23 ;
F_43 ( V_14 , V_11 ) ;
return 0 ;
}
static void F_44 ( struct V_53 * V_14 , struct V_53 * V_54 ,
void * V_55 )
{
struct V_1 * V_11 = F_45 ( V_14 ) ;
if ( V_11 -> V_49 )
F_46 ( V_11 -> V_49 ) ;
if ( V_11 -> V_17 )
F_47 ( V_11 -> V_17 ) ;
F_48 ( V_11 -> V_20 ) ;
}
static int F_49 ( struct V_70 * V_71 )
{
return F_50 ( & V_71 -> V_14 , & V_72 ) ;
}
static int F_51 ( struct V_70 * V_71 )
{
F_52 ( & V_71 -> V_14 , & V_72 ) ;
return 0 ;
}
