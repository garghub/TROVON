static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 != NULL ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( (struct V_10 * ) V_4 -> V_11 != V_9 -> V_12 ) ;
F_1 ( V_2 ) ;
}
static int F_6 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 , struct V_13 * V_14 ,
int V_15 )
{
struct V_1 * V_16 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_16 -> V_5 ;
F_2 ( V_4 != NULL ) ;
if ( V_15 ) {
if ( ! F_7 ( V_4 ) )
return - V_17 ;
if ( F_8 ( F_9 ( V_4 ) ) ) {
F_10 ( V_4 ) ;
return - V_17 ;
}
return 0 ;
}
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static void F_13 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_12 ( V_4 ) ;
}
static void F_16 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
}
static void F_17 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 , struct V_13 * V_14 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_10 ( F_14 ( V_9 ) ) ;
}
static void F_18 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_19 * V_20 ;
struct V_1 * V_21 = F_5 ( V_9 ) ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
V_20 = V_4 -> V_20 ;
if ( V_21 -> V_22 && ! V_21 -> V_23 )
F_19 ( V_20 , V_24 ) ;
F_20 ( V_20 , V_4 ) ;
}
static int F_21 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
T_1 V_25 ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
V_25 = V_4 -> V_26 << V_27 ;
F_22 ( V_4 -> V_20 , V_25 , V_25 + V_28 ) ;
return 0 ;
}
static void F_23 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_29 * V_29 = V_4 -> V_20 -> V_30 ;
struct V_31 * V_32 = V_9 -> V_33 ;
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( (struct V_10 * ) V_4 -> V_11 == V_9 -> V_12 ) ;
F_2 ( V_29 == F_24 ( V_32 ) ) ;
F_25 ( F_26 ( V_32 ) , F_5 ( V_9 ) ) ;
F_27 ( V_4 ) ;
V_4 -> V_11 = 0 ;
}
static void F_28 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_34 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 != NULL ) ;
F_2 ( F_15 ( V_4 ) ) ;
if ( V_34 )
F_29 ( V_4 ) ;
else
F_30 ( V_4 ) ;
}
static int F_31 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
return F_15 ( F_14 ( V_9 ) ) ? - V_35 : - V_36 ;
}
static int F_32 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
return F_33 ( F_14 ( V_9 ) ) ? - V_37 : 0 ;
}
static int F_34 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_10 * V_38 = V_9 -> V_12 ;
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( ! F_35 ( V_4 ) ) ;
if ( ! V_38 -> V_39 )
F_36 ( V_4 ) ;
F_37 ( F_26 ( V_9 -> V_33 ) , F_5 ( V_9 ) ) ;
return 0 ;
}
static void F_38 ( struct V_29 * V_29 , struct V_3 * V_4 , int V_40 )
{
struct V_41 * V_32 = F_39 ( V_29 ) ;
if ( V_40 == 0 ) {
F_40 ( V_4 ) ;
V_32 -> V_42 = 0 ;
} else {
F_41 ( V_4 ) ;
if ( V_40 == - V_43 )
F_42 ( V_44 , & V_29 -> V_45 -> V_46 ) ;
else
F_42 ( V_47 , & V_29 -> V_45 -> V_46 ) ;
if ( ( V_40 == - V_48 || V_40 == - V_49 ) &&
V_32 -> V_42 == 0 ) {
V_32 -> V_42 = 1 ;
F_43 ( V_4 , V_40 ) ;
}
}
}
static void F_44 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_40 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_3 = F_45 ( V_9 -> V_12 ) ;
struct V_29 * V_29 = F_24 ( V_3 -> V_50 ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_46 ( V_51 , V_7 , V_3 , L_1 , V_40 ) ;
if ( V_2 -> V_22 )
F_47 ( F_48 ( V_29 ) , 1 ) ;
if ( V_40 == 0 ) {
if ( ! V_2 -> V_22 )
F_49 ( V_7 , V_3 , 1 ) ;
} else
V_2 -> V_22 = 0 ;
if ( V_3 -> V_39 == NULL )
F_10 ( V_4 ) ;
}
static void F_50 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_40 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_10 * V_38 = V_9 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_46 ( V_51 , V_7 , V_38 , L_2 , V_40 ) ;
V_2 -> V_52 = 0 ;
F_25 ( F_26 ( V_9 -> V_33 ) , V_2 ) ;
if ( V_38 -> V_39 != NULL ) {
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( ! F_9 ( V_4 ) ) ;
} else {
F_2 ( F_9 ( V_4 ) ) ;
F_38 ( F_24 ( V_38 -> V_50 ) , V_4 , V_40 ) ;
F_51 ( V_4 ) ;
}
}
static int F_52 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_10 * V_38 = V_9 -> V_12 ;
int V_53 = 0 ;
F_11 ( V_4 ) ;
if ( F_53 ( V_4 ) ) {
F_2 ( V_38 -> V_54 == V_55 ) ;
F_36 ( V_4 ) ;
F_37 ( F_26 ( V_9 -> V_33 ) ,
F_5 ( V_9 ) ) ;
F_46 ( V_51 , V_7 , V_38 , L_3 ) ;
} else if ( V_38 -> V_54 == V_56 ) {
V_53 = - V_37 ;
} else {
F_54 ( V_57 , V_7 , V_38 , L_4 ,
V_38 -> V_54 ) ;
F_55 () ;
}
F_10 ( V_4 ) ;
return V_53 ;
}
static int F_56 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
void * V_58 , T_2 V_59 )
{
struct V_1 * V_60 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_60 -> V_5 ;
(* V_59)( V_7 , V_58 , V_61 L_5 ,
V_60 , V_60 -> V_22 , V_60 -> V_23 ,
V_60 -> V_52 , V_4 ) ;
if ( V_4 != NULL ) {
(* V_59)( V_7 , V_58 , L_6 ,
( long ) V_4 -> V_46 , F_57 ( V_4 ) ,
F_58 ( V_4 ) , V_4 -> V_11 ,
F_59 ( V_4 ) ,
F_60 ( & V_4 -> V_62 ) ? L_7 : L_8 ) ;
}
(* V_59)( V_7 , V_58 , L_9 ) ;
return 0 ;
}
static void F_61 ( const struct V_10 * V_3 )
{
struct V_29 * V_29 = F_24 ( V_3 -> V_50 ) ;
F_2 ( ! F_62 ( V_29 ) ) ;
}
static int F_63 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 , int V_15 )
{
F_61 ( V_9 -> V_12 ) ;
return 0 ;
}
static void F_64 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
F_61 ( V_9 -> V_12 ) ;
}
static void F_65 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
F_61 ( V_9 -> V_12 ) ;
}
static void F_66 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
F_61 ( V_9 -> V_12 ) ;
}
static void F_67 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_18 )
{
struct V_10 * V_3 = V_9 -> V_12 ;
F_61 ( V_9 -> V_12 ) ;
F_68 ( V_7 , V_3 ) ;
}
static int F_69 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_29 * V_29 = F_24 ( V_9 -> V_33 ) ;
int V_63 ;
V_63 = ! F_62 ( V_29 ) ;
if ( ! V_63 )
F_70 ( V_29 ) ;
return V_63 ? - V_35 : - V_36 ;
}
static void
F_71 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_40 )
{
F_61 ( V_9 -> V_12 ) ;
}
static void F_72 ( const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_10 * V_64 = V_9 -> V_12 ;
struct V_41 * V_65 = F_26 ( V_64 -> V_50 ) ;
F_1 ( V_2 ) ;
F_2 ( ! F_62 ( V_65 -> V_66 ) ) ;
V_65 -> V_67 -- ;
}
int F_73 ( const struct V_6 * V_7 , struct V_31 * V_32 ,
struct V_10 * V_3 , struct V_3 * V_4 )
{
struct V_1 * V_21 = F_74 ( V_32 , V_3 ) ;
F_75 ( V_7 , V_32 , F_76 ( V_32 ) ) ;
V_21 -> V_5 = V_4 ;
F_77 ( V_4 ) ;
F_78 ( & V_21 -> V_68 ) ;
if ( V_3 -> V_69 == V_70 ) {
F_79 ( V_4 ) ;
V_4 -> V_11 = ( unsigned long ) V_3 ;
F_80 ( V_3 , & V_21 -> V_71 , V_32 ,
& V_72 ) ;
} else {
struct V_41 * V_65 = F_26 ( V_32 ) ;
F_2 ( ! F_62 ( V_65 -> V_66 ) ) ;
F_80 ( V_3 , & V_21 -> V_71 , V_32 ,
& V_73 ) ;
V_65 -> V_67 ++ ;
}
return 0 ;
}
