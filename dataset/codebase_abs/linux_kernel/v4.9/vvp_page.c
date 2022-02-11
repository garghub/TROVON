static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 ) ;
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
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 ) ;
if ( V_15 ) {
if ( ! F_7 ( V_4 ) )
return - V_16 ;
if ( F_8 ( F_9 ( V_4 ) ) ) {
F_10 ( V_4 ) ;
return - V_16 ;
}
return 0 ;
}
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static void F_13 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_12 ( V_4 ) ;
}
static void F_16 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 ) ;
F_2 ( F_15 ( V_4 ) ) ;
}
static void F_17 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 , struct V_13 * V_14 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_10 ( F_14 ( V_9 ) ) ;
}
static void F_18 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_2 ( V_4 ) ;
F_2 ( F_15 ( V_4 ) ) ;
if ( V_2 -> V_18 && ! V_2 -> V_19 )
F_19 ( V_4 -> V_20 -> V_21 , V_22 ) ;
F_20 ( V_4 ) ;
}
static void F_21 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_23 * V_23 = V_4 -> V_20 -> V_21 ;
struct V_24 * V_25 = V_9 -> V_26 ;
struct V_10 * V_3 = V_9 -> V_12 ;
int V_27 ;
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( (struct V_10 * ) V_4 -> V_11 == V_3 ) ;
F_2 ( V_23 == F_22 ( V_25 ) ) ;
F_23 ( F_24 ( V_25 ) , F_5 ( V_9 ) ) ;
V_27 = F_25 ( & V_3 -> V_28 ) ;
F_26 ( V_27 >= 1 , L_1 , V_3 , V_27 ) ;
F_27 ( V_4 ) ;
F_28 ( V_4 ) ;
V_4 -> V_11 = 0 ;
}
static void F_29 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_29 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_2 ( V_4 ) ;
F_2 ( F_15 ( V_4 ) ) ;
if ( V_29 )
F_30 ( V_4 ) ;
else
F_27 ( V_4 ) ;
}
static int F_31 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
return F_15 ( F_14 ( V_9 ) ) ? - V_30 : - V_31 ;
}
static int F_32 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
return F_33 ( F_14 ( V_9 ) ) ? - V_32 : 0 ;
}
static int F_34 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_10 * V_33 = V_9 -> V_12 ;
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( ! F_35 ( V_4 ) ) ;
if ( ! V_33 -> V_34 )
F_36 ( V_4 ) ;
F_37 ( F_24 ( V_9 -> V_26 ) , F_5 ( V_9 ) ) ;
return 0 ;
}
static void F_38 ( struct V_23 * V_23 , struct V_3 * V_4 , int V_35 )
{
struct V_36 * V_25 = F_39 ( V_23 ) ;
if ( V_35 == 0 ) {
F_40 ( V_4 ) ;
V_25 -> V_37 = 0 ;
} else {
F_41 ( V_4 ) ;
F_42 ( V_23 -> V_38 , V_35 ) ;
if ( ( V_35 == - V_39 || V_35 == - V_40 ) &&
V_25 -> V_37 == 0 ) {
V_25 -> V_37 = 1 ;
F_43 ( V_4 , V_35 ) ;
}
}
}
static void F_44 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_35 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_3 = V_9 -> V_12 ;
struct V_23 * V_23 = F_22 ( V_3 -> V_41 ) ;
F_2 ( F_15 ( V_4 ) ) ;
F_45 ( V_42 , V_7 , V_3 , L_2 , V_35 ) ;
if ( V_2 -> V_18 )
F_46 ( F_47 ( V_23 ) , 1 ) ;
if ( V_35 == 0 ) {
if ( ! V_2 -> V_18 )
F_48 ( V_7 , V_3 , 1 ) ;
} else {
V_2 -> V_18 = 0 ;
}
if ( ! V_3 -> V_34 )
F_10 ( V_4 ) ;
}
static void F_49 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_35 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_10 * V_33 = V_9 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_45 ( V_42 , V_7 , V_33 , L_3 , V_35 ) ;
V_2 -> V_43 = 0 ;
F_23 ( F_24 ( V_9 -> V_26 ) , V_2 ) ;
if ( V_33 -> V_34 ) {
F_2 ( F_15 ( V_4 ) ) ;
F_2 ( ! F_9 ( V_4 ) ) ;
} else {
F_2 ( F_9 ( V_4 ) ) ;
F_38 ( F_22 ( V_33 -> V_41 ) , V_4 , V_35 ) ;
F_50 ( V_4 ) ;
}
}
static int F_51 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
struct V_10 * V_33 = V_9 -> V_12 ;
int V_44 = 0 ;
F_11 ( V_4 ) ;
if ( F_52 ( V_4 ) ) {
F_2 ( V_33 -> V_45 == V_46 ) ;
F_36 ( V_4 ) ;
F_37 ( F_24 ( V_9 -> V_26 ) , F_5 ( V_9 ) ) ;
F_45 ( V_42 , V_7 , V_33 , L_4 ) ;
} else if ( V_33 -> V_45 == V_47 ) {
V_44 = - V_32 ;
} else {
F_53 ( V_48 , V_7 , V_33 , L_5 ,
V_33 -> V_45 ) ;
F_54 () ;
}
F_10 ( V_4 ) ;
return V_44 ;
}
static int F_55 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_14 , T_1 * V_49 )
{
if ( V_14 -> V_50 == V_51 || V_14 -> V_50 == V_52 ||
V_14 -> V_50 == V_53 ) {
struct V_54 * V_55 = F_56 ( V_7 ) ;
if ( F_8 ( V_55 -> V_56 -> V_57 & V_58 ) )
* V_49 = V_59 ;
}
return 0 ;
}
static int F_57 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
void * V_60 , T_2 V_61 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
(* V_61)( V_7 , V_60 , V_62 L_6 ,
V_2 , V_2 -> V_18 , V_2 -> V_19 ,
V_2 -> V_43 , V_4 ) ;
if ( V_4 ) {
(* V_61)( V_7 , V_60 , L_7 ,
( long ) V_4 -> V_63 , F_58 ( V_4 ) ,
F_59 ( V_4 ) , V_4 -> V_11 ,
V_4 -> V_64 ,
F_60 ( & V_4 -> V_65 ) ? L_8 : L_9 ) ;
}
(* V_61)( V_7 , V_60 , L_10 ) ;
return 0 ;
}
static int F_61 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
F_54 () ;
return 0 ;
}
static int F_62 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
return 0 ;
}
static int F_63 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 , int V_15 )
{
return 0 ;
}
static void F_64 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
}
static void F_65 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
}
static void F_66 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
}
static void F_67 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_10 * V_3 = V_9 -> V_12 ;
F_68 ( V_7 , V_3 ) ;
}
static int F_69 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_23 * V_23 = F_22 ( V_9 -> V_26 ) ;
int V_66 ;
V_66 = ! F_70 ( V_23 ) ;
if ( ! V_66 )
F_71 ( V_23 ) ;
return V_66 ? - V_30 : - V_31 ;
}
static void
F_72 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_35 )
{
}
static void F_73 ( const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_10 * V_67 = V_9 -> V_12 ;
struct V_36 * V_68 = F_24 ( V_67 -> V_41 ) ;
F_1 ( V_2 ) ;
F_74 ( & V_68 -> V_69 ) ;
}
int F_75 ( const struct V_6 * V_7 , struct V_24 * V_25 ,
struct V_10 * V_3 , T_1 V_64 )
{
struct V_1 * V_2 = F_76 ( V_25 , V_3 ) ;
struct V_3 * V_4 = V_3 -> V_70 ;
F_77 ( V_7 , V_25 , F_78 ( V_25 ) ) ;
V_2 -> V_5 = V_4 ;
F_79 ( V_4 ) ;
F_80 ( & V_2 -> V_71 ) ;
if ( V_3 -> V_72 == V_73 ) {
F_81 ( & V_3 -> V_28 ) ;
F_82 ( V_4 ) ;
V_4 -> V_11 = ( unsigned long ) V_3 ;
F_83 ( V_3 , & V_2 -> V_74 , V_25 , V_64 ,
& V_75 ) ;
} else {
struct V_36 * V_68 = F_24 ( V_25 ) ;
F_83 ( V_3 , & V_2 -> V_74 , V_25 , V_64 ,
& V_76 ) ;
F_81 ( & V_68 -> V_69 ) ;
}
return 0 ;
}
