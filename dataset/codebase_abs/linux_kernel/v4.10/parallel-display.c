static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static int F_4 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_11 -> V_12 ;
int V_13 = 0 ;
if ( V_8 -> V_14 && V_8 -> V_14 -> V_15 &&
V_8 -> V_14 -> V_15 -> V_16 ) {
V_13 = V_8 -> V_14 -> V_15 -> V_16 ( V_8 -> V_14 ) ;
if ( V_13 > 0 )
return V_13 ;
}
if ( V_8 -> V_17 ) {
F_5 ( V_4 , V_8 -> V_17 ) ;
V_13 = F_6 ( V_4 , V_8 -> V_17 ) ;
}
if ( V_10 ) {
struct V_18 * V_19 = F_7 ( V_4 -> V_11 ) ;
int V_20 ;
if ( ! V_19 )
return - V_21 ;
V_20 = F_8 ( V_10 , & V_8 -> V_19 ,
& V_8 -> V_22 ,
V_23 ) ;
if ( V_20 )
return V_20 ;
F_9 ( V_19 , & V_8 -> V_19 ) ;
V_19 -> type |= V_24 | V_25 ,
F_10 ( V_4 , V_19 ) ;
V_13 ++ ;
}
return V_13 ;
}
static struct V_5 * F_11 (
struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
return & V_8 -> V_7 ;
}
static void F_12 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
F_13 ( V_8 -> V_14 ) ;
F_14 ( V_8 -> V_14 ) ;
}
static void F_15 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
F_16 ( V_8 -> V_14 ) ;
F_17 ( V_8 -> V_14 ) ;
}
static int F_18 ( struct V_5 * V_7 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_30 = F_19 ( V_27 ) ;
struct V_31 * V_32 = & V_29 -> V_4 -> V_33 ;
struct V_1 * V_8 = F_3 ( V_7 ) ;
if ( ! V_8 -> V_34 && V_32 -> V_35 ) {
V_30 -> V_22 = V_32 -> V_22 ;
V_30 -> V_34 = V_32 -> V_36 [ 0 ] ;
} else {
V_30 -> V_22 = V_8 -> V_22 ;
V_30 -> V_34 = V_8 -> V_34 ;
}
V_30 -> V_37 = 2 ;
V_30 -> V_38 = 3 ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_1 * V_8 )
{
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_20 ;
V_20 = F_21 ( V_40 , V_7 , V_8 -> V_11 -> V_12 ) ;
if ( V_20 )
return V_20 ;
V_8 -> V_4 . V_41 = V_42 ;
F_22 ( V_7 , & V_43 ) ;
F_23 ( V_40 , V_7 , & V_44 ,
V_45 , NULL ) ;
if ( ! V_8 -> V_46 ) {
F_24 ( & V_8 -> V_4 ,
& V_47 ) ;
F_25 ( V_40 , & V_8 -> V_4 ,
& V_48 ,
V_49 ) ;
}
if ( V_8 -> V_14 )
F_26 ( V_8 -> V_14 , & V_8 -> V_4 ) ;
if ( V_8 -> V_46 ) {
V_8 -> V_46 -> V_7 = V_7 ;
V_7 -> V_46 = V_8 -> V_46 ;
V_20 = F_27 ( V_40 , V_8 -> V_46 ) ;
if ( V_20 < 0 ) {
F_28 ( V_8 -> V_11 , L_1 ,
V_20 ) ;
return V_20 ;
}
} else {
F_29 ( & V_8 -> V_4 , V_7 ) ;
}
return 0 ;
}
static int F_30 ( struct V_50 * V_11 , struct V_50 * V_51 , void * V_52 )
{
struct V_39 * V_40 = V_52 ;
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_9 * V_53 ;
const T_1 * V_54 ;
struct V_1 * V_8 ;
int V_20 ;
T_2 V_34 = 0 ;
const char * V_55 ;
V_8 = F_31 ( V_11 , sizeof( * V_8 ) , V_56 ) ;
if ( ! V_8 )
return - V_57 ;
V_54 = F_32 ( V_10 , L_2 , & V_8 -> V_58 ) ;
if ( V_54 )
V_8 -> V_17 = F_33 ( V_54 , V_8 -> V_58 , V_56 ) ;
V_20 = F_34 ( V_10 , L_3 , & V_55 ) ;
if ( ! V_20 ) {
if ( ! strcmp ( V_55 , L_4 ) )
V_34 = V_59 ;
else if ( ! strcmp ( V_55 , L_5 ) )
V_34 = V_60 ;
else if ( ! strcmp ( V_55 , L_6 ) )
V_34 = V_61 ;
else if ( ! strcmp ( V_55 , L_7 ) )
V_34 = V_62 ;
}
V_8 -> V_34 = V_34 ;
V_53 = F_35 ( V_10 , 1 , - 1 ) ;
if ( V_53 ) {
struct V_9 * V_63 ;
V_63 = F_36 ( V_53 ) ;
if ( ! V_63 ) {
F_37 ( V_11 , L_8 ,
V_53 -> V_64 ) ;
F_38 ( V_53 ) ;
return - V_65 ;
}
F_38 ( V_53 ) ;
V_8 -> V_14 = F_39 ( V_63 ) ;
if ( V_8 -> V_14 ) {
F_40 ( V_11 , L_9 , V_63 -> V_64 ) ;
} else {
V_8 -> V_46 = F_41 ( V_63 ) ;
if ( V_8 -> V_46 )
F_40 ( V_11 , L_10 ,
V_63 -> V_64 ) ;
}
if ( ! V_8 -> V_14 && ! V_8 -> V_46 ) {
F_40 ( V_11 , L_11 ,
V_63 -> V_64 ) ;
F_38 ( V_63 ) ;
return - V_66 ;
}
F_38 ( V_63 ) ;
}
V_8 -> V_11 = V_11 ;
V_20 = F_20 ( V_40 , V_8 ) ;
if ( V_20 )
return V_20 ;
F_42 ( V_11 , V_8 ) ;
return 0 ;
}
static void F_43 ( struct V_50 * V_11 , struct V_50 * V_51 ,
void * V_52 )
{
struct V_1 * V_8 = F_44 ( V_11 ) ;
if ( V_8 -> V_46 )
F_45 ( V_8 -> V_46 ) ;
if ( V_8 -> V_14 )
F_46 ( V_8 -> V_14 ) ;
F_47 ( V_8 -> V_17 ) ;
}
static int F_48 ( struct V_67 * V_68 )
{
return F_49 ( & V_68 -> V_11 , & V_69 ) ;
}
static int F_50 ( struct V_67 * V_68 )
{
F_51 ( & V_68 -> V_11 , & V_69 ) ;
return 0 ;
}
